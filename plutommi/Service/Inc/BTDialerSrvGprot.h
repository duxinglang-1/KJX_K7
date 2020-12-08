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
 *   BTDialerSrvGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Interface file to let user use inet service functionality
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================*/

#ifndef __BTDIALER_SRV_GPROT_H__
#define __BTDIALER_SRV_GPROT_H__

#ifdef __BT_DIALER_SUPPORT__

#include "bluetooth_bm_struct.h"
#include "bluetooth_struct.h"
#include "BtcmSrvGprot.h"


#define SRV_BT_DIALER_AT_MAX_INDICATORS 9
/*--------------------------------------------------------------------------
 * AtHoldFlag type
 *-------------------------------------------------------------------------*/
typedef enum _srv_bt_dialer_AtHoldFlag{

	/** Releases all held calls or sets User Determined User Busy
	 *  (UDUB) for a waiting call.
	 */
	SRV_BT_DIALER_AT_FLAG_HOLD_RELEASE_HELD_CALLS  =   0x01,

	/** Releases all active calls (if any exist) and accepts the other
	 *  (held or waiting) call.
	 */
	SRV_BT_DIALER_AT_FLAG_HOLD_RELEASE_ACTIVE_CALLS    =0x02,

	/** Releases a specific call. */
	SRV_BT_DIALER_AT_FLAG_HOLD_RELEASE_SPECIFIC_CALL   =0x04,

	/** Places all active calls (if any exist) on hold and accepts the
	 *  other (held or waiting) call.
	 */
	SRV_BT_DIALER_AT_FLAG_HOLD_HOLD_ACTIVE_CALLS       =0x08,

	/** Places a specific call on hold. */
	SRV_BT_DIALER_AT_FLAG_HOLD_HOLD_SPECIFIC_CALL      =0x10,

	/** Adds a held call to the conversation. */
	SRV_BT_DIALER_AT_FLAG_HOLD_ADD_HELD_CALL           =0x20,

	/** Connects the two calls and disconnects the AG from
	 * both calls (Explicit Call Transfer).
	 */
	SRV_BT_DIALER_AT_FLAG_HOLD_EXPLICIT_TRANSFER       =0x40

	/* End of AtHoldFlag */
}srv_bt_dialer_AtHoldFlag_enum;



/*---------------------------------------------------------------------------
 * AtCallState
 *
 *--------------------------------------------------------------------------*/
typedef enum _srv_bt_dialer_AtCallState{
	/** Active */
	SRV_BT_DIALER_ATCS_ACTIVE ,

	/** Held */
	SRV_BT_DIALER_ATCS_HELD,

	/**  Dialing (Mobile Originated only) */
	SRV_BT_DIALER_ATCS_DIALING,

	/** Alerting (Mobile Originated only) */
	SRV_BT_DIALER_ATCS_ALERTING,

	/** Incoming (Mobile Terminated only) */
	SRV_BT_DIALER_ATCS_INCOMING,

	/** Waiting (Mobile Terminated only) */
	SRV_BT_DIALER_ATCS_WAITING

/* End of AtCallState */
}srv_bt_dialer_AtCallState_enum;

/*---------------------------------------------------------------------------
 * AtResponseHold
 *
 *--------------------------------------------------------------------------*/
typedef enum _srv_bt_dialer_AtResponseHold {

	/** Put the incoming call on hold (or the incoming call was put on hold).
	 */
	SRV_BT_DIALER_ATRH_ON_HOLD,

	/** Accept the incoming held call (or the call on hold was accepted).
	 */
	SRV_BT_DIALER_ATRH_ACCEPT_HELD,

	/** Reject the incoming held call (or the call on hold was rejected).
	 */
	SRV_BT_DIALER_ATRH_REJECT_HELD

	/* End of AtResponseHold */
}srv_bt_dialer_AtResponseHold_enum;



/*---------------------------------------------------------------------------
 * AtResponseHold AT TYPE
 *
 *--------------------------------------------------------------------------*/
