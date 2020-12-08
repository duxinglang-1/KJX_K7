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
 * DataTipListCtrl.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implemented the Data Tip List Control
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

// DataTipListCtrl.cpp : implementation file
//

#include "stdafx.h"

#include "DataTipListCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDataTipListCtrl

CDataTipListCtrl::CDataTipListCtrl()
{
	m_pchTip = NULL;
	m_pwchTip = NULL;
	m_bToolTipCtrlCustomizeDone = FALSE;
}

CDataTipListCtrl::~CDataTipListCtrl()
{
	if(m_pchTip != NULL)
		delete m_pchTip;

	if(m_pwchTip != NULL)
		delete m_pwchTip;
}


BEGIN_MESSAGE_MAP(CDataTipListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CDataTipListCtrl)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
	ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTW, 0, 0xFFFF, OnToolTipText)
	ON_NOTIFY_EX_RANGE(TTN_NEEDTEXTA, 0, 0xFFFF, OnToolTipText)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDataTipListCtrl message handlers

// InsertColumn() override to ease of inserting tooltip column
int CDataTipListCtrl::InsertColumn(int nCol, LPCTSTR lpszColumnHeading,
	int nFormat /*= LVCFMT_LEFT*/, int nWidth /*= -1*/, int nSubItem /*= -1*/)
{
	int res = CListCtrl::InsertColumn(nCol, lpszColumnHeading, nFormat, nWidth, nSubItem);
/*
	if(res!=-1 && (GetStyle()&LVS_TYPEMASK)==LVS_REPORT)
		if(!m_Header.AddToolTip(nCol, lpszColumnHeading, nFormat))
			return -1;
*/
	return res;
}


void CDataTipListCtrl::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	SetExtendedStyle(LVS_EX_FULLROWSELECT); // Enables full row selection
	EnableToolTips(); // Enables list contrl ToolTip control
	m_Header.SubclassDlgItem(0, this); // Replaces new header control with default list contrl header control.
	
	CListCtrl::PreSubclassWindow();
}

// Detects column resizing.
BOOL CDataTipListCtrl::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	// TODO: Add your specialized code here and/or call the base class
	LPNMHEADER pNMHD = (LPNMHEADER)lParam;

	switch(pNMHD->hdr.code)
	{
		case HDN_ITEMCHANGEDA:
		case HDN_ITEMCHANGEDW:
			BOOL bRes;
			bRes = CListCtrl::OnNotify(wParam, lParam, pResult);
			m_Header.RecalcToolRect();
			return bRes;
	}
	
	return CListCtrl::OnNotify(wParam, lParam, pResult);
}

// Detects mouse hovering and finds which row is hovering on
int CDataTipListCtrl::OnToolHitTest(CPoint point, TOOLINFO * pTI) const
{
	CRect rect;
	GetClientRect(&rect);
	if(rect.PtInRect(point))
	{
		if(GetItemCount())
		{
			int nTopIndex = GetTopIndex();
			int nBottomIndex = nTopIndex + GetCountPerPage();
			if(nBottomIndex > GetItemCount()) nBottomIndex = GetItemCount();
			for(int nIndex = nTopIndex; nIndex <= nBottomIndex; nIndex++)
			{
				GetItemRect(nIndex, rect, LVIR_BOUNDS);
				if(rect.PtInRect(point))
				{
					pTI->hwnd = m_hWnd;
					pTI->uId = (UINT)(nIndex+1);
					pTI->lpszText = LPSTR_TEXTCALLBACK;
					pTI->rect = rect;
					return pTI->uId;
				}
			}
		}
	}

	return -1;
}

/* Get item text in Unicode */
int GetItemTextW(HWND m_hWnd, int nItem, int nSubItem, LPTSTR lpszText, int nLen)
{
	LVITEM lvi;
	memset(&lvi, 0, sizeof(LVITEM));
	lvi.iSubItem = nSubItem;
	lvi.cchTextMax = nLen;
	lvi.pszText = lpszText;
	return (int)::SendMessage(m_hWnd, LVM_GETITEMTEXTW, (WPARAM)nItem,
		(LPARAM)&lvi);
}

/* Concatenate an ASCII string, mbuf, to a UNICODE string, wbuf. */
static void strcat_wm(wchar_t *wbuf, char* mbuf, int *len)  
{
    _mbstowcsz(wbuf + *len, mbuf, strlen(mbuf) + 1);
    *len += strlen(mbuf);
}

