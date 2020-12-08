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
 * ColorPickerDlg.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file implemented the Color Picker dialog
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

// ColorPickerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "resource.h"
#include "ColorPickerDlg.h"
#include "Common.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define RADUIS	100

#define IN_CIRCLE	1
#define IN_BRIGHT	2
#define IN_NOTHING	0


/////////////////////////////////////////////////////////////////////////////
// CColorPickerDlg dialog


CColorPickerDlg::CColorPickerDlg(COLORREF c,CWnd* pParent /*=NULL*/)
	: CDialog(CColorPickerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CColorPickerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

	Vertex = CPoint(102,108);
	Top = CPoint(102,9);
	Left = CPoint(23,147);
	Right = CPoint(181,147);

	color.r = GetRValue(c);
	color.g = GetGValue(c);
	color.b = GetBValue(c);

	m_OldColor = color;
	hsvColor = color.toHSV();
	m_bInMouse = FALSE;
	m_bInitOver = FALSE;
	m_bInDrawAll = FALSE;
}

CColorPickerDlg::~CColorPickerDlg()
{
	if(m_RgbBitmap.GetSafeHandle())
	{
		m_RgbBitmap.DeleteObject();
	}
	if(m_HsbBitmap.GetSafeHandle())
	{
		m_HsbBitmap.DeleteObject();
	}
}


void CColorPickerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CColorPickerDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CColorPickerDlg, CDialog)
	//{{AFX_MSG_MAP(CColorPickerDlg)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_SYSCOLORCHANGE()
	ON_WM_PAINT()
	ON_EN_CHANGE(IDC_EDIT_BLUE, OnChangeEditBlue)
	ON_EN_CHANGE(IDC_EDIT_GREEN, OnChangeEditGreen)
	ON_EN_CHANGE(IDC_EDIT_HUE, OnChangeEditHue)
	ON_EN_CHANGE(IDC_EDIT_RED, OnChangeEditRed)
	ON_EN_CHANGE(IDC_EDIT_SAT, OnChangeEditSat)
	ON_EN_CHANGE(IDC_EDIT_VAL, OnChangeEditVal)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CColorPickerDlg message handlers

void CColorPickerDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if(hsbRect.PtInRect(point))
	{
		m_bInMouse = FALSE;
		if(InCircle(point))
		{
			m_nMouseIn = IN_CIRCLE;
		}
		else
		if(InBright(point))
		{
			m_nMouseIn = IN_BRIGHT;
		}
		else
		{
			m_nMouseIn = IN_NOTHING;
		}
		if(m_nMouseIn)
		{
			SetCapture();
			TrackPoint(point);
		}
	}
	else
	if(rgbRect.PtInRect(point))
	{
		m_nMouseIn = IN_NOTHING;
		if(rects[RED].PtInRect(point))
		{
			SetCapture();
			m_bInMouse = TRUE;
			nIndex = RED;
		}
		else
		if(rects[GREEN].PtInRect(point))
		{
			SetCapture();
			m_bInMouse = TRUE;
			nIndex = GREEN;
		}
		else
		if(rects[BLUE].PtInRect(point))
		{
			SetCapture();
			m_bInMouse = TRUE;
			nIndex = BLUE;
		}
	}
	
	CDialog::OnLButtonDown(nFlags, point);
}

void CColorPickerDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if(GetCapture() == this)
	{
		ReleaseCapture();
		m_bInMouse = FALSE;
	}
	CDialog::OnLButtonUp(nFlags, point);
}

void CColorPickerDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	if(GetCapture() == this && m_nMouseIn)
	{
		TrackPoint(point);
	}
	else
	if(GetCapture() == this && m_bInMouse)
	{
	double val;
	BOOL bChange = FALSE;
		if(nIndex == RED)
		{
			if(point.y > Vertex.y)
			{
				point.y = Vertex.y;
			}
			point.x = Vertex.x;
			val = Distance(point,Vertex);
			if(val > RedLen)
			{
				val = RedLen;
			}
			CClientDC dc(this);
			DrawLines(&dc);
			val = (val/RedLen)*255;
			color.r = (int)val;
			CPoint pt;
			pt = PointOnLine(Vertex,Top,(color.r*RedLen)/255,RedLen);
			rects[RED] = CRect(pt.x - RECT_WIDTH ,pt.y-RECT_WIDTH ,pt.x+RECT_WIDTH ,pt.y+RECT_WIDTH );
			CalcCuboid();
			DrawLines(&dc);
			bChange = TRUE;
		}
		else
		if(nIndex == GREEN)
		{
			if(point.x > Vertex.x)
			{
				point.x = Vertex.x;
			}
			point.y = rects[GREEN].top + RECT_WIDTH;
			val = Distance(point,Vertex);
			if(val > GreenLen)
			{
				val = GreenLen;
			}
			CClientDC dc(this);
			DrawLines(&dc);
			val = (val/GreenLen)*255;
			color.g = (int)val;
			CPoint pt;
			pt = PointOnLine(Vertex,Left,(color.g*GreenLen)/255,GreenLen);
			rects[GREEN] = CRect(pt.x - RECT_WIDTH ,pt.y-RECT_WIDTH ,pt.x+RECT_WIDTH ,pt.y+RECT_WIDTH );
			CalcCuboid();
			DrawLines(&dc);
			bChange = TRUE;
		}
		else
		if(nIndex == BLUE)
		{
			if(point.x < Vertex.x)
			{
				point.x = Vertex.x;
			}
			point.y = rects[BLUE].top + RECT_WIDTH;
			val = Distance(point,Vertex);
			if(val > BlueLen)
			{
				val = BlueLen;
			}
			CClientDC dc(this);
			DrawLines(&dc);
			val = (val/BlueLen)*255;
			color.b = (int)val;
			CPoint pt;
			pt = PointOnLine(Vertex,Right,(color.b*GreenLen)/255,BlueLen);
			rects[BLUE] = CRect(pt.x - RECT_WIDTH ,pt.y-RECT_WIDTH ,pt.x+RECT_WIDTH ,pt.y+RECT_WIDTH );
			CalcCuboid();
			DrawLines(&dc);
			bChange = TRUE;
		}
		if(bChange)
		{
			hsvColor = color.toHSV();
			SetEditVals();
			CClientDC dc(this);
			DrawMarkers(&dc);
			CalcRects();
			SetDIBPalette();

			InvalidateRect(&brightRect,FALSE);
			DrawHSB(&dc);
		}
	}
	CDialog::OnMouseMove(nFlags, point);
}

void CColorPickerDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	DrawFilledColor(&dc,OldColorRect,m_OldColor.color());
	DrawHSB(&dc);
	DrawRGB(&dc);
}

BOOL CColorPickerDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	GetDlgItem(IDC_STATIC_RGB_RECT)->GetWindowRect(&rgbRect);
	GetDlgItem(IDC_STATIC_HSB_RECT)->GetWindowRect(&hsbRect);
	ScreenToClient(&rgbRect);
	ScreenToClient(&hsbRect);

	GetDlgItem(IDC_STATIC_OLD)->GetWindowRect(&OldColorRect);
	GetDlgItem(IDC_STATIC_NEW)->GetWindowRect(&NewColorRect);
	ScreenToClient(&OldColorRect);
	ScreenToClient(&NewColorRect);

	
CWindowDC dc(NULL);
CSize bmSize;
//	Set Up HSB
	
	memDC.CreateCompatibleDC(&dc);

	LoadMappedBitmap(m_HsbBitmap,IDB_BITMAP_HSB,bmSize);
	hsbWidth = bmSize.cx;
	hsbHeight = bmSize.cy;

	hsbRect.InflateRect(-5,-5);
	hsbRect.top += 20;
	hsbRect.left += 10;

	m_Centre = CPoint(RADIUS,RADIUS);
	m_Centre += CPoint(hsbRect.left,hsbRect.top);

	brightRect = CRect(hsbRect.left+hsbWidth+20,hsbRect.top,hsbRect.left+hsbWidth+20+20,hsbRect.top + hsbHeight);
	CreateBrightDIB();
	CalcRects();
	SetDIBPalette();

