#pragma once


// CPWD �Ի���

class CPWD : public CDialog
{
	DECLARE_DYNAMIC(CPWD)

public:
	CPWD(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPWD();

// �Ի�������
	enum { IDD = IDD_PWD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_pwd;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
