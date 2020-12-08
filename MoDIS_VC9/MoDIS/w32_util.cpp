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
*   w32_utility.cpp
*
* Project:
* --------
*   Maui
*
* Description:
* ------------
*   Utility for MoDIS
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "stdafx.h "
#include "w32_util.h"
#include <math.h>
#include <algorithm>
using namespace std;

unsigned int _hex2int(char c)
{
	if (c >= '0' && c <= '9')
		return (unsigned int)(c-'0');
	if (c >= 'a' && c <= 'f')
		return (unsigned int)(c-'a'+10);
	if (c >= 'A' && c <= 'F')
		return (unsigned int)(c-'A'+10);

	return 0;
}

/* ANSII to hex value */
unsigned int atohex(char *in)
{
	unsigned int value = 0;
	if (in[0]=='0' && (in[1]=='x' || in[1]=='X'))
	{
		in = in+2;
		while (*in != 0)
		{
			value = value*16 + _hex2int(*in);
			in++;
		}
	}
	return value;
}

void ParseSizeString(char* szIn, int lengthIn, SIZE* prectOut)
{
	char szTemp[8];
	char* pTemp=NULL;
	int nLayout[2];
	int i=0, j=0;


	memset(szTemp, 0, 8);
	pTemp = szTemp;

	for (i=0; i < lengthIn; i++)
	{
		char c=szIn[i];
		if(c == '(')
			continue;
		else if(c == ')')
		{
			*pTemp = '\0';
			nLayout[j++] = atoi(szTemp);
			break;
		}
		else if(c == ',')
		{
			*pTemp = '\0';
			nLayout[j++] = atoi(szTemp);
			memset(szTemp, 0, 8);
			pTemp = szTemp;
		}
		else
		{
			*pTemp++ = c;
		}
	}

	prectOut->cx = nLayout[0];
	prectOut->cy = nLayout[1];
}

void ParseLayoutString(char* szIn, int lengthIn, RECT* prectOut)
{
	char szTemp[8];
	char* pTemp=NULL;
	int nLayout[4];
	int i=0, j=0;


	memset(szTemp, 0, 8);
	pTemp = szTemp;

	for (i=0; i < lengthIn; i++)
	{
		char c=szIn[i];
		if(c == '(')
			continue;
		else if(c == ')')
		{
			*pTemp = '\0';
			nLayout[j++] = atoi(szTemp);
			break;
		}
		else if(c == ',')
		{
			*pTemp = '\0';
			nLayout[j++] = atoi(szTemp);
			memset(szTemp, 0, 8);
			pTemp = szTemp;
		}
		else
		{
			*pTemp++ = c;
		}
	}

	prectOut->left = nLayout[0];
	prectOut->top = nLayout[1];
	prectOut->right = nLayout[0] + nLayout[2];
	prectOut->bottom = nLayout[1] + nLayout[3];
}

void ResizeRECT(RECT*pRECT, float ratio)
{
	pRECT->left *= ratio;
	pRECT->right *= ratio;
	pRECT->top *= ratio;
	pRECT->bottom *= ratio;
}

void Swap(unsigned int* nVal1, unsigned int* nVal2)
{
	swap(*nVal1, *nVal2);
}

void RotateLayout(int* px, int* py, int nAngle, int w, int h)
{
	int nX = *px;
	int nY = *py;

	switch (nAngle)
	{
	case 90:
		
		*px = h - nY;
		*py = nX;
		break;
	case 180:
		break;
	case 270:
		break;
	}
}
void RotateSIZE(SIZE* sz, int nAngle, int w, int h)
{
	RotateLayout((int*)&sz->cx, (int*)sz->cy, nAngle, w, h);
}
void RotateRECT(RECT* rc, int nAngle, int w, int h)
{
	RECT rcTemp = *rc;
	switch (nAngle)
	{
	case 90:
		rc->left = h - rcTemp.bottom;
		rc->top = rcTemp.left;
		rc->right = h - rcTemp.top;
		rc->bottom = rcTemp.right;
		break;
	case 180:
		rc->left = w - rcTemp.right;
		rc->top = h - rcTemp.bottom;
		rc->right = w - rcTemp.left;
		rc->bottom = h - rcTemp.top;

		break;
	case 270:
		rc->left = rcTemp.top;
		rc->top = w - rcTemp.right;
		rc->right = rcTemp.bottom;
		rc->bottom = w - rcTemp.left;
		break;
	}
}

