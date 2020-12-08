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
 *  vapp_phb_info.cpp
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "mmi_rp_vapp_contact_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_srv_venus_component_button_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_vapp_callset_def.h"
#include "mmi_rp_app_usbsrv_def.h"
#include "FileMgrSrvGProt.h"
#include "vapp_uc_gprot.h"

#include "vapp_phb_info.h"
#include "vapp_phb_copy_delete.h"
#include "vapp_phb_cui.h"
#include "vapp_phb_app.h"
#include "vapp_clog_ui.h"
#include "vapp_dialer_cui.h"
#include "vapp_contact_storage.h"
#include "vapp_contact_vcard.h"
#include "vapp_msg_gprot.h"
#include "vapp_phb_gprot.h"
#include "vcui_phb_gprot.h"
#ifdef __MMI_SMS_COMPOSER__
#include "vcui_sms_composer_gprot.h"
#endif

#ifdef __MMI_SNS_CONTACTS__
#include "../../Sns/vapp_sns_main.h"
#include "vapp_sns_gprot.h"
#include "vcui_sns_gprot.h"
#include "vapp_sns_settings_gprot.h"
#include "mmi_rp_vapp_sns_def.h"
#include "mmi_rp_srv_sns_def.h"
#endif /* __MMI_SNS_CONTACTS__ */

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
#include "mmi_rp_app_usbsrv_def.h"
#endif

#include "vapp_cal_add_birthday_gprot.h"

#ifdef __MMI_OPP_SUPPORT__
#include "vapp_bt_send_gprot.h"
#endif

#include "vapp_uc_gprot.h"
#include "vapp_sim_setting_gprot.h"

#ifdef __MMI_USB_SUPPORT__
#include "vapp_usb_gprot.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __MMI_SNS_CONTACTS__
#include "SnsSrvGprot.h"
#endif

#include "GeneralSettingSrvGprot.h"

#ifdef __MMI_EMAIL__
#include "EmailAppGprot.h"
#endif

#include "SimCtrlSrvGprot.h"

#include "NwUsabSrvGprot.h"

#include "ModeSwitchSrvGprot.h"

#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGprot.h"
#endif

#include "FileMgrSrvGProt.h"

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Class VappPhbViewerScr
 *****************************************************************************/
VappPhbViewerScr::VappPhbViewerScr(mmi_phb_contact_id id): m_id(id)
{
    VFX_ASSERT(ContactEntry::isValid(id));
    setAppContextShareForVrt(VFX_TRUE); // myler VK memory isn't enough
}


void VappPhbViewerScr::on1stReady()
{
    VfxMainScr::on1stReady();
#ifdef __MMI_PHB_VIEW_CALLOG__
    VFX_OBJ_CREATE_EX(m_page, VappPhbViewerPage, this, (m_id));
#else
    VFX_OBJ_CREATE_EX(m_page, VappPhbViewerProfilePage, this, (m_id));
#endif
    pushPage(VFX_ID_NULL, m_page);

    ContactTask *task = GET_CONTACT_TASK();
    task->m_signalTask.connect(this, &VappPhbViewerScr::onContactUpdated);
}


void VappPhbViewerScr::on2ndReady()
{
    VfxMainScr::on2ndReady();

    ((VappPhbViewerPage*) m_page)->updatePage();
}


void VappPhbViewerScr::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


void VappPhbViewerScr::onContactUpdated(ContactTask* task, mmi_event_struct* evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_PHB_READY:
        {
            srv_phb_startup_evt_struct *ready = (srv_phb_startup_evt_struct*) evt;
            if (!ready->phb_ready)
            {
                exit();
            }
            break;
        }
        case EVT_ID_PHB_UPD_CONTACT:
        {
            // related page should update it's content
            // dispatch the event to sub pages            
            srv_phb_op_evt_struct *op = (srv_phb_op_evt_struct*) evt;
            if (op->store_index == m_id)
            {
                processProc(evt);
            }
            break;
        }
        case EVT_ID_PHB_DEL_CONTACT:
        {
            srv_phb_op_evt_struct *op = (srv_phb_op_evt_struct*) evt;
            if (op->store_index == m_id)
            {
                processProc(evt);
                exit();
            }
            break;
        }
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        case EVT_ID_USB_ENTER_MS_MODE:
        {
            processProc(evt);
            break;
        }
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        {
            // view don't care plug in
            break;
        }
    #else
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        case EVT_ID_USB_ENTER_MS_MODE:
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        case EVT_ID_USB_EXIT_MS_MODE:
        {
            processProc(evt);
            break;
        }
    #endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
    }
}


/***************************************************************************** 
 * Class VappPhbViewerPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappPhbViewerPage", VappPhbViewerPage, VcpTabCtrlPage);

void VappPhbViewerPage::onInit()
{
    VcpTabCtrlPage::onInit();

    addTab(VAPP_PHB_VIEWER_PROFILE, VFX_WSTR_RES(VAPP_PHB_STR_PROFILE), VcpStateImage(VAPP_PHB_IMG_TAB_PROFILE));
    addTab(VAPP_PHB_VIEWER_CLOG, VFX_WSTR_RES(VAPP_PHB_STR_CLOG), VcpStateImage(VAPP_PHB_IMG_TAB_CLOG));
    addTab(VAPP_PHB_VIEWER_MSG, VFX_WSTR_RES(VAPP_PHB_STR_MSG), VcpStateImage(VAPP_PHB_IMG_TAB_MESSAGE));

    // always set profile page as first one
    setCurrTab(VAPP_PHB_VIEWER_PROFILE);
}


VfxPage* VappPhbViewerPage::onCreateTabPage(VfxId tabId)
{
    VfxPage *page = NULL;

    switch (tabId)
    {
    case VAPP_PHB_VIEWER_PROFILE:
        VFX_OBJ_CREATE_EX(page, VappPhbViewerProfilePage, this, (m_id));
        m_profilePage = page;
        break;
        
#ifdef __MMI_PHB_VIEW_CALLOG__
    case VAPP_PHB_VIEWER_CLOG:
        VFX_OBJ_CREATE_EX(page, VappCLogList, this, (VAPP_CLOG_PAGE_FOR_CONTACT, VFX_FALSE, VAPP_CLOG_LIST_ID_ALL_CALL, m_id));
        break;

    case VAPP_PHB_VIEWER_MSG:
        VFX_OBJ_CREATE_EX(page, VappMsgPhbDialogPage, this, (m_id));
        break;
#endif
#if defined(__MMI_SNS_CENTER__) && defined(__MMI_SNS_CONTACTS__)
    case VAPP_PHB_VIEWER_SNS:
        VFX_OBJ_CREATE_EX(page, VappSnsActivitiesPage, this, (m_id));
        break;
#endif /* __MMI_SNS_CENTER__ && __MMI_SNS_CONTACTS__ */
    }

    return page;
}


void VappPhbViewerPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


void VappPhbViewerPage::updatePage()
{
#ifdef __MMI_SNS_CONTACTS__
    ((VappPhbViewerProfilePage*) m_profilePage)->updatePage();
#endif
}


/***************************************************************************** 
 * Class VappPhbViewerProfilePage
 *****************************************************************************/
VappPhbViewerProfilePage::VappPhbViewerProfilePage(mmi_phb_contact_id id, VfxBool viewOnly):
    m_id(id),
    m_contact(NULL),
    m_toolBar(NULL),
    m_form(NULL),
    m_field(NULL),
#ifdef __MMI_SNS_CONTACTS__
    m_providerCount(0),
    m_listId(-1),
    m_linkedCount(0),
    m_startIndex(-1),
    m_endIndex(-1),
    m_refresh(VFX_FALSE),
#endif /* __MMI_SNS_CONTACTS__ */
    m_cui(GRP_ID_INVALID),
#ifdef __MMI_VCARD__    
    m_vcard(NULL),
#endif /* __MMI_VCARD__*/
    m_path(NULL),
    m_viewOnly(viewOnly),
    m_b2ndReady(VFX_FALSE)
{
    m_editTcard = VFX_FALSE;
    m_isMsmode = VFX_FALSE;
    //m_buffer = NULL;
}


void VappPhbViewerProfilePage::onInit()
{
    VfxPage::onInit();

    mmi_frm_cb_reg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, &VappPhbViewerProfilePage::listener, getObjHandle());
    /*mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &VappPhbViewerProfilePage::listener, getObjHandle());
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappPhbViewerProfilePage::listener, getObjHandle());
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, &VappPhbViewerProfilePage::listener, getObjHandle());
    mmi_frm_cb_reg_event(EVT_ID_USB_EXIT_MS_MODE, &VappPhbViewerProfilePage::listener, getObjHandle());
#endif*/
    // create contact
    VFX_ALLOC_NEW_EX(m_contact, ContactEntry, this, (m_id));
#ifndef __MMI_PHB_VIEW_CALLOG__
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VAPP_PHB_STR_PROFILE);
    setTopBar(bar);
#else
    if (m_viewOnly)
    {
        VcpTitleBar *bar;
        VFX_OBJ_CREATE(bar, VcpTitleBar, this);
        bar->setTitle(VAPP_PHB_STR_PROFILE);
        setTopBar(bar);
    }
    else
#endif
    {
        if(!m_viewOnly)
        {
            VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
            setBottomBar(m_toolBar);

            m_toolBar->addItem(CONTACT_PROFIEL_CMD_EDIT, (VfxResId)STR_GLOBAL_EDIT, VCP_IMG_TOOL_BAR_COMMON_ITEM_EDIT);
#ifdef __MMI_VCARD__
            m_toolBar->addItem(CONTACT_PROFIEL_CMD_SHARE, (VfxResId)VAPP_PHB_STR_SHARE, VCP_IMG_TOOL_BAR_COMMON_ITEM_SHARE);
#endif /* __MMI_VCARD__ */
            m_toolBar->addItem(CONTACT_PROFIEL_CMD_DELETE, (VfxResId)STR_GLOBAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);

            VfxWString text = VFX_WSTR_RES(VCP_STR_TOOL_BAR_COPY);
            if (ContactSim::getTotal() == 1)
            {
                text += VFX_WSTR_RES(STR_ID_VAPP_PHB_TO_LOW);
                phb_storage_enum storage = (ContactStorage::getStorage(m_id) == PHB_STORAGE_NVRAM) ? PHB_STORAGE_SIM : PHB_STORAGE_NVRAM;
                text += ContactStorage::getName(storage);
            }

            m_toolBar->addItem(CONTACT_PROFIEL_CMD_COPY, text, VCP_IMG_TOOL_BAR_COMMON_ITEM_COPY);
#ifdef __MMI_SNS_CONTACTS__
            if (m_contact->getStorage() == PHB_STORAGE_NVRAM)
            {
                m_toolBar->addItem(CONTACT_PROFILE_CMD_SNS_LINK, VFX_WSTR_RES(STR_ID_VAPP_PHB_LINK), VAPP_PHB_IMG_CMD_LINK);
            }
#endif /* __MMI_SNS_CONTACTS__ */

            if (srv_sim_ctrl_get_num_of_inserted() == 0 ||
                (srv_sim_ctrl_get_num_of_inserted() == 1 && srv_sim_ctrl_get_one_available_sim() == 0))
            {
                m_toolBar->setDisableItem(CONTACT_PROFIEL_CMD_COPY, VFX_TRUE);
            }

            m_toolBar->m_signalButtonTap.connect(this, &VappPhbViewerProfilePage::onToolBarClick);
        }
    }
    mmi_id m_appId = getApp()->getGroupId();
    // build form
    buildForm();
}


void VappPhbViewerProfilePage::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, &VappPhbViewerProfilePage::listener, getObjHandle());
    /*mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &VappPhbViewerProfilePage::listener, getObjHandle());
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappPhbViewerProfilePage::listener, getObjHandle());
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, &VappPhbViewerProfilePage::listener, getObjHandle());
    mmi_frm_cb_dereg_event(EVT_ID_USB_EXIT_MS_MODE, &VappPhbViewerProfilePage::listener, getObjHandle());
#endif*/
    VFX_DELETE(m_contact);

#ifdef __MMI_SNS_CONTACTS__
    if (m_listId != -1)
    {
        srv_sns_release_list(m_listId, MMI_TRUE);
        m_listId = -1;
    }
