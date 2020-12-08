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
 *  vapp_hs_widget_recent_event.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: recent event
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
     
/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_RECENT_EVENT__

/* Venus MMI headers: */
#include "vfx_uc_include.h"
#include "vapp_hs_widget_recent_event.h"
#include "vapp_hs_res.h"
#include "trc/vadp_app_trc.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "GlobalConstants.h"
#include "GlobalDefs.h"

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Home screen widget: recent event item
 *****************************************************************************/

VappHsWidgetRecentEventItem::VappHsWidgetRecentEventItem(VfxBool needSeparateLine) :
    m_subject(NULL),
    m_hint(NULL),
    m_button(NULL),
    m_buttonImgUp(NULL),
    m_buttonImgDown(NULL),
    m_iconId(0),
    m_needSeparateLine(needSeparateLine),
    m_lineImgData(NULL)
{
    m_lineImgSize.width = 0;
    m_lineImgSize.height = 0;
}


void VappHsWidgetRecentEventItem::onInit()
{
    VfxControl::onInit();
    
    setBounds(VfxRect(0, 0, WIDTH, HEIGHT));
    
    // Subject string
    VFX_OBJ_CREATE(m_subject, VfxTextFrame, this);
    m_subject->setBounds(VfxRect(0 ,0, TEXT_WIDTH, 0 /* dummy */));
    m_subject->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_subject->setString(VFX_WSTR_EMPTY);
    m_subject->setColor(VfxColor(255, 225, 225, 199));
    m_subject->setFont(VfxFontDesc(g_vfxFontSmall));
    
    // Hint string
    VFX_OBJ_CREATE(m_hint, VfxTextFrame, this);
    m_hint->setBounds(VfxRect(0, 0, HINT_WIDTH, 0 /* dummy */));
    m_hint->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_hint->setString(VFX_WSTR_EMPTY);
    m_hint->setColor(VfxColor(255, 138, 132, 116));
    m_hint->setFont(VfxFontDesc(g_vfxFontSmall));

    // Button for option menu
    VFX_OBJ_CREATE(m_button, VcpButtonInternal, this);
    m_button->m_eventUp.connect(this, &VappHsWidgetRecentEventItem::onClick);

    VFX_OBJ_CREATE(m_buttonImgUp, VfxImageFrame, this);
    m_buttonImgUp->setResId(VAPP_HS_IMG_WG_RECENT_EVENT_MORE);
    m_button->setBackgroundUp(m_buttonImgUp, VFX_TRUE);

    VFX_OBJ_CREATE(m_buttonImgDown, VfxImageFrame, this);
    m_buttonImgDown->setResId(VAPP_HS_IMG_WG_RECENT_EVENT_MORE_DOWN);
    m_button->setBackgroundDown(m_buttonImgDown, VFX_TRUE);

    // Separate line
    m_lineImgData = vrt_sys_res_image_lock(VAPP_HS_IMG_WG_RECENT_EVENT_SEPARATE_LINE);
    m_lineImgSize = vrt_sys_image_get_size_from_mem(m_lineImgData);
}


void VappHsWidgetRecentEventItem::onDeinit()
{
    VfxControl::onDeinit();
}


void VappHsWidgetRecentEventItem::onDraw(VfxDrawContext &dc)
{
    vrt_u8 *imgData;
    vrt_size_struct size;
    
    // Draw event icon.
    imgData = vrt_sys_res_image_lock(m_iconId);
    size = vrt_sys_image_get_size_from_mem(imgData);

    dc.drawImageFromMem(ICON_X, ICON_Y, imgData);

    // Draw the separate line if it is required.
    if (m_needSeparateLine)
    {
        dc.drawImageFromMem(
            (WIDTH - m_lineImgSize.width) >> 1,
            (0),
            m_lineImgData);
    }
}


void VappHsWidgetRecentEventItem::alignment()
{
    VfxSize subjectSize, hintSize, buttonSize;
    VfxPoint subject_pos, hint_pos, button_pos;
    VfxS32 text_height, startY;

    startY = m_lineImgSize.height / 2;
    subjectSize = m_subject->getBounds().size;
    hintSize = m_hint->getBounds().size;
    buttonSize = m_button->getBounds().size;
    
    text_height = subjectSize.height + TEXT_GAP_Y + hintSize.height;

    // Subject
    subject_pos.x = TEXT_X;
    subject_pos.y = startY + ((HEIGHT - text_height) >> 1);
    m_subject->setPos(subject_pos);

    // Hint
    hint_pos.x = TEXT_X;
    hint_pos.y = startY + subject_pos.y + subjectSize.height + TEXT_GAP_Y;
    m_hint->setPos(hint_pos);

    // Button for option menu
    button_pos.x = BUTTON_X;
    button_pos.y = startY + hint_pos.y + ((hintSize.height - buttonSize.height) >> 1);
    m_button->setPos(button_pos);
}


void VappHsWidgetRecentEventItem::onClick()
{
    m_signalClick.emit(this);
}


void VappHsWidgetRecentEventItem::setSubject(const VfxWString &str)
{
    m_subject->setString(str);
    alignment();
}


