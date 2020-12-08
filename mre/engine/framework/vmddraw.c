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
*  
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  
*
* Author:
* -------
*
*
*==============================================================================
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_features.h"
#include "PixcomFontEngine.h"
#include "vmswitch.h"
#include "gdi_include.h"
#ifdef __MRE_LIB_GRAPIC_DDRAW__
#include "string.h"
#include "math.h"
#include "vmsys.h"
#include "vmgraph.h"
#include "vmlog.h"
#include "vmmod.h"
#include "vmpromng.h"

#define VM_LCD_BUFF_IS_16BIT		

#define MRE_SUPPORT_MULTILAYER


const char * const MTK_CAN_MAGIC = "MTKCAN";
const char * const MTK_CANVAS_MAGIC = "MTKCANVAS";

#define blend(dst, src, alpha)	((((src - dst) * alpha) >> 8) + dst)	//alpha (0 ~ 255)

#define blend565(dst, src, alpha)	((blend((dst & 0xf800), (src & 0xf800), alpha) & 0xf800) | \
    (blend((dst & 0x07e0), (src & 0x07e0), alpha) & 0x07e0) | \
    (blend((dst & 0x001f), (src & 0x001f), alpha) & 0x001f))


#define GDI_ACT_COLOR_FROM_RGB(color16) ( gdi_act_color_from_rgb(255, VM_COLOR_GET_RED(color16), VM_COLOR_GET_GREEN(color16), VM_COLOR_GET_BLUE(color16)) )


extern layer_param_t layer_trans_tbl[];


extern VMINT active_layer ;
extern VMINT vm_graphic_canvas_textout_internal(VMUINT8* platform_disp_buffer, 
                                                VMUINT width, VMUINT height, VMUINT text_x, VMUINT text_y, 
                                                VMUINT clip_x1, VMUINT clip_y1, VMUINT clip_x2, VMUINT clip_y2,
                                                VMWSTR text, VMINT length, VMUINT32 text_color);
extern VMINT vm_graphic_layer_textout_internal(VMUINT8* platform_disp_buffer, 
                                               VMUINT text_x, VMUINT text_y, 
                                               VMUINT clip_x1, VMUINT clip_y1, VMUINT clip_x2, VMUINT clip_y2,
                                               VMWSTR text, VMINT length, VMUINT32 text_color);

extern VMINT vm_graphic_canvas_textout_by_baseline_internal(VMUINT8* platform_disp_buffer, 
                                                            VMUINT width, VMUINT height, VMUINT text_x, VMUINT text_y, 
                                                            VMUINT clip_x1, VMUINT clip_y1, VMUINT clip_x2, VMUINT clip_y2,
                                                            VMWSTR text, VMINT length, VMUINT32 text_color,VMINT baseline);
extern VMINT vm_graphic_layer_textout_by_baseline_internal(VMUINT8* platform_disp_buffer, 
                                                           VMUINT text_x, VMUINT text_y, 
                                                           VMUINT clip_x1, VMUINT clip_y1, VMUINT clip_x2, VMUINT clip_y2,
                                                           VMWSTR text, VMINT length, VMUINT32 text_color,VMINT baseline);

extern	VM_GDI_RESULT vm_graphic_set_layer_clip_internal(VMINT handle ,VMINT16 x1,VMINT16 y1,VMINT16 x2,VMINT16 y2);

extern VMINT is_color_format_valid(vm_graphic_color_famat cf);
extern VM_GDI_RESULT convert_to_gdi_color_format(vm_graphic_color_famat cf, gdi_color_format *color_format);
extern VM_GDI_RESULT calculate_datasize_from_cf(vm_graphic_color_famat cf, VMINT width, VMINT height, VMINT *datasize);

extern VMINT get_canvas_prop(VMBYTE *buf,vm_canvas_prop  type);

extern vm_graphic_cb * vm_graphic_get_current_cb(void);


static void dd_circle(VMUINT8 *buf, VMINT x, VMINT y, VMINT r, VMINT quadrant, VMUINT16 color_rgb565, vm_graphic_color_argb* p_color_argb); 

extern VMUINT vm_graphic_get_trans_handle(VMINT handle);
extern VMINT vm_graphic_get_layer_porp_from_buf(VMUINT8* platform_disp_buffer,VMINT *x,VMINT *y, VMINT *width, VMINT *height, vm_graphic_color_famat *cf);
static VMINT vm_graphic_get_handle_from_buf(VMUINT8 *buf,VMUINT* gdi_layer_handle,VMINT* bIsCanvas,VMINT* buf_x, VMINT* buf_y,VMINT* buf_width,VMINT* buf_height);

void _vm_graphic_set_pixel(VMUINT8 *buf, VMINT x, VMINT y, VMUINT16 color_rgb565, vm_graphic_color_argb* p_color_argb);

extern VMINT layer_operation_permission_check(void);

static vm_graphic_check_module_result vm_graphic_check_module_state(void)
{
    if( layer_operation_permission_check() < 0 )
        return VM_GRAPHIC_CHECK_MODULE_RET_MIBR;
    if ( _vm_get_status() != MOD_STATUS_RUNNING )
        return VM_GRAPHIC_CHECK_MODULE_RET_STATUS;

	return VM_GRAPHIC_CHECK_MODULE_SUCCEED;
}


/*****************************************************************************
* FUNCTION
*  dd_circle
* DESCRIPTION
*  
* PARAMETERS
*  buf             [?]         
*  x               [IN]        
*  y               [IN]        
*  r               [IN]        
*  quadrant        [IN]        
*  color           [IN]        
* RETURNS
*  void
*****************************************************************************/
static void dd_circle(VMUINT8 *buf, VMINT x, VMINT y, VMINT r, VMINT quadrant, VMUINT16 color_rgb565, vm_graphic_color_argb* p_color_argb) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT x1,y1,d;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buf == NULL)
        return;

    x1=0;y1=r;d=1-r;               
    while(x1 <= y1)
    {
        if (quadrant & 0x02) {
            _vm_graphic_set_pixel(buf, x + x1, y + y1, color_rgb565, p_color_argb);
            _vm_graphic_set_pixel(buf, x + y1, y + x1, color_rgb565, p_color_argb);
        }
        if (quadrant & 0x04) {
            _vm_graphic_set_pixel(buf, x - x1, y + y1, color_rgb565, p_color_argb);
            _vm_graphic_set_pixel(buf, x - y1, y + x1, color_rgb565, p_color_argb);
        }
        if (quadrant & 0x01) {
            _vm_graphic_set_pixel(buf, x + x1, y - y1, color_rgb565, p_color_argb);
            _vm_graphic_set_pixel(buf, x + y1, y - x1, color_rgb565, p_color_argb);
        }
        if (quadrant & 0x08) {
            _vm_graphic_set_pixel(buf, x - x1, y - y1, color_rgb565, p_color_argb);
            _vm_graphic_set_pixel(buf, x - y1, y - x1, color_rgb565, p_color_argb);
        }

		if (x1 == y1)
		{
			break;
		}
		else
		{
	        if(d<0)  
	            d+=2*x1+3;
	        else
	        { d+=2*(x1-y1)+5;
	        y1--;
	        }
	        x1++;
		}
    }     
}

VMUINT32 vm_graphic_get_frame_offset(VMUINT8 *data, VMUINT8 frame_index)
{
    int i;
    VMUINT32 frame_offset;
    VMUINT32 frame_data_offset;

    frame_offset = VM_CANVAS_SIGNATURE_SIZE;			
    for( i = 1; i < frame_index; i++ )
    {
        frame_data_offset = data[frame_offset+16] 
            + (data[frame_offset+17]<<8)
            + (data[frame_offset+18]<<16) 
            + (data[frame_offset+19]<<24);
        frame_offset += frame_data_offset + VM_CANVAS_FRAME_PROPERTY_SIZE;
    }

    return frame_offset;
}

/*****************************************************************************
* FUNCTION
*  vm_graphic_get_img_property
* DESCRIPTION
*  
* PARAMETERS
*  hcanvas         [IN]        
*  frame_index     [IN]        
* RETURNS
*  
*****************************************************************************/
struct frame_prop * vm_graphic_get_img_property(VMINT hcanvas, VMUINT8 frame_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8		frame_num;
    VMUINT32	frame_offset;
    VMUINT8*	img;
    static struct frame_prop frame_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
    img = (VMUINT8*)hcanvas;

    if (!img || memcmp(img, MTK_CAN_MAGIC, 6) || frame_index == 0)	
        return NULL;	
	
    frame_num = img[VM_CANVAS_FRAME_NUM_OFFSET];
    if (frame_index > frame_num)	
        return NULL;	
    
    frame_offset = vm_graphic_get_frame_offset(img, frame_index);
    
    frame_info.flag			= img[frame_offset];
    frame_info.left			= img[frame_offset+1] + (img[frame_offset+2]<<8); 
    frame_info.top			= img[frame_offset+3] + (img[frame_offset+4]<<8); 
    frame_info.width		= img[frame_offset+5] + (img[frame_offset+6]<<8); 
    frame_info.height		= img[frame_offset+7] + (img[frame_offset+8]<<8);
    frame_info.delay_time	= (img[frame_offset+9] + (img[frame_offset+10]<<8))*10;
    frame_info.trans_color_index = img[frame_offset+11];
    frame_info.trans_color  = img[frame_offset+12] + (img[frame_offset+13]<<8);
    frame_info.offset		= img[frame_offset+16] + (img[frame_offset+17]<<8) + (img[frame_offset+18]<<16) + (img[frame_offset+19]<<24);
	
    return &frame_info;
}

VMUINT8* vm_graphic_get_img_buffer(VMINT hcanvas, VMUINT8 frame_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8		frame_num;
    VMUINT32	frame_offset;
    VMUINT8*	img;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    img = (VMUINT8*)hcanvas;

    if (!img || memcmp(img, MTK_CAN_MAGIC, 6) || frame_index == 0)	
        return NULL;	
	
    frame_num = img[VM_CANVAS_FRAME_NUM_OFFSET];
    if (frame_index > frame_num)	
        return NULL;	
	
    frame_offset = vm_graphic_get_frame_offset(img, frame_index);
	
    return (img + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE);
}


/*****************************************************************************
* FUNCTION
*  vm_graphic_get_frame_number
* DESCRIPTION
*  
* PARAMETERS
*  hcanvas     [IN]        
* RETURNS
*  
*****************************************************************************/
VMINT vm_graphic_get_frame_number(VMINT hcanvas)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8*	img;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img = (VMUINT8*)hcanvas;
    if (!img || memcmp(img, MTK_CAN_MAGIC, 6))
        return VM_GDI_ERR_WRONG_PARAM;
	
    return img[VM_CANVAS_FRAME_NUM_OFFSET];
}


