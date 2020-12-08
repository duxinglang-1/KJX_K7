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
 * BrowserSrvGProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERSRVBOOKMARKS_H
#define MMI_BROWSERSRVBOOKMARKS_H

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__

#ifdef __MMI_VBOOKMARK__
#include "FileMgrSrvGProt.h"
#include "custom_wap_config.h"
#include "MMIDataType.h"
#include "gui_data_types.h"
#include "kal_general_types.h"
#include "BrowserSrvBookmarkConfig.h"

/*********************************************MACROS START********************************************/
#define SRV_BRW_BKM_DEFAULT_DRIVE					SRV_FMGR_SYSTEM_DRV

#define SRV_BRW_BKM_DEFAULT_FOLDER_NAME             L"@vbookmarks"  /* should be consistent with the path defined in fs_quota.c file */
#define SRV_BRW_BKM_ROOT_FILE_NAME                  L"bkm.dat"  /* it is the name of the single bookmark file to be created */

#define SRV_BRW_BKM_DEFAULT_EXPORT_FOLDER_NAME                  L"Bookmarks"  /* it is the name of the folder under which the bookmarks will be exported */

#define SRV_BRW_BKM_MAX_PATH_LEN                    (SRV_FMGR_PATH_MAX_LEN+1) + SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1
#define SRV_BRW_BKM_MAX_FILE_EXTN_LEN               SRV_FMGR_PATH_MAX_FILE_EXT_LEN
#define SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN         (SRV_BRW_BKM_MAX_FILE_NAME_LEN - SRV_BRW_BKM_MAX_FILE_EXTN_LEN)  //SRV_FMGR_PATH_MAX_FILE_BASENAME_LEN - 1  /* subtracting 1 to sync it with file manager */
#define SRV_BRW_BKM_MAX_FOLDER_NAME_LEN             40 //SRV_FMGR_PATH_MAX_FILE_NAME_LEN - 1      /* subtracting 1 to sync it with file manager */


#define SRV_BRW_BKM_FILE_EXTN_DFT_STRING            L"dft"
#define SRV_BRW_BKM_FILE_EXTN_URL_STRING            L"url"
#define SRV_BRW_BKM_FILE_EXTN_VBM_STRING            L"vbm"
#define SRV_BRW_BKM_USER_CREATED_FILE_DEFAULT_EXTN  SRV_BRW_BKM_FILE_EXTN_URL_STRING

#define SRV_BRW_BKM_DEFAULT_FILE_NAME               L"default"
#define SRV_BRW_BKM_DEFAULT_FILE_EXTN               SRV_BRW_BKM_USER_CREATED_FILE_DEFAULT_EXTN

#define SRV_BRW_BKM_TITLE_PADDING_TOKEN                 '/'
#define SRV_BRW_BKM_URL_PADDING_TOKEN                    ' '

#define SRV_BRW_BKM_LINE_BREAK                                  "\r\n"

#define SRV_BRW_BKM_MAX_COUNT                       WAP_CUSTOM_CFG_BRW_BOOKMARK_MAX_COUNT

#define SRV_BRW_BKM_TYPE_SIZE                          2
#define SRV_BRW_BKM_TIMESTAMP_SIZE                     10
#define SRV_BRW_BKM_INVALID_INDEX                      -1
#define SRV_BRW_BKM_PARENT_INDEX_SIZE                  3
#define SRV_BRW_ROOT_PARENT_INDEX                      SRV_BRW_BKM_MAX_COUNT

typedef void (*srv_brw_bkm_rsp_funcptr_type)(void *rsp_data);
/*********************************************MACROS END********************************************/


/*********************************************ENUMS START********************************************/

typedef enum
{
    SRV_BRW_BKM_DEFAULT_COUNT = 0,
    SRV_BRW_BKM_ALL_COUNT,
    SRV_BRW_BKM_FOLDER_COUNT,
    SRV_BRW_BKM_USER_CREATED_COUNT,
	SRV_BRW_BKM_TOTAL
} srv_brw_bkm_count_enum;

typedef enum
{
    SRV_BRW_BKM_GET_FILE_EXTN = 0,
    SRV_BRW_BKM_GET_FILENAME_WITHOUT_EXTN,
    SRV_BRW_BKM_GET_FOLDER_PATH,
    SRV_BRW_BKM_GET_FOLDER_NAME,
    SRV_BRW_BKM_GET_FILENAME,
    SRV_BRW_BKM_GET_END
} srv_brw_bkm_opcode_enum;

