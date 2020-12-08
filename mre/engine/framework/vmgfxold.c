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
#include "vmsys.h"
#include "vmgraph.h"
#include "vmlog.h"
#include "vmgfxold.h"
#include "vmmod.h"
#include "vmpromng.h"
#include "vmswitch.h"


#ifdef __MRE_LIB_GRAPIC_GFXOLD__

VMINT is_base_layer_created = FALSE;             //基层创建标志
VMINT is_screen_buffer_initialized = FALSE;      //屏幕初始化标志

VMINT gfxold_layer_handles[1] = {0}; 
clip_rect gfxold_cliprect;              // 全局裁剪区

		
/**************************************************************************/
/*                                                                        */
/* 全部局变量引用                                                        */
/*                                                                        */
/**************************************************************************/

typedef VMUINT8* (*vm_graphic_user_get_resource_fp)(VMINT, VMINT*);
extern vm_graphic_user_get_resource_fp vm_get_res_provider(void);

extern VMINT vm_graphic_get_current_layer_count(void);
extern VMUINT8* vm_graphic_get_resource(VMINT resid,VMINT* len);

extern VMUINT32 vm_graphic_get_frame_offset(VMUINT8 *data, VMUINT8 frame_index);


vm_graphic_check_module_result vm_graphic_check_module_state_old(void)
{
    if(vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
        return VM_GRAPHIC_CHECK_MODULE_RET_MIBR;
    if (_vm_get_status() != MOD_STATUS_RUNNING)
        return VM_GRAPHIC_CHECK_MODULE_RET_STATUS;
		
    return VM_GRAPHIC_CHECK_MODULE_SUCCEED;
}


/*****************************************************************************
 * FUNCTION
 *  vm_graphic_lock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_graphic_lock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state_old() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return;
    
    if ((vm_graphic_get_current_layer_count()!=0) || is_base_layer_created)
        return;
    else
    {
        gfxold_layer_handles[0] = vm_graphic_create_layer(0, 0, vm_graphic_get_screen_width(), vm_graphic_get_screen_height(), -1);
        vm_graphic_set_clip(0, 0, vm_graphic_get_screen_width(), vm_graphic_get_screen_height());
        is_base_layer_created = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_graphic_unlock
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_graphic_unlock(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state_old() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return;

    vm_graphic_flush_layer(gfxold_layer_handles, 1);
    if (is_base_layer_created && !is_screen_buffer_initialized)
    {
        vm_graphic_delete_layer(gfxold_layer_handles[0]);
        is_base_layer_created = FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_graphic_get_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMUINT8* vm_graphic_get_buffer(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state_old() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return NULL;
    
    return (VMUINT8*)vm_graphic_get_layer_buffer(gfxold_layer_handles[0]);
}


/*****************************************************************************
 * FUNCTION
 *  vm_graphic_flush_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_graphic_flush_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state_old() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return;

    vm_graphic_flush_layer(gfxold_layer_handles, 1);
}


/*****************************************************************************
 * FUNCTION
 *  vm_initialize_screen_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_initialize_screen_buffer(void) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (_vm_get_status() != MOD_STATUS_RUNNING)
    //	return;
    if(vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
        return;	
    if ((vm_graphic_get_current_layer_count()!=0) || is_base_layer_created)
    {
        vm_graphic_set_clip(0, 0, vm_graphic_get_screen_width(), vm_graphic_get_screen_height());
    }
    else
    {
        gfxold_layer_handles[0] = vm_graphic_create_layer(0, 0, vm_graphic_get_screen_width(), vm_graphic_get_screen_height(), -1);
        vm_graphic_set_clip(0, 0, vm_graphic_get_screen_width(), vm_graphic_get_screen_height());
        is_base_layer_created = TRUE;
    }
    is_screen_buffer_initialized = TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vm_finalize_screen_buffer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_finalize_screen_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (_vm_get_status() != MOD_STATUS_RUNNING)
    //	return;
    //if(vm_pmng_state(VM_PMNG_CUR_HANDLE) != VM_PMNG_FOREGROUND)
    //  return;		
    if (is_base_layer_created)
    {
        vm_graphic_delete_layer(gfxold_layer_handles[0]);
        is_base_layer_created = FALSE;
    }
    is_screen_buffer_initialized = FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  vm_graphic_draw_gif
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gif             [?]         
 *  gif_len         [IN]        
 *  x               [IN]        
 *  y               [IN]        
 *  width           [IN]        
 *  height          [IN]        
 *  frame_index     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_graphic_draw_gif(VMUINT8 *gif, VMINT gif_len, VMINT x, VMINT y, VMINT width, VMINT height, VMINT frame_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8* buf = NULL;
    VMINT hcanvas;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state_old() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return 0;
    hcanvas = vm_graphic_load_image(gif, gif_len);
    buf = vm_graphic_get_layer_buffer(gfxold_layer_handles[0]);
    if (!buf)
        return 0;
    vm_graphic_blt(buf, x, y, vm_graphic_get_canvas_buffer(hcanvas), 0, 0, width, height, frame_index + 1);
    vm_graphic_release_canvas(hcanvas);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_graphic_bitblt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  resid       [IN]        
 *  x           [IN]        
 *  y           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_graphic_bitblt(VMINT resid, int x, int y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8 *ptr = NULL;
    VMINT size;
    VMINT hcanvas;
    VMUINT8* buf = NULL;
    struct frame_prop * prop = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state_old() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return -1;

    ptr = vm_graphic_get_resource(resid, &size);
    if (NULL == ptr) 
    {
        if (vm_get_res_provider() != NULL)
            ptr = (vm_get_res_provider())(resid, &size);
    }
    if (ptr != NULL) 
    {
        if ((hcanvas = vm_graphic_load_image(ptr, size)) < 0)
            return -1;
        if ((prop = vm_graphic_get_img_property(hcanvas, 1)) == NULL)
            return -1;
        buf = vm_graphic_get_layer_buffer(gfxold_layer_handles[0]);
        if (!buf)
        {
            vm_graphic_release_canvas(hcanvas);
            return -1;
        }
        vm_graphic_blt(buf, x, y, vm_graphic_get_canvas_buffer(hcanvas), 0, 0, prop->width, prop->height, 1	);
        vm_graphic_release_canvas(hcanvas);
    }
 
    return -1;
}

static VMBOOL vm_graphic_set_gfx_environment(void)
{
    VMUINT8* buf = NULL;

	if ( vm_graphic_check_module_state_old() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return FALSE;
    
    buf = vm_graphic_get_layer_buffer(gfxold_layer_handles[0]);
    if (!buf)
        return FALSE;

	return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  vm_graphic_drawtext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x           [IN]        
 *  y           [IN]        
 *  s           [IN]        
 *  length      [IN]        
 *  color       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_graphic_drawtext(VMINT x, VMINT y, VMWSTR s, VMINT32 length, VMINT color)
{
	if ( FALSE == vm_graphic_set_gfx_environment() )
		return;

	vm_graphic_textout(vm_graphic_get_layer_buffer(gfxold_layer_handles[0]), x, y, s, length, VM_COLOR_INT_TO_565(color));
}


/*****************************************************************************
 * FUNCTION
 *  vm_graphic_setpixel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x           [IN]        
 *  y           [IN]        
 *  color       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_graphic_setpixel(VMINT x, VMINT y, VMINT color)
{
	if ( FALSE == vm_graphic_set_gfx_environment() )
		return;

    vm_graphic_set_pixel(vm_graphic_get_layer_buffer(gfxold_layer_handles[0]), x, y, VM_COLOR_INT_TO_565(color));
}


/*****************************************************************************
 * FUNCTION
 *  vm_graphic_drawline
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x0          [IN]        
 *  y0          [IN]        
 *  x1          [IN]        
 *  y1          [IN]        
 *  color       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_graphic_drawline(VMINT x0, VMINT y0, VMINT x1, VMINT y1, VMINT color)
{
	if ( FALSE == vm_graphic_set_gfx_environment() )
		return;

    vm_graphic_line(vm_graphic_get_layer_buffer(gfxold_layer_handles[0]), x0, y0, x1, y1, VM_COLOR_INT_TO_565(color));
}


/*****************************************************************************
 * FUNCTION
 *  vm_graphic_drawrect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x           [IN]        
 *  y           [IN]        
 *  width       [IN]        
 *  height      [IN]        
 *  color       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_graphic_drawrect(VMINT x, VMINT y, VMINT width, VMINT height, VMINT color)
{
	if ( FALSE == vm_graphic_set_gfx_environment() )
		return;

    vm_graphic_rect(vm_graphic_get_layer_buffer(gfxold_layer_handles[0]), x, y, width, height, VM_COLOR_INT_TO_565(color));
}


/*****************************************************************************
 * FUNCTION
 *  vm_graphic_fillrect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x           [IN]        
 *  y           [IN]        
 *  width       [IN]        
 *  height      [IN]        
 *  color       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_graphic_fillrect(VMINT x, VMINT y, int width, int height, int color)
{
	if ( FALSE == vm_graphic_set_gfx_environment() )
		return;

    vm_graphic_fill_rect(vm_graphic_get_layer_buffer(gfxold_layer_handles[0]), x, y, width, height, VM_COLOR_INT_TO_565(color), VM_COLOR_INT_TO_565(color));
}


/*****************************************************************************
 * FUNCTION
 *  vm_dd_initialize_clip_rect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_dd_initialize_clip_rect(void)
{
	if ( FALSE == vm_graphic_set_gfx_environment() )
		return;

    vm_graphic_set_clip(0, 0, vm_graphic_get_screen_width(), vm_graphic_get_screen_height());
}


/*****************************************************************************
 * FUNCTION
 *  vm_dd_set_clip
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x           [IN]        
 *  y           [IN]        
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_dd_set_clip(VMINT x, VMINT y, VMINT width, VMINT height)
{	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state_old() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return;

    gfxold_cliprect.left = x < 0 ? 0 : x;
    gfxold_cliprect.top = y < 0 ? 0 : y;
    gfxold_cliprect.right = width < 0 ? 0 : x + width - 1;
    gfxold_cliprect.bottom = height < 0 ? 0 : y + height - 1;
    gfxold_cliprect.flag = 1;
    if (gfxold_cliprect.left  > gfxold_cliprect.right)
    {
        tmp = gfxold_cliprect.left;
        gfxold_cliprect.left = gfxold_cliprect.right;
        gfxold_cliprect.right = tmp;
    }
    
    if (gfxold_cliprect.top  > gfxold_cliprect.bottom)
    {
        tmp = gfxold_cliprect.top;
        gfxold_cliprect.top = gfxold_cliprect.bottom;
        gfxold_cliprect.bottom = tmp;
    }
    
    vm_graphic_set_clip(gfxold_cliprect.left , gfxold_cliprect.top, gfxold_cliprect.right, gfxold_cliprect.bottom);
}


/*****************************************************************************
 * FUNCTION
 *  vm_dd_reset_clip
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_dd_reset_clip(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gfxold_cliprect.flag = 1;
    gfxold_cliprect.left = 0;
    gfxold_cliprect.top = 0;
    gfxold_cliprect.right = vm_graphic_get_screen_width();
    gfxold_cliprect.bottom = vm_graphic_get_screen_height();
    vm_graphic_reset_clip();
}


/*****************************************************************************
 * FUNCTION
 *  vm_dd_blt_all_cutting_frames
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf                 [?]         
 *  source_surface      [?]         
 *  x_num               [IN]        
 *  y_num               [IN]        
 *  width               [IN]        
 *  height              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_dd_blt_all_cutting_frames(
        VMBYTE *buf,
        VMBYTE *source_surface,
        VMINT x_num,
        VMINT y_num,
        VMINT width,
        VMINT height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT	i,j; 
    VMINT	frame_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state_old() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return;
    
    if ((buf == NULL) || (source_surface == NULL))
        return;

    frame_num = 1;
    for(i=0; i < x_num; i++)
        for(j=0; j < y_num; j++)
        {
            vm_dd_blt(buf, j*(width/x_num), i*(height/y_num), source_surface, 0, 0, width/x_num, height/y_num, frame_num++);
        }
}

static VMBOOL vm_graphic_gfx_operation_setup(VMBYTE *buf, VMBYTE *source_surface, VMINT frame_index) 
{
    VMINT 	frame_num;

	if ( vm_graphic_check_module_state_old() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return FALSE;
    
    if ((buf == NULL) || (source_surface == NULL))
        return FALSE;

    frame_num = source_surface[VM_CANVAS_FRAME_NUM_OFFSET];
    if (frame_index > frame_num)
        return FALSE;
	
	return TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  vm_dd_img_flood
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf                 [?]         
 *  x_dst               [IN]        
 *  y_dst               [IN]        
 *  source_surface      [?]         
 *  width               [IN]        
 *  height              [IN]        
 *  frame_index         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_dd_img_flood(
        VMBYTE *buf,
        VMINT x_dst,
        VMINT y_dst,
        VMBYTE *source_surface,
        VMINT width,
        VMINT height,
        VMINT frame_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT	i,j;
    VMINT16 frame_width;
    VMINT16 frame_height;
    VMINT	frame_offset;
    VMINT	frame_data_offset;
    VMINT   x_num,y_num;
    VMINT 	frame_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( FALSE == vm_graphic_gfx_operation_setup(buf, source_surface, frame_index) )
		return;

    frame_offset = vm_graphic_get_frame_offset(source_surface, frame_index);
	
    frame_width = source_surface[frame_offset+5] + (source_surface[frame_offset+6]<<8); 
    frame_height = source_surface[frame_offset+7] + (source_surface[frame_offset+8]<<8);
    

    if(width%frame_width==0)
        x_num=width/frame_width;
    else
        x_num=width/frame_width+1;

    if(height%frame_height==0)
        y_num=height/frame_height;
    else
        y_num=height/frame_height+1;

    for(i=0; i<y_num; i++)
        for(j=0; j<x_num; j++)
            vm_dd_blt(buf, x_dst+j*frame_width, y_dst+i*frame_height, source_surface, 0, 0, 
                      frame_width, frame_height, frame_index);
}


/*****************************************************************************
 * FUNCTION
 *  vm_dd_copy
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
 *  direction           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_dd_copy(
        VMBYTE *buf,
        VMINT x_dest,
        VMINT y_dest,
        VMBYTE *source_surface,
        VMINT x_src,
        VMINT y_src,
        VMINT width,
        VMINT height,
        VMINT frame_index,
        VMINT direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT i;
    clip_rect rect;
    VMBYTE accept=0;
    VMINT 	frame_num;
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( FALSE == vm_graphic_gfx_operation_setup(buf, source_surface, frame_index) )
		return;

    vm_dd_blt(buf,x_dest,y_dest,source_surface,x_src,y_src,width,height,frame_index);

    rect.left = x_dest;
    rect.top = y_dest;
    rect.right = x_dest + width - 1;
    rect.bottom = y_dest + height - 1;
    
    if (!(rect.left > gfxold_cliprect.right || rect.right < gfxold_cliprect.left || rect.top > gfxold_cliprect.bottom || rect.bottom < gfxold_cliprect.top))
    {
        rect.left = rect.left<gfxold_cliprect.left ? gfxold_cliprect.left : rect.left;
        rect.top = rect.top<gfxold_cliprect.top ? gfxold_cliprect.top : rect.top;
        rect.right = rect.right < gfxold_cliprect.right ? rect.right : gfxold_cliprect.right;
        rect.bottom = rect.bottom<gfxold_cliprect.bottom ? rect.bottom : gfxold_cliprect.bottom;
        accept = 1;
    }
    
    if (accept)
    {
        if(direction == 0)
        {
            if (rect.right + (rect.right - rect.left) < gfxold_cliprect.right)
            {
                for (i = 0; i < rect.bottom - rect.top; i++)
                {
#ifdef VM_LCD_BUFF_IS_16BIT
                memcpy( buf + (rect.right + (i + rect.top) * screen_width) * 2,
                        buf + (rect.left + (i + rect.top) * screen_width) * 2, (rect.right - rect.left) * 2);
#endif

#ifdef VM_LCD_BUFF_IS_24BIT
                memcpy( buf + (rect.right + (i + rect.top) * screen_width) * 3,
                        buf + (rect.left + (i + rect.top) * screen_width) * 3, (rect.right - rect.left) * 3);
#endif	
                }
            }
            else
            {
                for (i = 0; i < rect.bottom - rect.top; i++)
                {
#ifdef VM_LCD_BUFF_IS_16BIT
                memcpy( buf + (rect.right + (i + rect.top) * screen_width) * 2,
                        buf + (rect.left + (i + rect.top) * screen_width) * 2, (gfxold_cliprect.right - rect.right) * 2);
#endif

#ifdef VM_LCD_BUFF_IS_24BIT
                memcpy( buf + (rect.right + (i + rect.top) * screen_width) * 3,
                        buf + (rect.left + (i + rect.top) * screen_width) * 3, (gfxold_cliprect.right - rect.right) * 3);
#endif	
                }
                
            }
        }
        else if(direction == 1)
        {
            if (rect.bottom + (rect.bottom - rect.top) < gfxold_cliprect.bottom)
            {
                for (i = 0; i < rect.bottom - rect.top; i++)
                {
#ifdef VM_LCD_BUFF_IS_16BIT
                memcpy( buf + (rect.left + (i + rect.bottom) * screen_width) * 2,
                        buf + (rect.left + (i + rect.top) * screen_width) * 2, (rect.right - rect.left) * 2);
#endif

#ifdef VM_LCD_BUFF_IS_24BIT
                memcpy( buf + (rect.left + (i + rect.bottom) * screen_width) * 3,
                        buf + (rect.left + (i + rect.top) * screen_width) * 3, (rect.right - rect.left) * 3);
#endif				
                }
            }
            else
            {
                for (i = 0; i < gfxold_cliprect.bottom - rect.bottom; i++)
                {
#ifdef VM_LCD_BUFF_IS_16BIT
                memcpy( buf + (rect.left + (i + rect.bottom) * screen_width) * 2,
                        buf + (rect.left + (i + rect.top) * screen_width) * 2, (rect.right - rect.left) * 2);
#endif

#ifdef VM_LCD_BUFF_IS_24BIT
                memcpy( buf + (rect.left + (i + rect.bottom) * screen_width) * 3,
                        buf + (rect.left + (i + rect.top) * screen_width) * 3, (rect.right - rect.left) * 3);
#endif
                }			
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_dd_flood_4_regional
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf                 [?]         
 *  x_dst               [IN]        
 *  y_dst               [IN]        
 *  source_surface      [?]         
 *  width               [IN]        
 *  height              [IN]        
 *  frame_index         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_dd_flood_4_regional(
        VMBYTE *buf,
        VMINT x_dst,
        VMINT y_dst,
        VMBYTE *source_surface,
        VMINT width,
        VMINT height,
        VMINT frame_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT	i;
    VMINT16 frame_width;
    VMINT16 frame_height;
    VMINT	frame_offset;
    VMINT	frame_data_offset;
    VMINT 	frame_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( FALSE == vm_graphic_gfx_operation_setup(buf, source_surface, frame_index) )
		return;
    
    frame_offset = vm_graphic_get_frame_offset(source_surface, frame_index);
	
    frame_width = source_surface[frame_offset+5] + (source_surface[frame_offset+6]<<8); 
    frame_height = source_surface[frame_offset+7] + (source_surface[frame_offset+8]<<8);

    vm_dd_copy(buf,x_dst,y_dst,source_surface,0,0,frame_width,frame_height,frame_index,0);
    vm_dd_copy(buf,x_dst,y_dst+frame_height,source_surface,0,0,frame_width,frame_height,frame_index,0);

}


/*****************************************************************************
 * FUNCTION
 *  vm_dd_load_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img         [?]         
 *  img_len     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMUINT8* vm_dd_load_image(VMUINT8 *img, VMINT img_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state_old() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return NULL;
    
    ret = vm_graphic_load_image(img, img_len);

    if (ret < 0)
        return NULL;
    else
        return (VMUINT8*) ret;
} 


/*****************************************************************************
 * FUNCTION
 *  vm_dd_get_img_property
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img             [?]         
 *  frame_index     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
struct frame_prop * vm_dd_get_img_property(VMUINT8 *img,  VMUINT8 frame_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vm_graphic_get_img_property((VMINT)img, frame_index);
} 


/*****************************************************************************
 * FUNCTION
 *  vm_dd_get_frame_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img     [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_dd_get_frame_number(VMUINT8 *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vm_graphic_get_frame_number((VMINT)img);
}


/*****************************************************************************
 * FUNCTION
 *  vm_dd_clean
 * DESCRIPTION
 *  
 * PARAMETERS
 *  buf         [?]         
 *  color16     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_dd_clean(VMUINT8* buf, VMUINT16 color16)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state_old() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return;
    
    vm_graphic_fill_rect(buf, 0, 0, vm_graphic_get_screen_width(), vm_graphic_get_screen_height(), color16, color16);
}


/*****************************************************************************
 * FUNCTION
 *  vm_dd_active_layer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_dd_active_layer(VMINT handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT x = 0, y = 0, w = -1, h = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state_old() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return;
    
    vm_graphic_get_layer_position(handle,&x,&y,&w,&h);
    vm_graphic_active_layer(handle);
    vm_graphic_set_clip(0, 0, w, h);
}


/*****************************************************************************
 * FUNCTION
 *  vm_graph_drawtext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x           [IN]        
 *  y           [IN]        
 *  s           [IN]        
 *  length      [IN]        
 *  color       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_graph_drawtext(VMINT x, VMINT y, VMWSTR s, VMINT32 length, VMUINT16 color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT8* buf = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state_old() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return;
    
    buf = vm_graphic_get_layer_buffer(gfxold_layer_handles[0]);
    if (!buf)
        return;
    vm_graphic_textout(buf, x, y, s, length, VM_COLOR_INT_TO_565(color));
}




/*****************************************************************************
 * FUNCTION
 *  vm_graph_release_surface
 * DESCRIPTION
 *  
 * PARAMETERS
 *  off_surface     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vm_graph_release_surface(VMUINT8 * off_surface)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(vm_pmng_state(VM_PMNG_CUR_HANDLE) == VM_PMNG_UNLOAD)
        return;

    if (off_surface == NULL)
        return;
    else
        vm_free(off_surface);	
}


/*****************************************************************************
 * FUNCTION
 *  vm_graph_create_custom_buf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  width       [IN]        
 *  height      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMUINT8 * vm_graph_create_custom_buf(VMINT width, VMINT height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT hcanvas;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hcanvas = vm_graphic_create_canvas(width, height);
    if (hcanvas != VM_GDI_FAILED)
        return (VMUINT8 *) hcanvas;
    else
        return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  vm_graph_delete_custom_buf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  custom_buf      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void vm_graph_delete_custom_buf(VMUINT8 * custom_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(vm_pmng_state(VM_PMNG_CUR_HANDLE) == VM_PMNG_UNLOAD)
        return;
    
    vm_free(custom_buf);
}


/*****************************************************************************
 * FUNCTION
 *  vm_graph_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  screen_buf      [?]         
 *  x_dest          [IN]        
 *  y_dest          [IN]        
 *  custom_buf      [?]         
 *  x_src           [IN]        
 *  y_src           [IN]        
 *  width           [IN]        
 *  height          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_graph_move(
        VMBYTE *screen_buf,
        VMINT x_dest,
        VMINT y_dest,
        VMBYTE *custom_buf,
        VMINT x_src,
        VMINT y_src,
        VMINT width,
        VMINT height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( vm_graphic_check_module_state_old() != VM_GRAPHIC_CHECK_MODULE_SUCCEED ) 
		return;
    
    vm_graphic_blt(screen_buf, x_dest, y_dest, custom_buf, x_src, y_src, width, height, 1);
}


#endif
