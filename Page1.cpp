// Page1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "Page1.h"
#include "afxdialogex.h"


// CPage1 �Ի���

IMPLEMENT_DYNAMIC(CPage1, CDialog)

CPage1::CPage1(CWnd* pParent /*=NULL*/)
	: CDialog(CPage1::IDD, pParent)
{

}

CPage1::~CPage1()
{
}

void CPage1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPage1, CDialog)
END_MESSAGE_MAP()


// CPage1 ��Ϣ�������


BOOL CPage1::OnInitDialog()
{
	CDialog::OnInitDialog();

	///////��ȡCPUƵ��
	HKEY hKey;//��ȡ����
	RegOpenKey(HKEY_LOCAL_MACHINE,"HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0",&hKey);
	DWORD dwType;
	DWORD dwValue;
	DWORD dwAge;
	RegQueryValueEx(hKey,"~MHz",0,&dwType,(LPBYTE)&dwAge,&dwValue);
	CString str;
	str.Format("%d",dwAge);
	GetDlgItem(IDC_EDIT1)->SetWindowText(str);
	//////////��ȡ�������ڴ��С
	MEMORYSTATUS   Mem;   
	GlobalMemoryStatus(&Mem);   
	DWORD dwSize = (DWORD)Mem.dwTotalPhys/(1024*1024);
	CString dwTotalPhys;
	dwTotalPhys.Format(_T("%ld MB"),dwSize);   
	GetDlgItem(IDC_EDIT2)->SetWindowText(dwTotalPhys);
	UpdateData(FALSE);
	///////��ȡ�������
	///��REG_SZ
	char sz[256];
	memset(sz,0,256);
	DWORD dwtype;
	DWORD s1=256;
	LONG result=RegOpenKey(HKEY_LOCAL_MACHINE,"SYSTEM\\CurrentControlSet\\Control\\ComputerName\\ActiveComputerName",&hKey);
	result=RegQueryValueEx(hKey,"ComputerName",NULL,&dwtype,(LPBYTE)sz,&s1);
	RegCloseKey(hKey);
	str=sz;
	GetDlgItem(IDC_EDIT3)->SetWindowText(str);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
