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
 *  FileMgrSrvCommon
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Common part of FileMgr service, including:
 *  1. Unsolicited (Interrupted) primitives handling. Ex. Card / OTG hot plug
 *  2. Memory management
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#define _FMGR_INTERNAL_SOURCE_C_
#define _FMGR_GPROT_H_

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
// by RHR //#include "MMI_include.h"

#include "FileMgrSrvProt.h"
#include "FileMgrSrvNotification.h"
#include "mmi_rp_srv_filemanager_def.h"

#include "fmt_struct.h"

#include "Conversions.h"        /* for convert native name */
#include "msdc_api.h"
#include "BootupSrvGprot.h"     /* for srv_bootup_is_booting() */

#if defined(__MMI_FMGR_SUPPORT_DEFAULT_STORAGE__)
// TODO: need revise
//#include "IdleGProt.h"          /* for mmi_idle_get_group_id() && mmi_idle_display() */
extern mmi_id mmi_idle_get_group_id(void);
extern void mmi_idle_display(void);
#endif

// TODO: Service include App, need revise
// by RHR //#include "gpioInc.h"            /* for TurnOnBacklight */
//#include "MainMenuDef.h"        /* for MAIN_MENU_SCREENID */

//#include "RightsMgrGProt.h"     /* for mmi_rmgr_get_err_string */
// by RHR //#include "CommonScreens.h"      /* for MMI_EVENT_SUCCESS, MMI_EVENT_FAILURE */

#ifdef __MMI_FACTORY_MODE__
#include "FactoryModeProt.h"
#include "FactoryModeGProt.h"
#endif

#ifdef __OTG_ENABLE__
#include "otg_if.h"             /* for OTG_DISPLAY_MSG_UN_SUPPORT, etc... */
#endif 

#include "MMI_features.h"

#include "string.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

#include "stack_msgs.h"

#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"

#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "Unicodexdcl.h"

#include "mmi_rp_file_type_def.h"
#include "GlobalResDef.h"
#include "GlobalConstants.h"
#include "CommonScreensResDef.h"
#include "CustDataRes.h"
#include "custom_mmi_default_value.h"

#include "gui_effect_oem.h"
#include "wgui_categories.h"
#include "wgui_categories_util.h"
#include "AlertScreen.h"
#include "custom_events_notify.h"
#include "NotificationGprot.h"
#include "FileMgrSrvGProt.h"

#include "fmt_trc.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif

/****************************************************************************
* Define
*****************************************************************************/

#if (defined(__FS_CARD_SUPPORT__) && !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)) || \
    (defined(__FS_CARD_SUPPORT__) && !defined(__MTK_TARGET__)) || \
    (defined(__OTG_ENABLE__))
#define SRV_FMGR_HOT_PLUG_SUPPORT
#endif

#if defined(__OTG_ENABLE__) && !defined(__FS_CARD_SUPPORT__)
#error "OTG is depend on Card support!"
#endif

/****************************************************************************
* Typedef
*****************************************************************************/

#define SRV_FMGR_MAX_FILEPATH_BUFFER    5

typedef struct _srv_fmgri_filepath_buffer_struct
{
    WCHAR   *path;
    S32     line;
} srv_fmgri_filepath_buffer_struct;

typedef struct
{
    S32 error;            /* error code */
    mmi_str_id str_id;    /* error string id */
} srv_fmgri_fs_error_info_struct;

typedef struct 
{
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
    MMI_BOOL                            default_stroage_need_confirm;
#endif                                

#if defined(SRV_FMGR_TESTBED_ENABLE) || !defined(__MTK_TARGET__)
    S8                                  trace_level;
#endif

    srv_fmgri_filepath_buffer_struct    filepath_array[SRV_FMGR_MAX_FILEPATH_BUFFER];
    FS_Pattern_Struct                   filter_pattern[FMGR_MAX_FILTER_COUNT];
    WCHAR                               stock_filepath[SRV_FMGR_PATH_MAX_LEN+1];
} srv_fmgr_context_struct;

/****************************************************************************
* Global Variable
*****************************************************************************/


/****************************************************************************
* Static Variable
*****************************************************************************/

