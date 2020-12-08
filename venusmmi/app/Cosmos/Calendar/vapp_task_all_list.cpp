/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_cal_task_all.cpp
 *
 * Project:
 * --------
 *  Cosmos
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "mmi_features.h"
#include "vfx_mc_include.h"
#include "vfx_adp_device.h"

#include "vcp_include.h"
#include "mmi_rp_vapp_calendar_def.h"
#include "vapp_task_all_list.h"
#include "vapp_cal_view_detail.h"
#include "vapp_cal_edit.h"
#include "vapp_cal_utility.h"
#include "vapp_cal_search.h"
#include "vapp_cal_reminder.h"
#include "vcp_menu_popup.h"
#include "vcui_cal_list_gprot.h"

extern "C"
{
    #include "todolistsrvgprot.h"
}


VFX_IMPLEMENT_CLASS("VappTaskAllListPage", VappTaskAllListPage, VfxPage);

void VappTaskAllListPage::onInit()
{
    VfxPage::onInit();

    mmi_frm_cb_reg_event(EVT_ID_SRV_TDL_OP, updateTaskListPage, this);

    updateListData();


    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
    m_titleBar->setTitle((VfxResId)STR_ID_VAPP_CAL_TASKS);
    setTopBar(m_titleBar);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->addItem(VAPP_TASK_LIST_ADD, (VfxResId)STR_ID_VAPP_CAL_ADD, VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
#ifndef __LOW_COST_SUPPORT_COMMON__
    m_toolBar->addItem(VAPP_TASK_LIST_SEARCH, (VfxResId)STR_GLOBAL_SEARCH, VCP_IMG_TOOL_BAR_COMMON_ITEM_SEARCH);
#endif
    m_toolBar->addItem(VAPP_TASK_LIST_DELETE, (VfxResId)STR_ID_VAPP_CAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_toolBar->m_signalButtonTap.connect(this, &VappTaskAllListPage::onToolBarClicked);
    setBottomBar(m_toolBar);

    if (m_listMgr->getListCount() == 0)
    {
#ifndef __LOW_COST_SUPPORT_COMMON__
        m_toolBar->setDisableItem(VAPP_TASK_LIST_SEARCH, VFX_TRUE);
#endif
        m_toolBar->setDisableItem(VAPP_TASK_LIST_DELETE, VFX_TRUE);
    }

    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listMenu->setContentProvider((IVcpListMenuContentProvider*)this);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);

    m_listMenu->setPos(0, 0);
    m_listMenu->setSize(getSize());
    m_listMenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE, 
                                VFX_FRAME_ALIGNER_MODE_SIDE, 
                                VFX_FRAME_ALIGNER_MODE_SIDE);

    if (m_entryType != VAPP_TASK_ALL_ENTRY_UC)
    {
        m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_TRUE);
        m_listMenu->m_signalItemSelectionStateChanged.connect(this, &VappTaskAllListPage::onSelListMenuClicked);
        m_listMenu->m_signalItemTapped.connect(this, &VappTaskAllListPage::onListMenuClicked);
        m_listMenu->m_signalCmdButtonClicked.connect(this, &VappTaskAllListPage::onCommBtnClicked);
        m_listMenu->m_signalItemLongTapped.connect(this, &VappTaskAllListPage::onListMenuLongTap);
    }
    else
    {
        m_listMenu->m_signalItemTapped.connect(this, &VappTaskAllListPage::onListMenuClicked);
        // hide toolbar
        setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, NULL, VFX_TRUE);
    }

    m_isMutiDelProcessing = VFX_FALSE;
    m_dataChangedType = SRV_TDL_OP_TOTAL;
    
    VFX_ALLOC_MEM(path, VAPP_CAL_MAX_FILE_PATH_SIZE, this);
}

void VappTaskAllListPage::onDeinit()
{
   
    VFX_FREE_MEM(path);

   
    mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_OP, updateTaskListPage, this);
    VfxPage::onDeinit();
}

void VappTaskAllListPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    // if a new item is added
    if (m_dataChangedType == SRV_TDL_OP_ADD || m_dataChangedType == SRV_TDL_OP_UPDATE)	
    {
        m_listMenu->setVisibleMenuRegion(m_selIdx, -1, VFX_TRUE);
    }

    m_dataChangedType = SRV_TDL_OP_TOTAL;
}

void VappTaskAllListPage::onBack()
{
    if (m_listMenu->getMenuMode() == VCP_LIST_MENU_MODE_MULTI_SELECTION)	
    {
        m_toolBar->removeItem(VAPP_TASK_SEL_LIST_MARK_ALL);
        m_toolBar->removeItem(VAPP_TASK_SEL_LIST_DELETE);
        m_toolBar->removeItem(VAPP_TASK_SEL_LIST_CANCEL);
        m_toolBar->addItem(VAPP_TASK_LIST_ADD, (VfxResId)STR_ID_VAPP_CAL_ADD, VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
#ifndef __LOW_COST_SUPPORT_COMMON__
        m_toolBar->addItem(VAPP_TASK_LIST_SEARCH, (VfxResId)STR_GLOBAL_SEARCH, VCP_IMG_TOOL_BAR_COMMON_ITEM_SEARCH);
#endif
        m_toolBar->addItem(VAPP_TASK_LIST_DELETE, (VfxResId)STR_ID_VAPP_CAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
        m_titleBar->setTitle((VfxResId)STR_ID_VAPP_CAL_TASKS);

        m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
        m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_TRUE);
    }
    else
    {
        VfxPage::onBack();
    }
}


void VappTaskAllListPage::onQueryRotateEx( VfxScreenRotateParam &param)
{
    if (m_entryType == VAPP_TASK_ALL_ENTRY_TASK)
    {
        param.rotateTo =  VFX_SCR_ROTATE_TYPE_NORMAL;
    }

}


VfxBool VappTaskAllListPage::getItemText(
                                VfxU32 index,                  
                                VcpListMenuFieldEnum fieldType,  
                                VfxWString &text,                
                                VcpListMenuTextColorEnum &color)
{
    if (!m_listMgr->getListCount())
    {
        return VFX_TRUE;
    }

    VfxU16 storeIndex;
    storeIndex = m_listMgr->getListItemStoreIndex(index);

    srv_tdl_task_short_struct *buffer;
    srv_tdl_get_cache(
                    (void**) &buffer, 
                    sizeof(srv_tdl_task_short_struct),
                    SRV_TDL_VCAL_TASK, 
                    storeIndex);

    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        text.loadFromMem((VfxWChar*) buffer->subject);
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
        VappCalUtility::getListItemDateTimeStr(
                                        fieldType, 
                                        SRV_TDL_VCAL_TASK, 
                                        buffer,
                                        text);
    }

    if (buffer->status == SRV_TDL_STATUS_UNDONE)
    {
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    }
    else
    {
        color = VCP_LIST_MENU_TEXT_COLOR_DISABLED;
    }

    return VFX_TRUE;
}

VfxBool VappTaskAllListPage::getItemImage(
                                    VfxU32 index,                  
                                    VcpListMenuFieldEnum fieldType,  
                                    VfxImageSrc &image)
{
    if (!m_listMgr->getListCount())
    {
        return VFX_TRUE;
    }

    VfxU16 storeIndex;
    storeIndex = m_listMgr->getListItemStoreIndex(index);

    srv_tdl_task_short_struct *buffer;
    srv_tdl_get_cache(
                    (void**) &buffer, 
                    sizeof(srv_tdl_task_short_struct),
                    SRV_TDL_VCAL_TASK, 
                    storeIndex);

    if (fieldType == VCP_LIST_MENU_FIELD_ICON)
    {
        VAPP_CAL_PRIORITY_ENUM priority = VappCalEditPage::convertPriorityStoM((srv_vcal_priority_enum)buffer->priority);

        switch(priority)
        {
            case VAPP_CAL_PRIORITY_HIGH:
                image.setResId(IMG_ID_VAPP_CAL_HIGH);
                break;

            case VAPP_CAL_PRIORITY_MEDIUM:
                image.setResId(IMG_ID_VAPP_CAL_MEDIUM);
                break;

            case VAPP_CAL_PRIORITY_LOW:
                image.setResId(IMG_ID_VAPP_CAL_LOW);
                break;

            default:
                break;
        }
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL)
    {
        if (buffer->status == SRV_TDL_STATUS_UNDONE)
        {
            image.setResId(IMG_ID_VAPP_CAL_TASK_UNDO);
        }
        else
        {
            image.setResId(IMG_ID_VAPP_CAL_TASK_DONE);
        }
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED)
    {
        if (buffer->status == SRV_TDL_STATUS_UNDONE)
        {
            image.setResId(IMG_ID_VAPP_CAL_TASK_DONE);
        }
        else
        {
            image.setResId(IMG_ID_VAPP_CAL_TASK_UNDO);
        }
    }

    return VFX_TRUE;
}

