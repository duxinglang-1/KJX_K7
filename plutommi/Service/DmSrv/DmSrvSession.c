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
 *  DmSrvSession.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  DM service session manager.
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
#ifdef SYNCML_DM_SUPPORT
/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "MMI_include.h"
#include "MMIDataType.h"
#include "DmSrvSession.h"
#include "DmSrvMain.h"
#include "DmSrvFota.h"
#include "DmSrvIprot.h"
#include "DmSrvGprot.h"
#include "DmSrvUtil.h"
#include "DMTypeDef.h"
#include "DmSelfRegisterGprot.h"
#include "mmi_rp_srv_dm_def.h"
/****************************************************************************
 * Global Variable
 ****************************************************************************/

/****************************************************************************
 * Static Variable
 ****************************************************************************/
static srv_dm_session_cntx session_cntx;

/****************************************************************************
 * Local Function
 ****************************************************************************/

void srv_dm_session_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_dm_session_notification_ind_hdlr, MSG_ID_DM_NOTIFICATION_INIT_SESSION_REQ_IND);
    //SetProtocolEventHandler(mmi_dmui_userpin_ind_handle, MSG_ID_DM_GET_BOOTSTRAP_USERPIN_REQ_IND);
    SetProtocolEventHandler(srv_dm_session_alert_ind_hdlr, MSG_ID_DM_ALERT_REQ_IND);
    SetProtocolEventHandler(srv_dm_session_start_ind_hdlr, MSG_ID_DM_SESSION_START_IND);
    SetProtocolEventHandler(srv_dm_session_finish_ind_hdlr, MSG_ID_DM_SESSION_FINISH_IND);
    SetProtocolEventHandler(srv_dm_session_ps_status_ind_hdlr, MSG_ID_DM_PS_STATUS_IND);

    srv_dm_session_set_status(SRV_DM_SESSION_STATUS_IDLE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dmui_da_push_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_id                  [IN]        
 *  mime_type                   [IN]        
 *  mime_subtype                [IN]        
 *  action                      [IN]        
 *  filesize                    [IN]        
 *  url                         [IN]        
 *  mime_type_string            [IN]      
 *  content_len                 [IN]
 *  content                     [IN]
 *  setting                     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_session_da_push_setting(
    S32 session_id,
    S32 mime_type,
    S32 mime_subtype,
    S32 action,
    U32 filesize,
    PS8 url,
    PS8 mime_type_string,
    U32 content_len,
    PS8 content,
    srv_da_setting_struct * setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_da_push_setting(
        session_id,
        mime_type,
        mime_subtype,
        action,
        filesize,
        url,
        mime_type_string,
        content_len,
        content,
        setting);

#ifdef __MMI_USB_SUPPORT__
    if (MMI_TRUE == srv_usb_is_in_mass_storage_mode())
    {
        setting->storage = SRV_DA_STORAGE_PUSH_TEMP;
    }
    else
    {
        setting->storage = SRV_DA_STORAGE_GIVEN;
        setting->drv = SRV_FMGR_SYSTEM_DRV;
        mmi_wcscpy(setting->folder, L"@dm\\");
    }
#else
    setting->storage = SRV_DA_STORAGE_GIVEN;
    setting->drv = SRV_FMGR_SYSTEM_DRV;
    mmi_wcscpy(setting->folder, L"@dm\\");
#endif /* __MMI_USB_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  dm_receive_da_file
 * DESCRIPTION
 *  receive the push message file
 * PARAMETERS
 *  session_id              [IN]        
 *  mime_type               [IN]        The mime type of file
 *  mime_subtype            [IN]        The sub mime type of file
 *  action                  [IN]        
 *  filepath                [IN]        Of file
 *  url                     [IN]        
 *  mime_type_string        [IN]        The originaly mime type string get from server
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_session_notification_receive_da_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 filepath,
        PS8 url,
        PS8 mime_type_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *data_ptr = NULL;
    kal_int32 data_len = 0;
    kal_uint32 read_len = 0;
    FS_HANDLE fSrc, fDes;
    dm_push_struct *ptr = NULL;
    mmi_sim_enum used_sim = srv_dm_get_reg_sim();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_RECV_DA_FILE, used_sim);
    if ((used_sim == MMI_SIM1 && action == MMI_DA_PUSH_SIM2) ||
        (used_sim == MMI_SIM2 && action == MMI_DA_PUSH_SIM1) ||
        used_sim == MMI_SIM_NONE)
    {
        return;
    }

    fSrc = FS_Open(filepath, FS_READ_ONLY);

    if (fSrc < 0)
    {
        /* ASSERT(0); */

        return;
    }

    fDes = FS_Open(DM_PUSH_TEMP_FILE_NAME, FS_READ_WRITE | FS_CREATE_ALWAYS);

    if (fDes < 0)
    {
        FS_Close(fSrc);

        FS_Delete(filepath);

        return;
    }

    if (FS_NO_ERROR == FS_GetFileSize(fSrc, (kal_uint32*) & data_len))
    {
        data_ptr = (kal_uint8*)OslMalloc(TMP_BUFFER_SIZE);

        data_ptr[0] = 0x01;
        data_ptr[1] = 0x06;
        data_ptr[2] = 0x03;
        data_ptr[3] = 0xC4;
        data_ptr[4] = 0xAF;
        data_ptr[5] = 0x87;

        if (FS_NO_ERROR == FS_Write(fDes, data_ptr, 6, NULL))
        {
            while (data_len > 0)
            {
                if (FS_NO_ERROR == FS_Read(fSrc, data_ptr, TMP_BUFFER_SIZE, &read_len))
                {
                    if (FS_NO_ERROR == FS_Write(fDes, data_ptr, read_len, NULL))
                        data_len -= read_len;
                    else
                        break;
                }
                else
                    break;
            }
        }

        OslMfree(data_ptr);
    }

    FS_Close(fSrc);
    FS_Close(fDes);
    FS_Delete(filepath);

    ptr = OslAllocDataPtr(dm_push_struct);

    mmi_ucs2cpy((S8*) (ptr->file_path), (const S8*)DM_PUSH_TEMP_FILE_NAME);

    ptr->type = DM_MSG_TYPE_NOTIFICATION;

    mmi_frm_send_ilm(
        MOD_DM,
        MSG_ID_DM_PUSH_IND,
        (oslParaType*)ptr,
        NULL);
}

