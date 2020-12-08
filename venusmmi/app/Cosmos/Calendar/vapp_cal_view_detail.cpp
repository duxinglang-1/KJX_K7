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
 *  vapp_cal_view_detail.cpp
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  implementation of view event/task detail
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
 * removed!
 * removed!
 * removed!
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
extern "C" 
{
#include "mmi_features.h"
#include "MMIDataType.h"

#include "app_datetime.h"
#include "custom_mmi_default_value.h"
#include "emailappgprot.h"
#include "filemgrsrvgprot.h"
#include "todolistsrvgprot.h"
#include "ucsrvgprot.h"
#include "unicodexdcl.h"
#include "usbsrvgprot.h"
#include "vcalsrvgprot.h"
}

#include "globalresdef.h"
#include "mmi_rp_vapp_calendar_def.h"

#include "vfx_system.h"
#include "vcp_navi_title_bar.h"
#include "vcp_text_view.h"

#include "vapp_usb_gprot.h"
#include "vapp_uc_gprot.h"
#include "vapp_bt_send_gprot.h"

#include "vapp_cal_prot.h"
#include "vapp_cal_edit.h"
#include "vapp_cal_utility.h"
#include "vapp_cal_view_detail.h"
#include "vcp_tool_bar.h"


/**************************IMPLEMENTATION****************************************/
/********************************************************************************/
#ifndef __MMI_VCALENDAR__
#pragma arm section code = "DYNAMIC_CODE_CLNDR_ROCODE", rodata = "DYNAMIC_CODE_CLNDR_RODATA"
#endif

VFX_IMPLEMENT_CLASS("VappCalViewDetailPage", VappCalViewDetailPage, VfxPage);

void VappCalViewDetailPage::onInit()
{
    VfxPage::onInit();

    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    setTopBar(m_titleBar);

    //1. alloc memory for m_data, only once
    
#ifdef __MMI_TASK_APP__
    VfxU32 size = 
    (m_vcalType == SRV_TDL_VCAL_EVENT ? sizeof(srv_tdl_event_struct) : sizeof(srv_tdl_task_struct));
#else
    VfxU32 size = sizeof(srv_tdl_event_struct);
#endif

    VFX_ALLOC_MEM(m_data, size, this);
    VFX_ASSERT(m_data);


    //2. create detailed content text view

    VFX_OBJ_CREATE(m_multilineView, VcpTextView, this);
    VFX_ALLOC_MEM(m_multiViewString, ((VAPP_CAL_VIEW_DETAIL_MAX_LEN + 1) * 2), this);
    VFX_ASSERT(m_multiViewString);

    m_multilineView->setPos(VAPP_CAL_DETAIL_LEFT_GAP, VAPP_CAL_DETAIL_TOP_GAP);
    m_multilineView->setSize(
                    getSize().width - VAPP_CAL_DETAIL_LEFT_GAP - VAPP_CAL_DETAIL_RIGHT_GAP,
                    getSize().height - VAPP_CAL_DETAIL_TOP_GAP - VAPP_CAL_DETAIL_DOWN_GAP);

    m_multilineView->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                VFX_FRAME_ALIGNER_MODE_SIDE, 
                                VFX_FRAME_ALIGNER_MODE_SIDE, 
                                VFX_FRAME_ALIGNER_MODE_SIDE);

    //3. create toolbar for view page

    VcpToolBar *toolBar;

    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);

    toolBar->addItem(VAPP_CAL_TOOLBAR_VIEW_EDIT, (VfxResId)STR_ID_VAPP_CAL_EDIT, VCP_IMG_TOOL_BAR_COMMON_ITEM_EDIT);
    // do not support this function
    // toolBar->addItem(VAPP_CAL_TOOLBAR_VIEW_SAVEAS, VFX_WSTR_RES(STR_ID_VAPP_CAL_SAVE_AS_FILE), IMG_ID_VAPP_CAL_SAVE_AS_FILE);
#if ((defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__) || \
     defined(__MMI_EMAIL__) || defined(__MMI_OPP_SUPPORT__))&& defined(__MMI_VCALENDAR__))		
    toolBar->addItem(VAPP_CAL_TOOLBAR_VIEW_SHARE, (VfxResId)STR_ID_VAPP_CAL_SHARE, VCP_IMG_TOOL_BAR_COMMON_ITEM_SHARE);
