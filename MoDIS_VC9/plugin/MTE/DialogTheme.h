/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 * DialogTheme.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implemented the Version dialog
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if !defined(AFX_DIALOGTHEME_H__9770FD44_DCA7_45D9_B182_0D158C507B3D__INCLUDED_)
#define AFX_DIALOGTHEME_H__9770FD44_DCA7_45D9_B182_0D158C507B3D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DialogTheme.h : header file
//
#include "DialogThemeEditor.h"
#include "mtegprot.h"
#include "XMLite.h"
#include "DialogProcess.h"
#include <string>

//Plugin
#include "plugin.h"
#include "plugin_hlpr.h"
#include "uiplugin.h"
#include <Shlwapi.h>

/////////////////////////////////////////////////////////////////////////////
// CDialogTheme dialog

#define MAX_THEME_NUM 10
#define MAX_THEME_COM_NUM 1000
#define MessageShow(string) MessageBox(this->m_hWnd,string,"MoDIS_UI",MB_OK)
class CDialogTheme : public CDialog
{
// Construction
public:
	CDialogTheme(CWnd* pParent = NULL);   // standard constructor
	CDialogTheme(CWnd* pParent /*=NULL*/, void (*(*w32_mmi_mte_api_cb)(int))(void) );
	int m_total_system_theme_num;
	int m_total_system_theme_size;
	int m_total_edit_theme_num;
    bool b_output_sucessful;
	void InitialSpecificTheCom();
	void (*(*w32_mmi_mte_api)(int))(void);
	CDialogProcess m_dlgpro;
	void UpdatePosition();
	void EnableThemeEditor();
	
	void EnableAllButtons(bool flag); 
	//MMI_theme *theme_ptr; //wayne add resveration
	MMI_theme *m_edit_theme_list[MAX_THEME_NUM];
	CString m_LastOffsetStrinTheme;
	const MMI_theme *m_system_theme_list[MAX_THEME_NUM];
	
	void SetParent(CWnd* pParent /*=NULL*/);
	CWnd		*main_dlg;
	CDialogThemeEditor *theme_editor_dlg;
	FILE *m_fp1;
	//void WriteReadUI_filled_area(UI_filled_area *ptr, bool b_write);
	//void WriteReadcolor(color *ptr, bool b_write);
	CString MakeColorStr(CString structname,CString type,color *ptr);
	CString MakeUI_filled_areaStr(CString structname,CString type,UI_filled_area *ptr);
	CString MakeOtherStr(MMI_theme mmi_theme,int theme_id);
	CString MakeUI_imageStr(CString structname,unsigned char *ptr);
    CString Make_IntegerStr(const MMI_theme *theme);
	void GetModifyFlagComByStr(CString theme_name,int theme_id);	

	void InitialTheComArray();
	bool m_loadmte;
	CString m_mtexmlstr[MAX_THEME_NUM];

     MMI_theme *m_DefaultSystemTheme;
	
	CString CodeGenMakeFiller(CString theme_name,CString filler_name, MMI_theme theme,int theme_idx,int filler_idx);
	CString CodeGenMakeColor(CString theme_name,CString color_name, MMI_theme theme);

	int GetThemeComID(CString member);
	CString GenImageToArray(unsigned char *ptr,CString name);
	CString MakeColorAttrStr(CString structname,CString type,color *ptr);
	XNode m_xmlnode;
	XNode m_xmlallnodes;
	CString m_retimage[1024];
	CString GenImageRet(MMI_theme *mmi_theme, CString member,CString themename,CString strTemp,int theme_idx);
	int m_image_count; 
	int m_image_link;
    float GetThemeComSize(MMI_theme *mmi_theme, CString member,bool type);
	/*int GetThemeComSize(MMI_theme *mmi_theme, CString member,bool type);*/
	int CountTotalThemeSize();
	void DisplayTotalSize();
	CString FillerCheckSameFiller(int theme_idx,int filler_idx);
	bool CompareFillerorImage(char *pat,char *dest);
	CString ImageCheckSameFillerandImage(char *image,int theme_idx,CString member);
	bool SaveTheme();
	CString m_savepath;
	CString GetThemeNameVal(CString theme_name);
	CString GetStrFromThemeNameVal(CString theme_name);
	
	CListCtrl	m_ListTheme;

	CString m_strVersion;

	//Plugin
protected:
	CHAR m_szCurDllName[MAX_PATH];
	plugin_information m_plugin_info;
	PLUG_IN_INT_PARAM m_int_param;
	BOOL m_bDisabled;
	UINT InitPlugin();

	//CString MakeUI_font_typeStr(CString structname,CString type,UI_font_type ptr);
	// Dialog Data
	//{{AFX_DATA(CDialogTheme)
	enum { IDD = IDD_DIALOG_THEME };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogTheme)
	public:
	//virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogTheme)
	afx_msg void OnClose();
	afx_msg void OnEdit();
	afx_msg void OnCopyasnew();
	afx_msg void OnDelete();
	afx_msg void OnOutput();
	afx_msg void OnLoadTheme();
	afx_msg LRESULT OnPluginMessage(WPARAM wParam, LPARAM lParam);
//	afx_msg void OnSavetheme();
	virtual BOOL OnInitDialog();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    CString ConvertThemeToXML(const MMI_theme *theme,
                              const CString &themeName,
                              int themeID);

    UI_filled_area *GetFillerPtr(const MMI_theme *theme,
                                 const CString &componentName);

    color *GetColorPtr(const MMI_theme *theme, const CString &componentName);

    UI_font_type GetFontPtr(const MMI_theme *theme,
                                 const CString &componentName);

    unsigned char *GetImagePtr(const MMI_theme *theme,
                               const CString &componentName);

    CString MakeUI_font_typeStr(const CString &name,
                                const CString &type,
                                UI_font_type ptr);

    CString FindDuplicateFont(int themeIndex, int fontIndex);

    CString GenerateFontStructure(const MMI_theme *theme,
                                  const CString &fontName,
                                  const CString &themeName);

	void LoadThemeComponents(MMI_theme *theme);
	
    void LoadColor(MMI_theme *theme,
                   const mmi_mte_theme_component_struct *component,
                   const CString &xmlNodeName);

    void LoadFiller(MMI_theme *theme,
                    const mmi_mte_theme_component_struct *component,
                    const CString &xmlNodeName);

    void LoadImage(MMI_theme *theme,
                   const mmi_mte_theme_component_struct *component,
                   const CString &xmlNodeName);

    void LoadFont(MMI_theme *theme,
                  const mmi_mte_theme_component_struct *component,
                  const CString &xmlNodeName);

    void LoadInteger(MMI_theme *theme,
                     const mmi_mte_theme_component_struct *component,
                     const CString &xmlNodeName);
	
    void LoadFillerMembers(UI_filled_area *filler, const CString &xmlNodeName);

    void* GetComponentAddr(const MMI_theme *theme,
                           const mmi_mte_theme_component_struct *component);

    void* GetComponentAddr(const MMI_theme *theme,
                           const CString &componentName);

    CString ReadFile(const CString &filename);
	CString ReadFileW(const std::wstring &filename);
    bool CheckThemeVersion();
	void EnableMinimizeButton(bool bEnable);
    void RunUnitTest();
protected:
	virtual void OnCancel();
	virtual void PostNcDestroy();
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGTHEME_H__9770FD44_DCA7_45D9_B182_0D158C507B3D__INCLUDED_)