typedef enum _srv_bt_dialer_AtResponseHold_type {
	/*Bluetooth Response hold feature
	+BTRH: <n>
	<n>: 0,1,2 entered as integer value, where
	0 = Incoming call is put on hold in the AG
	1 = Held incoming call is accepted in the AG
	2 = Held incoming call is rejected in the AG
	*/
	SRV_BT_DIALER_ATRESHOLD_READ,
	/*Bluetooth Response hold feature
	AT+BTRH=<n>
	<n>: 0, 1, 2 entered as integer values, where
	0 = Put Incoming call on hold
	1 = Accept a held incoming call
	2 = Reject a held incoming call
	*/
	SRV_BT_DIALER_ATRESHOLD_SET,

	/* End of AtResponseHold */
}srv_bt_dialer_AtResponseHoldtype_enum;



/*---------------------------------------------------------------------------
 * AtOperFormat
 *
 *---------------------------------------------------------------------------*/
typedef enum _srv_bt_dialer_AtOperFormat{

	/** */
	SRV_BT_DIALER_ATOF_LONG_ALPHANUM,

	/** */
	SRV_BT_DIALER_ATOF_SHORT_ALPHANUM,

	/** */
	SRV_BT_DIALER_ATOF_NUMERIC

	/* End of AtOperFormat */
}srv_bt_dialer_AtOperFormat_enum;

/* End of AtError */
/*---------------------------------------------------------------------------
 * Number format
 *--------------------------------------------------------------------------*/
typedef enum _srv_bt_dialer_AtNumberFormat{
	SRV_BT_DIALER_ATNUM_TYPE_UNKNOWN        =  0x80,
	SRV_BT_DIALER_ATNUM_TYPE_INTERNATIONAL   = 0x90,
	SRV_BT_DIALER_ATNUM_TYPE_NATIONAL        = 0xA0,
	SRV_BT_DIALER_ATNUM_TYPE_NETWORK_SPEC     =0xB0,
	SRV_BT_DIALER_ATNUM_TYPE_DEDICATED_ACC    =0xC0,

	SRV_BT_DIALER_ATNUM_PLAN_UNKNOWN          =0x00,
	SRV_BT_DIALER_ATNUM_PLAN_ISDN_TELEPHONY   =0x01,
	SRV_BT_DIALER_ATNUM_PLAN_DATA_NUMBERING   =0x03,
	SRV_BT_DIALER_ATNUM_PLAN_TELEX_NUMBERING  =0x04,
	SRV_BT_DIALER_ATNUM_PLAN_NATIONAL         =0x08,
	SRV_BT_DIALER_ATNUM_PLAN_PRIVATE          =0x09,

	/* Commonly used formats */
	SRV_BT_DIALER_ATNUM_INTERNATIONAL_ISDN    =(SRV_BT_DIALER_ATNUM_TYPE_INTERNATIONAL|SRV_BT_DIALER_ATNUM_PLAN_ISDN_TELEPHONY),
	SRV_BT_DIALER_ATNUM_ISDN_TELEPHONY        =(SRV_BT_DIALER_ATNUM_TYPE_UNKNOWN|SRV_BT_DIALER_ATNUM_PLAN_ISDN_TELEPHONY),
	SRV_BT_DIALER_ATNUM_NATIONAL_ISDN         =(SRV_BT_DIALER_ATNUM_TYPE_NATIONAL|SRV_BT_DIALER_ATNUM_PLAN_ISDN_TELEPHONY)
}srv_bt_dialer_AtNumberFormat_enum;

/*---------------------------------------------------------------------------
*Call state - Check this if call is active or not
---------------------------------------------------------------------------*/ 
typedef enum _srv_bt_dialer_call_ind_enum
{
	/*state if call no call is made or call is rejected successfully*/
	SRV_BT_DIALER_CALL_NOT_ACTIVE,
	/*if call is answered successfully*/
	SRV_BT_DIALER_CALL_ACTIVE
}srv_bt_dialer_call_ind_enum;


/*---------------------------------------------------------------------------
*Call setup indication to identify call type[ incoming/outgoing]
*and inbetween call states [e.g. remote party being alerted] 
---------------------------------------------------------------------------*/
typedef enum _srv_bt_dialer_call_setup_ind_enum
{
	/*call setup [inclimg/outgoing] complete
	in both case if 1)Call is successfully active
	OR 2) Calll is rejected*/
	SRV_BT_DIALER_CALL_SETUP_COMPLETE,
	/*Incoming call indication - Call setup process is ongoing*/
	SRV_BT_DIALER_CALL_INCOMING_CALL,	
	/*Outgoing call intitiated successfully - Call setup process is ongoing*/
	SRV_BT_DIALER_CALL_OUTGOING_CALL_INITIATED,
	/*Remote party being alerted in case of outgoing call
	Call setup process is ongoing*/
	SRV_BT_DIALER_CALL_REMOTE_ALERT
	
}srv_bt_dialer_call_setup_ind_enum;