HBITMAP GetSrcBit(HDC hDC, int BitWidth, int BitHeight)
{
	HDC hBufDC;
	HBITMAP hBitmap;
	
	hBufDC = CreateCompatibleDC(hDC);
	hBitmap = CreateCompatibleBitmap(hDC, BitWidth, BitHeight);
	SelectObject(hBufDC, hBitmap);
	BitBlt(hBufDC, 0, 0, BitWidth, BitHeight, hDC,  0, 0, SRCCOPY);
	DeleteDC(hBufDC);
	return hBitmap;

}

void GetBitmapDataBuffer(HBITMAP hBitmap, LPVOID* ppBuffer)
{
	HDC hdc=GetDC(NULL);
	
	BITMAPINFO bmpInfo;
	ZeroMemory(&bmpInfo,sizeof(BITMAPINFO));
	bmpInfo.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
	GetDIBits(hdc,hBitmap,0,0,NULL,&bmpInfo,DIB_RGB_COLORS); 
	if(bmpInfo.bmiHeader.biSizeImage<=0)
		bmpInfo.bmiHeader.biSizeImage=bmpInfo.bmiHeader.biWidth*abs(bmpInfo.bmiHeader.biHeight)*(bmpInfo.bmiHeader.biBitCount+7)/8;
	if((*ppBuffer = malloc(bmpInfo.bmiHeader.biSizeImage))==NULL)
	{
	   *ppBuffer = NULL;
	   return;
	}			  
	bmpInfo.bmiHeader.biCompression=BI_RGB;
	GetDIBits(hdc,hBitmap,0,bmpInfo.bmiHeader.biHeight,*ppBuffer, &bmpInfo, DIB_RGB_COLORS);
	if(hdc)     
		ReleaseDC(NULL,hdc); 
}

void RotateBmpBuf(int nwidth,int nheight, unsigned char * bmp, unsigned char *destbmp,int nAngle)
{

	int nLineTailDest,nnewTail;
	int x,y;
	int nlooppixel,nNewlooppixel;
	
	nLineTailDest = 0;//	= (((24*nwidth) + 31) / 32 * 4)-3*nwidth;
	nnewTail  = 0;// = (((24lnheight) + 31) / 32 * 4)-3*nheight;
	if(270 == nAngle)//270
	{
			
		for (y = nheight-1 ; y >=0 ; y--)
		{
				
			for(x = 0;x < nwidth-1;x++)
			{
				 nlooppixel = y * (nwidth*4 + nLineTailDest) + x*4;
				 nNewlooppixel = (x)*(nheight*4 + nnewTail) + (nheight - y /*- 1*/)*4;		
				destbmp[nNewlooppixel] = bmp[nlooppixel];
				destbmp[nNewlooppixel++] = bmp[nlooppixel++];
				destbmp[nNewlooppixel++] = bmp[nlooppixel++];
				destbmp[nNewlooppixel++] = bmp[nlooppixel++];
			}

		}	
	}
	else if(90 == nAngle)//90
	{
		for(y = nheight-1;y >=0 ;y--)//for (x = nwidth-1 ; x >=0 ; x--)
		{		
			for (x = nwidth-1 ; x >=0 ; x--)//for(y = nheight-1;y >=0 ;y--)
			{
				 nlooppixel = y * (nwidth*4 + nLineTailDest) + x*4;
				 nNewlooppixel = (nwidth - x)*(nheight*4 + nnewTail) + y*4;//(nheight - y - 1)*4;		
				destbmp[nNewlooppixel] = bmp[nlooppixel];
				destbmp[nNewlooppixel++] = bmp[nlooppixel++];
				destbmp[nNewlooppixel++] = bmp[nlooppixel++];
				destbmp[nNewlooppixel++] = bmp[nlooppixel++];
			}
		}	
	}
	else if(180 == nAngle)//180
	{
		for (x = nwidth-1 ; x >=0 ; x--)
		{
			for(y = nheight-1;y >=0 ;y--)
			{
				 nlooppixel = y * (nwidth*4 + nLineTailDest) + x*4;
				nNewlooppixel = (nwidth - x + (nheight - y) * nwidth)*4;
				destbmp[nNewlooppixel] = bmp[nlooppixel];
				destbmp[nNewlooppixel++] = bmp[nlooppixel++];
				destbmp[nNewlooppixel++] = bmp[nlooppixel++];
				destbmp[nNewlooppixel++] = bmp[nlooppixel++];
			}
		}	
	}
}

