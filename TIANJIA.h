#pragma once


// CTIANJIA 对话框

class CTIANJIA : public CDialogEx
{
	DECLARE_DYNAMIC(CTIANJIA)

public:
	CTIANJIA(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTIANJIA();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CComboBox m_combox1;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
public:
	CString m_connect,m_serverAndPro;
	CString m_ip,m_name,m_pwd;
	CString m_begPath,m_proPath;
};
