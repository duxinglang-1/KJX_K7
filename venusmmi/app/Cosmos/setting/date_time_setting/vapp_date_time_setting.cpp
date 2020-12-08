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
 *  Vapp_Setting_DateTimeSetting.cpp
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
 *  
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
#include "vapp_date_time_setting.h"
#include "vapp_setting_framework_gprot.h"
#include "vapp_worldclock_gprot.h"
#include "Vcui_worldclock_select_city_gprot.h"
#include "vapp_setting_framework_gprot.h"
#include "vdat_systime.h"
#include "vapp_nitz_gprot.h"

extern "C"
{
//#include "phonesetupgprots.h"
//#include "SettingGprots.h"
#include "GeneralSettingSrvGprot.h"
#include "GlobalResDef.h"
#include "DateTimeType.h"
#include "DateTimeGprot.h"

#include "mmi_msg_struct.h"
#include "MMIDataType.h"
#include "mmi_rp_vapp_clock_def.h"
#include "ps_public_enum.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_DATE_TIME_STRING_BUFFER_LENGTH (12)
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_SETTING_ROCODE", rodata = "DYNAMIC_CODE_SETTING_RODATA" 
static VfxWString vapp_get_current_date_string(srv_setting_date_format_enum date_format, srv_setting_date_format_enum date_seperator, VfxU32 year, VfxU32 month, VfxU32 day)
{
    VfxWString seperatorString(VappDateSeperatorString[date_seperator]);
    VfxWString displayString = VFX_WSTR_EMPTY;
    switch (date_format)
	{
	case SETTING_DATE_FORMAT_DD_MM_YYYY:
        displayString.format(
            "%02d%s%02d%s%04d", 
            day, 
            seperatorString.getBuf(),
            month,
            seperatorString.getBuf(),
            year);
		break;
	case SETTING_DATE_FORMAT_MM_DD_YYYY:
        displayString.format(
            "%02d%s%02d%s%04d", 
            month, 
            seperatorString.getBuf(),
            day,
            seperatorString.getBuf(),
            year);        		
		break;
	case SETTING_DATE_FORMAT_YYYY_MM_DD:
        displayString.format(
            "%04d%s%02d%s%02d", 
            year, 
            seperatorString.getBuf(),
            month,
            seperatorString.getBuf(),
            day); 
		break;                
	default:
		ASSERT(0);
	}
    return displayString;
}
#pragma arm section code, rodata

 extern "C"
{
    #ifndef __SLIM_AT__
    VfxU8 vapp_home_city_at_handler(void *msg, VfxU32 mod_id)
    {
    #ifdef __MMI_TIMEZONE_SETTING__   
        mmi_set_mmi_default_prof_ind_struct *mmi_set_prof_struct = (mmi_set_mmi_default_prof_ind_struct*) msg;
    
        if (mmi_set_prof_struct->category == ESDP_CATEGORY_HOMECITY)
        {
            VfxU8 index = mmi_set_prof_struct->param3;
            mmi_at_general_res_req_struct *rsp;
    
            rsp = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));

            if (index > (STR_CITY_TOTAL_NUM - STR_WORLDCLOCK_CITY_NONE - 1) || index == 0)
            {
                rsp->result = KAL_FALSE;
            }
            else
            {
                VfxU16 homeIndex = (VfxU8)index-1;                
                if (homeIndex != mmi_wc_get_home_index())
                {
                    VfxS8 dstFlag = 0 - mmi_wc_get_home_dst();
                    mmi_wc_update_sys_datetime(homeIndex, dstFlag);
                    mmi_wc_save_home_city(homeIndex);
                    mmi_wc_save_home_dst(0);
                }
            #ifdef __MMI_TDL_NITZ_SUPPORT__
                srv_tdl_init();
            #endif

                rsp->result = KAL_TRUE;
            }
            
            mmi_frm_send_ilm((oslModuleType)mod_id, MSG_ID_MMI_AT_GENERAL_RES_REQ, (oslParaType*)rsp, NULL);
    
            return 1;
        }
    #endif /* __MMI_TIMEZONE_SETTING__ */

        return 0;
    }
    #endif /* __SLIM_AT__ */
    
    // reg this API in vapp_bootup_init_cfg.h, vapp_alarm_bootup_init_cfg.h, vapp_usb_bootup_init_cfg.h
    mmi_id vapp_home_city_init(mmi_event_struct *evt)
    {
        mmi_wc_save_home_city(mmi_wc_get_home_index());
    #ifndef __SLIM_AT__
        mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SET_MMI_DEFAULT_PROF_IND, (PsIntFuncPtr)vapp_home_city_at_handler, MMI_TRUE);
    #endif /*__SLIM_AT__*/
        return MMI_RET_OK;
    }
}

