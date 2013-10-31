
// zaozhuangDlg.h : 头文件
//

#pragma once

#include"CButtonST.h"
// CzaozhuangDlg 对话框
class CzaozhuangDlg : public CDialogEx
{
// 构造
public:
	CzaozhuangDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_ZAOZHUANG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

//	CStatic m_tik;
	void InitList(void);
	CListCtrl m_list;
	CImageList m_Imagelist;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
 
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
//	CString m_tik;

	afx_msg void OnEnChangeTik();
	CButtonST m_help;

	CButtonST m_media;
	CButtonST m_link;
	CStatic m_tik;


	afx_msg void OnDblclkList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCancel2();
	afx_msg void OnBnClickedCancel4();
	afx_msg void OnBnClickedCancel7();
	afx_msg void OnBnClickedCancel8();
	afx_msg void OnBnClickedCancel();
	virtual void OnOK();
	afx_msg void OnBnClickedCancel5();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel3();
	afx_msg void OnClickList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCancel6();
	void AddHook(void);
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
//	virtual BOOL PreTranslateMessage(MSG* pMsg);
//	virtual BOOL PreTranslateMessage(MSG* pMsg);
//	afx_msg void OnClose();
//	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
//	void KillProcess(void);
//	void KillProcess(CString m_strProcessName);
	BOOL EnableDebugPrivilege(void);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedQuit();
public:
	//bool isAdmin;
	CRITICAL_SECTION critsec;
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
};
