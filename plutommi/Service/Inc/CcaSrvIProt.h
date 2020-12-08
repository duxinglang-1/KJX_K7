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
 *  CcaSrvIprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef SRV_CCA_IPROT_H
#define SRV_CCA_IPROT_H

/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Abbreviation                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"
#include "kal_general_types.h"

#include "MMIDataType.h"
#include "mmi_res_range_def.h"

#include "CcaSrvGprot.h"

#ifdef __MMI_CCA_SUPPORT__


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

/*----------------------------------------------------------------------------*/
/* Base type define                                                           */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constants                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/
typedef enum
{
    EVT_ID_SRV_CCA_NOTIFY = SRV_CCA_BASE + 10,
    EVT_ID_SRV_CCA_RECV_INVALID_MSG,
    EVT_ID_SRV_CCA_RECV_NEW_MSG,
    EVT_ID_SRV_CCA_VERIFY_PIN,

    EVT_ID_SRV_CCA_PRE_INSTALL,
    EVT_ID_SRV_CCA_POST_INSTALL,

    EVT_ID_SRV_CCA_INSTALL_FINISHED,
    
	EVT_ID_SRV_CCA_APP_MAX_ITEM
} srv_cca_evt_id_to_app_enum;


typedef enum
{
    SRV_CCA_NOTIFY_TYPE_MEM_FULL,
    SRV_CCA_NOTIFY_TYPE_INVALID_SETTING,
    SRV_CCA_NOTIFY_TYPE_NO_APP_SUPPORT,
    SRV_CCA_NOTIFY_TYPE_NOT_AVAILABLE,
    SRV_CCA_NOTIFY_TYPE_GET_MSG_FAIL,
    SRV_CCA_NOTIFY_TYPE_UPDATE_MSG_FAIL,
    
    SRV_CCA_NOTIFY_TYPE_MAX_ITEM
}srv_cca_notify_type_enum;

typedef enum
{
    SRV_CCA_VERIFY_PIN_STATUS_REQ,
    SRV_CCA_VERIFY_PIN_STATUS_MEM_FULL,
    SRV_CCA_VERIFY_PIN_STATUS_ABORT,
    SRV_CCA_VERIFY_PIN_STATUS_RETRY,
    SRV_CCA_VERIFY_PIN_STATUS_FAIL,
    SRV_CCA_VERIFY_PIN_STATUS_PASS,
    SRV_CCA_VERIFY_PIN_STATUS_MAX_ITEM
}srv_cca_verify_pin_status_enum;

typedef enum
{
    SRV_CCA_ACTION_TYPE_CANCEL_NEW_MSG,
    SRV_CCA_ACTION_TYPE_VIEW_NEW_MSG,
    SRV_CCA_ACTION_TYPE_PIN_INPUT,
    SRV_CCA_ACTION_TYPE_PIN_ABORT,
    SRV_CCA_ACTION_TYPE_START_INSTALL,
    SRV_CCA_ACTION_TYPE_INSTALL_COMPLETE,
    
    SRV_CCA_ACTION_TYPE_MAX_NUM
}srv_cca_action_type_enum;


typedef struct
{
    MMI_EVT_PARAM_HEADER                    /* Event parameter header */
    SRV_CCA_HANDLE h_cca;
    srv_cca_notify_type_enum type;
}srv_cca_evt_notify_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER                    /* Event parameter header */
    SRV_CCA_HANDLE h_cca;
    srv_cca_status_enum status;
    MMI_BOOL is_new_msg;
}srv_cca_evt_recv_invalid_msg_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER                    /* Event parameter header */
    SRV_CCA_HANDLE h_cca;
    MMI_BOOL is_msg_from_box;
    mmi_sim_enum sim_id;
}srv_cca_evt_recv_new_msg_struct;


typedef struct
{
    MMI_EVT_PARAM_HEADER                    /* Event parameter header */
    SRV_CCA_HANDLE h_cca;
    S32 max_attempts;                       /* Max attempts can be done */
    S32 cur_attempt;                        /* Current attempt */                        
    MMI_BOOL is_msg_from_box;
    srv_cca_verify_pin_status_enum status;
}srv_cca_evt_verify_pin_struct;


typedef struct
{
    MMI_EVT_PARAM_HEADER                    /* Event parameter header */
    SRV_CCA_HANDLE h_cca;
    S32 config_num;
    MMI_BOOL has_config_result;
    MMI_BOOL is_msg_from_box;
    srv_cca_status_enum msg_config_result;
    srv_cca_app_config_result_struct app_config_result[SRV_CCA_MAX_APPS];
}srv_cca_evt_pre_install_struct;


typedef struct
{
    MMI_EVT_PARAM_HEADER                    /* Event parameter header */
    SRV_CCA_HANDLE h_cca;
    S32 config_num;
    srv_cca_app_config_result_struct app_config_result[SRV_CCA_MAX_APPS];
    srv_cca_status_enum msg_config_result;
}srv_cca_evt_post_install_struct;


typedef struct
{
    MMI_EVT_PARAM_HEADER                    /* Event parameter header */
    SRV_CCA_HANDLE h_cca;
    MMI_BOOL is_msg_from_box;

}srv_cca_evt_install_finished_struct;


typedef struct
{
    MMI_EVT_PARAM_HEADER
    SRV_CCA_HANDLE h_cca;
    S32 sel_config_num;
    U16 sel_config_ids[SRV_CCA_MAX_APPS];
    MMI_BOOL has_selected;
}srv_cca_act_para_start_install_struct;



/*----------------------------------------------------------------------------*/
/* Typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Callback                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Export API                                                                 */
/*----------------------------------------------------------------------------*/
/* Init */
extern MMI_RET srv_cca_init(mmi_event_struct *evt);

extern MMI_BOOL srv_cca_is_busy(void);

extern srv_cca_status_enum srv_cca_set_event_proc(SRV_CCA_HANDLE h_cca, mmi_proc_func evt_proc, void* user_data);

extern srv_cca_status_enum srv_cca_apply_action(SRV_CCA_HANDLE h_cca, srv_cca_action_type_enum action_type, void *action_data, S32 action_data_size);

extern U32 srv_cca_get_unread_msg_num(U32 *sim_num_list, U32 sim_num, mmi_sim_enum *first_sim_id);


/*----------------------------------------------------------------------------*/
/* End                                                                        */
/*----------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif 
#endif


#endif /* SRV_CCA_IPROT_H */ 