/***************************************************************************** 
 * Class 
 *****************************************************************************/
/***************************************************************************** 
 * VappHomeCitySettingCell
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_SETTING_ROCODE", rodata = "DYNAMIC_CODE_SETTING_RODATA" 

VFX_IMPLEMENT_CLASS("VappHomeCitySettingCell", VappHomeCitySettingCell, VcpFormItemLauncherCell);
void VappHomeCitySettingCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    setMainText(STR_ID_VAPP_SETTING_HOME_CITY);
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
    setHintText(getHint());
    m_signalTap.connect(this, &VappHomeCitySettingCell::onTap);
#ifdef __MMI_NITZ__
    VappNitzController *nitzController = VFX_OBJ_GET_INSTANCE(VappNitzController);
    nitzController->m_signalSettingUpdate.connect(this, &VappHomeCitySettingCell::updateCell);
    setIsDisabled(nitzController->getNITZSetting() == VAPP_NITZ_ON ? VFX_TRUE : VFX_FALSE);
#endif /* __MMI_NITZ__ */
}

void VappHomeCitySettingCell::updateCell() 
{
    setHintText(getHint());
#ifdef __MMI_NITZ__    
    VappNitzController *nitzController = VFX_OBJ_GET_INSTANCE(VappNitzController);
    setIsDisabled(nitzController->getNITZSetting() == VAPP_NITZ_ON ? VFX_TRUE : VFX_FALSE);
#endif /* __MMI_NITZ__ */
}

void VappHomeCitySettingCell::onTap(VcpFormItemCell* sender, VfxId senderId)
{
    cui_wc_launch_struct data;
    data.isSetHomeCity = 1;
    VappSettingFWMgr *manager = (VappSettingFWMgr*)VFX_OBJ_GET_INSTANCE(VappSettingFWMgr);
    mmi_id cuiId = vcui_wc_select_city_create(manager->getAppId(), data);
    mmi_frm_group_set_caller_proc(cuiId, &VappHomeCitySettingCell::cuiProc, this);
    vcui_wc_select_city_set_title(cuiId, VFX_WSTR_RES(STR_ID_VAPP_SETTING_HOME_CITY));
    vcui_wc_select_city_run(cuiId);
}

VfxWString VappHomeCitySettingCell::getHint()
{
    return VFX_WSTR_RES(mmi_wc_get_city_strid(mmi_wc_get_home_index()));
}

mmi_ret VappHomeCitySettingCell::cuiProc(mmi_event_struct *evt)
{
    VappHomeCitySettingCell *cell = (VappHomeCitySettingCell*)evt->user_data;
    cui_wc_event_struct *wcData = (cui_wc_event_struct*)evt;
    switch (evt->evt_id)
	{
	case EVT_ID_CUI_WC_CITY_SELECTED:
            cell->setHintText(wcData->cityName);
            break;

	default:
	    break;
	}
    vcui_wc_select_city_close(wcData->sender_id);
    return MMI_RET_OK;
}

/***************************************************************************** 
 * VappDateSettingCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappDateSettingCell", VappDateSettingCell, VcpFormItemLauncherCell);
void VappDateSettingCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    setMainText(STR_ID_VAPP_SETTING_DATE_SETTINGS);
    setHintText(getHint());
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_signalTap.connect(this, &VappDateSettingCell::onTap);

    VdatTimeNotification *sysTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    sysTimeSrv->m_signalTimeChanged.connect(this, &VappDateSettingCell::onDateUpdate);
#ifdef __MMI_NITZ__
    VappNitzController *nitzController = VFX_OBJ_GET_INSTANCE(VappNitzController);
    nitzController->m_signalSettingUpdate.connect(this, &VappDateSettingCell::updateCell);
    setIsDisabled(nitzController->getNITZSetting() == VAPP_NITZ_ON ? VFX_TRUE : VFX_FALSE);
#endif /* __MMI_NITZ__ */
}

