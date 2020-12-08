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
 *  vapp_phb_group.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_PHB_CALLER_GROUP__
#include "mmi_rp_vapp_contact_def.h"

#include "vapp_phb_group.h"
#include "vapp_phb_editor.h"
#include "vapp_phb_cui.h"
#include "vapp_phb_res.h"
#include "vapp_phb_app.h"
#include "vapp_uc_gprot.h"
#include "vcp_global_popup.h"

#include "vcui_gallery_gprot.h"
#include "vcui_tone_selector_gprot.h"
#include "vapp_fmgr_cui_gprot.h"
#include "vapp_phb_gprot.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __MMI_CAMCORDER__
#include "vcui_camco_gprot.h"
#endif

#ifdef __cplusplus
}
#endif

#ifdef __MMI_COSMOS_IMAGECLIPPER__
#include "vcui_imgedt_gprot.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#include "FileMgrSrvGprot.h"
#include "ProfilesSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "NotificationGprot.h"
#include "UsbSrvGprot.h"

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Class VappPhbGroupScr
 *****************************************************************************/
void VappPhbGroupScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VFX_OBJ_CREATE(m_groupManager, ContactGroupManager, this);

    VappPhbGroupListPage *page;
    VFX_OBJ_CREATE_EX(page, VappPhbGroupListPage, this, (m_groupManager));

    pushPage(VFX_ID_NULL, page);
}


void VappPhbGroupScr::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


/***************************************************************************** 
 * Class VappPhbGroupListCp
 *****************************************************************************/

VappPhbGroupListCp::VappPhbGroupListCp(ContactGroupManager *groupManager):
        m_groupManager(groupManager)
{
    m_mark = NULL;
    m_updateGroupList = VFX_FALSE;
}


void VappPhbGroupListCp::onInit()
{
    VcpListMenu::onInit();

    setContentProvider(this);

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    m_groupManager->m_signalGroupChanged.connect(this, &VappPhbGroupListCp::onGroupListChanged);
#endif
}


void VappPhbGroupListCp::setMarkSet(VappContactGroupMarkObj *mark)
{
    m_mark = mark;
}


VfxBool VappPhbGroupListCp::getMenuEmptyText(
    VfxWString &text,                // [OUT] the text resource
    VcpListMenuTextColorEnum &color  // [OUT] the text color
    )
{
    text = VFX_WSTR_RES(VAPP_PHB_STR_GROUP_EMPTY);

    return VFX_TRUE;
}


VfxBool VappPhbGroupListCp::getItemText(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxWString &text,                // [OUT] the text resource
    VcpListMenuTextColorEnum &color  // [OUT] the text color
    )
{
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        text = m_groupManager->getGroupName(index);
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxBool VappPhbGroupListCp::getItemImage(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxImageSrc &image               // [OUT] the image resource
    )
{
    if (fieldType == VCP_LIST_MENU_FIELD_DISCLOSURE_IMG)
    {
        image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
        return VFX_TRUE;
    }

#ifdef __MMI_PHB_USIM_SUPPORT__
    if (UsimGroup::getCount() > 0 && fieldType == VCP_LIST_MENU_FIELD_ICON)
    {
        image = ContactStorage::getIconEx(m_groupManager->getStorageById(m_groupManager->getGroupId(index)));
        return VFX_TRUE;
    }
#endif /* __MMI_PHB_USIM_SUPPORT__ */

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    if (TcardGroup::getCount() > 0 && fieldType == VCP_LIST_MENU_FIELD_ICON)
    {
        image = ContactStorage::getIconEx(m_groupManager->getStorageById(m_groupManager->getGroupId(index)));
        return VFX_TRUE;
    }
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */

    return VFX_FALSE; 
}


VcpListMenuItemStateEnum VappPhbGroupListCp::getItemState(
    VfxU32 id                        // [IN] position of the item
    ) const
{
    return (m_mark->checkMark(m_groupManager->getGroupId(id))) ? VCP_LIST_MENU_ITEM_STATE_SELECTED : VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}


VfxU32 VappPhbGroupListCp::getCount() const
{
    return m_groupManager->getGroupCount();
}


#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
void VappPhbGroupListCp::onGroupListChanged(ContactGroupManager *groupManager, mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        case EVT_ID_USB_ENTER_MS_MODE:
        {
          //  printf ("group list: %d\n", evt->evt_id);
            if (m_mark)
            {
                // clear mark in tcard
            }
            break;
        }
    }

    updateGroupList();
}


void VappPhbGroupListCp::getGroupList() // refresh group list
{
    updateGroupList();
}


void VappPhbGroupListCp::updateGroupList()
{
    if (!m_updateGroupList)
    {
        m_updateGroupList = VFX_TRUE; // set update flag

        vfxPostInvoke0(this, &VappPhbGroupListCp::getGroupListInter);
    }
}


void VappPhbGroupListCp::getGroupListInter()
{
    // update group list
    m_groupManager->getGroup();
    resetAllItems(VFX_TRUE);

    // reset update falg
    m_updateGroupList = VFX_FALSE;

    // notify group list refresh done
    m_signalGroupListReady.postEmit(this, m_groupManager->getGroupCount());
}
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */


/***************************************************************************** 
 * Class VappPhbMarkDeleteGroupObj
 *****************************************************************************/
VappPhbMarkDeleteGroupObj::VappPhbMarkDeleteGroupObj(
    VappPhbGroupListCp* list,
    VfxPage *page,
    VappPhbMarkCmdInterface *cmd,
    ContactGroupManager *groupManager):
     m_page(page),
     m_list(list),
     m_tool(NULL),
     m_mark(NULL),
     m_cmd(cmd),
     m_groupManager(groupManager)
{
     m_progress = NULL;
}


void VappPhbMarkDeleteGroupObj::onInit()
{
    VfxObject::onInit();

    m_cmd->onCmdStart(VAPP_PHB_MARK_CMD_DELETE_GROUP);

    VFX_OBJ_CREATE(m_mark, VappContactGroupMarkObj, this);
    m_list->setMarkSet(m_mark);

    VFX_OBJ_CREATE(m_tool, VcpToolBar, m_page);
    m_page->setBottomBar(m_tool);

    m_tool->addItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    m_tool->addItem(PB_MULTI_CMD_OP, VFX_WSTR_RES(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_tool->addItem(PB_MULTI_CMD_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);

    configToolBar();

    m_list->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION);
    m_list->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL);

    m_tool->m_signalButtonTap.connect(this, &VappPhbMarkDeleteGroupObj::onToolBarClicked);
    m_list->m_signalItemSelectionStateChanged.connect(this, &VappPhbMarkDeleteGroupObj::onStateChanged);
    m_groupManager->m_signalGroupManager.connect(this, &VappPhbMarkDeleteGroupObj::onGroupDeleted);

    // add m_signalGroupOp
    m_groupManager->m_signalGroupOp.connect(this, &VappPhbMarkDeleteGroupObj::onGroupOp);
}


void VappPhbMarkDeleteGroupObj::configToolBar()
{
    if (m_mark->getCount() > 0)
    {
        m_tool->setDisableItem(PB_MULTI_CMD_OP, VFX_FALSE);
    }
    else
    {
        m_tool->setDisableItem(PB_MULTI_CMD_OP, VFX_TRUE);
    }
}


