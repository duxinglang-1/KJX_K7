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
 *  vapp_callset_cug.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Closed User Group
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 

extern "C" 
{
#include "GlobalResDef.h"
#include "CallSetSrvGprot.h"
#include "NotificationGprot.h"
}

#include "Mmi_rp_vapp_callset_def.h"
#include "Mmi_rp_srv_venus_component_tool_bar_def.h"

#include "App_str.h" /* app_ucs2_itoa */

#include "vfx_signal.h"
#include "vfx_text_frame.h"

#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"
#include "vcp_form.h"
#include "vcp_function_bar.h"

#include "vapp_callset_cug.h"

#pragma arm section code = "DYNAMIC_CODE_CALLSET_ROCODE", rodata = "DYNAMIC_CODE_CALLSET_RODATA" 
/***************************************************************************** 
 * Class VappCallSetPageCug
 *****************************************************************************/

void VappCallSetPageCug::onInit()
{
    VappCallSetAsyncPage::onInit(); // call base class

    VcpTitleBar *titlebar;
    VFX_OBJ_CREATE(titlebar, VcpTitleBar, this);
    titlebar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_CUG));
    setTopBar(titlebar);

    m_list = NULL;

    updateList();

    VcpToolBar *toolbar;
    VFX_OBJ_CREATE(toolbar, VcpToolBar, this);
    toolbar->addItem(1, VFX_WSTR_RES(STR_GLOBAL_EDIT), VCP_IMG_TOOL_BAR_COMMON_ITEM_EDIT);
    toolbar->m_signalButtonTap.connect(this, &VappCallSetPageCug::onToolBarTapped);
    setBottomBar(toolbar);
}

void VappCallSetPageCug::onEnter(VfxBool isBackward)
{
    VappCallSetAsyncPage::onEnter(isBackward);

    if (isBackward)
    {
        updateList();
    }
}

void VappCallSetPageCug::onExit(VfxBool isBackward)
{
    if (getCurrState() == STATE_ACT)
    {
        setCurrState(STATE_ABORT);
        onResult(NULL);
    }

    VappCallSetAsyncPage::onExit(isBackward);

}

void VappCallSetPageCug::updateList(void)
{
    srv_callset_cug_get_item_struct item;
    m_count = 0;
    m_activateIndex = 0xff;
    for (VfxU32 i = 0; i < (VfxU32)SRV_CALLSET_CUG_MAX_GROUP_NUM; i++)
    {
        if (srv_callset_cug_get_item(callset_p->m_sim, i, &item) == SRV_CALLSET_RESULT_OK)
        {
            if (item.status == SRV_CALLSET_CUG_ACTIVATED)
            {
                m_activateIndex = m_count;
            }
            if (mmi_ucs2strlen((CHAR *)item.name))
            {
                m_count++;
            }
        }
    }

    if (m_list)
    {
        VFX_OBJ_CLOSE(m_list);
    }

    VFX_OBJ_CREATE(m_list, VcpListMenu, this);
    m_list->setSize(getSize());
    m_list->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
	
    m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_list->setContentProvider(this);

    if (m_activateIndex != 0xff)
    {
        m_list->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);
		m_list->setVisibleMenuItem(m_activateIndex);
    }
	
    m_list->m_signalItemTapped.connect(this, &VappCallSetPageCug::onTapped);
}

VfxBool VappCallSetPageCug::getItemText(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,                
    VcpListMenuTextColorEnum &color  
    )
{
    if (m_count)
    {
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    }
    else if (!index) /* empty list (!m_count && index == 0) */
    {
        color = VCP_LIST_MENU_TEXT_COLOR_DISABLED;
        text = VFX_WSTR_RES(STR_GLOBAL_EMPTY);
        return VFX_TRUE;
    }
    else /* abnormal */
    {
        return VFX_FALSE;
    }

    srv_callset_cug_get_item_struct item;
    VfxU32 order = 0;
    for (VfxU32 i = 0; i < (VfxU32)SRV_CALLSET_CUG_MAX_GROUP_NUM; i++)
    {
        if (srv_callset_cug_get_item(callset_p->m_sim, i, &item) == SRV_CALLSET_RESULT_OK)
        {
            if (mmi_ucs2strlen((CHAR *)item.name))
            {
                if (order == index)
                {
					text.format("[%d] ", i);
                    text += VFX_WSTR_MEM(item.name);
                    return VFX_TRUE;
                }
                order++;
            }
        }
    }

    return VFX_FALSE;
}