//	Set Up RGB
	LoadMappedBitmap(m_RgbBitmap,IDB_BITMAP_RGB,bmSize);
	rgbWidth = bmSize.cx;
	rgbHeight = bmSize.cy;

	rgbRect.InflateRect(-5,-5);
	rgbRect.top+=10;
	rgbRect.left-=3;
CPoint pt = CPoint(rgbRect.left,rgbRect.top);

	Top += pt;
	Left += pt;
	Right += pt;
	Vertex += pt;
	// TODO: Add your specialized code here and/or call the base class

	RedLen = Distance(Vertex,Top);
	GreenLen = Distance(Vertex,Left);
	BlueLen = Distance(Vertex,Right);

	CalcSlopes();
	CalcCuboid();

	SetSpinVals();
	SetEditVals();
	CEdit* pp   =   (CEdit*)GetDlgItem(IDC_EDIT_RED);
	pp->SetLimitText(3);
	pp = (CEdit*)GetDlgItem(IDC_EDIT_GREEN);
	pp->SetLimitText(3);
	pp = (CEdit*)GetDlgItem(IDC_EDIT_BLUE);
	pp->SetLimitText(3);
	pp = (CEdit*)GetDlgItem(IDC_EDIT_HUE);
	pp->SetLimitText(3);
	pp = (CEdit*)GetDlgItem(IDC_EDIT_SAT);
	pp->SetLimitText(3);
	pp = (CEdit*)GetDlgItem(IDC_EDIT_VAL);
	pp->SetLimitText(3);
	m_bInitOver = TRUE;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CColorPickerDlg::DrawMarkers(CDC *pDC)
{
	if(m_CurrentRect.Width())
	{
	CPen *oldPen;
	CBrush *oldBrush;
	int oldMode;
	CRect cr = m_CurrentRect;

		oldPen = (CPen *)pDC->SelectStockObject(WHITE_PEN);
		oldBrush = (CBrush *)pDC->SelectStockObject(NULL_BRUSH);

		oldMode = pDC->SetROP2(R2_XORPEN);

		pDC->Rectangle(&cr);
		CPen pen;
		pen.CreatePen(PS_SOLID,2,RGB(255,255,255));
		pDC->SelectObject(&pen);
		pDC->Rectangle(&brightMark);

		pDC->SelectObject(oldPen);
		pDC->SelectObject(oldBrush);
		pDC->SetROP2(oldMode);
		pen.DeleteObject();

	}

}


BOOL CColorPickerDlg::InCircle(CPoint pt)
{
	return Distance(pt,m_Centre) <= RADIUS;
}

BOOL CColorPickerDlg::InBright(CPoint pt)
{
	return brightRect.PtInRect(pt);
}

void CColorPickerDlg::TrackPoint(CPoint pt)
{
	if(m_nMouseIn == IN_CIRCLE)
	{
	CClientDC dc(this);
		DrawMarkers(&dc);
		
		hsvColor.h = (int)RAD2DEG(AngleFromPoint(pt,m_Centre));
		if(hsvColor.h < 0)
		{
			hsvColor.h += 360;
		}
		hsvColor.s = (int)SCALETOMAX(Distance(pt,m_Centre));
		if(hsvColor.s > 255) hsvColor.s = 255;

		SetDIBPalette();
		CalcRects();


		InvalidateRect(&brightRect,FALSE);

		DrawMarkers(&dc);

		color = hsvColor.toRGB();
		SetEditVals();
		DrawLines(&dc);
		CalcCuboid();
		DrawRGB(&dc);

	}
	else
	if(m_nMouseIn == IN_BRIGHT)
	{
		double d;
		d = brightRect.bottom - pt.y;
		d *= 255;
		d /= brightRect.Height();
		if(d < 0 ) d = 0;
		if(d > 255) d = 255;
		CClientDC dc(this);
		DrawMarkers(&dc);
		hsvColor.v = (int)d;
		CalcRects();
		DrawMarkers(&dc);

		color = hsvColor.toRGB();
		SetEditVals();
		DrawLines(&dc);
		CalcCuboid();
		DrawRGB(&dc);

	}
}