typedef enum
{
    SRV_BRW_BKM_FILE_EXTN_NONE = 0,
    SRV_BRW_BKM_FILE_EXTN_DFT,
    SRV_BRW_BKM_FILE_EXTN_URL,
    SRV_BRW_BKM_FILE_EXTN_VBM,
    SRV_BRW_BKM_FILE_EXTN_TOTAL
} srv_brw_bkm_file_extension_types_enum;


typedef enum
{
    SRV_BRW_BKM_ERROR_OK = 0,
    SRV_BRW_BKM_ERROR_INVALID_URL,
    SRV_BRW_BKM_ERROR_EMPTY_FILE_NAME,
    SRV_BRW_BKM_ERROR_INVALID_TITLE,
    SRV_BRW_BKM_ERROR_FILE_PATH_LEN_EXCEEDED,
    SRV_BRW_BKM_ERROR_INVALID_BOOKMARK_FILE,
    SRV_BRW_BKM_ERROR_DIR_PATH_TOO_DEEP,
    SRV_BRW_BKM_ERROR_NOT_ENOUGH_MEMORY,
    SRV_BRW_BKM_ERROR_FILE_ALREADY_EXISTS,
    SRV_BRW_BKM_ERROR_FOLDER_CREATED,
    SRV_BRW_BKM_ERROR_INVALID_FILE,
    SRV_BRW_BKM_ERROR_EMPTY_FOLDER_NAME,
    SRV_BRW_BKM_ERROR_TOTAL
} srv_brw_bkm_error_code_enum;

typedef enum
{
    SRV_BRW_BKM_PROVISIONING_SUCCESS = 0,
    SRV_BRW_BKM_PROVISIONING_INVALID_URL,
    SRV_BRW_BKM_PROVISIONING_INVALID_TITLE,
    SRV_BRW_BKM_PROVISIONING_FILE_SYSTEM_ERROR,
    SRV_BRW_BKM_PROVISIONING_MEMORY_FULL
} srv_brw_bkm_provisioning_err_enum;

typedef enum
{
    SRV_BRW_BKM_FOLDER_NONE = 0,
    SRV_BRW_BKM_FOLDER_CREATE,
    SRV_BRW_BKM_FOLDER_RENAME,
    SRV_BRW_BKM_FOLDER_END
} srv_brw_bkm_folder_opeartion_enum;

typedef enum
{
    VBKM_FIELD_BEGIN,
    VBKM_FIELD_VERSION,
    VBKM_FIELD_TITLE,
    VBKM_FIELD_URL,
    VBKM_FIELD_XIRMC,
    VBKM_FIELD_IS,
    VBKM_FIELD_END,
    VBKM_FIELD_TOTAL
} vbkm_field_enum;

typedef enum
{
    VBKM_SUB_FIELD_VBKM,
    VBKM_SUB_FIELD_ENV,
    VBKM_SUB_FIELD_CHARSET,
    VBKM_SUB_FIELD_ENCODING,
    VBKM_SUB_FIELD_TOTAL
} vbkm_sub_field_enum;

typedef enum
{
    VBKM_PARSE_NO_ERROR=0,
    VBKM_BEGIN_ERROR,
    VBKM_URL_ERROR,
    VBKM_END_ERROR,
    VBKM_PARSE_UNKNOWN_ERROR
} vbkm_parse_enum;

/* NOTE : the ordering of this enum should not be changed because the bookmarks
   in the bookmark list will be displayed using this order only 
   If the ordering is changed then there will be some changes needed in 
   srv_brw_bkm_arrange_bookmark_list_in_order function*/
typedef enum
{
    SRV_BRW_BKM_TYPE_EMPTY = 0,
#ifdef    __MMI_BRW_BKM_FOLDER_SUPPORT__
    SRV_BRW_BKM_TYPE_FOLDER,
#endif
    SRV_BRW_BKM_TYPE_DEFAULT_FILE,
    SRV_BRW_BKM_TYPE_USER_CREATED_FILE,
    SRV_BRW_BKM_TYPE_END
} srv_brw_bkm_types_enum;


/*********************************************ENUMS END********************************************/

/*********************************************STRUCT START********************************************/