#endif /* __MMI_SNS_CONTACTS__ */
    VfxPage::onDeinit();
}


void VappPhbViewerProfilePage::onEntered()
{
    VfxPage::onEntered();

    vcui_phb_contact_viewer_result_event_struct evt;
    VappPhbViewContactCui *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VappPhbViewContactCui);

    if (cui && !m_viewOnly)
    {
        MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_PHB_VIEW_ENTERED, cui->getGroupId());
        evt.result = 0;

        cui->postToCaller((mmi_group_event_struct*)&evt);
    }
}


mmi_ret VappPhbViewerProfilePage::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
    #ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
        case EVT_ID_PHB_FIELD_TYPE_CHNAGED_IND:
        {
            // refresh form
            VFX_OBJ_CLOSE(m_form);
            buildForm();
            break;
        }
    #endif /* __MMI_PHB_CUSTOM_FIELD_TYPE__ */
        case EVT_ID_PHB_DEL_CONTACT:
        {
            srv_phb_op_evt_struct *op = (srv_phb_op_evt_struct*) evt;
            if (op->store_index == m_id)
            {
                if (m_cui != GRP_ID_INVALID)
                {
                    VfxAppLauncher::terminate(m_cui);
                    m_cui = GRP_ID_INVALID;
                    if (ContactStorage::getStorage(m_id) == PHB_STORAGE_TCARD)
                    {
                        m_editTcard = VFX_FALSE;
                    }
                }
            }
            break;
        }
        case EVT_ID_PHB_UPD_CONTACT:
        {
            srv_phb_op_evt_struct *op = (srv_phb_op_evt_struct*) evt;
            if (op->store_index == m_id)
            {
                // refresh form
                VFX_OBJ_CLOSE(m_form);

    #ifdef __MMI_PHB_BIRTHDAY_FIELD__
                vapp_cal_add_birthday_close();
    #endif
                VFX_DELETE(m_contact);
                VFX_ALLOC_NEW_EX(m_contact, ContactEntry, this, (m_id));

                buildForm();
            }
            break;
        }
        case EVT_ID_CUI_PHB_SAVE_RESULT:
        {
            vcui_phb_contact_saver_close(((mmi_group_event_struct*) evt)->sender_id);
            m_cui = GRP_ID_INVALID;
            if (m_editTcard)  // later close view page & storage == tcard
            {
                getMainScr()->popPage();
                m_editTcard = VFX_FALSE;
            }
            break;
        }
        case EVT_ID_CUI_DIALER_CLOSE_REQ:
        {
            vcui_dialer_close(((mmi_group_event_struct*) evt)->sender_id);
            return MMI_RET_OK;
        }
    #ifdef __MMI_SNS_CONTACTS__
        case EVT_ID_VCUI_SNS_CONTACT_PICKER_RESULT:
        {
            vcui_sns_contacts_picker_result_event_sturct *sns_evt = (vcui_sns_contacts_picker_result_event_sturct *)evt;
    
            if (sns_evt->result > 0)
            {
                srv_sns_modify_link_contact(m_id, sns_evt->selected_list, sns_evt->selected_list_num, MMI_TRUE, &VappPhbViewerProfilePage::listener, getObjHandle());
            }
            else
            {
                disableSnsToolBar(VFX_FALSE);
            }

            vcui_sns_contacts_picker_close(sns_evt->sender_id);
            break;
        }

        case EVT_ID_SRV_SNS_RESULT:
        {
            srv_sns_evt_result_struct *sns_result = (srv_sns_evt_result_struct *)evt;

            if (sns_result->result == SRV_SNS_OK)
            {
                refreshForm();
            }
            break;
        }

        case EVT_ID_SRV_SNS_LIST_UPDATED:
        {
            srv_sns_evt_list_updated_struct *sns_update = (srv_sns_evt_list_updated_struct *)evt;

            m_linkedCount = sns_update->total;
            m_startIndex = sns_update->start_index;
            m_endIndex = sns_update->end_index;

            if (m_linkedCount > 0 && sns_update->result == SRV_SNS_OK)
            {
                VFX_ASSERT(m_endIndex - m_startIndex + 1 == m_linkedCount);
            }

            if (sns_update->list_id == m_listId)
            {
                // refresh form
                VFX_OBJ_CLOSE(m_form);
                buildForm();

                if (m_linkedCount == 0)
                {
                    snsAccountsUnlinked();
                }
                else
                {
                    snsAccountsLinked();
                }

                disableSnsToolBar(VFX_FALSE);
            }
            break; // myler lose before 
        }
    #endif /* __MMI_SNS_CONTACTS__ */
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        case EVT_ID_USB_ENTER_MS_MODE:
        {
            if (m_editTcard) // check m_editTcard, later close view page
            {
                break;
            }
            // close view page if == TCARD
            if (m_contact->getStorage() == PHB_STORAGE_TCARD)
            {
               getMainScr()->popPage();
            }
            else
            {
               VFX_OBJ_CLOSE(m_form);
               buildForm();
            }
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        case EVT_ID_USB_EXIT_MS_MODE:
        {
            if (m_contact->getStorage() != PHB_STORAGE_TCARD)
            {
               VFX_OBJ_CLOSE(m_form);
               buildForm();
            }
            break;
        }
    #else
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
    #ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_EXIT_MS_MODE:
    #endif
        {
          // refresh form
            VFX_OBJ_CLOSE(m_form);
            buildForm();
            return MMI_RET_OK;
        }
    #ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE :
    #endif
        {
            VFX_OBJ_CLOSE(m_form);
            m_isMsmode = VFX_TRUE;
            buildForm();  
            return MMI_RET_OK;
        }

    #endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */

        case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
        {
            // refresh form
            VFX_OBJ_CLOSE(m_form);

          //  VFX_DELETE(m_contact);
          //  VFX_ALLOC_NEW_EX(m_contact, ContactEntry, this, (m_id));
            buildForm();
          
            break;
        }
    #ifdef __MMI_SMS_COMPOSER__
        case EVT_ID_CUI_SMS_COMPOSER_CLOSE:
        {
                    /* just close it */
            VcuiSmsComposerEventStruct *ucEvt = (VcuiSmsComposerEventStruct *)evt;
            vcui_sms_composer_close(ucEvt->sender_id);        
            break;
        }
   #endif
    }

    return VfxPage::onProc(evt);
}


void VappPhbViewerProfilePage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


void VappPhbViewerProfilePage::buildForm()
{
    // create form
    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

    // create field stack
    VFX_OBJ_CREATE(m_field, VappPhbFieldItem, m_form);

    // create detail
    createName();
    createNumber();
    createEmail();
#ifdef __MMI_SNS_CONTACTS__
    if (m_contact->getStorage() == PHB_STORAGE_NVRAM)
    {
        createSNS();
    }
#endif /* __MMI_SNS_CONTACTS__ */
#ifdef __MMI_PHB_INFO_FIELD__
    createAddress();
#endif
#ifdef __MMI_PHB_BIRTHDAY_FIELD__
    createBday();
#endif
#ifdef __MMI_PHB_INFO_FIELD__
    createTitle();
#endif
#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    createCompany();
#endif
#ifdef __MMI_PHB_INFO_FIELD__
    createNote();
#endif
}


void VappPhbViewerProfilePage::createName()
{
    VappPhbViewerNameFormItem *name;
    VFX_OBJ_CREATE(name, VappPhbViewerNameFormItem, m_form);
    m_name = name;

    VappContactFieldItem item;
    item.m_itemId = m_field->getNewItemId();
    item.m_itemType = CONTACT_PROFILE_FIELD_NAME;
    item.m_obj = name;
    m_field->setItem(item);

    VfxWString nameStr = m_contact->getName().getString();
    if (nameStr.isEmpty())
    {
        nameStr.loadFromRes(VAPP_PHB_STR_UNNAMED);
    }

    name->setName(nameStr);
#ifdef __MMI_PHB_USIM_SUPPORT__
    name->setNickname(m_contact->getNickname().getString());
#endif
    //kal_prompt_trace(MOD_MMI,"srv_fmgr_fs_path_exist: %d", srv_fmgr_fs_path_exist(m_contact->getImage().getPath()));
    if (m_isMsmode)
    {
        name->setImage(VfxImageSrc(VAPP_PHB_IMG_DEFAULT_CONTACT));
        m_isMsmode = VFX_FALSE;
    }
    else
    {
        if (!m_contact->getImage().getPath())
        {
            name->setImage(m_contact->getImage().getImageSrc());
        }
        else  if (srv_fmgr_fs_path_exist(m_contact->getImage().getPath()) >= 0)
        {
            //kal_prompt_trace(MOD_MMI, "VappPhbViewerProfilePage::createName ():path is  exist :%d", srv_fmgr_fs_path_exist(m_contact->getImage().getPath()));

            if (vapp_phb_query_head_portrait_need_thumbnail((CHAR*)m_contact->getImage().getPath().getBuf()))
            {
                name->m_image->setImageContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
            }
            name->setImage(VfxImageSrc(m_contact->getImage().getPath()));
        }
        else
        {
             name->setImage(m_contact->getImage().getImageSrc());
        }
    }
    name->setIcon(ContactStorage::getIcon(m_id));

    m_form->addItem(name, item.m_itemId);
    m_form->insertSeparator(item.m_itemId);
}


/*VfxImageBuffer VappPhbViewerProfilePage::UpdateImage(VfxWString filePath)
{
    S32 image_width;
    S32 image_height;
    S32 result;
    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;
    gdi_handle handleT;
    gdi_layer_create_cf_using_outside_memory(
                                            GDI_COLOR_FORMAT_16,
                                            0,
                                            0,
                                            ICON_SIZE,
                                            ICON_SIZE,
                                            &handleT,
                                            (U8*)m_buffer,
                                            ICON_SIZE * ICON_SIZE * 2);

    gdi_layer_push_and_set_active(handleT);

    result = gdi_image_get_dimension_file(
                                          (S8*)filePath.getBuf(),
                                          &image_width,
                                          &image_height);

    if (result >= 0)
    {
      gdi_util_fit_box(
                      GDI_UTIL_MODE_SHORT_SIDE_FIT,//GDI_UTIL_MODE_NO_RESIZE_OR_SHORT_SIDE_FIT,
                      ICON_SIZE,
                      ICON_SIZE,
                      image_width,
                      image_height,
                      &resized_offset_x,
                      &resized_offset_y,
                      &resized_width,
                      &resized_height);
      gdi_image_draw_resized_file(
                                      resized_offset_x,
                                      resized_offset_y,
                                      resized_width,
                                      resized_height,
                                      (S8*)filePath.getBuf());
    }
    gdi_layer_pop_and_restore_active();
    gdi_layer_free(handleT);

    VfxImageBuffer imageBuf;
    imageBuf.ptr = (VfxU8*)m_buffer;
    imageBuf.pitchBytes = ICON_SIZE*2;
    imageBuf.width = ICON_SIZE;
    imageBuf.height = ICON_SIZE;
    imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
    return imageBuf;
}
*/


