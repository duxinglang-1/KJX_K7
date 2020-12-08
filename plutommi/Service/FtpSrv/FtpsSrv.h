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
 *  FtpsSrv.h
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
 * 03 02 2011 zhanying.liu
 * removed!
 * .reduce ftp buffer size for slim load
 *
 * 01 06 2011 zhanying.liu
 * removed!
 * .[Slim] systematic memory reduction code check in
 *
 * 12 16 2010 zhanying.liu
 * removed!
 * .update RHR code check in.
 *
 * 12 14 2010 zhanying.liu
 * removed!
 * .update RHR add files
 *
 * 12 14 2010 zhanying.liu
 * removed!
 * .MAUI RHR code check in
 *
 * 11 27 2010 zhanying.liu
 * removed!
 * .add srv_ftps_set_permission() in FTP service
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
#ifndef __FTPSSRV_H__
#define __FTPSSRV_H__
// RHR: add
#include "MMI_features.h"
#include "MMIDataType.h"
#include "FileMgrSrvGProt.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "BtcmSrvGprot.h"
#include "fs_type.h"
#include "bluetooth_struct.h"
#include "kal_general_types.h"
// RHR: add
#include "FtpSrv.h"

/******************************************************************************
    Enum Value
******************************************************************************/
#ifdef __MMI_FTS_SUPPORT__
#define SRV_FTPS_MAX_PARSE_FILE_INFO_NUMBER (100)
#ifndef __LOW_COST_SUPPORT_COMMON__
#define SRV_FTPS_MEM_BUFF_SIZE              (14336)
#else
#define SRV_FTPS_MEM_BUFF_SIZE              (7168)
#endif
#define SRV_FTPS_FOLDER_CONTENT_PATH_SIZE   (32) /* should > 2 * "Z:\\@ftp\\folder_content_%d" */
#define SRV_FTPS_MAX_OBJ_NAME_LEN           ((SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH)

#define SRV_FTPS_MAKE_FOLDER_CONTENT(x)                                 \
   kal_wsprintf( (kal_uint16 *)x, "Z:\\@ftp\\folder_content_%d", 0);

#define SRV_FTPS_LOG_STATE_ERR()                                        \
   {                                                                    \
       MMI_TRACE(MMI_CONN_TRC_G7_BT , SRV_FTPS_STATE_ERROR, act_server_cntx_p->ftps_state); \
   }

#define SRV_FTPS_STATE_TRANS(x)                 \
{                                               \
    SRV_FTPS_LOG_STATE(x);                      \
    act_server_cntx_p->ftps_state = (x);        \
}

#define SRV_FTPS_LOG_STATE(x)                                           \
   {                                                                    \
      MMI_TRACE(MMI_CONN_TRC_G7_BT , SRV_FTPS_STATE_TRANSITION, act_server_cntx_p->ftps_state, x); \
   }

/* FTP Server State for maintaining status and context */
typedef enum
{
    SRV_FTPS_STATE_IDLE,            /* FTPS Initial State */
    SRV_FTPS_STATE_REGISTERING,     /* Register goep and sdp */
    SRV_FTPS_STATE_ACTIVE,          /* goep and sdp is ready to service */
    SRV_FTPS_STATE_AUTHORIZING,     /* RFCOMM connection confirm state */
    SRV_FTPS_STATE_ACCEPTED,        /* Connection established state */
    SRV_FTPS_STATE_RECEIVING,       /* FTPS is receiving obj from FTPC */
    SRV_FTPS_STATE_SENDING,         /* FTPS is sending folder content or obj to FTPC */
    SRV_FTPS_STATE_DISCONNECTING,   /* FTPS is disconnecting the connection */
    SRV_FTPS_STATE_DEACTIVATING,    /* FTPS service is going to stop */
    SRV_FTPS_STATE_END_OF_ENUM
} srv_ftps_state_enum;


