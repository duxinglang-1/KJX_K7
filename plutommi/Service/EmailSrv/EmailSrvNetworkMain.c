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
 *  EmailSrvNetworkMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email network internal functions.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#if defined(__MMI_EMAIL__) || defined(__SMS_CLOUD_SUPPORT__)

#include "EmailSrvGprot.h"
#include "EmailSrvProt.h"
#include "EmailSrvNetwork.h"
#include "EmailSrvNetworkProt.h"
#include "EmailSrvSso.h"

#include "email_ps_public.h"

#include "cbm_consts.h"
#include "cbm_api.h"
#include "CbmSrvGprot.h"

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "string.h"
#include "stack_msgs.h"

#include "MMI_trc_Int.h"
#include "mmi_inet_app_trc.h"
#include "kal_trace.h"

#include "Unicodexdcl.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "che_api.h"
#include "app_str.h"
#include "tst_sap.h"
#include "app_datetime.h"

#ifdef __MMI_SSO__
#include "SsoSrvGprot.h"
#endif

#ifdef __MMI_EMAIL__

#include "EmailSrvSMTP.h"
#include "EmailSrvPOP3.h"
#include "EmailSrvIMAP4.h"

#include "EmailSrvStorage.h"
#include "custom_data_account.h"

#ifdef __MMI_SSO__
#include "CloudPlugin.h"
#include "vmpromnginner.h"
#include "vmpromng.h"
#include "FileMgrSrvGProt.h"
#include "custom_cloud_config.h"
#ifdef __MMI_CLOUD_VPP_UPGRADE__
#include "UpgradeSrvGprot.h"
#endif
#endif /* __MMI_SSO__ */

#endif /* __MMI_EMAIL__ */

typedef struct
{
    EMAIL_SRV_HANDLE srv_handle;
    srv_email_app_info_query_funcptr_type callback;
} srv_email_nwk_struct;

#define SRV_EMAIL_YAHOO_NAME_NAME           "name"
#define SRV_EMAIL_YAHOO_OS_NAME             "os"
#define SRV_EMAIL_YAHOO_OS_VERSION_NAME     "os-version"
#define SRV_EMAIL_YAHOO_VENDOR_NAME         "vendor"
#define SRV_EMAIL_YAHOO_DEVICE_NAME         "device"
#define SRV_EMAIL_YAHOO_OPERATOR_NAME       "mobile-net-operator"
#define SRV_EMAIL_YAHOO_AGUID_NAME          "AGUID"
#define SRV_EMAIL_YAHOO_ACLID_NAME          "ACLID"

#define SRV_EMAIL_YAHOO_NAME_LEN            (30)
#define SRV_EMAIL_YAHOO_OS_LEN              (30)
#define SRV_EMAIL_YAHOO_OS_VERSION_LEN      (20)
#define SRV_EMAIL_YAHOO_VENDOR_LEN          (30)
#define SRV_EMAIL_YAHOO_DEVICE_LEN          (30)
#define SRV_EMAIL_YAHOO_OPERATOR_LEN        (30)
#define SRV_EMAIL_YAHOO_AGUID_LEN           (40)
#define SRV_EMAIL_YAHOO_ACLID_LEN           (20)

typedef struct
{
    CHAR email_addr[SRV_EMAIL_MAX_ADDR_LEN + 1];
    CHAR in_server_addr[SRV_EMAIL_MAX_SERVER_NAME_LEN + 1];
    U16 in_server_port;
    srv_email_sec_mode_enum in_sec_mode;
    CHAR out_server_addr[SRV_EMAIL_MAX_SERVER_NAME_LEN + 1];
    U16 out_server_port;
    srv_email_sec_mode_enum out_sec_mode;

    CHAR name[SRV_EMAIL_YAHOO_NAME_LEN + 1];
    CHAR os[SRV_EMAIL_YAHOO_OS_LEN + 1];
    CHAR os_version[SRV_EMAIL_YAHOO_OS_VERSION_LEN + 1];
    CHAR vendor[SRV_EMAIL_YAHOO_VENDOR_LEN + 1];
    CHAR device[SRV_EMAIL_YAHOO_DEVICE_LEN + 1];
    CHAR operator[SRV_EMAIL_YAHOO_OPERATOR_LEN + 1];
    //CHAR aguid[SRV_EMAIL_YAHOO_AGUID_LEN + 1];
    CHAR aclid[SRV_EMAIL_YAHOO_ACLID_LEN + 1];
} srv_email_yahoo_info_struct;

#ifdef __MMI_EMAIL__
static srv_email_nwk_struct srv_email_nwk;
static srv_email_nwk_struct *srv_email_nwk_p = NULL;
static srv_email_nwk_cntx_struct *srv_email_nwk_cntx_p = NULL;
srv_email_app_id_reg_struct *srv_email_app_id_reg;

#ifdef __MMI_SSO__
#define SRV_EMAIL_MAX_CLOUD_PROVIDER_NUM    (1)
#define SRV_EMAIL_MAX_CLOUD_SERVER_NUM      (SRV_EMAIL_MAX_CLOUD_PROVIDER_NUM * 2)

typedef struct
{
    U32 provider_id;
    cloud_plugin_server_info_struct server_info;
} srv_email_cloud_server_info_struct;

typedef struct
{
    U32 provider_id;
    const U8 *provider_addr;
} srv_email_cloud_preload_struct;

typedef struct
{
    U32 provider_id;
    WCHAR filename[SRV_EMAIL_MAX_FILE_NAME_LEN + 1];
} srv_email_cloud_provider_struct;

static srv_email_cloud_server_info_struct srv_email_cloud_server[SRV_EMAIL_MAX_CLOUD_SERVER_NUM];
static srv_email_cloud_provider_struct srv_email_cloud_providers[SRV_EMAIL_MAX_CLOUD_PROVIDER_NUM];

#ifndef WIN32
#ifdef __MMI_SSO_PRELOAD_YAHOO__
extern const U8 YAHOO_vpp[];
#endif
#endif

static srv_email_cloud_preload_struct srv_email_cloud_preload_vpps[] =
{
#ifndef WIN32
#ifdef __MMI_SSO_PRELOAD_YAHOO__
    {PROVIDER_YAHOO, YAHOO_vpp},
#endif
#endif
    {0, NULL},
};

#ifdef __MMI_CLOUD_VPP_UPGRADE__
static MMI_BOOL srv_email_cloud_upgrade_checked = MMI_FALSE;
#endif
#endif /* __MMI_SSO__ */

#endif /* __MMI_EMAIL__ */

#ifdef __SMS_CLOUD_SUPPORT__
static srv_email_nwk_cloud_cntx_struct *srv_email_nwk_cloud_cntx_p = NULL;
#endif

static MMI_BOOL srv_email_nwk_inited = MMI_FALSE;

static srv_email_fs_async_struct *srv_email_fs_async_job_list_p = NULL;

static srv_email_yahoo_info_struct srv_email_yahoo =
{
    "@yahoo.com",
    "mediatek.imap.mail.yahoo.com",
    993,
    SRV_EMAIL_SEC_SSL_TLS,
    "mediatek.smtp.mail.yahoo.com",
    465,
    SRV_EMAIL_SEC_SSL_TLS,
    "",
    "MediaTek",
    "11A",
    "MediaTek",
    "Feature Phone",
    "",
    "MTK"
};

//#define __SRV_EMAIL_NWK_UT__

#ifdef __SRV_EMAIL_NWK_UT__

enum
{
    SRV_EMAIL_NWK_UT_CREATE = 0,
    SRV_EMAIL_NWK_UT_DESTROY,
    SRV_EMAIL_NWK_UT_SET_PROCESS_NOTIFY,
    SRV_EMAIL_NWK_UT_SET_FINISH_NOTIFY,
    SRV_EMAIL_NWK_UT_CONNECT,
    SRV_EMAIL_NWK_UT_DISCONNECT,
    SRV_EMAIL_NWK_UT_APPEND,
    SRV_EMAIL_NWK_UT_RETRIEVE,
    SRV_EMAIL_NWK_UT_ABORT,
    SRV_EMAIL_NWK_UT_TOTAL
};

static void SRV_EMAIL_NWK_UT_Create(CHAR *);
static void SRV_EMAIL_NWK_UT_Destroy(CHAR *);
static void SRV_EMAIL_NWK_UT_SetProcessNotify(CHAR *);
static void SRV_EMAIL_NWK_UT_SetFinishNotify(CHAR *);
static void SRV_EMAIL_NWK_UT_Connect(CHAR *);
static void SRV_EMAIL_NWK_UT_Disconnect(CHAR *);
static void SRV_EMAIL_NWK_UT_Append(CHAR *);
static void SRV_EMAIL_NWK_UT_Retrieve(CHAR *);
static void SRV_EMAIL_NWK_UT_Abort(CHAR *);

typedef void (*SRV_EMAIL_NWK_UT_FUNC)(CHAR*);

static EMAIL_NWK_HANDLE srv_email_nwk_tst_hd = EMAIL_NWK_INVALID_HANDLE;

static EMAIL_ACCT_ID srv_email_nwk_tst_id = 1;
static EMAIL_MSG_HANDLE srv_email_nwk_tst_msg = EMAIL_MSG_INVALID_HANDLE;
static srv_email_nwk_cloud_retr_struct srv_email_nwk_tst_retr = {0};
static WCHAR srv_email_nwk_tst_cont[128] = {0};
static srv_email_msg_update_content_struct srv_email_nwk_tst_updt = {0};
static U32 srv_email_nwk_tst_sms_id = 100;

static const SRV_EMAIL_NWK_UT_FUNC SRV_EMAIL_NWK_UT_Func[SRV_EMAIL_NWK_UT_TOTAL] =
{
    SRV_EMAIL_NWK_UT_Create,            /* 0. SRV_EMAIL_NWK_UT_CREATE */
    SRV_EMAIL_NWK_UT_Destroy,           /* 1. SRV_EMAIL_NWK_UT_DESTROY */
    SRV_EMAIL_NWK_UT_SetProcessNotify,  /* 2. SRV_EMAIL_NWK_UT_SET_PROCESS_NOTIFY */
    SRV_EMAIL_NWK_UT_SetFinishNotify,   /* 3. SRV_EMAIL_NWK_UT_SET_FINISH_NOTIFY */
    SRV_EMAIL_NWK_UT_Connect,           /* 4. SRV_EMAIL_NWK_UT_CONNECT */
    SRV_EMAIL_NWK_UT_Disconnect,        /* 5. SRV_EMAIL_NWK_UT_DISCONNECT */
    SRV_EMAIL_NWK_UT_Append,            /* 6. SRV_EMAIL_NWK_UT_APPEND */
    SRV_EMAIL_NWK_UT_Retrieve,          /* 7. SRV_EMAIL_NWK_UT_RETRIEVE */
    SRV_EMAIL_NWK_UT_Abort              /* 8. SRV_EMAIL_NWK_UT_ABORT */
};

static void srv_email_nwk_tst_inject_str(void *inMsg)
{
    tst_module_string_inject_struct *tst_str_p = (tst_module_string_inject_struct*)inMsg;

    if (tst_str_p->index < SRV_EMAIL_NWK_UT_TOTAL)
    {
        (*SRV_EMAIL_NWK_UT_Func[tst_str_p->index])((CHAR*)tst_str_p->string);
    }
}

static void srv_email_nwk_ut_proc_notify_func(srv_email_nwk_proc_struct *data)
{
}

static void srv_email_nwk_ut_finish_notify_func(srv_email_nwk_finish_struct *data)
{
    if (srv_email_nwk_tst_msg != EMAIL_MSG_INVALID_HANDLE)
    {
        srv_email_msg_destroy(srv_email_nwk_tst_msg);
        srv_email_nwk_tst_msg = EMAIL_MSG_INVALID_HANDLE;
    }
}

static void SRV_EMAIL_NWK_UT_Create(CHAR *str_p)
{
    if (srv_email_nwk_tst_hd == EMAIL_NWK_INVALID_HANDLE)
    {
        srv_email_nwk_cloud_create(srv_email_nwk_tst_id, &srv_email_nwk_tst_hd);
    }
}

static void SRV_EMAIL_NWK_UT_Destroy(CHAR *str_p)
{
    srv_email_nwk_cloud_destroy(srv_email_nwk_tst_hd);
    srv_email_nwk_tst_hd = EMAIL_NWK_INVALID_HANDLE;
}

static void SRV_EMAIL_NWK_UT_SetProcessNotify(CHAR *str_p)
{
    srv_email_nwk_cloud_set_process_notify(
        srv_email_nwk_tst_hd,
        srv_email_nwk_ut_proc_notify_func,
        NULL);
}

static void SRV_EMAIL_NWK_UT_SetFinishNotify(CHAR *str_p)
{
    srv_email_nwk_cloud_set_finish_notify(
        srv_email_nwk_tst_hd,
        srv_email_nwk_ut_finish_notify_func,
        NULL);
}

static void SRV_EMAIL_NWK_UT_Connect(CHAR *fldr_name_p)
{
    if (srv_email_nwk_tst_hd == EMAIL_NWK_INVALID_HANDLE)
    {
        srv_email_nwk_cloud_create(srv_email_nwk_tst_id, &srv_email_nwk_tst_hd);
        srv_email_nwk_cloud_set_process_notify(
            srv_email_nwk_tst_hd,
            srv_email_nwk_ut_proc_notify_func,
            NULL);
        srv_email_nwk_cloud_set_finish_notify(
            srv_email_nwk_tst_hd,
            srv_email_nwk_ut_finish_notify_func,
            NULL);
    }

    srv_email_nwk_cloud_connect(srv_email_nwk_tst_hd, fldr_name_p, MMI_TRUE);
}

static void SRV_EMAIL_NWK_UT_Disconnect(CHAR *str_p)
{
    srv_email_nwk_cloud_disconnect(srv_email_nwk_tst_hd);
}

