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
 *   mmc_struct.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMC_STRUCT_H
#define _MMC_STRUCT_H

#include "app_ltlcom.h"
#include "stack_config.h"
#include "kal_general_types.h"

typedef enum
{
    WAP_MMS_PROF_MMSC_ADDRESS /* WAP MMSC address */
} wap_mms_prof_access_enum;

typedef enum
{
    MMC_RESULT_OK,
    MMC_RESULT_BUSY,
    MMC_RESULT_INSUFFICIENT_MEMORY,
    MMC_RESULT_INSUFFICIENT_PERSISTENT_STORAGE,
    MMC_RESULT_INVALID_MESSAGE,
    MMC_RESULT_INVALID_MESSAGE_BODY,
    MMC_RESULT_MESSAGE_ID_NOT_FOUND,
    MMC_RESULT_FILE_OPERATION_ERROR,
    MMC_RESULT_INVALID_FOLDER,
    MMC_RESULT_ACCESS_DENY,
    MMC_RESULT_INVALID_PARAMETER,
    MMC_RESULT_EXCEED_MAX_MSGS,
    MMC_RESULT_ERROR,
    MMC_RESULT_MMS_NO_READY,
    MMC_RESULT_NO_MSG_FOR_JAVA,
    MMC_RESULT_ERROR_APPID_EXIST,
    MMC_RESULT_ERROR_APPID_NOT_FOUND,
    MMC_RESULT_ERROR_APPID_TOO_LARGE,
    MMC_RESULT_ERROR_APPID_FULL,
    MMC_RESULT_ERROR_FAIL_TO_GEN_MMS_HDR,
    MMC_RESULT_ERROR_FAIL_TO_WR_MMS_HDR,
    MMC_RESULT_ERROR_MSG_CORRUPTED,
    MMC_RESULT_ERROR_SEND_CANCEL_BY_SYSTEM,
    MMC_RESULT_ERROR_MESSAGE_TOO_LARGE
} mmc_result_enum;

typedef enum
{
    MMC_US_ASCII            = 3,   
    MMC_UTF8                = 106,
    MMC_UCS2                = 1000,
    MMC_UTF16BE             = 1013, 
    MMC_UTF16LE             = 1014, 
    /*< UTF-16 is to be used only if the document starts with a UTF-16 BOM  */
    MMC_UTF16               = 1015, 
    MMC_ISO_8859_1          = 4,
    MMC_CHARSET_EUC_JP      = 18,
    MMC_CHARSET_ISO_2022_JP = 39,
    MMC_CHARSET_SHIFT_JIS   = 17,
    MMC_UNKNOWN_CHARSET     = 0
} mmc_charset_enum;

typedef enum
{
    MMC_SIM_CARD_SIM1     = 1,
    MMC_SIM_CARD_SIM2,
    MMC_SIM_CARD_SIM3,
    MMC_SIM_CARD_SIM4,
    MMC_SIM_CARD_MAX_SIM
} mmc_sim_card_enum;

typedef struct 
{	
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    kal_uint8 app_id_len;
    kal_uint8 app_id[100];
}wap_mmc_recv_appmms_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result; /* FFS */
    kal_uint8 priority; //WAP_MMS_PRIORITY_LOW:0,  WAP_MMS_PRIORITY_MED: 1, WAP_MMS_PRIORITY_HIGH: 2
    kal_uint8 from_addr_no; //If this value is zero, please skip item 2 (FROM address field)of peer bufer.
    kal_uint8 to_addr_no;
    kal_uint8 cc_addr_no;
    kal_uint8 bdy_part_no;
    kal_uint32 date;
    kal_uint8 start_cnt_id_len;  
    kal_uint8 start_cnt_id[100];
    kal_uint8 reply_app_id_len;
    kal_uint8 reply_app_id[100];
    kal_uint8 simId;
    kal_uint8 is_more_msg;
}wap_mmc_recv_appmms_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 send_by_file; //SEND BY MEM:0, SEND BY FILE:1
    kal_uint8 filepath_len; //Valid when send_by_file=1
    kal_wchar filepath[100];//Valid when send_by_file=1 
    kal_uint8 mms_type; //WAP_MMS_MULTIPART_RELATED: 0, WAP_MMS_MULTIPART_MIXED: 1
    kal_uint8 priority; //WAP_MMS_PRIORITY_LOW:0,  WAP_MMS_PRIORITY_MED: 1, WAP_MMS_PRIORITY_HIGH: 2
    kal_uint8 to_addr_no;
    kal_uint8 cc_addr_no;
    kal_uint8 bcc_addr_no;
    kal_uint8 bdy_part_no;
    kal_uint32 delivery_time; /*tony: 0 means deliver immediately*/
    kal_uint8 app_id_len;
    kal_uint8 reply_app_id_len;
    kal_uint8 start_cnt_id_len;   
    kal_uint8 app_id[100];
    kal_uint8 reply_app_id[100];
    kal_uint8 start_cnt_id[100];
    kal_uint8 simId;
}wap_mmc_send_appmms_req_struct;

