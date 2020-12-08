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
 * BrowserSrvBookmarks.c
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
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef MMI_BROWSERSRVBOOKMARKS_C
#define MMI_BROWSERSRVBOOKMARKS_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#ifdef __MMI_VBOOKMARK__
#include "FileMgrSrvGProt.h"
#include "BrowserSrvProts.h"
#include "BrowserSrvBookmarks.h"
#include "BrowserSrvGProt.h"
#ifdef BRW_DEFAULT_BKM_SUPPORT
#include "custom_wap_config.h"
#endif 

#include "BrowserSrvConfig.h"
#include "MMIDataType.h"
#include "fs_type.h"
#include "kal_general_types.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "app_buff_alloc.h"
#include "Unicodexdcl.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "gui_data_types.h"
#include "string.h"
#include "DebugInitDef_Int.h"
#include "vBookmark.h"
#include "stdio.h"
#include "common_nvram_editor_data_item.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "Conversions.h"
#include "BrowserSrvMain.h"
#include "BrowserSrvInterface.h"
#include "BrowserSrvMsgHdlr.h"
#include "app_str.h"
#include "app_qp.h"
#include "ctype.h"

const S8 *g_vbkm_field[VBKM_FIELD_TOTAL] = 
{
    "BEGIN",
    "VERSION",
    "TITLE",
    "URL",
    "X-IRMC-URL",
    "[InternetShortcut]",
    "END"
};

