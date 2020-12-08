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
 * BTMMIBip.c
 *
 * Project:
 * --------
 *   BT BIP MMI
 *
 * Description:
 * ------------
 *   This file is for MMI BIP service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_BT_MTK_SUPPORT__
#if defined(__MMI_BIP_SUPPORT__)

/***************************************************************************** 
 * Include 
 *****************************************************************************/

#ifndef __MTK_TARGET__
#include "Windows.h"
#endif 
#include "BtcmSrvGprot.h"
#include "BTMMIScr.h"
#include "BTMMIScrGprots.h"
#include "BTMMIObexGprots.h"

#include "Bluetooth_struct.h"
#include "Bluetooth_bm_struct.h"

#include "BTMMIBipGprot.h"
#include "BipSrvGprot.h"
#include "BipSrv.h"




/* Applib MIME Header Files */
#include "app_mine.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "string.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "stack_config.h"
#include "FileMgrSrvGProt.h"
#include "Unicodexdcl.h"
#include "stack_ltlcom.h"
#include "stack_common.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "gdi_include.h"
#include "gdi_const.h"
#include "gdi_features.h"
#include "stdio.h"
#include "gdi_datatype.h"
#include "lcd_sw_rnd.h"
#include "app_buff_alloc.h"

/***************************************************************************** 
 * Define 
 *****************************************************************************/


/* macro defination */
#define BIP_MEMSET(local_para_ptr)    do {                              \
    memset((kal_uint8*)(local_para_ptr) + sizeof(local_para_struct), 0, \
           (local_para_ptr)->msg_len - sizeof(local_para_struct));      \
} while(0)

#define MMI_BIP_FS_DEVICE_BUSY(ret) (ret == FS_DEVICE_BUSY|| ret == FS_LOCK_MUTEX_FAIL)

#define MMI_BIP_MIN(a,b) ((a)<(b)?(a):(b))


/***************************************************************************** 
 * global variable
 *****************************************************************************/
srv_bip_context_struct srv_bip_context;
srv_bip_context_struct *srv_bip_p = &srv_bip_context;
//extern U16 mmi_bip_notify_str[];


/***************************************************************************** 
 * func prototype
 *****************************************************************************/

static void srv_bipi_cntx_init(void);
static void srv_bipi_deinit(void);
static void srv_bip_disconnect_ind_hdlr(void *msg);
static void srv_bip_continue_ind_hdlr(void *msg);
static void srv_bip_send_continue_rsp(U32 cm_conn_id, U8 rsp_code);
static mmi_ret srv_bip_post_proc(mmi_event_struct* para);
static void srv_bipi_send_get_capabilities_req(U32 cm_conn_id);
static void srv_bipi_send_push_req(void);
static void srv_bipi_send_disconnect_req(srv_bip_disconnect_type_enum type);
static void srv_bipi_send_abort_req(U32 cm_conn_id);
static void srv_bip_send_disconnect_req(U32 cm_conn_id, srv_bip_disconnect_type_enum type, bt_bip_session_role_enum role);
static void srv_bip_request_timeout_hdlr(void);
static MMI_BOOL srv_bipi_pairing_permit(srv_bt_cm_bt_addr bt_addr);
static S32 srv_bipi_notify_app(S32 event_id, void *para);
static void srv_bipi_connect_cnf_hdlr(void *msg);
static void srv_bipi_abort_cnf_hdlr(void *msg);
static void srv_bipi_push_abort_cnf_hdlr(bt_bip_abort_cnf_struct *rsp);
static void srv_bipi_push_get_capabilities_cnf_hdlr(void *msg);
static void srv_bipi_push_img_cnf_hdlr(void *msg);
static void srv_bipi_push_thm_cnf_hdlr(void *msg);
static void srv_bipi_push_continue_ind_hdlr(bt_bip_continue_ind_struct *ind);
static void srv_bipi_disconnect_ind_hdlr(void);
static void srv_bipi_connection_terminated(void);
static void srv_bipi_disconnect_from_cm(U32 conn_id);

static void srv_bipr_cntx_init(void);
static void srv_bipr_activate_cnf_hdlr(void *msg);
static void srv_bipr_deactivate_cnf_hdlr(void *msg);
static U8 srv_bipr_sdp_register_cnf_hdlr(void *msg);
static U8 srv_bipr_sdp_deregister_cnf_hdlr(void *msg);
static void srv_bipr_authorize_ind_hdlr(void *msg);
static void srv_bipr_connect_ind_hdlr(void *msg);

static void srv_bipr_get_capabilities_ind_hdlr(void *msg);
static void srv_bipr_push_img_ind_hdlr(void *msg);
static void srv_bipr_push_thm_ind_hdlr(void *msg);
static void srv_bipr_complete_ind_hdlr(void *msg);
static void srv_bipr_aborted_ind_hdlr(void *msg);
static void srv_bipr_disconnect_ind_hdlr(void);
static void srv_bipr_send_authorize_rsp(U8 rsp_code);
static void srv_bipr_send_connect_rsp(U8 rsp_code);
static void srv_bipr_send_get_capabilities_rsp(void);
static void srv_bipr_send_push_rsp(U8 cnf_code, U16 *recv_path);
static void srv_bipr_send_push_thm_rsp(U8 cnf_code, U16 *thm_path);
//static void srv_bipr_pre_send_push_rsp(U16 *recv_path);
static void srv_bipr_connection_terminated(void);
static void srv_bipr_notify_app(S32 event_id, void *para);

static srv_bip_handle_struct *srv_bip_get_inst_from_srv_hd(S32 srv_hd);
static U16 srv_bip_ntohs(U16 s);
static bt_bip_img_format_enum srv_bip_get_image_type_from_postfix(U16 *pathfileName);
static bt_bip_img_format_enum srv_bip_get_image_type(U16 *pathfileName);
static void srv_bip_get_file_name(U16 *pathFileName, U16 *path, U16 *name, U16 name_size);
static U8 srv_bip_get_dimension_for_thumbnail(U16* image_name, S32 *width, S32 *height);
static MMI_BOOL srv_bip_encode_file_to_thumbnail(
            U16 *src_file_name,
            U16 *dest_file_name,
            U8 *buf_ptr,
            S32 buf_size);
static MMI_BOOL srv_bip_generate_thumbnail(U16 *img_path, U16 *thm_path, U16 thm_path_len, srv_bip_role_enum role);
static void srv_bip_construct_send_thm_path(U16 *img_path_file, U16 *dst_path, U16 path_size);
//static mmi_bt_bip_error_enum srv_bip_compose_recv_folder(srv_bip_role_enum role, MMI_BOOL popup_info);
//static mmi_bt_bip_error_enum srv_bip_create_folder_if_not_exist(U16 *folder_name, srv_bip_role_enum role, MMI_BOOL popup_info);

static void srv_bip_gen_thm_filename(U16 *img_name, S8 *img_handle);

//static S32 srv_bip_dup_filename_if_exist(U16 *path, U16 *src_name);

static void srv_bip_send_msg(U32 msg_id, void *p_local_para);

//static U8 srv_bipi_convert_bip_err_to_btsend_err(U8 bip_err);
//static mmi_bt_bip_error_enum srv_bip_convert_fs_err_to_bip_err(int fs_err);
//static U8 srv_bip_convert_bip_err_to_cnf_code(mmi_bt_bip_error_enum bip_err);
static mmi_bt_bip_error_enum srv_bip_convert_cnf_code_to_bip_err(U8 cnf_code);

/* event handle func */
static void srv_bip_event_hdlr(void);

/*****************************************************************************
*
* BIP external function
*
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_bip_open
 * DESCRIPTION
 *  This function is to return a handle to app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_bip_open(U8 role)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (role == SRV_BIP_INITIATOR_ROLE)
    {
        if (srv_bipi_is_idle())
        {
            for (i = 0; i < SRV_BIP_MAX_CLIENT_NUM; i++)
            {
                if (srv_bip_p->initiator_hd[i].srv_hd == 0)
                {
                    srv_bip_p->initiator_hd[i].srv_hd = i + 1;
                    srv_bip_p->initiator_hd[i].u.bipi_cntx = &srv_bip_p->bipi_cntx;
                    return srv_bip_p->initiator_hd[i].srv_hd;
                }
            }
        }
        
    }
    else
    {
        for (i = 0; i < SRV_BIP_MAX_SERVER_NUM; i++)
        {
            if (srv_bip_p->responder_hd[i].srv_hd == 0)
            {
                srv_bip_p->responder_hd[i].srv_hd = i + SRV_BIP_REPONDER_HANDLE_BEGIN;
                srv_bip_p->responder_hd[i].u.bipr_cntx = &srv_bip_p->bipr_cntx;
                return srv_bip_p->responder_hd[i].srv_hd;
            }
        }
    }

    return SRV_BIP_RESULT_INVALID_HANDLE;
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_open
 * DESCRIPTION
 *  This function is to return a handle to app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 S32 srv_bip_close(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bip_handle_struct *inst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst = srv_bip_get_inst_from_srv_hd(srv_hd);

    if (inst == NULL)
        return SRV_BIP_RESULT_INVALID_HANDLE;

    if (inst->srv_hd > 0 && inst->srv_hd < SRV_BIP_REPONDER_HANDLE_BEGIN)
    {
        if (!srv_bipi_is_idle())
        {
            srv_bipi_send_end(srv_hd);
        }
    }

    inst->srv_hd = 0;
    inst = NULL;

    return SRV_BIP_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_set_notify
 * DESCRIPTION
 *  This function is to set app callback and event_mask
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_bip_set_notify(S32 srv_hd, U32 event_mask, bt_notify notifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bip_handle_struct *inst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst = srv_bip_get_inst_from_srv_hd(srv_hd);

    if (inst == NULL)
        return SRV_BIP_RESULT_INVALID_HANDLE;

    if (notifier == NULL)
        return SRV_BIP_RESULT_INVALID_PARAM;

    inst->event_mask = event_mask;
    inst->notifier = notifier;

    return SRV_BIP_RESULT_OK;
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_event_hdlr
 * DESCRIPTION
 *  This function is to initialize BIP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bip_event_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* general msg */
    SetProtocolEventHandler(srv_bip_continue_ind_hdlr, MSG_ID_BT_BIP_CONTINUE_IND);
    SetProtocolEventHandler(srv_bip_disconnect_ind_hdlr, MSG_ID_BT_BIP_DISCONNECT_IND);
    
    /* initiator msg */
    SetProtocolEventHandler(srv_bipi_connect_cnf_hdlr, MSG_ID_BT_BIP_CONNECT_CNF);
    SetProtocolEventHandler(srv_bipi_push_get_capabilities_cnf_hdlr, MSG_ID_BT_BIP_GET_CAPABILITIES_CNF);
    SetProtocolEventHandler(srv_bipi_push_img_cnf_hdlr, MSG_ID_BT_BIP_PUT_IMG_CNF);
    SetProtocolEventHandler(srv_bipi_push_thm_cnf_hdlr, MSG_ID_BT_BIP_PUT_LINKED_THUMBNAIL_CNF);
    
    SetProtocolEventHandler(srv_bipi_abort_cnf_hdlr, MSG_ID_BT_BIP_ABORT_CNF);
    /* responder msg */
    SetProtocolEventHandler(srv_bipr_activate_cnf_hdlr, MSG_ID_BT_BIP_ACTIVATE_CNF);
    SetProtocolEventHandler(srv_bipr_deactivate_cnf_hdlr, MSG_ID_BT_BIP_DEACTIVATE_CNF);
    SetProtocolEventHandler(srv_bipr_authorize_ind_hdlr, MSG_ID_BT_BIP_AUTHORIZE_IND);
    SetProtocolEventHandler(srv_bipr_connect_ind_hdlr, MSG_ID_BT_BIP_CONNECT_IND);
    SetProtocolEventHandler(srv_bipr_get_capabilities_ind_hdlr, MSG_ID_BT_BIP_GET_CAPABILITIES_IND);
    SetProtocolEventHandler(srv_bipr_push_img_ind_hdlr, MSG_ID_BT_BIP_PUT_IMG_IND);
    SetProtocolEventHandler(srv_bipr_push_thm_ind_hdlr, MSG_ID_BT_BIP_PUT_LINKED_THUMBNAIL_IND);
    SetProtocolEventHandler(srv_bipr_aborted_ind_hdlr, MSG_ID_BT_BIP_ABORT_IND);
    SetProtocolEventHandler(srv_bipr_complete_ind_hdlr, MSG_ID_BT_BIP_COMPLETE_IND);

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_SDPDB_REGISTER_CNF, (PsIntFuncPtr)srv_bipr_sdp_register_cnf_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_SDPDB_DEREGISTER_CNF, (PsIntFuncPtr)srv_bipr_sdp_deregister_cnf_hdlr, MMI_TRUE);
    
#ifdef __BIP_PULL_SUPPORT__
    SetProtocolEventHandler(mmi_bipi_get_imglist_cnf_hdlr, MSG_ID_BT_BIP_GET_IMG_LIST_CNF);
    SetProtocolEventHandler(mmi_bipi_get_imgprop_cnf_hdlr, MSG_ID_BT_BIP_GET_IMG_PROP_CNF);
    SetProtocolEventHandler(mmi_bipi_get_img_cnf_hdlr, MSG_ID_BT_BIP_GET_IMG_CNF);
    SetProtocolEventHandler(mmi_bipi_get_thm_cnf_hdlr, MSG_ID_BT_BIP_GET_LINKED_THUMBNAIL_CNF);

    SetProtocolEventHandler(mmi_bipr_get_imglist_ind_hdlr, MSG_ID_BT_BIP_GET_IMG_LIST_IND);
    SetProtocolEventHandler(mmi_bipr_get_imgprop_ind_hdlr, MSG_ID_BT_BIP_GET_IMG_PROP_IND);
    SetProtocolEventHandler(mmi_bipr_get_img_ind_hdlr, MSG_ID_BT_BIP_GET_IMG_IND);
    SetProtocolEventHandler(mmi_bipr_get_thm_ind_hdlr, MSG_ID_BT_BIP_GET_LINKED_THUMBNAIL_IND);
    
