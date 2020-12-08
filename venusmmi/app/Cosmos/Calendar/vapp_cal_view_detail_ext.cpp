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
 *  vapp_cal_view_detail_ext.cpp
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  implementation view detail event/task fomr external APP 
 *  such as SMS/MMS/FMGR/EMAIL/BT
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "app_datetime.h"
#include "custom_mmi_default_value.h"
#include "fs_func.h"
#include "conversions.h"

#include "FileMgrSrvGprot.h"
#include "vcalsrvgprot.h"
#include "GeneralSettingSrvGprot.h"
#include "globalresdef.h"
}

#include "mmi_rp_vapp_calendar_def.h"

#include "vfx_system.h"
#include "vcp_global_popup.h"
#include "vcp_text_view.h"

#include "vapp_nmgr_gprot.h"
#include "vapp_cal_view_detail_ext_gprot.h"
#include "vapp_sms_provider.h"

#include "vapp_cal_edit.h"
#include "vapp_cal_utility.h"
#include "vapp_cal_view_detail.h"
#include "vapp_cal_view_detail_ext.h"
#ifdef __MMI_VCALENDAR__



/**************************IMPLEMENTATION****************************************/
/********************************************************************************/

VAPP_CAL_REMINDER_ENUM VappCalViewDetailFromExtPage::computeReminderType(void *data, srv_tdl_vcal_enum vcalType)
{
    //if can not convert to a proper reminder type, change the value to VAPP_CAL_REMINDER_NEVER.

    srv_tdl_alarm_struct *alarm;
    MYTIME *startTime;
    applib_time_struct difference;
    applib_time_struct diffBase;
    VAPP_CAL_CATEGORY_ENUM category = VAPP_CAL_CATEGORY_PERSONAL;
    
    if (vcalType == SRV_TDL_VCAL_EVENT)
    {
        srv_tdl_event_struct *event = (srv_tdl_event_struct *)data;
        alarm = &(event->alarm);
        startTime = &(event->start_time);
        category = VappCalEditPage::convertCategoryStoM((srv_vcal_category_type_enum)(event->category));
    }
    else
    {
        srv_tdl_task_struct *task = (srv_tdl_task_struct *)data;
        alarm = &(task->alarm);
        startTime = &(task->due_time);
    }

    memset(&difference, 0, sizeof(applib_time_struct));
    applib_get_time_difference(
                        (applib_time_struct*)startTime,
                        (applib_time_struct*)&(alarm->first_launch),
                        (applib_time_struct*)&difference);

    difference.DayIndex = 0;
    memset(&diffBase, 0, sizeof(applib_time_struct));
    diffBase.nMin = 5;
    if(memcmp(&diffBase, &difference, sizeof(applib_time_struct)) == 0)
    {
        return VAPP_CAL_REMINDER_5MINS_EARLIER;
    }

    diffBase.nMin = 15;
    if(memcmp(&diffBase, &difference, sizeof(applib_time_struct)) == 0)
    {
        return VAPP_CAL_REMINDER_15MINS_EARLIER;
    }

    diffBase.nMin = 30;
    if(memcmp(&diffBase, &difference, sizeof(applib_time_struct)) == 0)
    {
        return VAPP_CAL_REMINDER_30MINS_EARLIER;
    }

    diffBase.nMin = 0;
    diffBase.nHour = 1;
    if(memcmp(&diffBase, &difference, sizeof(applib_time_struct)) == 0)
    {
        return VAPP_CAL_REMINDER_1HOUR_EARLIER;
    }

    if (vcalType == SRV_TDL_VCAL_EVENT && 
        (category == VAPP_CAL_CATEGORY_SPECIALDAY || category == VAPP_CAL_CATEGORY_BIRTHDAY))
    {
        diffBase.nHour = 15;
        diffBase.nDay = 0;	
    }
    else
    {
        diffBase.nHour = 0;
        diffBase.nDay = 1;	
    }
    if(memcmp(&diffBase, &difference, sizeof(applib_time_struct)) == 0)
    {
        return VAPP_CAL_REMINDER_1DAY_EARLIER;
    }

    if (vcalType == SRV_TDL_VCAL_EVENT && 
        (category == VAPP_CAL_CATEGORY_SPECIALDAY || category == VAPP_CAL_CATEGORY_BIRTHDAY))
    {
        diffBase.nHour = 15;
        diffBase.nDay = 2;	
    }
    else
    {
        diffBase.nHour = 0;
        diffBase.nDay = 3;	
    }
    if(memcmp(&diffBase, &difference, sizeof(applib_time_struct)) == 0)
    {
        return VAPP_CAL_REMINDER_3DAYS_EARLIER;
    }

    if (vcalType == SRV_TDL_VCAL_EVENT && 
        (category == VAPP_CAL_CATEGORY_SPECIALDAY || category == VAPP_CAL_CATEGORY_BIRTHDAY))
    {
        diffBase.nHour = 15;
        diffBase.nDay = 6;	
    }
    else
    {
        diffBase.nHour = 0;
        diffBase.nDay = 7;	
    }
    if(memcmp(&diffBase, &difference, sizeof(applib_time_struct)) == 0)
    {
        return VAPP_CAL_REMINDER_1WEEK_EARLIER;
    }


    //other case , we do not support.
    return VAPP_CAL_REMINDER_NEVER;
}


