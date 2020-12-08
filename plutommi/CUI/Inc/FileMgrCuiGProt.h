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
 *  FileMgrCUIGProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  File Manager CUI exported APIs.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef _FMGR_CUI_GPROT_H_
#define _FMGR_CUI_GPROT_H_

/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "FileMgrSrvGProt.h"
#include "FileMgrGProt.h"
#include "gui_typedef.h"    /* for gui_icon_bar_item_resource_struct */

#include "MenuCuiGProt.h"   /* for menu cui event structure */

#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_rp_file_type_def.h"
/****************************************************************************
* Setting
*****************************************************************************/

/****************************************************************************
* Define
*****************************************************************************/

/* <GROUP Common>
 *  UI style about how to display a list. If not specified, default will be used.
 *  Note. default style may change according to compile option
 *  There are 5 style:
 *    Simple list:  List, each listitem only display basic information
 *    Banner list:  List with banner, each listitem only display basic information, 
 *                  detail information of highlighted item is displayed at banner area
 *    Icon list:    Each listitem display more information (and is larger due to more info)
 *    Expand list:  A combination of simple / icon list, only highlighted item is larger with 
 *                  detail info.
 *                  other item will display basic info as in simple list.
 *    Matrix:       also known as Grid style, there is a NxN area, where each item display as 
 *                  a icon.
 */
typedef enum
{
    CUI_FMGR_UI_STYLE_BANNER_LIST,  /* List with banner, each listitem only display basic 
                                     * information, detail information of highlighted item is 
                                     * displayed at banner area */
    CUI_FMGR_UI_STYLE_ICON_LIST,    /* Each listitem display more information (and is larger due 
                                     * to more info.) */
    CUI_FMGR_UI_STYLE_EXPAND_LIST,  /* A combination of simple / icon list, only highlighted item 
                                     * is larger with detail info. other item will display basic 
                                     * info as in simple list. */
    CUI_FMGR_UI_STYLE_SIMPLE_LIST,  /* List, each listitem only display basic information */
    CUI_FMGR_UI_STYLE_MATRIX,       /* also known as Grid style, there is a NxN area, where each 
                                     * item display as a icon. */

    CUI_FMGR_UI_STYLE_DEFAULT       /* default style, may change according to compile option */
        = CUI_FMGR_UI_STYLE_BANNER_LIST
} cui_fmgr_ui_style_enum;

/****************************************************************************
*
* CUI - Storage selector
*
*****************************************************************************/
/* 
 * Available Option:
 *      n/a
 * Event
 *      Result of selection
 */

/* <GROUP File Selector>
 *  Display drive types of "Storage selector CUI". 
 *  Display drive types affect if removed memory will be displayed
 */
typedef enum
{
    CUI_STORAGE_SELECTOR_DRV_TYPE_ACCESIBLE, /* Display removed memory card */
    CUI_STORAGE_SELECTOR_DRV_TYPE_ACCESIBLE_ONLY, /* Don't display removed memory card */

    /* DOM-NOT_FOR_SDK-BEGIN */
    CUI_STORAGE_SELECTOR_DRV_TYPE_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} cui_storage_selector_drv_type_enum;


/* <GROUP Storage Selector Event>
 *  Here are events that "Stroage selector CUI" will notify to caller.
 */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
#if !defined(__COSMOS_MMI__)
    EVT_ID_CUI_STORAGE_SELECTOR_BEGIN = APP_FILEMANAGER,
#else
    EVT_ID_CUI_STORAGE_SELECTOR_BEGIN = VAPP_FMGR+100,
#endif
    /* DOM-NOT_FOR_SDK-END */
    
    EVT_ID_CUI_STORAGE_SELECTOR_RESULT, /* This event indicate the result of selection.
                                         * There may be 3 situation caller will receive this 
                                         * event:
                                         *      1: User select a storage
                                         *      2: User cancel
                                         *      3: Some error happen (mostly FS error)
                                         * See cui_storage_selector_result_event_struct for more 
                                         * info */
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_STORAGE_SELECTOR_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} cui_storage_selector_event_enum;

/* <GROUP Storage Selector Event>
 *  event structure of EVT_ID_CUI_STORAGE_SELECTOR_RESULT
 */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    
    S32     result;         /* > 0: drive letter user select,
                             * = 0: user cancel,
                             * < 0: error */
       
} cui_storage_selector_result_event_struct;

/* <GROUP Storage Selector>
 * DESCRIPTION
 *  Create an instance of "Storage selector CUI", 
 * PARAMETERS
 *  caller                  : [IN]  group id of caller
 *  default_drive_letter    : [IN]  drive letter to highlight on.
 *  flag                    : [IN]  Display removed memory card of not, see cui_storage_selector_drv_type_enum
 * RETURNS
 *  id of the new created CUI
 */
mmi_id cui_storage_selector_create(mmi_id caller, U8 default_drive_letter, U32 flag);

/* <GROUP Storage Selector>
 * DESCRIPTION
 *  Run function of "Storage selector CUI".
 *  It will display a list of existed storage for user to select
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void   cui_storage_selector_run(mmi_id cui_id);

/* <GROUP Storage Selector>
 * DESCRIPTION
 *  Close function of "Storage selector CUI", 
 *  Caller should be responsible for closing CUI it created.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void   cui_storage_selector_close(mmi_id cui_id);

/* <GROUP Storage Selector>
 * DESCRIPTION
 *  Set title string and title icon of a storage selector CUI
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  string                  : [IN]  new resource id of title string
 *  icon                    : [IN]  new resource id of title icon
 * RETURNS
 *  void
 */
void   cui_storage_selector_set_title(mmi_id cui_id, U16 string, U16 icon);

/* <GROUP Storage Selector>
 * DESCRIPTION
 *  Set display style of a storage selector CUI
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  style                   : [IN]  new style
 * RETURNS
 *  void
 */
void   cui_storage_selector_set_ui_style(mmi_id cui_id, cui_fmgr_ui_style_enum style);

/* <GROUP Storage Selector>
 * DESCRIPTION
 *  Set a userdata of a storage selector CUI, later caller can query using 
 *  cui_storage_selector_get_userdata().
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  userdata                : [IN]  new userdata
 * RETURNS
 *  void
 */
void   cui_storage_selector_set_userdata(mmi_id cui_id, U32 userdata);

/* <GROUP Storage Selector>
 * DESCRIPTION
 *  Get userdata of a storage selector CUI, previous set by cui_storage_selector_get_userdata().
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  an U32 userdata
 */
U32    cui_storage_selector_get_userdata(mmi_id cui_id);