VfxU32 VappTaskAllListPage::getCount() const
{
    return (m_listMgr->getListCount());
}

VfxBool VappTaskAllListPage::getMenuEmptyText(VfxWString &text,VcpListMenuTextColorEnum &color)
{
    text = VfxWString(VFX_WSTR_RES(STR_ID_VAPP_CAL_NO_TASK));
    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    return VFX_TRUE;
}

VcpListMenuItemStateEnum VappTaskAllListPage::getItemState(VfxU32 index) const
{
    return ((VcpListMenuItemStateEnum)m_listMgr->getSelListState(index));
}

void VappTaskAllListPage::updateListData()
{
    VFX_OBJ_CREATE_EX(m_listMgr, VappCalListMgr, this, (SRV_TDL_VCAL_TASK, VAPP_TASK_MAX_COUNT));
    m_listMgr->getAllList(SRV_TDL_VCAL_TASK);
    m_listMgr->sortList(SRV_TDL_SORT_TYPE_ENTRY_TIME);
}

void VappTaskAllListPage::onToolBarClicked(VfxObject *sender, VfxId id)
{
    switch(id)
    {
        case VAPP_TASK_LIST_ADD:
        {
            if (srv_tdl_is_full(SRV_TDL_VCAL_TASK))
            {  
                VcpConfirmPopup *popup;
                VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
                popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
                popup->setText((VfxResId)STR_ID_VAPP_CAL_MEM_FULL);
                popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
                popup->setAutoDestory(VFX_FALSE);
                popup->show(VFX_TRUE);      
                break;
            }

            VappCalEditPage *editPage;
            VfxDateTime dateTime;
            dateTime.setCurrentTime();
            VFX_OBJ_CREATE_EX(
                            editPage, 
                            VappCalEditPage, 
                            getMainScr(), 
                            (SRV_TDL_VCAL_TASK, 0, VAPP_CAL_OPERATION_TYPE_ADD, &(dateTime.getDateTime())));
            getMainScr()->pushPage(0, editPage);

            break;
        }

        #ifndef __LOW_COST_SUPPORT_COMMON__
        case VAPP_TASK_LIST_SEARCH:
        {
        #ifndef __VAPP_CAL_TEST_MODE__
            VappCalSearchPage *searchPage;
            VFX_OBJ_CREATE_EX(searchPage, VappCalSearchPage, getMainScr(), (SRV_TDL_VCAL_TASK));
            getMainScr()->pushPage(0, searchPage);
        #else
            {
                VappCalRemInfoStruct arg;
                arg.expiriedIdx = 0;
                arg.type = SRV_TDL_VCAL_EVENT;

                VfxAppLauncher::launch( 
                                    VAPP_CALENDAR,
                                    VFX_OBJ_CLASS_INFO(VappCalReminderApp),
                                    GRP_ID_ROOT,
                                    &arg,
                                    sizeof(VappCalRemInfoStruct));
            }
        #endif /* __VAPP_CAL_TEST_MODE__ */

            break;
        }
        #endif
        case VAPP_TASK_LIST_DELETE:
        {

#ifndef __VAPP_CAL_TEST_MODE__
            m_markAllBtn = VFX_TRUE;
            m_toolBar->removeItem(VAPP_TASK_LIST_ADD);
#ifndef __LOW_COST_SUPPORT_COMMON__
            m_toolBar->removeItem(VAPP_TASK_LIST_SEARCH);
#endif
            m_toolBar->removeItem(VAPP_TASK_LIST_DELETE);
            m_toolBar->addItem(VAPP_TASK_SEL_LIST_MARK_ALL, (VfxResId)STR_ID_VAPP_CAL_MARK_ALL, VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
            m_toolBar->addItem(VAPP_TASK_SEL_LIST_DELETE, (VfxResId)STR_ID_VAPP_CAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
            m_toolBar->addItem(VAPP_TASK_SEL_LIST_CANCEL, (VfxResId)STR_ID_VAPP_CAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
            m_toolBar->setDisableItem(VAPP_TASK_SEL_LIST_DELETE, VFX_TRUE);

            m_titleBar->setTitle((VfxResId)STR_ID_VAPP_TASK_DELETE_TASK_TITLE);

            m_listMgr->setSelListState(VCP_LIST_MENU_ITEM_STATE_UNSELECTED);

            m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_TRUE);
            m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_TRUE);
#else
            {
                VappCalRemInfoStruct arg;
                arg.expiriedIdx = 1;
                arg.type = SRV_TDL_VCAL_EVENT;

                VfxAppLauncher::launch( 
                                    VAPP_CALENDAR,
                                    VFX_OBJ_CLASS_INFO(VappCalReminderApp),
                                    GRP_ID_ROOT,
                                    &arg,
                                    sizeof(VappCalRemInfoStruct));
            }
        #endif /* __VAPP_CAL_TEST_MODE__ */

                break;
            }
        case VAPP_TASK_SEL_LIST_MARK_ALL:
        {
            if (m_listMgr->getSelListMarkedCount() == m_listMgr->getListCount())
            {
                m_listMgr->setSelListState(VCP_LIST_MENU_ITEM_STATE_UNSELECTED);
                m_toolBar->changeItem(VAPP_TASK_SEL_LIST_MARK_ALL, VFX_WSTR_RES(STR_ID_VAPP_CAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
                m_markAllBtn = VFX_TRUE;
            }
            else if (m_listMgr->getSelListMarkedCount() == 0)
            {
                m_listMgr->setSelListState(VCP_LIST_MENU_ITEM_STATE_SELECTED);
                m_toolBar->changeItem(VAPP_TASK_SEL_LIST_MARK_ALL, VFX_WSTR_RES(STR_ID_VAPP_CAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
                m_markAllBtn = VFX_FALSE;
            }
            else
            {
                if (m_markAllBtn == VFX_TRUE)
                {
                    m_listMgr->setSelListState(VCP_LIST_MENU_ITEM_STATE_SELECTED);
                    m_toolBar->changeItem(VAPP_TASK_SEL_LIST_MARK_ALL, VFX_WSTR_RES(STR_ID_VAPP_CAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
                    m_markAllBtn = VFX_FALSE;
                }
                else
                {
                    m_listMgr->setSelListState(VCP_LIST_MENU_ITEM_STATE_UNSELECTED);
                    m_toolBar->changeItem(VAPP_TASK_SEL_LIST_MARK_ALL, VFX_WSTR_RES(STR_ID_VAPP_CAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
                    m_markAllBtn = VFX_TRUE;
                }
            }

            if (m_listMgr->getSelListMarkedCount() == 0)
            {
                m_toolBar->setDisableItem(VAPP_TASK_SEL_LIST_DELETE, VFX_TRUE);
            }
            else
            {
                m_toolBar->setDisableItem(VAPP_TASK_SEL_LIST_DELETE, VFX_FALSE);
            }

            m_listMenu->resetAllItems(VFX_TRUE);
            break;
        }
        case VAPP_TASK_SEL_LIST_DELETE:
        {
            VfxResId strId = (m_listMgr->getSelListMarkedCount() > 1) ? STR_ID_VAPP_CAL_DELETE_TASKS : STR_ID_VAPP_CAL_DELETE_ONE_TASK;
            VfxWString str(strId);

            VfxWChar tempBuf[3];
            kal_wsprintf(tempBuf, "%d", m_listMgr->getSelListMarkedCount());

            str += VFX_WSTR_RES(STR_ID_VAPP_CAL_LEFT_PARENTHESES);
            str += VFX_WSTR_MEM(tempBuf);
            str += VFX_WSTR_RES(STR_ID_VAPP_CAL_RIGHT_PARENTHESES);
            str += VFX_WSTR_RES(STR_ID_VAPP_CAL_QUESTION_MARK);

            VcpConfirmPopup *confirmPopup;

            VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
            confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            confirmPopup->setText(str);

            confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            confirmPopup->setCustomButton(
                                VFX_WSTR_RES(STR_ID_VAPP_CAL_DELETE),
                                VFX_WSTR_RES(STR_ID_VAPP_CAL_CANCEL),
                                VCP_POPUP_BUTTON_TYPE_WARNING,
                                VCP_POPUP_BUTTON_TYPE_CANCEL);

            confirmPopup->setAutoDestory(VFX_FALSE);    
            confirmPopup->m_signalButtonClicked.connect(this, &VappTaskAllListPage::onDeleteConfirm);
            confirmPopup->show(VFX_TRUE);

            m_confirmPopupWeakPtr = confirmPopup;

            break;
        }
        case VAPP_TASK_SEL_LIST_CANCEL:
        {
            m_toolBar->removeItem(VAPP_TASK_SEL_LIST_MARK_ALL);
            m_toolBar->removeItem(VAPP_TASK_SEL_LIST_DELETE);
            m_toolBar->removeItem(VAPP_TASK_SEL_LIST_CANCEL);
            m_toolBar->addItem(VAPP_TASK_LIST_ADD, (VfxResId)STR_ID_VAPP_CAL_ADD, VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
#ifndef __LOW_COST_SUPPORT_COMMON__
            m_toolBar->addItem(VAPP_TASK_LIST_SEARCH, (VfxResId)STR_GLOBAL_SEARCH, VCP_IMG_TOOL_BAR_COMMON_ITEM_SEARCH);
#endif
            m_toolBar->addItem(VAPP_TASK_LIST_DELETE, (VfxResId)STR_ID_VAPP_CAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);

            m_titleBar->setTitle((VfxResId)STR_ID_VAPP_CAL_TASKS);

            m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
            m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_TRUE);
            break;
        }
        default:
            break;
    }
}

void VappTaskAllListPage::onListMenuClicked(VcpListMenu *sender, VfxU32 index)
{
    if (m_listMenu->getMenuMode() != VCP_LIST_MENU_MODE_NORMAL)
    {
        return;
    }

    VfxU16 storeIdx = m_listMgr->getListItemStoreIndex(index);

    if (m_entryType != VAPP_TASK_ALL_ENTRY_UC)
    {

        VappCalViewDetailPage *viewPage;
        VFX_OBJ_CREATE_EX(
                    viewPage, 
                    VappCalViewDetailPage,
                    getMainScr(),
                    (SRV_TDL_VCAL_TASK, storeIdx));

        getMainScr()->pushPage(0, viewPage);
    }
#ifdef __MMI_VCALENDAR__
    else
    {
        // build a vcalenda file and send event

        srv_tdl_task_struct *buffer;

        VFX_SYS_ALLOC_MEM(buffer, sizeof(srv_tdl_task_struct));

        if (srv_tdl_get(
                    buffer, 
                    sizeof(srv_tdl_task_struct), 
                    SRV_TDL_VCAL_TASK, 
                    storeIdx) == SRV_TDL_RESULT_OK)
        {
            if (VappCalUtility::buildTempVcalFile(path, (void*)buffer, SRV_TDL_VCAL_TASK, VAPP_CAL_BUILD_FOLDER_FOR_UC) != NULL)
            {
                // send event with path;

                VFX_FREE_MEM(buffer);
                vcui_cal_list_result_struct evt;
                MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_CAL_ITEM_SELECTED, getApp()->getGroupId());

                evt.path = path;

                getApp()->sendToCaller((mmi_group_event_struct*)&evt);
            }
        }

        VFX_FREE_MEM(buffer);
    }
#endif
}

void VappTaskAllListPage::onListMenuLongTap(VcpListMenu *sender, VfxId id)
{
    if (m_listMenu->getMenuMode() != VCP_LIST_MENU_MODE_NORMAL)
    {
        return;
    }

    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);

    m_selIdx = id;

    srv_tdl_task_short_struct *buffer;
    srv_tdl_get_cache(
                (void**) &buffer, 
                sizeof(srv_tdl_task_short_struct),
                SRV_TDL_VCAL_TASK, 
                m_listMgr->getListItemStoreIndex(m_selIdx));


    VcpMenuPopup *opList;
    VFX_OBJ_CREATE(opList, VcpMenuPopup, this);
    opList->setTitle((VfxWChar *)buffer->subject);	
    opList->addItem(0, (VfxResId)STR_ID_VAPP_CAL_DELETE);
    opList->m_signalMenuCallback.connect(this, &VappTaskAllListPage::onOpListClicked);
    opList->show(VFX_TRUE);

    m_opListWeakPtr = opList;
}

void VappTaskAllListPage::onOpListClicked(VcpMenuPopup* sender, VcpMenuPopupEventEnum evtEnum, VcpMenuPopupItem* item)
{
    if (evtEnum == VCP_MENU_POPUP_EVENT_ITEM_SELECTED && item->getId() == 0)
    {
        VcpConfirmPopup *confirmPopup;
        VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
        confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        confirmPopup->setCustomButton(
                                VFX_WSTR_RES(STR_ID_VAPP_CAL_DELETE),
                                VFX_WSTR_RES(STR_ID_VAPP_CAL_CANCEL),
                                VCP_POPUP_BUTTON_TYPE_WARNING,
                                VCP_POPUP_BUTTON_TYPE_CANCEL);

        confirmPopup->setText((VfxResId)STR_ID_VAPP_CAL_DELETE_TASK);
        confirmPopup->setAutoDestory(VFX_FALSE);    
        confirmPopup->m_signalButtonClicked.connect(this, &VappTaskAllListPage::onLongPressDelConfirm);
        confirmPopup->show(VFX_TRUE);

        m_confirmPopupWeakPtr = confirmPopup;
    }
}


void VappTaskAllListPage::onLongPressDelConfirm(VfxObject* sender, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        srv_tdl_delete(m_listMgr->getListItemStoreIndex(m_selIdx), SRV_TDL_VCAL_TASK);
    }
}


void VappTaskAllListPage::onSelListMenuClicked(
                    VcpListMenu * sender, 
                    VfxU32 index,        
                    VcpListMenuItemStateEnum state)
{
    m_listMgr->setSelListItemState(index, state);

    if (m_listMgr->getSelListMarkedCount() == 0)
    {
        m_toolBar->setDisableItem(VAPP_TASK_SEL_LIST_DELETE, VFX_TRUE);
    }
    else
    {
        m_toolBar->setDisableItem(VAPP_TASK_SEL_LIST_DELETE, VFX_FALSE);
    }

    if (m_listMgr->getSelListMarkedCount() == m_listMgr->getListCount())
    {
        m_toolBar->changeItem(VAPP_TASK_SEL_LIST_MARK_ALL, VFX_WSTR_RES(STR_ID_VAPP_CAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
        m_markAllBtn = VFX_FALSE;
    }
    else if (m_listMgr->getSelListMarkedCount() == 0)
    {
        m_toolBar->changeItem(VAPP_TASK_SEL_LIST_MARK_ALL, VFX_WSTR_RES(STR_ID_VAPP_CAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
        m_markAllBtn = VFX_TRUE;
    }
    else
    {
        m_toolBar->changeItem(VAPP_TASK_SEL_LIST_MARK_ALL, VFX_WSTR_RES(STR_ID_VAPP_CAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
        m_markAllBtn = VFX_TRUE;
    }
}

void VappTaskAllListPage::onCommBtnClicked(VcpListMenu *sender, VfxU32 index)
{
    VfxU16 storeIndex;
    storeIndex = m_listMgr->getListItemStoreIndex(index);

    srv_tdl_task_struct *buffer;
    VFX_SYS_ALLOC_MEM(buffer, sizeof(srv_tdl_task_struct));
    VFX_ASSERT(buffer);

    srv_tdl_get(
        buffer, 
        sizeof(srv_tdl_task_struct), 
        SRV_TDL_VCAL_TASK, 
        storeIndex);

    if (buffer->status == SRV_TDL_STATUS_UNDONE)
    {
        buffer->status = SRV_TDL_STATUS_DONE;
    }
    else
    {
        buffer->status = SRV_TDL_STATUS_UNDONE;
    }

    srv_tdl_update(buffer, SRV_TDL_VCAL_TASK, storeIndex);

    VFX_FREE_MEM(buffer);

    m_listMenu->updateItem(index);
}

void VappTaskAllListPage::onDeleteConfirm(VfxObject* sender, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        m_toolBar->removeItem(VAPP_TASK_SEL_LIST_MARK_ALL);
        m_toolBar->removeItem(VAPP_TASK_SEL_LIST_DELETE);
        m_toolBar->removeItem(VAPP_TASK_SEL_LIST_CANCEL);
        m_toolBar->addItem(VAPP_TASK_LIST_ADD, (VfxResId)STR_ID_VAPP_CAL_ADD, VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
#ifndef __LOW_COST_SUPPORT_COMMON__
        m_toolBar->addItem(VAPP_TASK_LIST_SEARCH, (VfxResId)STR_GLOBAL_SEARCH, VCP_IMG_TOOL_BAR_COMMON_ITEM_SEARCH);
#endif
        m_toolBar->addItem(VAPP_TASK_LIST_DELETE, (VfxResId)STR_ID_VAPP_CAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);

        m_titleBar->setTitle((VfxResId)STR_ID_VAPP_CAL_TASKS);

        m_isMutiDelProcessing = VFX_TRUE;
        VfxU16 count = m_listMgr->getListCount();
        for (VfxU16 j = 0; j < count; j++)
        {
            if (m_listMgr->getSelListState(j) == VCP_LIST_MENU_ITEM_STATE_SELECTED)
            {
                srv_tdl_delete(m_listMgr->getListItemStoreIndex(j), SRV_TDL_VCAL_TASK);
            }
        }
        m_isMutiDelProcessing = VFX_FALSE;

        m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
        srv_tdl_op_evt_struct param;
        MMI_FRM_INIT_EVENT(&param, 0XFFFF);
        param.op_type = SRV_TDL_OP_DELETE;
        param.vcal_type = SRV_TDL_VCAL_TASK;
        param.store_idx = 0xFFFF;
        param.user_data = this;
        updateTaskListPage((mmi_event_struct*)&param);
    }
    else if (id == VCP_CONFIRM_POPUP_BUTTON_USER_2)
    {
        if (m_confirmPopupWeakPtr.isValid())
        {
            VcpConfirmPopup *temp = m_confirmPopupWeakPtr.get();
            if (temp->isValid())
            {
                VFX_OBJ_CLOSE(temp);
            }
        }
    }
}

void VappTaskAllListPage::updateTaskListPageInt()
{
    updateListData();


    // do not change the viewer if stay on selection page
    if (m_listMenu->getMenuMode() == VCP_LIST_MENU_MODE_MULTI_SELECTION)
    {
        m_listMgr->setSelListState(VCP_LIST_MENU_ITEM_STATE_UNSELECTED);
        m_toolBar->setDisableItem(VappTaskAllListPage::VAPP_TASK_SEL_LIST_DELETE, VFX_TRUE);
        m_toolBar->changeItem(VappTaskAllListPage::VAPP_TASK_SEL_LIST_MARK_ALL, VFX_WSTR_RES(STR_ID_VAPP_CAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
        m_markAllBtn = VFX_TRUE;
    }
    else
    {
        m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_TRUE);

        if (m_listMgr->getListCount() == VAPP_TASK_MAX_COUNT)
        {
        //page->m_toolBar->setDisableItem(VappTaskAllListPage::VAPP_TASK_LIST_ADD, VFX_TRUE);
#ifndef __LOW_COST_SUPPORT_COMMON__
            m_toolBar->setDisableItem(VappTaskAllListPage::VAPP_TASK_LIST_SEARCH, VFX_FALSE);
#endif
            m_toolBar->setDisableItem(VappTaskAllListPage::VAPP_TASK_LIST_DELETE, VFX_FALSE);
        }
        else
        {
            m_toolBar->setDisableItem(VappTaskAllListPage::VAPP_TASK_LIST_ADD, VFX_FALSE);
#ifndef __LOW_COST_SUPPORT_COMMON__
            m_toolBar->setDisableItem(VappTaskAllListPage::VAPP_TASK_LIST_SEARCH, VFX_FALSE);
#endif
            m_toolBar->setDisableItem(VappTaskAllListPage::VAPP_TASK_LIST_DELETE, VFX_FALSE);
        }
    }

    if (m_listMgr->getListCount() == 0)
    {
        m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
        m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_TRUE);
        if(getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))
        {
            VFX_OBJ_CLOSE(m_toolBar);
            VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
            m_toolBar->addItem(VAPP_TASK_LIST_ADD, (VfxResId)STR_ID_VAPP_CAL_ADD, VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
#ifndef __LOW_COST_SUPPORT_COMMON__
            m_toolBar->addItem(VAPP_TASK_LIST_SEARCH, (VfxResId)STR_GLOBAL_SEARCH, VCP_IMG_TOOL_BAR_COMMON_ITEM_SEARCH);
#endif
            m_toolBar->addItem(VAPP_TASK_LIST_DELETE, (VfxResId)STR_ID_VAPP_CAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
            m_toolBar->m_signalButtonTap.connect(this, &VappTaskAllListPage::onToolBarClicked);
            setBottomBar(m_toolBar);
            m_toolBar->setDisableItem(VappTaskAllListPage::VAPP_TASK_LIST_ADD, VFX_FALSE);
#ifndef __LOW_COST_SUPPORT_COMMON__
            m_toolBar->setDisableItem(VappTaskAllListPage::VAPP_TASK_LIST_SEARCH, VFX_TRUE);
#endif
            m_toolBar->setDisableItem(VappTaskAllListPage::VAPP_TASK_LIST_DELETE, VFX_TRUE);
        }
    }
    m_listMenu->resetAllItems(VFX_TRUE);

    if (m_opListWeakPtr.isValid())
    {
        VcpMenuPopup *temp = m_opListWeakPtr.get();
        if (temp->isValid())
        {
            VFX_OBJ_CLOSE(temp);
        }
    }
    if (m_confirmPopupWeakPtr.isValid())
    {
        VcpConfirmPopup *temp = m_confirmPopupWeakPtr.get();
        if (temp->isValid())
        {
            VFX_OBJ_CLOSE(temp);
        }
    }
}

mmi_ret VappTaskAllListPage::updateTaskListPage(mmi_event_struct *param)
{
    srv_tdl_op_evt_struct *event = (srv_tdl_op_evt_struct *)param;
    VappTaskAllListPage *page = (VappTaskAllListPage *)event->user_data;

    if (event->vcal_type != SRV_TDL_VCAL_TASK)
    {
        return MMI_RET_OK;
    }
    // for deletion, should distinguish single deletion and muti deletion;
    if (event->op_type == SRV_TDL_OP_DELETE && page->m_isMutiDelProcessing == VFX_TRUE)
    {
        return MMI_RET_OK;
    }

    page->updateTaskListPageInt();

    if (event->op_type == SRV_TDL_OP_ADD || event->op_type == SRV_TDL_OP_UPDATE)
    {
    // in order that the new added or updated could be visible on this list page, we need remember the index
        VfxU16 listIdx = page->m_listMgr->getListIdx(event->store_idx);

        if (listIdx != page->m_listMgr->getListCount())
        {
            page->m_selIdx = listIdx;
        }
    }

    page->m_dataChangedType = event->op_type;

    return MMI_RET_OK;
}


