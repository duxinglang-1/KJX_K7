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
 * DtcntSrvDb.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file provides the data account database services.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __TCPIP__
#include "DtcntSrv.h"
#include <stdio.h>
#include "abm_api.h"
#include "cbm_api.h"
#include "app_str.h"
#include "MMI_features.h"
//#if defined (SYNCML_DM_SUPPORT) && defined(__CCA_SUPPORT__)
#if defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__)

#include "cbfunc.h"
#ifndef OMADM
#include "bftype.h"
#else
#include "toolset_types.h"
#endif
#endif
#include "mmi2abm_struct.h"
#include "NwInfoSrvGprot.h"
#include "NwUsabSrvGprot.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "DtcntSrvIprot.h"
#include "DtcntSrvIntStruct.h"
#include "DtcntSrvGprot.h"
#include "DtcntSrvDb.h"
#include "custom_data_account.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "DtcntSrvIntDef.h"
#include "fs_func.h"
#include "DtcntSrvIntEnum.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "mmi_frm_mem_gprot.h"
#include "string.h"
#include "DtcntSrvWlan.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "Unicodexdcl.h"
#include "app_ltlcom.h"
#include "cbm_consts.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "stack_common.h"
#include "mmi_l3_enums.h"
#include "ps_public_enum.h"
#include "csmcc_common_enums.h"
#include "csmcc_enums.h"
#include "mmi_cb_mgr_gprot.h"
#include "MRESrvGProt.h"
#include "CbmSrvIprot.h"

/***************************************************************************** 
* Definitions
*****************************************************************************/
#define srv_dtcnt_n2s(c,s)	((s=(((unsigned int)(c[0]))<< 8)| \
			    (((unsigned int)(c[1]))    )),c+=2)

#define srv_dtcnt_s2n(s,c)	((c[0]=(unsigned char)(((s)>> 8)&0xff), \
			  c[1]=(unsigned char)(((s)    )&0xff)),c+=2)
			  
#define srv_dtcnt_n2l(c,l)	(l =((unsigned long)(*((c)++)))<<24, \
			 l|=((unsigned long)(*((c)++)))<<16, \
			 l|=((unsigned long)(*((c)++)))<< 8, \
			 l|=((unsigned long)(*((c)++))))

#define srv_dtcnt_l2n(l,c)	(*((c)++)=(unsigned char)(((l)>>24)&0xff), \
			 *((c)++)=(unsigned char)(((l)>>16)&0xff), \
			 *((c)++)=(unsigned char)(((l)>> 8)&0xff), \
			 *((c)++)=(unsigned char)(((l)    )&0xff))

/***************************************************************************** 
* Local Function
*****************************************************************************/
static void srv_dtcnt_db_compose_acc_path(kal_wchar **path, U8 acc_id, srv_dtcnt_prof_acc_type_enum acc_type, srv_dtcnt_sim_type_enum sim);
static MMI_BOOL srv_dtcnt_db_store_filter(srv_dtcnt_store_prof_qry_filter_struct *filter, srv_dtcnt_account_info_st *target);
static MMI_BOOL srv_dtcnt_db_store_filter_val_check(srv_dtcnt_store_qry_type_enum type, void *sim_qry_info);
static srv_dtcnt_result_enum srv_dtcnt_db_store_detail_prof_fillin(void *dest, srv_dtcnt_account_info_st *target);
static void srv_dtcnt_db_store_acc_info_fillin(void *dest, srv_dtcnt_account_info_st *target);
static MMI_BOOL srv_dtcnt_db_store_acc_info_compose(void *data, U32 fields, srv_dtcnt_account_info_st *target);
static MMI_BOOL srv_dtcnt_db_store_compose_prof(void *data, U32 active_fields, void **raw_data, U32 *data_size, int idx);
static void srv_dtcnt_db_store_del_backup_info_file(void);
static void srv_dtcnt_db_store_del_backup_prof_file(void);
static void srv_dtcnt_db_store_recalc_acc_num(void);
static MMI_BOOL srv_dtcnt_db_store_backup_info_file(void);
static MMI_BOOL srv_dtcnt_db_store_backup_prof_file(kal_wchar * prof_name);
static void srv_dtcnt_db_store_send_msg(kal_uint16 msg_id, void *req, int mod_dst);
static MMI_BOOL srv_dtcnt_db_store_get_def_acc_info(cbm_sim_id_enum *sim_id,U8 *acc_id, srv_dtcnt_prof_px_srv_enum *px_service, srv_dtcnt_sim_type_enum *sim_info, srv_dtcnt_bearer_enum *bearer,U8 * proxy);
static void srv_dtcnt_db_store_prof_proxy_info_req_hdlr(void *info, int mod_src, void *msg);
static void srv_dtcnt_db_store_send_acc_delete_post_evt(U8 acc_id, srv_dtcnt_sim_type_enum sim_info, MMI_BOOL sync_done);
static MMI_BOOL srv_dtcnt_db_store_readonly_update_check(U8 ro_flag, U32 update_fields);
static void srv_dtcnt_db_store_update_abm_acc_info(void);
//void srv_dtcnt_db_store_send_abm_acc_info(srv_dtcnt_db_trans_type_enum opcode, int index, U8 sim_changed);
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
static MMI_BOOL srv_dtcnt_db_store_sim_prof_filter(srv_dtcnt_store_prof_qry_filter_struct *filter, srv_dtcnt_sim_comm_account_info_st *target, srv_dtcnt_bearer_enum type);
static U8 srv_dtcnt_db_store_find_best_mms_sim_acct(srv_dtcnt_db_find_best_acct_cntx_struct *best_acct_ctx);
#ifdef __MMI_GPRS_FEATURES__
srv_dtcnt_result_enum srv_dtcnt_db_store_sim_gprs_prof_fillin(srv_dtcnt_prof_gprs_struct *dest, srv_dtcnt_sim_gprs_account_info_st *src);
#endif
#ifdef __TCPIP_OVER_CSD__
srv_dtcnt_result_enum srv_dtcnt_db_store_sim_csd_prof_fillin(srv_dtcnt_prof_csd_struct *dest, srv_dtcnt_sim_csd_account_info_st *src);
#endif
#endif

#ifdef SYNCML_DM_SUPPORT
static int srv_dtcnt_db_store_check_dm_acc(int * out_idx, srv_dtcnt_bearer_enum type, void *data);
#endif /* SYNCML_DM_SUPPORT */

#ifdef __MMI_OP01_WIFI__
static void srv_dtcnt_bearer_init_wlan_ap_query_ind_callback(U32 bearer_type, U32 acct_id);
extern void srv_dtcnt_db_record_real_account(kal_uint32 ori_acct_id, kal_uint32 real_acct_id);

#endif /* __MMI_OP01_WIFI__ */

/***************************************************************************** 
* Global Function
*****************************************************************************/
//#if defined (SYNCML_DM_SUPPORT) && defined(__CCA_SUPPORT__)
#if defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__)
extern void mmi_dm_set_check_function(dm_setting_type_enum type, DMCheckCBFunc func);
#ifndef OMADM
extern bf_bool srv_dtcnt_ota_dm_set_check(void);
#else
extern IBOOL srv_dtcnt_ota_dm_set_check(void);
#endif
#endif
#ifdef __MMI_WLAN_FEATURES__
extern srv_dtcnt_wlan_ctx_struct g_srv_dtcnt_wlan_ctx;
extern srv_dtcnt_wlan_setting_struct g_srv_dtcnt_wlan_setting_ctx;
extern srv_dtcnt_prof_wlan_struct g_srv_dtcnt_wlan_prof_list[];
extern srv_dtcnt_prof_wlan_struct *g_srv_dtcnt_wlan_prof_list_p[];
#endif /* __MMI_WLAN_FEATURES__ */
//#ifdef __CCA_SUPPORT__
#ifdef __MMI_CCA_SUPPORT__
#include "DtcntSrvProv.h"
extern srv_dtcnt_ota_ctx_struct g_srv_dtcnt_ota_ctx;
#endif
/***************************************************************************** 
* Local Variable
*****************************************************************************/
srv_dtcnt_store_info_context g_srv_dtcnt_store_ctx;
/* APP_INFO_MODIFY */
MMI_BOOL g_srv_dtcnt_store_sync_done = MMI_FALSE;
srv_dtcnt_acct_delete_ind_evt_struct g_srv_dtcnt_del_evt;

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
#ifdef __TCPIP_OVER_CSD__
srv_dtcnt_sim_csd_account_info_st   csd_sim_acc_list[MAX_CSD_SIM_PROV_NUM];
#endif /* __TCPIP_OVER_CSD__ */
#ifdef __MMI_GPRS_FEATURES__
srv_dtcnt_sim_gprs_account_info_st  gprs_sim_acc_list[MAX_GPRS_SIM_PROV_NUM];
#endif /* __MMI_GPRS_FEATURES__ */
#endif

#ifdef __MMI_OP01_WIFI__
srv_dtcnt_bearer_init_job_list *g_bearer_init_job_list;
srv_dtcnt_real_account_for_app g_real_acct_map;

#endif /* __MMI_OP01_WIFI__ */



/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern srv_dtcnt_context g_srv_dtcnt_context;
//#ifdef __CCA_SUPPORT__
#ifdef __MMI_CCA_SUPPORT__
extern MMI_BOOL g_srv_dtcnt_ota_ongoing;
#endif /* __CCA_SUPPORT__ */

void srv_dtcnt_db_store_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_INIT);
    kal_mem_set(&g_srv_dtcnt_store_ctx, 0, sizeof(srv_dtcnt_store_info_context));
    kal_mem_set(&g_srv_dtcnt_del_evt, 0, sizeof(srv_dtcnt_acct_delete_ind_evt_struct));

    //SetProtocolEventHandler(srv_dtcnt_db_store_bearer_init_ind_hdlr, MSG_ID_MMI_ABM_BEARER_INIT_IND);
    SetProtocolEventHandler(srv_dtcnt_db_store_prof_query_ind_hdlr, MSG_ID_MMI_ABM_PROFILE_QUERY_IND);
    SetProtocolEventHandler(srv_dtcnt_db_store_prof_proxy_info_req_hdlr, MSG_ID_SRV_DTCNT_PROF_PROXY_INFO_REQ);    
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
#ifdef __TCPIP_OVER_CSD__
    kal_mem_set(csd_sim_acc_list, 0, sizeof(srv_dtcnt_sim_csd_account_info_st) * MAX_CSD_SIM_PROV_NUM);
#endif /* __TCPIP_OVER_CSD__ */
#ifdef __MMI_GPRS_FEATURES__
    kal_mem_set(gprs_sim_acc_list, 0, sizeof(srv_dtcnt_sim_gprs_account_info_st) * MAX_GPRS_SIM_PROV_NUM);
#endif /* __MMI_GPRS_FEATURES__ */
#endif    
//#if defined (SYNCML_DM_SUPPORT) && defined(__CCA_SUPPORT__)
#if defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__)
	mmi_dm_set_check_function(DM_SETTING_TYPE_DATA_ACCOUNT_HTTP, srv_dtcnt_ota_dm_set_check);
    mmi_dm_set_check_function(DM_SETTING_TYPE_DATA_ACCOUNT_WAP, srv_dtcnt_ota_dm_set_check);
    mmi_dm_set_check_function(DM_SETTING_TYPE_DATA_ACCOUNT_CSD, srv_dtcnt_ota_dm_set_check);
#endif /* SYNCML_DM_SUPPORT */
    if(!srv_dtcnt_db_file_path_exist(SRV_DTCNT_ROOT_FOLDER))
    {
        FS_CreateDir(SRV_DTCNT_ROOT_FOLDER);
    }
    
#ifdef __MMI_OP01_WIFI__
    g_bearer_init_job_list = NULL;
    //SetProtocolEventHandler(srv_dtcnt_db_store_bearer_deinit_ind_hdlr, MSG_ID_MMI_ABM_BEARER_DEINIT_IND);
#endif /* __MMI_OP01_WIFI__ */
}

srv_dtcnt_store_status_enum srv_dtcnt_db_store_info_file_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int read;
    int fs_err;
    int sim_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_INFO_FILE_OPEN);
    /* check if file exists */
    if (!srv_dtcnt_db_fileio_file_exist((const WCHAR*)SRV_DTCNT_DB_STORE_INFOFILE_NAME))
    {
        g_srv_dtcnt_context.store_status = SRV_DTCNT_STORE_STATUS_FIRST_BOOTUP;
    }
    else    /* not first-bootup case */
    {
        /* --- check abnormal case by folder exists and info file, then error handling --- */        
        /* open cert info file */
        g_srv_dtcnt_context.info_file_fp = FS_Open((const WCHAR*)SRV_DTCNT_DB_STORE_INFOFILE_NAME, FS_READ_WRITE|FS_COMMITTED);
        if (g_srv_dtcnt_context.info_file_fp < 0)
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_INFO_FILE_OPEN_FAIL, g_srv_dtcnt_context.info_file_fp);
            g_srv_dtcnt_context.store_status = SRV_DTCNT_STORE_STATUS_FS_ERROR;
            goto store_info_open_ret;
        }
        
        fs_err = FS_Read(g_srv_dtcnt_context.info_file_fp, &g_srv_dtcnt_store_ctx, sizeof(srv_dtcnt_store_info_context), (UINT*)&read);
        if (fs_err < FS_NO_ERROR || (read != sizeof(srv_dtcnt_store_info_context)))
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_INFO_FILE_READ_FAIL, fs_err);
            FS_Close(g_srv_dtcnt_context.info_file_fp);
            g_srv_dtcnt_context.store_status = SRV_DTCNT_STORE_STATUS_FS_ERROR;
            goto store_info_open_ret;
        }

        for(sim_index = 0; sim_index < SRV_DTCNT_SIM_TYPE_TOTAL-1; sim_index++)
        {
            if (g_srv_dtcnt_store_ctx.default_acc_idx[sim_index] && g_srv_dtcnt_store_ctx.default_acc_idx[sim_index] > SRV_DTCNT_PROF_MAX_ACCOUNT_NUM)
        {
                #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif
                MMI_ASSERT(0);
            }
        }
        
        /* check corruption */
        //g_srv_dtcnt_context.store_status = SRV_DTCNT_STORE_STATUS_CORRUPT;
        //goto store_info_open_ret;
        
        /* check factory reset */
        if (!srv_dtcnt_db_fileio_file_exist(SRV_DTCNT_SIM_PROF_RESET_FILE))
        {		
			int i, res;
            g_srv_dtcnt_context.store_status = SRV_DTCNT_STORE_STATUS_RESET_FACTORY;            
            for (i = 0; i < (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM + SRV_DTCNT_RESERVED_DM_ACC_NUM); i++)
            {
                if (g_srv_dtcnt_store_ctx.acc_list[i].in_use)
				{
					switch (g_srv_dtcnt_store_ctx.acc_list[i].acc_type)
					{
						case SRV_DTCNT_PROF_TYPE_DM_CONF:
							{
								kal_wchar *ucs2_filename = NULL;

								srv_dtcnt_db_compose_acc_path(
										&ucs2_filename,                 
										(U8)(g_srv_dtcnt_store_ctx.acc_list[i].acc_id),
										g_srv_dtcnt_store_ctx.acc_list[i].acc_type,
										g_srv_dtcnt_store_ctx.acc_list[i].sim_info);
								FS_Delete(ucs2_filename);
								OslMfree(ucs2_filename);
							}
						case SRV_DTCNT_PROF_TYPE_FACTORY_CONF:
							g_srv_dtcnt_store_ctx.acc_list[i].in_use = 0;
							g_srv_dtcnt_store_ctx.ctrl_block.total_acc_num--;

                            for(sim_index = 0; sim_index < SRV_DTCNT_SIM_TYPE_TOTAL-1; sim_index++)
                            {
                                if(g_srv_dtcnt_store_ctx.default_acc_idx[sim_index] == i+1)
                                {
                                    g_srv_dtcnt_store_ctx.acc_list[i].app_type &= ~DTCNT_APPTYPE_DEF;
                                    g_srv_dtcnt_store_ctx.default_acc_idx[sim_index] = 0;
                                }
                            }
							break;
					}
				}
            }
            
            res = FS_Open (SRV_DTCNT_SIM_PROF_RESET_FILE, FS_CREATE_ALWAYS);
            if (res < 0)
            {
                return SRV_DTCNT_STORE_STATUS_FS_ERROR;
            }
            FS_Close(res);
        }
        /*
        else if (!srv_dtcnt_db_file_path_exist(SRV_DTCNT_USER_PROF_PATH))
        {
            g_srv_dtcnt_context.store_status = SRV_DTCNT_STORE_STATUS_FS_ERROR;
        }
        */
        else
        {
            g_srv_dtcnt_context.store_status = SRV_DTCNT_STORE_STATUS_OPENED;
        }
    }
    
store_info_open_ret:
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_INFO_FILE_OPEN_DONE, g_srv_dtcnt_context.store_status);
    return g_srv_dtcnt_context.store_status;
}

void srv_dtcnt_db_store_ids_qry(srv_dtcnt_store_prof_qry_struct *qry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (qry->qry_info.filters & SRV_DTCNT_STORE_QRY_TYPE_BEARER_TYPE &&
        qry->qry_info.bearer_qry_info == SRV_DTCNT_BEARER_WIFI)
    {
#ifdef __MMI_WLAN_FEATURES__
        U8 total_num = g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num + g_srv_dtcnt_wlan_setting_ctx.infra_prof_num;

        for (i = 0; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; i++)
        {
            if (g_srv_dtcnt_wlan_prof_list[i].priority > 0 && g_srv_dtcnt_wlan_prof_list[i].ssid_len)
            {
                if (qry->num_ids < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM)
                {
                    qry->ids[qry->num_ids++] = g_srv_dtcnt_wlan_prof_list[i].profile_id;
                }
            }
        }
        if (qry->num_ids != total_num)
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_WLAN_IDS_QRY, qry->num_ids, total_num);
        }
#endif /* __MMI_WLAN_FEATURES__ */        
    }
    else
    {
        for (i = 0; i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM + SRV_DTCNT_RESERVED_DM_ACC_NUM; i++)
        {
            if (g_srv_dtcnt_store_ctx.acc_list[i].in_use)
            {
                if (srv_dtcnt_db_store_filter(&(qry->qry_info), &(g_srv_dtcnt_store_ctx.acc_list[i])))
                {
                    qry->ids[qry->num_ids++] = (U32)g_srv_dtcnt_store_ctx.acc_list[i].acc_id;
                }
            }
        }
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
        #ifdef __TCPIP_OVER_CSD__
        for (i = 0; i<MAX_CSD_SIM_PROV_NUM; i++)
        {
            if (csd_sim_acc_list[i].comm_header.in_use)
            {
                if (srv_dtcnt_db_store_sim_prof_filter(&(qry->qry_info), &(csd_sim_acc_list[i].comm_header), SRV_DTCNT_BEARER_CSD))
                {
                    qry->ids[qry->num_ids++] = (U32)csd_sim_acc_list[i].comm_header.acc_id;
                }
            }
        }
        #endif /* __TCPIP_OVER_CSD__ */
        #ifdef __MMI_GPRS_FEATURES__
        for (i = 0; i<MAX_GPRS_SIM_PROV_NUM; i++)
        {
            if (gprs_sim_acc_list[i].comm_header.in_use)
            {
                if (srv_dtcnt_db_store_sim_prof_filter(&(qry->qry_info), &(gprs_sim_acc_list[i].comm_header), SRV_DTCNT_BEARER_GPRS))
                {
                    qry->ids[qry->num_ids++] = (U32)gprs_sim_acc_list[i].comm_header.acc_id;
                }
            }
        }
        #endif /* __MMI_GPRS_FEATURES__ */
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */
    }
}

srv_dtcnt_result_enum srv_dtcnt_db_store_prof_qry(U8 acc_id, srv_dtcnt_store_prof_data_struct *prof_qry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_PROF_QRY, acc_id);
    for (i = 0; i < (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM + SRV_DTCNT_RESERVED_DM_ACC_NUM); i++)
    {
        if (g_srv_dtcnt_store_ctx.acc_list[i].in_use &&
            g_srv_dtcnt_store_ctx.acc_list[i].acc_id == acc_id)            
        {        
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_PROF_QRY_FOUND);
            prof_qry->prof_type = g_srv_dtcnt_store_ctx.acc_list[i].bearer_type;
            prof_qry->prof_fields = g_srv_dtcnt_store_ctx.acc_list[i].fields;
            if (!(prof_qry->prof_data))
            {
                return SRV_DTCNT_RESULT_SUCCESS;
            }
            else if (prof_qry->prof_type == SRV_DTCNT_BEARER_CSD)
            {
                kal_mem_set(prof_qry->prof_data, 0, sizeof(srv_dtcnt_prof_csd_struct));
            }
            else /* gprs */
            {
                kal_mem_set(prof_qry->prof_data, 0, sizeof(srv_dtcnt_prof_gprs_struct));
            }
            return srv_dtcnt_db_store_detail_prof_fillin(prof_qry->prof_data, &(g_srv_dtcnt_store_ctx.acc_list[i]));
        }
    }

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
#ifdef __TCPIP_OVER_CSD__
    for (i = 0; i < MAX_CSD_SIM_PROV_NUM; i++)
    {
        if (csd_sim_acc_list[i].comm_header.in_use &&
            csd_sim_acc_list[i].comm_header.acc_id == acc_id)            
        {        
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_PROF_QRY_FOUND_SIM_CSD);
            prof_qry->prof_type = SRV_DTCNT_BEARER_CSD;
            prof_qry->prof_fields = csd_sim_acc_list[i].comm_header.fields;
            if (!(prof_qry->prof_data))
            {
                return SRV_DTCNT_RESULT_SUCCESS;
            }
            else
            {
                kal_mem_set(prof_qry->prof_data, 0, sizeof(srv_dtcnt_prof_csd_struct));
            }
            return srv_dtcnt_db_store_sim_csd_prof_fillin((srv_dtcnt_prof_csd_struct *)prof_qry->prof_data, &csd_sim_acc_list[i]);
        }
    }
#endif /* __TCPIP_OVER_CSD__ */
#ifdef __MMI_GPRS_FEATURES__
    for (i = 0; i < MAX_GPRS_SIM_PROV_NUM; i++)
    {
        if (gprs_sim_acc_list[i].comm_header.in_use &&
            gprs_sim_acc_list[i].comm_header.acc_id == acc_id)
        {        
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_PROF_QRY_FOUND_SIM_GPRS);
            prof_qry->prof_type = SRV_DTCNT_BEARER_GPRS;
            prof_qry->prof_fields = gprs_sim_acc_list[i].comm_header.fields;
            if (!(prof_qry->prof_data))
            {
                return SRV_DTCNT_RESULT_SUCCESS;
            }
            else /* gprs */
            {
                kal_mem_set(prof_qry->prof_data, 0, sizeof(srv_dtcnt_prof_gprs_struct));
            }
            return srv_dtcnt_db_store_sim_gprs_prof_fillin((srv_dtcnt_prof_gprs_struct *)prof_qry->prof_data, &gprs_sim_acc_list[i]);
        }
    }
#endif /* __MMI_GPRS_FEATURES__ */
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */

    return SRV_DTCNT_RESULT_INVALID_INPUT;
}

srv_dtcnt_result_enum srv_dtcnt_db_store_wlan_prof_qry(U32 prof_id, srv_dtcnt_store_prof_data_struct *prof_qry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
    int i;
    srv_dtcnt_prof_wlan_struct *prof;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_WLAN_PROF_QRY, prof_id);    
    for (i = 0; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; i++)
    {
        if (g_srv_dtcnt_wlan_prof_list[i].priority > 0 && 
            g_srv_dtcnt_wlan_prof_list[i].ssid_len &&
            g_srv_dtcnt_wlan_prof_list[i].profile_id == prof_id)
        {           
            prof_qry->prof_type = SRV_DTCNT_BEARER_WIFI;
            prof_qry->prof_fields = SRV_DTCNT_WLAN_PROF_FIELD_ALL;
            if (prof_qry->prof_data)
            {
                prof = (srv_dtcnt_prof_wlan_struct *)prof_qry->prof_data;
                kal_mem_cpy(prof, &(g_srv_dtcnt_wlan_prof_list[i]), sizeof(srv_dtcnt_prof_wlan_struct));
            }
            return SRV_DTCNT_RESULT_SUCCESS;
        }
    }
    return SRV_DTCNT_RESULT_INVALID_INPUT;
#else /* !__MMI_WLAN_FEATURES__ */
    return SRV_DTCNT_RESULT_FAILED;
#endif /* __MMI_WLAN_FEATURES__ */
}