void VappPhbViewerProfilePage::createNumber()
{
    VfxU32 numCount = m_contact->getNumber();
    VfxU32 index = 0;

    for (; numCount > 0; numCount--)
    {
        VappContactNumber number = m_contact->getNextNumber();

        VappPhbViewerNumFormItem *num;
        VFX_OBJ_CREATE(num, VappPhbViewerNumFormItem, m_form);

        VappContactFieldItem item;
        item.m_itemId = m_field->getNewItemId();
        item.m_itemType = CONTACT_PROFILE_FIELD_NUMBER;
        item.m_fieldId = number.getSubId();
        item.m_fieldType = number.getSubType();
        item.m_obj = num;
        m_field->setItem(item);
        m_itemIdArray[index++] = item.m_itemId;

        num->setItemContent(
            number.getLabel(),
            number.getString(),
            m_contact->getPreferSim(number.getSubId()),
            m_contact->getPreferSim(number.getSubId(), VFX_FALSE));

    #ifdef __MMI_CM_BLACK_LIST__ // setItemContent is not working
        if (vapp_phb_is_blocked_number(0, number))
        {
            num->setBlockIcon();
        }
    #endif /* __MMI_CM_BLACK_LIST__ */

        m_form->addItem(num, item.m_itemId);
        m_form->insertSeparator(item.m_itemId);

        // create call button
        VcpComboButton *call;
        call = num->getCallBtn();
        call->setId(item.m_itemId);
        call->m_signalClicked.connect(this, &VappPhbViewerProfilePage::makeCall);
        if (srv_sim_ctrl_get_num_of_inserted() >= 2)
        {
            call->setHasChildBtn(VFX_TRUE, item.m_itemId);
            call->m_signalChildBtnClicked.connect(this, &VappPhbViewerProfilePage::makeChildCall);
        }

        // create message button
        VcpComboButton *msg;
        msg = num->getMsgBtn();
        msg->setId(item.m_itemId);
        msg->m_signalClicked.connect(this, &VappPhbViewerProfilePage::sendMsg);
        if (srv_sim_ctrl_get_num_of_inserted() >= 2)
        {
            msg->setHasChildBtn(VFX_TRUE, item.m_itemId);
            msg->m_signalChildBtnClicked.connect(this, &VappPhbViewerProfilePage::sendChildMsg);
        }

        // create more button
        VcpButton *more;
        more = num->getMoreBtn();
        more->setId(item.m_itemId);
        more->m_signalClicked.connect(this, &VappPhbViewerProfilePage::moreAction);
    }
}


void VappPhbViewerProfilePage::createEmail()
{
    VfxU32 emailCount = m_contact->getEmail();

    for (; emailCount > 0; emailCount--)
    {
        VappContactEmail email = m_contact->getNextEmail();

        VappPhbViewerLabelBtnFormItem *formItem;
        VFX_OBJ_CREATE(formItem, VappPhbViewerLabelBtnFormItem, m_form);

        VappContactFieldItem item;
        item.m_itemId = m_field->getNewItemId();
        item.m_itemType = CONTACT_PROFILE_FIELD_EMAIL;
        item.m_fieldId = email.getSubId();
        item.m_fieldType = email.getSubType();
        item.m_obj = formItem;
        m_field->setItem(item);

    #ifdef __MMI_EMAIL__
        formItem->setStyle(VappPhbViewerLabelBtnFormItem::VAPP_PHB_VIEWER_FORM_ITEM_LABEL_BTN);
        formItem->setItemContent(email.getLabel(), email.getString());

        VcpButton *btn = formItem->getButton();
        btn->setId(item.m_itemId);
        btn->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY_LEFT);
        btn->setText(VAPP_PHB_STR_SEND_EMAIL);
        btn->m_signalClicked.connect(this, &VappPhbViewerProfilePage::sendEmail);
    #else /* __MMI_EMAIL__ */
        formItem->setStyle(VappPhbViewerLabelBtnFormItem::VAPP_PHB_VIEWER_FORM_ITEM_LABEL);
        formItem->setItemContent(email.getLabel(), email.getString());
    #endif /* __MMI_EMAIL__ */

        m_form->addItem(formItem, item.m_itemId);
        m_form->insertSeparator(item.m_itemId);
    }
}


#ifdef __MMI_SNS_CONTACTS__
void VappPhbViewerProfilePage::createSNS()
{
    if (!m_b2ndReady)
    {
        return;
    }

    if (m_refresh)
    {
        srv_sns_info_struct *info;

        for (VfxS16 i = m_startIndex; i <= m_endIndex && m_linkedCount > 0; i++)
        {
            srv_sns_get_item(m_listId, i, (void **)&info);

            if (i == 0)
            {
                VappPhbViewerNameFormItem *name = (VappPhbViewerNameFormItem *)m_name;
                name->setComment(VFX_WSTR_MEM(info->status));
            }

            VappSnsFormItemAcctViewer *formItem;
            VFX_OBJ_CREATE_EX(formItem, VappSnsFormItemAcctViewer, m_form, (info->user.provider, info->user.user_id, info->user.user_name, info->profile_url));

            VappContactFieldItem item;
            item.m_itemId = m_field->getNewItemId();
            item.m_itemType = CONTACT_PROFILE_FIELD_SNS;
            item.m_obj = formItem;
            m_field->setItem(item);

            m_form->addItem(formItem, item.m_itemId);
            m_form->insertSeparator(item.m_itemId);
        }

        m_refresh = VFX_FALSE;
    }
    else
    {
        refreshForm();
    }
}
#endif /* __MMI_SNS_CONTACTS__ */


#ifdef __MMI_PHB_INFO_FIELD__
void VappPhbViewerProfilePage::createAddress()
{
    if (MMI_PHB_CONTACT_FIELD_ADDRESS & m_contact->getFieldMask())
    {
        VappContactAddress addr = m_contact->getAddress();

        if (!addr.isEmpty())
        {
            VappPhbViewerLabelTextFormItem *formItem;
            VFX_OBJ_CREATE(formItem, VappPhbViewerLabelTextFormItem, m_form);

            VappContactFieldItem item;
            item.m_itemId = m_field->getNewItemId();
            item.m_itemType = CONTACT_PROFILE_FIELD_ADDRESS;
            item.m_obj = formItem;
            m_field->setItem(item);

            formItem->setItemContent(addr.getLabel(), addr.getString());

            m_form->addItem(formItem, item.m_itemId);
            m_form->insertSeparator(item.m_itemId);

            m_form->m_signalBoundsChanged.connect(formItem, &VappPhbViewerLabelTextFormItem::onItemBoundsChanged);
        }
    }
}
#endif /* __MMI_PHB_INFO_FIELD__ */


#ifdef __MMI_PHB_BIRTHDAY_FIELD__
void VappPhbViewerProfilePage::createBday()
{
    if (MMI_PHB_CONTACT_FIELD_BDAY & m_contact->getFieldMask())
    {
        VappContactBday bday = m_contact->getBday();

        VappPhbViewerLabelBtnFormItem *formItem;
        VFX_OBJ_CREATE(formItem, VappPhbViewerLabelBtnFormItem, m_form);

        VappContactFieldItem item;
        item.m_itemId = m_field->getNewItemId();
        item.m_itemType = CONTACT_PROFILE_FIELD_BIRTHDAY;
        item.m_obj = formItem;
        m_field->setItem(item);

        formItem->setStyle(VappPhbViewerLabelBtnFormItem::VAPP_PHB_VIEWER_FORM_ITEM_LABEL_BTN);
        formItem->setItemContent(bday.getLabel(), bday.getString());

        VcpButton *btn = formItem->getButton();
        btn->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        btn->setText(VAPP_PHB_STR_NOTIFY_ME);
        btn->m_signalClicked.connect(this, &VappPhbViewerProfilePage::onBdayClicked);

        m_form->addItem(formItem, item.m_itemId);
        m_form->insertSeparator(item.m_itemId);
    }
}
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */


#ifdef __MMI_PHB_INFO_FIELD__
void VappPhbViewerProfilePage::createTitle()
{
    if (MMI_PHB_CONTACT_FIELD_TITLE & m_contact->getFieldMask())
    {
        VappContactTitle title = m_contact->getTitle();

        VappPhbViewerLabelTextFormItem *formItem;
        VFX_OBJ_CREATE(formItem, VappPhbViewerLabelTextFormItem, m_form);

        VappContactFieldItem item;
        item.m_itemId = m_field->getNewItemId();
        item.m_itemType = CONTACT_PROFILE_FIELD_TITLE;
        item.m_obj = formItem;
        m_field->setItem(item);

        formItem->setItemContent(title.getLabel(), title.getString());

        m_form->addItem(formItem, item.m_itemId);
        m_form->insertSeparator(item.m_itemId);

        m_form->m_signalBoundsChanged.connect(formItem, &VappPhbViewerLabelTextFormItem::onItemBoundsChanged);
    }
}
#endif /* __MMI_PHB_INFO_FIELD__ */


#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
void VappPhbViewerProfilePage::createCompany()
{
    if (MMI_PHB_CONTACT_FIELD_COMPANY & m_contact->getFieldMask())
    {
        VappContactCompany company = m_contact->getCompany();

        VappPhbViewerLabelTextFormItem *formItem;
        VFX_OBJ_CREATE(formItem, VappPhbViewerLabelTextFormItem, m_form);

        VappContactFieldItem item;
        item.m_itemId = m_field->getNewItemId();
        item.m_itemType = CONTACT_PROFILE_FIELD_COMPANY;
        item.m_obj = formItem;
        m_field->setItem(item);

        formItem->setItemContent(company.getLabel(), company.getString());

        m_form->addItem(formItem, item.m_itemId);
        m_form->insertSeparator(item.m_itemId);

        m_form->m_signalBoundsChanged.connect(formItem, &VappPhbViewerLabelTextFormItem::onItemBoundsChanged);
    }
}
#endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */


#ifdef __MMI_PHB_INFO_FIELD__
void VappPhbViewerProfilePage::createNote()
{
    if (MMI_PHB_CONTACT_FIELD_NOTE & m_contact->getFieldMask())
    {
        VappContactNote note = m_contact->getNote();

        VappPhbViewerLabelTextFormItem *formItem;
        VFX_OBJ_CREATE(formItem, VappPhbViewerLabelTextFormItem, m_form);

        VappContactFieldItem item;
        item.m_itemId = m_field->getNewItemId();
        item.m_itemType = CONTACT_PROFILE_FIELD_NOTE;
        item.m_obj = formItem;
        m_field->setItem(item);

        formItem->setItemContent(note.getLabel(), note.getString());

        m_form->addItem(formItem, item.m_itemId);
        m_form->insertSeparator(item.m_itemId);

        m_form->m_signalBoundsChanged.connect(formItem, &VappPhbViewerLabelTextFormItem::onItemBoundsChanged);
    }
}
#endif /* __MMI_PHB_INFO_FIELD__ */


#ifdef __MMI_PHB_BIRTHDAY_FIELD__
void VappPhbViewerProfilePage::onBdayClicked(VfxObject* obj, VfxId id)
{
    vapp_cal_add_birthday_struct bday;
    VfxWChar name[MMI_PHB_NAME_LENGTH + 1];

    mmi_wcscpy(name, m_contact->getName().getString().getBuf());
    vfx_sys_wcsncpy(bday.name, name, VFX_MIN(MMI_PHB_NAME_LENGTH, VAPP_CAL_MAX_SUBJECT_LEN));

    VappContactBday contactBday = m_contact->getBday();

    bday.date.nYear = contactBday.getYear();
    bday.date.nMonth = contactBday.getMonth();
    bday.date.nDay = contactBday.getDay();
    bday.date.nMin = 0;
    bday.date.nSec = 0;
    bday.date.DayIndex = 0;

    vapp_cal_add_birthday_launch(&bday);
}
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */


void VappPhbViewerProfilePage::selectSimPopup(VfxBool call, mmi_sim_enum sim)
{
    VcpMenuPopup *cntxMenu;
    VFX_OBJ_CREATE(cntxMenu, VcpMenuPopup, this);
    cntxMenu->setTitle(STR_ID_VAPP_PHB_SELECT_SIM);

    for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
    {
        mmi_sim_enum storage = mmi_frm_index_to_sim(i);
        if (srv_sim_ctrl_is_inserted(storage))
        {
            if (storage == sim)
            {
                continue;
            }

            VfxId btnId = call ? VAPP_PHB_SELECT_SIM_CALL + i : VAPP_PHB_SELECT_SIM_MSG + i;
            VfxWString text = call ? (VAPP_PHB_STR_CALL) : (VAPP_PHB_STR_MESSAGE);
            if (call)
            {
                cntxMenu->addItem(btnId, text, ContactSim::getCallIcon(storage), VCP_MENU_POPUP_ITEM_TYPE_2);
            }
            else
            {
                cntxMenu->addItem(btnId, text, ContactSim::getMsgIcon(storage), VCP_MENU_POPUP_ITEM_TYPE_2);
            }
            ((VcpMenuPopupItemType2 *)cntxMenu->getItemById(btnId))->setHintText(vapp_sim_settings_get_sim_name(storage));
            if (!(srv_mode_switch_get_current_mode() & storage))
            {
                cntxMenu->getItemById(btnId)->setIsDisabled(VFX_TRUE);
            }
        }
    }

    cntxMenu->m_signalMenuCallback.connect(this, &VappPhbViewerProfilePage::onSimSelected);
    cntxMenu->show(VFX_TRUE);
}