/*---------------------------------------------------------------------------
*Roaming state
---------------------------------------------------------------------------*/
typedef enum _srv_bt_dialer_roaming_state_enum
{
	/*Sim not is roaming*/
	SRV_BT_DIALER_DEVICE_NOT_IN_ROAMING,
	/*Sim is in roaming*/
	SRV_BT_DIALER_DEVICE_IN_ROAMING
}srv_bt_dialer_roaming_state_enum;

/*---------------------------------------------------------------------------
*AG registration state [Service availability indicator]
*Whenever AG(smartphone) chanegs its registration state ,it notifies Application
---------------------------------------------------------------------------*/
typedef enum _srv_bt_dialer_service_availability_state_enum
{
	/*AG doesn't have sim module ready*/
	SRV_BT_DIALER_SERVICE_NOT_AVAILABLE,
	/*Sim module is ready*/
	SRV_BT_DIALER_SERVICE_AVAILABLE
}srv_bt_dialer_service_availability_state_enum;

/*--------------------------------------------------------------------------
 * AtError type
 *
 *     Error types used with AT_EXTENEDED_ERROR result.
 *-------------------------------------------------------------------------*/
typedef U8 srv_bt_dialer_AtError;

#define SRV_BT_DIALER_ATCME_SUCCESS		              0
#define SRV_BT_DIALER_ATCME_NO_CONNECTION             1
#define SRV_BT_DIALER_ATCME_OP_NOT_ALLOWED            3
#define SRV_BT_DIALER_ATCME_OP_NOT_SUPPORTED          4
#define SRV_BT_DIALER_ATCME_PH_SIM_PIN_REQUIRED       5
#define SRV_BT_DIALER_ATCME_SIM_NOT_INSERTED          10
#define SRV_BT_DIALER_ATCME_SIM_PIN_REQUIRED          11
#define SRV_BT_DIALER_ATCME_SIM_PUK_REQUIRED          12
#define SRV_BT_DIALER_ATCME_SIM_FAILURE               13
#define SRV_BT_DIALER_ATCME_SIM_BUSY                  14  
#define SRV_BT_DIALER_ATCME_INCORRECT_PASSWORD        16
#define SRV_BT_DIALER_ATCME_SIM_PIN2_REQUIRED         17
#define SRV_BT_DIALER_ATCME_SIM_PUK2_REQUIRED         18
#define SRV_BT_DIALER_ATCME_MEMORY_FULL               20
#define SRV_BT_DIALER_ATCME_INVALID_INDEX             21
#define SRV_BT_DIALER_ATCME_MEMORY_FAILURE            23
#define SRV_BT_DIALER_ATCME_TEXT_STRING_TOO_LONG      24
#define SRV_BT_DIALER_ATCME_INVALID_CHARS_IN_TEXT_STRING  25
#define SRV_BT_DIALER_ATCME_DIAL_STRING_TOO_LONG      26
#define SRV_BT_DIALER_ATCME_INVALID_CHARS_IN_DIAL_STRING 27
#define SRV_BT_DIALER_ATCME_NO_NETWORK_SERVICE        30
#define SRV_BT_DIALER_ATCME_NETWORK_NOT_ALLOWED       32
#define SRV_BT_DIALER_ATCME_TIMEOUT                   34
#define SRV_BT_DIALER_ATCME_UNKNOWN                   100
#define SRV_BT_DIALER_ATCME_NO_ANSWER			      200

#define SRV_BT_DIALER_SERVICE_UNAVAILABLE             400