VfxU32 VappCallSetPageCug::getCount() const
{
    return m_count ? m_count : 1;
}

VcpListMenuItemStateEnum VappCallSetPageCug::getItemState(VfxU32 index) const
{
    return (index == m_activateIndex) ?
                VCP_LIST_MENU_ITEM_STATE_SELECTED : VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

VfxBool VappCallSetPageCug::getItemIsHighlightable(VfxU32 index) const
{
    return m_count ? VFX_TRUE : VFX_FALSE;
}

void VappCallSetPageCug::onTapped(
    VcpListMenu* menu,
    VfxU32 index)
{
    if (!m_count)
    {
        return;
    }

    srv_callset_cug_activate_struct act_info;
    act_info.sim = callset_p->m_sim;
    VfxWString tmpStr;
    if (!(m_list->getItemTextIfPresent(index, VCP_LIST_MENU_FIELD_TEXT, tmpStr)))
    {
        /* abnormal */
        return;
    }
    VfxWChar tmpNumStr[2];
    memset(tmpNumStr, 0, sizeof(tmpNumStr));
    tmpNumStr[0] = *(tmpStr.getBuf() + 1);
    act_info.cug_id = (U8)app_ucs2_atoi((kal_int8*)tmpNumStr);

    srv_callset_result_enum result;
    if (act_info.cug_id == srv_callset_cug_get_actviated_id(callset_p->m_sim))
    {
        srv_callset_cug_deactivate_struct deact_info;
        deact_info.sim = callset_p->m_sim;
        deact_info.cug_id = act_info.cug_id;
        result = srv_callset_cug_deactivate(&deact_info, vapp_callset_hdlr_rsp, NULL);
    }
    else
    {
        result = srv_callset_cug_activate(&act_info, vapp_callset_hdlr_rsp, NULL);
    }

    setCurrState(STATE_ACT);
    showWaitPopup(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT), VFX_FALSE);
    if (result != SRV_CALLSET_RESULT_OK)
    {
        srv_callset_rsp_evt_struct evt;
        evt.evt_id = EVT_ID_SRV_CALLSET_ACT_RESPONSE;
        srv_callset_result_struct res;
        res.sim = callset_p->m_sim;
        res.result = result;
        evt.data = &res;
        onResult((mmi_event_struct*)&evt);
    }

    m_activateIndex = index;
}

void VappCallSetPageCug::onToolBarTapped(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case 1:
            VappCallSetPageCugEdit *pageCugEdit;
            VFX_OBJ_CREATE(pageCugEdit, VappCallSetPageCugEdit, getMainScr());
            getMainScr()->pushPage(VFX_ID_NULL, pageCugEdit);
            break;
    }
}

void VappCallSetPageCug::onResult(mmi_event_struct *info)
{
    if (getCurrState() == STATE_NONE ||
            getCurrState() >= STATE_INVALID)
    {
        /* abort rsp from the previous page or abnormal */
        return;
    }

    if (info->evt_id != EVT_ID_SRV_CALLSET_ACT_RESPONSE)
    {
        /* may receive rsp for the previous page, ex. pageAdditional */
        return;
    }

    if (getCurrState() != STATE_ABORT)
    {
        srv_callset_rsp_evt_struct * evt = (srv_callset_rsp_evt_struct*)info;
        srv_callset_result_struct *res = (srv_callset_result_struct*)(evt->data);

        if (res->result != SRV_CALLSET_RESULT_OK)
        {
            VAPP_CALLSET_FAIL_POPUP(this, VFX_WSTR_RES(srv_callset_get_result_string_id(res->result)));
        }

        setCurrState(STATE_NONE);
        leaveWaitPopup();

        if (res->result == SRV_CALLSET_RESULT_OK)
        {
            getMainScr()->popPage();
        }
    }
    else
    {
        setCurrState(STATE_NONE);
    }

}



