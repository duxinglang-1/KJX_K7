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
 *  vapp_hs_widget_fmradio.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: photo album
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
#include "MMI_features.h"
#ifdef __MMI_VUI_HOMESCREEN_FM_RADIO__

#include "vapp_hs_widget_fmradio.h"
#include "vadp_v2p_widget_fmradio.h"
#include "vadp_app_trc.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_input_event.h"
#include "vfx_primitive_frame.h"
#include "vfx_basic_type.h"
#include "gui_typedef.h"
#include "vfx_signal.h"
#include "vapp_hs_widget_base.h"
#include "vfx_string.h"
#include "vfx_weak_ptr.h"
#include "vapp_hs_def.h"
#include "vrt_datatype.h"
#include "vfx_system.h"
/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "gui_touch_feedback.h"
#ifdef __cplusplus
#include "MMIDataType.h"
#include "mmi_rp_app_venus_homescreen_wg_fmradio_def.h"
#include "kal_trace.h"
}
#endif

/*****************************************************************************
 * Class VappHsWidgetFmrButton
 *****************************************************************************/
VFX_IMPLEMENT_CLASS(VAPP_HS_FMR_BUTTON_CLASS_NAME, VappHsWidgetFmrButton, VfxControl);


VappHsWidgetFmrButton::VappHsWidgetFmrButton() : m_image(NULL)
{   
}


VappHsWidgetFmrButton::~VappHsWidgetFmrButton()
{

}

void VappHsWidgetFmrButton::onInit(void)
{
    VfxControl::onInit();

    m_curr_pentype = VFX_PEN_EVENT_TYPE_UP;
    VFX_OBJ_CREATE(m_image, VfxImageFrame, this);
}


void VappHsWidgetFmrButton::onDeinit(void)
{
    VfxControl::onDeinit();
}


void VappHsWidgetFmrButton::setImage(VfxS32 upImage,VfxS32 downImage)
{
    m_imageUpId= upImage;
    m_imageDownId = downImage;

    if (m_curr_pentype == VFX_PEN_EVENT_TYPE_DOWN)
    {
        if (m_image->getResId() != downImage)
        {
            m_image->setResId(downImage);
        }
    }
    else
    {
        if (m_image->getResId() != upImage)
        {
            m_image->setResId(upImage);
        }
    }
    setBounds(m_image->getBounds());
}


void VappHsWidgetFmrButton::setDisplay(VfxBool isDisplay)
{
    if (isDisplay)
    {
        setHidden(VFX_FALSE);
    }
    else
    {
        setHidden(VFX_TRUE);
    }
}


VfxBool VappHsWidgetFmrButton::onPenInput(VfxPenEvent &event)
{
    VfxPoint pos(event.getRelPos(this));
    
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
        m_curr_pentype = VFX_PEN_EVENT_TYPE_DOWN;
        m_image->setResId(m_imageDownId);
        m_eventPenDown.emit(event);
        return VFX_TRUE;
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        m_curr_pentype = VFX_PEN_EVENT_TYPE_UP;
        m_image->setResId(m_imageUpId);
        m_eventPenUp.emit(event);
        return VFX_TRUE;
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        if (containPoint(pos))
        {
            m_curr_pentype = VFX_PEN_EVENT_TYPE_DOWN;
            m_image->setResId(m_imageDownId);
        }
        else
        {
            m_curr_pentype = VFX_PEN_EVENT_TYPE_UP;
            m_image->setResId(m_imageUpId);
        }
        return VFX_TRUE;
    }
    m_curr_pentype = VFX_PEN_EVENT_TYPE_UP;
    return VfxControl::onPenInput(event);
}


/*****************************************************************************
 * Class VappHsWidgetFmr
 *****************************************************************************/
VappHsWidgetFmr::VappHsWidgetFmr() : 
    m_imageBg(NULL),
    m_marqueeText(NULL)
{

}


void VappHsWidgetFmr::onInit()
{   
    VappHsWidget::onInit();
    setBounds(VfxRect(0, 0, 224, 72));
    m_state = STATE_INIT;
    m_curr_show_title = VFX_WSTR_EMPTY;
}

