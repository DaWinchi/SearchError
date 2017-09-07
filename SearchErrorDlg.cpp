
// SearchErrorDlg.cpp : файл реализации
//
#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "SearchError.h"
#include "SearchErrorDlg.h"
#include "afxdialogex.h"
#include "WinError.h"
#include <iostream>
#include <stdio.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно CSearchErrorDlg



CSearchErrorDlg::CSearchErrorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSearchErrorDlg::IDD, pParent)
	, error_id(_T("5"))
	, text_error(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSearchErrorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEXT_SEARCH, error_id);
	DDX_Text(pDX, IDC_TEXT_ERROR, text_error);
}

BEGIN_MESSAGE_MAP(CSearchErrorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CLOSE, &CSearchErrorDlg::OnBnClickedClose)
	ON_BN_CLICKED(IDC_SEARCH, &CSearchErrorDlg::OnBnClickedSearch)
END_MESSAGE_MAP()


// обработчики сообщений CSearchErrorDlg

BOOL CSearchErrorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CSearchErrorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CSearchErrorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSearchErrorDlg::OnBnClickedClose()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialog::OnCancel();

}


void CSearchErrorDlg::OnBnClickedSearch()
{
	// TODO: добавьте свой код обработчика уведомлений

	UpdateData();
	LPTSTR text;

	int id=0;
	swscanf_s((error_id.GetBuffer()), _T("%i"), &id);




	::FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER, NULL, id, 0, (LPTSTR)&text, 0, NULL);

	text_error.Format(_T("%s"), text);

	UpdateData(FALSE);

	::LocalFree(text);


}