void CColorPickerDlg::CreateBrightDIB()
{
CDIB& d = m_BrightDIB;
	d.Create(brightRect.Width(),brightRect.Height(),8);
	for(int i=0; i < d.Height(); i++)
	{
		memset(d.GetLinePtr(i),i,d.Width());
	}
}

void CColorPickerDlg::SetDIBPalette()
{
BYTE palette[768],*p;
HSVType h = hsvColor;
double d;
	d = 255.0/brightRect.Height();
	p = palette;
	for(int i=brightRect.Height()-1; i >= 0 ;i--,p+=3)
	{
		h.v = (int)((double)i * d);
		RGBType rgb = h.toRGB();
		p[0] = rgb.r;
		p[1] = rgb.g;
		p[2] = rgb.b;
	}
	m_BrightDIB.SetPalette(palette);
}

void CColorPickerDlg::CalcRects()
{
CPoint pt;
	pt = PtFromAngle(hsvColor.h,hsvColor.s,m_Centre);
	m_CurrentRect = CRect(pt.x - RECT_WIDTH,pt.y - RECT_WIDTH,pt.x+RECT_WIDTH,pt.y + RECT_WIDTH);	
	
int y;
	y = (int)(((double)hsvColor.v/255)*brightRect.Height()); 	
	y = brightRect.bottom - y;
	brightMark = CRect(brightRect.left - 2, y - 4, brightRect.right+2,y+4);
}


void CColorPickerDlg::DrawHSB(CDC *pDC)
{
	if(m_HsbBitmap.GetSafeHandle())
	{
	CBitmap *pOldBitmap ;
		pOldBitmap  = (CBitmap *)memDC.SelectObject(&m_HsbBitmap);
		pDC->BitBlt(hsbRect.left,hsbRect.top,hsbWidth,hsbHeight,&memDC,0,0,SRCCOPY);
		m_BrightDIB.BitBlt(pDC->m_hDC,brightRect.left,brightRect.top,brightRect.Width(),brightRect.Height(),0,0);
		DrawMarkers(pDC);
		memDC.SelectObject(pOldBitmap);
	}
}

void CColorPickerDlg::DrawRGB(CDC *pDC)
{
	if(m_RgbBitmap.GetSafeHandle())
	{
	CBitmap *pOldBitmap ;
		pOldBitmap  = (CBitmap *)memDC.SelectObject(&m_RgbBitmap);
		pDC->BitBlt(rgbRect.left,rgbRect.top,rgbWidth,rgbHeight,&memDC,0,0,SRCCOPY);
		DrawLines(pDC);
		memDC.SelectObject(pOldBitmap);
	}
}

