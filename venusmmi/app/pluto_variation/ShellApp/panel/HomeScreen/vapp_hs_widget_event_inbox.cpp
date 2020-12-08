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
 *  vapp_hs_widget_event_inbox.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Home screen widget: event inbox
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_VUI_HOMESCREEN_EVENT_INBOX__

/* Venus MMI headers: */
#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_system.h"
#include "vrt_datatype.h"
#include "vfx_async_signal.h"
#include "vfx_sys_memory.h"
#include "vfx_basic_type.h"
#include "vfx_text_frame.h"
#include "vfx_string.h"
#include "vcp_button.h"
#include "vfx_signal.h"
#include "vfx_primitive_frame.h"
#include "vapp_hs_widget_event_inbox.h"
#include "vadp_app_trc.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#include "SmsSrvGprot.h"
#include "MmsSrvGprot.h"
#include "UmSrvDefs.h"
#include "umsrvgprot.h"
#include "UMGProt.h"
#include "CallLogSrvGprot.h"
#include "CallLogGprot.h"
#include "mmi_rp_app_venus_homescreen_wg_event_inbox_def.h"

#ifdef __cplusplus
}   /* extern "C" */
#endif


/*****************************************************************************
 * Home screen widget: event inbox
 *****************************************************************************/

VappHsWidgetEventInbox::VappHsWidgetEventInbox() :
    m_title(NULL)
{
    for (VfxS32 i = 0; i < EVT_TOTAL; i++)
    {
        m_button[i] = NULL;
        m_text[i] = NULL;
        m_icon[i] = NULL;
        m_imgDown[i] = NULL;
    }
}


VfxU16 VappHsWidgetEventInbox::getIcon()
{
    return VAPP_HS_IMG_WG_ICON_EVENT_INBOX;
}


VfxU16 VappHsWidgetEventInbox::getName()
{
    return VAPP_HS_STR_WG_EVENT_INBOX;
}


void VappHsWidgetEventInbox::onCreateView()
{
    // background image
    VfxImageSrc bgImage;
    bgImage.setResId(VAPP_HS_IMG_WG_EVENT_INBOX_BG);
    VfxSize size = bgImage.getSize();

    setImgContent(bgImage);
    setBounds(VfxRect(VFX_POINT_ZERO, size));
    setIsCached(VFX_TRUE);

    // Title
    VFX_OBJ_CREATE(m_title, VfxTextFrame, this);
    m_title->setColor(VFX_COLOR_WHITE);
    m_title->setFont(VfxFontDesc(g_vfxFontSmall));
    m_title->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_title->setPos(VfxPoint(size.width / 2, Y_TITLE));
    m_title->setString(VFX_WSTR_RES(VAPP_HS_STR_WG_EVENT_INBOX));

    // Call button
    VcpButtonInternal *button;

    button = createButton(
                EVT_CALL,
                VAPP_HS_IMG_WG_EVENT_INBOX_CALL,
                VAPP_HS_IMG_WG_EVENT_INBOX_CALL_DOWN);

    button->setPos(VfxPoint(X_CALL_BUTTON, Y_ALL_BUTTON));
    button->m_eventUp.connect(this, &VappHsWidgetEventInbox::launchCallInbox);

    // SMS button
    button = createButton(
                EVT_SMS,
                VAPP_HS_IMG_WG_EVENT_INBOX_SMS,
                VAPP_HS_IMG_WG_EVENT_INBOX_SMS_DOWN);

    button->setPos(VfxPoint(X_SMS_BUTTON, Y_ALL_BUTTON));
    button->m_eventUp.connect(this, &VappHsWidgetEventInbox::launchSmsInbox);

    // MMS button
    button = createButton(
                EVT_MMS,
                VAPP_HS_IMG_WG_EVENT_INBOX_MMS,
                VAPP_HS_IMG_WG_EVENT_INBOX_MMS_DOWN);

    button->setPos(VfxPoint(X_MMS_BUTTON, Y_ALL_BUTTON));
    button->m_eventUp.connect(this, &VappHsWidgetEventInbox::launchMmsInbox);

    // Update the counter.
    updateCounter();

    // Register events.
    registerEvent();
}


void VappHsWidgetEventInbox::onReleaseView()
{
    // Deregister events.
    deregisterEvent();

    // Release UI components.
    VFX_OBJ_CLOSE(m_title);

    for (VfxS32 i = 0; i < EVT_TOTAL; i++)
    {
        VFX_OBJ_CLOSE(m_button[i]);
    }
}


VcpButtonInternal *VappHsWidgetEventInbox::createButton(
    evt_type t,
    VfxS32 imgIcon,
    VfxS32 imgDown)
{
    VFX_OBJ_CREATE(m_button[t], VcpButtonInternal, this);

    VFX_OBJ_CREATE(m_imgDown[t], VfxImageFrame, m_button[t]);
    m_imgDown[t]->setResId(imgDown);
    m_button[t]->setBackgroundDown(m_imgDown[t]);

    VfxSize size = m_button[t]->getBounds().size;

    VFX_OBJ_CREATE(m_icon[t], VfxImageFrame, m_button[t]);
    m_icon[t]->setResId(imgIcon);
    m_icon[t]->setAnchor(VfxFPoint(0.0f, 0.5f));
    m_icon[t]->setPos(VfxPoint(X_GAP_ICON, size.height / 2));

    VFX_OBJ_CREATE(m_text[t], VfxTextFrame, m_button[t]);
    m_text[t]->setAnchor(VfxFPoint(1.0f, 0.5f));
    m_text[t]->setColor(VFX_COLOR_WHITE);
    m_text[t]->setFont(VfxFontDesc(g_vfxFontSmall));
    m_text[t]->setPos(VfxPoint(size.width - X_GAP_TEXT, size.height / 2));

    return m_button[t];
}


