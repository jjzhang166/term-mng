// SetIP.cpp : 实现文件
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "SetIP.h"
#include "afxdialogex.h"
#include"iniRwApi.h"
#pragma   comment( lib,"iniRwApi.lib")

// CSetIP 对话框

IMPLEMENT_DYNAMIC(CSetIP, CDialog)

#pragma comment(lib, "ws2_32.lib")
	//#pragma comment(lib, "Iphlpapi.lib") 
	using namespace std;


typedef int (CALLBACK* DHCPNOTIFYPROC)(LPWSTR, LPWSTR, BOOL, DWORD, DWORD, DWORD, int);

typedef struct tagAdapterInfo
{
	string strName;			// 适配器名称
	string strDriverDesc;	// 适配器描述
	string strIP;			// IP地址
	string strNetMask;		// 子网掩码
	string strNetGate;		// 网关
}ADAPTER_INFO;

BOOL GetAdapterInfo();
BOOL RegGetIP(ADAPTER_INFO *pAI, LPCTSTR lpszAdapterName, int nIndex = 0);

vector<ADAPTER_INFO*> AdapterInfoVector;

BOOL GetAdapterInfo()
{
	// 这里的代码适合WINDOWS2000，对于NT需要读取HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\NetworkCards
	HKEY hKey, hSubKey, hNdiIntKey;

	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		"System\\CurrentControlSet\\Control\\Class\\{4d36e972-e325-11ce-bfc1-08002be10318}",
		0,
		KEY_READ,
		&hKey) != ERROR_SUCCESS)
		return FALSE;

	DWORD dwIndex = 0;
	DWORD dwBufSize = 256;
	DWORD dwDataType;
	char szSubKey[256];
	unsigned char szData[256];

	while(RegEnumKeyEx(hKey, dwIndex++, szSubKey, &dwBufSize, NULL, NULL, NULL, NULL) == ERROR_SUCCESS)
	{
		if(RegOpenKeyEx(hKey, szSubKey, 0, KEY_READ, &hSubKey) == ERROR_SUCCESS)
		{		
			if(RegOpenKeyEx(hSubKey, "Ndi\\Interfaces", 0, KEY_READ, &hNdiIntKey) == ERROR_SUCCESS)
			{
				dwBufSize = 256;
				if(RegQueryValueEx(hNdiIntKey, "LowerRange", 0, &dwDataType, szData, &dwBufSize) == ERROR_SUCCESS)
				{
					if(strcmp((char*)szData, "ethernet") == 0)		//	判断是不是以太网卡
					{
						dwBufSize = 256;
						if(RegQueryValueEx(hSubKey, "DriverDesc", 0, &dwDataType, szData, &dwBufSize) == ERROR_SUCCESS)
						{
							ADAPTER_INFO *pAI = new ADAPTER_INFO;
							pAI->strDriverDesc = (LPCTSTR)szData;
							dwBufSize = 256;
							if(RegQueryValueEx(hSubKey, "NetCfgInstanceID", 0, &dwDataType, szData, &dwBufSize) == ERROR_SUCCESS)
							{
								pAI->strName = (LPCTSTR)szData;
								RegGetIP(pAI, (LPCTSTR)szData);
							}
							AdapterInfoVector.push_back(pAI);	// 加入到容器中
						}
					}
				}
				RegCloseKey(hNdiIntKey);
			}
			RegCloseKey(hSubKey);
		}

		dwBufSize = 256;
	}	/* end of while */

	RegCloseKey(hKey);

	/*
	//	可以使用GetAdaptersInfo来取得网卡信息，但其显示的名称不是很具体

	ULONG ulAdapterInfoSize = sizeof(IP_ADAPTER_INFO);
	IP_ADAPTER_INFO *pAdapterInfoBkp, *pAdapterInfo = (IP_ADAPTER_INFO*)new char[ulAdapterInfoSize];
	if( GetAdaptersInfo(pAdapterInfo, &ulAdapterInfoSize) == ERROR_BUFFER_OVERFLOW )	// 缓冲区不够大
	{
	delete pAdapterInfo;
	pAdapterInfo = (IP_ADAPTER_INFO*)new char[ulAdapterInfoSize];
	pAdapterInfoBkp = pAdapterInfo;
	}
	if( GetAdaptersInfo(pAdapterInfo, &ulAdapterInfoSize) == ERROR_SUCCESS )
	{
	do {
	if (pAdapterInfo->Type == MIB_IF_TYPE_ETHERNET)
	{
	ADAPTER_INFO *pAI = new ADAPTER_INFO;
	pAI->strDriverDesc = pAdapterInfo->Description;
	pAI->strName = pAdapterInfo->AdapterName;
	RegGetIP(pAI, (LPCTSTR)pAdapterInfo->AdapterName);	// 因为IP_ADAPTER_INFO中未包含掩码信息，所以干脆直接读注册表
	AdapterInfoVector.push_back(pAI);
	}
	pAdapterInfo = pAdapterInfo->Next;
	} while(pAdapterInfo);
	}
	delete pAdapterInfoBkp;	
	*/
	return TRUE;
}