#endif
    
    //SetProtocolEventHandler(srv_bipi_get_imglist_parsing_ind_hdlr, MSG_ID_BT_BIP_GET_IMG_LIST_PARSING_IND);

}

/*****************************************************************************
 * FUNCTION
 *  srv_bip_init
 * DESCRIPTION
 *  This function is to initialize BIP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bip_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG(SRV_BIP_INIT);

    /* bip context init */
    srv_bipi_cntx_init();
    srv_bipr_cntx_init();

    //srv_bip_compose_recv_folder(SRV_BIP_RESPONDER_ROLE, MMI_FALSE);

    srv_bip_p->cur_req_id = MMI_BIP_INVALID_REQ_ID;
    srv_bip_p->flag = 0;

    /* set msg handler */
    srv_bip_event_hdlr();

}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_deinit
 * DESCRIPTION
 *  This function is to clear screens for bip in de-init bt procedure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bip_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG(SRV_BIP_DEINIT);

    srv_bipi_deinit();

    srv_bipr_connection_terminated();
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipi__deinit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipi_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIPI_DEINIT, srv_bip_p->bipi_cntx.state);
    if (srv_bip_p->bipi_cntx.state > SRV_BIPI_STATE_IDLE)
    {
        srv_bipi_connection_terminated();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipi_send_begin
 * DESCRIPTION
 *  This function is to connect server for bip service
 * PARAMETERS
 *  bd_addr         [IN]        
 *  bip_service     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_bipi_send_begin(S32 srv_hd, srv_bt_cm_bt_addr *bd_addr, bt_bip_service_enum bip_service)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_connect_req_struct *req;
    srv_bip_handle_struct *inst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIP_SEND_BEGIN, srv_hd);

    if (srv_bip_p->bipi_cntx.state > SRV_BIPI_STATE_IDLE)
    {
        return SRV_BIP_RESULT_STATE_BUSY;
    }

    inst = srv_bip_get_inst_from_srv_hd(srv_hd);

    if (inst == NULL)
        return SRV_BIP_RESULT_INVALID_HANDLE;
    

    MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_CONNECTING);
    inst->u.bipi_cntx->bt_device.lap = bd_addr->lap;
    inst->u.bipi_cntx->bt_device.uap = bd_addr->uap;
    inst->u.bipi_cntx->bt_device.nap = bd_addr->nap;

    inst->u.bipi_cntx->req_id = srv_bt_cm_start_conn(MMI_FALSE, SRV_BT_CM_OBEX_IMAGING_UUID, bd_addr, NULL);
    if (inst->u.bipi_cntx->req_id < 0)
        return SRV_BIP_RESULT_STATE_BUSY;

    /* connect server */
    req = (bt_bip_connect_req_struct*) OslConstructDataPtr(sizeof(bt_bip_connect_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->bd_addr.lap = bd_addr->lap;
    req->bd_addr.uap = bd_addr->uap;
    req->bd_addr.nap = bd_addr->nap;

    req->req_id = inst->u.bipi_cntx->req_id;
    req->bip_service = bip_service;

    /* send connect req to server */
    srv_bip_send_msg(MSG_ID_BT_BIP_CONNECT_REQ, req);

    return SRV_BIP_RESULT_OK;
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipi_send_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_bipi_send_end(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bip_handle_struct *inst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIP_SEND_END, srv_hd);

    inst = srv_bip_get_inst_from_srv_hd(srv_hd);

    if (inst == NULL)
        return SRV_BIP_RESULT_INVALID_HANDLE;

    if (inst->u.bipi_cntx->state == SRV_BIPI_STATE_SENDING_IMG||
        inst->u.bipi_cntx->state == SRV_BIPI_STATE_SENDING_THM||
        inst->u.bipi_cntx->state == SRV_BIPI_STATE_GETTING_CAPABILITIES ||
        inst->u.bipi_cntx->state == SRV_BIPI_STATE_CONNECTING)
    {
        srv_bipi_send_disconnect_req(SRV_BIP_TP_DISCONNECT);

    }
    else if (inst->u.bipi_cntx->state == SRV_BIPI_STATE_CONNECTED)
    {
        srv_bt_cm_reg_pairing_permission(SRV_BT_CM_OBEX_IMAGING_UUID, (void*)srv_bipi_pairing_permit);
     
        StopTimer(BT_BIP_REQ_TIMER); /* stop the connect timer */
        srv_bipi_send_disconnect_req(SRV_BIP_OBEX_DISCONNECT);
    }
    else if (inst->u.bipi_cntx->state == SRV_BIPI_STATE_DISCONNECTING) 
    {
      /* already disconnecting, only entry aborting screen */
    }
    else
    {
        
    }

    return SRV_BIP_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bip_send_begin
 * DESCRIPTION
 *  This function is to connect_server
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_bipi_send_img(S32 srv_hd, U16 *path, U16 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bip_handle_struct *inst;
    srv_bip_snd_notify_struct snd_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIP_SEND_IMG, srv_hd);
    
    inst = srv_bip_get_inst_from_srv_hd(srv_hd);

    if (inst == NULL)
    {
        return SRV_BIP_RESULT_INVALID_HANDLE;
    }

    if (path == NULL)
    {
        return SRV_BIP_RESULT_INVALID_PARAM;
    }
    
    SRV_BIP_LOG_PATH(path);
    mmi_wcscpy(inst->u.bipi_cntx->img_path_snd, path);

    mmi_wcscpy(inst->u.bipi_cntx->img_name, name);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    if (inst->u.bipi_cntx->state == SRV_BIPI_STATE_CONNECTED)
    {
        SRV_BIP_LOG(SRV_BIP_SEND_IMG_CASE1);
        srv_bipi_send_get_capabilities_req(srv_bip_p->bipi_cntx.cm_conn_id);
    }
    else
    {
        inst->u.bipi_cntx->img_total_size = 0;
        inst->u.bipi_cntx->sent_size = 0;

        snd_notify.type = SRV_BIP_SND_PERSENT;
        snd_notify.u.info.sent_size= 0;
        snd_notify.u.info.total_obj_size = 0;

        srv_bipi_notify_app(SRV_BIP_EVENT_SND_NOTIFY, (void *) &snd_notify);
        /* send image */
        srv_bipi_send_push_req();
    
    }
    
    return SRV_BIP_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_send_begin
 * DESCRIPTION
 *  This function is to connect_server
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_bip_send_cancel(U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG(SRV_BIP_SEND_CANCEL);

    srv_bip_send_msg(MSG_ID_BT_BIP_ENTER_USB_MODE_REQ, NULL);

    return SRV_BIP_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_activate
 * DESCRIPTION
 *  This function is to activate the BIP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bipr_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 req_id;
    //srv_bip_handle_struct *inst;
    srv_bip_event_struct event;
    bt_bip_activate_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //SRV_BIP_LOG1(SRV_BIPS_ACTIVATE, srv_hd);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    
    /* find all IDLE state connection and register them all */
    switch (srv_bip_p->bipr_cntx.state)
    {
            /* unactivated connection */
        case SRV_BIPR_STATE_IDLE:

            req_id = BIP_CURR_REQ_ID;
            srv_bip_p->bipr_cntx.req_id = req_id;
            /* switch state to registering */
            MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_REGISTERING);

            req = (bt_bip_activate_req_struct*) OslConstructDataPtr(sizeof(bt_bip_activate_req_struct));
            BIP_MEMSET(req);    /* memory init */
            req->req_id = req_id;
            req->bip_service_set = BT_BIP_IMAGE_PUSH | BT_BIP_IMAGE_PULL;

            /* Send activate_REQ primitive */
            srv_bip_send_msg(MSG_ID_BT_BIP_ACTIVATE_REQ, req);

            /* set flag to notify the unactivaed connection is found */
            
            break;

        case SRV_BIPR_STATE_REGISTERING:
            break;
            
            /* other states */
        default:
            /* MMI_BIPS_LOG_STATE_ERR(i); */
            MMI_FRM_INIT_EVENT(&event, EVENT_ID_BIP_SDP_REG);
            srv_bt_cm_activate_cnf_hdler((U32) SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID);
            event.event_id = SRV_BIP_EVENT_START;
            event.role = SRV_BIP_RESPONDER_ROLE;
            event.data = (void *)NULL;
            
            mmi_frm_post_event((mmi_event_struct *)&event, srv_bip_post_proc, NULL);
            break;
    }
    
    //return SRV_BIP_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_deactivate
 * DESCRIPTION
 *  This function is to deactivate the BIP application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bipr_deactivate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bip_handle_struct *inst;
    bt_sdpdb_deregister_req_struct *req;
    srv_bip_event_struct event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //SRV_BIP_LOG1(SRV_BIPS_DEACTIVATE, srv_hd);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    /* check all connections state */
    switch (srv_bip_p->bipr_cntx.state)
    {
        case SRV_BIPR_STATE_REGISTERING:    /* activating -> deactivating */
        case SRV_BIPR_STATE_DEACTIVATING:   /* deactivating -> deactivating */
            break;
            
        case SRV_BIPR_STATE_IDLE:           /* unactivated */
            MMI_FRM_INIT_EVENT(&event, EVENT_ID_BIP_SDP_DEREG);
            srv_bt_cm_deactivate_cnf_hdler((U32) SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID);
            event.event_id = SRV_BIP_EVENT_STOP;
            event.role = SRV_BIP_RESPONDER_ROLE;
            event.data = (void *)NULL;
            
            mmi_frm_post_event((mmi_event_struct *)&event, srv_bip_post_proc, NULL);
            break;
            
        default:                            /* other activated states */
            /* send SDP deregister primitive */

            req = (bt_sdpdb_deregister_req_struct*) OslConstructDataPtr(sizeof(bt_sdpdb_deregister_req_struct));
            BIP_MEMSET(req);    /* memory init */
            req->uuid = SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID;

            /* send req to bt */
            {
                ilm_struct *ilm_send;

                ilm_send = allocate_ilm(MOD_MMI);
                ilm_send->src_mod_id = MOD_MMI;
                ilm_send->dest_mod_id = MOD_BT;
                ilm_send->sap_id = BT_APP_SAP;
                ilm_send->msg_id = (U16) MSG_ID_BT_SDPDB_DEREGISTER_REQ;
                ilm_send->local_para_ptr = (local_para_struct*) req;
                ilm_send->peer_buff_ptr = (peer_buff_struct*) NULL;

                msg_send_ext_queue(ilm_send);
            }

            break;
    }

    //return SRV_BIP_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_accept
 * DESCRIPTION
 *  This function is to accept rfcomm channel.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_bipr_accept(S32 srv_hd, U32 conn_id, U16 *recv_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bip_handle_struct *inst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG2(SRV_BIPR_ACCEPT_CONN, srv_hd, conn_id);

    inst = srv_bip_get_inst_from_srv_hd(srv_hd);

    if (inst == NULL)
        return SRV_BIP_RESULT_INVALID_HANDLE;

    SRV_BIP_LOG_PATH(recv_path);
    
    if (inst->u.bipr_cntx->state == SRV_BIPR_STATE_AUTHORIZING)
    {
        /* Send success connect response to OBEX task */
        srv_bipr_send_authorize_rsp(BT_BIP_CNF_SUCCESS);
    }
    
    if (inst->u.bipr_cntx->state == SRV_BIPR_STATE_RECEIVING_IMG)
    {
        if (recv_path != NULL)
        {
            //srv_bipr_pre_send_push_rsp(recv_path);
            srv_bipr_send_push_rsp(BT_BIP_CNF_SUCCESS, recv_path);
        }
        else
        {
            srv_bipr_send_push_rsp(GOEP_NOT_ACCEPTABLE, NULL);
            MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_CONNECTED);
        }
    }
    
    if (inst->u.bipr_cntx->state == SRV_BIPR_STATE_RECEIVING_THM)
    {
        if (recv_path != NULL)
        {
            srv_bipr_send_push_thm_rsp(BT_BIP_CNF_SUCCESS, recv_path);
        }
        else
        {
            srv_bipr_send_push_thm_rsp(GOEP_INTERNAL_SERVER_ERR, NULL);
            MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_CONNECTED);
        }
    }

    return SRV_BIP_RESULT_OK;
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_reject
 * DESCRIPTION
 *  This function is to reject rfcomm channel.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_bipr_reject(S32 srv_hd, U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bip_handle_struct *inst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG2(SRV_BIPR_REJECT_CONN,srv_hd, conn_id);

    inst = srv_bip_get_inst_from_srv_hd(srv_hd);

    if (inst == NULL)
        return SRV_BIP_RESULT_INVALID_HANDLE;

    if (inst->u.bipr_cntx->state == SRV_BIPR_STATE_AUTHORIZING)
    {
        /* Send failed connect response to OBEX task */
        srv_bipr_send_authorize_rsp(GOEP_NOT_ACCEPTABLE/*BT_BIP_CNF_FAILED*/);
    }

    if (inst->u.bipr_cntx->state == SRV_BIPR_STATE_RECEIVING_IMG)
    {
        srv_bipr_send_push_rsp(GOEP_NOT_ACCEPTABLE, NULL);
        MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_CONNECTED);
    }

    if (inst->u.bipr_cntx->state == SRV_BIPR_STATE_RECEIVING_THM)
    {
        srv_bipr_send_push_thm_rsp(GOEP_NOT_ACCEPTABLE, NULL);
        MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_CONNECTED);
    }

    return SRV_BIP_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_disconnect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bip_disconnect_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_disconnect_ind_struct *ind = (bt_bip_disconnect_ind_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(BT_BIP_REQ_TIMER);

    if (ind->session_role == BT_BIP_RESPONDER_ROLE)
    {
        srv_bipr_disconnect_ind_hdlr();
    }
    else    
    {
        srv_bipi_disconnect_ind_hdlr();
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_continue_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bip_continue_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_continue_ind_struct *ind = (bt_bip_continue_ind_struct*) msg;
    //S32 retval = 0;
    //mmi_bt_bip_error_enum bip_error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bip_p->bipi_cntx.cm_conn_id == ind->cm_conn_id)
    {
        srv_bipi_push_continue_ind_hdlr(ind);
    }
    else
    {
        if (srv_bip_p->bipr_cntx.cm_conn_id == ind->cm_conn_id)
        {
            srv_bip_send_continue_rsp(ind->cm_conn_id, BT_BIP_CNF_SUCCESS);

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
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
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
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_send_continue_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cm_conn_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bip_send_continue_rsp(U32 cm_conn_id, U8 rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_continue_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_bip_continue_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_continue_rsp_struct));
    BIP_MEMSET(rsp);    /* memory init */
    rsp->cnf_code = rsp_code;

    rsp->cm_conn_id = cm_conn_id;

    srv_bip_send_msg(MSG_ID_BT_BIP_CONTINUE_RSP, rsp);
}



/*****************************************************************************
 * FUNCTION
 *  srv_oppc_post_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_id        [IN]        
 *  para            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret srv_bip_post_proc(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bip_event_struct *event = (srv_bip_event_struct *)para;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (event->role == SRV_BIP_INITIATOR_ROLE)
    {
        SRV_BIP_LOG(SRV_BIPI_POST_EVENT_PROC);
        srv_bipi_notify_app(event->event_id, event->data);

    }
    else
    {
        SRV_BIP_LOG(SRV_BIPR_POST_EVENT_PROC);
        srv_bipr_notify_app(event->event_id, event->data);
    }
    
    if (event->data != NULL)
    {
        OslMfree(event->data);
    }
    
    return MMI_RET_OK;
}



#define MMI_BIP_INITIATOR_FUNC

/*****************************************************************************
 * FUNCTION
 *  srv_bip_cntx_init
 * DESCRIPTION
 *  This function is to initialize BIP application context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipi_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 handle;
    S32 ret;
    srv_bt_cm_profile_struct prof_struct;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&srv_bip_p->bipi_cntx, 0, sizeof(srv_bip_p->bipi_cntx));
    memset(&srv_bip_p->initiator_hd, 0, sizeof (srv_bip_p->initiator_hd));

    srv_bip_p->bipi_cntx.state = SRV_BIPI_STATE_IDLE;
    srv_bip_p->bipi_cntx.req_id = MMI_BIP_INVALID_REQ_ID;

    srv_bip_p->bipi_cntx.cm_conn_id = MMI_BIP_INVALID_CONN_ID;

    handle = FS_Open((U16*) BIP_FOLDER_PATH, FS_READ_ONLY | FS_OPEN_DIR);
    if (handle >= FS_NO_ERROR)
    {
        FS_Close(handle);
    }
    else    /* Error handling */
    {
        SRV_BIP_LOG2(SRV_BIP_FS_OPEN_RETURN, handle, 3);
        ret = FS_CreateDir((U16*) BIP_FOLDER_PATH);
        if (ret < 0)
        {
            SRV_BIP_LOG2(SRV_BIP_FS_CREATEDIR_RETURN, ret, 2);
        }
    }
    prof_struct.profile_id = SRV_BT_CM_OBEX_IMAGING_UUID;
    prof_struct.activater = NULL;
    prof_struct.deactivater = NULL;
    prof_struct.disconnector = srv_bipi_disconnect_from_cm;
    srv_bt_cm_profile_register((const srv_bt_cm_profile_struct *)&prof_struct);

}


/*****************************************************************************
 * FUNCTION
 *  srv_bipi__connect_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle server MSG_ID_BT_BIP_CONNECT_CNF msg
 * PARAMETERS
 *  msg     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipi_connect_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_connect_cnf_struct *rsp = (bt_bip_connect_cnf_struct*) msg;
    //U8 cause = MMI_BIP_SUCCESS;
    srv_bip_conn_notify_struct conn_notify;
    srv_bip_snd_notify_struct snd_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG2(SRV_BIPI_CONNECT_CNF, rsp->cnf_code, srv_bip_p->bipi_cntx.state);

    StopTimer(BT_BIP_REQ_TIMER);

    //srv_bip_p->bipi_cntx.req_id = MMI_BIP_INVALID_REQ_ID;

    /* Connection is established successfully  */
    if (rsp->cnf_code == BT_BIP_CNF_SUCCESS)
    {
        switch (srv_bip_p->bipi_cntx.state)
        {
            case SRV_BIPI_STATE_CONNECTING:
            {
                /* The connection is established */

                /* set bip context */
                srv_bip_p->bipi_cntx.cm_conn_id = rsp->cm_conn_id;
                
                MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_CONNECTED);

                conn_notify.type = SRV_BIP_CONN_SUCC;
                conn_notify.conn_id = srv_bip_p->bipi_cntx.cm_conn_id;
                conn_notify.bt_addr = srv_bip_p->bipi_cntx.bt_device;

                srv_bt_cm_connect_ind(srv_bip_p->bipi_cntx.req_id);

                srv_bipi_notify_app(SRV_BIP_EVENT_CONN_NOTIFY, (void *)&conn_notify);

                snd_notify.type = SRV_BIP_SND_READY;
                srv_bipi_notify_app(SRV_BIP_EVENT_SND_NOTIFY, (void *)&snd_notify);
              
                return;
            }

            case SRV_BIPI_STATE_ABORTING:
            case SRV_BIPI_STATE_DISCONNECTING:
                srv_bipi_send_disconnect_req(SRV_BIP_OBEX_DISCONNECT);
                break;
                
                /* connect cancel before connect rsp (race condition -> discard this msg) */
            
                /* reset */
            case SRV_BIPI_STATE_IDLE:
                return;
                
                /* Connection establish fail */
            default:

                MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_IDLE);

                MMI_ASSERT(0);
                return;
        }
    }
    else
    {
        MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_IDLE);
        conn_notify.conn_id = MMI_BIP_INVALID_CONN_ID;
        
        if (rsp->cnf_code == BT_BIP_SCO_REJECT)
        {
            conn_notify.type = SRV_BIP_CONN_SCO_REJECT;
        }
        else
        {
            conn_notify.type = SRV_BIP_CONN_FAILED;
        }

        srv_bt_cm_stop_conn(srv_bip_p->bipi_cntx.req_id);

        srv_bipi_notify_app(SRV_BIP_EVENT_CONN_NOTIFY, (void *) &conn_notify);
        
        snd_notify.type = SRV_BIP_SND_DONE;

        srv_bipi_notify_app(SRV_BIP_EVENT_SND_NOTIFY, (void *) &snd_notify);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipi_abort_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]   
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipi_abort_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_abort_cnf_struct *rsp = (bt_bip_abort_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG2(SRV_BIP_ABORT_CNF, rsp->cnf_code, srv_bip_p->bipi_cntx.state);

    StopTimer(BT_BIP_REQ_TIMER);

    if (srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_IDLE)
    {
        return;
    }
    
    srv_bipi_push_abort_cnf_hdlr(rsp);

    //srv_bip_p->bipi_cntx.cur_oper = MMI_BIP_OPER_IDLE;
}



