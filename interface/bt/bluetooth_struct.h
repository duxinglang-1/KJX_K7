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
 *   bluetooth_struct.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is defines SAP for MTK Bluetooth.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __BLUETOOTH_STRUCT_H_
#define __BLUETOOTH_STRUCT_H_

#include "kal_general_types.h"
#include "uart_sw.h"
#include "app_ltlcom.h"
#include "dcl.h"
#include "btdrv_struct.h"  //move 2 struct to btdrv_struct.h for HAL rule2

#ifdef __BT_DIALER_SUPPORT__
#include "bt_hfadp_struct.h"
#endif /* __BT_DIALER_SUPPORT__ */

#define HFG_SEQUENCE_NUM_LENGHT 16
#define BT_MAX_VERSION_STR_SIZE 20

/* SPP definitions */
#define SPP_MAX_SERVICE_NAME_LENGTH 14
#define BT_SPP_MAX_DEV_NAME_LEN     80 

/* MSG_ID_BT_SPP_ACTIVATE_REQ */
typedef struct  
{       
	kal_uint8 ref_count;
	kal_uint16 msg_len;			
	kal_char svcName[SPP_MAX_SERVICE_NAME_LENGTH];
	kal_uint16 svcUUID;   /* Vonder UUID */
	module_type owner;    /* Owner of spp port */
	kal_uint8 secLevel;   /* User set security level */	
	kal_uint32 req_id;
}bt_spp_activate_req_struct;

/* MSG_ID_BT_SPP_ACTIVATE_CNF */
typedef struct  
{       
	kal_uint8 ref_count;
	kal_uint16 msg_len;			
    DCL_DEV port;         /* virtual port number */
	kal_uint16 uuid;      
    kal_uint8 result;
	kal_uint32 req_id;
}bt_spp_activate_cnf_struct;

/* MSG_ID_BT_SPP_DEACTIVATE_REQ */
typedef struct  
{       
	kal_uint8 ref_count;
	kal_uint16 msg_len;			
    DCL_DEV port;         /* virtual port number */	
}bt_spp_deactivate_req_struct;

/* MSG_ID_BT_SPP_DEACTIVATE_CNF */
typedef struct  
{       
	kal_uint8 ref_count;
	kal_uint16 msg_len;			
    DCL_DEV port;         /* virtual port number */
    kal_uint8 result;
}bt_spp_deactivate_cnf_struct;

/* MSG_ID_BT_SPP_CONNECT_REQ */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
	kal_uint8* txBufPtr;  /* User set tx/rx buffer */
	kal_uint8* rxBufPtr;
	kal_uint32 txBufSize; /* User set tx/rx buffer size */
	kal_uint32 rxBufSize;
	kal_uint8 server_chnl_num;
	kal_uint16 uuid;
	kal_uint32 req_id;  
	kal_uint8 sec_level;
} bt_spp_connect_req_struct;

/* MSG_ID_BT_SPP_SEND_DATA_REQ */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
} bt_spp_send_data_req_struct;

/* MSG_ID_BT_SPP_GET_DATA_REQ */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
} bt_spp_get_data_req_struct;

/* MSG_ID_BT_SPP_CONNECT_IND */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
    kal_uint8 cid;  /* connection id */
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
} bt_spp_connect_ind_struct;

/* MSG_ID_BT_SPP_DISCONNECT_REQ */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
} bt_spp_disconnect_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
} bt_spp_audio_connect_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
} bt_spp_audio_disconnect_req_struct;

/* MSG_ID_BT_SPP_DISCONNECT_IND */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
} bt_spp_disconnect_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
    kal_uint8 result;
} bt_spp_audio_connect_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
} bt_spp_audio_connect_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
    kal_uint8 result;
} bt_spp_audio_disconnect_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
} bt_spp_audio_disconnect_ind_struct;

/* MSG_ID_BT_SPP_DISCONNECT_CNF */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port;     /* virtual port number */
    kal_uint8 cid;      /* connection id */
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
    kal_uint8 result;   /* This is result field of this returned cnf msg */
} bt_spp_disconnect_cnf_struct;

/* MSG_ID_BT_SPP_AUTH_REQ */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
    kal_uint8 dev_name[BT_SPP_MAX_DEV_NAME_LEN];
} bt_spp_auth_req_struct;

/* MSG_ID_BT_SPP_CONNECT_IND_REQ */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
	kal_uint8 dev_name[BT_SPP_MAX_DEV_NAME_LEN];
} bt_spp_connect_ind_req_struct;

/* MSG_ID_BT_SPP_CONNECT_IND_RES */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
	kal_uint8 *txBufPtr;  /* User set tx/rx buffer */
	kal_uint8 *rxBufPtr;
	kal_uint32 txBufSize; /* User set tx/rx buffer size */
	kal_uint32 rxBufSize;
    kal_uint8 result;
} bt_spp_connect_ind_res_struct;

/* MSG_ID_BT_DUN_CONNECT_IND_REQ */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
	kal_uint8 dev_name[BT_SPP_MAX_DEV_NAME_LEN];
} bt_dun_connect_ind_req_struct;

/* MSG_ID_BT_DUN_CONNECT_IND_RES */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
	kal_uint8 *txBufPtr;  /* User set tx/rx buffer */
	kal_uint8 *rxBufPtr;
	kal_uint32 txBufSize; /* User set tx/rx buffer size */
	kal_uint32 rxBufSize;
    kal_uint8 result;
} bt_dun_connect_ind_res_struct;

/* MSG_ID_BT_DUN_DISCONNECT_CNF */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port;     /* virtual port number */
    kal_uint8 cid;      /* connection id */
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
    kal_uint8 result;   /* This is result field of this returned cnf msg */
} bt_dun_disconnect_cnf_struct;

/* MSG_ID_BT_FAX_CONNECT_IND_REQ */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
	kal_uint8 dev_name[BT_SPP_MAX_DEV_NAME_LEN];
} bt_fax_connect_ind_req_struct;

/* MSG_ID_BT_FAX_CONNECT_IND_RES */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
	kal_uint8 *txBufPtr;  /* User set tx/rx buffer */
	kal_uint8 *rxBufPtr;
	kal_uint32 txBufSize; /* User set tx/rx buffer size */
	kal_uint32 rxBufSize;
    kal_uint8 result;
} bt_fax_connect_ind_res_struct;

/* MSG_ID_BT_SPP_CONNECT_CNF */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port;             /* virtual port number */
    kal_uint8 cid;              /* connection id */
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
	kal_uint32 req_id;
    kal_uint8 result;           /* This is result field of this returned cnf msg */
    kal_uint8 server_chnl_num; 
} bt_spp_connect_cnf_struct;

/* MSG_ID_BT_SPP_AUTH_RSP */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port;     /* virtual port number */
	kal_uint8 *txBufPtr;  /* User set tx/rx buffer */
	kal_uint8 *rxBufPtr;
	kal_uint32 txBufSize; /* User set tx/rx buffer size */
	kal_uint32 rxBufSize;
    kal_bool result;    /* TRUE: accepted by MMI */
} bt_spp_auth_rsp_struct;

/* MSG_ID_BT_SPP_UART_OWNER_IND */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port;
} bt_spp_uart_owner_ind_struct;

/* MSG_ID_BT_SPP_UART_OWNER_CNF */

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port;
} bt_spp_uart_owner_cnf_struct;

/* MSG_ID_BT_SPP_UART_PLUGOUT_CNF */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port;
} bt_spp_uart_plugout_cnf_struct;

/* MSG_ID_BT_SPP_SCO_RSSI_IND */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 bd_address[6];
    kal_uint8 rssi_value;
} bt_spp_sco_rssi_ind_struct;

/* MSG_ID_BT_DUN_CONNECT_REQ */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
	kal_uint8 *txBufPtr;  /* User set tx/rx buffer */
	kal_uint8 *rxBufPtr;
	kal_uint32 txBufSize; /* User set tx/rx buffer size */
	kal_uint32 rxBufSize;
    kal_uint8 server_chnl_num;
} bt_dun_connect_req_struct;

/* MSG_ID_BT_DUN_CONNECT_IND */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
    kal_uint8 cid;  /* connection id */
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
} bt_dun_connect_ind_struct;

/* MSG_ID_BT_DUN_DISCONNECT_REQ */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
} bt_dun_disconnect_req_struct;

/* MSG_ID_BT_DUN_DISCONNECT_IND */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
} bt_dun_disconnect_ind_struct;

/* MSG_ID_BT_DUN_AUTH_RSP : add 2007-01-12 */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port;     /* virtual port number */
	kal_uint8 *txBufPtr;  /* User set tx/rx buffer */
	kal_uint8 *rxBufPtr;
	kal_uint32 txBufSize; /* User set tx/rx buffer size */
	kal_uint32 rxBufSize;
    kal_bool result;    /* TRUE: accepted by MMI */
} bt_dun_auth_rsp_struct;

/* MSG_ID_BT_DUN_CONNECT_CNF */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port;             /* virtual port number */
    kal_uint8 cid;              /* connection id */
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
    kal_uint8 result;           /* This is result field of this returned cnf msg */
    kal_uint8 server_chnl_num;  
} bt_dun_connect_cnf_struct;

/* MSG_ID_BT_FAX_CONNECT_IND */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
    kal_uint8 cid;  /* connection id */
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
} bt_fax_connect_ind_struct;

/* MSG_ID_BT_FAX_DISCONNECT_REQ */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
} bt_fax_disconnect_req_struct;

/* MSG_ID_BT_FAX_DISCONNECT_IND */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
} bt_fax_disconnect_ind_struct;

/* MSG_ID_BT_FAX_AUTH_RSP : add 2007-01-12 */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port;     /* virtual port number */
	kal_uint8* txBufPtr;  /* User set tx/rx buffer */
	kal_uint8* rxBufPtr;
	kal_uint32 txBufSize; /* User set tx/rx buffer size */
	kal_uint32 rxBufSize;
    kal_bool result;    /* TRUE: accepted by MMI */
} bt_fax_auth_rsp_struct;

/* MSG_ID_BT_SPP_CONNECT_IND */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    DCL_DEV port; /* virtual port number */
	kal_uint8    seq1[HFG_SEQUENCE_NUM_LENGHT];
	kal_uint8    seq2[HFG_SEQUENCE_NUM_LENGHT];
	
} bt_hf_connect_ind_struct;

/* MSG_ID_BT_HFG_SEND_DATA_REQ */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool more_data;
    DCL_DEV port; /* virtual port number */
} bt_hf_send_data_req_struct;

/* MSG_ID_BT_POWERON_CNF */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;    /* TRUE: successful, FALSE: failed */
} bt_poweron_cnf_struct;

/* MSG_ID_BT_DETECT_CHIP_CNF */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;    /* TRUE: bt chip exist, FALSE: bt chip absent */
} bt_detect_chip_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;    /* TRUE: successful, FALSE: failed */
} bt_engineer_mode_poweron_cnf_struct;

/* MSG_ID_BT_POWEROFF_CNF */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;    /* TRUE: successful, FALSE: failed */
} bt_poweroff_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_bool afh;    /* True: send AFH command */
    kal_uint32 freq;
/* #if defined (WIFI_BB_MT5921) */
    kal_uint8 hb;
/* #endif */
    kal_bool pta;    /* True: send PTA command */
    kal_uint8 pta_action;
} bt_wifi_set_chnl_req_struct;

/* MSG_ID_BT_MMI_RESET_CNF */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;    /* TRUE: successful, FALSE: failed */
} bt_mmi_reset_cnf_struct;

/* MSG_ID_BT_TEST_MODE_REQ */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 mode;                     /* 1: enter test mode, 2: leave test mode */
#ifdef __GEMINI__
    kal_uint8 dual_sim_uart_setting;    /* 0: L4C_UART_TO_SIM1, 1: L4C_UART_UART_TO_SIM2 */
#endif 
} bt_test_mode_req_struct;

/* MSG_ID_BT_SSP_DEBUG_MODE_REQ */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 on;                     /* 0: debug mode off, 1: debug mode on */
} bt_ssp_debug_mode_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;    /* TRUE: successful, FALSE: failed */
} bt_ssp_debug_mode_cnf_struct;

//move to interface\hal\bluetooth\public\btdrv_struct.h
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
} bt_set_bd_addr_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 index;
    kal_uint8 external_pa;
    kal_uint8 internal_pa;
    kal_uint16 output_power;
} bt_set_power_table_req_struct;

