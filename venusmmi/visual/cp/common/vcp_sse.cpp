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
 *  vcp_sse.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 *
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
 *
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
 * removed!
 * removed!
 * removed!
 *
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
 *
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
 *
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
 *
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
 *
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
 * removed!
 *
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
 *
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
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vcp_sse.h"

#include "vfx_mmi.h"
#include "vfx_input_event.h"
#include "vfx_animation.h"
#include "vfx_renderer.h"
#include "vfx_control.h"

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_system.h"
#include "vfx_basic_type.h"
#include "vfx_auto_animate.h"
#include "vfx_signal.h"
#include "vfx_context.h"
#include "vfx_logger.h"
#include "vfx_pen.h"

#include "vfx_system.h"
#include "vfx_app_cat_scr.h"

#include "vapp_platform_context.h"
#include "vadp_sys_trc.h"
extern "C" 
{
    #include "gdi_layer.h"
    #include "vrt_canvas.h"
    #include "cache_sw.h"
    #include "app_mem.h"
}
#include "app_mem_med.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#if defined(VFX_CFG_SOFTWARE_LA)
#undef __MAUI_SOFTWARE_LA__
#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
extern "C" 
{
#include "SST_sla.h"
}
#endif

#include "vcp_global_popup.h"

extern "C" void gui_screen_switch_effect_get_frame_buffer_info(U32 frame_buf_index, PU8 *buf_p, S32 *buf_size);
extern "C" gui_sse_scenario_enum gui_sse_get_scenario();
extern "C" void vrt_time_reset_time_entered(void);

#ifdef __MMI_REDUCED_UI_BUFFER__
static vrt_bool g_vcp_sse_use_vrt_single_buffer_mode = VRT_FALSE;
static MMI_BOOL g_vcp_sse_is_forced_cancel = MMI_FALSE;
#endif /* __MMI_REDUCED_UI_BUFFER__ */


/***************************************************************************** 
 * define
 *****************************************************************************/

#if defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__)
#define VCP_SSE_2D_DEFAULT_DURATION                        (450)
#else
#define VCP_SSE_2D_DEFAULT_DURATION                        (300)
#endif
 #define VCP_SSE_3D_DEFAULT_DURATION                        (1000)

/***************************************************************************** 
 * static function
 *****************************************************************************/