void VappCalViewDetailFromExtPage::getEventAlarmTime(const srv_tdl_event_struct *event, MYTIME *almTime)
{
    if (event == NULL)
    {
        return;
    }

    VAPP_CAL_CATEGORY_ENUM category;
    category = VappCalEditPage::convertCategoryStoM((srv_vcal_category_type_enum)(event->category));

    *almTime = event->alarm.first_launch;
    if (category == VAPP_CAL_CATEGORY_SPECIALDAY ||
    category == VAPP_CAL_CATEGORY_BIRTHDAY)
    {
        // clear the default 9 hours for alarm time.
        almTime->nHour = 0;
    }
}


void VappCalViewDetailFromExtPage::adjustCategory(srv_tdl_event_struct *event)
{
    // adjust category to MMI supported range.


    switch (event->category)
    {
        case SRV_VCAL_CATEGORY_TYPE_REMINDER:
        case SRV_VCAL_CATEGORY_TYPE_MEETING:
        case SRV_VCAL_CATEGORY_TYPE_DATE:
        case SRV_VCAL_CATEGORY_TYPE_ANNIVERSARY:
        case SRV_VCAL_CATEGORY_TYPE_BIRTHDAY:
             // supported value, no need to adjust.
             return;
             
        default:
            break;
    }

    //if can not supported, should use this value
    event->category = SRV_VCAL_CATEGORY_TYPE_REMINDER;

}