const static srv_fmgri_fs_error_info_struct g_srv_fmgr_fs_error_table[] = 
{
#ifdef __MMI_SLIM_FILE_MANAGER__
    {FS_INVALID_FILENAME,               STR_GLOBAL_INVALID_FILENAME},
    {FS_FILE_NOT_FOUND,                 FMGR_FS_FILE_NOT_FOUND_TEXT},
    {FS_PATH_NOT_FOUND,                 FMGR_FS_PATH_NOT_FOUND_TEXT},
    {FS_DISK_FULL,                      STR_GLOBAL_NOT_ENOUGH_MEMORY},
    {FS_FILE_EXISTS,                    STR_GLOBAL_FILE_ALREADY_EXISTS},
    {FS_ACCESS_DENIED,                  FMGR_FS_ACCESS_DENIED_TEXT},
    {FS_ABORTED_ERROR,                  FMGR_FS_ABORTED_ERROR_TEXT},
    {FS_PATH_OVER_LEN_ERROR,            FMGR_FS_PATH_OVER_LEN_ERROR_TEXT},
    {FS_DEVICE_BUSY,                    FMGR_FS_DEVICE_BUSY_TEXT},
    {FS_APP_QUOTA_FULL,                 FMGR_FS_APP_QUOTA_FULL_TEXT},
#else
    {FS_ERROR_RESERVED,                 STR_GLOBAL_ERROR},
        
    {FS_PARAM_ERROR,                    FMGR_FS_PARAM_ERROR_TEXT},
    {FS_INVALID_FILENAME,               STR_GLOBAL_INVALID_FILENAME},
    {FS_DRIVE_NOT_FOUND,                FMGR_FS_DRIVE_NOT_FOUND_TEXT},
    {FS_TOO_MANY_FILES,                 FMGR_FS_TOO_MANY_FILES_TEXT},
    {FS_NO_MORE_FILES,                  FMGR_FS_NO_MORE_FILES_TEXT},
    {FS_WRONG_MEDIA,                    FMGR_FS_WRONG_MEDIA_TEXT},
    {FS_INVALID_FILE_SYSTEM,            FMGR_FS_INVALID_FILE_SYSTEM_TEXT},
    {FS_FILE_NOT_FOUND,                 FMGR_FS_FILE_NOT_FOUND_TEXT},
    {FS_INVALID_FILE_HANDLE,            FMGR_FS_INVALID_FILE_HANDLE_TEXT},
    {FS_UNSUPPORTED_DEVICE,             FMGR_FS_UNSUPPORTED_DEVICE_TEXT},
    {FS_UNSUPPORTED_DRIVER_FUNCTION,    FMGR_FS_UNSUPPORTED_DRIVER_FUNCTION_TEXT},
    {FS_CORRUPTED_PARTITION_TABLE,      FMGR_FS_CORRUPTED_PARTITION_TABLE_TEXT},
    {FS_TOO_MANY_DRIVES,                FMGR_FS_TOO_MANY_DRIVES_TEXT},
    {FS_INVALID_FILE_POS,               FMGR_FS_INVALID_FILE_POS_TEXT},
    {FS_ACCESS_DENIED,                  FMGR_FS_ACCESS_DENIED_TEXT},
    {FS_STRING_BUFFER_TOO_SMALL,        FMGR_FS_STRING_BUFFER_TOO_SMALL_TEXT},
    {FS_GENERAL_FAILURE,                FMGR_FS_GENERAL_FAILURE_TEXT},
    {FS_PATH_NOT_FOUND,                 FMGR_FS_PATH_NOT_FOUND_TEXT},
    {FS_FAT_ALLOC_ERROR,                FMGR_FS_FAT_ALLOC_ERROR_TEXT},
    {FS_ROOT_DIR_FULL,                  FMGR_FS_ROOT_DIR_FULL_TEXT},
    {FS_DISK_FULL,                      STR_GLOBAL_NOT_ENOUGH_MEMORY},
    {FS_TIMEOUT,                        FMGR_FS_TIMEOUT_TEXT},
    {FS_BAD_SECTOR,                     FMGR_FS_BAD_SECTOR_TEXT},
    {FS_DATA_ERROR,                     FMGR_FS_DATA_ERROR_TEXT},
    {FS_MEDIA_CHANGED,                  FMGR_FS_MEDIA_CHANGED_TEXT},
    {FS_SECTOR_NOT_FOUND,               FMGR_FS_SECTOR_NOT_FOUND_TEXT},
    {FS_ADDRESS_MARK_NOT_FOUND,         FMGR_FS_ADDRESS_MARK_NOT_FOUND_TEXT},
    {FS_DRIVE_NOT_READY,                FMGR_FS_DRIVE_NOT_READY_TEXT},
    {FS_WRITE_PROTECTION,               FMGR_FS_WRITE_PROTECTION_TEXT},
    {FS_DMA_OVERRUN,                    FMGR_FS_DMA_OVERRUN_TEXT},
    {FS_CRC_ERROR,                      FMGR_FS_CRC_ERROR_TEXT},
    {FS_DEVICE_RESOURCE_ERROR,          FMGR_FS_DEVICE_RESOURCE_ERROR_TEXT},
    {FS_INVALID_SECTOR_SIZE,            FMGR_FS_INVALID_SECTOR_SIZE_TEXT},
    {FS_OUT_OF_BUFFERS,                 FMGR_FS_OUT_OF_BUFFERS_TEXT},
    {FS_FILE_EXISTS,                    STR_GLOBAL_FILE_ALREADY_EXISTS},
    {FS_LONG_FILE_POS,                  FMGR_FS_LONG_FILE_POS_TEXT},
    {FS_FILE_TOO_LARGE,                 FMGR_FS_FILE_TOO_LARGE_TEXT},
    {FS_BAD_DIR_ENTRY,                  FMGR_FS_BAD_DIR_ENTRY_TEXT},
    {FS_READ_ONLY_ERROR,                FMGR_FS_READ_ONLY_ERROR_TEXT},
    {FS_SYSTEM_CRASH,                   FMGR_FS_SYSTEM_CRASH_TEXT},
    {FS_FAIL_GET_MEM,                   STR_GLOBAL_NOT_ENOUGH_MEMORY},
    {FS_DEVICE_BUSY,                    FMGR_FS_DEVICE_BUSY_TEXT},
    {FS_ABORTED_ERROR,                  FMGR_FS_ABORTED_ERROR_TEXT},
    {FS_FLASH_MOUNT_ERROR,              FMGR_FS_FLASH_MOUNT_ERROR_TEXT},
    {FS_PATH_OVER_LEN_ERROR,            FMGR_FS_PATH_OVER_LEN_ERROR_TEXT},
    {FS_APP_QUOTA_FULL,                 FMGR_FS_APP_QUOTA_FULL_TEXT},
    {FS_DEVICE_EXPORTED_ERROR,          FMGR_FS_DEVICE_EXPORTED_ERROR_TEXT},
    {FS_MSDC_MOUNT_ERROR,               FMGR_FS_MSDC_MOUNT_ERROR_TEXT},
    {FS_MSDC_READ_SECTOR_ERROR,         FMGR_FS_MSDC_READ_SECTOR_ERROR_TEXT},
    {FS_MSDC_WRITE_SECTOR_ERROR,        FMGR_FS_MSDC_WRITE_SECTOR_ERROR_TEXT},
    {FS_MSDC_DISCARD_SECTOR_ERROR,      FMGR_FS_MSDC_DISCARD_SECTOR_ERROR_TEXT},
    {FS_MSDC_PRESNET_NOT_READY,         FMGR_FS_MSDC_PRESENT_NOT_READY_TEXT},
    {FS_MSDC_NOT_PRESENT,               FMGR_FS_MSDC_NOT_PRESENT_TEXT},
    {FS_FLASH_ERASE_BUSY,               FMGR_FS_FLASH_ERASE_BUSY_TEXT},
    {FS_LOCK_MUTEX_FAIL,                FMGR_FS_LOCK_MUTEX_FAIL_TEXT},
#endif
    //{FS_ATTR_CONFLICT,                FMGR_FS_ATTR_CONFLICT_TEXT},
    //{FS_CHECKDISK_RETRY,              FMGR_FS_CHECKDISK_RETRY_TEXT},
    //{FS_LACK_OF_PROTECTION_SPACE,     FMGR_FS_LACK_OF_PROTECTION_SPACE_TEXT},

    {0, 0}
};

static srv_fmgr_context_struct g_srv_fmgr_ctxt;
static kal_uint32 g_msdc_plugin_cause = 0;

/****************************************************************************
* Function Forward Declaration
*****************************************************************************/
void srv_fmgri_device_ready_hdlr(void *msg_ptr);

