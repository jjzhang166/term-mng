#pragma once


// CProp1_3 �Ի���

class CProp1_3 : public CPropertyPage
{
	DECLARE_DYNAMIC(CProp1_3)

public:
	CProp1_3();
	virtual ~CProp1_3();

// �Ի�������
	enum { IDD = IDD1_PROP3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	CComboBox m_combox1;
	CComboBox m_combox2;
	CComboBox m_combox3;
	CComboBox m_combox4;
	CComboBox m_combox5;
	CComboBox m_combox6;
	CComboBox m_combox7;
	CComboBox m_combox8;
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo6();
};