/*Application will receive these events*/
typedef enum
{
	SRV_BT_DIALER_EVT_ID_AT_CMD_RSP,
	/*Call waiting notification*/	
	SRV_BT_DIALER_EVT_ID_AT_CALL_WAIT_NOTIFY,
	/*call hold notification*/
	SRV_BT_DIALER_EVT_ID_AT_CALL_HOLD,
    
	SRV_BT_DIALER_EVT_ID_AT_INDICATORS,
	/*call id e.g CLIP notification*/
	SRV_BT_DIALER_EVT_ID_AT_CALL_ID,
	/*various indicators like roam, battery charge, call ind,  etc*/	
	SRV_BT_DIALER_EVT_ID_AT_INDICATOR_EVENT,
	/*Voice Tag Notification*/
	SRV_BT_DIALER_EVT_ID_AT_VOICE_TAG,
	/*Voice Recognition notification*/
	SRV_BT_DIALER_EVT_ID_AT_VOICE_RECOGNITION,
	/*SUpported feature of HF unit*/
	SRV_BT_DIALER_EVT_ID_AT_SUPPORTED_FEATURES,	
	/*In-band ring tone settings notification*/
	SRV_BT_DIALER_EVT_ID_AT_IN_BAND_RING_TONE,
	/*Response and HOLD notificaiton +BTRH command*/
	SRV_BT_DIALER_EVT_ID_AT_RESPONSE_AND_HOLD,
	/*Subscriber number notification*/
	SRV_BT_DIALER_EVT_ID_AT_SUBSCRIBER_NUM,
	/*List current calls notification*/
	SRV_BT_DIALER_EVT_ID_AT_LIST_CURRENT_CALLS,
	/*Network operator information notification*/
	SRV_BT_DIALER_EVT_ID_AT_NETWORK_OPERATOR,
	
}srv_bt_dialer_event_enum;

/*---------------------------------------------------------------------------
 * Parsing handsfree command response
 *---------------------------------------------------------------------------*/


 
/*---------------------------------------------------------------------------
 * AtHandsfreeResult
 * 
 *     This structure is used to specify the parameters associated with
 *     Handsfree results. Handsfree results are sent from the Audio Gateway
 *     to the Handsfree unit. As such, this structure is used by the Audio
 *     Gateway encoder, and the Handsfree unit decoder functions.
 *---------------------------------------------------------------------------*/
typedef union SRV_BT_DIALER_AtHandsfreeResult {

    /* AT_CALL_WAIT_NOTIFY */
    struct {
        const char     *number;
        U8              classmap;
        srv_bt_dialer_AtNumberFormat_enum  type;
    } wait;

    /* AT_CALL_HOLD | AT_TEST */
    struct {
        srv_bt_dialer_AtHoldFlag_enum      flags;
    } hold_test;
        
    /* AT_CALL_ID (AT+CLIP) */
    struct {
        const char     *number;
        srv_bt_dialer_AtNumberFormat_enum  type;
    } callId;

    /* AT_INDICATOR_EVENT */
    struct {
        /* One based indicator index. */
        U32              indicator;
        /* Current value of this indicator. */
        U32              value;
    } event;

    /* AT_VOICE_TAG */
    struct {
        const char     *number;
    } voiceTag;

    /* AT_VOICE_RECOGNITION  AT+VREC*/
    struct {
        BOOL            enabled;
    } vrec;

    /* AT_IN_BAND_RING_TONE  AT+BSIR*/
    struct {
        BOOL            enabled;
    } inBandRing;

    /* AT_RESPONSE_AND_HOLD (AT+BTRH) */
    struct {
        srv_bt_dialer_AtResponseHold_enum  setting;
    } btrh;

    /* AT_SUBSCRIBER_NUM  AT+CNUM*/
    struct {
        /* String phone number of format specified by "type". */
        const char     *number;

        /* Phone number format */
        srv_bt_dialer_AtNumberFormat_enum  type;

        /* Service related to the phone number. */
        U8              service;
    } subscribeNum;

    /* AT_LIST_CURRENT_CALLS */
    struct {
        /* The numbering (starting with 1) of the call given by the sequence
         * of setting up or receiving the calls (active, held or waiting) as
         * seen by the served subscriber. Calls hold their number until they
         * are released. New calls take the lowest available number.
         */
        U8              index;

        /* Direction: 0 (Mobile Originated), 1 (Mobile Terminated), 
         * 0xFF (Value not present) 
         */
        U8              dir;

        /* Call State */
        srv_bt_dialer_AtCallState_enum     state;

        /* Mode: 0=Voice, 1=Data, 2=FAX */
        U8              mode;

        /* Multiparty 0=Not Multiparty, 1=Multiparty. */
        U8              multiParty;

        /* Phone number */
        const char     *number;

        /* Phone number type */
        srv_bt_dialer_AtNumberFormat_enum  type;
    } currentCalls;

    /* AT_NETWORK_OPERATOR AT+COPS*/
    struct {
        /* 0 = automatic, 1 = manual, 2 = deregister, 3 = set format only, 
         * 4 = manual/automatic.
         */
        U8              mode;
        /* Format of "oper" parameter (0-3) */
        srv_bt_dialer_AtOperFormat_enum    format;

        /* Numeric or long or short alphanumeric name of operator */
        const char     *oper;

    } networkOper_read;
    
	struct
	{
		srv_bt_dialer_AtError error;
	} error_code;
    
} srv_bt_dialer_AtHfResult_struct;

