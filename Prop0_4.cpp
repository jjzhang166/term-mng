// Prop0_4.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "Prop0_4.h"
#include "afxdialogex.h"


// CProp0_4 �Ի���

IMPLEMENT_DYNAMIC(CProp0_4, CPropertyPage)

CProp0_4::CProp0_4()
	: CPropertyPage(CProp0_4::IDD)
{

}

CProp0_4::~CProp0_4()
{
}

void CProp0_4::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CProp0_4, CPropertyPage)
END_MESSAGE_MAP()


// CProp0_4 ��Ϣ�������
BOOL CProp0_4::OnSetActive()
{
	((CPropertySheet*)GetParent())->SetWizardButtons(PSWIZB_BACK|PSWIZB_FINISH);
	return CPropertyPage::OnSetActive();
}

BOOL CProp0_4::OnWizardFinish()
{
	return CPropertyPage::OnWizardFinish();
}