void VappCalViewDetailFromExtPage::adjustDataValidation(void *data, srv_tdl_vcal_enum vcalType)
{
    // For event:
    // adjust category to MMI supported range.
    // if category is birthday or sepcial day: 1. should set end date to be equal to start date, time should be 00:00 23:59
    //                                         2. should set repeat to SRV_TDL_RULE_YEARLY.
    // all Day: if 00~23:59, all Day should be set TURE
    // repeat rule : if rule is SRV_TDL_RULE_DAYS , check Monday to Friday,if not all masked, should change value to SRV_TDL_RULE_ONCE because not support.
    // reminder type: compare the reminder datetime, map it to supported reminder type value, ex. 15 mins ealier.
    //                if can not support, change the value to VAPP_CAL_REMINDER_NEVER.
    // check reminder validation, if invalid, change valut to VAPP_CAL_REMINDER_NEVER.


    // For task:
    // change repeat to Never, because not support this field on UE.
    // reminder type:  the same as above.
    // reminder validation: the same as above.

    if (vcalType == SRV_TDL_VCAL_EVENT)
    {
        srv_tdl_event_struct *event = (srv_tdl_event_struct *)data;

        adjustCategory(event);

        VAPP_CAL_CATEGORY_ENUM categoryUI = 
            VappCalEditPage::convertCategoryStoM((srv_vcal_category_type_enum)event->category);
        
        if (categoryUI == VAPP_CAL_CATEGORY_BIRTHDAY ||
            categoryUI == VAPP_CAL_CATEGORY_SPECIALDAY)
        {
            event->start_time.nHour = 0;
            event->start_time.nMin = 0;
            event->start_time.nSec = 0;
            memcpy(&(event->end_time), &(event->start_time), sizeof(MYTIME));
            event->end_time.nHour = 23;
            event->end_time.nMin = 59;

            memset(&(event->repeat), 0, sizeof(srv_tdl_repeat_struct));
            event->repeat.rule = SRV_TDL_RULE_YEARLY;
        }

        if (event->start_time.nHour == 0 && 
            event->start_time.nMin == 0 &&
            event->end_time.nHour == 23 &&
            event->end_time.nMin == 59)
        {
            event->all_day = VFX_TRUE;
        }

        // Check rrule.
        if (event->repeat.rule == SRV_TDL_RULE_DAYS)
        {
            VfxU8 index;

            for (index = 1; index <= 5; index++)
            {
                if (!(event->repeat.dows & GetWeekDayMASK(index)))
                {
                    memset(&(event->repeat), 0, sizeof(srv_tdl_repeat_struct));
                    event->repeat.rule = SRV_TDL_RULE_ONCE; 
                    break;
                }
            }
        }
        
        if (VappCalEditPage::durationIsMoreThan1Day(&(event->start_time), &(event->end_time)))
        {
            event->repeat.rule = SRV_TDL_RULE_ONCE;
        }

        event->alarm.type = computeReminderType(event, vcalType);
        if (event->alarm.type == VAPP_CAL_REMINDER_NEVER)
        {
            memset(&(event->alarm.first_launch), 0, sizeof(MYTIME));
        }
        
        if (!(VappCalEditPage::checkreminderValidation(data, vcalType, (VAPP_CAL_REMINDER_ENUM)(event->alarm.type))))
        {
            event->alarm.type = VAPP_CAL_REMINDER_NEVER;
            memset(&(event->alarm.first_launch), 0, sizeof(MYTIME));
        }
        
    }
    else
    {
        srv_tdl_task_struct *task = (srv_tdl_task_struct *)data;
        memset(&(task->repeat), 0, sizeof(srv_tdl_repeat_struct));
        task->repeat.rule = SRV_TDL_RULE_ONCE;
        
        task->alarm.type = (VfxU8)computeReminderType(data, vcalType);
        if (task->alarm.type == VAPP_CAL_REMINDER_NEVER)
        {
            memset(&(task->alarm.first_launch), 0, sizeof(MYTIME));
        }
        
        if (!(VappCalEditPage::checkreminderValidation(data, vcalType, (VAPP_CAL_REMINDER_ENUM)(task->alarm.type))))
        {
            task->alarm.type = VAPP_CAL_REMINDER_NEVER;
            memset(&(task->alarm.first_launch), 0, sizeof(MYTIME));
        }
    }
    

}




void VappCalViewDetailFromExtPage::onDeinit()
{
    if(m_data)
    {
        VFX_FREE_MEM(m_data);
    }

    if (m_multiViewString)
    {
        VFX_FREE_MEM(m_multiViewString);
    }

    VfxPage::onDeinit();
}

void VappCalViewDetailFromExtPage::displayErrorPopup(void)
{
    VcpConfirmPopup *popup;

    VFX_OBJ_CREATE(popup, VcpConfirmPopup, this);
    popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
    popup->setText(VFX_WSTR_RES(STR_ID_VAPP_CAL_UNSUPPORT_FORMAT));
    popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    popup->setAutoDestory(VFX_TRUE);
    popup->show(VFX_TRUE);
    popup->m_signalButtonClicked.connect(this, &VappCalViewDetailFromExtPage::onPopupClicked);
}

void VappCalViewDetailFromExtPage::onPopupClicked(VfxObject* sender, VfxId id)
{
    getMainScr()->popPage();
}

void VappCalViewDetailFromExtPage::onInit()
{
    VfxPage::onInit();  

    
    //parse data
    srv_vcal_parse_struct *handle;
    void *data;

    VfxU8 finish;
    VfxS32 result;

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);

    setTopBar(bar);


    mmi_chset_enum encode_type = (mmi_chset_enum)0;
#ifdef __MMI_SET_DEF_ENCODING_TYPE__    
    encode_type = srv_setting_get_encoding_type();