/*****************************************************************************
 * FUNCTION
 *  srv_bipi__push_abort_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsp     [?]   
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipi_push_abort_cnf_hdlr(bt_bip_abort_cnf_struct *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bip_snd_notify_struct snd_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG(SRV_BIPI_PUSH_ABORT_CNF);

    MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_CONNECTED);
    
    snd_notify.type = SRV_BIP_SND_FAIL;
    srv_bipi_notify_app(SRV_BIP_EVENT_SND_NOTIFY, (void *) &snd_notify);

}


/*****************************************************************************
 * FUNCTION
 *  srv_bipi__push_get_capabilities_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg    
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipi_push_get_capabilities_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_capabilities_cnf_struct *cnf = (bt_bip_get_capabilities_cnf_struct*) msg;
    bt_bip_img_format_enum cur_img_fmt;
    U8 i;
    MMI_BOOL bSupport = MMI_FALSE;
    srv_bip_capability_notify_struct capability_notify;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG2(SRV_BIPI_GET_CAPABILITIES_CNF, cnf->cnf_code,srv_bip_p->bipi_cntx.state);

    if (srv_bip_p->bipi_cntx.state != SRV_BIPI_STATE_GETTING_CAPABILITIES)
    {
        /* if not in proper state, discard the cnf msg */
        return;
    }

    if (cnf->cnf_code != BT_BIP_CNF_SUCCESS)
    {
        capability_notify.type = SRV_BIP_CAPABILITY_FAIL;

        srv_bipi_notify_app(SRV_BIP_EVENT_GET_CAPABILITY_NOTIFY, (void *)&capability_notify);
        return;
    }
    
    /* check if the responder support current image format */
    cur_img_fmt = srv_bip_get_image_type(srv_bip_p->bipi_cntx.img_path_snd);
    srv_bip_p->bipi_cntx.img_type = cur_img_fmt;
    
    if (cur_img_fmt != BT_BIP_IMG_TYPE_UNSUPPORT)
    {
        for (i=0; i < BT_BIP_MAX_IMG_FORMATS; i++)
        {
            if (cur_img_fmt == cnf->supported_img_formats[i])
            {       
                bSupport = MMI_TRUE;
                break;
            }
        }

        if (!bSupport)
        {
            srv_bip_p->bipi_cntx.img_type = BT_BIP_IMG_TYPE_JPEG;

            capability_notify.type = SRV_BIP_CAPABILITY_UNSUPPORT;

            srv_bipi_notify_app(SRV_BIP_EVENT_GET_CAPABILITY_NOTIFY, (void *)&capability_notify);
            return;
        }
    }

    /* send PUSH image request */

    srv_bipi_send_push_req();
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipi__put_img_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]    
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipi_push_img_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_put_img_cnf_struct *rsp = (bt_bip_put_img_cnf_struct*) msg;
    MMI_BOOL b_thm_success;
    U16 thm_path_file[SRV_FMGR_PATH_MAX_LEN];
    srv_bip_snd_notify_struct snd_notify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG2(SRV_BIPI_PUT_IMG_CNF, rsp->cnf_code,srv_bip_p->bipi_cntx.state);

    if (srv_bip_p->bipi_cntx.state != SRV_BIPI_STATE_SENDING_IMG)
    {
        return;
    }

    MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_CONNECTED);

    //rsp->cnf_code = BT_BIP_PARTIAL_CONTENT;
    if (rsp->cnf_code == BT_BIP_CNF_SUCCESS)
    {
        snd_notify.type = SRV_BIP_SND_PERSENT;
        srv_bip_p->bipi_cntx.sent_size = srv_bip_p->bipi_cntx.img_total_size;
        snd_notify.u.info.sent_size = srv_bip_p->bipi_cntx.sent_size;
        snd_notify.u.info.total_obj_size = srv_bip_p->bipi_cntx.img_total_size;
        srv_bipi_notify_app(SRV_BIP_EVENT_SND_NOTIFY, (void *) &snd_notify);
    }
    
    if (rsp->cnf_code == BT_BIP_CNF_SUCCESS)
    {
        snd_notify.type = SRV_BIP_SND_SUCC;  
    }
    else if (rsp->cnf_code == BT_BIP_PARTIAL_CONTENT)
    {
        /* the responder request to put thumbnail */

        /* generate thumbnail */
        b_thm_success = srv_bip_generate_thumbnail(
                            srv_bip_p->bipi_cntx.img_path_snd,
                            thm_path_file,
                            SRV_FMGR_PATH_MAX_LEN,
                            SRV_BIP_INITIATOR_ROLE);
        if (b_thm_success)
        {
            bt_bip_put_linked_thumbnail_req_struct *req;

            req = (bt_bip_put_linked_thumbnail_req_struct*)OslConstructDataPtr(sizeof(bt_bip_put_linked_thumbnail_req_struct));

            BIP_MEMSET(req);

            req->cm_conn_id = rsp->cm_conn_id;
            strcpy((char*)req->img_handle, (char*)rsp->img_handle);
            
            mmi_wcscpy(req->img_path, thm_path_file);

            MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_SENDING_THM);
            
            srv_bip_send_msg(MSG_ID_BT_BIP_PUT_LINKED_THUMBNAIL_REQ, req);
            return;
        }
        else
        {
            snd_notify.type = SRV_BIP_SND_FAIL;
            //srv_bipi_notify_app(SRV_BIP_EVENT_SND_NOTIFY, (void *) &snd_notify);
        }
    }
    else if (rsp->cnf_code == GOEP_PRECONDITION_FAILED)
    {
        snd_notify.type = SRV_BIP_SND_FAIL_BY_SERVER;
    }
    else
    {
        snd_notify.type = SRV_BIP_SND_FAIL;
        
        //srv_bipi_notify_app(SRV_BIP_EVENT_SND_NOTIFY, (void *) &snd_notify);
    }

    srv_bipi_notify_app(SRV_BIP_EVENT_SND_NOTIFY, (void *) &snd_notify);
 
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipi__put_thm_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipi_push_thm_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_put_linked_thumbnail_cnf_struct *rsp = (bt_bip_put_linked_thumbnail_cnf_struct*) msg;
    //mmi_bt_bip_error_enum rst;
    srv_bip_snd_notify_struct snd_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG2(SRV_BIPI_PUT_THM_CNF, rsp->cnf_code, srv_bip_p->bipi_cntx.state);

    if (srv_bip_p->bipi_cntx.state != SRV_BIPI_STATE_SENDING_THM)
    {
        /* send abort request because user already abort */
        return;
    }

    if (rsp->cnf_code == BT_BIP_CNF_SUCCESS)
    {
        snd_notify.type = SRV_BIP_SND_SUCC;
        //srv_bipi_notify_app(SRV_BIP_EVENT_SND_NOTIFY, (void *) &snd_notify);
    }
    else    /* failed */
    {
        snd_notify.type = SRV_BIP_SND_FAIL;
       
    }

    srv_bipi_notify_app(SRV_BIP_EVENT_SND_NOTIFY, (void *) &snd_notify);

}


