
// zaozhuangDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "zaozhuangDlg.h"
#include "afxdialogex.h"
#include"CButtonST.h"
#include"TIANJIA.h"
#include"iniRwApi.h"
#pragma   comment( lib,"iniRwApi.lib")
#include"SkinPlusPlus.h"
#pragma   comment( lib,"SkinPlusPlusDLL.lib")
#include"SystemSet.h"
#include"ShutDown.h"
#include"LinkStyle.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "MaskKey.h"
#include "Xiugai.h"
#include "SetIP.h"
#include "PWD.h"
#include "SetPwd.h"
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
extern CString listname;

extern BOOL CALLBACK EnumTop(HWND hWnd, LPARAM param);

void KillProcess(CString m_strProcessName)
{
	//UpdateData(TRUE);

	BOOL bResult;
	CString strTemp,strProcessName;
	HANDLE hSnapshot;				//�ڴ���̵ġ����ա����  
	PROCESSENTRY32 ProcessEntry;	//�������̵Ľṹ
	vector<DWORD> vtPID;			//����ID����
	//����Ҫ�����Ľ�������
	strProcessName = m_strProcessName;
	strProcessName.MakeLower();
	//�����ڴ����н��̵Ŀ��ա�����ΪTH32CS_SNAPPROCESSȡ�еĽ���,���Բ���2��
	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	//��ȡҪ�����Ľ������ƶ�Ӧ�����н���ID
	ProcessEntry.dwSize = sizeof(PROCESSENTRY32);
	bResult = Process32First(hSnapshot,&ProcessEntry);//��ȡ��һ������
	while(bResult)
	{
		//�ж��Ƿ�ΪҪ�����Ľ���
		strTemp.Format("%s",ProcessEntry.szExeFile);
		strTemp.MakeLower();
		if(strTemp==strProcessName)
			vtPID.push_back(ProcessEntry.th32ProcessID);
		//��ȡ��һ������
		bResult = Process32Next(hSnapshot,&ProcessEntry);
	}
	//��������
	bResult = FALSE;
	vector<DWORD>::iterator it = vtPID.begin();
	for(;it!=vtPID.end();++it)
	{
		if(*it)
		{
			//��ȡ���̾��
			HANDLE hProcess;
			hProcess = OpenProcess(PROCESS_ALL_ACCESS,FALSE,*it);
			//��������
			if(hProcess)
				bResult = TerminateProcess(hProcess,0);
			if(!bResult)
				break;
		}
	}

	//
	/*if(bResult)
	{
	MessageBox("�������̳ɹ���");
	}
	else
	MessageBox("��������ʧ�ܣ�");*/


}


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CzaozhuangDlg �Ի���




CzaozhuangDlg::CzaozhuangDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CzaozhuangDlg::IDD, pParent)
{
	InitializeCriticalSection(&critsec);
}

void CzaozhuangDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDS_TIK, m_tik);
	DDX_Control(pDX, IDC_LIST2, m_list);

	DDX_Control(pDX, IDC_HELP1, m_help);
	DDX_Control(pDX, IDC_LINK, m_link);
	DDX_Control(pDX, IDC_MEDI, m_media);
	DDX_Control(pDX, IDC_LINK, m_link);
	//DDX_Control(pDX, IDC_STATIC1, m_tik);
}

BEGIN_MESSAGE_MAP(CzaozhuangDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

	ON_WM_ERASEBKGND()
	ON_WM_MOUSEMOVE()


	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, &CzaozhuangDlg::OnDblclkList2)
	ON_BN_CLICKED(IDC_BUTTON1, &CzaozhuangDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDCANCEL2, &CzaozhuangDlg::OnBnClickedCancel2)
	ON_BN_CLICKED(IDCANCEL4, &CzaozhuangDlg::OnBnClickedCancel4)
	ON_BN_CLICKED(IDCANCEL7, &CzaozhuangDlg::OnBnClickedCancel7)
	ON_BN_CLICKED(IDCANCEL8, &CzaozhuangDlg::OnBnClickedCancel8)
	ON_BN_CLICKED(IDCANCEL, &CzaozhuangDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDCANCEL5, &CzaozhuangDlg::OnBnClickedCancel5)
	ON_BN_CLICKED(IDOK, &CzaozhuangDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL3, &CzaozhuangDlg::OnBnClickedCancel3)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, &CzaozhuangDlg::OnClickList2)
	ON_BN_CLICKED(IDCANCEL6, &CzaozhuangDlg::OnBnClickedCancel6)
	ON_WM_KEYDOWN()
	ON_WM_CHAR()
	ON_WM_CLOSE()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON2, &CzaozhuangDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_QUIT, &CzaozhuangDlg::OnBnClickedQuit)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CzaozhuangDlg::OnLvnItemchangedList2)
