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
 *  SmsProtSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Internal Prototype Header File
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __SMS_PROT_SRV_H__
#define __SMS_PROT_SRV_H__
#include "MMI_features.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "SmsSrvGprot.h"
#include "Ems.h"
#include "customer_ps_inc.h"
#include "mmi_frm_utility_gprot.h"
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
#include "TcardSrvGprot.h"
#endif
#include "SmsArchiveSrv.h"




#define SRV_SMS_MSG_LEN             160

#define SRV_SMS_MAX_BUFF_SIZE       (2048)
#define SRV_SMS_MAX_CHAR_NUM        (SRV_SMS_MAX_BUFF_SIZE / ENCODING_LENGTH)

#define SRV_SMS_MAX_SEND_SEG        MMI_SMS_MAX_MSG_SEG

#define SRV_SMS_MAX_SPDU_SIZE       (sizeof(srv_sms_spdu_struct))
#define SRV_SMS_MAX_PDU_SIZE        (175)

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
#define SRV_SMS_MAX_TCARD_SPDU_SIZE       (sizeof(srv_sms_tcard_spdu_struct))
#endif


#define SRV_SMS_RESERVED_HANDLE     ((void*)0xFFFFFFFF)

#define SRV_SMS_INVALID_ADDR_ID     (0xFFFF)

#ifdef __SRV_SMS_MULTI_SIM__
#define SMS_SIM_NUM                 MMI_SIM_TOTAL
#else /* __SRV_SMS_MULTI_SIM__ */
#define SMS_SIM_NUM                 1
#endif /* __SRV_SMS_MULTI_SIM__ */

#ifdef __SRV_SMS_SIMBOX_SUPPORT__
#define __SRV_SMS_ME_PREFER_STORAGE_ONLY__
#else /* __SRV_SMS_SIMBOX_SUPPORT__ */
#ifdef __SRV_SMS_ME_PREFER_STORAGE_ONLY__
#undef __SRV_SMS_ME_PREFER_STORAGE_ONLY__
#endif /* __SRV_SMS_ME_PREFER_STORAGE_ONLY__ */
#endif /* __SRV_SMS_SIMBOX_SUPPORT__ */
#ifdef __SRV_SMS_ARCHIVE__
#define SRV_SMS_MAX_MSG_NUM             (SRV_SMS_MAX_SMS_ENTRY + SRV_SMS_MAX_ARCH_ENTRY)
#else /* __SRV_SMS_ARCHIVE__ */
#define SRV_SMS_MAX_MSG_NUM             SRV_SMS_MAX_SMS_ENTRY
#endif

#define SRV_SMS_HANDLE_HEADER                   \
            srv_sms_action_enum action;         \
            MMI_BOOL is_abort;                  \
            void *hd_data;                      \
            SrvSmsCallbackFunc abort_func;      \
            void *abort_user_data;              \
            SrvSmsCallbackFunc callback_func;   \
            void *user_data;                    \
            SMS_HANDLE sub_handle;              \
            SrvSmsCallbackFunc sub_abort_func;  \
            void *sub_user_data;

#define CNTX_IS_ABORT(cntx)             ((cntx)->is_abort)
#define CNTX_GET_ACTION(cntx)           ((cntx)->action)
#define CNTX_SET_HD_DATA(cntx, data)    (cntx)->hd_data = (data)
#define CNTX_GET_HD_DATA(cntx)          ((cntx)->hd_data)
#define CNTX_SET_CALLBACK(cntx, callback, user_data)    \
            do                                          \
            {                                           \
                (cntx)->callback_func = (callback);     \
                (cntx)->user_data = (user_data);        \
            } while (0)

#define CNTX_SET_SUB_HANDLE(cntx, handle, func)         \
            do                                          \
            {                                           \
                if (handle != SRV_SMS_INVALID_HANDLE)   \
                {                                       \
                    (cntx)->sub_handle = (handle);      \
                    (cntx)->sub_abort_func = (func);    \
                    (cntx)->sub_user_data = (cntx);     \
                }                                       \
            } while (0)


typedef enum
{
    SMS_SIM1 = 0,
    SMS_SIM2 = 1,
    SMS_SIM3 = 2,
    SMS_SIM4 = 3
} sms_sim_enum;

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
typedef enum
{
    SRV_SMS_UPDATE_TCARD_ADDR_LIST = 1,    
    SRV_SMS_UPDATE_TCARD_PDU_LIST = 2,
    SRV_SMS_UPDATE_TCARD_SMS_PDU = 4
} srv_sms_update_tcard_op_enum;
#endif

/* SMS Address Type */
typedef enum
{
    SRV_SMS_ADDR_NATIONAL_NUM       = 0x81, /* National Number, ISDN/telephone numbering plan */
    SRV_SMS_ADDR_INTERNATIONAL_NUM  = 0x91, /* International Number, ISDN/telephone numbering plan */

    SRV_SMS_ADDR_NATIONAL_MASK      = 0x80, /* National Number Mask */
    SRV_SMS_ADDR_INTERNATIONAL_MASK = 0x90, /* International Number Mask */
    SRV_SMS_ADDR_ALPHANUMERIC       = 0xD0, /* Alphanumeric Mask*/

    SRV_SMS_ADDR_RESERVED
} srv_sms_address_type_enum;


