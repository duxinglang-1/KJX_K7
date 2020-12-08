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
 * WAPProfileSrvType.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines the structures ,enum,varaibles etc used by WAP_PROF profile module.
 *
 * Author: Ramneek Kalra
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
#ifndef _WAPPROFILESRVTYPE_H
#define _WAPPROFILESRVTYPE_H

#include "MMI_features.h"
#include "MMIDataType.h"
//#include "custom_nvram_editor_data_item.h"
#include "common_nvram_editor_data_item.h"

#include "browser_api.h"

#ifdef WAP_SUPPORT

#ifdef __MMI_CCA_SUPPORT__
#define PROV_SUPPORT
#endif

#ifdef __MMI_WAP_UPP_SLIM__
#define __SRV_UPP_SLIM__
#endif

 #include "WAPProfSrvconfig.h" 

/* Defines */
#define SRV_WAP_PROF_TRC_GRP9                       TRACE_GROUP_9
#define SRV_WAP_PROF_MOD_INET_APP                   MOD_MMI_INET_APP
#define SRV_WAP_PROF_TRACE_STRING_LEN               NVRAM_WAP_PROF_URL_LEN * 4




#define SRV_WAP_PROF_MAX_SIM_PROFILES         3



#define SRV_WAP_PROF_MAX_PROXY_ADDR_LEN				CUSTOM_MAX_PROXY_ADDR_LEN
#define SRV_WAP_PROF_DEFAULT_PROXY_URL				""
#define SRV_WAP_PROF_DEFAULT_URL                       "http://"
#define SRV_WAP_PROF_DEFAULT_URL_SIZE              strlen(SRV_WAP_PROF_DEFAULT_URL)
#define SRV_WAP_PROF_DEFAULT_USERNAME              ""
#define SRV_WAP_PROF_DEFAULT_PASSWORD              ""
#define SRV_WAP_PROF_DEFAULT_IP1                   0
#define SRV_WAP_PROF_DEFAULT_IP2                   0
#define SRV_WAP_PROF_DEFAULT_IP3                   0
#define SRV_WAP_PROF_DEFAULT_IP4                   0
#define SRV_WAP_PROF_DEFAULT_PORT                  0
#define SRV_WAP_PROF_INVALID_CONTENT_INDEX         99
#define SRV_WAP_PROV_MAX_BOOKMARK_TITLE_LEN          NVRAM_WAP_PROF_PROFILE_NAME_LEN
#define SRV_WAP_PROV_MAX_BOOKMARK_URL_LEN         NVRAM_WAP_PROF_URL_LEN
#define SRV_WAP_PROV_MAX_MMS_SETTING_VALUE_SIZE     40
#define SRV_WAP_PROF_SIM_TOTAL MMI_MAX_SIM_NUM  



/* enum for DCS. */
typedef enum
{
    SRV_WAP_PROF_DCS_ASCII,
    SRV_WAP_PROF_DCS_UCS2,

    /* Add above this. */
    SRV_WAP_PROF_DCS_END
} srv_wap_prof_dcs_enum;


/*Enum for STRING IDs */
typedef enum
{
	SRV_WAP_PROF_GLOBAL_NOT_AVAILABLE,
	SRV_WAP_PROF_GLOBAL_MULTIMEDIA_MESSAGE,
	SRV_WAP_PROF_CBM_BROWSER,
	SRV_WAP_PROF_DTCNT_ALREADY_CONFIGURED,

    /* Add above this. */
	SRV_WAP_PROF_STR_END
}srv_wp_prof_str_enum;

/*Enum for IMAGE IDs */
typedef enum
{
	SRV_WAP_PROF_GLOBAL_WEB_BROWSER_CSK,
	SRV_WAP_PROF_GLOBAL_COMMON_CSK,

    /* Add above this. */
	SRV_WAP_PROF_IMG_END

}srv_wp_prof_img_enum;


/* Enum for results */
typedef enum
{
    SRV_WAP_PROF_SUCCESS,
    SRV_WAP_PROF_ERR,
    SRV_WAP_PROF_MEM_FULL_ERR,
    SRV_WAP_PROF_URL_VALIDATION_ERR,
    SRV_WAP_PROF_BKM_TITLE_ERR,
    SRV_WAP_PROF_ACCESS_DENIED_ERR,
    SRV_WAP_PROF_NOT_FOUND_ERR,
    /* Internal error numbers. */
    SRV_WAP_PROF_INVALID_PORT_ERR,
    SRV_WAP_PROF_INVALID_IP_ERR,
    SRV_WAP_PROF_EMPTY_PORT_NUMBER_ERR, /* MAUI_01356886 */
    SRV_WAP_PROF_CURRENTLY_NOT_AVAILABLE_ERR,

    /* Add above this */
    SRV_WAP_PROF_RESULT_END
} srv_wap_prof_result_enum;