// GetRotatedBitmap - Create a new bitmap with rotated image
// Returns  - Returns new bitmap with rotated image
// hDIB   - Device-independent bitmap to rotate
// radians  - Angle of rotation in radians
// clrBack  - Color of pixels in the resulting bitmap that do
//     not get covered by source pixels
HANDLE GetRotatedBitmapDIB( HANDLE hDIB, float radians, COLORREF clrBack )
{
	 // Get source bitmap info
	 BITMAPINFO &bmInfo = *(LPBITMAPINFO)hDIB ;
	 int bpp = bmInfo.bmiHeader.biBitCount;  // Bits per pixel
	 
	 int nColors = bmInfo.bmiHeader.biClrUsed ? bmInfo.bmiHeader.biClrUsed : 
	     1 << bpp;
	 int nWidth = bmInfo.bmiHeader.biWidth;
	 int nHeight = bmInfo.bmiHeader.biHeight;
	 int nRowBytes = ((((nWidth * bpp) + 31) & ~31) / 8);

	 // Make sure height is positive and biCompression is BI_RGB or BI_BITFIELDS
	 DWORD &compression = bmInfo.bmiHeader.biCompression;
	 if( nHeight < 0 || (compression!=BI_RGB && compression!=BI_BITFIELDS))
	  return NULL;

	 LPVOID lpDIBBits;
	 if( bmInfo.bmiHeader.biBitCount > 8 )
	  lpDIBBits = (LPVOID)((LPDWORD)(bmInfo.bmiColors +
	   bmInfo.bmiHeader.biClrUsed) + 
	   ((compression == BI_BITFIELDS) ? 3 : 0));
	 else
	  lpDIBBits = (LPVOID)(bmInfo.bmiColors + nColors);

	    
	 // Compute the cosine and sine only once
	 float cosine = (float)cos(radians);
	 float sine = (float)sin(radians);

	 // Compute dimensions of the resulting bitmap
	 // First get the coordinates of the 3 corners other than origin
	 int x1 = (int)(-nHeight * sine);
	 int y1 = (int)(nHeight * cosine);
	 int x2 = (int)(nWidth * cosine - nHeight * sine);
	 int y2 = (int)(nHeight * cosine + nWidth * sine);
	 int x3 = (int)(nWidth * cosine);
	 int y3 = (int)(nWidth * sine);

	 int minx = min(0,min(x1, min(x2,x3)));
	 int miny = min(0,min(y1, min(y2,y3)));
	 int maxx = max(x1, max(x2,x3));
	 int maxy = max(y1, max(y2,y3));

	 int w = maxx - minx;
	 int h = maxy - miny;

	 // Create a DIB to hold the result
	 int nResultRowBytes = ((((w * bpp) + 31) & ~31) / 8);
	 long len = nResultRowBytes * h;
	 int nHeaderSize = ((LPBYTE)lpDIBBits-(LPBYTE)hDIB) ;
	 HANDLE hDIBResult = GlobalAlloc(GMEM_FIXED,len+nHeaderSize);
	 // Initialize the header information
	 memcpy( (void*)hDIBResult, (void*)hDIB, nHeaderSize);
	 BITMAPINFO &bmInfoResult = *(LPBITMAPINFO)hDIBResult ;
	 bmInfoResult.bmiHeader.biWidth = w;
	 bmInfoResult.bmiHeader.biHeight = h;
	 bmInfoResult.bmiHeader.biSizeImage = len;

	 LPVOID lpDIBBitsResult = (LPVOID)((LPBYTE)hDIBResult + nHeaderSize);

	 // Get the back color value (index)
	 ZeroMemory( lpDIBBitsResult, len );
	 DWORD dwBackColor;
	 switch(bpp)
	 {
	 case 1: //Monochrome
	  if( clrBack == RGB(255,255,255) )
	   memset( lpDIBBitsResult, 0xff, len );
	  break;
	 case 4:
	 case 8: //Search the color table
	  int i;
	  for(i = 0; i < nColors; i++ )
	  {
	   if( bmInfo.bmiColors[i].rgbBlue ==  GetBValue(clrBack)
	    && bmInfo.bmiColors[i].rgbGreen ==  GetGValue(clrBack)
	    && bmInfo.bmiColors[i].rgbRed ==  GetRValue(clrBack) )
	   {
	    if(bpp==4) i = i | i<<4;
	    memset( lpDIBBitsResult, i, len );
	    break;
	   }
	  }
	  // If not match found the color remains black
	  break;
	 case 16:
	  // Windows95 supports 5 bits each for all colors or 5 bits for red & blue
	  // and 6 bits for green - Check the color mask for RGB555 or RGB565
	  if( *((DWORD*)bmInfo.bmiColors) == 0x7c00 )
	  {
	   // Bitmap is RGB555
	   dwBackColor = ((GetRValue(clrBack)>>3) << 10) + 
	     ((GetRValue(clrBack)>>3) << 5) +
	     (GetBValue(clrBack)>>3) ;
	  }
	  else
	  {
	   // Bitmap is RGB565
	   dwBackColor = ((GetRValue(clrBack)>>3) << 11) + 
	     ((GetRValue(clrBack)>>2) << 5) +
	     (GetBValue(clrBack)>>3) ;
	  }
	  break;
	 case 24:
	 case 32:
	  dwBackColor = (((DWORD)GetRValue(clrBack)) << 16) | 
	    (((DWORD)GetGValue(clrBack)) << 8) |
	    (((DWORD)GetBValue(clrBack)));
	  break;
	 }

	 // Now do the actual rotating - a pixel at a time
	 // Computing the destination point for each source point
	 // will leave a few pixels that do not get covered
	 // So we use a reverse transform - e.i. compute the source point
	 // for each destination point

	 for( int y = 0; y < h; y++ )
	 {
	  for( int x = 0; x < w; x++ )
	  {
	   int sourcex = (int)((x+minx)*cosine + (y+miny)*sine);
	   int sourcey = (int)((y+miny)*cosine - (x+minx)*sine);
	   if( sourcex >= 0 && sourcex < nWidth && sourcey >= 0 
	    && sourcey < nHeight )
	   {
	    // Set the destination pixel
	    switch(bpp)
	    {
	     BYTE mask;
	    case 1:  //Monochrome
	     mask = *((LPBYTE)lpDIBBits + nRowBytes*sourcey + 
	      sourcex/8) & (0x80 >> sourcex%8);
	     //Adjust mask for destination bitmap
	     mask = mask ? (0x80 >> x%8) : 0;
	     *((LPBYTE)lpDIBBitsResult + nResultRowBytes*(y) + 
	        (x/8)) &= ~(0x80 >> x%8);
	     *((LPBYTE)lpDIBBitsResult + nResultRowBytes*(y) + 
	        (x/8)) |= mask;
	     break;
	    case 4:
	     mask = *((LPBYTE)lpDIBBits + nRowBytes*sourcey + 
	      sourcex/2) & ((sourcex&1) ? 0x0f : 0xf0);
	     //Adjust mask for destination bitmap
	     if( (sourcex&1) != (x&1) )
	      mask = (mask&0xf0) ? (mask>>4) : (mask<<4);
	     *((LPBYTE)lpDIBBitsResult + nResultRowBytes*(y) + 
	       (x/2)) &= ~((x&1) ? 0x0f : 0xf0);
	     *((LPBYTE)lpDIBBitsResult + nResultRowBytes*(y) + 
	       (x/2)) |= mask;
	     break;
	    case 8:
	     BYTE pixel ;
	     pixel = *((LPBYTE)lpDIBBits + nRowBytes*sourcey + 
	       sourcex);
	     *((LPBYTE)lpDIBBitsResult + nResultRowBytes*(y) + 
	       (x)) = pixel;
	     break;
	    case 16:
	     DWORD dwPixel;
	     dwPixel = *((LPWORD)((LPBYTE)lpDIBBits + 
	       nRowBytes*sourcey + sourcex*2));
	     *((LPWORD)((LPBYTE)lpDIBBitsResult + 
	      nResultRowBytes*y + x*2)) = (WORD)dwPixel;
	     break;
	    case 24:
	     dwPixel = *((LPDWORD)((LPBYTE)lpDIBBits + 
	      nRowBytes*sourcey + sourcex*3)) & 0xffffff;
	     *((LPDWORD)((LPBYTE)lpDIBBitsResult + 
	      nResultRowBytes*y + x*3)) |= dwPixel;
	     break;
	    case 32:
	     dwPixel = *((LPDWORD)((LPBYTE)lpDIBBits + 
	      nRowBytes*sourcey + sourcex*4));
	     *((LPDWORD)((LPBYTE)lpDIBBitsResult + 
	      nResultRowBytes*y + x*4)) = dwPixel;
	    }
	   }
	   else 
	   {
	    // Draw the background color. The background color
	    // has already been drawn for 8 bits per pixel and less
	    switch(bpp)
	    {
	    case 16:
	     *((LPWORD)((LPBYTE)lpDIBBitsResult + 
	      nResultRowBytes*y + x*2)) = 
	      (WORD)dwBackColor;
	     break;
	    case 24:
	     *((LPDWORD)((LPBYTE)lpDIBBitsResult + 
	      nResultRowBytes*y + x*3)) |= dwBackColor;
	     break;
	    case 32:
	     *((LPDWORD)((LPBYTE)lpDIBBitsResult + 
	      nResultRowBytes*y + x*4)) = dwBackColor;
	     break;
	    }
	   }
	  }
	 }

 	return hDIBResult;
}