//-----------------------------------------------------------------
//	得到注册表中的IP信息
//	nIndex暂时未处理
//-----------------------------------------------------------------

BOOL RegGetIP(ADAPTER_INFO *pAI, LPCTSTR lpszAdapterName, int nIndex/* =0 */)
{
	ASSERT(pAI);

	HKEY hKey;
	string strKeyName = "SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters\\Interfaces\\";
	strKeyName += lpszAdapterName;
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		strKeyName.c_str(),
		0,
		KEY_READ,
		&hKey) != ERROR_SUCCESS)
		return FALSE;

	unsigned char szData[256];
	DWORD dwDataType, dwBufSize;

	dwBufSize = 256;
	if(RegQueryValueEx(hKey, "IPAddress", 0, &dwDataType, szData, &dwBufSize) == ERROR_SUCCESS)
		pAI->strIP = (LPCTSTR)szData;

	dwBufSize = 256;
	if(RegQueryValueEx(hKey, "SubnetMask", 0, &dwDataType, szData, &dwBufSize) == ERROR_SUCCESS)
		pAI->strNetMask = (LPCTSTR)szData;

	dwBufSize = 256;
	if(RegQueryValueEx(hKey, "DefaultGateway", 0, &dwDataType, szData, &dwBufSize) == ERROR_SUCCESS)
		pAI->strNetGate = (LPCTSTR)szData;

	RegCloseKey(hKey);
	return TRUE;
}

//-----------------------------------------------------------------
//	设置注册表中的IP信息
//-----------------------------------------------------------------

BOOL RegSetIP(LPCTSTR lpszAdapterName, int nIndex, LPCTSTR pIPAddress, LPCTSTR pNetMask, LPCTSTR pNetGate)
{
	HKEY hKey;
	string strKeyName = "SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters\\Interfaces\\";
	strKeyName += lpszAdapterName;
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		strKeyName.c_str(),
		0,
		KEY_WRITE,
		&hKey) != ERROR_SUCCESS)
		return FALSE;

	char mszIPAddress[100];
	char mszNetMask[100];
	char mszNetGate[100];

	strncpy(mszIPAddress, pIPAddress, 98);
	strncpy(mszNetMask, pNetMask, 98);
	strncpy(mszNetGate, pNetGate, 98);

	int nIP, nMask, nGate;

	nIP = strlen(mszIPAddress);
	nMask = strlen(mszNetMask);
	nGate = strlen(mszNetGate);

	*(mszIPAddress + nIP + 1) = 0x00;
	nIP += 2;

	*(mszNetMask + nMask + 1) = 0x00;
	nMask += 2;

	*(mszNetGate + nGate + 1) = 0x00;
	nGate += 2;

	RegSetValueEx(hKey, "IPAddress", 0, REG_MULTI_SZ, (unsigned char*)mszIPAddress, nIP);
	RegSetValueEx(hKey, "SubnetMask", 0, REG_MULTI_SZ, (unsigned char*)mszNetMask, nMask);
	RegSetValueEx(hKey, "DefaultGateway", 0, REG_MULTI_SZ, (unsigned char*)mszNetGate, nGate);

	RegCloseKey(hKey);

	return TRUE;
}
BOOL NotifyIPChange(LPCTSTR lpszAdapterName, int nIndex, LPCTSTR pIPAddress, LPCTSTR pNetMask)
{
	BOOL			bResult = FALSE;
	HINSTANCE		hDhcpDll;
	DHCPNOTIFYPROC	pDhcpNotifyProc;
	WCHAR wcAdapterName[256];
	
	MultiByteToWideChar(CP_ACP, 0, lpszAdapterName, -1, wcAdapterName,256);

	if((hDhcpDll = LoadLibrary("dhcpcsvc")) == NULL)
		return FALSE;

	if((pDhcpNotifyProc = (DHCPNOTIFYPROC)GetProcAddress(hDhcpDll, "DhcpNotifyConfigChange")) != NULL)
		if((pDhcpNotifyProc)(NULL, wcAdapterName, TRUE, nIndex, inet_addr(pIPAddress), inet_addr(pNetMask), 0) == ERROR_SUCCESS)
			bResult = TRUE;

	FreeLibrary(hDhcpDll);
	return bResult;
}
BOOL SetIP(LPCTSTR lpszAdapterName, int nIndex, LPCTSTR pIPAddress, LPCTSTR pNetMask, LPCTSTR pNetGate)
{
	if(!RegSetIP(lpszAdapterName, nIndex, pIPAddress, pNetMask, pNetGate))
		return FALSE;

	if(!NotifyIPChange(lpszAdapterName, nIndex, pIPAddress, pNetMask))
		return FALSE;

	return TRUE;
}
CSetIP::CSetIP(CWnd* pParent /*=NULL*/)
	: CDialog(CSetIP::IDD, pParent)
{

}

