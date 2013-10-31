#pragma once



// CPropSheet1
#include"PROP1_1.h"
#include"Prop1_2.h"
#include"Prop1_3.h"
class CPropSheet1 : public CPropertySheet
{
	DECLARE_DYNAMIC(CPropSheet1)

public:
	CPropSheet1(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPropSheet1(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CPropSheet1();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CPROP1_1 m_prop1;
	CProp1_2 m_prop2;
	CProp1_3 m_prop3;
};