/* Enum for SIMID */
typedef enum
{
    SRV_WAP_PROF_SIMID_DEFAULT,
    SRV_WAP_PROF_SIMID_SIM1 = SRV_WAP_PROF_SIMID_DEFAULT,
#if (MMI_MAX_SIM_NUM >= 2) 
    SRV_WAP_PROF_SIMID_SIM2,
#endif
#if (MMI_MAX_SIM_NUM >= 3)
    SRV_WAP_PROF_SIMID_SIM3,
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    SRV_WAP_PROF_SIMID_SIM4,    
#endif
    SRV_WAP_PROF_SIMID_WLAN,

    /* Add above this line. */
    SRV_WAP_PROF_SIMID_END
} srv_wap_prof_sim_id_enum;

/* Enum for APPID */
typedef enum
{
    SRV_WAP_PROF_APPID_BRW,
    SRV_WAP_PROF_APPID_MMS,
    /* Add above this line. */
    SRV_WAP_PROF_APPID_END
} srv_wap_prof_app_id_enum;



/* Enum for connection type. */
/* Note: Do not change the order of HTTP/CONNECTION_ORIENTED, as they are linked to UI. */
typedef enum
{
    SRV_WAP_PROF_CONN_TYPE_HTTP,
    SRV_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED,
    SRV_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE,

    /* Add above this line */
    SRV_WAP_PROF_CONN_TYPE_END
} srv_wap_prof_conn_type_enum;

#ifndef __SRV_UPP_SLIM__
/* enum for Job type. */
typedef enum
{
    SRV_WAP_PROF_JOB_GET_PROFILE_CONTENT,


    /* Add above this line */
    SRV_WAP_PROF_JOB_TYPE_END
} srv_wap_prof_job_type_enum;
#endif

/* enum for module status. */
typedef enum
{
    SRV_WAP_PROF_WAITING,
    SRV_WAP_PROF_BOOTUP_NOT_READY,
    SRV_WAP_PROF_READY,
	SRV_WAP_PROF_READY_TO_DELETE,


    /* Add above this line */
    SRV_WAP_PROF_STATUS_END
} srv_wap_prof_module_status_enum;

/* enum for profile content source. */
typedef enum
{
    SRV_WAP_PROF_PROFILE_SRC_USER,
    SRV_WAP_PROF_PROFILE_SRC_OTA_PROV,
    SRV_WAP_PROF_PROFILE_SRC_USIM_PROV,
    SRV_WAP_PROF_PROFILE_SRC_DM_PROV,
    SRV_WAP_PROF_PROFILE_SRC_SIM_STATUS_CHG,    /* USIM */
#ifdef __MMI_WAP_PROF_DYNAMIC_DTCNT_SUPPORT__
    SRV_WAP_PROF_PROFILE_SRC_DTCNT_DELETE,
#endif
    SRV_WAP_PROF_PROFILE_SRC_DTCNT_CHANGED,
    SRV_WAP_PROF_SRC_WLAN_DTCNT_CHANGED,
    SRV_WAP_PROF_PROFILE_SRC_DTCNT_DELETED,

    /* Add above this line */
    SRV_WAP_PROF_PROFILE_SRC_END
} srv_wap_prof_profile_source_enum;

/* enum for action type. */
typedef enum
{

    SRV_WAP_PROF_AXN_ACTIVATE,
  
    SRV_WAP_PROF_AXN_CFG_DTCNT,

    /* Add above this line. */
    SRV_WAP_PROF_AXN_END
} srv_wap_prof_action_enum;

typedef enum
{
    SRV_WAP_PROV_MMS_SETTING_CM,
    SRV_WAP_PROV_MMS_SETTING_RM,
    SRV_WAP_PROV_MMS_SETTING_MS,
    SRV_WAP_PROV_MMS_SETTING_MA,
    SRV_WAP_PROV_MMS_SETTING_PCADDR,

    /* Add above this line */
    SRV_WAP_PROV_MMS_SETTING_KEY_INVALID = 0xFFFF,

    SRV_WAP_PROV_MMS_SETTING_KEY_END
} srv_wap_prov_mms_setting_key_id_enum;

typedef enum
{
    SRV_WAP_PROV_MMS_SETTING_RESTRICTED,
    SRV_WAP_PROV_MMS_SETTING_WARNING,
    SRV_WAP_PROV_MMS_SETTING_FREE,
    SRV_WAP_PROV_MMS_SETTING_MA_DISABLE,
    SRV_WAP_PROV_MMS_SETTING_MA_ENABLE,
    SRV_WAP_PROV_MMS_SETTING_MA_LOCKED,

    /* Add above this line */
    SRV_WAP_PROV_MMS_SETTING_VALUE_INVALID = 0xFFFF,

    SRV_WAP_PROV_MMS_SETTING_VALUE_END
} srv_wap_prov_mms_setting_value_enum;

