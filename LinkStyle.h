#pragma once


// CLinkStyle �Ի���

class CLinkStyle : public CDialog
{
	DECLARE_DYNAMIC(CLinkStyle)

public:
	CLinkStyle(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLinkStyle();

// �Ի�������
	enum { IDD = IDD_LINKSTYLE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
};
