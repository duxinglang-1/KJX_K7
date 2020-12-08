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
 *  Vapp_nitz.cpp
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

#ifdef __MMI_NITZ__
#include "vapp_nitz_gprot.h"
#include "vapp_nitz.h"
#include "vapp_setting_framework_gprot.h"
#include "mmi_rp_vapp_setting_def.h"
#include "mmi_rp_srv_nmgr_def.h"
#include "vapp_worldclock_gprot.h"
#include "vcp_global_popup.h"
extern "C"
{
#include "NITZSrvGprot.h"
#include "nvram_common_defs.h"
#include "Custom_mmi_default_value.h"
#include "datetimeGprot.h"
#include "app_str.h"
extern kal_uint8 applib_dt_sec_2_mytime(kal_uint32 utc_sec, applib_time_struct *result);
}

#include "mmi_rp_vapp_fmgr_def.h"
#include "Vsrv_ncenter.h"
#include "Vsrv_notification.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
void on_popup_btn_tap(VfxId id, void *userData)
{
    VappNitzController *controller = VFX_OBJ_GET_INSTANCE(VappNitzController);
    if (id == 'USR1')
    {
        controller->confirmUpdate();
    }    
    else
    {
        controller->ignoreUpdate();
    }
}

// nitz call back to pop up confirm.
void vapp_nitz_update_cb(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
    if(intent.type == VSRV_NINTENT_TYPE_LAUNCH)
    {
    	vcp_global_popup_show_confirm_two_button_id(
            GRP_ID_ROOT,
            VCP_POPUP_TYPE_QUESTION, 
            STR_ID_VAPP_SETTING_NITZ_UPDATE_HINT,
            STR_GLOBAL_UPDATE,
            STR_GLOBAL_CANCEL,
            VCP_POPUP_BUTTON_TYPE_RECOMMEND,
            VCP_POPUP_BUTTON_TYPE_CANCEL,
            &on_popup_btn_tap,
            NULL);
    }
}

mmi_ret vapp_nitz_update_proc(mmi_event_struct* evt)
{    
    if (evt->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH)
        {
            vcp_global_popup_show_confirm_two_button_id(
                GRP_ID_ROOT,
                VCP_POPUP_TYPE_QUESTION, 
                STR_ID_VAPP_SETTING_NITZ_UPDATE_HINT,
                STR_GLOBAL_UPDATE,
                STR_GLOBAL_CANCEL,
                VCP_POPUP_BUTTON_TYPE_RECOMMEND,
                VCP_POPUP_BUTTON_TYPE_CANCEL,
                &on_popup_btn_tap,
                NULL);

            VSRV_NOTIFICATION_CLOSE_EX('NITZ',0);
            VSRV_NGROUP_CLOSE_EX('NITZ');
        }
    return MMI_RET_OK;
}