/*****************************************************************************
* FUNCTION
*  vm_graphic_create_canvas_cf
* DESCRIPTION
*  
* PARAMETERS
*  width       [IN]        
*  height      [IN]        
* RETURNS
*  
*****************************************************************************/
VMINT vm_graphic_create_canvas_cf(vm_graphic_color_famat cf, VMINT width, VMINT height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8 *buffer = NULL;
    VMINT data_size;
    VMINT offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (width <= 0 || height <= 0)
        return VM_GDI_FAILED;

	if ( ( calculate_datasize_from_cf(cf, width, height, &data_size) ) < 0 )
        return VM_GDI_FAILED;	

    if ((buffer = (VMUINT8 *)vm_malloc_nc(VM_CANVAS_SIGNATURE_SIZE + VM_CANVAS_FRAME_PROPERTY_SIZE + data_size)) == NULL)
    {
        MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMDDRAW_498 , data_size);
        return VM_GDI_FAILED;
    }
	
    memset(buffer, 0, VM_CANVAS_SIGNATURE_SIZE + VM_CANVAS_FRAME_PROPERTY_SIZE + data_size);
    memcpy(buffer, MTK_CANVAS_MAGIC, 9);
    buffer[VM_CANVAS_FRAME_NUM_OFFSET] = 1;
    buffer[VM_CANVAS_FRAME_NUM_OFFSET + 1] = 0xff;
    buffer[VM_CANVAS_FRAME_NUM_OFFSET + 2] = cf;

    offset = VM_CANVAS_SIGNATURE_SIZE;
    buffer[offset] = 0;
    buffer[offset + 1] = 0;	        buffer[offset + 2] = 0;							//left
    buffer[offset + 3] = 0;         buffer[offset + 4] = 0;							//top
    buffer[offset + 5] = (width % 256);	    buffer[offset + 6] = (width >> 8);		//width
    buffer[offset + 7] = (height % 256);	buffer[offset + 8] = (height >> 8);		//height
    buffer[offset + 9] = 0;	buffer[offset + 10] = 0;								//delay
    buffer[offset + 11] = 0;
    buffer[offset + 12] = 0;	    buffer[offset + 13] = 0;
    buffer[offset + 14] = 0;	    buffer[offset + 15] = 0;
    buffer[offset + 16] = data_size & 0x000000ff; 
    buffer[offset + 17] = (data_size & 0x0000ff00) >> 8; 
    buffer[offset + 18] = (data_size & 0x00ff0000) >> 16;
    buffer[offset + 19] = (data_size & 0xff000000) >> 24;
	
    MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMDDRAW_524 , buffer);
	
    return (VMINT)buffer;	
}

/*****************************************************************************
* FUNCTION
*  vm_graphic_create_canvas
* DESCRIPTION
*  
* PARAMETERS
*  width       [IN]        
*  height      [IN]        
* RETURNS
*  
*****************************************************************************/
VMINT vm_graphic_create_canvas(VMINT width, VMINT height)
{
	return vm_graphic_create_canvas_cf(VM_GRAPHIC_COLOR_FORMAT_16, width, height);
}


/*****************************************************************************
* FUNCTION
*  vm_graphic_release_canvas
* DESCRIPTION
*  
* PARAMETERS
*  hcanvas     [IN]        
* RETURNS
*  void
*****************************************************************************/
void vm_graphic_release_canvas(VMINT hcanvas)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8 *img;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(hcanvas < 0)
    {
		MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMDDRAW_552 );
        return;
    }
	
    img = (VMUINT8*)hcanvas;
    MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMDDRAW_557 , img);
	
    vm_free(img);
}


/*****************************************************************************
* FUNCTION
*  vm_graphic_get_canvas_buffer
* DESCRIPTION
*  
* PARAMETERS
*  hcanvas     [IN]        
* RETURNS
*  
*****************************************************************************/
VMUINT8* vm_graphic_get_canvas_buffer (VMINT hcanvas)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8 *img;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img = (VMUINT8*)hcanvas;
	
    return img;
}


VMINT vm_graphic_get_canvas_buffer_size (VMINT hcanvas)
{
	VMINT frame_offset, frame_data_offset;
	VMINT frame_num;
	VMUINT8 *img;
	VMINT i;

    if(hcanvas <= 0)
    {
        return 0;
    }
    
    img = (VMUINT8*)hcanvas;
	
    frame_num = img[VM_CANVAS_FRAME_NUM_OFFSET];
	
    frame_offset = VM_CANVAS_SIGNATURE_SIZE;			
    for(i=1; i<=frame_num; i++)
    {
        frame_data_offset = img[frame_offset+16] 
        + (img[frame_offset+17]<<8)
            + (img[frame_offset+18]<<16) 
            + (img[frame_offset+19]<<24);
        frame_offset += frame_data_offset + VM_CANVAS_FRAME_PROPERTY_SIZE;
    }
	
	return frame_offset;
}



/*****************************************************************************
* FUNCTION
*  vm_graphic_set_clip
* DESCRIPTION
*  
* PARAMETERS
*  x1      [IN]        
*  y1      [IN]        
*  x2      [IN]        
*  y2      [IN]        
* RETURNS
*  void
*****************************************************************************/
void vm_graphic_set_clip(VMINT x1, VMINT y1, VMINT x2, VMINT y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT tmp;
	vm_graphic_cb *current_cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return;

	current_cb = vm_graphic_get_current_cb();
	if (current_cb == NULL)
		return;		
	
    current_cb->cliprect.left = x1 < 0 ? 0 : x1;
    current_cb->cliprect.top = y1 < 0 ? 0 : y1;
    current_cb->cliprect.right = x2 < 0 ? 0 : x2;
    current_cb->cliprect.bottom = y2 < 0 ? 0 : y2;
    current_cb->cliprect.flag = 1;
    if (current_cb->cliprect.left  > current_cb->cliprect.right)
    {
        tmp = current_cb->cliprect.left;
        current_cb->cliprect.left = current_cb->cliprect.right;
        current_cb->cliprect.right = tmp;
    }

    if (current_cb->cliprect.top  > current_cb->cliprect.bottom)
    {
        tmp = current_cb->cliprect.top;
        current_cb->cliprect.top = current_cb->cliprect.bottom;
        current_cb->cliprect.bottom = tmp;
    }
    vm_graphic_set_layer_clip_internal(current_cb->active_layer,x1, y1, x2, y2);
}


