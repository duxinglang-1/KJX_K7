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
 * DialogColor.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implemented combined Color Select dialog
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

// DialogColor.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include  "ColourPickerCB.h"
#include "DialogColor.h"
#include "TCColorDialog.h"
#include "ColorPickerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDialogColor dialog

COLORREF 	g_Color;
bool g_thecom_cancel = false; 
CDialogColor::CDialogColor(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogColor::IDD, pParent)
{
	main_dlg = pParent;
	m_Color = RGB(255,255,255);
	m_pCtlColour = new CColourPickerCB(this);
}


CDialogColor::CDialogColor(COLORREF color,
                           bool isTransparentColorAllowed,
                           CWnd* pParent /*=NULL*/)
    : CDialog(CDialogColor::IDD, pParent),
      m_IsTransparentColorAllowed(isTransparentColorAllowed)
{
	//{{AFX_DATA_INIT(CDialogColor)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	main_dlg = pParent;
	m_Color=color;
	g_Color=color;
	m_OldColor=m_Color;
	m_pCtlColour = new CColourPickerCB(this);
}

CDialogColor::~CDialogColor()
{
	if(NULL != m_pCtlColour)
		delete m_pCtlColour;
}

void CDialogColor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogColor)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_SLIDER_R, m_RSlider);
	DDX_Control(pDX, IDC_SLIDER_G, m_GSlider);
	DDX_Control(pDX, IDC_SLIDER_B, m_BSlider);
	DDX_Text(pDX, IDC_EDIT_COLOR, m_ColorStr);
	DDV_MaxChars(pDX, m_ColorStr, 6);
	DDX_Control(pDX, IDC_COLOUR, *m_pCtlColour);
	DDX_ColourPickerCB( pDX, IDC_COLOUR, m_Color );
}


BEGIN_MESSAGE_MAP(CDialogColor, CDialog)
	//{{AFX_MSG_MAP(CDialogColor)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_R, OnReleasedcaptureSliderR)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_G, OnReleasedcaptureSliderG)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER_B, OnReleasedcaptureSliderB)
	ON_EN_CHANGE(IDC_EDIT_COLOR, OnChangeEditColor)
	ON_BN_CLICKED(IDC_BUTTON_BOX, OnButtonBox)
	ON_BN_CLICKED(IDC_BUTTON_HSB, OnButtonHsb)
	ON_BN_CLICKED(IDCANCEL, OnCancel)
	ON_WM_SHOWWINDOW()
	ON_WM_TIMER()
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogColor message handlers
void CDialogColor::OnCancel()
{
	g_thecom_cancel = false;
	g_Color = m_OldColor;
	EndDialog(1);
}


 void CDialogColor::OnPaint() 
{
	
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

	}
	else
	{	
		DrawRGB();
		CDialog::OnPaint();
		
	}
}

BOOL CDialogColor::OnInitDialog() 
{
	CDialog::OnInitDialog();
//	WaitForSingleObject( g_hWMutex, INFINITE );
	m_uiRangeFrom = 0;
	m_uiRangeTo = 255;
	m_uiFre = 30;
	
	m_ColorR = RGB(GetRValue(m_Color),0,0);
	m_ColorG = RGB(0,GetGValue(m_Color),0);
	m_ColorB = RGB(0,0,GetBValue(m_Color));
	
		

	SetDlgItemInt(IDC_EDITR,m_uiRangeTo);
	m_RSlider.SetRange( m_uiRangeFrom, m_uiRangeTo, TRUE );
	m_RSlider.SetPos(GetRValue(m_Color));
	m_RSlider.SetTicFreq(m_uiFre);

	SetDlgItemInt(IDC_EDITG,m_uiRangeTo);
	m_GSlider.SetRange( m_uiRangeFrom, m_uiRangeTo, TRUE );
	m_GSlider.SetPos(GetGValue(m_Color));
	m_GSlider.SetTicFreq(m_uiFre);

	SetDlgItemInt(IDC_EDITB,m_uiRangeTo);
	m_BSlider.SetRange( m_uiRangeFrom, m_uiRangeTo, TRUE );
	m_BSlider.SetPos(GetBValue(m_Color));
	m_BSlider.SetTicFreq(m_uiFre);
	// TODO: Add extra initialization here

	CString hexcolor;
	hexcolor.Format("%s%s%s",DectoHex(m_RSlider.GetPos()),DectoHex(m_GSlider.GetPos()),DectoHex(m_BSlider.GetPos()));
	GetDlgItem(IDC_EDIT_COLOR)->SetWindowText(hexcolor);
	
	//UpdatePosition();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
	
}
CRect CDialogColor::GetColorDisplayRect(unsigned int idc)
{
	CRect Rect;
	CWnd * pWnd = GetDlgItem( idc );
	ASSERT(pWnd);
	pWnd->GetWindowRect( Rect );
	ScreenToClient( Rect );

	return Rect;
}