END_MESSAGE_MAP()
// CzaozhuangDlg ��Ϣ�������

BOOL CzaozhuangDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//system("c:\\Program Files\autoUpDate.exe");
	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_Imagelist.Create(32,32,ILC_COLOR24|ILC_MASK,1,1);//����ͼ���б�
	m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_list.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE);//Ϊ�б�ؼ�������ʽ
	m_list.SetImageList(&m_Imagelist,LVSIL_SMALL);//
	m_list.InsertColumn(0,"��������",LVCFMT_LEFT,100,0);//Ϊ�б�ؼ�������в�����
	m_list.InsertColumn(1,"��������",LVCFMT_LEFT,100,1);
	m_list.InsertColumn(2,"����״̬",LVCFMT_LEFT,100,2);
	m_list.InsertColumn(3,"������ �� Ӧ�ó���",LVCFMT_LEFT,140,3);
	m_list.InsertColumn(4,"�û���",LVCFMT_LEFT,100,4);
	InitList();

	AddHook();
	SetTimer(1,100,NULL);
	
	EnableDebugPrivilege();
	
	//GetDlgItem(IDOK)->EnableWindow(FALSE);
	GetDlgItem(IDCANCEL2)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
	GetDlgItem(IDCANCEL4)->EnableWindow(FALSE);
	GetDlgItem(IDCANCEL5)->EnableWindow(FALSE);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
	GetDlgItem(IDC_QUIT)->EnableWindow(FALSE);
	GetDlgItem(IDCANCEL)->EnableWindow(FALSE);
	GetDlgItem(IDCANCEL7)->EnableWindow(FALSE);
	//zhangbo
	//InitializeSkin(_T(SSK_MINI));
	//LoadSkin(_T(SSK_SOFT));
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CzaozhuangDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CzaozhuangDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CzaozhuangDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CzaozhuangDlg::InitList(void)
{
	//m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);


    for(int i(1);i<=returnIniJieCount(INI_TEST);i++)
	{
		char strChar[128];
		char z_style[128],z_link[128],z_ip[128],z_username[128];
		int rv=returnIniJieName(INI_TEST,i,strChar);	
		if(rv!=0) 
		{
			MessageBox("��ȡ��һ���������ʧ��!\n");
			return;
		}
		CString name,style,link,ip,username;
		memset(z_style,0x00,128);
		rv=readIniStr(strChar,"��������",z_style,INI_TEST);
		rv=readIniStr(strChar,"����״̬",z_link,INI_TEST);
		rv=readIniStr(strChar,"��������Ӧ�ó���",z_ip,INI_TEST);
		rv=readIniStr(strChar,"�û���",z_username,INI_TEST);
		name.Format("%s",strChar);
		style.Format("%s",z_style);
		link.Format("%s",z_link);
		ip.Format("%s",z_ip);
		username.Format("%s",z_username);
		m_list.InsertItem(i-1,name);//����һ��
		m_list.SetItemText(i-1,1,style);//���ø��еĲ�ͬ�е���ʾ�ַ�
		m_list.SetItemText(i-1,2,link);
		m_list.SetItemText(i-1,3,ip);
		m_list.SetItemText(i-1,4,username);
	}
	UpdateData(false);
}




BOOL CzaozhuangDlg::OnEraseBkgnd(CDC* pDC)
{
		CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP2);

	BITMAP bmp;
	bitmap.GetBitmap(&bmp);
	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);
	
	dcCompatible.SelectObject(&bitmap);

	CRect rect;
	GetClientRect(&rect);
	//pDC->BitBlt(0,0,rect.Width(),rect.Height(),&dcCompatible,0,0,SRCCOPY);
	pDC->StretchBlt(0,0,rect.Width(),rect.Height(),&dcCompatible,0,0,bmp.bmWidth,bmp.bmHeight,SRCCOPY);
	return TRUE;
	// CDialogEx::OnEraseBkgnd(pDC);*/
}


void CzaozhuangDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CDialogEx::OnMouseMove(nFlags, point);
}

DWORD WINAPI RunThread(LPVOID pvoid) {
	CString* str = (CString*) pvoid;
	ShellExecute(NULL,"open",EXE_MSTSC,NULL,NULL,SW_SHOW);
	Sleep(500);
	CWnd *pMainWnd = CWnd::FromHandle(FindWindow(NULL,"Զ����������"));
	HWND hMainWnd = pMainWnd->m_hWnd;

	CRect rect_mainwnd;
	pMainWnd->GetWindowRect(rect_mainwnd);
	pMainWnd->SetWindowPos(NULL, rect_mainwnd.left,rect_mainwnd.top,rect_mainwnd.Width(),rect_mainwnd.Height(),SWP_SHOWWINDOW);
	pMainWnd->SetFocus();
	HWND hOptionWnd = ::FindWindowEx(hMainWnd,NULL,"Button","ѡ��(&O) >>");
	::SendMessage(hOptionWnd,BM_CLICK,0,0);

	HWND hDlgWnd = ::FindWindowEx(hMainWnd,NULL,"#32770","");
	if ( hDlgWnd == NULL )
	{
		AfxMessageBox("δ�ҵ�Զ�����������ϵ�dialog!");
		delete str;
		return 0;
	}
	HWND hComputerIPWnd = ::FindWindowEx(hDlgWnd,NULL,"ComboBoxEx32",NULL);
	if ( hComputerIPWnd == NULL )
	{
		AfxMessageBox("δ�ҵ���дԶ�̼����IP��ַ�Ĵ��ڣ�");
		delete str;
		return 0;
	}
	HWND hComputerUserNameWnd = ::FindWindowEx(hDlgWnd,NULL,"Edit",NULL);
	if ( hComputerUserNameWnd == NULL)
	{
		AfxMessageBox("δ�ҵ���дԶ�̼�����û����Ĵ��ڣ�");
		delete str;
		return 0;
	}

	HWND hComputerUserPwdWnd = ::FindWindowEx(hDlgWnd,hComputerUserNameWnd,"Edit",NULL);
	if ( hComputerUserPwdWnd == NULL )
	{
		AfxMessageBox("δ�ҵ���дԶ�̼�����û�����Ĵ��ڣ�");
		delete str;
		return 0;
	}
	HWND hComputerUserYuWnd = ::FindWindowEx(hDlgWnd,hComputerUserPwdWnd,"Edit",NULL);
	if ( hComputerUserYuWnd == NULL )
	{
		AfxMessageBox("δ�ҵ���дԶ�̼������Ĵ��ڣ�");
		delete str;
		return 0;
	}

	char szComputerIP[16];
	memset(szComputerIP,0x00,16);
	readIniStr(str->GetBuffer(),"��������Ӧ�ó���",szComputerIP,INI_TEST);
	char servuser[16];
	memset(servuser,0x00,16);
	readIniStr(str->GetBuffer(),"�û���",servuser,INI_TEST);
	char servpwd[16];
	memset(servpwd,0x00,16);
	readIniStr(str->GetBuffer(),"����",servpwd,INI_TEST);
	char servyu[16];
	memset(servyu,0x00,16);
	readIniStr(str->GetBuffer(),"��",servyu,INI_TEST);

	::SendMessage(hComputerIPWnd,WM_SETTEXT,0,(LPARAM)szComputerIP);
	::SendMessage(hComputerUserNameWnd,WM_SETTEXT,0,(LPARAM)servuser);
	::SendMessage(hComputerUserPwdWnd,WM_SETTEXT,0,(LPARAM)servpwd);
	::SendMessage(hComputerUserYuWnd,WM_SETTEXT,0,(LPARAM)servyu);
	HWND hOptionWnd1 = ::FindWindowEx(hMainWnd,NULL,"Button","����(&N)");
	::SendMessage(hOptionWnd1,BM_CLICK,0,0);

	Sleep(1000);
	string title = szComputerIP;
	EnumWindows(EnumTop, (LPARAM) &title);
	
	delete str;
	return 0;
}

