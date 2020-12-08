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
 * bt_hfg_struct.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   struct of local parameter for hfg adp sap
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef BT_HFG_STRUCT_H
#define BT_HFG_STRUCT_H

/* RHR ADD */
#include "bt_dm_struct.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
/* RHR ADD end */

/***************************************************************************** 
* Definations
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/
#define HFG_CONNECT_GUARD_TIMER         20000 /* 20 sec */
#define HFG_SCO_CONNECT_GUARD_TIMER     5000000  /* 5 sec */

/***************************************************************************** 
* Structure
*****************************************************************************/
typedef enum
{
	hfg_idle, /* hfg_deactivated */
	hfg_activated,
	hfg_connected,
	hfg_sco_connected,

	hfg_activating,
	hfg_deactivating,
	hfg_connecting,
	hfg_disconnecting,
	hfg_sco_connecting,
	hfg_sco_disconnecting,
	hfg_authorizing		
	
} bt_hfg_state;

typedef enum {
    hfg_sim_none,
    hfg_sim_1 = 0x01,
    hfg_sim_2 = 0x02,
    hfg_sim_3 = 0x04,
    hfg_sim_4 = 0x08,
    hfg_sim_total
} bt_hfg_sim_card;

typedef enum
{
	hfg_connect_accept_cnf_result_accepted,
	hfg_connect_accept_cnf_result_rejected,
	hfg_connect_accept_cnf_total

} bt_hfg_connect_accept_confirm_enum;

typedef enum {
    hsg_no_call,
    hsg_incoming_call = 0x01,
    hsg_outgoing_call = 0x02,
    hsg_in_call = 0x04
} bt_hsg_call_status;

typedef kal_uint32 (*HSCheckCallStatus)(void);

typedef struct
{
	LOCAL_PARA_HDR
    HSCheckCallStatus check_call;
} bt_hfg_activate_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16 result;
} bt_hfg_activate_cnf_struct;


typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16 result;
} bt_hfg_deactivate_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32 sim;
    kal_bool hs_conn;
} bt_hfg_connect_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16  result;
    bt_dm_addr_struct bt_addr;
    kal_uint32 connection_id;
} bt_hfg_connect_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;    
} bt_hfg_connect_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
    kal_bool hs_conn;
} bt_hfg_connect_ind_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_hfg_connect_accept_confirm_enum result;
    bt_dm_addr_struct bt_addr;
    kal_uint32 connection_id;
    kal_uint32 sim;
} bt_hfg_connect_ind_res_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;    
} bt_hfg_disconnect_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16          result;
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hfg_disconnect_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint32   connection_id;
} bt_hfg_disconnect_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	       connection_id;
} bt_hfg_sco_connect_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16			result;
	kal_uint8 	       connection_id;
} bt_hfg_sco_connect_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	       connection_id;
} bt_hfg_sco_connect_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	//bt_dm_addr_struct bt_addr;
	kal_uint8 	       connection_id;
} bt_hfg_sco_disconnect_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint16 	       result;
	kal_uint8 	       connection_id;
} bt_hfg_sco_disconnect_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	       connection_id;
} bt_hfg_sco_disconnect_ind_struct;

typedef enum
{
	BT_HFG_RESULT_OK = 0,
	BT_HFG_RESULT_FAIL,
	BT_HFG_RESULT_CHIP_REASON,
	BT_HFG_RESULT_TIMEOUT,
	BT_HFG_RESULT_MED_ERROR /* Error cause by MED state error, not BT */
} BT_HFG_RESULT_ENUM;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	        gain;
    kal_uint32          connection_id;
} bt_hfg_speaker_gain_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16          result;
    kal_uint32          connection_id;
} bt_hfg_speaker_gain_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	        gain;
    kal_uint32          connection_id;
} bt_hfg_speaker_gain_ind_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	        gain;
    kal_uint32          connection_id;
} bt_hfg_mic_gain_req_struct;

typedef struct
{
	LOCAL_PARA_HDR
    kal_uint16          result;
    kal_uint32          connection_id;
} bt_hfg_mic_gain_cnf_struct;

typedef struct
{
	LOCAL_PARA_HDR
	kal_uint8 	        gain;
    kal_uint32          connection_id;
} bt_hfg_mic_gain_ind_struct;

/*****************************************************************************              
* Extern Global Variable                                                                    
*****************************************************************************/             
                                                                                           
/*****************************************************************************              
* Functions                                                                    
*****************************************************************************/     



#endif//BT_HFG_STRUCT_H

