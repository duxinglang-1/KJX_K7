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
 * BTMMIBip.h
 *
 * Project:
 * --------
 *   BT BIP MMI
 *
 * Description:
 * ------------
 *   
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __BT_MMI_BIP_H__
#define __BT_MMI_BIP_H__

#include "MMI_features.h"
#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "BtcmSrvGprot.h"
#include "bluetooth_struct.h"
#include "FileMgrSrvGProt.h"
#include "BipSrvGprot.h"
#include "kal_general_types.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifdef __BIP_PULL_SUPPORT__
/* L for wide char, @ for hidden working folder */
#define BIP_RECV_THM_PATH     (L"Z:\\@bip\\recv_thm\\") /* for recving thm  */
#define BIP_TEMP_PATH         (L"Z:\\@bip\\tmp\\")      /* for tmp file */

#define BIP_IMG_LIST_PATH_FILE         (L"Z:\\@bip\\tmp\\mmi_imglist.tmp")      /* for tmp imglist file */
#define BIP_TMP_IMG_HDLE_NAME_FILE     (L"Z:\\@bip\\tmp\\hdle_name.tmp")        /* for tmp image handle-name file */
#define BIP_TMP_IMG_UCS2_NAME_FILE     (L"Z:\\@bip\\tmp\\ucs2_name.tmp")        /* for tmp image handle-name file */
#define BIP_TMP_IMG_THM_NAME_FILE     (L"Z:\\@bip\\tmp\\thm_name.tmp")  /* for tmp thm name file */
#define BIP_CUR_IMG_LIST_PATH_FILE         (L"Z:\\@bip\\tmp\\mmi_curimglist.tmp")      /* for tmp imglist file */

/* max number of images returned in the image list */
#define BT_BIP_MAX_RETURNED_IMG_HANDLES  0X7FFF /*send get imglist_req use*/

#define MMI_BIP_MAX_FILTER_PATTERN_NUM  10
#define MMI_BIP_COMPOSE_HDLNAME_SIZE  1024
#define MMI_BIP_COMPOSE_XML_BUF_SIZE  512

/* for responder in image list */
#define BIPR_MAX_NAME_BUF_LEN      ((FMGR_MAX_FILE_LEN+1) * ENCODING_LENGTH) //128

#define BIP_PULL_I_TMP_FILENAME  (L"bip_i.tmp") /* pulled img and thm */

#define BT_BIP_MAX_BROWSE_FOLDER_LEN    60


#if (UI_DEVICE_WIDTH > 128)

#define BT_BIP_MAX_IMGHDLE_NUM  2048

#define BT_BIP_RESPONDER_MAX_IMGHDLE_NUM  (BT_BIP_MAX_IMGHDLE_NUM)

#define MMI_BIP_ONE_TIME_MAX_FIND_NUM  100

#define BT_BIP_RESPONDER_MAX_SFN_NUM  100

#else

/* customize for M8223 */
#define BT_BIP_MAX_IMGHDLE_NUM  1024

#define BT_BIP_RESPONDER_MAX_IMGHDLE_NUM  (BT_BIP_MAX_IMGHDLE_NUM)

#define MMI_BIP_ONE_TIME_MAX_FIND_NUM  50

#define BT_BIP_RESPONDER_MAX_SFN_NUM  20

#endif

#define MMI_BIP_TO_SELF_ID (L"MMI_BIP_SELF_MSG")

#define IS_BIPI_PULLING  (srv_bip_p.bipi_cntx.cur_service == BT_BIP_IMAGE_PULL)

typedef enum
{
    MMI_BIPR_FIND_START,
    MMI_BIPR_FIND_CONTINUE
}mmi_bip_find_type_enum;

typedef enum
{
    MMI_BIPR_CONSTRUCT_IMGLIST_SUCCESS,
    MMI_BIPR_CONSTRUCT_IMGLIST_FAILED,
    MMI_BIPR_CONSTRUCT_IMGLIST_CONTINUE,
    MMI_BIPR_CONSTRUCT_IMGLIST_PARTIAL_CONTENT
}mmi_bip_construct_imglist_ret_enum;


