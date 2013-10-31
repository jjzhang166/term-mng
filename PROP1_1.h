#pragma once


// CPROP1_1 对话框

class CPROP1_1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CPROP1_1)

public:
	CPROP1_1();
	virtual ~CPROP1_1();

// 对话框数据
	enum { IDD = IDD1_PROP1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual LRESULT OnWizardNext();
	CString m_connect;
	virtual BOOL OnSetActive();
	CComboBox m_combox1;
	CComboBox m_combox2;
	CComboBox m_combox3;
	virtual BOOL OnInitDialog();
};
