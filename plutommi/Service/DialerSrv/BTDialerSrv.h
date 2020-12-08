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
 * BtDialersrv.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for BT CM main application flow and utilities.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================*/
#include "BTDialerSrvGprot.h"

#ifndef __BTDIALER_SRV_H__
#define __BTDIALER_SRV_H__

#ifdef __BT_DIALER_SUPPORT__

 /* AtCommands type*/
typedef  enum
{
	/**  */
	SRV_BT_DIALER_AT_MICROPHONE_GAIN  = 0x0100,

	/**  */
	SRV_BT_DIALER_AT_SPEAKER_GAIN      =   0x0101,

	/**  */
	SRV_BT_DIALER_AT_KEYPAD_CONTROL     =  0x0102,
	/* Command to answer incoming call. No parameters. */
	SRV_BT_DIALER_AT_ANSWER =	0x0200, 

	/** Command to dial a number from memory. The AtHandsfreeCmd.dial parameter is
	 *  valid. 
	 */
	SRV_BT_DIALER_AT_DIAL_MEMORY,
	/** Command to dial a phone number. The AtHandsfreeCmd.dial parameter is valid.
	 */
	SRV_BT_DIALER_AT_DIAL_NUMBER,
	/** This command allows control of the Call Waiting supplementary service. 
	 *  An unsolicited result is used to indicate the presence of a call. The
	 *  "wait" parameter is used with this command.
	 */
	SRV_BT_DIALER_AT_CALL_WAIT_NOTIFY,
	/** This command allows calls can be put on hold, recovered, released, added 
	 *  to conversation, and transferred. The test command can be issued to request
	 *  a list of supported operations. The AtHandsfreeCmd.hold parameter is valid.
	 */
	SRV_BT_DIALER_AT_CALL_HOLD,
	/** This command instructs the ME to hangup the current GSM call. There are
	 *  no parameters.
	 */
	SRV_BT_DIALER_AT_HANG_UP,

	/** The test command is used to retrieve the mapping between each indicator
	 *  supported by the ME and its corresponding range and order index. The TE
	 *  can retrieve the current status of the indicators by issuing a read
	 *  command. There are no parameters to this command.
	 */
	SRV_BT_DIALER_AT_INDICATORS,

	/** This command enables/disables presentation of the calling line identity
	 *  (CLI) to the subscriber. An unsolicited result is used to indicate the
	 *  identity to the TE. The "callId" parameter is used with this command.
	 */
	SRV_BT_DIALER_AT_CALL_ID,

	/** The TE may test and read the status of the the ME indicators. Received
	 *  unsolicited indicator result messages are indicated by AT_INDICATOR_EVENT.
	 */
	SRV_BT_DIALER_AT_EVENT_REPORTING,

	/** This unsolicited result code is used to report an indicator status change.
	 */
	SRV_BT_DIALER_AT_INDICATOR_EVENT,

	/** This command allows the transmission of DTMF and arbitrary tones. These
	 *  tones may be used (for example) when announcing the start of a recording
	 *  period. The "dtmf" parameter is used with this command.
	 */
	SRV_BT_DIALER_AT_GENERATE_DTMF_TONE,

	/** Command used for requesting the phone number corresponding to the last
	 *  voice tag recorded in the ME. There are no parameters to this command.
	 */
	SRV_BT_DIALER_AT_VOICE_TAG,

	/** This command is used to call the last phone number dialed. On reception,
	 *  the ME shall set up a voice call to the last phone number dialed. There
	 *  are no parameters to this command.
	 */
	SRV_BT_DIALER_AT_REDIAL,

	/** This command enables/disables the voice recognition function in the ME.
	 *  The unsolicited result code is used to indicate when the voice recognition
	 *  setting was changed autonomously on the ME. The "vrec" parameter is used
	 *  with this command.
	 */
	SRV_BT_DIALER_AT_VOICE_RECOGNITION,

	/** This command and result are used for exchanging the supported features
	 *  list between the TE and ME. The "features" parameter is used with this
	 *  command.
	 */
	SRV_BT_DIALER_AT_SUPPORTED_FEATURES, 

	/** This command is issued to disable any Echo Canceling and Noise Reduction
	 *  functions embedded in the ME. There are no parameters to this command.
	 */
	SRV_BT_DIALER_AT_ECHO_C_AND_NOISE_R,

	/** An unsolicited result code issued by the ME to indicate to the TE that
	 *  the in-band ring tone setting has been locally changed. The TE may react
	 *  accordingly by changing its own alert method.
	 */
	SRV_BT_DIALER_AT_IN_BAND_RING_TONE,

	/** This command is used by the TE to read the current "Response and Hold"
	 *  state of the ME. This command may also be used to set the response
	 *  and hold state on the ME of an incoming call. The unsolicited result
	 *  code is used to indicate when an incoming call is either put on hold,
	 *  accepted or rejected. The "btrh" parameters are used with this command.
	 */
	SRV_BT_DIALER_AT_RESPONSE_AND_HOLD,    

	/** This command is used to request the Subscriber Number information from
	 *  the ME. The result provides "subscriberNum" parameters.
	 */
	SRV_BT_DIALER_AT_SUBSCRIBER_NUM,       
	/** This command is used to request a list of the current calls. The result
	 *  indicates each current call and its information. The "currentCall"
	 *  parameter is used with the result of this command.
	 */
	SRV_BT_DIALER_AT_LIST_CURRENT_CALLS,

	/** This command is used for reading, selecting and registering the network
	 *  operator. The response is used to return the current mode and the currently
	 *  selected operator.  The "networkOper" and "networkOper_read" parameters
	 *  are used with this command.
	 */
	SRV_BT_DIALER_AT_NETWORK_OPERATOR,

	/**Set Network operator format.
	 */
	SRV_BT_DIALER_AT_SET_NETWORK_OPERATOR_FORMAT,

}srv_bt_dialer_at_cmd_type_enum;