void VappPhbMarkDeleteGroupObj::onToolBarClicked(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case PB_MULTI_CMD_SELECT:
        {
            if (m_mark->getCount() == m_groupManager->getGroupCount())
            {
                m_mark->reset();
                m_list->resetAllItems(VFX_TRUE);
                m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
            }
            else
            {
                m_mark->reset();
                for (VfxU32 i = 0; i < m_groupManager->getGroupCount(); i++)
                {
                    m_mark->setMark(m_groupManager->getGroupId(i));
                    m_list->resetAllItems(VFX_TRUE);
                }

                m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
            }

            configToolBar();
            break;
        }
        case PB_MULTI_CMD_OP:
        {
            if (m_mark->getCount() > 0)
            {
                VcpConfirmPopup *confirm;
                VFX_OBJ_CREATE(confirm, VcpConfirmPopup, m_page);

                VfxWString text = VFX_WSTR_RES(STR_ID_VAPP_PHB_DELETE_SELECTED);
                if (m_mark->getCount() == 1)
                {
                    text += VFX_WSTR_RES(STR_ID_VAPP_PHB_GROUP);
                }
                else
                {
                    text += VFX_WSTR_RES(STR_ID_VAPP_PHB_GROUPS);
                }
                text += VFX_WSTR_RES(STR_ID_VAPP_PHB_LEFT_PARENTHESES);
                text += VfxWString().format("%d", m_mark->getCount());
                text += VFX_WSTR_RES(STR_ID_VAPP_PHB_RIGHT_PARENTHESES);
                text += VFX_WSTR_RES(STR_ID_VAPP_PHB_QUESTION);

                confirm->setText(text);
                confirm->setInfoType(VCP_POPUP_TYPE_WARNING);
                confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
                confirm->setCustomButton(
                            VFX_WSTR_RES(STR_GLOBAL_DELETE),
                            VFX_WSTR_RES(STR_GLOBAL_CANCEL),
                            VCP_POPUP_BUTTON_TYPE_WARNING,
                            VCP_POPUP_BUTTON_TYPE_CANCEL);

                confirm->m_signalButtonClicked.connect(this, &VappPhbMarkDeleteGroupObj::onOptionClicked);

                confirm->show(VFX_TRUE);
            }
            break;
        }
        case PB_MULTI_CMD_CANCEL:
        {
            closeSelf();
            break;
        }
    }
}


void VappPhbMarkDeleteGroupObj::onOptionClicked(VfxObject *obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        VfxU8 *idArray = (VfxU8*) mmi_frm_temp_alloc(m_mark->getCount() * sizeof(VfxU8));

        for (VfxU32 i = 0; i < m_mark->getCount(); i++)
        {
            idArray[i] = m_mark->getMarkKey(i).m_id;
        }

        m_tool->setDisableItem(PB_MULTI_CMD_SELECT, VFX_TRUE);
        m_tool->setDisableItem(PB_MULTI_CMD_OP, VFX_TRUE);
        m_tool->setDisableItem(PB_MULTI_CMD_CANCEL, VFX_TRUE);

        m_groupManager->deleteGroup(idArray, m_mark->getCount());
        // show progress bar
        VFX_OBJ_CREATE(m_progress, VcpIndicatorPopup, m_page);
        m_progress->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
        m_progress->setText(VFX_WSTR_RES(STR_ID_VAPP_PHB_PROCESSING));

        m_progress->show(VFX_TRUE);

        mmi_frm_temp_free(idArray);
    }
    else
    {
        closeSelf();
    }
}


void VappPhbMarkDeleteGroupObj::onStateChanged(VcpListMenu *list, VfxU32 id, VcpListMenuItemStateEnum state)
{
    m_mark->changeMark(m_groupManager->getGroupId(id));

    if (m_mark->getCount() == m_groupManager->getGroupCount())
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
    }
    else
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    }

    configToolBar();
}


void VappPhbMarkDeleteGroupObj::onGroupDeleted(ContactGroupManager* manager, VfxU8 groupId, srv_phb_group_op_type_enum op)
{
    if (op == SRV_PHB_GROUP_OP_TYPE_DEL)
    {
        closeSelf();
    }
}


void VappPhbMarkDeleteGroupObj::onGroupOp(ContactGroupManager* manager, VfxS32 result, srv_phb_group_op_type_enum op)
{
    if (op == SRV_PHB_GROUP_OP_TYPE_DEL)
    {
        closeSelf();
    }
}


void VappPhbMarkDeleteGroupObj::closeSelf()
{
    m_cmd->onCmdEnd(VAPP_PHB_MARK_CMD_DELETE_GROUP);

    if (m_progress)
    {
        m_progress->exit(VFX_TRUE);
        m_progress = NULL;
    }

    VFX_OBJ_CLOSE(m_tool);

    VfxObject *obj = this;
    VFX_OBJ_CLOSE(obj);
}


/***************************************************************************** 
 * Class VappPhbGroupListPage
 *****************************************************************************/
VappPhbGroupListPage::VappPhbGroupListPage(ContactGroupManager *groupManager):
    m_groupManager(groupManager),
    m_groupList(NULL),
    m_toolBar(NULL)
{
}


void VappPhbGroupListPage::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *title;
    VFX_OBJ_CREATE(title, VcpTitleBar, this);
    title->setTitle(VFX_WSTR_RES(VAPP_PHB_STR_GROUPS));
    setTopBar(title);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    setBottomBar(m_toolBar);
    m_toolBar->addItem(VAPP_PHB_GROUP_CMD_ADD, VFX_WSTR_RES(VAPP_PHB_STR_ADD_GROUP), VAPP_PHB_IMG_CMD_ADD_GROUP);
    m_toolBar->addItem(VAPP_PHB_GROUP_CMD_DELETE, VFX_WSTR_RES(STR_GLOBAL_DELETE), VAPP_PHB_IMG_CMD_DELETE_GROUP);

    VFX_OBJ_CREATE_EX(m_groupList, VappPhbGroupListCp, this, (m_groupManager));

#if defined (__MMI_PHB_USIM_SUPPORT__) || defined (__MMI_PHB_TCARD_STORAGE_SUPPORT__)

    VfxBool showIcon = VFX_FALSE;

#ifdef __MMI_PHB_USIM_SUPPORT__
    if (UsimGroup::getCount() > 0)
    {
        showIcon = VFX_TRUE;
       // m_groupList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT);
    }
#endif /* __MMI_PHB_USIM_SUPPORT__ */

#ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
    if (TcardGroup::getCount() > 0)
    {
        showIcon = VFX_TRUE;
    }
#endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */

    if (showIcon)
    {
        m_groupList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT);
    }
    else
#endif /* defined (__MMI_PHB_USIM_SUPPORT__) || defined (__MMI_PHB_TCARD_STORAGE_SUPPORT__) */
    {
        m_groupList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    }
    m_groupList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE);
    m_groupList->setSize(getSize());
    m_groupList->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    if (m_groupManager->getGroupCount() == 0)
    {
        m_toolBar->setDisableItem(VAPP_PHB_GROUP_CMD_DELETE, VFX_TRUE);
    }

    m_toolBar->m_signalButtonTap.connect(this, &VappPhbGroupListPage::onToolBarClicked);
    m_groupList->m_signalItemTapped.connect(this, &VappPhbGroupListPage::onItemTaped);
    m_groupManager->m_signalGroupManager.connect(this, &VappPhbGroupListPage::onGroupListChanged);
}


void VappPhbGroupListPage::onEntered()
{
    m_groupManager->getGroup();
}


void VappPhbGroupListPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


void VappPhbGroupListPage::onItemTaped(VcpListMenu* obj, VfxU32 id)
{
    VappPhbGroupMemberListPage *page;

    VFX_OBJ_CREATE_EX(page, VappPhbGroupMemberListPage, getMainScr(), (m_groupManager, m_groupManager->getGroupId(id)));
    getMainScr()->pushPage(VFX_ID_NULL, page);
}