/*****************************************************************************
 * FUNCTION
 *  dm_bootstrap_receive_da_file
 * DESCRIPTION
 *  receive the push message file
 * PARAMETERS
 *  session_id              [IN]        
 *  mime_type               [IN]        The mime type of file
 *  mime_subtype            [IN]        The sub mime type of file
 *  action                  [IN]        
 *  filepath                [IN]        Of file
 *  url                     [IN]        
 *  mime_type_string        [IN]        The originaly mime type string get from server
 * RETURNS
 *  void
 *****************************************************************************/
void srv_dm_session_bootstrap_receive_da_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 filepath,
        PS8 url,
        PS8 mime_type_string)
{
#ifdef _DM_BOOTSTRAP_SUPPORT_
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *data_ptr = NULL;
    kal_uint8 *header_ptr = NULL;
    kal_uint8 *temp_ptr = NULL;
    kal_int32 data_len = 0;
    kal_uint32 read_len = 0;
    FS_HANDLE fSrc, fDes;
    dm_push_struct *ptr = NULL;
    kal_int32 header_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_BOOTSTRAP_RECV_DA_FILE, action);

    fSrc = FS_Open(filepath, FS_READ_ONLY);

    if (fSrc < 0)
    {
        return;
    }

    fDes = FS_Open(DM_PUSH_TEMP_FILE_NAME, FS_READ_WRITE | FS_CREATE_ALWAYS);

    if (fDes < 0)
    {
        FS_Close(fSrc);

        FS_Delete(filepath);

        return;
    }

    if (FS_NO_ERROR == FS_GetFileSize(fSrc, (kal_uint32*) & data_len))
    {
        temp_ptr = (kal_uint8*) mmi_da_get_header(session_id, &header_len);

        if (temp_ptr && header_len > 0)
        {
            header_ptr = (kal_uint8*)OslMalloc(header_len + 1);

            memcpy(header_ptr, temp_ptr, header_len);

            header_ptr[header_len] = '\0';

            if (header_len > 2)
            {
                if (header_ptr[header_len - 2] == 0x0D && header_ptr[header_len - 1] == 0x0A)
                {
                    header_ptr[header_len - 2] = '\0';

                    header_len -= 2;
                }
            }

            header_len++;

            if (FS_NO_ERROR == FS_Write(fDes, &header_len, sizeof(kal_int32), NULL)
                && FS_NO_ERROR == FS_Write(fDes, header_ptr, header_len, NULL))
            {
                data_ptr = (kal_uint8*) OslMalloc(TMP_BUFFER_SIZE);

                while (data_len > 0)
                {
                    if (FS_NO_ERROR == FS_Read(fSrc, data_ptr, TMP_BUFFER_SIZE, &read_len))
                    {
                        if (FS_NO_ERROR == FS_Write(fDes, data_ptr, read_len, NULL))
                            data_len -= read_len;
                        else
                            break;
                    }
                    else
                        break;
                }

                OslMfree(data_ptr);
            }

            OslMfree(header_ptr);
        }
    }

    FS_Close(fSrc);

    FS_Close(fDes);

    FS_Delete(filepath);

    ptr = OslAllocDataPtr(dm_push_struct);

    mmi_ucs2cpy((S8*) (ptr->file_path), (const S8*)DM_PUSH_TEMP_FILE_NAME);

    ptr->type = DM_MSG_TYPE_BOOTSTRAP;

    mmi_frm_send_ilm(
        MOD_DM,
        MSG_ID_DM_PUSH_IND,
        (oslParaType*)ptr,
        NULL);
