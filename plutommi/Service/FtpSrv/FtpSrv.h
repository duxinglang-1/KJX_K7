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
 * FtpSrv.h
 *
 * Project:
 * --------
 *   MMI
 *
 * Description:
 * ------------
 *   
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __FTPSRV_H__
#define __FTPSRV_H__
// RHR: add
#include "MMI_features.h"
#include "FileMgrType.h"
#include "GlobalConstants.h"
#include "MMIDataType.h"
#include "mmi_res_range_def.h"
#include "kal_general_types.h"
// RHR: add

//#include "FileMgrGProt.h"
#include "FtpSrvGprots.h"

#if defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__)
/***************************************************************************** 
* MMI TRACE MACROS
*****************************************************************************/

#define SRV_FTPS_RECV_OBJ_FILEPATH       FMGR_DEFAULT_FOLDER_RECEIVED
#define SRV_FTPC_RECV_OBJ_FILEPATH       FMGR_DEFAULT_FOLDER_RECEIVED
#define SRV_FTP_MAX_FILE_WRITER_BUF_SIZE (1024)
#define SRV_FTP_FOLDER_PATH              (L"Z:\\@ftp\\") /* working folder */
#define SRV_FTP_MAX_CLIENT_NUM           (1)
#define SRV_FTP_MAX_SERVER_NUM           (1)
/* #define FTP_WRITER_BUF_THRESHOLD      (512) */

#define FTP_MEMSET(local_para_ptr)    do {                              \
    memset((kal_uint8*)(local_para_ptr) + sizeof(local_para_struct), 0, \
           (local_para_ptr)->msg_len - sizeof(local_para_struct));      \
} while(0)


typedef enum
{
    SRV_FTP_PRE_PKT_ERR_FS,
    SRV_FTP_PRE_PKT_ERR_USB_MASS_IN,
    SRV_FTP_PRE_PKT_ERR_NONE
} srv_ftp_pre_pkt_err_enum;


/******************************************************************************
    Structure
******************************************************************************/
/* temp buffer for file writing */
typedef struct
{
    kal_int32  fd;              /* file handle */
    kal_char   buf[SRV_FTP_MAX_FILE_WRITER_BUF_SIZE]; /* buffer */
    kal_uint32 buflen;          /* buffer len used */
    kal_uint32 written;         /* written len */
} srv_ftp_file_writer_struct;


typedef struct
{
    /* short name is only for display*/
    U16 name[MAX_SUBMENU_CHARACTERS + (SRV_FTP_FILE_EXTENTION_LEN - 3) + 1]; /* 3 means the length of "...",
                                                                              * here will use the length to save the extention name */
    /* the length of the actual name */
    U16 actual_name_len;
    U16 created_date[SRV_FTP_MAX_OBJ_CREATED_DATE_LEN / 2];
    //U16 size[SRV_FTP_MAX_OBJ_SIZE_LEN / 2];
    U32 size;
    U8  type;
    /* Indicate the start addr in file parsed_folder_lname,
     * when the file name is more than MAX_SUBMENU_SIZE */
    U32 offset;
} srv_ftp_entity_int_struct;


typedef struct
{
    S32        srv_hd;
    ftp_notify notifier;
    U32        event_mask;
    U16        connection_id;
    //U16 oper;
} srv_ftp_hdlr_struct;

typedef enum
{
    EVENT_ID_FTPS_START = FTP_BASE + 1,
    EVENT_ID_FTPS_STOP,
    EVENT_ID_FTPS_DISCONNECT_CLIENT,
    EVENT_ID_FTPC_CONNECT_SERVER,
    EVENT_ID_FTPC_DISCONNECT_SERVER,
    EVENT_ID_FTPS_END_OF_ENUM
} srv_ftp_post_event_enum;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    U16 ftp_role;
    U16 event;
    void* data_p;
} srv_ftp_post_event_struct;

/******************************************************************************
    MMI FTP FUNCTIONS
******************************************************************************/
MMI_BOOL srv_ftp_work_folder_init(void);
S32 srv_ftp_check_folder_existed(U8* absolute_path);
void srv_ftp_ucs2_cut_name_with_ext(CHAR* dest, U32  dest_size, const CHAR* src);

void srv_ftp_ucs2_cut_name_without_ext(CHAR* dest, U32  dest_size, const CHAR* src);

void srv_ftp_obj_name_swapcpy(CHAR* h_order_name, CHAR* n_order_name);
void srv_ftp_send_msg(U32 msg_id, void *p_local_para);
mmi_ret srv_ftp_post_event_proc(mmi_event_struct* para);

#ifdef __MMI_FTS_SUPPORT__
void srv_ftps_disconnect_ind_handle(void);
MMI_BOOL srv_ftps_is_valid_handle(S32 srv_hd);
void srv_ftps_notify(U16 event, void* para);
void srv_ftps_deinit(void);
#endif /* __MMI_FTS_SUPPORT__ */ 

#ifdef __MMI_FTC_SUPPORT__
void srv_ftpc_disconnect_ind_hdlr(void);
MMI_BOOL srv_ftpc_is_valid_handle(S32 srv_hd);
void srv_ftpc_notify(U16 event, void* para);
void srv_ftpc_deinit(void);
#endif /* __MMI_FTC_SUPPORT__ */

#endif /* defined(__MMI_FTS_SUPPORT__) || defined(__MMI_FTC_SUPPORT__) */ 
#endif /* __FTPSRV_H__ */
