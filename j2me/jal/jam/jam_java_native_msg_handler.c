/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
* permission of MediaTek Inc. (C) 2005
*
* BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
* NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
* SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
* BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
* WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
* LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
* RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
* THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * --------- 
 *   jam_java_native_msg_handler.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file handles java level massages and native level messages.
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
 * removed!
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "MMI_features.h"
#include "jam_msg_handler.h"

#include "jnw_interface.h"
#include "jnw_internal.h"

#include "jal.h"
#include "jvm_internal.h"
#include "jvm_adaptor.h"

#include "jam_internal.h"
#include "jam_msg_handler.h"
#include "j2me_trace.h"
#include "jam_interface.h"

#include "GlobalDefs.h"
#include "JavaAgencyDef.h"
#include "JavaAgencyProt.h"
#include "wgui_categories_util.h"
#include "j2me_custom_param.h"
#include "wapadp.h"
#include "mmsadp.h"
#include "app_ua.h"
#include "jam_mvm_manager.h"
#include "mmc_struct.h"
#include "custpack_java_certs.h"
#include "app_str.h"
#include "FileMgrSrvGProt.h"

char g_jam_ota_user_name[MMI_JAVA_AUTH_LEN_USERNAME];
char g_jam_ota_passwd[MMI_JAVA_AUTH_LEN_PASSWORD];
//static kal_int32 g_jam_http_channel_id;
extern kal_uint32 g_jam_need_storage_size;
kal_int32 g_jam_need_lauch = 0;
kal_int32 g_jam_install_mids_id;
kal_uint32 hdr_len = 0;
kal_uint32 data_len = 0;
extern kal_char g_jam_need_storage_drive;
kal_int32 g_jam_download_jar_check;
/* HTTP parameters */
kal_uint32 g_jam_http_conn_id = 0;
kal_uint8 *rsp_hdr = NULL;
kal_uint8 *content = NULL;
kal_bool terminated_by_user_cancel = KAL_FALSE;
extern jam_drm_sd_callback_struct_t g_jam_drm_sd_callback_state;
kal_bool g_jam_install_bearer_switch = KAL_FALSE;
/*****************************************************************************
 * FUNCTION
 *  jam_vm_get_next_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wait_forever        [IN]        
 *  expected_msg        [IN]        
 *  clean_msg           [IN]        
 *  must_match          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jam_vm_get_next_event(kal_bool wait_forever, msg_type expected_msg, kal_bool clean_msg, kal_bool must_match)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool abort_received = KAL_FALSE;
    kal_int32 return_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return_value = get_next_event(wait_forever, expected_msg, clean_msg, must_match, &abort_received);
    if (abort_received)
    {
        return jam_call_back_functions.jam_get_event_abort_handler();
    }
    return return_value;
}


/*****************************************************************************
 * FUNCTION
 *  clean_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 clean_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return jam_vm_get_next_event(KAL_FALSE, (msg_type)0, KAL_TRUE, KAL_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  jam_install_user_confirm
 * DESCRIPTION
 *  Send MSG_ID_MMI_JAVA_INSTALL_CONFIRM_IND massage containing confirm
 *  string to MMI, and wait for the MMI if the installation should be
 *  continued
 * PARAMETERS
 *  confirmMsg      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jam_install_user_confirm(kal_wchar *confirmMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_install_confirm_ind_struct *install_cnf_ind;
    kal_int32 return_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    install_cnf_ind = construct_local_para(sizeof(mmi_java_install_confirm_ind_struct), TD_CTRL);

    install_cnf_ind->confirm_msg = confirmMsg;

    check_incoming_call_and_block();
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_INSTALL_CONFIRM_IND,install_cnf_ind);
    return_value = jam_vm_get_next_event(KAL_TRUE, MSG_ID_MMI_JAVA_INSTALL_CONFIRM_RES, KAL_FALSE, KAL_FALSE);

    if (return_value == 1)
    {
        install_update_status.install_cancelled = KAL_FALSE;
        return KAL_TRUE;
    }
    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  jam_install_get_rms_confirm
 * DESCRIPTION
 *  Send MSG_ID_MMI_JAVA_INSTALL_RESET_RMS_IND massage to MMI, and wait for
 *  the response of MMI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jam_install_get_rms_confirm(kal_int32 *error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_install_reset_rms_ind_struct *reset_rms_ind;
    kal_int32 return_value = 0;
    kal_bool abort_received = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_rms_ind = construct_local_para(sizeof(mmi_java_install_reset_rms_ind_struct), TD_CTRL);

    check_incoming_call_and_block();
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_INSTALL_RESET_RMS_IND,reset_rms_ind);

    return_value = get_next_event(KAL_TRUE, MSG_ID_MMI_JAVA_INSTALL_RESET_RMS_RES, KAL_FALSE, KAL_FALSE, &abort_received);
    if (abort_received)
    {
        *error_code = USER_CANCEL;
        return KAL_FALSE;
    }
    if (return_value)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  jam_update_confirm
 * DESCRIPTION
 *  Send the installation result to MMI
 * PARAMETERS
 *  success     [IN]        
 *  buffer      [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_update_confirm(kal_int32 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_update_cnf_struct *update_cnf_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    install_update_status.has_returned_res = KAL_TRUE;

    update_cnf_ptr = construct_local_para(sizeof(mmi_java_mids_update_cnf_struct), TD_CTRL);
    update_cnf_ptr->download_error_code = download_error_code;
    update_cnf_ptr->error_string = get_string_by_error_code(error_code);
    if (error_code!=INSUFFICIENT_STORAGE)
    {
        g_jam_need_storage_size = 0;
        g_jam_need_storage_drive = 'Z';
    }
    update_cnf_ptr->error_code = error_code;
    check_incoming_call_and_block();
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MIDS_UPDATE_CNF,update_cnf_ptr);

}


/*****************************************************************************
 * FUNCTION
 *  jam_install_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  success     [IN]        
 *  buffer      [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jam_install_confirm(kal_int32 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_install_mids_cnf_struct *install_cnf_ptr;
    kal_uint32 retErrorCode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    install_update_status.has_returned_res = KAL_TRUE;

    retErrorCode = error_code;

    install_cnf_ptr = construct_local_para(sizeof(mmi_java_install_mids_cnf_struct), TD_CTRL);
    install_cnf_ptr->download_error_code = download_error_code;
    install_cnf_ptr->mids_storage_id = NULL;
    install_cnf_ptr->mids_name = NULL;
    install_cnf_ptr->mids_vendor = NULL;
    install_cnf_ptr->mids_version = NULL;
    install_cnf_ptr->vm_id = -1;

    install_cnf_ptr->need_storage_size = 0;
    install_cnf_ptr->need_lauch = KAL_FALSE;
    install_cnf_ptr->drm_file_path = NULL;
    install_cnf_ptr->drm_serial = 0;

    if (error_code == INSUFFICIENT_STORAGE)
    {
        retErrorCode = INSUFFICIENT_STORAGE;
        #ifdef __MMI_JAVA_INSTALL_DELETE_MENU__
        install_cnf_ptr->storage_drive = (kal_int32) g_jam_need_storage_drive;
        install_cnf_ptr->need_storage_size = g_jam_need_storage_size;
        #else
        install_cnf_ptr->storage_drive = 'Z';
        install_cnf_ptr->need_storage_size = 0;
        g_jam_need_storage_drive = 'Z';
        g_jam_need_storage_size = 0;
        #endif
    }
    else if (error_code == MIDLET_RUNNING)
    {
        retErrorCode = MIDLET_RUNNING;
        if(g_jam_install_report.install_mids_storage_id)
        {
            #ifdef __MVM__
            install_cnf_ptr->vm_id = jam_mvm_get_vm_id(g_jam_install_report.install_mids_storage_id,-1);
            #else
            install_cnf_ptr->vm_id = 0;    
            #endif
            jam_listmem_free(g_jam_install_report.install_mids_storage_id);
            g_jam_install_report.install_mids_storage_id = NULL;
        }
    }
    else if (error_code == DRM_NO_RIGHT)
    {
        kal_int32 len = 0;
        kal_wchar* filepath = NULL;
        retErrorCode = DRM_RIGHT_NOT_RECEIVED;
        if(g_jam_drm_current_install_jar_path)
        {
            len = (app_ucs2_strlen((const kal_int8*)g_jam_drm_current_install_jar_path)+1)<<1;
            filepath = (kal_wchar*)get_ctrl_buffer(len);
            memset(filepath,0,len);
            memcpy(filepath,g_jam_drm_current_install_jar_path,len);
            jam_listmem_free(g_jam_drm_current_install_jar_path);
            g_jam_drm_current_install_jar_path = NULL;
        }
        install_cnf_ptr->drm_file_path = filepath;
        install_cnf_ptr->drm_serial = g_jam_drm_sd_callback_state.waiting_right_serial;
        install_cnf_ptr->acquire_right = g_jam_drm_sd_callback_state.need_acquire_right;
    }
    else if (error_code == POST_ERROR || 
          error_code ==J2ME_NO_ERROR ||
          error_code == J2ME_USER_CANCEL ||
          error_code == USER_CANCEL        
        )
    {
        kal_int32 len = 0;
        kal_wchar* wtemp = NULL;
        kal_char* temp = NULL;
        retErrorCode = error_code;
        if(error_code == USER_CANCEL)
        {
            retErrorCode = J2ME_USER_CANCEL;
        }
        install_cnf_ptr->installed_drv = g_jam_install_report.install_drv;
        if (g_jam_need_lauch && jam_mvm_has_fg_running_vm() == KAL_FALSE)
        {
            install_cnf_ptr->need_lauch = (kal_bool)g_jam_need_lauch;
            install_cnf_ptr->mids_id = g_jam_install_report.install_mids_id;
        }
        if(g_jam_install_report.install_mids_storage_id){
            len = strlen(g_jam_install_report.install_mids_storage_id)+1;
            temp = (kal_char*)get_ctrl_buffer(len);
            memset(temp,0,len);
            memcpy(temp,g_jam_install_report.install_mids_storage_id,len);
            install_cnf_ptr->mids_storage_id = temp;
            jam_listmem_free(g_jam_install_report.install_mids_storage_id);
            g_jam_install_report.install_mids_storage_id = NULL;
        }
        if(g_jam_install_report.install_mids_name){
            len = (app_ucs2_strlen((const kal_int8*)g_jam_install_report.install_mids_name)+1)<<1;
            wtemp = (kal_wchar*)get_ctrl_buffer(len);
            memset(wtemp,0,len);
            memcpy(wtemp,g_jam_install_report.install_mids_name,len);
            install_cnf_ptr->mids_name = wtemp;
            jam_listmem_free(g_jam_install_report.install_mids_name);
            g_jam_install_report.install_mids_name = NULL;
        }
        if(g_jam_install_report.install_mids_vendor){
            len = (app_ucs2_strlen((const kal_int8*)g_jam_install_report.install_mids_vendor)+1)<<1;
            wtemp = (kal_wchar*)get_ctrl_buffer(len);
            memset(wtemp,0,len);
            memcpy(wtemp,g_jam_install_report.install_mids_vendor,len);
            install_cnf_ptr->mids_vendor = wtemp;
            jam_listmem_free(g_jam_install_report.install_mids_vendor);
            g_jam_install_report.install_mids_vendor = NULL;
        }
        if(g_jam_install_report.install_mids_version){
            len = strlen(g_jam_install_report.install_mids_version)+1;
            temp = (kal_char*)get_ctrl_buffer(len);
            memset(temp,0,len);
            memcpy(temp,g_jam_install_report.install_mids_version,len);
            install_cnf_ptr->mids_version = temp;
            jam_listmem_free(g_jam_install_report.install_mids_version);
            g_jam_install_report.install_mids_version = NULL;
        }

    }
    /*free install report information*/
    if(g_jam_install_report.install_mids_name)
    {
        jam_listmem_free(g_jam_install_report.install_mids_name);
        g_jam_install_report.install_mids_name = NULL;
    }
    if(g_jam_install_report.install_mids_storage_id)
    {
        jam_listmem_free(g_jam_install_report.install_mids_storage_id);
        g_jam_install_report.install_mids_storage_id = NULL;
    }
    if(g_jam_install_report.install_mids_vendor)
    {
        jam_listmem_free(g_jam_install_report.install_mids_vendor);
        g_jam_install_report.install_mids_vendor = NULL;
    }
    if(g_jam_install_report.install_mids_version)
    {
        jam_listmem_free(g_jam_install_report.install_mids_version);
        g_jam_install_report.install_mids_version = NULL;
    }
    /* reset paramter when install success */
    if (error_code != INSUFFICIENT_STORAGE)
    {
        g_jam_need_storage_size = 0;
        g_jam_need_storage_drive = 'Z';
    }
    install_cnf_ptr->error_code = retErrorCode;

    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_INSTALL_MIDS_CNF,install_cnf_ptr);
}
/*****************************************************************************
 * FUNCTION
 *  jam_download_progess
 * DESCRIPTION
 *  Send install progess status to MMI. MMI may show progress bar for the status.
 * PARAMETERS
 *  total_size          [IN]        
 *  current_size        [IN]        
 *  midlet_name         [?]         
 *  name_len            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jam_download_progess(kal_int32 total_size, kal_int32 current_size, kal_wchar *midlet_name, kal_int32 name_len)
{
#ifdef __MMI_JAVA_INSTALL_DOWNLOAD_JAR_IND__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_show_percentage_ind_struct *percentage_ind = NULL;
    kal_wchar *cb_midlet_name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name_len > 0)
    {
        cb_midlet_name = get_ctrl_buffer((name_len << 1) + 2);
    }

    if (midlet_name != NULL)
        memcpy(cb_midlet_name, midlet_name, name_len << 1);
    else
    {
        free_ctrl_buffer(cb_midlet_name);
        name_len = 11;
        cb_midlet_name = get_ctrl_buffer((name_len << 1) + 2);
        kal_wsprintf(cb_midlet_name, "Java MIDlet");
    }

    if (current_size > total_size)
    {
        total_size = current_size;
    }

    percentage_ind = construct_local_para(sizeof(mmi_java_show_percentage_ind_struct), TD_CTRL);

    percentage_ind->current = current_size;
    percentage_ind->total = total_size;
    percentage_ind->midlet_name = cb_midlet_name;

    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_SHOW_PERCENTAGE_IND,percentage_ind);
#endif /*__MMI_JAVA_INSTALL_DOWNLOAD_JAR_IND__*/
}


