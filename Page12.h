#pragma once


// CPage12 对话框

class CPage12 : public CDialog
{
	DECLARE_DYNAMIC(CPage12)

public:
	CPage12(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPage12();

// 对话框数据
	enum { IDD = IDD_SYSTEM12 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
