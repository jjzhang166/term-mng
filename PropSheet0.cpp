// PropSheet0.cpp : 实现文件
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "PropSheet0.h"


// CPropSheet0

IMPLEMENT_DYNAMIC(CPropSheet0, CPropertySheet)

CPropSheet0::CPropSheet0(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_prop1);
	AddPage(&m_prop2);
	AddPage(&m_prop3);
	AddPage(&m_prop4);
}

CPropSheet0::CPropSheet0(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_prop1);
	AddPage(&m_prop2);
	AddPage(&m_prop3);
	AddPage(&m_prop4);
}

CPropSheet0::~CPropSheet0()
{
}


BEGIN_MESSAGE_MAP(CPropSheet0, CPropertySheet)
END_MESSAGE_MAP()


// CPropSheet0 消息处理程序