void VappCallSetPageCugEdit::onInit()
{
    VfxPage::onInit(); // call base class

    VcpTitleBar *titlebar;
    VFX_OBJ_CREATE(titlebar, VcpTitleBar, this);
    titlebar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_CUG_EDIT));
    setTopBar(titlebar);

    m_count = 10;
    m_list = NULL;

    updateList();
}

void VappCallSetPageCugEdit::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    if (isBackward)
    {
        updateList();
    }
}

void VappCallSetPageCugEdit::updateList(void)
{
    if (m_list)
    {
        VFX_OBJ_CLOSE(m_list);
    }

    VFX_OBJ_CREATE(m_list, VcpListMenu, this);
    m_list->setSize(getSize());
    m_list->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
    m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_list->setContentProvider(this);
    m_list->m_signalItemTapped.connect(this, &VappCallSetPageCugEdit::onTapped);

}

VfxBool VappCallSetPageCugEdit::getItemText(
    VfxU32 index,                    
    VcpListMenuFieldEnum fieldType,  
    VfxWString &text,                
    VcpListMenuTextColorEnum &color  
    )
{
    srv_callset_cug_get_item_struct item;
    if (srv_callset_cug_get_item(callset_p->m_sim, index, &item) == SRV_CALLSET_RESULT_OK)
    {
		text.format("[%d] ", index);
        if (mmi_ucs2strlen((CHAR *)item.name))
        {
            color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
            text += VFX_WSTR_MEM(item.name);
        }
        else
        {
            color = VCP_LIST_MENU_TEXT_COLOR_DISABLED;
            text += VFX_WSTR_RES(STR_GLOBAL_EMPTY_LIST);
        }
        return VFX_TRUE;
    }

    return VFX_FALSE;
}

VfxU32 VappCallSetPageCugEdit::getCount() const
{
    return m_count;
}


void VappCallSetPageCugEdit::onTapped(
    VcpListMenu* menu,
    VfxU32 index)
{
    if (index > 9)
    {
        return;
    }

    srv_callset_cug_get_item_struct item;
    if (srv_callset_cug_get_item(callset_p->m_sim, index, &item) == SRV_CALLSET_RESULT_OK)
    {
        VfxWString tmpStr = VFX_WSTR_MEM(item.name);
        callset_p->m_inCugName = tmpStr; /* shall not assign mem addr of item.name to callset_p->m_inCugName directly */
    }
    else
    {
        callset_p->m_inCugName = VFX_WSTR_EMPTY;
    }

    callset_p->m_inCugId = index;
    VappCallSetPageCugNameEdit *pageCugNameEdit;
    VFX_OBJ_CREATE(pageCugNameEdit, VappCallSetPageCugNameEdit, getMainScr());
    getMainScr()->pushPage(VFX_ID_NULL, pageCugNameEdit);
}


void VappCallSetPageCugNameEdit::onInit()
{
    VappCallSetPageCommonInputAsync::onInit(); // call base class

    if (callset_p->m_inCugName.isEmpty())
    {
        m_titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_CUG_INPUT_NAME));
    }
    else
    {
        m_titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_CUG_EDIT_NAME));
    }

    VfxWString tmpStr;
	tmpStr.format("[%d] ", callset_p->m_inCugId);
    tmpStr += VFX_WSTR_RES(STR_ID_VAPP_CALLSET_CUG_NAME);
    m_mainText->setString(tmpStr);

    m_textInput->setIME(IMM_INPUT_TYPE_SENTENCE);
    setInputBuf(SRV_CALLSET_CUG_MAX_NAME_LENGTH, callset_p->m_inCugName);
	
    m_hint->setString(VFX_WSTR_RES(STR_ID_VAPP_CALLSET_CUG_EDIT_HINT)); 
}

