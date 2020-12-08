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
 *  Vapp_Setting_SchedulePowerOnOff.cpp
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_schedule_power_on_off.h"
#include "mmi_rp_vapp_setting_def.h"
#include "vcp_global_popup.h"
extern "C"
{
#include "Nvram_common_defs.h"
#include "custom_mmi_default_value.h"
#include "ReminderSrvGprot.h"
#include "mmi_rp_srv_reminder_def.h"
#include "ShutdownSrvGprot.h"
#include "GeneralSettingSrvGprot.h"
#include "GlobalResDef.h"
//#include "TimerEvents.h"
#include "Mdi_audio.h" // for suspend and resume audio play when display power off confirm popup
#include "UcmSrvGprot.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_SCHEDULE_POWER_TIME_STRING_BUFFER_LENGTH (12)
#define VAPP_SCHEDULE_POWER_OFF_AUTO_SHUTDOWN_TIME (30000)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
void vapp_schedule_power_launch(VfxMainScr *mainScr)
{
    VappSchedulePowerSettingPage *settingPage;
    VFX_OBJ_CREATE(settingPage, VappSchedulePowerSettingPage, mainScr);    
    mainScr->pushPage(0, settingPage);	
}
extern "C"
{
mmi_ret vapp_schedule_power_reminder_srv_proc(mmi_event_struct* evt)
{
    srv_reminder_evt_struct *reminder_evt = (srv_reminder_evt_struct*)evt;

    if ((reminder_evt->reminder_type != SRV_REMINDER_TYPE_SPON
        && reminder_evt->reminder_type != SRV_REMINDER_TYPE_SPOF
	&& reminder_evt->reminder_type != SRV_REMINDER_TYPE_TOTAL)
        || reminder_evt->evt_id != EVT_ID_SRV_REMINDER_NOTIFY)
	{
	    return MMI_RET_OK;
	}
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[SPOF] PROC() notify %d reminder_type %d", reminder_evt->notify, reminder_evt->reminder_type);
    VappSchedulePowerController *controller = VFX_OBJ_GET_INSTANCE(VappSchedulePowerController);
    switch (reminder_evt->notify)
	{
    case SRV_REMINDER_NOTIFY_INIT:
        controller->initSchedulePower();
        break;
        
    case SRV_REMINDER_NOTIFY_EXPIRY:
        controller->scheduleExpired(reminder_evt->usr_data, reminder_evt->pwr_off);
        break;

    case SRV_REMINDER_NOTIFY_REINIT:
        controller->scheduleReinit();
        break;
        
    case SRV_REMINDER_NOTIFY_DEINIT:
        controller->scheduleDeinit();
		break;
	default:
		break;
	}
    return MMI_RET_OK;
}

static mmi_ret shutProc(mmi_event_struct *evt)
{
    srv_shutdown_normal_start(VAPP_SETTING);
    return MMI_RET_OK;
}

}

extern "C" void srv_reminder_util_send_pwron(void);
/***************************************************************************** 
 * Class 
 *****************************************************************************/
/***************************************************************************** 
 * VappSchedulePowerController
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappSchedulePowerController);
void VappSchedulePowerController::initSchedulePower()
{
    if (m_isInit)
	{
	    return;
	}
    VfxS16 error;

    memset(&m_data, 0, sizeof(m_data));

    ReadRecord(NVRAM_EF_ALM_SPOF_DATA_LID, 1, &m_data, NVRAM_ALM_SPOF_DATA_SIZE, &error);
    VfxU8 i = 0;
    for (i = 0; i < VAPP_SCHEDULE_TOTAL_RECORD_NUM; i++)
	{
	    if (i < VAPP_SCHEDULE_ON_RECORD_NUM)
		{
    		m_data[i].Type = VAPP_SPOF_POWERON;		
		}
        else
        {
            m_data[i].Type = VAPP_SPOF_POWEROFF;		
        }
	}
    m_isInit = VFX_TRUE;
}

VappSchedulePowerErrorEnum VappSchedulePowerController::setSchedule(VfxId index, const spof_nvram_struct &data)
{
    // Check if it is conflict schedule
    if (data.Status == VAPP_SPOF_ENABLE)
	{
	    VfxU8 i;
        for (i = 0; i < VAPP_SCHEDULE_TOTAL_RECORD_NUM; i++)
    	{
    		if (index == i)
        	{
        	    continue;
        	}
            if (m_data[i].Status == VAPP_SPOF_ENABLE 
                && m_data[i].Hour == data.Hour
                && m_data[i].Min == data.Min)
        	{
        	    return VAPP_SPOF_SCHEDULE_ERROR_CONFLICT;
        	}
    	}
	}

    VfxS16 error;
    m_data[index] = data;
    WriteRecord(NVRAM_EF_ALM_SPOF_DATA_LID, 1, &m_data, NVRAM_ALM_SPOF_DATA_SIZE, &error);
    // set to reminder service
    srv_reminder_type type = SRV_REMINDER_TYPE_SPON;
    switch (m_data[index].Type)
	{
	case VAPP_SPOF_POWERON:
		type = SRV_REMINDER_TYPE_SPON;
		break;
	case VAPP_SPOF_POWEROFF:
		type = SRV_REMINDER_TYPE_SPOF;
		break;
	default:
		ASSERT(0);
	}
    
    srv_reminder_cancel(type, index);

    if (m_data[index].Status != VAPP_SPOF_ENABLE)
	{
	    return VAPP_SPOF_SCHEDULE_NO_ERROR;
	}
    
    MYTIME time;
    GetDateTime(&time);
    
    time.nMin = m_data[index].Min;
    time.nHour = m_data[index].Hour;
    time.nSec = 0;
    
    MYTIME newTime = srv_reminder_calc_time(&time, SRV_REMINDER_REPEAT_EVERYDAY, 0);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[SPOF] setSchedule type %d %d:%d:%d", type, newTime.nHour, newTime.nMin, newTime.nDay);
    srv_reminder_set(type, &newTime, index);
    return VAPP_SPOF_SCHEDULE_NO_ERROR;
}

spof_nvram_struct VappSchedulePowerController::getSchedule(VfxId index)
{
	return m_data[index];
}

void VappSchedulePowerController::updateNextTime(VfxU8 index, VfxBool pwrOn)
{
    MYTIME time;
    GetDateTime(&time);
    time.nMin = m_data[index].Min;
    time.nHour = m_data[index].Hour;
    time.nSec = 0;
    MYTIME newtime = srv_reminder_calc_time(&time, SRV_REMINDER_REPEAT_EVERYDAY, 0);
    if (pwrOn)
    {
        srv_reminder_set(SRV_REMINDER_TYPE_SPON, &newtime, index);
    }
    else
    {
        srv_reminder_set(SRV_REMINDER_TYPE_SPOF, &newtime, index);
    }
}


void VappSchedulePowerController::scheduleExpired(VfxU8 index, VfxBool powerOff)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[SPOF] scheduleExpired index %d poweroff %d", index, powerOff);
    if (m_data[index].Status != VAPP_SPOF_ENABLE)
	{
	    return;
    }
    if (powerOff)
    {
        switch (m_data[index].Type)
    	{
    	case VAPP_SPOF_POWERON:
        {    
            updateNextTime(index, VFX_TRUE);
       	    srv_reminder_util_send_pwron();        	
            // No need to call srv_reminder_notify_finish(MMI_FALSE), 
            // reminder service will be initialized at boot up
    	    break;
        }
    	case VAPP_SPOF_POWEROFF:
        {
            updateNextTime(index, VFX_FALSE);
            srv_reminder_notify_finish(MMI_FALSE);
            break;            
        }

    	default:
    		ASSERT(0);
    	}
    }
    else
    {
        switch (m_data[index].Type)
    	{
    	case VAPP_SPOF_POWERON:
        {
            updateNextTime(index, VFX_TRUE);
            srv_reminder_notify_finish(MMI_FALSE);
            break;            
        }
    	case VAPP_SPOF_POWEROFF:
            updateNextTime(index, VFX_FALSE);
            mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_SCHEDULE_POWER_OFF,
                                             MMI_EVENT_SCHEDULE_POWER_OFF,
                                             &VappSchedulePowerController::onNmgrNotified,
                                             NULL);   
       	    break;

    	default:
    		ASSERT(0);
    	}
    }
}

void VappSchedulePowerController::scheduleReinit()
{
    VfxU8 i;
    for (i = 0; i < NUM_OF_SPOF; i++)
    {
        if (m_data[i].Status == VAPP_SPOF_ENABLE)
        {
            /* save the alarm in the nvram */
            MYTIME set_time; 
            srv_reminder_type type;

            DTGetRTCTime(&set_time);
            set_time.nMin = m_data[i].Min;
            set_time.nHour = m_data[i].Hour;
            set_time.nSec = 0;
            MYTIME calc_time = srv_reminder_calc_time(&set_time, SRV_REMINDER_REPEAT_EVERYDAY, 0);
        
            if (m_data[i].Type == VAPP_SPOF_POWERON)
            {
                type = SRV_REMINDER_TYPE_SPON;
            }
            else
            {
                type = SRV_REMINDER_TYPE_SPOF;
            }
            srv_reminder_set(type, &calc_time, i);
        }
    }
}