void CzaozhuangDlg::OnDblclkList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	///////////////////Ԥ����
	CString str_yu("taskmgr.exe");
	KillProcess(str_yu);
	//////////////////////////////˫��Զ�̵�¼
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	int i=m_list.GetSelectionMark();//��ȡ�˵�����ѡ���������
	CString str=m_list.GetItemText(i,0);//��ȡ��ѡ������ı�

	CString* s = new CString();
	*s = str;
	CreateThread(NULL, 0, RunThread, s, NULL, NULL);

	*pResult = 0;
}

void CzaozhuangDlg::OnBnClickedButton1()
{
    int i=m_list.GetSelectionMark();//��ȡ�˵�����ѡ���������
	listname=m_list.GetItemText(i,0);//��ȡ��ѡ������ı�

	if(listname=="")
	{
		MessageBox("����ѡ��һ���޸���Ŀ��","������ʾ");
		return ;
	}

	CXiugai dlg;
	dlg.DoModal();
	m_list.DeleteAllItems();
	InitList();
}


void CzaozhuangDlg::OnBnClickedCancel2()
{
	CTIANJIA dlg;
	dlg.DoModal();
	m_list.DeleteAllItems();
	InitList();
}


BOOL CAboutDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CzaozhuangDlg::OnBnClickedCancel4()
{
	int i=m_list.GetSelectionMark();//��ȡ�˵�����ѡ���������
	CString str=m_list.GetItemText(i,0);//��ȡ��ѡ������ı�

	if(str=="")
	{
		MessageBox("����ѡ��һ��ɾ����Ŀ��","������ʾ");
		return ;
	}
	if(MessageBox("��ȷ��ɾ����","��ʾ��",MB_OKCANCEL)==IDOK)
	{
		int rv=deleteIniJie(str.GetBuffer(),INI_TEST);
		if(rv!=0)
		{
			MessageBox("ɾ���ֶ�ʧ��!\n","������ʾ");
		}
		else
		{
			MessageBox("ɾ���ֶγɹ�!\n","������ʾ");
		}
		m_list.DeleteAllItems();
		InitList();
	}
}


void CzaozhuangDlg::OnBnClickedCancel7()
{
	CSystemSet dlg;
	dlg.DoModal();
}


void CzaozhuangDlg::OnBnClickedCancel8()
{
	 CShutDown dlg;
	 dlg.DoModal();
}


void CzaozhuangDlg::OnBnClickedCancel()
{
	CSetPwd dlg;
	dlg.DoModal();
}


void CzaozhuangDlg::OnOK()
{

}


void CzaozhuangDlg::OnBnClickedCancel5()
{
	int i=m_list.GetSelectionMark();//��ȡ�˵�����ѡ���������
	listname=m_list.GetItemText(i,0);//��ȡ��ѡ������ı�

	if(listname=="")
	{
		MessageBox("��ѡ��һ����Ŀ��","������ʾ");
		return ;
	}


	CLinkStyle dlg;
	dlg.DoModal();
	m_list.DeleteAllItems();
	InitList();
}


BOOL CALLBACK EnumTop(HWND hWnd, LPARAM param) {
	char title[1024];
	GetWindowText(hWnd, title, 1024);
	string* content = (string*) param;
	if (strstr(title, content->c_str()) != NULL) {
		SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	}
	return true;
}

void CzaozhuangDlg::OnBnClickedOk()
{	///////////////////Ԥ����
	CString str_yu("taskmgr.exe");
	KillProcess(str_yu);

	////////////////////////
	int i=m_list.GetSelectionMark();//��ȡ�˵�����ѡ���������
	CString str=m_list.GetItemText(i,0);//��ȡ��ѡ������ı�
	if(str=="")
	{
		MessageBox("����ѡ��һ��������Ŀ��","������ʾ");
		return ;
	}
	
	CString* s = new CString();
	*s = str;
	CreateThread(NULL, 0, RunThread, s, NULL, NULL);
}


void CzaozhuangDlg::OnBnClickedCancel3()
{
	char path[128];
	memset(path,0x00,128);
	char exe[128];
	memset(exe,0x00,128);
	readIniStr("����", "·��", path, INI_PATH);
	readIniStr("����", "����", exe, INI_PATH);
	ShellExecute(NULL,"open", exe, NULL, path, SW_SHOWNORMAL);
}

