#pragma once


// CProp0_4 �Ի���

class CProp0_4 : public CPropertyPage
{
	DECLARE_DYNAMIC(CProp0_4)

public:
	CProp0_4();
	virtual ~CProp0_4();

// �Ի�������
	enum { IDD = IDD0_PROP4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	virtual BOOL OnWizardFinish();
};