void VappPhbViewerProfilePage::onSimSelected(VcpMenuPopup* popup, VcpMenuPopupEventEnum flag, VcpMenuPopupItem* item)
{
    if (flag != VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
        return;
    }

    if (item->getId() >= VAPP_PHB_SELECT_SIM_MSG)
    {
#if (defined( __MMI_SMS_COMPOSER__) || defined(__MMI_UNIFIED_COMPOSER__) )
        createMsg(m_id, m_number, mmi_frm_index_to_sim(item->getId() - VAPP_PHB_SELECT_SIM_MSG));
#else
        VappPhbActionObj::sendMessage(m_id, m_number, mmi_frm_index_to_sim(item->getId() - VAPP_PHB_SELECT_SIM_MSG));
#endif
    }
    else if (item->getId() >= VAPP_PHB_SELECT_SIM_CALL)
    {
        VappPhbActionObj::makeCall(m_id, m_number, mmi_frm_index_to_sim(item->getId() - VAPP_PHB_SELECT_SIM_CALL));
    }
}


void VappPhbViewerProfilePage::makeCall(VfxObject *obj, VfxId id)
{
    VappContactFieldItem& item = m_field->getItem(id);

    m_number = m_contact->getNumberById(item.m_fieldId);
    if (m_contact->getPreferSim(m_number.getSubId()) != MMI_SIM_NONE)
    {
        VappPhbActionObj::makeCall(m_id, m_number, m_contact->getPreferSim(m_number.getSubId()));
    }
    else if (m_contact->getPreferSim(m_number.getSubId()) == MMI_SIM_NONE && srv_sim_ctrl_get_num_of_inserted() == 1)
    {
        for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
        {
            if (srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(i)))
            {
                VappPhbActionObj::makeCall(m_id, m_number, mmi_frm_index_to_sim(i));
                return;
            }
        }
    }
    else
    {
        selectSimPopup(VFX_TRUE, MMI_SIM_NONE);
    }
}


void VappPhbViewerProfilePage::makeChildCall(VcpButton *button, VfxId id)
{
    VappContactFieldItem& item = m_field->getItem(id);

    m_number = m_contact->getNumberById(item.m_fieldId);
    if (srv_sim_ctrl_get_num_of_inserted() == 2 && m_contact->getPreferSim(m_number.getSubId()) != MMI_SIM_NONE)
    {
        for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
        {
            mmi_sim_enum sim = mmi_frm_index_to_sim(i);
            if (srv_sim_ctrl_is_inserted(sim) && sim != m_contact->getPreferSim(m_number.getSubId()))
            {
                VappPhbActionObj::makeCall(m_id, m_number, sim);
                break;
            }
        }
    }
    else
    {
        selectSimPopup(VFX_TRUE, m_contact->getPreferSim(m_number.getSubId()));
    }
}


void VappPhbViewerProfilePage::sendMsg(VfxObject *obj, VfxId id)
{
    VappContactFieldItem& item = m_field->getItem(id);

    m_number = m_contact->getNumberById(item.m_fieldId);
    if (m_contact->getPreferSim(m_number.getSubId(), VFX_FALSE) != MMI_SIM_NONE)
    {
 #if (defined( __MMI_SMS_COMPOSER__) || defined(__MMI_UNIFIED_COMPOSER__))
        createMsg(m_id, m_number, m_contact->getPreferSim(m_number.getSubId(), VFX_FALSE));
#else           
        VappPhbActionObj::sendMessage(m_id, m_number, m_contact->getPreferSim(m_number.getSubId(), VFX_FALSE));
#endif
    
    }
    else if (m_contact->getPreferSim(m_number.getSubId(), VFX_FALSE) == MMI_SIM_NONE && srv_sim_ctrl_get_num_of_inserted() == 1)
    {
        for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
        {
            if (srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(i)))
            {
            #if (defined( __MMI_SMS_COMPOSER__) || defined(__MMI_UNIFIED_COMPOSER__))
                createMsg(m_id, m_number, mmi_frm_index_to_sim(i));
            #else
            
                VappPhbActionObj::sendMessage(m_id, m_number, mmi_frm_index_to_sim(i));
            #endif
                return;
            }
        }
    }
    else
    {
        selectSimPopup(VFX_FALSE, MMI_SIM_NONE);
    }
}

#if (defined( __MMI_SMS_COMPOSER__) || defined(__MMI_UNIFIED_COMPOSER__))
void VappPhbViewerProfilePage::createMsg(mmi_phb_contact_id id, VappContactNumber& number, mmi_sim_enum sim)
{
#ifdef __MMI_SMS_COMPOSER__
    mmi_id smsComposerCui = 0;
    VcuiSmsComposerEntryStruct *entryData;
    VFX_ALLOC_MEM(entryData, sizeof(VcuiSmsComposerEntryStruct),this);
    vfx_sys_mem_zero(entryData, sizeof(VcuiSmsComposerEntryStruct) );

    // set address
    VcuiSmsComposerAddrStruct address;
    address.next = NULL;
    address.previous = NULL;
    address.type = VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER;
    address.addr = number.getBuf();  
    entryData->addr_num = 1;
    entryData->addr = &address;
    entryData->sim_id = sim;
    smsComposerCui = vcui_sms_composer_create(getApp()->getGroupId());
    if(smsComposerCui !=  GRP_ID_INVALID)
    {
        vcui_sms_composer_set_entry_data(smsComposerCui, entryData);        
        vfxSetCuiCallerScr(smsComposerCui, getMainScr());
        vcui_sms_composer_run(smsComposerCui);
    }
    VFX_FREE_MEM(entryData);
#else
#ifdef  __MMI_UNIFIED_COMPOSER__ 
        VappUcEntryStruct *ucEntry;
#ifdef __MMI_PHB_NEED_SERIALZE__
    ucEntry = (VappUcEntryStruct*)srv_phb_mem_malloc(sizeof(VappUcEntryStruct), SRV_PHB_MEMORY_TYPE_ADM);
#else 
    ucEntry = (VappUcEntryStruct*) mmi_frm_temp_alloc(sizeof(VappUcEntryStruct));
#endif
        // set uc type
        memset(ucEntry, 0, sizeof(VappUcEntryStruct));
#if defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__)
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VIDEO_CALL_TYPE, NULL))
        {
            ucEntry->msg_type = SRV_UC_MSG_TYPE_SMS_ONLY;
        }
#else /* defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__) */
        {
            ucEntry->msg_type = SRV_UC_MSG_TYPE_DEFAULT;
        }
#endif /* defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__) */
        ucEntry->type = SRV_UC_STATE_WRITE_NEW_MSG;
        ucEntry->launch_mode = UC_LAUNCH_MODE_NORMAL;
    
        // set address
        srv_uc_addr_struct addr;
        addr.next = NULL;
        addr.previous = NULL;
        addr.type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
        addr.addr = (U8*)(number.getBuf());
        addr.group = SRV_UC_ADDRESS_GROUP_TYPE_TO;
        ucEntry->addr_num = 1;
        ucEntry->addr = &addr;
    
        if (sim == MMI_SIM1)
        {
            ucEntry->sim_id = SRV_UC_SIM_ID_GSM_SIM1;
        }
#if (MMI_MAX_SIM_NUM >= 2)
        else if (sim == MMI_SIM2)
        {
            ucEntry->sim_id = SRV_UC_SIM_ID_GSM_SIM2;
        }
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        else if (sim == MMI_SIM3)
        {
            ucEntry->sim_id = SRV_UC_SIM_ID_GSM_SIM3;
        }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        else if (sim == MMI_SIM4)
        {
            ucEntry->sim_id = SRV_UC_SIM_ID_GSM_SIM4;
        }
#endif
        else
        {
            ucEntry->sim_id = (srv_uc_sim_id)sim;
        }
#ifdef __MMI_PHB_NEED_SERIALZE__
        VappPhbUcSerialze param ;

        param.entry = ucEntry;
        param.m_id= m_id;
        param.m_groupId = getApp()->getGroupId();
        param.m_ptr = getApp();

        VfxBool pre_check = vappUcCuiCreatePreCheck(ucEntry, VFX_TRUE);
        kal_prompt_trace(MOD_MMI, "VappPhbViewerProfilePage::createMsg() :pre_check = %d", pre_check);
        if( pre_check)
        {
            getApp()->serialize((void *)PHB_CUI_UC_MESSAGE, VFX_TRUE, vapp_phb_open_uc_cui, &param, sizeof(param), vapp_phb_proxy_proc);
        }
#else
    vappUcAppLauncher(ucEntry);
    mmi_frm_temp_free(ucEntry);
#endif
#endif
#endif
}
#endif /* __MMI_SMS_COMPOSER__ */


void VappPhbViewerProfilePage::sendChildMsg(VcpButton *button, VfxId id)
{
    VappContactFieldItem& item = m_field->getItem(id);

    m_number = m_contact->getNumberById(item.m_fieldId);
    if (srv_sim_ctrl_get_num_of_inserted() == 2 && m_contact->getPreferSim(m_number.getSubId(), VFX_FALSE) != MMI_SIM_NONE)
    {
        for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
        {
            mmi_sim_enum sim = mmi_frm_index_to_sim(i);
            if (srv_sim_ctrl_is_inserted(sim) && sim != m_contact->getPreferSim(m_number.getSubId(), VFX_FALSE))
            {
    #if (defined( __MMI_SMS_COMPOSER__) || defined(__MMI_UNIFIED_COMPOSER__))
                createMsg(m_id, m_number, sim);
    #else
                VappPhbActionObj::sendMessage(m_id, m_number, sim);
    #endif
                break;
            }
        }
    }
    else
    {
        selectSimPopup(VFX_FALSE, m_contact->getPreferSim(m_number.getSubId(), VFX_FALSE));
    }
}


void VappPhbViewerProfilePage::sendEmail(VfxObject *obj, VfxId id)
{
    VappContactFieldItem& item = m_field->getItem(id);

    VappContactEmail email = m_contact->getEmailById(item.m_fieldId);
    VappPhbActionObj::sendEmail(m_id, email);
}


void VappPhbViewerProfilePage::onMoreActionClick(VfxObject *obj, VfxId id)
{
   // kal_prompt_trace(MOD_MMI,"VappPhbViewerProfilePage::onMoreActionClick: id = %d", id);

    if (id == VAPP_PHB_PROFILE_EDIT_BEFORE_CALL)
    {
        MMI_ID cui_id = vcui_dialer_create(getApp()->getGroupId());

        vfxSetCuiCallerScr(cui_id, getMainScr());

        vcui_dialer_set_dial_string(cui_id, m_contact->getNumberById(m_fieldId).getString());
        vcui_dialer_run(cui_id);
    }

#ifdef __MMI_VIDEO_TELEPHONY__
    else if (id == VAPP_PHB_PROFILE_VIDEO_CALL)
    {
        VappContactNumber number = m_contact->getNumberById(m_fieldId);

        VappPhbActionObj::videoCall(m_id, number);
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __MMI_CM_BLACK_LIST__
    else if (id == VAPP_PHB_PROFILE_BLOCK_NUMBER)
    {
        VfxBool clearBlock(VFX_FALSE);
        srv_callset_result_enum result;

        VappContactNumber number = m_contact->getNumberById(m_fieldId);
        VappContactFieldItem& item = m_field->getItem(m_itemId);
        VappPhbViewerNumFormItem *num = (VappPhbViewerNumFormItem *) item.m_obj;

        if (vapp_phb_is_blocked_number(m_id, number))
        {
            result = vapp_phb_delete_from_blacklist(m_id, number);
            if (result == SRV_CALLSET_RESULT_OK)
            {
                num->setBlockIcon(VFX_TRUE);
                clearBlock = VFX_TRUE;
            }
        }
        else
        {
            result = vapp_phb_add_to_blacklist(m_id, number);
            if (result == SRV_CALLSET_RESULT_OK)
            {
                num->setBlockIcon();
            }
        }

        if (result != SRV_CALLSET_RESULT_OK)
        {
            VcpConfirmPopup *comfirm;
            VFX_OBJ_CREATE(comfirm, VcpConfirmPopup, this);

            comfirm->setText(srv_callset_get_result_string_id(result));
            comfirm->setInfoType(VCP_POPUP_TYPE_FAILURE);
            comfirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);

            comfirm->show(VFX_TRUE);
        }

        if (result == SRV_CALLSET_RESULT_OK)
        {
            for (VfxU32 i = 0; i < m_contact->getNumberCount(); i++)
            {
                VappContactFieldItem &fieldItem = m_field->getItem(m_itemIdArray[i]);
                VappPhbViewerNumFormItem *numForm = (VappPhbViewerNumFormItem *) fieldItem.m_obj;
                if (fieldItem.m_fieldId != m_fieldId)
                {
                    VappContactNumber subnum = m_contact->getNumberById(fieldItem.m_fieldId);
                    if (srv_phb_compare_number(subnum.getBuf(), number.getBuf()))
                    {
                        numForm->setBlockIcon(clearBlock);
                    }
                }
            }
        }
    }
#endif /* __MMI_CM_BLACK_LIST__ */
#ifdef __IP_NUMBER__
    if (id == VAPP_PHB_PROFILE_IP_DIAL)
    {
        if (srv_sim_ctrl_get_num_of_inserted() == 1)
        {
            VappContactFieldItem& item = m_field->getItem(m_itemId);
            m_number = m_contact->getNumberById(item.m_fieldId);
            for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
            {
                if (srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(i)))
                {
                    VappPhbActionObj::makeCall(m_id, m_number, mmi_frm_index_to_sim(i), MMI_TRUE);
                }
            }
        }
        else
        {
            simPopupShow(obj, m_itemId);

        }

    }
