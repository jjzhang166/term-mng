// LinkStyle.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "LinkStyle.h"
#include "afxdialogex.h"
#include"iniRwApi.h"
#pragma   comment( lib,"iniRwApi.lib")

// CLinkStyle �Ի���
extern CString listname;
IMPLEMENT_DYNAMIC(CLinkStyle, CDialog)

CLinkStyle::CLinkStyle(CWnd* pParent /*=NULL*/)
	: CDialog(CLinkStyle::IDD, pParent)
{

}

CLinkStyle::~CLinkStyle()
{
}

void CLinkStyle::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLinkStyle, CDialog)
	ON_BN_CLICKED(IDOK, &CLinkStyle::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLinkStyle::OnBnClickedCancel)
END_MESSAGE_MAP()


// CLinkStyle ��Ϣ�������


void CLinkStyle::OnBnClickedOk()
{
	if(listname!="")
	writeIniFileStr(listname.GetBuffer(),"����״̬","ֱ��",INI_TEST);
    CDialog::OnOK();
}


void CLinkStyle::OnBnClickedCancel()
{
	if(listname!="")
	writeIniFileStr(listname.GetBuffer(),"����״̬"," ",INI_TEST);
	CDialog::OnOK();
}


BOOL CLinkStyle::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
