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
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH��
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
 *  vcp_msg_misc_cp.cpp
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#define VAPP_MSG_MS_TIMER_PERIOD 300
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"  
#include "vapp_msg.h"
#include "vapp_msg_misc_cp.h"
#include "vapp_msg_gprot.h"
#include "vapp_sms_viewer.h"
#ifdef __MMI_MMS_IN_UM__
#include "vapp_mms_lite_viewer.h"
#endif /* __MMI_MMS_IN_UM__ */
#ifdef __MMI_PUSH_IN_UM__
#include "vapp_wap_push_viewer.h"
#endif /* __MMI_MMS_IN_UM__ */
#ifdef __MMI_PROV_IN_UM__
#include "vapp_prov_viewer.h"
#endif /* __MMI_PROV_IN_UM__ */

#include "vapp_ncenter_base_cell.h"
#include "vapp_sms_gprot.h"
#include "vapp_phb_gprot.h"
#include "vapp_contact_entry.h"
#include "vapp_sim_setting_gprot.h" /* vapp_sim_settings_get_sim_name_with_sim_id */
#include "vcp_global_popup.h"

#ifdef __MMI_USB_SUPPORT__
#include "Vapp_usb_gprot.h"
#endif /* __MMI_USB_SUPPORT__ */

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
#endif
{
    #include "mmi_rp_vapp_msg_def.h"
    #include "SmsSrvGprot.h"
    #include "MmsSrvGprot.h"
    #include "Mma_api.h"
#ifdef __MMI_PUSH_IN_UM__
    #include "WAPPushSrvGprots.h"
#endif /* __MMI_PUSH_IN_UM__ */
    #include "Wgui_categories_util.h" /* wgui_status_icon_bar_show_icon */
    #include "Mmi_frm_events_gprot.h" /* nmgr event */
    #include "PhbSrvGprot.h" /* srv_phb_get_name_by_number */
    #include "custom_phb_config.h" /* MMI_PHB_NAME_LENGTH */
#ifdef __MMI_PROV_IN_UM__
    #include "ProvBoxSrvGProt.h" /* srv_provbox_get_msg_status, srv_provbox_set_msg_status */
    #include "mmi_rp_srv_provbox_def.h" /* EVT_ID_SRV_PROVBOX_NOTIFY_IND */
#endif /* __MMI_PROV_IN_UM__ */
    #include "Gui_typedef.h" /* STATUS_ICON_MESSAGE_UNREAD */
    #include "Mmi_rp_app_cosmos_global_def.h" /* IMG_COSMOS_SEPARATOR_LINE */
    #include "SimCtrlSrvGprot.h" /* srv_sim_ctrl_get_num_of_inserted */
    #include "mmi_frm_utility_gprot.h" /* MMI_SIM_ALL */
}

//NCenter 2.0
#include "vsrv_notification.h"
#include "vsrv_ncenter.h"
#include "vsrv_ndeclaration.h"
#include "vapp_msg_ncenter_gprot.h"

//NSS
#include "mmi_rp_srv_status_icons_def.h"

VFX_IMPLEMENT_CLASS("VappMsgDialogCellCp", VappMsgDialogCellCp, VappMsgDialogCell);

VappMsgDialogCellCp::VappMsgDialogCellCp(VfxU32 index, VfxU32 msgId, srv_um_msg_enum msgType) :
    VappMsgDialogCell(VcpMenuPos(0, index), VappMsgDialogCell::LEFT, VappMsgDialogCell::NORMAL),
    m_index(index), 
    m_msgId(msgId), 
    m_msgType(msgType), 
    m_msgViewer(NULL), 
    m_isCellDiabled(VFX_FALSE)
{
}

void VappMsgDialogCellCp::setMsgInfo(VfxU32 index, VfxU32 msgId, srv_um_msg_enum msgType)
{
    m_index = index;
    m_msgId = msgId;
    m_msgType = msgType;

    m_msgViewer->setMsgId(m_msgId);
    m_msgViewer->setMsgType(m_msgType);

    /* forceupdate to get the latest time stampe */
    m_msgViewer->forceUpdate();
#ifdef __MMI_MMS_IN_UM__
    VappMMSLiteViewer *mms;
    mms = VFX_OBJ_DYNAMIC_CAST(m_msgViewer, VappMMSLiteViewer);
    if (SRV_UM_MSG_MMS == m_msgType &&
        NULL != mms &&
        VFX_TRUE == mms->isMsgInValid())
    {
        /* invalid MMS, corrupted MMS */
        setTime(VFX_WSTR_EMPTY);
    }
    else
#endif /* __MMI_MMS_IN_UM__ */
    {
        /* set time */
        VfxU32 localSec = 0;
        VfxU32 timestamp;
        applib_time_struct dateTime;

        vfx_sys_mem_zero(&dateTime, sizeof(applib_time_struct));
        timestamp = m_msgViewer->getTimestamp();
        localSec = applib_dt_sec_utc_to_local(timestamp);
        mmi_dt_utc_sec_2_mytime(localSec, &dateTime, MMI_FALSE);

        VfxDateTime time;
        time.setDateTime(&dateTime);
        setTime(time.getDateTimeString(VFX_DATE_TIME_FORMAT_AUTO_DETECT_DATE_DISPLAY));
    }
    setSide(getMsgBox() == SRV_UM_MSG_BOX_INBOX ? VappMsgDialogCell::LEFT : VappMsgDialogCell::RIGHT);

    needRelayout();
}

void VappMsgDialogCellCp::setCellDisabled(VfxBool isDisabled)
{
    m_isCellDiabled = isDisabled;
}

VfxU32 VappMsgDialogCellCp::getIndex() const
{
    return m_index;
}

VfxU32 VappMsgDialogCellCp::getMsgId() const
{
    return m_msgId;
}

srv_um_msg_enum VappMsgDialogCellCp::getMsgType() const
{
    return m_msgType;
}

srv_um_msg_box_enum VappMsgDialogCellCp::getMsgBox() const
{
    if ((0 == m_msgId && SRV_UM_MSG_SMS != m_msgType) || SRV_UM_MSG_NONE == m_msgType)
    {
        return SRV_UM_MSG_BOX_NONE;
    }

    srv_um_msg_box_enum msgBox = SRV_UM_MSG_BOX_INBOX;

    switch (m_msgType)
    {
        case SRV_UM_MSG_SMS:
        {
            srv_sms_box_enum smsBox = SRV_SMS_BOX_NONE;
            srv_sms_get_msg_list_index(&smsBox, m_msgId);
            switch (smsBox)
            {
                case SRV_SMS_BOX_INBOX:
                    msgBox = SRV_UM_MSG_BOX_INBOX;
                    break;
                case SRV_SMS_BOX_OUTBOX:
                    msgBox = SRV_UM_MSG_BOX_SENT;
                    break;
                case SRV_SMS_BOX_DRAFTS:
                    msgBox = SRV_UM_MSG_BOX_DRAFT;
                    break;
                case SRV_SMS_BOX_UNSENT:
                    msgBox = SRV_UM_MSG_BOX_UNSENT;
                    break;
                default:
                    msgBox = SRV_UM_MSG_BOX_NONE;
                    break;
            }
        }
            break;

    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
        {
            mma_folder_enum mmsBox = MMA_FOLDER_NONE;
            mmsBox = mma_get_box(m_msgId);
            switch (mmsBox)
            {
                case MMA_FOLDER_INBOX:
                    msgBox = SRV_UM_MSG_BOX_INBOX;
                    break;
                case MMA_FOLDER_OUTBOX:
                    msgBox = SRV_UM_MSG_BOX_UNSENT;
                    break;
                case MMA_FOLDER_SENT:
                    msgBox = SRV_UM_MSG_BOX_SENT;
                    break;
                case MMA_FOLDER_DRAFT:
                    msgBox = SRV_UM_MSG_BOX_DRAFT;
                    break;
                default:
                    msgBox = SRV_UM_MSG_BOX_NONE;
                    break;
            }
        }
            break;
    #endif /* __MMI_MMS_IN_UM__ */

        case SRV_UM_MSG_WAP_PUSH:
        case SRV_UM_MSG_PROV:
            msgBox = SRV_UM_MSG_BOX_INBOX;
            break;

        default:
            break;
    }

    return msgBox;
}

void VappMsgDialogCellCp::onInit()
{
    VappMsgDialogCell::onInit();

    m_msgViewer = createViewer(VappMsgViewerCp::VAPP_MSG_VIEWER_LITE, m_msgId, m_msgType, this);
    m_msgViewer->m_signalContentReady.connect(this, &VappMsgDialogCellCp::onMsgViewerContentReady);
    setContentFrame(m_msgViewer);
    setTime(VFX_WSTR_EMPTY); /* initial, emtpy */
    setSide(getMsgBox() == SRV_UM_MSG_BOX_INBOX ? VappMsgDialogCell::LEFT : VappMsgDialogCell::RIGHT);

    needRelayout();
}

void VappMsgDialogCellCp::forceUpdateContent()
{
    VfxFrame *content;
    content = getContentFrame();
    if (NULL != content)
    {
        if ( content->isKindOf(VFX_OBJ_CLASS_INFO(VappMsgViewerCp)) )
        {
            ((VappMsgViewerCp *)content)->forceUpdate();
        }
    }
}

VfxBool VappMsgDialogCellCp::isDisabled()
{
    return m_isCellDiabled;
}

VappMsgViewerCp *VappMsgDialogCellCp::createViewer(VfxU32 type, VfxU32 msgId, VfxU32 msgType, VfxObject *parent)
{
    VappMsgViewerCp *viewer;
    switch (msgType)
    {
        case SRV_UM_MSG_SMS:
            VappSmsLiteViewer *smsViewerCp;
            VFX_OBJ_CREATE(smsViewerCp, VappSmsLiteViewer, parent);
            smsViewerCp->setMsgId(msgId);
            return smsViewerCp;

    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
            VappMMSLiteViewer *mmsViewerCp;
            VFX_OBJ_CREATE_EX(mmsViewerCp, VappMMSLiteViewer, parent, (msgId));
            return mmsViewerCp;
    #endif /* __MMI_MMS_IN_UM__ */

    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
            VappWapPushLiteViewerCp *pushViewerCp;
            VFX_OBJ_CREATE_EX(pushViewerCp, VappWapPushLiteViewerCp, parent, (msgId));
            return pushViewerCp;
    #endif /* __MMI_PUSH_IN_UM__ */

    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
            VappProvViewerCp *provViewerCp;
            VFX_OBJ_CREATE_EX(provViewerCp, VappProvViewerCp, parent, (VappMsgViewerCp::VAPP_MSG_VIEWER_LITE, msgId, SRV_UM_MSG_PROV));
            return provViewerCp;
    #endif /* __MMI_PROV_IN_UM__ */

        default:
            VFX_OBJ_CREATE_EX(viewer, VappMsgViewerCp, parent, (type, msgId, msgType));
            break;
    }
    return viewer;
}

void VappMsgDialogCellCp::onMsgViewerContentReady(VfxObject * obj,VfxBool isReady)
{
    if (VFX_FALSE == isReady)
    {
        return;
    }
    else
    {
        setReadyForAnimation(isReady);
    }

    /* set latest timestamp */
    /* forceupdate to get the latest time stampe */
    m_msgViewer->forceUpdate();
#ifdef __MMI_MMS_IN_UM__
    VappMMSLiteViewer *mms;
    mms = VFX_OBJ_DYNAMIC_CAST(m_msgViewer, VappMMSLiteViewer);
    if (SRV_UM_MSG_MMS == m_msgType &&
        NULL != mms &&
        VFX_TRUE == mms->isMsgInValid())
    {
        /* invalid MMS, corrupted MMS */
        setTime(VFX_WSTR_EMPTY);
    }
    else
#endif /* __MMI_MMS_IN_UM__ */
    {
        /* set time */
        VfxU32 localSec = 0;
        VfxU32 timestamp;
        applib_time_struct dateTime;

        vfx_sys_mem_zero(&dateTime, sizeof(applib_time_struct));
        timestamp = m_msgViewer->getTimestamp();
        localSec = applib_dt_sec_utc_to_local(timestamp);
        mmi_dt_utc_sec_2_mytime(localSec, &dateTime, MMI_FALSE);

        VfxDateTime time;
        time.setDateTime(&dateTime);
        setTime(time.getDateTimeString(VFX_DATE_TIME_FORMAT_AUTO_DETECT_DATE_DISPLAY));
    }

    // call ready for menu
    getMenu()->checkReadyForAnimation(obj, isReady);
}


VFX_IMPLEMENT_CLASS("VappMsgDialogListCp", VappMsgDialogListCp, VcpVarHeightMenu);

VappMsgDialogListCp::VappMsgDialogListCp(VcpVarHeightMenu::VcpVarHeightMenuLayoutType type):
    VcpVarHeightMenu(type), // set scroll_to_bottom to true
    m_contentProvider(NULL), 
    m_mode(VAPP_MSG_DIALOG_LIST_CP_MODE_NORMAL), 
    m_defaultCellHeight(0),
    m_hasPlayAnimation(VFX_FALSE)
{
}

void VappMsgDialogListCp::setProvider(IVappMsgDialogListContentProvider *provider)
{
    m_contentProvider = provider;
}

void VappMsgDialogListCp::setMode(VappMsgDialogListCpModeEnum newMode, VfxBool isUpdateExistCell)
{
    if (m_mode == newMode)
    {
        return;
    }
    m_mode = newMode;

    if (VFX_TRUE == isUpdateExistCell)
    {
        // reset the list, get the list cell to change as checkbox mode
        VcpVarHeightMenuCurCellsIter cellList = getCurrentCellsIter();
        while (!cellList.isEnd())
        {
            VcpVarHeightMenuCell *cell;
            VappMsgDialogCellCp *dialogCell;
            cell = cellList.next();
            dialogCell = VFX_OBJ_DYNAMIC_CAST(cell, VappMsgDialogCellCp);
            VFX_ASSERT(NULL != dialogCell);
            if (VAPP_MSG_DIALOG_LIST_CP_MODE_NORMAL == m_mode)
            {
                dialogCell->setStyle(VappMsgDialogCell::NORMAL, VFX_TRUE);
                dialogCell->setCellDisabled(m_contentProvider->getCellIsDisabled(dialogCell->getIndex()));
            }
            else
            {
                dialogCell->setStyle(VappMsgDialogCell::CHECKBOX, VFX_TRUE);
                dialogCell->setCellDisabled(m_contentProvider->getCellIsDisabled(dialogCell->getIndex()));
            }
        }
    }
}

void VappMsgDialogListCp::setMarkAll(VfxBool isMark)
{
    if (VAPP_MSG_DIALOG_LIST_CP_MODE_NORMAL == m_mode)
    {
        return;
    }

    // reset the list, get the list cell to set as "isMark"
    VcpVarHeightMenuCurCellsIter cellList = getCurrentCellsIter();
    while (!cellList.isEnd())
    {
        VcpVarHeightMenuCell *cell;
        VappMsgDialogCellCp *dialogCell;
        cell = cellList.next();
        dialogCell = VFX_OBJ_DYNAMIC_CAST(cell, VappMsgDialogCellCp);
        VFX_ASSERT(NULL != dialogCell);
        if (VFX_TRUE != m_contentProvider->getCellIsDisabled(dialogCell->getIndex()))
        {
            dialogCell->setMark(isMark);
        }
    }
}

VappMsgDialogListCpModeEnum VappMsgDialogListCp::getMode() const
{
    return m_mode;
}

VfxFrame *VappMsgDialogListCp::createCell(VfxS32 group, VfxS32 pos)
{
    VfxFrame *cell;
    cell = intCreateCell(group, pos);

    return cell;
}

VfxU32 VappMsgDialogListCp::getCount()
{
    if (NULL == m_contentProvider)
    {
        return 0;
    }

    return m_contentProvider->getCount();
}

/* No need to override this function now because VcpVarHeightMenu design change*/
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
#endif
/* under construction !*/
#endif
VfxBool VappMsgDialogListCp::getMenuEmptyText(VfxWString & text,VcpListMenuTextColorEnum & color)
{
    /* no content provider */
    if (NULL == m_contentProvider)
    {
        text.loadFromRes(STR_ID_VAPP_MSG_NO_MESSAGES);
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

        return VFX_TRUE;
    }

    /* loading finished */
    if (VFX_FALSE == m_contentProvider->getLoadingStatus())
    {
        text.loadFromRes(STR_ID_VAPP_MSG_NO_MESSAGES);
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

        return VFX_TRUE;
    }

    return VFX_FALSE;
}

void VappMsgDialogListCp::reset()
{   
    VfxS32 count = getCount();

    setCount(count);
    setDefaultHeight(VappMsgDialogCell::BUBBLE_MIN_HEIGHT);
    if (!m_hasPlayAnimation)
    {
        setIsUnhittable(VFX_TRUE);
        
        unregisterKeyHandler(VFX_KEY_CODE_SPECIAL_ALL_ARROW);
    }
    
    VcpVarHeightMenu::reset();
}

void VappMsgDialogListCp::onInit()
{
    VcpVarHeightMenu::onInit();


    /* compute the default cell size */
    VappMsgDialogCellCp *cell;
    VFX_OBJ_CREATE(cell, VappMsgDialogCellCp, this);
    m_defaultCellHeight = cell->getSize().height;
    VFX_OBJ_CLOSE(cell);

    m_signalBoundsChanged.connect(this, &VappMsgDialogListCp::onBoundsChanged);
}

VfxFrame *VappMsgDialogListCp::intCreateCell(VfxU32 group, VfxU32 index)
{
    VFX_ASSERT(NULL != m_contentProvider);

    VfxU32 msgId = 0;
    VappMsgDialogCellCp *cell = NULL;
    srv_um_msg_enum msgType = SRV_UM_MSG_NONE;
    /* get the message information */
    m_contentProvider->getItemInfo(index, msgId, msgType);

    if(SRV_UM_MSG_NONE != msgType)
    {
        if (VAPP_MSG_DIALOG_LIST_CP_MODE_NORMAL == m_mode)
        {
            VFX_OBJ_CREATE_EX(cell, VappMsgDialogCellCp, this, (index, msgId, msgType));
            cell->setCellDisabled(m_contentProvider->getCellIsDisabled(cell->getIndex()));
        }
        else
        {
            VFX_OBJ_CREATE_EX(cell, VappMsgDialogCellCp, this, (index, msgId, msgType));
            /* get mark status and set to cell */
            cell->setStyle(VappMsgDialogCell::CHECKBOX, VFX_FALSE);
            cell->setMark(m_contentProvider->getMarkStatus(index));
            cell->setCellDisabled(m_contentProvider->getCellIsDisabled(cell->getIndex()));
        }
        cell->setSize(getSize().width, cell->getSize().height);

        cell->m_signalTapped.connect(this, &VappMsgDialogListCp::onCellTapped);
        cell->m_signalMarked.connect(this, &VappMsgDialogListCp::onCellMarked);
        cell->m_signalLongPressed.connect(this, &VappMsgDialogListCp::onCellLongPressed);
        cell->m_signalAnimationPlayed.connect(this, &VappMsgDialogListCp::onCellAnimationPlayed);
    }
    return cell;
}

void VappMsgDialogListCp::onCellTapped(VcpVarHeightMenuCell *varHeightCell)
{
    VappMsgDialogCellCp *cell;
    cell = VFX_OBJ_DYNAMIC_CAST(varHeightCell, VappMsgDialogCellCp);

    VFX_ASSERT(NULL != cell);
    if (VFX_TRUE != cell->isValid() || VFX_TRUE != cell->isKindOf(VFX_OBJ_CLASS_INFO(VappMsgDialogCellCp)))
    {
        VFX_ASSERT(0);
    }
    // send out the event
    if (VAPP_MSG_DIALOG_LIST_CP_MODE_NORMAL == m_mode)
    {
        m_signalCellTapped.postEmit(this, cell->getIndex(), cell->getMsgId(), cell->getMsgType());
    }
}

void VappMsgDialogListCp::onCellMarked(VfxControl * control, VfxBool isMarked)
{
    VappMsgDialogCellCp *cell;
    cell = VFX_OBJ_DYNAMIC_CAST(control, VappMsgDialogCellCp);

    VFX_ASSERT(NULL != cell);
    if (VFX_TRUE != cell->isValid() || VFX_TRUE != cell->isKindOf(VFX_OBJ_CLASS_INFO(VappMsgDialogCellCp)))
    {
        VFX_ASSERT(0);
    }
    // send out the event
    m_signalCellMarked.postEmit(this, cell->getIndex(), isMarked);
}

void VappMsgDialogListCp::onCellLongPressed(VcpVarHeightMenuCell *varHeightCell)
{
    VappMsgDialogCellCp *cell;
    cell = VFX_OBJ_DYNAMIC_CAST(varHeightCell, VappMsgDialogCellCp);

    VFX_ASSERT(NULL != cell);
    if (VFX_TRUE != cell->isValid() || VFX_TRUE != cell->isKindOf(VFX_OBJ_CLASS_INFO(VappMsgDialogCellCp)))
    {
        VFX_ASSERT(0);
    }
    if (VAPP_MSG_DIALOG_LIST_CP_MODE_NORMAL == m_mode)
    {
        m_signalCellLongPressed.postEmit(this, cell->getMsgBox(), cell->getMsgId(), cell->getMsgType());
    }
}

void VappMsgDialogListCp::onCellAnimationPlayed()
{    
    if(!m_hasPlayAnimation)
    {
	setIsUnhittable(VFX_FALSE);
        registerKeyHandler(VFX_KEY_CODE_SPECIAL_ALL_ARROW);
        m_hasPlayAnimation = VFX_TRUE;
    }
}

void VappMsgDialogListCp::onBoundsChanged(VfxFrame *frame, const VfxRect &rect)
{
    VappMsgDialogListCp *listCp = VFX_OBJ_DYNAMIC_CAST(frame, VappMsgDialogListCp);

    if (listCp->getSize().width != rect.getWidth())
    {
        for(int i = 0; i < getCellCount(); i++)
        {
            VappMsgDialogCellCp *cell = VFX_OBJ_DYNAMIC_CAST(getCellIfPresent(0, i), VappMsgDialogCellCp);

            if (cell)
            {
                cell->setSize(listCp->getSize().width, cell->getSize().height);
            }
        }
    }
}

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
    #endif
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
/* under construction !*/
/* under construction !*/
#endif

VFX_IMPLEMENT_CLASS("VappMsgCntxOptItemCp", VappMsgCntxOptItemCp, VcpMenuPopupItem);

VappMsgCntxOptItemCp::VappMsgCntxOptItemCp():
    m_msgId(0), 
    m_msgType(SRV_UM_MSG_NONE), 
    m_index(0), 
    m_thrdIdType(0), 
    m_thrdIdValue(0)
{
}

VfxU32 VappMsgCntxOptItemCp::getMsgId() const
{
    return m_msgId;
}

srv_um_msg_enum VappMsgCntxOptItemCp::getMsgType() const
{
    return m_msgType;
}

VfxU32 VappMsgCntxOptItemCp::getIndex() const
{
    return m_index;
}

VfxU32 VappMsgCntxOptItemCp::getThrdIdType() const
{
    return m_thrdIdType;
}

VfxU64 VappMsgCntxOptItemCp::getThrdIdValue() const
{
    return m_thrdIdValue;
}

void VappMsgCntxOptItemCp::setMsgId(VfxU32 msgId)
{
    m_msgId = msgId;
}

void VappMsgCntxOptItemCp::setMsgType(srv_um_msg_enum msgType)
{
    m_msgType = msgType;
}

void VappMsgCntxOptItemCp::setIndex(VfxU32 index)
{
    m_index = index;
}

void VappMsgCntxOptItemCp::setThrdIdType(VfxU32 thrdIdType)
{
    m_thrdIdType = thrdIdType;
}

void VappMsgCntxOptItemCp::setThrdIdValue(VfxU64 thrdIdValue)
{
    m_thrdIdValue = thrdIdValue;
}

void VappMsgCntxOptItemCp::onInit()
{
    VcpMenuPopupItem::onInit();
}


VFX_IMPLEMENT_CLASS("VappMessageList", VappMessageList, VfxObject);

VappMessageList::VappMessageList(VfxU32 msgType, VfxU32 boxType, VfxU32 simType, VappMessageListStyleEnum style):
    m_isMsActionActive(VFX_FALSE), 
    m_listId(0), 
    m_list(NULL), 
    m_msList(NULL), 
    m_msMarkStatus(NULL), 
    m_numMarked(0), 
    m_msgDataProvider(NULL), 
    m_style(style), 
    m_updateMsgInfoListSize(0), 
    m_updateMsgInfoList(NULL), 
    m_isResetList(VFX_FALSE)
{
    m_boxId.msg_type = (srv_um_msg_enum) msgType;
    m_boxId.msg_box_type = (srv_um_msg_box_enum) boxType;
    m_boxId.sim_id = (srv_um_sim_enum) simType;

    m_listFilter.idx_type = SRV_UM_LIST_IDX_TIMESTAMP;
    m_listFilter.order = SRV_UM_SORT_ORDER_UNCLASSIFIED;
#ifdef __MMI_UM_CONVERSATION_BOX__
    vfx_sys_mem_zero(&m_listFilter.thread_id, sizeof(srv_um_thread_id_struct));
#endif /* __MMI_UM_CONVERSATION_BOX__ */
}

