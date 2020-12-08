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
 *  TcardSrvGProtSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  T Card service Global prototype declaration
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
*****************************************************************************/
#ifndef SRV_TCARDSRVGPROT_H
#define SRV_TCARDSRVGPROT_H

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
#include "mmi_rp_srv_tcard_def.h"
#include "Mmi_frm_mem_gprot.h"
#include "Tcard_config.h"



typedef void* TCARD_HANDLE; 

/*CHECK PLUG OUT ALWAYS OPEN, FILE ERROR, OR MULTI FILE*/

#define SRV_TCARD_MAX_MSG_NUM SMS_TCARD_ENTRY
#define SRV_TCARD_MAX_ADDR_NUM 100


#define SRV_TCARD_OP_INVALID_HDL 0xFFFFFFFF 
#define SRV_TCARD_OP_INVALID_INDEX 0xFFFFFFFF 
#define SRV_TCARD_APP_TOTAL 10
#define SRV_TCARD_FILE_TOTAL 20



/****************************************************/
/*                                                  */
/*               Enum                               */
/*                                                  */
/****************************************************/


typedef enum
{
    SRV_TCARD_OP_SUCC = 0, /* none */
    SRV_TCARD_OP_INVALID_PARA = -1, /* the para is invalid, such, the buff is NULL, the record id is invalid*/
    SRV_TCARD_OP_NOT_AVAILABLE = -2,/*the app init is error, not finish*/
    SRV_TCARD_OP_INVALID_CONTENT = -3,/*the content size is not equ the size expect*/
    SRV_TCARD_OP_MEM_INSUFFICIENT = -4,/*there is no handle*/
    SRV_TCARD_OP_FS_ERROR = -5

} srv_tcard_op_result_enum;

typedef enum
{
    SRV_TCARD_NONE = 0, /* none */
    SRV_TCARD_OPEN, 
    SRV_TCARD_READ,
    SRV_TCARD_WRITE,
    SRV_TCARD_INIT,

    /*Add the file name in the end */
    SRV_TCARD_OP_TOTAL
} srv_tcard_op_enum;



typedef struct
{
    S32 result;                /* Result of the operation: MMI_TRUE: success; MMI_FALSE: failed */
    srv_tcard_op_enum action;     /* Action to indicate the operation type(read/save/Delete...), refer to srv_sms_action_enum */
    U32 data_size;
    void *action_data;
    void *user_data; 
} srv_tcard_callback_struct;

typedef struct
{
    srv_tcard_app_index_enum app_index;
    srv_tcard_file_index_enum file_index;         /* where to backup or restore the sms */
    U32 start_record_id;
    U32 record_num;
} srv_tcard_op_struct;



typedef struct
{
    MMI_EVT_PARAM_HEADER
    void *event_info;               
} srv_tcard_event_struct;


typedef struct
{
    MMI_BOOL is_tcard_ready;      /* Flag to indciate whether tcard service is ready or not */
} srv_tcard_event_tcard_ready_struct;

/*****************************************************************************
 * FUNCTION
 *  srv_tcard_read_record
 * DESCRIPTION
 *  to read a record in a file 
 * PARAMETERS
 *  app_index: [in] the app's index, it can identify a folder
 *  file_index: [in] the file index, it identify a file name.
 *  record_id: [in] the record id that will be read in the 
 *  buff: [in/out] to hold the content
 * RETURNS
 *  the result of the read action
 *****************************************************************************/
typedef void(*SrvTcardCallbackFunc)(srv_tcard_callback_struct* callback_data); 

extern TCARD_HANDLE srv_tcard_read_record(
                        srv_tcard_op_struct *read_cntx, 
                        CHAR *buff,
                        SrvTcardCallbackFunc callback_func,
                        void *user_data);

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
/*****************************************************************************
 * FUNCTION
 *  srv_tcard_read_record
 * DESCRIPTION
 *  to read a record in a file 
 * PARAMETERS
 *  app_index: [in] the app's index, it can identify a folder
 *  file_index: [in] the file index, it identify a file name.
 *  record_id: [in] the record id that will be read in the 
 *  buff: [in] the content to write to the file
 * RETURNS
 *  the result of the write action
 *****************************************************************************/

extern TCARD_HANDLE srv_tcard_write_record(
                        srv_tcard_op_struct *cntx,
                        CHAR *buff,
                        SrvTcardCallbackFunc callback_func,
                        void *user_data);
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
#endif


extern MMI_BOOL srv_tcard_query_app_stauts(srv_tcard_app_index_enum app_index);
extern S32 srv_tcard_sync_write_record(srv_tcard_op_struct *read_cntx, CHAR *buff);
extern S32 srv_tcard_sync_read_record(srv_tcard_op_struct *read_cntx, CHAR *buff);
#endif /*__SRV_TCARD_DATA_STORE__*/
#endif