#else /* _DM_BOOTSTRAP_SUPPORT_ */

    FS_Delete(filepath);

#endif /* _DM_BOOTSTRAP_SUPPORT_ */
}


void srv_dm_session_set_status(srv_dm_session_status_enum session_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SESSION_SET_STATUS, session_status);
    session_cntx.session_status = session_status;
}


srv_dm_session_status_enum srv_dm_session_get_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return session_cntx.session_status;
}


void srv_dm_session_notification_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_ui_mode_struct *notification_ind = (dm_ui_mode_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SESSION_NOTIFICATION_IND_HDLR);

    // new session, close pending interactions, special fota update defer
    srv_dm_cancel_defer_user_interaction();
    // todo notify to deinit fota update screen

    if (srv_dm_check_sr_sim_match() == MMI_FALSE)
    {
        return;
    }

    srv_dm_session_set_status(SRV_DM_SESSION_STATUS_NOTIFICATION_WAIT_CNF);

    if (notification_ind->ui_mode == DM_UI_MODE_NOTSPECIFIED)
    {
        session_cntx.notification_ui_mode = DM_UI_MODE_USERINTERACTION;
    }
    else
    {
        session_cntx.notification_ui_mode = notification_ind->ui_mode;
    }

#ifdef __DM_LAWMO_SUPPORT__
    if (mmi_dmui_is_phone_lock() == MMI_TRUE)
    {
        session_cntx.notification_ui_mode = DM_UI_MODE_BACKGROUND;
    }
