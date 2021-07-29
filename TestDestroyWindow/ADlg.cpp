// ADlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestDestroyWindow.h"
#include "ADlg.h"
#include "afxdialogex.h"


// CADlg dialog

IMPLEMENT_DYNAMIC(CADlg, CDialog)

CADlg::CADlg(CWnd* pParent /*=NULL*/)
	: CDialog(CADlg::IDD, pParent)
{
	m_ptr = new int(10);
}

CADlg::~CADlg()
{
	// 释放成员
	delete m_ptr;
}

void CADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CADlg, CDialog)
	ON_WM_CLOSE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CADlg message handlers


void CADlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	CDialog::OnClose();	//默认的onclose只关闭窗口，并没有摧毁cadlg对象，即m_hWnd还有值

	// 摧毁cadlg对象
	DestroyWindow();
}


void CADlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: Add your message handler code here
}