void VappDateSettingCell::updateCell() 
{
    setHintText(getHint());
#ifdef __MMI_NITZ__    
    VappNitzController *nitzController = VFX_OBJ_GET_INSTANCE(VappNitzController);
    setIsDisabled(nitzController->getNITZSetting() == VAPP_NITZ_ON ? VFX_TRUE : VFX_FALSE);
#endif /* __MMI_NITZ__ */
}
void VappDateSettingCell::onTap(VcpFormItemCell* sender, VfxId senderId)
{

    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);
    if (mainScr)
	{
	    VappDateSettingPage *settingPage;
        VFX_OBJ_CREATE(settingPage, VappDateSettingPage, mainScr);
        settingPage->m_signalUpdateCell.connect(this, &VappDateSettingCell::updateCell);
        mainScr->pushPage(0, settingPage);    
	}        
}

VfxWString VappDateSettingCell::getHint()
{
    VfxDateTime dateTime;
    dateTime.setCurrentTime();
    
    VfxWChar buffer[VAPP_DATE_TIME_STRING_BUFFER_LENGTH] = {0};
    dateTime.getDateTimeString(VFX_DATE_TIME_DATE_MASK, buffer, VAPP_DATE_TIME_STRING_BUFFER_LENGTH);

    return VFX_WSTR_MEM(buffer);
}

