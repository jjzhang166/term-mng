
// zaozhuang.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CzaozhuangApp:
// �йش����ʵ�֣������ zaozhuang.cpp
//

class CzaozhuangApp : public CWinApp
{
public:
	CzaozhuangApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
	void InitializeHook(void);
};

extern CzaozhuangApp theApp;