void VappSchedulePowerController::scheduleDeinit()
{
    //vcp_global_popup_leave();
}

void VappSchedulePowerController::showSchedulePowerOffPopup()
{
    mmi_frm_start_scenario(MMI_SCENARIO_ID_SCHEDULE_POWER_OFF);

    mdi_audio_suspend_background_play();
    vcp_global_popup_show_confirm_two_button_id(
        GRP_ID_ROOT,
        VCP_POPUP_TYPE_WARNING, 
        STR_ID_VAPP_SETTING_SCHEDULE_POWER_OFF_CONFIRM,
        STR_ID_VAPP_SETTING_SCHEDULE_POWER_SHUT_DOWN_NOW,
        STR_GLOBAL_CANCEL,
        VCP_POPUP_BUTTON_TYPE_WARNING,
        VCP_POPUP_BUTTON_TYPE_CANCEL,
        &VappSchedulePowerController::onSchedulePowerOffPopupTapped,
        this);
    StopTimer(MMI_ALARM_ALERT_NOTIFYDURATION_TIMER);

    StartTimer(MMI_ALARM_ALERT_NOTIFYDURATION_TIMER, VAPP_SCHEDULE_POWER_OFF_AUTO_SHUTDOWN_TIME, &VappSchedulePowerController::schedulePowerOffAutoShutDown);
}