typedef struct
{
    S8 img_handle[BT_BIP_IMG_HANDLE_LEN];
    S8 found_name[BIPR_MAX_NAME_BUF_LEN];
    S16 ucs2_name_idx;
} bip_img_handle_name_struct;

typedef struct
{
    S8 ucs2_name[BIPR_MAX_NAME_BUF_LEN];
}bip_img_ucs2_name_struct;


#endif


#define SRV_BIP_MAX_CLIENT_NUM  1
#define SRV_BIP_MAX_SERVER_NUM  1
#define SRV_BIP_REPONDER_HANDLE_BEGIN   512       /* from the 513~ox7fff, it is server srv_hd */


/* tmp file name for reciever */
#define BIP_PUSH_R_TMP_FILENAME  (L"bip_r.tmp") /* pushed img and thm */


#define BIP_FOLDER_PATH       (L"Z:\\@bip\\")   /* working folder */
//#define BIP_GEN_THM_PATH     (L"Z:\\@bip\\")   /* for generating thm */

#define BIP_THM_POSTFIX  (l"_thm.jpg")

#define MMI_BIP_IMG_HANDLE_PREFIX  "8800000"


/* BIP receive file folder */
#ifndef __MMI_BT_RECV_FDR_SWITCH__
#define MMI_BIP_RECV_FOLDER    FMGR_DEFAULT_FOLDER_RECEIVED

#define MMI_BIP_GET_RECV_FOLDER(folder) \
    mmi_ucs2cpy((S8 *)(folder), (S8 *)MMI_BIP_RECV_FOLDER)

#else
#define MMI_BIP_GET_RECV_FOLDER(folder) \
    mmi_bth_get_receive_folder((U16*)(folder),\
                                NULL, NULL, \
                                MIME_TYPE_IMAGE, MIME_SUBTYPE_NONE)
#endif

/* image thumbnail pixels: */
#define BT_BIP_THM_WIDTH   160
#define BT_BIP_THM_HEIGHT  120


//#define BT_BIP_NO_TOTAL_IMAGE_SIZE  0XFFFFFFFF


/* timer duration */
#define MMI_BIP_ABORT_TIMER_DUR         (20000)
#define MMI_BIP_DISCONNECT_TIMER_DUR    (20000)



#define MMI_BIP_INVALID_REQ_ID   0xFF
#define MMI_BIP_INVALID_CONN_ID  0xFF


#define BIP_CURR_REQ_ID   1 /*(srv_bip_p.cur_req_id++)*/



#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/* disconnect type for sending disconnect request */
typedef enum
{
    SRV_BIP_OBEX_DISCONNECT,
    SRV_BIP_TP_DISCONNECT
} srv_bip_disconnect_type_enum;


/* mmi_bip_initiator_state_enum */
typedef enum
{
    SRV_BIPI_STATE_IDLE,
    SRV_BIPI_STATE_CONNECTING,
    SRV_BIPI_STATE_CONNECTED,

    SRV_BIPI_STATE_GETTING_CAPABILITIES,
    SRV_BIPI_STATE_SENDING_IMG,
    SRV_BIPI_STATE_SENDING_THM,
//#ifdef __BIP_PULL_SUPPORT__
    SRV_BIPI_STATE_GETTING_IMGLIST,
    SRV_BIPI_STATE_GETTING_IMG,
    SRV_BIPI_STATE_GETTING_THM,
    SRV_BIPI_STATE_GETTING_IMGPROP,
//#endif
    SRV_BIPI_STATE_ABORTING,
    SRV_BIPI_STATE_DISCONNECTING
} srv_bip_initiator_state_enum;

