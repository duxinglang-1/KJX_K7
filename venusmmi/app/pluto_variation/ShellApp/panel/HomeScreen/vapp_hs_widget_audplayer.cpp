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
 *  vapp_hs_widget_audplayer.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: audplayer
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
#ifdef __MMI_VUI_HOMESCREEN_AUDIO_PLAYER__
#include "vapp_hs_widget_audplayer.h"
#include "MediaAppWidgetDef.h"
#include "vadp_v2p_widget_audplayer.h"
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
#include "vfx_signal.h"
#include "vfx_frame.h"
#include "vfx_draw_context.h"
#include "vrt_system.h"
#include "vapp_hs_widget_base.h"
#include "vfx_string.h"
#include "vfx_timer.h"
#include "vfx_weak_ptr.h"
#include "vapp_hs_def.h"
#include "vfx_renderer.h"
#include "vrt_canvas.h"
#include "vrt_datatype.h"
#include "vfx_system.h"
#include "vcp_marquee.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "ConnectivityResDef.h"
#ifdef __MMI_USB_SUPPORT__
 #include "USBSrvGProt.h"
#endif
#include "gui_touch_feedback.h"
#include "gui_typedef.h"
#if !defined(__COSMOS_MMI__)
#include "mmi_rp_app_usbmmi_def.h"
#endif
#include "mmi_rp_app_venus_homescreen_wg_audioplayer_def.h"
#include "MMIDataType.h"
#include "kal_trace.h"
#include "GlobalResDef.h"
#ifdef __cplusplus
}
#endif

/*****************************************************************************
 * Class VappHsWidgetAudplayerButton
 *****************************************************************************/
VFX_IMPLEMENT_CLASS(VAPP_HS_AUDPLAYER_BUTTON_CLASS_NAME, VappHsWidgetAudplayerButton, VfxControl);


VappHsWidgetAudplayerButton::VappHsWidgetAudplayerButton() : m_image(NULL)
{   
}


VappHsWidgetAudplayerButton::~VappHsWidgetAudplayerButton()
{

}

void VappHsWidgetAudplayerButton::onInit(void)
{
    VfxControl::onInit();
    
    m_curr_pentype = VFX_PEN_EVENT_TYPE_UP;
    VFX_OBJ_CREATE(m_image, VfxImageFrame, this);
}


void VappHsWidgetAudplayerButton::onDeinit(void)
{
    VfxControl::onDeinit();
}


void VappHsWidgetAudplayerButton::setImage(VfxS32 upImage,VfxS32 downImage)
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


void VappHsWidgetAudplayerButton::setDisplay(VfxBool isDisplay)
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


VfxBool VappHsWidgetAudplayerButton::onPenInput(VfxPenEvent &event)
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


VfxS32 VappHsWidgetAudplayerButton::getPenType(void)
{
    return m_curr_pentype;
}


void VappHsWidgetAudplayerButton::setPenType(VfxS32 PenType)
{
    m_curr_pentype = PenType;
}


/*****************************************************************************
 * Class VappHsWidgetAudplayerProgress
 *****************************************************************************/
VFX_IMPLEMENT_CLASS(VAPP_HS_AUDPLAYER_PROGRESS_CLASS_NAME, VappHsWidgetAudplayerProgress, VfxImageFrame);


VappHsWidgetAudplayerProgress::VappHsWidgetAudplayerProgress() : m_ratio(0)
{

}


VappHsWidgetAudplayerProgress::~VappHsWidgetAudplayerProgress()
{

}


void VappHsWidgetAudplayerProgress::onInit()
{
    VfxFrame::onInit();

    VFX_OBJ_CREATE(m_imageBg, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_imageFg, VfxImageFrame, this);
}


void VappHsWidgetAudplayerProgress::onDeinit()
{   
    VfxFrame::onDeinit();
}


void VappHsWidgetAudplayerProgress::onDraw(VfxDrawContext &dc)
{
    VfxRect size;
    VfxS32 progress_width;

    size = m_imageBg->getBounds();
    progress_width = (size.getWidth()* m_ratio)/100;
    
    dc.setClip(VfxRect(0, 0, size.getWidth(), size.getHeight()));
    dc.drawImageFromMem(0, 0, (const void*)vrt_sys_res_image_lock(m_imageBgId));
    
    dc.setClip(VfxRect(0, 0,progress_width, size.getHeight()));
    dc.drawImageFromMem(0, 0, (const void*)vrt_sys_res_image_lock(m_imageFgId));
}


void VappHsWidgetAudplayerProgress::setRatio(VfxS32 ratio)
{
    m_ratio = ratio;
    invalidate();
}


VfxS32 VappHsWidgetAudplayerProgress::getRatio(void) const
{
    return m_ratio;
}


void VappHsWidgetAudplayerProgress::setImage(VfxS32 bgImage,VfxS32 fgImage)
{
    m_imageFgId = fgImage;
    m_imageBgId = bgImage;

    m_imageFg->setResId(fgImage);
    m_imageBg->setResId(bgImage);
    
    setBounds(m_imageBg->getBounds()); 
}


/*****************************************************************************
 * Class VappHsWidgetAudplayerTime
 *****************************************************************************/
