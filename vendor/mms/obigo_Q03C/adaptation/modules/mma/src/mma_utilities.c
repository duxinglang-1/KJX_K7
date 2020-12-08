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
 * mma_utilities.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains MMA core functions, like MMAc_start, MMAc_wantsToRun.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MMA_UTILITIES_C
#define _MMA_UTILITIES_C

#if defined(MMS_SUPPORT)
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "kal_public_defs.h" 
#include "stack_ltlcom.h"
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "mmsadp.h"

#include "mma_struct.h"
#include "mmc_struct.h"
#include "mms_adp_struct.h"
#include "mms_sap_struct.h"

#include "app_datetime.h"
#include "wgui_datetime.h"
#include "DateTimeType.h"
#include "conversions.h"
#include "FileMgrSrvGProt.h"

#include "gui_typedef.h"

/* APPLIB */
#include "app_str.h"
#include "app_mine.h"
#include "app_datetime.h"

/* FS service */
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"

/* Unified Message */
#include "MMI_features.h"
#include "MMIDataType.h"
#ifdef __MMI_MMS_IN_UM__
//#include "UMGProt.h"
#include "UmSrvGprot.h"
#include "UmSrvDefs.h"
#endif 
#include "wgui_categories_util.h"
#ifdef __USB_IN_NORMAL_MODE__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif 

#include "msf_lib.h"    /* MSF: ANSI Standard libs allowed to use */
#include "msf_cfg.h"    /* MSF: Module definition */
#include "msf_def.h"    /* MSF: Global definitions */
#include "msf_core.h"   /* MSF: System core call */
#include "msf_dcvt.h"   /* MSF: Type conversion routines */
#include "msf_mem.h"    /* MSF: Memory handling */
#include "msf_cmmn.h"   /* MSF: MSF common functions, e.g. string handling */
#include "msf_pipe.h"   /* MSF: Pipe handling */
#include "msf_file.h"   /* MSF: File handling */
#include "msf_log.h"    /* MSF: Log handling */
#include "int_cmmn.h"

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#include "stk_if.h"     /* STK: WSP/HTTP Stack signals and types */
#else
#include "nts_if.h"
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
#include "mms_cfg.h"
#include "mms_def.h"    /* MMS: Exported types in adapter/connector functions */
#include "mms_if.h"     /* MMS: Exported signal interface */
#include "mmsl_if.h"
#include "mconfig.h"
#include "Mmem.h"
/* SLS */
#include "mma_smil.h"
//#include "sls_cfg.h"
//#include "sls_def.h"
//#include "sls_if.h"

/* MMA Service */
#include "mma_cfg.h"
#include "mma_def.h"
#include "mma_api.h"
#include "mma_env.h"
#include "mma_main.h"
#include "mma_sendrecv.h"
#include "mma_msgmgr.h"
#include "mma_utilities.h"
#include "mma_msg_struct.h"
#include "mma_create.h"
#include "mma_parse.h"
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
#include "mma_drmsrv.h"
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */

/***************************************************************************** 
* Define
*****************************************************************************/

/***************************************************************************** 
* Typedef 
*****************************************************************************/
extern mms_mma_queue_struct *g_mma_wrapper_queue;
/***************************************************************************** 
* Local static Variable
*****************************************************************************/
static kal_uint32 last_ticks;
extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);
//extern kal_int32 mmi_chset_ucs2_to_utf8_string(kal_uint8 *dest, kal_int32 dest_size, kal_uint8 *src);

/***************************************************************************** 
* Local Function
*****************************************************************************/
/***************************************************************************** 
 * FUNCTION
 *  mma_reset_last_tick
 * DESCRIPTION
 * This function will reset the value for last tick.
 *  
 * PARAMETERS
 * void
 * RETURNS
 * void
 *****************************************************************************/
void mma_reset_last_tick(void)
{
    kal_get_time(&last_ticks);
}

/***************************************************************************** 
 * FUNCTION
 *  mma_check_and_sleep
 * DESCRIPTION
 * This function will check, if MMA is executing for a long time and if so
 * it make it sleep.
 *  
 * PARAMETERS
 * void
 * RETURNS
 * void
 *****************************************************************************/