/*****************************************************************************
 * FUNCTION
 *  jam_install_progress
 * DESCRIPTION
 *  Send install progess status to MMI. MMI may show progress bar for the status.
 * PARAMETERS
 *  progress        [IN]        Number in percetage for the install progress
 *  suiteName       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void jam_install_progress(kal_int32 progress, kal_uint16 *suiteName)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_install_progress_ind_struct *progress_ind = construct_local_para(sizeof(mmi_java_install_progress_ind_struct), TD_CTRL);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    progress_ind->value = progress;
    progress_ind->number_of_items = 0;
    progress_ind->list_of_items = NULL;

    if (suiteName)
    {
        progress_ind->list_of_items = get_ctrl_buffer(sizeof(kal_uint8*));
        progress_ind->list_of_items[0] = (kal_uint8*) suiteName;
        progress_ind->number_of_items = 1;
    }

    check_incoming_call_and_block();
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_INSTALL_PROGRESS_IND,progress_ind);
}

#ifdef __MMI_JAVA_INSTALL_DELETE_NOTIFIER__
/* install/delete mids notify msg handler                                                                                    */
/*****************************************************************************
 * FUNCTION
 *  jam_send_mids_notify_start_handler
 * DESCRIPTION
 *  send the start msg of notify to MMI
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jam_send_mids_notify_start_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_post_notify_start_req_struct *post_notify_start_msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_sleep_task(5000); */
    post_notify_start_msg = construct_local_para(sizeof(mmi_java_post_notify_start_req_struct), TD_CTRL);
    check_incoming_call_and_block();
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_NOTIFY_POST_START_REQ,post_notify_start_msg);
}


