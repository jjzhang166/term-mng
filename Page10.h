#pragma once


// CPage10 �Ի���

class CPage10 : public CDialog
{
	DECLARE_DYNAMIC(CPage10)

public:
	CPage10(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPage10();

// �Ի�������
	enum { IDD = IDD_SYSTEM10 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	//CString m_ResShow;
	//CEdit m_HostName;
	//CString m_getHname;
	//HANDLE m_ListenThreadHandle;
	//CEdit m_setEmpty;
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButton1();
	void ClearAll(void);
};