void VappPhbGroupListPage::onToolBarClicked(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case VAPP_PHB_GROUP_CMD_ADD:
        {
        #if defined (__MMI_PHB_USIM_SUPPORT__) || defined (__MMI_PHB_TCARD_STORAGE_SUPPORT__)
            VfxU32 groupCount = 0;
        #ifdef __MMI_PHB_USIM_SUPPORT__
            groupCount += UsimGroup::getCount();
        #endif

        #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
            groupCount += TcardGroup::getCount();
        #endif
            if (groupCount > 0)
            {
                    VcpCommandPopup *option;
                    VFX_OBJ_CREATE(option, VcpCommandPopup, this);

                    option->setText(VFX_WSTR_RES(VAPP_PHB_STR_ADD_GROUP));

                    VfxWString text = VFX_WSTR_RES(STR_ID_VAPP_PHB_TO);
                    text += VFX_WSTR_RES(VAPP_PHB_STR_PHONE);
                    option->addItem(PHB_STORAGE_NVRAM, text, VCP_POPUP_BUTTON_TYPE_NORMAL);
                #ifdef __MMI_PHB_USIM_SUPPORT__
                    if (UsimGroup::getCount() > 0)
                    {
                        for (VfxU32 i = 0; i < ContactSim::getTotal(); i++)
                        {
                            mmi_sim_enum sim = mmi_frm_index_to_sim(i);
                            if (srv_sim_ctrl_is_inserted(sim))
                            {
                                phb_storage_enum storage = ContactSim::getStorage(sim);
                                text = VFX_WSTR_RES(STR_ID_VAPP_PHB_TO);
                                text += ContactStorage::getName(storage);
                                option->addItem(storage, text, VCP_POPUP_BUTTON_TYPE_NORMAL);
                                if (!UsimGroup::isSupport(storage))
                                {
                                    option->disableItem(storage);
                                }
                            }
                        }
                    }
                #endif /* __MMI_PHB_USIM_SUPPORT__ */

                #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
                    if (TcardGroup::getCount() > 0)
                    {
                        text = VFX_WSTR_RES(STR_ID_VAPP_PHB_TO);
                        text += ContactStorage::getName(PHB_STORAGE_TCARD);
                        option->addItem(PHB_STORAGE_TCARD, text, VCP_POPUP_BUTTON_TYPE_NORMAL);
                        if (!TcardGroup::isSupport(PHB_STORAGE_TCARD))
                        {
                            option->disableItem(PHB_STORAGE_TCARD);
                        }
                    }
                #endif /* __MMI_PHB_TCARD_STORAGE_SUPPORT__ */
                option->addItem(PHB_STORAGE_MAX, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);

                option->m_signalButtonClicked.connect(this, &VappPhbGroupListPage::onOptionClicked);

                option->show(VFX_TRUE);
            }
            else
        #endif /* defined (__MMI_PHB_USIM_SUPPORT__) || defined (__MMI_PHB_TCARD_STORAGE_SUPPORT__) */
            if (m_groupManager->getGroupCount() == m_groupManager->getMaxGroupCount(PHB_STORAGE_NVRAM))
            {
                VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
                balloon->addItem(VCP_INFO_BALLOON_TYPE_FAILURE, VFX_WSTR_RES(STR_ID_VAPP_PHB_MAX_NUM_REACH));
            }
            else
            {
                VappPhbGroupEditorScr *scr;
                VFX_OBJ_CREATE_EX(scr, VappPhbGroupEditorScr, getApp(), (PHB_STORAGE_NVRAM, m_groupManager));
                scr->show();
            }
            break;
        }
        case VAPP_PHB_GROUP_CMD_DELETE:
        {
            VappPhbMarkDeleteGroupObj *del;
            VFX_OBJ_CREATE_EX(del, VappPhbMarkDeleteGroupObj, this, (m_groupList, this, this, m_groupManager));
            break;
        }
    }
}


void VappPhbGroupListPage::onOptionClicked(VfxObject* obj, VfxId id)
{
    phb_storage_enum storage = (phb_storage_enum)id;

    if (storage == PHB_STORAGE_MAX || id == VCP_POPUP_BUTTON_NO_PRESSED || id == VCP_CONFIRM_POPUP_BUTTON_CANCEL)
    {
        return;
    }

    if (m_groupManager->getUsedGroupCount(storage) == m_groupManager->getMaxGroupCount(storage))
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(VCP_INFO_BALLOON_TYPE_FAILURE, VFX_WSTR_RES(STR_ID_VAPP_PHB_MAX_NUM_REACH));
        return;
    }

    VappPhbGroupEditorScr *scr;
    VFX_OBJ_CREATE_EX(scr, VappPhbGroupEditorScr, getApp(), (storage, m_groupManager));
    scr->show();
}


void VappPhbGroupListPage::onGroupListChanged(ContactGroupManager* manager, VfxU8 groupId, srv_phb_group_op_type_enum op)
{
    m_groupList->resetAllItems(VFX_TRUE);

    if (m_groupManager->getGroupCount() == 0)
    {
        m_toolBar->setDisableItem(VAPP_PHB_GROUP_CMD_DELETE, VFX_TRUE);
    }
    else
    {
        m_toolBar->setDisableItem(VAPP_PHB_GROUP_CMD_DELETE, VFX_FALSE);
    }

    if ((op == SRV_PHB_GROUP_OP_TYPE_ADD)
        && (ContactStorage::getMask() & ContactStorage::getMask(m_groupManager->getStorageById(groupId)))
        )
    {
        VappPhbGroupMemberListPage *page;
        VFX_OBJ_CREATE_EX(page, VappPhbGroupMemberListPage, getMainScr(), (m_groupManager, groupId));

        getMainScr()->pushPage(VFX_ID_NULL, page);
    }
}


void VappPhbGroupListPage::onGroupListOp(ContactGroupManager* manager, VfxS32 result, srv_phb_group_op_type_enum op)
{
    m_groupList->resetAllItems(VFX_TRUE);

    if (SRV_PHB_GROUP_OP_TYPE_DEL == op)
    {
        if (m_groupManager->getGroupCount() == 0)
        {
            m_toolBar->setDisableItem(VAPP_PHB_GROUP_CMD_DELETE, VFX_TRUE);
        }
        else
        {
            m_toolBar->setDisableItem(VAPP_PHB_GROUP_CMD_DELETE, VFX_FALSE);
        }
    }
}


void VappPhbGroupListPage::onCmdStart(vapp_phb_mark_cmd_type_enum cmd)
{
    m_groupList->m_signalItemTapped.disconnect(this, &VappPhbGroupListPage::onItemTaped);
}


void VappPhbGroupListPage::onCmdEnd(vapp_phb_mark_cmd_type_enum cmd)
{
    m_groupList->setMenuMode(VCP_LIST_MENU_MODE_NORMAL);
    m_groupList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE);

    m_groupList->m_signalItemTapped.connect(this, &VappPhbGroupListPage::onItemTaped);
    setBottomBar(m_toolBar);
}


/***************************************************************************** 
 * Class VappPhbGroupEditorScr
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappPhbGroupEditorScr", VappPhbGroupEditorScr, VfxMainScr);

VappPhbGroupEditorScr::VappPhbGroupEditorScr(phb_storage_enum storage, ContactGroupManager *manager, VfxU8 groupId):
    m_storage(storage),
    m_groupManager(manager),
    m_groupId(groupId)
{
}


void VappPhbGroupEditorScr::on1stReady()
{
    VfxMainScr::on1stReady();

    VappPhbGroupEditorPage *page;
    VFX_OBJ_CREATE_EX(page, VappPhbGroupEditorPage, this, (m_storage, m_groupId));

    pushPage(VFX_ID_NULL, page);
}


void VappPhbGroupEditorScr::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


/***************************************************************************** 
 * Class VappPhbGroupNameFormItem
 *****************************************************************************/
VappPhbGroupNameFormItem::VappPhbGroupNameFormItem():
        m_image(NULL),
        m_editor(NULL)
{
}