#if defined(SRV_FMGR_HOT_PLUG_SUPPORT)
#if !defined(__COSMOS_MMI__)
static MMI_BOOL srv_fmgri_device_check_memory_card(U8 drive_letter, MMI_BOOL check_available);
#endif
static void srv_fmgri_device_plug_in_hdlr(fmt_mmi_card_plug_in_ind_struct *msg_ptr);
static void srv_fmgri_device_plug_out_hdlr(fmt_mmi_card_plug_out_ind_struct *msg_ptr);
static void srv_fmgri_device_plug_in_display_hdlr(msdc_card_detect_ind_struct *msg_ptr);

#if defined(__MSDC_DUAL_CARD_SWITCH__) && !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
static void srv_fmgri_msdc_msg_hdlr(msdc_card_detect_ind_struct *msg_prt);

static MMI_BOOL g_fmt_msdc_available;
static U8 g_queue_num;

#define MAX_MSDC_MSG_QUEUE_SIZE 2
static msdc_card_detect_ind_struct g_msdc_msg_queue[MAX_MSDC_MSG_QUEUE_SIZE];
#endif /* __MSDC_DUAL_CARD_SWITCH__ */
#elif defined(SRV_FMGR_DRV_LSD_SUPPORT)
static void srv_fmgri_device_plug_in_hdlr(fmt_mmi_card_plug_in_ind_struct *msg_ptr);
#endif
#ifdef __OTG_ENABLE__
static void srv_fmgri_otg_display_hdlr(otg_display_struct *msg_ptr);
#endif

extern void srv_fmgr_folder_filelist_init(void);

#define END_OF_FUNCTION_DECLARATION
/****************************************************************************
* Function Body
*****************************************************************************/

void srv_fmgr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_fmgri_device_ready_hdlr, MSG_ID_MMI_FMT_CARD_READY_IND);
#if defined (SRV_FMGR_HOT_PLUG_SUPPORT)
    SetProtocolEventHandler(srv_fmgri_device_plug_in_hdlr,  MSG_ID_FMT_MMI_CARD_PLUG_IN_IND);
    SetProtocolEventHandler(srv_fmgri_device_plug_out_hdlr, MSG_ID_FMT_MMI_CARD_PLUG_OUT_IND);
    SetProtocolEventHandler(srv_fmgri_device_plug_in_display_hdlr, MSG_ID_MSDC_CARD_DISPLAY_IND);
#if defined(__MSDC_DUAL_CARD_SWITCH__) && !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
    SetProtocolEventHandler(srv_fmgri_msdc_msg_hdlr, MSG_ID_MSDC_CARD_DETECT_IND);

    memset(g_msdc_msg_queue, 0, sizeof(msdc_card_detect_ind_struct)*MAX_MSDC_MSG_QUEUE_SIZE);

    g_fmt_msdc_available = MMI_TRUE;
    g_queue_num = 0;
#endif
#elif defined(SRV_FMGR_DRV_LSD_SUPPORT)
    SetProtocolEventHandler(srv_fmgri_device_plug_in_hdlr,  MSG_ID_FMT_MMI_CARD_PLUG_IN_IND);
#endif 

#ifdef __OTG_ENABLE__
    SetProtocolEventHandler(srv_fmgri_otg_display_hdlr, MSG_ID_FMT_MMI_OTG_DISPLAY_IND);
#endif /* __FS_CARD_SUPPORT__ */

    memset(&g_srv_fmgr_ctxt, 0, sizeof(g_srv_fmgr_ctxt));

    srv_fmgr_drv_init();

    srv_fmgr_folder_filelist_init();

}

/* used by SSCStringHandle.c */
void srv_fmgr_testbed_launch(void)
{
#if defined(SRV_FMGR_TESTBED_ENABLE)
    extern void srv_ftst_rt_main_entry(void);
    srv_ftst_rt_main_entry();
#endif
}

#define SECTION_COMMON_TOOL

WCHAR* srv_fmgri_alloc_path_buffer_internal(S32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i=0;i<SRV_FMGR_MAX_FILEPATH_BUFFER;i++)
    {
        if(!g_srv_fmgr_ctxt.filepath_array[i].path)
            break;
    }

    FMGR_ASSERT(i != SRV_FMGR_MAX_FILEPATH_BUFFER);

    if(i==0)
    {
        g_srv_fmgr_ctxt.filepath_array[i].path = g_srv_fmgr_ctxt.stock_filepath;
    }
    else
    {
        g_srv_fmgr_ctxt.filepath_array[i].path = (WCHAR*)OslMalloc(SRV_FMGR_PATH_BUFFER_SIZE);
    }
    g_srv_fmgr_ctxt.filepath_array[i].path[0] = 0;
    g_srv_fmgr_ctxt.filepath_array[i].line = line;
    
    return g_srv_fmgr_ctxt.filepath_array[i].path;

}

void srv_fmgri_free_path_buffer(WCHAR* buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_ASSERT(buffer);
    
    for(i=0;i<SRV_FMGR_MAX_FILEPATH_BUFFER;i++)
    {
        if(g_srv_fmgr_ctxt.filepath_array[i].path == buffer)
            break;
    }
    FMGR_ASSERT(i != SRV_FMGR_MAX_FILEPATH_BUFFER);

    if(i)
        OslMfree(buffer);
    g_srv_fmgr_ctxt.filepath_array[i].path = NULL;
    g_srv_fmgr_ctxt.filepath_array[i].line = 0;

}

S32 srv_fmgri_convert_string(WCHAR* dest_buf, S32 dest_size, const WCHAR* src_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!src_buf)
        return FS_PARAM_ERROR;

    if(dest_buf)
    {
        mmi_chset_mixed_text_to_ucs2_str(
            (U8*) dest_buf,
            (S16) dest_size,
            (U8*) src_buf,
            (mmi_chset_enum) mmi_chset_get_default_encoding_type());
        return 0;
    }
    else
    {
        return mmi_wcslen(src_buf);
    }
}

