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
 * ebrsrvgprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Ebook Reader External Interface
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#ifndef __EBRSRV_H__
#define __EBRSRV_H__

/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "FileMgrSrvGProt.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
/*******************************************************************************
* Macro Define
*******************************************************************************/

/* the character length of bookmark name(not including '\0') */
#define     SRV_EBR_MAX_BOOKMARK_NAME_SIZE      14
/* the number of a book's bookmark */
#define     SRV_EBR_MAX_BOOKMARK_NUMBER         10
/* the character length of searched string */
#define     SRV_EBR_MAX_SEARCH_STRING_LENGTH    24

/* File manager related */
/* the full path length of the book's name */
#define     SRV_EBR_MAX_PATH_LEN                (SRV_FMGR_PATH_MAX_LEN + 1)
/* the length of the book's name */
#define     SRV_EBR_MAX_FILE_LEN                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN)
/* the length of the book's extension name */
#define     SRV_EBR_EXTENSION_NAME_LENGTH       3

/*******************************************************************************
* Structure Define
*******************************************************************************/

/* the struct of the bookmark */
typedef struct
{
    /* the name of the bookmark */
    U8 bookmark_name[(SRV_EBR_MAX_BOOKMARK_NAME_SIZE + 1) * ENCODING_LENGTH];
    /* the start line of the bookmark */
    S32 start_line;
    /* the offset from the head of the UCS2 encoding file */
    U32 total_offset;
} srv_ebr_book_bookmark_struct;

/* the setting of the bookshelf */
typedef struct
{
    /* the font size of the bookshelf */
    U8 font_size;
    /* the scroll speed of the bookshelf */
    U8 scroll_speed;
    /* the scroll type of the bookshelf */
    U8 scroll_type;
    /* the encoding format of the bookshelf */
    U8 encoding_format;
    /* memory type of the bookshelf */
    U8 memory_type;
} srv_ebr_bookshelf_setting;


/* the operation result of the servive api */
typedef enum
{
    /* operation failed */
    SRV_EBR_OP_RESULT_FAILURE = 0,
    /* operation successfully */
    SRV_EBR_OP_RESULT_SUCCESS,
    /* operation cancelled */
    SRV_EBR_OP_RESULT_CANCELLED,
    /* operation blocking */
    SRV_EBR_OP_RESULT_BLOCKING,
    SRV_EBR_OP_RESULT_TOTAL
} srv_ebr_op_result_enum;

/* the search string result */
typedef enum
{
    /* the search string is invalid */
    SRV_EBR_SEARCH_RESULT_INVALID = 0,
    /* the search string is not completed */
    SRV_EBR_SEARCH_RESULT_NOT_COMPLETE,
    /* the search operation is successful */
    SRV_EBR_SEARCH_RESULT_SUCCESS,
    /* the search operation is failed */
    SRV_EBR_SEARCH_RESULT_FAIL,
    SRV_EBR_SEARCH_RESULT_TOTAL
} srv_ebr_search_result_enum;

/* the type of searching string */
typedef enum
{
    /* search string case sensitive */
    SRV_EBR_SEARCH_TYPE_CASE_SENSITIVE = 0,
    /* search string case insensitive */
    SRV_EBR_SEARCH_TYPE_CASE_INSENSITIVE,
    SRV_EBR_SEARCH_TYPE_TOTAL
} srv_ebr_search_type_enum;

/* the open book event which notify the app */
typedef enum
{
    /* the refresh screen event */
    SRV_EBR_OPEN_BOOK_REFRESH_SCREEN = 0,
    /* the convert record event */
    SRV_EBR_OPEN_BOOK_CONVERT_RECORD,
    /* the book is converted completely event */
    SRV_EBR_OPEN_BOOK_COMPLETE,
    /* the converting book error event */
    SRV_EBR_OPEN_BOOK_ERROR,
    SRV_EBR_OPEN_BOOK_TOTAL
} srv_ebr_open_book_enum;

/* the speed of converting book */
typedef enum
{
    /* the fast speed of converting book */
    SRV_EBR_BOOK_CONVERT_SPEED_FAST,
    /* the slow speed of converting book */
    SRV_EBR_BOOK_CONVERT_SPEED_SLOW,
    SRV_EBR_BOOK_CONVERT_SPEED_TOTAL
} srv_ebr_book_convert_speed_enum;

/* the struct of book line information */
typedef struct
{
    /* the line number when closing book last time */
    S32 start_line;
    /* the offset of line when closing book last time */
    S32 start_line_offset;
    /* the total line of the book */
    S32 total_line; 
} srv_ebr_book_line_info;

