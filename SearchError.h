
// SearchError.h : ������� ���� ��������� ��� ���������� PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"		// �������� �������


// CSearchErrorApp:
// � ���������� ������� ������ ��. SearchError.cpp
//

class CSearchErrorApp : public CWinApp
{
public:
	CSearchErrorApp();

// ���������������
public:
	virtual BOOL InitInstance();

// ����������

	DECLARE_MESSAGE_MAP()
};

extern CSearchErrorApp theApp;