VFX_IMPLEMENT_CLASS(VAPP_HS_AUDPLAYER_TIME_CLASS_NAME, VappHsWidgetAudplayerTime, VfxImageFrame);


VappHsWidgetAudplayerTime::VappHsWidgetAudplayerTime()
{
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
#endif
}


VappHsWidgetAudplayerTime::~VappHsWidgetAudplayerTime()
{

}


void VappHsWidgetAudplayerTime::onInit()
{
    VfxImageFrame::onInit();

    setBounds(VfxRect(0, 0, 50, 10));
    
    m_hour = 0;
    m_min = 0;
    m_sec = 0;

    VFX_OBJ_CREATE(m_imageH1, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_imageH2, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_imageColon_1, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_imageM1, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_imageM2, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_imageColon_2, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_imageS1, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_imageS2, VfxImageFrame, this);
    
}

void VappHsWidgetAudplayerTime::onDeinit()
{
    VfxImageFrame::onDeinit();
}


void VappHsWidgetAudplayerTime::layout()
{
    VfxRect num_size;
    VfxRect colon_size;
    VfxS32 offsetX;

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
#endif
    {
        m_imageH1->setResId(m_imageNum0Id);
        m_imageColon_1->setResId(m_imageColonId);
        m_imageColon_2->setResId(m_imageColonId);

        num_size = m_imageH1->getBounds();
        colon_size = m_imageColon_1->getBounds();

        offsetX = 0;
        m_imageH1->setPos(VfxPoint(offsetX, 0));
        offsetX = offsetX + num_size.getWidth();
        m_imageH2->setPos(VfxPoint(offsetX, 0));
        offsetX = offsetX + num_size.getWidth();
        m_imageColon_1->setPos(VfxPoint(offsetX, 0));
        

        offsetX = offsetX + colon_size.getWidth();
        m_imageM1->setPos(VfxPoint(offsetX, 0));
        offsetX = offsetX + num_size.getWidth();
        m_imageM2->setPos(VfxPoint(offsetX, 0));
        offsetX = offsetX + num_size.getWidth(); 
        m_imageColon_2->setPos(VfxPoint(offsetX ,0));

        offsetX = offsetX + colon_size.getWidth();
        m_imageS1->setPos(VfxPoint(offsetX ,0));
        offsetX = offsetX + num_size.getWidth();
        m_imageS2->setPos(VfxPoint(offsetX,0));     
    }


}


void VappHsWidgetAudplayerTime::setTime(VfxS32 hour, VfxS32 min, VfxS32 sec)
{
    VfxS32 h1 = 0;
    VfxS32 h2 = 0;
    VfxS32 m1 = 0;
    VfxS32 m2 = 0;
    VfxS32 s1 = 0;
    VfxS32 s2 = 0;
    
    m_hour = hour;
    m_min = min;
    m_sec = sec;

    layout();
    
    h1 = m_hour/10;
    h2 = m_hour%10;
    m1 = m_min/10;
    m2 = m_min%10;
    s1 = m_sec/10;
    s2 = m_sec%10;  

    m_imageH1->setResId(m_imageNum0Id + h1);
    m_imageH2->setResId(m_imageNum0Id + h2);
    m_imageM1->setResId(m_imageNum0Id + m1);
    m_imageM2->setResId(m_imageNum0Id + m2);
    m_imageS1->setResId(m_imageNum0Id + s1);
    m_imageS2->setResId(m_imageNum0Id + s2);    
}

void VappHsWidgetAudplayerTime::setTime(VfxU64 msec)
{
    VfxS64 totol_secs = msec / 1000;
    VfxS32 hour;
    VfxS32 hour_remain;
    VfxS32 min;
    VfxS32 sec;
    VfxS32 h1 = 0;
    VfxS32 h2 = 0;
    VfxS32 m1 = 0;
    VfxS32 m2 = 0;
    VfxS32 s1 = 0;
    VfxS32 s2 = 0;
    
    hour = totol_secs / 3600;
    hour_remain = totol_secs % 3600;
    min = hour_remain / 60;
    sec = hour_remain % 60; 

    m_hour = hour;
    m_min = min;
    m_sec = sec;    

    layout();
    
    h1 = m_hour/10;
    h2 = m_hour%10;
    m1 = m_min/10;
    m2 = m_min%10;
    s1 = m_sec/10;
    s2 = m_sec%10;  

    m_imageH1->setResId(m_imageNum0Id + h1);
    m_imageH2->setResId(m_imageNum0Id + h2);
    m_imageM1->setResId(m_imageNum0Id + m1);
    m_imageM2->setResId(m_imageNum0Id + m2);
    m_imageS1->setResId(m_imageNum0Id + s1);
    m_imageS2->setResId(m_imageNum0Id + s2);    

}


void VappHsWidgetAudplayerTime::getTime(VfxS32* hourP, VfxS32* minP, VfxS32* secP)
{
    *hourP = m_hour;
    *minP = m_min;
    *secP = m_sec;
}


/*****************************************************************************
 * Class VappHsWidgetAudplayer
 *****************************************************************************/
VappHsWidgetAudplayer::VappHsWidgetAudplayer() : 
    m_marqueeText(NULL),
    m_imageBg(NULL)
{
    
}

