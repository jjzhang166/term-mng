// Prop1_2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "Prop1_2.h"
#include "afxdialogex.h"


// CProp1_2 �Ի���

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


// CProp1_2 ��Ϣ�������


LRESULT CProp1_2::OnWizardNext()
{
	UpdateData();
	if(m_ip==L"")
	{
		MessageBox("����/IP��ַ����Ϊ��!");
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// �쳣: OCX ����ҳӦ���� FALSE
}