//move to interface\hal\bluetooth\public\btdrv_struct.h
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
} bt_pcm_lb_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;    /* TRUE: successful, FALSE: failed */
    char chip_version[BT_MAX_VERSION_STR_SIZE];  /* ASCII */
    char lmp_version[BT_MAX_VERSION_STR_SIZE];   /* ASCII */
    char patch_version[BT_MAX_VERSION_STR_SIZE]; /* ASCII */
} bt_get_bt_version_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
} bt_l4c_at_general_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
} bt_engineer_mode_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 pattern;
    kal_uint8 channel_hopping;
    kal_uint8 tx_freq;
    kal_uint8 rx_freq;
    kal_uint8 poll_period;
    kal_uint8 packet_type;
    kal_uint16 packet_length;
    kal_uint8 bt_addr[6]; /*For NSR test ext, LCH 20110808*/
} bt_engineer_mode_txrx_test_req_struct;

/*For NSR test result return to MMI, LCH 20110808*/
typedef struct
{
    kal_uint8  ref_count;    
    kal_bool   result;
    kal_uint16 msg_len;
    kal_uint32 nsr_packet_count; /*NSR receive total packet*/ 
    kal_uint32 nsr_per;          /*NSR packet error rate:nsr_per%*/
    kal_uint32 nsr_byte_count;   /*NSR receive total bytes*/ 
    kal_uint32 nsr_ber;          /*NSR bit error rate:nsr_per%*/
} bt_engineer_mode_nsr_result_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
} bt_engineer_mode_txrx_test_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 level;
} bt_engineer_mode_power_test_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
} bt_engineer_mode_txrx_power_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 addr[12];
} bt_engineer_mode_device_test_req_struct;

#ifdef __GEMINI__
/* MSG_ID_BT_ENGINEER_MODE_POWERON_REQ */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 dual_sim_uart_setting;
} bt_engineer_mode_poweron_req_struct;
#endif /* __GEMINI__ */ 

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
#ifdef __GEMINI__
    kal_uint8 dual_sim_uart_setting;    /* 0: L4C_UART_TO_SIM1, 1: L4C_UART_UART_TO_SIM2 */
#endif 
} bt_read_bd_addr_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
    kal_uint8 bd_addr[6];
} bt_read_bd_addr_cnf_struct;

/* MSG_ID_BT_TEST_CMD_REQ */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 test_cmd_content[256];
} bt_test_cmd_req_struct;

/* MSG_ID_BT_L4C_TEST_CMD_CNF */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 test_cmd_rsp_buf[256];
    kal_uint16 length;
} bt_test_cmd_rsp_struct;

/* MSG_ID_BT_READ_RSSI_REQ */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 lap;
    kal_uint8  uap;
    kal_uint16 nap;
}bt_read_rssi_req_struct;

/* MSG_ID_BT_READ_RSSI_CNF */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;
    kal_int8 rssi_value;
    kal_uint32 lap;
    kal_uint8  uap;
    kal_uint16 nap;
}bt_read_rssi_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 value;
}bt_set_sco_accept_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 value;
}bt_set_sco_accept_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 value;
}bt_set_dual_pcm_setting_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 value;
}bt_set_dual_pcm_switch_req_struct;

#ifdef __GEMINI__
typedef struct
{
    kal_uint8  ref_count;
    kal_uint16 msg_len;
    kal_uint8  active_uart;
} bt_active_uart_change_req_struct;
#endif


/* BPP definitions */
#define OBRC_SCO_REJECT 0xFF    /* SCO REJECT */

/* BIP definitions */
#define BT_BIP_MAX_PATH_LEN     260
#define BT_BIP_MAX_IMG_FORMATS  10
#define BT_BIP_MAX_IMG_NAME_LEN  GOEP_MAX_OBJ_NAME      /* 256 */
#define BT_BIP_MAX_TIME_LEN     18  /* (YYYYMMDDTHHMMSS)(Z) */
#define BT_BIP_IMG_HANDLE_LEN   8
#define BT_BIP_MAX_DEV_NAME_LEN 80
#define BT_BIP_MAX_ATTR_NAME_LEN 40
#define BT_BIP_MAX_IMG_LIST_ITEMS 32
#define BT_BIP_ENCODING_LENGTH 2

#ifdef __BT_BPP_PROFILE__
#define BPP_MAX_TMP_FILE_NAME 130
#define BPP_INLINE_INSTRUCT_PREFIX_LEN 8
#define BPP_INVALID_PRINTER_HANDLE  (-1)
#define BPP_XHTML_MULTI_DOC_CHK_SIZE  2048
#define BPP_XHTML_SPECIAL_CHAR_NUM 8
#define BPP_PRINTER_ERROR_CODE_MAX 12
#endif /* __BT_BPP_PROFILE__ */ 
/* GOEP definitions */
#define GOEP_MAX_UUID_SIZE 16
#define GOEP_MAX_PASSWD_SIZE 16
#define GOEP_MAX_REALM_SIZE 20
#define GOEP_MAX_USERID_SIZE 20
#define GOEP_MAX_OBJ_NAME (256 * 2)
#define GOEP_MAX_FOLDER_NAME (256 * 2)
#define GOEP_MAX_DEV_NAME 80
#define GOEP_MAX_DESCRIPTION 80
#define GOEP_MAX_MIME_TYPE 80
#define GOEP_MAX_SERVER_NUM 16
#define GOEP_MAX_CLIENT_NUM 16
#define GOEP_CONNECTION_NUM (GOEP_MAX_SERVER_NUM + GOEP_MAX_CLIENT_NUM)

/* The function call was successful. */
#define GOEP_STATUS_SUCCESS          0
/* The operation has failed to start. */
#define GOEP_STATUS_FAILED           1
/* The operation is pending to wait for authentication information */
#define GOEP_STATUS_PENDING          2
/* The transport layer link is disconnected. */
#define GOEP_STATUS_DISCONNECT       3
/* No connection exists, when one is required */
#define GOEP_STATUS_NO_CONNECT       4
/* A request is pending or resources are in use. */
#define GOEP_STATUS_BUSY             11
/* The necessary resources are not available. */
#define GOEP_STATUS_NO_RESOURCES     12
/* An invalid function parameter was provided. */
#define GOEP_STATUS_INVALID_PARM     18
/*
 * Bluetooth Only: The request failed because the specified device
 * is in the process of being disconnected.
 */
#define GOEP_STATUS_IN_PROGRESS      19
/* Feature not supported */
#define GOEP_STATUS_NOT_SUPPORTED    23
/*
 * Bluetooth Only : Feature is restricted, due to a 
 * Bluetooth security failure 
 */
#define GOEP_STATUS_RESTRICTED       20
/* The OBEX packet is too small to support the request. */
#define GOEP_STATUS_PACKET_TOO_SMALL 31
/* No active session exists, when one is required. */
#define GOEP_STATUS_NO_SESSION       32

/* SCO_REJECT */
#define GOEP_STATUS_SCO_REJECT       25

#define GOEP_CREATED              0x21  /* Created */
#define GOEP_ACCEPTED             0x22  /* Accepted */
#define GOEP_NON_AUTHOR_INFO      0x23  /* Non-Authoritative Information */
#define GOEP_NO_CONTENT           0x24  /* No Content */
#define GOEP_RESET_CONTENT        0x25  /* Reset Content */
#define GOEP_PARTIAL_CONTENT      0x26  /* Partial Content */

#define GOEP_MULTIPLE_CHOICES     0x30  /* Multiple Choices */
#define GOEP_MOVED_PERMANENT      0x31  /* Moved Permanently */
#define GOEP_MOVED_TEMPORARY      0x32  /* Moved Temporarily */
#define GOEP_SEE_OTHER            0x33  /* See Other */
#define GOEP_NOT_MODIFIED         0x34  /* Not Modified */
#define GOEP_USE_PROXY            0x35  /* Use Proxy */

#define GOEP_BAD_REQUEST          0x40  /* Bad Request */
#define GOEP_UNAUTHORIZED         0x41  /* Unauthorized */
#define GOEP_PAYMENT_REQUIRED     0x42  /* Payment Required */
#define GOEP_FORBIDDEN            0x43  /* Forbidden - operation is understood but refused */                                           
#define GOEP_NOT_FOUND            0x44  /* Not Found */
#define GOEP_METHOD_NOT_ALLOWED   0x45  /* Method Not Allowed */
#define GOEP_NOT_ACCEPTABLE       0x46  /* Not Acceptable */
#define GOEP_PROXY_AUTHEN_REQ     0x47  /* Proxy Authentication Required */
#define GOEP_REQUEST_TIME_OUT     0x48  /* Request Timed Out */
#define GOEP_CONFLICT             0x49  /* Conflict */

#define GOEP_GONE                 0x4a  /* Gone */
#define GOEP_LENGTH_REQUIRED      0x4b  /* Length Required */
#define GOEP_PRECONDITION_FAILED  0x4c  /* Precondition Failed */
#define GOEP_REQ_ENTITY_TOO_LARGE 0x4d  /* Requested entity is too large */
#define GOEP_REQ_URL_TOO_LARGE    0x4e  /* Requested URL is too large */
#define GOEP_UNSUPPORT_MEDIA_TYPE 0x4f  /* Unsupported Media Type */

#define GOEP_INTERNAL_SERVER_ERR  0x50  /* Internal Server Error */
#define GOEP_NOT_IMPLEMENTED      0x51  /* Not Implemented */
#define GOEP_BAD_GATEWAY          0x52  /* Bad Gateway */
#define GOEP_SERVICE_UNAVAILABLE  0x53  /* Service Unavailable */
#define GOEP_GATEWAY_TIMEOUT      0x54  /* Gateway Timeout */
#define GOEP_HTTP_VER_NO_SUPPORT  0x55  /* HTTP version not supported */

#define GOEP_DATABASE_FULL        0x60  /* Database Full */
#define GOEP_DATABASE_LOCKED      0x61  /* Database Locked */

/* End of GOEPStatus */

/* GOEP ENUM */
typedef enum
{
    GOEP_TP_BT = 0,
    GOEP_TP_IRDA
} goep_tp_type_enum;

typedef enum
{
    GOEP_FIRST_PKT = 0,
    GOEP_NORMAL_PKT,
    GOEP_FINAL_PKT,
    GOEP_SINGLE_PKT
} goep_pkt_type_enum;

typedef enum
{
    GOEP_FORWARD_FOLDER = 0,
    GOEP_BACK_FOLDER,
    GOEP_ROOT_FOLDER,
    GOEP_CREATE_FOLDER
} goep_set_folder_type_enum;

typedef enum
{
    GOEP_PUT_NORMAL = 0,
    GOEP_PUT_DELETE,
    GOEP_CREATEEMPTY
} goep_put_type_enum;

typedef enum
{
    GOEP_SERVER_ROLE = 0,
    GOEP_CLIENT_ROLE
} goep_role_enum;

#ifdef __BT_BPP_PROFILE__
typedef enum
{
    BPP_IMAGE_JPEG_TYPE,
    BPP_IMAGE_GIF_TYPE,
    BPP_IMAGE_BMP_TYPE,
    BPP_IMAGE_WBMP_TYPE,
    BPP_IMAGE_PNG_TYPE,
    BPP_IMAGE_SVG_TYPE,
    BPP_IMAGE_TYPE_MAX_ENUM
} bpp_image_type_enum;

typedef enum
{
    BPP_PRINTER_STATE_IDLE,
    BPP_PRINTER_STATE_PROCESSING,
    BPP_PRINTER_STATE_STOPPED
} bpp_printer_state_enum;

typedef enum
{
    BPP_JOB_STATE_PRINTING,
    BPP_JOB_STATE_WAITING,
    BPP_JOB_STATE_STOPPED,
    BPP_JOB_STATE_COMPLETED,
    BPP_JOB_STATE_ABORTED,
    BPP_JOB_STATE_CANCELED,
    BPP_JOB_STATE_UNKNOWN
} bpp_job_state_enum;

typedef enum
{
    BPP_DOCUMENT_FORMAT_XHTML_095,
    BPP_DOCUMENT_FORMAT_XHTML_100,
    BPP_DOCUMENT_FORMAT_XHTML_MULTI,
    BPP_DOCUMENT_FORMAT_MAX_ENUM
} bpp_docu_format_enum;