#endif
    handle = (srv_vcal_parse_struct *)srv_vcal_parse_begin(m_filePath, encode_type);
    result = srv_vcal_parse(handle, &data, (srv_vcal_type_enum*)&m_vcalType, &finish);
    if (result != SRV_VCAL_RESULT_SUCCESS)
    {
        bar->setTitleStyle(VCP_TITLE_BAR_STYLE_EMPTY);
        displayErrorPopup();
        srv_vcal_parse_free_object(handle, data);
        srv_vcal_parse_end(handle);
        return;

    }


    if (m_vcalType == SRV_VCAL_VEVENT)
    {
        VFX_ALLOC_MEM(m_data, sizeof(srv_tdl_event_struct), this);
        memcpy(m_data, data, sizeof(srv_tdl_event_struct));

        srv_tdl_event_struct *evt = (srv_tdl_event_struct*)m_data;

        if (vfx_sys_wcslen((const VfxWChar *)evt->subject) == 0)
        {
            VfxWString strEmpty = VFX_WSTR_RES(STR_ID_VAPP_CAL_NO_CONTENT);

            vfx_sys_wcscpy((VfxWChar *)evt->subject, strEmpty.getBuf());
        }
        bar->setTitle(VFX_WSTR_STATIC((VfxWChar*)((srv_tdl_event_struct*)m_data)->subject));
    }
    else if (m_vcalType == SRV_VCAL_VTODO)
    {
        VFX_ALLOC_MEM(m_data, sizeof(srv_tdl_task_struct), this);
        memcpy(m_data, data, sizeof(srv_tdl_task_struct));

        srv_tdl_task_struct *task = (srv_tdl_task_struct*)m_data;
        if (vfx_sys_wcslen((const VfxWChar *)task->subject) == 0)
        {
            VfxWString strEmpty = VFX_WSTR_RES(STR_ID_VAPP_CAL_NO_CONTENT);

            vfx_sys_wcscpy((VfxWChar *)task->subject, strEmpty.getBuf());
        }

        bar->setTitle(VFX_WSTR_STATIC((VfxWChar*)((srv_tdl_task_struct*)m_data)->subject));
    }
    else
    {        
        srv_vcal_parse_free_object(handle, data);
        srv_vcal_parse_end(handle);
        bar->setTitleStyle(VCP_TITLE_BAR_STYLE_EMPTY);
        displayErrorPopup();
        
        return;
        
    }
    srv_vcal_parse_free_object(handle, data);
    srv_vcal_parse_end(handle);

    adjustDataValidation(m_data, m_vcalType);
   
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


    m_multiViewString[0] = 0;
    m_multilineView->setText(m_multiViewString, VFX_TRUE);

    if (m_vcalType == SRV_TDL_VCAL_EVENT)
    {
        initEventView();
    }
    
#ifdef __MMI_TASK_APP__
    else
    {
        initTaskView();
    }
#endif

    VcpToolBar *toolBar;
    
    VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
    VfxWString strSave;
    strSave = (m_vcalType == SRV_TDL_VCAL_EVENT ?
                    VFX_WSTR_RES(STR_ID_VAPP_CAL_SAVE_TO_CAL) : VFX_WSTR_RES(STR_ID_VAPP_CAL_SAVE_TO_TASK));
    toolBar->addItem(VAPP_CAL_VIEW_DETAIL_EXT_TB_SAVE, strSave, VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    toolBar->addItem(VAPP_CAL_VIEW_DETAIL_EXT_TB_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);

    if (m_appType == VAPP_CAL_VIEW_DETAIL_EXT_FROM_MESSAGE)
    {
        // It is not neccessary to support this function
        // toolBar->addItem(VAPP_CAL_VIEW_DETAIL_EXT_TB_SAVEASFILE, VFX_WSTR_RES(STR_ID_VAPP_CAL_SAVE_AS_FILE), IMG_ID_VAPP_CAL_SAVE_AS_FILE);
    }
    toolBar->m_signalButtonTap.connect(this, &VappCalViewDetailFromExtPage::onTBClick);
    setBottomBar(toolBar);
}


void VappCalViewDetailFromExtPage::initEventView()
{
    srv_tdl_event_struct *event = (srv_tdl_event_struct*)m_data;


    VfxWString str;
  
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
        str = dt.getDateTimeString(VFX_DATE_TIME_DATE_MASK);
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

}