/* <GROUP Storage Selector>
 * DESCRIPTION
 *  Get drive letter of current highlighted storage from a storage selector CUI.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  drive letter of current highlighted storage
 */
WCHAR  cui_storage_selector_get_selected_drive_letter(mmi_id cui_id);

/* <GROUP Storage Selector>
 * DESCRIPTION
 *  set disable ncenter or not.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  value                : [IN]   Set or reset value
 * RETURNS
 *  void
 */
void cui_storage_selector_set_is_disable_ncenter(mmi_id cui_id, MMI_BOOL value);

/****************************************************************************
*
* CUI - Single file selector
*
*****************************************************************************/
/* Available Style:
 *      Select an exist file (read only)
 *      Select an exist file or path (read-only) 
 * Available Option:
 *      Folder traverse: No / Sub-only / ALL
 *      Preview audio file ?
 *      Permission check ?
 *      DRM 2.0 Multipart, treat it as: Folder / File / Not support
 * Event
 *      Result of selection
 * Note:
 *      The select process is read-only, 
 *      User CANNOT modify (rename/create/delete) any folders.
 */

/* <GROUP File Selector>
 *  Styles of "File selector CUI". 
 *  Styles affect major behavior, so it must be assigned during creation, 
 *  and not able to be changed later.
 */
typedef enum
{
    CUI_FILE_SELECTOR_STYLE_FILE_ONLY,          /* Only file can be selected */
    CUI_FILE_SELECTOR_STYLE_FILE_AND_PATH,      /* Both file and folder can be selected */

    /* DOM-NOT_FOR_SDK-BEGIN */
    CUI_FILE_SELECTOR_STYLE_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} cui_file_selector_style_enum;

/* <GROUP File Selector>
 *  Options of "File selector CUI". 
 *  Options also affect CUI's behavior. They are set using cui_file_selector_set_option().
 */
typedef enum
{
    CUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_MASK  = 0x000003, /* Mask of "Folder traversing" option */
    CUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL   = 0x000000, /* All: all folder traversing are 
                                                             * allowed, including enter sub-folder
                                                             * and back to upper folder */
    CUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_SUB   = 0x000001, /* Sub: only sub-folder of starting 
                                                             * folder are allowed to enter. Press 
                                                             * back at starting folder will trigger
                                                             * cancel selection */
    CUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_NONE  = 0x000002, /* None: no folder traversing allowed, 
                                                             * sub-folder is not listed at all. 
                                                             * Press back will trigger cancel 
                                                             * selection */

    CUI_FILE_SELECTOR_OPT_AUDIO_PREVIEW_MASK    = 0x000004, /* Mask of "Audio preview" option */
    CUI_FILE_SELECTOR_OPT_AUDIO_PREVIEW_OFF     = 0x000000, /* Turn audio preview off */
    CUI_FILE_SELECTOR_OPT_AUDIO_PREVIEW_ON      = 0x000004, /* Turn audio preview on, when audio 
                                                             * preview is on, stay at a audio file
                                                             * for a while will trigger audio 
                                                             * play-back. */

    CUI_FILE_SELECTOR_OPT_DRM_CHECK_MASK        = 0x000030, /* Mask of "DRM permission check" */
    CUI_FILE_SELECTOR_OPT_DRM_CHECK_SEND_OFF    = 0x000000, /* Turn DRM sendable check off */
    CUI_FILE_SELECTOR_OPT_DRM_CHECK_SEND_ON     = 0x000010, /* Turn DRM sendable check on, when it 
                                                             * is on, non-sendable(non-forwardable)
                                                             * file cannot be selected */
    CUI_FILE_SELECTOR_OPT_DRM_CHECK_SET_OFF     = 0x000000, /* Turn DRM setable check off */
    CUI_FILE_SELECTOR_OPT_DRM_CHECK_SET_ON      = 0x000020, /* Turn DRM setable check on, when it 
                                                             * is on, non-setable (non-usable)
                                                             * file cannot be selected */

    CUI_FILE_SELECTOR_OPT_FIXED_PATH_MASK       = 0x000040, /* Mask of "Fixed path" option */
    CUI_FILE_SELECTOR_OPT_FIXED_PATH_OFF        = 0x000000, /* Turn fixed path off */
    CUI_FILE_SELECTOR_OPT_FIXED_PATH_ON         = 0x000040, /* Turn fixed path on. In some project, 
                                                             * the start folder will be overwritten 
                                                             * to a pre-define value. Turn on this
                                                             * option can keep start folder from 
                                                             * being overwritten. */
    
    CUI_FILE_SELECTOR_OPT_ARCHIVE_MASK          = 0x000F00, /* Mask of "Archive" option */
    CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FILE       = 0x000000, /* File: During selection, treat archive 
                                                             * as a single file. User can select 
                                                             * this archive */
    CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FOLDER     = 0x000100, /* Folder: During selection, treat 
                                                             * archive as a sub-folder. It can be 
                                                             * entered or selected as folder */
    CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_UNKNOWN    = 0x000200, /* Unknown: Ignore archive file, 
                                                             * There will be no option if highlight
                                                             * on it. */

    /* DOM-NOT_FOR_SDK-BEGIN */
    CUI_FILE_SELECTOR_OPT_END
    /* DOM-NOT_FOR_SDK-END */
} cui_file_selector_option_enum;

/* <GROUP File Selector Event>
 *  Here are events that "File selector CUI" will notify to caller.
 */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_FILE_SELECTOR_BEGIN = EVT_ID_CUI_STORAGE_SELECTOR_TOTAL,
    /* DOM-NOT_FOR_SDK-END */
    
    EVT_ID_CUI_FILE_SELECTOR_RESULT,    /* This event indicate the result of selection.
                                         * There may be 3 situation caller will receive this event:
                                         *      1: User select a file or folder
                                         *      2: User cancel
                                         *      3: Some error happen (mostly FS error)
                                         * See cui_file_selector_result_event_struct for more info */
#ifdef __GAIN_TABLE_SUPPORT__
    EVT_ID_CUI_FILE_SELECTOR_PREVIEW_START, /* Preview is going to start, cui_file_selector_preview_struct */
    EVT_ID_CUI_FILE_SELECTOR_PREVIEW_STOP, /*Preview is stopped, cui_file_selector_preview_struct */
#endif
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_FILE_SELECTOR_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} cui_file_selector_event_enum;


/* <GROUP File Selector Event> 
 *  event structure of EVT_ID_CUI_FILE_SELECTOR_RESULT
 */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    S32     result;         /* > 0: user selected a path, use cui_file_selector_get_selected_filepath() 
                             *      to query,
                             * = 0: user cancel,
                             * < 0: FS error */

} cui_file_selector_result_event_struct;