typedef enum
{
    ONE_SIDED,
    TWO_SIDED_LONG_EDGE,
    TWO_SIDED_SHORT_EDGE,
    BPP_SIDED_MAX_ENUM
} bpp_sided_enum;

typedef enum
{
    PORTRAIT,
    LANDSCAPE,
    REVERSE_PORTRAIT,
    REVERSE_LANDSCAPE,
    BPP_ORIENTATION_MAX_ENUM
} bpp_orientation_enum;

typedef enum
{
    QUALITY_DRAFT,
    QUALITY_NORMAL,
    QUALITY_HIGHT,
    BPP_QUALITY_MAX_ENUM
} bpp_print_quality_enum;

typedef enum
{
    ONE_PAGE_PEER_SHEET = 1,
    TWO_PAGE_PEER_SHEET = 2,
    FOUR_PAGE_PEER_SHEET = 4,
    BPP_NUMBERUP_MAX_ENUM
} bpp_numberup_enum;

typedef enum
{
    BPP_ATTR_PRINTERNAME,
    BPP_ATTR_PRINTERLOCATION,
    BPP_ATTR_PRINTERSTATE,
    BPP_ATTR_PRINTERSTATEREASONS,
    BPP_ATTR_PRINTERGENERALCURRENTOPERATOR,
    BPP_ATTR_DOCUMENTFORMATSSUPPORTED,
    BPP_ATTR_IMAGEFORMATSSUPPORTED,
    BPP_ATTR_COLORSUPPORTED,
    BPP_ATTR_MAXCOPIESSUPPORTED,
    BPP_ATTR_SIDESSUPPORTED,
    BPP_ATTR_NUMBERUPSUPPORTED,
    BPP_ATTR_ORIENTATIONSSUPPORTED,
    BPP_ATTR_MEDIASIZESSUPPORTED,
    BPP_ATTR_MEDIATYPESSUPPORTED,
    BPP_ATTR_MEDIALOADED,
    BPP_ATTR_PRINTQUALITYSUPPORTED,
    BPP_ATTR_QUEUEDJOBCOUNT,
    BPP_ATTR_OPERATIONSTATUS,
    BPP_ATTR_MAX_ATTRIBUTE
} bpp_attribute_enum;

typedef enum
{
    MEDIA_TYPE_STATIONERY,
    MEDIA_TYPE_STATIONERY_COATED,
    MEDIA_TYPE_STATIONERY_INKJET,
    MEDIA_TYPE_STATIONERY_PREPRINTED,
    MEDIA_TYPE_STATIONERY_LETTERHEAD,
    MEDIA_TYPE_STATIONERY_PREPUNCHED,
    MEDIA_TYPE_STATIONERY_FINE,
    MEDIA_TYPE_STATIONERY_HEAVYWEIGHT,
    MEDIA_TYPE_STATIONERY_LIGHTWEIGHT,
    MEDIA_TYPE_TRANSPARENCY,
    MEDIA_TYPE_ENVELOPE,
    MEDIA_TYPE_ENVELOPE_PLAIN,
    MEDIA_TYPE_ENVELOPE_WINDOW,
    MEDIA_TYPE_CONTINUOUS,
    MEDIA_TYPE_CONTINUOUS_LONG,
    MEDIA_TYPE_CONTINUOUS_SHORT,
    MEDIA_TYPE_TAB_STOCK,
    MEDIA_TYPE_PRE_CUT_TABS,
    MEDIA_TYPE_FULL_CUT_TABS,
    MEDIA_TYPE_MULTI_PART_FORM,
    MEDIA_TYPE_LABELS,
    MEDIA_TYPE_MULTI_LAYER,
    MEDIA_TYPE_SCREEN,
    MEDIA_TYPE_SCREEN_PAGED,
    MEDIA_TYPE_PHOTOGRAPHIC,
    MEDIA_TYPE_PHOTOGRAPHIC_GLOSSY,
    MEDIA_TYPE_PHOTOGRAPHIC_HIGH_GLOSS,
    MEDIA_TYPE_PHOTOGRAPHIC_SEMI_GLOSS,
    MEDIA_TYPE_PHOTOGRAPHIC_SATIN,
    MEDIA_TYPE_PHOTOGRAPHIC_MATTE,
    MEDIA_TYPE_PHOTOGRAPHIC_FILM,
    MEDIA_TYPE_BACK_PRINT_FILM,
    MEDIA_TYPE_CARDSTOCK,
    MEDIA_TYPE_ROLL,
    BPP_MEDIA_TYPE_MAX_ENUM
} bpp_media_type_enum;

typedef enum
{
    BPP_MEDIA_SIZE_A10,
    BPP_MEDIA_SIZE_A9,
    BPP_MEDIA_SIZE_A8,
    BPP_MEDIA_SIZE_A7,
    BPP_MEDIA_SIZE_A6,
    BPP_MEDIA_SIZE_A5,
    BPP_MEDIA_SIZE_A5_EXTRA,
    BPP_MEDIA_SIZE_A4,
    BPP_MEDIA_SIZE_A4_TAB,
    BPP_MEDIA_SIZE_A4_EXTRA,
    BPP_MEDIA_SIZE_A3,
    BPP_MEDIA_SIZE_A2,
    BPP_MEDIA_SIZE_A1,
    BPP_MEDIA_SIZE_A0,
    BPP_MEDIA_SIZE_2A0,
    BPP_MEDIA_SIZE_B10,
    BPP_MEDIA_SIZE_B9,
    BPP_MEDIA_SIZE_B8,
    BPP_MEDIA_SIZE_B7,
    BPP_MEDIA_SIZE_B6,
    BPP_MEDIA_SIZE_B6_C4,
    BPP_MEDIA_SIZE_B5,
    BPP_MEDIA_SIZE_B5_EXTRA,
    BPP_MEDIA_SIZE_B4,
    BPP_MEDIA_SIZE_B3,
    BPP_MEDIA_SIZE_B2,
    BPP_MEDIA_SIZE_B1,
    BPP_MEDIA_SIZE_B0,
    BPP_MEDIA_SIZE_C10,
    BPP_MEDIA_SIZE_C9,
    BPP_MEDIA_SIZE_C8,
    BPP_MEDIA_SIZE_C7,
    BPP_MEDIA_SIZE_C7_C6,
    BPP_MEDIA_SIZE_C6,
    BPP_MEDIA_SIZE_C6_C5,
    BPP_MEDIA_SIZE_C5,
    BPP_MEDIA_SIZE_C4,
    BPP_MEDIA_SIZE_C3,
    BPP_MEDIA_SIZE_C2,
    BPP_MEDIA_SIZE_C1,
    BPP_MEDIA_SIZE_C0,
    BPP_MEDIA_SIZE_4X6_POSTCARD,
    BPP_MEDIA_SIZE_LETTER,
    BPP_MEIDA_SIZE_MAX_ENUM
} bpp_media_size_enum;
typedef enum
{

    BPP_ADP_ERROR_LINK_DISC = -127,
    BPP_ADP_ERROR_PEER_ABORT,
    BPP_ADP_ERROR_USER_ABORT,
    BPP_ADP_ERROR_CREATE_JOB_FAILED,
    BPP_ADP_ERROR_SCO_REJECT,
    BPP_ADP_ERROR_SERVICE_NOT_FOUND,
    BPP_ADP_ERROR_INTERNAL_ERR,
    BPP_ADP_ERROR_DEVICE_BUSY,
    BPP_ADP_ERROR_DISC_STATUS_FIRST,
    BPP_ADP_ERROR_INVALID_PARAM,

    BPP_ADP_ERROR = -1,
    BPP_ADP_SUCCESS = 0,
    BPP_ADP_PENDING
} BPP_ADP_ERROR_CODE;

typedef enum
{
    BPP_SIMPLE_PUSH_PRINT,
    BPP_JOB_BASE_DEFAULT_PRINT, /* use default attribute */
    BPP_JOB_BASE_NOT_DEFAULT_PRINT
} bpp_mode_enum;

#endif /* __BT_BPP_PROFILE__ */ 
/**** End of BPP Enum ****/

/**** Start of BIP Enum ****/
typedef enum
{
    BT_BIP_IMAGE_PUSH = 0x01,
    BT_BIP_IMAGE_PULL = 0x02,
    BT_BIP_ADVANCED_PRINTING = 0x04,
    BT_BIP_REMOTE_CAMERA = 0x08,
    BT_BIP_AUTO_ARCHIVE = 0x10,
    BT_BIP_REMOTE_DISPLAY = 0x20
} bt_bip_service_enum;

typedef enum
{
    BT_BIP_CNF_SUCCESS = 0x70,
    BT_BIP_CNF_FAILED,
    BT_BIP_PARTIAL_CONTENT,
    BT_BIP_XML_GEN_FAIL,
    BT_BIP_FILE_OPEN_FAIL,
    BT_BIP_FILE_READ_FAIL,
    BT_BIP_FILE_WRITE_FAIL,
    BT_BIP_FILE_MOVE_FAIL,
    BT_BIP_INVALID_PARM,
    BT_BIP_DISK_FULL,
    BT_BIP_ROOT_DIR_FULL,
    BT_BIP_FS_MEDIA_CHANGED,
    BT_BIP_FS_DEVICE_BUSY,
    BT_BIP_SCO_REJECT,
    BT_BIP_BTCHIP_REJECT,
    BT_BIP_XML_PARSE_FAIL,
    BT_BIP_FS_QUOTA_FULL,
    BT_BIP_DISCONNECTED,
    BT_BIP_FS_WRITE_PROTECTION,
    BT_BIP_DRM_NO_RIGHTS,

    BT_BIP_LAST_CNF_CODE
} bt_bip_cnf_enum;

typedef enum
{
    BT_BIP_IMG_TYPE_UNSUPPORT = 0x00000000,
    BT_BIP_IMG_TYPE_JPEG = 0x00000001,
    BT_BIP_IMG_TYPE_BMP = 0x00000002,
    BT_BIP_IMG_TYPE_GIF = 0x00000004,
    BT_BIP_IMG_TYPE_WBMP = 0x00000008,
    BT_BIP_IMG_TYPE_PNG = 0x00000010
} bt_bip_img_format_enum;

/**** End of BIP Enum ****/

/* GOEP structure */

#define GOEP2MMI_MSG_COMM \
    kal_uint8 ref_count; \
    kal_uint16 msg_len; \
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];\
    kal_uint8 uuid_len;\
    kal_uint8 goep_conn_id\


typedef struct
{
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
} goep_bd_addr_struct;

typedef struct
{
	GOEP2MMI_MSG_COMM;
}goep_2mmi_common_msg;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 req_id;
    goep_tp_type_enum tp_type;
    kal_bool need_auth;
    kal_uint8 *buf_ptr;
    kal_uint16 buf_size;
} goep_register_server_req_struct;

typedef struct
{
	GOEP2MMI_MSG_COMM;
	
    kal_uint8 req_id;
    kal_uint8 rsp_code;
} goep_register_server_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 goep_conn_id;
} goep_deregister_server_req_struct;

typedef struct
{
	GOEP2MMI_MSG_COMM;
	
    goep_bd_addr_struct bd_addr;
    kal_uint8 dev_name[GOEP_MAX_DEV_NAME];
} goep_authorize_ind_struct;

typedef struct
{
	GOEP2MMI_MSG_COMM;
	
    goep_bd_addr_struct bd_addr;
    kal_uint8 dev_name[GOEP_MAX_DEV_NAME];
    kal_uint16 peer_mru;
    kal_uint32 cm_conn_id;
} goep_connect_ind_struct;

typedef struct
{
	GOEP2MMI_MSG_COMM;

    goep_pkt_type_enum pkt_type;
    goep_put_type_enum put_type;
    kal_uint32 total_obj_len;
    kal_uint8 obj_name[GOEP_MAX_OBJ_NAME];
    kal_uint8 obj_mime_type[GOEP_MAX_MIME_TYPE];
    kal_uint8 *frag_ptr;
    kal_uint16 frag_len;
} goep_push_ind_struct;

typedef struct
{
	GOEP2MMI_MSG_COMM;

    kal_uint8 obj_name[GOEP_MAX_OBJ_NAME];
    kal_uint8 obj_mime_type[GOEP_MAX_MIME_TYPE]; 
    goep_pkt_type_enum pkt_type;
} goep_pull_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 goep_conn_id;
    goep_pkt_type_enum pkt_type;
    kal_uint8 rsp_code;
    kal_uint8 obj_mime_type[GOEP_MAX_MIME_TYPE];
    kal_uint32 total_obj_len;
    kal_uint8 *frag_ptr;
    kal_uint16 frag_len;
} goep_pull_res_struct;

