/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the Event Handlers and Main flow of the MMS Application.
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
 */

/***************************************************************************** 
 * removed!
*****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_MMS_2__

//#include "customer_ps_inc.h"
//#include "AlarmFrameworkProt.h"
//#include "SmsGuiInterfaceType.h"
#include "mmi_inet_app_trc.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "fs_type.h"

#include "DebugInitDef_Int.h"

#include "kal_trace.h"
#include "fs_func.h"
// #include "SimDetectionStruct.h"
#include "FileMgrSrvGProt.h"
#include "Unicodexdcl.h"
#include "fs_errcode.h"
#include "stdio.h"
#include "string.h"
#include "gui_data_types.h"
#include "gui.h"
#include "kal_public_api.h"
#include "mmi_frm_timer_gprot.h"
#include "mmiapi_dm_struct.h"
#include "mms_api.h"
#include "mms_sap_struct.h"
#include "mma_api.h"
#include "stdlib.h"
/* For Bearer Type */
//#include "wap_ps_struct.h"
//#include "custom_wap_config.h"
//#include "mmsadp.h"
//#include "MMSAppUICommon.h"
#include "MmsSrvGprot.h"
#include "MmsSrvProt.h"
//#include "MMSJSRProts.h"
#include "MMSJSRSrvProts.h"
#ifdef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__

#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
//#include "IdleNotificationManagerGprot.h"
//#include "ProfilesSrvGprot.h"
//#include "Custom_events_notify.h"
//#include "SimDetectionGprot.h"
#include "DLAgentSrvDef.h"
#include "MmsSrvSendRcv.h"
// #include "MmsAppUtil.h"
#include "fmt_struct.h"
#include "MMSMemoryManagerSrv.h"
#include "UcSrvGprot.h"
//#include "UcAppGprot.h"
//#include "MmsSrvExt.h"
#include "MmsSrvSendRcv.h"
#include "mmi_frm_utility_gprot.h"

#include "mmi_rp_srv_mms_def.h"
#ifdef __DM_LAWMO_SUPPORT__
#include "dmuigprot.h"
#endif 

#ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__
static srv_mms_notification_struct current_obj_struct;
static srv_mms_notification_struct *g_current_obj_ind_struct = &current_obj_struct;
srv_mms_notification_list *g_notification_list;
#endif /* __MMI_MMS_MMA_MMS_OBJECT_IND__ */ 

#ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__
static U16 g_full_ind_counter = 0;
static MMI_BOOL g_obj_ind_flag = MMI_FALSE;
#endif /* __MMI_MMS_MMA_MMS_OBJECT_IND__ */ 

extern kal_uint8 sim_id_for_new_msg;
extern MMI_BOOL g_nmgr_informed;

#ifdef __MMI_MMS_MMA_MMS_OBJECT_IND__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_handle_mms_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  session_id                  [IN]        
 *  mime_type                   [IN]        
 *  mime_subtype                [IN]        
 *  action_type                 [IN]        
 *  filename                    [IN]        
 *  download_url                [IN]        
 *  mime_type_str_string        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_handle_mms_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action_type,
        PU16 filename,
        PS8 download_url,
        PS8 mime_type_str_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 second_byte[1] = {0, };
    U32 size = 0;

    /* Open the file and based on the type save to Stystem or Public Drive */
    FS_HANDLE file_hnd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_HANDLE_MMS_FILE, filename, action_type);
    file_hnd = FS_Open((const WCHAR*)filename, FS_READ_ONLY);
    FS_Seek(file_hnd, 1, FS_FILE_BEGIN);
    FS_Read(file_hnd, &second_byte, 1, &size);
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SECOND_BYTE_FROM_FILE, second_byte[0]);
    FS_Close(file_hnd);

    if ((S32) MMI_DA_PUSH_SIM1 == action_type)
    {
        g_current_obj_ind_struct->sim_id = MMI_SIM1;
    }
#if(MMI_MAX_SIM_NUM >= 2)
    else if ((S32) MMI_DA_PUSH_SIM2 == action_type)
    {
        g_current_obj_ind_struct->sim_id = MMI_SIM2;
    }
#endif /* (MMI_MAX_SIM_NUM >= 2) */ /* (defined(__MMI_MMS_DUAL_SIM__) || defined(__GEMINI__) || (GEMINI_PLUS > 2)) */
#if(MMI_MAX_SIM_NUM >= 3)
    else if ((S32) MMI_DA_PUSH_SIM3 == action_type)
    {
        g_current_obj_ind_struct->sim_id = MMI_SIM3;
    }
#endif /* (MMI_MAX_SIM_NUM >= 3) */ /* (defined(__MMI_MMS_DUAL_SIM__) || defined(__GEMINI__) || (GEMINI_PLUS > 2)) */
#if(MMI_MAX_SIM_NUM >= 4)
    else if ((S32) MMI_DA_PUSH_SIM4 == action_type)
    {
        g_current_obj_ind_struct->sim_id = MMI_SIM4;
    }
