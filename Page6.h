#pragma once


// CPage6 �Ի���

class CPage6 : public CDialog
{
	DECLARE_DYNAMIC(CPage6)

public:
	CPage6(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPage6();

// �Ի�������
	enum { IDD = IDD_SYSTEM6 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