typedef struct
{
	GOEP2MMI_MSG_COMM;

    kal_uint8 folder_name[GOEP_MAX_FOLDER_NAME];
    goep_set_folder_type_enum setpath_flag;
} goep_set_folder_ind_struct;

typedef struct
{
	GOEP2MMI_MSG_COMM;

} goep_abort_ind_struct;


typedef struct 
{
	GOEP2MMI_MSG_COMM;

    kal_uint8 server_supported_formats;
} goep_opp_supported_formats_ind_struct;


typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 req_id;
    kal_uint8 goep_conn_id;
    kal_uint8 passwd[GOEP_MAX_PASSWD_SIZE];
    kal_uint8 passwd_len;
    kal_uint8 realm_str[GOEP_MAX_REALM_SIZE];
    kal_uint8 realm_len;
    goep_role_enum goep_role;
} goep_auth_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 req_id;
    goep_bd_addr_struct bd_addr;
    goep_tp_type_enum tp_type;
    kal_uint8 *buf_ptr;
    kal_uint16 buf_size;
    kal_bool auth_use;
    kal_uint8 passwd[GOEP_MAX_PASSWD_SIZE];
    kal_uint8 passwd_len;
    kal_uint8 realm[GOEP_MAX_REALM_SIZE];
    kal_uint8 realm_len;
} goep_connect_req_struct;

typedef struct
{
	GOEP2MMI_MSG_COMM;

    kal_uint8 req_id;
    kal_uint8 rsp_code;
    kal_uint16 peer_mru;
    kal_uint32 cm_conn_id;
} goep_connect_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 goep_conn_id;
    goep_pkt_type_enum pkt_type;
    goep_put_type_enum put_type;
    kal_uint8 obj_mime_type[GOEP_MAX_MIME_TYPE];
    kal_uint32 total_obj_len;
    kal_uint8 obj_name[GOEP_MAX_OBJ_NAME];
    kal_uint8 *frag_ptr;
    kal_uint16 frag_len;
} goep_push_req_struct;

typedef struct
{
	GOEP2MMI_MSG_COMM;
	
    kal_uint8 rsp_code;
    kal_uint8 reason;   /* failed reason. added for application */
} goep_push_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 goep_conn_id;
    goep_pkt_type_enum pkt_type;
    kal_uint8 obj_mime_type[GOEP_MAX_MIME_TYPE];
    kal_uint8 obj_name[GOEP_MAX_OBJ_NAME];
} goep_pull_req_struct;

typedef struct
{
	GOEP2MMI_MSG_COMM;
	
    goep_pkt_type_enum pkt_type;
    kal_uint8 rsp_code;
    kal_uint32 total_obj_len;
    kal_uint8 *frag_ptr;
    kal_uint16 frag_len;
    kal_bool to_self;   /* added for continue parsing large folder content */
    kal_uint8 reason;   /* failed reason. added for application */
} goep_pull_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 goep_conn_id;
    goep_set_folder_type_enum setpath_flag;
    kal_uint8 folder_name[GOEP_MAX_FOLDER_NAME];
} goep_set_folder_req_struct;

typedef struct
{
	GOEP2MMI_MSG_COMM;

    kal_uint8 rsp_code;
    kal_uint8 reason;   /* failed reason. added for application */
} goep_set_folder_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 goep_conn_id;
} goep_abort_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 req_id;
    kal_uint8 goep_conn_id;
} goep_disconnect_req_struct;

typedef struct
{
	GOEP2MMI_MSG_COMM;
	
    kal_uint8 rsp_code;
} goep_disconnect_rsp_struct;

typedef struct
{
	GOEP2MMI_MSG_COMM;

    kal_uint8 req_id;
} goep_disconnect_ind_struct;

typedef struct
{
	GOEP2MMI_MSG_COMM;
	
    kal_uint8 req_id;
    kal_uint8 realm[GOEP_MAX_REALM_SIZE];
    kal_uint8 realm_len;
    kal_uint8 dev_name[GOEP_MAX_DEV_NAME];
    goep_bd_addr_struct bd_addr;
} goep_auth_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 goep_conn_id;
    kal_uint8 passwd[GOEP_MAX_PASSWD_SIZE];
    kal_uint8 passwd_len;
    kal_uint8 userid[GOEP_MAX_USERID_SIZE];
    kal_uint8 userid_len;
} goep_auth_res_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 goep_conn_id;
    kal_uint8 rsp_code;
} goep_rsp_struct;

/**** BPP Structure ****/

#ifdef __BT_BPP_PROFILE__
/*****************************************************************
BPP MSG  STRUCT
*******************************************************************/
typedef kal_int32 PRT_HANDLE;
typedef struct
{
    kal_char special_char;
    const kal_char *replace_str;
} bpp_xhtml_special_char_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    PRT_HANDLE hprinter;
} bt_bpp_common_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    PRT_HANDLE hprinter;
    kal_int32 ret;
} bt_bpp_common_ret_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    goep_bd_addr_struct add;
    kal_int32 prt_handle;
} bt_bpp_open_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    PRT_HANDLE hprinter;
} bt_bpp_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    PRT_HANDLE hprinter;
    kal_int32 ret;
    goep_bd_addr_struct addr;
    kal_uint32 cm_conn_id;
} bt_bpp_close_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    PRT_HANDLE hprinter;
    kal_int32 ret;
    goep_bd_addr_struct addr;
    kal_uint32 cm_conn_id;
} bt_bpp_open_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    PRT_HANDLE hpriter;

    WCHAR file_name[BPP_MAX_TMP_FILE_NAME];

    kal_uint32 total_data_len;

    bpp_mode_enum print_mode;

    kal_char *pjob_name;
    kal_char *puser_name;
    kal_uint8 copies;
    bpp_sided_enum side;
    bpp_numberup_enum numberup;
    bpp_orientation_enum orientation;
    bpp_media_size_enum media_size;
    bpp_print_quality_enum quality;
    bpp_media_type_enum media_type;

} bt_bpp_print_doc_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    PRT_HANDLE hpriter;
    kal_uint8 attr_req[BPP_ATTR_MAX_ATTRIBUTE];
} bt_bpp_get_attr_req_struct;

typedef struct
{
    kal_uint32 copies;
    kal_uint32 numberup;
    kal_uint32 basictextpagewidth;
    kal_uint32 basictextpageheight;
    kal_uint8 doc_format[BPP_DOCUMENT_FORMAT_MAX_ENUM];
    kal_uint8 sides[BPP_SIDED_MAX_ENUM];
    kal_uint8 orientation[BPP_ORIENTATION_MAX_ENUM];
    kal_uint8 media_size[BPP_MEIDA_SIZE_MAX_ENUM];
    kal_uint8 media_type[BPP_MEDIA_TYPE_MAX_ENUM];
    kal_uint8 quality[BPP_QUALITY_MAX_ENUM];
    kal_uint8 imagetype[BPP_IMAGE_TYPE_MAX_ENUM];
} bt_bpp_prt_capability;

typedef struct
{
    LOCAL_PARA_HDR 
    PRT_HANDLE hprinter;
    kal_int32 ret;

    kal_uint16 printer_state;
    kal_uint16 state_reson;
    bt_bpp_prt_capability capability;
} bt_bpp_get_attr_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    PRT_HANDLE hprinter;
    kal_uint32 precent;
} bt_bpp_progress_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    PRT_HANDLE hprinter;

    bpp_printer_state_enum printer_state;
    bpp_job_state_enum job_state;
    kal_int16 state_reson;
} bt_bpp_job_state_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    PRT_HANDLE hprinter;
    goep_bd_addr_struct bt_addr;
    kal_uint8 realm[GOEP_MAX_REALM_SIZE];
    kal_uint16 realm_len;
} bt_bpp_authen_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    PRT_HANDLE hprinter;
    goep_bd_addr_struct bt_addr;

    kal_bool cancel;
    kal_uint8 passwd[GOEP_MAX_PASSWD_SIZE];
    kal_uint16 passwd_len;
    kal_uint8 userid[GOEP_MAX_USERID_SIZE];
    kal_uint16 userid_len;
} bt_bpp_authen_rsp_struct;
typedef struct
{
    LOCAL_PARA_HDR 
    PRT_HANDLE hprinter;
    goep_bd_addr_struct addr;
    kal_uint32 cm_conn_id;
} bt_bpp_disc_ind_struct;

typedef bt_bpp_common_ind_struct bt_bpp_common_req_struct;

typedef bt_bpp_common_ind_struct bt_bpp_common_rsp_struct;

typedef bt_bpp_common_rsp_struct bt_bpp_status_rsp_struct;

typedef bt_bpp_common_rsp_struct bt_bpp_progress_rsp_struct;

typedef bt_bpp_common_ret_struct bt_bpp_print_doc_cnf_struct;

#endif /* __BT_BPP_PROFILE__ */ 
/**** End of BPP Structure ****/
typedef goep_rsp_struct goep_deregister_server_rsp_struct;
typedef goep_rsp_struct goep_auth_rsp_struct;
typedef goep_rsp_struct goep_abort_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 goep_conn_id;
    kal_uint8 rsp_code;
} goep_res_struct;

typedef goep_res_struct goep_authorize_res_struct;
typedef goep_res_struct goep_connect_res_struct;
typedef goep_res_struct goep_push_res_struct;
typedef goep_res_struct goep_set_folder_res_struct;
typedef goep_res_struct goep_abort_res_struct;

/* The following defined structs for SIM Access Profile (SAP) */

/* Bingyi 20091225: Move BT-SIM interface to SIM header files (APDU_REQ_MAX_LEN, APDU_RSP_MAX_LEN, ATR_MAX_LEN). */

/* SIM Card ID  */
#define BT_SIM_CARD_ID_1	0x01
#define BT_SIM_CARD_ID_2	0x02
#define BT_SIM_CARD_ID_3	0x04
#define BT_SIM_CARD_ID_4	0x08


/* MSG_ID_BT_SIMAP_CONNECT_IND */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cid;  /* connection id */
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
} bt_simap_connect_ind_struct;

/* MSG_ID_BT_SIMAP_DISCONNECT_IND */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cid;  /* connection id */

} bt_simap_disconnect_ind_struct;

/* MSG_ID_BT_SIMAP_DISCONNECT_CNF */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
    kal_uint8 cid;  /* connection id */
} bt_simap_disconnect_cnf_struct;

/* MSG_ID_BT_SIMAP_DEACTIVATE_CNF */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
} bt_simap_deactivate_cnf_struct;

/* MSG_ID_BT_SIMAP_AUTH_REQ */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 lap;
    kal_uint8 uap;
    kal_uint16 nap;
} bt_simap_auth_req_struct;

/* MSG_ID_BT_SIMAP_AUTH_RSP */
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool result;
#ifdef __GEMINI__
    kal_uint8 sim_card_id;	// Used SIM card ID; BT_SIM_CARD_ID_1 for SIM_1, BT_SIM_CARD_ID_2 for SIM_2
#endif
} bt_simap_auth_rsp_struct;

/* Bingyi 20091225: Move BT-SIM interface to SIM header files. */

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 result;
    kal_uint32 handle;
} bt_app_sdpdb_get_handle_cnf_struct;

/* MSG_ID_BT_SDPDB_REGISTER_REQ */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint32 handle;
    kal_uint8 type;
    kal_uint8 *record_raw;
    kal_uint16 record_raw_length;
    kal_uint8 *attribs_buffer;
    kal_uint16 attribs_buffer_size;
} bt_app_sdpdb_register_req_struct;

/* MSG_ID_BT_SDPDB_REGISTER_CNF */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 result;
    kal_uint32 handle;
} bt_app_sdpdb_register_cnf_struct;

/* MSG_ID_BT_SDPDB_DEREGISTER_REQ */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint32 handle;
} bt_app_sdpdb_deregister_req_struct;

/* MSG_ID_BT_SDPDB_DEREGISTER_CNF */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 result;
    kal_uint32 handle;
} bt_app_sdpdb_deregister_cnf_struct;

/* MSG_ID_BT_SDPDB_RETRIEVE_RECOED_REQ */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint32 handle;
} bt_app_sdpdb_retrieve_record_req_struct;