#endif
    toolBar->addItem(VAPP_CAL_TOOLBAR_VIEW_DELETE, (VfxResId)STR_ID_VAPP_CAL_DELETE, VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE);

#ifdef __MMI_SNS_CALENDAR__
    if(m_eventbuffer.source_id != SRV_TDL_EVENT_SOURCE_LOCAL)
    {
        toolBar->setDisableItem(VAPP_CAL_TOOLBAR_VIEW_DELETE, VFX_TRUE);
    }
    if(m_vcalType == SRV_TDL_VCAL_TASK)
    {

        toolBar->setDisableItem(VAPP_CAL_TOOLBAR_VIEW_DELETE, VFX_FALSE);
    }

#endif
    toolBar->m_signalButtonTap.connect(this, &VappCalViewDetailPage::onTBClick);
    setBottomBar(toolBar);
    
#ifndef __MMI_CAL_SLIM__
    if (m_vcalType == SRV_TDL_VCAL_EVENT)
    {
        mmi_frm_cb_reg_event(EVT_ID_SRV_TDL_EVENT_OP, &VappCalViewDetailPage::onEventChange, getObjHandle());
    }
    mmi_frm_cb_reg_event(EVT_ID_SRV_TDL_OP, &VappCalViewDetailPage::onEvent, getObjHandle());
#endif

}


void VappCalViewDetailPage::onDeinit()
{

#ifndef __MMI_CAL_SLIM__
    if (m_vcalType == SRV_TDL_VCAL_EVENT)
    {
        mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_EVENT_OP, &VappCalViewDetailPage::onEventChange, getObjHandle());
    }
    
    mmi_frm_cb_dereg_event(EVT_ID_SRV_TDL_OP, &VappCalViewDetailPage::onEvent, getObjHandle());
#endif
    if (m_data)
    {
        VFX_FREE_MEM(m_data);        
    }

    if (m_multiViewString)
    {
        VFX_FREE_MEM(m_multiViewString);
    }

    VfxPage::onDeinit();
}

void VappCalViewDetailPage::onUpdate()
{
    VfxPage::onUpdate();

    if (m_vcalType == SRV_TDL_VCAL_EVENT)
    {
        srv_tdl_event_struct *buffer;
        VFX_ALLOC_MEM(buffer,sizeof(srv_tdl_event_struct),this);
        srv_tdl_event_get(
                buffer, 
                sizeof(srv_tdl_event_struct), 
                m_eventbuffer.source_id,
                m_eventbuffer.event_id);


        m_titleBar->setTitle(VFX_WSTR_DYNAMIC((VfxWChar*)buffer->subject));

        if(buffer->src_id != SRV_TDL_EVENT_SOURCE_LOCAL)
        {
            ((VcpToolBar *)getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))->setDisableItem(3, VFX_TRUE); 	
        }

        VFX_FREE_MEM(buffer);
        
        initEventViewDetail();

    }
#ifdef __MMI_TASK_APP__
    else //SRV_TDL_VCAL_TASK
    {
        srv_tdl_task_short_struct *buffer;
        srv_tdl_get_cache(
                    (void**) &buffer, 
                    sizeof(srv_tdl_task_short_struct),
                    SRV_TDL_VCAL_TASK, 
                    m_index);

        m_titleBar->setTitle(VFX_WSTR_DYNAMIC((VfxWChar*)buffer->subject));
        
        initTaskViewDetail();
    }
#endif

}


