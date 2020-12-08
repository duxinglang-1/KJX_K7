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
 *  vapp_alarm.h
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
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_ALARM_H__
#define __VAPP_ALARM_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_datatype.h"
#include "vfx_app.h"
#include "vfx_main_scr.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_ALM_HINT_TEXT_COLOR  VfxColor(255,50, 50, 50)
#define VAPP_ALM_NO_ALM_TEXT_COLOR  VfxColor(255, 128, 128, 128)

#define ALARM_TOTAL_WDAY 	(VappAlarmApp::ID_DAY_TOTAL)
#define ALARM_TOTAL_SNOOZE  (VappAlarmApp::ID_SNOOZE_TOTAL)
#define ALARM_MAX_LABEL_LEN	(VappAlarmApp::MAX_LABEL_LEN)

#define ALARM_REPEAT_EVERYDAY (0x7F)
#define ALARM_REPEAT_ONCE (0)

#define ALARM_GET_TIMESTAMP		VappAlarmApp::getTimeStamp()
#define ALARM_GET_WDAY_STR(v)	   (VFX_WSTR_RES(VappAlarmApp::s_weekStringList[v]))
#define ALARM_GET_WDAY_SHORTSTR(v) (VFX_WSTR_RES(VappAlarmApp::s_weekShortStringList[v]))

#define ALARM_GET_SNOOZE_STR(v)   (VFX_WSTR_RES(VappAlarmApp::s_snoozeStringList[v]))
#define ALARM_GET_SNOOZE_FOR_RES(v)   (VappAlarmApp::s_snoozeForList[v])
#define ALARM_GET_SNOOZING_FOR_RES(v)   (VappAlarmApp::s_snoozingForList[v])

#define ALARM_GET_SNOOZE_VALUE(v) (VappAlarmApp::s_snoozeVal[v])
#define ALARM_GET_SNOOZE_IDX(v) (VappAlarmApp::getSnoozeIndex(v))

#define ALM_TRC_GRP TRACE_GROUP_2
#define ALM_DEFAULT_VOL 4
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef struct{
	VfxId launch_id;
	VfxBool pwr_off;
	VfxU32	expiry_index;
    VfxScrRotateTypeEnum rotateType;
}VappAlarmParam;

/***************************************************************************** 
 * Class VappAlarmApp
 *****************************************************************************/
class VfxAppScr;
class VappAlarmApp : public VfxApp, public IVfxMainScrHandler
{
    VFX_DECLARE_CLASS(VappAlarmApp);


public:
	VappAlarmApp() {};
	virtual ~VappAlarmApp(){};

	enum 
	{
		MAX_TEXT_LEN = 32,
		MAX_LABEL_LEN = 10,
		MAX_SNOOZE_TIME = 10
	};

	enum
	{
		ID_LAUNCH_ALARM,
		ID_LAUNCH_ALARM_IND,
		ID_LAUNCH_TOTAL
	};
	
	enum
	{
		ID_SNOOZE_3MIN,
		ID_SNOOZE_5MIN,
		ID_SNOOZE_10MIN,
		ID_SNOOZE_15MIN,
		ID_SNOOZE_TOTAL
	};
	enum
	{
		ID_DAY_SUN,
		ID_DAY_MON,
		ID_DAY_TUE,
		ID_DAY_WED,
		ID_DAY_THU,
		ID_DAY_FRI,
		ID_DAY_SAT,
		ID_DAY_TOTAL
	};

	enum
	{
		ID_ACTION_STOP,
		ID_ACTION_SNOOZE,
		ID_ACTION_TOTAL
	};

// Override
protected:
    void onRun(void* args, VfxU32 argSize);
	void onScr1stReady(VfxMainScrEx *scr);
		
public:
	static VfxU8 getVol(void);
	static VfxU8 getSnoozeVal(void);
	static VfxWString checkPathExt(VfxWChar* toneStr, const VfxWChar *hideStr);
	static VfxS8 getSnoozeIndex(const VfxU8 &value);
	static VfxWString getRepeatString(const VfxU16 &repeat,const VfxU8 &days);
	static VfxU32 getTimeStamp(void);
	static VfxWString getTimeString(const VfxU32 &hour, const VfxU32 &min);
	static void getAlmList(VfxU8 *list, VfxU8 &count);
	static VfxU8 getRecentAlm(void);
	static MMI_BOOL cmpCallback(U8 index1, U8 index2, MMI_BOOL snooze);
	static MMI_BOOL searchAllCallback(void *data, void *usr_data);
	static MMI_BOOL searchRecentCallback(void *data, void *usr_data);
	static mmi_ret onFmgrEvtFormat(mmi_event_struct *evt);
	static mmi_ret onFmgrEvtAdv(mmi_event_struct *evt);
	static mmi_ret onPwroffAsk(mmi_event_struct *evt);
	static VfxBool needPwrOff(void);
	static void refreshStatusIcon(void);
	
	const static VfxId s_snoozeStringList[ALARM_TOTAL_SNOOZE];
	const static VfxId s_snoozeForList[ALARM_TOTAL_SNOOZE];
	const static VfxId s_snoozingForList[ALARM_TOTAL_SNOOZE];
	const static VfxId s_weekStringList[ALARM_TOTAL_WDAY];
	const static VfxId s_weekShortStringList[ALARM_TOTAL_WDAY];
	const static VfxU8 s_snoozeVal[ALARM_TOTAL_SNOOZE];

	
};


#endif /* __VAPP_ALARM_H__ */