#endif /* __DM_LAWMO_SUPPORT__ */

    switch (session_cntx.notification_ui_mode)
    {
        case DM_UI_MODE_BACKGROUND:
        {
            srv_dm_session_set_status(SRV_DM_SESSION_STATUS_NOTIFICATION_CNF);
            srv_dm_session_send_notification_rsp(DM_UI_INTERACTION_ACTION_ACCEPT);
        }
            break;

        case DM_UI_MODE_INFORMATION: 
        {
            srv_dm_session_set_status(SRV_DM_SESSION_STATUS_NOTIFICATION_CNF);
            srv_dm_session_send_notification_rsp(DM_UI_INTERACTION_ACTION_ACCEPT);

            srv_dm_session_send_app_notification_evt();
        }
            break;

        case DM_UI_MODE_USERINTERACTION: 
        {
            srv_dm_session_set_status(SRV_DM_SESSION_STATUS_NOTIFICATION_WAIT_CNF);

            srv_dm_session_send_app_notification_evt();
        }
            break;

        default:
            break;
    }
    srv_dm_session_check_suspend();
}


void srv_dm_session_send_app_notification_evt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_app_adp_evt_display_notification_struct display_notification_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    display_notification_evt.ui_mode = session_cntx.notification_ui_mode;
    MMI_TRACE(
        MMI_CONN_TRC_G3_DM,
        TRC_SRV_DM_SESSION_SEND_APP_NOTIFICATION_EVT,
        display_notification_evt.ui_mode);
    srv_dm_app_adp_send_evt(
        SRV_DM_APP_ADP_EVT_DISPLAY_NOTIFICATION,
        (void*)&display_notification_evt);
}


void srv_dm_session_notification_app_rsp(dm_ui_interaction_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SESSION_NOTIFICATION_APP_RSP, result);
    switch (result)
    {
        case DM_UI_INTERACTION_ACTION_ACCEPT:
        {
            srv_dm_session_set_status(SRV_DM_SESSION_STATUS_NOTIFICATION_CNF);
            srv_dm_session_send_notification_rsp(result);
        }
            break;

        case DM_UI_INTERACTION_ACTION_REJECT:
        case DM_UI_INTERACTION_ACTION_CANCEL:
        {
            srv_dm_session_set_status(SRV_DM_SESSION_STATUS_IDLE);
            srv_dm_session_send_notification_rsp(result);
        }
            break;

        case DM_UI_INTERACTION_ACTION_DEFER:
        {
            srv_dm_defer_user_interaction(
                SRV_DM_APP_ADP_EVT_DISPLAY_NOTIFICATION,
                SRV_DM_TIME_USER_INTERACTION_DEFER);
        }
            break;

        default:
            break;
    }
}


void srv_dm_session_send_notification_rsp(dm_ui_interaction_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_ui_struct *dm_init_session_res = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SESSION_SEND_NOTIFICATION_RSP, result);
    dm_init_session_res = OslAllocDataPtr(dm_ui_struct);
    dm_init_session_res->ui_interaction = result;
    mmi_frm_send_ilm(
        MOD_DM,
        MSG_ID_DM_NOTIFICATION_INIT_SESSION_RES,
        (oslParaType*)dm_init_session_res,
        NULL);
}


void srv_dm_session_start_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SESSION_START_IND_HDLR);
    srv_dm_session_set_status(SRV_DM_SESSION_STATUS_PROCESSING);
    srv_dm_session_set_ending_msg(SRV_DM_APP_ADP_SESSION_ENDING_MSG_NONE);
#ifdef __DM_SCOMO_SUPPORT__
    srv_dm_scomo_reset_report_info();
#endif /* __DM_SCOMO_SUPPORT__ */
}


void srv_dm_session_finish_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_session_progress_struct *session_finish = (dm_session_progress_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SESSION_FINISH_IND_HDLR);
    srv_dm_session_send_app_ending_msg_evt();
    srv_dm_session_finish_evt();
