// Page3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "Page3.h"
#include "afxdialogex.h"

// CPage3 �Ի���

IMPLEMENT_DYNAMIC(CPage3, CDialogEx)

CPage3::CPage3(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPage3::IDD, pParent)
{

}

CPage3::~CPage3()
{
}

void CPage3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO11, m_combo1);
	DDX_Control(pDX, IDC_COMBO12, m_combo2);
	DDX_Control(pDX, IDC_COMBO13, m_combo3);
}


BEGIN_MESSAGE_MAP(CPage3, CDialogEx)
	ON_WM_HSCROLL()
	//ON_CBN_SELCHANGE(IDC_COMBO11, &CPage3::OnCbnSelchangeCombo11)
	//ON_CBN_SELCHANGE(IDC_COMBO12, &CPage3::OnCbnSelchangeCombo12)
	//ON_CBN_SELCHANGE(IDC_COMBO13, &CPage3::OnCbnSelchangeCombo13)
	ON_BN_CLICKED(IDC_BUTTON3, &CPage3::OnBnClickedButton3)
END_MESSAGE_MAP()


// CPage3 ��Ϣ�������


//BOOL CPage3::OnInitDialog()
//{
//	CDialogEx::OnInitDialog();
//
//	CProgressCtrl *pProg=(CProgressCtrl*)GetDlgItem(IDC_IPADDRESS1);
//	pProg->SetRange(1,255);
//
//
//	CString strTest;
//	strTest.Format("%d%%",pos);
//	SetDlgItemText(IDC_STATIC1,strText);
//	return TRUE;  // return TRUE unless you set the focus to a control
//	// �쳣: OCX ����ҳӦ���� FALSE
//}


//void CPage3::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
//{
//	CSliderCtrl *pSlide=(CSliderCtrl*)pScrollBar;
//
//	
//	CString strTest;
//	strTest.Format("%d%%",pSlide->GetPos()/256);
//	SetDlgItemText(IDC_STATIC1,strText);
//
//	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
//}


