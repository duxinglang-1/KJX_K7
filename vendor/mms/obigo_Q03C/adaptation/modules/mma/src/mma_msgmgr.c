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
 * mma_msgmgr.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains some functions used by MMA to sync with FLDR
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMA_MSGMGR_C
#define _MMA_MSGMGR_C
#if defined(MMS_SUPPORT)
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" 
#include "stack_ltlcom.h"
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "custom_wap_config.h"

#include "MMI_features.h"
#include "MMIDataType.h"
#include "Unicodexdcl.h"
#include "GlobalResDef.h"

#include "mma_struct.h"
#include "mmc_struct.h"
#include "mms_adp_struct.h"
#include "mms_sap_struct.h"
#include "mma_api.h"
#include "wapadp.h"
#include "mmsadp.h"
#include "conversions.h"
#include "mmi_frm_gprot.h"
#include "WguiCategoryGprot.h"
#include "PhoneBookGprot.h"
/* APPLIB */
#include "app_str.h"
#include "app_mine.h"
/* MSF */
#include "msf_lib.h"    /* MSF: ANSI Standard libs allowed to use */
#include "msf_cfg.h"    /* MSF: Module definition */
#include "msf_def.h"    /* MSF: Global definitions */
#include "msf_core.h"   /* MSF: System core call */
#include "msf_dcvt.h"   /* MSF: Type conversion routines */
#include "msf_chrs.h"   /* MSF: character API */
#include "msf_mem.h"    /* MSF: Memory handling */
#include "msf_log.h"    /* MSF: Signal logging */
#include "msf_cmmn.h"   /* MSF: MSF common functions, e.g. string handling */
#include "msf_pipe.h"   /* MSF: Pipe handling */
#include "msf_file.h"   /* MSF: File handling */
#include "msf_errc.h"
#include "msm.h"

/* MMS */
#include "mms_cfg.h"    /* MMS: Configuration definitions */
#include "mms_def.h"    /* MMS: Exported types in adapter/connector functions */
#include "mms_if.h"     /* MMS: Exported signal interface */
#include "mltypes.h"
#include "mlfetch.h"
#include "mmsl_if.h"
/* ashok added */
#include "mcpdu.h"
#include "mms_def.h"
#include "mms_aApp.h"

/* SLS */
#include "mma_smil.h"
//#include "sls_cfg.h"
//#include "sls_def.h"
//#include "sls_if.h"

/* fldr */
#include "msig.h"       /* dependency file for the fldmgr.h */
#include "fldmgr.h"
#include "UmSrvGprot.h"
#include "UmSrvStruct.h"
#include "UmSrvDefs.h"


/* MMA */
#include "mma_cfg.h"
#include "mma_def.h"
#include "mma_env.h"
#include "mma_main.h"
#include "mma_interface.h"
#include "mma_utilities.h"
#include "mma_msgmgr.h"
#include "mma_sendrecv.h"
#include "mma_msg_struct.h"
#include "mma_event.h"
#include "mma_create.h"
#include "GlobalDefs.h"
#include "wgui_categories_util.h"
#include "mmi_rp_srv_mms_def.h"
#ifndef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_app_sms_def.h"
#endif	/* __COSMOS_MMI_PACKAGE__ */
#include "MmsSrvGprot.h"   /* for mms sending/downloading status */
#include "mma_parse.h"
#include "mma_setting.h"

#define MMS_SYS_FOLDER "/mms_sys/"
static mma_msgmgr_context_strcut g_mma_msgmgr_cntx;
extern mma_setting_context_struct g_mma_setting_cntx;
static void mma_msgmgr_save_req_hdlr(module_type source, wap_mma_save_req_struct *save_req);
//static void mma_msgmgr_mms_delete_ind_hdlr(MmsResult result, kal_uint32 msg_id);
void mma_msgmgr_mms_delete_ind_hdlr(MmsResult result, kal_uint32 msg_id);
//static void mma_msgmgr_update_mms_folder_status(mma_msg_info_list_struct *msg_list, BOOL is_update, kal_uint8 old_folder, kal_uint8 new_folder);
static kal_bool mma_msgmgr_check_busy_state_pending_list(
                    module_type source,
                    mma_int_sig_type_enum sig,
                    void *pending_msg_struct);
static MSF_BOOL mma_msgmgr_free_msg_notif_data(mma_msgmgr_recv_notif_data_struct *notif_data);
static void mma_msgmgr_update_addr_objects_info_req_hdlr(kal_uint32 msg_id, mmsAddrObjectInfo *data);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
static void mma_msgmgr_update_mms_thumbnail_info_req_hdlr(kal_uint32 msg_id, mmsBodyObjectInfo *data);
static void mma_msgmgr_get_mms_attr_and_thumbnail_req_hdlr(module_type source, wap_mma_get_mms_thumbnail_and_attr_info_req_struct *mms_attr_tbm_req);
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
#ifdef __COSMOS_MMI_PACKAGE__
static kal_uint32 mma_msgmgr_get_mms_msg_status(kal_uint32 msg_id);
#endif

#if defined (__MMI_MMS_GROUP_MSG__) || defined (__MMI_OP12_MMS_GROUP_MSG_SUPPORT__)
#define MMA_INT_TO_STRING_CONV_RADIX 10
#endif


extern kal_uint32 mma_mms_get_msg_file_size(kal_uint32 msg_id);

#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  translate_um_simid_to_mma_simid
 * DESCRIPTION
 *  This function is used to convert MMS SIM ENUM value to UM ENUMSIN value
 * CALLS
 *  
 * PARAMETERS
 *  version     [IN]        
 *  prio(?)
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 translate_um_simid_to_mma_simid(kal_uint32 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 mma_sim_id = MMA_SIM_ID_SIM_UNCLASSIFIED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(sim_id & SRV_UM_SIM_UNCLASSIFIED)
	{
		mma_sim_id |= MMA_SIM_ID_SIM_UNCLASSIFIED;
	}
    if(sim_id & SRV_UM_SIM_GSM_SIM1)
	{
		mma_sim_id |= MMA_SIM_ID_SIM1;
	}
    if(sim_id & SRV_UM_SIM_GSM_SIM2)
	{
		mma_sim_id |= MMA_SIM_ID_SIM2;
	}
#if (MMI_MAX_SIM_NUM >= 4)
    if(sim_id & SRV_UM_SIM_GSM_SIM4)
    {
        mma_sim_id |= MMA_SIM_ID_SIM4;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 3)
     if(sim_id & SRV_UM_SIM_GSM_SIM3)
    {
        mma_sim_id |= MMA_SIM_ID_SIM3;
    }
#endif
     if((sim_id & SRV_UM_SIM_GSM_SIM1) && (sim_id & SRV_UM_SIM_UNCLASSIFIED) && (sim_id & SRV_UM_SIM_GSM_SIM2)
 #if (MMI_MAX_SIM_NUM >= 4)
        && (sim_id & SRV_UM_SIM_GSM_SIM4)
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        && (sim_id & SRV_UM_SIM_GSM_SIM3)
#endif
        )
	{
		mma_sim_id = MMA_SIM_ID_TOTAL;
	}
    return mma_sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  translate_mma_simid_to_um_simid
 * DESCRIPTION
 *  This function is used to convert MMS SIM ENUM value to UM ENUMS value
 * CALLS
 *  
 * PARAMETERS
 *  version     [IN]        
 *  prio(?)
 * RETURNS
 *  
 *****************************************************************************/
srv_um_sim_enum translate_mma_simid_to_um_simid(kal_uint8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {
        case MMA_SIM_ID_SIM_UNCLASSIFIED:
            return SRV_UM_SIM_UNCLASSIFIED;
	    case MMA_SIM_ID_SIM1:
            return SRV_UM_SIM_GSM_SIM1;
        case MMA_SIM_ID_SIM2:
            return SRV_UM_SIM_GSM_SIM2;
    #if (MMI_MAX_SIM_NUM >= 4)
        case MMA_SIM_ID_SIM4:
            return SRV_UM_SIM_GSM_SIM4;
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMA_SIM_ID_SIM3:
                return SRV_UM_SIM_GSM_SIM3;
    #endif
        case MMA_SIM_ID_TOTAL:
            return SRV_UM_SIM_ALL;
        default:
            return SRV_UM_SIM_UNCLASSIFIED; 
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_index_from_sim_id
 * DESCRIPTION
 *  This function is used to convert MMS SIM ENUM value to array index  
 * PARAMETERS
 *  sim_id     [IN]
 * RETURNS
 *  index of array
 *****************************************************************************/
 int mma_msgmgr_get_index_from_sim_id(mma_sim_id_enum sim_id)
 {
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {
        case MMA_SIM_ID_SIM_UNCLASSIFIED:
            return MMA_INDEX_FOR_SIM_UNCLASSIFIED;
	    case MMA_SIM_ID_SIM1:
            return MMA_INDEX_FOR_SIM1;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMA_SIM_ID_SIM2:
            return MMA_INDEX_FOR_SIM2;
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMA_SIM_ID_SIM3:
            return MMA_INDEX_FOR_SIM3;
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        case MMA_SIM_ID_SIM4:
            return MMA_INDEX_FOR_SIM4;
    #endif
        default:
            return MMA_INDEX_FOR_SIM1; 
    }
}


#ifndef __COSMOS_MMI_PACKAGE__
#ifdef __MMI_ULTRA_SLIM_MMS_2__
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_create_img_id
 * DESCRIPTION
 *  This function is used to create the image ID of the icon.
 * PARAMETERS
 *  property_st              [IN]        
 *  large_data_st                [IN]
  * RETURNS
 *  kal_uint16
 *****************************************************************************/
kal_uint16 mma_msgmgr_create_img_id( mms_msg_info_property_struct *property_st, mms_msg_info_large_data_struct *large_data_st)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (property_st->suffix) 
    {
        case MMS_SUFFIX_MSG:
        case MMS_SUFFIX_READREPORT:
        case MMS_SUFFIX_DELIVERYREPORT:
        {
            if(property_st->is_read)
            {
#ifndef __MMI_SMS_BOX_ICON_SLIM__ 
                return (kal_uint16) MMA_IMG_LETTER_READ;
#else 
#ifndef __COSMOS_MMI_PACKAGE__
				return (kal_uint16) IMG_MESSAGE_READ;
#else		
				return 0;
#endif	/* __COSMOS_MMI_PACKAGE__ */
#endif	/* __MMI_SMS_BOX_ICON_SLIM__ */
            }
            else
            {
#ifndef __MMI_SMS_BOX_ICON_SLIM__ 
                return (kal_uint16) MMA_IMG_LETTER;
#else 
#ifndef __COSMOS_MMI_PACKAGE__
				return (kal_uint16) IMG_MESSAGE_UNREAD;
#else	
				return 0;
#endif	/* __COSMOS_MMI_PACKAGE__ */
#endif	/* __MMI_SMS_BOX_ICON_SLIM__ */
            }
        }
        /* Messages in the Template folder has its own icon  */
        case MMS_SUFFIX_TEMPLATE:   /* MMA_IMG_TEMPLATE */
        case MMS_SUFFIX_SEND_REQ:
        {
#ifndef __MMI_SMS_BOX_ICON_SLIM__ 
                return (kal_uint16) MMA_IMG_LETTER_CREATED;
#else 
#ifndef __COSMOS_MMI_PACKAGE__
				return (kal_uint16) IMG_MESSAGE_READ;
#else	
				return 0;
#endif	/* __COSMOS_MMI_PACKAGE__ */
#endif	/* __MMI_SMS_BOX_ICON_SLIM__ */
        }
        case MMS_SUFFIX_NOTIFICATION:
        case MMS_SUFFIX_IMMEDIATE:
        {
			return MMA_IMG_NOTIF;			
        }
        default:
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MMA, MMA_MSGMGR_CREATE_IMG_ID_FILE_SUFFIX,
                             "(%s) (%d) createListItemImg suffix state (%d)\n", __FILE__, __LINE__, suffix));
            break;
    }
    return 0;
}

#else
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_create_img_id
 * DESCRIPTION
 *  This function is used to create the image ID of the icon.
 * PARAMETERS
 *  suffix              [IN]        
 *  read                [IN]        
 *  forwardlock         [IN]        
 *  prio                [IN]        
 *  isJSR               [IN]        
 *  has_attachment      [IN]        
 *  is_in_lock_mode     [IN]        
 *  is_corrupted        [IN]        
 *  forwardLock(?)      [IN]        
 * RETURNS
 *  kal_uint16       [OUT]
 *****************************************************************************/
kal_uint16 mma_msgmgr_create_img_id( mms_msg_info_property_struct *property_st, mms_msg_info_large_data_struct *large_data_st)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_POSTCARD__
	if(property_st->msg_type == MMA_MSG_TYPE_POSTCARD)
	{
		return (kal_uint16)MMA_IMG_POSTCARD_MMS;
	}
#endif /* __MMI_MMS_POSTCARD__ */
    switch (property_st->suffix) 
    {
        case MMS_SUFFIX_MSG:
        {
            if (property_st->msg_type == MMA_MSG_TYPE_JAVA)
            {
				return (kal_uint16)MMA_IMG_LETTER_JAVA;
            }
            break;
        }
        default:
            break;
    }
    
    if(property_st->suffix == MMS_SUFFIX_MSG)
    {
        switch (property_st->msg_media_type)
        {
            case MMA_MEDIA_MSG_AUDIO:
            {
    #if defined (__MMI_OP11_MMS_SUPPORT_AUDIO_MSG__) || defined (__MMI_MMS_VOICE_MESSAGE_HANDLING__)
                if (property_st->is_read)
                {
    #ifdef __MMI_MMS_GROUP_MSG__
                    if (property_st->num_of_recipient > 1)
                    {
                        switch (property_st->priority)
                        {
                            case MMA_PRIORITY_HIGH:
                                return (kal_uint16)MMA_IMG_GROUP_AUDIO_READ_PRIO_HIGH;
                            case MMA_PRIORITY_LOW:
                                return (kal_uint16)MMA_IMG_GROUP_AUDIO_READ_PRIO_LOW;
                            case MMA_PRIORITY_MEDIUM:
                            case MMA_PRIORITY_NOT_SET:
                            default:
                                return (kal_uint16)MMA_IMG_GROUP_AUDIO_READ;
                        }
                    }
    #endif
                    switch (property_st->priority)
                    {
                        case MMA_PRIORITY_HIGH:
                            return (kal_uint16)MMA_IMG_AUDIO_READ_PRIO_HIGH;
                        case MMA_PRIORITY_LOW:
                            return (kal_uint16)MMA_IMG_AUDIO_READ_PRIO_LOW;
                        case MMA_PRIORITY_MEDIUM:
                        case MMA_PRIORITY_NOT_SET:
                        default:
                            return (kal_uint16)MMA_IMG_AUDIO_READ;
                    }
                    break;
                }
                else
                {
    #ifdef __MMI_MMS_GROUP_MSG__
                    if (property_st->num_of_recipient > 1)
                    {
                        switch (property_st->priority)
                        {
                            case MMA_PRIORITY_HIGH:
                                return (kal_uint16)MMA_IMG_GROUP_AUDIO_PRIO_HIGH;
                            case MMA_PRIORITY_LOW:
                                return (kal_uint16)MMA_IMG_GROUP_AUDIO_PRIO_LOW;
                            case MMA_PRIORITY_MEDIUM:
                            case MMA_PRIORITY_NOT_SET:
                            default:
                                return (kal_uint16)MMA_IMG_GROUP_AUDIO;
                        }
                    }
    #endif
				    switch (property_st->priority)
                    {
                        case MMA_PRIORITY_HIGH:
                            return (kal_uint16)MMA_IMG_AUDIO_PRIO_HIGH;
                        case MMA_PRIORITY_LOW:
                            return (kal_uint16)MMA_IMG_AUDIO_PRIO_LOW;
                        case MMA_PRIORITY_MEDIUM:
                        case MMA_PRIORITY_NOT_SET:
                        default:
                            return (kal_uint16)MMA_IMG_AUDIO;
                    }
                    break;
                }
    #endif /* __MMI_OP11_MMS_SUPPORT_AUDIO_MSG__ */
                break;
            }
            case MMA_MEDIA_MSG_PHOTO:
            {
    #ifdef __MMI_OP11_MMS_SUPPORT_PHOTO_MSG__
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_MMS_GROUP_MSG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_MMS_GROUP_MSG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_OP11_MMS_SUPPORT_PHOTO_MSG__ */
                break;
            }
            case MMA_MEDIA_MSG_VIDEO:
            {
    #ifdef __MMI_OP11_MMS_SUPPORT_VIDEO_MSG__
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_MMS_GROUP_MSG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_MMS_GROUP_MSG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_OP11_MMS_SUPPORT_VIDEO_MSG__ */
                break;
            }
            case MMA_MEDIA_MSG_NONE:
            case MMA_MEDIA_MSG_TEXT:
            default:
			{
    #ifdef __MMI_MMS_GROUP_MSG__
				if ((property_st->num_of_recipient > 1) && (property_st->is_read))
				{
					switch (property_st->priority)
					{
						case MMA_PRIORITY_HIGH:
							return (kal_uint16)MMA_IMG_GROUP_READ_PRIO_HIGH;

						case MMA_PRIORITY_LOW:
							return (kal_uint16)MMA_IMG_GROUP_READ_PRIO_LOW;

						case MMA_PRIORITY_MEDIUM:
						case MMA_PRIORITY_NOT_SET:
						default:
							return (kal_uint16)MMA_IMG_GROUP_READ;
					}
				}
				else if (property_st->num_of_recipient > 1)
				{
					switch (property_st->priority)
					{
						case MMA_PRIORITY_HIGH:
							return (kal_uint16)MMA_IMG_GROUP_PRIO_HIGH;
                                
						case MMA_PRIORITY_LOW:
							return (kal_uint16)MMA_IMG_GROUP_PRIO_LOW;

						case MMA_PRIORITY_MEDIUM:
						case MMA_PRIORITY_NOT_SET:
						default:
							return (kal_uint16)MMA_IMG_GROUP;
					}
				}
    #endif
				break;
			}
        }
    }
    
    switch (property_st->suffix)
    {
        case MMS_SUFFIX_MSG:
        {
            if (large_data_st->app_data[MMA_MSGMGR_CORRUPT_MMS_POS] > 0)
            {
                return (kal_uint16) MMA_IMG_CORRUPT;
            }
            /* case of java MMS is already handled above */
		#ifndef __MMI_SLIM_MMS_2__
            if (property_st->is_forward_lock && property_st->has_attachment && property_st->is_read)
            {
                switch (property_st->priority)
                {
                    case MMA_PRIORITY_HIGH:
                        return (kal_uint16) MMA_IMG_FORWARD_LOCK_ATTACHMENT_READ_PRIO_HIGH;

                    case MMA_PRIORITY_LOW:
                        return (kal_uint16) MMA_IMG_FORWARD_LOCK_ATTACHMENT_READ_PRIO_LOW;

                    case MMA_PRIORITY_MEDIUM:
                    case MMA_PRIORITY_NOT_SET:
                    default:
                        return (kal_uint16) MMA_IMG_FORWARD_LOCK_ATTACHMENT_READ;
                };
            }
            else if (property_st->is_forward_lock && property_st->has_attachment && !property_st->is_read)
            {
                switch (property_st->priority)
                {
                    case MMA_PRIORITY_HIGH:
                        return (kal_uint16) MMA_IMG_FORWARD_LOCK_ATTACHMENT_PRIO_HIGH;

                    case MMA_PRIORITY_LOW:
                        return (kal_uint16) MMA_IMG_FORWARD_LOCK_ATTACHMENT_PRIO_LOW;

                    case MMA_PRIORITY_MEDIUM:
                    case MMA_PRIORITY_NOT_SET:
                    default:
                        return (kal_uint16) MMA_IMG_FORWARD_LOCK_ATTACHMENT;
                };
            }
            else if (!property_st->is_forward_lock && property_st->has_attachment && property_st->is_read)
            {
                switch (property_st->priority)
                {
                    case MMA_PRIORITY_HIGH:
                        return (kal_uint16) MMA_IMG_ATTACHMENT_READ_PRIO_HIGH;

                    case MMA_PRIORITY_LOW:
                        return (kal_uint16) MMA_IMG_ATTACHMENT_READ_PRIO_LOW;

                    case MMA_PRIORITY_MEDIUM:
                    case MMA_PRIORITY_NOT_SET:
                    default:
                        return (kal_uint16) MMA_IMG_ATTACHMENT_READ;
                };
            }
            else if (!property_st->is_forward_lock && property_st->has_attachment && !property_st->is_read)
            {
                switch (property_st->priority)
                {
                    case MMA_PRIORITY_HIGH:
                        return (kal_uint16) MMA_IMG_ATTACHMENT_PRIO_HIGH;

                    case MMA_PRIORITY_LOW:
                        return (kal_uint16) MMA_IMG_ATTACHMENT_PRIO_LOW;

                    case MMA_PRIORITY_MEDIUM:
                    case MMA_PRIORITY_NOT_SET:
                    default:
                        return (kal_uint16) MMA_IMG_ATTACHMENT;
                };
            }
            else 
      #endif  /* __MMI_SLIM_MMS_2__ */
            if (property_st->is_forward_lock && property_st->is_read)
            {
                switch (property_st->priority)
                {
                    case MMA_PRIORITY_HIGH:
                        return (kal_uint16) MMA_IMG_FORWARD_LOCK_READ_PRIO_HIGH;

                    case MMA_PRIORITY_LOW:
                        return (kal_uint16) MMA_IMG_FORWARD_LOCK_READ_PRIO_LOW;

                    case MMA_PRIORITY_MEDIUM:
                    case MMA_PRIORITY_NOT_SET:
                    default:
                        return (kal_uint16) MMA_IMG_FORWARD_LOCK_READ;
                };
            }
            else if (property_st->is_forward_lock && !property_st->is_read)
            {
                switch (property_st->priority)
                {
                    case MMA_PRIORITY_HIGH:
                        return (kal_uint16) MMA_IMG_FORWARD_LOCK_PRIO_HIGH;

                    case MMA_PRIORITY_LOW:
                        return (kal_uint16) MMA_IMG_FORWARD_LOCK_PRIO_LOW;

                    case MMA_PRIORITY_MEDIUM:
                    case MMA_PRIORITY_NOT_SET:
                    default:
                        return (kal_uint16) MMA_IMG_FORWARD_LOCK;
                };
            }
            else if (!property_st->is_forward_lock && property_st->is_read)
            {
                switch (property_st->priority)
                {
                    case MMA_PRIORITY_HIGH:
                        return (kal_uint16) MMA_IMG_LETTER_READ_PRIO_HIGH;

                    case MMA_PRIORITY_LOW:
                        return (kal_uint16) MMA_IMG_LETTER_READ_PRIO_LOW;

                    case MMA_PRIORITY_MEDIUM:
                    case MMA_PRIORITY_NOT_SET:
                    default:
#ifndef __MMI_SMS_BOX_ICON_SLIM__ 
                        return (kal_uint16) MMA_IMG_LETTER_READ;
#else 
#ifndef __COSMOS_MMI_PACKAGE__
						return (kal_uint16) IMG_MESSAGE_READ;
#else
						return 0;
#endif	/* __COSMOS_MMI_PACKAGE__ */
#endif	/* __MMI_SMS_BOX_ICON_SLIM__ */
                      
                };
            }
            else /* (!property_st->is_forward_lock && !property_st->is_read) */
            {
                switch (property_st->priority)
                {
                    case MMA_PRIORITY_HIGH:
                        return (kal_uint16) MMA_IMG_LETTER_PRIO_HIGH;

                    case MMA_PRIORITY_LOW:
                        return (kal_uint16) MMA_IMG_LETTER_PRIO_LOW;

                    case MMA_PRIORITY_MEDIUM:
                    case MMA_PRIORITY_NOT_SET:
                    default:
#ifndef __MMI_SMS_BOX_ICON_SLIM__ 
                        return (kal_uint16) MMA_IMG_LETTER;
#else 
#ifndef __COSMOS_MMI_PACKAGE__
				return (kal_uint16) IMG_MESSAGE_UNREAD;
#else
						return 0;
#endif	/* __COSMOS_MMI_PACKAGE__ */
#endif	/* __MMI_SMS_BOX_ICON_SLIM__ */
                };
            }
           
        }
            /* Messages in the Template folder has its own icon  */
        case MMS_SUFFIX_TEMPLATE:   /* MMA_IMG_TEMPLATE */
        case MMS_SUFFIX_SEND_REQ:
        {
            /* no need to handle for Dual Sim case */
            /* case of java MMS is already handled above */
			/* no need to handle the draft message in Dual Sim case */
#ifndef __MMI_SMS_BOX_ICON_SLIM__ 
                return (kal_uint16) MMA_IMG_LETTER_CREATED;
#else 
#ifndef __COSMOS_MMI_PACKAGE__
				return (kal_uint16) IMG_MESSAGE_READ;
#else
						return 0;
#endif	/* __COSMOS_MMI_PACKAGE__ */
#endif	/* __MMI_SMS_BOX_ICON_SLIM__ */
        }
        case MMS_SUFFIX_NOTIFICATION:
        case MMS_SUFFIX_IMMEDIATE:
        {
            if (large_data_st->app_data[MMA_MSGMGR_CORRUPT_MMS_POS] > 0)
            {
                return (kal_uint16) MMA_IMG_CORRUPT;
            }
			switch (property_st->priority)
            {
                case MMA_PRIORITY_HIGH:
                    return (kal_uint16) MMA_IMG_NOTIF_PRIO_HIGH;

                case MMA_PRIORITY_LOW:
                    return (kal_uint16) MMA_IMG_NOTIF_PRIO_LOW;

                case MMA_PRIORITY_MEDIUM:
                case MMA_PRIORITY_NOT_SET:
                default:
					return MMA_IMG_NOTIF;
            };			
        }
    #ifndef __MMI_MMS_REPORT_STATUS_SUPPORT__
        case MMS_SUFFIX_READREPORT:
        {
			return (kal_uint16) ((property_st->is_read) ? (MMA_IMG_RR_READ) : (MMA_IMG_RR));
        }
        case MMS_SUFFIX_DELIVERYREPORT:
        {
			return (kal_uint16) ((property_st->is_read) ? (MMA_IMG_DR_READ) : (MMA_IMG_DR));
        }
    #endif /* __MMI_MMS_REPORT_STATUS_SUPPORT__ */
        default:
            MSF_LOG_MSG_OFF((MSF_LOG_DETAIL_HIGH, MSF_MODID_MMA, MMA_MSGMGR_CREATE_IMG_ID_FILE_SUFFIX,
                             "(%s) (%d) createListItemImg suffix state (%d)\n", __FILE__, __LINE__, suffix));
            return 0;
    }
}
#endif   /* __MMI_ULTRA_SLIM_MMS_2__ */
#endif   /* __COSMOS_MMI_PACKAGE__ */


#ifdef __COSMOS_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_mms_msg_status
 * DESCRIPTION
 *  This function is used to get the mms icon state status. This status is used by UMMS SRV to provide MMS icon to UM  
 * PARAMETERS
 *  msg_id     [IN]
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 mma_msgmgr_get_mms_msg_status(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info = NULL;
    kal_uint32 msg_status = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Put hack to get the msg Status of mms in FTO. UM will improve the method in future */
    /* Current flow, UM will give this status to UMMS Service. UMMS Service will provide the MMS Icon based on this status */
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    if(msg_info->folder == MMA_FOLDER_OUTBOX)
    {
        msg_status = srv_mms_bgsr_get_msg_status(msg_id);
        /* Print log to get the BGSR status */
        if(msg_status == SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND)
        {
            msg_status = MMA_MSG_ICON_STATUS_WAITING_FOR_SEND;
        }
        else if (msg_status == SRV_MMS_BGSR_STATUS_SENDING)
        {
            msg_status = MMA_MSG_ICON_STATUS_SENDING;
        }
        else if((msg_status == SRV_MMS_BGSR_STATUS_SEND_FAIL) || (msg_status == SRV_MMS_BGSR_STATUS_DEFERRED_FOR_SEND))
        {
            msg_status = MMA_MSG_ICON_STATUS_SEND_FAIL;
        }
		else if((msg_status == SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND) || (msg_status == SRV_MMS_BGSR_STATUS_SEND_SIM_UNAVAILABLE))
        {
            msg_status = MMA_MSG_ICON_STATUS_POSTPONE_FOR_SEND;
        }
    }
    else
    {
        switch (msg_info->suffix) 
        {
            case MMS_SUFFIX_MSG:
                if (msg_info->mms_msg_type == MMA_MSG_TYPE_JAVA)
                {
	                msg_status = MMA_MSG_ICON_STATUS_JAVA_MMS;
                }
                else
                {
                    switch (msg_info->mms_priority)
                    {
                        case MMA_PRIORITY_HIGH:
                            msg_status = MMA_MSG_ICON_STATUS_PRIO_HIGH_MMS;
                            break;
                        case MMA_PRIORITY_LOW:
                            msg_status = MMA_MSG_ICON_STATUS_PRIO_LOW_MMS;
                            break;
                        case MMA_PRIORITY_MEDIUM:
                        case MMA_PRIORITY_NOT_SET:
                        default:
                            msg_status = MMA_MSG_ICON_STATUS_PRIO_MED_MMS;
                            break;
                    }
                }
                break;
            case MMS_SUFFIX_READREPORT:
                msg_status = MMA_MSG_ICON_STATUS_RR_MMS;
                break;
            case MMS_SUFFIX_DELIVERYREPORT:
                msg_status = MMA_MSG_ICON_STATUS_DR_MMS;
                break;
            case MMS_SUFFIX_NOTIFICATION:
                msg_status = MMA_MSG_ICON_STATUS_NOTIFICATION_MMS;
                break;
            default:
                msg_status = MMA_MSG_ICON_STATUS_DRAFT_MMS;
                break;
        }
    }
    return msg_status;
}
#endif /* #ifdef __COSMOS_MMI_PACKAGE__ */


#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_translate_report_status_to_string
 * DESCRIPTION
 *  This function is used to convert report status to string  
 * PARAMETERS
 *  report_type
 *  status     [IN]
 * RETURNS
 *  kal_wchar*
 *****************************************************************************/
kal_wchar* mma_translate_report_status_to_string(kal_uint8 report_type, kal_uint8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(report_type == MMS_STATUS_IS_DR)
    {
        switch (status)
        {
            case MMA_DR_STATUS_PENDING:
                return get_string(STR_ID_UMMS_STATUS_PENDING);    
	        case MMA_DR_STATUS_EXPIRED:
                return get_string(STR_ID_UMMS_STATUS_EXPIRED);
            case MMA_DR_STATUS_RETRIEVED:
                return get_string(STR_ID_UMMS_STATUS_DELIVERED);
            case MMA_DR_STATUS_REJECTED:
                return get_string(STR_ID_UMMS_STATUS_REJECTED);
            case MMA_DR_STATUS_DEFERRED:
                return get_string(STR_ID_UMMS_STATUS_DEFERRED);
            case MMA_DR_STATUS_UNRECOGNISED:
                return get_string(STR_ID_UMMS_STATUS_UNRECOGNIZED);
            case MMA_DR_STATUS_INDETERMINATE:
                return get_string(STR_ID_UMMS_STATUS_INTERMEDIATE);
            case MMA_DR_STATUS_FORWARDED:
                return get_string(STR_ID_UMMS_STATUS_FORWARDED);
            default:
                return get_string(STR_ID_UMMS_STATUS_UNREACHABLE);
        }
    }
    else
    {
        switch (status)
        {
            case MMA_RR_STATUS_PENDING:
                return get_string(STR_ID_UMMS_STATUS_PENDING);    
	        case MMA_RR_STATUS_READ:
                return get_string(STR_ID_UMMS_STATUS_READ);
            case MMA_RR_STATUS_DELETED_NO_READ:
                return get_string(STR_ID_UMMS_STATUS_DELETED_WITHOUT_READ);
            default:
                return get_string(STR_ID_UMMS_STATUS_READ);
        }
    }
}
#endif  /* __MMI_MMS_REPORT_BOX_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_check_msg_exist
 * DESCRIPTION
 *  This function is used to check if the msg file is still avaliable
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mma_msgmgr_check_msg_exist(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    char *filename = MMAlib_getMessagePath(MSF_MODID_MMA, msg_id);

    if(filename)
    {
        if (MSF_FILE_GETSIZE_EXT(filename, mma_get_mms_type_message_storage(msg_id)) <= 0)
        {
            MMA_FREE(filename);
            return KAL_FALSE;
        }
        else
        {
            MMA_FREE(filename);
            return KAL_TRUE;
        }
    }
    else
    {
        return KAL_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_send_int_perform_msg_oper_ind
 * DESCRIPTION
 *  This function is used to send the MMA_INT_SIG_TYPE_MSG_CONTINUE_MSG_OPER signal to internal queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_msgmgr_send_int_perform_msg_oper_ind()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_msgmgr_cntx.is_cnt_msg_oper_sent == FALSE)
    {
        /* Process pending request */
        MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_MSG_CONTINUE_MSG_OPER);
        g_mma_msgmgr_cntx.is_cnt_msg_oper_sent = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_send_int_notify_ind
 * DESCRIPTION
 *  This function is used to send the MMA_INT_SIG_TYPE_NOFITY signal to internal queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_msgmgr_send_int_notify_ind()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_msgmgr_cntx.is_notify_sig_sent == FALSE)
    {
        MMA_SIGNAL_SENDTO(MMA_SUBMODULE_MSG_MGR, MMA_INT_SIG_TYPE_NOTIFY);
        g_mma_msgmgr_cntx.is_notify_sig_sent = TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_execute_pending_req_hdlr
 * DESCRIPTION
 *  This function is used to execute the pending operations.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_execute_pending_req_hdlr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_signal_struct *sig_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mma_msgmgr_cntx.is_notify_sig_sent = FALSE;

    if (g_mma_msgmgr_cntx.pending_req_list != NULL)
    {
        if (MMA_MSGMGR_GET_STATE() == MMA_MSGMGR_STATE_READY)
        {
            sig_p = mma_get_int_sig(&(g_mma_msgmgr_cntx.pending_req_list));
            mma_msgmgr_process_int_sig(sig_p);
            mma_delete_int_sig(sig_p);
        }
        else
        {
            mma_signal_struct *tmp = NULL;
            kal_uint32 count = 0;

            tmp = g_mma_msgmgr_cntx.pending_req_list;
            while (tmp)
            {
                count++;
                tmp = tmp->next;
            }
            tmp = g_mma_msgmgr_cntx.pending_req_list;
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_EXEC_PENDING_REQ_TYPE_COUNT,
                              "MmaMsgMgrPR:%d,%d", (int)tmp->type, count));
        }
    }
    if (MMA_MSGMGR_GET_STATE() == MMA_MSGMGR_STATE_READY && g_mma_msgmgr_cntx.pending_req_list != NULL)
    {
#if (defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_MMS_TEMPLATE_SUPPORT__))
        if(mms_is_default_templates_ready())
		{
#endif
			mma_msgmgr_send_int_notify_ind();
#if (defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_MMS_TEMPLATE_SUPPORT__))
		}
#endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_terminate_ind_hdlr
 * DESCRIPTION
 *  This function is used to terminate the msgmgr.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_msgmgr_terminate_ind_hdlr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mma_msg_info_list_struct *msg_list_p = g_mma_msgmgr_cntx.msg_list;
    mma_msgmgr_msg_id_list_struct *unread_msg_list = g_mma_msgmgr_cntx.unread_msg_list;
    mma_msgmgr_msg_id_list_struct *recent_event_list = g_mma_msgmgr_cntx.recent_event_list;
    mma_msgmgr_recv_notif_data_struct *notif_data = g_mma_msgmgr_cntx.notif_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* no need to check for the MSGMGR_STATE_READY or PENDING. Simply free the context */
    while (msg_list_p != NULL)
    {
        mma_msg_info_list_struct *temp = msg_list_p;
        msg_list_p = msg_list_p->next;
        MMA_FREE(temp);
		temp = NULL;
    }
    while(unread_msg_list != NULL)
    {
        mma_msgmgr_msg_id_list_struct *temp = unread_msg_list;
        unread_msg_list = unread_msg_list->next;
        MMA_FREE(temp);
		temp = NULL;
    }
    while(recent_event_list != NULL)
    {
        mma_msgmgr_msg_id_list_struct *temp = recent_event_list;
        recent_event_list = recent_event_list->next;
        MMA_FREE(temp);
		temp = NULL;
    }
    while(notif_data != NULL)
    {
        mma_msgmgr_recv_notif_data_struct *temp = notif_data;
        notif_data = notif_data->next;
        mma_msgmgr_free_msg_notif_data(temp);
		temp = NULL;
    }
    memset(&g_mma_msgmgr_cntx, 0x00, sizeof(mma_msgmgr_context_strcut));
    MMAc_kill();
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_set_state
 * DESCRIPTION
 *  This function is used to set the state in the msgmmgr context.
 * PARAMETERS
 *  state       [IN]        
 *  line_no     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_msgmgr_set_state(kal_uint32 state, int line_no)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                      MMA_MSGMGR_SET_STATE_TO_NEW_STATE,
                      "Mma msgmgr state is changed from %d to %d in line %d", g_mma_msgmgr_cntx.state, state, line_no));
    g_mma_msgmgr_cntx.state = state;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_new_msg_info_by_req_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mma_msgmgr_new_msg_info_struct *mma_msgmgr_get_new_msg_info_by_req_id(MSF_UINT32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msgmgr_new_msg_info_struct *new_msg_info = g_mma_msgmgr_cntx.new_msg_req_queue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_msg_info == NULL)
    {
        return NULL;
    }
    while (new_msg_info)
    {
        if (new_msg_info->req_id == req_id)
        {
            return new_msg_info;
        }
        new_msg_info = new_msg_info->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_new_msg_info_by_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mma_msgmgr_new_msg_info_struct *mma_msgmgr_get_new_msg_info_by_msg_id(MSF_UINT32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msgmgr_new_msg_info_struct *new_msg_info = g_mma_msgmgr_cntx.new_msg_req_queue;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_msg_info == NULL)
    {
        return NULL;
    }
    while (new_msg_info)
    {
        if (new_msg_info->msg_id == msg_id)
        {
            return new_msg_info;
        }
        new_msg_info = new_msg_info->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_add_new_msg_info_to_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_info        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static MSF_BOOL mma_msgmgr_add_new_msg_info_to_list(mma_msgmgr_new_msg_info_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_info == NULL)
    {
        return FALSE;
    }
    if (msg_info->next != NULL)
    {
        ASSERT(0);
    }
    if (g_mma_msgmgr_cntx.new_msg_req_queue == NULL)
    {
        g_mma_msgmgr_cntx.new_msg_req_queue = msg_info;
    }
    else
    {
        mma_msgmgr_new_msg_info_struct *tmp = g_mma_msgmgr_cntx.new_msg_req_queue;

        while (tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = msg_info;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_remove_new_msg_info_from_list
 * DESCRIPTION
 *  The function is used to
 * PARAMETERS
 *  req_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mma_msgmgr_new_msg_info_struct *mma_msgmgr_remove_new_msg_info_from_list(MSF_UINT32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msgmgr_new_msg_info_struct *result = NULL;
    mma_msgmgr_new_msg_info_struct *list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_msgmgr_cntx.new_msg_req_queue == NULL)
    {
        return NULL;
    }
    else if (g_mma_msgmgr_cntx.new_msg_req_queue->req_id == req_id)
    {
        result = g_mma_msgmgr_cntx.new_msg_req_queue;
        g_mma_msgmgr_cntx.new_msg_req_queue = g_mma_msgmgr_cntx.new_msg_req_queue->next;
        result->next = NULL;
        return result;
    }
    else
    {
        list_p = g_mma_msgmgr_cntx.new_msg_req_queue;
        while (list_p->next != NULL)
        {
            if (list_p->next->req_id == req_id)
            {
                result = list_p->next;
                list_p->next = list_p->next->next;
                result->next = NULL;
                return result;
            }
            list_p = list_p->next;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_msg_info_by_idx
 * DESCRIPTION
 *  This function is used to get the message list from the index of a folder.
 * PARAMETERS
 *  folder      [IN]        
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_msg_info_list_struct *mma_msgmgr_get_msg_info_by_idx(kal_uint32 folder, kal_uint32 index, kal_uint8 sim_id)
{
    /* Use Mutex!!!!!!!!!!!! */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_list_p = g_mma_msgmgr_cntx.msg_list;
    kal_uint32 curr_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list_p == NULL)
    {
        return NULL;
    }
    while (msg_list_p)
    {
        if (msg_list_p->user_can_not_see == FALSE)
        {
            if (msg_list_p->folder == (mma_folder_enum) folder)
            {
            #if (MMI_MAX_SIM_NUM >= 2)
				if(msg_list_p->msg_sim_id & sim_id)
				{
			#endif
                if (curr_idx == index)
                {
                    return msg_list_p;
                }
                curr_idx++;
            #if (MMI_MAX_SIM_NUM >= 2)
				}
			#endif
            }
        }
        msg_list_p = msg_list_p->next;
    }
    /* Ashok to Do: Write the code for the next cache list */
    return NULL;
    /* Use Mutex!!!!!!!!!!!! */
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_template_msg_info_by_idx
 * DESCRIPTION
 *  This function is used to get the template message list from the index.
 * PARAMETERS
 *  index      [IN]        
 *  sim_id       [IN]        
 * RETURNS
 *  mma_msg_info_list_struct*
 *****************************************************************************/
mma_msg_info_list_struct *mma_msgmgr_get_template_msg_info_by_idx(kal_uint32 index, kal_uint8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_list_p = g_mma_msgmgr_cntx.msg_list;
    kal_uint32 curr_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list_p == NULL)
    {
        return NULL;
    }
    while (msg_list_p)
    {
        if ((msg_list_p->user_can_not_see == FALSE) && 
            ((msg_list_p->folder == MMA_FOLDER_TEMPLATE) || (msg_list_p->folder == MMA_FOLDER_USRDEF_TEMPLATE)))
        {
        #if (MMI_MAX_SIM_NUM >= 2)
			if(msg_list_p->msg_sim_id & sim_id)
			{
		#endif
            if (curr_idx == index)
            {
                return msg_list_p;
            }
            curr_idx++;
        #if (MMI_MAX_SIM_NUM >= 2)
			}
		#endif
        }
        msg_list_p = msg_list_p->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_add_msg_notif_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  notif_data        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static MSF_BOOL mma_msgmgr_add_msg_notif_data(mma_msgmgr_recv_notif_data_struct *notif_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (notif_data == NULL)
    {
        return FALSE;
    }
    if (notif_data->next != NULL)
    {
        ASSERT(0);
    }
    if(g_mma_msgmgr_cntx.notif_data == NULL)
    {
        g_mma_msgmgr_cntx.notif_data = notif_data;
    }
    else
    {
        mma_msgmgr_recv_notif_data_struct *tmp = g_mma_msgmgr_cntx.notif_data;
        while(tmp->next)
        {
            tmp = tmp->next;
        }
        tmp->next = notif_data;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_remove_msg_notif_data
 * DESCRIPTION
 *  The function is used to
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mma_msgmgr_recv_notif_data_struct *mma_msgmgr_remove_msg_notif_data(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msgmgr_recv_notif_data_struct *result = NULL;
    mma_msgmgr_recv_notif_data_struct *list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_msgmgr_cntx.notif_data == NULL)
    {
        return NULL;
    }
    else if (g_mma_msgmgr_cntx.notif_data->data->notifId == msg_id)
    {
        result = g_mma_msgmgr_cntx.notif_data;
        g_mma_msgmgr_cntx.notif_data = g_mma_msgmgr_cntx.notif_data->next;
        result->next = NULL;
        return result;
    }
    else
    {
        list_p = g_mma_msgmgr_cntx.notif_data;
        while (list_p->next != NULL)
        {
            if (list_p->next->data->notifId == msg_id)
            {
                result = list_p->next;
                list_p->next = list_p->next->next;
                result->next = NULL;
                return result;
            }
            list_p = list_p->next;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_remove_msg_notif_data
 * DESCRIPTION
 *  The function is used to
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MSF_BOOL mma_msgmgr_free_msg_notif_data(mma_msgmgr_recv_notif_data_struct *notif_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (notif_data == NULL)
    {
        return FALSE;
    }
    else
    {
        if(notif_data->data && notif_data->data->subjectText)
        {
            MMA_FREE(notif_data->data->subjectText);
        }
        if(notif_data->data && notif_data->data->fromAddress)
        {
            MMA_FREE(notif_data->data->fromAddress);
        }
        if(notif_data->data)
        {
            MMA_FREE(notif_data->data);
        }
        MMA_FREE(notif_data);        
    }
    return FALSE;
}

#if defined (__MMI_OP11_HOMESCREEN__) || defined (__MMI_OP12_TOOLBAR__) || defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_add_new_msg_to_unread_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_info        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static MSF_BOOL mma_msgmgr_add_new_msg_to_unread_list(kal_uint32 msg_id, kal_uint32 date, kal_uint8 suffix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_id == 0)
    {
        return FALSE;
    }
    if (g_mma_msgmgr_cntx.unread_msg_list == NULL)
    {
        g_mma_msgmgr_cntx.unread_msg_list = (mma_msgmgr_msg_id_list_struct*) MMA_CALLOC(sizeof(mma_msgmgr_msg_id_list_struct));
        g_mma_msgmgr_cntx.unread_msg_list->msg_id = msg_id;
        g_mma_msgmgr_cntx.unread_msg_list->suffix = suffix;
        g_mma_msgmgr_cntx.unread_msg_list->date = date;
        g_mma_msgmgr_cntx.unread_msg_list->next = NULL;
    }
    else
    {
        mma_msgmgr_msg_id_list_struct *tmp = g_mma_msgmgr_cntx.unread_msg_list;
        mma_msgmgr_msg_id_list_struct *new_msg = (mma_msgmgr_msg_id_list_struct*) MMA_CALLOC(sizeof(mma_msgmgr_msg_id_list_struct));
        new_msg->msg_id = msg_id;
        new_msg->suffix = suffix;
        new_msg->date = date;
        new_msg->next = NULL;
        /* insert the new node based on the timestamp */
        if(tmp->date <= new_msg->date)
        {
            new_msg->next = tmp;
            g_mma_msgmgr_cntx.unread_msg_list = new_msg;
            return KAL_TRUE;
        }
        while (tmp->next)
        {
            if(tmp->next->date <= new_msg->date)
            {
                new_msg->next = tmp->next;
                tmp->next = new_msg;
                return KAL_TRUE;
            }
            tmp = tmp->next;
        }
        tmp->next = new_msg;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_remove_msg_from_unread_list
 * DESCRIPTION
 *  The function is used to
 * PARAMETERS
 *  req_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MSF_BOOL mma_msgmgr_remove_msg_from_unread_list(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msgmgr_msg_id_list_struct *result = NULL;
    mma_msgmgr_msg_id_list_struct *list_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_msgmgr_cntx.unread_msg_list == NULL)
    {
        return FALSE;
    }
    else if (g_mma_msgmgr_cntx.unread_msg_list->msg_id == msg_id)
    {
        result = g_mma_msgmgr_cntx.unread_msg_list;
        g_mma_msgmgr_cntx.unread_msg_list = g_mma_msgmgr_cntx.unread_msg_list->next;
        result->next = NULL;
        MMA_FREE(result);
        return TRUE;
    }
    else
    {
        list_p = g_mma_msgmgr_cntx.unread_msg_list;
        while (list_p->next != NULL)
        {
            if (list_p->next->msg_id == msg_id)
            {
                result = list_p->next;
                list_p->next = list_p->next->next;
                result->next = NULL;
                MMA_FREE(result);
                return TRUE;
            }
            list_p = list_p->next;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_unread_msg_id_by_idx
 * DESCRIPTION
 *  This function is used to get unread msg info according to index in INBOX.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  msg_id
 *****************************************************************************/
static kal_uint32 mma_msgmgr_get_unread_msg_id_by_idx(kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msgmgr_msg_id_list_struct *msg_id_list_p = g_mma_msgmgr_cntx.unread_msg_list;
    MSF_UINT32 curr_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_id_list_p == NULL)
    {
        return NULL;
    }
    while (msg_id_list_p)
    {
        if (curr_idx == index)
        {
            return msg_id_list_p->msg_id;
        }
        curr_idx++;
        msg_id_list_p = msg_id_list_p->next;
    }
    /* Ashok to Do: Write the code for the next cache list */
    return NULL;
}
#endif

#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_add_msg_to_recent_evt_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_info        [IN]     
 * RETURNS
 *  
 *****************************************************************************/
static MSF_BOOL mma_msgmgr_add_msg_to_recent_evt_list(kal_uint32 msg_id, kal_uint32 date, kal_uint8 suffix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_id == 0)
    {
        return FALSE;
    }
    if (g_mma_msgmgr_cntx.recent_event_list == NULL)
    {
        g_mma_msgmgr_cntx.recent_event_list = (mma_msgmgr_msg_id_list_struct*) MMA_CALLOC(sizeof(mma_msgmgr_msg_id_list_struct));
        g_mma_msgmgr_cntx.recent_event_list->msg_id = msg_id;
        g_mma_msgmgr_cntx.recent_event_list->suffix = suffix;
        g_mma_msgmgr_cntx.recent_event_list->date = date;
        g_mma_msgmgr_cntx.recent_event_list->next = NULL;
        g_mma_msgmgr_cntx.mms_folder_status.recent_event_number = 1;
    }
    else
    {
        mma_msgmgr_msg_id_list_struct *tmp = g_mma_msgmgr_cntx.recent_event_list;
        mma_msgmgr_msg_id_list_struct *new_msg = (mma_msgmgr_msg_id_list_struct*) MMA_CALLOC(sizeof(mma_msgmgr_msg_id_list_struct));
        new_msg->msg_id = msg_id;
        new_msg->suffix = suffix;
        new_msg->date = date;
        new_msg->next = NULL;
        /* insert the new node based on the timestamp */
        if(tmp->date <= new_msg->date)
        {
            new_msg->next = tmp;
            g_mma_msgmgr_cntx.recent_event_list = new_msg;
            g_mma_msgmgr_cntx.mms_folder_status.recent_event_number++;
            return KAL_TRUE;
        }
        while (tmp->next)
        {
            if(tmp->next->date <= new_msg->date)
            {
                new_msg->next = tmp->next;
                tmp->next = new_msg;
                g_mma_msgmgr_cntx.mms_folder_status.recent_event_number++;
                return KAL_TRUE;
            }
            tmp = tmp->next;
        }
        tmp->next = new_msg;
        g_mma_msgmgr_cntx.mms_folder_status.recent_event_number++;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_remove_msg_from_recent_evt_list
 * DESCRIPTION
 *  The function is used to
 * PARAMETERS
 *  req_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MSF_BOOL mma_msgmgr_remove_msg_from_recent_evt_list(kal_uint32 msg_id, MSF_BOOL is_update )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msgmgr_msg_id_list_struct *result = NULL;
    mma_msgmgr_msg_id_list_struct *list_p = NULL;
    mma_result_enum ret = MMA_RESULT_OK;
    mms_msg_info_property_struct *property_st = NULL;                   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_msgmgr_cntx.recent_event_list == NULL)
    {
        return FALSE;
    }
    else if(msg_id == 0xFFFFFFFF)
    {
        list_p = g_mma_msgmgr_cntx.recent_event_list;
        while (list_p != NULL)
        {
            result = list_p;
            list_p = list_p->next;
            if(is_update)
            {
                property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));
                ASSERT(property_st);
                ret = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(result->msg_id),
                                    (kal_uint8)mma_get_mms_type_message_storage(result->msg_id),
                                    property_st, NULL));
			    if ((ret == MMA_RESULT_OK) && (property_st->reserve_space == MMA_MSGMGR_IS_RECENT_EVT))
                {
                    property_st->reserve_space = MMA_MSGMGR_UNSET_RECENT_EVT; 
                    ret = translate_mms_result_to_mma(MMSlib_UpdateChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(result->msg_id),
                                result->suffix, (kal_uint8)mma_get_mms_type_message_storage(result->msg_id),
                                property_st, NULL));
				    //memset(property_st, 0x00, sizeof(mms_msg_info_property_struct));
                }
                MMA_FREE(property_st);
                property_st = NULL;
            }
            MMA_FREE(result);
            result = NULL;
        }
        g_mma_msgmgr_cntx.recent_event_list = NULL;
        g_mma_msgmgr_cntx.mms_folder_status.recent_event_number = 0;
        return TRUE;
    }
    else if (g_mma_msgmgr_cntx.recent_event_list->msg_id == msg_id)
    {
        result = g_mma_msgmgr_cntx.recent_event_list;
        g_mma_msgmgr_cntx.recent_event_list = g_mma_msgmgr_cntx.recent_event_list->next;
        if(is_update)
        {
            property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));
            ASSERT(property_st);
            ret = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(result->msg_id),
                                    (kal_uint8)mma_get_mms_type_message_storage(result->msg_id),
                                    property_st, NULL));
		    if ((ret == MMA_RESULT_OK) && (property_st->reserve_space == MMA_MSGMGR_IS_RECENT_EVT))
            {
                property_st->reserve_space = MMA_MSGMGR_UNSET_RECENT_EVT;
                ret = translate_mms_result_to_mma(MMSlib_UpdateChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(result->msg_id),
                            result->suffix, (kal_uint8)mma_get_mms_type_message_storage(result->msg_id),
                            property_st, NULL));
            }
            MMA_FREE(property_st);
        }
        MMA_FREE(result);
        g_mma_msgmgr_cntx.mms_folder_status.recent_event_number--;
        return TRUE;
    }
    else
    {
        list_p = g_mma_msgmgr_cntx.recent_event_list;
        while (list_p->next != NULL)
        {
            if (list_p->next->msg_id == msg_id)
            {
                result = list_p->next;
                list_p->next = list_p->next->next;
                if(is_update)
                {
                    property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));
                    ASSERT(property_st);
                    ret = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(result->msg_id),
                                    (kal_uint8)mma_get_mms_type_message_storage(result->msg_id),
                                    property_st, NULL));
		            if ((ret == MMA_RESULT_OK) && (property_st->reserve_space == MMA_MSGMGR_IS_RECENT_EVT))
                    {
                        property_st->reserve_space = MMA_MSGMGR_UNSET_RECENT_EVT;
                        ret = translate_mms_result_to_mma(MMSlib_UpdateChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(result->msg_id),
                                    result->suffix, (kal_uint8)mma_get_mms_type_message_storage(result->msg_id),
                                    property_st, NULL));
                    }
                    MMA_FREE(property_st);
                    property_st = NULL;
                }
                MMA_FREE(result);
                result = NULL;
                g_mma_msgmgr_cntx.mms_folder_status.recent_event_number--;
                return TRUE;
            }
            list_p = list_p->next;
        }
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_recent_evt_msg_id_by_idx
 * DESCRIPTION
 *  This function is used to get unread msg info according to index in INBOX.
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  msg_id
 *****************************************************************************/
static kal_uint32 mma_msgmgr_get_recent_evt_msg_id_by_idx(kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msgmgr_msg_id_list_struct *msg_id_list_p = g_mma_msgmgr_cntx.recent_event_list;
    MSF_UINT32 curr_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_id_list_p == NULL)
    {
        return NULL;
    }
    while (msg_id_list_p)
    {
        if (curr_idx == index)
        {
            return msg_id_list_p->msg_id;
        }
        curr_idx++;
        msg_id_list_p = msg_id_list_p->next;
    }
    /* Ashok to Do: Write the code for the next cache list */
    return NULL;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_msg_from_list
 * DESCRIPTION
 *  This function is used to get the message list from the msgmgr list.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  mma_msg_info_list_struct
 *****************************************************************************/
mma_msg_info_list_struct *mma_msgmgr_get_msg_from_list(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_list_p = g_mma_msgmgr_cntx.msg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list_p == NULL)
    {
        return NULL;
    }
    while (msg_list_p != NULL)
    {
        if (msg_list_p->msg_id == msg_id)
        {
            return msg_list_p;
        }
        msg_list_p = msg_list_p->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_msg_num_for_sim_index
 * DESCRIPTION
 *  This function is used to get the total messages in folders based on Sim ID.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
static mma_result_enum mma_msgmgr_get_msg_num_for_sim_index(mma_msgmgr_msg_num_status_strcut *result, kal_uint32 index)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_folder_mms_count_status_struct folder_status = g_mma_msgmgr_cntx.mms_folder_status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_PARAMETER;
    }
    /* It's the Caller responsibility to check for the Garbage information */
    result->inbox_read_msg_number += folder_status.folder[index].inbox_read_msg_num;
    result->inbox_unread_msg_number += folder_status.folder[index].inbox_unread_msg_num;
    result->sent_msg_number += folder_status.folder[index].sent_msg_num;
    result->unsent_msg_number += folder_status.folder[index].unsent_msg_num;
    result->archive_msg_number += folder_status.folder[index].archive_read_inbox_msg_num + 
                                                        folder_status.folder[index].archive_unread_inbox_msg_num +
                                                        folder_status.folder[index].archive_sent_msg_num;
    return MMA_RESULT_OK;
 }


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_msg_num_of_each_folder
 * DESCRIPTION
 *  This function is used to get the total messages in each folder.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
static mma_result_enum mma_msgmgr_get_msg_num_of_each_folder(mma_msgmgr_msg_num_status_strcut *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_folder_mms_count_status_struct folder_status = g_mma_msgmgr_cntx.mms_folder_status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_PARAMETER;
    }
    /* Fill the information */
    result->draft_msg_number = folder_status.draft_msg_num;
    result->predefined_template_msg_number = folder_status.predefined_template_msg_num;
    result->userdefined_template_msg_number = folder_status.userdefined_template_msg_num;

    /* Initially, mark all mms count as Zero. Similar to memset for ZERO value */
    result->inbox_read_msg_number = 0;
    result->inbox_unread_msg_number = 0;
    result->sent_msg_number = 0;
    result->unsent_msg_number = 0;
    result->archive_msg_number = 0;

    if(result->msg_sim_id == MMA_SIM_ID_TOTAL)
    {
        kal_uint32  index = 0;
        for(; index <= MMA_MAX_SIM_COUNT; index++)
        {
            mma_msgmgr_get_msg_num_for_sim_index(result, index);
        }
        /* the DRAFT->ARCHIVE move case */
        result->archive_msg_number += folder_status.archive_msg_num;
    }
    else
    {
    #if (MMI_MAX_SIM_NUM >= 4)
        if(result->msg_sim_id & MMA_SIM_ID_SIM4)
	    {
            mma_msgmgr_get_msg_num_for_sim_index(result, MMA_INDEX_FOR_SIM4);
   	    }
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        if(result->msg_sim_id & MMA_SIM_ID_SIM3)
        {
            mma_msgmgr_get_msg_num_for_sim_index(result, MMA_INDEX_FOR_SIM3);
        }
    #endif
    #if (MMI_MAX_SIM_NUM >= 2)
        if(result->msg_sim_id & MMA_SIM_ID_SIM2)
        {
            mma_msgmgr_get_msg_num_for_sim_index(result, MMA_INDEX_FOR_SIM2);
        }
    #endif
        if(result->msg_sim_id & MMA_SIM_ID_SIM1)
        {
            mma_msgmgr_get_msg_num_for_sim_index(result, MMA_INDEX_FOR_SIM1);
        }
        if(result->msg_sim_id & MMA_SIM_ID_SIM_UNCLASSIFIED)
        {
            mma_msgmgr_get_msg_num_for_sim_index(result, MMA_INDEX_FOR_SIM_UNCLASSIFIED);
            /* the DRAFT->ARCHIVE move case */
            result->archive_msg_number += folder_status.archive_msg_num;
        }
    }

	/* ashok need to add the log */
	MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                          MMA_MSGMGR_MSG_STATUS_OF_FOLDER, "Msg status of folder:%d,%d,%d,%d,%d,%d,%d,%d",
                          result->inbox_read_msg_number, result->inbox_unread_msg_number,
						  result->draft_msg_number, result->sent_msg_number,
						  result->predefined_template_msg_number, result->userdefined_template_msg_number,
						  result->archive_msg_number, result->unsent_msg_number));
    return MMA_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_msg_folder_count
 * DESCRIPTION
 *  This function is used to get the total messages in each folder.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_result_enum mma_msgmgr_get_msg_folder_count(mma_mms_folder_mms_count_status_struct *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_folder_mms_count_status_struct folder_status = g_mma_msgmgr_cntx.mms_folder_status;
    int i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_PARAMETER;
    }
    /* Fill the information */
    result->draft_msg_num = folder_status.draft_msg_num;
    result->predefined_template_msg_num = folder_status.predefined_template_msg_num;
    result->userdefined_template_msg_num = folder_status.userdefined_template_msg_num;

    for(i = 0; i <= MMA_MAX_SIM_COUNT; i++)
    {
        result->folder[i].inbox_read_msg_num += folder_status.folder[i].inbox_read_msg_num;
        result->folder[i].inbox_unread_msg_num += folder_status.folder[i].inbox_unread_msg_num;
        result->folder[i].sent_msg_num += folder_status.folder[i].sent_msg_num;
        result->folder[i].unsent_msg_num += folder_status.folder[i].unsent_msg_num;
        result->folder[i].archive_read_inbox_msg_num += folder_status.folder[i].archive_read_inbox_msg_num;
        result->folder[i].archive_unread_inbox_msg_num += folder_status.folder[i].archive_unread_inbox_msg_num;
        result->folder[i].archive_sent_msg_num += folder_status.folder[i].archive_sent_msg_num;
    }
    /* the DRAFT->ARCHIVE move case */
    result->archive_msg_num = folder_status.archive_msg_num;
    result->total_phone_mms = folder_status.total_phone_mms;
    result->total_mcard_mms = folder_status.total_mcard_mms;
    return MMA_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_update_mms_folder_status
 * DESCRIPTION
 *  This function is used to get the total messages in a given folder.
 * PARAMETERS
 *  folder      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mma_msgmgr_update_mms_folder_status(mma_msg_info_list_struct *msg_list, kal_bool is_update, kal_uint8 old_folder, kal_uint8 new_folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int index = mma_msgmgr_get_index_from_sim_id((mma_sim_id_enum)msg_list->msg_sim_id);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(index < MMA_INDEX_FOR_SIM_UNCLASSIFIED || index >= MMA_MAX_INDEX_FOR_SIM)
    {
        ASSERT(0);
    }
    /* first check for the case of Update the folder */
    if((is_update == TRUE) && (old_folder))
    {
        switch (old_folder)
        {
            case MMA_FOLDER_INBOX:                
                if (msg_list->is_read)
                {
                    g_mma_msgmgr_cntx.mms_folder_status.folder[index].inbox_read_msg_num--;
                }
                else
                {
                    g_mma_msgmgr_cntx.mms_folder_status.folder[index].inbox_unread_msg_num--;
                #if defined (__MMI_OP11_HOMESCREEN__) || defined (__MMI_OP12_TOOLBAR__) || defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
                    mma_msgmgr_remove_msg_from_unread_list(msg_list->msg_id);
                #endif
                }
                break;
            case MMA_FOLDER_DRAFT:
                g_mma_msgmgr_cntx.mms_folder_status.draft_msg_num--;
                break;
            case MMA_FOLDER_SENT:
                g_mma_msgmgr_cntx.mms_folder_status.folder[index].sent_msg_num--;
                break;
            case MMA_FOLDER_ARCHIVE:
            {
                if ((!msg_list->is_read) && (msg_list->prev_folder == MMA_FOLDER_INBOX))
                {
                    g_mma_msgmgr_cntx.mms_folder_status.folder[index].archive_unread_inbox_msg_num--;
                }
                else if(msg_list->prev_folder == MMA_FOLDER_INBOX)
                {
                    g_mma_msgmgr_cntx.mms_folder_status.folder[index].archive_read_inbox_msg_num--;
                }
                else if(msg_list->prev_folder == MMA_FOLDER_DRAFT)
                {
                    /* Case of Unclassified Archive mms. Move from Draft to Archive */ 
                    g_mma_msgmgr_cntx.mms_folder_status.archive_msg_num--;
                }
                else
                {
                    g_mma_msgmgr_cntx.mms_folder_status.folder[index].archive_sent_msg_num--;
                }
            }
            break;
            case MMA_FOLDER_OUTBOX:
                g_mma_msgmgr_cntx.mms_folder_status.folder[index].unsent_msg_num--;
                break;
			case MMA_FOLDER_TEMPLATE:
				g_mma_msgmgr_cntx.mms_folder_status.predefined_template_msg_num--;
				break;
			case MMA_FOLDER_USRDEF_TEMPLATE:
				g_mma_msgmgr_cntx.mms_folder_status.userdefined_template_msg_num--;
				break;
            default:
                break;
        }
        if(old_folder != MMA_FOLDER_HIDDEN)
        {
            if(mma_get_message_storage(msg_list->msg_id) == MMA_MSG_STORAGE_PHONE)
            {
                g_mma_msgmgr_cntx.mms_folder_status.total_phone_mms--;
            }
            else
            {
                g_mma_msgmgr_cntx.mms_folder_status.total_mcard_mms--;
            }
        }
    }
    /* update the new entry */
    if((is_update == TRUE) && (!new_folder))
        return;
    if(new_folder != MMA_FOLDER_HIDDEN)
    {
        if(mma_get_message_storage(msg_list->msg_id) == MMA_MSG_STORAGE_PHONE)
        {
            g_mma_msgmgr_cntx.mms_folder_status.total_phone_mms++;
        }
        else
        {
            g_mma_msgmgr_cntx.mms_folder_status.total_mcard_mms++;
        }
    }
    switch (new_folder)
    {
        case MMA_FOLDER_INBOX:
            if (msg_list->is_read)
            {
                g_mma_msgmgr_cntx.mms_folder_status.folder[index].inbox_read_msg_num++;
            }
            else
            {
                g_mma_msgmgr_cntx.mms_folder_status.folder[index].inbox_unread_msg_num++;
            #if defined (__MMI_OP11_HOMESCREEN__) || defined (__MMI_OP12_TOOLBAR__) || defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
                mma_msgmgr_add_new_msg_to_unread_list(msg_list->msg_id, msg_list->receive_date, msg_list->suffix);
            #endif
            }
            break;
        case MMA_FOLDER_DRAFT:
            g_mma_msgmgr_cntx.mms_folder_status.draft_msg_num++;
            break;
        case MMA_FOLDER_SENT:
            g_mma_msgmgr_cntx.mms_folder_status.folder[index].sent_msg_num++;
            break;
        case MMA_FOLDER_TEMPLATE:
            g_mma_msgmgr_cntx.mms_folder_status.predefined_template_msg_num++;
            break;
        case MMA_FOLDER_USRDEF_TEMPLATE:
            g_mma_msgmgr_cntx.mms_folder_status.userdefined_template_msg_num++;
            break;
        case MMA_FOLDER_ARCHIVE:
            {
                if ((!msg_list->is_read) && (msg_list->prev_folder == MMA_FOLDER_INBOX))
                {
                    g_mma_msgmgr_cntx.mms_folder_status.folder[index].archive_unread_inbox_msg_num++;
                }
                else if(msg_list->prev_folder == MMA_FOLDER_INBOX)
                {
                    g_mma_msgmgr_cntx.mms_folder_status.folder[index].archive_read_inbox_msg_num++;
                }
                else if(msg_list->prev_folder == MMA_FOLDER_DRAFT)
                {
                    /* Case of Unclassified Archive mms. Move from Draft to Archive */ 
                    g_mma_msgmgr_cntx.mms_folder_status.archive_msg_num++;
                }
                else
                {
                    g_mma_msgmgr_cntx.mms_folder_status.folder[index].archive_sent_msg_num++;
                }
            }
            break;
        case MMA_FOLDER_OUTBOX:
            g_mma_msgmgr_cntx.mms_folder_status.folder[index].unsent_msg_num++;
            break;
        default:
            break;
    }
    /* ashok need to add the log */
	MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                          MMA_MSGMGR_UMMS_MSG_NUM_STATUS_OF_FOLDER, "(mma_msgmgr.c): UMMS Msg status of folder:%d,%d,%d,%d,%d,%d,%d",
                          g_mma_msgmgr_cntx.mms_folder_status.folder[0].inbox_read_msg_num, 
                          g_mma_msgmgr_cntx.mms_folder_status.folder[1].inbox_read_msg_num, 
                          g_mma_msgmgr_cntx.mms_folder_status.folder[0].inbox_unread_msg_num,
						  g_mma_msgmgr_cntx.mms_folder_status.folder[1].inbox_unread_msg_num, 
                          g_mma_msgmgr_cntx.mms_folder_status.draft_msg_num, 
                          g_mma_msgmgr_cntx.mms_folder_status.folder[0].sent_msg_num, 
                          g_mma_msgmgr_cntx.mms_folder_status.folder[1].sent_msg_num));
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                          MMA_MSGMGR_UMMS_MSG_NUM_STATUS_OF_FOLDER, "(mma_msgmgr.c): UMMS Msg status of folder:%d,%d,%d,%d,%d,%d,%d",
                          g_mma_msgmgr_cntx.mms_folder_status.predefined_template_msg_num, 
                          g_mma_msgmgr_cntx.mms_folder_status.userdefined_template_msg_num,
						  g_mma_msgmgr_cntx.mms_folder_status.folder[0].archive_unread_inbox_msg_num, 
                          g_mma_msgmgr_cntx.mms_folder_status.folder[0].archive_read_inbox_msg_num, 
                          g_mma_msgmgr_cntx.mms_folder_status.archive_msg_num,
						  g_mma_msgmgr_cntx.mms_folder_status.folder[0].unsent_msg_num, 
                          g_mma_msgmgr_cntx.mms_folder_status.folder[1].unsent_msg_num));
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_msg_num_of_folder
 * DESCRIPTION
 *  This function is used to get the total messages in a given folder.
 * PARAMETERS
 *  folder      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 mma_msgmgr_get_msg_num_of_folder(mma_folder_enum folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 result = 0;
    int i = 0;    /* Index */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (folder)
    {
        case MMA_FOLDER_INBOX:
            for(i = 0; i <= MMA_MAX_SIM_COUNT; i++)
            {
                result += g_mma_msgmgr_cntx.mms_folder_status.folder[i].inbox_read_msg_num + 
                            g_mma_msgmgr_cntx.mms_folder_status.folder[i].inbox_unread_msg_num;
            }
            break;
		case MMA_FOLDER_DRAFT:
            result = g_mma_msgmgr_cntx.mms_folder_status.draft_msg_num;
            break;
        case MMA_FOLDER_SENT:
            for(i = 0; i <= MMA_MAX_SIM_COUNT; i++)
            {
                result += g_mma_msgmgr_cntx.mms_folder_status.folder[i].sent_msg_num;
            }
            break;
        case MMA_FOLDER_OUTBOX:
            for(i = 0; i <= MMA_MAX_SIM_COUNT; i++)
            {
                result += g_mma_msgmgr_cntx.mms_folder_status.folder[i].unsent_msg_num;
            }
            break;
        case MMA_FOLDER_TEMPLATE:
            result = g_mma_msgmgr_cntx.mms_folder_status.predefined_template_msg_num;
            break;
        case MMA_FOLDER_USRDEF_TEMPLATE:
            result = g_mma_msgmgr_cntx.mms_folder_status.userdefined_template_msg_num;
            break;
        case MMA_FOLDER_ARCHIVE:
            for(i = 0; i <= MMA_MAX_SIM_COUNT; i++)
            {
                result += g_mma_msgmgr_cntx.mms_folder_status.folder[i].archive_unread_inbox_msg_num + 
                            g_mma_msgmgr_cntx.mms_folder_status.folder[i].archive_read_inbox_msg_num +
                            g_mma_msgmgr_cntx.mms_folder_status.folder[i].archive_sent_msg_num;
            }
            result += g_mma_msgmgr_cntx.mms_folder_status.archive_msg_num;
            break;
        default:
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_total_msg_num
 * DESCRIPTION
 *  This function is used to get the total number of messages
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 mma_msgmgr_get_total_msg_num(kal_uint8 storage_type)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msgmgr_new_msg_info_struct *new_msg_info = g_mma_msgmgr_cntx.new_msg_req_queue;
    MSF_UINT16 result = 0;
    kal_uint16 total_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* to get the number of mms from the msg list */
    switch(storage_type)
    {
        case MMA_MSG_STORAGE_PHONE:
        {
            while (new_msg_info != NULL)
            {
                if ((new_msg_info->state == MMA_MSGMGR_MSG_STATE_CREATING_ENCODED_MSG) && 
                    (mma_get_message_storage(new_msg_info->msg_id) == MMA_MSG_STORAGE_PHONE))
                {
                    result++;
                }
                new_msg_info = new_msg_info->next;
            }
            total_count = g_mma_msgmgr_cntx.mms_folder_status.total_phone_mms + result;
        }
        break;
        case MMA_MSG_STORAGE_TOTAL:
        {
            while (new_msg_info != NULL)
            {
                if (new_msg_info->state == MMA_MSGMGR_MSG_STATE_CREATING_ENCODED_MSG)
                {
                    result++;
                }
                new_msg_info = new_msg_info->next;
            }
            total_count = g_mma_msgmgr_cntx.mms_folder_status.total_phone_mms + result + 
                        g_mma_msgmgr_cntx.mms_folder_status.total_mcard_mms;
        }
        break;
        case MMA_MSG_STORAGE_CARD1:
        {
            while (new_msg_info != NULL)
            {
                if ((new_msg_info->state == MMA_MSGMGR_MSG_STATE_CREATING_ENCODED_MSG) && 
                    (mma_get_message_storage(new_msg_info->msg_id) == MMA_MSG_STORAGE_CARD1))
                {
                    result++;
                }
                new_msg_info = new_msg_info->next;
            }    
            total_count = g_mma_msgmgr_cntx.mms_folder_status.total_mcard_mms;
        }	
        break;
    default:
        ASSERT(0);
    }
    return total_count;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_add_msg_to_list
 * DESCRIPTION
 *  This function is used to add a messages in the message list.
 * PARAMETERS
 *  msg_info        [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static kal_bool mma_msgmgr_add_msg_to_list(mma_msg_info_list_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_info == NULL)
    {
        return KAL_FALSE;
    }
    if (msg_info->next != NULL)
    {
        ASSERT(0);
    }
    if (g_mma_msgmgr_cntx.msg_list == NULL)
    {
        g_mma_msgmgr_cntx.msg_list = msg_info;
    }
    else
    {
        mma_msg_info_list_struct *tmp = g_mma_msgmgr_cntx.msg_list;
        /* Check for the Duplicate message entry */
        if(tmp->msg_id == msg_info->msg_id)
        {
            ASSERT(0);
            /* Do not add it */
            return KAL_FALSE;
        }
        /* insert the new node based on the timestamp */
        if(tmp->receive_date <= msg_info->receive_date)
        {
            msg_info->next = tmp;
            g_mma_msgmgr_cntx.msg_list = msg_info;
            return KAL_TRUE;
        }
        while (tmp->next)
        {
            if(tmp->next->receive_date <= msg_info->receive_date)
            {
                msg_info->next = tmp->next;
                tmp->next = msg_info;
                return KAL_TRUE;
            }
            tmp = tmp->next;
        }
        tmp->next = msg_info;
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_remove_msg_from_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mma_msg_info_list_struct *mma_msgmgr_remove_msg_from_list(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_list_p = g_mma_msgmgr_cntx.msg_list;
    mma_msg_info_list_struct *result = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_list_p == NULL)
    {
        return NULL;
    }
    else if (msg_list_p->msg_id == msg_id)
    {
        g_mma_msgmgr_cntx.msg_list = msg_list_p->next;
        msg_list_p->next = NULL;
        //mma_msgmgr_update_mms_folder_status(msg_list_p, TRUE, msg_list_p->folder, 0);
        return msg_list_p;
    }
    else
    {
        while (msg_list_p->next != NULL)
        {
            if (msg_list_p->next->msg_id == msg_id)
            {
                result = msg_list_p->next;
                msg_list_p->next = msg_list_p->next->next;
                result->next = NULL;
                //mma_msgmgr_update_mms_folder_status(result, TRUE, result->folder, 0);
                return result;
            }
            msg_list_p = msg_list_p->next;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_pending_msg
 * DESCRIPTION
 *  This function is used to get the number of pending message operation.
 * PARAMETERS
 *  number      [IN]        
 * RETURNS
 *  Pointer of first message needs to be processed.
 *****************************************************************************/
mma_msg_info_list_struct *mma_msgmgr_get_pending_msg(kal_uint32 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 nbr_of_msg = 0;
    mma_msg_info_list_struct *output_msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_msgmgr_cntx.msg_list == NULL)
    {
        return NULL;
    }
    else
    {
        mma_msg_info_list_struct *msg_list_p = g_mma_msgmgr_cntx.msg_list;

        while (msg_list_p)
        {
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
            if (msg_list_p->flag != MMA_MSGMGR_MSG_OPER_NONE &&
                !MMA_MSGMGR_MSG_CHK_FLAG(msg_list_p->flag, MMA_MSGMGR_MSG_OPER_DRM_ENCODE_REQ_SENT) &&
                !MMA_MSGMGR_MSG_CHK_FLAG(msg_list_p->flag, MMA_MSGMGR_MSG_OPER_DRMSRV_ENCODING_SUSPENDED) &&
				!MMA_MSGMGR_MSG_CHK_FLAG(msg_list_p->flag, MMA_MSGMGR_MSG_OPER_PARSE_REQ_SENT) &&
                !MMA_MSGMGR_MSG_CHK_FLAG(msg_list_p->flag, MMA_MSGMGR_MSG_OPER_INT_PARSE_REQ_SUSPEND) &&
                !MMA_MSGMGR_MSG_CHK_FLAG(msg_list_p->flag, MMA_MSGMGR_MSG_OPER_NEED_MOVE_MSG))
#else
            if ((msg_list_p->flag != MMA_MSGMGR_MSG_OPER_NONE) &&
				!MMA_MSGMGR_MSG_CHK_FLAG(msg_list_p->flag, MMA_MSGMGR_MSG_OPER_PARSE_REQ_SENT) &&
                !MMA_MSGMGR_MSG_CHK_FLAG(msg_list_p->flag, MMA_MSGMGR_MSG_OPER_INT_PARSE_REQ_SUSPEND)&&
                !MMA_MSGMGR_MSG_CHK_FLAG(msg_list_p->flag, MMA_MSGMGR_MSG_OPER_NEED_MOVE_MSG))
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
            {
                nbr_of_msg++;
                if (output_msg_p == NULL)
                {
                    output_msg_p = msg_list_p;
					if (number == NULL)
					{
						return output_msg_p;
					}
                }
            }
            msg_list_p = msg_list_p->next;
        }
    }
    if (number != NULL)
    {
        *number = nbr_of_msg;
    }
    return output_msg_p;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_check_busy_state_pending_list
 * DESCRIPTION
 *  This function is used to check whether the MSGMGR is ready or not & to check for any pending message.
 * PARAMETERS
 *  source                  [IN]        
 *  sig                     [IN]        
 *  pending_msg_struct      [?]         
 *  pending_list(?)         [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mma_msgmgr_check_busy_state_pending_list(
            module_type source,
            mma_int_sig_type_enum sig,
            void *pending_msg_struct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMA_MSGMGR_GET_STATE() != MMA_MSGMGR_STATE_READY)
    {
        /* There are some pending message operation. */
        mma_send_int_sig(
            &(g_mma_msgmgr_cntx.pending_req_list),
            MMA_SUBMODULE_MSG_MGR,
            (long)sig,
            source,
            0,
            0,
            0,
            pending_msg_struct);
        return KAL_TRUE;
    }
    else if (mma_msgmgr_get_pending_msg(NULL))
    {
        /* There are some pending message operation. */
        MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_UPDATING_MSG_LIST);
        mma_msgmgr_send_int_perform_msg_oper_ind();
        mma_send_int_sig(
            &(g_mma_msgmgr_cntx.pending_req_list),
            MMA_SUBMODULE_MSG_MGR,
            (long)sig,
            source,
            0,
            0,
            0,
            pending_msg_struct);
        return KAL_TRUE;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_notify_app_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_id        [IN]        
 *  event_info      [IN]        
 *  event(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_notify_app_event(MSF_UINT16 event_id, void *event_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMA_NUM_OF_EVENT_APP_REGISTER; i++)
    {
        if (g_mma_app_event_table[i].event_id == event_id)
        {
            mms_mma_send_notify_event_ind(
                g_mma_app_event_table[i].dest_mod,
                g_mma_app_event_table[i].app_id,
                g_mma_app_event_table[i].event_id,
                event_info);
        }
    }

    MMA_FREE(event_info);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_free_new_msg_info
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  req_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_free_new_msg_info(MSF_UINT32 req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msgmgr_create_info_struct *create_info = NULL;
    mma_msgmgr_new_msg_info_struct *new_msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_msg_info = mma_msgmgr_remove_new_msg_info_from_list(req_id);
    ASSERT(new_msg_info);
    if ((create_info = (mma_msgmgr_create_info_struct*) new_msg_info->data) != NULL)
    {
        if (create_info->upload_filepath != NULL)
        {
            MMA_FREE(create_info->upload_filepath);
            create_info->upload_filepath = NULL;
        }
#if (defined(__MMI_MMS_VENDOR_APP_SUPPORT__) || defined(__MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__))
        if (create_info->mode == MMA_MODE_VENDOR_XML && create_info->xml_filepath != NULL)
        {
            MMA_FREE(create_info->xml_filepath);
            create_info->xml_filepath = NULL;
        }
#endif
        MMA_FREE(create_info);
        create_info = NULL;
    }
    MMA_FREE(new_msg_info);
    new_msg_info = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_process_msg_oper
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_info_p      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static mma_result_enum mma_msgmgr_process_msg_oper(mma_msg_info_list_struct *msg_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_info_p == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_PARAMETER;
    }
	MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_PROCESS_MSG_OPER_SIGNAL, "(mma_msgmgr.c): Recv sig flag %d",
						(int)msg_info_p->flag));

    if (msg_info_p->flag == MMA_MSGMGR_MSG_OPER_NONE)
    {
        return MMA_RESULT_OK;
    }
	#ifdef __MMI_MMS_MMA_DRM_ENCODING__
    if (msg_info_p->flag & MMA_MSGMGR_MSG_OPER_NEED_DRM_ENCODE)
    {
        /* need to check for the space */
        if(mma_msgmgr_check_parsing_status())
        {
            /* Parsing is going on, check for memory */
            if(MSF_MEM_GET_AVAILABLE_FREE_MEMORY() < MMA_PARSING_DRM_ENCODING_REQD_FREE_MEMORY)
            {
                /* not enough memory, delay the encoding procedure*/
                MMA_MSGMGR_MSG_SET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_DRMSRV_ENCODING_SUSPENDED);
                MMA_MSGMGR_MSG_UNSET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_NEED_DRM_ENCODE);
                return MMA_RESULT_OK;
            }
        }
        if (!(msg_info_p->flag & MMA_MSGMGR_MSG_OPER_DRM_ENCODE_REQ_SENT))
        {
            /* Send DRM encode request to MSG_DRMSRV */
            mma_msgmgr_new_msg_info_struct *new_msg_info = mma_msgmgr_get_new_msg_info_by_msg_id(msg_info_p->msg_id);
            if(new_msg_info == NULL)
            {
                /* It should not be NULL */
                ASSERT(0);
            }

            new_msg_info->state = MMA_MSGMGR_MSG_STATE_DRM_ENCODING;
            MMA_SIGNAL_SENDTO_UU(
                MMA_SUBMODULE_MSG_DRMSRV,
                MMA_INT_SIG_TYPE_MSG_DRM_ENCODE_REQ,
                new_msg_info->req_id,
                msg_info_p->msg_id);
            MMA_MSGMGR_MSG_SET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_DRM_ENCODE_REQ_SENT);
            MMA_MSGMGR_MSG_UNSET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_NEED_DRM_ENCODE);
        }
        return MMA_RESULT_OK;
    }
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
    if (msg_info_p->flag & MMA_MSGMGR_MSG_OPER_NEED_PARSE)
    {
        if (!(msg_info_p->flag & MMA_MSGMGR_MSG_OPER_PARSE_REQ_SENT))
        {
            if(g_mma_msgmgr_cntx.count_int_parse_req)
            {
                MMA_MSGMGR_MSG_UNSET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_NEED_PARSE);
                MMA_MSGMGR_MSG_SET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_INT_PARSE_REQ_SUSPEND);
            }
            else
            {
                /* Send Parse request to MSG_PARSER */
                MMA_SIGNAL_SENDTO_IU(
                    MMA_SUBMODULE_MSG_PARSE,
                    MMA_INT_SIG_TYPE_MSG_PARSER_GET_BASIC_MSG_INFO,
                    MMA_SUBMODULE_MSG_MGR,
                    msg_info_p->msg_id);
                MMA_MSGMGR_MSG_SET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_PARSE_REQ_SENT);
                MMA_MSGMGR_MSG_UNSET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_NEED_PARSE);
                g_mma_msgmgr_cntx.count_int_parse_req = TRUE;
            }
        }
        /* We still wait for PARSE_RSP. Don't do other operations */
        return MMA_RESULT_OK;
    }
    if (msg_info_p->flag & MMA_MSGMGR_MSG_OPER_REPLY_DOWNLOAD_RSP)
    {
        /* Remove notification */
        if (msg_info_p->def_noti_msg_id > 0)
        {
            mma_msg_info_list_struct *msg_info = mma_msgmgr_get_msg_from_list(msg_info_p->def_noti_msg_id);

            if (msg_info != NULL)
            {
                MMA_MSGMGR_MSG_SET_FLAG(msg_info->flag, MMA_MSGMGR_MSG_OPER_DELETE);
                mma_msgmgr_update_mms_folder_status(msg_info, KAL_TRUE, msg_info->folder, 0);

                if (msg_info->folder == MMA_FOLDER_INBOX &&
                    (msg_info->suffix == MMS_SUFFIX_NOTIFICATION || msg_info->suffix == MMS_SUFFIX_IMMEDIATE))
                {
                    /* When you come here, it means that users download one MMS manually (defer retrieval).
                       The MMS notifiction is deleted by MMS service in background. */
                    MMA_MSGMGR_MSG_SET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_NEED_SEND_UM_HIGHLIGHT_IND);
                }
                else
                {
                    ASSERT(0);
                }
                if (MMA_MSGMGR_GET_STATE() == MMA_MSGMGR_STATE_READY)
                {
                    MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_UPDATING_MSG_LIST);
                    mma_msgmgr_send_int_perform_msg_oper_ind();
                }
            }
            else
            {
                /* the case may be that notification is on Memory Card & card is removed.
                No operation need to do here. */
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                           MMA_MSGMGR_NOTIFICATION_MSG_ID_NOT_FOUND, 
                           "(mma_msgmgr.c): Notification entry %d not found in mms list\n", 
                           msg_info_p->def_noti_msg_id));
            }
        }
        MMA_MSGMGR_MSG_UNSET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_REPLY_DOWNLOAD_RSP);
        mma_sendrecv_msgmgr_download_rsp_hdlr(MMS_RESULT_OK, msg_info_p->msg_id);
        msg_info_p->user_can_not_see = FALSE;
        return MMA_RESULT_OK;
    }
    /* ashok add the new case for deleting the notif_id for the successful downloaded message */
    if (msg_info_p->flag & MMA_MSGMGR_MSG_OPER_DELETE_DOWNLOAD_MSG_NOTIFID_IND)
    {
        /* Remove notification */
        mma_msgmgr_recv_notif_data_struct *notif_data = NULL;
        if (msg_info_p->def_noti_msg_id > 0)
        {
            MMSif_deleteMessage(MSF_MODID_MMA, MMA_TRANSLATE_MSG_ID(msg_info_p->def_noti_msg_id), MMS_SUFFIX_IMMEDIATE, (MSF_UINT8) mma_get_mms_type_message_storage(msg_info_p->def_noti_msg_id));
        }
        /* get the context from the global context for the notif ID */
        notif_data = mma_msgmgr_remove_msg_notif_data(msg_info_p->def_noti_msg_id);
        if(notif_data != NULL)
        {
            /* free the memory of the notif data */
            mma_msgmgr_free_msg_notif_data(notif_data);
        }
    #ifdef __MMI_SLIM_MMS_2__
		/* send the OK result to SEND_RECV Module */
		MMA_SIGNAL_SENDTO_I(
                MMA_SUBMODULE_MSG_SENDRECV,
                MMA_INT_SIG_TYPE_MSG_MMS_OBJ_RES, MMS_RESULT_OK);
    #endif /* __MMI_SLIM_MMS_2__ */

        MMA_MSGMGR_MSG_UNSET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_DELETE_DOWNLOAD_MSG_NOTIFID_IND);
        return MMA_RESULT_OK;
    }
    if (msg_info_p->flag & MMA_MSGMGR_MSG_OPER_NEED_SEND_NEW_MSG_IND)
    {
        wap_mma_event_new_msg_struct *event_info = NULL;
        mms_msg_info_property_struct *property_st = NULL;
        mma_msgmgr_new_msg_info_struct *new_msg_info = mma_msgmgr_get_new_msg_info_by_msg_id(msg_info_p->msg_id);
        if (new_msg_info != NULL)
        {
            mma_msgmgr_free_new_msg_info(new_msg_info->req_id);
        }
        /* Update the count status */
        mma_msgmgr_update_mms_folder_status(msg_info_p, KAL_FALSE, 0, msg_info_p->folder);
        /* Allocate memory */
        property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));
        MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_info_p->msg_id),
                  (kal_uint8)mma_get_mms_type_message_storage(msg_info_p->msg_id),
                  property_st, NULL /*large_data_st */);
        /* send MSG_ID_UM_NEW_MSG_IND to application */
        if (msg_info_p->folder == MMA_FOLDER_INBOX)
        {
            if (msm_get_module_status(MSF_MODID_MMA) == MODULE_STATUS_ACTIVE)
            {
                event_info = (wap_mma_event_new_msg_struct*) MMA_CALLOC(sizeof(wap_mma_event_new_msg_struct));
                event_info->msg_id = msg_info_p->msg_id;
                event_info->folder = msg_info_p->folder;
				if(property_st->compose_date != 0)
				{
					event_info->date = property_st->compose_date;
				}
				else
				{
					event_info->date = msg_info_p->receive_date;
				}
                event_info->sim_id = msg_info_p->msg_sim_id;
                event_info->msg_media_type = property_st->msg_media_type;
                event_info->msg_type = property_st->msg_type;
                mma_msgmgr_notify_app_event(MMA_EVENT_NEW_MSG, event_info);
            }
        }
        MMA_MSGMGR_MSG_UNSET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_NEED_SEND_NEW_MSG_IND);
        msg_info_p->user_can_not_see = FALSE;
        //mma_msgmgr_update_mms_folder_status(msg_info_p, FALSE, 0, msg_info_p->folder);
        /* Free memory */        
        MMA_FREE(property_st);
        return MMA_RESULT_OK;
    }
    if (msg_info_p->flag & MMA_MSGMGR_MSG_OPER_NEED_SEND_CREATE_MMS_RSP)
    {
        mma_msgmgr_new_msg_info_struct *new_msg_info = NULL;
        mma_msgmgr_create_info_struct *info = NULL;

        if ((new_msg_info = mma_msgmgr_get_new_msg_info_by_msg_id(msg_info_p->msg_id)) == NULL)
        {
            ASSERT(0);
        }
        info = (mma_msgmgr_create_info_struct*) new_msg_info->data;
        g_mma_msgmgr_cntx.process_create_req_num--;
		if(msg_info_p->folder != MMA_FOLDER_HIDDEN)
        {
            msg_info_p->user_can_not_see = FALSE;
            mma_msgmgr_update_mms_folder_status(msg_info_p, KAL_FALSE, 0, msg_info_p->folder);
        }
        /* send MSG_ID_UM_NEW_MSG_IND to application */
        mma_create_send_reject_rsp(
            (module_type) (kal_uint32) info->source,
            info->req_id,
            info->app_id,
            info->msg_id,
            info->buffer_index,
             MMA_RESULT_OK);
        mma_msgmgr_free_new_msg_info(info->req_id);
        MMA_MSGMGR_MSG_UNSET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_NEED_SEND_CREATE_MMS_RSP);
        return MMA_RESULT_OK;
    }
    if (msg_info_p->flag & MMA_MSGMGR_MSG_OPER_DELETE)
    {
        if (!(msg_info_p->flag & MMA_MSGMGR_MSG_OPER_DELETE_REQ_SENT))
        {
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            if((mma_get_message_storage(msg_info_p->msg_id) == MMA_MSG_STORAGE_PHONE) || (MSF_IS_MEM_CARD_PRESNT(MSF_MMS_STORAGE_MEM_CARD_1)))
            {
                MMAif_deleteMessage(MMA_SUBMODULE_MSG_MGR, msg_info_p->msg_id);
                MMA_MSGMGR_MSG_SET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_DELETE_REQ_SENT);
            }
            else
            {
                /* Case of deleting a memory card mms while user plug-out the card */
                MMA_MSGMGR_MSG_SET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_DELETE_REQ_SENT);
                mma_msgmgr_mms_delete_ind_hdlr(MMS_RESULT_OK, msg_info_p->msg_id);
                //MMA_MSGMGR_MSG_SET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_DELETE_DONE);
            }
        #else
            MMAif_deleteMessage(MMA_SUBMODULE_MSG_MGR, msg_info_p->msg_id);
            MMA_MSGMGR_MSG_SET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_DELETE_REQ_SENT);
        #endif
        }
        else if (msg_info_p->flag & MMA_MSGMGR_MSG_OPER_DELETE_DONE)
        {
            wap_mma_event_delete_msg_struct *event_info = NULL;
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            if(msg_info_p->folder == MMA_FOLDER_INBOX)
            {
                /* case of deleting a received mms that was moved to other storage */  
                mma_msgmgr_new_msg_info_struct *new_msg_info = NULL;
                new_msg_info = mma_msgmgr_get_new_msg_info_by_msg_id(msg_info_p->msg_id);
                if((new_msg_info) && (new_msg_info->state != MMA_MSGMGR_MSG_STATE_CREATING_ENCODED_MSG))
                {
                    /* It is the moved mms. It is not the DRM FL CD encoding ongoing MMS */
                    mma_msgmgr_free_new_msg_info(new_msg_info->req_id);
                }
            }
        #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
            msg_info_p = mma_msgmgr_remove_msg_from_list(msg_info_p->msg_id);
            if((mma_get_message_storage(msg_info_p->msg_id) == MMA_MSG_STORAGE_PHONE) || (mma_main_is_storage_type_present(MMA_MSG_STORAGE_CARD1)))
            {
                MMSlib_delChkSumFile(MMA_TRANSLATE_MSG_ID(msg_info_p->msg_id), (kal_uint8)mma_get_mms_type_message_storage(msg_info_p->msg_id));
                //MMSlib_delAddrObjFile(MMA_TRANSLATE_MSG_ID(msg_info_p->msg_id), (kal_uint8)mma_get_mms_type_message_storage(msg_info_p->msg_id));
            }

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
            if (msg_info_p->flag & MMA_MSGMGR_MSG_OPER_NEED_SEND_DELETE_RSP)
            {
                mma_msgmgr_req_info_struct *delete_req = (mma_msgmgr_req_info_struct*) g_mma_msgmgr_cntx.delete_req;
                mms_mma_send_delete_msg_rsp(
                    (module_type) (kal_uint32) delete_req->source,
                    (kal_uint8) delete_req->app_id,
                    (kal_uint32*)delete_req->result,
                    (kal_uint32) delete_req->req_id,
                    (kal_uint32*) delete_req->msg_id,
					delete_req->no_of_msg);
				MMA_FREE(delete_req->result);
				MMA_FREE(delete_req->msg_id);
                MMA_FREE(delete_req);
				g_mma_msgmgr_cntx.delete_req = NULL;
            }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
			if (g_mma_msgmgr_cntx.source_module && g_mma_msgmgr_cntx.user_data)
            {
                if (msg_info_p->flag & MMA_MSGMGR_MSG_OPER_NEED_SEND_UM_DELETE_FOLDER_RSP)
                {
                    srv_um_delete_folder_req_struct *delete_folder_req =
                        (srv_um_delete_folder_req_struct*) g_mma_msgmgr_cntx.user_data;
                    mms_mma_send_delete_folder_rsp(
                        (module_type) (kal_uint32) g_mma_msgmgr_cntx.source_module,
                        delete_folder_req->app_id,
                        SRV_UM_MSG_MMS,
                        (g_mma_msgmgr_cntx.delete_result == MMA_RESULT_OK) ? KAL_TRUE : KAL_FALSE);
                    mma_msgmgr_notify_app_event(MMA_EVENT_UM_DELETE_FOLDER_DONE, NULL);
                    MMA_FREE(delete_folder_req);
                }
            }
                        
            event_info = (wap_mma_event_delete_msg_struct*) MMA_CALLOC(sizeof(wap_mma_event_delete_msg_struct));
            event_info->msg_id = msg_info_p->msg_id;
            event_info->folder = msg_info_p->folder;
            mma_msgmgr_notify_app_event(MMA_EVENT_DELETE_MSG, event_info);

            MMA_FREE(msg_info_p);
            return MMA_RESULT_OK;
        }
    }
    if (MMA_MSGMGR_MSG_CHK_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_NEED_SEND_UM_HIGHLIGHT_IND))
    {
        mms_mma_send_um_highlight_decide_by_um_ind(MOD_MMI, (mma_folder_enum)msg_info_p->folder, msg_info_p->msg_id);
        MMA_MSGMGR_MSG_UNSET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_NEED_SEND_UM_HIGHLIGHT_IND);
    }
    return MMA_RESULT_OK;
}


#ifdef __MMI_MMS_MMA_DRM_ENCODING__
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_encode_filepath
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  msg_id          [IN]        
 *  dest            [?]         [?]
 *  dest_len(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_msgmgr_get_encode_filepath(MSF_UINT32 msg_id, char *dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef MMS_IN_LARGE_STORAGE
	int drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);
#endif /* MMS_IN_LARGE_STORAGE */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dest != NULL)
    {
    #ifdef MMS_IN_LARGE_STORAGE
        sprintf(dest, "%s%x.e", MMS_PDU_FOLDER, (unsigned int)msg_id);
    #else /* MMS_IN_LARGE_STORAGE */
        sprintf(dest, "%c:\\@wap\\%x.e", drive_letter, (unsigned int)msg_id);
    #endif /* MMS_IN_LARGE_STORAGE */ 
    }
    return;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_give_msg_info_to_app
 * DESCRIPTION
 *  This function is used to 
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MSF_BOOL mma_msgmgr_give_msg_info_to_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_msgmgr_cntx.msg_list == NULL)
    {
        return TRUE;
    }
    else
    {
        mma_msg_info_list_struct *msg_list_p = g_mma_msgmgr_cntx.msg_list;

        while (msg_list_p)
        {
            /* encode and parse flag msg can't be seen to user, so put check only for the move & delete */
            /* Unseen mms also not added in the count status. So, count status is OK. */
            /* When MMS become seen from Unseen, then the count status get updated */
            if (MMA_MSGMGR_MSG_CHK_FLAG(msg_list_p->flag, MMA_MSGMGR_MSG_OPER_NEED_MOVE_MSG) ||
                MMA_MSGMGR_MSG_CHK_FLAG(msg_list_p->flag, MMA_MSGMGR_MSG_OPER_DELETE))
            {
                return FALSE;
            }
            msg_list_p = msg_list_p->next;
        }
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_um_get_msg_num_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source                  [IN]        
 *  get_um_msg_num_req      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_um_get_msg_num_req_hdlr(module_type source, srv_um_get_msg_num_req_struct *get_um_msg_num_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 report_msg_num = 0;
    kal_uint8 msg_sim_id = MMA_SIM_ID_TOTAL;
#if (MMI_MAX_SIM_NUM >= 2)
	if(get_um_msg_num_req->app_id == MMA_APP_ID_UM)
	{
		msg_sim_id = translate_um_simid_to_mma_simid(get_um_msg_num_req->sim_id);
	}
	else
	{
		msg_sim_id = get_um_msg_num_req->sim_id;
	}
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                           MMA_MSGMGR_UM_GET_MSG_NUM_REQ_MMA_NOT_READY, "MMA is not ready to get um msg num\n"));

        mms_mma_send_um_get_msg_num_rsp(
            source,
            get_um_msg_num_req->app_id,
            KAL_FALSE,
            SRV_UM_MSG_MMS,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0, 0);
    }
    else if (mma_main_is_in_usb_mode())
    {
        mms_mma_send_um_get_msg_num_rsp(
            source,
            get_um_msg_num_req->app_id,
            KAL_TRUE,
            SRV_UM_MSG_MMS,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            0, 0);
    }
	else if (mma_msgmgr_give_msg_info_to_app() == FALSE)
    {
        mma_send_int_sig(
            &(g_mma_msgmgr_cntx.pending_req_list),
            MMA_SUBMODULE_MSG_MGR,
            MMA_INT_SIG_TYPE_MSG_UM_GET_MSG_NUM_REQ,
            source,
            0,
            0,
            0,
            get_um_msg_num_req);
		return;
    }
    else
    {
    #ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
        /* Check the report_msg_num count for the Report Box feature */
        {
            //mms_msg_report_info *report_data = MMA_CALLOC(sizeof(mms_msg_report_info));
            mms_msg_report_info *report_data = MMA_CALLOC(MMS_REPORT_FILE_SIZE);
            if(MMSlib_readReportInfoFile(MSF_MMS_STORAGE_PHONE, report_data) == MMS_RESULT_OK)
            {
                report_msg_num = (kal_uint16)report_data->report_count;
            }
            MMA_FREE(report_data);
        }
    #endif
        {
            kal_uint16 inbox_unread_msg_num = 0;
            kal_uint16 inbox_read_msg_num = 0;
            kal_uint16 sent_msg_num = 0;
            kal_uint16 unsent_msg_num = 0;
            kal_uint16 archive_msg_num = 0;

			/* Getting the MMS no of diffrent boxes based on device storages */
            kal_uint16 draft_msg_num = 0;
            kal_uint16 predefined_template_msg_num = 0;
            kal_uint16 userdefined_template_msg_num = 0;
			mma_msg_storage_type_enum storage_filter = (mma_msg_storage_type_enum)g_mma_setting_cntx.setting->storage_filter;
			mma_msg_info_list_struct *msg_list_p = g_mma_msgmgr_cntx.msg_list;
			while(msg_list_p)
                {
					/* Populate various folder MMS no here */

			 if((mma_get_message_storage(msg_list_p->msg_id) & storage_filter) && (msg_list_p->msg_sim_id & msg_sim_id))
            {
				switch (msg_list_p->folder)
                {
					case MMA_FOLDER_INBOX:
						if(msg_list_p->is_read)
                {
							inbox_read_msg_num++;
                }
						else
                {
							inbox_unread_msg_num++;
                }
						break;
					case MMA_FOLDER_DRAFT:
						draft_msg_num++;
						break;
					case MMA_FOLDER_OUTBOX:
						unsent_msg_num++;
						break;
					case MMA_FOLDER_SENT:
						sent_msg_num++;
						break;
					case MMA_FOLDER_TEMPLATE:
						predefined_template_msg_num++;
						break;
					case MMA_FOLDER_USRDEF_TEMPLATE:
						userdefined_template_msg_num++;
						break;
					case MMA_FOLDER_ARCHIVE:
						archive_msg_num++;
						break;
					default:
						/*Do nothing May be hidden folder MMS*/;
                }
                }                
				msg_list_p = msg_list_p->next;
            }
            /* send the response */
            mms_mma_send_um_get_msg_num_rsp(
                source,
                get_um_msg_num_req->app_id,
                KAL_TRUE,
                SRV_UM_MSG_MMS,
                inbox_unread_msg_num,
                inbox_read_msg_num,
                unsent_msg_num,
                sent_msg_num,
                draft_msg_num,
                predefined_template_msg_num,
                userdefined_template_msg_num,
                archive_msg_num,
                report_msg_num);
        }
    }
    MMA_FREE(get_um_msg_num_req);
}


#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_um_get_report_list_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source              [IN]        
 *  get_list_req        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_um_get_report_list_req_hdlr(module_type source, srv_um_get_msg_list_req_struct *get_list_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_msg_report_info *report_data = NULL;
    srv_um_get_msg_list_rsp_struct *result = NULL;
    kal_int32 index = get_list_req->start_entry;
    kal_int32 total_msg_number = 0;
    kal_uint32 num_of_msg = 0;
    kal_bool more = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //report_data = (mms_msg_report_info*)MMA_CALLOC(sizeof(mms_msg_report_info));
    report_data = (mms_msg_report_info*)MMA_CALLOC(MMS_REPORT_FILE_SIZE);
    if(MMSlib_readReportInfoFile(MSF_MMS_STORAGE_PHONE, report_data) != MMS_RESULT_OK)
    {
		/* Still send the OK Result with 0 Reports */
        mms_mma_send_um_get_list_rsp(
            source,
            get_list_req->app_id,
            KAL_TRUE,
            (kal_uint16) get_list_req->msg_type,
            (kal_uint16) get_list_req->msg_box_type,
            (kal_uint16) get_list_req->start_entry,
            (kal_uint16) 0,
            NULL,
            KAL_FALSE,
            NULL, 0);
        MMA_FREE(get_list_req);
        MMA_FREE(report_data);
        return;
    }
    total_msg_number = report_data->report_count;
    result = (srv_um_get_msg_list_rsp_struct*) MMA_CALLOC(sizeof(srv_um_get_msg_list_rsp_struct));
    if (index < total_msg_number)
    {        
        do
        {
            result->list_info[num_of_msg].msg_id = (kal_uint32)MMSlib_genReportMsgId(index);
            if(report_data->data[index].date)
            {
                result->list_info[num_of_msg].timestamp = report_data->data[index].date;
            }
            else
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                              MMA_MSGMGR_UM_GET_LIST_RECEIVE_DATE_NULL,
                                              "(mma_msgmgr.c): No receive date for MsgId%d UMGetList\n", index));
                result->list_info[num_of_msg].timestamp = 0;
            }
            num_of_msg++;
            index++;
        }while(index < total_msg_number && num_of_msg < SRV_UM_MAX_GET_MSG_LIST_NUMBER);
    }
    if (index < total_msg_number)
    {
        more = KAL_TRUE;
    }

    mms_mma_send_um_get_list_rsp(
        source,
        get_list_req->app_id,
        KAL_TRUE,
        (kal_uint16) get_list_req->msg_type,
        (kal_uint16) get_list_req->msg_box_type,
        (kal_uint16) get_list_req->start_entry,
        (kal_uint16) num_of_msg,
        &(result->list_info),
        (kal_bool) more, NULL,0);
    MMA_FREE(get_list_req);
    MMA_FREE(report_data);
    MMA_FREE(result);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_um_get_report_info_req_hdlr
 * DESCRIPTION
 *  This function is used to get the message info of the Report Box folder.
 * PARAMETERS
 *  source                  [IN]        
 *  get_msg_info_req        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_um_get_report_info_req_hdlr(module_type source, srv_um_get_msg_info_req_struct *get_msg_info_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_msg_info_struct *msg_info_table_p = NULL;
    mms_msg_report_info *report_data = NULL;
    kal_bool *info_result = NULL;
    kal_uint32 index_of_msg = 0;
    kal_uint32 msg_index = 0;
    kal_wchar *str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info_result = MMA_CALLOC(sizeof(kal_bool) * SRV_UM_MAX_GET_MSG_INFO_NUMBER);
    memset(info_result, 0x00, sizeof(kal_bool) * SRV_UM_MAX_GET_MSG_INFO_NUMBER);
    for(index_of_msg = 0; ((index_of_msg < get_msg_info_req->msg_number) && index_of_msg < SRV_UM_MAX_GET_MSG_INFO_NUMBER ); index_of_msg++)
	{
		info_result[index_of_msg] = KAL_FALSE;
	}

    //report_data = (mms_msg_report_info*)MMA_CALLOC(sizeof(mms_msg_report_info));
    report_data = (mms_msg_report_info*)MMA_CALLOC(MMS_REPORT_FILE_SIZE);
    if(MMSlib_readReportInfoFile(MSF_MMS_STORAGE_PHONE, report_data) != MMS_RESULT_OK)
    {
        mms_mma_send_um_get_msg_info_rsp(
            source,
            get_msg_info_req->app_id,
            (kal_bool*)info_result,
			(kal_uint32*) get_msg_info_req->msg_id,
            (kal_uint16) SRV_UM_MSG_MMS,
            (kal_uint16) get_msg_info_req->msg_box_type,
            (kal_uint16) get_msg_info_req->msg_number,
            NULL);
        MMA_FREE(get_msg_info_req);
        MMA_FREE(report_data);
        MMA_FREE(info_result);
        return;
    }
    msg_info_table_p = (srv_um_msg_info_struct*) MMA_CALLOC(sizeof(srv_um_msg_info_struct) * SRV_UM_MAX_GET_MSG_INFO_NUMBER);

    for(index_of_msg = 0; ((index_of_msg < get_msg_info_req->msg_number) && (index_of_msg < SRV_UM_MAX_GET_MSG_INFO_NUMBER)); index_of_msg++)
	{
        info_result[index_of_msg] = KAL_TRUE;
        /* This msg_index is actually the index in the Report data array */
        //msg_index = get_msg_info_req->msg_id[index_of_msg];
        msg_index = MMSlib_getReportMsgIndex(get_msg_info_req->msg_id[index_of_msg]);
        /*if(msg_index > 0)
        {
            msg_index--;
        }
        else
        {
            ASSERT(0);
        }*/

        /* Fill the response data */
        msg_info_table_p[index_of_msg].msg_id = get_msg_info_req->msg_id[index_of_msg];
        msg_info_table_p[index_of_msg].timestamp = report_data->data[msg_index].date;
        /* This Report Box feature will come in Non-Slim build. So, check the DR/RR Icons */
    #ifndef __COSMOS_MMI_PACKAGE__
        if(report_data->data[msg_index].report_type == MMS_STATUS_IS_DR)
        {
            msg_info_table_p[index_of_msg].icon_id = MMA_IMG_REPORT_BOX_DR;
        }
        else
        {
            msg_info_table_p[index_of_msg].icon_id = MMA_IMG_REPORT_BOX_RR;
        }
    #endif    /* __COSMOS_MMI_PACKAGE__ */
        /* Fill the address detail */
        msg_info_table_p[index_of_msg].address_length = app_ucs2_strlen((const kal_int8*)report_data->data[msg_index].address);
        if (msg_info_table_p[index_of_msg].address_length > SRV_UM_MAX_ADDR_LEN)
        {
            msg_info_table_p[index_of_msg].address_length = SRV_UM_MAX_ADDR_LEN;
        }
        if (msg_info_table_p[index_of_msg].address_length > 0)
        {
            app_ucs2_strncpy(
                    (kal_int8*) msg_info_table_p[index_of_msg].address,
                    (const kal_int8*)report_data->data[msg_index].address,
                    msg_info_table_p[index_of_msg].address_length);
		}
        if(report_data->data[msg_index].addr_type == MMA_ADDR_TYPE_EMAIL)
        {
            msg_info_table_p[index_of_msg].address_type = SRV_UM_ADDR_EMAIL_ADDRESS;
        }
        else
        {
            msg_info_table_p[index_of_msg].address_type = SRV_UM_ADDR_PHONE_NUMBER;
        }
        /* Fill the subject */
        /* First get the Strng ID based on the Status */
        str = (kal_wchar*)mma_translate_report_status_to_string(report_data->data[msg_index].report_type, report_data->data[msg_index].status);           
        if(str != NULL)
        {
            msg_info_table_p[index_of_msg].subject_length = app_ucs2_strlen((const kal_int8*)str);
            if (msg_info_table_p[index_of_msg].subject_length > 0)
            {
                app_ucs2_strncpy(
                    (kal_int8*) msg_info_table_p[index_of_msg].subject,
                    (const kal_int8*)str,
                    SRV_UM_MAX_SUBJECT_LEN);
            }
        }
    }
    MMA_FREE(report_data);
    /* Send the response */
    mms_mma_send_um_get_msg_info_rsp(
        source,
        get_msg_info_req->app_id,
        (kal_bool*)info_result,
		(kal_uint32*) get_msg_info_req->msg_id,
        (kal_uint16) SRV_UM_MSG_MMS,
        (kal_uint16) get_msg_info_req->msg_box_type,
        (kal_uint16) get_msg_info_req->msg_number,
        msg_info_table_p);
    MMA_FREE(msg_info_table_p);
    MMA_FREE(get_msg_info_req);
    MMA_FREE(info_result);    
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_delete_report_data_req_hdlr
 * DESCRIPTION
 *  This function is used to get the message info of the Report Box folder.
 * PARAMETERS
 *  source                  [IN]        
 *  get_msg_info_req        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_delete_report_data_req_hdlr(module_type source, wap_mma_delete_req_struct *delete_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 *delete_result = NULL;
    kal_uint32 *list_of_msg = NULL;
    kal_uint32 msg_index = 0;
    MmsResult result = MMS_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    delete_result = MMA_CALLOC(sizeof(kal_uint32) * delete_req->no_of_msg);
    list_of_msg = MMA_CALLOC(sizeof(kal_uint32) * delete_req->no_of_msg);
    for(msg_index = 0; msg_index < delete_req->no_of_msg; msg_index++)
	{
		delete_result[msg_index] = MMA_RESULT_OK;
        list_of_msg[msg_index] = MMSlib_getReportMsgIndex(delete_req->msg_id[msg_index]);
        //list_of_msg[msg_index] = delete_req->msg_id[msg_index];
	}
    result = MMSlib_deleteEntryFromReportInfoFile(delete_req->no_of_msg, list_of_msg);
    if(result != MMS_RESULT_OK)
    {
        for(msg_index = 0; msg_index < delete_req->no_of_msg; msg_index++)
		{
			delete_result[msg_index] = MMA_RESULT_FAIL;
		}
    }
	mms_mma_send_delete_msg_rsp(
        (module_type) source,
        (kal_uint8) delete_req->app_id,
        delete_result,
        (kal_uint32) delete_req->req_id,
        (kal_uint32*) delete_req->msg_id,
		delete_req->no_of_msg);
    MMA_FREE(delete_req);
    MMA_FREE(delete_result);
    MMA_FREE(list_of_msg);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_um_delete_report_folder_req_hdlr
 * DESCRIPTION
 *  This function is used to get the message info of the Report Box folder.
 * PARAMETERS
 *  source                  [IN]        
 *  get_msg_info_req        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_um_delete_report_folder_req_hdlr(module_type source, srv_um_delete_folder_req_struct *delete_folder_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if it is in usb mode */
    if (mma_main_is_in_usb_mode() == TRUE)
    {
        mms_mma_send_delete_folder_rsp(source, delete_folder_req->app_id, SRV_UM_MSG_MMS, KAL_FALSE);
    }
    else
    {
        MMSlib_deleteReportInfoFile();
        /* Make the unread count as 0 */
        mma_msgmgr_reset_unread_report_count();
        mms_mma_send_delete_folder_rsp(source, delete_folder_req->app_id, SRV_UM_MSG_MMS, KAL_TRUE);
    }
    MMA_FREE(delete_folder_req);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_um_get_list_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source              [IN]        
 *  get_list_req        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_um_get_list_req_hdlr(module_type source, srv_um_get_msg_list_req_struct *get_list_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(get_list_req);

    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                           MMA_MSGMGR_UM_GET_LIST_REQ_MMA_NOT_READY, "MMA is not ready to get um list\n"));

        mms_mma_send_um_get_list_rsp(
            source,
            get_list_req->app_id,
            KAL_FALSE,
            (kal_uint16) get_list_req->msg_type,
            (kal_uint16) get_list_req->msg_box_type,
            (kal_uint16) get_list_req->start_entry,
            (kal_uint16) 0,
            NULL,
            KAL_FALSE,
            NULL, 0);
        MMA_FREE(get_list_req);
        return;
    }
    else if (mma_main_is_in_usb_mode())
    {
        mms_mma_send_um_get_list_rsp(
            source,
            get_list_req->app_id,
            KAL_TRUE,
            (kal_uint16) get_list_req->msg_type,
            (kal_uint16) get_list_req->msg_box_type,
            (kal_uint16) get_list_req->start_entry,
            (kal_uint16) 0,
            NULL,
            KAL_FALSE,
            NULL, 0);
        MMA_FREE(get_list_req);
        return;
    }
	else if ((mma_msgmgr_give_msg_info_to_app() == FALSE))
    {
        mma_send_int_sig(
            &(g_mma_msgmgr_cntx.pending_req_list),
            MMA_SUBMODULE_MSG_MGR,
            MMA_INT_SIG_TYPE_MSG_UM_GET_LIST_REQ,
            source,
            0,
            0,
            0,
            get_list_req);
		return;
    }
#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
    else if(get_list_req->msg_box_type == SRV_UM_MSG_BOX_REPORT)
    {
        mma_msgmgr_um_get_report_list_req_hdlr(source, get_list_req);
        return;
    }
#endif
    else
    {
        mma_msg_info_list_struct *msg_info = NULL;
        srv_um_get_msg_list_rsp_struct *result = NULL;
        kal_int32 index = get_list_req->start_entry;
        kal_int32 total_msg_number = 0;
        kal_uint32 num_of_msg = 0;
        kal_bool more = KAL_FALSE;
        mma_msgmgr_msg_num_status_strcut msg_status = {0};
		mma_msg_storage_type_enum storage_filter = (mma_msg_storage_type_enum)g_mma_setting_cntx.setting->storage_filter;		/*get list based on stoarge filter*/
        msg_status.msg_sim_id = MMA_SIM_ID_TOTAL;
#if (MMI_MAX_SIM_NUM >= 2)
		if(get_list_req->app_id == MMA_APP_ID_UM)
		{
			msg_status.msg_sim_id = translate_um_simid_to_mma_simid(get_list_req->sim_id);
		}
        else
        {
            msg_status.msg_sim_id = get_list_req->sim_id;
        }
#endif
        if (mma_msgmgr_get_msg_num_of_each_folder(&msg_status) == MMA_RESULT_OK)
        {
            switch (get_list_req->msg_box_type)
            {
                case SRV_UM_MSG_BOX_INBOX:
                    total_msg_number =
                        msg_status.inbox_read_msg_number + msg_status.inbox_unread_msg_number;
                    break;
                case SRV_UM_MSG_BOX_UNSENT:
                    total_msg_number = msg_status.unsent_msg_number;
                    break;
                case SRV_UM_MSG_BOX_SENT:
                    total_msg_number = msg_status.sent_msg_number;
                    break;
                case SRV_UM_MSG_BOX_DRAFT:
                    total_msg_number = msg_status.draft_msg_number;
                    break;
                case SRV_UM_MSG_BOX_PREDEF_TEMPLATES:
                    total_msg_number = msg_status.predefined_template_msg_number;
                    break;
                case SRV_UM_MSG_BOX_USRDEF_TEMPLATES:
                    total_msg_number = msg_status.userdefined_template_msg_number;
                    break;
            #if defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__)
                case SRV_UM_MSG_BOX_ARCHIVE:
                    total_msg_number = msg_status.archive_msg_number;
                    break;
            #endif /* defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) */
                default:
                    if((get_list_req->msg_box_type & SRV_UM_MSG_BOX_PREDEF_TEMPLATES) && (get_list_req->msg_box_type & SRV_UM_MSG_BOX_USRDEF_TEMPLATES))
                    {
                        /* Case of providing the list of both Default & User-defined template list to UM in FTO */
                        total_msg_number = msg_status.predefined_template_msg_number + msg_status.userdefined_template_msg_number;
                    }
                    break;
            }
#if (defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_MMS_TEMPLATE_SUPPORT__))
            if((get_list_req->msg_box_type & SRV_UM_MSG_BOX_PREDEF_TEMPLATES) &&
                !mms_is_default_templates_ready())
            {
                /* Put this primitive in Pending list now. UMMS will create the template */
                    mma_send_int_sig( &(g_mma_msgmgr_cntx.pending_req_list),
                            MMA_SUBMODULE_MSG_MGR,
                            MMA_INT_SIG_TYPE_MSG_UM_GET_LIST_REQ,
                            source, 0, 0, 0, get_list_req);                    
                /* Send a primitive to UMMS to check the default template */
           /*     mms_mma_send_ilm(NULL, NULL, MSG_ID_WAP_MMA_CHECK_TEMPLATE_REQ, MOD_MMI); not required now the srv mms API would internally do it*/
                return;
            }
        #endif   /* __COSMOS_MMI_PACKAGE__ */
            if (index < total_msg_number)
            {
                result = (srv_um_get_msg_list_rsp_struct*) MMA_CALLOC(sizeof(srv_um_get_msg_list_rsp_struct));
                do
                {
                    if(!((get_list_req->msg_box_type & SRV_UM_MSG_BOX_PREDEF_TEMPLATES) ||
                        (get_list_req->msg_box_type & SRV_UM_MSG_BOX_USRDEF_TEMPLATES)))
                    {
                        msg_info = mma_msgmgr_get_msg_info_by_idx(
                                (kal_uint32) mma_cvt_um_folder_to_mma_folder(get_list_req->msg_box_type),
                                index, msg_status.msg_sim_id);
                    }
                    else
                    {
                #ifdef __COSMOS_MMI_PACKAGE__
                        msg_info = mma_msgmgr_get_template_msg_info_by_idx(index, msg_status.msg_sim_id);
                #else
                        msg_info = mma_msgmgr_get_msg_info_by_idx(
                                (kal_uint32) mma_cvt_um_folder_to_mma_folder(get_list_req->msg_box_type),
                                index, msg_status.msg_sim_id);
                #endif
                    }
                    if (msg_info != NULL && (mma_get_message_storage(msg_info->msg_id) & storage_filter))
                    {
                        mma_result_enum ret;
                        mms_msg_info_property_struct *property_st = NULL;
                        mms_msg_info_large_data_struct *large_data_st = NULL;
                        
                        if(0 ||
                    #ifdef __MMI_MMS_POSTCARD__
                        (msg_info->folder == MMA_FOLDER_SENT) ||
                    #endif
                    #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
                        (get_list_req->list_idx_type == SRV_UM_LIST_IDX_SUBJECT) ||
                        (get_list_req->list_idx_type == SRV_UM_LIST_IDX_ADDRESS) ||
                        ((get_list_req->list_idx_type == SRV_UM_LIST_IDX_MSG_SIZE) &&
                        (msg_info->suffix != MMS_SUFFIX_NOTIFICATION))||
                    #endif
                        0)
                        {
                            large_data_st = (mms_msg_info_large_data_struct*)MMA_CALLOC(sizeof(mms_msg_info_large_data_struct));
                            ASSERT(large_data_st);                        
                            property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));
                            ASSERT(property_st);
                         
                            ret = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_info->msg_id),
                                        (kal_uint8)mma_get_mms_type_message_storage(msg_info->msg_id),
                                        property_st, large_data_st));
                        }
						else
						{
							ret = MMA_RESULT_OK;						
						}

                        result->list_info[num_of_msg].msg_id = msg_info->msg_id;
                        if (msg_info->receive_date)
                        {
                            result->list_info[num_of_msg].timestamp = msg_info->receive_date;
                        }
                        else
                        {
                            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                              MMA_MSGMGR_UM_GET_LIST_RECEIVE_DATE_NULL,
                                              "(mma_msgmgr.c): No receive date for MsgId%d UMGetList\n", msg_info->msg_id));

                            result->list_info[num_of_msg].timestamp = 0;
                        }
				#ifdef __MMI_MMS_POSTCARD__
						if(msg_info->folder == MMA_FOLDER_SENT)
						{
                            if ((ret == MMA_RESULT_OK) && (property_st->msg_type == MMA_MSG_TYPE_POSTCARD))
							{
							    result->list_info[num_of_msg].timestamp = property_st->compose_date;
							}
                        }
			    #endif /* __MMI_MMS_POSTCARD__ */
                #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
                        {
                            switch (get_list_req->list_idx_type)
                            {
                                case SRV_UM_LIST_IDX_READ_STATUS:
                                    result->list_idx_data[num_of_msg].read_status = msg_info->is_read;
                                     break;
                                case SRV_UM_LIST_IDX_MSG_SIZE:
                                    if(msg_info->suffix == MMS_SUFFIX_NOTIFICATION)
                                    {
                                        char *msg_file_path = NULL;
                                        msg_file_path = MMAlib_getMessagePath(MSF_MODID_MMA, msg_info->msg_id);
                                        ASSERT(msg_file_path);
                                        result->list_idx_data[num_of_msg].msg_size = MSF_FILE_GETSIZE_EXT(msg_file_path, 
                                                                                    mma_get_mms_type_message_storage(msg_info->msg_id));
                                    }
                                    else
                                    {
                                        result->list_idx_data[num_of_msg].msg_size = property_st->msg_size;
                                    }
                                    break;
                                case SRV_UM_LIST_IDX_MSG_TYPE:
                                    result->list_idx_data[num_of_msg].msg_type = SRV_UM_MSG_MMS;
                                    break;
                                case SRV_UM_LIST_IDX_SUBJECT:
                                {
                                    if(msg_info->mms_msg_type == MMA_MSG_TYPE_UNSUPPORTED)
                                    {
                                        kal_wchar *error_str = NULL;

                                        error_str = (kal_wchar*) get_string(MMA_STR_ID_MESSAGE_UNSUPPORTED);

                                        if(app_ucs2_strlen((const kal_int8*)error_str) > 0)
                                        {
                                            app_ucs2_strncpy(
                                                    (kal_int8*) result->list_idx_data[num_of_msg].subject,
                                                    (const kal_int8*)error_str,
                                                    SRV_UM_MAX_LIST_INDEX_LEN);
                                        }
                                    }
                                    else if (ret == MMA_RESULT_OK)
                                    {// Sandeep, now delivery report may also have the subject field
                                        if(msg_info->suffix != MMS_SUFFIX_DELIVERYREPORT && 
											msg_info->suffix != MMS_SUFFIX_READREPORT && 
											app_ucs2_strlen((const kal_int8*) large_data_st->subject) > 0)
					                    {
						                    app_ucs2_strncpy(
                                                    (kal_int8*) result->list_idx_data[num_of_msg].subject,
                                                    (const kal_int8*)large_data_st->subject,
                                                    SRV_UM_MAX_LIST_INDEX_LEN);
					                    }
                                        else
                                        {
                                            /* Give special information to subject. We need to use String ID */
                                            kal_wchar *str = NULL;
                                    #ifndef __MMI_MMS_REPORT_STATUS_SUPPORT__
                                            if (msg_info->suffix == MMS_SUFFIX_DELIVERYREPORT)
                                            {
                                                str = (kal_wchar*) get_string(MMA_STR_ID_MMS_DELIVERY_REPORT);
                                            }
                                            else if (msg_info->suffix == MMS_SUFFIX_READREPORT)
                                            {
                                                str = (kal_wchar*) get_string(MMA_STR_ID_MMS_READ_REPORT);
                                            }
                                    #endif
                                    #ifdef __MMI_MMS_GROUP_MSG__
                                            if ((msg_info->suffix == MMS_SUFFIX_MSG || msg_info->suffix == MMS_SUFFIX_SEND_REQ) &&
                                                     property_st->num_of_recipient > 1)
                                            {
                                                str = (kal_wchar*) get_string(MMA_STR_ID_MMS_GROUP_MESSAGE);
                                            }
                                    #endif
                                            if (app_ucs2_strlen((const kal_int8*)str) > 0)
                                            {
                                                app_ucs2_strncpy(
                                                    (kal_int8*) result->list_idx_data[num_of_msg].subject,
                                                    (const kal_int8*)str,
                                                    SRV_UM_MAX_LIST_INDEX_LEN);
                                            }
                                        }
                                    }
                                }

                                    break;
                                case SRV_UM_LIST_IDX_ADDRESS:
                                {
                                    if (ret == MMA_RESULT_OK && msg_info->mms_msg_type != MMA_MSG_TYPE_UNSUPPORTED )
                                    {
                                        if((msg_info->suffix == MMS_SUFFIX_READREPORT) || 
                                            (msg_info->suffix == MMS_SUFFIX_DELIVERYREPORT) || 
                                            (msg_info->suffix == MMS_SUFFIX_MSG) ||
                                            (msg_info->suffix == MMS_SUFFIX_NOTIFICATION))
                                        {
                                            if(app_ucs2_strlen((const kal_int8*) large_data_st->from_address) > 0)
					                        {
						                        app_ucs2_strncpy(
                                                        (kal_int8*) result->list_idx_data[num_of_msg].address,
                                                        (const kal_int8*)large_data_st->from_address,
                                                        SRV_UM_MAX_LIST_INDEX_LEN);
					                        }
                                        }
                                        else if(app_ucs2_strlen((const kal_int8*) large_data_st->address) > 0)
					                    {
						                    app_ucs2_strncpy(
                                                    (kal_int8*) result->list_idx_data[num_of_msg].address,
                                                    (const kal_int8*)large_data_st->address,
                                                    SRV_UM_MAX_LIST_INDEX_LEN);
					                    }
                                    }
                                    
                                }
                                    break;
                                default:
                                    break;
                            }
                        }
			    #endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */

                        num_of_msg++;
                        index++;
                        if ((ret == MMA_RESULT_OK) || (property_st != NULL))
                        {
                            MMA_FREE(property_st);
                            property_st = NULL;
                        }
                        if (large_data_st != NULL)
                        {
                            MMA_FREE(large_data_st);
                            large_data_st = NULL;
                        }
                    }
                    else
                    {
                        index++;
                    }
                } while (msg_info != NULL && index < total_msg_number && num_of_msg < SRV_UM_MAX_GET_MSG_LIST_NUMBER);

                if (index < total_msg_number)
                {
                    more = KAL_TRUE;
                }
           #ifdef __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__
                mms_mma_send_um_get_list_rsp(
                    source,
                    get_list_req->app_id,
                    KAL_TRUE,
                    (kal_uint16) get_list_req->msg_type,
                    (kal_uint16) get_list_req->msg_box_type,
                    (kal_uint16) get_list_req->start_entry,
                    (kal_uint16) num_of_msg,
                    &(result->list_info),
                    (kal_bool) more,
                    &(result->list_idx_data),
                    get_list_req->list_idx_type);
           #else
                mms_mma_send_um_get_list_rsp(
                    source,
                    get_list_req->app_id,
                    KAL_TRUE,
                    (kal_uint16) get_list_req->msg_type,
                    (kal_uint16) get_list_req->msg_box_type,
                    (kal_uint16) get_list_req->start_entry,
                    (kal_uint16) num_of_msg,
                    &(result->list_info),
                    (kal_bool) more, NULL,0);
            #endif /* __UNIFIED_MESSAGE_SORT_MESSAGE_LIST__ */
                MMA_FREE(result);
                MMA_FREE(get_list_req);
                return;
            }
        }
    }
    mms_mma_send_um_get_list_rsp(
        source,
        get_list_req->app_id,
        KAL_TRUE,
        (kal_uint16) get_list_req->msg_type,
        (kal_uint16) get_list_req->msg_box_type,
        (kal_uint16) get_list_req->start_entry,
        (kal_uint16) 0,
        NULL,
        KAL_FALSE,
        NULL, 0);
    MMA_FREE(get_list_req);
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_um_msg_info_req_hdlr
 * DESCRIPTION
 *  This function is used to get the message info of the UM folder.
 * PARAMETERS
 *  source                  [IN]        
 *  get_msg_info_req        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_get_um_msg_info_req_hdlr(module_type source, srv_um_get_msg_info_req_struct *get_msg_info_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_msg_info_struct *msg_info_table_p = NULL;
    kal_bool *info_result = NULL;
    kal_uint32 index_of_msg = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                           MMA_MSGMGR_GET_UM_MSG_INFO_REQ, "MMA get the um msg info req\n"));
    info_result = MMA_CALLOC(sizeof(kal_bool) * SRV_UM_MAX_GET_MSG_INFO_NUMBER);
    memset(info_result, 0x00, sizeof(kal_bool) * SRV_UM_MAX_GET_MSG_INFO_NUMBER);

	if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                           MMA_MSGMGR_UM_GET_MSG_INFO_REQ_MMA_NOT_READY, "(mma_msgmgr.c): MMA is not ready to get um msg info"));

        for(index_of_msg = 0; ((index_of_msg < get_msg_info_req->msg_number) && index_of_msg < SRV_UM_MAX_GET_MSG_INFO_NUMBER ); index_of_msg++)
		{
			info_result[index_of_msg] = KAL_FALSE;
		}
        mms_mma_send_um_get_msg_info_rsp(
            source,
            get_msg_info_req->app_id,
            (kal_bool*)info_result,
			(kal_uint32*) get_msg_info_req->msg_id,
            (kal_uint16) SRV_UM_MSG_MMS,
            (kal_uint16) get_msg_info_req->msg_box_type,
            (kal_uint16) get_msg_info_req->msg_number,
            NULL);
        MMA_FREE(get_msg_info_req);
        MMA_FREE(info_result);
        return;
    }
    else if (mma_main_is_in_usb_mode())
    {
        for(index_of_msg = 0; ((index_of_msg < get_msg_info_req->msg_number) && index_of_msg < SRV_UM_MAX_GET_MSG_INFO_NUMBER ); index_of_msg++)
		{
			info_result[index_of_msg] = KAL_FALSE;
		}
        mms_mma_send_um_get_msg_info_rsp(
            source,
            get_msg_info_req->app_id,
            (kal_bool*)info_result,
			(kal_uint32*) get_msg_info_req->msg_id,
            (kal_uint16) SRV_UM_MSG_MMS,
            (kal_uint16) get_msg_info_req->msg_box_type,
            (kal_uint16) get_msg_info_req->msg_number,
            NULL);
        MMA_FREE(get_msg_info_req);
        MMA_FREE(info_result);
        return;
    }
    else if (mma_msgmgr_check_busy_state_pending_list
             (source, MMA_INT_SIG_TYPE_MSG_UM_GET_MSG_INFO_REQ, get_msg_info_req))
    {
        MMA_FREE(info_result);
        return;
    }
#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
    else if(get_msg_info_req->msg_box_type == SRV_UM_MSG_BOX_REPORT)
    {
        MMA_FREE(info_result);
        mma_msgmgr_um_get_report_info_req_hdlr(source, get_msg_info_req);
        return;
    }
#endif
    else
    {
        kal_uint32 msg_id = 0;
        mma_msg_info_list_struct *msg_info = NULL;
        mma_result_enum result = MMA_RESULT_OK;
        mms_msg_info_property_struct *property_st = NULL;
        mms_msg_info_large_data_struct *large_data_st = NULL;
        large_data_st = (mms_msg_info_large_data_struct*)MMA_CALLOC(sizeof(mms_msg_info_large_data_struct));
        ASSERT(large_data_st);                        
        property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));
        ASSERT(property_st);

        msg_info_table_p =
            (srv_um_msg_info_struct*) MMA_CALLOC(sizeof(srv_um_msg_info_struct) * SRV_UM_MAX_GET_MSG_INFO_NUMBER);

        for(index_of_msg = 0; ((index_of_msg < get_msg_info_req->msg_number) && (index_of_msg < SRV_UM_MAX_GET_MSG_INFO_NUMBER)); index_of_msg++)
		{
            info_result[index_of_msg] = KAL_TRUE;
            msg_id = get_msg_info_req->msg_id[index_of_msg];
            msg_info = mma_msgmgr_get_msg_from_list(get_msg_info_req->msg_id[index_of_msg]);
            msg_info_table_p[index_of_msg].msg_id = get_msg_info_req->msg_id[index_of_msg];
            if(msg_info->mms_msg_type == MMA_MSG_TYPE_UNSUPPORTED)
            {
                kal_wchar *error_str = NULL;

                error_str = (kal_wchar*) get_string(MMA_STR_ID_MESSAGE_UNSUPPORTED);

                msg_info_table_p[index_of_msg].subject_length = app_ucs2_strlen((const kal_int8*)error_str);
                if (msg_info_table_p[index_of_msg].subject_length > 0)
                {
                    app_ucs2_strncpy(
                        (kal_int8*) msg_info_table_p[index_of_msg].subject,
                        (const kal_int8*)error_str,
                        MMA_MAX_SUBJECT_LEN - 1);
                }
            #ifndef __COSMOS_MMI_PACKAGE__
                msg_info_table_p[index_of_msg].icon_id = MMA_IMG_CORRUPT;
            #endif  /* __COSMOS_MMI_PACKAGE__ */
        #ifdef __COSMOS_MMI_PACKAGE__
                msg_info_table_p[index_of_msg].msg_status = MMA_MSG_ICON_STATUS_CORRUPTED_MMS;
        #endif
                info_result[index_of_msg] = KAL_FALSE;
                continue;
            }
            result = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_id),
                            (kal_uint8)mma_get_mms_type_message_storage(msg_id),
                            property_st, large_data_st));

            if (result == MMA_RESULT_OK)
            {
        #ifdef __COSMOS_MMI_PACKAGE__
                msg_info_table_p[index_of_msg].msg_status = mma_msgmgr_get_mms_msg_status(msg_id);
        #endif
                msg_info_table_p[index_of_msg].subject_length = app_ucs2_strlen((const kal_int8*) large_data_st->subject);
                if (property_st->suffix != MMS_SUFFIX_DELIVERYREPORT &&
					property_st->suffix != MMS_SUFFIX_READREPORT &&
					msg_info_table_p[index_of_msg].subject_length > 0)
                {
                    app_ucs2_strncpy(
                            (kal_int8*) msg_info_table_p[index_of_msg].subject,
                            (const kal_int8*)large_data_st->subject,
                            SRV_UM_MAX_SUBJECT_LEN);
				}
                else
                {
                    // Give special information to subject. We need to use String ID 
                    kal_wchar *str = NULL;
#ifndef __MMI_MMS_REPORT_STATUS_SUPPORT__
                    if (property_st->suffix == MMS_SUFFIX_DELIVERYREPORT)
                    {
                        str = (kal_wchar*) get_string(MMA_STR_ID_MMS_DELIVERY_REPORT);
                    }
                    else if (property_st->suffix == MMS_SUFFIX_READREPORT)
                    {
                        str = (kal_wchar*) get_string(MMA_STR_ID_MMS_READ_REPORT);
                    }
#endif
#ifdef __MMI_MMS_GROUP_MSG__
                    if ((property_st->suffix == MMS_SUFFIX_MSG || property_st->suffix == MMS_SUFFIX_SEND_REQ) &&
                             property_st->num_of_recipient > 1)
                    {
                        str = (kal_wchar*) get_string(MMA_STR_ID_MMS_GROUP_MESSAGE);
                    }
#endif
                    if(str != NULL)
                    {
                        msg_info_table_p[index_of_msg].subject_length = app_ucs2_strlen((const kal_int8*)str);
                        if (msg_info_table_p[index_of_msg].subject_length > 0)
                        {
                            app_ucs2_strncpy(
                                (kal_int8*) msg_info_table_p[index_of_msg].subject,
                                (const kal_int8*)str,
                                SRV_UM_MAX_SUBJECT_LEN);
                        }
                    }
                }
				if((property_st->suffix == MMS_SUFFIX_READREPORT) || 
                    (property_st->suffix == MMS_SUFFIX_DELIVERYREPORT) ||
                    (property_st->suffix == MMS_SUFFIX_MSG) ||
                    (property_st->suffix == MMS_SUFFIX_NOTIFICATION))
				{
                    msg_info_table_p[index_of_msg].address_length = app_ucs2_strlen((const kal_int8*) large_data_st->from_address);
                    if (msg_info_table_p[index_of_msg].address_length > SRV_UM_MAX_ADDR_LEN)
                    {
                        msg_info_table_p[index_of_msg].address_length = SRV_UM_MAX_ADDR_LEN;
                    }
                    if (msg_info_table_p[index_of_msg].address_length > 0)
                    {
                        app_ucs2_strncpy(
                                (kal_int8*) msg_info_table_p[index_of_msg].address,
                                (const kal_int8*)large_data_st->from_address,
                                msg_info_table_p[index_of_msg].address_length);
					}
					msg_info_table_p[index_of_msg].address_type = (srv_um_addr_enum)large_data_st->from_address_type;
					if(get_msg_info_req->app_id == MMA_APP_ID_UM)
                    {
                        if(large_data_st->from_address_type == MMA_ADDR_TYPE_EMAIL)
                        {
                            msg_info_table_p[index_of_msg].address_type = SRV_UM_ADDR_EMAIL_ADDRESS;
                        }
                        else
                        {
                            msg_info_table_p[index_of_msg].address_type = SRV_UM_ADDR_PHONE_NUMBER;
                        }
                    }
				}
            #if defined (__MMI_MMS_GROUP_MSG__) || defined (__MMI_OP12_MMS_GROUP_MSG_SUPPORT__)
                else if ((property_st->folder == MMA_FOLDER_OUTBOX) && (property_st->num_of_recipient > 1))
                {
                    /* Maximum 32 bit number contain 10 digits. (10+1)* ENCODING_LENGTH is the size of array for the itoa*/
                    /* Although Maximum number of permissible addresses are 20 but tester can put more using the tool */
                    kal_wchar string_buf[MMA_MAX_ADDR_LEN] = {0,};
                    kal_uint32 size = 0;
                    app_ucs2_itoa (property_st->num_of_recipient, (kal_int8*) &string_buf, MMA_INT_TO_STRING_CONV_RADIX);
                    /* concat the "recipients" string */
                    app_ucs2_strcat((kal_int8*) &string_buf, (kal_int8*) " ");
                    size = app_ucs2_strlen((const kal_int8*) string_buf);
                    app_ucs2_strncat((kal_int8*) &string_buf, (kal_int8*) get_string(MMA_STR_ID_GROUP_MSG_RECIPIENT),
                            (MMA_MAX_ADDR_LEN - size -1));
                    msg_info_table_p[index_of_msg].address_length = app_ucs2_strlen((const kal_int8*) string_buf);
                    if (msg_info_table_p[index_of_msg].address_length > SRV_UM_MAX_ADDR_LEN)
                    {
                        msg_info_table_p[index_of_msg].address_length = SRV_UM_MAX_ADDR_LEN;
                    }
                    if (msg_info_table_p[index_of_msg].address_length > 0)
                    {
                        app_ucs2_strncpy(
                                (kal_int8*) msg_info_table_p[index_of_msg].address,
                                (const kal_int8*)string_buf,
                                msg_info_table_p[index_of_msg].address_length);
					}
                }
            #endif
				else
                {
                    msg_info_table_p[index_of_msg].address_length = app_ucs2_strlen((const kal_int8*) large_data_st->address);
                    
                    if (msg_info_table_p[index_of_msg].address_length > 0)
                    {
                        app_ucs2_strncpy(
                                (kal_int8*) msg_info_table_p[index_of_msg].address,
                                (const kal_int8*)large_data_st->address,
                                msg_info_table_p[index_of_msg].address_length);
                        if ((mmi_ucs2chr((const S8*)msg_info_table_p[index_of_msg].address, (U16) L'@')) == NULL)
                        {
                            if(get_msg_info_req->app_id == MMA_APP_ID_UM)
                            {
                                msg_info_table_p[index_of_msg].address_type = SRV_UM_ADDR_PHONE_NUMBER;
                            }
                            else
                            {
                                msg_info_table_p[index_of_msg].address_type = (srv_um_addr_enum)translate_mms_address_type_to_mma(MMS_PLMN);
                            }
                        }
                        else
                        {
                            if(get_msg_info_req->app_id == MMA_APP_ID_UM)
                            {
                                msg_info_table_p[index_of_msg].address_type = SRV_UM_ADDR_EMAIL_ADDRESS;
                            }
                            else
                            {
                                msg_info_table_p[index_of_msg].address_type = (srv_um_addr_enum)translate_mms_address_type_to_mma(MMS_EMAIL);
                            }
                        }
					}
				}
#if (MMI_MAX_SIM_NUM >= 2)
                if(get_msg_info_req->app_id == MMA_APP_ID_UM)
				{
					msg_info_table_p[index_of_msg].sim_id = (srv_um_sim_enum)translate_mma_simid_to_um_simid(msg_info->msg_sim_id);
				}
#endif
	                              
	            if(property_st->msg_type == MMA_MSG_TYPE_JAVA || 
				   property_st->msg_type == MMA_MSG_TYPE_NOTIFICATION || 
				   get_msg_info_req->msg_box_type == SRV_UM_MSG_BOX_UNSENT) 
                {
#ifndef __MMI_WGUI_DISABLE_CSK__
                    msg_info_table_p[index_of_msg].csk_icon_id = IMG_GLOBAL_OPTION_CSK;
#else
					msg_info_table_p[index_of_msg].csk_icon_id = 0;
#endif /*__MMI_WGUI_DISABLE_CSK__ */
                }
                else
                {
#ifndef __MMI_WGUI_DISABLE_CSK__
                    msg_info_table_p[index_of_msg].csk_icon_id = IMG_GLOBAL_COMMON_CSK;
#else
                    msg_info_table_p[index_of_msg].csk_icon_id = 0;
#endif /*__MMI_WGUI_DISABLE_CSK__ */
                }
              
            #ifndef __COSMOS_MMI_PACKAGE__
                msg_info_table_p[index_of_msg].icon_id = mma_msgmgr_create_img_id( property_st, large_data_st);
            #endif   /* __COSMOS_MMI_PACKAGE__ */
                if (property_st->receive_date != NULL)
                {
                    msg_info_table_p[index_of_msg].timestamp = property_st->receive_date;
                }
                else
                {
                    msg_info_table_p[index_of_msg].timestamp = 0;
                }
		    #ifdef __MMI_MMS_POSTCARD__
			    if(property_st->folder == MMA_FOLDER_SENT)
			    {
				    if (property_st->msg_type == MMA_MSG_TYPE_POSTCARD)
				    {
					    msg_info_table_p[index_of_msg].timestamp = property_st->compose_date;
				    }
			    }
		    #endif 
            }
            else
            {
                kal_wchar *error_str = NULL;

                error_str = (kal_wchar*) get_string(MMA_STR_ID_MESSAGE_CORRUPT);

                msg_info_table_p[index_of_msg].subject_length = app_ucs2_strlen((const kal_int8*)error_str);
                if (msg_info_table_p[index_of_msg].subject_length > 0)
                {
                    app_ucs2_strncpy(
                        (kal_int8*) msg_info_table_p[index_of_msg].subject,
                        (const kal_int8*)error_str,
                        MMA_MAX_SUBJECT_LEN - 1);
                }
            #ifndef __COSMOS_MMI_PACKAGE__
                msg_info_table_p[index_of_msg].icon_id = MMA_IMG_CORRUPT;
            #endif  /* __COSMOS_MMI_PACKAGE__*/
        #ifdef __COSMOS_MMI_PACKAGE__
                msg_info_table_p[index_of_msg].msg_status = MMA_MSG_ICON_STATUS_CORRUPTED_MMS;
        #endif
                info_result[index_of_msg] = KAL_FALSE;
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                  MMA_MSGMGR_UM_GET_MSG_INFO_REQ_NO_DATE_4MSGID, "(mma_msgmgr.c): No receive data for MsgId%d UMGetInfo",
                                  get_msg_info_req->msg_id[index_of_msg]));
            }
            memset(large_data_st, 0x00, sizeof(mms_msg_info_large_data_struct));
            memset(property_st, 0x00, sizeof(mms_msg_info_property_struct));
        }
        MMA_FREE(large_data_st);
        large_data_st = NULL;
		MMA_FREE(property_st);
		property_st = NULL;
    }

   mms_mma_send_um_get_msg_info_rsp(
        source,
        get_msg_info_req->app_id,
        (kal_bool*)info_result,
		(kal_uint32*) get_msg_info_req->msg_id,
        (kal_uint16) SRV_UM_MSG_MMS,
        (kal_uint16) get_msg_info_req->msg_box_type,
        (kal_uint16) get_msg_info_req->msg_number,
        msg_info_table_p);
    MMA_FREE(msg_info_table_p);
    MMA_FREE(get_msg_info_req);
    MMA_FREE(info_result);
}


#ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_update_report_data_req_hdlr
 * DESCRIPTION
 *  To add the RR, DR & notification mms in the report  box
 * PARAMETERS
 *  data                            [IN]        
 *  new_msg_source                  [IN]        
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/ 
mma_result_enum mma_msgmgr_update_report_data_req_hdlr(mma_msgmgr_new_message_source_enum new_msg_source, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_msg_report_info_struct *report_data = NULL;
    wap_mma_event_new_msg_struct *event_info = NULL;
    mms_msg_addr_info_struct *addr = NULL;
    kal_uint8 storage_type = 0;
    kal_uint8 sim_id = 0;
    kal_uint32 orig_msg_id = 0;  /* To free the memory */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read the data from the file */
    report_data = (mms_msg_report_info_struct*)MMA_CALLOC(sizeof(mms_msg_report_info_struct));

    if(new_msg_source == MMA_MSGMGR_GET_FROM_READ_REPORT)
    {
        MmsMsgReadReport *sig_data = (MmsMsgReadReport*) data;
        
        sim_id = sig_data->simId;
        report_data->date = sig_data->date;
        report_data->storage_type = sig_data->storageType;
        report_data->report_type = MMS_STATUS_IS_RR;
        report_data->status = translate_mms_rr_status_to_mma_status((kal_uint16)sig_data->readStatus);
        report_data->sim_id = sig_data->simId;
        if (sig_data->address != NULL)
        {
            report_data->addr_type = translate_mms_address_type_to_mma(sig_data->addrType);
            if(report_data->addr_type != MMA_ADDR_TYPE_NONE)
            {
                long srcLen = 0, dstLen = 0;
			    srcLen = strlen(sig_data->address);
                dstLen = (MMS_MAX_ADDR_DATA_LEN - 1) * sizeof(kal_wchar);
                msf_charset_utf8_to_ucs2le(sig_data->address, 
                                     &srcLen,
                                     (char *)report_data->address, 
                                     &dstLen);
            }
        }
        
        if (sig_data->serverMessageId != NULL)
        {
            report_data->orig_msgId = MMSlib_mmsGetMsgId(sig_data->serverMessageId, &storage_type);
            report_data->storage_type = storage_type;
        }
        /* Now update the Data. Call the API */
        MMSlib_UpdateReportInfoFile(MSF_MMS_STORAGE_PHONE, report_data);
        /* Now delete the entry of this report from FLDR */
        MMSif_deleteMessage(MSF_MODID_MMA, sig_data->msgId, MMS_SUFFIX_READREPORT, (MSF_UINT8) sig_data->storageType);
    }
    else if(new_msg_source == MMA_MSGMGR_GET_FROM_DELIVERY_REPORT)
    {
        MmsMsgDeliveryReportInd *sig_data = (MmsMsgDeliveryReportInd*) data;

        sim_id = sig_data->simId;
        report_data->date = sig_data->date;
        report_data->storage_type = sig_data->storageType;
        report_data->report_type = MMS_STATUS_IS_DR;
        report_data->status = translate_mms_dr_status_to_mma_status((kal_uint16)sig_data->status);
        report_data->sim_id = sig_data->simId;
        if (sig_data->address != NULL)
        {
            report_data->addr_type = translate_mms_address_type_to_mma(sig_data->addrType);
            if(report_data->addr_type != MMA_ADDR_TYPE_NONE)
            {
                long srcLen = 0, dstLen = 0;
			    srcLen = strlen(sig_data->address);
                dstLen = (MMS_MAX_ADDR_DATA_LEN - 1) * sizeof(kal_wchar);
                msf_charset_utf8_to_ucs2le(sig_data->address, 
                                     &srcLen,
                                     (char *)report_data->address, 
                                     &dstLen);
            }
        }
        
        if (sig_data->serverMsgId != NULL)
        {
            report_data->orig_msgId = MMSlib_mmsGetMsgId(sig_data->serverMsgId, &storage_type);
            report_data->storage_type = storage_type;
            /*report_data->orig_msgId =  mma_main_encode_msg_id(
                            (kal_uint8)translate_mms_storage_to_mma_storage_enum(storage_type), 
                            report_data->orig_msgId);*/
        }
        /* Now update the Data. Call the API */
        MMSlib_UpdateReportInfoFile(MSF_MMS_STORAGE_PHONE, report_data);
        /* Now delete the entry of this report from FLDR */
        MMSif_deleteMessage(MSF_MODID_MMA, sig_data->msgId, MMS_SUFFIX_DELIVERYREPORT, (MSF_UINT8) sig_data->storageType);
    }
    else
    {
        ASSERT(0);
    } 
    /* Update the entry in AddrObj File */
    addr = (mms_msg_addr_info_struct*)MMA_CALLOC(sizeof(mms_msg_addr_info_struct));
    addr->addr_type = report_data->addr_type;
    if(report_data->report_type == MMS_STATUS_IS_DR)
    {
        addr->dr_status = report_data->status;                            
    }
    else
    {
        addr->rr_status = report_data->status;
    }
    app_ucs2_strncpy((kal_int8*) addr->address,
             (const MSF_INT8*)report_data->address,
             MMS_MAX_ADDR_DATA_LEN - 1);

    /* First free the Memory to prevent the memory shortage */
    orig_msg_id = report_data->orig_msgId; 
    MMA_FREE(report_data);

    MMSlib_UpdateAddrObjFile(orig_msg_id, storage_type, addr);
    
    /* Update the Unread report count */
    g_mma_msgmgr_cntx.mms_folder_status.unread_report_msg_num++;
    MMSlib_updateReportMmsCount((MSF_UINT32)g_mma_msgmgr_cntx.mms_folder_status.unread_report_msg_num);

    /* Send the new msg ind to Application */
    /* Need to recheck all the values of variables after discussion with Ashwani */
    event_info = (wap_mma_event_new_msg_struct*) MMA_CALLOC(sizeof(wap_mma_event_new_msg_struct));
    event_info->msg_id = 0;
    event_info->date = MSF_TIME_GET_SECURE_CLOCK();
    event_info->folder = MMA_FOLDER_REPORT_BOX;
    event_info->msg_media_type = MMA_MEDIA_MSG_NONE;
    event_info->sim_id = sim_id;
    if(new_msg_source == MMA_MSGMGR_GET_FROM_READ_REPORT)
    {
        event_info->msg_type = MMA_MSG_TYPE_READ_REPORT;
        event_info->report_status = addr->rr_status;
    }
    else
    {
        event_info->msg_type = MMA_MSG_TYPE_DELIVERY_REPORT;
        event_info->report_status = addr->dr_status;
    }
    event_info->from_address_type = addr->addr_type;
    app_ucs2_strncpy((kal_int8*) event_info->from_address,
             (const MSF_INT8*)addr->address,
             MMA_MAX_ADDR_LEN - 1);
	
    mma_msgmgr_notify_app_event(MMA_EVENT_NEW_MSG, event_info);
    MMA_FREE(addr);
    return MMA_RESULT_OK;
}
#endif

/* ashok test the new function */
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_add_new_report_notif_req_hdlr
 * DESCRIPTION
 *  To add the RR, DR & notification mms in the mms list
 * PARAMETERS
 *  data                            [IN]        
 *  new_msg_source                  [IN]        
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/ 
mma_result_enum mma_msgmgr_add_new_report_notif_req_hdlr( mma_msgmgr_new_message_source_enum new_msg_source, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_list;
    char *msg_file_path = NULL;
    mma_result_enum result = MMA_RESULT_OK;
    MmsResult mms_result = MMS_RESULT_OK;
    mms_msg_info_property_struct *property_st = NULL;
    mms_msg_info_large_data_struct *large_data_st = NULL;
    kal_int32 msg_size = 0;
    kal_uint8 preferred_storage = MMA_MSG_STORAGE_PHONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
         
    /* add this msg into msg list */
    msg_list = (mma_msg_info_list_struct*) MMA_CALLOC(sizeof(mma_msg_info_list_struct));
    /* allocate memory for the checksum data */
    large_data_st = (mms_msg_info_large_data_struct*)MMA_CALLOC(sizeof(mms_msg_info_large_data_struct));
    property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));

    msg_list->folder = MMA_FOLDER_INBOX;
    if(new_msg_source == MMA_MSGMGR_GET_FROM_READ_REPORT)
    {
        MmsMsgReadReport *sig_data = (MmsMsgReadReport*) data;

        msg_list->suffix = MMS_SUFFIX_READREPORT;
        /* ashok added code for DUal SIM */
        msg_list->msg_sim_id =  translate_mms_sim_to_mma_sim((kal_uint8)sig_data->simId);
        property_st->compose_date = sig_data->date;
        property_st->msg_report_status = translate_mms_rr_status_to_mma_status((kal_uint16)sig_data->readStatus);
        msg_list->msg_id = mma_main_encode_msg_id(
                            (kal_uint8)translate_mms_storage_to_mma_storage_enum((msf_mms_storage_enum)sig_data->storageType), 
                            sig_data->msgId);
        if (sig_data->address != NULL)
        {
            large_data_st->from_address_type = translate_mms_address_type_to_mma(sig_data->addrType);
            if(large_data_st->from_address_type != MMA_ADDR_TYPE_NONE)
            {
                long srcLen = 0, dstLen = 0;
			    srcLen = strlen(sig_data->address);
                dstLen = (MMA_MAX_ADDR_LEN - 1) * sizeof(kal_wchar);
                msf_charset_utf8_to_ucs2le(sig_data->address, 
                                     &srcLen,
                                     (char *)large_data_st->from_address, 
                                     &dstLen);
            }
        }

        if (sig_data->subject != NULL)
        {
            long srcLen = 0, dstLen = 0;
			srcLen = strlen(sig_data->subject);
			dstLen = (MMS_MAX_SUBJECT_LEN - 1) * sizeof(kal_wchar);
			msf_charset_utf8_to_ucs2le(sig_data->subject , 
									 &srcLen,
									 (char*)large_data_st->subject, 
									 &dstLen);
        }

        if (sig_data->serverMessageId != NULL)
        {
            long srcLen = 0, dstLen = 0;
			srcLen = strlen(sig_data->serverMessageId);
			dstLen = JSR_MAX_APP_ID_LENGTH - 1; // Sandeep: To Change this later
			gmms_msf_charset_utf8_to_utf8((const char*)sig_data->serverMessageId , 
									 &srcLen,
									 (char*)large_data_st->java_reply_app_id, 
									 &dstLen);
        }

        /* Ashok to do: need to check if there is memory that is need to be 
        free by msgmgr which is allocated by core */
    }
    else if(new_msg_source == MMA_MSGMGR_GET_FROM_DELIVERY_REPORT)
    {
        MmsMsgDeliveryReportInd *sig_data = (MmsMsgDeliveryReportInd*) data;
        msg_list->suffix = MMS_SUFFIX_DELIVERYREPORT;
        msg_list->msg_sim_id = translate_mms_sim_to_mma_sim((kal_uint8)sig_data->simId);
        property_st->compose_date = sig_data->date;
        property_st->msg_report_status = translate_mms_dr_status_to_mma_status((kal_uint16)sig_data->status);
        msg_list->msg_id = mma_main_encode_msg_id(
                        (kal_uint8)translate_mms_storage_to_mma_storage_enum((msf_mms_storage_enum)sig_data->storageType),
                        sig_data->msgId);
        if (sig_data->address != NULL)
        {
            large_data_st->from_address_type = translate_mms_address_type_to_mma(sig_data->addrType);
            if(large_data_st->from_address_type != MMA_ADDR_TYPE_NONE)
            {
                long srcLen = 0, dstLen = 0;
			    srcLen = strlen(sig_data->address);
                dstLen = (MMA_MAX_ADDR_LEN - 1) * sizeof(kal_wchar);
                msf_charset_utf8_to_ucs2le(sig_data->address, 
                                     &srcLen,
                                     (char *)large_data_st->from_address, 
                                     &dstLen);
            }
        }
        if (sig_data->subject != NULL)
        {
            long srcLen = 0, dstLen = 0;
			srcLen = strlen(sig_data->subject);
			dstLen = (MMS_MAX_SUBJECT_LEN - 1) * sizeof(kal_wchar);
			msf_charset_utf8_to_ucs2le(sig_data->subject , 
									 &srcLen,
									 (char*)large_data_st->subject, 
									 &dstLen);
        }

        if (sig_data->serverMsgId != NULL)
        {
            long srcLen = 0, dstLen = 0;
			srcLen = strlen(sig_data->serverMsgId);
			dstLen = JSR_MAX_APP_ID_LENGTH - 1; // Sandeep: To Change this later
			gmms_msf_charset_utf8_to_utf8((const char*)sig_data->serverMsgId , 
									 &srcLen,
									 (char*)large_data_st->java_reply_app_id, 
									 &dstLen);
        }

    }
    else if(new_msg_source == MMA_MSGMGR_GET_FROM_NOTIFICATION)
    {
        MmsMsgReplyNotification *sig_data = (MmsMsgReplyNotification*) data;

        msg_list->suffix = MMS_SUFFIX_NOTIFICATION;
        msg_list->msg_id = mma_main_encode_msg_id((kal_uint8)translate_mms_storage_to_mma_storage_enum((msf_mms_storage_enum)sig_data->storageType), sig_data->notifId);
        msg_list->msg_sim_id = translate_mms_sim_to_mma_sim((kal_uint8)sig_data->simId);
        msg_list->new_msg_state = MMA_MSGMGR_GET_FROM_NOTIFICATION;
        property_st->compose_date = MSF_TIME_GET_SECURE_CLOCK();
        property_st->expiry_date = sig_data->expiryDate;
        property_st->msg_class = translate_mms_class_to_mma(sig_data->msgClass);
        property_st->priority = translate_mms_priority_to_mma(sig_data->priority);
        msg_list->mms_priority = (kal_uint8)property_st->priority;
        if(sig_data->type == MMS_NOTIFICATION_IMMEDIATE)
        {
            /* Ashok to do rename the file name from *.q to *.n to make it notification */
            kal_uint8 mms_storage = mma_get_mms_type_message_storage(msg_list->msg_id);
            char *path_notif = (char*)MMSlib_getMessageFullPath(MSF_MODID_MMA, MMA_TRANSLATE_MSG_ID(msg_list->msg_id), MMS_SUFFIX_NOTIFICATION);
            char *path_immed = (char*)MMSlib_getMessageFullPath(MSF_MODID_MMA, MMA_TRANSLATE_MSG_ID(msg_list->msg_id), MMS_SUFFIX_IMMEDIATE);

            MSF_FILE_REMOVE_EXT(path_notif, (msf_mms_storage_enum)mms_storage);
            /* Ashok, Check the error here */
            mms_result = MMSlib_translateMsfFileErrorToMmsError(MSF_FILE_RENAME_EXT(path_immed, path_notif, (msf_mms_storage_enum)mms_storage));
            result = translate_mms_result_to_mma(mms_result);
            
            MMA_FREE(path_notif);
            MMA_FREE(path_immed);
            
            if(result != MMA_RESULT_OK)
            {
                /* As the entry is not added in the MSGMGR, add it */
                mma_msgmgr_add_msg_to_list(msg_list);
                /* Now, Process for deletion of this entry */
                goto error;
            }
        }
        if (sig_data->subjectText != NULL)
        {
            long srcLen = 0, dstLen = 0;
			srcLen = strlen(sig_data->subjectText);
			dstLen = (MMS_MAX_SUBJECT_LEN - 1) * sizeof(kal_wchar);
			msf_charset_utf8_to_ucs2le(sig_data->subjectText , 
									 &srcLen,
									 (char*)large_data_st->subject, 
									 &dstLen);
        }
        if (sig_data->fromAddress != NULL)
        {
            large_data_st->from_address_type = translate_mms_address_type_to_mma(sig_data->fromAddrType);
            if(large_data_st->from_address_type != MMA_ADDR_TYPE_NONE)
            {
                long srcLen = 0, dstLen = 0;
			    srcLen = strlen(sig_data->fromAddress);
                dstLen = (MMA_MAX_ADDR_LEN - 1) * sizeof(kal_wchar);
                msf_charset_utf8_to_ucs2le(sig_data->fromAddress, 
                                     &srcLen,
                                     (char *)large_data_st->from_address, 
                                     &dstLen);
            }
        }
    }
    else 
    {
        ASSERT(0);
    }
    /* make the status as NORMAL, as the enum default value is not correct */ 
    msg_list->user_can_not_see = TRUE;
    msg_list->receive_date = MSF_TIME_GET_SECURE_CLOCK(); 
    property_st->folder = MMA_FOLDER_INBOX;
    property_st->msg_sim_id = msg_list->msg_sim_id;
    property_st->reserve_space = MMA_MSGMGR_IS_RECENT_EVT;
    mma_msgmgr_add_msg_to_list(msg_list);
    /* error handling check */
    msg_file_path = MMAlib_getMessagePath(MSF_MODID_MMA, msg_list->msg_id);
    ASSERT(msg_file_path);
    if ((msg_size = MSF_FILE_GETSIZE_EXT(msg_file_path, mma_get_mms_type_message_storage(msg_list->msg_id))) <= 0)
    {
        MMA_FREE(msg_file_path);
        result = MMA_RESULT_FAIL_FILE_EMPTY;
        mms_result = MMS_RESULT_FILE_READ_ERROR;
        goto error;
    }
    MMA_FREE(msg_file_path);
    /* msg_size is the mms header+ body size. in this case, there is only header, which is the file size */
    property_st->msg_size = msg_size;
    if(new_msg_source == MMA_MSGMGR_GET_FROM_NOTIFICATION)
    {
        /* it is the downloaded mms size */
        property_st->msg_size = ((MmsMsgReplyNotification*)data)->size;
    }
    property_st->user_elements_size = msg_size;
    property_st->suffix = msg_list->suffix;
    property_st->msg_type = (MSF_UINT8) translate_mms_msg_type_to_mma((MmsFileType)msg_list->suffix);
    msg_list->mms_msg_type = property_st->msg_type;
    property_st->receive_date = msg_list->receive_date;
  
    /* generate the checksum file. Only create a file with the checksum */
    mms_result = MMSlib_genChkSumFile(MMA_TRANSLATE_MSG_ID(msg_list->msg_id), 
                (MmsFileType)msg_list->suffix, (kal_uint8)mma_get_mms_type_message_storage(msg_list->msg_id), 
                property_st, large_data_st);
    result = translate_mms_result_to_mma(mms_result);
    if (result != MMA_RESULT_OK)
    {
        goto error;
    }
	/* Update the entry in AddrObj File for DR & RR */
	if((new_msg_source == MMA_MSGMGR_GET_FROM_READ_REPORT) || 
		(new_msg_source == MMA_MSGMGR_GET_FROM_DELIVERY_REPORT))
	{
		mms_msg_addr_info_struct *addr = NULL;
		kal_uint8 storage_type = 0;
        kal_uint32 orig_msg_id = 0;

		if (large_data_st->java_reply_app_id != NULL)
        {
            orig_msg_id = MMSlib_mmsGetMsgId((char*)large_data_st->java_reply_app_id, &storage_type);
        }
		if(orig_msg_id > 0)
		{
			addr = (mms_msg_addr_info_struct*)MMA_CALLOC(sizeof(mms_msg_addr_info_struct));
			addr->addr_type = large_data_st->from_address_type;
			if(new_msg_source == MMA_MSGMGR_GET_FROM_DELIVERY_REPORT)
			{
				addr->dr_status = property_st->msg_report_status;                            
			}
			else
			{
				addr->rr_status = property_st->msg_report_status;
			}
			app_ucs2_strncpy((kal_int8*) addr->address,
					 (const MSF_INT8*)large_data_st->from_address,
					 MMS_MAX_ADDR_DATA_LEN - 1);
			MMSlib_UpdateAddrObjFile(orig_msg_id, storage_type, addr);
			MMA_FREE(addr);	
		}		
	}
    
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    /* Check the storage is proper or not */
    preferred_storage = mma_setting_get_preffered_storage();
    if(mma_get_message_storage(msg_list->msg_id) != preferred_storage)
    {
        /* check if the max mms state is reached */
        if(((mma_get_message_storage(msg_list->msg_id) == MMA_MSG_STORAGE_PHONE) && (g_mma_msgmgr_cntx.mms_folder_status.total_phone_mms < (wap_custom_get_max_mms_num() - 1))) ||
        	((mma_get_message_storage(msg_list->msg_id) == MMA_MSG_STORAGE_CARD1) && (g_mma_msgmgr_cntx.mms_folder_status.total_mcard_mms < wap_custom_get_max_mms_num_on_card())))
        {
            /* send a primitive to lower layer. After get the response from the lower layer, update the entry */
            MMA_MSGMGR_MSG_SET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_NEED_MOVE_MSG);
            MMSif_moveMessage(
                        MSF_MODID_MMA,
                        MMA_TRANSLATE_MSG_ID(msg_list->msg_id),
                        msg_list->suffix,
                        (MSF_UINT8) mma_get_mms_type_message_storage(msg_list->msg_id),
                        (MSF_UINT8) translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)preferred_storage), FALSE);
            MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_UPDATING_MSG_LIST);
            mma_msgmgr_send_int_perform_msg_oper_ind();
        }        
    }
    else
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
    {
        /* send the new mms ind */
        //g_mma_msgmgr_cntx.new_msg_state = MMA_MSGMGR_GET_FROM_NONE;
    #if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
        /* Add the message in the recent event list */
        mma_msgmgr_add_msg_to_recent_evt_list(msg_list->msg_id, msg_list->receive_date, msg_list->suffix);
    #endif
        MMA_MSGMGR_MSG_SET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_NEED_SEND_NEW_MSG_IND);
        mma_msgmgr_send_int_perform_msg_oper_ind();
    #ifdef __MMI_SLIM_MMS_2__
        if(new_msg_source == MMA_MSGMGR_GET_FROM_NOTIFICATION)
        {
            /* send the ok result to SEND_RECV Module */
            /* case consider, notification req, fail to save mms PDU with reason other than mem_FULL */
            MMA_SIGNAL_SENDTO_I(
                    MMA_SUBMODULE_MSG_SENDRECV,
                    MMA_INT_SIG_TYPE_MSG_MMS_OBJ_RES,
                    ((MmsMsgReplyNotification*) data)->result);
        }
    #endif /* __MMI_SLIM_MMS_2__ */
    }
    /* Free the memory */
    MMA_FREE(property_st);
    MMA_FREE(large_data_st);
    return result;
error:        
    /* delete the entry from the message list */
    /* we can delete the entry of the MSG_ID in the list after the genchksum success case. 
    but adding it before help to delete it from the FLDR list */
    msg_list->flag = 0;
    MMA_MSGMGR_MSG_SET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_DELETE);
    /* Till now, the entry of the mms is not updated. After delete, when reduce the count create error */
    //mma_msgmgr_update_mms_folder_status(msg_list, FALSE, 0, msg_list->folder);
    if (MMA_MSGMGR_GET_STATE() == MMA_MSGMGR_STATE_READY)
    {
        MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_UPDATING_MSG_LIST);
        mma_msgmgr_send_int_perform_msg_oper_ind();
    }
#ifdef __MMI_SLIM_MMS_2__
    if(new_msg_source == MMA_MSGMGR_GET_FROM_NOTIFICATION)
    {
        if(((MmsMsgReplyNotification*) data)->result == MMS_RESULT_OK_MEM_FULL)
        {
            /* if fail due to mem full */
            mms_result = MMS_RESULT_INSUFFICIENT_PERSISTENT_STORAGE;
        }
        /* case of fail to save mms PDU with reason other than MEM_FULL
        send the actual reason come, if the notification does not get saved */
        MMA_SIGNAL_SENDTO_I(
                MMA_SUBMODULE_MSG_SENDRECV,
                MMA_INT_SIG_TYPE_MSG_MMS_OBJ_RES,
                mms_result);
    }
#endif /* __MMI_SLIM_MMS_2__ */
    /* Free the memory */
    MMA_FREE(property_st);
    MMA_FREE(large_data_st);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_add_new_message_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id                          [IN]        
 *  new_msg_source                  [IN]        
 *  def_ori_msg_id                  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mma_result_enum mma_msgmgr_add_new_message_req_hdlr(
        kal_uint32 msg_id,
        mma_msgmgr_new_message_source_enum new_msg_source,
        kal_uint32 def_ori_msg_id,
        kal_uint32 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_list;
    char *msg_file_path = NULL;
    mma_result_enum result = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_msg_source != MMA_MSGMGR_GET_FROM_CREATE)
    {
        if (MMA_MSGMGR_GET_STATE() != MMA_MSGMGR_STATE_READY)
        {
            mma_send_int_sig(
                &(g_mma_msgmgr_cntx.pending_req_list),
                MMA_SUBMODULE_MSG_MGR,
                MMA_INT_SIG_TYPE_MSG_UPDATE_NEW_MSG_REQ,
                msg_id,
                new_msg_source,
                def_ori_msg_id,
                sim_id,
                NULL);
            return result;
        }
    }
    /* add this msg into msg list */
    msg_list = (mma_msg_info_list_struct*) MMA_CALLOC(sizeof(mma_msg_info_list_struct));
    /* Assume that the message ID is already Encoded */
    msg_list->msg_id = msg_id;
    if(new_msg_source == MMA_MSGMGR_GET_FROM_CREATE)
    {
        msg_list->folder = MMA_FOLDER_HIDDEN;
        msg_list->suffix = MMS_SUFFIX_SEND_REQ;
        /* Check for the correct Folder & suffix in case of Default template */
        {
            mma_msgmgr_new_msg_info_struct *new_msg_info = NULL;
            mma_msgmgr_create_info_struct *info = NULL;
			            
            if((new_msg_info = mma_msgmgr_get_new_msg_info_by_msg_id(msg_id)) != NULL)
            {
                info = (mma_msgmgr_create_info_struct*) new_msg_info->data;
                if(new_msg_info->msg_type != MMA_MSGMGR_MSG_TYPE_USER_CREATE)
                {
                    /* case of DRM encoded receive mms */
                    msg_list->folder = MMA_FOLDER_INBOX;
                    msg_list->suffix = MMS_SUFFIX_MSG;
                }
                if(info && (info->msg_filetype == MMS_SUFFIX_TEMPLATE))
                {
                    msg_list->folder = MMA_FOLDER_TEMPLATE;
                    msg_list->suffix = MMS_SUFFIX_TEMPLATE;
                }
				if((info) && (info->app_id == MMA_APP_ID_JSR) && (info->mode == MMA_MODE_UPLOAD))
				{
					msg_list->folder = MMA_FOLDER_DRAFT;
				}
                /* this state is taken form the new_msg_info as it clearly indiicate that from which module 
                are creating this MMS i.e from create , notification or delay */
                msg_list->new_msg_state = new_msg_info->new_msg_state;
                msg_list->def_noti_msg_id = new_msg_info->def_noti_msg_id;
            }
        }
    }
    else
    {
        msg_list->folder = MMA_FOLDER_INBOX;
        msg_list->suffix = MMS_SUFFIX_MSG;
    }

    msg_list->user_can_not_see = TRUE;
    /* ashok added code for DUal SIM */
    msg_list->msg_sim_id = (kal_uint8) sim_id;
    msg_list->receive_date = MSF_TIME_GET_SECURE_CLOCK();
    mma_msgmgr_add_msg_to_list(msg_list);
    /* error handling check */
    msg_file_path = MMAlib_getMessagePath(MSF_MODID_MMA, msg_id);
    ASSERT(msg_file_path);
    if (MSF_FILE_GETSIZE_EXT(msg_file_path, mma_get_mms_type_message_storage(msg_list->msg_id)) <= 0)
    {
        MMA_FREE(msg_file_path);
        result = MMA_RESULT_FAIL_FILE_EMPTY;
        goto error;
    }
    MMA_FREE(msg_file_path);
      
    if ((new_msg_source == MMA_MSGMGR_GET_FROM_MESSAGE) || (new_msg_source == MMA_MSGMGR_GET_FROM_DEFERRED_DOWNLOAD))
    {
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
		mma_msgmgr_new_msg_info_struct *new_msg_info = NULL;
        kal_char file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];
        int fh = 0;

        MMA_MSGMGR_MSG_SET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_NEED_DRM_ENCODE);

        new_msg_info = (mma_msgmgr_new_msg_info_struct*) MMA_CALLOC(sizeof(mma_msgmgr_new_msg_info_struct));
        new_msg_info->msg_id = msg_list->msg_id;
        new_msg_info->state = MMA_MSGMGR_MSG_STATE_STARTED;
        new_msg_info->req_id = mma_get_request_id();
		new_msg_info->next = NULL;
        if(new_msg_source == MMA_MSGMGR_GET_FROM_MESSAGE)
        {
            new_msg_info->msg_type = MMA_MSGMGR_MSG_TYPE_PUSH;
            new_msg_info->new_msg_state = MMA_MSGMGR_GET_FROM_MESSAGE;
        }
        else
        {
            new_msg_info->msg_type = MMA_MSGMGR_MSG_TYPE_DEFER_DOWNLOAD;
            new_msg_info->new_msg_state = MMA_MSGMGR_GET_FROM_DEFERRED_DOWNLOAD;
        }
        if (mma_msgmgr_add_new_msg_info_to_list(new_msg_info) == FALSE)
        {
            ASSERT(0);
        }
        mma_msgmgr_get_encode_filepath(msg_list->msg_id, file_path);
        if ((fh = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, file_path, 
                                        MSF_FILE_SET_CREATE_ALWAYS | MSF_FILE_SET_WRONLY, 
                                        wap_custom_get_max_mms_msg_size(), 
                                        mma_get_message_storage(msg_list->msg_id))) >= 0)
        {
            MSF_FILE_CLOSE(fh);
        }
        else
        {
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_CAN_NOT_OCCUPY_ENCODE_FILE_SPACE, 
                         "MMA MSGMGR can't occupy encode file space for new msg %d", msg_list->msg_id));
            mma_msgmgr_free_new_msg_info(new_msg_info->req_id);
            MMA_MSGMGR_MSG_UNSET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_NEED_DRM_ENCODE);
        }
#endif
		if(new_msg_source == MMA_MSGMGR_GET_FROM_MESSAGE)
        {
            msg_list->new_msg_state = MMA_MSGMGR_GET_FROM_MESSAGE; 
            msg_list->def_noti_msg_id = def_ori_msg_id; /* def_ori_msg_id is msg_id of the notification of the download message */
        }
        else
        {
            msg_list->new_msg_state = MMA_MSGMGR_GET_FROM_DEFERRED_DOWNLOAD;        /* for deferred download message */
            msg_list->def_noti_msg_id = def_ori_msg_id; /* def_ori_msg_id is msg_id of the notification of the deferred download message */
        }        
    } 
    else if(new_msg_source != MMA_MSGMGR_GET_FROM_CREATE)
    {
        /* Only 3 cases should come */
        ASSERT(0);
    }
    /* ashok set the flag for parse for non-encoding flow */
    MMA_MSGMGR_MSG_SET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_NEED_PARSE);
    mma_msgmgr_send_int_perform_msg_oper_ind();
    return result;
error:
    /* We need to reply CREATE_RSP to Create module */
    /* no need to do here, case of dangling pointer for the new_msg_info */    
    if (new_msg_source == MMA_MSGMGR_GET_FROM_MESSAGE)
    {
        /* Ashok need to implement the code for removing this msg_id and save the notification msg */
        /* get the context from the global context for the notif ID */
        mma_msgmgr_recv_notif_data_struct *notif_data = mma_msgmgr_remove_msg_notif_data(def_ori_msg_id);
        if(notif_data != NULL)
        {
            /* case of fail to save mms PDU with reason other than MEM_FULL
            send the correct result to SEND_RECV Module, if the notification get saved */
            notif_data->data->result = MMS_RESULT_OK;
            mma_msgmgr_add_new_report_notif_req_hdlr( MMA_MSGMGR_GET_FROM_NOTIFICATION, notif_data->data);
            mma_msgmgr_free_msg_notif_data(notif_data);
        }
    }
    else if (new_msg_source == MMA_MSGMGR_GET_FROM_DEFERRED_DOWNLOAD)
    {
        /* Ashok, as new message info struct is not created. No need to free */
        mma_sendrecv_msgmgr_download_rsp_hdlr(MMS_RESULT_INSUFFICIENT_PERSISTENT_STORAGE, 0);
    }
    /* delete the entry from the message list */
    /* we can the entry of the MSG_ID in the list after the genchksum success case. 
    but ading it before help to delete it from the FLDR list */
    msg_list->flag = 0;
    MMA_MSGMGR_MSG_SET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_DELETE);
    /* Till now, the entry of the mms is not updated. After delete, when reduce the count create error */
    //mma_msgmgr_update_mms_folder_status(msg_list, FALSE, 0, msg_list->folder);
    if (MMA_MSGMGR_GET_STATE() == MMA_MSGMGR_STATE_READY)
    {
        MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_UPDATING_MSG_LIST);
        mma_msgmgr_send_int_perform_msg_oper_ind();
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_check_any_pending_int_parse_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void mma_msgmgr_check_any_pending_int_parse_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_list_p = g_mma_msgmgr_cntx.msg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (msg_list_p)
    {
        if (MMA_MSGMGR_MSG_CHK_FLAG(msg_list_p->flag, MMA_MSGMGR_MSG_OPER_INT_PARSE_REQ_SUSPEND))
        {
            MMA_MSGMGR_MSG_UNSET_FLAG(msg_list_p->flag, MMA_MSGMGR_MSG_OPER_INT_PARSE_REQ_SUSPEND);
            MMA_MSGMGR_MSG_SET_FLAG(msg_list_p->flag, MMA_MSGMGR_MSG_OPER_NEED_PARSE);
            return;
        }
        msg_list_p = msg_list_p->next;
    }
}
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_parser_get_msg_info_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id              [IN]        
 *  result              [IN]        
 *  msg_content_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_parser_get_msg_info_hdlr(
                kal_uint32 msg_id,
                mma_result_enum result,
                mms_msg_info_struct *msg_content_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_p = NULL;
    //mma_msgmgr_new_msg_info_struct *new_msg_info = NULL;
    kal_uint8 preferred_storage = mma_setting_get_preffered_storage();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_PARSER_GET_MSG_INFO_REQ_HDLR, "mma_msgmgr_parser_get_msg_info_hdlr(): msg %d, result %d", msg_id, result));
	/* first check for any other pending Parse message in list */
    g_mma_msgmgr_cntx.count_int_parse_req = FALSE;
    mma_msgmgr_check_any_pending_int_parse_msg();
    /* Check END */
    if (result == MMA_RESULT_OK)
    {
        /* Parsing is OK */
        ASSERT(msg_content_p);
        msg_p = mma_msgmgr_get_msg_from_list(msg_id);
        if (msg_p != NULL)
        {
			MMA_MSGMGR_MSG_UNSET_FLAG(msg_p->flag, MMA_MSGMGR_MSG_OPER_PARSE_REQ_SENT);
		#ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
			if (msg_content_p->property->user_elements_size > wap_custom_get_max_mms_msg_size())
			{
				result = MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED;
				MMA_FREE(msg_content_p->large_data);
				MMA_FREE(msg_content_p->property);
				MMA_FREE(msg_content_p);
			}
		#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
            if (result == MMA_RESULT_OK)
			{
                msg_p->is_read = msg_content_p->property->is_read;
                /* Ashok put check as read status for suffix MMS_SUFFIX_SEND_REQ */
                if((msg_p->suffix == MMS_SUFFIX_SEND_REQ) || (msg_p->suffix == MMS_SUFFIX_TEMPLATE))
                {
                    msg_p->is_read = 1;
                    msg_content_p->property->is_read = 1;
                }
                
                /* write code for update the folder in checksum file */
                msg_content_p->property->folder = msg_p->folder;
                /* ashok need to write code for the Dual SIm */
                if(msg_p->msg_sim_id == 0)
				{
					msg_p->msg_sim_id = MMA_SIM_ID_SIM_UNCLASSIFIED;
				}
				msg_content_p->property->msg_sim_id = msg_p->msg_sim_id;
                msg_content_p->property->suffix = msg_p->suffix;
                msg_content_p->property->receive_date = msg_p->receive_date;
                if (msg_p->folder == MMA_FOLDER_INBOX)
				{
					msg_content_p->property->reserve_space = MMA_MSGMGR_IS_RECENT_EVT;
				}
				
                /* Make the Java mms in Draft folder as normal MMS */
                if((msg_p->folder != MMA_FOLDER_INBOX) && (msg_content_p->property->msg_type == MMA_MSG_TYPE_JAVA))
                {
                    /* to make the uploaded Java mms in Draft folder as normal MMS */
                    msg_content_p->property->msg_type = MMA_MSG_TYPE_MMS;
                }
                msg_p->mms_msg_type = msg_content_p->property->msg_type;
                msg_p->mms_priority = msg_content_p->property->priority;
#ifdef __COSMOS_MMI_PACKAGE__
                /* latest version mms Checksum file. Only used to differentiate the mms functionality. No other check required. */
                msg_content_p->large_data->app_data[MMA_MSGMGR_INT_VERSION_POS] = (kal_uint8)1;
#else
                msg_content_p->large_data->app_data[MMA_MSGMGR_INT_VERSION_POS] = (kal_uint8)0;
#endif
                result = translate_mms_result_to_mma(MMSlib_genChkSumFile(MMA_TRANSLATE_MSG_ID(msg_p->msg_id), 
                    (MmsFileType)msg_p->suffix, (kal_uint8)mma_get_mms_type_message_storage(msg_p->msg_id), 
                    msg_content_p->property, msg_content_p->large_data));
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                          MMA_MSGMGR_NEED_UPDATE_CHECKSUM_MSGID_RETURN_VALUE, "Create the msg %d's checksum file,ret:%d.",
                          msg_p->msg_id, result));
                if(result != MMA_RESULT_OK)
                {
                    goto error;
                }
                
            #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
                /* Check the proper storage of the Received MMS */
                if((msg_p->folder == MMA_FOLDER_INBOX) && (mma_get_message_storage(msg_p->msg_id) != preferred_storage))
                {
                    /* send a primitive to lower layer. After get the response from the lower layer, update the entry */
                    MMA_MSGMGR_MSG_SET_FLAG(msg_p->flag, MMA_MSGMGR_MSG_OPER_NEED_MOVE_MSG);
                    MMSif_moveMessage(
                                MSF_MODID_MMA,
                                MMA_TRANSLATE_MSG_ID(msg_p->msg_id),
                                msg_p->suffix,
                                (MSF_UINT8) mma_get_mms_type_message_storage(msg_p->msg_id),
                                (MSF_UINT8) translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)preferred_storage), FALSE);
                    MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_UPDATING_MSG_LIST);
                    //mma_msgmgr_send_int_perform_msg_oper_ind();
                }
                else
            #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
                {
                    /* check for deferred downloaded mms */
                    if (msg_p->new_msg_state == MMA_MSGMGR_GET_FROM_DEFERRED_DOWNLOAD) /* deferred download */
                    {
                        msg_p->new_msg_state = MMA_MSGMGR_GET_FROM_NONE;
                        MMA_MSGMGR_MSG_SET_FLAG(msg_p->flag, MMA_MSGMGR_MSG_OPER_REPLY_DOWNLOAD_RSP);
                        MMA_MSGMGR_MSG_SET_FLAG(msg_p->flag, MMA_MSGMGR_MSG_OPER_NEED_SEND_NEW_MSG_IND);
                    }
                    /* ashok write code for the Immediate downloaded message */
                    else if (msg_p->new_msg_state == MMA_MSGMGR_GET_FROM_MESSAGE) /* download full message */
                    {
                        msg_p->new_msg_state = MMA_MSGMGR_GET_FROM_NONE;
                        /* ashok set flag to delete the notification msg_id */
                        /* ashok need to create a new flag for it as this notif id is not present in the message list */
                        MMA_MSGMGR_MSG_SET_FLAG(msg_p->flag, MMA_MSGMGR_MSG_OPER_DELETE_DOWNLOAD_MSG_NOTIFID_IND);
                        MMA_MSGMGR_MSG_SET_FLAG(msg_p->flag, MMA_MSGMGR_MSG_OPER_NEED_SEND_NEW_MSG_IND);
                    }
                #if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
                    /* Add the message in the recent event list */
                    if(msg_p->folder == MMA_FOLDER_INBOX)
                    {
                        mma_msgmgr_add_msg_to_recent_evt_list(msg_p->msg_id, msg_p->receive_date, msg_p->suffix);
                    }
                #endif
                }
                /* Case of user created mms */
                if (msg_p->new_msg_state == MMA_MSGMGR_GET_FROM_CREATE)       /* from create module */
                {
                    msg_p->new_msg_state = MMA_MSGMGR_GET_FROM_NONE;
                    MMA_MSGMGR_MSG_SET_FLAG(msg_p->flag, MMA_MSGMGR_MSG_OPER_NEED_SEND_CREATE_MMS_RSP);
                }
                /* free the memory */
                MMA_FREE(msg_content_p->property);
                MMA_FREE(msg_content_p->large_data);
                MMA_FREE(msg_content_p);
                mma_msgmgr_send_int_perform_msg_oper_ind();
				return;
			}
			else
			{
				goto error;
			}
        }
		else
		{
			ASSERT(0);
		}
		return;
    }
	else
	{
		goto error;
	}
error:
        msg_p = mma_msgmgr_get_msg_from_list(msg_id);
        if (msg_p != NULL)
        {
            /* ashok need to check for the drm encoding macro i.e. DRM support macro off case */            
            mma_msgmgr_new_msg_info_struct *new_msg_info = NULL;
			new_msg_info = mma_msgmgr_get_new_msg_info_by_msg_id(msg_id);
			/* Check if we need to send create MMS response to MMA create module */
            if (msg_p->new_msg_state == MMA_MSGMGR_GET_FROM_CREATE)
            {
				mma_msgmgr_create_info_struct *info = NULL;
				if(new_msg_info == NULL)
				{
					ASSERT(0);
				}
				info = (mma_msgmgr_create_info_struct*) new_msg_info->data;
				g_mma_msgmgr_cntx.process_create_req_num--;
				/* send MSG_ID_UM_NEW_MSG_IND to application */
				mma_create_send_reject_rsp(
					(module_type) (kal_uint32) info->source,
					info->req_id,
					info->app_id,
					info->msg_id,
					info->buffer_index,
					result);
            }
            else if (msg_p->new_msg_state == MMA_MSGMGR_GET_FROM_DEFERRED_DOWNLOAD)
            {
                if(result == MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED)
				{
					mma_sendrecv_msgmgr_download_rsp_hdlr(MMS_RESULT_MAX_RETRIEVAL_SIZE_EXCEEDED, 0);
				}
				else
				{
					mma_sendrecv_msgmgr_download_rsp_hdlr(MMS_RESULT_COMM_ILLEGAL_PDU, 0);
				}
            }
            /* ashok need to write code for the MESSAGE type received msg fail case */
            else if (msg_p->new_msg_state == MMA_MSGMGR_GET_FROM_MESSAGE)
            {
                /* Ashok need to implement the code for removing this msg_id and save the notification msg */
                /* get the context from the global context for the notif ID */
                mma_msgmgr_recv_notif_data_struct *notif_data = mma_msgmgr_remove_msg_notif_data(msg_p->def_noti_msg_id);
                if(notif_data != NULL)
                {
                    if(result == MMA_RESULT_FAIL_INSUFFICIENT_MEMORY)
                    {
                        notif_data->data->result = MMS_RESULT_OK_MEM_FULL;
                    }
                    else
                    {
                        /* Reason other than memory full. Save the notification & send OK result */
                        notif_data->data->result = MMS_RESULT_OK;
                    }
                    mma_msgmgr_add_new_report_notif_req_hdlr( MMA_MSGMGR_GET_FROM_NOTIFICATION, notif_data->data);
                    /* free the memory of the notif data */
                    mma_msgmgr_free_msg_notif_data(notif_data);
                }                
            }
			if(new_msg_info != NULL)
			{
				mma_msgmgr_free_new_msg_info(new_msg_info->req_id);
			}
            /* Till now, the entry of the mms is not updated. After delete, when reduce the count create error */
            //mma_msgmgr_update_mms_folder_status(msg_p, FALSE, 0, msg_p->folder);
            if (mma_main_is_in_usb_mode() == FALSE)
            {
                msg_p->flag = 0;
                MMA_MSGMGR_MSG_SET_FLAG(msg_p->flag, MMA_MSGMGR_MSG_OPER_DELETE);
                if (MMA_MSGMGR_GET_STATE() == MMA_MSGMGR_STATE_READY)
                {
                    MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_UPDATING_MSG_LIST);
                    mma_msgmgr_send_int_perform_msg_oper_ind();
                }
            }
            else
            {
                /* We don't need to delete MMS message in USB mode. */
                msg_p = mma_msgmgr_remove_msg_from_list(msg_id);
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 					
                if (msg_p->flag & MMA_MSGMGR_MSG_OPER_NEED_SEND_DELETE_RSP)
                {
					mma_msgmgr_req_info_struct *delete_req = (mma_msgmgr_req_info_struct*) g_mma_msgmgr_cntx.delete_req;
					mms_mma_send_delete_msg_rsp(
						(module_type) (kal_uint32) delete_req->source,
						(kal_uint8) delete_req->app_id,
						(kal_uint32*)delete_req->result,
						(kal_uint32) delete_req->req_id,
						(kal_uint32*) delete_req->msg_id,
						delete_req->no_of_msg);
					MMA_FREE(delete_req->result);
					MMA_FREE(delete_req->msg_id);
                    MMA_FREE(delete_req);
					g_mma_msgmgr_cntx.delete_req = NULL;
                }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
				if (g_mma_msgmgr_cntx.source_module && g_mma_msgmgr_cntx.user_data)
                {
                    if (msg_p->flag & MMA_MSGMGR_MSG_OPER_NEED_SEND_UM_DELETE_FOLDER_RSP)
                    {
                        srv_um_delete_folder_req_struct *delete_folder_req =
                            (srv_um_delete_folder_req_struct*) g_mma_msgmgr_cntx.user_data;
                        mms_mma_send_delete_folder_rsp(
                            (module_type) (kal_uint32) g_mma_msgmgr_cntx.source_module,
                            delete_folder_req->app_id,
                            SRV_UM_MSG_MMS,
                            (g_mma_msgmgr_cntx.delete_result == MMA_RESULT_OK) ? KAL_TRUE : KAL_FALSE);
                        MMA_FREE(delete_folder_req);
                    }
                }
                MMA_FREE(msg_p);
                mma_msgmgr_send_int_perform_msg_oper_ind();
            }
        }
        else
        {
            ASSERT(0);
        }
        /* free the memory */
        if(msg_content_p && msg_content_p->property)
        {
            MMA_FREE(msg_content_p->property);
        }
        if(msg_content_p && msg_content_p->large_data)
        {
            MMA_FREE(msg_content_p->large_data);
        }
        if(msg_content_p)
        {
            MMA_FREE(msg_content_p);
        }
}


#ifndef MMA_JSR_PST_MMS_OPERATON_SUPPORT 
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_msg_num_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source                  [IN]        
 *  get_um_msg_num_req      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_get_msg_num_req_hdlr(module_type source, wap_mma_get_msg_num_req_struct *get_msg_num_req)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_mma_get_msg_num_rsp_struct get_msg_num_rsp = {0};
    //mma_msgmgr_app_msg_num_status_struct app_msg_num_status = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	get_msg_num_rsp.result = MMA_RESULT_FAIL;

    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                           MMA_MSGMGR_UMMS_GET_MSG_NUM_REQ_MMA_NOT_READY, "(mma_msgmgr.c): MMA is not ready to get umms msg num\n"));

        mms_mma_send_get_msg_num_rsp(
            source,
            get_msg_num_req->app_id,
			get_msg_num_req->req_id,
            KAL_FALSE,
			get_msg_num_rsp);
    }
    else if (mma_main_is_in_usb_mode() == TRUE)
    {
        mms_mma_send_get_msg_num_rsp(
            source,
            get_msg_num_req->app_id,
			get_msg_num_req->req_id,
            KAL_TRUE,
			get_msg_num_rsp);
    }
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    else if(MMA_MSGMGR_STATE_CREATE_CARD_PLUG_IN_MSG_LIST == MMA_MSGMGR_GET_STATE())
    {
        /* check whether get list of memory card is in progress */
        mma_send_int_sig(
            &(g_mma_msgmgr_cntx.pending_req_list),
            MMA_SUBMODULE_MSG_MGR,
            MMA_INT_SIG_TYPE_MSG_GET_MSG_NUM_REQ,
            source,
            0,
            0,
            0,
            get_msg_num_req);
		return;
    }
#endif  /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
	else if (mma_msgmgr_give_msg_info_to_app() == FALSE)
    {
        mma_send_int_sig(
            &(g_mma_msgmgr_cntx.pending_req_list),
            MMA_SUBMODULE_MSG_MGR,
            MMA_INT_SIG_TYPE_MSG_GET_MSG_NUM_REQ,
            source,
            0,
            0,
            0,
            get_msg_num_req);
		return;
    }
    else
    {
        kal_uint8 i = 0;
		while(i < MMA_MAX_MSG_NUM_QUERY_NUM)
		{
			if(get_msg_num_req->req_tb[i] == 0)
				break;
			switch (get_msg_num_req->req_tb[i])
			{
				case MMA_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM1:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM1].inbox_unread_msg_num;
					break;
            #if (MMI_MAX_SIM_NUM >= 2)
				case MMA_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM2:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM2].inbox_unread_msg_num;
					break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                case MMA_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM3:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM3].inbox_unread_msg_num;
					break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
				case MMA_QUERY_OPTION_NUM_UNREAD_INBOX_MSG_SIM4:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM4].inbox_unread_msg_num;
					break;
            #endif
				case MMA_QUERY_OPTION_NUM_TOTAL_UNREAD_INBOX_MSG:
                    {
                        int loop = 0;
                        for(loop = 0; loop <= MMA_MAX_SIM_COUNT; loop++)
                        {
					        get_msg_num_rsp.rsp_tb[i] += g_mma_msgmgr_cntx.mms_folder_status.folder[loop].inbox_unread_msg_num;
                        }
                    }
					break;
				case MMA_QUERY_OPTION_NUM_TOTAL_INBOX_SIM1:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM1].inbox_read_msg_num + 
                                        g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM1].inbox_unread_msg_num;
					break;
            #if (MMI_MAX_SIM_NUM >= 2)
				case MMA_QUERY_OPTION_NUM_TOTAL_INBOX_SIM2:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM2].inbox_read_msg_num + 
                                        g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM2].inbox_unread_msg_num;
					break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                case MMA_QUERY_OPTION_NUM_TOTAL_INBOX_SIM3:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM3].inbox_read_msg_num + 
                                        g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM3].inbox_unread_msg_num;
					break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
				case MMA_QUERY_OPTION_NUM_TOTAL_INBOX_SIM4:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM4].inbox_read_msg_num + 
                                        g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM4].inbox_unread_msg_num;
					break;
            #endif
				case MMA_QUERY_OPTION_NUM_TOTAL_INBOX_MSG:
                {
                    int loop = 0;
                    for(loop = 0; loop <= MMA_MAX_SIM_COUNT; loop++)
                    {
					    get_msg_num_rsp.rsp_tb[i] += (g_mma_msgmgr_cntx.mms_folder_status.folder[loop].inbox_unread_msg_num + 
                                            g_mma_msgmgr_cntx.mms_folder_status.folder[loop].inbox_read_msg_num);
                    }
                }
					break;
				case MMA_QUERY_OPTION_NUM_TOTAL_OUTBOX_SIM1:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM1].unsent_msg_num;
					break;
            #if (MMI_MAX_SIM_NUM >= 2)
				case MMA_QUERY_OPTION_NUM_TOTAL_OUTBOX_SIM2:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM2].unsent_msg_num;
					break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                case MMA_QUERY_OPTION_NUM_TOTAL_OUTBOX_SIM3:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM3].unsent_msg_num;
					break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
				case MMA_QUERY_OPTION_NUM_TOTAL_OUTBOX_SIM4:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM4].unsent_msg_num;
					break;
            #endif
				case MMA_QUERY_OPTION_NUM_TOTAL_OUTBOX_MSG:
                {
                    int loop = 0;
                    for(loop = 0; loop <= MMA_MAX_SIM_COUNT; loop++)
                    {
					    get_msg_num_rsp.rsp_tb[i] += g_mma_msgmgr_cntx.mms_folder_status.folder[loop].unsent_msg_num;
                    }
                }
					break;
				case MMA_QUERY_OPTION_NUM_TOTAL_SENT_SIM1:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM1].sent_msg_num;
					break;
            #if (MMI_MAX_SIM_NUM >= 2)
				case MMA_QUERY_OPTION_NUM_TOTAL_SENT_SIM2:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM2].sent_msg_num;
					break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                case MMA_QUERY_OPTION_NUM_TOTAL_SENT_SIM3:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM3].sent_msg_num;
					break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
				case MMA_QUERY_OPTION_NUM_TOTAL_SENT_SIM4:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM4].sent_msg_num;
					break;
            #endif
				case MMA_QUERY_OPTION_NUM_TOTAL_SENT_MSG:
                {
                    int loop = 0;
                    for(loop = 0; loop <= MMA_MAX_SIM_COUNT; loop++)
                    {
					    get_msg_num_rsp.rsp_tb[i] += g_mma_msgmgr_cntx.mms_folder_status.folder[loop].sent_msg_num;
                    }
                }
					break;
				case MMA_QUERY_OPTION_NUM_TOTAL_DRAFT_MSG:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.draft_msg_num;
					break;
                case MMA_QUERY_OPTION_NUM_UNREAD_ARCHIVE_MSG_SIM1:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM1].archive_unread_inbox_msg_num;
					break;
            #if (MMI_MAX_SIM_NUM >= 2)
				case MMA_QUERY_OPTION_NUM_UNREAD_ARCHIVE_MSG_SIM2:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM2].archive_unread_inbox_msg_num;
					break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                case MMA_QUERY_OPTION_NUM_UNREAD_ARCHIVE_MSG_SIM3:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM3].archive_unread_inbox_msg_num;
					break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
				case MMA_QUERY_OPTION_NUM_UNREAD_ARCHIVE_MSG_SIM4:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM4].archive_unread_inbox_msg_num;
					break;
            #endif
                case MMA_QUERY_OPTION_NUM_TOTAL_UNREAD_ARCHIVE_MSG:
                {
                    int loop = 0;
                    for(loop = 0; loop <= MMA_MAX_SIM_COUNT; loop++)
                    {
					    get_msg_num_rsp.rsp_tb[i] += g_mma_msgmgr_cntx.mms_folder_status.folder[loop].archive_unread_inbox_msg_num;
                    }
                }
					break;
				case MMA_QUERY_OPTION_NUM_TOTAL_ARCHIVE_SIM1:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM1].archive_sent_msg_num +
                                            g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM1].archive_read_inbox_msg_num +
                                            g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM1].archive_unread_inbox_msg_num;
					break;
            #if (MMI_MAX_SIM_NUM >= 2)
				case MMA_QUERY_OPTION_NUM_TOTAL_ARCHIVE_SIM2:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM2].archive_sent_msg_num +
                                        g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM2].archive_read_inbox_msg_num +
                                        g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM2].archive_unread_inbox_msg_num;
					break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                case MMA_QUERY_OPTION_NUM_TOTAL_ARCHIVE_SIM3:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM3].archive_sent_msg_num +
                                        g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM3].archive_read_inbox_msg_num +
                                        g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM3].archive_unread_inbox_msg_num;
					break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
				case MMA_QUERY_OPTION_NUM_TOTAL_ARCHIVE_SIM4:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM4].archive_sent_msg_num +
                                        g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM4].archive_read_inbox_msg_num +
                                        g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM4].archive_unread_inbox_msg_num;
					break;
            #endif
				case MMA_QUERY_OPTION_NUM_TOTAL_ARCHIVE_UNCLASSIFIED:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.archive_msg_num;
					break;
				case MMA_QUERY_OPTION_NUM_TOTAL_ARCHIVE_MSG:
                {
                    int loop = 0;
                    for(loop = 0; loop <= MMA_MAX_SIM_COUNT; loop++)
                    {
					    get_msg_num_rsp.rsp_tb[i] += (g_mma_msgmgr_cntx.mms_folder_status.folder[loop].archive_unread_inbox_msg_num + 
                                            g_mma_msgmgr_cntx.mms_folder_status.folder[loop].archive_read_inbox_msg_num +
                                            g_mma_msgmgr_cntx.mms_folder_status.folder[loop].archive_sent_msg_num );
                    }
                    get_msg_num_rsp.rsp_tb[i] += g_mma_msgmgr_cntx.mms_folder_status.archive_msg_num;
                }
					break;
				case MMA_QUERY_OPTION_NUM_TOTAL_USER_DEF_TEMPLATE_MSG:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.userdefined_template_msg_num;
					break;
				case MMA_QUERY_OPTION_NUM_TOTAL_PRE_DEF_TEMPLATE_MSG:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.predefined_template_msg_num;
					break;
				case MMA_QUERY_OPTION_NUM_TOTAL_UNREAD_MSG:
                {
                    int loop = 0;
                    for(loop = 0; loop <= MMA_MAX_SIM_COUNT; loop++)
                    {
					    get_msg_num_rsp.rsp_tb[i] += (g_mma_msgmgr_cntx.mms_folder_status.folder[loop].inbox_unread_msg_num + 
                                            g_mma_msgmgr_cntx.mms_folder_status.folder[loop].archive_unread_inbox_msg_num);
                    }
                }
					break;
                case MMA_QUERY_OPTION_NUM_UNREAD_TOTAL_MSG_SIM1:
					get_msg_num_rsp.rsp_tb[i] = (g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM1].inbox_unread_msg_num + 
                                                g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM1].archive_unread_inbox_msg_num);
					break;
            #if (MMI_MAX_SIM_NUM >= 2)
                case MMA_QUERY_OPTION_NUM_UNREAD_TOTAL_MSG_SIM2:
					get_msg_num_rsp.rsp_tb[i] = (g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM2].inbox_unread_msg_num + 
                                                g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM2].archive_unread_inbox_msg_num);
					break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 3)
                case MMA_QUERY_OPTION_NUM_UNREAD_TOTAL_MSG_SIM3:
					get_msg_num_rsp.rsp_tb[i] = (g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM3].inbox_unread_msg_num + 
                                                g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM3].archive_unread_inbox_msg_num);
					break;
            #endif
            #if (MMI_MAX_SIM_NUM >= 4)
				case MMA_QUERY_OPTION_NUM_UNREAD_TOTAL_MSG_SIM4:
					get_msg_num_rsp.rsp_tb[i] = (g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM4].inbox_unread_msg_num + 
                                                g_mma_msgmgr_cntx.mms_folder_status.folder[MMA_INDEX_FOR_SIM4].archive_unread_inbox_msg_num);
					break;
            #endif
                case MMA_QUERY_OPTION_NUM_TOTAL_PHONE_MSG:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.total_phone_mms;
					break;
				case MMA_QUERY_OPTION_NUM_TOTAL_CARD_MSG:
					get_msg_num_rsp.rsp_tb[i] = g_mma_msgmgr_cntx.mms_folder_status.total_mcard_mms;
					break;
				default:
					break;
			}
			i++;
		}

		mms_mma_send_get_msg_num_rsp(
            source,
            get_msg_num_req->app_id,
			get_msg_num_req->req_id,
            KAL_TRUE,
			get_msg_num_rsp);
    }
    MMA_FREE(get_msg_num_req);
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_msg_info_req_hdlr
 * DESCRIPTION
 *  This function is used to get the message info of a message.
 * PARAMETERS
 *  source                  [IN]        
 *  get_msg_info_req        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_get_msg_info_req_hdlr(module_type source, wap_mma_get_msg_info_req_struct *get_msg_info_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar subject_ucs2[MMA_MAX_SUBJECT_LEN] = {0};
    mma_msg_info_list_struct *msg_info = NULL;
    kal_uint32 msg_size = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(get_msg_info_req);

    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                           MMA_MSGMGR_GET_MSG_INFO_REQ_MMA_NOT_READY, "(mma_msgmgr.c): MMA is not ready to get msg info"));

        mms_mma_send_get_msg_info_rsp(
            source,
            get_msg_info_req->app_id,
            MMA_RESULT_FAIL_NOT_READY,
            get_msg_info_req->req_id,
            get_msg_info_req->msg_id,
            0,
            NULL,
            NULL,
            0,
            0,
            0,
            0,
            0,
            0,
            0,
            KAL_FALSE,
            KAL_FALSE,
            KAL_FALSE,
            KAL_FALSE,
            KAL_FALSE,
            KAL_FALSE,
            NULL,
            NULL,
            NULL,
            MMA_MEDIA_MSG_NONE,
            (MSF_UINT8) mma_get_message_storage(get_msg_info_req->msg_id),
            MMA_SIM_ID_SIM_UNCLASSIFIED,0);

    }
    else if (mma_msgmgr_check_busy_state_pending_list(source, MMA_INT_SIG_TYPE_MSG_GET_MSG_INFO_REQ, get_msg_info_req))
        return;
    else
    {
        mma_result_enum result = MMA_RESULT_OK;
        mms_msg_info_property_struct *property_st = NULL;
        mms_msg_info_large_data_struct *large_data_st = NULL;
        /* Check msg exist or not */
        msg_info = mma_msgmgr_get_msg_from_list(get_msg_info_req->msg_id);
        if(msg_info == NULL)
        {
            mms_mma_send_get_msg_info_rsp(
						source, get_msg_info_req->app_id,
						(kal_uint8) MMA_RESULT_FAIL_INVALID_MSGID,
						get_msg_info_req->req_id, get_msg_info_req->msg_id,
						0, NULL, NULL, 0,
						0, 0, 0, 0,
						0, 0, KAL_FALSE, KAL_FALSE,
						KAL_FALSE, KAL_FALSE,
						KAL_FALSE, KAL_FALSE,
						NULL, NULL, NULL,
						MMA_MEDIA_MSG_NONE,
                        (MSF_UINT8) mma_get_message_storage(get_msg_info_req->msg_id),
                        MMA_SIM_ID_SIM_UNCLASSIFIED,0);
            MMA_FREE(get_msg_info_req);
            return;
        }
		if(msg_info->mms_msg_type == MMA_MSG_TYPE_UNSUPPORTED)
        {
            mms_mma_send_get_msg_info_rsp(
						source, get_msg_info_req->app_id,
						(kal_uint8) MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE,
						get_msg_info_req->req_id, get_msg_info_req->msg_id,
						0, NULL, NULL, 0,
						0, 0, 0, 0,
						0, 0, KAL_FALSE, KAL_FALSE,
						KAL_FALSE, KAL_FALSE,
						KAL_FALSE, KAL_FALSE,
						NULL, NULL, NULL,
						MMA_MEDIA_MSG_NONE, 
                        (MSF_UINT8) mma_get_message_storage(get_msg_info_req->msg_id),
                        MMA_SIM_ID_SIM_UNCLASSIFIED,0);
            MMA_FREE(get_msg_info_req);
            return;
        }
        
        large_data_st = (mms_msg_info_large_data_struct*)MMA_CALLOC(sizeof(mms_msg_info_large_data_struct));
        ASSERT(large_data_st);                        
        property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));
        ASSERT(property_st);

        result = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(get_msg_info_req->msg_id),
                    (kal_uint8)mma_get_mms_type_message_storage(get_msg_info_req->msg_id),
                    property_st, large_data_st));

        if (result != MMA_RESULT_OK)
        {
            /* corrupt checksum or info file */
            mms_mma_send_get_msg_info_rsp(
                source,
                get_msg_info_req->app_id,
                (kal_uint8) MMA_RESULT_FAIL_FILE_CORRUPTED,
                get_msg_info_req->req_id,
                get_msg_info_req->msg_id,
                0,
                NULL,
                NULL,
                0,
                0,
                0,
                0,
                0,
                0,
                0,
                KAL_FALSE,
                KAL_FALSE,
                KAL_FALSE,
                KAL_FALSE,
                KAL_FALSE,
                KAL_FALSE,
                NULL,
                NULL,
                NULL,
                MMA_MEDIA_MSG_NONE,
                (MSF_UINT8) mma_get_message_storage(get_msg_info_req->msg_id),
                MMA_SIM_ID_SIM_UNCLASSIFIED,0);
        }
        else
        {
			if (mma_main_is_in_usb_mode() == FALSE)
			{
				/* check for the Corrupt Message file and info file */
				if (FALSE == MMSlib_isValidMmsMSg_Ext1((MmsMsgId) (MMA_TRANSLATE_MSG_ID(get_msg_info_req->msg_id)), (MmsFileType)property_st->suffix, 
                        (kal_uint8)mma_get_mms_type_message_storage(get_msg_info_req->msg_id)))
				{
					/* corrupt message or info file */
					mms_mma_send_get_msg_info_rsp(
						source,
						get_msg_info_req->app_id,
						(kal_uint8) MMA_RESULT_FAIL_FILE_CORRUPTED,
						get_msg_info_req->req_id,
						get_msg_info_req->msg_id,
						0,
						NULL,
						NULL,
						0,
						0,
						0,
						0,
						0,
						0,
						0,
						KAL_FALSE,
						KAL_FALSE,
						KAL_FALSE,
						KAL_FALSE,
						KAL_FALSE,
						KAL_FALSE,
						NULL,
						NULL,
						NULL,
						MMA_MEDIA_MSG_NONE, 
                        (MSF_UINT8) mma_get_message_storage(get_msg_info_req->msg_id),
                        MMA_SIM_ID_SIM_UNCLASSIFIED,0);
					/* Free large data */
					MMA_FREE(large_data_st);
					MMA_FREE(property_st);
					large_data_st = NULL;
					property_st = NULL;
					MMA_FREE(get_msg_info_req);
					return;
				}
			}
            if(app_ucs2_strlen((const kal_int8*)large_data_st->subject) > 0)
            {
                /* check for the subject */
                app_ucs2_strncpy((kal_int8*) subject_ucs2,
                                 (const kal_int8*)large_data_st->subject,
                                 MMA_MAX_SUBJECT_LEN - 1);
            }
#ifdef __MMI_MMS_GROUP_MSG__
            if (((property_st->suffix == MMS_SUFFIX_MSG) || (property_st->suffix == MMS_SUFFIX_SEND_REQ)) &&
                (property_st->num_of_recipient > 1) &&
                app_ucs2_strlen((const kal_int8*)subject_ucs2) == 0)
            {
                kal_wchar *str = NULL;

                str = (kal_wchar*) get_string(MMA_STR_ID_MMS_GROUP_MESSAGE);
                app_ucs2_strncpy((kal_int8*) subject_ucs2,
                                 (const kal_int8*)str,
                                 MMA_MAX_SUBJECT_LEN - 1);
            }
#endif 
			/* Check the mms size for the notification */
            if(msg_info->suffix == MMS_SUFFIX_NOTIFICATION)
            {
                char *msg_file_path = NULL;
                msg_file_path = MMAlib_getMessagePath(MSF_MODID_MMA, get_msg_info_req->msg_id);
                ASSERT(msg_file_path);
                msg_size = MSF_FILE_GETSIZE_EXT(msg_file_path, mma_get_mms_type_message_storage(get_msg_info_req->msg_id));
            }
            else
            {
                msg_size = property_st->msg_size;
            }
            mms_mma_send_get_msg_info_rsp(
                source,
                get_msg_info_req->app_id,
                MMA_RESULT_OK,
                get_msg_info_req->req_id,
                get_msg_info_req->msg_id,
                large_data_st->from_address_type,
                large_data_st->from_address,
                subject_ucs2,
                property_st->msg_type,
                property_st->priority,
                msg_size,
                property_st->user_elements_size,
                property_st->receive_date,
                property_st->expiry_date,
                property_st->compose_date,
                (kal_bool)property_st->need_read_report,
                (kal_bool)property_st->is_read,
                (kal_bool)property_st->is_forward_lock,
                (kal_bool)property_st->is_drm,
                (kal_bool)property_st->is_follow_phone_mms_content_class,
                (kal_bool)property_st->has_attachment,
                large_data_st->app_data,
                large_data_st->java_app_id,
                large_data_st->java_reply_app_id,
                property_st->msg_media_type,
                (MSF_UINT8) mma_get_message_storage(get_msg_info_req->msg_id),
                msg_info->msg_sim_id,
                property_st->msg_class);   
        }
        /* Free large data */
        MMA_FREE(large_data_st);
        MMA_FREE(property_st);
		large_data_st = NULL;
		property_st = NULL;        
    }
    MMA_FREE(get_msg_info_req);
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_msg_list_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source                  [IN]        
 *  get_msg_list_req        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_get_msg_list_req_hdlr(module_type source, wap_mma_get_msg_list_req_struct *get_msg_list_req)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(get_msg_list_req);

    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                           MMA_MSGMGR_GET_MSG_LIST_REQ_MMA_NOT_ACTIVE, "MMA is not ready to get msg info\n"));

        mms_mma_send_get_msg_list_rsp(
            source,
            get_msg_list_req->app_id,
            MMA_RESULT_FAIL_NOT_READY,
            get_msg_list_req->req_id,
            0,
            NULL,
            KAL_FALSE);
    }
    else if (mma_msgmgr_check_busy_state_pending_list(source, MMA_INT_SIG_TYPE_MSG_GET_MSG_LIST_REQ, get_msg_list_req))
        return;
#ifdef  __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    /* Check for the Memory Card mms in plug out state for which this req come */
    else if((get_msg_list_req->storage == MMA_MSG_STORAGE_CARD1) && (!MSF_IS_MEM_CARD_PRESNT(MSF_MMS_STORAGE_MEM_CARD_1)))
	{
		mms_mma_send_get_msg_list_rsp(
            source,
            get_msg_list_req->app_id,
            MMA_RESULT_OK,
            get_msg_list_req->req_id,
            0,
            NULL,
            KAL_FALSE);
        MMA_FREE(get_msg_list_req);
        return;
	}
#endif
    else
    {
        kal_uint32 *msg_id;
        kal_uint32 index = 0;
        kal_bool more = KAL_FALSE;
        mma_msg_info_list_struct *msg_list = g_mma_msgmgr_cntx.msg_list;

        msg_id = (kal_uint32*) MMA_CALLOC(sizeof(kal_uint32) * MMA_MAX_MSG_ARRAY_NUM);
        ASSERT(msg_id);
        if((get_msg_list_req->app_id == MMA_APP_ID_JSR) && (get_msg_list_req->folder == MMA_FOLDER_TEMPLATE) &&
            (get_msg_list_req->storage == MMA_MSG_STORAGE_PHONE))
        {
            /* In some flavor build, Userdef template can be unlimited */
            mma_msgmgr_msg_num_status_strcut msg_status = {0};
            kal_int32 total_msg_number = 0;
            msg_status.msg_sim_id = MMA_SIM_ID_TOTAL;
            mma_msgmgr_get_msg_num_of_each_folder(&msg_status);
            total_msg_number = msg_status.userdefined_template_msg_number + msg_status.predefined_template_msg_number;
            while (msg_list != NULL && index < total_msg_number)
            {
                if (msg_list->user_can_not_see == FALSE)
                {
                    if ((msg_list->folder == MMA_FOLDER_TEMPLATE) || (msg_list->folder == MMA_FOLDER_USRDEF_TEMPLATE))
                    {
                        msg_id[index] = msg_list->msg_id;
                        index++;
                    }
                }
                msg_list = msg_list->next;
            }
        }
        else
        {
            /* MMA_MAX_MSG_ARRAY_NUM have value 100 in place of 101 */
            while (msg_list != NULL && index < MMA_MAX_MSG_ARRAY_NUM)
            {
                if (msg_list->user_can_not_see == FALSE)
                {
                    if(get_msg_list_req->app_id == MMA_APP_ID_JSR)
                    {
                        if ((msg_list->folder == get_msg_list_req->folder) && (mma_get_message_storage(msg_list->msg_id) == get_msg_list_req->storage))
                        {
                            msg_id[index] = msg_list->msg_id;
                            index++;
                        }
                    }
                    else
                    {
                        if (msg_list->folder == get_msg_list_req->folder)
                        {
                            msg_id[index] = msg_list->msg_id;
                            index++;
                        }
                    }
                }
                msg_list = msg_list->next;
            }
        }
        mms_mma_send_get_msg_list_rsp(
            source,
            get_msg_list_req->app_id,
            MMA_RESULT_OK,
            get_msg_list_req->req_id,
            index,
            msg_id,
            more);
        MMA_FREE(msg_id);
    }
    MMA_FREE(get_msg_list_req);
}
#endif /* MMA_JSR_PST_MMS_OPERATON_SUPPORT */

/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_save_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source          [IN]        
 *  save_req        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_save_req_hdlr(module_type source, wap_mma_save_req_struct *save_req)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_uint32 index_of_msg = 0;
    kal_uint32 *save_result = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(save_req);
	save_result = MMA_CALLOC(sizeof(kal_uint32) * save_req->no_of_msg);
    memset(save_result, 0x00, sizeof(kal_uint32) * save_req->no_of_msg);
	
    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                           MMA_MSGMGR_SAVE_REQ_MMA_NOT_READY, "(mma_msgmgr.c): MMA is not ready to save msg"));

        for(index_of_msg = 0; index_of_msg < save_req->no_of_msg; index_of_msg++)
		{
			save_result[index_of_msg] = MMA_RESULT_FAIL_NOT_READY;
		}
		mms_mma_send_save_rsp(
            source,
            save_req->app_id,
            save_result,
            save_req->req_id,
            save_req->msg_id,
			save_req->no_of_msg);
        MMA_FREE(save_result);
		MMA_FREE(save_req);
        return;
    }
    else if (mma_msgmgr_check_busy_state_pending_list(source, MMA_INT_SIG_TYPE_MSG_SAVE_REQ, save_req))
    {
        MMA_FREE(save_result);
        return;
    }
    else if (mma_main_is_in_usb_mode() == TRUE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM,
                           MSF_MODID_MMA,
                           MMA_MSGMGR_SAVE_REQ_USB_MODE, "(mma_msgmgr.c): MMA can not save mms message in USB mode"));

        for(index_of_msg = 0; index_of_msg < save_req->no_of_msg; index_of_msg++)
		{
			save_result[index_of_msg] = MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE;
        }    
        mms_mma_send_save_rsp(
            source,
            save_req->app_id,
            save_result,
            save_req->req_id,
            save_req->msg_id,
            save_req->no_of_msg);
        MMA_FREE(save_result);
        MMA_FREE(save_req);
        return;
    }
    else if(mma_cvt_mma_folder_to_mms_folder((mma_folder_enum)save_req->box) == -1)
    {
        for(index_of_msg = 0; index_of_msg < save_req->no_of_msg; index_of_msg++)
		{
			save_result[index_of_msg] = MMA_RESULT_FAIL_INVALID_FOLDER;
		}
        mms_mma_send_save_rsp(
            source,
            save_req->app_id,
            save_result,
            save_req->req_id,
            save_req->msg_id,
			save_req->no_of_msg);
		MMA_FREE(save_result);
        MMA_FREE(save_req);
        return;
    }
    else
    {
        kal_uint32 *msg_id_list = MMA_CALLOC(sizeof(kal_uint32) * save_req->no_of_msg);
        MSF_UINT32 i = 0;
        wap_mma_event_save_msg_struct *event_info = NULL;
    #ifndef __COSMOS_MMI_PACKAGE__
        kal_uint32 usrdef_template_num = mma_msgmgr_get_msg_num_of_folder(MMA_FOLDER_USRDEF_TEMPLATE);        
    #endif  /* __COSMOS_MMI_PACKAGE__ */
        memset(msg_id_list, 0x00, sizeof(kal_uint32) * save_req->no_of_msg);
        
        for (i = 0; i < save_req->no_of_msg; i++)
        {
            mma_msg_info_list_struct *msg_info = NULL;
            mms_msg_info_property_struct *property_st = NULL;
            mms_msg_info_large_data_struct *large_data_st = NULL;
            mma_result_enum result = MMA_RESULT_OK;

            msg_id_list[i] = save_req->msg_id[i];
            save_result[i] = MMA_RESULT_OK;
            
            msg_info = mma_msgmgr_get_msg_from_list(save_req->msg_id[i]);
            if (msg_info == NULL)
            {
                save_result[i] = MMA_RESULT_FAIL_INVALID_MSGID;
                continue;
            }
            if(msg_info->folder == (MSF_UINT8)save_req->box)
            {
                /* same box. No need to precess. send OK result*/
                save_result[i] = MMA_RESULT_OK;
                continue;
            }
            if(save_req->app_id != MMA_APP_ID_BGSR)
            {
                /* If BGSR have asked to change the folder ID, then no need to check for Send/Download case */ 
                if ((mma_sendrecv_is_downloading(save_req->msg_id[i]) || mma_sendrecv_is_sending(save_req->msg_id[i])) == TRUE)
                {
                    save_result[i] = MMA_RESULT_FAIL_MSGID_IS_USING;
                    continue;
                }
            }
        #ifndef __COSMOS_MMI_PACKAGE__
            if (save_req->box == MMA_FOLDER_USRDEF_TEMPLATE)
            {
                if (usrdef_template_num >= MMA_MAX_USER_DEF_TEMPLATE_NUM)
                {
                    save_result[i] = MMA_RESULT_FAIL_USERDEF_TEMPLATE_FULL;
                    continue;    
                }
            }
        #endif  /* __COSMOS_MMI_PACKAGE__ */
            /* all cases are OK. Update the folder ID */
            /* case to show the proper icon in archive folder and date of postcard in Sent folder*/
            large_data_st = (mms_msg_info_large_data_struct*)MMA_CALLOC(sizeof(mms_msg_info_large_data_struct));
            ASSERT(large_data_st);                        
            property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));
            ASSERT(property_st);

            result = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_info->msg_id),
                        (kal_uint8)mma_get_mms_type_message_storage(msg_info->msg_id),
                        property_st, large_data_st));

                            
            if(result == MMA_RESULT_OK)
            {
                if(save_req->box == MMA_FOLDER_ARCHIVE)
                {
                    large_data_st->app_data[MMA_MSGMGR_PREV_FOLDER_POS] = (kal_uint8)msg_info->folder;
                }
            #ifdef __MMI_MMS_POSTCARD__
                else if(save_req->box == MMA_FOLDER_SENT)
                {
                    if (property_st->msg_type == MMA_MSG_TYPE_POSTCARD)
				    {
					    property_st->compose_date = MSF_TIME_GET_SECURE_CLOCK();
				    }
                }
            #endif /* __MMI_MMS_POSTCARD__ */
                property_st->folder = (MSF_UINT8)save_req->box;
                /* update the checksum of the property part */
                result = translate_mms_result_to_mma(MMSlib_UpdateChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_info->msg_id), (MmsFileType)msg_info->suffix,
                    (kal_uint8)mma_get_mms_type_message_storage(msg_info->msg_id), 
                    property_st, large_data_st));
                if(result == MMA_RESULT_OK)
                {
                    msg_info->prev_folder = msg_info->folder;
                    /* update the mms folder status */
                    mma_msgmgr_update_mms_folder_status(msg_info, KAL_TRUE, msg_info->folder, (kal_uint8)save_req->box);
                #if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)                    
                    if((msg_info->folder == MMA_FOLDER_INBOX) && (property_st->reserve_space == MMA_MSGMGR_IS_RECENT_EVT))
                    {
                        mma_msgmgr_remove_msg_from_recent_evt_list(msg_info->msg_id, KAL_TRUE);
                    }
                #endif
                    msg_info->folder = (MSF_UINT8)save_req->box;
                    if(msg_info->user_can_not_see)
                    {
                        msg_info->user_can_not_see = FALSE;
                    }
                #ifndef __COSMOS_MMI_PACKAGE__
                    /* count the number of user-def templates */
                    if (save_req->box == MMA_FOLDER_USRDEF_TEMPLATE)
                    {
                        usrdef_template_num++;
                    }
                #endif  /* __COSMOS_MMI_PACKAGE__ */
                    /* send the event notification */
                    event_info = (wap_mma_event_save_msg_struct*) MMA_CALLOC(sizeof(wap_mma_event_save_msg_struct));
                    event_info->msg_id = msg_info->msg_id;
                    event_info->folder = msg_info->folder;
                    mma_msgmgr_notify_app_event(MMA_EVENT_SAVE_MSG, event_info);
                }
            }
            /* Update the result. There may be chance that Data is not updated properly. Memory card plug out */
            save_result[i] = result;

			MMA_FREE(large_data_st);
            large_data_st = NULL;
            MMA_FREE(property_st);
            property_st = NULL;
            
        }
        /* send the rsp */
        mms_mma_send_save_rsp(
                source,
                save_req->app_id,
                save_result,
                save_req->req_id,
                save_req->msg_id,
			    save_req->no_of_msg);
		MMA_FREE(save_result);
		MMA_FREE(msg_id_list);
        mma_msgmgr_send_int_perform_msg_oper_ind();
    }
    MMA_FREE(save_req);
}


#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_delete_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source          [IN]        
 *  delete_req      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_delete_req_hdlr(module_type source, wap_mma_delete_req_struct *delete_req)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_uint32 index_of_msg = 0;
    kal_uint32 *delete_result = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(delete_req);
	delete_result = MMA_CALLOC(sizeof(kal_uint32) * delete_req->no_of_msg);
    memset(delete_result, 0x00, sizeof(kal_uint32) * delete_req->no_of_msg);

    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                           MMA_MSGMGR_DELETE_REQ_MMA_NOT_READY, "(mma_msgmgr.c): MMA is not ready to delete msg"));

        for(index_of_msg = 0; index_of_msg < delete_req->no_of_msg; index_of_msg++)
		{
			delete_result[index_of_msg] = MMA_RESULT_FAIL_NOT_READY;
		}
		mms_mma_send_delete_msg_rsp(
            (module_type) source,
            (kal_uint8) delete_req->app_id,
            delete_result,
            (kal_uint32) delete_req->req_id,
            (kal_uint32*) delete_req->msg_id,
			delete_req->no_of_msg);
		MMA_FREE(delete_result);
		MMA_FREE(delete_req);
		return;
    }
    else if (mma_msgmgr_check_busy_state_pending_list(source, MMA_INT_SIG_TYPE_MSG_DELETE_REQ, delete_req))
    {
        MMA_FREE(delete_result);
        return;
    }
    else if (mma_main_is_in_usb_mode() == TRUE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                           MMA_MSGMGR_DELETE_REQ_USB_MODE,
                           "(mma_msgmgr.c): MMA can not delete mms message in USB mode"));

        for(index_of_msg = 0; index_of_msg < delete_req->no_of_msg; index_of_msg++)
		{
			delete_result[index_of_msg] = MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE;
		}
		mms_mma_send_delete_msg_rsp(
            (module_type) source,
            (kal_uint8) delete_req->app_id,
            delete_result,
            (kal_uint32) delete_req->req_id,
            (kal_uint32*) delete_req->msg_id,
			delete_req->no_of_msg);
		MMA_FREE(delete_result);
		MMA_FREE(delete_req);
        return;
    }
#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
    else if(delete_req->box == MMA_FOLDER_REPORT_BOX)
    {
        MMA_FREE(delete_result);
        mma_msgmgr_delete_report_data_req_hdlr(source, delete_req);
        return;
    }
#endif
    else
    {
        kal_uint32 *msg_id_list = MMA_CALLOC(sizeof(kal_uint32) * delete_req->no_of_msg);
        MSF_UINT32 i = 0;
        kal_bool send_rsp = KAL_TRUE;
        
        memset(msg_id_list, 0x00, sizeof(kal_uint32) * delete_req->no_of_msg);
		g_mma_msgmgr_cntx.delete_result = MMA_RESULT_OK;
		for (i = 0; i < delete_req->no_of_msg; i++)
        {
            mma_msg_info_list_struct *msg_info = NULL;

            msg_id_list[i] = delete_req->msg_id[i];
            delete_result[i] = MMA_RESULT_OK;
            
            msg_info = mma_msgmgr_get_msg_from_list(delete_req->msg_id[i]);
            if (msg_info == NULL)
            {
                delete_result[i] = MMA_RESULT_FAIL_INVALID_MSGID;
                continue;
            }
        #ifdef  __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            /* Check for the Memory Card mms in plug out state for which the delete req come */
            if((mma_get_message_storage(msg_info->msg_id) == MMA_MSG_STORAGE_CARD1) && (!MSF_IS_MEM_CARD_PRESNT(MSF_MMS_STORAGE_MEM_CARD_1)))
			{
				delete_result[i] = MMA_RESULT_FAIL_MEM_CARD_PLUG_OUT;
                continue;
			}
        #endif
            if(MMA_MSGMGR_MSG_CHK_FLAG(msg_info->flag, MMA_MSGMGR_MSG_OPER_DELETE_REQ_SENT))
            {
                /* Message is already deleted in Sync behavior */
                delete_result[i] = MMA_RESULT_FAIL_INVALID_MSGID;
                continue;
            }
            if(msg_info->is_rr_send)
			{
				delete_result[i] = MMA_RESULT_FAIL_MSGID_IS_USING;
                continue;
			}
            if ((mma_sendrecv_is_downloading(delete_req->msg_id[i]) || mma_sendrecv_is_sending(delete_req->msg_id[i])) == TRUE)
            {
                delete_result[i] = MMA_RESULT_FAIL_MSGID_IS_USING;
                continue;
            }
			/* Check if the MMS is in waiting queue */
            if (!mma_sendrecv_remove_single_pending_send_node(delete_req->msg_id[i]))
            {
                /* not in sending list, check for downloading list */
                mma_sendrecv_remove_single_pending_download_node(delete_req->msg_id[i]);
            }
			if (delete_result[i] == MMA_RESULT_OK)
            {
                MMA_MSGMGR_MSG_SET_FLAG(msg_info->flag, MMA_MSGMGR_MSG_OPER_DELETE);
                /* Remove the entry here, as it is not removed from the final remove of mms from mms list */
				mma_msgmgr_update_mms_folder_status(msg_info, KAL_TRUE, msg_info->folder, 0);
                send_rsp = KAL_FALSE;
            }
        }
        if (send_rsp == TRUE)
        {
            mms_mma_send_delete_msg_rsp(
            (module_type) source,
            (kal_uint8) delete_req->app_id,
            delete_result,
            (kal_uint32) delete_req->req_id,
            (kal_uint32*) delete_req->msg_id,
			delete_req->no_of_msg);
            MMA_FREE(delete_result);
            MMA_FREE(msg_id_list);
			MMA_FREE(delete_req);
        }
        else
        {
            mma_msg_info_list_struct *msg_list = g_mma_msgmgr_cntx.msg_list;
            mma_msg_info_list_struct *tmp = NULL;
            mma_msgmgr_req_info_struct *req_info = MMA_CALLOC(sizeof(mma_msgmgr_req_info_struct));

            while (msg_list)
            {
                kal_uint32 msg_count = 0;
				if (MMA_MSGMGR_MSG_CHK_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_DELETE))
                {
                    tmp = msg_list;
					msg_count++;
					if(msg_count == delete_req->no_of_msg)
					{
						/* all delete flags are checked. No need to go for others. stop loop */
						break;
					}
                }
                msg_list = msg_list->next;
            }

            ASSERT(tmp != NULL);

            MMA_MSGMGR_MSG_SET_FLAG(tmp->flag, MMA_MSGMGR_MSG_OPER_NEED_SEND_DELETE_RSP);

            req_info->app_id = delete_req->app_id;
            req_info->req_id = delete_req->req_id;
            req_info->no_of_msg = delete_req->no_of_msg;
            req_info->msg_id = (MSF_UINT32*)msg_id_list;
            req_info->result = (MSF_UINT32*)delete_result;
            req_info->source = source;
                        
            if (g_mma_msgmgr_cntx.delete_req != NULL)
            {
                MMA_FREE(g_mma_msgmgr_cntx.delete_req);
            }
            g_mma_msgmgr_cntx.delete_req = req_info;
			MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_UPDATING_MSG_LIST);
            mma_msgmgr_send_int_perform_msg_oper_ind();
        }
    }
    MMA_FREE(delete_req);
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_um_delete_folder_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source                  [IN]        
 *  delete_folder_req       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_um_delete_folder_req_hdlr(
                module_type source,
                srv_um_delete_folder_req_struct *delete_folder_req)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(delete_folder_req);

    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                           MMA_MSGMGR_UM_DELETE_FOLDER_REQ_MMA_NOT_READY, "(mma_msgmgr.c): MMA is not ready to delete folder"));

        mms_mma_send_delete_folder_rsp(source, delete_folder_req->app_id, delete_folder_req->msg_type, KAL_FALSE);
        MMA_FREE(delete_folder_req);
        return;
    }
    else if (mma_msgmgr_check_busy_state_pending_list
             (source, MMA_INT_SIG_TYPE_MSG_UM_DELETE_FOLDER_REQ, delete_folder_req))
        return;
#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
    else if(delete_folder_req->msg_box_type == SRV_UM_MSG_BOX_REPORT)
    {
        /* Need to delete only REPORT BOX */
        mma_msgmgr_um_delete_report_folder_req_hdlr(source, delete_folder_req);
        return;
    }
#endif
    else
    {
        mma_msg_info_list_struct *msg_info = NULL;
        kal_uint32 msg_id_in_sending = 0;
        kal_uint32 msg_id_in_sending_outbox = 0;
        kal_uint32 count_rr_msg_id_in_inbox = 0;
        kal_uint32 msg_id_in_receiving = 0;
        kal_uint32 count_rr_msg_id_in_archive = 0;
		mma_msg_storage_type_enum storage_filter;
		mma_sim_id_enum mma_app_sim = MMA_SIM_ID_TOTAL;
		if(g_mma_setting_cntx.setting)
        		 storage_filter = (mma_msg_storage_type_enum)g_mma_setting_cntx.setting->storage_filter;		/*Delete all message based on storage filter*/
		else
				 storage_filter = MMA_MSG_STORAGE_TOTAL;

		
#if (MMI_MAX_SIM_NUM >= 2)
		mma_app_sim = (mma_sim_id_enum)translate_um_simid_to_mma_simid(delete_folder_req->sim_id);
#endif
        g_mma_msgmgr_cntx.delete_result = MMA_RESULT_OK;

        /* Check if it is in usb mode */
        if (mma_main_is_in_usb_mode() == TRUE)
        {
            kal_bool result = KAL_TRUE;

            if ((delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_INBOX) &&
                mma_msgmgr_get_msg_num_of_folder(MMA_FOLDER_INBOX) > 0)
            {
                result = KAL_FALSE;
            }
            if ((delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_UNSENT) &&
                mma_msgmgr_get_msg_num_of_folder(MMA_FOLDER_OUTBOX) > 0)
            {
                result = KAL_FALSE;
            }
            if ((delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_SENT) &&
                mma_msgmgr_get_msg_num_of_folder(MMA_FOLDER_SENT) > 0)
            {
                result = KAL_FALSE;
            }
            if ((delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_DRAFT) &&
                mma_msgmgr_get_msg_num_of_folder(MMA_FOLDER_DRAFT) > 0)
            {
                result = KAL_FALSE;
            }
            if ((delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_USRDEF_TEMPLATES) &&
                mma_msgmgr_get_msg_num_of_folder(MMA_FOLDER_USRDEF_TEMPLATE) > 0)
            {
                result = KAL_FALSE;
            }
        #if defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__)
            if ((delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_ARCHIVE) &&
                mma_msgmgr_get_msg_num_of_folder(MMA_FOLDER_ARCHIVE) > 0)
            {
                result = KAL_FALSE;
            }
        #endif /* defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) */
        #ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
            if(delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_REPORT)
            {
                kal_uint32 report_msg_num = 0;
                mms_msg_report_info *report_data = MMA_CALLOC(MMS_REPORT_FILE_SIZE);
                if(MMSlib_readReportInfoFile(MSF_MMS_STORAGE_PHONE, report_data) == MMS_RESULT_OK)
                {
                    report_msg_num = (kal_uint16)report_data->report_count;
                }
                MMA_FREE(report_data);
                if(report_msg_num > 0)
                {
                    result = KAL_FALSE;
                }
            }
        #endif
            mms_mma_send_delete_folder_rsp(source, delete_folder_req->app_id, delete_folder_req->msg_type, result);
            MMA_FREE(delete_folder_req);
            return;
        }
        /* check for the send & download messages */
        if (delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_UNSENT)
        {
            /* Cancel send queue */
            mma_sendrecv_remove_pending_send_nodes();
            msg_id_in_sending_outbox = mma_sendrecv_get_sending_msgid();
            if ((msg_id_in_sending_outbox != 0) && (mma_get_box(msg_id_in_sending_outbox) != MMA_FOLDER_OUTBOX))
            {
                msg_info = mma_msgmgr_get_msg_from_list(msg_id_in_sending_outbox);
                if(!(msg_info && (msg_info->folder == MMA_FOLDER_OUTBOX) && (msg_info->msg_sim_id & mma_app_sim)))
                {
                    msg_id_in_sending_outbox = 0;
                }
            }
            msg_info = NULL;
        }

        if ((delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_INBOX) 
            #if defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__)
            || (delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_ARCHIVE)
            #endif /* defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) */
            )
        {
            /* Cancel download queue */
            mma_sendrecv_remove_pending_download_nodes();

            /* get all the messages from the INBOX & check for the Send READ report case */
            msg_info = g_mma_msgmgr_cntx.msg_list;
            while (msg_info)
            {
                /* count the number of RR need to be sent from the INBOX & ARCHIVE */
                if ((msg_info->folder == MMA_FOLDER_INBOX) && (msg_info->is_rr_send) && (msg_info->msg_sim_id & mma_app_sim))
                {
                    count_rr_msg_id_in_inbox++;
                }
                else if ((msg_info->folder == MMA_FOLDER_ARCHIVE) && (msg_info->is_rr_send) && (msg_info->msg_sim_id & mma_app_sim))
                {
                    count_rr_msg_id_in_archive++;
                }
                else if ((msg_info->folder == MMA_FOLDER_INBOX) && mma_sendrecv_is_downloading(msg_info->msg_id) && (msg_info->msg_sim_id & mma_app_sim))
                {
                    msg_id_in_receiving = msg_info->msg_id;
                }
                msg_info = msg_info->next;
            }
        }
        if (msg_id_in_sending_outbox)
        {
            msg_id_in_sending = msg_id_in_sending_outbox;
        }
        /*else if (msg_id_in_sending_inbox)
        {
            msg_id_in_sending = msg_id_in_sending_inbox;
        }*/
        {
            /* Remove msg_id from msg_list */
            kal_uint32 index = 0;
            mma_msgmgr_msg_num_status_strcut status = {0};
            kal_uint32 msg_num = 0;
            mma_folder_enum folder = MMA_FOLDER_INBOX;
            mma_msg_info_list_struct *msg_list = NULL;
            status.msg_sim_id = mma_app_sim;

            if (mma_msgmgr_get_msg_num_of_each_folder(&status) != MMA_RESULT_OK)
            {
                ASSERT(0);
            }
          start:
            msg_list = g_mma_msgmgr_cntx.msg_list;
            if (delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_INBOX)
            {
                folder = MMA_FOLDER_INBOX;
                delete_folder_req->msg_box_type &= ~SRV_UM_MSG_BOX_INBOX;
            }
            else if (delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_UNSENT)
            {
                folder = MMA_FOLDER_OUTBOX;
                delete_folder_req->msg_box_type &= ~SRV_UM_MSG_BOX_UNSENT;
            }
            else if (delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_SENT)
            {
                folder = MMA_FOLDER_SENT;
                delete_folder_req->msg_box_type &= ~SRV_UM_MSG_BOX_SENT;
            }
            else if (delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_DRAFT)
            {
                folder = MMA_FOLDER_DRAFT;
                delete_folder_req->msg_box_type &= ~SRV_UM_MSG_BOX_DRAFT;
            }
            else if (delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_PREDEF_TEMPLATES)
            {
                folder = MMA_FOLDER_TEMPLATE;
                delete_folder_req->msg_box_type &= ~SRV_UM_MSG_BOX_PREDEF_TEMPLATES;
            }
            else if (delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_USRDEF_TEMPLATES)
            {
                folder = MMA_FOLDER_USRDEF_TEMPLATE;
                delete_folder_req->msg_box_type &= ~SRV_UM_MSG_BOX_USRDEF_TEMPLATES;
            }
        #if defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__)
            else if (delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_ARCHIVE)
            {
                folder = MMA_FOLDER_ARCHIVE;
                delete_folder_req->msg_box_type &= ~SRV_UM_MSG_BOX_ARCHIVE;
            }
        #endif /* defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) */ 
        #if defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__)
            else if (delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_SIM)
            {
                delete_folder_req->msg_box_type &= ~SRV_UM_MSG_BOX_SIM;
                goto start; /* We don;t handle this SRV_UM_MSG_BOX_SIM folder */
            }
        #endif /* defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) */
        #ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
            else if(delete_folder_req->msg_box_type & SRV_UM_MSG_BOX_REPORT)
            {
                /* Need to delete REPORT BOX */
                delete_folder_req->msg_box_type &= ~SRV_UM_MSG_BOX_REPORT;
                MMSlib_deleteReportInfoFile();
                /* Make the unread report count as 0 */
                mma_msgmgr_reset_unread_report_count();
                goto start; /* No report mms entry in msgmgr list */
            }
        #endif
            else if (delete_folder_req->msg_box_type == 0)
            {
                /* Keep the last node to send MMA_MSGMGR_MSG_OPER_NEED_SEND_UM_DELETE_FOLDER_RSP. Remove others */
                mma_msg_info_list_struct *msg_list = g_mma_msgmgr_cntx.msg_list;
                mma_msg_info_list_struct *tmp = NULL;
                MSF_BOOL send_rsp_now = TRUE;

                while (msg_list)
                {
                    if (MMA_MSGMGR_MSG_CHK_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_NEED_SEND_UM_DELETE_FOLDER_RSP))
                    {
                        if (tmp != msg_list)
                        {
                            if (tmp)
                            {
                                MMA_MSGMGR_MSG_UNSET_FLAG(
                                    tmp->flag,
                                    MMA_MSGMGR_MSG_OPER_NEED_SEND_UM_DELETE_FOLDER_RSP);
                                //tmp->source_module = NULL;
                                //tmp->user_data = NULL;
                                tmp = NULL;
                            }
                        }
                        tmp = msg_list;
                        send_rsp_now = FALSE;
                    }
                    msg_list = msg_list->next;
                }

                if (send_rsp_now)
                {
                    mms_mma_send_delete_folder_rsp(
                        source,
                        delete_folder_req->app_id,
                        SRV_UM_MSG_MMS,
                        (g_mma_msgmgr_cntx.delete_result == MMA_RESULT_OK) ? KAL_TRUE : KAL_FALSE);
                    MMA_FREE(delete_folder_req);
                }
                return;
            }
            else
            {
                ASSERT(0);
            }

            switch (folder)
            {
                case MMA_FOLDER_INBOX:
                    msg_num = (status.inbox_read_msg_number + status.inbox_unread_msg_number);
                    break;
                case MMA_FOLDER_DRAFT:
                    msg_num = status.draft_msg_number;
                    break;
                case MMA_FOLDER_OUTBOX:
                    msg_num = status.unsent_msg_number;
                    break;
                case MMA_FOLDER_SENT:
                    msg_num = status.sent_msg_number;
                    break;
                case MMA_FOLDER_TEMPLATE:
                    msg_num = status.predefined_template_msg_number;
                    break;
                case MMA_FOLDER_USRDEF_TEMPLATE:
                    msg_num = status.userdefined_template_msg_number;
                    break;
                case MMA_FOLDER_ARCHIVE:
                    msg_num = status.archive_msg_number;
                    break;
                default:
                    ASSERT(0);
            }
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                              MMA_MSGMGR_UM_DELETE_FOLDER_REQ_MSG_DETAIL,
                              "(mma_msgmgr.c): Delete %d folder and msg_num is %d, msg_id_in_sending: %d,msg_id_in_receiving:%d\n",
                              folder, msg_num, msg_id_in_sending, msg_id_in_receiving));

            if (msg_num > 0)
            {
                if (msg_id_in_sending_outbox != 0 && folder == MMA_FOLDER_OUTBOX)
                {
                    msg_num--;  /* Application want to delete outbox folder */
                    g_mma_msgmgr_cntx.delete_result = MMA_RESULT_FAIL_MSGID_IS_USING;
                }
                else if (count_rr_msg_id_in_archive != 0 && folder == MMA_FOLDER_ARCHIVE)
                {
                    msg_num = msg_num - count_rr_msg_id_in_archive;  /* Application want to delete read report sending Archive folder */
                    g_mma_msgmgr_cntx.delete_result = MMA_RESULT_FAIL_MSGID_IS_USING;
                }
                else if (folder == MMA_FOLDER_INBOX)
                {
                    if (msg_id_in_receiving != 0)
                    {
                        if (msg_num > 0)
                        {
                            msg_num--;  /* Application want to delete inbox folder */
                            g_mma_msgmgr_cntx.delete_result = MMA_RESULT_FAIL_MSGID_IS_USING;
                        }
                    }
                    if (count_rr_msg_id_in_inbox != 0)
                    {
                        /* Check if this send request is read report. 
                           Bcoz the MMS message trigger the send read report is still in inbox folder.
                           If we delete the MMS message in inbox, 
                           MMS service is not able to create read report corresponding to the deleted MMS message. */
                        if (msg_num > 0)
                        {
                            msg_num = msg_num - count_rr_msg_id_in_inbox;;
                            g_mma_msgmgr_cntx.delete_result = MMA_RESULT_FAIL_MSGID_IS_USING;
                        }
                    }
                }
            }
            if (msg_num > 0)
            {
            #ifdef __MMI_MMS_BGSR_SUPPORT__
                wap_mma_event_delete_folder_struct *event_info = NULL;

                event_info =
                    (wap_mma_event_delete_folder_struct*) MMA_CALLOC(sizeof(wap_mma_event_delete_folder_struct));
                event_info->folder = folder;
                mma_msgmgr_notify_app_event(MMA_EVENT_DELETE_FOLDER, event_info);
            #endif /* __MMI_MMS_BGSR_SUPPORT__ */ 
            }
            index = 0;
            while (msg_list)
            {
                if (msg_list->folder == folder && msg_list->user_can_not_see == FALSE && (msg_list->msg_sim_id & mma_app_sim))
                {
                     		  if((mma_get_message_storage(msg_list->msg_id) & storage_filter))
				  {
                    /* Delete file */
                    if (((msg_list->folder != MMA_FOLDER_INBOX) && (msg_list->folder != MMA_FOLDER_OUTBOX) &&
                         (msg_list->folder != MMA_FOLDER_ARCHIVE)) || 
                        ((msg_list->folder == MMA_FOLDER_OUTBOX) && (msg_list->msg_id != msg_id_in_sending)) ||
                        ((msg_list->folder == MMA_FOLDER_INBOX) && (msg_list->msg_id != msg_id_in_receiving) &&
                         (!msg_list->is_rr_send)) ||
                        ((msg_list->folder == MMA_FOLDER_ARCHIVE) && (!msg_list->is_rr_send)))
                    {
                        index++;
                        if(!MMA_MSGMGR_MSG_CHK_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_DELETE_REQ_SENT))
                        {
                            /* This flag message is already deleted in Sync behavior */
                            /* Delete file */
                            MMA_MSGMGR_MSG_SET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_DELETE);
                            mma_msgmgr_update_mms_folder_status(msg_list, KAL_TRUE, msg_list->folder, 0);
                            if (index == msg_num)
                            {
                                /* The last MMS should be deleted */
                                MMA_MSGMGR_MSG_SET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_NEED_SEND_UM_DELETE_FOLDER_RSP);
                                g_mma_msgmgr_cntx.source_module = source;
                                g_mma_msgmgr_cntx.user_data = delete_folder_req;
                            }
                            MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_UPDATING_MSG_LIST);
                            mma_msgmgr_send_int_perform_msg_oper_ind();
                        }
                    }
                }
				  else
				  {
					index++;
				  }
                }
                msg_list = msg_list->next;
            }
            if (index != msg_num)
            {
                ASSERT(0);
            }
            goto start;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_enter_usb_mode_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_enter_usb_mode_req_hdlr()
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        /* ashok, no need to do anything. simply return */
		mms_mma_send_enter_usb_rsp(MOD_MMI);
    }
    else if (mma_msgmgr_check_busy_state_pending_list(MOD_MMI, MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ, NULL))
        return;
    else
    {
        mms_mma_send_enter_usb_rsp(MOD_MMI);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_mms_delete_ind_hdlr
 * DESCRIPTION
 *  To send the delete response to the application.
 * PARAMETERS
 *  result      [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_msgmgr_mms_delete_ind_hdlr(MmsResult result, kal_uint32 msg_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mma_msg_info_list_struct *msg_list;
	//mma_msg_info_list_struct *msg_info_p;
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
    mma_msgmgr_new_msg_info_struct *new_msg_info = NULL;
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
    new_msg_info = mma_msgmgr_get_new_msg_info_by_msg_id(msg_id);
	if (new_msg_info != NULL && new_msg_info->state == MMA_MSGMGR_MSG_STATE_DELETE_OLD_MSG)
    {
        mma_msgmgr_create_info_struct *int_create_req = NULL;
        kal_char file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];
        char *temp_path = NULL;
        char *temp_path_utf8 = NULL;

        mma_msgmgr_get_encode_filepath(new_msg_info->msg_id, file_path);
        temp_path = (char*)MSF_FILE_GET_EXTERNAL_FILENAME_EXT(MSF_MODID_MMA, file_path, 
                        mma_get_mms_type_message_storage(msg_id));
        memset(file_path, 0, MMA_MAX_INTERNAL_FILENAME_LENGTH);
        temp_path_utf8 = mma_ucs2_to_utf8_string((const kal_wchar *) temp_path);
        strcpy(file_path, temp_path_utf8);
        MMA_FREE(temp_path);
        MMA_FREE(temp_path_utf8);
        /* send internal signal to MMA CREATE to create a MMS */
        int_create_req = (mma_msgmgr_create_info_struct*) MMA_CALLOC(sizeof(mma_msgmgr_create_info_struct));
        int_create_req->req_id = new_msg_info->req_id;
        int_create_req->mode = MMA_MODE_UPLOAD;
        int_create_req->upload_filepath = (char*)MMA_CALLOC(strlen(file_path) + 1);
        if(new_msg_info->data != NULL)
        {
            int_create_req->app_id = ((mma_msgmgr_create_info_struct*)(new_msg_info->data))->app_id;
        }
        if (new_msg_info->msg_type == MMA_MSGMGR_MSG_TYPE_USER_CREATE)
        {
            int_create_req->msg_filetype = MMS_SUFFIX_SEND_REQ;
        }
        else
        {
            int_create_req->msg_filetype = MMS_SUFFIX_MSG;
        }

        strncpy(int_create_req->upload_filepath, file_path, strlen(file_path));

        MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_CREATE, MMA_INT_SIG_TYPE_MSG_INT_CREATE_REQ, TRUE, int_create_req);
        new_msg_info->state = MMA_MSGMGR_MSG_STATE_CREATING_ENCODED_MSG;
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_MMS_DELETE_IND_NEW_MMS_DETAIL, "MMA MSGMGR new msg type %d, state %d", new_msg_info->msg_type, new_msg_info->state));
    }
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
    {
        /* handle the delete case */
        mma_msg_info_list_struct *msg_info;

        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_DELTE_IND_FOR_MSG_ID,
                          "(mma_msgmgr.c): RecvMmsNotifyDelInd %d", (int)msg_id));
        /* Already not care about the mms core result. Send OK result to APP */
        msg_info = mma_msgmgr_get_msg_from_list(msg_id);
        if (msg_info != NULL)
        {
            if (MMA_MSGMGR_MSG_CHK_FLAG(msg_info->flag, MMA_MSGMGR_MSG_OPER_DELETE_REQ_SENT))
            {
                //MMSlib_delChkSumFile(MMA_TRANSLATE_MSG_ID(msg_id), (kal_uint8)mma_get_mms_type_message_storage(msg_info->msg_id));
                MMA_MSGMGR_MSG_SET_FLAG(msg_info->flag, MMA_MSGMGR_MSG_OPER_DELETE_DONE);
            }
            else
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_DELTE_IND_ERROR_FOR_MSG_ID,
                                  "(mma_msgmgr.c): RecvMmsNotifyDelInd.Err %d", (int)msg_id));
            }
        #if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
            if(msg_info->folder == MMA_FOLDER_INBOX)
            {
                mma_msgmgr_remove_msg_from_recent_evt_list(msg_info->msg_id, KAL_FALSE);
            }
        #endif
            if (result != MMS_RESULT_OK)
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM,
                                  MSF_MODID_MMA,
                                  MMA_MSGMGR_DELETE_IND_FAIL_TO_DELETE, "(mma_msgmgr.c): fail to delete msg %d. flag:%d",
                                  (int)msg_id, msg_info->flag));
            }
			mma_msgmgr_send_int_perform_msg_oper_ind();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_sync_delete_mms_ind_hdlr
 * DESCRIPTION
 *  To delete the mms entry from list.
 * PARAMETERS        
 *  msg_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_msgmgr_sync_delete_mms_ind_hdlr(mms_sync_delete_msg_ind_struct *sync_delete_ind)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMAif_deleteMessage(MMA_SUBMODULE_MSG_MGR, sync_delete_ind->msg_id);

    MMA_FREE(sync_delete_ind);
}

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_validate_msg_req_hdlr
 * DESCRIPTION
 *  This function is used to check if messages are still valid
 * PARAMETERS
 *  source                  [IN]        
 *  msg_is_valid_req        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_validate_msg_req_hdlr(module_type source, wap_mma_msg_is_valid_req_struct *msg_is_valid_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(msg_is_valid_req);

    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        mms_mma_send_msg_is_valid_rsp(
            source,
            msg_is_valid_req->app_id,
            msg_is_valid_req->req_id,
            MMA_RESULT_FAIL_NOT_READY,
            NULL,
            NULL);

        MMA_FREE(msg_is_valid_req);
        return;
    }
    else if (mma_msgmgr_check_busy_state_pending_list(source, MMA_INT_SIG_TYPE_MSG_VALIDATE_MSG_REQ, msg_is_valid_req))
        return;
    else
    {
        kal_uint8 *msg_list;
        kal_uint16 *box_list;
        kal_uint32 i = 0;

        /* msg_list indicate the value 1 for OK and 0 for not OK  for a msg_id */
        msg_list = (kal_uint8*) MMA_CALLOC(sizeof(kal_uint8) * MMA_MAX_MSG_ARRAY_NUM);
        /* box_list specify the folder of the msg_id */
        box_list = (kal_uint16*) MMA_CALLOC(sizeof(kal_uint16) * MMA_MAX_MSG_ARRAY_NUM);

        for (i = 0; i < MMA_MAX_MSG_ARRAY_NUM; i++)
        {
            kal_uint32 msg_id = msg_is_valid_req->msg_id_list[i];

            if (msg_id > 0)
            {
                mma_msg_info_list_struct *msg_info;

                msg_info = mma_msgmgr_get_msg_from_list(msg_id);
                if (msg_info)
                {
                    *(msg_list + i) = 1;
                    *(box_list + i) = msg_info->folder;
                }
            }
            else
            {
                break;
            }
        }
        mms_mma_send_msg_is_valid_rsp(
            source,
            msg_is_valid_req->app_id,
            msg_is_valid_req->req_id,
            MMA_RESULT_OK,
            msg_list,
            box_list);
        MMA_FREE(msg_list);
        MMA_FREE(box_list);
        MMA_FREE(msg_is_valid_req);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_set_appdata_req_hdlr
 * DESCRIPTION
 *  This function is used to set the app data in the list
 * PARAMETERS
 *  source                  [IN]        
 *  set_appdata_req_p       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_msgmgr_set_appdata_req_hdlr(module_type source, wap_mma_set_app_data_req_struct *set_appdata_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;
    mms_msg_info_large_data_struct *large_data_st = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(set_appdata_req_p);

    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        mms_mma_send_set_app_data_rsp(
            source,
            set_appdata_req_p->app_id,
            set_appdata_req_p->req_id,
            set_appdata_req_p->msg_id,
            MMA_RESULT_FAIL_NOT_READY);

        MMA_FREE(set_appdata_req_p);
        return;
    }
#ifdef  __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    /* Check for the Memory Card mms in plug out state for which this req come */
    else if((mma_get_message_storage(set_appdata_req_p->msg_id) == MMA_MSG_STORAGE_CARD1) && (!MSF_IS_MEM_CARD_PRESNT(MSF_MMS_STORAGE_MEM_CARD_1)))
	{
		mms_mma_send_set_app_data_rsp(
            source,
            set_appdata_req_p->app_id,
            set_appdata_req_p->req_id,
            set_appdata_req_p->msg_id,
            MMA_RESULT_FAIL_MEM_CARD_PLUG_OUT);

        MMA_FREE(set_appdata_req_p);
        return;
	}
#endif
    else if (mma_msgmgr_check_busy_state_pending_list(source, MMA_INT_SIG_TYPE_MSG_SET_APPDATA_REQ, set_appdata_req_p))
        return;
    else
    {
        /* read the previous information of the large data */
        large_data_st = (mms_msg_info_large_data_struct*)MMA_CALLOC(sizeof(mms_msg_info_large_data_struct));
        ASSERT(large_data_st);
#ifndef __MMI_SLIM_MMS_2__
        result = mma_msgmgr_set_lock_status(set_appdata_req_p->msg_id, 
                            (kal_uint8)set_appdata_req_p->app_data[MMA_MSGMGR_LOCK_MODE_APP_DATA_POS],
                            (kal_uint8)set_appdata_req_p->app_data[MMA_MSGMGR_CORRUPT_MMS_POS], large_data_st);
#else /* __MMI_SLIM_MMS_2__ */
		ASSERT(0);
#endif /* __MMI_SLIM_MMS_2__ */
    
        mms_mma_send_set_app_data_rsp(
            source,
            set_appdata_req_p->app_id,
            set_appdata_req_p->req_id,
            set_appdata_req_p->msg_id,
            result);
	    MMA_FREE(large_data_st);
        MMA_FREE(set_appdata_req_p);
    }
}


#if defined (__MMI_OP11_HOMESCREEN__) || defined (__MMI_OP12_TOOLBAR__) || defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_unread_msg_list_req_hdlr
 * DESCRIPTION
 *  This function is used to handle GET_UNREAD_MSG_LIST_REQ.
 * PARAMETERS
 *  source                          [IN]        
 *  get_unread_msg_list_req_p       [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_get_unread_msg_list_req_hdlr(
                module_type source,
                wap_mma_get_unread_msg_list_req_struct *get_unread_msg_list_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_unread_msg_list_struct *unread_msg_list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(get_unread_msg_list_req_p);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_GET_UNREAD_MSG_LIST_REQ_HDLR, "MMA MSGMGR: get unread msg list"));

    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_GET_UNREAD_MSG_LIST_MMA_NOT_READY, "MMA is not ready to get unread msg list"));
        mms_mma_send_get_unread_msg_list_rsp(
            source,
            get_unread_msg_list_req_p->app_id,
            get_unread_msg_list_req_p->req_id,
            MMA_RESULT_FAIL_NOT_READY,
            0,
            0,
            0,
            NULL);

        MMA_FREE(get_unread_msg_list_req_p);
        return;
    }
    else if (mma_main_is_in_usb_mode())
    {
        mms_mma_send_get_unread_msg_list_rsp(
            source,
            get_unread_msg_list_req_p->app_id,
            get_unread_msg_list_req_p->req_id,
            MMA_RESULT_OK,
            0,
            0,
            0,
            NULL);
        MMA_FREE(get_unread_msg_list_req_p);
        return;
    }
    else if (mma_msgmgr_check_busy_state_pending_list
             (source, MMA_INT_SIG_TYPE_MSG_GET_UNREAD_MSG_LIST_REQ, get_unread_msg_list_req_p))
        return;
    else
    {
        MSF_UINT32 index = (MSF_UINT32) get_unread_msg_list_req_p->start_index;
        MSF_UINT32 num_of_msg_requested = (MSF_UINT32) get_unread_msg_list_req_p->num_of_msg_requested;
        MSF_UINT32 num_of_unread_msg = 0;
        MSF_UINT32 total_num_of_unread_msg = 0;
        MSF_UINT8 more = 0;
        mma_result_enum result = MMA_RESULT_OK;
        kal_uint32 msg_id = 0;
        mms_msg_info_property_struct *property_st = NULL;
        mms_msg_info_large_data_struct *large_data_st = NULL;
        int loop = 0;

        /* get unread msg number in inbox */
        /* Need to check when different SIM ID type requirement come */
        for(; loop <= MMA_MAX_SIM_COUNT; loop++)
        {
            total_num_of_unread_msg += g_mma_msgmgr_cntx.mms_folder_status.folder[loop].inbox_unread_msg_num ;
        }

        large_data_st = (mms_msg_info_large_data_struct*)MMA_CALLOC(sizeof(mms_msg_info_large_data_struct));
        ASSERT(large_data_st);                        
        property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));
        ASSERT(property_st);

        unread_msg_list =
            (mma_unread_msg_list_struct*) MMA_CALLOC(sizeof(mma_unread_msg_list_struct) * MMA_MAX_UNREAD_MSG_NUM);

        /* check msg list has msg */
        if (g_mma_msgmgr_cntx.unread_msg_list == NULL)
        {
            mms_mma_send_get_unread_msg_list_rsp(
                source,
                get_unread_msg_list_req_p->app_id,
                get_unread_msg_list_req_p->req_id,
                MMA_RESULT_OK,
                0,
                0,
                0,
                unread_msg_list);
            MMA_FREE(unread_msg_list);
            MMA_FREE(get_unread_msg_list_req_p);
            /* free the memory */
            MMA_FREE(large_data_st);
		    large_data_st = NULL;
		    MMA_FREE(property_st);
		    property_st = NULL;
            return;
        }
        if (index < total_num_of_unread_msg)
        {
            do
            {
                //msg_info = mma_msgmgr_get_unread_msg_info_by_idx(index);
                msg_id = mma_msgmgr_get_unread_msg_id_by_idx(index);
                if (msg_id != 0)
                {
                    result = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_id),
                                (kal_uint8)mma_get_mms_type_message_storage(msg_id),
                                property_st, large_data_st));

                    unread_msg_list[num_of_unread_msg].msg_id = msg_id;
                    unread_msg_list[num_of_unread_msg].is_subject = FALSE;
                    unread_msg_list[num_of_unread_msg].is_text = FALSE;
                    unread_msg_list[num_of_unread_msg].num_attach = 0;
                    
                    /* check for the Corrupted or normal MMS */
                    if (result == MMA_RESULT_OK)
                    {
                        unread_msg_list[num_of_unread_msg].msg_type = property_st->msg_type; 
                        if (property_st->receive_date != NULL)
                        {
                            unread_msg_list[num_of_unread_msg].received_date =
                                property_st->receive_date;
                        }
                        else
                        {
                            unread_msg_list[num_of_unread_msg].received_date = 0;
                        }
                        if(property_st->suffix != MMS_SUFFIX_DELIVERYREPORT &&
							property_st->suffix != MMS_SUFFIX_READREPORT &&
							app_ucs2_strlen((const kal_int8*)large_data_st->subject) > 0)
                        {
	                        app_ucs2_strncpy((kal_int8*) unread_msg_list[num_of_unread_msg].subject,
                                 (const kal_int8*)large_data_st->subject,
                                 MMA_MAX_SUBJECT_LEN - 1);
                            unread_msg_list[num_of_unread_msg].is_subject = TRUE;
	                    }
	                    else
	                    {
	                        kal_wchar *str = NULL;
#ifndef __MMI_MMS_REPORT_STATUS_SUPPORT__
	                        if (property_st->suffix == MMS_SUFFIX_DELIVERYREPORT)
	                        {
	                            str = (kal_wchar*) get_string(MMA_STR_ID_MMS_DELIVERY_REPORT);
	                        }
	                        else if (property_st->suffix == MMS_SUFFIX_READREPORT)
	                        {
	                            str = (kal_wchar*) get_string(MMA_STR_ID_MMS_READ_REPORT);
	                        }
#endif
#ifdef __MMI_MMS_GROUP_MSG__
							if ((property_st->suffix == MMS_SUFFIX_MSG) &&
									 (property_st->num_of_recipient > 1))
							{
								str = (kal_wchar*) get_string(MMA_STR_ID_MMS_GROUP_MESSAGE);
							}
#endif
                            if (app_ucs2_strlen((const kal_int8*)str) > 0)
	                        {
	                            app_ucs2_strncpy(
	                                (kal_int8*) unread_msg_list[num_of_unread_msg].subject,
	                                (const kal_int8*)str,
	                                MMA_MAX_SUBJECT_LEN - 1);
                                unread_msg_list[num_of_unread_msg].is_subject = TRUE;
	                        }
                            /* case of HS 3.1 */
                #if defined (__MMI_OP11_HOMESCREEN_0301__) || defined (__MMI_OP11_HOMESCREEN_0302__)
                            else if(property_st->msg_type != MMA_MSG_TYPE_JAVA)
                            {
                                /* There may be the case that a Java mms is received without Subject */
                                /* As we can not show the mms in normal view, so no need to show the TEXT or objects count */
                                if(strlen((char*)(large_data_st->java_app_id)) > 0)
                                {
                                    long srcLen = 0, dstLen = 0;
			                        srcLen = strlen((char*)(large_data_st->java_app_id)) + 1;
                                    dstLen = (MMA_MAX_SUBJECT_LEN - 1) * sizeof(kal_wchar);
                                    msf_charset_utf8_to_ucs2le((char*)large_data_st->java_app_id, &srcLen,
                                                         (char*) unread_msg_list[num_of_unread_msg].subject, &dstLen);
                                    unread_msg_list[num_of_unread_msg].is_text = TRUE;
                                }
                                else
                                {
                                    unread_msg_list[num_of_unread_msg].num_attach = property_st->object_count;
                                }
                            }
                #endif /* (__MMI_OP11_HOMESCREEN_0301__) || (__MMI_OP11_HOMESCREEN_0302__) */
	                    }
						if(app_ucs2_strlen((const kal_int8*) large_data_st->from_address) > 0)
						{
							app_ucs2_strncpy(
                                (kal_int8*) unread_msg_list[num_of_unread_msg].from_address,
                                (const kal_int8*)large_data_st->from_address,
                                MMA_MAX_ADDR_LEN - 1);
						}
                    #ifndef __COSMOS_MMI_PACKAGE__						
                        unread_msg_list[num_of_unread_msg].icon_id = mma_msgmgr_create_img_id(property_st, large_data_st);
                    #endif  /* __COSMOS_MMI_PACKAGE__ */
                        /* reset the context */
                        memset(large_data_st, 0x00, sizeof(mms_msg_info_large_data_struct));
						memset(property_st, 0x00, sizeof(mms_msg_info_property_struct));
					}
                    else
                    {
                        /* Give error information to subject. We need to use String ID */
                        kal_wchar *error_str = NULL;
                        kal_uint32 subject_length = 0;

                        error_str = (kal_wchar*) get_string(MMA_STR_ID_MESSAGE_CORRUPT);

                        subject_length = app_ucs2_strlen((const kal_int8*)error_str);
                        if (subject_length > 0)
                        {
                            app_ucs2_strncpy(
                                (kal_int8*) unread_msg_list[num_of_unread_msg].subject,
                                (const kal_int8*)error_str,
                                MMA_MAX_SUBJECT_LEN - 1);
                        }
                    #ifndef __COSMOS_MMI_PACKAGE__
                        unread_msg_list[num_of_unread_msg].icon_id = MMA_IMG_CORRUPT;
                    #endif   /* __COSMOS_MMI_PACKAGE__ */
                        unread_msg_list[num_of_unread_msg].received_date = 0;
                    }
                    num_of_unread_msg++;
                }
                index++;
            }
            while (msg_id != 0 && num_of_unread_msg < MMA_MAX_UNREAD_MSG_NUM &&
                   num_of_unread_msg < num_of_msg_requested && index < total_num_of_unread_msg);
        }
        /* free the memory */
        MMA_FREE(large_data_st);
		large_data_st = NULL;
		MMA_FREE(property_st);
		property_st = NULL;

        more = (index < total_num_of_unread_msg) ? 1 : 0;
        mms_mma_send_get_unread_msg_list_rsp(
            source,
            get_unread_msg_list_req_p->app_id,
            get_unread_msg_list_req_p->req_id,
            MMA_RESULT_OK,
            more,
            total_num_of_unread_msg,
            num_of_unread_msg,
            unread_msg_list);
        
        MMA_FREE(unread_msg_list);
        MMA_FREE(get_unread_msg_list_req_p);
    }
}
#else
static void mma_msgmgr_get_unread_msg_list_req_hdlr(
                module_type source,
                wap_mma_get_unread_msg_list_req_struct *get_unread_msg_list_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mma_unread_msg_list_struct *unread_msg_list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(get_unread_msg_list_req_p);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_GET_UNREAD_MSG_LIST_REQ_HDLR, "MMA MSGMGR: get unread msg list"));

    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_GET_UNREAD_MSG_LIST_MMA_NOT_READY, "MMA is not ready to get unread msg list"));
        mms_mma_send_get_unread_msg_list_rsp(
            source,
            get_unread_msg_list_req_p->app_id,
            get_unread_msg_list_req_p->req_id,
            MMA_RESULT_FAIL_NOT_READY,
            0,
            0,
            0,
            NULL);

        MMA_FREE(get_unread_msg_list_req_p);
        return;
    }
    else if (mma_main_is_in_usb_mode())
    {
        mms_mma_send_get_unread_msg_list_rsp(
            source,
            get_unread_msg_list_req_p->app_id,
            get_unread_msg_list_req_p->req_id,
            MMA_RESULT_OK,
            0,
            0,
            0,
            NULL);
        MMA_FREE(get_unread_msg_list_req_p);
        return;
    }
    else
    {
        /* Need to Provide only the total number of unread messages */
        kal_uint16 unread_msg_count = 0;
        int i = 0;
        for(; i <= MMA_MAX_SIM_COUNT; i++)
        {
            unread_msg_count += g_mma_msgmgr_cntx.mms_folder_status.folder[i].inbox_unread_msg_num ;
        }
        mms_mma_send_get_unread_msg_list_rsp(
            source,
            get_unread_msg_list_req_p->app_id,
            get_unread_msg_list_req_p->req_id,
            MMA_RESULT_OK,
            0,
            unread_msg_count,
            0,
            NULL);
        MMA_FREE(get_unread_msg_list_req_p);
        return;
    }
}
#endif
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_recent_evt_list_req_hdlr
 * DESCRIPTION
 *  This function is used to handle GET_RECENT_EVT_LIST_REQ.
 * PARAMETERS
 *  source                          [IN]        
 *  get_recent_evt_list_req_p       [?]         
 *  get_unread_msg_list_req_p       [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
static void mma_msgmgr_get_recent_evt_list_req_hdlr(
                module_type source,
                wap_mma_get_recent_evt_list_req_struct *get_recent_evt_list_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_recent_evt_list_struct *recent_evt_list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(get_recent_evt_list_req_p);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_GET_RECENT_EVT_LIST_REQ_HDLR, "MMA MSGMGR: get recent event"));

    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_GET_RECENT_EVT_LIST_REQ_MMA_NOT_READY, "MMA is not ready to get recent event list"));
        mms_mma_send_get_recent_evt_list_rsp(
            source,
            get_recent_evt_list_req_p->app_id,
            get_recent_evt_list_req_p->req_id,
            MMA_RESULT_FAIL_NOT_READY,
            0,
            0,
            0,
            NULL);

        MMA_FREE(get_recent_evt_list_req_p);
        return;
    }
    else if (mma_main_is_in_usb_mode() || (g_mma_msgmgr_cntx.recent_event_list == NULL))
    {
        mms_mma_send_get_recent_evt_list_rsp(
            source,
            get_recent_evt_list_req_p->app_id,
            get_recent_evt_list_req_p->req_id,
            MMA_RESULT_OK,
            0,
            0,
            0,
            NULL);
        MMA_FREE(get_recent_evt_list_req_p);
        return;
    }
    else if (mma_msgmgr_check_busy_state_pending_list
             (source, MMA_INT_SIG_TYPE_MSG_GET_RECENT_EVT_LIST_REQ, get_recent_evt_list_req_p))
        return;
    else
    {
        MSF_UINT32 index = (MSF_UINT32) get_recent_evt_list_req_p->start_index;
        MSF_UINT32 num_of_evt_requested = (MSF_UINT32) get_recent_evt_list_req_p->num_of_evt_requested;
        MSF_UINT32 num_of_evt = 0;
        /* get recent event number */
        MSF_UINT32 total_num_of_evt = g_mma_msgmgr_cntx.mms_folder_status.recent_event_number;
        MSF_UINT8 more = 0;
        kal_uint32 msg_id = 0;
        //mma_msg_info_list_struct *msg_info = NULL;
        mma_result_enum result = MMA_RESULT_OK;
        mms_msg_info_property_struct *property_st = NULL;
        mms_msg_info_large_data_struct *large_data_st = NULL;
        large_data_st = (mms_msg_info_large_data_struct*)MMA_CALLOC(sizeof(mms_msg_info_large_data_struct));
        ASSERT(large_data_st);                        
        property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));
        ASSERT(property_st);

        recent_evt_list =
            (mma_recent_evt_list_struct*) MMA_CALLOC(sizeof(mma_recent_evt_list_struct) * MMA_MAX_EVT_NUM);

        if (index < total_num_of_evt)
        {
            do
            {
                //msg_info = mma_msgmgr_get_recent_evt_info_by_idx(index);
                msg_id = mma_msgmgr_get_recent_evt_msg_id_by_idx(index);
                if (msg_id != 0)
                {
                    result = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_id),
                                (kal_uint8)mma_get_mms_type_message_storage(msg_id),
                                property_st, large_data_st));

                    recent_evt_list[num_of_evt].msg_id = msg_id;
                    recent_evt_list[num_of_evt].is_subject = (kal_uint8)FALSE;
                    recent_evt_list[num_of_evt].is_text = (kal_uint8)FALSE;
                    recent_evt_list[num_of_evt].num_attach = 0;
					
                    /* check for the Corrupted or normal MMS */
                    if (result == MMA_RESULT_OK)
                    {
                        if (property_st->receive_date != NULL)
                        {
                            recent_evt_list[num_of_evt].received_date =
                                property_st->receive_date; 
                        }
                        else
                        {
                            recent_evt_list[num_of_evt].received_date = 0;
                        }
					    recent_evt_list[num_of_evt].is_read = (kal_uint8)property_st->is_read;
						recent_evt_list[num_of_evt].msg_type = property_st->msg_type;

                        if(property_st->suffix != MMS_SUFFIX_DELIVERYREPORT &&
							property_st->suffix != MMS_SUFFIX_READREPORT &&
							app_ucs2_strlen((const kal_int8*)large_data_st->subject) > 0)
                        {
	                        app_ucs2_strncpy((kal_int8*) recent_evt_list[num_of_evt].subject,
                                 (const kal_int8*)large_data_st->subject,
                                 MMA_MAX_SUBJECT_LEN - 1);
                            recent_evt_list[num_of_evt].is_subject = (kal_uint8)TRUE;
                        }
                        else
                        {
                            kal_wchar *str = NULL;
                            kal_uint32 subject_length = 0;
#ifndef __MMI_MMS_REPORT_STATUS_SUPPORT__
                            if (property_st->suffix == MMS_SUFFIX_DELIVERYREPORT)
                            {
                                str = (kal_wchar*) get_string(MMA_STR_ID_MMS_DELIVERY_REPORT);
                            }
                            else if (property_st->suffix == MMS_SUFFIX_READREPORT)
                            {
                                str = (kal_wchar*) get_string(MMA_STR_ID_MMS_READ_REPORT);
                            }
#endif
#ifdef __MMI_MMS_GROUP_MSG__
                            if ((property_st->suffix == MMS_SUFFIX_MSG) &&
                                     (property_st->num_of_recipient > 1))
                            {
								str = (kal_wchar*) get_string(MMA_STR_ID_MMS_GROUP_MESSAGE);
                            }
#endif
                            subject_length = app_ucs2_strlen((const kal_int8*)str);
                            if (subject_length > 0)
                            {
                                app_ucs2_strncpy(
                                    (kal_int8*) recent_evt_list[num_of_evt].subject,
                                    (const kal_int8*)str,
                                    MMA_MAX_SUBJECT_LEN - 1);
                                recent_evt_list[num_of_evt].is_subject = (kal_uint8)TRUE;
                            }
                            /* case of HS 3.1 */
                        #if defined (__MMI_OP11_HOMESCREEN_0301__) || defined (__MMI_OP11_HOMESCREEN_0302__)
                            else if(property_st->msg_type != MMA_MSG_TYPE_JAVA)
                            {
                                if(strlen((char*)(large_data_st->java_app_id)) > 0)
                                {
                                    long srcLen = 0, dstLen = 0;
			                        srcLen = strlen((char*)(large_data_st->java_app_id)) + 1;
                                    dstLen = (MMA_MAX_SUBJECT_LEN - 1) * sizeof(kal_wchar);
                                    //msg_info->large_data->address_type = translate_mms_address_type_to_mma(sig_data->addrType);
                                    msf_charset_utf8_to_ucs2le((char*)large_data_st->java_app_id, &srcLen,
                                                         (char*) recent_evt_list[num_of_evt].subject, &dstLen);
                                    recent_evt_list[num_of_evt].is_text = (kal_uint8)TRUE;
                                }
                                else
                                {
                                    recent_evt_list[num_of_evt].num_attach = property_st->object_count;
                                }
                            }
                        #endif /* (__MMI_OP11_HOMESCREEN_0301__) || (__MMI_OP11_HOMESCREEN_0302__) */
                        }
                    #ifndef __COSMOS_MMI_PACKAGE__
                        recent_evt_list[num_of_evt].icon_id = mma_msgmgr_create_img_id(property_st, large_data_st);
                    #endif   /* __COSMOS_MMI_PACKAGE__ */
                        /* reset the context */
                        memset(large_data_st, 0x00, sizeof(mms_msg_info_large_data_struct));
						memset(property_st, 0x00, sizeof(mms_msg_info_property_struct));
					}
                    else
                    {
                        /* Give error information to subject. We need to use String ID */
                        kal_wchar *error_str = NULL;
                        kal_uint32 subject_length = 0;

                        error_str = (kal_wchar*) get_string(MMA_STR_ID_MESSAGE_CORRUPT);

                        subject_length = app_ucs2_strlen((const kal_int8*)error_str);
                        if (subject_length > 0)
                        {
                            app_ucs2_strncpy(
                                (kal_int8*) recent_evt_list[num_of_evt].subject,
                                (const kal_int8*)error_str,
                                MMA_MAX_SUBJECT_LEN - 1);
                        }
                    #ifndef __COSMOS_MMI_PACKAGE__
                        recent_evt_list[num_of_evt].icon_id = MMA_IMG_CORRUPT;
                    #endif  /* __COSMOS_MMI_PACKAGE__ */
                        recent_evt_list[num_of_evt].received_date = 0;
					    recent_evt_list[num_of_evt].is_read = (kal_uint8)1;
                    }
                    num_of_evt++;
                }
                index++;
            }
            while (msg_id != 0 && num_of_evt < MMA_MAX_EVT_NUM && num_of_evt < num_of_evt_requested &&
                   index < total_num_of_evt);
        }
        /* Free large data */
        MMA_FREE(large_data_st);
		large_data_st = NULL;
		MMA_FREE(property_st);
		property_st = NULL;

        more = (index < total_num_of_evt) ? 1 : 0;
        mms_mma_send_get_recent_evt_list_rsp(
            source,
            get_recent_evt_list_req_p->app_id,
            get_recent_evt_list_req_p->req_id,
            MMA_RESULT_OK,
            more,
            total_num_of_evt,
            num_of_evt,
            recent_evt_list);
        
        MMA_FREE(recent_evt_list);
        MMA_FREE(get_recent_evt_list_req_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_delete_recent_evt_req_hdlr
 * DESCRIPTION
 *  This function is used to delete recent event.
 * PARAMETERS
 *  source                      [IN]        
 *  delete_recent_evt_req_p     [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_delete_recent_evt_req_hdlr(
                module_type source,
                wap_mma_delete_recent_evt_req_struct *delete_recent_evt_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(delete_recent_evt_req_p);

    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_DELETE_RECENT_EVT_REQ_HDLR, "MMA MSGMGR: delete recent event"));

    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_DELETE_RECENT_EVT_REQ_MMA_NOT_READY, "MMA is not ready to delete recent event"));
        mms_mma_send_delete_recent_evt_rsp(
            source,
            delete_recent_evt_req_p->app_id,
            delete_recent_evt_req_p->req_id,
            MMA_RESULT_FAIL_NOT_READY,
            delete_recent_evt_req_p->msg_id);

        MMA_FREE(delete_recent_evt_req_p);
        return;
    }
    else if (mma_msgmgr_check_busy_state_pending_list
             (source, MMA_INT_SIG_TYPE_MSG_DELETE_RECENT_EVT_REQ, delete_recent_evt_req_p))
        return;
    else
    {
        /* delete all recent event */
        mma_msgmgr_remove_msg_from_recent_evt_list(delete_recent_evt_req_p->msg_id, KAL_TRUE);
        mms_mma_send_delete_recent_evt_rsp(
                (module_type) (kal_uint32) source,
                delete_recent_evt_req_p->app_id,
                delete_recent_evt_req_p->req_id,
                (kal_uint8) result /*MMA_RESULT_OK*/,
                delete_recent_evt_req_p->msg_id);
        MMA_FREE(delete_recent_evt_req_p);
        return;        
    }
}
#endif  /* #if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_create_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source              [IN]        
 *  create_req_p        [?]         
 *  create_req(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_create_req_hdlr(module_type source, wap_mma_create_req_struct *create_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msgmgr_create_info_struct *info = NULL;
    mma_msgmgr_new_msg_info_struct *new_msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(create_req_p);
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_CREATE_MMA_REQ_HDLR, "mma_msgmgr_create_req_hdlr(%d, %d, %d, %d)",
                 create_req_p->app_id, create_req_p->req_id, create_req_p->msg_id, create_req_p->mode));
	/*logging information */
	#ifdef MMS_CONTENT_DUMP_DATA 
	(void)mma_trace_mms_content_info(create_req_p->content_info);
	#endif	/* MMS_CONTENT_DUMP_DATA */

    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_CREATE_MMA_NOT_READY, "MMA is not ready to create MMS"));
        mma_create_send_reject_rsp(
            (module_type) (kal_uint32) source,
            create_req_p->req_id,
            create_req_p->app_id,
            create_req_p->msg_id,
            create_req_p->buffer_index,
            MMA_RESULT_FAIL_NOT_READY);

        MMA_FREE(create_req_p);
        return;
    }
    else if (mma_main_is_in_usb_mode())
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_CREATE_MMA_IN_USB_MODE, "In USB mode, MMA can not create MMS"));
        mma_create_send_reject_rsp(
            (module_type) (kal_uint32) source,
            create_req_p->req_id,
            create_req_p->app_id,
            create_req_p->msg_id,
            create_req_p->buffer_index,
           MMA_RESULT_FAIL_IN_USB_MODE);

        MMA_FREE(create_req_p);
        return;
    }
    else if (mma_main_is_in_terminate())
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_CREATE_MMA_IN_TERMINATE_MODE, "(mma_msgmgr.c): MMA is terminating. MMA can not create MMS"));
        mma_create_send_reject_rsp(
            (module_type) (kal_uint32) source,
            create_req_p->req_id,
            create_req_p->app_id,
            create_req_p->msg_id,
            create_req_p->buffer_index,
            MMA_RESULT_FAIL_TERMINATING);
        
        MMA_FREE(create_req_p);
        return;
    } 
    else if ((new_msg_info = mma_msgmgr_get_new_msg_info_by_req_id(create_req_p->req_id)) != NULL)  /* wait for next XML content */
    {
        info = (mma_msgmgr_create_info_struct*) new_msg_info->data;
        if (info != NULL && create_req_p->buffer_index == info->buffer_index + 1)       /* receiving next XML buffer: buffer_index = 1+ */
        {
            info->buffer_index++;
            info->more = create_req_p->more;
        }
        else
        {
            ASSERT(0);
        }
    }
#ifndef __COSMOS_MMI_PACKAGE__
    else if((create_req_p->app_id == MMA_APP_ID_UC) && (create_req_p->mode == MMA_MODE_TEMPLATE) &&
        (g_mma_msgmgr_cntx.mms_folder_status.userdefined_template_msg_num >= MMA_MAX_USER_DEF_TEMPLATE_NUM))
    {
        mma_create_send_reject_rsp(
                (module_type) source,
                create_req_p->req_id,
                create_req_p->app_id,
                create_req_p->msg_id,
                create_req_p->buffer_index,
                MMA_RESULT_FAIL_USERDEF_TEMPLATE_FULL);
        MMA_FREE(create_req_p);
        return;
    }
#endif   /* __COSMOS_MMI_PACKAGE__ */
    else if (g_mma_msgmgr_cntx.process_create_req_num < MMA_MSGMGR_MAX_CREATE_TASK_NUM) /* add new creation task */
    {
        info = (mma_msgmgr_create_info_struct*) MMA_CALLOC(sizeof(mma_msgmgr_create_info_struct));
        if(info == NULL)
        {
            mma_create_send_reject_rsp(
                (module_type) source,
                create_req_p->req_id,
                create_req_p->app_id,
                create_req_p->msg_id,
                create_req_p->buffer_index,
                MMA_RESULT_FAIL_INSUFFICIENT_MEMORY);

            MMA_FREE(create_req_p);
            return;
        }
        info->source = source;
        info->app_id = create_req_p->app_id;
        info->req_id = create_req_p->req_id;
        info->mode = (mma_app_mode_enum)create_req_p->mode;
        info->o_msg_id = create_req_p->msg_id;
        info->msg_filetype = MMS_SUFFIX_SEND_REQ;
        if((create_req_p->app_id == MMA_APP_ID_TEMPLATE) && (create_req_p->mode == MMA_MODE_EDIT))
        {
			info->msg_filetype = MMS_SUFFIX_TEMPLATE;
        }
    #ifdef __COSMOS_MMI_PACKAGE__
        if((create_req_p->msg_id > 0) && (mma_get_box(create_req_p->msg_id) == MMA_FOLDER_TEMPLATE)
            && (create_req_p->mode == MMA_MODE_EDIT))
        {
            info->msg_filetype = MMS_SUFFIX_TEMPLATE;
        }
    #endif
        /*if (info->mode == MMA_MODE_SEND || info->mode == MMA_MODE_FORWARD)
        {
            ASSERT(create_req_p->msg_id != 0);
            info->o_msg_id = create_req_p->msg_id;
        }
        else
        {
            ASSERT(create_req_p->msg_id == 0);
        }*/

        if (create_req_p->mode == MMA_MODE_UPLOAD)
        {
        #ifdef __MTK_TARGET__
            if (app_ucs2_strlen((kal_int8*) create_req_p->msg_file_path) > 0)
            {
                info->upload_filepath = mma_ucs2_to_utf8_string(create_req_p->msg_file_path);
            }
            else
            {
                mma_create_send_reject_rsp(
                    source,
                    create_req_p->req_id,
                    create_req_p->app_id,
                    create_req_p->msg_id,
                    create_req_p->buffer_index,
                    MMA_RESULT_FAIL_FILE_NOT_FOUND);

                MMA_FREE(create_req_p);
                MMA_FREE(info);
                return;
            }
        #else /* __MTK_TARGET__ */ 
            if(create_req_p->app_id == MMA_APP_ID_TEMPLATE)
			{
				if (app_ucs2_strlen((kal_int8*) create_req_p->msg_file_path) > 0)
				{
					info->upload_filepath = mma_ucs2_to_utf8_string(create_req_p->msg_file_path);
				}
			}
			else
			{
                info->upload_filepath = msf_cmmn_strdup(MSF_MODID_MMA, "D:\\test.mms");
			}
        #endif /* __MTK_TARGET__ */ 
        }
        else
        {
#if (defined(__MMI_MMS_VENDOR_APP_SUPPORT__) || defined(__MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__))
			if(info->mode == MMA_MODE_VENDOR_XML)
			{
            info->xml_size = create_req_p->xml_size;
            info->xml_filepath = MMA_CALLOC(app_ucs2_strlen((kal_int8*) create_req_p->xml_filepath) * ENCODING_LENGTH + 2);
            app_ucs2_strcpy((kal_int8*) info->xml_filepath, (kal_int8*) create_req_p->xml_filepath);
            info->buffer_index = create_req_p->buffer_index;
            info->more = create_req_p->more;
			}
#endif	/* __MMI_MMS_VENDOR_APP_SUPPORT__ */
			info->mms_dsr = create_req_p->content_info;
#if (defined(__MMI_MMS_VENDOR_APP_SUPPORT__) || defined(__MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__))
            if (info->mode == MMA_MODE_VENDOR_XML && mma_get_mmi_file_size(-1, info->xml_filepath) != info->xml_size)
            {
                MMA_FREE(info->xml_filepath);
                MMA_FREE(info);
                mma_create_send_reject_rsp(
                    (module_type) source,
                    create_req_p->req_id,
                    create_req_p->app_id,
                    create_req_p->msg_id,
                    create_req_p->buffer_index,
                    MMA_RESULT_FAIL_FILE_CORRUPTED);

                MMA_FREE(create_req_p);
                return;
            }
#endif	/* __MMI_MMS_VENDOR_APP_SUPPORT__ */
        }
        info->msg_id = 0;

        new_msg_info = (mma_msgmgr_new_msg_info_struct*) MMA_CALLOC(sizeof(mma_msgmgr_new_msg_info_struct));
        ASSERT(new_msg_info);
        
        new_msg_info->req_id = create_req_p->req_id;
        new_msg_info->state = MMA_MSGMGR_MSG_STATE_STARTED;
        new_msg_info->msg_type = MMA_MSGMGR_MSG_TYPE_USER_CREATE;
        new_msg_info->data = info;
    #ifdef __COSMOS_MMI_PACKAGE__
        new_msg_info->msg_sim_id = create_req_p->sim_id;
    #endif
        new_msg_info->next = NULL;

        if (mma_msgmgr_add_new_msg_info_to_list(new_msg_info) == FALSE)
        {
            ASSERT(0);
        }
        g_mma_msgmgr_cntx.process_create_req_num++;
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_CREATE_NEW_MMS_MSG_TYPE, "MMA MSGMGR new msg type %d, state %d", new_msg_info->msg_type, new_msg_info->state));
    }
    else    /* reject request */
    {
        mma_create_send_reject_rsp(
            (module_type) source,
            create_req_p->req_id,
            create_req_p->app_id,
            create_req_p->msg_id,
            create_req_p->buffer_index,
            MMA_RESULT_FAIL_BUSY);

        MMA_FREE(create_req_p);
        return;
    }

#if (defined(__MMI_MMS_VENDOR_APP_SUPPORT__) || defined(__MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__))
    if (info->more == KAL_TRUE)
    {
        mma_create_send_reject_rsp(
            (module_type) (kal_uint32) info->source,
            info->req_id,
            info->app_id,
            info->msg_id,
            info->buffer_index + 1,
             MMA_RESULT_OK);
    }
    else
#endif
    {
        mma_msgmgr_create_info_struct *int_create_req = NULL;

        /* send internal signal to MMA CREATE to create a MMS */
        int_create_req = (mma_msgmgr_create_info_struct*) MMA_CALLOC(sizeof(mma_msgmgr_create_info_struct));
        memcpy((char*)int_create_req, (char*)info, sizeof(mma_msgmgr_create_info_struct));

        if (info->upload_filepath != NULL)
        {
            int_create_req->upload_filepath = MMA_CALLOC(strlen(info->upload_filepath) + 1);
            strcpy(int_create_req->upload_filepath, info->upload_filepath);
            /* no need of this memory in future. free it */
            MMA_FREE(info->upload_filepath);
            info->upload_filepath = NULL;
        }
#if (defined(__MMI_MMS_VENDOR_APP_SUPPORT__) || defined(__MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__))
        if (info->xml_filepath != NULL)
        {
            int_create_req->xml_filepath = MMA_CALLOC(app_ucs2_strlen((kal_int8*) info->xml_filepath) * ENCODING_LENGTH + 2);
            app_ucs2_strcpy((kal_int8*) int_create_req->xml_filepath, (kal_int8*) info->xml_filepath);
            /* no need of this memory in future. free it */
            MMA_FREE(info->xml_filepath);
            info->xml_filepath = NULL;
        }
#endif
        MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_CREATE, MMA_INT_SIG_TYPE_MSG_INT_CREATE_REQ, FALSE, int_create_req);
        new_msg_info->state = MMA_MSGMGR_MSG_STATE_MMS_CREATING;
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_CREATE_NEW_MMS_MSG_TYPE2, "MMA MSGMGR new msg type %d, state %d", new_msg_info->msg_type, new_msg_info->state));
    }
    MMA_FREE(create_req_p);
}


#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_mms_attr_and_thumbnail_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source              [IN]        
 *  mms_attr_tbm_req_p        [?]         
 *  mms_attr_tbm_req_p(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_get_mms_attr_and_thumbnail_req_hdlr(module_type source, wap_mma_get_mms_thumbnail_and_attr_info_req_struct *mms_attr_tbm_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    ASSERT(mms_attr_tbm_req);

    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_MSG_ATTRIBUTE_AND_THUMBNAIL_NOT_READY, "MMA is not ready to give msg attribute and thumbnail"));
        mms_mma_send_get_msg_attr_and_thumbnail_info_rsp(
            source,
            mms_attr_tbm_req->app_id,
            MMA_RESULT_FAIL_NOT_READY,
            mms_attr_tbm_req->req_id,
			mms_attr_tbm_req->msg_id,
            NULL
            );
    }
    else if (mma_main_is_in_usb_mode())
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM,
                           MSF_MODID_MMA,
                           MMA_MSGMGR_MSG_ATTRIBUTE_AND_THUMBNAIL_REQ_USB_MODE, "(mma_msgmgr.c): MMA can not give msg attribute and thumbnail in USB mode"));
        mms_mma_send_get_msg_attr_and_thumbnail_info_rsp(
            source,
            mms_attr_tbm_req->app_id,
            MMA_RESULT_FAIL_TERMINATING,
            mms_attr_tbm_req->req_id,
			mms_attr_tbm_req->msg_id,
            NULL
            );
        MMA_FREE(mms_attr_tbm_req);
        return;
    }
    else if (mma_main_is_in_terminate())
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_ATTRIBUTE_AND_THUMBNAIL_REQ_IN_TERMINATE_MODE, "(mma_msgmgr.c): MMA is terminating. MMA can not give msg attribute and thumbnail"));
		mms_mma_send_get_msg_attr_and_thumbnail_info_rsp(
            source,
            mms_attr_tbm_req->app_id,
            MMA_RESULT_FAIL_TERMINATING,
            mms_attr_tbm_req->req_id,
			mms_attr_tbm_req->msg_id,
            NULL
			);        
        MMA_FREE(mms_attr_tbm_req);
        return;
    } 
    else if (mma_msgmgr_check_busy_state_pending_list(source, MMA_INT_SIG_TYPE_MSG_GET_ATTR_AND_THUMBNAIL_REQ, mms_attr_tbm_req))
        return;
#ifdef  __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    /* Check for the Memory Card mms in plug out state for which this req come */
    else if((mma_get_message_storage(mms_attr_tbm_req->msg_id) == MMA_MSG_STORAGE_CARD1) && (!MSF_IS_MEM_CARD_PRESNT(MSF_MMS_STORAGE_MEM_CARD_1)))
	{
		mms_mma_send_get_msg_attr_and_thumbnail_info_rsp(
            source,
            mms_attr_tbm_req->app_id,
            MMA_RESULT_FAIL_MEM_CARD_NOT_PRESENT,
            mms_attr_tbm_req->req_id,
			mms_attr_tbm_req->msg_id,
            NULL
			);
        MMA_FREE(mms_attr_tbm_req);
        return;
	}
#endif	/* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
	else
	{
	
        mma_result_enum result = MMA_RESULT_OK;
        mms_msg_info_property_struct *property_st = NULL;
        mms_msg_info_large_data_struct *large_data_st = NULL;
		mma_msg_info_list_struct *msg_info = NULL;
		msg_info = mma_msgmgr_get_msg_from_list(mms_attr_tbm_req->msg_id);
       
        property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));
        ASSERT(property_st);
        large_data_st = (mms_msg_info_large_data_struct*)
                    MMA_CALLOC(sizeof(mms_msg_info_large_data_struct));
        ASSERT(large_data_st);
        result = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(mms_attr_tbm_req->msg_id),
                                (kal_uint8)mma_get_mms_type_message_storage(mms_attr_tbm_req->msg_id),
                                property_st, large_data_st));
        if(result == MMA_RESULT_OK)
		{
            if (FALSE == MMSlib_isValidMmsMSg_Ext1((MMA_TRANSLATE_MSG_ID(mms_attr_tbm_req->msg_id)), (MmsFileType)msg_info->suffix, 
                        (kal_uint8)mma_get_mms_type_message_storage(mms_attr_tbm_req->msg_id)))
            {
                MMA_FREE(property_st);
                MMA_FREE(large_data_st);
						mms_mma_send_get_msg_attr_and_thumbnail_info_rsp(
							source,
						    mms_attr_tbm_req->app_id,  
							MMA_RESULT_FAIL_FILE_CORRUPTED,
							mms_attr_tbm_req->req_id,
							mms_attr_tbm_req->msg_id,
							NULL
							);
				MMA_FREE(mms_attr_tbm_req);
				return;

                
            }
			else
			{
				wap_mma_get_mms_thumbnail_and_attr_info_struct *rsp_info =  NULL;	
				rsp_info = 	(wap_mma_get_mms_thumbnail_and_attr_info_struct*)MMA_CALLOC(sizeof(wap_mma_get_mms_thumbnail_and_attr_info_struct));
				memset(rsp_info, 0, sizeof(wap_mma_get_mms_thumbnail_and_attr_info_struct));
				rsp_info->timestamp = property_st->receive_date;
				rsp_info->msg_type = property_st->msg_type;
				rsp_info->storage_type = mma_get_message_storage(mms_attr_tbm_req->msg_id);
				if(msg_info->suffix == MMS_SUFFIX_NOTIFICATION)
				{
					rsp_info->msg_size = mma_mms_get_msg_file_size(mms_attr_tbm_req->msg_id);
				}
				else
				{
					rsp_info->msg_size = property_st->msg_size;
				}
				rsp_info->msg_sim_id = msg_info->msg_sim_id;


				if(msg_info->suffix == MMS_SUFFIX_NOTIFICATION)
				{
					 rsp_info->body_header_data.msg_download_size = property_st->msg_size;
				}
				if(property_st->suffix != MMS_SUFFIX_DELIVERYREPORT &&
					property_st->suffix != MMS_SUFFIX_READREPORT &&
					app_ucs2_strlen((const kal_int8*)large_data_st->subject) > 0)
				{
					app_ucs2_strncpy(
								(kal_int8*) rsp_info->body_header_data.subject,
								(const kal_int8*)large_data_st->subject,
								MMA_MAX_SUBJECT_LEN - 1);
				}
				else
				{
					kal_wchar *str = NULL;

					if (property_st->suffix == MMS_SUFFIX_DELIVERYREPORT)
					{
						str = (kal_wchar*) get_string(MMA_STR_ID_MMS_DELIVERY_REPORT);
					}
					else if (property_st->suffix == MMS_SUFFIX_READREPORT)
					{
						str = (kal_wchar*) get_string(MMA_STR_ID_MMS_READ_REPORT);
					}
					if (app_ucs2_strlen((const kal_int8*)str) > 0)
					{
						app_ucs2_strncpy(
								(kal_int8*) rsp_info->body_header_data.subject,
								(const kal_int8*)str,
								MMA_MAX_SUBJECT_LEN - 1);
					}
				}

				/* thumbnail for text*/
				if( (*((kal_uint32*)(large_data_st->app_data + MMA_MSGMGR_MMS_FIRST_SLIDE_TEXT_OFFSET_POS * sizeof(MSF_UINT8))) > 0) )
				{
					rsp_info->body_header_data.thumbnail_info_txt.body_type = MMA_MEDIA_MSG_TEXT;	/* specific for text */
					rsp_info->body_header_data.thumbnail_info_txt.body_size = *((kal_uint32*)(large_data_st->app_data + MMA_MSGMGR_MMS_FIRST_SLIDE_TEXT_SIZE_POS * sizeof(MSF_UINT8)));
					rsp_info->body_header_data.thumbnail_info_txt.body_offset = *((kal_uint32*)(large_data_st->app_data + MMA_MSGMGR_MMS_FIRST_SLIDE_TEXT_OFFSET_POS * sizeof(MSF_UINT8)));
					rsp_info->body_header_data.thumbnail_info_txt.txt_encoding_scheme = *((kal_uint16*)(large_data_st->app_data + MMA_MSGMGR_MMS_FIRST_SLIDE_TEXT_CHARSET_POS * sizeof(MSF_UINT8)));
					rsp_info->body_header_data.thumbnail_info_txt.is_drm = *((kal_uint8*)(large_data_st->app_data + MMA_MSGMGR_MMS_FIRST_SLIDE_TEXT_DRM_INFO_POS * sizeof(MSF_UINT8)));
				}
				if((msg_info->suffix != MMS_SUFFIX_DELIVERYREPORT) && (msg_info->suffix != MMS_SUFFIX_READREPORT) && 
					(msg_info->suffix != MMS_SUFFIX_NOTIFICATION) && (result == MMA_RESULT_OK))
				{
					MSF_UINT8 total_object = 0;
					mma_result_enum ret = MMA_RESULT_OK;
					mmsBodyObjectInfo *thumbnail_info = (mmsBodyObjectInfo*)MMA_CALLOC(sizeof(mmsBodyObjectInfo));
					ret = translate_mms_result_to_mma(MMSlib_readBodyObjFile(MMA_TRANSLATE_MSG_ID(mms_attr_tbm_req->msg_id),
                                    (kal_uint8)mma_get_mms_type_message_storage(mms_attr_tbm_req->msg_id),
                                    &total_object, thumbnail_info, NULL, NULL));
					if((ret == MMA_RESULT_OK) && (total_object > 0))
					{
                
							rsp_info->body_header_data.thumbnail_info.body_type = (kal_uint8)thumbnail_info->body_data[0].body_type;
							rsp_info->body_header_data.thumbnail_info.body_size = (kal_uint32)thumbnail_info->body_data[0].body_size;
							rsp_info->body_header_data.thumbnail_info.body_offset = (kal_uint32)thumbnail_info->body_data[0].body_offset;
							rsp_info->body_header_data.thumbnail_info.body_name_len = thumbnail_info->body_data[0].body_name_len;
							rsp_info->body_header_data.thumbnail_info.is_drm = thumbnail_info->body_data[0].is_drm;
							if(rsp_info->body_header_data.thumbnail_info.body_name_len > 0)
							{
								app_ucs2_strncpy(
									(kal_int8*) rsp_info->body_header_data.thumbnail_info.body_name,
									(const kal_int8*)thumbnail_info->body_data[0].body_name,
									MMS_MAX_OBJECT_FILE_NAME_LEN - 1);
							}
					}
							MMA_FREE(thumbnail_info);
				}
				
				mms_mma_send_get_msg_attr_and_thumbnail_info_rsp(
							source,
						    mms_attr_tbm_req->app_id,  
							MMA_RESULT_OK,
							mms_attr_tbm_req->req_id,
							mms_attr_tbm_req->msg_id,
							rsp_info
							);

				MMA_FREE(rsp_info);
			}
		
		

		}
		else
		{
		
			mms_mma_send_get_msg_attr_and_thumbnail_info_rsp(
					source,
					mms_attr_tbm_req->app_id,  
					result,
					mms_attr_tbm_req->req_id,
					mms_attr_tbm_req->msg_id,
					NULL
					);


		
		
		
		}
		
		MMA_FREE(property_st);
		MMA_FREE(large_data_st);
	
	
	
	
	
	}


 MMA_FREE(mms_attr_tbm_req);
}

#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_int_create_rsp_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_id      [IN]        
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_int_create_rsp_hdlr(MSF_UINT32 req_id, MSF_UINT32 msg_id, MSF_INT32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msgmgr_new_msg_info_struct *new_msg_info = NULL;
    mma_msg_info_list_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_CREATE_NEW_MMS_MSG_RSP_HDLR,
                 "MMA MSGMGR recv create rsp %d, result %d, msg_id %d", req_id, result, msg_id));

    if ((new_msg_info = mma_msgmgr_get_new_msg_info_by_req_id(req_id)) != NULL)
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_CREATE_NEW_MMS_RSP, "MMA MSGMGR CREATE_RSP new msg type %d, state %d", new_msg_info->msg_type, new_msg_info->state));
        if (new_msg_info->state == MMA_MSGMGR_MSG_STATE_MMS_CREATING)
        {
            mma_msgmgr_create_info_struct *info = (mma_msgmgr_create_info_struct*) new_msg_info->data;
            new_msg_info->msg_id = msg_id;
            info->msg_id = msg_id;

            if (result != MMA_RESULT_OK)
            {
                mma_create_send_reject_rsp(
                    (module_type) (kal_uint32) info->source,
                    info->req_id,
                    info->app_id,
                    info->msg_id,
                    info->buffer_index,
                   (mma_result_enum)result);
                mma_msgmgr_free_new_msg_info(info->req_id);
                g_mma_msgmgr_cntx.process_create_req_num--;
                return;
            }            
#ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
			/* ashok need to check for the JSR sending message size */
			if (info->mode == MMA_MODE_RAW)
			{
				/* Till now, the Message ID is not added in the list. Get the path directly */
				kal_uint32 msg_size = 0;
                kal_uint8 storage_type = mma_get_message_storage(info->msg_id);
                //char *filename = MMAlib_getMessagePath(info->msg_id);
                char *filename = (char*)MMA_CALLOC(strlen("c:\\@mms\\mms_sys\\xxxxxxxx.s") + ENCODING_LENGTH);
                if (storage_type == MMA_MSG_STORAGE_PHONE)
                {
                    sprintf(filename, "%s%x.%c", MMS_PDU_FOLDER, (unsigned int)info->msg_id, MMS_SUFFIX_SEND_REQ);
                }
                else if(storage_type == MMA_MSG_STORAGE_CARD1)
                {
                    sprintf(filename, "%s%x.%c", MMS_PDU_FOLDER, (unsigned int)(MMA_TRANSLATE_MSG_ID(info->msg_id)), MMS_SUFFIX_SEND_REQ);
                }

				if ((msg_size = MSF_FILE_GETSIZE_EXT(filename, mma_get_mms_type_message_storage(info->msg_id))) > mma_get_setting_max_mms_size())
				{
					MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_CREATE_NEW_MMS_RSP_MSG_SIZE_EXCEED, "MMA MSGMGR CREATE_RSP msg_size %d", msg_size));
					mma_create_send_reject_rsp(
                    (module_type) (kal_uint32) info->source,
                    info->req_id,
                    info->app_id,
                    info->msg_id,
                    info->buffer_index,
                    (kal_uint8) MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED);
					mma_msgmgr_free_new_msg_info(info->req_id);
					g_mma_msgmgr_cntx.process_create_req_num--;
					MMA_FREE(filename);
					return; 
				}
				MMA_FREE(filename);
				filename = NULL;
			}
#endif
            /* Result is OK */
            {
                mma_result_enum res = MMA_RESULT_OK;                
                #ifdef __MMI_MMS_MMA_DRM_ENCODING__
				kal_char file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];
                int fh = 0;
				#endif

                new_msg_info->new_msg_state = MMA_MSGMGR_GET_FROM_CREATE;
                /* ashok need to handle the return type, as error may come in the functiion */ 
                res = mma_msgmgr_add_new_message_req_hdlr(msg_id, MMA_MSGMGR_GET_FROM_CREATE, 0, (kal_uint32)new_msg_info->msg_sim_id);
                if(res != MMA_RESULT_OK)
                {
			        mma_msgmgr_create_info_struct *info = NULL;
			        info = (mma_msgmgr_create_info_struct*) new_msg_info->data;
			        mma_create_send_reject_rsp(
				        (module_type) (kal_uint32) info->source,
				        info->req_id,
				        info->app_id,
				        info->msg_id,
				        info->buffer_index,
				        (mma_result_enum)res);
			        mma_msgmgr_free_new_msg_info(info->req_id);
                    g_mma_msgmgr_cntx.process_create_req_num--;
					//MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_CREATE_NEW_MMS_RSP_ERROR, "MMA MSGMGR CREATE_RSP_ERROR "));
                    return;
                }
                msg_p = mma_msgmgr_get_msg_from_list(msg_id);
                if(msg_p != NULL)
				{
				#ifdef __MMI_MMS_MMA_DRM_ENCODING__
					mma_msgmgr_get_encode_filepath(msg_id, file_path);
					if ((fh = mma_msf_file_open_in_blocking_mode(
								MSF_MODID_MMA,
								file_path,
								MSF_FILE_SET_CREATE_ALWAYS | MSF_FILE_SET_WRONLY,
								wap_custom_get_max_mms_msg_size(), mma_get_message_storage(msg_p->msg_id))) >= 0)
					{
						MSF_FILE_CLOSE(fh);
						MMA_MSGMGR_MSG_SET_FLAG(msg_p->flag, MMA_MSGMGR_MSG_OPER_NEED_DRM_ENCODE);
					}
					else
					{
						MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_CAN_NOT_OCCUPY_ENCODE_FILE_SPACE, 
                         "MMA MSGMGR can't occupy encode file space for new msg %d", msg_p->msg_id));
                        /* No need to set the flag for DRM encoding */
					}
				#endif
				}
				else
				{
					/* error while creating the MMS, response is already send */
					MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_CREATE_NEW_MMS_RSP_ERROR, "MMA MSGMGR CREATE_RSP_ERROR "));
                    return;
                }
            }
        }
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
        else if (new_msg_info->state == MMA_MSGMGR_MSG_STATE_CREATING_ENCODED_MSG)
        {
            if (result != MMA_RESULT_OK)
            {
                /* send response, delete occupied file and free new msg info */
                kal_char file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];

                mma_msgmgr_get_encode_filepath(new_msg_info->msg_id, file_path);
                MSF_FILE_REMOVE_EXT(file_path, mma_get_mms_type_message_storage(new_msg_info->msg_id));
                if (new_msg_info->msg_type == MMA_MSGMGR_MSG_TYPE_USER_CREATE)
                {
                    mma_msgmgr_create_info_struct *info = (mma_msgmgr_create_info_struct*) new_msg_info->data;

                    g_mma_msgmgr_cntx.process_create_req_num--;

                    mma_create_send_reject_rsp(
                        (module_type) (kal_uint32) info->source,
                        info->req_id,
                        info->app_id,
                        info->msg_id,
                        info->buffer_index,
                        (kal_uint8) result);
                }
                else if (new_msg_info->msg_type == MMA_MSGMGR_MSG_TYPE_DEFER_DOWNLOAD)
                {
                    mma_sendrecv_msgmgr_download_rsp_hdlr(MMS_RESULT_INSUFFICIENT_PERSISTENT_STORAGE, 0);
                }
                mma_msgmgr_free_new_msg_info(new_msg_info->req_id);
            }
            else
            {
                mma_result_enum result = MMA_RESULT_OK;
                new_msg_info->msg_id = msg_id;
                /* ashok need to handle the error case */
                result = mma_msgmgr_add_new_message_req_hdlr(msg_id, MMA_MSGMGR_GET_FROM_CREATE, 0, (kal_uint32)new_msg_info->msg_sim_id);
                if(result != MMA_RESULT_OK)
				{
					if(new_msg_info->msg_type == MMA_MSGMGR_MSG_TYPE_USER_CREATE)
					{
						mma_msgmgr_create_info_struct *info = NULL;
						info = (mma_msgmgr_create_info_struct*) new_msg_info->data;
						g_mma_msgmgr_cntx.process_create_req_num--;
						mma_create_send_reject_rsp(
							(module_type) (kal_uint32) info->source,
							info->req_id,
							info->app_id,
							info->msg_id,
							info->buffer_index,
							(kal_uint8) result);
					}
					else if (new_msg_info->msg_type == MMA_MSGMGR_MSG_TYPE_DEFER_DOWNLOAD)
					{
						mma_sendrecv_msgmgr_download_rsp_hdlr(MMS_RESULT_INSUFFICIENT_PERSISTENT_STORAGE, 0);
					}
					mma_msgmgr_free_new_msg_info(new_msg_info->req_id);
					return;
				}
                if (new_msg_info->msg_type == MMA_MSGMGR_MSG_TYPE_USER_CREATE)
                {
                    mma_msgmgr_create_info_struct *info = NULL;
                    info = (mma_msgmgr_create_info_struct*) new_msg_info->data;
                    info->msg_id = msg_id;
                }
            }
        }
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */        
        else
        {
            ASSERT(0);
        }
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_is_busy
 * DESCRIPTION
 *  This function is used to check if MMA module is busy or not.
 * PARAMETERS
 *  void
 *  void(?)     [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mma_msgmgr_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMA_MSGMGR_GET_STATE() != MMA_MSGMGR_STATE_READY)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_mms_move_ind_hdlr
 * DESCRIPTION
 *  To move the message in the destination folder.
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_mms_move_ind_hdlr(MmsResult result, kal_uint32 new_msg_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_list = g_mma_msgmgr_cntx.msg_list;
    mma_msg_info_list_struct *msg_info_p = NULL;   /* To add the new mms entry */
    mma_result_enum ret = translate_mms_result_to_mma(result);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (msg_list)
    {
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (MMA_MSGMGR_MSG_CHK_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_NEED_MOVE_MSG))
        {
            //wap_mma_event_save_msg_struct *event_info = NULL;
            wap_mma_change_msg_storage_req_struct *move_req = (wap_mma_change_msg_storage_req_struct*)g_mma_msgmgr_cntx.move_req;
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_MMS_MOVE_IND_RSP_DETAIL, "MMA MSGMGR recv move rsp %d. msg_id %d, flag %d", result, msg_list->msg_id, msg_list->flag));
            if (ret != MMA_RESULT_OK)
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM,
                                  MSF_MODID_MMA,
                                  MMA_MSGMGR_MMS_MOVE_IND_RESULT_FAIL, "(mma_msgmgr.c): fail to move msg %d. flag:%d",
                                  msg_list->msg_id, msg_list->flag));
                MMA_MSGMGR_MSG_UNSET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_NEED_MOVE_MSG);
                MMA_MSGMGR_MSG_UNSET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_MOVE_REQ_SENT);
            }
            else
            {
                /* make a entry & update the date of Pdu & info file in the checksum file */
                kal_uint8 dest_storage = MMA_MSG_STORAGE_PHONE;
                mms_msg_info_property_struct *property_st = NULL;
                property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));

                if(move_req)
                {
                    dest_storage = move_req->dest_storage;
                }
                else if(mma_get_message_storage(msg_list->msg_id) == MMA_MSG_STORAGE_PHONE)
                {
                    dest_storage = MMA_MSG_STORAGE_CARD1;
                }
                msg_info_p = (mma_msg_info_list_struct*) MMA_CALLOC(sizeof(mma_msg_info_list_struct));

                /* update the message ID as per the format */
                msg_info_p->msg_id = mma_main_encode_msg_id(dest_storage, new_msg_id);
                //msg_info_p->msg_status = MMA_MSG_STATUS_NORMAL;
                /* fill the info */
                msg_info_p->msg_sim_id = msg_list->msg_sim_id;
                msg_info_p->folder = msg_list->folder;
                msg_info_p->suffix = msg_list->suffix;
                msg_info_p->receive_date = msg_list->receive_date;
                msg_info_p->is_read = msg_list->is_read;
                msg_info_p->is_rr_send = FALSE;
                msg_info_p->new_msg_state = msg_list->new_msg_state;
                msg_info_p->prev_folder = msg_list->prev_folder;
                msg_info_p->def_noti_msg_id = msg_list->def_noti_msg_id;
                msg_info_p->mms_msg_type = msg_list->mms_msg_type;
                msg_info_p->mms_priority = msg_list->mms_priority;

                ret = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_info_p->msg_id),
                                (kal_uint8)mma_get_mms_type_message_storage(msg_info_p->msg_id),
                                property_st, NULL));
				
				/* update w.r.t Action Type */
                if(move_req && move_req->action_type == MMA_MMS_STORAGE_ACTION_COPY_MMS)
                {
                    if(ret == MMA_RESULT_OK)
                    {
                        kal_int8 modify_flag = 0;
                        //msg_info_p->receive_date = MSF_TIME_GET_SECURE_CLOCK(); // Should be new date                        
                        //property_st->receive_date = msg_info_p->receive_date;
                        if((msg_info_p->folder == MMA_FOLDER_INBOX) || (msg_info_p->folder == MMA_FOLDER_ARCHIVE))
                        {
		                    if(property_st->need_read_report)
		                    {
			                    property_st->need_read_report = FALSE;
                                modify_flag = 1;
                            }
                            if(property_st->is_rr_send)
		                    {
			                    property_st->is_rr_send = FALSE;
                                modify_flag = 1;
                            }
                            if((msg_info_p->folder == MMA_FOLDER_INBOX) &&
                                (property_st->reserve_space == MMA_MSGMGR_IS_RECENT_EVT))
                            {
                                /* This copied mms is not a recent event mms */
                                property_st->reserve_space = MMA_MSGMGR_UNSET_RECENT_EVT;
                                modify_flag = 1;
                            }
                            /* update the checksum of the property part */
                            if(modify_flag)
                            {
                                ret = translate_mms_result_to_mma(MMSlib_UpdateChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_info_p->msg_id),
                                        (MmsFileType)msg_info_p->suffix, (kal_uint8)mma_get_mms_type_message_storage(msg_info_p->msg_id),
                                        property_st, NULL));
                            }
                        }
                    }
                    /* may get error in genchksum or updatechksum operation */
                    if(ret != MMA_RESULT_OK)
                    {
                        /* Later add the entry in the list. Now, set the flag to delete this new entry */
                        MMA_MSGMGR_MSG_SET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_DELETE);
                        MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_UPDATING_MSG_LIST);
				        mma_msgmgr_send_int_perform_msg_oper_ind();
                    }
                    MMA_MSGMGR_MSG_UNSET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_NEED_MOVE_MSG);
                }
                else if(move_req && move_req->action_type == MMA_MMS_STORAGE_ACTION_MOVE_MMS)
                {
                    MMA_MSGMGR_MSG_UNSET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_NEED_MOVE_MSG);
                    if(ret == MMA_RESULT_OK)
                    {
                        /* remove the old entry of mms  */
                        MMA_MSGMGR_MSG_SET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_DELETE);
                        mma_msgmgr_update_mms_folder_status(msg_list, KAL_TRUE, msg_list->folder, 0);
                    #if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
                        if(msg_list->folder == MMA_FOLDER_INBOX)
                        {
                            if(property_st && (property_st->reserve_space == MMA_MSGMGR_IS_RECENT_EVT))
                            {
                                mma_msgmgr_add_msg_to_recent_evt_list(msg_info_p->msg_id, msg_info_p->receive_date, msg_info_p->suffix);
                            }
                        }
                    #endif
                    }
                    else
                    {
                        /* Later add the entry in the list. Now, set the flag to delete this new entry */
                        MMA_MSGMGR_MSG_SET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_DELETE);
                    }
                    MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_UPDATING_MSG_LIST);
					mma_msgmgr_send_int_perform_msg_oper_ind();
                }
                mma_msgmgr_add_msg_to_list(msg_info_p);	
                MMA_FREE(property_st);
            }
            /* Only need to send the response for request come from USer */
            if(move_req)
            {
                if(ret == MMA_RESULT_OK)
                {
                    mma_msgmgr_update_mms_folder_status(msg_info_p, KAL_FALSE, 0, msg_info_p->folder);
                }
                mms_mma_send_chg_mms_storage_rsp(
                    MOD_MMI,
                    (kal_uint8) move_req->app_id,
                    move_req->req_id,
                    move_req->msg_id,
                    move_req->action_type,
                    ret);
            }
            else
            {
                /* Case when receive a mms & Change it's storage as the preferred 
                storage is different then the storage of the received mms */
                if(ret == MMA_RESULT_OK)
                {
                    if (msg_info_p->new_msg_state == MMA_MSGMGR_GET_FROM_DEFERRED_DOWNLOAD) /* deferred download */
                    {
                        MMA_MSGMGR_MSG_SET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_REPLY_DOWNLOAD_RSP);
                    }
                    /* ashok write code for the Immediate downloaded message */
                    else if (msg_info_p->new_msg_state == MMA_MSGMGR_GET_FROM_MESSAGE) /* download full message */
                    {
                        /* ashok set flag to delete the notification msg_id */
                        /* ashok need to create a new flag for it as this notif id is not present in the message list */
                        MMA_MSGMGR_MSG_SET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_DELETE_DOWNLOAD_MSG_NOTIFID_IND);
                    }
                #ifdef __MMI_SLIM_MMS_2__
                    else if (msg_info_p->new_msg_state == MMA_MSGMGR_GET_FROM_NOTIFICATION)
                    {
                        /* send the OK result to SEND_RECV Module */
		                MMA_SIGNAL_SENDTO_I(
                                MMA_SUBMODULE_MSG_SENDRECV,
                                MMA_INT_SIG_TYPE_MSG_MMS_OBJ_RES, MMS_RESULT_OK);
                    }
                #endif /* __MMI_SLIM_MMS_2__ */
                    MMA_MSGMGR_MSG_UNSET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_NEED_MOVE_MSG);
                    /* Till now, the entry of the mms is not updated. After delete, when reduce the count create error */
                    //mma_msgmgr_update_mms_folder_status(msg_list, FALSE, 0, msg_list->folder);
				    MMA_MSGMGR_MSG_SET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_DELETE);
                    /* send the new mms ind. Also new msg ind for the RR/DR/Notification */
                    msg_info_p->new_msg_state = MMA_MSGMGR_GET_FROM_NONE;
                    MMA_MSGMGR_MSG_SET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_NEED_SEND_NEW_MSG_IND);
                #if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
                    /* Add the message in the recent event list */
                    mma_msgmgr_add_msg_to_recent_evt_list(msg_info_p->msg_id, msg_info_p->receive_date, msg_info_p->suffix);
                #endif

                    MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_UPDATING_MSG_LIST);
                    mma_msgmgr_send_int_perform_msg_oper_ind();
                }
                else
                {
                    /* Move storage get failed. Save the old mms on different storage */
                    if (msg_list->new_msg_state == MMA_MSGMGR_GET_FROM_DEFERRED_DOWNLOAD) /* deferred download */
                    {
                        MMA_MSGMGR_MSG_SET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_REPLY_DOWNLOAD_RSP);
                    }
                    /* ashok write code for the Immediate downloaded message */
                    else if (msg_list->new_msg_state == MMA_MSGMGR_GET_FROM_MESSAGE) /* download full message */
                    {
                        /* ashok set flag to delete the notification msg_id */
                        /* ashok need to create a new flag for it as this notif id is not present in the message list */
                        MMA_MSGMGR_MSG_SET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_DELETE_DOWNLOAD_MSG_NOTIFID_IND);
                    }
                #ifdef __MMI_SLIM_MMS_2__
                    else if (msg_list->new_msg_state == MMA_MSGMGR_GET_FROM_NOTIFICATION)
                    {
                        /* send the OK result to SEND_RECV Module */
		                MMA_SIGNAL_SENDTO_I(
                                MMA_SUBMODULE_MSG_SENDRECV,
                                MMA_INT_SIG_TYPE_MSG_MMS_OBJ_RES, MMS_RESULT_OK);
                    }
                #endif /* __MMI_SLIM_MMS_2__ */
                    MMA_MSGMGR_MSG_UNSET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_NEED_MOVE_MSG);
                    msg_list->new_msg_state = MMA_MSGMGR_GET_FROM_NONE;
                    MMA_MSGMGR_MSG_SET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_NEED_SEND_NEW_MSG_IND);
                #if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
                    /* Add the message in the recent event list */
                    mma_msgmgr_add_msg_to_recent_evt_list(msg_list->msg_id, msg_list->receive_date, msg_list->suffix);
                #endif
                    MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_UPDATING_MSG_LIST);
                    mma_msgmgr_send_int_perform_msg_oper_ind();
                }
            }
            if(move_req)
            {
                MMA_FREE(move_req);
                move_req = NULL;
            }
            g_mma_msgmgr_cntx.move_req = NULL;         
            return;
        }
        else
    #endif /* #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
    #ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
        if (MMA_MSGMGR_MSG_CHK_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_COPY_ARCHIVE_REQ))
        {
            wap_mma_cpy_msg_to_archive_folder_req_struct *copy_archive_req = (wap_mma_cpy_msg_to_archive_folder_req_struct*)g_mma_msgmgr_cntx.copy_archive_req;
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_MMS_MOVE_IND_RSP_DETAIL, "MMA MSGMGR recv move rsp %d. msg_id %d, flag %d", result, msg_list->msg_id, msg_list->flag));
            ASSERT(copy_archive_req);
            if (ret != MMA_RESULT_OK)
            {
                MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                                  MMA_MSGMGR_MMS_MOVE_IND_RESULT_FAIL, "(mma_msgmgr.c): fail to move msg %d. flag:%d",
                                  msg_list->msg_id, msg_list->flag));
                //MMA_MSGMGR_MSG_UNSET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_COPY_ARCHIVE_REQ);
            }
            else
            {
                /* make a entry & update the date of Pdu & info file in the checksum file */
                kal_uint8 mms_storage = mma_setting_get_preffered_storage();
                mms_msg_info_property_struct *property_st = NULL;
                mms_msg_info_large_data_struct *large_data_st = NULL;
        
                property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));
                msg_info_p = (mma_msg_info_list_struct*) MMA_CALLOC(sizeof(mma_msg_info_list_struct));
                large_data_st = (mms_msg_info_large_data_struct*)MMA_CALLOC(sizeof(mms_msg_info_large_data_struct));
                ASSERT(large_data_st);

                /* update the message ID as per the format */
                msg_info_p->msg_id = mma_main_encode_msg_id(mms_storage, new_msg_id);

                ret = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_info_p->msg_id),
                                (kal_uint8)mma_get_mms_type_message_storage(msg_info_p->msg_id),
                                property_st, large_data_st));
                if(ret == MMA_RESULT_OK)
                {
                    /* fill the info */
                    msg_info_p->msg_sim_id = msg_list->msg_sim_id;
                    msg_info_p->prev_folder = msg_list->folder;
                    msg_info_p->folder = MMA_FOLDER_ARCHIVE;
                    msg_info_p->suffix = msg_list->suffix;
                    msg_info_p->receive_date = MSF_TIME_GET_SECURE_CLOCK();
                    msg_info_p->is_read = msg_list->is_read;
                    msg_info_p->is_rr_send = FALSE;
                    msg_info_p->mms_msg_type = msg_list->mms_msg_type;
                    msg_info_p->mms_priority = msg_list->mms_priority;
                
                    /* Update the Property attributes */
                    property_st->folder = MMA_FOLDER_ARCHIVE;
                    property_st->receive_date = msg_info_p->receive_date;
                    property_st->need_read_report = FALSE;
                    property_st->is_rr_send = FALSE;
                    property_st->reserve_space = MMA_MSGMGR_UNSET_RECENT_EVT;
                    large_data_st->app_data[MMA_MSGMGR_PREV_FOLDER_POS] = msg_info_p->prev_folder;

                    /* update the checksum of the property part */
                    ret = translate_mms_result_to_mma(MMSlib_UpdateChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_info_p->msg_id),
                            msg_info_p->suffix, (kal_uint8)mma_get_mms_type_message_storage(msg_info_p->msg_id),
                            property_st, large_data_st));
                }
                MMA_FREE(property_st);
                MMA_FREE(large_data_st);
                /* may get error in genchksum or updatechksum operation */
                if(ret != MMA_RESULT_OK)
                {
                    /* Later add the entry in the list. Now, set the flag to delete this new entry */
                    MMA_MSGMGR_MSG_SET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_DELETE);
                    MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_UPDATING_MSG_LIST);
			        mma_msgmgr_send_int_perform_msg_oper_ind();
                }
                else
                {
                    mma_msgmgr_add_msg_to_list(msg_info_p);	
                    mma_msgmgr_update_mms_folder_status(msg_info_p, FALSE, 0, msg_info_p->folder);
                }
            }
            mms_mma_send_copy_msg_to_archive_rsp(
                    MOD_MMI,
                    (kal_uint8) copy_archive_req->app_id,
                    copy_archive_req->req_id,
                    copy_archive_req->msg_id,
                    ret);
            MMA_MSGMGR_MSG_UNSET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_COPY_ARCHIVE_REQ);
            MMA_FREE(copy_archive_req);
            g_mma_msgmgr_cntx.copy_archive_req = NULL;         
            return;
        }
    #endif   /* #ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__ */
        msg_list = msg_list->next;
    }
}

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_set_readmark_req_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                  [IN]        
 *  set_readmark_req_p      [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void mma_msgmgr_set_readmark_req_hdlr(module_type source, wap_mma_set_readmark_req_struct *set_readmark_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;
    mms_msg_info_property_struct *property_st = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(set_readmark_req_p);

    if (msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE ||
        msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        mms_mma_send_set_readmark_rsp(
            source,
            (kal_uint8) set_readmark_req_p->app_id,
            set_readmark_req_p->req_id,
            MMA_RESULT_FAIL_NOT_READY);

        MMA_FREE(set_readmark_req_p);
        return;
    }
#ifdef  __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    /* Check for the Memory Card mms in plug out state for which the delete req come */
    if((mma_get_message_storage(set_readmark_req_p->msg_id) == MMA_MSG_STORAGE_CARD1) && (!MSF_IS_MEM_CARD_PRESNT(MSF_MMS_STORAGE_MEM_CARD_1)))
	{
		mms_mma_send_set_readmark_rsp(
            source,
            (kal_uint8) set_readmark_req_p->app_id,
            set_readmark_req_p->req_id,
            MMA_RESULT_FAIL_MEM_CARD_PLUG_OUT);

        MMA_FREE(set_readmark_req_p);
        return;
	}
#endif
    else if (mma_msgmgr_check_busy_state_pending_list
             (source, MMA_INT_SIG_TYPE_MSG_SET_READMARK_REQ, set_readmark_req_p))
        return;
    else
    {
        property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));
        result = mma_msgmgr_set_read_status(set_readmark_req_p->msg_id, set_readmark_req_p->readmark, property_st);
        mms_mma_send_set_readmark_rsp(
            source,
            (kal_uint8) set_readmark_req_p->app_id,
            set_readmark_req_p->req_id,
            result);
        MMA_FREE(set_readmark_req_p);
        MMA_FREE(property_st);
    }
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_drm_encode_done_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_id          [IN]        
 *  msg_id          [IN]        
 *  result          [IN]        
 *  encode_msg      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_drm_encode_done_hdlr(
                MSF_UINT32 req_id,
                MSF_UINT32 msg_id,
                MSF_UINT32 result,
                MSF_INT32 encode_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msgmgr_new_msg_info_struct *new_msg_info = NULL;
    mma_msg_info_list_struct *msg_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_DRM_ENCODE_DONE_HDLR,
                 "MMA MSGMGR recv encode rsp %d, result %d, msg_id %d", req_id, result, msg_id));

    if ((new_msg_info = mma_msgmgr_get_new_msg_info_by_req_id(req_id)) != NULL)
    {
        msg_p = mma_msgmgr_get_msg_from_list(msg_id);
        if(msg_p == NULL)
        {
            /* It should not be NULL */
            ASSERT(0);
        }

        /* if (!MMA_MSGMGR_MSG_CHK_FLAG(msg_p->flag, MMA_MSGMGR_MSG_OPER_NEED_DRM_ENCODE) ||
           !MMA_MSGMGR_MSG_CHK_FLAG(msg_p->flag, MMA_MSGMGR_MSG_OPER_DRM_ENCODE_REQ_SENT))
           {
           EXT_ASSERT(0, (int)msg_id, (int)msg_p->flag, 0);
           } */

        MMA_MSGMGR_MSG_UNSET_FLAG(msg_p->flag, MMA_MSGMGR_MSG_OPER_NEED_DRM_ENCODE);
        MMA_MSGMGR_MSG_UNSET_FLAG(msg_p->flag, MMA_MSGMGR_MSG_OPER_DRM_ENCODE_REQ_SENT);

        if (result == MMA_RESULT_OK && encode_msg == TRUE)
        {
            msg_p->flag = 0;
            MMA_MSGMGR_MSG_SET_FLAG(msg_p->flag, MMA_MSGMGR_MSG_OPER_DELETE);
            /* Put a hack. To increment the Old mms count. 
            So, that at the delete process, when it is get deleted, 
            then there will be no side effect */
            //mma_msgmgr_update_mms_folder_status(msg_p, FALSE, 0, msg_p->folder);
            if (MMA_MSGMGR_GET_STATE() == MMA_MSGMGR_STATE_READY)
            {
                MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_UPDATING_MSG_LIST);
            }
            new_msg_info->state = MMA_MSGMGR_MSG_STATE_DELETE_OLD_MSG;
            new_msg_info->new_msg_state = msg_p->new_msg_state;
            new_msg_info->def_noti_msg_id = msg_p->def_noti_msg_id;
			new_msg_info->msg_sim_id = msg_p->msg_sim_id;
        }
        else
        {
            char file_path[MMA_MAX_INTERNAL_FILENAME_LENGTH];
            if(result == MMA_RESULT_FAIL_SUSPENDED_MODE)
			{
				/* Encoding get delayed due to less memory.*/
                msg_p->flag = 0;
                MMA_MSGMGR_MSG_SET_FLAG(msg_p->flag, MMA_MSGMGR_MSG_OPER_DRMSRV_ENCODING_SUSPENDED);
                mma_msgmgr_send_int_perform_msg_oper_ind();
				return;
			}
            mma_msgmgr_get_encode_filepath(msg_id, file_path);
            MSF_FILE_REMOVE_EXT(file_path, mma_get_mms_type_message_storage(new_msg_info->msg_id));
			if(result == MMA_RESULT_FAIL_TERMINATING)
			{
				/* MMA is terminating. No need to parse this Message.*/
				return;
			}
            new_msg_info->state = MMA_MSGMGR_MSG_STATE_MMS_PARSING;
            MMA_MSGMGR_MSG_SET_FLAG(msg_p->flag, MMA_MSGMGR_MSG_OPER_NEED_PARSE);
        }
        mma_msgmgr_send_int_perform_msg_oper_ind();
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_is_drm_encoding_started
 * DESCRIPTION
 *  Check for the encoding process
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mma_msgmgr_is_drm_encoding_started(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_msgmgr_cntx.msg_list == NULL)
    {
        return KAL_FALSE;
    }
    else
    {
        mma_msg_info_list_struct *msg_list_p = g_mma_msgmgr_cntx.msg_list;

        while (msg_list_p)
        {
            if (MMA_MSGMGR_MSG_CHK_FLAG(msg_list_p->flag, MMA_MSGMGR_MSG_OPER_DRM_ENCODE_REQ_SENT))
            {
                MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, 
                    MMA_MSGMGR_ENCODING_IS_GOING_ON, "(mma_msgmgr.c): Check Encoding:TRUE"));
                return TRUE;
            }
            msg_list_p = msg_list_p->next;
        }
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_check_parsing_status
 * DESCRIPTION
 *  Check for the parsing process
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mma_msgmgr_check_parsing_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_msgmgr_cntx.msg_list == NULL)
    {
        return KAL_FALSE;
    }
    else
    {
        mma_msg_info_list_struct *msg_list_p = g_mma_msgmgr_cntx.msg_list;

        while (msg_list_p)
        {
            if (MMA_MSGMGR_MSG_CHK_FLAG(msg_list_p->flag, MMA_MSGMGR_MSG_OPER_PARSING_STATUS_IND))
            {
                MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, 
                    MMA_MSGMGR_PARSING_IS_GOING_ON, "(mma_msgmgr.c): Check parsing:TRUE"));
                return TRUE;
            }
            msg_list_p = msg_list_p->next;
        }
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_content_req_hdlr
 * DESCRIPTION
 *  Handle the response signal
 * PARAMETERS
 *  sig         [IN]        
 *  sigData     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static void mma_msgmgr_get_content_req_hdlr(module_type source, wap_mma_get_content_req_struct *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(p != NULL);
    if ((p->mode == MMA_MODE_ABORT) || (mma_main_is_in_usb_mode()) || (mma_main_is_in_terminate()))
    {
        MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_PARSE, MMA_INT_SIG_TYPE_MSG_PARSE_REQ, source, p);
    }
    else
    {
        mma_msg_info_list_struct *msg_info_p = NULL;
        msg_info_p = mma_msgmgr_get_msg_from_list(p->msg_id);
        if(msg_info_p)
        {
            MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_PARSE, MMA_INT_SIG_TYPE_MSG_PARSE_REQ, source, p);
            MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, 
                    MMA_MSGMGR_SET_PARSING_STATUS, "(mma_msgmgr.c): Set parsing status"));
            MMA_MSGMGR_MSG_SET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_PARSING_STATUS_IND);
        }
        else
        {

                mma_parse_send_direct_rsp(
                    source,
                    p->req_id,
                    p->app_id,
                    p->msg_id,
                    p->mode,
                    MMA_RESULT_FAIL_INVALID_MSGID);
                MMA_FREE(p);
            }
        }
    }


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_check_encoding_suspended
 * DESCRIPTION
 *  check for the suspended encoding process
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void mma_msgmgr_resume_suspended_encoding()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mma_msgmgr_cntx.msg_list == NULL)
    {
        return;
    }
    else
    {
        mma_msg_info_list_struct *msg_list_p = g_mma_msgmgr_cntx.msg_list;

        while (msg_list_p)
        {
            if (MMA_MSGMGR_MSG_CHK_FLAG(msg_list_p->flag, MMA_MSGMGR_MSG_OPER_DRMSRV_ENCODING_SUSPENDED))
            {
                MMA_MSGMGR_MSG_UNSET_FLAG(msg_list_p->flag, MMA_MSGMGR_MSG_OPER_DRMSRV_ENCODING_SUSPENDED);
                MMA_MSGMGR_MSG_SET_FLAG(msg_list_p->flag, MMA_MSGMGR_MSG_OPER_NEED_DRM_ENCODE);
                //return;   /* can be a case of multi DRM encoding request */
            }
            msg_list_p = msg_list_p->next;
        }
        return;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_reset_parsing_status
 * DESCRIPTION
 *  Reset the flag for the parsing process
 * PARAMETERS
 *  sig         [IN]        
 *  sigData     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mma_msgmgr_reset_parsing_status(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info_p = mma_msgmgr_get_msg_from_list(msg_id);
    if(msg_info_p)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, 
                    MMA_MSGMGR_RESET_PARSING_STATUS, "(mma_msgmgr.c): Reset parsing status"));
        MMA_MSGMGR_MSG_UNSET_FLAG(msg_info_p->flag, MMA_MSGMGR_MSG_OPER_PARSING_STATUS_IND);
        /* Resume the encoding Procedure */
        mma_msgmgr_resume_suspended_encoding();
    }
}

#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_msg_property_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source                      [IN]        
 *  get_msg_property_req        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_get_msg_property_req_hdlr(module_type source, wap_mma_get_msg_property_req_struct *get_msg_property_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(get_msg_property_req);

    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        //MSF_LOG_MSG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                          // "MMA is not ready to get msg property\n"));

        mms_mma_send_get_msg_property_rsp(
            source,
            get_msg_property_req->app_id,
            MMA_RESULT_FAIL_NOT_READY,
            get_msg_property_req->req_id,
            get_msg_property_req->no_of_msg,
            NULL);
    }
    else if (mma_msgmgr_give_msg_info_to_app() == FALSE)
    { 
        mma_send_int_sig(
            &(g_mma_msgmgr_cntx.pending_req_list),
            MMA_SUBMODULE_MSG_MGR,
            MMA_INT_SIG_TYPE_MSG_GET_MSG_PROPERTY_REQ,
            source,
            0,
            0,
            0,
            get_msg_property_req);
        return;
    }
    else
    {
        mma_msg_property_struct *mma_msg_property = (mma_msg_property_struct*)MMA_CALLOC(sizeof(mma_msg_property_struct) * MMA_MAX_MSG_ARRAY_NUM);

        memset(mma_msg_property, 0x00, sizeof(mma_msg_property_struct) * MMA_MAX_MSG_ARRAY_NUM);
        for (index = 0; index < get_msg_property_req->no_of_msg; index++)
        {
            mma_msg_info_list_struct *msg_info_p = mma_msgmgr_get_msg_from_list(get_msg_property_req->msg_id[index]);
            mma_msg_property[index].msg_id = get_msg_property_req->msg_id[index];
			
            
            if ((msg_info_p != NULL) && (msg_info_p->mms_msg_type == MMA_MSG_TYPE_UNSUPPORTED))
            {
                mma_msg_property[index].is_read = (kal_bool)msg_info_p->is_read;
                mma_msg_property[index].msg_type = msg_info_p->mms_msg_type;
                mma_msg_property[index].is_valid = KAL_TRUE;
            }
            else if (msg_info_p != NULL)
            {
                MSF_UINT32 result = MMA_RESULT_OK;
                mms_msg_info_property_struct *property_st = NULL;

                mma_msg_property[index].is_read = (kal_bool)msg_info_p->is_read;
                property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));
                ASSERT(property_st);

                result = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_info_p->msg_id),
                            (kal_uint8)mma_get_mms_type_message_storage(msg_info_p->msg_id),
                            property_st, NULL));

                if (result == MMA_RESULT_OK)
                {
                    mma_msg_property[index].msg_type = property_st->msg_type;
                    mma_msg_property[index].is_valid = KAL_TRUE;
                }
				MMA_FREE(property_st);
				property_st = NULL;
            }
        }
        mms_mma_send_get_msg_property_rsp(
            source,
            get_msg_property_req->app_id,
            MMA_RESULT_OK,
            get_msg_property_req->req_id,
            get_msg_property_req->no_of_msg,
            mma_msg_property);
        MMA_FREE(mma_msg_property);
    }
    MMA_FREE(get_msg_property_req);
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_mark_rr_req_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                  [IN]        
 *  mark_rr_req_p           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mma_msgmgr_mark_rr_req_hdlr(module_type source, wap_mma_rr_mark_req_struct *mark_rr_req_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_p = NULL;
    mma_result_enum result = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mark_rr_req_p);

    if (msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE ||
        msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        mms_mma_send_mark_rr_rsp(
            source,
            (kal_uint8) mark_rr_req_p->app_id,
            mark_rr_req_p->req_id,
            MMA_RESULT_FAIL_NOT_READY);

        MMA_FREE(mark_rr_req_p);
        return;
    }
    else if (mma_msgmgr_check_busy_state_pending_list
             (source, MMA_INT_SIG_TYPE_MSG_RR_MARK_REQ, mark_rr_req_p))
        return;
    else
    {
        msg_p = mma_msgmgr_get_msg_from_list(mark_rr_req_p->msg_id);
        if (msg_p == NULL)
        {
            mms_mma_send_mark_rr_rsp(
                source,
                (kal_uint8) mark_rr_req_p->app_id,
                mark_rr_req_p->req_id,
                MMA_RESULT_FAIL_INVALID_MSGID);

            MMA_FREE(mark_rr_req_p);
            return;
        }
        msg_p->is_rr_send = mark_rr_req_p->rr_mark;
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
#endif
        mms_mma_send_mark_rr_rsp(
                source,
                (kal_uint8) mark_rr_req_p->app_id,
                mark_rr_req_p->req_id,
                result);
        MMA_FREE(mark_rr_req_p);
    }
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */

#ifndef __MMI_FMGR_HIDE_FORMAT_DRIVE__ 
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_mms_list_format_req_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                  [IN]        
 *  mark_rr_req_p           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mma_msgmgr_mms_list_format_req_hdlr(kal_uint8 drive_enum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_list_p = g_mma_msgmgr_cntx.msg_list;
    //mma_result_enum result = MMA_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* This Primitive come when MMa & MMS is ready. No need for error check. free the list */
    /* Still check the case of creation of a mms */
    if(g_mma_msgmgr_cntx.new_msg_req_queue != NULL)
    {
        /* Creation process is going on. Can't format now. */
        mma_send_int_sig(
            &(g_mma_msgmgr_cntx.pending_req_list),
            MMA_SUBMODULE_MSG_MGR,
            MMA_INT_SIG_TYPE_MSG_FMT_FORMAT_IND,
            drive_enum,
            0,
            0,
            0,
            NULL);
		return;
    }
    /* update the first node in the global list */
    MMSlib_fldrMgrFormatDriveReq((kal_uint8)translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)drive_enum));
    g_mma_msgmgr_cntx.msg_list = NULL;
    while(msg_list_p != NULL)
    {
        mma_msg_info_list_struct *temp = msg_list_p;
        if(mma_get_message_storage(temp->msg_id) == drive_enum)
        {
            msg_list_p = msg_list_p->next;
            mma_msgmgr_update_mms_folder_status(temp, KAL_TRUE, temp->folder, 0);
        #if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
            /* Update the recent event list */
            if(temp->folder == MMA_FOLDER_INBOX)
            {
                mma_msgmgr_remove_msg_from_recent_evt_list(temp->msg_id, KAL_FALSE);
            }
        #endif
            MMA_FREE(temp);
		    temp = NULL;
        }
        else
        {
            g_mma_msgmgr_cntx.msg_list = msg_list_p;
            break;
        }
    }
    /* the first node is the Phone Node. Check for the next node */
    while ((msg_list_p) && (msg_list_p->next != NULL))
    {
        mma_msg_info_list_struct *temp = NULL;
        if(mma_get_message_storage(msg_list_p->next->msg_id) == drive_enum)
        {
            temp = msg_list_p->next;
            msg_list_p->next = msg_list_p->next->next;
            temp->next = NULL;
            mma_msgmgr_update_mms_folder_status(temp, KAL_TRUE, temp->folder, 0);
        #if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
            /* Update the recent event list */
            if(temp->folder == MMA_FOLDER_INBOX)
            {
                mma_msgmgr_remove_msg_from_recent_evt_list(temp->msg_id, KAL_FALSE);
            }
        #endif
            MMA_FREE(temp);
		    temp = NULL;
        }
        else
        {
            msg_list_p = msg_list_p->next;
        }
    }
    /* Put extra check for the Count of mms in Different folder */
    if(g_mma_msgmgr_cntx.msg_list == NULL)
    {
        memset(&g_mma_msgmgr_cntx.mms_folder_status, 0x00, sizeof(mma_mms_folder_mms_count_status_struct));
    }
    mma_main_exit_terminate_mode();
    mma_send_fmt_format_rsp(drive_enum);
}
#endif /* __MMI_FMGR_HIDE_FORMAT_DRIVE__ */

#ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_copy_mms_to_archive_req_hdlr
 * DESCRIPTION
 *  This function is used to make another Copy of mms in Archive folder
 * PARAMETERS
 *  source                  [IN]        
 *  mark_rr_req_p           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mma_msgmgr_copy_mms_to_archive_req_hdlr(module_type source, wap_mma_cpy_msg_to_archive_folder_req_struct *cpy_archive_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_p = NULL;
    kal_uint8 mms_storage;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(cpy_archive_p);

    if (msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE ||
        msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        mms_mma_send_copy_msg_to_archive_rsp(
            source,
            (kal_uint8) cpy_archive_p->app_id,
            cpy_archive_p->req_id,
            cpy_archive_p->msg_id,
            MMA_RESULT_FAIL_NOT_READY);

        MMA_FREE(cpy_archive_p);
        return;
    }
    else if (mma_msgmgr_check_busy_state_pending_list
             (source, MMA_INT_SIG_TYPE_MSG_CPY_TO_ARCHIVE_REQ, cpy_archive_p))
        return;
    else
    {
        msg_p = mma_msgmgr_get_msg_from_list(cpy_archive_p->msg_id);
        if (msg_p == NULL)
        {
            mms_mma_send_copy_msg_to_archive_rsp(
                source,
                (kal_uint8) cpy_archive_p->app_id,
                cpy_archive_p->req_id,
                cpy_archive_p->msg_id,
                MMA_RESULT_FAIL_INVALID_MSGID);

            MMA_FREE(cpy_archive_p);
            return;
        }
        mms_storage = mma_setting_get_preffered_storage();
        if(((mms_storage == MMA_MSG_STORAGE_PHONE) && (g_mma_msgmgr_cntx.mms_folder_status.total_phone_mms >= (wap_custom_get_max_mms_num() - 1)))
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            || ((mms_storage == MMA_MSG_STORAGE_CARD1) && (g_mma_msgmgr_cntx.mms_folder_status.total_mcard_mms >= wap_custom_get_max_mms_num_on_card()))
        #endif
            )
        {
            mms_mma_send_copy_msg_to_archive_rsp(
                source,
                (kal_uint8) cpy_archive_p->app_id,
                cpy_archive_p->req_id,
                cpy_archive_p->msg_id,
                MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED);

            MMA_FREE(cpy_archive_p);
            return;
            
        }
        g_mma_msgmgr_cntx.copy_archive_req = (void*)cpy_archive_p;
        /* send a primitive to lower layer. After get the response from the lower layer, update the entry */
        MMA_MSGMGR_MSG_SET_FLAG(msg_p->flag, MMA_MSGMGR_MSG_OPER_COPY_ARCHIVE_REQ);
        MMSif_moveMessage(
                    MSF_MODID_MMA,
                    MMA_TRANSLATE_MSG_ID(msg_p->msg_id),
                    msg_p->suffix,
                    (MSF_UINT8) mma_get_mms_type_message_storage(msg_p->msg_id),
                    (MSF_UINT8) translate_mma_storage_to_mms_storage_enum(mms_storage), (MSF_UINT8)FALSE); 
        MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_UPDATING_MSG_LIST);
        mma_msgmgr_send_int_perform_msg_oper_ind();
    }
}
#endif   /* __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__ */

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_chg_mms_storage_req_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  source                  [IN]        
 *  chg_msg_storage_p           [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mma_msgmgr_chg_mms_storage_req_hdlr(module_type source, wap_mma_change_msg_storage_req_struct *chg_msg_storage_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_p = NULL;
    //mma_result_enum result = MMA_RESULT_OK;
    MSF_BOOL is_move_msg = TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(chg_msg_storage_p);

    if (msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE ||
        msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        mms_mma_send_chg_mms_storage_rsp(
            source,
            (kal_uint8) chg_msg_storage_p->app_id,
            chg_msg_storage_p->req_id,
            chg_msg_storage_p->msg_id,
            chg_msg_storage_p->action_type,
            MMA_RESULT_FAIL_NOT_READY);

        MMA_FREE(chg_msg_storage_p);
        return;
    }
    else if (mma_msgmgr_check_busy_state_pending_list
             (source, MMA_INT_SIG_TYPE_MSG_CHG_STORAGE_REQ, chg_msg_storage_p))
        return;
    else
    {
        msg_p = mma_msgmgr_get_msg_from_list(chg_msg_storage_p->msg_id);
        if (msg_p == NULL)
        {
            mms_mma_send_chg_mms_storage_rsp(
                source,
                (kal_uint8) chg_msg_storage_p->app_id,
                chg_msg_storage_p->req_id,
                chg_msg_storage_p->msg_id,
                chg_msg_storage_p->action_type,
                MMA_RESULT_FAIL_INVALID_MSGID);

            MMA_FREE(chg_msg_storage_p);
            return;
        }
        /* check if the request come for the same storage */
        if(chg_msg_storage_p->dest_storage == mma_get_message_storage(msg_p->msg_id))
        {
            mms_mma_send_chg_mms_storage_rsp(
                source,
                (kal_uint8) chg_msg_storage_p->app_id,
                chg_msg_storage_p->req_id,
                chg_msg_storage_p->msg_id,
                chg_msg_storage_p->action_type,
                MMA_RESULT_FAIL);

            MMA_FREE(chg_msg_storage_p);
            return;
            
        }
			/*check for the availability of destination storage*/
        if((chg_msg_storage_p->dest_storage == MMA_MSG_STORAGE_CARD1) && (!MSF_IS_MEM_CARD_PRESNT(MSF_MMS_STORAGE_MEM_CARD_1)))
        {
            mms_mma_send_chg_mms_storage_rsp(
                source,
                (kal_uint8) chg_msg_storage_p->app_id,
                chg_msg_storage_p->req_id,
                chg_msg_storage_p->msg_id,
                chg_msg_storage_p->action_type,
                MMA_RESULT_FAIL_MEM_CARD_NOT_PRESENT);

            MMA_FREE(chg_msg_storage_p);
            return;
            
        }   

        /* check if the max mms state is reached */
        if(((chg_msg_storage_p->dest_storage == MMA_MSG_STORAGE_PHONE) && (g_mma_msgmgr_cntx.mms_folder_status.total_phone_mms >= (wap_custom_get_max_mms_num() - 1))) ||
        	((chg_msg_storage_p->dest_storage == MMA_MSG_STORAGE_CARD1) && (g_mma_msgmgr_cntx.mms_folder_status.total_mcard_mms >= wap_custom_get_max_mms_num_on_card())))
        {
            mms_mma_send_chg_mms_storage_rsp(
                source,
                (kal_uint8) chg_msg_storage_p->app_id,
                chg_msg_storage_p->req_id,
                chg_msg_storage_p->msg_id,
                chg_msg_storage_p->action_type,
                MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED);

            MMA_FREE(chg_msg_storage_p);
            return;
            
        }                        
        if (g_mma_msgmgr_cntx.move_req != NULL)
        {
            MMA_FREE(g_mma_msgmgr_cntx.move_req);
        }
        g_mma_msgmgr_cntx.move_req = (void*)chg_msg_storage_p;
        /* send a primitive to lower layer. After get the response from the lower layer, update the entry */
        MMA_MSGMGR_MSG_SET_FLAG(msg_p->flag, MMA_MSGMGR_MSG_OPER_NEED_MOVE_MSG);
        
        if (chg_msg_storage_p->action_type == MMA_MMS_STORAGE_ACTION_COPY_MMS)
        {
            is_move_msg = FALSE;
        }

        MMSif_moveMessage(
                    MSF_MODID_MMA,
                    MMA_TRANSLATE_MSG_ID(msg_p->msg_id),
                    msg_p->suffix,
                    (MSF_UINT8) mma_get_mms_type_message_storage(msg_p->msg_id),
                    (MSF_UINT8) translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)chg_msg_storage_p->dest_storage), (MSF_UINT8)is_move_msg); // In case of move message it should be true, so that timestamp is not update
        MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_UPDATING_MSG_LIST);
        mma_msgmgr_send_int_perform_msg_oper_ind();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_mem_card_plug_in_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_mem_card_plug_in_req_hdlr(mms_mem_card_plug_in_out_struct *mem_card_struct)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE ||
        msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        /* ashok, no need to do anything. simply return */
        MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_MAIN, MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_IN_RES, mem_card_struct->drv_list[0], NULL);
		
    }
    else if(!MSF_IS_MEM_CARD_PRESNT(MSF_MMS_STORAGE_MEM_CARD_1))
	{
		/* send the plug-in response to mma main */
		MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_READY);
		MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_MAIN, MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_IN_RES, mem_card_struct->drv_list[0], NULL);
		/* To execute the pending message. Get msg num by umms */
		mma_msgmgr_send_int_notify_ind();
	}
    else
    {
        /*get the list of the memory card */
        mma_reset_last_tick();
        MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_CREATE_CARD_PLUG_IN_MSG_LIST);
        MMSif_getMMSList(MSF_MODID_MMA, 0, MAX_MMS_GET_CARD_LIST_COUNT - 1, MSF_MMS_STORAGE_MEM_CARD_1);
    }
    MMA_FREE(mem_card_struct);
}

/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_mem_card_plug_out_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_mem_card_plug_out_req_hdlr(mms_mem_card_plug_in_out_struct *mem_card_struct)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_list_p = g_mma_msgmgr_cntx.msg_list;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check for the FALSE case */
    
    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        /* ashok, no need to do anything. simply return */
        MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_MAIN, MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_OUT_RES, mem_card_struct->drv_list[0], NULL);
    }
    else if (mma_msgmgr_check_busy_state_pending_list((module_type)0, MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_OUT_IND, mem_card_struct))
    {
        return;
    }
    else
    {
        /* update the first node in the global list */
        g_mma_msgmgr_cntx.msg_list = NULL;
        while(msg_list_p != NULL)
        {
            mma_msg_info_list_struct *temp = msg_list_p;
            if(mma_get_message_storage(temp->msg_id) == mem_card_struct->drv_list[0])
            {
                msg_list_p = msg_list_p->next;
                mma_msgmgr_update_mms_folder_status(temp, KAL_TRUE, temp->folder, 0);
            #if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
                if(temp->folder == MMA_FOLDER_INBOX)
                {
                    /* if the recent event flag is not ON, then this msg_id is not
                    in recent event list. Calling this API have no side effect*/
                    mma_msgmgr_remove_msg_from_recent_evt_list(temp->msg_id, KAL_FALSE);
                }
            #endif
                MMA_FREE(temp);
		        temp = NULL;
            }
            else
            {
                g_mma_msgmgr_cntx.msg_list = msg_list_p;
                //msg_list_p = msg_list_p->next;
                break;
            }
        }
        /* the first node is the Phone Node. Check for the next node */
        while ((msg_list_p) && (msg_list_p->next != NULL))
        {
            mma_msg_info_list_struct *temp = NULL;
            if(mma_get_message_storage(msg_list_p->next->msg_id) == mem_card_struct->drv_list[0])
            {
                temp = msg_list_p->next;
                msg_list_p->next = msg_list_p->next->next;
                temp->next = NULL;
                mma_msgmgr_update_mms_folder_status(temp, KAL_TRUE, temp->folder, 0);
            #if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
                if(temp->folder == MMA_FOLDER_INBOX)
                {
                    /* if the recent event flag is not ON, then this msg_id is not
                    in recent event list. Calling this API have no side effect*/
                    mma_msgmgr_remove_msg_from_recent_evt_list(temp->msg_id, KAL_FALSE);
                }
            #endif
                MMA_FREE(temp);
		        temp = NULL;
            }
            else
            {
                msg_list_p = msg_list_p->next;
            }
        }
        MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_MAIN, MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_OUT_RES, mem_card_struct->drv_list[0], NULL);
        /* To refresh the UM list. Refresh ind from UMMS takes time to result in error at UM end */
        mms_mma_send_um_refresh_ind(MOD_MMI, MMA_FOLDER_ALL);
    }
    MMA_FREE(mem_card_struct);
}
#endif /*__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/

#ifdef __MMI_MMS_CONVERSATION_BOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_um_get_conv_list_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source              [IN]        
 *  get_list_req        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_um_get_conv_list_req_hdlr(module_type source, srv_um_traverse_msg_req_struct *get_conv_list_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(get_conv_list_req);

    if (msm_get_module_status(MSF_MODID_MMA) != MODULE_STATUS_ACTIVE)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                           MMA_MSGMGR_UM_GET_LIST_REQ_MMA_NOT_READY, "MMA is not ready to get um list\n"));

        mms_mma_send_um_get_conv_list_rsp(
            source,
            get_conv_list_req->app_id,
            KAL_FALSE, 0, KAL_FALSE);
        MMA_FREE(get_conv_list_req);
        return;
    }
    else if (mma_main_is_in_usb_mode())
    {
        mms_mma_send_um_get_conv_list_rsp(
            source,
            get_conv_list_req->app_id,
            KAL_TRUE, 0, KAL_FALSE);
        MMA_FREE(get_conv_list_req);
        return;
    }
	else if (mma_msgmgr_give_msg_info_to_app() == FALSE)
    {
        mma_send_int_sig(
            &(g_mma_msgmgr_cntx.pending_req_list),
            MMA_SUBMODULE_MSG_MGR,
            MMA_INT_SIG_TYPE_MSG_UM_TRAVERSE_MSG_REQ,
            source,
            0,
            0,
            0,
            get_conv_list_req);
		return;
    }
    else
    {
        mma_msg_info_list_struct *msg_info = NULL;
        srv_um_msg_detail_struct *data = NULL;
        srv_um_result_enum um_result = SRV_UM_RESULT_OK;
        kal_uint32 index = 0;
        kal_uint32 num_of_msg = 0;
        kal_int32 total_msg_number = 0;
		mma_msg_storage_type_enum storage_filter = (mma_msg_storage_type_enum)g_mma_setting_cntx.setting->storage_filter;		/*Conversation list based on stoarge filter*/
        kal_bool more = KAL_FALSE;
        
        /* Data need to be provided in two ways */
        if(get_conv_list_req->start_entry == -1)
        {
            /* Provide the info based on input message ID list */
            total_msg_number = get_conv_list_req->msg_number;
        }
        else
        {
            mma_msgmgr_msg_num_status_strcut msg_status = {0};
            msg_status.msg_sim_id = MMA_SIM_ID_TOTAL;
            index = get_conv_list_req->start_entry;
            if (mma_msgmgr_get_msg_num_of_each_folder(&msg_status) == MMA_RESULT_OK)
            {
                /* Provide the info based on Folder */
                switch (get_conv_list_req->msg_box_type)
                {
                    case SRV_UM_MSG_BOX_INBOX:
                        total_msg_number =
                            msg_status.inbox_read_msg_number + msg_status.inbox_unread_msg_number;
                        break;
                    case SRV_UM_MSG_BOX_UNSENT:
                        total_msg_number = msg_status.unsent_msg_number;
                        break;
                    case SRV_UM_MSG_BOX_SENT:
                        total_msg_number = msg_status.sent_msg_number;
                        break;
                #ifdef __COSMOS_MMI_PACKAGE__
                    case SRV_UM_MSG_BOX_DRAFT:
                        total_msg_number = msg_status.draft_msg_number;
                        break;
                #endif
                    default:
                        ASSERT(0);
                }
            }
        }
                   
        if (index < total_msg_number)
        {
            data = (srv_um_msg_detail_struct*) MMA_CALLOC(sizeof(srv_um_msg_detail_struct));
            do
            {
                if(get_conv_list_req->start_entry == -1)
                {
                    msg_info = mma_msgmgr_get_msg_from_list(get_conv_list_req->msg_id[num_of_msg]);
                }
                else
                {
                    msg_info = mma_msgmgr_get_msg_info_by_idx(
                                (kal_uint32) mma_cvt_um_folder_to_mma_folder(get_conv_list_req->msg_box_type),
                                index, (kal_uint8) MMA_SIM_ID_TOTAL);
                }
                if (msg_info != NULL && (mma_get_message_storage(msg_info->msg_id) & storage_filter))
                {
                    data->msg_id = msg_info->msg_id;
                    data->msg_type = get_conv_list_req->msg_type;
                    if(get_conv_list_req->field & SRV_UM_DETAIL_MSG_BOX)
                    {
                        data->msg_box_type = mma_cvt_mma_folder_to_um_folder((mma_folder_enum)msg_info->folder);
                    }
                    if(get_conv_list_req->field & SRV_UM_DETAIL_READ_STATUS)
                    {
                        data->read_status = (kal_bool)msg_info->is_read;
                    }
                #if (MMI_MAX_SIM_NUM >= 2)
                    if(get_conv_list_req->field & SRV_UM_DETAIL_SIM_ID)
                    {
                        data->sim_id = translate_mma_simid_to_um_simid(msg_info->msg_sim_id);
                    }
                #endif
                    if(get_conv_list_req->field & SRV_UM_DETAIL_TIMESTAMP)
                    {
                        data->timestamp = msg_info->receive_date;
                    }
                    if(msg_info->mms_msg_type == MMA_MSG_TYPE_UNSUPPORTED)
                    {
                        if(get_conv_list_req->field & SRV_UM_DETAIL_SUBJECT)
                        {
                            kal_wchar *error_str = NULL;

							data->subject = (kal_wchar*)MMA_CALLOC(sizeof(kal_wchar) * MMA_MAX_SUBJECT_LEN);
							memset(data->subject, 0x00, sizeof(kal_wchar) * MMA_MAX_SUBJECT_LEN);
                            error_str = (kal_wchar*) get_string(MMA_STR_ID_MESSAGE_UNSUPPORTED);

                            if(app_ucs2_strlen((const kal_int8*)error_str) > 0)
                            {
                                app_ucs2_strncpy(
                                        (kal_int8*) data->subject,
                                        (const kal_int8*)error_str,
                                        MMA_MAX_SUBJECT_LEN - 1);
                            }
                        }
                    #ifdef __COSMOS_MMI_PACKAGE__
                        if(get_conv_list_req->field & SRV_UM_DETAIL_MSG_STATUS)
                        {
                            /* Checksum file get corrupted */
                            data->msg_status = MMA_MSG_ICON_STATUS_CORRUPTED_MMS;
                        }
                    #endif
                        if(get_conv_list_req->field & SRV_UM_DETAIL_READ_STATUS)
                        {
                            data->read_status = KAL_TRUE;
                        }
                    }
                    /* Read the checksum file data */
                    else if((get_conv_list_req->field & SRV_UM_DETAIL_MSG_SIZE) ||
                        (get_conv_list_req->field & SRV_UM_DETAIL_SUBJECT) ||
                        (get_conv_list_req->field & SRV_UM_DETAIL_ADDRESS) ||
                        (get_conv_list_req->field & SRV_UM_DETAIL_MULTI_ADDRESS) 
                    #ifdef __MMI_MMS_POSTCARD__
						 || ((msg_info->folder == MMA_FOLDER_SENT) && (get_conv_list_req->field & SRV_UM_DETAIL_TIMESTAMP))
                    #endif
                        )
                    {
                        mma_result_enum ret = MMA_RESULT_OK;
                        mms_msg_info_property_struct *property_st = NULL;
                        mms_msg_info_large_data_struct *large_data_st = NULL;

                        large_data_st = (mms_msg_info_large_data_struct*)MMA_CALLOC(sizeof(mms_msg_info_large_data_struct));
                        ASSERT(large_data_st);                        
                        property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));
                        ASSERT(property_st);

                        ret = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_info->msg_id),
                                    (kal_uint8)mma_get_mms_type_message_storage(msg_info->msg_id),
                                    property_st, large_data_st));
                        if(ret == MMA_RESULT_OK)
                        {
                        #ifdef __MMI_MMS_POSTCARD__
						    if((msg_info->folder == MMA_FOLDER_SENT) && (get_conv_list_req->field & SRV_UM_DETAIL_TIMESTAMP)
                                  && (property_st->msg_type == MMA_MSG_TYPE_POSTCARD))
						    {
						        data->timestamp = property_st->compose_date;
                            }
			            #endif /* __MMI_MMS_POSTCARD__ */
                
                            if(get_conv_list_req->field & SRV_UM_DETAIL_MSG_SIZE)
                            {
                                data->msg_size = property_st->msg_size;
                            }
                    #ifdef __COSMOS_MMI_PACKAGE__
                            if(get_conv_list_req->field & SRV_UM_DETAIL_MSG_STATUS)
                            {
                                data->msg_status = mma_msgmgr_get_mms_msg_status(msg_info->msg_id);
                            }
                    #endif
                            if(get_conv_list_req->field & SRV_UM_DETAIL_SUBJECT)
                            {
                                data->subject = (kal_wchar*)MMA_CALLOC(sizeof(kal_wchar) * MMA_MAX_SUBJECT_LEN);
                                memset(data->subject, 0x00, sizeof(kal_wchar) * MMA_MAX_SUBJECT_LEN);                          
                                if(msg_info->suffix != MMS_SUFFIX_DELIVERYREPORT && 
								    msg_info->suffix != MMS_SUFFIX_READREPORT && 
								    app_ucs2_strlen((const kal_int8*) large_data_st->subject) > 0)
					            {
                                    app_ucs2_strncpy(
                                            (kal_int8*) data->subject,
                                            (const kal_int8*)large_data_st->subject,
                                            MMA_MAX_SUBJECT_LEN - 1);
					            }
                        #ifndef __MMI_MMS_REPORT_STATUS_SUPPORT__
                                else
                                {
                                    /* Give special information to subject. We need to use String ID */
                                    kal_wchar *str = NULL;

                                    if (msg_info->suffix == MMS_SUFFIX_DELIVERYREPORT)
                                    {
                                        str = (kal_wchar*) get_string(MMA_STR_ID_MMS_DELIVERY_REPORT);
                                    }
                                    else if (msg_info->suffix == MMS_SUFFIX_READREPORT)
                                    {
                                        str = (kal_wchar*) get_string(MMA_STR_ID_MMS_READ_REPORT);
                                    }
                                    if (app_ucs2_strlen((const kal_int8*)str) > 0)
                                    {
                                        app_ucs2_strncpy(
                                            (kal_int8*) data->subject,
                                            (const kal_int8*)str,
                                            MMA_MAX_SUBJECT_LEN - 1);
                                    }
                                }
                        #endif
                            }
                            if(((get_conv_list_req->field & SRV_UM_DETAIL_ADDRESS) ||
                                (get_conv_list_req->field & SRV_UM_DETAIL_MULTI_ADDRESS)) &&
                                (msg_info->folder == MMA_FOLDER_INBOX))
                            {
								data->address.addr = NULL;
                                data->address.next = NULL;
                                data->address.previous = NULL;
								data->address.group = (srv_um_addr_group_enum)0;		//future compatible, 0 is gruop type 2
                                 /* Check for NULL FROM address */
								if(app_ucs2_strlen((const kal_int8*) large_data_st->from_address) > 0)
					            {
									data->address.addr = (kal_wchar*)MMA_CALLOC(sizeof(kal_wchar) * MMA_MAX_ADDR_LEN);
                                    memset(data->address.addr, 0x00, sizeof(kal_wchar) * MMA_MAX_ADDR_LEN);
						            app_ucs2_strncpy(
                                            (kal_int8*) data->address.addr,
                                            (const kal_int8*)large_data_st->from_address,
                                            MMA_MAX_ADDR_LEN - 1);
                                    data->address.group = SRV_UM_ADDR_GROUP_FROM;
                                    if(large_data_st->from_address_type == MMA_ADDR_TYPE_EMAIL)
                                    {
                                        data->address.type = SRV_UM_ADDR_EMAIL_ADDRESS;
                                    }
                                    else
                                    {
                                        data->address.type = SRV_UM_ADDR_PHONE_NUMBER;
                                    }
                                }
								/*else
								{
									data->address.type = SRV_UM_ADDR_EMPTY;
								}*/
                            }
                            else if((get_conv_list_req->field & SRV_UM_DETAIL_ADDRESS) ||
                                    (get_conv_list_req->field & SRV_UM_DETAIL_MULTI_ADDRESS))
                            {
                                /* For UNSENT, SENT folder MMS */
                                MSF_UINT8 total_address = 0;
                                MSF_UINT8 total_object = 0;
                                srv_um_addr_struct *temp_Addr = NULL;
                                mms_msg_addr_info_struct *addr_data = NULL;

                                temp_Addr = (srv_um_addr_struct*) &(data->address);
                                addr_data = (mms_msg_addr_info_struct*)
                                    MMA_CALLOC(sizeof(mms_msg_addr_info_struct) * MMS_MAX_ADDR_COUNT);

                                ret = translate_mms_result_to_mma(MMSlib_readAddrObjFile(MMA_TRANSLATE_MSG_ID(msg_info->msg_id),
                                                        (kal_uint8)mma_get_mms_type_message_storage(msg_info->msg_id),
                                                        &total_address, &total_object, addr_data, NULL, NULL, NULL));
                                //ret = translate_mms_result_to_mma(ret);
                                data->address.next = NULL;
                                data->address.previous = NULL;
                                if((ret == MMA_RESULT_OK) && (total_address > 0))
                                {
                                    kal_uint8 count = 0;
                                    kal_bool loop = KAL_TRUE;
                                    
                                    while((count < total_address) && loop)
                                    {
                                        if(addr_data[count].addr_group == MMA_ADDRESS_GROUP_TYPE_TO)
                                        {
                                            if(data->address.addr == NULL)
                                            {
                                                /* Fill the first node */
                                                data->address.addr = (kal_wchar*)MMA_CALLOC(sizeof(kal_wchar) * MMA_MAX_ADDR_LEN);
                                                data->address.group = SRV_UM_ADDR_GROUP_TO;
                                                if(addr_data[count].addr_type == MMA_ADDR_TYPE_EMAIL)
                                                {
                                                    data->address.type = SRV_UM_ADDR_EMAIL_ADDRESS;
                                                }
                                                else
                                                {
                                                    data->address.type = SRV_UM_ADDR_PHONE_NUMBER;
                                                }
                                                app_ucs2_strncpy(
                                                        (kal_int8*) data->address.addr,
                                                        (const kal_int8*)addr_data[count].address,
                                                        MMS_MAX_ADDR_DATA_LEN - 1);
                                                count++;
												if(get_conv_list_req->field & SRV_UM_DETAIL_ADDRESS)
												{
													loop = KAL_FALSE;   /* If multiple address is on, then make it TRUE */
												}
												continue;
                                            }
                                            /* for MULTIPLE ADDRESS */
                                            if((get_conv_list_req->field & SRV_UM_DETAIL_MULTI_ADDRESS) && (count < total_address))
                                            {
                                                loop = KAL_TRUE;
                                                /* Fill other Nodes */
                                                temp_Addr->next = (srv_um_addr_struct*)MMA_CALLOC(sizeof(srv_um_addr_struct));
                                                temp_Addr->next->addr = (kal_wchar*)MMA_CALLOC(sizeof(kal_wchar) * MMA_MAX_ADDR_LEN);
                                                temp_Addr->next->previous = temp_Addr;
                                                temp_Addr->next->next = NULL;
                                                temp_Addr->next->group = SRV_UM_ADDR_GROUP_TO;
                                                if(addr_data[count].addr_type == MMA_ADDR_TYPE_EMAIL)
                                                {
                                                    temp_Addr->next->type = SRV_UM_ADDR_EMAIL_ADDRESS;
                                                }
                                                else
                                                {
                                                    temp_Addr->next->type = SRV_UM_ADDR_PHONE_NUMBER;
                                                }
                                                app_ucs2_strncpy(
                                                        (kal_int8*) temp_Addr->next->addr,
                                                        (const kal_int8*)addr_data[count].address,
                                                        MMS_MAX_ADDR_DATA_LEN - 1);
                                                temp_Addr = temp_Addr->next;
                                                count++;
                                            }
                                        }
										else
										{
											/* CC or BCC address */
											count++;
										}
                                    }
                                }
                                MMA_FREE(addr_data);
                            }
                        }
                    #ifdef __COSMOS_MMI_PACKAGE__
                        else
                        {
                            if(get_conv_list_req->field & SRV_UM_DETAIL_MSG_STATUS)
                            {
                                /* Checksum file get corrupted */
                                data->msg_status = MMA_MSG_ICON_STATUS_CORRUPTED_MMS;
                            }
                            if(get_conv_list_req->field & SRV_UM_DETAIL_READ_STATUS)
                            {
                                data->read_status = KAL_TRUE;
                            }
                        }
                    #endif

                        /* Free the memory */
                        if (property_st != NULL)
                        {
                            MMA_FREE(property_st);
                            property_st = NULL;
                        }
                        if (large_data_st != NULL)
                        {
                            MMA_FREE(large_data_st);
                            large_data_st = NULL;
                        }
                    }
					if(data->address.addr == NULL)
                    {
                        /* if any file read error come or No TO/FROM Field or the MMS is corrupted/Unsupported.*/
                        data->address.type = SRV_UM_ADDR_EMPTY; 
						data->address.group = (srv_um_addr_group_enum)0;		//future compatible, 0 is gruop type 2
                    }
					if(data->subject == NULL)
                    {
						/* Checksum file operation read error can occur */
                        data->subject = (kal_wchar*)MMA_CALLOC(sizeof(kal_wchar) * MMA_MAX_SUBJECT_LEN);
                    }
                    /* Call the Callback function of UM & check the return type */
                    um_result = (srv_um_result_enum)get_conv_list_req->traverse_func(get_conv_list_req->user_data, data);
                    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_UM_GET_CONV_LIST_RSP,
                                      "(mma_msgmgr.c): Result of Conv traverse function is: %d\n", um_result));
                    /* Free the memory start*/
                    if(data->address.addr)
                    {
                        MMA_FREE(data->address.addr);
                        data->address.addr = NULL;
                    }
                    while(data->address.next)
                    {
                        srv_um_addr_struct *tmp = data->address.next;
                        data->address.next = data->address.next->next;
                        if(tmp->addr)
                        {
                            MMA_FREE(tmp->addr);
                        }
                        MMA_FREE(tmp);
                        tmp = NULL;
                    }
                    if(data->subject)
                    {
                        MMA_FREE(data->subject);
                        data->subject = NULL;
                    }
                    memset(data, 0x00, sizeof(srv_um_msg_detail_struct));
                    /* Free memory end */
                    
                    /* Check the return type from UM */
                    if(um_result == SRV_UM_RESULT_BUFFER_FULL)
                    {
                        /* Stop the process. Send the response */
                        more = KAL_TRUE;
                        mms_mma_send_um_get_conv_list_rsp(
                            source,
                            get_conv_list_req->app_id,
                            KAL_TRUE,
                            (kal_uint16) num_of_msg,
                            (kal_bool) more);
                        MMA_FREE(data);
                        MMA_FREE(get_conv_list_req);
                        return;
                    }
                    if(um_result == SRV_UM_RESULT_CANCELLLED)
                    {
                        /* Stop the process. Send the response */
                        more = KAL_FALSE;
                        mms_mma_send_um_get_conv_list_rsp(
                            source,
                            get_conv_list_req->app_id,
                            KAL_FALSE,
                            (kal_uint16) num_of_msg,
                            (kal_bool) more);
                        MMA_FREE(data);
                        MMA_FREE(get_conv_list_req);
                        return;
                    }
					num_of_msg++;
                    index++;
                }
                else
                {
                    /* No entry of Message. May be, it is deleted */
                    //num_of_msg++; /* No data is provided. So, can not count it */
                    index++;
                }
            } while (msg_info != NULL && index < total_msg_number);
            MMA_FREE(data);
        }
        mms_mma_send_um_get_conv_list_rsp(
            source,
            get_conv_list_req->app_id,
            KAL_TRUE,
            (kal_uint16) num_of_msg,
            (kal_bool) KAL_FALSE);
        MMA_FREE(get_conv_list_req);
        return;
    }
}
#endif  /* __MMI_MMS_CONVERSATION_BOX_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_handle_rsp
 * DESCRIPTION
 *  Handle the response signal
 * PARAMETERS
 *  sig         [IN]        
 *  sigData     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mma_msgmgr_handle_rsp(kal_uint16 sig, void *sigData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sig)
    {
        case MMS_SIG_DELETE_MSG_REPLY:
        {
            MmsMsgDoneReplySig *delete_rsp = (MmsMsgDoneReplySig*) sigData;

            if (delete_rsp != NULL)
            {
                mma_msg_info_list_struct *msg_p = NULL;
				kal_uint32 mma_msg_id;

				mma_msg_id = mma_main_encode_msg_id((kal_uint8)translate_mms_storage_to_mma_storage_enum((msf_mms_storage_enum)delete_rsp->storageType), 
                             delete_rsp->msgId);

                msg_p = mma_msgmgr_get_msg_from_list(mma_msg_id);
                if (msg_p == NULL)
                {
                    return KAL_FALSE;
                }

                MMA_SIGNAL_SENDTO_IU(
                    MMA_SUBMODULE_MSG_MGR,
                    MMA_INT_SIG_TYPE_MSG_MMS_DELETE_IND,
                    delete_rsp->result,
                    (unsigned int)mma_msg_id);

                return KAL_TRUE;
            }
            else
            {
                return KAL_FALSE;
            }
        }
        case MMS_SIG_READ_REPORT_IND:
        {
            MmsMsgReadReport *data = (MmsMsgReadReport*) sigData;

            ASSERT(data);

            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM,
                              MSF_MODID_MMA,
                              MMA_MSGMGR_HANDLE_READ_REPORT_IND, "(mma_msgmgr.c): RecvReadReportFromMMSService,%d,%d",
                              data->msgId, data->simId));
        #ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
            mma_msgmgr_update_report_data_req_hdlr(MMA_MSGMGR_GET_FROM_READ_REPORT, data);
        #else
            mma_msgmgr_add_new_report_notif_req_hdlr(MMA_MSGMGR_GET_FROM_READ_REPORT, data);
        #endif
            /* Now, free the memory */
            if(data)
            {
                if(data->address)
                {
                    MMA_FREE(data->address);
                }
                if(data->text)
                {
                    MMA_FREE(data->text);
                }
                if(data->serverMessageId)
                {
                    MMA_FREE(data->serverMessageId);
                }
                if(data->subject)
                {
                    MMA_FREE(data->subject);
                }
            }
            return KAL_TRUE;
        }
        case MMS_SIG_DELIVERY_REPORT:
        {
            MmsMsgDeliveryReportInd *data = (MmsMsgDeliveryReportInd*) sigData;

            ASSERT(data);

            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM,
                              MSF_MODID_MMA,
                              MMA_MSGMGR_HANDLE_DELIVERY_REPORT_IND, "(mma_msgmgr.c): RecvDeliveryReportFromMMSService,%d,%d",
                              data->msgId, data->simId));
        #ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
            mma_msgmgr_update_report_data_req_hdlr(MMA_MSGMGR_GET_FROM_DELIVERY_REPORT, data);
        #else
            mma_msgmgr_add_new_report_notif_req_hdlr(MMA_MSGMGR_GET_FROM_DELIVERY_REPORT, data);
        #endif
            /* Now, free the memory */
            if(data)
            {
                if(data->address)
                {
                    MMA_FREE(data->address);
                }
                if(data->text)
                {
                    MMA_FREE(data->text);
                }
                if(data->serverMsgId)
                {
                    MMA_FREE(data->serverMsgId);
                }
                if(data->subject)
                {
                    MMA_FREE(data->subject);
                }
            }
            return KAL_TRUE;
        }
        case MMS_SIG_NOTIFICATION:
        {
            MmsMsgReplyNotification *data = (MmsMsgReplyNotification*) sigData;

            ASSERT(data);

            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM,
                              MSF_MODID_MMA,
                              MMA_MSGMGR_HANDLE_SIG_NOTIFICATION, "(mma_msgmgr.c): RecvNotificationFromMMSService,%d,%d,%d",
                              data->notifId, data->type, data->simId));
            /* check whether the Memory card is present or not for the sig notification of memory card mms */
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            if((data->storageType == MSF_MMS_STORAGE_MEM_CARD_1) && (!MSF_IS_MEM_CARD_PRESNT(MSF_MMS_STORAGE_MEM_CARD_1)))
            {
                /* No need to process this request. Simply return */
                MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,
                              MMA_MSGMGR_HANDLE_SIG_NOTIFICATION_CARD_NOT_PRESENT, "(mma_msgmgr.c): Recv sig Notification for card but card not present"));
                return KAL_FALSE;                
            }
        #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */

            /* ashok need to check for the message MMS, need to get the notification
			   & delete it after saving the Message MMS */
            if(data->type == MMS_NOTIFICATION_MESSAGE)
            {
                mma_msgmgr_recv_notif_data_struct *temp_data = NULL;
                /* add a entry in the Global context of the Notification. As it will not be parsed again */
                temp_data = (mma_msgmgr_recv_notif_data_struct*) MMA_CALLOC(sizeof(mma_msgmgr_recv_notif_data_struct));
                temp_data->data = (MmsMsgReplyNotification*) MMA_CALLOC(sizeof(MmsMsgReplyNotification));
                temp_data->next = NULL;
                temp_data->data->notifId = data->notifId;
                temp_data->data->msgId = data->msgId;
                temp_data->data->storageType = data->storageType;
                temp_data->data->simId = data->simId;
                temp_data->data->size = data->size;
                temp_data->data->fromAddrType = data->fromAddrType;
                temp_data->data->expiryDate = data->expiryDate;
                temp_data->data->msgClass = data->msgClass;
                temp_data->data->priority = data->priority;
                temp_data->data->result = data->result;
                if (data->subjectText != NULL)
                {
                    temp_data->data->subjectText = MMA_CALLOC(strlen(data->subjectText) + 1);
                    strcpy(temp_data->data->subjectText, data->subjectText);
                }
                if (data->fromAddress != NULL)
                {
                    temp_data->data->fromAddress = MMA_CALLOC(strlen(data->fromAddress) + 1);
                    strcpy(temp_data->data->fromAddress, data->fromAddress);
                }
                /* Add it in the global context */
                mma_msgmgr_add_msg_notif_data(temp_data);
                
		    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__		
                /* encode the msg_id parameter for the storage case */
                data->msgId = mma_main_encode_msg_id((kal_uint8)translate_mms_storage_to_mma_storage_enum((msf_mms_storage_enum)data->storageType), data->msgId);
                data->notifId = mma_main_encode_msg_id((kal_uint8)translate_mms_storage_to_mma_storage_enum((msf_mms_storage_enum)data->storageType), data->notifId);
            #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
                mma_msgmgr_add_new_message_req_hdlr(data->msgId, MMA_MSGMGR_GET_FROM_MESSAGE, data->notifId, translate_mms_sim_to_mma_sim(data->simId));
            }
            else
            {
                mma_msgmgr_add_new_report_notif_req_hdlr(MMA_MSGMGR_GET_FROM_NOTIFICATION, data);
            }
            /* Now, free the memory */
            if(data)
            {
                if(data->fromName)
                {
                    MMA_FREE(data->fromName);
                }
                if(data->fromAddress)
                {
                    MMA_FREE(data->fromAddress);
                }
                if(data->subjectText)
                {
                    MMA_FREE(data->subjectText);
                }
            }
            return KAL_TRUE;
        }
        case MMS_SIG_GET_FLDR_REPLY:
        {
            MmsListOfProperties *list = (MmsListOfProperties*) sigData;

            if (NULL != list)
            {
                void mma_msgmgr_get_fldr_property_data(MmsListOfProperties * list);

                mma_msgmgr_get_fldr_property_data(list);
                return KAL_TRUE;
            }
        }
        default:
            return KAL_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_process_int_sig
 * DESCRIPTION
 *  Process the internal signals.
 * PARAMETERS
 *  sig     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_msgmgr_process_int_sig(mma_signal_struct *sig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(sig);
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_PROCESS_INT_SIGNAL, "(mma_msgmgr.c): Recv sig %d",
                      (int)sig->type));

    switch (sig->type)
    {
        case MMA_INT_SIG_TYPE_MSG_ENTER_USB_REQ:
        {
            mma_msgmgr_enter_usb_mode_req_hdlr();
            break;
        }
        case MMA_INT_SIG_TYPE_MSG_UPDATE_NEW_MSG_REQ:
        {
            mma_msgmgr_add_new_message_req_hdlr(
                (kal_uint32) sig->i_param,
                (mma_msgmgr_new_message_source_enum) sig->u_param1,
                (kal_uint32) sig->u_param2,
                (kal_uint32) sig->u_param3);
        }
            break;
        case MMA_INT_SIG_TYPE_MSG_GET_REPORT_NOTIF_REQ:
        {
            mma_msgmgr_add_new_report_notif_req_hdlr(
                (mma_msgmgr_new_message_source_enum) sig->u_param1,
                (void*) sig->p_param);
        }
            break;
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
        case MMA_INT_SIG_TYPE_MSG_SET_APPDATA_REQ:
            mma_msgmgr_set_appdata_req_hdlr(
                (module_type) sig->i_param,
                (wap_mma_set_app_data_req_struct*) sig->p_param);
            break;
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
        case MMA_INT_SIG_TYPE_MSG_UM_GET_MSG_NUM_REQ:
        {
            mma_msgmgr_um_get_msg_num_req_hdlr(
                (module_type) sig->i_param,
                (srv_um_get_msg_num_req_struct*) sig->p_param);
        }
            break;
        case MMA_INT_SIG_TYPE_MSG_UM_GET_LIST_REQ:
        {
            mma_msgmgr_um_get_list_req_hdlr((module_type) sig->i_param, (srv_um_get_msg_list_req_struct*) sig->p_param);
        }
            break;
        case MMA_INT_SIG_TYPE_MSG_UM_DELETE_FOLDER_REQ:
        {

            mma_msgmgr_um_delete_folder_req_hdlr(
                (module_type) sig->i_param,
                (srv_um_delete_folder_req_struct*) sig->p_param);
        }
            break;
        case MMA_INT_SIG_TYPE_MSG_CONTINUE_MSG_OPER:
        {
            mma_msg_info_list_struct *msg_p = NULL;

            ASSERT(g_mma_msgmgr_cntx.is_cnt_msg_oper_sent == TRUE);
            g_mma_msgmgr_cntx.is_cnt_msg_oper_sent = FALSE;
            msg_p = mma_msgmgr_get_pending_msg(NULL);
            if (msg_p != NULL)
            {
                mma_msgmgr_process_msg_oper(msg_p);
            }
            msg_p = mma_msgmgr_get_pending_msg(NULL);
            if (msg_p != NULL)
            {
                mma_msgmgr_send_int_perform_msg_oper_ind();
            }
            else
            {
                /* No pending message. Please do what you shall do */
		if(!(MMA_MSGMGR_STATE_CREATE_CARD_PLUG_IN_MSG_LIST == MMA_MSGMGR_GET_STATE()))
		{
                    MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_READY);
		}
                if (g_mma_msgmgr_cntx.pending_req_list != NULL)
                {
                    mma_msgmgr_send_int_notify_ind();
                }
            }
        }
            break;
        case MMA_INT_SIG_TYPE_MSG_PARSER_GET_BASIC_MSG_INFO_REPLY:
        {
            mma_msgmgr_parser_get_msg_info_hdlr(sig->u_param1, (mma_result_enum)sig->i_param, sig->p_param);
        }
            break;
#ifndef MMA_JSR_PST_MMS_OPERATON_SUPPORT 
        case MMA_INT_SIG_TYPE_MSG_GET_MSG_INFO_REQ:
        {
            mma_msgmgr_get_msg_info_req_hdlr(
                (module_type) sig->i_param,
                (wap_mma_get_msg_info_req_struct*) sig->p_param);
        }
            break;
        case MMA_INT_SIG_TYPE_MSG_GET_MSG_LIST_REQ:
        {
            mma_msgmgr_get_msg_list_req_hdlr(
                (module_type) sig->i_param,
                (wap_mma_get_msg_list_req_struct*) sig->p_param);
        }
            break;
#endif	/* MMA_JSR_PST_MMS_OPERATON_SUPPORT */

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
        case MMA_INT_SIG_TYPE_MSG_DELETE_REQ:
        {
            mma_msgmgr_delete_req_hdlr((module_type) sig->i_param, (wap_mma_delete_req_struct*) sig->p_param);
        }
            break;
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
        case MMA_INT_SIG_TYPE_MSG_SAVE_REQ:
        {
            mma_msgmgr_save_req_hdlr((module_type) sig->i_param, (wap_mma_save_req_struct*) sig->p_param);
        }
            break;
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
        case MMA_INT_SIG_TYPE_MSG_SET_READMARK_REQ:
        {
            mma_msgmgr_set_readmark_req_hdlr(
                (module_type) sig->i_param,
                (wap_mma_set_readmark_req_struct*) sig->p_param);
        }
            break;
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
        case MMA_INT_SIG_TYPE_MSG_MMS_DELETE_IND:
        {
            mma_msgmgr_mms_delete_ind_hdlr((MmsResult) sig->i_param, (kal_uint32) sig->u_param1);
        }
            break;
        case MMA_INT_SIG_TYPE_MSG_MMS_MOVE_IND:
        {
            mma_msgmgr_mms_move_ind_hdlr((MmsResult) sig->i_param, (kal_uint32) sig->u_param1);
        }
            break;
        case MMA_INT_SIG_TYPE_NOTIFY:
        {
            mma_msgmgr_execute_pending_req_hdlr();
        }
            break;
        case MMA_INT_SIG_TYPE_MSG_TERMINATE_IND:
        {
            mma_msgmgr_terminate_ind_hdlr();
        }
            break;
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
        case MMA_INT_SIG_TYPE_MSG_VALIDATE_MSG_REQ:
        {
            mma_msgmgr_validate_msg_req_hdlr(
                (module_type) sig->i_param,
                (wap_mma_msg_is_valid_req_struct*) sig->p_param);
            break;
        }
        case MMA_INT_SIG_TYPE_MSG_GET_UNREAD_MSG_LIST_REQ:
        {
            mma_msgmgr_get_unread_msg_list_req_hdlr(
                (module_type) sig->i_param,
                (wap_mma_get_unread_msg_list_req_struct*) sig->p_param);
            break;
        }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
    #if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
        case MMA_INT_SIG_TYPE_MSG_GET_RECENT_EVT_LIST_REQ:
        {
            mma_msgmgr_get_recent_evt_list_req_hdlr(
                (module_type) sig->i_param,
                (wap_mma_get_recent_evt_list_req_struct*) sig->p_param);
            break;
        }
        case MMA_INT_SIG_TYPE_MSG_DELETE_RECENT_EVT_REQ:
        {
            mma_msgmgr_delete_recent_evt_req_hdlr(
                (module_type) sig->i_param,
                (wap_mma_delete_recent_evt_req_struct*) sig->p_param);
            break;
        }
    #endif
        case MMA_INT_SIG_TYPE_MSG_CREATE_REQ:
        {
            mma_msgmgr_create_req_hdlr((module_type) sig->i_param, (wap_mma_create_req_struct*) sig->p_param);
            break;
        }
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
        case MMA_INT_SIG_TYPE_MSG_GET_ATTR_AND_THUMBNAIL_REQ:
        {
           mma_msgmgr_get_mms_attr_and_thumbnail_req_hdlr((module_type) sig->i_param, (wap_mma_get_mms_thumbnail_and_attr_info_req_struct*) sig->p_param);
           break;
        }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
        case MMA_INT_SIG_TYPE_MSG_INT_CREATE_RSP:
        {
            mma_msgmgr_int_create_rsp_hdlr(sig->u_param1, sig->u_param2, sig->i_param);
            break;
        }
		#ifdef __MMI_MMS_MMA_DRM_ENCODING__
        case MMA_INT_SIG_TYPE_MSG_DRM_ENCODE_RSP:
        {
            mma_msgmgr_drm_encode_done_hdlr(sig->u_param1, sig->u_param2, sig->u_param3, sig->i_param);
            break;
        }
        case MMA_INT_SIG_TYPE_MSG_PARSE_REQ:
        {
            mma_msgmgr_get_content_req_hdlr((module_type) sig->i_param, (wap_mma_get_content_req_struct*) sig->p_param);
            break;
        }
		#endif
#ifndef MMA_JSR_PST_MMS_OPERATON_SUPPORT 
		case MMA_INT_SIG_TYPE_MSG_GET_MSG_NUM_REQ:
        {
            mma_msgmgr_get_msg_num_req_hdlr(
                (module_type) sig->i_param,
                (wap_mma_get_msg_num_req_struct*) sig->p_param);
            break;
        }
#endif /* MMA_JSR_PST_MMS_OPERATON_SUPPORT */

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
        case MMA_INT_SIG_TYPE_MSG_GET_MSG_PROPERTY_REQ:
        {
            mma_msgmgr_get_msg_property_req_hdlr((module_type) sig->i_param,
                (wap_mma_get_msg_property_req_struct*) sig->p_param);
            break;
        }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
        case MMA_INT_SIG_TYPE_MSG_UM_GET_MSG_INFO_REQ:
        {
            mma_msgmgr_get_um_msg_info_req_hdlr(
                (module_type) sig->i_param,
                (srv_um_get_msg_info_req_struct*) sig->p_param);
            break;
        }
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
        case MMA_INT_SIG_TYPE_MSG_RR_MARK_REQ:
        {
            mma_msgmgr_mark_rr_req_hdlr(
                (module_type) sig->i_param,
                (wap_mma_rr_mark_req_struct*) sig->p_param);
            break;
        }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
#ifndef __MMI_FMGR_HIDE_FORMAT_DRIVE__ 
        case MMA_INT_SIG_TYPE_MSG_FMT_FORMAT_IND:
        {
            mma_msgmgr_mms_list_format_req_hdlr((kal_uint8) sig->i_param);
            break;
        }
#endif /* __MMI_FMGR_HIDE_FORMAT_DRIVE__ */
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        case MMA_INT_SIG_TYPE_MSG_CHG_STORAGE_REQ:
        {
            mma_msgmgr_chg_mms_storage_req_hdlr(
                (module_type) sig->i_param,
                (wap_mma_change_msg_storage_req_struct*) sig->p_param);
            break;
        }
        case MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_IN_IND:
        {
            mma_msgmgr_mem_card_plug_in_req_hdlr((mms_mem_card_plug_in_out_struct*) sig->p_param);
            break;
        }
        case MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_OUT_IND:
        {
            mma_msgmgr_mem_card_plug_out_req_hdlr((mms_mem_card_plug_in_out_struct*) sig->p_param);
            break;
        }
    #endif /*__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/
    #ifdef __MMI_MMS_CONVERSATION_BOX_SUPPORT__
        case MMA_INT_SIG_TYPE_MSG_UM_TRAVERSE_MSG_REQ:
        {
            mma_msgmgr_um_get_conv_list_req_hdlr((module_type) sig->i_param, (srv_um_traverse_msg_req_struct*) sig->p_param);
            break;
        }
    #endif  /* __MMI_MMS_CONVERSATION_BOX_SUPPORT__ */
        case MMA_INT_SIG_TYPE_MSG_UPDATE_ADDR_OBLECTS_INFO:
        {
            mma_msgmgr_update_addr_objects_info_req_hdlr(sig->u_param1, (mmsAddrObjectInfo*)sig->p_param);
            break;
        }
        case MMA_INT_SIG_TYPE_MSG_SYNC_DELETE_MSG_IND:
        {
            mma_msgmgr_sync_delete_mms_ind_hdlr((mms_sync_delete_msg_ind_struct*) sig->p_param);
            break;
        }
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
        case MMA_INT_SIG_TYPE_MSG_UPDATE_MMS_THUMBNAIL_INFO:
        {
            mma_msgmgr_update_mms_thumbnail_info_req_hdlr(sig->u_param1, (mmsBodyObjectInfo*)sig->p_param);
            break;
        }
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */
    #ifdef __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__
        case MMA_INT_SIG_TYPE_MSG_CPY_TO_ARCHIVE_REQ:
        {
            mma_msgmgr_copy_mms_to_archive_req_hdlr((module_type) sig->i_param,
                (wap_mma_cpy_msg_to_archive_folder_req_struct*) sig->p_param);
            break;
        }
    #endif   /* __MMI_MMS_COPY_TO_ARCHIVE_SUPPORT__ */
#if (defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_MMS_TEMPLATE_SUPPORT__))
        case MMA_INT_SIG_TYPE_MSG_DEF_TMPLT_GEN_DONE_IND:
        {
            MMA_FREE(sig->p_param);
            /* Process the UM_GET_LIST for the Default Template */
            mma_msgmgr_send_int_notify_ind();
            break;
        }
    #endif   /* __COSMOS_MMI_PACKAGE__ */
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_init
 * DESCRIPTION
 *  Initialize the msgmgr module.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mma_msgmgr_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msm_get_module_status(MSF_MODID_MMS) != MODULE_STATUS_ACTIVE)
    {
        return KAL_FALSE;
    }
    if (MMA_MSGMGR_STATE_IDLE == MMA_MSGMGR_GET_STATE())
    {
        mma_reset_last_tick();
        memset(&g_mma_msgmgr_cntx, 0x00, sizeof(mma_msgmgr_context_strcut));
        MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_CREATE_PHONE_MSG_LIST);
        MMSif_getMMSList(MSF_MODID_MMA, 0, MAX_MMS_GET_PHONE_LIST_COUNT - 1, MSF_MMS_STORAGE_PHONE);
    }

    if (MMA_MSGMGR_STATE_READY == MMA_MSGMGR_GET_STATE())
        return KAL_TRUE;
    else
        return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_terminate
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mma_msgmgr_terminate()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_mma_msgmgr_cntx, 0x00, sizeof(mma_msgmgr_context_strcut));
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_fldr_property_data
 * DESCRIPTION
 *  fill the mma_msg_info_property_fldr_struct of global context.
 * PARAMETERS
 *  list        [IN]        
 *  result(?)       [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void mma_msgmgr_get_fldr_property_data(MmsListOfProperties *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;
    mma_msg_info_list_struct *msg_list;
    mma_result_enum result = MMA_RESULT_OK;
    mms_msg_info_property_struct *property_st = NULL;
    mms_msg_info_large_data_struct *large_data_st = NULL;
	msf_mms_storage_enum mms_storage_type = (msf_mms_storage_enum)list->storageType;
	mma_msg_storage_type_enum mma_storage_type = translate_mms_storage_to_mma_storage_enum (mms_storage_type);
	kal_uint32 mms_msg_id;
#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
    kal_uint32 report_count = 0;
#endif /* __MMI_MMS_POSTCARD__*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((i < list->noOfElements) && (list->msgPropertyList[i].msgFolderInfo.msgId))
    {
        mms_msg_id = list->msgPropertyList[i].msgFolderInfo.msgId;
		msg_list = (mma_msg_info_list_struct*) MMA_CALLOC(sizeof(mma_msg_info_list_struct));
		msg_list->msg_id = mma_main_encode_msg_id((MSF_UINT8) mma_storage_type, mms_msg_id);
		i++;
        
        /* fill the other info from the checksum file */
        property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));
        ASSERT(property_st);
        large_data_st = (mms_msg_info_large_data_struct*)
                    MMA_CALLOC(sizeof(mms_msg_info_large_data_struct));
        ASSERT(large_data_st);
		result = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(mms_msg_id, (kal_uint8)mms_storage_type, property_st, large_data_st));
        if ((result != MMA_RESULT_OK) && (result != MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE))
        {
            /* Can not use mmaif_delete becasue this msg in not in the msg_list so can not return the suffix */
            if((mms_storage_type == MSF_MMS_STORAGE_PHONE) || MSF_IS_MEM_CARD_PRESNT(MSF_MMS_STORAGE_MEM_CARD_1))
            {
                MMSif_deleteMessage(MSF_MODID_MMA, mms_msg_id, MMS_SUFFIX_ERROR, (MSF_UINT8) mms_storage_type);
                MMSlib_delChkSumFile(mms_msg_id, mms_storage_type);
                //MMSlib_delAddrObjFile(mms_msg_id, mms_storage_type);
            }
			MMA_FREE(property_st);
            MMA_FREE(msg_list);
			property_st = NULL;
			MMA_FREE(large_data_st);
			large_data_st = NULL;
            continue;
        }
        /* fill the info */
        msg_list->folder = property_st->folder;
        msg_list->msg_sim_id = property_st->msg_sim_id;
        if(msg_list->folder == MMA_FOLDER_DRAFT)
        {
            /* Old version mms have default value as SIM1. Memory card mms of draft folder can be shown as SIM1 */
        #ifndef __COSMOS_MMI_PACKAGE__
            msg_list->msg_sim_id = MMA_SIM_ID_SIM_UNCLASSIFIED;
        #endif
        }
        if(msg_list->msg_sim_id == 0)
        {
        #ifdef __COSMOS_MMI_PACKAGE__
            msg_list->msg_sim_id = MMA_SIM_ID_SIM1;
        #else
            msg_list->msg_sim_id = MMA_SIM_ID_SIM_UNCLASSIFIED;
        #endif
        }
    #if (MMI_MAX_SIM_NUM == 1)
        /* single sim build. Always SIM ID as 1 */
        msg_list->msg_sim_id = MMA_SIM_ID_SIM1;
    #endif
        if(msg_list->msg_sim_id == MMA_SIM_ID_SIM3)
        {
        #if (MMI_MAX_SIM_NUM < 3)
            msg_list->msg_sim_id = MMA_SIM_ID_SIM_UNCLASSIFIED;
        #endif
        }
        if(msg_list->msg_sim_id == MMA_SIM_ID_SIM4)
        {
        #if (MMI_MAX_SIM_NUM < 4)
            msg_list->msg_sim_id = MMA_SIM_ID_SIM_UNCLASSIFIED;
        #endif
        }
        msg_list->suffix = property_st->suffix;
        msg_list->receive_date = property_st->receive_date;
        msg_list->is_read = property_st->is_read;
        msg_list->is_rr_send = FALSE;
        msg_list->prev_folder = large_data_st->app_data[MMA_MSGMGR_PREV_FOLDER_POS];
        msg_list->mms_msg_type = property_st->msg_type;
        msg_list->mms_priority = property_st->priority;
        mma_msgmgr_add_msg_to_list(msg_list);
        if(result == MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE)
        {
            msg_list->mms_msg_type = MMA_MSG_TYPE_UNSUPPORTED;
            //msg_list->receive_date = 0;
            msg_list->is_read = TRUE;
			/* extra handling */
			if((msg_list->msg_sim_id != MMA_SIM_ID_SIM1) && (msg_list->msg_sim_id != MMA_SIM_ID_SIM2))
			{
				msg_list->msg_sim_id = MMA_SIM_ID_SIM1;
			}
			if((msg_list->folder != MMA_FOLDER_INBOX) && (msg_list->folder != MMA_FOLDER_OUTBOX) &&
				(msg_list->folder != MMA_FOLDER_SENT) && (msg_list->folder != MMA_FOLDER_DRAFT) &&
				(msg_list->folder != MMA_FOLDER_TEMPLATE) && (msg_list->folder != MMA_FOLDER_USRDEF_TEMPLATE) &&
				(msg_list->folder != MMA_FOLDER_ARCHIVE) && (msg_list->folder != MMA_FOLDER_HIDDEN))
			{
				msg_list->folder = MMA_FOLDER_DRAFT;
                                msg_list->msg_sim_id = MMA_SIM_ID_SIM_UNCLASSIFIED;
			}
        }
       /* There may be a chance that user put a UNCLASSIFIFED SIM MMS in COSMOS build using memory card or the Checksum file get corrupted*/
    #ifdef __COSMOS_MMI_PACKAGE__
        if(msg_list->msg_sim_id == MMA_SIM_ID_SIM_UNCLASSIFIED)
        {
            msg_list->msg_sim_id = MMA_SIM_ID_SIM1;
        }
    #endif
        /* check for the validation of the file */
        /*if (FALSE == MMSlib_isValidMmsMSg((MmsMsgId) mms_msg_id, msg_list->suffix, (kal_uint8)mms_storage_type))
		{
			MMA_MSGMGR_MSG_SET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_DELETE);
		}*/
    #ifndef __MMI_MMS_POSTCARD__
        if(property_st->msg_type == MMA_MSG_TYPE_POSTCARD)
        {
            /* check for the postcard MMS on the NON-VF_UE build */
            //MMA_MSGMGR_MSG_SET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_DELETE);
            msg_list->mms_msg_type = MMA_MSG_TYPE_UNSUPPORTED;
            msg_list->is_read = TRUE;
            //msg_list->receive_date = 0;
        }
    #endif /* __MMI_MMS_POSTCARD__*/
		/* valid folder check */
        if((msg_list->folder == MMA_FOLDER_HIDDEN) || (msg_list->folder == MMA_FOLDER_NONE))
        {
			MMA_MSGMGR_MSG_SET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_DELETE_REQ_SENT);
            MMA_MSGMGR_MSG_SET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_DELETE);
			MMAif_deleteMessage(MMA_SUBMODULE_MSG_MGR, msg_list->msg_id);
            MMA_FREE(property_st);
			property_st = NULL;
			MMA_FREE(large_data_st);
			large_data_st = NULL;
            continue;
        }
    #ifndef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        if(msg_list->folder == MMA_FOLDER_ARCHIVE)
        {
            /* check for the Archive mms in non-archive build */
            //MMA_MSGMGR_MSG_SET_FLAG(msg_list->flag, MMA_MSGMGR_MSG_OPER_DELETE);
            msg_list->mms_msg_type = MMA_MSG_TYPE_UNSUPPORTED;
            msg_list->folder = MMA_FOLDER_DRAFT;
            msg_list->is_read = TRUE;
            //msg_list->receive_date = 0;
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
    #ifdef __MMI_MMS_REPORT_STATUS_SUPPORT__
        if((msg_list->suffix == MMS_SUFFIX_READREPORT) || (msg_list->suffix == MMS_SUFFIX_DELIVERYREPORT))
        {
            /* check for the DR/RR in INBOX folder on the REPORT BOX build */
            msg_list->mms_msg_type = MMA_MSG_TYPE_UNSUPPORTED;
            msg_list->is_read = TRUE;
        }
    #endif /* __MMI_MMS_REPORT_BOX_SUPPORT__*/
        if((msg_list->suffix != MMS_SUFFIX_NOTIFICATION) && (property_st->msg_size > wap_custom_get_max_mms_msg_size()))
        {
            msg_list->mms_msg_type = MMA_MSG_TYPE_UNSUPPORTED;
            msg_list->is_read = TRUE;
            //msg_list->receive_date = 0;
        }
    #ifndef __COSMOS_MMI_PACKAGE__
        if(msg_list->folder == MMA_FOLDER_USRDEF_TEMPLATE)
        {
            /* check for MAX 5 mms. shift other to draft folder in NON-COSMOS build */
            if(g_mma_msgmgr_cntx.mms_folder_status.userdefined_template_msg_num >= MMA_MAX_USER_DEF_TEMPLATE_NUM)
            {
                /* Need to create one API in wap_custem format to let customer configure the max userdef template */
                msg_list->folder = MMA_FOLDER_DRAFT;
            }
        }
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/
        /* Update the mms folder status */
        mma_msgmgr_update_mms_folder_status(msg_list, KAL_FALSE, 0, msg_list->folder);
    #if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
        if((msg_list->folder == MMA_FOLDER_INBOX) && (property_st->reserve_space == MMA_MSGMGR_IS_RECENT_EVT))
        {
            if(msg_list->mms_msg_type != MMA_MSG_TYPE_UNSUPPORTED)
            {
                mma_msgmgr_add_msg_to_recent_evt_list(msg_list->msg_id, msg_list->receive_date, msg_list->suffix);
            }
        }
    #endif
        MMA_FREE(property_st);
		property_st = NULL;
		MMA_FREE(large_data_st);
		large_data_st = NULL;
    }
    /* For unlimited MMS Support Start*/
    if((list->more == TRUE) && (mms_storage_type == MSF_MMS_STORAGE_PHONE))
    {    
        mma_check_and_sleep();
        MMSif_getMMSList(MSF_MODID_MMA, (list->startEntry + list->noOfElements),
            MAX_MMS_GET_PHONE_LIST_COUNT - 1, (MSF_UINT8) mms_storage_type);
            
    }
#ifdef  __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    else if((list->more == TRUE) && MSF_IS_MEM_CARD_PRESNT(MSF_MMS_STORAGE_MEM_CARD_1))
    {
        /* Ignore the More as TRUE case, if card is not present */
        mma_check_and_sleep();
        MMSif_getMMSList(MSF_MODID_MMA, (list->startEntry + list->noOfElements),
            MAX_MMS_GET_CARD_LIST_COUNT - 1, (MSF_UINT8) mms_storage_type);
    }
#endif  /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
	else
	{
    /* For unlimited MMS Support End*/
	#ifdef  __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
		if (MMA_MSGMGR_STATE_CREATE_CARD_MSG_LIST == MMA_MSGMGR_GET_STATE())
		{
	#endif  /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
			MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_READY);
        #ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
            MMSlib_getReportMmsCount(&report_count);
            g_mma_msgmgr_cntx.mms_folder_status.unread_report_msg_num = (kal_uint16)report_count;
        #endif
    #ifdef  __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
		}	
		else if(MMA_MSGMGR_STATE_CREATE_PHONE_MSG_LIST == MMA_MSGMGR_GET_STATE())
		{
            /*get the list of the memory card. If memory Card is supported */
            if(MSF_IS_MEM_CARD_PRESNT(MSF_MMS_STORAGE_MEM_CARD_1))
            {
			    MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_CREATE_CARD_MSG_LIST);
			    MMSif_getMMSList(MSF_MODID_MMA, 0, MAX_MMS_GET_CARD_LIST_COUNT - 1, MSF_MMS_STORAGE_MEM_CARD_1);
		    }
            else
            {
                MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_READY);
            #ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
                MMSlib_getReportMmsCount(&report_count);
                g_mma_msgmgr_cntx.mms_folder_status.unread_report_msg_num = (kal_uint16)report_count;
            #endif
            }
        }
		else if(MMA_MSGMGR_STATE_CREATE_CARD_PLUG_IN_MSG_LIST == MMA_MSGMGR_GET_STATE())
		{
			/* send the plug-in response to mma main */
			MMA_MSGMGR_SET_STATE(MMA_MSGMGR_STATE_READY);
			MMA_SIGNAL_SENDTO_IP(MMA_SUBMODULE_MSG_MAIN, MMA_INT_SIG_TYPE_MSG_MEM_CARD_PLUG_IN_RES, MMA_MSG_STORAGE_CARD1, NULL);
                        mms_mma_send_um_refresh_ind(MOD_MMI, MMA_FOLDER_ALL);
                        /* To execute the pending message. Get msg num by umms */
			mma_msgmgr_send_int_notify_ind();
		}
	#endif  /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
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
#endif

/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_msg_info_exist
 * DESCRIPTION
 *  to check whether the msg_info exist for the msg_id or not.
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mma_msgmgr_msg_info_exist(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    if (msg_info)
        return KAL_TRUE;
    else
        return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_msg_suffix
 * DESCRIPTION
 *  fill the msg_status of the msg in sending/receiving state.
 * PARAMETERS
 *  msg_id      [IN]        
 *  status      [IN]        
 *  result(?)       [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 mma_msgmgr_get_msg_suffix(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    //ASSERT(msg_info);
    if((msg_info == NULL) || (msg_info->suffix == 0) || (msg_info->suffix == MMS_SUFFIX_ERROR))
    {
        return MMS_SUFFIX_ERROR;
    }
    return msg_info->suffix;

}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_is_valid_notifiction
 * DESCRIPTION
 *  check for the valid notification.
 * PARAMETERS
 *  msg_id      [IN]        
 *  result(?)       [IN](?)
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mma_msgmgr_is_valid_notifiction(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    if(msg_info == NULL)
    {
        return KAL_FALSE;
    }
    if ((msg_info) && (msg_info->suffix == MMS_SUFFIX_NOTIFICATION || msg_info->suffix == MMS_SUFFIX_IMMEDIATE))
        return KAL_TRUE;
    else
        return KAL_FALSE;
}

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_report_data
 * DESCRIPTION
 *  check for the valid notification.
 * PARAMETERS
 *  msg_id      [IN]        
 *  result(?)       [IN](?)
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mma_msgmgr_get_report_data(kal_uint32 msg_id, MmaReport *get_report_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_msg_info_list_struct *msg_info = NULL;
    mma_result_enum result = MMA_RESULT_OK;
    mms_msg_info_large_data_struct *large_data_st = NULL;
    mms_msg_info_property_struct *property_st = NULL;
    kal_uint32 length = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info = mma_msgmgr_get_msg_from_list(msg_id); 
    if(msg_info == NULL)
    {
        /* Invalid msg_id */
        return KAL_FALSE;
    }
    
    if(msg_info->mms_msg_type == MMA_MSG_TYPE_UNSUPPORTED)
    {
        /* Give error information to subject. We need to use String ID */
        kal_wchar *error_str = NULL;

        error_str = (kal_wchar*) get_string(MMA_STR_ID_MESSAGE_CORRUPT);

        length = app_ucs2_strlen((const kal_int8*)error_str);
        if (length > 0)
        {
            if (length >= MMA_MAX_SUBJECT_LEN)
            {
                length = MMA_MAX_SUBJECT_LEN - 1;
            }
			
            get_report_data->subject = MMA_CALLOC((length + 1) * ENCODING_LENGTH);
            app_ucs2_strncpy(
                    (kal_int8*) get_report_data->subject,
                    (const kal_int8*)error_str,
                    length);
        }
        return KAL_TRUE;
    }
    else
    {
        large_data_st = (mms_msg_info_large_data_struct*)MMA_CALLOC(sizeof(mms_msg_info_large_data_struct));
        ASSERT(large_data_st);
        property_st = (mms_msg_info_property_struct*)MMA_CALLOC(sizeof(mms_msg_info_property_struct));
        ASSERT(property_st);
    
        result = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_info->msg_id),
                      (kal_uint8)mma_get_mms_type_message_storage(msg_info->msg_id),
                      property_st, large_data_st));
        if (result == MMA_RESULT_OK)
        {
            length = app_ucs2_strlen((const kal_int8*) large_data_st->from_address);
            if(length > 0)
		    {
			    if (length >= MMA_MAX_ADDR_LEN)
                {
                    length = MMA_MAX_ADDR_LEN - 1;
                }
            
                get_report_data->address = MMA_CALLOC((length + 1) * ENCODING_LENGTH);
            
                app_ucs2_strncpy(
                        (kal_int8*) get_report_data->address,
                        (const kal_int8*)large_data_st->from_address,
                        length);
                get_report_data->addrType = (MmsAddressType)large_data_st->from_address_type;
		    }

            length = app_ucs2_strlen((const kal_int8*) large_data_st->subject);
            if(length > 0)
		    {
			    if (length >= MMA_MAX_SUBJECT_LEN)
                {
                    length = MMA_MAX_SUBJECT_LEN - 1;
                }
			    
                get_report_data->subject = MMA_CALLOC((length + 1) * ENCODING_LENGTH);
                app_ucs2_strncpy(
                        (kal_int8*) get_report_data->subject,
                        (const kal_int8*)large_data_st->subject,
                        length);
		    }

            /*length = strlen((char*)large_data_st->java_reply_app_id);
            if(length > 0)
		    {
                long srcLen = 0;
                get_report_data->serverMsgId = MMA_CALLOC(length + 1);

			    srcLen = strlen((char*)large_data_st->java_reply_app_id);
			    gmms_msf_charset_utf8_to_utf8((const char *)large_data_st->java_reply_app_id , 
									     &srcLen,
									     (char*)get_report_data->serverMsgId, 
									     (long*)&length);
		    }*/

            get_report_data->date = (MmsTimeSec)msg_info->receive_date;
            get_report_data->readStatus = (MmsStatus)property_st->msg_report_status;
            MMA_FREE(large_data_st);
		    MMA_FREE(property_st);
		    return KAL_TRUE;
	    }
	    MMA_FREE(large_data_st);
	    MMA_FREE(property_st);
	}
    return KAL_FALSE;
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_parse_mode_msg_type
 * DESCRIPTION
 *  Return the msg type to the PARSE module.
 * PARAMETERS
 *  msg_id      [IN]        
 *  result(?)       [IN](?)
 * RETURNS
 *  
 *****************************************************************************/
mma_msg_type_enum mma_msgmgr_parse_mode_msg_type(kal_uint32 mode, kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mma_msg_type_enum msg_type = MMA_MSG_TYPE_MMS;
	mma_app_mode_enum msg_mode_type = MMA_MODE_RAW;
	mma_msg_info_list_struct *msg_p = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg_p = mma_msgmgr_get_msg_from_list(msg_id);
    if (msg_p != NULL)
    {
        if(mode == MMA_MODE_INT_PARSE)
	    {
		    /* handle only the create case. No need to check for postcard for the other cases */
            if(msg_p->new_msg_state == MMA_MSGMGR_GET_FROM_CREATE)
            {
                /* check only for the postcard, for other cases, no need to check*/
		        mma_msgmgr_new_msg_info_struct *new_msg_info = mma_msgmgr_get_new_msg_info_by_msg_id(msg_id);
                ASSERT(new_msg_info);
                /* check only for the create process. For receive send MMA_MSG_TYPE_MMS as msg_type*/
                if((new_msg_info->msg_type != MMA_MSGMGR_MSG_TYPE_DEFER_DOWNLOAD) && (new_msg_info->msg_type != MMA_MSGMGR_MSG_TYPE_PUSH))
                {
		            ASSERT((mma_msgmgr_create_info_struct*) (new_msg_info->data));
                    msg_mode_type = ((mma_msgmgr_create_info_struct*) (new_msg_info->data))->mode;
		            if(msg_mode_type == MMA_MODE_POSTCARD)
		            {
			            msg_type = MMA_MSG_TYPE_POSTCARD;
		            }
                }
            }
	    }
        else
        {
            msg_type = (mma_msg_type_enum)msg_p->mms_msg_type;
        }
    }
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MSGMGR_PARSE_MODE_RETURN_MSG_TYPE, "(mma_msgmgr.c): return msg_type as: %d",(int)msg_type));
	return msg_type;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_update_addr_objects_info_req_hdlr
 * DESCRIPTION
 *  Update the To, CC, BCC address & object file name list
 * PARAMETERS
 *  mmsAddrObjectInfo       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_update_addr_objects_info_req_hdlr(kal_uint32 msg_id, mmsAddrObjectInfo *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Update the data */
    MMSlib_genAddrObjFile(MMA_TRANSLATE_MSG_ID(msg_id), 
                        (kal_uint8)mma_get_mms_type_message_storage(msg_id), data);
    /* Free the memory */
    MMA_FREE(data);
}

#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_update_mms_thumbnail_info_req_hdlr
 * DESCRIPTION
 *  Update the thumbnail information of the mms
 * PARAMETERS
 *  mmsAddrObjectInfo       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mma_msgmgr_update_mms_thumbnail_info_req_hdlr(kal_uint32 msg_id, mmsBodyObjectInfo *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Update the data */
    MMSlib_genBodyObjFile(MMA_TRANSLATE_MSG_ID(msg_id), 
                        (kal_uint8)mma_get_mms_type_message_storage(msg_id), data);
    /* Free the memory */
    MMA_FREE(data);
}
#endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_set_read_status
 * DESCRIPTION
 *  This function is used to set the read status flag of msg
 * PARAMETERS
 *  msg_id      [IN]
 *  is_read      [IN]
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_result_enum mma_msgmgr_set_read_status(kal_uint32 msg_id, kal_bool is_read, mms_msg_info_property_struct *property_st)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;
    mma_msg_info_list_struct *msg_info = NULL;
    int index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    if (msg_info == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_MSGID;
    }
    if(msg_info->mms_msg_type == MMA_MSG_TYPE_UNSUPPORTED)
    {
        /* This mms is shown as READ mms */
        return MMA_RESULT_OK;
    }
    result = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_id),
                    (kal_uint8)mma_get_mms_type_message_storage(msg_id),
                    property_st, NULL));
    if(result == MMA_RESULT_OK)
    {
        /* disable the send Read report flag, while it's status is changed from UNREAD to READ
		and first time it's read report has been sent. This check is to prevent the Multiple 
		read report sending, in case of Mark as UNREAD functionalty */
		if(property_st->need_read_report)
		{
			property_st->need_read_report = FALSE;
        }
        if(property_st->is_read == is_read)
        {
            /* APP is wrongly set the Read status */
            msg_info->is_read = is_read;
            return MMA_RESULT_OK;
        }
        property_st->is_read = is_read;
		/* update the checksum of the property part */
        result = translate_mms_result_to_mma(MMSlib_UpdateChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_id), (MmsFileType)msg_info->suffix,
            (kal_uint8)mma_get_mms_type_message_storage(msg_id), property_st, NULL));
        mma_setting_set_registry_10_rr_all_string_res();
        if(result == MMA_RESULT_OK)
        {
            index = mma_msgmgr_get_index_from_sim_id((mma_sim_id_enum)msg_info->msg_sim_id);
            if(index < MMA_INDEX_FOR_SIM_UNCLASSIFIED || index >= MMA_MAX_INDEX_FOR_SIM)
            {
                ASSERT(0);
            }
            if(msg_info->folder == MMA_FOLDER_INBOX)
            {
                if(property_st->is_read == TRUE)
                {
                #if defined (__MMI_OP11_HOMESCREEN__) || defined (__MMI_OP12_TOOLBAR__) || defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
                    mma_msgmgr_remove_msg_from_unread_list(msg_info->msg_id);
                #endif
                    
                    g_mma_msgmgr_cntx.mms_folder_status.folder[index].inbox_unread_msg_num--;
                    g_mma_msgmgr_cntx.mms_folder_status.folder[index].inbox_read_msg_num++;
                }
                else
                {
                #if defined (__MMI_OP11_HOMESCREEN__) || defined (__MMI_OP12_TOOLBAR__) || defined( __MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
                    /* Marking it as Unread */
                    mma_msgmgr_add_new_msg_to_unread_list(msg_info->msg_id, msg_info->receive_date, msg_info->suffix);
                #endif

                    g_mma_msgmgr_cntx.mms_folder_status.folder[index].inbox_unread_msg_num++;
                    g_mma_msgmgr_cntx.mms_folder_status.folder[index].inbox_read_msg_num--;
                }
            }
            else if(msg_info->folder == MMA_FOLDER_ARCHIVE)
            {
                if((property_st->is_read == TRUE) && (msg_info->prev_folder == MMA_FOLDER_INBOX))
                {
                    g_mma_msgmgr_cntx.mms_folder_status.folder[index].archive_unread_inbox_msg_num--;
                    g_mma_msgmgr_cntx.mms_folder_status.folder[index].archive_read_inbox_msg_num++;
                }
            }
            msg_info->is_read = is_read;
        }
    }
    return result;    
}

#ifndef __MMI_SLIM_MMS_2__
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_set_lock_status
 * DESCRIPTION
 *  This function is used to set the lock/unkock status flag of msg
 * PARAMETERS
 *  msg_id      [IN]
 *  is_read      [IN]
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_result_enum mma_msgmgr_set_lock_status(kal_uint32 msg_id, kal_uint8 is_lock, kal_uint8 is_corrupt, mms_msg_info_large_data_struct *large_data_st)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;
    mma_msg_info_list_struct *msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    if (msg_info == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_MSGID;
    }
    
    result = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_info->msg_id),
                        (kal_uint8)mma_get_mms_type_message_storage(msg_info->msg_id),
                        NULL, large_data_st));
    if(result == MMA_RESULT_OK)
    {
        /* Ashok, only set the bit of the lock mode */
        large_data_st->app_data[MMA_MSGMGR_LOCK_MODE_APP_DATA_POS] = (kal_uint8)is_lock;
        large_data_st->app_data[MMA_MSGMGR_CORRUPT_MMS_POS] = (kal_uint8)is_corrupt;
        result = translate_mms_result_to_mma(MMSlib_UpdateChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_info->msg_id), (MmsFileType)msg_info->suffix,
                    (kal_uint8)mma_get_mms_type_message_storage(msg_info->msg_id), NULL, large_data_st));
    }
    return result;    
}
#endif /* __MMI_SLIM_MMS_2__ */
#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_set_sim_status
 * DESCRIPTION
 *  This function is used to set the sim status flag of msg
 * PARAMETERS
 *  msg_id      [IN]
 *  is_read      [IN]
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_result_enum mma_msgmgr_set_sim_status(kal_uint32 msg_id, kal_uint8 sim_id, mms_msg_info_property_struct *property_st)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_result_enum result = MMA_RESULT_OK;
    mma_msg_info_list_struct *msg_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info = mma_msgmgr_get_msg_from_list(msg_id);
    if (msg_info == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_MSGID;
    }
    if(msg_info->msg_sim_id == sim_id)
    {
        return result;
    }
    /* read the previous information of the Property data */
    result = translate_mms_result_to_mma(MMSlib_ReadFromChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_info->msg_id),
                        (kal_uint8)mma_get_mms_type_message_storage(msg_info->msg_id),
                        property_st, NULL));
    if (result == MMA_RESULT_OK)
	{
		property_st->msg_sim_id = sim_id;
		/* update the checksum of the Property part */
        result = translate_mms_result_to_mma(MMSlib_UpdateChkSumFile_Ext(MMA_TRANSLATE_MSG_ID(msg_info->msg_id), (MmsFileType)msg_info->suffix,
                (kal_uint8)mma_get_mms_type_message_storage(msg_info->msg_id), property_st, NULL));
	}
    if(result == MMA_RESULT_OK)
    {
        /* First Modify the count w.r.t SIM ID */
        mma_msgmgr_update_mms_folder_status(msg_info, KAL_TRUE, msg_info->folder, 0);
		msg_info->msg_sim_id = sim_id;
        mma_msgmgr_update_mms_folder_status(msg_info, KAL_FALSE, 0, msg_info->folder);
    }
    return result;
}
#endif

#ifdef __MMI_MMS_REPORT_BOX_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_reset_unread_report_count
 * DESCRIPTION
 *  This function is used to reset the unread report mms count
 * PARAMETERS
 *  void      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mma_msgmgr_reset_unread_report_count(void)
{
    if(g_mma_msgmgr_cntx.mms_folder_status.unread_report_msg_num != 0)
    {
        MMSlib_deleteReportMmsCount();
    }
    g_mma_msgmgr_cntx.mms_folder_status.unread_report_msg_num = 0;
}


/*****************************************************************************
 * FUNCTION
 *  mma_msgmgr_get_unread_report_count
 * DESCRIPTION
 *  This function is used to get the unread report mms count
 * PARAMETERS
 *  void      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint16 mma_msgmgr_get_unread_report_count(void)
{
    return g_mma_msgmgr_cntx.mms_folder_status.unread_report_msg_num;
}

#endif  /* __MMI_MMS_REPORT_BOX_SUPPORT__ */

#endif /* defined(MMS_SUPPORT) */ 
#endif /* _MMA_MSGMGR_C */ 

