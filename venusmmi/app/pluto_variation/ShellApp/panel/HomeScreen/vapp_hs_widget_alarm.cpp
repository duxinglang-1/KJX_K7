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
 *  vapp_hs_widget_alarm.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: alarm
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_ALARM__

/***************************************************************************** 
 * Include
 *****************************************************************************/

/* Venus MMI header: */
#include "vfx_uc_include.h"
#include "vapp_hs_widget_alarm.h"
#include "vapp_hs_res.h"
#include "trc/vadp_app_trc.h"

/* Venus & Pluto Adaptation: */
#include "HomeScreen\vadp_v2p_hs.h"


/***************************************************************************** 
 * Home screen widget: alarm item
 *****************************************************************************/

VappHsWidgetAlarmItem::VappHsWidgetAlarmItem(VfxBool needSeparateLine) :
    m_timeString(NULL),
    m_button(NULL),
    m_buttonImgUp(NULL),
    m_buttonImgDown(NULL),
    m_needSeparateLine(needSeparateLine),
    m_lineImgData(NULL)
{
    m_lineImgSize.width = 0;
    m_lineImgSize.height = 0;
}


void VappHsWidgetAlarmItem::onInit()
{
    VfxControl::onInit();
    
    setBounds(VfxRect(0, 0, WIDTH, HEIGHT));
    
    // Alarm toggle button
    VFX_OBJ_CREATE(m_button, VcpButtonInternal, this);
    m_button->setAnchor(VfxFPoint(0, 0.5));
    m_button->m_eventUp.connect(this, &VappHsWidgetAlarmItem::onClick);

    VFX_OBJ_CREATE(m_buttonImgUp, VfxImageFrame, this);
    m_buttonImgUp->setResId(VAPP_HS_IMG_WG_ALARM_ON);
    m_button->setBackgroundUp(m_buttonImgUp, MMI_TRUE);

    VFX_OBJ_CREATE(m_buttonImgDown, VfxImageFrame, this);
    m_buttonImgDown->setResId(VAPP_HS_IMG_WG_ALARM_ON);
    m_button->setBackgroundDown(m_buttonImgDown, MMI_TRUE);

    // Alarm time string
    VFX_OBJ_CREATE(m_timeString, VfxTextFrame, this);
    m_timeString->setBounds(VfxRect(0, 0, TEXT_WIDTH, 0 /* dummy */));
    m_timeString->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_timeString->setString(VFX_WSTR_EMPTY);
    m_timeString->setAnchor(VfxFPoint(0, 0.5));
    m_timeString->setColor(VfxColor(255, 242, 240, 240));
    m_timeString->setFont(VfxFontDesc(g_vfxFontSmall));

    // Separate line
    m_lineImgData = vrt_sys_res_image_lock(VAPP_HS_IMG_WG_ALARM_SEPARATE_LINE);
    m_lineImgSize = vrt_sys_image_get_size_from_mem(m_lineImgData);
    
    alignment();
}


void VappHsWidgetAlarmItem::onDeinit()
{
    VfxControl::onDeinit();
}


void VappHsWidgetAlarmItem::onDraw(VfxDrawContext &dc)
{
    // Draw the separate line if it is required.
    if (m_needSeparateLine)
    {
        dc.drawImageFromMem(
            (WIDTH - m_lineImgSize.width) >> 1,
            (0),
            m_lineImgData);
    }
}


void VappHsWidgetAlarmItem::alignment()
{
    VfxS32 startY;
    VfxPoint iconPos, strPos;

    startY = m_lineImgSize.height / 2;
    
    // Status icon: vertical central alignment
    iconPos.x = BUTTON_X;
    iconPos.y = startY + getBounds().getMidY();
    m_button->setPos(iconPos);

    // Time string: vertical central alignment
    strPos.x = TEXT_X;
    strPos.y = startY + getBounds().getMidY();
    m_timeString->setPos(strPos);
}


void VappHsWidgetAlarmItem::onClick()
{
    m_signalToggle.emit(this);
}


void VappHsWidgetAlarmItem::setTimeString(VfxU8 *str)
{
    if (str)
    {
        m_timeString->setString(VFX_WSTR_MEM((VfxWChar *)str));
    }
}


void VappHsWidgetAlarmItem::setStatus(VfxBool isEnable)
{
    VfxFontDesc font;
    
    font = m_timeString->getFont();
    
    if (isEnable)
    {
        font.effect = VFX_FONT_DESC_EFFECT_BORDER;
        m_buttonImgUp->setResId(VAPP_HS_IMG_WG_ALARM_ON);
        m_buttonImgDown->setResId(VAPP_HS_IMG_WG_ALARM_ON);
    }
    else
    {
        font.effect = VFX_FONT_DESC_EFFECT_NONE;
        m_buttonImgUp->setResId(VAPP_HS_IMG_WG_ALARM_OFF);
        m_buttonImgDown->setResId(VAPP_HS_IMG_WG_ALARM_OFF);
    }
    
    m_timeString->setFont(font);
}