void VappMessageList::setThreadId(const srv_um_thread_id_struct threadId)
{
    vfx_sys_mem_copy((void *)&(m_listFilter.thread_id), (void *)&threadId, sizeof(srv_um_thread_id_struct));

    /* already has list, release it */
    resetList(VFX_FALSE);
}

void VappMessageList::setMsgType(const VfxU32 msgType)
{
    m_boxId.msg_type = (srv_um_msg_enum) msgType;

    /* alread has list, release it */
    resetList(VFX_FALSE);
}

void VappMessageList::setBoxType(const VfxU32 boxType)
{
    m_boxId.msg_box_type = (srv_um_msg_box_enum) boxType;

    /* already has list, release it */
    resetList(VFX_FALSE);
}

void VappMessageList::setSortType(const srv_um_list_idx_enum index)
{
    if (SRV_UM_LIST_IDX_MSG_TYPE == index)
    {
        m_listFilter.order = SRV_UM_SORT_ORDER_DESCENDING;
    }
    else
    {
        m_listFilter.order = SRV_UM_SORT_ORDER_UNCLASSIFIED;
    }
    m_listFilter.idx_type = index;

    /************************************** 
     * already has list, release it       *
     * New sorting type, it must clean    *
     * the list, it may changed because   *
     * of some status change(read/unread) *
     *************************************/
    resetList(VFX_TRUE);
}

void VappMessageList::setStyle(const VappMessageListStyleEnum style)
{
    m_style = style;

    /* already has list, release it */
    resetList(VFX_FALSE);
}

void VappMessageList::setMarkStatus(const VfxU32 index, const VfxBool isMark)
{
    if (VFX_TRUE == m_isMsActionActive)
    {
        return;
    }

    if (VFX_TRUE == generateMsList(VFX_FALSE))
    {
        if (VFX_TRUE == m_isResetList)
        {
            // reset list, need to update ms status
            updateMsList();
            m_isResetList = VFX_FALSE;
        }

        VfxU16 setIdx;
        VfxU16 reminding;
        setIdx = index / 32;
        reminding = index - (setIdx * 32);

        if (VFX_FALSE == isMark && ((m_msMarkStatus[setIdx] >> (32 - 1 - reminding)) & 1))
        {
            m_numMarked--;
            /* reset as unmarked */
            m_msMarkStatus[setIdx] &= ~(1 << (32 - 1 - reminding));
        }
        else if (VFX_TRUE == isMark && !((m_msMarkStatus[setIdx] >> (32 - 1 - reminding)) & 1))
        {
            m_numMarked++;
            /* set as marked */
            m_msMarkStatus[setIdx] |= (1 << (32 - 1 - reminding));
        }
        else
        {
            /* do nothing */
        }
    }
}

void VappMessageList::setMarkAll(VfxBool isMark, srv_um_msg_enum msgType, VappMessageListCopyStorageEnum storage)
{
    if (VFX_TRUE == m_isMsActionActive)
    {
        return;
    }

    if (VFX_TRUE == generateMsList(VFX_FALSE))
    {
        if (VFX_TRUE == m_isResetList)
        {
            // reset list, need to update ms status
            updateMsList();
            m_isResetList = VFX_FALSE;
        }

        if (SRV_UM_MSG_ALL == msgType)
        {
            if (VFX_TRUE == isMark)
            {
                memset(m_msMarkStatus, 0xff, sizeof(VfxU32) * (m_msList->msg_number/32 + 1));
                m_numMarked = m_msList->msg_number;
            }
            else
            {
                vfx_sys_mem_zero(m_msMarkStatus, sizeof(VfxU32) * (m_msList->msg_number/32 + 1));
                m_numMarked = 0;
            }
        }
        else
        {
            if (VAPP_MESSAGE_LIST_COPY_STORAGE_NONE == storage ||
                VAPP_MESSAGE_LIST_COPY_STORAGE_ARCHIVE == storage)
            {
                /* traverse all message to mark all or unmark all */
                VfxU32 i;
                for (i = 0 ; i < m_list->msg_number ; i++)
                {
                    /* need to handle */
                    if (getMsgType(i) & msgType)
                    {
                        setMarkStatus(i, isMark);
                    }
                }
            }
            else
            {
                /* traverse all message to mark all or unmark all */
                VfxU32 i;
                for (i = 0 ; i < m_list->msg_number ; i++)
                {
                    if (SRV_UM_MSG_SMS & msgType)
                    {
                        if (SRV_UM_MSG_SMS == getMsgType(i) &&
                            (VAPP_MESSAGE_LIST_COPY_STORAGE_SIM1 <= storage &&
                             VAPP_MESSAGE_LIST_COPY_STORAGE_SIM4 >= storage))
                        {
                            setMarkStatus(i, isMark);
                        }
                        else if (VAPP_MESSAGE_LIST_COPY_STORAGE_PHONE == storage && 
                            SRV_SMS_STORAGE_TCARD == srv_sms_get_msg_storage_type(getMsgId(i)))
                        {
                            setMarkStatus(i, isMark);
                        }
                        else if (VAPP_MESSAGE_LIST_COPY_STORAGE_MEMORY_CARD == storage && 
                                 SRV_SMS_STORAGE_ME == srv_sms_get_msg_storage_type(getMsgId(i)))
                        {
                            setMarkStatus(i, isMark);
                        }
                        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                        #endif
                    }
                    else if (SRV_UM_MSG_MMS & msgType)
                    {
                    #ifdef __MMI_MMS_IN_UM__
                        if (SRV_UM_MSG_MMS == getMsgType(i))
                        {
                            if (VAPP_MESSAGE_LIST_COPY_STORAGE_PHONE == storage && 
                                SRV_MMS_STORAGE_CARD1 == srv_mms_get_msg_storage(getMsgId(i)))
                            {
                                setMarkStatus(i, isMark);
                            }
                            else if (VAPP_MESSAGE_LIST_COPY_STORAGE_MEMORY_CARD == storage && 
                                     SRV_MMS_STORAGE_PHONE == srv_mms_get_msg_storage(getMsgId(i)))
                            {
                                setMarkStatus(i, isMark);
                            }
                        }
                    #endif /* __MMI_MMS_IN_UM__ */
                    }
                }
            }
        }
    }
}

VfxS32 VappMessageList::getCount()
{
    if (MMI_FALSE == srv_um_check_ready_type(m_boxId.msg_type))
    {
        return -1;
    }

    // Start to get the list
    VfxS32 numOfList = 0;

    if (NULL == m_list)
    {
        VfxS32 result = -1;

        if (VAPP_MESSAGE_LIST_STYLE_NORMAL == m_style)
        {
            result = m_msgDataProvider->getMsgList(
                        m_boxId, 
                        m_listFilter, 
                        VappMessageList::onMsgListStatusCb, 
                        (VfxS32)getObjHandle(), 
                        m_list);
        }
        else
        {
            result = m_msgDataProvider->getThreadList(
                        m_boxId, 
                        m_listFilter, 
                        VappMessageList::onMsgListStatusCb, 
                        (VfxS32)getObjHandle(), 
                        m_list);
        }
        
        if (result < SRV_UM_RESULT_OK)
        {
            numOfList = -1;
        }
        else
        {
            numOfList = m_list->msg_number;
            m_listId = result;
            m_isResetList = VFX_TRUE;
        }

    }
    else
    {
        numOfList = m_list->msg_number;
        if (NULL == m_updateMsgInfoList)
        {
            if (0 != numOfList)
            {
                VFX_ALLOC_MEM(m_updateMsgInfoList, sizeof(VfxBool)*numOfList, this);
                vfx_sys_mem_zero(m_updateMsgInfoList, sizeof(VfxBool)*numOfList);
            }
            m_updateMsgInfoListSize = numOfList;
        }
    }

    return numOfList;
}

VfxBool VappMessageList::getMsgInfo(const VfxU32 index, srv_um_msg_info_struct *&msgInfo)
{
    VFX_ASSERT(NULL != m_msgDataProvider);
    if (NULL == m_list)
    {
        return VFX_FALSE;
    }

    VfxS32 result = -1;
    srv_um_msg_info_struct *msgInfoRef[1];

    msgInfoRef[0] = NULL;
    if (VAPP_MESSAGE_LIST_STYLE_NORMAL == m_style)
    {
        result = m_msgDataProvider->getMsgInfo(
                        (srv_um_msg_node_struct *)(m_list->list), 
                        m_list->msg_number, 
                        (VfxU16) index, 
                        1, 
                        msgInfoRef);
    }
    else
    {
        srv_um_thread_info_struct *threadInfoRef[1];

        threadInfoRef[0] = NULL;
        result = m_msgDataProvider->getThreadInfo(
                        (srv_um_thread_id_struct *)(m_list->list), 
                        m_list->msg_number, 
                        (VfxU16) index, 
                        1, 
                        threadInfoRef, 
                        msgInfoRef);
    }

    msgInfo = msgInfoRef[0];
    if (result < SRV_UM_RESULT_OK)
    {
        VFX_ASSERT(NULL != m_updateMsgInfoList);
        m_updateMsgInfoList[index] = VFX_TRUE;
        return VFX_FALSE;
    }

    return VFX_TRUE;
}

VfxBool VappMessageList::getMsgInfo(const VfxU32 index, srv_um_msg_info_struct *&msgInfo, srv_um_thread_info_struct *&threadInfo)
{
    VFX_ASSERT(NULL != m_msgDataProvider);
    if (NULL == m_list)
    {
        return VFX_FALSE;
    }

    VfxS32 result = -1;
    srv_um_msg_info_struct *msgInfoRef[1];

    msgInfoRef[0] = NULL;
    if (VAPP_MESSAGE_LIST_STYLE_NORMAL == m_style)
    {
        result = m_msgDataProvider->getMsgInfo(
                        (srv_um_msg_node_struct *)(m_list->list), 
                        m_list->msg_number, 
                        (VfxU16) index, 
                        1, 
                        msgInfoRef);
    }
    else
    {
        srv_um_thread_info_struct *threadInfoRef[1];

        threadInfoRef[0] = NULL;
        result = m_msgDataProvider->getThreadInfo(
                        (srv_um_thread_id_struct *)(m_list->list), 
                        m_list->msg_number, 
                        (VfxU16) index, 
                        1, 
                        threadInfoRef, 
                        msgInfoRef);

        threadInfo = threadInfoRef[0];
    }

    msgInfo = msgInfoRef[0];
    if (result < SRV_UM_RESULT_OK)
    {
        VFX_ASSERT(NULL != m_updateMsgInfoList);
        m_updateMsgInfoList[index] = VFX_TRUE;
        return VFX_FALSE;
    }

    return VFX_TRUE;
}

VfxS32 VappMessageList::getIndex(const VfxU32 msgId, const VfxU32 msgType) const
{
    if (NULL == m_list ||
        VAPP_MESSAGE_LIST_STYLE_THREAD == m_style)
    {
        return -1;
    }

    VfxU32 i;
    VfxS32 hit = -1;
    for (i = 0 ; i < m_list->msg_number ; i++)
    {
        if (msgId == ((srv_um_msg_node_struct*)m_list->list)[i].msg_id &&
            msgType == ((srv_um_msg_node_struct*)m_list->list)[i].msg_type)
        {
            hit = i;
            break;
        }
    }

    return hit;
}

VfxU32 VappMessageList::getMsgId(const VfxU32 index) const
{
    if (NULL == m_list)
    {
        return 0;
    }

    if (index > m_list->msg_number)
    {
        return 0;
    }

    return ((srv_um_msg_node_struct*)m_list->list)[index].msg_id;
}

srv_um_msg_enum VappMessageList::getMsgType(const VfxU32 index) const
{
    if (NULL == m_list)
    {
        return SRV_UM_MSG_NONE;
    }

    if (index > m_list->msg_number)
    {
        return SRV_UM_MSG_NONE;
    }

    return ((srv_um_msg_node_struct*)m_list->list)[index].msg_type;
}

VfxU32 VappMessageList::getThreadIdType(const VfxU32 index) const
{
    if (NULL == m_list)
    {
        return 0;
    }

    if (index > m_list->msg_number)
    {
        return 0;
    }

    return ((srv_um_thread_id_struct*) m_list->list)[index].type;
}

VfxU64 VappMessageList::getThreadIdValue(const VfxU32 index) const
{
    if (NULL == m_list)
    {
        return 0;
    }

    if (index > m_list->msg_number)
    {
        return 0;
    }

    return ((srv_um_thread_id_struct*) m_list->list)[index].value;
}

VfxBool VappMessageList::getMarkStatus(const VfxU32 index)
{
    if (VFX_TRUE == m_isMsActionActive)
    {
        return VFX_FALSE;
    }

    if (VFX_TRUE == generateMsList(VFX_FALSE))
    {
        if (VFX_TRUE == m_isResetList)
        {
            // reset list, need to update ms status
            updateMsList();
            m_isResetList = VFX_FALSE;
        }

        VfxU16 setIdx;
        VfxU16 reminding;

        setIdx = index / 32;
        reminding = index - (setIdx * 32);

        /* It has been marked */
        if ((m_msMarkStatus[setIdx] >> (32 - 1 - reminding)) & 1)
        {
            return VFX_TRUE;
        }
        else
        {
            return VFX_FALSE;
        }
    }

    return VFX_FALSE;
}

VfxU32 VappMessageList::getNumMarked() const
{
    return m_numMarked;
}

VfxBool VappMessageList::getIsAllMarked(VfxBool isMark, srv_um_msg_enum msgType, VappMessageListCopyStorageEnum storage) const
{
    // check ms list 
    VFX_ASSERT(!((NULL != m_msList && NULL == m_msMarkStatus) || (NULL == m_msList && NULL != m_msMarkStatus)));

    if (SRV_UM_MSG_ALL == msgType)
    {
        if (NULL == m_msList)
        {
            if (VFX_TRUE == isMark)
            {
                /* check if all marked */
                return VFX_FALSE;
            }
            else
            {
                /* check if all unmarked */
                return VFX_TRUE;
            }
        }

        if (VFX_TRUE == isMark)
        {
            if (m_numMarked == m_msList->msg_number)
            {
                /* all marked */
                return VFX_TRUE;
            }
            else
            {
                /* some unmarked */
                return VFX_FALSE;
            }
        }
        else
        {
            if (m_numMarked == 0)
            {
                /* all unmarked */
                return VFX_TRUE;
            }
            else
            {
                /* some marked */
                return VFX_FALSE;
            }
        }
    }
    else
    {
        VfxU32 numValidMsg = 0;
        numValidMsg = getNumValidMsMsg(msgType, storage);
        /* check status */
        if (0 == numValidMsg)
        {
            /* special case, always select all and action item(delete/copy) is disable */
            if (VFX_TRUE == isMark)
            {
                return VFX_FALSE;
            }
            else
            {
                return VFX_TRUE;
            }
        }
        else
        {
            if (VFX_TRUE == isMark)
            {
                if (m_numMarked == numValidMsg)
                {
                    /* all marked */
                    return VFX_TRUE;
                }
                else
                {
                    /* some unmarked */
                    return VFX_FALSE;
                }
            }
            else
            {
                if (0 < m_numMarked)
                {
                    /* some marked */
                    return VFX_FALSE;
                }
                else
                {
                    /* all unmarked */
                    return VFX_TRUE;
                }
            }
        }
    }
}

VfxU32 VappMessageList::getNumValidMsMsg(srv_um_msg_enum msgType,VappMessageListCopyStorageEnum storage) const
{
    // check ms list 
    VFX_ASSERT(!((NULL != m_msList && NULL == m_msMarkStatus) || (NULL == m_msList && NULL != m_msMarkStatus)));

    if (NULL == m_list)
    {
        return 0;
    }

    if (SRV_UM_MSG_ALL == msgType)
    {
        return m_list->msg_number;
    }

    VfxU32 numValidMsg = 0;
    if (VAPP_MESSAGE_LIST_COPY_STORAGE_NONE == storage ||
        VAPP_MESSAGE_LIST_COPY_STORAGE_ARCHIVE == storage)
    {
        /* traverse all message to see if how many valid message inside */
        VfxU32 i;
        for (i = 0 ; i < m_list->msg_number ; i++)
        {
            /* need to handle */
            if (getMsgType(i) & msgType)
            {
                numValidMsg++;
            }
        }
    }
    else
    {
        /* traverse all message to mark all or unmark all */
        VfxU32 i;
        for (i = 0 ; i < m_list->msg_number ; i++)
        {
            if (SRV_UM_MSG_SMS & msgType && SRV_UM_MSG_SMS == getMsgType(i))
            {
                if (VAPP_MESSAGE_LIST_COPY_STORAGE_SIM1 <= storage &&
                    VAPP_MESSAGE_LIST_COPY_STORAGE_SIM4 >= storage)
                {
                    numValidMsg++;
                }
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif
                else if (VAPP_MESSAGE_LIST_COPY_STORAGE_PHONE == storage && 
                        (SRV_SMS_STORAGE_TCARD == srv_sms_get_msg_storage_type(getMsgId(i)) ||
                         SRV_SMS_STORAGE_SIM == srv_sms_get_msg_storage_type(getMsgId(i))))
                {
                    numValidMsg++;
                }
                else if (VAPP_MESSAGE_LIST_COPY_STORAGE_MEMORY_CARD == storage && 
                        (SRV_SMS_STORAGE_ME == srv_sms_get_msg_storage_type(getMsgId(i)) ||
                         SRV_SMS_STORAGE_SIM == srv_sms_get_msg_storage_type(getMsgId(i))))
                {
                    numValidMsg++;
                }
            }
            else if (SRV_UM_MSG_MMS & msgType && SRV_UM_MSG_MMS == getMsgType(i))
            {
            #ifdef __MMI_MMS_IN_UM__
                if (SRV_UM_MSG_MMS == getMsgType(i))
                {
                    if (VAPP_MESSAGE_LIST_COPY_STORAGE_PHONE == storage && 
                        SRV_MMS_STORAGE_CARD1 == srv_mms_get_msg_storage(getMsgId(i)))
                    {
                        numValidMsg++;
                    }
                    else if (VAPP_MESSAGE_LIST_COPY_STORAGE_MEMORY_CARD == storage && 
                             SRV_MMS_STORAGE_PHONE == srv_mms_get_msg_storage(getMsgId(i)))
                    {
                        numValidMsg++;
                    }
                }
            #endif /* __MMI_MMS_IN_UM__ */
            }
        }
    }

    return numValidMsg;
}

VfxBool VappMessageList::getIsMsActionActive() const
{
    return m_isMsActionActive;
}

VfxBool VappMessageList::getMsActionDuriation(VfxS32 &finishNum, VfxS32 &totalNum) const
{
    // reset first
    finishNum = totalNum = 0;
    if (VFX_TRUE == m_isMsActionActive)
    {
        // check from service
        m_msgDataProvider->getProcessProgress(finishNum, totalNum);
        return VFX_TRUE;
    }

    return VFX_FALSE;
}

VfxBool VappMessageList::isMsgList()
{
    if (MMI_FALSE == srv_um_check_ready_type(m_boxId.msg_type))
    {
        return VFX_FALSE;
    }

    VfxBool listStatus = VFX_FALSE;

    if (NULL == m_list)
    {
        VfxS32 result = -1;

        if (VAPP_MESSAGE_LIST_STYLE_NORMAL == m_style)
        {
            result = srv_um_check_msg_list(m_boxId, &m_listFilter, VappMessageList::onMsgListStatusCb, (VfxS32)getObjHandle(), &m_list);
        }
        else
        {
        #ifdef __MMI_UM_CONVERSATION_BOX__
            result = srv_um_check_thread_list(m_boxId, &m_listFilter, VappMessageList::onMsgListStatusCb, (VfxS32)getObjHandle(), &m_list);
        #endif /* __MMI_UM_CONVERSATION_BOX__ */
        }

        if (result < SRV_UM_RESULT_OK)
        {
            listStatus = VFX_FALSE;
        }
        else
        {
            listStatus = VFX_TRUE;
            m_listId = result;
            m_isResetList = VFX_TRUE;
        }

    }
    else
    {
        listStatus = VFX_TRUE;
        if (NULL == m_updateMsgInfoList)
        {
            if (0 != m_list->msg_number)
            {
                VFX_ALLOC_MEM(m_updateMsgInfoList, sizeof(VfxBool)*m_list->msg_number, this);
                vfx_sys_mem_zero(m_updateMsgInfoList, sizeof(VfxBool)*m_list->msg_number);
            }
            m_updateMsgInfoListSize = m_list->msg_number;
        }
    }

    return listStatus;
}

VfxBool VappMessageList::checkMsgList()
{
    if (MMI_FALSE == srv_um_check_ready_type(m_boxId.msg_type))
    {
        return VFX_FALSE;
    }

    VfxBool listStatus = VFX_FALSE;

    if (NULL == m_list)
    {
        VfxS32 result = -1;

        if (VAPP_MESSAGE_LIST_STYLE_NORMAL == m_style)
        {
            result = m_msgDataProvider->getMsgList(
                        m_boxId, 
                        m_listFilter, 
                        VappMessageList::onMsgListStatusCb, 
                        (VfxS32)getObjHandle(), 
                        m_list);
        }
        else
        {
            result = m_msgDataProvider->getThreadList(
                        m_boxId, 
                        m_listFilter, 
                        VappMessageList::onMsgListStatusCb, 
                        (VfxS32)getObjHandle(), 
                        m_list);
        }

        if (result < SRV_UM_RESULT_OK)
        {
            listStatus = VFX_FALSE;
        }
        else
        {
            listStatus = VFX_TRUE;
            m_listId = result;
            m_isResetList = VFX_TRUE;
        }

    }
    else
    {
        listStatus = VFX_TRUE;
        if (NULL == m_updateMsgInfoList)
        {
            if (0 != m_list->msg_number)
            {
                VFX_ALLOC_MEM(m_updateMsgInfoList, sizeof(VfxBool)*m_list->msg_number, this);
                vfx_sys_mem_zero(m_updateMsgInfoList, sizeof(VfxBool)*m_list->msg_number);
            }
            m_updateMsgInfoListSize = m_list->msg_number;
        }
    }

    return listStatus;
}

void VappMessageList::freeMsStatus()
{
    if (NULL != m_msList)
    {
        VFX_FREE_MEM(m_msList->list);
    }
    VFX_FREE_MEM(m_msList);
    VFX_FREE_MEM(m_msMarkStatus);
    m_numMarked = 0;
}

VfxBool VappMessageList::deleteMarked()
{
    if (VFX_TRUE == m_isMsActionActive)
    {
        return VFX_FALSE;
    }

    // check ms list 
    VFX_ASSERT(!((NULL != m_msList && NULL == m_msMarkStatus) || (NULL == m_msList && NULL != m_msMarkStatus)));

    if (NULL == m_msList || 
        0 == m_msList->msg_number || 
        0 == m_numMarked)
    {
        m_signalOperationResult.postEmit(this, 0, 0, SRV_UM_RESULT_UNKNOWN_ERROR);
        freeMsStatus();
        return VFX_FALSE;
    }

    /* release the current list because of mark several delete */
    resetList(VFX_TRUE);
    VfxS32 result = 0;
    if (VAPP_MESSAGE_LIST_STYLE_NORMAL == m_style)
    {
        result = m_msgDataProvider->markSeveralOp(
                                        m_boxId, 
                                        (srv_um_msg_node_struct *)m_msList->list, 
                                        m_msList->msg_number, 
                                        m_msMarkStatus, 
                                        SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE);
    }
    else if (VAPP_MESSAGE_LIST_STYLE_THREAD == m_style)
    {
        result = m_msgDataProvider->markSeveralThreadOp(
                                        m_boxId, 
                                        (srv_um_thread_id_struct *)m_msList->list, 
                                        m_msList->msg_number, 
                                        m_msMarkStatus, 
                                        SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE);
    }
    else
    {
        VFX_ASSERT(0);
    }

    if (SRV_UM_RESULT_PROCESS_BUSY == result)
    {
        m_isMsActionActive = VFX_TRUE;
    }

    if (SRV_UM_RESULT_TOO_MANY_THREAD == result)
    {
        /* only one process for this class */
        m_signalOperationResult.postEmit(this, 0, m_msList->msg_number, SRV_UM_RESULT_TOO_MANY_THREAD);
    }
    return (SRV_UM_RESULT_PROCESS_BUSY == result);
}