void VappCalViewDetailPage::initEventViewDetail()
{
    srv_tdl_event_struct *event = (srv_tdl_event_struct*)m_data;


    //VFX_ALLOC_MEM(event,sizeof(srv_tdl_event_struct),this);
    VFX_ASSERT(srv_tdl_event_get(event, sizeof(srv_tdl_event_struct), m_eventbuffer.source_id, m_eventbuffer.event_id) == SRV_TDL_RESULT_OK);



    VfxWString str;


    m_multiViewString[0] = 0;
    m_multilineView->setText(m_multiViewString, VFX_TRUE);

    //category
    str = VFX_WSTR_RES(STR_ID_VAPP_CAL_CATEGORY);
    str += VFX_WSTR("\n");
    m_multilineView->addDetail(str, 
                            VCP_TEXT_DETAIL_TITLE, 
                            VAPP_CAL_VIEW_DETAIL_MAX_LEN);
    VAPP_CAL_CATEGORY_ENUM categoryUI = VappCalEditPage::convertCategoryStoM((srv_vcal_category_type_enum)(event->category));
    str = VappCalCategoryListPage::getCategoryString(categoryUI);
    str += VFX_WSTR("\n");
    m_multilineView->addDetail(str, 
                            VCP_TEXT_DETAIL_CONTENT, 
                            VAPP_CAL_VIEW_DETAIL_MAX_LEN);
    
    VfxDateTime dt;

    applib_time_struct time;
    if (categoryUI == VAPP_CAL_CATEGORY_SPECIALDAY ||
        categoryUI == VAPP_CAL_CATEGORY_BIRTHDAY)
    {
        //Date
        str = VFX_WSTR_RES(STR_ID_VAPP_CAL_DATE);
        str += VFX_WSTR("\n");
        m_multilineView->addDetail(str, 
        VCP_TEXT_DETAIL_TITLE, 
        VAPP_CAL_VIEW_DETAIL_MAX_LEN);
        memcpy(&time, &(event->start_time), sizeof(applib_time_struct));
        dt.setDateTime(&time);
        str =dt.getDateTimeString(VFX_DATE_TIME_DATE_MASK);
        str += VFX_WSTR("\n");
        m_multilineView->addDetail(str, 
                        VCP_TEXT_DETAIL_CONTENT, 
                        VAPP_CAL_VIEW_DETAIL_MAX_LEN);
    }
    else
    {
        //Start , To	
        str = VFX_WSTR_RES(STR_ID_VAPP_CAL_START);
        str += VFX_WSTR("\n");
        m_multilineView->addDetail(str, 
        VCP_TEXT_DETAIL_TITLE, 
        VAPP_CAL_VIEW_DETAIL_MAX_LEN);
        memcpy(&time, &(event->start_time), sizeof(applib_time_struct));
        dt.setDateTime(&time);
        str = dt.getDateTimeString(VFX_DATE_TIME_DATE_MASK | VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE);
        str += VFX_WSTR("\n");
        m_multilineView->addDetail(str, 
                    VCP_TEXT_DETAIL_CONTENT, 
                    VAPP_CAL_VIEW_DETAIL_MAX_LEN);

        str = VFX_WSTR_RES(STR_ID_VAPP_CAL_TO);
        str += VFX_WSTR("\n");
        m_multilineView->addDetail(str, 
                    VCP_TEXT_DETAIL_TITLE, 
                    VAPP_CAL_VIEW_DETAIL_MAX_LEN);
        memcpy(&time, &(event->end_time), sizeof(applib_time_struct));
        dt.setDateTime(&time);

        str = dt.getDateTimeString(VFX_DATE_TIME_DATE_MASK | VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE);
        str += VFX_WSTR("\n");
        m_multilineView->addDetail(str, 
                    VCP_TEXT_DETAIL_CONTENT, 
                    VAPP_CAL_VIEW_DETAIL_MAX_LEN);
    }


    //Repetition
    str = VFX_WSTR_RES(STR_ID_VAPP_CAL_REPEATITION);
    str += VFX_WSTR("\n");
    m_multilineView->addDetail(str, 
                    VCP_TEXT_DETAIL_TITLE, 
                    VAPP_CAL_VIEW_DETAIL_MAX_LEN);
    str = VappCalRepeatListPage::getRepeatString
                (VappCalEditPage::convertRepeatStoM((srv_tdl_repeat_rule_enum)(event->repeat.rule)));
    str += VFX_WSTR("\n");
    m_multilineView->addDetail(str, 
                    VCP_TEXT_DETAIL_CONTENT, 
                    VAPP_CAL_VIEW_DETAIL_MAX_LEN);

    //Reminder
    str = VFX_WSTR_RES(STR_ID_VAPP_CAL_REMINDER);
    str += VFX_WSTR("\n");
    m_multilineView->addDetail(str, 
                        VCP_TEXT_DETAIL_TITLE, 
                        VAPP_CAL_VIEW_DETAIL_MAX_LEN);
    str = VappCalReminderListPage::getReminderString(event->alarm.type);
    if (categoryUI == VAPP_CAL_CATEGORY_BIRTHDAY ||
        categoryUI == VAPP_CAL_CATEGORY_SPECIALDAY)
    {
        if (event->alarm.type != VAPP_CAL_REMINDER_NEVER)
        {
            str += VappCalReminderListPage::getReminderAdditionalString();
        }
    }
    str += VFX_WSTR("\n");
    m_multilineView->addDetail(str, 
                    VCP_TEXT_DETAIL_CONTENT, 
                    VAPP_CAL_VIEW_DETAIL_MAX_LEN);
    //Location
    if (vfx_sys_wcslen((const VfxWChar*)(event->location)) != 0)
    {   
        str = VFX_WSTR_RES(STR_ID_VAPP_CAL_LOC);
        str += VFX_WSTR("\n");
        m_multilineView->addDetail(str, 
        VCP_TEXT_DETAIL_TITLE, 
        VAPP_CAL_VIEW_DETAIL_MAX_LEN);
        str = VFX_WSTR_STATIC((VfxWChar*)event->location);
        str += VFX_WSTR("\n");
        m_multilineView->addDetail(str, 
                            VCP_TEXT_DETAIL_CONTENT, 
                            VAPP_CAL_VIEW_DETAIL_MAX_LEN);
    }


    //Note
    if (vfx_sys_wcslen((const VfxWChar*)(event->details)) != 0)
    {   
        str = VFX_WSTR_RES(STR_ID_VAPP_CAL_NOTE);
        str += VFX_WSTR("\n");
        m_multilineView->addDetail(str, 
        VCP_TEXT_DETAIL_TITLE, 
        VAPP_CAL_VIEW_DETAIL_MAX_LEN);
        str = VFX_WSTR_STATIC((VfxWChar*)event->details);
        str += VFX_WSTR("\n");
        m_multilineView->addDetail(str, 
                            VCP_TEXT_DETAIL_CONTENT, 
                            VAPP_CAL_VIEW_DETAIL_MAX_LEN);
    }
    //VFX_FREE_MEM(event);

}

