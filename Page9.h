#pragma once


// CPage9 �Ի���

class CPage9 : public CDialog
{
	DECLARE_DYNAMIC(CPage9)

public:
	CPage9(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPage9();

// �Ի�������
	enum { IDD = IDD_SYSTEM9 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
