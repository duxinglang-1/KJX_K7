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
 *  vapp_alarm.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Fancy alarm ap.
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
 * removed!
 *
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


extern "C"
{
	#include "app_datetime.h"
	#include "GlobalResDef.h"
	#include "gui_typedef.h"
	#include "Wgui_categories_util.h"
	
	#include "AlarmSrvGprot.h"
	#include "BootupSrvGprot.h"
	#include "CharBatSrvGprot.h"
	#include "FileMgrSrvGprot.h"
	#include "ProfilesSrvGprot.h"
	#include "ReminderSrvGprot.h"
	#include "USBSrvGprot.h"
}

#include "custom_srv_prof_defs.h"
#include "mmi_rp_vapp_alarm_def.h"

#include "vfx_app_launcher.h"

#include "vapp_alarm.h"
#include "vapp_alarm_edit.h"
#include "vapp_alarm_indication.h"
#include "vapp_alarm_list.h"
#include "vapp_alarm_setting.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define RETURN_IF_FAIL(p) if (!(p)) { return; }
#define RETURN_VAL_IF_FAIL(p, val) if (!(p)) { return val; }

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * Class VappAlarmApp
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappAlarmApp", VappAlarmApp, VfxApp);
const VfxId VappAlarmApp::s_snoozeStringList[ALARM_TOTAL_SNOOZE] =
{
	STR_ID_VAPP_ALARM_SNOOZE_3MIN,
	STR_ID_VAPP_ALARM_SNOOZE_5MIN,
	STR_ID_VAPP_ALARM_SNOOZE_10MIN,
	STR_ID_VAPP_ALARM_SNOOZE_15MIN
};
const VfxId VappAlarmApp::s_snoozeForList[ALARM_TOTAL_SNOOZE] =
{
	STR_ID_VAPP_ALARM_SNOOZE_FOR_3MIN,
	STR_ID_VAPP_ALARM_SNOOZE_FOR_5MIN,
	STR_ID_VAPP_ALARM_SNOOZE_FOR_10MIN,
	STR_ID_VAPP_ALARM_SNOOZE_FOR_15MIN
};

const VfxId VappAlarmApp::s_snoozingForList[ALARM_TOTAL_SNOOZE] =
{
	STR_ID_VAPP_ALARM_SNOOZING_FOR_3MIN,
	STR_ID_VAPP_ALARM_SNOOZING_FOR_5MIN,
	STR_ID_VAPP_ALARM_SNOOZING_FOR_10MIN,
	STR_ID_VAPP_ALARM_SNOOZING_FOR_15MIN,
};

const VfxU8 VappAlarmApp::s_snoozeVal[ALARM_TOTAL_SNOOZE] = 
{
	3, 5, 10, 15
};

const VfxId VappAlarmApp::s_weekStringList[ALARM_TOTAL_WDAY] =
{
	STR_ID_VAPP_ALARM_WDAY_SUN,
	STR_ID_VAPP_ALARM_WDAY_MON,
	STR_ID_VAPP_ALARM_WDAY_TUE,
	STR_ID_VAPP_ALARM_WDAY_WED,
	STR_ID_VAPP_ALARM_WDAY_THU,
	STR_ID_VAPP_ALARM_WDAY_FRI,
	STR_ID_VAPP_ALARM_WDAY_SAT,
};

const VfxId VappAlarmApp::s_weekShortStringList[ALARM_TOTAL_WDAY] =
{
	STR_ID_VAPP_ALARM_WDAY_SHORT_SUN,
	STR_ID_VAPP_ALARM_WDAY_SHORT_MON,
	STR_ID_VAPP_ALARM_WDAY_SHORT_TUE,
	STR_ID_VAPP_ALARM_WDAY_SHORT_WED,
	STR_ID_VAPP_ALARM_WDAY_SHORT_THU,
	STR_ID_VAPP_ALARM_WDAY_SHORT_FRI,
	STR_ID_VAPP_ALARM_WDAY_SHORT_SAT
};


void VappAlarmApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

	VappAlarmParam *param = (VappAlarmParam *)args;

	VFX_ASSERT(param != NULL && argSize == sizeof(VappAlarmParam));

	VfxMainScrEx *scr;
	VFX_OBJ_CREATE_EX(scr, VfxMainScrEx, this, (this));
		scr->show();
}

void VappAlarmApp::onScr1stReady(VfxMainScrEx *scr)
{
	VappAlarmlistPage *page;
	
	VFX_OBJ_CREATE(page, VappAlarmlistPage, scr);
	scr->pushPage(VFX_ID_NULL, page);
}

VfxU32 VappAlarmApp::getTimeStamp(void)
{
    applib_time_struct t;

    applib_dt_get_rtc_time(&t);
	
    return (VfxU32)applib_dt_mytime_2_utc_sec(&t, KAL_FALSE);
}

VfxS8 VappAlarmApp::getSnoozeIndex(const VfxU8 &value)
{
	for (VfxU32 i = 0; i < ALARM_TOTAL_SNOOZE; i++) 
	{
		if (value == ALARM_GET_SNOOZE_VALUE(i))
		{
			return i;
		}
	}

	return -1;
}

VfxU8 VappAlarmApp::getVol(void)
{
	VfxU8 vol;
	VfxS16 sError;
	
	ReadValue(NVRAM_ALARM_SETTINGS_VOL, &vol, DS_BYTE, &sError);
	if (vol == 0xFF)
	{
		vol = ALM_DEFAULT_VOL;
		WriteValue(NVRAM_ALARM_SETTINGS_VOL, &vol, DS_BYTE, &sError);
	}
	
	return vol;
}

VfxU8 VappAlarmApp::getSnoozeVal(void)
{
	VfxU8 snooze;
	VfxS16 errorCode;
	
	ReadValue(NVRAM_ALARM_SETTINGS_SNOOZE, &snooze, DS_BYTE, &errorCode);
	if (snooze > ALARM_GET_SNOOZE_VALUE(ALARM_TOTAL_SNOOZE - 1) ||
		snooze < ALARM_GET_SNOOZE_VALUE(0))
	{
		snooze = ALARM_GET_SNOOZE_VALUE(0);
		WriteValue(NVRAM_ALARM_SETTINGS_SNOOZE, &snooze, DS_BYTE, &errorCode);
	}

	return snooze;
}

VfxWString VappAlarmApp::getRepeatString(const VfxU16 &repeat, const VfxU8 &days)
{
	if (repeat == SRV_REMINDER_REPEAT_ONCE)
	{
		return VFX_WSTR_RES(STR_ID_VAPP_ALARM_REPEAT_ONCE);
	}

	VfxWString outStr;
	for (VfxU32 i = 0; i < 7; i++)
	{
		if (days & (1 << i))
		{
			if (!outStr.isNull())
			{
				outStr += VFX_WSTR_RES(STR_ID_VAPP_ALARM_COMMA);
			}
			outStr += ALARM_GET_WDAY_SHORTSTR(i);
		}	
	}

	return outStr;
}

VfxWString VappAlarmApp::getTimeString(const VfxU32 &hour, const VfxU32 &min)
{
	VfxDateTime dateTime;
	dateTime.setTime(hour, min, 0);

	VfxWChar buffer[MAX_TEXT_LEN];

	dateTime.getDateTimeString(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE, 
							   buffer, 
							   MAX_TEXT_LEN);
	VfxWString outStr;
	outStr.loadFromMem(buffer);

	return outStr;
}

VfxWString VappAlarmApp::checkPathExt(VfxWChar* toneStr, const VfxWChar *hideStr)
{
	VfxWString strTemp;
	VfxWChar *namePtr, *resultNamePtr, *extPtr;
	
	namePtr = (VfxWChar*)srv_fmgr_path_get_filename_ptr((WCHAR*)toneStr);
	extPtr = (VfxWChar*)srv_fmgr_path_get_extension_const_ptr((const WCHAR*)toneStr);
	
	if (extPtr == NULL ||
		(mmi_ucs2icmp((const CHAR*)extPtr, (const CHAR*)hideStr) != 0))
	{
		strTemp = VFX_WSTR_MEM(namePtr);
		return strTemp;
	}

	resultNamePtr = (VfxWChar *)OslMalloc(sizeof(VfxWChar) * (SRV_FMGR_PATH_BUFFER_SIZE));
	
    /* Only show file name */
	mmi_ucs2cpy((CHAR *)resultNamePtr, (CHAR *)namePtr);
	extPtr = srv_fmgr_path_get_extension_ptr((WCHAR*)resultNamePtr);
	*(extPtr - 1) = 0;

	strTemp = VFX_WSTR_MEM(resultNamePtr);

	OslMfree(resultNamePtr);
	
	return strTemp;
}

