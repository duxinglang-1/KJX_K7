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
 *   w32_util.h
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
#ifndef __PC_UTILITY_H
#define __PC_UTILITY_H


#ifdef __cplusplus	
extern "C"
{
#endif

#define PI 3.1415926



/* Hex to Int */
unsigned int _hex2int(char c);

/* ANSII to hex value */
unsigned int atohex(char *in);

/*Convert "240x320" string to SIZE(240, 320)*/
void ParseSizeString(char* szIn, int lengthIn, SIZE* prectOut);

/*Convert "(l,t,w,h)" string to RECT(l,t,r,b)*/
void ParseLayoutString(char* szIn, int lengthIn, RECT* prectOut);

/*Resize a RECT, RECT(l,t,r,b) -> RECT(l*ratio,t*ratio,r*ratio,b*ratio)*/
void ResizeRECT(RECT*pRECT, float ratio);

/*Swap two variables*/
void Swap(unsigned int*, unsigned int*);

/*Get HBITMAP from a HDC*/
HBITMAP GetSrcBit(HDC hdc, int bitWidth, int bitHeight);

/*Get bitmap data buffer from a HBITMAP */
void GetBitmapDataBuffer(HBITMAP, LPVOID);

/*Rotate */
void RotateLayout(int* px, int* py, int nAngle, int w, int h);
void RotateSIZE(SIZE*, int nAngle, int w, int h);
void RotateRECT(RECT*, int nAngle, int w, int h);

/*Rotate a bitmap buffer */
void RotateBmpBuf(int nwidth,int nheight, unsigned char * bmp, unsigned char *destbmp,int nAngle);

/*Rotate a bitmap*/
HANDLE GetRotatedBitmapDIB( HANDLE hDIB, float radians, COLORREF clrBack );
HBITMAP GetRotatedBitmapPixel( HBITMAP hBitmap, float radians, COLORREF clrBack );
HBITMAP GetRotatedBitmapNT( HBITMAP hBitmap, float radians, COLORREF clrBack );

/*Save a bitmap into local disk*/	
void  SaveBitmap(char *szFilename,HBITMAP hBitmap);

/*Rotate a HDC*/
void RotateHDC(HDC hdc, int w, int h, int nAngle);

/*Safely delete a DC*/
#define MTKDeleteDC(hdc) \
	if(NULL != hdc)\
	{\
		DeleteDC(hdc);\
		hdc = NULL;\
	}\
\

#ifdef __cplusplus
}
#endif


#endif
