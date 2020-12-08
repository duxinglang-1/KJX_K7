/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_fmgr_cui_gprot.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_FMGR_CUI_GPROT_H__
#define __VAPP_FMGR_CUI_GPROT_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "MMI_include.h"
    #include "FileMgrSrvGProt.h"
    #include "mmi_rp_file_type_def.h"
#ifdef __cplusplus
}
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
/* External interface */
#ifdef __cplusplus
extern "C"
{
#endif
typedef enum
{
	VCUI_FMGR_TYPE_FILE_SELECTOR,
	VCUI_FMGR_TYPE_FOLDER_SELECTOR,
	VCUI_FMGR_TYPE_FOLDER_BROWSER,
	VCUI_FMGR_TYPE_MEDIA_PICKER,

	VCUI_FMGR_END
} vcui_fmgr_type_enum;

/* CUI */
void vcui_fmgr_run(mmi_id cui_id);
void vcui_fmgr_close(mmi_id cui_id, vcui_fmgr_type_enum cui_type);
void vcui_fmgr_set_title(mmi_id cui_id, U16 string, U16 icon, vcui_fmgr_type_enum cui_type);
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
    VCUI_FILE_SELECTOR_STYLE_FILE_ONLY,          /* Only file can be selected */
    VCUI_FILE_SELECTOR_STYLE_FILE_AND_PATH,      /* Both file and folder can be selected */

    /* DOM-NOT_FOR_SDK-BEGIN */
    VCUI_FILE_SELECTOR_STYLE_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} vcui_file_selector_style_enum;

/* <GROUP File Selector>
 *  Options of "File selector CUI". 
 *  Options also affect CUI's behavior. They are set using vcui_file_selector_set_option().
 */
typedef enum
{
    VCUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_MASK  = 0x000003, /* Mask of "Folder traversing" option */
    VCUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL   = 0x000000, /* All: all folder traversing are 
                                                             * allowed, including enter sub-folder
                                                             * and back to upper folder */
    VCUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_SUB   = 0x000001, /* Sub: only sub-folder of starting 
                                                             * folder are allowed to enter. Press 
                                                             * back at starting folder will trigger
                                                             * cancel selection */
    VCUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_NONE  = 0x000002, /* None: no folder traversing allowed, 
                                                             * sub-folder is not listed at all. 
                                                             * Press back will trigger cancel 
                                                             * selection */

    VCUI_FILE_SELECTOR_OPT_AUDIO_PREVIEW_MASK    = 0x000004, /* Mask of "Audio preview" option */
    VCUI_FILE_SELECTOR_OPT_AUDIO_PREVIEW_OFF     = 0x000000, /* Turn audio preview off */
    VCUI_FILE_SELECTOR_OPT_AUDIO_PREVIEW_ON      = 0x000004, /* Turn audio preview on, when audio 
                                                             * preview is on, stay at a audio file
                                                             * for a while will trigger audio 
                                                             * play-back. */

    VCUI_FILE_SELECTOR_OPT_DRM_CHECK_MASK        = 0x000030, /* Mask of "DRM permission check" */
    VCUI_FILE_SELECTOR_OPT_DRM_CHECK_SEND_OFF    = 0x000000, /* Turn DRM sendable check off */
    VCUI_FILE_SELECTOR_OPT_DRM_CHECK_SEND_ON     = 0x000010, /* Turn DRM sendable check on, when it 
                                                             * is on, non-sendable(non-forwardable)
                                                             * file cannot be selected */
    VCUI_FILE_SELECTOR_OPT_DRM_CHECK_SET_OFF     = 0x000000, /* Turn DRM setable check off */
    VCUI_FILE_SELECTOR_OPT_DRM_CHECK_SET_ON      = 0x000020, /* Turn DRM setable check on, when it 
                                                             * is on, non-setable (non-usable)
                                                             * file cannot be selected */

    VCUI_FILE_SELECTOR_OPT_FIXED_PATH_MASK       = 0x000040, /* Mask of "Fixed path" option */
    VCUI_FILE_SELECTOR_OPT_FIXED_PATH_OFF        = 0x000000, /* Turn fixed path off */
    VCUI_FILE_SELECTOR_OPT_FIXED_PATH_ON         = 0x000040, /* Turn fixed path on. In some project, 
                                                             * the start folder will be overwritten 
                                                             * to a pre-define value. Turn on this
                                                             * option can keep start folder from 
                                                             * being overwritten. */
    
    VCUI_FILE_SELECTOR_OPT_ARCHIVE_MASK          = 0x000F00, /* Mask of "Archive" option */
    VCUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FILE       = 0x000000, /* File: During selection, treat archive 
                                                             * as a single file. User can select 
                                                             * this archive */
    VCUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FOLDER     = 0x000100, /* Folder: During selection, treat 
                                                             * archive as a sub-folder. It can be 
                                                             * entered or selected as folder */
    VCUI_FILE_SELECTOR_OPT_ARCHIVE_AS_UNKNOWN    = 0x000200, /* Unknown: Ignore archive file, 
                                                             * There will be no option if highlight
                                                             * on it. */

    /* DOM-NOT_FOR_SDK-BEGIN */
    VCUI_FILE_SELECTOR_OPT_END
    /* DOM-NOT_FOR_SDK-END */
} vcui_file_selector_option_enum;