const S8 *g_vbkm_sub_field[VBKM_SUB_FIELD_TOTAL] = 
{
    "VBKM",
    "ENV",
    "CHARSET",
    "ENCODING",
};


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
void srv_brw_bookmarks_parse_filepath(srv_brw_bkm_opcode_enum op_code, U8* sel_file_path, U8* output_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(op_code)
    {
        case SRV_BRW_BKM_GET_FILE_EXTN:
        {
            srv_brw_extract_file_extn(sel_file_path, output_buffer);
            break;
        }
        case SRV_BRW_BKM_GET_FILENAME_WITHOUT_EXTN:
        {
            srv_brw_bookmark_extract_filename_without_extn(sel_file_path, output_buffer);
            break;
        }
        case SRV_BRW_BKM_GET_FOLDER_PATH:
        {
            srv_brw_bookmarks_extract_file_directory(sel_file_path, output_buffer);
            break;
        }
        case SRV_BRW_BKM_GET_FOLDER_NAME:
        {
            srv_brw_bookmarks_extract_folder_name(sel_file_path, output_buffer);
            break;
        }
        case SRV_BRW_BKM_GET_FILENAME:
        {
            srv_brw_bookmark_extract_filename(sel_file_path, output_buffer);
            break;
        }
    }
}


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
void srv_brw_bookmark_extract_filename_without_extn(U8 *file_path, U8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type start_loc;
    UI_string_type end_loc;
    S32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_loc = (UI_string_type) mmi_ucs2rchr((const S8*)file_path, (U16) '\\');
    if (start_loc)
    {
        end_loc = (UI_string_type) mmi_ucs2rchr((const S8*)start_loc, (U16) '.');
        if (end_loc)
        {
            len = end_loc - start_loc - 1;
            mmi_ucs2ncpy((S8*) file_name, (S8*) start_loc + ENCODING_LENGTH, len);
        }
        else
        {
            mmi_ucs2cpy((S8*) file_name, (S8*) start_loc + ENCODING_LENGTH);
        }
    }
}

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
void srv_brw_bookmark_extract_filename(U8 *file_path, U8 *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type start_loc;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_loc = (UI_string_type) mmi_ucs2rchr((const S8*)file_path, (U16) '\\');
    if (start_loc)
    {
        mmi_ucs2cpy((S8*) file_name, (S8*) start_loc + ENCODING_LENGTH);
    }
}

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
void srv_brw_bookmarks_extract_file_directory(U8 *file_path, U8 *file_dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type end_loc;
    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    end_loc = (UI_string_type) mmi_ucs2rchr((const S8*)file_path, (U16) '\\');
    if (end_loc)
    {
        len = end_loc - (UI_string_type) file_path;
        mmi_ucs2ncpy((S8*) file_dir, (S8*) file_path, len);
    }
}


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
void srv_brw_bookmarks_extract_folder_name(U8 *file_path, U8 *folder_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type end_loc;
    U8* temp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = (U8*) srv_brw_malloc ((SRV_BRW_BKM_MAX_PATH_LEN + 1) *ENCODING_LENGTH);
    mmi_ucs2ncpy((S8*) temp, (S8*) file_path, SRV_BRW_BKM_MAX_PATH_LEN);
    end_loc = (UI_string_type) mmi_ucs2rchr((const S8*)temp, (U16) '\\');
    if(end_loc)
    {
        *end_loc = NULL;
        end_loc = (UI_string_type) mmi_ucs2rchr((const S8*)temp, (U16) '\\');
    }
    if (end_loc)
    {
        mmi_ucs2cpy((S8*) folder_name, (S8*) end_loc + ENCODING_LENGTH);
    }
    srv_brw_free(temp);
}

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
void srv_brw_bookmarks_create_full_file_path(S8* folder_path, S8* file_name, S8* file_extn, S8* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(folder_path);
    MMI_ASSERT(file_name);
    MMI_ASSERT(file_extn);
    MMI_ASSERT(file_path);

    mmi_ucs2cpy((S8*) file_path, (S8*) folder_path);
    mmi_ucs2cat((S8*) file_path, (S8*) L"\\");
    mmi_ucs2cat((S8*) file_path, (S8*) file_name);
    mmi_ucs2cat((S8*) file_path, (S8*) L".");
    mmi_ucs2cat((S8*) file_path, (S8*) file_extn);
}


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
void srv_brw_trim_left_white_spaces(S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *tempstr;
    S32 index = 0, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(string);

    if (!mmi_ucs2strlen((S8*) string))
    {
        return;
    }

    len = mmi_ucs2strlen(string);
    tempstr = OslMalloc((len + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) tempstr, (S8*) string);

    while ((tempstr[index] == 9 && tempstr[index + 1] == 0) ||
           (tempstr[index] == 10 && tempstr[index + 1] == 0) ||
           (tempstr[index] == 13 && tempstr[index + 1] == 0) || (tempstr[index] == 32 && tempstr[index + 1] == 0))
    {
        index += ENCODING_LENGTH;
        if (index >= len * ENCODING_LENGTH)
        {
            break;
        }
    }

    mmi_ucs2cpy((S8*) string, (S8*) tempstr + index);
    OslMfree(tempstr);
    return;
}


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
void srv_brw_trim_right_white_spaces(S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(string);

    if (!mmi_ucs2strlen(string))
    {
        return;
    }

    index = (mmi_ucs2strlen(string) - 1) * ENCODING_LENGTH;

    while ((string[index] == 9 && string[index + 1] == 0) ||
           (string[index] == 10 && string[index + 1] == 0) ||
           (string[index] == 13 && string[index + 1] == 0) || (string[index] == 32 && string[index + 1] == 0))
    {
        index -= ENCODING_LENGTH;
        if (index <= 0)
        {
            break;
        }
    }

    string[index + 2] = '\0';
    string[index + 3] = '\0';

    return;
}


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
S32 srv_brw_bookmark_validate_file_for_add(srv_brw_bookmark_file_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 file_name[SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1] = {0};
    U8 array_index;
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    S8 parent_folder_index = SRV_BRW_ROOT_PARENT_INDEX;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
    MMI_ASSERT(bkm_cntx_ptr);
    if (g_srv_brw_cntx.bookmark_count == SRV_BRW_BKM_MAX_COUNT)
    {
        return SRV_BRW_BKM_ERROR_NOT_ENOUGH_MEMORY;
    }
    
    /* removing white spaces from title string */
    srv_brw_trim_left_white_spaces((S8*) obj->file_name);
    srv_brw_trim_right_white_spaces((S8*) obj->file_name);

    if(!mmi_ucs2strlen((S8*)obj->file_name))
    {
        return SRV_BRW_BKM_ERROR_EMPTY_FILE_NAME;
    }

    /* check filename regarding the special chars */
    if (!srv_brw_bookmarks_validate_filename(obj->file_name))
    {
        return SRV_BRW_BKM_ERROR_INVALID_TITLE;
    }

    /* validating the url string */
    if (srv_brw_validate_url((U8*)obj->file_url, SRV_BRW_MAX_URL_LEN) < 0)
    {
        return SRV_BRW_BKM_ERROR_INVALID_URL;
    }
    mmi_chset_ucs2_to_utf8_string((kal_uint8*)file_name, SRV_BRW_BKM_MAX_FILE_NAME_LEN, (kal_uint8*)obj->file_name);
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    parent_folder_index = srv_brw_bkm_get_parent_folder_index(obj->parent_folder);
#endif
    for(array_index = 0; array_index < SRV_BRW_BKM_MAX_COUNT; array_index++)
    {
        if(bkm_cntx_ptr[array_index].type == SRV_BRW_BKM_TYPE_USER_CREATED_FILE && !app_stricmp((S8*)file_name, (S8*)bkm_cntx_ptr[array_index].title))
        {
        #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
            if(bkm_cntx_ptr[array_index].parent_index == parent_folder_index)
        #endif
            {
                return SRV_BRW_BKM_ERROR_FILE_ALREADY_EXISTS;
            }
        }
    }
    return SRV_BRW_BKM_ERROR_OK;
}


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
S32 srv_brw_bookmark_validate_file_for_edit(srv_brw_bookmark_file_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 file_name[SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1] = {0};
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    U8 array_index;
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    S8 parent_folder_index = SRV_BRW_ROOT_PARENT_INDEX;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
    MMI_ASSERT(bkm_cntx_ptr);

    /* removing white spaces from title string */
    srv_brw_trim_left_white_spaces((S8*) obj->file_name);
    srv_brw_trim_right_white_spaces((S8*) obj->file_name);

    if(!mmi_ucs2strlen((S8*)obj->file_name))
    {
        return SRV_BRW_BKM_ERROR_EMPTY_FILE_NAME;
    }

    /* check filename regarding the special chars */
    if (!srv_brw_bookmarks_validate_filename(obj->file_name))
    {
        return SRV_BRW_BKM_ERROR_INVALID_TITLE;
    }

    /* validating the url string */
    if (srv_brw_validate_url((U8*)obj->file_url, SRV_BRW_MAX_URL_LEN) < 0)
    {
        return SRV_BRW_BKM_ERROR_INVALID_URL;
    }
    mmi_chset_ucs2_to_utf8_string((kal_uint8*)file_name, SRV_BRW_BKM_MAX_FILE_NAME_LEN, (kal_uint8*)obj->file_name);

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    parent_folder_index = srv_brw_bkm_get_parent_folder_index(obj->parent_folder);
#endif
    if (!app_stricmp((S8*)bkm_cntx_ptr[obj->selected_bookmark_index].title , (S8*) file_name)
    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        && (bkm_cntx_ptr[obj->selected_bookmark_index].parent_index == parent_folder_index)
    #endif
        )
    {
        return SRV_BRW_BKM_ERROR_OK;
    }
    else
    {
        for(array_index = 0; array_index < SRV_BRW_BKM_MAX_COUNT; array_index++)
        {
            if(bkm_cntx_ptr[array_index].type == SRV_BRW_BKM_TYPE_USER_CREATED_FILE && !app_stricmp((S8*)file_name, (S8*)bkm_cntx_ptr[array_index].title))
            {
            #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
                if(bkm_cntx_ptr[array_index].parent_index == parent_folder_index)
            #endif
                {
                    return SRV_BRW_BKM_ERROR_FILE_ALREADY_EXISTS;
                }
            }
        }
    }
    return SRV_BRW_BKM_ERROR_OK;
}

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
S32 srv_brw_bookmark_validate_folder(srv_brw_bookmark_folder_struct *obj, srv_brw_bkm_folder_opeartion_enum folder_op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 folder_name[(SRV_BRW_BKM_MAX_FOLDER_NAME_LEN + 1)*ENCODING_LENGTH] = {0};
    U8 array_index;
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
    MMI_ASSERT(bkm_cntx_ptr);

    if (folder_op == SRV_BRW_BKM_FOLDER_CREATE && g_srv_brw_cntx.bookmark_count == SRV_BRW_BKM_MAX_COUNT)
    {
        return SRV_BRW_BKM_ERROR_NOT_ENOUGH_MEMORY;
    }
    mmi_ucs2cpy((S8*) folder_name, (S8*) obj->folder_name);

    /* removing white spaces from folder name */
    srv_brw_trim_left_white_spaces((S8*) obj->folder_name);
    srv_brw_trim_right_white_spaces((S8*) obj->folder_name);

    if(!mmi_ucs2strlen((S8*)obj->folder_name))
    {
        return SRV_BRW_BKM_ERROR_EMPTY_FOLDER_NAME;
    }

    /* check folder name regarding the special chars */
    if (!srv_brw_bookmarks_validate_filename(obj->folder_name))
    {
        return FS_INVALID_FILENAME;
    }
    mmi_chset_ucs2_to_utf8_string((kal_uint8*)folder_name, SRV_BRW_BKM_MAX_FILE_NAME_LEN, (kal_uint8*)obj->folder_name);
    if(folder_op == SRV_BRW_BKM_FOLDER_RENAME)
    {
        if(!app_stricmp((S8*)folder_name, (S8*)bkm_cntx_ptr[obj->selected_folder_index].title))
        {
            return SRV_BRW_BKM_ERROR_OK;
        }
    }
    for(array_index = 0; array_index < SRV_BRW_BKM_MAX_COUNT; array_index++)
    {
        if(bkm_cntx_ptr[array_index].type != SRV_BRW_BKM_TYPE_EMPTY)
        {
            if(bkm_cntx_ptr[array_index].type == SRV_BRW_BKM_TYPE_FOLDER && !app_stricmp((S8*)folder_name, (S8*)bkm_cntx_ptr[array_index].title))
            {
                return FS_FILE_EXISTS;
            }
        }
    }
    return SRV_BRW_BKM_ERROR_OK;
}
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
S32 srv_brw_bookmark_add_item(srv_brw_bookmark_file_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code;
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    U8 array_index;
    S32 empty_slot = (S32)SRV_BRW_BKM_INVALID_INDEX;
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    S8 parent_index = (S8)SRV_BRW_ROOT_PARENT_INDEX;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
    MMI_ASSERT(bkm_cntx_ptr);

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    parent_index = srv_brw_bkm_get_parent_folder_index(obj->parent_folder);
#endif
    for(array_index = 0; array_index < SRV_BRW_BKM_MAX_COUNT; array_index++)
    {
        if(bkm_cntx_ptr[array_index].type == SRV_BRW_BKM_TYPE_EMPTY)
        {
            empty_slot = array_index;
            bkm_cntx_ptr[empty_slot].type = SRV_BRW_BKM_TYPE_USER_CREATED_FILE;
            bkm_cntx_ptr[empty_slot].timestamp = srv_brw_get_current_utc_time();

            bkm_cntx_ptr[empty_slot].title = (U8*)srv_brw_malloc(SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1);
            memset(bkm_cntx_ptr[empty_slot].title, 0, SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1);
            mmi_chset_ucs2_to_utf8_string((kal_uint8*)bkm_cntx_ptr[empty_slot].title, SRV_BRW_BKM_MAX_FILE_NAME_LEN, (kal_uint8*) obj->file_name);

            bkm_cntx_ptr[empty_slot].url = (U8*)srv_brw_malloc(SRV_BRW_MAX_URL_LEN + 1);
            memset(bkm_cntx_ptr[empty_slot].url, 0, SRV_BRW_MAX_URL_LEN + 1);
            mmi_ucs2_to_asc((CHAR*)bkm_cntx_ptr[empty_slot].url, (CHAR*) obj->file_url);

        #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
            bkm_cntx_ptr[empty_slot].parent_index = parent_index;
        #endif
            break;
        }
    }
    MMI_ASSERT(empty_slot != SRV_BRW_BKM_INVALID_INDEX);
    error_code = srv_brw_bkm_update_bookmark_entry_to_file(empty_slot);
    if(error_code < FS_NO_ERROR)
    {
        srv_brw_bkm_free_item_memory(&bkm_cntx_ptr[empty_slot]);
        bkm_cntx_ptr[empty_slot].type = SRV_BRW_BKM_TYPE_EMPTY;
        /* free the new items memory here if it is not update in the file */
        return error_code;
    }
    g_srv_brw_cntx.bookmark_count++;
    return SRV_BRW_BKM_ERROR_OK;
}


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
S32 srv_brw_bookmark_add_replace_item(srv_brw_bookmark_file_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 file_name[SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1] = {0};
    S32 error_code = SRV_BRW_BKM_ERROR_OK;
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    U8 array_index;
    S32 selected_slot = (S32)SRV_BRW_BKM_INVALID_INDEX;
    srv_brw_bkm_bookmark_context_struct *prev_data;
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    S8 parent_folder_index;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
    MMI_ASSERT(bkm_cntx_ptr);
    srv_brw_trim_left_white_spaces((S8*) obj->file_name);
    srv_brw_trim_right_white_spaces((S8*) obj->file_name);
    mmi_chset_ucs2_to_utf8_string((kal_uint8*)file_name, SRV_BRW_BKM_MAX_FILE_NAME_LEN, (kal_uint8*)obj->file_name);
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    parent_folder_index = srv_brw_bkm_get_parent_folder_index(obj->parent_folder);
#endif
    for(array_index = 0; array_index < SRV_BRW_BKM_MAX_COUNT; array_index++)
    {
        if(bkm_cntx_ptr[array_index].type == SRV_BRW_BKM_TYPE_USER_CREATED_FILE && !app_stricmp((S8*)file_name, (S8*)bkm_cntx_ptr[array_index].title))
        {
        #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
            if(bkm_cntx_ptr[array_index].parent_index == parent_folder_index)
        #endif
            {
                selected_slot = array_index;
                prev_data = (srv_brw_bkm_bookmark_context_struct*) srv_brw_malloc(sizeof(srv_brw_bkm_bookmark_context_struct));
                memcpy(prev_data, &bkm_cntx_ptr[selected_slot], sizeof(srv_brw_bkm_bookmark_context_struct));

                bkm_cntx_ptr[selected_slot].type = SRV_BRW_BKM_TYPE_USER_CREATED_FILE;
                bkm_cntx_ptr[selected_slot].timestamp = srv_brw_get_current_utc_time();

                bkm_cntx_ptr[selected_slot].title = (U8*)srv_brw_malloc(SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1);
                memset(bkm_cntx_ptr[selected_slot].title, 0, SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1);
                mmi_chset_ucs2_to_utf8_string((kal_uint8*)bkm_cntx_ptr[selected_slot].title, SRV_BRW_BKM_MAX_FILE_NAME_LEN, (kal_uint8*) obj->file_name);

                bkm_cntx_ptr[selected_slot].url = (U8*)srv_brw_malloc(SRV_BRW_MAX_URL_LEN + 1);
                memset(bkm_cntx_ptr[selected_slot].url, 0, SRV_BRW_MAX_URL_LEN + 1);
                mmi_ucs2_to_asc((CHAR*)bkm_cntx_ptr[selected_slot].url, (CHAR*) obj->file_url);

            #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
                bkm_cntx_ptr[selected_slot].parent_index = parent_folder_index;
            #endif
                break;
            }
        }
    }
    MMI_ASSERT(selected_slot != SRV_BRW_BKM_INVALID_INDEX);
    error_code = srv_brw_bkm_update_bookmark_entry_to_file(selected_slot);
    if(error_code < FS_NO_ERROR)
    {
        /* free the new items memory here if it is not update in the file */
        srv_brw_bkm_free_item_memory(&bkm_cntx_ptr[selected_slot]);
        memcpy(&bkm_cntx_ptr[selected_slot], prev_data, sizeof(srv_brw_bkm_bookmark_context_struct));
    }
    else
    {
        srv_brw_bkm_free_item_memory(prev_data);
    }
    srv_brw_free_browser_memory((void**)&(prev_data));
    return error_code;
}


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
S32 srv_brw_bookmark_edit_item(srv_brw_bookmark_file_struct *obj, MMI_BOOL internal_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code;
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    srv_brw_bkm_bookmark_context_struct *prev_data;
    S32 selected_slot;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
    MMI_ASSERT(bkm_cntx_ptr);
    selected_slot = obj->selected_bookmark_index;
    MMI_ASSERT(selected_slot >= 0);

    prev_data = (srv_brw_bkm_bookmark_context_struct*) srv_brw_malloc(sizeof(srv_brw_bkm_bookmark_context_struct));
    memcpy(prev_data, &bkm_cntx_ptr[selected_slot], sizeof(srv_brw_bkm_bookmark_context_struct));

    bkm_cntx_ptr[selected_slot].type = SRV_BRW_BKM_TYPE_USER_CREATED_FILE;
    bkm_cntx_ptr[selected_slot].timestamp = srv_brw_get_current_utc_time();

    bkm_cntx_ptr[selected_slot].title = (U8*)srv_brw_malloc(SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1);
    memset(bkm_cntx_ptr[selected_slot].title, 0, SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1);
    mmi_chset_ucs2_to_utf8_string((kal_uint8*)bkm_cntx_ptr[selected_slot].title, SRV_BRW_BKM_MAX_FILE_NAME_LEN, (kal_uint8*) obj->file_name);

    bkm_cntx_ptr[selected_slot].url = (U8*)srv_brw_malloc(SRV_BRW_MAX_URL_LEN + 1);
    memset(bkm_cntx_ptr[selected_slot].url, 0, SRV_BRW_MAX_URL_LEN + 1);
    mmi_ucs2_to_asc((CHAR*)bkm_cntx_ptr[selected_slot].url, (CHAR*) obj->file_url);

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    bkm_cntx_ptr[selected_slot].parent_index = srv_brw_bkm_get_parent_folder_index(obj->parent_folder);
#endif

    error_code = srv_brw_bkm_update_bookmark_entry_to_file(selected_slot);
    if(error_code < FS_NO_ERROR)
    {
        /* free the new items memory here if it is not update in the file */
        srv_brw_bkm_free_item_memory(&bkm_cntx_ptr[selected_slot]);
        memcpy(&bkm_cntx_ptr[selected_slot], prev_data, sizeof(srv_brw_bkm_bookmark_context_struct));
    }
    else
    {
        srv_brw_bkm_free_item_memory(prev_data);
    }
    srv_brw_free_browser_memory((void**)&(prev_data));
    return error_code;
}


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
S32 srv_brw_bookmark_edit_replace_item(srv_brw_bookmark_file_struct *obj, MMI_BOOL internal_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 file_name[SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1] = {0};
    S32 error_code = SRV_BRW_BKM_ERROR_OK;
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    U8 array_index;
    S32 selected_slot = (S32)SRV_BRW_BKM_INVALID_INDEX;
    srv_brw_bkm_bookmark_context_struct *prev_data;
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    S8 parent_folder_index;
#endif
    S32 original_slot;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
    MMI_ASSERT(bkm_cntx_ptr);
    original_slot = obj->selected_bookmark_index;
    MMI_ASSERT(original_slot > SRV_BRW_BKM_INVALID_INDEX);

    mmi_chset_ucs2_to_utf8_string((kal_uint8*)file_name, SRV_BRW_BKM_MAX_FILE_NAME_LEN, (kal_uint8*) obj->file_name);
#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    parent_folder_index = srv_brw_bkm_get_parent_folder_index(obj->parent_folder);
#endif
    for(array_index = 0; array_index < SRV_BRW_BKM_MAX_COUNT; array_index++)
    {
        if(bkm_cntx_ptr[array_index].type == SRV_BRW_BKM_TYPE_USER_CREATED_FILE && !app_stricmp((S8*)file_name, (S8*)bkm_cntx_ptr[array_index].title))
        {
        #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
            if(bkm_cntx_ptr[array_index].parent_index == parent_folder_index)
        #endif
            {
                selected_slot = array_index;
                prev_data = (srv_brw_bkm_bookmark_context_struct*) srv_brw_malloc(sizeof(srv_brw_bkm_bookmark_context_struct));
                memcpy(prev_data, &bkm_cntx_ptr[selected_slot], sizeof(srv_brw_bkm_bookmark_context_struct));

                bkm_cntx_ptr[selected_slot].type = SRV_BRW_BKM_TYPE_USER_CREATED_FILE;
                bkm_cntx_ptr[selected_slot].timestamp = srv_brw_get_current_utc_time();

                bkm_cntx_ptr[selected_slot].title = (U8*)srv_brw_malloc(SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1);
                memset(bkm_cntx_ptr[selected_slot].title, 0, SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1);
                mmi_chset_ucs2_to_utf8_string((kal_uint8*)bkm_cntx_ptr[selected_slot].title, SRV_BRW_BKM_MAX_FILE_NAME_LEN, (kal_uint8*) obj->file_name);

                bkm_cntx_ptr[selected_slot].url = (U8*)srv_brw_malloc(SRV_BRW_MAX_URL_LEN + 1);
                memset(bkm_cntx_ptr[selected_slot].url, 0, SRV_BRW_MAX_URL_LEN + 1);
                mmi_ucs2_to_asc((CHAR*)bkm_cntx_ptr[selected_slot].url, (CHAR*) obj->file_url);

            #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
                bkm_cntx_ptr[selected_slot].parent_index = parent_folder_index;
            #endif
                break;
            }
        }
    }
    MMI_ASSERT(selected_slot != SRV_BRW_BKM_INVALID_INDEX);
    error_code = srv_brw_bkm_update_bookmark_entry_to_file(selected_slot);
    if(error_code < FS_NO_ERROR)
    {
        /* free the new items memory here if it is not update in the file */
        srv_brw_bkm_free_item_memory(&bkm_cntx_ptr[selected_slot]);
        memcpy(&bkm_cntx_ptr[selected_slot], prev_data, sizeof(srv_brw_bkm_bookmark_context_struct));
    }
    else
    {
        srv_brw_bkm_free_item_memory(prev_data);
        error_code = srv_brw_bkm_remove_item(original_slot);
        if(error_code == FS_NO_ERROR)
        {
            bkm_cntx_ptr[original_slot].type = SRV_BRW_BKM_TYPE_EMPTY;
            srv_brw_bkm_free_item_memory(&bkm_cntx_ptr[original_slot]);
        }
    }
    srv_brw_free_browser_memory((void**)&(prev_data));
    g_srv_brw_cntx.bookmark_count--;
    return error_code;
}