#ifdef __MMI_TASK_APP__

void VappCalViewDetailPage::initTaskViewDetail()
{
    srv_tdl_task_struct *task = (srv_tdl_task_struct*)m_data;
    VFX_ASSERT(srv_tdl_get(task, sizeof(srv_tdl_task_struct), m_vcalType, m_index) == SRV_TDL_RESULT_OK);

    m_multiViewString[0] = 0;
    m_multilineView->setText(m_multiViewString, VFX_TRUE);

    VfxWString str;

    //Priority
    str = VFX_WSTR_RES(STR_ID_VAPP_CAL_PRIORITY);
    str += VFX_WSTR("\n");
    m_multilineView->addDetail(str, 
                VCP_TEXT_DETAIL_TITLE, 
                VAPP_CAL_VIEW_DETAIL_MAX_LEN);
    VAPP_CAL_PRIORITY_ENUM priorityUI = VappCalEditPage::convertPriorityStoM((srv_vcal_priority_enum)(task->priority));
    str = VappCalPriorityListPage::getPriorityString(priorityUI);
    str += VFX_WSTR("\n");
    m_multilineView->addDetail(str, 
                    VCP_TEXT_DETAIL_CONTENT, 
                    VAPP_CAL_VIEW_DETAIL_MAX_LEN);

    //Due to
    str = VFX_WSTR_RES(STR_ID_VAPP_CAL_DUE_TO);
    str += VFX_WSTR("\n");
    m_multilineView->addDetail(str, 
                            VCP_TEXT_DETAIL_TITLE, 
                            VAPP_CAL_VIEW_DETAIL_MAX_LEN);
    VfxDateTime dt;
    applib_time_struct time;
    memcpy(&time, &(task->due_time), sizeof(applib_time_struct));
    dt.setDateTime(&time);
    str = dt.getDateTimeString(VFX_DATE_TIME_DATE_MASK | VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE);
    str += VFX_WSTR("\n");
    m_multilineView->addDetail(str, 
                            VCP_TEXT_DETAIL_CONTENT, 
                            VAPP_CAL_VIEW_DETAIL_MAX_LEN);

    //Reminder
    str = VFX_WSTR_RES(STR_ID_VAPP_CAL_REMINDER);
    str += VFX_WSTR("\n");
    m_multilineView->addDetail(str, 
                            VCP_TEXT_DETAIL_TITLE, 
                            VAPP_CAL_VIEW_DETAIL_MAX_LEN);
    str = VappCalReminderListPage::getReminderString(task->alarm.type);
    str += VFX_WSTR("\n");
    m_multilineView->addDetail(str, 
                            VCP_TEXT_DETAIL_CONTENT, 
                            VAPP_CAL_VIEW_DETAIL_MAX_LEN);


    //Note
    if (vfx_sys_wcslen((const VfxWChar*)(task->details)) != 0)
    {   
        str = VFX_WSTR_RES(STR_ID_VAPP_CAL_NOTE);
        str += VFX_WSTR("\n");
        m_multilineView->addDetail(str, 
                            VCP_TEXT_DETAIL_TITLE, 
                            VAPP_CAL_VIEW_DETAIL_MAX_LEN);
        str = VFX_WSTR_STATIC((VfxWChar*)task->details);
        str += VFX_WSTR("\n");
        m_multilineView->addDetail(str, 
                    VCP_TEXT_DETAIL_CONTENT, 
                    VAPP_CAL_VIEW_DETAIL_MAX_LEN);
    }

}