void srv_fmgri_convert_direntry(srv_fmgr_fileinfo_struct* fileinfo, const FS_DOSDirEntry* direntry, const WCHAR* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_ASSERT(fileinfo && direntry);

    fileinfo->attribute = direntry->Attributes;
    
    fileinfo->datetime.nYear = direntry->DateTime.Year1980 + 1980;
    fileinfo->datetime.nMonth = direntry->DateTime.Month;
    fileinfo->datetime.nDay = direntry->DateTime.Day;
    fileinfo->datetime.nHour = direntry->DateTime.Hour;
    fileinfo->datetime.nMin = direntry->DateTime.Minute;
    fileinfo->datetime.nSec = direntry->DateTime.Second2;

    fileinfo->created_datetime.nYear = direntry->CreateDateTime.Year1980 + 1980;
    fileinfo->created_datetime.nMonth = direntry->CreateDateTime.Month;
    fileinfo->created_datetime.nDay = direntry->CreateDateTime.Day;
    fileinfo->created_datetime.nHour = direntry->CreateDateTime.Hour;
    fileinfo->created_datetime.nMin = direntry->CreateDateTime.Minute;
    fileinfo->created_datetime.nSec = direntry->CreateDateTime.Second2;

    fileinfo->size = direntry->FileSize;

    if(fileinfo->attribute & FS_ATTR_DIR)
    {
        fileinfo->type = FMGR_TYPE_FOLDER;
    }
    else if(filename)
    {
        fileinfo->type = srv_fmgr_types_find_type_by_filename_str(filename);
        // TODO: [FileMgrSrv] check DRM 2.0 (use drm_open_file instead of FS_Open)
    }
    else
    {
        fileinfo->type = FMGR_TYPE_UNKNOWN;
    }

}

#define SECTION_FIND_FIRST

S32 srv_fmgri_find_first(const WCHAR* folderpath, const FMGR_FILTER *filter, S32 start_index,
                             WCHAR* name_buf, S32 name_buf_size,
                             srv_fmgr_fileinfo_struct *fileinfo,
                             FS_HANDLE *fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR           find_pattern[SRV_FMGR_PATH_MAX_LEN+5];
    FS_DOSDirEntry  direntry;
    FS_HANDLE       file_handle;
    U8              filter_count, with_folder, folder_only, need_free;
    S32             len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!folderpath || !fh)
        return FS_PARAM_ERROR;

    len = mmi_wcslen(folderpath);
    if(len <= 0)
        return FS_PARAM_ERROR;
    if(len > SRV_FMGR_PATH_MAX_LEN || (folderpath[len-1] != '\\' && len+1 > SRV_FMGR_PATH_MAX_LEN))
        return FS_PATH_OVER_LEN_ERROR;

    need_free = 0;
    if(!name_buf)
    {
        need_free = 1;
        name_buf = srv_fmgri_alloc_path_buffer();
        name_buf_size = SRV_FMGR_PATH_BUFFER_SIZE;
    }

    /* prepare find_pattern */
    mmi_wcsncpy(find_pattern, folderpath, len);
    if(folderpath[len-1] != '\\')
    {
        find_pattern[len++] = '\\';
        find_pattern[len] = 0;
    }
    mmi_wcscpy(find_pattern + len, (WCHAR*)L"*.*");

    /* construct filter */
    if(filter)
    {
        filter_count = srv_fmgri_construct_filter_pattern(filter, g_srv_fmgr_ctxt.filter_pattern, FMGR_MAX_FILTER_COUNT);

        /* When filter isn't with folder, it means browse without folder.  */
        with_folder = FMGR_FILTER_IS_SET(filter, FMGR_TYPE_FOLDER);
        folder_only = (filter_count == 1 && with_folder) ? 1 : 0;
    }
    else
    {
        filter_count = 0;
        with_folder = 1;
        folder_only = 0;
    }
    
    file_handle = FS_FindFirstN(
        find_pattern,
        filter ? g_srv_fmgr_ctxt.filter_pattern : NULL,
        filter_count,
        (BYTE)(with_folder ? FS_ATTR_DIR : 0),
        (BYTE)(folder_only ? FS_ATTR_DIR : 0),
        (BYTE)(with_folder ? 
            (FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME) : 
            (FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME | FS_ATTR_DIR)),
        &direntry,
        name_buf,
        name_buf_size,
        start_index,
        FS_FIND_DEFAULT);

    if(file_handle < 0)
    {
        if(need_free)
            srv_fmgri_free_path_buffer(name_buf);
        return file_handle;
    }

    if(fileinfo)
        srv_fmgri_convert_direntry(fileinfo, &direntry, name_buf);

    if(need_free)
        srv_fmgri_free_path_buffer(name_buf);
    *fh = file_handle;
    return 0;
}

S32 srv_fmgri_find_next (FS_HANDLE fh, const FMGR_FILTER *filter,
                             WCHAR* name_buf, S32 name_buf_size,
                             srv_fmgr_fileinfo_struct *fileinfo)
{
#ifndef __MMI_SLIM_FILE_MANAGER__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DOSDirEntry direntry;
    U8 filter_count, with_folder;
    S32 fs_ret;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!name_buf)
        return FS_PARAM_ERROR;

    filter_count = srv_fmgri_construct_filter_pattern(filter, g_srv_fmgr_ctxt.filter_pattern, FMGR_MAX_FILTER_COUNT);

    with_folder = FMGR_FILTER_IS_SET(filter, FMGR_TYPE_FOLDER);
    
    fs_ret = FS_FindNextN(
        fh,
        g_srv_fmgr_ctxt.filter_pattern,
        filter_count,
        (BYTE)(with_folder ? FS_ATTR_DIR : 0),
        &direntry,
        name_buf,
        name_buf_size,
        FS_FIND_DEFAULT);

    if(fileinfo)
        srv_fmgri_convert_direntry(fileinfo, &direntry, name_buf);
    
    return fs_ret;
#else
	return FS_ERROR_RESERVED;
#endif
}

S32 srv_fmgri_find_close(FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return FS_FindClose(fh);
}

#define SECTION_FS_ERROR

mmi_str_id srv_fmgr_fs_error_get_string(S32 fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; g_srv_fmgr_fs_error_table[i].error != 0; i++)
    {
        if (g_srv_fmgr_fs_error_table[i].error == fs_error)
        {
            return g_srv_fmgr_fs_error_table[i].str_id;
        }
    }
    
#ifdef __DRM_SUPPORT__    
    if (fs_error < FS_MINIMUM_ERROR_CODE)  /* The max of File System error code */
    {
        return mmi_rmgr_get_err_string(fs_error);
    }
#endif

    return STR_GLOBAL_ERROR;
}

S32 srv_fmgr_fs_error_get_popup_type(S32 fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(fs_error)
    {
    case FS_ABORTED_ERROR:
        return MMI_EVENT_SUCCESS;
    }
    
    return MMI_EVENT_FAILURE;
}

mmi_str_id  srv_fmgr_fs_error_get_string_and_popup_type(S32 fs_error, S32* popup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(popup_type)
        *popup_type = srv_fmgr_fs_error_get_popup_type(fs_error);
    return srv_fmgr_fs_error_get_string(fs_error);
}