/* MSG_ID_BT_SDPDB_RETRIEVE_RECOED_CNF */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 result;
    kal_uint32 handle;
    kal_uint8 *record;
    kal_uint16 record_size;
} bt_app_sdpdb_retrieve_record_cnf_struct;

#define BTSDPDBAPP_SUCCESS        (0)
#define BTSDPDBAPP_FAILED     (1)
#define BTSDPDBAPP_SDP_REGISTER_FAILED        (2)
#define BTSDPDBAPP_INVALID_HANDLE     (3)
#define BTSDPDBAPP_SDP_DEREGISTER_FAILED      (4)
#define BTSDPDBAPP_SDP_DDB_FULL        (5)
#define BTSDPDBAPP_SDP_RECORD_SYNTAX_ERROR     (6)
#define BTSDPDBAPP_SDP_RECORD_TOO_LARGE        (7)
#define BTSDPDBAPP_SDP_RECORD_ATTRIBUTE_BUFFER_TOO_SMALL       (8)

#define BT_APP_REGISTER_RECORD    (0x01)
#define BT_APP_UPDATE_RECORD    (0x02)

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 bd_addr[6];
    kal_uint8 ps_type;
    kal_uint16 mtu;
    kal_uint16 channel;
    kal_uint32 identify;    /* Modify to uint32: 2007-0917 */
    kal_uint8 security_value;
    kal_uint8 *channel_context;
} bt_jsr82_connect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 bd_addr[6];
    kal_uint16 mtu;
    kal_uint8 ps_type;
    kal_uint16 channel;
    kal_uint8 index;
    kal_uint32 identify;
    kal_uint16 l2cap_id;
    kal_uint8 result;
} bt_jsr82_connect_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 ps_type;
    kal_uint16 mtu;
    kal_uint32 identify;
    kal_uint8 security_value;
    kal_uint8 *channel_context;
    /* To support same channel number can be connected via different client devices on multiple MUX */
    kal_uint16 existing_psm_chnl_num;
} bt_jsr82_enable_service_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 result;
    kal_uint8 ps_type;
    kal_uint16 channel;
    kal_uint8 index;    /* When the service is registered, the session_inx must be returned */
    kal_uint32 identify;
} bt_jsr82_enable_service_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 index;
    kal_uint8 ps_type;
    kal_uint32 identify;
} bt_jsr82_turnon_service_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 index;
    kal_uint8 ps_type;
    kal_uint32 identify;
} bt_jsr82_turnoff_service_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 result;
    kal_uint8 index;
    kal_uint32 identify;
    kal_uint8 ps_type;
} bt_jsr82_turnon_service_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 result;
    kal_uint8 index;
    kal_uint32 identify;
    kal_uint8 ps_type;
} bt_jsr82_turnoff_service_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 index; /* Modified from identify to index: For Read and Write Procedure, only session_inx is needed 2007-0917 */
    kal_uint32 identify;
} bt_jsr82_disable_service_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 result;
    kal_uint8 ps_type;
    kal_uint8 index;
    kal_uint32 identify;
} bt_jsr82_disable_service_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 bd_addr[6];
    kal_uint8 ps_type;
    kal_uint16 mtu;
    kal_uint16 channel;
    kal_uint8 index;
    kal_uint32 identify;
    kal_uint8 friendly_name[BT_BIP_MAX_IMG_NAME_LEN];     
    kal_uint16 l2cap_id;
    kal_uint8 rsp_result;
} bt_jsr82_connect_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 bd_addr[6];
    kal_uint8 ps_type;
    kal_uint16 mtu;
    kal_uint16 channel;
    kal_uint8 index;
    kal_uint32 identify;
    kal_uint16 l2cap_id;
    kal_uint8 result;
} bt_jsr82_connect_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 ps_type;
    kal_uint8 index;
    kal_uint32 identify;
    kal_uint16 l2cap_id;
} bt_jsr82_disconnect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 ps_type;
    kal_uint32 identify;
    kal_uint8 index;    /* session_inx */
    kal_uint16 l2cap_id;
} bt_jsr82_disconnect_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 index; /* Modified from identify to index: For Read and Write Procedure, only session_inx is needed 2007-0917 */
    kal_uint16 length;
    kal_uint16 l2cap_id;
    kal_uint8 *data;
} bt_jsr82_tx_data_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 index; /* Modified from identify to index: For Read and Write Procedure, only session_inx is needed 2007-0917 */
    kal_uint16 l2cap_id;
    kal_uint8 result;
} bt_jsr82_tx_data_cfn_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 index; /* index is con_id */
    kal_uint16 length;
    kal_uint16 l2cap_id;
    kal_uint8 *data;
} bt_jsr82_rx_data_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 index; /* Modified as session_index for RX operation : 2007-0917 */
    kal_uint16 l2cap_id;
} bt_jsr82_tx_ready_ind_struct;

/* Add MSG_ID_BT_JSR82_RX_READY_IND */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 index; /* Modified as session_index for RX operation : 2007-0917 */
    kal_uint16 length;
    kal_uint16 l2cap_id;
} bt_jsr82_rx_ready_ind_struct;

/* Add MSG_ID_BT_JSR82_SPP_GET_DATA_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 index;
    kal_uint32 identify;
    kal_uint16 length;
    kal_uint16 l2cap_id;
} bt_jsr82_spp_get_data_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 index;
    kal_uint16 l2cap_id;
} bt_jsr82_rx_data_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 ps_type;
    kal_uint8 index;
    kal_uint16 l2cap_id;
    kal_uint16 psm_chnl_num;
} bt_jsr82_allocate_txrx_buf_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 result;
    kal_uint8 ps_type;
    kal_uint8 index;
    kal_uint16 l2cap_id;
    kal_uint16 psm_chnl_num;
} bt_jsr82_allocate_txrx_buf_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint32 transaction_id;
    kal_uint8 bd_addr[6];
    kal_uint8 security_mode;
} bt_jsr82_set_acl_security_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8 result;
    kal_uint32 transaction_id;
    kal_uint8 bdAddr[6];
} bt_jsr82_set_acl_security_cnf_struct;

/**** Start of BIP Structure ****/

typedef enum
{
    BT_BIP_NULL,
    BT_BIP_INITIATOR_ROLE,
    BT_BIP_RESPONDER_ROLE
} bt_bip_session_role_enum;

typedef struct
{
    bt_bip_img_format_enum encoding;
    kal_bool define_pixel_with_range;
    kal_uint16 max_pixel_width;
    kal_uint16 min_pixel_width;
    kal_uint16 max_pixel_height;
    kal_uint16 min_pixel_height;
    kal_uint16 specified_pixel_width;
    kal_uint16 specified_pixel_height;
    kal_uint8 img_handle[8];
    kal_uint8 friendly_name[BT_BIP_MAX_IMG_NAME_LEN];
    kal_uint32 size;
    kal_uint8 created[BT_BIP_MAX_TIME_LEN];     /* (YYYYMMDDTHHMMSS)(Z) */
    kal_uint8 modified[BT_BIP_MAX_TIME_LEN];    /* (YYYYMMDDTHHMMSS)(Z) */
} bt_bip_img_info_struct;

typedef goep_bd_addr_struct bt_bip_bd_addr_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 req_id;
    bt_bip_bd_addr_struct bd_addr;
    bt_bip_service_enum bip_service;
} bt_bip_connect_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 req_id;
    kal_uint8 cnf_code;
    kal_uint32 cm_conn_id;
} bt_bip_connect_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
} bt_bip_get_capabilities_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 cnf_code;
    bt_bip_img_format_enum supported_img_formats[BT_BIP_MAX_IMG_FORMATS];
    bt_bip_img_format_enum preferred_format;
    kal_bool created_time_filter;
    kal_bool modified_time_filter;
    kal_bool encoding_filter;
    kal_bool pixel_filter;
} bt_bip_get_capabilities_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint16 img_path[BT_BIP_MAX_PATH_LEN];
    kal_uint8 img_name[BT_BIP_MAX_IMG_NAME_LEN];
    kal_uint32 img_size;
    bt_bip_img_info_struct img_descriptor;
} bt_bip_put_img_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 img_handle[BT_BIP_IMG_HANDLE_LEN];
    kal_uint8 cnf_code;
} bt_bip_put_img_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint16 img_path[BT_BIP_MAX_PATH_LEN];
    kal_uint8 img_handle[BT_BIP_IMG_HANDLE_LEN];
} bt_bip_put_linked_thumbnail_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 cnf_code;
} bt_bip_put_linked_thumbnail_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    bt_bip_img_info_struct img_list_descriptor;
    kal_uint16 max_img_handle_number;
    kal_uint16 start_index;
    kal_bool latest_captured;
} bt_bip_get_img_list_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint16 img_list_path[BT_BIP_MAX_PATH_LEN];
    kal_uint16 img_count;
    kal_uint8 cnf_code;
} bt_bip_get_img_list_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 img_handle[BT_BIP_IMG_HANDLE_LEN];
} bt_bip_get_img_prop_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    bt_bip_img_info_struct native_img;
    bt_bip_img_info_struct *variant_img_p;
    bt_bip_img_info_struct *attachment_p;
    kal_uint8 cnf_code;
} bt_bip_get_img_prop_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint16 img_path[BT_BIP_MAX_PATH_LEN];
    kal_uint8 img_handle[BT_BIP_IMG_HANDLE_LEN];
    bt_bip_img_info_struct img_descriptor;
} bt_bip_get_img_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 cnf_code;
    kal_uint32 data_len;
} bt_bip_get_img_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint16 img_path[BT_BIP_MAX_PATH_LEN];
    kal_uint8 img_handle[BT_BIP_IMG_HANDLE_LEN];
} bt_bip_get_linked_thumbnail_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 cnf_code;
} bt_bip_get_linked_thumbnail_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint16 img_path[BT_BIP_MAX_PATH_LEN];
    kal_uint8 store_flag;
} bt_bip_get_monitoring_img_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 cnf_code;
} bt_bip_get_monitoring_img_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
} bt_bip_abort_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 cnf_code;
} bt_bip_abort_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 req_id;
    kal_uint8 bip_service_set;
} bt_bip_activate_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 req_id;
    kal_uint8 cnf_code;
} bt_bip_activate_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 req_id;
    kal_uint8 bip_service_set;
} bt_bip_deactivate_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 req_id;
    kal_uint8 cnf_code;
} bt_bip_deactivate_cnf_struct;


typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    bt_bip_bd_addr_struct   bd_addr;
    kal_uint8               dev_name[BT_BIP_MAX_DEV_NAME_LEN];
} bt_bip_authorize_ind_struct;


typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint8               cnf_code;
} bt_bip_authorize_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    bt_bip_bd_addr_struct bd_addr;
    kal_uint8 dev_name[BT_BIP_MAX_DEV_NAME_LEN];
} bt_bip_connect_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 cnf_code;
} bt_bip_connect_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
} bt_bip_get_capabilities_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 cnf_code;
    bt_bip_img_format_enum supported_img_formats[BT_BIP_MAX_IMG_FORMATS];
    bt_bip_img_format_enum preferred_format;
    kal_bool created_time_filter;
    kal_bool modified_time_filter;
    kal_bool encoding_filter;
    kal_bool pixel_filter;
} bt_bip_get_capabilities_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 img_name[BT_BIP_MAX_IMG_NAME_LEN];
    kal_uint32 img_size;
    bt_bip_img_info_struct img_descriptor;
	kal_bool r_last_pkt;
} bt_bip_put_img_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint16 img_path[BT_BIP_MAX_PATH_LEN];   /* checked done */
    kal_uint8 img_handle[BT_BIP_IMG_HANDLE_LEN];
    kal_uint8 cnf_code;
} bt_bip_put_img_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 img_handle[BT_BIP_IMG_HANDLE_LEN];
	kal_bool r_last_pkt;
} bt_bip_put_linked_thumbnail_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint16 img_path[BT_BIP_MAX_PATH_LEN];   /* checked done */
    kal_uint8 cnf_code;
} bt_bip_put_linked_thumbnail_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    bt_bip_img_info_struct img_list_descriptor;
    kal_uint16 max_img_handle_number;
    kal_uint16 start_index;
    kal_bool latest_captured;
} bt_bip_get_img_list_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint16 img_list_path[BT_BIP_MAX_PATH_LEN];
    kal_uint16 img_count;
    kal_uint8 cnf_code;
} bt_bip_get_img_list_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 img_handle[BT_BIP_IMG_HANDLE_LEN];
} bt_bip_get_img_prop_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 img_handle[BT_BIP_IMG_HANDLE_LEN];
    bt_bip_img_info_struct native_img;
    bt_bip_img_info_struct *variant_img_p;
    bt_bip_img_info_struct *attachment_p;
    kal_uint8 cnf_code;
} bt_bip_get_img_prop_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 img_handle[BT_BIP_IMG_HANDLE_LEN];
    bt_bip_img_info_struct img_descriptor;
} bt_bip_get_img_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint16 img_path[BT_BIP_MAX_PATH_LEN];
    kal_uint8 img_handle[BT_BIP_IMG_HANDLE_LEN];
    kal_uint8 cnf_code;
} bt_bip_get_img_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 img_handle[BT_BIP_IMG_HANDLE_LEN];
} bt_bip_get_linked_thumbnail_ind_struct;