MMI_BOOL srv_dtcnt_db_store_qry_check(srv_dtcnt_store_prof_qry_struct *qry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_QRY_CHECK_ERR, qry->qry_info.sim_qry_info, qry->qry_info.app_type,qry->qry_info.bearer_qry_info,qry->qry_info.acc_type_info);
    if (qry->qry_info.filters & SRV_DTCNT_STORE_QRY_TYPE_SIM &&
        !srv_dtcnt_db_store_filter_val_check(SRV_DTCNT_STORE_QRY_TYPE_SIM, &(qry->qry_info.sim_qry_info)))
    {
        return MMI_FALSE;
    }
    if (qry->qry_info.filters & SRV_DTCNT_STORE_QRY_TYPE_APP_TYPE &&
        !srv_dtcnt_db_store_filter_val_check(SRV_DTCNT_STORE_QRY_TYPE_APP_TYPE, &(qry->qry_info.app_type)))
    {
        return MMI_FALSE;
    }
    if (qry->qry_info.filters & SRV_DTCNT_STORE_QRY_TYPE_BEARER_TYPE &&
        !srv_dtcnt_db_store_filter_val_check(SRV_DTCNT_STORE_QRY_TYPE_BEARER_TYPE, &(qry->qry_info.bearer_qry_info)))
    {
        return MMI_FALSE;
    }
    if (qry->qry_info.filters & SRV_DTCNT_STORE_QRY_TYPE_ACC_TYPE &&
        !srv_dtcnt_db_store_filter_val_check(SRV_DTCNT_STORE_QRY_TYPE_ACC_TYPE, &(qry->qry_info.acc_type_info)))
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_db_atomic_begin
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  
 *****************************************************************************/
srv_dtcnt_result_enum srv_dtcnt_db_atomic_begin(srv_dtcnt_db_trans_type_enum trans_type, U32 acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 data[sizeof(srv_dtcnt_db_trans_type_enum)+sizeof(U32)];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_ATOMIC_BEGIN, trans_type, acc_id);
    kal_mem_set(data, 0, sizeof(srv_dtcnt_db_trans_type_enum)+sizeof(U32));
    kal_mem_cpy(data, &trans_type, sizeof(srv_dtcnt_db_trans_type_enum));
    kal_mem_cpy(data+sizeof(srv_dtcnt_db_trans_type_enum), &acc_id, sizeof(U32));
    
    return srv_dtcnt_db_fileio_save_data(SRV_DTCNT_ATOMIC_OP_FILENAME, (const void*)data, sizeof(srv_dtcnt_db_trans_type_enum)+sizeof(U32));
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_db_atomic_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  
 *****************************************************************************/
void srv_dtcnt_db_atomic_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_ATOMIC_END);
    srv_dtcnt_db_atomic_begin(SRV_DTCNT_DB_TRANS_NONE, 0);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_db_atomic_peek_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  0       no transaction
 *  1       has transaction
 *****************************************************************************/
MMI_BOOL srv_dtcnt_db_atomic_peek_status(srv_dtcnt_db_trans_type_enum *trans_type, U32 *acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_result_enum err;
    kal_uint8 data[sizeof(srv_dtcnt_db_trans_type_enum)+sizeof(U32)];
    srv_dtcnt_db_trans_type_enum tp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err = srv_dtcnt_db_fileio_read_data(SRV_DTCNT_ATOMIC_OP_FILENAME, (void*)data, sizeof(srv_dtcnt_db_trans_type_enum)+sizeof(U32), 0);
    if (err)
    {
        srv_dtcnt_db_atomic_end();
        return MMI_FALSE;
    }
    
    kal_mem_cpy(&tp, data, sizeof(srv_dtcnt_db_trans_type_enum));
    
    if (tp == SRV_DTCNT_DB_TRANS_NONE)
        return MMI_FALSE;

    if (tp >= SRV_DTCNT_DB_TRANS_TOTAL)
    {
        srv_dtcnt_db_atomic_end();
        return MMI_FALSE;
    }

    if (trans_type)
        *trans_type = tp;

    if (acc_id)
        kal_mem_cpy(acc_id, data+sizeof(srv_dtcnt_db_trans_type_enum), sizeof(U32));

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_db_atomic_terminate_trans
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  
 *****************************************************************************/
void srv_dtcnt_db_atomic_terminate_trans(srv_dtcnt_db_trans_type_enum trans_type, U32 acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 found = 0;
    int i;
    U32 out_size;
    kal_wchar *ucs2_filename = NULL;
    srv_dtcnt_result_enum ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_ATOMIC_TERM_TRANS, trans_type, acc_id);
    if (trans_type != SRV_DTCNT_DB_TRANS_ADD &&
        trans_type != SRV_DTCNT_DB_TRANS_DELETE &&
        trans_type != SRV_DTCNT_DB_TRANS_UPDATE)
    {
        return;
    }

    for (i = 0; i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
        if (g_srv_dtcnt_store_ctx.acc_list[i].acc_id == (U8)acc_id)
        {
            found = 1;
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_ATOMIC_TERM_TRANS_FOUND);
            break;
        }
    }

    if (trans_type != SRV_DTCNT_DB_TRANS_UPDATE)
    {
        if (!found || !g_srv_dtcnt_store_ctx.acc_list[i].in_use)
        {
            srv_dtcnt_db_store_recalc_acc_num();
            srv_dtcnt_db_atomic_end();
            return;
        }

        /* check real account file first */
        srv_dtcnt_db_compose_acc_path(
                                &ucs2_filename,
                                (U8)acc_id, 
                                g_srv_dtcnt_store_ctx.acc_list[i].acc_type,
                                g_srv_dtcnt_store_ctx.acc_list[i].sim_info);

        if (ucs2_filename)
        {
            int fs_err;
            
            fs_err = FS_Delete(ucs2_filename);
            if (fs_err < FS_NO_ERROR && fs_err != FS_FILE_NOT_FOUND)
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_ATOMIC_TERM_TRANS_FS_ERR, fs_err);
            }
            else
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_ATOMIC_TERM_TRANS_DONE);
            }
        }
    }
    else /* SRV_DTCNT_DB_TRANS_UPDATE */
    {        
        /* delete current profile file first */
        srv_dtcnt_db_compose_acc_path(
                &ucs2_filename, 
                (U8)(g_srv_dtcnt_store_ctx.acc_list[i].acc_id),
                g_srv_dtcnt_store_ctx.acc_list[i].acc_type,
                g_srv_dtcnt_store_ctx.acc_list[i].sim_info);
        FS_Delete(ucs2_filename);
        OslMfree(ucs2_filename);
        ucs2_filename = NULL;
        
        /* rollback settings and backup file */
        MMI_ASSERT(srv_dtcnt_db_fileio_file_exist(SRV_DTCNT_DB_STORE_INFOFILE_BAK_NAME));
        ret = srv_dtcnt_db_fileio_read_data(SRV_DTCNT_DB_STORE_INFOFILE_BAK_NAME, &(g_srv_dtcnt_store_ctx), sizeof(srv_dtcnt_store_info_context), &out_size);
        MMI_ASSERT(ret == SRV_DTCNT_RESULT_SUCCESS && out_size == sizeof(srv_dtcnt_store_info_context));
        if (srv_dtcnt_db_fileio_file_exist(SRV_DTCNT_DB_ACC_FILE_BAK_NAME))
        {
            int fp;
            U32 filesize = 0;
            U32 read;
            void *buffer;

            if (g_srv_dtcnt_store_ctx.acc_list[i].acc_id == (U8)acc_id)
            {
                srv_dtcnt_db_compose_acc_path(
                        &ucs2_filename, 
                        (U8)(g_srv_dtcnt_store_ctx.acc_list[i].acc_id),
                        g_srv_dtcnt_store_ctx.acc_list[i].acc_type,
                        g_srv_dtcnt_store_ctx.acc_list[i].sim_info);

                fp = FS_Open(SRV_DTCNT_DB_ACC_FILE_BAK_NAME, FS_READ_ONLY);
                if (fp > 0 && FS_GetFileSize(fp, (UINT*)&filesize) > 0 && !filesize)
                {
                    buffer = OslMalloc(filesize);
                    if (FS_Read(fp, (void*)buffer, (UINT)filesize, &read) < 0 || filesize != read)
                    {
                        OslMfree(buffer);
                        goto fs_err_handle;
                    }
                    FS_Close(fp);

                    if (srv_dtcnt_db_fileio_save_data(ucs2_filename, buffer, filesize) != SRV_DTCNT_RESULT_SUCCESS)
                    {
                        OslMfree(buffer);
                        goto fs_err_handle;
                    }
                    OslMfree(buffer);
                    goto update_done;
                }
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_ATOMIC_TERM_TRANS_FS_ERR, fp);
            }           
        }       
        else /* no profile file */
        {
            goto update_done;
        }
    }
    
fs_err_handle:
    g_srv_dtcnt_store_ctx.acc_list[i].in_use = 0;    
update_done:
    if (ucs2_filename)
    {
        OslMfree(ucs2_filename);
    }
    srv_dtcnt_db_store_del_backup_info_file();
    srv_dtcnt_db_store_del_backup_prof_file();    
    srv_dtcnt_db_atomic_end();
    return;

}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_db_compose_acc_path
 * DESCRIPTION
 *  this func generates a unique filename and also checks for existence of file on file system,
 * 
 *  filename format: "path\id_xxxxxx.extension"
 * 
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
void srv_dtcnt_db_compose_acc_path(kal_wchar **path, U8 acc_id, srv_dtcnt_prof_acc_type_enum acc_type, srv_dtcnt_sim_type_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 size = 0;
    kal_wchar  namestr[11] = {0};
    U8 asc_id_str[4] = {0};    /* 3 digits in U8, 1 for zero-terminate */
    U8 sim_id_str[2] = {0};    /* 1 digits for SIM id, 1 for zero-terminate */    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
    if (!srv_dtcnt_db_file_path_exist(SRV_DTCNT_SIM_PROF_PATH))
    {
        FS_CreateDir(SRV_DTCNT_SIM_PROF_PATH);
    }
    */
    if (!srv_dtcnt_db_file_path_exist(SRV_DTCNT_USER_PROF_PATH))
    {
        FS_CreateDir(SRV_DTCNT_USER_PROF_PATH);
    }

    /* setup path */
    switch (acc_type)
    {
        /* c:\@Dtcnt\DB\SIM\sim_x_xxx */
        case SRV_DTCNT_PROF_TYPE_FACTORY_CONF:
            size = app_ucs2_strlen((const kal_int8 *)SRV_DTCNT_SIM_PROF_PATH);
            size += strlen((CHAR*)"sim_x_");
            break;
        /* c:\@Dtcnt\DB\USER\ota_x_xxx */
        case SRV_DTCNT_PROF_TYPE_OTA_CONF:
        case SRV_DTCNT_PROF_TYPE_SIM_PROF:
        case SRV_DTCNT_PROF_TYPE_DM_CONF:
            size = app_ucs2_strlen((const kal_int8 *)SRV_DTCNT_USER_PROF_PATH);
            size += strlen((CHAR*)"ota_x_");
            break;
        /* c:\@Dtcnt\DB\USER\user_x_xxx */
        case SRV_DTCNT_PROF_TYPE_USER_CONF:
            size = app_ucs2_strlen((const kal_int8 *)SRV_DTCNT_USER_PROF_PATH);            
            size += strlen((CHAR*)"user_x_");
            break;
    }

    size += (3+1);//maximum 3 digits and 1 zero-terminate    
    *path = OslMalloc(size * ENCODING_LENGTH);
    kal_mem_set(*path, 0, (size * ENCODING_LENGTH));
    sprintf((CHAR *)asc_id_str, "%d", acc_id);
    sprintf((CHAR *)sim_id_str, "%d", (U8)sim);
    
    switch (acc_type)
    {
        case SRV_DTCNT_PROF_TYPE_FACTORY_CONF:
            app_ucs2_strcpy((kal_int8*)*path, (const kal_int8*)SRV_DTCNT_SIM_PROF_PATH);
            app_asc_str_n_to_ucs2_str((kal_int8*)(namestr), (kal_int8*)"sim_", 4);
            app_asc_str_n_to_ucs2_str((kal_int8*)(namestr+4), (kal_int8*)sim_id_str, 1);
            app_asc_str_n_to_ucs2_str((kal_int8*)(namestr+5), (kal_int8*)"_", 1);
            app_asc_str_n_to_ucs2_str((kal_int8*)(namestr+6), (kal_int8*)asc_id_str, 4);
            break;
        case SRV_DTCNT_PROF_TYPE_OTA_CONF:
        case SRV_DTCNT_PROF_TYPE_SIM_PROF:
        case SRV_DTCNT_PROF_TYPE_DM_CONF:
            app_ucs2_strcpy((kal_int8*)*path, (const kal_int8*)SRV_DTCNT_USER_PROF_PATH);
            app_asc_str_n_to_ucs2_str((kal_int8*)(namestr), (kal_int8*)"ota_", 4);
            app_asc_str_n_to_ucs2_str((kal_int8*)(namestr+4), (kal_int8*)sim_id_str, 1);
            app_asc_str_n_to_ucs2_str((kal_int8*)(namestr+5), (kal_int8*)"_", 1);
            app_asc_str_n_to_ucs2_str((kal_int8*)(namestr+6), (kal_int8*)asc_id_str, 4);
            break;
        case SRV_DTCNT_PROF_TYPE_USER_CONF:
            app_ucs2_strcpy((kal_int8*)*path, (const kal_int8*)SRV_DTCNT_USER_PROF_PATH);
            app_asc_str_n_to_ucs2_str((kal_int8*)(namestr), (kal_int8*)"user_", 5);
            app_asc_str_n_to_ucs2_str((kal_int8*)(namestr+5), (kal_int8*)sim_id_str, 1);
            app_asc_str_n_to_ucs2_str((kal_int8*)(namestr+6), (kal_int8*)"_", 1);
            app_asc_str_n_to_ucs2_str((kal_int8*)(namestr+7), (kal_int8*)asc_id_str, 4);            
            break;
    }

    app_ucs2_strcat((kal_int8 *)(*path), (const kal_int8 *)namestr);
}


MMI_BOOL srv_dtcnt_db_store_filter(srv_dtcnt_store_prof_qry_filter_struct *filter, srv_dtcnt_account_info_st *target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (filter->filters & SRV_DTCNT_STORE_QRY_TYPE_SIM)
    {
        if (target->sim_info != filter->sim_qry_info)
        {
            return MMI_FALSE;
        }
    }
    if (filter->filters & SRV_DTCNT_STORE_QRY_TYPE_APP_TYPE)
    {
        if ((target->app_type & filter->app_type) == 0)
        {
            return MMI_FALSE;
        }
    }
    if (filter->filters & SRV_DTCNT_STORE_QRY_TYPE_BEARER_TYPE)
    {
        if (target->bearer_type != filter->bearer_qry_info)
        {
            return MMI_FALSE;
        }
    }
    if (filter->filters & SRV_DTCNT_STORE_QRY_TYPE_ACC_TYPE)
    {
        if (target->acc_type != filter->acc_type_info)
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;    
}

MMI_BOOL srv_dtcnt_db_store_filter_val_check(srv_dtcnt_store_qry_type_enum type, void *qry_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (type)
    {
        case SRV_DTCNT_STORE_QRY_TYPE_SIM:
            {
                srv_dtcnt_sim_type_enum *sim_qry_info = qry_info;
                if (*sim_qry_info >= SRV_DTCNT_SIM_TYPE_TOTAL ||
                    *sim_qry_info < SRV_DTCNT_SIM_TYPE_1)
                {
                    return MMI_FALSE;
                }
            }
            break;
            
        case SRV_DTCNT_STORE_QRY_TYPE_APP_TYPE:
            {
                U64 *app_type_qry_info = qry_info;
                if (*app_type_qry_info == 0)
                {
                    return MMI_FALSE;
                }
            }
            break;
            
        case SRV_DTCNT_STORE_QRY_TYPE_BEARER_TYPE:
            {
                srv_dtcnt_bearer_enum *bearer_qry_info = qry_info;
                if (*bearer_qry_info > SRV_DTCNT_BEARER_WIFI ||
                    *bearer_qry_info < SRV_DTCNT_BEARER_CSD)
                {
                    return MMI_FALSE;
                }
            }
            break;

        case SRV_DTCNT_STORE_QRY_TYPE_ACC_TYPE:
            {
                srv_dtcnt_prof_acc_type_enum *acc_qry_info = qry_info;
                if (*acc_qry_info >= SRV_DTCNT_PROF_TYPE_TOTAL)
                {
                    return MMI_FALSE;
                }
            }
            break;
    }
    return MMI_TRUE;
}


void srv_dtcnt_db_store_acc_info_fillin(void *dest, srv_dtcnt_account_info_st *target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __TCPIP_OVER_CSD__ 
    srv_dtcnt_prof_csd_struct *csd = (srv_dtcnt_prof_csd_struct *)dest;
#endif
    srv_dtcnt_prof_gprs_struct *gprs = (srv_dtcnt_prof_gprs_struct *)dest;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!dest || !target)
    {
        return;
    }

    gprs->prof_common_header.acc_id = target->acc_id;
    gprs->prof_common_header.AccountName = target->acc_name;
    gprs->prof_common_header.acct_type = target->acc_type;
    gprs->prof_common_header.sim_info = target->sim_info;
    gprs->prof_common_header.px_service = target->px_service;
    gprs->prof_common_header.AppType = target->app_type;
    gprs->prof_common_header.use_proxy = target->use_proxy;
    kal_mem_cpy(gprs->prof_common_header.Auth_info.UserName, target->auth_info.UserName, SRV_DTCNT_PROF_MAX_USER_LEN+1);
    kal_mem_cpy(gprs->prof_common_header.Auth_info.Passwd, target->auth_info.Passwd, SRV_DTCNT_PROF_MAX_PW_LEN+1);    
    kal_mem_cpy(gprs->prof_common_header.PrimaryAddr, target->PrimaryAddr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    kal_mem_cpy(gprs->prof_common_header.SecondaryAddr, target->SecondaryAddr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);    

#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    kal_mem_cpy(gprs->prof_common_header.provurl_hash_val, target->provurl_hash_val, SRV_DTCNT_PROVURL_HASH_LEN);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    kal_mem_cpy(gprs->prof_common_header.napid_hash_val, target->napid_hash_val, SRV_DTCNT_NAPID_HASH_LEN);
    gprs->prof_common_header.read_only = target->readonly;

#ifdef __TCPIP_OVER_CSD__    
    if (target->bearer_type == SRV_DTCNT_BEARER_CSD)
    {
        csd->DialNumber = target->dest_name;
        csd->DataRate = target->DataRate;
        csd->DialType = target->DialType;
        return;
    }
#endif /* __TCPIP_OVER_CSD__ */
    if (target->bearer_type == SRV_DTCNT_BEARER_GPRS)
    {
        gprs->prof_common_header.Auth_info.AuthType = target->auth_info.AuthType;
        gprs->APN = target->dest_name;
    }
}

srv_dtcnt_result_enum srv_dtcnt_db_store_parse_prof(void *raw_data, U32 data_size, srv_dtcnt_prof_common_header_struct *comm_header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 length;
    U8 *cur_pos = NULL;
    U32 type;    
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!comm_header || !raw_data || !data_size)
    {
        return SRV_DTCNT_RESULT_INVALID_INPUT;
    }

    cur_pos = raw_data;
    while (data_size)
    {

        srv_dtcnt_n2l(cur_pos, type);
        srv_dtcnt_n2s(cur_pos, length);
        //data = cur_pos;

        switch (type)
        {
            /* MISC INFO */
            case SRV_DTCNT_PROF_FIELD_USER_DATA:
                {
                    U32 tmp_user_data;
                    //comm_header->user_data = (void *)*user_data;
                    srv_dtcnt_n2l(cur_pos, tmp_user_data);
                    comm_header->user_data = (void *)tmp_user_data;
                    MMI_ASSERT(length == sizeof(U32));
                }
                break;
            case SRV_DTCNT_PROF_FIELD_HOME:
                {
                    MMI_ASSERT(length <= SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN);
                    kal_mem_cpy(comm_header->HomePage, cur_pos, length);
                    cur_pos += length;
                }
                break;


            /* INET INFO */
            case SRV_DTCNT_PROF_FIELD_INET_IP:
                {
                    MMI_ASSERT(length == SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
                    kal_mem_cpy(comm_header->StaicIPAddr, cur_pos, length);
                    cur_pos += length;
                }
                break;
            case SRV_DTCNT_PROF_FIELD_INET_MASK:
                {
                    MMI_ASSERT(length == SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
                    kal_mem_cpy(comm_header->NetMask, cur_pos, length);
                    cur_pos += length;
                }
                break;

            /* PROXY INFO */
            case SRV_DTCNT_PROF_FIELD_PX_ADDR:
                {
                    MMI_ASSERT(length <= SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN);
                    kal_mem_cpy(comm_header->px_addr, cur_pos, length);
                    comm_header->px_addr[length] = 0;
                    cur_pos += length;
                }
                break;
            case SRV_DTCNT_PROF_FIELD_PX_PORT:
                {
                    //U16 *port = data;
                    //comm_header->px_port = *port;
                    srv_dtcnt_n2s(cur_pos, comm_header->px_port);
                    MMI_ASSERT(length == sizeof(U16));
                }
                break;
            case SRV_DTCNT_PROF_FIELD_PX_AUTH_ID:
                {
                    MMI_ASSERT(length <= SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN);
                    kal_mem_cpy(comm_header->px_authid, cur_pos, length);
                    cur_pos += length;
                }
                break;
            case SRV_DTCNT_PROF_FIELD_PX_AUTH_PW:
                {
                    MMI_ASSERT(length <= SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN);
                    kal_mem_cpy(comm_header->px_authpw, cur_pos, length);
                    cur_pos += length;
                }
                break;
            default: /* ignore */
                break;
        }
        data_size -= (length + 6);        
    }

    return SRV_DTCNT_RESULT_SUCCESS;
}

srv_dtcnt_result_enum srv_dtcnt_db_store_load_prof(srv_dtcnt_account_info_st *target, void *out_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *ucs2_filename = NULL;
    int fp, fs_err;
    U32 size, read;
    void *raw_data = NULL;
    srv_dtcnt_result_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!out_data || !target)
    {
        return SRV_DTCNT_RESULT_INVALID_INPUT;
    }

    srv_dtcnt_db_compose_acc_path(
                            &ucs2_filename,        
                            (U8)target->acc_id, 
                            target->acc_type,
                            target->sim_info);
    if (!ucs2_filename)
    {
        MMI_ASSERT(0);
    }    
        
    fp = FS_Open(ucs2_filename, FS_READ_ONLY);
    if (fp < FS_NO_ERROR)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_LOAD_PROF_FOPEN_FS_ERR, fp);
        goto load_fs_error;
    }
    OslMfree(ucs2_filename);

    /* Load the profile file */
    fs_err = FS_GetFileSize(fp, (UINT *)&(size));
    if (fs_err < FS_NO_ERROR)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_LOAD_PROF_FSIZE_FS_ERR, fs_err);
        goto load_fs_error;
    }
    raw_data = OslMalloc(size);
    fs_err = FS_Read(fp, raw_data, size, (UINT *)&read);
    if (fs_err < FS_NO_ERROR || read != size)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_LOAD_PROF_FREAD_FS_ERR, fs_err);
        goto load_fs_error;
    }
    FS_Close(fp);

    ret = srv_dtcnt_db_store_parse_prof(raw_data, size, (srv_dtcnt_prof_common_header_struct *)out_data);

    OslMfree(raw_data);
    return ret;
    
load_fs_error:
    if (ucs2_filename)
    {
        OslMfree(ucs2_filename);
    }
    FS_Close(fp);
    
    if (raw_data)
    {
        OslMfree(raw_data);
    }
    return SRV_DTCNT_RESULT_FS_ERROR;
}

srv_dtcnt_result_enum srv_dtcnt_db_store_detail_prof_fillin(void *dest, srv_dtcnt_account_info_st *target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dtcnt_db_store_acc_info_fillin(dest, target);
    return srv_dtcnt_db_store_load_prof(target, dest);
}