void CColorPickerDlg::DrawLines(CDC *pDC)
{
CPoint pt[3];
	pt[0] = PointOnLine(Vertex,Top,(color.r*RedLen)/255,RedLen);
	pt[1] = PointOnLine(Vertex,Left,(color.g*GreenLen)/255,GreenLen);
	pt[2] = PointOnLine(Vertex,Right,(color.b*BlueLen)/255,BlueLen);
COLORREF col = RGB(255,255,255);
CRect cr;
	for(int i=0; i < 3; i++)
	{
		cr = CRect(pt[i].x - RECT_WIDTH ,pt[i].y-RECT_WIDTH ,pt[i].x+RECT_WIDTH ,pt[i].y+RECT_WIDTH );
		rects[i] = cr;
		DrawXorRect(pDC,cr);
	}
CPen *oldPen;
int oldMode;
	oldPen = (CPen *)pDC->SelectStockObject(WHITE_PEN);
	oldMode = pDC->SetROP2(R2_XORPEN);
/*
Draw the following lines :
	
	1 -2 
	2 -3
	3 - 4
	4- 5
	5 -2
	5 - 6
	6-7
	7-4
*/
	if(color.r>8&&color.g>8&&color.b>8)
	{
		pDC->MoveTo(m_Cuboid[1]);
		pDC->LineTo(m_Cuboid[2]);
		pDC->LineTo(m_Cuboid[3]);
		pDC->LineTo(m_Cuboid[4]);
		pDC->LineTo(m_Cuboid[5]);
		pDC->LineTo(m_Cuboid[2]);

		pDC->MoveTo(m_Cuboid[5]);
		pDC->LineTo(m_Cuboid[6]);
		pDC->LineTo(m_Cuboid[7]);
		pDC->LineTo(m_Cuboid[4]);
		
		pDC->MoveTo(m_Cuboid[1]);
		pDC->LineTo(m_Cuboid[6]);

		TRACE("m_Cuboid[1].x = %d,m_Cuboid[1].y = %d\n", m_Cuboid[1].x,m_Cuboid[1].y);
		TRACE("m_Cuboid[2].x = %d,m_Cuboid[2].y = %d\n", m_Cuboid[2].x,m_Cuboid[2].y);
		TRACE("m_Cuboid[3].x = %d,m_Cuboid[3].y = %d\n", m_Cuboid[3].x,m_Cuboid[3].y);
		TRACE("m_Cuboid[4].x = %d,m_Cuboid[4].y = %d\n", m_Cuboid[4].x,m_Cuboid[4].y);
		TRACE("m_Cuboid[5].x = %d,m_Cuboid[5].y = %d\n", m_Cuboid[5].x,m_Cuboid[5].y);
		
		TRACE("m_Cuboid[6].x = %d,m_Cuboid[6].y = %d\n", m_Cuboid[6].x,m_Cuboid[6].y);
		TRACE("m_Cuboid[7].x = %d,m_Cuboid[7].y = %d\n", m_Cuboid[7].x,m_Cuboid[7].y);

		
	
	}
	else if(color.r<=8&&color.g>8&&color.b>8)
	{
		pDC->MoveTo(m_Cuboid[3]);
		pDC->LineTo(m_Cuboid[4]);
		pDC->LineTo(m_Cuboid[7]);
	}
	
	else if(color.r>8&&color.g<=8&&color.b>8)
	{
		pDC->MoveTo(m_Cuboid[7]);
		pDC->LineTo(m_Cuboid[6]);
		pDC->LineTo(m_Cuboid[1]);
	}

	else if(color.r>8&&color.g>8&&color.b<=8)
	{
		pDC->MoveTo(m_Cuboid[1]);
		pDC->LineTo(m_Cuboid[2]);
		pDC->LineTo(m_Cuboid[3]);
	}

	pDC->SelectObject(oldPen);
	pDC->SetROP2(oldMode);

	DrawFilledColor(pDC,NewColorRect,color.color());
}


void CColorPickerDlg::DrawXorRect(CDC *pDC,CRect& cr)
{
CPen pen,*oldPen;
CBrush *oldBrush;
int oldMode;
	pen.CreatePen(PS_SOLID,1,RGB(255,255,255));
	oldPen = (CPen *)pDC->SelectObject(&pen);
	oldBrush = (CBrush *)pDC->SelectStockObject(NULL_BRUSH);
	oldMode =pDC->SetROP2(R2_XORPEN);
	pDC->Rectangle(&cr);
	pDC->SetROP2(oldMode);
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);
	pen.DeleteObject();

}

void CColorPickerDlg::CalcSlopes()
{
	lines[RED].slope = Slope(Top,Vertex);
	lines[GREEN].slope = Slope(Left,Vertex);
	lines[BLUE].slope = Slope(Right,Vertex);

int i;
	for(i=0; i < 3; i++)
	{
		lines[i].x = Vertex.x;
		lines[i].y = Vertex.y;
		lines[i].c = FindC(lines[i]);
	}
}


/*

  Cuboid points
   0 = vertex
   1 = Red Axis
   2 = Red Green Intersection
   3 = Green Axis
   4 = Blue Green Intersection
   5 = Blue Green Red Intersection
   6 = Red Blue Intersection
   7 = Blue Axis

  Draw the following lines :
	
	1 -2 
	2 -3
	3 - 4
	4- 5
	5 -2
	5 - 6
	6-7
	7-4
*/