/*****************************************************************************
 * FUNCTION
 *  jam_send_mids_notify_end_handler
 * DESCRIPTION
 *  send the finish msg of notify to MMI
 * PARAMETERS
 *  success     [IN]        
 * RETURNS
 *  kal_bool  the sending success or not(?)
 *****************************************************************************/
void jam_send_mids_notify_end_handler(kal_bool success)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_post_notify_end_req_struct *post_notify_end_msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    post_notify_end_msg = construct_local_para(sizeof(mmi_java_post_notify_end_req_struct), TD_CTRL);
    post_notify_end_msg->success = success;

    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_NOTIFY_POST_END_REQ,post_notify_end_msg);
}
#endif /* __MMI_JAVA_INSTALL_DELETE_NOTIFIER__ */ 


/*****************************************************************************
 * FUNCTION
 *  jam_file_save_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  download_err_code       [IN]        
 *  downloadSize            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jam_file_save_status(kal_int32 download_err_code, kal_int32 downloadSize)
{
#ifdef __MMI_JAVA_INSTALL_DOWNLOAD_JAR_IND__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_get_file_and_save_ind_struct *get_file_ind;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    get_file_ind = construct_local_para(sizeof(mmi_java_get_file_and_save_ind_struct), TD_CTRL);
    if (downloadSize < 0)
    {
        get_file_ind->error_code = J2ME_FILE_DONWLOAD_FAILED;
    }
    else
    {
        get_file_ind->error_code = J2ME_NO_ERROR;
    }

    get_file_ind->download_error_code = download_err_code;

    check_incoming_call_and_block();
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_GET_FILE_AND_SAVE_IND,get_file_ind);
    if (jam_vm_get_next_event(KAL_TRUE, MSG_ID_MMI_JAVA_GET_FILE_AND_SAVE_RES, KAL_FALSE, KAL_FALSE) ==
        J2ME_GET_NEXT_EVENT_ABORT)
    {
        return -1;  /* user cancel */
    }
#endif //__MMI_JAVA_INSTALL_DOWNLOAD_JAR_IND__
    return 0;
}
/*****************************************************************************
 * FUNCTION
 *  jam_get_permission_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  permission_display_id               [IN]        The id string to display in the permission dialog.
 *  permission_dialog_selected_item     [OUT]       A pointer that points to an integer to be set by MMI after the user selecting Yes or No in the permission dialog
 *  trusted_title                       [IN]        Title to be displayed on the dialog
 *  appendix                            [IN]        Appendix information for the dialog content.
 * RETURNS
 *  void
 *****************************************************************************/
void jam_get_permission_req(
        kal_int32 permission_display_id,
        kal_int32 *permission_dialog_selected_item,
        trusted_title_display_enum trusted_title,
        kal_wchar *appendix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_get_permission_ind_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = construct_local_para(sizeof(mmi_java_get_permission_ind_struct), TD_CTRL);

    msg->title_id = permission_display_id;
    msg->chosen_id = permission_dialog_selected_item;
    msg->trusted_display = trusted_title;
    msg->appendix = appendix;
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_GET_PERMISSION_IND,msg);
}


/*****************************************************************************
 * FUNCTION
 *  jam_get_removal_confirm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  MIDSID      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jam_get_removal_confirm( kal_int32 MIDSID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* kal_int32 len; */
    mmi_java_mids_remove_confirm_ind_struct *remove_confirm_ind = NULL;
    kal_wchar *buffer = NULL;
    kal_char* storage_id = NULL;
    mids_list_info_struct *thisMIDS = NULL;

    /*    mid_struct *thisMID; */
    kal_int32 scanPos = 0;
    kal_char *tempStr=NULL;
    kal_bool commit_remove = KAL_FALSE;
    mid_struct *thisMID = NULL;
    kal_int32 temp_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clean_event() == J2ME_GET_NEXT_EVENT_ABORT)
    {
        goto remove_confirm_abort;
    }

    /* Check if mids exist or not */
    thisMIDS = find_mids_info_by_id(MIDSID, KAL_FALSE);
    if (thisMIDS == NULL)
    {
        return KAL_FALSE;
    }

    /* allocate a very big buffer that will be not over */
    buffer = (kal_wchar*) jvm_malloc(20000);
    if (buffer == NULL)
    {
        return KAL_FALSE;
    }

    /*    trans_utf8_to_ucs2(buffer, "Are you sure you want to remove ");
       scanPos = 32; */
    tempStr = (kal_char*) get_string(STR_GLOBAL_DELETE);
    scanPos = get_ucs2_len((kal_wchar*) tempStr);
    memcpy(buffer, tempStr, scanPos << 1);
    memcpy(buffer + scanPos, " \0", 2);
    scanPos += 1;
    memcpy(buffer + scanPos, thisMIDS->mids_name, get_ucs2_len(thisMIDS->mids_name) << 1);

    scanPos += get_ucs2_len(thisMIDS->mids_name);
    tempStr = (kal_char*) get_string(STR_JAVA_DELETE_ASK);
    temp_len = get_ucs2_len((kal_wchar*) tempStr);
    memcpy(buffer + scanPos, tempStr, temp_len << 1);
    scanPos += temp_len;

    thisMID = thisMIDS->mid_info.mid_list;

    while (thisMID != NULL)
    {
        kal_wchar *name = thisMID->mid_name;
        kal_int32 nameLen = get_ucs2_len(name);

        trans_utf8_to_ucs2(buffer + scanPos, "  ");
        scanPos += 2;
        memcpy(buffer + scanPos, name, nameLen << 1);
        scanPos += nameLen;
        trans_utf8_to_ucs2(buffer + scanPos, "\n");
        scanPos += 1;
        thisMID = thisMID->mid_next;
    }

    buffer[scanPos] = 0;

    storage_id = (kal_char*)jvm_malloc(30);
    if(storage_id == NULL)
    {
        goto remove_confirm_abort;
    }

    remove_confirm_ind = construct_local_para(sizeof(mmi_java_mids_remove_confirm_ind_struct), TD_CTRL);
    app_ucs2_str_to_asc_str((kal_int8 *) storage_id, (kal_int8 *) thisMIDS->mids_root);
    remove_confirm_ind->storage_name = storage_id;

    remove_confirm_ind->confirm_msg = buffer;

    check_incoming_call_and_block();
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_MIDS_REMOVE_CONFIRM_IND,remove_confirm_ind);

    if (get_next_event(KAL_TRUE, MSG_ID_MMI_JAVA_MIDS_REMOVE_CONFIRM_RES, KAL_FALSE, KAL_FALSE, NULL) == KAL_TRUE)
    {
        commit_remove = KAL_TRUE;
    }
  remove_confirm_abort:
    if(buffer)
    {
        jvm_free(buffer);
    }
    if(storage_id)
    {
        jvm_free(storage_id);
    }
    return commit_remove;
}


