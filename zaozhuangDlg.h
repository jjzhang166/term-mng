
// zaozhuangDlg.h : ͷ�ļ�
//

#pragma once

#include"CButtonST.h"
// CzaozhuangDlg �Ի���
class CzaozhuangDlg : public CDialogEx
{
// ����
public:
	CzaozhuangDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_ZAOZHUANG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
