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
 * DtcntSrvDb.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the internal header file of data account database services.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _DTCNT_SRV_DB_H
#define _DTCNT_SRV_DB_H

#include "MMIDataType.h"
#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"
#include "cbm_consts.h"
#include "DtcntSrvIntEnum.h"
#include "kal_general_types.h"
#include "DtcntSrvIntStruct.h"

typedef enum
{
    SRV_DTCNT_DB_TRANS_NONE,
    SRV_DTCNT_DB_TRANS_CREATE,
    SRV_DTCNT_DB_TRANS_FIRST_BOOTUP,
    SRV_DTCNT_DB_TRANS_UPDATE,
    SRV_DTCNT_DB_TRANS_ADD,
    SRV_DTCNT_DB_TRANS_DELETE,
    SRV_DTCNT_DB_TRANS_TOTAL
} srv_dtcnt_db_trans_type_enum;


typedef struct 
{
    U8 store_commit;
    U32 csd_fields;
    U32 gprs_fields;
} srv_dtcnt_db_config_struct;

typedef struct 
{
    U8 need_px_flag;
    U8 no_px_flag;
    U8 skip_csd;
    srv_dtcnt_prof_px_srv_enum default_px_service;
    srv_dtcnt_sim_type_enum default_sim_info;
    srv_dtcnt_bearer_enum default_bearer_type;
    U8 use_proxy;
    U8 *best_fit_acc_id;
    cbm_sim_id_enum *sim_id;
    U64 app_type;
} srv_dtcnt_db_find_best_acct_cntx_struct;

extern srv_dtcnt_store_info_context g_srv_dtcnt_store_ctx;

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
#ifdef __TCPIP_OVER_CSD__
extern srv_dtcnt_sim_csd_account_info_st   csd_sim_acc_list[];
#endif /* __TCPIP_OVER_CSD__ */
#ifdef __MMI_GPRS_FEATURES__
extern srv_dtcnt_sim_gprs_account_info_st  gprs_sim_acc_list[];
#endif /* __MMI_GPRS_FEATURES__ */
#endif



extern void srv_dtcnt_db_store_init(void);
extern srv_dtcnt_store_status_enum srv_dtcnt_db_store_info_file_open(void);
extern void srv_dtcnt_db_store_ids_qry(srv_dtcnt_store_prof_qry_struct *qry);
extern MMI_BOOL srv_dtcnt_db_store_qry_check(srv_dtcnt_store_prof_qry_struct *qry);
extern srv_dtcnt_result_enum srv_dtcnt_db_store_add_wlan_prof(srv_dtcnt_prof_wlan_struct *data, U32 fields, U32 *out_acc_id);
extern srv_dtcnt_result_enum srv_dtcnt_db_store_csd_wlan_prof(srv_dtcnt_prof_csd_struct *data, U32 fields, U32 *out_acc_id);
extern srv_dtcnt_result_enum srv_dtcnt_db_store_gprs_wlan_prof(srv_dtcnt_prof_gprs_struct *data, U32 fields, U32 *out_acc_id);
extern srv_dtcnt_result_enum srv_dtcnt_db_store_add_prof(void *data, U32 fields, srv_dtcnt_bearer_enum type, U32 *out_acc_id);

extern srv_dtcnt_result_enum srv_dtcnt_db_atomic_begin(srv_dtcnt_db_trans_type_enum trans_type, kal_uint32 acc_id);
extern void srv_dtcnt_db_atomic_end(void);
extern MMI_BOOL srv_dtcnt_db_atomic_peek_status(srv_dtcnt_db_trans_type_enum *trans_type, kal_uint32 *acc_id);
extern void srv_dtcnt_db_atomic_terminate_trans(srv_dtcnt_db_trans_type_enum trans_type, kal_uint32 acc_id);


