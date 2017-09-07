
// SearchErrorDlg.h : файл заголовка
//

#pragma once


// диалоговое окно CSearchErrorDlg
class CSearchErrorDlg : public CDialogEx
{
// Создание
public:
	CSearchErrorDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
	enum { IDD = IDD_SEARCHERROR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedClose();
	afx_msg void OnBnClickedSearch();
	CString error_id;
	CString text_error;
};
