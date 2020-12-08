/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * Vmgraph.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   vre graphic head file
 *
 * Author:
 * -------
 * -------
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/



#ifndef VMGRAPHIC_H_
#define VMGRAPHIC_H_

#include "vmgraph_sdk.h"
#include "PixcomFontEngine.h"
#include "gdi_include.h"


#ifndef VM_CANVAS_FRAME_NUM_OFFSET
#define VM_CANVAS_FRAME_NUM_OFFSET            (9)    //canvas offset
#endif

#ifndef VM_CANVAS_SIGNATURE_SIZE
#define VM_CANVAS_SIGNATURE_SIZE            (12)    //canvas signature size
#endif

#ifndef VM_CANVAS_FRAME_PROPERTY_SIZE
#define VM_CANVAS_FRAME_PROPERTY_SIZE       (20)    //canvas property size
#endif


typedef struct _layer_param_t {
	gdi_handle handle;
	gdi_color  trans_color;
	VMINT   trans_color_enable;	
	VMINT   x;
	VMINT   y;
	VMINT   width;
	VMINT   height;
	VMUINT8* buffer;
    VMUINT8* buffer1;
	VMUINT buffer_size;
	VMUINT8* canvas;
    VMUINT8* canvas1;
	VMINT   mibrhandle;
	VMINT   rotate;
	VMINT   used;
	VMINT   all_delete;
    VMUINT  flag;
    VMUINT  cf;	
} layer_param_t;

typedef VMUINT8* (*vm_graphic_user_get_resource_fp)(VMINT, VMINT*);

typedef struct vm_graphic_cb
{
	VMINT active_layer;
	gdi_handle old_alpha_blending_layer;
	clip_rect cliprect;
	vm_graphic_pen pen;
	vm_graphic_color color;
	vm_graphic_color_argb color_argb;
	stFontAttribute font;
	VMINT baseline;
	VMINT blt_layers[6];
	vm_graphic_user_get_resource_fp user_get_resource_fp;     //self-define callback function pointer,  only compatible with older version
	                                        //vm_graphic_bitblt() in vmfxold.c use it, and mini use it	
}vm_graphic_cb;


typedef enum
{
    VM_GRAPHIC_CHECK_MODULE_RET_MIBR = -2, 
	VM_GRAPHIC_CHECK_MODULE_RET_STATUS,                     
	VM_GRAPHIC_CHECK_MODULE_SUCCEED                     
}vm_graphic_check_module_result;                          

typedef enum
{
    VM_GRAPHIC_INT_GET_HANDLE_FAIL = -3, 
	VM_GRAPHIC_INT_GET_CUR_CB_FAIL,	
	VM_GRAPHIC_INT_CHECK_MODULE_FAIL,                     
	VM_GRAPHIC_INT_NO_ERROR                     
}vm_graphic_internal_error_code;                          

typedef enum{
	VM_GRAPHIC_CREATE_LAYER,  
	VM_GRAPHIC_CREATE_LAYER_EX,      
	VM_GRAPHIC_CREATE_LAYER_CF,
	VM_GRAPHIC_CREATE_LAYER_CF_DOUBLE   
}vm_graphic_create_layer_way;

typedef enum{
	VM_GRAPHIC_GIF_DECODE,  
	VM_GRAPHIC_GIF_DECODE_RESIZED,      
	VM_GRAPHIC_GIF_DECODE_RESIZED_BY_PERCENT
}vm_graphic_gif_decode_flag;


struct _buf_prop 
{
	vm_graphic_color_famat cf;
	VMINT dst_is_canvas;
	VMINT buf_x;
	VMINT buf_y;
	VMINT buf_width;
	VMINT buf_height;
	VMUINT8 *buf_ex;
};

struct _frame_prop 
{
	vm_graphic_color_famat cf;
    VMINT	 offset;
	VMUINT8  flag;					/* marker to show it is  frame beginning  */
	VMUINT8  is_resize;                             /* if resize */
	VMUINT16 left;					/* x offset */
	VMUINT16 top;					/* y offset */
	VMUINT16 width;					/*image width */
	VMUINT16 height;				/* image height*/
	VMUINT16 trans_color_565;
	vm_graphic_color_argb trans_color_argb;
	VMUINT32 size;				/* current frame size , unit:byte */	
};


#endif
