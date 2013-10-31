#pragma once


// CSystemSet 对话框
#include"Page1.h"
#include"Page2.h"
#include"Page3.h"
#include"Page4.h"
#include"Page5.h"
#include"Page6.h"
#include"Page7.h"
#include"Page8.h"
#include"Page9.h"
#include"Page10.h"
#include"Page11.h"
#include"Page12.h"
class CSystemSet : public CDialog
{
	DECLARE_DYNAMIC(CSystemSet)

public:
	CSystemSet(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSystemSet();

// 对话框数据
	enum { IDD = IDD_SYSTEMSET };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	CPage1 page1;
	CPage2 page2;
	CPage3 page3;
	CPage4 page4;
	CPage5 page5;
	CPage6 page6;
	CPage7 page7;
	CPage8 page8;
	CPage9 page9;
	CPage10 page10;
	CPage11 page11;
	CPage12 page12;
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
};