#ifdef    __MMI_BRW_BKM_FOLDER_SUPPORT__
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
S32 srv_brw_bookmark_create_new_folder(srv_brw_bookmark_folder_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code;
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    U8 array_index;
    S8 empty_slot = SRV_BRW_BKM_INVALID_INDEX;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
    MMI_ASSERT(bkm_cntx_ptr);

    for(array_index = 0; array_index < SRV_BRW_BKM_MAX_COUNT; array_index++)
    {
        if(bkm_cntx_ptr[array_index].type == SRV_BRW_BKM_TYPE_EMPTY)
        {
            empty_slot = array_index;
            bkm_cntx_ptr[empty_slot].type = SRV_BRW_BKM_TYPE_FOLDER;
            bkm_cntx_ptr[empty_slot].timestamp = srv_brw_get_current_utc_time();

            bkm_cntx_ptr[empty_slot].title = (U8*)srv_brw_malloc(SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1);
            memset(bkm_cntx_ptr[empty_slot].title, 0, SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1);
            mmi_chset_ucs2_to_utf8_string((kal_uint8*)bkm_cntx_ptr[empty_slot].title, SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1, (kal_uint8*) obj->folder_name);
            bkm_cntx_ptr[empty_slot].parent_index = SRV_BRW_ROOT_PARENT_INDEX;
            break;
        }
    }
    MMI_ASSERT((S8)empty_slot != SRV_BRW_BKM_INVALID_INDEX);
    error_code = srv_brw_bkm_update_bookmark_entry_to_file(empty_slot);
    if(error_code < FS_NO_ERROR)
    {
        srv_brw_bkm_free_item_memory(&bkm_cntx_ptr[empty_slot]);
        bkm_cntx_ptr[empty_slot].type = SRV_BRW_BKM_TYPE_EMPTY;
        /* free the new items memory here if it is not update in the file */
        return error_code;
    }
    g_srv_brw_cntx.bookmark_count++;
    return SRV_BRW_BKM_ERROR_OK;
}


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
S32 srv_brw_bookmark_rename_folder(srv_brw_bookmark_folder_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code = SRV_BRW_BKM_ERROR_TOTAL;
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    U8 previous_folder_name[SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(obj);
    MMI_ASSERT(bkm_cntx_ptr);

    if(bkm_cntx_ptr[obj->selected_folder_index].type == SRV_BRW_BKM_TYPE_FOLDER)
    {
        strcpy((S8*)previous_folder_name, (S8*)bkm_cntx_ptr[obj->selected_folder_index].title);
        mmi_chset_ucs2_to_utf8_string((kal_uint8*)bkm_cntx_ptr[obj->selected_folder_index].title, SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1, (kal_uint8*) obj->folder_name);
        error_code = srv_brw_bkm_update_bookmark_entry_to_file(obj->selected_folder_index);
        if(error_code < FS_NO_ERROR)
        {
            strcpy((S8*)bkm_cntx_ptr[obj->selected_folder_index].title, (S8*)previous_folder_name);
        }
    }
    return error_code;
}


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
S32 srv_brw_bookmark_create_folder(srv_brw_bookmark_folder_struct *obj, srv_brw_bkm_folder_opeartion_enum folder_op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(folder_op == SRV_BRW_BKM_FOLDER_CREATE)
    {
        return (srv_brw_bookmark_create_new_folder(obj));
    }
    else
    {
        return (srv_brw_bookmark_rename_folder(obj));
    }
}
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
void srv_brw_extract_file_extn(U8 *file_path, U8 *file_extn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type start_loc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    start_loc = (UI_string_type) mmi_ucs2rchr((const S8*)file_path, (U16) '.');
    if (start_loc)
    {
        mmi_ucs2cpy((S8*) file_extn, (S8*) start_loc + ENCODING_LENGTH);
        srv_brw_UCS2Strtolower((S8*) file_extn);
    }
}


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
S32 srv_brw_bookmarks_standardize_file(U8 *file_path, U8 *file_name, U8 *file_url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 error_code = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_handle = FS_Open((UI_string_type) file_path, FS_READ_WRITE);
    if (file_handle < 0)
    {
        return file_handle;
    }
    else
    {
        error_code = srv_vbkm_writer_convert_file_to_standard_format(file_handle, file_name, file_url);
        FS_Close(file_handle);
        return error_code;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmarks_validate_filename
 * DESCRIPTION
 *  This funtion is to check if a file name is valid or not by getting the 
 * filename checked from the FMGR API
 * PARAMETERS
 *  filename        [IN]        The filename to be validated
 * RETURNS
 *  MMI_BOOL        [OUT]       MMI_TRUE if valid MMI_FALSE otherwise
 *****************************************************************************/
MMI_BOOL srv_brw_bookmarks_validate_filename(U8 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_fmgr_path_is_filename_valid((const WCHAR*)((S8*) filename));
}


#ifdef __MMI_CCA_SUPPORT__
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
S16 srv_brw_bookmarks_add_to_bookmark_silently(srv_brw_bookmark_file_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 status;
    S32 error_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.bookmark_count == SRV_BRW_BKM_MAX_COUNT)
    {
        return SRV_BRW_BKM_PROVISIONING_MEMORY_FULL;
    }

    if (srv_brw_validate_url((U8*)obj->file_url, SRV_BRW_MAX_URL_LEN) < 0)
    {
        return SRV_BRW_BKM_PROVISIONING_INVALID_URL;
    }

    srv_brw_trim_left_white_spaces((S8*) obj->file_name);
    srv_brw_trim_right_white_spaces((S8*) obj->file_name);

    /* check filename regarding the special chars */
    if (!srv_brw_bookmarks_validate_filename(obj->file_name))
    {
        return SRV_BRW_BKM_PROVISIONING_INVALID_TITLE;
    }

    if (!mmi_ucs2strlen((S8*) obj->file_name))
    {
        mmi_ucs2cpy((S8*) obj->file_name, (S8*) SRV_BRW_BKM_DEFAULT_FILE_NAME);
    }
    srv_brw_bookmarks_modify_file_for_save(obj->file_name, SRV_BRW_ROOT_PARENT_INDEX);
    obj->selected_bookmark_index = (S8)SRV_BRW_BKM_INVALID_INDEX;
    error_code = srv_brw_bookmark_add_item(obj);
    if (error_code < 0)
    {
        if (error_code == FS_INVALID_FILENAME)
        {
            status = SRV_BRW_BKM_PROVISIONING_INVALID_TITLE;
        }
        else if (error_code == FS_ROOT_DIR_FULL || error_code == FS_DISK_FULL)
        {
            status = SRV_BRW_BKM_PROVISIONING_MEMORY_FULL;
        }
        else
        {
            status = SRV_BRW_BKM_PROVISIONING_FILE_SYSTEM_ERROR;
        }
    }
    else
    {
        mmi_event_struct evt;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BRW_BKM_PROVISIONING_IND);
        MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);
        status = SRV_BRW_BKM_PROVISIONING_SUCCESS;
    }
    return (status);
}
#endif /* #ifdef __MMI_CCA_SUPPORT__ */

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
void srv_brw_UCS2Strtolower(S8 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(str);

    for (index = 0; index < mmi_ucs2strlen((S8*) str) * ENCODING_LENGTH; index += 2)
    {
        if ((str[index] >= 'A') && (str[index] <= 'Z'))
        {
            str[index] += 'a' - 'A';
        }
    }
    return;
}


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
void srv_brw_bookmarks_modify_file_for_save(U8 *file_name, U8 parent_folder_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_bkm_bookmark_list_struct bookmark_list[SRV_BRW_BKM_MAX_COUNT];
    U8 array_index, array_count = 0;
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    U8 file_index_ascii[10];
    U16 file_index = 0;
    U8 file_sufx_len = 0;
    U8 *temp_file_name;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(bkm_cntx_ptr);
    for(array_index = 0; array_index < SRV_BRW_BKM_MAX_COUNT; array_index++)
    {
        if(bkm_cntx_ptr[array_index].type == SRV_BRW_BKM_TYPE_USER_CREATED_FILE 
        #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
            && bkm_cntx_ptr[array_index].parent_index == parent_folder_index
        #endif
			)
        {
            bookmark_list[array_count++].actual_index = array_index;
        }
    }
    temp_file_name = (U8*)srv_brw_malloc((SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1)* ENCODING_LENGTH);
    memset(temp_file_name, 0, (SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1)* ENCODING_LENGTH);
    mmi_chset_ucs2_to_utf8_string((kal_uint8*)temp_file_name, SRV_BRW_BKM_MAX_FILE_NAME_LEN, (kal_uint8*) file_name);

    while(srv_brw_is_bookmark_present(temp_file_name, bookmark_list, array_count))
    {
        mmi_chset_ucs2_to_utf8_string((kal_uint8*)temp_file_name, SRV_BRW_BKM_MAX_FILE_NAME_LEN, (kal_uint8*) file_name);
        ++file_index;
        sprintf((S8*) file_index_ascii, "(%d)", file_index);
        file_sufx_len = strlen((S8*) file_index_ascii);
        if (strlen((S8*) temp_file_name) > (SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN - file_sufx_len))
        {
            temp_file_name[SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN - file_sufx_len] = '\0';
        }
        strcat((S8*)temp_file_name, (S8*)file_index_ascii);
    }
    mmi_chset_utf8_to_ucs2_string((U8*) file_name, (SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH, (U8*) temp_file_name);
    srv_brw_free(temp_file_name);
}

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
S32 srv_brw_bookmarks_create_root_folder_and_files(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    U16 record_count;
    WCHAR *folder_path;
    WCHAR *root_file_path;
#ifdef BRW_DEFAULT_BKM_SUPPORT
    U8 index;
    S16 NvramError;
    srv_brw_bkm_bookmark_struct *def_bkm_data;
    nvram_wap_bookmark_struct* def_bkms_list;
#endif
    U16 timestamp = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* create bookmark folder if it is not being created */
    folder_path = (WCHAR*)OslMalloc((mmi_ucs2strlen((S8*) g_srv_brw_cntx.default_folder_path) + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) folder_path, (S8*) g_srv_brw_cntx.default_folder_path);
    file_handle = FS_Open((const WCHAR*) folder_path, FS_READ_ONLY | FS_OPEN_DIR);
    if (file_handle >= FS_NO_ERROR)
    {
        FS_Close(file_handle);
        OslMfree(folder_path);
        return FS_NO_ERROR; /* don't re-create default bookmarks if already done once */
    }
    else
    {
        FS_CreateDir((const WCHAR*) folder_path);
    }
    OslMfree(folder_path);

    root_file_path = (WCHAR*)OslMalloc((mmi_ucs2strlen((S8*) g_srv_brw_cntx.default_folder_path) + mmi_ucs2strlen((S8*)SRV_BRW_BKM_ROOT_FILE_NAME) + 2) * ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) root_file_path, (S8*) g_srv_brw_cntx.default_folder_path);
    mmi_ucs2cat((S8*) root_file_path, (S8*) L"\\");
    mmi_ucs2cat((S8*) root_file_path, (S8*) SRV_BRW_BKM_ROOT_FILE_NAME);

    file_handle = FS_Open((const WCHAR*) root_file_path, FS_READ_WRITE | FS_CREATE);
    if(file_handle < 0)
    {
        OslMfree(root_file_path);
        return file_handle;
    }
    //FS_Extend(file_handle, SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE * SRV_BRW_BKM_MAX_COUNT);
#ifdef BRW_DEFAULT_BKM_SUPPORT
    FS_Seek(file_handle, 0, SEEK_SET);

    /*Reading default bookmarks from NVRAM*/
    for (record_count = 1; record_count <= NVRAM_EF_WAP_BOOKMARK_LIST_TOTAL_RECORDS; record_count++)
    {
        def_bkms_list = (nvram_wap_bookmark_struct*) OslMalloc(NVRAM_WAP_BOOKMARK_MAX_ENTRY_IN_ONE_RECORD * sizeof(nvram_wap_bookmark_struct));
        memset(def_bkms_list, 0, NVRAM_WAP_BOOKMARK_MAX_ENTRY_IN_ONE_RECORD * sizeof(nvram_wap_bookmark_struct));

        ReadRecord(
            NVRAM_EF_WAP_BOOKMARK_LIST_LID,
            record_count,
            def_bkms_list,
            NVRAM_EF_WAP_BOOKMARK_LIST_SIZE,
            &NvramError);

        /* create bookmark file for each available URL */
        for (index = 0; index < NVRAM_WAP_BOOKMARK_MAX_ENTRY_IN_ONE_RECORD; index++)
        {
            if (!def_bkms_list[index].empty)
            {
                U8* buffer;
                U32 nBytes;
                U16 title_len = 0;
                U16 url_len = 0;
                def_bkm_data = (srv_brw_bkm_bookmark_struct*) OslMalloc(sizeof(srv_brw_bkm_bookmark_struct));
                memset(def_bkm_data, 0, sizeof(srv_brw_bkm_bookmark_struct));
                if(def_bkms_list[index].dcs_flag == 0)
                {
                    title_len = mmi_chset_utf8_strlen((U8*)def_bkms_list[index].title);
                    if (title_len > SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN)
                    {
                        continue;
                    }
                    else
                    {
                        strncpy((S8*) def_bkm_data->title, (S8*) def_bkms_list[index].title, SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN);
                    }
                }
                else if (def_bkms_list[index].dcs_flag == 1)
                {
                    title_len = mmi_ucs2strlen((S8*)def_bkms_list[index].title);
                    if (title_len > SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN)
                    {
                        continue;
                    }
                    else
                    {
                        mmi_chset_ucs2_to_utf8_string((kal_uint8*)def_bkm_data->title, SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN, (kal_uint8*) def_bkms_list[index].title);
                        title_len = mmi_charset_ucs2_to_utf8_length_in_bytes((kal_uint8*)def_bkms_list[index].title);
                    }
                }
                strcpy((S8*) def_bkm_data->url, (S8*) def_bkms_list[index].url);
                url_len = strlen((S8*)def_bkm_data->url);
                memset((S8*)def_bkm_data->url + url_len, SRV_BRW_BKM_URL_PADDING_TOKEN, SRV_BRW_MAX_URL_LEN - url_len);
                memset((S8*)def_bkm_data->title + title_len, SRV_BRW_BKM_TITLE_PADDING_TOKEN, SRV_BRW_BKM_MAX_FILE_NAME_LEN - title_len);
                buffer = (U8*)OslMalloc(SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE + 1);
                memset(buffer, 0, SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE + 1);
            #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
                sprintf((S8*)buffer, "%2d%s%10d%s%s%s%s%s%3d%s", 
                    SRV_BRW_BKM_TYPE_DEFAULT_FILE,
                    SRV_BRW_BKM_LINE_BREAK,
                    timestamp++,
                    SRV_BRW_BKM_LINE_BREAK,
                    def_bkm_data->title,
                    SRV_BRW_BKM_LINE_BREAK,
                    def_bkm_data->url,
                    SRV_BRW_BKM_LINE_BREAK,
                    SRV_BRW_ROOT_PARENT_INDEX,
                    SRV_BRW_BKM_LINE_BREAK);
            #else
                sprintf((S8*)buffer, "%2d%s%10d%s%s%s%s%s",
                    SRV_BRW_BKM_TYPE_DEFAULT_FILE,
                    SRV_BRW_BKM_LINE_BREAK,
                    timestamp++,
                    SRV_BRW_BKM_LINE_BREAK,
                    def_bkm_data->title,
                    SRV_BRW_BKM_LINE_BREAK,
                    def_bkm_data->url,
                    SRV_BRW_BKM_LINE_BREAK);
            #endif
                FS_Write(file_handle, buffer, strlen((S8*)buffer), (U32*)&nBytes);
                OslMfree(buffer);
                OslMfree(def_bkm_data);
            }
        }
        OslMfree(def_bkms_list);
    }
#endif /* BRW_DEFAULT_BKM_SUPPORT */ 
    FS_Close(file_handle);
    return FS_NO_ERROR;
}