// GetRotatedBitmapNT	- Create a new bitmap with rotated image
// Returns		- Returns new bitmap with rotated image
// hBitmap		- Bitmap to rotate
// radians		- Angle of rotation in radians5.
// clrBack		- Color of pixels in the resulting bitmap that do
//			  not get covered by source pixels
HBITMAP GetRotatedBitmapNT( HBITMAP hBitmap, float radians, COLORREF clrBack )
{	
	// Create a memory DC compatible with the display10.
	/*
	CDC sourceDC, destDC;	
	sourceDC.CreateCompatibleDC( NULL );	
	destDC.CreateCompatibleDC( NULL ); 	*/
	HDC sourceDC, destDC, dstpDC;
	dstpDC = GetDC(NULL);
	sourceDC = CreateCompatibleDC(NULL);	
	destDC = CreateCompatibleDC(NULL);
	
	// Get logical coordinates15.	
	BITMAP bm;	
	::GetObject( hBitmap, sizeof( bm ), &bm ); 
	
	float cosine = (float)cos(radians);	
	float sine = (float)sin(radians);
	
	// Compute dimensions of the resulting bitmap	
	// First get the coordinates of the 3 corners other than origin	
	int x1 = (int)(bm.bmHeight * sine);	
	int y1 = (int)(bm.bmHeight * cosine);	
	int x2 = (int)(bm.bmWidth * cosine + bm.bmHeight * sine);	
	int y2 = (int)(bm.bmHeight * cosine - bm.bmWidth * sine);	
	int x3 = (int)(bm.bmWidth * cosine);	
	int y3 = (int)(-bm.bmWidth * sine);
	
	int minx = min(0,min(x1, min(x2,x3)));	
	int miny = min(0,min(y1, min(y2,y3)));	
	int maxx = max(0,max(x1, max(x2,x3)));	
	int maxy = max(0,max(y1, max(y2,y3))); 
	
	int w = maxx - minx;	
	int h = maxy - miny; 
	
	// Create a bitmap to hold the result	
	HBITMAP hbmResult = ::CreateCompatibleBitmap(dstpDC, w, h);

	HBITMAP hbmOldSource = (HBITMAP)::SelectObject( sourceDC, hBitmap );	
	HBITMAP hbmOldDest = (HBITMAP)::SelectObject( destDC, hbmResult ); 	

	// Draw the background color before we change mapping mode
	HBRUSH hbrBack = CreateSolidBrush( clrBack );	
	HBRUSH hbrOld = (HBRUSH)::SelectObject( destDC, hbrBack );	
	::PatBlt(destDC, 0,0,w,h,PATCOPY);
	::DeleteObject( ::SelectObject( destDC, hbrOld ) );

	// We will use world transform to rotate the bitmap	
	SetGraphicsMode(destDC, GM_ADVANCED);	
	XFORM xform;	
	xform.eM11 = cosine;	
	xform.eM12 = -sine;
	xform.eM21 = sine;	
	xform.eM22 = cosine;	
	xform.eDx = (float)-minx;	
	xform.eDy = (float)-miny;
	
	SetWorldTransform( destDC, &xform ); 
	
	// Now do the actual rotating - a pixel at a time	
	BitBlt(destDC, 0, 0, bm.bmWidth, bm.bmHeight, sourceDC,  0, 0, SRCCOPY);

	// Restore DCs	
	::SelectObject( sourceDC, hbmOldSource );	
	::SelectObject( destDC, hbmOldDest ); 

	::DeleteDC(sourceDC);
	::DeleteDC(destDC);
	::ReleaseDC(NULL, dstpDC);
	
	return hbmResult;
}

