#pragma once


// CPROP1_1 �Ի���

class CPROP1_1 : public CPropertyPage
{
	DECLARE_DYNAMIC(CPROP1_1)

public:
	CPROP1_1();
	virtual ~CPROP1_1();

// �Ի�������
	enum { IDD = IDD1_PROP1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

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
