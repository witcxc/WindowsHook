
// KeyboardHookEXE.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CKeyboardHookEXEApp:
// �йش����ʵ�֣������ KeyboardHookEXE.cpp
//

class CKeyboardHookEXEApp : public CWinApp
{
public:
	CKeyboardHookEXEApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CKeyboardHookEXEApp theApp;