/* the struct of refreshing bookshelf */
typedef struct
{
    /* the id of the bookshelf */
    S32 bookshelf_id;
    /* the result of refreshing bookshelf */
    srv_ebr_op_result_enum refresh_result;
} srv_ebr_bookshelf_refresh_result_struct;

/* the struct of restoing bookshelf */
typedef struct
{
    /* the id of the bookshelf */
    S32 bookshelf_id;
    /* the result of restoring bookshelf */
    srv_ebr_op_result_enum restore_result;
} srv_ebr_bookshelf_restore_result_struct;

/* the struct of searching string in book */
typedef struct
{
    /* the id of the book */
    S32 book_id;
    /* the result of searching string */
    srv_ebr_op_result_enum search_result;
    /* if searching string successfully, the offset of the searching string */
    S32 offset;
} srv_ebr_book_search_result;

/* the struct of refreshing screen when converting book */
typedef struct
{
    /* the id of the book */
    S32 book_id;
    /* the total line number of current converting book */
    S32 line_number;
} srv_ebr_book_refresh_screen_struct;

/* the struct of converting book completely */
typedef struct
{
    /* the id of the book */
    S32 book_id;
} srv_ebr_book_open_complete_struct;

/* the struct of opening book error */
typedef struct
{
    /* the id of the book */
    S32 book_id;
    /* the error code of file system */
    S32 fs_error;
} srv_ebr_book_open_error_struct;

/* the opening book error result */
typedef enum
{
    /* the book type is not supported */
    SRV_EBR_BOOk_OPEN_ERROR_FIYE_TYPE_NOT_SUPPORTED = -1,
    /* the book is empty */
    SRV_EBR_BOOk_OPEN_ERROR_FIYE_EMPTY = -2,
    /* the storge memory is not enough */
    SRV_EBR_BOOK_OPEN_ERROR_MEMORY_NOT_ENOUGH = -3,
    /* the other error */
    SRV_EBR_BOOK_OPEN_ERROR_GENERAL = -4,
    SRV_EBR_BOOK_OPEN_ERROR_TOTAL   
} srv_ebr_book_open_error_enum;

/*******************************************************************************
* Export API 
*******************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_bookshelf_init
 * DESCRIPTION
 *  Initialize the bookshelf service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
******************************************************************************/
extern void srv_ebr_bookshelf_init(void);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_bookshelf_create
 * DESCRIPTION
 *  Create the bookshelf
 * PARAMETERS
 *  boooshelf_path_name  : [IN] The bookshelf's name
 *  p_bookshelf_setting  : [IN] The bookshelf's setting
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 srv_ebr_bookshelf_create(char *bookshelf_path_name, srv_ebr_bookshelf_setting *p_bookshelf_setting);


extern srv_ebr_op_result_enum srv_ebr_bookshelf_set_path(S32 bookshelf_id, char *bookshelf_path);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_bookshelf_set_setting
 * DESCRIPTION
 *  Save the settings for bookshelf
 * PARAMETERS
 *  bookshelf_id       [IN] The id of the bookshelf
 *  p_setting          [IN] The setting for the bookshelf
 * RETURNS
 *  srv_ebr_op_result_enum
 *****************************************************************************/
extern srv_ebr_op_result_enum srv_ebr_bookshelf_set_setting(S32 bookshelf_id, srv_ebr_bookshelf_setting *p_setting);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_bookshelf_get_setting
 * DESCRIPTION
 *  Save the settings for bookshelf
 * PARAMETERS
 *  bookshelf_id       [IN] The id of the bookshelf
 * RETURNS
 *  srv_ebr_bookshelf_setting*
 *****************************************************************************/
extern srv_ebr_bookshelf_setting *srv_ebr_bookshelf_get_setting(S32 bookshelf_id);

extern srv_ebr_op_result_enum srv_ebr_bookshelf_close(S32 bookshelf_id);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_bookshelf_refresh
 * DESCRIPTION
 *  Refresh the bookshelf operation
 * PARAMETERS
 *  bookshelf_id              [IN] The id of the bookshelf
 *  refresh_complete_handler  [IN] The callback function which app registers 
 *                                 in service                                    
 * RETURNS
 *  srv_ebr_op_result_enum
 *****************************************************************************/
extern srv_ebr_op_result_enum srv_ebr_bookshelf_refresh(S32 bookshelf_id, void (*refresh_complete_handler)(srv_ebr_bookshelf_refresh_result_struct *));

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_bookshelf_abort_refresh
 * DESCRIPTION
 *  Abort the refresh bookshelf operation
 * PARAMETERS
 *  bookshelf_id              [IN] The id of the bookshelf
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_ebr_bookshelf_abort_refresh(S32 bookshelf_id);