void VappSchedulePowerController::schedulePowerOffAutoShutDown()
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[SPOF] schedulePowerOffAutoShutDown");
    StopTimer(MMI_ALARM_ALERT_NOTIFYDURATION_TIMER);

    if (!srv_ucm_is_any_call())
    {
        //srv_shutdown_normal_start(VAPP_SETTING);
        mmi_event_struct postInvoke;
         
        MMI_FRM_INIT_EVENT(&postInvoke, 0);
        MMI_FRM_POST_EVENT(&postInvoke, shutProc, NULL);
        
        mmi_frm_end_scenario(MMI_SCENARIO_ID_SCHEDULE_POWER_OFF);
        srv_reminder_notify_finish(MMI_FALSE);
    }
    else
    {
        // Wait for the call end then restart the auto shut down timer
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[SPOF] schedulePowerOffAutoShutDown wait");
        mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, &VappSchedulePowerController::onCallEnd, NULL);
    }
}

mmi_ret VappSchedulePowerController::onCallEnd(mmi_event_struct *evt)
{
    if (evt->evt_id == EVT_ID_SRV_UCM_STATUS_CHANGE && !srv_ucm_is_any_call())
    {
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[SPOF] schedulePowerOffAutoShutDown call end");
        StartTimer(MMI_ALARM_ALERT_NOTIFYDURATION_TIMER, VAPP_SCHEDULE_POWER_OFF_AUTO_SHUTDOWN_TIME, &VappSchedulePowerController::schedulePowerOffAutoShutDown);
        mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, &VappSchedulePowerController::onCallEnd, NULL);
    }
    return MMI_RET_OK;
}

