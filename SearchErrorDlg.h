
// SearchErrorDlg.h : ���� ���������
//

#pragma once


// ���������� ���� CSearchErrorDlg
class CSearchErrorDlg : public CDialogEx
{
// ��������
public:
	CSearchErrorDlg(CWnd* pParent = NULL);	// ����������� �����������

// ������ ����������� ����
	enum { IDD = IDD_SEARCHERROR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// ��������� DDX/DDV


// ����������
protected:
	HICON m_hIcon;

	// ��������� ������� ����� ���������
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