CSetIP::~CSetIP()
{
}

void CSetIP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_ADAPTER_COMBO, m_ctlAdapters);
	DDX_Control(pDX, IDC_NETMASK, m_ctlNetMask);
	//  DDX_Control(pDX, IDC_NETGATE, m_m_ctlNetGate);
	DDX_Control(pDX, IDC_NETGATE, m_ctlNetGate);
	DDX_Control(pDX, IDC_IPADDRESS, m_ctlIPAddress);
	//  DDX_Control(pDX, m_ctlAdapters, m_m_ctlAdapters);
	DDX_Control(pDX, m_ctlAdapters, m_ctlAdapters1);
}


BEGIN_MESSAGE_MAP(CSetIP, CDialog)
	ON_BN_CLICKED(IDOK, &CSetIP::OnBnClickedOk)
	ON_WM_DESTROY()
	//ON_CBN_SELCHANGE(m_ctlAdapters1, &CSetIP::OnSelchangeMCtladapters)
	ON_CBN_SELCHANGE(m_ctlAdapters, &CSetIP::OnCbnSelchangectladapters)
END_MESSAGE_MAP()


// CSetIP 消息处理程序


void CSetIP::OnBnClickedOk()
{////////设置IP
	UpdateData(true);
	char szIP[16];
	char szMask[16];
	char szGate[16];
	unsigned char *pIP, *pMask, *pGate;
	DWORD dwIP, dwMask, dwGate;
	int nSel = m_ctlAdapters1.GetCurSel();

	m_ctlIPAddress.GetAddress(dwIP);
	m_ctlNetMask.GetAddress(dwMask);
	m_ctlNetGate.GetAddress(dwGate);

	pIP = (unsigned char*)&dwIP;
	pMask = (unsigned char*)&dwMask;
	pGate = (unsigned char*)&dwGate;

	sprintf(szIP, "%u.%u.%u.%u", *(pIP+3), *(pIP+2), *(pIP+1), *pIP);
	sprintf(szMask, "%u.%u.%u.%u", *(pMask+3), *(pMask+2), *(pMask+1), *pMask);
	sprintf(szGate, "%u.%u.%u.%u", *(pGate+3), *(pGate+2), *(pGate+1), *pGate);

	if(SetIP(AdapterInfoVector[nSel]->strName.c_str(), 0, szIP, szMask, szGate) == TRUE)
		//::MessageBox(this->m_hWnd, "设置IP地址成功!", "操作结果", MB_OK | MB_ICONINFORMATION);
	//else
		//::MessageBox(this->m_hWnd, "设置IP地址失败!", "操作结果", MB_OK | MB_ICONERROR);
	     AfxMessageBox("设置完成");
	//记录IP
	CString str;
	m_ctlAdapters1.GetLBText(m_ctlAdapters1.GetCurSel(),str);//获取所选选项的信息
	writeIniFileStr("终端","适配器",str.GetBuffer(),INI_IP);
	writeIniFileStr("终端","IP地址",szIP,INI_IP);
	writeIniFileStr("终端","子网掩码",szMask,INI_IP);
	writeIniFileStr("终端","网关",szGate,INI_IP);
}