VfxBool VappMessageList::copyMarked(VappMessageListCopyStorageEnum storage)
{
    if (VFX_TRUE == m_isMsActionActive)
    {
        return VFX_FALSE;
    }

    // check ms list 
    VFX_ASSERT(!((NULL != m_msList && NULL == m_msMarkStatus) || (NULL == m_msList && NULL != m_msMarkStatus)));

    if (NULL == m_msList ||
        0 == m_msList->msg_number || 
        0 == m_numMarked)
    {
        m_signalOperationResult.postEmit(this, 0, 0, SRV_UM_RESULT_UNKNOWN_ERROR);
        freeMsStatus();
        return VFX_FALSE;
    }

    VfxS32 result = 0;
    srv_um_mark_several_op_action_enum actionType = SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE;
    switch (storage)
    {
        case VAPP_MESSAGE_LIST_COPY_STORAGE_ARCHIVE:
            actionType = SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_ARCHIVE;
            break;

        case VAPP_MESSAGE_LIST_COPY_STORAGE_SIM1:
            actionType = SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM1;
            break;

    #if (MMI_MAX_SIM_NUM >= 2)
        case VAPP_MESSAGE_LIST_COPY_STORAGE_SIM2:
            actionType = SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM2;
            break;
    #endif /* MMI_MAX_SIM_NUM >= 2 */

    #if (MMI_MAX_SIM_NUM >= 3)
        case VAPP_MESSAGE_LIST_COPY_STORAGE_SIM3:
            actionType = SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM3;
            break;
    #endif /* MMI_MAX_SIM_NUM >= 3 */

    #if (MMI_MAX_SIM_NUM >= 4)
        case VAPP_MESSAGE_LIST_COPY_STORAGE_SIM4:
            actionType = SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM4;
            break;
    #endif /* MMI_MAX_SIM_NUM >= 4 */

        case VAPP_MESSAGE_LIST_COPY_STORAGE_PHONE:
            actionType = SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_PHONE;
            break;

        case VAPP_MESSAGE_LIST_COPY_STORAGE_MEMORY_CARD:
            actionType = SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_MEMORY_CARD;
            break;

        default:
            actionType = SRV_UM_MARK_SEVERAL_OP_ACTION_NONE;
            VFX_ASSERT(0);
            break;
    }

    if (VAPP_MESSAGE_LIST_STYLE_NORMAL == m_style)
    {
        result = m_msgDataProvider->markSeveralOp(
                                        m_boxId, 
                                        (srv_um_msg_node_struct *)m_msList->list, 
                                        m_msList->msg_number, 
                                        m_msMarkStatus, 
                                        actionType);
    }
    else if (VAPP_MESSAGE_LIST_STYLE_THREAD == m_style)
    {
        result = m_msgDataProvider->markSeveralThreadOp(
                                        m_boxId, 
                                        (srv_um_thread_id_struct *)m_msList->list, 
                                        m_msList->msg_number, 
                                        m_msMarkStatus, 
                                        actionType);
    }
    else
    {
        VFX_ASSERT(0);
    }

    if (SRV_UM_RESULT_PROCESS_BUSY == result)
    {
        m_isMsActionActive = VFX_TRUE;
    }

    if (SRV_UM_RESULT_TOO_MANY_THREAD == result)
    {
        /* only one process for this class */
        m_signalOperationResult.postEmit(this, 0, m_msList->msg_number, SRV_UM_RESULT_TOO_MANY_THREAD);
    }
    else
    {
        resetList(VFX_TRUE);
    }
    return (SRV_UM_RESULT_PROCESS_BUSY == result);
}

void VappMessageList::cancelMsAction()
{
    if (VFX_FALSE == m_isMsActionActive)
    {
        return;
    }

    m_msgDataProvider->cancelProcess();
}

void VappMessageList::onInit()
{
    VfxObject::onInit();

    /* create the data provide to get data from UM service */
    VFX_OBJ_CREATE(m_msgDataProvider, VappMsgDataProvider, this);
    m_msgDataProvider->m_signalGetMsgNumFinished.connect(this, &VappMessageList::onGetMsgNumCb);
    m_msgDataProvider->m_signalGetMsgListFinished.connect(this, &VappMessageList::onGetMsgListCb);
    m_msgDataProvider->m_signalGetMsgInfoFinished.connect(this, &VappMessageList::onGetMsgInfoCb);
#ifdef __MMI_UM_CONVERSATION_BOX__
    m_msgDataProvider->m_signalGetThreadListFinished.connect(this, &VappMessageList::onGetThreadListCb);
    m_msgDataProvider->m_signalGetThreadInfoFinished.connect(this, &VappMessageList::onGetThreadInfoCb);
#endif /* __MMI_UM_CONVERSATION_BOX__ */
    m_msgDataProvider->m_signalMarkSeveralOpFinished.connect(this, &VappMessageList::onMarkSeveralOpCb);
    m_msgDataProvider->m_signalMarkSeveralThreadOpFinished.connect(this, &VappMessageList::onMarkSeveralThreadOpCb);

    /* register the event from UM service */
    mmi_frm_cb_reg_event(EVT_ID_SRV_UM_NOTIFY_READY, &VappMessageList::onMsgSrvEvtCb, getObjHandle());
    mmi_frm_cb_reg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH, &VappMessageList::onMsgSrvEvtCb, getObjHandle());
}

void VappMessageList::onDeinit()
{
    resetList(VFX_FALSE);

    if (m_msgDataProvider->isProcessing())
    {
        m_msgDataProvider->cancelProcess();
    }

    mmi_frm_cb_dereg_event(EVT_ID_SRV_UM_NOTIFY_READY, &VappMessageList::onMsgSrvEvtCb, getObjHandle());
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UM_NOTIFY_REFRESH, &VappMessageList::onMsgSrvEvtCb, getObjHandle());

    freeMsStatus();
    VFX_FREE_MEM(m_updateMsgInfoList);

    VfxObject::onDeinit();
}

void VappMessageList::onMsgListStatusCb(VfxS32 event, VfxS32 listId, VfxS32 userData)
{
    VappMessageList *self = (VappMessageList *)VfxObject::handleToObject((VfxObjHandle)userData);

    if (self)
    {
        if (self->isKindOf(VFX_OBJ_CLASS_INFO(VappMessageList)))
        {
            if (self->m_listId == listId)
            {
                switch (event)
                {
                    case SRV_UM_NOTIFY_LIST_RELEASED_IND:
                    {
                        /* Reset the list */
                        if (NULL != self->m_list)
                        {
                            self->m_listId = 0;
                            self->m_list = NULL;
                        }
                        break;
                    }
                    default:
                    {
                        break;
                    }
                }
            }
        }
    }
}

mmi_ret VappMessageList::onMsgSrvEvtCb(mmi_event_struct * param)
{
    VappMessageList *self = (VappMessageList *)VfxObject::handleToObject((VfxObjHandle)param->user_data);

    if (self)
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "%s", self->getClassInfo()->getClassName());
        MMI_TRACE(TRACE_GROUP_6, TRC_MMI_VAPP_MSG_UM_SRV_EVT, param->evt_id, self);
        if (self->isKindOf(VFX_OBJ_CLASS_INFO(VappMessageList)))
        {
            switch (param->evt_id)
            {
                case EVT_ID_SRV_UM_NOTIFY_READY:
                    /* release the list */
                    self->resetList(VFX_TRUE);
                    self->m_signalListUpdated.postEmit(self);
                    break;

                case EVT_ID_SRV_UM_NOTIFY_REFRESH:
                    if (VFX_TRUE != self->m_isMsActionActive)
                    {
                        srv_um_notify_refresh_evt_struct *refreshEvt;
                        refreshEvt = (srv_um_notify_refresh_evt_struct *)param;
                        /* cancel previous */
                        self->m_msgDataProvider->cancelProcess();
                        /* has list */
                        if (VFX_TRUE == self->isMsgList() &&
                            VAPP_MESSAGE_LIST_STYLE_THREAD != self->m_style)
                        {
                            if (SRV_UM_REFRESH_MSG_STATUS_CHANGED == refreshEvt->refresh_type || 
                                 SRV_UM_REFRESH_MSG_CONTENT_CHANGED == refreshEvt->refresh_type)
                            {
                                /* find the specified index */
                                VfxS32 index = 0;
                                index = self->getIndex(refreshEvt->msg_id, refreshEvt->msg_type);
                                if (-1 != index)
                                {
                                    /* find it */
                                    self->m_signalSingleMsgUpdated.postEmit(self, index);
                                }
                                /* not find, do nothing */
                            }
                            else
                            {
                                /* same box type */
                                if (self->m_boxId.msg_box_type & refreshEvt->msg_box_type)
                                {
                                    self->m_signalListUpdated.postEmit(self);
                                    /* reset msgInfoList */
                                    VFX_FREE_MEM(self->m_updateMsgInfoList);
                                    self->m_updateMsgInfoListSize = 0;
                                }
                            }
                        }
                        else
                        {
                            /* same box type */
                            if (self->m_boxId.msg_box_type & refreshEvt->msg_box_type)
                            {
                                self->m_signalListUpdated.postEmit(self);
                                /* reset msgInfoList */
                                VFX_FREE_MEM(self->m_updateMsgInfoList);
                                self->m_updateMsgInfoListSize = 0;
                            }
                        }
                    }
                    break;

                default:
                    break;
            }
        }
    }

    return MMI_RET_OK;
}

void VappMessageList::onGetMsgNumCb(srv_um_get_msg_num_result result)
{
    m_signalListUpdated.postEmit(this);
}

void VappMessageList::onGetMsgListCb(srv_um_get_msg_list_result result)
{
    /* create a list to record the msg info status */
    if (VFX_TRUE == isMsgList())
    {
        VfxU32 size = 0;
        size = getCount();
        if (0 != size)
        {
            VFX_FREE_MEM(m_updateMsgInfoList);
            VFX_ALLOC_MEM(m_updateMsgInfoList, sizeof(VfxBool)*size, this);
            vfx_sys_mem_zero(m_updateMsgInfoList, sizeof(VfxBool)*size);
        }
        updateMsList();
        m_isResetList = VFX_FALSE;
        m_updateMsgInfoListSize = size;
    }
    m_signalListUpdated.postEmit(this);
}

void VappMessageList::onGetMsgInfoCb(srv_um_get_msg_info_result result)
{
    checkUpdateMsgInfoList();
}

void VappMessageList::onGetThreadListCb(srv_um_get_thread_list_result result)
{
    /* create a list to record the msg info status */
    if (VFX_TRUE == isMsgList())
    {
        VfxU32 size = 0;
        size = getCount();
        if (0 != size)
        {
            VFX_FREE_MEM(m_updateMsgInfoList);
            VFX_ALLOC_MEM(m_updateMsgInfoList, sizeof(VfxBool)*size, this);
            vfx_sys_mem_zero(m_updateMsgInfoList, sizeof(VfxBool)*size);
        }
        updateMsList();
        m_isResetList = VFX_FALSE;
        m_updateMsgInfoListSize = size;
    }
    m_signalListUpdated.postEmit(this);
}

void VappMessageList::onGetThreadInfoCb(srv_um_get_thread_info_result result)
{
    checkUpdateMsgInfoList();
}

void VappMessageList::onMarkSeveralOpCb(srv_um_mark_several_op_result result)
{
    m_signalOperationResult.postEmit(this, result.no_of_success, result.no_of_fail, result.error);
    m_isMsActionActive = VFX_FALSE;
    freeMsStatus();
}

void VappMessageList::onMarkSeveralThreadOpCb(srv_um_mark_several_thread_op_result result)
{
    m_signalOperationResult.postEmit(this, result.no_of_success, result.no_of_fail, result.error);
    m_isMsActionActive = VFX_FALSE;
    freeMsStatus();
}

void VappMessageList::resetList(VfxBool out_of_date)
{
    MMI_BOOL del = MMI_TRUE;
    if (VFX_TRUE == out_of_date)
    {
        del = MMI_TRUE;
    }
    else
    {
        del = MMI_FALSE;
    }

    if (NULL != m_list)
    {
        srv_um_release_list(m_listId, del);
        m_listId = 0;
        m_list = NULL;
    }
}

VfxBool VappMessageList::generateMsList(VfxBool isReset)
{
    // check ms list 
    VFX_ASSERT(!((NULL != m_msList && NULL == m_msMarkStatus) || (NULL == m_msList && NULL != m_msMarkStatus)));

    if (VFX_TRUE == m_isMsActionActive)
    {
        // during mark several operation, could not update the memory
        return VFX_FALSE;
    }

    if (NULL == m_list ||
        0 == m_list->msg_number)
    {
        return VFX_FALSE;
    }

    if (VFX_TRUE == isReset)
    {
        freeMsStatus();
    }

    if (NULL == m_msList)
    {
        // allocate memory
        VFX_ALLOC_MEM(m_msList, sizeof(srv_um_list_cntx_struct), this);
        vfx_sys_mem_copy(m_msList, m_list, sizeof(srv_um_list_cntx_struct));

        m_msList->list = NULL;
        if (VAPP_MESSAGE_LIST_STYLE_NORMAL == m_style)
        {
            VFX_ALLOC_MEM(m_msList->list, sizeof(srv_um_msg_node_struct) * m_list->msg_number, this);
            vfx_sys_mem_copy(m_msList->list, m_list->list, sizeof(srv_um_msg_node_struct) * m_list->msg_number);
        }
        else if (VAPP_MESSAGE_LIST_STYLE_THREAD == m_style)
        {
            VFX_ALLOC_MEM(m_msList->list, sizeof(srv_um_thread_id_struct) * m_list->msg_number, this);
            vfx_sys_mem_copy(m_msList->list, m_list->list, sizeof(srv_um_thread_id_struct) * m_list->msg_number);
        }
        else
        {
            VFX_ASSERT(0);
        }

        VFX_ALLOC_MEM(m_msMarkStatus, sizeof(VfxU32) * (m_list->msg_number/32 + 1), this);
        vfx_sys_mem_zero(m_msMarkStatus, sizeof(VfxU32) * (m_list->msg_number/32 + 1));
    }

    return VFX_TRUE;
}

void VappMessageList::updateMsList()
{
    // check ms list 
    VFX_ASSERT(!((NULL != m_msList && NULL == m_msMarkStatus) || (NULL == m_msList && NULL != m_msMarkStatus)));

    if (VFX_TRUE == m_isMsActionActive)
    {
        // during mark several operation, could not update the memory
        return;
    }

    if (NULL == m_list || 
        0 == m_list->msg_number ||
        NULL == m_msList)
    {
        /* free the mark status because of empty list */
        freeMsStatus();
        return;
    }

    VfxU32 *newMarkStatus;
    VFX_ALLOC_MEM(newMarkStatus, sizeof(VfxU32) * (m_list->msg_number/32 + 1), this);
    vfx_sys_mem_zero(newMarkStatus, sizeof(VfxU32) * (m_list->msg_number/32 + 1));

    /* compare with mark several list */
    VfxU32 i, j;
    VfxU32 numMarked = 0;
    // ms list
    for (i = 0 ; i < m_msList->msg_number ; i++)
    {
        VfxU32 setIdx;
        VfxU32 reminding;

        setIdx = i / 32;
        reminding = i - (setIdx * 32);
        if (!((m_msMarkStatus[setIdx] >> (32 - 1 - reminding)) & 1))
        {
            continue;
        }
        // new list
        for (j = 0 ; j < m_list->msg_number ; j++)
        {
            if (VAPP_MESSAGE_LIST_STYLE_NORMAL == m_style)
            {
                /* hit */
                if (((srv_um_msg_node_struct*)m_msList->list)[i].msg_id == ((srv_um_msg_node_struct*)m_list->list)[j].msg_id &&
                    ((srv_um_msg_node_struct*)m_msList->list)[i].msg_type == ((srv_um_msg_node_struct*)m_list->list)[j].msg_type)
                {
                    setIdx = j / 32;
                    reminding = j - (setIdx * 32);
                    newMarkStatus[setIdx] |= (1 << (32 - 1 - reminding));
                    numMarked ++;
                    break;
                }
            }
            else if (VAPP_MESSAGE_LIST_STYLE_THREAD == m_style)
            {
                /* hit */
                if (((srv_um_thread_id_struct*)m_msList->list)[i].type == ((srv_um_thread_id_struct*)m_list->list)[j].type &&
                    ((srv_um_thread_id_struct*)m_msList->list)[i].value == ((srv_um_thread_id_struct*)m_list->list)[j].value &&
                    ((srv_um_thread_id_struct*)m_msList->list)[i].sim_id == ((srv_um_thread_id_struct*)m_list->list)[j].sim_id)
                {
                    setIdx = j / 32;
                    reminding = j - (setIdx * 32);
                    newMarkStatus[setIdx] |= (1 << (32 - 1 - reminding));
                    numMarked ++;
                    break;
                }
            }
            else
            {
                VFX_ASSERT(0);
            }
        }
    }

    generateMsList(VFX_TRUE);

    // copy the latest mark status
    vfx_sys_mem_copy(m_msMarkStatus, newMarkStatus, sizeof(VfxU32) * (m_list->msg_number/32 + 1));
    m_numMarked = numMarked;
    VFX_FREE_MEM(newMarkStatus);
}

void VappMessageList::checkUpdateMsgInfoList()
{
    if (VFX_FALSE == checkMsgList() ||
        NULL == m_updateMsgInfoList)
    {
        return;
    }

    VfxU32 i;

    for (i = 0 ; i < m_updateMsgInfoListSize ; i++)
    {
        if (VFX_TRUE == m_updateMsgInfoList[i])
        {
            /* hit */
            srv_um_msg_info_struct *msgInfo = NULL;
            srv_um_thread_info_struct *threadInfo = NULL;
            /* try to get the next one */
            if (VFX_FALSE == getMsgInfo(i, msgInfo, threadInfo))
            {
                break;
            }
            else
            {
                m_updateMsgInfoList[i] = VFX_FALSE;
                m_signalSingleMsgUpdated.postEmit(this, i);
            }
        }
    }
}

/****************************************************************************/
/* NCenter 2.0
*****************************************************************************/
static VfxU8 mem_full_setting = 0;
static MMI_BOOL is_first_ready = MMI_TRUE;
static MMI_BOOL mem_full_phone_prev = MMI_FALSE;

extern "C" mmi_ret vapp_msg_event_ncenter_hdlr(mmi_event_struct *evt)
{
    mmi_ret ret = MMI_RET_OK;
    MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "vapp_msg_event_ncenter_hdlr evt->evt_id %d", evt->evt_id);
    switch(evt->evt_id)
    {
        case EVT_ID_SRV_UM_NOTIFY_READY:
            ret = vapp_msg_ready_event_hdlr(evt);
            break;
            
        case EVT_ID_SRV_UM_NOTIFY_REFRESH:
            ret = vapp_msg_refresh_event_hdlr(evt);
            break;

        case EVT_ID_SRV_SMS_UPDATE_UNSENT_MSG_STATUS:
            ret = vapp_msg_sms_send_event_hdlr(evt);
            break;
            
    #ifdef __MMI_MMS_IN_UM__
        case EVT_ID_SRV_MMS_UPDATE_STATUS:
            ret = vapp_msg_mms_send_event_hdlr(evt);
            break;
    #endif /*__MMI_MMS_IN_UM__*/

        case EVT_ID_SRV_SMS_MEM_FULL:
		case EVT_ID_SRV_SMS_MEM_AVAILABLE:
            ret = vapp_msg_sms_mem_full_event_hdlr(evt);
            break;
            
    #ifdef __MMI_MMS_IN_UM__
        case EVT_ID_SRV_MMS_MEM_FULL:
            ret = vapp_msg_mms_mem_full_event_hdlr(evt);
            break;
    #endif /*__MMI_MMS_IN_UM__*/
    
    #ifdef __MMI_PROV_IN_UM__
        case EVT_ID_SRV_PROVBOX_EVT_IND:
            ret = vapp_msg_prov_mem_full_event_hdlr(evt);
            break;
    #endif /*__MMI_PROV_IN_UM__*/

        default:
            ret = MMI_RET_DONT_CARE;
            break;
    }
    return ret;
}

extern "C" mmi_ret vapp_msg_ready_event_hdlr(mmi_event_struct *evt)
{
    if (srv_um_check_ready())
    {        
        if (is_first_ready)
        {
            is_first_ready = MMI_FALSE;
            vapp_msg_write_nvram_mem_full_setting(mem_full_setting, VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
            mem_full_setting = 0;
        }
        srv_um_get_msg_num_result data;
        S32 result = srv_um_check_msg_num(SRV_UM_SIM_ALL, SRV_UM_MSG_ALL, &data);  

        if( 0 < data.inbox_unread_msg_number && VFX_TRUE == vapp_msg_read_nvram_setting(VAPP_MSG_NCENTER_UNREAD_CELL))
        { 
            vapp_msg_show_ncenter_cell(VAPP_MSG_NCENTER_UNREAD_CELL, data.inbox_unread_msg_number);  

            mmi_frm_nmgr_alert_struct alert_info;
            memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct)); 
            vapp_msg_nss_set_alert_info_icon(ICON_UNREAD, alert_info);
            mmi_frm_nmgr_alert(&alert_info);
        }

        VfxU32 count = vapp_msg_get_send_fail_count();
        if ((count > 0) && (VFX_TRUE == vapp_msg_read_nvram_setting(VAPP_MSG_NCENTER_UNSEND_CELL)))
        {
            vapp_msg_show_ncenter_cell(VAPP_MSG_NCENTER_UNSEND_CELL, count);

            mmi_frm_nmgr_alert_struct alert_info;
            memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct)); 
            vapp_msg_nss_set_alert_info_icon(ICON_UNSEND, alert_info);
            mmi_frm_nmgr_alert(&alert_info);
        }
		
        for(VfxU32 cell = VAPP_MSG_NCENTER_FULL_SMS_SIM1_CELL; cell < VAPP_MSG_NCENTER_MESSAGE_CELL_END; cell++)
        {
            VfxU32 previousSetting = 0;
			
            previousSetting = vapp_msg_read_nvram_mem_full_setting(VAPP_MSG_FULL_NCENTER_PREVIOUS_EVT);
            /* get the specified flag setting */
            previousSetting = (VfxU32)(previousSetting & vapp_msg_full_ncenter_msg_cell_to_type(VappMsgNCenterCellMenu(cell)));

            //if previous is false, the full event is available
            if (0 == previousSetting)
            {
                VfxU32 displaySetting = 0;
                displaySetting = vapp_msg_read_nvram_mem_full_setting(VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
                displaySetting = (VfxU32)(displaySetting & vapp_msg_full_ncenter_msg_cell_to_type(VappMsgNCenterCellMenu(cell)));
        	if (displaySetting != 0)
        	{
                    vapp_msg_show_ncenter_cell(VappMsgNCenterCellMenu(cell));
        	}
            }
        }  
    }
    else
    {            
        is_first_ready = MMI_TRUE;
    }
    return MMI_RET_OK;
}

mmi_ret vapp_msg_refresh_event_hdlr(mmi_event_struct *evt)
{
    srv_um_notify_refresh_evt_struct *refreshEvt = (srv_um_notify_refresh_evt_struct *)evt;
    MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "vapp_msg_refresh_event_hdlr refresh_type = %d, refresg_msg_box = %d", refreshEvt->refresh_type, refreshEvt->refresh_type);
    //unread message
    if (SRV_UM_MSG_BOX_INBOX  == (SRV_UM_MSG_BOX_INBOX & refreshEvt->msg_box_type))
    {
        return vapp_msg_unread_event_hdlr(evt);
    }        

    //unsend message
    if (SRV_UM_MSG_BOX_UNSENT == (SRV_UM_MSG_BOX_UNSENT & refreshEvt->msg_box_type) &&
        MMI_TRUE == srv_um_check_ready() &&
		(SRV_UM_REFRESH_NEW_INCOMING_MSG != refreshEvt->refresh_type && 
        SRV_UM_REFRESH_MSG_CONTENT_CHANGED != refreshEvt->refresh_type))   
    {            
        return vapp_msg_unsend_event_hdlr(evt);
    }

    return MMI_RET_OK;
}

/****************************************************************************/
/* unread cell
*****************************************************************************/
//when msg app launch, close the unread cell
extern "C" mmi_ret vapp_msg_enter_hdlr(mmi_event_struct *evt)
{
    if (EVT_ID_VAPP_MSG_ENTRY == evt->evt_id)
    {
        vapp_msg_close_ncenter_cell(VAPP_MSG_NCENTER_UNREAD_CELL);
        vapp_msg_write_nvram_setting(VAPP_MSG_NCENTER_UNREAD_CELL, VFX_FALSE);
    }
    return MMI_RET_OK;
}

