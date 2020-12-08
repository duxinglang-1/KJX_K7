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
 *  PhbpbapcSrv.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  PBAPC
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PHB_PBAPC_SRV_H__
#define __PHB_PBAPC_SRV_H__

#include "MMI_features.h"

#if defined(__BT_PBAP_CLIENT__)

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
/* KAL Layer */
#include "kal_general_types.h"

/* MMI Layer */
#include "MMIDataType.h"
#include "PhbpbapSrvGprot.h"
#include "MMI_common_app_trc.h"

#include "MMI_trc_Int.h"
#include "string.h"
#include "kal_trace.h"
#include "MMI_include.h"

#define SRV_PHB_PBAP_TRACE_GROUP     MMI_COMMON_TRC_G4_PHB

static const WCHAR *g_srv_phb_pbapc_path[] =
{
    L"",                    /* SRV_PHB_PBAP_STORAGE_NO */

    L"telecom/pb",          /* SRV_PHB_PBAP_STORAGE_PHONE_PB */
    L"telecom/ich",         /* SRV_PHB_PBAP_STORAGE_PHONE_ICH */
    L"telecom/och",         /* SRV_PHB_PBAP_STORAGE_PHONE_OCH */
    L"telecom/mch",         /* SRV_PHB_PBAP_STORAGE_PHONE_MCH */
    L"telecom/cch",         /* SRV_PHB_PBAP_STORAGE_PHONE_CCH */

    L"SIM1/telecom/pb",     /* SRV_PHB_PBAP_STORAGE_SIM1_PB */
    L"SIM1/telecom/ich",    /* SRV_PHB_PBAP_STORAGE_SIM1_ICH */    
    L"SIM1/telecom/och",    /* SRV_PHB_PBAP_STORAGE_SIM1_OCH */
    L"SIM1/telecom/mch",    /* SRV_PHB_PBAP_STORAGE_SIM1_MCH */
    L"SIM1/telecom/ccm",    /* SRV_PHB_PBAP_STORAGE_SIM1_CCH */

    L"End"                  /* SRV_PHB_PBAP_STORAGE_TOTAL */
};

static const WCHAR *srv_phb_pbapc_folder_name[] =
{
    L"",            /* SRV_PHB_PBAP_STORAGE_NO */

    L"pb",          /* SRV_PHB_PBAP_STORAGE_PHONE_PB */
    L"ich",         /* SRV_PHB_PBAP_STORAGE_PHONE_ICH */
    L"och",         /* SRV_PHB_PBAP_STORAGE_PHONE_OCH */
    L"mch",         /* SRV_PHB_PBAP_STORAGE_PHONE_MCH */
    L"cch",         /* SRV_PHB_PBAP_STORAGE_PHONE_CCH */

    L"pb",          /* SRV_PHB_PBAP_STORAGE_SIM1_PB */
    L"ich",         /* SRV_PHB_PBAP_STORAGE_SIM1_ICH */    
    L"och",         /* SRV_PHB_PBAP_STORAGE_SIM1_OCH */
    L"mch",         /* SRV_PHB_PBAP_STORAGE_SIM1_MCH */
    L"ccm",         /* SRV_PHB_PBAP_STORAGE_SIM1_CCH */

    L"End"          /* SRV_PHB_PBAP_STORAGE_TOTAL */
};


#define SRV_PHB_PBAPC_MAX_HANDLE_NUM            (1)

#define SRV_PHB_PBAPC_MAX_OBJ_NAME_LEN          (32)

#define SRV_PHB_PBAPC_OBJ_NAME_SUFFIX           (L".vcf")

typedef struct
{
    void *para;
    S32 list_count;
} srv_phb_pbapc_handle_ex_strcut;

typedef struct
{
    U8 used_flag; /* 0: can be used, 1: not */
    S32 srv_hd;
    MMI_BOOL is_busy;
    srv_phb_pbapc_job_enum job_type;
    srv_phb_pbap_storage_enum cur_path;
    srv_phb_pbap_storage_enum want_path;

    void *user_data;
    void *func;
    /* ex handle struct */
    srv_phb_pbapc_handle_ex_strcut ex_hd;
} srv_phb_pbapc_handle_struct;

typedef struct
{
    MMI_BOOL handle_exhausted;
    MMI_BOOL is_ready;
    srv_phb_pbapc_handle_struct pbapc_handle[SRV_PHB_PBAPC_MAX_HANDLE_NUM];
} srv_phb_pbapc_cntx_struct;

typedef struct
{
    S32 srv_handle;
    void *para;
    void *user_data;
} srv_phb_pbapc_async_hdlr_struct;


/* Structure for the request of prepare reading list */
typedef struct
{
    srv_phb_pbap_storage_enum storage;
    void *user_data;
    srv_phb_pbapc_read_pse_list_cb cb_func;
    S32 srv_hd;

    U16 *folder_name;
    U8 query_attr;
    U8 order;
    U8 *query_pattern;
    U8 query_length;           /* < SRV_PHB_PBAPC_MAX_ENTRY_NAME_LEN */
    U16 query_count;
    U16 query_offset;
    /* ex-req, provide buf to save index & name. list_entry buf size: SRV_PHB_PBAPC_MAX_READ_LIST_NUM * sizeof(srv_phb_pbapc_list_entry_struct) */
    srv_phb_pbapc_read_list_req_ex_struct list_req_ex;
} srv_phb_pbapc_prepare_read_list_req_struct;


