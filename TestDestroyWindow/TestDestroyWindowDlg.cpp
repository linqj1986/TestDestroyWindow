
// TestDestroyWindowDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestDestroyWindow.h"
#include "TestDestroyWindowDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTestDestroyWindowDlg dialog




CTestDestroyWindowDlg::CTestDestroyWindowDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTestDestroyWindowDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDestroyWindowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestDestroyWindowDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONCREATE, &CTestDestroyWindowDlg::OnBnClickedButtoncreate)
	ON_BN_CLICKED(IDC_BUTTONDESTROY, &CTestDestroyWindowDlg::OnBnClickedButtondestroy)
	ON_BN_CLICKED(IDC_BUTTON_CREATEMODAL, &CTestDestroyWindowDlg::OnBnClickedButtonCreatemodal)
	ON_BN_CLICKED(IDC_BUTTON_DESTROYMODAL, &CTestDestroyWindowDlg::OnBnClickedButtonDestroymodal)
END_MESSAGE_MAP()


// CTestDestroyWindowDlg message handlers

BOOL CTestDestroyWindowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_pADlg = NULL;
	m_pBDlg = NULL;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestDestroyWindowDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestDestroyWindowDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestDestroyWindowDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestDestroyWindowDlg::OnBnClickedButtoncreate()
{
	// TODO: Add your control notification handler code here
	BOOL needCreate = TRUE;
	if (m_pADlg)
	{
		if (!m_pADlg->GetSafeHwnd())
		{
			delete m_pADlg;
			m_pADlg = NULL;
		} else {
			needCreate = FALSE;
		}
	}

	if (needCreate)
	{
		m_pADlg = new CADlg();
		m_pADlg->Create(IDD_ADLG);
		m_pADlg->ShowWindow(SW_SHOW);
	}
}


void CTestDestroyWindowDlg::OnBnClickedButtondestroy()
{
	// TODO: Add your control notification handler code here
	if (m_pADlg)
	{
		if (m_pADlg->GetSafeHwnd())
		{
			// 方法1
			//m_pADlg->OnClose();
			// 方法2
			::SendMessageA(m_pADlg->GetSafeHwnd(),WM_CLOSE,0,0);
			 
			// 如果postmessage，因为非阻塞
			// 有可能wm_close消息还没被处理就执行了下面的delete，导致ADlg的onclose没有被执行？
			//::PostMessageA(m_pADlg->GetSafeHwnd(),WM_CLOSE,0,0);
		}

		delete m_pADlg;
		m_pADlg = NULL;
	}
}


void CTestDestroyWindowDlg::OnBnClickedButtonCreatemodal()
{
	// TODO: Add your control notification handler code here
	BOOL needCreate = TRUE;
	if (m_pBDlg)
	{
		if (!m_pBDlg->GetSafeHwnd())
		{
			delete m_pBDlg;
			m_pBDlg = NULL;
		} else {
			needCreate = FALSE;
		}
	}

	if (needCreate)
	{
		m_pBDlg = new CBDlg();
		m_pBDlg->DoModal();

		delete m_pBDlg;
		m_pBDlg = NULL;
	}
}


void CTestDestroyWindowDlg::OnBnClickedButtonDestroymodal()
{
	// TODO: Add your control notification handler code here

}
