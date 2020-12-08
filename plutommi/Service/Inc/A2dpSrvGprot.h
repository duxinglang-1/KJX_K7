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
 * A2dpSrvGprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Global Export Function
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __A2DP_SRV_GPROT_H__
#define __A2DP_SRV_GPROT_H__

#include "BtcmSrvGprot.h"
#include "kal_general_types.h"
#include "MMIDataType.h"

#ifdef __cplusplus
extern "C"
{
#endif


typedef void(*A2DP_SRV_CALLBACK)(kal_int32 result);
typedef MMI_BOOL(*A2DP_SRV_CHECK_OUTPUT_CALLBACK)(void);
typedef MMI_BOOL(*A2DP_SRV_IS_OUTPUT_TO_BT_CALLBACK)(void);
typedef srv_bt_cm_bt_addr*(*A2DP_SRV_GET_BT_HEADSET_CALLBACK)(void);

/* The result or event of A2DP streaming, which will pass to clinet through registered callback */
typedef enum
{
    SRV_A2DP_CALLBACK_EVENT_OPEN_OK,                    /* open success */
    SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED,                /* open faied */
    SRV_A2DP_CALLBACK_EVENT_OPEN_STOPPED,               /* open stopped by client */
    SRV_A2DP_CALLBACK_EVENT_OPEN_CANCELED,              /* open canceled by another audio playback request */
    SRV_A2DP_CALLBACK_EVENT_STREAM_SUSPEND_IND,         /* streaming suspend indication by lower layer (ex: the other BT device) */
    SRV_A2DP_CALLBACK_EVENT_STREAM_START_IND,           /* streaming start indication by lower layer (ex: the other BT device) */
    SRV_A2DP_CALLBACK_EVENT_STREAM_CLOSE_IND,           /* streaming close indication by lower layer (ex: the other BT device) */
    SRV_A2DP_CALLBACK_EVENT_STREAM_ABORT_IND,           /* streaming abort indication by lower layer (ex: the other BT device) */
    SRV_A2DP_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND,  /* streaming disconnect indication by lower layer (ex: the other BT device) */
    SRV_A2DP_CALLBACK_EVENT_INQUIRY_START_IND,          /* BT CM starts to inquiry BT devices */
    SRV_A2DP_CALLBACK_EVENT_INQUIRY_STOP_IND,           /* BT CM stops inquirying BT devices */
    SRV_A2DP_CALLBACK_EVENT_OPEN_SCO,                   /* A2DP connect fail but HFP SCO is connected successfully */
/* DOM-NOT_FOR_SDK-BEGIN */
    SRV_A2DP_CALLBACK_EVENT_SECURITY_BLOCK              /* Connect fail due to stack security block, clinet will not get thie result, it will be SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED instead */
/* DOM-NOT_FOR_SDK-END */
} srv_a2dp_callback_event_enum;

/* Open result */
typedef enum
{
    SRV_A2DP_OPEN_WAITING,      /* wiat for result. result will be pass to client through callback */
    SRV_A2DP_OPEN_FAILED,       /* open failed */
    SRV_A2DP_OPEN_DONE          /* open done, A2DP streaming started */
} srv_a2dp_open_result_enum;


/* DOM-NOT_FOR_SDK-BEGIN */
/* A2DP state*/
typedef enum
{
    SRV_A2DP_STATE_IDLE,            /* Initial */
    SRV_A2DP_STATE_ACTIVATING,      /* Activating  */
    SRV_A2DP_STATE_ACTIVATED,       /* Activated */
    SRV_A2DP_STATE_DEACTIVATING,    /* Deactivaing */
    SRV_A2DP_STATE_CONNECTING,      /* Connecting: send request to connect and wait for connect result */
    SRV_A2DP_STATE_CONNECTED,       /* Connected */
    SRV_A2DP_STATE_DISCONNECTING    /* Disconnecting: send request to disconnect and wait for disconnect result */
} srv_a2dp_state_enum;


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_init
 * DESCRIPTION
 *  To init a2pd service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_a2dp_init(void);


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_set_auto_disconnect_dalay
 * DESCRIPTION
 *  To set the auto disconnect timer, if set to 0, it means do not auto disconnect 
 *  A2DP signal
 * PARAMETERS
 *  msec  :  [IN] delay time in milli second
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_a2dp_set_auto_disconnect_dalay(kal_uint16 msec);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_connect_req
 * DESCRIPTION
 *  send a connect req to bluetooth task
 * PARAMETERS
 *  dev_addr  :  [IN] device address to connect
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_a2dp_connect_req(srv_bt_cm_bt_addr dev_addr);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_query_state
 * DESCRIPTION
 *  query a2dp state
 * PARAMETERS
 *  voide
 * RETURNS
 *  a2dp current state
 *****************************************************************************/
extern srv_a2dp_state_enum srv_bt_a2dp_query_state(void);

/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_set_default_callback
 * DESCRIPTION
 *  This function is to set default callback handler. When there is A2DP indication
 *  event, A2DP module would have someone to inform to when there is no application
 *  request for connect. Only used in PlutoMMI application
 * PARAMETERS
 *  handler  :  [IN] defalt callback
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_a2dp_set_default_callback(A2DP_SRV_CALLBACK handler);



/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_set_check_output_callback
 * DESCRIPTION
 *  This function is to set check output path hdlr
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_a2dp_set_check_output_callback(A2DP_SRV_CHECK_OUTPUT_CALLBACK handler);

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_set_is_output_to_bt_callback
 * DESCRIPTION
 *  This function is to set is output to be callback
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_a2dp_set_is_output_to_bt_callback(A2DP_SRV_IS_OUTPUT_TO_BT_CALLBACK handler);

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_set_get_bt_headset_callback
 * DESCRIPTION
 *  This function is to set get bt headset address callbackk
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_a2dp_set_get_bt_headset_callback(A2DP_SRV_GET_BT_HEADSET_CALLBACK handler);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_output_to_bt
 * DESCRIPTION
 *  to check if currently application could go through a2dp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_a2dp_is_output_to_bt(void);


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_get_bt_headset
 * DESCRIPTION
 *  to query current a2dp headset setting to pass to a2dp service for signal connection
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_bt_cm_bt_addr *
 *****************************************************************************/
extern srv_bt_cm_bt_addr *srv_a2dp_get_bt_headset(void);



/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_bt_inquirying
 * DESCRIPTION
 *  This function is for background play application to check if BT CM is now
 *  performing inquirying action
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : inquirying
 *  MMI_FALSE : not inquiring
 *****************************************************************************/
extern MMI_BOOL srv_a2dp_is_bt_inquirying(void);


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_codec_open
 * DESCRIPTION
 *  To check if audio driver open codec to send A2DP streaming data to BT stack
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : codec open
 *  MMI_FALSE : codec not open
 *****************************************************************************/
extern MMI_BOOL srv_a2dp_is_codec_open(void);


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_streaming
 * DESCRIPTION
 *  To check if A2DP is in streaming state
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : streaming
 *  MMI_FALSE : not streaming
 *****************************************************************************/
extern MMI_BOOL srv_a2dp_is_streaming(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_mp3_configured
 * DESCRIPTION
 *  To check if A2DP coedc is configured as mp3 streaming.
 *  After 11A, mp3 streaming is disabled for some performance reason.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : streaming
 *  MMI_FALSE : not streaming
 *****************************************************************************/
extern MMI_BOOL srv_a2dp_is_mp3_configured(void);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open
 * DESCRIPTION
 *   Request A2DP service to establish a connection configured to start streaming 
 *   audio with commaned sample rate / stereo type with the commaned address
 * PARAMETERS
 *  bt_dev              : [IN] bt address to connect
 *  sample_rate         : [IN] audio sample rate of requested streaming file
 *  stereo              : [IN] stereo type of requested streaming file
 *  callback            : [IN] callback function
 *  immediate_callback  : [IN] if need to callback when the result can be return immediately
 * RETURNS
 *  result
 *****************************************************************************/
extern S32 srv_a2dp_open(srv_bt_cm_bt_addr *bt_dev, U16 sample_rate, U8 stereo, A2DP_SRV_CALLBACK callback, MMI_BOOL immediate_callback);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open_ex
 * DESCRIPTION
 *   Request A2DP service to establish a connection configured to start streaming 
 *   audio with the requested audio file (Audio Only).
 *   This function could only supported in PlutoMMI for memory configuration sake.
 *   For non-PlutoMMI project, it returns failed directly.
 * PARAMETERS
 *  bt_dev              : [IN] bt address to connect
 *  filename            : [IN] audio file full path.
 *  callback            : [IN] callback function
 *  sbc_only            : [IN] do not goes with mp3 streaming
 *  immediate_callback  : [IN] if need to callback when the result can be return immediately
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 srv_a2dp_open_ex(srv_bt_cm_bt_addr *bt_dev, WCHAR *filename, A2DP_SRV_CALLBACK callback, MMI_BOOL sbc_only, MMI_BOOL immediate_callback);
/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_close
 * DESCRIPTION
 *  To temporarily suspend A2DP streaming. And start a timer to disconnect if necessary.
 *  Disconnect or not depends on the project A2DP configuration.
 * PARAMETERS
 *  notify_opener   : [IN] callback to clinet who request to open this connection
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_a2dp_close(MMI_BOOL notify_opener);


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open_codec
 * DESCRIPTION
 *  To inform MED to mute handset and go with A2DP streaming
 *  while audio playback
 * PARAMETERS
 *  immediate      : [IN] to turn on coedec immediately or wait for next play action
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_a2dp_open_codec(MMI_BOOL immediate);


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_close_codec
 * DESCRIPTION
 *  To inform MED to unmute handset and stop sending audio data through A2DP streaming
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_a2dp_close_codec(void);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_pause
 * DESCRIPTION
 *  Suspend streaming
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_a2dp_pause(void);


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_inquiry_start_callback
 * DESCRIPTION
 *  for BT CM to infrom A2DP service about inquiry action starts
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_a2dp_inquiry_start_callback(void);


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_inquiry_stop_callback
 * DESCRIPTION
 *  for BT CM to infrom A2DP service about inquiry action stops
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_a2dp_inquiry_stop_callback(void);
/* DOM-NOT_FOR_SDK-END */


#ifdef __cplusplus
}
#endif

#endif /* __A2DP_SRV_GPROT_H__ */