void VappHsWidgetAudplayer::audplayerCallback(void* userdata, VfxU32 type, void* resultP)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappHsWidgetAudplayer* this_ptr = (VappHsWidgetAudplayer*) userdata;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == MMI_WIDGET_PLAYER_STATUS_CHANGE_CALLBACK)
    {
        this_ptr->onStatusChanged(resultP);
    }
    else if (type == MMI_WIDGET_PLAYER_MEDIA_CHANGE_CALLBACK)
    {
        this_ptr->onMediaChanged(resultP);
    }
    else if (type == MMI_WIDGET_PLAYER_PLAY_END_CALLBACK)
    {
        this_ptr->onPlayEnd(resultP);
    }
    else if (type == MMI_WIDTET_PLAYER_RESET_TIME_CALLBACK)
    {
        this_ptr->onResetTime(resultP);
    }
    
}


void VappHsWidgetAudplayer::onInit()
{   
    VappHsWidget::onInit();

    setBounds(VfxRect(0, 0, 224, 72));
    m_state = STATE_INIT;
    m_isTimerStart = VFX_FALSE;
    m_curr_show_title = VFX_WSTR_EMPTY;
    m_isRescrollText = VFX_FALSE;
        
    VFX_OBJ_CREATE(m_timer, VfxTimer, this);

}


void VappHsWidgetAudplayer::onDeinit()
{
    
    if (m_timer->getIsEnabled())
    {
        m_timer->stop();
    }
    
    VappHsWidget::onDeinit();
}


void VappHsWidgetAudplayer::onDirectLaunch()
{
    vfxPostInvoke0(this, &VappHsWidgetAudplayer::launchApp);
}


void VappHsWidgetAudplayer::launchApp()
{
    vadp_v2p_audplayer_launch_app();
}


VfxBool VappHsWidgetAudplayer::onPenInput(VfxPenEvent &event)
{
    return VappHsWidget::onPenInput(event);
}

void VappHsWidgetAudplayer::onButtonUp(VfxObjWeakPtr this_ptr)
{    
    if (this_ptr != NULL)
    {
        getState();
        update();
    }
}

void VappHsWidgetAudplayer::onPlayDown(VfxPenEvent &event)
{
    VFX_UNUSED(event);
#ifdef __MMI_MEDIA_PLAYER_FTE__
    if (m_state == STATE_PROCESS)
        return;
#endif
    
    vadp_v2p_audplayer_button_process(VAPP_HS_WIDGET_BUTTON_PLAY, VAPP_HS_WIDGET_PEN_EVENT_DOWN);
}


void VappHsWidgetAudplayer::onPlayUp(VfxPenEvent &event)
{
    VfxObjWeakPtr this_ptr = this;

    VFX_UNUSED(event);

#ifdef __MMI_MEDIA_PLAYER_FTE__
    if (m_state == STATE_PROCESS)
        return;
#endif

    if (m_butPlay->containPoint(event.getRelPos(m_butPlay)))
    {
        vadp_v2p_audplayer_button_process(VAPP_HS_WIDGET_BUTTON_PLAY, VAPP_HS_WIDGET_PEN_EVENT_UP);

        if (this_ptr != NULL)
        {
            startGetCurrtimeTimer();
        }
    }
    else
    {
        vadp_v2p_audplayer_button_process(VAPP_HS_WIDGET_BUTTON_PLAY, VAPP_HS_WIDGET_PEN_EVENT_CANCEL);
    }
    onButtonUp(this_ptr);
}


void VappHsWidgetAudplayer::onPauseDown(VfxPenEvent &event)
{
    VFX_UNUSED(event);
    vadp_v2p_audplayer_button_process(VAPP_HS_WIDGET_BUTTON_PAUSE, VAPP_HS_WIDGET_PEN_EVENT_DOWN);
}


void VappHsWidgetAudplayer::onPauseUp(VfxPenEvent &event)
{
    VfxObjWeakPtr this_ptr = this;

    VFX_UNUSED(event);
    if (m_butPause->containPoint(event.getRelPos(m_butPause)))
    {
        vadp_v2p_audplayer_button_process(VAPP_HS_WIDGET_BUTTON_PAUSE, VAPP_HS_WIDGET_PEN_EVENT_UP);
    }
    else
    {
        vadp_v2p_audplayer_button_process(VAPP_HS_WIDGET_BUTTON_PAUSE, VAPP_HS_WIDGET_PEN_EVENT_CANCEL);
    }
    onButtonUp(this_ptr);

    if (this_ptr != NULL)
    {
        setCurrentProgress();
    }
}


void VappHsWidgetAudplayer::onStopDown(VfxPenEvent &event)
{
    VFX_UNUSED(event);
    vadp_v2p_audplayer_button_process(VAPP_HS_WIDGET_BUTTON_STOP, VAPP_HS_WIDGET_PEN_EVENT_DOWN);
}


void VappHsWidgetAudplayer::onStopUp(VfxPenEvent &event)
{
    VfxObjWeakPtr this_ptr = this;

    VFX_UNUSED(event);
    if (m_butStop->containPoint(event.getRelPos(m_butStop)))
    {
        vadp_v2p_audplayer_button_process(VAPP_HS_WIDGET_BUTTON_STOP, VAPP_HS_WIDGET_PEN_EVENT_UP); 
        if (this_ptr != NULL)
        {
            m_progress->setRatio(0);
        }
    }
    else
    {
        vadp_v2p_audplayer_button_process(VAPP_HS_WIDGET_BUTTON_STOP, VAPP_HS_WIDGET_PEN_EVENT_CANCEL);
    }
    onButtonUp(this_ptr);
}


