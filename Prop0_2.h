#pragma once


// CProp0_2 对话框

class CProp0_2 : public CPropertyPage
{
	DECLARE_DYNAMIC(CProp0_2)

public:
	CProp0_2();
	virtual ~CProp0_2();

// 对话框数据
	enum { IDD = IDD0_PROP2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual LRESULT OnWizardNext();
	virtual BOOL OnSetActive();
	BOOL m_check;
	CString m_name;
	CString m_pwd;
	CString m_ip;
	afx_msg void OnClickedCheck1();
	virtual BOOL OnInitDialog();
};