extern "C" void vapp_msg_show_ncenter_cell(VappMsgNCenterCellMenu type, VfxU32 data)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "vapp_msg_show_ncenter_cell type:%d", type);
    VsrvNGroupSingleTitle *group = NULL;
    VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (VAPP_MSG));
    group->setTitle(VFX_WSTR_RES(STR_ID_VAPP_MSG)); 
    
    VsrvNotificationEvent *noti;
    VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent, ((VsrvNGroup*) group, type));   
    VfxWString tmp;
    VfxU32 param = type; 
    VfxU32 setting = 0;
    vapp_msg_ncenter_info_struct msg_info;
    vfx_sys_mem_zero(&msg_info, sizeof(vapp_msg_ncenter_info_struct));    
        
    switch(type)
    {
        case VAPP_MSG_NCENTER_UNREAD_CELL:
            {     
                noti->setIcon(VfxImageSrc(IMG_ID_VAPP_MSG_NCENTER_UNREAD));
                noti->setMainText(VFX_WSTR_RES(STR_ID_VAPP_MSG_NCENTER_UNREAD_MSG));
                tmp = VfxWString().format("%d ", data);
                if (1 == data)
                {
                    tmp += VFX_WSTR_RES(STR_ID_VAPP_MSG_UNREAD_MSG);
                }
                else
                {
                    tmp += VFX_WSTR_RES(STR_ID_VAPP_MSG_UNREAD_MSGS);
                }
                noti->setSubText(tmp);
                noti->setAutoClose(VFX_FALSE);
                noti->setAutoLaunch(VFX_TRUE);                
                noti->setIntentCallback(vapp_msg_unread_intent_callback, &param, sizeof(VappMsgNCenterCellMenu));
            }
            break;    

        case VAPP_MSG_NCENTER_UNSEND_CELL:
            {   
                noti->setIcon(VfxImageSrc(IMG_ID_VAPP_MSG_NCENTER_UNSENT));
                noti->setMainText(VFX_WSTR_RES(STR_ID_VAPP_MSG_NCENTER_UNSENT_MSG));
                tmp = VfxWString().format("%d ", data);
                if (1 == data)
                {
                    tmp += VFX_WSTR_RES(STR_ID_VAPP_MSG_MSG);
                }
                else
                {
                    tmp += VFX_WSTR_RES(STR_ID_VAPP_MSG_MSGS);
                }
                noti->setSubText(tmp);
                noti->setAutoClose(VFX_FALSE);
                noti->setAutoLaunch(VFX_TRUE);
                noti->setIntentCallback(vapp_msg_unsend_intent_callback, &param, sizeof(VappMsgNCenterCellMenu));

                if (0 == vapp_msg_get_sending_count())
                {                    
                    vapp_msg_nss_cancel_alert(ICON_SENDING);
                }
                else
                {        	
                    mmi_frm_nmgr_alert_struct alert_info;
                    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct)); 
                    vapp_msg_nss_set_alert_info_icon(ICON_SENDING, alert_info);
                    mmi_frm_nmgr_alert(&alert_info);
                }
            }
            break;       
        
        case VAPP_MSG_NCENTER_FULL_SMS_SIM1_CELL:
            
	#if (MMI_MAX_SIM_NUM >= 2)
        case VAPP_MSG_NCENTER_FULL_SMS_SIM2_CELL:
	#endif /*MMI_MAX_SIM_NUM >= 2*/
    
	#if (MMI_MAX_SIM_NUM >= 3)
        case VAPP_MSG_NCENTER_FULL_SMS_SIM3_CELL:
	#endif /*MMI_MAX_SIM_NUM >= 3*/
                
	#if (MMI_MAX_SIM_NUM >= 4)
        case VAPP_MSG_NCENTER_FULL_SMS_SIM4_CELL:
	#endif /*MMI_MAX_SIM_NUM >= 4*/  
            
        case VAPP_MSG_NCENTER_FULL_SMS_PHONE_CELL:

    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
        case VAPP_MSG_NCENTER_FULL_SMS_CARD_CELL:
    #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */
            
	#ifdef __MMI_MMS_IN_UM__
        case VAPP_MSG_NCENTER_FULL_MMS_PHONE_CELL:
            
        case VAPP_MSG_NCENTER_FULL_MMS_CARD_CELL:
	#endif /*__MMI_MMS_IN_UM__*/

	#ifdef __MMI_PROV_IN_UM__
        case VAPP_MSG_NCENTER_FULL_PRO_CELL:
	#endif /*__MMI_PROV_IN_UM__*/
            {   
                noti->setIcon(VfxImageSrc(IMG_ID_VAPP_MSG_NCENTER_MEMORY_FULL));
                noti->setMainText(VFX_WSTR_RES(vapp_msg_tsfr_type_to_strId(vapp_msg_full_ncenter_msg_cell_to_type(type), VAPP_MSG_FULL_NCENTER_MAIN_TEXT)));
                tmp = VFX_WSTR_RES(vapp_msg_tsfr_type_to_strId(vapp_msg_full_ncenter_msg_cell_to_type(type), VAPP_MSG_FULL_NCENTER_SUB_TEXT));
                tmp += VfxWString().format(" %d", vapp_msg_query_memory_max(vapp_msg_full_ncenter_msg_cell_to_type(type)));
                noti->setSubText(tmp);
                noti->setAutoClose(VFX_FALSE);
                noti->setAutoLaunch(VFX_TRUE);
                msg_info.type = type;
                noti->setIntentCallback(vapp_msg_mem_full_intent_callback, &msg_info, sizeof(VappMsgNCenterCellMenu));

                setting = vapp_msg_read_nvram_mem_full_setting(VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
                if (0 != setting)
                {
                    /* show status icon */
                    mmi_frm_nmgr_alert_struct alert_info;
                    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct)); 
                    vapp_msg_nss_set_alert_info_icon(ICON_MEMFULL, alert_info);
                    mmi_frm_nmgr_alert(&alert_info);
                }
            }
            break;
        
        default:
            break;
    }
    noti->setCurrentTime();
    noti->notify(); 
}

extern "C" void vapp_msg_check_show_mem_full_cell(VappMsgNCenterCellMenu cell)
{
	MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "vapp_msg_check_show_mem_full_cell cell:%d", cell);
    VfxU32 previousSetting = 0;    
    previousSetting = vapp_msg_read_nvram_mem_full_setting(VAPP_MSG_FULL_NCENTER_PREVIOUS_EVT);
    /* get the specified flag setting */
    previousSetting = (VfxU32)(previousSetting & vapp_msg_full_ncenter_msg_cell_to_type(cell));
    MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "vapp_msg_check_show_mem_full_cell previousSetting:%d", previousSetting);

    //if previous is false, the full event is available
    if (0 == previousSetting)
    {
        if (vapp_msg_update_mem_full_previous_setting(vapp_msg_full_ncenter_msg_cell_to_type(cell)))
        {
            vapp_msg_write_nvram_mem_full_setting_single(vapp_msg_full_ncenter_msg_cell_to_type(cell), VFX_TRUE, VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
        }

        VfxU32 displaySetting = 0;
        displaySetting = vapp_msg_read_nvram_mem_full_setting(VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
        displaySetting = (VfxU32)(displaySetting & vapp_msg_full_ncenter_msg_cell_to_type(cell));
        if (displaySetting)
        {
            vapp_msg_show_ncenter_cell(cell);
        }
    }
}

extern "C" void vapp_msg_show_ncenter_unread_nmgr_text(mmi_event_struct *evt)
{
    srv_um_notify_refresh_evt_struct *refresh = (srv_um_notify_refresh_evt_struct *)evt;
    if (refresh != NULL)
    {
        if ((SRV_UM_REFRESH_NEW_INCOMING_MSG == refresh->refresh_type))
        {
            VfxWString prefix;
            prefix.loadFromRes(STR_ID_VAPP_MSG_NMGR_NEW_MESSAGE_PREFIX);
            prefix += VfxWString().format(" ");
            VfxWChar tmpName[(MMI_PHB_NAME_LENGTH + SRV_UM_MAX_ADDR_LEN) * ENCODING_LENGTH];
            memset(tmpName, 0, (MMI_PHB_NAME_LENGTH + SRV_UM_MAX_ADDR_LEN) * ENCODING_LENGTH * sizeof(VfxWChar));
            
            MMI_BOOL find = srv_phb_get_name_by_number(refresh->address, tmpName, 
    			(MMI_PHB_NAME_LENGTH > SRV_UM_MAX_ADDR_LEN) ? MMI_PHB_NAME_LENGTH : SRV_UM_MAX_ADDR_LEN);
            if (find)
            {
                if (VFX_WSTR_EMPTY == VFX_WSTR_MEM(tmpName))
                {
                    /* set as number */
                    prefix += VFX_WSTR_MEM(refresh->address);
                }
                else
                {
                    prefix += VFX_WSTR_MEM(tmpName);
                }
            }
            else
            {
                prefix += VFX_WSTR_MEM(refresh->address);
            }

            mmi_frm_nmgr_alert_struct alert_info;
            memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct)); 
            vapp_msg_nss_set_alert_info_unread_text_preview(&prefix, alert_info);
            mmi_frm_nmgr_alert(&alert_info);
        }
        else
        {
            mmi_frm_nmgr_alert_struct alert_info;
            memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct)); 
            vapp_msg_nss_set_alert_info_icon(ICON_UNREAD, alert_info);
            mmi_frm_nmgr_alert(&alert_info);
        }
    }
}

extern "C" void vapp_msg_show_ncenter_send_fail_balloon(mmi_event_struct *evt, VfxBool isSMS)
{
    mmi_frm_nmgr_alert_struct icon_alert_info;
    memset(&icon_alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct)); 
    vapp_msg_nss_set_alert_info_icon(ICON_UNSEND, icon_alert_info);
    mmi_frm_nmgr_alert(&icon_alert_info);
    
    vapp_msg_write_nvram_setting(VAPP_MSG_NCENTER_UNSEND_CELL, VFX_TRUE);
    vapp_msg_show_ncenter_cell(VAPP_MSG_NCENTER_UNSEND_CELL, vapp_msg_get_send_fail_count());

    VfxWString prefix;
    prefix.loadFromRes(STR_ID_VAPP_MSG_NMGR_SEND_FAIL_PREFIX);
    prefix += VfxWString().format(" ");    

    VfxBool firstHit = VFX_FALSE;  
    MMI_BOOL find = MMI_FALSE;
    VfxU32 numAddr = 0;
    VfxU32 i = 0;
    
    if (isSMS)
    {
        srv_sms_event_struct *smsEvt = (srv_sms_event_struct *)evt;       
        srv_sms_event_update_unsent_msg_status_struct *smsUnsent 
            = (srv_sms_event_update_unsent_msg_status_struct *)smsEvt->event_info;

        VfxWChar smsTmpName[(MMI_PHB_NAME_LENGTH + SRV_UM_MAX_ADDR_LEN) * ENCODING_LENGTH];
        memset(smsTmpName, 0, (MMI_PHB_NAME_LENGTH + SRV_UM_MAX_ADDR_LEN) * ENCODING_LENGTH * sizeof(VfxWChar));
        VfxWChar smsAddr[SRV_SMS_MAX_ADDR_LEN + 1];
        memset(smsAddr, 0, (SRV_SMS_MAX_ADDR_LEN + 1) * sizeof(VfxWChar));
        numAddr = srv_sms_get_msg_addr_num(smsUnsent->msg_id);
        
        /* get the first address */
        srv_sms_status_enum status = SRV_SMS_STATUS_NONE;
        for (i = 0 ; i < numAddr ; i++)
        {
            memset(smsTmpName, 0, (MMI_PHB_NAME_LENGTH + SRV_UM_MAX_ADDR_LEN) * ENCODING_LENGTH * sizeof(VfxWChar));
            memset(smsAddr, 0, (SRV_SMS_MAX_ADDR_LEN + 1) * sizeof(VfxWChar));
            /* check if send fail case */
            srv_sms_get_msg_multi_addr(
                smsAddr, 
                &status,
                smsUnsent->msg_id, 
                i);
            if (SRV_SMS_STATUS_UNSENT == (SRV_SMS_STATUS_UNSENT & status))
            {
                if (VFX_TRUE == firstHit)
                {
                    /* already hit one, add ","*/
                    prefix += VFX_WSTR(", ");
                }
                find = srv_phb_get_name_by_number(smsAddr, smsTmpName, (MMI_PHB_NAME_LENGTH + SRV_UM_MAX_ADDR_LEN) * ENCODING_LENGTH);
                if (find)
                {
                    if (VFX_WSTR_EMPTY == VFX_WSTR_MEM(smsTmpName))
                    {
                        prefix += VFX_WSTR_MEM(smsAddr);
                    }
                    else
                    {
                        prefix += VFX_WSTR_MEM(smsTmpName);
                    }
                }
                else
                {
                    prefix += VFX_WSTR_MEM(smsAddr);
                }
                firstHit = VFX_TRUE;
            }
        }
    }
#ifdef __MMI_MMS_IN_UM__
    else
    {
        srv_mms_base_event_struct *mmsEvt = (srv_mms_base_event_struct *)evt;      
        srv_mms_update_status_struct *mmsUnsent = (srv_mms_update_status_struct *)mmsEvt->sender_data; 
        VfxWChar mmsTmpName[MMI_PHB_NAME_LENGTH + MMA_MAX_ADDR_LEN * 2];
        memset(mmsTmpName, 0, (MMI_PHB_NAME_LENGTH + MMA_MAX_ADDR_LEN * 2) * sizeof(VfxWChar)); 
        VfxWChar mmsAddr[MMA_MAX_ADDR_LEN * 2 + 1];          
        memset(mmsAddr, 0, (MMA_MAX_ADDR_LEN * 2 + 1) * sizeof(VfxWChar));
        /* get the first address */
        for (i = 0 ; i < srv_mms_get_msg_to_address_count(mmsUnsent->msg_id) ; i++)
        {            
            memset(mmsTmpName, 0, (MMI_PHB_NAME_LENGTH + MMA_MAX_ADDR_LEN * 2) * sizeof(VfxWChar));           
            memset(mmsAddr, 0, (MMA_MAX_ADDR_LEN * 2 + 1) * sizeof(VfxWChar));
            srv_mms_get_msg_to_address_by_index(mmsAddr, mmsUnsent->msg_id, i);
            if (VFX_TRUE == firstHit)
            {
                prefix += VFX_WSTR(", ");
            }
            find = srv_phb_get_name_by_number(mmsAddr, mmsTmpName, (MMI_PHB_NAME_LENGTH + MMA_MAX_ADDR_LEN * 2));
            if (find)
            {
                if (VFX_WSTR_EMPTY == VFX_WSTR_MEM(mmsTmpName))
                {
                    prefix += VFX_WSTR_MEM(mmsAddr);
                }
                else
                {
                    prefix += VFX_WSTR_MEM(mmsTmpName);
                }
            }
            else
            {
                prefix += VFX_WSTR_MEM(mmsAddr);
            }
            firstHit = VFX_TRUE;
        }
    } 
#endif /* __MMI_MMS_IN_UM__ */

    mmi_frm_nmgr_alert_struct alert_info;
    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct)); 
    vapp_msg_nss_set_alert_info_unsend_balloon(&prefix, alert_info);
    mmi_frm_nmgr_alert(&alert_info);
}

extern "C" void vapp_msg_close_ncenter_cell(VappMsgNCenterCellMenu cell)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "vapp_msg_close_ncenter_cell cell:%d", cell);
    VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_MSG, cell);
    VfxU32 setting = 0;
    
    switch(cell)
    {
        case VAPP_MSG_NCENTER_UNREAD_CELL:
            {     
                vapp_msg_nss_cancel_alert(ICON_UNREAD);
            }
            break;
            
        case VAPP_MSG_NCENTER_UNSEND_CELL:
            {      
                vapp_msg_nss_cancel_alert(ICON_UNSEND);
            }
            break;            
            
        case VAPP_MSG_NCENTER_FULL_SMS_SIM1_CELL:
    #if (MMI_MAX_SIM_NUM >= 2)
        case VAPP_MSG_NCENTER_FULL_SMS_SIM2_CELL:
    #endif /* MMI_MAX_SIM_NUM >= 2 */
    
    #if (MMI_MAX_SIM_NUM >= 3)
        case VAPP_MSG_NCENTER_FULL_SMS_SIM3_CELL: 
    #endif /* MMI_MAX_SIM_NUM >= 3 */
    
    #if (MMI_MAX_SIM_NUM >= 4)
        case VAPP_MSG_NCENTER_FULL_SMS_SIM4_CELL: 
    #endif /* MMI_MAX_SIM_NUM >= 4 */
    
        case VAPP_MSG_NCENTER_FULL_SMS_PHONE_CELL: 
            
    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
        case VAPP_MSG_NCENTER_FULL_SMS_CARD_CELL:
    #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */
            
    #ifdef __MMI_MMS_IN_UM__
        case VAPP_MSG_NCENTER_FULL_MMS_PHONE_CELL:            
        case VAPP_MSG_NCENTER_FULL_MMS_CARD_CELL:
    #endif /* __MMI_MMS_IN_UM__ */
    
    #ifdef __MMI_PROV_IN_UM__
        case VAPP_MSG_NCENTER_FULL_PRO_CELL:
    #endif /* __MMI_PROV_IN_UM__ */
            {
                vapp_msg_write_nvram_mem_full_setting_single(vapp_msg_full_ncenter_msg_cell_to_type(cell), MMI_FALSE, VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
                setting = vapp_msg_read_nvram_mem_full_setting(VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
            	MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "vapp_msg_close_ncenter_cell setting:%d", setting);	
                if (0 == setting)
                {
                    /* hide status icon */
                    vapp_msg_nss_cancel_alert(ICON_MEMFULL);
                }            
            }
            break;

        default:
            VFX_ASSERT(0);
            break;
    }
}

//Unread
extern "C" mmi_ret vapp_msg_unread_event_hdlr(mmi_event_struct * evt)
{
    srv_um_notify_refresh_evt_struct *refreshEvt = (srv_um_notify_refresh_evt_struct *)evt;
    MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "vapp_msg_unread_event_hdlr box_type:%d, refresh_type:%d", refreshEvt->msg_box_type, refreshEvt->refresh_type);
    
    /* check if copy the unread message into inbox, if yes, treate as new msg */
    VfxBool isRead = VFX_TRUE;
    if (0 == refreshEvt->msg_id && SRV_UM_REFRESH_CREATE_MSG == refreshEvt->refresh_type)
    {
        isRead = VFX_FALSE;
    }
    
    if (0 != refreshEvt->msg_id &&
        SRV_UM_REFRESH_NONE != refreshEvt->refresh_type)
    {
        switch (refreshEvt->msg_type)
        {
            case SRV_UM_MSG_SMS:
                if (SRV_SMS_STATUS_UNREAD & srv_sms_get_msg_status(refreshEvt->msg_id))
                {
                    isRead = VFX_FALSE;
                }
                break;

        #ifdef __MMI_MMS_IN_UM__
            case SRV_UM_MSG_MMS:
                if (MMI_FALSE == srv_mms_mma_get_mms_read_status(refreshEvt->msg_id))
                {
                    isRead = VFX_FALSE;
                }
                break;
        #endif /* __MMI_MMS_IN_UM__ */

        #ifdef __MMI_PUSH_IN_UM__
            case SRV_UM_MSG_WAP_PUSH:
                if (MMI_FALSE == srv_wap_push_msg_read_status(refreshEvt->msg_id))
                {
                    isRead = VFX_FALSE;
                }
                break;
        #endif /* __MMI_PUSH_IN_UM__ */

        #ifdef __MMI_PROV_IN_UM__
            case SRV_UM_MSG_PROV:
                if (SRV_PROVBOX_MSG_READ_STATUS_UNREAD == srv_provbox_get_msg_status(refreshEvt->msg_id))
                {
                    isRead = VFX_FALSE;
                }
                break;
        #endif /* __MMI_PROV_IN_UM__ */

            default:
                break;
        }
    }

    if (VFX_FALSE == isRead)
    {
        vapp_msg_write_nvram_setting(VAPP_MSG_NCENTER_UNREAD_CELL, VFX_TRUE);
    }

    srv_um_get_msg_num_result data;
    S32 result = srv_um_check_msg_num(SRV_UM_SIM_ALL, SRV_UM_MSG_ALL, &data);   
    if( 0 < data.inbox_unread_msg_number && VFX_TRUE == vapp_msg_read_nvram_setting(VAPP_MSG_NCENTER_UNREAD_CELL))
    { 
        vapp_msg_show_ncenter_cell(VAPP_MSG_NCENTER_UNREAD_CELL, data.inbox_unread_msg_number);                  
        vapp_msg_show_ncenter_unread_nmgr_text(evt);
    }
    else
    {
        vapp_msg_close_ncenter_cell(VAPP_MSG_NCENTER_UNREAD_CELL);
        vapp_msg_write_nvram_setting(VAPP_MSG_NCENTER_UNREAD_CELL, VFX_FALSE);
    }
    
    return MMI_RET_OK;
}

extern "C" void vapp_msg_unread_intent_callback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
    if (VSRV_NINTENT_TYPE_LAUNCH == intent.type)
    {
        VappMsgLaunchStruct param;
        vfx_sys_mem_zero(&param, sizeof(VappMsgLaunchStruct));
        param.mode = VAPP_MSG_LAUNCH_INBOX;
        vapp_msg_launch_with_callback(&param, sizeof(VappMsgLaunchStruct));
    }
    else if(VSRV_NINTENT_TYPE_CLEAR == intent.type)
    {
        vapp_msg_close_ncenter_cell(VAPP_MSG_NCENTER_UNREAD_CELL);
        vapp_msg_write_nvram_setting(VAPP_MSG_NCENTER_UNREAD_CELL, VFX_FALSE);
    }    
    else if(VSRV_NINTENT_TYPE_LANGUAGE_CHANGED == intent.type)
    {
        srv_um_get_msg_num_result data;
        S32 result = srv_um_check_msg_num(SRV_UM_SIM_ALL, SRV_UM_MSG_ALL, &data);   
        if( 0 < data.inbox_unread_msg_number && VFX_TRUE == vapp_msg_read_nvram_setting(VAPP_MSG_NCENTER_UNREAD_CELL))
        {
            vapp_msg_show_ncenter_cell(VAPP_MSG_NCENTER_UNREAD_CELL, data.inbox_unread_msg_number);
        }
    }
}

//Unsend
extern "C" mmi_ret vapp_msg_unsend_event_hdlr(mmi_event_struct * evt)
{
    VfxU32 count = vapp_msg_get_send_fail_count();
    if (count > 0 && VFX_TRUE == vapp_msg_read_nvram_setting(VAPP_MSG_NCENTER_UNSEND_CELL))
    {
        vapp_msg_show_ncenter_cell(VAPP_MSG_NCENTER_UNSEND_CELL, count);  
        
        mmi_frm_nmgr_alert_struct alert_info;
        memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct)); 
        vapp_msg_nss_set_alert_info_icon(ICON_UNSEND, alert_info);
        mmi_frm_nmgr_alert(&alert_info);
    }
    else
    {
        vapp_msg_close_ncenter_cell(VAPP_MSG_NCENTER_UNSEND_CELL);
        vapp_msg_write_nvram_setting(VAPP_MSG_NCENTER_UNSEND_CELL, VFX_FALSE);
    }
    
    return MMI_RET_OK;
}

extern "C" mmi_ret vapp_msg_sms_send_event_hdlr(mmi_event_struct * evt)
{
    srv_sms_event_struct *smsEvt = (srv_sms_event_struct *)evt;       
    srv_sms_event_update_unsent_msg_status_struct *smsUnsent 
        = (srv_sms_event_update_unsent_msg_status_struct *)smsEvt->event_info;

    switch (smsUnsent->status)
    {
        case SRV_SMS_SEND_SUCCESS:
        {
            VfxU32 count = vapp_msg_get_send_fail_count();
            if (0 == count || VFX_TRUE == vapp_msg_read_nvram_setting(VAPP_MSG_NCENTER_UNSEND_CELL))
            {
                vapp_msg_close_ncenter_cell(VAPP_MSG_NCENTER_UNSEND_CELL);
                vapp_msg_write_nvram_setting(VAPP_MSG_NCENTER_UNSEND_CELL, VFX_FALSE);                    
                vapp_msg_nss_cancel_alert(ICON_UNSEND);
            }
            else
            {
                vapp_msg_show_ncenter_cell(VAPP_MSG_NCENTER_UNSEND_CELL, count);
            }

            count = vapp_msg_get_sending_count();
            if (0 == count)
            {
                vapp_msg_nss_cancel_alert(ICON_SENDING);
            }
        }
        break;
    
        case SRV_SMS_SEND_SENDING:
        case SRV_SMS_SEND_WAITING:
            {
            	mmi_frm_nmgr_alert_struct alert_info;
                memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct)); 
                vapp_msg_nss_set_alert_info_icon(ICON_SENDING, alert_info);
                mmi_frm_nmgr_alert(&alert_info);
            }
            break;
    
        case SRV_SMS_SEND_FAIL:
            {
                VfxU32 count = vapp_msg_get_send_fail_count();
                if (0 != count)
	        {
                    vapp_msg_show_ncenter_cell(VAPP_MSG_NCENTER_UNSEND_CELL, count);
                    vapp_msg_show_ncenter_send_fail_balloon(evt, VFX_TRUE); 
                }

                //hide sending icon
	        count = vapp_msg_get_sending_count();
                if (0 == count)
        	{
                    vapp_msg_nss_cancel_alert(ICON_SENDING);
        	}
            }
           break;         
    
        default:
            break;
    }

    return MMI_RET_OK;
}

