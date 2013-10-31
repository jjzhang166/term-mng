#pragma once


// CProp0_1 对话框

class CProp0_1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CProp0_1)

public:
	CProp0_1();
	virtual ~CProp0_1();

// 对话框数据
	enum { IDD = IDD0_PROP1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual LRESULT OnWizardNext();
	virtual BOOL OnSetActive();
	CString m_name;
	CString m_ip;
};