#ifdef __GAIN_TABLE_SUPPORT__
/* event structure for EVT_ID_CUI_FILE_SELECTOR_PREVIEW_START & EVT_ID_CUI_FILE_SELECTOR_PREVIEW_STOP */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
} cui_file_selector_preview_struct; 
#endif

/* <GROUP File Selector>
 * DESCRIPTION
 *  Create an instance of "File selector CUI", 
 *  Allow user to select a file or a folder for reading.
 * PARAMETERS
 *  caller                  : [IN]  group id of caller
 *  start_path              : [IN]  the starting path of selection, L"root" can also be used to 
 *                                  start from root.
 *  filter                  : [IN]  filter is used to list only prefered type of files, for 
 *                                  example, images only.
 *  style                   : [IN]  style of CUI, see cui_file_selector_style_enum
 *  option_flag             : [IN]  option of CUI, see cui_file_selector_option_enum
 * RETURNS
 *  id of the new created CUI
 */
mmi_id cui_file_selector_create(mmi_id caller, const WCHAR* start_path, const FMGR_FILTER* filter, 
                                cui_file_selector_style_enum style, U32 option_flag);

/* <GROUP File Selector>
 * DESCRIPTION
 *  Run function of "File selector CUI".
 *  Allow user to select a file or a folder for reading.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void   cui_file_selector_run(mmi_id cui_id);

/* <GROUP File Selector>
 * DESCRIPTION
 *  Close function of "File selector CUI", 
 *  Caller should be responsible for closing CUI it created.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void   cui_file_selector_close(mmi_id cui_id);

/* <GROUP File Selector>
 * DESCRIPTION
 *  Set title string and title icon of a file selector CUI
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  string                  : [IN]  new resource id of title string
 *  icon                    : [IN]  new resource id of title icon
 * RETURNS
 *  void
 */
void   cui_file_selector_set_title(mmi_id cui_id, U16 string, U16 icon);

/* <GROUP File Selector>
 * DESCRIPTION
 *  Modify option of a file selector CUI
 *  see also cui_file_selector_option_enum.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  option_mask             : [IN]  indicate option to be modifed
 *  option_value            : [IN]  indicate new option value
 * RETURNS
 *  void
 */
void   cui_file_selector_set_option(mmi_id cui_id, U32 option_mask, U32 option_value);

/* <GROUP File Selector>
 * DESCRIPTION
 *  Set display style of a file selector CUI
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  style                   : [IN]  new ui style
 * RETURNS
 *  void
 */
void   cui_file_selector_set_ui_style(mmi_id cui_id, cui_fmgr_ui_style_enum style);

/* <GROUP File Selector>
 * DESCRIPTION
 *  Set a userdata of a file selector CUI, later caller can query using 
 *  cui_file_selector_get_userdata().
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  userdata                : [IN]  new userdata
 * RETURNS
 *  void
 */
void   cui_file_selector_set_userdata(mmi_id cui_id, U32 userdata);

/* <GROUP File Selector>
 * DESCRIPTION
 *  Get userdata of a file selector CUI, previous set by cui_file_selector_set_userdata().
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  an U32 userdata
 */
U32    cui_file_selector_get_userdata(mmi_id cui_id);

/* <GROUP File Selector>
 * DESCRIPTION
 *  Get a pointer to the current path of a file selector CUI.
 *  The buffer belongs to this CUI, is read-only, and will become invalid if CUI dies.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  pointer to current path 
 */
const WCHAR* cui_file_selector_get_folder(mmi_id cui_id);

/* <GROUP Obsolete>
 * DESCRIPTION
 *  Query more information of current selected file/folder from a file selector CUI.
 *  Including file information and full filepath.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  info                    : [OUT] a pointer to file info. structure. Can not be NULL.
 *                                  It will be reset if there is any error to prevent mis-usage.
 *  path_buffer             : [OUT] buffer to store full filepath of selected file/folder
 *  path_size               : [IN]  size of path_buffer, in bytes, including null terminated.
 * RETURNS
 *  Refer to FS error, ok if == 0, error if < 0.
 */
S32    cui_file_selector_get_selected_filepath_old(mmi_id cui_id, FMGR_FILE_INFO_STRUCT* info, 
                                               WCHAR* path_buffer, S32 path_size);

/* <GROUP File Selector>
 * DESCRIPTION
 *  Query more information of current selected file/folder from a file selector CUI.
 *  Including file information and full filepath.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  info                    : [OUT] a pointer to file info. structure. Can not be NULL.
 *                                  It will be reset if there is any error to prevent mis-usage.
 *  path_buffer             : [OUT] buffer to store full filepath of selected file/folder
 *  path_size               : [IN]  size of path_buffer, in bytes, including null terminated.
 * RETURNS
 *  Refer to FS error, ok if == 0, error if < 0.
 */
S32    cui_file_selector_get_selected_filepath(mmi_id cui_id, srv_fmgr_fileinfo_struct* info, 
                                               WCHAR* path_buffer, S32 path_size);


/****************************************************************************
*
* CUI - Folder selector
*
*****************************************************************************/

/* Available Style:
 *      Select an folder for read
 *      Select an folder for write, user can create / rename / delete sub-folders
 * Available Option:
 *      Folder traverse: No / Sub-only / ALL
 * Event
 *      Result of selection
 */

/* <GROUP Folder Selector>
 *  Styles of "Folder selector CUI". 
 *  Styles affect major behavior, so it must be assigned during creation, 
 *  and not able to be changed later.
 */
typedef enum
{
    CUI_FOLDER_SELECTOR_STYLE_READ,     /* Select a folder for reading data from. During 
                                         * selection, User cannot modify file system, such as
                                         * folder creation / renaming / deletion */
    CUI_FOLDER_SELECTOR_STYLE_WRITE,    /* Select a folder for writing data to. During selection,
                                         * User can create / rename / delete any sub-folder */

    /* DOM-NOT_FOR_SDK-BEGIN */
    CUI_FOLDER_SELECTOR_STYLE_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} cui_folder_selector_style_enum;

/* <GROUP Folder Selector>
 *  Options of "Folder selector CUI". 
 *  Options also affect CUI's behavior. They are set using cui_folder_selector_set_option().
 */