BOOL CPage3::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_combo1.AddString(_T("16 λ"));
	m_combo1.AddString(_T("32 λ"));
	m_combo2.AddString(_T("600��800 ����"));
	m_combo2.AddString(_T("1024��768 ����"));
	m_combo2.AddString(_T("1440��900 ����"));
	m_combo3.AddString(_T("60 ����"));
	m_combo3.AddString(_T("75 ����"));

	DEVMODE DevMode; 

	//�����ʾ����
	EnumDisplaySettings(NULL, ENUM_REGISTRY_SETTINGS, &DevMode);

	//��ɫ���
	if (DevMode.dmBitsPerPel == 16)
	{
		m_combo1.SetCurSel(0);
	}
	else if (DevMode.dmBitsPerPel == 32)
	{
		m_combo1.SetCurSel(1);
	}
	//�ֱ���
	if ((DevMode.dmPelsWidth == 800) && (DevMode.dmPelsHeight == 600))
	{
		m_combo2.SetCurSel(0);
	}
	else if ((DevMode.dmPelsWidth == 1024) && (DevMode.dmPelsHeight == 768))
	{
		m_combo2.SetCurSel(1);
	}
	else
	{
		m_combo2.SetCurSel(2);
	}
	//ˢ����
	if (DevMode.dmDisplayFrequency == 60)
	{
		m_combo3.SetCurSel(0);
	}
	else if (DevMode.dmDisplayFrequency == 75)
	{
		m_combo3.SetCurSel(1);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


//void CPage3::OnCbnSelchangeCombo11()
//{
//	DEVMODE DevMode;
//	DevMode.dmDisplayFrequency=m_combo3.GetLBText(m_combo3.GetCurSel(),str);
//	//��ɫ���
//	if (m_combo1.GetCurSel() == 0)
//	{
//		DevMode.dmBitsPerPel = 16;
//	}
//	else if (m_combo1.GetCurSel() == 1)
//	{
//		DevMode.dmBitsPerPel = 32;
//	}
//
//	DevMode.dmSize = sizeof(DEVMODE);  
//	DevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | 
//		DM_BITSPERPEL | DM_DISPLAYFREQUENCY; 
//
//	//������ʾ����
//	LONG nResult = ChangeDisplaySettings(&DevMode, 0);
//	if (nResult == DISP_CHANGE_SUCCESSFUL)  
//	{
//		//���µ����ò�������ע���
//		ChangeDisplaySettings(&DevMode, CDS_UPDATEREGISTRY);
//
//		AfxMessageBox(_T("������ʾ���Գɹ���"));
//	}
//	else  
//	{
//		//�ָ�Ĭ������
//		ChangeDisplaySettings(NULL, 0);
//
//		AfxMessageBox(_T("������ʾ����ʧ�ܡ�"));
//	}
//}


//void CPage3::OnCbnSelchangeCombo12()
//{
//	DEVMODE DevMode;
//	DevMode.dmPelsWidth=m_combo1.GetLBText(m_combo1.GetCurSel(),str);
//	DevMode.dmDisplayFrequency=m_combo3.GetLBText(m_combo3.GetCurSel(),str);
//	//�ֱ���
//	if (m_combo2.GetCurSel() == 0)
//	{
//		DevMode.dmPelsWidth = 800;
//		DevMode.dmPelsHeight = 600;
//	}
//	else if (m_combo2.GetCurSel() == 1)
//	{
//		DevMode.dmPelsWidth = 1024;
//		DevMode.dmPelsHeight = 768;
//	}
//
//	DevMode.dmSize = sizeof(DEVMODE);  
//	DevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | 
//		DM_BITSPERPEL | DM_DISPLAYFREQUENCY; 
//
//	//������ʾ����
//	LONG nResult = ChangeDisplaySettings(&DevMode, 0);
//	if (nResult == DISP_CHANGE_SUCCESSFUL)  
//	{
//		//���µ����ò�������ע���
//		ChangeDisplaySettings(&DevMode, CDS_UPDATEREGISTRY);
//
//		AfxMessageBox(_T("������ʾ���Գɹ���"));
//	}
//	else  
//	{
//		//�ָ�Ĭ������
//		ChangeDisplaySettings(NULL, 0);
//
//		AfxMessageBox(_T("������ʾ����ʧ�ܡ�"));
//	}
//}


//void CPage3::OnCbnSelchangeCombo13()
//{
//	DEVMODE DevMode;
//
//	if (m_combo3.GetCurSel() == 0)
//	{
//		DevMode.dmDisplayFrequency = 60;
//	}
//	else if (m_combo3.GetCurSel() == 1)
//	{
//		DevMode.dmDisplayFrequency = 75;
//	}
//
//	DevMode.dmSize = sizeof(DEVMODE);  
//	DevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | 
//		DM_BITSPERPEL | DM_DISPLAYFREQUENCY; 
//
//	//������ʾ����
//	LONG nResult = ChangeDisplaySettings(&DevMode, 0);
//	if (nResult == DISP_CHANGE_SUCCESSFUL)  
//	{
//		//���µ����ò�������ע���
//		ChangeDisplaySettings(&DevMode, CDS_UPDATEREGISTRY);
//
//		AfxMessageBox(_T("������ʾ���Գɹ���"));
//	}
//	else  
//	{
//		//�ָ�Ĭ������
//		ChangeDisplaySettings(NULL, 0);
//
//		AfxMessageBox(_T("������ʾ����ʧ�ܡ�"));
//	}
//}


void CPage3::OnBnClickedButton3()
{
	DEVMODE DevMode;

	//��ɫ���
	if (m_combo1.GetCurSel() == 0)
	{
		DevMode.dmBitsPerPel = 16;
	}
	else if (m_combo1.GetCurSel() == 1)
	{
		DevMode.dmBitsPerPel = 32;
	}
	//�ֱ���
	if (m_combo2.GetCurSel() == 0)
	{
		DevMode.dmPelsWidth = 800;
		DevMode.dmPelsHeight = 600;
	}
	else if (m_combo2.GetCurSel() == 1)
	{
		DevMode.dmPelsWidth = 1024;
		DevMode.dmPelsHeight = 768;
	}
	else
	{
		DevMode.dmPelsWidth = 1440;
		DevMode.dmPelsHeight = 900;
	}
	//ˢ����
	if (m_combo3.GetCurSel() == 0)
	{
		DevMode.dmDisplayFrequency = 60;
	}
	else if (m_combo3.GetCurSel() == 1)
	{
		DevMode.dmDisplayFrequency = 75;
	}
	DevMode.dmSize = sizeof(DEVMODE);  
	DevMode.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT | 
		DM_BITSPERPEL | DM_DISPLAYFREQUENCY; 

	//������ʾ����
	LONG nResult = ChangeDisplaySettings(&DevMode, 0);
	if (nResult == DISP_CHANGE_SUCCESSFUL)  
	{
		//���µ����ò�������ע���
		ChangeDisplaySettings(&DevMode, CDS_UPDATEREGISTRY);

		AfxMessageBox(_T("������ʾ���Գɹ���"));
	}
	else  
	{
		//�ָ�Ĭ������
		ChangeDisplaySettings(NULL, 0);

		AfxMessageBox(_T("������ʾ����ʧ�ܡ�"));
	}
}