int CDialogColor::is_rgb565_transparent_color(unsigned int rgb888) //Glory provide api
{
	return ((rgb888 >> 16) < 8) && (((rgb888 >> 8) & 0xFF) < 4) && ((rgb888 & 0xFF) > 247);
}

void CDialogColor::OnOK() 
{
	// TODO: Add extra validation here
	CString hexcolor;
	GetDlgItem(IDC_EDIT_COLOR)->GetWindowText(hexcolor);
	char hexchar[7] = {0};
	
	sprintf(hexchar,hexcolor);//Cstring to char*

	for(int i=0;i<hexcolor.GetLength();i++)
	{
		if((hexchar[i]>=65&&hexchar[i]<=70)||(hexchar[i]>=97&&hexchar[i]<=102)||(hexchar[i]>=48&&hexchar[i]<=57))
		{
		}
		else
		{
			::MessageShow("Invalid hex code."); 
			GetDlgItem(IDC_EDIT_COLOR)->SetWindowText("0");
			UpdateData(false);
			return;
		}
	}
	
	unsigned int rgb888=(HextoDec(hexchar[0])*16 +HextoDec(hexchar[1]))*256*256+
	(HextoDec(hexchar[2])*16 +HextoDec(hexchar[3]))*256+
	(HextoDec(hexchar[4])*16 +HextoDec(hexchar[5]));
	
    if (is_rgb565_transparent_color(rgb888))
    {
        if (m_IsTransparentColorAllowed)
        {
            ::MessageShow("CAUTION: You have selected the transparent color. We do not guarantee the display result.");
        }
        else
        {
            ::MessageShow("You have selected the transparent color. Please re-select another color.");
            return;
        }
    }
	g_thecom_cancel = true;
	g_Color = m_Color;

	CDialog::OnOK();
}

void CDialogColor::OnReleasedcaptureSliderR(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	GetDrawRGB();
	*pResult = 0;
}
void CDialogColor::OnReleasedcaptureSliderG(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	GetDrawRGB();
	*pResult = 0;
}
void CDialogColor::OnReleasedcaptureSliderB(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	GetDrawRGB();
	*pResult = 0;
}
void CDialogColor::GetDrawRGB()
{
	
	DrawRGB();
	unsigned char R = m_RSlider.GetPos();
	unsigned char G = m_GSlider.GetPos();
	unsigned char B = m_BSlider.GetPos();
	CString hexcolor;
	hexcolor.Format("%s%s%s",DectoHex(R),DectoHex(G),DectoHex(B));
	GetDlgItem(IDC_EDIT_COLOR)->SetWindowText(hexcolor);
}
void CDialogColor::DrawRGB()
{
	CDC * ptmpDC =GetDC();
	unsigned char R = m_RSlider.GetPos();
	unsigned char G = m_GSlider.GetPos();
	unsigned char B = m_BSlider.GetPos();
	m_Color = RGB(R,G,B);
	m_ColorR = RGB(R,0,0);
	m_ColorG = RGB(0,G,0);
	m_ColorB = RGB(0,0,B);

	ptmpDC->FillSolidRect(GetColorDisplayRect(IDC_STATIC_RGB_COLOR),m_Color);   
	ptmpDC->FillSolidRect(GetColorDisplayRect(IDC_STATIC_R_COLOR),m_ColorR);
	ptmpDC->FillSolidRect(GetColorDisplayRect(IDC_STATIC_G_COLOR),m_ColorG);
	ptmpDC->FillSolidRect(GetColorDisplayRect(IDC_STATIC_B_COLOR),m_ColorB);
	
	ReleaseDC( ptmpDC );
	
	SetDlgItemInt(IDC_EDITR,R );
	SetDlgItemInt(IDC_EDITG,G );
	SetDlgItemInt(IDC_EDITB,B );
}
CString CDialogColor::DectoHex(unsigned char R)
{
	CString ret;

	if(R<16)
		ret.Format("0%X",R);
	else
		ret.Format("%X",R);
	return ret;
}
void CDialogColor::OnChangeEditColor() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CString hexcolor;
	GetDlgItem(IDC_EDIT_COLOR)->GetWindowText(hexcolor);
	char hexchar[7] = {0};

	sprintf(hexchar,hexcolor);//Cstring to char*
	for(int i=0;i<hexcolor.GetLength();i++)
	{
		if((hexchar[i]>=65&&hexchar[i]<=70)||(hexchar[i]>=97&&hexchar[i]<=102)||(hexchar[i]>=48&&hexchar[i]<=57))
		{
		}
		else
		{
			::MessageShow("Invalid hex code."); 
			GetDlgItem(IDC_EDIT_COLOR)->SetWindowText("0");
			return;
			break;
		}
	}
	m_RSlider.SetPos(HextoDec(hexchar[0])*16 +HextoDec(hexchar[1]));
	m_GSlider.SetPos(HextoDec(hexchar[2])*16 +HextoDec(hexchar[3]));
	m_BSlider.SetPos(HextoDec(hexchar[4])*16 +HextoDec(hexchar[5]));
	
	DrawRGB();
	
}