/* <GROUP File Selector Event>
 *  Here are events that "File selector CUI" will notify to caller.
 */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_VCUI_FILE_SELECTOR_BEGIN = VAPP_FMGR,
    /* DOM-NOT_FOR_SDK-END */
    
    EVT_ID_VCUI_FILE_SELECTOR_RESULT,    /* This event indicate the result of selection.
                                         * There may be 3 situation caller will receive this event:
                                         *      1: User select a file or folder
                                         *      2: User cancel
                                         *      3: Some error happen (mostly FS error)
                                         * See vcui_file_selector_result_event_struct for more info */
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_VCUI_FILE_SELECTOR_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} vcui_file_selector_event_enum;


/* <GROUP File Selector Event> 
 *  event structure of EVT_ID_VCUI_FILE_SELECTOR_RESULT
 */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    S32     result;         /* > 0: user selected a path, use vcui_file_selector_get_selected_filepath() 
                             *      to query,
                             * = 0: user cancel,
                             * < 0: FS error */

} vcui_file_selector_result_event_struct;

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
 *  style                   : [IN]  style of CUI, see vcui_file_selector_style_enum
 *  option_flag             : [IN]  option of CUI, see vcui_file_selector_option_enum
 * RETURNS
 *  id of the new created CUI
 */
mmi_id vcui_file_selector_create(mmi_id caller, const WCHAR* start_path, const FMGR_FILTER* filter, 
                                vcui_file_selector_style_enum style, U32 option_flag);

/* <GROUP File Selector>
 * DESCRIPTION
 *  Run function of "File selector CUI".
 *  Allow user to select a file or a folder for reading.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
#define vcui_file_selector_run(cui_id) vcui_fmgr_run((mmi_id)(cui_id))

/* <GROUP File Selector>
 * DESCRIPTION
 *  Close function of "File selector CUI", 
 *  Caller should be responsible for closing CUI it created.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
#define vcui_file_selector_close(cui_id) vcui_fmgr_close((mmi_id)(cui_id), VCUI_FMGR_TYPE_FILE_SELECTOR)


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
 // TODO:
#define vcui_file_selector_set_title(cui_id, string, icon) \
	vcui_fmgr_set_title((mmi_id)(cui_id), (U16)string, (U16)icon, VCUI_FMGR_TYPE_FILE_SELECTOR)


/* <GROUP File Selector>
 * DESCRIPTION
 *  Modify option of a file selector CUI
 *  see also vcui_file_selector_option_enum.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  option_mask             : [IN]  indicate option to be modifed
 *  option_value            : [IN]  indicate new option value
 * RETURNS
 *  void
 */
