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
 *  vcui_dtcnt_select_gprot.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file define cui inferfaces for other app
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DTCNT_CUI_GPROT_H__
#define __VAPP_DTCNT_CUI_GPROT_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

//#include "mmi_rp_app_dtcnt_cui_def.h"
//#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "vfx_datatype.h"
//#include "vapp_dtcnt_def.h"
#include "vapp_dtcnt_gprot.h"
#include "mmi_frm_utility_gprot.h"



/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// select dtcnt options not include sim option(which will be set according another enum)
typedef enum
{
    CUI_DTCNT_SELECT_NONE = 0x00, // just for some app to assign initial value 0

    CUI_DTCNT_SELECT_SIM = 0x01, // not used in FTO
    
    CUI_DTCNT_SELECT_ALWAYS_ASK = 0x02, /* always ask turned on when compile option enabled, not turned on if undef */

    CUI_DTCNT_SELECT_DEFAULT = 0x03, // is the same with CUI_DTCNT_SELECT_ALWAYS_ASK

    CUI_DTCNT_SELECT_BEARER_SWITCH = 0x04, /* Not used in FTO. dual account support */

    CUI_DTCNT_SELECT_ALLOW_SAME_BEARER_SWITCH = 0x08, /* Not used in FTO. take effect on DTCNT_SELECT_BEARER_SWITCH set */  

    // can't choose http_only and wap_only at the same time  
    CUI_DTCNT_SELECT_CONNTYPE_HTTP_ONLY = 0x10, /* To show connection type HTTP only and filter out WAP */ 

    CUI_DTCNT_SELECT_CONNTYPE_WAP_ONLY = 0x20, /* To show connection type WAP only and filter out HTTP */ 

    CUI_DTCNT_SELECT_SIM_PROFILE = 0x40, /* sim provisioning prof will be display if turn on sim provisioning feature */

    CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT = 0x80, /* The user needs to call the function mmi_dtcnt_subscribe_account() to 
                                                        save the str_id and icon_id if the option is set. 
                                                      Note: If app process EVT_ID_SRV_DTCNT_ACCT_DELETE_IND, 
                                                      pls set this option to avoid register app info to data account */

    // can't set with_proxy_only and without_proxy_only as option value at the same time      
    CUI_DTCNT_SELECT_WITH_PROXY_ONLY = 0x100, /* filter for APP which need profile with proxy only */

    CUI_DTCNT_SELECT_WITHOUT_PROXY_ONLY = 0x200, /* filter for APP which need profile without proxy only */

    CUI_DTCNT_SELECT_END
} cui_dtcnt_select_option_enum;


// for support multi_card later, here we will use bit "or" to provide sim option
typedef enum
{
    CUI_DTCNT_SELECT_SIM1 = 0x01, /* choose account id for sim1 */
    
    CUI_DTCNT_SELECT_SIM2 = 0x02, /* choose account id for sim2 */

    CUI_DTCNT_SELECT_SIM3 = 0x04, /* choose account id for sim3 */

    CUI_DTCNT_SELECT_SIM4 = 0x08, /* choose account id for sim4 */

    CUI_DTCNT_SELECT_SIM_ALL = 0x0F, /* choose account id for all sim */

    CUI_DTCNT_SELECT_TOTAL
} cui_dtcnt_select_sim_enum;


/* dtcnt select type */
typedef enum
{                                                                                                 
     CUI_DTCNT_SELECT_TYPE_NORMAL, /* normal CUI, APP should use this type */ 
        
     CUI_DTCNT_SELECT_TYPE_CBM,    /* only CBM used CUI */ 
     
     CUI_DTCNT_SELECT_TYPE_TOTAL
} cui_dtcnt_select_type_enum;


/* Data account CUI event ID, success/cancel/fail/close */
typedef enum
{
    CUI_DTCNT_SELECT_EVENT_RESULT_OK = VCUI_DTCNT + 1, /* If user selected account and then press back key, send this event to APP's proc */

    CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL,    /* If user don't select account and press back key, send this event to APP's proc */

    CUI_DTCNT_SELECT_EVENT_RESULT_FAILED,    /* If APP fill wrong parameter to run CUI it will send this event */

    CUI_DTCNT_SELECT_EVENT_CLOSE,     /* If CUI's part screen closed abnormally not by user, send this event to APP's proc */

    /* CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED evt (added in COSMOS): 
       1. always send when user taps account list item; 
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
    CUI_DTCNT_SIM_TOTAL
} cui_dtcnt_sim_enum;


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
    VfxU32 accountId; // account value
} cui_dtcnt_select_event_any_sim_selected_struct;


/* Select account CUI parameter struct, used to customized data account selection CUI */
typedef struct
{ 
    U8 bearers;       /* account list bearer filter */
    U8 app_id;        /* APP ID of each APP */ 
    U16 icon_id;    /* APP icon id */
    U16 str_id;     /* APP string id */
    U32 sim_account_id[MMI_SIM_TOTAL];  /* sim account id, used to mark last time seleted, cbm not used */
    cui_dtcnt_select_option_enum option;   /* select option type */
    cui_dtcnt_select_type_enum type;     /* select CUI type */
    cui_dtcnt_select_sim_enum sim_selection;  /* SIM profile selection filter, , cbm not used */
} cui_dtcnt_select_run_struct;


/*******************************************************************************
* Export API 
*******************************************************************************/
#ifdef __cplusplus
extern "C" 
{
#endif

/* Create select CUI, data account CUI will support multi-instance */
mmi_id vcui_dtcnt_select_create(mmi_id parent_id);

/* Initialize CUI */
void vcui_dtcnt_select_set_param(mmi_id cui_id, cui_dtcnt_select_run_struct *p_args);

/* Execute CUI*/
void vcui_dtcnt_select_run(mmi_id cui_id);

/* Close CUI */
void vcui_dtcnt_select_close(mmi_id cui_id);

// add following api to support redraw for application which changes account id by provisioning
void vcui_dtcnt_select_set_account_id(mmi_id cui_id, cui_dtcnt_sim_enum sim, U32 accountId);

#ifdef __cplusplus
}
#endif


#endif /* __VAPP_DTCNT_CUI_GPROT_H__ */