/*****************************************************************************
 * FUNCTION
 *  jam_waiting_http_response
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg                         [IN]        
 *  user_cancel_dont_care       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool jam_waiting_http_response(kal_int32 msg, kal_bool user_cancel_dont_care)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool get_an_auth_ind = KAL_FALSE;
    kal_int32 result = J2ME_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (jnw_http_check_response_primitive(J2ME_HTTP_INSTALL_APP_ID, g_jam_http_conn_id, msg) == -2)
    {
        if(g_jam_install_bearer_switch)
        {
            kal_prompt_trace(MOD_JAM,"jam_waiting_http_response: g_jam_install_bearer_switch is KAL_TRUE");
            return KAL_FALSE;
        }
        if(jnw_http_check_response_primitive(J2ME_HTTP_INSTALL_APP_ID, g_jam_http_conn_id, MSG_WPS_HTTP_AUTH_IND) 
            == J2ME_HTTP_OK)
        {
            if (!get_an_auth_ind)
            {
                #ifdef __MMI_JAVA_INSTALL_AUTHENTICATION__
                {
                    mmi_java_get_auth_ind_struct *auth_ind;

                    auth_ind = construct_local_para(sizeof(mmi_java_mids_remove_confirm_ind_struct), TD_CTRL);

                    check_incoming_call_and_block();
                    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_GET_AUTH_IND,auth_ind);
                    result = jam_vm_get_next_event(KAL_TRUE, MSG_ID_MMI_JAVA_GET_AUTH_RES, KAL_FALSE, KAL_FALSE);
                    if(result == J2ME_GET_NEXT_EVENT_ABORT)
                    {
                        if (!user_cancel_dont_care)
                        {
                            g_jam_ota_user_name[0] = 0;
                            g_jam_ota_passwd[0] = 0;
                            jnw_http_auth_res(J2ME_HTTP_INSTALL_APP_ID, g_jam_http_conn_id, (kal_uint8 *)g_jam_ota_user_name, MMI_JAVA_AUTH_LEN_USERNAME, (kal_uint8 *)g_jam_ota_passwd, MMI_JAVA_AUTH_LEN_USERNAME);
                            terminated_by_user_cancel = KAL_TRUE;
                            return KAL_FALSE;
                        }
                    }
                    jnw_http_auth_res(J2ME_HTTP_INSTALL_APP_ID, g_jam_http_conn_id, (kal_uint8 *)g_jam_ota_user_name, MMI_JAVA_AUTH_LEN_USERNAME, (kal_uint8 *)g_jam_ota_passwd, MMI_JAVA_AUTH_LEN_USERNAME);
                    get_an_auth_ind = KAL_TRUE;
                    g_jam_ota_user_name[0] = 0;
                    g_jam_ota_passwd[0] = 0;
                }
                #else
                {
                    g_jam_ota_user_name[0] = 0;
                    g_jam_ota_passwd[0] = 0;
                    jnw_http_auth_res(J2ME_HTTP_INSTALL_APP_ID, g_jam_http_conn_id, (kal_uint8 *)g_jam_ota_user_name, MMI_JAVA_AUTH_LEN_USERNAME, (kal_uint8 *)g_jam_ota_passwd, MMI_JAVA_AUTH_LEN_USERNAME);
                    get_an_auth_ind = KAL_TRUE;
                }
                #endif//__MMI_JAVA_INSTALL_AUTHENTICATION__
            }

        }
        kal_sleep_task(10);
        result = clean_event();
        if (result == J2ME_GET_NEXT_EVENT_ABORT)
        {
            if (!user_cancel_dont_care)
            {
                terminated_by_user_cancel = KAL_TRUE;
                return KAL_FALSE;
            }
        }
        if(mmi_java_is_no_network_service())
        {
            kal_prompt_trace(MOD_JAM,"jam_waiting_http_response: mmi_java_is_no_network_service is KAL_TRUE");
            return KAL_FALSE;
        }
        
    }
    if (rsp_hdr)
    {
        jam_listmem_free(rsp_hdr);
        rsp_hdr = NULL;
        hdr_len = 0;
    }
    if (content)
    {
        jam_listmem_free(content);
        content = NULL;
        data_len = 0;
    }
    
    if (jnw_http_get_rsp_msg_len(J2ME_HTTP_INSTALL_APP_ID, g_jam_http_conn_id, 
        msg, (kal_uint32 *)&hdr_len, (kal_uint32 *)&data_len) != J2ME_HTTP_OK)
        return KAL_FALSE;
    
    if (hdr_len > 0)
    {
        rsp_hdr = jam_listmem_malloc(hdr_len);
    }
    if (data_len > 0)
    {
        content = jam_listmem_malloc(data_len);
    }
    if (jnw_http_get_rsp_msg(J2ME_HTTP_INSTALL_APP_ID, g_jam_http_conn_id, 
                    msg, rsp_hdr, content) != J2ME_HTTP_OK)
    {
        return KAL_FALSE;
    }
    if(msg == MSG_WPS_HTTP_RSP)
    {
        if(jnw_http_get_status((void *)rsp_hdr, MSG_WPS_HTTP_RSP) != 206 &&
            jnw_http_get_status((void *)rsp_hdr, MSG_WPS_HTTP_RSP) != 200
        )
        {
            return KAL_FALSE;
        }
    }
    if (jnw_http_get_result((void *)rsp_hdr, msg) != WPS_OK)
    {
        return KAL_FALSE;
    }
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  jam_check_MIME_type
 * DESCRIPTION
 *  check MIME type of reply header
 * PARAMETERS
 *  input           [?]         
 *  input_size      [IN]        
 * RETURNS
 *  return KAL_TRUE if jam support, otherwise return KAL_FALSE
 *****************************************************************************/