#define SRV_BT_DIALER_SUCCESS						  1
#define SRV_BT_DIALER_FAILURE						  0


/*---------------------------------------------------------------------------
 * AtHandsfreeResult
 *--------------------------------------------------------------------------*/

/*Utility indicators for Application layer*/

/*Signal Indication*/
#define SRV_BT_DIALER_UNMASK_CIEV_SIGNAL_INDICATION		0x0001
/*Roaming status Indicator*/
#define SRV_BT_DIALER_UNMASK_ROAM_INDICATION			0x0002
/*AG registration status - Serive indication*/
#define SRV_BT_DIALER_UNMASK_CIEV_SERVICE_INDICATION	0x0004
/*Battery Charge level Indication*/
#define SRV_BT_DIALER_UNMASK_BATTCHG_INDICATION			0x0008
/*call indication*/
#define SRV_BT_DIALER_CIEV_CALL_INDICATION				0x0080
/*Call setup indication*/
#define SRV_BT_DIALER_CIEV_CALL_SETUP_INDICATION   		0x0100




typedef struct
{
	srv_bt_dialer_AtHfResult_struct result;
	srv_bt_dialer_event_enum event_id;
	
}srv_bt_dialer_notify_event_struct;

/*
* Application should register this callback function
* which would be called when BT dialer recieves AT command response
* from the BT stack layer.
* In this callback funtion, application needs to identify the event,
* Based on that event, it needs to typecast the structure to valid one.
*/
typedef void(*srv_bt_dialer_notify_hf_event)(int srv_hd, srv_bt_dialer_notify_event_struct result); 

/*
* Application should first open the BT dialer service by calling this API.
* In return, BT dialer will provide the Service handle,
* which should be used for all subsequent interaction with BT dialer service
*/
int srv_bt_dialer_open(void);

/*
* Application should close the BT dialer service by calling this API.
* BT dialer will clean up all the resources after invoking this API by Application.
*/
void srv_bt_dialer_close(int srv_hd); 

/*
* Application should register the above callback function using this interface
* The application should register the callback function before using the service of
* BT dialer, otherwise BT dialer won't be able to send back the response to APP.
*/
int srv_bt_dialer_register_hf_notifier(int srv_hd, srv_bt_dialer_notify_hf_event cb_ptr);

/*
* Application can register for certain indicators if reqired like roaming status of AG
* battery charge status, voice recognition etc.
* its not mandatory to register it but incase app wants to know about certain indicator
* If application don't register for these indicator, Dialor service won't notify them to apps at all
*/
int srv_bt_dialer_register_indicators(int srv_hd, U16 ind_event);

/* Command to answer a incoming call. */
int srv_bt_dialer_send_ata_req(int srv_hd);

/*Command to dial a phone number or dial from memory. */
int srv_bt_dialer_send_dial_req(int srv_hd, const char *number);

/* This command allows control of the Call Waiting supplementary service. 
*  "wait" parameter is used with this command.
*  Enable/Disable the presentation of the AT_CALL_WAIT_NOTIFY unsolicited result code
* MMI_TRUE: Enable the call wait
* MMI_FALSE: Disable the call wait
 */
int srv_bt_dialer_send_call_wait_req(int srv_hd, MMI_BOOL wait);


/* Call hold procedure to perform.
 * the index (1 - 9) of a specific call to address.   
 */   
int srv_bt_dialer_send_hold_req(int srv_hd, U8 Call);

/* 
 * This command allows control of the Call Identification supplementary service.  
 * MMI_TRUE: Enable the call Identification unsolicited result code
 * MMI_FALSE: Disable the call Identification unsolicited result code
*/   
int srv_bt_dialer_send_set_clip_req(int srv_hd, MMI_BOOL enable_callId);

