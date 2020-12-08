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
 * DialogThemeIndex.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

// DialogThemeIndex.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "DialogThemeIndex.h"
#include "DialogTheme.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogThemeIndex dialog


CDialogThemeIndex::CDialogThemeIndex(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogThemeIndex::IDD, pParent)
{
	m_pParent = pParent;
	ASSERT(NULL != m_pParent);
}


void CDialogThemeIndex::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogThemeIndex)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogThemeIndex, CDialog)
	//{{AFX_MSG_MAP(CDialogThemeIndex)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDCANCEL, OnCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogThemeIndex message handlers

int CDialogThemeIndex::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	
	return 0;
}
void CDialogThemeIndex::OnCancel()
{
	CDialog::OnCancel();
}
BOOL CDialogThemeIndex::OnInitDialog() 
{
	CDialog::OnInitDialog();
	int theme_idx =  ((CDialogTheme*)m_pParent)->m_ListTheme.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);

	char theme_str[512];
	((CDialogTheme*)m_pParent)->m_ListTheme.GetItemText(theme_idx,1,theme_str,512);
	GetDlgItem(IDC_EDIT_FROM)->SetWindowText(theme_str);
	
	((CEdit*)GetDlgItem(IDC_EDIT_INDEX))->SetLimitText(3);//limit index index
	((CEdit*)GetDlgItem(IDC_EDIT_NAME))->SetLimitText(20);//limit index name
	
	return TRUE;
}
void CDialogThemeIndex::OnOK() 
{
	// TODO: Add extra validation here
	CString theme_copy_str;

	GetDlgItem(IDC_EDIT_NAME)->GetWindowText(theme_copy_str);
	if(theme_copy_str=="")
	{
		::MessageShow("Please input theme name.");
		return;
	}
	int theme_idx =  ((CDialogTheme*)m_pParent)->m_ListTheme.GetNextItem(-1,LVNI_ALL|LVNI_SELECTED);
	char theme_str[512];
	((CDialogTheme*)m_pParent)->m_ListTheme.GetItemText(theme_idx,1,theme_str,512);
	
	CString nid;
	GetDlgItem(IDC_EDIT_INDEX)->GetWindowText(nid);

	if(nid.GetLength()==0||nid.GetLength()>3)
	{
		::MessageShow("Please input correct theme index.");
		return;
	}
	
	int theme_count = ((CDialogTheme*)m_pParent)->m_ListTheme.GetItemCount();
	if(atoi(nid)>theme_count+1)
	{
		CString warnstr;
		warnstr.Format("The theme is copied to index number %d.",theme_count+1);
		::MessageShow(warnstr);
		nid.Format("%d",theme_count+1);
	}
	if(atoi(nid)<1)
	{
		CString warnstr;
		warnstr.Format("Minimum theme index is 1.");
		::MessageShow(warnstr);
		return;
	}
	//((CDialogTheme*)m_pParent)->m_edit_theme_list[((CDialogTheme*)m_pParent)->m_total_edit_theme_num] = new MMI_theme;
	((CDialogTheme*)m_pParent)->m_edit_theme_list[theme_count] = new MMI_theme;	

	if(atoi(nid)==(theme_count+1))//last record
	{
		memcpy(((CDialogTheme*)m_pParent)->m_edit_theme_list[((CDialogTheme*)m_pParent)->m_total_edit_theme_num], ((CDialogTheme*)m_pParent)->m_edit_theme_list[theme_idx], sizeof(MMI_theme));
		((CDialogTheme*)m_pParent)->m_mtexmlstr[((CDialogTheme*)m_pParent)->m_total_edit_theme_num] = ((CDialogTheme*)m_pParent)->m_mtexmlstr[theme_idx];
		
		((CDialogTheme*)m_pParent)->m_total_edit_theme_num ++;
		CString idstr;
		idstr.Format("%d",theme_count+1);
		((CDialogTheme*)m_pParent)->m_ListTheme.InsertItem(LVIF_TEXT|LVIF_STATE, theme_count,idstr,0, LVIS_SELECTED,0, 0);
		((CDialogTheme*)m_pParent)->m_ListTheme.SetItemText(theme_count,1,theme_copy_str);
	}

	else
	{
		//insert first, beacuse 003 is 3 not insert 003, so atoi(nid)
		CString idstr;
		idstr.Format("%d",atoi(nid));
		((CDialogTheme*)m_pParent)->m_ListTheme.InsertItem(LVIF_TEXT|LVIF_STATE, theme_count,idstr,0, LVIS_SELECTED,0, 0);
		((CDialogTheme*)m_pParent)->m_ListTheme.SetItemText(theme_count,1,theme_copy_str);
		
	
		for( int kk=atoi(nid);kk<=theme_count;kk++)
		{
			int id = atoi(nid); 
			char theme_str[512];
			//char theme_id[512];
			//itoa(kk+1,10)
			//((CDialogTheme*)m_pParent)->m_ListTheme.GetItemText(kk-1,0,theme_id,512);
			CString theme_id;
			theme_id.Format("%d",kk+1);
			((CDialogTheme*)m_pParent)->m_ListTheme.GetItemText(id-1,1,theme_str,512);
			((CDialogTheme*)m_pParent)->m_ListTheme.DeleteItem(id-1);
			((CDialogTheme*)m_pParent)->m_ListTheme.InsertItem(LVIF_TEXT|LVIF_STATE, theme_count,theme_id,0, LVIS_SELECTED,0, 0);
			((CDialogTheme*)m_pParent)->m_ListTheme.SetItemText(theme_count,1,theme_str);
		}
		//((CDialogTheme*)m_pParent)->m_ListTheme.DeleteItem(jj-1);
		
		
		for(int jj=theme_count;jj>=atoi(nid);jj--)
		{	
		
				memcpy(((CDialogTheme*)m_pParent)->m_edit_theme_list[jj], ((CDialogTheme*)m_pParent)->m_edit_theme_list[jj-1], sizeof(MMI_theme));
				((CDialogTheme*)m_pParent)->m_mtexmlstr[jj] = ((CDialogTheme*)m_pParent)->m_mtexmlstr[jj-1];
		}
		
		memcpy(((CDialogTheme*)m_pParent)->m_edit_theme_list[atoi(nid)-1], ((CDialogTheme*)m_pParent)->m_edit_theme_list[theme_idx], sizeof(MMI_theme));
		((CDialogTheme*)m_pParent)->m_mtexmlstr[atoi(nid)-1] = ((CDialogTheme*)m_pParent)->m_mtexmlstr[theme_idx];

		((CDialogTheme*)m_pParent)->m_total_edit_theme_num ++;
	}
	/*
	for(int jj=0;jj<theme_count;jj++)
	{
		char theme_idx_char[16];
		((CDialogTheme*)m_pParent)->m_ListTheme.GetItemText(jj,0,theme_idx_char,16);
		if(nid.CompareNoCase(theme_idx_char)==0)
		{
			::AfxMessageBox("The theme index has existed, Please input another theme index");
			return;
		}
	}*/
	
		//theme_copy_str.Format("Copy of %s",theme_str);
	//((CDialogTheme*)m_pParent)->m_ListTheme.InsertItem(LVIF_TEXT|LVIF_STATE, theme_count,nid,0, LVIS_SELECTED,0, 0);
	//((CDialogTheme*)m_pParent)->m_ListTheme.SetItemText(theme_count,1,theme_copy_str);
	
/*

	LVITEM lvItem;
		int nItem;
	
		lvItem.mask = LVIF_IMAGE | LVIF_TEXT;
		lvItem.iItem = theme_idx;
		lvItem.iSubItem = 0;
		lvItem.pszText = theme_info;
		lvItem.iImage = 0;
		
		m_ListThemeEditor.DeleteItem(theme_idx);

		nItem = m_ListThemeEditor.InsertItem(&lvItem);
		

		
		m_ListThemeEditor.SetItemText(nItem,1,type_str);*/
	CDialog::OnOK();
}
