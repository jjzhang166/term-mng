// SystemSet.cpp : 实现文件
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "SystemSet.h"
#include "afxdialogex.h"


// CSystemSet 对话框

IMPLEMENT_DYNAMIC(CSystemSet, CDialog)

CSystemSet::CSystemSet(CWnd* pParent /*=NULL*/)
	: CDialog(CSystemSet::IDD, pParent)
{

}

CSystemSet::~CSystemSet()
{
}

void CSystemSet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}


BEGIN_MESSAGE_MAP(CSystemSet, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CSystemSet::OnSelchangeTab1)
END_MESSAGE_MAP()


// CSystemSet 消息处理程序


BOOL CSystemSet::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_tab.InsertItem(0,"信息");
	m_tab.InsertItem(1,"版本");
	m_tab.InsertItem(2,"显示");
	m_tab.InsertItem(3,"网络");
	m_tab.InsertItem(4,"鼠标");
	m_tab.InsertItem(5,"安全");
	m_tab.InsertItem(6,"打印机");
    m_tab.InsertItem(7,"OEM软件");
	m_tab.InsertItem(8,"PPP设置");
	m_tab.InsertItem(9,"PING");
	m_tab.InsertItem(10,"其他");
	m_tab.InsertItem(11,"键盘");
	//建立属性页各页 
    page1.Create(IDD_SYSTEM1,GetDlgItem(IDC_TAB1)); 
	page2.Create(IDD_SYSTEM2,GetDlgItem(IDC_TAB1)); 
	page3.Create(IDD_SYSTEM3,GetDlgItem(IDC_TAB1)); 
	page4.Create(IDD_SYSTEM4,GetDlgItem(IDC_TAB1)); 
	page5.Create(IDD_SYSTEM5,GetDlgItem(IDC_TAB1)); 
	page6.Create(IDD_SYSTEM6,GetDlgItem(IDC_TAB1)); 
	page7.Create(IDD_SYSTEM7,GetDlgItem(IDC_TAB1)); 
	page8.Create(IDD_SYSTEM8,GetDlgItem(IDC_TAB1)); 
	page9.Create(IDD_SYSTEM9,GetDlgItem(IDC_TAB1)); 
	page10.Create(IDD_SYSTEM10,GetDlgItem(IDC_TAB1)); 
	page11.Create(IDD_SYSTEM11,GetDlgItem(IDC_TAB1)); 
	page12.Create(IDD_SYSTEM12,GetDlgItem(IDC_TAB1)); 
	//设置页面的位置在m_tab控件范围内 
	CRect rect; 
	m_tab.GetClientRect(&rect); 
	rect.top+=20; 
	rect.bottom-=4; 
	rect.left+=4;
	rect.right-=4; 
	page1.MoveWindow(&rect); 
	page2.MoveWindow(&rect); 
	page3.MoveWindow(&rect); 
	page4.MoveWindow(&rect); 
    page5.MoveWindow(&rect);  
	page6.MoveWindow(&rect);  
	page7.MoveWindow(&rect);  
	page8.MoveWindow(&rect);  
	page9.MoveWindow(&rect);  
	page10.MoveWindow(&rect);  
	page11.MoveWindow(&rect); 
	page12.MoveWindow(&rect); 
	page1.ShowWindow(TRUE); 
    m_tab.SetCurSel(0); 
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CSystemSet::OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	int CurSel; 
	CurSel=m_tab.GetCurSel(); 
	switch(CurSel) 
	{
	case 0: 
		page1.ShowWindow(TRUE); 
		page2.ShowWindow(FALSE); 
		page3.ShowWindow(FALSE); 
		page4.ShowWindow(FALSE); 
		page5.ShowWindow(FALSE); 
		page6.ShowWindow(FALSE); 
		page7.ShowWindow(FALSE); 
		page8.ShowWindow(FALSE); 
		page9.ShowWindow(FALSE); 
		page10.ShowWindow(FALSE); 
		page11.ShowWindow(FALSE); 
		page12.ShowWindow(FALSE); 
		break; 
	case 1: 
		page1.ShowWindow(FALSE); 
		page2.ShowWindow(TRUE); 
		page3.ShowWindow(FALSE); 
		page4.ShowWindow(FALSE); 
		page5.ShowWindow(FALSE); 
		page6.ShowWindow(FALSE); 
		page7.ShowWindow(FALSE); 
		page8.ShowWindow(FALSE); 
		page9.ShowWindow(FALSE); 
		page10.ShowWindow(FALSE); 
		page11.ShowWindow(FALSE); 
		page12.ShowWindow(FALSE); 
		break; 
	case 2: 
		page1.ShowWindow(FALSE); 
		page2.ShowWindow(FALSE); 
		page3.ShowWindow(TRUE); 
		page4.ShowWindow(FALSE); 
		page5.ShowWindow(FALSE); 
		page6.ShowWindow(FALSE); 
		page7.ShowWindow(FALSE); 
		page8.ShowWindow(FALSE); 
		page9.ShowWindow(FALSE); 
		page10.ShowWindow(FALSE); 
		page11.ShowWindow(FALSE); 
		page12.ShowWindow(FALSE); 
		break; 
	case 3: 
		page1.ShowWindow(FALSE); 
		page2.ShowWindow(FALSE); 
		page3.ShowWindow(FALSE); 
		page4.ShowWindow(TRUE); 
		page5.ShowWindow(FALSE); 
		page6.ShowWindow(FALSE); 
		page7.ShowWindow(FALSE); 
		page8.ShowWindow(FALSE); 
		page9.ShowWindow(FALSE); 
		page10.ShowWindow(FALSE); 
		page11.ShowWindow(FALSE); 
		page12.ShowWindow(FALSE); 
		break; 
	case 4: 
		page1.ShowWindow(FALSE); 
		page2.ShowWindow(FALSE); 
		page3.ShowWindow(FALSE); 
		page4.ShowWindow(FALSE); 
		page5.ShowWindow(TRUE); 
		page6.ShowWindow(FALSE); 
		page7.ShowWindow(FALSE); 
		page8.ShowWindow(FALSE); 
		page9.ShowWindow(FALSE); 
		page10.ShowWindow(FALSE); 
		page11.ShowWindow(FALSE); 
		page12.ShowWindow(FALSE); 
		break; 
	case 5: 
		page1.ShowWindow(FALSE); 
		page2.ShowWindow(FALSE); 
		page3.ShowWindow(FALSE); 
		page4.ShowWindow(FALSE); 
		page5.ShowWindow(FALSE); 
		page6.ShowWindow(TRUE); 
		page7.ShowWindow(FALSE); 
		page8.ShowWindow(FALSE); 
		page9.ShowWindow(FALSE); 
		page10.ShowWindow(FALSE); 
		page11.ShowWindow(FALSE); 
		page12.ShowWindow(FALSE);
		break; 
	case 6: 
		page1.ShowWindow(FALSE); 
		page2.ShowWindow(FALSE); 
		page3.ShowWindow(FALSE); 
		page4.ShowWindow(FALSE); 
		page5.ShowWindow(FALSE); 
		page6.ShowWindow(FALSE); 
		page7.ShowWindow(TRUE); 
		page8.ShowWindow(FALSE); 
		page9.ShowWindow(FALSE); 
		page10.ShowWindow(FALSE); 
		page11.ShowWindow(FALSE); 
		page12.ShowWindow(FALSE); 
		break; 
	case 7: 
		page1.ShowWindow(FALSE); 
		page2.ShowWindow(FALSE); 
		page3.ShowWindow(FALSE); 
		page4.ShowWindow(FALSE); 
		page5.ShowWindow(FALSE); 
		page6.ShowWindow(FALSE); 
		page7.ShowWindow(FALSE); 
		page8.ShowWindow(TRUE); 
		page9.ShowWindow(FALSE); 
		page10.ShowWindow(FALSE); 
		page11.ShowWindow(FALSE); 
		page12.ShowWindow(FALSE); 
		break; 
	case 8: 
		page1.ShowWindow(FALSE); 
		page2.ShowWindow(FALSE); 
		page3.ShowWindow(FALSE); 
		page4.ShowWindow(FALSE); 
		page5.ShowWindow(FALSE); 
		page6.ShowWindow(FALSE); 
		page7.ShowWindow(FALSE); 
		page8.ShowWindow(FALSE); 
		page9.ShowWindow(TRUE); 
		page10.ShowWindow(FALSE); 
		page11.ShowWindow(FALSE); 
		page12.ShowWindow(FALSE); 
		break; 
	case 9: 
		page1.ShowWindow(FALSE); 
		page2.ShowWindow(FALSE); 
		page3.ShowWindow(FALSE); 
		page4.ShowWindow(FALSE); 
		page5.ShowWindow(FALSE); 
		page6.ShowWindow(FALSE); 
		page7.ShowWindow(FALSE); 
		page8.ShowWindow(FALSE); 
		page9.ShowWindow(FALSE); 
		page10.ShowWindow(TRUE); 
		page11.ShowWindow(FALSE); 
		page12.ShowWindow(FALSE); 
		break; 
	case 10: 
		page1.ShowWindow(FALSE); 
		page2.ShowWindow(FALSE); 
		page3.ShowWindow(FALSE); 
		page4.ShowWindow(FALSE); 
		page5.ShowWindow(FALSE); 
		page6.ShowWindow(FALSE); 
		page7.ShowWindow(FALSE); 
		page8.ShowWindow(FALSE); 
		page9.ShowWindow(FALSE); 
		page10.ShowWindow(FALSE); 
		page11.ShowWindow(TRUE); 
		page12.ShowWindow(FALSE); 
		break; 
	case 11: 
		page1.ShowWindow(FALSE); 
		page2.ShowWindow(FALSE); 
		page3.ShowWindow(FALSE); 
		page4.ShowWindow(FALSE); 
		page5.ShowWindow(FALSE); 
		page6.ShowWindow(FALSE); 
		page7.ShowWindow(FALSE); 
		page8.ShowWindow(FALSE); 
		page9.ShowWindow(FALSE); 
		page10.ShowWindow(FALSE); 
		page11.ShowWindow(FALSE); 
		page12.ShowWindow(TRUE); 
        break; 
	default: ; 
	} 
	*pResult = 0;
}