srv_dtcnt_result_enum srv_dtcnt_db_store_add_wlan_prof(srv_dtcnt_prof_wlan_struct *data, U32 fields, U32 *out_acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
    int i, error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(fields == SRV_DTCNT_WLAN_PROF_FIELD_ALL);
    
    /* Find an empty slot index first */
    for (i = 0; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; ++i)
    {
        if (g_srv_dtcnt_wlan_prof_list[i].ssid_len == 0) 
        {
            break;
        }
    }
    /* If there is no empty slot, replay a same-type one, if no same type, not replace */
    if (i == SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM)
    {
        for (i = 0; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; i++)
        {
            if (data->network_type == g_srv_dtcnt_wlan_prof_list_p[i]->network_type)
            {
                
                U32 profile_id = g_srv_dtcnt_wlan_prof_list_p[i]->profile_id;
                U8 priority = g_srv_dtcnt_wlan_prof_list_p[i]->priority;
                
                kal_mem_cpy(g_srv_dtcnt_wlan_prof_list_p[i], data, sizeof(srv_dtcnt_prof_wlan_struct));
                g_srv_dtcnt_wlan_prof_list_p[i]->profile_id = profile_id;
                g_srv_dtcnt_wlan_prof_list_p[i]->priority = priority;
                *out_acc_id = g_srv_dtcnt_wlan_prof_list_p[i]->profile_id;
                break;
            }
        }
        if (i == SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM)
        {
            *out_acc_id = 0;
            return SRV_DTCNT_RESULT_STORE_FULL;
        }        
    }
    else /* found empty slot */
    {
        srv_dtcnt_wlan_save_profiles((U8)i, 0, SRV_DTCNT_WLAN_NETWORK_TYPE_TOTAL, data);
        *out_acc_id = g_srv_dtcnt_wlan_prof_list[i].profile_id;
    }

    //srv_dtcnt_db_atomic_begin(SRV_DTCNT_DB_TRANS_ADD, g_srv_dtcnt_wlan_prof_list_p[i]->profile_id);
    if (WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, (void*)&g_srv_dtcnt_wlan_setting_ctx, NVRAM_MAX_WLAN_SETTING_SIZE, (S16 *)&error) 
        <NVRAM_MAX_WLAN_SETTING_SIZE)
    {
        MMI_ASSERT(0);
    }
    
    for (i = 0; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; i++)
    {
        if (WriteRecord(NVRAM_EF_WLAN_PROFILE_LID, (U16)(i + 1), (void*)&g_srv_dtcnt_wlan_prof_list[i], NVRAM_MAX_WLAN_PROFILE_SIZE, (S16 *)&error) 
            < NVRAM_MAX_WLAN_PROFILE_SIZE)
        {
            MMI_ASSERT(0);
        }
    }
    //srv_dtcnt_db_atomic_end();
    return SRV_DTCNT_RESULT_SUCCESS;
#else /* !__MMI_WLAN_FEATURES__ */
    return SRV_DTCNT_RESULT_FAILED;
#endif /* __MMI_WLAN_FEATURES__ */
}

MMI_BOOL srv_dtcnt_db_store_acc_info_compose(void *data, U32 fields, srv_dtcnt_account_info_st *target)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_prof_common_header_struct *comm_header = data;
    U8 temp_ascii_acct_no[3] = {0,};   /* xx + null terminate */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(fields & SRV_DTCNT_PROF_FIELD_NAME) ||
        !(fields & SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM) ||
        !(fields & SRV_DTCNT_PROF_FIELD_ACC_TYPE) ||
        !(fields & SRV_DTCNT_PROF_FIELD_SIM_TYPE))
    {
        return MMI_FALSE;
    }

    kal_mem_set(target->acc_name, 0, (SRV_DTCNT_PROF_MAX_ACC_NAME_LEN+1) * ENCODING_LENGTH);
    if (mmi_ucs2strlen((const CHAR *)comm_header->AccountName))
    {
        mmi_ucs2ncpy((char *)target->acc_name, (char *)comm_header->AccountName, SRV_DTCNT_PROF_MAX_ACC_NAME_LEN);
    }
    else
    {
        mmi_ucs2cpy((CHAR *)target->acc_name, (const CHAR *)L"Account ");
        sprintf((char *)temp_ascii_acct_no, "%d", (target->acc_id+1));
        mmi_asc_n_to_ucs2((CHAR *) (target->acc_name + 16), (CHAR *) temp_ascii_acct_no, 2);
    }

    target->acc_type = comm_header->acct_type;
    target->sim_info = comm_header->sim_info;
    target->fields |= (SRV_DTCNT_PROF_FIELD_NAME | SRV_DTCNT_PROF_FIELD_ACC_TYPE | SRV_DTCNT_PROF_FIELD_SIM_TYPE);
    
    if (fields & SRV_DTCNT_PROF_FIELD_PX_SRV_TYPE)
    {
        target->px_service = comm_header->px_service;
        target->fields |= SRV_DTCNT_PROF_FIELD_PX_SRV_TYPE;
    }

    if (fields & SRV_DTCNT_PROF_FIELD_USE_PX)
    {
        target->use_proxy = comm_header->use_proxy;
        target->fields |= SRV_DTCNT_PROF_FIELD_USE_PX;
    }

    if (fields & SRV_DTCNT_PROF_FIELD_APP_TYPE)
    {
        target->app_type = comm_header->AppType;
        target->fields |= SRV_DTCNT_PROF_FIELD_APP_TYPE;
    }

    if (fields & SRV_DTCNT_PROF_FIELD_AUTH_USER_ID)
    {
        kal_mem_cpy(target->auth_info.UserName, comm_header->Auth_info.UserName, SRV_DTCNT_PROF_MAX_USER_LEN+1);
        target->fields |= SRV_DTCNT_PROF_FIELD_AUTH_USER_ID;
    }

    if (fields & SRV_DTCNT_PROF_FIELD_AUTH_USER_PW)
    {
        kal_mem_cpy(target->auth_info.Passwd, comm_header->Auth_info.Passwd, SRV_DTCNT_PROF_MAX_PW_LEN+1);
        target->fields |= SRV_DTCNT_PROF_FIELD_AUTH_USER_PW;
    }

    if (fields & SRV_DTCNT_PROF_FIELD_INET_PRI_DNS)
    {
        kal_mem_cpy(target->PrimaryAddr, comm_header->PrimaryAddr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        target->fields |= SRV_DTCNT_PROF_FIELD_INET_PRI_DNS;
    }

    if (fields & SRV_DTCNT_PROF_FIELD_INET_SEC_DNS)
    {
        kal_mem_cpy(target->SecondaryAddr, comm_header->SecondaryAddr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        target->fields |= SRV_DTCNT_PROF_FIELD_INET_SEC_DNS;
    }

    if (fields & SRV_DTCNT_PROF_FIELD_HASH_VAL)
    {
        kal_mem_cpy(target->napid_hash_val, comm_header->napid_hash_val, SRV_DTCNT_NAPID_HASH_LEN);
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
        kal_mem_cpy(target->provurl_hash_val, comm_header->provurl_hash_val, SRV_DTCNT_PROVURL_HASH_LEN);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
        target->fields |= SRV_DTCNT_PROF_FIELD_HASH_VAL;
    }

    if (fields & SRV_DTCNT_PROF_FIELD_READONLY)
    {
        target->readonly = comm_header->read_only;
    }
#ifdef __MMI_GPRS_FEATURES__
    if (target->bearer_type == SRV_DTCNT_BEARER_GPRS)
    {
        srv_dtcnt_prof_gprs_struct *gprs = (srv_dtcnt_prof_gprs_struct *)data;
        strcpy((CHAR *)target->dest_name, (CHAR *)gprs->APN);
        target->fields |= SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM;
        if (fields & SRV_DTCNT_PROF_FIELD_AUTH_TYPE)
        {
            target->auth_info.AuthType = gprs->prof_common_header.Auth_info.AuthType;
            target->fields |= SRV_DTCNT_PROF_FIELD_AUTH_TYPE;
        }
        return MMI_TRUE;
    }
#endif /* __MMI_GPRS_FEATURES__ */

#ifdef __TCPIP_OVER_CSD__
    if (target->bearer_type == SRV_DTCNT_BEARER_CSD)
    {
        srv_dtcnt_prof_csd_struct *csd = (srv_dtcnt_prof_csd_struct *)data;
        strcpy((CHAR *)target->dest_name, (CHAR *)csd->DialNumber);
        target->fields |= SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM;
        if (fields & SRV_DTCNT_PROF_FIELD_DIAL_TYPE)
        {
            target->DialType = csd->DialType;
            target->fields |= SRV_DTCNT_PROF_FIELD_DIAL_TYPE;
        }
        if (fields & SRV_DTCNT_PROF_FIELD_DATA_RATE)
        {
            target->DataRate = csd->DataRate;
            target->fields |= SRV_DTCNT_PROF_FIELD_DATA_RATE;
        }
        return MMI_TRUE;
    }
#endif /* __TCPIP_OVER_CSD__ */

    return MMI_FALSE;
}

MMI_BOOL srv_dtcnt_db_store_compose_prof(void *data, U32 active_fields, void **raw_data, U32 *data_size, int idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_prof_common_header_struct *comm_header = data;
    U32 size = 0;
    U8 *cur_pos;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!raw_data || !data_size || !data)
    {
        return MMI_FALSE;
    }
    /* MISC INFO */
    if (active_fields & SRV_DTCNT_PROF_FIELD_USER_DATA)
    {
        size += (6 + sizeof(U32));
    }
    if (active_fields & SRV_DTCNT_PROF_FIELD_HOME)
    {
        size += (6 + strlen((CHAR *)comm_header->HomePage));
    }

    /* INET INFO */
    if (active_fields & SRV_DTCNT_PROF_FIELD_INET_IP)
    {
        size += (6 + SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }
    if (active_fields & SRV_DTCNT_PROF_FIELD_INET_MASK)
    {
        size += (6 + SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }
    /* PROXY INFO */
    if (active_fields & SRV_DTCNT_PROF_FIELD_PX_ADDR)
    {
        size += (6 + strlen((CHAR *)comm_header->px_addr));
    }
    if (active_fields & SRV_DTCNT_PROF_FIELD_PX_AUTH_ID)
    {
        size += (6 + strlen((CHAR *)comm_header->px_authid));
    }
    if (active_fields & SRV_DTCNT_PROF_FIELD_PX_AUTH_PW)
    {
        size += (6 + strlen((CHAR *)comm_header->px_authpw));
    }    
    if (active_fields & SRV_DTCNT_PROF_FIELD_PX_PORT)
    {
        size += (6 + sizeof(U16));
    }

    if (!size)
    {
        *raw_data = NULL;
        *data_size = 0;
        return MMI_TRUE;
    }
    
    cur_pos = *raw_data = OslMalloc(size);
    *data_size = size;
    /* MISC INFO */
    if (active_fields & SRV_DTCNT_PROF_FIELD_USER_DATA)
    {
        //const void *user_data;

        srv_dtcnt_l2n(SRV_DTCNT_PROF_FIELD_USER_DATA, cur_pos);
        srv_dtcnt_s2n(sizeof(U32), cur_pos);

        //user_data = (const void *)cur_pos;
        //user_data = comm_header->user_data;
        cur_pos += sizeof(PU32);
        g_srv_dtcnt_store_ctx.acc_list[idx].fields |= SRV_DTCNT_PROF_FIELD_USER_DATA;        
    }
    if (active_fields & SRV_DTCNT_PROF_FIELD_HOME)
    {
        srv_dtcnt_l2n(SRV_DTCNT_PROF_FIELD_HOME, cur_pos);
        srv_dtcnt_s2n((strlen((CHAR*)comm_header->HomePage)), cur_pos);
        
        strcpy((CHAR *)cur_pos, (CHAR*)comm_header->HomePage);
        cur_pos += strlen((CHAR*)comm_header->HomePage);
        g_srv_dtcnt_store_ctx.acc_list[idx].fields |= SRV_DTCNT_PROF_FIELD_HOME;        
    }

    /* INET INFO */
    if (active_fields & SRV_DTCNT_PROF_FIELD_INET_IP)
    {
        srv_dtcnt_l2n(SRV_DTCNT_PROF_FIELD_INET_IP, cur_pos);
        srv_dtcnt_s2n(SRV_DTCNT_PROF_MAX_IP_ADDR_LEN, cur_pos);
        
        kal_mem_cpy(cur_pos, comm_header->StaicIPAddr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        cur_pos += SRV_DTCNT_PROF_MAX_IP_ADDR_LEN;
        g_srv_dtcnt_store_ctx.acc_list[idx].fields |= SRV_DTCNT_PROF_FIELD_INET_IP;
    }
    if (active_fields & SRV_DTCNT_PROF_FIELD_INET_MASK)
    {
        srv_dtcnt_l2n(SRV_DTCNT_PROF_FIELD_INET_MASK, cur_pos);
        srv_dtcnt_s2n(SRV_DTCNT_PROF_MAX_IP_ADDR_LEN, cur_pos);
        
        kal_mem_cpy(cur_pos, comm_header->NetMask, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        cur_pos += SRV_DTCNT_PROF_MAX_IP_ADDR_LEN;
        g_srv_dtcnt_store_ctx.acc_list[idx].fields |= SRV_DTCNT_PROF_FIELD_INET_MASK;
    }
    /* PROXY INFO */
    if (active_fields & SRV_DTCNT_PROF_FIELD_PX_ADDR)
    {
        srv_dtcnt_l2n(SRV_DTCNT_PROF_FIELD_PX_ADDR, cur_pos);
        srv_dtcnt_s2n(strlen((CHAR *)comm_header->px_addr), cur_pos);        

        kal_mem_cpy(cur_pos, comm_header->px_addr, strlen((CHAR *)comm_header->px_addr));
        cur_pos += strlen((CHAR *)comm_header->px_addr);
        g_srv_dtcnt_store_ctx.acc_list[idx].fields |= SRV_DTCNT_PROF_FIELD_PX_ADDR;
    }
    if (active_fields & SRV_DTCNT_PROF_FIELD_PX_AUTH_ID)
    {
        srv_dtcnt_l2n(SRV_DTCNT_PROF_FIELD_PX_AUTH_ID, cur_pos);
        srv_dtcnt_s2n((strlen((CHAR*)comm_header->px_authid)), cur_pos);
        
        strcpy((CHAR *)cur_pos, (CHAR *)comm_header->px_authid);
        cur_pos += strlen((CHAR*)comm_header->px_authid);
        g_srv_dtcnt_store_ctx.acc_list[idx].fields |= SRV_DTCNT_PROF_FIELD_PX_AUTH_ID;
    }
    if (active_fields & SRV_DTCNT_PROF_FIELD_PX_AUTH_PW)
    {
        srv_dtcnt_l2n(SRV_DTCNT_PROF_FIELD_PX_AUTH_PW, cur_pos);
        srv_dtcnt_s2n((strlen((CHAR*)comm_header->px_authpw)), cur_pos);
        
        strcpy((CHAR *)cur_pos, (CHAR *)comm_header->px_authpw);
        cur_pos += strlen((CHAR*)comm_header->px_authpw);
        g_srv_dtcnt_store_ctx.acc_list[idx].fields |= SRV_DTCNT_PROF_FIELD_PX_AUTH_PW;        
    }    
    if (active_fields & SRV_DTCNT_PROF_FIELD_PX_PORT)
    {
        srv_dtcnt_l2n(SRV_DTCNT_PROF_FIELD_PX_PORT, cur_pos);
        srv_dtcnt_s2n(sizeof(U16), cur_pos);

        srv_dtcnt_s2n(comm_header->px_port, cur_pos);
        g_srv_dtcnt_store_ctx.acc_list[idx].fields |= SRV_DTCNT_PROF_FIELD_PX_PORT;
    }
    MMI_ASSERT(((U32)cur_pos - (U32)(*raw_data)) == size);
    return MMI_TRUE;
}
U8 srv_dtcnt_get_account_num(srv_dtcnt_sim_type_enum sim_info)
{
    U8 i = 0;
    U8 count = 0;
    for(i = 0; i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
        if(g_srv_dtcnt_store_ctx.acc_list[i].in_use == 1 && 
            g_srv_dtcnt_store_ctx.acc_list[i].sim_info == sim_info)
        {
            count++;
        }
    }
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_ACCOUNT_NUM,  sim_info, count);
    return count;
}
srv_dtcnt_result_enum srv_dtcnt_db_store_add_prof(void *data, U32 fields, srv_dtcnt_bearer_enum type, U32 *out_acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    kal_wchar *ucs2_filename = NULL;
    void *raw_data = NULL;
    U32 data_size, active_fields;
    srv_dtcnt_result_enum ret;
    MMI_BOOL is_normal_prof_full = MMI_TRUE;
    srv_dtcnt_prof_common_header_struct *comm_header = data;
    int default_index = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ( (g_srv_dtcnt_store_ctx.ctrl_block.total_acc_num >= (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM + SRV_DTCNT_RESERVED_DM_ACC_NUM))
        ||(SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM == srv_dtcnt_get_account_num(comm_header->sim_info)) )
    {
        *out_acc_id = 0;
        return SRV_DTCNT_RESULT_STORE_FULL;
    }
    
    if (!fields)
    {
        return SRV_DTCNT_RESULT_INVALID_INPUT;
    }

    if (type == SRV_DTCNT_BEARER_GPRS)
    {
        active_fields = fields & g_srv_dtcnt_store_ctx.ctrl_block.gprs_fields;
    }
    else
    {
        active_fields = fields & g_srv_dtcnt_store_ctx.ctrl_block.csd_fields;
    }

    /* find empty slot */
    for (i = 0; i<SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
#ifdef SYNCML_DM_SUPPORT
        int dm_check = srv_dtcnt_db_store_check_dm_acc(&i, type, data);
        if (dm_check == 1)
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_ADD_DM_PROF, i, type);
            //g_srv_dtcnt_store_ctx.acc_list[i].in_use = 0;
        }
        else if (dm_check == 0)
        {
            /* ignore DM accounts */
            return SRV_DTCNT_RESULT_FAILED;
        }
#else /* !SYNCML_DM_SUPPORT */
        srv_dtcnt_prof_common_header_struct *comm_header = data;
        if (comm_header->AppType & DTCNT_APPTYPE_DM)
        {
            /* ignore DM accounts */
            return SRV_DTCNT_RESULT_FAILED;
        }
//#ifdef __CCA_SUPPORT__
#ifdef __MMI_CCA_SUPPORT__
            if (g_srv_dtcnt_ota_ongoing == MMI_TRUE && g_srv_dtcnt_ota_ctx.replace_acct_index != 0)
            {
                i = g_srv_dtcnt_ota_ctx.replace_acct_index - 1;
            }
#endif 

#endif /* SYNCML_DM_SUPPORT */
        if (!g_srv_dtcnt_store_ctx.acc_list[i].in_use)
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_ADD_NORMAL_PROF, i, type);
            kal_mem_set(&(g_srv_dtcnt_store_ctx.acc_list[i]), 0, sizeof(srv_dtcnt_account_info_st));
            g_srv_dtcnt_store_ctx.acc_list[i].bearer_type = type;
            g_srv_dtcnt_store_ctx.acc_list[i].acc_id = i;
            if (!srv_dtcnt_db_store_acc_info_compose(data, active_fields, &(g_srv_dtcnt_store_ctx.acc_list[i])))
            {
                return SRV_DTCNT_RESULT_INVALID_INPUT;
            }            
            
            srv_dtcnt_db_compose_acc_path(
                            &ucs2_filename,                 
                            (U8)(g_srv_dtcnt_store_ctx.acc_list[i].acc_id),
                            g_srv_dtcnt_store_ctx.acc_list[i].acc_type,
                            g_srv_dtcnt_store_ctx.acc_list[i].sim_info);
            if (!srv_dtcnt_db_store_compose_prof(data, active_fields, &raw_data, &data_size, i))
            {
                return SRV_DTCNT_RESULT_FAILED;
            }            
            is_normal_prof_full = MMI_FALSE;
            break;
        }
    }

    if (is_normal_prof_full)
    {
        *out_acc_id = 0;
        return SRV_DTCNT_RESULT_STORE_FULL;
    }

    if (raw_data)
    {
        srv_dtcnt_db_atomic_begin(SRV_DTCNT_DB_TRANS_ADD, g_srv_dtcnt_store_ctx.acc_list[i].acc_id);
        ret = srv_dtcnt_db_fileio_save_data(ucs2_filename, raw_data, data_size);
        if (ret == SRV_DTCNT_RESULT_FS_ERROR)
        {
            ret = SRV_DTCNT_RESULT_FAILED;
            goto add_prof_end;
        }
    }
    g_srv_dtcnt_store_ctx.ctrl_block.total_acc_num++;
    g_srv_dtcnt_store_ctx.acc_list[i].in_use = 1;
    if (g_srv_dtcnt_store_ctx.acc_list[i].app_type & DTCNT_APPTYPE_DEF)
    {
        default_index = g_srv_dtcnt_store_ctx.default_acc_idx[comm_header->sim_info - 1];
        if(default_index != 0)
        {
            g_srv_dtcnt_store_ctx.acc_list[default_index-1].app_type &= ~DTCNT_APPTYPE_DEF;
        }
        g_srv_dtcnt_store_ctx.default_acc_idx[comm_header->sim_info - 1] = i+1;
    }

    if (!srv_dtcnt_db_fileio_write_store_info_file())
    {
        g_srv_dtcnt_store_ctx.ctrl_block.total_acc_num--;
        g_srv_dtcnt_store_ctx.acc_list[i].in_use = 0;
        g_srv_dtcnt_store_ctx.default_acc_idx[comm_header->sim_info - 1] = 0;
        FS_Delete(ucs2_filename);
        ret = SRV_DTCNT_RESULT_FAILED;        
    }
    else
    {
		/* APP_INFO_MODIFY */
        if (g_srv_dtcnt_store_sync_done)
        {
            srv_dtcnt_db_store_send_abm_acc_info(SRV_DTCNT_DB_TRANS_ADD, i, 0);
            srv_dtcnt_db_store_send_acc_update_post_evt(g_srv_dtcnt_store_ctx.acc_list[i].acc_id,
                                            g_srv_dtcnt_store_ctx.acc_list[i].sim_info,
                                            0, 2);            
        }
        *out_acc_id = (U32)g_srv_dtcnt_store_ctx.acc_list[i].acc_id;
        ret = SRV_DTCNT_RESULT_SUCCESS;
    }
add_prof_end:
    srv_dtcnt_db_atomic_end();
	if (raw_data)
		OslMfree(raw_data);
	if (ucs2_filename)
		OslMfree(ucs2_filename);
    return ret;
}

