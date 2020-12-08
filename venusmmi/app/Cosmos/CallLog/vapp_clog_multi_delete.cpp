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
 *  vapp_clog_multi_delete.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#include "vapp_clog_multi_delete.h"
#include "vapp_clog_ui.h"

#include "mmi_rp_vapp_calllog_def.h"


/***************************************************************************** 
 * Class VappClogMultiDeleteObj
 *****************************************************************************/ 
VFX_IMPLEMENT_CLASS("VappClogMultiDeleteObj", VappClogMultiDeleteObj, VfxObject);

VappClogMultiDeleteObj::VappClogMultiDeleteObj(
    VappCLogList *list,
    VfxPage *page)
    :m_page(page),
     m_list(list),
     m_tool(NULL),
     m_mark(NULL)
{
}


void VappClogMultiDeleteObj::onInit()
{
    VfxObject::onInit();

    // delete start
    m_list->onMultiDeleteStart();

    // toolbar
    VFX_OBJ_CREATE(m_tool, VcpToolBar, m_page);
    m_page->setBottomBar(m_tool);

    m_tool->addItem(CLOG_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    m_tool->addItem(CLOG_MULTI_CMD_DELETE, VFX_WSTR_RES(STR_GLOBAL_DELETE), VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);
    m_tool->addItem(CLOG_MULTI_CMD_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);

    // toolbar event handler
    m_tool->m_signalButtonTap.connect(this, &VappClogMultiDeleteObj::onToolBarClick);

    // config list
    m_list->setListMode(VAPP_CLOG_LIST_MARK);
    m_mark = m_list->getMarked();

    // config toolbar
    configToolBar();

    m_list->getListMenu()->m_signalItemSelectionStateChanged.connect(this, &VappClogMultiDeleteObj::onStateChanged);
    m_list->m_listUpdated.connect(this, &VappClogMultiDeleteObj::onListUpdated);
}


void VappClogMultiDeleteObj::onListUpdated()
{
    if (m_mark->checkMarkAll())
    {
        m_tool->changeItem(CLOG_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
    }
    else
    {
        m_tool->changeItem(CLOG_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    }

    // config toolbar
    configToolBar();    
}


void VappClogMultiDeleteObj::configToolBar()
{
    if (m_mark->getCount() > 0)
    {
        m_tool->setDisableItem(CLOG_MULTI_CMD_DELETE, VFX_FALSE);
    }
    else
    {
        m_tool->setDisableItem(CLOG_MULTI_CMD_DELETE, VFX_TRUE);
    }
}


void VappClogMultiDeleteObj::onStateChanged(
        VcpListMenu *list,
        VfxU32 index,
        VcpListMenuItemStateEnum state)
{
    if (m_mark->checkMarkAll())
    {
        m_tool->changeItem(CLOG_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
    }
    else
    {
        m_tool->changeItem(CLOG_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
    }

    // config toolbar
    configToolBar();
}


void VappClogMultiDeleteObj::onToolBarClick(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case CLOG_MULTI_CMD_SELECT:
        {
            if (m_mark->checkMarkAll())
            {
                m_list->unMarkAll();
                m_tool->changeItem(CLOG_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_MARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL);
            }
            else
            {
                m_list->markAll();
                m_tool->changeItem(CLOG_MULTI_CMD_SELECT, VFX_WSTR_RES(STR_GLOBAL_UNMARK_ALL), VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL);
            }

            // config toolbar
            configToolBar();
            break;
        }
        case CLOG_MULTI_CMD_DELETE:
        {
            VappClogDeleteSeveral *del;
            VFX_OBJ_CREATE_EX(del, VappClogDeleteSeveral, this, (m_list->getMarked(), m_page->findScreen()));

            del->m_signalDone.connect(this, &VappClogMultiDeleteObj::deleteDone);
            break;
        }
        case CLOG_MULTI_CMD_CANCEL:
        {
            closeSelf();
            break;
        }
    }
}


void VappClogMultiDeleteObj::deleteDone()
{
    closeSelf();
}


void VappClogMultiDeleteObj::closeSelf()
{
    m_list->onMultiDeleteEnd();

    VfxObject *obj = this;
    VFX_OBJ_CLOSE(obj);
}


/***************************************************************************** 
 * Class VappClogDeleteSeveral
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappClogDeleteSeveral", VappClogDeleteSeveral, VfxObject);

VappClogDeleteSeveral::VappClogDeleteSeveral(CLogMark *mark, VfxScreen *scr):
    m_mark(mark),
    m_parent(scr)
{
    // the parent must be a screen
    VFX_ASSERT(scr->isKindOf(VFX_OBJ_CLASS_INFO(VfxScreen)));
}


void VappClogDeleteSeveral::onInit()
{
    VfxObject::onInit();

	VcpConfirmPopup *cnfPopup;
    VFX_OBJ_CREATE(cnfPopup, VcpConfirmPopup, m_parent);

    VfxWString info = VFX_WSTR_RES(STR_ID_VAPP_CLOG_DELETE_SELECTED_CALL_LOGS_QUERY);
    info += VFX_WSTR_RES(STR_ID_VAPP_CLOG_LEFT_BRACKET);
    info += VfxWString().format("%d", m_mark->getCount());
    info += VFX_WSTR_RES(STR_ID_VAPP_CLOG_RIGHT_BRACKET);
    info += VFX_WSTR_RES(STR_ID_VAPP_CLOG_QUESTION_MARK);

    cnfPopup->setText(info);
    cnfPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
    cnfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    cnfPopup->setCustomButton(
        VFX_WSTR_RES(STR_GLOBAL_DELETE),
        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
        VCP_POPUP_BUTTON_TYPE_WARNING,
        VCP_POPUP_BUTTON_TYPE_CANCEL);

    cnfPopup->m_signalButtonClicked.connect(this, &VappClogDeleteSeveral::onButtonClicked);
    cnfPopup->show(VFX_TRUE);
}


void VappClogDeleteSeveral::onDeinit()
{
    // operation done
    m_signalDone.postEmit();

    VfxObject::onDeinit();
}


void VappClogDeleteSeveral::closeSlef()
{
    VfxObject* self = this;
    VFX_OBJ_CLOSE(self);
}


void VappClogDeleteSeveral::onButtonClicked(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        multiDeleteClog(&VappClogDeleteSeveral::onMultiDeleteCbk);
    }
    else
    {
        // closeSlef();
    }
}


VfxU32 VappClogDeleteSeveral::multiDeleteClog(SRV_CLOG_BASE_CB cbk)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												          */
	/*----------------------------------------------------------------*/
	VfxU32 i, j;
	
    SRV_CLOG_HANDLE hdlr;       
    VfxU32 sim_id = MMI_SIM_ALL;
    srv_clog_create_struct rc_create;
    rc_create.identity.cate = SRV_CLOG_CATE_CALL;
    rc_create.identity.sim_id = sim_id;
    rc_create.identity.log_type = SRV_CLOG_CLT_ALL;
    rc_create.identity.sub_type = SRV_CLOG_CALL_TYPE_ALL;
    rc_create.user_data = (void *)this;
    
    hdlr = srv_clog_create((const srv_clog_create_struct *)&rc_create);

    srv_clog_del_multi_logs_req_struct req_data;
	srv_clog_init_para(SRV_CLOG_PARA_DEL_MULTI_LOGS_REQ, &req_data);
	req_data.log_type = SRV_CLOG_CLT_ALL;

    for (i = 0, j = 0; i < m_mark->getClogCount() && j < SRV_CLOG_DEL_MULTI_LOG_MAX_NUM; i++)
    {
        if (m_mark->checkMark(i))
        {
            req_data.log_ids[j] = m_mark->getClogIDByIdx(i);
			j++;
			m_mark->resetMark(i);
        }
    }
    if (j < SRV_CLOG_DEL_MULTI_LOG_MAX_NUM)
    {
        req_data.log_ids[j] = SRV_CLOG_INVALID_ELM;
    }

    if (j == 0) /* don't need to delete */
        return j;
    
    srv_clog_delete_multi_logs(
        hdlr, 0, 
        (const srv_clog_del_multi_logs_req_struct *)&req_data, 
        cbk);
	
    return j; /* log count of need to delete */
}


VfxS32 VappClogDeleteSeveral::onMultiDeleteCbk(SRV_CLOG_HANDLE handle, VfxS32 pid,
                                void *req_data, void *cnf_data, MMI_BOOL more, srv_clog_ret_enum ret)
{
    VfxU32 count;
    
    VappClogDeleteSeveral *obj = (VappClogDeleteSeveral *)srv_clog_get_user_data(handle);
	
    // if use obj, need check if obj->isValid()
    if (obj->isValid() && (ret == SRV_CLOG_RET_OK))
    {
        count = obj->multiDeleteClog(&VappClogDeleteSeveral::onMultiDeleteCbk);
        if (count != 0)
            return SRV_CLOG_RET_OK;
        else
        {
            srv_clog_destroy(handle);
            obj->closeSlef();
        }
    }
    
	return SRV_CLOG_RET_OK;
}