#endif /* __IP_NUMBER__ */
}


#ifdef __IP_NUMBER__
void VappPhbViewerProfilePage:: simPopupShow(VfxObject *obj, VfxU32 m_itemId)
{

    VappContactFieldItem& item = m_field->getItem(m_itemId);

    m_number = m_contact->getNumberById(item.m_fieldId);

    VcpMenuPopup *cntxMenu;
    VFX_OBJ_CREATE(cntxMenu, VcpMenuPopup, this);
    cntxMenu->setTitle(STR_ID_VAPP_PHB_SELECT_SIM);
    
    for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
    {
        mmi_sim_enum sim = mmi_frm_index_to_sim(i);
        VfxId btnId =  VAPP_PHB_SELECT_SIM_CALL + i ;
        if (srv_sim_ctrl_is_inserted(sim))
        {      
            cntxMenu->addItem(btnId, (VfxResId)VAPP_PHB_STR_CALL, ContactSim::getCallIcon(sim), VCP_MENU_POPUP_ITEM_TYPE_2);
         //cntxMenu->addItem(btnId, VFX_WSTR_RES(VAPP_PHB_STR_CALL), ContactSim::getCallIcon(sim), VCP_MENU_POPUP_ITEM_TYPE_2);
        }
        if (!(srv_mode_switch_get_current_mode() & sim))
        {
                cntxMenu->getItemById(btnId)->setIsDisabled(VFX_TRUE);
        }
    }
    cntxMenu->m_signalMenuCallback.connect(this, &VappPhbViewerProfilePage::onIpSimSelected);
    cntxMenu->show(VFX_TRUE);
}
#endif /* __IP_NUMBER__ */


#ifdef __IP_NUMBER__
void VappPhbViewerProfilePage::onIpSimSelected(VcpMenuPopup* popup, VcpMenuPopupEventEnum flag, VcpMenuPopupItem* item)
{
    if (flag != VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
        return;
    }
    if (item->getId() >= VAPP_PHB_SELECT_SIM_CALL)
    {
        VappPhbActionObj::makeCall(m_id, m_number, mmi_frm_index_to_sim(item->getId()- VAPP_PHB_SELECT_SIM_CALL), MMI_TRUE);
    }
}
#endif /* __IP_NUMBER__ */

void VappPhbViewerProfilePage::moreAction(VfxObject *obj, VfxId id)
{
    VappContactFieldItem& item = m_field->getItem(id);
    m_itemId = id;
    m_fieldId = item.m_fieldId;

    VcpMoreCommandPopup *option;
    VFX_OBJ_CREATE(option, VcpMoreCommandPopup, getMainScr());

    // edit before call
    if (srv_nw_usab_any_sim_is_usable())
    {
        option->addItem(VAPP_PHB_PROFILE_EDIT_BEFORE_CALL, (VfxResId)(STR_GLOBAL_EDIT_BEFORE_CALL), VCP_POPUP_BUTTON_TYPE_NORMAL);
    }

    // make video call
#ifdef __MMI_VIDEO_TELEPHONY__
    if (srv_nw_usab_is_usable(MMI_SIM1))
    {
        option->addItem(VAPP_PHB_PROFILE_VIDEO_CALL, (VfxResId)(STR_ID_VAPP_PHB_VIDEO_CALL), VCP_POPUP_BUTTON_TYPE_NORMAL);
    }
#endif /* __MMI_VIDEO_TELEPHONY__ */

#ifdef __MMI_CM_BLACK_LIST__
    VfxWString text;
    VappContactNumber number;
    
    number = m_contact->getNumberById(m_fieldId);
    if (vapp_phb_is_blocked_number(m_id, number))
    {
        text.loadFromRes(VAPP_PHB_STR_UNBLOCK_NUMBER);
    }
    else
    {
        text.loadFromRes(VAPP_PHB_STR_BLOCK_NUMBER);
    }
    option->addItem(VAPP_PHB_PROFILE_BLOCK_NUMBER, text, VCP_POPUP_BUTTON_TYPE_NORMAL);
#endif
#ifdef __IP_NUMBER__
    option->addItem(VAPP_PHB_PROFILE_IP_DIAL , (VfxResId)(STR_ID_VAPP_CALLSET_IP_NUMBER), VCP_POPUP_BUTTON_TYPE_NORMAL);
    if(srv_sim_ctrl_get_num_of_inserted() == 0 || srv_sim_ctrl_get_one_available_sim() == 0)
    {
        option->disableItem(VAPP_PHB_PROFILE_IP_DIAL);
    }
#endif    
    option->addItem(VAPP_PHB_PROFILE_ACTION_TOTAL, (VfxResId)(STR_GLOBAL_CLOSE), VCP_POPUP_BUTTON_TYPE_CANCEL);

    option->m_signalButtonClicked.connect(this, &VappPhbViewerProfilePage::onMoreActionClick);

    option->show(VFX_TRUE);
}


#ifdef __MMI_VCARD__
void VappPhbViewerProfilePage::onShareSelected(VfxObject *obj, VfxId id)
{
    if (id >= VAPP_PHB_PROFILE_SHARE_TOTAL)
    {
        return;
    }

    if (!vapp_phb_usb_app_is_available())
    {
        return;
    }

    VFX_OBJ_CREATE_EX(m_vcard, VappContactvCard, this, (m_id));

    VfxS32 result;
    m_path = m_vcard->getFile(&result);

    if (m_path == NULL)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
            (WCHAR*)VFX_WSTR_RES(STR_GLOBAL_NOT_ENOUGH_MEMORY).getBuf());
        return;
    }

    switch (id)
    {
        case VAPP_PHB_PROFILE_SHARE_BY_SMS:
        case VAPP_PHB_PROFILE_SHARE_BY_MMS:
        {
    #if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
            VappUcEntryStruct *ucEntry;
            ucEntry = (VappUcEntryStruct*) mmi_frm_temp_alloc(sizeof(VappUcEntryStruct));

            memset(ucEntry, 0, sizeof(VappUcEntryStruct));
            ucEntry->info_type = SRV_UC_INFO_TYPE_VCARD;
            ucEntry->operation = (id == VAPP_PHB_PROFILE_SHARE_BY_SMS) ? UC_OPERATION_SEND_VCARD_AS_SMS : UC_OPERATION_SEND_VCARD_AS_MMS;
            ucEntry->msg_type = (id == VAPP_PHB_PROFILE_SHARE_BY_SMS) ? SRV_UC_MSG_TYPE_SMS_ONLY : SRV_UC_MSG_TYPE_MMS_ONLY;
            ucEntry->type = SRV_UC_STATE_WRITE_NEW_MSG;
            ucEntry->auto_delete_file = TRUE;
            ucEntry->callback_para = this;
            ucEntry->media_num = 1;
            ucEntry->file_path = (U8*) m_path;

            vappUcAppLauncher(ucEntry);

            mmi_frm_temp_free(ucEntry);
            break;
    #endif
        }

    #ifdef __MMI_EMAIL__
        case VAPP_PHB_PROFILE_SHARE_BY_EMAIL:
        {
            mmi_email_app_send_attch_ext((CHAR*) m_path, MMI_TRUE); 
            break;
        }
    #endif /* __MMI_EMAIL__ */

    #ifdef __MMI_OPP_SUPPORT__    
        case VAPP_PHB_PROFILE_SHARE_BY_BT:
        {
            vapp_bt_send_app_info info;
            info.group_id = getApp()->getGroupId();
            info.callback = NULL;
            info.user_data = NULL;

            VfxWChar* pathArray[1];
            pathArray[0] = m_path;

            vapp_bt_send_obj(&info, VAPP_BT_SEND_DELETE_FILE, 1, pathArray);
            break;
        }
    #endif /* __MMI_OPP_SUPPORT__ */
    }

    VFX_OBJ_CLOSE(m_vcard);
}


void VappPhbViewerProfilePage::shareContact()
{
    // check usb mass storage
    if (!vapp_phb_usb_app_is_available())
    {
        return;
    }

    VcpCommandPopup *option;
    VFX_OBJ_CREATE(option, VcpCommandPopup, this);

    option->setText(STR_ID_VAPP_PHB_SHARE_CONTACT);
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

    option->addItem(VAPP_PHB_PROFILE_SHARE_BY_SMS, VFX_WSTR_RES(STR_ID_VAPP_PHB_SHARE_WITH_SMS), VCP_POPUP_BUTTON_TYPE_NORMAL);
    option->addItem(VAPP_PHB_PROFILE_SHARE_BY_MMS, VFX_WSTR_RES(STR_ID_VAPP_PHB_SHARE_WITH_MMS), VCP_POPUP_BUTTON_TYPE_NORMAL);
#endif
#ifdef __MMI_EMAIL__
    option->addItem(VAPP_PHB_PROFILE_SHARE_BY_EMAIL, VFX_WSTR_RES(STR_ID_VAPP_PHB_SHARE_WITH_EMAIL), VCP_POPUP_BUTTON_TYPE_NORMAL);
#endif
#ifdef __MMI_OPP_SUPPORT__
    option->addItem(VAPP_PHB_PROFILE_SHARE_BY_BT, VFX_WSTR_RES(STR_ID_VAPP_PHB_SHARE_WITH_BLUETOOTH), VCP_POPUP_BUTTON_TYPE_NORMAL);
#endif
    option->addItem(VAPP_PHB_PROFILE_SHARE_TOTAL, (VfxResId)(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);

    option->m_signalButtonClicked.connect(this, &VappPhbViewerProfilePage::onShareSelected);

    option->show(VFX_TRUE);
}
#endif /* __MMI_VCARD__*/

void VappPhbViewerProfilePage::onToolBarClick(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case CONTACT_PROFIEL_CMD_EDIT:
        {
            mmi_id cui_id = vcui_phb_contact_saver_create2(getApp()->getGroupId());

            vfxSetCuiCallerScr(cui_id, getMainScr());

            vcui_phb_contact_saver_set_contact_id(cui_id, m_id);
            vcui_phb_contact_saver_run(cui_id);

            m_cui = cui_id;
            if (m_contact->getStorage() == PHB_STORAGE_TCARD)
            {
                m_editTcard = VFX_TRUE;
            }
            break;
        }
    #ifdef __MMI_VCARD__
        case CONTACT_PROFIEL_CMD_SHARE:
        {
            shareContact();
            break;
        }
    #endif /* __MMI_VCARD__*/
        case CONTACT_PROFIEL_CMD_DELETE:
        {
            VappPhbDelete *del;
            VFX_OBJ_CREATE_EX(del, VappPhbDelete, this, (m_id, getMainScr()));
            break;
        }
        case CONTACT_PROFIEL_CMD_COPY:
        {
            VappPhbCopy *copy;
            VFX_OBJ_CREATE_EX(copy, VappPhbCopy, this, (m_id, getMainScr()));
            break;
        }
    #ifdef __MMI_SNS_CONTACTS__
        case CONTACT_PROFILE_CMD_SNS_LINK:
        {
        #ifdef __MMI_USB_SUPPORT__
            if (srv_usb_is_in_mass_storage_mode())
            {
                vapp_usb_unavailable_popup(0);
                return;
            }
        #endif /* __MMI_USB_SUPPORT__ */
            if (!checkAccountsSetting())
            {
                createSettingConfirmPopup();
            }
            else
            {
                snsDoLinked();
            }
            break;
        }

        case CONTACT_PROFILE_CMD_SNS_UNLINK:
        {
        #ifdef __MMI_USB_SUPPORT__
            if (srv_usb_is_in_mass_storage_mode())
            {
                vapp_usb_unavailable_popup(0);
                return;
            }
        #endif /* __MMI_USB_SUPPORT__ */
            snsDoUnlinked();
            break;
        }
   #endif /* __MMI_SNS_CONTACTS__ */
    }
}