typedef enum
{
	SRV_BT_DIALER_STATE_IDLE,
	SRV_BT_DIALER_STATE_ACTIVATING,
	SRV_BT_DIALER_STATE_ACTIVATED,
	SRV_BT_DIALER_STATE_CONNECTING,
	SRV_BT_DIALER_STATE_CONNECTED,
	SRV_BT_DIALER_STATE_DISCONNECTING,
	SRV_BT_DIALER_STATE_DISCONNECTED,
    SRV_BT_DIALER_STATE_DEACTIVATING,
    SRV_BT_DIALER_STATE_DEACTIVATED,
	SRV_BT_DIALER_STATE_INVALID
	
} srv_bt_dialer_state_enum;

/*---------------------------------------------------------------------------
 * Hold action enum
 *---------------------------------------------------------------------------*/
typedef enum
{
	SRV_BT_DIALER_AT_HOLD_RELEASE_HELD_CALLS,
	
	/** Releases all active calls (if any exist) and accepts the other
	 *  (held or waiting) call. If "call" is specified, will release the
	 *  specific call.
	 */
	SRV_BT_DIALER_AT_HOLD_RELEASE_ACTIVE_CALLS,

	/** Places all active calls (if any exist) on hold and accepts the other
	 *  (held or waiting) call. If "call" is specified, places all active calls
	 *  on hold except the specified call.
	 */
	SRV_BT_DIALER_AT_HOLD_HOLD_ACTIVE_CALLS,

	/** Adds a held call to the conversation. 
	 */
	SRV_BT_DIALER_AT_HOLD_ADD_HELD_CALL,

	/** Connects the two calls and disconnects the AG from both calls
	 *  (Explicit Call Transfer).
	 */
	SRV_BT_DIALER_AT_HOLD_EXPLICIT_TRANSFER,

	/* End of AtHoldAction */

}srv_bt_dailer_at_cmd_hold_action_enum;

