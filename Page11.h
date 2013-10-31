#pragma once


// CPage11 对话框

class CPage11 : public CDialog
{
	DECLARE_DYNAMIC(CPage11)

public:
	CPage11(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPage11();

// 对话框数据
	enum { IDD = IDD_SYSTEM11 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
