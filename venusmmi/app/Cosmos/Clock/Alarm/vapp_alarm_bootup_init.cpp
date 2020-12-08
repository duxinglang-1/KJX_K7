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
 *  vapp_alarm_bootup_init.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Alarm bootup init process, it should be removed in the future. and replaced by callbackmgr
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
	 
/****************************************************************************
* Include
****************************************************************************/
#include "MMI_features.h"
#include "ReminderSrvGprot.h"
#include "mmi_rp_srv_reminder_def.h"
#include "vapp_alarm.h"

/****************************************************************************
* Typedef
****************************************************************************/

typedef struct
{
 mmi_proc_func hdlr;
} vapp_bootup_init_table_entry_struct;


/****************************************************************************
* Handler table
****************************************************************************/

/* Declare function prototypes */
#define VAPP_BOOTUP_INIT_REG_BEGIN(evt_id)
#define VAPP_BOOTUP_INIT_REG(hdlr) \
	extern "C" mmi_ret hdlr(mmi_event_struct *evt);
/* Export the adaptor so that we can look it up in the symbol table */
#define VAPP_BOOTUP_INIT_ADP(hdlr) \
    extern "C" void hdlr(void); \
    static mmi_ret hdlr##_adp(mmi_event_struct *evt) { hdlr(); return MMI_RET_OK; }
#define VAPP_BOOTUP_INIT_REG_END(evt_id)
#include "vapp_alarm_bootup_init_cfg.h"
#undef VAPP_BOOTUP_INIT_REG_BEGIN
#undef VAPP_BOOTUP_INIT_REG
#undef VAPP_BOOTUP_INIT_ADP
#undef VAPP_BOOTUP_INIT_REG_END

/* Generate the handler table */
#define VAPP_BOOTUP_INIT_REG_BEGIN(evt_id) \
    static const vapp_bootup_init_table_entry_struct evt_id##_table[] = {
#define VAPP_BOOTUP_INIT_REG(hdlr) { hdlr },
#define VAPP_BOOTUP_INIT_ADP(hdlr) { hdlr##_adp },
#define VAPP_BOOTUP_INIT_REG_END(evt_id) { NULL }  };
#include "vapp_alarm_bootup_init_cfg.h"
#undef VAPP_BOOTUP_INIT_REG_BEGIN
#undef VAPP_BOOTUP_INIT_REG
#undef VAPP_BOOTUP_INIT_ADP
#undef VAPP_BOOTUP_INIT_REG_END

#define VAPP_BOOTUP_INIT_GET_TABLE(evt_id) (evt_id##_table)


/****************************************************************************
* Functions
****************************************************************************/

/*****************************************************************************
* FUNCTION
*  mmi_reminder_bootup_init_apps
* DESCRIPTION
*  Invoke the callbacks in the table.
* PARAMETERS
*  evt	 [IN] Event to be sent to the callbacks
*  table	 [IN] The callback table
* RETURNS
*  void
*****************************************************************************/
static void vapp_alarm_bootup_init_apps(
	 mmi_event_struct *evt,
	 const vapp_bootup_init_table_entry_struct *table)
{
	 /*----------------------------------------------------------------*/
	 /* Local Variables 											   */
	 /*----------------------------------------------------------------*/
	 const vapp_bootup_init_table_entry_struct *entry;
	 
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	 MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_BOOTUP_INITS);
	 for (entry = table; entry->hdlr != NULL; entry++)
	 {
		 entry->hdlr(evt);
	 }
}


/*****************************************************************************
* FUNCTION
*  vapp_alarm_bootup_start
* DESCRIPTION
*  Start RTC booting flow.
*  This function is the handler of EVT_ID_SRV_REMINDER_BOOTUP_START.
* PARAMETERS
*  evt	 :[IN] mmi_event_struct*
* RETURNS
*  Always MMI_RET_OK
*****************************************************************************/
extern "C" mmi_ret vapp_alarm_bootup_start(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   */
	/*----------------------------------------------------------------*/
	mmi_event_struct rmdr_evt;
	const vapp_bootup_init_table_entry_struct *table;

	/*----------------------------------------------------------------*/
	/* Code Body													   */
	/*----------------------------------------------------------------*/
	MMI_ASSERT(evt != NULL);
	if (evt->evt_id != EVT_ID_SRV_REMINDER_BOOTUP_START)
	{
		return MMI_RET_OK;
	}
	MMI_TRACE(ALM_TRC_GRP, VAPP_ALM_BOOTUP_START);
	
	/* Init all related app. */
	MMI_FRM_INIT_EVENT(&rmdr_evt, EVT_ID_SRV_REMINDER_BOOTUP_INIT);  
	table = VAPP_BOOTUP_INIT_GET_TABLE(EVT_ID_SRV_REMINDER_BOOTUP_INIT);
	
	vapp_alarm_bootup_init_apps(&rmdr_evt, table);

	/* Notify bootup complete event */
	MMI_FRM_INIT_EVENT(&rmdr_evt, EVT_ID_SRV_REMINDER_BOOTUP_COMPLETE);
	MMI_FRM_CB_EMIT_EVENT(&rmdr_evt);

	return MMI_RET_OK;
}