/******************************************************************************
    Structure
******************************************************************************/
/* object info struct is used to save the object detail information */
typedef struct
{
    U8* file_name;
    U32 file_size;
    U16 year;
    U8  month;
    U8  day;
    U8  hour;
    U8  min;
    U8  sec;
} srv_ftp_obj_info_struct;


/******************************************************************************
    MMI FTP CONTEXT
******************************************************************************/
typedef struct
{
    U8 ftps_state;                                             /* ftps state */
    U8 send_obj_type;                                          /* save the obj_type in sending */
    U16 folder_content[SRV_FTPS_FOLDER_CONTENT_PATH_SIZE];      /* should > 2 * "Z:\\@ftp\\folder_content_%d" */
    srv_ftp_file_writer_struct xml_composer;                   /* for generating folder listing object composer */
    U16 current_folder[SRV_FMGR_PATH_MAX_LEN + 1];             /* saving current folder */
    U16 ftps_obj_name[SRV_FMGR_PATH_MAX_LEN + 1];              /* saving the obj name */
    U16 ftps_browse_depth;                                     /* indicate the depth of client browsed, root: 0 */

    //U8 storage_drive;
    //U16 save_path_from_app[(SRV_FMGR_PATH_MAX_LEN+1)];
    U32 send_obex_pkt_size;                                    /* peer Max packet size */
    U32 total_send_obj_len;                                    /* total length of a object */
    U32 remain_send_obj_len;                                   /* remains length of a object */
    srv_bt_cm_bt_addr ftps_bt_device;                          /* saving bt device address */
    FS_HANDLE fh_ftps_send;                                    /* fh for sending file */
    FS_HANDLE fh_ftps_recv;                                    /* fh for receiving file */
    FS_HANDLE fh_ftps_generating;                              /* fh for generating composing obj */
    kal_uint8 ftps_obj_buff[SRV_FTPS_MEM_BUFF_SIZE];           /* ftps obj memory buffer */
#ifdef __MMI_BT_RX_ENHANCE__
    U8 ftps_inbuf_pkt_error;                                   /* MMI_TRUE: when write the pkt in internal buffer, error happens*/
    kal_uint8 ftps_obj_int_buff[SRV_FTPS_MEM_BUFF_SIZE];       /* 2 buffer design: this is internal buffer, ftpc_obj_buff is external buf*/
    U32 ftps_inbuf_len;
#endif /* __MMI_BT_RX_ENHANCE__ */
    goep_push_ind_struct *push_ind;                             /* remember the push indication message */
    S32 ftps_fmgr_job_id;
} srv_ftps_conn_cntx_struct;


typedef struct
{
    U8 goep_conn_id;                                    /* goep connection id */
    U8 access_right;                                    /* access right */
    U8 cur_goep_conn_id;                                /* save active goep_conn_id for authorizing */
    S32 conn_id;
    U32 g_conn_id;                                      /* global connection id */
    U32 ftps_flag;                                      /* bit-wise flag for FS error summary */
    srv_ftps_conn_cntx_struct conn_cntx;                /* connection cntx */
} srv_ftps_cntx_struct;


/*****************************************************************
    GLOBAL VARIABLE
*****************************************************************/
extern srv_ftps_cntx_struct *const ftps_cntx_p;
extern srv_ftps_conn_cntx_struct *act_server_cntx_p;


/******************************************************************************
    MMI FTP FUNCTIONS
******************************************************************************/
void srv_ftps_register_server_rsp_handle(void *msg);
void srv_ftps_deregister_server_rsp_handle(void *msg);
void srv_ftps_connect_ind_handle(void *msg);
void srv_ftps_push_ind_handle(void *msg);
void srv_ftps_pull_ind_handle(void *msg);
void srv_ftps_set_folder_ind_handle(void *msg);
void srv_ftps_abort_ind_handle(void *msg);
void srv_ftps_authorize_ind_handle(void *msg);
void srv_ftps_cntx_init(void);
#endif /* __MMI_FTS_SUPPORT__ */
#endif /* __FTPSSRV_H__ */
