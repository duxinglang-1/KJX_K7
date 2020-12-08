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
 *  TcardUtilSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  T Card service int prototype declaration
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
*****************************************************************************/
#ifndef SRV_TCARDUTILSRV_H
#define SRV_TCARDUTILSRV_H

#include "MMI_features.h"
#ifdef __SRV_TCARD_DATA_STORE__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "custom_mmi_default_value.h"
#include "ps_public_enum.h"
#include "stack_config.h"
#include "customer_ps_inc.h"
#include "nvram_common_defs.h"
#include "Fs_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "Mmi_cb_mgr_gprot.h"

#include "TcardSrvprot.h"
#include "TcardSrvGprot.h"


/**************************************************************
* MARCO
**************************************************************/


/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    MMI_EVT_PARAM_HEADER
    SrvTcardCallbackFunc callback_func;
    srv_tcard_callback_struct callback_data;
} srv_tcard_evt_callback_struct;

typedef struct
{
    srv_tcard_op_enum action;
    S32 result;
    void *action_data;
    U32 data_size;
    void *user_data;
    SrvTcardCallbackFunc callback_func;
}srv_tcard_async_struct;

typedef struct
{
    srv_tcard_op_enum action;         
    MMI_BOOL is_abort;                  
    SrvTcardCallbackFunc callback_func; 
    void *user_data; 
    CHAR *action_buff;
    CHAR *curr_ptr;
    CHAR *next_ptr;                  
    U32 start_index;
    U32 record_num;
    U32 record_size;
    U32 curr_index;
    U32 remain_num;
    FS_HANDLE hd;
    MMI_BOOL is_backup;
} srv_tcard_read_cntx_struct;


typedef struct
{
    srv_tcard_op_enum action;         
    MMI_BOOL is_abort;                  
    SrvTcardCallbackFunc callback_func; 
    void *user_data;
    CHAR *action_buff;
    CHAR *curr_ptr;
    CHAR *next_ptr;                    
    srv_tcard_file_entry_struct *record;
    U32 start_index;
    U32 record_num;
    U32 record_size;
    U32 curr_index;
    U32 remain_num;
    FS_HANDLE hd;
    MMI_BOOL is_backup;
    MMI_BOOL is_org;
} srv_tcard_write_cntx_struct;


typedef struct
{
    srv_tcard_op_enum action;         
    MMI_BOOL is_abort;                  
    SrvTcardCallbackFunc callback_func; 
    void *user_data;
}srv_tcard_handle_struct;


extern srv_tcard_file_entry_struct tcard_file_mgr_common_table[SRV_TCARD_MAX_FILE_SUPPORT];

/**************************************************************
* Extern Function Declaration
**************************************************************/
extern mmi_ret srv_tcard_async_callback_proc(mmi_event_struct *param);

extern void srv_tcard_async_callback(
                srv_tcard_op_enum action,
                S32 result,
                void *action_data,
                U32 action_data_size,
                void *user_data,
                SrvTcardCallbackFunc callback_func);

extern S32 srv_tcard_get_app_index(srv_tcard_file_index_enum file_index);

extern MMI_BOOL srv_tcard_check_op_para(srv_tcard_op_struct *op_cntx, srv_tcard_file_entry_struct *record);

extern void srv_tcard_emit_event(U32 event_id, void* event_info);

extern void srv_tcard_callback(
                srv_tcard_op_enum action,
                MMI_BOOL result,
                srv_tcard_op_result_enum cause,
                void *action_data,
                void *user_data,
                SrvTcardCallbackFunc callback_func);

extern void srv_tcard_handle_asyc(void *arg);


/**************************************************************
* Static Variables Defination
**************************************************************/



/**************************************************************
* Static Function Declaration
**************************************************************/
#endif
#endif