void mma_check_and_sleep(void)
{
    kal_uint32 ticks;
    
    kal_get_time(&ticks);
    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_CHECK_AND_SLEEP,"(mma_utilities.c)mma_check_and_sleep last_ticks: %d  Current_ticks:%d\n", last_ticks, ticks));

     if (ticks > last_ticks)
    {
        if (ticks - last_ticks > KAL_TICKS_1_SEC)
        {
            /* Voluntarily make the current task sleep */
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SLEEP_START,"(mma_utilities.c)MMA sleep at tick: %d\n", ticks));


            kal_sleep_task(kal_milli_secs_to_ticks(10));
            kal_get_time(&last_ticks);
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_SLEEP_END, "(mma_utilities.c)MMA sleep at tick: %d\n", last_ticks));
        }
    }    
    else
    {
        /* Abnormal. maybe integer overflow */
        last_ticks = ticks;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mms_mma_send_ilm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  local_para_ptr      [IN]         
 *  peer_buff_ptr       [IN]         
 *  msg_id              [IN]        
 *  dst_id              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mms_mma_send_ilm(void *local_para_ptr, void *peer_buff_ptr, msg_type msg_id, module_type dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    sap_type sap_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dst_id)
    {
        case MOD_MMI:
            sap_id = WAP_MMI_SAP;
            break;
        default:
            /* invalid value */
            sap_id = WAP_MMI_SAP;
            break;
    }   /* switch (dst_id) */

    ilm_ptr = allocate_ilm(MOD_MMS);
    ilm_ptr->src_mod_id = MOD_MMS;
    ilm_ptr->dest_mod_id = dst_id;
    ilm_ptr->sap_id = sap_id;
    ilm_ptr->msg_id = msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_para_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;
    msg_send_ext_queue(ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  mma_insert_node_to_queue
 * DESCRIPTION
 *  Append the new node to queue
 * PARAMETERS
 *  queue_list      [IN]        
 *  first_id        [IN]        
 *  second_id       [IN]        
 *  data            [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
mma_result_enum mma_insert_node_to_queue(
                    mms_mma_queue_struct **queue_list,
                    kal_uint32 first_id,
                    kal_uint32 second_id,
                    void *data,
					mma_queue_action_type_enum action_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_mma_queue_struct *new_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (queue_list == NULL)
    {
        return MMA_RESULT_FAIL_INVALID_PARAMETER;
    }
    new_node = (mms_mma_queue_struct*) MMA_CALLOC(sizeof(mms_mma_queue_struct));
    if (new_node == NULL)
    {
        return MMA_RESULT_FAIL_INSUFFICIENT_MEMORY;
    }
    new_node->first_id = first_id;
    new_node->second_id = second_id;
    new_node->data = data;
	new_node->action_type = action_type;

    if (*queue_list == NULL)
    {
        *queue_list = new_node;
        return MMA_RESULT_OK;
    }
    else
    {
        mms_mma_queue_struct *tmp_node_p = *queue_list;

        while (tmp_node_p->next != NULL)
        {
            tmp_node_p = tmp_node_p->next;
        }
        tmp_node_p->next = new_node;
        return MMA_RESULT_OK;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_remove_node_from_queue
 * DESCRIPTION
 *  Move node from queue (User is responsible to release node memory)
 * PARAMETERS
 *  queue_list      [IN]        
 *  first_id        [IN]        
 *  second_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mms_mma_queue_struct *mma_remove_node_from_queue(
                        mms_mma_queue_struct **queue_list,
                        kal_uint32 first_id,
                        kal_uint32 second_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_mma_queue_struct *tmp_list_p, *prev_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (queue_list == NULL || *queue_list == NULL)
    {
        return NULL;
    }
    tmp_list_p = *queue_list;
    prev_p = NULL;

    while (tmp_list_p != NULL)
    {
        if (tmp_list_p->first_id == first_id && tmp_list_p->second_id == second_id)
        {
            if (tmp_list_p == *queue_list)
            {
                *queue_list = (*queue_list)->next;
            }
            else
            {
                prev_p->next = tmp_list_p->next;
            }
            return tmp_list_p;
        }
        prev_p = tmp_list_p;
        tmp_list_p = tmp_list_p->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_node_from_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  queue_list      [IN]         
 *  first_id        [IN]        
 *  second_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mms_mma_queue_struct *mma_get_node_from_queue(
                        mms_mma_queue_struct *queue_list,
                        kal_uint32 first_id,
                        kal_uint32 second_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mms_mma_queue_struct *tmp_list_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (queue_list == NULL)
    {
        return NULL;
    }
    tmp_list_p = queue_list;

    while (tmp_list_p != NULL)
    {
        if (tmp_list_p->first_id == first_id && tmp_list_p->second_id == second_id)
        {
            return tmp_list_p;
        }
        tmp_list_p = tmp_list_p->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_count_node_in_queue
 * DESCRIPTION
 *  
 * PARAMETERS
 *  queue_list      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 mma_count_node_in_queue(mms_mma_queue_struct *queue_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; queue_list != NULL; i++, queue_list = queue_list->next);
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  mma_handle_wrapper_queue_next_call_based_on_action_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mma_handle_wrapper_queue_next_call_based_on_action_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(g_mma_wrapper_queue->action_type)
	{
	case MMA_ACTION_DELETE_MSG:
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_ENV_SIG_GET_NEXT_DELETE_MSG_REQ,
                          "Next MMSif_deleteMessage(): msg %d by %d\n", g_mma_wrapper_queue->second_id,
                          g_mma_wrapper_queue->first_id));
        MMSif_deleteMessage(MSF_MODID_MMA, MMA_TRANSLATE_MSG_ID(g_mma_wrapper_queue->second_id), (MmsFileType)mma_msgmgr_get_msg_suffix(g_mma_wrapper_queue->second_id), (MSF_UINT8) mma_get_mms_type_message_storage(g_mma_wrapper_queue->second_id));
		break;

	default:
		/* not found use. You can add more enums if found use. */
		ASSERT(0);
		break;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mma_check_fs_is_busy
 * DESCRIPTION
 *  This function is used to check file system is busy
 * PARAMETERS
 *  void
 * RETURNS
 *  MSF_BOOL
 *****************************************************************************/
kal_bool mma_check_fs_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMS_IN_LARGE_STORAGE
    /* Order: 1. Invisible NAND 2. Visible NAND 3. visible NOR 4. Invisible NOR */
    drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
#endif /* MMS_IN_LARGE_STORAGE */ 

    if (FS_GetDevStatus(drive_letter, FS_FEATURE_STATE_ENUM) == FS_DEVICE_BUSY)
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_UTILITIES_CHECK_FS_DEVICE_BUSY, "mma_check_fs_is_busy(): drive %c is busy", (char)drive_letter));
        return KAL_TRUE;
    }
    else
    {
        MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_UTILITIES_CHECK_FS_DEVICE_NOT_BUSY, "mma_check_fs_is_busy(): drive %c is not busy", (char)drive_letter));
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_mms_avaliable_file_space
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *  used_bytes      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint64 mma_get_mms_avaliable_file_space(kal_uint32 *used_bytes, kal_uint8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR wpath[16] = {0};
    char path[16] = {0};
    FS_DiskInfo diskinfo = {0};
    kal_uint64 freebytes = 0;
    int folder_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (storage == MMA_MSG_STORAGE_PHONE)
    {

#if defined(__FS_QM_SUPPORT__) && !defined(MMS_IN_LARGE_STORAGE)
    kal_int32 ret = 0;
#endif 
    int drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);

#ifdef MMS_IN_LARGE_STORAGE
    /* Order: 1. Invisible NAND 2. Visible NAND 3. visible NOR 4. Invisible NOR */
    drive_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
#endif /* MMS_IN_LARGE_STORAGE */ 
    kal_wsprintf(wpath, "%c:\\", (char)drive_letter);
    sprintf(path, "%c:\\@mms\\", (char)drive_letter);

#if !defined(MMS_IN_LARGE_STORAGE)
#if defined(__FS_QM_SUPPORT__)
    ret = FS_QmGetFree((BYTE*) "Z:\\@mms\\");
    if (ret < 0)
    {
        freebytes = 0;
    }
    else
    {
        freebytes = ret;
    }
#else /* defined(__FS_QM_SUPPORT__) */ 
    if (FS_GetDiskInfo(wpath, &diskinfo, FS_DI_FREE_SPACE | FS_DI_BASIC_INFO) >= 0)
    {
        freebytes = (kal_uint64)diskinfo.FreeClusters * (kal_uint64)diskinfo.SectorsPerCluster * (kal_uint64)diskinfo.BytesPerSector;
       
    }
#endif /* defined(__FS_QM_SUPPORT__) */ 
    if (used_bytes)
    {
        *used_bytes = 0;
        kal_wsprintf(wpath, "%c:\\@mms", (char)drive_letter);
        folder_size = FS_GetFolderSize(wpath, FS_COUNT_IN_BYTE, NULL, 0);
        if (folder_size >= 0)
        {
            *used_bytes = (kal_uint32) folder_size;
        }
    }
#elif defined(MMS_IN_LARGE_STORAGE)
    if (FS_GetDiskInfo(wpath, &diskinfo, FS_DI_FREE_SPACE | FS_DI_BASIC_INFO) >= 0)
    {
        freebytes = (kal_uint64)diskinfo.FreeClusters * (kal_uint64)diskinfo.SectorsPerCluster * (kal_uint64)diskinfo.BytesPerSector;
      
    }
    if (used_bytes)
    {
        *used_bytes = 0;
        kal_wsprintf(wpath, "%c:\\@mms", (char)drive_letter);
        folder_size = FS_GetFolderSize(wpath, FS_COUNT_IN_BYTE, NULL, 0);
        if (folder_size >= 0)
        {
            *used_bytes = (kal_uint32) folder_size;
        }
    }
#endif /* defined(__FS_QM_SUPPORT__) && !defined(MMS_IN_LARGE_STORAGE) */
    }
    else if (storage == MMA_MSG_STORAGE_CARD1) /* Check if there is need to check for card plug-in ststus*/
    {
        /* No need to check for card presnce as PS API will return error if card is not present and 
        then this API will return 0 in that case*/
        kal_wsprintf(wpath, "%c:\\", (char)SRV_FMGR_CARD_DRV);
        if (FS_GetDiskInfo(wpath, &diskinfo, FS_DI_FREE_SPACE | FS_DI_BASIC_INFO) >= 0)
        {
            freebytes = (kal_uint64)diskinfo.FreeClusters * (kal_uint64)diskinfo.SectorsPerCluster * (kal_uint64)diskinfo.BytesPerSector;
        }
        if (used_bytes)
        {
            *used_bytes = 0;
            kal_wsprintf(wpath, "%c:\\@mms", (char)SRV_FMGR_CARD_DRV);
            folder_size = FS_GetFolderSize(wpath, FS_COUNT_IN_BYTE, NULL, 0);
            if (folder_size >= 0)
            {
                *used_bytes = (kal_uint32) folder_size;
            }
        }
    }
    
   
    return (kal_uint64) freebytes;
}


/*****************************************************************************
 * FUNCTION
 *  mma_cvt_um_folder_to_mma_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folder      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mma_folder_enum mma_cvt_um_folder_to_mma_folder(kal_int32 folder)
{
#if defined(__MMI_MMS_IN_UM__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_msg_box_enum um_folder = (srv_um_msg_box_enum) folder;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (um_folder)
    {
        case SRV_UM_MSG_BOX_INBOX:
            return MMA_FOLDER_INBOX;
        case SRV_UM_MSG_BOX_SENT:
            return MMA_FOLDER_SENT;
        case SRV_UM_MSG_BOX_DRAFT:
            return MMA_FOLDER_DRAFT;
        case SRV_UM_MSG_BOX_UNSENT:
            return MMA_FOLDER_OUTBOX;
        case SRV_UM_MSG_BOX_PREDEF_TEMPLATES:
            return MMA_FOLDER_TEMPLATE;
        case SRV_UM_MSG_BOX_USRDEF_TEMPLATES:
            return MMA_FOLDER_USRDEF_TEMPLATE;
    #if defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__)
        case SRV_UM_MSG_BOX_ARCHIVE:
            return MMA_FOLDER_ARCHIVE;
    #endif /* defined(__UNIFIED_MESSAGE_ARCHIVE_SUPPORT__) */
    #if defined(__MMI_MMS_REPORT_BOX_SUPPORT__)
        case SRV_UM_MSG_BOX_REPORT:
            return MMA_FOLDER_REPORT_BOX;
    #endif /* __MMI_MMS_REPORT_BOX_SUPPORT__ */ 
        default:
            ASSERT(0);
    }
#endif /* defined(__MMI_MMS_IN_UM__) */ 
    return MMA_FOLDER_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_cvt_mma_folder_to_um_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folder_id       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_um_msg_box_enum mma_cvt_mma_folder_to_um_folder(mma_folder_enum folder_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (folder_id)
    {
        case MMA_FOLDER_INBOX:
            return SRV_UM_MSG_BOX_INBOX;
        case MMA_FOLDER_OUTBOX:
            return SRV_UM_MSG_BOX_UNSENT;
        case MMA_FOLDER_SENT:
            return SRV_UM_MSG_BOX_SENT;
        case MMA_FOLDER_DRAFT:
            return SRV_UM_MSG_BOX_DRAFT;
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMA_FOLDER_ARCHIVE:
            return SRV_UM_MSG_BOX_ARCHIVE;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
        case MMA_FOLDER_TEMPLATE:
            return SRV_UM_MSG_BOX_PREDEF_TEMPLATES;
        case MMA_FOLDER_USRDEF_TEMPLATE:
            return SRV_UM_MSG_BOX_USRDEF_TEMPLATES;
    #if defined(__MMI_MMS_REPORT_BOX_SUPPORT__)
        case MMA_FOLDER_REPORT_BOX:
            return SRV_UM_MSG_BOX_REPORT;
    #endif /* __MMI_MMS_REPORT_BOX_SUPPORT__ */
        case MMA_FOLDER_ALL:
            return SRV_UM_MSG_BOX_ALL;
    }
    return SRV_UM_MSG_BOX_END;
}


/*****************************************************************************
 * FUNCTION
 *  mma_cvt_mma_folder_to_mms_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folder      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 mma_cvt_mma_folder_to_mms_folder(mma_folder_enum folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_folder_enum mma_folder = (mma_folder_enum) folder;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mma_folder)
    {
        case MMA_FOLDER_INBOX:
            return (kal_int32) MMS_INBOX;
        case MMA_FOLDER_OUTBOX:
            return (kal_int32) MMS_OUTBOX;
        case MMA_FOLDER_DRAFT:
            return (kal_int32) MMS_DRAFTS;
        case MMA_FOLDER_SENT:
            return (kal_int32) MMS_SENT;
        case MMA_FOLDER_TEMPLATE:
            return (kal_int32) MMS_TEMPLATES;
        case MMA_FOLDER_USRDEF_TEMPLATE:
            return (kal_int32) MMS_USRDEF_TEMPLATES;
        case MMA_FOLDER_ARCHIVE:
            return (kal_int32) MMS_ARCHIVE;
        case MMA_FOLDER_ALL:
            return MMS_ALL_FOLDERS;
        default:
            return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_mem_alloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 *  clear       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *mma_mem_alloc(kal_uint32 size, kal_bool clear)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *output_mem_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (clear == FALSE)
    {
        output_mem_p = (void*)MSF_MEM_ALLOC(MSF_MODID_MMA, size);
    }
    else
    {
        output_mem_p = (void*)MSF_MEM_CALLOC(MSF_MODID_MMA, 1, size);
    }
    ASSERT(output_mem_p);
    return output_mem_p;
}


/*****************************************************************************
 * FUNCTION
 *  mma_mem_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mma_mem_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ptr != NULL)
    {
        MSF_MEM_FREE(MSF_MODID_MMA, ptr);
    }
}

void mma_mem_free_ext(void *ptr, void* user_data)
{
    mma_mem_free(ptr);

}
/*****************************************************************************
 * FUNCTION
 *  mma_mem_alloc_ext
 * DESCRIPTION
 *  This function is just a wrapper over mma_mem_alloc();
 * PARAMETERS
 *  size        [IN]        
 *
 * RETURNS
 *  void*
 *****************************************************************************/
void *mma_mem_alloc_ext(kal_uint32 size, void* user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return mma_mem_alloc(size, KAL_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_date_time_string
 * DESCRIPTION
 *  This function is used to create date_time string
 * PARAMETERS
 *  sec                 [IN]            
 *  output_buf          [IN/OUT]        
 *  output_bufsize      [IN]            
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
kal_bool mma_create_date_time_string(kal_uint32 sec, char *output_buf, int output_bufsize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct t = {0};
    int utf8_str_len = 0;
    kal_int8 *buffer = (kal_int8*) MMA_CALLOC(100);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_dt_utc_sec_2_mytime(sec, &t, KAL_FALSE);
    date_string((UI_time*) & t, (unsigned short*)buffer, DT_IDLE_SCREEN);
    app_ucs2_wcscat((kal_wchar*) buffer, L" ");
    time_string(
        (UI_time*) & t,
        (unsigned short*)(buffer + app_ucs2_strlen((const kal_int8*)buffer) * 2),
        DT_IDLE_SCREEN);
    app_ucs2_wcscat((kal_wchar*) buffer, L" GMT");
    utf8_str_len = mmi_charset_ucs2_to_utf8_length_in_bytes((const kal_uint8*)buffer);
    if (utf8_str_len <= 0)
    {
        MMA_FREE(buffer);
        return KAL_FALSE;
    }
    utf8_str_len++;
    if (output_bufsize < utf8_str_len)
    {
        MMA_FREE(buffer);
        return KAL_FALSE;
    }
    mmi_chset_ucs2_to_utf8_string((kal_uint8*) output_buf, (kal_int32) output_bufsize, (kal_uint8*) buffer);
    MMA_FREE(buffer);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_utf8_string
 * DESCRIPTION
 *  This function is used to convert mmi ucs2 string to utf8 string id
 * PARAMETERS
 *  modid                   [IN]            
 *  string_id               [IN]            
 *  output_bufsize(?)       [IN]            
 *  output_buf(?)           [IN/OUT]        
 *  sec(?)                  [IN]            
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
char *mma_get_utf8_string(MSF_UINT8 modid, int string_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int str_len = 0;
    char *str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (get_string((MSF_UINT16) string_id) != NULL)
    {
        str_len = mmi_charset_ucs2_to_utf8_length_in_bytes((const kal_uint8*)get_string((MSF_UINT16) string_id));

        if (str_len <= 1000)
        {
            str_len += 2;
            str = MSF_MEM_ALLOC(modid, str_len);
            if (str != NULL)
            {
                mmi_chset_ucs2_to_utf8_string(
                    (kal_uint8*) str,
                    str_len,
                    (kal_uint8*) get_string((MSF_UINT16) string_id));
                return str;
            }
        }
    }
    return str;
}


/*****************************************************************************
 * FUNCTION
 *  mma_is_busy
 * DESCRIPTION
 *  This function is used to check if mma module is busy
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
int mma_is_busy(kal_uint8 card_enum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mma_msgmgr_is_busy())
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,MMA_UTILITIES_GET_ACTIVE_TASK_MSGMGR, "MMAMgr_BUSY"));
        return TRUE;
    }
    else if (mma_create_is_busy_on_storage(card_enum) != NULL)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,MMA_UTILITIES_GET_ACTIVE_TASK_CREATE, "MMACreate_BUSY"));
        return TRUE;
    }
    else if (mma_parse_is_busy_on_storage(card_enum) != NULL)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA,MMA_UTILITIES_GET_ACTIVE_TASK_PARSE, "MMAParse_BUSY"));
        return TRUE;
    }
    else if (mma_sendrecv_is_busy((mma_msg_storage_type_enum)card_enum))
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_UTILITIES_GET_ACTIVE_TASK_SENDRECV,
                           "MMASndRcv_BUSY"));
        return TRUE;
    }
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
    else if (mma_drmsrv_is_busy_on_storage(card_enum) != NULL)
    {
        MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_UTILITIES_GET_ACTIVE_TASK_DRMSRV, "MMADrmsrv_BUSY"));
        return TRUE;
    }
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_is_ready_for_usb
 * DESCRIPTION
 *  This function is used to check if MMA is ready for USB mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
int mma_is_ready_for_usb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mms_task_is_ready() && 
            !mma_is_busy(MMA_MSG_STORAGE_PHONE) 
            #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            && !mma_is_busy(MMA_MSG_STORAGE_CARD1)
            #endif
            );
}


/*****************************************************************************
 * FUNCTION
 *  mma_is_ready_for_format
 * DESCRIPTION
 *  This function is used to check if MMA is ready for format operation.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
kal_bool mma_is_ready_for_format(kal_uint8 fmt_drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_UTILITIES_IS_READY_FOR_FORMAT, "(mma_utilities.c)mma_is_ready_for_format: drive %c", fmt_drv));
    
    if (mms_task_is_init())
    {
        return KAL_FALSE;
    }
    else    
    {
        kal_uint8 drv_enum = MMA_MSG_STORAGE_NONE;
#ifdef MMS_IN_LARGE_STORAGE
        if (fmt_drv == SRV_FMGR_PUBLIC_DRV)
        { 
            drv_enum = MMA_MSG_STORAGE_PHONE;
            
        }
        else
#endif
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (fmt_drv == SRV_FMGR_CARD_DRV)
        {
            /*For Memory card*/
            drv_enum = MMA_MSG_STORAGE_CARD1;
            
        }
        else
#endif   /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__*/
        {
			MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_UTILITIES_IS_READY_FOR_FORMAT_RESULT, "((mma_utilities.c)mma_is_ready_for_format_Result: @ %d", 1));            
            return (kal_bool)!mms_task_is_init();
        }
        
        
        if (mms_task_is_ready())
        {
            MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_UTILITIES_IS_READY_FOR_FORMAT_RESULT, "((mma_utilities.c)mma_is_ready_for_format_Result: @ %d", 2));
            if (mma_is_ready())
            {
				MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_UTILITIES_IS_READY_FOR_FORMAT_RESULT, "((mma_utilities.c)mma_is_ready_for_format_Result: @ %d", 3));
                
                if (!mma_is_busy(drv_enum))
                {
                    /* We will not send MMS push to MMS service. Bcoz the storage is formated. */
					MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_UTILITIES_IS_READY_FOR_FORMAT_RESULT, "((mma_utilities.c)mma_is_ready_for_format_Result: @ %d", 4));
                    mma_main_enter_terminate_mode();
                    return KAL_TRUE;
                }
                return KAL_FALSE;
            }
            return KAL_TRUE;
        }
        return KAL_TRUE;
    }
}