void VappPhbGroupNameFormItem::onInit()
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
    m_image->setPhoto(VfxImageSrc(VAPP_PHB_IMG_DEFAULT_CONTACT));

    // create group name control
    VfxFrame* bg;
    VFX_OBJ_CREATE(bg, VfxFrame, this);
    bg->setAnchor(0, 0.5f);
    bg->setPos(m_image->getPos().x + m_image->getSize().width + VCPFRM_INDENT_L3, getSize().height/2);
    bg->setSize(
        getSize().width - (m_image->getPos().x + m_image->getSize().width + VCPFRM_INDENT_L3) - VCPFRM_SIDE_MARGIN_LARGE,
        VCPFRM_FONT_SIZE_3 + VCPFRM_ITEM_HORZ_GAP_1 + VCPFRM_STANDARD_BTN_HEIGHT + VCPFRM_ITEM_HORZ_GAP_1);

    bg->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    // create group name
    VfxTextFrame *label;
    VFX_OBJ_CREATE(label, VfxTextFrame, bg);
    label->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCPFRM_FONT_SIZE_3)));
    label->setColor(VCP_FORM_DARK_FONT_COLOR);
    label->setString(VFX_WSTR_RES(VAPP_PHB_STR_GROUP_NAME));
    label->setSize(label->getMeasureBounds().size);

    label->setAlignParent(
        VFX_FRAME_ALIGNER_SIDE_LEFT,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    label->setAlignParent(
        VFX_FRAME_ALIGNER_SIDE_RIGHT,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    // create group editor
    VFX_OBJ_CREATE(m_editor, VcpTextEditor, bg);
    m_editor->setPos(0, label->getSize().height + VCPFRM_ITEM_HORZ_GAP_1);
    m_editor->setSize(bg->getSize().width, VCPFRM_STANDARD_BTN_HEIGHT);
    m_editor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);

    m_editor->setAlignParent(
        VFX_FRAME_ALIGNER_SIDE_LEFT,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    m_editor->setAlignParent(
        VFX_FRAME_ALIGNER_SIDE_RIGHT,
        VFX_FRAME_ALIGNER_MODE_SIDE);
}


VcpTextEditor* VappPhbGroupNameFormItem::getEditor()
{
    return m_editor;
}


VappPhbPhotoCp *VappPhbGroupNameFormItem::getImageBtn()
{
    return m_image;
}


/***************************************************************************** 
 * Class VappPhbGroupEditorPage
 *****************************************************************************/
VappPhbGroupEditorPage::VappPhbGroupEditorPage(phb_storage_enum storage, VfxU8 groupId):
    m_storage(storage),
    m_groupId(groupId),
    m_form(NULL),
    m_group(NULL)
{
}


void VappPhbGroupEditorPage::onInit()
{
    VfxPage::onInit();

    VFX_OBJ_CREATE_EX(m_group, ContactGroup, this, (m_groupId));

    VcpTitleBar* titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);

    if (m_groupId == MMI_PHB_INVALID_GROUP_ID)
    {
        titleBar->setTitle(VFX_WSTR_RES(VAPP_PHB_STR_ADD_GROUP));
    }
    else
    {
        titleBar->setTitle(VFX_WSTR_RES(VAPP_PHB_STR_EDIT_GROUP));
    }
    setTopBar(titleBar);

    VcpToolBar* toolbar; 
    VFX_OBJ_CREATE(toolbar,VcpToolBar,this);
    toolbar->addItem(VAPP_PHB_GROUP_EDITOR_CMD_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    toolbar->addItem(VAPP_PHB_GROUP_EDITOR_CMD_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    setBottomBar(toolbar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

    if (m_storage == PHB_STORAGE_NVRAM
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        || m_storage == PHB_STORAGE_TCARD
    #endif
        )
    {
        VappPhbGroupNameFormItem *name;
        VFX_OBJ_CREATE(name, VappPhbGroupNameFormItem, m_form);

        VcpTextEditor *editor = name->getEditor();
        editor->setText(m_group->getGroupNameBuf(), MMI_PHB_GROUP_NAME_LENGTH, VFX_TRUE);

        VappPhbPhotoCp *image = name->getImageBtn();
        image->setPhoto(m_group->getImageSrc());
        image->m_signalClicked.connect(this, &VappPhbGroupEditorPage::onImageClicked);

        m_form->addItem(name, VAPP_PHB_GROUP_FORM_ITEM_NAME);
    }
    else
    {
        VcpFormItemTextInput *name;
        VFX_OBJ_CREATE(name, VcpFormItemTextInput, m_form);

        m_form->addCaption(VFX_WSTR_RES(VAPP_PHB_STR_GROUP_NAME));

        VcpTextEditor *editor = name->getTextBox();
        VfxU32 length = srv_phb_get_alpha_field_length(m_storage, MMI_PHB_CONTACT_FIELD_ID_GROUP);
        length = (length > MMI_PHB_GROUP_NAME_LENGTH) ? MMI_PHB_GROUP_NAME_LENGTH : length;
        editor->setText(
                    m_group->getGroupNameBuf(),
                    length,
                    VFX_TRUE,
                 #ifdef __PHB_0x81_SUPPORT__
                    VCP_TEXT_ENCODING_0X81,
                 #else
                    VCP_TEXT_ENCODING_GSM,
                 #endif
                    NULL);

        editor->setIME(IMM_INPUT_TYPE_SENTENCE, IME_DISABLE_NEW_LINE_SYMBOL);

        m_form->addItem(name, VAPP_PHB_GROUP_FORM_ITEM_NAME);
    }

    if (m_storage == PHB_STORAGE_NVRAM
    #ifdef __MMI_PHB_TCARD_STORAGE_SUPPORT__
        || m_storage == PHB_STORAGE_TCARD
    #endif
        )
    {
        VcpFormItemBigArrowButton *ring;
        VFX_OBJ_CREATE(ring, VcpFormItemBigArrowButton, m_form);
        ring->setButtonText(VFX_WSTR_RES(VAPP_PHB_STR_GROUP_RINGTONE));
        ring->setHintText(m_group->getRingName());

        VcpArrowButton *btn = ring->getButton();
        btn->m_signalClicked.connect(this, &VappPhbGroupEditorPage::onRingClicked);

        m_form->addItem(ring, VAPP_PHB_GROUP_FORM_ITEM_RING);
    }

    toolbar->m_signalButtonTap.connect(this, &VappPhbGroupEditorPage::onToolBarClicked);
}


void VappPhbGroupEditorPage::onDeinit()
{
    VfxPage::onDeinit();
}


void VappPhbGroupEditorPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


mmi_ret VappPhbGroupEditorPage::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_VCUI_GALLERY_PICKER_RESULT_READY:
        {
            vcui_gallery_evt_struct *result = (vcui_gallery_evt_struct*) evt;
            if (result->result == VCUI_GALLERY_RESULT_OK)
            {
                VappPhbResSelectorObj *userData;
                VFX_OBJ_CREATE(userData, VappPhbResSelectorObj, this);

                userData->result = VFX_FALSE;
                userData->selector_cui_id = ((mmi_group_event_struct*) evt)->sender_id;

                VfxU32 size = sizeof(WCHAR) * (SRV_FMGR_PATH_MAX_LEN + 1);
                vcui_gallery_media_state_enum state =
                    vcui_gallery_picker_get_single_path(((mmi_group_event_struct*) evt)->sender_id, userData->img_path, &size);

            #ifdef __MMI_COSMOS_IMAGECLIPPER__
                if (cui_vapp_imgclip_is_file_support(userData->img_path) == CUI_IMGEDT_OK)
                {
                    cui_imgclip_launch_struct param;
                    param.scr_file_path = (U8*) userData->img_path;
                    param.user_data = (U32)userData;

                    mmi_id cui_id = cui_vapp_imgclip_create(getApp()->getGroupId(), &param);
                    if (cui_id != GRP_ID_INVALID)
                    {
                        vfxSetCuiCallerScr(cui_id, getMainScr());

                        userData->img_cliper_cui_id = cui_id;

                        cui_vapp_imgclip_set_size_limit(cui_id, VAPP_PHB_IMG_SIZE_WIDTH, VAPP_PHB_IMG_SIZE_HEIGHT);
                        cui_vapp_imgclip_set_ratio_fixed(cui_id, MMI_TRUE);
                        cui_vapp_imgclip_set_ratio(cui_id, 1, 1);
                        cui_vapp_imgclip_save_pbm_file(cui_id, MMI_TRUE);

                        cui_vapp_imgclip_run(cui_id);
                    }
                    else
                    {
                        VFX_OBJ_CLOSE(userData);
                        vcui_gallery_close(((mmi_group_event_struct*) evt)->sender_id);
                    }
                }
                else
                {
                    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
                        (WCHAR*)VFX_WSTR_RES(STR_GLOBAL_INVALID_FORMAT).getBuf());
                    VFX_OBJ_CLOSE(userData);
                }
            #else /* __MMI_COSMOS_IMAGECLIPPER__ */
                if (state == VCUI_GALLERY_MEDIA_STATE_OK)
                {
                    VappPhbGroupNameFormItem *name = (VappPhbGroupNameFormItem*) m_form->getItem(VAPP_PHB_GROUP_FORM_ITEM_NAME);
                    VappPhbPhotoCp *image = name->getImageBtn();

                    m_group->setImage(userData->img_path, 0);
                    image->setPhoto(m_group->getImageSrc());

                    VFX_OBJ_CLOSE(userData);
                    vcui_gallery_close(((mmi_group_event_struct*) evt)->sender_id);
                }
                else
                {
                    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
                        (WCHAR*)VFX_WSTR_RES(STR_GLOBAL_INVALID_FORMAT).getBuf());
                    VFX_OBJ_CLOSE(userData);
                }
            #endif /* __MMI_COSMOS_IMAGECLIPPER__ */
            }
            break;
        }

        case EVT_ID_VCUI_GALLERY_CLOSE_GID:
        {
            vcui_gallery_close(((mmi_group_event_struct*) evt)->sender_id);
            break;
        }

    #ifndef __LOW_COST_SUPPORT_COMMON__
    #ifdef __MMI_CAMCORDER__
        case VCUI_CAMCO_EVENT_RESULT_SUCCESS:
        {
            vcui_camco_event_struct *cam = (vcui_camco_event_struct*)evt;
            if (cam->errCode == VCUI_CAMCO_ERR_NONE)
            {
                VappPhbResSelectorObj *userData;
                VFX_OBJ_CREATE(userData, VappPhbResSelectorObj, this);

                mmi_ucs2cpy((CHAR*)userData->img_path, (CHAR *) cam->filePath);

                userData->result = VFX_FALSE;
                userData->selector_cui_id = ((mmi_group_event_struct*) evt)->sender_id;

            #ifdef __MMI_COSMOS_IMAGECLIPPER__
                if (cui_vapp_imgclip_is_file_support(userData->img_path) == CUI_IMGEDT_OK)
                {
                    cui_imgclip_launch_struct param;
                    param.scr_file_path = (U8*) userData->img_path;
                    param.user_data = (U32)userData;

                    mmi_id cui_id = cui_vapp_imgclip_create(getApp()->getGroupId(), &param);
                    if (cui_id != GRP_ID_INVALID)
                    {
                        vfxSetCuiCallerScr(cui_id, getMainScr());

                        userData->img_cliper_cui_id = cui_id;

                        cui_vapp_imgclip_set_size_limit(cui_id, VAPP_PHB_IMG_SIZE_WIDTH, VAPP_PHB_IMG_SIZE_HEIGHT);
                        cui_vapp_imgclip_set_ratio_fixed(cui_id, MMI_TRUE);
                        cui_vapp_imgclip_set_ratio(cui_id, 1, 1);
                        cui_vapp_imgclip_save_pbm_file(cui_id, MMI_TRUE);

                        cui_vapp_imgclip_run(cui_id);
                        vcui_standard_camera_close(((mmi_group_event_struct*) evt)->sender_id);
                    }
                    else
                    {
                        VFX_OBJ_CLOSE(userData);
                        vcui_standard_camera_close(((mmi_group_event_struct*) evt)->sender_id);
                    }
                }
                else
            #endif /* __MMI_COSMOS_IMAGECLIPPER__ */
                {
                    VappPhbGroupNameFormItem *name = (VappPhbGroupNameFormItem*) m_form->getItem(VAPP_PHB_GROUP_FORM_ITEM_NAME);
                    VappPhbPhotoCp *image = name->getImageBtn();

                    m_group->setImage(userData->img_path, 0);
                    image->setPhoto(m_group->getImageSrc());

                    VFX_OBJ_CLOSE(userData);
                    vcui_standard_camera_close(((mmi_group_event_struct*) evt)->sender_id);
                }
            }
            else
            {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
                    (WCHAR*)VFX_WSTR_RES(vcui_standard_camera_get_err_string(cam->errCode)).getBuf());
                vcui_standard_camera_close(((mmi_group_event_struct*) evt)->sender_id);
            }
            break;
        }
        case VCUI_CAMCO_EVENT_RESULT_FAILED:
        {
            vcui_camco_event_struct *cam = (vcui_camco_event_struct*) evt;
            if (cam->errCode != VCUI_CAMCO_ERR_NONE)
            {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
                    (WCHAR*)VFX_WSTR_RES(vcui_standard_camera_get_err_string(cam->errCode)).getBuf());
            }
            vcui_standard_camera_close(((mmi_group_event_struct*) evt)->sender_id);
            break;
        }
    #endif /* __MMI_CAMCORDER__ */
    #endif /* __LOW_COST_SUPPORT_COMMON__ */

    #ifdef __MMI_COSMOS_IMAGECLIPPER__
        case EVT_ID_CUI_IMGCLIP_SAVE_NEW:
        case EVT_ID_CUI_IMGCLIP_SAVE_OVERWRITE:
        {
            cui_imgclip_event_struct *param = (cui_imgclip_event_struct*) evt;
            VappPhbResSelectorObj *userData = NULL;

            cui_vapp_imgclip_get_user_data(((mmi_group_event_struct*) evt)->sender_id, (U32*)(&userData));

            if (param->result == 0)
            {
                cui_vapp_imgclip_get_dest_path(((mmi_group_event_struct*) evt)->sender_id, (CHAR*) userData->img_path);

                VappPhbGroupNameFormItem *name = (VappPhbGroupNameFormItem*) m_form->getItem(VAPP_PHB_GROUP_FORM_ITEM_NAME);
                VappPhbPhotoCp *image = name->getImageBtn();

                FS_SetAttributes(userData->img_path, FS_ATTR_HIDDEN);

                m_group->setImage(userData->img_path, 0);
                image->setPhoto(m_group->getImageSrc());

                userData->result = VFX_TRUE;
            }
            return MMI_RET_OK;
        }
        case EVT_ID_CUI_IMGCLIP_CLOSE_REQUEST:
        {
            VappPhbResSelectorObj *userData = NULL;

            cui_vapp_imgclip_get_user_data(((mmi_group_event_struct*) evt)->sender_id, (U32*)(&userData));

            MMI_ID selector_cui_id = userData->selector_cui_id;
            VfxBool result = userData->result;

            VFX_OBJ_CLOSE(userData);
            cui_vapp_imgclip_close(((mmi_group_event_struct*) evt)->sender_id);

            if (result)
            {
                vcui_gallery_close(selector_cui_id);
            }
            return MMI_RET_OK;
        }
    #endif /* __MMI_COSMOS_IMAGECLIPPER__ */
        case EVT_ID_VCUI_TONE_SELECTOR_RESULT:
        {
            vcui_tone_selector_evt_struct *result = (vcui_tone_selector_evt_struct*) evt;
            if (!result->is_default_sound)
            {
                VfxWChar* path = (VfxWChar*) mmi_frm_temp_alloc(sizeof(VfxWChar) * (SRV_FMGR_PATH_MAX_LEN + 1));

                vcui_tone_selector_get_selected_filepath(
                    ((mmi_group_event_struct*) evt)->sender_id, NULL, path, sizeof(VfxWChar) * (SRV_FMGR_PATH_MAX_LEN + 1));

                m_group->setRingTone(VFX_WSTR_MEM(path), 0);

                mmi_frm_temp_free(path);
            }
            else
            {
                m_group->setRingTone(VFX_WSTR_EMPTY, result->selected_tone);
            }

            VcpFormItemBigArrowButton* ring = (VcpFormItemBigArrowButton*) m_form->getItem(VAPP_PHB_GROUP_FORM_ITEM_RING);
            ring->setHintText(m_group->getRingName());
        }

        case EVT_ID_VCUI_TONE_SELECTOR_CLOSE_REQUEST:
            vcui_tone_selector_close(((mmi_group_event_struct*) evt)->sender_id);
            break;
    }

    return VfxPage::onProc(evt);
}


