// MainDialog.cpp : ʵ���ļ�
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
// CMainDialog �Ի���
//#pragma comment(lib, "ws2_32.lib")
//	//#pragma comment(lib, "Iphlpapi.lib") 
//	using namespace std;
//
	extern int theSetIP();
//typedef int (CALLBACK* DHCPNOTIFYPROC)(LPWSTR, LPWSTR, BOOL, DWORD, DWORD, DWORD, int);

//typedef struct tagAdapterInfo
//{
//	string strName;			// ����������
//	string strDriverDesc;	// ����������
//	string strIP;			// IP��ַ
//	string strNetMask;		// ��������
//	string strNetGate;		// ����
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
	// �쳣: OCX ����ҳӦ���� FALSE
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
	/////��������
    CString   strPath;
	GetModuleFileName(NULL,strPath.GetBufferSetLength(MAX_PATH+1),MAX_PATH);   
	strPath.ReleaseBuffer();   
	HKEY  hKey;       
	char  SubKeyName[]="SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Winlogon";
	char  ValueName[]="Userinit";

	//��
	//zhangbo
	if(RegOpenKeyEx(HKEY_LOCAL_MACHINE,SubKeyName,0,KEY_ALL_ACCESS,&hKey) != ERROR_SUCCESS)
	{
		//printf("Error:Regedit cannot be opened!");
	}
	else
	{    //����       
		//�ı�ֵ  
		LPBYTE lpstrPath=CString_To_LPBYTE(strPath); 
		if(RegSetValueEx(hKey,ValueName,0,REG_SZ,lpstrPath,strPath.GetLength())!=ERROR_SUCCESS)
		{       
			//printf("Error:Change Value failed ");
		}
		RegCloseKey(hKey);
	}
	
	////����Del+Ctrl+Alt
	/*ShellExecute(NULL,"open","\MaskKey.exe",NULL,NULL,SW_SHOW);
	Sleep(500);
	CWnd *pMainWnd = FindWindow(NULL,"���ü��� - Power By HuangKe 2005-8-29 V1.2");
	HWND hMainWnd = pMainWnd->m_hWnd;
	::ShowWindow(hMainWnd,   SW_HIDE); 
	*/
	/*�������������
	DWORD val=1;
	RegCreateKey(HKEY_CURRENT_USER,"Software\\Microsoft\\Windows\\CurrentVersion\\Policies\\System",&hKey);
	//RegSetValue(hKey,NULL,REG_SZ,"zhangsan",strlen("zhangsan"));
	RegSetValueEx(hKey,"DisableTaskMgr",0,REG_DWORD,(CONST BYTE*)&val,4);
	RegCloseKey(hKey);*/
	///���ΰ�ȫģʽ

	/////////////////////////////ֱ������
	for(int i(1);i<=returnIniJieCount(INI_TEST);i++)
	{
		char strChar[128];
		char z_link[128];
		int rv=returnIniJieName(INI_TEST,i,strChar);	
		if(rv!=0) 
		{
			MessageBox("��ȡ��һ���������ʧ��!\n");
			return ;
		}
		CString link;
		memset(z_link,0x00,128);
		rv=readIniStr(strChar,"����״̬",z_link,INI_TEST);
		link.Format("%s",z_link);
		if(link=="ֱ��")
		{
			ShellExecute(NULL,"open",EXE_MSTSC,NULL,NULL,SW_SHOW);
			Sleep(500);
			CWnd *pMainWnd = FindWindow(NULL,"Զ����������");
			HWND hMainWnd = pMainWnd->m_hWnd;
			HWND hOptionWnd = ::FindWindowEx(hMainWnd,NULL,"Button","ѡ��(&O) >>");
			::SendMessage(hOptionWnd,BM_CLICK,0,0);
			HWND hDlgWnd = ::FindWindowEx(hMainWnd,NULL,"#32770","");
			if ( hDlgWnd == NULL )
			{
				MessageBox("δ�ҵ�Զ�����������ϵ�dialog!");
				return;
			}
			HWND hComputerIPWnd = ::FindWindowEx(hDlgWnd,NULL,"ComboBoxEx32",NULL);
			if ( hComputerIPWnd == NULL )
			{
				MessageBox("δ�ҵ���дԶ�̼����IP��ַ�Ĵ��ڣ�");
				return;
			}
			HWND hComputerUserNameWnd = ::FindWindowEx(hDlgWnd,NULL,"Edit",NULL);
			if ( hComputerUserNameWnd == NULL)
			{
				MessageBox("δ�ҵ���дԶ�̼�����û����Ĵ��ڣ�");
				return;
			}
			HWND hComputerUserPwdWnd = ::FindWindowEx(hDlgWnd,hComputerUserNameWnd,"Edit",NULL);
			if ( hComputerUserPwdWnd == NULL )
			{
				MessageBox("δ�ҵ���дԶ�̼�����û�����Ĵ��ڣ�");
				return;
			}
			HWND hComputerUserYuWnd = ::FindWindowEx(hDlgWnd,hComputerUserPwdWnd,"Edit",NULL);
			if ( hComputerUserYuWnd == NULL )
			{
				MessageBox("δ�ҵ���дԶ�̼������Ĵ��ڣ�");
				return;
			}

			char szComputerIP[16];
			memset(szComputerIP,0x00,16);
			readIniStr(strChar,"��������Ӧ�ó���",szComputerIP,INI_TEST);
			char servuser[16];
			memset(servuser,0x00,16);
			readIniStr(strChar,"�û���",servuser,INI_TEST);
			char servpwd[16];
			memset(servpwd,0x00,16);
			readIniStr(strChar,"����",servpwd,INI_TEST);

			char servyu[16];
			memset(servyu,0x00,16);
			readIniStr(strChar,"��",servyu,INI_TEST);

			::SendMessage(hComputerIPWnd,WM_SETTEXT,0,(LPARAM)szComputerIP);
			::SendMessage(hComputerUserNameWnd,WM_SETTEXT,0,(LPARAM)servuser);
			::SendMessage(hComputerUserPwdWnd,WM_SETTEXT,0,(LPARAM)servpwd);
			::SendMessage(hComputerUserYuWnd,WM_SETTEXT,0,(LPARAM)servyu);

			HWND hOptionWnd1 = ::FindWindowEx(hMainWnd,NULL,"Button","����(&N)");
			::SendMessage(hOptionWnd1,BM_CLICK,0,0);

			
			Sleep(1000);
			string title = "Զ������";
			EnumWindows(EnumTop, (LPARAM) &title);
			break;

		}
	}
}