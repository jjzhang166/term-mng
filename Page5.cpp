// Page5.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "Page5.h"
#include "afxdialogex.h"


// CPage5 �Ի���

IMPLEMENT_DYNAMIC(CPage5, CDialog)

CPage5::CPage5(CWnd* pParent /*=NULL*/)
	: CDialog(CPage5::IDD, pParent)
{
	m_bSwap =0;
}

CPage5::~CPage5()
{
}

void CPage5::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CPage5, CDialog)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_CHECK1, &CPage5::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CPage5 ��Ϣ�������


BOOL CPage5::OnInitDialog()
{
	CDialog::OnInitDialog();

	//////��ȡ����ƶ��ٶ�
	CSliderCtrl* pSlide1=(CSliderCtrl*)GetDlgItem(IDC_TRACKBAR1);
	pSlide1->SetRange(1,20);
	int MouseSpend(0);
	::SystemParametersInfo(SPI_GETMOUSESPEED,sizeof(int),&MouseSpend,0);
	pSlide1->SetPos(MouseSpend);

	////�������˫��ʱ��
	CSliderCtrl* pSlide2=(CSliderCtrl*)GetDlgItem(IDC_TRACKBAR2);
	pSlide2->SetRange(1,1000);
	UINT nInterval = GetDoubleClickTime();
	pSlide2->SetPos(nInterval);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CPage5::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CSliderCtrl *pSlide=(CSliderCtrl*)pScrollBar;
	int MouseSpend;
	UINT nInterval;
	switch(pScrollBar->GetDlgCtrlID())
	{
	case IDC_TRACKBAR1:
		//////�ı�����ƶ��ٶ�
		//CSliderCtrl *pSlide=(CSliderCtrl*)pScrollBar;
		MouseSpend=pSlide->GetPos();
		::SystemParametersInfo(SPI_SETMOUSESPEED,0,(void *)MouseSpend,0);
		break;
	case IDC_TRACKBAR2:
		//��������˫��ʱ��
		nInterval=pSlide->GetPos();
		SetDoubleClickTime(nInterval);
		break;
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CPage5::OnBnClickedCheck1()
{
	m_bSwap = !m_bSwap;
	//�л�������Ҽ�
	::SwapMouseButton(m_bSwap);
}
