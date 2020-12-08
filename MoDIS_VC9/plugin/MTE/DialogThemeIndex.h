#if !defined(AFX_DIALOGTHEMEINDEX_H__FFD94C7A_9FB3_431D_8844_C740B5E4A33C__INCLUDED_)
#define AFX_DIALOGTHEMEINDEX_H__FFD94C7A_9FB3_431D_8844_C740B5E4A33C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogThemeIndex.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogThemeIndex dialog

class CDialogThemeIndex : public CDialog
{
// Construction
public:
	CDialogThemeIndex(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDialogThemeIndex)
	enum { IDD = IDD_DIALOG_THEME_INDEX };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogThemeIndex)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogThemeIndex)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
	CWnd* m_pParent;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGTHEMEINDEX_H__FFD94C7A_9FB3_431D_8844_C740B5E4A33C__INCLUDED_)
