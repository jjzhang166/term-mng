#pragma once


// CPage8 �Ի���

class CPage8 : public CDialog
{
	DECLARE_DYNAMIC(CPage8)

public:
	CPage8(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPage8();

// �Ի�������
	enum { IDD = IDD_SYSTEM8 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