MMI_BOOL VappSchedulePowerController::onNmgrNotified(mmi_scenario_id scenarioId, void *userData)
{
    if (scenarioId == MMI_SCENARIO_ID_SCHEDULE_POWER_OFF)
	{
        VappSchedulePowerController *controller = VFX_OBJ_GET_INSTANCE(VappSchedulePowerController);
        controller->showSchedulePowerOffPopup();
	}
    return MMI_TRUE;
}

void VappSchedulePowerController::onSchedulePowerOffPopupTapped(VfxId id, void* userData)
{
    if (id == 'USR1')
	{
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[SPOF] schedulePowerOffAutoShutDown");
        
        mmi_event_struct postInvoke;
        
       MMI_FRM_INIT_EVENT(&postInvoke, 0);
       MMI_FRM_POST_EVENT(&postInvoke, shutProc, NULL);
       //srv_shutdown_normal_start(VAPP_SETTING);
	}
    else
    {
        //vcp_global_popup_leave();
        StopTimer(MMI_ALARM_ALERT_NOTIFYDURATION_TIMER);
        mdi_audio_resume_background_play();
    }
    srv_reminder_notify_finish(MMI_FALSE);
    mmi_frm_end_scenario(MMI_SCENARIO_ID_SCHEDULE_POWER_OFF);
}