#define SECTION_SORT

S32 srv_fmgr_sort_set(U32 sort_option)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(srv_fmgr_sort_get() == sort_option)
        return 0;

    switch(sort_option)
    {
    case FS_NO_SORT:
    case FS_SORT_NAME:
    case FS_SORT_SIZE:
    case FS_SORT_TIME:
    case FS_SORT_TYPE:
        break;

    default:
        return FS_PARAM_ERROR;
    }

    temp = sort_option >> 5;
    WriteValue(NVRAM_EF_FMGR_SORT_OPTION_LID, &temp, DS_BYTE, &error);

    return 1;    
}

U32  srv_fmgr_sort_get(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 temp;
    U32 sort_option;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_EF_FMGR_SORT_OPTION_LID, &temp, DS_BYTE, &error);
    if(error != NVRAM_READ_SUCCESS)
        temp = 0xFF;
    if(temp == 0xFF)
        temp = 0;
    sort_option = (U32)temp << 5;

    switch(sort_option)
    {
    case FS_NO_SORT:    
    case FS_SORT_NAME:
    case FS_SORT_SIZE:
    case FS_SORT_TIME:
    case FS_SORT_TYPE:
        return sort_option;
	default:	
        break;
    }
    return FS_SORT_NAME;
}


#define LOCAL_FUNCTION

void srv_fmgri_device_ready_hdlr(void *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_notification_dev_ready_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&evt, 0, sizeof(evt));
    evt.evt_id = EVT_ID_SRV_FMGR_NOTIFICATION_DEV_READY;
    evt.size = sizeof(evt);

    FMGR_TRACE0(TGL1, TRC_SRV_FMGR_NOTIFICATION_DEV_READY,
        "[SRV_FMGR] > Notify > Devices ready");

    mmi_frm_cb_emit_post_event((mmi_event_struct*)&evt);
}

#if defined (SRV_FMGR_HOT_PLUG_SUPPORT)
#if !defined(__COSMOS_MMI__)

static MMI_BOOL srv_fmgri_device_check_memory_card(U8 drive_letter, MMI_BOOL check_available)
{
    MMI_BOOL result = MMI_FALSE;

    do {
        if (drive_letter == SRV_FMGR_CARD_DRV ||
            drive_letter == SRV_FMGR_CARD2_DRV)
        {
            result = MMI_TRUE;
            if (check_available && !srv_fmgr_drv_is_accessible(drive_letter))
            {
                result = MMI_FALSE;
            }
            break;
        }
    } while(0);

    return result;
}
#endif
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__

static void srv_fmgri_device_set_default_storage_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 drv;
    S32 fs_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_fmgr_ctxt.default_stroage_need_confirm = MMI_FALSE;
    drv = SRV_FMGR_CARD_DRV;

    do {

        if(!srv_fmgr_drv_is_accessible(drv))
        {
            fs_ret = FS_DRIVE_NOT_FOUND;
            break;
        }

        fs_ret = srv_fmgri_notify_def_storage_event(drv);
        if(fs_ret < 0)
            break;
    } while(0);

    if(fs_ret < 0)
    {
        mmi_popup_display((WCHAR*)(get_string(srv_fmgr_fs_error_get_string(fs_ret))), MMI_EVENT_FAILURE, NULL);
    }
    else
    {
        mmi_popup_display((WCHAR*)(get_string(STR_GLOBAL_DONE)), MMI_EVENT_SUCCESS, NULL);
    }
}

static void srv_fmgri_device_set_default_storage_cancel_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_fmgr_ctxt.default_stroage_need_confirm = MMI_FALSE;
    mmi_frm_scrn_close_active_id();
}

U8 srv_fmgr_default_storage_need_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_fmgr_ctxt.default_stroage_need_confirm &&
        srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
    {
        return MMI_TRUE;
    }
    g_srv_fmgr_ctxt.default_stroage_need_confirm = MMI_FALSE;
    return MMI_FALSE;
}

static mmi_ret srv_fmgri_default_storage_key_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_key_evt_struct *key_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    key_evt = (mmi_frm_key_evt_struct*)evt;

    switch(evt->evt_id)
    {
    case EVT_ID_ON_KEY:
        break;

    case EVT_ID_PRE_KEY:
        if (key_evt->key_code == KEY_END &&
            key_evt->key_type == KEY_EVENT_DOWN)
        {
            g_srv_fmgr_ctxt.default_stroage_need_confirm = MMI_FALSE;
        }
        break;
    }
    return MMI_RET_OK;
}
    
void srv_fmgr_default_storage_do_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *display_ptr;
    WCHAR *last_mark;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!mmi_frm_scrn_enter(mmi_idle_get_group_id(), SCR_CONFIRM_SCREEN, NULL, NULL, 0))
        return;

    display_ptr = (WCHAR*)subMenuData;
    mmi_wcscpy(display_ptr, (WCHAR*)get_string(STR_GLOBAL_MC_INSERTED));

    last_mark = (WCHAR*)get_string(STR_ID_FMGR_CARD_APPLY_DEF_STORAGE2);
    last_mark += mmi_wcslen(last_mark)-1;
    mmi_wcscat(display_ptr, last_mark);

    ShowCategory154Screen(STR_GLOBAL_MEMORY_CARD, 0,
                          STR_GLOBAL_YES, IMG_GLOBAL_YES,
                          STR_GLOBAL_NO, IMG_GLOBAL_NO,
                          (PU8) display_ptr,
                          (PU8) GetString(STR_ID_FMGR_CARD_APPLY_DEF_STORAGE3),
                          mmi_get_event_based_image(MMI_EVENT_QUERY),
                          NULL);

    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(srv_fmgri_device_set_default_storage_hdlr, KEY_EVENT_UP);
    SetLeftSoftkeyFunction(srv_fmgri_device_set_default_storage_hdlr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(srv_fmgri_device_set_default_storage_cancel_hdlr, KEY_EVENT_UP);
    mmi_frm_scrn_set_key_proc(
        mmi_idle_get_group_id(),
        SCR_CONFIRM_SCREEN,
        srv_fmgri_default_storage_key_proc);
}
#endif

