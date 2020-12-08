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
 *  SatCoreProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements application functions for SAT feature.
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

#ifndef _MMI_SAT_RSP_H
#define _MMI_SAT_RSP_H

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */

#include "MMIDataType.h"
#include "SatSrvGprot.h"
#include "UcmSrvGprot.h"


#ifdef __cplusplus
}
#endif /* __cplusplus */


typedef enum
{
    SAT_RSP_OK = 0,
    SAT_RSP_IMMEDIATE_OK,
    SAT_RSP_DELAY_OK,
    SAT_RSP_HELP,
    SAT_RSP_BACK,
    SAT_RSP_CANCEL,
    SAT_RSP_ABORT,
    SAT_RSP_TERMINATE,
    SAT_RSP_NO_RESPONSE,

    SAT_RSP_END
} mmi_core_sat_rsp_enum;

typedef enum
{
    SAT_TIMER_WAIT,
    SAT_TIMER_CLEAR_DELAY,
    SAT_TIMER_NO_RESPONSE,
    SAT_TIMER_HELP,
    SAT_TIMER_POPUP,
    SAT_TIMER_PLAY_TONE,
    SAT_TIMER_REFRESH_REBOOT
} mmi_core_sat_timer_enum;

typedef struct
{
    srv_sat_cmd_enum cmd_type;
    MMI_BOOL is_inform;
} mmi_sat_timer_data_struct;



PU8 mmi_sat_get_cmd_hint(srv_sat_cmd_enum cmd_type, srv_sat_cmd_enum for_cmd_type);

/* Terminal Response */
extern MMI_BOOL mmi_sat_setup_menu_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type, U8 item_id);
extern MMI_BOOL mmi_sat_select_item_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type, U8 item_id);
extern MMI_BOOL mmi_sat_display_text_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum rsp_type);
extern MMI_BOOL mmi_sat_get_inkey_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type, MMI_BOOL is_yes_selected, WCHAR *input_buf);
extern MMI_BOOL mmi_sat_get_input_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type, WCHAR *input_buf);
extern MMI_BOOL mmi_sat_play_tone_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type);
extern MMI_BOOL mmi_sat_send_ss_result_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type, U8 length, PU8 add_info);
extern MMI_BOOL mmi_sat_send_ussd_result_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type, U8 length, PU8 add_info);
extern MMI_BOOL mmi_sat_setup_call_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type, srv_ucm_result_enum *error_code);
extern MMI_BOOL mmi_sat_setup_call_ucm_requset(mmi_sim_enum sim_id, srv_ucm_result_enum *error_code);
extern MMI_BOOL mmi_sat_send_dtmf_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type);
extern MMI_BOOL mmi_sat_launch_browser_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type);
extern MMI_BOOL mmi_sat_open_channel_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type);

#ifdef __SRV_SAT_TR_CLOSE_CHANNEL__
extern MMI_BOOL mmi_sat_close_channel_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type);
#endif

extern MMI_BOOL mmi_sat_send_data_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type);
extern MMI_BOOL mmi_sat_recv_data_response(mmi_sim_enum sim_id, mmi_core_sat_rsp_enum res_type);


extern void mmi_sat_create_folder(void);
extern MMI_BOOL mmi_sat_save_calling_icon(mmi_sim_enum sim_id, PU8 icon_data, CHAR *save_path);
extern CHAR *mmi_sat_create_calling_icon_path(mmi_sim_enum sim_id, CHAR **save_path);

extern void mmi_sat_sim_reboot(mmi_sim_enum sim_id);
extern void mmi_sat_nw_detach_before_reboot(mmi_sim_enum sim_id);
extern void mmi_sat_nw_detach_before_reboot_hdlr(void *info, int mod_src);

extern void mmi_sat_get_screen_capability(U8 *max_char_down, U8 *max_char_accross);

#endif /* _MMI_SAT_RSP_H */
