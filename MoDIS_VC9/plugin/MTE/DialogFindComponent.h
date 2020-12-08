#if !defined(AFX_DIALOGFINDCOMPONENT_H__65EEE060_3CE3_4572_B837_B15C9E33AF6E__INCLUDED_)
#define AFX_DIALOGFINDCOMPONENT_H__65EEE060_3CE3_4572_B837_B15C9E33AF6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogFindComponent.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDialogFindComponent dialog

class CDialogFindComponent : public CDialog
{
// Construction
public:
	//CDialogFindComponent(CWnd* pParent = NULL);   // standard constructor
	CDialogFindComponent(CDialogThemeEditor* pEditor);   

// Dialog Data
	//{{AFX_DATA(CDialogFindComponent)
	enum { IDD = IDD_DIALOG_FIND_COMPONENT };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogFindComponent)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	CDialogThemeEditor* m_pThemeEditor;
	// Generated message map functions
	//{{AFX_MSG(CDialogFindComponent)
	
	virtual BOOL OnInitDialog();
	afx_msg void OnOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGFINDCOMPONENT_H__65EEE060_3CE3_4572_B837_B15C9E33AF6E__INCLUDED_)