typedef struct
{
    U8 file_name[(SRV_BRW_BKM_MAX_FILE_NAME_LEN +1) * ENCODING_LENGTH];
    U8 file_url[(SRV_BRW_MAX_URL_LEN +1) * ENCODING_LENGTH];
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    U8 parent_folder[SRV_BRW_BKM_MAX_FILE_NAME_LEN +1];
#endif
    S8 selected_bookmark_index;
} srv_brw_bookmark_file_struct;

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
typedef struct
{
    U8 folder_name[(SRV_BRW_BKM_MAX_FILE_NAME_LEN +1) * ENCODING_LENGTH];
    S8 selected_folder_index;
} srv_brw_bookmark_folder_struct;
#endif

typedef struct
{
    U8 file_path[(SRV_BRW_BKM_MAX_PATH_LEN + 1) * ENCODING_LENGTH];
    U8 url[(SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH];
    U8 title[(SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN + 1) * ENCODING_LENGTH];
} srv_brw_default_bookmark_struct;

typedef struct
{
    srv_brw_bkm_types_enum type;
    U32 timestamp;
    U8 *title;
    U8 *url;
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    U8 parent_index;
#endif
} srv_brw_bkm_bookmark_context_struct;

typedef struct
{
    U8 title[SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1];
    U8 url[SRV_BRW_MAX_URL_LEN + 1];
} srv_brw_bkm_bookmark_struct;

typedef struct
{
    U8 actual_index;
} srv_brw_bkm_bookmark_list_struct;

/* MSG_ID_SRV_BRW_BOOKMARK_EXPORT_IND */
typedef struct
{
    LOCAL_PARA_HDR 
    U8 exported;
    U8 failed;
    U8 current_index;
    U8 *destination_folder_path;
    srv_brw_bkm_rsp_funcptr_type rsp_callback;
} srv_brw_bookmark_export_ind_struct;

typedef struct
{
    U8 exported;
    U8 failed;
    S32 error_code;
} srv_brw_bookmark_export_rsp_struct;


/*********************************************STRUCT END********************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmarks_parse_filepath
 * DESCRIPTION
 *  This func is the service internal API to parse the provided file path
 * to extract some data depending on the operation code passed
 * PARAMETERS
 *  op_code         [IN]     The operation code to tell what operation to perform
 *  sel_file_path   [IN]     The input file path in which to search
 *  output_buffer   [IN|OUT] The output buffer in which the result is copied
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_brw_bookmarks_parse_filepath(srv_brw_bkm_opcode_enum op_code, U8* sel_file_path, U8* output_buffer);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_extract_filename_without_extn
 * DESCRIPTION
 *  This function is to extract the file name without extension from the file
 * path passed to the function
 * PARAMETERS
 *  file_path       [IN]        the file path in which to search
 *  file_dir        [IN|OUT]    the output buffer in which the result is copied
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_brw_bookmark_extract_filename_without_extn(U8 *file_path, U8 *file_name);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_extract_filename
 * DESCRIPTION
 *  This function is to extract the file name from the file
 * path passed to the function
 * PARAMETERS
 *  file_path       [IN]        the file path in which to search
 *  file_dir        [IN|OUT]    the output buffer in which the result is copied
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_brw_bookmark_extract_filename(U8 *file_path, U8 *file_name);

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_extract_file_directory_from_filepath
 * DESCRIPTION
 *  This function is to extract the file directory from the passed file path
 * PARAMETERS
 *  file_path       [IN]        the file path in which to search
 *  file_dir        [IN|OUT]    the output buffer in which the result is copied
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_brw_bookmarks_extract_file_directory(U8 *file_path, U8 *file_dir);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmarks_extract_folder_name
 * DESCRIPTION
 *  This function is to extract the folder name y from the passed file path
 * PARAMETERS
 *  file_path       [IN]        the file path in which to search
 *  file_dir        [IN|OUT]    the output buffer in which the result is copied
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_brw_bookmarks_extract_folder_name(U8 *file_path, U8 *folder_name);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmarks_create_full_file_path
 * DESCRIPTION
 *  Utility function to create the full file path from the varios information
 * passed
 * PARAMETERS
 *  folder_path [IN]    The path of the folder for creating file path
 *  file_name   [IN]    The name of the file for creating file path
 *  file_extn   [IN]    The externsion of the file for creating file path
 *  file_path   [IN]    The output buffer in which the created file path is copied
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_brw_bookmarks_create_full_file_path(S8* folder_path, S8* file_name, S8* file_extn, S8* file_path);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_trim_left_white_spaces
 * DESCRIPTION
 *  This function is used for removing white spaces from a string at left end
 * PARAMETERS
 *  string      [OUT]       String in unicode
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_brw_trim_left_white_spaces(S8 *string);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_trim_right_white_spaces
 * DESCRIPTION
 *  This function is used for removing white spaces from a string at right end
 * PARAMETERS
 *  string      [OUT]       String in unicode
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_brw_trim_right_white_spaces(S8 *string);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_validate_file_for_add
 * DESCRIPTION
 *  This function is the service internal API to check the various condition
 * required before adding a new Bookmark file
 * PARAMETERS
 *  obj     [IN]    The object of file struct containing all the information
 * RETURNS
 *  S32     [OUT]   The error code value if any of the checks fail
 *****************************************************************************/
extern S32 srv_brw_bookmark_validate_file_for_add(srv_brw_bookmark_file_struct *obj);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_validate_file_for_edit
 * DESCRIPTION
 *  This function is the service internal API to check the various condition
 * required before editing a Bookmark file
 * PARAMETERS
 *  obj     [IN]    The object of file struct containing all the information
 * RETURNS
 *  S32     [OUT]   The error code value if any of the checks fail
 *****************************************************************************/
extern S32 srv_brw_bookmark_validate_file_for_edit(srv_brw_bookmark_file_struct *obj);

#ifdef    __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_validate_folder
 * DESCRIPTION
 *  This function is the service internal API to check the various condition
 * required before creating or renaming a folder
 * PARAMETERS
 *  obj         [IN]    The object of folder struct containing all the information
 *  folder_op   [IN]    The folder operation being performed(create/rename)
 * RETURNS
 *  S32         [OUT]   The error code value if any of the checks fail
 *****************************************************************************/
extern S32 srv_brw_bookmark_validate_folder(srv_brw_bookmark_folder_struct *obj, srv_brw_bkm_folder_opeartion_enum folder_op);
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_add_item
 * DESCRIPTION
 *  This function is the service internal API to add a new bookmark file
 * PARAMETERS
 *  obj     [IN]    The object of file struct containing all the information
 * RETURNS
 *  S32     [OUT]   The error code value if any while adding a new file
 *****************************************************************************/
extern S32 srv_brw_bookmark_add_item(srv_brw_bookmark_file_struct *obj);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_add_replace_item
 * DESCRIPTION
 *  This function is the service internal API to replace and existing bookmark
 * file to add a new bookmark file
 * PARAMETERS
 *  obj     [IN]    The object of file struct containing all the information
 * RETURNS
 *  S32     [OUT]   The error code value if any while adding a new file
 *****************************************************************************/
extern S32 srv_brw_bookmark_add_replace_item(srv_brw_bookmark_file_struct *obj);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_edit_item
 * DESCRIPTION
 *  This function is the service internal API to edit an existing bookmark
 * PARAMETERS
 *  obj             [IN]    The object of file struct containing all the information
 *  internal_format [IN]    Flag to check if the new file is to be in internal
 *                          format or standard
 * RETURNS
 *  S32     [OUT]   The error code value if any while adding a new file
 *****************************************************************************/
extern S32 srv_brw_bookmark_edit_item(srv_brw_bookmark_file_struct *obj, MMI_BOOL internal_format);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_edit_replace_item
 * DESCRIPTION
 *  This function is the service internal API to replace and existing bookmark
 * while edit operation was being performed
 * PARAMETERS
 *  obj             [IN]    The object of file struct containing all the information
 *  internal_format [IN]    Flag to check if the new file is to be in internal
 *                          format or standard
 * RETURNS
 *  S32     [OUT]   The error code value if any while adding a new file
 *****************************************************************************/
extern S32 srv_brw_bookmark_edit_replace_item(srv_brw_bookmark_file_struct *obj, MMI_BOOL internal_format);

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_validate_folder
 * DESCRIPTION
 *  This function is the service internal API to check the various condition
 * required before creating or renaming a folder
 * PARAMETERS
 *  obj         [IN]    The object of folder struct containing all the information
 *  folder_op   [IN]    The folder operation being performed(create/rename)
 * RETURNS
 *  S32         [OUT]   The error code value if any of the checks fail
 *****************************************************************************/
extern S32 srv_brw_bookmark_validate_folder(srv_brw_bookmark_folder_struct *obj, srv_brw_bkm_folder_opeartion_enum folder_op);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_create_new_folder
 * DESCRIPTION
 *  This function is the service internal API to create a new folder
 * depending on the information passed
 * PARAMETERS
 *  obj         [IN]    The object of folder struct containing all the information
 * RETURNS
 *  S32     [OUT]   The error code value if any of the checks fail
 *****************************************************************************/
extern S32 srv_brw_bookmark_create_new_folder(srv_brw_bookmark_folder_struct *obj);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_rename_folder
 * DESCRIPTION
 *  This function is the service internal API to rename a folder
 * depending on the information passed
 * PARAMETERS
 *  obj         [IN]    The object of folder struct containing all the information
 * RETURNS
 *  S32     [OUT]   The error code value if any of the checks fail
 *****************************************************************************/
extern S32 srv_brw_bookmark_rename_folder(srv_brw_bookmark_folder_struct *obj);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_create_folder
 * DESCRIPTION
 *  This function is the service internal API to create or rename a folder
 * depending on the information passed
 * PARAMETERS
 *  obj         [IN]    The object of folder struct containing all the information
 *  folder_op   [IN]    The folder operation being performed(create/rename)
 * RETURNS
 *  S32     [OUT]   The error code value if any of the checks fail
 *****************************************************************************/
extern S32 srv_brw_bookmark_create_folder(srv_brw_bookmark_folder_struct *obj, srv_brw_bkm_folder_opeartion_enum folder_op);
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_brw_extract_file_extn
 * DESCRIPTION
 *  This function is to extract the file extension from the file path passed 
 * to the function
 * PARAMETERS
 *  file_path       [IN]        the file path in which to search
 *  file_dir        [IN|OUT]    the output buffer in which the result is copied
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_brw_extract_file_extn(U8 *file_path, U8 *file_extn);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmarks_standardize_file
 * DESCRIPTION
 *  This function is the service API to convert the bookmark file into standard 
 * vBookmark format
 * PARAMETERS
 *  file_path     [IN]     The path of the file to be converted to standard
 *  file_name     [IN]     The title of the Bookmark to be stored in the file
 *  file_url      [IN]     The URL if the Bookmark to be stored in the file
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 srv_brw_bookmarks_standardize_file(U8 *file_path, U8 *file_name, U8 *file_url);

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_validate_filename
 * DESCRIPTION
 *  This funtion is to check if a file name is valid or not by getting the 
 * filename checked from the FMGR API
 * PARAMETERS
 *  filename        [IN]        The filename to be validated
 * RETURNS
 *  MMI_BOOL        [OUT]       MMI_TRUE if valid MMI_FALSE otherwise
 *****************************************************************************/
extern MMI_BOOL srv_brw_bookmarks_validate_filename(U8 *filename);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_UCS2Strtolower
 * DESCRIPTION
 *  This function is to converts a unicode string to lowercase
 * PARAMETERS
 *  str     [IN]        The string in unicode to be converted to lower case
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_brw_UCS2Strtolower(S8 *str);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmarks_add_to_bookmark_silently
 * DESCRIPTION
 *  This function is the interface for adding bookmark received from provisioning
 * PARAMETERS
 *  obj     [IN]        structure pointer contaning the title and URL of the Bookmark
 * RETURNS
 *  void
 *****************************************************************************/
extern S16 srv_brw_bookmarks_add_to_bookmark_silently(srv_brw_bookmark_file_struct *obj);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmarks_modify_file_for_save
 * DESCRIPTION
 *  This function is to modify the filename if a same bookmark file is already 
 * present in the same location
 * PARAMETERS
 *  file_name     [IN|OUT]        The name of the file to be modified
 * parent_folder_index [IN]     The index of the parent folder of Bookmark
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_brw_bookmarks_modify_file_for_save(U8 *file_name, U8 parent_folder_index);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmarks_get_selected_item
 * DESCRIPTION
 *  This function is used for getting the index of the selected bookmark 
 * folder when returning from a bookmark folder to the previous one 
 * to highlight the selected folder 
 * PARAMETERS
 *  sel_folder_name     [IN]        The name of the folder selected
 * RETURNS
 *  void
 *****************************************************************************/
extern U32 srv_brw_bookmarks_get_selected_item(U8 *sel_folder_name, srv_brw_bkm_bookmark_list_struct* bkm_list);

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_bookmarks_create_standard_vbookmark_file
 * DESCRIPTION
 *  it creates a standard vbookmark file for other modules
 * PARAMETERS
 *  file_path       [IN]        The path of the bookmark file to be created
 *  url             [IN]        Url string which has to be included in the file contents
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 srv_brw_bookmarks_create_standard_vbookmark_file(U8 *file_path, U8 *url);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_writer_convert_file_to_standard_format
 * DESCRIPTION
 *  it convert the bookmark file into standard vbookmark format
 * PARAMETERS
 *  filepath	[IN]	path of the bookmark file
 *  title		[IN]	title of the bookmark
 *  url			[IN]	url of the bookmark
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 srv_vbkm_writer_convert_file_to_standard_format(FS_HANDLE fh, U8* title, U8* url);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_reader_validate_file
 * DESCRIPTION
 *  validates the vbookmark file and returns the status
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : for a valid vbookmark file
 *  MMI_FALSE : for an invalid vbookmark file
 *****************************************************************************/
extern MMI_BOOL srv_vbkm_reader_validate_file(FS_HANDLE fh);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_reader_is_vbookmark_file
 * DESCRIPTION
 *  checks whether the received file is a vbookmark file or not
 * PARAMETERS
 *  file_path	[IN]	path of the file
 * RETURNS
 *  MMI_TRUE  : for a vbookmark file
 *  MMI_FALSE : for non-vbookmark files
 *****************************************************************************/
extern MMI_BOOL srv_vbkm_reader_is_vbookmark_file(S8* file_path);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_reader_check_file_syntax
 * DESCRIPTION
 *  validates the vbookmark file and returns the status
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : for a valid vbookmark file
 *  MMI_FALSE : for an invalid vbookmark file
 *****************************************************************************/
extern U8 srv_vbkm_reader_check_file_syntax(FS_HANDLE fh);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_reader_extract_url
 * DESCRIPTION
 *  extracts the URL info from vbookmark file
 * PARAMETERS
 *  filepath	[IN]	path for the vbookmark file
 *  url			[OUT]	copy the extracted url info into it
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_vbkm_reader_extract_url(FS_HANDLE fh, U8* url);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_reader_extract_title
 * DESCRIPTION
 *  extracts the title info from vbookmark file
 * PARAMETERS
 *  filepath	[IN]	path for the vbookmark file
 *  url			[OUT]	copy the extracted url info into it
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_vbkm_reader_extract_title(FS_HANDLE fh, U8* title);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_reader_get_single_line
 * DESCRIPTION
 *  validates the vbookmark file and returns the status
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : for a valid vbookmark file
 *  MMI_FALSE : for an invalid vbookmark file
 *****************************************************************************/
extern MMI_BOOL srv_vbkm_reader_get_single_line(S8 *strOutput, FS_HANDLE fh);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_reader_get_line
 * DESCRIPTION
 *  Get a line from file system, excluding the escape characters for vbookmark
 * PARAMETERS
 *  strOutput       [IN/OUT]        Storage location for data
 *  fh              [IN]            File handle
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 srv_vbkm_reader_get_line(S8 *strOutput, FS_HANDLE fh);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_reader_get_field
 * DESCRIPTION
 *  validates the vbookmark file and returns the status
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : for a valid vbookmark file
 *  MMI_FALSE : for an invalid vbookmark file
 *****************************************************************************/
extern U8 srv_vbkm_reader_get_field(S8 *String);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_reader_check_header
 * DESCRIPTION
 *  Check the VCARD header.
 * PARAMETERS
 *  String      [IN]        String read from file for one line
 * RETURNS
 *  parse error cause
 *****************************************************************************/
extern U8 srv_vbkm_reader_check_header(S8 *String);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_reader_check_URL
 * DESCRIPTION
 *  Check the VCARD header.
 * PARAMETERS
 *  String      [IN]        String read from file for one line
 * RETURNS
 *  parse error cause
 *****************************************************************************/
extern MMI_BOOL srv_vbkm_reader_check_URL(S8 *string);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_reader_get_URL_string
 * DESCRIPTION
 *  Check the VCARD header.
 * PARAMETERS
 *  String      [IN]        String read from file for one line
 * RETURNS
 *  parse error cause
 *****************************************************************************/
extern void srv_vbkm_reader_get_URL_string(S8 *inBuff, U8* url);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_reader_get_title_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inBuff      [IN]        
 *  title      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_vbkm_reader_get_title_string(S8 *inBuff, U8* title);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_util_convert_to_system_encoding
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst     [?]     
 *  src     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
extern U8 srv_vbkm_util_convert_to_system_encoding(S8 *dst, S8 *src);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_util_convert_to_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst             [?]         
 *  dst_size        [IN]        
 *  src             [?]         
 *  encode          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_vbkm_util_convert_to_ucs2(S8 *dst, U8 dst_size, S8 *src, U8 encode);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_util_get_filename_and_extn
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dst             [?]         
 *  dst_size        [IN]        
 *  src             [?]         
 *  encode          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_vbkm_util_get_filename_and_extn(U8* file_path, U8* filename, U8* file_extn);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_util_convert_str_to_printable_form
 * DESCRIPTION
 *  
 * PARAMETERS
 *  printable_str		[OUT]         
 *  title				[IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_vbkm_util_convert_str_to_printable_form(S8* printable_str, S8* actual_str);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_util_strnicmp
 * DESCRIPTION
 *  Compare two string ignoring their cases
 * PARAMETERS
 *  src         [IN]        String pointer to be compared
 *  dest        [IN]        String pointer to be compared
 *  maxlen      [IN]        Lengh to be compared
 * RETURNS
 *  Ture if two string is identical, otherwise, false
 *****************************************************************************/
extern S8 srv_vbkm_util_strnicmp(S8 *src, S8 *dest, S32 maxlen);

/*****************************************************************************
 * FUNCTION
 *  srv_vbkm_util_cmp_filed
 * DESCRIPTION
 *  Check if the string constains a filed.
 * PARAMETERS
 *  srcString       [IN]        Source string to be compared.
 *  refString       [IN]        Header of the filed
 * RETURNS
 *  TRUE if string exists, otherwise FALSE.
 *****************************************************************************/
extern U8 srv_vbkm_util_cmp_filed(S8 *srcString, const S8 *refString);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bkm_initialize_bookmark_context
 * DESCRIPTION
 *  This function is to initialize the bookmark context and read all the 
 * bookmark data
 * PARAMETERS
 *  void
 * RETURNS
 *  return if the initialization was successful or not
 *****************************************************************************/
extern S32 srv_brw_bkm_initialize_bookmark_context(void);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bkm_deinitialize_bookmark_context
 * DESCRIPTION
 *  This function is to deinitialize the bookmark context and free all
 * the memory taken by it.
 * PARAMETERS
 *  void
 * RETURNS
 *  return if the deinitialization was successful or not
 *****************************************************************************/
extern MMI_BOOL srv_brw_bkm_deinitialize_bookmark_context(void);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmarks_create_root_folder_and_files
 * DESCRIPTION
 *  To create the root vbookmark folder and root bookmark file.
 * Also to read and store information of default bookmarks if
 * the feature is enabled.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 srv_brw_bookmarks_create_root_folder_and_files(void);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_sort_bookmark_list
 * DESCRIPTION
 *  This function is to sort the bookmark items list passed to it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_brw_bookmark_sort_bookmark_list(srv_brw_bkm_bookmark_list_struct* bkm_list, U8 start_index, U8 end_index);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bkm_arrange_bookmark_list_in_order
 * DESCRIPTION
 *  This function is to sort the bookmark items list passed to it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_brw_bkm_arrange_bookmark_list_in_order(srv_brw_bkm_bookmark_list_struct* bkm_list, U8 item_count);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bkm_update_bookmark_entry_to_file
 * DESCRIPTION
 *  This function is to update the content of the selected bookmark
 * index in the bookmark context to the root file
 * PARAMETERS
 *  selected_index  The selected index which needs to be updated
 * RETURNS
 *  S32 returns the file system error code if any
 *****************************************************************************/
extern S32 srv_brw_bkm_update_bookmark_entry_to_file(U8 selected_index);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bkm_remove_item
 * DESCRIPTION
 *  This function is to make the selected index free in the root
 * bookmark file
 * PARAMETERS
 *  selected_index  The selected index which needs to be removed
 * RETURNS
 *  S32 returns the file system error code if any
 *****************************************************************************/
extern S32 srv_brw_bkm_remove_item(U8 selected_index);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bkm_free_item_memory
 * DESCRIPTION
 *  This function is to free the memory taken by the bookmark item
 * bookmark file
 * PARAMETERS
 *  the bookmark items whose memory needs to be freed
 * RETURNS
 *  returns if object was successfully freed or not
 *****************************************************************************/
extern MMI_BOOL srv_brw_bkm_free_item_memory(srv_brw_bkm_bookmark_context_struct *bkm_item);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bkm_delete_bookmark
 * DESCRIPTION
 *  This function is to delete the selected bookmark index from the
 * context structure as well as the root file
 * PARAMETERS
 *  selected_index  The selected index which needs to be removed
 * RETURNS
 *  S32 returns the file system error code if any
 *****************************************************************************/
extern S32 srv_brw_bkm_delete_bookmark(U8 selected_index);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bkm_get_parent_folder_index
 * DESCRIPTION
 *  This function is to get the index location where the parent folder
 * which is passed to the API is present
 * PARAMETERS
 *  selected_index  The selected parent folder
 * RETURNS
 *  S8 returns the parent folders index in the bookmark context
 *****************************************************************************/
extern S8 srv_brw_bkm_get_parent_folder_index(U8 *parent_folder);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_list_find_entry
 * DESCRIPTION
 *  Interface for getting the matched items list,from bookmarks list, 
	corresponding to a given input URL string
 * PARAMETERS
 *  input_str       [IN]     
 * RETURNS
 *  Number of matched items in bookmark list
 *****************************************************************************/
extern S32 srv_brw_bookmark_list_find_entry(U8 *input_str);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_list_get_matched_item_count
 * DESCRIPTION
 *  API to get the count of matched items in the bookmark list
 * PARAMETERS
 *  void
 * RETURNS
 *  count
 *****************************************************************************/
extern S32 srv_brw_bookmark_list_get_matched_item_count(void);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_list_get_matched_item
 * DESCRIPTION
 *  Item call back function for Matched Bookmarks items list
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 * RETURNS
 *  The matched item URL
 *****************************************************************************/
extern S8* srv_brw_bookmark_list_get_matched_item(S32 item_index);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_list_get_matched_item_title
 * DESCRIPTION
 *  Item call back function for getting the title of Matched bookmark item
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 * RETURNS
 *  The matched item Title
 *****************************************************************************/
extern S8* srv_brw_bookmark_list_get_matched_item_title(S32 item_index);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_is_bookmark_present
 * DESCRIPTION
 *  This function is to check if the given bookmark name is already
 * present in the bookmark list passed to it or not.
 * PARAMETERS
 *  file_name       [IN]  The name of the Bookmark to search
 *  bkm_list          [IN]  The list of bookmark items in which to search
 *  bkm_count     [IN]  The count of the bookmark list items
 * RETURNS
 *  MMI_TRUE if the bookmark already exists MMI_FALSE otherwise
 *****************************************************************************/
extern MMI_BOOL srv_brw_is_bookmark_present(U8 *file_name, srv_brw_bkm_bookmark_list_struct *bkm_list, U8 bkm_count);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmarks_modify_filepath_for_save
 * DESCRIPTION
 *  This function is to modify the filename if a same bookmark file is already 
 * present in the same location
 * PARAMETERS
 *  file_path     [IN|OUT]        The full file path of the file to be saved
 * RETURNS
 *  void
 *****************************************************************************/
extern S16 srv_brw_bookmarks_modify_filepath_for_save(U8 *file_path);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_export_all_bookmarks
 * DESCRIPTION
 *  This function is to start the file export process
 * PARAMETERS
 *  sel_folder_path       [IN]  The path of the destination folder 
 * where all the bookmarks and folders are to be exported
 *  callback_function    [IN]   This callback function will be called
 * to notify the export process end and the the status of export
 * RETURNS
 *  S32 returns the error code if any happens while exporting the bookmarks
 *****************************************************************************/
extern S32 srv_brw_bookmark_export_all_bookmarks(U8 *sel_folder_path, srv_brw_bkm_rsp_funcptr_type callback_function);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmark_export_ind_hdlr
 * DESCRIPTION
 *  This function is to handle the 
 * MSG_ID_SRV_BRW_BOOKMARK_EXPORT_IND and continue
 * the export process
 *  msg         [IN] 
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_brw_bookmark_export_ind_hdlr(void *msg);

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bkm_get_bookmarks_count_for_op_hs
 * DESCRIPTION
 *  This function is to get the count of the bookmarks with same type
 * (USER_CREATED or DEFAULT) as passed to this function.
 * NOTE: no ASM memory is to be used in this function
 * PARAMETERS
 *  selected_file_type     [IN]   The type of the file whose count is to be 
 * calculated
 * RETURNS
 *  count if calculated successfully otherwise the error code.
 *****************************************************************************/
extern S32 srv_brw_bkm_get_bookmarks_count_for_op_hs(srv_brw_bkm_types_enum selected_file_type);

#endif /* __MMI_VBOOKMARK__ */

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERSRVPROTS_H */