#if defined(__MSDC_DUAL_CARD_SWITCH__) && !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
static void srv_fmgri_send_fmt_msdc_msg(msdc_card_detect_ind_struct *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;
    msdc_card_detect_ind_struct *msgReq = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (msdc_card_detect_ind_struct*) OslConstructDataPtr(sizeof(msdc_card_detect_ind_struct));

    msgReq->media_size = msg_ptr->media_size;
    msgReq->media_array = msg_ptr->media_array;
    msgReq->media_status = msg_ptr->media_status;
        
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_FMT;
    Message.oslMsgId = MSG_ID_MMI_FMT_MSDC_CARD_DETECT_IND;
    Message.oslDataPtr = (oslParaType*) msgReq;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);

    g_fmt_msdc_available = MMI_FALSE;
}

static void srv_fmgri_msdc_msg_hdlr(msdc_card_detect_ind_struct *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do {
        /* If the queue is empty, and the current message is:
           1. OUT => Send FMT the message anyway 
           2. IN, and msdc available flag is true => Send FMT the message */
        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_9d71258a3d8f495bbad1ba5d05087763, "[SRV_FMGR] > Current > msg status: %d, queue size: %d, send available: %d", msg_ptr->media_status, g_queue_num, g_fmt_msdc_available);
        if ((msg_ptr->media_status == 0 && g_queue_num == 0) || 
            (msg_ptr->media_status == 1 && g_queue_num == 0 && g_fmt_msdc_available))
        {
            srv_fmgri_send_fmt_msdc_msg(msg_ptr);
            break;
        }

        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_2162a813145b4d029891fbb9405042ca, "[SRV_FMGR] > Before > queue size: %d, queue[0] status: %d, queue[1] status: %d", g_queue_num, g_msdc_msg_queue[0].media_status, g_msdc_msg_queue[1].media_status);
        if (g_queue_num == MAX_MSDC_MSG_QUEUE_SIZE)
        {
            /* Case 1: queue is full => IN-OUT pair, drop both then insert current IN message
                                     => OUT-IN pair, drop IN msg and the current OUT message*/
            if (g_msdc_msg_queue[0].media_status == 1 && g_msdc_msg_queue[1].media_status == 0)
            {
                /* IN-OUT pair, the current one should be IN */
                MMI_ASSERT(msg_ptr->media_status == 1);
                /* Drop both */
                memset(g_msdc_msg_queue, 0, sizeof(msdc_card_detect_ind_struct)*MAX_MSDC_MSG_QUEUE_SIZE);
                /* Insert current IN message */
                g_msdc_msg_queue[0].media_size = msg_ptr->media_size;
                g_msdc_msg_queue[0].media_array = msg_ptr->media_array;
                g_msdc_msg_queue[0].media_status = msg_ptr->media_status;

                g_queue_num = 1;
            }
            else if (g_msdc_msg_queue[0].media_status == 0 && g_msdc_msg_queue[1].media_status == 1)
            {
                /* OUT-IN pair, the current one should be OUT */
                MMI_ASSERT(msg_ptr->media_status == 0);
                /* Drop IN and the current OUT msg */
                memset((void*)&g_msdc_msg_queue[1], 0, sizeof(msdc_card_detect_ind_struct));

                g_queue_num = 1;
            }
            else
            {
                MMI_ASSERT(0);
            }
            break;
        }
        else
        {
            if (g_queue_num >= 0 && g_queue_num < MAX_MSDC_MSG_QUEUE_SIZE)
            {
                /* Case 2: Insert the current msg anyway */
                g_msdc_msg_queue[g_queue_num].media_size = msg_ptr->media_size;
                g_msdc_msg_queue[g_queue_num].media_array = msg_ptr->media_array;
                g_msdc_msg_queue[g_queue_num].media_status = msg_ptr->media_status;
                g_queue_num++;
            }
        }
        FMGR_TRACE3(TGL1, TRC_SRV_FMGR_a22c75b21c274085a660d1d45f8e0fe8, "[SRV_FMGR] > After > queue size: %d, queue[0] status: %d, queue[1] status: %d",
                    g_queue_num, g_msdc_msg_queue[0].media_status, g_msdc_msg_queue[1].media_status);
    } while(0);
}
#endif

static void srv_fmgri_device_plug_in_hdlr(fmt_mmi_card_plug_in_ind_struct *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__COSMOS_MMI__)
    mmi_str_id str_id;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MSDC_DUAL_CARD_SWITCH__) && !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
    /* Reset msdc available flag */
    g_fmt_msdc_available = MMI_TRUE;

    FMGR_TRACE3(TGL1, TRC_SRV_FMGR_7d83fe57831b498d824f52fe36f6cae1, "[SRV_FMGR] > Receive from FMT > queue size: %d, queue[0] status: %d, queue[1] status: %d",
                g_queue_num, g_msdc_msg_queue[0].media_status, g_msdc_msg_queue[1].media_status);
    if (g_queue_num > 0 && g_fmt_msdc_available)
    {
        /* Send FMT msdc message */
        srv_fmgri_send_fmt_msdc_msg(&g_msdc_msg_queue[0]);
        if (g_queue_num == MAX_MSDC_MSG_QUEUE_SIZE)
        {
            /* Shift */
            g_msdc_msg_queue[0].media_size = g_msdc_msg_queue[1].media_size;
            g_msdc_msg_queue[0].media_array = g_msdc_msg_queue[1].media_array;
            g_msdc_msg_queue[0].media_status = g_msdc_msg_queue[1].media_status;
            /* Remove slot 1 */
            memset((void*)&g_msdc_msg_queue[1], 0, sizeof(msdc_card_detect_ind_struct));
        }
        else
        {
            memset(g_msdc_msg_queue, 0, sizeof(msdc_card_detect_ind_struct)*MAX_MSDC_MSG_QUEUE_SIZE);
        }
        g_queue_num--;
    }
#else
	if(msg_ptr->cause == FS_NO_ERROR  && g_msdc_plugin_cause == FS_MSDC_MOUNT_ERROR)
	{
		srv_fmgri_drv_update_status(msg_ptr->drv_letter, msg_ptr->drv_num, msg_ptr->cause, MMI_TRUE);
		g_msdc_plugin_cause = msg_ptr->cause;
		return;
	}
	
#endif

    srv_fmgri_drv_update_status(msg_ptr->drv_letter, msg_ptr->drv_num, msg_ptr->cause, MMI_TRUE);

    // TODO: make this a notification receiver
#if defined(__MMI_FACTORY_MODE__) && (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))
    {
        mmi_fmt_get_msdc_status_rsp_strcut card_status;
        
        memset(&card_status, 0, sizeof(card_status));
        card_status.present = MMI_TRUE;
        card_status.type = msg_ptr->type;
        FM_MemoryCardResponseHandler(&card_status);
    }