#define MAX_CHAR_OF_LINE (512)
kal_bool jam_check_MIME_type(kal_char *input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 idx = 0;
    kal_char* accept_mime_types[] = {
        "application/java-archive",
        "application/java",
        "application/x-java-archive",
        "application/vnd.oma.drm.message",
        "application/vnd.oma.drm.content"
    };
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if the header didn't replay Content-Type, It means we accept it */
    if (input == NULL) return KAL_TRUE;   
    for(idx = 0;idx<sizeof(accept_mime_types);idx++)
    {
       if (!strcmp(input, accept_mime_types[idx]))
       {
           return KAL_TRUE;
       }
    }
    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  jam_parse_header_value
 * DESCRIPTION
 *  check MIME type of reply header
 * PARAMETERS
 *  input           [?]         
 *  input_size      [IN]        
 *  key             [?]         
 * RETURNS
 *  return KAL_TRUE if jam support, otherwise return KAL_FALSE
 *****************************************************************************/
kal_char* jam_parse_header_value(kal_char *input, kal_int32 input_size, kal_char* key)
{
    kal_char* ptr = NULL;
    kal_char* start = NULL;
    kal_int32 len =0;
    kal_char* return_str = NULL;
    len = strlen(key);
    ptr = input;
    do{
        ptr = strstr(ptr,key);
        if(ptr && strchr(" \t\n\r:",*(ptr+len)) == NULL)
        {
            ptr += len;
        }
        else
        {
            break;
        }
    }while(ptr != NULL);
    
    if(ptr == NULL) return NULL;
    start = ptr;
    ptr = start+len;
    while(ptr!=NULL && strchr(" \t\n\r:",*ptr) != NULL)
    {
        ptr++;
    }

    for(start = ptr; ptr!=NULL && strchr("\n;",*ptr) == NULL; ptr++)
        ;
    if(ptr)
    {
        len = ptr - start;
        return_str = jam_listmem_malloc(len);
        if(return_str)
        {
            strncpy(return_str, start,len-1);
            return_str[len-1]='\0';
        }
    }
    return return_str;
}


/*****************************************************************************
 * FUNCTION
 *  jam_request_http_and_save_to_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  total_jar_size      [IN]        
 *  url                 [?]         [?]
 *  file_name           [?]         [?]
 *  midlet_name         [?]         
 *  name_len            [IN]        
 *  checkJAR            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
 kal_int32 jam_request_http_and_save_data_to_file(
            kal_int32* current_size,
            kal_int32 total_jar_size,
            kal_wchar *url,
            kal_int32 handle,
            kal_wchar *midlet_name,
            kal_int32 name_len,
            kal_int32 checkJAR)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 url_len = get_ucs2_len(url);
    kal_int32 read_seq_length = 0;
    kal_char *utf8_url;
    kal_uint32 dummy;
    kal_int32 seq_num = 0;
    kal_char *temp_buffer;
    kal_int32 download_size = 0;
    kal_int32 return_error_code = J2ME_NO_ERROR;
    kal_int32 header_len = 0;
    kal_char *header_content = NULL;
    kal_char *user_agent;
    kal_uint32 msg_id;
    kal_int32 result = 0;
    kal_char *header_attribute;
    kal_uint32 last_time = 0;
    kal_uint32 temp_time;
    kal_int32 last_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    utf8_url = jvm_malloc(2 * J2ME_HTTP_WPS_MAX_INPUT_BUFFER + 1000);
    /* check if we have J2ME_HTTP_WPS_MAX_INPUT_BUFFER * 2 buffer for WPS manipulation */
    if (utf8_url == NULL)
    {
        return JAM_HTTP_MEMORY_NOT_ENOUGH;
    }
    jvm_free(utf8_url);

    utf8_url = jvm_malloc(url_len + 1);
    if (utf8_url == NULL)
    {
        return_error_code = JAM_HTTP_MEMORY_NOT_ENOUGH;
        goto connection_failed;
    }

    trans_ucs2_to_utf8(utf8_url, url);

    /* get wap user agent */
    user_agent = (kal_char*) applib_inet_get_user_agent_string();

      header_len = 89 + strlen(user_agent) + 100 + strlen(J2ME_ACCEPT_LANGUAGE_HEADER);

    header_content = jvm_malloc(header_len + 1);
    if (header_content == NULL)
    {
        return_error_code = JAM_HTTP_MEMORY_NOT_ENOUGH;
        goto connection_failed;

    }
    header_content[0] = 0;

    strcat(header_content, "User-Agent: ");
    strcat(header_content, user_agent);
    strcat(
        header_content,
        "\r\nAccept: text/vnd.sun.j2me.app-descriptor, application/java-archive, */*\r\nAccept-Language: ");
    strcat(header_content, J2ME_ACCEPT_LANGUAGE_HEADER);
    strcat(header_content, "\r\n");
      sprintf(header_content + strlen(header_content),"Range: bytes=%d-\r\n",(*current_size));
      download_size = *current_size;
    /* display 0% progress bar */
    if (total_jar_size)
    {
          jam_download_progess(total_jar_size, download_size, midlet_name, name_len);
    }

    if (g_jam_http_conn_id == 0)
        g_jam_http_conn_id = jnw_http_get_req_id(J2ME_HTTP_WPS_CHANNEL_HTTP);
    jnw_http_initialize(J2ME_HTTP_INSTALL_APP_ID);
    while((result = jnw_http_open_connection(J2ME_HTTP_INSTALL_APP_ID, g_jam_http_conn_id)) == J2ME_HTTP_ABM_WOULDBLOCK )
    {
        result = clean_event();
        if (result == J2ME_GET_NEXT_EVENT_ABORT)
        {
            kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,1);
            terminated_by_user_cancel = KAL_TRUE;
            goto http_error;
        }
        if (terminated_by_user_cancel  == KAL_TRUE )
        {
            kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,2);
            goto http_error;
        }
        if(mmi_java_is_no_network_service())
        {
            kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,3);
            goto http_error;
        }      
        kal_sleep_task(10);

    }
    if (result == J2ME_HTTP_WOULDBLOCK)
    {
        if (!jam_waiting_http_response(MSG_WPS_SET_CHANNEL_RSP, KAL_FALSE))
        {           
            if (terminated_by_user_cancel)
            {
                kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,4);
                return_error_code = JAM_HTTP_USER_CANCEL;
            }
            else
            {
                kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,5);
                return_error_code = JAM_HTTP_SET_CHANNEL_ERROR;
            }
            if(g_jam_install_bearer_switch)
            {
                kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,6);
                return_error_code = JAM_HTTP_BEARER_SWITCH;
            }
            goto http_error;
        }
    }else if(result<0){
        kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,7);
        return_error_code = JAM_HTTP_SET_CHANNEL_ERROR;
        goto connection_failed;
    }

    result = jnw_http_clear_cache(J2ME_HTTP_INSTALL_APP_ID, g_jam_http_conn_id, url_len, utf8_url);
    if(result == J2ME_HTTP_ABORT)
    {
        terminated_by_user_cancel = KAL_TRUE;
        return_error_code = JAM_HTTP_USER_CANCEL;
        kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,8);
        goto http_error;
    }
    jnw_http_set_auto_return_auth(J2ME_HTTP_INSTALL_APP_ID, KAL_FALSE);
    
    while ((result = jnw_http_write_req(J2ME_HTTP_INSTALL_APP_ID, g_jam_http_conn_id, J2ME_HTTP_METHOD_GET, url_len, (kal_uint8 *)utf8_url, header_len, (kal_uint8 *)header_content, 0, 0, NULL, KAL_FALSE)) == -2)
    {
        result = clean_event();
        if (result == J2ME_GET_NEXT_EVENT_ABORT)
        {
            terminated_by_user_cancel = KAL_TRUE;
            kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,9);
            goto http_error;
        }
        if (terminated_by_user_cancel  == KAL_TRUE )
        {
            kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,10);
            goto http_error;
        }
        if(g_jam_install_bearer_switch)
        {
            return_error_code = JAM_HTTP_BEARER_SWITCH;
            kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,11);
            goto http_error;
        }      
        kal_sleep_task(10);
    }
    if (result == J2ME_HTTP_ERROR){
        return_error_code = JAM_HTTP_SET_CHANNEL_ERROR;
        goto http_error;
    }
    if (!jam_waiting_http_response(MSG_WPS_HTTP_RSP, KAL_FALSE))
    {
        if (terminated_by_user_cancel)
        {
            kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,12);
            return_error_code = JAM_HTTP_USER_CANCEL;
        }
        else
        {
            return_error_code = JAM_HTTP_SERVER_RESPONSE_ERROR;
        }
        if(g_jam_install_bearer_switch)
        {
            kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,13);
            return_error_code = JAM_HTTP_BEARER_SWITCH;
        }       
        goto http_error;
    }
    
    /* CT887 */
    /* because when Download JAR we will set checkJAR = TRUE */
    if (checkJAR)
    {
        read_seq_length = jnw_http_get_reply_header_length((void *)content);
        if (read_seq_length <= 0)
        {
            return_error_code = JAM_HTTP_SERVER_RESPONSE_ERROR;
            kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,14);
            goto http_error;
        }
        temp_buffer = jvm_malloc(read_seq_length);
        if(temp_buffer == NULL)
        {
            return_error_code = JAM_HTTP_MEMORY_NOT_ENOUGH;
             goto http_error;
        }
        if (jnw_http_get_reply_header((void *)content, (kal_uint8 *)temp_buffer))
        {
            header_attribute = jam_parse_header_value(temp_buffer,read_seq_length,"Content-Type");
            if(!jam_check_MIME_type(header_attribute))
            {
                return_error_code = JAM_HTTP_INCORRECT_MIDLET_DATA;
                jvm_free(temp_buffer);
                if (header_attribute)
                {
                    jam_listmem_free(header_attribute);
                    header_attribute = NULL;
                }
                kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,15);
                goto http_error;
            }
            if (header_attribute)
            {
                jam_listmem_free(header_attribute);
                header_attribute = NULL;
            }
            /* TCD 1114  */
            header_attribute = jam_parse_header_value(temp_buffer,read_seq_length,"X-Oma-Drm-Separate-Delivery");
            jam_drm_set_waiting_time(0, header_attribute);
            if (header_attribute)
            {
                jam_listmem_free(header_attribute);
                header_attribute = NULL;
            }
        }
        jvm_free(temp_buffer);
    }
    msg_id = MSG_WPS_HTTP_RSP;
    do
    {
        read_seq_length = jnw_http_get_reply_segment_length((void *)content, msg_id);
        if (read_seq_length <= 0)
        {
            kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,16);
            break;
        }
        temp_buffer = jvm_malloc(read_seq_length);
        if(temp_buffer == NULL)
        {
            return_error_code = JAM_HTTP_MEMORY_NOT_ENOUGH;
             goto http_error;
        }
        if (jnw_http_get_reply_segment((void *)content, (kal_uint8 *)temp_buffer, msg_id))
        {
            FS_Write(handle, temp_buffer, read_seq_length, &dummy);
        }
        else
        {
            jvm_free(temp_buffer);
            return_error_code = JAM_HTTP_SERVER_RESPONSE_ERROR;
            kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,17);
            goto http_error;
        }
        jvm_free(temp_buffer);
        download_size += dummy;
        if (dummy != read_seq_length)
        {
            return_error_code = JAM_HTTP_STORAGE_NOT_ENOUGH;
            kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,18);
            goto http_error;
        }
        if (total_jar_size)
        {
            kal_get_time(&temp_time);
            if ((download_size-last_size) > (total_jar_size/4) || 
                last_time == 0 || temp_time < last_time ||  kal_ticks_to_milli_secs(temp_time - last_time)> 250)
            {
                jam_download_progess(total_jar_size, download_size, midlet_name, name_len);
                last_time = temp_time;
                last_size = download_size;
            }
            
        }
        if (!jnw_http_check_more((void *)rsp_hdr, msg_id))
        {
            break;
        }
        seq_num = (seq_num + 1) % 256;
        msg_id = MSG_WPS_READ_CONTENT_RSP;
        jnw_http_read_req(g_jam_http_conn_id, seq_num);
        if (!jam_waiting_http_response(msg_id, KAL_FALSE))
        {
            if (terminated_by_user_cancel)
            {
                return_error_code = JAM_HTTP_USER_CANCEL;
            }
            else
            {
                return_error_code = JAM_HTTP_SERVER_RESPONSE_ERROR;
            }
            if(g_jam_install_bearer_switch)
            {
                return_error_code = JAM_HTTP_BEARER_SWITCH;
            }
            kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_SAVE_DATA_TO_FILE,19);
            goto http_error;
        }
    } while (1);

  http_error:
    if(jnw_http_close_connection(J2ME_HTTP_INSTALL_APP_ID, g_jam_http_conn_id) != J2ME_HTTP_ERROR)
    {
        if(!jam_waiting_http_response(MSG_WPS_CANCEL_RSP, KAL_TRUE))
        {
            /*can ingore the wps result for cancel rsp*/
            if (terminated_by_user_cancel)
            {
                return_error_code = JAM_HTTP_USER_CANCEL;
            }
            if(g_jam_install_bearer_switch)
            {
                return_error_code = JAM_HTTP_BEARER_SWITCH;
            }
        }
    }
    jnw_http_clear_pending_request(J2ME_HTTP_INSTALL_APP_ID, g_jam_http_conn_id);
    jnw_http_finalize(J2ME_HTTP_INSTALL_APP_ID);
  connection_failed:

    if (total_jar_size)
    {
        jam_download_progess(total_jar_size, download_size, midlet_name, name_len);
    }
    
    if(utf8_url)
    {
        jvm_free(utf8_url);
        utf8_url = NULL;
    }
    if(header_content)
    {
        jvm_free(header_content);
        header_content = NULL;
    }
    download_error_code = return_error_code;

    if (terminated_by_user_cancel)
        return_error_code = JAM_HTTP_USER_CANCEL;
      *current_size = download_size ;
    if(g_jam_install_bearer_switch)
    {
        download_error_code = J2ME_NO_ERROR;
        return_error_code = JAM_HTTP_BEARER_SWITCH;
    }
    if (rsp_hdr)
    {
        jam_listmem_free(rsp_hdr);
        rsp_hdr = NULL;
        hdr_len = 0;
    }
    if (content)
    {
        jam_listmem_free(content);
        content = NULL;
        data_len = 0;
    }
    return return_error_code;
}