void VappHsWidgetFmr::onDeinit()
{   
    
    VappHsWidget::onDeinit();
}


void VappHsWidgetFmr::onDirectLaunch()
{
    vfxPostInvoke0(this, &VappHsWidgetFmr::launchApp);
}


void VappHsWidgetFmr::launchApp()
{
    vadp_v2p_fmr_launch_app();
}

    
void VappHsWidgetFmr::fmrCallback(void* userdata, VfxU32 result)
{
    VappHsWidgetFmr* this_ptr = (VappHsWidgetFmr*)userdata;

    this_ptr->onStatusChanged(result);
}

void VappHsWidgetFmr::onButtonUp(VfxObjWeakPtr this_ptr)
{   
    if (this_ptr != NULL)
    {
        getState();
        update();
    }
}

void VappHsWidgetFmr::onPrevUp(VfxPenEvent &event)
{
    if (m_butPrev->containPoint(event.getRelPos(m_butPrev)))
    {
        VfxObjWeakPtr this_ptr = this;
        vadp_v2p_fmr_button_process(VAPP_HS_WIDGET_BUTTON_PREV,VAPP_HS_WIDGET_PEN_EVENT_UP);
        onButtonUp(this_ptr);
    }
}


void VappHsWidgetFmr::onNextUp(VfxPenEvent &event)
{
    if (m_butNext->containPoint(event.getRelPos(m_butNext)))
    {
        VfxObjWeakPtr this_ptr = this;
        vadp_v2p_fmr_button_process(VAPP_HS_WIDGET_BUTTON_NEXT,VAPP_HS_WIDGET_PEN_EVENT_UP);
        onButtonUp(this_ptr);
    }
}


void VappHsWidgetFmr::onPlayUp(VfxPenEvent &event)
{
    if (m_butPlay->containPoint(event.getRelPos(m_butPlay)))
    {
        VfxObjWeakPtr this_ptr = this;
        vadp_v2p_fmr_button_process(VAPP_HS_WIDGET_BUTTON_PLAY,VAPP_HS_WIDGET_PEN_EVENT_UP);
        onButtonUp(this_ptr);
    }
}


void VappHsWidgetFmr::onStopUp(VfxPenEvent &event)
{
    if (m_butStop->containPoint(event.getRelPos(m_butStop)))
    {
        VfxObjWeakPtr this_ptr = this;
        vadp_v2p_fmr_button_process(VAPP_HS_WIDGET_BUTTON_STOP,VAPP_HS_WIDGET_PEN_EVENT_UP);
        onButtonUp(this_ptr);
    }
}

void VappHsWidgetFmr::onStatusChanged(VfxU32 result)
{
    VFX_UNUSED(result);
    getState();
    update();
}


