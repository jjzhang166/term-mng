#pragma once


// CProp1_2 �Ի���

class CProp1_2 : public CPropertyPage
{
	DECLARE_DYNAMIC(CProp1_2)

public:
	CProp1_2();
	virtual ~CProp1_2();

// �Ի�������
	enum { IDD = IDD1_PROP2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual LRESULT OnWizardNext();
	CString m_ip;
	virtual BOOL OnSetActive();
	afx_msg void OnCbnSelchangeCombo7();
	virtual BOOL OnInitDialog();
};