/*
 * typedef struct
 * {
 * kal_uint8       ref_count;
 * kal_uint16      msg_len;
 * kal_uint32      cm_conn_id;
 * kal_uint8       cnf_code;
 * kal_uint16      thumbnail_path[BT_BIP_MAX_PATH_LEN];
 * } bt_bip_get_linked_thumbnail_rsp_struct;
 */

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 store_flag;
} bt_bip_get_monitoring_img_ind_struct;

/*
 * typedef struct
 * {
 * kal_uint8       ref_count;
 * kal_uint16      msg_len;
 * kal_uint32      cm_conn_id;
 * kal_uint8       cnf_code;
 * kal_uint16      img_path[BT_BIP_MAX_PATH_LEN];
 * kal_uint8               img_handle[BT_BIP_IMG_HANDLE_LEN];
 * } bt_bip_get_monitoring_img_rsp_struct;
 */

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 ind_code;
} bt_bip_abort_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
} bt_bip_complete_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint32 obj_len;
    kal_uint32 data_len;
	kal_bool r_last_pkt;
} bt_bip_continue_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 cnf_code;
} bt_bip_continue_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 req_id;
    kal_uint32 cm_conn_id;
    kal_bool disconnect_tp_directly;
    bt_bip_session_role_enum session_role;
} bt_bip_disconnect_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    bt_bip_session_role_enum session_role;
} bt_bip_disconnect_ind_struct;

typedef struct
{
    kal_uint8 img_handle[BT_BIP_IMG_HANDLE_LEN];
    kal_uint8 created[BT_BIP_MAX_TIME_LEN];     /* (YYYYMMDDTHHMMSS)(Z) */
    kal_uint8 modified[BT_BIP_MAX_TIME_LEN];    /* (YYYYMMDDTHHMMSS)(Z) */
} bt_bip_img_min_info_struct;

typedef bt_bip_get_img_rsp_struct bt_bip_get_linked_thumbnail_rsp_struct;
typedef bt_bip_get_img_rsp_struct bt_bip_get_monitoring_img_rsp_struct;

/**** End of BIP Structure ****/

/* for OBEX authentication */
typedef struct
{
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;
    kal_uint8 passwd[GOEP_MAX_PASSWD_SIZE];
    kal_uint8 passwd_len;
    kal_uint8 realm_str[GOEP_MAX_REALM_SIZE];
    kal_uint8 realm_len;
} auth_chal_struct;

typedef kal_uint8(*AUTH_IND_HANDLER) (goep_auth_ind_struct *auth_ind);

struct auth_ind_handler_struct
{
    kal_uint8 uuid[GOEP_MAX_UUID_SIZE];
    kal_uint8 uuid_len;

    AUTH_IND_HANDLER auth_ind_handler;

    struct auth_ind_handler_struct *next;

};

typedef struct auth_ind_handler_struct auth_ind_handler_struct;

/* END for OBEX authentication */

/* csj */
/* struct used by pbap */
/*#if defined(__BT_PBAP_NEW_PROFILE__) || defined(__MMI_PBAP_NEW_SUPPORT__) */
#if defined(__BT_PBAP_PROFILE__) || defined(__BT_PBAP_CLIENT__)

#define PBAP_FILTER_SIZE                8
#define BT_PBAP_MAX_DEV_NAME_LEN        80

#define PBAP_INVALID_COUNT   0xFFFF

typedef struct _PbapVcardFilter
{
    /* Array of 8 bytes for this 64-bit filter value */
    kal_uint8 byte[PBAP_FILTER_SIZE];
} PbapVcardFilter;

typedef kal_uint8 PbapVcardFormat;

#define VCARD_FORMAT_21        0x00     /* Version 2.1 format */
#define VCARD_FORMAT_30        0x01     /* Version 3.0 format */

/*SearchAttributes*/
#define PBAP_SEARCH_ATTRIB_NAME        0x00    /* Search by Name */
#define PBAP_SEARCH_ATTRIB_NUMBER      0x01    /* Search by Number */
#define PBAP_SEARCH_ATTRIB_SOUND       0x02    /* Search by Sound */

/*vcard sort order in listing*/
#define PBAP_SORT_ORDER_INDEXED        0x00    /* Indexed sorting */
#define PBAP_SORT_ORDER_ALPHA          0x01    /* Alphabetical sorting */
#define PBAP_SORT_ORDER_PHONETICAL     0x02    /* Phonetical sorting */

/*---------------------------------------------------------------------------
 * PB_MAX_NAME_LEN constant
 *
 *     Maximum number of characters allowed for pathnames + 1 (null-
 *     terminating character).
 */
#define PBAP_MAX_NAME_LEN         128
#define MAX_PBAP_SEARCH_VALUE_LENGTH PBAP_MAX_NAME_LEN

/* PBAP MAX length of file path */
#define BT_PBAP_MAX_FILEPATH_NAME_LEN        256


/*---------------------------------------------------------------------------
 * PbStatus type
 *
 *     This type is returned from most phonebook APIs to indicate the success
 *     or failure of the operation. In many cases, BT_STATUS_PENDING
 *     is returned, meaning that a future callback will indicate the
 *     result of the operation.
 */

typedef kal_uint8 PbStatus;

#define PB_STATUS_SUCCESS           0   /* XA_STATUS_SUCCESS */
#define PB_STATUS_FAILED            1   /* XA_STATUS_FAILED */
#define PB_STATUS_NO_RESOURCES      12  /* XA_STATUS_NO_RESOURCES */
#define PB_STATUS_NOT_FOUND         13  /* XA_STATUS_NOT_FOUND */
#define PB_STATUS_UNKNOWN_REMOTE    14  /* XA_STATUS_DEVICE_NOT_FOUND */
#define PB_STATUS_INUSE             5   /* XA_STATUS_IN_USE */
#define PB_STATUS_NOT_SUPPORTED     23  /* XA_STATUS_NOT_SUPPORTED */
#define PB_STATUS_PENDING           2   /* XA_STATUS_PENDING */
/* End of PbStatus */
typedef kal_uint8 PbapRespCode;

/* Group: Successful response codes */

#define PBRC_CONTINUE              0x10 /* Continue */
#define PBRC_STATUS_SUCCESS        0x20 /* Success */

/* Group: Failure response codes */

#define PBRC_BAD_REQUEST           0x40 /* Bad Request */
#define PBRC_UNAUTHORIZED          0x41 /* Unauthorized */
#define PBRC_FORBIDDEN             0x43 /* Forbidden - operation is understood */
#define PBRC_NOT_FOUND             0x44 /* Not Found */
#define PBRC_NOT_ACCEPTABLE        0x46 /* Not Acceptable */
#define PBRC_PRECONDITION_FAILED   0x4c /* Precondition Failed */
#define PBRC_NOT_IMPLEMENTED       0x51 /* Not Implemented */
#define PBRC_SERVICE_UNAVAILABLE   0x53 /* Service Unavailable */
#define PBRC_LINK_DISCONNECT       0x80 /* Transport connection has been disconnected. */
#define PBRC_INTERNAL_SERVER_ERR   0x50 /* OBRC_INTERNAL_SERVER_ERR */

/* End of PbapRespCode */

#define PBAP_ADP_WORK_FOLDER     (L"Z:\\@pbap\\")
#define PBAP_ADP_FOLDER_FILE        (L"Z:\\@pbap\\folder.tmp")
#define PBAP_ADP_LIST_FILE   (L"Z:\\@pbap\\list.tmp")
#define PBAP_ADP_ENTRY_FILE   (L"Z:\\@pbap\\entry.tmp")

/*---------------------------------------------------------------------------
 * PbapAppParmsTag type
 *
 *     Describes the tag values used in the Application Parameters OBEX header
 *     that are used on both the Phonebook Access client and server side.
 */
typedef kal_uint8 PbapAppParmsTag;

#define PBAP_TAG_ORDER              0x01        /* 1-byte, 0x00 (indexed), 0x01 (alpha), or 0x02 (phonetic) */
#define PBAP_TAG_SEARCH_VALUE       0x02        /* Variable length text string */
#define PBAP_TAG_SEARCH_ATTRIB      0x03        /* 1-byte, 0x00 (Name), 0x01 (Number), or 0x02 (Sound) */
#define PBAP_TAG_MAX_LIST_COUNT     0x04        /* 2-bytes, 0x0000 to 0xFFFF */
#define PBAP_TAG_LIST_OFFSET        0x05        /* 2-bytes, 0x0000 to 0xFFFF */
#define PBAP_TAG_FILTER             0x06        /* 8-bytes, 64 bit mask */
#define PBAP_TAG_FORMAT             0x07        /* 1-byte, 0x00 = 2.1, 0x01 = 3.0 */
#define PBAP_TAG_PHONEBOOK_SIZE     0x08        /* 2-bytes, 0x0000 to 0xFFFF */
#define PBAP_TAG_MISSED_CALLS       0x09        /* 1-byte, 0x00 to 0xFF */

/* End of PbapAppParmsTag */

/*---------------------------------------------------------------------------
 * pbap_set_folder_type_enum type
 *
 *     Flags used in the SetFolder operation.  PBAP specification requires
 *     that the PBAP_SETPB_DONT_CREATE flag is always set.
 */
typedef enum
{
    PBAP_FORWARD_FOLDER = 0,
    PBAP_BACK_FOLDER,
    PBAP_ROOT_FOLDER
} pbap_set_folder_type_enum;


typedef enum
{
    PBAP_CNF_SUCCESS,
    PBAP_CNF_FAILED,
    PBAP_CNF_TOTAL
} bt_pbap_cnf_enum;

typedef goep_bd_addr_struct bt_pbap_bd_addr_struct;

#endif /* defined(__BT_PBAP_PROFILE__) || defined(__BT_PBAP_CLIENT__) */

#ifdef __BT_PBAP_PROFILE__
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 security_level;
} bt_pbap_register_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 register_result;
} bt_pbap_register_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} bt_pbap_deregister_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 register_result;
} bt_pbap_deregister_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} bt_pbap_abort_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} bt_pbap_disconnect_ind_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    bt_pbap_bd_addr_struct   bd_addr;
    kal_uint8               dev_name[BT_PBAP_MAX_DEV_NAME_LEN];
} bt_pbap_authorize_ind_struct;

typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint8               cnf_code;
} bt_pbap_authorize_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    bt_pbap_bd_addr_struct bd_addr;
    kal_uint8 dev_name[BT_PBAP_MAX_DEV_NAME_LEN];
} bt_pbap_connect_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_bool disconnect_tp_directly;
} bt_pbap_disconnect_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} bt_pbap_disconnect_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint32 cm_conn_id;
    kal_uint8 cnf_code;
} bt_pbap_connect_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 dev_name[BT_PBAP_MAX_DEV_NAME_LEN];
} bt_pbap_auth_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cancel;
    /* OBEX Authentication password */
    kal_uint8 password[20];
    /* OBEX Authentication userId */
    kal_uint8 userId[20];
    /* OBEX Authentication realm */
    kal_uint8 realm[20];
} bt_pbap_auth_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    pbap_set_folder_type_enum type;
    kal_uint16 name[PBAP_MAX_NAME_LEN/2 + 1];
} bt_pbap_set_path_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;
} bt_pbap_set_path_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 objectName[PBAP_MAX_NAME_LEN/2 + 1];  /* (*.vcf) */
    PbapVcardFilter filter;
    PbapVcardFormat format;
} bt_pbap_read_entry_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;   /* PBSTATUS */
} bt_pbap_read_entry_rsp_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 pbName[PBAP_MAX_NAME_LEN/2 + 1];
    PbapVcardFilter filter;
    PbapVcardFormat format;
    kal_uint16 maxListCount;
    kal_uint16 listStartOffset;
    kal_uint8 to_self;
} bt_pbap_read_folder_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 folderName[PBAP_MAX_NAME_LEN/2 + 1];
    kal_uint8 searchAttribute;
    kal_uint8 searchValue[MAX_PBAP_SEARCH_VALUE_LENGTH + 1];
    kal_uint8 searchValueLength;
    kal_uint8 order;
    kal_uint16 maxListCount;
    kal_uint16 listStartOffset;
    kal_uint8 to_self;
} bt_pbap_read_list_ind_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 result;
    kal_uint16 phoneBookSize; /*0xFFFF indicates have only data*/
    kal_uint16 newMissedCalls; /*0xFFFF indicates the type is not MCH*/
} bt_pbap_read_rsp_struct;

