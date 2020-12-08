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
 *  SmsArchiveSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Archive handler
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MOD_SMSAL__
#ifdef __SRV_SMS_ARCHIVE__
/**************************************************************
* Header Files Include
**************************************************************/
#include "kal_general_types.h"
#include "kal_trace.h"
#include "MMIDataType.h"
#include "DebugInitDef_Int.h"
#include "fs_errcode.h"
#include "fs_type.h"
#include "fs_func.h"
#include "string.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "app_datetime.h"
#include "DateTimeType.h"

#include "mmi_common_app_trc.h"
#include "SmsSrvGProt.h"
#include "SmsArchiveSrv.h"
#include "SmsConverterSrv.h"
#include "ems.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGprot.h"
#endif /* __MMI_USB_SUPPORT__ */
#include "FileMgrSrvGProt.h"


/**************************************************************
* MARCO
**************************************************************/
#define SRV_SMS_ARCHIVE_GUARD_PATTERN           "F2F2"
#define SRV_SMS_ARCHIVE_GUARD_PATTERN_LEN       4

/* Before read/write arch file, need to "%s%lx.a", SMSARCH_FOLDER, fileid */
#define SRV_SMS_ARCH_PUB_PATH               "\\SMSArch\\"
/* to store idx file in system drive */
#define SRV_SMS_ARCH_SYS_PATH               "\\@SMSArch\\"
/* File Path Format: [Drive Name][SRV_SMS_ARCH_PUB_PATH \ SRV_SMS_ARCH_SYS_PATH][File name]
 * For example: "C:\\@SMSArch\\001.a" */
#define SRV_SMS_MAX_ARCH_PATH_LEN           (5 + 18 + 6)
#define SRV_SMS_MAX_ARCH_BUF_SIZE           (100+ SRV_SMS_MAX_SEG *160 * ENCODING_LENGTH)


/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    U16 file_size;
    S8 number[SRV_SMS_MAX_ADDR_LEN + 1];
    U32 timestamp;
    srv_sms_status_enum status; 
    MMI_BOOL is_complete;
#ifdef __SRV_SMS_MULTI_SIM__
    srv_sms_sim_enum sim_id;
#endif /* __SRV_SMS_MULTI_SIM__ */
#ifdef __SRV_SMS_MSG_INFO_CONTENT__
    U16 content[SRV_SMS_MSG_INFO_CONTENT_LEN + 1];
#endif /* __SRV_SMS_MSG_INFO_CONTENT__ */
    U8 guardPattern[4];
} srv_sms_archive_entry_struct;


/**************************************************************
* Global Variables Declaration
**************************************************************/ 


/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static srv_sms_archive_entry_struct srv_sms_archive_msg_list[SRV_SMS_MAX_ARCH_ENTRY];  
static S32 archive_fs_error;

/**************************************************************
* Static Function Declaration
**************************************************************/
static MMI_BOOL srv_sms_archive_check_folder(void);
static MMI_BOOL srv_sms_archive_init_msg_list(void);
static MMI_BOOL srv_sms_archive_check_guard_pattern(void);
static MMI_BOOL srv_sms_archive_check_entry(void);

static void srv_sms_archive_reset_msg_list(void);

static void srv_sms_archive_get_entry(U16 entry_id, srv_sms_archive_entry_struct *entry_node);
static MMI_BOOL srv_sms_archive_add_entry(U16 entry_id, srv_sms_archive_entry_struct *entry_node);
static MMI_BOOL srv_sms_archive_delete_entry(U16 entry_id);
static void srv_sms_archive_memset_entry(srv_sms_archive_entry_struct *entry_node);
static U16 srv_sms_archive_find_unused_entry(void);

static MMI_BOOL srv_sms_archive_update_entry_to_file(
                    U16 entry_id,
                    srv_sms_archive_entry_struct *entry_node);
static MMI_BOOL srv_sms_archive_update_index_file(void);

static MMI_BOOL srv_sms_archive_delete_content_file(U16 entry_id);
static MMI_BOOL srv_sms_archive_delete_all_content_file(void);

static MMI_BOOL srv_sms_archive_create_folder(char *ucs2_file_name);
static MMI_BOOL srv_sms_archive_delete_file(char *ucs2_file_name);

static void srv_sms_archive_get_folder_name(char* ucs2_buff, MMI_BOOL flag);

static void srv_sms_archive_get_index_file_name(char* ucs2_buff);
static void srv_sms_archive_get_content_file_name(char* ucs2_buff, U16 entry_id);