extern srv_dtcnt_result_enum srv_dtcnt_db_fileio_save_data(const kal_wchar *filename, const void *data, kal_uint32 data_size);
extern MMI_BOOL srv_dtcnt_db_fileio_file_exist(const kal_wchar *filename);
extern srv_dtcnt_result_enum srv_dtcnt_db_fileio_read_data(const kal_wchar *filename, void *buffer, kal_uint32 bufsize, U32 *out_size);
extern MMI_BOOL srv_dtcnt_db_file_path_exist(const kal_wchar *path);
extern MMI_BOOL srv_dtcnt_db_fileio_write_store_info_file(void);

extern void srv_dtcnt_db_store_bearer_init_ind_hdlr(void *info);
#ifdef __MMI_OP01_WIFI__
extern void srv_dtcnt_db_store_bearer_deinit_ind_hdlr(void *info);
#endif /* __MMI_OP01_WIFI__ */
extern void srv_dtcnt_db_store_prof_query_ind_hdlr(void *info);
extern MMI_BOOL srv_dtcnt_db_store_wifi_prefer_acct_check(U32 acc_id, srv_dtcnt_account_enum acc_idx);

extern MMI_BOOL srv_dtcnt_db_store_status_check(void);
extern U8 srv_dtcnt_extract_specified_acc_id(U32 acc_id, srv_dtcnt_account_enum idx);
extern srv_dtcnt_account_info_st* srv_dtcnt_db_store_get_acc_info(U8 acc_id);
extern srv_dtcnt_account_info_st* srv_dtcnt_db_store_get_acc_info_by_apn(S8 *apn);
extern srv_dtcnt_result_enum srv_dtcnt_db_store_update_prof(void *data, U32 fields, U32 acc_id, U8 dm_update);
extern srv_dtcnt_result_enum srv_dtcnt_db_store_load_prof(srv_dtcnt_account_info_st *target, void *out_data);
extern U8 srv_dtcnt_db_store_find_best_fit_acct(U8 ap_id, U8 *best_fit_acc_id, cbm_sim_id_enum *sim_id);
extern srv_dtcnt_result_enum srv_dtcnt_db_store_wlan_prof_qry(U32 prof_id, srv_dtcnt_store_prof_data_struct *prof_qry);
extern srv_dtcnt_result_enum srv_dtcnt_db_store_prof_qry(U8 acc_id, srv_dtcnt_store_prof_data_struct * prof_qry);
extern srv_dtcnt_result_enum srv_dtcnt_db_store_update_wlan_prof(srv_dtcnt_prof_wlan_struct * data, U32 fields, U32 prof_id);
extern void srv_dtcnt_db_store_del_wlan_profile(U32 profile_id);
extern srv_dtcnt_result_enum srv_dtcnt_db_store_del_account(U8 acc_id, MMI_BOOL force_exec, void *user_data, srv_dtcnt_store_delete_cb_func_ptr callback);
extern void srv_dtcnt_db_store_send_acc_update_post_evt(U8 acc_id, srv_dtcnt_sim_type_enum sim_info, U8 sim_changed, U8 cause);

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
extern MMI_BOOL srv_dtcnt_db_store_qry_sim_acc_info(U8 acc_id, srv_dtcnt_account_info_st *out_acc_info);
extern srv_dtcnt_sim_comm_account_info_st* srv_dtcnt_db_store_get_sim_acc_info(U8 acc_id);
extern srv_dtcnt_result_enum srv_dtcnt_db_store_add_sim_prof(void *data, srv_dtcnt_bearer_enum type, U32 *out_acc_id);
#endif

extern cbm_sim_id_enum srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(srv_dtcnt_sim_type_enum sim_info);
//extern void srv_dtcnt_db_store_update_user_defined_account_sim_info(srv_dtcnt_sim_type_enum sim_info);
extern U8 srv_dtcnt_get_real_acct(U32 acc_id, srv_dtcnt_account_enum acc_idx);
extern U8 srv_dtcnt_get_account_num(srv_dtcnt_sim_type_enum sim_info);
extern void srv_dtcnt_db_store_send_abm_acc_info(srv_dtcnt_db_trans_type_enum opcode, int index, U8 sim_changed);
#endif /* _DTCNT_SRV_DB_H */ 