typedef enum
{
    SRV_WAP_PROV_VALUE_TYPE_INT = 0,
    SRV_WAP_PROV_VALUE_TYPE_STR,

    SRV_WAP_PROV_VALUE_TYPE_END
} srv_wap_prov_value_type_enum;



typedef enum
{
    SRV_WAP_PROF_DTCNT_PRIMARY =1,
    SRV_WAP_PROF_DTCNT_SECONDARY,

    SRV_WAP_PROF_DTCNT_COUNT_TOTAL
} srv_wap_prof_dtcnt_count_enum;

typedef enum
{
	SRV_WAP_PROF_CBM_BRW_APP_ID_1 = 0,
	SRV_WAP_PROF_CBM_BRW_APP_ID_2,
	SRV_WAP_PROF_CBM_BRW_APP_ID_3,
	SRV_WAP_PROF_CBM_BRW_APP_ID_4,
	SRV_WAP_PROF_CBM_MMS_APP_ID_1,
	SRV_WAP_PROF_CBM_MMS_APP_ID_2,
	SRV_WAP_PROF_CBM_MMS_APP_ID_3,
	SRV_WAP_PROF_CBM_MMS_APP_ID_4,

	SRV_WAP_PROF_CBM_APP_TOTAL
}srv_wap_prof_cbm_app_id_enum;
/* Typedefs */
typedef struct srv_wap_prof_profile_content_struct srv_wap_prof_profile_content_struct;

/* Typedef for response */
typedef void (*srv_wap_prof_response_funcptr_type) (srv_wap_prof_result_enum result);

/* Type for active profile changed indication. */
typedef void (*srv_wap_prof_active_profile_chg_ind_funcptr_type)
    (srv_wap_prof_profile_content_struct *profile_content_p,
     srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_response_funcptr_type active_profile_chg_rsp_callback);

/* Type for configure data account confirmation. */

typedef void (*srv_wap_prof_configure_dtcnt_cnf_funcptr_type)
    (srv_wap_prof_sim_id_enum sim_id,
     srv_wap_prof_app_id_enum app_id,
	 U8 profile_id,
	 srv_wap_prof_result_enum configure_dtcnt_rsp);


/* Typedef for profile in use. */
/* typedef kal_bool(*srv_wap_prof_is_active_profile_in_use_funcptr_type) (void); */
typedef kal_bool(*srv_wap_prof_is_active_profile_in_use_funcptr_type) (kal_uint8 sim_id); /* MAUI_1420567 */

/* Typedef for get profile response. */
typedef void (*srv_wap_prof_get_profile_rsp_funcptr_type)
    (srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_profile_content_struct *profile_content_p);
#ifdef BROWSER_SUPPORT
/* Get active sim id function ptr type. */
typedef mmi_brw_sim_id_enum(*srv_wap_prof_get_active_sim_id_funcptr_type) (void);
#endif

/* Delete profile callback for Java or other applications which want a callback upon profile deletion. */
typedef void (*srv_wap_prof_profile_delete_ind_callback_funcptr_type) (U8 sim_id, U8 deleted_profile_id);

/* Is application ready to recieve profile callback */
typedef kal_bool(*srv_wap_prof_is_target_app_ready) (void);

#ifndef PROV_SUPPORT
typedef struct
{
    srv_wap_prof_active_profile_chg_ind_funcptr_type active_profile_changed_callback[SRV_WAP_PROF_APPID_END];
    srv_wap_prof_is_active_profile_in_use_funcptr_type is_active_profile_in_use_callback[SRV_WAP_PROF_APPID_END];

/*Callback structure for MMS and browser*/
#ifdef BROWSER_SUPPORT
    srv_wap_prof_get_active_sim_id_funcptr_type active_sim_id_callback;
#endif
#ifdef PROV_SUPPORT
    srv_wap_prov_add_bookmark_funcptr_type add_bookmark_callback;
    srv_wap_prov_save_ota_mms_setting_funcptr_type save_ota_mms_setting_callback;
#endif
    srv_wap_prof_is_target_app_ready is_application_ready[SRV_WAP_PROF_APPID_END];

} srv_wap_prof_callback_struct;
#endif

typedef struct{
	srv_wap_prof_app_id_enum app_id;
	srv_wap_prof_sim_id_enum sim_id;
	U32 activate_data_account_id;
}account_update_struct;