void   vcui_file_selector_set_option(mmi_id cui_id, U32 option_mask, U32 option_value);

/* <GROUP File Selector>
 * DESCRIPTION
 *  Set display style of a file selector CUI
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  style                   : [IN]  new ui style
 * RETURNS
 *  void
 */
void   vcui_file_selector_set_ui_style(mmi_id cui_id, S32 style);

/* <GROUP File Selector>
 * DESCRIPTION
 *  Set a userdata of a file selector CUI, later caller can query using 
 *  vcui_file_selector_get_userdata().
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  userdata                : [IN]  new userdata
 * RETURNS
 *  void
 */
void   vcui_file_selector_set_userdata(mmi_id cui_id, U32 userdata);

/* <GROUP File Selector>
 * DESCRIPTION
 *  Get userdata of a file selector CUI, previous set by vcui_file_selector_set_userdata().
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  an U32 userdata
 */
U32    vcui_file_selector_get_userdata(mmi_id cui_id);

/* <GROUP File Selector>
 * DESCRIPTION
 *  Get a pointer to the current path of a file selector CUI.
 *  The buffer belongs to this CUI, is read-only, and will become invalid if CUI dies.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  pointer to current path 
 */
const WCHAR* vcui_file_selector_get_folder(mmi_id cui_id);

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
S32    vcui_file_selector_get_selected_filepath_old(mmi_id cui_id, srv_fmgr_fileinfo_struct* info, 
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
S32    vcui_file_selector_get_selected_filepath(mmi_id cui_id, srv_fmgr_fileinfo_struct* info, 
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
    VCUI_FOLDER_SELECTOR_STYLE_READ,     /* Select a folder for reading data from. During 
                                         * selection, User cannot modify file system, such as
                                         * folder creation / renaming / deletion */
    VCUI_FOLDER_SELECTOR_STYLE_WRITE,    /* Select a folder for writing data to. During selection,
                                         * User can create / rename / delete any sub-folder */

    /* DOM-NOT_FOR_SDK-BEGIN */
    VCUI_FOLDER_SELECTOR_STYLE_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} vcui_folder_selector_style_enum;

/* <GROUP Folder Selector>
 *  Options of "Folder selector CUI". 
 *  Options also affect CUI's behavior. They are set using vcui_folder_selector_set_option().
 */
typedef enum
{
    VCUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_MASK  = 0x00000F,   /* Mask of "Folder traversing" option */
    VCUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_ALL   = 0x000000,   /* All: all folder traversing are 
                                                                 * allowed, including enter sub-folder
                                                                 * and back to upper folder */
    VCUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_SUB   = 0x000001,   /* Sub: only sub-folder of starting 
                                                                 * folder are allowed to enter. Press 
                                                                 * back at starting folder will trigger
                                                                 * cancel selection */
    VCUI_FOLDER_SELECTOR_OPT_FOLDER_TRAVERSE_NONE  = 0x000002,   /* None: no folder traversing allowed, 
                                                                 * sub-folder is not listed at all. 
                                                                 * Press back will trigger cancel 
                                                                 * selection */

    VCUI_FOLDER_SELECTOR_OPT_FIXED_PATH_MASK       = 0x000040,   /* Mask of "Fixed path" option */
    VCUI_FOLDER_SELECTOR_OPT_FIXED_PATH_OFF        = 0x000000,   /* Turn fixed path off */
    VCUI_FOLDER_SELECTOR_OPT_FIXED_PATH_ON         = 0x000040,   /* Turn fixed path on. In some project, 
                                                                 * the start folder will be overwritten 
                                                                 * to a pre-define value. Turn on this
                                                                 * option can keep start folder from 
                                                                 * being overwritten. */

    /* DOM-NOT_FOR_SDK-BEGIN */
    VCUI_FOLDER_SELECTOR_OPT_END
    /* DOM-NOT_FOR_SDK-END */
} vcui_folder_selector_option_enum;

/* <GROUP Folder Selector Event>
 *  Here are events that "Folder selector CUI" will notify to caller.
 */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_VCUI_FOLDER_SELECTOR_BEGIN = EVT_ID_VCUI_FILE_SELECTOR_TOTAL,
    /* DOM-NOT_FOR_SDK-END */
    
    EVT_ID_VCUI_FOLDER_SELECTOR_RESULT,  /* This event indicate the result of selection.
                                         * There may be 3 situation caller will receive this event:
                                         *      1: User select a folder
                                         *      2: User cancel
                                         *      3: Some error happen (mostly FS error)
                                         * See vcui_folder_selector_result_event_struct for more info */

    EVT_ID_VCUI_FOLDER_SELECTOR_BEFORE_ERROR_HANDLE,
    EVT_ID_VCUI_FOLDER_SELECTOR_ENABLE_CREATE_FOLDER,    /* See vcui_folder_selector_query_event_struct for more info */
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_VCUI_FOLDER_SELECTOR_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} vcui_folder_selector_event_enum;