#ifdef __USB_IN_NORMAL_MODE__


/*****************************************************************************
 * FUNCTION
 *  mma_is_storage_exported_to_pc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mma_is_storage_exported_to_pc()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar mms_folder_path[10] = {0};
    int drv_letter = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMS_IN_LARGE_STORAGE
    /* Order: 1. Invisible NAND 2. Visible NAND 3. visible NOR 4. Invisible NOR */
    drv_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_I_SYSTEM);
#else /* MMS_IN_LARGE_STORAGE */ 
    drv_letter = FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_NO_ALT_DRIVE);
#endif /* MMS_IN_LARGE_STORAGE */ 
    kal_wsprintf(mms_folder_path, "%c", drv_letter);
    kal_wstrcat(mms_folder_path, L"\\");

    if (srv_usb_check_path_exported((WCHAR*)mms_folder_path) == MMI_FALSE)
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }

}
#endif /* __USB_IN_NORMAL_MODE__ */ 


/*****************************************************************************
 * FUNCTION
 *  mms_task_is_ready
 * DESCRIPTION
 *  The function is used to check if mms task is ready (MMS module is ready).
 * PARAMETERS
 *  void
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int mms_task_is_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mms_msf_mod_is_ready();
}


/*****************************************************************************
 * FUNCTION
 *  mms_task_is_init
 * DESCRIPTION
 *  The function is used to check if mms task is in initialization state.
 * PARAMETERS
 *  void
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int mms_task_is_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mms_msf_mod_is_init();
}


/*****************************************************************************
 * FUNCTION
 *  mma_msf_file_open_in_blocking_mode
 * DESCRIPTION
 *  The function is used to open file in blocking mode.
 * PARAMETERS
 *  modID
 *  fileName
 *  mode
 *  size
 * RETURNS
 *  int
 *****************************************************************************/
