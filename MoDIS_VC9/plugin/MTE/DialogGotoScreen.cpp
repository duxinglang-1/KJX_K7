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
 * DialogGotoScreen.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implemented the Goto Specific Screen dialog
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

// DialogGotoScreen.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "DialogThemeEditor.h"
#include "DialogGotoScreen.h"
#include "mtegprot.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogGotoScreen dialog

#define START_CURRENT_SCR  "----Current Screen----"

CDialogGotoScreen::CDialogGotoScreen(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogGotoScreen::IDD, pParent)
{
	m_pThemeEditor = pParent;
}

CDialogGotoScreen::CDialogGotoScreen(CWnd* pParent /*=NULL*/, void(*(*w32_mmi_mte_api_cb)(int))(void))
	: CDialog(CDialogGotoScreen::IDD, pParent)
{
	m_pThemeEditor = pParent;
	w32_mmi_mte_api=w32_mmi_mte_api_cb;
}
void CDialogGotoScreen::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBOBOXEX1, m_ComboScr);
}


BEGIN_MESSAGE_MAP(CDialogGotoScreen, CDialog)
	//{{AFX_MSG_MAP(CDialogGotoScreen)
	ON_WM_CREATE()
	ON_CBN_SELCHANGE(IDC_COMBOBOXEX1, OnSelchangeScreen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogGotoScreen message handlers

int CDialogGotoScreen::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	return 0;
}
void CDialogGotoScreen::OnSelchangeScreen()
{
	if (m_ComboScr.GetCurSel()<0)
	{
		m_ComboScr.SetCurSel(0);
	}
}
char* CDialogGotoScreen::ConvertBSTRToString(BSTR pSrc)
{
    if(!pSrc) return NULL;

    //convert even embeded NULL
    DWORD cb,cwch = ::SysStringLen(pSrc);

    char *szOut = NULL;

    if(cb = ::WideCharToMultiByte(CP_ACP, 0, pSrc, cwch + 1, NULL, 0, 0, 0))
    {
        szOut = new char[cb];
        if(szOut)
        {
            szOut[cb - 1]  = '\0';
            if(!::WideCharToMultiByte(CP_ACP, 0, pSrc, cwch + 1, szOut, cb, 0, 0))
            {
                delete []szOut;//clean up if failed;
                szOut = NULL;
            }
        }
    }

    return szOut;
}

BSTR CDialogGotoScreen::ConvertStringToBSTR(const char* pSrc)
{
    if(!pSrc) return NULL;

    DWORD cwch;

    BSTR wsOut(NULL);

    if(cwch = ::MultiByteToWideChar(CP_ACP, 0, pSrc, -1, NULL, 0))//get size minus NULL terminator
    {
		cwch--;
		wsOut = ::SysAllocStringLen(NULL, cwch);

		if(wsOut)
		{
			if(!::MultiByteToWideChar(CP_ACP, 0, pSrc, -1, wsOut, cwch))
			{
				if(ERROR_INSUFFICIENT_BUFFER == ::GetLastError())
					return wsOut;
				::SysFreeString(wsOut);//must clean up
				wsOut = NULL;
			}
		}
    }

    return wsOut;
}
BOOL CDialogGotoScreen::OnInitDialog() 
{
	CDialog::OnInitDialog();
	int example_screen_num;

	wchar_t* example_screen_name;
	example_screen_num  = mmi_mte_get_example_screen_num();
	HWND hwndCB = ::GetDlgItem(m_hWnd,IDC_COMBOBOXEX1);
	COMBOBOXEXITEMW ComboItemW; 
	memset(&ComboItemW,0,sizeof(ComboItemW)); 
	ComboItemW.mask = CBEIF_TEXT; 

	// Get the last example screen name.	
	for(int i=0;i<example_screen_num;i++)
	{
		example_screen_name = (wchar_t*)mmi_mte_get_example_screen_name(i);
		ComboItemW.pszText= example_screen_name;
		ComboItemW.iItem=i; 
		::SendMessage(hwndCB,CBEM_INSERTITEMW,-1,(LPARAM)&ComboItemW); 

	}
	m_ComboScr.SetCurSel(0);
	((CDialogThemeEditor*)m_pThemeEditor)->EnableWindow(false);
	return true;
}

void CDialogGotoScreen::OnOK() 
{
	if(m_ComboScr.GetCurSel() < 0)
		return;
    if(m_ComboScr.GetCurSel() >=0)
	{
		mmi_mte_show_example_screen(m_ComboScr.GetCurSel());

		((CDialogThemeEditor*)m_pThemeEditor)->m_group_name = START_CURRENT_SCR;
		((CDialogThemeEditor*)m_pThemeEditor)->m_ComboComGroup.SetCurSel(1);//1 mean START_CURRENT_SCR
		((CDialogThemeEditor*)m_pThemeEditor)->ShowCurrentScreen();
                mmi_mte_return_code_enum erronum = mmi_mte_is_controlarea_in_current_screen();	
 		if (MMI_MTE_SUCCESS == erronum)
 		{
			((CDialogThemeEditor*)m_pThemeEditor)->m_StaticWarningScreen.ShowWindow(SW_SHOW);
 		}
		else
		{
			((CDialogThemeEditor*)m_pThemeEditor)->m_StaticWarningScreen.ShowWindow(SW_HIDE);
		}
	}
	((CDialogThemeEditor*)m_pThemeEditor)->EnableWindow(true);
	CDialog::OnOK();
}
void CDialogGotoScreen::OnCancel() 
{
	((CDialogThemeEditor*)m_pThemeEditor)->EnableWindow(true);
	CDialog::OnCancel();
}