#endif
void VappCalViewDetailPage::onTBClick(VfxObject* sender, VfxId id)
{
    switch(id)
    {
        case VAPP_CAL_TOOLBAR_VIEW_EDIT:
        {
            VappCalEditPage *page;
            VfxU16 temp = (VfxU16)-1;
            if (m_index != temp)
            {
                VFX_OBJ_CREATE_EX(page, VappCalEditPage, getMainScr(), (m_vcalType, m_index, VAPP_CAL_OPERATION_TYPE_EDIT));
            }
            else
            {
                VFX_OBJ_CREATE_EX(page, VappCalEditPage, getMainScr(), (m_vcalType, m_eventbuffer));
            }
#ifndef __MMI_CAL_SLIM__
            page->m_signalDataUpdated.connect(this, &VappCalViewDetailPage::onDataUpdated);
#endif
            getMainScr()->pushPage(0, page);
            break;
        }


#if ((defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__) || \
     defined(__MMI_EMAIL__) || defined(__MMI_OPP_SUPPORT__))&&defined(__MMI_VCALENDAR__))	
        case VAPP_CAL_TOOLBAR_VIEW_SHARE:

    #ifdef __MMI_USB_SUPPORT__
            if (srv_usb_is_in_mass_storage_mode())
            {
                /* Todo: Usd defined value SRV_USB_ERROR_UNAVAILABLE to get error string id then popup */
                vapp_usb_unavailable_popup(0);	
                return;
            }
    #endif

            VcpCommandPopup *cmd;
            VFX_OBJ_CREATE(cmd, VcpCommandPopup, this);

            cmd->setInfoType(VCP_POPUP_TYPE_INFO);
            if (m_vcalType == SRV_TDL_VCAL_EVENT)
            {
                cmd->setText((VfxResId)STR_ID_VAPP_CAL_SHARE_CAL);
            }
            
#ifdef __MMI_TASK_APP__
            else
            {
                cmd->setText((VfxResId)STR_ID_VAPP_CAL_SHARE_TASK);
            }
#endif
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))		
            cmd->addItem(VAPP_CAL_CMD_SHARE_BY_SMS, (VfxResId)STR_ID_VAPP_CAL_BY_SMS);
            cmd->addItem(VAPP_CAL_CMD_SHARE_BY_MMS, (VfxResId)STR_ID_VAPP_CAL_BY_MMS);
#endif		
#ifdef __MMI_EMAIL__
            cmd->addItem(VAPP_CAL_CMD_SHARE_BY_EMAIL, (VfxResId)STR_ID_VAPP_CAL_BY_EMAIL);
#endif
#ifdef __MMI_OPP_SUPPORT__
            cmd->addItem(VAPP_CAL_CMD_SHARE_BY_BLUETOOTH, (VfxResId)STR_ID_VAPP_CAL_BY_BT);
#endif
            cmd->addItem(VAPP_CAL_CMD_SHARE_CANCEL, (VfxResId)STR_ID_VAPP_CAL_CANCEL, VCP_POPUP_BUTTON_TYPE_CANCEL);
            cmd->m_signalButtonClicked.connect(this, &VappCalViewDetailPage::onShareCmdBtnClicked);
            cmd->setAutoDestory(VFX_TRUE);
            cmd->show(VFX_TRUE);
            break;      