kal_int32 jam_request_http_and_save_to_file(
            kal_int32 total_jar_size,
            kal_wchar *url,
            kal_wchar *file_name,
            kal_wchar *midlet_name,
            kal_int32 name_len,
            kal_int32 checkJAR)
{
    kal_int32 current_size = 0;
    kal_int32 error_code = J2ME_NO_ERROR;
    kal_int32 retry_num = 0;
    kal_int32 handle = FS_Open(file_name, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (handle < 0)
    {
          return JAM_HTTP_OPEN_FILE_ERROR;
    }
    do{
        g_jam_install_bearer_switch = KAL_FALSE;
        terminated_by_user_cancel = KAL_FALSE;
        error_code = jam_request_http_and_save_data_to_file(&current_size, total_jar_size,
            url,handle, midlet_name, name_len, checkJAR);
        retry_num++;
    }while( 
        ( current_size != total_jar_size && retry_num < 15 &&
        error_code != JAM_HTTP_USER_CANCEL &&
        error_code != JAM_HTTP_MEMORY_NOT_ENOUGH &&
        error_code != J2ME_NO_ERROR 
     )
     || error_code == JAM_HTTP_BEARER_SWITCH);
    FS_Close(handle);
    terminated_by_user_cancel = KAL_FALSE;
    g_jam_install_bearer_switch = KAL_FALSE;

    return error_code;
}
kal_int32 jam_request_http_post_ext(
            kal_wchar *url,
            kal_char *post_message,
            kal_int32 *server_response_code,
            kal_bool first_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 url_len = get_ucs2_len(url);
    kal_char *utf8_url;
    kal_int32 return_error_code = J2ME_NO_ERROR;
    kal_int32 header_len = 0;
    kal_char *header_content = NULL;
    kal_char *user_agent;
    kal_int32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    utf8_url = jvm_malloc(2 * J2ME_HTTP_WPS_MAX_INPUT_BUFFER + 1000);
    /* check if we have 2 * J2ME_HTTP_WPS_MAX_INPUT_BUFFER buffer for WPS manipulation */
    if (utf8_url == NULL)
    {
        return_error_code =  JAM_HTTP_MEMORY_NOT_ENOUGH;
        goto connection_failed;
    }
    jvm_free(utf8_url);
    utf8_url = jvm_malloc(url_len + 1);
    if (utf8_url == NULL)
    {
        return_error_code =  JAM_HTTP_MEMORY_NOT_ENOUGH;
        goto connection_failed;
    }

    trans_ucs2_to_utf8(utf8_url, url);

    user_agent = (kal_char*) applib_inet_get_user_agent_string();
    header_len = 15 + 26 + strlen(user_agent);

    header_content = jvm_malloc(header_len + 1);
    if (header_content == NULL)
    {
        return_error_code = JAM_HTTP_MEMORY_NOT_ENOUGH;
        goto connection_failed;
    }
    header_content[0] = 0;

    strcat(header_content, "Content-Type: text/plain\r\n");
    strcat(header_content, "User-Agent: ");
    strcat(header_content, user_agent);
    strcat(header_content, "\r\n");
    if (g_jam_http_conn_id == 0)
        g_jam_http_conn_id = jnw_http_get_req_id(J2ME_HTTP_WPS_CHANNEL_HTTP);
    jnw_http_initialize(J2ME_HTTP_INSTALL_APP_ID);
	jnw_http_set_time_out(J2ME_HTTP_INSTALL_APP_ID,20);
	while((result = jnw_http_open_connection(J2ME_HTTP_INSTALL_APP_ID, g_jam_http_conn_id)) == J2ME_HTTP_ABM_WOULDBLOCK )
    {
        result = clean_event();
        if (result == J2ME_GET_NEXT_EVENT_ABORT)
        {            
            kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_POST_EXT,1);
            terminated_by_user_cancel = KAL_TRUE;
            goto connection_failed;
        }
        if (terminated_by_user_cancel  == KAL_TRUE )
        {
           kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_POST_EXT,2);
            goto connection_failed;
        }
        if(mmi_java_is_no_network_service())
        {
            kal_trace(TRACE_INFO,FUNC_JAM_REQUEST_HTTP_POST_EXT,3);
            goto connection_failed;
        }        
        kal_sleep_task(10);
    }

    if (result == J2ME_HTTP_WOULDBLOCK)
    {
        if (!jam_waiting_http_response(MSG_WPS_SET_CHANNEL_RSP, KAL_TRUE))
        {
            if (terminated_by_user_cancel)
            {
                return_error_code = JAM_HTTP_USER_CANCEL;
            }else{
                return_error_code = JAM_HTTP_SET_CHANNEL_ERROR;
            }
            if(g_jam_install_bearer_switch)
            {
                return_error_code = JAM_HTTP_BEARER_SWITCH;
            }
            goto connection_failed;
        }
    }else if(result < 0){
        return_error_code = JAM_HTTP_SET_CHANNEL_ERROR;
        goto connection_failed;
    }
    while ((result = jnw_http_write_req(J2ME_HTTP_INSTALL_APP_ID, 
        g_jam_http_conn_id,
        J2ME_HTTP_METHOD_POST,
        url_len,
        (kal_uint8 *)utf8_url,
        header_len,
        (kal_uint8 *)header_content,
        strlen(post_message),
        strlen(post_message),
        (kal_uint8 *)post_message,
        KAL_FALSE)) == -2)
    {
        if(g_jam_install_bearer_switch)
        {
            return_error_code = JAM_HTTP_BEARER_SWITCH;
            goto connection_failed;
        }
        kal_sleep_task(10);
    }
    if (result == J2ME_HTTP_ERROR)
        goto connection_failed;

    if (!jam_waiting_http_response(MSG_WPS_HTTP_RSP, KAL_TRUE))
    {   
        if (terminated_by_user_cancel)
        {
            return_error_code = JAM_HTTP_USER_CANCEL;
        }else{
            return_error_code = JAM_HTTP_SERVER_RESPONSE_ERROR;
        }
        if(g_jam_install_bearer_switch)
        {
            return_error_code = JAM_HTTP_BEARER_SWITCH;
            goto connection_failed;
        }
    }
