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
 *  DmSrvSession.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * DM service session header.
 *
 * Author:
 * -------
 * -------
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __DM_SRV_SESSION_H__
#define __DM_SRV_SESSION_H__

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "DMTypeDef.h"
#include "DLAgentSrvGProt.h"
#include "DmSrvIprot.h"
/****************************************************************************
 * Define
 ****************************************************************************/
#define TMP_BUFFER_SIZE 256
#define DM_PUSH_TEMP_FILE_NAME L"Z:\\@dm\\dmpush.tmp"

/****************************************************************************
 * Typedef
 ****************************************************************************/
typedef enum
{
    SRV_DM_SESSION_STATUS_IDLE,
    SRV_DM_SESSION_STATUS_NOTIFICATION_WAIT_CNF,
    SRV_DM_SESSION_STATUS_NOTIFICATION_CNF,
    SRV_DM_SESSION_STATUS_PROCESSING,
    SRV_DM_SESSION_STATUS_SUSPEND,
    SRV_DM_SESSION_STATUS_ABORT,
    SRV_DM_SESSION_STATUS_ALERT_WAIT_CNF,
    SRV_DM_SESSION_STATUS_END
} srv_dm_session_status_enum;

typedef struct
{
    srv_dm_session_status_enum session_status;
    dm_ui_mode_enum notification_ui_mode;
    srv_dm_app_adp_session_ending_msg_enum ending_msg;
    dm_alert_struct *alert;
} srv_dm_session_cntx;

/****************************************************************************
 * Global variable
 ****************************************************************************/

/****************************************************************************
 * Global Function
 ****************************************************************************/
extern void srv_dm_session_init(void);
extern void srv_dm_session_da_push_setting(
    S32 session_id,
    S32 mime_type,
    S32 mime_subtype,
    S32 action,
    U32 filesize,
    PS8 url,
    PS8 mime_type_string,
    U32 content_len,
    PS8 content,
    srv_da_setting_struct * setting);
extern void srv_dm_session_notification_receive_da_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 filepath,
        PS8 url,
        PS8 mime_type_string);
extern void srv_dm_session_bootstrap_receive_da_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 filepath,
        PS8 url,
        PS8 mime_type_string);
extern void srv_dm_session_set_status(srv_dm_session_status_enum session_status);
extern srv_dm_session_status_enum srv_dm_session_get_status(void);
extern void srv_dm_session_notification_ind_hdlr(void *msg);
extern void srv_dm_session_send_app_notification_evt(void);
extern void srv_dm_session_notification_app_rsp(dm_ui_interaction_enum result);
extern void srv_dm_session_send_notification_rsp(dm_ui_interaction_enum result);
extern void srv_dm_session_start_ind_hdlr(void *msg);
extern void srv_dm_session_finish_ind_hdlr(void *msg);
extern MMI_BOOL srv_dm_session_check_suspend(void);
extern void srv_dm_session_suspend(void);
extern void srv_dm_session_resume(void);
extern void srv_dm_session_suspend_timeout_hdlr(void);
extern void srv_dm_session_abort(void);
extern void srv_dm_session_finish_evt(void);
extern void srv_dm_session_send_app_session_abort_evt(void);
extern void srv_dm_session_send_cancel_req(void);
extern void srv_dm_session_ps_status_ind_hdlr(void *msg);
extern void srv_dm_session_set_ending_msg(srv_dm_app_adp_session_ending_msg_enum ending_msg);
extern void srv_dm_session_send_app_ending_msg_evt(void);
extern void srv_dm_session_alert_init(void *alert_ind);
extern void srv_dm_session_alert_deinit(void);
extern void srv_dm_session_alert_ind_hdlr(void *msg);
extern void srv_dm_session_alert_send_app_alert_evt(void);
extern void srv_dm_session_alert_send_rsp(dm_alert_rsp_struct *alert_rsp);
extern void srv_dm_session_alert_app_rsp(dm_alert_rsp_struct *alert_rsp);
extern MMI_BOOL srv_dm_session_alert_get_option_val(U32 mask, void *val);
extern WCHAR* srv_dm_session_alert_get_display_str_ptr(void);

#endif /* __DM_SRV_SESSION_H__ */