void VappHsWidgetRecentEventItem::setHint(const VfxWString &str)
{
    m_hint->setString(str);
    alignment();
}


void VappHsWidgetRecentEventItem::setIcon(VfxS32 iconId)
{
    m_iconId = iconId;
}


void VappHsWidgetRecentEventItem::setBold(VfxBool isBold)
{
    VfxFontDesc font;

    font = m_subject->getFont();
    font.effect = (isBold ? VFX_FONT_DESC_EFFECT_BORDER : VFX_FONT_DESC_EFFECT_NONE);
    m_subject->setFont(font);

    font = m_hint->getFont();
    font.effect = (isBold ? VFX_FONT_DESC_EFFECT_BORDER : VFX_FONT_DESC_EFFECT_NONE);
    m_hint->setFont(font);
}


/***************************************************************************** 
 * Home screen widget: recent event
 *****************************************************************************/

VappHsWidgetRecentEvent::VappHsWidgetRecentEvent() :
    m_body(NULL),
    m_helpText(NULL),
    m_numEvent(0)
{
    for (VfxS32 i = 0; i < MAX_EVENT; i++)
    {
        m_event[i] = NULL;
    }
}


VfxS32 VappHsWidgetRecentEvent::getIcon()
{
    return VAPP_HS_IMG_WG_ICON_RECENT_EVENT;
}


void VappHsWidgetRecentEvent::onCreateView()
{
    VFX_LOG(VFX_STATE, VAPP_HS_RECENT_EVENT_ON_CREATE_VIEW_MSG);
    
    // background image
    VfxImageSrc bgImage;
    bgImage.setResId(VAPP_HS_IMG_WG_RECENT_EVENT_BG);

#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    setIsOpaque(VFX_TRUE);
#endif /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

    setImgContent(bgImage);
    setBounds(VfxRect(VFX_POINT_ZERO, bgImage.getSize()));
    setIsCached(VFX_TRUE);

    // Empty string (centralized in both vertical and horizontal directions)
    VFX_OBJ_CREATE(m_helpText, VfxTextFrame, this);
    m_helpText->setColor(VfxColor(255, 225, 225, 199));
    m_helpText->setFont(VfxFontDesc(g_vfxFontSmall));

    // Connect signal to refresh the recent event time string.
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);

    systemTimeSrv->m_signalTimeChanged.connect(this, &VappHsWidgetRecentEvent::onTimeChanged);
    
    // Connect signal to refresh the recent event lists.
    VdatRecentEvent *recentEventSrv = VFX_OBJ_GET_INSTANCE(VdatRecentEvent);

    recentEventSrv->m_signalEventChanged.connect(this, &VappHsWidgetRecentEvent::onEventChanged);
    recentEventSrv->refresh();

    // Update the scrollable immediately.
    onEventChanged(recentEventSrv);
}


void VappHsWidgetRecentEvent::onReleaseView()
{
    VFX_LOG(VFX_STATE, VAPP_HS_RECENT_EVENT_ON_RELEASE_VIEW_MSG);

    // Disconnect system time signal
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.disconnect(this, &VappHsWidgetRecentEvent::onTimeChanged);
    
    // Disconnect recent event signal
    VdatRecentEvent *recentEventSrv = VFX_OBJ_GET_INSTANCE(VdatRecentEvent);
    recentEventSrv->m_signalEventChanged.disconnect(this, &VappHsWidgetRecentEvent::onEventChanged);

    VFX_OBJ_CLOSE(m_body);
    VFX_OBJ_CLOSE(m_helpText);    
}