/*****************************************************************************
* FUNCTION
*  vm_graphic_reset_clip
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void vm_graphic_reset_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vm_graphic_cb *current_cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	if ( vm_graphic_check_module_state() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return;

	current_cb = vm_graphic_get_current_cb();
	if (current_cb == NULL)
		return ;		
	
    current_cb->cliprect.flag = 1;
    current_cb->cliprect.left = 0;
    current_cb->cliprect.top = 0;
    current_cb->cliprect.right = LCD_WIDTH - 1;
    current_cb->cliprect.bottom = LCD_HEIGHT - 1;
}


static VMBOOL vm_graphic_buf_operation_setup(VMBYTE *dst_buf, VMBYTE *source_surface, VMINT frame_index, 
					clip_rect *cliprect,										
					struct _buf_prop * dst_buf_prop, struct _frame_prop * src_frame_prop)
{
	vm_graphic_cb *current_cb;
    VMBYTE	frame_num;	
    VMINT   ret;	

	if ( vm_graphic_check_module_state() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return FALSE;

	current_cb = vm_graphic_get_current_cb();
	if (current_cb == NULL)
		return FALSE;		

    memcpy(cliprect, &(current_cb->cliprect), sizeof(clip_rect));	

    if ((dst_buf == NULL) || (source_surface == NULL))
        return FALSE;

    frame_num = source_surface[VM_CANVAS_FRAME_NUM_OFFSET];
	if ( ( cliprect->flag == 0 ) || ( frame_index > frame_num ) || ( frame_index <= 0 ) )										
        return FALSE;

	src_frame_prop->cf = source_surface[VM_CANVAS_FRAME_NUM_OFFSET + 2];
	if ( !is_color_format_valid(src_frame_prop->cf) )
		return FALSE;
	
	if (memcmp(dst_buf, MTK_CAN_MAGIC, 6) == 0)
	{
		dst_buf_prop->dst_is_canvas = 1;

		dst_buf_prop->buf_x = dst_buf[VM_CANVAS_SIGNATURE_SIZE+1] + (dst_buf[VM_CANVAS_SIGNATURE_SIZE+2]<<8); 
		dst_buf_prop->buf_y = dst_buf[VM_CANVAS_SIGNATURE_SIZE+3] + (dst_buf[VM_CANVAS_SIGNATURE_SIZE+4]<<8); 
		dst_buf_prop->buf_width = (dst_buf[VM_CANVAS_SIGNATURE_SIZE + 6] << 8) + dst_buf[VM_CANVAS_SIGNATURE_SIZE + 5]; 
		dst_buf_prop->buf_height = (dst_buf[VM_CANVAS_SIGNATURE_SIZE + 8] << 8) + dst_buf[VM_CANVAS_SIGNATURE_SIZE + 7]; 

		dst_buf_prop->cf = dst_buf[VM_CANVAS_FRAME_NUM_OFFSET + 2];

		dst_buf_prop->buf_ex = dst_buf + VM_CANVAS_SIGNATURE_SIZE + VM_CANVAS_FRAME_PROPERTY_SIZE;
	}
	else
	{
		dst_buf_prop->dst_is_canvas = 0;
#ifndef MRE_SUPPORT_MULTILAYER		
		dst_buf_prop->buf_width = LCD_WIDTH;
		dst_buf_prop->buf_height = LCD_HEIGHT;
#else
		ret = vm_graphic_get_layer_porp_from_buf(dst_buf, 
            					&(dst_buf_prop->buf_x), &(dst_buf_prop->buf_y),
            					&(dst_buf_prop->buf_width), &(dst_buf_prop->buf_height),
            					&(dst_buf_prop->cf));
		if (ret == GDI_FAILED)
		{
			MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMDDRAW_339 );
			return FALSE;
		}
#endif
		dst_buf_prop->buf_ex = dst_buf;
	}
		
	if ( !is_color_format_valid(dst_buf_prop->cf) )
		return FALSE;

	if (cliprect->left < 0)
		cliprect->left = 0;
	if (cliprect->right >= dst_buf_prop->buf_width)
		cliprect->right = dst_buf_prop->buf_width - 1;
	if (cliprect->top < 0)
		cliprect->top = 0;
	if (cliprect->bottom >= dst_buf_prop->buf_height)
		cliprect->bottom = dst_buf_prop->buf_height -1;

	src_frame_prop->offset = vm_graphic_get_frame_offset(source_surface, frame_index);

	src_frame_prop->flag = source_surface[src_frame_prop->offset];
	src_frame_prop->left = source_surface[src_frame_prop->offset+1] + (source_surface[src_frame_prop->offset+2]<<8); 
	src_frame_prop->top = source_surface[src_frame_prop->offset+3] + (source_surface[src_frame_prop->offset+4]<<8); 
	src_frame_prop->width = source_surface[src_frame_prop->offset+5] + (source_surface[src_frame_prop->offset+6]<<8); 
	src_frame_prop->height = source_surface[src_frame_prop->offset+7] + (source_surface[src_frame_prop->offset+8]<<8);
	src_frame_prop->is_resize = source_surface[src_frame_prop->offset+14];
	src_frame_prop->size = (VMINT)(source_surface[src_frame_prop->offset+16]
								+ (source_surface[src_frame_prop->offset+17]<<8)
								+ (source_surface[src_frame_prop->offset+18]<<16)
								+ (source_surface[src_frame_prop->offset+19]<<24));  
	if (src_frame_prop->cf == VM_GRAPHIC_COLOR_FORMAT_16)
	{
		src_frame_prop->trans_color_565 = source_surface[src_frame_prop->offset + 12] + (source_surface[src_frame_prop->offset + 13] << 8); 
		src_frame_prop->trans_color_argb.a = 255;
		src_frame_prop->trans_color_argb.r = VM_COLOR_GET_RED(src_frame_prop->trans_color_565);
		src_frame_prop->trans_color_argb.g = VM_COLOR_GET_GREEN(src_frame_prop->trans_color_565);
		src_frame_prop->trans_color_argb.b = VM_COLOR_GET_BLUE(src_frame_prop->trans_color_565);
	}
	else
	{
		src_frame_prop->trans_color_565 = 0;
		src_frame_prop->trans_color_argb.a = 255;
		src_frame_prop->trans_color_argb.r = source_surface[src_frame_prop->offset + 13];
		src_frame_prop->trans_color_argb.g = source_surface[src_frame_prop->offset + 12];
		src_frame_prop->trans_color_argb.b = source_surface[src_frame_prop->offset + 11];
	}

	return TRUE;
}

static VMINT _vm_graphic_get_gdi_layer_handle(VMUINT8 *buf, gdi_handle *p_handle)
{
    int layer_hdl = 0;

    for(layer_hdl = 0; layer_hdl < MAX_LAYER; layer_hdl++)
    {
        if (layer_trans_tbl[layer_hdl].buffer == buf)
        {
            *p_handle = vm_graphic_get_trans_handle(layer_hdl);
            return 1;
        }
    }

    return 0;
}

static void _vm_graphic_blt(
                    VMBYTE *buf,
                    VMINT x_dest,
                    VMINT y_dest,
                    VMBYTE *source_surface,
                    VMINT x_src,
                    VMINT y_src,
                    VMINT width,
                    VMINT height,
                    VMINT frame_index,
                    VMINT alpha)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT i, j;
	VMBYTE	src_cf, dst_cf;	
	gdi_color_format src_color_format, dst_color_format;
	gdi_handle src_layer_handle, dst_layer_handle;	
	gdi_handle flatten_handles[2];
	VMINT	dst_is_canvas = 0;
	VMINT16 frame_width, frame_height;
	VMINT	frame_offset;
	VMINT	frame_left, frame_top;
	VMBYTE	frame_flag;
	VMBYTE  frame_resized;
	VMINT   frame_datasize;
	vm_graphic_color_argb trans_color_argb;
	VMINT	buf_x, buf_y;	
	VMINT	buf_width, buf_height;	
	VMINT   ret;	
	clip_rect cliprect;
	gdi_handle cur_active_layer;
	VMUINT8*	buf_ex;
	BOOL dst_trans_color_enable;
	gdi_color dst_trans_color;
	struct _buf_prop dst_buf_prop;
	struct _frame_prop src_frame_prop;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if ( FALSE == vm_graphic_buf_operation_setup(buf, source_surface, frame_index,
				&cliprect,
				&dst_buf_prop, &src_frame_prop) )
	return;

	dst_cf = dst_buf_prop.cf;
	dst_is_canvas = dst_buf_prop.dst_is_canvas;
	buf_x = dst_buf_prop.buf_x;
	buf_y = dst_buf_prop.buf_y;
	buf_width = dst_buf_prop.buf_width;
	buf_height = dst_buf_prop.buf_height;
	buf_ex = dst_buf_prop.buf_ex;

	src_cf = src_frame_prop.cf;
	frame_offset = src_frame_prop.offset;
	frame_flag = src_frame_prop.flag;
	frame_resized = src_frame_prop.is_resize;
	frame_left = src_frame_prop.left;
	frame_top = src_frame_prop.top;
	frame_width = src_frame_prop.width;
	frame_height = src_frame_prop.height;
	frame_datasize = src_frame_prop.size;
	trans_color_argb = src_frame_prop.trans_color_argb;
		

  	if(x_src<0 || y_src<0 || x_dest<0 || y_dest<0 )
    {
        if(x_dest<0)
        {
            if((x_dest +width)<0)
                return ;
        }
  
        if(y_dest<0)
        {
            if((y_dest +height)<0)
                return ;
        }
  
        if(x_src <0)
        {
            if((x_src +width)<0)
                return ;
  
            x_src   = x_src*(-1); 
            x_dest += x_src;
            x_src   = 0;
            if(x_dest >buf_width -1 )
                return ;
        }		
  
        if(y_src <0)
        {
            if((y_src +height)<0)
                return ;
  
            y_src   = y_src*(-1); 
            y_dest += y_src;
            y_src   = 0;
            if(y_dest >buf_height-1 )
                return ;
        }
    }
  
    if (frame_resized == 0)
    {
        x_dest += frame_left;
        y_dest += frame_top;
    }
    
    if(x_dest < cliprect.left)
    {	
        width -= cliprect.left - x_dest;
        x_src += cliprect.left - x_dest;
        x_dest = cliprect.left;
    }
    if(y_dest < cliprect.top)
    {	
        height -= cliprect.top - y_dest;
        y_src += cliprect.top - y_dest;
        y_dest = cliprect.top;
    }
    if((x_dest + width - 1) > cliprect.right)
        width -= (x_dest + width - 1 - cliprect.right);
    if((y_dest + height - 1) > cliprect.bottom)
        height -= (y_dest + height - 1 - cliprect.bottom);
		
    if (y_src + height > frame_height)
        height = frame_height - y_src;
    if (x_src + width > frame_width)
        width = frame_width - x_src;

    if ( width <=0 || height <= 0)
        return;

	if ( src_cf == VM_GRAPHIC_COLOR_FORMAT_16 && dst_cf == VM_GRAPHIC_COLOR_FORMAT_16 ) 
	{
		VMUINT16 *buf_temp;
		VMUINT16 trans_color;
		VMUINT16 cur_color;
		
		buf_temp = (VMUINT16 *)buf_ex;

		if ( alpha >= 0 && alpha <= 255 )
		{
			switch(frame_flag) {		
			case 0: 
				{
					for (j=0;j<height;j++)
					{
						for (i=0;i<width;i++)
						{
							cur_color = *(source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE + ((y_src + j) * frame_width + x_src + i) * 2) 
								+ (*(source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE + ((y_src + j) * frame_width + x_src + i) * 2 + 1) << 8);
							buf_temp[(y_dest + j) * buf_width + (x_dest + i)] = blend565(buf_temp[(y_dest + j) * buf_width + (x_dest + i)], cur_color, alpha);
						}
					}			
				}
				break;
			case 1: 	
				{			
					trans_color = source_surface[frame_offset + 12] + (source_surface[frame_offset + 13] << 8); 
					for (j=0;j<height;j++)
					{
						for (i=0;i<width;i++)
						{
							cur_color = *(source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE + ((y_src + j) * frame_width + x_src + i) * 2) 
								+ (*(source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE + ((y_src + j) * frame_width + x_src + i) * 2 + 1) << 8);
							if (cur_color != trans_color)						
							{
								buf_temp[(y_dest + j) * buf_width + (x_dest + i)] = blend565(buf_temp[(y_dest + j) * buf_width + (x_dest + i)], cur_color, alpha);
							}
						}
					}					
				}	
				break;
			default:
				break;
			}
		}
		else
		{				
			switch(frame_flag) {		
			case 0: 
				{
					for (j=0;j<height;j++)
					{
						if (width > 0)
							memcpy(buf_ex + ((y_dest + j) * buf_width + x_dest)* 2, 
							source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE + (x_src +(y_src + j) * frame_width) * 2, width * 2);
					}			
				}
				break;
			case 1: 	
				{	
					VMUINT16 *pSrc;
					VMUINT16 *pDst;
					VMINT src_line_bytes = frame_width - width;
					VMINT dst_line_bytes = buf_width - width;
			
					trans_color = source_surface[frame_offset + 12] + (source_surface[frame_offset + 13] << 8); 
					pSrc = (VMUINT16 *)(source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE + (y_src	* frame_width + x_src)* 2);
					pDst = &buf_temp[y_dest * buf_width + x_dest];
					for (j=0;j<height;j++)
					{
						for (i=0;i<width;i++)
						{
							cur_color = *pSrc;
							if (cur_color != trans_color)						
								{
									*pDst = cur_color;
								}
				
								pSrc ++;
								pDst ++;
							}
							pSrc += src_line_bytes;
							pDst += dst_line_bytes;
						}			
					}	
					break;
				default:
					break;
			}
		}
	}
	else
	{
		convert_to_gdi_color_format(src_cf, &src_color_format);
		ret = gdi_layer_create_cf_using_outside_memory(src_color_format, 
					(buf_x + x_dest) - x_src, (buf_y + y_dest) - y_src, frame_width, frame_height, 
					&src_layer_handle, 
					source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE, 
					frame_datasize);	
		if (ret == GDI_FAILED)
		{
			MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMDDRAW_BLT_CREATE_SRC_LAYER_FAIL );
			return;
		}
		
		if ( frame_flag || ( alpha >= 0 && alpha <= 255 ) )
		{
			gdi_layer_push_and_set_active(src_layer_handle);		
			if (frame_flag)
				gdi_layer_set_source_key(TRUE, gdi_act_color_from_rgb(trans_color_argb.a, trans_color_argb.r, trans_color_argb.g, trans_color_argb.b));
			if ( alpha >= 0 && alpha <= 255 )
				gdi_layer_set_opacity(TRUE, (VMUINT8)alpha);
			gdi_layer_pop_and_restore_active();
		}

		if (dst_is_canvas)
		{
			convert_to_gdi_color_format(dst_cf, &dst_color_format);
			ret = gdi_layer_create_cf_using_outside_memory(dst_color_format, 
						buf_x, buf_y, buf_width, buf_height, 
						&dst_layer_handle, 
						buf + VM_CANVAS_SIGNATURE_SIZE + VM_CANVAS_FRAME_PROPERTY_SIZE, 
						get_canvas_prop(buf, VM_CANVAS_DATASIZE));
			if (ret == GDI_FAILED)
			{
				gdi_layer_free(src_layer_handle);
				MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMDDRAW_BLT_CREATE_DST_LAYER_FAIL );
				return;
			}			
		}
		else
		{					
			if (!_vm_graphic_get_gdi_layer_handle(buf, &dst_layer_handle))
			{		
				gdi_layer_free(src_layer_handle);
				MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMDDRAW_BLT_FIND_DST_LAYER_FAIL );
				return;
			}
		}

		flatten_handles[0] = dst_layer_handle;
		flatten_handles[1] = src_layer_handle;

		gdi_layer_get_active(&cur_active_layer);
		if (dst_layer_handle != cur_active_layer)
		{
	        gdi_layer_push_and_set_active(dst_layer_handle);	
		}
		gdi_layer_push_and_set_clip( x_dest, y_dest, x_dest + width - 1, y_dest + height - 1);
		gdi_layer_get_source_key(&dst_trans_color_enable, &dst_trans_color);
		gdi_layer_set_source_key(FALSE, 0);	
		ret = gdi_layer_flatten_with_clipping_ext(flatten_handles[0],	flatten_handles[1], 0, 0, 0, 0);
		gdi_layer_set_source_key(dst_trans_color_enable, dst_trans_color);
		gdi_layer_pop_clip();
		if (dst_layer_handle != cur_active_layer)
		{
	        gdi_layer_pop_and_restore_active();
		}

		if (ret == GDI_FAILED)
			MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMDDRAW_BLT_FLATTEN_LAYER_FAIL );	  

		gdi_layer_free(src_layer_handle);
		if(dst_is_canvas)
		{
			gdi_layer_free(dst_layer_handle);
		}
  	}		
}

/*****************************************************************************
* FUNCTION
*  vm_graphic_blt
* DESCRIPTION
*  
* PARAMETERS
*  buf                 [?]         
*  x_dest              [IN]        
*  y_dest              [IN]        
*  source_surface      [?]         
*  x_src               [IN]        
*  y_src               [IN]        
*  width               [IN]        
*  height              [IN]        
*  frame_index         [IN]        
* RETURNS
*  void
*****************************************************************************/

void vm_graphic_blt(
                    VMBYTE *buf,
                    VMINT x_dest,
                    VMINT y_dest,
                    VMBYTE *source_surface,
                    VMINT x_src,
                    VMINT y_src,
                    VMINT width,
                    VMINT height,
                    VMINT frame_index)
{
	_vm_graphic_blt(buf, x_dest, y_dest, source_surface, x_src, y_src, width, height, frame_index, -1);
}

/*****************************************************************************
* FUNCTION
*  vm_graphic_blt_ex
* DESCRIPTION
*  
* PARAMETERS
*  buf                 [?]         
*  x_dest              [IN]        
*  y_dest              [IN]        
*  source_surface      [?]         
*  x_src               [IN]        
*  y_src               [IN]        
*  width               [IN]        
*  height              [IN]        
*  frame_index         [IN]        
*  alpha               [IN]        
* RETURNS
*  void 
*****************************************************************************/
void vm_graphic_blt_ex(
                       VMBYTE *buf,
                       VMINT x_dest,
                       VMINT y_dest,
                       VMBYTE *source_surface,
                       VMINT x_src,
                       VMINT y_src,
                       VMINT width,
                       VMINT height,
                       VMINT frame_index,
                       VMINT alpha)
{
    if (alpha < 0)
        alpha = 0;
    if (alpha > 255)
        alpha = 255;

    _vm_graphic_blt(buf, x_dest, y_dest, source_surface, x_src, y_src, width, height, frame_index, alpha);

}


