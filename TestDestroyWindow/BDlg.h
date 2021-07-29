#pragma once


// CBDlg dialog

class CBDlg : public CDialog
{
	DECLARE_DYNAMIC(CBDlg)

public:
	CBDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CBDlg();

// Dialog Data
	enum { IDD = IDD_BDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

};
