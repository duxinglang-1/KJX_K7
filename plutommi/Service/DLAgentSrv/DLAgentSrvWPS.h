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
 *
 *
 * Project:
 * --------
 *  MAUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
  ****************************************************************************/

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#ifndef DOWNLOAD_AGENT_APP_ADP_H
#define DOWNLOAD_AGENT_APP_ADP_H

//#ifdef __COSMOS_MMI_PACKAGE__

//#include "Wap_ps_struct.h"

#ifndef DOWNLOAD_AGENT_DEF_H
#include "DLAgentSrvDef.h"
#endif
#include "DLAgentSrvGprot.h"
#if defined(__MMI_DOWNLOAD_AGENT__) && (defined(BROWSER_SUPPORT) || defined(__MMI_OMA_DD_DOWNLOAD__))
#define __MMI_DA_WPS_UTIL__
#endif

    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "wps_struct.h"
    #include "BrowserSrvGprot.h"


#ifdef __HTTP_INTERFACE__

/****************************************************************************
 * Constants
 *****************************************************************************/

/*
 * Default timeout in seconds for no response from server.
 */
#define SRV_DA_WPS_DEFAULT_TIMEOUT  90 /* sec */

/*
 * Timeout in seconds for no response from server when send OMA reports.
 */
#define SRV_DA_OMA_REPORT_TIMEOUT   5  /* sec */


#define SRV_DA_WPS_INVALID_SESSION  (NULL)
#define SRV_DA_WPS_DEFAULT_CHANNEL  (NULL)

#ifdef __MMI_DA_OMADL_CUST_CHL_SUPPORT__
#define SRV_DA_WPS_MAX_CUST_SESSION      2
#else
#define SRV_DA_WPS_MAX_CUST_SESSION      0
#endif

/* The number of session slot should be enough to be successfully allocated */
#define SRV_DA_WPS_MAX_SESSION      (8 + SRV_DA_WPS_MAX_CUST_SESSION)


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef void *srv_da_wps_session_handle;
typedef void *srv_da_wps_channel_handle;

typedef enum
{
    SRV_DA_WPS_SETTING_DEFAULT,
    SRV_DA_WPS_SETTING_OMA_REPORT,

    SRV_DA_WPS_SETTING_END_OF_ENUM
} srv_da_wps_setting_enum;

typedef enum
{
    SRV_DA_WPS_OPTION_UNBUFFERED_WRITE,

    SRV_DA_WPS_OPTION_END_OF_ENUM
} srv_da_wps_option_enum;

typedef void (*srv_da_wps_session_created_funcptr_type)(MMI_BOOL success, U32 arg);

typedef void (*srv_da_wps_http_response_funcptr_type)(
    U32 arg,
    U8 result,
    U16 status,
    S8 *header,
    S8 *content_type,
    U32 content_len,
    const wps_http_rsp_struct *rsp);
    
typedef void (*srv_da_wps_http_auth_ind_funcptr_type)(U32 arg);
typedef void (*srv_da_wps_dl_progress_funcptr_type)(U32 arg, U8 status, U32 curr_size, S32 cause);
typedef void (*srv_da_wps_session_aborted_funcptr_type)(U32 arg);

typedef enum
{
    SRV_DA_WPS_SESSION_STATE_READY = 0,
    SRV_DA_WPS_SESSION_STATE_POSTING,
    SRV_DA_WPS_SESSION_STATE_DOWNLOADING,
    SRV_DA_WPS_SESSION_STATE_ABORTING,
    SRV_DA_WPS_SESSION_STATE_INIT,
    
    SRV_DA_WPS_SESSION_STATE_END_OF_ENUM
} srv_da_wps_session_state_enum;

typedef enum
{
    SRV_DA_WPS_CHANNEL_STATE_FREE = 0,
    SRV_DA_WPS_CHANNEL_STATE_IN_SETTING,
	SRV_DA_WPS_CHANNEL_STATE_IN_AUTHENTICATING,
    SRV_DA_WPS_CHANNEL_STATE_IN_UNSETTING,


    MMI_DA_WPS_STATE_END_OF_ENUM
} srv_da_wps_channel_state_enum;

/****************************************************************************
* Typedef - Struct
*****************************************************************************/

typedef struct srv_da_wps_channel_struct_s
{
    MMI_BOOL    is_set;  // channel is set or not.
    MMI_BOOL    is_reserved; /* If not reserved by any client, we can unset the channel after session closed */
    srv_da_wps_channel_state_enum busy_flag;  // during set/unset channel
    U8      channel_id;
    U8      ref_count;
    U32     request_id;
    wps_set_channel_req_struct *cust_ch_req;

    U32 curr_account_id;


    /* NOTE: ref_count & msg_len will be cleaned by this function */
    void (*get_set_channel_req)(
		void *session,
        struct srv_da_wps_channel_struct_s *channel,
        wps_set_channel_req_struct *set_channel_req);
} srv_da_wps_channel_struct;


typedef struct
{
    U16 id;             /* Unique ID to distinguish sessions */
    U16 session_idx;    /* Index of da_wps_context.session_table[] */
    U8  request_id;
    MMI_BOOL unbuffered_write;
    srv_da_wps_channel_struct  *channel;

    /* run-time */
    srv_da_wps_session_state_enum state;

    /* Client infomation */
    U32                                     arg;
	U32										time_stamp1;
	U32										time_stamp2;
	U32										acc_size;
    srv_da_wps_session_created_funcptr_type create_cb;
    srv_da_wps_http_response_funcptr_type   http_rsp_cb;
    srv_da_wps_http_auth_ind_funcptr_type   http_auth_cb;
    srv_da_wps_dl_progress_funcptr_type     dl_progress_cb;
    srv_da_wps_session_aborted_funcptr_type abort_cb;
    
} srv_da_wps_session_struct;