mmi_ret VappPhbViewerProfilePage::listener(mmi_event_struct *evt)
{
    VappPhbViewerProfilePage *self = NULL;

    self = (VappPhbViewerProfilePage *)VfxObject::handleToObject((VfxObjHandle) evt->user_data);
    if (self)
    {
        return self->onProc(evt);
    }

    return MMI_RET_OK;
}


#ifdef __MMI_SNS_CONTACTS__
VfxS32 VappPhbViewerProfilePage::loadSnsList(VfxS32 listId, VfxU32 index)
{
    return srv_sns_load_list(listId, index, &VappPhbViewerProfilePage::listener, getObjHandle());
}


void VappPhbViewerProfilePage::disableSnsToolBar(VfxBool isEnable)
{
    m_toolBar->setDisableItem(CONTACT_PROFILE_CMD_SNS_LINK, isEnable);
    m_toolBar->setDisableItem(CONTACT_PROFILE_CMD_SNS_UNLINK, isEnable);
}


void VappPhbViewerProfilePage::refreshForm()
{
    if (m_refresh)
    {
        return; // form is refreshing now
    }

    m_refresh = VFX_TRUE;

    if (m_listId != -1)
    {
        srv_sns_release_list(m_listId, MMI_TRUE);
        m_listId = -1;
    }

    VfxS32 listId = srv_sns_get_friends_by_contact(m_id);
    if (listId > 0)
    {
        if (loadSnsList(listId, 0) == SRV_SNS_OK)
        {
            m_listId = listId;
            disableSnsToolBar(VFX_TRUE);
        }
        else
        {
            disableSnsToolBar(VFX_FALSE);
        }
    }
}


void VappPhbViewerProfilePage::updatePage()
{
    m_b2ndReady = VFX_TRUE;
    createSNS();
}


void VappPhbViewerProfilePage::snsAccountsLinked()
{
    m_toolBar->addItem(CONTACT_PROFILE_CMD_SNS_UNLINK, VFX_WSTR_RES(STR_ID_VAPP_PHB_UNLINK), VAPP_PHB_IMG_CMD_UNLINK);

#if defined(__MMI_SNS_CENTER__) && defined(__MMI_SNS_CONTACTS__)
    VcpTabCtrlPage *ctrlPage = VFX_OBJ_DYNAMIC_CAST(getParentFrame(), VcpTabCtrlPage);
    if (ctrlPage)
    {
       ctrlPage->addTab(VAPP_PHB_VIEWER_SNS, VFX_WSTR_RES(STR_ID_VAPP_SNS_HAPPENINGS), VcpStateImage(IMG_ID_VAPP_SNS_TAB_HAPPENINGS_ICN));
    }
#endif /* __MMI_SNS_CENTER__ && __MMI_SNS_CONTACTS__ */
}


void VappPhbViewerProfilePage::snsAccountsUnlinked()
{
    m_toolBar->removeItem(CONTACT_PROFILE_CMD_SNS_UNLINK);

#if defined(__MMI_SNS_CENTER__) && defined(__MMI_SNS_CONTACTS__)
    VcpTabCtrlPage *ctrlPage = VFX_OBJ_DYNAMIC_CAST(getParentFrame(), VcpTabCtrlPage);
    if (ctrlPage)
    {
        ctrlPage->closeTab(VAPP_PHB_VIEWER_SNS);
    }
#endif /* __MMI_SNS_CENTER__ && __MMI_SNS_CONTACTS__ */
}


void VappPhbViewerProfilePage::snsDoLinked()
{
    createProviderCommandPopup();
}


void VappPhbViewerProfilePage::snsDoUnlinked()
{
    createProviderSelectPopup();
}


void VappPhbViewerProfilePage::onSettingConfirmPopup(VfxObject *obj, VfxId id)
{
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
             {
                 VappSnsAccountSettingsPageExport *obj;
                 VFX_OBJ_CREATE(obj, VappSnsAccountSettingsPageExport, this);
                 VfxPage *page = obj->createInstance(getMainScr());
                 getMainScr()->pushPage(VFX_ID_NULL, page);
                 break;
             }
    }
}


void VappPhbViewerProfilePage::createSettingConfirmPopup()
{
    VcpConfirmPopup *confirm;
    VFX_OBJ_CREATE(confirm, VcpConfirmPopup, this);

    confirm->setText(VFX_WSTR_RES(STR_ID_VAPP_PHB_NO_SNS_ACCOUNT_CONFIRM));
    confirm->setInfoType(VCP_POPUP_TYPE_INFO);
    confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    confirm->setCustomButton(
                VFX_WSTR_RES(STR_ID_VAPP_SNS_ACCOUNTS_SETTINGS),
                VFX_WSTR_RES(STR_GLOBAL_CANCEL),
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                VCP_POPUP_BUTTON_TYPE_CANCEL);

    confirm->m_signalButtonClicked.connect(this, &VappPhbViewerProfilePage::onSettingConfirmPopup);

    confirm->show(VFX_TRUE);
}


VfxBool VappPhbViewerProfilePage::checkAccountsSetting()
{
    VfxU16 count;

    VfxS32 listId = srv_sns_get_accounts(SRV_SNS_LOGIN_TRUE, SRV_SNS_FEATURE_ANY, 0, &count); 

    srv_sns_release_list(listId, MMI_TRUE);

    return (count == 0) ? VFX_FALSE : VFX_TRUE;
}


void VappPhbViewerProfilePage::onProviderCommandClicked(VfxObject *obj, VfxId id)
{
    if (id != SRV_SNS_PROVIDER_ALL)
    {
        mmi_id cuiId = GRP_ID_INVALID;

        cuiId = vcui_sns_contacts_picker_create(getApp()->getGroupId());

        if (cuiId != GRP_ID_INVALID)
        {
            VfxWString text = VFX_WSTR_RES(STR_ID_VAPP_SNS_SELECT_SNS_CONTACT);

            vcui_sns_contacts_picker_set_title(cuiId, VFX_WSTR_RES(STR_ID_VAPP_PHB_SELECT_CONTACT));
            vcui_sns_contacts_picker_set_filter_id(cuiId, MMI_TRUE, id, MMI_FALSE);
            vcui_sns_contacts_picker_set_max_selected_num(cuiId, 1);
            vfxSetCuiCallerScr(cuiId, getMainScr());

            vcui_sns_contacts_picker_run(cuiId);
        }
    }
    else
    {
        disableSnsToolBar(VFX_FALSE);
    }
}


void VappPhbViewerProfilePage::createProviderCommandPopup()
{
    VfxU16 count;
    srv_sns_account_struct *account;
    srv_sns_info_struct *info;

    VfxS32 listId = srv_sns_get_accounts(SRV_SNS_LOGIN_TRUE, SRV_SNS_FEATURE_ANY, 0, &count);
    if (listId < 0)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
            (WCHAR*)VFX_WSTR_RES(srv_sns_get_error_string(listId)).getBuf());
        return;
    }

    VcpCommandPopup *option;
    VFX_OBJ_CREATE(option, VcpCommandPopup, this);

    option->setText(VFX_WSTR_RES(STR_ID_VAPP_PHB_SELECT_ACCOUNT));
    option->setInfoType(VCP_POPUP_TYPE_INFO);

    for (VfxU16 i = 0; i < count; i++)
    {
        srv_sns_get_item(listId, i, (void **)&account);

        option->addItem(account->provider, VFX_WSTR_MEM(account->name), VCP_POPUP_BUTTON_TYPE_NORMAL);
    }

    srv_sns_release_list(listId, MMI_TRUE);

    // disable linked provider
    for (VfxS16 j = m_startIndex; j <= m_endIndex && m_linkedCount > 0; j++)
    {
        srv_sns_get_item(m_listId, j, (void **)&info);

        option->disableItem(info->user.provider);
    }

    option->addItem(SRV_SNS_PROVIDER_ALL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);

    option->m_signalButtonClicked.connect(this, &VappPhbViewerProfilePage::onProviderCommandClicked);

    option->show(VFX_TRUE);
}


void VappPhbViewerProfilePage::onProviderSelectButtonClicked(VfxObject *obj, VfxId buttonId)
{
    srv_sns_user_list_struct list[SRV_SNS_MAX_NUM_FRIENDS_PER_LINKED_CONTACT];

    memset(list, 0, sizeof(srv_sns_user_list_struct) * SRV_SNS_MAX_NUM_FRIENDS_PER_LINKED_CONTACT);

    if (buttonId == VCP_SELECT_POPUP_BUTTON_OK)
    {
        VcpSelectPopup *m_selectPopup = (VcpSelectPopup *)obj;

        for (VfxS32 i = m_selectPopup->getFirstSeletedIndex(); i != -1; i = m_selectPopup->getNextSelectedIndex(i))
        {
            m_linkMark[i] = VFX_TRUE;
        }

        for (VfxU16 j = 0; j < m_providerCount; j++)
        {
            if (m_linkMark[j])
            {
                srv_sns_edit_user_list(list, SRV_SNS_MAX_NUM_FRIENDS_PER_LINKED_CONTACT, m_listId, m_linkIndex[j], MMI_TRUE);
            }
        }

        srv_sns_modify_link_contact(m_id, list, SRV_SNS_MAX_NUM_FRIENDS_PER_LINKED_CONTACT, MMI_FALSE, &VappPhbViewerProfilePage::listener, getObjHandle());
    }
    else
    {
        disableSnsToolBar(VFX_FALSE);
    }
}


void VappPhbViewerProfilePage::createProviderSelectPopup()
{
    VfxU16 count;

    VfxS32 listId = srv_sns_get_accounts(SRV_SNS_LOGIN_DONT_CARE, SRV_SNS_FEATURE_ANY, 0, &count);
    if (listId < 0)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
            (WCHAR*)VFX_WSTR_RES(srv_sns_get_error_string(listId)).getBuf());
        return;
    }

    srv_sns_release_list(listId, MMI_TRUE);

    VcpSelectPopup *m_selectPopup;
    VappPhbSelectCoreMenu *m_radioMenu;

    VFX_OBJ_CREATE(m_radioMenu, VappPhbSelectCoreMenu, this);
    VFX_OBJ_CREATE_EX(m_selectPopup, VcpSelectPopup, this, (m_radioMenu));

    m_selectPopup->setIsAllowedNoSelect(VFX_FALSE);
    m_selectPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_PHB_CHOOSE_TO_UNLINK));
    m_selectPopup->setType(VCP_SELECT_POPUP_BUTTON_TYPE_MULTI);

    m_providerCount = 0;
    srv_sns_info_struct *info;

    for (VfxS16 i = m_startIndex; i <= m_endIndex && m_linkedCount > 0; i++)
    {
        srv_sns_get_item(m_listId, i, (void **)&info);

        m_radioMenu->setProviderId(info->user.provider, m_providerCount);
        m_selectPopup->addItem(info->user.provider, VFX_WSTR_MEM(info->user.user_name), VFX_FALSE);

        m_linkMark[m_providerCount] = VFX_FALSE;
        m_linkIndex[m_providerCount++] = i;
    }

    m_selectPopup->m_signalButtonClicked.connect(this, &VappPhbViewerProfilePage::onProviderSelectButtonClicked);
    m_selectPopup->show(VFX_TRUE);
}

