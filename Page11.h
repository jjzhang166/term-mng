#pragma once


// CPage11 �Ի���

class CPage11 : public CDialog
{
	DECLARE_DYNAMIC(CPage11)

public:
	CPage11(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPage11();

// �Ի�������
	enum { IDD = IDD_SYSTEM11 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