int mma_msf_file_open_in_blocking_mode(MSF_UINT8 modId, const char *fileName, int mode, long size, mma_msg_storage_type_enum storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	return (MSF_FILE_OPEN_EXT(modId, fileName, mode | HDI_FILE_SET_CUSTOM_BLOCKING, size, translate_mma_storage_to_mms_storage_enum(storage_type)));
}


/*****************************************************************************
 * FUNCTION
 *  translate_mms_sim_to_mma_sim
 * DESCRIPTION
 *  This function is used to convert MMS SIM ENUM value to MMS ENUM SIN value
 * CALLS
 *  
 * PARAMETERS
 *  version     [IN]        
 *  prio(?)
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 translate_mms_sim_to_mma_sim(kal_uint32 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {
	    case MMS_SIM_CARD_SIM1:
            return MMA_SIM_ID_SIM1;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMS_SIM_CARD_SIM2:
            return MMA_SIM_ID_SIM2;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMS_SIM_CARD_SIM3:
            return MMA_SIM_ID_SIM3;
    #if (MMI_MAX_SIM_NUM >= 4)
        case MMS_SIM_CARD_SIM4:
            return MMA_SIM_ID_SIM4;
    #endif /*(MMI_MAX_SIM_NUM >= 4)*/
    #endif /*(MMI_MAX_SIM_NUM >= 3)*/
    #endif /*MMI_MAX_SIM_NUM*/
        default:
            return MMA_SIM_ID_SIM1;
    }
}