typedef enum
{
    CUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_MASK  = 0x00000F,   /* Mask of "Folder traversing" option */
    CUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_ALL   = 0x000000,   /* All: all folder traversing are 
                                                                 * allowed, including enter sub-folder
                                                                 * and back to upper folder */
    CUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_SUB   = 0x000001,   /* Sub: only sub-folder of starting 
                                                                 * folder are allowed to enter. Press 
                                                                 * back at starting folder will trigger
                                                                 * cancel selection */
    CUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_NONE  = 0x000002,   /* None: no folder traversing allowed, 
                                                                 * sub-folder is not listed at all. 
                                                                 * Press back will trigger cancel 
                                                                 * selection */

    CUI_FOLDER_SELECTOR_OPT_FIXED_PATH_MASK       = 0x000040,   /* Mask of "Fixed path" option */
    CUI_FOLDER_SELECTOR_OPT_FIXED_PATH_OFF        = 0x000000,   /* Turn fixed path off */
    CUI_FOLDER_SELECTOR_OPT_FIXED_PATH_ON         = 0x000040,   /* Turn fixed path on. In some project, 
                                                                 * the start folder will be overwritten 
                                                                 * to a pre-define value. Turn on this
                                                                 * option can keep start folder from 
                                                                 * being overwritten. */

    /* DOM-NOT_FOR_SDK-BEGIN */
    CUI_FOLDER_SELECTOR_OPT_END
    /* DOM-NOT_FOR_SDK-END */
} cui_folder_selector_option_enum;

/* <GROUP Folder Selector Event>
 *  Here are events that "Folder selector CUI" will notify to caller.
 */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_FOLDER_SELECTOR_BEGIN = EVT_ID_CUI_FILE_SELECTOR_TOTAL,
    /* DOM-NOT_FOR_SDK-END */
    
    EVT_ID_CUI_FOLDER_SELECTOR_RESULT,  /* This event indicate the result of selection.
                                         * There may be 3 situation caller will receive this event:
                                         *      1: User select a folder
                                         *      2: User cancel
                                         *      3: Some error happen (mostly FS error)
                                         * See cui_folder_selector_result_event_struct for more info */

    EVT_ID_CUI_FOLDER_SELECTOR_BEFORE_ERROR_HANDLE,
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_FOLDER_SELECTOR_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} cui_folder_selector_event_enum;

/* <GROUP Folder Selector Event>
 * event structure of EVT_ID_CUI_FOLDER_SELECTOR_RESULT  */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    S32     result;         /* > 0: user selected a path, use cui_folder_selector_get_selected_filepath() 
                             *      to query,
                             * = 0: user cancel,
                             * < 0: FS error */

} cui_folder_selector_result_event_struct;

/* <GROUP Folder Selector>
 * DESCRIPTION
 *  Create an instance of "Folder selector CUI", 
 *  Allow user to select a folder for reading/writing.
 * PARAMETERS
 *  caller                  : [IN]  group id of caller
 *  start_path              : [IN]  the starting path of selection, L"root" can also be used to start 
 *                                  from root.
 *  style                   : [IN]  style of CUI, see cui_folder_selector_style_enum
 *  option_flag             : [IN]  option of CUI, see cui_folder_selector_option_enum
 * RETURNS
 *  id of the new created CUI
 */
mmi_id cui_folder_selector_create(mmi_id caller, const WCHAR* start_path, 
                                  cui_folder_selector_style_enum style, U32 option_flag);
/* <GROUP Folder Selector>
 * DESCRIPTION
 *  Run function of "Folder selector CUI".
 *  Allow user to select a folder for read/write.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void   cui_folder_selector_run(mmi_id cui_id);

/* <GROUP Folder Selector>
 * DESCRIPTION
 *  Close function of "Folder selector CUI", 
 *  Caller should be responsible for closing CUI it created.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void   cui_folder_selector_close(mmi_id cui_id);

/* <GROUP Folder Selector>
 * DESCRIPTION
 *  Set title string and title icon of a folder selector CUI
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  string                  : [IN]  new resource id of title string
 *  icon                    : [IN]  new resource id of title icon
 * RETURNS
 *  void
 */
void   cui_folder_selector_set_title(mmi_id cui_id, U16 string, U16 icon);

/* <GROUP Folder Selector>
 * DESCRIPTION
 *  Modify option of a folder selector CUI
 *  see also cui_folder_selector_option_enum.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  option_mask             : [IN]  indicate option to be modifed
 *  option_value            : [IN]  indicate new option value
 * RETURNS
 *  void
 */
void   cui_folder_selector_set_option(mmi_id cui_id, U32 option_mask, U32 option_value);

/* <GROUP Folder Selector>
 * DESCRIPTION
 *  Set display style of a folder selector CUI
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  style                   : [IN]  new ui style
 * RETURNS
 *  void
 */
void   cui_folder_selector_set_ui_style(mmi_id cui_id, cui_fmgr_ui_style_enum style);

/* <GROUP Folder Selector>
 * DESCRIPTION
 *  Set a userdata of a folder selector CUI, later caller can query using 
 *  cui_folder_selector_get_userdata().
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  userdata                : [IN]  new userdata
 * RETURNS
 *  void
 */
void   cui_folder_selector_set_userdata(mmi_id cui_id, U32 userdata);

/* <GROUP Folder Selector>
 * DESCRIPTION
 *  Get userdata of a folder selector CUI, previous set by cui_folder_selector_set_userdata().
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  an U32 userdata
 */
U32    cui_folder_selector_get_userdata(mmi_id cui_id);

/* <GROUP Folder Selector>
 * DESCRIPTION
 *  Get a pointer to the current path of a folder selector CUI.
 *  The buffer belongs to this CUI, is read-only, and will become invalid if CUI dies.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  pointer to current path 
 */
const WCHAR* cui_folder_selector_get_folder(mmi_id cui_id);

/* <GROUP Obsolete>
 * DESCRIPTION
 *  Query more information of current selected folder from a folder selector CUI.
 *  Including file information and full filepath.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  info                    : [OUT] a pointer to file info. structure. Can not be NULL.
 *                                  It will be reset if there is any error to prevent mis-usage.
 *  path_buffer             : [OUT] buffer to store full filepath of selected folder
 *  path_size               : [IN]  size of path_buffer, in bytes, including null terminated.
 * RETURNS
 *  Refer to FS error, ok if == 0, error if < 0.
 */
S32    cui_folder_selector_get_selected_filepath_old(mmi_id cui_id, FMGR_FILE_INFO_STRUCT* info, WCHAR* path_buffer, S32 path_size);

