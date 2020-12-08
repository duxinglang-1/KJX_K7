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
 *  vcp_alert_popup.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_popup_data_type.h"
#include "vcp_alert_popup.h"
#include "vadp_mmi_frm.h"
#include "vcp_res.h"
extern "C"
{
#include "custom_events_notify.h"
#include "profilesSrvGprot.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
}

#include "vfx_base_popup.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_frame.h"
#include "mmi_rp_srv_venus_component_popup_def.h"
#include "vfx_image_src.h"
#include "vfx_datatype.h"
#include "vfx_text_frame.h"
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vfx_string.h"
#include "vrt_datatype.h"
#include "vfx_timer.h"
#include "vfx_signal.h"
#include "vcp_button.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/*****************************************************************************
 * Class VcpAlertPopup
 *****************************************************************************/

VcpAlertPopup::VcpAlertPopup() :
    m_duration(-1),
    m_background(NULL),
    m_icon(NULL),
    m_textFrame(NULL),
    m_textHeight(0),
    m_timer(NULL)
{
}


void VcpAlertPopup::onInit()
{
    VfxBasePopup::onInit();

    VFX_OBJ_CREATE(m_background, VfxFrame, this);
    m_background->setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND));
    m_background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_background->setIsCached(VFX_TRUE);

    VFX_OBJ_CREATE(m_icon, VfxFrame, this);
    m_icon->setAnchor(0.5, 0.5);
    m_icon->setPos(VCP_ALERT_POPUP_WIDTH/2,VCP_ALERT_POPUP_ICON_Y);
    m_icon->setBounds(0,0,VCP_ALERT_POPUP_ICON_WIDTH,VCP_ALERT_POPUP_ICON_HEIGHT);


    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
    m_textFrame->setRect(VCP_ALERT_POPUP_WIDTH/2, VCP_ALERT_POPUP_TEXT_Y, VCP_ALERT_POPUP_TEXT_WIDTH, 20);
    m_textFrame->setAnchor(0.5f,0);
    m_textFrame->setColor(VfxColor(255,26,26,26));
    m_textFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textFrame->setMaxLines(4);
    
    checkUpdate();
}


VfxBool VcpAlertPopup::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        leave(VFX_TRUE);
        return VFX_TRUE;
    }

    return VfxBasePopup::onPenInput(event);
}


VfxBool VcpAlertPopup::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        leave(VFX_TRUE);
        return VFX_TRUE;
    }

    return VfxBasePopup::onKeyInput(event);
}


void VcpAlertPopup::onUpdate()
{
    m_textFrame->forceUpdate();
    m_textHeight = m_textFrame->getSize().height;
    setBounds(0,0,VCP_ALERT_POPUP_WIDTH,VCP_ALERT_POPUP_HEIGHT + m_textHeight);
    m_background->setBounds(0,0,VCP_ALERT_POPUP_WIDTH,VCP_ALERT_POPUP_HEIGHT + m_textHeight);
}


VfxBool VcpAlertPopup::needPushHistory() const
{
    return VFX_FALSE;
}


void VcpAlertPopup::onPenInputOnOutside(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        leave(VFX_TRUE);
        return;
    }

    VfxBasePopup::onPenInputOnOutside(event);
}


void VcpAlertPopup::setText(const VfxWString &text)
{
    m_textFrame->setString(text);
    checkUpdate();
}


void VcpAlertPopup::setTextFont(const VfxFontDesc &font)
{
    m_textFrame->setFont(font);
    checkUpdate();
}


void VcpAlertPopup::setInfoType(VcpPopupTypeEnum type)
{
    m_infoType = type;
    switch (type)
    {
        case VCP_POPUP_TYPE_FAILURE:
            m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_FAILURE_ALERT));
            m_duration = mmi_get_event_based_duration(MMI_EVENT_FAILURE);
            break;
        case VCP_POPUP_TYPE_INFO:
            m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_INFO_ALERT));
            m_duration = mmi_get_event_based_duration(MMI_EVENT_INFO);
            break;
        case VCP_POPUP_TYPE_WARNING:
            m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_WARNING_ALERT));
            m_duration = mmi_get_event_based_duration(MMI_EVENT_WARNING);
            break;
        case VCP_POPUP_TYPE_SUCCESS:
            m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_SUCCESS_ALERT));
            m_duration = mmi_get_event_based_duration(MMI_EVENT_SUCCESS);
            break;
        case VCP_POPUP_TYPE_PROGRESS:
            m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_PROGRESS_ALERT));
            m_duration = mmi_get_event_based_duration(MMI_EVENT_PROGRESS);
            break;
        case VCP_POPUP_TYPE_QUESTION:
            m_icon->setImgContent(VfxImageSrc(VCP_IMG_POPUP_TYPE_QUESTION_ALERT));
            m_duration = mmi_get_event_based_duration(MMI_EVENT_INFO);
            break;
        default:
            VFX_ASSERT(0);
    }
}


void VcpAlertPopup::setImage(const VfxImageSrc &imgScr)
{
    m_icon->setImgContent(imgScr);
}


void VcpAlertPopup::setTextAlignMode(VfxTextFrame::AlignModeEnum value)
{
    m_textFrame->setAlignMode(value);
    checkUpdate();
}


void VcpAlertPopup::onEnter()
{
    VfxBasePopup::onEnter();

    if (m_duration != -1)
    {
        if (m_timer == NULL)
        {
            VFX_OBJ_CREATE(m_timer, VfxTimer, this);
        }
        m_timer->setStartDelay(m_duration);
        m_timer->start();
        m_timer->m_signalTick.connect(this, &VcpAlertPopup::onTimerStop);
    }
}


void VcpAlertPopup::onExit()
{
    if (m_timer)
    {
        m_timer->stop();
    }
    
    VfxBasePopup::onExit();
}


void VcpAlertPopup::onPlayTone()
{
    switch (m_infoType)
    {
        case VCP_POPUP_TYPE_FAILURE:
            srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_FAILURE), NULL);
            break;
        case VCP_POPUP_TYPE_INFO:
            srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_INFO), NULL);
            break;
        case VCP_POPUP_TYPE_WARNING:
            srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_WARNING), NULL);
            break;
        case VCP_POPUP_TYPE_SUCCESS:
            srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_SUCCESS), NULL);
            break;
        case VCP_POPUP_TYPE_PROGRESS:
            srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_PROGRESS), NULL);
            break;
        case VCP_POPUP_TYPE_QUESTION:
            // Question must no sound according rule
            //srv_prof_play_tone(mmi_get_event_based_sound(MMI_EVENT_INFO), NULL);
            break;
    }
}


void VcpAlertPopup::onStopTone()
{
    switch (m_infoType)
    {
        case VCP_POPUP_TYPE_FAILURE:
            srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_FAILURE));
            break;
        case VCP_POPUP_TYPE_INFO:
            srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_INFO));
            break;
        case VCP_POPUP_TYPE_WARNING:
            srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_WARNING));
            break;
        case VCP_POPUP_TYPE_SUCCESS:
            srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_SUCCESS));
            break;
        case VCP_POPUP_TYPE_PROGRESS:
            srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_PROGRESS));
            break;
        case VCP_POPUP_TYPE_QUESTION:
            // Question must no sound according rule
            //srv_prof_stop_tone(mmi_get_event_based_sound(MMI_EVENT_INFO));
            break;
    }
}


void VcpAlertPopup::onTimerStop(VfxTimer *source)
{   
    VFX_UNUSED(source);

    leave(VFX_TRUE);
}