// GetRotatedBitmap	- Create a new bitmap with rotated image
// Returns		- Returns new bitmap with rotated image
// hBitmap		- Bitmap to rotate
// radians		- Angle of rotation in radians5.
// clrBack		- Color of pixels in the resulting bitmap that do
//			  not get covered by source pixels
// Note			- If the bitmap uses colors not in the system palette 
//			  then the result is unexpected. You can fix this by
//			  adding an argument for the logical palette.10.
HBITMAP GetRotatedBitmapPixel( HBITMAP hBitmap, float radians, COLORREF clrBack )
{	
	// Create a memory DC compatible with the display	
	HDC sourceDC, destDC, dstpDC;
	dstpDC = GetDC(NULL);
	sourceDC = CreateCompatibleDC( NULL );
	destDC = CreateCompatibleDC( NULL ); 	

	// Get logical coordinates	
	BITMAP bm;	
	::GetObject( hBitmap, sizeof( bm ), &bm );

	float cosine = (float)cos(radians);	
	float sine = (float)sin(radians); 	

	// Compute dimensions of the resulting bitmap
	// First get the coordinates of the 3 corners other than origin	
	int x1 = (int)(-bm.bmHeight * sine);	
	int y1 = (int)(bm.bmHeight * cosine);	
	int x2 = (int)(bm.bmWidth * cosine - bm.bmHeight * sine);	
	int y2 = (int)(bm.bmHeight * cosine + bm.bmWidth * sine);
	int x3 = (int)(bm.bmWidth * cosine);	
	int y3 = (int)(bm.bmWidth * sine); 	
	int minx = min(0,min(x1, min(x2,x3)));	
	int miny = min(0,min(y1, min(y2,y3)));
	int maxx = max(x1, max(x2,x3));	
	int maxy = max(y1, max(y2,y3)); 

	int w = maxx - minx;	
	int h = maxy - miny;	

	// Create a bitmap to hold the result	
	HBITMAP hbmResult = ::CreateCompatibleBitmap(dstpDC, w, h);

	HBITMAP hbmOldSource = (HBITMAP)::SelectObject( sourceDC, hBitmap );	
	HBITMAP hbmOldDest = (HBITMAP)::SelectObject( destDC, hbmResult ); 	

	// Draw the background color before we change mapping mode	
	HBRUSH hbrBack = CreateSolidBrush( clrBack );
	HBRUSH hbrOld = (HBRUSH)::SelectObject( destDC, hbrBack );	
	::PatBlt(destDC, 0, 0, w, h, PATCOPY );	
	::DeleteObject( ::SelectObject( destDC, hbrOld ) ); 	

	// Set mapping mode so that +ve y axis is upwords55.	
	::SetMapMode(sourceDC, MM_ISOTROPIC);	
	::SetWindowExtEx(sourceDC, 1,1, NULL);	
	::SetViewportExtEx(sourceDC, 1,-1, NULL);	
	::SetViewportOrgEx(sourceDC, 0, bm.bmHeight-1, NULL); 

	::SetMapMode(destDC, MM_ISOTROPIC);	
	::SetWindowExtEx(destDC, 1,1, NULL);	
	::SetViewportExtEx(destDC, 1,-1, NULL);	
	::SetWindowOrgEx(destDC, minx, maxy, NULL); 

	// Now do the actual rotating - a pixel at a time	
	// Computing the destination point for each source point	
	// will leave a few pixels that do not get covered	
	// So we use a reverse transform - e.i. compute the source point	
	// for each destination point70. 	
	for( int y = miny; y < maxy; y++ )	
	{		
		for( int x = minx; x < maxx; x++ )		
		{
			int sourcex = (int)(x*cosine + y*sine);			
			int sourcey = (int)(y*cosine - x*sine);			
			if( sourcex >= 0 && sourcex < bm.bmWidth && sourcey >= 0
				&& sourcey < bm.bmHeight )				
				::SetPixel(destDC, x,y,::GetPixel(sourceDC, sourcex,sourcey));
		}	
	} 	
	// Restore DCs	
	::SelectObject( sourceDC, hbmOldSource );
	::SelectObject( destDC, hbmOldDest ); 
	
	::DeleteDC(sourceDC);
	::DeleteDC(destDC);
	::ReleaseDC(NULL, dstpDC);
	return hbmResult;
}

