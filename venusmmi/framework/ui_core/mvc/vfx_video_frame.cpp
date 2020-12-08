/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vfx_video_frame.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Description
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
#include "vfx_video_frame.h"
#include "ui_core\base\vfx_base.h"
#include "vfx_timer.h"
#include "vfx_control.h"
#include "vfx_screen.h"
#include "vfx_top_level.h"
#include "vfx_draw_context.h"
#include "vfx_frame_filter.h"
#include "vfx_animation.h"
#include "vfx_auto_animate.h"
#include "vfx_renderer.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include "lcd_if.h"
#include "gdi_include.h"
#include "mdi_datatype.h"
#include "mdi_include.h"

extern void vrt_register_video_callback(vrt_sys_video_layer_index_enum index, void (*callback)(void *), void *arg);
extern gdi_handle vrt_get_blt_layer(void);
extern void vrt_set_video_layer_ext(vrt_sys_video_layer_index_enum index, gdi_handle layer, vrt_s32 order, vrt_bool is_video, vrt_u32 flag);

extern BOOL gdi_lcd_get_high_priority_freeze(void);

#ifdef __cplusplus
}
#endif
/***************************************************************************** 
 * Class VfxVideoFrame
 *****************************************************************************/
 
VFX_IMPLEMENT_CLASS(VFX_VIDEOFRAME_CLASS_NAME, VfxVideoFrame, VfxFrame);

VfxS32 VfxVideoFrame::m_videoLayerCount = 0;

VfxVideoFrame::VfxVideoFrame() : 
    m_multimediaType(MULTIMEDIA_NULL),
    m_buffer(NULL),
    m_bufferSize(0),
    m_rotateAngle(0),
    m_colorFormat(VRT_COLOR_TYPE_RGB565),
    m_layerHandle(0),
    m_appID(0),
    m_index(-1),
    m_isAnimation(VFX_FALSE),
    m_isReady(VFX_FALSE),
    m_playReadyTimer(NULL),
    m_hint(HINT_NONE)
{
}


VfxVideoFrame::~VfxVideoFrame()
{
}


void VfxVideoFrame::setMultimediaType(MultimediaTypeEnum value)
{
    m_multimediaType = value;
}


void VfxVideoFrame::setIsAnimation(VfxBool value)
{
    m_isAnimation = value;
    
    // TODO: call canvas to inform the videoframe need to change LT path 
}