#endif

    if (srv_bootup_is_booting())
        return;

#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
    if( msg_ptr->drv_num == 1 &&
        msg_ptr->drv_letter[0] == SRV_FMGR_CARD_DRV &&
        srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
    {
        g_srv_fmgr_ctxt.default_stroage_need_confirm = MMI_TRUE;
    }
#endif

#if !defined(__COSMOS_MMI__)
    if( msg_ptr->drv_num == 1 &&
        srv_fmgri_device_check_memory_card((U8)msg_ptr->drv_letter[0], MMI_FALSE))
    {
        str_id = STR_GLOBAL_MC_INSERTED;
    }
    else
    {
        str_id = STR_GLOBAL_OTG_CONNECTED;
    }

#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    gui_screen_switch_effect_force_block(MMI_TRUE);
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_MSDC_PLUG, MMI_EVENT_INFO, (WCHAR *)get_string(str_id));
    gui_screen_switch_effect_force_block(MMI_FALSE);
#else
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_MSDC_PLUG, MMI_EVENT_INFO, (WCHAR *)get_string(str_id));
#endif
#endif

    srv_fmgri_notify_device_plug_event(SRV_FMGRI_PLUG_IN, msg_ptr->drv_letter, msg_ptr->drv_num);
}

static void srv_fmgri_device_plug_out_hdlr(fmt_mmi_card_plug_out_ind_struct *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__COSMOS_MMI__)
    mmi_str_id prompt_str;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MSDC_DUAL_CARD_SWITCH__) && !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
    /* Reset msdc available flag */
    g_fmt_msdc_available = MMI_TRUE;

    FMGR_TRACE3(TGL1, TRC_SRV_FMGR_7d83fe57831b498d824f52fe36f6cae1, "[SRV_FMGR] > Receive from FMT > queue size: %d, queue[0] status: %d, queue[1] status: %d",
                g_queue_num, g_msdc_msg_queue[0].media_status, g_msdc_msg_queue[1].media_status);
    if (g_queue_num > 0 && g_fmt_msdc_available)
    {
        /* Send FMT msdc message */
        srv_fmgri_send_fmt_msdc_msg(&g_msdc_msg_queue[0]);
        if (g_queue_num == MAX_MSDC_MSG_QUEUE_SIZE)
        {
            /* Shift */
            g_msdc_msg_queue[0].media_size = g_msdc_msg_queue[1].media_size;
            g_msdc_msg_queue[0].media_array = g_msdc_msg_queue[1].media_array;
            g_msdc_msg_queue[0].media_status = g_msdc_msg_queue[1].media_status;
            /* Remove slot 1 */
            memset((void*)&g_msdc_msg_queue[1], 0, sizeof(msdc_card_detect_ind_struct));
        }
        else
        {
            memset(g_msdc_msg_queue, 0, sizeof(msdc_card_detect_ind_struct)*MAX_MSDC_MSG_QUEUE_SIZE);
        }
        g_queue_num--;
    }
 #else
  g_msdc_plugin_cause = FS_NO_ERROR;
  #endif
  
    srv_fmgri_drv_update_status(msg_ptr->drv_letter, msg_ptr->drv_num, msg_ptr->cause, MMI_FALSE);
    
#if defined(__MMI_FACTORY_MODE__) && (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__) || defined(__MSDC_MSPRO__))
    {
        mmi_fmt_get_msdc_status_rsp_strcut card_status;
    
        memset(&card_status, 0, sizeof(card_status));
        card_status.present = MMI_FALSE;
        FM_MemoryCardResponseHandler(&card_status);
    }
#endif

    if (srv_bootup_is_booting())
        return;

#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
    if( msg_ptr->drv_num == 1 &&
        msg_ptr->drv_letter[0] == SRV_FMGR_CARD_DRV)
    {
        g_srv_fmgr_ctxt.default_stroage_need_confirm = MMI_FALSE;
    }
#endif

#if !defined(__COSMOS_MMI__)
    if (msg_ptr->cause == FS_NO_ERROR || msg_ptr->cause == FS_MSDC_NOT_PRESENT)
    {
        if( msg_ptr->drv_num == 1 &&
            srv_fmgri_device_check_memory_card((U8)msg_ptr->drv_letter[0], MMI_FALSE))
        {
            prompt_str = STR_GLOBAL_MC_REMOVED;
        }
        else
        {
            prompt_str = STR_GLOBAL_OTG_REMOVED;
        }
    }
    else
        prompt_str = srv_fmgr_fs_error_get_string(msg_ptr->cause);

#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    gui_screen_switch_effect_force_block(MMI_TRUE);
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_MSDC_PLUG, MMI_EVENT_INFO, (WCHAR *)get_string(prompt_str));
    gui_screen_switch_effect_force_block(MMI_FALSE);
#else
    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_MSDC_PLUG, MMI_EVENT_INFO, (WCHAR *)get_string(prompt_str));
#endif
#endif

    srv_fmgri_notify_device_plug_event(SRV_FMGRI_PLUG_OUT, msg_ptr->drv_letter, msg_ptr->drv_num);

}

static void srv_fmgri_device_plug_in_display_hdlr(msdc_card_detect_ind_struct* msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 path[10];
    kal_int32 result;
    FS_DeviceInfo info;
    MMI_BOOL show = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If it is case 1-bit and phone isn't in mass storage mode, to display "Mounting" */
    memset(path, 0, 10);
    kal_wsprintf((WCHAR*) path, "%c:\\", FS_GetDrive(FS_DRIVE_V_REMOVABLE, (msg_ptr->media_index+1), FS_NO_ALT_DRIVE));
    result = FS_IOCtrl((WCHAR*)path, FS_IOCTRL_QUERY_CARD_INFO, &info);
    FMGR_TRACE2(TGL1, TRC_SRV_FMGR_e75ae42313e34d30991f4346759b37e7, "[SRV_FMGR] > Card > bit: (%d, %d)", result, info.DeviceInfo.Card.DeferredMount);
    if (FS_NO_ERROR == result && info.DeviceInfo.Card.DeferredMount != 0)
    {
        show = MMI_TRUE;
    }
    
    if (show
#ifdef __MMI_USB_SUPPORT__
        && !srv_usb_is_in_mass_storage_mode()
#endif
       )
    {
    #if defined(__COSMOS_MMI__)
        srv_fmgri_notify_device_plug_event(SRV_FMGRI_PLUG_DISPLAY_MOUNTING, path, 1);
    #else
    /* Case Pluto */
    #ifdef __MMI_SCREEN_SWITCH_EFFECT__
        gui_screen_switch_effect_force_block(MMI_TRUE);
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_MSDC_PLUG, MMI_EVENT_INFO, (WCHAR *)get_string(STR_FMGR_CARD_MOUNTING));
        gui_screen_switch_effect_force_block(MMI_FALSE);
    #else
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_MSDC_PLUG, MMI_EVENT_INFO, (WCHAR *)get_string(STR_FMGR_CARD_MOUNTING));
    #endif
    #endif
    }
}
#else
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
U8 srv_fmgr_default_storage_need_confirm(void)
{
    return MMI_FALSE;
}

