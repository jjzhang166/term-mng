#pragma once


// CSetPwd �Ի���

class CSetPwd : public CDialog
{
	DECLARE_DYNAMIC(CSetPwd)

public:
	CSetPwd(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSetPwd();

// �Ի�������
	enum { IDD = IDD_DIALOG4 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_edit1;
	CString m_edit2;
	CString m_edit3;
	afx_msg void OnBnClickedOk();
};