/* <GROUP Folder Selector>
 * DESCRIPTION
 *  Query more information of current selected folder from a folder selector CUI.
 *  Including file information and full filepath.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  info                    : [OUT] a pointer to file info. structure. Can not be NULL.
 *                                  It will be reset if there is any error to prevent mis-usage.
 *  path_buffer             : [OUT] buffer to store full filepath of selected folder
 *  path_size               : [IN]  size of path_buffer, in bytes, including null terminated.
 * RETURNS
 *  Refer to FS error, ok if == 0, error if < 0.
 */
S32    cui_folder_selector_get_selected_filepath(mmi_id cui_id, srv_fmgr_fileinfo_struct* info, WCHAR* path_buffer, S32 path_size);
/****************************************************************************
*
* CUI - Browse
*
*****************************************************************************/

/* 
 * Available Option:
 *      Display type
 *      LSK setting: string, handler, menu
 *      DRM 2.0 Multipart, treat it as: Folder / File / Not support
 *      Custom CSK: Send option
 * Event
 *      On entry, On exit, On destory, On softkey, On menuitem
 */

/* <GROUP Folder Browser>
 *  Options of "Folder browser CUI". 
 *  Options also affect CUI's behavior. They are set using cui_folder_browser_set_option().
 */
typedef enum
{
    CUI_FOLDER_BROWSER_OPT_FAST_FORWARD_MASK    = 0x0000F0, /* Mask of "Fast forward" option */
    CUI_FOLDER_BROWSER_OPT_FAST_FORWARD_OFF     = 0x000000, /* Off: Send key has no function*/
    CUI_FOLDER_BROWSER_OPT_FAST_FORWARD_ON      = 0x000010, /* On: Send key will bring up Send option menu */

    CUI_FOLDER_BROWSER_OPT_ARCHIVE_MASK         = 0x000F00, /* Mask of "Archive" option */
    CUI_FOLDER_BROWSER_OPT_ARCHIVE_AS_FILE      = 0x000000, /* File: During browsing, treat archive 
                                                             * as a single file. User can operation 
                                                             * this archive */
    CUI_FOLDER_BROWSER_OPT_ARCHIVE_AS_UNKNOWN   = 0x000200, /* Unknown: Ignore archive file, 
                                                             * There will be no option if highlight
                                                             * on it. */
                                                             
    CUI_FOLDER_BROWSER_OPT_USE_CSK_MASK         = 0x00000F, /* CSK handling */
    CUI_FOLDER_BROWSER_OPT_USE_CSK_OFF          = 0x000000, /* Off: Normal behavior */
    CUI_FOLDER_BROWSER_OPT_USE_CSK_ON           = 0x000001, /* On: When press CSK, send event to caller */

    /* DOM-NOT_FOR_SDK-BEGIN */
    CUI_FOLDER_BROWSER_OPT_END
    /* DOM-NOT_FOR_SDK-END */
} cui_folder_browser_option_enum;

/* <GROUP Folder Browser Event>
 *  Here are events that "Folder browser CUI" will notify to caller.
 */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_FOLDER_BROWSER_BEGIN = EVT_ID_CUI_FOLDER_SELECTOR_TOTAL,
    /* DOM-NOT_FOR_SDK-END */
    
    EVT_ID_CUI_FOLDER_BROWSER_ON_ENTRY,    /* Caller will receive this event before entrying
                                            * (displaying) file-list, some data preparation
                                            * can be done here.
                                            * also see cui_folder_browser_on_entry_event_struct. */
    EVT_ID_CUI_FOLDER_BROWSER_ON_EXIT,     /* Caller will receive this event before exiting
                                            * file-list screen, some data clean-up can be done
                                            * here.
                                            * also see cui_folder_browser_on_exit_event_struct */
    EVT_ID_CUI_FOLDER_BROWSER_ON_QUIT,     /* Caller will receive this event when:
                                            *   1: Canceled by user
                                            *   2: There are error
                                            * also see cui_folder_browser_on_quit_event_struct */
    EVT_ID_CUI_FOLDER_BROWSER_ON_EMPTY,    /* Caller will receive this event when empty LSK is set
                                            * and user press LSK when there is no files (list is 
                                            * empty).
                                            * also see cui_folder_browser_on_empty_event_struct and
                                              cui_folder_browser_set_empty_lsk() */
    EVT_ID_CUI_FOLDER_BROWSER_ON_MENU,     /* Caller will receive this event when user choose 
                                            * any option and can stop CUI handling by returning
                                            * MMI_RET_ERR.
                                            * Using this event, caller can do customized behavior.
                                            * also see cui_folder_browser_on_menu_event_struct */
    EVT_ID_CUI_FOLDER_BROWSER_ON_CSK,      /* Caller will receive this event when 
                                            * 1. USE_CSK flag is ON
                                            * 2. User press CSK
                                            * Using this event, caller can do customized behavior.
                                            * also see cui_folder_browser_on_csk_event_struct */

    EVT_ID_CUI_FOLDER_BROWSER_ON_OPTION,   /* Caller will receive this event when user entry option menu.
                                            * According to parent_menu_id, caller can set attribute for
                                            * the parent_menu_id's child. Ex: radio button flag. */
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_FOLDER_BROWSER_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} cui_folder_browser_event_enum;

/* <GROUP Folder Browser Event>
 *  event structure of EVT_ID_CUI_FOLDER_BROWSER_ON_ENTRY, EVT_ID_CUI_FOLDER_BROWSER_ON_EXIT, 
    EVT_ID_CUI_FOLDER_BROWSER_ON_EMPTY  */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

} cui_folder_browser_on_entry_event_struct, cui_folder_browser_on_exit_event_struct, 
  cui_folder_browser_on_empty_event_struct, cui_folder_browser_on_csk_event_struct;

/* <GROUP Folder Browser Event>
 *  event structure of EVT_ID_CUI_FOLDER_BROWSER_ON_QUIT  */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    S32     quit_reason;            /* 0 for user cancel, < 0 for FS error */

} cui_folder_browser_on_quit_event_struct;

/* <GROUP Folder Browser Event>
 *  event structure of EVT_ID_CUI_FOLDER_BROWSER_ON_MENU  */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    U16     menuitem_id;            /* id of item user just chose */
    
} cui_folder_browser_on_menu_event_struct;

/* <GROUP Folder Browser Event>
 * DESCRIPTION 
 *  event structure of EVT_ID_CUI_FOLDER_BROWSER_ON_OPTION
 *  
 * PARAMETERS
 *  menu_cui_id             : [IN]  id of menu CUI
 *  file_path               : [IN]  current file path
 *  file_name               : [IN]  current highlighted file naem. It may be NULL, ex: empty folder.
 *  file_info               : [IN]  info of highlighted file.
 *  menu_cui_evt            : [IN]  complete menu cui event.
 */

typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    mmi_id                    menu_cui_id;
    const WCHAR*              file_path;
    const WCHAR*              file_name;
    srv_fmgr_fileinfo_struct* file_info;
    cui_menu_event_struct*    menu_cui_evt;
} cui_folder_browser_on_option_event_struct;
/*****************************************************************************
 * FUNCTION
 *  cui_folder_browser_launch
 * DESCRIPTION
 *  Launch a folder browser.
 * PARAMETERS
 *  parent_id        : [IN] group id of parent    
 *  base_path        : [IN] start folder 
 *  filter           : [IN] only matched files are displayed
 *  option_flag      : [IN] option of CUI, see cui_folder_browser_option_enum
 *  title_str_id     : [IN] title string id
 *  title_icon_id    : [IN] title icon id
 * RETURN VALUES
 * MMI_BOOL            : [OUT] Launch OK or not
 *****************************************************************************/
MMI_BOOL cui_folder_browser_launch(mmi_id parent_id, const WCHAR* base_path, const FMGR_FILTER* filter, U32 option_flag,
                                 U16 title_str_id, U16 title_icon_id);
/* <GROUP Folder Browser>
 * DESCRIPTION
 *  Create an instance of "Folder browser CUI", 
 *  Provide a file list screen and allow caller manage files in a specified folder
 *  Ex. Image viewer, Ebook, Video player
 * PARAMETERS
 *  caller                  : [IN]  group id of caller
 *  folder_path             : [IN]  the starting path of selection, L"root" can also be used to 
 *                                  start from root.
 *  filter                  : [IN]  filter is used to list only prefered type of files, for 
 *                                  example, images only.
 *  option_flag             : [IN]  option of CUI, see cui_folder_browser_option_enum
 *  opt_menu                : [IN]  option to be displayed while user press LSK on any file
 *  opt_menu_empty          : [IN]  option to be displayed while user press LSK when there is no 
 *                                  files (list empty)
 * RETURNS
 *  id of the new created CUI
 */
mmi_id cui_folder_browser_create(mmi_id caller, const WCHAR* folder_path, const FMGR_FILTER* filter, 
                                  U32 option_flag, U16 opt_menu, U16 opt_menu_empty);
/* <GROUP Folder Browser>
 * DESCRIPTION
 *  Run function of "Folder browser CUI".
 *  Provide a file list screen and allow caller manage files in a specified folder
 *  Ex. Image viewer, Ebook, Video player
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  MMI_BOOL
 */
MMI_BOOL   cui_folder_browser_run(mmi_id cui_id);

/* <GROUP Folder Browser>
 * DESCRIPTION
 *  Close function of "Folder browser CUI", 
 *  Caller should be responsible for closing CUI it created.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void   cui_folder_browser_close(mmi_id cui_id);

/* <GROUP Folder Browser>
 * DESCRIPTION
 *  Set title string and title icon of a folder browser CUI
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  string                  : [IN]  new resource id of title string
 *  icon                    : [IN]  new resource id of title icon
 * RETURNS
 *  void
 */
void   cui_folder_browser_set_title(mmi_id cui_id, U16 string, U16 icon);

/* <GROUP Folder Browser>
 * DESCRIPTION
 *  Modify option of a folder browser CUI.
 *  see also cui_folder_browser_option_enum.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  option_mask             : [IN]  indicate option to be modifed
 *  option_value            : [IN]  indicate new option value
 * RETURNS
 *  void
 */
void   cui_folder_browser_set_option(mmi_id cui_id, U32 option_mask, U32 option_value);

/* <GROUP Folder Browser>
 * DESCRIPTION
 *  Set display style of a folder browser CUI
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  style                   : [IN]  new ui style
 * RETURNS
 *  void
 */
void   cui_folder_browser_set_ui_style(mmi_id cui_id, cui_fmgr_ui_style_enum style);

/* <GROUP Folder Browser>
 * DESCRIPTION
 *  Set a userdata of a folder browser CUI, later caller can query using 
 *  cui_folder_browser_get_userdata().
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  userdata                : [IN]  new userdata
 * RETURNS
 *  void
 */
void   cui_folder_browser_set_userdata(mmi_id cui_id, U32 userdata);

/* <GROUP Folder Browser>
 * DESCRIPTION
 *  Get userdata of a folder browser CUI, previous set by cui_folder_browser_set_userdata().
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  an U32 userdata
 */
U32    cui_folder_browser_get_userdata(mmi_id cui_id);

/* <GROUP Folder Browser>
 * DESCRIPTION
 *  Ask a folder browser CUI to change folder, to list files at another folder
 *  The CUI will refresh if it is at foreground.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  new_path                : [IN]  new folder path
 * RETURNS
 *  void
 */
void   cui_folder_browser_set_folder_path(mmi_id cui_id, const WCHAR* new_path);

/* <GROUP Folder Browser>
 * DESCRIPTION
 *  Ask a folder browser CUI to change highlight item.
 *  The CUI will refresh if it is at foreground.
 *  If the new index is out of range, it will fail and do nothing
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  new_index               : [IN]  new highlight item
 * RETURNS
 *  void
 */
void   cui_folder_browser_set_highlight_index(mmi_id cui_id, S32 new_index);

/* <GROUP Folder Browser>
 * DESCRIPTION
 *  Set "empty LSK" of a folder browser CUI. Empty LSK will be displayed when there is no 
 *  files (list is empty).
 *  If empty LSK is set (not 0), CUI will notify caller EVT_ID_CUI_FOLDER_BROWSER_ON_EMPTY
 *  when user click LSK, so caller can customized the behavior
 *  The decision order for LSK behavior when empty is:
 *    1. If empty LSK is set, notify EVT_ID_CUI_FOLDER_BROWSER_ON_EMPTY
 *    2. If empty LSK is not set, and opt_menu_empty is not 0, display opt_menu_empty option
 *    3. Both empty LSK and opt_menu_empty is 0, hide LSK
 *  The CUI will refresh if it is at foreground and there is no files.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  string                  : [IN]  resource id of new LSK string
 *  icon                    : [IN]  resource id of new LSK icon
 * RETURNS
 *  void
 */
void   cui_folder_browser_set_empty_lsk(mmi_id cui_id, U16 string, U16 icon);

/* <GROUP Folder Browser>
 * DESCRIPTION
 *  get index of current highlighted file of a folder browser CUI.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  highlighted index, -1 means there is no files at all
 */
S32    cui_folder_browser_get_highlight_index(mmi_id cui_id);

