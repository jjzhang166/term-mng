// Prop0_1.cpp : 实现文件
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "Prop0_1.h"
#include "afxdialogex.h"
#include"iniRwApi.h"
#pragma   comment( lib,"iniRwApi.lib")

// CProp0_1 对话框

IMPLEMENT_DYNAMIC(CProp0_1, CPropertyPage)

CProp0_1::CProp0_1()
	: CPropertyPage(CProp0_1::IDD)
{

	m_name = "";
	m_ip = "";
}

CProp0_1::~CProp0_1()
{
}

void CProp0_1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_ip);
}


BEGIN_MESSAGE_MAP(CProp0_1, CPropertyPage)
END_MESSAGE_MAP()


// CProp0_1 消息处理程序


LRESULT CProp0_1::OnWizardNext()
{
	UpdateData();
	if(m_name==""||m_ip=="")
	{
		MessageBox("请填写连接名与服务器名！");
		return -1;
	}
	for(int i(1);i<=returnIniJieCount(INI_TEST);i++)
	{
		char strChar[128];
		CString str;
		int rv=returnIniJieName(INI_TEST,i,strChar);	
		str.Format("%s",strChar);
		if(strChar==m_name)
		{
			MessageBox("该连接名已存在，请选择一个不同的名称！","友情提示");
			return -1;
		}
	}
	return CPropertyPage::OnWizardNext();
}


BOOL CProp0_1::OnSetActive()
{
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_NEXT);
	return CPropertyPage::OnSetActive();
}
