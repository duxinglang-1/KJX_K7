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
 * ColourPickerCB.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implemented the Color Combo Box dialog
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
// ColourPickerCB.cpp : implementation file
//
#include "stdafx.h"
#include "resource.h"
#include "ColourPickerCB.h"
#include "DialogColor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//extern CUIDlg		dlg;

Colour g_arrColours[] =
{
Colour("ALICEBLUE",RGB(240, 248, 255)),
Colour("ANTIQUEWHITE",RGB(250, 235, 215)),
Colour("AQUA",RGB( 0, 255, 255)),
Colour("AQUAMARINE",RGB(127, 255, 212)),
Colour("AZURE",RGB(240, 255, 255)),
Colour("BEIGE",RGB(245, 245, 220)), 
Colour("BISQUE",RGB(255, 228, 196)), 
Colour("BLACK",RGB( 0, 0, 0)), 
Colour("BLANCHEDALMOND",RGB(255, 235, 205)), 
//Colour("BLUE",RGB( 0, 0, 255)), 
Colour("BLUEVIOLET",RGB(138, 43, 226)), 
Colour("BROWN",RGB(165, 42, 42)), 
Colour("BURLYWOOD",RGB(222, 184, 135)), 
Colour("CADETBLUE",RGB( 95, 158, 160)), 
Colour("CHARTREUSE",RGB(127, 255, 0)), 
Colour("CHOCOLATE",RGB(210, 105, 30)), 
Colour("CORAL",RGB(255, 127, 80)), 
Colour("CORNFLOWERBLUE",RGB(100, 149, 237)), 
Colour("CORNSILK",RGB(255, 248, 220)), 
Colour("CRIMSON",RGB(220, 20, 60)), 
Colour("CYAN",RGB( 0, 255, 255)), 
Colour("DARKBLUE",RGB( 0, 0, 139)), 
Colour("DARKCYAN",RGB( 0, 139, 139)), 
Colour("DARKGOLDENROD",RGB(184, 134, 11)), 
Colour("DARKGRAY",RGB(169, 169, 169)), 
Colour("DARKGREEN",RGB( 0, 100, 0)), 
Colour("DARKGREY",RGB(169, 169, 169)), 
Colour("DARKKHAKI",RGB(189, 183, 107)), 
Colour("DARKMAGENTA",RGB(139, 0, 139)), 
Colour("DARKOLIVEGREEN",RGB( 85, 107, 47)), 
Colour("DARKORANGE",RGB(255, 140, 0)), 
Colour("DARKORCHID",RGB(153, 50, 204)), 
Colour("DARKRED",RGB(139, 0, 0)), 
Colour("DARKSALMON",RGB(233, 150, 122)), 
Colour("DARKSEAGREEN",RGB(143, 188, 143)),
Colour("DARKSLATEBLUE",RGB( 72, 61, 139)), 
Colour("DARKSLATEGRAY",RGB( 47, 79, 79)), 
Colour("DARKSLATEGREY",RGB( 47, 79, 79)), 
Colour("DARKTURQUOISE",RGB( 0, 206, 209)), 
Colour("DARKVIOLET",RGB(148, 0, 211)), 
Colour("DEEPPINK",RGB(255, 20, 147)), 
Colour("DEEPSKYBLUE",RGB( 0, 191, 255)), 
Colour("DIMGRAY",RGB(105, 105, 105)), 
Colour("DIMGREY",RGB(105, 105, 105)), 
Colour("DODGERBLUE",RGB( 30, 144, 255)), 
Colour("FIREBRICK",RGB(178, 34, 34)), 
Colour("FLORALWHITE",RGB(255, 250, 240)), 
Colour("FORESTGREEN",RGB( 34, 139, 34)), 
Colour("FUCHSIA",RGB(255, 0, 255)), 
Colour("GAINSBORO",RGB(220, 220, 220)), 
Colour("GHOSTWHITE",RGB(248, 248, 255)), 
Colour("GOLD",RGB(255, 215, 0)), 
Colour("GOLDENROD",RGB(218, 165, 32)), 
Colour("GRAY",RGB(128, 128, 128)), 
Colour("GREY",RGB(128, 128, 128)), 
Colour("GREEN",RGB( 0, 128, 0)), 
Colour("GREENYELLOW",RGB(173, 255, 47)), 
Colour("HONEYDEW",RGB(240, 255, 240)), 
Colour("HOTPINK",RGB(255, 105, 180)), 
Colour("INDIANRED",RGB(205, 92, 92)), 
Colour("INDIGO",RGB( 75, 0, 130)),
Colour("IVORY",RGB(255, 255, 240)), 
Colour("KHAKI",RGB(240, 230, 140)),
Colour("LAVENDER",RGB(230, 230, 250)),
Colour("LAVENDERBLUSH",RGB(255, 240, 245)),
Colour("LAWNGREEN",RGB(124, 252, 0)),
Colour("LEMONCHIFFON",RGB(255, 250, 205)),
Colour("LIGHTBLUE",RGB(173, 216, 230)),
Colour("LIGHTCORAL",RGB(240, 128, 128)),
Colour("LIGHTCYAN",RGB(224, 255, 255)),
Colour("LIGHTGOLDENRODYELLOW",RGB(250, 250, 210)),
Colour("LIGHTGRAY",RGB(211, 211, 211)),
Colour("LIGHTGREEN",RGB(144, 238, 144)),
Colour("LIGHTGREY",RGB(211, 211, 211)),	    	 
Colour("LIGHTPINK",RGB(255, 182, 193)),
Colour("LIGHTSALMON",RGB(255, 160, 122)),
Colour("LIGHTSEAGREEN",RGB( 32, 178, 170)),
Colour("LIGHTSKYBLUE",RGB(135, 206, 250)),
Colour("LIGHTSLATEGRAY",RGB(119, 136, 153)),
Colour("LIGHTSLATEGREY",RGB(119, 136, 153)),
Colour("LIGHTSTEELBLUE",RGB(176, 196, 222)),
Colour("LIGHTYELLOW",RGB(255, 255, 224)),
Colour("LIME",RGB( 0, 255, 0)),
Colour("LIMEGREEN",RGB( 50, 205, 50)),
Colour("LINEN",RGB(250, 240, 230)),
Colour("MAGENTA",RGB(255, 0, 255)),
Colour("MAROON",RGB(128, 0, 0)),
Colour("MEDIUMAQUAMARINE",RGB(102, 205, 170)),
Colour("MEDIUMBLUE",RGB( 0, 0, 205)),
Colour("MEDIUMORCHID",RGB(186, 85, 211)),
Colour("MEDIUMPURPLE",RGB(147, 112, 219)),
Colour("MEDIUMSEAGREEN",RGB( 60, 179, 113)),
Colour("MEDIUMSLATEBLUE",RGB(123, 104, 238)),
Colour("MEDIUMSPRINGGREEN",RGB( 0, 250, 154)),
Colour("MEDIUMTURQUOISE",RGB( 72, 209, 204)),
Colour("MEDIUMVIOLETRED",RGB(199, 21, 133)),
Colour("MIDNIGHTBLUE",RGB( 25, 25, 112)),
Colour("MINTCREAM",RGB(245, 255, 250)),
Colour("MISTYROSE",RGB(255, 228, 225)),
Colour("MOCCASIN",RGB(255, 228, 181)),
Colour("NAVAJOWHITE",RGB(255, 222, 173)),
Colour("NAVY",RGB( 0, 0, 128)),
Colour("OLDLACE",RGB(253, 245, 230)),
Colour("OLIVE",RGB(128, 128, 0)),
Colour("OLIVEDRAB",RGB(107, 142, 35)),
Colour("ORANGE",RGB(255, 165, 0)),
Colour("ORANGERED",RGB(255, 69, 0)),
Colour("ORCHID",RGB(218, 112, 214)),
Colour("PALEGOLDENROD",RGB(238, 232, 170)),
Colour("PALEGREEN",RGB(152, 251, 152)),
Colour("PALETURQUOISE",RGB(175, 238, 238)),
Colour("PALEVIOLETRED",RGB(219, 112, 147)),
Colour("PAPAYAWHIP",RGB(255, 239, 213)),
Colour("PEACHPUFF",RGB(255, 218, 185)),
Colour("PERU",RGB(205, 133, 63)),
Colour("PINK",RGB(255, 192, 203)),
Colour("PLUM",RGB(221, 160, 221)),
Colour("POWDERBLUE",RGB(176, 224, 230)),
Colour("PURPLE",RGB(128, 0, 128)),
Colour("RED",RGB(255, 0, 0)),
Colour("ROSYBROWN",RGB(188, 143, 143)),
Colour("ROYALBLUE",RGB( 65, 105, 225)),
Colour("SADDLEBROWN",RGB(139, 69, 19)),
Colour("SALMON",RGB(250, 128, 114)),
Colour("SANDYBROWN",RGB(244, 164, 96)),
Colour("SEAGREEN",RGB( 46, 139, 87)),
Colour("SEASHELL",RGB(255, 245, 238)),
Colour("SIENNA",RGB(160, 82, 45)),
Colour("SILVER",RGB(192, 192, 192)),
Colour("SKYBLUE",RGB(135, 206, 235)),
Colour("SLATEBLUE",RGB(106, 90, 205)),
Colour("SLATEGRAY",RGB(112, 128, 144)),
Colour("SLATEGREY",RGB(112, 128, 144)),
Colour("SNOW",RGB(255, 250, 250)),
Colour("SPRINGGREEN",RGB( 0, 255, 127)),
Colour("STEELBLUE",RGB( 70, 130, 180)),
Colour("TAN",RGB(210, 180, 140)),
Colour("TEAL",RGB( 0, 128, 128)),
Colour("THISTLE",RGB(216, 191, 216)),
Colour("TOMATO",RGB(255, 99, 71)),
Colour("TURQUOISE",RGB( 64, 224, 208)),
Colour("VIOLET",RGB(238, 130, 238)),
Colour("WHEAT",RGB(245, 222, 179)),
Colour("WHITE",RGB(255, 255, 255)),
Colour("WHITESMOKE",RGB(245, 245, 245)),
Colour("YELLOW",RGB(255, 255, 0)),
Colour("YELLOWGREEN",RGB(154, 205, 50)),
Colour("TRANSPARENT", RGB(0, 0, 255))
};

