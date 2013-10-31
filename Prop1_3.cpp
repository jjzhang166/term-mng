// Prop1_3.cpp : 实现文件
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "Prop1_3.h"
#include "afxdialogex.h"


// CProp1_3 对话框

IMPLEMENT_DYNAMIC(CProp1_3, CPropertyPage)

CProp1_3::CProp1_3()
	: CPropertyPage(CProp1_3::IDD)
{

}

CProp1_3::~CProp1_3()
{
}

void CProp1_3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_1, m_combox1);
	DDX_Control(pDX, IDC_COMBO_2, m_combox2);
	DDX_Control(pDX, IDC_COMBO_3, m_combox3);
	DDX_Control(pDX, IDC_COMBO_4, m_combox4);
	DDX_Control(pDX, IDC_COMBO_5, m_combox5);
	DDX_Control(pDX, IDC_COMBO_6, m_combox6);
	DDX_Control(pDX, IDC_COMBO_7, m_combox7);
	DDX_Control(pDX, IDC_COMBO_8, m_combox8);
}


BEGIN_MESSAGE_MAP(CProp1_3, CPropertyPage)
	ON_CBN_SELCHANGE(IDC_COMBO_6, &CProp1_3::OnCbnSelchangeCombo6)
END_MESSAGE_MAP()


// CProp1_3 消息处理程序


BOOL CProp1_3::OnSetActive()
{
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_BACK|PSWIZB_FINISH);
	return CPropertyPage::OnSetActive();
}


BOOL CProp1_3::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	m_combox1.AddString("LQ系列");
	m_combox1.AddString("M2024");
	m_combox1.AddString("M1724");
	m_combox1.AddString("TH3070");
	m_combox1.AddString("9针打印机");
	m_combox1.AddString("IBM PR50");
	m_combox1.AddString("Oliv PR40");
	m_combox1.AddString("OKI5330");
	m_combox1.AddString("Oliv PR2");
	m_combox1.AddString("OKI_PR2");
	m_combox1.AddString("自定义");
	m_combox1.AddString("PCL激光打印机");
	m_combox1.AddString("PCL5系列");


	m_combox2.AddString("代码打印");
	m_combox2.AddString("点阵打印");
	m_combox2.AddString("透明打印");
	m_combox2.AddString("不打印");

	m_combox3.AddString("并口1");
	m_combox3.AddString("并口2");
	m_combox3.AddString("辅口1");
	m_combox3.AddString("辅口2");
	m_combox3.AddString("辅口3");
	m_combox3.AddString("辅口4");

	m_combox4.AddString("串口1");
	m_combox4.AddString("串口2");
	m_combox4.AddString("串口3");
	m_combox4.AddString("串口4");

	m_combox5.AddString("串口1");
	m_combox5.AddString("串口2");
	m_combox5.AddString("串口3");
	m_combox5.AddString("串口4");

	m_combox6.AddString("串口1");
	m_combox6.AddString("串口2");
	m_combox6.AddString("串口3");
	m_combox6.AddString("串口4");

	m_combox7.AddString("串口1");
	m_combox7.AddString("串口2");
	m_combox7.AddString("串口3");
	m_combox7.AddString("串口4");

	m_combox8.AddString("实达");
	m_combox8.AddString("长城I");
	m_combox8.AddString("长城II");
	m_combox8.AddString("国光I");
	m_combox8.AddString("国光II");
	m_combox8.AddString("WYSE");
	m_combox8.AddString("BP系列");
	m_combox8.AddString("其他");
	m_combox8.AddString("通用");
	m_combox8.AddString("长城III");
	m_combox8.AddString("国光III");
	m_combox8.AddString("升腾BP");

	m_combox1.SetCurSel(0);
	m_combox2.SetCurSel(0);
    m_combox3.SetCurSel(0);
	m_combox4.SetCurSel(0);
	m_combox5.SetCurSel(0);
	m_combox6.SetCurSel(0);
	m_combox7.SetCurSel(0);
	m_combox8.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CProp1_3::OnCbnSelchangeCombo6()
{
	// TODO: 在此添加控件通知处理程序代码
}