void VappHsWidgetFmr::update()
{
    VfxWString temp_title;
    
    m_butPlay->m_eventPenUp.disconnect(this, &VappHsWidgetFmr::onPlayUp);
    m_butStop->m_eventPenUp.disconnect(this, &VappHsWidgetFmr::onStopUp);
    m_butPrev->m_eventPenUp.disconnect(this, &VappHsWidgetFmr::onPrevUp);
    m_butNext->m_eventPenUp.disconnect(this, &VappHsWidgetFmr::onNextUp);

    if (m_state == STATE_INIT || m_state == STATE_READY)
    {
        temp_title = VFX_WSTR_MEM((const U16*)getTitle());
        
        m_butPlay->setDisplay(VFX_TRUE);
        m_butStop->setDisplay(VFX_FALSE);
        
        m_butPlay->m_eventPenUp.connect(this, &VappHsWidgetFmr::onPlayUp);
        m_butStop->m_eventPenUp.disconnect(this, &VappHsWidgetFmr::onStopUp);
        m_butPrev->m_eventPenUp.connect(this, &VappHsWidgetFmr::onPrevUp);
        m_butNext->m_eventPenUp.connect(this, &VappHsWidgetFmr::onNextUp);
    }
    else if (m_state == STATE_PLAY || m_state == STATE_PLAY_NO_LIST)
    {       
        temp_title = VFX_WSTR_MEM((const U16*)getTitle());
        
        m_butPlay->setDisplay(VFX_FALSE);
        m_butStop->setDisplay(VFX_TRUE);
        
        m_butPlay->m_eventPenUp.disconnect(this, &VappHsWidgetFmr::onPlayUp);
        m_butStop->m_eventPenUp.connect(this, &VappHsWidgetFmr::onStopUp);
        m_butPrev->m_eventPenUp.connect(this, &VappHsWidgetFmr::onPrevUp);
        m_butNext->m_eventPenUp.connect(this, &VappHsWidgetFmr::onNextUp);
    }
    else if (m_state == STATE_SEARCHING)
    {
        temp_title = VFX_WSTR_MEM((const U16*)getTitle());

        m_butPlay->setDisplay(VFX_TRUE);
        m_butStop->setDisplay(VFX_FALSE);
    }

    if (m_state == STATE_SEARCHING)
    {
        m_butPrev->setImage(VAPP_HS_IMG_WG_FMR_PREV_DISABLE, VAPP_HS_IMG_WG_FMR_PREV_DISABLE);      
        m_butPlay->setImage(VAPP_HS_IMG_WG_FMR_PLAY_DISABLE, VAPP_HS_IMG_WG_FMR_PLAY_DISABLE);
        m_butNext->setImage(VAPP_HS_IMG_WG_FMR_NEXT_DISABLE, VAPP_HS_IMG_WG_FMR_NEXT_DISABLE);
    }
    else
    {
        m_butPrev->setImage(VAPP_HS_IMG_WG_FMR_PREV_UP, VAPP_HS_IMG_WG_FMR_PREV_DOWN);      
        m_butPlay->setImage(VAPP_HS_IMG_WG_FMR_PLAY_UP, VAPP_HS_IMG_WG_FMR_PLAY_DOWN);
        m_butStop->setImage(VAPP_HS_IMG_WG_FMR_STOP_UP, VAPP_HS_IMG_WG_FMR_STOP_DOWN);
        m_butNext->setImage(VAPP_HS_IMG_WG_FMR_NEXT_UP, VAPP_HS_IMG_WG_FMR_NEXT_DOWN);
    }

    if (m_state == STATE_INIT || 
        m_state == STATE_READY || 
        m_state == STATE_PLAY || 
        m_state == STATE_PLAY_NO_LIST || 
        m_state == STATE_SEARCHING)
    {
        if (temp_title != m_curr_show_title)
        {
            m_curr_show_title = temp_title;
            m_marqueeText->setMovableFrame(m_curr_show_title, VFX_FONT_DESC_SMALL);
            m_marqueeText->startScroll();
        }   
    }

}


void VappHsWidgetFmr::getState()
{
    VfxU8 state;
    
    vadp_v2p_fmr_get_info(VAPP_HS_WIDGET_FMR_INFO_STATE, &state);
    m_state = (VfxU32)state;

    VFX_LOG(VFX_INFO, VAPP_HS_FMR_GET_STATE_MSG, m_state);
}


VfxS16 VappHsWidgetFmr::getChannelNum()
{
    vadp_v2p_fmr_get_info(VAPP_HS_WIDGET_FMR_INFO_CH_NUM,&m_channelNum);
    VFX_LOG(VFX_INFO, VAPP_HS_FMR_GET_CHNUM_MSG, m_channelNum);
    
    return m_channelNum;
}


VfxChar* VappHsWidgetFmr::getTitle(void)
{
    VfxU8* title_ptr;
    
    vadp_v2p_fmr_get_info(VAPP_HS_WIDGET_FMR_INFO_CH_TITLE,&title_ptr);

    vadp_v2p_fmr_copy_title(m_title, title_ptr);
    
    return m_title;
}

VfxU16 VappHsWidgetFmr::getIcon()
{
    return VAPP_HS_IMG_WG_ICON_FMR;
}

VfxU16 VappHsWidgetFmr::getName()
{
    return VAPP_HS_STR_WG_FM_RADIO;
}