void VappPhbGroupEditorPage::onToolBarClicked(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case VAPP_PHB_GROUP_EDITOR_CMD_SAVE:
        {
            if (m_group->getGroupName().isEmpty())
            {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
                    (WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_PHB_GROUP_NAME_EMPTY).getBuf());
                return;
            }
            else
            {
                VappPhbGroupEditorScr* scr = VFX_OBJ_DYNAMIC_CAST(getMainScr(), VappPhbGroupEditorScr);
                scr->m_groupManager->addGroup(m_group, m_storage);
            }
        }
        case VAPP_PHB_GROUP_EDITOR_CMD_CANCEL:
        {
            getMainScr()->popPage();
            break;
        }
    }
}


void VappPhbGroupEditorPage::onImageClicked(VfxObject* obj, VfxId id)
{
    if (!vapp_phb_usb_app_is_available())
    {
        return;
    }

    VcpCommandPopup *option;
    VFX_OBJ_CREATE(option, VcpCommandPopup, this);

    option->setText(VFX_WSTR_RES(STR_ID_VAPP_PHB_SET_PHOTO));

    option->addItem(VAPP_PHB_IMAGE_CMD_FILE, VFX_WSTR_RES(STR_ID_VAPP_PHB_SELECT_FROM_GALLERY), VCP_POPUP_BUTTON_TYPE_NORMAL);

#ifndef __LOW_COST_SUPPORT_COMMON__
#ifdef __MMI_CAMCORDER__
    option->addItem(VAPP_PHB_IMAGE_CMD_CAMERA, VFX_WSTR_RES(STR_ID_VAPP_PHB_TAKE_A_PHOTO), VCP_POPUP_BUTTON_TYPE_NORMAL);
#if defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__)
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_VIDEO_CALL_TYPE, NULL))
    {
        option->disableItem(VAPP_PHB_IMAGE_CMD_CAMERA);
    }