void VappDateSettingCell::onDateUpdate(VfxU32 flag)
{
    if ((flag & VDAT_SYSTIME_CHANGED_DAY) || (flag & VDAT_SYSTIME_CHANGED_MONTH) || (flag & VDAT_SYSTIME_CHANGED_YEAR))
    {
        updateCell();
    }    
}
/***************************************************************************** 
 * VappDateSettingPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappDateSettingPage", VappDateSettingPage, VfxPage);

void VappDateSettingPage::onInit()
{
    VfxPage::onInit();
    m_selectFormat = srv_setting_get_date_format();
    m_selectSeperator = srv_setting_get_date_seperator();
    VfxDateTime currentDate;
    currentDate.setCurrentTime();
    m_date.year = currentDate.getYear();
    m_date.month = currentDate.getMonth();
    m_date.day = currentDate.getDay();
    
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle(STR_ID_VAPP_SETTING_DATE_SETTINGS);
    setTopBar(m_titleBar);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->addItem(0, STR_GLOBAL_SAVE, VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    m_toolBar->addItem(1, STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect(this, &VappDateSettingPage::onToolBarTap);
    setBottomBar(m_toolBar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
	m_form->setPos(0, 0);
	m_form->setBounds(VfxRect(0, 0, LCD_WIDTH, LCD_HEIGHT));
	m_form->setViewRect(VfxRect(0, 0, LCD_WIDTH, LCD_HEIGHT));
//	m_form->setBgColor(VFX_COLOR_WHITE);
	m_form->enableVerticalScrollIndicator(VFX_TRUE);
	m_form->setBorderColor(VFX_COLOR_BLACK);    

    VFX_OBJ_CREATE(m_dateFormatCell, VcpFormItemLauncherCell, this);
    m_dateFormatCell->setMainText(STR_ID_VAPP_SETTING_DATE_FORMAT);	    
    m_dateFormatCell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
	m_dateFormatCell->setHintText(VappDateFormatString[m_selectFormat]);
    m_dateFormatCell->m_signalTap.connect(this, &VappDateSettingPage::onEntryDateFormat);
    m_form->addItem(m_dateFormatCell, 0);
    
    VFX_OBJ_CREATE(m_dateSeperatorCell, VcpFormItemLauncherCell, this);
    m_dateSeperatorCell->setMainText(STR_ID_VAPP_SETTING_DATE_SEPERATOR);	    
    m_dateSeperatorCell->setAccessory(VCPFORM_NEXT_ITEM_ICON);

    UpdateDateSeperator(m_selectSeperator);
    m_dateSeperatorCell->m_signalTap.connect(this, &VappDateSettingPage::onEntryDateSeperator);
    m_form->addItem(m_dateSeperatorCell, 1);

    VFX_OBJ_CREATE(m_datePicker, VcpDatePicker, this);
    m_datePicker->setDate(m_date);
    VcpDatePickerStruct minDate;
    minDate.year = 2000;
    minDate.month = 1;
    minDate.day = 1;
    
    VcpDatePickerStruct maxDate;
    maxDate.year = 2030;
    maxDate.month = 12;
    maxDate.day = 31;
    
    VcpDatePickerFormatEnum format = VCP_DATE_PICKER_FORMAT_DDMMYYYY;
    switch (m_selectFormat)
	{
	case 0:
		format = VCP_DATE_PICKER_FORMAT_DDMMYYYY;
		break;

	case 1:
		format = VCP_DATE_PICKER_FORMAT_MMDDYYYY;
		break;

	case 2:
		format = VCP_DATE_PICKER_FORMAT_YYYYMMDD;
		break;
	default:
		break;
	}
    m_datePicker->setFormat(format);

    m_datePicker->setMinDate(minDate);
    m_datePicker->setMaxDate(maxDate);
    m_datePicker->setAnchor(0.5, 0);
    m_datePicker->setPos(LCD_WIDTH / 2, VAPP_DATE_TIME_PICKER_TOP_MARGIN);
    m_datePicker->m_signalOnDateChanged.connect(this, &VappDateSettingPage::updateDate);

    VcpFormItemCustomFrame *customCell;
    VFX_OBJ_CREATE(customCell, VcpFormItemCustomFrame, this);
    customCell->attachCustomFrame(m_datePicker);
    const VfxSize cellSize = customCell->getSize();
    customCell->setSize(cellSize.width, cellSize.height+VAPP_DATE_TIME_PICKER_TOP_MARGIN);
    m_form->addItem(customCell, 2);   
}

void VappDateSettingPage::onEntryDateFormat(VcpFormItemCell* sender, VfxId senderId)
{
    VappDateFormatSettingPage *dateFormatSettingPage;
    VFX_OBJ_CREATE(dateFormatSettingPage, VappDateFormatSettingPage, this);
    dateFormatSettingPage->setSelectIndex(m_selectFormat);
    dateFormatSettingPage->m_updateFormat.connect(this, &VappDateSettingPage::UpdateDateFormat);
    getMainScr()->pushPage(0, dateFormatSettingPage);
}

void VappDateSettingPage::onEntryDateSeperator(VcpFormItemCell* sender, VfxId senderId)
{
    VappDateSeperatorSettingPage *dateSeperatorSettingPage;
    VFX_OBJ_CREATE(dateSeperatorSettingPage, VappDateSeperatorSettingPage, this);
    dateSeperatorSettingPage->setSelectIndex(m_selectSeperator);
    dateSeperatorSettingPage->setDateFormat(m_selectFormat);
    dateSeperatorSettingPage->setDate(m_date);
    dateSeperatorSettingPage->m_updateSeperator.connect(this, &VappDateSettingPage::UpdateDateSeperator);
    getMainScr()->pushPage(0, dateSeperatorSettingPage);
}

void VappDateSettingPage::UpdateDateFormat(VfxU8 dateFormat)
{
    m_selectFormat = dateFormat;
    m_dateFormatCell->setHintText(VappDateFormatString[m_selectFormat]);
    UpdateDateSeperator(m_selectSeperator);
    VcpDatePickerFormatEnum format = VCP_DATE_PICKER_FORMAT_DDMMYYYY;
    switch (m_selectFormat)
	{
	case 0:
		format = VCP_DATE_PICKER_FORMAT_DDMMYYYY;
		break;

	case 1:
		format = VCP_DATE_PICKER_FORMAT_MMDDYYYY;
		break;

	case 2:
		format = VCP_DATE_PICKER_FORMAT_YYYYMMDD;
		break;
	default:
		break;
	}
    m_datePicker->setFormat(format);
}

void VappDateSettingPage::UpdateDateSeperator(VfxU8 dateSeperator)
{
    m_selectSeperator = dateSeperator;

    VfxWString seperatorString = vapp_get_current_date_string(
    (srv_setting_date_format_enum)m_selectFormat, 
    (srv_setting_date_format_enum)m_selectSeperator,
    m_date.year,
    m_date.month,
    m_date.day);
	m_dateSeperatorCell->setHintText(seperatorString);
}
    
void VappDateSettingPage::updateDate(VfxObject* sender, VcpDatePickerStruct *date)
{
    m_date = *date;
    UpdateDateSeperator(m_selectSeperator);
}


void VappDateSettingPage::onToolBarTap(VfxObject* sender, VfxId senderId)
{
    if (senderId == 0)
	{
        srv_setting_set_date_format((srv_setting_date_format_enum)m_selectFormat);
        srv_setting_set_date_seperator((srv_setting_date_seperator_enum)m_selectSeperator);
        MYTIME updateTime;
        applib_dt_get_rtc_time((applib_time_struct*)&updateTime);
        updateTime.nYear = m_date.year;
        updateTime.nMonth= m_date.month;
        updateTime.nDay = m_date.day;
        mmi_dt_set_dt(&updateTime, &VappDateSettingPage::onDateUpdateRsp, this);
	}
    else
    {
    getMainScr()->popPage();
    }

}

void VappDateSettingPage::onDateUpdate(VfxBool result)
{
    m_signalUpdateCell.emit();
    getMainScr()->popPage();    
}

void VappDateSettingPage::onDateUpdateRsp(MMI_BOOL result, void *userData)
{
    VfxObject *obj = (VfxObject*)userData;
    VappDateSettingPage* page = VFX_OBJ_DYNAMIC_CAST(obj, VappDateSettingPage);
    if (page)
	{
	    page->onDateUpdate((result == MMI_TRUE ? VFX_TRUE : VFX_FALSE));
	}
}
/***************************************************************************** 
 * VappDateFormatSettingPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappDateFormatSettingPage", VappDateFormatSettingPage, VfxPage);
void VappDateFormatSettingPage::onInit()
{
    VfxPage::onInit();
    
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(STR_ID_VAPP_SETTING_DATE_FORMAT);
    setTopBar(titleBar);    
    

    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);

    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_listMenu->setContentProvider(this);
	m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_TRUE);    
	m_listMenu->setRect(0, 0, LCD_WIDTH, LCD_HEIGHT);		 
    m_listMenu->m_signalItemTapped.connect(this, &VappDateFormatSettingPage::onSelectItem); 
}

VfxBool VappDateFormatSettingPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
	if (index < (VfxU32)getCount())
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)	
		{
		   text.loadFromRes(VappDateFormatString[index]);
		   color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		   return VFX_TRUE;
		}
	}
	return VFX_FALSE;    
}

void VappDateFormatSettingPage::onSelectItem(VcpListMenu *listMenu, VfxU32 selectIdx) 
{
    m_updateFormat.emit(selectIdx);
    getMainScr()->popPage(); 
}

/***************************************************************************** 
 * VappDateSeperatorSettingPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappDateSeperatorSettingPage", VappDateSeperatorSettingPage, VfxPage);
void VappDateSeperatorSettingPage::onInit()
{
    VfxPage::onInit();
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(STR_ID_VAPP_SETTING_DATE_SEPERATOR);
    setTopBar(titleBar);    

	VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);

    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	m_listMenu->setContentProvider(this);
	m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_TRUE);    
	m_listMenu->setRect(0, 0, LCD_WIDTH, LCD_HEIGHT);		 
    m_listMenu->m_signalItemTapped.connect(this, &VappDateSeperatorSettingPage::onSelectItem); 
}

VfxBool VappDateSeperatorSettingPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
	if (index < (VfxU32)getCount())
	{
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)	
		{
		    text = vapp_get_current_date_string(
                (srv_setting_date_format_enum)m_dateFormat, 
                (srv_setting_date_format_enum)index,
                m_date.year,
                m_date.month,
                m_date.day);
		    color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
		    return VFX_TRUE;
		}
	}
	return VFX_FALSE;    
}

void VappDateSeperatorSettingPage::onSelectItem(VcpListMenu *listMenu, VfxU32 selectIdx) 
{
    getMainScr()->popPage(); 
    m_updateSeperator.emit(selectIdx);
}


/***************************************************************************** 
 * VappTimeSettingCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappTimeSettingCell", VappTimeSettingCell, VcpFormItemLauncherCell);
void VappTimeSettingCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    setMainText(STR_ID_VAPP_SETTING_TIME_SETTINGS);
    setHintText(getHint());
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_signalTap.connect(this, &VappTimeSettingCell::onTap);

    VdatTimeNotification *sysTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    sysTimeSrv->m_signalTimeChanged.connect(this, &VappTimeSettingCell::onTimeUpdate);    
#ifdef __MMI_NITZ__
    VappNitzController *nitzController = VFX_OBJ_GET_INSTANCE(VappNitzController);
    nitzController->m_signalSettingUpdate.connect(this, &VappTimeSettingCell::updateCell);
    setIsDisabled(nitzController->getNITZSetting() == VAPP_NITZ_ON ? VFX_TRUE : VFX_FALSE);
#endif /* __MMI_NITZ__ */
}
void VappTimeSettingCell::onTap(VcpFormItemCell* sender, VfxId senderId)
{
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);
    if (mainScr)
	{
        VappTimeSettingPage *settingPage;
        VFX_OBJ_CREATE(settingPage, VappTimeSettingPage, mainScr);
        settingPage->m_signalUpdate.connect(this, &VappTimeSettingCell::updateCell);
        mainScr->pushPage(0, settingPage);    
	}    
}

