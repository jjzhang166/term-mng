#pragma once


// CPage12 �Ի���

class CPage12 : public CDialog
{
	DECLARE_DYNAMIC(CPage12)

public:
	CPage12(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPage12();

// �Ի�������
	enum { IDD = IDD_SYSTEM12 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
