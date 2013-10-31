#pragma once


// CPage8 对话框

class CPage8 : public CDialog
{
	DECLARE_DYNAMIC(CPage8)

public:
	CPage8(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPage8();

// 对话框数据
	enum { IDD = IDD_SYSTEM8 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
