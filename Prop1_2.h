#pragma once


// CProp1_2 对话框

class CProp1_2 : public CPropertyPage
{
	DECLARE_DYNAMIC(CProp1_2)

public:
	CProp1_2();
	virtual ~CProp1_2();

// 对话框数据
	enum { IDD = IDD1_PROP2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual LRESULT OnWizardNext();
	CString m_ip;
	virtual BOOL OnSetActive();
	afx_msg void OnCbnSelchangeCombo7();
	virtual BOOL OnInitDialog();
};
