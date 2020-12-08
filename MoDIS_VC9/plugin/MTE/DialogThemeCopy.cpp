// DialogThemeCopy.cpp : implementation file
//

#include "stdafx.h"
#include "modis_ui.h"
#include "DialogThemeCopy.h"
#include "UIDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CUIDlg		dlg;
/////////////////////////////////////////////////////////////////////////////
// CDialogThemeCopy dialog


CDialogThemeCopy::CDialogThemeCopy(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogThemeCopy::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogThemeCopy)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDialogThemeCopy::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogThemeCopy)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogThemeCopy, CDialog)
	//{{AFX_MSG_MAP(CDialogThemeCopy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogThemeCopy message handlers

void CDialogThemeCopy::OnOK() 
{
	// TODO: Add extra validation here
	dlg.theme_dlg->m_ListTheme.DeleteAllItems();
	CString CopyIdx;
	GetDlgItem(IDC_EDIT_COPY_THEME)->GetWindowText(CopyIdx);
	//CWnd *wndDlg = GetParent();
	//wndDlg->m_ListTheme.DeleteAllItems();
	
	CDialog::OnOK();
}
