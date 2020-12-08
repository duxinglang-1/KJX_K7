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
 * WAPPushSrvGProts.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file have the declaration of internally used function.
 *
 * Author:
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __WAP_PUSH_SRV_GPROT__
#define __WAP_PUSH_SRV_GPROT__
#include "MMI_features.h"
#ifdef WAP_SUPPORT

#include "pmg_struct.h" /* For Accessing Pmg Structures */
#include "WAPProfileSrvType.h"
/* This enum is used to define async notification events to Push application by Push application service */
typedef enum
{
    EVT_ID_SRV_PUSH_ERROR_IND = SRV_PUSH_BASE + 1,  /* Notify Push app for some error indication  */
    EVT_ID_SRV_PUSH_SHOW_PROGRESS,                      /* Notify Push app for showing progress screen*/
    EVT_ID_SRV_PUSH_SHOW_POPUP,                         /* Notify Push app for showing pop-up screen  */
    EVT_ID_SRV_PUSH_HANDLE_NEW_SERVICE_MSG,             /* Notify Push app for handling new service msg */
    EVT_ID_SRV_PUSH_MSG_DELETED_BY_SERVER_IND,          /* Notify Push app for handling delete indication by server */
    EVT_ID_SRV_PUSH_DELETE_PUSH_SETTING,                /* Notify Push app for deleting push setting screens */
    EVT_ID_SRV_PUSH_OTA_LIST_ENTRY,                     /* Notify Push app for entry in OTA list */
    EVT_ID_SRV_PUSH_HANDLE_FULL_MSG,                    /* Notify Push app for handling full message from PMG */
    EVT_ID_SRV_PUSH_LAUNCH_SL,                          /* Notify Push app for launching SL */
    EVT_ID_SRV_PUSH_HANDLE_SL_NON_IDLE,                 /* Notify Push app for handling SL on non-idle */
    EVT_ID_SRV_PUSH_HANDLE_SL_IDLE,                     /* Notify Push app for handling SL on idle screen */
    EVT_ID_SRV_PUSH_MSG_LIST_REPLY,                     /* Notify Push app for handling message list from PMG */
    EVT_ID_SRV_PUSH_MSG_COUNT_RSP,                      /* Notify Push app for handling message count response from PMG */
    EVT_ID_SRV_PUSH_DRAW_UNKNOWN,                       /* Notify Push app for drawing unknown message confirmation screen */
    EVT_ID_SRV_PUSH_SERVICE_INIT,                       /* Notify Push app for initializing dialog */
    EVT_ID_SRV_PUSH_HANDLE_DLG_DATA_RSP,                /* Notify Push app for handling confirmation of dlg query from PMG */
    EVT_ID_SRV_PUSH_HANDLE_STORAGE_FULL_IND,            /* Notify Push app for handling storage full indication */
    EVT_ID_SRV_PUSH_HANDLE_DELETE_FOLDER_IND,           /* Notify Push app for handling delete folder indication */
    EVT_ID_SRV_PUSH_HANDLE_PENDIG_EVENT_ON_IDLE,        /* Notify Push app for handling any pending event on idle */ 
    EVT_ID_SRV_PUSH_FETCH_DLG_QUEUE,                    /* Notify Push app for fetching dialogue from message queue */
    EVT_ID_SRV_PUSH_INBOX_INIT,                         /* Notify Push app for initializing UI */
    EVT_ID_SRV_PUSH_DISPLAY_MSG,                        /* Notify Push app for displaying message body */
    EVT_ID_SRV_PUSH_UNKNOWN_ADDR_REQ,                   /* Notify Push app for unknown address request */
    EVT_ID_SRV_PUSH_PMG_ERROR_DLG_IND,                   /* Notify Push app for unknown address request */
    EVT_ID_SRV_PUSH_DISPLAY_ERROR_DLG,                   /* Notify Push app for display error dlg */
    EVT_ID_SRV_PUSH_PROCESS_DELETE_MSG_RSP,              /* Notify Push app for deletion of msg response from PMG */  
    EVT_ID_SRV_PUSH_PROCESS_DELETE_ALL_MSG_RSP,          /* Notify Push app for deletion of all msg reponse from PMG */
    EVT_ID_MMI_UM_DELETE_ALL_RES,                        
    EVT_ID_MMI_UM_ENTRY_MARK_SEVERAL_RSP,
    EVT_ID_SRV_PUSH_PROV_CUI_CREATE,
    EVT_ID_SRV_PUSH_PROV_CUI_REDISPLAY,
    EVT_ID_SRV_PUSH_END
} srv_wap_push_event_enum;

