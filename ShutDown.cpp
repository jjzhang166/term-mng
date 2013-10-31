// ShutDown.cpp : 实现文件
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "ShutDown.h"
#include "afxdialogex.h"


// CShutDown 对话框

IMPLEMENT_DYNAMIC(CShutDown, CDialogEx)

CShutDown::CShutDown(CWnd* pParent /*=NULL*/)
	: CDialogEx(CShutDown::IDD, pParent)
{

}

CShutDown::~CShutDown()
{
}

void CShutDown::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CShutDown, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CShutDown::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CShutDown::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CShutDown::OnBnClickedButton3)
END_MESSAGE_MAP()


// CShutDown 消息处理程序


void CShutDown::OnBnClickedButton1()
{
	if(IDOK==MessageBox("您确定要退出吗","友好提示"))
	{
		UINT FFlag = EWX_SHUTDOWN | EWX_POWEROFF | EWX_FORCE;

		// Get version info to determine operation
		OSVERSIONINFO osvi;
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
		if (GetVersionEx(&osvi))
		{
			// Determine the platform
			if (osvi.dwPlatformId == VER_PLATFORM_WIN32_NT)
			{
				HANDLE hToken;
				TOKEN_PRIVILEGES tkp;

				// Windows NT 3.51, Windows NT 4.0, Windows 2000,
				// Windows XP, or Windows .NET Server
				if (OpenProcessToken(GetCurrentProcess(),
					TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
				{
					LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);

					tkp.PrivilegeCount = 1;  // one privilege to set
					tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

					AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
				}
			}
		}

		ExitWindowsEx(FFlag, 0);

	}
}


void CShutDown::OnBnClickedButton2()
{
	if(IDOK==MessageBox("您确定要退出吗","友好提示"))
	{
		UINT FFlag = EWX_REBOOT| EWX_FORCE;

		// Get version info to determine operation
		OSVERSIONINFO osvi;
		osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
		if (GetVersionEx(&osvi))
		{
			// Determine the platform
			if (osvi.dwPlatformId == VER_PLATFORM_WIN32_NT)
			{
				HANDLE hToken;
				TOKEN_PRIVILEGES tkp;

				// Windows NT 3.51, Windows NT 4.0, Windows 2000,
				// Windows XP, or Windows .NET Server
				if (OpenProcessToken(GetCurrentProcess(),
					TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
				{
					LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);

					tkp.PrivilegeCount = 1;  // one privilege to set
					tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

					AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);
				}
			}
		}

		ExitWindowsEx(FFlag, 0);

	}
}


void CShutDown::OnBnClickedButton3()
{
	CDialogEx::OnOK();
}
