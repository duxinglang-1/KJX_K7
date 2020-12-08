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
 *  vapp_phb_launch.cpp
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "mmi_rp_vapp_fmgr_def.h"

#include "vfx_adp_device.h"

#include "vapp_phb_launch.h"
#include "vapp_phb_multi.h"
#include "vapp_phb_editor.h"
#include "vapp_phb_info.h"
#include "vapp_phb_group.h"
#include "vapp_phb_mycard.h"
#include "vapp_phb_setting.h"
#include "vapp_contact_task.h"
#include "vapp_phb_cui.h"
#include "vapp_phb_app.h"
#include "vapp_phb_copy_delete.h"
#include "vapp_dialer_main.h"
#include "vapp_uc_gprot.h"
#include "vapp_sim_setting_gprot.h"
#include "vapp_phb_gprot.h"
#include "mmi_rp_app_usbsrv_def.h"

#ifdef __MMI_SMS_COMPOSER__
#include "vcui_sms_composer_gprot.h"
#endif
#ifdef __MMI_SNS_CONTACTS__
#include "vapp_sns_gprot.h"
#endif

#ifdef __cplusplus
extern "C"
{

#include "SimCtrlSrvGprot.h"
#include "NwUsabSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "mmi_rp_vapp_calllog_def.h"


}
#endif


/***************************************************************************** 
 * Class VappPhbApp
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappPhbApp", VappPhbApp, VfxApp);

VappPhbApp::VappPhbApp():
    m_subAppId(VAPP_PHB_SUB_APP_CONTACT),
    m_clogUserData(NULL),
    m_dialerUserData((void *)((S32)VFX_KEY_CODE_UNKNOWN)),
    m_contactUserData(NULL)
{
}


void VappPhbApp::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    if (args)
    {
        VFX_ASSERT(argSize == sizeof(vapp_phb_sub_app_launch_struct));
        vapp_phb_sub_app_launch_struct *param = (vapp_phb_sub_app_launch_struct *)args;

        setSubAppId(param->sub_app);
        setUserData(param->user_data);
    }

    VappPhbScr *scr;
    VFX_OBJ_CREATE(scr, VappPhbScr, this);

    scr->show();
}


void VappPhbApp::setSubAppId(vapp_phb_sub_app_type_enum id)
{
    m_subAppId = id;
}


vapp_phb_sub_app_type_enum VappPhbApp::getSubAppId()
{
    return m_subAppId;
}


void VappPhbApp::setUserData(void* userData)
{
    switch (m_subAppId)
    {
        case VAPP_PHB_SUB_APP_CLOG:
            m_clogUserData = userData;
            break;

        case VAPP_PHB_SUB_APP_DIAL:
            m_dialerUserData = userData;
            break;

        case VAPP_PHB_SUB_APP_CONTACT:
            m_contactUserData = userData;
            break;
    }
}


void* VappPhbApp::getUserData(vapp_phb_sub_app_type_enum id)
{
    void* data = NULL;

    switch (id)
    {
        case VAPP_PHB_SUB_APP_CLOG:
            data = m_clogUserData;
            break;

        case VAPP_PHB_SUB_APP_DIAL:
            data = m_dialerUserData;
            break;

        case VAPP_PHB_SUB_APP_CONTACT:
            data = m_contactUserData;
            break;
    }

    return data;
}


/***************************************************************************** 
 * Class VappPhbScr
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappPhbScr", VappPhbScr, VfxMainScr);

VappPhbScr::VappPhbScr() :
    m_page(NULL)
{
    setAppContextShareForVrt(VFX_TRUE);
}


void VappPhbScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VFX_OBJ_CREATE(m_page, VappPhbPage, this);

    pushPage(VFX_ID_NULL, m_page);

    ContactTask *task = GET_CONTACT_TASK();
    task->m_signalTask.connect(this, &VappPhbScr::onContactEvent);
}


void VappPhbScr::on2ndReady()
{
    VfxMainScr::on2ndReady();

    VappPhbApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappPhbApp);
    ((VappPhbPage*) m_page)->m_b2ndReady = VFX_TRUE;
    ((VappPhbPage*) m_page)->updatePage(app->getSubAppId());
}


void VappPhbScr::onContactEvent(ContactTask *task, mmi_event_struct *evt)
{
    // transfer the event to pages
    processProc(evt);
}


void VappPhbScr::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


/***************************************************************************** 
 * Class VappPhbPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappPhbPage", VappPhbPage, VcpTabCtrlPage);

void VappPhbPage::onInit()
{
    VcpTabCtrlPage::onInit();

    VfxBool addFlag = VFX_FALSE;
    VappPhbApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappPhbApp);
    m_b2ndReady = VFX_FALSE;

    if (app->getSubAppId() != VAPP_PHB_SUB_APP_PIM_MANAGER)
    {
    #ifdef __MMI_SNS_CONTACTS__
        if (app->getSubAppId() == VAPP_PHB_SUB_APP_CONTACT)
        {
            addFlag = VFX_TRUE;
            addTab(VAPP_PHB_SUB_APP_CONTACT, VFX_WSTR_RES(VAPP_PHB_STR_LOCAL), VcpStateImage(VAPP_PHB_IMG_TAB_LOCAL));
            addTab(VAPP_PHB_SUB_APP_SNS, VFX_WSTR_RES(VAPP_PHB_STR_SNS), VcpStateImage(VAPP_PHB_IMG_TAB_SNS));
        }
    #endif /* __MMI_SNS_CONTACTS__ */
        if (!addFlag)
        {
            addTab(VAPP_PHB_SUB_APP_DIAL, (VfxResId)(VAPP_PHB_STR_DIAL), VcpStateImage(VAPP_PHB_IMG_TAB_DIALPAD));
            addTab(VAPP_PHB_SUB_APP_CLOG, (VfxResId)(VAPP_PHB_STR_CLOGS), VcpStateImage(VAPP_PHB_IMG_TAB_CLOG));
            addTab(VAPP_PHB_SUB_APP_CONTACT, (VfxResId)(VAPP_PHB_STR_CONTACTS), VcpStateImage(VAPP_PHB_IMG_TAB_CONTACT));
        }
    }
    else
    {
        addTab(VAPP_PHB_SUB_APP_PIM_MANAGER, (VfxResId)(VAPP_PHB_STR_CONTACTS), VcpStateImage(VAPP_PHB_IMG_TAB_CONTACT));
    }

    // show related sub application
    setCurrTab(app->getSubAppId());
}