int CDialogColor::HextoDec(char c)
{
	switch(c){
	case '0':
			return 0;
	case '1':
			return 1;
	case '2':
			return 2;
	case '3':
			return 3;
	case '4':
			return 4;
	case '5':
			return 5;
	case '6':
			return 6;
	case '7':
			return 7;
	case '8':
			return 8;
	case '9':
			return 9;
	case 'A':
	case 'a':
			return 10;
	case 'B':
	case 'b':
			return 11;
	case 'C':
	case 'c':
			return 12;
	case 'D':
	case 'd':
			return 13;
	case 'E':
	case 'e':
			return 14;
	case 'F':
	case 'f':
			return 15;
	}
		return 0;
}

bool CDialogColor::SelectColorBox(COLORREF &getcolor)
{
	COLORREF crDefColor=RGB(255,0,0);
	CTCColorDialog ColorDlg(crDefColor,0,this);
	ColorDlg.m_cc.Flags |= CC_RGBINIT | CC_FULLOPEN;
	if (ColorDlg.DoModal()==IDOK)
	{
		getcolor = ColorDlg.GetColor();
		return true;
	}
	return false;
}

void CDialogColor::OnButtonBox() 
{
	SelectColorBox(m_Color);
	ChangeSlider();
	GetDrawRGB();
	// TODO: Add your control notification handler code here
	
}

void CDialogColor::ChangeSlider()
{
	m_RSlider.SetPos(GetRValue(m_Color));
	m_GSlider.SetPos(GetGValue(m_Color));
	m_BSlider.SetPos(GetBValue(m_Color));
}
void CDialogColor::OnButtonHsb() 
{
	// TODO: Add your control notification handler code here
	CColorPickerDlg dlg(m_Color,this);
	if(dlg.DoModal() == IDOK)
	{
		m_Color = dlg.GetColor();
		ChangeSlider();
	}
	GetDrawRGB();
}
COLORREF CDialogColor::GetColor() 
{ 
	return m_Color;
}

void CDialogColor::UpdatePosition()
{
	/*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
	RECT		window_info, dlg_window_info;

	
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
	/* shift the dialog to be align with the main windows */
	this->GetWindowRect(&dlg_window_info);
	main_dlg->GetWindowRect(&window_info);
	//For DraeRGB so move window and use timer, tricky
	MoveWindow(window_info.left, window_info.top, dlg_window_info.right - dlg_window_info.left + 0, dlg_window_info.bottom - dlg_window_info.top + 0, TRUE);

} /* end of UpdatePosition */

void CDialogColor::OnTimer(UINT nIDEvent) 
{

	//UpdatePosition();
	//KillTimer(101);//101 mean SetTimer(101,
	
}

void CDialogColor::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	//UpdatePosition();
	//SetTimer(101, 100,  NULL);
} /* end of OnShowWindow */


BOOL CDialogColor::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	
	if( pMsg->message==WM_KEYDOWN||pMsg->message==WM_KEYUP)
	{
		if(pMsg->wParam == VK_UP || pMsg->wParam == VK_DOWN || pMsg->wParam == VK_LEFT || pMsg->wParam == VK_RIGHT||pMsg->wParam == VK_HOME||
			pMsg->wParam == VK_END || pMsg->wParam == VK_PRIOR || pMsg->wParam == VK_NEXT)
		{
		   if(GetFocus() == GetDlgItem(IDC_SLIDER_R) || GetFocus() == GetDlgItem(IDC_SLIDER_G) || GetFocus() == GetDlgItem(IDC_SLIDER_B) )
		   {
			   //GetDrawRGB();
			   return true;
		   }
		}
	}

	return CDialog::PreTranslateMessage(pMsg);
}