void VappAlarmApp::getAlmList(VfxU8 *list, VfxU8 &count)
{
	srv_alm_search(list, NUM_OF_ALM, &count, &count, VappAlarmApp::searchAllCallback);

	if (count != NULL)
	{
		srv_alm_sort(list, count, MMI_FALSE, VappAlarmApp::cmpCallback);
	}

	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_GET_LIST, count, 1);

	//return (count == 0) ? VFX_TRUE : VFX_FALSE;
}

VfxU8 VappAlarmApp::getRecentAlm(void)
{
	VappAlarmApp::refreshStatusIcon();
	
	VfxU8 count = 0;
	VfxU8 list[NUM_OF_ALM];
	MYTIME currTime;
	GetDateTime(&currTime);
	
	srv_alm_search(list, NUM_OF_ALM, &count, &currTime, VappAlarmApp::searchRecentCallback);

	if (count != 0)
	{
		srv_alm_sort(list, count, MMI_FALSE, NULL);
		
		MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_GET_RECENT, count, list[0], list[0]);
		
		return list[0];
	}

	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_GET_RECENT, 0, 0, 0xFF);
	
	return 0xFF;
}

MMI_BOOL VappAlarmApp::cmpCallback(U8 index1, U8 index2, MMI_BOOL snooze)
{
    srv_alm_node_type *node1 = srv_alm_read(index1);
	srv_alm_node_type *node2 = srv_alm_read(index2);

	/* The one has larger time will be at behind */
	if (node1->Hour > node2->Hour)
	{
		return MMI_TRUE;
	}
	else if (node1->Hour == node2->Hour)
	{
		if (node1->Min > node2->Min)
		{
			return MMI_TRUE;
		}
		else if (node1->Min == node2->Min)
		{
			return ((node1->timestamp > node2->timestamp) ? MMI_TRUE : MMI_FALSE);
		}
	}

	return MMI_FALSE;
}


MMI_BOOL VappAlarmApp::searchAllCallback(void *data, void *usr_data)
{
	srv_alm_node_type *node;

	RETURN_VAL_IF_FAIL(data != NULL, MMI_FALSE);
	
	node = (srv_alm_node_type*)data;

	if (node->Hour == 0xFF)
	{
		return MMI_FALSE;
	}

	return MMI_TRUE;
}

MMI_BOOL VappAlarmApp::searchRecentCallback(void *data, void *usr_data)
{
	srv_alm_node_type *node;

	RETURN_VAL_IF_FAIL(data != NULL, MMI_FALSE);
	
	node = (srv_alm_node_type*)data;

	if (node->Hour == 0xFF || node->State != 1 || node->Snooze != 0)
	{
		return MMI_FALSE;
	}

	MYTIME currTime, almTime;
	GetDateTime(&currTime);
	currTime.nSec = 0;
	
	almTime = currTime;
	//almTime.nSec = 0;
	almTime.nHour = node->Hour;
	almTime.nMin = node->Min;
	
	almTime = srv_reminder_calc_time(&almTime, (srv_reminder_repeat_enum)node->Freq, node->Days);

	VfxU32 ret = CompareTime(almTime, currTime, NULL);
	
	if (ret == DT_TIME_EQUAL || ret == DT_TIME_GREATER)
	{
		return MMI_TRUE;
	}
	
	return MMI_FALSE;

}

