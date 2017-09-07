
// SearchErrorDlg.cpp : ���� ����������
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


// ���������� ���� CSearchErrorDlg



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


// ����������� ��������� CSearchErrorDlg

BOOL CSearchErrorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ������ ������ ��� ����� ����������� ����.  ����� ������ ��� �������������,
	//  ���� ������� ���� ���������� �� �������� ����������
	SetIcon(m_hIcon, TRUE);			// ������� ������
	SetIcon(m_hIcon, FALSE);		// ������ ������

	// TODO: �������� �������������� �������������

	return TRUE;  // ������� �������� TRUE, ���� ����� �� ������� �������� ����������
}

// ��� ���������� ������ ����������� � ���������� ���� ����� ��������������� ����������� ���� �����,
//  ����� ���������� ������.  ��� ���������� MFC, ������������ ������ ���������� ��� �������������,
//  ��� ������������� ����������� ������� ��������.

void CSearchErrorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �������� ���������� ��� ���������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ������������ ������ �� ������ ����������� ��������������
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ��������� ������
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ������� �������� ��� ������� ��� ��������� ����������� ������� ��� �����������
//  ���������� ����.
HCURSOR CSearchErrorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSearchErrorDlg::OnBnClickedClose()
{
	// TODO: �������� ���� ��� ����������� �����������
	CDialog::OnCancel();

}


void CSearchErrorDlg::OnBnClickedSearch()
{
	// TODO: �������� ���� ��� ����������� �����������

	UpdateData();
	LPTSTR text;

	int id=0;
	swscanf_s((error_id.GetBuffer()), _T("%i"), &id);




	::FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER, NULL, id, 0, (LPTSTR)&text, 0, NULL);

	text_error.Format(_T("%s"), text);

	UpdateData(FALSE);

	::LocalFree(text);


}