void VappHsWidgetAudplayer::onPrevDown(VfxPenEvent &event)
{
    VFX_UNUSED(event);
    vadp_v2p_audplayer_button_process(VAPP_HS_WIDGET_BUTTON_PREV, VAPP_HS_WIDGET_PEN_EVENT_DOWN);
}


void VappHsWidgetAudplayer::onPrevUp(VfxPenEvent &event)
{   
    VfxObjWeakPtr this_ptr = this;

    VFX_UNUSED(event);
    if (m_butPrev->containPoint(event.getRelPos(m_butPrev)))
    {
        vadp_v2p_audplayer_button_process(VAPP_HS_WIDGET_BUTTON_PREV, VAPP_HS_WIDGET_PEN_EVENT_UP);
        if (this_ptr != NULL)
        {
//          m_progress->setRatio(0);
            setCurrentProgress();
            if (m_progress->getRatio() == 0)
            {
                m_isRescrollText = VFX_TRUE;
            }
        }
    }
    else
    {
        vadp_v2p_audplayer_button_process(VAPP_HS_WIDGET_BUTTON_PREV, VAPP_HS_WIDGET_PEN_EVENT_CANCEL);
    }
    onButtonUp(this_ptr);
}


void VappHsWidgetAudplayer::onNextDown(VfxPenEvent &event)
{
    VFX_UNUSED(event);
    vadp_v2p_audplayer_button_process(VAPP_HS_WIDGET_BUTTON_NEXT, VAPP_HS_WIDGET_PEN_EVENT_DOWN);
}


void VappHsWidgetAudplayer::onNextUp(VfxPenEvent &event)
{
    VfxObjWeakPtr this_ptr = this;

    VFX_UNUSED(event);
    if (m_butNext->containPoint(event.getRelPos(m_butNext)))
    {
        vadp_v2p_audplayer_button_process(VAPP_HS_WIDGET_BUTTON_NEXT, VAPP_HS_WIDGET_PEN_EVENT_UP);

        if (this_ptr != NULL)
        {
//          m_progress->setRatio(0);
            setCurrentProgress();
            if (m_progress->getRatio() == 0)
            {
                m_isRescrollText = VFX_TRUE;
            }
        }
    }
    else
    {
        vadp_v2p_audplayer_button_process(VAPP_HS_WIDGET_BUTTON_NEXT, VAPP_HS_WIDGET_PEN_EVENT_CANCEL);
    }
    onButtonUp(this_ptr);
}


void VappHsWidgetAudplayer::onStatusChanged(void* resultP)
{
    VfxBool is_change = VFX_FALSE;
    
    VFX_UNUSED(resultP);
    getState();

    if (m_butPause->getPenType() == VFX_PEN_EVENT_TYPE_DOWN && 
        m_butPlay->getPenType() == VFX_PEN_EVENT_TYPE_UP)
    {
        m_butPlay->setPenType(VFX_PEN_EVENT_TYPE_DOWN);
        is_change = VFX_TRUE;
    }  

    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();
        
    update();
        
    if (is_change)
    {
        m_butPlay->setPenType(VFX_PEN_EVENT_TYPE_UP);
    }
}


void VappHsWidgetAudplayer::onMediaChanged(void* resultP)
{
    VfxBool is_change = VFX_FALSE;
    
    VFX_UNUSED(resultP);
    getState();
    m_isRescrollText = VFX_TRUE;
    m_progress->setRatio(0);
    if (m_butPause->getPenType() == VFX_PEN_EVENT_TYPE_DOWN && 
        m_butPlay->getPenType() == VFX_PEN_EVENT_TYPE_UP)
    {
        m_butPlay->setPenType(VFX_PEN_EVENT_TYPE_DOWN);
        is_change = VFX_TRUE;
    }
    
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();
        
    update();

    if (is_change)
    {
        m_butPlay->setPenType(VFX_PEN_EVENT_TYPE_UP);
    }
}


void VappHsWidgetAudplayer::onPlayEnd(void* resultP)
{
    VfxBool is_change = VFX_FALSE;
    
    VFX_UNUSED(resultP);
    getState();
    m_progress->setRatio(100);
    if (m_butPause->getPenType() == VFX_PEN_EVENT_TYPE_DOWN && 
        m_butPlay->getPenType() == VFX_PEN_EVENT_TYPE_UP)
    {
        m_butPlay->setPenType(VFX_PEN_EVENT_TYPE_DOWN);
        is_change = VFX_TRUE;
    } 

    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();
        
    update();
    
    if (is_change)
    {
        m_butPlay->setPenType(VFX_PEN_EVENT_TYPE_UP);
    }
}