#ifdef __DM_FOTA_SUPPORT__
    if (session_finish->session_process == DM_PROCESS_DOWNLOADING &&
        srv_dm_fota_get_status() == SRV_DM_FOTA_STATUS_USER_QUERY)
    {
        srv_dm_fota_query_finish(SRV_DM_FOTA_QUERY_RESULT_FAIL);
    }
    else
    {
        srv_dm_fota_set_status(SRV_DM_FOTA_STATUS_IDLE);
    }
#endif /* __DM_FOTA_SUPPORT__ */
    // check mem leak
    MMI_ASSERT(session_cntx.alert == NULL);
    memset(&session_cntx, 0x00, sizeof(session_cntx));
}


void srv_dm_session_finish_evt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dm_app_adp_send_evt(SRV_DM_APP_ADP_EVT_SESSION_FINISH, NULL);
}


MMI_BOOL srv_dm_session_check_suspend(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_session_status_enum session_status = srv_dm_session_get_status();
    MMI_BOOL nw_available = srv_dm_check_nw_available();
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (nw_available == MMI_TRUE)
    {
        srv_dm_session_resume();
        result = MMI_FALSE;
    }
    else
    {
        if (session_status == SRV_DM_SESSION_STATUS_SUSPEND ||
            MMI_TRUE == IsMyTimerExist(TIMER_ID_DM_SRV_SESSION_SUSPEND))
        {
            result = MMI_TRUE;
        }
        else if (session_status == SRV_DM_SESSION_STATUS_NOTIFICATION_WAIT_CNF ||
                 session_status == SRV_DM_SESSION_STATUS_ALERT_WAIT_CNF ||
                 session_status == SRV_DM_SESSION_STATUS_NOTIFICATION_CNF ||
                 session_status == SRV_DM_SESSION_STATUS_PROCESSING)
        {
            srv_dm_session_suspend();
            result = MMI_TRUE;
        }
        else
        {
            result = MMI_FALSE;
        }
    }
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SESSION_CHECK_SUSPEND, result);
    return result;
}


void srv_dm_session_suspend(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 curr_timer_id[] = {TIMER_ID_DM_SRV_NOTIFICATION_CNF_USER_INTERACTION,
                           TIMER_ID_DM_SRV_ALERT_CNF_USER_INTERACTION};
    S32 timer_id;
    S32 curr_timer_id_array_size = sizeof(curr_timer_id)/sizeof(curr_timer_id[0]);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SESSION_SUSPEND);
    for (timer_id = curr_timer_id[0]; timer_id < curr_timer_id_array_size; timer_id++)
    {
        if (MMI_TRUE == IsMyTimerExist(timer_id))
        {
            StopTimer(timer_id);
        }
    }

    StartTimer(
        TIMER_ID_DM_SRV_SESSION_SUSPEND,
        SRV_DM_TIME_SESSION_SUSPEND,
        srv_dm_session_suspend_timeout_hdlr);

    if (srv_dm_session_get_status() == SRV_DM_SESSION_STATUS_PROCESSING)
    {
        srv_dm_session_set_status(SRV_DM_SESSION_STATUS_SUSPEND);
    }
}


void srv_dm_session_resume(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SESSION_RESUME);
    StopTimer(TIMER_ID_DM_SRV_SESSION_SUSPEND);
    if (srv_dm_session_get_status() == SRV_DM_SESSION_STATUS_SUSPEND)
    {
        srv_dm_session_set_status(SRV_DM_SESSION_STATUS_PROCESSING);
    }
}


void srv_dm_session_suspend_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SESSION_SUSPEND_TIMEOUT_HDLR);
    // notify ps cancel session
    srv_dm_session_abort();
}