/*****************************************************************************
 * FUNCTION
 *  srv_bipi__push_continue_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ind     [?]   
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipi_push_continue_ind_hdlr(bt_bip_continue_ind_struct *ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bip_snd_notify_struct snd_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    SRV_BIP_LOG1(SRV_BIPI_PUSH_CONTINUE_IND, srv_bip_p->bipi_cntx.state);

    if (srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_ABORTING)
    {
        return;
    }
    else if (srv_bip_p->bipi_cntx.state != SRV_BIPI_STATE_SENDING_IMG &&
            srv_bip_p->bipi_cntx.state != SRV_BIPI_STATE_SENDING_THM&&
            srv_bip_p->bipi_cntx.state != SRV_BIPI_STATE_GETTING_CAPABILITIES)
    {
        /*notify APP the sending process failed, and wait APP send disconnect req */

        snd_notify.type = SRV_BIP_SND_FAIL;
        srv_bipi_notify_app(SRV_BIP_EVENT_SND_NOTIFY, (void *) &snd_notify);
        
        return;
    }

    /* update sent_size */
    if (srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_SENDING_IMG)
    {
        srv_bip_p->bipi_cntx.sent_size += ind->data_len;
    }

    /* send continue rsp */
    srv_bip_send_continue_rsp(ind->cm_conn_id, BT_BIP_CNF_SUCCESS);
}



/*****************************************************************************
 * FUNCTION
 *  srv_bipi__disconnect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipi_disconnect_ind_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U8 cause = MMI_BIP_ERR_DISCONNECTED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIPI_DISCONNECT_IND,srv_bip_p->bipi_cntx.state);
    
    srv_bt_cm_unreg_pairing_permission(SRV_BT_CM_OBEX_IMAGING_UUID);
 
    switch (srv_bip_p->bipi_cntx.state)
    {
        case SRV_BIPI_STATE_IDLE:
            return;
            
        case SRV_BIPI_STATE_DISCONNECTING:
        case SRV_BIPI_STATE_ABORTING:         
            /* fall through */        
        case SRV_BIPI_STATE_CONNECTING:
        default:
            MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_IDLE);  /* state -> active */
            /* reset context */
            srv_bipi_connection_terminated();
            return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipi__send_get_capabilities_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cm_conn_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipi_send_get_capabilities_req(U32 cm_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_capabilities_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_GETTING_CAPABILITIES);

    req = (bt_bip_get_capabilities_req_struct*) OslConstructDataPtr(sizeof(bt_bip_get_capabilities_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->cm_conn_id = cm_conn_id;

    srv_bip_send_msg(MSG_ID_BT_BIP_GET_CAPABILITIES_REQ, req);
}



/*****************************************************************************
 * FUNCTION
 *  srv_bipi__send_push_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipi_send_push_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_put_img_req_struct *req;
    bt_bip_img_info_struct desc;
    FS_HANDLE hFile;
    int ret;
    S32 result;
    S32 width = 0, height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_SENDING_IMG);
    
    hFile = FS_Open( srv_bip_p->bipi_cntx.img_path_snd, FS_READ_ONLY);
    SRV_BIP_LOG2(SRV_BIP_FS_OPEN_RETURN, hFile, 20);

    memset(&desc, 0, sizeof(bt_bip_img_info_struct));
    
    desc.encoding = srv_bip_p->bipi_cntx.img_type;

    ret = FS_GetFileSize(hFile, &desc.size);
    SRV_BIP_LOG2(SRV_BIP_FS_GETFILESIZE_RETRUN, ret, desc.size);
    
    ret = FS_Close(hFile);
    SRV_BIP_LOG1(SRV_BIP_FS_CLOSE_RETURN, ret);

    result = gdi_image_get_dimension_file(
                (S8*) srv_bip_p->bipi_cntx.img_path_snd,
                (S32*) & width,
                (S32*) & height);

    if (result != GDI_SUCCEED)
    {
        SRV_BIP_LOG(SRV_BIP_GET_DIMENSION_FAILED);
    }

    SRV_BIP_LOG3(SRV_BIP_GDI_GET_DIMENSION, result,width,height);

    desc.specified_pixel_width = (U16) width;
    desc.specified_pixel_height = (U16) height;

    srv_bip_p->bipi_cntx.img_total_size = desc.size;
    srv_bip_p->bipi_cntx.sent_size = 0;

    /* construct push image req ilm */
    req = (bt_bip_put_img_req_struct*) OslConstructDataPtr(sizeof(bt_bip_put_img_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->cm_conn_id = srv_bip_p->bipi_cntx.cm_conn_id;

    req->img_descriptor = desc;
    req->img_size = desc.size;

    mmi_wcscpy((U16 *)req->img_name, srv_bip_p->bipi_cntx.img_name);

    SRV_BIP_LOG_PATH(req->img_name);
    mmi_wcscpy(req->img_path, srv_bip_p->bipi_cntx.img_path_snd);

    srv_bip_send_msg(MSG_ID_BT_BIP_PUT_IMG_REQ, req);

}


/*****************************************************************************
 * FUNCTION
 *  srv_bipi__send_disconnect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipi_send_disconnect_req(srv_bip_disconnect_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_BIPI_STATE_TRANS(SRV_BIPI_STATE_DISCONNECTING);
    //srv_bip_p->bipi_cntx.b_disconnect_req_sent = MMI_TRUE;
    srv_bip_send_disconnect_req(srv_bip_p->bipi_cntx.cm_conn_id, type, BT_BIP_INITIATOR_ROLE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipi__send_abort_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cm_conn_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipi_send_abort_req(U32 cm_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_abort_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    req = (bt_bip_abort_req_struct*) OslConstructDataPtr(sizeof(bt_bip_abort_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->cm_conn_id = cm_conn_id;

    srv_bip_send_msg(MSG_ID_BT_BIP_ABORT_REQ, req);

    StartTimer(BT_BIP_REQ_TIMER, MMI_BIP_ABORT_TIMER_DUR, srv_bip_request_timeout_hdlr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_send_disconnect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cm_conn_id      [IN]        
 *  type            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bip_send_disconnect_req(U32 cm_conn_id, srv_bip_disconnect_type_enum type, bt_bip_session_role_enum role)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_disconnect_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    req = (bt_bip_disconnect_req_struct*) OslConstructDataPtr(sizeof(bt_bip_disconnect_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->cm_conn_id = cm_conn_id;
    req->session_role = role;

    if (type == SRV_BIP_TP_DISCONNECT)
    {
        req->disconnect_tp_directly = KAL_TRUE;
        /* TP-Disconnect need no timer */
    }
    else
    {
        req->disconnect_tp_directly = KAL_FALSE;

        StartTimer(BT_BIP_REQ_TIMER, MMI_BIP_DISCONNECT_TIMER_DUR, srv_bip_request_timeout_hdlr);
    }

    srv_bip_send_msg(MSG_ID_BT_BIP_DISCONNECT_REQ, req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_request_timeout_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bip_request_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIP_REQUEST_TIMEOUT, srv_bip_p->bipi_cntx.state);

    switch (srv_bip_p->bipi_cntx.state)
    {
        case SRV_BIPI_STATE_CONNECTING:            
        case SRV_BIPI_STATE_ABORTING:
        case SRV_BIPI_STATE_DISCONNECTING:
            srv_bipi_send_disconnect_req(SRV_BIP_TP_DISCONNECT);
            break;

        default:
            break;
    }

}

/*****************************************************************************
 * FUNCTION
 *  srv_bipi_connection_terminated
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipi_connection_terminated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_bip_disconn_notify_struct disconn_notify;
    srv_bip_snd_notify_struct snd_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIPI_CONNECTION_TERMINATED, srv_bip_p->bipi_cntx.state);

    disconn_notify.conn_id = srv_bip_p->bipi_cntx.cm_conn_id;
    disconn_notify.bt_addr = srv_bip_p->bipi_cntx.bt_device;
    srv_bt_cm_stop_conn(srv_bip_p->bipi_cntx.req_id);
    srv_bipi_notify_app(SRV_BIP_EVENT_DISCONN_NOTIFY, (void *) &disconn_notify);

    snd_notify.type = SRV_BIP_SND_DONE;
    srv_bipi_notify_app(SRV_BIP_EVENT_SND_NOTIFY, (void *) &snd_notify);

    /* reset members */
    srv_bip_p->bipi_cntx.state = SRV_BIPI_STATE_IDLE;
    srv_bip_p->bipi_cntx.cm_conn_id = MMI_BIP_INVALID_CONN_ID;
    srv_bip_p->bipi_cntx.req_id = MMI_BIP_INVALID_REQ_ID;
    srv_bip_p->bipi_cntx.img_total_size = 0;
    srv_bip_p->bipi_cntx.sent_size = 0;
        
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipi_pairing_permit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cause       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_bipi_pairing_permit(srv_bt_cm_bt_addr bt_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_DISCONNECTING) &&
          ((bt_addr.lap == srv_bip_p->bipi_cntx.bt_device.lap) && 
         (bt_addr.uap == srv_bip_p->bipi_cntx.bt_device.uap) && 
         (bt_addr.nap == srv_bip_p->bipi_cntx.bt_device.nap)))
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bipi_push_prog_percentage
 * DESCRIPTION
 *  This function is to retrieve the file put progress.
 * PARAMETERS
 *  void
 * RETURNS
 *  1 ~ 100  The percentage of put process.
 *****************************************************************************/
void srv_bipi_get_obj_info(srv_bip_img_info_struct *obj_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    obj_info->sent_size = srv_bip_p->bipi_cntx.sent_size;
    obj_info->total_obj_size = srv_bip_p->bipi_cntx.img_total_size;
}