void VappHsWidgetAudplayer::onResetTime(void* resultP)
{
    VfxBool is_change = VFX_FALSE;
    
    VFX_UNUSED(resultP);
    getState();
    m_progress->setRatio(0);
    if (m_butPause->getPenType() == VFX_PEN_EVENT_TYPE_DOWN && 
        m_butPlay->getPenType() == VFX_PEN_EVENT_TYPE_UP)
    {
        m_butPlay->setPenType(VFX_PEN_EVENT_TYPE_DOWN);
        is_change = VFX_TRUE;
    } 

    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();
        
    update();
    
    if (is_change)
    {
        m_butPlay->setPenType(VFX_PEN_EVENT_TYPE_UP);
    }
}

void VappHsWidgetAudplayer::setCurrentProgress(void)
{
    VfxObjWeakPtr this_ptr = this;
    
    if (m_progress == NULL)
        return;
        
    VfxS32 ratio = 0;

    getDuration();
    getCurrTime();
        
    if (m_durationMsec)
    {
        ratio = (m_currTimeMsec*100)/m_durationMsec;
        m_progress->setRatio(ratio);
    }
    else
    {
        m_progress->setRatio(0);
    }
}

void VappHsWidgetAudplayer::startGetCurrtimeTimer(void)
{
    if (!m_isTimerStart)
    {
        m_timer->setStartDelay(100);
        m_timer->setDuration(100);
        m_timer->start();

        m_isTimerStart = VFX_TRUE;
    }
}
void VappHsWidgetAudplayer::stopGetCurrtimeTimer(void)
{
    if (m_isTimerStart)
    {
        m_timer->stop();
        m_isTimerStart = VFX_FALSE;
    }
}

