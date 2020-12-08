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

/*******************************************************************************
 * Filename:
 * ---------
 *   das_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for local parameter declaration about DAS SAP
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                              HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _DAS_STRUCT_H
#define _DAS_STRUCT_H 

#include "kal_general_types.h"

/* Maximum URL length in byte */
#define WAP_DL_MAX_URL_LEN          (1020)  
/* Maximum MIME type in byte */
#define WAP_DL_MAX_MIME_TYPE_LEN    (512)  
/* Maximum file name in byte */
#define WAP_DL_MAX_FILE_NAME_LEN    (256)  


/* This enum is used to indicate the result and error code of a response from MMI. */
typedef enum
{
    WAP_DL_ERROR_OK,                    /* Success */
    WAP_DL_ERROR_CANCELLED,             /* Operation cancelled */
    WAP_DL_ERROR_INVALID_SESSION_ID,    /* Invaild session id */
    WAP_DL_ERROR_CONNECTION_CLOSED,     /* Connection closed */
    WAP_DL_ERROR_INVALID_FILE,          /* Invalid filename */
    WAP_DL_ERROR_DISK_FULL,             /* Disk full */
    WAP_DL_ERROR_FILE_ACCESS,           /* File access error */
    WAP_DL_ERROR_FILE_READ_ONLY,        /* File read only */
    WAP_DL_ERROR_NEED_CONTENT           /* For progressive download */
} wap_dl_error_enum;

/* This enum is used to indicate the status of downloading replied content while the reply data type is file. */
typedef enum
{
    WAP_DL_STATUS_DOWNLOADING, /* Downloading is in progress */
    WAP_DL_STATUS_COMPLETE,    /* Complete downloading */
    WAP_DL_STATUS_ABORTED,     /* Downloading is aborted by network side */
    WAP_DL_STATUS_CANCELLED    /* Downloading is cancelled by user */
} wap_dl_status_enum;

/* This enum is used to indicate bearer switch type when download need to switch from one bearer to other. */
typedef enum
{
    WAP_DL_BEARER_SWITCH_NONE,
    WAP_DL_BEARER_SWITCH_WIFI_TO_PS,   /* Netork switch from WLAN to cellular network */
    WAP_DL_BEARER_SWITCH_WIFI_TO_WIFI, /* Netork switch from one WLAN APP to other */
    WAP_DL_BEARER_SWITCH_PS_TO_WIFI,   /* Netork switch from cellular to WLAN network */
    WAP_DL_BEARER_SWITCH_END           /* END of enum*/
} wap_dl_nw_switch_type_enum;

/* This structure is for the local parameter of MSG_ID_WAP_MMI_FILE_DL_IND */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;   
    kal_int32   session_id;                          /* Download session id */
    kal_uint8   url[WAP_DL_MAX_URL_LEN];             /* URL of downloading object */
    kal_uint8   mime_type[WAP_DL_MAX_MIME_TYPE_LEN]; /* Mime type of downloading object */
    kal_uint8   file_name[WAP_DL_MAX_FILE_NAME_LEN]; /* Default file name */
    kal_uint32  file_length;                         /* The size of downloading object */
    kal_bool    with_content;                        /* Indicate whether this message carries downloading content */
} wap_mmi_file_dl_ind_struct;

/* This structure is for the peer buffer of MSG_ID_WAP_MMI_FILE_DL_IND */
typedef struct
{
    kal_uint32  header_len;    /* The length of header */
    kal_uint8   *header;       /* Content header sent by server */
    kal_uint32  content_len;   /* The length of content */
    kal_uint8   *content;      /* Partial content of downloading object. The maximum size is no more than (2000 bytes - header_len).*/
} wap_mmi_file_dl_var_struct;

/* This structure is for the local parameter of MSG_ID_WAP_MMI_FILE_DL_RES */
typedef struct
{
    kal_uint8   ref_count;      
    kal_uint16  msg_len;   
    kal_int32   session_id;     /* Session id of download object */
    kal_uint8   result;         /* Result */
    kal_wchar   file_path[WAP_DL_MAX_FILE_NAME_LEN + 2]; /* File path to store the downloading object */
} wap_mmi_file_dl_res_struct;

/* This structure is for the local parameter of MSG_ID_WAP_MMI_FILE_DL_PROGRESS_IND */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;   
    kal_int32   session_id;     /* Session id of download object */
    kal_uint32  seq_num;        /* Sequence number */
    kal_int32   cause;          /* error cause*/
    kal_uint32  acc_size;       /* accumulated size of downloading*/
    kal_uint8   status;         /* downloading status */
} wap_mmi_file_dl_progress_ind_struct;

/* This structure is for the local parameter of MSG_ID_WAP_MMI_FILE_DL_PROGRESS_RES */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;   
    kal_int32   session_id;     /* Session id of download object */
    kal_uint32  seq_num;        /* Sequence number */
} wap_mmi_file_dl_progress_res_struct;

/* This structure is for the local parameter of MSG_ID_WAP_MMI_FILE_DL_STOP_REQ */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;   
    kal_int32   session_id;     /* Session id of download object */
} wap_mmi_file_dl_stop_req_struct;

/* This structure is for the local parameter of MSG_ID_WAP_MMI_FILE_DL_STOP_RSP */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;   
    kal_int32	session_id;     /* Session id of download object */
    kal_uint32  seq_num;        /* Sequence number */
    kal_uint32  acc_size;       /* Accumulated size of downloading */
    kal_uint8   status;         /* downloading status */
    kal_uint8   cause;          /* error cause */
} wap_mmi_file_dl_stop_rsp_struct;

/* This structure is for the local parameter of MSG_ID_WAP_MMI_FILE_DL_CANCEL_PREFETCH_REQ */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;   
    kal_int32   session_id;     /* Session id of download object */
} wap_mmi_file_dl_cancel_prefetch_req_struct;

/* This structure is for the local parameter of MSG_ID_WAP_MMI_FILE_DL_CANCEL_PREFETCH_RSP */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;   
    kal_int32   session_id;     /* Session id of download object */
} wap_mmi_file_dl_cancel_prefetch_rsp_struct;

/* This structure is for the local parameter of MSG_ID_WAP_MMI_FILE_DL_PREFETCH_ABORTED_IND */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;   
    kal_int32   session_id;     /* Session id of download object */
    kal_int32   cause;          /* error cause */
} wap_mmi_file_dl_prefetch_aborted_ind_struct;

typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;   
    kal_bool    user_result;
    kal_int32   switch_type;   /* Switching type of network switch, refer wap_dl_nw_switch_type_enum */
} wap_mmi_file_dl_nw_switch_ind_struct;


#endif /* _DAS_STRUCT_H */