/* <GROUP Folder Selector Event>
 * event structure of EVT_ID_VCUI_FOLDER_SELECTOR_RESULT  */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    S32     result;         /* > 0: user selected a path, use vcui_folder_selector_get_selected_filepath() 
                             *      to query,
                             * = 0: user cancel,
                             * < 0: FS error */

} vcui_folder_selector_result_event_struct;

/* <GROUP Folder Selector Event>
 * event structure of EVT_ID_VCUI_FOLDER_SELECTOR_ENABLE_CREATE_FOLDER  */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    CHAR   *path;         /* current path */
    S32    menuid;

} vcui_folder_selector_query_event_struct;

/* <GROUP Folder Selector>
 * DESCRIPTION
 *  Create an instance of "Folder selector CUI", 
 *  Allow user to select a folder for reading/writing.
 * PARAMETERS
 *  caller                  : [IN]  group id of caller
 *  start_path              : [IN]  the starting path of selection, L"root" can also be used to start 
 *                                  from root.
 *  style                   : [IN]  style of CUI, see vcui_folder_selector_style_enum
 *  option_flag             : [IN]  option of CUI, see vcui_folder_selector_option_enum
 * RETURNS
 *  id of the new created CUI
 */
mmi_id vcui_folder_selector_create(mmi_id caller, const WCHAR* start_path, 
                                  vcui_folder_selector_style_enum style, U32 option_flag);
/* <GROUP Folder Selector>
 * DESCRIPTION
 *  Run function of "Folder selector CUI".
 *  Allow user to select a folder for read/write.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
#define vcui_folder_selector_run(cui_id) vcui_fmgr_run((mmi_id)(cui_id))


/* <GROUP Folder Selector>
 * DESCRIPTION
 *  Close function of "Folder selector CUI", 
 *  Caller should be responsible for closing CUI it created.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
#define vcui_folder_selector_close(cui_id) vcui_fmgr_close((mmi_id)(cui_id), VCUI_FMGR_TYPE_FOLDER_SELECTOR)


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
 // TODO:
#define vcui_folder_selector_set_title(cui_id, string, icon) \
		vcui_fmgr_set_title((mmi_id)(cui_id), (U16)string, (U16)icon, VCUI_FMGR_TYPE_FOLDER_SELECTOR)

/* <GROUP Folder Selector>
 * DESCRIPTION
 *  Modify option of a folder selector CUI
 *  see also vcui_folder_selector_option_enum.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  option_mask             : [IN]  indicate option to be modifed
 *  option_value            : [IN]  indicate new option value
 * RETURNS
 *  void
 */
void   vcui_folder_selector_set_option(mmi_id cui_id, U32 option_mask, U32 option_value);

