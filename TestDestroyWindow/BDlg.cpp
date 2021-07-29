// BDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestDestroyWindow.h"
#include "BDlg.h"
#include "afxdialogex.h"


// CBDlg dialog

IMPLEMENT_DYNAMIC(CBDlg, CDialog)

CBDlg::CBDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CBDlg::IDD, pParent)
{

}

CBDlg::~CBDlg()
{
}

void CBDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBDlg, CDialog)
END_MESSAGE_MAP()


// CBDlg message handlers
