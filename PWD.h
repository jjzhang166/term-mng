#pragma once


// CPWD 对话框

class CPWD : public CDialog
{
	DECLARE_DYNAMIC(CPWD)

public:
	CPWD(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPWD();

// 对话框数据
	enum { IDD = IDD_PWD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_pwd;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
