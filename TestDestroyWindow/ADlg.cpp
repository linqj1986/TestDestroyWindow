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
	// �ͷų�Ա
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
	CDialog::OnClose();	//Ĭ�ϵ�oncloseֻ�رմ��ڣ���û�дݻ�cadlg���󣬼�m_hWnd����ֵ

	// �ݻ�cadlg����
	DestroyWindow();
}


void CADlg::OnDestroy()
{
	CDialog::OnDestroy();

	// TODO: Add your message handler code here
}