mmi_ret VappAlarmApp::onFmgrEvtFormat(mmi_event_struct *evt)
{
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_FMGR_FMT, 0);
	
	srv_alm_node_type *node;
	srv_fmgr_notification_format_event_struct *format_evt;
    format_evt = (srv_fmgr_notification_format_event_struct*)evt;

	for (VfxU32 i = 0; i < NUM_OF_ALM; i++) 
	{
		node = srv_alm_read(i);	
		if ((node->AudioOption == SRV_PROF_AUDIO_RES_FILE) &&
			(format_evt->drv_letter == node->tone_path[0]))
		{
			MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_FMGR_FMT, i);
			
			node->AudioOptionValue =  0;
			node->AudioOption = SRV_PROF_AUDIO_RES_TONE;
			node->tone_path[0] = 0;
			node->tone_path[1] = 0;

			srv_alm_write(i, node);
		}
	}
	
	return MMI_RET_OK;
}

mmi_ret VappAlarmApp::onFmgrEvtAdv(mmi_event_struct *evt)
{
	srv_fmgr_notification_adv_action_event_struct *fmgr_adv;
	fmgr_adv = (srv_fmgr_notification_adv_action_event_struct*)evt;
	
	if(fmgr_adv->state != SRV_FMGR_NOTIFICATION_STATE_AFTER || 
	   fmgr_adv->action == SRV_FMGR_NOTIFICATION_ACTION_COPY ||
	   fmgr_adv->action == SRV_FMGR_NOTIFICATION_ACTION_CREATE_FOLDER)
	{
		return MMI_RET_OK;
	}

	if(fmgr_adv->result < 0)
	{
		return MMI_RET_OK;
	}
	
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_FMGR_ADV, 0);
	
	VfxBool bFound;
	srv_alm_node_type *node;
	
	for (VfxU32 i = 0; i < NUM_OF_ALM; i++) 
	{
		node = srv_alm_read(i);
		
		if (node->AudioOption == SRV_PROF_AUDIO_RES_FILE)
		{
			bFound = VFX_FALSE;		
			if (!(fmgr_adv->src_fileinfo.attribute & FS_ATTR_DIR))
			{
				// the file is delted
				if (fmgr_adv->src_filepath != NULL &&
					mmi_ucs2cmp((const CHAR *)node->tone_path, 
								(const CHAR *)fmgr_adv->src_filepath) == 0)
				{
					bFound = VFX_TRUE;
				}
			}
			else
			{
				// The file is under the deleted folder
				if (mmi_ucs2str((const CHAR *)node->tone_path, 
								(const CHAR *)fmgr_adv->src_filepath) != NULL)
				{
					bFound = VFX_TRUE;
				}
			}
			
			if (bFound)
			{
				MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_FMGR_ADV, i);
				
				node->AudioOptionValue =  0;
				node->AudioOption = SRV_PROF_AUDIO_RES_TONE;
				node->tone_path[0] = 0;
				node->tone_path[1] = 0;

				srv_alm_write(i, node);
			}
		}
	} 	
	
	return MMI_RET_OK;
}

mmi_ret VappAlarmApp::onPwroffAsk(mmi_event_struct *evt)
{
	if (needPwrOff())
	{
		srv_reminder_util_send_pwroff();
	}
	return MMI_RET_OK;
}


VfxBool VappAlarmApp::needPwrOff(void)
{
	srv_bootup_mode_enum mode = srv_bootup_get_booting_mode();
			
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_PWR_ASK, mode);

	if (mode == SRV_BOOTUP_MODE_NORMAL)
	{
		return VFX_FALSE;
	}
	
#ifdef __MMI_USB_SUPPORT__
	if (mode == SRV_BOOTUP_MODE_USB && srv_usb_is_connected())
	{
		return VFX_FALSE;
	}
#endif

	if (srv_charbat_is_charger_connect() &&
		((mode == SRV_BOOTUP_MODE_CHARGE) || 
		(mode == SRV_BOOTUP_MODE_PRECHARGE)))
	{
		return VFX_FALSE;
	}

	return VFX_TRUE;
}

void VappAlarmApp::refreshStatusIcon(void)
{
	if (srv_alm_active_alms() != 0)
	{
		wgui_status_icon_bar_show_icon(STATUS_ICON_ALARM);
	}
	else
	{
		wgui_status_icon_bar_hide_icon(STATUS_ICON_ALARM);
	}
}