static VMINT vm_graphic_set_buf_environment(VMUINT8 *buf, vm_graphic_cb **p_current_cb,
                                     VMUINT* gdi_layer_handle, VMINT* bIsCanvas,
                                     VMINT* buf_x, VMINT* buf_y,
                                     VMINT* buf_width, VMINT* buf_height)
{
    VMINT ret = VM_GDI_FAILED;	

	if ( vm_graphic_check_module_state() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return VM_GRAPHIC_INT_CHECK_MODULE_FAIL;

	*p_current_cb = vm_graphic_get_current_cb();
	if (*p_current_cb == NULL)
		return VM_GRAPHIC_INT_GET_CUR_CB_FAIL;	

    ret = vm_graphic_get_handle_from_buf(buf,gdi_layer_handle,bIsCanvas,buf_x,buf_y,buf_width,buf_height);
    if(VM_GDI_FAILED == ret)
        return VM_GRAPHIC_INT_GET_HANDLE_FAIL;

	gdi_layer_push_and_set_active(*gdi_layer_handle);	
	gdi_layer_push_clip(); 
	gdi_layer_set_clip( (*p_current_cb)->cliprect.left,(*p_current_cb)->cliprect.top,(*p_current_cb)->cliprect.right,(*p_current_cb)->cliprect.bottom);
	
	return VM_GRAPHIC_INT_NO_ERROR;
}

static void vm_graphic_restore_buf_environment(VMUINT gdi_layer_handle, VMINT bIsCanvas)
{
	gdi_layer_pop_clip();
	gdi_layer_pop_and_restore_active();
	
    if(bIsCanvas)
    {
        gdi_layer_free(gdi_layer_handle);
    }
}

/*****************************************************************************
* FUNCTION
*  vm_graphic_set_pixel
* DESCRIPTION
*  
* PARAMETERS
*  buf         [?]         
*  x           [IN]        
*  y           [IN]        
*  color       [IN]        
* RETURNS
*  void
*****************************************************************************/

static void _vm_graphic_set_pixel(VMUINT8 *buf, VMINT x, VMINT y, VMUINT16 color_rgb565, vm_graphic_color_argb* p_color_argb)
{
    VMUINT gdi_layer_handle = 0;
    VMINT bIsCanvas = 0;	
    VMINT buf_x = 0;
    VMINT buf_y = 0;
    VMINT buf_width = 0;
    VMINT buf_height = 0;
    VMINT ret;	
	vm_graphic_cb *current_cb;
	gdi_color color;

    if( x<0 || y<0 )
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMDDRAW, TRC_MRE_VMDDRAW_1038 );
        return;
    }		

	ret = vm_graphic_set_buf_environment(buf,&current_cb,
				&gdi_layer_handle,&bIsCanvas,
				&buf_x,&buf_y,
				&buf_width,&buf_height);	
    if( ret != VM_GRAPHIC_INT_NO_ERROR )
        return;

    if(x < buf_x || y<buf_y || x> buf_x+buf_width || y>buf_y+buf_height)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMDDRAW, TRC_MRE_VMDDRAW_1047 );
    }
    else
    {
    	if (p_color_argb == NULL)
			color = GDI_ACT_COLOR_FROM_RGB(color_rgb565);
		else
			color = gdi_act_color_from_rgb(p_color_argb->a, p_color_argb->r, p_color_argb->g, p_color_argb->b);
		
        gdi_draw_point(x,y,color);
    }

	vm_graphic_restore_buf_environment(gdi_layer_handle, bIsCanvas);
}

void vm_graphic_set_pixel(VMUINT8 *buf, VMINT x, VMINT y, VMUINT16 color)
{
	_vm_graphic_set_pixel(buf, x, y, color, NULL);
}

void vm_graphic_set_pixel_cf(VMUINT8 *buf, VMINT x, VMINT y, vm_graphic_color_argb* color)
{
	if (!color)
		return;

	_vm_graphic_set_pixel(buf, x, y, 0, color);
}


static VMINT vm_graphic_get_handle_from_buf(VMUINT8 *buf,VMUINT* gdi_layer_handle,VMINT* bIsCanvas,VMINT* buf_x, VMINT* buf_y,
                                     VMINT* buf_width,VMINT* buf_height)
{

    if(buf == NULL || gdi_layer_handle == NULL || bIsCanvas == NULL ||buf_x == NULL|| buf_x== NULL||buf_width== NULL||buf_height==NULL)
    {
        return VM_GDI_FAILED;
    }

    if (memcmp(buf, MTK_CAN_MAGIC, 6) == 0)
    {

        VMUINT8*	buf_ex = NULL;
		vm_graphic_color_famat cf;
		gdi_color_format color_format;
		VMINT	buf_datasize;
        *bIsCanvas = 1;
        *buf_width = buf[VM_CANVAS_SIGNATURE_SIZE + 6] *256 + buf[VM_CANVAS_SIGNATURE_SIZE + 5]; 
        *buf_height = buf[VM_CANVAS_SIGNATURE_SIZE + 8] *256 + buf[VM_CANVAS_SIGNATURE_SIZE + 7]; 
        *buf_x = buf[VM_CANVAS_SIGNATURE_SIZE+2] *256 + buf[VM_CANVAS_SIGNATURE_SIZE+1]; 
        *buf_y = (buf[VM_CANVAS_SIGNATURE_SIZE+4] * 256 + buf[VM_CANVAS_SIGNATURE_SIZE+3]); 

		cf = buf[VM_CANVAS_FRAME_NUM_OFFSET + 2];
		if ( convert_to_gdi_color_format(cf, &color_format) != VM_GDI_SUCCEED )
			return VM_GDI_FAILED;
		
		buf_datasize = (VMINT)(buf[VM_CANVAS_SIGNATURE_SIZE+16]
								+ (buf[VM_CANVAS_SIGNATURE_SIZE+17]<<8)
								+ (buf[VM_CANVAS_SIGNATURE_SIZE+18]<<16)
								+ (buf[VM_CANVAS_SIGNATURE_SIZE+19]<<24));  

        buf_ex = buf + VM_CANVAS_SIGNATURE_SIZE + VM_CANVAS_FRAME_PROPERTY_SIZE;
        if (gdi_layer_create_cf_using_outside_memory(color_format, 0, 0, *buf_width, *buf_height, gdi_layer_handle, buf_ex, buf_datasize)!= 0)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMDDRAW, TRC_MRE_VMDDRAW_1104 );
            return VM_GDI_FAILED;
        } 
    }
    else
    {
		if (!_vm_graphic_get_gdi_layer_handle(buf, gdi_layer_handle))			
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMDDRAW, TRC_MRE_VMDDRAW_1123 );
            return VM_GDI_FAILED;
        }

        *bIsCanvas = 0;
        gdi_layer_push_and_set_active(*gdi_layer_handle);
        gdi_layer_get_position(buf_x,buf_y);
        gdi_layer_get_dimension(buf_width,buf_height);
        gdi_layer_pop_and_restore_active();

    }
	
    MMI_TRACE(MMI_MRE_TRC_MOD_VMDDRAW, TRC_MRE_VMDDRAW_1134 ,*gdi_layer_handle,*bIsCanvas,*buf_x,*buf_y,*buf_width,*buf_height);

	return VM_GDI_SUCCEED;
}

/*****************************************************************************
* FUNCTION
*  vm_graphic_line
* DESCRIPTION
*  
* PARAMETERS
*  buf         [?]         
*  x0          [IN]        
*  y0          [IN]        
*  x1          [IN]        
*  y1          [IN]        
*  color       [IN]        
* RETURNS
*  void
*****************************************************************************/
static void _vm_graphic_line(VMUINT8 *buf, VMINT x0, VMINT y0, VMINT x1, VMINT y1, VMUINT16 color_rgb565, vm_graphic_color_argb* p_color_argb)
{
    VMUINT gdi_layer_handle = 0;
    VMINT bIsCanvas = 0;	
    VMINT buf_x = 0;
    VMINT buf_y = 0;
    VMINT buf_width = 0;
    VMINT buf_height = 0;
    VMINT ret;	
	vm_graphic_cb *current_cb;
	gdi_color color;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMDDRAW, TRC_MRE_VMDDRAW_1168 ,x0,y0,x1,y1);

    if( x0<0 || y0<0 || x1>LCD_WIDTH || y1>LCD_HEIGHT )
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMDDRAW, TRC_MRE_VMDDRAW_1176 );
        return;
    }

	ret = vm_graphic_set_buf_environment(buf,&current_cb,
				&gdi_layer_handle,&bIsCanvas,
				&buf_x,&buf_y,
				&buf_width,&buf_height);	
    if( ret != VM_GRAPHIC_INT_NO_ERROR )
        return;

    if( x1-x0 > buf_width || y1-y0 > buf_height )
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMDDRAW, TRC_MRE_VMDDRAW_1186 );
    }
    else
    {
    	if (p_color_argb == NULL)
			color = GDI_ACT_COLOR_FROM_RGB(color_rgb565);
		else
			color = gdi_act_color_from_rgb(p_color_argb->a, p_color_argb->r, p_color_argb->g, p_color_argb->b);

        gdi_draw_line(x0, y0, x1, y1, color);
    }

	vm_graphic_restore_buf_environment(gdi_layer_handle, bIsCanvas);
}

void vm_graphic_line(VMUINT8 *buf, VMINT x0, VMINT y0, VMINT x1, VMINT y1, VMUINT16 color)
{
	_vm_graphic_line(buf, x0, y0, x1, y1, color, NULL);
}

void vm_graphic_line_cf(VMUINT8 *buf, VMINT x0, VMINT y0, VMINT x1, VMINT y1, vm_graphic_color_argb* color)
{
	if (!color)
		return;

	_vm_graphic_line(buf, x0, y0, x1, y1, 0, color);
}


/*****************************************************************************
* FUNCTION
*  vm_graphic_rect
* DESCRIPTION
*  
* PARAMETERS
*  buf         [?]         
*  x           [IN]        
*  y           [IN]        
*  width       [IN]        
*  height      [IN]        
*  color       [IN]        
* RETURNS
*  void
*****************************************************************************/
static void _vm_graphic_rect(VMUINT8 *buf, VMINT x, VMINT y, VMINT width, VMINT height, VMUINT16 color_rgb565, vm_graphic_color_argb* p_color_argb)
{
    VMUINT gdi_layer_handle = 0;
    VMINT bIsCanvas = 0;	
    VMINT buf_x = 0;
    VMINT buf_y = 0;
    VMINT buf_width = 0;
    VMINT buf_height = 0;
    VMINT ret;	
	vm_graphic_cb *current_cb;
	gdi_color color;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMDDRAW, TRC_MRE_VMDDRAW_1236 ,x,y,width,height,color_rgb565);

    if(x<0||y<0||width>LCD_WIDTH || height>LCD_HEIGHT  )
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMDDRAW, TRC_MRE_VMDDRAW_1244 );
        return;
    }			

	ret = vm_graphic_set_buf_environment(buf,&current_cb,
				&gdi_layer_handle,&bIsCanvas,
				&buf_x,&buf_y,
				&buf_width,&buf_height);	
    if( ret != VM_GRAPHIC_INT_NO_ERROR )
        return;

    if(width >buf_width ||height>buf_height)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMDDRAW, TRC_MRE_VMDDRAW_1253 );
    }
    else
    {
    	if (p_color_argb == NULL)
			color = GDI_ACT_COLOR_FROM_RGB(color_rgb565);
		else
			color = gdi_act_color_from_rgb(p_color_argb->a, p_color_argb->r, p_color_argb->g, p_color_argb->b);

        gdi_draw_rect(x,y,x+width-1,y+height-1,color);
    }

	vm_graphic_restore_buf_environment(gdi_layer_handle, bIsCanvas);
}

void vm_graphic_rect(VMUINT8 *buf, VMINT x, VMINT y, VMINT width, VMINT height, VMUINT16 color)
{
	_vm_graphic_rect(buf, x, y, width, height, color, NULL);
}

