#pragma once


// CPage5 �Ի���

class CPage5 : public CDialog
{
	DECLARE_DYNAMIC(CPage5)

public:
	CPage5(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPage5();

// �Ի�������
	enum { IDD = IDD_SYSTEM5 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
public:
	bool m_bSwap;
	afx_msg void OnBnClickedCheck1();
};
