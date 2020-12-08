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
 *  vapp_cal_search.cpp
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  implementation of search list screen of event/task
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
 /***************************************************************************** 
* Include
*****************************************************************************/
#include "mmi_features.h"
#ifndef __LOW_COST_SUPPORT_COMMON__
extern "C" 
{
#include "app_datetime.h"
#include "custom_mmi_default_value.h"
#include "Unicodexdcl.h"
#include "todolistsrvgprot.h"
#include "mmi_rp_vapp_calendar_def.h"
}
#include "globalresdef.h"


#include "vfx_system.h"
#include "vcp_navi_title_bar.h"
#include "vcp_text_editor.h"

#include "vapp_cal_utility.h"
#include "vapp_cal_view_detail.h"
#include "vapp_cal_edit.h"
#include "vapp_cal_list_mgr.h"
#include "vapp_cal_prot.h"
#include "vapp_cal_search.h"
#include "vfx_adp_device.h"

#ifdef __MMI_VUI_COSMOS_CP__
#include "mmi_rp_app_cosmos_global_def.h"
#endif




/***************************************************************************** 
 * Class  VappCalSearchPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappCalSearchPage", VappCalSearchPage, VfxPage);

// IVcpListMenuContentProvider
VfxBool VappCalSearchPage::getItemText(
                                VfxU32 index,                    
                                VcpListMenuFieldEnum fieldType,  
                                VfxWString &text,                
                                VcpListMenuTextColorEnum &color  
                                )
{

    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;


    srv_tdl_event_struct *event = NULL;

    srv_tdl_task_short_struct *task;
    void *data;

    if (m_vcalType == SRV_TDL_VCAL_EVENT)
    {   
        
        VFX_ALLOC_MEM(event,sizeof(srv_tdl_event_struct),this);
        srv_tdl_event_get(
                    event, 
                    sizeof(srv_tdl_event_struct), 
                    m_eventbuffer[index].source_id,
                    m_eventbuffer[index].event_id);

        
        data = event;
    }
    else
    {
        VfxU16 storeIndex = m_dataMgr->getListItemStoreIndex(index);
        srv_tdl_get_cache(
                (void**)&task, 
                sizeof(srv_tdl_task_short_struct), 
                m_vcalType, 
                storeIndex);
        
        data = task;
    }

    
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        if (m_vcalType == SRV_TDL_VCAL_EVENT)
        {   

            //text = VFX_WSTR_STATIC((VfxWChar*)event->subject);
            text = VFX_WSTR_MEM((VfxWChar*)event->subject);
        }
        else
        {            
            text = VFX_WSTR_STATIC((VfxWChar*)task->subject);
        }
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1 ||
             fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT2)
    {
        VappCalUtility::getListItemDateTimeStr(
                                fieldType, 
                                m_vcalType,
                                (const void*)data,
                                text);  
    }

   
    if (m_vcalType == SRV_TDL_VCAL_EVENT)
    {
        VFX_FREE_MEM(data);
    }


    return VFX_TRUE;
}


VfxU32 VappCalSearchPage::getCount() const
{
    if(m_vcalType == SRV_TDL_VCAL_EVENT)
    {
        return m_count;
    }
    else
    {
        return m_dataMgr->getListCount();
    }
 
}

VfxBool VappCalSearchPage::getMenuEmptyText(
                            VfxWString &text,               
                            VcpListMenuTextColorEnum &color)
{
 
    if (m_vcalType == SRV_TDL_VCAL_EVENT)
    {   
        text = VfxWString(VFX_WSTR_RES(m_stringId));
    }
    else
    {
        text = VfxWString(VFX_WSTR_RES(STR_ID_VAPP_CAL_NO_TASK));
    }

    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    return VFX_TRUE;
}


VfxBool VappCalSearchPage::getItemTextFormat(
                        VfxU32 index,                    
                        VcpListMenuFieldEnum fieldType,  
                        VcpRichText &format        
    )
{

    if(fieldType == VCP_LIST_MENU_FIELD_TEXT && m_searchStringLen)
    {   

        VcpListMenuSearchBar *searchBar;
        searchBar = m_listMenu->getSearchBar();

        VcpTextEditor *txtEditor;
        txtEditor = searchBar->getSearchEditor();

       

        VfxChar *resultStr;
        VfxS32 startPos = 0;

        VfxChar *editorStr;
        VfxChar *subjStr;

        VFX_SYS_ALLOC_MEM(editorStr, MAX_TODO_LIST_NOTE);
        VFX_ASSERT(editorStr);

        VFX_SYS_ALLOC_MEM(subjStr, MAX_TODO_LIST_NOTE);
        VFX_ASSERT(subjStr);

        mmi_ucs2cpy(editorStr, (const CHAR*)txtEditor->getText());

        if (m_vcalType == SRV_TDL_VCAL_EVENT)
        {
           
            srv_tdl_event_struct *event;
            VFX_ALLOC_MEM(event,sizeof(srv_tdl_event_struct),this);
            srv_tdl_event_get(
                        event, 
                        sizeof(srv_tdl_event_struct), 
                        m_eventbuffer[index].source_id,
                        m_eventbuffer[index].event_id);

            mmi_ucs2cpy(subjStr, (const CHAR *)event->subject);

            resultStr = VappCalListMgr::vappCalUcs2istr(subjStr, editorStr);

            startPos = (resultStr - (VfxChar*)subjStr) / 2;


            VFX_FREE_MEM(event);

        }
        else
        {
            srv_tdl_task_short_struct *task;
            VfxU16 storeIndex;
            storeIndex = m_dataMgr->getListItemStoreIndex(index);
            srv_tdl_get_cache(
                    (void**)&task, 
                    sizeof(srv_tdl_task_short_struct), 
                    SRV_TDL_VCAL_TASK,
                    storeIndex);

            mmi_ucs2cpy(subjStr, (const CHAR *)task->subject);

            resultStr = VappCalListMgr::vappCalUcs2istr(subjStr, editorStr);

            startPos = (resultStr - (VfxChar*)subjStr) / 2;
        }
        
        VFX_SYS_FREE_MEM(editorStr);
        VFX_SYS_FREE_MEM(subjStr);

        format.setRange(startPos, startPos + m_searchStringLen);
        format.setTextBgColor(VfxColor(VFX_COLOR_RES(CLR_COSMOS_BG_SEARCH)));
        format.setTextColor(VfxColor(VFX_COLOR_BLACK));


        return VFX_TRUE;
    }

    return VFX_FALSE;

}


void VappCalSearchPage::onInit()
{
    VfxPage::onInit();

    if(m_vcalType == SRV_TDL_VCAL_EVENT)
    {
        mmi_frm_cb_reg_event(EVT_ID_SRV_TDL_EVENT_OP, updateEventSearchPage, getObjHandle());
    }

    mmi_frm_cb_reg_event(EVT_ID_SRV_TDL_OP, updateSearchPage, getObjHandle());

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_GLOBAL_SEARCH));
    setTopBar(bar);

    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listMenu->setSize(getSize());
    m_listMenu->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->setContentProvider(this);

    if (m_vcalType == SRV_TDL_VCAL_EVENT)
    {
        m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_TRIPLE_TEXT);
    }
    else //task
    {
        m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT);
    }
    
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_FALSE);
    m_listMenu->m_signalItemTapped.connect(this, &VappCalSearchPage::onItemTapped);
    m_listMenu->m_signalItemLongTapped.connect(this,&VappCalSearchPage::onListMenuLongTap);
    m_listMenu->enableSearchBar(VFX_TRUE);

    VcpListMenuSearchBar *searchBar;
    searchBar = m_listMenu->getSearchBar();
    searchBar->setMaxSearchLength(VAPP_CAL_MAX_SUBJECT_LEN);
    VcpTextEditor *txtEditor;
    txtEditor = searchBar->getSearchEditor();
    txtEditor->setIME(IMM_INPUT_TYPE_SENTENCE, IME_SETTING_FLAG_NONE);
    txtEditor->m_signalTextChanged.connect(this, &VappCalSearchPage::onTextChanged);
    txtEditor->setAutoActivated(VFX_TRUE);

   if(m_vcalType == SRV_TDL_VCAL_TASK)
   {
        VfxU16 count =  VAPP_TASK_MAX_COUNT;
        VFX_OBJ_CREATE_EX(m_dataMgr, VappCalListMgr, this, (m_vcalType, count));
        m_dataMgr->getAllList(m_vcalType);
   }
   else
   {
        m_count = 0;
        m_eventbuffer = NULL;
        m_stringId = STR_GLOBAL_LOADING;
        m_jobId = -1;
        GetSnsData(NULL);
   }

    m_dataChangedType = SRV_TDL_OP_TOTAL;
}


void VappCalSearchPage::setDataChangeState(VfxBool isDataChanged)
{
    m_dataChanged = isDataChanged;
}

void VappCalSearchPage::GetSnsData(const VfxWChar *subject)
{
    if(m_eventbuffer)
    {
        VFX_FREE_MEM(m_eventbuffer);
    } 
    m_count = 0;
    if(m_jobId > 0)
    {
        srv_tdl_event_search_end(m_jobId);
        mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_EVENT_SEARCH, VappCalSearchPage::updateSNSListData, getObjHandle());
        m_jobId = -1;
    }
    m_stringId = STR_GLOBAL_LOADING;

    srv_tdl_search_filter_struct search_info;
    search_info.type=SRV_TDL_SEARCH_TYPE_ALL;
   
    //srv_tdl_set_source_state(MMI_TRUE, SRV_TDL_EVENT_SOURCE_TOTAL);	

    m_jobId = srv_tdl_event_search_begin(&search_info, SRV_TDL_EVENT_SORT_START_TIME,SRV_TDL_EVENT_SOURCE_TOTAL);
    if(m_jobId > 0)
    {
        mmi_frm_cb_reg_event(EVT_ID_SRV_TDL_EVENT_SEARCH, VappCalSearchPage::updateSNSListData, getObjHandle());
    }
    else
    { 
        m_stringId = STR_ID_VAPP_CAL_NO_EVTS;
    }
}


mmi_ret VappCalSearchPage::updateSNSListData(mmi_event_struct *param)
{
    srv_tdl_search_callback_struct* sEvent = (srv_tdl_search_callback_struct*)param;

    VfxObject *obj = handleToObject((VfxObjHandle)param->user_data);
    if(obj == NULL)
    {
        return MMI_RET_OK;
    }
    VappCalSearchPage *page = VFX_OBJ_DYNAMIC_CAST(obj,VappCalSearchPage);

    if(page == NULL) 
    {
        return MMI_RET_OK;
    }


    if(!sEvent->success)
    { 
        VappCalUtility::getSnsDataError();
    }

    if(sEvent->job_id == page->m_jobId)
    {
        page->m_count = sEvent->event_cnt;
        if(page->m_count != 0)
        {
            VFX_ALLOC_MEM(page->m_eventbuffer, sEvent->event_cnt * sizeof(srv_tdl_event_id_struct),page);
            if(srv_tdl_event_search_get(page->m_jobId, page->m_eventbuffer, page->m_count * sizeof(srv_tdl_event_id_struct) , 0) < 0)
            {
                VFX_ASSERT(0);
            }

        }

        page->m_stringId = STR_ID_VAPP_CAL_NO_EVTS;
        srv_tdl_event_search_end(sEvent->job_id);
        mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_EVENT_SEARCH, VappCalSearchPage::updateSNSListData, page->getObjHandle());
        page->m_jobId = -1;

        if(page->m_searchStringLen != 0)
        {
            srv_tdl_search_filter_struct search_info;
            search_info.type=SRV_TDL_SEARCH_TYPE_SUBJECT;
            VcpTextEditor *txtEditor;
            txtEditor = page->m_listMenu->getSearchBar()->getSearchEditor();
            vfx_sys_wcscpy((VfxWChar*)(search_info.u.str_buf), txtEditor->getText());


            srv_tdl_event_struct *event = NULL;
            VFX_SYS_ALLOC_MEM(event,sizeof(srv_tdl_event_struct));

            VfxU32 index = 0;
            for(VfxU32 idx = 0; idx < page->m_count; idx++)
            {
                srv_tdl_event_get(
                            event, 
                            sizeof(srv_tdl_event_struct), 
                            page->m_eventbuffer[idx].source_id,
                            page->m_eventbuffer[idx].event_id);


                VfxBool suit;

                suit = srv_tdl_search_default_check(event, SRV_TDL_VCAL_EVENT, search_info);
                if(suit)
                {
                    page->m_eventbuffer[index].source_id =  page->m_eventbuffer[idx].source_id;

                    page->m_eventbuffer[index].event_id =  page->m_eventbuffer[idx].event_id;

                    index++;
                }
            }
            VFX_FREE_MEM(event);
            page->m_count = index;
        }
        

        page->m_listMenu->resetAllItems(VFX_TRUE);

    }
    return MMI_RET_OK;
}


void VappCalSearchPage::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_OP, updateSearchPage, getObjHandle());

    if(m_vcalType == SRV_TDL_VCAL_EVENT) 
    {
        mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_EVENT_OP, updateEventSearchPage, getObjHandle());
        if(m_eventbuffer)
        {
            VFX_FREE_MEM(m_eventbuffer);
        }
        if(m_jobId)
        {
            srv_tdl_event_search_end(m_jobId);
            mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_EVENT_SEARCH, VappCalSearchPage::updateSNSListData, getObjHandle());
            m_jobId = -1;
        }
    }

    VfxPage::onDeinit();
}


void VappCalSearchPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    if (m_dataChangedType == SRV_TDL_OP_UPDATE)
    {
        m_listMenu->setVisibleMenuRegion(m_selIdx, -1, VFX_TRUE);
    }

    m_dataChangedType = SRV_TDL_OP_TOTAL;
}


void VappCalSearchPage::onEntered()
{
    if(m_dataChanged)
    {
        if(m_vcalType == SRV_TDL_VCAL_EVENT)
        {
            VcpTextEditor *txtEditor;
            txtEditor = m_listMenu->getSearchBar()->getSearchEditor();
            m_searchStringLen = vfx_sys_wcslen(txtEditor->getText());
            if(m_searchStringLen == 0)
            {
                GetSnsData(NULL);
            }
            else
            {
                GetSnsData(txtEditor->getText());
            }
        }
        else if(m_vcalType == SRV_TDL_VCAL_TASK)
        {
            onDataUpdated(NULL);
        }
    }

}


void VappCalSearchPage::onItemTapped(VcpListMenu *sender, VfxU32 id)
{
    VappCalViewDetailPage *page;
    if(m_vcalType == SRV_TDL_VCAL_TASK)
    {
        VfxU16 storeIndex = m_dataMgr->getListItemStoreIndex(id);
        VFX_OBJ_CREATE_EX(page, VappCalViewDetailPage, this, (m_vcalType, storeIndex));
    }
    else
    {
        VFX_OBJ_CREATE_EX(page, VappCalViewDetailPage, this, (m_vcalType, m_eventbuffer[id]));
    }

    page->m_signalDataUpdated.connect(this, &VappCalSearchPage::onDataUpdated);
    getMainScr()->pushPage(0, page);
}


void VappCalSearchPage::onListMenuLongTap(VcpListMenu *sender, VfxU32 id)
{
    //VFX_ASSERT(pos.group > 0 && pos.group < 0);

    if (m_listMenu->getMenuMode() != VCP_LIST_MENU_MODE_NORMAL)
    {
        return;
    }

    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);

    m_selIdx = id;


    VcpMenuPopup *opList;
    VFX_OBJ_CREATE(opList, VcpMenuPopup, this);
    opList->addItem(0, VFX_WSTR_RES(STR_ID_VAPP_CAL_DELETE));
    void* buffer = NULL;
    if(m_vcalType == SRV_TDL_VCAL_TASK)
    {
        srv_tdl_task_short_struct *buffer;
        srv_tdl_get_cache(
                    (void**) &buffer, 
                    sizeof(srv_tdl_task_short_struct),
                    SRV_TDL_VCAL_TASK, 
                    m_dataMgr->getListItemStoreIndex(m_selIdx));
        opList->setTitle(VFX_WSTR_MEM((VfxWChar *)(srv_tdl_task_short_struct *)buffer->subject));
    }
    else
    {
        VFX_ALLOC_MEM(buffer,sizeof(srv_tdl_event_struct),this);
        srv_tdl_event_get(
                    (srv_tdl_event_struct *)buffer, 
                    sizeof(srv_tdl_event_struct), 
                    m_eventbuffer[m_selIdx].source_id,
                    m_eventbuffer[m_selIdx].event_id);   
        opList->setTitle(VFX_WSTR_MEM((VfxWChar *)(((srv_tdl_event_struct *)buffer)->subject)));

    }

    if(m_vcalType == SRV_TDL_VCAL_EVENT)
    {
        if(((srv_tdl_event_struct *)buffer)->src_id != SRV_TDL_EVENT_SOURCE_LOCAL)
        {
            opList->removeItem(opList->getItemById(0));
            opList->addItem(1, VFX_WSTR_RES(STR_ID_VAPP_CAL_CANCEL));
        }

        VFX_FREE_MEM(buffer);
    }

    opList->m_signalMenuCallback.connect(this, &VappCalSearchPage::onOpListClicked);
    opList->show(VFX_TRUE);

    m_opListWeakPtr = opList;  
}


void  VappCalSearchPage::onOpListClicked(VcpMenuPopup* sender, VcpMenuPopupEventEnum evtEnum, VcpMenuPopupItem* item)
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

        if (m_vcalType == SRV_TDL_VCAL_EVENT)
        {
            srv_tdl_event_struct *buffer;
            VFX_ALLOC_MEM(buffer,sizeof(srv_tdl_event_struct),this);
            srv_tdl_event_get(
                              buffer, 
                              sizeof(srv_tdl_event_struct), 
                              m_eventbuffer[m_selIdx].source_id,
                              m_eventbuffer[m_selIdx].event_id);



            if (!buffer->repeat.rule)
            {
                confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_CAL_DELETE_EVENT_ASK));
            }
            else
            {
                confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_CAL_DELETE_ALL_REPEAT_ASK));
            }
            VFX_FREE_MEM(buffer);
        }
        else
        {
            VfxU16 storeIndex = m_dataMgr->getListItemStoreIndex(m_selIdx);
            srv_tdl_task_short_struct *buffer;
            srv_tdl_get_cache(
                        (void**) &buffer, 
                        sizeof(srv_tdl_task_short_struct),
                        SRV_TDL_VCAL_TASK, 
                        m_dataMgr->getListItemStoreIndex(m_selIdx));
            confirmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_CAL_DELETE_TASK));
        }


        confirmPopup->setAutoDestory(VFX_TRUE);    
        confirmPopup->m_signalButtonClicked.connect(this, &VappCalSearchPage::onLongPressDelConfirm);
        confirmPopup->show(VFX_TRUE);

        m_confirmPopupWeakPtr = confirmPopup;
    }
    else
    {
        if (m_opListWeakPtr.isValid())
        {
            VcpMenuPopup *temp = m_opListWeakPtr.get();
            VFX_OBJ_CLOSE(temp);
        }
    }

}


void VappCalSearchPage::onLongPressDelConfirm(VfxObject* sender, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        if(m_vcalType ==SRV_TDL_VCAL_EVENT)
        {
            srv_tdl_event_delete(m_eventbuffer[m_selIdx].source_id,m_eventbuffer[m_selIdx].event_id);
        }
        else
        {
            srv_tdl_delete(m_dataMgr->getListItemStoreIndex(m_selIdx), SRV_TDL_VCAL_TASK);
        }
    }

}




void VappCalSearchPage::onDataUpdated(VfxObject *sender)
{
    VcpTextEditor *txtEditor;

    txtEditor = m_listMenu->getSearchBar()->getSearchEditor();

    m_dataMgr->getListBySubject(txtEditor->getText());

    m_listMenu->resetAllItems();
}


void VappCalSearchPage::onTextChanged(VcpTextEditor* sender)
{
    m_searchStringLen = vfx_sys_wcslen(sender->getText());

    if(m_vcalType ==SRV_TDL_VCAL_TASK)
    {
    m_dataMgr->getListBySubject(sender->getText());
        }
    else
    {
        GetSnsData(sender->getText());
    }
    m_listMenu->resetAllItems();
}

mmi_ret VappCalSearchPage::updateEventSearchPage(mmi_event_struct *param)
{
    VfxObject *obj = handleToObject((VfxObjHandle)param->user_data);
    if(obj == NULL)
    {
        return MMI_RET_OK;
    }
    VappCalSearchPage *page = VFX_OBJ_DYNAMIC_CAST(obj,VappCalSearchPage);

    if(page == NULL) 
    {
        return MMI_RET_OK;
    }

    if(!page->isActive())
    {
        page->setDataChangeState(VFX_TRUE);	 
        return MMI_RET_OK;
    }

    VcpTextEditor *txtEditor;
    txtEditor = page->m_listMenu->getSearchBar()->getSearchEditor();
    page->m_searchStringLen = vfx_sys_wcslen(txtEditor->getText());
    if(page->m_searchStringLen == 0)
    {
        page->GetSnsData(NULL);
    }
    else
    {
        page->GetSnsData(txtEditor->getText());
    }

    page->m_listMenu->resetAllItems(VFX_TRUE);

    if (page->m_opListWeakPtr.isValid())
    {
        VcpMenuPopup *temp = page->m_opListWeakPtr.get();
        VFX_OBJ_CLOSE(temp);
    }
    if (page->m_confirmPopupWeakPtr.isValid())
    {
        VcpConfirmPopup *temp = page->m_confirmPopupWeakPtr.get();
        VFX_OBJ_CLOSE(temp);
    }

    return MMI_RET_OK;
}


mmi_ret VappCalSearchPage::updateSearchPage(mmi_event_struct *param)
{
    VfxObject *obj = handleToObject((VfxObjHandle)param->user_data);
    if(obj == NULL)
    {
        return MMI_RET_OK;
    }

    VappCalSearchPage *thiz = VFX_OBJ_DYNAMIC_CAST(obj,VappCalSearchPage);

    if(thiz == NULL) 
    {
        return MMI_RET_OK;
    }

    return thiz->processOpEvent(param);
}

mmi_ret VappCalSearchPage::processOpEvent(mmi_event_struct *param)
{
    if(!isActive())
    {
        setDataChangeState(VFX_TRUE);	 
        return MMI_RET_OK;
    }

    if (m_opListWeakPtr.isValid())
    {
        VcpMenuPopup *temp = m_opListWeakPtr.get();
        VFX_OBJ_CLOSE(temp);
    }
    if (m_confirmPopupWeakPtr.isValid())
    {
        VcpConfirmPopup *temp = m_confirmPopupWeakPtr.get();
        VFX_OBJ_CLOSE(temp);
    }

    if(m_vcalType == SRV_TDL_VCAL_TASK)
    {
        srv_tdl_op_evt_struct *event = (srv_tdl_op_evt_struct *)param;
        onDataUpdated(NULL);

        if (event->op_type == SRV_TDL_OP_UPDATE)
        {
        // in order that the new added or updated could be visible on this list page, we need remember the index
            VfxU16 listIdx = m_dataMgr->getListIdx(event->store_idx);

            if (listIdx != m_dataMgr->getListCount())
            {
                m_selIdx = listIdx;
            }
        }

        m_dataChangedType = event->op_type;
        m_listMenu->resetAllItems(VFX_TRUE);

        return MMI_RET_OK;
    }
    else
    {
        VappCalSearchPage::updateEventSearchPage(param);
    }

}
#endif   /*undefine __LOW_COST_SUPPORT_COMMON__*/