// method to handle nitz ask type, waiting for confirm
void vapp_nitz_proc()
{
    mmi_frm_nmgr_alert_struct alert_info;
   /*Clear the alert information for filling in the correct content*/
    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct)); 
    
   /*fill in the app information*/
   alert_info.app_id = VAPP_SETTING;
   alert_info.scen_id = MMI_SCENARIO_ID_DEFAULT;
   alert_info.event_type = MMI_EVENT_GENERAL_PREVIEW;
   alert_info.alert_option = MMI_FRM_NMGR_DISABLE_TONE;
  
   /*fill in the notification information*/
   alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK;    
   alert_info.behavior_mask = FORCE_STATUS_BAR; 

   /*fill in the status bar information*/
   alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
   alert_info.status_bar_para.image_type =MMI_NMGR_IMG_RES_ID;
   /*the image icon is used for text preview, can be different from popup*/    
   alert_info.status_bar_para.image.id = IMG_ID_DEFAULT_PREVIEW_ICON;
   alert_info.status_bar_para.display_string = (WCHAR *)VFX_WSTR_RES(STR_ID_VAPP_SETTING_NITZ_UPDATE_TEXT_PREVIEW).getBuf();

  /*fill in the status bar icon information*/
   alert_info.status_bar_icon_para.icon_id = STATUS_ICON_INVALID_ID;
   /*fill in the app launch callback*/
   alert_info.app_proc_para.scrn_group_proc = &vapp_nitz_update_proc;//&vapp_nitz_update_cb;
   alert_info.app_proc_para.user_data = NULL;    
   alert_info.app_proc_para.data_size = 0;
   mmi_frm_nmgr_alert(&alert_info);
    // Group header
    VsrvNGroupSingleTitle* group = NULL;
    VSRV_NGROUP_CREATE_EX(group,VsrvNGroupSingleTitle,('NITZ'));
    group->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SETTING_NITZ_UPDATE_NCENTER_MAIN));

    // Cell
    VsrvNotificationEvent *noti = NULL;
    VSRV_NOTIFICATION_CREATE_EX(noti,VsrvNotificationEvent, ((VsrvNGroup*)group, 0));
    noti->setIcon(VfxImageSrc(IMG_ID_VAPP_FMGR_DETAIL_INFO));
    noti->setMainText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_NITZ_UPDATE_NCENTER_MAIN));
    noti->setIntentCallback(&vapp_nitz_update_cb);

	VfxDateTime dateTime;
	dateTime.setCurrentTime();
	noti->setTimeStamp(dateTime);

    noti->notify();
}

extern "C"
{
mmi_ret vapp_nitz_update_hdlr(mmi_event_struct* evt)
{
    if (evt->evt_id == EVT_ID_SRV_NITZ_UPDATE_REQ)
	{
	    srv_nitz_update_req_event_struct *nitzUpdateData = (srv_nitz_update_req_event_struct*)evt;
        const srv_nitz_context_struct *data = &nitzUpdateData->nitz_data;
        VappNitzController *controller = VFX_OBJ_GET_INSTANCE(VappNitzController);
	    controller->updateReqHandler(data);
	}
    
    return MMI_RET_OK;
}

}
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
VfxResId g_nitz_setting_string[VAPP_NITZ_SETTING_OPTION_NUM] = { 
    STR_GLOBAL_OFF,
    STR_GLOBAL_ON,
    STR_ID_VAPP_SETTING_NITZ_ALWAYS_ASK};

/***************************************************************************** 
 * Class 
 *****************************************************************************/