#ifdef __MMI_MMS_IN_UM__
extern "C" mmi_ret vapp_msg_mms_send_event_hdlr(mmi_event_struct * evt)
{
    srv_mms_base_event_struct *mmsEvt = (srv_mms_base_event_struct *)evt;       
    srv_mms_update_status_struct *mmsUnsent = (srv_mms_update_status_struct *)mmsEvt->sender_data;
    MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "vapp_msg_mms_send_event_hdlr mmsUnsent->status:%d", mmsUnsent->status);
    
    switch (mmsUnsent->status)
    {
        case SRV_MMS_MSG_STATUS_SENT:
            {
                VfxU32 count = vapp_msg_get_send_fail_count();
                MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "vapp_msg_get_send_fail_count count:%d", count);
                if (0 == count || VFX_TRUE == vapp_msg_read_nvram_setting(VAPP_MSG_NCENTER_UNSEND_CELL))
                {
                    vapp_msg_close_ncenter_cell(VAPP_MSG_NCENTER_UNSEND_CELL);
                    vapp_msg_write_nvram_setting(VAPP_MSG_NCENTER_UNSEND_CELL, VFX_FALSE);                    
                    vapp_msg_nss_cancel_alert(ICON_SENDING);
                }
                else
                {
                    vapp_msg_show_ncenter_cell(VAPP_MSG_NCENTER_UNSEND_CELL, count);
                }

                count = vapp_msg_get_sending_count();
                MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "vapp_msg_get_sending_count count:%d", count);
                if (0 == count)
                {
                    vapp_msg_nss_cancel_alert(ICON_SENDING);
                }
            }
            break;
   
        case SRV_MMS_MSG_STATUS_SENDING:
        case SRV_MMS_MSG_STATUS_PENDING:
        case SRV_MMS_MSG_STATUS_WAITING:
            {
            	mmi_frm_nmgr_alert_struct alert_info;
                memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct)); 
                vapp_msg_nss_set_alert_info_icon(ICON_SENDING, alert_info);
                mmi_frm_nmgr_alert(&alert_info);
            }
            break;
   
       case SRV_MMS_MSG_STATUS_SENDING_FAILED:
           {
		MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "SRV_MMS_MSG_STATUS_SENDING_FAILED");	
		VfxU32 count = 0;
		if (srv_mms_is_msg_exist(mmsUnsent->msg_id))
		{
		      MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "SRV_MMS_MSG_STATUS_SENDING_FAILED srv_mms_is_msg_exist");
		      count = vapp_msg_get_send_fail_count();
	              MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "vapp_msg_get_send_fail_count count:%d", count);
		      if (0 != count)
		      {
                           vapp_msg_show_ncenter_cell(VAPP_MSG_NCENTER_UNSEND_CELL, count);
                           vapp_msg_show_ncenter_send_fail_balloon(evt, VFX_FALSE); 
		      }
		}
               count = vapp_msg_get_sending_count();
	       MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "SRV_MMS_MSG_STATUS_SENDING_FAILED vapp_msg_get_sending_count %d", count);
               if (0 == count)
               {				   
                   vapp_msg_nss_cancel_alert(ICON_SENDING);
               }
           }
           break;
   
       default:
           break;
   }

    return MMI_RET_OK;
}
#endif /* __MMI_MMS_IN_UM__ */

extern "C" void vapp_msg_unsend_intent_callback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
    if (VSRV_NINTENT_TYPE_LAUNCH == intent.type)
    {
        VappMsgLaunchStruct param;
        vfx_sys_mem_zero(&param, sizeof(VappMsgLaunchStruct));
        param.mode = VAPP_MSG_LAUNCH_OUTBOX;
        param.cbFunc = vapp_msg_unsend_launch_callback;
        vapp_msg_launch_with_callback(&param, sizeof(VappMsgLaunchStruct));
    }
    else if(VSRV_NINTENT_TYPE_CLEAR == intent.type)
    {
        vapp_msg_close_ncenter_cell(VAPP_MSG_NCENTER_UNSEND_CELL);
        vapp_msg_write_nvram_setting(VAPP_MSG_NCENTER_UNSEND_CELL, VFX_FALSE);
    }
    else if(VSRV_NINTENT_TYPE_LANGUAGE_CHANGED == intent.type)
    {
        VfxU32 count = vapp_msg_get_send_fail_count();
        if (count > 0 && vapp_msg_read_nvram_setting(VAPP_MSG_NCENTER_UNSEND_CELL))
        {
            vapp_msg_show_ncenter_cell(VAPP_MSG_NCENTER_UNSEND_CELL, count);
        }
    }
}

extern "C" void vapp_msg_unsend_launch_callback(VfxAppLauncherResultEnum result, void *userData)
{
    if (VFX_APP_LAUNCHER_RESULT_OK == result)
    {
        vapp_msg_close_ncenter_cell(VAPP_MSG_NCENTER_UNSEND_CELL);
        vapp_msg_write_nvram_setting(VAPP_MSG_NCENTER_UNSEND_CELL, VFX_FALSE);
    }
}

extern "C" VfxU32 vapp_msg_get_send_fail_count()
{
    VfxU32 count = 0;

    count += vapp_sms_get_send_failed_count();

#ifdef __MMI_MMS_IN_UM__
    srv_mms_get_msg_count_struct msg_count_req;

    vfx_sys_mem_zero(&msg_count_req, sizeof(srv_mms_get_msg_count_struct));

    msg_count_req.count = MMI_MAX_SIM_NUM;
    U16 requestSim = SRV_MMS_QUERY_TOTAL_OUTBOX_SIM1;
    U16 index = 0;
    for (index = 0; index < MMI_MAX_SIM_NUM ; index++, requestSim++)
    {
        msg_count_req.count++;
        msg_count_req.req_tb[index] = requestSim;
    }
    
    VfxS32 result = srv_mms_get_msg_count(&msg_count_req);    
    if (SRV_MMS_RESULT_OK == result)
    {
        for (index = 0 ; index < MMI_MAX_SIM_NUM ; index++)
        {
            count += msg_count_req.rsp_tb[index];
        }
        if (0 < count)
        {
            if (MMI_TRUE == srv_mms_has_sending_mms())
            {
                /* one is sending, decrese it */
                count--;
            }
            if (MMI_TRUE == srv_mms_has_waiting_mms())
            {
                VfxU32 waitingCount = 0;
                waitingCount = srv_mms_get_waiting_mms_count();
                if (count >= waitingCount)
                {
                    count -= waitingCount;
                }
                else
                {
                    count = 0;
                }
            }
        }
    }
#endif /* __MMI_MMS_IN_UM__ */

    return count;
}

extern "C" VfxU32 vapp_msg_get_sending_count()
{
    VfxU32 count = 0;
    
    if (MMI_TRUE == vapp_sms_has_sending_sms() 
        || MMI_TRUE == vapp_sms_has_waiting_sms() 
#ifdef __MMI_MMS_IN_UM__
        || MMI_TRUE == srv_mms_has_sending_mms() 
        || MMI_TRUE == srv_mms_has_waiting_mms()
#endif /* __MMI_MMS_IN_UM__ */
        )
    {
        count = 1;
    }
    
    return count;
}