void srv_fmgr_default_storage_do_confirm(void)
{
}
#endif
#ifdef SRV_FMGR_DRV_LSD_SUPPORT
static void srv_fmgri_device_plug_in_hdlr(fmt_mmi_card_plug_in_ind_struct *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Update drive status only */
    srv_fmgri_drv_update_status(msg_ptr->drv_letter, msg_ptr->drv_num, msg_ptr->cause, MMI_TRUE);
}
#endif /* SRV_FMGR_DRV_LSD_SUPPORT */
#endif

#ifdef __OTG_ENABLE__
static void srv_fmgri_otg_display_hdlr(otg_display_struct *msg_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_str_id prompt_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(srv_bootup_is_booting())
        return;

    switch (msg_ptr->type)
    {
        case OTG_DISPLAY_MSG_UN_SUPPORT:
            prompt_str = STR_FMGR_OTG_UNSUPPORT;
            break;
        case OTG_DISPLAY_MSG_CONNECTING:
            prompt_str = STR_FMGR_OTG_CONNECTING;
            break;
        case OTG_DISPLAY_MSG_STOP_CONNECTING:
            prompt_str = STR_FMGR_OTG_STOP_CONNECTING;
            break;
        case OTG_DISPLAY_MSG_NO_RESPONSE:
            prompt_str = STR_FMGR_OTG_NO_RESPONSE;
            break;
        case OTG_DISPLAY_MSG_HNP_PROCESS:
            prompt_str = STR_FMGR_OTG_HNP_PROCESS;
            break;
        case OTG_DISPLAY_MSG_HNP_STOP:
            prompt_str = STR_FMGR_OTG_HNP_STOP;
            break;
        case OTG_DISPLAY_MSG_HUB_NOT_SUPPORT:
            prompt_str = STR_FMGR_OTG_HUB_NOT_SUPPORT;
            break;
        case OTG_DISPLAY_MSG_UN_SUPPORT_CABLE:
            prompt_str = STR_FMGR_OTG_UNSUPPORT_CABLE;
            break;
        default:
            prompt_str = 0;
            break;
    }

    if(prompt_str)
    {
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
        gui_screen_switch_effect_force_block(MMI_TRUE);
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_MSDC_PLUG, MMI_EVENT_INFO, (WCHAR *)get_string(prompt_str));
        gui_screen_switch_effect_force_block(MMI_FALSE);
#else
        mmi_frm_nmgr_popup(MMI_SCENARIO_ID_MSDC_PLUG, MMI_EVENT_INFO, (WCHAR *)get_string(prompt_str));
#endif
    }
}
#endif

S32 srv_fmgri_construct_filter_pattern(const FMGR_FILTER *filter_type, FS_Pattern_Struct* buffer, U32 buffer_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, count = 0, type_count = 0;
    const WCHAR *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(buffer)
        memset(buffer, 0, sizeof(FS_Pattern_Struct)*buffer_count);

    if (FMGR_FILTER_IS_SET(filter_type, FMGR_TYPE_ALL))
    {
        return 0;
    }

    for (i=0; i < FMGR_TYPE_COUNT; i++)
    {
        if (FMGR_FILTER_IS_SET(filter_type, i))
        {
            if(buffer)
            {
                if (i != FMGR_TYPE_FOLDER)
                {
                    ptr = srv_fmgr_types_get_extension_ucs2((filetypes_file_type_enum)i);
                    
                    mmi_wcscpy(buffer[type_count].Pattern, L"*.");
                    if(ptr)
                        mmi_wcscat(buffer[type_count].Pattern, ptr);
                    type_count++;
                }
            }
            
            count++;
            FMGR_ASSERT(!buffer || count <= (S32)buffer_count);
        }
    }
    return count;
}

#if defined(SRV_FMGR_TESTBED_ENABLE) || !defined(__MTK_TARGET__)
void srv_fmgri_write_trace(S32 g, char* format, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const S32   trace_level[] = {TGL1, TGL2};
    va_list     arg_list;
    S32         param_length, i;

    static U8   print_buffer[1024];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_fmgr_ctxt.trace_level > (sizeof(trace_level) / sizeof(S32)))
        g_srv_fmgr_ctxt.trace_level = (sizeof(trace_level) / sizeof(S32));

    for(i=0;i<g_srv_fmgr_ctxt.trace_level;i++)
    {
        if(g == trace_level[i])
            break;
    }
    
    if(i == g_srv_fmgr_ctxt.trace_level)
        return;

    va_start(arg_list, format);
    param_length = vsprintf((void*)print_buffer, format, arg_list);
    FMGR_ASSERT(param_length < 1022);
    print_buffer[param_length] = '\r';
    print_buffer[param_length+1] = '\n';
    param_length+=2;
    print_buffer[param_length] = 0;

#if !defined(__MTK_TARGET__)
    kal_printf(print_buffer);   /* modis, print it */
#endif

#if defined(SRV_FMGR_TESTBED_ENABLE)
    {
        WCHAR       path[20];
        FS_HANDLE   out_fh;

        /* target, write file! */
        kal_wsprintf(path, "%c:\\fmgr.log", SRV_FMGR_PUBLIC_DRV);
        out_fh = FS_Open(path, FS_READ_WRITE | FS_CREATE);
        if(out_fh > 0)
        {
            FS_Seek(out_fh, 0, FS_FILE_END);
            FS_Write(out_fh, print_buffer, param_length, NULL);
            FS_Close(out_fh);
        }
    }
#endif
}
#endif

#if defined(SRV_FMGR_TESTBED_ENABLE)
void    srv_fmgri_set_trace_level(S32 lvl)
{
    g_srv_fmgr_ctxt.trace_level = lvl;
}
#endif

mmi_ret srv_fmgr_ms_handler(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_fmgr_drv_init();    
    return MMI_RET_OK;
}