/***************************************************************************** 
 * VappNitzController
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappNitzController);
VappNitzController::VappNitzController()
{

    srv_nitz_enable_update(getNITZSetting() == VAPP_NITZ_OFF ? MMI_FALSE : MMI_TRUE);


    memset(m_tempOperatorName, 0, sizeof(nitz_nw_name_struct) * MMI_SIM_TOTAL); 

    m_tempTimeZone = mmi_wc_get_time_zone(mmi_wc_get_home_index());
    m_tempdayLightSaving = mmi_wc_get_home_dst();
    m_updateTime = m_updateDayLightSaving = VFX_FALSE;
}

VappNitzController::~VappNitzController()
{
}

VappNitzSettingEnum VappNitzController::getNITZSetting()
{
    VfxS16 error;
    VfxU8 data;
    ReadValue(NVRAM_SETTING_AUTOUPDATE_DT_TIME, &data, DS_BYTE, &error);
    if (data >= VAPP_NITZ_SETTING_OPTION_NUM)
	{
	    data = VAPP_NITZ_OFF;
        WriteValue(NVRAM_SETTING_AUTOUPDATE_DT_TIME, &data, DS_BYTE, &error);
	}
    return (VappNitzSettingEnum)data;
}

void VappNitzController::setNITZSetting(VappNitzSettingEnum setting)
{
    VfxS16 error;
    VfxU8 data = setting;
    if (data >= VAPP_NITZ_SETTING_OPTION_NUM)
	{
	    data = VAPP_NITZ_OFF;
	}
    WriteValue(NVRAM_SETTING_AUTOUPDATE_DT_TIME, &data, DS_BYTE, &error);

    srv_nitz_enable_update(data == VAPP_NITZ_OFF ? MMI_FALSE : MMI_TRUE);   

    m_signalSettingUpdate.emit();
}

void VappNitzController::confirmUpdate()
{
    updateSystemData();
}

void VappNitzController::ignoreUpdate()
{

    srv_nitz_update_callback(SRV_NITZ_UPDATE_REJECT);
}

VfxBool VappNitzController::checkTimeZone(void)
{
    if (m_updateTime || m_updateLocalTimeZone)
    {
        VfxS16 timezone = (VfxS16)(mmi_wc_get_time_zone(mmi_wc_get_home_index()) * 4);
        // If the time zone or day light saving setting is different
        if ((timezone + (m_tempdayLightSaving * 4)) != (VfxS16)(m_tempTimeZone*4) || m_tempdayLightSaving != mmi_wc_get_home_dst())
        {
            return VFX_TRUE;
        }
    }
    else if(m_updateDayLightSaving 
        || ( m_tempdayLightSaving != mmi_wc_get_home_dst() 
            && (m_updateTime == VFX_TRUE || mmi_dt_is_valid(&m_tempTime))))
    {               
        return VFX_TRUE;
    }
    return VFX_FALSE;
}


void VappNitzController::saveTempData(const srv_nitz_context_struct *data)
{
    m_tempTime = data->nitz_time;
    m_tempRecvTick = data->recv_tick_count;
    #ifdef __MMI_NITZ_TZ_SUPPORT__    
    m_updateTime = data->update_time;
    m_updateLocalTimeZone = data->update_local_time_zone;
    if (m_updateTime || m_updateLocalTimeZone)
	{
        m_tempTimeZone = ((FLOAT)data->nitz_timezone) / 4;
	}
    m_updateDayLightSaving = data->update_day_light_saving;
    m_tempdayLightSaving = 0;
    if (data->update_day_light_saving)
	{
	    m_tempdayLightSaving = data->day_light_saving;
	}
    #endif
    VfxU8 simIndex = mmi_frm_sim_to_index(data->sim_id);

    // Save operator name temp data
    memset(&m_tempOperatorName[simIndex], 0x00, sizeof(nitz_nw_name_struct));

    if (strlen((CHAR*) data->operator_short_name) != 0)
    {
        memcpy(&(m_tempOperatorName[simIndex].name), &data->operator_short_name, MAX_NW_LEN * ENCODING_LENGTH);
        m_tempOperatorName[simIndex].add_ci = (U8) data->add_ci;

		memcpy(&m_tempOperatorName[simIndex].plmn, data->nitz_plmn, MAX_PLMN_LEN);	

        //mmi_nitz_write_nw_name_to_nvram(data->sim_id, &nwk_name);
    }
    else if (strlen((CHAR*)data->operator_full_name) != 0)
    {
        memcpy(&(m_tempOperatorName[simIndex].name), &data->operator_full_name, MAX_NW_LEN * ENCODING_LENGTH);
        m_tempOperatorName[simIndex].add_ci = (U8) data->add_ci;

		memcpy(&m_tempOperatorName[simIndex].plmn, data->nitz_plmn, MAX_PLMN_LEN);	
   
        //mmi_nitz_write_nw_name_to_nvram(g_nitz_cntx.sim_id, &nwk_name);
    }
    else
    {
        memset(&m_tempOperatorName[simIndex].plmn,0, MAX_PLMN_LEN);    
        memset(&(m_tempOperatorName[simIndex].name), 0, MAX_NW_LEN * ENCODING_LENGTH);
        m_tempOperatorName[simIndex].add_ci = 0;
        //mmi_nitz_write_nw_name_to_nvram(g_nitz_cntx.sim_id, &nwk_name);        
    }
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[NITZ] saveTempData() time %d/%d/%d %d:%d", m_tempTime.nYear, m_tempTime.nMonth, m_tempTime.nDay, m_tempTime.nHour, m_tempTime.nMin);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[NITZ] saveTempData() timezone %d day light saving %d", m_tempTimeZone, m_tempdayLightSaving);
}

void VappNitzController::updateSystemData()
{
    // Update Time
    if (mmi_dt_is_valid(&m_tempTime))
    {
        VfxU32 currentTick = 0;
        kal_get_time(&currentTick);
        
        //MMI_TRACE(MMI_COMMON_TRC_G2_ORG, MMI_NITZ_TRACE_002, tick_count_2);
        VfxU32 seconds = 0;
        if (currentTick >= m_tempRecvTick)
        {
            seconds = kal_ticks_to_secs(currentTick - m_tempRecvTick);
        }
        else
        {
            seconds = kal_ticks_to_secs(0xFFFF - (m_tempRecvTick - currentTick));
        }

        MYTIME incTime;
        applib_dt_sec_2_mytime(seconds, (applib_time_struct*)&incTime);
        
        IncrementTime(m_tempTime, incTime, &m_tempTime);
        
#ifdef __MMI_NITZ_TZ_SUPPORT__
        /* set time zone */        
        /* If time zone is invalid, set time zone as GMT 0 */
        VfxFloat dstTimeZone = m_tempTimeZone - m_tempdayLightSaving;

        if ((VfxS16)(mmi_wc_get_time_zone(mmi_wc_get_home_index())*4) != (VfxS16)(dstTimeZone*4))
    	{
            if(mmi_wc_set_home_timezone(dstTimeZone) == MMI_FALSE)
            {
                mmi_wc_set_home_timezone(0);
            }    	
    	}
        mmi_wc_save_home_dst((VfxU8)m_tempdayLightSaving);
