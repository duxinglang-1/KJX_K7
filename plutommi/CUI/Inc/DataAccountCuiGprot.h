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
 *   DataAccountCuiGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Data Account Common UI header file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef CUI_DTCNT_GPROT_H
#define CUI_DTCNT_GPROT_H

/*******************************************************************************
* Include Header File
*******************************************************************************/

#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "mmi_frm_utility_gprot.h"


// need remove later when all plutommi code removed
#if defined(__COSMOS_MMI_PACKAGE__)
#ifndef DATA_ACCOUNT_BASE
#define DATA_ACCOUNT_BASE VAPP_DTCNT
#endif
#endif

/*******************************************************************************
* Enum Define
*******************************************************************************/
typedef enum
{
    CUI_DTCNT_SELECT_NONE = 0x00, // just for some app to assign initial value 0

    CUI_DTCNT_SELECT_SIM = 0x01, /* Not useful. single sim: single, no select sim screen,  dual sim: select sim1 / sim2 screen */
                             /* not turned on:     select SIM1 only  */
    CUI_DTCNT_SELECT_ALWAYS_ASK = 0x02, /* always ask turned on when compile option enabled, not turned on if undef */

    CUI_DTCNT_SELECT_DEFAULT = 0x03,  /* single sim:  single, no select sim screen,  dual sim: select sim1/sim2 screen */
                                  /* always ask : allowed if compile option turned on */
    CUI_DTCNT_SELECT_BEARER_SWITCH = 0x04, /* Not useful. dual account support */
    
    CUI_DTCNT_SELECT_ALLOW_SAME_BEARER_SWITCH = 0x08, /* Not useful. take effect on DTCNT_SELECT_BEARER_SWITCH set */

    // can't set http_only and wap_only as option value at the same time  
    CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY = 0x10, /* To show connection type HTTP only and filter out WAP */ 

    CUI_DTCNT_SELECT_CONNTYPE_WAP_ONLY = 0x20, /* To show connection type WAP only and filter out HTTP */ 

    CUI_DTCNT_SELECT_SIM_PROFILE = 0x40,

    CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT = 0x80, /* Not useful. The user needs to call the function mmi_dtcnt_subscribe_account() to save the str_id and icon_id if the option is set */

    CUI_DTCNT_SELECT_HIDE_AUTOMATIC_ACCOUNT = 0x1000, /* Not useful. use this option to hide automatic account */

    // can't set with_proxy_only and without_proxy_only as option value at the same time      
    CUI_DTCNT_SELECT_WITH_PROXY_ONLY = 0x200, /* filter for APP which need profile with proxy only */

    CUI_DTCNT_SELECT_WITHOUT_PROXY_ONLY = 0x400, /* filter for APP which need profile without proxy only */

    CUI_DTCNT_SELECT_END   /* total enum */
} cui_dtcnt_select_option_enum;

/* CUI type */
typedef enum                                                                            
{                                                                                                 
     CUI_DTCNT_SELECT_TYPE_NORMAL, /* normal CUI, APP should use this type */ 
     CUI_DTCNT_SELECT_TYPE_CBM,    /* only CBM used CUI */ 
     CUI_DTCNT_SELECT_TYPE_TOTAL
}cui_dtcnt_select_type_enum;

/* SIM profile selection filter */ 
typedef enum                                                                            
{                                                                                                 
     CUI_DTCNT_SELECT_SIM1,   /* SIM1 for display SIM1 profile only */ 
     CUI_DTCNT_SELECT_SIM2,   /* SIM2 for display SIM2 only */
     CUI_DTCNT_SELECT_SIM3,   /* SIM3 for display SIM3 only */
     CUI_DTCNT_SELECT_SIM4,   /* SIM4 for display SIM4 only */
     CUI_DTCNT_SELECT_DUAL_SIM,    /* keep it because most app use it before, it is the same to CUI_DTCNT_SELECT_SIM_ALL */
     CUI_DTCNT_SELECT_SIM_ALL = CUI_DTCNT_SELECT_DUAL_SIM,   /* ALL sim */
     CUI_DTCNT_SELECT_TOTAL
}cui_dtcnt_select_sim_enum;

