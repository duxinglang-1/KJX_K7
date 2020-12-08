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
 *  CtmSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CTM service global prototypes
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
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
 *==============================================================================
 *******************************************************************************/

#ifdef __CTM_SUPPORT__

#ifndef SRV_CTM_GPROT_H
#define SRV_CTM_GPROT_H

#include "mmi_rp_srv_ctm_def.h" /* EVT_ID_SRV_CTM_INDICATION */

#include "med_struct.h"/* CTM_SEND_TEXT_CHAR_MAX_NUM */

#include "MMIDataType.h"
#include "kal_non_specific_general_types.h"
#include "mmi_res_range_def.h"


/* CTM action operation code */
typedef enum
{
    SRV_CTM_ACT_IDLE,
    SRV_CTM_ACT_CONNECT, /* CTM connect. req: NULL, rsp: srv_ctm_connect_rsp_struct */
    SRV_CTM_ACT_SEND_TEXT, /* CTM send text. req: srv_ctm_send_text_req_struct, rsp: srv_ctm_send_text_rsp_struct  */
    SRV_CTM_ACT_TOTAL
} srv_ctm_act_op_enum;


/* CTM indication operation code */
typedef enum
{
    SRV_CTM_IND_CONNECT, /* CTM connect indication. Use NULL as info in the callback function */
    SRV_CTM_IND_RECEIVE_TEXT,/* CTM receive text indication. Use srv_ctm_receive_text_ind_struct as info in the callback function */
    SRV_CTM_IND_CLOSE, /* CTM close indication. Use NULL as info in the callback function */
    SRV_CTM_IND_TTY_DEVICE_STATUS, /* srv_ctm_tty_device_status_struct */
    SRV_CTM_IND_TOTAL
} srv_ctm_ind_enum;


/* CTM state */
typedef enum
{
    SRV_CTM_STATE_IDLE, /* CTM idle state */
    SRV_CTM_STATE_OPENING, /* CTM opening state */
    SRV_CTM_STATE_OPENED, /* CTM opened state */
    SRV_CTM_STATE_CONNECTING, /* CTM connecting state */
    SRV_CTM_STATE_CONNECTED, /* CTM connected state */
    SRV_CTM_STATE_SENDING, /* CTM sending state */
    SRV_CTM_STATE_CLOSING, /* CTM closing state */
    SRV_CTM_STATE_TOTAL
} srv_ctm_state_enum;


/* CTM information structure for receive text indication */
typedef struct
{
    PU16 text; /* received text buffer */
    U16 text_len; /* number of characters in received text buffer */
} srv_ctm_receive_text_ind_struct;


/* CTM information structure for send text indication */
typedef struct
{
    MMI_BOOL result; /* result of send text */
    U8 *sent_text; /* sent text buffer */
    U16 sent_text_len; /* number of characters in sent text buffer */
} srv_ctm_send_text_ind_struct;


/* 
 * CTM tty device status indication event structure
 */
typedef struct
{
    MMI_BOOL is_plug_in; /* MMI_TRUE if tty device plug in */
} srv_ctm_tty_device_status_struct;


/* CTM send text request structure */
typedef struct
{
    U8  text[(CTM_SEND_TEXT_CHAR_MAX_NUM + 1) * ENCODING_LENGTH]; /* text buffer to be sent, in UCS2 */
} srv_ctm_send_text_req_struct;


/* CTM response structure */
typedef struct
{
    MMI_BOOL result; /* result */
} srv_ctm_rsp_struct;


#ifdef __BUILD_DOM__
/* Event id definition */
typedef enum
{
    EVT_ID_SRV_CTM_INDICATION = SRV_CTM_BASE + 1, /* srv_ctm_ind_struct, must return MMIO_RET_OK */
    EVT_ID_SRV_CTM_TOTAL
} srv_ctm_event_enum;
#endif /* __BUILD_DOM__ */


/* CTM indication structure */
typedef struct {
    MMI_EVT_PARAM_HEADER
    srv_ctm_ind_enum ind; /* Indication Id */
    void *ptr; /* Data pointer */
} srv_ctm_ind_struct;


/*****************************************************************************
 * <GROUP  CallBackFunctions>		
 *
 * FUNCTION
 *    srv_ctm_ind_cb_func_ptr
 * DESCRIPTION
 *  CTM indication callback function pointer
 * PARAMETERS
 *  opcode :  [IN]  Indication operation code 
 *  info :  [IN] Information
 * RETURNS
 *  MMI_TRUE if processed
*****************************************************************************/
typedef U32 (*srv_ctm_ind_cb_func_ptr) (srv_ctm_ind_struct *info);


/*****************************************************************************
 * <GROUP  CallBackFunctions>		
 *
 * FUNCTION
 *    srv_ctm_rsp_cb_func_ptr
 * DESCRIPTION
 *  CTM response callback function pointer
 * PARAMETERS
 *  opcode :  [IN]  Response operation code 
 *  info :  [IN] Information
 * RETURNS
 *  void
*****************************************************************************/
typedef void (*srv_ctm_rsp_cb_func_ptr) (void *info);


/*****************************************************************************
 * FUNCTION
 *    srv_ctm_srv_init
 * DESCRIPTION
 *  Initialize CTM service 
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_ctm_init(void);


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_act_req
 * DESCRIPTION
 *  CTM action request
 * PARAMETERS
 *  opcode : [IN]  request opcode
 *  info : [IN]  parameter for request
 *  callback : [IN] callback function pointer
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_ctm_act_req(srv_ctm_act_op_enum opcode, void* info, srv_ctm_rsp_cb_func_ptr callback);


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_permit_connect
 * DESCRIPTION
 *  Permit CTM connect operation
 * PARAMETERS
 *  void
 * RETURNS
 *  Permit or not
 *****************************************************************************/
extern MMI_BOOL srv_ctm_prmt_connect(void);


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_is_connected
 * DESCRIPTION
 *  Check if CTM has been connected
 * PARAMETERS
 *  void
 * RETURNS
 *  is connected or not
 *****************************************************************************/
extern MMI_BOOL srv_ctm_is_connected(void);


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_get_tty_status
 * DESCRIPTION
 *  Get TTY status
 * PARAMETERS
 *  void
 * RETURNS
 *  TTY status is on or off
 *****************************************************************************/
extern MMI_BOOL srv_ctm_get_tty_status(void);


/*****************************************************************************
 * FUNCTION
 *  srv_ctm_is_opened_as_manual_mode
 * DESCRIPTION
 *  To query if ctm service is opened as manual mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE: opended as manual mode
 *****************************************************************************/
extern MMI_BOOL srv_ctm_is_opened_as_manual_mode(void);



#endif /* SRV_CTM_GPROT_H */

#endif /* __CTM_SUPPORT__ */