/***************************************************************************** 
 * Home screen widget: alarm
 *****************************************************************************/

VappHsWidgetAlarm::VappHsWidgetAlarm() :
    m_body(NULL)
{
    for (VfxS32 i = 0; i < NUM_OF_ALM; i++)
    {
        m_alarm[i] = NULL;
    }
}


VfxS32 VappHsWidgetAlarm::getIcon()
{
    return VAPP_HS_IMG_WG_ICON_ALARM;
}


void VappHsWidgetAlarm::onCreateView()
{
    VFX_LOG(VFX_STATE, VAPP_HS_ALARM_ON_CREATE_VIEW_MSG);
    
    // Background image
#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    setIsOpaque(VFX_TRUE);
#endif /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

    VfxImageSrc bgImage;
    bgImage.setResId(VAPP_HS_IMG_WG_ALARM_BG);

    setImgContent(bgImage);
    setBounds(VfxRect(VFX_POINT_ZERO, bgImage.getSize()));
    setIsCached(VFX_TRUE);

    // Scrollable
    VFX_OBJ_CREATE(m_body, VcpScrollable, this);
    m_body->setPos(VfxPoint(MAIN_POS_X, MAIN_POS_Y));
    m_body->setBounds(VfxRect(0, 0, MAIN_WIDTH, MAIN_HEIGHT));
    m_body->setContentSize(VfxSize(MAIN_WIDTH, NUM_OF_ALM * VappHsWidgetAlarmItem::HEIGHT));
    m_body->setViewRect(VfxRect(0, 0, MAIN_WIDTH, MAIN_HEIGHT));

    // Alarm
    VfxPoint pos(0, 0);

    for (VfxS32 i = 0; i < NUM_OF_ALM; i++)
    {
        VfxU8 state;
        VfxU8 time_str[STR_LEN]; // shall be large enough

        // Alarm item. Separate line isn't needed for the 1st item. 
        if (i == 0)
        {
            VFX_OBJ_CREATE_EX(
                m_alarm[i], 
                VappHsWidgetAlarmItem, 
                m_body,
                (VFX_FALSE));
        }
        else
        {
            VFX_OBJ_CREATE_EX(
                m_alarm[i], 
                VappHsWidgetAlarmItem, 
                m_body,
                (VFX_TRUE));
        }

        m_alarm[i]->m_signalToggle.connect(this, &VappHsWidgetAlarm::onToggleAlarm);
            
        // Alarm position
        pos.x = 0;
        m_alarm[i]->setPos(pos);
        
        pos.y += m_alarm[i]->getBounds().getHeight();

        // Get alarm information. Set alarm status and time string.
        vadp_v2p_hs_get_alarm_info(i, &state, time_str);
        
        m_alarm[i]->setStatus(state ? VFX_TRUE : VFX_FALSE);
        m_alarm[i]->setTimeString((VfxU8 *)time_str);
    }
}


void VappHsWidgetAlarm::onReleaseView()
{    
    VFX_LOG(VFX_STATE, VAPP_HS_ALARM_ON_RELEASE_VIEW_MSG);

    VFX_OBJ_CLOSE(m_body);
}


void VappHsWidgetAlarm::onToggleAlarm(VappHsWidgetAlarmItem *alarm)
{
    VfxS32 idx;
    VfxU8 state;
    VfxU8 time_str[STR_LEN]; // shall be large enough

    VFX_LOG(VFX_STATE, VAPP_HS_ALARM_ON_TOGGLE_MSG);

    for (idx = 0; idx < NUM_OF_ALM; idx++)
    {
        if (alarm == m_alarm[idx])
        {
            break;
        }
    }

    if (idx == NUM_OF_ALM)
    {
        return;
    }

    // get the old state
    vadp_v2p_hs_get_alarm_info(idx, &state, time_str);

    // toggle the state
    VFX_LOG(VFX_INFO, VAPP_HS_ALARM_DUMP_DETAIL_TOGGLE_MSG, idx, state);

    if (state)
    {
        // Change from on to off
        alarm->setStatus(VFX_FALSE);
        vadp_v2p_hs_set_alarm(idx, VFX_FALSE);
    }
    else
    {
        // Change from off to on
        alarm->setStatus(VFX_TRUE);
        vadp_v2p_hs_set_alarm(idx, VFX_TRUE);
    }
}

#endif /* __MMI_VUI_HOMESCREEN_ALARM__ */

