// Page2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "Page2.h"
#include "afxdialogex.h"


// CPage2 �Ի���

IMPLEMENT_DYNAMIC(CPage2, CDialog)

CPage2::CPage2(CWnd* pParent /*=NULL*/)
	: CDialog(CPage2::IDD, pParent)
{

}

CPage2::~CPage2()
{
}

void CPage2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPage2, CDialog)
END_MESSAGE_MAP()


// CPage2 ��Ϣ�������


BOOL CPage2::OnInitDialog()
{
	CDialog::OnInitDialog();

	/////��ȡIE�汾��
	HKEY hKey;///��REG_SZ
	char sz[256];
	memset(sz,0,256);
	DWORD dwtype;
	DWORD s1=256;
	LONG result=RegOpenKey(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Internet Explorer",&hKey);
	result=RegQueryValueEx(hKey,"Version",NULL,&dwtype,(LPBYTE)sz,&s1);
	RegCloseKey(hKey);
	GetDlgItem(IDC_STATIC5)->SetWindowText(sz);
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
