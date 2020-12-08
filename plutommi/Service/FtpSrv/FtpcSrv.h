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

/******************************************************************************
 * 
 * Filename
 * ---------
 *  FtpcSrv.h
 * 
 * Project:
 * --------
 *  
 * 
 * Description:
 * ------------
 *  
 * 
 * Author:
 * -------
 * -------
 * 
 *=============================================================================
 *            HISTORY
 * Below this line,  this part is controlled by PVCS VM. DO NOT MODIFY!!
 *-----------------------------------------------------------------------------
 * $Log$
 *
 * 09 25 2011 zhanying.liu
 * removed!
 * .feature set reduction code check in
 *
 * 12 14 2010 zhanying.liu
 * removed!
 * .MAUI RHR code check in
 *
 * 12 10 2010 zhanying.liu
 * removed!
 * .move ftp client buffer to ftp client service
 *
 * 11 23 2010 zhanying.liu
 * removed!
 * .BT CM revise code check in
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 * 
 *-----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *=============================================================================
 ******************************************************************************/
#ifndef __FTPCSRV_H__
#define __FTPCSRV_H__
// RHR: add
#include "MMI_features.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "wgui_categories_popup.h"
#include "fs_type.h"
#include "MMIDataType.h"
#include "BtcmSrvGprot.h"
#include "FileMgrSrvGProt.h"
// RHR: add

#include "xml_def.h" /* XML_PARSER_STRUCT */
#include "FtpSrv.h"


/******************************************************************************
    Enum Value
******************************************************************************/
#ifdef __MMI_FTC_SUPPORT__
#define SRV_FTPC_MAX_PARSE_THRESHOLD           (30)
#define SRV_FTPC_FOLDER_OBJ_PATH_SIZE          (26) /* should > 2 * "Z:\\@ftp\\folder_object_%d" */
#define SRV_FTPC_MAX_FILE_COUNT_PER_WRITER_BUF (5)  /* sizeof(srv_ftp_file_writer_struct) / sizeof(srv_ftp_entity_int_struct) */

#define SRV_FTPC_MAKE_FOLDER_OBJECT(x)                          \
    kal_wsprintf((WCHAR*)x, "Z:\\@ftp\\folder_object_%d", 0);

#define SRV_FTPC_MAKE_FOLDER_PARSED(x)                  \
    kal_wsprintf((WCHAR*)x, "Z:\\@ftp\\fc.tmp_%d", 0);

#define SRV_FTPC_MAKE_FOLDER_PARSED_LONG_NAME(x)                \
    kal_wsprintf((WCHAR*)x, "Z:\\@ftp\\fc.tmp_lname_%d", 0);

#define SRV_FTPC_MAKE_FOLDER_PARSED_FILEINDEX(x)            \
    kal_wsprintf((WCHAR*)x, "Z:\\@ftp\\fc.tmp_fidx_%d", 0);


#define SRV_FTPC_LOG_STATE_ERR()                                        \
   {                                                                    \
      MMI_TRACE(MMI_CONN_TRC_G7_BT , SRV_FTPC_STATE_ERROR, act_client_cntx_p->ftpc_state); \
   }

#define SRV_FTPC_LOG_STATE(x)                                           \
   {                                                                    \
      MMI_TRACE(MMI_CONN_TRC_G7_BT , SRV_FTPC_STATE_TRANSITION, act_client_cntx_p->ftpc_state, x); \
   }

#define SRV_FTPC_STATE_TRANS(x)                 \
{                                               \
    SRV_FTPC_LOG_STATE((x));                    \
    act_client_cntx_p->ftpc_state = (x);        \
}

#define FTPC_BROWSE_FILES_FAILED_DELAY_DUR    (UI_POPUP_NOTIFYDURATION_TIME)

/* FTP Client State for maintaining status and context */
typedef enum
{
    SRV_FTPC_STATE_IDLE,                /* 0 FTPC Initial State */
    SRV_FTPC_STATE_CONNECTING,          /* 1 FTPC is connecting to FTPS */
    SRV_FTPC_STATE_CONNECTED,           /* 2 FTPC has established the connection to FTPS */
    SRV_FTPC_STATE_GETTING_FOLDER,      /* 3 FTPC is getting the folder content for browsing */
    SRV_FTPC_STATE_PARSING_FOLDER,      /* 4  FTPC is parsing the folder content */
    SRV_FTPC_STATE_GETTING_OBJ,         /* 5 FTPC is getting obj from FTPS */
    SRV_FTPC_STATE_ABORTING,            /* 6 FTPC is aborting the getting obj behavior */
    SRV_FTPC_STATE_SETTING_FOLDER,      /* 7 FTPC is setting the current folder of connected FTPS */
    SRV_FTPC_STATE_SETTING_BACK_FOLDER, /* 8 FTPC is setting the current folder of connected FTPS */
    SRV_FTPC_STATE_SETTING_ROOT_FOLDER, /* 9 FTPC is setting the current folder of connected FTPS */
    SRV_FTPC_STATE_DISCONNECTING,       /* 10 FTPC is disconnecting the connection */
    SRV_FTPC_STATE_TPDISCONNECTING,     /* 11 */
    SRV_FTPC_STATE_END_OF_ENUM
} srv_ftpc_state_enum;


