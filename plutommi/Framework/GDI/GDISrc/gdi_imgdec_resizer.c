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

/*******************************************************************************
 * Filename:
 * ---------
 *  gdi_imgdec_resizer.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  IMGDEC resizer
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gdi_internal.h"
#include "gdi_const.h"
#include "gdi_include.h"

#include "med_utility.h"

#include "gdi_imgdec_resizer.h"

#include "kal_general_types.h"
#include "kal_release.h"
#include "lcd_sw_rnd.h"
#include "med_smalloc.h"
#include "MMIDataType.h"

#include "gdi_datatype.h"
#include "gd_include.h"
#include "gdi_primitive.h"
#include "gdi_imgdec_internal.h"

#include "gdi_lcd_config.h"
#include "lcd_sw_inc.h"

#define SWAP(t,a,b) do {t tmp = a; a = b; b = tmp;} while(0)

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_resizer_put_null
 * DESCRIPTION
 *  dummy put pixel function
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_imgdec_resizer_put_null(gdi_imgdec_resizer_struct *resizer, gdi_color c, BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	// keep empty
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_resizer_put_8
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_imgdec_resizer_put_8(gdi_imgdec_resizer_struct *resizer, gdi_color c, BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(want_draw)
		*((U8*)resizer->dest) = (U8)c;

	resizer->dest+=1;
	// generate next_position
	if(resizer->next_want_sx >= resizer->want_sx_table_end)
	{
		resizer->next_want_sx = resizer->want_sx_table;

		if(resizer->dir_x>0)
			resizer->dest = ((gdi_layer_struct*)(resizer->out_layer))->buf_ptr + (resizer->want_dx1+ resizer->next_want_dy* ((gdi_layer_struct*)(resizer->out_layer))->width )*1;
		else
			resizer->dest = ((gdi_layer_struct*)(resizer->out_layer))->buf_ptr + (resizer->want_dx2+ resizer->next_want_dy* ((gdi_layer_struct*)(resizer->out_layer))->width )*1;
		//resizer->want_sy = (((resizer->next_want_dy  - resizer->offset_dy) * resizer->y_scale_factor) >> 16);
		resizer->want_sy = ((((resizer->next_want_dy  - resizer->offset_dy) * resizer->src_height_range << 1) +  resizer->dest_height_range) / (resizer->dest_height_range << 1));

		if(resizer->next_want_dy < resizer->want_dy1 || resizer->next_want_dy > resizer->want_dy2)
		{
			resizer->put_func = gdi_imgdec_resizer_put_null;
			
			return;
		}
		resizer->next_want_dy += resizer->dir_y;
	}
	resizer->want_sx = *resizer->next_want_sx++;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_resizer_put_16
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_imgdec_resizer_put_16(gdi_imgdec_resizer_struct *resizer, gdi_color c, BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(want_draw)
		*((U16*)resizer->dest) = (U16)c;

	resizer->dest+=2;
	// generate next_position
	if(resizer->next_want_sx >= resizer->want_sx_table_end)
	{
		resizer->next_want_sx = resizer->want_sx_table;

		if(resizer->dir_x>0)
			resizer->dest = ((gdi_layer_struct*)(resizer->out_layer))->buf_ptr + (resizer->want_dx1+ resizer->next_want_dy* ((gdi_layer_struct*)(resizer->out_layer))->width )*2;
		else
			resizer->dest = ((gdi_layer_struct*)(resizer->out_layer))->buf_ptr + (resizer->want_dx2+ resizer->next_want_dy* ((gdi_layer_struct*)(resizer->out_layer))->width )*2;
		//resizer->want_sy = (((resizer->next_want_dy  - resizer->offset_dy) * resizer->y_scale_factor) >> 16);
		resizer->want_sy = ((((resizer->next_want_dy  - resizer->offset_dy) * resizer->src_height_range << 1) +  resizer->dest_height_range) / (resizer->dest_height_range << 1));

		if(resizer->next_want_dy < resizer->want_dy1 || resizer->next_want_dy > resizer->want_dy2)
		{
			resizer->put_func = gdi_imgdec_resizer_put_null;
			
			return;
		}
		resizer->next_want_dy += resizer->dir_y;
	}
	resizer->want_sx = *resizer->next_want_sx++;
}

    
/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_resizer_put_24
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_imgdec_resizer_put_24(gdi_imgdec_resizer_struct *resizer, gdi_color c, BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(want_draw)
	{
		U32 *ptr = (U32*)(resizer->dest);
		switch(((U32)ptr)&0x3)
		{
		case 0:
			*ptr = (*ptr&0xff000000)|(c&0x00ffffff);
			break;
		case 1:
			ptr= (U32*)(((U32)ptr)&(~0x3));
			*ptr = (*ptr&0x000000ff)|(c<<8);
			break;
		case 2:
			ptr= (U32*)(((U32)ptr)&(~0x3));
			*ptr = (*ptr&0x0000ffff)|(c<<16); ptr++;
			*ptr = (*ptr&0xffffff00)|((c&0x00ff0000)>>16);
			break;
		default:
			ptr= (U32*)(((U32)ptr)&(~0x3));
			*ptr = (*ptr&0x00ffffff)|(c<<24); ptr++;
			*ptr = (*ptr&0xffff0000)|((c&0x00ffff00)>>8);
			break;
		}
	}

	resizer->dest+=3;
	// generate next_position
	if(resizer->next_want_sx >= resizer->want_sx_table_end)
	{
		resizer->next_want_sx = resizer->want_sx_table;

		if(resizer->dir_x>0)
			resizer->dest = ((gdi_layer_struct*)(resizer->out_layer))->buf_ptr + (resizer->want_dx1+ resizer->next_want_dy* ((gdi_layer_struct*)(resizer->out_layer))->width )*3;
		else
			resizer->dest = ((gdi_layer_struct*)(resizer->out_layer))->buf_ptr + (resizer->want_dx2+ resizer->next_want_dy* ((gdi_layer_struct*)(resizer->out_layer))->width )*3;
		//resizer->want_sy = (((resizer->next_want_dy  - resizer->offset_dy) * resizer->y_scale_factor) >> 16);
		resizer->want_sy = ((((resizer->next_want_dy  - resizer->offset_dy) * resizer->src_height_range << 1) +  resizer->dest_height_range) / (resizer->dest_height_range << 1));

		if(resizer->next_want_dy < resizer->want_dy1 || resizer->next_want_dy > resizer->want_dy2)
		{
			resizer->put_func = gdi_imgdec_resizer_put_null;
			
			return;
		}
		resizer->next_want_dy += resizer->dir_y;
	}
	resizer->want_sx = *resizer->next_want_sx++;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_resizer_put_32
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_imgdec_resizer_put_32(gdi_imgdec_resizer_struct *resizer, gdi_color c, BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(want_draw)
	{
		 *(U32*)(resizer->dest) = (U32)c;
	}

	resizer->dest+=4;
	// generate next_position
	if(resizer->next_want_sx >= resizer->want_sx_table_end)
	{
		resizer->next_want_sx = resizer->want_sx_table;

		if(resizer->dir_x>0)
			resizer->dest = ((gdi_layer_struct*)(resizer->out_layer))->buf_ptr + (resizer->want_dx1+ resizer->next_want_dy* ((gdi_layer_struct*)(resizer->out_layer))->width )*4;
		else
			resizer->dest = ((gdi_layer_struct*)(resizer->out_layer))->buf_ptr + (resizer->want_dx2+ resizer->next_want_dy* ((gdi_layer_struct*)(resizer->out_layer))->width )*4;
		//resizer->want_sy = (((resizer->next_want_dy  - resizer->offset_dy) * resizer->y_scale_factor) >> 16);
		resizer->want_sy = ((((resizer->next_want_dy  - resizer->offset_dy) * resizer->src_height_range << 1) +  resizer->dest_height_range) / (resizer->dest_height_range << 1));

		if(resizer->next_want_dy < resizer->want_dy1 || resizer->next_want_dy > resizer->want_dy2)
		{
			resizer->put_func = gdi_imgdec_resizer_put_null;
			
			return;
		}
		resizer->next_want_dy += resizer->dir_y;
	}
	resizer->want_sx = *resizer->next_want_sx++;
}

#if  GDI_MAINLCD_BIT_PER_PIXEL ==  1 || !defined(GDI_USING_LAYER)


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_resizer_put_mainlcd
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_imgdec_resizer_put_mainlcd(gdi_imgdec_resizer_struct *resizer, gdi_color c, BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * W06.26 Fix the wrong position resizer->want_sx and resizer->want_sy
     * Use resizer->next_want_sx - resizer->want_sx_table instead of resizer->want_sx
     * as jumping to the next pixel
     * resizer->next_want_dy - 1 is the current y position
     */
	if(want_draw)
		DRV_MAINLCD_SET_BUFFER_PIXEL(
			(resizer->want_dx1 + (int)(resizer->next_want_sx - resizer->want_sx_table) - 1), 
			(resizer->next_want_dy - 1),
			(c));

	// generate next_position
	if(resizer->next_want_sx >= resizer->want_sx_table_end)
	{
		resizer->next_want_sx = resizer->want_sx_table;

		//resizer->want_sy = (((resizer->next_want_dy  - resizer->offset_dy) * resizer->y_scale_factor) >> 16);
		resizer->want_sy = ((((resizer->next_want_dy  - resizer->offset_dy) * resizer->src_height_range << 1) +  resizer->dest_height_range) / (resizer->dest_height_range << 1));

		if(resizer->next_want_dy < resizer->want_dy1 || resizer->next_want_dy > resizer->want_dy2)
		{
			resizer->put_func = gdi_imgdec_resizer_put_null;
			
			return;
		}
		resizer->next_want_dy += resizer->dir_y;
	}
	resizer->want_sx = *resizer->next_want_sx++;
}
#elif GDI_MAINLCD_BIT_PER_PIXEL == 16
	#define gdi_imgdec_resizer_put_mainlcd 	gdi_imgdec_resizer_put_16