static void srv_sms_archive_entry_to_msg_info(
                srv_sms_msg_info_struct *msg_info,
                srv_sms_archive_entry_struct *entry_node);
static void srv_sms_archive_msg_info_to_entry(
                srv_sms_archive_entry_struct *entry_node,
                srv_sms_msg_info_struct *msg_info);


/**************************************************************
* Function Defination
**************************************************************/

#ifdef __SRV_SMS_ARCHIVE__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_fmgr_format_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_sms_fmgr_format_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_fmgr_notification_format_event_struct *event_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_data = (srv_fmgr_notification_format_event_struct*)evt;

    if((event_data->state == SRV_FMGR_NOTIFICATION_STATE_AFTER) &&
       ((event_data->drv_letter == 'C') || (event_data->drv_letter == 'D')))
    {
        srv_sms_format_archive();
    }

	return MMI_RET_OK;
}
#endif /* __SRV_SMS_ARCHIVE__ */
/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_archive_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_INIT);

    if ((srv_sms_archive_check_folder() == MMI_TRUE) &&
        (srv_sms_archive_init_msg_list() == MMI_TRUE))
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_INIT_1, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_read_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_cause_enum srv_sms_archive_read_msg(
                    U16 entry_id,
                    MMI_BOOL change_status,
                    EMSData* ems_data,
                    srv_sms_msg_info_struct* msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_READ_MSG, entry_id, change_status);

#ifdef __MMI_USB_SUPPORT__
    if (srv_usb_is_in_mass_storage_mode())
    {
        error_cause = SRV_SMS_CAUSE_IN_USB_MODE;
    }
    else
#endif /* __MMI_USB_SUPPORT__ */
    {
        if (srv_sms_archive_is_msg_exist(entry_id) == MMI_TRUE)
        {
            srv_sms_archive_entry_struct *entry_node;
            S8 ucs2_folder_path[SRV_SMS_MAX_ARCH_PATH_LEN * ENCODING_LENGTH];
            S32 read_result;

            archive_fs_error = FS_NO_ERROR;

            entry_node = &srv_sms_archive_msg_list[entry_id];

            srv_sms_archive_get_content_file_name(ucs2_folder_path, entry_id);

            read_result = srv_sms_read_ems_data_from_file(
                            ems_data,
                            ucs2_folder_path,
                            &archive_fs_error);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_READ_MSG_1, entry_node->file_size);

            if (read_result == entry_node->file_size)
            {
                entry_node = &srv_sms_archive_msg_list[entry_id];

                if ((change_status == MMI_TRUE) &&
                    (entry_node->status == SRV_SMS_STATUS_UNREAD))
                {
                    entry_node->status = SRV_SMS_STATUS_READ;

                    srv_sms_archive_update_entry_to_file(entry_id, entry_node);
                }

                if (msg_info != NULL)
                {
                    srv_sms_archive_entry_to_msg_info(msg_info, entry_node);            
                }

                if (archive_fs_error < FS_NO_ERROR)
                {
                    error_cause = SRV_SMS_CAUSE_FS_ERROR;
                }
            }
            else
            {
                if (archive_fs_error < FS_NO_ERROR)
                {
                    if ((archive_fs_error == FS_PATH_NOT_FOUND) ||
                        (archive_fs_error == FS_FILE_NOT_FOUND))
                    {
                        error_cause = SRV_SMS_CAUSE_ARCH_FILE_NOT_EXIST;
                    }
                    else
                    {
                        error_cause = SRV_SMS_CAUSE_FS_ERROR;
                    }
                }
                else
                {
                    error_cause = SRV_SMS_CAUSE_DATA_INVALID;
                }
            }
        }
        else
        {
            error_cause = SRV_SMS_CAUSE_DATA_INVALID;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_READ_MSG_2, error_cause);

    return error_cause;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_save_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_cause_enum srv_sms_archive_save_msg(
                    U16* dest_entry_id,
                    EMSData* ems_data,
                    srv_sms_msg_info_struct* msg_info,
                    MMI_BOOL is_complete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    U16 unused_entry_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_SAVE_MSG, is_complete);

#ifdef __MMI_USB_SUPPORT__
    if (srv_usb_is_in_mass_storage_mode())
    {
        error_cause = SRV_SMS_CAUSE_IN_USB_MODE;
    }
    else