#ifdef __MMI_TASK_APP__
void VappCalViewDetailFromExtPage::initTaskView()
{
    srv_tdl_task_struct *task = (srv_tdl_task_struct*)m_data;

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
void VappCalViewDetailFromExtPage::onTBClick(VfxObject* sender, VfxId id)
{
    switch(id)
    {
        case VAPP_CAL_VIEW_DETAIL_EXT_TB_SAVE:
        {
            VfxU16 index;
            VfxU32 eventIndex;
            VfxBool isMemoryFull = VFX_FALSE;
            if(m_vcalType == SRV_TDL_VCAL_EVENT)
            {
                if(srv_tdl_event_add((srv_tdl_event_struct*)m_data,SRV_TDL_EVENT_SOURCE_LOCAL,&eventIndex) == SRV_TDL_RESULT_ADD_NOT_ENOUGH_MEMORY)
                {
                    isMemoryFull = VFX_TRUE;
                }
            }
            else
            {
                if (srv_tdl_add(m_data, m_vcalType, &index) == SRV_TDL_RESULT_ADD_NOT_ENOUGH_MEMORY)
                {
                    isMemoryFull = VFX_TRUE;
                }
            }

            if (isMemoryFull)
            {
                vapp_nmgr_global_popup_show_confirm_one_button_id(
                                                        MMI_SCENARIO_ID_DEFAULT,
                                                        VCP_POPUP_TYPE_FAILURE, 
                                                        STR_ID_VAPP_CAL_MEM_FULL, 
                                                        STR_GLOBAL_OK, 
                                                        VCP_POPUP_BUTTON_TYPE_NORMAL, 
                                                        NULL, 
                                                        NULL);
            }
            else
            {   
                getMainScr()->popPage();

                VfxResId resId = (m_vcalType == SRV_TDL_VCAL_EVENT) ? STR_ID_VAPP_CAL_EVT_SAVED : STR_ID_VAPP_CAL_TASK_SAVED;
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
                MMI_EVENT_INFO_BALLOON, 
                MMI_NMGR_BALLOON_TYPE_SUCCESS, 
                VFX_WSTR_RES(resId));
            }
        }
            break;
        
        case VAPP_CAL_VIEW_DETAIL_EXT_TB_CANCEL:
            getMainScr()->popPage();
            break;
        
        default:
            break;
    } 

}

void VappCalViewDetailFromExtPage::onQueryRotateEx( VfxScreenRotateParam &param)
{

}