CColourPickerCB::CColourPickerCB(CWnd* pParent)
{
	m_pParent = pParent;
	ASSERT(NULL != pParent);
}

CColourPickerCB::~CColourPickerCB()
{
}

void DDX_ColourPickerCB( CDataExchange *pDX, int nIDC, COLORREF& rgbColor )
{
	HWND hWndCtrl = pDX->PrepareCtrl( nIDC );
	ASSERT( hWndCtrl );

	CColourPickerCB *pPicker = (CColourPickerCB*)CWnd::FromHandle( hWndCtrl );
	ASSERT( pPicker );

	// only support getting of colour.
	if( pDX->m_bSaveAndValidate )
	{
		rgbColor = pPicker->GetSelectedColourValue();
	}
}


BEGIN_MESSAGE_MAP(CColourPickerCB, CComboBox)
	//{{AFX_MSG_MAP(CColourPickerCB)
	ON_CONTROL_REFLECT(CBN_SELCHANGE, OnSelchange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColourPickerCB message handlers

void CColourPickerCB::PreSubclassWindow() 
{
	CComboBox::PreSubclassWindow();

	Initialise();
}

void CColourPickerCB::Initialise()
{
	// add colours.
	int iNumColours = sizeof( g_arrColours ) / sizeof( g_arrColours[0] );

	for( int iNum = 0; iNum < iNumColours; iNum++ )
	{
		Colour& colour = g_arrColours[iNum];
		AddColour( colour.m_strName, colour.m_crColour );
	}

	// add a custom item on the end.
	//AddColour( "Custom...", RGB( 255, 255, 255 ) );

	SetCurSel( 0 );
	m_noldindex = 0;
}

void CColourPickerCB::DrawItem( LPDRAWITEMSTRUCT pDIStruct )
{
	CString strColour;
	CDC dcContext;
	CRect rItemRect( pDIStruct->rcItem );
	CRect rBlockRect( rItemRect );
	CRect rTextRect( rBlockRect );
	CBrush brFrameBrush;
	int iFourthWidth = 0;
	int iItem = pDIStruct->itemID;
	int iAction = pDIStruct->itemAction;
	int iState = pDIStruct->itemState;
	COLORREF crColour = NULL;
	COLORREF crNormal = GetSysColor( COLOR_WINDOW );
	COLORREF crSelected = GetSysColor( COLOR_HIGHLIGHT );
	COLORREF crText = GetSysColor( COLOR_WINDOWTEXT );

	if( !dcContext.Attach( pDIStruct->hDC ) )
	{
		return;
	}

	iFourthWidth = ( rBlockRect.Width() / 4 );
	brFrameBrush.CreateStockObject( BLACK_BRUSH );

	if( iState & ODS_SELECTED )
	{
		dcContext.SetTextColor(	( 0x00FFFFFF & ~( crText ) ) );
		dcContext.SetBkColor( crSelected );
		dcContext.FillSolidRect( &rBlockRect, crSelected );
	}
	else
	{
		dcContext.SetTextColor( crText );
		dcContext.SetBkColor( crNormal );
		dcContext.FillSolidRect( &rBlockRect, crNormal );
	}

	if( iState & ODS_FOCUS )
	{
		dcContext.DrawFocusRect( &rItemRect );
	}

	// calculate text area.
	rTextRect.left += ( iFourthWidth + 2 );
	rTextRect.top += 2;

	// calculate colour block area.
	rBlockRect.DeflateRect( CSize( 2, 2 ) );
	rBlockRect.right = iFourthWidth;

	// draw colour text and block.
	if( iItem != -1 )
	{
		GetLBText( iItem, strColour );

		if( iState & ODS_DISABLED )
		{
			crColour = GetSysColor( COLOR_INACTIVECAPTIONTEXT );
			dcContext.SetTextColor( crColour );
		}
		else
		{
			crColour = GetItemData( iItem );
		}

		dcContext.SetBkMode( TRANSPARENT );
		dcContext.TextOut( rTextRect.left, rTextRect.top,	strColour );

		dcContext.FillSolidRect( &rBlockRect, crColour );
				
		dcContext.FrameRect( &rBlockRect, &brFrameBrush );
	}

	dcContext.Detach();
}

COLORREF CColourPickerCB::GetSelectedColourValue()
{
	return GetItemData( GetCurSel() );
}

void CColourPickerCB::AddColour( CString strName, COLORREF crColour )
{
	int iIndex = AddString( strName );

	if( iIndex >= 0 )
	{
		SetItemData( iIndex, crColour );
	}
}

void CColourPickerCB::OnSelchange() 
{
    CString strText;
    int selectedIndex = GetCurSel();

    if (selectedIndex == CB_ERR)
    {
		selectedIndex = 0;
        SetCurSel(0); 
    }
	else
	{
		m_noldindex = selectedIndex;
    }

    GetLBText(selectedIndex, strText);
    ((CDialogColor *)m_pParent)->m_Color = GetSelectedColourValue();
    ((CDialogColor *)m_pParent)->ChangeSlider();
    ((CDialogColor *)m_pParent)->GetDrawRGB();

}