#endif /* defined(__MMI_VIDEO_TELEPHONY__) && defined(__OP01__) */
#endif /* __MMI_CAMCORDER__ */
#endif /* __LOW_COST_SUPPORT_COMMON__ */

    VfxU16 imageId;
    if (!(m_group->getImageSrc().isEmpty()) && srv_fmgr_fs_path_exist((WCHAR*)(m_group->getImage(imageId))) >= 0)
    {
        option->addItem(VAPP_PHB_IMAGE_CMD_REMOVE, VFX_WSTR_RES(STR_ID_VAPP_PHB_REMOVE_PHOTO), VCP_POPUP_BUTTON_TYPE_NORMAL);
    }

    option->addItem(VAPP_PHB_IMAGE_CMD_TYPE_TOTAL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);

    option->m_signalButtonClicked.connect(this, &VappPhbGroupEditorPage::onOptionClicked);

    option->show(VFX_TRUE);
}


void VappPhbGroupEditorPage::onOptionClicked(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case VAPP_PHB_IMAGE_CMD_FILE:
        {
            FMGR_FILTER filter;
            FMGR_FILTER_INIT(&filter);
        #if defined(__GDI_MEMORY_PROFILE_2__)   /* Able to select jpeg file if supported */
            FMGR_FILTER_SET(&filter, FMGR_TYPE_JPG);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_JPEG);
        #endif 
            FMGR_FILTER_SET(&filter, FMGR_TYPE_GIF);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_BMP);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_WBMP);
            FMGR_FILTER_SET(&filter, FMGR_TYPE_WBM);
        #if defined(GDI_USING_PNG)
            FMGR_FILTER_SET(&filter, FMGR_TYPE_PNG);
        #endif 
        #if defined(__DRM_V02__)
            FMGR_FILTER_SET(&filter, FMGR_TYPE_ODF);
        #endif /* defined(__DRM_V02__) */
            FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

            mmi_id cui_id = vcui_gallery_image_picker_create(getApp()->getGroupId(), MMI_FALSE, &filter);
            if (cui_id != GRP_ID_INVALID)
            {
                vfxSetCuiCallerScr(cui_id, getMainScr());
                vcui_gallery_picker_set_auto_close(cui_id, MMI_FALSE);
                vcui_gallery_run(cui_id);
            }
            break;
        }
    #ifndef __LOW_COST_SUPPORT_COMMON__
    #ifdef __MMI_CAMCORDER__
        case VAPP_PHB_IMAGE_CMD_CAMERA:
        {
            vcui_camco_err_code_enum errCode = vcui_standard_camera_launchable_check();
            if (errCode == VCUI_CAMCO_ERR_NONE)
            {
                vcui_camco_param_struct param;
                vcui_standard_camera_struct_init(&param);

                mmi_id cui_id = vcui_standard_camera_create(getApp()->getGroupId(), &param);
                if (cui_id != GRP_ID_INVALID)
                {
                    vfxSetCuiCallerScr(cui_id, getMainScr());
                    vcui_standard_camera_run(cui_id);
                }
            }
            else
            {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
                    (WCHAR*)VFX_WSTR_RES(vcui_standard_camera_get_err_string(errCode)).getBuf());
            }
            break;
        }
    #endif /* __MMI_CAMCORDER__ */
    #endif /* __LOW_COST_SUPPORT_COMMON__ */
        case VAPP_PHB_IMAGE_CMD_REMOVE:
        {
            VappPhbGroupNameFormItem *name = (VappPhbGroupNameFormItem*) (m_form->getItem(VAPP_PHB_GROUP_FORM_ITEM_NAME));
            VappPhbPhotoCp *image = name->getImageBtn();

            m_group->setImage(NULL, 0);
            image->setPhoto(m_group->getImageSrc());
            break;
        }
    }
}


void VappPhbGroupEditorPage::onRingClicked(VfxObject* obj, VfxId id)
{
    MMI_ID cui_id = vcui_tone_selector_create(getApp()->getGroupId());
    if (cui_id != GRP_ID_INVALID)
    {
        vfxSetCuiCallerScr(cui_id, getMainScr());

        VfxU16 filter;
        VCUI_TONE_SELECTOR_FILTER_INIT(filter);
        VCUI_TONE_SELECTOR_FILTER_SET(filter, (VCUI_TONE_SELECTOR_FILTER_RING | VCUI_TONE_SELECTOR_FILTER_FILE));

        vcui_tone_selector_set_filter(cui_id, filter);
        vcui_tone_selector_set_title_id(cui_id, STR_ID_VAPP_PHB_SELECT_RINGTONE, 0);

        VfxU16 toneId;
        VfxWString ringPath = m_group->getRingTone(toneId);

        if (ringPath.isEmpty() && toneId != 0)
        {
            vcui_tone_selector_set_hightlight_tone(cui_id, toneId);
        }

        vcui_tone_selector_run(cui_id);
    }
}


/***************************************************************************** 
 * Class VappPhbGroupMemberListPage
 *****************************************************************************/
VappPhbGroupMemberListPage::VappPhbGroupMemberListPage(ContactGroupManager *groupManager, VfxU8 groupId):
    m_groupManager(groupManager),
    m_groupId(groupId),
    m_list(NULL),
    m_toolBar(NULL),
    m_titleBar(NULL),
    m_cmdObj(NULL)
{
    m_cmd = VAPP_PHB_MARK_CMD_NONE;
    m_progress = NULL;
}


void VappPhbGroupMemberListPage::onInit()
{
    VfxPage::onInit();

    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle(m_groupManager->getGroupNameById(m_groupId));
    setTopBar(m_titleBar);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    setBottomBar(m_toolBar);
    m_toolBar->addItem(VAPP_PHB_GROUP_MEMBER_LIST_CMD_EDIT_GROUP, VFX_WSTR_RES(VAPP_PHB_STR_EDIT_GROUP), VAPP_PHB_IMG_CMD_EDIT_GROUP);
    m_toolBar->addItem(VAPP_PHB_GROUP_MEMBER_LIST_CMD_EDIT_MEMBER, VFX_WSTR_RES(VAPP_PHB_STR_EDIT_MEMBER), VAPP_PHB_IMG_CMD_ADD_MEMBER);
    m_toolBar->addItem(VAPP_PHB_GROUP_MEMBER_LIST_CMD_MESSAGE, VFX_WSTR_RES(VAPP_PHB_STR_MESSAGE), VAPP_PHB_IMG_CMD_MESSAGE);

    VFX_OBJ_CREATE(m_list, VappPhbListCp, this);
    m_list->setGroup(m_groupId, VFX_TRUE);
    m_list->setEmptyStr(STR_ID_VAPP_PHB_NO_MEMBERS);
    m_list->setSize(getSize());
    m_list->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

    m_toolBar->m_signalButtonTap.connect(this, &VappPhbGroupMemberListPage::onToolBarClicked);
    m_list->m_signalItemTapped.connect(this, &VappPhbGroupMemberListPage::onItemTaped);
    m_list->m_signalCount.connect(this, &VappPhbGroupMemberListPage::onCountChanged);
    m_groupManager->m_signalGroupManager.connect(this, &VappPhbGroupMemberListPage::onGroupListChanged);
    // myler add
    m_groupManager->m_signalGroupMember.connect(this, &VappPhbGroupMemberListPage::onGroupMemberChanged);
}


void VappPhbGroupMemberListPage::onBack()
{
    if (m_cmd == VAPP_PHB_MARK_CMD_MESSAGE || m_cmd == VAPP_PHB_MARK_CMD_DELETE_GROUP_MEMBER)
    {
        onCmdEnd(m_cmd);

        VFX_OBJ_CLOSE(m_cmdObj);
    }
    else
    {
        VfxPage::onBack();
    }
}


void VappPhbGroupMemberListPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