/*****************************************************************************
 * FUNCTION
 *  translate_mma_sim_to_mms_sim
 * DESCRIPTION
 *  This function is used to convert MMS SIM ENUM value to MMS ENUM SIN value
 * CALLS
 *  
 * PARAMETERS
 *  version     [IN]        
 *  prio(?)
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 translate_mma_sim_to_mms_sim(kal_uint32 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    { 
	    case MMA_SIM_ID_SIM1:
            return MMS_SIM_CARD_SIM1;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMA_SIM_ID_SIM2:
            return MMS_SIM_CARD_SIM2;
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMA_SIM_ID_SIM3:
            return MMS_SIM_CARD_SIM3;
    #if (MMI_MAX_SIM_NUM >= 4)
       case MMA_SIM_ID_SIM4:
            return MMS_SIM_CARD_SIM4;
    #endif /*(MMI_MAX_SIM_NUM >= 4)*/
    #endif /*(MMI_MAX_SIM_NUM >= 3)*/
    #endif /*MMI_MAX_SIM_NUM*/
        default:
            return MMS_SIM_CARD_SIM1;
    }
}
/*****************************************************************************
 * FUNCTION
 *  mms_get_file_extension
 * DESCRIPTION
 *  This function is to get the file extension
 * 
 * PARAMETERS
 *  file_path     [IN]        
 *  
 * RETURNS
 *  
 *****************************************************************************/

