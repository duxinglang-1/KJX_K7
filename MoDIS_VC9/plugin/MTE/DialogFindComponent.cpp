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
 * DialogFindComponent.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implemented the find theme component dialog
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

// DialogFindComponent.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "DialogThemeEditor.h"
#include "DialogFindComponent.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern int g_Theme_Lan;

#define MessageShow(string) MessageBox(this->m_hWnd,string,"MoDIS_UI",MB_OK)

/////////////////////////////////////////////////////////////////////////////
// CDialogFindComponent dialog

WCHAR SearchResultSC[30] = { 0x641C, 0x5BFB, 0x7ED3, 0x679C, 0xFF1A, 0x0000 } ;

// CDialogFindComponent::CDialogFindComponent(CWnd* pParent /*=NULL*/)
// 	: CDialog(CDialogFindComponent::IDD, pParent)
// {
// 	//{{AFX_DATA_INIT(CDialogFindComponent)
// 		// NOTE: the ClassWizard will add member initialization here
// 	//}}AFX_DATA_INIT
// }

CDialogFindComponent::CDialogFindComponent(CDialogThemeEditor* pEditor)
	: CDialog(CDialogFindComponent::IDD, (CWnd*)pEditor)
{
	m_pThemeEditor = pEditor;
	ASSERT(NULL != m_pThemeEditor);
}

void CDialogFindComponent::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogFindComponent)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogFindComponent, CDialog)
	//{{AFX_MSG_MAP(CDialogFindComponent)

	ON_BN_CLICKED(IDOK, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogFindComponent message handlers


BOOL CDialogFindComponent::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CEdit*   p   =   (CEdit*)GetDlgItem(   IDC_EDIT_COMPONENT_NAME   );   
    CString   a   =   _T("");   
    p->SetWindowText(   a   );   
    p->SetFocus();   
    p->SetSel(a.GetLength(),   a.GetLength()   ); 
    p->SetLimitText(30);
    return   FALSE;  
}
void CDialogFindComponent::OnOk() 
{
	int i;
	CString srhpat;
	GetDlgItem(IDC_EDIT_COMPONENT_NAME)->GetWindowText(srhpat);
	if(srhpat.GetLength()==0)
	{
		::MessageShow("Please input component name.");
		return;
	}
	else
	{
		CString temp = "", temp2(SearchResultSC), temp3(L"Search Result:");
		int index_temp = m_pThemeEditor->m_ComboComGroup.GetCurSel();
		if (index_temp != -1)
		{
			m_pThemeEditor->m_ComboComGroup.GetLBText(index_temp,temp);
		}

	
		short nofound[1024];
	
		//int theme_idx =  m_pThemeEditor->m_ListThemeEditor.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
		//From 0, not From select index
		int theme_idx =0;
		int theme_cnt = m_pThemeEditor->m_ListThemeEditor.GetItemCount(); 
	
		bool b_found=false;
		unsigned short nofound_num =0;
		int m_nfound = 0;
		for(i =theme_idx;i<theme_cnt;i++)
		{
			char theme_str[512];
			m_pThemeEditor->m_ListThemeEditor.GetItemText(i,1,theme_str,512); //1 mean component name
			CString str_theme(theme_str);
			TRACE("str_theme = %s\n",str_theme);
			if(str_theme.Find(srhpat)!=-1)//find such pattern
			{
				
				b_found = true;
				m_nfound++;
			}
			else
			{
				nofound[nofound_num] = i;
				nofound_num ++;
			}
			if(i==theme_cnt-1)
			{
				if(!b_found)
				{
					::MessageShow("The theme component is not found.");
					return;
				}
				else
				{
					m_pThemeEditor->m_StaticWarningScreen.ShowWindow(SW_HIDE);
					if (!temp.CompareNoCase(temp3) || !temp.CompareNoCase(temp2)||!temp.CompareNoCase(""))
					{
						m_pThemeEditor->m_notedit = true;
						m_pThemeEditor->DisableThemeComponent(false,false,false,false);
						m_pThemeEditor->ShowHideSliceControls(false);
						m_pThemeEditor->DrawNonBitmap();
						m_pThemeEditor->m_old_theme_idx = -1;  
					}
					else
					{
						m_pThemeEditor->UpdateListTheme();  
						m_pThemeEditor->m_notedit = true;
						m_pThemeEditor->DisableThemeComponent(false,false,false,false);
						m_pThemeEditor->ShowHideSliceControls(false);
						m_pThemeEditor->DrawNonBitmap();
						m_pThemeEditor->m_old_theme_idx = -1;
					}
				}
			}
		}
		if (m_nfound == 0)
		{
			::MessageShow("The theme component is not found.");
			return;
		}
		for(i=0;i<nofound_num;i++)
		{
			m_pThemeEditor->m_ListThemeEditor.DeleteItem(nofound[i]-i);
		}
	/*
		for(int kk=0;kk<count;kk++)
		{	
			m_pThemeEditor->m_ComboComGroup.DeleteString(0);
		}
	*/	
		//m_pThemeEditor->m_ComboComGroup.AddString("Search Result:"+srhpat);
	if (!temp.CompareNoCase(temp3) || !temp.CompareNoCase(temp2) )
	{
		;
	}
	else
	{
	int count = m_pThemeEditor->m_ComboComGroup.GetCount();
	
	HWND hwndCB = ::GetDlgItem(m_pThemeEditor->m_hWnd,IDC_COMBO_COMPONENT_GROUP_EX);
	COMBOBOXEXITEMW ComboItemW; 
	memset(&ComboItemW,0,sizeof(ComboItemW)); 
	//ComboItemW.pszText=L"Search Result:";//+srhpat; 
	if( g_Theme_Lan == 0 )
	    ComboItemW.pszText = L"Search Result:";
	else if( g_Theme_Lan == 1 )
		ComboItemW.pszText = SearchResultSC;	
	ComboItemW.mask = CBEIF_TEXT; 
	ComboItemW.iItem=count; 
	::SendMessage(hwndCB,CBEM_INSERTITEMW,-1,(LPARAM)&ComboItemW); 	
	m_pThemeEditor->m_ComboComGroup.SetCurSel(count);
	}
	m_pThemeEditor->m_find = true;
	}
	CDialog::OnOK();
}