void srv_dm_session_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_session_status_enum session_status = srv_dm_session_get_status();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SESSION_ABORT, session_status);
    srv_dm_cancel_defer_user_interaction();
    srv_dm_session_send_app_session_abort_evt();
    switch (session_status)
    {
        case SRV_DM_SESSION_STATUS_NOTIFICATION_WAIT_CNF:
        {
            srv_dm_session_send_notification_rsp(DM_UI_INTERACTION_ACTION_CANCEL);
            break;
        }

        case SRV_DM_SESSION_STATUS_ALERT_WAIT_CNF:
        {
            dm_alert_rsp_struct alert_rsp;
            alert_rsp.alert_type = session_cntx.alert->alert_type;
            alert_rsp.ui_interaction = DM_UI_INTERACTION_ACTION_CANCEL;
            srv_dm_session_alert_send_rsp(&alert_rsp);
            break;
        }

        case SRV_DM_SESSION_STATUS_SUSPEND:
        case SRV_DM_SESSION_STATUS_PROCESSING:
        {
            srv_dm_session_send_cancel_req();
            break;
        }

        default:
            break;
    }
}


void srv_dm_session_send_app_session_abort_evt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dm_app_adp_send_evt(SRV_DM_APP_ADP_EVT_SESSION_ABORT, NULL);
}


void srv_dm_session_send_cancel_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_send_ilm(
        MOD_DM,
        MSG_ID_DM_CANCEL_REQ,
        NULL,
        NULL);
}


void srv_dm_session_ps_status_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_ps_status_ind_struct *ptr_ps_ind = (dm_ps_status_ind_struct*)msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SESSION_PS_STATUS_IND_HDLR, ptr_ps_ind->status);
    switch (ptr_ps_ind->status)
    {
        case DM_PS_STATUS_DISCONNECTED:
        case DM_PS_STATUS_UNAUTHCATED:
        {
            srv_dm_session_set_ending_msg(SRV_DM_APP_ADP_SESSION_ENDING_MSG_SESSION_FAIL);
            srv_dm_session_set_status(SRV_DM_SESSION_STATUS_ABORT);
            break;
        }

        case DM_PS_STATUS_NOT_ENOUGH_MEMORY:
        {
            srv_dm_session_set_ending_msg(SRV_DM_APP_ADP_SESSION_ENDING_MSG_NO_MEM);
            srv_dm_session_set_status(SRV_DM_SESSION_STATUS_ABORT);
            break;
        }

        default:
            break;
    }
}


void srv_dm_session_set_ending_msg(srv_dm_app_adp_session_ending_msg_enum ending_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SESSION_SET_ENDING_MSG, ending_msg);
    if (session_cntx.notification_ui_mode != DM_UI_MODE_BACKGROUND)
    {
        if (session_cntx.ending_msg != SRV_DM_APP_ADP_SESSION_ENDING_MSG_NONE)
        {
            return;
        }
        else
        {
            session_cntx.ending_msg = ending_msg;
        }
    }
    else
    {
        session_cntx.ending_msg = SRV_DM_APP_ADP_SESSION_ENDING_MSG_NONE;
    }
}


void srv_dm_session_send_app_ending_msg_evt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_app_adp_evt_display_ending_msg_struct ending_msg_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ending_msg_evt.ending_msg = session_cntx.ending_msg;
    srv_dm_app_adp_send_evt(SRV_DM_APP_ADP_EVT_DISPLAY_ENDING_MSG, (void*)&ending_msg_evt);
    srv_dm_session_set_ending_msg(SRV_DM_APP_ADP_SESSION_ENDING_MSG_NONE);
}


void srv_dm_session_alert_init(void *alert_ind)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SESSION_ALERT_INIT);
    session_cntx.alert = OslMalloc(sizeof(dm_alert_struct));
    memcpy(session_cntx.alert, alert_ind, sizeof(dm_alert_struct));

    if (session_cntx.alert->b_filename == KAL_TRUE)
    {
        FS_HANDLE fd;
        WCHAR *file_path;
        U32 size;

        file_path = OslMalloc(sizeof(WCHAR) * mmi_wcslen((WCHAR*)session_cntx.alert->alert_string));
        mmi_wcscpy(file_path, (WCHAR*)session_cntx.alert->alert_string);
        session_cntx.alert->alert_string = OslMalloc(session_cntx.alert->buffer_len);
        fd = FS_Open(file_path, FS_READ_ONLY);

        if (fd >= FS_NO_ERROR)
        {
            FS_Read(
                fd,
                session_cntx.alert->alert_string,
                sizeof(session_cntx.alert->buffer_len),
                &size);
            FS_Close(fd);
            FS_Delete(file_path);
        }
        else
        {
            session_cntx.alert->alert_string = NULL;
        }
        OslMfree(file_path);
    }
}