/* Validity-Period Format */
typedef enum
{
    SRV_SMS_VPF_NOT_PRESENT = 0x00, /* TP-VP field not present */
    SRV_SMS_VPF_RELATIVE    = 0x10, /* TP-VP field present - relative format */
    SRV_SMS_VPF_ENHANCED    = 0x08, /* TP-VP field present - enhanced format */
    SRV_SMS_VPF_ABSOLUTE    = 0x18  /* TP-VP field present - absolute format */
} srv_sms_vp_format_enum;

/* Pack EMSData to TP-UD Flag */
typedef enum
{
    SRV_SMS_PACK_DEFAULT            = 0x00,
    SRV_SMS_PACK_SAVE_NON_STD       = 0x01,
    SRV_SMS_PACK_DYNAMIC_SEG        = 0x02,
    SRV_SMS_PACK_REVERED
} srv_sms_pack_enum;

/* Pack EMSData to TP-UD Flag */
typedef enum
{
    SRV_SMS_UNPACK_DEFAULT          = 0x00,
    SRV_SMS_UNPACK_REPLACE_END_CHAR = 0x01,
    SRV_SMS_UNPACK_ORI_8BIT_DATA    = 0x02,
    SRV_SMS_UNPACK_REVERED          = 0xFF
} srv_sms_unpack_enum;

/* If want to adjust the order of this structure's member, 
 * need to modify the compare msg node function, 
 * ex. srv_sms_search_concatenated_sms()
 * In those function, we use memcmp() to compare two msg node */
typedef struct
{
    /* srv_sms_status_enum */
    U8 status;

#ifdef __SRV_SMS_MSG_INFO_DCS__ 
	U8 dcs;
#endif /* __SRV_SMS_MSG_INFO_DCS__ */

#ifdef __SRV_SMS_MSG_EXT_STATUS__ 
	U8 ext_status;
#endif /* __SRV_SMS_MSG_EXT_STATUS__ */

#ifdef __SRV_SMS_RESEND_COUNT__
    U8 resend_count;
#endif /* __SRV_SMS_RESEND_COUNT__ */

    /* <<-- msg node compare range start */
    U8 storage_type;
    U8 mti;
	U8 pid;

    /* Concatenated inforamtion */
    U8 total_seg;
    U8 start_seg;
    U16 ref_num;

#ifdef __SRV_SMS_MULTI_SIM__ 
	U16 sim_id;
#endif /* __SRV_SMS_MULTI_SIM__ */

#ifdef __SRV_SMS_MULTI_ADDR__
    /* Extension address number */
    U16 ext_addr_num;
    /* Start Externsion Address ID */
    U16 start_addr_id;
#endif /* __SRV_SMS_MULTI_ADDR__ */

#ifdef __SRV_SMS_MSG_INFO_PORT__
    U16 port_num;
#endif /* __SRV_SMS_MSG_INFO_PORT__ */
    /* msg node compare range End -->> */

    U16 start_pdu_id;

    S8 number[SRV_SMS_MAX_ADDR_LEN + 1];

#ifdef __SRV_SMS_MSG_INFO_CONTENT__
    U16 content[SRV_SMS_MSG_INFO_CONTENT_LEN + 1];
#endif /* __SRV_SMS_MSG_INFO_CONTENT__ */

    U32 timestamp;
} srv_sms_msg_node_struct;

#ifdef __SRV_SMS_MULTI_ADDR__

/* Extension Address Structure, need to sync with structure srv_sms_addr_record_struct */
typedef struct
{
    U16 next_addr_id;
    /* srv_sms_status_enum, Unsent/Sent, if it is SRV_SMS_STATUS_NONE, this node is unused */
    U8 status;
#ifdef __SRV_SMS_MULTI_ADDR_REPORT__
    U8 total_seg;
    U8 msg_ref[SRV_SMS_MAX_SEG];
    U8 tp_st[SRV_SMS_MAX_SEG];
#endif /* __SRV_SMS_MULTI_ADDR_REPORT__ */
    S8 address[SRV_SMS_MAX_ADDR_LEN + 1];
} srv_sms_addr_node_struct;

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
typedef struct
{
    U16 next_addr_id;
    /* srv_sms_status_enum, Unsent/Sent, if it is SRV_SMS_STATUS_NONE, this node is unused */
    U8 status;
    U8 total_seg;
    U8 msg_ref[10];
    U8 tp_st[10];
    S8 address[SRV_SMS_MAX_ADDR_LEN + 1];
} srv_sms_tcard_addr_node_struct;
#endif
#endif /* __SRV_SMS_MULTI_ADDR__ */

