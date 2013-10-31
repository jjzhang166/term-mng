
// zaozhuangDlg.cpp : 实现文件
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
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
extern CString listname;

extern BOOL CALLBACK EnumTop(HWND hWnd, LPARAM param);

void KillProcess(CString m_strProcessName)
{
	//UpdateData(TRUE);

	BOOL bResult;
	CString strTemp,strProcessName;
	HANDLE hSnapshot;				//内存进程的“快照”句柄  
	PROCESSENTRY32 ProcessEntry;	//描述进程的结构
	vector<DWORD> vtPID;			//进程ID容器
	//输入要结束的进程名称
	strProcessName = m_strProcessName;
	strProcessName.MakeLower();
	//返回内存所有进程的快照。参数为TH32CS_SNAPPROCESS取有的进程,忽略参数2；
	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	//获取要结束的进程名称对应的所有进程ID
	ProcessEntry.dwSize = sizeof(PROCESSENTRY32);
	bResult = Process32First(hSnapshot,&ProcessEntry);//获取第一个进程
	while(bResult)
	{
		//判断是否为要结束的进程
		strTemp.Format("%s",ProcessEntry.szExeFile);
		strTemp.MakeLower();
		if(strTemp==strProcessName)
			vtPID.push_back(ProcessEntry.th32ProcessID);
		//获取下一个进程
		bResult = Process32Next(hSnapshot,&ProcessEntry);
	}
	//结束进程
	bResult = FALSE;
	vector<DWORD>::iterator it = vtPID.begin();
	for(;it!=vtPID.end();++it)
	{
		if(*it)
		{
			//获取进程句柄
			HANDLE hProcess;
			hProcess = OpenProcess(PROCESS_ALL_ACCESS,FALSE,*it);
			//结束进程
			if(hProcess)
				bResult = TerminateProcess(hProcess,0);
			if(!bResult)
				break;
		}
	}

	//
	/*if(bResult)
	{
	MessageBox("结束进程成功！");
	}
	else
	MessageBox("结束进程失败！");*/


}


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CzaozhuangDlg 对话框




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
// CzaozhuangDlg 消息处理程序

BOOL CzaozhuangDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//system("c:\\Program Files\autoUpDate.exe");
	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_Imagelist.Create(32,32,ILC_COLOR24|ILC_MASK,1,1);//创建图像列表
	m_Imagelist.Add(AfxGetApp()->LoadIcon(IDI_ICON1));
	m_list.SetExtendedStyle(LVS_EX_FLATSB|LVS_EX_FULLROWSELECT|LVS_EX_HEADERDRAGDROP|LVS_EX_ONECLICKACTIVATE);//为列表控件设置样式
	m_list.SetImageList(&m_Imagelist,LVSIL_SMALL);//
	m_list.InsertColumn(0,"连接名称",LVCFMT_LEFT,100,0);//为列表控件添加两列并命名
	m_list.InsertColumn(1,"连接类型",LVCFMT_LEFT,100,1);
	m_list.InsertColumn(2,"连接状态",LVCFMT_LEFT,100,2);
	m_list.InsertColumn(3,"服务器 或 应用程序",LVCFMT_LEFT,140,3);
	m_list.InsertColumn(4,"用户名",LVCFMT_LEFT,100,4);
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
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CzaozhuangDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
			MessageBox("获取第一个结点名字失败!\n");
			return;
		}
		CString name,style,link,ip,username;
		memset(z_style,0x00,128);
		rv=readIniStr(strChar,"连接类型",z_style,INI_TEST);
		rv=readIniStr(strChar,"连接状态",z_link,INI_TEST);
		rv=readIniStr(strChar,"服务器或应用程序",z_ip,INI_TEST);
		rv=readIniStr(strChar,"用户名",z_username,INI_TEST);
		name.Format("%s",strChar);
		style.Format("%s",z_style);
		link.Format("%s",z_link);
		ip.Format("%s",z_ip);
		username.Format("%s",z_username);
		m_list.InsertItem(i-1,name);//插入一行
		m_list.SetItemText(i-1,1,style);//设置该行的不同列的显示字符
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
	CWnd *pMainWnd = CWnd::FromHandle(FindWindow(NULL,"远程桌面连接"));
	HWND hMainWnd = pMainWnd->m_hWnd;

	CRect rect_mainwnd;
	pMainWnd->GetWindowRect(rect_mainwnd);
	pMainWnd->SetWindowPos(NULL, rect_mainwnd.left,rect_mainwnd.top,rect_mainwnd.Width(),rect_mainwnd.Height(),SWP_SHOWWINDOW);
	pMainWnd->SetFocus();
	HWND hOptionWnd = ::FindWindowEx(hMainWnd,NULL,"Button","选项(&O) >>");
	::SendMessage(hOptionWnd,BM_CLICK,0,0);

	HWND hDlgWnd = ::FindWindowEx(hMainWnd,NULL,"#32770","");
	if ( hDlgWnd == NULL )
	{
		AfxMessageBox("未找到远程桌面连接上的dialog!");
		delete str;
		return 0;
	}
	HWND hComputerIPWnd = ::FindWindowEx(hDlgWnd,NULL,"ComboBoxEx32",NULL);
	if ( hComputerIPWnd == NULL )
	{
		AfxMessageBox("未找到填写远程计算机IP地址的窗口！");
		delete str;
		return 0;
	}
	HWND hComputerUserNameWnd = ::FindWindowEx(hDlgWnd,NULL,"Edit",NULL);
	if ( hComputerUserNameWnd == NULL)
	{
		AfxMessageBox("未找到填写远程计算机用户名的窗口！");
		delete str;
		return 0;
	}

	HWND hComputerUserPwdWnd = ::FindWindowEx(hDlgWnd,hComputerUserNameWnd,"Edit",NULL);
	if ( hComputerUserPwdWnd == NULL )
	{
		AfxMessageBox("未找到填写远程计算机用户密码的窗口！");
		delete str;
		return 0;
	}
	HWND hComputerUserYuWnd = ::FindWindowEx(hDlgWnd,hComputerUserPwdWnd,"Edit",NULL);
	if ( hComputerUserYuWnd == NULL )
	{
		AfxMessageBox("未找到填写远程计算机域的窗口！");
		delete str;
		return 0;
	}

	char szComputerIP[16];
	memset(szComputerIP,0x00,16);
	readIniStr(str->GetBuffer(),"服务器或应用程序",szComputerIP,INI_TEST);
	char servuser[16];
	memset(servuser,0x00,16);
	readIniStr(str->GetBuffer(),"用户名",servuser,INI_TEST);
	char servpwd[16];
	memset(servpwd,0x00,16);
	readIniStr(str->GetBuffer(),"密码",servpwd,INI_TEST);
	char servyu[16];
	memset(servyu,0x00,16);
	readIniStr(str->GetBuffer(),"域",servyu,INI_TEST);

	::SendMessage(hComputerIPWnd,WM_SETTEXT,0,(LPARAM)szComputerIP);
	::SendMessage(hComputerUserNameWnd,WM_SETTEXT,0,(LPARAM)servuser);
	::SendMessage(hComputerUserPwdWnd,WM_SETTEXT,0,(LPARAM)servpwd);
	::SendMessage(hComputerUserYuWnd,WM_SETTEXT,0,(LPARAM)servyu);
	HWND hOptionWnd1 = ::FindWindowEx(hMainWnd,NULL,"Button","连接(&N)");
	::SendMessage(hOptionWnd1,BM_CLICK,0,0);

	Sleep(1000);
	string title = szComputerIP;
	EnumWindows(EnumTop, (LPARAM) &title);
	
	delete str;
	return 0;
}