void CColorPickerDlg::CalcCuboid()
{
double rLen,gLen,bLen;
	rLen = (double)(color.r*RedLen)/255;
	gLen = (double)(color.g*GreenLen)/255;
	bLen = (double)(color.b*BlueLen)/255;
LineDesc l[12];

	m_Cuboid[0] = Vertex;
	m_Cuboid[1] = PointOnLine(Vertex,Top,(int)rLen,RedLen);
	m_Cuboid[3] = PointOnLine(Vertex,Left,(int)gLen,GreenLen);
	m_Cuboid[7] = PointOnLine(Vertex,Right,(int)bLen,BlueLen);

	l[0] = lines[RED];
	l[1] = lines[GREEN];
	l[2] = lines[BLUE];

	l[3].slope = lines[GREEN].slope;
	l[3].x = m_Cuboid[1].x;
	l[3].y = m_Cuboid[1].y;
	l[3].c = FindC(l[3]);
	
	l[4].slope = lines[RED].slope;
	l[4].x = m_Cuboid[3].x;
	l[4].y = m_Cuboid[3].y;
	l[4].c = FindC(l[4]);

	l[5].slope = lines[BLUE].slope;
	l[5].x = m_Cuboid[3].x;
	l[5].y = m_Cuboid[3].y;
	l[5].c = FindC(l[5]);
	
	l[6].slope = lines[GREEN].slope;
	l[6].x = m_Cuboid[7].x;
	l[6].y = m_Cuboid[7].y;
	l[6].c = FindC(l[6]);



	l[10].slope = lines[BLUE].slope;
	l[10].x = m_Cuboid[1].x;
	l[10].y = m_Cuboid[1].y;
	l[10].c = FindC(l[10]);
	
	l[11].slope = lines[RED].slope;
	l[11].x = m_Cuboid[7].x;
	l[11].y = m_Cuboid[7].y;
	l[11].c = FindC(l[11]);

	m_Cuboid[2] = Intersection(l[3],l[4]);
	m_Cuboid[4] = Intersection(l[5],l[6]);
	m_Cuboid[6] = Intersection(l[10],l[11]);

	l[7].slope = lines[RED].slope;
	l[7].x = m_Cuboid[4].x;
	l[7].y = m_Cuboid[4].y;
	l[7].c = FindC(l[7]);
	
	l[8].slope = lines[BLUE].slope;
	l[8].x = m_Cuboid[2].x;
	l[8].y = m_Cuboid[2].y;
	l[8].c = FindC(l[8]);

	m_Cuboid[5] = Intersection(l[7],l[8]);
		
}


void CColorPickerDlg::SetSpinVals()
{
	((CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_RED))->SetRange(0,255);
	((CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_GREEN))->SetRange(0,255);
	((CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_BLUE))->SetRange(0,255);

	((CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_HUE))->SetRange(0,360);
	((CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_SAT))->SetRange(0,255);
	((CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_VAL))->SetRange(0,255);
}

void CColorPickerDlg::SetEditVals()
{
	((CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_RED))->SetPos(color.r);
	((CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_GREEN))->SetPos(color.g);
	((CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_BLUE))->SetPos(color.b);

	((CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_HUE))->SetPos(hsvColor.h);
	((CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_SAT))->SetPos(hsvColor.s);
	((CSpinButtonCtrl *)GetDlgItem(IDC_SPIN_VAL))->SetPos(hsvColor.v);

}

void CColorPickerDlg::OnChangeEditBlue() 
{
int b;
	b = GetDlgItemInt(IDC_EDIT_BLUE);
	if( b != color.b && m_bInitOver)
	{
		color.b = b;
		if(color.b < 0) color.b = 0;
		if(color.b > 255) color.b = 255;
		hsvColor = color.toHSV();
		DrawAll();
	}
}

void CColorPickerDlg::OnChangeEditGreen() 
{
int g;
	
	g = GetDlgItemInt(IDC_EDIT_GREEN);
	if(g != color.g && m_bInitOver)
	{
		color.g = g;
		if(color.g < 0) color.g = 0;
		if(color.g > 255) color.g = 255;
		hsvColor = color.toHSV();
		DrawAll();
	}
}