connection_failed:
    if(jnw_http_close_connection(J2ME_HTTP_INSTALL_APP_ID, g_jam_http_conn_id) != J2ME_HTTP_ERROR)
    {
        if(!jam_waiting_http_response(MSG_WPS_CANCEL_RSP, KAL_TRUE))
        {
            /*can ingore the wps result for cancel rsp*/
            if (terminated_by_user_cancel)
            {
                return_error_code = JAM_HTTP_USER_CANCEL;
            }
            if(g_jam_install_bearer_switch)
            {
                return_error_code = JAM_HTTP_BEARER_SWITCH;
            }
        }

    }
    jnw_http_finalize(J2ME_HTTP_INSTALL_APP_ID);
    if(utf8_url)
    {
        jvm_free(utf8_url);
        utf8_url = NULL;
    }
    if(header_content)
    {
        jvm_free(header_content);
        header_content = NULL;
    }
    if (rsp_hdr)
    {
        jam_listmem_free(rsp_hdr);
        rsp_hdr = NULL;
        hdr_len = 0;
    }
    if (content)
    {
        jam_listmem_free(content);
        content = NULL;
        data_len = 0;
    }
    return return_error_code;
}

/*****************************************************************************
 * FUNCTION
 *  jam_request_http_post
 * DESCRIPTION
 *  
 * PARAMETERS
 *  url                         [?]         [?]
 *  post_message                [?]         [?]
 *  server_response_code        [?]         [?]
 *  first_time                  [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jam_request_http_post(
            kal_wchar *url,
            kal_char *post_message,
            kal_int32 *server_response_code,
            kal_bool first_time)
{
    kal_int32 return_error_code = J2ME_NO_ERROR;
#ifdef __MMI_JAVA_INSTALL_DELETE_NOTIFIER__
    /* Start to show the nodified dialog */
    /* only at the first time to send this report */
    if (first_time)
    {
        jam_send_mids_notify_start_handler();
    }
#endif /* __MMI_JAVA_INSTALL_DELETE_NOTIFIER__ */ 

    do{
        g_jam_install_bearer_switch = KAL_FALSE;
        terminated_by_user_cancel = KAL_FALSE;
        return_error_code = jam_request_http_post_ext(url, post_message,
            server_response_code,first_time);
    }while(return_error_code == JAM_HTTP_BEARER_SWITCH);
    g_jam_install_bearer_switch = KAL_FALSE;
    terminated_by_user_cancel = KAL_FALSE;

#ifdef __MMI_JAVA_INSTALL_DELETE_NOTIFIER__
    /* Finish to show the nodified dialog */
    /* only at the first time to send this report */
    if (first_time)
    {
        if (return_error_code == J2ME_NO_ERROR)
        {
            jam_send_mids_notify_end_handler(KAL_TRUE);
        }
        else
        {
            jam_send_mids_notify_end_handler(KAL_FALSE);
        }
    }
#endif /* __MMI_JAVA_INSTALL_DELETE_NOTIFIER__ */ 
#ifdef __JAVA_MANAGER__

    /* Send the report status to l4c, Just only want to be catched by Catcher. */
    if(return_error_code == J2ME_NO_ERROR)
    {
        kal_int32 status_code = 0;
        kal_char buffer[4] = {0};
        mmi_l4c_ota_status_ind_struct *ptr = NULL;

        strncpy(buffer, post_message, 3);
        buffer[3] = '\0';
        status_code = atoi(buffer);
        ptr = OslAllocDataPtr(mmi_l4c_ota_status_ind_struct);    
        
        if (NULL == ptr)
        {
            //MMI_PRINT(MOD_J2ME, TRACE_FUNC, "jam_request_http_post : no mem for mmi_l4c_ota_status_ind_struct");
            return J2ME_INSUFFICIENT_MEMORY;
        }

        ptr->error_code = (kal_uint8) return_error_code;
        ptr->status_code = status_code;
        mmi_frm_send_ilm(MOD_L4C,MSG_ID_MMI_L4C_OTA_STATUS_IND,(oslParaType *)ptr,NULL);
    }
#endif /* __JAVA_MANAGER__ */ 


    return return_error_code;
}

/*****************************************************************************
 * FUNCTION
 *  jam_get_install_drv
 * DESCRIPTION
 *  Get Preinstall game driver after updating.
 * PARAMETERS
 *  requestSize     [IN]        
 * RETURNS
 *  The drive char that the user selected. 0 if the user cancels the selection
 *****************************************************************************/