#ifdef __MMI_SNS_CONTACTS__
// [workaround-VcpTabCtrlPage can't provide correct entered timing]
void VappPhbPage::onEntered()
{
    VappSnsContactListPage *page = VFX_OBJ_DYNAMIC_CAST(getTabPage(getCurrTab()), VappSnsContactListPage);

    if (page)
    {
        return page->onSubPageEntered();
    }

    return VcpTabCtrlPage::onEntered();
}
#endif /*__MMI_SNS_CONTACTS__*/


VfxPage* VappPhbPage::onCreateTabPage(VfxId tabId)
{
    // set current sub app
    VappPhbApp *app = VFX_OBJ_DYNAMIC_CAST(getApp(), VappPhbApp);
    app->setSubAppId((vapp_phb_sub_app_type_enum)tabId);

    // create tab
    VfxPage *page = NULL;

    switch (tabId)
    {
    case VAPP_PHB_SUB_APP_DIAL:
        VFX_OBJ_CREATE(page, VappDialerPage, this);
        m_dialerPage = page;
        break;

    case VAPP_PHB_SUB_APP_CLOG:
        VFX_OBJ_CREATE_EX(page, VappCLogList, this, (VAPP_CLOG_PAGE_BASIC, VFX_TRUE));
        m_clogPage = page;
        break;

    case VAPP_PHB_SUB_APP_CONTACT:
        VFX_OBJ_CREATE(page, VappPhbListTabPage, this);
        m_contactPage = page;
        break;

#ifdef __MMI_MOBILE_SERVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MOBILE_SERVICE__ */

 #ifdef __MMI_SNS_CONTACTS__
    case VAPP_PHB_SUB_APP_SNS:
        VFX_OBJ_CREATE(page, VappSnsContactListPage, this); 
        ((VappSnsContactListPage *)page)->enableMeContact(VFX_TRUE);
        break;
 #endif /* __MMI_SNS_CONTACTS__ */

    default:
        VFX_ASSERT(0);
        break;
    }

    return page;
}


void VappPhbPage::onTabSwitched(VfxId tabId)
{
    if (!m_b2ndReady)
    {
        return;
    }

    updatePage(tabId);
}


void VappPhbPage::updatePage(VfxId tabId)
{
    switch (tabId)
    {
    case VAPP_PHB_SUB_APP_DIAL:
        //((VappDialerPage*) m_dialerPage)->updatePage();
        break;

    case VAPP_PHB_SUB_APP_CLOG:
        ((VappCLogList*) m_clogPage)->updatePage();
        break;

    case VAPP_PHB_SUB_APP_CONTACT:
        ((VappPhbListTabPage*) m_contactPage)->updatePage();
        break;

#ifdef __MMI_MOBILE_SERVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MOBILE_SERVICE__ */

#ifdef __MMI_SNS_CONTACTS__
    case VAPP_PHB_SUB_APP_SNS:
    {
        VappSnsContactListPage *page = VFX_OBJ_DYNAMIC_CAST(getTabPage(getCurrTab()), VappSnsContactListPage);

        if (page)
        {
            page->onSubPageEntered();
        }
        break;
    }
 #endif /* __MMI_SNS_CONTACTS__ */

    default:
        VFX_ASSERT(0);
        break;
    }
}