#endif /* (MMI_MAX_SIM_NUM >= 4) */ /* (defined(__MMI_MMS_DUAL_SIM__) || defined(__GEMINI__) || (GEMINI_PLUS > 3)) */
    else
    {
        g_current_obj_ind_struct->sim_id = MMI_SIM1;
    }

    if (second_byte[0] == 0x82)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_OBJECT_FILEIS_NOTIFICATION);
        g_current_obj_ind_struct->file_type = SRV_MMS_FILE_TYPE_NOTIFICATION;
        srv_mms_save_mms_to_drv(filename, SRV_MMS_DEFAULT_SYS_DRIVE);
        /* This is a Notification */

    }
    else if (second_byte[0] == 0x86)
    {
        g_current_obj_ind_struct->file_type = SRV_MMS_FILE_TYPE_DELIVERY_REPORT;
        srv_mms_save_mms_to_drv(filename, SRV_MMS_DEFAULT_SYS_DRIVE);
    }
    else if (second_byte[0] == 0x88)
    {
        g_current_obj_ind_struct->file_type = SRV_MMS_FILE_TYPE_READ_REPORT;
        srv_mms_save_mms_to_drv(filename, SRV_MMS_DEFAULT_SYS_DRIVE);
    }
    else
    {
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_save_mms_to_drv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  drv_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_save_mms_to_drv(PU16 filename, int drv_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Concatinate the File Path and the name and then Send Copy Request */
    U8 full_file_path[(SRV_FMGR_PATH_MAX_LEN + 1 + UMMS_CONVERT_INDEX) * ENCODING_LENGTH];
    int fh = 0;
    kal_uint32 size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SAVE_MMS_TO_DRV, drv_type, g_current_obj_ind_struct->sim_id);

    if (srv_mms_mem_mgr_app_adm_low_memory())   /* MAUI_02142001  */
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SAVE_MMS_TO_DRV, 7, 7);
        return;
    }

    srv_mms_generate_file_path(drv_type, g_current_obj_ind_struct->sim_id);

    
        mmi_ucs2cpy((S8*) full_file_path, (S8*) g_current_obj_ind_struct->default_sys_folder_path);
        mmi_ucs2cat((S8*) full_file_path, (S8*) L"\\");
        
    

    fh = FS_Open((UI_string_type) filename, FS_READ_ONLY);

    FS_GetFileSize(fh, &size);

    FS_Close(fh);


    while(FS_QmGetFree((BYTE*)full_file_path) < size)
    {
        srv_mms_obj_ind_delete_node_and_file(0, MMI_SIM_ALL);
    }

        srv_mms_generate_unique_file_name(SRV_MMS_DEFAULT_SYS_DRIVE);
        mmi_ucs2cat((S8*) full_file_path, (S8*) g_current_obj_ind_struct->unique_file_name);

    fh = FS_Move(filename, (U16*) full_file_path, FS_MOVE_KILL | FS_MOVE_OVERWRITE, NULL, NULL, 0);
    if (fh == FS_NO_ERROR)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_COPY_REQ_IS_SUCESS);
        /* If the current Message Type is Notification Add to the Queue */
        if ((g_current_obj_ind_struct->file_type == SRV_MMS_FILE_TYPE_NOTIFICATION) ||
            (g_current_obj_ind_struct->file_type == SRV_MMS_FILE_TYPE_DELIVERY_REPORT) ||
            (g_current_obj_ind_struct->file_type == SRV_MMS_FILE_TYPE_READ_REPORT))
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_CURRENT_OBJECT_TYPE, g_current_obj_ind_struct->file_type);
            if (drv_type == SRV_MMS_DEFAULT_SYS_DRIVE)
            {
                g_current_obj_ind_struct->sim_push.next_push++;
                g_current_obj_ind_struct->sim_push.count++;
            }
            srv_mms_enqueue_in_object_list();
            if ((g_current_obj_ind_struct->state != SRV_MMS_OBJ_STATE_BUSY) && (srv_mms_is_usb_mode() != TRUE))
            {
                srv_mms_check_and_send_object_req();
            }
            else
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_STATE_IS_BUSY);
                /* Do Nothing */
            }
        }
        else
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_CURRENT_OBJECT_TYPE, g_current_obj_ind_struct->file_type);
            /* Do Nothing */
        }
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_COPY_REQ_IS_UN_SUCESS);
        /* Log the error with the File Name */
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_generate_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv_type        [IN]        
 *  sim_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_generate_file_path(int drv_type, U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 def_drive_str[SRV_MMS_DRIVE_NAME_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_GENERATE_FILE_PATH, drv_type, sim_id);
    
        sprintf((S8*) def_drive_str, "%c", SRV_MMS_DEFAULT_SYS_DRIVE);
        mmi_asc_to_ucs2((S8*) g_current_obj_ind_struct->default_sys_folder_path, (S8*) def_drive_str);
        mmi_ucs2cat((S8*) g_current_obj_ind_struct->default_sys_folder_path, (S8*) L":\\");

        mmi_ucs2cat((S8*) g_current_obj_ind_struct->default_sys_folder_path, (S8*) SRV_MMS_DEFAULT_OBJ_IND_FOLDER);

        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_UMMS_PATH_FOR_NOTIFICATION,
            g_current_obj_ind_struct->default_sys_folder_path);

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_generate_unique_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_generate_unique_file_name(int drv_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 current_time = 0;
    U8 tmp_str[(UMMS_CONVERT_INDEX + 1) * ENCODING_LENGTH] = {0, };
    U8 tmp_file_name[(SRV_MMS_OBJ_FILE_NAME_LEN + 1) * ENCODING_LENGTH];
    U8 temp[20];
    
    
    U8 prefix[2 * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_current_obj_ind_struct->sim_id)
    {
        case MMI_SIM1:
            mmi_ucs2cpy((S8*) prefix, (S8*) L"1");
            break;
        case MMI_SIM2:
            mmi_ucs2cpy((S8*) prefix, (S8*) L"2");
            break;
        case MMI_SIM3:
            mmi_ucs2cpy((S8*) prefix, (S8*) L"3");
            break;
        case MMI_SIM4:
            mmi_ucs2cpy((S8*) prefix, (S8*) L"4");
            break;
        default:
            mmi_ucs2cpy((S8*) prefix, (S8*) L"1");
            break;
    }
    memset(temp, 0, 20);
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_UNIQUE_FILE_NAME_ENTRY, drv_type, g_current_obj_ind_struct->sim_id);
    if (SRV_MMS_DEFAULT_SYS_DRIVE == drv_type)
    {

        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            MMI_UMMS_UNIQUE_FILE_NAME_PUSH_LIST,
            g_current_obj_ind_struct->sim_push.count,
            g_current_obj_ind_struct->sim_push.next_push);

            /* if(0 == g_current_obj_ind_struct->sim1_push.next_push)
               {
               g_current_obj_ind_struct->sim1_push.next_push++;
               } */
            sprintf((S8*) temp, "%u.mms", g_current_obj_ind_struct->sim_push.next_push);
            mmi_asc_to_ucs2((S8*) tmp_file_name, (S8*) temp);
            memset(g_current_obj_ind_struct->unique_file_name, 0, (SRV_MMS_OBJ_FILE_NAME_LEN + 1) * ENCODING_LENGTH);
            mmi_ucs2cat((S8*) g_current_obj_ind_struct->unique_file_name, (S8*) prefix);
            mmi_ucs2cat((S8*) g_current_obj_ind_struct->unique_file_name, (S8*) tmp_file_name);
            g_current_obj_ind_struct->filename_int = g_current_obj_ind_struct->sim_push.next_push;
        }
    else
    {
        current_time = srv_mms_get_current_utc_time();
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_UNIQUE_FILE_NAME, current_time);
        gui_itoa(current_time, (UI_string_type) tmp_str, UMMS_CONVERT_INDEX);
        memset(g_current_obj_ind_struct->unique_file_name, 0, (UMMS_CONVERT_INDEX + 1) * ENCODING_LENGTH);
        mmi_ucs2cpy((S8*) g_current_obj_ind_struct->unique_file_name, (S8*) tmp_str);
        mmi_ucs2cat((S8*) g_current_obj_ind_struct->unique_file_name, (S8*) SRV_MMS_FILE_EXT);
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_UNIQUE_FILE_NAME_GENERATE, g_current_obj_ind_struct->unique_file_name);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_enqueue_in_object_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_enqueue_in_object_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_notification_list *msg_hndlr = NULL;
    srv_mms_notification_list *temp_node = NULL;
    srv_mms_notification_list *prev_node = NULL;

    /* umms_req_msg_handler_struct *start = NULL; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_UMMS_ADD_TO_OBJECT_LIST,
        g_current_obj_ind_struct->sim_id,
        g_current_obj_ind_struct->filename_int,
        g_current_obj_ind_struct->file_type);
    msg_hndlr = (srv_mms_notification_list*) srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_mms_notification_list));
    MMI_ASSERT(msg_hndlr);
    memset(msg_hndlr, 0, sizeof(srv_mms_notification_list));
    mmi_ucs2cpy((S8*) msg_hndlr->file_name, (S8*) g_current_obj_ind_struct->unique_file_name);

    msg_hndlr->sim_id = g_current_obj_ind_struct->sim_id;
    msg_hndlr->filename_int = g_current_obj_ind_struct->filename_int;
    msg_hndlr->file_type = g_current_obj_ind_struct->file_type;
    msg_hndlr->next = NULL;

    temp_node = g_notification_list;
    while (temp_node != NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PRINT_OBJECT_LIST, temp_node->sim_id, temp_node->filename_int);
        temp_node = temp_node->next;
    }

    temp_node = g_notification_list;

    if (g_notification_list == NULL)
    {
        g_notification_list = msg_hndlr;
    }
    else
    {
        while (temp_node && temp_node->filename_int < msg_hndlr->filename_int)
        {
            prev_node = temp_node;
            temp_node = temp_node->next;
        }

        if(prev_node)
        {
            prev_node->next = msg_hndlr;
            msg_hndlr->next = temp_node;
        }
        else
        {
            msg_hndlr->next = g_notification_list;
            g_notification_list = msg_hndlr;
        }
        
    }
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_UMMS_PRINT_PUSH_LIST_INFO,
        g_current_obj_ind_struct->sim_push.count,
        g_current_obj_ind_struct->sim_push.next_push);

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_free_object_handler_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_free_object_handler_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_notification_list *temp_node = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_MMS_MEM_MGR_APP_ADM_FREE_OBJECT_LIST); */
    temp_node = g_notification_list->next;
    if (temp_node->next != NULL)
    {
        g_notification_list->next = temp_node->next;
        srv_mms_mem_mgr_app_adm_free(temp_node);
        temp_node = NULL;
    }
    else
    {
        srv_mms_mem_mgr_app_adm_free(temp_node);
        temp_node = NULL;
        g_notification_list->next = NULL;
    }

    temp_node = g_notification_list;
    while (temp_node != NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PRINT_OBJECT_LIST, temp_node->file_name);
        temp_node = temp_node->next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_obj_file_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  complete_file_path      [?]     [?]     [?]     [?]
 *  node                    [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_obj_file_path(U8 *complete_file_path, srv_mms_notification_list *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(node);
    if (node->file_name != NULL)
    {

        srv_mms_generate_file_path((int)SRV_MMS_DEFAULT_SYS_DRIVE, node->sim_id);

        mmi_ucs2cpy((S8*) complete_file_path, (S8*) g_current_obj_ind_struct->default_sys_folder_path);
        mmi_ucs2cat((S8*) complete_file_path, (S8*) L"\\");
        mmi_ucs2cat((S8*) complete_file_path, (S8*) node->file_name);
    }
    else
    {
        MMI_ASSERT(0);
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DELETE_FILE_PATH, complete_file_path);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_start_object_indication_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_start_object_indication_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_START_TIMER);
    StartTimer(UMMS_SEND_TIMER, MMI_UMMS_TIMER_VALUE, srv_mms_handle_obj_timer_expiry);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_stop_object_indication_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_stop_object_indication_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_STOP_TIMER);
    StopTimer(UMMS_SEND_TIMER);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_object_indication_state_as_busy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_object_indication_state_as_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_obj_ind_struct->state = SRV_MMS_OBJ_STATE_BUSY;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_unset_object_indication_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_unset_object_indication_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_obj_ind_struct->state = SRV_MMS_OBJ_STATE_NORMAL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_handle_obj_timer_expiry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_handle_obj_timer_expiry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check the State.If Busy Just Restart the timer */
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PRINT_STATE, g_current_obj_ind_struct->state);
    if (g_current_obj_ind_struct->state == SRV_MMS_OBJ_STATE_BUSY)
    {
        /* Start the timer Again */
        srv_mms_start_object_indication_timer();
    }
    else
    {
        srv_mms_check_and_send_object_req();
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_check_and_send_object_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_check_and_send_object_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if (srv_dm_lawmo_is_wiping())
    {
        srv_mms_delete_all_obj_ind_msg();
        return;
    }
#endif /* __DM_LAWMO_SUPPORT__ */ 
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_CHECK_AND_SEND, g_notification_list);

    if (mms_is_ready() && !srv_mms_mem_mgr_app_adm_low_memory())        /* MAUI_02142001  */
    {
        if (g_notification_list != NULL)
        {
            srv_mms_send_object_indication();
        }
    }
    else
    {
        srv_mms_stop_object_indication_timer();
        srv_mms_start_object_indication_timer();
    }
}

