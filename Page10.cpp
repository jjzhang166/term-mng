// Page10.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "Page10.h"
#include "afxdialogex.h"


// CPage10 �Ի���

IMPLEMENT_DYNAMIC(CPage10, CDialog)

CPage10::CPage10(CWnd* pParent /*=NULL*/)
	: CDialog(CPage10::IDD, pParent)
{

}

CPage10::~CPage10()
{
}

void CPage10::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPage10, CDialog)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, &CPage10::OnBnClickedButton1)
END_MESSAGE_MAP()


// CPage10 ��Ϣ�������


void CPage10::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
}


void CPage10::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CPage10::ClearAll(void)
{
	GetDlgItem(IDC_EDIT2)->SetWindowText("");
}
