// Prop1_3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "Prop1_3.h"
#include "afxdialogex.h"


// CProp1_3 �Ի���

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


// CProp1_3 ��Ϣ�������


BOOL CProp1_3::OnSetActive()
{
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_BACK|PSWIZB_FINISH);
	return CPropertyPage::OnSetActive();
}


BOOL CProp1_3::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	m_combox1.AddString("LQϵ��");
	m_combox1.AddString("M2024");
	m_combox1.AddString("M1724");
	m_combox1.AddString("TH3070");
	m_combox1.AddString("9���ӡ��");
	m_combox1.AddString("IBM PR50");
	m_combox1.AddString("Oliv PR40");
	m_combox1.AddString("OKI5330");
	m_combox1.AddString("Oliv PR2");
	m_combox1.AddString("OKI_PR2");
	m_combox1.AddString("�Զ���");
	m_combox1.AddString("PCL�����ӡ��");
	m_combox1.AddString("PCL5ϵ��");


	m_combox2.AddString("�����ӡ");
	m_combox2.AddString("�����ӡ");
	m_combox2.AddString("͸����ӡ");
	m_combox2.AddString("����ӡ");

	m_combox3.AddString("����1");
	m_combox3.AddString("����2");
	m_combox3.AddString("����1");
	m_combox3.AddString("����2");
	m_combox3.AddString("����3");
	m_combox3.AddString("����4");

	m_combox4.AddString("����1");
	m_combox4.AddString("����2");
	m_combox4.AddString("����3");
	m_combox4.AddString("����4");

	m_combox5.AddString("����1");
	m_combox5.AddString("����2");
	m_combox5.AddString("����3");
	m_combox5.AddString("����4");

	m_combox6.AddString("����1");
	m_combox6.AddString("����2");
	m_combox6.AddString("����3");
	m_combox6.AddString("����4");

	m_combox7.AddString("����1");
	m_combox7.AddString("����2");
	m_combox7.AddString("����3");
	m_combox7.AddString("����4");

	m_combox8.AddString("ʵ��");
	m_combox8.AddString("����I");
	m_combox8.AddString("����II");
	m_combox8.AddString("����I");
	m_combox8.AddString("����II");
	m_combox8.AddString("WYSE");
	m_combox8.AddString("BPϵ��");
	m_combox8.AddString("����");
	m_combox8.AddString("ͨ��");
	m_combox8.AddString("����III");
	m_combox8.AddString("����III");
	m_combox8.AddString("����BP");

	m_combox1.SetCurSel(0);
	m_combox2.SetCurSel(0);
    m_combox3.SetCurSel(0);
	m_combox4.SetCurSel(0);
	m_combox5.SetCurSel(0);
	m_combox6.SetCurSel(0);
	m_combox7.SetCurSel(0);
	m_combox8.SetCurSel(0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CProp1_3::OnCbnSelchangeCombo6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