/* Context structure. */
typedef struct
{

    MMI_BOOL end_key_pressed;
    MMI_BOOL prov_activate_profile_flag;
	MMI_BOOL profile_activated_bkm_flag;
    MMI_BOOL dtcnt_update_flag;
    U8 setting_installed;
    U8 cbm_app_id[SRV_WAP_PROF_SIMID_END -1][SRV_WAP_PROF_APPID_END];  // - 1 for SRV_WAP_PROF_SIMID_WLAN

    U8 update_account_count;
    U8 update_account_index; 
    mmi_id parent_id;
    srv_wap_prof_sim_id_enum sim_id;                        /* SIMID of the working sim */
    srv_wap_prof_app_id_enum app_id;
    srv_wap_prof_module_status_enum module_status;
    srv_wap_prof_action_enum action;
    srv_wap_prof_profile_source_enum profile_content_src;   /* Source of profile content */
    U16 titlebar_icon_id;
	U16 app_menu_id;
    U32 active_dtcnt_index[SRV_WAP_PROF_SIMID_END][SRV_WAP_PROF_APPID_END];    
	U32 smart_dtcnt_index[SRV_WAP_PROF_SIMID_END][SRV_WAP_PROF_APPID_END]; 
    U32 updated_mms_dtcnt;
    void *callback;
    account_update_struct update_account_info[2 * SRV_WAP_PROF_APPID_END];
} srv_wap_prof_context_struct;


typedef struct srv_wap_prof_profile_content_struct
{
    kal_uint32 data_account_primary_id;
    kal_uint32 data_account_secondary_id;
    kal_uint16 proxy_port;
    srv_wap_prof_conn_type_enum conn_type;
    kal_uint8 proxy_ip[SRV_WAP_PROF_MAX_PROXY_ADDR_LEN+1];
    kal_uint8 username[NVRAM_WAP_PROF_PROFILE_USERNAME_LEN];
    kal_uint8 password[NVRAM_WAP_PROF_PROFILE_PASSWORD_LEN];
    kal_uint8 url[NVRAM_WAP_PROF_URL_LEN];
} srv_wap_prof_profile_content_struct;

/* Provisioning structures */
typedef struct srv_wap_prof_add_bookmark_ind_struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    /* LOCAL_PARA_HDR */
    U8 name[SRV_WAP_PROV_MAX_BOOKMARK_TITLE_LEN *ENCODING_LENGTH];
    U8 url[NVRAM_WAP_PROF_URL_LEN];
} srv_wap_prof_add_bookmark_ind_struct;

typedef struct srv_wap_prof_add_bookmark_rsp_struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    /* LOCAL_PARA_HDR */
    srv_wap_prof_result_enum result;
} srv_wap_prof_add_bookmark_rsp_struct;

typedef struct srv_wap_prov_mms_setting_data_list_struct srv_wap_prov_mms_setting_data_list_struct;

typedef struct srv_wap_prov_mms_setting_data_list_struct
{
    srv_wap_prov_mms_setting_key_id_enum key;
    srv_wap_prov_value_type_enum value_type;
    srv_wap_prov_mms_setting_value_enum value_i;
    U8 value_s[SRV_WAP_PROV_MAX_MMS_SETTING_VALUE_SIZE + 1];
    struct srv_wap_prov_mms_setting_data_list_struct *next;
} srv_wap_prov_mms_setting_data_list_struct;

#ifndef __SRV_UPP_SLIM__
/* Job linked list structure. */
typedef struct srv_wap_prof_job_list_data_struct srv_wap_prof_job_list_data_struct;
typedef struct srv_wap_prof_job_list_data_struct
{
    U16 src_mod_id;
    srv_wap_prof_job_type_enum job_type;
    srv_wap_prof_sim_id_enum job_sim_id;
    srv_wap_prof_app_id_enum job_app_id;
    void *job_data;
    srv_wap_prof_job_list_data_struct *next;
} srv_wap_prof_job_list_data_struct;

/* Job structure of JOB_WAP_GET */
typedef struct
{
    U8 profile_id;
} srv_wap_prof_job_wap_get_profile_content_struct;

/* Job structure of Get profile. */
typedef struct
{
    U8 profile_id;
     srv_wap_prof_dtcnt_count_enum  dtcnt_type;
    void *callback;
} srv_wap_prof_job_get_profile_struct;
#endif

extern srv_wap_prof_context_struct g_srv_wap_prof_cntx;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 sim_id;
    kal_uint8 app_id;
    kal_uint8 profile_id;
    srv_wap_prof_result_enum response;
    void *callback;
} srv_wap_prof_cfg_dtcnt_send_response_ind_struct;

extern srv_wap_prof_context_struct g_srv_wap_prof_cntx;

#endif /* WAP_SUPPORT */ 
#endif /* _WAPPROFILETYPE_H */