/* Structure for the request of prepare reading folder */
typedef struct
{
    srv_phb_pbap_storage_enum storage;
    void *user_data;
    srv_phb_pbapc_read_pse_folder_cb cb_func;
    S32 srv_hd;

    U16 *folder_name;
    srv_phb_pbap_vcard_format_enum vcard_format;
    U32 vcard_filter;
    U16 list_count;
    U16 list_offset;
} srv_phb_pbapc_prepare_read_folder_req_struct;


/* Structure for the request of prepare reading entry */
typedef struct
{
    srv_phb_pbap_storage_enum storage;
    void *user_data;
    srv_phb_pbapc_read_pse_entry_cb cb_func;
    S32 srv_hd;

    U16 entry_index;          /* index in pse index.vcf */
    srv_phb_pbap_vcard_format_enum vcard_format;
    U32 vcard_filter;
} srv_phb_pbapc_prepare_read_entry_req_struct;


srv_phb_pbapc_cntx_struct g_srv_phb_pbapc_cntx;

srv_phb_pbapc_cntx_struct *srv_phb_pbapc_cntx_p;

srv_phb_pbapc_read_list_req_ex_struct g_srv_phb_pbapc_list_req;


/* function declare */

static srv_phb_pbapc_handle_struct *srv_phb_pbapc_get_handle_from_srv_hd(S32 srv_hd, S32 *result);

static void srv_phb_pbapc_read_pse_list_hdlr(void *user_data);

static void srv_phb_pbapc_read_pse_list_data_hdlr(void *user_data);

static void srv_phb_pbapc_read_pse_entry_hdlr(void *user_data);

static void srv_phb_pbapc_read_pse_folder_hdlr(void *user_data);

static void srv_phb_pbapc_disconnect_pse_hdlr(void *user_data);

static void srv_phb_pbapc_set_pse_path_hdlr(void *user_data);

static srv_phb_pbapc_cntx_struct *srv_phb_pbapc_get_cntx(void);

static mmi_pbapc_path_enum srv_phb_pbapc_get_path_enum(srv_phb_pbap_storage_enum storage);

static void srv_phb_pbapc_copy_list_entry(S32 srv_hd, bt_pbap_list_data_rsp_struct *list_rsp);

static srv_phb_pbapc_job_enum srv_phb_pbapc_get_job_type(S32 srv_hd);

static void srv_phb_pbapc_prepare_read_pse_entry(srv_phb_pbapc_read_entry_req_struct *entry_req, srv_phb_pbapc_read_pse_entry_cb cb_func);

static S32 srv_phb_pbapc_prepare_read_pse_entry_hdlr(srv_phb_pbapc_set_path_rsp_struct *path_rsp, void *user_data);

static void srv_phb_pbapc_prepare_read_pse_list(srv_phb_pbapc_read_list_req_struct *list_req, srv_phb_pbapc_read_pse_list_cb cb_func);

static S32 srv_phb_pbapc_prepare_read_pse_list_hdlr(srv_phb_pbapc_set_path_rsp_struct *path_rsp, void *user_data);

static void srv_phb_pbapc_prepare_read_pse_folder(srv_phb_pbapc_read_folder_req_struct *list_req, srv_phb_pbapc_read_pse_folder_cb cb_func);

static S32 srv_phb_pbapc_prepare_read_pse_folder_hdlr(srv_phb_pbapc_set_path_rsp_struct *path_rsp, void *user_data);

static void srv_phb_pbapc_change_pse_path(srv_phb_pbapc_handle_struct *handle, srv_phb_pbap_storage_enum cur_path);

static void srv_phb_pbapc_change_job_type(srv_phb_pbapc_handle_struct *handle, srv_phb_pbapc_job_enum job_type);

static S32 srv_phb_pbapc_set_pse_path(srv_phb_pbapc_set_path_req_struct *path_req, srv_phb_pbapc_set_pse_path_cb cb_func);

static S32 srv_phb_pbapc_get_folder_name(srv_phb_pbap_storage_enum folder, U16 *folder_name, U16 name_len);

static S32 srv_phb_pbapc_get_obj_name(U16 entry_index, U16 *obj_name, U16 name_len);

static void srv_phb_pbapc_start_read_data(void *user_data);

#define __SRV_PHB_PBAPC_TEST_TST__


#ifdef __SRV_PHB_PBAPC_TEST_TST__

static void srv_phb_pbapc_test_read_list(srv_phb_pbap_storage_enum path);

static S32 srv_phb_pbapc_test_read_list_cb(srv_phb_pbapc_read_list_rsp_struct *list_rsp, void *user_data);

static void srv_phb_pbapc_test_read_folder(srv_phb_pbap_storage_enum path);

static S32 srv_phb_pbapc_test_read_folder_cb(srv_phb_pbapc_read_folder_rsp_struct *folder_rsp, void *user_data);

static void srv_phb_pbapc_test_print_file(U16 *file_name);

static void srv_phb_pbapc_test_read_entry(U16 entry_index, srv_phb_pbap_storage_enum storage);

static S32 srv_phb_pbapc_test_read_entry_cb(srv_phb_pbapc_read_entry_rsp_struct *entry_rsp, void *user_data);

void srv_phb_pbapc_dump_trace_info(void *buf, int buf_len);

#endif /* __SRV_PHB_PBAPC_TEST_TST__ */

#endif /* defined(__BT_PBAP_CLIENT__) */

#endif /* __PHB_PBAPC_SRV_H__ */