typedef enum
{
    SRV_FTPC_ABORT_NONE,
    SRV_FTPC_ABORT_GETTING_FILE_FROM_SERVICE,
    SRV_FTPC_ABORT_GETTING_FILE_FROM_APP,
    SRT_FTPC_ABORT_GETTING_FOLDER_CONTENT_FROM_SERVICE,
    //SRT_FTPC_ABORT_GETTING_FOLDER_CONTENT_FROM_APP,
    //SRV_FTPC_ABORT_CONNECTION_FROM_SERVICE,
    SRV_FTPC_ABORT_CONNECTION_FROM_APP,
    SRV_FTPC_ABORT_END_OF_ENUM
} srv_ftpc_abort_enum;
    

/******************************************************************************
    MMI FTP CONTEXT
******************************************************************************/
typedef struct
{
    srv_ftp_file_writer_struct folder_content;             /* temp buffer for parsed folder content */
    XML_PARSER_STRUCT *xml_parser_p;                       /* xml parser for parsing folder content */
    srv_ftp_entity_int_struct obj_entity;                  /* temp buffer for receiving object */
    FS_HANDLE fh_ftpc_recv;                                /* fh for receiving file */
    FS_HANDLE fh_ftpc_fileindex;                           /* fh for file index in folder content */
    U32 total_recv_obj_len;                                /* total length of a object */
    U8 ftpc_obj_buff[FTPC_MEM_BUFF_SIZE];                                     /* ftpc obj memory buffer */
    U16 entity_cnt_cur_folder;                             /* entity count in current folder */
    srv_bt_cm_bt_addr ftpc_bt_device;                      /* saving bt device address */
    U16 folder_obj[SRV_FTPC_FOLDER_OBJ_PATH_SIZE];          /* should > 2 * "Z:\\@ftp\\folder_object_%d" */
    U16 parsed_folder[SRV_FTPC_FOLDER_OBJ_PATH_SIZE];       /* should > 2 * "Z:\\@ftp\\fc.tmp_%d" */
    U16 parsed_folder_lname[SRV_FTPC_FOLDER_OBJ_PATH_SIZE]; /* Sub file of parsed file, saving long file name, should > 2 * "Z:\\@ftp\\fc.tmp_lname_%d" */
    U16 parsed_folder_fileindex[SRV_FTPC_FOLDER_OBJ_PATH_SIZE];
    U16 fileindex_in_folder[SRV_FTPC_MAX_FILE_COUNT_PER_WRITER_BUF + 1];
    U8 parsed_folder_item_cnt;                             /* saving the temp count of parsed folder item */
    U32 recved_obj_len;                                    /* only save received length of a file, not folder-content file */
    U16 file_cnt_cur_folder;                               /* files count in current folder */
    S32 client_write_file_error;
    U8 ftpc_state;                                         /* ftpc state */
    U8 flag_abort_req_sent;                                /* have send abort_req*/
    U8 abort_type;                                         /* reference srv_ftpc_abort_enum */
    //U8 storage_drive;                                    /* storage drive */
    U16 actual_name[SRV_FMGR_PATH_MAX_LEN + 1];            /* when pull a file, storage the actual name */
#ifdef __MMI_BT_RX_ENHANCE__
    U8 inbuf_pkt_error;                                    /* MMI_TRUE: when write the pkt in internal buffer, error happens*/
    U8 ftpc_obj_int_buff[FTPC_MEM_BUFF_SIZE];              /* 2 buffer design: this is internal buffer, ftpc_obj_buff is external buf*/
    U32 inbuf_len;
#endif /* __MMI_BT_RX_ENHANCE__ */
} srv_ftpc_conn_cntx_struct;


typedef struct
{
    S32 conn_id;
    U8 goep_conn_id;    /* goep connection id */
    //U8 req_id;          /* req from CM id */
    U32 g_conn_id;      /* global connection id */
    srv_ftpc_conn_cntx_struct conn_cntx;          /* connection cntx */
    //U32 ftpc_flag;                              /* bit-wise flag for FS error summary */
} srv_ftpc_cntx_struct;

/*****************************************************************
    GLOBAL VARIABLE
*****************************************************************/
extern srv_ftpc_cntx_struct *const ftpc_cntx_p;
extern srv_ftpc_conn_cntx_struct *act_client_cntx_p;

/***************************************************************************** 
* MMI TRACE MACROS
*****************************************************************************/

/******************************************************************************
    MMI FTP FUNCTIONS
******************************************************************************/
void srv_ftpc_abort_rsp_handle(void *msg);
void srv_ftpc_set_folder_rsp_handle(void *msg);
void srv_ftpc_pull_rsp_handle(void *msg);
void srv_ftpc_connect_rsp_handle(void *msg);
void srv_ftpc_cntx_init(void);
void srv_ftpc_connection_terminated(void);
#endif /* __MMI_FTC_SUPPORT__ */
#endif /* __FTPCSRV_H__ */