typedef bt_pbap_read_rsp_struct bt_pbap_read_folder_rsp_struct;
typedef bt_pbap_read_rsp_struct bt_pbap_read_list_rsp_struct;
#endif /* __BT_PBAP_PROFILE__ */ 

#ifdef __BT_PBAP_CLIENT__
/*--------------------------- Begin of the PBAP Client ------------------*/
/*------------------------------------------------------------------------
 * For PBAP Client
 * Add for the PCE Role of BT dialer(MTK 54345, 2012.11 ~ 2012.12)
 *-----------------------------------------------------------------------*/
#ifndef PBAP_MAX_PASSWORD_LEN
#define PBAP_MAX_PASSWORD_LEN       20
#endif

#ifndef PBAP_MAX_USERID_LEN
#define PBAP_MAX_USERID_LEN         20
#endif

#ifndef FHANDLE
typedef signed int FHANDLE;
#endif /* FHANDLE */

#ifndef FHANDLE_INVALID_VALUE
#define FHANDLE_INVALID_VALUE -10
#endif /* FHANDLE_INVALID_VALUE */


/* Puplic Data Structures */
typedef enum
{
	PBAPC_REQ_NONE,
	PBAPC_REQ_ENABLE,
	PBAPC_REQ_DISABLE,
	PBAPC_REQ_CONNECT,
	PBAPC_REQ_SET_PATH,
	PBAPC_REQ_PULL_ENTRY,
	PBAPC_REQ_PULL_LIST,
	PBAPC_REQ_PULL_PB,
	PBAPC_REQ_ABORT,
	PBAPC_REQ_DISCONNECT,
	PBAPC_REQ_LAST
} bt_pbapc_request_type;

typedef enum
{
	PBAP_STATE_IDLE,
	PBAP_STATE_TP_CONNECTING,
	PBAP_STATE_OBEX_CONNECTING,
	PBAP_STATE_CONNECTED,
	PBAP_STATE_PULLING,
	PBAP_STATE_SETTING_PATH,
	PBAP_STATE_DISCONNECTING,
	PBAP_STATE_MAX
} bt_pbap_conn_state;


/* Activate the PCE */
typedef struct
{
	LOCAL_PARA_HDR
} bt_pbapc_enable_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	bt_pbap_cnf_enum register_result;
} bt_pbapc_enable_cnf_struct;

/* Deactivate the PCE */
typedef struct
{
	LOCAL_PARA_HDR
} bt_pbapc_disable_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	bt_pbap_cnf_enum deregister_result;
} bt_pbapc_disable_cnf_struct;

/* PCE Connect Request */
typedef struct
{
    LOCAL_PARA_HDR
    bt_pbap_bd_addr_struct bd_addr;/* local bt device address(lap, uap, nap) */
} bt_pbapc_connect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    /* allocated during the connection establishmen to indicate the connection */
    kal_uint32	cm_conn_id;
    bt_pbap_cnf_enum	cnf_code;
} bt_pbapc_connect_cnf_struct;

/* Client Disconnect confirmation(Confirmation of disconnect indication and request) */
typedef struct
{
	LOCAL_PARA_HDR
	bt_pbap_cnf_enum cnf_code;
} bt_pbapc_disconnect_cnf_struct;

/* Client Disconnect Indication */
typedef struct
{
    LOCAL_PARA_HDR
}bt_pbapc_disconnect_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
	bt_pbap_cnf_enum cnf_code;
} bt_pbapc_abort_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 cancel;
    /* OBEX Authentication password */
    kal_uint8 password[PBAP_MAX_PASSWORD_LEN];
    /* OBEX Authentication userId */
    kal_uint8 userId[PBAP_MAX_USERID_LEN];
} bt_pbapc_auth_challenge_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    /*don't use the following two paramters now please */
    kal_uint8 dev_name[BT_PBAP_MAX_DEV_NAME_LEN]; /* UTF8 zero-terminated string */
    kal_uint8 auth_option;
} bt_pbapc_auth_challenge_ind_struct;


/* PCE SetPath Request(SetPhoneBook) */
typedef struct
{
    LOCAL_PARA_HDR
    pbap_set_folder_type_enum type; /* Forward, Back or Root folder */
    /* Maximum number of characters allowed for pathnames + 1 (null-
     * terminating character */
    kal_uint8                 name[PBAP_MAX_NAME_LEN/2+1];						
} bt_pbapc_set_path_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    bt_pbap_cnf_enum	cnf_code;
} bt_pbapc_set_path_cnf_struct;


/* PCE get vCard Request(PullvCardEntry) */
typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 		pbap_data_file[BT_PBAP_MAX_FILEPATH_NAME_LEN];	// UCS-2
	kal_uint8		objectName[PBAP_MAX_NAME_LEN/2+1];				// UCS-2
	PbapVcardFilter	filter;
	PbapVcardFormat	format;
} bt_pbapc_read_entry_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	bt_pbap_cnf_enum	cnf_code;
} bt_pbapc_read_entry_cnf_struct;

/* PCE get vCard Listing(PullvCardListing) */
typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8  pbap_data_file[BT_PBAP_MAX_FILEPATH_NAME_LEN];	// UCS-2
	kal_uint8  folderName[PBAP_MAX_NAME_LEN/2+1];				// UCS-2
	kal_uint8  searchAttribute;
	kal_uint8  searchValue[MAX_PBAP_SEARCH_VALUE_LENGTH + 1]; // UTF-8
	kal_uint8  searchValueLength;
	kal_uint8  order;
	kal_uint16 maxListCount;
	kal_uint16 listStartOffset;
} bt_pbapc_read_list_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	bt_pbap_cnf_enum  cnf_code;
	kal_uint16 phoneBookSize; /*0xFFFF indicates have only data*/
	kal_uint16 newMissedCalls; /*0xFFFF indicates the type is not MCH*/
} bt_pbapc_read_list_cnf_struct;


/* PCE get PhoneBook(PullPhoneBook) */
typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 		pbap_data_file[BT_PBAP_MAX_FILEPATH_NAME_LEN]; // UCS-2
	kal_uint8		folderName[PBAP_MAX_NAME_LEN/2+1];			// UCS-2
	PbapVcardFilter	filter;
	PbapVcardFormat	format;
	kal_uint16		maxListCount;
	kal_uint16		listStartOffset;
} bt_pbapc_read_folder_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	bt_pbap_cnf_enum  cnf_code;
	kal_uint16 phoneBookSize; /*0xFFFF indicates have only data*/
	kal_uint16 newMissedCalls; /*0xFFFF indicates the type is not MCH*/
} bt_pbapc_read_folder_cnf_struct;

#define PBAPC_ADP_WORK_FOLDER     L"Z:\\@pbap\\"
#define PBAPC_ADP_FOLDER_FILE        L"Z:\\@pbap\\folder.tmp"
#define PBAPC_ADP_LIST_FILE   L"Z:\\@pbap\\list.tmp"
#define PBAPC_ADP_ENTRY_FILE   L"Z:\\@pbap\\entry.tmp"

/*--------------------------- end of the PBAP Client --------------------*/
#endif /* __BT_PBAP_PROFILE__ */

#ifdef __BT_MAP_CLIENT__
/*----------------------- Begin of the MAP Client -----------------------*/
/*------------------------------------------------------------------------
 * For MAP Client
 * Add for the MCE Role of BT dialer(MTK 54345, 2012.11 ~ 2012.12)
 *-----------------------------------------------------------------------*/
#define BT_MAP_MAX_DEV_NAME_LEN          80
#define BT_MAP_MAX_FOLDER_NAME_LEN       256
#define BT_MAP_MAX_PATH_NAME_LEN         512
#define BT_MAP_MAX_TEMP_FILE_NAME_LEN    160
#define BT_MAP_MAX_DATE_STR_LEN          16
#define BT_MAP_MAX_DATETIME_STR_LEN      20
#define BT_MAP_MAX_CONTACT_STR_LEN       80
#define BT_MAP_MAX_HANDLE_STR_LEN        32
#define MAP_MAX_HANDLE_STR_UCS2_LEN      64
    
typedef enum
{
    BT_MAP_MSG_NONE = 0x0,
    BT_MAP_MSG_SMS_GSM = 0x1,
    BT_MAP_MSG_SMS_CDMA = 0x2,
    BT_MAP_MSG_EMAIL = 0x4,
    BT_MAP_MSG_MMS = 0x8,
    BT_MAP_MSG_END
} bt_map_msg_enum;

typedef enum
{
    BT_MAP_FOLDER_OP_ROOT,  /* set to root folder */
    BT_MAP_FOLDER_OP_NEXT,  /* set to peer folder ex. cd ../xxx */
    BT_MAP_FOLDER_OP_DOWN,  /* set to child folder */
    BT_MAP_FOLDER_OP_UP,    /* set to parent folder */
    BT_MAP_FOLDER_OP_END
} bt_map_folder_op_enum;

typedef enum
{
    BT_MAP_SUCCESS                = 0,
    BT_MAP_FAIL                   = 1,
    BT_MAP_FAIL_BUSY              = 2,
    BT_MAP_FAIL_NOT_FOUND         = 3,
    BT_MAP_FAIL_NOT_SUPPORT       = 4,
    BT_MAP_FAIL_FORBIDDEN         = 5,
    BT_MAP_FAIL_TIMEOUT           = 6,
    BT_MAP_FAIL_NO_RESOURCE       = 7,
    BT_MAP_FAIL_UNAUTHORIZED      = 8,
    BT_MAP_FAIL_BAD_FORMAT        = 9,
    BT_MAP_FAIL_INVALID_PARAMETER = 10,
    BT_MAP_FAIL_BAD_STATE         = 11,
    BT_MAP_FAIL_STORAGE_FULL      = 12,
    BT_MAP_RESULT_END
} bt_map_result_enum;

typedef enum
{
    BT_MAP_MSGLIST_MASK_NONE        = 0x0000,
    BT_MAP_MSGLIST_MASK_SUBJECT     = 0x0001,  /* REQUIRED */
    BT_MAP_MSGLIST_MASK_DATETIME    = 0x0002,  /* REQUIRED */
    BT_MAP_MSGLIST_MASK_SENDER_N    = 0x0004,
    BT_MAP_MSGLIST_MASK_SENDER_ADDR = 0x0008,
    BT_MAP_MSGLIST_MASK_REC_N       = 0x0010,
    BT_MAP_MSGLIST_MASK_REC_ADDR    = 0x0020,  /* REQUIRED */
    BT_MAP_MSGLIST_MASK_TYPE        = 0x0040,  /* REQUIRED */
    BT_MAP_MSGLIST_MASK_SIZE        = 0x0080,  /* REQUIRED */
    BT_MAP_MSGLIST_MASK_REC_STATUS  = 0x0100,  /* REQUIRED */
    BT_MAP_MSGLIST_MASK_TEXT        = 0x0200,  /* default: no */
    BT_MAP_MSGLIST_MASK_ATTACH_SIZE = 0x0400,  /* REQUIRED */
    BT_MAP_MSGLIST_MASK_PRIO        = 0x0800,  /* default: no */
    BT_MAP_MSGLIST_MASK_READ        = 0x1000,  /* default: no */
    BT_MAP_MSGLIST_MASK_SENT        = 0x2000,  /* default: no */
    BT_MAP_MSGLIST_MASK_DRM         = 0x4000,  /* default: no */
    BT_MAP_MSGLIST_MASK_REPLY_ADDR  = 0x8000,
    BT_MAP_MSGLIST_MASK_ALL         = 0xFFFF
} bt_map_msg_list_mask_enum;

