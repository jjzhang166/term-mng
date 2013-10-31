#pragma once


// CSetIP 对话框

class CSetIP : public CDialog
{
	DECLARE_DYNAMIC(CSetIP)

public:
	CSetIP(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSetIP();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//CComboBox m_ctlAdapters;
	CIPAddressCtrl m_ctlNetMask;
//	CIPAddressCtrl m_m_ctlNetGate;
	CIPAddressCtrl m_ctlNetGate;
	CIPAddressCtrl m_ctlIPAddress;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	virtual BOOL DestroyWindow();
	afx_msg void OnSelchangeMCtladapters();
//	CComboBox m_m_ctlAdapters;
	CComboBox m_ctlAdapters1;
	afx_msg void OnCbnSelchangectladapters();
};