#endif /* __MMI_SNS_CONTACTS__ */


/***************************************************************************** 
 * Class VappPhbLocatorScr
 *****************************************************************************/
VappPhbLocatorScr::VappPhbLocatorScr(mmi_phb_contact_id id): m_id(id)
{
    VFX_ASSERT(ContactEntry::isValid(id));
}


void VappPhbLocatorScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VappPhbViewerProfilePage *page;
    VFX_OBJ_CREATE_EX(page, VappPhbViewerProfilePage, this, (m_id, VFX_TRUE));

    pushPage(VFX_ID_NULL, page);

    ContactTask *task = GET_CONTACT_TASK();
    task->m_signalTask.connect(this, &VappPhbLocatorScr::onContactUpdated);
}


void VappPhbLocatorScr::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


void VappPhbLocatorScr::onContactUpdated(ContactTask* task, mmi_event_struct* evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_PHB_READY:
        {
            srv_phb_startup_evt_struct *ready = (srv_phb_startup_evt_struct*) evt;
            if (!ready->phb_ready)
            {
                exit();
            }
            break;
        }
        case EVT_ID_PHB_UPD_CONTACT:
        {
            // related page should update it's content
            // dispatch the event to sub pages            
            srv_phb_op_evt_struct *op = (srv_phb_op_evt_struct*) evt;
            if (op->store_index == m_id)
            {
                processProc(evt);
            }
            break;
        }
        case EVT_ID_PHB_DEL_CONTACT:
        {
            srv_phb_op_evt_struct *op = (srv_phb_op_evt_struct*) evt;
            if (op->store_index == m_id)
            {
                processProc(evt);
                exit();
            }
            break;
        }
    }
}


/***************************************************************************** 
 * Class VappPhbViewerNameFormItem
 *****************************************************************************/
VappPhbViewerNameFormItem::VappPhbViewerNameFormItem():
    m_name(NULL),
    m_image(NULL),
    m_icon(NULL)
{
}


void VappPhbViewerNameFormItem::onInit()
{
    VcpFormItemBase::onInit();

    // set item height
    setHeight(ICON_SIZE + VCPFRM_SIDE_MARGIN_LARGE + VCPFRM_SIDE_MARGIN_LARGE);

    // create thumbnail image
    VFX_OBJ_CREATE(m_image, VappPhbPhotoCp, this);
    m_image->setAnchor(0, 0);
    m_image->setPos(VCPFRM_SIDE_MARGIN_LARGE, VCPFRM_SIDE_MARGIN_LARGE);
    m_image->setSize(VfxSize(ICON_SIZE, ICON_SIZE));
    m_image->setMaxSize(VfxSize(ICON_SIZE, ICON_SIZE));
    m_image->setDisableClick(VFX_TRUE);

    // create name control
    VFX_OBJ_CREATE(m_name, VappPhbNameCp, this);
    m_name->setAnchor(0, 0.5f);
    m_name->setPos(m_image->getPos().x + m_image->getSize().width + VCPFRM_INDENT_L3, getSize().height/2);
    m_name->setSize(
        getSize().width - (m_image->getPos().x + m_image->getSize().width + VCPFRM_INDENT_L3) - VCPFRM_STD_UI_CNTRL_HEIGHT / 2 - VCPFRM_SIDE_MARGIN_LARGE,
        m_image->getSize().height - VCPFRM_ITEM_HORZ_GAP_2);

    m_name->setAlignParent(
        VFX_FRAME_ALIGNER_SIDE_LEFT,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    m_name->setAlignParent(
        VFX_FRAME_ALIGNER_SIDE_RIGHT,
        VFX_FRAME_ALIGNER_MODE_SIDE);
}


void VappPhbViewerNameFormItem::setName(const VfxWString &name)
{
    m_name->setName(name);
}


#ifdef __MMI_PHB_USIM_SUPPORT__
void VappPhbViewerNameFormItem::setNickname(const VfxWString &nickname)
{
    m_name->setNickname(nickname);
}
#endif /* __MMI_PHB_USIM_SUPPORT__ */


#ifdef __MMI_SNS_CONTACTS__
void VappPhbViewerNameFormItem::setComment(const VfxWString &comment)
{
    m_name->setComment(comment);
}
#endif /* __MMI_SNS_CONTACTS__ */


void VappPhbViewerNameFormItem::setImage(const VfxImageSrc &image)
{
    if (image.isEmpty())
    {
        m_image->setPhoto(VfxImageSrc(VAPP_PHB_IMG_DEFAULT_CONTACT));
    }
    else
    {
        m_image->setPhoto(image);
    }
}


void VappPhbViewerNameFormItem::setIcon(const VfxImageSrc &icon)
{
    VFX_OBJ_CREATE(m_icon, VfxImageFrame, this);
    m_icon->setImgContent(icon);
    m_icon->setAnchor(1.0f, 1.0f);
    m_icon->setPos(getSize().width - (VCPFRM_INDENT_L1 + VCPFRM_INDENT_L2), getSize().height - VCPFRM_SIDE_MARGIN_LARGE);
    m_icon->setSize(icon.getSize());

    m_name->setSize(
        getSize().width - (m_image->getPos().x + m_image->getSize().width + VCPFRM_INDENT_L3) - icon.getSize().width - VCPFRM_SIDE_MARGIN_LARGE,
        m_image->getSize().height - VCPFRM_ITEM_HORZ_GAP_2);

    m_icon->setAlignParent(
        VFX_FRAME_ALIGNER_SIDE_RIGHT,
        VFX_FRAME_ALIGNER_MODE_SIDE);
}


/***************************************************************************** 
 * Class VappPhbViewerNumFormItem
 *****************************************************************************/
void VappPhbViewerNumFormItem::onInit()
{
    VcpFormItemBase::onInit();
}


void VappPhbViewerNumFormItem::onItemBoundsChanged(VfxFrame *frame, const VfxRect& rect)
{
    m_title->setSize(getSize().width/2, VCPFRM_FONT_SIZE_2);
    m_title->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_NONE);

    VfxSize size = m_title->getMeasureBounds().size;
    if (size.width > getSize().width/2)
    {
        m_title->setSize(getSize().width/2, VCPFRM_FONT_SIZE_2);
        m_title->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    }

    m_content->setPos(m_title->getSize().width + m_title->getPos().x, m_title->getSize().height/2 + m_title->getPos().y);
    m_content->setSize(getSize().width - m_title->getSize().width - 2 * VAPP_PHB_FORM_ITEM_LEFT_GAP, VCPFRM_FONT_SIZE_2);

#ifdef __MMI_CM_BLACK_LIST__ // rotate case
    if (m_icon)
    {
        VfxImageSrc iconRes;
        iconRes.setResId(IMG_ID_VAPP_PHB_BLOCK_NUMBER);
        m_content->setSize(getSize().width - m_title->getSize().width - iconRes.getSize().width - 3 * VAPP_PHB_FORM_ITEM_LEFT_GAP, VCPFRM_FONT_SIZE_2);
    }
#endif /* __MMI_CM_BLACK_LIST__ */
}


#ifdef __MMI_CM_BLACK_LIST__
void VappPhbViewerNumFormItem::setBlockIcon(VfxBool reset)
{
    if (reset)
    {
        if (m_icon)
        {
            VFX_OBJ_CLOSE(m_icon);
            m_content->setSize(getSize().width - m_title->getSize().width - 2 * VAPP_PHB_FORM_ITEM_LEFT_GAP, VCPFRM_FONT_SIZE_2);
        }
    }
    else
    {
        VFX_OBJ_CREATE(m_icon, VfxImageFrame, this);
        
        VfxImageSrc iconRes;
        iconRes.setResId(IMG_ID_VAPP_PHB_BLOCK_NUMBER);
        m_icon->setImgContent(iconRes);
        m_icon->setAnchor(1.0f, 0.0f);
        m_icon->setPos(getSize().width - 2 * VAPP_PHB_FORM_ITEM_LEFT_GAP + VCPFRM_INDENT_L1, VAPP_PHB_FORM_ITEM_T0P_GAP);
        m_icon->setSize(iconRes.getSize());
        m_icon->setAlignParent(VFX_FRAME_ALIGNER_SIDE_RIGHT, VFX_FRAME_ALIGNER_MODE_SIDE);

        m_content->setSize(getSize().width - m_title->getSize().width - iconRes.getSize().width - 3 * VAPP_PHB_FORM_ITEM_LEFT_GAP, VCPFRM_FONT_SIZE_2);
    }
}
#endif /* __MMI_CM_BLACK_LIST__ */


void VappPhbViewerNumFormItem::setItemContent(
            const VfxWString &title, const VfxWString &content, mmi_sim_enum call, mmi_sim_enum message)
{
    VFX_OBJ_CREATE(m_title, VfxTextFrame, this);

    m_title->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCPFRM_FONT_SIZE_2)));
    m_title->setColor(VCP_FORM_HINT_TEXT_COLOR);
    m_title->setPos(VAPP_PHB_FORM_ITEM_LEFT_GAP, VAPP_PHB_FORM_ITEM_T0P_GAP);
    m_title->setSize(getSize().width/2, VCPFRM_FONT_SIZE_2);
    m_title->setString(title);

    VfxSize size = m_title->getMeasureBounds().size;
    if (size.width > getSize().width/2)
    {
        m_title->setSize(getSize().width/2, VCPFRM_FONT_SIZE_2);
        m_title->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    }

    VFX_OBJ_CREATE(m_content, VfxTextFrame, this);

    m_content->setAnchor(0.0f, 0.5f);
    m_content->setPos(m_title->getSize().width + m_title->getPos().x, m_title->getSize().height/2 + m_title->getPos().y);
    m_content->setSize(getSize().width - m_title->getSize().width - 2 * VAPP_PHB_FORM_ITEM_LEFT_GAP, VCPFRM_FONT_SIZE_2);
    m_content->setColor(VCP_FORM_DARK_FONT_COLOR);
    m_content->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCPFRM_FONT_SIZE_2)));
    m_content->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

    VfxWString temp = VFX_WSTR("  ");
    temp += content;
    m_content->setString(temp);

    m_signalBoundsChanged.connect(this, &VappPhbViewerNumFormItem::onItemBoundsChanged);

    VFX_OBJ_CREATE(m_btnCall, VcpComboButton, this);

    setButtonInfo(m_btnCall, VFX_TRUE, call);

    VFX_OBJ_CREATE(m_btnMsg, VcpComboButton, this);

    setButtonInfo(m_btnMsg, VFX_FALSE, message);

    VFX_OBJ_CREATE(m_btnMore, VcpButton, this);

    m_btnMore->setPos(VAPP_PHB_FORM_ITEM_LEFT_GAP, m_btnMsg->getPos().y + m_btnMsg->getSize().height + VCPFRM_ITEM_HORZ_GAP_1);
    m_btnMore->setSize(getSize().width - VAPP_PHB_FORM_ITEM_LEFT_GAP * 2, VCPFRM_STD_UI_CNTRL_HEIGHT);
    m_btnMore->setAlignParent(
        VFX_FRAME_ALIGNER_SIDE_LEFT,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    m_btnMore->setAlignParent(
        VFX_FRAME_ALIGNER_SIDE_RIGHT,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_btnMore->setText(STR_GLOBAL_MORE);
    m_btnMore->setImage(VcpStateImage(IMG_ID_VAPP_PHB_MORE_ACTION));
    m_btnMore->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_LEFT);

    setHeight(m_btnMore->getPos().y + m_btnMore->getSize().height + VCPFRM_ITEM_HORZ_GAP_1);
}