/*---------------------------------------------------------------------------
 * Sending Handsfree command
 *---------------------------------------------------------------------------*/
typedef union {   
 
    /* AT_DIAL_NUMBER, AT_DIAL_MEMORY */   
    struct {   
        const char     *number;   
    } dial;   
   
    /* AT_CALL_WAIT_NOTIFY */   
    struct {   
        /* Enable/Disable the presentation of the AT_CALL_WAIT_NOTIFY
         * unsolicited result code.   
         */   
        U8              notify;   
    } wait;   
   
    /* AT_CALL_HOLD */   
    struct {   
        /* Call hold procedure to perform. */   
        srv_bt_dailer_at_cmd_hold_action_enum    action;   
   
        /* If "action" is AT_HOLD_RELEASE_ACTIVE_CALLS or    
         * AT_HOLD_HOLD_ACTIVE_CALLS, this value can be used to specify
         * the index (1 - 9) of a specific call to address.   
         */   
        U8              call;   
    } hold;   
   
    /* AT_CALL_ID */   
    struct {   
        BOOL            enabled;   
    } callId;   
   
    /* AT_EVENT_REPORTING */   
    struct {   
        U8              mode;   
        U8              ind;   
    } report;   
           
    /* AT_GENERATE_DTMF_TONE */   
    struct {   
        U8              tone;   
    } dtmf;   
   
    /* AT_VOICE_RECOGNITION */   
    struct {   
        BOOL            enabled;   
    } vrec;   
   
    /* AT_RESPONSE_AND_HOLD */   
    struct {   
        srv_bt_dialer_AtResponseHold_enum  setting;   
		srv_bt_dialer_AtResponseHoldtype_enum  at_type;
    } btrh;   
   
    /* AT_NETWORK_OPERATOR */   
    struct {   
        /* 0 = automatic, 1 = manual, 2 = deregister, 3 = set format only, 
         * 4 = manual/automatic.   
         */   
        U8              mode;   
   
        /* Format of "oper" parameter (0-3) */   
        srv_bt_dialer_AtOperFormat_enum    format;   
    } networkOper;   
   
} srv_bt_dialer_AtHfCmd_struct;   

typedef struct _srv_bt_dialer_send_at_cmd_struct
{
	srv_bt_dialer_AtHfCmd_struct *btd_hf_cmd;
	srv_bt_dialer_at_cmd_type_enum type;
	struct _srv_bt_dialer_send_at_cmd_struct *Flink;
} srv_bt_dialer_send_at_cmd_struct;

#define SRV_BT_DIALER_AT_CMD_EVENT	20

typedef struct
{
	MMI_BOOL hs_conn;
	MMI_BOOL alloc;
	MMI_BOOL bsir_enable;
	MMI_BOOL ciev_service;	
	MMI_BOOL bvra_enable;
	MMI_BOOL                callId;           /* State of caller id nofitication  */
	MMI_BOOL                callWaiting;      /* State of call waiting            */
	
	U8 ciev_call;
	U8 callsetup;
	U8 callheld;	
	U8 ciev_signal;
	U8 ciev_roam;
	U8 ciev_battchg;
	U8 btrh_n;	
	U8                  micGain;          /* Current microphone gain          */
    U8                  speakerGain;      /* Current speaker gain             */
	
	U16 ind_mask;
	U32 cm_conn_id;	
	
	int srv_hd;
	int conn_id;
	int state;

    srv_bt_cm_bt_addr bd_addr;
	srv_bt_dialer_notify_hf_event cb_ptr;
	srv_bt_dialer_send_at_cmd_struct *hf_cmd; //send AT command
	srv_bt_dialer_notify_event_struct *hf_result; //Parse At command

} srv_bt_dialer_g_struct;

#define MMI_HF_INVALID_CONN_ID 			 0xFF
#define MMI_HF_CONN_CNF 				 1
#define srv_bt_dialer_IsListEmpty(ListHead) (((ListHead)->Flink == (ListHead)))
#define srv_bt_dialer_GetHeadList(ListHead) ((ListHead)->Flink)
#define MMI_RET_OK          (0)         /* the return value of mmi_ret */
typedef unsigned int U32;

