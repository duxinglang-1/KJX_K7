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
 *  EmailSrvOTAP.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email OTAP functions.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
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
 * removed!
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_EMAIL__
#include "stdlib.h"

#include "EmailSrvGProt.h"
#include "EmailSrvProt.h"
#include "EmailSrvStorage.h"
#include "EmailSrvNetworkProt.h"

#ifdef __MMI_EMAIL_OTAP__

#include "app_usedetails.h"
#include "conversions.h"
#include "CcaSrvGprot.h"

#include "soc_api.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "customer_ps_inc.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_utility_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "cbm_consts.h"
#include "cbm_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_inet_app_trc.h"
#include "kal_trace.h"

#define SRV_EMAIL_OTAP_MAX_PROFILE_NUM          (3)  /* the max number of combined profile */
#define SRV_EMAIL_OTAP_MAX_PROXY_ID_LEN         (40)
#define SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN     (16)
#define SRV_EMAIL_OTAP_PROVURL_HASH_VALUE_LEN   (16)

#define SRV_EMAIL_OTAP_UTF8_ENCODING_LENGTH     (3)

#define SRV_EMAIL_OTAP_CONVERT_BUFF_SIZE        (1024)

typedef enum
{
    SRV_EMAIL_OTAP_APP_NONE,
    SRV_EMAIL_OTAP_APP_SMTP,
    SRV_EMAIL_OTAP_APP_POP3,
    SRV_EMAIL_OTAP_APP_IMAP4,
    SRV_EMAIL_OTAP_APP_TOTAL
} srv_email_otap_app_type_enum;

/* Converted symbols used to define CCA namespace mapping table */
typedef enum
{
    SRV_EMAIL_OTAP_NS_BOOTSTRAP,
    SRV_EMAIL_OTAP_NS_PROXY,
    SRV_EMAIL_OTAP_NS_APPLICATION,
    SRV_EMAIL_OTAP_NS_APPADDR,
    SRV_EMAIL_OTAP_NS_APPAUTH,
    SRV_EMAIL_OTAP_NS_TOTAL
} srv_email_otap_symbol_enum;

typedef enum
{
    SRV_EMAIL_OTAP_ACTION_NONE,
    SRV_EMAIL_OTAP_ACTION_ADD,
    SRV_EMAIL_OTAP_ACTION_MODIFY,
    SRV_EMAIL_OTAP_ACTION_REPLACE,
    SRV_EMAIL_OTAP_ACTION_UPDATE,
    SRV_EMAIL_OTAP_ACTION_SKIP,
    SRV_EMAIL_OTAP_ACTION_TOTAL
} srv_email_otap_action_enum;

typedef struct
{
    CHAR proxy_id[SRV_EMAIL_OTAP_MAX_PROXY_ID_LEN + 1];   /* CCA_NS_OMA_PROXY_ID */
    U8 napid_hash[SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN];
    S32 data_acct_id;   /*DATAACCTID*/

    /* indicate whether it is a valid node */
    MMI_BOOL is_have_proxy_id;
    MMI_BOOL is_have_dataacctid;
} srv_email_otap_proxy_struct;

typedef struct _srv_email_otap_proxy_node_struct
{
    struct _srv_email_otap_proxy_node_struct *next;
    srv_email_otap_proxy_struct proxy_parms;
} srv_email_otap_proxy_node_struct;

/*All the string from CCA is UTF8*/
typedef struct
{
    WCHAR prof_name[SRV_EMAIL_MAX_ACCT_NAME_LEN + 1];       /* NAME, save as UCS2 */
    WCHAR provider_id[SRV_EMAIL_MAX_ACCT_NAME_LEN + 1];     /* PROVIDER-ID */
    CHAR to_proxy[SRV_EMAIL_OTAP_MAX_PROXY_ID_LEN + 1];     /* CCA_NS_OMA_TO_PROXY */
    U8 napid_hash_val[SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN]; /* Hashed value of NAPID */
    WCHAR from_name[SRV_EMAIL_MAX_DISP_NAME_LEN + 1];       /* nick name after split from */
    WCHAR from_addr[SRV_EMAIL_MAX_ADDR_LEN + 1];            /* email address after split from */
    WCHAR rt_addr[SRV_EMAIL_MAX_ADDR_LEN + 1];              /* RT-ADDR */
    WCHAR server_addr[SRV_EMAIL_MAX_SERVER_NAME_LEN + 1];   /* ADDR */
    U16 server_addr_type;                                   /* ADDRTYPE */
    U16 port_num;                                           /* PORTNBR */
    U16 service;                                            /* SERVICE */
    WCHAR username[SRV_EMAIL_MAX_USERNAME_LEN + 1];         /* AAUTHNAME */
    WCHAR password[SRV_EMAIL_MAX_PASSWORD_LEN + 1];         /* AAUTHSECRET */

    srv_email_otap_app_type_enum app_type;

    //MMI_BOOL is_valid_node; /*indicate whether it is a valid node*/
} srv_email_otap_application_struct;

typedef struct
{
    U8 napid_hash_val[SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN];     /* Hashed value of NAPID */
    WCHAR prof_name_combined[SRV_EMAIL_MAX_ACCT_NAME_LEN + 1];  /* convert UTF8 to UCS2 to save to this buffer,profile name after combined */
    S32 data_acct_id;
    srv_email_otap_application_struct *smtp_node;
    srv_email_otap_application_struct *pop3_imap4_node;

    CHAR to_proxy_combined[SRV_EMAIL_OTAP_MAX_PROXY_ID_LEN + 1];/* CCA_NS_OMA_TO_PROXY */
    srv_email_prot_type_enum in_protocol_type;                  /* POP3 or IMAP4 */

    /*indicate the Profile have what information*/
    MMI_BOOL is_have_dataacctid;
    MMI_BOOL is_have_smtp;
    MMI_BOOL is_have_pop3_imap4;

    MMI_BOOL is_valid_profile;  /* indicate whether it is a valid profile */
    MMI_BOOL is_updateble;
    EMAIL_ACCT_ID matched_acct_id;
    cca_status_enum cca_prof_status; /* each profile's status */
} srv_email_otap_profile_struct;

typedef struct
{
    U16 conf_id;                        /* Configuration ID                  */
    S32 doc_hdl;                        /* Configuration document handle     */   
    U32 num_profiles;                    /* Num of existed profile, have malloc space */
    U32 profile_index;                   /* index of profile, after install or skip a profile, profile_index++ */
    U8 provurl_hash_val[SRV_EMAIL_OTAP_PROVURL_HASH_VALUE_LEN];  /* Hashed value of PROVURL */
    mmi_cca_prov_type_enum prov_type;   /* provisioning type, get from mmi_cca_app_configure_ind_struct */
    U32 prov_flag;                      /* provisioning flag, get from mmi_cca_app_configure_ind_struct */
    srv_email_otap_application_struct *curr_node; /*no space will malloc, just point to other node */

    srv_email_otap_proxy_node_struct *proxy_linklist;
    srv_email_otap_application_struct *tmp_app_node;

    srv_email_otap_profile_struct *profile[SRV_EMAIL_OTAP_MAX_PROFILE_NUM];

    MMI_BOOL is_updating;
    cca_status_enum cca_status; /* status to response to CCA */
    U16 sim_id; /* for_generating_dataaccount */

    srv_email_otap_option_struct option;

    srv_email_otap_action_enum action;
    EMAIL_ACCT_HANDLE acct_handle;
    EMAIL_ACCT_ID acct_id;
    srv_email_otap_profile_struct *profile_p;
    srv_email_otap_funcptr_type callback;
    void *user_data;
} srv_email_otap_cntx_struct;

typedef struct
{
    EMAIL_SRV_HANDLE srv_handle;
    MMI_BOOL allow_register;
    srv_email_otap_notify_funcptr_type otap_callback;
    srv_email_funcptr_type clear_callback;
} srv_email_otap_struct;

extern EMAIL_SRV_HANDLE srv_email_get_int_srv_handle(void);

static srv_email_otap_struct srv_email_otap;
static srv_email_otap_struct *srv_email_otap_p = NULL;
static srv_email_otap_cntx_struct *srv_email_otap_cntx_p = NULL;
static MMI_BOOL srv_email_otap_inited = MMI_FALSE;

static void srv_email_otap_strcpy(CHAR *str_dst, const CHAR *str_src, U32 buflen);
static void srv_email_otap_wstrcpy(WCHAR *str_dst, const WCHAR *str_src, U32 buflen);
static WCHAR *srv_email_otap_utf8_to_ucs2(const CHAR *data, U32 *outLen);

static srv_email_otap_cntx_struct *srv_email_otap_new_cntx(void);
static void srv_email_otap_free_cntx(srv_email_otap_cntx_struct *cntx_p);

static void srv_email_otap_init_profile(srv_email_otap_profile_struct *profile_p);
static srv_email_otap_profile_struct *srv_email_otap_new_profile(void);
static void srv_email_otap_free_profile(srv_email_otap_profile_struct *profile_p);

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
static MMI_BOOL srv_email_otap_hash_value_is_empty(U8 *hash_value, U32 len);
#endif

static MMI_BOOL srv_email_otap_is_server_vaild(const WCHAR *server);
static MMI_BOOL srv_email_otap_correct_disp_name(WCHAR *disp_name);
static MMI_BOOL srv_email_otap_is_username_vaild(const WCHAR *username);
static MMI_BOOL srv_email_otap_is_password_valid(const WCHAR *username);
static void srv_email_otap_split_from(const CHAR *from, CHAR *name_buf, CHAR *addr_buf);

static MMI_BOOL srv_email_otap_is_valid_but_discard(
                    U8 *provurl_hash,
                    U8 *napid_hash,
                    U32 factory_acct_updatable,
                    WCHAR *acct_name);
static MMI_BOOL srv_email_otap_is_matched_acct(
                    U8 *provurl_hash,
                    U8 *napid_hash,
                    U32 factory_acct_updatable,
                    WCHAR *acct_name,
                    EMAIL_ACCT_ID *matched_acct_id);

static void srv_email_otap_add_proxy_node_to_tail(
                srv_email_otap_cntx_struct *cntx_p,
                srv_email_otap_proxy_node_struct *proxy_p);
static cca_status_enum srv_email_otap_add_application_to_profile(srv_email_otap_cntx_struct *cntx_p);

static cca_status_enum srv_email_otap_proc_cca_param_bootstrap(
                        const cca_core_data_struct *param_p,
                        srv_email_otap_cntx_struct *cntx_p);
static cca_status_enum srv_email_otap_proc_cca_param_proxy(
                        const cca_core_data_struct *param_p,
                        srv_email_otap_proxy_node_struct *proxy_p);
static cca_status_enum srv_email_otap_proc_cca_param_application(
                        const cca_core_data_struct *param_p,
                        srv_email_otap_cntx_struct *cntx_p);
static cca_status_enum srv_email_otap_proc_cca_param_appaddr(
                        const cca_core_data_struct *param_p,
                        srv_email_otap_cntx_struct *cntx_p);
static cca_status_enum srv_email_otap_proc_cca_param_appauth(
                        const cca_core_data_struct *param_p,
                        srv_email_otap_cntx_struct *cntx_p);
static cca_status_enum srv_email_otap_proc_cca_nodes(
                        S32 doc_hdl,
                        S32 node_hdl,
                        U16 symbol,
                        cca_iterator_struct *param_list,
                        void *user_data);

static void srv_email_otap_add_dataacctid_to_profile(srv_email_otap_cntx_struct *cntx_p);
static void srv_email_otap_check_profile_validity(srv_email_otap_cntx_struct *cntx_p);

static cca_status_enum srv_email_otap_exec_proc_cca_doc(srv_email_otap_cntx_struct *cntx_p);

static cca_status_enum srv_email_otap_get_cca_status(srv_email_otap_cntx_struct *cntx_p);
static void srv_email_otap_send_cca_rsp(U16 config_id, S32 hConfig, cca_status_enum status);

static void srv_email_otap_fill_acct_info(
                srv_email_acct_info_struct *acct_p,
                srv_email_otap_profile_struct *profile_p,
                const WCHAR *prof_name,
                srv_email_otap_cntx_struct *cntx_p);