extern "C" void vapp_msg_mem_full_intent_callback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
    VappMsgLaunchStruct param;
    vfx_sys_mem_zero(&param, sizeof(VappMsgLaunchStruct));
    vapp_msg_ncenter_info_struct* cell_info = (vapp_msg_ncenter_info_struct*)userData;
    
    if (VSRV_NINTENT_TYPE_LAUNCH == intent.type)
    {        
        switch(cell_info->type)
        {
            case VAPP_MSG_NCENTER_FULL_SMS_SIM1_CELL:
                param.mode = VAPP_MSG_LAUNCH_SIM1_BOX;
                break;     
                
    	#if (MMI_MAX_SIM_NUM >= 2)
            case VAPP_MSG_NCENTER_FULL_SMS_SIM2_CELL:
                param.mode = VAPP_MSG_LAUNCH_SIM2_BOX;
                break;    
        #endif /* (MMI_MAX_SIM_NUM >= 2 */
    	#if (MMI_MAX_SIM_NUM >= 3)
            case VAPP_MSG_NCENTER_FULL_SMS_SIM3_CELL:
                param.mode = VAPP_MSG_LAUNCH_SIM3_BOX;
                break;      
        #endif /* (MMI_MAX_SIM_NUM >= 3 */
    	#if (MMI_MAX_SIM_NUM >= 4)
            case VAPP_MSG_NCENTER_FULL_SMS_SIM4_CELL:
                param.mode = VAPP_MSG_LAUNCH_SIM4_BOX;
                break;    
        #endif /* (MMI_MAX_SIM_NUM >= 4 */
        
            case VAPP_MSG_NCENTER_FULL_SMS_PHONE_CELL:
                param.mode = VAPP_MSG_LAUNCH_INBOX;
                break;  
                
        #ifdef __MMI_MMS_IN_UM__   
            case VAPP_MSG_NCENTER_FULL_MMS_PHONE_CELL:
                param.mode = VAPP_MSG_LAUNCH_INBOX;
                break;  
            case VAPP_MSG_NCENTER_FULL_MMS_CARD_CELL:
                param.mode = VAPP_MSG_LAUNCH_INBOX;
                break; 
        #endif /* __MMI_MMS_IN_UM__ */

        #ifdef __MMI_PROV_IN_UM__
            case VAPP_MSG_NCENTER_FULL_PRO_CELL:
                param.mode = VAPP_MSG_LAUNCH_INBOX;
                break;          
        #endif /* __MMI_PROV_IN_UM__ */    
                
        #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
            case VAPP_MSG_NCENTER_FULL_SMS_CARD_CELL:
                param.mode = VAPP_MSG_LAUNCH_INBOX;
                break;          
        #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */

            default:
                break;
        }
        param.cbFunc = vapp_msg_mem_full_launch_callback;
        param.cbFuncParam = (void*)(cell_info);
        param.cbFuncParamSize = sizeof(vapp_msg_ncenter_info_struct);
        vapp_msg_launch_with_callback(&param, sizeof(VappMsgLaunchStruct));
    }
    else if(VSRV_NINTENT_TYPE_CLEAR == intent.type )
    {
        vapp_msg_update_mem_full_previous_setting(vapp_msg_full_ncenter_msg_cell_to_type(cell_info->type));
        vapp_msg_write_nvram_mem_full_setting_single(vapp_msg_full_ncenter_msg_cell_to_type(cell_info->type), VFX_FALSE, VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
        vapp_msg_close_ncenter_cell(cell_info->type);
    }  
    else if(VSRV_NINTENT_TYPE_LANGUAGE_CHANGED == intent.type)
    {
        VfxU32 setting = vapp_msg_read_nvram_mem_full_setting(VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
        if (setting & vapp_msg_full_ncenter_msg_cell_to_type(cell_info->type))
        {
            vapp_msg_show_ncenter_cell(cell_info->type);
        }
    }
}

extern "C" void vapp_msg_mem_full_launch_callback(VfxAppLauncherResultEnum result, void *userData)
{
    if(VFX_APP_LAUNCHER_RESULT_OK == result)
    {
        vapp_msg_ncenter_info_struct* cell_info = (vapp_msg_ncenter_info_struct*)userData;
        vapp_msg_update_mem_full_previous_setting(vapp_msg_full_ncenter_msg_cell_to_type(cell_info->type));
        vapp_msg_write_nvram_mem_full_setting_single(vapp_msg_full_ncenter_msg_cell_to_type(cell_info->type), VFX_FALSE, VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
        vapp_msg_close_ncenter_cell(cell_info->type);
    }
}

extern "C" srv_sms_sim_enum vapp_msg_tsfr_type_to_sms_sim(VappMsgFullNCenterMsgTypeEnum type)
{
    srv_sms_sim_enum simCard = (srv_sms_sim_enum)0;

    switch (type)
    {
        case VAPP_MSG_FULL_NCENTER_SMS_SIM1:
            simCard = SRV_SMS_SIM_1;
            break;

    #if (MMI_MAX_SIM_NUM >= 2)
        case VAPP_MSG_FULL_NCENTER_SMS_SIM2:
            simCard = SRV_SMS_SIM_2;
            break;
    #endif /* MMI_MAX_SIM_NUM >= 2 */

    #if (MMI_MAX_SIM_NUM >= 3)
        case VAPP_MSG_FULL_NCENTER_SMS_SIM3:
            simCard = SRV_SMS_SIM_3;
            break;
    #endif /* MMI_MAX_SIM_NUM >= 3 */

    #if (MMI_MAX_SIM_NUM >= 4)
        case VAPP_MSG_FULL_NCENTER_SMS_SIM4:
            simCard = SRV_SMS_SIM_4;
            break;
    #endif /* MMI_MAX_SIM_NUM >= 4 */

        case VAPP_MSG_FULL_NCENTER_SMS_CARD:
            simCard = SRV_SMS_SIM_1;
            break;

        case VAPP_MSG_FULL_NCENTER_SMS_PHONE:
            simCard = SRV_SMS_SIM_1;
            break;

        default:
            break;
    }

    return simCard;
}

extern "C" VfxU32 vapp_msg_tsfr_type_to_strId(VappMsgFullNCenterMsgTypeEnum type, VappMsgFullNcenterTextFieldEnum field)
{
    VfxU32 strId = 0;

    /* if type is sim sms and only insert one sim, use as the single project design */
    if (type == VAPP_MSG_FULL_NCENTER_SMS_SIM1 ||
        type == VAPP_MSG_FULL_NCENTER_SMS_SIM2 ||
        type == VAPP_MSG_FULL_NCENTER_SMS_SIM3 ||
        type == VAPP_MSG_FULL_NCENTER_SMS_SIM4)
    {
        if (1 == srv_sim_ctrl_get_num_of_inserted())
        {
            if (VAPP_MSG_FULL_NCENTER_MAIN_TEXT == field)
            {
                strId = STR_ID_VAPP_MSG_SIM_SMS_FULL;
            }
            else
            {
                strId = STR_ID_VAPP_MSG_SMS_REACH;
            }

            return strId;
        }
    }

    switch (type)
    {
    #if (MMI_MAX_SIM_NUM >= 2)
        case VAPP_MSG_FULL_NCENTER_SMS_SIM1:
            if (VAPP_MSG_FULL_NCENTER_MAIN_TEXT == field)
            {
                strId = STR_ID_VAPP_MSG_SIM1_SMS_FULL;
            }
            else
            {
                strId = STR_ID_VAPP_MSG_SMS_REACH;
            }
            break;

        case VAPP_MSG_FULL_NCENTER_SMS_SIM2:
            if (VAPP_MSG_FULL_NCENTER_MAIN_TEXT == field)
            {
                strId = STR_ID_VAPP_MSG_SIM2_SMS_FULL;
            }
            else
            {
                strId = STR_ID_VAPP_MSG_SMS_REACH;
            }
            break;
    #endif /* MMI_MAX_SIM_NUM >= 2 */

    #if (MMI_MAX_SIM_NUM >= 3)
        case VAPP_MSG_FULL_NCENTER_SMS_SIM3:
            if (VAPP_MSG_FULL_NCENTER_MAIN_TEXT == field)
            {
                strId = STR_ID_VAPP_MSG_SIM3_SMS_FULL;
            }
            else
            {
                strId = STR_ID_VAPP_MSG_SMS_REACH;
            }
            break;
    #endif /* MMI_MAX_SIM_NUM >= 3 */

    #if (MMI_MAX_SIM_NUM >= 4)
        case VAPP_MSG_FULL_NCENTER_SMS_SIM4:
            if (VAPP_MSG_FULL_NCENTER_MAIN_TEXT == field)
            {
                strId = STR_ID_VAPP_MSG_SIM4_SMS_FULL;
            }
            else
            {
                strId = STR_ID_VAPP_MSG_SMS_REACH;
            }
            break;
    #endif /* MMI_MAX_SIM_NUM >= 4 */

        case VAPP_MSG_FULL_NCENTER_SMS_PHONE:
            if (VAPP_MSG_FULL_NCENTER_MAIN_TEXT == field)
            {
                strId = STR_ID_VAPP_MSG_PHONE_SMS_FULL;
            }
            else
            {
                strId = STR_ID_VAPP_MSG_SMS_REACH;
            }
            break;

    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
        case VAPP_MSG_FULL_NCENTER_SMS_CARD:
            if (VAPP_MSG_FULL_NCENTER_MAIN_TEXT == field)
            {
                strId = STR_ID_VAPP_MSG_SMS_MEMORY_CARD_FULL;
            }
            else
            {
                strId = STR_ID_VAPP_MSG_SMS_REACH;
            }
            break;
    #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */

    #ifdef __MMI_MMS_IN_UM__
        case VAPP_MSG_FULL_NCENTER_MMS_PHONE:
            if (VAPP_MSG_FULL_NCENTER_MAIN_TEXT == field)
            {
                strId = STR_ID_VAPP_MSG_PHONE_MMS_FULL;
            }
            else
            {
                strId = STR_ID_VAPP_MSG_MMS_REACH;
            }
            break;

        case VAPP_MSG_FULL_NCENTER_MMS_CARD:
            if (VAPP_MSG_FULL_NCENTER_MAIN_TEXT == field)
            {
                strId = STR_ID_VAPP_MSG_CARD_MMS_FULL;
            }
            else
            {
                strId = STR_ID_VAPP_MSG_MMS_REACH;
            }
            break;
    #endif /* __MMI_MMS_IN_UM__ */

    #ifdef __MMI_PROV_IN_UM__
        case VAPP_MSG_FULL_NCENTER_PROV:
            if (VAPP_MSG_FULL_NCENTER_MAIN_TEXT == field)
            {
                strId = STR_ID_VAPP_MSG_PROV_FULL;
            }
            else
            {
                strId = STR_ID_VAPP_MSG_PROV_REACH;
            }
            break;
    #endif /* __MMI_PROV_IN_UM__ */

        default:
            break;
    }

    return strId;
}

extern "C" VfxBool vapp_msg_is_insert_sim(VappMsgFullNCenterMsgTypeEnum type)
{
    VfxBool insert = VFX_TRUE;
    
    switch (type)
    {
        case VAPP_MSG_FULL_NCENTER_SMS_SIM1:
            if (MMI_FALSE == srv_sim_ctrl_is_inserted(MMI_SIM1))
            {
                insert = VFX_FALSE;
            }
            break;

    #if (MMI_MAX_SIM_NUM >= 2)
        case VAPP_MSG_FULL_NCENTER_SMS_SIM2:
            if (MMI_FALSE == srv_sim_ctrl_is_inserted(MMI_SIM2))
            {
                insert = VFX_FALSE;
            }
            break;
    #endif /* MMI_MAX_SIM_NUM >= 2 */

    #if (MMI_MAX_SIM_NUM >= 3)
        case VAPP_MSG_FULL_NCENTER_SMS_SIM3:
            if (MMI_FALSE == srv_sim_ctrl_is_inserted(MMI_SIM3))
            {
                insert = VFX_FALSE;
            }
            break;
    #endif /* MMI_MAX_SIM_NUM >= 3 */

    #if (MMI_MAX_SIM_NUM >= 4)
        case VAPP_MSG_FULL_NCENTER_SMS_SIM4:
            if (MMI_FALSE == srv_sim_ctrl_is_inserted(MMI_SIM4))
            {
                insert = VFX_FALSE;
            }
            break;
    #endif /* MMI_MAX_SIM_NUM >= 4 */

        case VAPP_MSG_FULL_NCENTER_MMS_CARD:
            if (MMI_FALSE == srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
            {
                insert = VFX_FALSE;
            }
            break;

        default:
            break;
    }

    return insert;
}

extern "C" VfxU32 vapp_msg_query_memory_max(VappMsgFullNCenterMsgTypeEnum type)
{    
    VfxU32 max = 0;

    if (VAPP_MSG_FULL_NCENTER_SMS_SIM1 <= type && VAPP_MSG_FULL_NCENTER_SMS_CARD >= type)
    {
        /* sms memory */
        max = vapp_msg_query_sms_max(vapp_msg_tsfr_type_to_sms_sim(type), type);
    }
#ifdef __MMI_MMS_IN_UM__
    else if (VAPP_MSG_FULL_NCENTER_MMS_PHONE == type || VAPP_MSG_FULL_NCENTER_MMS_CARD == type)
    {
        max = vapp_msg_query_mms_max(type);
    }
#endif /* __MMI_MMS_IN_UM__ */
#ifdef __MMI_PROV_IN_UM__
    else if (VAPP_MSG_FULL_NCENTER_PROV == type)
    {
        max = vapp_msg_query_prov_max();
    }
#endif /* __MMI_PROV_IN_UM__ */

    return max;
}

extern "C" VfxU32 vapp_msg_query_sms_max(srv_sms_sim_enum simCard, VappMsgFullNCenterMsgTypeEnum type)
{
    MMI_BOOL ready = MMI_FALSE;
    srv_sms_memory_status_struct status;

    vfx_sys_mem_zero(&status, sizeof(srv_sms_memory_status_struct));
    ready = srv_sms_get_memory_status(simCard, &status);

    VfxU32 max = 0;
    if (MMI_TRUE == ready)
    {
        if (VAPP_MSG_FULL_NCENTER_SMS_PHONE == type)
        {
            max = status.me_total;
        }
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        else if (VAPP_MSG_FULL_NCENTER_SMS_CARD == type)
        {
            max = status.tcard_total;
        }
    #endif /* __SRV_SMS_TCARD_STORAGE_SUPPORT__ */
        else
        {
            max = status.sim_total;
        }
    }

    return max;
}

#ifdef __MMI_MMS_IN_UM__
extern "C" VfxU32 vapp_msg_query_mms_max(VappMsgFullNCenterMsgTypeEnum type)
{
    VfxU32 max = 0;
    if (VAPP_MSG_FULL_NCENTER_MMS_PHONE == type)
    {
        max = (VfxU32)srv_mms_get_max_mms_num_on_phone();
    }
    else
    {
        max = (VfxU32)srv_mms_get_max_mms_num_on_card();
    }
        
    return max;
}
#endif /* __MMI_MMS_IN_UM__ */

#ifdef __MMI_PROV_IN_UM__
extern "C" VfxU32 vapp_msg_query_prov_max()
{
    return srv_provbox_get_total_msg_num();
}
#endif /* __MMI_PROV_IN_UM__ */

extern "C" mmi_ret vapp_msg_sms_mem_full_event_hdlr(mmi_event_struct *evt)
{
    srv_sms_event_struct *smsEvt = (srv_sms_event_struct *)evt;
    srv_sms_event_mem_available_struct *smsMemory = (srv_sms_event_mem_available_struct *)smsEvt->event_info;

    MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "vapp_msg_sms_mem_full_event_hdlr, evt_id = %d, smsMemory_memtype = %d", evt->evt_id, smsMemory->mem_type);
    
    VfxBool isPhoneMemFull = VFX_FALSE;
    VfxBool isPhoneAvailable = VFX_FALSE;
    
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
    VfxBool isCardMemFull = VFX_FALSE;
    VfxBool isCardAvailable = VFX_FALSE;
#endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_SMS_MEM_FULL:
        {            
            switch(smsMemory->sim_id)
            {
                case SRV_SMS_SIM_1:
                    {
                        if (SRV_SMS_MEM_ME_ONLY == (SRV_SMS_MEM_ME_ONLY & smsMemory->mem_type))
                        {
                            if (!mem_full_phone_prev)
                            {
                                isPhoneMemFull = VFX_TRUE;
                                mem_full_phone_prev = MMI_TRUE;
                            }
                        }
                        
                    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
                        if ((SRV_SMS_MEM_TCARD_ONLY == (SRV_SMS_MEM_TCARD_ONLY & smsMemory->mem_type)) && (MMI_TRUE == srv_sms_is_tcard_valid()))
                        {
                            isCardMemFull = VFX_TRUE;
                        }
                    #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */
                    
                        if ((SRV_SMS_MEM_SIM_ONLY == (SRV_SMS_MEM_SIM_ONLY & smsMemory->mem_type)) && (MMI_TRUE == srv_sim_ctrl_is_inserted(MMI_SIM1)))
                        {       
                            if (srv_um_check_ready())
                            {
                                if (!vapp_msg_mem_full_cell_is_show(VAPP_MSG_FULL_NCENTER_SMS_SIM1))
                                {
                                    vapp_msg_check_show_mem_full_cell(VAPP_MSG_NCENTER_FULL_SMS_SIM1_CELL);
                                }
                            }
                            else
                            {
                                if (!vapp_msg_mem_full_cell_is_previous_show(VAPP_MSG_FULL_NCENTER_SMS_SIM1))
                                {
                                    mem_full_setting |= VAPP_MSG_FULL_NCENTER_SMS_SIM1;
                                }
                            }
                        }
                    }
                    break;
                        
            #if (MMI_MAX_SIM_NUM >= 2)
                case SRV_SMS_SIM_2:
                    {
                        if (SRV_SMS_MEM_ME_ONLY == (SRV_SMS_MEM_ME_ONLY & smsMemory->mem_type)) 
                        {
                            if (!mem_full_phone_prev)
                            {
                                isPhoneMemFull = VFX_TRUE;
                                mem_full_phone_prev = MMI_TRUE;
                            }
                        }

                    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
                        if ((SRV_SMS_MEM_TCARD_ONLY == (SRV_SMS_MEM_TCARD_ONLY & smsMemory->mem_type)) && (MMI_TRUE == srv_sms_is_tcard_valid()))
                        {
                            isCardMemFull = VFX_TRUE;
                        }
                    #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */

                        if ((SRV_SMS_MEM_SIM_ONLY == (SRV_SMS_MEM_SIM_ONLY & smsMemory->mem_type)) && (MMI_TRUE == srv_sim_ctrl_is_inserted(MMI_SIM2)))
                        {	
                            if (srv_um_check_ready())
                            {                            
                                if (!vapp_msg_mem_full_cell_is_show(VAPP_MSG_FULL_NCENTER_SMS_SIM2))
                                {
                                    vapp_msg_check_show_mem_full_cell(VAPP_MSG_NCENTER_FULL_SMS_SIM2_CELL);
                                }
                            }
                            else
                            {
                                if (!vapp_msg_mem_full_cell_is_previous_show(VAPP_MSG_FULL_NCENTER_SMS_SIM2))
                                {
                                    mem_full_setting |= VAPP_MSG_FULL_NCENTER_SMS_SIM2;
                                }
                            }
                        }
                    }
                    break;
            #endif /*MMI_MAX_SIM_NUM >= 2*/

            #if (MMI_MAX_SIM_NUM >= 3)
                case SRV_SMS_SIM_3:
                    {
                        if (SRV_SMS_MEM_ME_ONLY == (SRV_SMS_MEM_ME_ONLY & smsMemory->mem_type))
                        {
                            isPhoneMemFull = VFX_TRUE;
                        }

                    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
                        if ((SRV_SMS_MEM_TCARD_ONLY == (SRV_SMS_MEM_TCARD_ONLY & smsMemory->mem_type)) && (MMI_TRUE == srv_sms_is_tcard_valid()))
                        {
                            if (!mem_full_phone_prev)
                            {
                                isPhoneMemFull = VFX_TRUE;
                                mem_full_phone_prev = MMI_TRUE;
                            }
                        }                        
                    #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */
                    
                        if ((SRV_SMS_MEM_SIM_ONLY == (SRV_SMS_MEM_SIM_ONLY & smsMemory->mem_type)) && (MMI_TRUE == srv_sim_ctrl_is_inserted(MMI_SIM3)))
                        {
                            if (srv_um_check_ready())
                            {
                                if (!vapp_msg_mem_full_cell_is_show(VAPP_MSG_FULL_NCENTER_SMS_SIM3))
                                {
                                    vapp_msg_check_show_mem_full_cell(VAPP_MSG_NCENTER_FULL_SMS_SIM3_CELL);
                                }
                            }
                            else
                            {
                                if (!vapp_msg_mem_full_cell_is_previous_show(VAPP_MSG_FULL_NCENTER_SMS_SIM3))
                                {
                                    mem_full_setting |= VAPP_MSG_FULL_NCENTER_SMS_SIM3;
                                }
                            }
                        }
                    }
                    break;
            #endif /*MMI_MAX_SIM_NUM >= 3*/
                    
            #if (MMI_MAX_SIM_NUM >= 4)
                case SRV_SMS_SIM_4:
                    {
                        if (SRV_SMS_MEM_ME_ONLY == (SRV_SMS_MEM_ME_ONLY & smsMemory->mem_type))
                        {
                            if (!mem_full_phone_prev)
                            {
                                isPhoneMemFull = VFX_TRUE;
                                mem_full_phone_prev = MMI_TRUE;
                            }
                        }

                    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
                        if ((SRV_SMS_MEM_TCARD_ONLY == (SRV_SMS_MEM_TCARD_ONLY & smsMemory->mem_type)) && (MMI_TRUE == srv_sms_is_tcard_valid()))
                        {
                            isCardMemFull = VFX_TRUE;
                        }
                    #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */

                        if ((SRV_SMS_MEM_SIM_ONLY == (SRV_SMS_MEM_SIM_ONLY & smsMemory->mem_type)) && (MMI_TRUE == srv_sim_ctrl_is_inserted(MMI_SIM4)))
                        {
                            if (srv_um_check_ready())
                            {
                                if (!vapp_msg_mem_full_cell_is_show(VAPP_MSG_FULL_NCENTER_SMS_SIM4))
                                {
                                    vapp_msg_check_show_mem_full_cell(VAPP_MSG_NCENTER_FULL_SMS_SIM4_CELL);
                                }
                            }
                            else
                            {
                                if (!vapp_msg_mem_full_cell_is_previous_show(VAPP_MSG_FULL_NCENTER_SMS_SIM4))
                                {
                                    mem_full_setting |= VAPP_MSG_FULL_NCENTER_SMS_SIM4;
                                }
                            }
                        }
                    }
                    break;
            #endif /*MMI_MAX_SIM_NUM >= 4*/
            
                default:
                    break;
            }
            if (isPhoneMemFull)
            {                    
                if (srv_um_check_ready())
                {
                    if (!vapp_msg_mem_full_cell_is_show(VAPP_MSG_FULL_NCENTER_SMS_PHONE))
                    {
                        vapp_msg_check_show_mem_full_cell(VAPP_MSG_NCENTER_FULL_SMS_PHONE_CELL);
                    }
                }
                else
                {                    
                    if (!vapp_msg_mem_full_cell_is_previous_show(VAPP_MSG_FULL_NCENTER_SMS_PHONE))
                    {
                        mem_full_setting |= VAPP_MSG_FULL_NCENTER_SMS_PHONE;
                    }
                }
            }
        #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
            if (isCardMemFull)
            {
                if (srv_um_check_ready())
                {
                    if (!vapp_msg_mem_full_cell_is_show(VAPP_MSG_FULL_NCENTER_SMS_CARD))
                    {
                        vapp_msg_check_show_mem_full_cell(VAPP_MSG_NCENTER_FULL_SMS_CARD_CELL);
                    }
                }
                else
                {
                    if (!vapp_msg_mem_full_cell_is_previous_show(VAPP_MSG_FULL_NCENTER_SMS_CARD))
                    {
                        mem_full_setting |= VAPP_MSG_FULL_NCENTER_SMS_CARD;
                    }
                }
            }    
        #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__  */
        }
            break;        

        case EVT_ID_SRV_SMS_MEM_AVAILABLE:
        {
            switch(smsMemory->sim_id)
            {
                case SRV_SMS_SIM_1:
                    {                        
                        if (SRV_SMS_MEM_ME_ONLY == (SRV_SMS_MEM_ME_ONLY & smsMemory->mem_type))
                        {
                            isPhoneAvailable = VFX_TRUE;
                        }

                    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
                        if ((SRV_SMS_MEM_TCARD_ONLY == (SRV_SMS_MEM_TCARD_ONLY & smsMemory->mem_type)) || (MMI_FALSE == srv_sms_is_tcard_valid()))
                        {
                            isCardAvailable = VFX_TRUE;
                        }
                    #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */

                        if (SRV_SMS_MEM_SIM_ONLY == (SRV_SMS_MEM_SIM_ONLY & smsMemory->mem_type) || (MMI_FALSE == srv_sim_ctrl_is_inserted(MMI_SIM1)))
                        {                               
                            vapp_msg_write_nvram_mem_full_setting_single(VAPP_MSG_FULL_NCENTER_SMS_SIM1, VFX_FALSE, VAPP_MSG_FULL_NCENTER_PREVIOUS_EVT);
                            vapp_msg_write_nvram_mem_full_setting_single(VAPP_MSG_FULL_NCENTER_SMS_SIM1, VFX_FALSE, VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
                            vapp_msg_close_ncenter_cell(VAPP_MSG_NCENTER_FULL_SMS_SIM1_CELL);
                        }
                    }
                    break;
                        
            #if (MMI_MAX_SIM_NUM >= 2)
                case SRV_SMS_SIM_2:
                    { 
                        if (SRV_SMS_MEM_ME_ONLY == (SRV_SMS_MEM_ME_ONLY & smsMemory->mem_type))
                        {
                            isPhoneAvailable = VFX_TRUE;
                        }

                    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
                        if ((SRV_SMS_MEM_TCARD_ONLY == (SRV_SMS_MEM_TCARD_ONLY & smsMemory->mem_type)) || (MMI_FALSE == srv_sms_is_tcard_valid()))
                        {
                            isCardAvailable = VFX_TRUE;
                        }
                    #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */

                        if (SRV_SMS_MEM_SIM_ONLY == (SRV_SMS_MEM_SIM_ONLY & smsMemory->mem_type) || (MMI_FALSE == srv_sim_ctrl_is_inserted(MMI_SIM2)))
                        {    
                            vapp_msg_write_nvram_mem_full_setting_single(VAPP_MSG_FULL_NCENTER_SMS_SIM2, VFX_FALSE, VAPP_MSG_FULL_NCENTER_PREVIOUS_EVT);
                            vapp_msg_write_nvram_mem_full_setting_single(VAPP_MSG_FULL_NCENTER_SMS_SIM2, VFX_FALSE, VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
                            vapp_msg_close_ncenter_cell(VAPP_MSG_NCENTER_FULL_SMS_SIM2_CELL);
                        }
                    }
                    break;
            #endif /* MMI_MAX_SIM_NUM >= 2 */

            #if (MMI_MAX_SIM_NUM >= 3)
                case SRV_SMS_SIM_3:
                    {
                        if (SRV_SMS_MEM_ME_ONLY == (SRV_SMS_MEM_ME_ONLY & smsMemory->mem_type))
                        {
                            isPhoneAvailable = VFX_TRUE;
                        }

                    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
                        if ((SRV_SMS_MEM_TCARD_ONLY == (SRV_SMS_MEM_TCARD_ONLY & smsMemory->mem_type)) || (MMI_FALSE == srv_sms_is_tcard_valid()))
                        {
                            isCardAvailable = VFX_TRUE;
                        }
                    #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */

                        if (SRV_SMS_MEM_SIM_ONLY == (SRV_SMS_MEM_SIM_ONLY & smsMemory->mem_type) || (MMI_FALSE == srv_sim_ctrl_is_inserted(MMI_SIM3)))
                        {                            
                            vapp_msg_write_nvram_mem_full_setting_single(VAPP_MSG_FULL_NCENTER_SMS_SIM3, VFX_FALSE, VAPP_MSG_FULL_NCENTER_PREVIOUS_EVT);
                            vapp_msg_write_nvram_mem_full_setting_single(VAPP_MSG_FULL_NCENTER_SMS_SIM3, VFX_FALSE, VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
                            vapp_msg_close_ncenter_cell(VAPP_MSG_NCENTER_FULL_SMS_SIM3_CELL);
                        }
                    }
                    break;
            #endif /* MMI_MAX_SIM_NUM >= 3 */
                    
            #if (MMI_MAX_SIM_NUM >= 4)
                case SRV_SMS_SIM_4:
                    {
                        if (SRV_SMS_MEM_ME_ONLY == (SRV_SMS_MEM_ME_ONLY & smsMemory->mem_type))
                        {
                            isPhoneAvailable = VFX_TRUE;
                        }

                    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
                        if ((SRV_SMS_MEM_TCARD_ONLY == (SRV_SMS_MEM_TCARD_ONLY & smsMemory->mem_type)) || (MMI_FALSE == srv_sms_is_tcard_valid()))
                        {
                            isCardAvailable = VFX_TRUE;
                        }
                    #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */

                        if (SRV_SMS_MEM_SIM_ONLY == (SRV_SMS_MEM_SIM_ONLY & smsMemory->mem_type) || (MMI_FALSE == srv_sim_ctrl_is_inserted(MMI_SIM4)))
                        {                            
                            vapp_msg_write_nvram_mem_full_setting_single(VAPP_MSG_FULL_NCENTER_SMS_SIM4, VFX_FALSE, VAPP_MSG_FULL_NCENTER_PREVIOUS_EVT);
                            vapp_msg_write_nvram_mem_full_setting_single(VAPP_MSG_FULL_NCENTER_SMS_SIM4, VFX_FALSE, VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
                            vapp_msg_close_ncenter_cell(VAPP_MSG_NCENTER_FULL_SMS_SIM4_CELL);
                        }
                    }
                    break;
            #endif /* MMI_MAX_SIM_NUM >= 4 */
            
                default:
                    break;
            }
            if (isPhoneAvailable)
            {                    
                vapp_msg_write_nvram_mem_full_setting_single(VAPP_MSG_FULL_NCENTER_SMS_PHONE, VFX_FALSE, VAPP_MSG_FULL_NCENTER_PREVIOUS_EVT);
                vapp_msg_write_nvram_mem_full_setting_single(VAPP_MSG_FULL_NCENTER_SMS_PHONE, VFX_FALSE, VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
                vapp_msg_close_ncenter_cell(VAPP_MSG_NCENTER_FULL_SMS_PHONE_CELL);
                mem_full_phone_prev = MMI_FALSE;
            }
        #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
            if (isCardAvailable)
            {                    
                vapp_msg_write_nvram_mem_full_setting_single(VAPP_MSG_FULL_NCENTER_SMS_CARD, VFX_FALSE, VAPP_MSG_FULL_NCENTER_PREVIOUS_EVT);
                vapp_msg_write_nvram_mem_full_setting_single(VAPP_MSG_FULL_NCENTER_SMS_CARD, VFX_FALSE, VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
                vapp_msg_close_ncenter_cell(VAPP_MSG_NCENTER_FULL_SMS_CARD_CELL);
            }
        #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */
        }
            break;

        default:
            break;
        }

    return MMI_RET_OK;
}

#ifdef __MMI_MMS_IN_UM__
extern "C" mmi_ret vapp_msg_mms_mem_full_event_hdlr(mmi_event_struct *evt)
{    
    srv_mms_mem_status_event_struct *mmsEvt = (srv_mms_mem_status_event_struct *)evt;
    
    MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "vapp_msg_mms_mem_full_event_hdlr mmsEvt->mms_mem_status:%d", mmsEvt->mms_mem_status);
    switch (mmsEvt->mms_mem_status)
    {
        case SRV_MMS_MEM_STATUS_PHONE_COUNT_MAX_REACH:
            {
                if (srv_um_check_ready())
                {
                    vapp_msg_check_show_mem_full_cell(VAPP_MSG_NCENTER_FULL_MMS_PHONE_CELL);
                    mem_full_setting |= VAPP_MSG_FULL_NCENTER_MMS_PHONE;
                }
                else
                {
                    if (!vapp_msg_mem_full_cell_is_previous_show(VAPP_MSG_FULL_NCENTER_MMS_PHONE))
                    {
                        mem_full_setting |= VAPP_MSG_FULL_NCENTER_MMS_PHONE;
                    }
                }
            }
            break;
            
        case SRV_MMS_MEM_STATUS_PHONE_COUNT_NOT_MAX:
            {
                vapp_msg_write_nvram_mem_full_setting_single(VAPP_MSG_FULL_NCENTER_MMS_PHONE, VFX_FALSE, VAPP_MSG_FULL_NCENTER_PREVIOUS_EVT);
                vapp_msg_write_nvram_mem_full_setting_single(VAPP_MSG_FULL_NCENTER_MMS_PHONE, VFX_FALSE, VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
                vapp_msg_close_ncenter_cell(VAPP_MSG_NCENTER_FULL_MMS_PHONE_CELL);
            }
            break;

        case SRV_MMS_MEM_STATUS_CARD_COUNT_MAX_REACH:
            {
                if (srv_um_check_ready())
                {
	                MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "vapp_msg_mms_mem_full_event_hdlr SRV_MMS_MEM_STATUS_CARD_COUNT_MAX_REACH");
                    vapp_msg_check_show_mem_full_cell(VAPP_MSG_NCENTER_FULL_MMS_CARD_CELL);
                    mem_full_setting |= VAPP_MSG_FULL_NCENTER_MMS_CARD;
                }
                else
                {
                    if (!vapp_msg_mem_full_cell_is_previous_show(VAPP_MSG_FULL_NCENTER_MMS_CARD))
                    {
                        mem_full_setting |= VAPP_MSG_FULL_NCENTER_MMS_CARD;
                    }
                }
            }
            break;
            
        case SRV_MMS_MEM_STATUS_CARD_COUNT_NOT_MAX:
            {               
                if (MMI_TRUE == srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))
                {
                    vapp_msg_write_nvram_mem_full_setting_single(VAPP_MSG_FULL_NCENTER_MMS_CARD, VFX_FALSE, VAPP_MSG_FULL_NCENTER_PREVIOUS_EVT);
                }
                vapp_msg_write_nvram_mem_full_setting_single(VAPP_MSG_FULL_NCENTER_MMS_CARD, VFX_FALSE, VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
                vapp_msg_close_ncenter_cell(VAPP_MSG_NCENTER_FULL_MMS_CARD_CELL);
            }
	    break;

        default:
            break;
    }
    
    return MMI_RET_OK;
}
#endif /* __MMI_MMS_IN_UM__ */

#ifdef __MMI_PROV_IN_UM__
extern "C" mmi_ret vapp_msg_prov_mem_full_event_hdlr(mmi_event_struct *evt)
{    
    srv_provbox_evt_notify_struct *provEvt = (srv_provbox_evt_notify_struct *)evt;

    switch (provEvt->type)
    {
        case SRV_PROVBOX_NOTIFY_TYPE_INBOX_FULL:
            {
                if (srv_um_check_ready())
                {
                    vapp_msg_check_show_mem_full_cell(VAPP_MSG_NCENTER_FULL_PRO_CELL);
                }
                if (srv_um_check_ready())
                {
                    if (!vapp_msg_mem_full_cell_is_show(vapp_msg_full_ncenter_msg_cell_to_type(VAPP_MSG_NCENTER_FULL_PRO_CELL)))
                    {
                        vapp_msg_check_show_mem_full_cell(VAPP_MSG_NCENTER_FULL_PRO_CELL);
                    }
                }
                else
                {
                    if (!vapp_msg_mem_full_cell_is_previous_show(VAPP_MSG_FULL_NCENTER_PROV))
                    {
                        mem_full_setting |= VAPP_MSG_FULL_NCENTER_PROV;
                    }
                }
            }
            break;

        case SRV_PROVBOX_NOTIFY_TYPE_NO_FULL:
            {
                vapp_msg_write_nvram_mem_full_setting_single(VAPP_MSG_FULL_NCENTER_PROV, VFX_FALSE, VAPP_MSG_FULL_NCENTER_PREVIOUS_EVT);
                vapp_msg_write_nvram_mem_full_setting_single(VAPP_MSG_FULL_NCENTER_PROV, VFX_FALSE, VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
                vapp_msg_close_ncenter_cell(VAPP_MSG_NCENTER_FULL_PRO_CELL);
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}
#endif /* __MMI_PROV_IN_UM__ */

extern "C" VappMsgNCenterCellMenu vapp_msg_full_ncenter_msg_type_to_cell(VappMsgFullNCenterMsgTypeEnum type)
{
    VappMsgNCenterCellMenu cell = VAPP_MSG_NCENTER_MESSAGE_CELL_BEGIN;

    switch(type)
    {	
        case VAPP_MSG_FULL_NCENTER_SMS_SIM1:
            cell = VAPP_MSG_NCENTER_FULL_SMS_SIM1_CELL;
            break;

    #if (MMI_MAX_SIM_NUM >= 2)
        case VAPP_MSG_FULL_NCENTER_SMS_SIM2:
            cell = VAPP_MSG_NCENTER_FULL_SMS_SIM2_CELL;
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 2  */
            
    #if (MMI_MAX_SIM_NUM >= 3)
        case VAPP_MSG_FULL_NCENTER_SMS_SIM3:
            cell = VAPP_MSG_NCENTER_FULL_SMS_SIM3_CELL;
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 3  */
            
    #if (MMI_MAX_SIM_NUM >= 4)
        case VAPP_MSG_FULL_NCENTER_SMS_SIM4:
            cell = VAPP_MSG_NCENTER_FULL_SMS_SIM4_CELL;
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 4  */
            
        case VAPP_MSG_FULL_NCENTER_SMS_PHONE:
            cell = VAPP_MSG_NCENTER_FULL_SMS_PHONE_CELL;
            break;
    
    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
        case VAPP_MSG_FULL_NCENTER_SMS_CARD:
            cell = VAPP_MSG_NCENTER_FULL_SMS_CARD_CELL;
            break;
    #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */
            
    #ifdef __MMI_MMS_IN_UM__
        case VAPP_MSG_FULL_NCENTER_MMS_PHONE:
            cell = VAPP_MSG_NCENTER_FULL_MMS_PHONE_CELL;
            break;
            
        case VAPP_MSG_FULL_NCENTER_MMS_CARD:
            cell = VAPP_MSG_NCENTER_FULL_MMS_CARD_CELL;
            break;
    #endif /* __MMI_MMS_IN_UM__ */

    #ifdef __MMI_PROV_IN_UM__
        case VAPP_MSG_FULL_NCENTER_PROV:
            cell = VAPP_MSG_NCENTER_FULL_PRO_CELL;
            break;
    #endif /* __MMI_PROV_IN_UM__ */
            
        default:
            break;
    }
    
    return cell;
}

extern "C" VappMsgFullNCenterMsgTypeEnum vapp_msg_full_ncenter_msg_cell_to_type(VappMsgNCenterCellMenu cell)
{
    VappMsgFullNCenterMsgTypeEnum type = VAPP_MSG_FULL_NCENTER_NONE;

    switch(cell)
    {	
        case VAPP_MSG_NCENTER_FULL_SMS_SIM1_CELL:
            type = VAPP_MSG_FULL_NCENTER_SMS_SIM1;
            break;
            
    #if (MMI_MAX_SIM_NUM >= 2)
        case VAPP_MSG_NCENTER_FULL_SMS_SIM2_CELL:
            type = VAPP_MSG_FULL_NCENTER_SMS_SIM2;
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 2  */
            
    #if (MMI_MAX_SIM_NUM >= 3)
            
        case VAPP_MSG_NCENTER_FULL_SMS_SIM3_CELL:
            type = VAPP_MSG_FULL_NCENTER_SMS_SIM3;
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 3  */
            
    #if (MMI_MAX_SIM_NUM >= 4)            
        case VAPP_MSG_NCENTER_FULL_SMS_SIM4_CELL:
            type = VAPP_MSG_FULL_NCENTER_SMS_SIM4;
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 4  */
            
        case VAPP_MSG_NCENTER_FULL_SMS_PHONE_CELL:
            type = VAPP_MSG_FULL_NCENTER_SMS_PHONE;
            break;

    #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
        case VAPP_MSG_NCENTER_FULL_SMS_CARD_CELL:
            type = VAPP_MSG_FULL_NCENTER_SMS_CARD;
            break;
    #endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */
            
    #ifdef __MMI_MMS_IN_UM__
        case VAPP_MSG_NCENTER_FULL_MMS_PHONE_CELL:
            type = VAPP_MSG_FULL_NCENTER_MMS_PHONE;
            break;
            
        case VAPP_MSG_NCENTER_FULL_MMS_CARD_CELL:
            type = VAPP_MSG_FULL_NCENTER_MMS_CARD;
            break;
    #endif /* __MMI_MMS_IN_UM__ */

    #ifdef __MMI_PROV_IN_UM__
            
        case VAPP_MSG_NCENTER_FULL_PRO_CELL:
            type = VAPP_MSG_FULL_NCENTER_PROV;
            break;
    #endif /* __MMI_PROV_IN_UM__ */
            
        default:
            break;
    }
    
    return type;
}


//NVRAM
extern "C" VfxBool vapp_msg_read_nvram_setting(VappMsgNCenterCellMenu type)
{
    VfxBool setting = VFX_FALSE;
    VfxS16 error;
    switch (type)
    {
        case VAPP_MSG_NCENTER_UNREAD_CELL:
            {
                ReadValue(NVRAM_VAPP_MSG_NCENTER_UNREAD_MSG, (void *)&setting, DS_BYTE, &error);
            }
            break;

        case VAPP_MSG_NCENTER_UNSEND_CELL:
            {
                ReadValue(NVRAM_VAPP_MSG_NCENTER_OUTBOX_MSG, (void *)&setting, DS_BYTE, &error);
            }
            break;

        default:
            break;
    }
    
    return setting;    
}

extern "C" void vapp_msg_write_nvram_setting(VappMsgNCenterCellMenu tag, VfxBool setting)
{
    /* Write to NVRAM */
    VfxS16 error;
    switch(tag)
    {
        case VAPP_MSG_NCENTER_UNREAD_CELL:
            WriteValue(NVRAM_VAPP_MSG_NCENTER_UNREAD_MSG, (void *)&setting, DS_BYTE, &error);
            break;

        case VAPP_MSG_NCENTER_UNSEND_CELL:
            WriteValue(NVRAM_VAPP_MSG_NCENTER_OUTBOX_MSG, (void *)&setting, DS_BYTE, &error);
            break;

        default:
            break;
    }
}

extern "C" VfxU32 vapp_msg_read_nvram_mem_full_setting(VappMsgFullNcenterNVRAMEnum tag)
{
    VfxU32 setting = 0;
    VfxS16 error;
    if (VAPP_MSG_FULL_NCENTER_PREVIOUS_EVT == tag)
    {
        ReadValue(NVRAM_VAPP_MSG_NCENTER_MEMORY_FULL_PREVIOUS_EVT, (void *)&setting, DS_BYTE, &error);
    }
    else
    {
        ReadValue(NVRAM_VAPP_MSG_NCENTER_MEMORY_FULL, (void *)&setting, DS_BYTE, &error);
    }
    
    return setting;
}

extern "C" void vapp_msg_write_nvram_mem_full_setting(VfxU8 setting, VappMsgFullNcenterNVRAMEnum tag)
{
    VfxS16 error;
    if (VAPP_MSG_FULL_NCENTER_PREVIOUS_EVT == tag)
    {
        WriteValue(NVRAM_VAPP_MSG_NCENTER_MEMORY_FULL_PREVIOUS_EVT, (void *)&setting, DS_BYTE, &error);
    }
    else
    { 
        WriteValue(NVRAM_VAPP_MSG_NCENTER_MEMORY_FULL, (void *)&setting, DS_BYTE, &error);
    }
}

extern "C" void vapp_msg_write_nvram_mem_full_setting_single(VappMsgFullNCenterMsgTypeEnum singleSetting, VfxBool isOn, VappMsgFullNcenterNVRAMEnum tag)
{
    VfxU32 setting = 0;
    VfxS16 error;
    if (VAPP_MSG_FULL_NCENTER_PREVIOUS_EVT == tag)
    {
        ReadValue(NVRAM_VAPP_MSG_NCENTER_MEMORY_FULL_PREVIOUS_EVT, (void *)&setting, DS_BYTE, &error);
    }
    else
    {
        ReadValue(NVRAM_VAPP_MSG_NCENTER_MEMORY_FULL, (void *)&setting, DS_BYTE, &error);
    }

    if (VFX_TRUE == isOn)
    {
        setting = setting | (VfxU32)singleSetting;
    }
    else
    {
        setting = setting & (~(VfxU32)singleSetting);
    }

    vapp_msg_write_nvram_mem_full_setting(setting, tag);
}

extern "C" MMI_BOOL vapp_msg_update_mem_full_previous_setting(VappMsgFullNCenterMsgTypeEnum singleSetting)
{
    VfxU32 setting = vapp_msg_read_nvram_mem_full_setting(VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
    VfxU32 needSetting = setting & ((VfxU32)singleSetting);
    MMI_BOOL needUpdate = (needSetting == 0) ? MMI_TRUE : MMI_FALSE;
    if (!needUpdate)
        vapp_msg_write_nvram_mem_full_setting_single(singleSetting, VFX_TRUE, VAPP_MSG_FULL_NCENTER_PREVIOUS_EVT);   
    return needUpdate;
}

extern "C" MMI_BOOL vapp_msg_mem_full_cell_is_previous_show(VappMsgFullNCenterMsgTypeEnum singleSetting)
{
    VfxU32 setting = vapp_msg_read_nvram_mem_full_setting(VAPP_MSG_FULL_NCENTER_PREVIOUS_EVT);
    setting = setting & ((VfxU32)singleSetting);
    return (setting != 0) ? MMI_TRUE : MMI_FALSE;
}

extern "C" MMI_BOOL vapp_msg_mem_full_cell_is_show(VappMsgFullNCenterMsgTypeEnum singleSetting)
{
    VfxU32 setting = vapp_msg_read_nvram_mem_full_setting(VAPP_MSG_FULL_NCENTER_DISPLAY_TAG);
    setting = setting & ((VfxU32)singleSetting);
    return (setting != 0) ? MMI_TRUE : MMI_FALSE;
}

/*******************************************************************************************************
* NSS
*******************************************************************************************************/
extern "C" void vapp_msg_nss_set_alert_info_icon(icon_type type, mmi_frm_nmgr_alert_struct& alert_info)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "vapp_msg_show_ncenter_cell type:%d", type);
    alert_info.app_id = VAPP_MSG;
    alert_info.alert_option = MMI_FRM_NMGR_DISABLE_TONE | MMI_FRM_NMGR_DISABLE_VIB;
    alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK;
    alert_info.behavior_mask = FORCE_ICON_ONLY;
    alert_info.scen_id = MMI_SCENARIO_ID_DEFAULT;
    switch(type)
    {
        case ICON_UNREAD:
        {
            alert_info.event_type = MMI_EVENT_NON_TONE;
            alert_info.status_bar_icon_para.icon_id = STATUS_ICON_MESSAGE_UNREAD;
        }
            break;
            
        case ICON_UNSEND:
        {            
            alert_info.event_type = MMI_EVENT_SEND_FAIL_MSG;
            alert_info.status_bar_icon_para.icon_id = STATUS_ICON_MESSAGE_SEND_FAIL;
        }
            break;
            
        case ICON_SENDING:
        {
            alert_info.event_type = MMI_EVENT_SENDING_MSG;
            alert_info.alert_option |= MMI_FRM_NMGR_ICON_ANIMATION;
            alert_info.status_bar_icon_para.icon_id = STATUS_ICON_MESSAGE_SENDING;  
        }
            break;
            
        case ICON_MEMFULL:
        {
            alert_info.event_type = MMI_EVENT_FULL_MSG;
            alert_info.status_bar_icon_para.icon_id = STATUS_ICON_MSG_FULL;
        }
            break;
            
        default:
            MMI_ASSERT(0);
            break;
    }
}

extern "C" void vapp_msg_nss_set_alert_info_unread_text_preview(VfxWString* previewText, mmi_frm_nmgr_alert_struct& alert_info)
{
    alert_info.app_id = VAPP_MSG;
    alert_info.alert_option = 0;
    alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK|MMI_FRM_NMGR_UI_STATUS_BAR_MASK|MMI_FRM_NMGR_UI_POPUP_MASK;
    alert_info.behavior_mask = PREFER_STATUS_BAR;
    alert_info.scen_id = MMI_SCENARIO_ID_INCOMING_MSG;
    alert_info.event_type = MMI_EVENT_UNREAD_MSG;
    alert_info.status_bar_para.image.id = IMG_SI_MESSAGE_UNREAD;
    alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
    alert_info.status_bar_para.image_type = MMI_NMGR_IMG_RES_ID;
    alert_info.status_bar_icon_para.icon_id = STATUS_ICON_MESSAGE_UNREAD;
    alert_info.status_bar_para.display_string = (WCHAR*)previewText->getBuf();
    alert_info.app_proc_para.scrn_group_proc = &vapp_msg_nss_unread_launch;
    alert_info.app_proc_para.user_data = NULL;
    alert_info.app_proc_para.data_size = 0;
    alert_info.popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
    alert_info.popup_para.image_type = MMI_NMGR_IMG_RES_ID;
    alert_info.popup_para.image.id = IMG_SI_MESSAGE_UNREAD;
    alert_info.popup_para.popup_string = (WCHAR*)previewText->getBuf();
    VfxWString button_string;
    button_string.loadFromRes(STR_ID_VAPP_MSG_NSS_VIEW);
    alert_info.popup_para.popup_button_string = (WCHAR*)button_string.getBuf();
}

extern "C" void vapp_msg_nss_set_alert_info_unsend_balloon(VfxWString* previewText, mmi_frm_nmgr_alert_struct& alert_info)
{
    alert_info.app_id = VAPP_MSG;
    alert_info.alert_option = 0;
    alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK;
    alert_info.behavior_mask = FORCE_STATUS_BAR;
    alert_info.scen_id = MMI_SCENARIO_ID_DEFAULT;
    alert_info.event_type = MMI_EVENT_SEND_FAIL_MSG;
    alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_BALLOON_TYPE;
    alert_info.status_bar_para.display_string = (WCHAR*)previewText->getBuf();
    alert_info.status_bar_icon_para.icon_id = STATUS_ICON_MESSAGE_SEND_FAIL;
}

extern "C" void vapp_msg_nss_cancel_alert(icon_type type)
{
    NMGR_HANDLE handle = 0;
    MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "vapp_msg_nss_cancel_alert type:%d", type);
    switch(type)
    {
        case ICON_UNREAD:
            handle = mmi_frm_nmgr_compose_alert_handle(VAPP_MSG, MMI_EVENT_UNREAD_MSG, STATUS_ICON_MESSAGE_UNREAD);
            break;
        case ICON_UNSEND:
            handle = mmi_frm_nmgr_compose_alert_handle(VAPP_MSG, MMI_EVENT_SEND_FAIL_MSG, STATUS_ICON_MESSAGE_SEND_FAIL);
            break;
        case ICON_SENDING:
            handle = mmi_frm_nmgr_compose_alert_handle(VAPP_MSG, MMI_EVENT_SENDING_MSG, STATUS_ICON_MESSAGE_SENDING);
            break;
        case ICON_MEMFULL:
            handle = mmi_frm_nmgr_compose_alert_handle(VAPP_MSG, MMI_EVENT_FULL_MSG, STATUS_ICON_MSG_FULL);
            break; 
        default:
            break;
    }
    mmi_frm_nmgr_alert_cancel_send(handle);
}

extern "C" mmi_ret vapp_msg_nss_unread_launch(mmi_event_struct *param)
{    
    VappMsgLaunchStruct launch_param;
	if(param->evt_id == EVT_ID_NMGR_POPUP_APP_LAUNCH ||
	   param->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH)
	{
		vfx_sys_mem_zero(&launch_param, sizeof(VappMsgLaunchStruct));
		launch_param.mode = VAPP_MSG_LAUNCH_INBOX;
		vapp_msg_launch_with_callback(&launch_param, sizeof(VappMsgLaunchStruct));
	}

    return MMI_RET_OK;
}

/*******************************************************************************************************/

VFX_IMPLEMENT_CLASS("VappMsgPhbDialogPage", VappMsgPhbDialogPage, VfxPage);

VappMsgPhbDialogPage::VappMsgPhbDialogPage(mmi_phb_contact_id id):
    m_id(id), 
    m_subId(0), 
    m_isNeedReset(VFX_TRUE), 
    m_isBlockUpdate(VFX_FALSE), 
    m_list(NULL), 
    m_listMenu(NULL), 
    m_loading(NULL), 
    m_toolbar(NULL), 
    m_isStartSetAllMsgRead(VFX_FALSE), 
    m_isWaitSetAllRead(VFX_TRUE), 
    m_setAllReadIndex(0), 
    m_name(NULL), 
    m_number(NULL), 
    m_clearBtn(NULL), 
    m_msAction(SRV_UM_MARK_SEVERAL_OP_ACTION_NONE), 
    m_msProcessing(NULL), 
    m_msProcessTimer(NULL), 
    m_sim(MMI_SIM1), 
    m_simImg(NULL)
{
    m_boxId.msg_type = SRV_UM_MSG_ALL;
    m_boxId.msg_box_type = (srv_um_msg_box_enum)(SRV_UM_MSG_BOX_INBOX | SRV_UM_MSG_BOX_UNSENT | SRV_UM_MSG_BOX_SENT | SRV_UM_MSG_BOX_DRAFT);
    m_boxId.sim_id = SRV_UM_SIM_ALL;

    vfx_sys_mem_zero(&m_listFilter, sizeof(srv_um_list_filter_struct));
    vfx_sys_mem_zero(&m_thrdId, sizeof(srv_um_thread_id_struct));
}

void VappMsgPhbDialogPage::onInit()
{
    MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "%s", this->getClassInfo()->getClassName());
    MMI_TRACE(TRACE_GROUP_6, TRC_MMI_VAPP_MSG_ON_INIT, this);
    VfxPage::onInit();

    ContactEntry contact(m_id);

    VfxFrame *bg;
    VFX_OBJ_CREATE(bg, VfxFrame, this);
    bg->setSize(getSize().width, VAPP_MSG_PHB_DIALOG_CB_BG_HEIGHT);
    bg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    bg->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_CONTACT_DIALOG_BAR_BG));
    bg->setPos(0, 0);
    bg->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_NONE);

    VfxU32 simImgWidth = 0;
#if (MMI_MAX_SIM_NUM >= 2)
    VFX_OBJ_CREATE(m_simImg, VfxFrame, bg);
    m_simImg->setSize(VAPP_MSG_PHB_DIALOG_CB_SIM_WIDTH, VAPP_MSG_PHB_DIALOG_CB_SIM_HEIGHT);
    m_simImg->setPos(VAPP_MSG_PHB_DIALOG_CB_MARGIN_LEFT, bg->getSize().height / 2 - m_simImg->getSize().height / 2);
    m_simImg->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_NONE, 
            VFX_FRAME_ALIGNER_MODE_SIDE);
    simImgWidth = VAPP_MSG_PHB_DIALOG_CB_SIM_MARGIN + m_simImg->getSize().width;
#endif /* MMI_MAX_SIM_NUM >= 2 */
    
    VfxFontDesc font;
    font.size = VFX_FONT_DESC_VF_SIZE(VAPP_MSG_PHB_DIALOG_CB_NAME_FONT_SIZE);
    VFX_OBJ_CREATE(m_name, VfxTextFrame, bg);
    m_name->setString(contact.getName().getString());
    if (VFX_WSTR_EMPTY == m_name->getString())
    {
        m_name->setString(STR_GLOBAL_UNNAMED);
    }
    m_name->setFont(font);
    m_name->setSize(bg->getSize().width - VAPP_MSG_PHB_DIALOG_CB_MARGIN_LEFT - VAPP_MSG_PHB_DIALOG_CB_NAME_MARGIN_RIGHT - simImgWidth, m_name->getSize().height);
    m_name->setPos(VAPP_MSG_PHB_DIALOG_CB_MARGIN_LEFT + simImgWidth, VAPP_MSG_PHB_DIALOG_CB_MARGIN_UP);
    m_name->setAutoResized(VFX_FALSE);
    m_name->setColor(VFX_COLOR_RES(VAPP_MSG_PHB_DIALOG_CB_NAME_COLOR));
    m_name->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_name->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_SIDE, 
            VFX_FRAME_ALIGNER_MODE_SIDE);

    font.size = VFX_FONT_DESC_VF_SIZE(VAPP_MSG_PHB_DIALOG_CB_NUMBER_FONT_SIZE);
    VFX_OBJ_CREATE(m_number, VfxTextFrame, bg);
    //m_number->setString(contact.getNumberById(m_subId).getString());
    m_number->setFont(font);
    m_number->setSize(bg->getSize().width - VAPP_MSG_PHB_DIALOG_CB_MARGIN_LEFT - VAPP_MSG_PHB_DIALOG_CB_NUMBER_MARGIN_RIGHT - simImgWidth, m_number->getSize().height);
    m_number->setAutoResized(VFX_FALSE);
    m_number->setPos(VAPP_MSG_PHB_DIALOG_CB_MARGIN_LEFT + simImgWidth, VAPP_MSG_PHB_DIALOG_CB_BG_HEIGHT - VAPP_MSG_PHB_DIALOG_CB_MARGIN_DOWN - m_number->getSize().height);
    m_number->setColor(VFX_COLOR_RES(VAPP_MSG_PHB_DIALOG_CB_NUMBER_COLOR));
    m_number->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_number->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_SIDE);
    if (0 < contact.getNumber())
    {
        m_subId = contact.getNextNumber().getSubId();
        m_number->setString(contact.getNumberById(m_subId).getString());
    #if (MMI_MAX_SIM_NUM >= 2)
        /* get preferred sim setting first */
        srv_phb_get_preferred_sim(
                (U16 *)contact.getNumberById(m_subId).getBuf(), 
                m_id, 
                SRV_PHB_NUMBER_OP_TYPE_MESSAGE, 
                &m_sim);
        if (MMI_SIM_NONE == m_sim)
        {
            /* first entry, check sim inserted status */
            VfxU32 i = 0;
            mmi_sim_enum sim = MMI_SIM1;
            for (i = 0 ; i < MMI_MAX_SIM_NUM ; i++, sim = (mmi_sim_enum)(sim << 1))
            {
                if (srv_sim_ctrl_is_inserted(sim))
                {
                    break;
                }
            }
            if (MMI_MAX_SIM_NUM == i)
            {
                /* not find, make sim1 as default sim */
                m_sim = MMI_SIM1;
            }
            else
            {
                /* find the inserted card and make as default sim */
                m_sim = sim;
            }
        }
    #else /* MMI_MAX_SIM_NUM >= 2 */
        m_sim = MMI_SIM_NONE;
    #endif /* MMI_MAX_SIM_NUM == 1 */
        /* transfer to thread id */
        srv_um_tsfr_address_to_thread_id(
                SRV_UM_ADDR_PHONE_NUMBER, 
                (U16 *)contact.getNumberById(m_subId).getBuf(), 
                switchSimToUmSimEnum(m_sim), 
                &m_thrdId);
    }
    else
    {
        m_number->setString(VFX_WSTR_EMPTY);
    }

#if (MMI_MAX_SIM_NUM >= 2)
    /* set sim image */
    m_simImg->setImgContent(VfxImageSrc(switchSimToImgId(m_sim)));
#endif /* MMI_MAX_SIM_NUM >= 2 */

    VFX_OBJ_CREATE(m_clearBtn, VcpButton, bg);
    m_clearBtn->setText(STR_GLOBAL_CLEAR);
    m_clearBtn->setSize(VAPP_MSG_PHB_DIALOG_CB_BTN_WIDTH, VAPP_MSG_PHB_DIALOG_CB_BTN_HEIGHT);
    m_clearBtn->setPos(bg->getSize().width - m_clearBtn->getSize().width - VAPP_MSG_PHB_DIALOG_CB_MARGIN_RIGHT, VAPP_MSG_PHB_DIALOG_CB_MARGIN_UP);
    m_clearBtn->setIsDisabled(VFX_TRUE); /* default set as disable */
    m_clearBtn->m_signalClicked.connect(this, &VappMsgPhbDialogPage::onClearBtnClicked);
    m_clearBtn->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_NONE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE);

    VfxFrame *seperator;
    VFX_OBJ_CREATE(seperator, VfxFrame, bg);
    seperator->setPos(0, bg->getSize().height - 2);
    seperator->setSize(bg->getSize().width, 2);
    seperator->setImgContent(VfxImageSrc(IMG_COSMOS_SEPARATOR_LINE));
    seperator->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    seperator->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_NONE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE_EX(m_list, VappMessageList, this, (m_boxId.msg_type, m_boxId.msg_box_type, m_boxId.sim_id));
    m_list->m_signalListUpdated.connect(this, &VappMsgPhbDialogPage::onListUpdate);
    m_list->m_signalOperationResult.connect(this, &VappMsgPhbDialogPage::onMsOpResult);
    if (0 < contact.getNumber())
    {
        /* set first number to the default thread id */
        m_list->setThreadId(m_thrdId);
    }

    VFX_OBJ_CREATE_EX(m_listMenu, VappMsgDialogListCp, this, (VcpVarHeightMenu::LAYOUT_REVERSE));
    m_listMenu->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_listMenu->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_PHB_DIALOG_LIST_BG));
    m_listMenu->setSize(getSize().width, getSize().height - bg->getSize().height);
    m_listMenu->setPos(0, bg->getSize().height);
    m_listMenu->setHasAnimation(VFX_TRUE);
    m_listMenu->setHasHighlight(VFX_FALSE);
    m_listMenu->setProvider(this);
    m_listMenu->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE, 
                    VFX_FRAME_ALIGNER_MODE_SIDE);
    
    VfxS32 count = m_list->getCount();
    VfxS32 countX = 0;
    if (-1 == count)
    {
        countX = 0;
    }
    else
    {
        countX = count;
    }
    m_listMenu->setCount(countX);
    m_listMenu->setDefaultHeight(VappMsgDialogCell::BUBBLE_MIN_HEIGHT);


    /* more than one */
    VFX_OBJ_CREATE(m_toolbar, VcpToolBar, this);