#ifdef __MMI_WLAN_FEATURES__
void srv_dtcnt_db_store_update_wlan_prof_val(srv_dtcnt_prof_wlan_struct *data, U32 fields, int i)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U8 j;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_NAME)
    {
        app_ucs2_strncpy((kal_int8 *)g_srv_dtcnt_wlan_prof_list[i].ProfName, (kal_int8 *)data->ProfName, SRV_DTCNT_PROF_MAX_WLAN_PROF_NAME_LEN);
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_SSID)
    {
        strcpy((CHAR *)g_srv_dtcnt_wlan_prof_list[i].ssid, (CHAR *)data->ssid);
        g_srv_dtcnt_wlan_prof_list[i].ssid_len = strlen((CHAR*)g_srv_dtcnt_wlan_prof_list[i].ssid);
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_IP)
    {
        kal_mem_cpy(g_srv_dtcnt_wlan_prof_list[i].ip_addr, data->ip_addr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_NETMASK)
    {
        kal_mem_cpy(g_srv_dtcnt_wlan_prof_list[i].netmask, data->netmask, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_GATEWAY)
    {
        kal_mem_cpy(g_srv_dtcnt_wlan_prof_list[i].gateway, data->gateway, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_DNS1)
    {
        kal_mem_cpy(g_srv_dtcnt_wlan_prof_list[i].dns1, data->dns1, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_DNS2)
    {
        kal_mem_cpy(g_srv_dtcnt_wlan_prof_list[i].dns2, data->dns2, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_DHCP)
    {
        g_srv_dtcnt_wlan_prof_list[i].use_dhcp = data->use_dhcp;
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_AUTH_TYPE)
    {
        g_srv_dtcnt_wlan_prof_list[i].auth_mode = data->auth_mode;
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_ENCRYPT_TYPE)
    {
        g_srv_dtcnt_wlan_prof_list[i].encrypt_mode = data->encrypt_mode;
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_ROOT_CERT_SETTINGS)
    {
        g_srv_dtcnt_wlan_prof_list[i].root_ca_id = data->root_ca_id;
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_USER_CERT_SETTINGS)
    {
        g_srv_dtcnt_wlan_prof_list[i].client_ca_id = data->client_ca_id;
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_PASSPHRASE)
    {
        kal_mem_cpy(g_srv_dtcnt_wlan_prof_list[i].passphrase, data->passphrase, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN+1);
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_PRIVKEY_PASS)
    {
        kal_mem_cpy(g_srv_dtcnt_wlan_prof_list[i].private_key_passwd, data->private_key_passwd, SRV_DTCNT_PROF_MAX_PW_LEN+1);
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_PSK)
    {
        kal_mem_cpy(g_srv_dtcnt_wlan_prof_list[i].psk, data->psk, SRV_DTCNT_PROF_MAX_PSK_LEN);
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_WEP_KEY_SETTINGS)
    {
        kal_mem_cpy(g_srv_dtcnt_wlan_prof_list[i].wep_key, data->wep_key, SRV_DTCNT_PROF_MAX_WEP_KEY_LEN+1);
        g_srv_dtcnt_wlan_prof_list[i].wep_key_index = data->wep_key_index;
        g_srv_dtcnt_wlan_prof_list[i].wep_key_len = data->wep_key_len;
        g_srv_dtcnt_wlan_prof_list[i].wep_key_format = data->wep_key_format;
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_EAP_AUTH_SETTINGS)
    {
        g_srv_dtcnt_wlan_prof_list[i].eap_auth_type = data->eap_auth_type;
        g_srv_dtcnt_wlan_prof_list[i].eap_peap_auth_type = data->eap_peap_auth_type;
        g_srv_dtcnt_wlan_prof_list[i].eap_ttls_auth_type = data->eap_ttls_auth_type;
        g_srv_dtcnt_wlan_prof_list[i].peap_version = data->peap_version;
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_USER)
    {
        kal_mem_cpy(g_srv_dtcnt_wlan_prof_list[i].username, data->username, SRV_DTCNT_PROF_MAX_USER_LEN+1);
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_PW)
    {
        kal_mem_cpy(g_srv_dtcnt_wlan_prof_list[i].password, data->password, SRV_DTCNT_PROF_MAX_PW_LEN+1);
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_HOME)
    {
        kal_mem_cpy(g_srv_dtcnt_wlan_prof_list[i].HomePage, data->HomePage, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1);
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_PX_ADDR)
    {
        kal_mem_cpy(g_srv_dtcnt_wlan_prof_list[i].px_addr, data->px_addr, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN+1);
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_PX_PORT)
    {
        g_srv_dtcnt_wlan_prof_list[i].px_port = data->px_port;
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_PX_AUTH_ID)
    {
        kal_mem_cpy(g_srv_dtcnt_wlan_prof_list[i].px_authid, data->px_authid, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN+1);
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_PX_AUTH_PW)
    {
        kal_mem_cpy(g_srv_dtcnt_wlan_prof_list[i].px_authpw, data->px_authpw, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN+1);
    }
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_USE_PX)
    {
        g_srv_dtcnt_wlan_prof_list[i].use_proxy = data->use_proxy;
    }

#ifdef __WAPI_SUPPORT__
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_WAPI_SETTINGS)
    {
        kal_mem_cpy(g_srv_dtcnt_wlan_prof_list[i].wapi_psk_str, data->wapi_psk_str, SRV_DTCNT_WAPI_PSK_STR_LEN);
        kal_mem_cpy(g_srv_dtcnt_wlan_prof_list[i].wapi_private_key_passwd_str, data->wapi_private_key_passwd_str, SRV_DTCNT_PROF_MAX_PW_LEN+2);
        g_srv_dtcnt_wlan_prof_list[i].wapi_ase_id = data->wapi_ase_id;
        g_srv_dtcnt_wlan_prof_list[i].wapi_client_id = data->wapi_client_id;
        g_srv_dtcnt_wlan_prof_list[i].wapi_psk_format = data->wapi_psk_format;
    }
#endif /* __WAPI_SUPPORT__ */

    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_NET_TYPE)
    {
        if (fields & SRV_DTCNT_WLAN_PROF_FIELD_PRIORITY)
        {
            if (g_srv_dtcnt_wlan_prof_list[i].network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA &&
                data->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC)
            {
                g_srv_dtcnt_wlan_setting_ctx.infra_prof_num--;
                g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num++;
            }
            if (g_srv_dtcnt_wlan_prof_list[i].network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC &&
                data->network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
            {
                g_srv_dtcnt_wlan_setting_ctx.infra_prof_num++;
                g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num--;
            }
            /* update wlan setting for profile number changed */
            if (WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_srv_dtcnt_wlan_setting_ctx, NVRAM_MAX_WLAN_SETTING_SIZE, &error) <
                NVRAM_MAX_WLAN_SETTING_SIZE)
            {
                ASSERT(0);
            }
            
            g_srv_dtcnt_wlan_prof_list[i].network_type = data->network_type;
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_UPDATE_WLAN_PROF_WARNING);
        }
    }
    
    /* update ap profile priority */
    if (fields & SRV_DTCNT_WLAN_PROF_FIELD_PRIORITY &&
        g_srv_dtcnt_wlan_prof_list[i].priority != data->priority)
    {
            g_srv_dtcnt_wlan_prof_list_p[(data->priority -1)] = &g_srv_dtcnt_wlan_prof_list[i];
            g_srv_dtcnt_wlan_prof_list[i].priority = data->priority;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
    }
    if(fields & SRV_DTCNT_WLAN_PROF_FIELD_AP_TYPE)
    {
        g_srv_dtcnt_wlan_prof_list[i].ap_type = data->ap_type;
    }


//    return 0;
}
#endif /* __MMI_WLAN_FEATURES__ */

srv_dtcnt_result_enum srv_dtcnt_db_store_update_wlan_prof(srv_dtcnt_prof_wlan_struct *data, U32 fields, U32 prof_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
    int i, error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* Find specified slot first */
    for (i = 0; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; ++i)
    {
        if (g_srv_dtcnt_wlan_prof_list[i].profile_id == prof_id) 
        {
            break;
        }
    }
    
    /* If can't found */
    if (i == SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM)
    {
        return SRV_DTCNT_RESULT_INVALID_INPUT;
    }
    else /* found specified slot */
    {        
        srv_dtcnt_db_store_update_wlan_prof_val(data, fields, i);

        if (g_srv_dtcnt_wlan_prof_list[i].priority > 0)
        {
            if (WriteRecord(NVRAM_EF_WLAN_PROFILE_LID, (U16)(i + 1), (void*)&g_srv_dtcnt_wlan_prof_list[i], NVRAM_MAX_WLAN_PROFILE_SIZE, (S16 *)&error) < NVRAM_MAX_WLAN_PROFILE_SIZE)
            {
                MMI_ASSERT(0);
            }
        }
    }

    return SRV_DTCNT_RESULT_SUCCESS;
#else /* !__MMI_WLAN_FEATURES__ */
    return SRV_DTCNT_RESULT_FAILED;
#endif /* __MMI_WLAN_FEATURES__ */
}

MMI_BOOL srv_dtcnt_db_store_acc_info_update(void *data, U32 fields, srv_dtcnt_account_info_st *target, U8 *sim_changed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_prof_common_header_struct *comm_header = data;
    MMI_BOOL file_name_changed = MMI_FALSE;
	U8 temp_ascii_acct_no[3] = {0,0,0}; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((fields & SRV_DTCNT_PROF_FIELD_ACC_TYPE) &&
        (target->acc_type != comm_header->acct_type))
    {       
        target->acc_type = comm_header->acct_type;
        file_name_changed = MMI_TRUE;
    }
    if ((fields & SRV_DTCNT_PROF_FIELD_SIM_TYPE) &&
        (target->sim_info != comm_header->sim_info))
    {
        g_srv_dtcnt_context.acct_update_evt_sim_id_old = target->sim_info;
        target->sim_info = comm_header->sim_info;
        file_name_changed = MMI_TRUE;
        *sim_changed = 1;
    }
    if (fields & SRV_DTCNT_PROF_FIELD_PX_SRV_TYPE)
    {
        target->px_service = comm_header->px_service;
        target->fields |= SRV_DTCNT_PROF_FIELD_PX_SRV_TYPE;
    }

    if (fields & SRV_DTCNT_PROF_FIELD_USE_PX)
    {
        target->use_proxy = comm_header->use_proxy;
        target->fields |= SRV_DTCNT_PROF_FIELD_USE_PX;
    }

    if (fields & SRV_DTCNT_PROF_FIELD_APP_TYPE)
    {
        target->app_type = comm_header->AppType;
        target->fields |= SRV_DTCNT_PROF_FIELD_APP_TYPE;
    }   

    if (fields & SRV_DTCNT_PROF_FIELD_AUTH_USER_ID)
    {
        kal_mem_cpy(target->auth_info.UserName, comm_header->Auth_info.UserName, SRV_DTCNT_PROF_MAX_USER_LEN+1);
        target->fields |= SRV_DTCNT_PROF_FIELD_AUTH_USER_ID;
    }

    if (fields & SRV_DTCNT_PROF_FIELD_AUTH_USER_PW)
    {
        kal_mem_cpy(target->auth_info.Passwd, comm_header->Auth_info.Passwd, SRV_DTCNT_PROF_MAX_PW_LEN+1);
        target->fields |= SRV_DTCNT_PROF_FIELD_AUTH_USER_PW;
    }

    if (fields & SRV_DTCNT_PROF_FIELD_INET_PRI_DNS)
    {
        kal_mem_cpy(target->PrimaryAddr, comm_header->PrimaryAddr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        target->fields |= SRV_DTCNT_PROF_FIELD_INET_PRI_DNS;
    }

    if (fields & SRV_DTCNT_PROF_FIELD_INET_SEC_DNS)
    {
        kal_mem_cpy(target->SecondaryAddr, comm_header->SecondaryAddr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
        target->fields |= SRV_DTCNT_PROF_FIELD_INET_SEC_DNS;
    }

    if (fields & SRV_DTCNT_PROF_FIELD_HASH_VAL)
    {
        kal_mem_cpy(target->napid_hash_val, comm_header->napid_hash_val, SRV_DTCNT_NAPID_HASH_LEN);
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
        kal_mem_cpy(target->provurl_hash_val, comm_header->provurl_hash_val, SRV_DTCNT_PROVURL_HASH_LEN);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
        target->fields |= SRV_DTCNT_PROF_FIELD_HASH_VAL;        
    }

	if (fields & SRV_DTCNT_PROF_FIELD_NAME)
    {
        if (mmi_ucs2ncmp((const CHAR *)target->acc_name, (const CHAR *)comm_header->AccountName, SRV_DTCNT_PROF_MAX_ACC_NAME_LEN))
        {
            kal_mem_set(target->acc_name, 0, (SRV_DTCNT_PROF_MAX_ACC_NAME_LEN+1) * ENCODING_LENGTH);
	    if (mmi_ucs2strlen((const CHAR *)comm_header->AccountName))
	    {
                mmi_ucs2ncpy((char *)target->acc_name, (char *)comm_header->AccountName, SRV_DTCNT_PROF_MAX_ACC_NAME_LEN);
	    }
	    else
	    {
		mmi_ucs2cpy((CHAR *)target->acc_name, (const CHAR *)L"Account ");
		sprintf((char *)temp_ascii_acct_no, "%d", (target->acc_id+1));
		mmi_asc_n_to_ucs2((CHAR *) (target->acc_name + 16), (CHAR *) temp_ascii_acct_no, 2);			
	    }
            kal_mem_set(target->napid_hash_val, 0, SRV_DTCNT_NAPID_HASH_LEN);
            #ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
            kal_mem_set(target->provurl_hash_val, 0, SRV_DTCNT_PROVURL_HASH_LEN);
            #endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
        }
    }

    if (fields & SRV_DTCNT_PROF_FIELD_READONLY)
    {
        target->readonly = comm_header->read_only;        
    }
#ifdef __MMI_GPRS_FEATURES__
    if (target->bearer_type == SRV_DTCNT_BEARER_GPRS)
    {
        srv_dtcnt_prof_gprs_struct *gprs = (srv_dtcnt_prof_gprs_struct *)data;
        if (fields & SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM)
        {
            strcpy((CHAR *)target->dest_name, (CHAR *)gprs->APN);
            target->fields |= SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM;
        }
        if (fields & SRV_DTCNT_PROF_FIELD_AUTH_TYPE)
        {
            target->auth_info.AuthType = gprs->prof_common_header.Auth_info.AuthType;
            target->fields |= SRV_DTCNT_PROF_FIELD_AUTH_TYPE;
        }
        return file_name_changed;
    }
#endif /* __MMI_GPRS_FEATURES__ */

#ifdef __TCPIP_OVER_CSD__
    if (target->bearer_type == SRV_DTCNT_BEARER_CSD)
    {
        srv_dtcnt_prof_csd_struct *csd = (srv_dtcnt_prof_csd_struct *)data;
        if (fields & SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM)
        {
            strcpy((CHAR *)target->dest_name, (CHAR *)csd->DialNumber);
            target->fields |= SRV_DTCNT_PROF_FIELD_APN_DIAL_NUM;
        }
        if (fields & SRV_DTCNT_PROF_FIELD_DIAL_TYPE)
        {
            target->DialType = csd->DialType;
            target->fields |= SRV_DTCNT_PROF_FIELD_DIAL_TYPE;
        }
        if (fields & SRV_DTCNT_PROF_FIELD_DATA_RATE)
        {
            target->DataRate = csd->DataRate;
            target->fields |= SRV_DTCNT_PROF_FIELD_DATA_RATE;
        }
        return file_name_changed;        
    }
#endif /* __TCPIP_OVER_CSD__ */

    MMI_ASSERT(0);
    return MMI_FALSE;
}
int srv_dtcnt_db_store_detail_prof_update_check(void *data, U32 update_fields, U32 *out_fields, kal_wchar *old_ucs2_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_prof_common_header_struct *comm_header = data;
    U32 size = 0, read;
    void *old_data;
    U8 *cur_pos;
    U32 field_type;
    U16 length;
    int fp, fs_err;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check need to change or not */
    if (!(update_fields & SRV_DTCNT_PROF_FIELD_USER_DATA)  &&
        !(update_fields & SRV_DTCNT_PROF_FIELD_HOME)       &&
        !(update_fields & SRV_DTCNT_PROF_FIELD_INET_IP)    &&
        !(update_fields & SRV_DTCNT_PROF_FIELD_INET_MASK)  &&
        !(update_fields & SRV_DTCNT_PROF_FIELD_PX_ADDR)    &&
        !(update_fields & SRV_DTCNT_PROF_FIELD_PX_AUTH_ID) &&
        !(update_fields & SRV_DTCNT_PROF_FIELD_PX_AUTH_PW) &&
        !(update_fields & SRV_DTCNT_PROF_FIELD_PX_PORT))
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_DETAIL_PROF_UPDATE_CHECK_NO_CHANGE);
        return 0;
    }

    fp = FS_Open(old_ucs2_filename, FS_READ_WRITE);
    if (fp < FS_NO_ERROR)
    {
        if (fp == FS_FILE_NOT_FOUND)
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_DETAIL_PROF_UPDATE_CHECK_FILE_NOT_FOUND);
            return 1;
        }
        return -1;
    }
    fs_err = FS_GetFileSize(fp, (UINT *)&size);
    if (fs_err < FS_NO_ERROR)
    {
        FS_Close(fp);
        return -1;
    }

    old_data = OslMalloc(size);
    fs_err = FS_Read(fp, old_data, size, (UINT *)&read);
    if (fs_err < FS_NO_ERROR)
    {
        OslMfree(old_data);
        FS_Close(fp);
        return -1;
    }
    FS_Close(fp);

    /* update information to data */
    cur_pos = old_data;   
    while(size)
    {
        srv_dtcnt_n2l(cur_pos, field_type);
        srv_dtcnt_n2s(cur_pos, length);
        size -= (6 + length);
        switch (field_type)
        {
            case SRV_DTCNT_PROF_FIELD_USER_DATA:
                {
					cur_pos +=length;
                }
                break;

            case SRV_DTCNT_PROF_FIELD_HOME:
                {
                    if (!(update_fields & SRV_DTCNT_PROF_FIELD_HOME))
                    {                    
                        strncpy((CHAR *)comm_header->HomePage, (CHAR *)cur_pos,length);
                        comm_header->HomePage[length] = 0;
                    }
                    cur_pos += length;
                }
                break;

            case SRV_DTCNT_PROF_FIELD_INET_IP:
                {
                    if (!(update_fields & SRV_DTCNT_PROF_FIELD_INET_IP))
                    {                    
                        kal_mem_cpy(comm_header->StaicIPAddr, cur_pos, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
                    }
                    cur_pos += length;
                }
                break;

            case SRV_DTCNT_PROF_FIELD_INET_MASK:
                {
                    if (!(update_fields & SRV_DTCNT_PROF_FIELD_INET_MASK))
                    {                                    
                        kal_mem_cpy(comm_header->NetMask, cur_pos, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
                    }
                    cur_pos += length;
                }
                break;

            case SRV_DTCNT_PROF_FIELD_PX_ADDR:
                {
                    if (!(update_fields & SRV_DTCNT_PROF_FIELD_PX_ADDR))
                    {                    
                        kal_mem_cpy(comm_header->px_addr, cur_pos, length);
                        comm_header->px_addr[length] = 0;
                    }
                    cur_pos += length;
                }
                break;
            case SRV_DTCNT_PROF_FIELD_PX_AUTH_ID:
                {
                    if (!(update_fields & SRV_DTCNT_PROF_FIELD_PX_AUTH_ID))
                    {                    
                        strcpy((CHAR *)comm_header->px_authid, (CHAR *)cur_pos);
                    }
                    cur_pos += length;
                }
                break;

            case SRV_DTCNT_PROF_FIELD_PX_AUTH_PW:
                {
                    if (!(update_fields & SRV_DTCNT_PROF_FIELD_PX_AUTH_PW))
                    {                    
                        strcpy((CHAR *)comm_header->px_authpw, (CHAR *)cur_pos);
                    }
                    cur_pos += length;
                }
                break;

            case SRV_DTCNT_PROF_FIELD_PX_PORT:
                {
                    if (!(update_fields & SRV_DTCNT_PROF_FIELD_PX_PORT))
                    {
                        srv_dtcnt_n2s(cur_pos, comm_header->px_port);
                    }
                    else
                    {
                        cur_pos += length;
                    }
                }
                break;

            default: /* should never occurs */
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_DETAIL_PROFUPDATE_CHECK_FILE_CORRUPT, field_type);
                OslMfree(old_data);
                return -1;
                
        }        
    }

    *out_fields |= update_fields;   

    /* All not-updated information had been copied to data profile */
    OslMfree(old_data);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_DETAIL_PROF_UPDATE_CHECK_CHANGE_REQUIRED);
    return 1;
}

srv_dtcnt_result_enum srv_dtcnt_db_store_update_prof(void *data, U32 fields, U32 acc_id, U8 dm_update)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, data_size, temp_def_idx = 0;
    kal_wchar *new_ucs2_filename = NULL, *old_ucs2_filename = NULL;
    U32 active_fields, size;
    void *temp_data = NULL;
    U8 sim_changed = 0;
    srv_dtcnt_sim_type_enum sim_info = SRV_DTCNT_SIM_TYPE_TOTAL;
    srv_dtcnt_account_info_st temp_acc_info = {0,};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* find specified slot */
    for (i = 0; i < (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM + SRV_DTCNT_RESERVED_DM_ACC_NUM); i++)
    {
        if (g_srv_dtcnt_store_ctx.acc_list[i].in_use &&
            srv_dtcnt_db_store_readonly_update_check(g_srv_dtcnt_store_ctx.acc_list[i].readonly, fields) &&
            g_srv_dtcnt_store_ctx.acc_list[i].acc_id == acc_id)
        {
            sim_info = g_srv_dtcnt_store_ctx.acc_list[i].sim_info;
            temp_def_idx = g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1];
            srv_dtcnt_db_compose_acc_path(
                            &old_ucs2_filename,                 
                            (U8)(g_srv_dtcnt_store_ctx.acc_list[i].acc_id),
                            g_srv_dtcnt_store_ctx.acc_list[i].acc_type,
                            g_srv_dtcnt_store_ctx.acc_list[i].sim_info);

            if (!srv_dtcnt_db_store_backup_info_file() || !srv_dtcnt_db_store_backup_prof_file(old_ucs2_filename))
            {
                srv_dtcnt_db_store_del_backup_info_file();
                OslMfree(old_ucs2_filename);
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_UPDATE_PROF_BACKUP_FILE_ERR);
                return SRV_DTCNT_RESULT_FAILED;
            }

            srv_dtcnt_db_atomic_begin(SRV_DTCNT_DB_TRANS_UPDATE, g_srv_dtcnt_store_ctx.acc_list[i].acc_id);
            kal_mem_cpy(&temp_acc_info, &(g_srv_dtcnt_store_ctx.acc_list[i]), sizeof(srv_dtcnt_account_info_st));            

            if (g_srv_dtcnt_store_ctx.acc_list[i].bearer_type == SRV_DTCNT_BEARER_GPRS)
            {
                active_fields = fields & g_srv_dtcnt_store_ctx.ctrl_block.gprs_fields;
            }
            else
            {
                active_fields = fields & g_srv_dtcnt_store_ctx.ctrl_block.csd_fields;
            }

            /* detail profile name unchanged */
            if (srv_dtcnt_db_store_acc_info_update(data, active_fields, &(g_srv_dtcnt_store_ctx.acc_list[i]), &sim_changed))
            {
                srv_dtcnt_db_compose_acc_path(
                            &new_ucs2_filename,                     
                            (U8)(g_srv_dtcnt_store_ctx.acc_list[i].acc_id),
                            g_srv_dtcnt_store_ctx.acc_list[i].acc_type,
                            g_srv_dtcnt_store_ctx.acc_list[i].sim_info);
            }

            data_size = srv_dtcnt_db_store_detail_prof_update_check(data, active_fields, &(g_srv_dtcnt_store_ctx.acc_list[i].fields), old_ucs2_filename);
            if (data_size > 0)
            {
                if (srv_dtcnt_db_store_compose_prof(data, g_srv_dtcnt_store_ctx.acc_list[i].fields, &temp_data, &size, i))
                {
                    goto save_new_prof_file;
                }
                else /* compose failed */
                {
                    goto update_prof_resume;
                }
            }
            else if (data_size == 0)
            {
                /* only acc_info need to be updated */
                if (new_ucs2_filename == NULL)
                {
                    if (g_srv_dtcnt_store_ctx.acc_list[i].app_type & DTCNT_APPTYPE_DEF &&
						g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] != i+1)
                    {
                        if (temp_def_idx)
                        {
                            g_srv_dtcnt_store_ctx.acc_list[temp_def_idx-1].app_type &= ~DTCNT_APPTYPE_DEF;
                        }
                        g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] = i+1;
                    }
                    if (!srv_dtcnt_db_fileio_write_store_info_file())
                    {
                        goto update_prof_resume;
                    }
                    else
                    {
                        goto update_prof_success;
                    }
                }
                else
                {                                       
                        temp_data = OslMalloc(sizeof(srv_dtcnt_prof_csd_struct));
                        if (srv_dtcnt_db_fileio_read_data(old_ucs2_filename, temp_data, sizeof(srv_dtcnt_prof_csd_struct), &size) == SRV_DTCNT_RESULT_SUCCESS)
                        {
                        save_new_prof_file:
                            if (!new_ucs2_filename)
                            {
                                srv_dtcnt_db_compose_acc_path(
                                            &new_ucs2_filename,                     
                                            (U8)(g_srv_dtcnt_store_ctx.acc_list[i].acc_id),
                                            g_srv_dtcnt_store_ctx.acc_list[i].acc_type,
                                            g_srv_dtcnt_store_ctx.acc_list[i].sim_info);
                            }

                            if (srv_dtcnt_db_fileio_save_data(new_ucs2_filename, temp_data, size) == SRV_DTCNT_RESULT_SUCCESS)
                            {
                                if (g_srv_dtcnt_store_ctx.acc_list[i].app_type & DTCNT_APPTYPE_DEF &&
                                    g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] != i+1)
                                {
                                    if (temp_def_idx)
                                    {
                                        g_srv_dtcnt_store_ctx.acc_list[temp_def_idx-1].app_type &= ~DTCNT_APPTYPE_DEF;
                                    }
                                    g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] = i+1;
                                }
                                if (srv_dtcnt_db_fileio_write_store_info_file())
                                {
                                    goto update_prof_success;
                                }
                            }
                        }
                        /* there is no old profile file originally */
                        if (!srv_dtcnt_db_fileio_file_exist(old_ucs2_filename))
                        {
                            goto update_prof_success;
                        }
                        goto update_prof_resume;
                }
            }
            else /* -1 */
            {
                goto update_prof_resume;
            }            
        }
    }

    /* can't find profile to update */
    if (i == (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM + SRV_DTCNT_RESERVED_DM_ACC_NUM))
    {
    #ifdef __DTCNT_SIM_PROFILES_SUPPORT__
        srv_dtcnt_sim_comm_account_info_st *sim_acct = NULL;
        srv_dtcnt_prof_common_header_struct *comm_header = data;
        
        sim_acct = srv_dtcnt_db_store_get_sim_acc_info((U8)acc_id);
        if (sim_acct && (fields & SRV_DTCNT_PROF_FIELD_HOME))
        {
            kal_mem_cpy(
                sim_acct->HomePage,
                comm_header->HomePage,
                (SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1));
            return SRV_DTCNT_RESULT_SUCCESS;
        }
    #endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_UPDATE_PROF_NOT_FOUND);
        return SRV_DTCNT_RESULT_FAILED;
    }

update_prof_resume:
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_UPDATE_PROF_RESUME);
    kal_mem_cpy(&(g_srv_dtcnt_store_ctx.acc_list[i]), &temp_acc_info, sizeof(srv_dtcnt_account_info_st));
    g_srv_dtcnt_store_ctx.default_acc_idx[sim_info-1] = temp_def_idx;
    if (new_ucs2_filename)
    {
        FS_Delete(new_ucs2_filename);
        OslMfree(new_ucs2_filename);
    }
    if (old_ucs2_filename)
    {
        OslMfree(old_ucs2_filename);
    }
    if (temp_data)
    {
        OslMfree(temp_data);
    }
    srv_dtcnt_db_store_del_backup_info_file();
    srv_dtcnt_db_store_del_backup_prof_file();
    srv_dtcnt_db_atomic_end();
    return SRV_DTCNT_RESULT_FAILED;