void srv_mms_object_indication_rsp_callback(srv_mms_result_enum srv_result, void *rsp_data, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_mms_send_object_indication
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_send_object_indication(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Set the State as UMMS_OBJ_STATE_BUSY before Sending the Request */
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Set the State as UMMS_OBJ_STATE_BUSY before Sending the Request */
    srv_mms_obj_ind_struct msg_req;
    U8 *complete_file_path =
        (U8*) srv_mms_mem_mgr_app_adm_alloc((SRV_FMGR_PATH_MAX_LEN + 1 + UMMS_CONVERT_INDEX) * ENCODING_LENGTH);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&msg_req, 0, sizeof(srv_mms_obj_ind_struct));
    msg_req.app_id = MMA_APP_ID_MMS_APP;
    msg_req.call_back = srv_mms_object_indication_rsp_callback;
    msg_req.user_data = 0;

    if (g_notification_list)
    {
        srv_mms_obj_ind_set_in_process_sim_id(g_notification_list->sim_id);
        srv_mms_obj_ind_set_in_process_filename_int(g_notification_list->filename_int);

        msg_req.msg_type = MMA_MSG_TYPE_NOTIFICATION;
        srv_mms_get_obj_file_path(complete_file_path, g_notification_list);
        if (complete_file_path != NULL)
        {
            mmi_ucs2cpy((S8*) msg_req.mms_filepath, (S8*) complete_file_path);
        }

        msg_req.sim_id = g_notification_list->sim_id;

        g_current_obj_ind_struct->state = SRV_MMS_OBJ_STATE_BUSY;
        srv_mms_send_obj_ind(&msg_req);

        if (complete_file_path != NULL)
        {
            srv_mms_mem_mgr_app_adm_free(complete_file_path);
            complete_file_path = NULL;
        }
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_object_indication_rsp_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_result      [IN]        
 *  rsp_data        [?]         [?]
 *  user_data       [IN]        
 *  inMsg(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_object_indication_rsp_callback(srv_mms_result_enum srv_result, void *rsp_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_obj_res_struct *contRsp = (srv_mms_obj_res_struct*) rsp_data;
    
    U8 sim_id = 0;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_obj_ind_struct->state = SRV_MMS_OBJ_STATE_NORMAL;
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        MMI_UMMS_OBJ_IND_RES,
        g_full_ind_counter,
        g_obj_ind_flag,
        contRsp->result,
        SRV_MMS_SHOW_FULL_POPUP_COUNT,
        SRV_MMS_MAX_NUM_FULL_POPUP);

    if ((contRsp->result == MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED) ||
        (contRsp->result == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE) || (contRsp->result == MMA_RESULT_FAIL_ROOT_DIR_FULL))
    {
        ++g_full_ind_counter;
        g_obj_ind_flag = MMI_TRUE;
        if ((g_full_ind_counter != 0) &&
            ((g_full_ind_counter % (SRV_MMS_SHOW_FULL_POPUP_COUNT * SRV_MMS_MAX_NUM_FULL_POPUP)) == 0))
        {
            g_full_ind_counter = 0;
            g_obj_ind_flag = MMI_FALSE;
            contRsp->result = MMA_RESULT_OK;    /* MMS Application will not retry push further and need to delete push from the queue */
        }
    }
    else
    {
        g_full_ind_counter = 0;
        g_obj_ind_flag = MMI_FALSE;
    }

    if ((contRsp->result == MMA_RESULT_FAIL_INSUFFICIENT_MEMORY) ||
        (contRsp->result == MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED) ||
        (contRsp->result == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE) ||
        (contRsp->result == MMA_RESULT_FAIL_BUSY) ||
        (contRsp->result == MMA_RESULT_FAIL_SUSPENDED_MODE) ||
        (contRsp->result == MMA_RESULT_FAIL_MEM_CARD_PLUG_OUT) || (contRsp->result == MMA_RESULT_FAIL_ROOT_DIR_FULL))
    {
        srv_mms_stop_object_indication_timer();
        srv_mms_start_object_indication_timer();
    }
    else
    {
        sim_id = srv_mms_obj_ind_get_in_process_sim_id();
        srv_mms_obj_ind_set_in_process_filename_int(0);
        srv_mms_obj_ind_delete_node_and_file(0, sim_id);

        srv_mms_check_and_send_object_req();
        srv_mms_stop_object_indication_timer();
        srv_mms_start_object_indication_timer();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_full_ind_counter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_mms_get_full_ind_counter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_full_ind_counter;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_obj_ind_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mms_get_obj_ind_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_obj_ind_flag;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_obj_ind_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 * RETURNS
 *  MMI_BOOL(?)
 *****************************************************************************/
void srv_mms_set_obj_ind_flag(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_obj_ind_flag = flag;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_init_object_ind_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_init_object_ind_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Read the Files from the System Folder and Create the Link List */
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_OBJECT_IND_INIT);
    srv_mms_init_push_info((U8) MMI_SIM1);

    srv_mms_generate_file_path((int)SRV_MMS_DEFAULT_SYS_DRIVE, (U8) MMI_SIM1);
    file_handle = FS_Open((UI_string_type) g_current_obj_ind_struct->default_sys_folder_path, FS_READ_ONLY);
    if (file_handle > 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SYS_FOLDER_EXISTS);
        FS_Close(file_handle);
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SYS_FOLDER_NOT_EXISTS);
        FS_CreateDir((PU16) g_current_obj_ind_struct->default_sys_folder_path);
    }

    srv_mms_generate_file_path((int)SRV_MMS_DEFAULT_PUBLIC_DRIVE, (U8) MMI_SIM1);
    file_handle = FS_Open((UI_string_type) g_current_obj_ind_struct->default_public_folder_path, FS_READ_ONLY);
    if (file_handle > 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PUBLIC_FOLDER_EXISTS);
        FS_Close(file_handle);
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PUBLIC_FOLDER_NOT_EXISTS);
        FS_CreateDir((PU16) g_current_obj_ind_struct->default_public_folder_path);
        FS_SetAttributes(
            (unsigned short*)g_current_obj_ind_struct->default_public_folder_path,
            FS_ATTR_DIR | FS_ATTR_HIDDEN);
    }

    srv_mms_start_object_indication_timer();
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_read_noti_file_frm_sys_drv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_read_noti_file_frm_sys_drv(U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh_cur;
    FS_DOSDirEntry file_info;
    S8 path[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
    U8 filename[(SRV_FMGR_PATH_MAX_LEN + UMMS_CONVERT_INDEX + 1) * ENCODING_LENGTH];
    U8 prefix[2 * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Apend *.mms in the file path */
    switch (sim_id)
    {
        case MMI_SIM1:
            mmi_ucs2cpy((S8*) prefix, (S8*) L"1");
            break;
        case MMI_SIM2:
            mmi_ucs2cpy((S8*) prefix, (S8*) L"2");
            break;
        case MMI_SIM3:
            mmi_ucs2cpy((S8*) prefix, (S8*) L"3");
            break;
        case MMI_SIM4:
            mmi_ucs2cpy((S8*) prefix, (S8*) L"4");
            break;
        default:
            mmi_ucs2cpy((S8*) prefix, (S8*) L"1");
            break;
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_READ_FROM_SYS_DRIVE, sim_id);
    mmi_ucs2cpy((S8*) path, (S8*) g_current_obj_ind_struct->default_sys_folder_path);
    mmi_ucs2cat((S8*) path, (S8*) L"\\");
    mmi_ucs2cat((S8*) path, (S8*) prefix);
    mmi_ucs2cat((S8*) path, (S8*) SRV_MMS_SEARCH_FILE_EXT);

    if ((fh_cur = FS_FindFirst(
                    (const WCHAR*)path,
                    0,
                    0,
                    &file_info,
                    (U16*) filename,
                    (SRV_FMGR_PATH_MAX_LEN + UMMS_CONVERT_INDEX + 1) * ENCODING_LENGTH)) >= 0)
    {
        do
        {
            if (!(file_info.Attributes & FS_ATTR_DIR))
            {
                srv_mms_get_file_name_and_add_to_list(filename, sim_id);
            }
        } while ((FS_FindNext
                  (fh_cur, &file_info, (U16*) filename,
                   (SRV_FMGR_PATH_MAX_LEN + UMMS_CONVERT_INDEX + 1) * ENCODING_LENGTH) == FS_NO_ERROR));
        FS_FindClose(fh_cur);
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_file_name_and_add_to_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?]         [?]         [?]         [?]
 *  sim_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_get_file_name_and_add_to_list(U8 filename[], U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_file_type mms_type = SRV_MMS_FILE_TYPE_MAX;
    U16 file_name_int = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_FILE_NAME_READ_FROM_SYS_DRV, filename, sim_id);
    memset(g_current_obj_ind_struct->unique_file_name, 0, (UMMS_CONVERT_INDEX + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) g_current_obj_ind_struct->unique_file_name, (S8*) filename);
    mms_type = srv_mms_get_file_type(filename);
    file_name_int = srv_mms_get_int_file_name(filename);
    if (mms_type != SRV_MMS_FILE_TYPE_MAX)
    {
        g_current_obj_ind_struct->file_type = mms_type;

        g_current_obj_ind_struct->sim_id = sim_id;

        g_current_obj_ind_struct->sim_push.count++;
        if (g_current_obj_ind_struct->sim_push.next_push <= file_name_int)
        {
            g_current_obj_ind_struct->sim_push.next_push = file_name_int + 1;
        }

        g_current_obj_ind_struct->filename_int = file_name_int;
        srv_mms_enqueue_in_object_list();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_int_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_get_int_file_name(U8 filename[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count = 0;
    U8 filename_temp[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(filename_temp, 0, 20);
    mmi_ucs2_to_asc((S8*) filename_temp, (S8*) filename);
    while (filename_temp[count] && (count < 20))
    {
        filename_temp[count] = filename_temp[count + 1];
        count++;
    }
    count = 0;
    while (filename_temp[count] && (filename_temp[count] != '.') && (count < 20))
    {
        ++count;
    }
    if (count == 20)
    {
        return 0;
    }

    if (filename_temp[count] == '.')
    {
        filename_temp[count] = 0;
        return (U8) atoi((S8*) filename_temp);
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_file_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [?]     [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_file_type srv_mms_get_file_type(U8 filename[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 path[(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH];
    U8 second_byte[1] = {0, };
    U32 size = 0;

    /* Open the file and based on the type save to Stystem or Public Drive */
    FS_HANDLE file_hnd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Apend *.mms in the file path */
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_READ_FROM_SYS_DRIVE);
    mmi_ucs2cpy((S8*) path, (S8*) g_current_obj_ind_struct->default_sys_folder_path);
    mmi_ucs2cat((S8*) path, (S8*) L"\\");
    mmi_ucs2cat((S8*) path, (S8*) filename);

    file_hnd = FS_Open((const WCHAR*)path, FS_READ_ONLY);
    FS_Seek(file_hnd, 1, FS_FILE_BEGIN);
    FS_Read(file_hnd, &second_byte, 1, &size);
    FS_Close(file_hnd);
    if (second_byte[0] == 0x82)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_OBJECT_FILEIS_NOTIFICATION);
        return SRV_MMS_FILE_TYPE_NOTIFICATION;
    }
    if (second_byte[0] == 0x86)
    {
        return SRV_MMS_FILE_TYPE_DELIVERY_REPORT;
    }
    if (second_byte[0] == 0x88)
    {
        return SRV_MMS_FILE_TYPE_READ_REPORT;
    }
    return SRV_MMS_FILE_TYPE_MAX;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_obj_ind_delete_node_and_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename_int        [IN]        
 *  sim_id              [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_obj_ind_delete_node_and_file(U16 filename_int, U8 sim_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_notification_list *temp_node = NULL;
    U8 *complete_file_path;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_DELETE_FILE_AND_NODE, filename_int, sim_id);

    MMI_ASSERT(g_notification_list);
    

    srv_mms_generate_file_path((int)SRV_MMS_DEFAULT_SYS_DRIVE, sim_id);

    if(srv_mms_obj_ind_get_in_process_filename_int() && (srv_mms_obj_ind_get_in_process_filename_int() == g_notification_list->filename_int))
    {
        temp_node = g_notification_list->next;
        if(temp_node)
    {
        g_notification_list->next = temp_node->next;
            }
    }
    else if(srv_mms_obj_ind_get_in_process_filename_int() == 0)
    {
        temp_node = g_notification_list;
        g_notification_list = temp_node->next;
        }
        else
        {
        MMI_ASSERT(0);
        /*In process Filename set wrong or didn't reset at response*/
        }



                        MMI_TRACE(
                            MMI_INET_TRC_G6_MMS,
                            TRC_MMI_UMMS_DELETED_NODE_INFO,
                    temp_node->filename_int,
                    temp_node->sim_id);

        if(temp_node)
            {
				complete_file_path = (U8*) srv_mms_mem_mgr_app_adm_alloc((SRV_FMGR_PATH_MAX_LEN + 1 + UMMS_CONVERT_INDEX) * ENCODING_LENGTH);
				MMI_ASSERT(complete_file_path);

                memset(complete_file_path, 0, (SRV_FMGR_PATH_MAX_LEN  + 1 + UMMS_CONVERT_INDEX) * ENCODING_LENGTH);
                mmi_ucs2cpy((S8*) complete_file_path, (S8*) g_current_obj_ind_struct->default_sys_folder_path);
                mmi_ucs2cat((S8*) complete_file_path, (S8*) L"\\");
        mmi_ucs2cat((S8*) complete_file_path, (S8*) temp_node->file_name);
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_DELETE_FILE_PATH, complete_file_path);
                FS_Delete((const WCHAR*)complete_file_path);

        srv_mms_mem_mgr_app_adm_free(temp_node);
        temp_node = NULL;

        srv_mms_mem_mgr_app_adm_free(complete_file_path);
        complete_file_path = NULL;

                mmi_update_sim_push_info(sim_id);
    }


    temp_node = g_notification_list;
    while (temp_node != NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_LEFT_NODE_INFO, temp_node->sim_id, temp_node->filename_int);
        temp_node = temp_node->next;
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_DELETE_FILE_AND_NODE_RESULT, MMI_TRUE);

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_obj_ind_get_in_process_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_obj_ind_get_in_process_sim_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_current_obj_ind_struct->in_process_sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_obj_ind_set_in_process_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_obj_ind_set_in_process_sim_id(U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_obj_ind_struct->in_process_sim_id = sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_obj_ind_get_in_process_filename_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_mms_obj_ind_get_in_process_filename_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_current_obj_ind_struct->in_process_filename_int;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_obj_ind_set_in_process_filename_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_process_filename_int     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_obj_ind_set_in_process_filename_int(U16 in_process_filename_int)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_current_obj_ind_struct->in_process_filename_int = in_process_filename_int;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_update_sim_push_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_update_sim_push_info(U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_UPDATE_PUSH_INFO, sim_id);
    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        TRC_MMI_UMMS_UPDATE_PUSH_LIST,
        g_current_obj_ind_struct->sim_push.count,
        g_current_obj_ind_struct->sim_push.next_push);

    g_current_obj_ind_struct->sim_push.count--;

    MMI_TRACE(
        MMI_INET_TRC_G6_MMS,
        TRC_MMI_UMMS_UPDATE_PUSH_LIST,
        g_current_obj_ind_struct->sim_push.count,
        g_current_obj_ind_struct->sim_push.next_push);

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_init_push_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_init_push_info(U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_INIT_PUSH_LIST, sim_id);

    g_current_obj_ind_struct->sim_push.count = 0;
    g_current_obj_ind_struct->sim_push.next_push = 1;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_init_object_ind_sim_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_init_object_ind_sim_data(U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, TRC_MMI_UMMS_OBJECT_IND_INIT_SINGLE_SIM, sim_id);


    srv_mms_generate_file_path((int)SRV_MMS_DEFAULT_SYS_DRIVE, sim_id);
    file_handle = FS_Open((UI_string_type) g_current_obj_ind_struct->default_sys_folder_path, FS_READ_ONLY);
    if (file_handle > 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SYS_FOLDER_EXISTS);
        srv_mms_free_all_sim_related_object_handler_node(sim_id);
        srv_mms_read_noti_file_frm_sys_drv(sim_id);
        FS_Close(file_handle);
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_SYS_FOLDER_NOT_EXISTS);
        FS_CreateDir((PU16) g_current_obj_ind_struct->default_sys_folder_path);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_free_all_sim_related_object_handler_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_free_all_sim_related_object_handler_node(U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_notification_list *temp_node1, *temp_node2 = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_FREE_ALL_SIM_NODE, sim_id);
    temp_node1 = g_notification_list;

    if (g_notification_list)
    {
        while (temp_node1->next != NULL)
        {
            temp_node2 = temp_node1->next;
            if (temp_node2->sim_id == sim_id)
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PRINT_ALL_NODE, temp_node2->filename_int, temp_node2->sim_id);

                if (temp_node2->next != NULL)
                {
                    temp_node1->next = temp_node2->next;
                    srv_mms_mem_mgr_app_adm_free(temp_node2);
                    temp_node2 = NULL;
                    g_current_obj_ind_struct->sim_push.count--;
                }
                else
                {
                    srv_mms_mem_mgr_app_adm_free(temp_node2);
                    temp_node2 = NULL;
                    temp_node1->next = NULL;
                    g_current_obj_ind_struct->sim_push.count--;
                }
            }
            else
            {
                temp_node1 = temp_node1->next;
            }
        }

		if(g_current_obj_ind_struct->state != SRV_MMS_OBJ_STATE_BUSY)
		{
        if (g_notification_list && (g_notification_list->sim_id == sim_id))
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PRINT_ALL_NODE, temp_node1->filename_int, temp_node1->sim_id);

            temp_node1 = g_notification_list;
            g_notification_list = g_notification_list->next;
            srv_mms_mem_mgr_app_adm_free(temp_node1);
            temp_node1 = NULL;
            g_current_obj_ind_struct->sim_push.count--;
        }
    }
    }

    /* srv_mms_init_push_info(sim_id); */
    temp_node1 = g_notification_list;
    while (temp_node1 != NULL)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_PRINT_ALL_NODE, temp_node1->filename_int, temp_node1->sim_id);
        temp_node1 = temp_node1->next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_delete_all_obj_ind_msg
 * DESCRIPTION
 *  This API is used to delete all the MMS push indication messages.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_delete_all_obj_ind_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_free_all_sim_related_object_handler_node((U8) MMI_SIM1);

#ifdef __MMI_MMS_DUAL_SIM__
    srv_mms_free_all_sim_related_object_handler_node((U8) MMI_SIM2);
#endif 

    srv_mms_generate_file_path((int)UMMS_MMS_DEFAULT_SYS_DRIVE, (U8) MMI_SIM1);
    FS_XDelete(
        (WCHAR*) g_current_obj_ind_struct->default_sys_folder_path,
        FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE,
        NULL,
        0);
    /* FS_RemoveDir((const WCHAR *) g_current_obj_ind_struct->default_sys_folder_path); */
    FS_CreateDir((const WCHAR*)g_current_obj_ind_struct->default_sys_folder_path);

#ifdef __MMI_MMS_DUAL_SIM__
    srv_mms_generate_file_path((int)UMMS_MMS_DEFAULT_SYS_DRIVE, (U8) MMI_SIM2);
    FS_XDelete(
        (WCHAR*) g_current_obj_ind_struct->default_sys_folder_path,
        FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE,
        NULL,
        0);
    /* FS_RemoveDir((const WCHAR *) g_current_obj_ind_struct->default_sys_folder_path); */
    FS_CreateDir((const WCHAR*)g_current_obj_ind_struct->default_sys_folder_path);
#endif /* __MMI_MMS_DUAL_SIM__ */ 
}
#endif /* __MMI_MMS_MMA_MMS_OBJECT_IND__ */ 

#endif /* __MMI_MMS_2__ */ 