void VappCallSetPageCugNameEdit::onExit(VfxBool isBackward)
{
    if (getCurrState() == STATE_ACT)
    {
        setCurrState(STATE_ABORT);
        onResult(NULL);
    }

    VappCallSetPageCommonInputAsync::onExit(isBackward);

}

void VappCallSetPageCugNameEdit::onFuncBtnClicked(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case VAPP_CALLSET_FUNC_OK:
        {
            srv_callset_rsp_evt_struct evt;
            srv_callset_result_struct res;

            setCurrState(STATE_ACT);

            if (!mmi_wcslen(m_textInput->getText()) && 
                (srv_callset_cug_get_actviated_id(callset_p->m_sim) == callset_p->m_inCugId))
            {
                srv_callset_result_enum result;

                /* deactivate first */
                srv_callset_cug_deactivate_struct deact;
                deact.sim = callset_p->m_sim;
                deact.cug_id = callset_p->m_inCugId;
                result = srv_callset_cug_deactivate(&deact, vapp_callset_hdlr_rsp, NULL);
                
                showWaitPopup(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT), VFX_FALSE);

                if (result != SRV_CALLSET_RESULT_OK)
                {
                    evt.evt_id = EVT_ID_SRV_CALLSET_ACT_RESPONSE;
                    res.sim = callset_p->m_sim;
                    res.result = result;
                    evt.data = &res;
                    onResult((mmi_event_struct*)&evt);
                }
            }
            else
            {
                evt.evt_id = EVT_ID_SRV_CALLSET_ACT_RESPONSE;
                res.sim = callset_p->m_sim;
                res.result = SRV_CALLSET_RESULT_OK;
                evt.data = &res;
                onResult((mmi_event_struct*)&evt);
            }
            break;
        }

        default:
            return VappCallSetPageCommonInputAsync::onFuncBtnClicked(sender, id);
    }
}

void VappCallSetPageCugNameEdit::onResult(mmi_event_struct *info)
{
    if (getCurrState() == STATE_NONE ||
            getCurrState() >= STATE_INVALID)
    {
        /* abort rsp from the previous page or abnormal */
        return;
    }


    if (getCurrState() != STATE_ABORT)
    {
        srv_callset_rsp_evt_struct * evt = (srv_callset_rsp_evt_struct*)info;
        MMI_ASSERT(evt);
        srv_callset_result_struct *res = (srv_callset_result_struct*)(evt->data);
        MMI_ASSERT(res);

        leaveWaitPopup();
        setCurrState(STATE_NONE);

        if (res->result != SRV_CALLSET_RESULT_OK)
        {
            VAPP_CALLSET_FAIL_POPUP(this, VFX_WSTR_RES(srv_callset_get_result_string_id(res->result)));
        }
        else
        {
            srv_callset_cug_set_item_struct item;
            item.cug_id = callset_p->m_inCugId;
            mmi_wcscpy(item.name, m_textInput->getText());

            srv_callset_result_enum result;
            result = srv_callset_cug_set_item(callset_p->m_sim, &item);

            if (result != SRV_CALLSET_RESULT_OK)
            {
                VAPP_CALLSET_FAIL_POPUP(this,
                    VFX_WSTR_RES(srv_callset_get_result_string_id(result)));
            }
            else
            {
                getMainScr()->popPage();
            }
        }
    }
    else
    {
        setCurrState(STATE_NONE);
    }

}

void VappCallSetPageCugNameEdit::onTextChanged(VcpTextEditor* editor)
{
    // Override VappCallSetPageCommonInputAsync::onTextChanged
}

#pragma arm section code, rodata