void VappHsWidgetEventInbox::launch(void *data)
{
    evt_type t = (evt_type)(VfxS32)data;

    switch (t)
    {
        case EVT_CALL:
            mmi_clog_mclt_launch();
            break;

        case EVT_SMS:
            mmi_um_launch_inbox_with_sms_only();
            break;

        case EVT_MMS:
            mmi_um_launch_inbox_with_mms_only();
            break;

        default:
            break;
    }
}


void VappHsWidgetEventInbox::launchCallInbox()
{
    vfxPostInvoke(this, &VappHsWidgetEventInbox::launch, (void *)EVT_CALL);
}


void VappHsWidgetEventInbox::launchSmsInbox()
{
    vfxPostInvoke(this, &VappHsWidgetEventInbox::launch, (void *)EVT_SMS);
}


void VappHsWidgetEventInbox::launchMmsInbox()
{
    vfxPostInvoke(this, &VappHsWidgetEventInbox::launch, (void *)EVT_MMS);
}


void VappHsWidgetEventInbox::updateCounter()
{
    WCHAR strBuf[MAX_STR_BUF_SIZE];
    VfxS32 num;

    //
    // Missed calls
    //
    num = srv_clog_get_unread_missed_call_num();
    num = (num > 99 ? 99 : num);
    kal_wsprintf(strBuf, "%d", num);
    m_text[EVT_CALL]->setString(VFX_WSTR_MEM(strBuf));

    //
    // Unread SMS
    //
    num = srv_sms_get_unread_sms_num();
    num = (num > 99 ? 99 : num);
    kal_wsprintf(strBuf, "%d", num);
    m_text[EVT_SMS]->setString(VFX_WSTR_MEM(strBuf));

    //
    // Unread MMS
    //
    srv_mms_get_msg_count_struct msgCount;
    num = 0;

    if (srv_mms_is_wap_ready())
    {
        memset(&msgCount, 0,sizeof(srv_mms_get_msg_count_struct));

        msgCount.count = 1;
        msgCount.req_tb[0] = SRV_MMS_QUERY_TOTAL_UNREAD_INBOX_MSG;

        S32 result = srv_mms_get_msg_count(&msgCount);

        if (result == SRV_MMS_RESULT_OK)
        {
            num = msgCount.rsp_tb[0];
        }
    }

    num = (num > 99 ? 99 : num);
    kal_wsprintf(strBuf, "%d", num);
    m_text[EVT_MMS]->setString(VFX_WSTR_MEM(strBuf));
}


mmi_ret VappHsWidgetEventInbox::onEventCallback(mmi_event_struct *event)
{
    VappHsWidgetEventInbox *widget = (VappHsWidgetEventInbox *)event->user_data;
    VFX_OBJ_ASSERT_VALID(widget);

    switch (event->evt_id)
    {
        case EVT_ID_SRV_SMS_READY:      /* fall through */
        case EVT_ID_SRV_SMS_ADD_MSG:    /* fall through */
        case EVT_ID_SRV_SMS_DEL_MSG:    /* fall through */
        case EVT_ID_SRV_SMS_UPDATE_MSG: /* fall through */
        case EVT_ID_SRV_MMS_READY:      /* fall through */
        case EVT_ID_JSR_DELETE_MMS:
            widget->updateCounter();
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


void VappHsWidgetEventInbox::registerEvent()
{
    mmi_frm_cb_reg_event(
        EVT_ID_SRV_SMS_READY,
        VappHsWidgetEventInbox::onEventCallback,
        this);

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_SMS_ADD_MSG,
        VappHsWidgetEventInbox::onEventCallback,
        this);

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_SMS_DEL_MSG,
        VappHsWidgetEventInbox::onEventCallback,
        this);

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_SMS_UPDATE_MSG,
        VappHsWidgetEventInbox::onEventCallback,
        this);

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_MMS_READY,
        VappHsWidgetEventInbox::onEventCallback,
        this);

    mmi_frm_cb_reg_event(
        EVT_ID_JSR_DELETE_MMS,
        VappHsWidgetEventInbox::onEventCallback,
        this);
}


void VappHsWidgetEventInbox::deregisterEvent()
{
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_SMS_READY,
        VappHsWidgetEventInbox::onEventCallback,
        this);

    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_SMS_ADD_MSG,
        VappHsWidgetEventInbox::onEventCallback,
        this);

    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_SMS_DEL_MSG,
        VappHsWidgetEventInbox::onEventCallback,
        this);

    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_SMS_UPDATE_MSG,
        VappHsWidgetEventInbox::onEventCallback,
        this);

    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_MMS_READY,
        VappHsWidgetEventInbox::onEventCallback,
        this);

    mmi_frm_cb_dereg_event(
        EVT_ID_JSR_DELETE_MMS,
        VappHsWidgetEventInbox::onEventCallback,
        this);
}

#endif /* __MMI_VUI_HOMESCREEN_EVENT_INBOX__ */