void VappTimeSettingCell::updateCell()
{
    setHintText(getHint());
#ifdef __MMI_NITZ__    
    VappNitzController *nitzController = VFX_OBJ_GET_INSTANCE(VappNitzController);
    setIsDisabled(nitzController->getNITZSetting() == VAPP_NITZ_ON ? VFX_TRUE : VFX_FALSE);
#endif /* __MMI_NITZ__ */
}

VfxWString VappTimeSettingCell::getHint()
{
    VfxDateTime dateTime;
    dateTime.setCurrentTime();
    
    VfxWChar buffer[VAPP_DATE_TIME_STRING_BUFFER_LENGTH] = {0};
    dateTime.getDateTimeString(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE, buffer, VAPP_DATE_TIME_STRING_BUFFER_LENGTH);
    return VFX_WSTR_MEM(buffer);
}

void VappTimeSettingCell::onTimeUpdate(VfxU32 flag)
{
    if ((flag & VDAT_SYSTIME_CHANGED_MIN) || (flag & VDAT_SYSTIME_CHANGED_HOUR))
    {
        updateCell();
    }    
}

/***************************************************************************** 
 * VappTimeSettingPage
 *****************************************************************************/
 VFX_IMPLEMENT_CLASS("VappTimeSettingPage", VappTimeSettingPage, VfxPage);