void CColorPickerDlg::OnChangeEditRed() 
{
int r;
	r = GetDlgItemInt(IDC_EDIT_RED);
	if(r != color.r && m_bInitOver)
	{
		color.r = r;
		if(color.r < 0) color.r = 0;
		if(color.r > 255) color.r = 255;
		hsvColor = color.toHSV();
		DrawAll();
	}
}

void CColorPickerDlg::OnChangeEditHue() 
{
int h;
	h = GetDlgItemInt(IDC_EDIT_HUE);
	if(h != hsvColor.h && m_bInitOver)
	{
		hsvColor.h = h;
		if(hsvColor.h < 0) hsvColor.h = 0;
		if(hsvColor.h > 359) hsvColor.h = 359;
		color = hsvColor.toRGB();
		DrawAll();
	}
}

void CColorPickerDlg::OnChangeEditSat() 
{
int s;
	s = GetDlgItemInt(IDC_EDIT_SAT);
	if(s != hsvColor.s && m_bInitOver)
	{
		hsvColor.s = s;
		if(hsvColor.s < 0) hsvColor.s = 0;
		if(hsvColor.s > 255) hsvColor.s = 255;
		color = hsvColor.toRGB();
		DrawAll();
	}
}

void CColorPickerDlg::OnChangeEditVal() 
{
int v;
	v = GetDlgItemInt(IDC_EDIT_VAL);
	if(v != hsvColor.v && m_bInitOver)
	{
		hsvColor.v = v;
		if(hsvColor.v < 0) hsvColor.v = 0;
		if(hsvColor.v > 255) hsvColor.v = 255;
		color = hsvColor.toRGB();
		DrawAll();
	}
}

void CColorPickerDlg::DrawAll()
{
	if(m_bInitOver && !m_bInDrawAll)
	{
	CClientDC dc(this);
		DrawMarkers(&dc);
		DrawLines(&dc);
		m_bInDrawAll = TRUE;
		CalcCuboid();
		CalcRects();
		SetDIBPalette();
		DrawRGB(&dc);
		DrawHSB(&dc);
		SetEditVals();
		m_bInDrawAll = FALSE;
	}
}


void CColorPickerDlg::DrawFilledColor(CDC *pDC,CRect cr,COLORREF c)
{
	pDC->FillSolidRect(&cr,c);
	pDC->Draw3dRect(&cr,RGB(0,0,0),RGB(0,0,0));
	cr.InflateRect(-1,-1);
	pDC->Draw3dRect(&cr,RGB(192,192,192),RGB(128,128,128));
}

void CColorPickerDlg::LoadMappedBitmap(CBitmap& bitmap,UINT nIdResource,CSize& size)
{
CBitmap *pOldBitmap;
	
	if(bitmap.GetSafeHandle()) bitmap.DeleteObject();
	
	if(bitmap.LoadBitmap(nIdResource))
	{

	int width,height;
	BITMAP bmInfo;
		::GetObject(bitmap.m_hObject,sizeof(bmInfo),&bmInfo);	
		width = bmInfo.bmWidth;
		height = bmInfo.bmHeight;

	COLORREF colorWindow = ::GetSysColor(COLOR_3DFACE);
	COLORREF sourceColor = RGB(192,192,192);

		pOldBitmap = (CBitmap *)memDC.SelectObject(&bitmap);
	
	int i,j;
		
		for(i=0; i < height; i++)
		{
			for(j=0; j < width; j++)
			{
				if(memDC.GetPixel(j,i) == sourceColor)
				{
					memDC.SetPixel(j,i,colorWindow);
				}
			}
		}

		memDC.SelectObject(&pOldBitmap);
		size = CSize(width,height);
	}

}

void CColorPickerDlg::OnSysColorChange()
{
CSize size;
	LoadMappedBitmap(m_HsbBitmap,IDB_BITMAP_HSB,size);
	LoadMappedBitmap(m_RgbBitmap,IDB_BITMAP_RGB,size);
}