typedef struct
{
    srv_da_wps_channel_struct dl_channel;
    srv_da_wps_channel_struct post_channel;

#ifdef __MMI_DA_OMADL_CUST_CHL_SUPPORT__
    srv_da_wps_channel_struct cust_ch[SRV_DA_WPS_MAX_CUST_SESSION];
#endif
    
    U8                        session_num;
    srv_da_wps_session_struct *session_table[SRV_DA_WPS_MAX_SESSION];

    MMI_BOOL                active_download;
    U8                      cbm_app_id;
	srv_da_wps_setting_enum setting_type;

    U16                             cbm_grp_id;    
    U16                             cbm_cui_id;
    U32                             acc_id;
	U8                      cbm_app_id1;
	U8                      cbm_app_id2;
    srv_da_switch_current_bearer_enum  cbm_bearer_type;

  
} srv_da_wps_context_struct;

#else /* __HTTP_INTERFACE__ */

typedef struct
{
    U8                      cbm_app_id;
#ifdef MMI_DA_WLAN_PREFER_SUPPORT
    U16                             cbm_grp_id;    
    U16                             cbm_cui_id;
    U32                             acc_id;
    srv_da_switch_current_bearer_enum  cbm_bearer_type;
#endif /* MMI_DA_WLAN_PREFER_SUPPORT */
} srv_da_wps_context_struct;

/****************************************************************************
 * Global Functions
 ****************************************************************************/
#endif

#ifdef __MMI_DA_WPS_UTIL__

extern void srv_da_wps_init(void);

#ifdef __HTTP_INTERFACE__

extern srv_da_wps_session_handle srv_da_wps_create_session(
    U32 arg,
    srv_da_wps_setting_enum setting,
    srv_da_wps_session_created_funcptr_type callback1,
    srv_da_wps_http_response_funcptr_type callback2,
    srv_da_wps_http_auth_ind_funcptr_type callback3,
    srv_da_wps_dl_progress_funcptr_type callback4);

extern MMI_BOOL srv_da_wps_http_req(srv_da_wps_session_handle session, 
                                U8 method,
                                S8 *url,
                                S8 *header,
                                S8 *post_data,
                                U16 *filepath,
                                U8 reply_type);

extern MMI_BOOL srv_da_wps_session_auth(srv_da_wps_session_handle session, U8 *username, U8 *password);
extern MMI_BOOL srv_da_wps_session_auth_UCS2(srv_da_wps_session_handle session, U16 *username, U16 *password);
extern MMI_BOOL srv_da_wps_send_dl_progress_res(srv_da_wps_session_struct *session, S32 seq_num, wps_dl_status_enum status, kal_wchar *filepath, kal_uint32 dl_buff_len, kal_uint8 *dl_buff);

extern void srv_da_wps_close_session(srv_da_wps_session_handle session,
                                     srv_da_wps_session_aborted_funcptr_type callback5);

extern S16 srv_da_wps_get_session_id(srv_da_wps_session_handle session);

extern void srv_da_wps_notify_active_downloads(MMI_BOOL active_download);

extern srv_da_wps_channel_handle srv_da_wps_reserve_cust_channel(wps_set_channel_req_struct *ch_req);
extern MMI_BOOL srv_da_wps_release_channel(srv_da_wps_channel_handle channel_hdlr);

extern srv_da_wps_session_handle srv_da_wps_create_session_ex(
    U32 arg,
    srv_da_wps_setting_enum setting,
    srv_da_wps_channel_handle cust_channel,
    srv_da_wps_session_created_funcptr_type create_cb,
    srv_da_wps_http_response_funcptr_type http_rsp_cb,
    srv_da_wps_http_auth_ind_funcptr_type http_auth_cb,
    srv_da_wps_dl_progress_funcptr_type dl_progress_cb);

extern void srv_da_wps_session_set_option(
    srv_da_wps_session_handle session,
    srv_da_wps_option_enum option,
    void *value_p);
extern srv_da_error_enum srv_da_wps_map_error_code(S32 wps_error_code);
extern U32 srv_da_wps_estimate_time_to_download_by_channel(U32 arg, srv_da_wps_channel_handle cust_channel, U32 filesize);
extern void srv_da_wps_register_bearer_fallback(U8 app_id);
extern void srv_da_wps_set_cbm_id (U8 app_id, U32 cbm_id);
extern U8 srv_da_wps_get_cbm_id (U8 cbm_id);
extern mmi_ret srv_da_wps_nwk_fsm_bearer_info_ind(mmi_event_struct *evt);
#endif /* __HTTP_INTERFACE__ */

extern MMI_BOOL srv_da_wps_is_bearer_activated(U32 arg);
extern U32 srv_da_wps_estimate_time_to_download(U32 arg, MMI_BOOL da_account_first, U32 filesize);
extern void srv_da_wps_reset_cbm_app_id(U8 app_id);

#endif /* __MMI_DA_WPS_UTIL__ */




//#endif /* __COSMOS_MMI_PACKAGE__ */
#endif /* DOWNLOAD_AGENT_APP_ADP_H */