/* Data account CUI event ID, only 3 types: success/cancel/fail/close now */
typedef enum
{
    CUI_DTCNT_SELECT_EVENT_RESULT_OK = DATA_ACCOUNT_BASE, /* If user selected an account and press OK, send this event to APP's proc */
    CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL,    /* If user press cancel, send this event to APP's proc */
    CUI_DTCNT_SELECT_EVENT_RESULT_FAILED,    /* If APP fill wrong parameter to run CUI it will send this event */
    CUI_DTCNT_SELECT_EVENT_CLOSE,            /* If CUI's part screen closed abnormally not by user, send this event to APP's proc */

    /* CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED evt (added for Pluto also): 
       1. always send when user select account list item; 
       2. maybe send many times before send CUI_DTCNT_SELECT_EVENT_RESULT_OK; 
       3. app can't close DA cui when process CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED evt */
    CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED,
    CUI_DTCNT_SELECT_EVENT_TOTAL
} cui_dtcnt_select_event_enum;


//this is used for getting sim related account in data account evt. 
typedef enum
{
    CUI_DTCNT_SIM1 = 0,
    CUI_DTCNT_SIM2,
    CUI_DTCNT_SIM3,
    CUI_DTCNT_SIM4,
    CUI_DTCNT_SIM_TOTAL // It isn't useful, just a enum end value.
} cui_dtcnt_sim_enum;


/*******************************************************************************
* Structure Define
*******************************************************************************/

/* [Remove later] Just use to make build succussful, not useful. Select account CUI event struct */
typedef struct    
{
    MMI_EVT_GROUP_PARAM_HEADER   /* screen group standard header */
    U32 account_id;     /* the selected account ID */
} cui_dtcnt_select_event_struct;

/* select account CUI event struct for 
    CUI_DTCNT_SELECT_EVENT_RESULT_OK,
    CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL,
    CUI_DTCNT_SELECT_EVENT_RESULT_FAILED,
    CUI_DTCNT_SELECT_EVENT_CLOSE,
    when receive these event, app need to close data account CUI */
typedef struct  
{
    MMI_EVT_GROUP_PARAM_HEADER   /* screen group standard header */
} cui_dtcnt_select_event_result_struct;


/*  select account CUI event struct for 
    CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED,  
    selectSim: will be CUI_DTCNT_SIM1/2/3/4 to indicate the account value related to which sim; 
    accountId: selected account value,
    when receive this event, app need to store the selected account */
typedef struct  
{
    MMI_EVT_GROUP_PARAM_HEADER   /* screen group standard header */
    cui_dtcnt_sim_enum selectSim; // sim indication
    U32 accountId; // account value
} cui_dtcnt_select_event_any_sim_selected_struct;


/* Select account CUI parameter struct, used to customized data account selection CUI */
typedef struct
{ 
    U8 bearers;       /* account list bearer filter */
    U8 app_id;        /* APP ID of each APP */
    U16 AppMenuID;  /* APP MENU ID */  
    U16 icon_id;    /* APP icon id */
    U16 str_id;     /* APP string id */
    U32 account_id;      /* [Remove later] just for build successful, not useful */  
    U32 sim_account_id[MMI_SIM_TOTAL];      /* set initial account ids to display in CUI */  
    cui_dtcnt_select_option_enum option;   /* select option type */
    cui_dtcnt_select_type_enum type;     /* select CUI type */
    cui_dtcnt_select_sim_enum sim_selection;  /* SIM profile selection filter */
} cui_dtcnt_select_run_struct;


/*******************************************************************************
* Macro Define
*******************************************************************************/


/*******************************************************************************
* Export API 
*******************************************************************************/
/* Create select CUI, data account CUI will support multi-instance */
extern mmi_id cui_dtcnt_select_create(mmi_id parent_gid);

/* Initialize CUI */
extern void cui_dtcnt_select_set_param(mmi_id cui_gid, cui_dtcnt_select_run_struct *p_args);

/* Execute CUI*/
extern void cui_dtcnt_select_run(mmi_id cui_gid);

/* Close CUI */
extern void cui_dtcnt_select_close(mmi_id cui_gid);
#endif /* CUI_DTCNT_GPROT_H */ 