/* mmi_bip_responder_state_enum */
typedef enum
{
    SRV_BIPR_STATE_IDLE,    /* Initial state */
    SRV_BIPR_STATE_REGISTERING,
    SRV_BIPR_STATE_ACTIVE,
    SRV_BIPR_STATE_AUTHORIZING,
    SRV_BIPR_STATE_AUTHORIZED,
    SRV_BIPR_STATE_CONNECTED,

    SRV_BIPR_STATE_RECEIVING_IMG,
    SRV_BIPR_STATE_RECEIVING_THM,

    SRV_BIPR_STATE_CONSTRUCTING_IMGLIST,
    
    SRV_BIPR_STATE_SENDING_IMG, /* sending image: need start blinking timer */    
    SRV_BIPR_STATE_SENDING_LPT, /* sending imgList, Prop, Thm */

    SRV_BIPR_STATE_DISCONNECTING,
    SRV_BIPR_STATE_DEACTIVATING
} srv_bip_responder_state_enum;



typedef enum
{
    EVENT_ID_BIP_OPEN_FAIL = BIP_BASE + 1,
    EVENT_ID_BIP_SDP_REG,
    EVENT_ID_BIP_SDP_DEREG,
    EVENT_ID_BIP_MAX
}srv_bip_event_enum;

/***************************************************************************** 
* Structure
*****************************************************************************/

typedef struct
{
    MMI_EVT_PARAM_HEADER
    U32 event_id;
    U8  role;
    void *data;
}srv_bip_event_struct;

/* BIP initiator context struct */
typedef struct
{
    srv_bt_cm_bt_addr bt_device;
    srv_bip_initiator_state_enum state;
    S32 req_id;
    U32 cm_conn_id;
        
    /* current sending/receving img handle */
    S8 img_handle[BT_BIP_IMG_HANDLE_LEN];

    /* PUSH info */
    U16 img_path_snd[SRV_FMGR_PATH_MAX_LEN + 1];
    U16 img_name[BT_BIP_MAX_IMG_NAME_LEN];
    U32 img_total_size;
    U32 sent_size;
    bt_bip_img_format_enum img_type;
    
    /* PULL info */
#ifdef __BIP_PULL_SUPPORT__

    U16 img_list_path[SRV_FMGR_PATH_MAX_LEN];

    U16 img_path[SRV_FMGR_PATH_MAX_LEN];
    U16 thm_path[SRV_FMGR_PATH_MAX_LEN];

    U32 cur_img_gotten_size;
    U32 cur_img_total_size;

    U16 img_handle_num_in_imglist;

    MMI_BOOL b_user_disconnect;   /*check whether user exit bip*/
  
    /* for getting image list */
    U32 start_index;
#endif
   
} srv_bipi_cntx_struct;




/* bip_pull_responder_cntx_struct */
typedef struct
{
    srv_bip_responder_state_enum state;
    U8 req_id;
    srv_bt_cm_bt_addr bt_device;
    U32 cm_conn_id;
    U32 conn_id;

    S8 cur_img_handle[BT_BIP_IMG_HANDLE_LEN];

    /* ---- data for push ---- */

    //U16 recv_path[SRV_FMGR_PATH_MAX_LEN];
    /* push: current filename */
    U16 recv_img_name[BT_BIP_MAX_IMG_NAME_LEN];

    U32 cur_recv_img_num;
    MMI_BOOL b_request_thm;


    /* ---- the following is for pull ---- */
#ifdef __BIP_PULL_SUPPORT__

    /* info in get_img_list_rsp */
    U16 cur_img_list_path[SRV_FMGR_PATH_MAX_LEN];
    U16 cur_img_count;
    
    /* total info */
    U16 img_list_path[SRV_FMGR_PATH_MAX_LEN];
    U16 img_count;

    /* save every image's handle and name list */
    U16 img_handle_name_path[SRV_FMGR_PATH_MAX_LEN];
    U16 img_ucs2_name_path[SRV_FMGR_PATH_MAX_LEN];

    /* thumbnail path for generating thm */
    U16 thm_path[SRV_FMGR_PATH_MAX_LEN];

    /* for image list constructing */
    FS_HANDLE fs_Find;
    FS_HANDLE fs_imglist;
    FS_HANDLE fs_handle_name;
    FS_HANDLE fs_ucs2_name;

    mmi_bip_operation_type cur_cmd;  
#endif
} srv_bipr_cntx_struct;


