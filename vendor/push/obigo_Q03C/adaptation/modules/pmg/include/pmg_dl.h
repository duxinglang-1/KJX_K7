/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   pmg_dl.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains PMG function prototypes, constant/macro/structure definition 
 *   for Push Inbox AP handling
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _pmg_dl_h
#define _pmg_dl_h

#include "pmg_main.h"
//suggested add
    #include "msf_def.h"
  #include "kal_general_types.h"


/* Maximum URL length in byte */
#define WPS_DL_MAX_URL_LEN          (512)  
/* Maximum MIME type in byte */
#define WPS_DL_MAX_MIME_TYPE_LEN    (512)  
/* Maximum file name in byte */
#define WPS_DL_MAX_FILE_NAME_LEN    (256)  

int pmg_dl_handle_content_data_route(MSF_UINT8 src_modId, void *p);

void pmg_set_browser_destroy_flag (MSF_BOOL destroy);

pmg_job_t *pmg_find_job_by_pipe_handle(int pipe_handle);

int pmg_read_push_pipe_data(pmg_job_t *job);

void pmg_delete_job(pmg_job_t *job);

void pmg_abort_download(pmg_job_t *job, int cause);

typedef enum
{
    //PMG_ERR_SUCCESS,
    PMG_ERR_CREATE_FILE_FAILED,
    PMG_ERR_SAVE_FULL,
    PMG_ERR_SAVE_SIZE,
    //PMG_ERR_DOWNLOAD_FAILED,
    PMG_ERR_CONNECTION_ABORT
    //PMG_ERR_USER_CANCELLED
} pmg_error_enum;

/* This enum is used to indicate the result and error code of a response from MMI. */
typedef enum
{
    WPS_DL_ERROR_OK                       /* Success */
} wps_dl_error_enum;

typedef enum
{
    //PMG_STATUS_IDLE,
    PMG_STATUS_STARTED,
    PMG_STATUS_DOWNLOADING,
    //PMG_STATUS_ABORTED,
    //PMG_STATUS_WAITING,
    PMG_STATUS_COMPLETE,
    PMG_STATUS_PREFETCHING,
    PMG_STATUS_PREFETCHING_COMPLETED
} pmg_status_enum;

/* This structure is for the local parameter of MSG_ID_WPS_MMI_FILE_DL_IND */
typedef struct
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;   
    kal_int32   session_id;                          /* Download session id */
    kal_uint8   url[WPS_DL_MAX_URL_LEN];             /* URL of downloading object */
    kal_uint8   mime_type[WPS_DL_MAX_MIME_TYPE_LEN]; /* Mime type of downloading object */
    kal_uint8   file_name[WPS_DL_MAX_FILE_NAME_LEN]; /* Default file name */
    kal_uint32  file_length;                         /* The size of downloading object */
    kal_bool    with_content;                        /* Indicate whether this message carries downloading content */
} wps_mmi_file_dl_ind_struct;

/* This structure is for the peer buffer of MSG_ID_WPS_MMI_FILE_DL_IND */
typedef struct
{
    kal_uint32  header_len;    /* The length of header */
    kal_uint8   *header;       /* Content header sent by server */
    kal_uint32  content_len;   /* The length of content */
    kal_uint8   *content;      /* Partial content of downloading object. The maximum size is no more than (2000 bytes - header_len).*/
} wps_mmi_file_dl_var_struct;

#endif /* _pmg_dl_h */