/*****************************************************************************
 * FUNCTION
 *  srv_bipi_notify_app
 * DESCRIPTION
 *  This function is to notify APP the happened event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 srv_bipi_notify_app(S32 event_id, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i = 0; i < SRV_BIP_MAX_CLIENT_NUM; i++)
    {
        if (srv_bip_p->initiator_hd[i].srv_hd > 0 && srv_bip_p->initiator_hd[i].srv_hd < SRV_BIP_REPONDER_HANDLE_BEGIN)
        {
            if (srv_bip_p->initiator_hd[i].event_mask & event_id)
            {
                return srv_bip_p->initiator_hd[i].notifier(srv_bip_p->initiator_hd[i].srv_hd, event_id, para);
            }
        }
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_oppc_disconnect_from_cm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  conn_id        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipi_disconnect_from_cm(U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_bip_handle_struct *inst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i++; i < SRV_BIP_MAX_CLIENT_NUM)
    {
        inst = &srv_bip_p->initiator_hd[i];
        if (conn_id == inst->u.bipi_cntx->req_id)
        {
            break;
        }
    }
    if (i < SRV_BIP_MAX_CLIENT_NUM)
    {
        srv_bipi_send_end(i + 1);
    }

}

void srv_bipr_disconnect_client(U32 cm_conn_id);


#define MMI_BIP_RESPONDER_FUNC
/*****************************************************************************
 * FUNCTION
 *  srv_bip_cntx_init
 * DESCRIPTION
 *  This function is to initialize BIP application context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipr_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_cm_profile_struct profile_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&srv_bip_p->bipr_cntx, 0, sizeof(srv_bip_p->bipr_cntx));
    memset(&srv_bip_p->responder_hd, 0, sizeof (srv_bip_p->responder_hd));

    srv_bip_p->bipr_cntx.state = SRV_BIPR_STATE_IDLE;
    //srv_bip_p->bipr_cntx.req_id = MMI_BIP_INVALID_REQ_ID;

    srv_bip_p->bipr_cntx.cm_conn_id = MMI_BIP_INVALID_CONN_ID;

    srv_bip_p->bipr_cntx.cur_recv_img_num = 0;

	profile_info_p.profile_id = SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID;
	profile_info_p.activater = srv_bipr_activate;
	profile_info_p.deactivater = srv_bipr_deactivate;
	profile_info_p.disconnector = srv_bipr_disconnect_client;
	srv_bt_cm_profile_register((const srv_bt_cm_profile_struct*)&profile_info_p);
}





/*****************************************************************************
 * FUNCTION
 *  srv_bipr_activate_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipr_activate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_activate_cnf_struct *cnf = (bt_bip_activate_cnf_struct*) msg;
    bt_sdpdb_register_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIPR_ACTIVATE_CNF,srv_bip_p->bipr_cntx.state);

    //srv_bip_p->bipr_cntx.req_id = MMI_BIP_INVALID_CONN_ID;
    if (cnf->cnf_code != BT_BIP_CNF_SUCCESS)
    {
        MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_IDLE);
        return;
    }
    /* success */
    if (srv_bip_p->bipr_cntx.state != SRV_BIPR_STATE_REGISTERING)
    {
        return;
    }

    MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_ACTIVE);

    /* Send SDP Register primitive */
    req = (bt_sdpdb_register_req_struct*) OslConstructDataPtr(sizeof(bt_sdpdb_register_req_struct));
    BIP_MEMSET(req);    /* memory init */
    req->uuid = (U32) SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID;
    {
        ilm_struct *ilm_send;

        ilm_send = allocate_ilm(MOD_MMI);
        ilm_send->src_mod_id = MOD_MMI;
        ilm_send->dest_mod_id = MOD_BT;
        ilm_send->sap_id = BT_APP_SAP;
        ilm_send->msg_id = (U16) MSG_ID_BT_SDPDB_REGISTER_REQ;
        ilm_send->local_para_ptr = (local_para_struct*) req;
        ilm_send->peer_buff_ptr = (peer_buff_struct*) NULL;

        msg_send_ext_queue(ilm_send);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_deactivate_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipr_deactivate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //bt_bip_deactivate_cnf_struct *rsp = (bt_bip_deactivate_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIPR_DEACTIVATE_CNF,srv_bip_p->bipr_cntx.state);

    srv_bt_cm_deactivate_cnf_hdler(SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID);
    
    MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_IDLE);  /* don't have to reset context */
    //srv_bip_p->bipr_cntx.req_id = MMI_BIP_INVALID_CONN_ID;
    /* no connection is wating for deregister rsp -> deactivate cnf to CM */

    srv_bipr_notify_app(SRV_BIP_EVENT_STOP, NULL);
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_sdp_register_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle SDP REGISTER CNF msg
 * PARAMETERS
 *  msg     
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_bipr_sdp_register_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_sdpdb_register_cnf_struct *cnf = (bt_sdpdb_register_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIPR_SDP_REGISTER_CNF,cnf->result);

    if (cnf->uuid != SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID)
    {
        return MMI_FALSE;
    }
    /* SDP register success */
    if (cnf->result == 0x00)
    {
        /* call activate cnf to CM */
        srv_bt_cm_activate_cnf_hdler((U32) SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID);
        srv_bipr_notify_app(SRV_BIP_EVENT_START, NULL);
        return MMI_TRUE;
        
    }
    /* SDP register failed */
    else
    {
        ASSERT(0);
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_sdp_deregister_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle SDP REGISTER CNF msg
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_bipr_sdp_deregister_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_sdpdb_deregister_cnf_struct *cnf = (bt_sdpdb_deregister_cnf_struct*) msg;
    bt_bip_deactivate_req_struct *req;
    srv_bt_cm_bt_addr bd_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIPR_SDP_DEREGISTER_CNF,srv_bip_p->bipr_cntx.state);

    if (cnf->uuid != SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID)
    {
        return MMI_FALSE;
    }
    
    if (cnf->result != 0x00)
    {
        /* SDP register Failed */
        return MMI_FALSE;
    }

    switch (srv_bip_p->bipr_cntx.state)
    {
            /* can't deactivate twice */
        case SRV_BIPR_STATE_DEACTIVATING:
            break;
            
            /* do nothing (handle this case in disconnecting rsp) */
        case SRV_BIPR_STATE_DISCONNECTING:
            MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_DEACTIVATING);
            break;
            
            /* states with active connection */
        case SRV_BIPR_STATE_AUTHORIZING:
        case SRV_BIPR_STATE_AUTHORIZED:
        case SRV_BIPR_STATE_CONNECTED:
        case SRV_BIPR_STATE_RECEIVING_IMG:
        case SRV_BIPR_STATE_RECEIVING_THM:
        case SRV_BIPR_STATE_SENDING_IMG:
        case SRV_BIPR_STATE_SENDING_LPT:
        case SRV_BIPR_STATE_CONSTRUCTING_IMGLIST:
            MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_DEACTIVATING);
            memset(&bd_addr, 0, sizeof(srv_bt_cm_bt_addr));
            srv_bipr_disconn_client(srv_bip_p->responder_hd[0].srv_hd, srv_bip_p->bipr_cntx.cm_conn_id);
            break;

        case SRV_BIPR_STATE_IDLE:
            return MMI_TRUE;

        case SRV_BIPR_STATE_ACTIVE:
            /* ok ? */
        default:
            MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_DEACTIVATING);
            req = (bt_bip_deactivate_req_struct*) OslConstructDataPtr(sizeof(bt_bip_deactivate_req_struct));
            BIP_MEMSET(req);    /* memory init */

            //req->req_id = BIP_CURR_REQ_ID;
            //srv_bip_p->bipr_cntx.req_id = req->req_id;
            req->bip_service_set = BT_BIP_IMAGE_PUSH | BT_BIP_IMAGE_PULL;

            /* send req to bt */
            srv_bip_send_msg(MSG_ID_BT_BIP_DEACTIVATE_REQ, req);
            break;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_disconnect_client
 * DESCRIPTION
 *  This function is to deactivate the BIP application
 * PARAMETERS
 *  bd_addr         [IN]        
 *  cm_conn_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_bipr_disconn_client(U32 srv_hd, U32 cm_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bip_handle_struct *inst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG3(SRV_BIPS_DISCONNECT_CLIENT,
            srv_bip_p->bipr_cntx.state, 
            srv_hd, 
            cm_conn_id);

    inst = srv_bip_get_inst_from_srv_hd(srv_hd);

    if (inst == NULL)
        return SRV_BIP_RESULT_INVALID_HANDLE;

	srv_bipr_disconnect_client(srv_bip_p->bipr_cntx.cm_conn_id);
    
    return SRV_BIP_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_disconnect_client
 * DESCRIPTION
 *  This function is to disconnect the BIP application
 * PARAMETERS
 *  bd_addr         [IN]        
 *  cm_conn_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bipr_disconnect_client(U32 cm_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bip_handle_struct *inst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG2(SRV_BIPS_DISCONNECT_CLIENT,
            srv_bip_p->bipr_cntx.state, 
            cm_conn_id);

    switch (srv_bip_p->bipr_cntx.state)
    {
        case SRV_BIPR_STATE_DISCONNECTING:  /* disconnecting -> disconnecting */
            return;

            /* connected states */
        case SRV_BIPR_STATE_RECEIVING_IMG:
        case SRV_BIPR_STATE_RECEIVING_THM:
        case SRV_BIPR_STATE_SENDING_IMG:
        case SRV_BIPR_STATE_SENDING_LPT:
        case SRV_BIPR_STATE_ACTIVE:
        case SRV_BIPR_STATE_AUTHORIZING:
        case SRV_BIPR_STATE_AUTHORIZED:
        case SRV_BIPR_STATE_CONNECTED:
        case SRV_BIPR_STATE_CONSTRUCTING_IMGLIST:
           /* then do the same thing as state deactivating */
            /* deactivate triggered disconnecting */
        case SRV_BIPR_STATE_DEACTIVATING:
            srv_bip_send_disconnect_req(
                srv_bip_p->bipr_cntx.cm_conn_id, 
                SRV_BIP_TP_DISCONNECT,
                BT_BIP_RESPONDER_ROLE);
            
            return;

            /* don't have to disconnect in states without connection */
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_authorize_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]   
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipr_authorize_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_authorize_ind_struct *ind = (bt_bip_authorize_ind_struct*) msg;
    srv_bip_authorize_notify_struct auth_notify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIPR_AUTHORIZE_IND, srv_bip_p->bipr_cntx.state);

    memset(srv_bip_p->bipr_cntx.recv_img_name, 0, 
            sizeof(srv_bip_p->bipr_cntx.recv_img_name));
                 

    if (srv_bip_p->bipr_cntx.state != SRV_BIPR_STATE_ACTIVE)
    {
        srv_bipr_send_authorize_rsp(GOEP_METHOD_NOT_ALLOWED/*BT_BIP_CNF_FAILED*/);
        return;
    }

    srv_bip_p->bipr_cntx.conn_id = srv_bt_cm_start_conn(
                                        MMI_TRUE,
                                        SRV_BT_CM_OBEX_IMAGING_RESPONDER_UUID, 
                                        (srv_bt_cm_bt_addr *)&(ind->bd_addr),
                                        ind->dev_name);

    if (srv_bip_p->bipr_cntx.conn_id > 0)
    {
    MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_AUTHORIZING);

    srv_bip_p->bipr_cntx.bt_device.lap = ((srv_bt_cm_bt_addr *) &ind->bd_addr)->lap;
    srv_bip_p->bipr_cntx.bt_device.uap = ((srv_bt_cm_bt_addr *) &ind->bd_addr)->uap;
    srv_bip_p->bipr_cntx.bt_device.nap = ((srv_bt_cm_bt_addr *) &ind->bd_addr)->nap;
    
    auth_notify.bt_addr = srv_bip_p->bipr_cntx.bt_device;

    strcpy((S8*)auth_notify.dev_name, (S8*)ind->dev_name);
        auth_notify.conn_id = srv_bip_p->bipr_cntx.conn_id;

    srv_bipr_notify_app(SRV_BIP_EVENT_AUTHORIZE_NOTIFY, (void *) &auth_notify);
    }
    else
    {
        srv_bipr_send_authorize_rsp(GOEP_METHOD_NOT_ALLOWED/*BT_BIP_CNF_FAILED*/);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_connect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]   
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipr_connect_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_connect_ind_struct *ind = (bt_bip_connect_ind_struct*) msg;
    srv_bip_conn_notify_struct conn_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIPR_CONNECT_IND, srv_bip_p->bipr_cntx.state);

    if (srv_bip_p->bipr_cntx.state != SRV_BIPR_STATE_AUTHORIZED/*MMI_BIPR_STATE_ACTIVE*/)
    {
        srv_bipr_send_connect_rsp(GOEP_METHOD_NOT_ALLOWED/*BT_BIP_CNF_FAILED*/);
        return;
    }

    /* update BIPR context */
    /* reset responder context */    
    srv_bip_p->bipr_cntx.cm_conn_id = ind->cm_conn_id;

    srv_bipr_send_connect_rsp(BT_BIP_CNF_SUCCESS);

    srv_bt_cm_connect_ind(srv_bip_p->bipr_cntx.conn_id);

    conn_notify.type = SRV_BIP_CONN_SUCC;
    conn_notify.conn_id = ind->cm_conn_id;
    conn_notify.bt_addr.lap = ((srv_bt_cm_bt_addr *) &ind->bd_addr)->lap;
    conn_notify.bt_addr.uap = ((srv_bt_cm_bt_addr *) &ind->bd_addr)->uap;
    conn_notify.bt_addr.nap = ((srv_bt_cm_bt_addr *) &ind->bd_addr)->nap;

    srv_bipr_notify_app(SRV_BIP_EVENT_CONN_NOTIFY, (void *)&conn_notify);

}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_get_capabilities_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg      
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipr_get_capabilities_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIPR_GET_CAPABILITIES_IND,srv_bip_p->bipr_cntx.state);

    switch (srv_bip_p->bipr_cntx.state)
    {
        case SRV_BIPR_STATE_CONNECTED:
            break;

        default:
            /* do nothing */
            return;
    }

    srv_bipr_send_get_capabilities_rsp();
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_push_img_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]   
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipr_push_img_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_put_img_ind_struct *ind = (bt_bip_put_img_ind_struct*) msg;
    srv_bip_recv_notify_struct recv_notify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIPR_PUSH_IMG_IND,srv_bip_p->bipr_cntx.state);

    if ((srv_bip_p->bipr_cntx.state == SRV_BIPR_STATE_DISCONNECTING) ||
        (srv_bip_p->bipr_cntx.state == SRV_BIPR_STATE_DEACTIVATING))
    {
        /* Do nothing */
        return;
    }

    
    if (srv_bip_p->bipr_cntx.state != SRV_BIPR_STATE_CONNECTED)
    {
        /* Wrong state */
        srv_bipr_send_push_rsp(GOEP_SERVICE_UNAVAILABLE, NULL);
        return;
    }

    srv_bip_truncate_obj_name(
        srv_bip_p->bipr_cntx.recv_img_name, 
        (U16 *)ind->img_name, 
        sizeof (srv_bip_p->bipr_cntx.recv_img_name), 
        MMI_TRUE);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_RECEIVING_IMG);

    recv_notify.type = SRV_BIP_RECV_BEGIN;
    recv_notify.conn_id = ind->cm_conn_id;
    recv_notify.u.detail.total_len = ind->img_size;
    recv_notify.u.detail.encoding= ind->img_descriptor.encoding;
    mmi_wcscpy(recv_notify.u.detail.name, srv_bip_p->bipr_cntx.recv_img_name);

    srv_bipr_notify_app(SRV_BIP_EVENT_RECV_NOTIFY, (void *)&recv_notify);
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_put_thm_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]   
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipr_push_thm_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_put_linked_thumbnail_ind_struct *ind = (bt_bip_put_linked_thumbnail_ind_struct*) msg;
    srv_bip_recv_notify_struct recv_notify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIPR_PUSH_THM_IND,srv_bip_p->bipr_cntx.state);

    if (srv_bip_p->bipr_cntx.state != SRV_BIPR_STATE_CONNECTED)
    {
        /* Wrong state */
        return;
    }

    MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_RECEIVING_THM);
    //memcpy(srv_bip_p->bipr_cntx.cur_img_handle, ind->img_handle, BT_BIP_IMG_HANDLE_LEN);

    srv_bip_gen_thm_filename(srv_bip_p->bipr_cntx.recv_img_name, (S8 *)ind->img_handle);

    recv_notify.type = SRV_BIP_RECV_READY;
    recv_notify.u.detail.total_len = -1;
    mmi_wcscpy(recv_notify.u.detail.name, srv_bip_p->bipr_cntx.recv_img_name);

    srv_bipr_notify_app(SRV_BIP_EVENT_RECV_NOTIFY, (void *)&recv_notify);

}



