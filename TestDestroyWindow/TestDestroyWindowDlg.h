
// TestDestroyWindowDlg.h : header file
//

#pragma once

#include "ADlg.h"
#include "BDlg.h"

// CTestDestroyWindowDlg dialog
class CTestDestroyWindowDlg : public CDialogEx
{
// Construction
public:
	CTestDestroyWindowDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TESTDESTROYWINDOW_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtoncreate();

private:
	CADlg *m_pADlg;
	CBDlg *m_pBDlg;

public:
	afx_msg void OnBnClickedButtondestroy();
	afx_msg void OnBnClickedButtonCreatemodal();
	afx_msg void OnBnClickedButtonDestroymodal();
};
