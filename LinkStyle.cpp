// LinkStyle.cpp : 实现文件
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "LinkStyle.h"
#include "afxdialogex.h"
#include"iniRwApi.h"
#pragma   comment( lib,"iniRwApi.lib")

// CLinkStyle 对话框
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


// CLinkStyle 消息处理程序


void CLinkStyle::OnBnClickedOk()
{
	if(listname!="")
	writeIniFileStr(listname.GetBuffer(),"连接状态","直连",INI_TEST);
    CDialog::OnOK();
}


void CLinkStyle::OnBnClickedCancel()
{
	if(listname!="")
	writeIniFileStr(listname.GetBuffer(),"连接状态"," ",INI_TEST);
	CDialog::OnOK();
}


BOOL CLinkStyle::OnInitDialog()
{
	CDialog::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