void CzaozhuangDlg::OnDblclkList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	///////////////////预处理
	CString str_yu("taskmgr.exe");
	KillProcess(str_yu);
	//////////////////////////////双击远程登录
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	int i=m_list.GetSelectionMark();//获取菜单中所选择的项的序号
	CString str=m_list.GetItemText(i,0);//获取所选择项的文本

	CString* s = new CString();
	*s = str;
	CreateThread(NULL, 0, RunThread, s, NULL, NULL);

	*pResult = 0;
}

void CzaozhuangDlg::OnBnClickedButton1()
{
    int i=m_list.GetSelectionMark();//获取菜单中所选择的项的序号
	listname=m_list.GetItemText(i,0);//获取所选择项的文本

	if(listname=="")
	{
		MessageBox("请先选择一个修改项目！","友情提示");
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

	// TODO:  在此添加额外的初始化

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CzaozhuangDlg::OnBnClickedCancel4()
{
	int i=m_list.GetSelectionMark();//获取菜单中所选择的项的序号
	CString str=m_list.GetItemText(i,0);//获取所选择项的文本

	if(str=="")
	{
		MessageBox("请先选择一个删除项目！","友情提示");
		return ;
	}
	if(MessageBox("您确定删除吗？","提示：",MB_OKCANCEL)==IDOK)
	{
		int rv=deleteIniJie(str.GetBuffer(),INI_TEST);
		if(rv!=0)
		{
			MessageBox("删除字段失败!\n","友情提示");
		}
		else
		{
			MessageBox("删除字段成功!\n","友情提示");
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
	int i=m_list.GetSelectionMark();//获取菜单中所选择的项的序号
	listname=m_list.GetItemText(i,0);//获取所选择项的文本

	if(listname=="")
	{
		MessageBox("请选择一个项目！","友情提示");
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
{	///////////////////预处理
	CString str_yu("taskmgr.exe");
	KillProcess(str_yu);

	////////////////////////
	int i=m_list.GetSelectionMark();//获取菜单中所选择的项的序号
	CString str=m_list.GetItemText(i,0);//获取所选择项的文本
	if(str=="")
	{
		MessageBox("请先选择一条链接项目！","友情提示");
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
	readIniStr("仿真", "路径", path, INI_PATH);
	readIniStr("仿真", "程序", exe, INI_PATH);
	ShellExecute(NULL,"open", exe, NULL, path, SW_SHOWNORMAL);
}

void CzaozhuangDlg::OnClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	int i=m_list.GetSelectionMark();//获取菜单中所选择的项的序号
	listname=m_list.GetItemText(i,0);//获取所选择项的文本
 
	*pResult = 0;
}

void CzaozhuangDlg::OnBnClickedCancel6()
{

}

void CzaozhuangDlg::AddHook(void)
{
	//zhangbo
	// 屏蔽 A, B, C, 上, 下, 左, 右及两个win键
	DWORD dwVK[] = {VK_UP, VK_DOWN, VK_LWIN, VK_RWIN,VK_TAB,VK_F4,VK_ESCAPE,VK_F1};
	int nLength = sizeof(dwVK) / sizeof(DWORD);
	StartMaskKey(dwVK, nLength, FALSE);	
	WinExec("taskkill /im explorer.exe /f", SW_HIDE);
}


BOOL CzaozhuangDlg::PreTranslateMessage(MSG* pMsg)
{
	static bool isAdmin = false;
	CPWD dlg;

	switch(pMsg->message)    //注意这里的参数设置。
	{
	case WM_KEYDOWN:
		switch(pMsg->wParam)   
		{
		case VK_F12://关闭程序//zhangbo
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
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