/* <GROUP Folder Browser>
 * DESCRIPTION
 *  get total file count of a folder browser CUI.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  return file count if >= 0, FS error if < 0
 */
S32    cui_folder_browser_get_total_count(mmi_id cui_id);

/* <GROUP Obsolete>
 * DESCRIPTION
 *  Query information of N-th file from a folder browser CUI
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  index                   : [IN]  which file to query
 *  info                    : [OUT] a pointer to file info. structure. Can not be NULL.
 *                                  It will be reset if there is any error to prevent mis-usage.
 * RETURNS
 *  Refer to FS error, ok if == 0, error if < 0.
 */
S32    cui_folder_browser_get_file_info_old(mmi_id cui_id, S32 index, FMGR_FILE_INFO_STRUCT* info);

/* <GROUP Folder Browser>
 * DESCRIPTION
 *  Query information of N-th file from a folder browser CUI
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  index                   : [IN]  which file to query
 *  info                    : [OUT] a pointer to file info. structure. Can be NULL.
 *                                  It will be reset if there is any error to prevent mis-usage.
 *  path_buffer             : [OUT] buffer to store full filepath of selected folder
 *  path_size               : [IN]  size of path_buffer, in bytes, including null terminated.
 * RETURNS
 *  Refer to FS error, ok if == 0, error if < 0.
 */
S32    cui_folder_browser_get_filepath(mmi_id cui_id, S32 index, srv_fmgr_fileinfo_struct* info, WCHAR* path_buffer, S32 path_size);

/* <GROUP Folder Browser>
 * DESCRIPTION
 *  Lock and retrieve filelist of a folder browser CUI. Caller can use file list related API to 
 *  query all file information in this list.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  fl_hdl                  : [OUT] locked file list.
 *  cur_index               : [OUT] current highlight index
 * RETURNS
 *  Refer to FS error, ok if == 0, error if < 0.
 */
S32    cui_folder_browser_lock_filelist(mmi_id cui_id, SRV_FMGR_FILELIST_HANDLE *fl_hdl, S32* cur_index);

/* <GROUP Folder Browser>
 * DESCRIPTION
 *  Unlock filelist of a folder browser CUI, previous handle get by cui_folder_browser_lock_filelist 
 *  is invalid.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  Refer to FS error, ok if == 0, error if < 0.
 */
S32    cui_folder_browser_unlock_filelist(mmi_id cui_id);

/* <GROUP Folder Browser>
 * DESCRIPTION
 *  Check if the filelist is locked
 *  is invalid.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  MMI_BOOL, MMI_TRUE means locked, MMI_FALSE means unlocked
 */
MMI_BOOL    cui_folder_browser_is_filelist_locked(mmi_id cui_id);

/* <GROUP Folder Browser>
 * DESCRIPTION
 *  Enable toolbar support of a folder browser CUI.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  btn_menus               : [IN]  array of button menu id
 *  btn_resources           : [IN]  array of button resources
 *  btn_count               : [IN]  button count
 * RETURNS
 *  0 if succeed, MMI_FMGR_ERROR_INVALID_PARAM if there is error
 */
S32    cui_folder_browser_set_toolbar(mmi_id cui_id, const mmi_menu_id* btn_menus, const gui_icon_bar_item_resource_struct* btn_resources, U16 btn_count);


/****************************************************************************
*
* CUI - File option
*
*****************************************************************************/
/* Available Style:
 *      DLA use
 * Available Option:
 *      n/a
 * Event
 *      n/a
 */

/* <GROUP File Option>
 *  Options of "File option CUI". 
 *  Options also affect CUI's behavior.
 */
typedef enum
{
    CUI_FILE_OPTION_OPT_FUNC_MASK       = 0x00000F, /* Mask of Function option */ 
    CUI_FILE_OPTION_OPT_FUNC_MAIN       = 0x000000, /* Show main option, such as "View/Play/Open" */
    CUI_FILE_OPTION_OPT_FUNC_SEND       = 0x000001, /* Show "Send via" option */
    CUI_FILE_OPTION_OPT_FUNC_SET        = 0x000002, /* Show "Set as" option */
    CUI_FILE_OPTION_OPT_FUNC_OTHER      = 0x000004, /* Show other option, such as Delete / Detail */

    /* DOM-NOT_FOR_SDK-BEGIN */
    CUI_FILE_OPTION_OPT_END
    /* DOM-NOT_FOR_SDK-END */
} cui_file_option_option_enum;
 
/* <GROUP File Option Event>
 *  Here are events that "File option CUI" will notify to caller.
 */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_FILE_OPTION_BEGIN = EVT_ID_CUI_FOLDER_BROWSER_TOTAL,
    /* DOM-NOT_FOR_SDK-END */

    EVT_ID_CUI_FILE_OPTION_ON_QUIT,     /* Caller will receive this event when:
                                         *      1: Canceld by user
                                         *      2: There are error
                                         * also see cui_file_option_on_quit_event_struct */
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_FILE_OPTION_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} cui_file_option_event_enum;

/* <GROUP File Option Event>
 *  event structure of EVT_ID_CUI_FILE_OPTION_ON_QUIT  */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    S32     result;         /* = 0: user cancel,
                             * < 0: FS error, such as File not found */

} cui_file_option_on_quit_event_struct;

/* <GROUP File Option>
 * DESCRIPTION
 *  Create an instance of "File option CUI", 
 *  Provide a file option screen with available functions of a file type
 *  These functions include: "View/Play/Install", "Send via", "Use as", "Delete", etc...
 * PARAMETERS
 *  caller                  : [IN]  group id of caller
 *  file_path               : [IN]  fullpath of file, CUI will use name / content of this file to 
 *                                  determine if option is aviable or not.
 *  option_flag             : [IN]  option of CUI, see cui_file_option_option_enum
 * RETURNS
 *  id of the new created CUI
 */
mmi_id cui_file_option_create(mmi_id caller, const WCHAR* file_path, U32 option_flag);

/* <GROUP File Option>
 * DESCRIPTION
 *  Create an instance of "File option CUI", 
 *  Provide a file option screen with available functions of a file type
 *  These functions include: "View/Play/Install", "Send via", "Use as", "Delete", etc...
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void   cui_file_option_run(mmi_id cui_id);

/* <GROUP File Option>
 * DESCRIPTION
 *  Close function of "File option CUI", 
 *  Caller should be responsible for closing CUI it created.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void   cui_file_option_close(mmi_id cui_id);

/* <GROUP File Option>
 * DESCRIPTION
 *  Set title string and title icon of a file option CUI
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  string                  : [IN]  new resource id of title string
 *  icon                    : [IN]  new resource id of title icon
 * RETURNS
 *  void
 */