/* SPDU Structure, need to sync with structure nvram_ef_srv_sms_pdu_struct */
typedef struct
{
    /* this status is msg status, not the SPDU status, refer to srv_sms_status_enum */
    U8 status;
    U8 pdu[SRV_SMS_MAX_PDU_SIZE];
    U32 timestamp;
#ifdef __SRV_SMS_MULTI_SIM__
    U16 sim_id;
#endif /* __SRV_SMS_MULTI_SIM__ */

#ifdef __SRV_SMS_MULTI_ADDR__
    /* Extension address number */
    U16 addr_num;
    /* Start Externsion Address ID, Address NVRAM record index */
    U16 start_addr_id;
#endif /*  __SRV_SMS_MULTI_ADDR__*/

#ifdef __SRV_SMS_RESEND_COUNT__
    U8 resend_count;
#endif /* __SRV_SMS_RESEND_COUNT__ */
#ifdef __SRV_SMS_DELIVERY_STATUS__
    U8 tp_st;
#endif /* __SRV_SMS_DELIVERY_STATUS__ */
} srv_sms_spdu_struct;

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*tcard*/
typedef struct
{
    U8 status;
    U8 pdu[SRV_SMS_MAX_PDU_SIZE];
    U32 timestamp;
    U16 sim_id;
    U16 addr_num;
    U16 start_addr_id;
    U8 resend_count;
    U8 tp_st;
} srv_sms_tcard_spdu_struct;

#endif
typedef struct
{
    SRV_SMS_HANDLE_HEADER
    U16 pdu_id_list[SRV_SMS_MAX_SEG];
    U8 total_pdu;
    U8 curr_index;
    U16 msg_id;
    MMI_BOOL is_background;
} srv_sms_delete_cntx_struct;





/* Message Data Struture */
typedef struct
{
    S8 number[(SRV_SMS_MAX_ADDR_LEN +1) *ENCODING_LENGTH];
    MMI_BOOL is_allow_num_emtpy;
    srv_sms_storage_enum storage_type;
    srv_sms_sim_enum sim_id;

#ifdef __SRV_SMS_MULTI_ADDR__
    /* Total Address number, include the number and the extension address */
    U16 addr_num;
    /* Extension Address list */
    srv_sms_addr_struct *ext_addr;
#endif /* __SRV_SMS_MULTI_ADDR__ */
    /* <<-- if save a SMS, Above member must be given, otherwise, we will fill the default value */

    srv_sms_para_enum para_flag;

    /* If want to set below members, you must set the according para_flag -->> */
    srv_sms_status_enum status;

    MMI_BOOL is_allow_sc_emtpy;
    S8 sc_address[(SRV_SMS_MAX_ADDR_LEN +1) *ENCODING_LENGTH];

    U16 src_port;
    U16 dest_port;

    /* Delivery status information */
    U16 report_id;
    U8 msg_ref[SRV_SMS_MAX_SEG];
    U8 total_seg;

    srv_sms_pid_enum pid;
    srv_sms_vp_enum vp;
    MMI_BOOL status_report;
    MMI_BOOL reply_path;

    srv_sms_dcs_enum dcs;
    srv_sms_class_enum class;

#ifdef __SRV_SMS_RESEND_COUNT__
    U8 resend_count;
#endif /* __SRV_SMS_RESEND_COUNT__ */

    /* Content information */
    MMI_BOOL is_asc_content;
    U16 content_buff_size;
    S8 *content_buff;
    S8 *content_file_path;
    EMSData *content_ems;

    MYTIME timestamp;
} srv_sms_int_msg_data_struct;

typedef struct
{
    srv_sms_action_enum action;
    MMI_BOOL is_abort;
    void *hd_data;
    SrvSmsCallbackFunc abort_func;
    void *abort_user_data;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
    SMS_HANDLE sub_handle;
    SrvSmsCallbackFunc sub_abort_func;
    void *sub_user_data;
} srv_sms_handle_struct;

typedef struct
{
    U16 reply_msg_id;
    U16 msg_id;
    U16 action_id;
#ifdef __SRV_SMS_MULTI_ADDR__
    U8 cur_send_index;
#endif
    MMI_BOOL is_tp_srr;
    U16 report_id;
    srv_sms_sim_enum  sim_id;
    MMI_BOOL is_mms;
    MMI_BOOL is_abort;
    U8 total_segment;
    U8 present_seg;
    U16 ref_num;
    U8 *pdu_list[SRV_SMS_MAX_SEG];
    U8 pdu_len_list[SRV_SMS_MAX_SEG];
    U8 msg_ref[SRV_SMS_MAX_SEG];
    MMI_BOOL is_use_action;
    srv_sms_send_type_enum send_type;
    srv_sms_specify_send_para_enum spec_para;
    srv_sms_int_msg_data_struct msg_data;
    srv_sms_command_type_enum cmdtype;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_send_handle_struct;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__

typedef struct
{
    MMI_BOOL is_in_change;
    U16 msg_id; 
    srv_sms_status_enum status;
} srv_sms_tcard_action_cntx_struct;
#endif

#endif /* __SMS_PROT_SRV_H__ */