#elif GDI_MAINLCD_BIT_PER_PIXEL == 24
	#define gdi_imgdec_resizer_put_mainlcd 	gdi_imgdec_resizer_put_24
#elif GDI_MAINLCD_BIT_PER_PIXEL == 32
	#define gdi_imgdec_resizer_put_mainlcd 	gdi_imgdec_resizer_put_32
#else
	#error "Unknown MAINLCD_BIT_PER_PIXEL"
#endif

#ifdef __MMI_SUBLCD__
#if GDI_SUBLCD_BIT_PER_PIXEL ==  1 || !defined(GDI_USING_LAYER)
/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_resizer_put_sublcd
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_imgdec_resizer_put_sublcd(gdi_imgdec_resizer_struct *resizer, gdi_color c, BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * W06.26 Fix the wrong position resizer->want_sx and resizer->want_sy
     * Use resizer->next_want_sx - resizer->want_sx_table instead of resizer->want_sx
     * as jumping to the next pixel
     * resizer->next_want_dy - 1 is the current y position
     */
	if(want_draw)
		DRV_SUBLCD_SET_BUFFER_PIXEL(
			(resizer->want_dx1 + (int)(resizer->next_want_sx - resizer->want_sx_table) - 1), 
			(resizer->next_want_dy - 1),
			(c));

	// generate next_position
	if(resizer->next_want_sx >= resizer->want_sx_table_end)
	{
		resizer->next_want_sx = resizer->want_sx_table;

		//resizer->want_sy = (((resizer->next_want_dy  - resizer->offset_dy) * resizer->y_scale_factor) >> 16);
		resizer->want_sy = ((((resizer->next_want_dy  - resizer->offset_dy) * resizer->src_height_range << 1) +  resizer->dest_height_range) / (resizer->dest_height_range << 1));

		if(resizer->next_want_dy < resizer->want_dy1 || resizer->next_want_dy > resizer->want_dy2)
		{
			resizer->put_func = gdi_imgdec_resizer_put_null;
			
			return;
		}
		resizer->next_want_dy += resizer->dir_y;
	}
	resizer->want_sx = *resizer->next_want_sx++;
}
#elif GDI_SUBLCD_BIT_PER_PIXEL == 16
	#define gdi_imgdec_resizer_put_sublcd 	gdi_imgdec_resizer_put_16