#define SRV_BT_DIALER_LOG(x)                            \
   {                                                    \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x);                 \
   }
#define SRV_BT_DIALER_LOG1(x, x1)                       \
   {                                                    \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1);             \
   }
#define SRV_BT_DIALER_LOG2(x, x1, x2)                   \
   {                                                    \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2);         \
   }

#define SRV_BT_DIALER_LOG3(x, x1, x2, x3)               \
   {                                                    \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2, x3);     \
   }

void srv_bt_dialer_send_activate_req(void);
void srv_bt_dialer_send_deactivate_req(void);
void srv_bt_dialer_connect_ind(void *msg);
void srv_bt_dialer_send_disconnect_req(U32 cm_conn_id);
MMI_BOOL srv_bt_dialer_disconnect_ind(void* msg);
void srv_bt_dialer_HfExecuteNextCommand(void);
void srv_bt_dialer_add_node_to_list(srv_bt_dialer_AtHfCmd_struct *cmd, srv_bt_dialer_at_cmd_type_enum type);
static void srv_bt_dialer_send_ilm( void *local_para_ptr, msg_type msg_id, module_type dst_mod);
void srv_bt_dialer_InsertTailList(srv_bt_dialer_send_at_cmd_struct* entry);
void srv_bt_dialer_send_connect_ind_rsp(int accept);
void srv_bt_dialer_volume_gain_req(int gain);
void srv_bt_dialer_free_atcmd_queue(MMI_BOOL req_queue);

MMI_BOOL srv_bt_dialer_volume_gain_cnf_hdlr(void *msg);
MMI_BOOL srv_bt_dialer_vgm_ind_hdlr(void *msg);
MMI_BOOL srv_bt_dialer_vgs_ind(void *msg);
MMI_BOOL srv_bt_dialer_activate_cnf_hdlr(void *msg);
MMI_BOOL srv_bt_dialer_deactivate_cnf_hdlr(void *msg);
MMI_BOOL srv_bt_dialer_connect_cnf_hdlr(void *msg);
MMI_BOOL srv_bt_dialer_disconnect_cnf_hdlr(void *msg);
mmi_ret srv_bt_dialer_hf_proc_func(mmi_event_struct *evt);
srv_bt_dialer_send_at_cmd_struct * srv_bt_dialer_HfGetCurrentCommand(void);

void srv_bt_dialer_ata_req(void);
MMI_BOOL srv_bt_dialer_ata_cnf_hdlr(void* msg);
void srv_bt_dialer_atd_req(U8 size, U8* number );
MMI_BOOL srv_bt_dialer_atd_cnf_hdlr(void* msg);
void srv_bt_dialer_atmem_req(U32 index );
MMI_BOOL srv_bt_dialer_atmem_cnf_hdlr(void* msg);
void srv_bt_dialer_atbldn_req(void );
MMI_BOOL srv_bt_dialer_atbldn_cnf_hdlr(void* msg);
void srv_bt_dialer_atchup_req(void );
MMI_BOOL srv_bt_dialer_atchup_cnf_hdlr(void* msg);
void srv_bt_dialer_atcmee_req(MMI_BOOL enable);
MMI_BOOL srv_bt_dialer_atcmee_cnf_hdlr(void* msg);
void srv_bt_dialer_atnrec_req(void );
MMI_BOOL srv_bt_dialer_atnrec_cnf_hdlr(void* msg);
void srv_bt_dialer_atvts_req(U8 dtmf );
MMI_BOOL srv_bt_dialer_atvts_cnf_hdlr(void* msg);
MMI_BOOL srv_bt_dialer_vgs_cnf_hdlr(void *msg);
void srv_bt_dialer_vgs_req(int gain);

