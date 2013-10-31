#pragma once


// CXiugai 对话框

class CXiugai : public CDialog
{
	DECLARE_DYNAMIC(CXiugai)

public:
	CXiugai(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CXiugai();

// 对话框数据
	enum { IDD = IDD_XIUGAI };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	CEdit m_connect;
	CString m_conn;
	CString m_style;
	CString m_zhuangtai;
	CString m_ip;
	CString m_name;
	CString m_pwd;
	CString m_yu;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