#ifdef    __MMI_BRW_BKM_FOLDER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmarks_get_selected_item
 * DESCRIPTION
 *  This function is used for getting the index of the selected bookmark 
 * folder when returning from a bookmark folder to the previous one 
 * to highlight the selected folder 
 * PARAMETERS
 *  sel_folder_name     [IN]        The name of the folder selected
 *  bkm_list
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_brw_bookmarks_get_selected_item(U8 *sel_folder_name, srv_brw_bkm_bookmark_list_struct* bkm_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    U8 array_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(bkm_list);
    MMI_ASSERT(bkm_cntx_ptr);
    for(array_index = 0; bkm_cntx_ptr[bkm_list[array_index].actual_index].type == SRV_BRW_BKM_TYPE_FOLDER;
        array_index++)
    {
        if(!app_stricmp((S8*)bkm_cntx_ptr[bkm_list[array_index].actual_index].title, (S8*)sel_folder_name))
        {
            return array_index;
        }
    }
    return 0;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_brw_bookmarks_create_standard_vbookmark_file
 * DESCRIPTION
 *  it creates a standard vbookmark file for other modules
 * PARAMETERS
 *  file_path       [IN]        
 *  url             [IN]        Url string which has to be included in the file contents
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_brw_bookmarks_create_standard_vbookmark_file(U8 *file_path, U8 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    U8 file_name[(SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN + 1) * ENCODING_LENGTH];
    S32 error_code = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_bookmarks_parse_filepath(SRV_BRW_BKM_GET_FILENAME_WITHOUT_EXTN, file_path, file_name);

    file_handle = FS_Open((UI_string_type) file_path, FS_READ_WRITE | FS_CREATE);
    if (file_handle < 0)
    {
        return file_handle;
    }
    else
    {
        if ((error_code = srv_vbkm_writer_convert_file_to_standard_format(file_handle, file_name, url)) == FS_NO_ERROR)
        {
            FS_Close(file_handle);
            return error_code;
        }
        else
        {
            FS_Close(file_handle);
            FS_Delete((UI_string_type) file_path);
            return error_code;
        }
    }
}


#ifdef __COSMOS_MMI_PACKAGE__
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
S32 srv_brw_bookmark_list_find_entry(U8 *input_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ip_address;
    MMI_BOOL list_ip_address;
    U8 *search_str1;
    U8 *search_str2;
    U8 temp_str[(SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH];
    U8 temp_str2[(SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH];
    U8 *pos = NULL;
    U16 len;
    S32 num_of_matched_items = 0;
    S32 index;
    S32 add_list_index;
    S32 matched_item_index = 0;
    U8 title_str[(SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH];
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check the URL string */
    MMI_ASSERT(bkm_cntx_ptr);
    if (!input_str || !g_srv_brw_cntx.bookmark_count)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_bookmark_items = 0;
        return 0;
    }
    /* Skip the URI scheme */
    pos = (U8*) mmi_ucs2str((const S8*)input_str, (const S8*)L"://");
    if (pos)
    {
        input_str = pos + 3 * ENCODING_LENGTH;
    }

    /* Display the complete address list if input URL host part is empty */
    if (!mmi_ucs2strlen((S8*) input_str))
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_bookmark_items = 0;
        for (index = 0; index < SRV_BRW_BKM_MAX_COUNT; index++)
        {
            if(bkm_cntx_ptr[index].type == SRV_BRW_BKM_TYPE_USER_CREATED_FILE ||
                bkm_cntx_ptr[index].type == SRV_BRW_BKM_TYPE_DEFAULT_FILE )
            {
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_bookmark_items_list[matched_item_index++] = index;
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_bookmark_items++;
            }
        }
        return g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_bookmark_items;
    }

    /* Check if it is a IP address */
    ip_address = MMI_TRUE;
    len = mmi_ucs2strlen((S8*) input_str);
    mmi_ucs2_to_asc(
        (CHAR*) temp_str,
        (CHAR*) input_str);
    for (index = 0; index < len; index++)
    {
        if(temp_str[index] == '/')
        {
            break;
        }
        if(!((temp_str[index] >= 48 && temp_str[index] <= 57) || temp_str[index] == '.' || temp_str[index] == ':'))
        {
            ip_address = MMI_FALSE;
            break;
        }
    }

    /* Search the matched URLs */
    for (index = 0; index < SRV_BRW_BKM_MAX_COUNT; index++)
    {
        if(bkm_cntx_ptr[index].type == SRV_BRW_BKM_TYPE_USER_CREATED_FILE ||
            bkm_cntx_ptr[index].type == SRV_BRW_BKM_TYPE_DEFAULT_FILE )
        {
            mmi_asc_to_ucs2(
                (S8*) temp_str,
                (S8*) bkm_cntx_ptr[index].url);

            /* Skip the URI scheme and extract & save the URL starting from first part */
            pos = (U8*) mmi_ucs2str((const S8*)temp_str, (const S8*)L"://");
            if (pos)
            {
                search_str1 = pos + 3 * ENCODING_LENGTH;
            }
            else
            {
                search_str1 = NULL;
            }
            /*Check if the address list URL is a IP address*/
            list_ip_address = MMI_TRUE;
            if(ip_address && search_str1)
            {
                len = mmi_ucs2strlen((S8*)search_str1);
                mmi_chset_ucs2_to_utf8_string((U8*) temp_str2, len + 1, (U8*) search_str1);
                for(add_list_index = 0; add_list_index < len; add_list_index++)
                {
                    if(temp_str2[add_list_index] == '/')
                    {
                        break;
                    }
                    if(!((temp_str2[add_list_index] >= 48 && temp_str2[add_list_index] <= 57) || temp_str2[add_list_index] == '.' || temp_str2[add_list_index] == ':'))
                    {
                        list_ip_address = MMI_FALSE;
                        break;
                    }
                }
            }
            /* Skip the URI scheme and extract & save the URL starting from second part if not an IP address */
            if(!(ip_address && list_ip_address) && search_str1)
            {
                pos = (U8*) mmi_ucs2chr((const S8*)search_str1, (U16) '.');
                if (pos)
                {
                    search_str2 = pos + ENCODING_LENGTH;
                }
                else
                {
                    search_str2 = NULL;
                }
            }
            else
            {
                search_str2 = NULL;
            }
            mmi_chset_utf8_to_ucs2_string((U8*) title_str, (SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH, (U8*) bkm_cntx_ptr[index].title);
            /* Compare the input URL with first and second part URL strings */
            if ((search_str1 && !mmi_ucs2nicmp((S8*) search_str1, (S8*) input_str, mmi_ucs2strlen((S8*) input_str))) ||
                (search_str2 && !mmi_ucs2nicmp((S8*) search_str2, (S8*) input_str, mmi_ucs2strlen((S8*) input_str)))
                ||(!mmi_ucs2nicmp((S8*) title_str, (S8*)input_str, mmi_ucs2strlen((S8*) input_str))))
            {
                /* Save the matched URL indices into matched URL list */
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_bookmark_items_list[matched_item_index++] = index;
                ++num_of_matched_items;
            }
        }
    }

    /* Update the total matched URL number */
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_bookmark_items = num_of_matched_items;

    return num_of_matched_items;
}

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
S32 srv_brw_bookmark_list_get_matched_item_count(void)
{
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p)
    {
        return g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_bookmark_items;
    }
    else
    {
        return 0;
    }
}

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
S8* srv_brw_bookmark_list_get_matched_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((item_index >= 0) && (item_index <= SRV_BRW_BKM_MAX_COUNT));
    MMI_ASSERT(bkm_cntx_ptr);
    return (S8*)(bkm_cntx_ptr[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_bookmark_items_list[item_index]].url);
}

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
S8* srv_brw_bookmark_list_get_matched_item_title(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((item_index >= 0) && (item_index < SRV_BRW_BKM_MAX_COUNT));
    MMI_ASSERT(bkm_cntx_ptr);
    return (S8*)(bkm_cntx_ptr[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_bookmark_items_list[item_index]].title);
}
#endif 

#ifdef __MMI_BRW_BOOKMARK_IN_FMGR__
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
S16 srv_brw_bookmarks_modify_filepath_for_save(U8 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *dest_file_dir;
    U8 dest_file_extn[(SRV_BRW_BKM_MAX_FILE_EXTN_LEN + 1) * ENCODING_LENGTH];
    U8 dest_file_name[(SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN + 1) * ENCODING_LENGTH];
    FS_HANDLE file_handle;
    U8 file_index_ascii[10];
    U8 file_index_ucs2[10 * ENCODING_LENGTH];
    U16 file_index = 0;
    U8 file_sufx_len;
    U8 *temp_file_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(file_path);

    dest_file_dir = (U8*) OslMalloc((SRV_BRW_BKM_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    memset(dest_file_dir, 0, (SRV_BRW_BKM_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

    temp_file_path = (U8*) OslMalloc((SRV_BRW_BKM_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    memset(temp_file_path, 0, (SRV_BRW_BKM_MAX_PATH_LEN + 1) * ENCODING_LENGTH);

    srv_brw_bookmarks_parse_filepath(SRV_BRW_BKM_GET_FOLDER_PATH, file_path, dest_file_dir);    
    srv_brw_bookmarks_parse_filepath(SRV_BRW_BKM_GET_FILE_EXTN, file_path, dest_file_extn);    

    mmi_ucs2cpy((S8*) temp_file_path, (S8*) file_path);

    while (1)
    {
        file_handle = FS_Open((UI_string_type) temp_file_path, FS_READ_ONLY);
        if (file_handle >= 0)
        {
            ++file_index;
            sprintf((S8*) file_index_ascii, "(%d)", file_index);
            file_sufx_len = strlen((S8*) file_index_ascii);
            srv_brw_bookmarks_parse_filepath(SRV_BRW_BKM_GET_FILENAME_WITHOUT_EXTN, file_path, dest_file_name);    
            if (mmi_ucs2strlen((S8*) dest_file_name) > (SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN - file_sufx_len))
            {
                dest_file_name[(SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN - file_sufx_len) * ENCODING_LENGTH] = '\0';
                dest_file_name[(SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN - file_sufx_len) * ENCODING_LENGTH + 1] = '\0';
            }
            mmi_asc_to_ucs2((S8*) file_index_ucs2, (S8*) file_index_ascii);
            mmi_ucs2cat((S8*) dest_file_name, (S8*) file_index_ucs2);

            srv_brw_bookmarks_create_full_file_path((S8*) dest_file_dir,
                                                    (S8*) dest_file_name,
                                                    (S8*) dest_file_extn,
                                                    (S8*) temp_file_path);
            FS_Close(file_handle);
            continue;
        }
        else
        {
            mmi_ucs2cpy((S8*) file_path, (S8*) temp_file_path);
            OslMfree(dest_file_dir);
            OslMfree(temp_file_path);
            return;
        }
    }
}
#endif

/************************************************vBookmark Service*********************************/
/*--------------------------------------------------BEGIN vBookmark writer ---------------------------------------------------*/
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
S32 srv_vbkm_writer_convert_file_to_standard_format(FS_HANDLE fh, U8* title, U8* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 fieldBuff[VBKM_WRITER_FIELD_BUFFER];
	U8 printable_str[VBKM_WRITER_FIELD_BUFFER];
	U8 url_ascii[VBKM_MAX_URL_LENGTH+1];
	U32 nBytes;
	S32 result = FS_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(fieldBuff, 0, VBKM_WRITER_FIELD_BUFFER);

    /* Header */
    sprintf(
        fieldBuff,
        "%s:%s%s",
        g_vbkm_field[VBKM_FIELD_BEGIN],
		g_vbkm_sub_field[VBKM_SUB_FIELD_VBKM],
		VBKM_LINE_BREAK);

    /* Version */
    sprintf(
        fieldBuff + strlen((S8*)fieldBuff),
        "%s:%s%s",
        g_vbkm_field[VBKM_FIELD_VERSION],
		VBKM_VERSION,
		VBKM_LINE_BREAK);

    /* TITLE */
    //mmi_ucs2_to_asc((S8*)title_ascii, (S8*)title);
	srv_vbkm_util_convert_str_to_printable_form((S8*)printable_str, (S8*)title);

    sprintf(
        fieldBuff + strlen((S8*)fieldBuff),
        "%s;%s=%s;%s=%s:%s%s",
        g_vbkm_field[VBKM_FIELD_TITLE],
        g_vbkm_sub_field[VBKM_SUB_FIELD_CHARSET],
        VBKM_CHAR_SET,
		g_vbkm_sub_field[VBKM_SUB_FIELD_ENCODING],
        VBKM_ENCODING,
		printable_str,
		VBKM_LINE_BREAK);
	
	if((result = FS_Write(fh, fieldBuff, strlen((S8*)fieldBuff), (U32*)&nBytes)) != FS_NO_ERROR)
	{
		return result;
	}

    /* URL */
    mmi_ucs2_to_asc((CHAR*)url_ascii, (CHAR*)url);
    sprintf(
        fieldBuff,
        "%s;%s=%s;%s=%s:%s%s",
        g_vbkm_field[VBKM_FIELD_URL],
        g_vbkm_sub_field[VBKM_SUB_FIELD_CHARSET],
        VBKM_CHAR_SET,
		g_vbkm_sub_field[VBKM_SUB_FIELD_ENCODING],
        VBKM_ENCODING,
		url_ascii,
		VBKM_LINE_BREAK);

	if((result = FS_Write(fh, fieldBuff, strlen((S8*)fieldBuff), (U32*)&nBytes)) != FS_NO_ERROR)
	{
		return result;
	}

    /* BEGIN ENV */
    sprintf(
        fieldBuff,
        "%s:%s%s",
        g_vbkm_field[VBKM_FIELD_BEGIN],
		g_vbkm_sub_field[VBKM_SUB_FIELD_ENV],
		VBKM_LINE_BREAK);

    /* X-IRMC-URL */
    sprintf(
        fieldBuff + strlen((S8*)fieldBuff),
        "%s;%s=%s;%s=%s:=%s",
        g_vbkm_field[VBKM_FIELD_XIRMC],
        g_vbkm_sub_field[VBKM_SUB_FIELD_CHARSET],
        VBKM_CHAR_SET,
		g_vbkm_sub_field[VBKM_SUB_FIELD_ENCODING],
        VBKM_ENCODING,
		VBKM_LINE_BREAK);

    /* Internet Shortcut */
    sprintf(
        fieldBuff + strlen((S8*)fieldBuff),
        "%s=%s",
        g_vbkm_field[VBKM_FIELD_IS],
		VBKM_LINE_BREAK);

	if((result = FS_Write(fh, fieldBuff, strlen((S8*)fieldBuff), (U32*)&nBytes)) != FS_NO_ERROR)
	{
		return result;
	}

    /* URL */
    mmi_ucs2_to_asc((CHAR*)url_ascii, (CHAR*)url);
    sprintf(
        fieldBuff,
        "%s=%s%s",
        g_vbkm_field[VBKM_FIELD_URL],
		url_ascii,
		VBKM_LINE_BREAK);

	if((result = FS_Write(fh, fieldBuff, strlen((S8*)fieldBuff), (U32*)&nBytes)) != FS_NO_ERROR)
	{
		return result;
	}

    /* END ENV */
    sprintf(
        fieldBuff,
        "%s:%s%s",
        g_vbkm_field[VBKM_FIELD_END],
		g_vbkm_sub_field[VBKM_SUB_FIELD_ENV],
		VBKM_LINE_BREAK);

    /* Footer */
    sprintf(
        fieldBuff + strlen((S8*)fieldBuff),
        "%s:%s%s",
        g_vbkm_field[VBKM_FIELD_END],
		g_vbkm_sub_field[VBKM_SUB_FIELD_VBKM],
		VBKM_LINE_BREAK);

	if((result = FS_Write(fh, fieldBuff, strlen((S8*)fieldBuff), (U32*)&nBytes)) != FS_NO_ERROR)
	{
		return result;
	}

	FS_Truncate(fh);//its truncates the file after the current pointer
	return result;
}
/*--------------------------------------------------END vBookmark writer ---------------------------------------------------*/


/*--------------------------------------------------BEGIN vbookmark reader ---------------------------------------------------*/
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
MMI_BOOL srv_vbkm_reader_validate_file(FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S8 inBuff[VOBJ_READ_BUFF_LEN];
    //U8 token;
	//MMI_BOOL URL_flag = MMI_FALSE;
	//S32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_vbkm_reader_check_file_syntax(fh) == VBKM_PARSE_NO_ERROR)
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
 *  srv_vbkm_reader_is_vbookmark_file
 * DESCRIPTION
 *  checks whether the received file is a vbookmark file or not
 * PARAMETERS
 *  file_path	[IN]	path of the file
 * RETURNS
 *  MMI_TRUE  : for a vbookmark file
 *  MMI_FALSE : for non-vbookmark files
 *****************************************************************************/
MMI_BOOL srv_vbkm_reader_is_vbookmark_file(S8* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	FS_HANDLE fh;
	MMI_BOOL ret_val;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	fh = FS_Open((UI_string_type)file_path, FS_READ_ONLY);
	MMI_ASSERT(fh >= 0);

	ret_val = srv_vbkm_reader_validate_file(fh);
	FS_Close(fh);

	return ret_val;
}


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
U8 srv_vbkm_reader_check_file_syntax(FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 inBuff[VOBJ_READ_BUFF_LEN];
	MMI_BOOL URL_flag = MMI_FALSE;
	U8 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	FS_Seek(fh, 0, SEEK_SET); /*set file pointer to its beginning*/

	/* read BEGIN tag */
	if(srv_vbkm_reader_get_single_line(inBuff, fh))
	{
        if (srv_vbkm_reader_get_field(inBuff) == VBKM_FIELD_BEGIN)
        {
			if(srv_vbkm_reader_check_header(inBuff) != VBKM_SUB_FIELD_VBKM)
			{
	            return VBKM_BEGIN_ERROR;
			}
        }
        else
        {
            return VBKM_BEGIN_ERROR;
        }
	}
	else
	{
		return VBKM_PARSE_UNKNOWN_ERROR;
	}

	while(srv_vbkm_reader_get_line(inBuff, fh))
	{
		switch(srv_vbkm_reader_get_field(inBuff))
		{
			case VBKM_FIELD_URL:
			{
				if(!URL_flag)
				{
					if(!srv_vbkm_reader_check_URL(inBuff))
					{
						return VBKM_URL_ERROR;
					}
					URL_flag = MMI_TRUE;
				}
				break;
			}
			case VBKM_FIELD_END:
			{
				result = srv_vbkm_reader_check_header(inBuff);
				if((result == VBKM_SUB_FIELD_VBKM) && URL_flag)
				{
					return VBKM_PARSE_NO_ERROR;
				}
				else if(result == VBKM_SUB_FIELD_ENV)
				{
					break;
				}
				else if(!URL_flag)
				{
					return VBKM_URL_ERROR;
				}
				else
				{
					return VBKM_END_ERROR;
				}
			}
			default:
				break;
		}
	}

	if(URL_flag)
	{
		return VBKM_END_ERROR;
	}
	else
	{
		return VBKM_URL_ERROR;
	}
}


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
void srv_vbkm_reader_extract_url(FS_HANDLE fh, U8* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 inBuff[VOBJ_READ_BUFF_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)url, (S8*)L"");

	FS_Seek(fh, 0, SEEK_SET); /*set file pointer to its beginning*/

	while(srv_vbkm_reader_get_line(inBuff, fh))
	{
		switch(srv_vbkm_reader_get_field(inBuff))
		{
			case VBKM_FIELD_URL:
			{
				srv_vbkm_reader_get_URL_string(inBuff, url);
				return;
			}
			default:
				break;
		}
	}
}


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
    void srv_vbkm_reader_extract_title(FS_HANDLE fh, U8* title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 inBuff[VOBJ_READ_BUFF_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)title, (S8*)L"");

	FS_Seek(fh, 0, SEEK_SET); /*set file pointer to its beginning*/

	while(srv_vbkm_reader_get_line(inBuff, fh))
	{
		switch(srv_vbkm_reader_get_field(inBuff))
		{
			case VBKM_FIELD_TITLE:
			{
				srv_vbkm_reader_get_title_string(inBuff, title);
				return;
			}
			default:
				break;
		}
	}
}


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
MMI_BOOL srv_vbkm_reader_get_single_line(S8 *strOutput, FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nBytes = 0;
    S8 strLF[2];
    S8 *currCursor;
    S32 strLen = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(strLF, "%c", VOBJ_LF_CHAR);
    FS_Read(fh, strOutput, VOBJ_READ_BUFF_LEN - 1, &nBytes);

    strOutput[nBytes] = VOBJ_NULL;

    if (!nBytes)
    {
        return MMI_FALSE;
    }

    if ((currCursor = strstr(strOutput, strLF)) != NULL)  /* find out first LF */
    {
        strLen = (S32) (currCursor - strOutput);
        if (strOutput[strLen - 1] == VOBJ_CR_CHAR)
        {
            strOutput[strLen - 1] = VOBJ_NULL;
        }
        else
        {
            strOutput[strLen] = VOBJ_NULL;
        }

		FS_Seek(fh, (S32) (strLen - nBytes + 1), SEEK_CUR);
		nBytes = strLen;
    }
    else    /* LF not found, read until LF */
    {
        strOutput[nBytes] = VOBJ_NULL;
    }

    return ((MMI_BOOL)nBytes);
}



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
S32 srv_vbkm_reader_get_line(S8 *strOutput, FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nBytes = 0;
    S8 *buffer = OslMalloc(VOBJ_READ_BUFF_LEN);
    S32 i;
    S32 strLen;
    S8 *curr_cursor;
    S8 *cursor = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Read(fh, buffer, VOBJ_READ_BUFF_LEN - 1, &nBytes);
    buffer[nBytes] = '\0';

    if (!nBytes)
    {
        OslMfree(buffer);
        return 0;
    }

    /*only the BEGIN, END and VERSION are sure to be single line*/
    if( !strncmp(g_vbkm_field[VBKM_FIELD_END], buffer, strlen(g_vbkm_field[VBKM_FIELD_BEGIN])) ||
		!strncmp(g_vbkm_field[VBKM_FIELD_END], buffer, strlen(g_vbkm_field[VBKM_FIELD_END])) ||
        !strncmp(g_vbkm_field[VBKM_FIELD_VERSION], buffer, strlen(g_vbkm_field[VBKM_FIELD_VERSION]))
		)
    {
        FS_Seek(fh, 0 - nBytes, SEEK_CUR);
        OslMfree(buffer);
        return srv_vbkm_reader_get_single_line(strOutput, fh);
    }

    /* find next filed */
    for (i = VBKM_FIELD_BEGIN; i < VBKM_FIELD_TOTAL; i++)
    {
        curr_cursor = strstr(buffer + 1, g_vbkm_field[i]);

        if (curr_cursor == (S8*) NULL)
        {
            continue;
        }
        else if (cursor == (S8*) NULL && (*(curr_cursor - 1) == 0x0A))
        {
            cursor = curr_cursor;
        }
        else if (((S32) cursor > (S32) curr_cursor) && (*(curr_cursor - 1) == 0x0A))
        {
            cursor = curr_cursor;
        }
    }
    if (cursor == NULL)
    {
        OslMfree(buffer);
        return 0;
    }

    strLen = (S32) cursor - (S32) buffer;
    strncpy(strOutput, buffer, strLen);
    strOutput[strLen] = VOBJ_NULL;

    /* Remove end of line "\r\n" */
    if (strncmp((S8*) ((strOutput + strLen) - strlen(VOBJ_LF_STR)), (S8*) VOBJ_LF_STR, strlen(VOBJ_LF_STR)) ==
        0)
    {
        if (strOutput[strLen - strlen(VOBJ_LF_STR) - 1] == VOBJ_CR_CHAR)
        {
            strOutput[strLen - strlen(VOBJ_LF_STR) - 1] = VOBJ_NULL;
        }
        else
        {
            strOutput[strLen - strlen(VOBJ_LF_STR)] = VOBJ_NULL;
        }
    }

    FS_Seek(fh, (S32) (strLen - nBytes), SEEK_CUR);

    OslMfree(buffer);
    return strLen;
}


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
U8 srv_vbkm_reader_get_field(S8 *String)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < VBKM_FIELD_TOTAL; i++)
    {
        if (srv_vbkm_util_cmp_filed(String, g_vbkm_field[i]))
        {
            break;
        }
    }

    return i;
}


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
U8 srv_vbkm_reader_check_header(S8 *String)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *cursor;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cursor = (S8*)strstr(String, (S8*) VBKM_COLON_SEP);
    if (!cursor || !srv_vbkm_util_strnicmp((cursor + 1), 
		(S8*)g_vbkm_sub_field[VBKM_SUB_FIELD_VBKM], strlen(g_vbkm_sub_field[VBKM_SUB_FIELD_VBKM])))
    {
        return VBKM_SUB_FIELD_VBKM;
    }
    else if (!cursor || !srv_vbkm_util_strnicmp((cursor + 1), 
		(S8*)g_vbkm_sub_field[VBKM_SUB_FIELD_ENV], strlen(g_vbkm_sub_field[VBKM_SUB_FIELD_ENV])))
    {
        return VBKM_SUB_FIELD_ENV;    
    }
	else
	{
        return VBKM_SUB_FIELD_TOTAL;    
	}
}


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
MMI_BOOL srv_vbkm_reader_check_URL(S8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *cursor;
	U32 len;
	U8* url_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	len = strlen((S8*)g_vbkm_field[VBKM_FIELD_URL]);
	if(!srv_vbkm_util_strnicmp((S8*)string+len, VBKM_COLON_SEP, strlen((S8*)VBKM_COLON_SEP)))
	{
		url_ptr = (U8*) (string + len + strlen((S8*)VBKM_COLON_SEP));
		len = strlen((S8*)url_ptr);
		if(len)
		{
			return MMI_TRUE;
		}
	}
	else if(!srv_vbkm_util_strnicmp((S8*)string+len, VBKM_EQUALITY_SEP, strlen((S8*)VBKM_EQUALITY_SEP)))
	{
		url_ptr = (U8*)(string + len + strlen((S8*)VBKM_EQUALITY_SEP));
		len = strlen((S8*)url_ptr);
		if(len)
		{
			return MMI_TRUE;
		}
	}
	else if(!srv_vbkm_util_strnicmp((S8*)string+len, VBKM_SEMI_COLON_SEP, strlen((S8*)VBKM_SEMI_COLON_SEP)))
	{
		cursor = strstr((S8*)string+len, VBKM_COLON_SEP);
		if(cursor)
		{
			url_ptr = (U8*)cursor + 1;
			len = strlen((S8*)url_ptr);
			if(len)
			{
				return MMI_TRUE;
			}
		}
	}
	return MMI_FALSE;
}


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
void srv_vbkm_reader_get_URL_string(S8 *inBuff, U8* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *cursor;
	U32 len;
	U8* url_ptr;
	U8 temp_str[VBKM_MAX_URL_LENGTH+1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	len = strlen((S8*)g_vbkm_field[VBKM_FIELD_URL]);
	if(!srv_vbkm_util_strnicmp((S8*)inBuff+len, VBKM_COLON_SEP, strlen((S8*)VBKM_COLON_SEP)))
	{
		url_ptr = (U8*)(inBuff + len + strlen((S8*)VBKM_COLON_SEP));
		strncpy((S8*)temp_str, (S8*)url_ptr, VBKM_MAX_URL_LENGTH);
		if(strlen((S8*)url_ptr) >= VBKM_MAX_URL_LENGTH)
		{
			temp_str[VBKM_MAX_URL_LENGTH] = '\0';
		}
		mmi_asc_to_ucs2((S8*)url, (S8*)temp_str);
	}
	else if(!srv_vbkm_util_strnicmp((S8*)inBuff+len, VBKM_EQUALITY_SEP, strlen((S8*)VBKM_EQUALITY_SEP)))
	{
		url_ptr = (U8*)(inBuff + len + strlen((S8*)VBKM_EQUALITY_SEP));
		strncpy((S8*)temp_str, (S8*)url_ptr, VBKM_MAX_URL_LENGTH);
		if(strlen((S8*)url_ptr) >= VBKM_MAX_URL_LENGTH)
		{
			temp_str[VBKM_MAX_URL_LENGTH] = '\0';
		}
		mmi_asc_to_ucs2((S8*)url, (S8*)temp_str);
	}
	else if(!srv_vbkm_util_strnicmp((S8*)inBuff+len, VBKM_SEMI_COLON_SEP, strlen((S8*)VBKM_SEMI_COLON_SEP)))
	{
		cursor = strstr((S8*)inBuff+len, VBKM_COLON_SEP);
		if(cursor)
		{
			url_ptr = (U8*)(cursor + 1);
			strncpy((S8*)temp_str, (S8*)url_ptr, VBKM_MAX_URL_LENGTH);
			if(strlen((S8*)url_ptr) >= VBKM_MAX_URL_LENGTH)
			{
				temp_str[VBKM_MAX_URL_LENGTH] = '\0';
			}
			mmi_asc_to_ucs2((S8*)url, (S8*)temp_str);
		}
	}
}


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
void srv_vbkm_reader_get_title_string(S8 *inBuff, U8* title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *cursor;
	U32 len;
	U8* title_ptr;
	U8 temp_str[VBKM_READER_FIELD_BUFFER];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	len = strlen((S8*)g_vbkm_field[VBKM_FIELD_TITLE]);

	if(!srv_vbkm_util_strnicmp((S8*)inBuff+len, VBKM_COLON_SEP, strlen((S8*)VBKM_COLON_SEP)))
	{
		title_ptr = (U8*)(inBuff + len + strlen((S8*)VBKM_COLON_SEP));
	}
	else if(!srv_vbkm_util_strnicmp((S8*)inBuff+len, VBKM_EQUALITY_SEP, strlen((S8*)VBKM_EQUALITY_SEP)))
	{
		title_ptr = (U8*)(inBuff + len + strlen((S8*)VBKM_EQUALITY_SEP));
	}
	else if(!srv_vbkm_util_strnicmp((S8*)inBuff+len, VBKM_SEMI_COLON_SEP, strlen((S8*)VBKM_SEMI_COLON_SEP)))
	{
		cursor = strstr((S8*)inBuff+len, VBKM_COLON_SEP);
		if(cursor)
		{
			title_ptr = (U8*)(cursor + 1);
		}
		else
		{
			title_ptr = NULL;
		}
	}
	else
	{
        title_ptr = NULL;
	}

	if(title_ptr)
	{
		applib_qprint_decode((S8*)title_ptr, strlen((S8*)title_ptr), (S8*)temp_str, VBKM_READER_FIELD_BUFFER);
		srv_vbkm_util_convert_to_ucs2((S8*)title, (U8)((VBKM_MAX_FILENAME_LENGTH+1) * ENCODING_LENGTH), (S8*)temp_str, VOBJ_CH_UTF8);

		if(mmi_ucs2strlen((S8*)title) >= VBKM_MAX_FILENAME_LENGTH)
		{
			title[VBKM_MAX_FILENAME_LENGTH * ENCODING_LENGTH] = '\0';
			title[VBKM_MAX_FILENAME_LENGTH * ENCODING_LENGTH + 1] = '\0';
		}
	}
}
/*--------------------------------------------------END vbookmark reader ---------------------------------------------------*/

/***************************************************vBookmark Utilities*********************************************************/
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
U8 srv_vbkm_util_convert_to_system_encoding(S8 *dst, S8 *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)src, (char*)dst, VBKM_WRITER_FIELD_BUFFER);

    return VOBJ_CH_UTF8;
}


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
void srv_vbkm_util_convert_to_ucs2(S8 *dst, U8 dst_size, S8 *src, U8 encode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (encode == VOBJ_CH_UTF8)
    {
        mmi_chset_convert(MMI_CHSET_UTF8, MMI_CHSET_UCS2, (char*)src, (char*)dst, dst_size);
    }
    else
    {
        mmi_chset_convert(g_chset_text_encoding, MMI_CHSET_UCS2, (char*)src, (char*)dst, dst_size);
    }
}


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
void srv_vbkm_util_get_filename_and_extn(U8* file_path, U8* filename, U8* file_extn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	UI_string_type start_loc;
	UI_string_type end_loc;
	S32 len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_ucs2cpy((S8*)filename, (S8*)L"");	
	mmi_ucs2cpy((S8*)file_extn, (S8*)L"");

	start_loc = (UI_string_type)mmi_ucs2rchr((const S8*)file_path, (U16)'\\');
	if(start_loc)
	{
		end_loc = (UI_string_type)mmi_ucs2rchr((const S8*)start_loc, (U16)'.');
		if(end_loc)
		{
			len = end_loc - start_loc - 1;
			mmi_ucs2ncpy((S8*)filename, (S8*)start_loc+ENCODING_LENGTH, len);
			mmi_ucs2cpy((S8*)file_extn, (S8*)end_loc+ENCODING_LENGTH);
		}
		else
		{
			mmi_ucs2cpy((S8*)filename, (S8*)start_loc+ENCODING_LENGTH);
		}
	}
}


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
void srv_vbkm_util_convert_str_to_printable_form(S8* printable_str, S8* actual_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 temp_buf[VBKM_WRITER_FIELD_BUFFER];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_vbkm_util_convert_to_system_encoding((S8*)temp_buf, (S8*)actual_str);
    applib_qprint_encode_ext((S8*)temp_buf, strlen(temp_buf), (S8*)printable_str, VBKM_WRITER_FIELD_BUFFER, KAL_TRUE);
}


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
S8 srv_vbkm_util_strnicmp(S8 *src, S8 *dest, S32 maxlen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ch1, ch2;
    S8 *s1, *s2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s1 = src;
    s2 = dest;

    while (maxlen-- > 0)
    {
        ch1 = tolower(*s1++);
        ch2 = tolower(*s2++);
        if (ch1 != ch2)
        {
            return TRUE;
        }
    }

    return FALSE;
}

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
U8 srv_vbkm_util_cmp_filed(S8 *srcString, const S8 *refString)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 refLen, srcLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srcLen = strlen(srcString);
    refLen = strlen(refString);

    if (srcLen < refLen)
    {
        return FALSE;
    }
    if (srv_vbkm_util_strnicmp(srcString, (S8*) refString, refLen))
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}
/***************************************************vBookmark Utilities*********************************************************/
/***************************************************vBookmark Service*********************************************************/


/*************************************************New Bookmark Design*******************************************************/

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
S32 srv_brw_bkm_initialize_bookmark_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nBytes = 0;
    FS_HANDLE file_handle = 0;
    WCHAR *root_file_path;
    U8* buffer;
    U8* buffer_ptr;
    U8 temp[SRV_BRW_BKM_TIMESTAMP_SIZE + 1] = {0};
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr;
    U8 bkm_cntx_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_brw_cntx.bkm_cntx_p)
    {
        return FS_NO_ERROR;
    }
    g_srv_brw_cntx.bookmark_count = 0;
    root_file_path = (WCHAR*)srv_brw_malloc((mmi_ucs2strlen((S8*) g_srv_brw_cntx.default_folder_path) + mmi_ucs2strlen((S8*)SRV_BRW_BKM_ROOT_FILE_NAME) + 2) * ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) root_file_path, (S8*) g_srv_brw_cntx.default_folder_path);
    mmi_ucs2cat((S8*) root_file_path, (S8*) L"\\");
    mmi_ucs2cat((S8*) root_file_path, (S8*) SRV_BRW_BKM_ROOT_FILE_NAME);

    file_handle = FS_Open((const WCHAR*) root_file_path, FS_READ_WRITE | FS_CREATE);
    if(file_handle < 0)
    {
        srv_brw_free(root_file_path);
        return file_handle;
    }
    g_srv_brw_cntx.bkm_cntx_p = (srv_brw_bkm_bookmark_context_struct*)srv_brw_malloc(sizeof(srv_brw_bkm_bookmark_context_struct) * SRV_BRW_BKM_MAX_COUNT);
    memset(g_srv_brw_cntx.bkm_cntx_p, 0, sizeof(srv_brw_bkm_bookmark_context_struct) * SRV_BRW_BKM_MAX_COUNT);

    buffer = (U8*)srv_brw_malloc(SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE);
    memset(buffer, 0, SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE);
    FS_Seek(file_handle, 0, SEEK_SET);
    bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    while(FS_Read(file_handle, buffer, SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE, &nBytes) == FS_NO_ERROR && nBytes != 0)
    {
        buffer_ptr = buffer;
        memset(temp, 0, SRV_BRW_BKM_TIMESTAMP_SIZE + 1);
        strncpy((S8*)temp, (S8*)buffer_ptr, SRV_BRW_BKM_TYPE_SIZE);
        bkm_cntx_ptr[bkm_cntx_index].type = (srv_brw_bkm_types_enum)atoi((const S8*)temp);
        if(bkm_cntx_ptr[bkm_cntx_index].type != SRV_BRW_BKM_TYPE_EMPTY)
        {
            S8* token_location;
            g_srv_brw_cntx.bookmark_count++;
            buffer_ptr = buffer_ptr + SRV_BRW_BKM_TYPE_SIZE + SRV_BRW_BKM_LINE_BREAK_SIZE;
            strncpy((S8*)temp, (S8*)buffer_ptr, SRV_BRW_BKM_TIMESTAMP_SIZE);
            bkm_cntx_ptr[bkm_cntx_index].timestamp = atoi((const S8*)temp);
            buffer_ptr = buffer_ptr + SRV_BRW_BKM_TIMESTAMP_SIZE + SRV_BRW_BKM_LINE_BREAK_SIZE;

            bkm_cntx_ptr[bkm_cntx_index].title = (U8*)srv_brw_malloc(SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1);
            memset(bkm_cntx_ptr[bkm_cntx_index].title, 0, SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1);
            strncpy((S8*)bkm_cntx_ptr[bkm_cntx_index].title, (S8*)buffer_ptr, SRV_BRW_BKM_MAX_FILE_NAME_LEN);
            token_location = strchr((S8*)bkm_cntx_ptr[bkm_cntx_index].title, SRV_BRW_BKM_TITLE_PADDING_TOKEN);
            if(token_location)
            {
                *token_location = '\0';
            }
            buffer_ptr = buffer_ptr + SRV_BRW_BKM_MAX_FILE_NAME_LEN + SRV_BRW_BKM_LINE_BREAK_SIZE;

        #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
            if(bkm_cntx_ptr[bkm_cntx_index].type != SRV_BRW_BKM_TYPE_FOLDER)
        #endif
            {
                bkm_cntx_ptr[bkm_cntx_index].url = (U8*)srv_brw_malloc(SRV_BRW_MAX_URL_LEN + 1);
                memset(bkm_cntx_ptr[bkm_cntx_index].url, 0, SRV_BRW_MAX_URL_LEN + 1);
                strncpy((S8*)bkm_cntx_ptr[bkm_cntx_index].url, (S8*)buffer_ptr, SRV_BRW_MAX_URL_LEN);
                token_location = strchr((S8*)bkm_cntx_ptr[bkm_cntx_index].url, SRV_BRW_BKM_URL_PADDING_TOKEN);
                if(token_location)
                {
                    *token_location = '\0';
                }
            }
            buffer_ptr = buffer_ptr + SRV_BRW_MAX_URL_LEN + SRV_BRW_BKM_LINE_BREAK_SIZE;
        #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
            memset(temp, 0, SRV_BRW_BKM_TIMESTAMP_SIZE + 1);
            strncpy((S8*)temp, (S8*)buffer_ptr, SRV_BRW_BKM_PARENT_INDEX_SIZE);
            bkm_cntx_ptr[bkm_cntx_index].parent_index = atoi((const S8*)temp);
        #endif
        }
        bkm_cntx_index++;
    }
    srv_brw_free(buffer);
    FS_Close(file_handle);
    return FS_NO_ERROR;
}

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
MMI_BOOL srv_brw_bkm_deinitialize_bookmark_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_brw_cntx.bkm_cntx_p)
    {
        for(index = 0; index < SRV_BRW_BKM_MAX_COUNT; index++)
        {
            if(g_srv_brw_cntx.bkm_cntx_p[index].type != SRV_BRW_BKM_TYPE_EMPTY)
            {
                srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.bkm_cntx_p[index].title));
                srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.bkm_cntx_p[index].url));
            }
        }
     }
    srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.bkm_cntx_p));
    g_srv_brw_cntx.bookmark_count = 0;
    return MMI_TRUE;
}

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
void srv_brw_bookmark_sort_bookmark_list(srv_brw_bkm_bookmark_list_struct* bkm_list, U8 start_index, U8 end_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 selected_index = 0;
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr;
    U8 outer_index , inner_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(bkm_list);
    if(start_index >= end_index)
    {
        return;
    }
    bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    for(outer_index = start_index; outer_index < end_index; outer_index++)
    {
        selected_index = outer_index;
        for(inner_index = outer_index + 1; inner_index <= end_index; inner_index++)
        {
            if(bkm_cntx_ptr[bkm_list[inner_index].actual_index].timestamp < bkm_cntx_ptr[bkm_list[selected_index].actual_index].timestamp)
            {
                selected_index = inner_index;
            }
        }
        if(selected_index != outer_index)
        {
            U8 temp = bkm_list[selected_index].actual_index;
            bkm_list[selected_index].actual_index = bkm_list[outer_index].actual_index;
            bkm_list[outer_index].actual_index = temp;
        }
    }
}

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
void srv_brw_bkm_arrange_bookmark_list_in_order(srv_brw_bkm_bookmark_list_struct* bkm_list, U8 item_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 start_index, end_index;
    srv_brw_bkm_types_enum current_type = (srv_brw_bkm_types_enum)(SRV_BRW_BKM_TYPE_EMPTY + 1);
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr;
    U8 ordered_list_start_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(bkm_list);
    MMI_ASSERT(item_count != 0);
    bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    if(item_count == 1)
    {
        return;
    }
    start_index = 0;
    while(current_type < SRV_BRW_BKM_TYPE_USER_CREATED_FILE)
    {
        ordered_list_start_index = start_index;
        end_index = item_count - 1;
        while(1)
        {
            while((start_index <= end_index) && (bkm_cntx_ptr[bkm_list[start_index].actual_index].type == current_type))
            {
                start_index++;
            }
            while((end_index > start_index) && (bkm_cntx_ptr[bkm_list[end_index].actual_index].type != current_type))
            {
                end_index--;
            }
            if(start_index < end_index)
            {
                U8 temp = bkm_list[start_index].actual_index;
                bkm_list[start_index].actual_index = bkm_list[end_index].actual_index;
                bkm_list[end_index].actual_index = temp;
            }
            else
            {
                break;
            }
        }
        current_type++;
        if(start_index > ordered_list_start_index)
        {
            srv_brw_bookmark_sort_bookmark_list(bkm_list, ordered_list_start_index, start_index - 1);
        }
    }
    if(start_index < (item_count - 1))
    {
        srv_brw_bookmark_sort_bookmark_list(bkm_list, start_index, item_count - 1);
    }
}

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
S32 srv_brw_bkm_update_bookmark_entry_to_file(U8 selected_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_p = g_srv_brw_cntx.bkm_cntx_p;
    U8* buffer;
    WCHAR *root_file_path;
    srv_brw_bkm_bookmark_struct *bkm_data;
    U16 title_len, url_len;
    S32 nBytes = 0;
    FS_HANDLE file_handle;
    S32 error_code = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(bkm_cntx_p);
    root_file_path = (WCHAR*)srv_brw_malloc((mmi_ucs2strlen((S8*) g_srv_brw_cntx.default_folder_path) + mmi_ucs2strlen((S8*)SRV_BRW_BKM_ROOT_FILE_NAME) + 2) * ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) root_file_path, (S8*) g_srv_brw_cntx.default_folder_path);
    mmi_ucs2cat((S8*) root_file_path, (S8*) L"\\");
    mmi_ucs2cat((S8*) root_file_path, (S8*) SRV_BRW_BKM_ROOT_FILE_NAME);

    file_handle = FS_Open((const WCHAR*) root_file_path, FS_READ_WRITE | FS_CREATE);
    if(file_handle < 0)
    {
        srv_brw_free(root_file_path);
        return file_handle;
    }
    FS_Seek(file_handle, SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE * selected_index, SEEK_SET);

    bkm_data = (srv_brw_bkm_bookmark_struct*) srv_brw_malloc(sizeof(srv_brw_bkm_bookmark_struct));
    memset(bkm_data, 0, sizeof(srv_brw_bkm_bookmark_struct));

    strncpy((S8*) bkm_data->title, (S8*)bkm_cntx_p[selected_index].title , SRV_BRW_BKM_MAX_FILE_NAME_LEN);
    title_len = strlen((S8*)bkm_data->title);
    if(bkm_cntx_p[selected_index].url)
    {
        strncpy((S8*) bkm_data->url, (S8*)bkm_cntx_p[selected_index].url , SRV_BRW_MAX_URL_LEN);
        url_len = strlen((S8*)bkm_data->url);
    }
    else
    {
        url_len = 0;
    }
    memset((S8*)bkm_data->url + url_len, SRV_BRW_BKM_URL_PADDING_TOKEN, SRV_BRW_MAX_URL_LEN - url_len);
    memset((S8*)bkm_data->title + title_len, SRV_BRW_BKM_TITLE_PADDING_TOKEN, SRV_BRW_BKM_MAX_FILE_NAME_LEN - title_len);
    buffer = (U8*)srv_brw_malloc(SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE + 1);
    memset(buffer, 0, SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE + 1);

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    sprintf((S8*)buffer, "%2d%s%10d%s%s%s%s%s%3d%s", 
        bkm_cntx_p[selected_index].type,
        SRV_BRW_BKM_LINE_BREAK,
        bkm_cntx_p[selected_index].timestamp,
        SRV_BRW_BKM_LINE_BREAK,
        bkm_data->title,
        SRV_BRW_BKM_LINE_BREAK,
        bkm_data->url,
        SRV_BRW_BKM_LINE_BREAK,
        bkm_cntx_p[selected_index].parent_index,
        SRV_BRW_BKM_LINE_BREAK);