#endif
        
        case VAPP_CAL_TOOLBAR_VIEW_DELETE:


            VcpConfirmPopup *confirmPopup;

            VFX_OBJ_CREATE(confirmPopup, VcpConfirmPopup, this);
            confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            if (m_vcalType == SRV_TDL_VCAL_EVENT)
            {
                srv_tdl_event_struct *event = (srv_tdl_event_struct*)m_data;

                if (!event->repeat.rule)
                {
                    confirmPopup->setText((VfxResId)STR_ID_VAPP_CAL_DELETE_EVENT_ASK);
                }
                else
                {
                    confirmPopup->setText((VfxResId)STR_ID_VAPP_CAL_DELETE_ALL_REPEAT_ASK);
                }
            }          
#ifdef __MMI_TASK_APP__
            else
            {
                confirmPopup->setText((VfxResId)STR_ID_VAPP_CAL_DELETE_TASK);
            }
#endif     
            confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            confirmPopup->setCustomButton(
                                (VfxResId)STR_ID_VAPP_CAL_DELETE,
                                (VfxResId)STR_ID_VAPP_CAL_CANCEL,
                                VCP_POPUP_BUTTON_TYPE_WARNING,
                                VCP_POPUP_BUTTON_TYPE_CANCEL);
            
            confirmPopup->setAutoDestory(VFX_TRUE);    
            confirmPopup->m_signalButtonClicked.connect(this, &VappCalViewDetailPage::onDeleteConfirm);
            confirmPopup->show(VFX_TRUE);
            break;        
        
        default:
            break;
    } 

}


void VappCalViewDetailPage::onDeleteConfirm(VfxObject* sender, VfxId id)
{        
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        if (m_vcalType == SRV_TDL_VCAL_EVENT)
        {
            srv_tdl_event_delete(m_eventbuffer.source_id,m_eventbuffer.event_id);
            
            #ifdef __MMI_CAL_SLIM__
            getMainScr()->closePage(getId());
            #endif
        }      
        #ifdef __MMI_TASK_APP__
        else
        {
            srv_tdl_delete(m_index, m_vcalType);
        }
        #endif
    }
}

#if ((defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__) || \
     defined(__MMI_EMAIL__) || defined(__MMI_OPP_SUPPORT__))&&defined(__MMI_VCALENDAR__))
void VappCalViewDetailPage::onShareCmdBtnClicked(VfxObject* sender, VfxId id)
{
    switch (id)
    {
    case VAPP_CAL_CMD_SHARE_BY_SMS:
    case VAPP_CAL_CMD_SHARE_BY_MMS:        
    case VAPP_CAL_CMD_SHARE_BY_EMAIL:
    case VAPP_CAL_CMD_SHARE_BY_BLUETOOTH:
        send((VAPP_CAL_CMD_SHARE_ID_ENUM)id);
        break;

    case VAPP_CAL_CMD_SHARE_CANCEL:
        break;

    default:
        break;
    }
}

