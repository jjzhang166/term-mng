// PWD.cpp : 实现文件
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "PWD.h"
#include "afxdialogex.h"
#include"iniRwApi.h"
#pragma   comment( lib,"iniRwApi.lib")

// CPWD 对话框

IMPLEMENT_DYNAMIC(CPWD, CDialog)

CPWD::CPWD(CWnd* pParent /*=NULL*/)
	: CDialog(CPWD::IDD, pParent)
{
	m_pwd = _T("");
}

CPWD::~CPWD()
{
}

void CPWD::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_pwd);
}

BEGIN_MESSAGE_MAP(CPWD, CDialog)
	ON_BN_CLICKED(IDOK, &CPWD::OnBnClickedOk)
END_MESSAGE_MAP()


// CPWD 消息处理程序


void CPWD::OnBnClickedOk()
{
	UpdateData();
	char strpwd[1024];
	readIniStr("1","密码",strpwd,INI_PWD);
	if(strcmp(m_pwd.GetBuffer(), strpwd) == 0){
		m_pwd="";
		UpdateData(FALSE);
	    CDialog::OnOK();
	}else{
		m_pwd="";
		UpdateData(FALSE);
	}
}


BOOL CPWD::OnInitDialog()
{
	CDialog::OnInitDialog();

	GetDlgItem(IDC_EDIT1)->SetFocus();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