/***************************************************************************** 
 * Class VappCalViewDetailScreen
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappCalViewDetailApp", VappCalViewDetailApp, VfxApp);
void VappCalViewDetailApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    // create and display main screen
    VfxMainScrEx *scr;
    VFX_OBJ_CREATE_EX(scr, VfxMainScrEx, this, (this));
    VFX_ALLOC_MEM(m_filePath, VAPP_CAL_MAX_FILE_PATH_SIZE,this);
    memcpy(m_filePath, ((vapp_cal_view_detail_struct*)args)->filePath, VAPP_CAL_MAX_FILE_PATH_SIZE);
    m_appType = ((vapp_cal_view_detail_struct*)args)->appType;
    scr->show();
}

void VappCalViewDetailApp::onScr1stReady(VfxMainScrEx *scr)
{
    VappCalViewDetailFromExtPage *mainPage;

    VFX_OBJ_CREATE_EX(mainPage, VappCalViewDetailFromExtPage, scr, (m_appType, m_filePath));

    scr->pushPage(0, mainPage);
}

void VappCalViewDetailApp::onDeinit()
{
    if (m_filePath)
    {
        VFX_FREE_MEM(m_filePath);
    }

    VfxApp::onDeinit();
}


void vapp_cal_view_detail_from_FMGR_launch(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{

    vapp_cal_view_detail_struct param; 

    mmi_wcsncpy(param.filePath, filepath, SRV_FMGR_PATH_MAX_LEN);

    param.appType = VAPP_CAL_VIEW_DETAIL_EXT_FROM_FMGR;

    VfxAppLauncher::launch(
                    VAPP_CALENDAR,
                    VFX_OBJ_CLASS_INFO(VappCalViewDetailApp),
                    GRP_ID_ROOT,
                    &param, sizeof(vapp_cal_view_detail_struct));
}

static void vapp_cal_file_error_display(VfxS32 errCode)
{
    vapp_nmgr_global_popup_show_confirm_one_button_id(
                                        MMI_SCENARIO_ID_DEFAULT,
                                        VCP_POPUP_TYPE_FAILURE, 
                                        srv_fmgr_fs_error_get_string(errCode), 
                                        STR_GLOBAL_OK, 
                                        VCP_POPUP_BUTTON_TYPE_NORMAL, 
                                        NULL, 
                                        NULL);
}
static void vapp_cal_unsupportfile_error_display()
{
    vapp_nmgr_global_popup_show_confirm_one_button_id(
                                        MMI_SCENARIO_ID_DEFAULT,
                                        VCP_POPUP_TYPE_FAILURE, 
                                        STR_ID_VAPP_CAL_UNSUPPORT_FORMAT, 
                                        STR_GLOBAL_OK, 
                                        VCP_POPUP_BUTTON_TYPE_NORMAL, 
                                        NULL, 
                                        NULL);



}

void vapp_cal_view_detail_from_message_launch(VfxChar *dataBuf, VfxU32 buf_size)
{
   
    if ((dataBuf == NULL)||(buf_size == 0))
    {
        vapp_cal_unsupportfile_error_display();
        return;

    }

    // Wrtie object to tempoary file, vcalendar service  conly support parsing files.

    FS_HANDLE fh;
    VfxU32 wLen;
    VfxWChar *filePath;
    VfxS32 result;

    VFX_SYS_ALLOC_MEM(filePath, VAPP_CAL_MAX_FILE_PATH_SIZE);
    kal_wsprintf(filePath, "%c:\\%s\\", VAPP_CAL_TEMP_DRV, VAPP_CAL_TEMP_FOLDER_PATH);

    // create folder
    result = VappCalUtility::createFolderIfNotExist(filePath);

    if (result != FS_NO_ERROR)
    {
        VFX_SYS_FREE_MEM(filePath);

        vapp_cal_file_error_display(result);

        return;
    }

    //create file
    mmi_ucs2cat((VfxChar*)filePath, (const VfxChar*)VAPP_CAL_TEMP_FILE_NAME);
    FS_Delete(filePath); //delete the last file
    
    fh = FS_Open(filePath, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (fh < 0)
    {
        VFX_SYS_FREE_MEM(filePath);

        vapp_cal_file_error_display(result);
        return;

    }

    FS_SetAttributes(filePath, FS_ATTR_HIDDEN);
    result = FS_Write(fh, dataBuf, buf_size, &wLen);

    // memory is not enough
    if (result != FS_NO_ERROR)
    {
        VFX_SYS_FREE_MEM(filePath);
        FS_Close(fh);

        vapp_cal_file_error_display(result);
        return;
    }

    FS_Close(fh);    

    vapp_cal_view_detail_struct param;

    mmi_wcsncpy(param.filePath, filePath, SRV_FMGR_PATH_MAX_LEN);

    param.appType = VAPP_CAL_VIEW_DETAIL_EXT_FROM_MESSAGE;

    VfxAppLauncher::launch(
                    VAPP_CALENDAR,
                    VFX_OBJ_CLASS_INFO(VappCalViewDetailApp),
                    GRP_ID_ROOT,
                    &param, sizeof(vapp_cal_view_detail_struct));

    VFX_SYS_FREE_MEM(filePath);
}


static void vapp_cal_vcal_port_reg_callback(VfxChar* data, VfxU32 dataSize, void* userData)
{
    vapp_cal_view_detail_from_message_launch(data, dataSize);
}


void vapp_vcal_view_detail_register_message(void)
{
    VfxImageSrc img(IMG_ID_VAPP_CAL_VCALENDAR);
 
    VappSmsPortReg *obj = VappSmsPortReg::getInstance();

    obj->registerPort(
        VAPP_VCAL_PORT,
        VfxWString().loadFromRes(STR_ID_VAPP_CAL_VCALENDAR),
        img,
        vapp_cal_vcal_port_reg_callback,
        NULL);
}
#endif   /*__MMI_VCALENDAR__*/
