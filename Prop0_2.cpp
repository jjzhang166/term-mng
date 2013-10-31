// Prop0_2.cpp : 实现文件
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "Prop0_2.h"
#include "afxdialogex.h"


// CProp0_2 对话框

IMPLEMENT_DYNAMIC(CProp0_2, CPropertyPage)

CProp0_2::CProp0_2()
	: CPropertyPage(CProp0_2::IDD)
{

	m_name = _T("");
	m_pwd = _T("");
	m_ip = _T("");
	m_check=false;
}

CProp0_2::~CProp0_2()
{
}

void CProp0_2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, m_check);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
	DDX_Text(pDX, IDC_EDIT3, m_ip);
}


BEGIN_MESSAGE_MAP(CProp0_2, CPropertyPage)
	ON_BN_CLICKED(IDC_CHECK1, &CProp0_2::OnClickedCheck1)
END_MESSAGE_MAP()


// CProp0_2 消息处理程序


LRESULT CProp0_2::OnWizardNext()
{
	GetDlgItem(IDC_EDIT1)->EnableWindow(m_check);
	GetDlgItem(IDC_EDIT2)->EnableWindow(m_check);
	GetDlgItem(IDC_EDIT3)->EnableWindow(m_check);
	/*if(m_check)
	{
		if(m_name==""||m_pwd==""||m_ip=="")
		{
			MessageBox("请将信息填写完全！");
			return -1;
		}
	}*/
	return CPropertyPage::OnWizardNext();
}


BOOL CProp0_2::OnSetActive()
{
	if(m_check==true&&(m_name==""||m_pwd==""||m_ip==""))
	{
		((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_BACK);
	}
	else
		((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_NEXT|PSWIZB_BACK);
	return CPropertyPage::OnSetActive();
}


void CProp0_2::OnClickedCheck1()
{
	if(m_check==false)
		m_check=true;
	else
		m_check=false;
	if(m_check==false)
	{
		GetDlgItem(IDC_EDIT1)->EnableWindow(false);
		GetDlgItem(IDC_EDIT2)->EnableWindow(false);
		GetDlgItem(IDC_EDIT3)->EnableWindow(false);
	}
	else
	{
		GetDlgItem(IDC_EDIT1)->EnableWindow(true);
		GetDlgItem(IDC_EDIT2)->EnableWindow(true);
		GetDlgItem(IDC_EDIT3)->EnableWindow(true);
	}
}


BOOL CProp0_2::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	GetDlgItem(IDC_EDIT1)->EnableWindow(false);
	GetDlgItem(IDC_EDIT2)->EnableWindow(false);
	GetDlgItem(IDC_EDIT3)->EnableWindow(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