void vm_graphic_rect_cf(VMUINT8 *buf, VMINT x, VMINT y, VMINT width, VMINT height, vm_graphic_color_argb* color)
{
	if (!color)
		return;

	_vm_graphic_rect(buf, x, y, width, height, 0, color);
}


/*****************************************************************************
* FUNCTION
*  vm_graphic_fill_rect
* DESCRIPTION
*  
* PARAMETERS
*  buf             [?]         
*  x               [IN]        
*  y               [IN]        
*  width           [IN]        
*  height          [IN]        
*  line_color      [IN]        
*  back_color      [IN]        
* RETURNS
*  void
*****************************************************************************/
static void _vm_graphic_fill_rect(VMUINT8 *buf,VMINT x,VMINT y,VMINT width,VMINT height,
							VMUINT16 line_color_rgb565, vm_graphic_color_argb* p_line_color_argb,
							VMUINT16 back_color_rgb565, vm_graphic_color_argb* p_back_color_argb)
{
    VMUINT gdi_layer_handle = 0;
    VMINT bIsCanvas = 0;	
    VMINT buf_x = 0;
    VMINT buf_y = 0;
    VMINT buf_width = 0;
    VMINT buf_height = 0;
    VMINT ret;
	vm_graphic_cb *current_cb;
	gdi_color back_color;
	gdi_color line_color;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMDDRAW, TRC_MRE_VMDDRAW_1305 ,x,y,width,height,line_color_rgb565,back_color_rgb565);

    if(x<0||y<0||width>LCD_WIDTH || height>LCD_HEIGHT  )
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMDDRAW, TRC_MRE_VMDDRAW_1313 );
        return;
    }			

	ret = vm_graphic_set_buf_environment(buf,&current_cb,
				&gdi_layer_handle,&bIsCanvas,
				&buf_x,&buf_y,
				&buf_width,&buf_height);	
    if( ret != VM_GRAPHIC_INT_NO_ERROR )
        return;

    if(width >buf_width ||height>buf_height)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMDDRAW, TRC_MRE_VMDDRAW_1322 );
    }
    else
    {        
    	if (p_line_color_argb == NULL)
			line_color = GDI_ACT_COLOR_FROM_RGB(line_color_rgb565);
		else
			line_color = gdi_act_color_from_rgb(p_line_color_argb->a, p_line_color_argb->r, p_line_color_argb->g, p_line_color_argb->b);

    	if (p_back_color_argb == NULL)
			back_color = GDI_ACT_COLOR_FROM_RGB(back_color_rgb565);
		else
			back_color = gdi_act_color_from_rgb(p_back_color_argb->a, p_back_color_argb->r, p_back_color_argb->g, p_back_color_argb->b);

        gdi_draw_solid_rect(x, y, x+width-1,y+height-1,back_color);
        gdi_draw_rect(x,y,x+width-1,y+height-1,line_color);
    }

	vm_graphic_restore_buf_environment(gdi_layer_handle, bIsCanvas);
}

void vm_graphic_fill_rect(VMUINT8 *buf,VMINT x,VMINT y,VMINT width,VMINT height,VMUINT16 line_color,VMUINT16 back_color)
{
	_vm_graphic_fill_rect(buf, x, y, width, height, line_color, NULL, back_color, NULL);
}

void vm_graphic_fill_rect_cf(VMUINT8 *buf,VMINT x,VMINT y,VMINT width,VMINT height,vm_graphic_color_argb* line_color,vm_graphic_color_argb* back_color)
{
	if (!line_color)
		return;
	if (!back_color)
		return;

	_vm_graphic_fill_rect(buf, x, y, width, height, 0, line_color, 0, back_color);
}


/*****************************************************************************
* FUNCTION
*  vm_graphic_get_pixel
* DESCRIPTION
*  
* PARAMETERS
*  buf     [?]         
*  x       [IN]        
*  y       [IN]        
* RETURNS
*  
*****************************************************************************/
static gdi_color _vm_graphic_get_pixel(VMUINT8 *buf, VMINT x, VMINT y)
{
    VMUINT gdi_layer_handle = 0;
    VMINT bIsCanvas = 0;	
    VMINT buf_x = 0;
    VMINT buf_y = 0;
    VMINT buf_width = 0;
    VMINT buf_height = 0;
    VMINT ret;
    gdi_color pixel = 0;	
	vm_graphic_cb *current_cb;
	
    MMI_TRACE(MMI_MRE_TRC_MOD_VMDDRAW, TRC_MRE_VMDDRAW_1369 , x, y);

    if( x<0 || y<0 )
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMDDRAW, TRC_MRE_VMDDRAW_1373 );
        return pixel;
    }		
	
	ret = vm_graphic_set_buf_environment(buf,&current_cb,
				&gdi_layer_handle,&bIsCanvas,
				&buf_x,&buf_y,
				&buf_width,&buf_height);	
    if( ret != VM_GRAPHIC_INT_NO_ERROR )
        return pixel;

    if(x < buf_x || y<buf_y || x> buf_x+buf_width || y>buf_y+buf_height)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMDDRAW, TRC_MRE_VMDDRAW_1382 );
    }
    else
    {
        pixel = gdi_act_get_pixel(x,y);
    }
	
	vm_graphic_restore_buf_environment(gdi_layer_handle, bIsCanvas);

    return pixel;
}

VMUINT16 vm_graphic_get_pixel(VMUINT8 *buf, VMINT x, VMINT y)
{
	VMUINT16 pixel;

	pixel = (VMUINT16)_vm_graphic_get_pixel(buf, x, y);

	return pixel;
}

vm_graphic_color_argb vm_graphic_get_pixel_cf(VMUINT8 *buf, VMINT x, VMINT y)
{
	vm_graphic_color_argb pixel_argb;
	gdi_color pixel;

	pixel = _vm_graphic_get_pixel(buf, x, y);
	
	pixel_argb.a = (VMUINT8)(pixel & 0xFF);
	pixel_argb.r = (VMUINT8)((pixel & 0xFF00) >> 8);
	pixel_argb.g = (VMUINT8)((pixel & 0xFF0000) >> 16);
	pixel_argb.b = (VMUINT8)((pixel & 0xFF000000) >> 24);

	return pixel_argb;
}


/*****************************************************************************
* FUNCTION
*  vm_graphic_rotate
* DESCRIPTION
*  
* PARAMETERS
*  des_buf             [?]         
*  x_des               [IN]        
*  y_des               [IN]        
*  source_surface      [?]         
*  frame_index         [IN]        
*  Degrees             [IN]        
* RETURNS
*  void
*****************************************************************************/
void vm_graphic_rotate(
                       VMBYTE *des_buf,
                       VMINT x_des,
                       VMINT y_des,
                       VMBYTE *source_surface,
                       VMINT frame_index,
                       VMINT Degrees)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMBYTE *buf = des_buf;
	VMBYTE	src_cf, dst_cf;	
	gdi_color_format src_color_format, dst_color_format;	
	gdi_handle src_layer_handle, dst_layer_handle;		
	gdi_handle flatten_handles[2];
	VMINT	dst_is_canvas = 0;
    VMINT16 frame_width;
    VMINT16 frame_height;
    VMINT	frame_offset;
    VMBYTE	frame_flag;
	VMINT   frame_datasize;
	vm_graphic_color_argb trans_color_argb;
    VMINT	buf_width;
    VMINT	buf_height;
    VMINT	buf_x;
    VMINT	buf_y;	
    VMINT ret;
    clip_rect cliprect;
	gdi_handle cur_active_layer;
	struct _buf_prop dst_buf_prop;
	struct _frame_prop src_frame_prop;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if ( FALSE == vm_graphic_buf_operation_setup(des_buf, source_surface, frame_index,
				&cliprect, 
				&dst_buf_prop, &src_frame_prop) )
		return;

	dst_cf = dst_buf_prop.cf;
	dst_is_canvas = dst_buf_prop.dst_is_canvas;
	buf_x = dst_buf_prop.buf_x;
	buf_y = dst_buf_prop.buf_y;
	buf_width = dst_buf_prop.buf_width;
	buf_height = dst_buf_prop.buf_height;

	src_cf = src_frame_prop.cf;
	frame_offset = src_frame_prop.offset;
	frame_flag = src_frame_prop.flag;
	frame_width = src_frame_prop.width;
	frame_height = src_frame_prop.height;
	frame_datasize = src_frame_prop.size;
	trans_color_argb = src_frame_prop.trans_color_argb;
	
		
	convert_to_gdi_color_format(src_cf, &src_color_format);
	ret = gdi_layer_create_cf_using_outside_memory(src_color_format, 
						0, 0, frame_width, frame_height, 
						&src_layer_handle, 
						source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE, 
						frame_datasize);	
	if (ret == GDI_FAILED)
	{
		MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMDDRAW_ROTATE_CREATE_SRC_LAYER_FAIL );	  
		return;
	}

	gdi_layer_push_and_set_active(src_layer_handle);	
	
	if ( Degrees == VM_ROTATE_DEGREE_90 )
	{
		gdi_layer_set_rotate(GDI_LAYER_ROTATE_90);
		gdi_layer_set_position(buf_y + y_des, buf_width - (buf_x + x_des + frame_height));
		
		if (cliprect.left < x_des)
			cliprect.left = x_des;
		if (cliprect.top < y_des)
			cliprect.top = y_des;
		if (cliprect.right >= x_des + frame_height - 1)
			cliprect.right = x_des + frame_height - 1;
		if (cliprect.bottom >= y_des + frame_width - 1)
			cliprect.bottom = y_des + frame_width - 1;
	}	
	else if ( Degrees == VM_ROTATE_DEGREE_180 )			
	{
		gdi_layer_set_rotate(GDI_LAYER_ROTATE_180);
		gdi_layer_set_position(buf_width - (buf_x + x_des + frame_width), buf_height- (buf_y + y_des + frame_height));

		if (cliprect.left < x_des)
			cliprect.left = x_des;
		if (cliprect.top < y_des)
			cliprect.top = y_des;
		if (cliprect.right >= x_des + frame_width - 1)
			cliprect.right = x_des + frame_width - 1;
		if (cliprect.bottom >= y_des + frame_height - 1)
			cliprect.bottom = y_des + frame_height - 1;
	}
	else if ( Degrees == VM_ROTATE_DEGREE_270 )
	{
		gdi_layer_set_rotate(GDI_LAYER_ROTATE_270);			
		gdi_layer_set_position(buf_height - (buf_y + y_des + frame_width), buf_x + x_des);

		if (cliprect.left < x_des)
			cliprect.left = x_des;
		if (cliprect.top < y_des)
			cliprect.top = y_des;
		if (cliprect.right >= x_des + frame_height - 1)
			cliprect.right = x_des + frame_height - 1;
		if (cliprect.bottom >= y_des + frame_width - 1)
			cliprect.bottom = y_des + frame_width - 1;
	}
	else
	{}

	if ( frame_flag )
		gdi_layer_set_source_key(TRUE, gdi_act_color_from_rgb(trans_color_argb.a, trans_color_argb.r, trans_color_argb.g, trans_color_argb.b));
	
	gdi_layer_pop_and_restore_active();

	if (dst_is_canvas)
	{
		convert_to_gdi_color_format(dst_cf, &dst_color_format);
		ret = gdi_layer_create_cf_using_outside_memory(dst_color_format, 
					buf_x, buf_y, buf_width, buf_height, 
					&dst_layer_handle, 
					buf + VM_CANVAS_SIGNATURE_SIZE + VM_CANVAS_FRAME_PROPERTY_SIZE, 
					get_canvas_prop(buf, VM_CANVAS_DATASIZE));
		
		if (ret == GDI_FAILED)
		{			
			gdi_layer_free(src_layer_handle);
			MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMDDRAW_ROTATE_CREATE_DST_LAYER_FAIL );	  
			return;
		}
	}
	else
	{				
		if (!_vm_graphic_get_gdi_layer_handle(buf, &dst_layer_handle))
		{		
			gdi_layer_free(src_layer_handle);
			MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMDDRAW_ROTATE_FIND_DST_LAYER_FAIL );  				
			return;
		}
	}

	flatten_handles[0] = dst_layer_handle;
	flatten_handles[1] = src_layer_handle;

	gdi_layer_get_active(&cur_active_layer);
	if (dst_layer_handle != cur_active_layer)
	{
        gdi_layer_push_and_set_active(dst_layer_handle);				
        gdi_layer_push_and_set_clip(cliprect.left, cliprect.top, cliprect.right, cliprect.bottom);
		ret = gdi_layer_flatten_with_clipping_ext(flatten_handles[0],	flatten_handles[1], 0, 0, 0, 0);
        gdi_layer_pop_clip();
        gdi_layer_pop_and_restore_active();
	}
	else
	{
        gdi_layer_push_and_set_clip(cliprect.left, cliprect.top, cliprect.right, cliprect.bottom);
        ret = gdi_layer_flatten_with_clipping_ext(flatten_handles[0], flatten_handles[1], 0, 0, 0, 0);
        gdi_layer_pop_clip();
	}

	if (ret == GDI_FAILED)
		MMI_TRACE(MMI_MRE_TRC_WARNING, TRC_MRE_VMDDRAW_ROTATE_FLATTEN_LAYER_FAIL );	 

	gdi_layer_free(src_layer_handle);
	if(dst_is_canvas)
	{
		gdi_layer_free(dst_layer_handle);
	}

}			


