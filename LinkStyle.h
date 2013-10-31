#pragma once


// CLinkStyle 对话框

class CLinkStyle : public CDialog
{
	DECLARE_DYNAMIC(CLinkStyle)

public:
	CLinkStyle(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLinkStyle();

// 对话框数据
	enum { IDD = IDD_LINKSTYLE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
};