/***************************************************************************** 
 * Class VappPhbListTabPage
 *****************************************************************************/
VappPhbListTabPage::VappPhbListTabPage():
    m_toolBar(NULL),
    m_list(NULL),
    m_cmdObj(NULL)
{
    m_cmd = VAPP_PHB_MARK_CMD_NONE;
#ifdef __LOW_COST_SUPPORT_COMMON__
    m_searchText = VFX_WSTR_EMPTY;
    m_recreatePhbForm = VFX_FALSE;
    m_setHistory = VFX_FALSE;
#endif /* __LOW_COST_SUPPORT_COMMON__ */
}


void VappPhbListTabPage::onInit()
{
    VfxPage::onInit();

    // tool bar
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    setBottomBar(m_toolBar);

    m_toolBar->addItem(VAPP_PHB_LIST_CMD_ADD, (VfxResId)(VAPP_PHB_STR_ADD_CONTACT), VAPP_PHB_IMG_CMD_ADD_CONTACT);
#ifdef __MMI_PHB_CALLER_GROUP__    
    m_toolBar->addItem(VAPP_PHB_LIST_CMD_GROUP, VFX_WSTR_RES(VAPP_PHB_STR_GROUPS), VAPP_PHB_IMG_CMD_GROUP);
#endif
#if defined (__MMI_OPP_SUPPORT__) && defined (__MMI_VCARD__)
    m_toolBar->addItem(VAPP_PHB_LIST_CMD_SHARE, VFX_WSTR_RES(VAPP_PHB_STR_SHARE), IMG_ID_VAPP_FMGR_SHARE_BY_BT);
#endif /* __MMI_OPP_SUPPORT__  && __MMI_VCARD__*/   
    m_toolBar->addItem(VAPP_PHB_LIST_CMD_DELETE, VFX_WSTR_RES(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
#ifdef __MMI_PHB_MARK_MESSAGE__
    m_toolBar->addItem(VAPP_PHB_LIST_CMD_MESSAGE, VFX_WSTR_RES(VAPP_PHB_STR_MESSAGE), VAPP_PHB_IMG_CMD_MESSAGE);
#endif /* __MMI_PHB_MARK_MESSAGE__*/
#ifdef __MMI_PHB_MYCARD__  
    m_toolBar->addItem(VAPP_PHB_LIST_CMD_MYCARD, VFX_WSTR_RES(VAPP_PHB_STR_MYCARD), VAPP_PHB_IMG_CMD_CARD);
#endif /* __MMI_PHB_MYCARD__ */
    m_toolBar->addItem(VAPP_PHB_LIST_CMD_SETTING, (VfxResId)(STR_GLOBAL_SETTINGS), VCP_IMG_TOOL_BAR_COMMON_ITEM_SETTING);

    // list menu
    VFX_OBJ_CREATE_EX(m_list, VappPhbListCp, this, (VFX_TRUE));
    m_list->setSize(getSize());
    m_list->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    m_list->setListStorageType(VAPP_PHB_LIST_STORAGE_TYPE_ENTRY);
    // signal
    m_list->m_signalItemTapped.connect(this, &VappPhbListTabPage::onItemTaped);
    m_list->m_signalItemLongTapped.connect(this, &VappPhbListTabPage::onItemLongTaped);
    m_list->m_signalCount.connect(this, &VappPhbListTabPage::onCountChanged);
    m_toolBar->m_signalButtonTap.connect(this, &VappPhbListTabPage::onToolBarClick);
    mmi_frm_cb_reg_event(EVT_ID_VAPP_CLOG_APP_ENTER, &VappPhbListTabPage::listener, getObjHandle());
    onCountChanged(m_list, 0); // disable before phb data ready
}


mmi_ret VappPhbListTabPage::listener(mmi_event_struct *evt)
{
    VappPhbListTabPage *self = NULL;

    self = (VappPhbListTabPage *)VfxObject::handleToObject((VfxObjHandle) evt->user_data);
    if (self)
    {
        return self->onProc(evt);
    }
    return MMI_RET_OK;
}


void VappPhbListTabPage::onBack()
{
    if (m_cmd == VAPP_PHB_MARK_CMD_DELETE
#ifdef __MMI_PHB_MARK_MESSAGE__
        || m_cmd == VAPP_PHB_MARK_CMD_MESSAGE
#endif
#if defined (__MMI_OPP_SUPPORT__) && defined (__MMI_VCARD__)
        || m_cmd == VAPP_PHB_MARK_CMD_SHARE
#endif
        )
    {
        onCmdEnd(m_cmd);

        VFX_OBJ_CLOSE(m_cmdObj);
    }
    else
    {
        VfxPage::onBack();
    }
}


void VappPhbListTabPage::onCountChanged(VappPhbListCp* list, VfxU32 count)
{
    if (count == 0)
    {
#if defined (__MMI_OPP_SUPPORT__) && defined (__MMI_VCARD__)
        m_toolBar->setDisableItem(VAPP_PHB_LIST_CMD_SHARE, VFX_TRUE);
#endif /* __MMI_OPP_SUPPORT__ &&__MMI_VCARD__ */
        m_toolBar->setDisableItem(VAPP_PHB_LIST_CMD_DELETE, VFX_TRUE);
#ifdef __MMI_PHB_MARK_MESSAGE__
        m_toolBar->setDisableItem(VAPP_PHB_LIST_CMD_MESSAGE, VFX_TRUE);
#endif /* __MMI_PHB_MARK_MESSAGE__ */
    }
    else
    {
#if defined (__MMI_OPP_SUPPORT__) && defined (__MMI_VCARD__)
        m_toolBar->setDisableItem(VAPP_PHB_LIST_CMD_SHARE, VFX_FALSE);
#endif /* __MMI_OPP_SUPPORT__  &&  __MMI_VCARD__ */
        m_toolBar->setDisableItem(VAPP_PHB_LIST_CMD_DELETE, VFX_FALSE);
#ifdef __MMI_PHB_MARK_MESSAGE__
        m_toolBar->setDisableItem(VAPP_PHB_LIST_CMD_MESSAGE, VFX_FALSE);

#endif /* __MMI_PHB_MARK_MESSAGE__ */  
#if defined ( __LOW_COST_SUPPORT_COMMON__ )|| defined (__MMI_CONTACT_SLIM__)
        if (m_setHistory)
        {
            m_list->setHistory(&m_listHistory);
            m_setHistory = VFX_FALSE;
        }
#endif /* __LOW_COST_SUPPORT_COMMON__ */  
    }
}


void VappPhbListTabPage::onItemTaped(VcpGroupListMenu *list, VcpMenuPos pos)
{
    if (pos.group >= 0 && pos.pos >= 0)
    {
        // contact viewer cui
        mmi_id cui_id = vcui_phb_contact_viewer_create(getApp()->getGroupId());
        vcui_phb_contact_viewer_set_contact_id(cui_id, m_list->getId(pos.pos, pos.group));
        vfxSetCuiCallerScr(cui_id, getMainScr());
        vcui_phb_contact_viewer_run(cui_id);
    }
}


void VappPhbListTabPage::onItemLongTaped(VcpGroupListMenu *list, VcpMenuPos pos)
{
    if (pos.group >= 0 && pos.pos >= 0)
    {
        m_id = m_list->getId(pos.pos, pos.group);
        ContactEntry entry(m_id);

        VcpMenuPopup *option;
        VFX_OBJ_CREATE(option, VcpMenuPopup, getMainScr());

        if (entry.getName().getString().isEmpty())
        {
            option->setTitle(VAPP_PHB_STR_UNNAMED);
        }
        else
        {
            option->setTitle(entry.getName().getString());
        }

        // call
        VfxU32 count = entry.getNumber();
        for (VfxU32 i = 0; i < count; i++)
        {
            VappContactNumber number = entry.getNextNumber();
            mmi_sim_enum sim = entry.getPreferSim(number.getSubId());
            VfxId id = VAPP_PHB_MORE_ACTION_CALL + number.getSubId();
            VfxWString text = VFX_WSTR_RES(STR_ID_VAPP_PHB_CALL_TO);
            text += number.getString();
            if (sim == MMI_SIM_NONE)
            {
                option->addItem(id, text);
            }
            else
            {
                if (!(srv_mode_switch_get_current_mode() & sim) || srv_sim_ctrl_get_num_of_inserted() <= 1)
                {
                    option->addItem(id, text);
                }
                else
                {
                    option->addItem(id, text, VfxImageSrc(ContactSim::getIcon(sim)));
                }
            }
            if (srv_sim_ctrl_get_num_of_inserted() == 0 ||
                (srv_sim_ctrl_get_num_of_inserted() == 1 && sim != MMI_SIM_NONE && (!(srv_mode_switch_get_current_mode() & sim))))
            {
                ((VcpMenuPopupItem*)option->getItemById(id))->setIsDisabled(VFX_TRUE);
            }
        }

        // message
        count = entry.getNumber();
        for (VfxU32 i = 0; i < count; i++)
        {
            VappContactNumber number = entry.getNextNumber();
            mmi_sim_enum sim = entry.getPreferSim(number.getSubId(), VFX_FALSE);
            VfxId id = VAPP_PHB_MORE_ACTION_MESSAGE + number.getSubId();
            VfxWString text = VFX_WSTR_RES(STR_ID_VAPP_PHB_MESSAGE_TO);
            text += number.getString();
            if (sim == MMI_SIM_NONE)
            {
                option->addItem(id, text);
            }
            else
            {
                if (!(srv_mode_switch_get_current_mode() & sim) || srv_sim_ctrl_get_num_of_inserted() <= 1)
                {
                    option->addItem(id, text);
                }
                else
                {
                    option->addItem(id, text, VfxImageSrc(ContactSim::getIcon(sim)));
                }
            }
            if (srv_sim_ctrl_get_num_of_inserted() == 0 ||
                (srv_sim_ctrl_get_num_of_inserted() == 1 && sim != MMI_SIM_NONE && (!(srv_mode_switch_get_current_mode() & sim))))
            {
                ((VcpMenuPopupItem*)option->getItemById(id))->setIsDisabled(VFX_TRUE);
            }
        }

        option->addItem(VAPP_PHB_MORE_ACTION_EDIT, (VfxResId)(VAPP_PHB_STR_EDIT_CONTACT));
        option->addItem(VAPP_PHB_MORE_ACTION_DELETE, (VfxResId)(STR_GLOBAL_DELETE));

        option->show(VFX_TRUE);
        option->m_signalMenuCallback.connect(this, &VappPhbListTabPage::onContextMenuSelected);

        vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
    }
}


#if defined ( __MMI_SMS_COMPOSER__) ||defined(__MMI_UNIFIED_COMPOSER__)
void VappPhbListTabPage::createMsg(mmi_phb_contact_id id, VappContactNumber& number, mmi_sim_enum sim)
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
        ucEntry = (VappUcEntryStruct*) mmi_frm_temp_alloc(sizeof(VappUcEntryStruct));
    
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
       mmi_id m_groupId =  getApp()->getGroupId();

    if (m_groupId == mmi_frm_get_root_app(m_groupId))
    {
        VfxBool pre_check = vappUcAppLauncherPreCheck(ucEntry, VFX_TRUE);
        if(pre_check)
        {
            VfxU32 expUsedSize = mmi_res_get_app_heap_size(m_groupId);
            mmi_frm_asm_base_shrink_size(m_groupId,expUsedSize);
            //kal_prompt_trace(MOD_MMI, "mmi_frm_asm_base_shrink_size : m_groupId= %d , expUsedSize = %d", m_groupId, expUsedSize);
           
        }
    }
#endif
    vappUcAppLauncher(ucEntry);
    mmi_frm_temp_free(ucEntry);

#endif
#endif
}
#endif /* __MMI_SMS_COMPOSER__ */


void VappPhbListTabPage::selectSimPopup(VfxBool call, mmi_sim_enum sim)
{
    VcpMenuPopup *cntxMenu;
    VFX_OBJ_CREATE(cntxMenu, VcpMenuPopup, this);
    cntxMenu->setTitle(STR_ID_VAPP_PHB_SELECT_SIM);

    for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
    {
        mmi_sim_enum storage = mmi_frm_index_to_sim(i);
        if (srv_sim_ctrl_is_inserted(storage))
        {
            VfxId btnId = call ? VAPP_PHB_MORE_ACTION_SELECT_SIM_CALL + i : VAPP_PHB_MORE_ACTION_SELECT_SIM_MSG + i;
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

    cntxMenu->m_signalMenuCallback.connect(this, &VappPhbListTabPage::onSimSelected);
    cntxMenu->show(VFX_TRUE);
}


void VappPhbListTabPage::onSimSelected(VcpMenuPopup* popup, VcpMenuPopupEventEnum flag, VcpMenuPopupItem* item)
{
    if (flag != VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
        return;
    }

    if (item->getId() >= VAPP_PHB_MORE_ACTION_SELECT_SIM_MSG)
    {
#if defined ( __MMI_SMS_COMPOSER__) ||defined(__MMI_UNIFIED_COMPOSER__)
        createMsg(m_id, m_number, mmi_frm_index_to_sim(item->getId() - VAPP_PHB_MORE_ACTION_SELECT_SIM_MSG));
#else
        VappPhbActionObj::sendMessage(m_id, m_number, mmi_frm_index_to_sim(item->getId() - VAPP_PHB_MORE_ACTION_SELECT_SIM_MSG));
#endif
    }
    else if (item->getId() >= VAPP_PHB_MORE_ACTION_SELECT_SIM_CALL)
    {
        VappPhbActionObj::makeCall(m_id, m_number, mmi_frm_index_to_sim(item->getId() - VAPP_PHB_MORE_ACTION_SELECT_SIM_CALL));
    }
}


void VappPhbListTabPage::onContextMenuSelected(VcpMenuPopup* popup, VcpMenuPopupEventEnum flag, VcpMenuPopupItem* item)
{
    if (flag != VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
        return;
    }

    switch (item->getId())
    {
        case VAPP_PHB_MORE_ACTION_DELETE:
        {
            VappPhbDelete *del;
            VFX_OBJ_CREATE_EX(del, VappPhbDelete, this, (m_id, getMainScr()));
            break;
        }
        case VAPP_PHB_MORE_ACTION_EDIT:
        {
            mmi_id cui_id = vcui_phb_contact_saver_create2(getApp()->getGroupId());

            if (cui_id != GRP_ID_INVALID)
            {
                vcui_phb_contact_saver_set_type(cui_id, VAPP_PHB_SAVE_CONTACT_EDIT);
                vcui_phb_contact_saver_set_contact_id(cui_id, m_id);
                vfxSetCuiCallerScr(cui_id, getMainScr());
                vcui_phb_contact_saver_run(cui_id);
            }
            break;
        }
        default:
        {
            ContactEntry entry(m_id);

            // call
            if (item->getId() < VAPP_PHB_MORE_ACTION_MESSAGE)
            {
                m_number = entry.getNumberById(item->getId() - VAPP_PHB_MORE_ACTION_CALL);
                mmi_sim_enum sim = entry.getPreferSim(m_number.getSubId());
                if (sim != MMI_SIM_NONE && (srv_mode_switch_get_current_mode() & sim))
                {
                    VappPhbActionObj::makeCall(m_id, m_number, sim);
                }
                else if (sim == MMI_SIM_NONE && srv_sim_ctrl_get_num_of_inserted() == 1)
                {
                    for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
                    {
                        if (srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(i)))
                        {
                            VappPhbActionObj::makeCall(m_id, m_number, mmi_frm_index_to_sim(i));
                        }
                    }
                }
                else
                {
                    selectSimPopup(VFX_TRUE, sim);
                }
            }
            // send message
            else
            {
                m_number = entry.getNumberById(item->getId() - VAPP_PHB_MORE_ACTION_MESSAGE);
                mmi_sim_enum sim = entry.getPreferSim(m_number.getSubId(), VFX_FALSE);
                if (sim != MMI_SIM_NONE && (srv_mode_switch_get_current_mode() & sim))
                {
            #if defined ( __MMI_SMS_COMPOSER__) ||defined(__MMI_UNIFIED_COMPOSER__)
                    createMsg(m_id, m_number, sim);
            #else
                    VappPhbActionObj::sendMessage(m_id, m_number, sim);
            #endif
                }
                else if (sim == MMI_SIM_NONE && srv_sim_ctrl_get_num_of_inserted() == 1)
                {
                    for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
                    {
                        if (srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(i)))
                        {
                    #if defined ( __MMI_SMS_COMPOSER__) ||defined(__MMI_UNIFIED_COMPOSER__)
                            createMsg(m_id, m_number, mmi_frm_index_to_sim(i));
                    #else
                            VappPhbActionObj::sendMessage(m_id, m_number, mmi_frm_index_to_sim(i));
                    #endif
                        }
                    }
                }
                else
                {
                    selectSimPopup(VFX_FALSE, sim);
                }
            }
        }
    }
}


void VappPhbListTabPage::onToolBarClick(VfxObject *obj, VfxId id)
{
    switch (id)
    {
        case VAPP_PHB_LIST_CMD_ADD:
        {
            mmi_id cui_id = vcui_phb_contact_saver_create2(getApp()->getGroupId());
            if (cui_id != GRP_ID_INVALID)
            {
                vcui_phb_contact_saver_set_type(cui_id, VAPP_PHB_SAVE_CONTACT_NEW);
                vfxSetCuiCallerScr(cui_id, getMainScr());
                vcui_phb_contact_saver_run(cui_id);
            }
            break;
        }
#ifdef __MMI_PHB_CALLER_GROUP__
        case VAPP_PHB_LIST_CMD_GROUP:
        {
            if (!vapp_phb_ready_balloon())
            {
                return;
            }

            VappPhbGroupScr *group;
            VFX_OBJ_CREATE(group, VappPhbGroupScr, getMainScr()->getApp());
            group->show();
            break;
        }
#endif   
#if defined (__MMI_OPP_SUPPORT__) && defined (__MMI_VCARD__)
        case VAPP_PHB_LIST_CMD_SHARE:
        {
            // check usb mass storage
            if (!vapp_phb_usb_app_is_available())
            {
                return;
            }

            VappPhbMarkShareObj *obj;
            VFX_OBJ_CREATE_EX(obj, VappPhbMarkShareObj, this, (m_list, this, this));

            m_cmdObj = obj;
            break;
        }
#endif /* __MMI_OPP_SUPPORT__ && __MMI_VCARD__*/
        case VAPP_PHB_LIST_CMD_DELETE:
        {
            VappPhbMarkDeleteObj *obj;
            VFX_OBJ_CREATE_EX(obj, VappPhbMarkDeleteObj, this, (m_list, this, this));

            m_cmdObj = obj;
            break;
        }
#ifdef __MMI_PHB_MARK_MESSAGE__
        case VAPP_PHB_LIST_CMD_MESSAGE:
        {
            VappPhbMarkMsgObj *obj;
            VFX_OBJ_CREATE_EX(obj, VappPhbMarkMsgObj, this, (m_list, this, this));

            m_cmdObj = obj;
            break;
        }
#endif /* __MMI_PHB_MARK_MESSAGE__ */

#ifdef __MMI_PHB_MYCARD__
        case VAPP_PHB_LIST_CMD_MYCARD:
        {
            VappPhbMycardScr *mycard;
            VFX_OBJ_CREATE(mycard, VappPhbMycardScr, getMainScr()->getApp());
            mycard->show();
            break;
        }
#endif /* __MMI_PHB_MYCARD__ */
        case VAPP_PHB_LIST_CMD_SETTING:
        {
#ifdef __MMI_CONTACT_SLIM__
            mmi_id cui_id = vcui_phb_setting_create(getMainScr()->getApp()->getGroupId());
            if (cui_id == GRP_ID_INVALID)
                return;
            vcui_phb_setting_run(cui_id);
            vfxSetCuiCallerScr(cui_id, getMainScr());
#else
            VappContactSettingLaunch(getMainScr());
#endif

            break;
        }
    }
}


void VappPhbListTabPage::onCmdStart(vapp_phb_mark_cmd_type_enum cmd)
{
    if (cmd == VAPP_PHB_MARK_CMD_DELETE
#ifdef __MMI_PHB_MARK_MESSAGE__       
        || cmd == VAPP_PHB_MARK_CMD_MESSAGE
#endif /* __MMI_PHB_MARK_MESSAGE__ */
#if defined (__MMI_OPP_SUPPORT__) && defined (__MMI_VCARD__)
        || cmd == VAPP_PHB_MARK_CMD_SHARE
#endif /* __MMI_OPP_SUPPORT__ &&  __MMI_VCARD__*/
        )
    {
        m_cmd = cmd;

        m_list->m_signalItemTapped.disconnect(this, &VappPhbListTabPage::onItemTaped);
        m_list->m_signalItemLongTapped.disconnect(this, &VappPhbListTabPage::onItemLongTaped);
    }
}


void VappPhbListTabPage::onCmdEnd(vapp_phb_mark_cmd_type_enum cmd)
{
    if (cmd == VAPP_PHB_MARK_CMD_DELETE
#ifdef __MMI_PHB_MARK_MESSAGE__
        || cmd == VAPP_PHB_MARK_CMD_MESSAGE
#endif /* __MMI_PHB_MARK_MESSAGE__ */
#if defined (__MMI_OPP_SUPPORT__) && defined (__MMI_VCARD__)
        || cmd == VAPP_PHB_MARK_CMD_SHARE
#endif /* __MMI_OPP_SUPPORT__ &&  __MMI_VCARD__ */
       )
    {
        m_cmd = VAPP_PHB_MARK_CMD_NONE;

        // set align field
        m_list->setAlignField(MMI_PHB_CONTACT_FIELD_NAME);

        // set list type
        m_list->setListType(VAPP_PHB_LIST_NORMAL);

        m_list->m_signalItemTapped.connect(this, &VappPhbListTabPage::onItemTaped);
        m_list->m_signalItemLongTapped.connect(this, &VappPhbListTabPage::onItemLongTaped);

        setBottomBar(m_toolBar);
    }
}


mmi_ret VappPhbListTabPage::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_PHB_READY:
        {
            srv_phb_startup_evt_struct *ready = (srv_phb_startup_evt_struct*) evt;
            if (!ready->phb_ready)
            {
                //m_list->onListReady();
            }
            break;
        }
        case EVT_ID_CUI_PHB_SAVE_RESULT:
        {
            vcui_phb_contact_saver_close(((mmi_group_event_struct*) evt)->sender_id);
            return MMI_RET_OK;
        }
        case EVT_ID_CUI_PHB_VIEW_RESULT:
        {
            vcui_phb_contact_viewer_close(((mmi_group_event_struct*) evt)->sender_id);
            return MMI_RET_OK;
        }
        case EVT_ID_PHB_STORAGE_CHANGE:
        {
            srv_phb_storage_change_evt_struct *event = (srv_phb_storage_change_evt_struct*) evt;
            m_list->getListObject()->setStorage(event->new_storage_mask);
            return MMI_RET_OK;
        }
    #ifdef __LOW_COST_SUPPORT_COMMON__
        case EVT_ID_CUI_PHB_SAVE_ENTERED:
        case EVT_ID_CUI_PHB_VIEW_ENTERED:
        {
            clearPhbForm();

            return MMI_RET_OK;
        }
    #endif /* __LOW_COST_SUPPORT_COMMON__ */
    #ifdef __MMI_CONTACT_SLIM__
    case EVT_ID_CUI_PHB_SETTING_RESULT:
   
         vcui_phb_setting_close(((mmi_group_event_struct*) evt)->sender_id);
         break;
    #endif
    #ifdef __MMI_SMS_COMPOSER__
         
    case EVT_ID_CUI_SMS_COMPOSER_CLOSE:
     {
         /* just close it */
         VcuiSmsComposerEventStruct *ucEvt = (VcuiSmsComposerEventStruct *)evt;
         vcui_sms_composer_close(ucEvt->sender_id);        
         break;
     }
    #endif
    case EVT_ID_VAPP_CLOG_APP_ENTER:
        if (m_cmd == VAPP_PHB_MARK_CMD_NONE)
        {
            clearPhbForm();
            //kal_prompt_trace(MOD_MMI,"VappPhbListTabPage::onProc():%d", EVT_ID_VAPP_CLOG_APP_ENTER);
            m_recreatePhbForm =VFX_TRUE;
        }
        break;
    }

    return VfxPage::onProc(evt);
}


