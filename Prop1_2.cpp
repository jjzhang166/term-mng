// Prop1_2.cpp : 实现文件
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "Prop1_2.h"
#include "afxdialogex.h"


// CProp1_2 对话框

IMPLEMENT_DYNAMIC(CProp1_2, CPropertyPage)

CProp1_2::CProp1_2()
	: CPropertyPage(CProp1_2::IDD)
{

	m_ip = ("");
}

CProp1_2::~CProp1_2()
{
}

void CProp1_2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_ip);
}


BEGIN_MESSAGE_MAP(CProp1_2, CPropertyPage)
	ON_CBN_SELCHANGE(IDC_COMBO7, &CProp1_2::OnCbnSelchangeCombo7)
END_MESSAGE_MAP()


// CProp1_2 消息处理程序


LRESULT CProp1_2::OnWizardNext()
{
	UpdateData();
	if(m_ip==L"")
	{
		MessageBox("域名/IP地址不能为空!");
		return -1;
	}
	return CPropertyPage::OnWizardNext();
}


BOOL CProp1_2::OnSetActive()
{
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_NEXT|PSWIZB_BACK);
	return CPropertyPage::OnSetActive();
}


void CProp1_2::OnCbnSelchangeCombo7()
{
	// TODO: 在此添加控件通知处理程序代码
}


BOOL CProp1_2::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	GetDlgItem(IDC_COMBO1)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO4)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO5)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO6)->EnableWindow(FALSE);
	GetDlgItem(IDC_COMBO7)->EnableWindow(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