void srv_bt_dialer_atccwa_req(U8 enable);
MMI_BOOL srv_bt_dialer_atccwa_cnf_hdlr(void *msg);
MMI_BOOL srv_bt_dialer_atclip_cnf_hdlr(void *msg);
void srv_bt_dialer_atclip_req(int enable);
MMI_BOOL srv_bt_dialer_atchld_cnf_hdlr(void *msg);
void srv_bt_dialer_atchld_req(U8 n);
MMI_BOOL srv_bt_dialer_volume_gain_cnf_hdlr(void *msg);
void srv_bt_dialer_set_atcops_req(void);
MMI_BOOL srv_bt_dialer_set_atcops_cnf_hdlr(void *msg);
void srv_bt_dialer_atcops_req(void);
MMI_BOOL srv_bt_dialer_atcops_cnf_hdlr(void *msg);
MMI_BOOL srv_bt_dialer_atcnum_cnf_hdlr(void *msg);
void srv_bt_dialer_atcnum_req(void);
void srv_bt_dialer_atbinp_req(void);
MMI_BOOL srv_bt_dialer_atbinp_cnf_hdlr(void *msg);
void srv_bt_dialer_atbtrh_read_req(void);
MMI_BOOL srv_bt_dialer_atbtrh_read_cnf_hdlr(void *msg);
void srv_bt_dialer_atbvra_req(MMI_BOOL enable);
MMI_BOOL srv_bt_dialer_atbvra_cnf_hdlr(void *msg);
void srv_bt_dialer_atbtrh_set_req(int n);
MMI_BOOL srv_bt_dialer_atbtrh_set_cnf_hdlr(void *msg);
void srv_bt_dialer_atclcc_req(void);
MMI_BOOL srv_bt_dialer_atclcc_cnf_hdlr(void *msg);
MMI_BOOL srv_bt_dialer_bsir_ind(void *msg);
MMI_BOOL srv_bt_dialer_ciev_service_ind(void *msg);
MMI_BOOL srv_bt_dialer_ciev_call_ind(void *msg);
MMI_BOOL srv_bt_dialer_callsetup_ind(void *msg);
MMI_BOOL srv_bt_dialer_callheld_ind(void *msg);

MMI_BOOL srv_bt_dialer_ciev_signal_ind(void *msg);
MMI_BOOL srv_bt_dialer_ciev_roam_ind(void *msg);
MMI_BOOL srv_bt_dialer_ciev_battchg_ind(void *msg);
MMI_BOOL srv_bt_dialer_clip_ind(void *msg);
MMI_BOOL srv_bt_dialer_ccwa_ind(void *msg);
MMI_BOOL srv_bt_dialer_bvra_ind(void *msg);
MMI_BOOL srv_bt_dialer_btrh_ind(void *msg);
static void srv_bt_dailer_cm_notify_hdlr(U32 event, void *args);
int srv_bt_dialer_convert_error_code(int error);
MMI_BOOL srv_bt_dialer_vgm_cnf_hdlr(void *msg);
MMI_BOOL srv_bt_dialer_ring_ind_hdlr(void *msg);
void srv_bt_dialer_vgm_req(int gain);
void srv_bt_dialer_send_connect_req(srv_bt_cm_bt_addr bd_addr);

void srv_bt_dialer_dump_trace_info(void *buf, int buf_len);
void srv_bt_dialer_handle_pending_at_cmd(void);
/*Interface to send AT command of any type*/
int srv_bt_dialer_send_at_command(  int srv_hd,
								    srv_bt_dialer_at_cmd_type_enum type,
                                    srv_bt_dialer_AtHfCmd_struct *btd_hf_cmd); 

extern void srv_bt_dialer_init(void);
extern MMI_BOOL srv_bt_dialer_vol_control_callback(U8 volume, MMI_BOOL is_mute);
extern void srv_bt_dialer_deinit(void);

#endif /*__BT_DIALER_SUPPORT__*/

#endif /*__BTDIALER_SRV_H__*/