void VfxVideoFrame::setColorFormat(vrt_color_type_enum colorFormat)
{
    if (m_layerHandle)
    {
        VfxU8 gdi_color_format = GDI_COLOR_FORMAT_16;

        if (colorFormat == VRT_COLOR_TYPE_RGB565)
            gdi_color_format = GDI_COLOR_FORMAT_16;
        else if (colorFormat == VRT_COLOR_TYPE_UYVY422)
            gdi_color_format = GDI_COLOR_FORMAT_UYVY422;
        else if (colorFormat == VRT_COLOR_TYPE_ARGB8888)
            gdi_color_format = GDI_COLOR_FORMAT_32;   
        else if (colorFormat == VRT_COLOR_TYPE_PARGB8888)
            gdi_color_format = GDI_COLOR_FORMAT_32_PARGB;
    
        gdi_layer_push_and_set_active(m_layerHandle);
        gdi_layer_set_color_format(gdi_color_format);
        gdi_layer_pop_and_restore_active();
    }
    m_colorFormat = colorFormat;
}

    
VfxBool VfxVideoFrame::prepare()
{
    if (m_videoLayerCount >= 2 && m_multimediaType != MULTIMEDIA_NULL)
    {
        VFX_ASSERT(0);
    }

    if (VFX_OBJ_GET_INSTANCE(VfxTopLevel))
    {
		VfxPoint pos;
        mdi_util_create_hw_layer_in_struct inStruct;
        mdi_util_create_hw_layer_out_struct outStruct;

        VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->mustShowNextFrame();

        // convert frame top-left point (0, 0) to LCD coordinate
        pos = convertPointTo(VfxPoint(0, 0), VFX_OBJ_GET_INSTANCE(VfxTopLevel));

        VfxU8 gdi_color_format = GDI_COLOR_FORMAT_16;

        if (m_colorFormat == VRT_COLOR_TYPE_RGB565)
            gdi_color_format = GDI_COLOR_FORMAT_16;
        else if (m_colorFormat == VRT_COLOR_TYPE_UYVY422)
            gdi_color_format = GDI_COLOR_FORMAT_UYVY422;
        else if (m_colorFormat == VRT_COLOR_TYPE_ARGB8888)
            gdi_color_format = GDI_COLOR_FORMAT_32;   
        else if (m_colorFormat == VRT_COLOR_TYPE_PARGB8888)
            gdi_color_format = GDI_COLOR_FORMAT_32_PARGB;
        
        inStruct.offset_x = pos.x;
        inStruct.offset_y = pos.y;
        inStruct.width = getSize().width;
        inStruct.height = getSize().height;
        inStruct.app_id = m_appID;
        inStruct.color_format = gdi_color_format;
        inStruct.scenario_id = (mdi_multimedia_scenario_enum)m_multimediaType;
  
        m_layerHandle = mdi_util_hw_layer_create(&inStruct, &outStruct);         

        if (m_layerHandle)
        {
            VfxFrame *f;            

            m_isReady = VFX_TRUE;
            m_videoLayerCount++;

            if (m_videoLayerCount == 1)
            {
                m_index = 0;                    

                // adjust video frame order to scene graph order for VT
                for (f = getPrevFrame(); f; f = f->getPrevFrame())
                {
                    if (f->isKindOf(VFX_OBJ_CLASS_INFO(VfxVideoFrame)))
                    {
                        m_index = 1;
                        break;
                    }                    
                }                    
            }                    
            else if (m_videoLayerCount == 2)
            {
                m_index = 1;
                
                // adjust video frame order to scene graph order for VT
                for (f = getNextFrame(); f; f = f->getNextFrame())
                {
                    if (f->isKindOf(VFX_OBJ_CLASS_INFO(VfxVideoFrame)))
                    {
                        m_index = 0;
                        break;
                    }                    
                }                                        
            }                    
            else
            {                
                m_index = 2;
            }

            if (getHidden())
            {
                gdi_layer_push_and_set_active(m_layerHandle);
                gdi_layer_set_opacity(TRUE, 0);
                gdi_layer_pop_and_restore_active();
            }            
        }
        else
        {
            return VFX_FALSE;
        }
        
        VfxFrame::setLayerHandle((VfxU32)m_layerHandle);
        		
        vrt_set_video_layer_ext((vrt_sys_video_layer_index_enum)(m_index), m_layerHandle, m_index, VRT_TRUE, (vrt_u32)getHint());

        // register video callback if someone connects the play ready signal.
        if (m_signalPlayReady.getSlotCount() > 0)
        {
            vrt_register_video_callback(
                (vrt_sys_video_layer_index_enum)(m_index), 
                (void (*)(void *))vrtPlayCallback,
                (void*)VfxObject::getObjHandle());
        }

        // must set blt layer for DDv2 element config
        if (m_layerHandle)
        {
            gdi_handle layer[4];
            VfxS32 i;

            VFX_ASSERT((m_index >= 0) && (m_index < 4));
            
            gdi_layer_get_blt_layer(&layer[0], &layer[1], &layer[2], &layer[3]);                      
            for (i = 0; i < 4; i++)
            {
                if (layer[i] && !(((gdi_layer_struct*)layer[i]) -> flag & 1))
                {
                    layer[i] = GDI_NULL_HANDLE;
                }
            }
            layer[m_index] = m_layerHandle;
            gdi_layer_set_blt_layer(layer[0], layer[1], layer[2], layer[3]);            

            invalidate();

            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


void VfxVideoFrame::unPrepare()
{
    if (m_isReady)
    {
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->mustShowNextFrame();
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->waitForRenderingComplete();

        if (m_playReadyTimer)
        {
            m_playReadyTimer->stop();
        }

        if (m_layerHandle)
        {
            gdi_handle layer[4];
            VfxS32 i;
            
            gdi_layer_get_blt_layer(&layer[0], &layer[1], &layer[2], &layer[3]);                      
            for (i = 0; i < 4; i++)
            {
                if (layer[i] && !(((gdi_layer_struct*)layer[i]) -> flag & 1))
                {
                    layer[i] = GDI_NULL_HANDLE;
                }
                
                if (layer[i] == m_layerHandle)
                {
                    layer[i] = GDI_NULL_HANDLE;
                }
            }
            
            gdi_layer_set_blt_layer(layer[0], layer[1], layer[2], layer[3]);            
        }

        VfxFrame::setLayerHandle(0);
        mdi_util_hw_layer_free(m_layerHandle);

        m_layerHandle = NULL;
        m_isReady = VFX_FALSE;
        m_videoLayerCount--;

        vrt_set_video_layer_ext((vrt_sys_video_layer_index_enum)m_index, GDI_LAYER_EMPTY_HANDLE, m_index, VRT_TRUE, (vrt_u32)getHint());

        invalidate();
        
        if (m_videoLayerCount < 0)
            VFX_ASSERT(0);
    }
}


VfxU32 VfxVideoFrame::getLayerHandle()
{
   return m_layerHandle;
}


VfxU32 VfxVideoFrame::getDisplayLayerFlag()
{
    VfxU32 bltFlag;

    // bltFlag = (getHwLayerFlag() | vrt_get_blt_layer());
    
    m_videoLayerCount++;
    bltFlag = getHwLayerFlag();
    m_videoLayerCount--;

    return bltFlag;
}


VfxU32 VfxVideoFrame::getHwLayerFlag()
{
    VfxU32 hwFlag = GDI_LAYER_ENABLE_LAYER_0;

    switch (m_index)
    {
        case 0:
          hwFlag = GDI_LAYER_ENABLE_LAYER_0;
          break;

        case 1:
          hwFlag = GDI_LAYER_ENABLE_LAYER_1;
          break;
          
        case 2:
          hwFlag = GDI_LAYER_ENABLE_LAYER_2;
          break;            

        case 3:
          hwFlag = GDI_LAYER_ENABLE_LAYER_3;
          break;
    #ifdef GDI_6_LAYERS
        case 4:
          hwFlag = GDI_LAYER_ENABLE_LAYER_4;
          break;
          
        case 5:
          hwFlag = GDI_LAYER_ENABLE_LAYER_5;
          break;
    #endif          
        default:
            VFX_ASSERT(0);        
    }

    return hwFlag;
}


VfxU32 VfxVideoFrame::getColorFormat()
{
    return 0;
}


void VfxVideoFrame::setHidden(VfxBool value)
{
    if (m_layerHandle)
    {
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->waitForRenderingComplete();
        
        gdi_layer_push_and_set_active(m_layerHandle);

        if (value)
        {
            vrt_set_video_layer_ext((vrt_sys_video_layer_index_enum)m_index, GDI_LAYER_EMPTY_HANDLE, m_index, VRT_TRUE, (vrt_u32)getHint());
            VfxFrame::setLayerHandle(0);            
            gdi_layer_set_opacity(TRUE, 0);
        }        
        else
        {
            vrt_set_video_layer_ext((vrt_sys_video_layer_index_enum)m_index, m_layerHandle, m_index, VRT_TRUE, (vrt_u32)getHint());
            VfxFrame::setLayerHandle((VfxU32)m_layerHandle);
            gdi_layer_set_opacity(TRUE, 255);
        }
                
        gdi_layer_pop_and_restore_active();        
    }        

    VfxFrame::setHidden(value);    
}


void VfxVideoFrame::onDeinit()
{
    unPrepare();
    
    if (m_playReadyTimer)
    {
        VFX_OBJ_CLOSE(m_playReadyTimer);
    }

    VfxFrame::onDeinit();
}


void VfxVideoFrame::bringToFront()
{    
    VfxFrame::bringToFront();
}

void VfxVideoFrame::vrtPlayCallback(void *userdata)
{
    VFX_DEV_ASSERT(userdata != NULL);

    VfxVideoFrame *frame = (VfxVideoFrame*)VfxObject::handleToObject((VfxObjHandle)userdata);
    if (frame == NULL)
    {
        return;
    }

    vfxPostInvoke0(frame, &VfxVideoFrame::playCallback);
}


void VfxVideoFrame::playCallback()
{
    if (m_isReady)
    {
        if (m_playReadyTimer == NULL)
        {
            VFX_OBJ_CREATE(m_playReadyTimer, VfxTimer, this);
        }

        /*
         * use timer 1ms to make sure the play ready is emitted in the next frame since
         * first screen enter will possibly check update after the first frame is drawn
         * but the LCD is freezed. If hw update is activated in this moment, the display
         * may show video layer content before the anti-blinking gdi blt or small screen 
         * background redraw
         */
        if (gdi_lcd_get_high_priority_freeze() || gdi_lcd_get_freeze())
        {   // TODO: use a better way to detect antiblinking instead of gdi lcd high freeze
            m_playReadyTimer->setStartDelay(1);
        }
        else
        {         
            m_playReadyTimer->setStartDelay(0);
        }
        
        m_playReadyTimer->setDuration(0);
        m_playReadyTimer->m_signalTick.connect(this, &VfxVideoFrame::onPlayReadyTimerTick);
        m_playReadyTimer->start();
    }        
}


void VfxVideoFrame::onPlayReadyTimerTick(VfxTimer *source)
{
	VFX_UNUSED(source);

    if (m_isReady)
    {
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->waitForRenderingComplete();
        m_signalPlayReady.emit();
    }        
}


