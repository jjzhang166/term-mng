#pragma once


// CMainDialog �Ի���

class CMainDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMainDialog)

public:
	CMainDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMainDialog();

// �Ի�������
	enum { IDD = IDD_MAINDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