/***************************************************************************** 
 * VappSchedulePowerStatusSettingCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSchedulePowerStatusSettingCell", VappSchedulePowerStatusSettingCell, VcpFormItemSwitchCell);
void VappSchedulePowerStatusSettingCell::setSchedulePowerRecordId(VfxU8 recordId)
{
    if (recordId < NUM_OF_SPOF)
	{
	    m_recordId = recordId;
        updateStatus();
        setIsTappable(VFX_FALSE);
        m_signalSwitchChangeReq.connect(this, &VappSchedulePowerStatusSettingCell::onSwitch);
	}
}

void VappSchedulePowerStatusSettingCell::onSwitch(VcpFormItemSwitchCell* sender, VfxId senderId, VfxBool status)
{
    VappSchedulePowerController *controller = VFX_OBJ_GET_INSTANCE(VappSchedulePowerController);
    spof_nvram_struct recordData = controller->getSchedule(m_recordId);
    recordData.Status = status ? VAPP_SPOF_ENABLE : VAPP_SPOF_DISABLE;
    
    if(controller->setSchedule(m_recordId, recordData) == VAPP_SPOF_SCHEDULE_NO_ERROR)
    {
        updateStatus();
    }
    else
    {
        VfxMainScr *mainScr = ((VfxPage*)getParent())->getMainScr();
        VcpConfirmPopup *popup;
        VFX_OBJ_CREATE(popup, VcpConfirmPopup, mainScr);        
        popup->setText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_SCHEDULE_POWER_CONFLICT));
        popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        //popup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        popup->show(VFX_TRUE);
    }
}

void VappSchedulePowerStatusSettingCell::updateStatus()
{
    VappSchedulePowerController *controller = VFX_OBJ_GET_INSTANCE(VappSchedulePowerController);
    spof_nvram_struct recordData = controller->getSchedule(m_recordId);
    m_status = recordData.Status;
    setSwitchStatus(m_status);
}

/***************************************************************************** 
 * VappSchedulePowerTimeSettingCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSchedulePowerTimeSettingCell", VappSchedulePowerTimeSettingCell, VcpFormItemLauncherCell);
void VappSchedulePowerTimeSettingCell::setSchedulePowerRecordId(VfxU8 recordId)
{
    if (recordId < NUM_OF_SPOF)
	{
	    m_recordId = recordId;
        updateTime();
        m_signalTap.connect(this, &VappSchedulePowerTimeSettingCell::onEntryTimeSetting);
	}
}

void VappSchedulePowerTimeSettingCell::updateTime()
{
    VappSchedulePowerController *controller = VFX_OBJ_GET_INSTANCE(VappSchedulePowerController);
    spof_nvram_struct recordData = controller->getSchedule(m_recordId);

    VfxDateTime dateTime;
    dateTime.setTime(recordData.Hour, recordData.Min, 0);

    VfxWChar buffer[VAPP_SCHEDULE_POWER_TIME_STRING_BUFFER_LENGTH] = {0};
    dateTime.getDateTimeString(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE, buffer, VAPP_SCHEDULE_POWER_TIME_STRING_BUFFER_LENGTH);  
    setHintText(VFX_WSTR_MEM(buffer));
}

void VappSchedulePowerTimeSettingCell::setTime(VfxU8 hour, VfxU8 minute)
{
    ASSERT(hour <= 24 && minute < 60);
    
    VappSchedulePowerController *controller = VFX_OBJ_GET_INSTANCE(VappSchedulePowerController);
    spof_nvram_struct recordData = controller->getSchedule(m_recordId);
    recordData.Hour = hour;
    recordData.Min = minute;

    VfxMainScr *mainScr = ((VfxPage*)getParent())->getMainScr();
    if(controller->setSchedule(m_recordId, recordData) == VAPP_SPOF_SCHEDULE_NO_ERROR)
    {
        updateTime();
        mainScr->popPage();
    }
    else
    {
        VcpConfirmPopup *popup;
        VFX_OBJ_CREATE(popup, VcpConfirmPopup, mainScr);        
        popup->setText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_SCHEDULE_POWER_CONFLICT));
        popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
        //popup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        popup->show(VFX_TRUE);
    }

}

void VappSchedulePowerTimeSettingCell::onEntryTimeSetting(VcpFormItemCell *sender, VfxId senderId)
{
    VfxMainScr *mainScr = (VfxMainScr*)((VfxPage*)getParent())->getMainScr();
    VappSchedulePowerController *controller = VFX_OBJ_GET_INSTANCE(VappSchedulePowerController);
    spof_nvram_struct recordData = controller->getSchedule(m_recordId);
    VFX_OBJ_CREATE_EX(m_settingPage, VappSchedulePowerTimeSettingPage, mainScr, ((VappSchedulePowerTypeEnum)recordData.Type, recordData.Hour, recordData.Min));
    m_settingPage->m_signalUpdateTime.connect(this, &VappSchedulePowerTimeSettingCell::setTime);
    mainScr->pushPage(0, m_settingPage);    
}


/***************************************************************************** 
 * VappSchedulePowerTimeSettingPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSchedulePowerTimeSettingPage", VappSchedulePowerTimeSettingPage, VfxPage);
void VappSchedulePowerTimeSettingPage::onInit()
{
    VfxPage::onInit();
    
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    VfxId titleId = STR_ID_VAPP_SETTING_EDIT_SCHEDULE_POWER_ON;
    switch (m_type)
	{
	case VAPP_SPOF_POWERON:
		titleId = STR_ID_VAPP_SETTING_EDIT_SCHEDULE_POWER_ON;
		break;
    case VAPP_SPOF_POWEROFF:
		titleId = STR_ID_VAPP_SETTING_EDIT_SCHEDULE_POWER_OFF;
		break;        
	default:
		break;
	}
    titleBar->setTitle(VFX_WSTR_RES(titleId));
    setTopBar(titleBar);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->addItem(0, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    m_toolBar->addItem(1, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect(this, &VappSchedulePowerTimeSettingPage::onToolBarTap);
    setBottomBar(m_toolBar);

    VfxFrame *background;
    VFX_OBJ_CREATE(background, VfxFrame, this);
    VfxSize size = this->getSize();
    VfxRect rect = this->getRect();
    background->setSize(this->getRect().getWidth(), this->getRect().getHeight());
//    background->setBgColor(VFX_COLOR_WHITE);

    VFX_OBJ_CREATE(m_timePicker, VcpTimePicker, background);
    m_timePicker->setTime(m_time);
    m_timePicker->setIs24HourView((srv_setting_get_time_format() == SETTING_TIME_FORMAT_24_HOURS ? VFX_TRUE : VFX_FALSE));
//    m_timePicker->m_signalOnTimeChanged.connect(this, &VappTimeSettingPage::updateTime);
    m_timePicker->setAnchor(0.5, 0);
    m_timePicker->setPos(LCD_WIDTH / 2, VAPP_SPOF_TIME_PICKER_TOP_MARGIN);
    m_timePicker->m_signalOnTimeChanged.connect(this, &VappSchedulePowerTimeSettingPage::updateTime);

    VfxTextFrame *textFrame;
    VFX_OBJ_CREATE(textFrame, VfxTextFrame, background);
    textFrame->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_SMALL));
    textFrame->setColor(VFX_COLOR_GREY);
    textFrame->setString(VFX_WSTR_RES(STR_ID_VAPP_SETTING_SCHEDULE_POWER_HINT));
    textFrame->setPos(m_timePicker->getRect().getX(), m_timePicker->getRect().getHeight() + VAPP_SPOF_TIME_PICKER_TOP_MARGIN);
    textFrame->setSize(m_timePicker->getRect().getWidth(), m_timePicker->getRect().getWidth());
    textFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);    
}

void VappSchedulePowerTimeSettingPage::onToolBarTap(VfxObject* sender, VfxId senderId)
{
    if (senderId == 0)
	{
        m_signalUpdateTime.emit(m_time.hour, m_time.minute);
	}
    else
    {
        getMainScr()->popPage();
    }
}

void VappSchedulePowerTimeSettingPage::updateTime(VfxObject *sender, VcpTimePickerStruct *time)
{
    m_time = *time;    
}    
/***************************************************************************** 
 * VappSchedulePowerSettingPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSchedulePowerSettingPage", VappSchedulePowerSettingPage, VfxPage);
void VappSchedulePowerSettingPage::onInit()
{
    VfxPage::onInit();
    
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SETTING_SCHEDULE_POWER_ON_OFF));
    setTopBar(m_titleBar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
	m_form->setPos(0, 0);
//	m_form->setBounds(VfxRect(0, 0, LCD_WIDTH, LCD_HEIGHT));
//	m_form->setViewRect(VfxRect(0, 0, LCD_WIDTH, LCD_HEIGHT));
    m_form->setSize(getSize());
//	m_form->setBgColor(VFX_COLOR_WHITE);
	m_form->enableVerticalScrollIndicator(VFX_TRUE);
	m_form->setBorderColor(VFX_COLOR_BLACK);        
	m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);    

    VfxId cellId = 0; // index for add item to form
    VfxU8 scheduleId = 0; // count for schedule 
    VfxU8 recordId = 0; // index for NVRAM record
    while (cellId < ((NUM_OF_SPOF * 2) + 2))
	{
    	// Set caption for schedule power on / off
	    if (cellId == 0 || cellId == ((VAPP_SCHEDULE_ON_RECORD_NUM * 2) + 1))
		{
            VcpFormItemCaption *scheduleOnCaptionCell;
            VFX_OBJ_CREATE(scheduleOnCaptionCell, VcpFormItemCaption, this);
            if (cellId == 0)
        	{
                scheduleOnCaptionCell->setText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_SCHEDULE_POWER_ON));        	
        	}
            else
            {
                scheduleOnCaptionCell->setText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_SCHEDULE_POWER_OFF));            
            }
            m_form->addItem(scheduleOnCaptionCell, cellId);		
            cellId++;
            continue;
		}
        // Set 
/*        
        VfxWString statusCellCaption;
        statusCellCaption.format("Schedule %d", (scheduleId + 1));
        VfxWString statusCellHint;
        statusCellHint.format("Enable or disable schedule %d", (scheduleId + 1));
*/        
    	VappSchedulePowerStatusSettingCell *statusCell = m_schedulePowerOnStatusCell[scheduleId];
		VFX_OBJ_CREATE(statusCell, VappSchedulePowerStatusSettingCell, this);
        statusCell->setSchedulePowerRecordId(recordId);
        statusCell->setMainText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_SCHEDULE1 + scheduleId));
//        statusCell->setHintText(statusCellHint);
        m_form->addItem(statusCell, cellId);
        cellId++;

        VappSchedulePowerTimeSettingCell *timeCell = m_schedulePowerOnTimeCell[scheduleId];
		VFX_OBJ_CREATE(timeCell, VappSchedulePowerTimeSettingCell, this);
		timeCell->setSchedulePowerRecordId(recordId);
		timeCell->setMainText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_SCHEDULE_POWER_SET_TIME));
        timeCell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        m_form->addItem(timeCell, cellId);
        cellId++;
        recordId++;
        scheduleId++;
	}
}