void  SaveBitmap(char *szFilename,HBITMAP hBitmap)
{

	HDC        hdc=NULL;
	FILE*      fp=NULL;
	LPVOID     pBuf=NULL;
	BITMAPINFO bmpInfo;
	BITMAPFILEHEADER  bmpFileHeader; 

	do{ 
	    hdc=GetDC(NULL);
	    ZeroMemory(&bmpInfo,sizeof(BITMAPINFO));
	    bmpInfo.bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
	    GetDIBits(hdc,hBitmap,0,0,NULL,&bmpInfo,DIB_RGB_COLORS); 
	    if(bmpInfo.bmiHeader.biSizeImage<=0)
			bmpInfo.bmiHeader.biSizeImage=bmpInfo.bmiHeader.biWidth*abs(bmpInfo.bmiHeader.biHeight)*(bmpInfo.bmiHeader.biBitCount+7)/8;
	    if((pBuf = malloc(bmpInfo.bmiHeader.biSizeImage))==NULL)
	    {
	          ::MessageBox(NULL,"Unable to allocate Bitmap memory.", "",MB_OK|MB_ICONERROR);
	          break;
	    }            
	    bmpInfo.bmiHeader.biCompression=BI_RGB;
	    GetDIBits(hdc,hBitmap,0,bmpInfo.bmiHeader.biHeight,pBuf, &bmpInfo, DIB_RGB_COLORS);       
	    if((fp = fopen(szFilename,"wb"))==NULL)
	    {
			::MessageBox(NULL,"Unable to create Bitmap file.", "",MB_OK|MB_ICONERROR);
	          break;
	    } 
	    bmpFileHeader.bfReserved1=0;
	    bmpFileHeader.bfReserved2=0;
	    bmpFileHeader.bfSize=sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+bmpInfo.bmiHeader.biSizeImage;
	    bmpFileHeader.bfType='MB';
	    bmpFileHeader.bfOffBits=sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER); 
	    fwrite(&bmpFileHeader,sizeof(BITMAPFILEHEADER),1,fp);
	    fwrite(&bmpInfo.bmiHeader,sizeof(BITMAPINFOHEADER),1,fp);
	    fwrite(pBuf,bmpInfo.bmiHeader.biSizeImage,1,fp); 
	}while(false); 

    if(hdc)     ReleaseDC(NULL,hdc); 
    if(pBuf)    free(pBuf); 
    if(fp)      fclose(fp);

}

void RotateHDC(HDC hdc, int w, int h, int nAngle)
{	
	HBITMAP hSrcBitmap = NULL;
	HBITMAP hDstBitmap = NULL;

	//Get bitmap from HDC
	hSrcBitmap = GetSrcBit(hdc, w, h);

	//Create rotated bitmap and selected into HDC
	hDstBitmap = GetRotatedBitmapNT(hSrcBitmap, (2*PI*(360-nAngle))/360, RGB(15,15,0));
	SelectObject(hdc, hDstBitmap);
	SaveBitmap("F:/home/mtk80753/Images/Test.bmp", hDstBitmap);
	
	DeleteObject(hDstBitmap);
	DeleteObject(hSrcBitmap);
}