typedef struct
{
    char *filename;
    char *bookname;
    U32 date;
}srv_ebr_bookshelf_book_info_struct;

extern S32 mmi_ebr_bookshelf_get_book_number(S32 bookshelf_id);
extern S32 mmi_ebr_bookshelf_get_book_list(S32 bookshelf_id, S32 start_idx, S32 end_idx, srv_ebr_bookshelf_book_info_struct *book_list);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_bookshelf_close
 * DESCRIPTION
 *  Close the bookshelf
 * PARAMETERS
 *  bookshelf_id   [IN] The identifier of the bookshelf
 * RETURNS
 *  srv_ebr_op_result_enum
 *****************************************************************************/
extern srv_ebr_op_result_enum srv_ebr_bookshelf_close(S32 bookshelf_id);

extern S32 srv_ebr_bookshelf_add_book(S32 bookshelf_id, char *file_name);
extern S32 srv_ebr_bookshelf_add_dir(S32 bookshelf_id, char *dir_name, void *options);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_bookshelf_delete_book
 * DESCRIPTION
 *  Delet the book in bookshelf
 * PARAMETERS
 *  bookshelf_id   [IN] The identifier of the bookshelf
 *  file_name      [IN] The book's name
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 srv_ebr_bookshelf_delete_book(S32 bookshelf_id, char *file_name);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_delete_book
 * DESCRIPTION
 *  Delete the book
 * PARAMETERS
 *  book_path     [IN] The full path of the file
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 srv_ebr_delete_book(char *book_path);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_init
 * DESCRIPTION
 *  Initialize the book service
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_ebr_book_init(void);


/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_convert
 * DESCRIPTION
 *  Convert the book
 * PARAMETERS
 *  book_id        [IN] The identifier of the book  
 *  p_fs_error     [IN] Pointer the variable which stores the error
 * RETURNS
 *  srv_ebr_op_result_enum
 *****************************************************************************/
extern srv_ebr_op_result_enum srv_ebr_book_convert(S32 book_id, S32 *p_fs_error, void (*open_book_handler)(srv_ebr_open_book_enum, void *));

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_search
 * DESCRIPTION
 *  The search string interface 
 * PARAMETERS
 *  book_id              [IN] The identifier of the book
 *  search_type          [IN] The search string type
 *  search_string        [IN] The wanted search string
 *  start_line           [IN] The begin search start line
 *  start_line_offset    [IN] The begin search start line offset(in word, 2 bytes)
 *  search_complete_hdlr [IN] The callback app register in service, service will
 *                            use this callback to notify app when search completely
 * RETURNS
 *  srv_ebr_op_result_enum
 *****************************************************************************/
extern srv_ebr_op_result_enum srv_ebr_book_search(
                                S32 book_id,
                                srv_ebr_search_type_enum search_type,
                                char *search_string,
                                S32 start_line,
                                S32 start_line_offset,
                                void (*search_complete_hdlr)(srv_ebr_book_search_result *));

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_abort_search
 * DESCRIPTION
 *  Abort search string operation
 * PARAMETERS
 *  book_id        [IN] The identifier of the book    
 * RETURNS
 *  srv_ebr_op_result_enum
 *****************************************************************************/
extern srv_ebr_op_result_enum srv_ebr_book_abort_search(S32 book_id);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_jump_to_line
 * DESCRIPTION
 *  Jump to the specific line
 * PARAMETERS
 *  book_id        [IN] The identifier of the book
 *  line_index     [IN] The specific line
 * RETURNS
 *  srv_ebr_op_result_enum
 *****************************************************************************/
extern srv_ebr_op_result_enum srv_ebr_book_jump_to_line(S32 book_id, S32 line_index);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_add_bookmark
 * DESCRIPTION
 *  Add the bookmark
 * PARAMETERS
 *  book_id        [IN] The identifier of the book
 *  p_bookmark     [IN] Points the bookmark struct
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 srv_ebr_book_add_bookmark(S32 book_id, srv_ebr_book_bookmark_struct *p_bookmark);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_delete_bookmark
 * DESCRIPTION
 *  Delete the selected bookmark
 * PARAMETERS
 *  book_id        [IN] The identifier of the book
 *  bookmark_id    [IN] The identifier of the bookmark
 * RETURNS
 *  srv_ebr_op_result_enum
 *****************************************************************************/
extern srv_ebr_op_result_enum srv_ebr_book_delete_bookmark(S32 book_id, S32 bookmark_id);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_get_bookmark_list
 * DESCRIPTION
 *  Get the bookmark info
 * PARAMETERS
 *  book_id         [IN]  The identifier of the book
 *  p_bookmark_id   [OUT] The bookmark_id information
 *  p_bookmark_count[OUT] The bookmark count
 * RETURNS
 *  srv_ebr_op_result_enum
 *****************************************************************************/
