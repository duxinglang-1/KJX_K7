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
 * AvrcpSrvGprot.h
 *
 * Project:
 * --------
 *   Maui
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __SRV_AVRCP_GPROT_H__
#define __SRV_AVRCP_GPROT_H__

#include "MMI_features.h"

#ifdef __MMI_AVRCP_SUPPORT__

#include "MMIDataType.h"
#include "kal_general_types.h"

#include "AvrcpSrvGprot.h"
#include "BtcmSrvGprot.h"

#ifdef __cplusplus
extern "C"
{
#endif


/***************************************************************************** 
* Definations
*****************************************************************************/

/* AVRCP command control type : accept */
#define SRV_AVRCP_CR_ACCEPT            (0x09)
/* AVRCP command control type : reject */
#define SRV_AVRCP_CR_REJECT            (0x0A)
/* AVRCP command control type : not implement */
#define SRV_AVRCP_CR_NOT_IMPLEMENT     (0x08)

/* AVRCP Commands : select */
#define SRV_AVRCP_POP_SELECT            0x00
/* AVRCP Commands : up */
#define SRV_AVRCP_POP_UP                0x01
/* AVRCP Commands : down */
#define SRV_AVRCP_POP_DOWN              0x02
/* AVRCP Commands : left */
#define SRV_AVRCP_POP_LEFT              0x03
/* AVRCP Commands : right */
#define SRV_AVRCP_POP_RIGHT             0x04
/* AVRCP Commands : right up */
#define SRV_AVRCP_POP_RIGHT_UP          0x05
/* AVRCP Commands : right down */
#define SRV_AVRCP_POP_RIGHT_DOWN        0x06
/* AVRCP Commands : left up */
#define SRV_AVRCP_POP_LEFT_UP           0x07
/* AVRCP Commands : left down */
#define SRV_AVRCP_POP_LEFT_DOWN         0x08
/* AVRCP Commands : root menu */
#define SRV_AVRCP_POP_ROOT_MENU         0x09
/* AVRCP Commands : setup menu */
#define SRV_AVRCP_POP_SETUP_MENU        0x0A
/* AVRCP Commands : contents menu */
#define SRV_AVRCP_POP_CONTENTS_MENU     0x0B
/* AVRCP Commands : favorite menu */
#define SRV_AVRCP_POP_FAVORITE_MENU     0x0C
/* AVRCP Commands : exit */
#define SRV_AVRCP_POP_EXIT              0x0D

/* AVRCP Commands : 0 */
#define SRV_AVRCP_POP_0                 0x20
/* AVRCP Commands : 1 */
#define SRV_AVRCP_POP_1                 0x21
/* AVRCP Commands : 2 */
#define SRV_AVRCP_POP_2                 0x22
/* AVRCP Commands : 3 */
#define SRV_AVRCP_POP_3                 0x23
/* AVRCP Commands : 4 */
#define SRV_AVRCP_POP_4                 0x24
/* AVRCP Commands : 5 */
#define SRV_AVRCP_POP_5                 0x25
/* AVRCP Commands : 6 */
#define SRV_AVRCP_POP_6                 0x26
/* AVRCP Commands : 7 */
#define SRV_AVRCP_POP_7                 0x27
/* AVRCP Commands : 8 */
#define SRV_AVRCP_POP_8                 0x28
/* AVRCP Commands : 9 */
#define SRV_AVRCP_POP_9                 0x29
/* AVRCP Commands : dot */
#define SRV_AVRCP_POP_DOT               0x2A
/* AVRCP Commands : enter */
#define SRV_AVRCP_POP_ENTER             0x2B
/* AVRCP Commands : clear */
#define SRV_AVRCP_POP_CLEAR             0x2C

/* AVRCP Commands : channel up */
#define SRV_AVRCP_POP_CHANNEL_UP        0x30
/* AVRCP Commands : channel down */
#define SRV_AVRCP_POP_CHANNEL_DOWN      0x31
/* AVRCP Commands : previous channel */
#define SRV_AVRCP_POP_PREVIOUS_CHANNEL  0x32
/* AVRCP Commands : sound select */
#define SRV_AVRCP_POP_SOUND_SELECT      0x33
/* AVRCP Commands : input select */
#define SRV_AVRCP_POP_INPUT_SELECT      0x34
/* AVRCP Commands : display info */
#define SRV_AVRCP_POP_DISPLAY_INFO      0x35
/* AVRCP Commands : help */
#define SRV_AVRCP_POP_HELP              0x36
/* AVRCP Commands : page up */
#define SRV_AVRCP_POP_PAGE_UP           0x37
/* AVRCP Commands : page down */
#define SRV_AVRCP_POP_PAGE_DOWN         0x38

/* AVRCP Commands : power */
#define SRV_AVRCP_POP_POWER             0x40
/* AVRCP Commands : volume up */
#define SRV_AVRCP_POP_VOLUME_UP         0x41
/* AVRCP Commands : volume down */
#define SRV_AVRCP_POP_VOLUME_DOWN       0x42
/* AVRCP Commands : mute */
#define SRV_AVRCP_POP_MUTE              0x43
/* AVRCP Commands : play */
#define SRV_AVRCP_POP_PLAY              0x44
/* AVRCP Commands : stop */
#define SRV_AVRCP_POP_STOP              0x45
/* AVRCP Commands : pause */
#define SRV_AVRCP_POP_PAUSE             0x46
/* AVRCP Commands : record */
#define SRV_AVRCP_POP_RECORD            0x47
/* AVRCP Commands : rewind */
#define SRV_AVRCP_POP_REWIND            0x48
/* AVRCP Commands : fast forward */
#define SRV_AVRCP_POP_FAST_FORWARD      0x49
/* AVRCP Commands : eject */
#define SRV_AVRCP_POP_EJECT             0x4A
/* AVRCP Commands : forward */
#define SRV_AVRCP_POP_FORWARD           0x4B
/* AVRCP Commands : backward */
#define SRV_AVRCP_POP_BACKWARD          0x4C

/* AVRCP Commands : angle */
#define SRV_AVRCP_POP_ANGLE             0x50
/* AVRCP Commands : subpicture */
#define SRV_AVRCP_POP_SUBPICTURE        0x51

/* AVRCP Commands : F1 */
#define SRV_AVRCP_POP_F1                0x71
/* AVRCP Commands : F2 */
#define SRV_AVRCP_POP_F2                0x72
/* AVRCP Commands : F3 */
#define SRV_AVRCP_POP_F3                0x73
/* AVRCP Commands : F4 */
#define SRV_AVRCP_POP_F4                0x74
/* AVRCP Commands : F5 */
#define SRV_AVRCP_POP_F5                0x75

/* AVRCP Commands : vendor unique */
#define SRV_AVRCP_POP_VENDOR_UNIQUE     0x7E

/* AVRCP Commands : reserved */
#define SRV_AVRCP_POP_RESERVED          0x7F

/***************************************************************************** 
* Enum
*****************************************************************************/

/* key event types */
typedef enum
{
    SRV_AVRCP_KEY_DOWN =0,      /* key down */
    SRV_AVRCP_KEY_UP,           /* key up */
    SRV_AVRCP_KEY_LONGPRESS,    /* key longpress */
    SRV_AVRCP_KEY_REPEAT,       /* key repeat */
    SRV_AVRCP_KEY_CANCELED,     /* key canceled */

    SRV_AVRCP_TOTAL_KEY_EVENTS  /* key total */
} srv_avrcp_key_events;


/***************************************************************************** 
* typedef 
*****************************************************************************/
typedef U8(*AVRCP_SRV_CMD_CALLBACK) (U8 command_type, srv_avrcp_key_events key_events);
typedef void(*AVRCP_SRV_CMD_CNF_CALLBACK) (U16 op_code, U16 command_type, MMI_BOOL key_press);

/***************************************************************************** 
* Functions
*****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_init
 * DESCRIPTION
 *  To init AVRCP service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_avrcp_init(void);


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_connect_tg_req
 * DESCRIPTION
 *  For A2DP to connect AVRCP
 * PARAMETERS
 *  dev_addr  :  [IN] device address to connect
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_avrcp_connect_tg_req(srv_bt_cm_bt_addr dev_addr);


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_disconnect_from_a2dp
 * DESCRIPTION
 *  to set the flag of disconnect avrcp from A2DP service , 
 *  so that we can judge if we shall inform cm for disconnect ind or cnf
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_avrcp_disconnect_from_a2dp(MMI_BOOL set);


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_disconnect_tg_req
 * DESCRIPTION
 *  To disconnect AVRCP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_avrcp_disconnect_tg_req(U32 connect_id);


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_set_cmd_frame_cnf_hdlr
 * DESCRIPTION
 *  To set command frame confirm callback handler. For controller used only.
 *  Currently we do not support controller role.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_avrcp_set_cmd_frame_cnf_hdlr(AVRCP_SRV_CMD_CNF_CALLBACK callback_func);

/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_set_cmd_hdlr
 * DESCRIPTION
 *  To set command callback handler. When receive AVRCP command, it will pass to clinet
 *  through this callback function
 * PARAMETERS
 *  callback_func   : [IN] callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_avrcp_set_cmd_hdlr(AVRCP_SRV_CMD_CALLBACK callback_func);


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_clear_cmd_hdlr
 * DESCRIPTION
 *  Clear command callback handler.
 * PARAMETERS
 *  callback_func   : [IN] callback function
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_avrcp_clear_cmd_hdlr(AVRCP_SRV_CMD_CALLBACK callback_func);


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_frm_sync_calllback
 * DESCRIPTION
 *  for framework to callback if keypad / touch is triggered.
 * PARAMETERS
 *  is_blocked   : [IN] is keypad / touch blocked by target
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_avrcp_frm_sync_calllback(MMI_BOOL is_blocked);


#ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_actively_connect_tg_flag
 * DESCRIPTION
 *  get EM mode setting
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE : flag on
 *  MMI_FALSE: flag off
 *****************************************************************************/
extern MMI_BOOL srv_avrcp_get_actively_connect_tg_flag(void);


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_set_actively_connect_tg_flag
 * DESCRIPTION
 *  set EM mode setting
 * PARAMETERS
 *  MMI_BOOL    : [IN] set flag on / off
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_avrcp_set_actively_connect_tg_flag(MMI_BOOL on_off);

/* DOM-NOT_FOR_SDK-END */


#endif

#ifdef __cplusplus
}
#endif

#endif /* __MMI_AVRCP_SUPPORT__ */

#endif /* __SRV_AVRCP_GPROT_H__ */ 