void srv_dm_session_alert_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SESSION_ALERT_DEINIT);
    if (session_cntx.alert != NULL)
    {
        if (session_cntx.alert->alert_string)
        {
            OslMfree(session_cntx.alert->alert_string);
            session_cntx.alert->alert_string = NULL;
        }
        OslMfree(session_cntx.alert);
        session_cntx.alert = NULL;
    }
}


void srv_dm_session_alert_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_alert_struct *alert_ind = (dm_alert_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SESSION_ALERT_IND_HDLR);
    if (srv_dm_check_sr_sim_match() == MMI_FALSE)
    {
        if (alert_ind->alert_string)
        {
            OslMfree(alert_ind->alert_string);
            alert_ind->alert_string = NULL;
        }
        return;
    }

    srv_dm_session_alert_init(alert_ind);
    srv_dm_session_set_status(SRV_DM_SESSION_STATUS_ALERT_WAIT_CNF);

#ifdef __DM_LAWMO_SUPPORT__
    if (mmi_dmui_is_phone_lock() == MMI_TRUE)
    {
        dm_alert_rsp_struct alert_rsp;
        alert_rsp.alert_type = alert_ind->alert_type;
        alert_rsp.ui_interaction = DM_UI_INTERACTION_ACTION_ACCEPT;
        srv_dm_session_alert_send_rsp(&alert_rsp);
        srv_dm_session_set_status(SRV_DM_SESSION_STATUS_PROCESSING);
        return;
    }
#endif /* __DM_LAWMO_SUPPORT__ */

    srv_dm_session_alert_send_app_alert_evt();
}


void srv_dm_session_alert_send_app_alert_evt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dm_app_adp_evt_display_alert_struct display_alert_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G3_DM,
        TRC_SRV_DM_SESSION_ALERT_SEND_APP_ALERT_EVT,
        session_cntx.alert->alert_type);
    display_alert_evt.alert = session_cntx.alert;
    srv_dm_app_adp_send_evt(
        SRV_DM_APP_ADP_EVT_DISPLAY_ALERT,
        (void*)&display_alert_evt);
}


void srv_dm_session_alert_send_rsp(dm_alert_rsp_struct *alert_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_alert_rsp_struct *dm_alert_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_alert_rsp = OslAllocDataPtr(dm_alert_rsp_struct);
    dm_alert_rsp->alert_type = session_cntx.alert->alert_type;
    switch (dm_alert_rsp->alert_type)
    {
        case DM_UI_INTERACTION_DISPLAY:
        case DM_UI_INTERACTION_CONFIRM:
        {
            dm_alert_rsp->ui_interaction = alert_rsp->ui_interaction;
            break;
        }

        default:
            break;
    }

    mmi_frm_send_ilm(
        MOD_DM,
        MSG_ID_DM_ALERT_RES,
        (oslParaType*)dm_alert_rsp,
        NULL);

    srv_dm_session_alert_deinit();
}