extern srv_ebr_op_result_enum srv_ebr_book_get_bookmark_list(S32 book_id, S32 *p_bookmark_id, S32 *p_bookmark_count);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_get_bookmark_info
 * DESCRIPTION
 *  Get the bookmark info
 * PARAMETERS
 *  book_id         [IN]  The identifier of the book
 *  bookmark_id     [IN]  The identifier of the bookmark
 *  p_bookmark_info [OUT] The bookmark information
 * RETURNS
 *  srv_ebr_op_result_enum
 *****************************************************************************/
extern srv_ebr_op_result_enum srv_ebr_book_get_bookmark_info(S32 book_id, S32 bookmark_id, srv_ebr_book_bookmark_struct *p_bookmark_info);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_sort_bookmark
 * DESCRIPTION
 *  Sort the bookmark info
 * PARAMETERS
 *  p_bookmark_info  [IN] The bookmark information
 *  p_bookmark_id    [IN] The bookmark id
 *  bookmark_count   [IN] The number of bookmarks
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_ebr_book_sort_bookmark(srv_ebr_book_bookmark_struct *p_bookmark_info, S32 *p_bookmark_id, S32 bookmark_count);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_set_settings
 * DESCRIPTION
 *  Set the book's setting information
 * PARAMETERS
 *  book_id         [IN] The identifier of the book
 *  p_book_setting  [IN] The setting for the book
 * RETURNS
 *  srv_ebr_op_result_enum
 *****************************************************************************/
//extern srv_ebr_op_result_enum srv_ebr_book_set_settings(S32 book_id, srv_ebr_book_setting *p_book_setting);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_get_settings
 * DESCRIPTION
 *  Get the book's setting information
 * PARAMETERS
 *  book_id         [IN]  The identifier of the book
 * RETURNS
 *  srv_ebr_book_setting *
 *****************************************************************************/
//extern srv_ebr_book_setting *srv_ebr_book_get_settings(S32 book_id);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_get_line_info
 * DESCRIPTION
 *  Get the book's line information
 * PARAMETERS
 *  book_id         [IN] The identifier of the book
 *  p_line_info     [OUT]The book's line information
 * RETURNS
 *  srv_ebr_op_result_enum
 *****************************************************************************/
extern srv_ebr_op_result_enum srv_ebr_book_get_line_info(S32 book_id, srv_ebr_book_line_info *p_line_info);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_get_data
 * DESCRIPTION
 *  Get the data between start_line and end_line
 * PARAMETERS
 *  book_id     [IN]   The identifier of the book
 *  U8   **     [OUT]  The pointer points the address of data 
 *  size        [OUT]  The length of the data
 *  start_line  [IN]   The start line of the required data
 *  end_line    [IN]   The end line of the required data
 *  p_error     [OUT]  The pointer stores the error code
 * RETURNS
 *  MMI_BOOL:
 *  MMI_TRUE : Get the data successfully
 *  MMI_FALSE: Get the data failed
 *****************************************************************************/
extern MMI_BOOL srv_ebr_book_get_data(S32 book_id, U8 **buffer, S32 *buf_len, S32 start_line, S32 end_line, S32 *p_error);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_get_print_info
 * DESCRIPTION
 *  Get the book's print information
 * PARAMETERS
 *  book_id     [IN]   The identifier of the book
 *  file_name   [OUT]  The print file's name
 *  file_size   [OUT]  The print file's size
 * RETURNS
 *  srv_ebr_op_result_enum
 *****************************************************************************/
extern srv_ebr_op_result_enum srv_ebr_book_get_print_info(S32 book_id, char *file_name, U32 *file_size);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_close
 * DESCRIPTION
 *  Close the book 
 * PARAMETERS
 *  book_id        [IN] The identifier of the book     
 * RETURNS
 *  srv_ebr_op_result_enum
 *****************************************************************************/
extern srv_ebr_op_result_enum srv_ebr_book_close(S32 book_id);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_set_convert_speed
 * DESCRIPTION
 *  Convert the book
 * PARAMETERS
 *  book_id        [IN] The identifier of the book  
 *  convert_speed  [IN] The book's convert speed
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_ebr_book_set_convert_speed(S32 book_id, srv_ebr_book_convert_speed_enum convert_speed);

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_async_open
 * DESCRIPTION
 *  Open the book
 * PARAMETERS
 *  full_book_path_name   [IN] The full path book name
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 srv_ebr_book_async_open(S8 *full_book_path_name);


#endif /* __EBRSRV_H__ */
