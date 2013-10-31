#pragma once


// CSetPwd 对话框

class CSetPwd : public CDialog
{
	DECLARE_DYNAMIC(CSetPwd)

public:
	CSetPwd(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSetPwd();

// 对话框数据
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_edit1;
	CString m_edit2;
	CString m_edit3;
	afx_msg void OnBnClickedOk();
};
