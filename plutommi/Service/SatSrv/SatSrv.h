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
 *  SatSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains internal structures & function prototypes for SAT service layer.
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
#ifndef SATSRV_H
#define SATSRV_H

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "Lang_interface.h"

typedef enum
{
    SRV_SAT_CHECK_FLIGHT_MODE = 0x01,
    SRV_SAT_CHECK_DM_SETTING = 0x02,
    SRV_SAT_CHECK_DM_SETTING_EX = SRV_SAT_CHECK_FLIGHT_MODE | SRV_SAT_CHECK_DM_SETTING,
    SRV_SAT_CHECK_NW_REG_STATUS = 0x04,
    SRV_SAT_CHECK_NW_REG_STATUS_EX = SRV_SAT_CHECK_DM_SETTING_EX | SRV_SAT_CHECK_NW_REG_STATUS
} srv_sat_check_enum;


typedef struct
{
    WCHAR data[256];
    U16 len;
} srv_sat_cache_struct;


typedef struct
{
    srv_sat_cmd_enum cmd_type;
    U8 sent;
    U8 pending;
    U16 occurrence;
    srv_sat_cache_struct cache;
    srv_sat_setup_menu_struct setup_menu;
    srv_sat_setup_idle_mode_text_struct setup_idle_mode_text;
} srv_sat_cntx_struct;


/*****************************************************************************
 * FUNCTION
 *  SATID_2_L4CID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 * RETURNS
 *  module_type
 *****************************************************************************/
extern module_type SATID_2_L4CID(srv_sat_enum sat_id);


/*****************************************************************************
 * FUNCTION
 *  L4CID_2_SATID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  l4c_id      [IN]        
 * RETURNS
 *  srv_sat_enum
 *****************************************************************************/
extern srv_sat_enum L4CID_2_SATID(module_type l4c_id);


/*****************************************************************************
 * FUNCTION
 *  SATID_2_SIMID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id      [IN]        
 * RETURNS
 *  mmi_sim_enum
 *****************************************************************************/
extern mmi_sim_enum SATID_2_SIMID(srv_sat_enum sat_id);


/*****************************************************************************
 * FUNCTION
 *  SIMID_2_SATID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  srv_sat_enum
 *****************************************************************************/
extern srv_sat_enum SIMID_2_SATID(mmi_sim_enum sim_id);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  check_type:     [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_check(srv_sat_enum sat_id, srv_sat_check_enum check_type);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_ptr:       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_do_free(void *data_ptr);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_display_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  display_text:   [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_display_text(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_display_text_struct *display_text,
                    void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_get_inkey
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  get_inkey:      [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_get_inkey(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_get_inkey_struct *get_inkey,
                    void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_get_input
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  get_input:      [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_get_input(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_get_input_struct *get_input,
                    void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_play_tone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  play_tone:      [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_play_tone(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_play_tone_struct *play_tone,
                    void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_send_setup_idle_display_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  present:        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_send_setup_idle_display_event(srv_sat_enum sat_id, MMI_BOOL present);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_refresh
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  refresh:        [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_refresh(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_refresh_struct *refresh,
                    void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_setup_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  setup_menu:     [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_setup_menu(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_setup_menu_struct *setup_menu,
                    void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_select_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  select_item:    [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_select_item(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_select_item_struct *select_item,
                    void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_send_sms
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  send_sms:       [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_send_sms(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_send_sms_struct *send_sms,
                    void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_send_ss
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  send_ss:        [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_send_ss(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_send_ss_struct *send_ss,
                    void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_send_ussd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  send_ussd:      [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_send_ussd(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_send_ussd_struct *send_ussd,
                    void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_setup_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  setup_call:     [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_setup_call(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_setup_call_struct *setup_call,
                    void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_setup_idle_mode_text
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  setup_idle_mode_text:   [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_setup_idle_mode_text(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_setup_idle_mode_text_struct *setup_idle_mode_text,
                    void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_run_at_command
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  run_at_command: [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_run_at_command(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_run_at_command_struct *run_at_command,
                    void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_send_dtmf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  send_dtmf:      [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_send_dtmf(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_send_dtmf_struct *send_dtmf,
                    void *info);

#ifndef __SAT_LOWCOST_UI_DISABLE__


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_language_notification
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  language_notification:  [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_language_notification(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_language_notification_struct *language_notification,
                    void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_launch_browser
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  launch_browser: [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_launch_browser(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_launch_browser_struct *launch_browser,
                    void *info);

#endif /* __SAT_LOWCOST_UI_DISABLE__ */

#ifdef __SATCE__


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_open_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  open_channel:   [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_open_channel(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_open_channel_struct *open_channel,
                    void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_close_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  close_channel:  [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_close_channel(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_close_channel_struct *close_channel,
                    void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_send_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  send_data:      [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_send_data(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_send_data_struct *send_data,
                    void *info);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_receive_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  context:        [IN]        
 *  receive_data:   [IN]        
 *  info:           [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_sat_do_receive_data(
                    srv_sat_enum sat_id,
                    srv_sat_cntx_struct *context,
                    srv_sat_receive_data_struct *receive_data,
                    void *info);

#endif /* __SATCE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_call_control_by_sim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  info:           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_do_call_control_by_sim(srv_sat_enum sat_id, void *info);


/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_sat_do_icon_callback_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:     [IN]        
 *  result:     [IN]        
 *  icon_data:  [IN]        
 *  user_data:  [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_sat_do_icon_callback_type) (srv_sat_enum sat_id, MMI_BOOL result, U8 *icon_data, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_icon_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  result:         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_do_icon_callback(srv_sat_enum sat_id, MMI_BOOL result);


/*****************************************************************************
 * FUNCTION
 *  srv_sat_do_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sat_id:         [IN]        
 *  icon_id:        [IN]        
 *  callback:       [IN]        
 *  user_data:      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_sat_do_icon(srv_sat_enum sat_id, U8 icon_id, srv_sat_do_icon_callback_type callback, void *user_data);

#endif /* SATSRV_H */