kal_wchar *mms_get_file_extension(kal_wchar *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 length, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = kal_wstrlen(file_path);

    /* search from tail until "." */
    for (i = length - 1; i >= 0; i--)
    {
        if (file_path[i] == '.')
        {
            return &file_path[i + 1];
        }
    }
    
    return NULL;
}

msf_mms_storage_enum translate_mma_storage_to_mms_storage_enum(mma_msg_storage_type_enum storage)
{
    switch(storage)
    {
        case MMA_MSG_STORAGE_NONE:
            return MSF_MMS_STORAGE_NONE;

        case MMA_MSG_STORAGE_PHONE:
            return MSF_MMS_STORAGE_PHONE;

        case MMA_MSG_STORAGE_CARD1:
            return MSF_MMS_STORAGE_MEM_CARD_1;

        default:
            ASSERT(0);
    }
    return MSF_MMS_STORAGE_PHONE;
}

mma_msg_storage_type_enum translate_mms_storage_to_mma_storage_enum(msf_mms_storage_enum storage)
{
    switch(storage)
    {
        case MSF_MMS_STORAGE_NONE:
            return MMA_MSG_STORAGE_NONE;

        case MSF_MMS_STORAGE_PHONE:
            return MMA_MSG_STORAGE_PHONE;

        case MSF_MMS_STORAGE_MEM_CARD_1:
            return MMA_MSG_STORAGE_CARD1;

        default:
            ASSERT(0);
    }
    return MMA_MSG_STORAGE_PHONE;
}