#else
    sprintf((S8*)buffer, "%2d%s%10d%s%s%s%s%s",
        bkm_cntx_p[selected_index].type,
        SRV_BRW_BKM_LINE_BREAK,
        bkm_cntx_p[selected_index].timestamp,
        SRV_BRW_BKM_LINE_BREAK,
        bkm_data->title,
        SRV_BRW_BKM_LINE_BREAK,
        bkm_data->url,
        SRV_BRW_BKM_LINE_BREAK);
#endif
    error_code = (S32)FS_Write(file_handle, buffer, strlen((S8*)buffer), (U32*)&nBytes);
    srv_brw_free(buffer);
    srv_brw_free(bkm_data);
    FS_Close(file_handle);
    return error_code;
}

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
S32 srv_brw_bkm_remove_item(U8 selected_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 buffer[10] = {0};
    WCHAR *root_file_path;
    S32 nBytes = 0;
    FS_HANDLE file_handle;
    S32 error_code = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    root_file_path = (WCHAR*)srv_brw_malloc((mmi_ucs2strlen((S8*) g_srv_brw_cntx.default_folder_path) + mmi_ucs2strlen((S8*)SRV_BRW_BKM_ROOT_FILE_NAME) + 2) * ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) root_file_path, (S8*) g_srv_brw_cntx.default_folder_path);
    mmi_ucs2cat((S8*) root_file_path, (S8*) L"\\");
    mmi_ucs2cat((S8*) root_file_path, (S8*) SRV_BRW_BKM_ROOT_FILE_NAME);

    file_handle = FS_Open((const WCHAR*) root_file_path, FS_READ_WRITE | FS_CREATE);
    if(file_handle < 0)
    {
        srv_brw_free(root_file_path);
        return file_handle;
    }
    FS_Seek(file_handle, SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE * selected_index, SEEK_SET);
    sprintf((S8*)buffer, "%2d",SRV_BRW_BKM_TYPE_EMPTY); 
    error_code = (S32)FS_Write(file_handle, buffer, strlen((S8*)buffer), (U32*)&nBytes);
    FS_Close(file_handle);
    return error_code;
}

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
MMI_BOOL srv_brw_bkm_free_item_memory(srv_brw_bkm_bookmark_context_struct *bkm_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(bkm_item)
    {
        srv_brw_free_browser_memory((void**)&(bkm_item->title));
        srv_brw_free_browser_memory((void**)&(bkm_item->url));
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

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
S32 srv_brw_bkm_delete_bookmark(U8 selected_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 error_code = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(selected_index < SRV_BRW_BKM_MAX_COUNT);
    if(g_srv_brw_cntx.bkm_cntx_p[selected_index].type != SRV_BRW_BKM_TYPE_EMPTY)
    {
        error_code = srv_brw_bkm_remove_item(selected_index);
        if(error_code >= 0)
        {
            srv_brw_bkm_free_item_memory(&g_srv_brw_cntx.bkm_cntx_p[selected_index]);
            g_srv_brw_cntx.bkm_cntx_p[selected_index].type = SRV_BRW_BKM_TYPE_EMPTY;
            g_srv_brw_cntx.bookmark_count--;
        }
    }
    return error_code;
}

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
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
S8 srv_brw_bkm_get_parent_folder_index(U8 *parent_folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    U8 array_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(bkm_cntx_ptr);
    if(*parent_folder != 0)
    {
        for(array_index = 0; array_index < SRV_BRW_BKM_MAX_COUNT; array_index++)
        {
            if(bkm_cntx_ptr[array_index].type == SRV_BRW_BKM_TYPE_FOLDER)
            {
                if(!app_stricmp((S8*)parent_folder, (S8*)bkm_cntx_ptr[array_index].title))
                {
                    return(array_index);
                }
            }
        }
    }
    return SRV_BRW_ROOT_PARENT_INDEX;
}
#endif


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
MMI_BOOL srv_brw_is_bookmark_present(U8 *file_name, srv_brw_bkm_bookmark_list_struct *bkm_list, U8 bkm_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    U8 array_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(array_index = 0; array_index < bkm_count; array_index++)
    {
        if(!app_stricmp((S8*)file_name, (S8*)bkm_cntx_ptr[bkm_list[array_index].actual_index].title))
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

#ifdef __COSMOS_MMI_PACKAGE__
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
S32 srv_brw_bookmark_export_all_bookmarks(U8 *sel_folder_path, srv_brw_bkm_rsp_funcptr_type callback_function)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    U8* dest_folder_path;
    S32 error_code = SRV_BRW_BKM_ERROR_OK;
    srv_brw_bookmark_export_ind_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(bkm_cntx_ptr);

    dest_folder_path = (U8*) srv_brw_malloc((SRV_BRW_BKM_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    memset(dest_folder_path, 0, (SRV_BRW_BKM_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) dest_folder_path, (S8*) sel_folder_path);
    mmi_ucs2cat((S8*) dest_folder_path, (S8*) SRV_BRW_BKM_DEFAULT_EXPORT_FOLDER_NAME);
    if(mmi_ucs2strlen((S8*) dest_folder_path) >= SRV_FMGR_PATH_MAX_LEN - 2)
    {
        srv_brw_free(dest_folder_path);
        return FS_PATH_OVER_LEN_ERROR;
    }
    error_code = FS_CreateDir((UI_string_type) dest_folder_path);
    if(error_code == FS_NO_ERROR || error_code == FS_FILE_EXISTS)
    {
        error_code = SRV_BRW_BKM_ERROR_OK;
    }
    else
    {
        srv_brw_free(dest_folder_path);
        return error_code;
    }
    mmi_ucs2cat((S8*) dest_folder_path, (S8*) L"\\");
    myMsgPtr = (srv_brw_bookmark_export_ind_struct*) OslConstructDataPtr(sizeof(srv_brw_bookmark_export_ind_struct));
    myMsgPtr->exported = 0;
    myMsgPtr->failed = 0;
    myMsgPtr->current_index = 0;
    myMsgPtr->destination_folder_path = dest_folder_path;
    myMsgPtr->rsp_callback = callback_function;
    while(bkm_cntx_ptr[myMsgPtr->current_index].type != SRV_BRW_BKM_TYPE_USER_CREATED_FILE &&
        myMsgPtr->current_index < SRV_BRW_BKM_MAX_COUNT)
    {
        myMsgPtr->current_index++;
    }
    srv_brw_event_hdlr_send_ilm_to_mmi(MSG_ID_SRV_BRW_BOOKMARK_EXPORT_IND, myMsgPtr, NULL);
    return SRV_BRW_BKM_ERROR_OK;
}

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
void srv_brw_bookmark_export_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_bkm_bookmark_context_struct *bkm_cntx_ptr = g_srv_brw_cntx.bkm_cntx_p;
    srv_brw_bookmark_export_ind_struct *localBuff_p = (srv_brw_bookmark_export_ind_struct*) msg;
    S32 error_code = SRV_BRW_BKM_ERROR_OK;
    U8 *export_file_name;
    U8 *export_file_path;
    FS_HANDLE file_handle;
    U8 export_count = 5;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(bkm_cntx_ptr);
    MMI_ASSERT(localBuff_p->current_index < SRV_BRW_BKM_MAX_COUNT);
    while(export_count > 0)
    {
        while(bkm_cntx_ptr[localBuff_p->current_index].type != SRV_BRW_BKM_TYPE_USER_CREATED_FILE &&
            localBuff_p->current_index < SRV_BRW_BKM_MAX_COUNT)
        {
            localBuff_p->current_index++;
        }
        if(localBuff_p->current_index == SRV_BRW_BKM_MAX_COUNT)
        {
            break;
        }
        export_file_name = (U8*)srv_brw_malloc((SRV_BRW_BKM_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
        memset(export_file_name, 0, (SRV_BRW_BKM_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        if(bkm_cntx_ptr[localBuff_p->current_index].parent_index!= SRV_BRW_ROOT_PARENT_INDEX)
        {
            U8 *temp_buffer;
            temp_buffer = (U8*)srv_brw_malloc((SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);
            memset(temp_buffer, 0, (SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);
            mmi_chset_utf8_to_ucs2_string((U8*) export_file_name, 
                SRV_BRW_BKM_MAX_FILE_NAME_LEN * ENCODING_LENGTH,
                (U8*) bkm_cntx_ptr[bkm_cntx_ptr[localBuff_p->current_index].parent_index].title);
            mmi_ucs2cat((S8*)export_file_name ,(S8*)L"(");
            mmi_chset_utf8_to_ucs2_string((U8*) temp_buffer, 
                SRV_BRW_BKM_MAX_FILE_NAME_LEN * ENCODING_LENGTH,
                (U8*) bkm_cntx_ptr[localBuff_p->current_index].title);
            mmi_ucs2cat((S8*)export_file_name ,(S8*)temp_buffer);
            mmi_ucs2cat((S8*)export_file_name ,(S8*)L")");
            srv_brw_free(temp_buffer);
        }
        else
    #endif
        {
            mmi_chset_utf8_to_ucs2_string((U8*) export_file_name, 
                SRV_BRW_BKM_MAX_FILE_NAME_LEN * ENCODING_LENGTH,
                (U8*) bkm_cntx_ptr[localBuff_p->current_index].title);
        }
        if((mmi_ucs2strlen((S8*) export_file_name) + mmi_ucs2strlen((S8*) localBuff_p->destination_folder_path)) >= (SRV_FMGR_PATH_MAX_LEN - SRV_BRW_BKM_MAX_FILE_EXTN_LEN))
        {
            error_code = FS_PATH_OVER_LEN_ERROR;
        }
        else
        {
            export_file_path = (U8*)srv_brw_malloc((SRV_BRW_BKM_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
            memset(export_file_path, 0, (SRV_BRW_BKM_MAX_PATH_LEN + 1) * ENCODING_LENGTH);
            mmi_ucs2cpy((S8*)export_file_path, (S8*)localBuff_p->destination_folder_path);
            mmi_ucs2cat((S8*)export_file_path, (S8*)export_file_name);
            mmi_ucs2cat((S8*)export_file_path ,(S8*)L".");
            mmi_ucs2cat((S8*)export_file_path ,(S8*)SRV_BRW_BKM_FILE_EXTN_URL_STRING);
            file_handle = FS_GetAttributes((UI_string_type) export_file_path);
            if(file_handle < 0)
            {
                file_handle = FS_Open((UI_string_type) export_file_path, FS_CREATE);
                if (file_handle < 0)
                {
                    error_code = file_handle;
                }
                else
                {
                    U8 *url = (U8*)srv_brw_malloc((SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
                    memset(url, 0, (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH);
                    mmi_asc_to_ucs2((S8*) url, (S8*)g_srv_brw_cntx.bkm_cntx_p[localBuff_p->current_index].url);
                    error_code = srv_vbkm_writer_convert_file_to_standard_format(file_handle, export_file_name, url);
                    srv_brw_free(url);
                    FS_Close(file_handle);
                }
            }
            else
            {
                error_code = file_handle;
            }
            srv_brw_free(export_file_path);
        }
        srv_brw_free(export_file_name);
        if(error_code == SRV_BRW_BKM_ERROR_OK)
        {
            localBuff_p->exported++;
        }
        else
        {
            localBuff_p->failed++;
        }
        localBuff_p->current_index++;
        export_count--;
    }
    while(bkm_cntx_ptr[localBuff_p->current_index].type != SRV_BRW_BKM_TYPE_USER_CREATED_FILE &&
        localBuff_p->current_index < SRV_BRW_BKM_MAX_COUNT)
    {
        localBuff_p->current_index++;
    }
    if(localBuff_p->current_index == SRV_BRW_BKM_MAX_COUNT)
    {
        srv_brw_bookmark_export_rsp_struct *rsp;
        rsp = (srv_brw_bookmark_export_rsp_struct*)srv_brw_malloc(sizeof(srv_brw_bookmark_export_rsp_struct));
        memset(rsp, 0, sizeof(srv_brw_bookmark_export_rsp_struct));
        rsp->exported = localBuff_p->exported;
        rsp->failed = localBuff_p->failed;
        localBuff_p->rsp_callback((void*)rsp);
        srv_brw_free(rsp);
        srv_brw_free(localBuff_p->destination_folder_path);
    }
    else
    {
        srv_brw_bookmark_export_ind_struct *myMsgPtr;
        myMsgPtr = (srv_brw_bookmark_export_ind_struct*) OslConstructDataPtr(sizeof(srv_brw_bookmark_export_ind_struct));
        myMsgPtr->exported = localBuff_p->exported;
        myMsgPtr->failed = localBuff_p->failed;
        myMsgPtr->current_index = localBuff_p->current_index;
        myMsgPtr->destination_folder_path = localBuff_p->destination_folder_path;
        myMsgPtr->rsp_callback = localBuff_p->rsp_callback;
        srv_brw_event_hdlr_send_ilm_to_mmi(MSG_ID_SRV_BRW_BOOKMARK_EXPORT_IND, myMsgPtr, NULL);
    }
}
#endif

/***********************************************New Bookmark Design End****************************************************/
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
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
S32 srv_brw_bkm_get_bookmarks_count_for_op_hs(srv_brw_bkm_types_enum selected_file_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nBytes = 0;
    FS_HANDLE file_handle = 0;
    WCHAR *root_file_path;
    U8* buffer;
    srv_brw_bkm_types_enum file_type;
    S32 count = 0;
    S32 result;
    U8 temp[SRV_BRW_BKM_TIMESTAMP_SIZE + 1] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    root_file_path = (WCHAR*)OslMalloc((mmi_ucs2strlen((S8*) g_srv_brw_cntx.default_folder_path) + mmi_ucs2strlen((S8*)SRV_BRW_BKM_ROOT_FILE_NAME) + 2) * ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) root_file_path, (S8*) g_srv_brw_cntx.default_folder_path);
    mmi_ucs2cat((S8*) root_file_path, (S8*) L"\\");
    mmi_ucs2cat((S8*) root_file_path, (S8*) SRV_BRW_BKM_ROOT_FILE_NAME);

    file_handle = FS_Open((const WCHAR*) root_file_path, FS_READ_WRITE | FS_CREATE);
    if(file_handle < 0)
    {
        OslMfree(root_file_path);
        return file_handle;
    }
    OslMfree(root_file_path);
    buffer = (U8*)OslMalloc(SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE);
    memset(buffer, 0, SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE);
    FS_Seek(file_handle, 0, SEEK_SET);
    while((result = FS_Read(file_handle, buffer, SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE, &nBytes)) == FS_NO_ERROR && nBytes != 0)
    {
        memset(temp, 0, SRV_BRW_BKM_TIMESTAMP_SIZE + 1);
        strncpy((S8*)temp, (S8*)buffer, SRV_BRW_BKM_TYPE_SIZE);
        file_type = atoi((const S8*)temp);
        if(file_type == selected_file_type)
        {
            count++;
        }
    }
    FS_Close(file_handle);
    OslMfree(buffer);
    return count;
}
#endif /* #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */

#endif /* __MMI_VBOOKMARK__ */

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERSRVBOOKMARKS_C */
