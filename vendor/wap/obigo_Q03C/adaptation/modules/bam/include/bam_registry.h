/*****************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2006
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
 *   bam_registry.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains code to handle the registry.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*
 * bam_registry.h
 *
 * Description:
 *              This file contains code to handle the registry.
 *
 */

#ifndef _bam_registry_h

#define _bam_registry_h

#include "brs_if.h"
#include "msf_int.h"
#include "bam_if.h"

#define BAM_REGISTRY_BAM_PATH                     "/BAM"
#define BAM_REGISTRY_BRS_BAM_PATH                 "/BRS/BAM"

/* IDs used when getting registry keys: */
#define BAM_REGISTRY_GET_ID_MAIN              1
#define BAM_REGISTRY_GET_ID_SIM               2
#define BAM_REGISTRY_GET_ID_HIST              3
#define BAM_REGISTRY_GET_ID_REG               4

#define BAM_REGISTRY_CONNECTION_TYPE_HTTP      STK_CONNECTION_TYPE_HTTP 
#define BAM_REGISTRY_CONNECTION_TYPE_WSP_CL    STK_CONNECTION_TYPE_WSP_CL 
#define BAM_REGISTRY_CONNECTION_TYPE_WSP_CO    STK_CONNECTION_TYPE_WSP_CO

/* 
 * There is no any module other than BAM has chance to update registry. BAM has 
 * no chance to receive response to inform registry is updated by other module. 
 */
#if 0
/* under construction !*/
/* under construction !*/
#endif

#define BAM_REGISTRY_PROXY_ADDR_LEN                             256
#define BAM_REGISTRY_USERNAME_LEN                               31
#define BAM_REGISTRY_PASSWORD_LEN                               31

typedef enum
{
  BAM_REGISTRY_ENUM_OBJ_ASK,
  BAM_REGISTRY_ENUM_OBJ_LOAD,
  BAM_REGISTRY_ENUM_TIMEOUT,
  BAM_REGISTRY_ENUM_USER_TIMEOUT,
  BAM_REGISTRY_ENUM_USER_AGT,
  BAM_REGISTRY_ENUM_ACCEPT_HEADER,
  BAM_REGISTRY_ENUM_COOKIES,
  BAM_REGISTRY_ENUM_CACHEON,
  BAM_REGISTRY_ENUM_CASHSIZE,
  BAM_REGISTRY_ENUM_HISTSIZE,
  BAM_REGISTRY_ENUM_LDNOMIME,
  BAM_REGISTRY_ENUM_REFRESH,
  BAM_REGISTRY_ENUM_USE_CAHCE,
  BAM_REGISTRY_ENUM_USE_CSS,
  BAM_REGISTRY_ENUM_UA_PROF,
  BAM_REGISTRY_ENUM_INLINE_DO,
  BAM_REGISTRY_ENUM_CACHE_MODE,
  BAM_REGISTRY_ENUM_NET_ID,
  BAM_REGISTRY_ENUM_CON_TYPE,
  BAM_REGISTRY_ENUM_PRX_ADDR,
  BAM_REGISTRY_ENUM_PRX_PWD,
  BAM_REGISTRY_ENUM_PRX_PORT,
  BAM_REGISTRY_ENUM_PRX_RLM,
  BAM_REGISTRY_ENUM_PRX_SECP,
  BAM_REGISTRY_ENUM_PRX_UID,
  BAM_REGISTRY_ENUM_HOMEPAGE_URL,
/* SLIM_R starts */
  BAM_REGISTRY_ENUM_ACCEPT_OBJ_HEADER,
  BAM_REGISTRY_ENUM_ACCEPT_CHARSET_HEADER,
  BAM_REGISTRY_ENUM_ACCEPT_LANGUAGE_HEADER,
  BAM_REGISTRY_ENUM_IMOD_USER_AGENT_HEADER,
#ifdef __BAIDU_TRANSCODING_SUPPORT__
  BAM_REGISTRY_ENUM_TRANSCODE_PROXY,
#endif


/* SLIM_R ends */
  BAM_REGISTRY_ENUM_TOTAL
} bam_registry_key_id_enum;

#ifdef OBIGO_Q03C_BROWSER

typedef struct
{
    int net_id;
	char username[BAM_REGISTRY_USERNAME_LEN];
    char password[BAM_REGISTRY_PASSWORD_LEN];
	int prx_port;
    int con_type;
    char prx_ip[BAM_REGISTRY_PROXY_ADDR_LEN];
    unsigned char prx_addr[4];
}bam_registry_content_t;

/************************************************************
 * Functions
 ************************************************************/

extern void bam_registry_init(void);

extern void bam_registry_terminate(void);

extern void bam_registry_set_profile(MSF_UINT8 setting_id,bam_set_profile_option_enum type, MSF_INT32 *int_value_table, char **str_value_table, void *p);

#ifdef MSF_MODID_CPS

extern void bam_registry_process_pending_profile(MSF_UINT8 result);

#endif /* MSF_MODID_CPS */ 

/*
 * Response from registry.
 */

/* 
 * There is no any module other than BAM has chance to update registry. BAM has 
 * no chance to receive/process response signal to inform registry is updated 
 * by other module. 
 */
#if 0
/* under construction !*/
#endif

extern void
bam_registry_enable_object_setting (int status, char* s);

extern void bam_registry_set_int(unsigned key, MSF_INT32 value);

extern MSF_INT32 bam_registry_get_int(unsigned key);

extern void bam_registry_set_string(unsigned key, const char *value);
extern void bam_registry_delete_value(unsigned key);
extern const char *bam_registry_get_string(unsigned key);

extern void bam_registry_delete_key(unsigned key);

#ifdef BAM_CFG_SUI_ZOOM_ENABLED
extern void bam_registry_set_zoom(int zoom_opt);

#endif /* BAM_CFG_SUI_ZOOM_ENABLED */ 

#if 0
/* under construction !*/
#endif

extern int bam_registry_get_net_acc_id(void);

extern int
bam_registry_change_key_str_value (int index, char* value, bam_set_profile_option_enum type);

extern int
bam_registry_change_key_int_value (int index, int value, bam_set_profile_option_enum type);

extern void
bam_registry_handle_em_setting_changed_ind(void *p);

extern void
bam_registry_handle_channel_config_notify(void);

extern int
bam_cfg_get_sec_conn_without_cert_dlg_setting(void);

extern int
bam_registry_get_browser_timeout(void);

extern MSF_UINT8
bam_registry_load_browser_active_profile(bam_registry_content_t  **prof_cont_ptr);


#endif /*OBIGO_Q03C_BROWSER*/

extern void bam_regitry_get_pref_value(int key, char **s_value, int *i_value);


extern const char* bam_registry_get_ua_profile();
extern int bam_registry_check_cache_status(void);
extern int bam_registry_check_cookie_status(void);
extern int bam_registry_check_auth_status(void);


extern const char* bam_registry_get_transcode_proxy_url(void);
extern const char* bam_registry_get_transcode_proxy_header(void);


#endif /* _bam_registry_h */ 