BOOL CDataTipListCtrl::OnToolTipText(UINT id, NMHDR* pNMHDR, LRESULT* pResult)
{
	// I want to implement this in PreSubclassWindow(), but it crashes.
	if(!m_bToolTipCtrlCustomizeDone)
	{
		AFX_MODULE_THREAD_STATE* pThreadState = AfxGetModuleThreadState();
		CToolTipCtrl *pToolTip = pThreadState->m_pToolTip;
		if (IsWindow(pToolTip->GetSafeHwnd()))  
		{
		pToolTip->SetMaxTipWidth(500);
		m_bToolTipCtrlCustomizeDone = TRUE;
         	}
		//	_AFX_THREAD_STATE* pThreadState = AfxGetThreadState();
		//		CToolTipCtrl *pToolTip = pThreadState->m_pToolTip;
		// Set max tip width in pixel.
		// you can change delay time, tip text or background color also. enjoy yourself!
		//		pToolTip->SetMaxTipWidth(500);
//		m_bToolTipCtrlCustomizeDone = TRUE;
	}

	// need to handle both ANSI and UNICODE versions of the message
	TOOLTIPTEXTA* pTTTA = (TOOLTIPTEXTA*)pNMHDR;
	TOOLTIPTEXTW* pTTTW = (TOOLTIPTEXTW*)pNMHDR;
	UINT nID = pNMHDR->idFrom;

	if(nID == 0)	  	// Notification in NT from automatically
		return FALSE;   	// created tooltip

	int nItem = nID - 1;
	CString strTip;
	TCHAR buf[MAX_TIP_LENGTH+1];
	HDITEM hdCol;
	hdCol.mask = HDI_TEXT;
	hdCol.pszText = buf;
	hdCol.cchTextMax = MAX_TIP_LENGTH; 
	int nNumCol = m_Header.GetItemCount();

    int tip_len = 0; 
    wchar_t wbuf[(MAX_TIP_LENGTH + 1) * 2];

    /* make the "UNICODE" tip string */
	for (int col=0; col<nNumCol; col++)
	{
		m_Header.GetItem(col, &hdCol);
        
        /* column header name for each line */
        strcat_wm(wbuf, hdCol.pszText, &tip_len);
        strcat_wm(wbuf, ": ", &tip_len);

        /* 
         * tip for each column 
         * 
         * Column 5 description is in Unicode.
         *
         * TODO: Column 2 group name should be in Unicode.
         */
	
        if (col == 2)
        {
            char name[1024];

            GetItemTextW(this->m_hWnd, nItem, col, name, 1024);
            memcpy(wbuf + tip_len, name, lstrlenW((wchar_t*)name) * 2);
            tip_len += lstrlenW((wchar_t*)name);
        }
		else if (col == 5)
        {
            char name[1024];

            GetItemTextW(this->m_hWnd, nItem, col, name, 1024);
            memcpy(wbuf + tip_len, name, lstrlenW((wchar_t*)name) * 2);
            tip_len += lstrlenW((wchar_t*)name);
        }
		
        else
        {
            strcat_wm(wbuf, (char*)(LPCSTR)GetItemText(nItem, col), &tip_len);
        }
            
        /* do not LF at the last line */
		if(col < nNumCol - 1) 
        {
            strcat_wm(wbuf, "\n", &tip_len);
        }
	}    

	if(pNMHDR->code == TTN_NEEDTEXTA)
	{
		if(m_pchTip != NULL)
			delete m_pchTip;

		m_pchTip = new TCHAR[tip_len + 1];
        _wcstombsz(m_pchTip, wbuf, tip_len);
		m_pwchTip[tip_len] = 0;

		pTTTA->lpszText = (LPTSTR)m_pchTip;
	}
	else
	{
		if(m_pwchTip != NULL)
			delete m_pwchTip;

		m_pwchTip = new WCHAR[tip_len + 1];
        memcpy(m_pwchTip, wbuf, tip_len * sizeof(WCHAR));
        m_pwchTip[tip_len] = 0;

		pTTTW->lpszText = (WCHAR*)m_pwchTip;
	}

	*pResult = 0;

	return TRUE;    // message was handled
}

