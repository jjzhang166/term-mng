// SetPwd.cpp : 实现文件
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "SetPwd.h"
#include "afxdialogex.h"
#include"iniRwApi.h"
#pragma   comment( lib,"iniRwApi.lib")

// CSetPwd 对话框

IMPLEMENT_DYNAMIC(CSetPwd, CDialog)

CSetPwd::CSetPwd(CWnd* pParent /*=NULL*/)
	: CDialog(CSetPwd::IDD, pParent)
{

	m_edit1 = _T("");
	m_edit2 = _T("");
	m_edit3 = _T("");
}

CSetPwd::~CSetPwd()
{
}

void CSetPwd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
}


BEGIN_MESSAGE_MAP(CSetPwd, CDialog)
	ON_BN_CLICKED(IDOK, &CSetPwd::OnBnClickedOk)
END_MESSAGE_MAP()


// CSetPwd 消息处理程序


void CSetPwd::OnBnClickedOk()
{
	UpdateData();
	CString strpwd;
	readIniStr("1","密码",strpwd.GetBuffer(),INI_PWD);
	if(m_edit1!=strpwd)
	{
	   MessageBox("原密码不正确！","友情提示");
	  return ;
	}
	if(m_edit2!=m_edit3)
	{
		MessageBox("两次密码输入不一致！","友情提示");
		return;
	}
	
	writeIniFileStr("1","密码",m_edit3.GetBuffer(),INI_PWD);
	MessageBox("修改成功！","友情提示");
	CDialog::OnOK();

}