static void srv_email_otap_acct_save_done(srv_email_result_enum ret, void *user_data);
static srv_email_result_enum srv_email_otap_add_prof_ext(
                                EMAIL_OTAP_HANDLE handle,
                                U32 prof_index,
                                const WCHAR *prof_name,
                                EMAIL_ACCT_ID *acct_id,
                                MMI_BOOL async_mode);


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_strcpy
 * DESCRIPTION
 *  This function is used to copy the char string.
 * PARAMETERS
 *  str_dst         [IN]        The destination string.
 *  str_src         [IN]        The source string.
 *  buflen          [IN]        The length of the destination string buffer.
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_otap_strcpy(CHAR *str_dst, const CHAR *str_src, U32 buflen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = strlen(str_src);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len > buflen - 1)
    {
        len = buflen - 1;
    }

    strncpy(str_dst, str_src, len);
    str_dst[len] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_wstrcpy
 * DESCRIPTION
 *  This function is used to copy the wchar string.
 * PARAMETERS
 *  str_dst         [IN]        The destination string.
 *  str_src         [IN]        The source string.
 *  buflen          [IN]        The length of the destination string buffer.
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_otap_wstrcpy(WCHAR *str_dst, const WCHAR *str_src, U32 buflen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = (U32)mmi_wcslen(str_src);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (len > buflen - 1)
    {
        len = buflen - 1;
    }

    mmi_wcsncpy(str_dst, str_src, len);
    str_dst[len] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_utf8_to_ucs2
 * DESCRIPTION
 *  This function is used to convert the UTF8 string to UCS2 string.
 * PARAMETERS
 *  data            [IN]        The UTF8 string
 *  outlen          [OUT]       Used to return the UCS2 string length
 * RETURNS
 *  The UCS2 string.
 *****************************************************************************/
static WCHAR *srv_email_otap_utf8_to_ucs2(const CHAR *data, U32 *outLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *convertedData = NULL;
    S32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    convertedData = (WCHAR*)OslMalloc(SRV_EMAIL_OTAP_CONVERT_BUFF_SIZE);

    len = mmi_chset_convert(
            MMI_CHSET_UTF8,
            MMI_CHSET_UCS2,
            (char*)data,
            (char*)convertedData,
            SRV_EMAIL_OTAP_CONVERT_BUFF_SIZE);

    if (len > 0)
    {
        *outLen = (U32)len;
        return convertedData;
    }
    else
    {
        OslMfree(convertedData);
        *outLen = 0;
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_new_cntx
 * DESCRIPTION
 *  The function is used to create a new OTAP context.
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer point to the new OTAP context.
 *****************************************************************************/
static srv_email_otap_cntx_struct *srv_email_otap_new_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_otap_cntx_struct *cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p = (srv_email_otap_cntx_struct*)OslMalloc(sizeof(srv_email_otap_cntx_struct));
    if (!cntx_p)
    {
        return NULL;
    }

    memset(cntx_p, 0, sizeof(srv_email_otap_cntx_struct));
    cntx_p->cca_status = CCA_STATUS_SETTING_NOT_INSTALLED;

    cntx_p->action = SRV_EMAIL_OTAP_ACTION_NONE;
    cntx_p->acct_handle = EMAIL_ACCT_INVALID_HANDLE;
    cntx_p->acct_id = EMAIL_ACCT_INVALID_ID;

    return cntx_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_free_cntx
 * DESCRIPTION
 *  The function is used to free the OTAP context.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the OTAP context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_otap_free_cntx(srv_email_otap_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_otap_proxy_node_struct *ptr = NULL;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Free all profiles. */
    for (i = 0; i < SRV_EMAIL_OTAP_MAX_PROFILE_NUM; i++)
    {
        if (cntx_p->profile[i])
        {
            srv_email_otap_free_profile(cntx_p->profile[i]);
        }
    }

    while (cntx_p->proxy_linklist)
    {
        ptr = cntx_p->proxy_linklist;
        cntx_p->proxy_linklist = ptr->next;
        OslMfree(ptr);
    }

    if (cntx_p->tmp_app_node)
    {
        OslMfree(cntx_p->tmp_app_node);
    }

    if (cntx_p->acct_handle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(cntx_p->acct_handle);
    }

    /* Free the control block. */
    OslMfree(cntx_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_init_profile
 * DESCRIPTION
 *  This function is used to initialize the specified profile.
 * PARAMETERS
 *  profile_p       [IN]        The pointer point to the profile
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_otap_init_profile(srv_email_otap_profile_struct *profile_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profile_p->data_acct_id = 0;

    if (profile_p->smtp_node)
    {
        memset(profile_p->smtp_node, 0, sizeof(srv_email_otap_application_struct));
    }
    if (profile_p->pop3_imap4_node)
    {
        memset(profile_p->pop3_imap4_node, 0, sizeof(srv_email_otap_application_struct));
    }

    memset(profile_p->prof_name_combined, 0, (SRV_EMAIL_MAX_ACCT_NAME_LEN + 1) * 2);
    memset(profile_p->to_proxy_combined, 0, SRV_EMAIL_OTAP_MAX_PROXY_ID_LEN + 1);
    memset(profile_p->napid_hash_val, 0, SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN);

    profile_p->is_have_dataacctid = MMI_FALSE;
    profile_p->is_have_smtp = MMI_FALSE;
    profile_p->is_have_pop3_imap4 = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_new_profile
 * DESCRIPTION
 *  This function is used to alloc a new profile.
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer point to the new profile.
 *****************************************************************************/
static srv_email_otap_profile_struct *srv_email_otap_new_profile(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_otap_profile_struct *profile_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profile_p = (srv_email_otap_profile_struct*)OslMalloc(sizeof(srv_email_otap_profile_struct));
    if (!profile_p)
    {
        return NULL;
    }

    profile_p->smtp_node = (srv_email_otap_application_struct*)
        OslMalloc(sizeof(srv_email_otap_application_struct));
    if (!profile_p->smtp_node)
    {
        OslMfree(profile_p);
        return NULL;
    }

    profile_p->pop3_imap4_node = (srv_email_otap_application_struct*)
        OslMalloc(sizeof(srv_email_otap_application_struct));
    if (!profile_p->pop3_imap4_node)
    {
        OslMfree(profile_p->smtp_node);
        OslMfree(profile_p);
        return NULL;
    }

    srv_email_otap_init_profile(profile_p);

    profile_p->is_valid_profile = MMI_TRUE;
    profile_p->cca_prof_status = CCA_STATUS_SETTING_NOT_INSTALLED;

    return profile_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_free_profile
 * DESCRIPTION
 *  This function is used to free the specified profile.
 * PARAMETERS
 *  profile_p       [IN]        The pointer point to the profile
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_otap_free_profile(srv_email_otap_profile_struct *profile_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (profile_p->smtp_node)
    {
        OslMfree(profile_p->smtp_node);
    }

    if (profile_p->pop3_imap4_node)
    {
        OslMfree(profile_p->pop3_imap4_node);
    }

    OslMfree(profile_p);
}


#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_hash_value_is_empty
 * DESCRIPTION
 *  This function is used to check if the hash value is empty.
 * PARAMETERS
 *  hash_value      [IN]        The hash value
 *  len             [IN]        The length of the hash value
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_email_otap_hash_value_is_empty(U8 *hash_value, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len; i++)
    {
        if (hash_value[i])
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_is_server_vaild
 * DESCRIPTION
 *  This function is used to check if the server address is valid.
 * PARAMETERS
 *  server          [IN]        The server address
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_email_otap_is_server_vaild(const WCHAR *server)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool ip_validity = MMI_FALSE;
    kal_uint8 ip_addr[4];
    kal_char in_server[SRV_EMAIL_MAX_SERVER_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2_to_asc(in_server, (CHAR*)server);
    if (soc_ip_check(in_server, ip_addr, &ip_validity) && !ip_validity)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_correct_disp_name
 * DESCRIPTION
 *  This function is used to correct the display name
 *  (convert the control characters into space).
 * PARAMETERS
 *  disp_name       [IN]        The display name
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_email_otap_correct_disp_name(WCHAR *disp_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*disp_name != 0)
    {
        if (*disp_name < 0x0020)
        {
            *disp_name = 0x0020;
        }
        disp_name++;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_is_username_vaild
 * DESCRIPTION
 *  The function is used to check if the username is valid.
 * PARAMETERS
 *  username        [IN]        The username
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_email_otap_is_username_vaild(const WCHAR *username)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*username != 0)
    {
        if (*username < 0x0020  || *username > 0x007E)
        {
            return MMI_FALSE;
        }
        username++;
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_is_password_valid
 * DESCRIPTION
 *  This function is used to check if the password is valid.
 * PARAMETERS
 *  password        [IN]        The password
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_email_otap_is_password_valid(const WCHAR *password)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*password != 0)
    {
        if (*password < 0x0020 || *password > 0x007E)
        {
            return MMI_FALSE;
        }
        password++;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_split_from
 * DESCRIPTION
 *  This function is used to split the from to display name and email address.
 * PARAMETERS
 *  from            [IN]        The from
 *  name_buf        [OUT]       Used to store the display name
 *  addr_buf        [OUT]       Used to store the email address
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_otap_split_from(const CHAR *from, CHAR *name_buf, CHAR *addr_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *from_p = (CHAR*)from;
    CHAR *ptr = NULL;
    CHAR *name_p = NULL;
    CHAR *addr_p = NULL;
    U32 len = 0;
    U32 offset = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = strchr(from, '<');
    if (!ptr)  /* No nickname */
    {
        len = strlen(from);
        if (len > SRV_EMAIL_MAX_ADDR_LEN)
        {
            len = SRV_EMAIL_MAX_ADDR_LEN;
        }
        strncpy(addr_buf, from, len);
        addr_buf[len] = 0;
        name_buf[0] = 0;
    }
    else
    {
        addr_p = ptr + 1;
        if (*from == '"')   /* "nickname"<abc@domain.com> */
        {
            offset = 2;
            name_p = from_p + 1;
        }
        else    /* nickname<abc@domain.com> */
        {
            name_p = from_p;
        }

        len = ptr - from_p - offset;
        if (len > SRV_EMAIL_MAX_DISP_NAME_LEN * SRV_EMAIL_OTAP_UTF8_ENCODING_LENGTH)
        {
            len = SRV_EMAIL_MAX_DISP_NAME_LEN * SRV_EMAIL_OTAP_UTF8_ENCODING_LENGTH;
        }
        strncpy(name_buf, name_p, len);
        name_buf[len] = 0;

        len = strlen(from) - strlen(name_buf) - 2 - offset;
        if (len > SRV_EMAIL_MAX_ADDR_LEN)
        {
            len = SRV_EMAIL_MAX_ADDR_LEN;
        }
        strncpy(addr_buf, addr_p, len);    /* not to copy < > */
        addr_buf[len] = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_is_valid_but_discard
 * DESCRIPTION
 *  This function is used to check if the profile is valid but need discard.
 * PARAMETERS
 *  provurl_hash            [IN]        The provurl hash
 *  napid_hash              [IN]        The napid hash of the profile
 *  factory_acct_updatable  [IN]        If the factory account is updatable
 *  acct_name               [IN]        The account name
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_email_otap_is_valid_but_discard(
                    U8 *provurl_hash,
                    U8 *napid_hash,
                    U32 factory_acct_updatable,
                    WCHAR *acct_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    srv_email_acct_info_struct *acct_p = NULL;
    EMAIL_ACCT_ID acct_id[EMAIL_STOR_ACCT_NUM_MAX];
    U32 acct_num = 0;
    U32 i = 0;
    MMI_BOOL is_pre_conf = MMI_FALSE;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 len = mmi_wcslen(acct_name);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    if (srv_email_otap_hash_value_is_empty(provurl_hash, SRV_EMAIL_OTAP_PROVURL_HASH_VALUE_LEN))
    {
        return MMI_FALSE;
    }

    acct_num = srv_email_stor_acct_id_get(acct_id);
    if (acct_num == 0)
    {
        return MMI_FALSE;
    }

    acct_p = (srv_email_acct_info_struct*)OslMalloc(sizeof(srv_email_acct_info_struct));

    for (i = 0; i < acct_num; i++)
    {
        memset(acct_p, 0, sizeof(srv_email_acct_info_struct));
        acct_p->acct_id = acct_id[i];

        retval = srv_email_stor_acct_info_read(acct_p);
        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            //trace: read account info error
            OslMfree(acct_p);
            return MMI_FALSE;
        }

        is_pre_conf = (acct_p->acct_type == SRV_EMAIL_ACCT_FACTORY_CONFIGURED ? MMI_TRUE : MMI_FALSE);
        if (!memcmp(
                provurl_hash,
                acct_p->provurl_hash,
                SRV_EMAIL_OTAP_PROVURL_HASH_VALUE_LEN))
        {
            /* provurl matched */
            if (srv_email_otap_hash_value_is_empty(acct_p->napid_hash, SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN))
            {
                /* napid empty, take account of account_name */
                if (mmi_wcslen(acct_p->acct_name) > 0 && len > 0)
                {
                    if (!mmi_wcscmp(acct_p->acct_name, acct_name))
                    {
                        /* Account name matched */
                        if (is_pre_conf && !factory_acct_updatable)
                        {
                            /* pre-configured profile matched, but not updatable */
                            ret = MMI_TRUE;
                            break;
                        }
                    }
                }
            }
            else if (!memcmp(
                        napid_hash,
                        acct_p->napid_hash,
                        SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN))
            {
                /* napid matched, and both not empty */
                if (is_pre_conf && !factory_acct_updatable)
                {
                    /* pre-configured profile matched, but not updatable */
                    ret = MMI_TRUE;
                    break;
                }
            }
        }
    }

    OslMfree(acct_p);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_is_matched_acct
 * DESCRIPTION
 *  This function is used to check if the profile is matched.
 * PARAMETERS
 *  provurl_hash            [IN]        The provurl hash
 *  napid_hash              [IN]        The napid hash of the profile
 *  factory_acct_updatable  [IN]        If the factory account is updatable
 *  acct_name               [IN]        The account name
 *  matched_acct_id         [OUT]       Used to store the matched account id
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_email_otap_is_matched_acct(
                    U8 *provurl_hash,
                    U8 *napid_hash,
                    U32 factory_acct_updatable,
                    WCHAR *acct_name,
                    EMAIL_ACCT_ID *matched_acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    srv_email_acct_info_struct *acct_p = NULL;
    EMAIL_ACCT_ID acct_id[EMAIL_STOR_ACCT_NUM_MAX];
    U32 acct_num = 0;

    EMAIL_ACCT_ID matched_id[EMAIL_STOR_ACCT_NUM_MAX];
    MMI_BOOL is_empty[EMAIL_STOR_ACCT_NUM_MAX];
    MMI_BOOL is_preconf[EMAIL_STOR_ACCT_NUM_MAX];
    U32 matched_num = 0;
    U32 i = 0;

    U32 priority = 0;
    U32 max_pri = 0;
    MMI_BOOL is_pre_conf = MMI_FALSE;

    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 len = mmi_wcslen(acct_name);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    if (srv_email_otap_hash_value_is_empty(provurl_hash, SRV_EMAIL_OTAP_PROVURL_HASH_VALUE_LEN))
    {
        return MMI_FALSE;
    }

    acct_num = srv_email_stor_acct_id_get(acct_id);
    if (acct_num == 0)
    {
        return MMI_FALSE;
    }

    acct_p = (srv_email_acct_info_struct*)OslMalloc(sizeof(srv_email_acct_info_struct));

    for (i = 0; i < acct_num; i++)
    {
        memset(acct_p, 0, sizeof(srv_email_acct_info_struct));
        acct_p->acct_id = acct_id[i];

        retval = srv_email_stor_acct_info_read(acct_p);
        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            //trace: read account info error
            OslMfree(acct_p);
            return MMI_FALSE;
        }

        is_pre_conf = (acct_p->acct_type == SRV_EMAIL_ACCT_FACTORY_CONFIGURED ? MMI_TRUE : MMI_FALSE);
        if (!memcmp(
                provurl_hash,
                acct_p->provurl_hash,
                SRV_EMAIL_OTAP_PROVURL_HASH_VALUE_LEN))
        {
            /* provurl matched */
            if (srv_email_otap_hash_value_is_empty(acct_p->napid_hash, SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN))
            {
                /* napid empty, take account of account_name */
                if (mmi_wcslen(acct_p->acct_name) > 0 && len > 0)
                {
                    if (!mmi_wcscmp(acct_p->acct_name, acct_name))
                    {
                        /* Account name matched */
                        if (!is_pre_conf || factory_acct_updatable)
                        {
                            matched_id[matched_num] = acct_id[i];
                            is_empty[matched_num] = MMI_FALSE;
                            is_preconf[matched_num] = is_pre_conf;
                            matched_num++;
                        }
                    }
                }
            }
            else if (!memcmp(
                        napid_hash,
                        acct_p->napid_hash,
                        SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN))
            {
                /* napid matched, and both not empty */
                if (!is_pre_conf || factory_acct_updatable)
                {
                    matched_id[matched_num] = acct_id[i];
                    is_empty[matched_num] = MMI_TRUE;
                    is_preconf[matched_num] = is_pre_conf;
                    matched_num++;
                }
            }
        }
    }

    OslMfree(acct_p);

    for (i = 0; i < matched_num; i++)
    {
        if (!is_empty[i] && is_preconf[i])
        {
            priority = 4;
        }
        else if (is_empty[i] && is_preconf[i])
        {
            priority = 3;
        }
        else if (!is_empty[i] && !is_preconf[i])
        {
            priority = 2;
        }
        else
        {
            priority = 1;
        }

        if (priority > max_pri)
        {
            *matched_acct_id = matched_id[i];
            max_pri = priority;
        }
    }

    if (matched_num)
    {
        ret = MMI_TRUE;
    }
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_add_proxy_node_to_tail
 * DESCRIPTION
 *  This function is used to add the new proxy node to the tail of the proxy list.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the OTAP context
 *  proxy_p         [IN]        The pointer point to the new proxy node
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_otap_add_proxy_node_to_tail(
                srv_email_otap_cntx_struct *cntx_p,
                srv_email_otap_proxy_node_struct *proxy_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_otap_proxy_node_struct *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = cntx_p->proxy_linklist;
    if (!ptr)
    {
        cntx_p->proxy_linklist = proxy_p;
    }
    else
    {
        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = proxy_p;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_add_application_to_profile
 * DESCRIPTION
 *  This function is used to add an new application node to profile.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the OTAP context
 * RETURNS
 *  void
 *****************************************************************************/
static cca_status_enum srv_email_otap_add_application_to_profile(srv_email_otap_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_otap_application_struct *tmp_app_node = cntx_p->tmp_app_node;
    srv_email_otap_profile_struct *profile_p = NULL;
    U8 i = 0;
    MMI_BOOL is_inserted = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (tmp_app_node->app_type)
    {
        case SRV_EMAIL_OTAP_APP_SMTP:
            if (mmi_wcslen(tmp_app_node->from_addr) && mmi_wcslen(tmp_app_node->server_addr))
            {
                /* is a valid outgoing node */
                for (i = 0; i < cntx_p->num_profiles; i++)
                {
                    profile_p = cntx_p->profile[i];

                    /* both not set */
                    if (!profile_p->is_have_smtp && !profile_p->is_have_pop3_imap4)
                    {
                        memcpy(
                            profile_p->smtp_node,
                            tmp_app_node,
                            sizeof(srv_email_otap_application_struct));
                        profile_p->is_have_smtp = MMI_TRUE;

                        is_inserted = MMI_TRUE;

                        strcpy(profile_p->to_proxy_combined, tmp_app_node->to_proxy);

                        /* hash value of napid */
                        memcpy(
                            profile_p->napid_hash_val,
                            tmp_app_node->napid_hash_val,
                            SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN);

                        if (mmi_wcslen(tmp_app_node->prof_name))
                        {
                            mmi_wcscpy(profile_p->prof_name_combined, tmp_app_node->prof_name);
                        }
                        break;
                    }
                    else if (!profile_p->is_have_smtp && profile_p->is_have_pop3_imap4)
                    {
                        if (!mmi_wcscmp(tmp_app_node->provider_id, profile_p->pop3_imap4_node->provider_id))
                        {
                            /* combine 2 application nodes with same provider_id to 1 profile */
                            /* set prof_name_combined */
                            if (mmi_wcslen(tmp_app_node->prof_name))
                            {
                                /* if have pop3/imap4 name, replace it */
                                memset(
                                    profile_p->prof_name_combined,
                                    0,
                                    (SRV_EMAIL_MAX_ACCT_NAME_LEN + 1) * 2);
                                mmi_wcscpy(profile_p->prof_name_combined, tmp_app_node->prof_name);
                            }

                            /* set to_proxy_combined */
                            if (!strlen(tmp_app_node->to_proxy)) /* both to_proxy not set */
                            {
                                memcpy(
                                    profile_p->smtp_node,
                                    tmp_app_node,
                                    sizeof(srv_email_otap_application_struct));
                                profile_p->is_have_smtp = MMI_TRUE;

                                is_inserted = MMI_TRUE;

                                strcpy(profile_p->to_proxy_combined, profile_p->pop3_imap4_node->to_proxy);

                                /* hash value of napid */
                                memcpy(
                                    profile_p->napid_hash_val,
                                    profile_p->pop3_imap4_node->napid_hash_val,
                                    SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN);
                                break;
                            }
                            else if (!strlen(profile_p->pop3_imap4_node->to_proxy)) /* outgoing to_proxy set, but incoming */
                            {
                                memcpy(
                                    profile_p->smtp_node,
                                    tmp_app_node,
                                    sizeof(srv_email_otap_application_struct));
                                profile_p->is_have_smtp = MMI_TRUE;

                                is_inserted = MMI_TRUE;

                                strcpy(profile_p->to_proxy_combined, tmp_app_node->to_proxy);

                                /* hash value of napid */
                                memcpy(
                                    profile_p->napid_hash_val,
                                    tmp_app_node->napid_hash_val,
                                    SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN);
                                break;
                            }
                            else    /* both to_proxy set */
                            {
                                if (!strcmp(tmp_app_node->to_proxy, profile_p->pop3_imap4_node->to_proxy))
                                {
                                    memcpy(
                                        profile_p->smtp_node,
                                        tmp_app_node,
                                        sizeof(srv_email_otap_application_struct));
                                    profile_p->is_have_smtp = MMI_TRUE;

                                    is_inserted = MMI_TRUE;

                                    strcpy(profile_p->to_proxy_combined, tmp_app_node->to_proxy);

                                    /* hash value of napid */
                                    memcpy(
                                        profile_p->napid_hash_val,
                                        tmp_app_node->napid_hash_val,
                                        SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN);
                                    break;
                                }
                            }
                        }
                    }
                }

                if (!is_inserted && cntx_p->num_profiles < SRV_EMAIL_OTAP_MAX_PROFILE_NUM)
                {
                    /* create a new profile */
                    profile_p = srv_email_otap_new_profile();
                    if (!profile_p)
                    {
                        return CCA_STATUS_FAIL;
                    }

                    cntx_p->profile[cntx_p->num_profiles++] = profile_p;

                    memcpy(
                        profile_p->smtp_node,
                        tmp_app_node,
                        sizeof(srv_email_otap_application_struct));
                    profile_p->is_have_smtp = MMI_TRUE;

                    strcpy(profile_p->to_proxy_combined, tmp_app_node->to_proxy);

                    /* hash value of napid */
                    memcpy(
                        profile_p->napid_hash_val,
                        tmp_app_node->napid_hash_val,
                        SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN);
                    mmi_wcscpy(profile_p->prof_name_combined, tmp_app_node->prof_name);
                }
            }
            break;

        case SRV_EMAIL_OTAP_APP_POP3:
        case SRV_EMAIL_OTAP_APP_IMAP4:
            if (mmi_wcslen(tmp_app_node->server_addr) && mmi_wcslen(tmp_app_node->username))
            {
                /* is a valid incoming node */
                for (i = 0; i < cntx_p->num_profiles; i++)
                {
                    profile_p = cntx_p->profile[i];

                    if (!profile_p->is_have_smtp && !profile_p->is_have_pop3_imap4)
                    {
                        memcpy(
                            profile_p->pop3_imap4_node,
                            tmp_app_node,
                            sizeof(srv_email_otap_application_struct));
                        profile_p->is_have_pop3_imap4 = MMI_TRUE;

                        is_inserted = MMI_TRUE;

                        strcpy(profile_p->to_proxy_combined, tmp_app_node->to_proxy);

                        /* hash value of napid */
                        memcpy(
                            profile_p->napid_hash_val,
                            tmp_app_node->napid_hash_val,
                            SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN);

                        if (mmi_wcslen(tmp_app_node->prof_name))
                        {
                            mmi_wcscpy(profile_p->prof_name_combined, tmp_app_node->prof_name);
                        }
                        break;
                    }
                    else if (profile_p->is_have_smtp && !profile_p->is_have_pop3_imap4)
                    {
                        if (!mmi_wcscmp(tmp_app_node->provider_id, profile_p->smtp_node->provider_id))
                        {
                            /* set prof_name_combined */
                            if (mmi_wcslen(tmp_app_node->prof_name) &&
                                !mmi_wcslen(profile_p->prof_name_combined))
                            {
                                mmi_wcscpy(profile_p->prof_name_combined, tmp_app_node->prof_name);
                            }

                            if (!strlen(tmp_app_node->to_proxy)) /* both not set */
                            {
                                memcpy(
                                    profile_p->pop3_imap4_node,
                                    tmp_app_node,
                                    sizeof(srv_email_otap_application_struct));
                                profile_p->is_have_pop3_imap4 = MMI_TRUE;

                                is_inserted = MMI_TRUE;

                                strcpy(profile_p->to_proxy_combined, profile_p->smtp_node->to_proxy);

                                /* hash value of napid */
                                memcpy(
                                    profile_p->napid_hash_val,
                                    profile_p->smtp_node->napid_hash_val,
                                    SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN);
                                break;
                            }
                            else if (!strlen(profile_p->smtp_node->to_proxy))   /* incoming set, but outgoing */
                            {
                                memcpy(
                                    profile_p->pop3_imap4_node,
                                    tmp_app_node,
                                    sizeof(srv_email_otap_application_struct));
                                profile_p->is_have_pop3_imap4 = MMI_TRUE;

                                is_inserted = MMI_TRUE;

                                strcpy(profile_p->to_proxy_combined, tmp_app_node->to_proxy);

                                /* hash value of napid */
                                memcpy(
                                    profile_p->napid_hash_val,
                                    tmp_app_node->napid_hash_val,
                                    SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN);
                                break;
                            }
                            else    /* both set */
                            {
                                if (!strcmp(tmp_app_node->to_proxy, profile_p->smtp_node->to_proxy))
                                {
                                    memcpy(
                                        profile_p->pop3_imap4_node,
                                        tmp_app_node,
                                        sizeof(srv_email_otap_application_struct));
                                    profile_p->is_have_pop3_imap4 = MMI_TRUE;

                                    is_inserted = MMI_TRUE;

                                    strcpy(profile_p->to_proxy_combined, tmp_app_node->to_proxy);

                                    /* hash value of napid */
                                    memcpy(
                                        profile_p->napid_hash_val,
                                        tmp_app_node->napid_hash_val,
                                        SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN);
                                    break;
                                }
                            }
                        }
                    }
                }

                if (!is_inserted && cntx_p->num_profiles < SRV_EMAIL_OTAP_MAX_PROFILE_NUM)
                {
                    /* create a new profile */
                    profile_p = srv_email_otap_new_profile();
                    if (!profile_p)
                    {
                        return CCA_STATUS_FAIL;
                    }

                    cntx_p->profile[cntx_p->num_profiles++] = profile_p;

                    memcpy(
                        profile_p->pop3_imap4_node,
                        tmp_app_node,
                        sizeof(srv_email_otap_application_struct));
                    profile_p->is_have_pop3_imap4 = MMI_TRUE;

                    strcpy(profile_p->to_proxy_combined, tmp_app_node->to_proxy);

                    /* hash value of napid */
                    memcpy(
                        profile_p->napid_hash_val,
                        tmp_app_node->napid_hash_val,
                        SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN);

                    if (mmi_wcslen(tmp_app_node->prof_name))
                    {
                        mmi_wcscpy(profile_p->prof_name_combined, tmp_app_node->prof_name);
                    }
                }
            }
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_proc_cca_param_bootstrap
 * DESCRIPTION
 *  This function is used to process the parameter of BOOTSTRAP node.
 * PARAMETERS
 *  param_p         [IN]        The parameter
 *  cntx_p          [IN]        The pointer point to the OTAP context
 * RETURNS
 *  The result.
 *****************************************************************************/
static cca_status_enum srv_email_otap_proc_cca_param_bootstrap(
                        const cca_core_data_struct *param_p,
                        srv_email_otap_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    if (param_p->id == CCA_NS_OMA_PROVURL)
    {
        if (param_p->values.s[0])
        {
            MMI_BOOL provurl_empty = srv_email_otap_hash_value_is_empty(
                                        cntx_p->provurl_hash_val,
                                        SRV_EMAIL_OTAP_PROVURL_HASH_VALUE_LEN);
            U32 len = strlen(param_p->values.s[0]);

            if (provurl_empty && len > 0)
            {
                mmi_cca_generate_hash_value(
                    (const CHAR*)param_p->values.s[0],
                    cntx_p->provurl_hash_val,
                    SRV_EMAIL_OTAP_PROVURL_HASH_VALUE_LEN);
            }
        }
    }
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_proc_cca_param_proxy
 * DESCRIPTION
 *  This function is used to process the parameter of PROXY node.
 * PARAMETERS
 *  param_p         [IN]        The parameter
 *  proxy_p         [IN]        The pointer point to the proxy node
 * RETURNS
 *  The result.
 *****************************************************************************/
static cca_status_enum srv_email_otap_proc_cca_param_proxy(
                        const cca_core_data_struct *param_p,
                        srv_email_otap_proxy_node_struct *proxy_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param_p->id)
    {
        case CCA_NS_OMA_PROXY_ID:
            if (param_p->values.s[0])
            {
                len = strlen(param_p->values.s[0]);
                if (len > 0)
                {
                    srv_email_otap_strcpy(
                        proxy_p->proxy_parms.proxy_id,
                        param_p->values.s[0],
                        SRV_EMAIL_OTAP_MAX_PROXY_ID_LEN + 1);

                    proxy_p->proxy_parms.is_have_proxy_id = MMI_TRUE;
                }
            }
            break;

        case CCA_NS_DATAACCTID:
            if (param_p->values.i[0] == CCA_NS_VAL__INVALID ||
                param_p->values.i[0] == CCA_NS_VAL__EMPTY)
            {
                proxy_p->proxy_parms.is_have_dataacctid = MMI_FALSE;
            }
            else
            {
                proxy_p->proxy_parms.data_acct_id = param_p->values.i[0];
                proxy_p->proxy_parms.is_have_dataacctid = MMI_TRUE;
            }
            break;

        default:
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_proc_cca_param_application
 * DESCRIPTION
 *  This function is used to process the parameter of APPLICATION node.
 * PARAMETERS
 *  param_p         [IN]        The parameter
 *  cntx_p          [IN]        The pointer point to the OTAP context
 * RETURNS
 *  The result.
 *****************************************************************************/
static cca_status_enum srv_email_otap_proc_cca_param_application(
                        const cca_core_data_struct *param_p,
                        srv_email_otap_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_otap_application_struct *tmp_app_node = cntx_p->tmp_app_node;
    WCHAR *tmp_ucs2_buf = NULL;
    U32 out_len = 0;
    U32 len = 0;
    S32 i = 0;
    srv_email_otap_proxy_node_struct *proxy_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param_p->id)
    {
        case CCA_NS_OMA_APPID:
            if (param_p->values.s[0])
            {
                if (!strcmp(param_p->values.s[0], "25"))
                {
                    tmp_app_node->app_type = SRV_EMAIL_OTAP_APP_SMTP;
                }
                else if (!strcmp(param_p->values.s[0], "110"))
                {
                    tmp_app_node->app_type = SRV_EMAIL_OTAP_APP_POP3;
                }
                else if (!strcmp(param_p->values.s[0], "143"))
                {
                    tmp_app_node->app_type = SRV_EMAIL_OTAP_APP_IMAP4;
                }
                else
                {
                    tmp_app_node->app_type = SRV_EMAIL_OTAP_APP_NONE;
                }
            }
            break;

        case CCA_NS_OMA_NAME:
            if (param_p->values.s[0])
            {
                len = strlen(param_p->values.s[0]);
                if (len > 0)
                {
                    tmp_ucs2_buf = srv_email_otap_utf8_to_ucs2(param_p->values.s[0], &out_len);
                    if (tmp_ucs2_buf)
                    {
                        srv_email_otap_wstrcpy(
                            tmp_app_node->prof_name,
                            tmp_ucs2_buf,
                            SRV_EMAIL_MAX_ACCT_NAME_LEN + 1);
                        OslMfree(tmp_ucs2_buf);
                    }
                }
            }
            break;

        case CCA_NS_OMA_PROVIDER_ID:
            if (param_p->values.s[0])
            {
                len = strlen(param_p->values.s[0]);
                if (len > 0)
                {
                    tmp_ucs2_buf = srv_email_otap_utf8_to_ucs2(param_p->values.s[0], &out_len);
                    if (tmp_ucs2_buf)
                    {
                        srv_email_otap_wstrcpy(
                            tmp_app_node->provider_id,
                            tmp_ucs2_buf,
                            SRV_EMAIL_MAX_ACCT_NAME_LEN + 1);
                        OslMfree(tmp_ucs2_buf);
                    }
                }
            }
            break;

        case CCA_NS_OMA_TO_PROXY:
            for (i = 0; i < param_p->size; i++)
            {
                for (proxy_p = cntx_p->proxy_linklist; proxy_p != NULL; proxy_p = proxy_p->next)
                {
                    if (param_p->values.s[i] &&
                        !strcmp(proxy_p->proxy_parms.proxy_id, param_p->values.s[i]))
                    {
                        break;
                    }
                }

                if (proxy_p != NULL)
                {
                    break;
                }
            }

            if (i >= param_p->size)
            {
                i = 0;
            }

            if (param_p->values.s[i])
            {
                len = strlen(param_p->values.s[i]);
                if (len > 0)
                {
                    srv_email_otap_strcpy(
                        tmp_app_node->to_proxy,
                        param_p->values.s[i],
                        SRV_EMAIL_OTAP_MAX_PROXY_ID_LEN + 1);

                    mmi_cca_generate_hash_value(
                        param_p->values.s[i],
                        tmp_app_node->napid_hash_val,
                        SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN);
                }
            }
            break;

        case CCA_NS_OMA_FROM:
            if (param_p->values.s[0])
            {
                len = strlen(param_p->values.s[0]);
                if (len > 0)
                {
                    CHAR from_name[SRV_EMAIL_MAX_DISP_NAME_LEN * SRV_EMAIL_OTAP_UTF8_ENCODING_LENGTH]; /* nick name after split from */
                    CHAR from_addr[SRV_EMAIL_MAX_ADDR_LEN + 1];   /* email address after split from */
                    WCHAR *tmp_ucs2_from_name = NULL;

                    srv_email_otap_split_from(param_p->values.s[0], from_name, from_addr);
                    if (applib_is_valid_email_address(from_addr))
                    {
                        /* copy from_name */
                        len = strlen(from_name);
                        if (len > 0)
                        {
                            tmp_ucs2_from_name = srv_email_otap_utf8_to_ucs2(from_name, &out_len);
                            if (tmp_ucs2_from_name)
                            {
                                srv_email_otap_correct_disp_name(tmp_ucs2_from_name);

                                srv_email_otap_wstrcpy(
                                    tmp_app_node->from_name,
                                    tmp_ucs2_from_name,
                                    SRV_EMAIL_MAX_DISP_NAME_LEN + 1);
                                OslMfree(tmp_ucs2_from_name);
                            }
                        }

                        /* copy from_address */
                        len = strlen(from_addr);
                        if (len > SRV_EMAIL_MAX_ADDR_LEN)
                        {
                            len = SRV_EMAIL_MAX_ADDR_LEN;
                        }
                        mmi_asc_n_to_ucs2((CHAR*)tmp_app_node->from_addr, from_addr, len);
                        tmp_app_node->from_addr[len] = 0;
                    }
                }
            }
            break;

        case CCA_NS_OMA_RT_ADDR:
            if (param_p->values.s[0])
            {
                len = strlen(param_p->values.s[0]);
                if (len > 0)
                {
                    if (applib_is_valid_email_address(param_p->values.s[0]))
                    {
                        if (len > SRV_EMAIL_MAX_ADDR_LEN)
                        {
                            len = SRV_EMAIL_MAX_ADDR_LEN;
                        }
                        mmi_asc_n_to_ucs2((CHAR*)tmp_app_node->rt_addr, param_p->values.s[0], len);
                        tmp_app_node->rt_addr[len] = 0;
                    }
                }
            }
            break;

        case CCA_NS_OMA_ADDR:
            if (param_p->values.s[0])
            {
                len = strlen(param_p->values.s[0]);
                if (len > 0)
                {
                    tmp_ucs2_buf = srv_email_otap_utf8_to_ucs2(param_p->values.s[0], &out_len);
                    if (tmp_ucs2_buf)
                    {
                        if (srv_email_otap_is_server_vaild(tmp_ucs2_buf))
                        {
                            srv_email_otap_wstrcpy(
                                tmp_app_node->server_addr,
                                tmp_ucs2_buf,
                                SRV_EMAIL_MAX_SERVER_NAME_LEN + 1);
                        }
                        OslMfree(tmp_ucs2_buf);
                    }
                }
            }
            break;

        default:
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_proc_cca_param_appaddr
 * DESCRIPTION
 *  This function is used to process the parameter of APPADDR node.
 * PARAMETERS
 *  param_p         [IN]        The parameter
 *  cntx_p          [IN]        The pointer point to the OTAP context
 * RETURNS
 *  The result.
 *****************************************************************************/
static cca_status_enum srv_email_otap_proc_cca_param_appaddr(
                        const cca_core_data_struct *param_p,
                        srv_email_otap_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_otap_application_struct *tmp_app_node = cntx_p->tmp_app_node;
    srv_email_otap_application_struct *curr_node = cntx_p->curr_node;
    WCHAR *tmp_ucs2_buf = NULL;
    U32 out_len = 0;
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param_p->id)
    {
        case CCA_NS_OMA_ADDR:
            if (param_p->values.s[0])
            {
                if (strlen((CHAR*)param_p->values.s[0]) > 0)
                {
                    tmp_ucs2_buf = srv_email_otap_utf8_to_ucs2(param_p->values.s[0], &out_len);
                    if (tmp_ucs2_buf)
                    {
                        if (srv_email_otap_is_server_vaild(tmp_ucs2_buf))
                        {
                            srv_email_otap_wstrcpy(
                                tmp_app_node->server_addr,
                                tmp_ucs2_buf,
                                SRV_EMAIL_MAX_SERVER_NAME_LEN + 1);
                        }
                        OslMfree(tmp_ucs2_buf);
                    }
                }
            }
            break;

        case CCA_NS_OMA_ADDRTYPE:
            if (param_p->values.i[0] == CCA_NS_VAL__INVALID)
            {
                return CCA_STATUS_FAIL;
            }
            else if (param_p->values.i[0] == CCA_NS_VAL__EMPTY)
            {
                curr_node->server_addr_type = CCA_NS_VAL_IPV4;
            }
            else
            {
                curr_node->server_addr_type = param_p->values.i[0];
            }
            break;

        case CCA_NS_OMA_PORTNBR:
            if (param_p->values.s[0])
            {
                U8 i;
                U16 portnbr;
                MMI_BOOL is_portnbr_valid = MMI_TRUE;

                len = strlen(param_p->values.s[0]);
                if (len == 0 || len > 5)
                {
                    is_portnbr_valid = MMI_FALSE;
                }
                else
                {
                    for (i = 0; i < len; i++)
                    {
                        if (param_p->values.s[0][i] < '0' || param_p->values.s[0][i] > '9')
                        {
                            is_portnbr_valid = MMI_FALSE;
                            break;
                        }
                    }
                }

                if (is_portnbr_valid)
                {
                    portnbr = (U16)atoi(param_p->values.s[0]);
                    if (portnbr > 0 && portnbr < 65536)
                    {
                        curr_node->port_num = portnbr;
                    }
                }
            }
            break;

        case CCA_NS_OMA_SERVICE:
            if (param_p->values.i[0] == CCA_NS_VAL__INVALID)
            {
                return CCA_STATUS_FAIL;
            }
            else if (param_p->values.i[0] == CCA_NS_VAL__EMPTY)
            {
                curr_node->service = CCA_NS_VAL_CL_WSP;
            }
            else
            {
                curr_node->service = param_p->values.i[0];
            }
            break;

        default:
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_proc_cca_param_appauth
 * DESCRIPTION
 *  This function is used to process the parameter of APPAUTH.
 * PARAMETERS
 *  param_p         [IN]        The parameter
 *  cntx_p          [IN]        The pointer point to the OTAP context
 * RETURNS
 *  The result.
 *****************************************************************************/
static cca_status_enum srv_email_otap_proc_cca_param_appauth(
                        const cca_core_data_struct *param_p,
                        srv_email_otap_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_otap_application_struct *curr_node = cntx_p->curr_node;
    WCHAR *tmp_ucs2_buf = NULL;
    U32 out_len = 0;
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param_p->id)
    {
        case CCA_NS_OMA_AAUTHTYPE:
            if (param_p->values.i[0] == CCA_NS_VAL__INVALID)
            {
                return CCA_STATUS_FAIL;
            }
            else if (param_p->values.i[0] == CCA_NS_VAL__EMPTY)
            {
                curr_node->server_addr_type = CCA_NS_VAL_HTTP_BASIC;
            }
            else
            {
                curr_node->server_addr_type = param_p->values.i[0];
            }
            break;

        case CCA_NS_OMA_AAUTHNAME:
            if (param_p->values.s[0])
            {
                len = strlen(param_p->values.s[0]);
                if (len > 0)
                {
                    tmp_ucs2_buf = srv_email_otap_utf8_to_ucs2(param_p->values.s[0], &out_len);
                    if (tmp_ucs2_buf)
                    {
                        if (srv_email_otap_is_username_vaild(tmp_ucs2_buf))
                        {
                            srv_email_otap_wstrcpy(
                                curr_node->username,
                                tmp_ucs2_buf,
                                SRV_EMAIL_MAX_USERNAME_LEN + 1);
                        }
                        OslMfree(tmp_ucs2_buf);
                    }
                }
            }
            break;

        case CCA_NS_OMA_AAUTHSECRET:
            if (param_p->values.s[0])
            {
                len = strlen(param_p->values.s[0]);
                if (len > 0)
                {
                    tmp_ucs2_buf = srv_email_otap_utf8_to_ucs2(param_p->values.s[0], &out_len);
                    if (tmp_ucs2_buf)
                    {
                        if (srv_email_otap_is_password_valid(tmp_ucs2_buf))
                        {
                            srv_email_otap_wstrcpy(
                                curr_node->password,
                                tmp_ucs2_buf,
                                SRV_EMAIL_MAX_PASSWORD_LEN + 1);
                        }
                        OslMfree(tmp_ucs2_buf);
                    }
                }
            }
            break;

        default:
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_proc_cca_nodes
 * DESCRIPTION
 *  This function is used to process the CCA document.
 * PARAMETERS
 *  doc_hdl         [IN]        The configuration document handle
 *  node_hdl        [IN]        The node handle
 *  symbol          [IN]        The converted node symbol
 *  param_list      [IN]        The list of parameters in the node
 *  user_data       [IN]        The User data
 * RETURNS
 *  The result.
 *****************************************************************************/
static cca_status_enum srv_email_otap_proc_cca_nodes(
                        S32 doc_hdl,
                        S32 node_hdl,
                        U16 symbol,
                        cca_iterator_struct *param_list,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_otap_cntx_struct *cntx_p = (srv_email_otap_cntx_struct*)user_data;
    cca_core_data_struct *param_p = NULL;
    cca_status_enum status = CCA_STATUS_OK;
    srv_email_otap_proxy_node_struct *proxy_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (symbol)
    {
        case SRV_EMAIL_OTAP_NS_BOOTSTRAP:
            /* Store the PROVURL */
            while (mmi_cca_doc_nodedata_next(param_list, &param_p) == CCA_STATUS_OK && status == CCA_STATUS_OK)
            {
                status = srv_email_otap_proc_cca_param_bootstrap(param_p, cntx_p);
            }
            break;

        case SRV_EMAIL_OTAP_NS_PROXY:
            proxy_p = (srv_email_otap_proxy_node_struct*)OslMalloc(sizeof(srv_email_otap_proxy_node_struct));
            if (!proxy_p)
            {
                return CCA_STATUS_FAIL;
            }
            memset(proxy_p, 0, sizeof(srv_email_otap_proxy_node_struct));

            /* Read all the parameters of the PROXY node */
            while (mmi_cca_doc_nodedata_next(param_list, &param_p) == CCA_STATUS_OK && status == CCA_STATUS_OK)
            {
                status = srv_email_otap_proc_cca_param_proxy(param_p, proxy_p);
            }

            if (!proxy_p->proxy_parms.is_have_proxy_id || !proxy_p->proxy_parms.is_have_dataacctid)
            {
                OslMfree(proxy_p);
            }
            else
            {
                srv_email_otap_add_proxy_node_to_tail(cntx_p, proxy_p);
            }
            break;

        case SRV_EMAIL_OTAP_NS_APPLICATION:
            /* Add the previous tmp_app_node into profile */
            status = srv_email_otap_add_application_to_profile(cntx_p);
            if (status != CCA_STATUS_OK)
            {
                return status;
            }

            memset(cntx_p->tmp_app_node, 0, sizeof(srv_email_otap_application_struct));

            while (mmi_cca_doc_nodedata_next(param_list, &param_p) == CCA_STATUS_OK && status == CCA_STATUS_OK)
            {
                status = srv_email_otap_proc_cca_param_application(param_p, cntx_p);
            }
            break;

        case SRV_EMAIL_OTAP_NS_APPADDR:
            /* Add into current node */
            cntx_p->curr_node = cntx_p->tmp_app_node;
            if (cntx_p->curr_node)
            {
                while (mmi_cca_doc_nodedata_next(param_list, &param_p) == CCA_STATUS_OK && status == CCA_STATUS_OK)
                {
                    status = srv_email_otap_proc_cca_param_appaddr(param_p, cntx_p);
                }
            }
            break;

        case SRV_EMAIL_OTAP_NS_APPAUTH:
            /* Add in current node */
            cntx_p->curr_node = cntx_p->tmp_app_node;
            if (cntx_p->curr_node)
            {
                while (mmi_cca_doc_nodedata_next(param_list, &param_p) == CCA_STATUS_OK && status == CCA_STATUS_OK)
                {
                    status = srv_email_otap_proc_cca_param_appauth(param_p, cntx_p);
                }
            }
            break;

        default:
            break;
    }

    return CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_add_dataacctid_to_profile
 * DESCRIPTION
 *  This function is used to set the data account id.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the OTAP context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_otap_add_dataacctid_to_profile(srv_email_otap_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_otap_proxy_node_struct *proxy_p = NULL;
    srv_email_otap_profile_struct *profile_p = NULL;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < cntx_p->num_profiles; i++)
    {
        proxy_p = cntx_p->proxy_linklist;
        profile_p = cntx_p->profile[i];

        while (proxy_p)
        {
            if (!strcmp(proxy_p->proxy_parms.proxy_id, profile_p->to_proxy_combined))
            {
                profile_p->data_acct_id = proxy_p->proxy_parms.data_acct_id;
                profile_p->is_have_dataacctid = MMI_TRUE;
                break;
            }
            proxy_p = proxy_p->next;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_check_profile_validity
 * DESCRIPTION
 *  This function checks the validity of a Profile
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the OTAP context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_otap_check_profile_validity(srv_email_otap_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_otap_profile_struct *prof_list[SRV_EMAIL_OTAP_MAX_PROFILE_NUM];
    srv_email_otap_profile_struct *profile_p = NULL;
    U8 count = 0;
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < cntx_p->num_profiles; i++)
    {
        profile_p = cntx_p->profile[i];

        if (!profile_p->is_have_smtp && !profile_p->is_have_pop3_imap4)
        {
            profile_p->is_valid_profile = MMI_FALSE;
        }
        else if (srv_email_otap_is_valid_but_discard(
                    cntx_p->provurl_hash_val,
                    profile_p->napid_hash_val,
                    cntx_p->prov_flag & MMI_CCA_PROV_FLAG_FACTORY_PROFILE_UPDATABLE,
                    profile_p->prof_name_combined))
        {
            profile_p->is_valid_profile = MMI_FALSE;
        }

        if (profile_p->is_valid_profile)
        {
            prof_list[count++] = profile_p;
        }
        else
        {
            srv_email_otap_free_profile(profile_p);
        }
    }

    for (i = 0; i < count; i++)
    {
        profile_p = prof_list[i];

        if (profile_p->is_have_pop3_imap4)
        {
            if (profile_p->pop3_imap4_node->app_type == SRV_EMAIL_OTAP_APP_POP3)
            {
                profile_p->in_protocol_type = SRV_EMAIL_PROT_POP3;
            }
            else
            {
                profile_p->in_protocol_type = SRV_EMAIL_PROT_IMAP4;
            }
        }
        else
        {
            profile_p->in_protocol_type = SRV_EMAIL_PROT_NONE;
        }

        profile_p->is_updateble =
            srv_email_otap_is_matched_acct(
                cntx_p->provurl_hash_val,
                profile_p->napid_hash_val,
                cntx_p->prov_flag & MMI_CCA_PROV_FLAG_FACTORY_PROFILE_UPDATABLE,
                profile_p->prof_name_combined,
                &profile_p->matched_acct_id);

        cntx_p->profile[i] = profile_p;
    }

    for (; i < cntx_p->num_profiles; i++)
    {
        cntx_p->profile[i] = NULL;
    }

    cntx_p->num_profiles = count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_exec_proc_cca_doc
 * DESCRIPTION
 *  This function is used to parse the CCA doc.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the OTAP context
 * RETURNS
 *  The parse result.
 *****************************************************************************/
static cca_status_enum srv_email_otap_exec_proc_cca_doc(srv_email_otap_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const U16 proc_tbl[] =
    {
        CCA_NS_TRIGNODE, CCA_NS_OMA_BOOTSTRAP, SRV_EMAIL_OTAP_NS_BOOTSTRAP, 0XFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_PROXY, SRV_EMAIL_OTAP_NS_PROXY, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, SRV_EMAIL_OTAP_NS_APPLICATION, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_APPADDR, SRV_EMAIL_OTAP_NS_APPADDR, 0xFFFF,
        CCA_NS_TRIGNODE, CCA_NS_OMA_APPLICATION, CCA_NS_OMA_APPAUTH, SRV_EMAIL_OTAP_NS_APPAUTH, 0xFFFF
    };

    cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p->tmp_app_node = (srv_email_otap_application_struct*)
        OslMalloc(sizeof(srv_email_otap_application_struct));
    if (!cntx_p->tmp_app_node)
    {
        return CCA_STATUS_FAIL;
    }
    memset(cntx_p->tmp_app_node, 0, sizeof(srv_email_otap_application_struct));

    cntx_p->profile[0] = srv_email_otap_new_profile();
    if (!cntx_p->profile[0])
    {
        return CCA_STATUS_FAIL;
    }
    cntx_p->num_profiles++;

    status = mmi_cca_doc_process(
                cntx_p->doc_hdl,
                proc_tbl,
                sizeof(proc_tbl) / sizeof(U16),
                NULL,
                srv_email_otap_proc_cca_nodes,
                cntx_p);
    if (status != CCA_STATUS_OK)
    {
        return status;
    }

    status = srv_email_otap_add_application_to_profile(cntx_p);
    if (status != CCA_STATUS_OK)
    {
        return status;
    }

    OslMfree(cntx_p->tmp_app_node);
    cntx_p->tmp_app_node = NULL;

    srv_email_otap_add_dataacctid_to_profile(cntx_p);

    srv_email_otap_check_profile_validity(cntx_p);

    if (cntx_p->num_profiles)
    {
        return CCA_STATUS_OK;
    }
    else
    {
        return CCA_STATUS_INVALID_SETTING;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_email_otap_get_cca_status
 * DESCRIPTION
 *  This function is used to get the CCA status.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the OTAP context
 * RETURNS
 *  The CCA status.
 *****************************************************************************/
static cca_status_enum srv_email_otap_get_cca_status(srv_email_otap_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL endkey = (cntx_p->cca_status == CCA_STATUS_ENDKEY_PRESSED ? MMI_TRUE : MMI_FALSE);
    U32 skip_num = 0;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < cntx_p->num_profiles; i++)
    {
        if (cntx_p->profile[i]->cca_prof_status == CCA_STATUS_SETTING_UPDATED)
        {
            if (endkey)
            {
                return CCA_STATUS_ENDKEY_SETTING_UPDATED;
            }
            else
            {
                return CCA_STATUS_SETTING_UPDATED;
            }
        }
    }

    for (i = 0; i < cntx_p->num_profiles; i++)
    {
        if (cntx_p->profile[i]->cca_prof_status == CCA_STATUS_OK)
        {
            if (endkey)
            {
                return CCA_STATUS_ENDKEY_SETTING_INSTALLED;
            }
            else
            {
                return CCA_STATUS_OK;
            }
        }
    }

    for (i = 0; i < cntx_p->num_profiles; i++)
    {
        if (cntx_p->profile[i]->cca_prof_status == CCA_STATUS_SETTING_SKIPPED)
        {
            skip_num++;
        }
    }

    if (skip_num == cntx_p->num_profiles)
    {
        if (endkey)
        {
            return CCA_STATUS_ENDKEY_SETTING_SKIPPED;
        }
        else
        {
            return CCA_STATUS_SETTING_SKIPPED;
        }
    }

    if (endkey)
    {
        return CCA_STATUS_ENDKEY_PRESSED;
    }
    else
    {
        return CCA_STATUS_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_send_cca_rsp
 * DESCRIPTION
 *  This function is used to send the result to CCA.
 * PARAMETERS
 *  config_id       [IN]        The config id
 *  hConfig         [IN]        The config handle
 *  status          [IN]        The config status
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_otap_send_cca_rsp(U16 config_id, S32 hConfig, cca_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cca_app_configure_rsp_struct *rsp_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_p = OslAllocDataPtr(mmi_cca_app_configure_rsp_struct);

    rsp_p->config_id = config_id;
    rsp_p->hConfig = hConfig;
    rsp_p->status = status;

    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_CCA_APP_CONFIGURE_RSP, (oslParaType*)rsp_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_fill_acct_info
 * DESCRIPTION
 *  This function is used to fill the account info with the specified profile.
 * PARAMETERS
 *  acct_p          [OUT]       The pointer point to the account info
 *  profile_p       [IN]        The pointer point to the profile
 *  prof_name       [IN]        The pointer point to the profile name
 *  cntx_p          [IN]        The pointer point to the OTAP context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_otap_fill_acct_info(
                srv_email_acct_info_struct *acct_p,
                srv_email_otap_profile_struct *profile_p,
                const WCHAR *prof_name,
                srv_email_otap_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_otap_application_struct *outgoing_p = profile_p->smtp_node;
    srv_email_otap_application_struct *incoming_p = profile_p->pop3_imap4_node;
    cbm_sim_id_enum sim_id = CBM_SIM_ID_SIM1;
    U32 dtcnt_id = 0;
    U32 sim_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Skip the acct_id, acct_type and read_only */
    if (profile_p->is_have_dataacctid)
    {
        if (cntx_p->sim_id == MMI_CCA_SIM_ID_SIM2)
        {
            sim_id = CBM_SIM_ID_SIM2;
        }

        dtcnt_id = cbm_encode_data_account_id((U32)profile_p->data_acct_id, sim_id, 0, MMI_FALSE);

        sim_index = mmi_frm_sim_to_index((mmi_sim_enum)cntx_p->sim_id);

        if (profile_p->is_have_smtp || cntx_p->option.same_dtcnt)
        {
            acct_p->out_server.data_acct[sim_index] = dtcnt_id;
        }
        if (profile_p->is_have_dataacctid || cntx_p->option.same_dtcnt)
        {
            acct_p->in_server.data_acct[sim_index] = dtcnt_id;
        }
    }

    if (profile_p->is_have_smtp)
    {
        /* From */
        if (mmi_wcslen(outgoing_p->from_addr) > 0)
        {
            mmi_wcscpy(acct_p->email_addr.email_addr, outgoing_p->from_addr);
        }
        if (mmi_wcslen(outgoing_p->from_name) > 0)
        {
            acct_p->email_addr.disp_charset = MMI_CHSET_UCS2;
            acct_p->email_addr.disp_name_len = mmi_wcslen(outgoing_p->from_name);
            mmi_wcscpy(acct_p->email_addr.disp_name, outgoing_p->from_name);
        }

        /* Reply-to */
        if (mmi_wcslen(outgoing_p->rt_addr) > 0)
        {
            mmi_wcscpy(acct_p->reply_to_addr.email_addr, outgoing_p->rt_addr);
        }

        /* Outgoing server */
        if (mmi_wcslen(outgoing_p->server_addr) > 0)
        {
            mmi_wcscpy(acct_p->out_server.server_name, outgoing_p->server_addr);
        }
        if (outgoing_p->service == CCA_NS_VAL_STARTTLS)
        {
            acct_p->out_server.sec_mode = SRV_EMAIL_SEC_STARTTLS;
        }
        if (outgoing_p->port_num)
        {
            acct_p->out_server.port_num = outgoing_p->port_num;
        }

        /* Outgoing auth */
        if (mmi_wcslen(outgoing_p->username) > 0)
        {
            mmi_wcscpy(acct_p->out_auth.username, outgoing_p->username);
            acct_p->out_auth.auth_type = SRV_EMAIL_AUTH_USER;
        }
        if (mmi_wcslen(outgoing_p->password) > 0)
        {
            mmi_wcscpy(acct_p->out_auth.password, outgoing_p->password);
            acct_p->out_auth.auth_type = SRV_EMAIL_AUTH_USER;
        }
    }

    if (profile_p->is_have_pop3_imap4)
    {
        acct_p->protocol = profile_p->in_protocol_type;

        /* Incoming server */
        if (mmi_wcslen(incoming_p->server_addr) > 0)
        {
            mmi_wcscpy(acct_p->in_server.server_name, incoming_p->server_addr);
        }
        if (incoming_p->service == CCA_NS_VAL_STARTTLS)
        {
            acct_p->in_server.sec_mode = SRV_EMAIL_SEC_STARTTLS;
        }
        if (incoming_p->port_num)
        {
            acct_p->in_server.port_num = incoming_p->port_num;
        }

        /* Incoming auth */
        if (mmi_wcslen(incoming_p->username) > 0)
        {
            mmi_wcscpy(acct_p->in_auth.username, incoming_p->username);
        }
        if (mmi_wcslen(incoming_p->password) > 0)
        {
            mmi_wcscpy(acct_p->in_auth.password, incoming_p->password);
        }
    }

    if (!profile_p->is_updateble)
    {
        memcpy(
            acct_p->provurl_hash,
            cntx_p->provurl_hash_val,
            SRV_EMAIL_OTAP_PROVURL_HASH_VALUE_LEN);
        acct_p->read_only = MMI_FALSE;
        acct_p->acct_type = SRV_EMAIL_ACCT_OTAP_CONFIGURED;
    }

    memcpy(
        acct_p->napid_hash,
        profile_p->napid_hash_val,
        SRV_EMAIL_OTAP_NAPID_HASH_VALUE_LEN);

    if (prof_name && mmi_wcslen(prof_name) > 0)
    {
        mmi_wcscpy(acct_p->acct_name, prof_name);
    }

    /* Update the acct_attr */
    acct_p->acct_attr &= ~(SRV_EMAIL_ACCT_ATTR_SMTP | SRV_EMAIL_ACCT_ATTR_POP3 | SRV_EMAIL_ACCT_ATTR_IMAP4);

    if (mmi_wcslen(acct_p->out_server.server_name) > 0)
    {
        acct_p->acct_attr |= SRV_EMAIL_ACCT_ATTR_SMTP;
    }

    if (acct_p->protocol == SRV_EMAIL_PROT_POP3)
    {
        acct_p->acct_attr |= SRV_EMAIL_ACCT_ATTR_POP3;
    }
    else if (acct_p->protocol == SRV_EMAIL_PROT_IMAP4)
    {
        acct_p->acct_attr |= SRV_EMAIL_ACCT_ATTR_IMAP4;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_acct_save_done
 * DESCRIPTION
 *  This function is used to process the result of saving account.
 * PARAMETERS
 *  ret             [IN]        The result of saving account
 *  user_data       [IN]        The OTAP handle
 * RETURNS
 *  void
 ****************************************************************************/
static void srv_email_otap_acct_save_done(srv_email_result_enum ret, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_otap_cntx_struct *cntx_p = (srv_email_otap_cntx_struct*)user_data;
    srv_email_result_struct result;
    EMAIL_ACCT_ID acct_id = EMAIL_ACCT_INVALID_ID;
    srv_email_otap_action_enum action = SRV_EMAIL_OTAP_ACTION_NONE;
    srv_email_otap_funcptr_type callback = NULL;
    void *callback_user_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx_p || cntx_p != srv_email_otap_cntx_p)
    {
        return;
    }

    if (cntx_p->action == SRV_EMAIL_OTAP_ACTION_NONE)
    {
        return;
    }

    EMAILSRV_EXT_ASSERT(
        (cntx_p->acct_handle != EMAIL_ACCT_INVALID_HANDLE && cntx_p->profile_p && cntx_p->callback),
        (U32)cntx_p->acct_handle,
        (U32)cntx_p->profile_p,
        (U32)cntx_p->callback);

    srv_email_acct_destroy(cntx_p->acct_handle);

    memset(&result, 0, sizeof(srv_email_result_struct));
    acct_id = cntx_p->acct_id;
    action = cntx_p->action;
    callback = cntx_p->callback;
    callback_user_data = cntx_p->user_data;

    if (ret == SRV_EMAIL_RESULT_SUCC)
    {
        cntx_p->profile_p->cca_prof_status = CCA_STATUS_OK;
        result.result = MMI_TRUE;
        result.sub_result = MMI_TRUE;
    }
    else
    {
        srv_email_acct_delete(acct_id);
        acct_id = EMAIL_ACCT_INVALID_ID;
        cntx_p->profile_p->cca_prof_status = CCA_STATUS_FAIL;
        result.result = MMI_FALSE;
        result.sub_result = MMI_TRUE;
        srv_email_get_stor_error(ret, &result.major, &result.minor);
    }

    cntx_p->action = SRV_EMAIL_OTAP_ACTION_NONE;
    cntx_p->acct_handle = EMAIL_ACCT_INVALID_HANDLE;
    cntx_p->acct_id = EMAIL_ACCT_INVALID_ID;
    cntx_p->profile_p = NULL;
    cntx_p->callback = NULL;
    cntx_p->user_data = NULL;

    callback(&result, acct_id, action, callback_user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_add_prof_ext
 * DESCRIPTION
 *  This function is used to create a new account with the specified profile.
 * PARAMETERS
 *  handle          [IN]        The OTAP handle
 *  prof_index      [IN]        The profile's index
 *  prof_name       [IN]        The profile name
 *  acct_id         [OUT]       Used to store the new account id
 *  async_mode      [IN]        If async mode or not
 * RETURNS
 *  The result code.
 ****************************************************************************/
static srv_email_result_enum srv_email_otap_add_prof_ext(
                                EMAIL_OTAP_HANDLE handle,
                                U32 prof_index,
                                const WCHAR *prof_name,
                                EMAIL_ACCT_ID *acct_id,
                                MMI_BOOL async_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_otap_cntx_struct *cntx_p = (srv_email_otap_cntx_struct*)handle;
    srv_email_otap_profile_struct *profile_p = NULL;
    srv_email_acct_info_struct *acct_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    EMAIL_SRV_HANDLE srv_handle = EMAIL_SRV_INVALID_HANDLE;
    EMAIL_ACCT_HANDLE acct_handle = EMAIL_ACCT_INVALID_HANDLE;
    EMAIL_ACCT_ID new_acct_id = EMAIL_ACCT_INVALID_ID;
    MMI_BOOL acct_need_del = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx_p || cntx_p != srv_email_otap_cntx_p)
    {
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (prof_index >= cntx_p->num_profiles)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    if (cntx_p->action != SRV_EMAIL_OTAP_ACTION_NONE)
    {
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    profile_p = cntx_p->profile[prof_index];

    if (profile_p->cca_prof_status != CCA_STATUS_SETTING_NOT_INSTALLED)
    {
        return SRV_EMAIL_RESULT_INVALID_OPERATION;
    }

    acct_p = (srv_email_acct_info_struct*)OslMalloc(sizeof(srv_email_acct_info_struct));
    if (!acct_p)
    {
        goto EXIT_HANDLE;
    }
    srv_email_acct_init_acct_info(acct_p);
    acct_p->out_server.port_num = 25;
    acct_p->out_server.sec_port_num = 465;
    if (profile_p->is_have_pop3_imap4)
    {
        if (profile_p->in_protocol_type == SRV_EMAIL_PROT_POP3)
        {
            acct_p->in_server.port_num = 110;
            acct_p->in_server.sec_port_num = 995;
        }
        else
        {
            acct_p->in_server.port_num = 143;
            acct_p->in_server.sec_port_num = 993;
        }
    }

    /* Fill the acct info */
    srv_email_otap_fill_acct_info(acct_p, profile_p, prof_name, cntx_p);

    srv_handle = srv_email_get_int_srv_handle();

    retval = srv_email_acct_create(srv_handle, &acct_handle);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        goto EXIT_HANDLE;
    }

    retval = srv_email_acct_new(acct_handle, &new_acct_id);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        goto EXIT_HANDLE;
    }
    acct_need_del = MMI_TRUE;

	acct_p->acct_id = new_acct_id;
    retval = srv_email_acct_edit(acct_handle, acct_p);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        goto EXIT_HANDLE;
    }

    if (async_mode)
    {
        retval = srv_email_acct_save_async(
                    acct_handle,
                    srv_email_otap_acct_save_done,
                    cntx_p);

        if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            cntx_p->action = SRV_EMAIL_OTAP_ACTION_ADD;
            cntx_p->acct_handle = acct_handle;
            cntx_p->acct_id = new_acct_id;
            cntx_p->profile_p = profile_p;
            acct_handle = EMAIL_ACCT_INVALID_HANDLE;
        }
    }
    else
    {
        retval = srv_email_acct_save(acct_handle);
    }

EXIT_HANDLE:
    if (acct_p)
    {
        OslMfree(acct_p);
    }

    if (acct_handle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acct_handle);
    }

    if (retval == SRV_EMAIL_RESULT_SUCC)
    {
        profile_p->cca_prof_status = CCA_STATUS_OK;

        if (acct_id)
        {
            *acct_id = new_acct_id;
        }
    }
    else if (!async_mode || retval != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        if (acct_need_del)
        {
            srv_email_acct_delete(new_acct_id);
        }

        profile_p->cca_prof_status = CCA_STATUS_FAIL;
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_proc_cca_doc
 * DESCRIPTION
 *  This function is used to process the CCA document.
 * PARAMETERS
 *  newConfigDoc    [IN]      The pointer point to the config document structure
 * RETURNS
 *  void
 ****************************************************************************/
void srv_email_otap_proc_cca_doc(mmi_cca_app_configure_ind_struct *newConfigDoc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_OTAP_RECEIVED, srv_email_otap_p->otap_callback);

    if (!srv_email_otap_p || !srv_email_otap_p->otap_callback)
    {
        srv_email_otap_send_cca_rsp(newConfigDoc->config_id, newConfigDoc->hConfig, CCA_STATUS_SETTING_SKIPPED);
        return;
    }

    EMAILSRV_ASSERT(!srv_email_otap_cntx_p);

    srv_email_otap_cntx_p = srv_email_otap_new_cntx();
    if (!srv_email_otap_cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_OTAP_NEW_CNTX);
        srv_email_otap_send_cca_rsp(newConfigDoc->config_id, newConfigDoc->hConfig, CCA_STATUS_FAIL);
        return;
    }

    srv_email_otap_cntx_p->prov_type = newConfigDoc->prov_type;
    srv_email_otap_cntx_p->prov_flag = newConfigDoc->prov_flag;
    srv_email_otap_cntx_p->sim_id = newConfigDoc->sim_id;
    srv_email_otap_cntx_p->conf_id = newConfigDoc->config_id;
    srv_email_otap_cntx_p->doc_hdl = newConfigDoc->hConfig;

    status = srv_email_otap_exec_proc_cca_doc(srv_email_otap_cntx_p);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_INFO_NWK_OTAP_PARSE_DONE, status);

    if (status != CCA_STATUS_OK)
    {
        srv_email_otap_free_cntx(srv_email_otap_cntx_p);
        srv_email_otap_cntx_p = NULL;

        srv_email_otap_send_cca_rsp(newConfigDoc->config_id, newConfigDoc->hConfig, status);
        return;
    }

    srv_email_otap_p->otap_callback(srv_email_otap_cntx_p->num_profiles);
}

#endif /* __MMI_EMAIL_OTAP__ */


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_init
 * DESCRIPTION
 *  This function is used to initialize the OTAP module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_email_result_enum srv_email_otap_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    if (!srv_email_otap_inited)
    {
        srv_email_otap_p = &srv_email_otap;
        memset(srv_email_otap_p, 0, sizeof(srv_email_otap_struct));
        srv_email_otap_p->allow_register = MMI_TRUE;
        srv_email_otap_inited = MMI_TRUE;
    }
#endif /* __MMI_EMAIL_OTAP__ */

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_register_otap_notify
 * DESCRIPTION
 *  This function is used to register the OTAP notify function for
 *  the specified service instance.
 * PARAMETERS
 *  srv_handle      [IN]      The service handle
 *  otap_callback   [IN]      The OTAP notify function
 *  clear_callback  [IN]      The OTAP clear notify function
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_register_otap_notify(
                        EMAIL_SRV_HANDLE srv_handle,
                        srv_email_otap_notify_funcptr_type otap_callback,
                        srv_email_funcptr_type clear_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    if (!otap_callback)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    // TODO: check the service handle first

    if (!srv_email_otap_p->allow_register)
    {
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    if (srv_email_otap_p->clear_callback)
    {
        srv_email_otap_p->allow_register = MMI_FALSE;
        srv_email_otap_p->clear_callback();
        srv_email_otap_p->allow_register = MMI_TRUE;
    }

    srv_email_otap_p->srv_handle = srv_handle;
    srv_email_otap_p->otap_callback = otap_callback;
    srv_email_otap_p->clear_callback = clear_callback;
    return SRV_EMAIL_RESULT_SUCC;
#else /* __MMI_EMAIL_OTAP__ */
    return SRV_EMAIL_RESULT_FAIL;
#endif /* __MMI_EMAIL_OTAP__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_clear_otap_notify
 * DESCRIPTION
 *  This function is used to clear the OTAP notify function for
 *  the specified service instance.
 * PARAMETERS
 *  srv_handle      [IN]      The service handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_clear_otap_notify(EMAIL_SRV_HANDLE srv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    // TODO: check the service handle first

    if (!srv_email_otap_p->otap_callback)
    {
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    if (srv_email_otap_p->srv_handle != srv_handle)
    {
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    srv_email_otap_p->srv_handle = EMAIL_SRV_INVALID_HANDLE;
    srv_email_otap_p->otap_callback = NULL;
    srv_email_otap_p->clear_callback = NULL;
    return SRV_EMAIL_RESULT_SUCC;
#else /* __MMI_EMAIL_OTAP__ */
    return SRV_EMAIL_RESULT_FAIL;
#endif /* __MMI_EMAIL_OTAP__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_start_install
 * DESCRIPTION
 *  This function is used to start installing the OTAP.
 * PARAMETERS
 *  handle          [OUT]     Used to store the OTAP handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_otap_start_install(EMAIL_OTAP_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    if (!handle)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    if (!srv_email_otap_cntx_p)
    {
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    *handle = (EMAIL_OTAP_HANDLE)srv_email_otap_cntx_p;
    return SRV_EMAIL_RESULT_SUCC;
#else /* __MMI_EMAIL_OTAP__ */
    return SRV_EMAIL_RESULT_FAIL;
#endif /* __MMI_EMAIL_OTAP__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_set_option
 * DESCRIPTION
 *  This function is used to get the profile's number in the specified OTAP.
 * PARAMETERS
 *  handle          [IN]      The OTAP handle
 *  prof_num        [OUT]     Used to store the profile's number
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_otap_set_option(
                        EMAIL_OTAP_HANDLE handle,
                        srv_email_otap_option_struct *option_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    srv_email_otap_cntx_struct *cntx_p = (srv_email_otap_cntx_struct*)handle;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    if (!cntx_p || cntx_p != srv_email_otap_cntx_p)
    {
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (!option_p)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    memcpy(&cntx_p->option, option_p, sizeof(srv_email_otap_option_struct));
    return SRV_EMAIL_RESULT_SUCC;
#else /* __MMI_EMAIL_OTAP__ */
    return SRV_EMAIL_RESULT_FAIL;
#endif /* __MMI_EMAIL_OTAP__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_get_prof_num
 * DESCRIPTION
 *  This function is used to get the profile's number in the specified OTAP.
 * PARAMETERS
 *  handle          [IN]      The OTAP handle
 *  prof_num        [OUT]     Used to store the profile's number
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_otap_get_prof_num(EMAIL_OTAP_HANDLE handle, U32 *prof_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    srv_email_otap_cntx_struct *cntx_p = (srv_email_otap_cntx_struct*)handle;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    if (!cntx_p || cntx_p != srv_email_otap_cntx_p)
    {
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (!prof_num)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    *prof_num = cntx_p->num_profiles;
    return SRV_EMAIL_RESULT_SUCC;
#else /* __MMI_EMAIL_OTAP__ */
    return SRV_EMAIL_RESULT_FAIL;
#endif /* __MMI_EMAIL_OTAP__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_get_prof_info
 * DESCRIPTION
 *  This function is used to get the specified profile's information.
 * PARAMETERS
 *  handle          [IN]      The OTAP handle
 *  prof_index      [IN]      The profile's index
 *  prof_info_p     [OUT]     Used to store the profile's information
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_otap_get_prof_info(
                        EMAIL_OTAP_HANDLE handle,
                        U32 prof_index,
                        srv_email_otap_prof_info_struct *prof_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    srv_email_otap_cntx_struct *cntx_p = (srv_email_otap_cntx_struct*)handle;
    srv_email_otap_profile_struct *profile_p = NULL;
    srv_email_acct_info_struct *acct_p = NULL;
    cbm_sim_id_enum sim_id = CBM_SIM_ID_SIM1;
#endif /* __MMI_EMAIL_OTAP__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    if (!cntx_p || cntx_p != srv_email_otap_cntx_p)
    {
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (!prof_info_p || prof_index >= cntx_p->num_profiles)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    memset(prof_info_p, 0, sizeof(srv_email_otap_prof_info_struct));
    profile_p = cntx_p->profile[prof_index];

    prof_info_p->updatable = profile_p->is_updateble;
    prof_info_p->update_acct_id = profile_p->matched_acct_id;
    prof_info_p->in_protocol = profile_p->in_protocol_type;

    if (profile_p->is_have_smtp)
    {
        mmi_wcscpy(prof_info_p->from, profile_p->smtp_node->from_addr);
        mmi_wcscpy(prof_info_p->out_server, profile_p->smtp_node->server_addr);
    }

    if (profile_p->is_have_pop3_imap4)
    {
        mmi_wcscpy(prof_info_p->in_server, profile_p->pop3_imap4_node->server_addr);
    }

    /* account name info */
    if (mmi_wcslen(profile_p->prof_name_combined))
    {
        mmi_wcscpy(prof_info_p->prof_name, profile_p->prof_name_combined);
    }

    if (profile_p->is_have_dataacctid)
    {
        if (cntx_p->sim_id == MMI_CCA_SIM_ID_SIM2)
        {
            sim_id = CBM_SIM_ID_SIM2;
        }

        prof_info_p->dtcnt_id = cbm_encode_data_account_id((U32)profile_p->data_acct_id, sim_id, 0, MMI_FALSE);
        prof_info_p->have_dtcnt = MMI_TRUE;
    }
    else
    {
        acct_p = (srv_email_acct_info_struct*)OslMalloc(sizeof(srv_email_acct_info_struct));

        srv_email_acct_init_acct_info(acct_p);

        prof_info_p->dtcnt_id = acct_p->in_server.data_acct[0];

        OslMfree(acct_p);
    }

    return SRV_EMAIL_RESULT_SUCC;
#else /* __MMI_EMAIL_OTAP__ */
    return SRV_EMAIL_RESULT_FAIL;
#endif /* __MMI_EMAIL_OTAP__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_add_prof
 * DESCRIPTION
 *  This function is used to create a new account with the specified profile.
 * PARAMETERS
 *  handle          [IN]      The OTAP handle
 *  prof_index      [IN]      The profile's index
 *  prof_name       [IN]      The profile name
 *  acct_id         [OUT]     Used to store the new account id
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_otap_add_prof(
                        EMAIL_OTAP_HANDLE handle,
                        U32 prof_index,
                        const WCHAR *prof_name,
                        EMAIL_ACCT_ID *acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    retval = srv_email_otap_add_prof_ext(handle, prof_index, prof_name, acct_id, MMI_FALSE);
    return retval;
#else /* __MMI_EMAIL_OTAP__ */
    return SRV_EMAIL_RESULT_FAIL;
#endif /* __MMI_EMAIL_OTAP__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_add_prof_async
 * DESCRIPTION
 *  This function is used to create a new account with the specified profile asynchronously.
 * PARAMETERS
 *  handle          [IN]        The OTAP handle
 *  prof_index      [IN]        The profile's index
 *  prof_name       [IN]        The profile name
 *  acct_id         [OUT]       Used to store the new account id
 *  req_id          [OUT]       Used to store the request id
 *  callback        [IN]        The pointer point to the callback function
 *  user_data       [IN]        The pointer point to the user data
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_otap_add_prof_async(
                        EMAIL_OTAP_HANDLE handle,
                        U32 prof_index,
                        const WCHAR *prof_name,
                        EMAIL_ACCT_ID *acct_id,
                        EMAIL_REQ_ID *req_id,
                        srv_email_otap_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    srv_email_otap_cntx_struct *cntx_p = (srv_email_otap_cntx_struct*)handle;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
#endif /* __MMI_EMAIL_OTAP__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    if (!req_id || !callback)
    {
        retval = srv_email_otap_add_prof_ext(handle, prof_index, prof_name, acct_id, MMI_FALSE);
    }
    else
    {
        retval = srv_email_otap_add_prof_ext(handle, prof_index, prof_name, acct_id, MMI_TRUE);
        if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            *req_id = cntx_p->action;
            cntx_p->callback = callback;
            cntx_p->user_data = user_data;
        }
    }

    return retval;
#else /* __MMI_EMAIL_OTAP__ */
    return SRV_EMAIL_RESULT_FAIL;
#endif /* __MMI_EMAIL_OTAP__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_modify_prof
 * DESCRIPTION
 *  This function is used to modify the existing account with the specified profile.
 * PARAMETERS
 *  handle          [IN]      The OTAP handle
 *  prof_index      [IN]      The profile's index
 *  prof_name       [IN]      The profile name
 *  acct_id         [IN]      The account id needed to be modified
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_otap_modify_prof(
                        EMAIL_OTAP_HANDLE handle,
                        U32 prof_index,
                        const WCHAR *prof_name,
                        EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    srv_email_otap_cntx_struct *cntx_p = (srv_email_otap_cntx_struct*)handle;
    srv_email_otap_profile_struct *profile_p = NULL;
    srv_email_acct_info_struct *acct_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    EMAIL_SRV_HANDLE srv_handle = EMAIL_SRV_INVALID_HANDLE;
    EMAIL_ACCT_HANDLE acct_handle = EMAIL_ACCT_INVALID_HANDLE;
#endif /* __MMI_EMAIL_OTAP__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    if (!cntx_p || cntx_p != srv_email_otap_cntx_p)
    {
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (prof_index >= cntx_p->num_profiles)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    if (cntx_p->action != SRV_EMAIL_OTAP_ACTION_NONE)
    {
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    profile_p = cntx_p->profile[prof_index];

    if (profile_p->cca_prof_status != CCA_STATUS_SETTING_NOT_INSTALLED)
    {
        return SRV_EMAIL_RESULT_INVALID_OPERATION;
    }

    acct_p = (srv_email_acct_info_struct*)OslMalloc(sizeof(srv_email_acct_info_struct));
    if (!acct_p)
    {
        goto EXIT_HANDLE;
    }

    srv_handle = srv_email_get_int_srv_handle();

    retval = srv_email_acct_create(srv_handle, &acct_handle);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        goto EXIT_HANDLE;
    }

    retval = srv_email_acct_open(acct_handle, acct_id);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        goto EXIT_HANDLE;
    }

    retval = srv_email_acct_read(acct_handle, acct_p);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        goto EXIT_HANDLE;
    }

    retval = srv_email_acct_get_permission(acct_handle);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        goto EXIT_HANDLE;
    }

    /* Fill the acct info */
    srv_email_otap_fill_acct_info(acct_p, profile_p, prof_name, cntx_p);

    retval = srv_email_acct_edit(acct_handle, acct_p);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        goto EXIT_HANDLE;
    }

    retval = srv_email_acct_save(acct_handle);

EXIT_HANDLE:
    if (acct_p)
    {
        OslMfree(acct_p);
    }

    if (acct_handle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(acct_handle);
    }

    if (retval == SRV_EMAIL_RESULT_SUCC)
    {
        profile_p->cca_prof_status = CCA_STATUS_OK;
    }
    else
    {
        profile_p->cca_prof_status = CCA_STATUS_FAIL;
    }

    return retval;
#else /* __MMI_EMAIL_OTAP__ */
    return SRV_EMAIL_RESULT_FAIL;
#endif /* __MMI_EMAIL_OTAP__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_replace_prof
 * DESCRIPTION
 *  This function is used to replace the existing account with the specified profile.
 * PARAMETERS
 *  handle          [IN]      The OTAP handle
 *  prof_index      [IN]      The profile's index
 *  prof_name       [IN]      The profile name
 *  src_acct_id     [IN]      The account id needed to be replaced
 *  dst_acct_id     [OUT]     Used to store the new account id
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_otap_replace_prof(
                        EMAIL_OTAP_HANDLE handle,
                        U32 prof_index,
                        const WCHAR *prof_name,
                        EMAIL_ACCT_ID src_acct_id,
                        EMAIL_ACCT_ID *dst_acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    srv_email_otap_cntx_struct *cntx_p = (srv_email_otap_cntx_struct*)handle;
    srv_email_otap_profile_struct *profile_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
#endif /* __MMI_EMAIL_OTAP__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    if (!cntx_p || cntx_p != srv_email_otap_cntx_p)
    {
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (prof_index >= cntx_p->num_profiles)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    if (cntx_p->action != SRV_EMAIL_OTAP_ACTION_NONE)
    {
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    profile_p = cntx_p->profile[prof_index];

    if (profile_p->cca_prof_status != CCA_STATUS_SETTING_NOT_INSTALLED)
    {
        return SRV_EMAIL_RESULT_INVALID_OPERATION;
    }

    retval = srv_email_acct_delete(src_acct_id);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        profile_p->cca_prof_status = CCA_STATUS_FAIL;
        return retval;
    }

    retval = srv_email_otap_add_prof(handle, prof_index, prof_name, dst_acct_id);
    return retval;
#else /* __MMI_EMAIL_OTAP__ */
    return SRV_EMAIL_RESULT_FAIL;
#endif /* __MMI_EMAIL_OTAP__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_replace_prof_async
 * DESCRIPTION
 *  This function is used to replace the existing account with the specified profile asynchronously.
 * PARAMETERS
 *  handle          [IN]        The OTAP handle
 *  prof_index      [IN]        The profile's index
 *  prof_name       [IN]        The profile name
 *  src_acct_id     [IN]        The account id needed to be replaced
 *  dst_acct_id     [OUT]       Used to store the new account id
 *  req_id          [OUT]       Used to store the request id
 *  callback        [IN]        The pointer point to the callback function
 *  user_data       [IN]        The pointer point to the user data
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_otap_replace_prof_async(
                        EMAIL_OTAP_HANDLE handle,
                        U32 prof_index,
                        const WCHAR *prof_name,
                        EMAIL_ACCT_ID src_acct_id,
                        EMAIL_ACCT_ID *dst_acct_id,
                        EMAIL_REQ_ID *req_id,
                        srv_email_otap_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    srv_email_otap_cntx_struct *cntx_p = (srv_email_otap_cntx_struct*)handle;
    srv_email_otap_profile_struct *profile_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
#endif /* __MMI_EMAIL_OTAP__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    if (!cntx_p || cntx_p != srv_email_otap_cntx_p)
    {
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (prof_index >= cntx_p->num_profiles)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    if (cntx_p->action != SRV_EMAIL_OTAP_ACTION_NONE)
    {
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    profile_p = cntx_p->profile[prof_index];

    if (profile_p->cca_prof_status != CCA_STATUS_SETTING_NOT_INSTALLED)
    {
        return SRV_EMAIL_RESULT_INVALID_OPERATION;
    }

    retval = srv_email_acct_delete(src_acct_id);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        profile_p->cca_prof_status = CCA_STATUS_FAIL;
        return retval;
    }

    retval = srv_email_otap_add_prof_async(
                handle,
                prof_index,
                prof_name,
                dst_acct_id,
                req_id,
                callback,
                user_data);
    if (retval == SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        cntx_p->action = SRV_EMAIL_OTAP_ACTION_REPLACE;
    }
    return retval;
#else /* __MMI_EMAIL_OTAP__ */
    return SRV_EMAIL_RESULT_FAIL;
#endif /* __MMI_EMAIL_OTAP__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_update_prof
 * DESCRIPTION
 *  This function is used to update the matched account.
 * PARAMETERS
 *  handle          [IN]      The OTAP handle
 *  prof_index      [IN]      The profile's index
 *  prof_name       [IN]      The profile name
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_otap_update_prof(
                        EMAIL_OTAP_HANDLE handle,
                        U32 prof_index,
                        const WCHAR *prof_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    srv_email_otap_cntx_struct *cntx_p = (srv_email_otap_cntx_struct*)handle;
    srv_email_otap_profile_struct *profile_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
#endif /* __MMI_EMAIL_OTAP__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    if (!cntx_p || cntx_p != srv_email_otap_cntx_p)
    {
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (prof_index >= cntx_p->num_profiles)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    if (cntx_p->action != SRV_EMAIL_OTAP_ACTION_NONE)
    {
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    profile_p = cntx_p->profile[prof_index];

    if (profile_p->cca_prof_status != CCA_STATUS_SETTING_NOT_INSTALLED)
    {
        return SRV_EMAIL_RESULT_INVALID_OPERATION;
    }

    if (!profile_p->is_updateble)
    {
        return SRV_EMAIL_RESULT_INVALID_OPERATION;
    }

    retval = srv_email_otap_modify_prof(
                handle,
                prof_index,
                prof_name,
                profile_p->matched_acct_id);

    if (retval == SRV_EMAIL_RESULT_SUCC)
    {
        profile_p->cca_prof_status = CCA_STATUS_SETTING_UPDATED;
    }

    return retval;
#else /* __MMI_EMAIL_OTAP__ */
    return SRV_EMAIL_RESULT_FAIL;
#endif /* __MMI_EMAIL_OTAP__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_skip_prof
 * DESCRIPTION
 *  This function is used to skip the specified profile or all left profiles.
 * PARAMETERS
 *  handle          [IN]      The OTAP handle
 *  skip_all_left   [IN]      Skip all left profiles or not
 *  prof_index      [IN]      The profile's index
 *  cause           [IN]      The skip cause
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_otap_skip_prof(
                        EMAIL_OTAP_HANDLE handle,
                        MMI_BOOL skip_all_left,
                        U32 prof_index,
                        srv_email_skip_cause_enum cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    srv_email_otap_cntx_struct *cntx_p = (srv_email_otap_cntx_struct*)handle;
    cca_status_enum status = CCA_STATUS_SETTING_SKIPPED;
    U32 i = 0;
#endif /* __MMI_EMAIL_OTAP__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    if (!cntx_p || cntx_p != srv_email_otap_cntx_p)
    {
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    if (prof_index >= cntx_p->num_profiles)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    if (cntx_p->action != SRV_EMAIL_OTAP_ACTION_NONE)
    {
        return SRV_EMAIL_RESULT_INPROGRESS;
    }

    if (cntx_p->profile[prof_index]->cca_prof_status != CCA_STATUS_SETTING_NOT_INSTALLED)
    {
        return SRV_EMAIL_RESULT_INVALID_OPERATION;
    }

    if (cause == SRV_EMAIL_SKIP_ERROR)
    {
        status = CCA_STATUS_FAIL;
    }

    cntx_p->profile[prof_index]->cca_prof_status = status;

    if (skip_all_left)
    {
        for (i = prof_index + 1; i < cntx_p->num_profiles; i++)
        {
            cntx_p->profile[i]->cca_prof_status = status;
        }
    }

    if (cause == SRV_EMAIL_SKIP_ENDKEY)
    {
        cntx_p->cca_status = CCA_STATUS_ENDKEY_PRESSED;
    }

    return SRV_EMAIL_RESULT_SUCC;
#else /* __MMI_EMAIL_OTAP__ */
    return SRV_EMAIL_RESULT_FAIL;
#endif /* __MMI_EMAIL_OTAP__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_otap_finish_install
 * DESCRIPTION
 *  This function is used to finish the installing.
 * PARAMETERS
 *  handle          [IN]      The OTAP handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_otap_finish_install(EMAIL_OTAP_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    srv_email_otap_cntx_struct *cntx_p = (srv_email_otap_cntx_struct*)handle;
    U16 config_id;
    S32 hConfig;
    cca_status_enum cca_status;
#endif /* __MMI_EMAIL_OTAP__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_EMAIL_OTAP__
    if (!cntx_p || cntx_p != srv_email_otap_cntx_p)
    {
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    config_id = cntx_p->conf_id;
    hConfig = cntx_p->doc_hdl;
    cca_status = srv_email_otap_get_cca_status(cntx_p);

    srv_email_otap_free_cntx(cntx_p);
    srv_email_otap_cntx_p = NULL;

    srv_email_otap_send_cca_rsp(config_id, hConfig, cca_status);
    return SRV_EMAIL_RESULT_SUCC;
#else /* __MMI_EMAIL_OTAP__ */
    return SRV_EMAIL_RESULT_FAIL;
#endif /* __MMI_EMAIL_OTAP__ */
}

#endif /* __MMI_EMAIL__ */
