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
 *  SmsBackupRestoreSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Backup and Restore 
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *****************************************************************************/
#ifndef __SRV_SMS_BACKUP_RESTORE_H__
#define __SRV_SMS_BACKUP_RESTORE_H__
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "custom_mmi_default_value.h"
#include "ps_public_enum.h"
#include "stack_config.h"
#include "customer_ps_inc.h"
#include "nvram_common_defs.h"
#include "mmi_rp_srv_sms_def.h"
#include "SmsSrvGprot.h"


#ifdef __cplusplus
 extern "C"
 {
#endif

typedef enum
{
    SRV_SMS_CLOUD_ACTION_NONE,      /*NOT IN BACKUP OR RESTORE*/
    SRV_SMS_CLOUD_ACTION_BACKUP,    /* BACKUP */
    SRV_SMS_CLOUD_ACTION_RESTORE,     /* RESTORE */
    SRV_SMS_CLOUD_ACTION_ALL        
} srv_sms_cloud_action_enum;

typedef struct
{
    SRV_SMS_HANDLE_HEADER
    MMI_BOOL result;
    S8 ext_number[(SRV_SMS_MAX_ADDR_LEN + 1)*SRV_SMS_MAX_CLOUD_RECIPIENTS_NUM];
    U8 ext_number_num;
    U16 uid_index;/*for syc UID*/
    U16 curr_index;
    U16 total_index;
    U16 *msg_id_list;
    U16 msg_list_size;
    S32 error_cause;
    S32 handle;
    SMS_HANDLE sms_hdlr;
} srv_sms_backup_cntx_struct;

typedef struct
{
    S8 number[(SRV_SMS_MAX_ADDR_LEN + 1) *ENCODING_LENGTH];
    U8 ext_number_num;
    S8 is_allow_num_emtpy;
    S32 storage_type;
    S32 sim_id;
    S32 para_flag;
    S32 status;
    S8 is_allow_sc_emtpy;
    CHAR sc_address[(SRV_SMS_MAX_ADDR_LEN +1) *ENCODING_LENGTH];
    U16 src_port;
    U16 dest_port;
    U16 report_id;
    U8 msg_ref[10];
    U8 total_seg;
    S32 pid;
    S32 vp;
    S8 status_report;
    S8 reply_path;
    S32 dcs;
    S32 msg_class;
    /* Content information */
    S8 is_asc_content;
} srv_sms_backup_restore_msg_data_struct;

typedef struct
{
    SRV_SMS_HANDLE_HEADER
    MMI_BOOL result;
    S32 error_cause;
    U16 uid_index;/*for syc UID*/
    U8 more_data;
    S32 handle;
    U16 curr_num;
    srv_sms_backup_restore_msg_data_struct backup_restore_msg_data;
} srv_sms_restore_cntx_struct;

extern srv_sms_cloud_action_enum in_cloud_action;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
extern srv_sms_restore_cntx_struct * srv_sms_get_restore_ctnx(void);
extern srv_sms_backup_cntx_struct * srv_sms_get_backup_ctnx(void);
extern srv_sms_cloud_action_enum srv_sms_get_cloud_action_ctnx(void);


#ifdef __cplusplus
 }
#endif

#endif