#ifdef __LOW_COST_SUPPORT_COMMON__
void VappPhbListTabPage::onEntered()
{
    VfxPage::onEntered();

    if (m_recreatePhbForm)
    {
    #ifdef __LOW_COST_SUPPORT_COMMON__
        recreatePhbForm();
    #endif
    }
}


void VappPhbListTabPage::onExit(VfxBool isBackward)
{
    m_list->getHistory(&m_listHistory); // get list history

    VcpListMenuSearchBar *searchbar = m_list->enableSearchBar();
    VcpTextEditor *editor;
    editor = searchbar->getSearchEditor();
    editor->getHistory(&m_editorHistory); // get editor history

    VfxPage::onExit(isBackward);
}


void VappPhbListTabPage::onExited()
{
    VfxPage::onExited();
}
#endif /* __LOW_COST_SUPPORT_COMMON__ */


void VappPhbListTabPage :: onDeinit()
{

    mmi_frm_cb_dereg_event(EVT_ID_VAPP_CLOG_APP_ENTER, &VappPhbListTabPage::listener, getObjHandle());
    VfxPage::onDeinit();
}


void VappPhbListTabPage::updatePage()
{
    m_list->setProvider();
}


#ifdef __LOW_COST_SUPPORT_COMMON__
void VappPhbListTabPage::clearPhbForm()
{
    if (m_recreatePhbForm) // clear done
    {
        return ;
    }

    // save history
    m_recreatePhbForm = VFX_TRUE;
    m_searchText = m_list->getSearchString();

    VFX_OBJ_CLOSE(m_list);
}