/*****************************************************************************
 * FUNCTION
 *  translate_mms_rr_status_to_mma_status
 * DESCRIPTION
 *  This function is used to convert MMS READ Report status to MMA ENUM status  
 * PARAMETERS
 *  status     [IN]
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 translate_mms_rr_status_to_mma_status(kal_uint16 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (status)
    {    
	    case MMS_READ_STATUS_READ:
            return MMA_RR_STATUS_READ;
        case MMS_READ_STATUS_DELETED_WITHOUT_BEING_READ:
            return MMA_RR_STATUS_DELETED_NO_READ;
        default:
            return MMA_RR_STATUS_READ;
    }
}

/*****************************************************************************
 * FUNCTION
 *  translate_mms_dr_status_to_mma_status
 * DESCRIPTION
 *  This function is used to convert MMS READ Report status to MMA ENUM status  
 * PARAMETERS
 *  status     [IN]
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 translate_mms_dr_status_to_mma_status(kal_uint16 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (status)
    {    
	    case MMS_STATUS_EXPIRED:
            return MMA_DR_STATUS_EXPIRED;
        case MMS_STATUS_RETRIEVED:
            return MMA_DR_STATUS_RETRIEVED;
        case MMS_STATUS_REJECTED:
            return MMA_DR_STATUS_REJECTED;
        case MMS_STATUS_DEFERRED:
            return MMA_DR_STATUS_DEFERRED;
        case MMS_STATUS_UNRECOGNIZED:
            return MMA_DR_STATUS_UNRECOGNISED;
        case MMS_STATUS_INDETERMINATE:
            return MMA_DR_STATUS_INDETERMINATE;
        case MMS_STATUS_FORWARDED:
            return MMA_DR_STATUS_FORWARDED;
        default:
            return MMA_DR_STATUS_UNREACHABLE;
    }
}

#endif /* defined(MMS_SUPPORT) */ 
#endif /* _MMA_UTILITIES_C */ 