kal_char jam_get_preinstall_drv(void)
{
#ifdef __LOW_COST_SUPPORT_COMMON__
    return (kal_char)SRV_FMGR_CARD_DRV;
#else
    return (kal_char)SRV_FMGR_PUBLIC_DRV;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  jam_get_install_drv
 * DESCRIPTION
 *  get the installatoin drive path. Remember free the install drive string with jam_listmem_free
 * PARAMETERS
 *  requestSize     [IN]        
 * RETURNS
 *  The drive char that the user selected. 0 if the user cancels the selection
 *****************************************************************************/
kal_int32 jam_get_install_drv(kal_int32 requestSize)
{

#ifdef __LOW_COST_SUPPORT_COMMON__
    return (kal_char)SRV_FMGR_CARD_DRV;
#else

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_get_install_drv_ind_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clean_event() == J2ME_GET_NEXT_EVENT_ABORT)
    {
        return J2ME_GET_NEXT_EVENT_ABORT;
    }
    msg = construct_local_para(sizeof(mmi_java_get_install_drv_ind_struct), TD_CTRL);

    msg->size = requestSize;

    check_incoming_call_and_block();
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_GET_INSTALL_DRV_IND,msg);
    return jam_vm_get_next_event(KAL_TRUE, MSG_ID_MMI_JAVA_GET_INSTALL_DRV_RES, KAL_FALSE, KAL_FALSE);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  jam_get_install_category
 * DESCRIPTION
 *  get the install category. 
 * PARAMETERS
 *  void       
 * RETURNS
 *  The drive char that the user selected. 0 if the user cancels the selection
 *****************************************************************************/
kal_int32 jam_get_install_category(void)
{
#ifdef __MMI_JAVA_CATEGORY_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_get_install_drv_ind_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clean_event() == J2ME_GET_NEXT_EVENT_ABORT)
    {
        return J2ME_GET_NEXT_EVENT_ABORT;
    }
    msg = construct_local_para(sizeof(mmi_java_get_install_category_ind_struct), TD_CTRL);

    check_incoming_call_and_block();
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_GET_INSTALL_CATEGORY_IND,msg);
    return jam_vm_get_next_event(KAL_TRUE, MSG_ID_MMI_JAVA_GET_INSTALL_CATEGORY_RES, KAL_FALSE, KAL_FALSE);
#else
    return 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  jam_get_mms_attachment
 * DESCRIPTION
 *  This function will send message to WAP to get the MMS attachment.
 * PARAMETERS
 *  file_name           [IN]        
 *  abort_received      [?]         
 * RETURNS
 *  A virtual file as request.
 *****************************************************************************/
kal_wchar *jam_get_mms_attachment(kal_wchar *file_name, kal_bool *abort_received)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 return_value = 0;

#ifdef MMS_SUPPORT
    kal_int32  dst_mod;
    mms_get_attachment_req_struct *mms_attachement = construct_local_para(sizeof(mms_get_attachment_req_struct), TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *abort_received = KAL_FALSE;
    mmi_ucs2cpy((kal_char*) mms_attachement->filename, (kal_char*) file_name);
    dst_mod = mms_get_service_module(MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_REQ);
    java_send_msg_from_active_mod(dst_mod,WAP_MMI_SAP,MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_REQ,mms_attachement);
    return_value = jam_vm_get_next_event(KAL_TRUE, MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_RSP, KAL_FALSE, KAL_FALSE);

    if (return_value == J2ME_GET_NEXT_EVENT_ABORT)
    {
        *abort_received = KAL_TRUE;
        return_value = 0;
    }
#endif /* MMS_SUPPORT */ /* WAP_SUPPORT */
    return (kal_wchar*) return_value;
}
/*****************************************************************************
 * FUNCTION
 *  jam_get_install_max_midlet_num
 * DESCRIPTION
 *  This function will get max install mid num in a suite.
 * PARAMETERS
 *     
 * RETURNS
 * MAX width of install icon.
 *****************************************************************************/
kal_int32 jam_get_install_max_midlet_num(void)
{
    return 50;
}
/*****************************************************************************
 * FUNCTION
 *  jam_get_install_max_mids_num
 * DESCRIPTION
 *  This function will get max install mid num in a suite.
 * PARAMETERS
 *     
 * RETURNS
 * MAX width of install icon.
 *****************************************************************************/
kal_int32 jam_get_install_max_mids_num(void)
{
    return 40;
}
/*****************************************************************************
 * FUNCTION
 *  jam_get_install_icon_max_width
 * DESCRIPTION
 *  This function will get max install icon width. so that vm poring easy.
 * PARAMETERS
 *     
 * RETURNS
 * MAX width of install icon.
 *****************************************************************************/
kal_int32 jam_get_install_icon_max_width(void)
{
    return MAX_INSTALL_ICON_WIDTH;
}
/*****************************************************************************
 * FUNCTION
 *  jam_get_install_icon_max_height
 * DESCRIPTION
 *  This function will get max install icon height. so that vm poring easy.
 * PARAMETERS
 *     
 * RETURNS
 * MAX height of install icon.
 *****************************************************************************/
kal_int32 jam_get_install_icon_max_height(void)
{
    return MAX_INSTALL_ICON_HEIGHT;
}
/*****************************************************************************
 * FUNCTION
 *  jam_construct_install_icon_path
 * DESCRIPTION
 *  This function will construct a path to install mids icon by MIDlet-NAME and MIDlet-Vendor.
 * PARAMETERS
 *  kal_wchar* midletname,
 *  kal_wchar* vendor_name,
 * RETURNS
 * kal_wchar* :Install icon path.
 *****************************************************************************/
kal_wchar* jam_construct_install_icon_path(kal_char* storage_name,kal_char installed_drv)
{
#if(defined(__MMI_APP_MANAGER_SUPPORT__)||defined(__COSMOS_MMI_PACKAGE__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char* icon_path = NULL;
    kal_int32 len = 0;
    kal_wchar* filepath = NULL; 
    kal_int32 result = J2ME_NO_ERROR;
    kal_char driver_arr[4] = {0};
    kal_int32 idx = 0;
    kal_char* icon_suffix = "icon";
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(storage_name);
    icon_path = _jvm_get_dir_path();
    len = (strlen((const char *)icon_path) + 1
        + strlen((const char *)storage_name) + 1
        + 5 
        +1)<<1;
    ASSERT(len < 512);
    filepath = (kal_wchar*)get_ctrl_buffer(len);
    kal_wsprintf(filepath, "%s\\%s.%s\0",icon_path,storage_name,icon_suffix);
    driver_arr[0] = SRV_FMGR_SYSTEM_DRV;
    driver_arr[1] = SRV_FMGR_PUBLIC_DRV;
    driver_arr[2] = SRV_FMGR_CARD_DRV;
    driver_arr[3] = SRV_FMGR_CARD2_DRV;
    for(idx = 0; idx<sizeof(driver_arr); idx++)
    {
        filepath[0] = driver_arr[idx];
        FS_Delete(filepath);// remove old icon file       
    }
    kal_wsprintf(filepath, "%s\0",icon_path);
    filepath[0] = installed_drv;
    result = FS_Open((const kal_wchar*)filepath, FS_OPEN_DIR | FS_READ_ONLY);
    if (result < FS_NO_ERROR)
    {
        result = FS_CreateDir((const kal_wchar*)filepath);
        if (FS_NO_ERROR > result)
        {
            free_ctrl_buffer(filepath);
            return NULL;
        }
    }
    else
    {
        FS_Close(result);
    }    
    kal_wsprintf(filepath, "%s\\%s.%s\0",icon_path,storage_name,icon_suffix);
    filepath[0] = installed_drv;
    return filepath;
#else
    return NULL;
#endif

}
kal_bool jam_is_need_malloc_temp(void)
{
#ifdef J2ME_SLIM_MEMORY_SUPPORT
    return KAL_FALSE;
#else
    return (kal_bool)(kal_get_active_module_id() == MOD_JAM);
#endif
}
char *jam_get_custpack_domain_name(int domain)
{
   
    if (domain == CERT_DOMAIN_MANUFACTURE)
    {
        return CUSTPACK_J2ME_CA_MANUFACTURER_DOMAIN;
    }
    else if (domain == CERT_DOMAIN_OPERATOR)
    {
        return CUSTPACK_J2ME_CA_OPERATOR_DOMAIN;
    }
    else if (domain == CERT_DOMAIN_3RD_PARTY)
    {
        return CUSTPACK_J2ME_CA_3RD_DOMAIN;
    }
    
    return NULL;
}


