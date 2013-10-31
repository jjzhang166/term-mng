// Xiugai.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "Xiugai.h"
#include "afxdialogex.h"
#include"iniRwApi.h"
#pragma   comment( lib,"iniRwApi.lib")
extern CString listname;
// CXiugai �Ի���

IMPLEMENT_DYNAMIC(CXiugai, CDialog)

CXiugai::CXiugai(CWnd* pParent /*=NULL*/)
	: CDialog(CXiugai::IDD, pParent)
{

	m_conn = _T("");
	m_style = _T("");
	m_zhuangtai = _T("");
	m_ip = _T("");
	m_name = _T("");
	m_pwd = _T("");
	m_yu = _T("");
}

CXiugai::~CXiugai()
{
}

void CXiugai::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_NAME, m_connect);
	DDX_Text(pDX, IDC_NAME, m_conn);
	DDX_Text(pDX, IDC_EDIT1, m_style);
	DDX_Text(pDX, IDC_EDIT2, m_zhuangtai);
	DDX_Text(pDX, IDC_EDIT3, m_ip);
	DDX_Text(pDX, IDC_EDIT4, m_name);
	DDX_Text(pDX, IDC_EDIT5, m_pwd);
	DDX_Text(pDX, IDC_EDIT6, m_yu);
}


BEGIN_MESSAGE_MAP(CXiugai, CDialog)
	ON_BN_CLICKED(IDOK, &CXiugai::OnBnClickedOk)
END_MESSAGE_MAP()


// CXiugai ��Ϣ�������


void CXiugai::OnBnClickedOk()
{
	UpdateData(true);
		//<1>дINI�����ļ�
	writeIniFileStr(m_conn.GetBuffer(),"��������",m_style.GetBuffer(),INI_TEST);
	writeIniFileStr(m_conn.GetBuffer(),"����״̬",m_zhuangtai.GetBuffer(),INI_TEST);
	writeIniFileStr(m_conn.GetBuffer(),"��������Ӧ�ó���",m_ip.GetBuffer(),INI_TEST);
	writeIniFileStr(m_conn.GetBuffer(),"�û���",m_name.GetBuffer(),INI_TEST);
	writeIniFileStr(m_conn.GetBuffer(),"����",m_pwd.GetBuffer(),INI_TEST);
	writeIniFileStr(m_conn.GetBuffer(),"��",m_yu.GetBuffer(),INI_TEST);
	//writeIniFileStr(m_conn.GetBuffer(),"����·�����ļ���",m_proPath.GetBuffer(),INI_TEST);
    Invalidate();
	UpdateData(false);
	CDialog::OnOK();
}


BOOL CXiugai::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_conn=listname;

	char szComputerIP[16];
	memset(szComputerIP,0x00,16);
	readIniStr(m_conn.GetBuffer(),"��������Ӧ�ó���",szComputerIP,INI_TEST);
	char servuser[16];
	memset(servuser,0x00,16);
	readIniStr(m_conn.GetBuffer(),"�û���",servuser,INI_TEST);
	char servpwd[16];
	memset(servpwd,0x00,16);
	readIniStr(m_conn.GetBuffer(),"����",servpwd,INI_TEST);

	char servyu[16];
	memset(servyu,0x00,16);
	readIniStr(m_conn.GetBuffer(),"��",servyu,INI_TEST);

	char servstyle[16];
	memset(servstyle,0x00,16);
	readIniStr(m_conn.GetBuffer(),"��������",servstyle,INI_TEST);

	char servzhuangtai[16];
	memset(servzhuangtai,0x00,16);
	readIniStr(m_conn.GetBuffer(),"����״̬",servzhuangtai,INI_TEST);

	m_ip.Format("%s",szComputerIP);
	m_name.Format("%s",servuser);
	m_pwd.Format("%s",servpwd);
	m_style.Format("%s",servstyle);
	m_yu.Format("%s",servyu);
	m_zhuangtai.Format("%s",servzhuangtai);
	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
