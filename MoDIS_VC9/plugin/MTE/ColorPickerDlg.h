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
 * ColorPickerDlg.h
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

// ColorPickerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CColorPickerDlg dialog
//#include "MODIS_UI.h"
#include "Dib.h"
#include "Common.h"

class CColorPickerDlg : public CDialog
{
// Construction
public:
	CColorPickerDlg(COLORREF c,CWnd* pParent = NULL);   // standard constructor
	~CColorPickerDlg();
	COLORREF GetColor() { return color.color();};

// Dialog Data
	//{{AFX_DATA(CColorPickerDlg)
	
	enum { IDD = IDD_DIALOG_COLORS };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorPickerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CColorPickerDlg)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSysColorChange();
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEditBlue();
	afx_msg void OnChangeEditGreen();
	afx_msg void OnChangeEditHue();
	afx_msg void OnChangeEditRed();
	afx_msg void OnChangeEditSat();
	afx_msg void OnChangeEditVal();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	void DrawFilledColor(CDC *pDC,CRect cr,COLORREF c);
	void DrawLines(CDC *pDC);
	void DrawXorRect(CDC *pDC,CRect& cr);
	void CalcSlopes();
	void CalcCuboid();

	void CreateBrightDIB();
	void SetDIBPalette();
	void DrawMarkers(CDC *pDC);
	void TrackPoint(CPoint pt);
	void CalcRects();
		
	BOOL InCircle(CPoint pt);
	BOOL InBright(CPoint pt);


	void SetSpinVals();
	void SetEditVals();
	void DrawAll();

	void DrawRGB(CDC *pDC);
	void DrawHSB(CDC *pDC);

	void LoadMappedBitmap(CBitmap& bitmap,UINT nIdResource,CSize& size);

	CBitmap m_RgbBitmap,m_HsbBitmap;

	CDC memDC;
	CPoint m_Centre;
	CDIB m_BrightDIB;
	int rgbWidth,rgbHeight;
	int hsbWidth,hsbHeight;

	int m_nMouseIn;
	CRect m_CurrentRect,brightMark	;
	CRect brightRect;

	HSVType hsvColor;	

	RGBType color, m_OldColor;
	CPoint Vertex,Top,Left,Right;
	CRect  rects[3];
	CPoint m_Cuboid[8];
	BOOL m_bInMouse;
	int nIndex;
	int RedLen,GreenLen,BlueLen;
	LineDesc lines[3];


	CRect rgbRect;
	CRect hsbRect;
	CRect OldColorRect,NewColorRect;

	BOOL m_bInitOver,m_bInDrawAll;
};