#elif GDI_SUBLCD_BIT_PER_PIXEL == 24
	#define gdi_imgdec_resizer_put_sublcd 	gdi_imgdec_resizer_put_24
#elif GDI_SUBLCD_BIT_PER_PIXEL == 32
	#define gdi_imgdec_resizer_put_sublcd 	gdi_imgdec_resizer_put_32
#else
		#error "Unknown SUBLCD_BIT_PER_PIXEL"
#endif
#endif

/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_non_resizer_put_8
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_imgdec_non_resizer_put_8(gdi_imgdec_resizer_struct *resizer, gdi_color c, BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	#define GDI_IMGDEC_RESIZER_PUT_PIXEL(COLOR)			*((U8*)resizer->dest) = (U8)COLOR
	#define GDI_IMGDEC_RESIZER_INCREASE_DEST				resizer->dest ++
	GDI_IMGDEC_NON_RESIZER_PUT_X(resizer, c, want_draw);
	#undef GDI_IMGDEC_RESIZER_PUT_PIXEL
	#undef GDI_IMGDEC_RESIZER_INCREASE_DEST
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_non_resizer_put_16
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_imgdec_non_resizer_put_16(gdi_imgdec_resizer_struct *resizer, gdi_color c, BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	#define GDI_IMGDEC_RESIZER_PUT_PIXEL(COLOR)		*((U16*)(resizer)->dest) = (U16)COLOR
	#define GDI_IMGDEC_RESIZER_INCREASE_DEST			(resizer)->dest +=2
	GDI_IMGDEC_NON_RESIZER_PUT_X(resizer, c, want_draw);
	#undef GDI_IMGDEC_RESIZER_PUT_PIXEL
	#undef GDI_IMGDEC_RESIZER_INCREASE_DEST
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_non_resizer_put_24
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_imgdec_non_resizer_put_24(gdi_imgdec_resizer_struct *resizer, gdi_color c, BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	#define GDI_IMGDEC_RESIZER_PUT_PIXEL(COLOR)			\
			do\
			{\
				U32 *ptr = (U32*)(resizer->dest);\
				switch(((U32)ptr)&0x3)\
				{\
				case 0:\
					*ptr = (*ptr&0xff000000)|(COLOR&0x00ffffff);\
					break;\
				case 1:\
					ptr= (U32*)(((U32)ptr)&(~0x3));\
					*ptr = (*ptr&0x000000ff)|(COLOR<<8);\
					break;\
				case 2:\
					ptr= (U32*)(((U32)ptr)&(~0x3));\
					*ptr = (*ptr&0x0000ffff)|(COLOR<<16); ptr++;\
					*ptr = (*ptr&0xffffff00)|((COLOR&0x00ff0000)>>16);\
					break;\
				default:\
					ptr= (U32*)(((U32)ptr)&(~0x3));\
					*ptr = (*ptr&0x00ffffff)|(COLOR<<24); ptr++;\
					*ptr = (*ptr&0xffff0000)|((COLOR&0x00ffff00)>>8);\
				}\
			}while(0)

	#define GDI_IMGDEC_RESIZER_INCREASE_DEST				resizer->dest +=3
	GDI_IMGDEC_NON_RESIZER_PUT_X(resizer, c, want_draw);
	#undef GDI_IMGDEC_RESIZER_PUT_PIXEL
	#undef GDI_IMGDEC_RESIZER_INCREASE_DEST
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_non_resizer_put_32
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_imgdec_non_resizer_put_32(gdi_imgdec_resizer_struct *resizer, gdi_color c, BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	#define GDI_IMGDEC_RESIZER_PUT_PIXEL(COLOR)			*((U32*)resizer->dest) = (U32)COLOR
	#define GDI_IMGDEC_RESIZER_INCREASE_DEST				resizer->dest +=4
	GDI_IMGDEC_NON_RESIZER_PUT_X(resizer, c, want_draw);
	#undef GDI_IMGDEC_RESIZER_PUT_PIXEL
	#undef GDI_IMGDEC_RESIZER_INCREASE_DEST
}

#if  GDI_MAINLCD_BIT_PER_PIXEL ==  1 || !defined(GDI_USING_LAYER)
/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_non_resizer_put_mainlcd
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_imgdec_non_resizer_put_mainlcd(gdi_imgdec_resizer_struct *resizer, gdi_color c, BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	#define GDI_IMGDEC_RESIZER_PUT_PIXEL(COLOR)			DRV_MAINLCD_SET_BUFFER_PIXEL((resizer->offset_dx + resizer->want_sx),(resizer->offset_dy + resizer->want_sy),COLOR)
	#define GDI_IMGDEC_RESIZER_INCREASE_DEST				
	GDI_IMGDEC_NON_RESIZER_PUT_X(resizer, c, want_draw);
	#undef GDI_IMGDEC_RESIZER_PUT_PIXEL
	#undef GDI_IMGDEC_RESIZER_INCREASE_DEST
}
#elif GDI_MAINLCD_BIT_PER_PIXEL == 16
	#define gdi_imgdec_non_resizer_put_mainlcd 	gdi_imgdec_non_resizer_put_16
#elif GDI_MAINLCD_BIT_PER_PIXEL == 24
	#define gdi_imgdec_non_resizer_put_mainlcd 	gdi_imgdec_non_resizer_put_24
#elif GDI_MAINLCD_BIT_PER_PIXEL == 32
	#define gdi_imgdec_non_resizer_put_mainlcd 	gdi_imgdec_non_resizer_put_32
#else
	#error "Unknown MAINLCD_BIT_PER_PIXEL"
#endif

#ifdef __MMI_SUBLCD__
#if GDI_SUBLCD_BIT_PER_PIXEL ==  1 || !defined(GDI_USING_LAYER)
/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_non_resizer_put_sublcd
 * DESCRIPTION
 *  put pixel
 * PARAMETERS
 *  c               [IN]    color want to output
 *  want_draw       [IN]    if false, it will not modify color of this pixel
 * RETURNS
 *  void
 *****************************************************************************/
static void gdi_imgdec_non_resizer_put_sublcd(gdi_imgdec_resizer_struct *resizer, gdi_color c, BOOL want_draw)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	#define GDI_IMGDEC_RESIZER_PUT_PIXEL(COLOR)			DRV_SUBLCD_SET_BUFFER_PIXEL((resizer->offset_dx + resizer->want_sx),(resizer->offset_dy + resizer->want_sy),COLOR)
	#define GDI_IMGDEC_RESIZER_INCREASE_DEST				
	GDI_IMGDEC_NON_RESIZER_PUT_X(resizer, c, want_draw);
	#undef GDI_IMGDEC_RESIZER_PUT_PIXEL
	#undef GDI_IMGDEC_RESIZER_INCREASE_DEST
}
#elif GDI_MAINLCD_BIT_PER_PIXEL == 16
	#define gdi_imgdec_non_resizer_put_sublcd 	gdi_imgdec_non_resizer_put_16
#elif GDI_MAINLCD_BIT_PER_PIXEL == 24
	#define gdi_imgdec_non_resizer_put_sublcd 	gdi_imgdec_non_resizer_put_24
#elif GDI_MAINLCD_BIT_PER_PIXEL == 32
	#define gdi_imgdec_non_resizer_put_sublcd 	gdi_imgdec_non_resizer_put_32
#else
	#error "Unknown MAINLCD_BIT_PER_PIXEL"
#endif
#endif

// TODO: NOT USED. TO BE DELETED.
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

const static gdi_imgdec_resizer_put_func gdi_imgdec_resizer_put_table[]=
{
	(gdi_imgdec_resizer_put_func)gd_null_pointer_function, // 1
	gdi_imgdec_resizer_put_8, // 8
	gdi_imgdec_resizer_put_16, // 16
	#if defined(GDI_SLIM_COLOR_FORMAT)
    (gdi_imgdec_resizer_put_func)gd_null_pointer_function, // 24
    #else
	gdi_imgdec_resizer_put_24, // 24
	#endif
	gdi_imgdec_resizer_put_32, // 32
	gdi_imgdec_resizer_put_32, // 32PARGB
	(gdi_imgdec_resizer_put_func)gd_null_pointer_function, // UYVY422
	(gdi_imgdec_resizer_put_func)gd_null_pointer_function, // A8
	gdi_imgdec_resizer_put_24, //PARGB6666
	gdi_imgdec_resizer_put_mainlcd, // main
#ifdef __MMI_SUBLCD__
	gdi_imgdec_resizer_put_sublcd
#else
	(gdi_imgdec_resizer_put_func)gd_null_pointer_function, // sub
#endif
};
const static gdi_imgdec_resizer_put_func gdi_imgdec_non_resizer_put_table[]=
{
	(gdi_imgdec_resizer_put_func)gd_null_pointer_function, // 1
	gdi_imgdec_non_resizer_put_8, // 8
	gdi_imgdec_non_resizer_put_16, // 16
	#if defined(GDI_SLIM_COLOR_FORMAT)
    (gdi_imgdec_resizer_put_func)gd_null_pointer_function, // 24
    #else
	gdi_imgdec_non_resizer_put_24, // 24
	#endif
	gdi_imgdec_non_resizer_put_32, // 32
	gdi_imgdec_non_resizer_put_32, // 32PARGB
	(gdi_imgdec_resizer_put_func)gd_null_pointer_function, // UYVY422
	(gdi_imgdec_resizer_put_func)gd_null_pointer_function, // A8
	gdi_imgdec_non_resizer_put_24, //PARGB6666
	gdi_imgdec_non_resizer_put_mainlcd, // main
#ifdef __MMI_SUBLCD__
	gdi_imgdec_non_resizer_put_sublcd // sub
#else
	(gdi_imgdec_resizer_put_func)gd_null_pointer_function // sub
#endif
};


/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_resizer_init
 * DESCRIPTION
 *  init the resizer
 * PARAMETERS
 *  src_width              [IN] srouce width
 *  src_height             [IN] source height
 *  src_clipx1             [IN] source clip x1
 *  src_clipy1             [IN] source clip y1
 *  src_clipx2             [IN] source clip x2
 *  src_clipy2             [IN] source clip y2
 *  dest_x1                [IN] destination x1
 *  dest_y1                [IN] destination y1
 *  dest_x2                [IN] destination x2
 *  dest_y2                [IN] destination y2
 * RETURNS
 *  S32, return 0 if no pixel to output, 1 if decoder need to continue to decode, -1 if error.
 *****************************************************************************/
S32 gdi_imgdec_resizer_init(
                gdi_imgdec_resizer_struct *resizer,
                gdi_handle out_layer,
				S32 src_width,S32 src_height, 
				S32 src_clipx1, S32 src_clipy1,S32 src_clipx2,S32 src_clipy2,
				S32 dest_x1,S32 dest_y1,S32 dest_x2,S32 dest_y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dest_width;
	S32 dest_height;
	S32 dir_x;
	S32 dir_y;
	S32 src_width_range;
	S32 src_height_range;
	S32 dest_width_range;
	S32 dest_height_range;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    resizer->want_sx = resizer->want_sy = -1;
	
	// we don't support 1, 8 bites color format in this resizer
	if(src_width  <=0) return 0;
	if(src_height <=0) return 0;

	dir_x=dir_y=1;

	if(dest_x1>dest_x2)
	{
		return FALSE; // current, we only support dir_x >0
		//SWAP(S32,dest_x1,dest_x2); //warning
		//dir_x = -1;
	}
	if(dest_y1>dest_y2)
	{
		SWAP(S32,dest_y1,dest_y2);
		dir_y = -1;
	}

	resizer->out_layer = out_layer;
	resizer->dest = ((gdi_layer_struct*)(resizer->out_layer))->buf_ptr;
	resizer->offset_dx = dest_x1;
	resizer->offset_dy = dest_y1;
	dest_width = dest_x2-dest_x1+1;
	dest_height = dest_y2-dest_y1+1;

	// TODO: IS THIS NECESSARY?
    // gdi_image_set_update_area(dest_x1,dest_y1,dest_x2,dest_y2);
	
	resizer->want_dx1 = dest_x1;
	resizer->want_dy1 = dest_y1;
	resizer->want_dx2 = dest_x2;
	resizer->want_dy2 = dest_y2;

	resizer->dir_x = dir_x;
	resizer->dir_y = dir_y;
	
	// check the clipping area
	GDI_IMGDEC_LAYER_CLIP_RECT_TEST(((gdi_layer_struct*)out_layer), resizer->want_dx1,resizer->want_dy1,resizer->want_dx2,resizer->want_dy2,return 0); // no pixel will be render !!

	/* W06.16 Use Coordinate Range instead of width and height */
	/* Use round off to compute want_sx and want_sy */
	if (1 == src_width)
	{
		src_width = 2;
	}
	if (1 == dest_width)
	{
		dest_width = 2;
	}
	if (1 == src_height)
	{
		src_height = 2;
	}
	if (1 == dest_height)
	{
		dest_height = 2;
	}
	src_width_range = src_width - 1;
	src_height_range = src_height - 1;
	dest_width_range  = dest_width - 1;
	dest_height_range  = dest_height - 1;
	//multiply_factor = ((src_width_range) <<16)/ (dest_width_range);
	// make y_scale_factor
	//resizer->y_scale_factor 		= ((src_height_range)<<16)  / (dest_height_range);
	//resizer->y_inv_scale_factory	= ((dest_height_range)<<16 )  / (src_height_range);
	resizer->src_height_range 		= src_height_range;
	resizer->dest_height_range	= dest_height_range;

	{
		int dx1,dy1,dx2,dy2;
		// check the source clipping area
		dx1 = dest_x1 + (src_clipx1*(dest_width_range<<1) + src_width_range)/(src_width_range<<1);
		dx2 = dest_x1 + (src_clipx2*(dest_width_range<<1) + src_width_range)/(src_width_range<<1);		
		
		dy1 = dest_y1 + (src_clipy1*(dest_height_range<<1) + src_height_range)/(src_height_range<<1);
		dy2 = dest_y1 + (src_clipy2*(dest_height_range)<<1) + src_height_range/(src_height_range<<1);		

		GDI_CLIP_TWO_RECT(
			resizer->want_dx1, resizer->want_dy1,
			resizer->want_dx2, resizer->want_dy2,
			dx1,dy1,
			dx2,dy2,
			return 0);

		//W05.39 Check points may be out of clipping area because of dividing
		while ( (((resizer->want_dx1 - resizer->offset_dx) * src_width_range << 1) + dest_width_range) / (dest_width_range << 1) < src_clipx1 )
			resizer->want_dx1++;

		while((((resizer->want_dy1 - resizer->offset_dy) * src_height_range << 1) + dest_height_range) / (dest_height_range << 1) < src_clipy1)
			resizer->want_dy1++;

		while ( (((resizer->want_dx2 - resizer->offset_dx) * src_width_range << 1) + dest_width_range) / (dest_width_range << 1) > src_clipx2 )
			resizer->want_dx2--;

		while((((resizer->want_dy2 - resizer->offset_dy) * src_height_range << 1) + dest_height_range) / (dest_height_range << 1)> src_clipy2)
			resizer->want_dy2--;
	}


	// non resize handler
	if(src_width == dest_width && src_height == dest_height)
	{
		U32 bytes_per_pixel = gdi_bits_per_pixel(((gdi_layer_struct*)(resizer->out_layer))->vcf) >> 3;
		resizer->want_sx_table = NULL;
		resizer->dest = ((gdi_layer_struct*)(resizer->out_layer))->buf_ptr;
		if(dir_x >0)
		{
			resizer->want_sx 		=
			resizer->want_start_sx = resizer->want_dx1 - dest_x1;
			resizer->want_end_sx 	= resizer->want_dx2 - dest_x1;
			
			resizer->dest 		+= resizer->want_dx1*bytes_per_pixel;
		}
		else
		{
			resizer->want_sx 		=
			resizer->want_start_sx = resizer->want_dx2 - dest_x1;
			resizer->want_end_sx  = resizer->want_dx1 - dest_x1;
			resizer->dest 		+= resizer->want_dx2*bytes_per_pixel;			
		}
		if(dir_y >0)
		{
			resizer->want_sy 		=
			resizer->want_start_sy = resizer->want_dy1 - dest_y1;
			resizer->want_end_sy 	= resizer->want_dy2 - dest_y1;
			
			resizer->dest 		+= resizer->want_dy1*((gdi_layer_struct*)(resizer->out_layer))->width*bytes_per_pixel;
			resizer->dest_pitch_jump = (((gdi_layer_struct*)(resizer->out_layer))->width - (resizer->want_dx2-resizer->want_dx1+1)) * bytes_per_pixel; ///TODO: only support dir_x>0
		}
		else
		{
			resizer->want_sy 		=
			resizer->want_start_sy = resizer->want_dy2 - dest_y1;
			resizer->want_end_sy  = resizer->want_dy1 - dest_y1;
			
			resizer->dest 		+= resizer->want_dy2*((gdi_layer_struct*)(resizer->out_layer))->width*bytes_per_pixel;
			resizer->dest_pitch_jump = -(((gdi_layer_struct*)(resizer->out_layer))->width + (resizer->want_dx2-resizer->want_dx1+1)) * bytes_per_pixel; ///TODO: only support dir_x>0
		}
		resizer->put_func = gdi_imgdec_non_resizer_put_table[((gdi_layer_struct*)(resizer->out_layer))->cf];

		return 1;		
	}


	// assign want_sx_table memory space
	if (resizer->want_dx2-resizer->want_dx1+1 > GDI_MAX_RESIZE_WIDTH)
	{
	    return -1;
	}

    // make want_x table
	{
		S32 x;
		S32 i;
		S32 start_dx,end_dx;

		if(dir_x>0)
		{
			start_dx = resizer->want_dx1;
			end_dx = resizer->want_dx2;
		}
		else
		{
			start_dx = resizer->want_dx2;
			end_dx = resizer->want_dx1;
		}
			
        // TODO: use memory allocator
        resizer->want_sx_table = (S16*)gdi_alloc_ext_mem((end_dx - start_dx + 1) * sizeof(S16));
        if (resizer->want_sx_table == NULL)
        {
            return 0;
        }
    	
		for(i=0,x=start_dx;x<=end_dx;x+=dir_x,i++)
		{
			S32 d = x - dest_x1;
			resizer->want_sx_table[i] = (S16)((((d) * src_width_range << 1) + dest_width_range) / (dest_width_range << 1));
		}
		resizer->want_sx_table_end = resizer->want_sx_table+i;
		resizer->next_want_sx = resizer->want_sx_table;
	}

	if(dir_y>0)
		resizer->next_want_dy = resizer->want_dy1;
	else
		resizer->next_want_dy = resizer->want_dy2;

	// set the put pixel function pointer
	resizer->put_func = gdi_imgdec_resizer_put_table[((gdi_layer_struct*)(resizer->out_layer))->cf];
	// init want position
	if(dir_x>0)
		resizer->dest = ((gdi_layer_struct*)(resizer->out_layer))->buf_ptr + (((resizer->want_dx1+ resizer->next_want_dy* ((gdi_layer_struct*)(resizer->out_layer))->width )* gdi_bits_per_pixel(((gdi_layer_struct*)(resizer->out_layer))->vcf))>>3);
	else
		resizer->dest = ((gdi_layer_struct*)(resizer->out_layer))->buf_ptr + (((resizer->want_dx2+ resizer->next_want_dy* ((gdi_layer_struct*)(resizer->out_layer))->width )* gdi_bits_per_pixel(((gdi_layer_struct*)(resizer->out_layer))->vcf))>>3);
	
	resizer->want_sx = *resizer->next_want_sx++;
	resizer->want_sy = ((((resizer->next_want_dy  - resizer->offset_dy) * src_height_range << 1) +  dest_height_range) / (dest_height_range << 1));
	resizer->next_want_dy +=dir_y;

	return 1;
}


/*****************************************************************************
 * FUNCTION
 *  gdi_imgdec_resizer_deinit
 * DESCRIPTION
 *  Deinit resizer.
 * PARAMETERS
 *  resizer       [IN]  resizer structure
 * RETURNS
 *  void
 *****************************************************************************/
void gdi_imgdec_resizer_deinit(gdi_imgdec_resizer_struct *resizer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: use memory allocator
    if (resizer->want_sx_table)
    {
        gdi_free_ext_mem((void*)&resizer->want_sx_table);
    }
}