#endif /* __MMI_NITZ_TZ_SUPPORT__ */ 
        
        mmi_dt_set_rtc_dt(&m_tempTime);
    }
#ifdef __MMI_NITZ_TZ_SUPPORT__
    else if (checkTimeZone())
    {
        MYTIME currentTime;
        DTGetRTCTime(&currentTime);
        FLOAT diff_tz = 0;

        if (m_updateLocalTimeZone)
        {
            diff_tz = m_tempTimeZone - m_tempdayLightSaving - mmi_wc_get_time_zone(mmi_wc_get_home_index());
        }
        
        /* turn DST off */
        if (mmi_wc_get_home_dst() == MMI_TRUE && m_tempdayLightSaving == 0)
        {
            diff_tz -= 1;
        }
        else if (mmi_wc_get_home_dst() == MMI_FALSE && m_tempdayLightSaving == 1)
        {
            diff_tz += 1;
        }   

        MYTIME resultTime;
        applib_dt_utc_to_rtc(diff_tz, (applib_time_struct*) & currentTime, (applib_time_struct*) &resultTime);
        memcpy(&m_tempTime, &resultTime, sizeof(MYTIME));
        
        /* set time zone */
       
        /* If time zone is invalid, set time zone as GMT 0 */
        VfxFloat timeZone = m_tempTimeZone - m_tempdayLightSaving;
        
        if ((VfxS16)(mmi_wc_get_time_zone(mmi_wc_get_home_index())*4) != (VfxS16)(timeZone*4))
    	{
            if(mmi_wc_set_home_timezone(timeZone) == MMI_FALSE)
            {
                mmi_wc_set_home_timezone(0);
            }    	
    	}
        mmi_wc_save_home_dst((VfxU8)m_tempdayLightSaving);
        
        /* Comment it out */
        mmi_dt_set_rtc_dt(&m_tempTime);
        
    }
#endif /* __MMI_NITZ_TZ_SUPPORT__ */ 