mmi_ret VappPhbGroupMemberListPage::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_PHB_LIST_RESULT:
        {
            vcui_phb_list_result_event_struct *result = (vcui_phb_list_result_event_struct*) evt;

            if (result->result && result->select_count > 0)
            {
                mmi_phb_contact_id *idArray = (mmi_phb_contact_id*) mmi_frm_temp_alloc(result->select_count * sizeof(mmi_phb_contact_id));

                for (VfxU32 i = 0; i < result->select_count; i++)
                {
                    idArray[i] = vcui_phb_list_get_contact_id_by_index(((mmi_group_event_struct*) evt)->sender_id , i);
                }

                m_groupManager->addGroupMembers(idArray, result->select_count, m_groupId);

                // show progress bar
                VFX_OBJ_CREATE(m_progress, VcpIndicatorPopup, this);
                m_progress->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY_WITH_CANCEL_BUTTON);
                m_progress->setText(VFX_WSTR_RES(STR_ID_VAPP_PHB_PROCESSING));
                m_progress->m_signalCanceled.connect(this, &VappPhbGroupMemberListPage::onCancelClick);
                m_progress->show(VFX_TRUE);

                // stop refresh list
                m_list->setRefreshFlag(VFX_TRUE);

                mmi_frm_temp_free(idArray);

              //  m_list->getList();
            }

            vcui_phb_list_close(((mmi_group_event_struct*) evt)->sender_id);
            return MMI_RET_OK;
        }
    }

    return VfxPage::onProc(evt);
}


void VappPhbGroupMemberListPage::onItemTaped(VcpGroupListMenu *list, VcpMenuPos pos)
{
    if (pos.group >= 0 && pos.pos >= 0)
    {
        /*         MAUI_03207314                */
       // mmi_id cui_id = vcui_phb_contact_viewer_create(getApp()->getGroupId());
      //  vcui_phb_contact_viewer_set_contact_id(cui_id, m_list->getId(pos.pos, pos.group));
     //   vcui_phb_contact_viewer_run(cui_id);

        VappPhbViewerProfilePage *viewPage;
        VFX_OBJ_CREATE_EX(viewPage, VappPhbViewerProfilePage, getMainScr(), (m_list->getId(pos.pos, pos.group), VFX_TRUE));
        getMainScr()->pushPage(VFX_ID_NULL, viewPage);
    }
}


void VappPhbGroupMemberListPage::onToolBarClicked(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case VAPP_PHB_GROUP_MEMBER_LIST_CMD_EDIT_GROUP:
            editGroup();
            break;

        case VAPP_PHB_GROUP_MEMBER_LIST_CMD_EDIT_MEMBER:
            editMember();
            break;
#ifdef __MMI_PHB_MARK_MESSAGE__

        case VAPP_PHB_GROUP_MEMBER_LIST_CMD_MESSAGE:
            sendMessage();
            break;
#endif
            
    }
}


void VappPhbGroupMemberListPage::onOptionClicked(VfxObject *obj, VfxId id)
{
    switch (id)
    {
        case VAPP_PHB_GROUP_ADD_GROUP_MEMBER:
            {
                addMember();
                break;
            }

        case VAPP_PHB_GROUP_REMOVE_GROUP_MEMBER:
            {
                VappPhbMarkDeleteGroupMemberObj *obj;
                VFX_OBJ_CREATE_EX(obj, VappPhbMarkDeleteGroupMemberObj, this, (m_list, this, this, m_groupManager, m_groupId));

                m_cmdObj = obj;
                break;
            }

    #if defined(__OP02__)
        case VAPP_PHB_GROUP_MOVE_GROUP_MEMBER:
            {
                VappPhbMarkMoveGroupMemberObj *obj;
                VFX_OBJ_CREATE_EX(obj, VappPhbMarkMoveGroupMemberObj, this, (m_list, this, this, m_groupManager, m_groupId));

                m_cmdObj = obj;
                break;
            }
    #endif /* defined(__OP02__) */
    }
}


void VappPhbGroupMemberListPage::editGroup()
{
    VappPhbGroupEditorScr *scr;
    VFX_OBJ_CREATE_EX(scr, VappPhbGroupEditorScr, getApp(), (m_groupManager->getStorageById(m_groupId), m_groupManager, m_groupId));

    scr->show();
}


void VappPhbGroupMemberListPage::addMember()
{
    mmi_id cui_id = vcui_phb_list_create(getMainScr()->getGroupId());
    vfxSetCuiCallerScr(cui_id, getMainScr());

    vcui_phb_list_set_title_str(cui_id, VAPP_PHB_STR_ADD_GROUP_MEMBER);
    vcui_phb_list_set_req_type(cui_id, VAPP_PHB_LIST_MULTI_SELECTOR);
    vcui_phb_list_set_group(cui_id, m_groupId, MMI_FALSE);
    vcui_phb_list_set_storage(cui_id, ContactStorage::getMask(m_groupManager->getStorageById(m_groupId)));
    vcui_phb_list_run(cui_id);
}


void VappPhbGroupMemberListPage::editMember()
{
    if (m_list->getGroupCount() == 0)
    {
        addMember();
    }
    else
    {
        VcpCommandPopup *option;
        VFX_OBJ_CREATE(option, VcpCommandPopup, this);

        option->setText(VFX_WSTR_RES(VAPP_PHB_STR_EDIT_GROUP_MEMBER));

        option->addItem(VAPP_PHB_GROUP_ADD_GROUP_MEMBER, VFX_WSTR_RES(VAPP_PHB_STR_ADD_GROUP_MEMBER), VCP_POPUP_BUTTON_TYPE_NORMAL);
        option->addItem(VAPP_PHB_GROUP_REMOVE_GROUP_MEMBER, VFX_WSTR_RES(VAPP_PHB_STR_REMOVE_GROUP_MEMBER), VCP_POPUP_BUTTON_TYPE_NORMAL);
    #if defined(__OP02__)
        option->addItem(VAPP_PHB_GROUP_MOVE_GROUP_MEMBER, VFX_WSTR_RES(VAPP_PHB_STR_MOVE_GROUP_MEMBER), VCP_POPUP_BUTTON_TYPE_NORMAL);
    #endif
        option->addItem(VAPP_PHB_GROUP_EDIT_GROUP_MEMBER_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);

        option->m_signalButtonClicked.connect(this, &VappPhbGroupMemberListPage::onOptionClicked);

        option->show(VFX_TRUE);
    }
}

#ifdef __MMI_PHB_MARK_MESSAGE__

void VappPhbGroupMemberListPage::sendMessage()
{
    VappPhbMarkMsgObj *obj;
    VFX_OBJ_CREATE_EX(obj, VappPhbMarkMsgObj, this, (m_list, this, this));

    m_cmdObj = obj;
}
#endif


void VappPhbGroupMemberListPage::onCancelClick(VfxObject *obj, VfxFloat num)
{
    if (m_progress)
    {
        m_progress->exit(VFX_TRUE);
        m_progress = NULL;
    }

    m_groupManager->cancelGroupOp(SRV_PHB_GROUP_OP_TYPE_TOTAL);
}


void VappPhbGroupMemberListPage::onGroupMemberChanged(ContactGroupManager *groupManager)
{
    if (m_progress)
    {
        m_progress->exit(VFX_TRUE);
        m_progress = NULL;
    }
    m_list->setRefreshFlag(VFX_FALSE);

    m_list->getList(); // updata group member list

    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G4_PHB, "[VAPP_CONTACT_GROUP]onGroupMemberChanged--groupManager: 0x%0x\n", groupManager);
}


void VappPhbGroupMemberListPage::onCountChanged(VappPhbListCp* list, VfxU32 count)
{
    if (count == 0)
    {
        m_toolBar->changeItem(VAPP_PHB_GROUP_MEMBER_LIST_CMD_EDIT_MEMBER, VFX_WSTR_RES(VAPP_PHB_STR_ADD_MEMBER), VAPP_PHB_IMG_CMD_ADD_MEMBER);
        m_toolBar->setDisableItem(VAPP_PHB_GROUP_MEMBER_LIST_CMD_MESSAGE, VFX_TRUE);
    }
    else
    {
        m_toolBar->changeItem(VAPP_PHB_GROUP_MEMBER_LIST_CMD_EDIT_MEMBER, VFX_WSTR_RES(VAPP_PHB_STR_EDIT_MEMBER), VAPP_PHB_IMG_CMD_EDIT_MEMBER);
        m_toolBar->setDisableItem(VAPP_PHB_GROUP_MEMBER_LIST_CMD_MESSAGE, VFX_FALSE);
    }
}


void VappPhbGroupMemberListPage::onGroupListChanged(ContactGroupManager* manager, VfxU8 groupId, srv_phb_group_op_type_enum op)
{
    if (groupId == m_groupId && op == SRV_PHB_GROUP_OP_TYPE_UPD)
    {
        m_titleBar->setTitle(m_groupManager->getGroupNameById(m_groupId));
    }
}


