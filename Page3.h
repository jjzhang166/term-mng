#pragma once


// CPage3 �Ի���

class CPage3 : public CDialogEx
{
	DECLARE_DYNAMIC(CPage3)

public:
	CPage3(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPage3();

// �Ի�������
	enum { IDD = IDD_SYSTEM3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL OnInitDialog();
//	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
public:
	CComboBox m_combo1;
	CComboBox m_combo2;
	CComboBox m_combo3;
	virtual BOOL OnInitDialog();
//	afx_msg void OnCbnSelchangeCombo11();
//	afx_msg void OnCbnSelchangeCombo12();
//	afx_msg void OnCbnSelchangeCombo13();
	afx_msg void OnBnClickedButton3();
};