void VappPhbListTabPage::recreatePhbForm()
{
    if (!m_toolBar)
    {
     //   VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    }

    if (!m_list)
    {
        VFX_OBJ_CREATE_EX(m_list, VappPhbListCp, this, (VFX_TRUE));
    }

    // list menu
    m_list->setSize(getSize());
    m_list->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    // signal
    m_list->m_signalItemTapped.connect(this, &VappPhbListTabPage::onItemTaped);
    m_list->m_signalItemLongTapped.connect(this, &VappPhbListTabPage::onItemLongTaped);
    m_list->m_signalCount.connect(this, &VappPhbListTabPage::onCountChanged);
    onCountChanged(m_list, 0); // disable before phb data ready

    // refresh list
    updatePage(); 
    m_list->setSearchString(m_searchText);

    // restore history
    //m_list->setHistory(&m_listHistory);
    m_setHistory = VFX_TRUE; // after list data ready

    VcpListMenuSearchBar *searchbar = m_list->enableSearchBar();
    VcpTextEditor *editor;
    editor = searchbar->getSearchEditor();
    editor->setHistory(&m_editorHistory);

    // reset form
    m_searchText = VFX_WSTR_EMPTY;
    m_recreatePhbForm = VFX_FALSE;
}
#endif /* __LOW_COST_SUPPORT_COMMON__ */