static void setupFramebyBuffer(VfxFrame *frame, VfxU8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle base_layer;

    gdi_color_format colorFormat;
    VfxS32 bpp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

    gdi_layer_get_base_handle(&base_layer);
    gdi_layer_push_and_set_active(base_layer);
   
    gdi_layer_get_color_format(&colorFormat);
    bpp = gdi_layer_get_bit_per_pixel();

    gdi_layer_pop_and_restore_active();


    // Config image buffer
    VfxImageBuffer imgBuf;
    imgBuf.ptr          = buffer;
    imgBuf.pitchBytes   = bpp * GDI_LCD_WIDTH / 8;
    imgBuf.width        = GDI_LCD_WIDTH;
    imgBuf.height       = GDI_LCD_HEIGHT;
    switch (colorFormat)
    {
        case GDI_COLOR_FORMAT_16:
            imgBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
            break;
        case GDI_COLOR_FORMAT_32:
            imgBuf.colorFormat = VRT_COLOR_TYPE_ARGB8888;
            break;
        case GDI_COLOR_FORMAT_32_PARGB:
            imgBuf.colorFormat = VRT_COLOR_TYPE_PARGB8888;
            break;
        default:
            VFX_DEV_ASSERT(0);
            imgBuf.colorFormat = VRT_COLOR_TYPE_UNKNOWN;
            break;
    };

    // Update this frame
    frame->setBounds(0, 0, GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    frame->setImgContent(VfxImageSrc(imgBuf));
    frame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    frame->invalidate();
}


/***************************************************************************** 
 * Class VcpSseSnapShotScreenBuilder
 *****************************************************************************/

void VcpSseSnapShotScreenBuilder::onSnapshot(VfxU8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle snap_layer;
    gdi_handle base_layer;

    VfxS32 bpp;
    gdi_color old_bg_color;
    gdi_color src_key_color;
    BOOL src_key_enable;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

    gdi_layer_get_base_handle(&base_layer);
    gdi_layer_push_and_set_active(base_layer);

    bpp = gdi_layer_get_bit_per_pixel();
    gdi_layer_get_source_key(&src_key_enable, &src_key_color);
    gdi_layer_set_source_key(VRT_TRUE, GDI_COLOR_TRANSPARENT);
    old_bg_color = gdi_layer_get_background();
    gdi_layer_set_background(GDI_COLOR_TRANSPARENT ^ 1);

    // use memcpy
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    gdi_layer_create_cf_using_outside_memory(
        GUI_SCREEN_SWITCH_EFFECT_LAYER_COLOR_FORMAT,
        0,
        0,
        GDI_LCD_WIDTH,
        GDI_LCD_HEIGHT,
        &snap_layer,
        (U8*)buffer,
        GDI_LCD_WIDTH * GDI_LCD_HEIGHT * bpp);
    

    gdi_layer_push_and_set_active(snap_layer);
    gdi_layer_set_source_key(VRT_TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_reset_clip();   
    
    gdi_layer_flatten_with_clipping(base_layer, 0, 0, 0);

    //gdi_layer_save_bmp_file((gdi_handle)base_layer, (PS8)L"D:\\\\base.bmp");
    //gdi_layer_save_bmp_file((gdi_handle)snap_layer, (PS8)L"D:\\\\snapshot.bmp");

    gdi_layer_pop_and_restore_active();


    gdi_layer_set_source_key(src_key_enable, src_key_color);
    gdi_layer_set_background(old_bg_color);

    gdi_layer_pop_and_restore_active();

    gdi_layer_free(snap_layer); 

}


void VcpSseSnapShotScreenBuilder::onBuildScreen(VfxFrame *frame, VfxU8 *buffer)
{
    setupFramebyBuffer(frame, buffer);
}



/***************************************************************************** 
 * Class VcpSseFlattenSnapShotScreenBuilder
 *****************************************************************************/

void VcpSseFlattenSnapShotScreenBuilder::onSnapshot(VfxU8 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;    
    gdi_handle snap_layer, layers[4];
    gdi_handle blt_layer = 0;

    VfxS32 bpp;
    gdi_handle base_layer;
    VfxBool sourcekeyEnable = VFX_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_layer_get_base_handle(&base_layer);
    gdi_layer_push_and_set_active(base_layer);
    
    bpp = gdi_layer_get_bit_per_pixel();

    gdi_layer_pop_and_restore_active();

    // use memcpy to improve proformance
    S32 count = 0;
    VfxBool is16bit = VFX_FALSE;
    gdi_layer_get_blt_layer(&layers[0], &layers[1], &layers[2], &layers[3]);
    for (i = 0; i < 4; i++)
    {
        if (layers[i] && GDI_LAYER_GET_FLAG(layers[i], GDI_LAYER_FLAG_USED))
        {
            count++;
            blt_layer = layers[i];

            BOOL        src_key_enable;
            gdi_color   src_key_color;
            gdi_layer_push_and_set_active(blt_layer);
            gdi_layer_get_source_key(&src_key_enable, &src_key_color);
            if (src_key_enable)
            {
                sourcekeyEnable = VFX_TRUE;
            }
            if (gdi_layer_get_bit_per_pixel() == 16)
            {
                is16bit = VFX_TRUE;
            }
            gdi_layer_pop_and_restore_active();
        }
    }

    if (count == 1 && is16bit)
    {
        U8* buf_ptr;

        gdi_layer_push_and_set_active(blt_layer);
        gdi_layer_get_buffer_ptr(&buf_ptr);
        gdi_layer_pop_and_restore_active();

        memcpy(buffer, buf_ptr, GDI_LCD_WIDTH * GDI_LCD_HEIGHT * bpp / 8);
    }
    else
    {
        gdi_layer_create_cf_using_outside_memory(
            GUI_SCREEN_SWITCH_EFFECT_LAYER_COLOR_FORMAT,
            0,
            0,
            UI_device_width,
            UI_device_height,
            &snap_layer,
            buffer,
            UI_device_width * UI_device_height * GUI_SCREEN_SWITCH_EFFECT_PIXEL_BYTE_SIZE);

        gdi_layer_push_and_set_active(snap_layer);
        gdi_layer_reset_clip();
        gdi_layer_set_source_key(sourcekeyEnable, GDI_COLOR_TRANSPARENT);
        
        gdi_layer_get_blt_layer(&layers[0], &layers[1], &layers[2], &layers[3]);
        for (i = 0; i < 4; i++)
        {
            /* do not touch the layer if it is already freed */
            // TODO: use GDI API
            if (layers[i] && !(((gdi_layer_struct*)layers[i])->flag & 1))
            {
                layers[i] = GDI_NULL_HANDLE;
            }
        }    

        gdi_layer_flatten(layers[0], layers[1], layers[2], layers[3]);
        
        gdi_layer_pop_and_restore_active();

        gdi_layer_free(snap_layer);
    }

}


void VcpSseFlattenSnapShotScreenBuilder::onBuildScreen(VfxFrame *frame, VfxU8 *buffer)
{
    setupFramebyBuffer(frame, buffer);
}
/***************************************************************************** 
 * Class VcpSseManager
 *****************************************************************************/
 
VFX_IMPLEMENT_CLASS(VCP_SSE_MANAGER_CLASS_NAME, VcpSseManager, VfxFrame);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VcpSseManager);


VcpSseManager::VcpSseManager() :
    m_context(NULL),
    m_mem(NULL),
    m_oldScreen(NULL),
    m_newScreen(NULL),
    m_pagePanel(NULL),
    m_oldScreenBuilder(NULL),
    m_newScreenBuilder(NULL),
    m_data(NULL),
    m_dataSize(0),
    m_isPluto(VFX_FALSE),
    m_useImageSrc(VFX_FALSE)
#ifdef __MMI_REDUCED_UI_BUFFER__
    ,m_oldScreenBuf(NULL)
    ,m_newScreenBuf(NULL)
#endif /* __MMI_REDUCED_UI_BUFFER__ */
{
}


void VcpSseManager::setup()
{
    gui_sse_scenario_enum scenario = gui_sse_get_scenario();

    VFX_LOG(VFX_INFO, VCP_SSE_SETUP_SCENARIO_2_MSG, scenario);
    
    VFX_OBJ_CLOSE(m_oldScreenBuilder);
    VFX_OBJ_CREATE(m_oldScreenBuilder, VcpSseSnapShotScreenBuilder, this);    
    VFX_OBJ_CLOSE(m_newScreenBuilder);
    VFX_OBJ_CREATE(m_newScreenBuilder, VcpSseFlattenSnapShotScreenBuilder, this);
    
    switch (scenario)
    {
        case GUI_SSE_SCENARIO_COSMOS_3D_TRIANGLE_ENTER:
            m_effectType = VCP_PAGE_EFFECT_3D_BLINDS;
            m_duration = VCP_SSE_3D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_LEFT;
            m_useImageSrc = VFX_TRUE;
            break;

        case GUI_SSE_SCENARIO_COSMOS_3D_TRIANGLE_EXIT:
            m_effectType = VCP_PAGE_EFFECT_3D_BLINDS;
            m_duration = VCP_SSE_3D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_BACKWARD;
            m_useImageSrc = VFX_TRUE;
            break;
            
        case GUI_SSE_SCENARIO_COSMOS_3D_CIRCLE_ENTER:
            m_effectType = VCP_PAGE_EFFECT_3D_CIRCLE;
            m_duration = VCP_SSE_3D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_LEFT;
            m_useImageSrc = VFX_TRUE;
            break;

        case GUI_SSE_SCENARIO_COSMOS_3D_CIRCLE_EXIT:
            m_effectType = VCP_PAGE_EFFECT_3D_CIRCLE;
            m_duration = VCP_SSE_3D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_BACKWARD;
            m_useImageSrc = VFX_TRUE;
            break;
            
        case GUI_SSE_SCENARIO_COSMOS_3D_CUBE_ENTER:
            m_effectType = VCP_PAGE_EFFECT_3D_CUBE_FLY_OUT;
            m_duration = VCP_SSE_3D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_LEFT;
            m_useImageSrc = VFX_TRUE;
            break;

        case GUI_SSE_SCENARIO_COSMOS_3D_CUBE_EXIT:
            m_effectType = VCP_PAGE_EFFECT_3D_CUBE_FLY_OUT;
            m_duration = VCP_SSE_3D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_BACKWARD;
            m_useImageSrc = VFX_TRUE;
            break;

        case GUI_SSE_SCENARIO_COSMOS_3D_BRICK_ENTER:
            m_effectType = VCP_PAGE_EFFECT_3D_BRICK_FLIP;
            m_duration = VCP_SSE_3D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_LEFT;
            m_useImageSrc = VFX_TRUE;
            break;

        case GUI_SSE_SCENARIO_COSMOS_3D_BRICK_EXIT:
            m_effectType = VCP_PAGE_EFFECT_3D_BRICK_FLIP;
            m_duration = VCP_SSE_3D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_RIGHT;
            m_useImageSrc = VFX_TRUE;
            break;

        case GUI_SSE_SCENARIO_COSMOS_3D_TWIST_ENTER:
            m_effectType = VCP_PAGE_EFFECT_3D_TWIST;
            m_duration = VCP_SSE_3D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_LEFT;
            m_useImageSrc = VFX_TRUE;
            break;

        case GUI_SSE_SCENARIO_COSMOS_3D_TWIST_EXIT:
            m_effectType = VCP_PAGE_EFFECT_3D_TWIST;
            m_duration = VCP_SSE_3D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_RIGHT;
            m_useImageSrc = VFX_TRUE;
            break;
            
        case GUI_SSE_SCENARIO_COSMOS_APP_ENTRY: 
            m_effectType = VCP_PAGE_EFFECT_COSMOS_ENTRY;
            m_duration = VCP_SSE_2D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_LEFT;
            m_useImageSrc = VFX_TRUE;
            break;

        case GUI_SSE_SCENARIO_COSMOS_APP_EXIT:
            m_effectType = VCP_PAGE_EFFECT_COSMOS_ENTRY;
            m_duration = VCP_SSE_2D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_BACKWARD;
            m_useImageSrc = VFX_TRUE;
            break;

        case GUI_SSE_SCENARIO_COSMOS_PAGE_ENTRY:
            m_effectType = VCP_PAGE_EFFECT_PUSH;
            m_duration = VCP_SSE_2D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_RIGHT;
            m_useImageSrc = VFX_FALSE;
            break;

        case GUI_SSE_SCENARIO_COSMOS_PAGE_EXIT:
            m_effectType = VCP_PAGE_EFFECT_PUSH;
            m_duration = VCP_SSE_2D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_LEFT;
            m_useImageSrc = VFX_FALSE;
            break; 

        case GUI_SSE_SCENARIO_COSMOS_MOVE_ENTRY:
            m_effectType = VCP_PAGE_EFFECT_ENTER;
            m_duration = VCP_SSE_2D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_UP;
            m_useImageSrc = VFX_FALSE;
            break;

        case GUI_SSE_SCENARIO_COSMOS_MOVE_EXIT:
            m_effectType = VCP_PAGE_EFFECT_ENTER;
            m_duration = VCP_SSE_2D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_BOTTOM;
            m_useImageSrc = VFX_FALSE;
            break; 

        /* 2D effect */
        case GUI_SSE_SCENARIO_FROM_IDLE:
            m_effectType = VCP_PAGE_EFFECT_ENTER;
            m_duration = VCP_SSE_2D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_BOTTOM;
            m_useImageSrc = VFX_FALSE;
            break;

        case GUI_SSE_SCENARIO_FROM_VENUS_HS_WIDGET:
            m_effectType = VCP_PAGE_EFFECT_FLIP;
            m_duration = VCP_SSE_2D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_RIGHT;
            m_useImageSrc = VFX_FALSE;
            break;

        case GUI_SSE_SCENARIO_FROM_VENUS_HS_SHORTCUT:
            m_effectType = VCP_PAGE_EFFECT_ENTER;
            m_duration = VCP_SSE_2D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_BOTTOM;
            m_useImageSrc = VFX_FALSE;
            break;


    /* main menu */
#if (defined(__CPU_ARM7EJ_S__) || defined(__MMI_VUI_3D_MAINMENU__) || defined(__MMI_VUI_LAUNCHER_KEY__))
        case GUI_SSE_SCENARIO_FROM_MAINMENU:
            m_effectType = VCP_PAGE_EFFECT_ZOOM;
            m_duration = VCP_SSE_2D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_UP;
            m_useImageSrc = VFX_FALSE;
            break;
#else
        case GUI_SSE_SCENARIO_FROM_MAINMENU:
            m_effectType = VCP_PAGE_EFFECT_CUBE;
            m_duration = VCP_SSE_2D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_RIGHT;
            m_useImageSrc = VFX_FALSE;
            break;
            
#endif /* (defined(__CPU_ARM7EJ_S__) || defined(__MMI_VUI_3D_MAINMENU__)) */ 

    /* photowall */
#if defined(__MMI_VUI_MEDIAWALL__)
        case GUI_SSE_SCENARIO_FROM_PHOTOWALL_TO_IMGVIEWER:
            m_effectType = VCP_PAGE_EFFECT_PUSH;
            m_duration = VCP_SSE_2D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_RIGHT;
            m_useImageSrc = VFX_FALSE;
            break;
#endif /* defined(__MMI_VUI_MEDIAWALL__) */

    /* popup */
        case GUI_SSE_SCENARIO_SMALL_SCREEN_IN:
            m_effectType = VCP_PAGE_EFFECT_FADE_IN;
            m_duration = VCP_SSE_2D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_LEFT;
            m_useImageSrc = VFX_FALSE;
            break;

        case GUI_SSE_SCENARIO_SMALL_SCREEN_OUT:
            m_effectType = VCP_PAGE_EFFECT_FADE_IN;
            m_duration = VCP_SSE_2D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_BACKWARD;
            m_useImageSrc = VFX_FALSE;
            break;

        case GUI_SSE_SCENARIO_FTE_DEFAULT_ENTER:
            m_effectType = VCP_PAGE_EFFECT_PUSH;
            m_duration = VCP_SSE_2D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_RIGHT;
            m_useImageSrc = VFX_FALSE;
            break;

        case GUI_SSE_SCENARIO_FTE_DEFAULT_EXIT:
            m_effectType = VCP_PAGE_EFFECT_PUSH;
            m_duration = VCP_SSE_2D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_LEFT;
            m_useImageSrc = VFX_FALSE;
            break;
                   
        default:
            m_effectType = VCP_PAGE_EFFECT_SMALL_FLIP;
            m_duration = VCP_SSE_2D_DEFAULT_DURATION;
            m_direction = VCP_PAGE_DIRECTION_FROM_LEFT;
            m_useImageSrc = VFX_FALSE;
            break;
    }
}   

void VcpSseManager::setupScenario(gui_sse_scenario_enum scenario)
{
    VFX_LOG(VFX_INFO, VCP_SSE_SETUP_SCENARIO_MSG, scenario);
}

void VcpSseManager::runSse()
{
    VFX_LOG(VFX_INFO, VCP_SSE_RUN_SSE_MSG);

    // TODO: need make sure VRT doesn't run at this time here

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SE3", SA_start);
#endif

    setup();

    // prepare two frame;
#if defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__)
    // create context memory; 3D need more memory to create 3D context
    m_mem = (VfxU8*) mmi_frm_asm_alloc_anonymous(70 * 1024);
    if (m_mem == NULL)
    {
        return;
    }
    VFX_OBJ_CREATE(m_context, VfxContext, this);
    m_context->assignPool(m_mem , 70 * 1024);
#endif
    // Special case handling: ask VRT time will reset after screen entering
    vrt_time_reset_time_entered();

    VFX_OBJ_CLOSE(m_oldScreen);

#if defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__)
    VFX_OBJ_CREATE(m_oldScreen, VfxFrame, m_context);
#else
    VFX_OBJ_CREATE(m_oldScreen, VfxFrame, this);
#endif

    VfxU8 *buffer;
    VfxS32 bufferSize;
    gui_screen_switch_effect_get_frame_buffer_info(0, &buffer, &bufferSize);
#ifdef __MMI_REDUCED_UI_BUFFER__
	if(g_vcp_sse_is_forced_cancel == MMI_TRUE)
	{
		return;
	}
    if (!buffer)
	{
	    // m_oldScreenBuf should be created when buildOldScreen
        buffer = m_oldScreenBuf;
    }
    VFX_ASSERT(buffer);
#endif /* __MMI_REDUCED_UI_BUFFER__ */

    m_oldScreenBuilder->onBuildScreen(m_oldScreen, buffer);
    m_oldScreenImageSrc = m_oldScreen->getImgContent();

    VFX_OBJ_CLOSE(m_newScreen);

#if defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__)
    VFX_OBJ_CREATE(m_newScreen, VfxFrame, m_context);
#else
    VFX_OBJ_CREATE(m_newScreen, VfxFrame, this);
#endif

    gui_screen_switch_effect_get_frame_buffer_info(1, &buffer, &bufferSize);
#if defined(__MMI_VUI_ENGINE__) && defined(__MMI_REDUCED_UI_BUFFER__)
    if (m_isPluto)
    {
        if (m_newScreenBuf)
        {
            buffer = m_newScreenBuf;
        }
        else
        {
            buffer = (VfxU8*)mmi_frm_asm_alloc_anonymous(GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE);
            m_newScreenBuf = buffer;
        }        
    }
    VFX_ASSERT(buffer);
#if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
	if (KAL_TRUE == INT_QueryIsCachedRAM((kal_uint32)buffer, GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE))
    {
	    clean_and_invalidate_dcache((kal_uint32)buffer, GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE);
    	buffer = (U8 *)virt_to_phys((void *)buffer);
    }
#endif
#endif /* __MMI_REDUCED_UI_BUFFER__ */

    m_newScreenBuilder->onBuildScreen(m_newScreen, buffer);
    m_newScreenImageSrc = m_newScreen->getImgContent();
    

#if defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__)
    VFX_OBJ_CREATE(m_pagePanel, VcpPagePanel, m_context); 
    addChildFrame(m_pagePanel); 
#else
    VFX_OBJ_CREATE(m_pagePanel, VcpPagePanel, this); 
#endif
    
    vrt_size_struct mainScreenSize;
    vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
    setRect(VfxRect(0, 0, mainScreenSize.width, mainScreenSize.height));

    m_pagePanel->setBounds(0, 0, mainScreenSize.width, mainScreenSize.height);

    buildNewScreen();

    m_pagePanel->addChildFrame(m_oldScreen);
    m_pagePanel->addChildFrame(m_newScreen);

    m_pagePanel->setCurrentFrame(m_oldScreen);

    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    VfxFrame *orgRoot = renderer->getRootFrame();
    if (orgRoot != NULL)
    {
        orgRoot->setOpacity(0.0f);
    }
    
    renderer->pushRootFrame(this);


    // use buffer for speed up on 3D project
    VcpPage3DImageBufferData data;

    if (m_useImageSrc)
    {    
        data.oldImageSrc = m_oldScreenImageSrc;
        data.newImageSrc = m_newScreenImageSrc;
        m_data = &data;
        m_dataSize = sizeof(VcpPage3DImageBufferData);
    }
    //

    m_pagePanel->switchTo(m_newScreen, m_effectType, m_duration, m_direction, VFX_FALSE, m_data, m_dataSize);
    
    renderer->blockAfterNextCommit(m_duration);
    vfx_mmi_update_scene();


    if (m_pagePanel)
    {
        m_pagePanel->setCurrentFrame(m_newScreen);
    }    
    renderer->blockAfterNextCommit(1);
    vfx_mmi_update_scene();


    VFX_LOG(VFX_INFO, VCP_SSE_FINISH_SSE_MSG);
    renderer->popRootFrame();
    closeSse();
    if (orgRoot)
    {
        orgRoot->setOpacity(1.0f);
    }
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SE3", SA_stop);
#endif

#if defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__)
    VFX_OBJ_CLOSE(m_context);
    if (m_mem != NULL)
    {
        mmi_frm_asm_free_anonymous(m_mem);
        m_mem = NULL;
    }
#endif

}


void VcpSseManager::closeSse()
{
    // Temp solution to reset page panel
    if (m_pagePanel)
    {
        m_pagePanel->setCurrentFrame(m_newScreen);
    }
    VFX_OBJ_CLOSE(m_oldScreenBuilder);
    VFX_OBJ_CLOSE(m_newScreenBuilder);
    VFX_OBJ_CLOSE(m_oldScreen);
    VFX_OBJ_CLOSE(m_newScreen);
    VFX_OBJ_CLOSE(m_pagePanel);
#ifdef __MMI_REDUCED_UI_BUFFER__
	if(m_oldScreenBuf)
	{
		applib_mem_ap_cache_free(m_oldScreenBuf);
		m_oldScreenBuf = NULL;
	}
    if (m_newScreenBuf)
    {
        mmi_frm_asm_free_anonymous(m_newScreenBuf);
        m_newScreenBuf = NULL;
    }
    g_vcp_sse_is_forced_cancel = MMI_FALSE;
#endif /* __MMI_REDUCED_UI_BUFFER__ */
    m_data = NULL;
    m_dataSize = 0;
}

#ifdef __MMI_REDUCED_UI_BUFFER__
void VcpSseManager::asm_free_cb(void *mem_ptr)
{
	if(s_instance)
	{
		s_instance->force_cancel((VfxU8 *)mem_ptr);
	}
}

void VcpSseManager::force_cancel(VfxU8 *mem_ptr)
{
      if(m_oldScreenBuf == mem_ptr)
             m_oldScreenBuf = NULL;
      else if (m_newScreenBuf == mem_ptr)  
             m_newScreenBuf = NULL;
      vcpSseUseSingleBufferModeInVRT(VRT_FALSE);
      g_vcp_sse_is_forced_cancel = MMI_TRUE;
}

void VcpSseManager::force_cancel(void)
{
    VFX_OBJ_CLOSE(m_oldScreenBuilder);
    VFX_OBJ_CLOSE(m_newScreenBuilder);
    VFX_OBJ_CLOSE(m_oldScreen);
    VFX_OBJ_CLOSE(m_newScreen);
    VFX_OBJ_CLOSE(m_pagePanel);
		if(m_oldScreenBuf)
		{
			applib_mem_ap_cache_free(m_oldScreenBuf);
			m_oldScreenBuf = NULL;
		}
    if (m_newScreenBuf)
    {
        mmi_frm_asm_free_anonymous(m_newScreenBuf);
        m_newScreenBuf = NULL;
    }
    m_data = NULL;
    m_dataSize = 0;
    vcpSseUseSingleBufferModeInVRT(VRT_FALSE);
    g_vcp_sse_is_forced_cancel = MMI_TRUE;
}

MMI_BOOL vcpSseIsForcedCancel()
{
		return g_vcp_sse_is_forced_cancel;
}
#endif /* __MMI_REDUCED_UI_BUFFER__ */

void VcpSseManager::onInit()
{
    VfxFrame::onInit();

    setBgColor(VRT_COLOR_MAKE(255, 64, 64, 64));
}


void VcpSseManager::buildOldScreen()
{
    VFX_LOG(VFX_INFO, VCP_SSE_BUILD_OLD_SCREEN_MSG);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SE1", SA_start);
#endif

    VfxU8 *buffer;
    VfxS32 bufferSize;
    gui_screen_switch_effect_get_frame_buffer_info(0, &buffer, &bufferSize);
#ifdef __MMI_REDUCED_UI_BUFFER__
	if (!buffer)
	{
	    if (m_oldScreenBuf)
        {
					applib_mem_ap_cache_free(m_oldScreenBuf);
			m_oldScreenBuf = NULL;
        }
            buffer = (VfxU8*)applib_mem_ap_cache_alloc_nc(GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE, &VcpSseManager::asm_free_cb);
            m_oldScreenBuf = buffer;

        if (!buffer)
        {
            // Out of memory. 
            // TODO:abort SSE 
            force_cancel();           
            vcpSseUseSingleBufferModeInVRT(VRT_FALSE);
            return;
        }
        else
        {
          applib_mem_ap_cache_set_priority(buffer, 0);
        #if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
			if (KAL_TRUE == INT_QueryIsCachedRAM((kal_uint32)buffer, GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE))
	        {
        	    clean_and_invalidate_dcache((kal_uint32)buffer, GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE);
            	buffer = (U8 *)virt_to_phys((void *)buffer);     
	        }
        #endif
            vcpSseUseSingleBufferModeInVRT(VRT_TRUE);
        }
	}
#endif /* __MMI_REDUCED_UI_BUFFER__ */
    m_oldScreenBuilder->onSnapshot(buffer);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SE1", SA_stop);
#endif
}


void VcpSseManager::buildNewScreen()
{

    VFX_LOG(VFX_INFO, VCP_SSE_BUILD_NEW_SCREEN_MSG);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SE2", SA_start);
#endif

    VfxU8 *buffer;
    VfxS32 bufferSize;
    gui_screen_switch_effect_get_frame_buffer_info(1, &buffer, &bufferSize);
    // SBL is used in pluto app, when back to cosmos app, buf_b should allocate from ASM
#if defined(__MMI_VUI_ENGINE__) && defined(__MMI_REDUCED_UI_BUFFER__)
    if (m_isPluto)
    {
        if (m_newScreenBuf)
        {
            buffer = m_newScreenBuf;
        }
        else
        {
            buffer = (VfxU8*)applib_mem_ap_cache_alloc_nc(GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE, &VcpSseManager::asm_free_cb);
            m_newScreenBuf = buffer;
        }
        if (!buffer)
        {
            // Out of memory.
            // TODO:abort SSE
            // force_cancel();
            // return;
        }
    #if defined(__MTK_TARGET__) && defined(__DYNAMIC_SWITCH_CACHEABILITY__)
    applib_mem_ap_cache_set_priority(buffer, 0);
		if (KAL_TRUE == INT_QueryIsCachedRAM((kal_uint32)buffer, GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE))
        {
    	    clean_and_invalidate_dcache((kal_uint32)buffer, GUI_SCREEN_SWITCH_EFFECT_MAIN_LCD_BUFFER_SIZE);
        	buffer = (U8 *)virt_to_phys((void *)buffer);
        }
    #endif
    }
#endif
    
    m_newScreenBuilder->onSnapshot(buffer);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("SE2", SA_stop);
#endif
}


vrt_allocator_handle VcpSseManager::getAllocator()
{
    return vfx_sys_mem_get_global_allocator();
}


/***************************************************************************** 
 * Class VcpSseDummyScr
 *****************************************************************************/

class VcpSseDummyScr : public VfxAppCatScr
{
// Constructor / Destructor
public:
    // Default constructor
    VcpSseDummyScr()
    {
        setIsSmallScreen();
    }
};


/***************************************************************************** 
 * ADP for pluto
 *****************************************************************************/

extern "C" void vrt_time_reset(void);

void vcpSseRunSse(void)
{
    // Avoid SSE will run only left 1/3,.
    // Because VRT is suspend at this time, VRT current frame time does not not move.
    vrt_time_reset();

    VcpSseManager *SseManager = VFX_OBJ_GET_INSTANCE(VcpSseManager);
    SseManager->setIsPluto(VFX_FALSE);
    SseManager->runSse();
#ifdef __MMI_REDUCED_UI_BUFFER__
    // VRT render switch back to double-buffer-mode
    if (vcpSseIsVRTinSingleBufferMode())
    {
        vcpSseUseSingleBufferModeInVRT(VRT_FALSE);
        // switch to double buffer mode
        vrt_canvas_switch_render_buffer_mode();
    }
#endif /* __MMI_REDUCED_UI_BUFFER__ */
}

void vcpSseRunSsePluto(void)
{
    VfxU8 *mem = NULL;
#if defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__)
    VfxS32 size = 150 * 1024;
#elif defined(__VENUS_3D_UI_ENGINE__)
    VfxS32 size = 80 * 1024;
#else
    VfxS32 size = 60 * 1024;
#endif
    mem = (VfxU8*) mmi_frm_asm_alloc_anonymous(size);
    if (mem == NULL)
    {
        VFX_LOG(VFX_INFO, VCP_SSE_OUT_OF_MEMORY_MSG);
        return;
    }
    VfxKeypad::sendIncompleteKeyToNewScreen(VFX_TRUE);
    VfxAppCatScr::initalizeWithMem(mem, size);

    VfxScreenEntryCanvasParam entryParam;
    entryParam.flags = 
        VFX_SCREEN_ENTRY_CANVAS_FLAG_WITHOUT_RESET |
        VFX_SCREEN_ENTRY_CANVAS_FLAG_FORBID_MAIN_BASE_LAYER |
        VFX_SCREEN_ENTRY_CANVAS_FLAG_FORBID_GDI_LAYER;
    VfxScreen::entryCanvas(VfxAppCatScr::getContext(), entryParam);
    
    VcpSseManager *SseManager = VFX_OBJ_GET_INSTANCE(VcpSseManager);
    SseManager->setIsPluto(VFX_TRUE);
    SseManager->runSse();
#ifdef __MMI_REDUCED_UI_BUFFER__
    // VRT render switch back to double-buffer-mode
    if (vcpSseIsVRTinSingleBufferMode())
    {
        vcpSseUseSingleBufferModeInVRT(VRT_FALSE);
        // switch to double buffer mode
        vrt_canvas_switch_render_buffer_mode();
    }
#endif /* __MMI_REDUCED_UI_BUFFER__ */

    VfxScreenLeaveCanvasParam leaveParam;
    leaveParam.flags = 
        VFX_SCREEN_LEAVE_CANVAS_FLAG_WITHOUT_RESET |
        VFX_SCREEN_LEAVE_CANVAS_FLAG_FORBID_FLATTEN;
    VfxScreen::leaveCanvas(leaveParam);
    VfxAppCatScr::deinitalize();

    mmi_frm_asm_free_anonymous(mem);
}

void vcpSseBuildOldScreen(void)
{
    VcpSseManager *SseManager = VFX_OBJ_GET_INSTANCE(VcpSseManager);
    SseManager->setup();
    SseManager->buildOldScreen();
}

void vcpSseBuildNewScreen(void)
{
    VcpSseManager *SseManager = VFX_OBJ_GET_INSTANCE(VcpSseManager);
    SseManager->buildNewScreen();
}

void vcpSseSetupScenario(gui_sse_scenario_enum scenario)
{
    VcpSseManager *SseManager = VFX_OBJ_GET_INSTANCE(VcpSseManager);
    SseManager->setupScenario(scenario);
}

void vcpSseReset(void)
{
    VcpSseManager *SseManager = VFX_OBJ_GET_INSTANCE(VcpSseManager);
    SseManager->closeSse();
}

#ifdef __MMI_REDUCED_UI_BUFFER__
/*****************************************************************************
 * FUNCTION
 *	vrt_canvas_set_single_buffer_mode
 * DESCRIPTION
 *	
 * PARAMETERS
 *	vrt_bool state
 * RETURNS
 *	
 *****************************************************************************/
void vcpSseUseSingleBufferModeInVRT(vrt_bool state)
{
	g_vcp_sse_use_vrt_single_buffer_mode = state;
}

/*****************************************************************************
 * FUNCTION
 *	vrt_canvas_is_single_buffer_mode
 * DESCRIPTION
 *	
 * PARAMETERS
 *	vrt_bool state
 * RETURNS
 *	
 *****************************************************************************/
vrt_bool vcpSseIsVRTinSingleBufferMode(void)
{
	return g_vcp_sse_use_vrt_single_buffer_mode;
}
#endif /* __MMI_REDUCED_UI_BUFFER__ */

/***************************************************************************** 
 * setup sse effect
 *****************************************************************************/
static VfxS32 g_vcp_sse_open = 0;

void vcpSseSetupScenarioByApp(mmi_app_package_name_struct appName)
{
#if (defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__))  && defined(__MMI_SCREEN_SWITCH_EFFECT_VENUS__)

    if (g_vcp_sse_open == 1)
    {
        if (strncmp(appName, "native.mtk.musicplayer", MMI_APP_NAME_MAX_LEN) == 0)
        {
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_BLIND, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
            vfx_adp_sse_commit();
        }
        else if (strncmp(appName, "native.mtk.fmradio", MMI_APP_NAME_MAX_LEN) == 0)
        {
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_CIRCLE, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
            vfx_adp_sse_commit();
        }
        else if (strncmp(appName, "native.mtk.calculator", MMI_APP_NAME_MAX_LEN) == 0)
        {
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_CUBE, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
            vfx_adp_sse_commit();
        }
        else if (strncmp(appName, "native.mtk.calendar", MMI_APP_NAME_MAX_LEN) == 0)
        {
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_BRICK, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
            vfx_adp_sse_commit();
        }
        else if (strncmp(appName, "native.mtk.worldclock", MMI_APP_NAME_MAX_LEN) == 0)
        {
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_CIRCLE, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
            vfx_adp_sse_commit();
        }
        else if (strncmp(appName, "native.mtk.setting", MMI_APP_NAME_MAX_LEN) == 0)
        {
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_BLIND, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
            vfx_adp_sse_commit();
        }
        else if (strncmp(appName, "native.mtk.gallery", MMI_APP_NAME_MAX_LEN) == 0)
        {
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_CUBE, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
            vfx_adp_sse_commit();
        }
        else if (strncmp(appName, "native.mtk.fmgr", MMI_APP_NAME_MAX_LEN) == 0)
        {
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_BRICK, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
            vfx_adp_sse_commit();
        }
        else if (strncmp(appName, "native.mtk.contact", MMI_APP_NAME_MAX_LEN) == 0)
        {
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_CIRCLE, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
            vfx_adp_sse_commit();
        }
        else if (strncmp(appName, "native.mtk.soundrec", MMI_APP_NAME_MAX_LEN) == 0)
        {
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_TWIST, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
            vfx_adp_sse_commit();
        }
        else if (strncmp(appName, "native.mtk.vapp_notes", MMI_APP_NAME_MAX_LEN) == 0)
        {
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_TWIST, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
            vfx_adp_sse_commit();
        }
        else if (strncmp(appName, "native.mtk.app_converter", MMI_APP_NAME_MAX_LEN) == 0)
        {
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_BRICK, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
            vfx_adp_sse_commit();
        }
        else if (strncmp(appName, "native.mtk.msg", MMI_APP_NAME_MAX_LEN) == 0)
        {
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_TWIST, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
            vfx_adp_sse_commit();
        }
        else if (strncmp(appName, "native.mtk.dialer", MMI_APP_NAME_MAX_LEN) == 0)
        {
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_CUBE, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
            vfx_adp_sse_commit();
        }
    }

#if defined(__COSMOS_3D_V10__)
    if (strncmp(appName, "native.mtk.app_converter", MMI_APP_NAME_MAX_LEN) == 0)
    {
        vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_CUBE, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
        vfx_adp_sse_commit();
    }
    else if (strncmp(appName, "native.mtk.cnmgr", MMI_APP_NAME_MAX_LEN) == 0)
    {
        vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_CIRCLE, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
        vfx_adp_sse_commit();
    }
    else if (strncmp(appName, "native.mtk.task", MMI_APP_NAME_MAX_LEN) == 0)
    {
        vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_TWIST, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
        vfx_adp_sse_commit();
    }
    else if (strncmp(appName, "native.mtk.appmanager", MMI_APP_NAME_MAX_LEN) == 0)
    {
        vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_BRICK, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
        vfx_adp_sse_commit();
    }
    else if (strncmp(appName, "native.mtk.alarm", MMI_APP_NAME_MAX_LEN) == 0)
    {
        vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_BLIND, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
        vfx_adp_sse_commit();
    }
#else
    if (strncmp(appName, "native.mtk.setting", MMI_APP_NAME_MAX_LEN) == 0)
    {
        vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_CUBE, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
        vfx_adp_sse_commit();
    }
    else if (strncmp(appName, "native.mtk.note", MMI_APP_NAME_MAX_LEN) == 0)
    {
        vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_CIRCLE, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
        vfx_adp_sse_commit();
    }
    else if (strncmp(appName, "native.mtk.todo", MMI_APP_NAME_MAX_LEN) == 0)
    {
        vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_TWIST, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
        vfx_adp_sse_commit();
    }
    else if (strncmp(appName, "native.mtk.sndrec", MMI_APP_NAME_MAX_LEN) == 0)
    {
        vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_BRICK, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
        vfx_adp_sse_commit();
    }
    else if (strncmp(appName, "native.mtk.alarm", MMI_APP_NAME_MAX_LEN) == 0)
    {
        vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_3D_BLIND, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
        vfx_adp_sse_commit();
    }
#endif
#endif
}

void vcpSseSetOpen()
{
    g_vcp_sse_open++;
    g_vcp_sse_open%=2;

#if defined(__MMI_VUI_COSMOS_CP__)
    if (g_vcp_sse_open == 1)
    {
        vcp_global_popup_show_confirm_one_button_str(GRP_ID_ROOT, VCP_POPUP_TYPE_INFO, VFX_WSTR("3D SSE is opened"), VFX_WSTR("ok"), VCP_POPUP_BUTTON_TYPE_NORMAL, NULL, NULL);
    }
    else
    {
        vcp_global_popup_show_confirm_one_button_str(GRP_ID_ROOT, VCP_POPUP_TYPE_INFO, VFX_WSTR("3D SSE is closed"), VFX_WSTR("ok"), VCP_POPUP_BUTTON_TYPE_NORMAL, NULL, NULL);
    }
#endif
}

