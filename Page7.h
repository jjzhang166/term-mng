#pragma once


// CPage7 对话框

class CPage7 : public CDialog
{
	DECLARE_DYNAMIC(CPage7)

public:
	CPage7(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPage7();

// 对话框数据
	enum { IDD = IDD_SYSTEM7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