void   cui_file_option_set_title(mmi_id cui_id, U16 string, U16 icon);

/* <GROUP File Option>
 * DESCRIPTION
 *  Set a userdata of a file option CUI, later caller can query using 
 *  cui_file_option_set_userdata().
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  userdata                : [IN]  new userdata
 * RETURNS
 *  void
 */
void   cui_file_option_set_userdata(mmi_id cui_id, U32 userdata);

/* <GROUP File Option>
 * DESCRIPTION
 *  Get userdata of a folder browser CUI, previous set by cui_file_option_set_userdata().
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  an U32 userdata
 */
U32    cui_file_option_get_userdata(mmi_id cui_id);

/* <GROUP File Option>
 * DESCRIPTION
 *  Set application id of a file option CUI, CUI will use also use this information to 
 *  determine any option is avaible or not.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  app_id                  : [IN]  application id
 * RETURNS
 *  void
 */
void   cui_file_option_set_app(mmi_id cui_id, U16 app_id);

/* <GROUP File Option>
 * DESCRIPTION
 *  Utility for user to check first if there is any option for the file
 * PARAMETERS
*  file_path               : [IN]  fullpath of file 
 * RETURNS
 *  MMI_BOOL
 */
MMI_BOOL   cui_file_option_is_any_option(const WCHAR* file_path);

/****************************************************************************
*
* CUI - Filename editor
*
*****************************************************************************/

/* <GROUP Filename Editor Event>
 *  Here are events that "Filename editor CUI" will notify to caller.
 */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_FILENAME_EDITOR_BEGIN = EVT_ID_CUI_FILE_OPTION_TOTAL,
    /* DOM-NOT_FOR_SDK-END */

    EVT_ID_CUI_FILENAME_EDITOR_RESULT,  /* Caller will receive this event when:
                                         *      1: result > 0, User complete the editing
                                         *      2: result = 0, User cancel the editing
                                         *      3: result < 0, The final path is too long or already exist, see FS error.
                                         * also see cui_filename_editor_result_event_struct */
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_CUI_FILENAME_EDITOR_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} cui_filename_editor_event_enum;

/* <GROUP Filename Editor Event>
 * event structure of EVT_ID_CUI_FILENAME_EDITOR_RESULT  */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    S32     result;         /* > 0: user complete
                             * = 0: user cancel,
                             * < 0: error, such as file exist, path too long */
                             
    const WCHAR* filename;  /* filename input by user, filtered out starting space and invalid chars
                             * Note. It is a pointer to caller's buffer */

} cui_filename_editor_result_event_struct;

/* <GROUP Filename Editor>
 * DESCRIPTION
 *  Create an instance of "Filename editor CUI", 
 *  It is an editor for Filename only, compatible with "Naming rule" with following feature:
 *      1: Not allow invalid characters, including /, \, :, *, ?, ", <, >, |, \n, \r
 *      2: Starting space will be removed automatically
 *      3: Display error when there is no input (empty)
 *      4: Check the final path exist or not. Note: to do so, "path" parameter must not be null.
 *
 * PARAMETERS
 *  caller                  : [IN]  group id of caller
 *  name_buf                : [IN]  buffer to store the filename, maintain by caller, 
 *                                  caller must take care to avoid dangling pointer problem.
 *  name_buf_size           : [IN]  size of name_buf (in bytes), including null terminated.
 *  max_char_length         : [IN]  max characters allow to input
 *  path                    : [IN]  Optional. If not null, CUI will use the path as the destination
 *                                  and check if there is the same entry already or the final path
 *                                  is too long.
 *  extension               : [IN]  Optional. If not null, with path also not null, CUI can do the 
 *                                  check
 * RETURNS
 *  id of the new created CUI
 */
mmi_id  cui_filename_editor_create(mmi_id caller, WCHAR* name_buf, S32 name_buf_size, S32 max_char_length, 
                                   const WCHAR* path, const WCHAR* extension);

/* <GROUP Filename Editor>
 * DESCRIPTION
 *  Run function of "Filename editor CUI".
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void    cui_filename_editor_run(mmi_id cui_id);

/* <GROUP Filename Editor>
 * DESCRIPTION
 *  Close function of "Filename editor CUI", 
 *  Caller should be responsible for closing CUI it created.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void    cui_filename_editor_close(mmi_id cui_id);

/* <GROUP Filename Editor>
 * DESCRIPTION
 *  Set title string and title icon of a Filename editor CUI
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  string                  : [IN]  new resource id of title string
 *  icon                    : [IN]  new resource id of title icon
 * RETURNS
 *  void
 */
void    cui_filename_editor_set_title(mmi_id cui_id, U16 string, U16 icon);

/* <GROUP Filename Editor>
 * DESCRIPTION
 *  Set flag of a Filename editor CUI. It is used for changing input characters length automatically by FSEditor.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  encoding_base_length    : [IN]  flag of encoding_base_length
 * RETURNS
 *  void
 */
void    cui_filename_editor_set_encoding_base_length(mmi_id cui_id, MMI_BOOL encoding_base_length);

/* <GROUP Filename Editor>
 * DESCRIPTION
 *  Set parent data of a Filename editor CUI, Caller can use this as a temporary storage
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  data                    : [IN]  data to remembered by CUI
 * RETURNS
 *  void
 */
void    cui_filename_editor_set_parent_data(mmi_id cui_id, U32 data);

/* <GROUP Filename Editor>
 * DESCRIPTION
 *  Get the parent data of a Filename editor CUI
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  data, previous set by cui_filename_editor_set_parent_data()
 */
U32     cui_filename_editor_get_parent_data(mmi_id cui_id);

/* <GROUP Filename Editor>
 * DESCRIPTION
 *  Get the final result of a Filename editor CUI.
 *  If path is set, the return result will be a fullpath. (Ex. D:\Image\1.bmp)
 *  If path is not set, the result result will be a filename only. (Ex. 1.bmp)
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  path_buf                : [OUT] buffer to store the result
 *  path_buf_size           : [IN]  size of the buffer
 * RETURNS
 *  0 if result is correctly written into path_buf
 *  < 0 if the size of path_buf is not enough
 */
S32     cui_filename_editor_get_fullpath(mmi_id cui_id, WCHAR* path_buf, S32 path_buf_size);

//add by shuo 20110830
void cui_filename_editor_set_rename_type(mmi_id cui_id, S32 type);

#endif /* _FMGR_CUI_GPROT_H_ */