static void SRV_EMAIL_NWK_UT_Append(CHAR *str_p)
{
    if (srv_email_nwk_tst_msg == EMAIL_MSG_INVALID_HANDLE)
    {
        srv_email_msg_create(1, &srv_email_nwk_tst_msg);
        srv_email_msg_set_new(srv_email_nwk_tst_msg);

        kal_wsprintf(srv_email_nwk_tst_cont, "%s", str_p);
        srv_email_msg_update_subject(
            srv_email_nwk_tst_msg,
            srv_email_nwk_tst_cont,
            CHSET_UCS2,
            mmi_wcslen(srv_email_nwk_tst_cont));

        kal_wsprintf(srv_email_nwk_tst_cont, "Hello %s,\r\n\r\nThis mail is used to test Cloud Email.\r\n", str_p);
        srv_email_nwk_tst_updt.buff_type = MMI_TRUE;
        srv_email_nwk_tst_updt.buff = srv_email_nwk_tst_cont;
        srv_email_nwk_tst_updt.charset = CHSET_UCS2;
        srv_email_nwk_tst_updt.buff_len = mmi_wcslen(srv_email_nwk_tst_cont);
        srv_email_msg_update_content(srv_email_nwk_tst_msg, &srv_email_nwk_tst_updt);

        kal_sprintf((CHAR*)srv_email_nwk_tst_cont, "%d", srv_email_nwk_tst_sms_id);
        srv_email_msg_update_extra_field(
            srv_email_nwk_tst_msg,
            SRV_EMAIL_MSG_SAVE_EXTRA_SMS_UID,
            (CHAR*)srv_email_nwk_tst_cont,
            strlen((CHAR*)srv_email_nwk_tst_cont) + 1);

        kal_sprintf((CHAR*)srv_email_nwk_tst_cont, "13800138000");
        srv_email_msg_update_extra_field(
            srv_email_nwk_tst_msg,
            SRV_EMAIL_MSG_SAVE_EXTRA_SMS_ADDR,
            (CHAR*)srv_email_nwk_tst_cont,
            strlen((CHAR*)srv_email_nwk_tst_cont) + 1);

        kal_sprintf((CHAR*)srv_email_nwk_tst_cont, "%dBASE64ENCODE", srv_email_nwk_tst_sms_id++);
        srv_email_msg_update_extra_field(
            srv_email_nwk_tst_msg,
            SRV_EMAIL_MSG_SAVE_EXTRA_SMS_DATA,
            (CHAR*)srv_email_nwk_tst_cont,
            strlen((CHAR*)srv_email_nwk_tst_cont) + 1);
    }

    srv_email_nwk_cloud_append(srv_email_nwk_tst_hd, srv_email_nwk_tst_msg);
}

static void SRV_EMAIL_NWK_UT_Retrieve(CHAR *str_p)
{
    mmi_asc_to_wcs(srv_email_nwk_tst_retr.filename, str_p);
    kal_wsprintf(srv_email_nwk_tst_retr.part_filename, "%s.part", str_p);
    srv_email_nwk_tst_retr.uid_max_num = 100;
    srv_email_nwk_cloud_retrieve(srv_email_nwk_tst_hd, &srv_email_nwk_tst_retr);
}

static void SRV_EMAIL_NWK_UT_Abort(CHAR *str_p)
{
    srv_email_nwk_cloud_abort(srv_email_nwk_tst_hd);
}

#endif /* __SRV_EMAIL_NWK_UT__ */

#ifdef __MMI_EMAIL__

/*****************************************************************************
 * FUNCTION
 *  srv_email_register_app_id_query_callback
 * DESCRIPTION
 *  This function is used to register the app id query callback function.
 * PARAMETERS
 *  srv_handle      [IN]        The service handle
 *  callback        [IN]        The query callback function
 * RETURNS
 *  The error code.
 ****************************************************************************/
srv_email_result_enum srv_email_register_app_id_query_callback(
                        EMAIL_SRV_HANDLE srv_handle,
                        srv_email_app_info_query_funcptr_type callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!callback)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    if (!srv_email_nwk_p)
    {
        return SRV_EMAIL_RESULT_INVALID_OPERATION;
    }

    srv_email_nwk_p->srv_handle = srv_handle;
    srv_email_nwk_p->callback = callback;

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_create_cntx
 * DESCRIPTION
 *  This function is used to create a new Network context.
 * PARAMETERS
 *  acct_id         [IN]        The account id
 *  is_incoming     [IN]        If incoming or outgoing server
 *  errcode         [OUT]       Return the error code
 * RETURNS
 *  The pointer point to the Network context.
 *****************************************************************************/
