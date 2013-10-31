// MainDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "MainDialog.h"
#include "afxdialogex.h"
#include"zaozhuangDlg.h"
#include"iniRwApi.h"
#include "SetIP.h"
#pragma   comment( lib,"iniRwApi.lib")

extern BOOL CALLBACK EnumTop(HWND hWnd, LPARAM param);
// CMainDialog 对话框
//#pragma comment(lib, "ws2_32.lib")
//	//#pragma comment(lib, "Iphlpapi.lib") 
//	using namespace std;
//
	extern int theSetIP();
//typedef int (CALLBACK* DHCPNOTIFYPROC)(LPWSTR, LPWSTR, BOOL, DWORD, DWORD, DWORD, int);

//typedef struct tagAdapterInfo
//{
//	string strName;			// 适配器名称
//	string strDriverDesc;	// 适配器描述
//	string strIP;			// IP地址
//	string strNetMask;		// 子网掩码
//	string strNetGate;		// 网关
//}ADAPTER_INFO;
IMPLEMENT_DYNAMIC(CMainDialog, CDialogEx)

CMainDialog::CMainDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMainDialog::IDD, pParent)
{

}

CMainDialog::~CMainDialog()
{
}

void CMainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMainDialog, CDialogEx)
	ON_WM_KEYDOWN()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