void VappPhbViewerNumFormItem::setButtonInfo(VcpComboButton* button, VfxBool call,  mmi_sim_enum sim)
{
    if (call)
    {
        button->setPos(VAPP_PHB_FORM_ITEM_LEFT_GAP, m_title->getPos().y + m_title->getSize().height + VCPFRM_ITEM_HORZ_GAP_1);
    }
    else
    {
        button->setPos(VAPP_PHB_FORM_ITEM_LEFT_GAP, m_btnCall->getPos().y + m_btnCall->getSize().height + VCPFRM_ITEM_HORZ_GAP_1);
    }
    button->setSize(getSize().width - VAPP_PHB_FORM_ITEM_LEFT_GAP * 2, VCPFRM_STD_UI_CNTRL_HEIGHT);
    button->setAlignParent(
        VFX_FRAME_ALIGNER_SIDE_LEFT,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    button->setAlignParent(
        VFX_FRAME_ALIGNER_SIDE_RIGHT,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    button->setText(call ? STR_GLOBAL_DIAL : STR_GLOBAL_MESSAGE);
    if (sim == MMI_SIM_NONE)
    {
        button->setImage(VcpStateImage(call ? IMG_COSMOS_GEMINI_SIM_CALL : IMG_COSMOS_GEMINI_SIM_MSG));
    }
    else
    {
        if (srv_sim_ctrl_get_num_of_inserted() > 1)
        {
            button->setHintText(vapp_sim_settings_get_sim_name(sim));
            if (call)
            {
                button->setImage(VcpStateImage(ContactSim::getCallIconId(sim)));
            }
            else
            {
                button->setImage(VcpStateImage(ContactSim::getMsgIconId(sim)));
            }
        }
        else
        {
            button->setImage(VcpStateImage(call ? IMG_COSMOS_GEMINI_SIM_CALL : IMG_COSMOS_GEMINI_SIM_MSG));
        }
        if (!(srv_mode_switch_get_current_mode() & sim))
        {
            button->setIsOnlyMainBtnDisabled(VFX_TRUE);
        }
    }
    button->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_LEFT);
    if (srv_sim_ctrl_get_num_of_inserted() > 2)
    {
        button->setChildButtonIcon(VcpStateImage(IMG_COSMOS_GEMINI_BUTTON_SIM));
    }
    else if (srv_sim_ctrl_get_num_of_inserted() == 2)
    {
        if (sim == MMI_SIM_NONE)
        {
            button->setChildButtonIcon(VcpStateImage(IMG_COSMOS_GEMINI_BUTTON_SIM));
        }
        else
        {
            for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
            {
                mmi_sim_enum storage = mmi_frm_index_to_sim(i);
                if (srv_sim_ctrl_is_inserted(storage) && storage != sim)
                {
                    if (call)
                    {
                        button->setChildButtonIcon(VcpStateImage(ContactSim::getCallIconId(storage)));
                    }
                    else
                    {
                        button->setChildButtonIcon(VcpStateImage(ContactSim::getMsgIconId(storage)));
                    }
                    if (!(srv_mode_switch_get_current_mode() & storage))
                    {
                        button->setChildIsDisabled(VFX_TRUE);
                        break;
                    }
                }
            }
        }
    }
    else if (srv_sim_ctrl_get_num_of_inserted() == 1)
    {
        button->setHasChildBtn(VFX_FALSE);
        if (sim != MMI_SIM_NONE)
        {
            if (!(srv_mode_switch_get_current_mode() & sim))
            {
                button->setIsDisabled(VFX_TRUE);
            }
        }
        if (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
        {
            button->setIsDisabled(VFX_TRUE);
        }
    }
    else if (srv_sim_ctrl_get_num_of_inserted() == 0)
    {
        button->setHasChildBtn(VFX_FALSE);
        button->setIsDisabled(VFX_TRUE);
    }
}


VcpComboButton* VappPhbViewerNumFormItem::getCallBtn()
{
    return m_btnCall;
}


VcpComboButton* VappPhbViewerNumFormItem::getMsgBtn()
{
    return m_btnMsg;
}


VcpButton* VappPhbViewerNumFormItem::getMoreBtn()
{
    return m_btnMore;
}


/***************************************************************************** 
 * Class VappPhbViewerLabelTextFormItem
 *****************************************************************************/
#if (defined (__MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__) ||defined (__MMI_PHB_INFO_FIELD__)|| defined (__MMI_PHB_MYCARD__)) 
void VappPhbViewerLabelTextFormItem::onInit()
{
    VcpFormItemBase::onInit();

    VFX_OBJ_CREATE(m_label, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_text, VfxTextFrame, this);
}


void VappPhbViewerLabelTextFormItem::onItemBoundsChanged(VfxFrame *frame, const VfxRect &rect)
{
    vfxPostInvoke(this, &VappPhbViewerLabelTextFormItem::changeItemHeight, this);
}


void VappPhbViewerLabelTextFormItem::changeItemHeight(void *p)
{
    setHeight(m_text->getPos().y + m_text->getSize().height + VCPFRM_SIDE_MARGIN_LARGE);
}


void VappPhbViewerLabelTextFormItem::setItemContent(const VfxWString& label, const VfxWString& text)
{
    m_label->setPos(VAPP_PHB_FORM_ITEM_LEFT_GAP, VAPP_PHB_FORM_ITEM_T0P_GAP);
    m_label->setSize(getSize().width, VCPFRM_FONT_SIZE_2);
    m_label->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCPFRM_FONT_SIZE_2)));
    m_label->setColor(VCP_FORM_HINT_TEXT_COLOR);

    VfxWString temp = label;
    temp += VFX_WSTR("  ");
    m_label->setString(temp);
    m_label->setSize(m_label->getMeasureBounds().size);

    m_label->setAlignParent(
        VFX_FRAME_ALIGNER_SIDE_LEFT,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    m_label->setAlignParent(
        VFX_FRAME_ALIGNER_SIDE_RIGHT,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    m_text->setPos(VAPP_PHB_FORM_ITEM_LEFT_GAP, m_label->getPos().y + m_label->getSize().height + VCPFRM_ITEM_HORZ_GAP_1);
    m_text->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCPFRM_FONT_SIZE_2)));
    m_text->setSize(getSize().width - VAPP_PHB_FORM_ITEM_LEFT_GAP * 2, VCPFRM_FONT_SIZE_2);
    m_text->setColor(VCP_FORM_DARK_FONT_COLOR);
    m_text->setString(text);
    m_text->setLineMode(VfxTextFrame::LINE_MODE_MULTI);

    m_text->setAlignParent(
        VFX_FRAME_ALIGNER_SIDE_LEFT,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    m_text->setAlignParent(
        VFX_FRAME_ALIGNER_SIDE_RIGHT,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    setHeight(m_text->getPos().y + m_text->getSize().height + VCPFRM_SIDE_MARGIN_LARGE);
}
#endif  


/***************************************************************************** 
 * Class VappPhbViewerLabelBtnFormItem
 *****************************************************************************/
void VappPhbViewerLabelBtnFormItem::onInit()
{
    VcpFormItemBase::onInit();

    VFX_OBJ_CREATE(m_title, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_content, VfxTextFrame, this);
    VFX_OBJ_CREATE(m_icon, VfxImageFrame, this);
}


void VappPhbViewerLabelBtnFormItem::setStyle(VappPhbViewerLabelBtnFormItemType type)
{
    m_type = type;

    if (type == VAPP_PHB_VIEWER_FORM_ITEM_LABEL_BTN)
    {
        VFX_OBJ_CREATE(m_btn, VcpButton, this);
    }
}


void VappPhbViewerLabelBtnFormItem::onItemBoundsChanged(VfxFrame *frame, const VfxRect& rect)
{
    m_title->setSize(getSize().width/2, VCPFRM_FONT_SIZE_2);
    m_title->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_NONE);

    VfxSize size = m_title->getMeasureBounds().size;
    if (size.width > getSize().width/2)
    {
        m_title->setSize(getSize().width/2, VCPFRM_FONT_SIZE_2);
        m_title->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    }

    m_content->setPos(m_title->getSize().width + m_title->getPos().x, m_title->getSize().height/2 + m_title->getPos().y);
    m_content->setSize(getSize().width - m_title->getSize().width - 2 * VAPP_PHB_FORM_ITEM_LEFT_GAP, VCPFRM_FONT_SIZE_2);

    if (m_type == VAPP_PHB_VIEWER_FORM_ITEM_LABEL_BTN)
    {
        m_btn->setSize(getSize().width - VAPP_PHB_FORM_ITEM_LEFT_GAP * 2, VCPFRM_STANDARD_BTN_HEIGHT);
    }
}


void VappPhbViewerLabelBtnFormItem::setItemContent(const VfxWString &title, const VfxWString &content)
{
    m_title->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCPFRM_FONT_SIZE_2)));
    m_title->setColor(VCP_FORM_HINT_TEXT_COLOR);
    m_title->setPos(VAPP_PHB_FORM_ITEM_LEFT_GAP, VAPP_PHB_FORM_ITEM_T0P_GAP);
    m_title->setSize(getSize().width/2, VCPFRM_FONT_SIZE_2);
    m_title->setString(title);

    VfxSize size = m_title->getMeasureBounds().size;
    if (size.width > getSize().width/2)
    {
        m_title->setSize(getSize().width/2, VCPFRM_FONT_SIZE_2);
        m_title->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    }

    m_content->setAnchor(0.0f, 0.5f);
    m_content->setPos(m_title->getSize().width + m_title->getPos().x, m_title->getSize().height/2 + m_title->getPos().y);
    m_content->setSize(getSize().width - m_title->getSize().width - 2 * VAPP_PHB_FORM_ITEM_LEFT_GAP, VCPFRM_FONT_SIZE_2);
    m_content->setColor(VCP_FORM_DARK_FONT_COLOR);
    m_content->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCPFRM_FONT_SIZE_2)));
    m_content->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

    VfxWString temp = VFX_WSTR("  ");
    temp += content;
    m_content->setString(temp);

    m_signalBoundsChanged.connect(this, &VappPhbViewerLabelBtnFormItem::onItemBoundsChanged);

    if (m_type == VAPP_PHB_VIEWER_FORM_ITEM_LABEL_BTN)
    {
        m_btn->setPos(VAPP_PHB_FORM_ITEM_LEFT_GAP, m_title->getPos().y + m_title->getSize().height + VCPFRM_ITEM_HORZ_GAP_1);
        m_btn->setSize(getSize().width - VAPP_PHB_FORM_ITEM_LEFT_GAP * 2, VCPFRM_STANDARD_BTN_HEIGHT);
        m_btn->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY_LEFT);

        setHeight(m_btn->getPos().y + VCPFRM_STANDARD_BTN_HEIGHT + VCPFRM_ITEM_HORZ_GAP_1);
    }
    else
    {
        setHeight(m_content->getPos().y + m_content->getSize().height + VCPFRM_ITEM_HORZ_GAP_1);
    }
}


VcpButton *VappPhbViewerLabelBtnFormItem::getButton()
{
    return m_btn;
}


#ifdef __MMI_SNS_CONTACTS__
/***************************************************************************** 
 * Class VappPhbSelectCoreMenu
 *****************************************************************************/
void VappPhbSelectCoreMenu::setProviderId(VfxU32 providerId, VfxU32 index)
{
    VFX_ASSERT(index < SRV_SNS_MAX_NUM_FRIENDS_PER_LINKED_CONTACT);
    m_providerId[index] = providerId;
}


VfxU32 VappPhbSelectCoreMenu::getProviderId(VfxU32 index)
{
    VFX_ASSERT(index < SRV_SNS_MAX_NUM_FRIENDS_PER_LINKED_CONTACT);
    return m_providerId[index];
}


VfxBool VappPhbSelectCoreMenu::getItemImage(
            VfxU32 index,                    // [IN] the position of item
            VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
            VfxImageSrc &image               // [OUT] the image resource
            )
{
    VfxU32 providerId = getProviderId(index);
    VfxWChar *path = srv_sns_get_provider_icon(providerId, SRV_SNS_LOGO_SMALL);

    if (path)
    {
        image.setPath(path);

        return VFX_TRUE;
    }

    return VFX_FALSE;
}


void VappPhbSelectCoreMenu::update()
{
    setContentProvider(this);
    setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT_EX);
}

#endif /* __MMI_SNS_CONTACTS__ */

