#pragma once


// CShutDown �Ի���

class CShutDown : public CDialogEx
{
	DECLARE_DYNAMIC(CShutDown)

public:
	CShutDown(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CShutDown();

// �Ի�������
	enum { IDD = IDD_SHUTDOWN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