/*****************************************************************************
* FUNCTION
*  vm_graphic_mirror
* DESCRIPTION
*  
* PARAMETERS
*  buf                 [?]         
*  x_des               [IN]        
*  y_des               [IN]        
*  source_surface      [?]         
*  frame_index         [IN]        
*  direction           [IN]        
* RETURNS
*  void
*****************************************************************************/
void vm_graphic_mirror(
                       VMBYTE *buf,
                       VMINT x_des,
                       VMINT y_des,
                       VMBYTE *source_surface,
                       VMINT frame_index,
                       VMINT direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT	i,j;
    VMINT16 frame_width = 0;
    VMINT16 frame_height = 0;
    VMINT	frame_offset = 0;
    VMBYTE	frame_flag = 0;
    VMUINT16 *buf_temp;
    VMUINT16 trans_color_565;
    VMUINT16 cur_color_565;
    VMUINT trans_color_888;
    VMUINT cur_color_888;	
    VMINT	buf_width;
    VMUINT8*	buf_ex;
    clip_rect cliprect;
	VMBYTE src_cf, dst_cf;	
	VMBYTE * src_data_ptr;
	VMUINT dst_data_idx;
	struct _buf_prop dst_buf_prop;
	struct _frame_prop src_frame_prop;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if ( FALSE == vm_graphic_buf_operation_setup(buf, source_surface, frame_index,
				&cliprect, 
				&dst_buf_prop, &src_frame_prop) )
		return;

	dst_cf = dst_buf_prop.cf;
	buf_width = dst_buf_prop.buf_width;
	buf_ex = dst_buf_prop.buf_ex;

	src_cf = src_frame_prop.cf;
	frame_offset = src_frame_prop.offset;
	frame_flag = src_frame_prop.flag;
	frame_width = src_frame_prop.width;
	frame_height = src_frame_prop.height;
	trans_color_565 = src_frame_prop.trans_color_565;
		

	if (src_cf != dst_cf)	
	{
        MMI_TRACE(MMI_MRE_TRC_ERROR, TRC_MRE_VMDDRAW_1724 , src_cf, dst_cf);
		return;
	}

    buf_temp = (VMUINT16 *)buf_ex;

    switch(frame_flag) 
    {		
    case 0:	
        {
			if (src_cf == VM_GRAPHIC_COLOR_FORMAT_16)
			{
	            for(j = 0; j < frame_height; j++)
	            {
	                for(i = 0; i < frame_width; i++)
	                {
	                    if(direction==0)	
	                    {
	                        if ((y_des + j >= cliprect.top) && 
	                            (y_des + j <= cliprect.bottom) && 
	                            (x_des + frame_width - i - 1 >= cliprect.left) && 
	                            (x_des + frame_width - i - 1 <= cliprect.right))
	                        {
								src_data_ptr = source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE + (j * frame_width + i) * 2;
								cur_color_565 = *(src_data_ptr) + (*(src_data_ptr + 1) << 8);
	                            buf_temp[(y_des + j) * buf_width + (x_des + frame_width - i - 1)] = cur_color_565;
	                        }
	                    }
	                    else if(direction==1)
	                    {
	                        if ((y_des + frame_height - j - 1 >= cliprect.top) && 
	                            (y_des + frame_height - j - 1 <= cliprect.bottom) && 
	                            (x_des + i >= cliprect.left) && 
	                            (x_des + i <= cliprect.right))
	                        {
								src_data_ptr = source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE + (j * frame_width + i) * 2;
	                            cur_color_565 = *(src_data_ptr) + (*(src_data_ptr + 1) << 8);
	                            buf_temp[(y_des + frame_height - j - 1) * buf_width + (x_des + i)] = cur_color_565;					
	                        }
	                    }
	                }
	            }
	        }
			else if (src_cf == VM_GRAPHIC_COLOR_FORMAT_24)
			{
	            for(j = 0; j < frame_height; j++)
	            {
	                for(i = 0; i < frame_width; i++)
	                {
	                    if(direction==0)	
	                    {
	                        if ((y_des + j >= cliprect.top) && 
	                            (y_des + j <= cliprect.bottom) && 
	                            (x_des + frame_width - i - 1 >= cliprect.left) && 
	                            (x_des + frame_width - i - 1 <= cliprect.right))
	                        {
								src_data_ptr = source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE + (j * frame_width + i) * 3;
								dst_data_idx = ((y_des + j) * buf_width + (x_des + frame_width - i - 1)) * 3;
								buf_ex[dst_data_idx] = *(src_data_ptr);
								buf_ex[dst_data_idx + 1] = *(src_data_ptr + 1);
								buf_ex[dst_data_idx + 2] = *(src_data_ptr + 2);
	                        }
	                    }
	                    else if(direction==1)
	                    {
	                        if ((y_des + frame_height - j - 1 >= cliprect.top) && 
	                            (y_des + frame_height - j - 1 <= cliprect.bottom) && 
	                            (x_des + i >= cliprect.left) && 
	                            (x_des + i <= cliprect.right))
	                        {
								src_data_ptr = source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE + (j * frame_width + i) * 3;
								dst_data_idx = ((y_des + frame_height - j - 1) * buf_width + (x_des + i)) * 3;
								buf_ex[dst_data_idx] = *(src_data_ptr);
								buf_ex[dst_data_idx + 1] = *(src_data_ptr + 1);
								buf_ex[dst_data_idx + 2] = *(src_data_ptr + 2);
	                        }
	                    }
	                }
	            }
	        }
			else if (src_cf == VM_GRAPHIC_COLOR_FORMAT_32 || src_cf == VM_GRAPHIC_COLOR_FORMAT_32_PARGB)
			{
	            for(j = 0; j < frame_height; j++)
	            {
	                for(i = 0; i < frame_width; i++)
	                {
	                    if(direction==0)	
	                    {
	                        if ((y_des + j >= cliprect.top) && 
	                            (y_des + j <= cliprect.bottom) && 
	                            (x_des + frame_width - i - 1 >= cliprect.left) && 
	                            (x_des + frame_width - i - 1 <= cliprect.right))
	                        {
								src_data_ptr = source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE + (j * frame_width + i) * 4;
								dst_data_idx = ((y_des + j) * buf_width + (x_des + frame_width - i - 1)) * 4;
								buf_ex[dst_data_idx] = *(src_data_ptr);
								buf_ex[dst_data_idx + 1] = *(src_data_ptr + 1);
								buf_ex[dst_data_idx + 2] = *(src_data_ptr + 2);
								buf_ex[dst_data_idx + 3] = *(src_data_ptr + 3);
	                        }
	                    }
	                    else if(direction==1)
	                    {
	                        if ((y_des + frame_height - j - 1 >= cliprect.top) && 
	                            (y_des + frame_height - j - 1 <= cliprect.bottom) && 
	                            (x_des + i >= cliprect.left) && 
	                            (x_des + i <= cliprect.right))
	                        {
								src_data_ptr = source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE + (j * frame_width + i) * 4;
								dst_data_idx = ((y_des + frame_height - j - 1) * buf_width + (x_des + i)) * 4;
								buf_ex[dst_data_idx] = *(src_data_ptr);
								buf_ex[dst_data_idx + 1] = *(src_data_ptr + 1);
								buf_ex[dst_data_idx + 2] = *(src_data_ptr + 2);
								buf_ex[dst_data_idx + 3] = *(src_data_ptr + 3);
	                        }
	                    }
	                }
	            }
	        }
			else
			{}
    	}
        break;
    case 1:
        {
			if (src_cf == VM_GRAPHIC_COLOR_FORMAT_16)
			{		
	            trans_color_565 = source_surface[frame_offset + 12] + (source_surface[frame_offset + 13] << 8);	

	            for(j = 0; j < frame_height; j++)
	            {
	                for(i = 0; i < frame_width; i++)
	                {
	                    if(direction==0)
	                    {
	                        if ((y_des + j >= cliprect.top) && 
	                            (y_des + j <= cliprect.bottom) && 
	                            (x_des + frame_width - i - 1 >= cliprect.left) && 
	                            (x_des + frame_width - i - 1 <= cliprect.right))
	                        {                        
								src_data_ptr = source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE + (j * frame_width + i) * 2;
	                            cur_color_565 = *(src_data_ptr) + (*(src_data_ptr + 1) << 8);

	                            if (cur_color_565 != trans_color_565)						
	                            {
	                                buf_temp[(y_des + j) * buf_width + (x_des + frame_width - i - 1)] = cur_color_565;
	                            }
	                        }
	                    }
	                    else if(direction==1)
	                    {
	                        if ((y_des + frame_height - j - 1 >= cliprect.top) && 
	                            (y_des + frame_height - j - 1 <= cliprect.bottom) && 
	                            (x_des + i >= cliprect.left) && 
	                            (x_des + i <= cliprect.right))
	                        {
								src_data_ptr = source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE + (j * frame_width + i) * 2;
	                            cur_color_565 = *(src_data_ptr) + (*(src_data_ptr + 1) << 8);
	                            if (cur_color_565 != trans_color_565)						
	                            {
	                                buf_temp[(y_des + frame_height - j - 1) * buf_width + (x_des + i)] = cur_color_565;
	                            }
	                        }
	                    }
	                }
	            }
	    	}
			else if (src_cf == VM_GRAPHIC_COLOR_FORMAT_24)
			{		
				trans_color_888 = source_surface[frame_offset + 11] + (source_surface[frame_offset + 12] << 8) + (source_surface[frame_offset + 13] << 16); 

	            for(j = 0; j < frame_height; j++)
	            {
	                for(i = 0; i < frame_width; i++)
	                {
	                    if(direction==0)
	                    {
	                        if ((y_des + j >= cliprect.top) && 
	                            (y_des + j <= cliprect.bottom) && 
	                            (x_des + frame_width - i - 1 >= cliprect.left) && 
	                            (x_des + frame_width - i - 1 <= cliprect.right))
	                        {
								src_data_ptr = source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE + (j * frame_width + i) * 3;
								dst_data_idx = ((y_des + j) * buf_width + (x_des + frame_width - i - 1)) * 3;

	                            cur_color_888 = *(src_data_ptr) + (*(src_data_ptr + 1) << 8) + (*(src_data_ptr + 2) << 16);

	                            if (cur_color_888 != trans_color_888)						
	                            {
	                                buf_ex[dst_data_idx] = *(src_data_ptr);
	                                buf_ex[dst_data_idx + 1] = *(src_data_ptr + 1);
	                                buf_ex[dst_data_idx + 2] = *(src_data_ptr + 2);
	                            }
	                        }
	                    }
	                    else if(direction==1)
	                    {
	                        if ((y_des + frame_height - j - 1 >= cliprect.top) && 
	                            (y_des + frame_height - j - 1 <= cliprect.bottom) && 
	                            (x_des + i >= cliprect.left) && 
	                            (x_des + i <= cliprect.right))
	                        {
								src_data_ptr = source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE + (j * frame_width + i) * 3;
								dst_data_idx = ((y_des + frame_height - j - 1) * buf_width + (x_des + i)) * 3;

	                            cur_color_888 = *(src_data_ptr) + (*(src_data_ptr + 1) << 8) + (*(src_data_ptr + 2) << 16);
	                            if (cur_color_888 != trans_color_888)						
	                            {
	                                buf_ex[dst_data_idx] = *(src_data_ptr) ;
									buf_ex[dst_data_idx + 1] = *(src_data_ptr + 1) ;
	                                buf_ex[dst_data_idx + 2] = *(src_data_ptr + 2) ;
	                            }
	                        }
	                    }
	                }
	            }
	    	}
			else if (src_cf == VM_GRAPHIC_COLOR_FORMAT_32 || src_cf == VM_GRAPHIC_COLOR_FORMAT_32_PARGB)
			{		
				trans_color_888 = source_surface[frame_offset + 11] + (source_surface[frame_offset + 12] << 8) + (source_surface[frame_offset + 13] << 16); 

	            for(j = 0; j < frame_height; j++)
	            {
	                for(i = 0; i < frame_width; i++)
	                {
	                    if(direction==0)
	                    {
	                        if ((y_des + j >= cliprect.top) && 
	                            (y_des + j <= cliprect.bottom) && 
	                            (x_des + frame_width - i - 1 >= cliprect.left) && 
	                            (x_des + frame_width - i - 1 <= cliprect.right))
	                        {
								src_data_ptr = source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE + (j * frame_width + i) * 4;
								dst_data_idx = ((y_des + j) * buf_width + (x_des + frame_width - i - 1)) * 4;

	                            cur_color_888 = *(src_data_ptr) + (*(src_data_ptr + 1) << 8) + (*(src_data_ptr + 2) << 16);

	                            if (cur_color_888 != trans_color_888)						
	                            {
	                                buf_ex[dst_data_idx] = *(src_data_ptr);
	                                buf_ex[dst_data_idx + 1] = *(src_data_ptr + 1);
	                                buf_ex[dst_data_idx + 2] = *(src_data_ptr + 2);
	                                buf_ex[dst_data_idx + 3] = *(src_data_ptr + 3);
	                            }
	                        }
	                    }
	                    else if(direction==1)
	                    {
	                        if ((y_des + frame_height - j - 1 >= cliprect.top) && 
	                            (y_des + frame_height - j - 1 <= cliprect.bottom) && 
	                            (x_des + i >= cliprect.left) && 
	                            (x_des + i <= cliprect.right))
	                        {
								src_data_ptr = source_surface + frame_offset + VM_CANVAS_FRAME_PROPERTY_SIZE + (j * frame_width + i) * 4;
								dst_data_idx = ((y_des + frame_height - j - 1) * buf_width + (x_des + i)) * 4;

	                            cur_color_888 = *(src_data_ptr) + (*(src_data_ptr + 1) << 8) + (*(src_data_ptr + 2) << 16);

								if (cur_color_888 != trans_color_888)						
	                            {
	                                buf_ex[dst_data_idx] = *(src_data_ptr) ;
	                                buf_ex[dst_data_idx + 1] = *(src_data_ptr + 1) ;
	                                buf_ex[dst_data_idx + 2] = *(src_data_ptr + 2) ;
	                                buf_ex[dst_data_idx + 3] = *(src_data_ptr + 3) ;
	                            }
	                        }
	                    }
	                }
	            }
	    	}
			else
			{}
        }	
        break;
    }
}