typedef enum
{
    BT_MAP_FILTER_MSG_SMS_GSM  = 0x1,
    BT_MAP_FILTER_MSG_SMS_CDMA = 0x2,
    BT_MAP_FILTER_MSG_EMAIL    = 0x4,
    BT_MAP_FILTER_MSG_MMS      = 0x8
} bt_map_filter_msg_enum;

typedef enum
{
    BT_MAP_FILTER_STATUS_ALL    = 0x0, /* no-filtering, get both ready and unready messages */
    BT_MAP_FILTER_STATUS_UNREAD = 0x1, /* get unread message only */
    BT_MAP_FILTER_STATUS_READ   = 0x2  /* get read status only */
} bt_map_filter_status_enum;

typedef enum
{
    BT_MAP_FILTER_PRIO_ALL      = 0x0, /* no-filtering */
    BT_MAP_FILTER_PRIO_HIGH     = 0x1, /* get high priority message only */
    BT_MAP_FILTER_PRIO_NOT_HIGH = 0x2  /* get non-high priority message only */
} bt_map_filter_prio_enum;

typedef enum
{
    BT_MAP_CHARSET_NATIVE = 0x0,
    BT_MAP_CHARSET_UTF8   = 0x1
} bt_map_charset_enum;

typedef enum
{
    BT_MAP_FRACTION_REQ_FIRST = 0x0,
    BT_MAP_FRACTION_REQ_NEXT  = 0x1,
    BT_MAP_FRACTION_REQ_NO
} bt_map_fraction_req_enum;

typedef enum
{
    BT_MAP_FRACTION_RSP_MORE = 0x0,
    BT_MAP_FRACTION_RSP_LAST = 0x1,
    BT_MAP_FRACTION_RSP_NO
} bt_map_fraction_rsp_enum;

typedef enum
{
    BT_MAP_MSG_STATUS_READ     = 0x0,
    BT_MAP_MSG_STATUS_UNREAD   = 0x1,
    BT_MAP_MSG_STATUS_DELETE   = 0x2,
    BT_MAP_MSG_STATUS_UNDELETE
} bt_map_msg_status_enum;

typedef enum
{
    BT_MAP_SAVE_AND_SENT,
    BT_MAP_SENT
} bt_map_sent_op_enum;


/* Activate the MCE */
typedef struct
{
    LOCAL_PARA_HDR
    bt_map_result_enum result;
} bt_mapc_activate_cnf_struct;

/* Deactive the MCE */
typedef struct
{
    LOCAL_PARA_HDR
    bt_map_result_enum result;
} bt_mapc_deactivate_cnf_struct;

typedef goep_bd_addr_struct bt_map_addr_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_addr_struct addr;
    kal_uint8          mas_id;  /* Range 0~255 */
} bt_mapc_connect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_addr_struct addr;
    kal_uint8          dev_name[BT_MAP_MAX_DEV_NAME_LEN + 1]; /* UTF8 zero-terminated string */
} bt_mapc_mns_authorize_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    kal_bool           accept;  /* TRUE: accept, FALSE: reject */
    bt_map_addr_struct addr;
} bt_mapc_mns_authorize_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    bt_map_result_enum result;
    bt_map_addr_struct addr;
    kal_uint8          mas_id;  /* Range 0~255 */
    kal_uint8          dev_name[BT_MAP_MAX_DEV_NAME_LEN + 1]; /* UTF8 zero-terminated string */
} bt_mapc_connect_cnf_struct;

/* MCE sends the gracefully disconnect request */
typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_addr_struct addr;
    kal_uint8          mas_id;  /* Range 0~255 */
} bt_mapc_disconnect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_result_enum result;
    bt_map_addr_struct addr;
    kal_uint8          mas_id;  /* Range 0~255 */
} bt_mapc_disconnect_cnf_struct;

/* MCE receives the disconnect indication */
typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_addr_struct addr;
    kal_uint8          mas_id;  /* Range 0~255 */
} bt_mapc_disconnect_ind_struct;

/* MCE sends the forcibly disconnect request */
typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_addr_struct addr;
} bt_mapc_mns_disconnect_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_result_enum result;
    bt_map_addr_struct addr;
} bt_mapc_mns_disconnect_cnf_struct;

/* MCE sends the SetFolder request */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8             mas_id;  /* Range 0~255 */
    bt_map_addr_struct    addr;    
    bt_map_folder_op_enum flag;
    kal_uint8             folder[BT_MAP_MAX_FOLDER_NAME_LEN + 2]; /* UCS2, null terminated, only used when NEXT and DOWN */
} bt_mapc_set_folder_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_result_enum result;
    kal_uint8          mas_id;  /* Range 0~255 */
    bt_map_addr_struct addr;
} bt_mapc_set_folder_cnf_struct;

/* Get the floder listing size */
typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_addr_struct addr;
    kal_uint8          mas_id;  /* Range 0~255 */
} bt_mapc_get_folder_listing_size_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_result_enum result;
    bt_map_addr_struct addr;
    kal_uint8          mas_id;  /* Range 0~255 */
    kal_uint16         list_size;
} bt_mapc_get_folder_listing_size_cnf_struct;

/* Get the folder listing request*/
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8          mas_id;  /* Range 0~255 */
    bt_map_addr_struct addr;
    kal_uint16         list_size;
    kal_uint16         list_offset;
} bt_mapc_get_folder_listing_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_result_enum result;
    kal_uint8          mas_id;  /* Range 0~255 */
    bt_map_addr_struct addr;
    kal_uint16         list_size;
    kal_uint16         data_size;
    kal_uint8          file[BT_MAP_MAX_TEMP_FILE_NAME_LEN + 2]; /* UCS2, null terminated */
} bt_mapc_get_folder_listing_cnf_struct;

/* Get the message listing size */
typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_addr_struct addr;
    kal_uint8          mas_id;  /* Range 0~255 */
    kal_uint8          child_folder[BT_MAP_MAX_FOLDER_NAME_LEN + 2]; /* UCS2, null terminated, empty if current folder */
} bt_mapc_get_message_listing_size_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_result_enum result;
    bt_map_addr_struct addr;
    kal_uint8          mas_id;  /* Range 0~255 */
    kal_uint16         list_size;
    kal_bool           unread;
    kal_uint8          datetime[BT_MAP_MAX_DATETIME_STR_LEN + 1]; /* UTF8, zero-terminated string */
} bt_mapc_get_message_listing_size_cnf_struct;

/* Get the message listing */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8                 mas_id;  /* Range 0~255 */
    bt_map_addr_struct        addr;
    kal_uint8                 child_folder[BT_MAP_MAX_FOLDER_NAME_LEN + 2];/* UCS2, null terminated, empty if current folder */
    kal_uint16                list_size;
    kal_uint16                list_offset;
    kal_uint8                 max_subject_len;  /* Range 1~255 */
    kal_uint32                mask;
    kal_uint8                 filter_msg;
    kal_uint8                 filter_begin[BT_MAP_MAX_DATE_STR_LEN + 1];/* UTF8 zero-terminated string */
    kal_uint8                 filter_end[BT_MAP_MAX_DATE_STR_LEN + 1];  /* UTF8 zero-terminated string */
    bt_map_filter_status_enum filter_status;
    kal_uint8                 filter_rec[BT_MAP_MAX_CONTACT_STR_LEN];   /* UTF8 zero-terminated string */
    kal_uint8                 filter_orig[BT_MAP_MAX_CONTACT_STR_LEN];  /* UTF8 zero-terminated string */
    bt_map_filter_prio_enum   filter_prio;
} bt_mapc_get_message_listing_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_result_enum result;
    kal_uint8          mas_id;  /* Range 0~255 */
    bt_map_addr_struct addr;
    kal_bool           unread;  /* TRUE: unread, FALSE: read */
    kal_uint8          datetime[BT_MAP_MAX_DATETIME_STR_LEN + 1];/* UTF8, zero-terminated string */
    kal_uint16         list_size;
    kal_uint16         data_size;
    kal_uint8          file[BT_MAP_MAX_TEMP_FILE_NAME_LEN + 2];/* UCS2, null terminated */
} bt_mapc_get_message_listing_cnf_struct;


/* Get message request */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8                mas_id; /* Range 0~255 */
    bt_map_addr_struct       addr;
    kal_uint8                handle[MAP_MAX_HANDLE_STR_UCS2_LEN + 2]; /* UCS2, null terminated */
    kal_bool                 attachment; /* TRUE: has attachment, FALSE: no attachment */
    bt_map_charset_enum      charset;
    bt_map_fraction_req_enum fraction_req;
} bt_mapc_get_message_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_result_enum       result;
    kal_uint8                mas_id; /* Range 0~255 */
    bt_map_addr_struct       addr;
    bt_map_fraction_rsp_enum fraction_rsp;
    kal_uint16               data_size;
    kal_uint8                file[BT_MAP_MAX_TEMP_FILE_NAME_LEN + 2]; /* UCS2, null terminated */
} bt_mapc_get_message_cnf_struct;

/* Set notification registration request */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8          mas_id;  /* Range 0~255 */
    bt_map_addr_struct addr;
    kal_bool           on;  /* TRUE: on, FALSE: off */
} bt_mapc_set_notify_registration_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_result_enum result;
    kal_uint8 mas_id; /* Range 0~255 */
    bt_map_addr_struct addr;
} bt_mapc_set_notify_registration_cnf_struct;

/* Set message status */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8              mas_id;  /* Range 0~255 */
    bt_map_addr_struct     addr;
    kal_uint8              handle[MAP_MAX_HANDLE_STR_UCS2_LEN + 2]; /* UCS2, null terminated */
    bt_map_msg_status_enum status;
} bt_mapc_set_message_status_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_result_enum result;
    kal_uint8          mas_id;  /* Range 0~255 */
    bt_map_addr_struct addr;
} bt_mapc_set_message_status_cnf_struct;

/* Push the message to the MSE */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8           mas_id;  /* Range 0~255 */
    bt_map_addr_struct  addr;
    kal_uint8           child_folder[BT_MAP_MAX_FOLDER_NAME_LEN + 2]; /* UCS2, null terminated, empty if current folder */
    bt_map_sent_op_enum sent_op;
    kal_bool            retry;  /* FALSE: no retry, TRUE: retry */
    bt_map_charset_enum charset;
    kal_uint8           file[BT_MAP_MAX_TEMP_FILE_NAME_LEN + 2]; /* UCS2, null terminated */
    kal_uint16          data_size;
} bt_mapc_push_message_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_result_enum result;
    kal_uint8          mas_id;  /* Range 0~255 */
    bt_map_addr_struct addr;
    kal_uint8          handle[MAP_MAX_HANDLE_STR_UCS2_LEN + 2];  /* UCS2 , null terminated */
} bt_mapc_push_message_cnf_struct;

/* Update the input inbox */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8          mas_id;  /* Range 0~255 */
    bt_map_addr_struct addr;
} bt_mapc_update_inbox_req_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_result_enum result;
    kal_uint8          mas_id;  /* Range 0~255 */
    bt_map_addr_struct addr;
} bt_mapc_update_inbox_cnf_struct;

/* MCE sends the Abort request */
typedef struct
{
    LOCAL_PARA_HDR
    bt_map_addr_struct addr;
    kal_uint8          mas_id;  /* Range 0~255 */
} bt_mapc_abort_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    bt_map_result_enum result;
    bt_map_addr_struct addr;
    kal_uint8          mas_id;  /* Range 0~255 */
} bt_mapc_abort_cnf_struct;

/* MCE receive the MSE notification event */
typedef struct
{
    LOCAL_PARA_HDR 
    kal_uint8          mas_id;  /* Range 0~255 */
    bt_map_addr_struct addr;
    kal_uint16         data_size;
    kal_uint8          file[BT_MAP_MAX_TEMP_FILE_NAME_LEN + 2]; /* UCS2, null terminated */
} bt_mapc_mns_send_event_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR 
    bt_map_result_enum result;
    kal_uint8          mas_id;  /* Range 0~255 */
    bt_map_addr_struct addr;
} bt_mapc_mns_send_event_rsp_struct;

/*------------------------- End of the MAP Client -----------------------*/
#endif /* __BT_MAP_CLIENT__ */

#endif /* __BLUETOOTH_STRUCT_H_ */ 