/* <GROUP Folder Selector>
 * DESCRIPTION
 *  Set display style of a folder selector CUI
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  style                   : [IN]  new ui style
 * RETURNS
 *  void
 */
void   vcui_folder_selector_set_ui_style(mmi_id cui_id, S32 style);

/* <GROUP Folder Selector>
 * DESCRIPTION
 *  Set a userdata of a folder selector CUI, later caller can query using 
 *  vcui_folder_selector_get_userdata().
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 *  userdata                : [IN]  new userdata
 * RETURNS
 *  void
 */
void   vcui_folder_selector_set_userdata(mmi_id cui_id, U32 userdata);

/* <GROUP Folder Selector>
 * DESCRIPTION
 *  Get userdata of a folder selector CUI, previous set by vcui_folder_selector_set_userdata().
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  an U32 userdata
 */
U32    vcui_folder_selector_get_userdata(mmi_id cui_id);

/* <GROUP Folder Selector>
 * DESCRIPTION
 *  Get a pointer to the current path of a folder selector CUI.
 *  The buffer belongs to this CUI, is read-only, and will become invalid if CUI dies.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  pointer to current path 
 */
const WCHAR* vcui_folder_selector_get_folder(mmi_id cui_id);

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
S32    vcui_folder_selector_get_selected_filepath_old(mmi_id cui_id, srv_fmgr_fileinfo_struct* info, WCHAR* path_buffer, S32 path_size);

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
S32    vcui_folder_selector_get_selected_filepath(mmi_id cui_id, srv_fmgr_fileinfo_struct* info, WCHAR* path_buffer, S32 path_size);


/* <GROUP Folder Browser Launch Event>
 *  Here are events that "Folder browser launch CUI" will notify to caller.
 */
typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_VCUI_FOLDER_BROWSER_LAUNCH_BEGIN = EVT_ID_VCUI_FOLDER_SELECTOR_TOTAL,
    /* DOM-NOT_FOR_SDK-END */
    
    EVT_ID_VCUI_FOLDER_BROWSER_LAUNCH_QUIT,    /* This event indicate user leave folder browser launch */
    
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_VCUI_FOLDER_BROWSER_LAUNCH_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} vcui_folder_browser_launch_event_enum;

/* <GROUP Folder Browser Launch Event>
 * event structure of EVT_ID_VCUI_FOLDER_BROWSER_LAUNCH_RESULT  */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */

    S32     result;         /* = 0: folder browser launch closed */

} vcui_folder_browser_launch_result_event_struct;

/*****************************************************************************
 * FUNCTION
 *  cui_folder_browser_launch
 * DESCRIPTION
 *  Launch a folder browser.
 * PARAMETERS
 *  parent_id        : [IN] group id of parent    
 *  base_path        : [IN] start folder 
 *  filter           : [IN] only matched files are displayed 
 * RETURN VALUES
 *  VFX_FALSE        : file manager can't be launched
 *  VFX_TRUE         : file manager was launched successfully
 *****************************************************************************/
mmi_id vcui_folder_browser_launch(mmi_id parent_id, const WCHAR* base_path, const FMGR_FILTER* filter);

/* <Folder Browser Launch>
 * DESCRIPTION
 *  Close function of "Folder Browser Launch CUI", 
 *  Caller should be responsible for closing CUI it created.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
#define vcui_folder_browser_close(cui_id) vcui_fmgr_close((mmi_id)(cui_id), VCUI_FMGR_TYPE_FOLDER_BROWSER)


mmi_id vcui_folder_browser_launch_by_custom(mmi_id parent_id, const WCHAR* base_path, const FMGR_FILTER* filter);
#define vcui_folder_browser_set_title_by_custom(cui_id, string, icon) \
		vcui_fmgr_set_title((mmi_id)(cui_id), (U16)string, (U16)icon, VCUI_FMGR_TYPE_FOLDER_BROWSER)
#define vcui_folder_browser_run_by_custom(cui_id) vcui_fmgr_run((mmi_id)(cui_id))
#define vcui_folder_browser_close_by_custom(cui_id) vcui_fmgr_close((mmi_id)(cui_id), VCUI_FMGR_TYPE_FOLDER_BROWSER)



/* For media picker */
#define MMI_FMGR_MEDIA_PICKER_MAX_NUM (40)