void VappTimeSettingPage::onInit()
{
    VfxPage::onInit();
    m_is24HourFormat = srv_setting_get_time_format();
    m_dayLightSaving = mmi_wc_get_home_dst() == 0 ? VFX_FALSE : VFX_TRUE;

    VfxDateTime currentDate;
    currentDate.setCurrentTime();
    m_time.hour = currentDate.getHour();
    m_time.minute = currentDate.getMinute();

    
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle(STR_ID_VAPP_SETTING_TIME_SETTINGS);
    setTopBar(m_titleBar);

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->addItem(0, STR_GLOBAL_SAVE, VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    m_toolBar->addItem(1, STR_GLOBAL_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect(this, &VappTimeSettingPage::onToolBarTap);
    setBottomBar(m_toolBar);

    VFX_OBJ_CREATE(m_form, VcpForm, this);
	m_form->setPos(0, 0);
	m_form->setBounds(VfxRect(0, 0, LCD_WIDTH, LCD_HEIGHT));
	m_form->setViewRect(VfxRect(0, 0, LCD_WIDTH, LCD_HEIGHT));
//	m_form->setBgColor(VFX_COLOR_WHITE);
	m_form->enableVerticalScrollIndicator(VFX_TRUE);
	m_form->setBorderColor(VFX_COLOR_BLACK);   
    
    VFX_OBJ_CREATE(m_timeFormatCell, VcpFormItemSwitchCell, this);
    m_timeFormatCell->setMainText(STR_ID_VAPP_SETTING_24_HOUR_TIME);
//    m_is24HourFormatCell->setHintText(VFX_WSTR("Enable or disable 24-Hour format"));
    m_timeFormatCell->setSwitchStatus(m_is24HourFormat);
    m_timeFormatCell->m_signalSwitchChangeReq.connect(this, &VappTimeSettingPage::onTimeFormatTap);
    m_timeFormatCell->setIsTappable(VFX_FALSE);
    m_form->addItem(m_timeFormatCell, 0);
    

    VFX_OBJ_CREATE(m_dayLightSavingCell, VcpFormItemSwitchCell, this);    
    m_dayLightSavingCell->setMainText(STR_ID_VAPP_SETTING_DAYLIGHT_SAVING_TIME);
//    m_dayLightSavingCell->setHintText(VFX_WSTR("Enable or disable daylight saving"));
    m_dayLightSavingCell->setSwitchStatus(m_dayLightSaving);
    m_dayLightSavingCell->m_signalSwitchChangeReq.connect(this, &VappTimeSettingPage::onDayLightSavingTap);    
    m_dayLightSavingCell->setIsTappable(VFX_FALSE);
    m_form->addItem(m_dayLightSavingCell, 1);

    VFX_OBJ_CREATE(m_timePicker, VcpTimePicker, this);
    m_timePicker->setTime(m_time);
    m_timePicker->setIs24HourView(m_is24HourFormat);
    m_timePicker->m_signalOnTimeChanged.connect(this, &VappTimeSettingPage::updateTime);
    m_timePicker->setAnchor(0.5, 0);
    m_timePicker->setPos(LCD_WIDTH / 2, VAPP_DATE_TIME_PICKER_TOP_MARGIN);

    VcpFormItemCustomFrame *customCell;
    VFX_OBJ_CREATE(customCell, VcpFormItemCustomFrame, this);
    customCell->attachCustomFrame(m_timePicker);
    const VfxSize cellSize = customCell->getSize();
    customCell->setSize(cellSize.width, cellSize.height+VAPP_DATE_TIME_PICKER_TOP_MARGIN);
    m_form->addItem(customCell, 2);   
}

void VappTimeSettingPage::onToolBarTap(VfxObject* sender, VfxId senderId)
{
    if (senderId == 0)
	{
        srv_setting_set_time_format((srv_setting_time_format_enum)m_is24HourFormat);
        srv_wc_save_home_dst((VfxU8)m_dayLightSaving);
        MYTIME updateTime;
        DTGetRTCTime(&updateTime);
        updateTime.nHour = m_time.hour;
        updateTime.nMin = m_time.minute;
        mmi_dt_set_dt(&updateTime, &VappTimeSettingPage::onTimeUpdateRsp, this);
	}
    else
    {
    getMainScr()->popPage();
}
}

void VappTimeSettingPage::onTimeFormatTap(VcpFormItemSwitchCell* sender, VfxId senderId, VfxBool value)
{
    m_is24HourFormat = value;
    m_timeFormatCell->setSwitchStatus(m_is24HourFormat);    
    m_timePicker->setIs24HourView(m_is24HourFormat);
}

void VappTimeSettingPage::onDayLightSavingTap(VcpFormItemSwitchCell* sender, VfxId senderId, VfxBool value)
{
    if (m_dayLightSaving == VFX_TRUE && value == VFX_FALSE)
    {
	m_time.hour = m_time.hour == 0 ? 23 : (m_time.hour - 1);
    }
    else if (m_dayLightSaving == VFX_FALSE && value == VFX_TRUE)
    {
	m_time.hour = m_time.hour == 23 ? 0 : (m_time.hour + 1);        
    }
    m_timePicker->setTime(m_time);
    m_dayLightSaving = value;
    m_dayLightSavingCell->setSwitchStatus(m_dayLightSaving);
}

void VappTimeSettingPage::updateTime(VfxObject *sender, VcpTimePickerStruct *time)
{
    m_time = *time;    
}

void VappTimeSettingPage::onTimeUpdate(VfxBool result)
{
    m_signalUpdate.emit();
    getMainScr()->popPage();
}

void VappTimeSettingPage::onTimeUpdateRsp(MMI_BOOL result, void *userData)
{
    if (result)
	{
        VfxObject *obj = (VfxObject*)userData;
        VappTimeSettingPage* page = VFX_OBJ_DYNAMIC_CAST(obj, VappTimeSettingPage);
        if (page)
    	{
    	    page->onTimeUpdate((result == MMI_TRUE ? VFX_TRUE : VFX_FALSE));
    	}
	}
}
#pragma arm section code, rodata