#endif /* __MMI_USB_SUPPORT__ */
    {
        unused_entry_id = srv_sms_archive_find_unused_entry();

        if (unused_entry_id != SRV_SMS_ARCHIVE_INVALID_ENTRY_ID)
        {
            S8 content_file_name[SRV_SMS_MAX_ARCH_PATH_LEN * ENCODING_LENGTH];
            S32 write_result;

            archive_fs_error = FS_NO_ERROR;

            srv_sms_archive_get_content_file_name(content_file_name, unused_entry_id);

            write_result = srv_sms_write_ems_data_to_file(
                            content_file_name,
                            ems_data,
                            &archive_fs_error);

            /* If the Folder is deleted, create it */
            if (archive_fs_error == FS_PATH_NOT_FOUND)
            {
                S8 pub_folder_path[SRV_SMS_MAX_ARCH_PATH_LEN * ENCODING_LENGTH];

                srv_sms_archive_get_folder_name(pub_folder_path, MMI_FALSE);

                srv_sms_archive_create_folder(pub_folder_path);

                archive_fs_error = FS_NO_ERROR;

                write_result = srv_sms_write_ems_data_to_file(
                                content_file_name,
                                ems_data,
                                &archive_fs_error);
            }

            if (write_result >= 0)
            {
                srv_sms_archive_entry_struct entry_node;

                srv_sms_archive_msg_info_to_entry(&entry_node, msg_info);
                entry_node.file_size = (U16)write_result;
                entry_node.is_complete = is_complete;

                if (srv_sms_archive_add_entry(unused_entry_id, &entry_node) == MMI_TRUE)
                {
                    *dest_entry_id = unused_entry_id;
                    FS_SetAttributes((const WCHAR*)content_file_name, FS_ATTR_HIDDEN);
                }
                else
                {
                    FS_Delete((const WCHAR*)content_file_name);
                }
            }

            if (archive_fs_error < FS_NO_ERROR)
            {
                error_cause = SRV_SMS_CAUSE_FS_ERROR;
            }
        }
        else
        {
            error_cause = SRV_SMS_CAUSE_MEM_FULL;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_SAVE_MSG_1, error_cause);

    return error_cause;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_delete_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_cause_enum srv_sms_archive_delete_msg(U16 entry_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_DELETE_MSG, entry_id);

#ifdef __MMI_USB_SUPPORT__
    if (srv_usb_is_in_mass_storage_mode())
    {
        error_cause = SRV_SMS_CAUSE_IN_USB_MODE;
    }
    else
#endif /* __MMI_USB_SUPPORT__ */
    {
        if (srv_sms_archive_is_msg_exist(entry_id) == MMI_TRUE)
        {
            srv_sms_archive_entry_struct entry_node;

            archive_fs_error = FS_NO_ERROR;

            srv_sms_archive_get_entry(entry_id, &entry_node);

            if (srv_sms_archive_delete_entry(entry_id) == MMI_TRUE)
            {
                if (srv_sms_archive_delete_content_file(entry_id) == MMI_FALSE)
                {
                    /* If deleted content failed, restored the entry index.
                     * If restored failed, because the index of this entry is not existed,
                     *  we will considder this message is deleted */
                    if (srv_sms_archive_add_entry(entry_id, &entry_node) == MMI_TRUE)
                    {
                        error_cause = SRV_SMS_CAUSE_FS_ERROR;
                    }
                }
            }
            else
            {
                error_cause = SRV_SMS_CAUSE_FS_ERROR;
            }
        }
        else
        {
            error_cause = SRV_SMS_CAUSE_INVALID_MEM_INDEX;
        }
    }
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_DELETE_MSG_1, error_cause);

    return error_cause;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_change_status
 * DESCRIPTION
 *  change archive msg status
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_cause_enum srv_sms_archive_change_msg_status(U16 entry_id, srv_sms_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_CHANGE_MSG_STATUS, entry_id, status);

    if (srv_sms_archive_is_msg_exist(entry_id) == MMI_TRUE)
    {
        srv_sms_archive_entry_struct *entry_node;

        entry_node = &srv_sms_archive_msg_list[entry_id];

        if (entry_node->status != status)
        {
            srv_sms_mti_enum mti;
            srv_sms_mti_enum msg_mti;

            mti = srv_sms_status_to_mti(status);
            msg_mti = srv_sms_status_to_mti(entry_node->status);

            if (mti != msg_mti)
            {
                error_cause = SRV_SMS_CAUSE_OP_NOT_ALLOWED;
            }
            else
            {
                srv_sms_status_enum original_status;

                archive_fs_error = FS_NO_ERROR;

                original_status = entry_node->status;

                entry_node->status = status;

                if (srv_sms_archive_update_entry_to_file(entry_id, entry_node) == MMI_FALSE)
                {
                    entry_node->status = original_status;
                }

                if (archive_fs_error < FS_NO_ERROR)
                {
                    error_cause = SRV_SMS_CAUSE_FS_ERROR;
                }
            }
        }
    }
    else
    {
        error_cause = SRV_SMS_CAUSE_DATA_INVALID;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_CHANGE_MSG_STATUS_1, error_cause);

    return error_cause;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_read_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_sms_archive_get_fs_error(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return archive_fs_error;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_get_msg_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_archive_get_msg_info(U16 entry_id, srv_sms_msg_info_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_GET_MSG_INFO, entry_id);

    if (srv_sms_archive_is_msg_exist(entry_id))
    {
        srv_sms_archive_entry_to_msg_info(msg_info, &srv_sms_archive_msg_list[entry_id]);
    }
    else
    {
        memset(msg_info, 0, sizeof(srv_sms_msg_info_struct));
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_get_msg_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
const char* srv_sms_archive_get_msg_address(U16 entry_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *address;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_archive_is_msg_exist(entry_id) == MMI_TRUE)
    {
        address = (S8*)srv_sms_archive_msg_list[entry_id].number;
    }
    else
    {
        address = NULL;
    }

    return address;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_get_msg_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
const char* srv_sms_archive_get_msg_content(U16 entry_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *content;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MSG_INFO_CONTENT__
    if (srv_sms_archive_is_msg_exist(entry_id) == MMI_TRUE)
    {
        content = (S8*)srv_sms_archive_msg_list[entry_id].content;
    }    
    else
    {
        content = NULL;
    }
#else /* __SRV_SMS_MSG_INFO_CONTENT__ */
    content = NULL;
#endif /* __SRV_SMS_MSG_INFO_CONTENT__ */

    return content;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_get_msg_timestamp_utc_sec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_sms_archive_get_msg_timestamp_utc_sec(U16 entry_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 int_timestamp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_archive_is_msg_exist(entry_id) == MMI_TRUE)
    {
        int_timestamp = srv_sms_archive_msg_list[entry_id].timestamp;
    }
    else
    {
        int_timestamp = 0;
    }

    return int_timestamp;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_get_msg_pid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_pid_enum srv_sms_archive_get_msg_pid(U16 entry_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SRV_SMS_PID_DEFAULT;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_get_msg_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_status_enum srv_sms_archive_get_msg_status(U16 entry_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_archive_is_msg_exist(entry_id) == MMI_TRUE)
    {
        status = srv_sms_archive_msg_list[entry_id].status;
    }
    else
    {
        status = SRV_SMS_STATUS_NONE;
    }

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_get_msg_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_sim_enum srv_sms_archive_get_msg_sim_id(U16 entry_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MULTI_SIM__
    if (srv_sms_archive_is_msg_exist(entry_id) == MMI_TRUE)
    {
        sim_id = srv_sms_archive_msg_list[entry_id].sim_id;
    }
    else
    {
        sim_id = SRV_SMS_SIM_1;
    }
#else /* __SRV_SMS_MULTI_SIM__ */
    sim_id = SRV_SMS_SIM_1;
#endif /* __SRV_SMS_MULTI_SIM__ */

    return sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_get_msg_storage_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_storage_enum srv_sms_archive_get_msg_storage_type(U16 entry_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_storage_enum storage_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_archive_is_msg_exist(entry_id) == MMI_TRUE)
    {
        storage_type = SRV_SMS_STORAGE_ME;
    }
    else
    {
        storage_type = SRV_SMS_STORAGE_UNSPECIFIC;
    }

    return storage_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_get_complete_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_archive_get_complete_flag(U16 entry_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_archive_is_msg_exist(entry_id) == MMI_TRUE)
    {
        result = (MMI_BOOL)srv_sms_archive_msg_list[entry_id].is_complete;
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_get_msg_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_archive_get_msg_size(U16 entry_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_archive_is_msg_exist(entry_id) == MMI_TRUE)
    {
        msg_size = srv_sms_archive_msg_list[entry_id].file_size;
    }
    else
    {
        msg_size = 0;
    }

    return msg_size;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_is_msg_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_archive_is_msg_exist(U16 entry_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (entry_id < SRV_SMS_MAX_ARCH_ENTRY)
    {
        U16 file_size = srv_sms_archive_msg_list[entry_id].file_size;

        if (file_size > 0)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_is_msg_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_archive_is_msg_valid(U16 entry_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 file_size = srv_sms_archive_msg_list[entry_id].file_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (file_size > 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_check_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_archive_check_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    S8 sys_folder_path[SRV_SMS_MAX_ARCH_PATH_LEN * ENCODING_LENGTH];
    S8 pub_folder_path[SRV_SMS_MAX_ARCH_PATH_LEN * ENCODING_LENGTH];
    FS_HANDLE sys_file_handle;
    FS_HANDLE pub_file_handle;
    MMI_BOOL syc_result;
    MMI_BOOL pub_result;    
    S32 fs_error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_CHECK_FOLDER);

    srv_sms_archive_get_folder_name(sys_folder_path, MMI_TRUE);
    srv_sms_archive_get_folder_name(pub_folder_path, MMI_FALSE);

    /* Check Whether the Folder is existed */
    sys_file_handle = FS_Open((WCHAR*)sys_folder_path, FS_OPEN_DIR | FS_READ_ONLY);
    pub_file_handle = FS_Open((WCHAR*)pub_folder_path, FS_OPEN_DIR | FS_READ_ONLY);
    FS_Close(sys_file_handle);
    FS_Close(pub_file_handle);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_CHECK_FOLDER_1, sys_file_handle, pub_file_handle);

    /* Clear the file in the existed folder, if it is only existed one folder */
    if ((sys_file_handle >= 0) && (pub_file_handle < 0))
    {
        fs_error = FS_XDelete((WCHAR*)sys_folder_path, FS_FILE_TYPE, NULL, 0);
    }
    else if ((sys_file_handle < 0) && (pub_file_handle >= 0))
    {
        fs_error = FS_XDelete((WCHAR*)pub_folder_path, FS_FILE_TYPE, NULL, 0);
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_CHECK_FOLDER_2, fs_error);

    if (sys_file_handle < 0)
    {
        syc_result = srv_sms_archive_create_folder(sys_folder_path); 
    }
    else
    {
        syc_result = MMI_TRUE;
    }

    if (pub_file_handle < 0)
    {
        pub_result = srv_sms_archive_create_folder(pub_folder_path); 
    }
    else
    {
        pub_result = MMI_TRUE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_CHECK_FOLDER_3, syc_result, pub_result);

    if ((syc_result == MMI_TRUE) && (pub_result == MMI_TRUE))
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_init_msg_list
 * DESCRIPTION
 *  Init archive msg list
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE/FASLE : init ok or fail
 *****************************************************************************/
static MMI_BOOL srv_sms_archive_init_msg_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    MMI_BOOL is_need_reset = MMI_FALSE;
    FS_HANDLE file_handle;
    S32 fs_error;
    S8 ucs2_filename[SRV_SMS_MAX_ARCH_PATH_LEN * ENCODING_LENGTH];
    U32 read_size = 0;
    U32 write_size = 0;
    U32 max_file_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    max_file_size = sizeof(srv_sms_archive_entry_struct) * SRV_SMS_MAX_ARCH_ENTRY;

    srv_sms_archive_get_index_file_name(ucs2_filename);

    file_handle = FS_Open((WCHAR*)ucs2_filename, FS_READ_WRITE);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_INIT_MSG_LIST, file_handle);

    if (file_handle < 0)
    {
        if (file_handle == FS_FILE_NOT_FOUND)
        {
            is_need_reset = MMI_TRUE;
        }
        else
        {
            result = MMI_FALSE;
        }
    }
    else
    {
        fs_error = FS_Read(
                        file_handle,
                        srv_sms_archive_msg_list,
                        max_file_size,
                        &read_size);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_INIT_MSG_LIST_1, fs_error);

        /* The structure or the number of archive is changed */
        if ((fs_error < FS_NO_ERROR ) || (read_size != max_file_size))
        {
            is_need_reset = MMI_TRUE;
        }
    }

    FS_Close(file_handle);

    if (is_need_reset == MMI_TRUE)
    {
        file_handle = FS_Open((WCHAR*)ucs2_filename, FS_CREATE_ALWAYS | FS_READ_WRITE | FS_ATTR_HIDDEN);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_INIT_MSG_LIST_2, file_handle);

        if (file_handle >= 0)
        {
            srv_sms_archive_reset_msg_list();

            fs_error = FS_Write(
                            file_handle,
                            srv_sms_archive_msg_list,
                            max_file_size,
                            &write_size);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_INIT_MSG_LIST_3, fs_error);

            srv_sms_archive_delete_all_content_file();
        }
        else
        {
            result = MMI_FALSE;
        }

        FS_Close(file_handle);
    }
    else
    {
        if (result == MMI_TRUE)
        {
            if (srv_sms_archive_check_guard_pattern() == MMI_FALSE)
            {
                srv_sms_archive_reset_all_msg();
            }
            else
            {
                if (srv_sms_archive_check_entry() == MMI_FALSE)
                {
                    srv_sms_archive_update_index_file();
                }
            }
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_INIT_MSG_LIST_4, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_check_guard_pattern
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL srv_sms_archive_check_guard_pattern(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL check_result = MMI_TRUE;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_CHECK_GUARD_PATTERN);

    for (i = 0; i < SRV_SMS_MAX_ARCH_ENTRY; i++)
    {
        if (memcmp(srv_sms_archive_msg_list[i].guardPattern,
                SRV_SMS_ARCHIVE_GUARD_PATTERN, SRV_SMS_ARCHIVE_GUARD_PATTERN_LEN) != 0)
        {
            check_result = MMI_FALSE;
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_CHECK_GUARD_PATTERN_1, check_result, i);

    return check_result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_check_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_archive_check_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    srv_sms_archive_entry_struct *entry_node;
    FS_HANDLE file_handle;
    S8 ucs2_filename[SRV_SMS_MAX_ARCH_PATH_LEN * ENCODING_LENGTH];
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_CHECK_ENTRY);

    for (i = 0; i < SRV_SMS_MAX_ARCH_ENTRY; i++)
    {
        entry_node = &srv_sms_archive_msg_list[i];

        if (entry_node->file_size > 0)
        {
            srv_sms_archive_get_content_file_name(ucs2_filename, i);

            file_handle = FS_Open((const WCHAR*)ucs2_filename, FS_READ_ONLY);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_CHECK_ENTRY_1, file_handle);

            FS_Close(file_handle);
            
            if (file_handle < 0)
            {
                srv_sms_archive_memset_entry(entry_node);
                srv_sms_archive_delete_file(ucs2_filename);
                result = MMI_FALSE;
            }
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_reset_all_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_archive_reset_all_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_RESET_ALL_MSG);

    srv_sms_archive_reset_msg_list();

    if ((srv_sms_archive_update_index_file() == MMI_TRUE) &&
        (srv_sms_archive_delete_all_content_file() == MMI_TRUE))
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_get_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_archive_get_entry(U16 entry_id, srv_sms_archive_entry_struct *entry_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(
        entry_node,
        &srv_sms_archive_msg_list[entry_id],
        sizeof(srv_sms_archive_entry_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_add_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_archive_add_entry(U16 entry_id, srv_sms_archive_entry_struct *entry_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_ADD_ENTRY, entry_id);

    if (srv_sms_archive_update_entry_to_file(entry_id, entry_node) == MMI_TRUE)
    {
        memcpy(
            &srv_sms_archive_msg_list[entry_id],
            entry_node,
            sizeof(srv_sms_archive_entry_struct));
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_delete_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_archive_delete_entry(U16 entry_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    srv_sms_archive_entry_struct entry_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_DELETE_ENTRY, entry_id);

    srv_sms_archive_memset_entry(&entry_node);

    if (srv_sms_archive_update_entry_to_file(entry_id, &entry_node) == MMI_TRUE)
    {
        srv_sms_archive_memset_entry(&srv_sms_archive_msg_list[entry_id]);
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_memset_entry
 * DESCRIPTION
 *  memset archive index entry (srv_sms_archive_msg_list[])
 *  guardPattern field will be reset to F2F2F2F2 and other fileds will be 0
 * PARAMETERS
 *  entry_ptr       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_archive_memset_entry(srv_sms_archive_entry_struct *entry_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_MEMSET_ENTRY);

    memset(entry_node, 0, sizeof(srv_sms_archive_entry_struct));
    memcpy(entry_node->guardPattern, SRV_SMS_ARCHIVE_GUARD_PATTERN, SRV_SMS_ARCHIVE_GUARD_PATTERN_LEN);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_find_unused_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_sms_archive_find_unused_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 unused_entry_id = SRV_SMS_ARCHIVE_INVALID_ENTRY_ID;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_FIND_UNUSED_ENTRY);

    for (i = 0; i < SRV_SMS_MAX_ARCH_ENTRY; i++)
    {
        if (srv_sms_archive_msg_list[i].file_size == 0)
        {
            unused_entry_id = i;
            break;
        }
    }

    return unused_entry_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_reset_msg_list
 * DESCRIPTION
 *  memset archive index list (srv_sms_archive_msg_list[])
 *  guardPattern field will be reset to F2F2F2F2 and other fileds will be 0
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_archive_reset_msg_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_RESET_MSG_LIST);

    for (i = 0; i < SRV_SMS_MAX_ARCH_ENTRY; i++)
    {
        srv_sms_archive_memset_entry(&srv_sms_archive_msg_list[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_write_index_to_file
 * DESCRIPTION
 * 
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_archive_update_entry_to_file(
                    U16 entry_id,
                    srv_sms_archive_entry_struct *entry_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    FS_HANDLE file_handle;
    S8 ucs2_file_name[SRV_SMS_MAX_ARCH_PATH_LEN * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_archive_get_index_file_name(ucs2_file_name);
    
    file_handle = FS_Open((const WCHAR*)ucs2_file_name, FS_READ_WRITE);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_UPDATE_ENTRY_TO_FILE, file_handle);

    if (file_handle >= 0)
    {
        S32 fs_error;
        S32 offset = entry_id * sizeof(srv_sms_archive_entry_struct);        
        U32 write_size = 0;

        FS_Seek(file_handle, offset, FS_FILE_BEGIN);

        fs_error = FS_Write(
                        file_handle,
                        entry_node,
                        sizeof(srv_sms_archive_entry_struct),
                        &write_size);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_UPDATE_ENTRY_TO_FILE_1, fs_error);

        if (fs_error < 0)
        {
            archive_fs_error = fs_error;
            result = MMI_FALSE;
        }
    }
    else
    {
        archive_fs_error = file_handle;
        result = MMI_FALSE;
    }

    FS_Close(file_handle);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_UPDATE_ENTRY_TO_FILE_2, result);

    return result;;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_update_index_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_archive_update_index_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    FS_HANDLE file_handle;
    S8 ucs2_file_name[SRV_SMS_MAX_ARCH_PATH_LEN * ENCODING_LENGTH];
    U32 write_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_archive_get_index_file_name(ucs2_file_name);

    file_handle = FS_Open((WCHAR*)ucs2_file_name, FS_READ_WRITE);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_UPDATE_INDEX_FILE, file_handle);

    if (file_handle >= 0)
    {
        S32 fs_error;

        fs_error = FS_Write(
                    file_handle,
                    srv_sms_archive_msg_list,
                    sizeof(srv_sms_archive_entry_struct) * SRV_SMS_MAX_ARCH_ENTRY,
                    &write_size);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_UPDATE_INDEX_FILE_1, fs_error);

        if (fs_error < 0)
        {
            archive_fs_error = fs_error;
            result = MMI_FALSE;
        }
    }
    else
    {
        archive_fs_error = file_handle;
        result = MMI_FALSE;
    }

    FS_Close(file_handle);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_UPDATE_INDEX_FILE_2, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_delete_content_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_archive_delete_content_file(U16 entry_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    S8 content_file_name[SRV_SMS_MAX_ARCH_PATH_LEN * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_DELETE_CONTENT_FILE, entry_id);

    srv_sms_archive_get_content_file_name(content_file_name, entry_id);

    result = srv_sms_archive_delete_file(content_file_name);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_delete_all_content_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_archive_delete_all_content_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    S8 pub_folder_name[SRV_SMS_MAX_ARCH_PATH_LEN * ENCODING_LENGTH];
    S32 fs_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_archive_get_folder_name(pub_folder_name, MMI_FALSE);

    fs_error = FS_XDelete((WCHAR*)pub_folder_name, FS_FILE_TYPE, NULL, 0);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_DELETE_ALL_CONTENT_FILE, fs_error);

    if (fs_error < 0)
    {
        archive_fs_error = fs_error;
        result = MMI_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_create_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_archive_create_folder(char *ucs2_folder_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_handle = FS_CreateDir((const WCHAR*)ucs2_folder_name);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_CREATE_FOLDER, file_handle);

    if ((file_handle >= 0) || (file_handle == FS_FILE_EXISTS))
    {
        FS_SetAttributes((const WCHAR*)ucs2_folder_name, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    }
    else
    {
        result = MMI_FALSE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_CREATE_FOLDER_1, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_delete_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_archive_delete_file(char *ucs2_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    FS_HANDLE file_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_handle = FS_Delete((const WCHAR*)ucs2_file_name);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_DELETE_FILE, file_handle);

    if (file_handle < 0)
    {
        /* mean user may change attribute to read only via usb */
        if (FS_READ_ONLY_ERROR == file_handle)
        {
            S32 fs_error;
            FS_SetAttributes((WCHAR*)ucs2_file_name, FS_READ_WRITE);

            fs_error = FS_Delete((const WCHAR*)ucs2_file_name);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_DELETE_FILE_1, file_handle);

            if (fs_error < 0)
            {
                archive_fs_error = fs_error;
                result = MMI_FALSE;
            }
        }
        else if ((FS_PATH_NOT_FOUND != file_handle) && (FS_FILE_NOT_FOUND != file_handle))
        {
            archive_fs_error = file_handle;
            /* if file or fil path is not found, means user remove files via usb, need sync to idx.a file */
            result = MMI_FALSE;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_DELETE_FILE_2, result);

    return result;
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_get_public_folder_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_archive_get_folder_name(char* ucs2_buff, MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 asc_folder_path[SRV_SMS_MAX_ARCH_PATH_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_GET_SYS_FOLDER_NAME);
    if(flag)
        sprintf(asc_folder_path, "%c:%s", SRV_FMGR_SYSTEM_DRV, SRV_SMS_ARCH_SYS_PATH);
    else
    sprintf(asc_folder_path, "%c:%s", SRV_FMGR_PUBLIC_DRV, SRV_SMS_ARCH_PUB_PATH);
    mmi_asc_to_ucs2((S8*)ucs2_buff, (S8*)asc_folder_path);
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_get_index_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_archive_get_index_file_name(char* ucs2_buff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 asc_file_name[SRV_SMS_MAX_ARCH_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_GET_INDEX_FILE_NAME);

    sprintf(asc_file_name, "%c:%s%s", (S8)SRV_FMGR_SYSTEM_DRV, SRV_SMS_ARCH_SYS_PATH, "idx.a");
    mmi_asc_to_ucs2(ucs2_buff, asc_file_name);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_get_content_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_archive_get_content_file_name(char* ucs2_buff, U16 entry_id)
{
    S8 asc_file_name[SRV_SMS_MAX_ARCH_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_GET_CONTENT_FILE_NAME, entry_id);

    sprintf(asc_file_name, "%c:%s%x.a", (S8) SRV_FMGR_PUBLIC_DRV, SRV_SMS_ARCH_PUB_PATH, entry_id);
    mmi_asc_to_ucs2(ucs2_buff, asc_file_name);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_entry_to_msg_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_archive_entry_to_msg_info(
                srv_sms_msg_info_struct *msg_info,
                srv_sms_archive_entry_struct *entry_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_ENTRY_TO_MSG_INFO, msg_info, entry_node);

    msg_info->status = entry_node->status;

    mmi_dt_utc_sec_2_mytime(entry_node->timestamp, &msg_info->timestamp, MMI_FALSE);

    mmi_asc_to_ucs2(msg_info->number, (S8*)entry_node->number);

    msg_info->folder_id = SRV_SMS_FOLDER_ARCHIVE;

    msg_info->storage_type = SRV_SMS_STORAGE_ME;
    msg_info->pid = SRV_SMS_PID_DEFAULT;

#ifdef __SRV_SMS_MULTI_SIM__
    msg_info->sim_id = entry_node->sim_id;
#else /* __SRV_SMS_MULTI_SIM__ */
    msg_info->sim_id = SRV_SMS_SIM_1;
#endif /* __SRV_SMS_MULTI_SIM__ */

#ifdef __SRV_SMS_MSG_INFO_CONTENT__
    mmi_ucs2cpy(msg_info->content, (S8*)entry_node->content);
#else /* __SRV_SMS_MSG_INFO_CONTENT__ */
    memset(msg_info->content, 0, ENCODING_LENGTH);
#endif /* __SRV_SMS_MSG_INFO_CONTENT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_archive_entry_to_msg_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_archive_msg_info_to_entry(
                srv_sms_archive_entry_struct *entry_node,
                srv_sms_msg_info_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ARCHIVE_MSG_INFO_TO_ENTRY, entry_node, msg_info);

    entry_node->status = msg_info->status;

    entry_node->timestamp = mmi_dt_mytime_2_utc_sec(&msg_info->timestamp, MMI_FALSE);

    mmi_ucs2_to_asc((S8*)entry_node->number, msg_info->number);

#ifdef __SRV_SMS_MULTI_SIM__
    entry_node->sim_id = msg_info->sim_id;
#endif /* __SRV_SMS_MULTI_SIM__ */

#ifdef __SRV_SMS_MSG_INFO_CONTENT__
    mmi_ucs2cpy((S8*)entry_node->content, msg_info->content);
#endif /* __SRV_SMS_MSG_INFO_CONTENT__ */

    memcpy(entry_node->guardPattern, SRV_SMS_ARCHIVE_GUARD_PATTERN, SRV_SMS_ARCHIVE_GUARD_PATTERN_LEN);
}
#endif /* __SRV_SMS_ARCHIVE__ */ 
#endif /* __MOD_SMSAL__ */

