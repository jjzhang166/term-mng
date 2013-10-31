// Prop0_1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "Prop0_1.h"
#include "afxdialogex.h"
#include"iniRwApi.h"
#pragma   comment( lib,"iniRwApi.lib")

// CProp0_1 �Ի���

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


// CProp0_1 ��Ϣ�������


LRESULT CProp0_1::OnWizardNext()
{
	UpdateData();
	if(m_name==""||m_ip=="")
	{
		MessageBox("����д�����������������");
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
			MessageBox("���������Ѵ��ڣ���ѡ��һ����ͬ�����ƣ�","������ʾ");
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
