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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  AlarmSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Published interface of alarm service.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __ALARM_SRV_GPROT_H__
#define __ALARM_SRV_GPROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/
#include "mmi_frm_gprot.h"

#define  SRV_ALM_SNOOZE_INTERVAL  4

/*****************************************************************************
 * Typedef 
*****************************************************************************/

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_alm_search_funcptr
 * DESCRIPTION
 *  App who use alarm service can define search callback itself.
 *  Then, when search alarm, the callback will be called.
 * PARAMETERS
 *  void *		: [IN] Node address
 *  void *		: [IN] filter address
 * RETURNS
 * 	MMI_TRUE  : can be searched
 *	MMI_FALSE : cannot be searched
 *****************************************************************************/
typedef MMI_BOOL (*srv_alm_search_funcptr)(void *, void *);


/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_alm_cmp_funcptr
 * DESCRIPTION
 *  App who use alarm service can define cmpare callback itself.
 *  Then, when sort alarm, the callback will be called.
 * PARAMETERS
 *  U8 : [IN] Index 1
 *  U8 : [IN] Index 2
 *  MMI_BOOL : [IN] snooze or not
 * RETURNS
 * 	MMI_TRUE  : Index 1 >= Index 2
 *	MMI_FALSE : Index 1 < Index 2
 *****************************************************************************/
typedef MMI_BOOL (*srv_alm_cmp_funcptr)(U8, U8, MMI_BOOL);


/* alarm node type */
typedef alm_nvram_struct srv_alm_node_type;

/* Alarm operation type */
typedef enum{
	SRV_ALM_OP_ADD, /* Add. */
	SRV_ALM_OP_MODIFY, /* Modify. */
	SRV_ALM_OP_DELETE, /* Delete. */
	SRV_ALM_OP_TOTAL, /* End. */
}srv_alm_op_enum;

/* Alarm operation event type */
typedef struct
{
    MMI_EVT_PARAM_HEADER  /* Common para. */
	U8 index; /* Index of alarm. */
	U16 operation; /* Operation type. */
} srv_alm_op_evt_struct;

/*****************************************************************************
 * FUNCTION
 *  srv_alm_init
 * DESCRIPTION
 *  Init alarm data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_id srv_alm_init(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  srv_alm_read
 * DESCRIPTION
 *  Read out alarm data.
 * PARAMETERS
 *  index		:[IN]	alarm index
 * RETURNS
 *  srv_alm_node_type
 *****************************************************************************/
extern srv_alm_node_type *srv_alm_read(U8 index);


/*****************************************************************************
 * FUNCTION
 *  srv_alm_write
 * DESCRIPTION
 *  Read out alarm data.
 * PARAMETERS
 *	index	:[IN]	alarm index
 *	node	:[IN]	alarm data
 * RETURNS
 *  srv_alm_node_type
 *****************************************************************************/
extern void srv_alm_write(U8 index, void *node);

/*****************************************************************************
 * FUNCTION
 *  srv_alm_active_alms
 * DESCRIPTION
 *  Get active alarms.
 * PARAMETERS
 *  index		:[IN]	alarm index
 * RETURNS
 *  U8
 *****************************************************************************/
extern U8 srv_alm_active_alms(void);

/*****************************************************************************
 * FUNCTION
 *  srv_alm_get_info
 * DESCRIPTION
 *  This function is used to get alarm info.
 * PARAMETERS
 *  index         :[IN] alarm index.
 *  hour         :[out] alarm hour time.
 *  min          :[out] alarm min time.
 *  state       :[out] on/off state
 *  freq          :[OUT] alarm freq
 *  days          :[OUT] only used when freq is custom
 * RETURNS
 *  
 *****************************************************************************/
extern void srv_alm_get_info(U8 index, U8 *hour, U8 *min, U8 *state, U8 *freq, U8 *days);

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_get_alm_time
 * DESCRIPTION
 *  This function is used to get the next alarm.
 * PARAMETERS
 *  time         :[out] next alarm time.
 *  soonze       :[IN] whether care about soonze alarm
 * RETURNS
 *  MMI_BOOL    MMI_FALSE means there is no next alarm
 *****************************************************************************/
extern MMI_BOOL srv_alm_get_alm_time(MYTIME *ActualTime, U8 index, MMI_BOOL snooze);

/*****************************************************************************
 * FUNCTION
 *  mmi_alm_search
 * DESCRIPTION
 *  This function is used to get the next alarm.
 * PARAMETERS
 *	list		:[OUT]	output list
 *	size		:[IN]	list buffer size
 *	count     :[OUT]	real count
 *	filter		:[IN]	search filter, callback should know about the filter
 *	callback	:[IN]	search callback
 * RETURNS
 *  MMI_BOOL    MMI_FALSE means there is no next alarm
 *****************************************************************************/
extern void srv_alm_search(U8 *list, U8 size, U8 *count, void *filter, srv_alm_search_funcptr callback);


/*****************************************************************************
 * FUNCTION
 *  mmi_alm_sort
 * DESCRIPTION
 *  This function is used to get the next alarm.
 * PARAMETERS
 *  time         :[OUT] next alarm time.
 *  soonze       :[IN] whether care about soonze alarm
 * RETURNS
 *  MMI_BOOL    MMI_FALSE means there is no next alarm
 *****************************************************************************/
extern void srv_alm_sort(U8 *list, U8 len, MMI_BOOL snooze, srv_alm_cmp_funcptr callback);

/*****************************************************************************
 * FUNCTION
 *  srv_alm_get_index
 * DESCRIPTION
 *  get empty slot in alarm list
 * PARAMETERS
 *  void
 * RETURNS
 *  U8	alarm index, if no empty, it will return 0xFF
 *****************************************************************************/
extern U8 srv_alm_get_index(void);

/*****************************************************************************
 * FUNCTION
 *  srv_alm_reset_reminder
 * DESCRIPTION
 *  reset all reminder of alarm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_alm_reset_reminder(void);

/*****************************************************************************
 * FUNCTION
 *  srv_alm_pwr_reset
 * DESCRIPTION
 *  reboot phone after sec
 * PARAMETERS
 *  pwr_off	:[IN]
 *  sec		:[IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_alm_pwr_reset(MMI_BOOL pwr_off, U8 sec);

/*DOM-NOT_FOR_SDK-BEGIN*/
/*****************************************************************************
 * FUNCTION
 *  srv_alm_normal_reset
 * DESCRIPTION
 *  reboot phone after sec
 * PARAMETERS
 *  pwr_off	:[IN]
 *  sec		:[IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_alm_normal_reset(MMI_BOOL pwr_off, U8 sec);
/*DOM-NOT_FOR_SDK-END*/

#endif /* __ALARM_SRV_GPROT_H__ */


