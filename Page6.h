#pragma once


// CPage6 对话框

class CPage6 : public CDialog
{
	DECLARE_DYNAMIC(CPage6)

public:
	CPage6(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPage6();

// 对话框数据
	enum { IDD = IDD_SYSTEM6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