void VappHsWidgetRecentEvent::onEventChanged(
    VdatRecentEvent *recentEventSrv)
{    
    VFX_LOG(VFX_STATE, VAPP_HS_RECENT_EVENT_ON_EVENT_CHANGED_MSG);

    // close the previous body
    VFX_OBJ_CLOSE(m_body);

    // Update the help text
    updateHelpText();
    
    // Get the total number of events
    m_numEvent = recentEventSrv->getEventNum();
    
    if (m_numEvent == 0)
    {
        return;
    }

    m_numEvent = (m_numEvent > MAX_EVENT ? MAX_EVENT : m_numEvent);

    // scrollable body
    VFX_OBJ_CREATE(m_body, VcpScrollable, this);
    
    m_body->setPos(VfxPoint(BODY_POS_X, BODY_POS_Y));
    m_body->setBounds(VfxRect(0, 0, BODY_WIDTH, BODY_HEIGHT));
    m_body->setContentSize(VfxSize(BODY_WIDTH, m_numEvent * VappHsWidgetRecentEventItem::HEIGHT));
    m_body->setViewRect(VfxRect(0, 0, BODY_WIDTH, BODY_HEIGHT));

    VfxPoint pos(0, 0);
    
    for (VfxS32 i = 0; i < m_numEvent; i++)
    {
        // Recent event. Separate line isn't needed for the first item.
        if (i == 0)
        {
            VFX_OBJ_CREATE_EX(
                m_event[i], 
                VappHsWidgetRecentEventItem, 
                m_body, 
                (VRT_FALSE));
        }
        else
        {
            VFX_OBJ_CREATE_EX(
                m_event[i], 
                VappHsWidgetRecentEventItem, 
                m_body, 
                (VRT_TRUE));
        }
        
        m_event[i]->m_signalClick.connect(this, &VappHsWidgetRecentEvent::onSelectEvent);
        
        // recent event position
        pos.x = 0;
        m_event[i]->setPos(pos);
        
        pos.y += m_event[i]->getBounds().getHeight();

        VFX_LOG(VFX_INFO, VAPP_HS_RECENT_EVENT_DUMP_DETAIL_CHANGED_MSG,
                            i,
                            recentEventSrv->getEventType(i),
                            0,
                            recentEventSrv->getEventIsRead(i));

        // subject, time
        m_event[i]->setSubject(recentEventSrv->getEventSubject(i));
        m_event[i]->setHint(recentEventSrv->getEventTimeString(i));

        // bold font for unread event
        if (recentEventSrv->getEventIsRead(i))
        {
            m_event[i]->setBold(VFX_FALSE);
        }
        else
        {
            m_event[i]->setBold(VFX_TRUE);
        }

        // icon
        switch (recentEventSrv->getEventType(i))
        {
            case VdatRecentEvent::EVENT_CALL:
            case VdatRecentEvent::EVENT_CALL2:
                m_event[i]->setIcon(VAPP_HS_IMG_WG_RECENT_EVENT_CALL);
                break;

            case VdatRecentEvent::EVENT_SMS:
                m_event[i]->setIcon(VAPP_HS_IMG_WG_RECENT_EVENT_SMS);
                break;

            case VdatRecentEvent::EVENT_MMS:
                m_event[i]->setIcon(VAPP_HS_IMG_WG_RECENT_EVENT_MMS);
                break;

            default:
                break;
        }
    }
}


void VappHsWidgetRecentEvent::onSelectEvent(
    VappHsWidgetRecentEventItem *event)
{
    VdatRecentEvent *recentEventSrv;
    VfxS32 idx;

    VFX_LOG(VFX_STATE, VAPP_HS_RECENT_EVENT_ON_SELECT_EVENT_MSG);
    
    recentEventSrv = VFX_OBJ_GET_INSTANCE(VdatRecentEvent);

    // Find the event        
    for (idx = 0; idx < m_numEvent; idx++)
    {
        if (event == m_event[idx])
        {
            break;
        }
    }
    
    if (idx == m_numEvent)
    {
        return;
    }

    VFX_LOG(VFX_INFO, VAPP_HS_RECENT_EVENT_DUMP_DETAIL_SELECTED_MSG,
                        idx,
                        recentEventSrv->getEventType(idx),
                        0, 
                        recentEventSrv->getEventIsRead(idx));

    // Execute the option menu of this event
    VdatRecentEvent::callback_t cbf = recentEventSrv->getEventCallback(idx);
    void *user_data = recentEventSrv->getEventUserData(idx);
    
    cbf(KEY_LSK, KEY_EVENT_UP, user_data);
}


void VappHsWidgetRecentEvent::onTimeChanged(VfxU32 flag)
{
    if ((flag & VDAT_SYSTIME_CHANGED_DAY) && m_numEvent > 0)
    {
        VdatRecentEvent *recentEventSrv = VFX_OBJ_GET_INSTANCE(VdatRecentEvent);

        // Update the time string of each event.    
        for (VfxS32 i = 0; i < m_numEvent; i++)
        {
            m_event[i]->setHint(recentEventSrv->getEventTimeString(i));
        }
    }
}


void VappHsWidgetRecentEvent::alignment()
{
    VfxImageSrc bgImage;
    bgImage.setResId(VAPP_HS_IMG_WG_RECENT_EVENT_BG);

    VfxSize bgSize   = bgImage.getSize();
    VfxSize textSize = m_helpText->getBounds().size;
    VfxPoint pos;

    // Centralize the help text
    pos.x = (bgSize.width - textSize.width) >> 1;
    pos.y = (bgSize.height - textSize.height) >> 1;
    
    m_helpText->setPos(pos);
}


void VappHsWidgetRecentEvent::updateHelpText()
{
    VdatRecentEvent *recentEventSrv = VFX_OBJ_GET_INSTANCE(VdatRecentEvent);

    if (recentEventSrv->getEventNum() != 0)
    {
        m_helpText->setHidden(VFX_TRUE);
    }
    else
    {
        m_helpText->setHidden(VFX_FALSE);
        
        if (recentEventSrv->getErr() == VdatRecentEvent::ERR_NONE)
        {
            m_helpText->setString(VFX_WSTR_RES(VAPP_HS_STR_WG_RECENT_EVENT_EMPTY));
        }
        else
        {
            m_helpText->setString(VFX_WSTR_RES(STR_GLOBAL_NOT_AVAILABLE));
        }

        alignment();
    }
}

#endif /* __MMI_VUI_HOMESCREEN_RECENT_EVENT__ */