BOOL CSetIP::OnInitDialog()
{
	CDialog::OnInitDialog();

	GetAdapterInfo();	// 得到适配器信息

	// 添加到ComboBox
	for( size_t i = 0; i < AdapterInfoVector.size(); i++ )
		m_ctlAdapters1.AddString(AdapterInfoVector[i]->strDriverDesc.c_str());

	m_ctlAdapters1.SetCurSel(0);
	OnSelchangeMCtladapters();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CSetIP::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
}

int theSetIP()
{
	//AfxMessageBox("test");
	GetAdapterInfo();	// 得到适配器信息
	//AfxMessageBox(AdapterInfoVector[0]->strName.c_str());
	// 
	char szIP[16];
	char szMask[16];
	char szGate[16];
	readIniStr("终端","IP地址",szIP,INI_IP);
	readIniStr("终端","子网掩码",szMask,INI_IP);
	readIniStr("终端","网关",szGate,INI_IP);
	//if(SetIP(AdapterInfoVector[0]->strName.c_str(), 0, szIP, szMask, szGate) == TRUE)
	  //   AfxMessageBox("设置完成");
	if(SetIP(AdapterInfoVector[1]->strName.c_str(), 0, szIP,szMask,szGate) == TRUE)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
BOOL CSetIP::DestroyWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	for( size_t i = 0; i < AdapterInfoVector.size(); i++ )
		delete AdapterInfoVector[i];
	AdapterInfoVector.clear();
	return CDialog::DestroyWindow();
}


void CSetIP::OnSelchangeMCtladapters()
{
	int nSel = m_ctlAdapters1.GetCurSel();
	DWORD dwIP, dwMask, dwGate;

	dwIP = inet_addr(AdapterInfoVector[nSel]->strIP.c_str());
	dwMask = inet_addr(AdapterInfoVector[nSel]->strNetMask.c_str());
	dwGate = inet_addr(AdapterInfoVector[nSel]->strNetGate.c_str());

	unsigned char *pIP = (unsigned char*)&dwIP;
	unsigned char *pMask = (unsigned char*)&dwMask;
	unsigned char *pGate = (unsigned char*)&dwGate;

	m_ctlIPAddress.SetAddress(*pIP, *(pIP+1), *(pIP+2), *(pIP+3));
	m_ctlNetMask.SetAddress(*pMask, *(pMask+1), *(pMask+2), *(pMask+3));
	m_ctlNetGate.SetAddress(*pGate, *(pGate+1), *(pGate+2), *(pGate+3));
}


void CSetIP::OnCbnSelchangectladapters()
{
		int nSel = m_ctlAdapters1.GetCurSel();
	DWORD dwIP, dwMask, dwGate;

	dwIP = inet_addr(AdapterInfoVector[nSel]->strIP.c_str());
	dwMask = inet_addr(AdapterInfoVector[nSel]->strNetMask.c_str());
	dwGate = inet_addr(AdapterInfoVector[nSel]->strNetGate.c_str());

	unsigned char *pIP = (unsigned char*)&dwIP;
	unsigned char *pMask = (unsigned char*)&dwMask;
	unsigned char *pGate = (unsigned char*)&dwGate;

	m_ctlIPAddress.SetAddress(*pIP, *(pIP+1), *(pIP+2), *(pIP+3));
	m_ctlNetMask.SetAddress(*pMask, *(pMask+1), *(pMask+2), *(pMask+3));
	m_ctlNetGate.SetAddress(*pGate, *(pGate+1), *(pGate+2), *(pGate+3));

}
