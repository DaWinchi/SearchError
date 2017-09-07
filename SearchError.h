
// SearchError.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CSearchErrorApp:
// О реализации данного класса см. SearchError.cpp
//

class CSearchErrorApp : public CWinApp
{
public:
	CSearchErrorApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CSearchErrorApp theApp;