#if (MMI_MAX_SIM_NUM >= 2)
    m_toolbar->addItem(VAPP_MSG_PHB_DIALOG_TB_SWITCH_SIM, STR_ID_VAPP_MSG_SWITCH_SIM, VCP_IMG_TOOL_BAR_COMMON_ITEM_SEARCH);
#endif /* MMI_MAX_SIM_NUM >= 2 */
    m_toolbar->addItem(VAPP_MSG_PHB_DIALOG_TB_SWITCH_NUMBER, STR_ID_VAPP_MSG_SWITCH_NUMBER, VCP_IMG_TOOL_BAR_COMMON_ITEM_SEARCH);
    m_toolbar->m_signalButtonTap.connect(this, &VappMsgPhbDialogPage::onToolbarClick);
    setBottomBar(m_toolbar);

    /* loading */
    VFX_OBJ_CREATE(m_loading, VcpActivityIndicator, this);
    m_loading->setAutoAnimate(VFX_TRUE);
    m_loading->setHiddenWhenStopped(VFX_TRUE);
    m_loading->setPos(getSize().width/2 - m_loading->getSize().width/2, getSize().height/2 - m_loading->getSize().height/2);
    m_loading->setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_MID, 
                        VFX_FRAME_ALIGNER_MODE_MID, 
                        VFX_FRAME_ALIGNER_MODE_MID, 
                        VFX_FRAME_ALIGNER_MODE_MID);

    /* mark several processing */
    VFX_OBJ_CREATE(m_msProcessing, VcpIndicatorPopup, this);
    m_msProcessing->setText(STR_ID_VAPP_MSG_CLEARING);
    m_msProcessing->setInfoType(VCP_INDICATOR_POPUP_STYLE_PROGRESS_WITH_CANCEL_BUTTON);
    m_msProcessing->m_signalCanceled.connect(this, &VappMsgPhbDialogPage::onMsActionCancelled);

    /* update timer */
    VFX_OBJ_CREATE(m_msProcessTimer, VfxTimer, this);
    m_msProcessTimer->setDuration(VAPP_MSG_MS_TIMER_PERIOD);
    m_msProcessTimer->m_signalTick.connect(this, &VappMsgPhbDialogPage::onMsProgressTimeout);

    relayout();
}

void VappMsgPhbDialogPage::onUpdate()
{
    MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "%s", this->getClassInfo()->getClassName());
    MMI_TRACE(TRACE_GROUP_6, TRC_MMI_VAPP_MSG_ON_UPDATE, this);
    VfxPage::onUpdate();

    if (VFX_FALSE == isActive() || 
        VFX_FALSE == getApp()->isActive() ||
        VFX_TRUE == m_isBlockUpdate)
    {
        return;
    }

    /* check list */
    ContactEntry contact(m_id);
    if (0 == contact.getNumber())
    {
        stopLoading();
        relayout();
        return;
    }

    if (VFX_FALSE == m_list->checkMsgList() ||
        VFX_FALSE == getAllMsgRead())
    {
        showLoading();
    }
    else
    {
        stopLoading();
        if (0 == m_list->getCount())
        {
            m_listMenu->reset();
        }
        else
        {
            if (VFX_TRUE == m_isNeedReset)
            {
                m_listMenu->reset();
            }
            else
            {
                m_listMenu->updateLayout();
            }
            m_isNeedReset = VFX_FALSE;
        }
        /* relayout the other component */
        relayout();
    }
}

void VappMsgPhbDialogPage::onEntered()
{
    VfxPage::onEntered();

    m_listMenu->setReadyForAnimation();

    checkUpdate();
}

