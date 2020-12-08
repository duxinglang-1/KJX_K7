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
 *  vapp_phb_multi.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "mmi_rp_vapp_contact_def.h"
#include "mmi_rp_vapp_fmgr_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"

#include "vapp_contact_several.h"
#include "vapp_phb_multi.h"
#include "vapp_phb_copy_delete.h"
#include "vapp_phb_app.h"
#include "vapp_phb_group.h"
#include "vapp_phb_gprot.h"

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __MMI_SNS_CONTACTS__
#include "SnsSrvGprot.h"
#endif

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Class VappPhbMarkDeleteObj
 *****************************************************************************/
VappPhbMarkDeleteObj::VappPhbMarkDeleteObj(
    VappPhbListCp *list,
    VfxPage *page,
    VappPhbMarkCmdInterface *cmd)
    :m_page(page),
     m_list(list),
     m_tool(NULL),
     m_mark(NULL),
     m_cmd(cmd)
{
}


void VappPhbMarkDeleteObj::onInit()
{
    VfxObject::onInit();

    m_cmd->onCmdStart(VAPP_PHB_MARK_CMD_DELETE);

    VFX_OBJ_CREATE(m_tool, VcpToolBar, m_page);
    m_page->setBottomBar(m_tool);

    m_tool->addItem(PB_MULTI_CMD_SELECT, (VfxResId)(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    m_tool->addItem(PB_MULTI_CMD_OP, (VfxResId)(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_tool->addItem(PB_MULTI_CMD_CANCEL, (VfxResId)(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);

    m_list->setListType(VAPP_PHB_LIST_MARK);
    m_mark = m_list->getMarked();

    configToolBar();

    m_tool->m_signalButtonTap.connect(this, &VappPhbMarkDeleteObj::onToolBarClick);
    m_list->getSearchBar()->getSearchEditor()->m_signalTextChanged.connect(this, &VappPhbMarkDeleteObj::onTextChanged);
    m_list->m_signalItemSelectionStateChanged.connect(this, &VappPhbMarkDeleteObj::onStateChanged);
    m_list->m_signalCount.connect(this, &VappPhbMarkDeleteObj::onListCountChanged);
}


void VappPhbMarkDeleteObj::onListCountChanged(VappPhbListCp* list, VfxU32 count)
{
    if (count > 0)
    {
        m_tool->setDisableItem(PB_MULTI_CMD_SELECT, VFX_FALSE);
    }
    else
    {
        m_tool->setDisableItem(PB_MULTI_CMD_SELECT, VFX_TRUE);
    }

    if (m_mark->checkMarkAll())
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, (VfxResId)(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
    }
    else
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, (VfxResId)(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    }

    configToolBar();
}


void VappPhbMarkDeleteObj::onTextChanged(VcpTextEditor *editor)
{
    if (m_mark->checkMarkAll())
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, (VfxResId)(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
    }
    else
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, (VfxResId)(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    }
}


void VappPhbMarkDeleteObj::configToolBar()
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


void VappPhbMarkDeleteObj::onStateChanged(VcpGroupListMenu *list, VcpMenuPos pos, VcpListMenuItemStateEnum state)
{
    if (m_mark->checkMarkAll())
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, (VfxResId)(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
    }
    else
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, (VfxResId)(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    }

    configToolBar();
}


void VappPhbMarkDeleteObj::onToolBarClick(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case PB_MULTI_CMD_SELECT:
        {
            if (m_mark->checkMarkAll())
            {
                m_list->unMarkAll();
                m_tool->changeItem(PB_MULTI_CMD_SELECT, (VfxResId)(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
            }
            else
            {
                m_list->markAll();
                m_tool->changeItem(PB_MULTI_CMD_SELECT, (VfxResId)(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
            }

            configToolBar();
            break;
        }
        case PB_MULTI_CMD_OP:
        {
            VappPhbDeleteSeveral *del;
            VFX_OBJ_CREATE_EX(del, VappPhbDeleteSeveral, this, (m_list->getMarked(), m_page->findScreen()));

            del->m_signalDone.connect(this, &VappPhbMarkDeleteObj::deleteDone);
            // stop refresh list
            m_list->setRefreshFlag(VFX_TRUE);
            break;
        }
        case PB_MULTI_CMD_CANCEL:
        {
            closeSelf();
            break;
        }
    }
}


void VappPhbMarkDeleteObj::deleteDone()
{
    closeSelf();
}


void VappPhbMarkDeleteObj::closeSelf()
{
    m_cmd->onCmdEnd(VAPP_PHB_MARK_CMD_DELETE);

    // start refresh list
    m_list->setRefreshFlag(VFX_FALSE);

#ifdef __MMI_SNS_CONTACTS__
    srv_sns_phb_stop_multi_op();
#endif

    VFX_OBJ_CLOSE(m_tool);

    VfxObject *obj = this;
    VFX_OBJ_CLOSE(obj);
}

void VappPhbMarkDeleteObj::onDeinit()
{
    if(m_tool && m_tool->isValid())
    {
        VFX_OBJ_CLOSE(m_tool);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/***************************************************************************** 
 * Class VappPhbMultiCopyObj
 *****************************************************************************/
VappPhbMultiCopyObj::VappPhbMultiCopyObj(
phb_storage_enum desStorage, 
phb_storage_enum srcStorage,
VfxBool isImport, 
VfxMainScr 
*screen ):m_desStorage(desStorage),
     m_srcStorage(srcStorage),
     m_isImport(isImport),
     m_parent(screen),
     m_page(NULL),
     m_list(NULL),
     m_tool(NULL)
{
}

void VappPhbMultiCopyObj::onInit()
{
    VfxObject::onInit();

    VFX_OBJ_CREATE(m_page, VfxPage, m_parent);
    m_parent->pushPage(VFX_ID_NULL, m_page);

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, m_page);
    if (m_isImport)
    {
        bar->setTitle(STR_ID_VAPP_PHB_SETTING_IMPORT);
    }
    else
    {
        bar->setTitle(STR_ID_VAPP_PHB_SETTING_EXPORT);
    }
    m_page->setTopBar(bar);

    VFX_OBJ_CREATE(m_tool, VcpToolBar, m_page);
    m_page->setBottomBar(m_tool);

    m_tool->addItem(PB_MULTI_CMD_SELECT, (VfxResId)(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    if (m_isImport)
    {
        m_tool->addItem(PB_MULTI_CMD_OP, (VfxResId)(STR_GLOBAL_IMPORT), VCP_IMG_TOOL_BAR_COMMON_ITEM_IMPORT);
    }
    else
    {
        m_tool->addItem(PB_MULTI_CMD_OP, (VfxResId)(STR_GLOBAL_EXPORT), VCP_IMG_TOOL_BAR_COMMON_ITEM_EXPORT);
    }
    
    m_tool->addItem(PB_MULTI_CMD_CANCEL, (VfxResId)(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);

    VFX_OBJ_CREATE(m_list, VappPhbListCp, m_page);
    m_list->setStorage(m_srcStorage);
    m_list->setSize(m_page->getSize());
    m_list->setAlignParent(
    VFX_FRAME_ALIGNER_MODE_SIDE,
    VFX_FRAME_ALIGNER_MODE_SIDE,
    VFX_FRAME_ALIGNER_MODE_SIDE,
    VFX_FRAME_ALIGNER_MODE_SIDE);
    m_list->setListType(VAPP_PHB_LIST_MARK);
    m_mark = m_list->getMarked();

    configToolBar();

    m_tool->m_signalButtonTap.connect(this, &VappPhbMultiCopyObj::onToolBarClick);
    m_list->getSearchBar()->getSearchEditor()->m_signalTextChanged.connect(this, &VappPhbMultiCopyObj::onTextChanged);
    m_list->m_signalItemSelectionStateChanged.connect(this, &VappPhbMultiCopyObj::onStateChanged);
    m_list->m_signalCount.connect(this, &VappPhbMultiCopyObj::onListCountChanged);

}


void VappPhbMultiCopyObj::onListCountChanged(VappPhbListCp* list, VfxU32 count)
{
    if (count > 0)
    {
        m_tool->setDisableItem(PB_MULTI_CMD_SELECT, VFX_FALSE);
    }
    else
    {
        m_tool->setDisableItem(PB_MULTI_CMD_SELECT, VFX_TRUE);
    }

    if (m_mark->checkMarkAll())
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, (VfxResId)(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
    }
    else
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(
STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    }

    configToolBar();
}



void VappPhbMultiCopyObj::onTextChanged(VcpTextEditor *editor)
{
    if (m_mark->checkMarkAll())
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, (VfxResId)(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
    }
    else
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, (VfxResId)(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    }
}

 void VappPhbMultiCopyObj::configToolBar()
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

void VappPhbMultiCopyObj::onStateChanged(VcpGroupListMenu *list, VcpMenuPos pos, VcpListMenuItemStateEnum state)
{
    if (m_mark->checkMarkAll())
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, (VfxResId)(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
    }
    else
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, (VfxResId)(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    }

    configToolBar();
}


void VappPhbMultiCopyObj::onToolBarClick(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case PB_MULTI_CMD_SELECT:
        {
            if (m_mark->checkMarkAll())
            {
                m_list->unMarkAll();
                m_tool->changeItem(PB_MULTI_CMD_SELECT, (VfxResId)(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
            }
            else
            {
                m_list->markAll();
                m_tool->changeItem(PB_MULTI_CMD_SELECT, (VfxResId)(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
            }

            configToolBar();
            break;
        }
        case PB_MULTI_CMD_OP:
        {
            VappPhbCopySeveral *copy;
            VFX_OBJ_CREATE_EX(copy, VappPhbCopySeveral, this, (m_desStorage, m_list->getMarked(), m_page->findScreen()));

            copy->m_signalDone.connect(this, &VappPhbMultiCopyObj::copyDone);
            // stop refresh list
            m_list->setRefreshFlag(VFX_TRUE);
            break;
        }
        case PB_MULTI_CMD_CANCEL:
        {
            copyDone();
            break;
        }
    }

}
void VappPhbMultiCopyObj::copyDone()
{
    closeSelf();

    m_parent->popPage();
}


void VappPhbMultiCopyObj::closeSelf()
{
    VfxObject *obj = this;
    VFX_OBJ_CLOSE(obj);
}



/***************************************************************************** 
 * Class VappPhbMarkMsgObj
 *****************************************************************************/
#ifdef __MMI_PHB_MARK_MESSAGE__
VappPhbMarkMsgObj::VappPhbMarkMsgObj(
    VappPhbListCp* list,
    VfxPage *page,
    VappPhbMarkCmdInterface *cmd)
    :m_page(page),
     m_list(list),
     m_tool(NULL),
     m_mark(NULL),
     m_cmd(cmd)
{
}


void VappPhbMarkMsgObj::onInit()
{
    VfxObject::onInit();

    m_cmd->onCmdStart(VAPP_PHB_MARK_CMD_MESSAGE);

    VFX_OBJ_CREATE(m_tool, VcpToolBar, m_page);
    m_page->setBottomBar(m_tool);

    m_tool->addItem(PB_MULTI_CMD_OP, (VfxResId)(VAPP_PHB_STR_MESSAGE), VAPP_PHB_IMG_CMD_MESSAGE);
    m_tool->addItem(PB_MULTI_CMD_CANCEL, (VfxResId)(STR_GLOBAL_CANCEL),VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);

    m_list->setListType(VAPP_PHB_LIST_MARK);
    m_list->setAlignField(MMI_PHB_CONTACT_FIELD_NUMBER);
    m_mark = m_list->getMarked();

    configToolBar();

    m_tool->m_signalButtonTap.connect(this, &VappPhbMarkMsgObj::onToolBarClick);
    m_list->m_signalItemSelectionStateChanged.connect(this, &VappPhbMarkMsgObj::onStateChanged);
    m_list->m_signalCount.connect(this, &VappPhbMarkMsgObj::onListCountChanged);
}


ContactMark* VappPhbMarkMsgObj::getMarkSet()
{
    return m_mark;
}


void VappPhbMarkMsgObj::onListCountChanged(VappPhbListCp* list, VfxU32 count)
{
    configToolBar();
}


void VappPhbMarkMsgObj::configToolBar()
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


void VappPhbMarkMsgObj::onStateChanged(VcpGroupListMenu *list, VcpMenuPos pos, VcpListMenuItemStateEnum state)
{
    configToolBar();
}


void VappPhbMarkMsgObj::onToolBarClick(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case PB_MULTI_CMD_OP:
        {
            sendMsg();
            break;
        }
        case PB_MULTI_CMD_CANCEL:
        {
            closeSelf();
            break;
        }
    }
}


void VappPhbMarkMsgObj::sendMsg()
{
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
    VappUcEntryStruct *ucEntry;
    VfxU32 i, total = (m_mark->getCount() > 100 ) ? 100 : m_mark->getCount();
    srv_uc_addr_struct *lastAddr, *tempAddr;
    srv_uc_addr_struct *ucAddrArray;

    ucEntry = (VappUcEntryStruct*) mmi_frm_temp_alloc(sizeof(VappUcEntryStruct));

    // set uc type
    memset(ucEntry, 0, sizeof(VappUcEntryStruct));
    ucEntry->msg_type = SRV_UC_MSG_TYPE_DEFAULT;
    ucEntry->type = SRV_UC_STATE_WRITE_NEW_MSG;

    // set address
    ucEntry->addr_num = total;
    ucEntry->get_address_callback = NULL;
    VFX_ALLOC_MEM(ucAddrArray, total * sizeof(srv_uc_addr_struct), this);

    for (lastAddr = NULL, i = 0; i < total; ++i)
    {
        tempAddr = &ucAddrArray[i];
        MarkKey key = m_mark->getMarkKey(i);
        ContactEntry entry(key.m_id);

        VFX_ALLOC_MEM(tempAddr->addr, sizeof(VfxWChar) * (MMI_PHB_NUMBER_LENGTH + 1 + 1), this);
        mmi_wcscpy((WCHAR*) tempAddr->addr, (WCHAR*) entry.getNumberById(key.m_subId).getBuf());
        tempAddr->next = NULL;
        tempAddr->previous = NULL;
        tempAddr->type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
        tempAddr->group = SRV_UC_ADDRESS_GROUP_TYPE_TO;

        if (lastAddr)
        {
            lastAddr->next = tempAddr;
            tempAddr->previous = lastAddr;
            lastAddr = tempAddr;
        }
        else
        {
            ucEntry->addr = tempAddr;
            lastAddr = tempAddr;
        }
        
    }

    vappUcAppLauncher(ucEntry);

    for (i = 0; i < total; ++i)
    {
        VFX_SYS_FREE_MEM(ucAddrArray[i].addr);
    }

    VFX_SYS_FREE_MEM(ucAddrArray);
    mmi_frm_temp_free(ucEntry);

    closeSelf();
#endif
}


void VappPhbMarkMsgObj::closeSelf()
{
    m_cmd->onCmdEnd(VAPP_PHB_MARK_CMD_MESSAGE);

    VFX_OBJ_CLOSE(m_tool);

    VfxObject *obj = this;
    VFX_OBJ_CLOSE(obj);
}


void VappPhbMarkMsgObj::onDeinit()
{
    if(m_tool && m_tool->isValid())
    {
        VFX_OBJ_CLOSE(m_tool);
    }
}
#endif /* __MMI_PHB_MARK_MESSAGE__ */ 


/***************************************************************************** 
 * Class VappPhbMarkShareObj
 *****************************************************************************/
#if defined (__MMI_OPP_SUPPORT__) && defined (__MMI_VCARD__)
VappPhbMarkShareObj::VappPhbMarkShareObj(VappPhbListCp* list, VfxPage *page, VappPhbMarkCmdInterface *cmd):
    m_page(page),
    m_list(list),
    m_tool(NULL),
    m_mark(NULL),
    m_cmd(cmd)
{
}


void VappPhbMarkShareObj::onInit()
{
    VfxObject::onInit();

    m_cmd->onCmdStart(VAPP_PHB_MARK_CMD_SHARE);

    VFX_OBJ_CREATE(m_tool, VcpToolBar, m_page);
    m_page->setBottomBar(m_tool);

    m_tool->addItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    m_tool->addItem(PB_MULTI_CMD_OP, VFX_WSTR_RES(VAPP_PHB_STR_SHARE), IMG_ID_VAPP_FMGR_SHARE_BY_BT);
    m_tool->addItem(PB_MULTI_CMD_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL),VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);

    m_list->setListType(VAPP_PHB_LIST_MARK);
    m_mark = m_list->getMarked();

    configToolBar();

    m_tool->m_signalButtonTap.connect(this, &VappPhbMarkShareObj::onToolBarClick);
    m_list->m_signalItemSelectionStateChanged.connect(this, &VappPhbMarkShareObj::onStateChanged);
    m_list->m_signalCount.connect(this, &VappPhbMarkShareObj::onListCountChanged);
}


void VappPhbMarkShareObj::onListCountChanged(VappPhbListCp* list, VfxU32 count)
{
    if (count > 0)
    {
        m_tool->setDisableItem(PB_MULTI_CMD_SELECT, VFX_FALSE);
    }
    else
    {
        m_tool->setDisableItem(PB_MULTI_CMD_SELECT, VFX_TRUE);
    }

    if (m_mark->checkMarkAll())
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
    }
    else
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    }

    configToolBar();
}


void VappPhbMarkShareObj::configToolBar()
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


void VappPhbMarkShareObj::onStateChanged(VcpGroupListMenu *list, VcpMenuPos pos, VcpListMenuItemStateEnum state)
{
    if (m_mark->checkMarkAll())
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
    }
    else
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    }

    configToolBar();
}


void VappPhbMarkShareObj::onToolBarClick(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case PB_MULTI_CMD_SELECT:
        {
            if (m_mark->checkMarkAll())
            {
                m_list->unMarkAll();
                m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
            }
            else
            {
                m_list->markAll();
                m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
            }

            configToolBar();
            break;
        }
        case PB_MULTI_CMD_OP:
        {
            shareContact();
            break;
        }
        case PB_MULTI_CMD_CANCEL:
        {
            closeSelf();
            break;
        }
    }
}


void VappPhbMarkShareObj::shareContact()
{
    VappContactvCard *m_vcard;
    VfxWChar *path(NULL);
    VfxS32 result;
    
    VFX_OBJ_CREATE_EX(m_vcard, VappContactvCard, this, (m_mark->getMarkKey(0).m_id));
    
    path = m_vcard->getFile(&result);
    
    if (NULL == path)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
            (WCHAR*)VFX_WSTR_RES(STR_GLOBAL_NOT_ENOUGH_MEMORY).getBuf());
        
        VFX_OBJ_CLOSE(m_vcard);
        
        return;
    }

    FS_Delete((WCHAR *)path);
    VFX_OBJ_CLOSE(m_vcard);

    VappPhbSharevCardBase *base = new VappPhbSharevCardBase();

    base->start(m_page->getApp()->getGroupId(), m_mark);
    closeSelf();
}


void VappPhbMarkShareObj::closeSelf()
{
    m_cmd->onCmdEnd(VAPP_PHB_MARK_CMD_SHARE);

    VFX_OBJ_CLOSE(m_tool);

    VfxObject *obj = this;
    VFX_OBJ_CLOSE(obj);
}

void VappPhbMarkShareObj::onDeinit()
{
    if(m_tool && m_tool->isValid())
    {
        VFX_OBJ_CLOSE(m_tool);
    }
}
#endif /* __MMI_PHB_MARK_MESSAGE__ */

/***************************************************************************** 
 * Class VappPhbMarkDeleteGroupMemberObj
 *****************************************************************************/
#ifdef __MMI_PHB_CALLER_GROUP__
VappPhbMarkDeleteGroupMemberObj::VappPhbMarkDeleteGroupMemberObj(
    VappPhbListCp* list,
    VfxPage *page,
    VappPhbMarkCmdInterface *cmd,
    ContactGroupManager *groupManager,
    VfxU8 groupId)
    :m_page(page),
     m_list(list),
     m_tool(NULL),
     m_mark(NULL),
     m_cmd(cmd),
     m_groupManager(groupManager),
     m_groupId(groupId)
{
    m_progress = NULL;
}


void VappPhbMarkDeleteGroupMemberObj::onInit()
{
    VfxObject::onInit();

    m_cmd->onCmdStart(VAPP_PHB_MARK_CMD_DELETE_GROUP_MEMBER);

    VFX_OBJ_CREATE(m_tool, VcpToolBar, m_page);
    m_page->setBottomBar(m_tool);

    m_tool->addItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    m_tool->addItem(PB_MULTI_CMD_OP, VFX_WSTR_RES(STR_GLOBAL_REMOVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_REMOVE);
    m_tool->addItem(PB_MULTI_CMD_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);

    m_list->setListType(VAPP_PHB_LIST_MARK);
    m_mark = m_list->getMarked();

    configToolBar();

    m_tool->m_signalButtonTap.connect(this, &VappPhbMarkDeleteGroupMemberObj::onToolBarClick);
    m_list->m_signalItemSelectionStateChanged.connect(this, &VappPhbMarkDeleteGroupMemberObj::onStateChanged);
    m_list->m_signalCount.connect(this, &VappPhbMarkDeleteGroupMemberObj::onListCountChanged);
    m_groupManager->m_signalGroupMember.connect(this, &VappPhbMarkDeleteGroupMemberObj::onGroupMemberDeleted);
}


void VappPhbMarkDeleteGroupMemberObj::onListCountChanged(VappPhbListCp* list, VfxU32 count)
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


void VappPhbMarkDeleteGroupMemberObj::configToolBar()
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


void VappPhbMarkDeleteGroupMemberObj::onStateChanged(VcpGroupListMenu *list, VcpMenuPos pos, VcpListMenuItemStateEnum state)
{
    if (m_mark->checkMarkAll())
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
    }
    else
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    }

    configToolBar();
}


void VappPhbMarkDeleteGroupMemberObj::onToolBarClick(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case PB_MULTI_CMD_SELECT:
        {
            if (m_mark->checkMarkAll())
            {
                m_list->unMarkAll();
                m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
            }
            else
            {
                m_list->markAll();
                m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
            }

            configToolBar();
            break;
        }
        case PB_MULTI_CMD_OP:
        {
            if (m_mark->getCount() > 0)
            {
                mmi_phb_contact_id *idArray = (mmi_phb_contact_id*) mmi_frm_temp_alloc(m_mark->getCount() * sizeof(mmi_phb_contact_id));

                for (VfxU32 i = 0; i < m_mark->getCount(); i++)
                {
                    MarkKey key = m_mark->getMarkKey(i);
                    idArray[i] = key.m_id;
                }

                m_tool->setDisableItem(PB_MULTI_CMD_SELECT, VFX_TRUE);
                m_tool->setDisableItem(PB_MULTI_CMD_OP, VFX_TRUE);
                m_tool->setDisableItem(PB_MULTI_CMD_CANCEL, VFX_TRUE);

                m_groupManager->removeGroupMembers(idArray, m_mark->getCount(), m_groupId);
                // show progress bar
                VFX_OBJ_CREATE(m_progress, VcpIndicatorPopup, m_page);
                m_progress->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
                m_progress->setText(VFX_WSTR_RES(STR_ID_VAPP_PHB_PROCESSING));

                m_progress->show(VFX_TRUE);

                m_list->setRefreshFlag(VFX_TRUE);

                mmi_frm_temp_free(idArray);
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


void VappPhbMarkDeleteGroupMemberObj::onGroupMemberDeleted(ContactGroupManager* manager)
{
    if (m_progress)
    {
        m_progress->exit(VFX_TRUE);
        m_progress = NULL;
    }

    m_list->setRefreshFlag(VFX_FALSE);

    closeSelf();
}


void VappPhbMarkDeleteGroupMemberObj::closeSelf()
{
    m_cmd->onCmdEnd(VAPP_PHB_MARK_CMD_DELETE_GROUP_MEMBER);

    VFX_OBJ_CLOSE(m_tool);

    VfxObject *obj = this;
    VFX_OBJ_CLOSE(obj);
}
#endif /* __MMI_PHB_CALLER_GROUP__ */


#if defined(__OP02__)
/***************************************************************************** 
 * Class VappPhbMarkMoveGroupMemberObj
 *****************************************************************************/
VappPhbMarkMoveGroupMemberObj::VappPhbMarkMoveGroupMemberObj(
    VappPhbListCp* list,
    VfxPage *page,
    VappPhbMarkCmdInterface *cmd,
    ContactGroupManager *groupManager,
    VfxU8 groupId)
    :m_page(page),
     m_list(list),
     m_tool(NULL),
     m_mark(NULL),
     m_cmd(cmd),
     m_groupManager(groupManager),
     m_groupId(groupId)
{
}


void VappPhbMarkMoveGroupMemberObj::onInit()
{
    VfxObject::onInit();

    m_cmd->onCmdStart(VAPP_PHB_MARK_CMD_MOVE_GROUP_MEMBER);

    VFX_OBJ_CREATE(m_tool, VcpToolBar, m_page);
    m_page->setBottomBar(m_tool);

    m_tool->addItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    m_tool->addItem(PB_MULTI_CMD_OP, VFX_WSTR_RES(STR_GLOBAL_MOVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_MOVE);
    m_tool->addItem(PB_MULTI_CMD_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);

    m_list->setListType(VAPP_PHB_LIST_MARK);
    m_mark = m_list->getMarked();

    configToolBar();

    m_tool->m_signalButtonTap.connect(this, &VappPhbMarkMoveGroupMemberObj::onToolBarClick);
    m_list->m_signalItemSelectionStateChanged.connect(this, &VappPhbMarkMoveGroupMemberObj::onStateChanged);
    m_list->m_signalCount.connect(this, &VappPhbMarkMoveGroupMemberObj::onListCountChanged);
    m_groupManager->m_signalGroupMember.connect(this, &VappPhbMarkMoveGroupMemberObj::onGroupMemberMoved);
}


void VappPhbMarkMoveGroupMemberObj::onListCountChanged(VappPhbListCp* list, VfxU32 count)
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();
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
#endif
}


void VappPhbMarkMoveGroupMemberObj::configToolBar()
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


void VappPhbMarkMoveGroupMemberObj::onStateChanged(VcpGroupListMenu *list, VcpMenuPos pos, VcpListMenuItemStateEnum state)
{
    if (m_mark->checkMarkAll())
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
    }
    else
    {
        m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    }

    configToolBar();
}


void VappPhbMarkMoveGroupMemberObj::onToolBarClick(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case PB_MULTI_CMD_SELECT:
        {
            if (m_mark->checkMarkAll())
            {
                m_list->unMarkAll();
                m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
            }
            else
            {
                m_list->markAll();
                m_tool->changeItem(PB_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
            }

            configToolBar();
            break;
        }
        case PB_MULTI_CMD_OP:
        {
            if (m_mark->getCount() > 0)
            {
                m_groupCount = m_mark->getCount();
                for (VfxU32 i = 0; i < m_groupCount; i++)
                {
                    MarkKey key = m_mark->getMarkKey(i);
                    m_groupIdArray[i] = key.m_id;
                }

                VappPhbGroupSelectorPage *page;
                VFX_OBJ_CREATE_EX(page, VappPhbGroupSelectorPage, m_page->getMainScr(), (m_groupManager->getStorageById(m_groupId), m_groupId, VFX_TRUE));

                page->m_signalGroupSelected.connect(this, &VappPhbMarkMoveGroupMemberObj::onGroupSelected);

                m_page->getMainScr()->pushPage(VFX_ID_NULL, page);
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


void VappPhbMarkMoveGroupMemberObj::onGroupSelected(VfxObject* obj, VfxU8 groupId)
{
    if (m_groupId != groupId)
    {
        m_tool->setDisableItem(PB_MULTI_CMD_SELECT, VFX_TRUE);
        m_tool->setDisableItem(PB_MULTI_CMD_OP, VFX_TRUE);
        m_tool->setDisableItem(PB_MULTI_CMD_CANCEL, VFX_TRUE);

        m_groupManager->moveGroupMembers(m_groupIdArray, m_groupCount, m_groupId, groupId);
    }
    else
    {
        closeSelf();
    }
}


void VappPhbMarkMoveGroupMemberObj::onGroupMemberMoved(ContactGroupManager* manager)
{
    closeSelf();
}


void VappPhbMarkMoveGroupMemberObj::closeSelf()
{
    m_cmd->onCmdEnd(VAPP_PHB_MARK_CMD_MOVE_GROUP_MEMBER);

    VFX_OBJ_CLOSE(m_tool);

    VfxObject *obj = this;
    VFX_OBJ_CLOSE(obj);
}
#endif /* defined(__OP02__) */

