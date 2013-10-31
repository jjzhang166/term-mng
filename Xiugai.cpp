// Xiugai.cpp : 实现文件
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "Xiugai.h"
#include "afxdialogex.h"
#include"iniRwApi.h"
#pragma   comment( lib,"iniRwApi.lib")
extern CString listname;
// CXiugai 对话框

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


// CXiugai 消息处理程序


void CXiugai::OnBnClickedOk()
{
	UpdateData(true);
		//<1>写INI配置文件
	writeIniFileStr(m_conn.GetBuffer(),"连接类型",m_style.GetBuffer(),INI_TEST);
	writeIniFileStr(m_conn.GetBuffer(),"连接状态",m_zhuangtai.GetBuffer(),INI_TEST);
	writeIniFileStr(m_conn.GetBuffer(),"服务器或应用程序",m_ip.GetBuffer(),INI_TEST);
	writeIniFileStr(m_conn.GetBuffer(),"用户名",m_name.GetBuffer(),INI_TEST);
	writeIniFileStr(m_conn.GetBuffer(),"密码",m_pwd.GetBuffer(),INI_TEST);
	writeIniFileStr(m_conn.GetBuffer(),"域",m_yu.GetBuffer(),INI_TEST);
	//writeIniFileStr(m_conn.GetBuffer(),"程序路径和文件名",m_proPath.GetBuffer(),INI_TEST);
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
	readIniStr(m_conn.GetBuffer(),"服务器或应用程序",szComputerIP,INI_TEST);
	char servuser[16];
	memset(servuser,0x00,16);
	readIniStr(m_conn.GetBuffer(),"用户名",servuser,INI_TEST);
	char servpwd[16];
	memset(servpwd,0x00,16);
	readIniStr(m_conn.GetBuffer(),"密码",servpwd,INI_TEST);

	char servyu[16];
	memset(servyu,0x00,16);
	readIniStr(m_conn.GetBuffer(),"域",servyu,INI_TEST);

	char servstyle[16];
	memset(servstyle,0x00,16);
	readIniStr(m_conn.GetBuffer(),"连接类型",servstyle,INI_TEST);

	char servzhuangtai[16];
	memset(servzhuangtai,0x00,16);
	readIniStr(m_conn.GetBuffer(),"连接状态",servzhuangtai,INI_TEST);

	m_ip.Format("%s",szComputerIP);
	m_name.Format("%s",servuser);
	m_pwd.Format("%s",servpwd);
	m_style.Format("%s",servstyle);
	m_yu.Format("%s",servyu);
	m_zhuangtai.Format("%s",servzhuangtai);
	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