/*****************************************************************************
 * FUNCTION
 *  srv_bipr_complete_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipr_complete_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_complete_ind_struct *ind = (bt_bip_complete_ind_struct*) msg;
    srv_bip_recv_notify_struct recv_notify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIPR_COMPLETE_IND,srv_bip_p->bipr_cntx.state);

    if (ind->cm_conn_id == srv_bip_p->bipr_cntx.cm_conn_id)
    {
        if (srv_bip_p->bipr_cntx.state == SRV_BIPR_STATE_RECEIVING_IMG)
        {
            if (srv_bip_p->bipr_cntx.b_request_thm == MMI_FALSE)
            {
                srv_bip_p->bipr_cntx.cur_recv_img_num ++;
                recv_notify.type = SRV_BIP_RECV_SUCCESS;

                srv_bipr_notify_app(SRV_BIP_EVENT_RECV_NOTIFY, (void *) &recv_notify);
            }

            else
            {
                recv_notify.type = SRV_BIP_RECV_FAIL;
                recv_notify.u.err_code = MMI_BIP_PARTIAL_CONTENT;
                
                srv_bipr_notify_app(SRV_BIP_EVENT_RECV_NOTIFY, (void *)&recv_notify);
            }

        }  
        else if (srv_bip_p->bipr_cntx.state == SRV_BIPR_STATE_RECEIVING_THM)
        {
            srv_bip_p->bipr_cntx.cur_recv_img_num ++;
            recv_notify.type = SRV_BIP_RECV_SUCCESS;

            srv_bipr_notify_app(SRV_BIP_EVENT_RECV_NOTIFY, (void *) &recv_notify);
        }
        else
        {
            
        }
        
        MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_CONNECTED);
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_aborted_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipr_aborted_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_abort_ind_struct *ind = (bt_bip_abort_ind_struct*) msg;
    //U16 tmp_file[SRV_FMGR_PATH_MAX_LEN];
    mmi_bt_bip_error_enum bip_err;
    srv_bip_recv_notify_struct recv_notify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIPR_ABORT_IND,srv_bip_p->bipr_cntx.state);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    if(srv_bip_p->bipr_cntx.state >= SRV_BIPR_STATE_RECEIVING_IMG &&
        srv_bip_p->bipr_cntx.state < SRV_BIPR_STATE_DISCONNECTING)
    {
        MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_CONNECTED);
    }
    
    bip_err = srv_bip_convert_cnf_code_to_bip_err(ind->ind_code);

    recv_notify.type = SRV_BIP_RECV_FAIL;
    recv_notify.u.err_code = bip_err;
    
    srv_bipr_notify_app(SRV_BIP_EVENT_RECV_NOTIFY, (void *)&recv_notify);

}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_disconnect_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipr_disconnect_ind_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_deactivate_req_struct *req;
    //U16 tmp_file[SRV_FMGR_PATH_MAX_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIPR_DISCONNECT_IND,srv_bip_p->bipr_cntx.state);

    if (srv_bip_p->bipr_cntx.state == SRV_BIPR_STATE_IDLE)
    {
        return;
    }    

    switch (srv_bip_p->bipr_cntx.state)
    {
        case SRV_BIPR_STATE_DEACTIVATING:
            /* send DEACTIVATE_REQ to BT */
            req = (bt_bip_deactivate_req_struct*) OslConstructDataPtr(sizeof(bt_bip_deactivate_req_struct));
            BIP_MEMSET(req);
            req->req_id = BIP_CURR_REQ_ID;
            srv_bip_send_msg(MSG_ID_BT_BIP_DEACTIVATE_REQ, req);

            /* reset context */
            srv_bipr_connection_terminated();
            return;
            
            /* connected states */
        case SRV_BIPR_STATE_RECEIVING_IMG:
        case SRV_BIPR_STATE_RECEIVING_THM:
        #if 0
/* under construction !*/
/* under construction !*/
        #endif

        case SRV_BIPR_STATE_SENDING_IMG:
        case SRV_BIPR_STATE_SENDING_LPT:
        
            /* fall through */
        case SRV_BIPR_STATE_ACTIVE:
        case SRV_BIPR_STATE_CONNECTED:
        case SRV_BIPR_STATE_DISCONNECTING:
        case SRV_BIPR_STATE_AUTHORIZING:
        case SRV_BIPR_STATE_AUTHORIZED:
        case SRV_BIPR_STATE_CONSTRUCTING_IMGLIST:

            /* reset context */
            srv_bipr_connection_terminated();

            return;
    }

}



/*****************************************************************************
 * FUNCTION
 *  srv_bipr_send_authorize_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsp_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipr_send_authorize_rsp(U8 rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_authorize_rsp_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send response */
    res = (bt_bip_authorize_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_authorize_rsp_struct));
    BIP_MEMSET(res);    /* memory init */
    res->cnf_code = rsp_code;

    /* Send  primitive */
    srv_bip_send_msg(MSG_ID_BT_BIP_AUTHORIZE_RSP, res);

    if (rsp_code == BT_BIP_CNF_SUCCESS)
    {
        MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_AUTHORIZED);
    }
    else
    {
        MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_ACTIVE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bipr_send_connect_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsp_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipr_send_connect_rsp(U8 rsp_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_connect_rsp_struct *res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* send response */
    res = (bt_bip_connect_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_connect_rsp_struct));
    BIP_MEMSET(res);    /* memory init */
    res->cnf_code = rsp_code;
    res->cm_conn_id = srv_bip_p->bipr_cntx.cm_conn_id;

    /* Send  primitive */
    srv_bip_send_msg(MSG_ID_BT_BIP_CONNECT_RSP, res);

    if (rsp_code == BT_BIP_CNF_SUCCESS)
    {
        MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_CONNECTED);   
    }
    else
    {
        MMI_BIPR_STATE_TRANS(SRV_BIPR_STATE_ACTIVE);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_send_get_capabilities_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipr_send_get_capabilities_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_get_capabilities_rsp_struct *rsp;
    int i = 0;
    bt_bip_img_format_enum spt_img_formats[] = 
    {   BT_BIP_IMG_TYPE_JPEG,
        BT_BIP_IMG_TYPE_BMP,
        BT_BIP_IMG_TYPE_GIF,
        BT_BIP_IMG_TYPE_WBMP,
#ifdef GDI_USING_PNG    
        BT_BIP_IMG_TYPE_PNG,
#endif
        BT_BIP_IMG_TYPE_UNSUPPORT
    };
    U8 cnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_bip_get_capabilities_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_get_capabilities_rsp_struct));
    BIP_MEMSET(rsp);    /* memory init */
    rsp->cm_conn_id = srv_bip_p->bipr_cntx.cm_conn_id;

    cnt = sizeof(spt_img_formats) / sizeof(bt_bip_img_format_enum);
    for (i = 0; i < cnt; i++)
        rsp->supported_img_formats[i] = spt_img_formats[i];

        rsp->cnf_code = BT_BIP_CNF_SUCCESS;

    /* refer to Moto K3: it has no prefered-format */
    //rsp->preferred_format = BT_BIP_IMG_TYPE_JPEG;

    rsp->created_time_filter = KAL_FALSE;
    rsp->modified_time_filter = KAL_FALSE;
    rsp->encoding_filter = KAL_FALSE;
    rsp->pixel_filter = KAL_FALSE;

    srv_bip_send_msg(MSG_ID_BT_BIP_GET_CAPABILITIES_RSP, rsp);
}



/*****************************************************************************
 * FUNCTION
 *  srv_bipr_send_push_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cnf_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipr_send_push_rsp(U8 cnf_code, U16 *recv_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_put_img_rsp_struct *rsp;
    U8 tmp_str[12];
    U8 *dst;
    U32 len, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_bip_put_img_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_put_img_rsp_struct));
    BIP_MEMSET(rsp);    /* memory init */
    rsp->cm_conn_id = srv_bip_p->bipr_cntx.cm_conn_id;

    rsp->cnf_code = cnf_code;

    if (cnf_code == BT_BIP_CNF_SUCCESS || cnf_code == BT_BIP_PARTIAL_CONTENT)
    {
        /* img_path */
        mmi_wcscpy(rsp->img_path, recv_path);

        /* img_handle */
        strcpy((S8*) srv_bip_p->bipr_cntx.cur_img_handle, MMI_BIP_IMG_HANDLE_PREFIX);
        kal_sprintf((S8*) tmp_str, "%d", srv_bip_p->bipr_cntx.cur_recv_img_num);
        len = strlen((S8*) tmp_str);

        if (len < strlen(srv_bip_p->bipr_cntx.cur_img_handle))
        {
            dst =
                (U8*)(srv_bip_p->bipr_cntx.cur_img_handle +
                        strlen(srv_bip_p->bipr_cntx.cur_img_handle) - len);

            for (i = 0; i < len; i++)
            {
                *dst = tmp_str[i];
                dst++;
            }
        }
        strcpy((S8*) rsp->img_handle, (S8*) srv_bip_p->bipr_cntx.cur_img_handle);

    }

    if (cnf_code == BT_BIP_PARTIAL_CONTENT)
    {
        srv_bip_p->bipr_cntx.b_request_thm = MMI_TRUE;    
    }
    else
    {
        srv_bip_p->bipr_cntx.b_request_thm = MMI_FALSE;
        //SRVBIP_RESET_FLAG(SRVBIP_MASK_LAST_PKT);
    }

    srv_bip_send_msg(MSG_ID_BT_BIP_PUT_IMG_RSP, rsp);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_send_push_thm_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cnf_code        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipr_send_push_thm_rsp(U8 cnf_code, U16 *thm_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_put_linked_thumbnail_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_bip_put_linked_thumbnail_rsp_struct*) OslConstructDataPtr(sizeof(bt_bip_put_img_rsp_struct));
    BIP_MEMSET(rsp);    /* memory init */
    rsp->cm_conn_id = srv_bip_p->bipr_cntx.cm_conn_id;

    rsp->cnf_code = cnf_code;

    if (cnf_code == BT_BIP_CNF_SUCCESS)
    {
        mmi_wcscpy(rsp->img_path, thm_path);
    }
    
    srv_bip_send_msg(MSG_ID_BT_BIP_PUT_LINKED_THUMBNAIL_RSP, rsp);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_convert_cnf_code_to_bip_err
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cnf_code          [in]  cnf code from BIP adapter     
 * RETURNS
 *  bip error enum  
 *****************************************************************************/
static mmi_bt_bip_error_enum srv_bip_convert_cnf_code_to_bip_err(U8 cnf_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_bt_bip_error_enum bip_err;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(cnf_code)
    {
        case BT_BIP_CNF_SUCCESS:
            bip_err = MMI_BIP_SUCCESS;
            break;
            
        case BT_BIP_PARTIAL_CONTENT:
            bip_err = MMI_BIP_PARTIAL_CONTENT;
            break;
            
        case BT_BIP_DISK_FULL:
            bip_err = MMI_BIP_ERR_DISK_FULL;
            break;
            
        case BT_BIP_ROOT_DIR_FULL:
            bip_err = MMI_BIP_ERR_ROOT_DIR_FULL;
            break;
            
        case BT_BIP_CNF_FAILED:
            bip_err = MMI_BIP_ERR_LAST;
            break;
            
        case BT_BIP_XML_GEN_FAIL:
            bip_err = MMI_BIP_ERR_XML_GEN_FAIL;
            break;
            
        case BT_BIP_FILE_OPEN_FAIL:
            bip_err = MMI_BIP_ERR_FILE_OPEN_FAIL;
            break;
                
        case BT_BIP_FILE_READ_FAIL:
            bip_err = MMI_BIP_ERR_FILE_READ_FAIL;
            break;
            
        case BT_BIP_FILE_WRITE_FAIL:
            bip_err = MMI_BIP_ERR_FILE_WRITE_FAIL;
            break;
            
        case BT_BIP_FILE_MOVE_FAIL:
            bip_err = MMI_BIP_ERR_FILE_WRITE_FAIL;
            break;
            
        case BT_BIP_FS_MEDIA_CHANGED:
            bip_err = MMI_BIP_ERR_MEDIA_CHANGED;
            break;
            
        case BT_BIP_INVALID_PARM:
            bip_err = MMI_BIP_ERR_INVALID_PARAM;
            break;
            
        case BT_BIP_SCO_REJECT:
            bip_err = MMI_BIP_ERR_SCO_REJECT;
            break;

        case BT_BIP_BTCHIP_REJECT:
            bip_err = MMI_BIP_ERR_BTCHIP_REASON;
            break;
            
        case BT_BIP_XML_PARSE_FAIL:
            bip_err = MMI_BIP_ERR_XML_PARSE_FAIL;
            break;

        case BT_BIP_FS_QUOTA_FULL:
            bip_err = MMI_BIP_ERR_FSQUOTA_FULL;
            break;
            
        case BT_BIP_DISCONNECTED:
            bip_err = MMI_BIP_ERR_DISCONNECTED;
            break;
            
        case BT_BIP_FS_WRITE_PROTECTION:
            bip_err = MMI_BIP_ERR_FS_WRITE_PROTECTION;
            break;
            
        case BT_BIP_DRM_NO_RIGHTS:
            bip_err = MMI_BIP_ERR_DRM_NO_RIGHTS;
            break;

        case BT_BIP_FS_DEVICE_BUSY:
            bip_err = MMI_BIP_ERR_FS_DEVICE_BUSY;
            break;
            
        default:
            switch(cnf_code)
            {
                case GOEP_GONE:
                bip_err = MMI_BIP_ERR_SHAREDFOLDER_GONE;
                break;
                    
                case GOEP_NOT_FOUND:
                    bip_err = MMI_BIP_ERR_NOT_FOUND;
                    break;
                    
                case GOEP_FORBIDDEN:
                    bip_err = MMI_BIP_ERR_FORBIDDEN;
                    break;
                    
                case GOEP_SERVICE_UNAVAILABLE:
                    bip_err = MMI_BIP_ERR_SERVICE_UNAVAILABLE;
                    break;
                    
                case GOEP_REQUEST_TIME_OUT:
                    bip_err = MMI_BIP_ERR_REQUEST_TIME_OUT;
                    break;
                    
                case GOEP_METHOD_NOT_ALLOWED:
                    bip_err = MMI_BIP_ERR_METHOD_NOT_ALLOWED;
                    break;
                    
                case GOEP_NOT_ACCEPTABLE:
                    bip_err = MMI_BIP_ERR_NOT_ACCEPTABLE;
                    break;
                    
                case GOEP_UNSUPPORT_MEDIA_TYPE:
                    bip_err = MMI_BIP_ERR_UNSUPPORT_MEDIA_TYPE;
                    break;
                    
                case GOEP_INTERNAL_SERVER_ERR:
                    bip_err = MMI_BIP_ERR_INTERNAL_SERVER_ERR;
                    break;
                            
                case GOEP_REQ_URL_TOO_LARGE:
                    bip_err = MMI_BIP_ERR_REQ_URL_TOO_LARGE;
                    break;
                            
                case GOEP_CONFLICT:
                    bip_err = MMI_BIP_ERR_CONFLICT;
                    break;
                            

                default:
                    bip_err = MMI_BIP_ERR_LAST;
                    break;
            }
    }

    return bip_err;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipr_connection_terminated
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipr_connection_terminated(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bip_disconn_notify_struct disconn_notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIPR_CONNECTION_TERMINATED, srv_bip_p->bipr_cntx.state);

    //srv_bt_cm_disconnect_ind(srv_bip_p->bipr_cntx.conn_id);
    srv_bt_cm_stop_conn(srv_bip_p->bipr_cntx.conn_id);

    //disconn_notify.conn_id = srv_bip_p->bipr_cntx.cm_conn_id;
    disconn_notify.bt_addr = srv_bip_p->bipr_cntx.bt_device;

    srv_bipr_notify_app(SRV_BIP_EVENT_DISCONN_NOTIFY, (void *) &disconn_notify);
    /* reset members */
    srv_bip_p->bipr_cntx.state = SRV_BIPR_STATE_ACTIVE;
    //srv_bip_p->bipr_cntx.req_id = MMI_BIP_INVALID_REQ_ID;
    srv_bip_p->bipr_cntx.cm_conn_id = MMI_BIP_INVALID_CONN_ID;
    srv_bip_p->bipr_cntx.cur_recv_img_num = 0;
    srv_bip_p->bipr_cntx.conn_id = 0;

    //SRVBIP_RESET_FLAG(SRVBIP_MASK_LAST_PKT);

}