void VappHsWidgetFmr::onCreateView()
{
    m_curr_show_title = VFX_WSTR_EMPTY;
    VFX_OBJ_CREATE(m_imageBg, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_marqueeText, VcpMarquee, this);    
    VFX_OBJ_CREATE(m_butPrev, VappHsWidgetFmrButton, this);
    VFX_OBJ_CREATE(m_butPlay, VappHsWidgetFmrButton, this);
    VFX_OBJ_CREATE(m_butNext, VappHsWidgetFmrButton, this);
    VFX_OBJ_CREATE(m_butStop, VappHsWidgetFmrButton, this);
    
    m_imageBg->setResId(VAPP_HS_IMG_WG_FMR_BG);
    setBounds(m_imageBg->getBounds());
#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    m_imageBg->setIsOpaque(VFX_TRUE);
    setIsOpaque(VFX_TRUE);
#endif /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */
    setIsCached(VFX_FALSE);
    m_marqueeText->setPos(VfxPoint(TITLE_START_OFFSET_X,TITLE_START_OFFSET_Y));
    m_marqueeText->setBounds(VfxRect(
                                            0, 
                                            0, 
                                            TITLE_END_OFFSET_X - TITLE_START_OFFSET_X, 
                                            TITLE_END_OFFSET_Y - TITLE_START_OFFSET_Y));
    m_marqueeText->setHalign(VcpMarquee::HALIGN_CENTER);
    m_marqueeText->setValign(VcpMarquee::VALIGN_CENTER);
    m_marqueeText->setSpeed(VcpMarquee::DEFAULT_SPEED / 3);
    
    m_butPrev->setPos(VfxPoint(BUTTON_PREV_OFFSET_X, BUTTON_PREV_OFFSET_Y));
    m_butPlay->setPos(VfxPoint(BUTTON_PLAY_OFFSET_X, BUTTON_PLAY_OFFSET_Y));
    m_butStop->setPos(VfxPoint(BUTTON_STOP_OFFSET_X, BUTTON_STOP_OFFSET_Y));
    m_butNext->setPos(VfxPoint(BUTTON_NEXT_OFFSET_X, BUTTON_NEXT_OFFSET_Y)); 
    m_butPrev->setImage(VAPP_HS_IMG_WG_FMR_PREV_UP, VAPP_HS_IMG_WG_FMR_PREV_DOWN);      
    m_butPlay->setImage(VAPP_HS_IMG_WG_FMR_PLAY_UP, VAPP_HS_IMG_WG_FMR_PLAY_DOWN);
    m_butStop->setImage(VAPP_HS_IMG_WG_FMR_STOP_UP, VAPP_HS_IMG_WG_FMR_STOP_DOWN);
    m_butNext->setImage(VAPP_HS_IMG_WG_FMR_NEXT_UP, VAPP_HS_IMG_WG_FMR_NEXT_DOWN);
        
    vadp_v2p_fmr_register_callback(this, fmrCallback);
    
    getState();
    update();
}


void VappHsWidgetFmr::onReleaseView()
{
    vadp_v2p_fmr_deregister_callback();
    
    m_butPlay->m_eventPenUp.disconnect(this, &VappHsWidgetFmr::onPlayUp);
    m_butStop->m_eventPenUp.disconnect(this, &VappHsWidgetFmr::onStopUp);
    m_butPrev->m_eventPenUp.disconnect(this, &VappHsWidgetFmr::onPrevUp);
    m_butNext->m_eventPenUp.disconnect(this, &VappHsWidgetFmr::onNextUp);
        
    VFX_OBJ_CLOSE(m_butNext);
    VFX_OBJ_CLOSE(m_butStop);
    VFX_OBJ_CLOSE(m_butPlay);
    VFX_OBJ_CLOSE(m_butPrev);
    VFX_OBJ_CLOSE(m_marqueeText);
    VFX_OBJ_CLOSE(m_imageBg);
    m_curr_show_title = VFX_WSTR_EMPTY;
}
#endif /* __MMI_VUI_HOMESCREEN_FM_RADIO__ */
