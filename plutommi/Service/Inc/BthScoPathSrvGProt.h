/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  BthScoPathSrvGProt.h
 *
 * Project:
 * --------
 *  Maui
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __BTH_SCO_PATH_SRV_G_PROT_H__
#define __BTH_SCO_PATH_SRV_G_PROT_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define SRV_BT_SCO_INT_A2DP      0x01
#define SRV_BT_SCO_INT_FMRADIO   0x02
#define SRV_BT_SCO_INT_CAMERA    0x04
#define SRV_BT_SCO_INT_VIDEO     0x08
#define SRV_BT_SCO_INT_MDI       0x10
#define SRV_BT_SCO_INT_CTM       0x20


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    SRV_BT_SCO_IND,
    SRV_BT_SCO_RSP,
    SRV_BT_SCO_REQ
} srv_btsco_indication_enum;

typedef enum
{
    SRV_BT_SCO_INQ_SCO_DISCONNECTED,
    SRV_BT_SCO_INQ_SCO_CONNECTED_DISCONNECTABLE,
    SRV_BT_SCO_INQ_SCO_CONNECTED_IN_CALL,
    SRV_BT_SCO_INQ_TOTAL
} srv_btsco_inquiry_result_enum;

/* Event */
typedef struct 
{
    MMI_EVT_PARAM_HEADER
    S32 result;
    U16 error_cause;
} mmi_evt_srv_btsco_close_ind_struct; 

/***************************************************************************** 
 * Function
 *****************************************************************************/
#ifdef __MMI_BT_AUDIO_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_btsco_is_sco_open
 * DESCRIPTION
 *  To check if bt is connected
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  MMI_TRUE if SCO is open
 *****************************************************************************/
MMI_BOOL srv_btsco_is_sco_open(void);

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_is_sco_connect_allowed
 * DESCRIPTION
 *  Check if bt sco connect request is allowed
 * PARAMETERS
 *  void
 * RETURN VALUSE
 *  MMI_TURE if allowed
 *****************************************************************************/
MMI_BOOL srv_btsco_is_sco_connect_allowed(void);

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_is_sco_in_call
 * DESCRIPTION
 *  Check is sco connection in call
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TURE if in call
 *****************************************************************************/
MMI_BOOL srv_btsco_is_sco_in_call(void);

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_connect_sco_req
 * DESCRIPTION
 *  Connect sco link before running application, use callback to make sure sco connected
 * PARAMETERS
 *  callback        [IN]
 * RETURNS
 *  MMI_TURE if connect successfully
 *****************************************************************************/
MMI_BOOL srv_btsco_connect_sco_req(void (*callback) (void));

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_disconnect_sco_req
 * DESCRIPTION
 *  Disconnect sco link
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE if disconnect successfully
 *****************************************************************************/
MMI_BOOL srv_btsco_disconnect_sco_req(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_btsco_deactivate_cnf_hdlr
 * DESCRIPTION
 *  Tthe cnf handler for bt a2dp deactivate req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_deactivate_cnf_hdlr(void);

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_reset
 * DESCRIPTION
 *  Tto reset bt profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_reset(void (*painc_cb)(void));

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_open_stream_req
 * DESCRIPTION
 *  Open SCO connection request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_btsco_open_stream_req(void);

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_close_stream_req
 * DESCRIPTION
 *  Close SCO connection request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_close_stream_req(void);

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_call_start_callback
 * DESCRIPTION
 *  The call back function for call start
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_call_start_callback(void);

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_call_end_callback
 * DESCRIPTION
 *  The call back function for call end
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_call_end_callback(void);

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_hfp_connect_callback
 * DESCRIPTION
 *  the call back function for HFP connect indication
 * PARAMETERS
 *  callback_type       [IN] : HFP callback type (ind, rsp)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_hfp_connect_callback(U8 callback_type);

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_hfp_disconnect_callback
 * DESCRIPTION
 *  the call back function for HFP connect indication
 * PARAMETERS
 *  callback_type       [IN] : HFP callback type (ind, rsp)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_hfp_disconnect_callback(U8 callback_type);

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_switch_profile_path
 * DESCRIPTION
 *  Set sco path when change user profile mode
 * PARAMETERS
 *  turn_on_sco     : [IN] Turn on sco
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_switch_profile_path(MMI_BOOL turn_on_sco);
/* DOM-NOT_FOR_SDK-END */

#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
/*****************************************************************************
 * FUNCTION
 *  srv_btsco_is_profile_connect_allowed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL srv_btsco_is_profile_connect_allowed(void);

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_set_always_on
 * DESCRIPTION
 *  Set SCO connection always on
 * PARAMETERS
 *  is_always_on    : [IN] is always turn on SCO connection
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_set_always_on(MMI_BOOL is_always_on);

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_disable_sco_connection
 * DESCRIPTION
 *  Disable SCO connect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_disable_sco_connection(U8 type_id);

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_enable_sco_connection
 * DESCRIPTION
 *  Enalbe SCO connect
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_enable_sco_connection(U8 type_id);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_btsco_inquiry_start_callback
 * DESCRIPTION
 *  Callback function for BT inquery
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_btsco_inquiry_result_enum srv_btsco_inquiry_start_callback(void (*callback) (void));

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_inquiry_stop_callback
 * DESCRIPTION
 *  Callback function for BT inquery
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_inquiry_stop_callback(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_reset_connection_timer
 * DESCRIPTION
 *  Reset SCO connect timeout timer
 * PARAMETERS
 *  void
 * RETURNS
 * void
 *****************************************************************************/
void srv_btsco_reset_connection_timer(void);

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_connect_audio_via_sco
 * DESCRIPTION
 *  Connect audio via SCO
 * PARAMETERS
 *  void
 * RETURNS
 * void
 *****************************************************************************/
extern void srv_btsco_connect_audio_via_sco(void);

#endif /* defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__) */
#endif /*__MMI_BT_AUDIO_SUPPORT__*/

#endif /* __BTH_SCO_PATH_SRV_G_PROT_H__ */

