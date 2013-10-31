#pragma once



// CPropSheet0
#include"PROP0_1.h"
#include"Prop0_2.h"
#include"Prop0_3.h"
#include"Prop0_4.h"
class CPropSheet0 : public CPropertySheet
{
	DECLARE_DYNAMIC(CPropSheet0)

public:
	CPropSheet0(UINT nIDCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	CPropSheet0(LPCTSTR pszCaption, CWnd* pParentWnd = NULL, UINT iSelectPage = 0);
	virtual ~CPropSheet0();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CProp0_1 m_prop1;
	CProp0_2 m_prop2;
	CProp0_3 m_prop3;
	CProp0_4 m_prop4;
};