void VappHsWidgetAudplayer::update(void)
{
    VfxWString temp_title;
    VfxS32 result = 0;
    VfxBool is_pause_disable;

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        m_isReady = VFX_FALSE;
        m_state = STATE_INIT;
    #if !defined(__COSMOS_MMI__)
        //temp_title = VFX_WSTR_RES(STR_ID_USB_MODE_EXPORTED_WARNING);
        temp_title = VFX_WSTR_RES(STR_GLOBAL_NOT_AVAILABLE_IN_MASS_STORAGE_MODE);
    #endif
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    vadp_v2p_audplayer_get_info(VAPP_HS_WIDGET_AUDPLAYER_INFO_PAUSE_DISABLE, (void*)&result);
    is_pause_disable = result ? VFX_TRUE : VFX_FALSE;
    
    if (m_state == STATE_INIT)
    {
        m_butPlay->setDisplay(VFX_TRUE);
        m_butPause->setDisplay(VFX_FALSE);
        m_progress->setImage(VAPP_HS_IMG_WG_AUDPLY_PROGRESS_BG, VAPP_HS_IMG_WG_AUDPLY_PROGRESS_FG);

        if (m_isReady)
        {
            temp_title = VFX_WSTR_MEM((const U16*)getTitle());
            
            m_butPrev->setImage(VAPP_HS_IMG_WG_AUDPLY_PREV_UP, VAPP_HS_IMG_WG_AUDPLY_PREV_DOWN);
            m_butPlay->setImage(VAPP_HS_IMG_WG_AUDPLY_PLAY_UP, VAPP_HS_IMG_WG_AUDPLY_PLAY_DOWN);
            
            if (is_pause_disable == VFX_TRUE)
                m_butPause->setImage(VAPP_HS_IMG_WG_AUDPLY_PAUSE_DIS, VAPP_HS_IMG_WG_AUDPLY_PAUSE_DIS);
            else    
                m_butPause->setImage(VAPP_HS_IMG_WG_AUDPLY_PAUSE_UP, VAPP_HS_IMG_WG_AUDPLY_PAUSE_DOWN);
            
            m_butNext->setImage(VAPP_HS_IMG_WG_AUDPLY_NEXT_UP, VAPP_HS_IMG_WG_AUDPLY_NEXT_DOWN);
            m_butStop->setImage(VAPP_HS_IMG_WG_AUDPLY_STOP_UP, VAPP_HS_IMG_WG_AUDPLY_STOP_DOWN);
        
            m_butPlay->m_eventPenDown.connect(this, &VappHsWidgetAudplayer::onPlayDown);
            m_butPlay->m_eventPenUp.connect(this, &VappHsWidgetAudplayer::onPlayUp);

            m_butPause->m_eventPenDown.disconnect(this, &VappHsWidgetAudplayer::onPauseDown);
            m_butPause->m_eventPenUp.disconnect(this, &VappHsWidgetAudplayer::onPauseUp);
            
            m_butStop->m_eventPenDown.connect(this, &VappHsWidgetAudplayer::onStopDown);
            m_butStop->m_eventPenUp.connect(this, &VappHsWidgetAudplayer::onStopUp);

            m_butPrev->m_eventPenDown.connect(this, &VappHsWidgetAudplayer::onPrevDown);
            m_butPrev->m_eventPenUp.connect(this, &VappHsWidgetAudplayer::onPrevUp);

            m_butNext->m_eventPenDown.connect(this, &VappHsWidgetAudplayer::onNextDown);
            m_butNext->m_eventPenUp.connect(this, &VappHsWidgetAudplayer::onNextUp);

            setCurrentProgress();
        }
        else
        {
            m_progress->setRatio(0);
        #ifdef __USB_IN_NORMAL_MODE__
            if (!srv_usb_is_in_mass_storage_mode())
        #endif /* __USB_IN_NORMAL_MODE__ */         
            {
                temp_title = VFX_WSTR_RES(VAPP_HS_STR_AUDPLY_PLAYLIST_NOT_READY);
            }
    
            m_butPrev->setImage(VAPP_HS_IMG_WG_AUDPLY_PREV_DIS, VAPP_HS_IMG_WG_AUDPLY_PREV_DIS);
            m_butPlay->setImage(VAPP_HS_IMG_WG_AUDPLY_PLAY_DIS, VAPP_HS_IMG_WG_AUDPLY_PLAY_DIS);
            m_butPause->setImage(VAPP_HS_IMG_WG_AUDPLY_PAUSE_DIS, VAPP_HS_IMG_WG_AUDPLY_PAUSE_DIS);
            m_butNext->setImage(VAPP_HS_IMG_WG_AUDPLY_NEXT_DIS, VAPP_HS_IMG_WG_AUDPLY_NEXT_DIS);
            m_butStop->setImage(VAPP_HS_IMG_WG_AUDPLY_STOP_DIS, VAPP_HS_IMG_WG_AUDPLY_STOP_DIS);

            m_butPlay->m_eventPenDown.disconnect(this, &VappHsWidgetAudplayer::onPlayDown);
            m_butPlay->m_eventPenUp.disconnect(this, &VappHsWidgetAudplayer::onPlayUp);

            m_butPause->m_eventPenDown.disconnect(this, &VappHsWidgetAudplayer::onPauseDown);
            m_butPause->m_eventPenUp.disconnect(this, &VappHsWidgetAudplayer::onPauseUp);
            
            m_butStop->m_eventPenDown.disconnect(this, &VappHsWidgetAudplayer::onStopDown);
            m_butStop->m_eventPenUp.disconnect(this, &VappHsWidgetAudplayer::onStopUp);

            m_butPrev->m_eventPenDown.disconnect(this, &VappHsWidgetAudplayer::onPrevDown);
            m_butPrev->m_eventPenUp.disconnect(this, &VappHsWidgetAudplayer::onPrevUp);

            m_butNext->m_eventPenDown.disconnect(this, &VappHsWidgetAudplayer::onNextDown);
            m_butNext->m_eventPenUp.disconnect(this, &VappHsWidgetAudplayer::onNextUp);
        }

        stopGetCurrtimeTimer();
    }
    else if (m_state == STATE_PLAY)
    {       
        m_butPrev->setImage(VAPP_HS_IMG_WG_AUDPLY_PREV_UP, VAPP_HS_IMG_WG_AUDPLY_PREV_DOWN);
        m_butPlay->setImage(VAPP_HS_IMG_WG_AUDPLY_PLAY_UP, VAPP_HS_IMG_WG_AUDPLY_PLAY_DOWN);

        if (is_pause_disable == VFX_TRUE)
            m_butPause->setImage(VAPP_HS_IMG_WG_AUDPLY_PAUSE_DIS, VAPP_HS_IMG_WG_AUDPLY_PAUSE_DIS);
        else
            m_butPause->setImage(VAPP_HS_IMG_WG_AUDPLY_PAUSE_UP, VAPP_HS_IMG_WG_AUDPLY_PAUSE_DOWN);
        
        m_butNext->setImage(VAPP_HS_IMG_WG_AUDPLY_NEXT_UP, VAPP_HS_IMG_WG_AUDPLY_NEXT_DOWN);
        m_butStop->setImage(VAPP_HS_IMG_WG_AUDPLY_STOP_UP, VAPP_HS_IMG_WG_AUDPLY_STOP_DOWN);

        m_progress->setImage(VAPP_HS_IMG_WG_AUDPLY_PROGRESS_BG, VAPP_HS_IMG_WG_AUDPLY_PROGRESS_FG);
            
        m_butPlay->setDisplay(VFX_FALSE);
        m_butPause->setDisplay(VFX_TRUE);
        
        temp_title = VFX_WSTR_MEM((const U16*)getTitle());
            
        m_butPlay->m_eventPenDown.disconnect(this, &VappHsWidgetAudplayer::onPlayDown);
        m_butPlay->m_eventPenUp.disconnect(this, &VappHsWidgetAudplayer::onPlayUp);
        
        m_butPause->m_eventPenDown.connect(this, &VappHsWidgetAudplayer::onPauseDown);
        m_butPause->m_eventPenUp.connect(this, &VappHsWidgetAudplayer::onPauseUp);

        m_butStop->m_eventPenDown.connect(this, &VappHsWidgetAudplayer::onStopDown);
        m_butStop->m_eventPenUp.connect(this, &VappHsWidgetAudplayer::onStopUp);

        m_butPrev->m_eventPenDown.connect(this, &VappHsWidgetAudplayer::onPrevDown);
        m_butPrev->m_eventPenUp.connect(this, &VappHsWidgetAudplayer::onPrevUp);

        m_butNext->m_eventPenDown.connect(this, &VappHsWidgetAudplayer::onNextDown);
        m_butNext->m_eventPenUp.connect(this, &VappHsWidgetAudplayer::onNextUp);

        startGetCurrtimeTimer();
        
    }
    else if (m_state == STATE_PROCESS)
    {
        m_butPrev->setImage(VAPP_HS_IMG_WG_AUDPLY_PREV_UP, VAPP_HS_IMG_WG_AUDPLY_PREV_DOWN);
        m_butPlay->setImage(VAPP_HS_IMG_WG_AUDPLY_PLAY_UP, VAPP_HS_IMG_WG_AUDPLY_PLAY_DOWN);
        
        if (is_pause_disable == VFX_TRUE)
            m_butPause->setImage(VAPP_HS_IMG_WG_AUDPLY_PAUSE_DIS, VAPP_HS_IMG_WG_AUDPLY_PAUSE_DIS);
        else
            m_butPause->setImage(VAPP_HS_IMG_WG_AUDPLY_PAUSE_UP, VAPP_HS_IMG_WG_AUDPLY_PAUSE_DOWN);
        
        m_butNext->setImage(VAPP_HS_IMG_WG_AUDPLY_NEXT_UP, VAPP_HS_IMG_WG_AUDPLY_NEXT_DOWN);
        m_butStop->setImage(VAPP_HS_IMG_WG_AUDPLY_STOP_UP, VAPP_HS_IMG_WG_AUDPLY_STOP_DOWN);
            
        m_butPlay->setDisplay(VFX_TRUE);
        m_butPause->setDisplay(VFX_FALSE);
        
        temp_title = VFX_WSTR_MEM((const U16*)getTitle());
            
        m_progress->setImage(VAPP_HS_IMG_WG_AUDPLY_PROGRESS_PROCESS, VAPP_HS_IMG_WG_AUDPLY_PROGRESS_PROCESS);
        m_progress->setRatio(0);

        m_butPlay->m_eventPenDown.connect(this, &VappHsWidgetAudplayer::onPlayDown);
        m_butPlay->m_eventPenUp.connect(this, &VappHsWidgetAudplayer::onPlayUp);
        
        m_butPause->m_eventPenDown.disconnect(this, &VappHsWidgetAudplayer::onPauseDown);
        m_butPause->m_eventPenUp.disconnect(this, &VappHsWidgetAudplayer::onPauseUp);

        m_butStop->m_eventPenDown.connect(this, &VappHsWidgetAudplayer::onStopDown);
        m_butStop->m_eventPenUp.connect(this, &VappHsWidgetAudplayer::onStopUp);
        
        m_butPrev->m_eventPenDown.connect(this, &VappHsWidgetAudplayer::onPrevDown);
        m_butPrev->m_eventPenUp.connect(this, &VappHsWidgetAudplayer::onPrevUp);
        
        m_butNext->m_eventPenDown.connect(this, &VappHsWidgetAudplayer::onNextDown);
        m_butNext->m_eventPenUp.connect(this, &VappHsWidgetAudplayer::onNextUp);

        stopGetCurrtimeTimer();
    }

    if (is_pause_disable == VFX_TRUE)
        m_butPause->setIsUnhittable(VFX_TRUE);
    else
        m_butPause->setIsUnhittable(VFX_FALSE);
    
    if (m_state == STATE_INIT || m_state == STATE_PLAY || m_state == STATE_PROCESS)
    {
        if (temp_title != m_curr_show_title || m_isRescrollText)
        {
            m_curr_show_title = temp_title;
            m_marqueeText->setMovableFrame(m_curr_show_title, VFX_FONT_DESC_SMALL);
            m_marqueeText->startScroll();

            if (m_isRescrollText)
            {
                m_isRescrollText = VFX_FALSE;
            }
        }
    }
}

