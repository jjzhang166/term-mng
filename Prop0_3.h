#pragma once


// CProp0_3 对话框

class CProp0_3 : public CPropertyPage
{
	DECLARE_DYNAMIC(CProp0_3)

public:
	CProp0_3();
	virtual ~CProp0_3();

// 对话框数据
	enum { IDD = IDD0_PROP3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
	CString m_filepath;
	CString m_begfile;
	virtual BOOL OnInitDialog();
//	virtual BOOL OnWizardFinish();
	int m_radio;
	afx_msg void OnClickedRadio11();
	afx_msg void OnRadio12();
	virtual LRESULT OnWizardNext();
//	virtual BOOL OnWizardFinish();
};