update_prof_success:
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_UPDATE_PROF_DONE);
    if (new_ucs2_filename)
    {
		if (old_ucs2_filename)
		{
			if (mmi_ucs2cmp((const CHAR *) old_ucs2_filename, (const CHAR *)new_ucs2_filename))
			{
				FS_Delete(old_ucs2_filename);
			}
			OslMfree(old_ucs2_filename);
		}        
        OslMfree(new_ucs2_filename);
        OslMfree(temp_data);        
    }
    else
    {
        OslMfree(old_ucs2_filename);        
    }
    srv_dtcnt_db_store_del_backup_info_file();
    srv_dtcnt_db_store_del_backup_prof_file();
    srv_dtcnt_db_atomic_end();

    if (g_srv_dtcnt_store_sync_done)
    {
        srv_dtcnt_db_store_send_abm_acc_info(SRV_DTCNT_DB_TRANS_ADD, i, sim_changed);
    }
    
    srv_dtcnt_db_store_send_acc_update_post_evt(g_srv_dtcnt_store_ctx.acc_list[i].acc_id,
                                            g_srv_dtcnt_store_ctx.acc_list[i].sim_info,
                                            sim_changed, 0);
    return SRV_DTCNT_RESULT_SUCCESS;    
}


MMI_BOOL srv_dtcnt_db_store_backup_info_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_dtcnt_db_fileio_save_data(SRV_DTCNT_DB_STORE_INFOFILE_BAK_NAME, &(g_srv_dtcnt_store_ctx), sizeof(srv_dtcnt_store_info_context)) 
        != SRV_DTCNT_RESULT_SUCCESS)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

void srv_dtcnt_db_store_del_backup_info_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_dtcnt_db_fileio_file_exist(SRV_DTCNT_DB_STORE_INFOFILE_BAK_NAME))
    {
        FS_Delete(SRV_DTCNT_DB_STORE_INFOFILE_BAK_NAME);
    }
}

void srv_dtcnt_db_store_del_backup_prof_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_dtcnt_db_fileio_file_exist(SRV_DTCNT_DB_ACC_FILE_BAK_NAME))
    {
        FS_Delete(SRV_DTCNT_DB_ACC_FILE_BAK_NAME);
    }
}

MMI_BOOL srv_dtcnt_db_store_backup_prof_file(kal_wchar *prof_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fp;
    U32 filesize = 0;
    U32 read;
    void *buffer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_dtcnt_db_fileio_file_exist(prof_name))
    {
        return MMI_TRUE;
    }

    fp = FS_Open(prof_name, FS_READ_ONLY);
    if (fp < 0)
    {
        return MMI_FALSE;
    }

    if (FS_GetFileSize(fp, (UINT*)&filesize) < 0)
    {
        return MMI_FALSE;
    }

    if (!filesize)
    {
        return MMI_FALSE;
    }

    buffer = OslMalloc(filesize);

    if (FS_Read(fp, (void*)buffer, (UINT)filesize, &read)<0 ||
        (filesize != read))
    {
        OslMfree(buffer);
        return MMI_FALSE;
    }
    FS_Close(fp);

    if (srv_dtcnt_db_fileio_save_data(SRV_DTCNT_DB_ACC_FILE_BAK_NAME, buffer, filesize) != SRV_DTCNT_RESULT_SUCCESS)
    {
        OslMfree(buffer);
        return MMI_FALSE;
    }
    OslMfree(buffer);    
    return MMI_TRUE;
}


void srv_dtcnt_db_store_del_wlan_profile(U32 profile_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
    int i, j;
    U8 target_priority=0, prof_num;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_DELETE_WLAN_PROF, profile_id);
    for (i = 0; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; i++)
    {
        if (g_srv_dtcnt_wlan_prof_list[i].priority > 0 && 
            g_srv_dtcnt_wlan_prof_list[i].ssid_len &&
            g_srv_dtcnt_wlan_prof_list[i].profile_id == profile_id)
        {           
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_DELETE_WLAN_PROF_FOUND);
            target_priority = g_srv_dtcnt_wlan_prof_list[i].priority;
            prof_num = g_srv_dtcnt_wlan_setting_ctx.infra_prof_num + g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num;

            if (g_srv_dtcnt_wlan_prof_list[i].network_type == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA)
            {
                g_srv_dtcnt_wlan_setting_ctx.infra_prof_num--;
            }
            else
            {
                g_srv_dtcnt_wlan_setting_ctx.adhoc_prof_num--;
            }
            kal_mem_set(&(g_srv_dtcnt_wlan_prof_list[i]), 0, sizeof(srv_dtcnt_prof_wlan_struct));

            for (j=target_priority; j < prof_num; j++)
            {
                MMI_ASSERT(g_srv_dtcnt_wlan_prof_list_p[j]->priority > target_priority);
                g_srv_dtcnt_wlan_prof_list_p[j-1] = g_srv_dtcnt_wlan_prof_list_p[j];
                g_srv_dtcnt_wlan_prof_list_p[j-1]->priority--;
            }
            g_srv_dtcnt_wlan_prof_list_p[prof_num-1] = NULL;

        }        
    }

    if (target_priority != 0)
    {
        /* update profile list for priority changed */
        for (i = 0; i < SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM; i++)
        {
            if (WriteRecord(NVRAM_EF_WLAN_PROFILE_LID, (U16)(i + 1), (void*)&g_srv_dtcnt_wlan_prof_list[i], NVRAM_MAX_WLAN_PROFILE_SIZE, (S16 *)&error) 
                < NVRAM_MAX_WLAN_PROFILE_SIZE)
            {
                MMI_ASSERT(0);
            }
        }

        /* update wlan setting for profile number changed */
        if (WriteRecord(NVRAM_EF_WLAN_SETTING_LID, 1, &g_srv_dtcnt_wlan_setting_ctx, NVRAM_MAX_WLAN_SETTING_SIZE, &error) <
            NVRAM_MAX_WLAN_SETTING_SIZE)
        {
            ASSERT(0);
        }
    }      
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#endif /* __MMI_WLAN_FEATURES__ */
}

srv_dtcnt_result_enum srv_dtcnt_db_store_del_account(U8 acc_id, MMI_BOOL force_exec, void *user_data, srv_dtcnt_store_delete_cb_func_ptr callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, j, temp_def_idx;
    kal_wchar *ucs2_filename = NULL;
    U8 same_sim_csd;
    srv_dtcnt_sim_type_enum sim_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_DELETE_ACCOUNT, acc_id, callback);
    for (i = 0; i < (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM + SRV_DTCNT_RESERVED_DM_ACC_NUM); i++)
    {
        if (g_srv_dtcnt_store_ctx.acc_list[i].in_use &&
            (force_exec || !g_srv_dtcnt_store_ctx.acc_list[i].readonly)&&
            g_srv_dtcnt_store_ctx.acc_list[i].acc_id == acc_id)            
        {        
            sim_info = g_srv_dtcnt_store_ctx.acc_list[i].sim_info;
            temp_def_idx = g_srv_dtcnt_store_ctx.default_acc_idx[sim_info - 1];
            srv_dtcnt_db_atomic_begin(SRV_DTCNT_DB_TRANS_DELETE, acc_id);
            if (temp_def_idx == (i+1))
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_DELETE_DEFAULT_ACCOUNT);
                same_sim_csd = 0;
                for (j = 0; j < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; j++)
                {
                    if (g_srv_dtcnt_store_ctx.acc_list[j].in_use && (j != i) )
                    {
                        if (g_srv_dtcnt_store_ctx.acc_list[i].sim_info == g_srv_dtcnt_store_ctx.acc_list[j].sim_info)
                        {
                            if (g_srv_dtcnt_store_ctx.acc_list[j].bearer_type == SRV_DTCNT_BEARER_GPRS)
                            {                               
                                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_DELETE_DEFAULT_ACCOUNT_SWITCH_SAME_SIM_GPRS, g_srv_dtcnt_store_ctx.acc_list[j].acc_id);
                                g_srv_dtcnt_store_ctx.default_acc_idx[sim_info - 1] = j+1;
                                break;
                            }
                            else
                                same_sim_csd = (U8)(j+1);
                        }

                    }
                }
                if (j == SRV_DTCNT_PROF_MAX_ACCOUNT_NUM)
                {
                    if (same_sim_csd)
                    {
                        g_srv_dtcnt_store_ctx.default_acc_idx[sim_info - 1] = same_sim_csd;
                        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_DELETE_DEFAULT_ACCOUNT_SWITCH_SAME_SIM_CSD, g_srv_dtcnt_store_ctx.default_acc_idx[sim_info - 1]);
                    }
                    else
                    {
                        g_srv_dtcnt_store_ctx.default_acc_idx[sim_info - 1] = 0;
                    }

                }
            }            
            g_srv_dtcnt_store_ctx.acc_list[i].in_use = 0;
            g_srv_dtcnt_store_ctx.ctrl_block.total_acc_num --;

            if (!srv_dtcnt_db_fileio_write_store_info_file())
            {
                g_srv_dtcnt_store_ctx.ctrl_block.total_acc_num++;
                g_srv_dtcnt_store_ctx.acc_list[i].in_use = 1;
                g_srv_dtcnt_store_ctx.default_acc_idx[sim_info - 1] = temp_def_idx;
                srv_dtcnt_db_atomic_end();
                return SRV_DTCNT_RESULT_FAILED;
            }

            srv_dtcnt_db_compose_acc_path(
                            &ucs2_filename,                 
                            (U8)(g_srv_dtcnt_store_ctx.acc_list[i].acc_id),
                            g_srv_dtcnt_store_ctx.acc_list[i].acc_type,
                            g_srv_dtcnt_store_ctx.acc_list[i].sim_info);
            FS_Delete(ucs2_filename);
            OslMfree(ucs2_filename);
            if (callback)
            {                
                U32 encoded_acc_id = cbm_encode_data_account_id(
                                (U32)g_srv_dtcnt_store_ctx.acc_list[i].acc_id,
                                srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(g_srv_dtcnt_store_ctx.acc_list[i].sim_info),
                                0,
                                KAL_FALSE);
                callback(encoded_acc_id, user_data);
            }
            srv_dtcnt_db_atomic_end();

    		/* APP_INFO_MODIFY */
            if (g_srv_dtcnt_store_sync_done)
            {
                srv_dtcnt_db_store_send_abm_acc_info(SRV_DTCNT_DB_TRANS_DELETE, i, 0);               
            }

            srv_dtcnt_db_store_send_acc_delete_post_evt(g_srv_dtcnt_store_ctx.acc_list[i].acc_id,
                                          g_srv_dtcnt_store_ctx.acc_list[i].sim_info,
                                          g_srv_dtcnt_store_sync_done);
            return SRV_DTCNT_RESULT_SUCCESS;
        }
    }
    return SRV_DTCNT_RESULT_FAILED;
}

void srv_dtcnt_db_store_recalc_acc_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    U32 count = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
        if (g_srv_dtcnt_store_ctx.acc_list[i].in_use)
        {
            count++;
        }
    }
    if (count != g_srv_dtcnt_store_ctx.ctrl_block.total_acc_num)
    {
        g_srv_dtcnt_store_ctx.ctrl_block.total_acc_num = count;
        srv_dtcnt_db_fileio_write_store_info_file();
    }
}

MMI_BOOL srv_dtcnt_db_store_readonly_update_check(U8 ro_flag, U32 update_fields)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!ro_flag ||
        (update_fields & SRV_DTCNT_PROF_FIELD_READONLY) ||
        (update_fields == SRV_DTCNT_PROF_FIELD_APP_TYPE))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

void srv_dtcnt_db_store_send_abm_acc_info(srv_dtcnt_db_trans_type_enum opcode, int index, U8 sim_changed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_update_account_info_req_struct *info_req = 
            (mmi_abm_update_account_info_req_struct *)construct_local_para(sizeof(mmi_abm_update_account_info_req_struct), TD_RESET);
    cbm_sim_id_enum sim_id = srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(g_srv_dtcnt_store_ctx.acc_list[index].sim_info);
    U32 encoded_acc_id = (U32)g_srv_dtcnt_store_ctx.acc_list[index].acc_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (opcode == SRV_DTCNT_DB_TRANS_ADD)
    {
        info_req->action = MMI_ABM_PROFILE_ADD;
        info_req->account_id = encoded_acc_id;
        info_req->bearer_type = (g_srv_dtcnt_store_ctx.acc_list[index].bearer_type == SRV_DTCNT_BEARER_GPRS)? CBM_PS : CBM_CSD;
    }
    else /* DELETE */
    {
		/* APP_INFO_MODIFY */
        info_req->action = MMI_ABM_PROFILE_DEL;
        info_req->account_id = encoded_acc_id;
        if (g_srv_dtcnt_store_ctx.acc_list[index].bearer_type == SRV_DTCNT_BEARER_CSD)
        {
            info_req->bearer_type = CBM_CSD;
        }
        else if (g_srv_dtcnt_store_ctx.acc_list[index].bearer_type == SRV_DTCNT_BEARER_GPRS)
        {
            info_req->bearer_type = CBM_PS;
        }
        else
        {
            free_local_para((local_para_struct *)info_req);
            return;
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_SEND_ABM_ACC_INFO, 
        opcode, sim_id, 
        g_srv_dtcnt_store_ctx.acc_list[index].acc_id, 
        g_srv_dtcnt_store_ctx.acc_list[index].bearer_type,
        sim_changed);
    srv_dtcnt_db_store_send_msg(MSG_ID_MMI_ABM_UPDATE_ACCOUNT_INFO_REQ, (void *)info_req, MOD_ABM);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}


/* APP_INFO_MODIFY */
void srv_dtcnt_db_store_update_abm_acc_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__ 
    mmi_abm_update_account_info_req_struct *info_req = NULL;
    U32 encoded_acc_id;
    cbm_sim_id_enum sim_id;
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_UPDATE_ABM_ACC_INFO, g_srv_dtcnt_store_ctx.ctrl_block.total_acc_num);
    if (g_srv_dtcnt_store_ctx.ctrl_block.total_acc_num)
    {
        for (; i < (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM + SRV_DTCNT_RESERVED_DM_ACC_NUM); i++)
        {
            if (g_srv_dtcnt_store_ctx.acc_list[i].in_use)
            {
                srv_dtcnt_db_store_send_abm_acc_info(SRV_DTCNT_DB_TRANS_ADD, i, 0);
            }
        }
    }

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__        
#ifdef  __TCPIP_OVER_CSD__
    if (g_srv_dtcnt_store_ctx.ctrl_block.csd_sim_acc_num)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_UPDATE_ABM_ACC_INFO_SIM_CSD, g_srv_dtcnt_store_ctx.ctrl_block.csd_sim_acc_num);

        for (i = 0; i<MAX_CSD_SIM_PROV_NUM; i++)
        {
            if (csd_sim_acc_list[i].comm_header.in_use)
            {                
                info_req = (mmi_abm_update_account_info_req_struct *)construct_local_para(sizeof(mmi_abm_update_account_info_req_struct), TD_RESET);
                info_req->action = MMI_ABM_PROFILE_ADD;

                sim_id = srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(csd_sim_acc_list[i].comm_header.sim_info);
                info_req->account_id = (U32)csd_sim_acc_list[i].comm_header.acc_id;
                info_req->bearer_type = CBM_CSD;
                srv_dtcnt_db_store_send_msg(MSG_ID_MMI_ABM_UPDATE_ACCOUNT_INFO_REQ, (void *)info_req, MOD_ABM);
            }
        }
    }
#endif /* __TCPIP_OVER_CSD__ */    
#ifdef __MMI_GPRS_FEATURES__
    if (g_srv_dtcnt_store_ctx.ctrl_block.gprs_sim_acc_num)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_UPDATE_ABM_ACC_INFO_SIM_GPRS, g_srv_dtcnt_store_ctx.ctrl_block.gprs_sim_acc_num);

        for (i = 0; i<MAX_GPRS_SIM_PROV_NUM; i++)
        {
            if (gprs_sim_acc_list[i].comm_header.in_use)
            {
                info_req = (mmi_abm_update_account_info_req_struct *)construct_local_para(sizeof(mmi_abm_update_account_info_req_struct), TD_RESET);
                info_req->action = MMI_ABM_PROFILE_ADD;

                sim_id = srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(gprs_sim_acc_list[i].comm_header.sim_info);
                info_req->account_id = (U32)gprs_sim_acc_list[i].comm_header.acc_id;
                info_req->bearer_type = CBM_PS;
                srv_dtcnt_db_store_send_msg(MSG_ID_MMI_ABM_UPDATE_ACCOUNT_INFO_REQ, (void *)info_req, MOD_ABM);
            }
        }
    }
#endif /* __MMI_GPRS_FEATURES__ */   
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */

    return;
}


/* APP_INFO_MODIFY */
void srv_dtcnt_store_update_acc_apinfo(srv_dtcnt_prof_app_info_struct *ap_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i=0;
    mmi_abm_update_app_info_req_struct *app_info_req = (mmi_abm_update_app_info_req_struct *)construct_local_para(sizeof(mmi_abm_update_app_info_req_struct), TD_RESET);
    //cbm_sim_id_enum sim_id[CBM_DEFAULT_ACCT_ID] = {0,};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(ap_info);
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_UPDATE_ACC_APINFO, g_srv_dtcnt_store_sync_done);

    if (MMI_FALSE == g_srv_dtcnt_store_sync_done)
    {
        srv_dtcnt_db_store_update_abm_acc_info();
        g_srv_dtcnt_store_sync_done = MMI_TRUE;
        srv_dtcnt_db_store_send_acc_delete_post_evt(CBM_INVALID_NWK_ACCT_ID, SRV_DTCNT_SIM_TYPE_1, g_srv_dtcnt_store_sync_done);
    }
        
    /* Prepare sim bit first */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
#ifdef __TCPIP_OVER_CSD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __TCPIP_OVER_CSD__ */
#ifdef __MMI_GPRS_FEATURES__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_GPRS_FEATURES__ */
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */
#endif 

    /* send ap info to abm */
    for (i = 0; i < ABM_MAX_APP_NUM; i++)
    {
        /* not using slot -> ignore */
        if ((ap_info->app_info[i].icon_id == 0) &&
            (ap_info->app_info[i].str_id == 0))
        {
            continue;    
        }

        app_info_req->invalid_app_info[i].app_icon_id = ap_info->app_info[i].icon_id;
        app_info_req->invalid_app_info[i].app_str_id = ap_info->app_info[i].str_id;
        app_info_req->invalid_app_info[i].account_id[0] = ap_info->app_info[i].acct_1;
        app_info_req->invalid_app_info[i].account_id[1] = ap_info->app_info[i].acct_2;
/*
        if (ap_info->app_info[i].acct_1 != CBM_INVALID_NWK_ACCT_ID)
        {
            encoded_acc_id = cbm_encode_data_account_id(
                                (U32)ap_info->app_info[i].acct_1,
                                sim_id[ap_info->app_info[i].acct_1],
                                0,
                                KAL_FALSE);
            app_info_req->invalid_app_info[i].account_id[0] = (U8)encoded_acc_id;
        }

        if (ap_info->app_info[i].acct_2 != CBM_INVALID_NWK_ACCT_ID)
        {
            encoded_acc_id = cbm_encode_data_account_id(
                                (U32)ap_info->app_info[i].acct_2,
                                sim_id[ap_info->app_info[i].acct_2],
                                0,
                                KAL_FALSE);
            app_info_req->invalid_app_info[i].account_id[1] = (U8)encoded_acc_id;
        }        
*/        
    }
    srv_dtcnt_db_store_send_msg(MSG_ID_MMI_ABM_UPDATE_APP_INFO_REQ, (void *)app_info_req, MOD_ABM);
}

void srv_dtcnt_db_store_send_msg(kal_uint16 msg_id, void *req, int mod_dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_send;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_send = allocate_ilm(MOD_MMI);   
    ilm_send->src_mod_id = MOD_MMI;
    ilm_send->dest_mod_id = (module_type)mod_dst;
    ilm_send->sap_id = MMI_ABM_SAP;
    ilm_send->msg_id = (msg_type) msg_id;
    ilm_send->local_para_ptr = (local_para_struct*) req;
    ilm_send->peer_buff_ptr = (peer_buff_struct*) NULL;    
    msg_send_ext_queue(ilm_send);    
}

MMI_BOOL srv_dtcnt_db_store_smart_acct_check(srv_dtcnt_db_find_best_acct_cntx_struct *best_acct_ctx, srv_dtcnt_sim_type_enum sim_type, srv_dtcnt_prof_px_srv_enum px_service, srv_dtcnt_bearer_enum bearer, MMI_BOOL check_app_type, U64 app_type, U8 proxy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (*(best_acct_ctx->sim_id) != srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(sim_type))
    {
        return MMI_FALSE;
    }

    if ((bearer == SRV_DTCNT_BEARER_CSD) &&
        best_acct_ctx->skip_csd)
    {
        return MMI_FALSE;
    }
/*
    if ((px_service != SRV_DTCNT_PROF_PX_SRV_NONE) &&
        best_acct_ctx->no_px_flag)
    {
        return MMI_FALSE;
    }

    if( px_service == SRV_DTCNT_PROF_PX_SRV_NONE && best_acct_ctx->need_px_flag)
    {
        return MMI_FALSE;
    }
*/
    if( (proxy!=0) && best_acct_ctx->no_px_flag )
    {
        return   MMI_FALSE;  		
    }

    if( (proxy==0) && best_acct_ctx->need_px_flag)
    {
        return   MMI_FALSE;  		
    }    
    /*Opera can't use wap protocol!*/
    if((best_acct_ctx->app_type == DTCNT_APPTYPE_BRW_HTTP) || 
        (best_acct_ctx->app_type == (DTCNT_APPTYPE_BRW_HTTP|DTCNT_APPTYPE_SPECIFIC_PROFILE)) )
    {
        if ((px_service < SRV_DTCNT_PROF_PX_SRV_HTTP) &&
            (px_service > SRV_DTCNT_PROF_PX_SRV_NONE))
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_NO_WAP);
            return MMI_FALSE;
        }

    }

    if (check_app_type)
    {
    #ifdef __DA_SMART_SELECTION_SUPPORT__
        if (!(app_type & best_acct_ctx->app_type &(~DTCNT_APPTYPE_SKIP_CSD)))
        {
            return MMI_FALSE;
        }
        if (app_type & best_acct_ctx->app_type & DTCNT_APPTYPE_BRW_HTTP &(~DTCNT_APPTYPE_SKIP_CSD))
        {
            if ((px_service < SRV_DTCNT_PROF_PX_SRV_HTTP) &&
                (px_service > SRV_DTCNT_PROF_PX_SRV_NONE))
            {
                return MMI_FALSE;
            }            
        }
        if (app_type & best_acct_ctx->app_type & DTCNT_APPTYPE_BRW_WAP &(~DTCNT_APPTYPE_SKIP_CSD))
        {
            if (px_service >= SRV_DTCNT_PROF_PX_SRV_HTTP)
            {
                return MMI_FALSE;
            }            
        }
    #else
        return MMI_FALSE;
    #endif
    }

    return MMI_TRUE;
}