typedef enum
{
    VCUI_FMGR_MEDIA_PICKER_STYLE_READ,     /* Select a folder for reading data from. During 
                                         * selection, User cannot modify file system, such as
                                         * folder creation / renaming / deletion */
    VCUI_FMGR_MEDIA_PICKER_STYLE_WRITE,    /* Select a folder for writing data to. During selection,
                                         * User can create / rename / delete any sub-folder */

    /* DOM-NOT_FOR_SDK-BEGIN */
    VCUI_FMGR_MEDIA_PICKER_STYLE_TOTAL
    /* DOM-NOT_FOR_SDK-END */

} vcui_fmgr_media_picker_style_enum;

typedef enum
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_VCUI_FMGR_MEDIA_PICKER_BEGIN =     EVT_ID_VCUI_FOLDER_BROWSER_LAUNCH_TOTAL,
    /* DOM-NOT_FOR_SDK-END */
    
    EVT_ID_VCUI_FMGR_MEDIA_PICKER_RESULT,  /* This event indicate the result of selection.
                                         * There may be 3 situation caller will receive this event:
                                         *      1: User select a folder
                                         *      2: User cancel
                                         *      3: Some error happen (mostly FS error)
                                         * See vcui_folder_selector_result_event_struct for more info */

    EVT_ID_VCUI_FMGR_MEDIA_PICKER_BEFORE_ERROR_HANDLE,
    EVT_ID_VCUI_FMGR_MEDIA_PICKER_ENABLE_CREATE_FOLDER,    /* See vcui_folder_selector_query_event_struct for more info */
    /* DOM-NOT_FOR_SDK-BEGIN */
    EVT_ID_VCUI_FMGR_MEDIA_PICKER_TOTAL
    /* DOM-NOT_FOR_SDK-END */
} vcui_fmgr_media_picker_event_enum;