srv_email_nwk_cntx_struct *srv_email_nwk_create_cntx(EMAIL_ACCT_ID acct_id, MMI_BOOL is_incoming, S32 *errcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = srv_email_nwk_cntx_p;
    srv_email_acct_info_struct *acct_info_p = NULL;
    srv_email_nwk_cntx_struct *new_cntx_p = NULL;
    srv_email_smtp_cntx_struct *smtp_cntx_p = NULL;
    srv_email_pop3_cntx_struct *pop3_cntx_p = NULL;
    srv_email_imap4_cntx_struct *imap4_cntx_p = NULL;
    srv_email_comm_cntx_struct *comm_p = NULL;
    srv_email_nwk_cb_struct *sync_p = NULL;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    srv_email_prot_type_enum protocol;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!is_incoming)
    {
        smtp_cntx_p = (srv_email_smtp_cntx_struct*)
            srv_email_mem_alloc(sizeof(srv_email_smtp_cntx_struct));
        if (!smtp_cntx_p)
        {
            *errcode = SRV_EMAIL_RESULT_NO_MEMORY;
            return NULL;
        }

        srv_email_smtp_cntx_init(smtp_cntx_p);

        new_cntx_p = (srv_email_nwk_cntx_struct*)smtp_cntx_p;
        comm_p = &new_cntx_p->common;
        comm_p->protocol = EMAIL_PS_PRTOTOCOL_TYPE_SMTP;
    }
    else
    {
        acct_info_p = (srv_email_acct_info_struct*)
            srv_email_mem_alloc(sizeof(srv_email_acct_info_struct));
        if (!acct_info_p)
        {
            *errcode = SRV_EMAIL_RESULT_NO_MEMORY;
            return NULL;
        }
        acct_info_p->acct_id = acct_id;
        retval = srv_email_stor_acct_info_read(acct_info_p);
        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            srv_email_mem_free(acct_info_p);
            *errcode = retval;
            return NULL;
        }
        protocol = acct_info_p->protocol;
        srv_email_mem_free(acct_info_p);

        if (protocol != SRV_EMAIL_PROT_POP3 && protocol != SRV_EMAIL_PROT_IMAP4)
        {
            *errcode = SRV_EMAIL_RESULT_INCOMPLETE_ACCT;
            return NULL;
        }

        if (protocol == SRV_EMAIL_PROT_POP3)
        {
            pop3_cntx_p = (srv_email_pop3_cntx_struct*)
                srv_email_mem_alloc(sizeof(srv_email_pop3_cntx_struct));
            if (!pop3_cntx_p)
            {
                *errcode = SRV_EMAIL_RESULT_NO_MEMORY;
                return NULL;
            }

            srv_email_pop3_cntx_init(pop3_cntx_p);

            new_cntx_p = (srv_email_nwk_cntx_struct*)pop3_cntx_p;
            comm_p = &new_cntx_p->common;
            comm_p->protocol = EMAIL_PS_PRTOTOCOL_TYPE_POP3;
        }
        else
        {
            imap4_cntx_p = (srv_email_imap4_cntx_struct*)
                srv_email_mem_alloc(sizeof(srv_email_imap4_cntx_struct));
            if (!imap4_cntx_p)
            {
                *errcode = SRV_EMAIL_RESULT_NO_MEMORY;
                return NULL;
            }

            srv_email_imap4_cntx_init(imap4_cntx_p);

            new_cntx_p = (srv_email_nwk_cntx_struct*)imap4_cntx_p;
            comm_p = &new_cntx_p->common;
            comm_p->protocol = EMAIL_PS_PRTOTOCOL_TYPE_IMAP4;
        }

        sync_p = (srv_email_nwk_cb_struct*)srv_email_mem_alloc(sizeof(srv_email_nwk_cb_struct));
        if (!sync_p)
        {
            srv_email_mem_free(new_cntx_p);
            *errcode = SRV_EMAIL_RESULT_NO_MEMORY;
            return NULL;
        }
        memset(sync_p, 0, sizeof(srv_email_nwk_cb_struct));

        sync_p->action = SRV_EMAIL_NWK_CONNECT;
        sync_p->fldr_id[0] = srv_email_stor_fldr_get_id_by_type(acct_id, SRV_EMAIL_FLDR_TYPE_INBOX);
        sync_p->fldr_count = 1;

        comm_p->sync_cb_p = sync_p;
    }

    comm_p->acct_id = acct_id;

    if (!srv_email_nwk_cntx_p)
    {
        srv_email_nwk_cntx_p = new_cntx_p;
    }
    else
    {
        while (cntx_p->next)
        {
            cntx_p = cntx_p->next;
        }

        cntx_p->next = new_cntx_p;
    }

    return new_cntx_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_run_cntx
 * DESCRIPTION
 *  This function is used to run the Network context.
 * PARAMETERS
 *  cntx            [IN]        The pointer point to the Network context
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_run_cntx(srv_email_nwk_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (comm_p->running_cb_p)
    {
        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }

    srv_email_nwk_stop_job(cntx);

    EMAILSRV_ASSERT(comm_p->pending_cb_list_p);

    comm_p->running_cb_p = comm_p->pending_cb_list_p;
    comm_p->pending_cb_list_p = comm_p->pending_cb_list_p->next;

    srv_email_nwk_start_job(srv_email_nwk_fsm_schdl, cntx);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_destroy_cntx
 * DESCRIPTION
 *  This function is used to destroy the specified Network context.
 * PARAMETERS
 *  data            [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_nwk_destroy_cntx(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx = (srv_email_nwk_cntx_struct*)data;
    srv_email_nwk_cntx_struct *cntx_p = srv_email_nwk_cntx_p;
    srv_email_comm_cntx_struct *comm_p = &cntx->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAILSRV_EXT_ASSERT(
        (!comm_p->idle_cb_list_p && !comm_p->pending_cb_list_p && !comm_p->running_cb_p),
        (U32)comm_p->idle_cb_list_p,
        (U32)comm_p->pending_cb_list_p,
        (U32)comm_p->running_cb_p);

    if (comm_p->destroy_flag)
    {
        return;
    }

    switch (comm_p->protocol)
    {
        case EMAIL_PS_PRTOTOCOL_TYPE_SMTP:
            srv_email_smtp_cntx_free((srv_email_smtp_cntx_struct*)cntx);
            break;

        case EMAIL_PS_PRTOTOCOL_TYPE_POP3:
            srv_email_pop3_cntx_free((srv_email_pop3_cntx_struct*)cntx);
            break;

        case EMAIL_PS_PRTOTOCOL_TYPE_IMAP4:
            srv_email_imap4_cntx_free((srv_email_imap4_cntx_struct*)cntx);
            break;

        default:
            EMAILSRV_EXT_ASSERT(0, comm_p->protocol, 0, 0);
            break;
    }

    if (comm_p->sync_cb_p)
    {
        srv_email_mem_free(comm_p->sync_cb_p);
    }

    if (comm_p->acct_handle != EMAIL_ACCT_INVALID_HANDLE)
    {
        srv_email_acct_destroy(comm_p->acct_handle);
    }

    if (comm_p->ps_handle != EMAIL_PS_INVALID_HANDLE)
    {
        srv_email_ps_disconnect_req(comm_p->ps_handle);
        srv_email_ps_destroy_instance_req(comm_p->ps_handle);
    }

    srv_email_nwk_deactivate_bearer(comm_p->nwk_acct_id,cntx);

    if (cntx_p == cntx)
    {
        srv_email_nwk_cntx_p = cntx_p->next;
    }
    else
    {
        while (cntx_p)
        {
            if (cntx_p->next == cntx)
            {
                cntx_p->next = cntx->next;
                break;
            }
            cntx_p = cntx_p->next;
        }
    }

    srv_email_mem_free(cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_is_cntx_valid
 * DESCRIPTION
 *  This function is used to check if the Network context is valid.
 * PARAMETERS
 *  cntx            [IN]        The pointer point to the Network context
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 *****************************************************************************/
MMI_BOOL srv_email_nwk_is_cntx_valid(srv_email_nwk_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = srv_email_nwk_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (cntx_p)
    {
        if (cntx_p == cntx)
        {
            return MMI_TRUE;
        }

        cntx_p = cntx_p->next;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_get_cntx_list
 * DESCRIPTION
 *  This function is used to get the Network context list.
 * PARAMETERS
 *  void
 * RETURNS
 *  The pointer point to the Network context.
 *****************************************************************************/
srv_email_nwk_cntx_struct *srv_email_nwk_get_cntx_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_email_nwk_cntx_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_get_cntx_by_id
 * DESCRIPTION
 *  This function is used to get the Network context pointer with account id and server type.
 * PARAMETERS
 *  acct_id         [IN]        The account id
 *  is_incoming     [IN]        If incoming or outgoing server
 * RETURNS
 *  The pointer point to the Network context.
 *****************************************************************************/
srv_email_nwk_cntx_struct *srv_email_nwk_get_cntx_by_id(EMAIL_ACCT_ID acct_id, MMI_BOOL is_incoming)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = srv_email_nwk_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (cntx_p)
    {
        if (cntx_p->common.acct_id == acct_id &&
            ((cntx_p->common.protocol == SRV_EMAIL_PROT_SMTP && !is_incoming) ||
             (cntx_p->common.protocol != SRV_EMAIL_PROT_SMTP && is_incoming)))
        {
            break;
        }

        cntx_p = cntx_p->next;
    }

    return cntx_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_get_cntx_by_cb
 * DESCRIPTION
 *  This function is used to get the Network context pointer with control block.
 * PARAMETERS
 *  cb              [IN]        The pointer point to the control block
 * RETURNS
 *  The pointer point to the Network context.
 *****************************************************************************/
srv_email_nwk_cntx_struct *srv_email_nwk_get_cntx_by_cb(srv_email_nwk_cb_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = srv_email_nwk_cntx_p;
    srv_email_nwk_cb_struct *cb_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (cntx_p)
    {
        /* Check the running control block */
        cb_p = cntx_p->common.running_cb_p;
        if (cb_p && cb_p == cb)
        {
            return cntx_p;
        }

        /* Check the pending control block list */
        cb_p = cntx_p->common.pending_cb_list_p;
        while (cb_p)
        {
            if (cb_p == cb)
            {
                return cntx_p;
            }

            cb_p = cb_p->next;
        }

        /* Check the idle control block list */
        cb_p = cntx_p->common.idle_cb_list_p;
        while (cb_p)
        {
            if (cb_p == cb)
            {
                return cntx_p;
            }

            cb_p = cb_p->next;
        }

        cntx_p = cntx_p->next;
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_get_cntx_by_ps_handle
 * DESCRIPTION
 *  This function is used to get the Network context pointer with PS handle.
 * PARAMETERS
 *  handle          [IN]        The PS handle
 * RETURNS
 *  The pointer point to the Network context.
 *****************************************************************************/
srv_email_nwk_cntx_struct *srv_email_nwk_get_cntx_by_ps_handle(EMAIL_PS_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = srv_email_nwk_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (cntx_p)
    {
        if (cntx_p->common.ps_handle == handle)
        {
            break;
        }

        cntx_p = cntx_p->next;
    }

    return cntx_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_get_running_cb
 * DESCRIPTION
 *  This function is used to get the running control block in the specified Network context.
 * PARAMETERS
 *  cntx            [IN]        The pointer point to the Network context
 * RETURNS
 *  The pointer point to the running control block.
 *****************************************************************************/
srv_email_nwk_cb_struct *srv_email_nwk_get_running_cb(srv_email_nwk_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cntx->common.running_cb_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_update_running_cb
 * DESCRIPTION
 *  This function is used to update the running control block in the specified Network context.
 * PARAMETERS
 *  cntx            [IN]        The pointer point to the Network context
 *  notify_result   [IN]        If need notify the result or not
 * RETURNS
 *  The pointer point to the next control block.
 *****************************************************************************/
srv_email_nwk_cb_struct *srv_email_nwk_update_running_cb(
                            srv_email_nwk_cntx_struct *cntx,
                            MMI_BOOL notify_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx->common;
    srv_email_nwk_cb_struct *cb_p = comm_p->running_cb_p;
    MMI_BOOL is_normal_cb = MMI_FALSE;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cb_p && cb_p != comm_p->sync_cb_p)
    {
        srv_email_nwk_append_cb_to_idle_list(cntx, cb_p);
        if (!notify_result)
        {
            cb_p->action = SRV_EMAIL_NWK_NONE;
        }
        is_normal_cb = MMI_TRUE;
    }

    if (comm_p->pending_cb_list_p)
    {
        comm_p->running_cb_p = comm_p->pending_cb_list_p;
        comm_p->pending_cb_list_p = comm_p->pending_cb_list_p->next;
    }
    else if (comm_p->sync_cb_p && is_normal_cb)
    {
        ret = srv_email_nwk_is_connected_cb_exist(cntx);
        if (ret)
        {
            comm_p->running_cb_p = comm_p->sync_cb_p;
        }
        else
        {
            comm_p->running_cb_p = NULL;
        }
    }
    else
    {
        comm_p->running_cb_p = NULL;
    }

    if (is_normal_cb && notify_result)
    {
        srv_email_nwk_cb_finish_notify(cb_p, &comm_p->result);
    }

    if (comm_p->refresh_flag && !comm_p->refresh_notified)
    {
        srv_email_need_refresh_data_struct refresh_data;

        refresh_data.refresh_type = comm_p->refresh_type;
        srv_email_nwk_cb_process_notify(cntx, NULL, SRV_EMAIL_NWK_NEED_REFRESH, &refresh_data);

        comm_p->refresh_notified = MMI_TRUE;
    }
    else if (!comm_p->refresh_flag && comm_p->refresh_notified && comm_p->refresh_result)
    {
        srv_email_nwk_cb_process_notify(cntx, NULL, SRV_EMAIL_NWK_REFRESHED, NULL);

        comm_p->refresh_notified = MMI_FALSE;
    }

    return comm_p->running_cb_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_update_running_cb_for_disc_ind
 * DESCRIPTION
 *  This function is used to update the running control block in the specified Network context.
 * PARAMETERS
 *  cntx            [IN]        The pointer point to the Network context
 * RETURNS
 *  The pointer point to the next control block.
 *****************************************************************************/
srv_email_nwk_cb_struct *srv_email_nwk_update_running_cb_for_disc_ind(srv_email_nwk_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx->common;
    srv_email_nwk_cb_struct *cb_p = comm_p->running_cb_p;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cb_p && cb_p != comm_p->sync_cb_p)
    {
        srv_email_nwk_append_cb_to_idle_list(cntx, cb_p);
        ret = MMI_TRUE;
    }

    if (comm_p->pending_cb_list_p)
    {
        comm_p->running_cb_p = comm_p->pending_cb_list_p;
        comm_p->pending_cb_list_p = comm_p->pending_cb_list_p->next;
    }
    else
    {
        comm_p->running_cb_p = NULL;
    }

    if (ret)
    {
        srv_email_nwk_cb_finish_notify(cb_p, &comm_p->result);
    }

    if (comm_p->refresh_notified)
    {
        srv_email_nwk_cb_process_notify(cntx, NULL, SRV_EMAIL_NWK_REFRESHED, NULL);

        comm_p->refresh_result = MMI_FALSE;
        comm_p->refresh_notified = MMI_FALSE;
        comm_p->refresh_flag = MMI_FALSE;
        comm_p->refresh_type = 0;
    }

    return comm_p->running_cb_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_is_sync_cb
 * DESCRIPTION
 *  This function is used to check if the control block is used for sync.
 * PARAMETERS
 *  cntx            [IN]        The pointer point to the Network context
 *  cb              [IN]        The pointer point to the control block
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 *****************************************************************************/
MMI_BOOL srv_email_nwk_is_sync_cb(srv_email_nwk_cntx_struct *cntx, srv_email_nwk_cb_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (comm_p->sync_cb_p && comm_p->sync_cb_p == cb)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_is_cb_full
 * DESCRIPTION
 *  This function is used to check if the control block is full in the specified Network context.
 * PARAMETERS
 *  cntx            [IN]        The pointer point to the Network context
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 *****************************************************************************/
MMI_BOOL srv_email_nwk_is_cb_full(srv_email_nwk_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx->common;
    srv_email_nwk_cb_struct *cb_p = NULL;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (comm_p->running_cb_p)
    {
        count++;
    }

    cb_p = comm_p->pending_cb_list_p;
    while (cb_p)
    {
        count++;
        cb_p = cb_p->next;
    }

    cb_p = comm_p->idle_cb_list_p;
    while (cb_p)
    {
        count++;
        cb_p = cb_p->next;
    }

    if (count < SRV_EMAIL_MAX_CB_NUM)
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
 *  srv_email_nwk_is_cb_empty
 * DESCRIPTION
 *  This function is used to check if the control block is empty in the specified Network context.
 * PARAMETERS
 *  cntx            [IN]        The pointer point to the Network context
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 *****************************************************************************/
MMI_BOOL srv_email_nwk_is_cb_empty(srv_email_nwk_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (comm_p->running_cb_p && comm_p->running_cb_p != comm_p->sync_cb_p)
    {
        return MMI_FALSE;
    }

    if (comm_p->pending_cb_list_p)
    {
        return MMI_FALSE;
    }

    if (comm_p->idle_cb_list_p)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_is_pending_cb_empty
 * DESCRIPTION
 *  This function is used to check if the pending control block is empty.
 * PARAMETERS
 *  cntx            [IN]        The pointer point to the Network context
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 *****************************************************************************/
MMI_BOOL srv_email_nwk_is_pending_cb_empty(srv_email_nwk_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cntx->common.pending_cb_list_p ? MMI_FALSE : MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_is_connected_cb_exist
 * DESCRIPTION
 *  This function is used to check if the connected control block exist.
 * PARAMETERS
 *  cntx            [IN]        The pointer point to the Network context
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 *****************************************************************************/
MMI_BOOL srv_email_nwk_is_connected_cb_exist(srv_email_nwk_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx->common;
    srv_email_nwk_cb_struct *cb_p = comm_p->pending_cb_list_p;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 2; i++)
    {
        while (cb_p)
        {
            if (cb_p->state & SRV_EMAIL_NWK_CB_CONNECTED)
            {
                return MMI_TRUE;
            }

            cb_p = cb_p->next;
        }

        cb_p = comm_p->idle_cb_list_p;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_append_cb_to_idle_list
 * DESCRIPTION
 *  This function is used to append the control block to the Network context.
 * PARAMETERS
 *  cntx            [IN]        The pointer point to the Network context
 *  cb              [IN]        The pointer point to the control block
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_nwk_append_cb_to_idle_list(
        srv_email_nwk_cntx_struct *cntx,
        srv_email_nwk_cb_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx->common;
    srv_email_nwk_cb_struct *cb_p = comm_p->idle_cb_list_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!comm_p->idle_cb_list_p)
    {
        comm_p->idle_cb_list_p = cb;
    }
    else
    {
        while (cb_p->next)
        {
            cb_p = cb_p->next;
        }

        cb_p->next = cb;
    }

    cb->next = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_move_cb_to_pending
 * DESCRIPTION
 *  This function is used to move the control block to pending list.
 * PARAMETERS
 *  cntx            [IN]        The pointer point to the Network context     
 *  cb              [IN]        The pointer point to the control block     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_nwk_move_cb_to_pending(
        srv_email_nwk_cntx_struct *cntx,
        srv_email_nwk_cb_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx->common;
    srv_email_nwk_cb_struct *prev_cb_p = comm_p->idle_cb_list_p;
    srv_email_nwk_cb_struct *cb_p = comm_p->idle_cb_list_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cb_p == cb)
    {
        comm_p->idle_cb_list_p = cb_p->next;
    }
    else
    {
        while (cb_p)
        {
            if (cb_p == cb)
            {
                break;
            }
            prev_cb_p = cb_p;
            cb_p = cb_p->next;
        }

        prev_cb_p->next = cb_p->next;
    }

    cb_p = comm_p->pending_cb_list_p;

    if (!cb_p)
    {
        comm_p->pending_cb_list_p = cb;
    }
    else
    {
        while (cb_p->next)
        {
            cb_p = cb_p->next;
        }

        cb_p->next = cb;
    }

    cb->next = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_move_cb_to_idle
 * DESCRIPTION
 *  This function is used to move the control block to idle list.
 * PARAMETERS
 *  cntx            [IN]        The pointer point to the Network context     
 *  cb              [IN]        The pointer point to the control block     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_nwk_move_cb_to_idle(
        srv_email_nwk_cntx_struct *cntx,
        srv_email_nwk_cb_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx->common;
    srv_email_nwk_cb_struct *prev_cb_p = comm_p->pending_cb_list_p;
    srv_email_nwk_cb_struct *cb_p = comm_p->idle_cb_list_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (cb_p)
    {
        if (cb_p == cb)
        {
            return;
        }
        cb_p = cb_p->next;
    }

    cb_p = comm_p->pending_cb_list_p;

    if (cb_p == cb)
    {
        comm_p->pending_cb_list_p = cb_p->next;
    }
    else
    {
        while (cb_p)
        {
            if (cb_p == cb)
            {
                break;
            }
            prev_cb_p = cb_p;
            cb_p = cb_p->next;
        }

        prev_cb_p->next = cb_p->next;
    }

    cb_p = comm_p->idle_cb_list_p;

    if (!cb_p)
    {
        comm_p->idle_cb_list_p = cb;
    }
    else
    {
        while (cb_p->next)
        {
            cb_p = cb_p->next;
        }

        cb_p->next = cb;
    }

    cb->next = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_move_cb_running_to_idle
 * DESCRIPTION
 *  This function is used to move the control block to idle list.
 * PARAMETERS
 *  cntx            [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_nwk_move_cb_running_to_idle(srv_email_nwk_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx->common;
    srv_email_nwk_cb_struct *cb_p = comm_p->idle_cb_list_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cb_p)
    {
        comm_p->idle_cb_list_p = comm_p->running_cb_p;
    }
    else
    {
        while (cb_p->next)
        {
            cb_p = cb_p->next;
        }

        cb_p->next = comm_p->running_cb_p;
    }

    comm_p->running_cb_p = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_remove_cb
 * DESCRIPTION
 *  This function is used to remove the control block from the Network context.
 * PARAMETERS
 *  cntx            [IN]        The pointer point to the Network context
 *  cb              [IN]        The pointer point to the control block
 *  cntx_valid      [OUT]       If the Network context will be valid after remove
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_nwk_remove_cb(srv_email_nwk_cntx_struct *cntx, srv_email_nwk_cb_struct *cb, MMI_BOOL *cntx_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx->common;
    srv_email_nwk_cb_struct *cb_p = NULL;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_nwk_abort_cb(cntx, cb);

    cb_p = comm_p->idle_cb_list_p;
    if (cb_p == cb)
    {
        comm_p->idle_cb_list_p = cb_p->next;
    }
    else
    {
        while (cb_p->next)
        {
            if (cb_p->next == cb)
            {
                cb_p->next = cb->next;
                break;
            }
            cb_p = cb_p->next;
        }
    }

    if (cb->action_data)
    {
        srv_email_mem_free(cb->action_data);
    }
    srv_email_mem_free(cb);

    ret = srv_email_nwk_is_cb_empty(cntx);
    if (ret)
    {
        /* If the running cb is sync cb, abort the FSM */
        if (comm_p->running_cb_p)
        {
            if (cntx->nwk_state == SRV_EMAIL_NWK_STATE_UPDATING)
            {
                srv_email_nwk_fsm_abort(cntx);
            }
            else
            {
                comm_p->running_cb_p = NULL;
            }
        }
    }

    if (cntx_valid)
    {
        *cntx_valid = ret ? MMI_FALSE : MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_abort_cb
 * DESCRIPTION
 *  This function is used to abort the control block operation.
 * PARAMETERS
 *  cntx            [IN]        The pointer point to the Network context
 *  cb              [IN]        The pointer point to the control block
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_nwk_abort_cb(srv_email_nwk_cntx_struct *cntx, srv_email_nwk_cb_struct *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cb_struct *cb_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_p = srv_email_nwk_get_running_cb(cntx);
    if (cb_p != cb)
    {
        cb->action = SRV_EMAIL_NWK_NONE;
        if (cb->action_data)
        {
            srv_email_mem_free(cb->action_data);
        }
        cb->action_data = NULL;

        srv_email_nwk_move_cb_to_idle(cntx, cb);
    }
    else
    {
        srv_email_nwk_fsm_abort(cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_cb_process_notify
 * DESCRIPTION
 *  This function is used to notify the process of the specified control block.
 * PARAMETERS
 *  cntx              [IN]        The pointer point to the Network context
 *  cb              [IN]        The pointer point to the control block
 *  status          [IN]        The status
 *  status_data     [IN]        The pointer point to the status related data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_nwk_cb_process_notify(
        srv_email_nwk_cntx_struct *cntx,
        srv_email_nwk_cb_struct *cb,
        srv_email_nwk_status_enum status,
        void *status_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = NULL;
    srv_email_nwk_cb_struct *p_next = NULL;
    srv_email_nwk_proc_struct process;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAILSRV_ASSERT(cntx || cb);

    if (status != SRV_EMAIL_NWK_NEED_REFRESH &&
        status != SRV_EMAIL_NWK_REFRESHED &&
        status != SRV_EMAIL_NWK_DISCONNECTED)
    {
        if (!cb)
        {
            cb = srv_email_nwk_get_running_cb(cntx);
        }

        if (cb && cb->proc_callback)
        {
            process.status = status;
            process.status_data = status_data;
            process.user_data = cb->proc_user_data;
            
            cb->proc_callback(&process);
        }
    }
    else
    {
        if (cb)
        {
            if ((cb->state & SRV_EMAIL_NWK_CB_CONNECTED) &&
                cb->proc_callback)
            {
                process.status = status;
                process.status_data = status_data;
                process.user_data = cb->proc_user_data;

                cb->proc_callback(&process);
            }
            return;
        }

        comm_p = &cntx->common;
        cb = comm_p->pending_cb_list_p;

        for (i = 0; i < 2; i++)
        {
            while (cb)
            {
                p_next = cb->next;

                if ((cb->state & SRV_EMAIL_NWK_CB_CONNECTED) &&
                    cb->proc_callback)
                {
                    if (status == SRV_EMAIL_NWK_DISCONNECTED)
                    {
                        cb->state &= ~SRV_EMAIL_NWK_CB_CONNECTED;
                    }

                    process.status = status;
                    process.status_data = status_data;
                    process.user_data = cb->proc_user_data;

                    cb->proc_callback(&process);
                }

                cb = p_next;
            }

            cb = comm_p->idle_cb_list_p;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_cb_finish_notify
 * DESCRIPTION
 *  This function is used to notify the result of the specified control block.
 * PARAMETERS
 *  cb              [IN]        The pointer point to the control block
 *  result          [IN]        The pointer point to the result
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_nwk_cb_finish_notify(srv_email_nwk_cb_struct *cb, srv_email_result_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_finish_struct *result_p = NULL;
    srv_email_nwk_finish_funcptr_type callback = cb->finish_callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result_p = (srv_email_nwk_finish_struct*)OslMalloc(sizeof(srv_email_nwk_finish_struct));

    memcpy(&result_p->result, result, sizeof(srv_email_result_struct));
    result_p->action = cb->action;
    result_p->user_data = cb->finish_user_data;

    cb->action = SRV_EMAIL_NWK_NONE;

    if (callback)
    {
        callback(result_p);
    }

    OslMfree(result_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_start_job
 * DESCRIPTION
 *  This function is used to schedule the Network operation.
 * PARAMETERS
 *  callback        [IN]        The callback function
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_nwk_start_job(srv_email_schdl_funcptr_type callback, srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!comm_p->schdl_flag)
    {
        comm_p->req_id = srv_email_schdl_start_job(callback, cntx_p);
        cntx_p->common.schdl_flag = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_stop_job
 * DESCRIPTION
 *  This function is used to stop the schedule of the Network operation.
 * PARAMETERS
 *  cntx_p          [IN]        The pointer point to the Network context
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_nwk_stop_job(srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comm_cntx_struct *comm_p = &cntx_p->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (comm_p->schdl_flag)
    {
        srv_email_schdl_stop_job(comm_p->req_id);
        cntx_p->common.schdl_flag = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_list_remote_fldr_id
 * DESCRIPTION
 *  This function is used to list the remote folder ids.
 * PARAMETERS
 *  acct_id         [IN]        The account id
 *  fldr_id         [OUT]       Used to store the remote folder ids
 *  fldr_cnt        [IN/OUT]    The folder count
 * RETURNS
 *  The error code.
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_list_remote_fldr_id(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID *fldr_id,
                        U16 *fldr_cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    EMAIL_STOR_HANDLE stor_handle = EMAIL_STOR_INVALID_HANDLE;
    U16 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    retval = srv_email_stor_acct_get_fldr_id_open(
                acct_id,
                SRV_EMAIL_FLDR_TYPE_REMOTE,
                &stor_handle);
    if (retval != SRV_EMAIL_RESULT_SUCC)
    {
        return retval;
    }

    while (1)
    {
        retval = srv_email_stor_acct_get_fldr_id_next(stor_handle, &fldr_id[count]);
        if (retval == SRV_EMAIL_RESULT_SUCC)
        {
            count++;
        }
        else
        {
            if (retval == SRV_EMAIL_RESULT_NO_MORE_RESULT)
            {
                retval = SRV_EMAIL_RESULT_SUCC;
            }
            break;
        }
    }

    srv_email_stor_acct_get_fldr_id_close(stor_handle);

    if (retval == SRV_EMAIL_RESULT_SUCC)
    {
        *fldr_cnt = count;
    }

    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_get_cbm_app_id
 * DESCRIPTION
 *  This function is used to get the CBM app id.
 * PARAMETERS
 *  acct_id         [IN]        The account id
 *  is_incoming     [IN]        Incoming/Outgoing
 *  dataacct_id     [IN]        The data account id
 * RETURNS
 *  The app id.
 *****************************************************************************/
U8 srv_email_nwk_get_cbm_app_id(EMAIL_ACCT_ID acct_id, MMI_BOOL is_incoming, U32 dataacct_id,srv_email_nwk_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_app_info_query_struct app_info_query;
    cbm_app_info_struct info;
    U8 app_id = CBM_INVALID_APP_ID;
    S32 retval = 0;
    MMI_BOOL ret = MMI_TRUE;
    //MMI_BOOL same_app_id;
    U8 temp_app_id = CBM_INVALID_APP_ID;
    srv_email_app_id_reg_struct *app_id_reg_p = NULL;
    srv_email_nwk_cntx_struct *cntx = NULL;
    kal_int32 state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_email_nwk_p->callback)
    {
        app_info_query.acct_id = acct_id;
        app_info_query.is_incoming = is_incoming;
        app_info_query.dataacct_id = dataacct_id;
       
        app_id_reg_p = srv_email_app_id_reg;
        cntx = srv_email_nwk_get_cntx_list();
        if(app_id_reg_p)
        {
            while(app_id_reg_p)
            {
                if(app_id_reg_p->acct_id == acct_id)
                {
                   if(app_id_reg_p->incoming_app_id)
                   {
                      temp_app_id = app_id_reg_p->incoming_app_id;
                   }
                   if(app_id_reg_p->outgoing_app_id)
                   {
                      temp_app_id = app_id_reg_p->outgoing_app_id;
                   }               
                   //temp_app_id = app_id_reg_p->incoming_app_id;
                   app_info_query.app_id = temp_app_id;
                   break;
                }
                app_id_reg_p = app_id_reg_p->next;
           }
           if(!app_id_reg_p)
           {
               while(cntx)
               {
                   if(cntx != cntx_p &&
                   cntx->common.acct_id == acct_id)
                   {
                      temp_app_id = cbm_get_app_id(cntx->common.nwk_acct_id);
                      app_info_query.app_id = temp_app_id;
                      break;
                   }
                   cntx = cntx->next;
              }
              if(!cntx)
              { 
                   app_info_query.app_id = app_id;
              }
           }
        }
        else
        {           
            while(cntx)
               {
                   if(cntx != cntx_p &&
                   cntx->common.acct_id == acct_id)
                   {
                      temp_app_id = cbm_get_app_id(cntx->common.nwk_acct_id);
                      app_info_query.app_id = temp_app_id;
                      break;
                   }
                   cntx = cntx->next;
              }
              if(!cntx)
              { 
                   app_info_query.app_id = app_id;
              }
        }

        ret = srv_email_nwk_p->callback(&app_info_query, &info.app_str_id, &info.app_icon_id);
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_GET_CBM_APP_INFO, ret, info.app_str_id, info.app_icon_id);
        if (ret)
        {
            app_id_reg_p=srv_email_app_id_reg;
            cntx = srv_email_nwk_get_cntx_list();
            
            if(app_id_reg_p)
            {
                while(app_id_reg_p)
                {
                    if(app_id_reg_p->acct_id == acct_id)
                    {
                        if(app_id_reg_p->outgoing_app_id == 0 && app_id_reg_p->incoming_app_id ==0)
                        {
                            info.app_type = DTCNT_APPTYPE_EMAIL;       
                            retval = cbm_register_app_id_with_app_info(&info, &app_id);
                            app_id_reg_p->outgoing_app_id=app_id;
                            app_id_reg_p->incoming_app_id=app_id;
                            return app_id;
                        }
                        else
                        {
                            if (app_id_reg_p->outgoing_app_id)
                            {
                                return app_id_reg_p->outgoing_app_id;
                            }
                            else
                            {
                                return app_id_reg_p->incoming_app_id;
                            }
                        }
                    }
                    app_id_reg_p = app_id_reg_p->next;
                }
                if(!app_id_reg_p)
                {                    
                    while(cntx)
                    {
                        if((cntx!=cntx_p) && (cntx->common.acct_id == cntx_p->common.acct_id))
                        {
                            state=cbm_get_bearer_status(cntx->common.nwk_acct_id);
                            if(state==CBM_ACTIVATED)//check it
                            {
                                app_id= cbm_get_app_id(cntx->common.nwk_acct_id);
                                return app_id;
                            }
                        }
                        cntx=cntx->next;
                    }
                    if(!app_id_reg_p && !cntx)
                    {
                        info.app_type = DTCNT_APPTYPE_EMAIL;
                        retval = cbm_register_app_id_with_app_info(&info, &app_id);
                        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_REGISTER_CBM_APP_ID, retval, app_id);
                        return app_id;
                    }     
                }
                
            }
            else
            { 
                while(cntx)
                {
                    if((cntx!=cntx_p) && (cntx->common.acct_id == cntx_p->common.acct_id))
                    {
                        state=cbm_get_bearer_status(cntx->common.nwk_acct_id);
                        if(state==CBM_ACTIVATED)//check it
                        {
                            app_id= cbm_get_app_id(cntx->common.nwk_acct_id);
                            return app_id;
                        }
                    }
                    cntx=cntx->next;
                }
                if(!cntx)
                {
                    info.app_type = DTCNT_APPTYPE_EMAIL;
                    retval = cbm_register_app_id_with_app_info(&info, &app_id);
                    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_REGISTER_CBM_APP_ID, retval, app_id);
                    return app_id;
                }
            }
               
       }
       return app_id;       
    }
    return app_id; 
}


void srv_email_get_stor_error(S32 ret, S32 *major, S32 *minor)
{
    if (ret == SRV_EMAIL_RESULT_FS_ERROR)
    {
        *major = SRV_EMAIL_FS_ERROR;
        *minor = srv_email_stor_get_detail_errno((srv_email_result_enum)ret);
    }
    else
    {
        *major = SRV_EMAIL_MAIL_ERROR;
        *minor = ret;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_compute_acct_digest
 * DESCRIPTION
 *  This function is used to compute the account's digest.
 * PARAMETERS
 *  server_name     [IN]        The pointer point to the server name
 *  username        [IN]        The pointer point to the username
 *  digest          [OUT]       Used to return
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_compute_acct_digest(WCHAR *server_name, WCHAR *username, U8 *digest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = 0;
    WCHAR *buf = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAILSRV_EXT_ASSERT((server_name && username && digest), (U32)server_name, (U32)username, (U32)digest);

    len = (mmi_wcslen(server_name) + mmi_wcslen(username) + 2) * 2;
    buf = (WCHAR*)srv_email_mem_alloc(len);
    memset(buf, 0, len);

    kal_wsprintf(buf, "%w %w", server_name, username);
    len = mmi_wcslen(buf);

    /* Compute digest value through MD5 by given account string */
    srv_email_compute_md5_digest((const CHAR*)buf, len * 2, digest);

    srv_email_mem_free(buf);
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_cbm_hold
 * DESCRIPTION
 *  This function is used to hold the bearer.
 * PARAMETERS
 *  acct_id                    [IN]        
 *  hold_outgoing           [IN]       
 *  hold_incoming           [IN]
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
extern srv_email_result_enum srv_email_cbm_hold(
                                EMAIL_ACCT_ID acct_id,
                                MMI_BOOL hold_outgoing,
                                MMI_BOOL hold_incoming)
{
    srv_email_app_id_reg_struct *app_id_reg_p = NULL;
    srv_email_nwk_cntx_struct *cntx_p = NULL;
    U8 app_id = 0;

    app_id_reg_p = srv_email_app_id_reg;

    while (app_id_reg_p)//check
    {
        if (acct_id == app_id_reg_p->acct_id)
        {
            if (hold_outgoing)
            {
                app_id_reg_p->hold_outgoing = MMI_TRUE;
            }
            if (hold_incoming)
            {
                app_id_reg_p->hold_incoming = MMI_TRUE;
            }
            return SRV_EMAIL_RESULT_SUCC;
        }
        app_id_reg_p = app_id_reg_p->next;
    }

    app_id_reg_p = (srv_email_app_id_reg_struct*)
        srv_email_mem_alloc(sizeof(srv_email_app_id_reg_struct));

    if (!app_id_reg_p)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    memset(app_id_reg_p, 0, sizeof(srv_email_app_id_reg_struct));
    app_id_reg_p->acct_id = acct_id;
    if (hold_outgoing)
    {
        app_id_reg_p->hold_outgoing = MMI_TRUE;
    }
    if (hold_incoming)
    {
        app_id_reg_p->hold_incoming = MMI_TRUE;
    }

    cntx_p = srv_email_nwk_get_cntx_list();

    while (cntx_p)
    {
        if (cntx_p->common.acct_id == acct_id)
        {
            if (cntx_p->common.protocol == EMAIL_PS_PRTOTOCOL_TYPE_SMTP)
            {
                app_id = cbm_get_app_id(cntx_p->common.nwk_acct_id);
                app_id_reg_p->outgoing_app_id = app_id;//check
            }
            else
            {
                app_id = cbm_get_app_id(cntx_p->common.nwk_acct_id);
                app_id_reg_p->incoming_app_id = app_id;//check
            }
        }

        cntx_p = cntx_p->next;
    }

    app_id_reg_p->next = srv_email_app_id_reg;
    srv_email_app_id_reg = app_id_reg_p;

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_cbm_hold
 * DESCRIPTION
 *  This function is used to release the bearer.
 * PARAMETERS
 *  acct_id                    [IN]        
 *  hold_outgoing           [IN]       
 *  hold_incoming           [IN]
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
extern srv_email_result_enum srv_email_cbm_release(
                                EMAIL_ACCT_ID acct_id,
                                MMI_BOOL hold_outgoing,
                                MMI_BOOL hold_incoming)
{
    srv_email_app_id_reg_struct *app_id_reg_p = NULL;
    srv_email_app_id_reg_struct *temp_app_id_reg_p = NULL;
    //srv_email_nwk_cntx_struct *cntx_p;
    app_id_reg_p = srv_email_app_id_reg;

    while (app_id_reg_p)
    {
        if (acct_id == app_id_reg_p->acct_id)
        {
            if (hold_outgoing)
            {
                app_id_reg_p->hold_outgoing = MMI_FALSE;
            }
            if (hold_incoming)
            {
                app_id_reg_p->hold_incoming = MMI_FALSE;
            }

            if (!app_id_reg_p->hold_outgoing && !app_id_reg_p->hold_incoming)
            {
                if (app_id_reg_p == srv_email_app_id_reg)
                {
                    srv_email_app_id_reg = app_id_reg_p->next;
                    srv_email_mem_free(app_id_reg_p);
                }
                else
                {
                    temp_app_id_reg_p->next = app_id_reg_p->next;
                    srv_email_mem_free(app_id_reg_p);
                }
            }
            return SRV_EMAIL_RESULT_SUCC;
        }

        temp_app_id_reg_p = app_id_reg_p;
        app_id_reg_p = app_id_reg_p->next;
    }

    return SRV_EMAIL_RESULT_SUCC;
}

#ifdef __MMI_SSO__

static srv_email_cloud_provider_struct *srv_email_nwk_get_cloud_provider(U32 provider_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_EMAIL_MAX_CLOUD_PROVIDER_NUM; i++)
    {
        if (srv_email_cloud_providers[i].provider_id == provider_id)
        {
            return &srv_email_cloud_providers[i];
        }
    }

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_GET_PROVIDER_FAIL, provider_id);
    return NULL;
}


static S32 srv_email_nwk_load_cloud_plugin(WCHAR *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMUINT library;
    cloud_plugin_manifest_func manifest_func;
    cloud_plugin_provider_struct *prov_p;
    U32 i;
    U32 j;
    S32 cnt = 0;
    srv_email_cloud_provider_struct *email_prov_p;
    MMI_BOOL is_valid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prov_p = (cloud_plugin_provider_struct*)srv_email_mem_alloc(sizeof(cloud_plugin_provider_struct));
    if (!prov_p)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_LOAD_CLOUD_PLUGIN_FAIL, __LINE__);
        return -1;
    }

    library = vm_native_load_library((VMWSTR)filename);
    if (library)
    {
        manifest_func = (cloud_plugin_manifest_func)vm_native_get_symbol(library, "cloud_plugin_manifest");
        if (manifest_func)
        {
            vm_pmng_set_ctx(library);
            manifest_func(prov_p);
            vm_pmng_reset_ctx();

            is_valid = srv_email_sso_is_provider_valid((U32)prov_p->id);
            if (is_valid)
            {
                for (i = 0; i < CLOUD_PLUGIN_FEATURE_TOTAL; i++)
                {
                    if (prov_p->server[i].features & CLOUD_PLUGIN_FEATURE_TYPE_EMAIL_REFRESH)
                    {
                        for (j = 0; j < SRV_EMAIL_MAX_CLOUD_SERVER_NUM; j++)
                        {
                            if (srv_email_cloud_server[j].provider_id == 0)
                            {
                                srv_email_cloud_server[j].provider_id = prov_p->id;
                                memcpy(
                                    &srv_email_cloud_server[j].server_info,
                                    &prov_p->server[i],
                                    sizeof(cloud_plugin_server_info_struct));
                                cnt++;

                                email_prov_p = srv_email_nwk_get_cloud_provider(prov_p->id);
                                if (!email_prov_p)
                                {
                                    email_prov_p = srv_email_nwk_get_cloud_provider(0);
                                    if (email_prov_p)
                                    {
                                        email_prov_p->provider_id = prov_p->id;
                                        mmi_wcscpy(email_prov_p->filename, filename);
                                    }
                                }
                                break;
                            }
                        }

                        if (cnt == SRV_EMAIL_MAX_CLOUD_SERVER_NUM)
                        {
                            vm_native_free_library(library);
                            goto EXIT_HANDLE;
                        }
                    }
                }
            }
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_LOAD_CLOUD_PLUGIN_FAIL, __LINE__);
        }

        vm_native_free_library(library);
    }

EXIT_HANDLE:
    srv_email_mem_free(prov_p);
    return cnt;
}


static void srv_email_nwk_read_cloud_plugin_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    FS_DOSDirEntry file_info;
    WCHAR *pattern;
    WCHAR *file_path;
    WCHAR *file_name;
    U32 file_path_len = (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2;
    S32 result = FS_NO_ERROR;
    S32 cnt = 0;
    S32 ret = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(srv_email_cloud_server, 0, sizeof(srv_email_cloud_server));
    memset(srv_email_cloud_providers, 0, sizeof(srv_email_cloud_providers));

    pattern = (WCHAR*)OslMalloc(file_path_len);
    file_path = (WCHAR*)OslMalloc(file_path_len);
    file_name = (WCHAR*)OslMalloc(file_path_len);

    memset(pattern, 0, file_path_len);
    memset(file_path, 0, file_path_len);
    memset(file_name, 0, file_path_len);

    kal_wsprintf(
        pattern,
        CLOUD_PLUGIN_PATH,
        custom_cloud_using_card_memory() ? SRV_FMGR_CARD_DRV : SRV_FMGR_PUBLIC_DRV);

#ifdef __MTK_TARGET__
    mmi_wcscat(pattern, CLOUD_PLUGIN_TARGET_EXT);
#else
    mmi_wcscat(pattern, CLOUD_PLUGIN_MODIS_EXT);
#endif

    handle = FS_FindFirst(pattern, 0, 0, &file_info, file_name, file_path_len);

    while (handle >= 0 && result == FS_NO_ERROR)
    {
        kal_wsprintf(
            file_path,
            CLOUD_PLUGIN_PATH,
            custom_cloud_using_card_memory() ? SRV_FMGR_CARD_DRV : SRV_FMGR_PUBLIC_DRV);
        mmi_wcscat(file_path, file_name);

        ret = srv_email_nwk_load_cloud_plugin(file_path);
        if (ret < 0)
        {
            goto EXIT_HANDLE;
        }

        cnt += ret;
        if (cnt == SRV_EMAIL_MAX_CLOUD_SERVER_NUM)
        {
            break;
        }

        result = FS_FindNext(handle, &file_info, file_name, file_path_len);
    }

    if (cnt == 0)
    {
        U32 i;

        for (i = 0; srv_email_cloud_preload_vpps[i].provider_id != 0; i++)
        {
            kal_wsprintf(file_path, "@:\\%u.rom", srv_email_cloud_preload_vpps[i].provider_addr);

            ret = srv_email_nwk_load_cloud_plugin(file_path);
            if (ret > 0)
            {
                cnt += ret;
            }
            else if (ret < 0)
            {
                goto EXIT_HANDLE;
            }
        }
    }

    if (cnt == 0)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_LOAD_CLOUD_PLUGIN_FAIL, __LINE__);
    }

EXIT_HANDLE:
    OslMfree(pattern);
    OslMfree(file_path);
    OslMfree(file_name);
    FS_FindClose(handle);
}


#ifdef __MMI_CLOUD_VPP_UPGRADE__
static S32 srv_email_nwk_update_cloud_plugin(srv_upgrade_result_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *filename;
    U32 file_path_len = (SRV_EMAIL_MAX_FILE_NAME_LEN + 1) * 2;
    S32 ret;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_EMAIL_MAX_CLOUD_SERVER_NUM; i++)
    {
        if (srv_email_cloud_server[i].provider_id == result->provider)
        {
            memset(&srv_email_cloud_server[i], 0, sizeof(srv_email_cloud_server_info_struct));
        }
    }

    filename = (WCHAR*)OslMalloc(file_path_len);
    memset(filename, 0, file_path_len);

    kal_wsprintf(
        filename,
        CLOUD_PLUGIN_PATH,
        custom_cloud_using_card_memory() ? SRV_FMGR_CARD_DRV : SRV_FMGR_PUBLIC_DRV);

#ifdef __MTK_TARGET__
    mmi_wcscat(filename, L"CloudEmailPlugin.vpp");
#else
    mmi_wcscat(filename, L"CloudEmailPlugin.dll");
#endif

    ret = FS_Move(result->path, filename, FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0);
    if (ret >= 0)
    {
        ret = srv_email_nwk_load_cloud_plugin(filename);
        if (ret > 0)
        {
            srv_email_cloud_upgrade_checked = MMI_TRUE;
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_UPGRADE_CLOUD_PLUGIN_FAIL, __LINE__);
        }
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_UPGRADE_CLOUD_PLUGIN_FAIL, __LINE__);
    }

    OslMfree(filename);
    return ret;
}


static void srv_email_nwk_upgrade_cloud_callback(
                srv_upgrage_originator_enum originator,
                srv_upgrade_result_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cntx_struct *cntx_p = srv_email_nwk_cntx_p;
    S32 major = 0;
    S32 minor = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (originator != SRV_UPGRADE_ORIGINATOR_CLOUD_EMAIL)
    {
        return;
    }

    switch (result->status)
    {
        case SRV_UPGRADE_STATUS_DOWNLOADED:
            minor = srv_email_nwk_update_cloud_plugin(result);
            if (minor < 0)
            {
                major = SRV_EMAIL_FS_ERROR;
            }
            break;

        case SRV_UPGRADE_STATUS_NO_UPGRADE:
        case SRV_UPGRADE_STATUS_CANCELLED:
        case SRV_UPGRADE_STATUS_FAILED:
        default:
            break;
    }

    while (cntx_p)
    {
        if (cntx_p->common.provider_id == result->provider &&
            cntx_p->nwk_state == SRV_EMAIL_NWK_STATE_CLOUD_UPGRADING)
        {
            if (major < 0)
            {
                srv_email_set_error_cause(&cntx_p->common.result, major, minor, NULL);
            }

            srv_email_nwk_fsm(cntx_p);
        }

        cntx_p = cntx_p->next;
    }
}


srv_email_result_enum srv_email_nwk_upgrade_cloud_plugin(U32 provider_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_upgrade_req_struct req;
    MMI_BOOL ret;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_email_cloud_upgrade_checked)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }

    for (i = 0; i < SRV_EMAIL_MAX_CLOUD_PROVIDER_NUM; i++)
    {
        if (srv_email_cloud_providers[i].provider_id == provider_id)
        {
            break;
        }
    }

    if (i == SRV_EMAIL_MAX_CLOUD_PROVIDER_NUM)
    {
        return SRV_EMAIL_RESULT_FAIL;
    }

    req.provider = provider_id;
    req.path = srv_email_cloud_providers[i].filename;
    req.url = NULL;
    req.next = NULL;

    ret = srv_upgrade_check_update(
            &req,
            1,
            SRV_UPGRADE_ORIGINATOR_CLOUD_EMAIL,
            srv_email_nwk_upgrade_cloud_callback);

    if (ret)
    {
        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }
    else
    {
        return SRV_EMAIL_RESULT_FAIL;
    }
}

#endif /* __MMI_CLOUD_VPP_UPGRADE__ */


MMI_BOOL srv_email_nwk_query_cloud_server_info(
            U32 provider_id,
            email_ps_protocol_type_enum protocol,
            srv_email_server_struct *server_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cloud_plugin_server_info_struct *info_p;
    U32 feature = CLOUD_PLUGIN_FEATURE_TYPE_EMAIL_REFRESH;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (protocol)
    {
        case EMAIL_PS_PRTOTOCOL_TYPE_SMTP:
            feature |= CLOUD_PLUGIN_PROTOCOL_SMTP;
            break;

        case EMAIL_PS_PRTOTOCOL_TYPE_IMAP4:
            feature |= CLOUD_PLUGIN_PROTOCOL_IMAP;
            break;

        default:
            return MMI_FALSE;
    }

    for (i = 0; i < SRV_EMAIL_MAX_CLOUD_SERVER_NUM; i++)
    {
        if (provider_id == srv_email_cloud_server[i].provider_id &&
            feature == srv_email_cloud_server[i].server_info.features)
        {
            info_p = &srv_email_cloud_server[i].server_info;

            mmi_asc_n_to_wcs(server_p->server_name, (CHAR*)info_p->server, SRV_EMAIL_MAX_SERVER_NAME_LEN);
            switch (info_p->sec_mode)
            {
                case CLOUD_PLUGIN_SEC_NONE:
                    server_p->port_num = info_p->port_num;
                    server_p->sec_mode = SRV_EMAIL_SEC_NONE;
                    break;

                case CLOUD_PLUGIN_SEC_SSL_TLS:
                    server_p->sec_port_num = info_p->port_num;
                    server_p->sec_mode = SRV_EMAIL_SEC_SSL_TLS;
                    break;

                case CLOUD_PLUGIN_SEC_STARTTLS:
                    server_p->port_num = info_p->port_num;
                    server_p->sec_mode = SRV_EMAIL_SEC_STARTTLS;
                    break;

                default:
                    MMI_ASSERT(0);
                    break;
            }

            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


MMI_BOOL srv_email_nwk_query_cloud_dtcnt_id(U32 provider_id, U32 *dtcnt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cloud_plugin_get_data_account_func dtcnt_func;
    VMUINT library;
    VMUINT32 vm_dtcnt_id;
    WCHAR *filename;
    U32 i;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_EMAIL_MAX_CLOUD_PROVIDER_NUM; i++)
    {
        if (srv_email_cloud_providers[i].provider_id == provider_id)
        {
            break;
        }
    }

    if (i == SRV_EMAIL_MAX_CLOUD_PROVIDER_NUM)
    {
        return MMI_FALSE;
    }

    filename = srv_email_cloud_providers[i].filename;

    library = vm_native_load_library((VMWSTR)filename);
    if (library)
    {
        dtcnt_func = (cloud_plugin_get_data_account_func)vm_native_get_symbol(library, "cloud_plugin_get_data_account");
        if (dtcnt_func)
        {
            vm_pmng_set_ctx(library);
            dtcnt_func((VMUINT32)provider_id, &vm_dtcnt_id);
            vm_pmng_reset_ctx();

            *dtcnt_id = (U32)vm_dtcnt_id;
            ret = MMI_TRUE;
        }

        vm_native_free_library(library);
    }

    return ret;
}

#endif /* __MMI_SSO__ */

#endif /* __MMI_EMAIL__ */

#ifdef __SMS_CLOUD_SUPPORT__

void srv_email_nwk_cloud_session_init(srv_email_nwk_cloud_session_struct *sess_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(sess_p, 0, sizeof(srv_email_nwk_cloud_session_struct));
}


void srv_email_nwk_cloud_session_free(srv_email_nwk_cloud_session_struct *sess_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_session_init(sess_p);
}


void srv_email_nwk_cloud_state_init(srv_email_nwk_cloud_state_struct *state_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(state_p, 0, sizeof(srv_email_nwk_cloud_state_struct));

    state_p->comp_handle = SRV_EMAIL_COMP_INVALID_HANDLE;
    state_p->msg_handle = EMAIL_MSG_INVALID_HANDLE;

    kal_wsprintf(
        state_p->rsp_filename,
        "%s%sMsg%08X.rsp",
        srv_email_get_root_path(),
        SRV_EMAIL_NWK_FILE_PATH,
        state_p);
}


void srv_email_nwk_cloud_state_free(srv_email_nwk_cloud_state_struct *state_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (state_p->comp_handle != SRV_EMAIL_COMP_INVALID_HANDLE)
    {
        srv_email_comp_destroy(state_p->comp_handle);
    }

    if (state_p->msg_env_p)
    {
        srv_email_imap4_free_envelope(&state_p->msg_env_p);
    }

    if (state_p->src_fd >= 0)
    {
        FS_Close(state_p->src_fd);
    }

    if (state_p->dst_fd >= 0)
    {
        FS_Close(state_p->dst_fd);
    }

    if (state_p->base64_p)
    {
        srv_email_mem_free(state_p->base64_p);
    }

    if (state_p->qprint_p)
    {
        srv_email_mem_free(state_p->qprint_p);
    }

    srv_email_fs_async_abort(
        &state_p->async_fs_job_id,
        (void**)&state_p->async_fs_work_buf,
        (void**)&state_p->async_fs_data_buf);

    FS_Delete(state_p->filename);
    FS_Delete(state_p->rsp_filename);

    srv_email_nwk_cloud_state_init(state_p);
}


void srv_email_nwk_cloud_cntx_init(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(cntx_p, 0, sizeof(srv_email_nwk_cloud_cntx_struct));
    cntx_p->common.result.result = MMI_TRUE;
}


void srv_email_nwk_cloud_cntx_free(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_session_free(&cntx_p->session);
    srv_email_nwk_cloud_state_free(&cntx_p->state);
}


MMI_BOOL srv_email_nwk_cloud_is_cntx_valid(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_curr_p = srv_email_nwk_cloud_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (cntx_curr_p)
    {
        if (cntx_curr_p == cntx_p)
        {
            return MMI_TRUE;
        }

        cntx_curr_p = cntx_curr_p->next;
    }

    return MMI_FALSE;
}


srv_email_nwk_cloud_cntx_struct *srv_email_nwk_cloud_create_cntx(EMAIL_ACCT_ID acct_id, S32 *errcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = srv_email_nwk_cloud_cntx_p;
    srv_email_nwk_cloud_cntx_struct *new_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_cntx_p = (srv_email_nwk_cloud_cntx_struct*)
        srv_email_mem_alloc(sizeof(srv_email_nwk_cloud_cntx_struct));
    if (!new_cntx_p)
    {
        *errcode = SRV_EMAIL_RESULT_NO_MEMORY;
        return NULL;
    }

    srv_email_nwk_cloud_cntx_init(new_cntx_p);

    new_cntx_p->common.acct_id = acct_id;

    if (!srv_email_nwk_cloud_cntx_p)
    {
        srv_email_nwk_cloud_cntx_p = new_cntx_p;
    }
    else
    {
        while (cntx_p->next)
        {
            cntx_p = cntx_p->next;
        }

        cntx_p->next = new_cntx_p;
    }

    return new_cntx_p;
}


void srv_email_nwk_cloud_destroy_cntx(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx = (srv_email_nwk_cloud_cntx_struct*)data;
    srv_email_nwk_cloud_cntx_struct *cntx_p = srv_email_nwk_cloud_cntx_p;
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx->common;
    U8 app_id = CBM_INVALID_APP_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAILSRV_EXT_ASSERT(
        (!comm_p->idle_cb_list_p && !comm_p->pending_cb_list_p && !comm_p->running_cb_p),
        (U32)comm_p->idle_cb_list_p,
        (U32)comm_p->pending_cb_list_p,
        (U32)comm_p->running_cb_p);

    if (comm_p->destroy_flag)
    {
        return;
    }

    srv_email_nwk_cloud_cntx_free(cntx);

    if (comm_p->ps_handle != EMAIL_PS_INVALID_HANDLE)
    {
        srv_email_ps_disconnect_req(comm_p->ps_handle);
        srv_email_ps_destroy_instance_req(comm_p->ps_handle);
    }

    app_id = cbm_get_app_id(comm_p->nwk_acct_id);

    srv_cbm_deregister_bearer_info(app_id);
    cbm_release_bearer(app_id);
    cbm_deregister_app_id(app_id);

    if (cntx_p == cntx)
    {
        srv_email_nwk_cloud_cntx_p = cntx_p->next;
    }
    else
    {
        while (cntx_p)
        {
            if (cntx_p->next == cntx)
            {
                cntx_p->next = cntx->next;
                break;
            }
            cntx_p = cntx_p->next;
        }
    }

    srv_email_mem_free(cntx);
}


MMI_BOOL srv_email_nwk_cloud_is_cb_empty(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (comm_p->running_cb_p)
    {
        return MMI_FALSE;
    }

    if (comm_p->pending_cb_list_p)
    {
        return MMI_FALSE;
    }

    if (comm_p->idle_cb_list_p)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


MMI_BOOL srv_email_nwk_cloud_is_pending_cb_empty(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cntx_p->common.pending_cb_list_p ? MMI_FALSE : MMI_TRUE;
}


MMI_BOOL srv_email_nwk_cloud_is_cb_full(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cb_struct *cb_p = NULL;
    S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (comm_p->running_cb_p)
    {
        count++;
    }

    cb_p = comm_p->pending_cb_list_p;
    while (cb_p)
    {
        count++;
        cb_p = cb_p->next;
    }

    cb_p = comm_p->idle_cb_list_p;
    while (cb_p)
    {
        count++;
        cb_p = cb_p->next;
    }

    if (count < SRV_EMAIL_MAX_CB_NUM)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


void srv_email_nwk_cloud_append_cb_to_idle_list(
        srv_email_nwk_cloud_cntx_struct *cntx_p,
        srv_email_nwk_cb_struct *cb_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cb_struct *cb_curr_p = comm_p->idle_cb_list_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!comm_p->idle_cb_list_p)
    {
        comm_p->idle_cb_list_p = cb_p;
    }
    else
    {
        while (cb_curr_p->next)
        {
            cb_curr_p = cb_curr_p->next;
        }

        cb_curr_p->next = cb_p;
    }

    cb_p->next = NULL;
}


void srv_email_nwk_cloud_move_cb_to_idle(
        srv_email_nwk_cloud_cntx_struct *cntx_p,
        srv_email_nwk_cb_struct *cb_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cb_struct *cb_prev_p = comm_p->pending_cb_list_p;
    srv_email_nwk_cb_struct *cb_curr_p = comm_p->idle_cb_list_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (cb_curr_p)
    {
        if (cb_curr_p == cb_p)
        {
            return;
        }
        cb_curr_p = cb_curr_p->next;
    }

    cb_curr_p = comm_p->pending_cb_list_p;

    if (cb_curr_p == cb_p)
    {
        comm_p->pending_cb_list_p = cb_curr_p->next;
    }
    else
    {
        while (cb_curr_p)
        {
            if (cb_curr_p == cb_p)
            {
                break;
            }
            cb_prev_p = cb_curr_p;
            cb_curr_p = cb_curr_p->next;
        }

        cb_prev_p->next = cb_curr_p->next;
    }

    cb_curr_p = comm_p->idle_cb_list_p;

    if (!cb_curr_p)
    {
        comm_p->idle_cb_list_p = cb_p;
    }
    else
    {
        while (cb_curr_p->next)
        {
            cb_curr_p = cb_curr_p->next;
        }

        cb_curr_p->next = cb_p;
    }

    cb_p->next = NULL;
}


void srv_email_nwk_cloud_move_cb_to_pending(
        srv_email_nwk_cloud_cntx_struct *cntx_p,
        srv_email_nwk_cb_struct *cb_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cb_struct *cb_prev_p = comm_p->idle_cb_list_p;
    srv_email_nwk_cb_struct *cb_curr_p = comm_p->idle_cb_list_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cb_curr_p == cb_p)
    {
        comm_p->idle_cb_list_p = cb_curr_p->next;
    }
    else
    {
        while (cb_curr_p)
        {
            if (cb_curr_p == cb_p)
            {
                break;
            }
            cb_prev_p = cb_curr_p;
            cb_curr_p = cb_curr_p->next;
        }

        cb_prev_p->next = cb_curr_p->next;
    }

    cb_curr_p = comm_p->pending_cb_list_p;

    if (!cb_curr_p)
    {
        comm_p->pending_cb_list_p = cb_p;
    }
    else
    {
        while (cb_curr_p->next)
        {
            cb_curr_p = cb_curr_p->next;
        }

        cb_curr_p->next = cb_p;
    }

    cb_p->next = NULL;
}


srv_email_nwk_cloud_cntx_struct *srv_email_nwk_cloud_get_cntx_by_cb(srv_email_nwk_cb_struct *cb_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = srv_email_nwk_cloud_cntx_p;
    srv_email_nwk_cb_struct *cb_curr_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (cntx_p)
    {
        /* Check the running control block */
        cb_curr_p = cntx_p->common.running_cb_p;
        if (cb_curr_p && cb_curr_p == cb_p)
        {
            return cntx_p;
        }

        /* Check the pending control block list */
        cb_curr_p = cntx_p->common.pending_cb_list_p;
        while (cb_curr_p)
        {
            if (cb_curr_p == cb_p)
            {
                return cntx_p;
            }

            cb_curr_p = cb_curr_p->next;
        }

        /* Check the idle control block list */
        cb_curr_p = cntx_p->common.idle_cb_list_p;
        while (cb_curr_p)
        {
            if (cb_curr_p == cb_p)
            {
                return cntx_p;
            }

            cb_curr_p = cb_curr_p->next;
        }

        cntx_p = cntx_p->next;
    }

    return NULL;
}


srv_email_nwk_cb_struct *srv_email_nwk_cloud_get_running_cb(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cntx_p->common.running_cb_p;
}


void srv_email_nwk_cloud_abort_cb(
        srv_email_nwk_cloud_cntx_struct *cntx_p,
        srv_email_nwk_cb_struct *cb_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cb_struct *cb_run_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cb_run_p = srv_email_nwk_cloud_get_running_cb(cntx_p);
    if (cb_run_p != cb_p)
    {
        cb_p->action = SRV_EMAIL_NWK_NONE;
        if (cb_p->action_data)
        {
            srv_email_mem_free(cb_p->action_data);
        }
        cb_p->action_data = NULL;

        srv_email_nwk_cloud_move_cb_to_idle(cntx_p, cb_p);
    }
    else
    {
        srv_email_nwk_cloud_fsm_abort(cntx_p);
    }
}


void srv_email_nwk_cloud_remove_cb(
        srv_email_nwk_cloud_cntx_struct *cntx_p,
        srv_email_nwk_cb_struct *cb_p,
        MMI_BOOL *cntx_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;
    srv_email_nwk_cb_struct *cb_curr_p = NULL;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_abort_cb(cntx_p, cb_p);

    cb_curr_p = comm_p->idle_cb_list_p;
    if (cb_curr_p == cb_p)
    {
        comm_p->idle_cb_list_p = cb_curr_p->next;
    }
    else
    {
        while (cb_curr_p->next)
        {
            if (cb_curr_p->next == cb_p)
            {
                cb_curr_p->next = cb_p->next;
                break;
            }
            cb_curr_p = cb_curr_p->next;
        }
    }

    if (cb_p->action_data)
    {
        srv_email_mem_free(cb_p->action_data);
    }
    srv_email_mem_free(cb_p);

    if (cntx_valid)
    {
        ret = srv_email_nwk_cloud_is_cb_empty(cntx_p);
        *cntx_valid = ret ? MMI_FALSE : MMI_TRUE;
    }
}


void srv_email_nwk_cloud_start_job(
        srv_email_schdl_funcptr_type callback,
        srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!comm_p->schdl_flag)
    {
        comm_p->req_id = srv_email_schdl_start_job(callback, cntx_p);
        cntx_p->common.schdl_flag = MMI_TRUE;
    }
}


void srv_email_nwk_cloud_stop_job(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (comm_p->schdl_flag)
    {
        srv_email_schdl_stop_job(comm_p->req_id);
        cntx_p->common.schdl_flag = MMI_FALSE;
    }
}


srv_email_nwk_cloud_cntx_struct *srv_email_nwk_cloud_get_cntx_by_id(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = srv_email_nwk_cloud_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (cntx_p)
    {
        if (cntx_p->common.acct_id == acct_id)
        {
            break;
        }

        cntx_p = cntx_p->next;
    }

    return cntx_p;
}


srv_email_nwk_cloud_cntx_struct *srv_email_nwk_cloud_get_cntx_by_ps_handle(EMAIL_PS_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_cntx_struct *cntx_p = srv_email_nwk_cloud_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (cntx_p)
    {
        if (cntx_p->common.ps_handle == handle)
        {
            break;
        }

        cntx_p = cntx_p->next;
    }

    return cntx_p;
}


srv_email_result_enum srv_email_nwk_cloud_run_cntx(srv_email_nwk_cloud_cntx_struct *cntx_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_nwk_cloud_comm_cntx_struct *comm_p = &cntx_p->common;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (comm_p->running_cb_p)
    {
        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }

    srv_email_nwk_cloud_stop_job(cntx_p);

    EMAILSRV_ASSERT(comm_p->pending_cb_list_p);

    comm_p->running_cb_p = comm_p->pending_cb_list_p;
    comm_p->pending_cb_list_p = comm_p->pending_cb_list_p->next;
    comm_p->running_cb_p->next = NULL;

    srv_email_nwk_cloud_start_job(srv_email_nwk_cloud_fsm_schdl, cntx_p);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}

#endif /* __SMS_CLOUD_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  srv_email_nwk_init
 * DESCRIPTION
 *  This function is used to initialize the Network module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_email_result_enum srv_email_nwk_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR fn[SRV_EMAIL_NWK_MAX_FILE_NAME_LEN + 1];
    U32 len = 0;
    S32 res;
#ifdef __MMI_EMAIL__
    S32 notify_id = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Create the Network working folder and clear this folder */
    kal_wsprintf(fn, "%s%s", srv_email_get_root_path(), SRV_EMAIL_NWK_FILE_PATH);
    len = mmi_wcslen(fn);
    fn[len] = 0;
    
    res = srv_email_util_dir_exist(fn);
    if (res < 0)
    {
        srv_email_init_errno_set(res);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    if (res)
    {
        FS_XDelete(fn, FS_FILE_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    }
    else
    {
        if ((res = FS_CreateDir(fn)) != FS_NO_ERROR)
        {
            srv_email_init_errno_set(res);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
    }

#ifdef __MMI_EMAIL__
    srv_email_om_set_notify(SRV_EMAIL_OM_NOTIFY_OBJ_MSG, srv_email_nwk_om_notify_callback, &notify_id);
#ifdef __MMI_SSO__
    srv_email_nwk_read_cloud_plugin_info();
#endif
#endif /* __MMI_EMAIL__ */

    if (srv_email_nwk_inited)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }

    srv_email_nwk_p = &srv_email_nwk;
    memset(srv_email_nwk_p, 0, sizeof(srv_email_nwk_struct));

    /* Register the PS message handler */
    SetProtocolEventHandler(srv_email_ps_create_instance_rsp, MSG_ID_EMAIL_PS_CREATE_INSTANCE_RSP);
    SetProtocolEventHandler(srv_email_ps_destroy_instance_rsp, MSG_ID_EMAIL_PS_DESTROY_INSTANCE_RSP);
    SetProtocolEventHandler(srv_email_ps_connect_rsp, MSG_ID_EMAIL_PS_CONN_RSP);
    SetProtocolEventHandler(srv_email_ps_disconnect_rsp, MSG_ID_EMAIL_PS_DISCONN_RSP);
    SetProtocolEventHandler(srv_email_ps_auth_rsp, MSG_ID_EMAIL_PS_AUTH_RSP);
    SetProtocolEventHandler(srv_email_ps_open_folder_rsp, MSG_ID_EMAIL_PS_FLD_OPEN_RSP);
    SetProtocolEventHandler(srv_email_ps_list_uid_rsp, MSG_ID_EMAIL_PS_MSG_UID_LIST_RSP);
    SetProtocolEventHandler(srv_email_ps_fetch_mail_rsp, MSG_ID_EMAIL_PS_MSG_FETCH_RSP);
    SetProtocolEventHandler(srv_email_ps_abort_rsp, MSG_ID_EMAIL_PS_ABORT_RSP);
    SetProtocolEventHandler(srv_email_ps_disconnect_ind, MSG_ID_EMAIL_PS_DISCONN_IND);
    SetProtocolEventHandler(srv_email_ps_fetch_mail_ind, MSG_ID_EMAIL_PS_MSG_FETCH_IND);
    SetProtocolEventHandler(srv_email_ps_imap4_push_ind, MSG_ID_EMAIL_PS_IMAP_PUSH_IND);
#ifdef __MMI_EMAIL__
    SetProtocolEventHandler(srv_email_ps_send_mail_rsp, MSG_ID_EMAIL_PS_MSG_SEND_RSP);
    SetProtocolEventHandler(srv_email_ps_list_size_rsp, MSG_ID_EMAIL_PS_MSG_SIZE_LIST_RSP);
    SetProtocolEventHandler(srv_email_ps_delete_mail_rsp, MSG_ID_EMAIL_PS_MSG_DELETE_RSP);
    SetProtocolEventHandler(srv_email_ps_list_folder_rsp, MSG_ID_EMAIL_PS_FLD_LIST_RSP);
    SetProtocolEventHandler(srv_email_ps_get_flag_rsp, MSG_ID_EMAIL_PS_MSG_FLAGS_GET_RSP);
    SetProtocolEventHandler(srv_email_ps_set_flag_rsp, MSG_ID_EMAIL_PS_MSG_FLAGS_SET_RSP);
    SetProtocolEventHandler(srv_email_ps_expunge_mail_rsp, MSG_ID_EMAIL_PS_MSG_EXPUNGE_RSP);
    SetProtocolEventHandler(srv_email_ps_close_folder_rsp, MSG_ID_EMAIL_PS_FLD_CLOSE_RSP);
    SetProtocolEventHandler(srv_email_ps_send_mail_ind, MSG_ID_EMAIL_PS_MSG_SEND_IND);
#endif /* __MMI_EMAIL__ */
#ifdef __SMS_CLOUD_SUPPORT__
    SetProtocolEventHandler(srv_email_ps_create_folder_rsp, MSG_ID_EMAIL_PS_FLD_CREATE_RSP);
    SetProtocolEventHandler(srv_email_ps_append_mail_rsp, MSG_ID_EMAIL_PS_MSG_APPEND_RSP);
#endif /* __SMS_CLOUD_SUPPORT__ */

#ifdef __SRV_EMAIL_NWK_UT__
    mmi_frm_set_protocol_event_handler(
        MSG_ID_TST_INJECT_STRING,
        (PsIntFuncPtr)srv_email_nwk_tst_inject_str,
        MMI_TRUE);
#endif

    srv_email_nwk_inited = MMI_TRUE;

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************/
/* Remove from this file */
void srv_email_set_error_cause(srv_email_result_struct *result, S32 major, S32 minor, CHAR *err_string)
{
    result->result = MMI_FALSE;
    result->major = major;
    result->minor = minor;
    // TODO: copy the error string
}

void srv_email_get_acct_error(S32 ret, S32 *major, S32 *minor)
{
    if (ret == SRV_EMAIL_RESULT_FS_ERROR)
    {
        *major = SRV_EMAIL_FS_ERROR;
        *minor = srv_email_errno_get();
    }
    else
    {
        *major = SRV_EMAIL_MAIL_ERROR;
        *minor = ret;
    }
}

void srv_email_get_msg_error(S32 ret, S32 *major, S32 *minor)
{
    if (ret == SRV_EMAIL_RESULT_FS_ERROR)
    {
        *major = SRV_EMAIL_FS_ERROR;
        *minor = srv_email_errno_get();
    }
    else
    {
        *major = SRV_EMAIL_MAIL_ERROR;
        *minor = ret;
    }
}

EMAIL_SRV_HANDLE srv_email_get_int_srv_handle(void)
{
    return 1;
}


void srv_email_compute_md5_digest(const CHAR *input, S32 input_len, U8 *digest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static STCHE che_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    che_init(&che_cntx, CHE_MD5);
    che_process(
        &che_cntx,
        CHE_MD5,
        CHE_MODE_NULL,
        CHE_HASH,
        (U8*)input,
        digest,
        input_len,
        KAL_TRUE);
    che_deinit(&che_cntx);
}


void srv_email_add_fs_async_job(fs_job_id job_id, void *work_buf_p, void *data_buf_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fs_async_struct *job_p = srv_email_fs_async_job_list_p;
    srv_email_fs_async_struct *new_job_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_job_p = (srv_email_fs_async_struct*)
        srv_email_mem_alloc(sizeof(srv_email_fs_async_struct));
    MMI_ASSERT(new_job_p);

    new_job_p->job_id = job_id;
    new_job_p->work_buf = work_buf_p;
    new_job_p->data_buf = data_buf_p;
    new_job_p->next = NULL;

    if (!srv_email_fs_async_job_list_p)
    {
        srv_email_fs_async_job_list_p = new_job_p;
    }
    else
    {
        while (job_p->next)
        {
            job_p = job_p->next;
        }

        job_p->next = new_job_p;
    }
}


MMI_BOOL srv_email_delete_fs_async_job(fs_job_id job_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_fs_async_struct *job_p = srv_email_fs_async_job_list_p;
    srv_email_fs_async_struct *prev_p = srv_email_fs_async_job_list_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (job_p)
    {
        if (job_p->job_id == job_id)
        {
            srv_email_fs_async_job_list_p = job_p->next;
        }
        else
        {
            while (job_p)
            {
                if (job_p->job_id == job_id)
                {
                    prev_p->next = job_p->next;
                    break;
                }
                prev_p = job_p;
                job_p = job_p->next;
            }
        }
    }

    if (job_p)
    {
        if (job_p->data_buf)
        {
            srv_email_mem_free(job_p->data_buf);
        }

        if (job_p->work_buf)
        {
            srv_email_mem_free(job_p->work_buf);
        }

        srv_email_mem_free(job_p);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


void srv_email_fs_async_abort(fs_job_id *job_id_p, void **work_buf_p, void **data_buf_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!job_id_p || !work_buf_p || !data_buf_p)
    {
        return;
    }

    if (*job_id_p > 0)
    {
        srv_email_add_fs_async_job(*job_id_p, *work_buf_p, *data_buf_p);

        fs_async_abort(*job_id_p);
        *job_id_p = -1;
        *work_buf_p = NULL;
        *data_buf_p = NULL;
    }
    else
    {
        if (*work_buf_p)
        {
            srv_email_mem_free(*work_buf_p);
            *work_buf_p = NULL;
        }

        if (*data_buf_p)
        {
            srv_email_mem_free(*data_buf_p);
            *data_buf_p = NULL;
        }
    }
}


static MMI_BOOL srv_email_nwk_make_yahoo_conn_req_file(
                    U32 provider_id,
                    const CHAR *from_addr_p,
                    U32 protocol,
                    srv_email_server_struct *server_p,
                    const WCHAR *filename,
                    MMI_BOOL *is_file_needed,
                    S32 *errcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_yahoo_info_struct *info_p = &srv_email_yahoo;
    FS_HANDLE fd = -1;
    S32 ret = -1;
    U32 len = 0;
    U32 wbyte = 0;
    CHAR *addr_p = NULL;
    U8 digest[SRV_EMAIL_MD5_DIGEST_LEN];
    CHAR aguid[SRV_EMAIL_MD5_DIGEST_LEN * 2];
    S32 i = 0;
    S32 j = 0;
    S32 cnt = 0;
    U8 ch = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SSO__) || defined(__SMS_CLOUD_SUPPORT__)
    if (provider_id != 0)
    {
        if (provider_id != PROVIDER_YAHOO)
        {
            return MMI_FALSE;
        }
    }
    else
#endif /* defined(__MMI_SSO__) || defined(__SMS_CLOUD_SUPPORT__) */
    {
        addr_p = strchr(from_addr_p, '@');
        if (app_strnicmp(addr_p, info_p->email_addr, strlen(info_p->email_addr)))
        {
            return MMI_FALSE;
        }
    }

    *is_file_needed = MMI_FALSE;
    *errcode = 0;

    if (protocol == EMAIL_PS_PRTOTOCOL_TYPE_POP3)
    {
        return MMI_TRUE;
    }
    else if (protocol == EMAIL_PS_PRTOTOCOL_TYPE_SMTP)
    {
    #ifndef __SSL_SUPPORT__
        if (info_p->out_sec_mode == SRV_EMAIL_SEC_SSL_TLS ||
            info_p->out_sec_mode == SRV_EMAIL_SEC_STARTTLS)
        {
            return MMI_TRUE;
        }
    #endif /* __SSL_SUPPORT__ */

        if (server_p)
        {
            if (strlen(info_p->out_server_addr))
            {
                mmi_asc_to_wcs(server_p->server_name, info_p->out_server_addr);
            }
            if (info_p->out_sec_mode < SRV_EMAIL_SEC_TOTAL)
            {
                server_p->sec_mode = info_p->out_sec_mode;
            }
            if (info_p->out_server_port)
            {
                if (server_p->sec_mode == SRV_EMAIL_SEC_SSL_TLS)
                {
                    server_p->sec_port_num = info_p->out_server_port;
                }
                else
                {
                    server_p->port_num = info_p->out_server_port;
                }
            }
        }
        return MMI_TRUE;
    }
    else
    {
    #ifndef __SSL_SUPPORT__
        if (info_p->in_sec_mode == SRV_EMAIL_SEC_SSL_TLS ||
            info_p->in_sec_mode == SRV_EMAIL_SEC_STARTTLS)
        {
            return MMI_TRUE;
        }
    #endif /* __SSL_SUPPORT__ */
    }

    *is_file_needed = MMI_TRUE;

    fd = FS_Open(filename, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (fd < 0)
    {
        ret = fd;
        goto ERROR_HANDLE;
    }

    /* Write the Name field */
    len = strlen(info_p->name);
    if (len)
    {
        /* Write the Name field name */
        len = strlen(SRV_EMAIL_YAHOO_NAME_NAME);
        ret = FS_Write(fd, &len, 4, &wbyte);
        if (ret < 0 || wbyte != 4)
        {
            goto ERROR_HANDLE;
        }
        ret = FS_Write(fd, SRV_EMAIL_YAHOO_NAME_NAME, len, &wbyte);
        if (ret < 0 || wbyte != len)
        {
            goto ERROR_HANDLE;
        }
        /* Write the Name field value */
        len = strlen(info_p->name);
        ret = FS_Write(fd, &len, 4, &wbyte);
        if (ret < 0 || wbyte != 4)
        {
            goto ERROR_HANDLE;
        }
        ret = FS_Write(fd, info_p->name, len, &wbyte);
        if (ret < 0 || wbyte != len)
        {
            goto ERROR_HANDLE;
        }
    }

    /* Write the OS field */
    len = strlen(info_p->os);
    if (len)
    {
        /* Write the OS field name */
        len = strlen(SRV_EMAIL_YAHOO_OS_NAME);
        ret = FS_Write(fd, &len, 4, &wbyte);
        if (ret < 0 || wbyte != 4)
        {
            goto ERROR_HANDLE;
        }
        ret = FS_Write(fd, SRV_EMAIL_YAHOO_OS_NAME, len, &wbyte);
        if (ret < 0 || wbyte != len)
        {
            goto ERROR_HANDLE;
        }
        /* Write the OS field value */
        len = strlen(info_p->os);
        ret = FS_Write(fd, &len, 4, &wbyte);
        if (ret < 0 || wbyte != 4)
        {
            goto ERROR_HANDLE;
        }
        ret = FS_Write(fd, info_p->os, len, &wbyte);
        if (ret < 0 || wbyte != len)
        {
            goto ERROR_HANDLE;
        }
    }

    /* Write the OS Version field */
    len = strlen(info_p->os_version);
    if (len)
    {
        /* Write the OS Version field name */
        len = strlen(SRV_EMAIL_YAHOO_OS_VERSION_NAME);
        ret = FS_Write(fd, &len, 4, &wbyte);
        if (ret < 0 || wbyte != 4)
        {
            goto ERROR_HANDLE;
        }
        ret = FS_Write(fd, SRV_EMAIL_YAHOO_OS_VERSION_NAME, len, &wbyte);
        if (ret < 0 || wbyte != len)
        {
            goto ERROR_HANDLE;
        }
        /* Write the OS Version field value */
        len = strlen(info_p->os_version);
        ret = FS_Write(fd, &len, 4, &wbyte);
        if (ret < 0 || wbyte != 4)
        {
            goto ERROR_HANDLE;
        }
        ret = FS_Write(fd, info_p->os_version, len, &wbyte);
        if (ret < 0 || wbyte != len)
        {
            goto ERROR_HANDLE;
        }
    }

    /* Write the Vendor field */
    len = strlen(info_p->vendor);
    if (len)
    {
        /* Write the Vendor field name */
        len = strlen(SRV_EMAIL_YAHOO_VENDOR_NAME);
        ret = FS_Write(fd, &len, 4, &wbyte);
        if (ret < 0 || wbyte != 4)
        {
            goto ERROR_HANDLE;
        }
        ret = FS_Write(fd, SRV_EMAIL_YAHOO_VENDOR_NAME, len, &wbyte);
        if (ret < 0 || wbyte != len)
        {
            goto ERROR_HANDLE;
        }
        /* Write the Vendor field value */
        len = strlen(info_p->vendor);
        ret = FS_Write(fd, &len, 4, &wbyte);
        if (ret < 0 || wbyte != 4)
        {
            goto ERROR_HANDLE;
        }
        ret = FS_Write(fd, info_p->vendor, len, &wbyte);
        if (ret < 0 || wbyte != len)
        {
            goto ERROR_HANDLE;
        }
    }

    /* Write the Device field */
    len = strlen(info_p->device);
    if (len)
    {
        /* Write the Device field name */
        len = strlen(SRV_EMAIL_YAHOO_DEVICE_NAME);
        ret = FS_Write(fd, &len, 4, &wbyte);
        if (ret < 0 || wbyte != 4)
        {
            goto ERROR_HANDLE;
        }
        ret = FS_Write(fd, SRV_EMAIL_YAHOO_DEVICE_NAME, len, &wbyte);
        if (ret < 0 || wbyte != len)
        {
            goto ERROR_HANDLE;
        }
        /* Write the Device field value */
        len = strlen(info_p->device);
        ret = FS_Write(fd, &len, 4, &wbyte);
        if (ret < 0 || wbyte != 4)
        {
            goto ERROR_HANDLE;
        }
        ret = FS_Write(fd, info_p->device, len, &wbyte);
        if (ret < 0 || wbyte != len)
        {
            goto ERROR_HANDLE;
        }
    }

    /* Write the Mobile Net Operator field */
    len = strlen(info_p->operator);
    if (len)
    {
        /* Write the Mobile Net Operator field name */
        len = strlen(SRV_EMAIL_YAHOO_OPERATOR_NAME);
        ret = FS_Write(fd, &len, 4, &wbyte);
        if (ret < 0 || wbyte != 4)
        {
            goto ERROR_HANDLE;
        }
        ret = FS_Write(fd, SRV_EMAIL_YAHOO_OPERATOR_NAME, len, &wbyte);
        if (ret < 0 || wbyte != len)
        {
            goto ERROR_HANDLE;
        }
        /* Write the Mobile Net Operator field value */
        len = strlen(info_p->operator);
        ret = FS_Write(fd, &len, 4, &wbyte);
        if (ret < 0 || wbyte != 4)
        {
            goto ERROR_HANDLE;
        }
        ret = FS_Write(fd, info_p->operator, len, &wbyte);
        if (ret < 0 || wbyte != len)
        {
            goto ERROR_HANDLE;
        }
    }
    else
    {
        // TODO: Get the operator name here
    }

    /* Write the AGUID field */
    srv_email_compute_md5_digest(from_addr_p, strlen(from_addr_p), digest);
    for (i = 0; i < SRV_EMAIL_MD5_DIGEST_LEN; i++)
    {
        ch = digest[i] >> 4;
        for (j = 0; j < 2; j++)
        {
            if (ch <= 9)
            {
                aguid[cnt++] = ch + '0';
            }
            else
            {
                aguid[cnt++] = ch + 'A' - 10;
            }
            ch = digest[i] & 0x0F;
        }
    }
    /* Write the AGUID field name */
    len = strlen(SRV_EMAIL_YAHOO_AGUID_NAME);
    ret = FS_Write(fd, &len, 4, &wbyte);
    if (ret < 0 || wbyte != 4)
    {
        goto ERROR_HANDLE;
    }
    ret = FS_Write(fd, SRV_EMAIL_YAHOO_AGUID_NAME, len, &wbyte);
    if (ret < 0 || wbyte != len)
    {
        goto ERROR_HANDLE;
    }
    /* Write the AGUID field value */
    len = SRV_EMAIL_MD5_DIGEST_LEN * 2;
    ret = FS_Write(fd, &len, 4, &wbyte);
    if (ret < 0 || wbyte != 4)
    {
        goto ERROR_HANDLE;
    }
    ret = FS_Write(fd, aguid, len, &wbyte);
    if (ret < 0 || wbyte != len)
    {
        goto ERROR_HANDLE;
    }

    /* Write the ACLID field */
    len = strlen(info_p->aclid);
    if (len)
    {
        /* Write the ACLID field name */
        len = strlen(SRV_EMAIL_YAHOO_ACLID_NAME);
        ret = FS_Write(fd, &len, 4, &wbyte);
        if (ret < 0 || wbyte != 4)
        {
            goto ERROR_HANDLE;
        }
        ret = FS_Write(fd, SRV_EMAIL_YAHOO_ACLID_NAME, len, &wbyte);
        if (ret < 0 || wbyte != len)
        {
            goto ERROR_HANDLE;
        }
        /* Write the ACLID field value */
        len = strlen(info_p->aclid);
        ret = FS_Write(fd, &len, 4, &wbyte);
        if (ret < 0 || wbyte != 4)
        {
            goto ERROR_HANDLE;
        }
        ret = FS_Write(fd, info_p->aclid, len, &wbyte);
        if (ret < 0 || wbyte != len)
        {
            goto ERROR_HANDLE;
        }
    }

    FS_Close(fd);

    if (server_p)
    {
        if (strlen(info_p->in_server_addr))
        {
            mmi_asc_to_wcs(server_p->server_name, info_p->in_server_addr);
        }
        if (info_p->in_sec_mode < SRV_EMAIL_SEC_TOTAL)
        {
            server_p->sec_mode = info_p->in_sec_mode;
        }
        if (info_p->in_server_port)
        {
            if (server_p->sec_mode == SRV_EMAIL_SEC_SSL_TLS)
            {
                server_p->sec_port_num = info_p->in_server_port;
            }
            else
            {
                server_p->port_num = info_p->in_server_port;
            }
        }
    }

    return MMI_TRUE;

ERROR_HANDLE:
    if (fd >= 0)
    {
        FS_Close(fd);
        FS_Delete(filename);
    }
    *errcode = ret;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 srv_email_nwk_make_conn_req_file
 * DESCRIPTION
 *  This function is used to check if the connect request file is needed or not.
 * PARAMETERS
 *  comm_p                  [IN]        The common context pointer
 *  filename                [IN]        The request filename
 *  errcode                 [OUT]       Used to return the file operation error
 * RETURNS
 *  MMI_TRUE/MMI_FALSE.
 *****************************************************************************/
MMI_BOOL srv_email_nwk_make_conn_req_file(
            U32 provider_id,
            const CHAR *from_addr_p,
            U32 protocol,
            srv_email_server_struct *server_p,
            const WCHAR *filename,
            S32 *errcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *addr_p = NULL;
    MMI_BOOL is_matched = MMI_FALSE;
    MMI_BOOL is_file_needed = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (provider_id == 0)
    {
        addr_p = strchr(from_addr_p, '@');
        if (!addr_p)
        {
            return MMI_FALSE;
        }
    }

    is_matched = srv_email_nwk_make_yahoo_conn_req_file(
                    provider_id,
                    from_addr_p,
                    protocol,
                    server_p,
                    filename,
                    &is_file_needed,
                    errcode);
    if (is_matched)
    {
        return is_file_needed;
    }

    return MMI_FALSE;
}


mmi_ret srv_email_nwk_evt_proc_hdlr(mmi_event_struct *evt)
{
#if defined(__MMI_EMAIL__) && defined(__MMI_SSO__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool card_used;
    U8 email_drive;
    U8 cloud_drive;
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_drive = (U8)srv_email_get_drive();
    card_used = custom_cloud_using_card_memory();
    cloud_drive = card_used ? SRV_FMGR_CARD_DRV : SRV_FMGR_PUBLIC_DRV;

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        {
            srv_fmgr_notification_dev_plug_event_struct *plug_in_p =
                (srv_fmgr_notification_dev_plug_event_struct*)evt;

            MMI_TRACE(
                MMI_INET_TRC_G9_EMAIL,
                SRV_EMAIL_INFO_NWK_DEV_PLUG_IN,
                plug_in_p->drv_letters[0],
                email_drive,
                cloud_drive,
                card_used);

            if (card_used && cloud_drive != email_drive)
            {
                for (i = 0; i < plug_in_p->count; i++)
                {
                    if (plug_in_p->drv_letters[i] == cloud_drive)
                    {
                        break;
                    }
                }
                if (i < plug_in_p->count)
                {
                    srv_email_nwk_read_cloud_plugin_info();
                }
            }
            break;
        }

        default:
            break;
    }
#endif /* defined(__MMI_EMAIL__) && defined(__MMI_SSO__) */

    return MMI_RET_OK;
}


#endif /* defined(__MMI_EMAIL__) || defined(__SMS_CLOUD_SUPPORT__) */