//  Update Operator name
    VfxU8 i;
    for (i = 0; i < MMI_SIM_TOTAL; i++)
	{
        if (app_ucs2_strlen((const kal_int8*)m_tempOperatorName[i].name) != 0)
        {
            srv_nitz_set_current_nw_name(mmi_frm_index_to_sim(i), &m_tempOperatorName[i]);
        }
	}
    
    m_signalSettingUpdate.emit();
    // Notify service
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[NITZ] updateSystemData()");
    srv_nitz_update_callback(SRV_NITZ_UPDATE_DONE);
}

void VappNitzController::updateReqHandler(const srv_nitz_context_struct *data)
{
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[NITZ] updateReqHandler getNITZSetting() %d", getNITZSetting());
    switch (getNITZSetting())
	{
	case VAPP_NITZ_OFF:
        srv_nitz_enable_update(MMI_FALSE);
        break;
    case VAPP_NITZ_ON:
        // Update directly
        saveTempData(data);
        updateSystemData();        
        break;
    case VAPP_NITZ_ALWAYS_ASK:
    {
        // Wait for confirm
        saveTempData(data);
        vapp_nitz_proc();
        break;        
    }
    default:
        break;
	}
}

/***************************************************************************** 
 * VappNitzLaunchCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappNitzLaunchCell", VappNitzLaunchCell, VcpFormItemLauncherCell);
void VappNitzLaunchCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    VappNitzController *controller = VFX_OBJ_GET_INSTANCE(VappNitzController);

    m_nitzSetting = controller->getNITZSetting();

    setMainText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_NITZ));
    setHintText(getHint());
    setAccessory(VCPFORM_NEXT_ITEM_ICON);

    m_signalTap.connect(this, &VappNitzLaunchCell::onTap);
}

void VappNitzLaunchCell::onTap(VcpFormItemCell* sender, VfxId senderId)
{
    VappNitzSettingPage *page;
    VfxMainScr *mainScr = (VfxMainScr*)((VfxPage*)getParent())->findScreen();
    VFX_OBJ_CREATE(page, VappNitzSettingPage, mainScr);
    page->setHighlightItem((VfxU8)m_nitzSetting);
    page->m_signalUpdate.connect(this, &VappNitzLaunchCell::updateNitzSetting);
    mainScr->pushPage(0, page);
}

VfxWString VappNitzLaunchCell::getHint()
{
    return VFX_WSTR_RES(g_nitz_setting_string[m_nitzSetting]);
}

void VappNitzLaunchCell::updateNitzSetting(VfxU8 setting)
{
    VappNitzController *controller = VFX_OBJ_GET_INSTANCE(VappNitzController);

    controller->setNITZSetting((VappNitzSettingEnum)setting);
    m_nitzSetting = controller->getNITZSetting();;
    setHintText(getHint());
}

/***************************************************************************** 
 * VappNitzSettingPage
 *****************************************************************************/
void VappNitzSettingPage::onInit()
{
    VfxPage::onInit();
    
	VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);

    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_listMenu->setContentProvider(this);

	m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_TRUE);
    
	m_listMenu->setRect(0, 0, LCD_WIDTH, LCD_HEIGHT);		 
    m_listMenu->m_signalItemTapped.connect(this, &VappNitzSettingPage::onSelectItem);  

    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SETTING_NITZ));
    setTopBar(titleBar);
}


VfxBool VappNitzSettingPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
	if (index < (VfxU32)getCount())
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)	
		{
		   text = VFX_WSTR_RES(g_nitz_setting_string[index]);
		   color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		   return VFX_TRUE;
		}
	}
	return VFX_FALSE;
}

void VappNitzSettingPage::onSelectItem(VcpListMenu *listMenu, VfxU32 selectIdx)
{
    m_selectItem = selectIdx;
    if (m_selectItem != m_highlightItem)
	{
        m_signalUpdate.emit(selectIdx);
	}
    getMainScr()->popPage();
}    

/***************************************************************************** 
 * VappNitzNCenterEventCell
 *****************************************************************************/
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
#endif
#endif /* __MMI_NITZ__ */