U8 srv_dtcnt_db_store_smart_acct(srv_dtcnt_db_find_best_acct_cntx_struct *best_acct_ctx, U8 brw_mms_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, def_acc_idx = g_srv_dtcnt_store_ctx.default_acc_idx[*(best_acct_ctx->sim_id)];
    U8 same_sim_gprs, same_sim_csd, diff_sim_gprs, diff_sim_csd, tmp_acc_id = CBM_INVALID_NWK_ACCT_ID;

    srv_dtcnt_sim_type_enum comp_sim = (srv_dtcnt_sim_type_enum)((*best_acct_ctx->sim_id)+1);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_SMART_ACC, best_acct_ctx->need_px_flag, best_acct_ctx->no_px_flag, best_acct_ctx->skip_csd, brw_mms_ind);

    if (def_acc_idx)
    {        
        /* default account contype check */
        if (!srv_dtcnt_db_store_smart_acct_check(
                best_acct_ctx, 
                best_acct_ctx->default_sim_info,
                best_acct_ctx->default_px_service,
                best_acct_ctx->default_bearer_type,
                MMI_FALSE,
                0, best_acct_ctx->use_proxy))
        {
            /* can't use default account, reset temp default account index */
            def_acc_idx = 0;
        }

        if (brw_mms_ind == 1 && comp_sim != best_acct_ctx->default_sim_info)
        {
            /* WAP can't use default account with different SIM, reset temp default account index */
            def_acc_idx = 0;
        }
    }

    same_sim_gprs = same_sim_csd = diff_sim_gprs = diff_sim_csd = 0;
    for (i = 0; i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
        if (g_srv_dtcnt_store_ctx.acc_list[i].in_use)
        {
            /* found specified account */
            /* check px_flag and ignore CSD */
            #ifdef __DA_SMART_SELECTION_SUPPORT__
            if (srv_dtcnt_db_store_smart_acct_check(
                        best_acct_ctx, 
                        g_srv_dtcnt_store_ctx.acc_list[i].sim_info,
                        (g_srv_dtcnt_store_ctx.acc_list[i].use_proxy)? g_srv_dtcnt_store_ctx.acc_list[i].px_service : SRV_DTCNT_PROF_PX_SRV_NONE,
                        g_srv_dtcnt_store_ctx.acc_list[i].bearer_type,
                        MMI_TRUE,
                        g_srv_dtcnt_store_ctx.acc_list[i].app_type,
                        g_srv_dtcnt_store_ctx.acc_list[i].use_proxy))
            {
                /* WAP/MMS specify own SIM setting */
                if (brw_mms_ind == 0)
                {
                    *(best_acct_ctx->sim_id) = srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(g_srv_dtcnt_store_ctx.acc_list[i].sim_info);
                }
                
                if (comp_sim == g_srv_dtcnt_store_ctx.acc_list[i].sim_info)
                {
                    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_SMART_ACC_APP_TYPE_MATCH, 
                        g_srv_dtcnt_store_ctx.acc_list[i].acc_id,
                        g_srv_dtcnt_store_ctx.acc_list[i].sim_info,
                        comp_sim);
                    
                    if(tmp_acc_id == CBM_INVALID_NWK_ACCT_ID ||
                        g_srv_dtcnt_store_ctx.acc_list[i].bearer_type == SRV_DTCNT_BEARER_GPRS)
                    {
                    tmp_acc_id = g_srv_dtcnt_store_ctx.acc_list[i].acc_id;
                    }
                    if(g_srv_dtcnt_store_ctx.acc_list[i].acc_type == SRV_DTCNT_PROF_TYPE_FACTORY_CONF
                        && g_srv_dtcnt_store_ctx.acc_list[i].bearer_type == SRV_DTCNT_BEARER_GPRS)
                    {
                    goto ret_tmp_acc_id;
                }
                    
                }
                else
                {
                    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_SMART_ACC_APP_TYPE_MATCH,
                        g_srv_dtcnt_store_ctx.acc_list[i].acc_id,
                        g_srv_dtcnt_store_ctx.acc_list[i].sim_info,
                        comp_sim);
                    
                    if (brw_mms_ind == 0)
                    {
                        if (tmp_acc_id == CBM_INVALID_NWK_ACCT_ID || 
                            (g_srv_dtcnt_store_ctx.acc_list[i].bearer_type == SRV_DTCNT_BEARER_GPRS
                            && g_srv_dtcnt_store_ctx.acc_list[i].acc_type == SRV_DTCNT_PROF_TYPE_FACTORY_CONF))
                        {
                            tmp_acc_id = g_srv_dtcnt_store_ctx.acc_list[i].acc_id;
                        }
                    }
                }
            }

            #endif /*__DA_SMART_SELECTION__SUPPORT__*/

            /* ignore MMS due to MMS can only accept the app type matched accounts */
            if (brw_mms_ind != 2) /* 2 == MMS */
            {
                /* can't use default account and not found app type matched account, need to save temp index */
                if (!def_acc_idx && (tmp_acc_id == CBM_INVALID_NWK_ACCT_ID)) 
                {
                    if (srv_dtcnt_db_store_smart_acct_check(
                            best_acct_ctx, 
                            g_srv_dtcnt_store_ctx.acc_list[i].sim_info,
                            g_srv_dtcnt_store_ctx.acc_list[i].px_service,
                            g_srv_dtcnt_store_ctx.acc_list[i].bearer_type,
                            MMI_FALSE,
                            0, g_srv_dtcnt_store_ctx.acc_list[i].use_proxy))
                    {
                        if (g_srv_dtcnt_store_ctx.acc_list[i].sim_info == comp_sim)
                        {
                            if (g_srv_dtcnt_store_ctx.acc_list[i].bearer_type == SRV_DTCNT_BEARER_GPRS)
                            {                               
                                same_sim_gprs = (U8)i+1;
                            }
                            else
                            {
                                same_sim_csd = (U8)i+1;
                            }
                        }
                        else if (brw_mms_ind == 0) /* browser only select SIM accounts by selected SIM */
                        {
                            if (g_srv_dtcnt_store_ctx.acc_list[i].bearer_type == SRV_DTCNT_BEARER_GPRS)
                            {                               
                                diff_sim_gprs = (U8)i+1;
                            }
                            else
                            {
                                diff_sim_csd = (U8)i+1;
                            }
                        }
                    }
                }
            }
        }
    }

    /* found one different sim matched app_type account, without app_type matched same sim account */
    if (tmp_acc_id != CBM_INVALID_NWK_ACCT_ID)
    {
        goto ret_tmp_acc_id;
    }

    /* without factory defined specified account --> use searching info */
    if (brw_mms_ind == 2) /* MMS */
    {
#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
        tmp_acc_id = srv_dtcnt_db_store_find_best_mms_sim_acct(best_acct_ctx);
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */
        goto ret_tmp_acc_id;
    }

    /* general application and brw app */
    /* database default profile -1 */
    if (def_acc_idx)
    {
        tmp_acc_id = g_srv_dtcnt_store_ctx.acc_list[def_acc_idx-1].acc_id;
        *(best_acct_ctx->sim_id) = srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(g_srv_dtcnt_store_ctx.acc_list[def_acc_idx-1].sim_info);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_SMART_ACC_DEFAULT_MATCH, tmp_acc_id, *(best_acct_ctx->sim_id));
        goto ret_tmp_acc_id;
    }
    /* same sim database gprs profile -2 */
    else if (same_sim_gprs)
    {
        tmp_acc_id = g_srv_dtcnt_store_ctx.acc_list[same_sim_gprs-1].acc_id;
        *(best_acct_ctx->sim_id) = srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(g_srv_dtcnt_store_ctx.acc_list[same_sim_gprs-1].sim_info);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_SMART_ACC_SAME_SIM_DB_GPRS, tmp_acc_id, *(best_acct_ctx->sim_id));
        goto ret_tmp_acc_id;
    }

    /* same sim database csd profile -3 */
    else if (same_sim_csd)
    {
        tmp_acc_id = g_srv_dtcnt_store_ctx.acc_list[same_sim_csd-1].acc_id;
        *(best_acct_ctx->sim_id) = srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(g_srv_dtcnt_store_ctx.acc_list[same_sim_csd-1].sim_info);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_SMART_ACC_SAME_SIM_DB_CSD, tmp_acc_id, *(best_acct_ctx->sim_id));
    }

    /* diff sim database gprs profile -4 */
    else if (diff_sim_gprs)
    {
        tmp_acc_id = g_srv_dtcnt_store_ctx.acc_list[diff_sim_gprs-1].acc_id;
        *(best_acct_ctx->sim_id) = srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(g_srv_dtcnt_store_ctx.acc_list[diff_sim_gprs-1].sim_info);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_SMART_ACC_DIFF_SIM_DB_GPRS, tmp_acc_id, *(best_acct_ctx->sim_id));
    }

    /* diff sim database csd profile -5 */
    else if (diff_sim_csd)
    {
        tmp_acc_id = g_srv_dtcnt_store_ctx.acc_list[diff_sim_csd-1].acc_id;
        *(best_acct_ctx->sim_id) = srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(g_srv_dtcnt_store_ctx.acc_list[diff_sim_csd-1].sim_info);
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_SMART_ACC_DIFF_SIM_DB_CSD, tmp_acc_id, *(best_acct_ctx->sim_id));
    }

    /* can't found same conn_type acct - 6 */
    else
    {
        //tmp_acc_id = CBM_INVALID_NWK_ACCT_ID;
        tmp_acc_id = CBM_DEFAULT_ACCT_ID;
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_SMART_ACC_CONN_TYPE_MISMATCH);
    }
    
ret_tmp_acc_id:
    if (best_acct_ctx->best_fit_acc_id)
    {
        *(best_acct_ctx->best_fit_acc_id) = tmp_acc_id;
    }
    return tmp_acc_id; 
}

MMI_BOOL srv_dtcnt_db_store_get_def_acc_info(cbm_sim_id_enum *sim_id,U8 *acc_id, srv_dtcnt_prof_px_srv_enum *px_service, srv_dtcnt_sim_type_enum *sim_info, srv_dtcnt_bearer_enum *bearer, U8 * use_proxy)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int default_index = g_srv_dtcnt_store_ctx.default_acc_idx[*sim_id];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!acc_id && !px_service && !sim_info)
    {
        return MMI_TRUE;
    }

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_GET_DEFAULT_ACC_INFO, default_index);
    if (default_index)
    {
        if (default_index > SRV_DTCNT_PROF_MAX_ACCOUNT_NUM)
        {
            #ifdef __DTCNT_SIM_PROFILES_SUPPORT__
            U8 acc_list_sum = (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM + SRV_DTCNT_RESERVED_DM_ACC_NUM);
            U8 diff = default_index - acc_list_sum;
            MMI_ASSERT(default_index > acc_list_sum);
                
            #ifdef __TCPIP_OVER_CSD__
            if (diff < MAX_CSD_SIM_PROV_NUM)
            {
                if (acc_id)
                {
                    *acc_id = csd_sim_acc_list[diff-1].comm_header.acc_id;
                }
                if (px_service)
                {
                        *px_service = csd_sim_acc_list[diff-1].comm_header.px_service;
                }
                if (sim_info)
                {
                    *sim_info = csd_sim_acc_list[diff-1].comm_header.sim_info;
                }
                if(use_proxy)
                {
                	*use_proxy = csd_sim_acc_list[diff-1].comm_header.use_proxy;
                }
                if (bearer)
                {
                    *bearer = SRV_DTCNT_BEARER_CSD;
                }
                return MMI_TRUE;
            }
            #endif /* __TCPIP_OVER_CSD__ */

            #ifdef __MMI_GPRS_FEATURES__                    
                if (acc_id)
                {
                    *acc_id = gprs_sim_acc_list[diff-1].comm_header.acc_id;
                }
                if (px_service)
                {
                        *px_service = gprs_sim_acc_list[diff-1].comm_header.px_service;
                }
                if (sim_info)
                {
                    *sim_info = gprs_sim_acc_list[diff-1].comm_header.sim_info;
                }
                 if(use_proxy)
                {
                	*use_proxy = gprs_sim_acc_list[diff-1].comm_header.use_proxy;
                }
                if (bearer)
                {
                    *bearer = SRV_DTCNT_BEARER_GPRS;
                }
                return MMI_TRUE;
            #endif /* __MMI_GPRS_FEATURES__ */
            #endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */
            return MMI_FALSE;
        }
        else
        {
            if (acc_id)
            {
                *acc_id = g_srv_dtcnt_store_ctx.acc_list[default_index-1].acc_id;
            }
            if (px_service)
            {
                    *px_service = g_srv_dtcnt_store_ctx.acc_list[default_index-1].px_service;
            }
            if (sim_info)
            {
                *sim_info = g_srv_dtcnt_store_ctx.acc_list[default_index-1].sim_info;
            }
            if(use_proxy)
            {
            	*use_proxy = g_srv_dtcnt_store_ctx.acc_list[default_index-1].use_proxy;
            }
            if (bearer)
            {
                *bearer = g_srv_dtcnt_store_ctx.acc_list[default_index-1].bearer_type;
            }
            return MMI_TRUE;
        }
    }
    else
    { 
        return MMI_FALSE;
    }
}

U8 srv_dtcnt_db_store_find_best_fit_acct(U8 ap_id, U8 *best_fit_acc_id, cbm_sim_id_enum *sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_app_info_struct ap_info;
    int i;
    U8 tmp_id = 0xFF, tmp_acc_id = 0;
    srv_dtcnt_prof_px_srv_enum px_service;
    srv_dtcnt_bearer_enum bearer;
    srv_dtcnt_sim_type_enum prefer_sim = SRV_DTCNT_SIM_TYPE_1;
    U8 use_proxy = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_FIND_BEST_ACC, ap_id);
    srv_dtcnt_db_store_get_def_acc_info(sim_id, &tmp_acc_id, &px_service, &prefer_sim, &bearer, &use_proxy);

    if ((abm_get_registered_app_name(ap_id, &ap_info) == CBM_ERROR)||
        !(ap_info.app_type))
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_FIND_BEST_ACC_INVALID_INPUT_N_APP_TYPE_NULL);

        if (g_srv_dtcnt_store_ctx.default_acc_idx[*sim_id] && 
            *sim_id == srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(prefer_sim))

        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_FIND_BEST_ACC_RET_DEFAULT, tmp_acc_id, prefer_sim);
        }
        else
        {
            for (i = 0; i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
            {
                if (g_srv_dtcnt_store_ctx.acc_list[i].in_use && 
                    *sim_id == srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(g_srv_dtcnt_store_ctx.acc_list[i].sim_info))
                {
                    if (g_srv_dtcnt_store_ctx.acc_list[i].bearer_type == SRV_DTCNT_BEARER_GPRS)
                    {                               
                        tmp_acc_id = g_srv_dtcnt_store_ctx.acc_list[i].acc_id;
                        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_FIND_BEST_ACC_RET_ANY_GPRS, tmp_acc_id, (*sim_id));
                        goto return_acc_id;
                    }
                    else
                    {
                        tmp_id = (U8)i;
                    }
                }
            }
            if (i == SRV_DTCNT_PROF_MAX_ACCOUNT_NUM)
            {

                #if defined (__MMI_GPRS_FEATURES__) && defined (__DTCNT_SIM_PROFILES_SUPPORT__)
                for (i = 0; i<MAX_GPRS_SIM_PROV_NUM; i++)
                {

                    if (gprs_sim_acc_list[i].comm_header.in_use &&
                        *sim_id == srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(gprs_sim_acc_list[i].comm_header.sim_info))
                    {
                        tmp_acc_id = gprs_sim_acc_list[i].comm_header.acc_id;
                        *sim_id = srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(gprs_sim_acc_list[i].comm_header.sim_info);
                        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_FIND_BEST_ACC_RET_ANY_SIM_GPRS, tmp_acc_id, (*sim_id));
                        goto return_acc_id;
                    }
                }
                #endif /* defined (__MMI_GPRS_FEATURES__) && defined (__DTCNT_SIM_PROFILES_SUPPORT__) */

                if (tmp_id == 0xFF)
                {
                    //tmp_acc_id = CBM_INVALID_NWK_ACCT_ID;
                    tmp_acc_id = CBM_DEFAULT_ACCT_ID;
                }
                else
                {
                    tmp_acc_id = g_srv_dtcnt_store_ctx.acc_list[tmp_id].acc_id;
                    *sim_id = srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(g_srv_dtcnt_store_ctx.acc_list[tmp_id].sim_info);
                }
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_FIND_BEST_ACC_RET_ANY_CSD, tmp_acc_id, (*sim_id));
                goto return_acc_id;
            }
        }        
    }
    else /* app_type info exist */
    {
        srv_dtcnt_db_find_best_acct_cntx_struct smart_acct_cntx = {0,};

        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_FIND_BEST_ACC_APP_TYPE_EXIST);
        smart_acct_cntx.app_type = ap_info.app_type;
        smart_acct_cntx.best_fit_acc_id = best_fit_acc_id;
        smart_acct_cntx.sim_id = sim_id;
        smart_acct_cntx.default_bearer_type = bearer;
        smart_acct_cntx.default_px_service = px_service;
        smart_acct_cntx.default_sim_info = prefer_sim;
        smart_acct_cntx.use_proxy = use_proxy;
        
        if (ap_info.app_type & DTCNT_APPTYPE_SKIP_CSD)
        {
            smart_acct_cntx.skip_csd = 1;
        }

        if (ap_info.app_type & DTCNT_APPTYPE_NO_PX)
        {
            smart_acct_cntx.no_px_flag = 1;
        }
        if (ap_info.app_type & DTCNT_APPTYPE_NEED_PX)
        {
            smart_acct_cntx.need_px_flag = 1;
            //MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_FIND_BEST_ACC_APP_TYPE_NEED_PROXY);
        }


        if ((ap_info.app_type & DTCNT_APPTYPE_BRW_WAP || ap_info.app_type & DTCNT_APPTYPE_BRW_HTTP) &&
            ap_info.app_type & DTCNT_APPTYPE_SPECIFIC_PROFILE)
        {
            return srv_dtcnt_db_store_smart_acct(&smart_acct_cntx, 1);
        }
        else if (ap_info.app_type & DTCNT_APPTYPE_MMS)
        {
            return srv_dtcnt_db_store_smart_acct(&smart_acct_cntx, 2);
        }           
        /* DM handling */
        else if (ap_info.app_type & DTCNT_APPTYPE_DM)
        {
            U8 csd = CBM_INVALID_NWK_ACCT_ID;
            for (i = SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i < (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM + SRV_DTCNT_RESERVED_DM_ACC_NUM); i++)
            {
                if (g_srv_dtcnt_store_ctx.acc_list[i].in_use)
                {
                    if (g_srv_dtcnt_store_ctx.acc_list[i].bearer_type == SRV_DTCNT_BEARER_GPRS)
                    {
                        if (best_fit_acc_id)
                        {
                            *best_fit_acc_id = g_srv_dtcnt_store_ctx.acc_list[i].acc_id;
                            *sim_id = srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(g_srv_dtcnt_store_ctx.acc_list[i].sim_info);
                        }
                        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_FIND_BEST_ACC_RET_DM_GPRS, g_srv_dtcnt_store_ctx.acc_list[i].acc_id, (*sim_id));
                        return g_srv_dtcnt_store_ctx.acc_list[i].acc_id;
                    }
                    else
                    {
                        csd = g_srv_dtcnt_store_ctx.acc_list[i].acc_id;
                        *sim_id = srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(g_srv_dtcnt_store_ctx.acc_list[i].sim_info);
                    }                        
                }
            }
            if (best_fit_acc_id)
            {
                *best_fit_acc_id = csd;
            }
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_FIND_BEST_ACC_RET_DM_CSD, csd, (*sim_id));
            return csd;
        }
        else
        {
            return srv_dtcnt_db_store_smart_acct(&smart_acct_cntx, 0);
        }
    }

return_acc_id:
    if (best_fit_acc_id)
    {
        *best_fit_acc_id = tmp_acc_id;
    }
    return tmp_acc_id;    
}


/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_db_store_prof_query_ind_hdlr
 * DESCRIPTION
 *  Response for wps query
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_db_store_prof_query_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_profile_query_ind_struct *ind;
    mmi_abm_profile_query_rsp_struct *rsp;
    int i;
    U8 temp_acc_id;
    const vm_srv_dtcnt_info_t * mre_account = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_PROFILE_QUERY_IND_HDLR);
    ind = (mmi_abm_profile_query_ind_struct*) info;
    rsp = (mmi_abm_profile_query_rsp_struct *)construct_local_para(sizeof(mmi_abm_profile_query_rsp_struct), TD_RESET);
    rsp->account_id = ind->account_id;
    temp_acc_id = cbm_get_original_account(ind->account_id);
    rsp->result = KAL_FALSE;
    
    if( temp_acc_id == CBM_MRE_ACCT_ID )
    {
        mre_account = srv_mre_get_cust_dtcnt_info();

        kal_mem_cpy(rsp->content.user_name, mre_account->UserName, 32);
        kal_mem_cpy(rsp->content.password, mre_account->Passwd, 32);
        kal_mem_cpy(rsp->content.dns, mre_account->PrimaryAddr, 4);
        rsp->content.ps_account_info.apn_length = strlen((S8*)mre_account->APN);
        strncpy((S8 *)rsp->content.ps_account_info.apn, (S8 *)mre_account->APN, rsp->content.ps_account_info.apn_length);

        rsp->content.ps_account_info.dcomp_algo = SND_NO_DCOMP;
        rsp->content.ps_account_info.hcomp_algo = SND_NO_DCOMP;
        rsp->content.ps_account_info.pdp_type = IPV4_ADDR_TYPE;
        rsp->content.ps_account_info.pdp_addr_len = IPV4_ADDR_LEN; 

        rsp->content.authentication_type = SRV_DTCNT_PROF_GPRS_AUTH_TYPE_NORMAL;
        rsp->result = KAL_TRUE;
        
        srv_dtcnt_db_store_send_msg(MSG_ID_MMI_ABM_PROFILE_QUERY_RSP, (void *)rsp, MOD_ABM);
        
        return;
    }
    
    for (i = 0; i < (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM + SRV_DTCNT_RESERVED_DM_ACC_NUM); i++)
    {
        if (g_srv_dtcnt_store_ctx.acc_list[i].in_use &&
            g_srv_dtcnt_store_ctx.acc_list[i].acc_id == temp_acc_id)
        {
            srv_dtcnt_account_info_st *tmp_p = &(g_srv_dtcnt_store_ctx.acc_list[i]);
            U32 fields = tmp_p->fields;
            
            if (fields & SRV_DTCNT_PROF_FIELD_AUTH_USER_ID)
            {
                kal_mem_cpy(rsp->content.user_name, tmp_p->auth_info.UserName, 32);
            }
            if (fields & SRV_DTCNT_PROF_FIELD_AUTH_USER_PW)
            {
                kal_mem_cpy(rsp->content.password, tmp_p->auth_info.Passwd, 32);
            }
            if (fields & SRV_DTCNT_PROF_FIELD_INET_PRI_DNS)
            {
                kal_mem_cpy(rsp->content.dns, tmp_p->PrimaryAddr, 4);
            }
            if (fields & SRV_DTCNT_PROF_FIELD_INET_SEC_DNS)
            {
                kal_mem_cpy(rsp->content.sec_dns, tmp_p->SecondaryAddr, 4);
            }
#ifdef __MMI_GPRS_FEATURES__
            if (tmp_p->bearer_type == SRV_DTCNT_BEARER_GPRS)
            {
                rsp->content.ps_account_info.apn_length = strlen((CHAR*)tmp_p->dest_name);
                strncpy((CHAR *)rsp->content.ps_account_info.apn, (CHAR *)tmp_p->dest_name, rsp->content.ps_account_info.apn_length);
                rsp->content.ps_account_info.dcomp_algo = SND_NO_DCOMP;
                rsp->content.ps_account_info.hcomp_algo = SND_NO_DCOMP;
                rsp->content.ps_account_info.pdp_type = IPV4_ADDR_TYPE;
                rsp->content.ps_account_info.pdp_addr_len = IPV4_ADDR_LEN;                
                rsp->content.authentication_type = tmp_p->auth_info.AuthType;
                
                rsp->result = KAL_TRUE;
                break;
            }
#endif /* __MMI_GPRS_FEATURES__ */

#ifdef __TCPIP_OVER_CSD__
            if (tmp_p->bearer_type == SRV_DTCNT_BEARER_CSD)
            {                
                kal_mem_cpy(rsp->content.csd_account_info.addr_str, tmp_p->dest_name, 23);
                switch (tmp_p->DataRate)
                {
                    case SRV_DTCNT_PROF_CSD_RATE_TWO_FOUR:
                        rsp->content.csd_account_info.csd_ur = (U8) CSD_PROF_RATE_2400;
                        break;
                    case SRV_DTCNT_PROF_CSD_RATE_FOUR_EIGHT:
                        rsp->content.csd_account_info.csd_ur = (U8) CSD_PROF_RATE_4800;
                        break;
                    case SRV_DTCNT_PROF_CSD_RATE_NINE_SIX:
                        rsp->content.csd_account_info.csd_ur = (U8) CSD_PROF_RATE_9600;
                        break;
                    case SRV_DTCNT_PROF_CSD_RATE_FOURTEEN_FOUR:
                        rsp->content.csd_account_info.csd_ur = (U8) CSD_PROF_RATE_14400;
                        break;
                    case SRV_DTCNT_PROF_CSD_RATE_AUTO:
                    default:
                        rsp->content.csd_account_info.csd_ur = (U8) CSD_PROF_RATE_AUTO;
                        break;
                }
                
                if (tmp_p->DialType == SRV_DTCNT_PROF_CSD_DIAL_TYPE_ANALOGUE)
                {
                    rsp->content.csd_account_info.csd_type = (U8) CSMCC_ITC_3_1_K_AUDIO;
                }
                else
                {
                    rsp->content.csd_account_info.csd_type = (U8) CSMCC_ITC_UDI;
                }
                
                rsp->result = KAL_TRUE;
                break;
            }
#endif /* __TCPIP_OVER_CSD__ */
        }
    }

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__        
#ifdef  __TCPIP_OVER_CSD__
    if (g_srv_dtcnt_store_ctx.ctrl_block.csd_sim_acc_num)
    {
        for (i = 0; i<MAX_CSD_SIM_PROV_NUM; i++)
        {
            if (csd_sim_acc_list[i].comm_header.in_use &&
                csd_sim_acc_list[i].comm_header.acc_id == temp_acc_id)
            {
                srv_dtcnt_sim_csd_account_info_st *tmp_p = &(csd_sim_acc_list[i]);
                U32 fields = tmp_p->comm_header.fields;
                
                if (fields & SRV_DTCNT_PROF_FIELD_AUTH_USER_ID)
                {
                    kal_mem_cpy(rsp->content.user_name, tmp_p->comm_header.UserName, 32);
                }
                if (fields & SRV_DTCNT_PROF_FIELD_AUTH_USER_PW)
                {
                    kal_mem_cpy(rsp->content.password, tmp_p->comm_header.Passwd, 32);
                }
                if (fields & SRV_DTCNT_PROF_FIELD_INET_PRI_DNS)
                {
                    kal_mem_cpy(rsp->content.dns, tmp_p->comm_header.PrimaryAddr, 4);
                }
                
                kal_mem_cpy(rsp->content.csd_account_info.addr_str, tmp_p->DialNumber, 23);
                switch (tmp_p->DataRate)
                {
                    case SRV_DTCNT_PROF_CSD_RATE_TWO_FOUR:
                        rsp->content.csd_account_info.csd_ur = (U8) CSD_PROF_RATE_2400;
                        break;
                    case SRV_DTCNT_PROF_CSD_RATE_FOUR_EIGHT:
                        rsp->content.csd_account_info.csd_ur = (U8) CSD_PROF_RATE_4800;
                        break;
                    case SRV_DTCNT_PROF_CSD_RATE_NINE_SIX:
                        rsp->content.csd_account_info.csd_ur = (U8) CSD_PROF_RATE_9600;
                        break;
                    case SRV_DTCNT_PROF_CSD_RATE_FOURTEEN_FOUR:
                        rsp->content.csd_account_info.csd_ur = (U8) CSD_PROF_RATE_14400;
                        break;
                    case SRV_DTCNT_PROF_CSD_RATE_AUTO:
                    default:
                        rsp->content.csd_account_info.csd_ur = (U8) CSD_PROF_RATE_AUTO;
                        break;
                }
                
                if (tmp_p->DialType == SRV_DTCNT_PROF_CSD_DIAL_TYPE_ANALOGUE)
                {
                    rsp->content.csd_account_info.csd_type = (U8) CSMCC_ITC_3_1_K_AUDIO;
                }
                else
                {
                    rsp->content.csd_account_info.csd_type = (U8) CSMCC_ITC_UDI;
                }
                
                rsp->result = KAL_TRUE;
                break;
            }
        }
    }