BOOL CMainDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//zhangbo
    //ShowWindow(SW_SHOWMAXIMIZED);
	ShowWindow(SW_HIDE);
	//zhangbo
	theSetIP();
	
	AutoBegin();
    CzaozhuangDlg dlg(this);
	dlg.DoModal();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CMainDialog::OnOK()
{

}
LPBYTE CString_To_LPBYTE(CString str)
{
	LPBYTE lpb=new BYTE[str.GetLength()+1];  
	for(int i=0; i< str.GetLength();i++)
		lpb[i]=str[i];
	lpb[str.GetLength()]=0;

	return lpb;
}
//BOOL SetIP(LPCTSTR lpszAdapterName, int nIndex, LPCTSTR pIPAddress, LPCTSTR pNetMask, LPCTSTR pNetGate)
//{
//	/*if(!RegSetIP(lpszAdapterName, nIndex, pIPAddress, pNetMask, pNetGate))
//		return FALSE;
//
//	if(!NotifyIPChange(lpszAdapterName, nIndex, pIPAddress, pNetMask))
//		return FALSE;
//*/
//	return TRUE;
//}
void  CMainDialog::AutoBegin(void)
{
	/////开机启动
    CString   strPath;
	GetModuleFileName(NULL,strPath.GetBufferSetLength(MAX_PATH+1),MAX_PATH);   
	strPath.ReleaseBuffer();   
	HKEY  hKey;       
	char  SubKeyName[]="SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon";
	char  ValueName[]="Userinit";

	//打开
	//zhangbo
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,SubKeyName,0,KEY_ALL_ACCESS,&hKey) != ERROR_SUCCESS)
	{
		//printf("Error:Regedit cannot be opened!");
	}
	else
	{    //存在       
		//改变值  
		LPBYTE lpstrPath=CString_To_LPBYTE(strPath); 
		if(RegSetValueEx(hKey,ValueName,0,REG_SZ,lpstrPath,strPath.GetLength())!=ERROR_SUCCESS)
		{       
			//printf("Error:Change Value failed ");
		}
		RegCloseKey(hKey);
	}
	
	////屏蔽Del+Ctrl+Alt
	/*ShellExecute(NULL,"open","\MaskKey.exe",NULL,NULL,SW_SHOW);
	Sleep(500);
	CWnd *pMainWnd = FindWindow(NULL,"禁用键盘 - Power By HuangKe 2005-8-29 V1.2");
	HWND hMainWnd = pMainWnd->m_hWnd;
	::ShowWindow(hMainWnd,   SW_HIDE); 
	*/
	/*禁用任务管理器
	DWORD val=1;
	RegCreateKey(HKEY_CURRENT_USER,"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System",&hKey);
	//RegSetValue(hKey,NULL,REG_SZ,"zhangsan",strlen("zhangsan"));
	RegSetValueEx(hKey,"DisableTaskMgr",0,REG_DWORD,(CONST BYTE*)&val,4);
	RegCloseKey(hKey);*/
	///屏蔽安全模式

	/////////////////////////////直连功能
	for(int i(1);i<=returnIniJieCount(INI_TEST);i++)
	{
		char strChar[128];
		char z_link[128];
		int rv=returnIniJieName(INI_TEST,i,strChar);	
		if(rv!=0) 
		{
			MessageBox("获取第一个结点名字失败!\n");
			return ;
		}
		CString link;
		memset(z_link,0x00,128);
		rv=readIniStr(strChar,"连接状态",z_link,INI_TEST);
		link.Format("%s",z_link);
		if(link=="直连")
		{
			ShellExecute(NULL,"open",EXE_MSTSC,NULL,NULL,SW_SHOW);
			Sleep(500);
			CWnd *pMainWnd = FindWindow(NULL,"远程桌面连接");
			HWND hMainWnd = pMainWnd->m_hWnd;
			HWND hOptionWnd = ::FindWindowEx(hMainWnd,NULL,"Button","选项(&O) >>");
			::SendMessage(hOptionWnd,BM_CLICK,0,0);
			HWND hDlgWnd = ::FindWindowEx(hMainWnd,NULL,"#32770","");
			if ( hDlgWnd == NULL )
			{
				MessageBox("未找到远程桌面连接上的dialog!");
				return;
			}
			HWND hComputerIPWnd = ::FindWindowEx(hDlgWnd,NULL,"ComboBoxEx32",NULL);
			if ( hComputerIPWnd == NULL )
			{
				MessageBox("未找到填写远程计算机IP地址的窗口！");
				return;
			}
			HWND hComputerUserNameWnd = ::FindWindowEx(hDlgWnd,NULL,"Edit",NULL);
			if ( hComputerUserNameWnd == NULL)
			{
				MessageBox("未找到填写远程计算机用户名的窗口！");
				return;
			}
			HWND hComputerUserPwdWnd = ::FindWindowEx(hDlgWnd,hComputerUserNameWnd,"Edit",NULL);
			if ( hComputerUserPwdWnd == NULL )
			{
				MessageBox("未找到填写远程计算机用户密码的窗口！");
				return;
			}
			HWND hComputerUserYuWnd = ::FindWindowEx(hDlgWnd,hComputerUserPwdWnd,"Edit",NULL);
			if ( hComputerUserYuWnd == NULL )
			{
				MessageBox("未找到填写远程计算机域的窗口！");
				return;
			}

			char szComputerIP[16];
			memset(szComputerIP,0x00,16);
			readIniStr(strChar,"服务器或应用程序",szComputerIP,INI_TEST);
			char servuser[16];
			memset(servuser,0x00,16);
			readIniStr(strChar,"用户名",servuser,INI_TEST);
			char servpwd[16];
			memset(servpwd,0x00,16);
			readIniStr(strChar,"密码",servpwd,INI_TEST);

			char servyu[16];
			memset(servyu,0x00,16);
			readIniStr(strChar,"域",servyu,INI_TEST);

			::SendMessage(hComputerIPWnd,WM_SETTEXT,0,(LPARAM)szComputerIP);
			::SendMessage(hComputerUserNameWnd,WM_SETTEXT,0,(LPARAM)servuser);
			::SendMessage(hComputerUserPwdWnd,WM_SETTEXT,0,(LPARAM)servpwd);
			::SendMessage(hComputerUserYuWnd,WM_SETTEXT,0,(LPARAM)servyu);

			HWND hOptionWnd1 = ::FindWindowEx(hMainWnd,NULL,"Button","连接(&N)");
			::SendMessage(hOptionWnd1,BM_CLICK,0,0);

			
			Sleep(1000);
			string title = "远程桌面";
			EnumWindows(EnumTop, (LPARAM) &title);
			break;

		}
	}
}