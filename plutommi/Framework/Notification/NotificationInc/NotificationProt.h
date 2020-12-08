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
 * NotificationProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef NOTIFICATIONPROT_H
#define NOTIFICATIONPROT_H
/***************************************************************************** 
 * Header file
 *****************************************************************************/
#include "custom_events_notify.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_DEFER_NOTIFICATION_NUM  5

#define MMI_FRM_NMGR_ALERT_POPUP_ALL_TYPE (2)


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/*Internal event usage*/
typedef enum
{
    EVT_ID_DO_PREVIEW,
    EVT_ID_CANCEL_PREVIEW,
    EVT_ID_DO_ALERT,
    EVT_ID_CANCEL_ALERT, 
    EVT_ID_NMGR_INTERNAL_EVT_MAX
} mmi_nmgr_internal_evt_enum;

/* Behavior of each attribute */
typedef enum
{
    /* Screen */
    MMI_NOTI_SCRN_BEHA_DISPLAY,
    MMI_NOTI_SCRN_BEHA_NO_DISPLAY,

    /* Sound */    
    MMI_NOTI_SND_BEHA_PALY,
    MMI_NOTI_SND_BEHA_NO_PLAY,

    /* Vibrator */
    MMI_NOTI_VIB_BEHA_USE,
    MMI_NOTI_VIB_BEHA_NO_USE,

    /* Backlight */
    MMI_NOTI_BL_BEHA_PREEMPT,
    MMI_NOTI_BL_BEHA_NO_PREEMPT,

    MMI_NOTI_BEHA_END
} mmi_noti_attr_beha_enum;

/* Internal attribute behavior decided by priority information. */
typedef struct
{
    mmi_noti_attr_beha_enum scrn_behavior;
    mmi_noti_attr_beha_enum snd_behavior;
    mmi_noti_attr_beha_enum vib_behavior;
    mmi_noti_attr_beha_enum bl_behavior;
} mmi_app_behavior_struct;

/* External attribute behavior decided by user configuration info in mmi_events_notify_tbl. */
typedef struct
{
    mmi_nmgr_behavior_enum scrn_action;
    mmi_nmgr_behavior_enum snd_action;
    mmi_nmgr_behavior_enum vib_action;
    mmi_nmgr_behavior_enum bl_action;
} mmi_attribute_action_struct;

typedef struct
{
    mmi_scenario_id noti_scen_id;
    WCHAR *string;
    mmi_event_notify_enum notify_type;
} mmi_nmgr_popup_scrn_arg_struct;

typedef struct
{    
    mmi_scenario_id scen_id;
    mmi_scen_attr_prio_enum scrn_attr_prio;
    mmi_noti_scrn_func_ptr scrn_entry_cb;
    void *arg;
    mmi_frm_nmgr_alert_struct popup_info;
} mmi_defer_item_struct;

typedef struct
{
    mmi_defer_item_struct data[MMI_DEFER_NOTIFICATION_NUM];     /* Only high & media scenario could be deferred */
    U16 priority_flag;                                          /* Each bit present if deferred scenario's priority is high */
    U8 used;
} mmi_defer_info_struct;

/***************************************************************************** 
 * Extern Global Function
 *****************************************************************************/

#endif /* NOTIFICATIONPROT_H */