#endif /* __TCPIP_OVER_CSD__ */    
#ifdef __MMI_GPRS_FEATURES__
    if (g_srv_dtcnt_store_ctx.ctrl_block.gprs_sim_acc_num)
    {
        for (i = 0; i<MAX_GPRS_SIM_PROV_NUM; i++)
        {
            if (gprs_sim_acc_list[i].comm_header.in_use &&
                gprs_sim_acc_list[i].comm_header.acc_id == temp_acc_id)
            {
                srv_dtcnt_sim_gprs_account_info_st *tmp_p = &(gprs_sim_acc_list[i]);
                U32 fields = tmp_p->comm_header.fields;
                
                if (fields & SRV_DTCNT_PROF_FIELD_AUTH_USER_ID)
                {
                    kal_mem_cpy(rsp->content.user_name, tmp_p->comm_header.UserName, 32);
                }
                if (fields & SRV_DTCNT_PROF_FIELD_AUTH_USER_PW)
                {
                    kal_mem_cpy(rsp->content.password, tmp_p->comm_header.Passwd, 32);
                }
                if (fields & SRV_DTCNT_PROF_FIELD_INET_PRI_DNS)
                {
                    kal_mem_cpy(rsp->content.dns, tmp_p->comm_header.PrimaryAddr, 4);
                }
                
                rsp->content.ps_account_info.apn_length = strlen((CHAR*)tmp_p->APN);
                strncpy((CHAR *)rsp->content.ps_account_info.apn, (CHAR *)tmp_p->APN, rsp->content.ps_account_info.apn_length);
                rsp->content.ps_account_info.dcomp_algo = SND_NO_DCOMP;
                rsp->content.ps_account_info.hcomp_algo = SND_NO_DCOMP;
                rsp->content.ps_account_info.pdp_type = IPV4_ADDR_TYPE;
                rsp->content.ps_account_info.pdp_addr_len = IPV4_ADDR_LEN;                
                rsp->content.authentication_type = tmp_p->AuthType;
                
                rsp->result = KAL_TRUE;
                break;
            }
        }
    }
#endif /* __MMI_GPRS_FEATURES__ */   
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */

    srv_dtcnt_db_store_send_msg(MSG_ID_MMI_ABM_PROFILE_QUERY_RSP, (void *)rsp, MOD_ABM);
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_db_store_prof_query_ind_hdlr
 * DESCRIPTION
 *  Response for wps query
 * PARAMETERS
 *  info        [IN]        Local parameters from protocol
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dtcnt_db_store_prof_proxy_info_req_hdlr(void *info, int mod_src, void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_prof_proxy_info_req_struct *req;
    srv_dtcnt_prof_proxy_info_cnf_struct *cnf;
    srv_dtcnt_prof_proxy_info_struct out_px_info = {0,};
    cbm_account_info_struct acct_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_PROFILE_PROXY_INFO_REQ_HDLR);
    req = (srv_dtcnt_prof_proxy_info_req_struct*) info;

    cnf = (srv_dtcnt_prof_proxy_info_cnf_struct *)construct_local_para(sizeof(srv_dtcnt_prof_proxy_info_cnf_struct), TD_RESET);    
    if (!srv_dtcnt_get_proxy_info(req->acc_id, &out_px_info, req->idx))
    {
        cnf->result = 0;        
    }
    else
    {
        cnf->result = 1;
        cnf->px_info.use_proxy = out_px_info.use_proxy;

        cbm_decode_data_account_id_ext(req->acc_id, &acct_info);
        acct_info.account[req->idx-1].account_id = out_px_info.acc_id;
        cbm_encode_data_account_id_ext(req->acc_id, &(cnf->px_info.acc_id), &acct_info);

        cnf->px_info.px_addrtype = out_px_info.px_addrtype;
        cnf->px_info.px_port = out_px_info.px_port;
        cnf->px_info.px_service = out_px_info.px_service;        
        kal_mem_cpy(cnf->px_info.px_addr, out_px_info.px_addr, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1);
        kal_mem_cpy(cnf->px_info.px_authid, out_px_info.px_authid, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1);
        kal_mem_cpy(cnf->px_info.px_authpw, out_px_info.px_authpw, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1);
        kal_mem_cpy(cnf->px_info.px_startpage, out_px_info.px_startpage, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1);
    }
    cnf->request_id = req->request_id;
    srv_dtcnt_db_store_send_msg(MSG_ID_SRV_DTCNT_PROF_PROXY_INFO_CNF, (void *)cnf, mod_src);
}


MMI_BOOL srv_dtcnt_db_store_status_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 acc_num = g_srv_dtcnt_store_ctx.ctrl_block.total_acc_num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_STATUS_CHECK, g_srv_dtcnt_context.store_status, acc_num);
    if(srv_dtcnt_db_store_check_ignore_num()==MMI_FALSE)
    {
            return MMI_FALSE;
    }

#ifdef __DTCNT_SIM_PROFILES_SUPPORT__        
#ifdef  __TCPIP_OVER_CSD__
    acc_num += g_srv_dtcnt_store_ctx.ctrl_block.csd_sim_acc_num;
#endif /* __TCPIP_OVER_CSD__ */    
#ifdef __MMI_GPRS_FEATURES__
    acc_num += g_srv_dtcnt_store_ctx.ctrl_block.gprs_sim_acc_num;
#endif /* __MMI_GPRS_FEATURES__ */   
#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */

    if (!acc_num)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


srv_dtcnt_account_info_st* srv_dtcnt_db_store_get_acc_info(U8 acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    for (i = 0; i < (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM + SRV_DTCNT_RESERVED_DM_ACC_NUM); i++)
    {
        if (g_srv_dtcnt_store_ctx.acc_list[i].in_use &&
            g_srv_dtcnt_store_ctx.acc_list[i].acc_id == acc_id)            
        {       
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_GET_ACC_INFO_SUCCESS);
            return &(g_srv_dtcnt_store_ctx.acc_list[i]);
        }
    }
    return NULL;
}

srv_dtcnt_account_info_st* srv_dtcnt_db_store_get_acc_info_by_apn(CHAR *apn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    srv_dtcnt_sim_type_enum sim_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    srv_dtcnt_get_sim_preference(&sim_info);
    for (i = 0; i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
    {
        if (g_srv_dtcnt_store_ctx.acc_list[i].in_use &&
            g_srv_dtcnt_store_ctx.acc_list[i].bearer_type == SRV_DTCNT_BEARER_GPRS &&
            g_srv_dtcnt_store_ctx.acc_list[i].sim_info == sim_info)            
        {       
            if (!app_stricmp((CHAR *)g_srv_dtcnt_store_ctx.acc_list[i].dest_name, apn))
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_GET_ACC_INFO_BY_APN_SUCCESS);
                return &(g_srv_dtcnt_store_ctx.acc_list[i]);
            }
        }
    }
    return NULL;
}

U8 srv_dtcnt_extract_specified_acc_id(U32 acc_id, srv_dtcnt_account_enum idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 decoded_acc_id;
    cbm_account_info_struct acct_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_dtcnt_get_auto_acc_id(acc_id, &decoded_acc_id) != SRV_DTCNT_RESULT_SUCCESS)
    {
        return CBM_INVALID_NWK_ACCT_ID;
    }

    cbm_decode_data_account_id_ext(decoded_acc_id, &acct_info);
    
    if (acct_info.acct_num == 0)
    {
        return CBM_INVALID_NWK_ACCT_ID;
    }
    else if (acct_info.acct_num == 1)
    {
        return acct_info.account[0].account_id;
    }
    else
    {
        return acct_info.account[idx-1].account_id;
    }

}

void srv_dtcnt_db_store_send_acc_update_post_evt(U8 acc_id, srv_dtcnt_sim_type_enum sim_info, U8 sim_changed, U8 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id_old = g_srv_dtcnt_context.acct_update_evt_sim_id_old;
    srv_dtcnt_acct_update_ind_evt_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND);    

    /* construct event struct */
    evt.sim_id_old = evt.sim_id = sim_info;
    if (sim_changed)
    {
        evt.sim_id_old = sim_id_old;
    }
    evt.acc_id = (U32)acc_id;
    evt.cause = cause;

//#ifdef __CCA_SUPPORT__
#ifdef __MMI_CCA_SUPPORT__
    if (g_srv_dtcnt_ota_ongoing == MMI_TRUE)
    {
        evt.cause = 1;
        if (g_srv_dtcnt_context.acct_update_evt_sim_id_old != SRV_DTCNT_SIM_TYPE_TOTAL)
        {
            evt.sim_id_old = g_srv_dtcnt_context.acct_update_evt_sim_id_old;
        }
    }
#endif /* __CCA_SUPPORT__ */

    g_srv_dtcnt_context.acct_update_evt_sim_id_old = SRV_DTCNT_SIM_TYPE_TOTAL;

    MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);
}

void srv_dtcnt_db_store_send_acc_delete_post_evt(U8 acc_id, srv_dtcnt_sim_type_enum sim_info, MMI_BOOL sync_done)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = (U8)sim_info;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( sim_id < 1 || sim_id > 4 )
    {
            MMI_ASSERT(0);
    }
    
    if (sync_done)
    {
        srv_dtcnt_acct_delete_ind_evt_struct evt;        
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_DTCNT_ACCT_DELETE_IND);

        /* sync all deleted accounts by sim replacement */
        if (acc_id == CBM_INVALID_NWK_ACCT_ID)
        {
            evt.cause = 1;
            evt.del_num = g_srv_dtcnt_del_evt.del_num;
            kal_mem_cpy(evt.sim_id, g_srv_dtcnt_del_evt.sim_id, SRV_DTCNT_PROF_MAX_ACCOUNT_NUM);
            kal_mem_cpy(evt.acc_id, g_srv_dtcnt_del_evt.acc_id, (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM * sizeof(U32)));
        }
        else
        {
            evt.cause = 0;
            evt.del_num = 1;
            evt.sim_id[0] = sim_id;
            evt.acc_id[0] = acc_id;
        }
        MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);
    }
    else /* only update del_account_gv, wait for sync done */
    {
        g_srv_dtcnt_del_evt.sim_id[g_srv_dtcnt_del_evt.del_num] = sim_id;
        g_srv_dtcnt_del_evt.acc_id[g_srv_dtcnt_del_evt.del_num] = acc_id;
        g_srv_dtcnt_del_evt.del_num++;
    }
}


#ifdef __DTCNT_SIM_PROFILES_SUPPORT__
U8 srv_dtcnt_db_store_find_best_mms_sim_acct(srv_dtcnt_db_find_best_acct_cntx_struct *best_acct_ctx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

#ifdef __MMI_GPRS_FEATURES__
    for (i = 0; i<MAX_GPRS_SIM_PROV_NUM; i++)
    {
        if (gprs_sim_acc_list[i].comm_header.in_use && 
            srv_dtcnt_db_store_smart_acct_check(
                    best_acct_ctx, 
                    gprs_sim_acc_list[i].comm_header.sim_info,
                    gprs_sim_acc_list[i].comm_header.px_service,
                    SRV_DTCNT_BEARER_GPRS,
                    MMI_FALSE,
                    0, gprs_sim_acc_list[i].comm_header.use_proxy))
        {
            if (gprs_sim_acc_list[i].comm_header.sim_info == (*(best_acct_ctx->sim_id)+1))
            {
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_FIND_BEST_MMS_ACC_SAME_SIM_SIM_GPRS, gprs_sim_acc_list[i].comm_header.acc_id, *(best_acct_ctx->sim_id));
                return gprs_sim_acc_list[i].comm_header.acc_id;                
            }
        }
    }
#endif /* __MMI_GPRS_FEATURES__ */

    if (best_acct_ctx->skip_csd)
    {
        return CBM_INVALID_NWK_ACCT_ID;
    }
    else /* don't skip csd account */
    {
#ifdef  __TCPIP_OVER_CSD__
        for (i = 0; i<MAX_CSD_SIM_PROV_NUM; i++)
        {
            if (csd_sim_acc_list[i].comm_header.in_use && 
                srv_dtcnt_db_store_smart_acct_check(
                        best_acct_ctx,
                        csd_sim_acc_list[i].comm_header.sim_info,
                        csd_sim_acc_list[i].comm_header.px_service,
                        SRV_DTCNT_BEARER_CSD,
                        MMI_FALSE,
                        0, csd_sim_acc_list[i].comm_header.use_proxy))
            {
                if (csd_sim_acc_list[i].comm_header.sim_info == (*(best_acct_ctx->sim_id)+1))
                {
                    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_FIND_BEST_MMS_ACC_SAME_SIM_SIM_CSD, csd_sim_acc_list[i].comm_header.acc_id, *(best_acct_ctx->sim_id));
                    return csd_sim_acc_list[i].comm_header.acc_id;
                }
            }
        }
#endif /* __TCPIP_OVER_CSD__ */

    return CBM_INVALID_NWK_ACCT_ID;
    }
}

void srv_dtcnt_db_store_sim_info_convert(srv_dtcnt_sim_comm_account_info_st *sim_acc_info, srv_dtcnt_account_info_st *out_acc_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_mem_set(out_acc_info, 0, sizeof(srv_dtcnt_account_info_st));
    mmi_ucs2ncpy((char *)out_acc_info->acc_name, (char *)sim_acc_info->acc_name, SRV_DTCNT_PROF_MAX_ACC_NAME_LEN);    
    out_acc_info->acc_type = SRV_DTCNT_PROF_TYPE_SIM_PROF;
    out_acc_info->sim_info = sim_acc_info->sim_info;
    out_acc_info->fields = sim_acc_info->fields;
    out_acc_info->px_service = sim_acc_info->px_service;    
    strncpy((CHAR *)out_acc_info->auth_info.UserName, (CHAR *)sim_acc_info->UserName, SRV_DTCNT_PROF_MAX_USER_LEN);
    strncpy((CHAR *)out_acc_info->auth_info.Passwd, (CHAR *)sim_acc_info->Passwd, SRV_DTCNT_PROF_MAX_PW_LEN);
}

MMI_BOOL srv_dtcnt_db_store_qry_sim_acc_info(U8 acc_id, srv_dtcnt_account_info_st *out_acc_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (!out_acc_info)
    {
        return MMI_FALSE;
    }

#ifdef  __TCPIP_OVER_CSD__
    for (i = 0; i<MAX_CSD_SIM_PROV_NUM; i++)
    {
        if (csd_sim_acc_list[i].comm_header.in_use &&
            csd_sim_acc_list[i].comm_header.acc_id == acc_id)
        {
            srv_dtcnt_db_store_sim_info_convert(&(csd_sim_acc_list[i].comm_header), out_acc_info);
            strncpy((CHAR *)out_acc_info->dest_name, (CHAR *)csd_sim_acc_list[i].DialNumber, SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN);
            out_acc_info->DataRate = csd_sim_acc_list[i].DataRate;
            out_acc_info->DialType = csd_sim_acc_list[i].DialType;
            out_acc_info->bearer_type = SRV_DTCNT_BEARER_CSD;
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_QRY_SIM_ACC_INFO_CSD, acc_id);
            return MMI_TRUE;
        }
    }
#endif /* __TCPIP_OVER_CSD__ */    
#ifdef __MMI_GPRS_FEATURES__
    for (i = 0; i<MAX_GPRS_SIM_PROV_NUM; i++)
    {
        if (gprs_sim_acc_list[i].comm_header.in_use &&
            gprs_sim_acc_list[i].comm_header.acc_id == acc_id)
        {
            srv_dtcnt_db_store_sim_info_convert(&(gprs_sim_acc_list[i].comm_header), out_acc_info);
            strncpy((CHAR *)out_acc_info->dest_name, (CHAR *)gprs_sim_acc_list[i].APN, SRV_DTCNT_PROF_MAX_APN_LEN);
            out_acc_info->auth_info.AuthType = gprs_sim_acc_list[i].AuthType;
            out_acc_info->bearer_type = SRV_DTCNT_BEARER_GPRS;
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_QRY_SIM_ACC_INFO_GPRS, acc_id);
            return MMI_TRUE;
        }
    }
#endif /* __MMI_GPRS_FEATURES__ */

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_QRY_SIM_ACC_INFO_FAILED, acc_id);
    return MMI_FALSE;
}
U8 srv_dtcnt_get_sim_gprs_account_num(srv_dtcnt_sim_type_enum sim_info)
{
    U32 i = 0;
    U8 count = 0;
    for(i = 0; i < MAX_GPRS_SIM_PROV_NUM; i++)
    {
        if(gprs_sim_acc_list[i].comm_header.in_use == 1 && 
            gprs_sim_acc_list[i].comm_header.sim_info == sim_info)
        {
            count++;
        }
    }
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT,SRV_DTCNT_DB_ACCOUNT_NUM, sim_info,count);
    return count;

}
U8 srv_dtcnt_get_sim_csd_account_num(srv_dtcnt_sim_type_enum sim_info)
{
    U32 i = 0;
    U8 count = 0;
    #ifdef __TCPIP_OVER_CSD__
    for(i = 0; i < MAX_CSD_SIM_PROV_NUM; i++)
    {
        if(csd_sim_acc_list[i].comm_header.in_use == 1 && 
            csd_sim_acc_list[i].comm_header.sim_info == sim_info)
        {
            count++;
        }
    }
    #endif
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT,SRV_DTCNT_DB_ACCOUNT_NUM, sim_info,count);
    return count;
}

srv_dtcnt_result_enum srv_dtcnt_db_store_add_sim_prof(void *data, srv_dtcnt_bearer_enum type, U32 *out_acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    mmi_abm_update_account_info_req_struct *info_req = NULL;
    U32 encoded_acc_id;
    cbm_sim_id_enum sim_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_ADD_SIM_PROF, type);
#ifdef  __TCPIP_OVER_CSD__
    if (type == SRV_DTCNT_BEARER_CSD)
    {
        srv_dtcnt_sim_csd_account_info_st *csd = (srv_dtcnt_sim_csd_account_info_st *)data;
        for (i = 0; i<MAX_CSD_SIM_PROV_NUM; i++)
        {
            if (csd_sim_acc_list[i].comm_header.in_use == 0
                && srv_dtcnt_get_sim_csd_account_num(csd_sim_acc_list[i].comm_header.sim_info)<MAX_CSD_SIM_PROV_NUM_PER_SIM)
            {
                kal_mem_cpy(&(csd_sim_acc_list[i]), csd, sizeof(srv_dtcnt_sim_csd_account_info_st));
                csd_sim_acc_list[i].comm_header.acc_id = SRV_DTCNT_PROF_MAX_ACCOUNT_NUM + SRV_DTCNT_RESERVED_DM_ACC_NUM + i;
                csd_sim_acc_list[i].comm_header.in_use = 1;
                if (out_acc_id)
                {
                    *out_acc_id = csd_sim_acc_list[i].comm_header.acc_id;
                }
                g_srv_dtcnt_store_ctx.ctrl_block.csd_sim_acc_num++;
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_ADD_SIM_CSD_PROF_DONE, csd_sim_acc_list[i].comm_header.acc_id);
                
                info_req = (mmi_abm_update_account_info_req_struct *)construct_local_para(sizeof(mmi_abm_update_account_info_req_struct), TD_RESET);
                info_req->action = MMI_ABM_PROFILE_ADD;
                sim_id = srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(csd_sim_acc_list[i].comm_header.sim_info);
                encoded_acc_id = cbm_encode_data_account_id((U32)csd_sim_acc_list[i].comm_header.acc_id, sim_id, 0, KAL_FALSE);
                info_req->account_id = encoded_acc_id;
                info_req->bearer_type = CBM_CSD;
                srv_dtcnt_db_store_send_msg(MSG_ID_MMI_ABM_UPDATE_ACCOUNT_INFO_REQ, (void *)info_req, MOD_ABM);
                
                return SRV_DTCNT_RESULT_SUCCESS;
            }
        }
        return SRV_DTCNT_RESULT_STORE_FULL;
    }
#endif /* __TCPIP_OVER_CSD__ */    
#ifdef __MMI_GPRS_FEATURES__
    if (type == SRV_DTCNT_BEARER_GPRS)
    {
        srv_dtcnt_sim_gprs_account_info_st *gprs = (srv_dtcnt_sim_gprs_account_info_st *)data;
        for (i = 0; i<MAX_GPRS_SIM_PROV_NUM; i++)
        {
            if (gprs_sim_acc_list[i].comm_header.in_use == 0 
                && srv_dtcnt_get_sim_gprs_account_num(gprs_sim_acc_list[i].comm_header.sim_info)<MAX_GPRS_SIM_PROV_NUM_PER_SIM)
            {
                kal_mem_cpy(&(gprs_sim_acc_list[i]), gprs, sizeof(srv_dtcnt_sim_gprs_account_info_st));
            #ifdef __TCPIP_OVER_CSD__
                gprs_sim_acc_list[i].comm_header.acc_id = SRV_DTCNT_PROF_MAX_ACCOUNT_NUM + SRV_DTCNT_RESERVED_DM_ACC_NUM + MAX_CSD_SIM_PROV_NUM + i;
            #else /* !__TCPIP_OVER_CSD__ */
                gprs_sim_acc_list[i].comm_header.acc_id = SRV_DTCNT_PROF_MAX_ACCOUNT_NUM + SRV_DTCNT_RESERVED_DM_ACC_NUM + i;
            #endif /* __TCPIP_OVER_CSD__ */                
                gprs_sim_acc_list[i].comm_header.in_use = 1;
                if (out_acc_id)
                {
                    *out_acc_id = gprs_sim_acc_list[i].comm_header.acc_id;
                }
                MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_ADD_SIM_GPRS_PROF_DONE, gprs_sim_acc_list[i].comm_header.acc_id);                
                g_srv_dtcnt_store_ctx.ctrl_block.gprs_sim_acc_num++;
                
                info_req = (mmi_abm_update_account_info_req_struct *)construct_local_para(sizeof(mmi_abm_update_account_info_req_struct), TD_RESET);
                info_req->action = MMI_ABM_PROFILE_ADD;
                sim_id = srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(gprs_sim_acc_list[i].comm_header.sim_info);
                encoded_acc_id = cbm_encode_data_account_id((U32)gprs_sim_acc_list[i].comm_header.acc_id, sim_id, 0, KAL_FALSE);
                info_req->account_id = encoded_acc_id;
                info_req->bearer_type = CBM_PS;
                srv_dtcnt_db_store_send_msg(MSG_ID_MMI_ABM_UPDATE_ACCOUNT_INFO_REQ, (void *)info_req, MOD_ABM);
                
                return SRV_DTCNT_RESULT_SUCCESS;
            }
        }
        return SRV_DTCNT_RESULT_STORE_FULL;
    }
#endif /* __MMI_GPRS_FEATURES__ */

    return SRV_DTCNT_RESULT_FAILED;
}