mmi_ret VappMsgPhbDialogPage::onProc(mmi_event_struct * evt)
{
    if (EVT_ID_PHB_UPD_CONTACT == evt->evt_id)
    {
        ContactEntry contact(m_id);

        /* reset the m_subId */
        if (0 < contact.getNumber())
        {
            m_subId = contact.getNextNumber().getSubId();
            srv_um_tsfr_address_to_thread_id(
                    SRV_UM_ADDR_PHONE_NUMBER, 
                    (U16 *)contact.getNumberById(m_subId).getBuf(), 
                    switchSimToUmSimEnum(m_sim), 
                    &m_thrdId);
            m_list->setThreadId(m_thrdId);
            m_isWaitSetAllRead = VFX_TRUE;
        }
        else
        {
            /* reset thread id */
            m_thrdId.type = SRV_UM_HASH_NONE;
            m_thrdId.value = 0;
            m_list->setThreadId(m_thrdId);
            m_isWaitSetAllRead = VFX_FALSE;
        }
        m_listMenu->reset();
        checkUpdate();
        relayout();
    }

    return MMI_RET_OK;
}

VfxBool VappMsgPhbDialogPage::getItemInfo(VfxU32 index,VfxU32 & msgId,srv_um_msg_enum & msgType)
{
    if (VFX_FALSE == m_list->checkMsgList())
    {
        return VFX_FALSE;
    }
    msgId = m_list->getMsgId(index);
    msgType = m_list->getMsgType(index);

    return VFX_TRUE;
}

VfxU32 VappMsgPhbDialogPage::getCount()
{
    ContactEntry contact(m_id);
    if (0 == contact.getNumber())
    {
        /* no number, return 0 */
        return 0;
    }

    VfxU32 count = 0;
    if (VFX_FALSE == m_list->checkMsgList())
    {
        count = 0;
    }
    else
    {
        count = m_list->getCount();
    }

    return count;
}

VfxBool VappMsgPhbDialogPage::getMarkStatus(VfxU32 index)
{
    return VFX_FALSE;
}

VfxBool VappMsgPhbDialogPage::getCellIsDisabled(VfxU32 index)
{
    return VFX_FALSE;
}

VfxBool VappMsgPhbDialogPage::getLoadingStatus()
{
    ContactEntry contact(m_id);

    if (0 == contact.getNumber())
    {
        /* no contact, no loading anymore */
        return MMI_FALSE;
    }
    if (MMI_FALSE == m_list->checkMsgList())
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}

void VappMsgPhbDialogPage::showLoading()
{
    m_loading->start();
    m_listMenu->setIsUnhittable(VFX_TRUE);
    if (NULL != m_toolbar)
    {
        m_toolbar->setIsUnhittable(VFX_TRUE);
    }
    m_clearBtn->setIsUnhittable(VFX_TRUE);
}

void VappMsgPhbDialogPage::stopLoading()
{
    m_loading->stop();
    m_listMenu->setIsUnhittable(VFX_FALSE);
    if (NULL != m_toolbar)
    {
        m_toolbar->setIsUnhittable(VFX_FALSE);
    }
    m_clearBtn->setIsUnhittable(VFX_FALSE);
}

void VappMsgPhbDialogPage::relayout()
{
    ContactEntry contact(m_id);
    if (NULL != m_simImg)
    {
        m_simImg->setImgContent(VfxImageSrc(switchSimToImgId(m_sim)));
    }

    if (NULL != m_name)
    {
        /* update the name text */
        m_name->setString(contact.getName().getString());
        if (VFX_WSTR_EMPTY == m_name->getString())
        {
            m_name->setString(STR_GLOBAL_UNNAMED);
        }
        VfxU32 simImgWidth = 0;
    #if (MMI_MAX_SIM_NUM >= 2)
        simImgWidth = VAPP_MSG_PHB_DIALOG_CB_SIM_MARGIN + m_simImg->getSize().width;
    #endif /* MMI_MAX_SIM_NUM >= 2 */
        if (0 == contact.getNumber())
        {
            /* reset as centeral */
            m_name->setPos(m_name->getPos().x, m_name->getParentFrame()->getSize().height / 2 - m_name->getSize().height / 2);
        }
        else
        {
            m_name->setPos(VAPP_MSG_PHB_DIALOG_CB_MARGIN_LEFT + simImgWidth, VAPP_MSG_PHB_DIALOG_CB_MARGIN_UP);
        }
    }

    if (NULL != m_number)
    {
        /* update the number text */
        m_number->setString(contact.getNumberById(m_subId).getString());
        if (0 == contact.getNumber())
        {
            /* set hidden */
            m_number->setHidden(VFX_TRUE);
        }
        else
        {
            m_number->setHidden(VFX_FALSE);
        }
    }

    if (NULL != m_clearBtn)
    {
        if (0 < contact.getNumber() && 
            0 < m_list->getCount())
        {
            m_clearBtn->setIsDisabled(VFX_FALSE);
        }
        else
        {
            m_clearBtn->setIsDisabled(VFX_TRUE);
        }
    }

    if (NULL != m_toolbar)
    {
        if (1 < contact.getNumber())
        {
        #if (MMI_MAX_SIM_NUM == 1)
            m_toolbar->setIsUnhittable(VFX_FALSE);
            if (VFX_FALSE == isBarOn(VFX_PAGE_BAR_LOCATION_BOTTOM))
            {
                // turn on it
                toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_TRUE);
            }
        #else /* MMI_MAX_SIM_NUM == 1 */
            m_toolbar->addItem(VAPP_MSG_PHB_DIALOG_TB_SWITCH_NUMBER, STR_ID_VAPP_MSG_SWITCH_NUMBER, VCP_IMG_TOOL_BAR_COMMON_ITEM_SEARCH);
        #endif /* MMI_MAX_SIM_NUM >= 2 */
        }
        else
        {
        #if (MMI_MAX_SIM_NUM == 1)
            m_toolbar->setIsUnhittable(VFX_TRUE);
            if (VFX_TRUE == isBarOn(VFX_PAGE_BAR_LOCATION_BOTTOM))
            {
                // turn off it
                toggleBar(VFX_PAGE_BAR_LOCATION_BOTTOM, VFX_FALSE);
            }
        #else /* MMI_MAX_SIM_NUM == 1 */
            m_toolbar->removeItem(VAPP_MSG_PHB_DIALOG_TB_SWITCH_NUMBER);
        #endif /* MMI_MAX_SIM_NUM >= 2 */
        }

    #if (MMI_MAX_SIM_NUM >= 2)
        if (0 < contact.getNumber())
        {
            m_toolbar->setDisableItem(VAPP_MSG_PHB_DIALOG_TB_SWITCH_SIM, VFX_FALSE);
        }
        else
        {
            m_toolbar->setDisableItem(VAPP_MSG_PHB_DIALOG_TB_SWITCH_SIM, VFX_TRUE);
        }
    #endif /* MMI_MAX_SIM_NUM >= 2 */
    }
}

VfxBool VappMsgPhbDialogPage::getAllMsgRead()
{
    ContactEntry contact(m_id);
    if (0 == contact.getNumber())
    {
        /* no number, return */
        return VFX_TRUE;
    }

    setAllMsgRead();

    if (VFX_TRUE == m_isWaitSetAllRead)
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}

void VappMsgPhbDialogPage::setAllMsgRead()
{
    if (VFX_FALSE == m_list->checkMsgList() ||
        VFX_FALSE == m_isWaitSetAllRead ||
        VFX_TRUE == m_isStartSetAllMsgRead)
    {
        return;
    }

    m_isStartSetAllMsgRead = VFX_TRUE;
    m_setAllReadIndex = 0;
    setAllMsgReadInt();
}

void VappMsgPhbDialogPage::setAllMsgReadInt()
{
    if (VFX_FALSE == m_list->checkMsgList())
    {
        /* list disappear, return */
        m_isStartSetAllMsgRead = VFX_FALSE;
        m_setAllReadIndex = 0;
        m_isWaitSetAllRead = VFX_TRUE;
        return;
    }

    VfxU32 i = m_setAllReadIndex;
    for (i = m_setAllReadIndex ; i < (VfxU32)m_list->getCount() ; i++)
    {
        if (VFX_TRUE == setMsgRead(m_list->getMsgId(i), m_list->getMsgType(i)))
        {
            break;
        }
    }

    /* set the last handling index */
    m_setAllReadIndex = i;
    /* complete, set non-wait */
    if (m_setAllReadIndex >= (VfxU32)m_list->getCount())
    {
        m_isWaitSetAllRead = VFX_FALSE;
        m_setAllReadIndex = 0;
        m_isStartSetAllMsgRead = VFX_FALSE;
        checkUpdate();
    }
}

VfxBool VappMsgPhbDialogPage::setMsgRead(VfxU32 msgId, srv_um_msg_enum msgType)
{
    VfxBool isWaitCb = VFX_FALSE;
    switch (msgType)
    {
        case SRV_UM_MSG_SMS:
            if (SRV_SMS_STATUS_UNREAD & srv_sms_get_msg_status(msgId))
            {
                /* unread, set as read */
                srv_sms_change_msg_status(
                        msgId, 
                        SRV_SMS_STATUS_READ, 
                        &VappMsgPhbDialogPage::setSmsReadCb, 
                        (void *)getObjHandle());
                isWaitCb = VFX_TRUE;
            }
            break;

    #ifdef __MMI_MMS_IN_UM__
        case SRV_UM_MSG_MMS:
            if (MMI_FALSE == srv_mms_mma_get_mms_read_status(msgId))
            {
                /* unrad, set as read */
                U8 result = MMA_RESULT_OK;
                srv_mms_set_read_status_and_refresh_list(msgId, MMI_TRUE, &result);
            }
            break;
    #endif /* __MMI_MMS_IN_UM__ */

    #ifdef __MMI_PUSH_IN_UM__
        case SRV_UM_MSG_WAP_PUSH:
            if (MMI_FALSE == srv_wap_push_msg_read_status(msgId))
            {
                /* unrad, set as read */
                srv_wap_push_update_all_service_msg_req(&VappMsgPhbDialogPage::setPushReadCb, (void *)getObjHandle());
                isWaitCb = VFX_TRUE;
            }
            break;
    #endif /* __MMI_PUSH_IN_UM__ */

    #ifdef __MMI_PROV_IN_UM__
        case SRV_UM_MSG_PROV:
            if (SRV_PROVBOX_MSG_READ_STATUS_UNREAD == srv_provbox_get_msg_status(msgId))
            {
                /* unrad, set as read */
                srv_provbox_main_um_set_msg_state(
                        msgId, 
                        SRV_PROVBOX_MSG_READ_STATUS_READ, 
                        &VappMsgPhbDialogPage::setProvReadCb, 
                        (void *)getObjHandle());
                isWaitCb = VFX_TRUE;
            }
            break;
    #endif /* __MMI_PROV_IN_UM__ */

        default:
            break;
    }

    return isWaitCb;
}

void VappMsgPhbDialogPage::setSmsReadCb(srv_sms_callback_struct * cbPara)
{
    VappMsgPhbDialogPage *self = (VappMsgPhbDialogPage *)VfxObject::handleToObject((VfxObjHandle)cbPara->user_data);

    if (self)
    {
        if (self->isKindOf(VFX_OBJ_CLASS_INFO(VappMsgPhbDialogPage)))
        {
            if (VFX_TRUE == self->m_isWaitSetAllRead)
            {
                /* success, increase one */
                if (MMI_TRUE == cbPara->result)
                {
                    self->m_setAllReadIndex++;
                }
                vfxPostInvoke0(self, &VappMsgPhbDialogPage::setAllMsgReadInt);
            }
        }
    }
}

#ifdef __MMI_PUSH_IN_UM__
void VappMsgPhbDialogPage::setPushReadCb(srv_wap_push_msg_read_status_enum result,void * user_data)
{   
    VappMsgPhbDialogPage *self = (VappMsgPhbDialogPage *)VfxObject::handleToObject((VfxObjHandle)user_data);

    if (self)
    {
        if (self->isKindOf(VFX_OBJ_CLASS_INFO(VappMsgPhbDialogPage)))
        {
            if (VFX_TRUE == self->m_isWaitSetAllRead)
            {
                /* success, increase one */
                if (SRV_WAP_PUSH_STATUS_FAIL != result)
                {
                    self->m_setAllReadIndex++;
                }
                vfxPostInvoke0(self, &VappMsgPhbDialogPage::setAllMsgReadInt);
            }
        }
    }
}
#endif /* __MMI_PUSH_IN_UM__ */

#ifdef __MMI_PROV_IN_UM__
void VappMsgPhbDialogPage::setProvReadCb(srv_provbox_result_enum result, void * cbPara)
{
    VappMsgPhbDialogPage *self = (VappMsgPhbDialogPage *)VfxObject::handleToObject((VfxObjHandle)cbPara);

    if (self)
    {
        if (self->isKindOf(VFX_OBJ_CLASS_INFO(VappMsgPhbDialogPage)))
        {
            if (VFX_TRUE == self->m_isWaitSetAllRead)
            {
                /* success, increase one */
                if (MMI_TRUE == result)
                {
                    self->m_setAllReadIndex++;
                }
                vfxPostInvoke0(self, &VappMsgPhbDialogPage::setAllMsgReadInt);
            }
        }
    }
}
#endif /* __MMI_PROV_IN_UM__ */

srv_um_sim_enum VappMsgPhbDialogPage::switchSimToUmSimEnum(mmi_sim_enum sim) const
{
    srv_um_sim_enum umSim = SRV_UM_SIM_UNCLASSIFIED;

#if (MMI_MAX_SIM_NUM >= 2)
    switch (sim)
    {
        case MMI_SIM_NONE:
            umSim = SRV_UM_SIM_UNCLASSIFIED;
            break;

        case MMI_SIM1:
            umSim = SRV_UM_SIM_GSM_SIM1;
            break;

        case MMI_SIM2:
            umSim = SRV_UM_SIM_GSM_SIM2;
            break;

        case MMI_SIM3:
            umSim = SRV_UM_SIM_GSM_SIM3;
            break;

        case MMI_SIM4:
            umSim = SRV_UM_SIM_GSM_SIM4;
            break;

        default:
            break;
    }
#endif /* MMI_MAX_SIM_NUM */
    return umSim;
}

VfxU32 VappMsgPhbDialogPage::switchSimToImgId(mmi_sim_enum sim) const
{
    VfxU32 imgId = IMG_COSMOS_SIM1;

    switch (sim)
    {
        case MMI_SIM2:
            imgId = IMG_COSMOS_SIM2;
            break;

        case MMI_SIM3:
            imgId = IMG_COSMOS_SIM3;
            break;

        case MMI_SIM4:
            imgId = IMG_COSMOS_SIM4;
            break;

        default:
            imgId = IMG_COSMOS_SIM1;
            break;
    }

    return imgId;
}

void VappMsgPhbDialogPage::onListUpdate(VfxObject * obj)
{
    m_isNeedReset = VFX_TRUE;
    /* update list, need to re-check all message if read */
    m_isWaitSetAllRead = VFX_TRUE;

    /*VfxS32 count = m_list->getCount();
    VfxS32 countX = 0;
    if (-1 == count)
    {
        countX = 0;
    }
    else
    {
        countX = count;
    }
    m_listMenu->setCount(countX);
    m_listMenu->setDefaultHeight(VappMsgDialogCell::BUBBLE_MIN_HEIGHT);*/

    checkUpdate();
}

void VappMsgPhbDialogPage::onMsOpResult(VfxObject * obj,VfxU32 success,VfxU32 fail,VfxS32 error)
{
    VFX_ASSERT(NULL != m_list);

    /* close processing */
    m_msProcessing->setProgress(0.0f);
    m_msProcessing->hide(VFX_TRUE);
    m_msProcessTimer->stop();
    stopLoading();
    m_isBlockUpdate = VFX_FALSE;

    m_isNeedReset = VFX_TRUE;

    VcpConfirmPopup *result;
    if (0 != fail || SRV_UM_RESULT_OK != error)
    {
        VFX_OBJ_CREATE(result, VcpConfirmPopup, this);
        result->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        result->setInfoType(VCP_POPUP_TYPE_FAILURE);
        result->setText(STR_ID_VAPP_MSG_FAIL_TO_CLEAR);
        result->show(VFX_TRUE);
    }
    //TODO: Need VcpVarHeightMenu does not need clear all cell, it should choose the "necessary cell" to delete
    m_msAction = SRV_UM_MARK_SEVERAL_OP_ACTION_NONE;
    checkUpdate();
}

void VappMsgPhbDialogPage::onToolbarClick(VfxObject * obj,VfxId id)
{
    /* show all number */
    ContactEntry contact(m_id);

    switch (id)
    {
        case VAPP_MSG_PHB_DIALOG_TB_SWITCH_NUMBER:
            if (2 == contact.getNumber())
            {
                /* switch to another directly, and show balloon */
                VfxU32 i = 0;
                VfxU32 subId = 0;
                for (i = 0 ; i < 2 ; i++)
                {
                    subId = contact.getNextNumber().getSubId();
                    /* find difference, record and break */
                    if (subId != m_subId)
                    {
                        break;
                    }
                }
                onNumberSelectorClicked(NULL, subId);
                /* display a ballon to notify end user */
                VfxWString info;
                info.loadFromRes(STR_ID_VAPP_MSG_SWITCH_TO);
                info += VFX_WSTR_MEM(contact.getNumberById(m_subId).getBuf());
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, info);
            }
            else if (2 < contact.getNumber())
            {
                VcpCommandPopup *numberSelector;
                VFX_OBJ_CREATE(numberSelector, VcpCommandPopup, this);
                numberSelector->setText(STR_ID_VAPP_MSG_SELECT_NUMBER);
                /* use service's enum to let as VfxId */
                VfxU32 i = 0;
                VfxU32 count = 0;
                count = contact.getNumber();
                for (i = 0 ; i < count ; i++)
                {
                    VfxU32 subId = 0;
                    subId = contact.getNextNumber().getSubId();
                    if (subId != m_subId)
                    {
                        numberSelector->addItem(subId, VFX_WSTR_MEM(contact.getNumberById(subId).getBuf()), VCP_POPUP_BUTTON_TYPE_NORMAL);
                    }
                }
                numberSelector->addItem(0xFF, STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_CANCEL);
                numberSelector->m_signalButtonClicked.connect(this, &VappMsgPhbDialogPage::onNumberSelectorClicked);
                numberSelector->show(VFX_TRUE);
            }
            break;

    #if (MMI_MAX_SIM_NUM >= 2)
        case VAPP_MSG_PHB_DIALOG_TB_SWITCH_SIM:
        {
        #if (MMI_MAX_SIM_NUM == 2)
            /* switch to another directly */
            VfxId tmpId = MMI_SIM1;
            if (MMI_SIM1 == m_sim)
            {
                tmpId = MMI_SIM2;
            }
            else if (MMI_SIM2 == m_sim)
            {
                tmpId = MMI_SIM1;
            }
            else
            {
                VFX_ASSERT(0);
            }
            onSimSelectorClicked(NULL, tmpId);
            /* display a ballon to notify end user */
            VfxWString info;
            info.loadFromRes(STR_ID_VAPP_MSG_SWITCH_TO);
            info += vapp_sim_settings_get_sim_name_with_sim_id(m_sim);
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, info);
        #else /* MMI_MAX_SIM_NUM == 2 */
            VcpCommandPopup *numberSelector;
            VFX_OBJ_CREATE(numberSelector, VcpCommandPopup, this);
            numberSelector->setText(STR_ID_VAPP_MSG_SELECT_SIM);
            VfxU32 i = 0;
            mmi_sim_enum sim = MMI_SIM1;
            for (i = 0 ; i < MMI_MAX_SIM_NUM ; i++, sim = (mmi_sim_enum)(sim << 1))
            {
                if (sim != m_sim)
                {
                    numberSelector->addItem((VfxId)sim, vapp_sim_settings_get_sim_name_with_sim_id(sim), VCP_POPUP_BUTTON_TYPE_NORMAL);
                }
            }
            numberSelector->addItem(MMI_SIM_END_OF_ENUM, STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_CANCEL);
            numberSelector->m_signalButtonClicked.connect(this, &VappMsgPhbDialogPage::onSimSelectorClicked);
            numberSelector->show(VFX_TRUE);
        #endif /* MMI_MAX_SIM_NUM >= 3 */
        }
            break;
    #endif /* MMI_MAX_SIM_NUM >= 2 */

        default:
            break;
    }
    
    
}

void VappMsgPhbDialogPage::onNumberSelectorClicked(VfxObject * obj,VfxId id)
{
    if (0xFF == id ||
        m_subId == id ||
        VCP_POPUP_BUTTON_NO_PRESSED == id)
    {
        return;
    }

    ContactEntry contact(m_id);
    srv_um_thread_id_struct thrdId;
    vfx_sys_mem_zero(&thrdId, sizeof(srv_um_thread_id_struct));
    m_subId = id;
    srv_um_tsfr_address_to_thread_id(
            SRV_UM_ADDR_PHONE_NUMBER, 
            (U16 *)contact.getNumberById(m_subId).getBuf(), 
            switchSimToUmSimEnum(m_sim), 
            &thrdId);

    m_list->setThreadId(thrdId);
    m_isWaitSetAllRead = VFX_TRUE;
    checkUpdate();
    relayout();
}

#if (MMI_MAX_SIM_NUM >= 2)
void VappMsgPhbDialogPage::onSimSelectorClicked(VfxObject * obj,VfxId id)
{
    if (MMI_SIM_END_OF_ENUM == id ||
        m_sim == id ||
        VCP_POPUP_BUTTON_NO_PRESSED == id)
    {
        return;
    }

    ContactEntry contact(m_id);
    srv_um_thread_id_struct thrdId;
    vfx_sys_mem_zero(&thrdId, sizeof(srv_um_thread_id_struct));
    m_sim = (mmi_sim_enum)id;
    srv_um_tsfr_address_to_thread_id(
            SRV_UM_ADDR_PHONE_NUMBER, 
            (U16 *)contact.getNumberById(m_subId).getBuf(), 
            switchSimToUmSimEnum(m_sim), 
            &thrdId);

    m_list->setThreadId(thrdId);
    m_isWaitSetAllRead = VFX_TRUE;
    checkUpdate();
    relayout();
}
#endif /* MMI_MAX_SIM_NUM >= 2 */

void VappMsgPhbDialogPage::onClearBtnClicked(VfxObject * obj,VfxId id)
{
    /* display a confirm */
    VcpConfirmPopup *confirm;
    VFX_OBJ_CREATE(confirm, VcpConfirmPopup, this);
    confirm->setText(STR_ID_VAPP_MSG_CLEAR_ALL_MSGS);
    confirm->setInfoType(VCP_POPUP_TYPE_WARNING);
    confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    confirm->setCustomButton(
                STR_GLOBAL_CLEAR, 
                STR_GLOBAL_CANCEL, 
                VCP_POPUP_BUTTON_TYPE_WARNING, 
                VCP_POPUP_BUTTON_TYPE_CANCEL);
    confirm->m_signalButtonClicked.connect(this, &VappMsgPhbDialogPage::onClearAllClicked);
    confirm->show(VFX_TRUE);
}

void VappMsgPhbDialogPage::onClearAllClicked(VfxObject * obj,VfxId id)
{
    VFX_ASSERT(NULL != m_list);
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_YES:
            /* show processing */
            m_msProcessing->setProgress(0.0f);
            m_msProcessing->show(VFX_TRUE);
            m_msAction = SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE;
            m_msProcessTimer->start();
            m_list->setMarkAll(VFX_TRUE);
            m_list->deleteMarked();
            break;

        default:
            break;
    }
}

void VappMsgPhbDialogPage::onMsActionCancelled(VfxObject * obj,VfxFloat process)
{
    if (SRV_UM_MARK_SEVERAL_OP_ACTION_NONE == m_msAction)
    {
        return;
    }

    m_list->cancelMsAction();
    m_msProcessing->hide(VFX_TRUE);
    m_msProcessTimer->stop();
    showLoading();
    m_isBlockUpdate = VFX_TRUE;
}

void VappMsgPhbDialogPage::onMsProgressTimeout(VfxTimer * timer)
{
    if (SRV_UM_MARK_SEVERAL_OP_ACTION_NONE != m_msAction)
    {
        // update the process screen
        VfxS32 finishNum, totalNum;
        finishNum = totalNum = 0;
        m_list->getMsActionDuriation(finishNum, totalNum);
        // update it
        m_msProcessing->setProgress((VfxFloat)finishNum/(VfxFloat)totalNum);
    }
    else
    {
        m_msProcessTimer->stop();
    }
}


/* only use for setting fw */
extern "C" void vapp_msg_setting_fw_launch(VfxMainScr *mainScr)
{
    /* not ready */
    if (MMI_FALSE == srv_um_check_ready())
    {
        /* display a error popup */
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_GENERAL,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR*)GetString(STR_ID_VAPP_MSG_NOT_READY));
        return;        
    }

    VappMsgSettingPage *settingPage;
    VFX_OBJ_CREATE_EX(settingPage, VappMsgSettingPage, mainScr, (VFX_FALSE));

    mainScr->pushPage(VFX_ID_NULL, settingPage);
}