/*****************************************************************************
 * FUNCTION
 *  srv_bipi_notify_app
 * DESCRIPTION
 *  This function is to notify APP the happened event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bipr_notify_app(S32 event_id, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i = 0; i < SRV_BIP_MAX_SERVER_NUM; i++)
    {
        if (srv_bip_p->responder_hd[i].srv_hd >= SRV_BIP_REPONDER_HANDLE_BEGIN)
        {
            if (srv_bip_p->responder_hd[i].event_mask & event_id)
            {
                srv_bip_p->responder_hd[i].notifier(srv_bip_p->responder_hd[i].srv_hd, event_id, para);
            }
        }
    }
}

#define MMI_BIP_COMMON_FUNC
/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_get_inst_from_srv_hd
 * DESCRIPTION
 *  This function is to get inst from service handle
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_bip_handle_struct* srv_bip_get_inst_from_srv_hd(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bip_handle_struct *inst;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_hd <= 0)
        return NULL;
    
    if (srv_hd >= SRV_BIP_REPONDER_HANDLE_BEGIN)
    {
        inst = &srv_bip_p->responder_hd[srv_hd - SRV_BIP_REPONDER_HANDLE_BEGIN];
    }
    else
    {
        inst = &srv_bip_p->initiator_hd[srv_hd - 1];
    }
    return inst;
}



/*****************************************************************************
 * FUNCTION
 *  srv_opp_ntohs
 * DESCRIPTION
 *  This function is to convert s.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: received file counter.(?)
 *****************************************************************************/
static U16 srv_bip_ntohs(U16 s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (((s       & 0xFF) << 8) | \
           (((s >> 8) & 0xFF)));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_opp_gen_recv_path
 * DESCRIPTION
 *  This function is to truncate object name if exceeds max buffer size
 * PARAMETERS
 * new_name    [OUT]
 * old_name    [IN]
 * max_len     [IN]
 * RETURNS
 *  S32
 *****************************************************************************/
void srv_bip_truncate_obj_name(U16 *dst_name, U16 *src_name, U16 max_dst_len, MMI_BOOL convert_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 src_name_len;
    U16 *p_ext, *p1;
    U32 ext_len;
    U32 copy_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src_name == NULL)
    {
        mmi_wcscpy(dst_name, (U16*)BIP_SND_DEFAULT_OBJNAME);
    }
    else
    {
        if (convert_flag)
        {
            p1 = src_name;
        
            for(; *p1; p1++)
            {
                *p1 = srv_bip_ntohs(*p1);
            }
            *p1 = (U16)'\0';
        }

        
        src_name_len = mmi_wcslen(src_name);

        max_dst_len /= ENCODING_LENGTH;

        if (src_name_len < max_dst_len)
        {
            /* need not truncate */
            mmi_wcscpy(dst_name, src_name);   
        }
        else
        {
            /* need truncate */
            
            memset(dst_name, 0, max_dst_len * ENCODING_LENGTH);
            
            /* find filename ext */
            p_ext = (U16 *)mmi_wcsrchr(src_name, L'.');
            if(p_ext)
            {
                ext_len = mmi_wcslen(p_ext);

                if (ext_len > 5)
                {
                    p_ext[5] = L'\0';
                    ext_len = 5;
                }
            }
            else
            {
                ext_len = 0;
            }
            
            /* 1 char for '~'; 1 char for \0 */
            copy_len = max_dst_len - ext_len - 1 - 1 ;
            
            mmi_wcsncpy(dst_name, src_name, copy_len);
            mmi_wcscat(dst_name, (L"~"));
            if (p_ext)
            {
                mmi_wcscat(dst_name, p_ext);
            }
        }
    } 
}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_send_is_imagefile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  obj_name: object filename
 * RETURNS
 *   MMI_TRUE:  the object is BIP image file
 *   MMI_FALSE: the object is NOT BIP image file
 *****************************************************************************/