MMI_BOOL srv_dtcnt_db_store_sim_prof_filter(srv_dtcnt_store_prof_qry_filter_struct *filter, srv_dtcnt_sim_comm_account_info_st *target, srv_dtcnt_bearer_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(filter && target);

    if (filter->filters & SRV_DTCNT_STORE_QRY_TYPE_SIM)
    {
        if (target->sim_info != filter->sim_qry_info)
        {
            return MMI_FALSE;
        }
    }
    if (filter->filters & SRV_DTCNT_STORE_QRY_TYPE_BEARER_TYPE)
    {
        if (type != filter->bearer_qry_info)
        {
            return MMI_FALSE;
        }
    }
    if (filter->filters & SRV_DTCNT_STORE_QRY_TYPE_ACC_TYPE)
    {
        if (SRV_DTCNT_PROF_TYPE_SIM_PROF != filter->acc_type_info)
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;    
}

srv_dtcnt_sim_comm_account_info_st* srv_dtcnt_db_store_get_sim_acc_info(U8 acc_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef  __TCPIP_OVER_CSD__
    for (i = 0; i<MAX_CSD_SIM_PROV_NUM; i++)
    {
        if (csd_sim_acc_list[i].comm_header.in_use &&
            csd_sim_acc_list[i].comm_header.acc_id == acc_id)
        {            
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_GET_SIM_CSD_ACC_INFO_SUCCESS);
            return &(csd_sim_acc_list[i].comm_header);
        }
    }
#endif /* __TCPIP_OVER_CSD__ */    
#ifdef __MMI_GPRS_FEATURES__
    for (i = 0; i<MAX_GPRS_SIM_PROV_NUM; i++)
    {
        if (gprs_sim_acc_list[i].comm_header.in_use &&
            gprs_sim_acc_list[i].comm_header.acc_id == acc_id)
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_GET_SIM_GPRS_ACC_INFO_SUCCESS);
            return &(gprs_sim_acc_list[i].comm_header);
        }
    }
#endif /* __MMI_GPRS_FEATURES__ */
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_STORE_GET_SIM_ACC_INFO_FAILED);
    return NULL;
}


#ifdef __TCPIP_OVER_CSD__
srv_dtcnt_result_enum srv_dtcnt_db_store_sim_csd_prof_fillin(srv_dtcnt_prof_csd_struct *dest, srv_dtcnt_sim_csd_account_info_st *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!dest || !src)
    {
        return SRV_DTCNT_RESULT_FAILED;
    }

    dest->prof_common_header.acc_id = src->comm_header.acc_id;
    dest->prof_common_header.AccountName = src->comm_header.acc_name;
    dest->prof_common_header.acct_type = SRV_DTCNT_PROF_TYPE_SIM_PROF;
    dest->prof_common_header.sim_info = src->comm_header.sim_info;
    kal_mem_cpy(dest->prof_common_header.Auth_info.UserName, src->comm_header.UserName, SRV_DTCNT_PROF_MAX_USER_LEN+1);
    kal_mem_cpy(dest->prof_common_header.Auth_info.Passwd, src->comm_header.Passwd, SRV_DTCNT_PROF_MAX_PW_LEN+1);    
    kal_mem_cpy(dest->prof_common_header.PrimaryAddr, src->comm_header.PrimaryAddr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    kal_mem_cpy(dest->prof_common_header.napid_hash_val, src->comm_header.napid_hash_val, SRV_DTCNT_NAPID_HASH_LEN);
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    kal_mem_cpy(dest->prof_common_header.provurl_hash_val, src->comm_header.provurl_hash_val, SRV_DTCNT_PROVURL_HASH_LEN);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    dest->prof_common_header.read_only = 1;    
    dest->prof_common_header.use_proxy = src->comm_header.use_proxy;
    dest->prof_common_header.px_port = src->comm_header.px_port;
    dest->prof_common_header.AppType = src->comm_header.app_type;
    dest->prof_common_header.px_service = src->comm_header.px_service;
    kal_mem_cpy(dest->prof_common_header.HomePage, src->comm_header.HomePage, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1);
    kal_mem_cpy(dest->prof_common_header.px_addr, src->comm_header.px_addr, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN+1);
    kal_mem_cpy(dest->prof_common_header.px_authid, src->comm_header.px_authid, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN+1);
    kal_mem_cpy(dest->prof_common_header.px_authpw, src->comm_header.px_authpw, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN+1);
    dest->DialNumber = src->DialNumber;
    dest->DataRate = src->DataRate;
    dest->DialType = src->DialType;

    return SRV_DTCNT_RESULT_SUCCESS;    
}
#endif /* __TCPIP_OVER_CSD__ */

#ifdef __MMI_GPRS_FEATURES__
srv_dtcnt_result_enum srv_dtcnt_db_store_sim_gprs_prof_fillin(srv_dtcnt_prof_gprs_struct *dest, srv_dtcnt_sim_gprs_account_info_st *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!dest || !src)
    {
        return SRV_DTCNT_RESULT_FAILED;
    }

    dest->prof_common_header.acc_id = src->comm_header.acc_id;
    dest->prof_common_header.AccountName = src->comm_header.acc_name;
    dest->prof_common_header.acct_type = SRV_DTCNT_PROF_TYPE_SIM_PROF;
    dest->prof_common_header.sim_info = src->comm_header.sim_info;
    //dest->prof_common_header.px_service = SRV_DTCNT_PROF_PX_SRV_HTTP;
    kal_mem_cpy(dest->prof_common_header.Auth_info.UserName, src->comm_header.UserName, SRV_DTCNT_PROF_MAX_USER_LEN+1);
    kal_mem_cpy(dest->prof_common_header.Auth_info.Passwd, src->comm_header.Passwd, SRV_DTCNT_PROF_MAX_PW_LEN+1);    
    kal_mem_cpy(dest->prof_common_header.PrimaryAddr, src->comm_header.PrimaryAddr, SRV_DTCNT_PROF_MAX_IP_ADDR_LEN);
    kal_mem_cpy(dest->prof_common_header.napid_hash_val, src->comm_header.napid_hash_val, SRV_DTCNT_NAPID_HASH_LEN);
#ifdef __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__
    kal_mem_cpy(dest->prof_common_header.provurl_hash_val, src->comm_header.provurl_hash_val, SRV_DTCNT_PROVURL_HASH_LEN);
#endif /* __MMI_CCA_OMACP_BOOTSTRAP_UPDATE_SUPPORT__ */
    dest->prof_common_header.read_only = 1;    
    dest->prof_common_header.use_proxy = src->comm_header.use_proxy;
    dest->prof_common_header.px_port = src->comm_header.px_port;
    dest->prof_common_header.AppType = src->comm_header.app_type;
    dest->prof_common_header.px_service = src->comm_header.px_service;
    kal_mem_cpy(dest->prof_common_header.HomePage, src->comm_header.HomePage, SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1);
    kal_mem_cpy(dest->prof_common_header.px_addr, src->comm_header.px_addr, SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN+1);
    kal_mem_cpy(dest->prof_common_header.px_authid, src->comm_header.px_authid, SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN+1);
    kal_mem_cpy(dest->prof_common_header.px_authpw, src->comm_header.px_authpw, SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN+1);
    dest->prof_common_header.read_only = 1;   
    dest->prof_common_header.Auth_info.AuthType = src->AuthType;
    dest->APN = src->APN;
    
    return SRV_DTCNT_RESULT_SUCCESS;    
}
    
#endif /* __MMI_GPRS_FEATURES__ */

#endif /* __DTCNT_SIM_PROFILES_SUPPORT__ */

#ifdef SYNCML_DM_SUPPORT
int srv_dtcnt_db_store_check_dm_acc(int * out_idx, srv_dtcnt_bearer_enum type, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_prof_common_header_struct *comm_header = data;
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (comm_header && comm_header->AppType & DTCNT_APPTYPE_DM)
    {
        MMI_ASSERT(out_idx);
        for (i = SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i<(SRV_DTCNT_PROF_MAX_ACCOUNT_NUM+SRV_DTCNT_RESERVED_DM_ACC_NUM); i++)
        {
            if(!g_srv_dtcnt_store_ctx.acc_list[i].in_use)
            {
                *out_idx = i;
                return 1;
            }
        }                
        return 0;
    }
    return -1;
}
#endif /* SYNCML_DM_SUPPORT */

cbm_sim_id_enum srv_dtcnt_db_store_cvt_dtcnt_sim_to_cbm_sim(srv_dtcnt_sim_type_enum sim_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_info)
    {
        case SRV_DTCNT_SIM_TYPE_1:
            return CBM_SIM_ID_SIM1;
        case SRV_DTCNT_SIM_TYPE_2:
            return CBM_SIM_ID_SIM2;
        case SRV_DTCNT_SIM_TYPE_3:
            return CBM_SIM_ID_SIM3;
        case SRV_DTCNT_SIM_TYPE_4:
            return CBM_SIM_ID_SIM4;
        default:
            MMI_ASSERT(0);
    }
    return CBM_SIM_ID_SIM1;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_OP01_WIFI__
void srv_dtcnt_db_update_acc_map_to_wifi()
{
	int i = 0;
	MMI_BOOL reg_app_flag = MMI_FALSE;
    cbm_app_info_struct ap_info;
    cbm_account_info_struct acct_info;
	
	for(i=0; i<g_real_acct_map.num_account; i++)
	{
		cbm_decode_data_account_id_ext(g_real_acct_map.account_map[i][0], &acct_info);
		reg_app_flag = abm_get_registered_app_name(acct_info.app_id, &ap_info);
		if(!reg_app_flag ||
		ap_info.app_type & DTCNT_APPTYPE_DM ||
		ap_info.app_type & DTCNT_APPTYPE_MMS)
		{
			continue;
		}
		MMI_TRACE(MMI_CONN_TRC_G6_DTCNT,SRV_DTCNT_ORI_ACCOUNT,g_real_acct_map.account_map[i][0]);	
		g_real_acct_map.account_map[i][1] = CBM_WIFI_ACCT_ID;
	}
}

MMI_BOOL srv_dtcnt_db_get_app_str(U32 acct_id, U16* app_str_id, U16* app_icon_id)
{
    cbm_app_info_struct ap_info;
    cbm_account_info_struct acct_info;
    
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT,SRV_DTCNT_GET_APP_NAME_STR,acct_id);
    memset(&ap_info, 0, sizeof(ap_info));

    if (cbm_decode_data_account_id_ext(acct_id, &acct_info) != CBM_OK)
    {
        MMI_ASSERT(0);
    }

    if(abm_get_registered_app_name(acct_info.app_id, &ap_info) == CBM_ERROR)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT,SRV_DTCNT_GET_APP_NAME_ERR);
        return MMI_FALSE;
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT,SRV_DTCNT_GET_APP_NAME, ap_info.app_str_id, ap_info.app_icon_id);
        *app_str_id = ap_info.app_str_id;
        *app_icon_id = ap_info.app_icon_id;
        return MMI_TRUE;
    }

}
void srv_dtcnt_db_record_real_account(U32 ori_acct_id,U32 real_acct_id)
{
    int j = 0;
    U16 app_str_id = 0;
    U16 app_icon_id = 0;
    U16 tmp_str_id = 0;
    U16 tmp_icon_id = 0;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT,SRV_DTCNT_RECORD_REAL_ACCOUNT,ori_acct_id,real_acct_id);
    srv_dtcnt_db_get_app_str(ori_acct_id, &app_str_id, &app_icon_id);
    for(j=0; j<g_real_acct_map.num_account; j++)
    {
        if( (srv_dtcnt_db_get_app_str(g_real_acct_map.account_map[j][0],&tmp_str_id,&tmp_icon_id)==MMI_FALSE)
            || (tmp_str_id==app_str_id && tmp_icon_id==app_icon_id) )
        {
            g_real_acct_map.account_map[j][0] = ori_acct_id;
            g_real_acct_map.account_map[j][1] = real_acct_id;
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT,SRV_DTCNT_UPDATE_REAL_ACCT);
            break;
        }
    }
    if(j == g_real_acct_map.num_account)
    {
        if(j < ABM_MAX_APP_NUM)
        {
            g_real_acct_map.account_map[j][0] = ori_acct_id;
            g_real_acct_map.account_map[j][1] = real_acct_id;
            g_real_acct_map.num_account++;
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT,SRV_DTCNT_ADD_REAL_ACCT);
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT,SRV_DTCNT_REAL_ACCT_IS_FULL);
        }
    }

}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
void srv_dtcnt_bearer_init_wlan_ap_query_ind_callback(U32 bearer_type, U32 acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_bearer_init_job_list *bearer_init_job_list_p = g_bearer_init_job_list;
    U8 ap_id;
    cbm_sim_id_enum sim_id;
    int i, j;
    U32 best_fit_acc_id;
    srv_dtcnt_change_real_acct_ind_evt_struct change_real_acct_ind_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_BEARER_INIT_WLAN_AP_QUERY_IND_CALLBACK, bearer_type, acct_id);
    
    while (bearer_init_job_list_p)
    {
        g_bearer_init_job_list = bearer_init_job_list_p->next;

        if (bearer_type == SRV_DTCNT_BEARER_WIFI)
        {
            bearer_init_job_list_p->rsp->rel_acct_id = CBM_WIFI_ACCT_ID;
            bearer_init_job_list_p->rsp->bearer_type = CBM_WIFI;
            bearer_init_job_list_p->rsp->result = KAL_TRUE;
            
            srv_dtcnt_db_record_real_account(bearer_init_job_list_p->rsp->ori_acct_id, bearer_init_job_list_p->rsp->rel_acct_id);           
        }
        else if (bearer_type == (SRV_DTCNT_BEARER_CSD|SRV_DTCNT_BEARER_GPRS))
        {
            if(acct_id == CBM_DEFAULT_ACCT_ID)
        {
            /* detect smart account from SIM database */
            if (srv_dtcnt_get_auto_acc_id(bearer_init_job_list_p->rsp->ori_acct_id,
                                          &(bearer_init_job_list_p->rsp->rel_acct_id))==SRV_DTCNT_RESULT_FAILED)
            {
                bearer_init_job_list_p->rsp->result = KAL_FALSE;
            }
            else
            {
                if (cbm_decode_data_account_id(bearer_init_job_list_p->rsp->rel_acct_id,
                                               NULL,
                                               &ap_id,
                                               NULL,
                                               &best_fit_acc_id))
                {
                    for (i = 0; i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
                    {
                        if (g_srv_dtcnt_store_ctx.acc_list[i].in_use &&
                            g_srv_dtcnt_store_ctx.acc_list[i].acc_id == best_fit_acc_id)
                        {
                            if (g_srv_dtcnt_store_ctx.acc_list[i].sim_info == SRV_DTCNT_SIM_TYPE_1)
                            {
                                sim_id = CBM_SIM_ID_SIM1;
                            }
                            else
                            {
                                sim_id = CBM_SIM_ID_SIM2;
                            }
                            
                            bearer_init_job_list_p->rsp->rel_acct_id = cbm_encode_data_account_id(best_fit_acc_id, sim_id, ap_id, KAL_FALSE);
                            if (g_srv_dtcnt_store_ctx.acc_list[i].bearer_type == SRV_DTCNT_BEARER_GPRS)
                            {
                                bearer_init_job_list_p->rsp->bearer_type = CBM_PS;
                            }
                            else
                            {
                                bearer_init_job_list_p->rsp->bearer_type = CBM_CSD;
                            }
                            bearer_init_job_list_p->rsp->result = KAL_TRUE;
                            
                            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT,
                                      SRV_DTCNT_POST_CHANGE_REAL_ACCT_IND,
                                      bearer_init_job_list_p->rsp->ori_acct_id,
                                      bearer_init_job_list_p->rsp->rel_acct_id);

                                srv_dtcnt_db_record_real_account(bearer_init_job_list_p->rsp->ori_acct_id, bearer_init_job_list_p->rsp->rel_acct_id); 
                                
                            MMI_FRM_INIT_EVENT(&change_real_acct_ind_evt, EVT_ID_SRV_DTCNT_CHANGE_REAL_ACCT_IND);    
                            change_real_acct_ind_evt.ori_acct_id = bearer_init_job_list_p->rsp->ori_acct_id;
                            change_real_acct_ind_evt.rel_acct_id = bearer_init_job_list_p->rsp->rel_acct_id;
                            MMI_FRM_CB_EMIT_EVENT(&change_real_acct_ind_evt);
                            break;
                        }
                    }
                    if (i == SRV_DTCNT_PROF_MAX_ACCOUNT_NUM)
                    {
                        /* can't find account for applications, send failed response */
                        bearer_init_job_list_p->rsp->result = KAL_FALSE;
                    }
                }
                else
                {
                    /* can't find account for applications, send failed response */
                    bearer_init_job_list_p->rsp->result = KAL_FALSE;
                }
            }

                            }
            else
            {
                if (cbm_decode_data_account_id(bearer_init_job_list_p->rsp->ori_acct_id,
                                               NULL,
                                               &ap_id,
                                               NULL,
                                               &best_fit_acc_id))
                {
                    for (i = 0; i < SRV_DTCNT_PROF_MAX_ACCOUNT_NUM; i++)
                    {
                        if (g_srv_dtcnt_store_ctx.acc_list[i].in_use &&
                            g_srv_dtcnt_store_ctx.acc_list[i].acc_id == acct_id)
                            {
                            if (g_srv_dtcnt_store_ctx.acc_list[i].sim_info == SRV_DTCNT_SIM_TYPE_1)
                                {
                                sim_id = CBM_SIM_ID_SIM1;
                                }
                                else
                                {
                                sim_id = CBM_SIM_ID_SIM2;
                            }
                            
                            bearer_init_job_list_p->rsp->rel_acct_id = cbm_encode_data_account_id(acct_id, sim_id, ap_id, KAL_FALSE);
                            bearer_init_job_list_p->rsp->bearer_type = CBM_PS;
                            bearer_init_job_list_p->rsp->result = KAL_TRUE;
                            
                            MMI_TRACE(MMI_CONN_TRC_G6_DTCNT,
                                      SRV_DTCNT_POST_CHANGE_REAL_ACCT_IND,
                                      bearer_init_job_list_p->rsp->ori_acct_id,
                                      bearer_init_job_list_p->rsp->rel_acct_id);
                            
                            srv_dtcnt_db_record_real_account(bearer_init_job_list_p->rsp->ori_acct_id, bearer_init_job_list_p->rsp->rel_acct_id); 
                            
                            MMI_FRM_INIT_EVENT(&change_real_acct_ind_evt, EVT_ID_SRV_DTCNT_CHANGE_REAL_ACCT_IND);    
                            change_real_acct_ind_evt.ori_acct_id = bearer_init_job_list_p->rsp->ori_acct_id;
                            change_real_acct_ind_evt.rel_acct_id = bearer_init_job_list_p->rsp->rel_acct_id;
                            MMI_FRM_CB_EMIT_EVENT(&change_real_acct_ind_evt);
                            break;

                        }
                    }

                }
                else
                {
                    /* can't find account for applications, send failed response */
                    bearer_init_job_list_p->rsp->result = KAL_FALSE;
                }

            }

        }
        else if (bearer_type == SRV_DTCNT_BEARER_UNKNOWN)
        {
            bearer_init_job_list_p->rsp->result = KAL_FALSE;
        }
        else
        {
            MMI_ASSERT(0);
        }
        srv_dtcnt_db_store_send_msg(MSG_ID_MMI_ABM_BEARER_INIT_RSP, (void *)bearer_init_job_list_p->rsp, MOD_ABM);
        OslMfree(bearer_init_job_list_p);

        bearer_init_job_list_p = g_bearer_init_job_list;
    }    
}
#endif /* __MMI_OP01_WIFI__ */

#define SRV_DB_FS_APIs

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_db_file_mkdir
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  
 *****************************************************************************/
srv_dtcnt_result_enum srv_dtcnt_db_file_mkdir(const WCHAR *path)
{
    int fp;

    fp = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    if (fp < 0)
    {
        if (FS_CreateDir(path) < 0)
            return SRV_DTCNT_RESULT_FS_ERROR;
    }
    else
        FS_Close(fp);

    return SRV_DTCNT_RESULT_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_db_fileio_path_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_dtcnt_db_file_path_exist(const WCHAR *path)
{
    int handle;

    /* check path exists */
    handle = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    if (handle < 0)
        return MMI_FALSE;

    FS_Close(handle);
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_db_fileio_save_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  
 *****************************************************************************/
srv_dtcnt_result_enum srv_dtcnt_db_fileio_save_data(const WCHAR *filename, const void *data, U32 data_size)
{
    int fp;
    U32 wtsize = 0;
    int create_mode;

    if (srv_dtcnt_db_fileio_file_exist(filename))
        create_mode = FS_CREATE_ALWAYS;
    else
        create_mode = FS_CREATE;


    fp = FS_Open (filename, create_mode | FS_READ_WRITE);
    if (fp < 0)
        return SRV_DTCNT_RESULT_FS_ERROR;

    if (FS_Seek(fp, data_size, FS_FILE_BEGIN) < 0)
    {
        FS_Close(fp);
        FS_Delete(filename);
        return SRV_DTCNT_RESULT_FS_ERROR;
    }

    FS_Seek(fp, 0, FS_FILE_BEGIN);
    if (FS_Write(fp, (void*)data, data_size, (UINT*)&wtsize) < 0 || wtsize != data_size)
    {
        FS_Close(fp);
        FS_Delete(filename);
        return SRV_DTCNT_RESULT_FS_ERROR;
    }

    FS_Close(fp);
    return SRV_DTCNT_RESULT_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_db_fileio_file_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_dtcnt_db_fileio_file_exist(const WCHAR *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fp = FS_Open((const WCHAR*)filename, FS_READ_ONLY);
    if (fp >= FS_NO_ERROR)
    {
        FS_Close(fp);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_db_fileio_read_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *
 *****************************************************************************/
srv_dtcnt_result_enum srv_dtcnt_db_fileio_read_data(const WCHAR *filename, void *buffer, U32 bufsize, U32 *out_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fp;
    U32 filesize = 0;
    U32 read;
    srv_dtcnt_result_enum err = SRV_DTCNT_RESULT_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fp = FS_Open(filename, FS_READ_ONLY);
    if (fp < 0)
        return SRV_DTCNT_RESULT_FS_ERROR;

    if (FS_GetFileSize(fp, (UINT*)&filesize) < 0)
        err = SRV_DTCNT_RESULT_FS_ERROR;

    if (!err && !filesize)
        err = SRV_DTCNT_RESULT_FS_ERROR;

    if (out_size)
        *out_size = filesize;

    bufsize = (bufsize>filesize?filesize:bufsize);
    if (!err && FS_Read(fp, (void*)buffer, (UINT)bufsize, &read)<0)
        err = SRV_DTCNT_RESULT_FS_ERROR;

    if (!err)
    {
        MMI_ASSERT(bufsize == read);
    }
    FS_Close(fp);
    return err;
}

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_db_fileio_write_store_info_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *
 *****************************************************************************/
MMI_BOOL srv_dtcnt_db_fileio_write_store_info_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UINT written;
    int fs_err;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Seek(g_srv_dtcnt_context.info_file_fp, 0, FS_FILE_BEGIN);    
    fs_err = FS_Write(g_srv_dtcnt_context.info_file_fp, &(g_srv_dtcnt_store_ctx), sizeof(srv_dtcnt_store_info_context), &written);

    if (fs_err < FS_NO_ERROR || written != sizeof(srv_dtcnt_store_info_context))
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_DB_FILEIO_WRITE_INFO_FILE_ERROR, fs_err);
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}

U8 srv_dtcnt_get_real_acct(U32 acc_id, srv_dtcnt_account_enum acc_idx)
{
    U32 real_acct_id = acc_id;
    cbm_account_info_struct acct_info;
    U8 decode_acct_id = 0;
    
    srv_cbm_get_real_account(acc_id, &real_acct_id);
    
    cbm_decode_data_account_id_ext(real_acct_id, &acct_info);

    if(acct_info.account[acc_idx-1].account_id != CBM_DEFAULT_ACCT_ID)
    {
        decode_acct_id = acct_info.account[acc_idx-1].account_id;
    }
    else 
    {
        decode_acct_id =  srv_dtcnt_extract_specified_acc_id(real_acct_id, acc_idx);
    }

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, SRV_DTCNT_GET_REAL_ACCT_FROM_CBM, acct_info.account[acc_idx-1].account_id , decode_acct_id);
    return decode_acct_id;
        
}

MMI_BOOL srv_dtcnt_db_store_check_ignore_num(void)
{
    switch(g_srv_dtcnt_context.store_status)
    {
        case SRV_DTCNT_STORE_STATUS_NONE:
        case SRV_DTCNT_STORE_STATUS_CLOSED:
        case SRV_DTCNT_STORE_STATUS_CORRUPT:
        case SRV_DTCNT_STORE_STATUS_FS_ERROR:
        case SRV_DTCNT_STORE_STATUS_PROV_PROC:
            return MMI_FALSE;
    }
    return MMI_TRUE;
}


#endif /* __TCPIP__ */