void CzaozhuangDlg::OnClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	int i=m_list.GetSelectionMark();//��ȡ�˵�����ѡ���������
	listname=m_list.GetItemText(i,0);//��ȡ��ѡ������ı�
 
	*pResult = 0;
}

void CzaozhuangDlg::OnBnClickedCancel6()
{

}

void CzaozhuangDlg::AddHook(void)
{
	//zhangbo
	// ���� A, B, C, ��, ��, ��, �Ҽ�����win��
	DWORD dwVK[] = {VK_UP, VK_DOWN, VK_LWIN, VK_RWIN,VK_TAB,VK_F4,VK_ESCAPE,VK_F1};
	int nLength = sizeof(dwVK) / sizeof(DWORD);
	StartMaskKey(dwVK, nLength, FALSE);	
	WinExec("taskkill /im explorer.exe /f", SW_HIDE);
}


BOOL CzaozhuangDlg::PreTranslateMessage(MSG* pMsg)
{
	static bool isAdmin = false;
	CPWD dlg;

	switch(pMsg->message)    //ע������Ĳ������á�
	{
	case WM_KEYDOWN:
		switch(pMsg->wParam)   
		{
		case VK_F12://�رճ���//zhangbo
			EnterCriticalSection(&critsec);
			if(IDOK==dlg.DoModal())
			{
				isAdmin = !isAdmin;
				if(isAdmin==true)
				{
					//GetDlgItem(IDOK)->EnableWindow(TRUE);
					GetDlgItem(IDCANCEL2)->EnableWindow(TRUE);
					GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
					GetDlgItem(IDCANCEL4)->EnableWindow(TRUE);
					GetDlgItem(IDCANCEL5)->EnableWindow(TRUE);
					GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
					GetDlgItem(IDC_QUIT)->EnableWindow(TRUE);
					GetDlgItem(IDCANCEL)->EnableWindow(TRUE);
				}
				else
				{
					//GetDlgItem(IDOK)->EnableWindow(FALSE);
					GetDlgItem(IDCANCEL2)->EnableWindow(FALSE);
					GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
					GetDlgItem(IDCANCEL4)->EnableWindow(FALSE);
					GetDlgItem(IDCANCEL5)->EnableWindow(FALSE);
					GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
					GetDlgItem(IDC_QUIT)->EnableWindow(FALSE);
					GetDlgItem(IDCANCEL)->EnableWindow(FALSE);
				}
			}
			LeaveCriticalSection(&critsec);
			return true;
		}
	default:
		return CDialogEx::PreTranslateMessage(pMsg);

	}
}


void CzaozhuangDlg::OnTimer(UINT_PTR nIDEvent)
{
	CString str("taskmgr.exe");
	KillProcess(str);
	CDialogEx::OnTimer(nIDEvent);
}


BOOL CzaozhuangDlg::EnableDebugPrivilege(void)
{
	HANDLE hToken; 
	BOOL fOk=FALSE; 
	if(OpenProcessToken(GetCurrentProcess(),TOKEN_ADJUST_PRIVILEGES,&hToken)) 
	{ 
		TOKEN_PRIVILEGES tp; 
		tp.PrivilegeCount=1; 
		if(!LookupPrivilegeValue(NULL,SE_DEBUG_NAME,&tp.Privileges[0].Luid)) 
			printf("Can't lookup privilege value.\n"); 
		tp.Privileges[0].Attributes=SE_PRIVILEGE_ENABLED; 
		if(!AdjustTokenPrivileges(hToken,FALSE,&tp,sizeof(tp),NULL,NULL)) 
			printf("Can't adjust privilege value.\n"); 
		fOk=(GetLastError()==ERROR_SUCCESS); 
		CloseHandle(hToken); 
	} 
	return fOk; 

}


void CzaozhuangDlg::OnBnClickedButton2()
{
	CSetIP dlg;
	dlg.DoModal();
	//ShellExecute(NULL,"open","\AdapterIPConfig.exe",NULL,NULL,SW_SHOW);
}

void CzaozhuangDlg::OnBnClickedQuit()
{
	DeleteCriticalSection(&critsec);
	ShellExecute(NULL,"open","explorer.exe",NULL,NULL,SW_SHOW);
	this->GetParent()->PostMessage(WM_CLOSE,0,0);
	//ExitSkin();
	CDialog::OnOK();
}


void CzaozhuangDlg::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
