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
 * DialogThemeSetting.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

// DialogThemeSetting.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "DialogThemeSetting.h"
#include "DialogThemeEditor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogThemeSetting dialog

extern bool g_hidetheme;
//extern CUIDlg		dlg;
CDialogThemeSetting::CDialogThemeSetting(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogThemeSetting::IDD, pParent)
{
	m_pParent = pParent;
	ASSERT(NULL != m_pParent);
}


void CDialogThemeSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogThemeSetting)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogThemeSetting, CDialog)
	//{{AFX_MSG_MAP(CDialogThemeSetting)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogThemeSetting message handlers

int CDialogThemeSetting::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}
void CDialogThemeSetting::OnOK() 
{
	// TODO: Add extra validation here
    CButton *pBtn=NULL;
	pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
	CString restr;
	if(pBtn->GetCheck())
	{	
		g_hidetheme = true;
		restr.Format("TRUE");
	}
	else 
	{
		g_hidetheme = false;
		restr.Format("FALSE");	
	}
	char path[1024],tempbuf[1024];
	char *name;
	memset(tempbuf, 0, sizeof(tempbuf));
	if(!SearchPath(NULL, "MoDIS.exe", NULL, sizeof(path), path, &name))		         
				return ;
	strncpy(tempbuf, path, strlen(path)-strlen(name));
	sprintf(path, "%sMoDIS.ini", tempbuf);
	WritePrivateProfileString("INTEGRATE", "HIDE_THEME", restr, path);

	if( ((CDialogThemeEditor *)m_pParent)->IsEditingAnimation() )
		((CDialogThemeEditor *)m_pParent)->LeaveAnimationEditingMode();
	
	((CDialogThemeEditor *)m_pParent)->UpdateListTheme();
	((CDialogThemeEditor *)m_pParent)->m_notedit = true;
	((CDialogThemeEditor *)m_pParent)->DisableThemeComponent(false,false,false,false);
	((CDialogThemeEditor *)m_pParent)->DrawNonBitmap();
	((CDialogThemeEditor *)m_pParent)->m_old_theme_idx = -1;
	((CDialogThemeEditor *)m_pParent)->ShowHideSliceControls(false);
	CDialog::OnOK();
}
BOOL CDialogThemeSetting::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CButton *pBtn=NULL;
	pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
	pBtn->SetCheck(g_hidetheme);
	return true;
}
