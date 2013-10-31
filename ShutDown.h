#pragma once


// CShutDown 对话框

class CShutDown : public CDialogEx
{
	DECLARE_DYNAMIC(CShutDown)

public:
	CShutDown(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CShutDown();

// 对话框数据
	enum { IDD = IDD_SHUTDOWN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