void VappHsWidgetAudplayer::getState()
{
    VfxU8 state = 0;
    
    vadp_v2p_audplayer_get_info(VAPP_HS_WIDGET_AUDPLAYER_INFO_STATE, (void*)&state);
    m_state = state;
    
    VFX_LOG(VFX_INFO, VAPP_HS_AUDPLY_GET_STATE_MSG, m_state);
}

VfxU64 VappHsWidgetAudplayer::getDuration()
{
    vadp_v2p_audplayer_get_info(VAPP_HS_WIDGET_AUDPLAYER_INFO_DURATION, &m_durationMsec);
    VFX_LOG(VFX_INFO, VAPP_HS_AUDPLY_GET_DURATION_MSG, m_durationMsec);
    
    return m_durationMsec;
}


VfxU64 VappHsWidgetAudplayer::getCurrTime()
{
    vadp_v2p_audplayer_get_info(VAPP_HS_WIDGET_AUDPLAYER_INFO_CURR_TIME, &m_currTimeMsec);
    VFX_LOG(VFX_INFO, VAPP_HS_AUDPLY_GET_CURRTIME_MSG, m_currTimeMsec);
    
    return m_currTimeMsec;
}

VfxChar* VappHsWidgetAudplayer::getTitle()
{
    vadp_v2p_audplayer_get_info(VAPP_HS_WIDGET_AUDPLAYER_INFO_TITLE, m_title);
    
    return m_title;
}

VfxU16 VappHsWidgetAudplayer::getIcon()
{
    return VAPP_HS_IMG_WG_ICON_AUDPLY;
}

VfxU16 VappHsWidgetAudplayer::getName()
{
    return VAPP_HS_STR_WG_AUDIO_PLAYER;
}