/*****************************************************************************
* FUNCTION
*  vm_graphic_roundrect
* DESCRIPTION
*  
* PARAMETERS
*  buf                 [?]         
*  x                   [IN]        
*  y                   [IN]        
*  width               [IN]        
*  height              [IN]        
*  corner_width        [IN]        
*  color               [IN]        
* RETURNS
*  void
*****************************************************************************/
static void _vm_graphic_roundrect(
                          VMUINT8 *buf,
                          VMINT x,
                          VMINT y,
                          VMINT width,
                          VMINT height,
                          VMINT corner_width,
                          VMUINT16 color_rgb565, vm_graphic_color_argb* p_color_argb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT r;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return;

    if ((buf == NULL) || (width <=0) || (height <=0) || (corner_width < 0))
        return ;

    if (corner_width > height / 2)
        corner_width = height / 2;
    if (corner_width > width / 2)
        corner_width = width / 2;
    r = corner_width;


    if (width < 10 || height < 10 || corner_width == 0) 
	{
        _vm_graphic_rect(buf, x, y, width, height, color_rgb565, p_color_argb);
    }
    else 
	{
        _vm_graphic_line(buf, x + r, y, x + width - r - 1, y, color_rgb565, p_color_argb);
        dd_circle(buf, x + width - r - 1, y + r, r, 0x01, color_rgb565, p_color_argb);
        _vm_graphic_line(buf, x + width - 1, y + r, x + width - 1, 
            y + height - r - 1, color_rgb565, p_color_argb);
        dd_circle(buf, x + width - r - 1, y + height - r - 1, r, 0x02, color_rgb565, p_color_argb);
        _vm_graphic_line(buf, x + r, y + height - 1, x + width - r - 1,
            y + height - 1, color_rgb565, p_color_argb);
        dd_circle(buf, x + r, y + height - r - 1, r, 0x04, color_rgb565, p_color_argb);
        _vm_graphic_line(buf, x, y + r, x, y + height - r - 1, color_rgb565, p_color_argb);
        dd_circle(buf, x + r, y + r, r, 0x08, color_rgb565, p_color_argb);
    }
}

void vm_graphic_roundrect(
                          VMUINT8 *buf,
                          VMINT x,
                          VMINT y,
                          VMINT width,
                          VMINT height,
                          VMINT corner_width,
                          VMUINT16 color)
{
	_vm_graphic_roundrect(buf, x, y,  width, height, corner_width, color, NULL);
}

void vm_graphic_roundrect_cf(
                          VMUINT8 *buf,
                          VMINT x,
                          VMINT y,
                          VMINT width,
                          VMINT height,
                          VMINT corner_width,
                          vm_graphic_color_argb* color)
{
	if (!color)
		return;

	_vm_graphic_roundrect(buf, x, y,  width, height, corner_width, 0, color);
}


/*****************************************************************************
* FUNCTION
*  vm_graphic_fill_roundrect
* DESCRIPTION
*  
* PARAMETERS
*  buf                 [?]         
*  x                   [IN]        
*  y                   [IN]        
*  width               [IN]        
*  height              [IN]        
*  corner_width        [IN]        
*  color               [IN]        
* RETURNS
*  void
*****************************************************************************/
static void _vm_graphic_fill_roundrect(
                               VMUINT8 *buf,
                               VMINT x,
                               VMINT y,
                               VMINT width,
                               VMINT height,
                               VMINT corner_width,
                               VMUINT16 color_rgb565, vm_graphic_color_argb* p_color_argb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT r, xc, yc, p, xa, xb, ya;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return;

    if ((buf == NULL) || (width <=0) || (height <=0) ||(corner_width < 0))
        return ;

    if (corner_width > height / 2)
        corner_width = height / 2;
    if (corner_width > width / 2)
        corner_width = width / 2;
    r = corner_width;
    xc = 0; yc = r; p = 3 - 2 * r;

    if (corner_width == 0)
    {
        _vm_graphic_fill_rect(buf, x, y, width, height, color_rgb565, p_color_argb, color_rgb565, p_color_argb);
        return;
    }
	
    while (xc <= yc) 
	{
        xa = x + r - xc;
        xb = x + width - r - 1 + xc;
        ya = y + r - yc;
        _vm_graphic_line(buf, xa, ya, xb, ya, color_rgb565, p_color_argb);
        xa = x + r - yc;
        xb = x + width - r - 1 + yc;
        ya = y + r - xc;
        _vm_graphic_line(buf, xa, ya, xb, ya, color_rgb565, p_color_argb);
        xa = x + r - xc;
        xb = x + width - r - 1 + xc;
        ya = y + height - r + yc - 1;
        _vm_graphic_line(buf, xa, ya, xb, ya, color_rgb565, p_color_argb);
        xa = x + r - yc;
        xb = x + width - r - 1 + yc;
        ya = y + height - r + xc - 1;
        _vm_graphic_line(buf, xa, ya, xb, ya, color_rgb565, p_color_argb);

		if (xc == yc)
		{
	        break;
		}
		else
		{
	        if (p < 0)
	            p = p + 4 * xc + 6;
	        else {
	            p = p + 4 * (xc - yc) + 10;
	            yc--;
	        }
	        xc++;
		}
    }

    for (ya = y + r; ya < y + height - r; ya++)
        _vm_graphic_line(buf, x, ya, x + width - 1, ya, color_rgb565, p_color_argb);
}

void vm_graphic_fill_roundrect(
                               VMUINT8 *buf,
                               VMINT x,
                               VMINT y,
                               VMINT width,
                               VMINT height,
                               VMINT corner_width,
                               VMUINT16 color)
{
	_vm_graphic_fill_roundrect(buf,x,y,width,height,corner_width,color,NULL);
}

void vm_graphic_fill_roundrect_cf(
                               VMUINT8 *buf,
                               VMINT x,
                               VMINT y,
                               VMINT width,
                               VMINT height,
                               VMINT corner_width,
                               vm_graphic_color_argb* color)
{
	if (!color)
		return;

	_vm_graphic_fill_roundrect(buf,x,y,width,height,corner_width,0,color);
}