typedef struct 
{	
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    kal_uint8 result; /* FFS */
}wap_mmc_send_appmms_rsp_struct;

typedef struct 
{	
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    kal_uint8 result; /* FFS */
}wap_mmc_post_appmms_msg_part_ind_struct;

typedef struct 
{	
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 encoding_scheme;
    kal_uint8 content_type_len;
    kal_uint8 content_type[256];
    kal_uint8 content_id_len;
    kal_uint8 content_id[100];
    kal_uint8 content_location_len;
    kal_uint8 content_location[100];   
    kal_uint8 filepath_len;
    kal_wchar filepath[100];
}wap_mmc_post_appmms_msg_part_res_struct;

typedef struct 
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result; /* FFS */
    kal_uint8 encoding_scheme;
    kal_uint32 content_type_value; /*MmsKnownMediaType*/
    kal_uint8 content_type_len;
    kal_uint8 content_type[256];
    kal_uint8 content_id_len;
    kal_uint8 content_id[100];
    kal_uint8 content_location_len;
    kal_uint8 content_location[100];   
    kal_uint8 filepath_len;
    kal_wchar filepath[100];
}wap_mmc_read_appmms_msg_part_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 vm_id;
    kal_uint8 op; //SET APP ID:0, REMOVE APP ID: 1
    module_type  ind_module; // the task which is indicated when new MMS with app_id is received
    kal_uint8 app_id_len;
    kal_uint8 app_id[100];
} wap_mmc_cfg_appmms_appid_req_struct;
typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 vm_id;
    kal_uint8	result;
} wap_mmc_cfg_appmms_appid_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool only_new;
    kal_uint8 app_id_len;
    kal_uint8 app_id[100];
} wap_mmc_check_appmms_coming_req_struct;
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8	result;
} wap_mmc_check_appmms_coming_rsp_struct;

typedef struct 
{	
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    kal_uint8 result;
}wap_mmc_abort_appmms_rsp_struct;

typedef struct 
{	
    LOCAL_PARA_HDR
    kal_uint32 access_id; /* wap_mms_prof_access_enum.*/
    kal_uint8 simId;
}wap_mmc_get_mms_prof_req_struct;

typedef struct 
{	
    LOCAL_PARA_HDR
    kal_uint8 result; /* 0 means Success; 1 means MMS is not ready yet; 2 means invalid prof_id*/
    kal_uint8 value_len; /*length include NULL terminator*/
    kal_uint8 value[256];
}wap_mmc_get_mms_prof_rsp_struct;

typedef struct 
{	
    LOCAL_PARA_HDR
    kal_uint8 app_id_len;
    kal_uint8 app_id[100];
}wap_mmc_appmms_new_mms_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar filename[261]; /* FMGR_MAX_PATH_LEN(260) + NULL char */
}mms_get_attachment_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar filepath[261];	/* FMGR_MAX_PATH_LEN(260) + NULL char */
    kal_uint8 result;
}mms_get_attachment_rsp_struct;

#endif /*_MMC_STRUCT_H*/