void VappHsWidgetAudplayer::onCreateView()
{
    VfxU8 state = 0;

    m_curr_show_title = VFX_WSTR_EMPTY;
    m_isRescrollText = VFX_FALSE;
    VFX_OBJ_CREATE(m_imageBg, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_progress, VappHsWidgetAudplayerProgress, this);
    VFX_OBJ_CREATE(m_marqueeText, VcpMarquee, this);
    VFX_OBJ_CREATE(m_butPrev, VappHsWidgetAudplayerButton, this);
    VFX_OBJ_CREATE(m_butPlay, VappHsWidgetAudplayerButton, this);
    VFX_OBJ_CREATE(m_butPause, VappHsWidgetAudplayerButton, this);
    VFX_OBJ_CREATE(m_butNext, VappHsWidgetAudplayerButton, this);
    VFX_OBJ_CREATE(m_butStop, VappHsWidgetAudplayerButton, this);
    
    m_imageBg->setResId(VAPP_HS_IMG_WG_AUDPLY_BG);
#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    m_imageBg->setIsOpaque(VFX_TRUE);
    setIsOpaque(VFX_TRUE);
#endif /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */
    setIsCached(VFX_FALSE);
    setBounds(m_imageBg->getBounds());
    m_progress->setImage(VAPP_HS_IMG_WG_AUDPLY_PROGRESS_BG, VAPP_HS_IMG_WG_AUDPLY_PROGRESS_FG);
    m_progress->setPos(VfxPoint(PROGRESS_BAR_OFFSET_X, PROGRESS_BAR_OFFSET_Y));
    m_progress->setRatio(0);

    m_isReady = vadp_v2p_audplayer_is_ready() != 0 ? VFX_TRUE : VFX_FALSE;

    m_marqueeText->setPos(VfxPoint(TITLE_START_OFFSET_X, TITLE_START_OFFSET_Y));
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
    m_butPause->setPos(VfxPoint(BUTTON_PAUSE_OFFSET_X, BUTTON_PAUSE_OFFSET_Y));
    m_butNext->setPos(VfxPoint(BUTTON_NEXT_OFFSET_X, BUTTON_NEXT_OFFSET_Y));
    m_butStop->setPos(VfxPoint(BUTTON_STOP_OFFSET_X, BUTTON_STOP_OFFSET_Y));
    
    vadp_v2p_audplayer_get_info(VAPP_HS_WIDGET_AUDPLAYER_INFO_STATE, (void*)&state);
    m_state = state;
    
    if (m_state == STATE_INIT)
    {
        m_butPlay->setDisplay(VFX_TRUE);
        m_butPause->setDisplay(VFX_FALSE);
    }
    else if (m_state == STATE_PLAY)
    {
        m_butPlay->setDisplay(VFX_FALSE);
        m_butPause->setDisplay(VFX_TRUE);       
    }

    if (m_isReady)
    {       
        if (m_state == STATE_INIT)
        {           
            setCurrentProgress();
        }
        else if (m_state == STATE_PLAY)
        {
            setCurrentProgress();
        }
    }
    else
    {
        m_progress->setRatio(0);
    }
    update();
    m_timer->m_signalTick.connect(this, &VappHsWidgetAudplayer::onTimerTick);
//  startGetCurrtimeTimer();

    vadp_v2p_audplayer_register_callback((void*)this, audplayerCallback);
}


void VappHsWidgetAudplayer::onReleaseView()
{
    vadp_v2p_audplayer_deregister_callback();
    
    stopGetCurrtimeTimer();
    
    m_butPlay->m_eventPenDown.disconnect(this, &VappHsWidgetAudplayer::onPlayDown);
    m_butPlay->m_eventPenUp.disconnect(this, &VappHsWidgetAudplayer::onPlayUp);
        
    m_butPause->m_eventPenDown.disconnect(this, &VappHsWidgetAudplayer::onPauseDown);
    m_butPause->m_eventPenUp.disconnect(this, &VappHsWidgetAudplayer::onPauseUp);
        
    m_butPrev->m_eventPenDown.disconnect(this, &VappHsWidgetAudplayer::onPrevDown);
    m_butPrev->m_eventPenUp.disconnect(this, &VappHsWidgetAudplayer::onPrevUp);
        
    m_butNext->m_eventPenDown.disconnect(this, &VappHsWidgetAudplayer::onNextDown);
    m_butNext->m_eventPenUp.disconnect(this, &VappHsWidgetAudplayer::onNextUp);
    
    m_timer->m_signalTick.disconnect(this, &VappHsWidgetAudplayer::onTimerTick);
    
    VFX_OBJ_CLOSE(m_butStop);
    VFX_OBJ_CLOSE(m_butNext);
    VFX_OBJ_CLOSE(m_butPause);
    VFX_OBJ_CLOSE(m_butPlay);
    VFX_OBJ_CLOSE(m_butPrev);
    VFX_OBJ_CLOSE(m_marqueeText);
    VFX_OBJ_CLOSE(m_progress);
    VFX_OBJ_CLOSE(m_imageBg);
    m_curr_show_title = VFX_WSTR_EMPTY;
    m_isRescrollText = VFX_FALSE;

}


void VappHsWidgetAudplayer::onTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);
    setCurrentProgress();
}

#endif /* __MMI_VUI_HOMESCREEN_AUDIO_PLAYER__ */