typedef enum
{
    VCUI_FMGR_MEDIA_PICKERR_OPT_FOLDER_TRAVERSE_MASK  = 0x000003, /* Mask of "Folder traversing" option */  /* not used*/
    VCUI_FMGR_MEDIA_PICKER_OPT_FOLDER_TRAVERSE_ALL   = 0x000000, /* All: all folder traversing are 
                                                             * allowed, including enter sub-folder
                                                             * and back to upper folder */
    VCUI_FMGR_MEDIA_PICKER_OPT_FOLDER_TRAVERSE_SUB   = 0x000001, /* Sub: only sub-folder of starting 
                                                             * folder are allowed to enter. Press 
                                                             * back at starting folder will trigger
                                                             * cancel selection */
    VCUI_FMGR_MEDIA_PICKER_OPT_FOLDER_TRAVERSE_NONE  = 0x000002, /* None: no folder traversing allowed, 
                                                             * sub-folder is not listed at all. 
                                                             * Press back will trigger cancel 
                                                             * selection */

    VCUI_FMGR_MEDIA_PICKER_OPT_AUDIO_PREVIEW_MASK    = 0x000004, /* Mask of "Audio preview" option */    /* not used*/
    VCUI_FMGR_MEDIA_PICKER_OPT_AUDIO_PREVIEW_OFF     = 0x000000, /* Turn audio preview off */             /* not used*/
    VCUI_FMGR_MEDIA_PICKER_OPT_AUDIO_PREVIEW_ON      = 0x000004, /* Turn audio preview on, when audio 
                                                             * preview is on, stay at a audio file
                                                             * for a while will trigger audio 
                                                             * play-back. */

    VCUI_FMGR_MEDIA_PICKER_OPT_DRM_CHECK_MASK        = 0x000030, /* Mask of "DRM permission check" */ /* not used*/
    VCUI_FMGR_MEDIA_PICKER_OPT_DRM_CHECK_SEND_OFF    = 0x000000, /* Turn DRM sendable check off */    /* not used*/
    VCUI_FMGR_MEDIA_PICKER_OPT_DRM_CHECK_SEND_ON     = 0x000010, /* Turn DRM sendable check on, when it 
                                                             * is on, non-sendable(non-forwardable)
                                                             * file cannot be selected */
    VCUI_FMGR_MEDIA_PICKER_OPT_DRM_CHECK_SET_OFF     = 0x000000, /* Turn DRM setable check off */    /* not used*/
    VCUI_FMGR_MEDIA_PICKER_OPT_DRM_CHECK_SET_ON      = 0x000020, /* Turn DRM setable check on, when it 
                                                             * is on, non-setable (non-usable)
                                                             * file cannot be selected */

    VCUI_FMGR_MEDIA_PICKER_OPT_FIXED_PATH_MASK       = 0x000040, /* Mask of "Fixed path" option */    /* not used*/
    VCUI_FMGR_MEDIA_PICKER_OPT_FIXED_PATH_OFF        = 0x000000, /* Turn fixed path off */            /* not used*/
    VCUI_FMGR_MEDIA_PICKER_OPT_FIXED_PATH_ON         = 0x000040, /* Turn fixed path on. In some project, 
                                                             * the start folder will be overwritten 
                                                             * to a pre-define value. Turn on this
                                                             * option can keep start folder from 
                                                             * being overwritten. */
    
    VCUI_FMGR_MEDIA_PICKER_OPT_ARCHIVE_MASK          = 0x000F00, /* Mask of "Archive" option */    /* not used*/
    VCUI_FMGR_MEDIA_PICKER_OPT_ARCHIVE_AS_FILE       = 0x000000, /* File: During selection, treat archive 
                                                             * as a single file. User can select 
                                                             * this archive */                   /* not used*/
    VCUI_FMGR_MEDIA_PICKER_OPT_ARCHIVE_AS_FOLDER     = 0x000100, /* Folder: During selection, treat 
                                                             * archive as a sub-folder. It can be 
                                                             * entered or selected as folder */
    VCUI_FMGR_MEDIA_PICKER_OPT_ARCHIVE_AS_UNKNOWN    = 0x000200, /* Unknown: Ignore archive file, 
                                                             * There will be no option if highlight
                                                             * on it. */

    /* DOM-NOT_FOR_SDK-BEGIN */
    VCUI_FMGR_MEDIA_PICKER_OPT_END
    /* DOM-NOT_FOR_SDK-END */
} vcui_fmgr_media_picker_option_enum;

typedef vcui_file_selector_result_event_struct vcui_fmgr_media_picker_event_struct;

typedef struct
{
	U8 isFolder;
	WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1];
} vcui_fmgr_media_path_struct;


mmi_id vcui_fmgr_media_picker_create(mmi_id caller, const WCHAR* start_path, const FMGR_FILTER* filter, 
                                vcui_fmgr_media_picker_style_enum style, U32 option_flag);

#define vcui_fmgr_media_picker_run(cui_id) vcui_fmgr_run((mmi_id)(cui_id))

#define vcui_fmgr_media_picker_close(cui_id) vcui_fmgr_close((mmi_id)(cui_id), VCUI_FMGR_TYPE_MEDIA_PICKER)

S32 vcui_fmgr_media_picker_get_picked_num(mmi_id cui_id);

S32 vcui_fmgr_media_picker_get_picked_path(mmi_id cui_id, vcui_fmgr_media_path_struct* pathArray, U32 picked_num);

mmi_id vapp_fmgr_launch_by_app(const WCHAR * rootPath,FMGR_FILTER * filter);

#ifdef __cplusplus
}
#endif

#endif /* __VAPP_FMGR_CUI_GPROT_H__ */

