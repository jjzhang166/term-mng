// TIANJIA.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "TIANJIA.h"
#include "afxdialogex.h"
#include"PropSheet0.h"
#include"PropSheet1.h"
// CTIANJIA �Ի���
#include"iniRwApi.h"
#pragma   comment( lib,"iniRwApi.lib")
IMPLEMENT_DYNAMIC(CTIANJIA, CDialogEx)

CTIANJIA::CTIANJIA(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTIANJIA::IDD, pParent)
{
	 m_connect="";
	 m_serverAndPro="";
	 m_ip="";
	 m_name="";
	 m_pwd="";
	 m_begPath="";
	 m_proPath="";
}

CTIANJIA::~CTIANJIA()
{
}

void CTIANJIA::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combox1);
}


BEGIN_MESSAGE_MAP(CTIANJIA, CDialogEx)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDOK, &CTIANJIA::OnBnClickedOk)
END_MESSAGE_MAP()


// CTIANJIA ��Ϣ�������


int CTIANJIA::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;


	return 0;
}


BOOL CTIANJIA::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_combox1.AddString("Citrix ICA Client");
	m_combox1.AddString("Microsoft RDP Client");
	m_combox1.AddString("Telnet");
	m_combox1.AddString("TN5250");
	m_combox1.AddString("Windows CE IE6.0");
	m_combox1.SetCurSel(1);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CTIANJIA::OnBnClickedOk()
{
	int index=m_combox1.GetCurSel();
	if(1==index)
	{
		CPropSheet0 propSheet0("WST������");
		propSheet0.SetWizardMode();
		if(ID_WIZFINISH==propSheet0.DoModal())
		{
			m_connect=propSheet0.m_prop1.m_name;
			m_serverAndPro=propSheet0.m_prop1.m_ip;//������
			m_name=propSheet0.m_prop2.m_name;
			m_pwd=propSheet0.m_prop2.m_pwd;
			m_ip=propSheet0.m_prop2.m_ip;//��
			m_proPath=propSheet0.m_prop3.m_filepath;//����·�����ļ���
			m_begPath=propSheet0.m_prop3.m_begfile;//�ڸ��ļ���������
	
			
			//<1>дINI�����ļ�
			writeIniFileStr(m_connect.GetBuffer(),"��������","RDP",INI_TEST);
			writeIniFileStr(m_connect.GetBuffer(),"����״̬"," ",INI_TEST);
			writeIniFileStr(m_connect.GetBuffer(),"��������Ӧ�ó���",m_serverAndPro.GetBuffer(),INI_TEST);
			writeIniFileStr(m_connect.GetBuffer(),"�û���",m_name.GetBuffer(),INI_TEST);
			writeIniFileStr(m_connect.GetBuffer(),"����",m_pwd.GetBuffer(),INI_TEST);
			writeIniFileStr(m_connect.GetBuffer(),"��",m_ip.GetBuffer(),INI_TEST);
			writeIniFileStr(m_connect.GetBuffer(),"����·�����ļ���",m_proPath.GetBuffer(),INI_TEST);
            Invalidate();
		}
	}
	else if(2==index)
	{
		CPropSheet1 propSheet1("�ն˷������ӹ���");
		propSheet1.SetWizardMode();
		propSheet1.DoModal();
	}

	CDialogEx::OnOK();
}