void VappCalViewDetailPage::send(VAPP_CAL_CMD_SHARE_ID_ENUM viaType)
{
    VfxWChar path[VAPP_CAL_MAX_FILE_PATH_SIZE];

    if (VappCalUtility::buildTempVcalFile(path, m_data, m_vcalType, VAPP_CAL_BUILD_FOLDER_RECEIVED) == NULL)
    {
    //VFX_FREE_MEM(path);
        return;
    }

    switch(viaType)
    {
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
    case VAPP_CAL_CMD_SHARE_BY_SMS:  
    case VAPP_CAL_CMD_SHARE_BY_MMS:
      
        VappUcEntryStruct *ucEntry;
        ucEntry = (VappUcEntryStruct*) mmi_frm_temp_alloc(sizeof(VappUcEntryStruct));

        memset(ucEntry, 0, sizeof(VappUcEntryStruct));
        ucEntry->info_type = SRV_UC_INFO_TYPE_VCALENDER;
        ucEntry->operation = (viaType == VAPP_CAL_CMD_SHARE_BY_SMS) ? UC_OPERATION_SEND_VCALENDAR_AS_SMS : UC_OPERATION_SEND_VCALENDAR_AS_MMS;
        ucEntry->msg_type = (viaType == VAPP_CAL_CMD_SHARE_BY_SMS) ? SRV_UC_MSG_TYPE_SMS_ONLY : SRV_UC_MSG_TYPE_MMS_ONLY;
        ucEntry->type = SRV_UC_STATE_WRITE_NEW_MSG;
        ucEntry->auto_delete_file = TRUE;
        ucEntry->callback_para = this;
        ucEntry->media_num = 1;
        ucEntry->file_path = (U8*) path;

        vappUcAppLauncher(ucEntry);

        mmi_frm_temp_free(ucEntry);

        break;

#endif

#ifdef __MMI_EMAIL__
    case VAPP_CAL_CMD_SHARE_BY_EMAIL:
        mmi_email_app_send_attch_ext((const VfxChar*)path, (MMI_BOOL)VFX_TRUE);
    
        break;
#endif

#ifdef __MMI_OPP_SUPPORT__
    case  VAPP_CAL_CMD_SHARE_BY_BLUETOOTH:
    {
        vapp_bt_send_app_info param;
        memset(&param, 0, sizeof(vapp_bt_send_app_info));
        param.group_id = getMainScr()->getGroupId();
        VfxWChar* temp = path;
        vapp_bt_send_obj(&param, VAPP_BT_SEND_DELETE_FILE, 1, &temp);
        break;
    
    }

#endif

    default:
        break;
    }
}
#endif


#ifndef __MMI_CAL_SLIM__
void VappCalViewDetailPage::check(srv_tdl_op_evt_struct *op_evt)
{
    if ((op_evt->store_idx== m_index) &&
    (op_evt->vcal_type== SRV_TDL_VCAL_TASK) &&
    (op_evt->op_type == SRV_TDL_OP_UPDATE))
    {
        onUpdate();
        checkUpdate();
    }
    if ((op_evt->store_idx== m_index) &&
    (op_evt->vcal_type== SRV_TDL_VCAL_TASK) &&
    (op_evt->op_type == SRV_TDL_OP_DELETE))

    {
        getMainScr()->closePage(getId());
    }
}

mmi_ret VappCalViewDetailPage::onEventChange(mmi_event_struct *evt)
{
    VfxObject *obj = handleToObject((VfxObjHandle)evt->user_data);
    if (obj == NULL)
    {
        return MMI_RET_OK;
    } 
    VappCalViewDetailPage *thiz = VFX_OBJ_DYNAMIC_CAST(obj, VappCalViewDetailPage);
    if (thiz == NULL)
    {
        return MMI_RET_OK;
    }

    srv_tdl_event_op_struct *op_evt = (srv_tdl_event_op_struct *)evt;

    thiz->updatepage(op_evt);
    return MMI_RET_OK;
}

void VappCalViewDetailPage::updatepage(srv_tdl_event_op_struct *op_evt)
{
    if ((op_evt->event_id == m_eventbuffer.event_id) &&
    (op_evt->source_id == m_eventbuffer.source_id))
    {
        if (op_evt->op_type == SRV_TDL_OP_UPDATE)
        {
            onUpdate();
            checkUpdate();
            
        }
        else if (op_evt->op_type == SRV_TDL_OP_DELETE)
        {
        
            getMainScr()->closePage(getId());
        }
    }
}
mmi_ret VappCalViewDetailPage::onEvent(mmi_event_struct *evt)
{
    VfxObject *obj = handleToObject((VfxObjHandle)evt->user_data);
    if (obj == NULL)
    {
        return MMI_RET_OK;
    }
    VappCalViewDetailPage *thiz = VFX_OBJ_DYNAMIC_CAST(obj, VappCalViewDetailPage);
    if (thiz == NULL)
    {
        return MMI_RET_OK;
    }

    srv_tdl_op_evt_struct *event = (srv_tdl_op_evt_struct *)evt;

    thiz->check(event);
    return MMI_RET_OK;
}
void VappCalViewDetailPage::onDataUpdated(VfxObject *sender)
{
    m_signalDataUpdated.emit(this);
    //checkUpdate();
}
#endif
#ifndef __MMI_VCALENDAR__
#pragma arm section code, rodata
#endif