/* DOM-NOT_FOR_SDK-BEGIN */


/* Response status type */
typedef enum
{
  SRV_WAP_PUSH_STATUS_OK,      /* Request completed successfully */
   SRV_WAP_PUSH_STATUS_FAIL,    /* Request completed in failure */
   SRV_WAP_PUSH_STATUS_NOT_FOUND    /* Request completed in failure due to message not found */
} srv_wap_push_msg_read_status_enum;



/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_check_pendig_event_on_idle
 * DESCRIPTION
 *  This function is an external interface for checking any pending event  
 *  on idle
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
extern U8 srv_wap_push_check_pendig_event_on_idle(void);

/*****************************************************************************
Callback function for srv_wap_push_update_all_service_msg_req
 
*****************************************************************/

typedef void (*srv_wap_push_update_all_read_callback_func) (srv_wap_push_msg_read_status_enum status_result , void* user_data);

/*****************************************************************************
Callback function for srv_wap_push_update_all_service_msg_req
 
*****************************************************************/

typedef void (*srv_wap_push_get_msg_content_callback_func) (pmg_detailed_msg_struct *msg_content ,kal_int8* url , void* user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_get_msg_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id        [OUT]
 *  call_back      [OUT]
 * RETURNS
 *  void
 *****************************************************************************/

extern void srv_wap_push_get_msg_content(U32 msg_id, srv_wap_push_get_msg_content_callback_func callback, void* user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_handle_pendig_event_on_idle
 * DESCRIPTION
 *  This function is an external interface to be registered at idle for  
 *  handling any pending event on idle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wap_push_handle_pendig_event_on_idle(void);

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_service_dlg_idle_scr_cb
 * DESCRIPTION
 *  This function is used for testing whether any dialogue screen to show
 *  at idle
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
extern U8 srv_wap_push_service_dlg_idle_scr_cb(void);

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_fetch_dlg_from_queue
 * DESCRIPTION
 *  This function is an external interface for fetching infomration for dialogue  
 *  at idle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wap_push_fetch_dlg_from_queue(void);

/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_msg_read_status
 * DESCRIPTION
 *  This function gets the read status of msg_id specific message
 * PARAMETERS
 *  U32 (msg_id)
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/

extern MMI_BOOL srv_wap_push_msg_read_status (U32);
/*****************************************************************************
 * FUNCTION
 *  srv_get_push_unread_count
 * DESCRIPTION
 *  This function gets unread count of push messages  
 *  on idle
 * PARAMETERS
 *  void
 * RETURNS
 *  U32
 *****************************************************************************/
extern U32 srv_get_push_unread_count(void);

/*****************************************************************************
 * FUNCTION
 *  srv_wap_push_update_all_service_msg_req
 * DESCRIPTION
 *  This function set all unread message to read  
 *  on idle
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/

extern void srv_wap_push_update_all_service_msg_req(srv_wap_push_update_all_read_callback_func callback_func , void* user_data);
extern void srv_wap_push_active_profile_changed_hdlr(srv_wap_prof_profile_content_struct *profile_content_p, srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_response_funcptr_type callback);

#endif /* WAP_SUPPORT */
#endif /* __WAP_PUSH_SRV_GPROT__ */