void srv_dm_session_alert_app_rsp(dm_alert_rsp_struct *alert_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SESSION_ALERT_APP_RSP, alert_rsp->ui_interaction);
    if (srv_dm_session_get_status() == SRV_DM_SESSION_STATUS_ALERT_WAIT_CNF)
    {
        switch (alert_rsp->ui_interaction)
        {
            case DM_UI_INTERACTION_ACTION_ACCEPT:
            {
                srv_dm_session_set_status(SRV_DM_SESSION_STATUS_PROCESSING);
                srv_dm_session_alert_send_rsp(alert_rsp);
                break;
            }

            case DM_UI_INTERACTION_ACTION_REJECT:
            case DM_UI_INTERACTION_ACTION_CANCEL:
            {
                srv_dm_session_set_status(SRV_DM_SESSION_STATUS_ABORT);
                srv_dm_session_alert_send_rsp(alert_rsp);
                break;
            }

            case DM_UI_INTERACTION_ACTION_DEFER:
            {
                srv_dm_defer_user_interaction(
                    SRV_DM_APP_ADP_EVT_DISPLAY_ALERT,
                    SRV_DM_TIME_USER_INTERACTION_DEFER);
                break;
            }

            default:
                break;
        }
    }
}


MMI_BOOL srv_dm_session_alert_get_option_val(U32 mask, void *val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((session_cntx.alert->option_mask & mask) == mask)
    {
        switch (mask)
        {
            case DM_ALERT_MINDT_MASK:
            {
                *(U32*)val = session_cntx.alert->min_dt > 0 ?
                              session_cntx.alert->min_dt * 1000 :
                              SRV_DM_TIME_ALERT_DEFAULT_MINDT;
                break;
            }

            case DM_ALERT_MAXDT_MASK:
            {
                *(U32*)val = session_cntx.alert->max_dt > 0 ?
                              session_cntx.alert->max_dt * 1000 :
                              SRV_DM_TIME_ALERT_DEFAULT_MAXDT;
                break;
            }

            case DM_ALERT_DR_MASK:
            {
                mmi_wcscpy(
                    (WCHAR*)val,
                    (WCHAR*)session_cntx.alert->dr);
                break;
            }

            case DM_ALERT_MAXLEN_MASK:
            {
                *(U32*)val = session_cntx.alert->max_len;
                break;
            }

            case DM_ALERT_IT_MASK:
            {
                *(dm_it_type_enum*)val = session_cntx.alert->it;
                break;
            }

            case DM_ALERT_ET_MASK:
            {
                *(dm_et_type_enum*)val = session_cntx.alert->et;
                break;
            }

            default:
                break;
        }
    }
    else
    {
        ret = MMI_FALSE;
    }

    MMI_TRACE(MMI_CONN_TRC_G3_DM, TRC_SRV_DM_SESSION_GET_OPTION_VAL, mask, *(U32*)val, ret);
    return ret;
}


WCHAR* srv_dm_session_alert_get_display_str_ptr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (WCHAR*)session_cntx.alert->alert_string;
}


void ut_srv_dm_session_send_notification_ind(void)
{
    dm_ui_mode_struct *ptr;
    ptr = OslAllocDataPtr(dm_ui_mode_struct);
    ptr->ui_mode = DM_UI_MODE_USERINTERACTION;
    mmi_frm_send_ilm(
        MOD_MMI,
        MSG_ID_DM_NOTIFICATION_INIT_SESSION_REQ_IND,
        (oslParaType*)ptr,
        NULL);
}

void ut_srv_dm_session_send_alert_ind(void)
{
    dm_alert_struct *ptr;
    ptr = OslAllocDataPtr(dm_alert_struct);
    ptr->alert_string = OslMalloc(16);
    mmi_wcscpy((WCHAR*)ptr->alert_string, L"Hello");
    ptr->alert_type = DM_UI_INTERACTION_CONFIRM;
    ptr->buffer_len = 16;
    ptr->max_dt = 10;
    ptr->min_dt = 5;
    ptr->option_mask = DM_ALERT_MAXDT_MASK;
    mmi_frm_send_ilm(
        MOD_MMI,
        MSG_ID_DM_ALERT_REQ_IND,
        (oslParaType*)ptr,
        NULL);
}
#endif /* SYNCML_DM_SUPPORT */
