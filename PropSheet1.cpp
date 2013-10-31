// PropSheet1.cpp : 实现文件
//

#include "stdafx.h"
#include "zaozhuang.h"
#include "PropSheet1.h"


// CPropSheet1

IMPLEMENT_DYNAMIC(CPropSheet1, CPropertySheet)

CPropSheet1::CPropSheet1(UINT nIDCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(nIDCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_prop1);
    AddPage(&m_prop2);
	AddPage(&m_prop3);
}

CPropSheet1::CPropSheet1(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	AddPage(&m_prop1);
	AddPage(&m_prop2);
	AddPage(&m_prop3);
}

CPropSheet1::~CPropSheet1()
{
}


BEGIN_MESSAGE_MAP(CPropSheet1, CPropertySheet)
END_MESSAGE_MAP()


// CPropSheet1 消息处理程序
