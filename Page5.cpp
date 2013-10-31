// Page5.cpp : 实现文件
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "Page5.h"
#include "afxdialogex.h"


// CPage5 对话框

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


// CPage5 消息处理程序


BOOL CPage5::OnInitDialog()
{
	CDialog::OnInitDialog();

	//////获取鼠标移动速度
	CSliderCtrl* pSlide1=(CSliderCtrl*)GetDlgItem(IDC_TRACKBAR1);
	pSlide1->SetRange(1,20);
	int MouseSpend(0);
	::SystemParametersInfo(SPI_GETMOUSESPEED,sizeof(int),&MouseSpend,0);
	pSlide1->SetPos(MouseSpend);

	////获得鼠标的双击时间
	CSliderCtrl* pSlide2=(CSliderCtrl*)GetDlgItem(IDC_TRACKBAR2);
	pSlide2->SetRange(1,1000);
	UINT nInterval = GetDoubleClickTime();
	pSlide2->SetPos(nInterval);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CPage5::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CSliderCtrl *pSlide=(CSliderCtrl*)pScrollBar;
	int MouseSpend;
	UINT nInterval;
	switch(pScrollBar->GetDlgCtrlID())
	{
	case IDC_TRACKBAR1:
		//////改变鼠标移动速度
		//CSliderCtrl *pSlide=(CSliderCtrl*)pScrollBar;
		MouseSpend=pSlide->GetPos();
		::SystemParametersInfo(SPI_SETMOUSESPEED,0,(void *)MouseSpend,0);
		break;
	case IDC_TRACKBAR2:
		//设置鼠标的双击时间
		nInterval=pSlide->GetPos();
		SetDoubleClickTime(nInterval);
		break;
	}
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CPage5::OnBnClickedCheck1()
{
	m_bSwap = !m_bSwap;
	//切换鼠标左右键
	::SwapMouseButton(m_bSwap);
}
