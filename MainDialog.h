#pragma once


// CMainDialog 对话框

class CMainDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMainDialog)

public:
	CMainDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMainDialog();

// 对话框数据
	enum { IDD = IDD_MAINDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	void AutoBegin(void);
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//	virtual BOOL PreTranslateMessage(MSG* pMsg);
//	void AddPicture(void);
//	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};