MMI_BOOL srv_bip_send_is_imagefile(void * obj_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *filename = (U16 *)obj_name;
    MMI_BOOL b_bip_imagefile = MMI_FALSE;
    bt_bip_img_format_enum img_format;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    

    SRV_BIP_LOG(SRV_BIP_CHECK_IS_IMAGE_FILE);
    SRV_BIP_LOG_PATH(filename);

    img_format = srv_bip_get_image_type(filename);

    if (img_format == BT_BIP_IMG_TYPE_UNSUPPORT)
    {
        SRV_BIP_LOG(SRV_BIP_SENDFILE_ISNOT_IMAGE);
        b_bip_imagefile = MMI_FALSE;
    }
    else
    {
        SRV_BIP_LOG(SRV_BIP_SENDFILE_IS_IMAGE);
        b_bip_imagefile = MMI_TRUE;
    }

    return b_bip_imagefile;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_get_image_type_from_postfix
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pathfileName       
 * RETURNS
 *  
 *****************************************************************************/
bt_bip_img_format_enum srv_bip_get_image_type_from_postfix(U16 *pathfileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_img_format_enum img_format = BT_BIP_IMG_TYPE_UNSUPPORT;
    applib_mime_type_struct *mime_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mime_type = applib_mime_get_file_type(pathfileName);
    if (mime_type == NULL)
    {
        SRV_BIP_LOG(SRV_BIP_MIME_NULL);
        goto RET;
    }

    SRV_BIP_LOG1(SRV_BIP_MIME_SUBTYPE, mime_type->mime_subtype);

    switch (mime_type->mime_subtype)
    {
        case MIME_SUBTYPE_GIF:
            img_format = BT_BIP_IMG_TYPE_GIF;
            break;
            
        case MIME_SUBTYPE_JPEG:
        case MIME_SUBTYPE_JPG:
            img_format = BT_BIP_IMG_TYPE_JPEG;
            break;
            
        case MIME_SUBTYPE_WBMP:
            img_format = BT_BIP_IMG_TYPE_WBMP;
            break;
            
        case MIME_SUBTYPE_PNG:
            img_format = BT_BIP_IMG_TYPE_PNG;
            break;
            
        case MIME_SUBTYPE_BMP:
        case MIME_SUBTYPE_BMP_1:
            img_format = BT_BIP_IMG_TYPE_BMP;
            break;
            
        default:
            break;
    }

RET:
    return img_format;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_get_image_type_from_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pathfileName       
 * RETURNS
 *  
 *****************************************************************************/
bt_bip_img_format_enum srv_bip_get_image_type_from_cntx(U16 *pathfileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_img_format_enum img_format = BT_BIP_IMG_TYPE_UNSUPPORT;
    U16 img_type = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    img_type = gdi_image_get_type_from_file((S8*)pathfileName);
    SRV_BIP_LOG1(SRV_BIP_GET_IMAGE_TYPE_FROM_CNTX, img_type)
        
    switch (img_type)
    {
        case GDI_IMAGE_TYPE_JPG_FILE:
            img_format = BT_BIP_IMG_TYPE_JPEG;
            break;
            
        case GDI_IMAGE_TYPE_PNG_FILE:
            img_format = BT_BIP_IMG_TYPE_PNG;
            break;
            
        case GDI_IMAGE_TYPE_BMP_FILE:
            img_format = BT_BIP_IMG_TYPE_BMP;
            break;
            
        case GDI_IMAGE_TYPE_WBMP_FILE:
            img_format = BT_BIP_IMG_TYPE_WBMP;
            break;
            
        case GDI_IMAGE_TYPE_GIF_FILE:
            img_format = BT_BIP_IMG_TYPE_GIF;
            break;
            
        default:
            break;
    }

    return img_format;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_get_image_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pathfileName       
 * RETURNS
 *  
 *****************************************************************************/
static bt_bip_img_format_enum srv_bip_get_image_type(U16 *pathfileName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bip_img_format_enum img_format = BT_BIP_IMG_TYPE_UNSUPPORT;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG(SRV_BIP_GET_IMGTYPE);
        
#ifdef GDI_USING_PNG    
    SRV_BIP_LOG(SRV_BIP_PNG_MACRO_DEFINED);
#else    

    SRV_BIP_LOG(SRV_BIP_PNG_MACRO_NOT_DEFINED);
#endif

    /* first check postfix */
    img_format = srv_bip_get_image_type_from_postfix(pathfileName);
    if (img_format != BT_BIP_IMG_TYPE_UNSUPPORT)
    {
        FS_HANDLE hFile;
        UINT fs_size;        
        int ret;

        hFile = FS_Open(pathfileName, FS_READ_ONLY);
        SRV_BIP_LOG2(SRV_BIP_FS_OPEN_RETURN, hFile, 29);
        
        ret = FS_GetFileSize(hFile, &fs_size);
        SRV_BIP_LOG2(SRV_BIP_FS_GETFILESIZE_RETRUN, ret, fs_size);
        
        ret = FS_Close(hFile);
        SRV_BIP_LOG1(SRV_BIP_FS_CLOSE_RETURN, ret);

        if (fs_size > 0)
        {
            /* then check content */
            img_format = srv_bip_get_image_type_from_cntx(pathfileName);
        }
    }

    SRV_BIP_LOG1(SRV_BIP_PUSH_GET_IMGTYPE_RETURN, img_format);
    return img_format;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bip_get_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pathFileName        [IN] 
 *  path                [OUT]
 *  name                [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bip_get_file_name(U16 *pathFileName, U16 *path, U16 *name, U16 name_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 PathLength = (U16) mmi_wcslen(pathFileName);
    U16 *UniPathName = pathFileName;
    U16 *p1 = NULL;
    U16 *p_ext;
    U16 NameLength = 0;
    U16 deter = L'\\';
    U32 ext_len, copy_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (PathLength > 0)
    {
        PathLength--;
        NameLength++;
        
        if (UniPathName[PathLength] == deter)
        {
            p1 = (U16 *)(UniPathName + PathLength + 1);
            break;
        }
    }
    
    if (name != NULL)
    {
        /* check name len */
        if (NameLength <= name_size )
        {
            mmi_wcscpy(name, p1);
        }
        else
        {
            p_ext = mmi_wcsrchr(p1, L'.');
            if(p_ext)
            {
                ext_len = mmi_wcslen(p_ext);

                if (ext_len > 5)
                {
                    p_ext[5] = L'\0';
                    ext_len = 5;
                }
            }
            else
            {
                ext_len = 0;
            }
            /*1 char for \0 */
            copy_len = name_size - ext_len - 1;
            
            /* name header*/
            mmi_wcsncpy(name, p1, copy_len);
            
            mmi_wcscat(name, p_ext);

        }
    }
    
    if (path != NULL)
    {
        mmi_wcsncpy(path, pathFileName, (PathLength + 1));
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bt_bip_get_dimension_for_thumbnail
 * DESCRIPTION
 *  Reture the image width and heigh, need compress in 160*120
 * PARAMETERS
 *  image_name        [IN]    image path name
 *  width            [IN]    the image width, compress in 160*120, and if the image
 *                            isn't out of the scale, reture the primary size
 *    height            [IN]    the image width, compress in 160*120, and if the image
 *                            isn't out of the scale, reture the primary size
 * RETURNS            [OUT]    Failed or Successed
 *  
 *****************************************************************************/
static U8 srv_bip_get_dimension_for_thumbnail(U16* image_name, S32 *width, S32 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT gdi_ret;
    S32 temp;
    S32 img_w, img_h;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    gdi_ret = gdi_image_get_dimension_file((S8 *)image_name, &img_w, &img_h);
    
    if (gdi_ret == GDI_SUCCEED)
    {
        SRV_BIP_LOG3(SRV_BIP_GDI_GET_DIMENSION, gdi_ret,img_w,img_h);
    
        if (img_w <= BT_BIP_THM_WIDTH && img_h <= BT_BIP_THM_HEIGHT)
        {
            *width = img_w;
            *height = img_h;
            return MMI_TRUE;
        }
        
        temp = img_h * BT_BIP_THM_WIDTH / img_w;

        if (temp < BT_BIP_THM_HEIGHT)
        {
            *width = BT_BIP_THM_WIDTH;
            *height = temp > 0 ? temp : 1;
        }
        else
        {
            *width = img_w * BT_BIP_THM_HEIGHT / img_h;
            *width = *width > 0 ? *width : 1;
            *height = BT_BIP_THM_HEIGHT;
        }

        SRV_BIP_LOG2(SRV_BIP_THM_DIMENSION, *width, *height);
        return MMI_TRUE;
    }
    else
    {
        SRV_BIP_LOG1(SRV_BIP_GET_DIMENSION_FAILED,gdi_ret);
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bipi__generate_thumbnail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_path        [IN]    
 *  thm_path        [IN]    
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_bip_generate_thumbnail(
                    U16 *img_path, 
                    U16 *thm_path, 
                    U16 thm_path_len, 
                    srv_bip_role_enum role )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buf_size = 0;
    U8 *buf_ptr = NULL;
    MMI_BOOL succ = MMI_FALSE;
    FS_HANDLE hFile;
    U32 file_size = 0;
    int ret;
    srv_bip_get_memory_notify_struct memory_notify;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG(SRV_BIP_GENERATE_THM);
    SRV_BIP_LOG_PATH(img_path);

    /* construct thm filename */
    srv_bip_construct_send_thm_path(img_path, thm_path, thm_path_len);                        

    SRV_BIP_LOG(SRV_BIP_THM_PATH);
    SRV_BIP_LOG_PATH(thm_path);

    /* check if the source image file is 0-byte */
    hFile = FS_Open((U16*) img_path, FS_READ_ONLY);
    if (hFile < 0)
    {
        SRV_BIP_LOG2(SRV_BIP_FS_OPEN_RETURN, hFile, 30);
        return MMI_FALSE;
    }
    
    ret = FS_GetFileSize(hFile, &file_size);
    SRV_BIP_LOG2(SRV_BIP_FS_GETFILESIZE_RETRUN, ret, file_size);
    ret = FS_Close(hFile);    

    if (file_size == 0)
    {
        /* Initiator: for 0-byte image, its thumbnail is 0-byte thumbnail */
        hFile = FS_Open((U16*) thm_path, FS_CREATE_ALWAYS);
        if (hFile < 0)
        {
            SRV_BIP_LOG2(SRV_BIP_FS_OPEN_ZERO_SIZE_RETURN_, hFile, 31);
            return MMI_FALSE;
        }
        FS_Close(hFile);
        return MMI_TRUE;
    }
    
    buf_size = (BT_BIP_THM_WIDTH * BT_BIP_THM_HEIGHT * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;
    buf_size = ((buf_size + 3) / 4) * 4;

    //get_memory_notify.type = SRV_BIP_SND_PARTIAL_CONTENT;
    if (buf_size == 0)
    {
        buf_size = 1;
    }
    
    memory_notify.buf_size = buf_size;

    buf_ptr = (U8 *)srv_bipi_notify_app(SRV_BIP_EVENT_GET_MEMORY_NOTIFY, (void *) &memory_notify);

    SRV_BIP_LOG1(SRV_BIP_ALLOC_APPLIBMEM, buf_size);
    
    //buf_ptr = applib_mem_ap_alloc_framebuffer(APPLIB_MEM_AP_ID_BT_BIP, buf_size);
    if (buf_ptr != NULL)
    {
        succ = srv_bip_encode_file_to_thumbnail(img_path, thm_path, buf_ptr, buf_size);

        memory_notify.buf_size = 0;
        srv_bipi_notify_app(SRV_BIP_EVENT_GET_MEMORY_NOTIFY, (void *) &memory_notify);
        //applib_mem_ap_free(buf_ptr);
    }
    else
    {
        SRV_BIP_LOG(SRV_BIP_APPLIBMEM_ALLOC_FAILED);
    }

    if (succ)
    {
        SRV_BIP_LOG(SRV_BIP_GDI_ENCODING_SUCCESS);
        return MMI_TRUE;
    }
    else
    {
        SRV_BIP_LOG(SRV_BIP_GDI_ENCODING_FAILED);
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_encode_file_to_thumbnail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pathFileName        [IN] 
 *  path                [OUT]
 *  name                [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_bip_encode_file_to_thumbnail(
            U16 *src_file_name,
            U16 *dest_file_name,
            U8 *buf_ptr,
            S32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle src_layer;
    MMI_BOOL b_thm_success;
    GDI_RESULT gdi_ret;
    S32 w = 0, h = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG(SRV_BIP_ENCODE_TO_THUMBNAIL);

    /* get thumbnail's dimension */
    b_thm_success = srv_bip_get_dimension_for_thumbnail(src_file_name, &w, &h);
    if (b_thm_success == MMI_FALSE)
    {
        SRV_BIP_LOG(SRV_BIP_GET_DIMENSION_FOR_THM_FAILED);
        return MMI_FALSE;
    }
    SRV_BIP_LOG2(SRV_BIP_THUMBNAIL_DIMENSION, w,h);
    
    gdi_image_set_encoding_flag(GDI_IMAGE_ENCODING_FLAG_JPEG_YUV_442);

    gdi_ret = gdi_layer_create_using_outside_memory(
        0,
        0,
        BT_BIP_THM_WIDTH,
        BT_BIP_THM_HEIGHT,
        &src_layer,
        (PU8) buf_ptr,
        (S32) buf_size);

    if (gdi_ret != GDI_SUCCEED)
    {
        SRV_BIP_LOG(SRV_BIP_CREATE_OUTSIDE_MEM_FAILED);
        return MMI_FALSE;
    }

    gdi_layer_push_and_set_active(src_layer);
    gdi_push_and_set_alpha_blending_source_layer(src_layer);
    gdi_layer_clear(GDI_COLOR_WHITE);

    b_thm_success = FALSE;
    
    gdi_image_jpeg_set_background_mode(KAL_TRUE);
    
    gdi_ret = gdi_image_draw_resized_file((BT_BIP_THM_WIDTH-w)/2, (BT_BIP_THM_HEIGHT-h)/2, w, h, src_file_name);
    if (gdi_ret == GDI_SUCCEED)
    {
        gdi_ret = gdi_image_encode_layer_to_jpeg(src_layer, (S8*)dest_file_name);
        if (gdi_ret == GDI_SUCCEED)
        {
            b_thm_success = MMI_TRUE;
        }
        else
        {
            SRV_BIP_LOG(SRV_BIP_ENCODE_TO_JPEG_FAILED);    
        }
    }
    else
    {
        SRV_BIP_LOG(SRV_BIP_DRAW_RESIZED_FILE_FAILED);
    }

    gdi_image_jpeg_set_background_mode(KAL_FALSE);

    gdi_layer_pop_and_restore_active();
    gdi_pop_and_restore_alpha_blending_source_layer();

    gdi_layer_free(src_layer);

    return b_thm_success;
}



/*****************************************************************************
 * FUNCTION
 *  srv_bip_construct_send_thm_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  img_path_file      
 *  dst_path           
 *  path_size            
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bip_construct_send_thm_path(U16 *img_path_file, U16 *thm_path, U16 path_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 img_name[BT_BIP_MAX_IMG_NAME_LEN];
    U16 name_len, left_len;
    U16 deter = L'.';

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG(SRV_BIP_CONSTRUCT_SEND_THM_PATH);
        
    mmi_wcscpy(thm_path, BIP_FOLDER_PATH);
    
    memset(img_name, 0, sizeof(img_name));

    srv_bip_get_file_name(img_path_file, (U16*) NULL, img_name, BT_BIP_MAX_IMG_NAME_LEN);
    
    name_len = mmi_wcslen(img_name);
    
    left_len = path_size - mmi_wcslen(thm_path);

    
    while (name_len > 0)
    {
        name_len--;
        if (*(img_name + name_len) == deter)
        {
            break;
        }
    }
    
    /* to be improved */
    ASSERT(left_len > 4 + 3 + 4);
    mmi_wcscat(thm_path, (U16 *) L"thm_");
    mmi_wcsncat(thm_path, img_name, name_len > 3 ? 3 : name_len);
    mmi_wcscat(thm_path, (U16 *) L".jpg");

    SRV_BIP_LOG_PATH(thm_path);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_gen_thm_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pathfileName       
 * RETURNS
 *  
 *****************************************************************************/
static void srv_bip_gen_thm_filename(U16 *img_name, S8 *img_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define THM_POSTFIX     L"_thm.jpg"
    
    //U16* img_name = srv_bip_p->bipr_cntx.recv_img_name; 
    U16 dst_thm_name[BIP_MAX_FILE_NAME_LEN];
    U16 *p_ext;
    U32 len, imgname_len, p_ext_len;
    //mmi_bt_bip_error_enum rst = MMI_BIP_SUCCESS;
    //S32 retval;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG(SRV_BIP_GEN_PUSHED_THM);
    SRV_BIP_LOG_PATH(img_name);

    /* construct pushed-in thm filename */

    imgname_len = mmi_wcslen(img_name);
    if (imgname_len > 0)
    {
        p_ext = mmi_wcsrchr(img_name, L'.');

        if (p_ext)
        {
            p_ext_len = mmi_wcslen(p_ext);
        }
        else
        {
            p_ext_len = 0;
        }

        len = imgname_len - p_ext_len;
        
        if (len + mmi_wcslen(THM_POSTFIX) >= BIP_MAX_FILE_NAME_LEN)
        {
           len = BIP_MAX_FILE_NAME_LEN - mmi_wcslen(THM_POSTFIX) - 1;
        }
        
        mmi_wcsncpy(dst_thm_name, img_name, len);
        
    }
    else
    {
        //mmi_asc_to_ucs2((S8*) dst_thm_name, (S8*) srv_bip_p->bipr_cntx.cur_img_handle);
        mmi_asc_to_ucs2((S8*) dst_thm_name, (S8*) img_handle);
    }

    mmi_wcscat(dst_thm_name, (U16 *) THM_POSTFIX);
    SRV_BIP_LOG(SRV_BIP_RENAME_PUSHED_THM_DST_NAME);
    SRV_BIP_LOG_PATH(dst_thm_name);

    /* rename the filename */
    mmi_wcscpy(srv_bip_p->bipr_cntx.recv_img_name,  dst_thm_name);

    
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
#endif

}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_send_msg
 * DESCRIPTION
 *  This function is to send msg to BT task
 * PARAMETERS
 *  msg_id              [IN]        
 *  p_local_para        [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bip_send_msg(U32 msg_id, void *p_local_para)
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
    ilm_send->dest_mod_id = MOD_BT;
    ilm_send->sap_id = BT_BIP_SAP;
    ilm_send->msg_id = (U16) msg_id;
    ilm_send->local_para_ptr = (local_para_struct*) p_local_para;
    ilm_send->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_send);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bip_is_receiving
 * DESCRIPTION
 *  This function is to get current status of bip server and initiator.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS:
 *  MMI_TRUE: is working
 *  MMI_FALSE: idle
 *****************************************************************************/
MMI_BOOL srv_bip_is_receiving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_bip_p->bipr_cntx.state == SRV_BIPR_STATE_RECEIVING_IMG 
        || srv_bip_p->bipr_cntx.state == SRV_BIPR_STATE_RECEIVING_THM 
        || srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_GETTING_IMG
        || srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_GETTING_THM)
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
 *  srv_bip_is_run
 * DESCRIPTION
 *  This function is to check that if changing storage is allowed.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS:
 *  MMI_TRUE: allowed
 *  MMI_FALSE: not allowed
 *****************************************************************************/
MMI_BOOL srv_bip_is_run(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_allowed = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* image push check responder state */
    if (srv_bip_p->bipr_cntx.state >= SRV_BIPR_STATE_AUTHORIZED)
    {
        is_allowed = MMI_FALSE;
    }
    /* image pull check initiator state*/
    else if (srv_bip_p->bipi_cntx.state >= SRV_BIPI_STATE_CONNECTING
            &&srv_bip_p->bipi_cntx.state <= SRV_BIPI_STATE_DISCONNECTING)
    {
        is_allowed = MMI_FALSE;
    }

    return is_allowed;
}



/*****************************************************************************
 * FUNCTION
 *  srv_bipi_is_sending
 * DESCRIPTION
 *  This function is to get current action.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS: 
 *
 *****************************************************************************/
MMI_BOOL srv_bipi_is_sending(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIP_PUSH_IS_SENDING,srv_bip_p->bipi_cntx.state);
    
    if ((SRV_BIPI_STATE_CONNECTING == srv_bip_p->bipi_cntx.state) || 
        (SRV_BIPI_STATE_CONNECTED == srv_bip_p->bipi_cntx.state) || 
        (SRV_BIPI_STATE_SENDING_IMG == srv_bip_p->bipi_cntx.state) || 
        (SRV_BIPI_STATE_SENDING_THM == srv_bip_p->bipi_cntx.state) ||
        (SRV_BIPI_STATE_GETTING_CAPABILITIES == srv_bip_p->bipi_cntx.state))
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
 *  srv_bip_client_is_idle
 * DESCRIPTION
 *  check if BIP initiator is idle
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE: idle
 *  FALSE: busy
 *****************************************************************************/
MMI_BOOL srv_bipi_is_idle(void)
{
    BOOL b_idle = MMI_FALSE;

    SRV_BIP_LOG1(SRV_BIP_CHECK_INIT_STATE,srv_bip_p->bipi_cntx.state);

    if (srv_bip_p->bipi_cntx.state == SRV_BIPI_STATE_IDLE)
    {
        b_idle = MMI_TRUE;
    }
    
    return b_idle;
}




/*****************************************************************************
 * FUNCTION
 *  srv_bip_server_is_working
 * DESCRIPTION
 *  This function is to get current status of bip server.
 *  
 *  PARAMETERS: void
 *  void
 *  RETURNS:
 *  MMI_TRUE: is working
 *  MMI_FALSE: idle
 *****************************************************************************/
MMI_BOOL srv_bipr_is_working(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BIP_LOG1(SRV_BIP_SERVER_IS_WORKING, srv_bip_p->bipr_cntx.state);

    switch (srv_bip_p->bipr_cntx.state)
    {
        case SRV_BIPR_STATE_AUTHORIZING:
        case SRV_BIPR_STATE_AUTHORIZED:
        case SRV_BIPR_STATE_CONNECTED:
        case SRV_BIPR_STATE_RECEIVING_IMG:
        case SRV_BIPR_STATE_RECEIVING_THM:
        case SRV_BIPR_STATE_SENDING_IMG:
        case SRV_BIPR_STATE_SENDING_LPT:
        case SRV_BIPR_STATE_CONSTRUCTING_IMGLIST:
        case SRV_BIPR_STATE_DISCONNECTING:
            return MMI_TRUE;
    
        default:
            return MMI_FALSE;
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


#endif /* defined(__MMI_BIP_SUPPORT__) */ 

#endif /* __MMI_BT_MTK_SUPPORT__ */ 