/* 
 * This command allows control of the Generating dtmf tone supplementary service.  
 * MMI_TRUE: Enable the DTMF tone unsolicited result code
 * MMI_FALSE: Disable the DTMF tone unsolicited result code
*/   
int srv_bt_dialer_send_generate_dtmf_tone_req(int srv_hd, MMI_BOOL tone);

/* 
 * This command allows control of the voice recognition supplementary service.  
 * MMI_TRUE: Enable the VR unsolicited result code
 * MMI_FALSE: Disable the VR unsolicited result code
*/   
int srv_bt_dialer_send_voice_recognition_req(int srv_hd, MMI_BOOL enabled_vr);

/* 
 * This command allows user to redial the last number
*/   
int srv_bt_dialer_send_redial_req(int srv_hd);

/* 
Network operator format should be set before retrieving 
netwrok operator name
*/
int srv_bt_dialer_set_network_operator_format(int srv_hd);
/* 
* This command allows to fetch network operator info supplementary service.  
* Some Audio gateway don't send Network op. info until asked them to send
* 
*/   
int srv_bt_dialer_get_network_operator_info_req(int srv_hd);

/* 
* This command allow user to control the behavior of active and hold call
*/   
int srv_bt_dialer_send_hold_response_set_req(int srv_hd,int index );

/* 
* This command allow user to read the behavior of active and hold call
*/   
int srv_bt_dialer_send_response_hold_read_req(int srv_hd);

/* 
* This command allows to fetch network operator info supplementary service.  
* Some Audio gateway don't send Network op. info until asked them to send
*/   
int srv_bt_dialer_get_network_operator_info_req(int srv_hd);
/*Hangup all active calls*/
int srv_bt_dialer_hangup_active_calls(int srv_hd);
/*Speaker volume gain*/
int srv_bt_dialer_speaker_vol_gain_req(int srv_hd,int gain);
/*Mic volume gain*/
int srv_bt_dialer_mic_vol_gain_req(int srv_hd,int gain);
/*Voice tag request*/
int srv_bt_dialer_send_voice_tag_req(int srv_hd);
/*Noice reduction req*/
int srv_bt_dialer_noise_red_req(int srv_hd);
/*List current active/holdcalls*/
int srv_bt_dialer_list_current_calls(int srv_hd);

int srv_bt_dialer_event_reporting(int srv_hd, U8 event);
/*Subscriber number info*/
int srv_bt_dialer_subscriber_num_req(int srv_hd);
/*code snippet to send AT command
UCM will request to open the BT dialer service and register the callback
This should be done only once before closing the BT dialer service.
int srv_hd;
int ind_event;
srv_hd = srv_bt_dialer_open();
srv_bt_dialer_register_hf_notifier(srv_hd, (void *)callback_ptr);

ind_event = SRV_BT_DIALER_UNMASK_BSIR_IND | SRV_BT_DIALER_UNMASK_CIEV_SIGNAL_IND |
            SRV_BT_DIALER_UNMASK_ROAM_IND | SRV_BT_DIALER_UNMASK_BATTCHG_IND ;
            
srv_bt_dialer_register_indicators(srv_hd, U16 ind_event);

 --> to dial a number:
srv_bt_dialer_send_dial_req(srv_hd, "9999999999");
*/


/*code snippet to receive Notification from BT Dialer service
((srv_bt_dialer_register_hf_event)inst->notify)(ptr); //at caller's end
When BT dialer receives any notification from the BT stack, it will kick off the callback
registered by UCM.
UCM needs to write the definition of this callback something like below.
UCM module should not close the BT dialer service inside the callback definition.
Since the current callback execution is being done in BT dialer service, 
its better to post a event (using Framework service and do the action after receiving the control)


void srv_bt_dialer_register_hf_event(srv_bt_dialer_notify_event_struct notify)
{
	switch(notify.event_id)
	{
		case SRV_BT_DIALER_EVT_ID_AT_CALL_HOLD:
			something = notify.hold_test.flags;
			uxm_xxx_hdlr();
			break;
		default:
		case SRV_BT_DIALER_AT_INDICATOR_EVENT:
			something = notify.event.indicator;
			something = notify.event.value;
			uxm_xxx_hdlr();
			break;
		default:
		
	}
	
	mmi_frm_post_event((mmi_event_struct *)&evnt, proc_func,user_data);
}
*/

#endif /*__BT_DIALER_SUPPORT__*/
#endif /*__BTDIALER_SRV_GPROT_H__*/