static void _vm_graphic_ellipse_internal(VMUINT8* buf, VMINT x, VMINT y, VMINT width, VMINT height, VMUINT16 color_rgb565, vm_graphic_color_argb* p_color_argb, VMBOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT xx,yy,x1,x2,x3,x4,y1,y2,y3,y4,pk,a2,b2;
    VMINT xc,yc,rx,ry,rx2,ry2,tworx2,twory2,px,py;
    VMINT xiseven, yiseven;	
    VMINT xx1,xx2,xx3,xx4;
    VMINT buf_width, buf_height;
    VMINT buf_x, buf_y;
    VMINT b = FALSE;
    VMINT ret;
	VMBYTE cf;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return;

    if ((buf == NULL) || (width <=0) || (height <=0))
        return;
	
    xiseven = (width + 1)% 2;
    yiseven = (height + 1)% 2;

    a2 = x + width - 1;
    b2 = y + height - 1;

	if (flag == TRUE)
	{
	    if (memcmp(buf, MTK_CAN_MAGIC, 6) == 0)
	    {
	        buf_width = (buf[VM_CANVAS_SIGNATURE_SIZE + 6] << 8) + buf[VM_CANVAS_SIGNATURE_SIZE + 5]; 
	        buf_height = (buf[VM_CANVAS_SIGNATURE_SIZE + 8] << 8) + buf[VM_CANVAS_SIGNATURE_SIZE + 7]; 
	    }
	    else
	    {
#ifndef MRE_SUPPORT_MULTILAYER		
	        buf_width = LCD_WIDTH;
	        buf_height = LCD_HEIGHT;
#else
	        ret = vm_graphic_get_layer_porp_from_buf(buf, &buf_x, &buf_y, &buf_width, &buf_height, &cf);
	        if (ret == GDI_FAILED)
	        {
		        return;
	        }
#endif
	    }
	}

    xc = (x + a2) >> 1;
    yc = (y + b2) >> 1;
    if(x > a2)
        rx = (x - a2) >> 1;
    else
        rx = (a2 - x) >> 1;
    if(y > b2)
        ry = (y - b2) >> 1;
    else
        ry = (b2 - y) >> 1;
    rx2 = rx * rx;
    ry2 = ry * ry;
    tworx2 = rx2<<1;
    twory2 = ry2<<1;
    xx = 0;
    yy = ry;
    px = 0;
    py = tworx2 * yy;
    pk = ry2 - rx2*ry + (rx2>>2); 
    x1 = xc , y1 = yc + ry;
    x2 = xc , y2 = yc + ry;
    x3 = xc , y3 = yc - ry;
    x4 = xc , y4 = yc - ry;
    _vm_graphic_set_pixel(buf, x1,y1+yiseven,color_rgb565, p_color_argb);
    _vm_graphic_set_pixel(buf, x3,y3,color_rgb565, p_color_argb);
    _vm_graphic_set_pixel(buf, x2+xiseven,y2+yiseven,color_rgb565, p_color_argb);
    _vm_graphic_set_pixel(buf, x4+xiseven,y4,color_rgb565, p_color_argb);

    while(px < py)
    {	
	    xx++;
	    px+= twory2;
	    x1++,x2--,x3++,x4--;
	    if(pk < 0)
	    {	
		    pk+= ry2 + px;
			if (flag == TRUE)
			{
			    b = FALSE;
			    _vm_graphic_set_pixel(buf,x1+xiseven,y1+yiseven,color_rgb565, p_color_argb);
			    _vm_graphic_set_pixel(buf,x2,y2+yiseven,color_rgb565, p_color_argb);
			    _vm_graphic_set_pixel(buf,x3+xiseven,y3,color_rgb565, p_color_argb);
			    _vm_graphic_set_pixel(buf,x4,y4,color_rgb565, p_color_argb);
			}
	    }
	    else
	    {	
		    yy--;
		    y1--,y2--,y3++,y4++;
		    py -= tworx2;
		    pk+= ry2 + px - py;			
			if (flag == TRUE)
			    b = TRUE;
	    }

		if (flag == TRUE)
		{
		    xx1=x1,xx2=x2,xx3=x3,xx4=x4;
		    if(xx1 < 0 || xx2 > buf_width)
		        b = FALSE;
		    if(xx1 > buf_width)
		        xx1=xx3=buf_width;
		    if(xx2 < 0)
		        xx2=xx4=0;
		    if(b)
		    {
		        if(y1>=0&&y1<buf_height)
		        {
		            _vm_graphic_set_pixel(buf, xx2, y2, color_rgb565, p_color_argb);
		            _vm_graphic_line(buf, xx2, y1+yiseven, xx1+xiseven, y1+yiseven, color_rgb565, p_color_argb);
		        }
		        if(y3>=0&&y3<buf_height)
		        {
		            _vm_graphic_set_pixel(buf, xx4, y4, color_rgb565, p_color_argb);
		            _vm_graphic_line(buf, xx4, y3, xx3+xiseven, y3, color_rgb565, p_color_argb);
		        }
		    }
		}
		else
		{
			_vm_graphic_set_pixel(buf,x1+xiseven,y1+yiseven,color_rgb565, p_color_argb);
			_vm_graphic_set_pixel(buf,x2,y2+yiseven,color_rgb565, p_color_argb);
			_vm_graphic_set_pixel(buf,x3+xiseven,y3,color_rgb565, p_color_argb);
			_vm_graphic_set_pixel(buf,x4,y4,color_rgb565, p_color_argb);
		}
    }
	
    pk = (VMINT)sqrt(((ry2*(xx*2+1)*(xx*2+1))>>2) + rx2*(yy-1)*(yy-1) - rx2*ry2);
    while(yy>0)
    {	
		if (flag == TRUE)
			b = TRUE;
	    yy--;
	    y1--,y2--,y3++,y4++;
	    py-=tworx2;
	    if(pk>0)
	    {	
	    	pk+=rx2 - py;
	    }
	    else
	    {	
		    xx++;
		    x1++,x2--,x3++,x4--;
		    px+=twory2;
		    pk+=rx2-py+px;
	    }
		
		if (flag == TRUE)
		{
		    xx1=x1,xx2=x2,xx3=x3,xx4=x4;
		    if(xx1 < 0 || xx2 > buf_width)
		        b = FALSE;
		    if(xx1 > buf_width)
		        xx1=xx3=buf_width;
		    if(xx2 < 0)
		        xx2=xx4=0;
		    if(b)
		    {	
			    if(y1>=0&&y1<buf_height)
			    {
			        _vm_graphic_set_pixel(buf, xx2, y2, color_rgb565, p_color_argb);
			        _vm_graphic_line(buf, xx2, y1+yiseven, xx1+xiseven, y1+yiseven, color_rgb565, p_color_argb);
			    }
			    if(y3>=0&&y3<buf_height)
			    {
			        _vm_graphic_set_pixel(buf, xx4, y4, color_rgb565, p_color_argb);
			        _vm_graphic_line(buf, xx4, y3, xx3+xiseven, y3, color_rgb565, p_color_argb);
			    }
		    }
		}
		else
		{
			_vm_graphic_set_pixel(buf,x1+xiseven,y1+yiseven,color_rgb565, p_color_argb);
			_vm_graphic_set_pixel(buf,x2,y2+yiseven,color_rgb565, p_color_argb);
			_vm_graphic_set_pixel(buf,x3+xiseven,y3,color_rgb565, p_color_argb);
			_vm_graphic_set_pixel(buf,x4,y4,color_rgb565, p_color_argb);
		}
    }
}

void vm_graphic_ellipse(VMUINT8* buf, VMINT x, VMINT y, VMINT width, VMINT height, VMUINT16 color)
{
	_vm_graphic_ellipse_internal(buf, x, y, width, height, color, NULL, FALSE);
}

void vm_graphic_ellipse_cf(VMUINT8* buf, VMINT x, VMINT y, VMINT width, VMINT height, vm_graphic_color_argb* color)
{
	if (!color)
		return;

	_vm_graphic_ellipse_internal(buf, x, y, width, height, 0, color, FALSE);
}

void vm_graphic_fill_ellipse(VMUINT8* buf, VMINT x, VMINT y, VMINT width, VMINT height, VMUINT16 color)
{
	_vm_graphic_ellipse_internal(buf, x, y, width, height, color, NULL, TRUE);
}

void vm_graphic_fill_ellipse_cf(VMUINT8* buf, VMINT x, VMINT y, VMINT width, VMINT height, vm_graphic_color_argb* color)
{
	if (!color)
		return;

	_vm_graphic_ellipse_internal(buf, x, y, width, height, 0, color, TRUE);
}


static void _vm_graphic_textout_internal(
                                    VMUINT8 *disp_buf,
                                    VMINT x,
                                    VMINT y,
                                    VMWSTR s,
                                    VMINT length,
                                    VMUINT32 color,
                                    VMBOOL flag,
                                    VMINT baseline)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT buf_width, buf_height;
    VMUINT8 *dst_buf;
    clip_rect cliprect;
	vm_graphic_cb *current_cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return;

	current_cb = vm_graphic_get_current_cb();
	if (current_cb == NULL)
		return ;		

    memcpy(&cliprect, &(current_cb->cliprect), sizeof(clip_rect));

    if ((disp_buf == NULL) || (length <= 0))
        return;

    if (memcmp(disp_buf, MTK_CAN_MAGIC, 6) == 0)
    {	
        buf_width = (disp_buf[VM_CANVAS_SIGNATURE_SIZE + 6] << 8) + disp_buf[VM_CANVAS_SIGNATURE_SIZE + 5]; 
        buf_height = (disp_buf[VM_CANVAS_SIGNATURE_SIZE + 8] << 8) + disp_buf[VM_CANVAS_SIGNATURE_SIZE + 7]; 
        dst_buf = disp_buf + VM_CANVAS_SIGNATURE_SIZE + VM_CANVAS_FRAME_PROPERTY_SIZE;	

		if (flag == TRUE)
		{
        vm_graphic_canvas_textout_by_baseline_internal(dst_buf, buf_width, buf_height, x, y, 
            cliprect.left, cliprect.top, cliprect.right, cliprect.bottom,
            s, length, color,baseline);		
		}
		else
		{
			vm_graphic_canvas_textout_internal(dst_buf, buf_width, buf_height, x, y, 
				cliprect.left, cliprect.top, cliprect.right, cliprect.bottom,
				s, length, color);		
		}
    }	
    else		
    {
		if (flag == TRUE)
		{
	        vm_graphic_layer_textout_by_baseline_internal(disp_buf, x, y, 
	            cliprect.left, cliprect.top, cliprect.right, cliprect.bottom,
	            s, length, color,baseline);		
		}
		else
		{
			vm_graphic_layer_textout_internal(disp_buf, x, y, 
				cliprect.left, cliprect.top, cliprect.right, cliprect.bottom,
				s, length, color);		
		}
    }
}

void vm_graphic_textout (VMUINT8* disp_buf, VMINT x, VMINT y, VMWSTR s, VMINT length, VMUINT16 color)
{
	_vm_graphic_textout_internal(disp_buf, x, y, s, length, VM_COLOR_RGB565_TO_RGB32(color), FALSE, 0);	
}

void vm_graphic_textout_cf (VMUINT8* disp_buf, VMINT x, VMINT y, VMWSTR s, VMINT length, vm_graphic_color_argb* color)
{
	if (!color)
		return;

	_vm_graphic_textout_internal(disp_buf, x, y, s, length, VM_RGB32_ARGB(color->a, color->r, color->g, color->b), FALSE, 0);	
}

void vm_graphic_textout_by_baseline(
                                    VMUINT8 *disp_buf,
                                    VMINT x,
                                    VMINT y,
                                    VMWSTR s,
                                    VMINT length,
                                    VMUINT16 color,
                                    VMINT baseline)
{
	_vm_graphic_textout_internal(disp_buf, x, y, s, length, VM_COLOR_RGB565_TO_RGB32(color), TRUE, baseline);	
}

void vm_graphic_textout_by_baseline_cf(
                                    VMUINT8 *disp_buf,
                                    VMINT x,
                                    VMINT y,
                                    VMWSTR s,
                                    VMINT length,
                                    vm_graphic_color_argb* color,
                                    VMINT baseline)
{
	if (!color)
		return;

	_vm_graphic_textout_internal(disp_buf, x, y, s, length, VM_RGB32_ARGB(color->a, color->r, color->g, color->b), TRUE, baseline);	
}


/*****************************************************************************
* FUNCTION
*  vm_graphic_set_clip_internal
* DESCRIPTION
*  
* PARAMETERS
*  x1      [IN]        
*  y1      [IN]        
*  x2      [IN]        
*  y2      [IN]        
* RETURNS
*  void
*****************************************************************************/
void vm_graphic_set_clip_internal(VMINT x1, VMINT y1, VMINT x2, VMINT y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT tmp;
	vm_graphic_cb *current_cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMDDRAW, TRC_MRE_VMDDRAW_2611 ,x1,y1,x2,y2);

	current_cb = vm_graphic_get_current_cb();
	if (current_cb == NULL)
		return ;		
	
    current_cb->cliprect.left = x1 < 0 ? 0 : x1;
    current_cb->cliprect.top = y1 < 0 ? 0 : y1;
    current_cb->cliprect.right = x2 < 0 ? 0 : x2;
    current_cb->cliprect.bottom = y2 < 0 ? 0 : y2;
    current_cb->cliprect.flag = 1;
	
    if (current_cb->cliprect.left  > current_cb->cliprect.right)
    {
        tmp = current_cb->cliprect.left;
        current_cb->cliprect.left = current_cb->cliprect.right;
        current_cb->cliprect.right = tmp;
    }
	
    if (current_cb->cliprect.top  > current_cb->cliprect.bottom)
    {
        tmp = current_cb->cliprect.top;
        current_cb->cliprect.top = current_cb->cliprect.bottom;
        current_cb->cliprect.bottom = tmp;
    }
}

#endif /* __MRE_LIB_GRAPIC_DDRAW__ */ 

