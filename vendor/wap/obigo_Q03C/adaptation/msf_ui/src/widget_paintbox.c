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
 * widget_paintbox.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * MsfPaintbox creation/attributes
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
 *==============================================================================
 *******************************************************************************/

#include "widget.h"
#include "widget_struct.h"
#include "widget_linklist.h"


#ifdef  __MMI_WAP_MOUSE_POINTER_SUPPORT__    
extern S32 gdi_sizeof_pixels(gdi_color_format cf, S32 width, S32 height);
#endif /* __MMI_WAP_MOUSE_POINTER_SUPPORT__ */
/****************************************************************
 PAINTBOX 
 ***************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetPaintboxCreate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId               [IN]        
 *  size                [?]         
 *  propertyMask        [IN]        
 *  defaultStyle        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MsfWindowHandle HDIa_widgetPaintboxCreate(
                    MSF_UINT8 modId,
                    MsfSize *size,
                    int propertyMask,
                    MsfStyleHandle defaultStyle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_paintbox_struct *w = widget_create_paintbox(modId);
#ifdef  __MMI_WAP_MOUSE_POINTER_SUPPORT__    
    kal_uint8 *buffer_ptr = NULL;
    S32 buffer_size = 0;
#endif /*  __MMI_WAP_MOUSE_POINTER_SUPPORT__*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    w->module_id = modId;

    if (size)
    {
        w->size = *size;
    }
    else
    {
        w->size = WGUI_CTX->default_display_size;
    }
    WGUI_CTX->is_paintbox_created = KAL_TRUE;
    w->property_mask = propertyMask;
    widget_set_attrib(w, style, defaultStyle);
#ifdef  __MMI_WAP_MOUSE_POINTER_SUPPORT__
#ifdef BROWSER_SUPPORT
   WGUI_CTX->link_select_tool_handle = HDIa_widgetIconCreate(MSF_MODID_BRS, MsfLinkSelectTool,0);
   WGUI_CTX->mouse_pointer_handle = HDIa_widgetIconCreate(MSF_MODID_BRS, MsfMousePointer,0);
#endif
   HDIa_widgetGetSize(WGUI_CTX->link_select_tool_handle, &WGUI_CTX->link_select_tool_size);
   HDIa_widgetGetSize(WGUI_CTX->mouse_pointer_handle, &WGUI_CTX->mouse_pointer_size);
   if (WGUI_CTX->mouse_pointer_size.width > WGUI_CTX->link_select_tool_size.width)
       WGUI_CTX->gdi_layer_size.width = WGUI_CTX->mouse_pointer_size.width;
   else
       WGUI_CTX->gdi_layer_size.width = WGUI_CTX->link_select_tool_size.width;
   if (WGUI_CTX->mouse_pointer_size.height > WGUI_CTX->link_select_tool_size.height)
       WGUI_CTX->gdi_layer_size.height = WGUI_CTX->mouse_pointer_size.height;
   else
       WGUI_CTX->gdi_layer_size.height = WGUI_CTX->link_select_tool_size.height;
   buffer_size = gdi_sizeof_pixels(GDI_COLOR_FORMAT_16, WGUI_CTX->gdi_layer_size.width, WGUI_CTX->gdi_layer_size.height);
#ifdef WIDGET_MALLOC_IN_OWNER_MODULE
    buffer_ptr = widget_malloc_mem(MSF_MODID_WIDGET, buffer_size);
#else 
    buffer_ptr = widget_malloc_mem(buffer_size);
#endif
    WGUI_CTX->layer_memory_handle = (U32)buffer_ptr;
    gdi_layer_create_using_outside_memory(
                0,
                0,
                WGUI_CTX->gdi_layer_size.width,
                WGUI_CTX->gdi_layer_size.height,
                &(WGUI_CTX->gdi_layer_handle),
                (PU8) buffer_ptr,
                buffer_size);  
    ASSERT(WGUI_CTX->gdi_layer_handle != GDI_ERROR_HANDLE); 
#endif /*    __MMI_WAP_MOUSE_POINTER_SUPPORT__ */ 
    return (MsfWindowHandle) w;
}


/*****************************************************************************
 * FUNCTION
 *  HDIa_widgetPaintboxRedrawArea
 * DESCRIPTION
 *  
 * PARAMETERS
 *  paintbox        [IN]        
 *  size            [?]         
 *  pos             [?]         
 * RETURNS
 *  
 *****************************************************************************/
int HDIa_widgetPaintboxRedrawArea(MsfWindowHandle paintbox, MsfSize *size, MsfPosition *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Currently unsupported and unused */
    return 0;
}

