// Prop0_3.cpp : 实现文件
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "Prop0_3.h"
#include "afxdialogex.h"


// CProp0_3 对话框

IMPLEMENT_DYNAMIC(CProp0_3, CPropertyPage)

CProp0_3::CProp0_3()
	: CPropertyPage(CProp0_3::IDD)
{
	m_filepath = _T("");
	m_begfile = _T("");
	m_radio = 0;
}

CProp0_3::~CProp0_3()
{
}

void CProp0_3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_filepath);
	DDX_Text(pDX, IDC_EDIT2, m_begfile);
	DDX_Radio(pDX, IDC_RADIO1_1, m_radio);
}


BEGIN_MESSAGE_MAP(CProp0_3, CPropertyPage)

	ON_BN_CLICKED(IDC_RADIO1_1, &CProp0_3::OnClickedRadio11)
	ON_COMMAND(IDC_RADIO1_2, &CProp0_3::OnRadio12)
END_MESSAGE_MAP()

BOOL CProp0_3::OnSetActive()
{
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_BACK|PSWIZB_NEXT);
    return CPropertyPage::OnSetActive();
}

BOOL CProp0_3::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	GetDlgItem(IDC_EDIT1)->EnableWindow(false);
	GetDlgItem(IDC_EDIT2)->EnableWindow(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CProp0_3::OnClickedRadio11()
{
	m_radio=0;
    GetDlgItem(IDC_EDIT1)->EnableWindow(false);
	GetDlgItem(IDC_EDIT2)->EnableWindow(false);

}


void CProp0_3::OnRadio12()
{
	m_radio=1;
	GetDlgItem(IDC_EDIT1)->EnableWindow(true);
	GetDlgItem(IDC_EDIT2)->EnableWindow(true);
}


LRESULT CProp0_3::OnWizardNext()
{
	if(m_radio==1)
		if(m_begfile==""||m_filepath=="")
		{
			MessageBox("请将信息填写完全！");
			return -1;
		}
	return CPropertyPage::OnWizardNext();
}


//BOOL CProp0_3::OnWizardFinish()
//{
//	// TODO: 在此添加专用代码和/或调用基类
//
//	return CPropertyPage::OnWizardFinish();
//}
