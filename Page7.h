#pragma once


// CPage7 �Ի���

class CPage7 : public CDialog
{
	DECLARE_DYNAMIC(CPage7)

public:
	CPage7(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPage7();

// �Ի�������
	enum { IDD = IDD_SYSTEM7 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