void VappPhbGroupMemberListPage::onCmdStart(vapp_phb_mark_cmd_type_enum cmd)
{
    if (cmd == VAPP_PHB_MARK_CMD_MESSAGE || cmd == VAPP_PHB_MARK_CMD_DELETE_GROUP_MEMBER || cmd == VAPP_PHB_MARK_CMD_MOVE_GROUP_MEMBER)
    {
        m_cmd = cmd;
        m_list->m_signalItemTapped.disconnect(this, &VappPhbGroupMemberListPage::onItemTaped);

        if (cmd == VAPP_PHB_MARK_CMD_DELETE_GROUP_MEMBER)
        {
            m_titleBar->setTitle(VFX_WSTR_RES(VAPP_PHB_STR_REMOVE_GROUP_MEMBER));
        }
        else if (cmd == VAPP_PHB_MARK_CMD_MOVE_GROUP_MEMBER)
        {
            m_titleBar->setTitle(VFX_WSTR_RES(VAPP_PHB_STR_MOVE_GROUP_MEMBER));
        }
        else
        {
            m_titleBar->setTitle(VFX_WSTR_RES(VAPP_PHB_STR_MESSAGE));
        }
    }
}


void VappPhbGroupMemberListPage::onCmdEnd(vapp_phb_mark_cmd_type_enum cmd)
{
    if (cmd == VAPP_PHB_MARK_CMD_MESSAGE || cmd == VAPP_PHB_MARK_CMD_DELETE_GROUP_MEMBER || cmd == VAPP_PHB_MARK_CMD_MOVE_GROUP_MEMBER)
    {
        m_cmd = VAPP_PHB_MARK_CMD_NONE;
        m_list->setAlignField(MMI_PHB_CONTACT_FIELD_NAME);
        m_list->setListType(VAPP_PHB_LIST_NORMAL);

        m_list->m_signalItemTapped.connect(this, &VappPhbGroupMemberListPage::onItemTaped);
        setBottomBar(m_toolBar);

        m_titleBar->setTitle(m_groupManager->getGroupNameById(m_groupId));
    }
}


/***************************************************************************** 
 * Class VappPhbGroupSelectorPage
 *****************************************************************************/
VappPhbGroupSelectorPage::VappPhbGroupSelectorPage(phb_storage_enum storage, VfxU8 groupId, VfxBool viewOnly):
    m_storage(storage),
    m_groupId(groupId),
    m_viewOnly(viewOnly),
    m_group(NULL),
    m_list(NULL)
{
}


void VappPhbGroupSelectorPage::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *title;
    VFX_OBJ_CREATE(title, VcpTitleBar, this);
    title->setTitle(VFX_WSTR_RES(m_viewOnly ? STR_ID_VAPP_PHB_MOVE_TO : STR_ID_VAPP_PHB_SELECT_GROUP));
    setTopBar(title);

    VFX_OBJ_CREATE_EX(m_group, ContactGroupManager, this, (m_storage));

    VFX_OBJ_CREATE(m_list, VcpListMenu, this);
    m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_list->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);
    m_list->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE);
    m_list->setSize(getSize());
    m_list->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);

   m_list->setContentProvider(this);

   m_list->m_signalItemSelectionStateChanged.connect(this, &VappPhbGroupSelectorPage::onStateChanged);
   m_list->m_signalItemTapped.connect(this, &VappPhbGroupSelectorPage::onItemTaped);
}


void VappPhbGroupSelectorPage::onEntered()
{
    m_list->resetAllItems(VFX_TRUE);
}


void VappPhbGroupSelectorPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


VfxBool VappPhbGroupSelectorPage::getItemText(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxWString &text,                // [OUT] the text resource
    VcpListMenuTextColorEnum &color  // [OUT] the text color
    )
{
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        if (m_viewOnly)
        {
            text = m_group->getGroupName(index);
            return VFX_TRUE;
        }

        if (index == 0)
        {
            text = VFX_WSTR_RES(VAPP_PHB_STR_NO_GROUP);
        }
        else if (index == m_group->getGroupCount() + 1)
        {
            text = VFX_WSTR_RES(VAPP_PHB_STR_CREATE_NEW_GROUP);
        }
        else
        {
            text = m_group->getGroupName(index - 1);
        }
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxBool VappPhbGroupSelectorPage::getItemImage(
    VfxU32 index,                    // [IN] the index of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxImageSrc &image               // [OUT] the image resource
    )
{
    if (fieldType == VCP_LIST_MENU_FIELD_DISCLOSURE_IMG)
    {
        if (index == m_group->getGroupCount() + 1)
        {
            image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


VcpListMenuItemStateEnum VappPhbGroupSelectorPage::getItemState(
    VfxU32 index                     // [IN] index of the item
    ) const
{
    if (m_viewOnly)
    {
        if (m_group->getGroupId(index) == m_groupId)
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }

        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }

    if (index == 0)
    {
        if (m_groupId == MMI_PHB_INVALID_GROUP_ID)
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
    }
    else if (index == m_group->getGroupCount() + 1)
    {
        return VCP_LIST_MENU_ITEM_STATE_NONE;
    }
    else if (m_group->getGroupId(index - 1) == m_groupId)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }

    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}


VfxBool VappPhbGroupSelectorPage::getItemIsDisabled(
    VfxU32 index                     // [IN] the index of item
    ) const
{
    if (index == m_group->getGroupCount() + 1)
    {
        if (m_group->getGroupCount() == m_group->getMaxGroupCount(m_storage))
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}


VfxBool VappPhbGroupSelectorPage::getItemStateValidation(
    VfxU32 index,                    // [IN] index of the item
    VcpListMenuItemStateEnum state   // [IN] the state to be checked
    ) const
{
    if (index == m_group->getGroupCount() + 1)
    {
        if (state == VCP_LIST_MENU_ITEM_STATE_SELECTED)
        {
            return VFX_FALSE;
        }
    }

    return VFX_TRUE;
}


VfxU32 VappPhbGroupSelectorPage::getCount() const
{
		VfxU32 temp_count = 0;
    if (m_viewOnly)
    {
        //return m_group->getGroupCount();
        temp_count = m_group->getGroupCount();
    }
    else
    {
    #ifdef __LOW_COST_SUPPORT_COMMON__
        //return m_group->getGroupCount() + 1; // 1 for slim remove create new group
        temp_count = m_group->getGroupCount() + 1;
    #else
        //return m_group->getGroupCount() + 1 + 1; // 1 for no group, 1 for create new group
        temp_count =  m_group->getGroupCount() + 1 + 1; 
    #endif
    }
    return temp_count;
}


void VappPhbGroupSelectorPage::onStateChanged(VcpListMenu *list, VfxU32 index, VcpListMenuItemStateEnum state)
{
    if (state == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        if (m_viewOnly)
        {
            m_groupId = m_group->getGroupId(index);
            return;
        }

        if (index == 0)
        {
            m_groupId = MMI_PHB_INVALID_GROUP_ID;
        }
        else if (index == m_group->getGroupCount() + 1)
        {
        }
        else
        {
            m_groupId = m_group->getGroupId(index - 1);
        }
    }
}


void VappPhbGroupSelectorPage::onItemTaped(VcpListMenu *list, VfxU32 index)
{
    if (m_viewOnly)
    {
        m_signalGroupSelected.postEmit(this, m_group->getGroupId(index));
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->mustShowNextFrame();
        getMainScr()->popPage();
        return;
    }

    if (index == 0)
    {
        m_signalGroupSelected.postEmit(this, MMI_PHB_INVALID_GROUP_ID);
        getMainScr()->popPage();
    }
    else if (index == m_group->getGroupCount() + 1)
    {
        VappPhbGroupEditorScr *scr;
        VFX_OBJ_CREATE_EX(scr, VappPhbGroupEditorScr, getApp(), (m_storage, m_group));
        scr->show();

        m_group->m_signalGroupManager.connect(this, &VappPhbGroupSelectorPage::onGroupAdded);
    }
    else
    {
        m_signalGroupSelected.postEmit(this, m_group->getGroupId(index - 1));
        getMainScr()->popPage();
    }
}


void VappPhbGroupSelectorPage::onGroupAdded(ContactGroupManager* manager, VfxU8 id, srv_phb_group_op_type_enum op)
{
    m_list->resetAllItems(VFX_TRUE);
}
#endif /* __MMI_PHB_CALLER_GROUP__ */


