#pragma once


// CADlg dialog

class CADlg : public CDialog
{
	DECLARE_DYNAMIC(CADlg)

public:
	CADlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CADlg();

// Dialog Data
	enum { IDD = IDD_ADLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClose();
	afx_msg void OnDestroy();

private:
	int* m_ptr;
};