typedef struct
{
    S32 srv_hd;
    U32 event_mask;
    bt_notify notifier;
    union
    {
        srv_bipi_cntx_struct *bipi_cntx;
        srv_bipr_cntx_struct *bipr_cntx;
    }u;
} srv_bip_handle_struct;


typedef struct
{
    srv_bip_handle_struct initiator_hd[SRV_BIP_MAX_CLIENT_NUM];
    srv_bip_handle_struct responder_hd[SRV_BIP_MAX_SERVER_NUM];
    srv_bipi_cntx_struct bipi_cntx;
    srv_bipr_cntx_struct bipr_cntx;
    U32 flag;
    U8 cur_req_id;

} srv_bip_context_struct;


/***************************************************************************** 
 *  global variable
 *****************************************************************************/
extern srv_bip_context_struct  *srv_bip_p;


/***************************************************************************** 
 * trace macro
 *****************************************************************************/

#define SRV_BIP_LOG(x)                                                             \
   {                                                                               \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x);                                           \
   }
#define SRV_BIP_LOG1(x, x1)                                                        \
   {                                                                               \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1);                                       \
   }
#define SRV_BIP_LOG2(x, x1, x2)                                                    \
   {                                                                               \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2);                                   \
   }
#define SRV_BIP_LOG3(x, x1, x2, x3)                                                \
   {                                                                               \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2, x3);                               \
   }
#define SRV_BIP_LOG4(x, x1, x2, x3, x4)                                            \
   {                                                                               \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2, x3, x4);                           \
   }
#define SRV_BIP_LOG6(x, x1, x2, x3, x4, x5, x6)                                    \
   {                                                                               \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2, x3, x4, x5, x6);                   \
   }
#define SRV_BIP_LOG7(x, x1, x2, x3, x4, x5, x6, x7)                                \
   {                                                                               \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2, x3, x4, x5, x6, x7);               \
   }

#define MMI_BIPI_STATE_TRANS(x)                                                                                                   \
{                                                                                                                                 \
    SRV_BIP_LOG2(SRV_BIP_INITOR_STATE_TRANS, srv_bip_p->bipi_cntx.state, x);\
    srv_bip_p->bipi_cntx.state = (x);                                                                                 \
}

#define MMI_BIPR_STATE_TRANS( x)                                                                                                  \
{                                                                                                                                 \
    SRV_BIP_LOG2(SRV_BIP_RESPDOR_STATE_TRANS,srv_bip_p->bipr_cntx.state, x);\
    srv_bip_p->bipr_cntx.state = (x);                                                                                 \
}

#define MMI_BIPI_LOG_STATE()                                                                                \
{                                                                                                            \
    SRV_BIP_LOG1(SRV_BIP_INITOR_STATE,srv_bip_p->bipi_cntx.state);\
}

#define MMI_BIPR_LOG_STATE()                                                                                \
{                                                                                                            \
    SRV_BIP_LOG1(SRV_BIP_RESPDOR_STATE,srv_bip_p->bipr_cntx.state);\
}


#define SRV_BIP_LOG_PATH(unicode_path)                   \
{                                                        \
    if (unicode_path != NULL)    \
    {               \
        U8 asc_path[SRV_FMGR_PATH_MAX_LEN + 1];                               \
        mmi_ucs2_to_asc((S8 *)asc_path, (S8 *)unicode_path);          \
        SRV_BIP_LOG1(SRV_BIP_PATH_LOG, asc_path);                  \
        kal_prompt_trace(MOD_MMI, "[BIP_SRV] path: %s\n", asc_path);  \
    }\
    else\
    {\
        SRV_BIP_LOG(SRV_BIP_PATH_IS_NULL);                  \
    }\
}

#endif /* __BT_MMI_BIP_H__ */ 

