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
 * EbrSrv.c
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#include "MMI_features.h"

#ifdef __MMI_EBOOK_READER__
#include "mmi_rp_app_ebook_def.h"
#include "EbookProt.h"
#include "ebrsrvgprot.h"
#include "MMIDataType.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "fs_type.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_timer_gprot.h"
#include "TimerEvents.h"
#include "fs_func.h"
#include "kal_non_specific_general_types.h"
#include "FileMgrSrvGProt.h"
#include "kal_release.h"
#include "EbookGprot.h"
#include "fs_errcode.h"
#include "gui_inputs.h"
#include "stdio.h"
#include "wgui_inputs.h"
#include "lcd_sw_inc.h"
#include "PixcomFontEngine.h"

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_bookshelf_init
 * DESCRIPTION
 *  Initialize the bookshelf context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ebr_bookshelf_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_bookshelf_init();
}


/*****************************************************************************
 * FUNCTION
 *  srv_ebr_bookshelf_create
 * DESCRIPTION
 *  Create the bookshelf
 * PARAMETERS
 *  boooshelf_path_name  [IN] The bookshelf's name
 *  p_bookshelf_setting  [IN] The bookshelf's setting
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_ebr_bookshelf_create(CHAR *boooshelf_path_name, srv_ebr_bookshelf_setting *p_bookshelf_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bookshelf_id;
    mmi_ebr_frm_bookshelf_context *p_bookshelf_context = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bookshelf_id = mmi_ebr_frm_get_first_available_bookshelf_id();
    if (bookshelf_id < 0)
    {
        goto end;
    }
    p_bookshelf_context = mmi_ebr_frm_get_bookshelf_context(bookshelf_id);
    mmi_ucs2cpy(p_bookshelf_context->path_name, (const CHAR*)boooshelf_path_name);
    memcpy(&p_bookshelf_context->setting, p_bookshelf_setting, sizeof(*p_bookshelf_setting));
    p_bookshelf_context->state = MMI_EBR_FRM_BOOKSHELF_STATE_IDLE;
    p_bookshelf_context->refresh_handle = (FS_HANDLE)-1;
    p_bookshelf_context->refresh_complete_handler = NULL;

end:
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOKSHELF_CREATE, bookshelf_id);
    return bookshelf_id;
}


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
srv_ebr_op_result_enum srv_ebr_bookshelf_set_setting(S32 bookshelf_id, srv_ebr_bookshelf_setting *p_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_bookshelf_context *p_bookshelf_context = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOKSHELF_SET_SETTING, bookshelf_id, p_setting);
    p_bookshelf_context = mmi_ebr_frm_get_bookshelf_context(bookshelf_id);
    memcpy(&p_bookshelf_context->setting, p_setting, sizeof(*p_setting));
    return SRV_EBR_OP_RESULT_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ebr_bookshelf_get_setting
 * DESCRIPTION
 *  Save the settings for bookshelf
 * PARAMETERS
 *  bookshelf_id       [IN] The id of the bookshelf
 *  p_setting          [IN] The setting for the bookshelf
 * RETURNS
 *  srv_ebr_op_result_enum
 *****************************************************************************/
srv_ebr_bookshelf_setting *srv_ebr_bookshelf_get_setting(S32 bookshelf_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_bookshelf_context *p_bookshelf_context = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_bookshelf_context = mmi_ebr_frm_get_bookshelf_context(bookshelf_id);
    return &p_bookshelf_context->setting;
}


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
srv_ebr_op_result_enum srv_ebr_bookshelf_refresh(
                            S32 bookshelf_id, 
                            void (*refresh_complete_handler)(srv_ebr_bookshelf_refresh_result_struct *))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_bookshelf_context *p_bookshelf_context = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOKSHELF_REFRESH, bookshelf_id, refresh_complete_handler);
    p_bookshelf_context = mmi_ebr_frm_get_bookshelf_context(bookshelf_id);
    p_bookshelf_context->state = MMI_EBR_FRM_BOOKSHELF_STATE_REFRESH;
    p_bookshelf_context->refresh_handle = (FS_HANDLE)-1;
    p_bookshelf_context->refresh_complete_handler = refresh_complete_handler;
    StartTimerEx(
        EBOOK_REFRESH_BOOK_SHELF_TIMER, 
        EBOOK_REFRESH_BOOKSHELF_TIMER_DURATION, 
        mmi_ebr_frm_refresh_bookshelf_timeout_handler, 
        (void*)bookshelf_id);
    return SRV_EBR_OP_RESULT_BLOCKING;
}


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
void srv_ebr_bookshelf_abort_refresh(S32 bookshelf_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_bookshelf_context *p_bookshelf_context = NULL;
    srv_ebr_bookshelf_refresh_result_struct refresh_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_bookshelf_context = mmi_ebr_frm_get_bookshelf_context(bookshelf_id);
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOKSHELF_ABORT_REFRESH, bookshelf_id, p_bookshelf_context->state);
    if (MMI_EBR_FRM_BOOKSHELF_STATE_REFRESH == p_bookshelf_context->state)
    {
        StopTimer(EBOOK_REFRESH_BOOK_SHELF_TIMER);
        if (p_bookshelf_context->refresh_handle >= 0)
        {
            FS_FindClose(p_bookshelf_context->refresh_handle);
            p_bookshelf_context->refresh_handle = (FS_HANDLE)-1;
        }
        p_bookshelf_context->state = MMI_EBR_FRM_BOOKSHELF_STATE_IDLE;
        refresh_result.bookshelf_id = bookshelf_id;
        refresh_result.refresh_result = SRV_EBR_OP_RESULT_CANCELLED;
        p_bookshelf_context->refresh_complete_handler(&refresh_result);        
    }
}


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
S32 srv_ebr_delete_book(CHAR *book_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *file_path = NULL;
    CHAR *ext_name = NULL;
    CHAR ext_name_array[8];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_path = mmi_ebr_frm_malloc_memory(SRV_EBR_MAX_PATH_LEN * ENCODING_LENGTH);
    
    /* Delete the .TXT file */
    mmi_ucs2cpy((CHAR*)file_path, book_path);       
    ext_name = (CHAR*)srv_fmgr_path_get_extension_ptr(file_path);
    if (mmi_ucs2icmp((const CHAR*)ext_name, (const CHAR*)L"TXT"))
    {
        mmi_ebr_frm_free_memory((void **)&file_path);
        return -1;
    }
    mmi_ebr_frm_async_delete((const WCHAR*)file_path);

    /* Delete the temp file */
    mmi_asc_to_ucs2(ext_name_array, (CHAR*)EBR_EBOOK_TXZ);
    mmi_ucs2cpy(ext_name, ext_name_array);
    mmi_ebr_frm_async_delete((const WCHAR*)file_path);

    /* Delete the line_index file */
    mmi_asc_to_ucs2(ext_name_array, (CHAR*)EBR_TXT_EBOOK_LARGE_FONT_LINE_FILE_EXT);
    mmi_ucs2cpy(ext_name, ext_name_array);
    mmi_ebr_frm_async_delete((const WCHAR*)file_path);

    mmi_asc_to_ucs2(ext_name_array, (CHAR*)EBR_TXT_EBOOK_MEDIUM_FONT_LINE_FILE_EXT);
    mmi_ucs2cpy(ext_name, ext_name_array);
    mmi_ebr_frm_async_delete((const WCHAR*)file_path);

    mmi_asc_to_ucs2(ext_name_array, (CHAR*)EBR_TXT_EBOOK_SMALL_FONT_LINE_FILE_EXT);
    mmi_ucs2cpy(ext_name, ext_name_array);
    mmi_ebr_frm_async_delete((const WCHAR*)file_path);
    
    /* Delete the nfo file */
    mmi_asc_to_ucs2(ext_name_array, (CHAR*)EBR_TXT_EBOOK_NFO_FILE_EXT);
    mmi_ucs2cpy(ext_name, ext_name_array);
    mmi_ebr_frm_async_delete((const WCHAR*)file_path);

    mmi_ebr_frm_free_memory((void **)&file_path);
    return 0;
}


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
S32 srv_ebr_bookshelf_delete_book(S32 bookshelf_id, CHAR *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_bookshelf_context *p_bookshelf_context = NULL;
    CHAR *p_book_path = NULL;
    S32 return_val = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOKSHELF_DELETE_BOOK, bookshelf_id, file_name);
    p_bookshelf_context = mmi_ebr_frm_get_bookshelf_context(bookshelf_id);
    p_book_path = mmi_ebr_frm_malloc_memory(SRV_EBR_MAX_PATH_LEN * ENCODING_LENGTH);
    mmi_ucs2cpy(p_book_path, p_bookshelf_context->path_name);
    mmi_ucs2cat(p_book_path, file_name);
    return_val = srv_ebr_delete_book(p_book_path);
    mmi_ebr_frm_free_memory((void **)&p_book_path);
    return return_val;
}


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
srv_ebr_op_result_enum srv_ebr_bookshelf_close(S32 bookshelf_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_bookshelf_context *p_bookshelf_context = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOKSHELF_CLOSE, bookshelf_id);
    MMI_ASSERT(bookshelf_id >= 0);
    srv_ebr_bookshelf_abort_refresh(bookshelf_id);
    p_bookshelf_context = mmi_ebr_frm_get_bookshelf_context(bookshelf_id);
    p_bookshelf_context->in_use = MMI_FALSE;
    return SRV_EBR_OP_RESULT_SUCCESS;
}


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
void srv_ebr_book_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOK_INIT);
    mmi_ebr_frm_book_init();
}


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
srv_ebr_op_result_enum srv_ebr_book_convert(S32 book_id, S32 *p_fs_error, void (*open_book_handler)(srv_ebr_open_book_enum, void *))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_op_result_enum op_result = MMI_EBR_FRM_OP_RESULT_SUCCESS;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOK_CONVERT, book_id, p_fs_error, open_book_handler);
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_book_context->open_book_handler = open_book_handler;
    op_result = mmi_ebr_frm_convert_record_and_line_index(book_id, p_fs_error);
    if (MMI_EBR_FRM_OP_RESULT_BLOCKING == op_result)
    {
        p_book_context = mmi_ebr_frm_get_book_context(book_id);
        if (SRV_EBR_BOOK_CONVERT_SPEED_SLOW == p_book_context->convert_speed)
        {
            StartTimerEx(EBOOK_RECURSIVE_TIMER, EBOOK_RECURSIVE_LONG_TIMER_DURATION, mmi_ebr_frm_convert_record_and_line_index_fsm, (void*)book_id);
        }
        else
        {
            StartNonAlignTimerEx(EBOOK_RECURSIVE_TIMER, EBOOK_RECURSIVE_SHORT_TIMER_DURATION, mmi_ebr_frm_convert_record_and_line_index_fsm, (void*)book_id);
        }
    }
    return mmi_ebr_frm_op_result_to_srv_result(op_result);
}


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
srv_ebr_op_result_enum srv_ebr_book_search(
                            S32 book_id,
                            srv_ebr_search_type_enum search_type,
                            CHAR *search_string,
                            S32 start_line,
                            S32 start_line_offset,
                            void (*search_complete_hdlr)(srv_ebr_book_search_result *))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 data_len = 0;
    S32 record_id = 0;
    S32 record_offset = 0;
    S32 total_offset = 0;
    S32 file_hnd = -1;
    S32 string_length = 0;
    mmi_ebr_app_search_result_enum search_result = MMI_EBR_APP_SEARCH_RESULT_SUCCESS;
    mmi_ebr_frm_search_struct *p_search_struct = NULL;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_book_context->search_complete_hdlr = search_complete_hdlr;
    
    MMI_EBR_RESET_SEARCH_STRING_FLAG(p_book_context->search_string_flag, MMI_EBR_LAST_RECORD_FLAG);
    mmi_ucs2cpy(p_book_context->last_search_string_input, (const CHAR*)search_string);
    file_hnd = p_book_context->convert_temp_file_hnd;
    if (file_hnd < 0)
    {
        search_result = MMI_EBR_APP_SEARCH_RESULT_FAIL;
        goto end;
    }

    if (MMI_FALSE == mmi_ebr_frm_get_data_len(book_id, start_line, start_line, &total_offset, &data_len, NULL))
    {
        search_result = MMI_EBR_APP_SEARCH_RESULT_FAIL;
        goto end;
    }
    total_offset += start_line_offset * ENCODING_LENGTH;
    record_id = total_offset / EBR_RECORD_SIZE_MAX + 1;
    record_offset = (total_offset % EBR_RECORD_SIZE_MAX) / ENCODING_LENGTH;
    
    string_length = mmi_ucs2strlen((const CHAR*)search_string);
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOK_SEARCH_LOG1, record_id, record_offset, string_length);
    if ((record_offset + string_length) > (EBR_RECORD_SIZE_MAX / ENCODING_LENGTH))
    {
        record_id++;
        record_offset = record_offset - (EBR_RECORD_SIZE_MAX / ENCODING_LENGTH);
        MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOK_SEARCH_LOG2, record_id, record_offset);
    }

end:
    if (MMI_EBR_APP_SEARCH_RESULT_FAIL == search_result)
    {
        return SRV_EBR_OP_RESULT_FAILURE;
    }
    else
    {
        p_search_struct = mmi_ebr_frm_malloc_memory(sizeof(mmi_ebr_frm_search_struct));
        p_search_struct->book_id = book_id;
        p_search_struct->file_hnd = file_hnd;
        p_search_struct->record_id = record_id;
        p_search_struct->record_offset = record_offset;
        p_search_struct->search_type = search_type;
        p_book_context->search_arg = (void*)p_search_struct;
        StartTimerEx(EBR_SEARCH_BLOCK_TIMER, EBR_FRM_SEARCH_BREAK_TIMER, mmi_ebr_frm_search_timeout_handler, p_search_struct);        
        return SRV_EBR_OP_RESULT_BLOCKING;
    }
}


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
srv_ebr_op_result_enum srv_ebr_book_abort_search(S32 book_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_book_context *p_book_context = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    StopTimer(EBR_SEARCH_BLOCK_TIMER);
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOK_ABORT_SEARCH, book_id, p_book_context->search_arg);
    if (NULL != p_book_context->search_arg)
    {
        mmi_ebr_frm_free_memory((void **)&p_book_context->search_arg);
        p_book_context->search_arg = NULL;
    }
    return SRV_EBR_OP_RESULT_SUCCESS;
}


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
srv_ebr_op_result_enum srv_ebr_book_jump_to_line(S32 book_id, S32 line_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL op_error = MMI_FALSE;
    S32 fs_error = 0;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    mmi_ebr_frm_book_context *p_book_context = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;
    p_nfo_file->start_line = line_index;
    p_nfo_file->start_line_offset = 0;

    op_error = mmi_ebr_frm_async_save_settings_in_nfo_file(
                book_id,
                &fs_error);

    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOK_JUMP_TO_LINE, book_id, line_index, fs_error);
    if (MMI_FALSE == op_error)
    {
        if ((FS_READ_ONLY_ERROR == fs_error) || (FS_WRITE_PROTECTION == fs_error))
        {
            return SRV_EBR_OP_RESULT_SUCCESS;
        }
        else
        {
            return SRV_EBR_OP_RESULT_FAILURE;
        }
    }
    else
    {
        return SRV_EBR_OP_RESULT_SUCCESS;
    }
}


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
S32 srv_ebr_book_add_bookmark(S32 book_id, srv_ebr_book_bookmark_struct *p_bookmark)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    S32 fs_error = 0;
    kal_int64 line_file_handle = -1;
    U32 bookmark_offset;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;
    
    line_file_handle = p_book_context->convert_line_file_hnd;
    
    fs_error = FS_Seek(
                    line_file_handle, 
                    p_bookmark->start_line * sizeof(p_bookmark->start_line), 
                    FS_FILE_BEGIN);
    if (fs_error < 0)
    {
        return fs_error;
    }
    
    fs_error = FS_Read(
                    line_file_handle, 
                    &bookmark_offset,
                    sizeof(p_bookmark->total_offset),
                    NULL);
    p_bookmark->total_offset = bookmark_offset;
    
    if (FS_NO_ERROR != fs_error)
    {
        return fs_error;
    }
    
    while ((mmi_ucs2strlen((const CHAR*)p_nfo_file->book_marks[i].bookmark_name)) &&
           (i < SRV_EBR_MAX_BOOKMARK_NUMBER))
    {
        i++;
    }

    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOK_ADD_BOOKMARK, book_id, p_bookmark, i);
    if (SRV_EBR_MAX_BOOKMARK_NUMBER == i)
    {
        return (-1);
    }
    else
    {
        memcpy(&p_nfo_file->book_marks[i], p_bookmark, sizeof(srv_ebr_book_bookmark_struct));
    }
    if (mmi_ebr_frm_async_save_settings_in_nfo_file(
                book_id, 
                &fs_error))
    {
        return i;
    }
    else
    {
        return fs_error;
    }   
}


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
srv_ebr_op_result_enum srv_ebr_book_delete_bookmark(S32 book_id, S32 bookmark_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOK_DELETE_BOOKMARK, book_id, bookmark_id);
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;

    memset(
        (CHAR*)&(p_nfo_file->book_marks[bookmark_id]),
        0x00, 
        sizeof(srv_ebr_book_bookmark_struct));

    if (mmi_ebr_frm_async_save_settings_in_nfo_file(
            book_id, 
            NULL))
    {
        return SRV_EBR_OP_RESULT_SUCCESS;
    }
    else
    {
        return SRV_EBR_OP_RESULT_FAILURE;
    }
}


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
srv_ebr_op_result_enum srv_ebr_book_get_bookmark_list(S32 book_id, S32 *p_bookmark_id, S32 *p_bookmark_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    S32 no_of_bookmarks = 0;
    FS_HANDLE nfo_handle = -1;
    S32 fs_error = 0;
    srv_ebr_op_result_enum return_value = SRV_EBR_OP_RESULT_SUCCESS;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;

    nfo_handle = p_book_context->async_nfo_file_handle;
    if (nfo_handle < 0)
    {
        return_value = SRV_EBR_OP_RESULT_FAILURE;
        goto end;
    }
    
    fs_error = FS_Seek(
                    nfo_handle, 
                    ((U32)&p_nfo_file->book_marks - (U32)p_nfo_file), 
                    FS_FILE_BEGIN);
    if (fs_error < 0)
    {
        return_value = SRV_EBR_OP_RESULT_FAILURE;
        goto end;
    }
    
    fs_error = FS_Read(
                    nfo_handle, 
                    p_nfo_file->book_marks,
                    sizeof(p_nfo_file->book_marks),
                    NULL);
    if (FS_NO_ERROR != fs_error)
    {
        return_value = SRV_EBR_OP_RESULT_FAILURE;
        goto end;
    }

    *p_bookmark_count = 0;
    while (no_of_bookmarks < SRV_EBR_MAX_BOOKMARK_NUMBER)
    {
        if (p_nfo_file->book_marks[no_of_bookmarks].bookmark_name[0] != 0 || 
            p_nfo_file->book_marks[no_of_bookmarks].bookmark_name[1] != 0)
        {
            *p_bookmark_id = no_of_bookmarks;
            p_bookmark_id++;
            (*p_bookmark_count)++;
        }
        no_of_bookmarks++;
    }
end:
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOK_GET_BOOKMARK_LIST, book_id, p_bookmark_id, p_bookmark_count, no_of_bookmarks);
    return return_value;
}


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
void srv_ebr_book_sort_bookmark(srv_ebr_book_bookmark_struct *p_bookmark_info, S32 *p_bookmark_id, S32 bookmark_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0, bookmark_id = 0, change = 0;
    srv_ebr_book_bookmark_struct bookmark_info;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (j = bookmark_count - 1; j > 0; j--)
    {
        change = 0;
        for (i = 0; i < j; i++)
        {
            if (p_bookmark_info[i].start_line > p_bookmark_info[i + 1].start_line)
            {
                bookmark_info = p_bookmark_info[i];
                p_bookmark_info[i] = p_bookmark_info[i + 1];
                p_bookmark_info[i + 1] = bookmark_info;

                bookmark_id = p_bookmark_id[i];
                p_bookmark_id[i] = p_bookmark_id[i + 1];
                p_bookmark_id[i + 1] = bookmark_id;

                change = 1;
            }
        }
        if (0 == change)
        {
            break;
        }
    } 
}

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
srv_ebr_op_result_enum srv_ebr_book_get_bookmark_info(S32 book_id, S32 bookmark_id, srv_ebr_book_bookmark_struct *p_bookmark_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOK_GET_BOOKMARK_INFO, book_id, bookmark_id, p_bookmark_info);
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;
    memcpy(p_bookmark_info, &p_nfo_file->book_marks[bookmark_id], sizeof(srv_ebr_book_bookmark_struct));
    return SRV_EBR_OP_RESULT_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_bookmark_offset_to_line_index
 * DESCRIPTION
 *  Get the bookmark info
 * PARAMETERS
 *  book_id         [IN]  The identifier of the book
 *  bookmark_id     [IN]  The identifier of the bookmark
 * RETURNS
 *  S32 line number [OUT]error if S32 < 0
 *****************************************************************************/
S32 srv_ebr_book_bookmark_offset_to_line_index(S32 book_id, S32 bookmark_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    kal_int64 line_file_handle = -1;
    U32 total_line, total_size;
    U32 head_line, end_line, middle_line = 0;
    U32 middle_line_offset, bookmark_offset, book_total_offset;
    S32 fs_error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;
    line_file_handle = p_book_context->convert_line_file_hnd;
    
    bookmark_offset = p_nfo_file->book_marks[bookmark_id].total_offset;

    fs_error = FS_Seek(
                line_file_handle, 
                -4, 
                FS_FILE_END);
	if(fs_error < 0)
	{
	    return fs_error;
	}
    fs_error = FS_Read(
                    line_file_handle, 
                    &book_total_offset,
                    sizeof(book_total_offset),
                    NULL);
	if(fs_error < 0)
	{
	    return fs_error;
	}
	if(bookmark_offset > book_total_offset)
	{
	    bookmark_offset = book_total_offset;
	}
	
    FS_GetFileSize(line_file_handle, &total_size);
    total_line = total_size / 4;

    head_line = 0;
    end_line = total_line;
    while(head_line < end_line)
    {
        middle_line = (head_line + end_line + 1)/2;
        fs_error = FS_Seek(
                    line_file_handle, 
                    middle_line * sizeof(middle_line), 
                    FS_FILE_BEGIN);
		if(fs_error < 0)
		{
		    return fs_error;
		}
        fs_error = FS_Read(
                        line_file_handle, 
                        &middle_line_offset,
                        sizeof(middle_line_offset),
                        NULL);
		if(fs_error < 0)
		{
		    return fs_error;
		}
		
        if(bookmark_offset == middle_line_offset)
		{
			return middle_line;
		}
        else if(bookmark_offset < middle_line_offset)
        {
            end_line = middle_line - 1;
        }
        else
        {
            head_line = middle_line;
        }
    }
    return middle_line;
}


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
srv_ebr_op_result_enum srv_ebr_book_get_line_info(S32 book_id, srv_ebr_book_line_info *p_line_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOK_GET_LINE_INFO_LOG1, book_id, p_line_info);
    if (NULL != p_line_info)
    {
        p_book_context = mmi_ebr_frm_get_book_context(book_id);
        p_nfo_file = &p_book_context->nfo_book_struct;
        p_line_info->start_line = p_nfo_file->start_line;
        p_line_info->start_line_offset = p_nfo_file->start_line_offset;
        p_line_info->total_line = p_book_context->total_line_num;
        MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOK_GET_LINE_INFO_LOG2, p_line_info->start_line, p_line_info->start_line_offset, p_line_info->total_line);
    }
    return SRV_EBR_OP_RESULT_SUCCESS;
}


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
MMI_BOOL srv_ebr_book_get_data(S32 book_id, U8 **buffer, S32 *buf_len, S32 start_line, S32 end_line, S32 *p_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 start_line_offset = 0;
    S32 total_length = 0;
    S32 start_offset_in_buffer = 0;
    U32 read_length = 0;
    gui_line_info_struct line_info_struct;
    S32 total_offset_from_file_head = 0;  
    S32 fs_error = -1;
    MMI_BOOL op_error = MMI_FALSE;
    U8 *p_src_buffer = NULL;
    U8 *p_dest_buffer = NULL;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_src_buffer = p_book_context->src_buffer;
    p_dest_buffer = p_book_context->dest_buffer;
    p_nfo_file = &p_book_context->nfo_book_struct;

    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOK_GET_DATA_LOG1, book_id, start_line, end_line, p_book_context->total_line_num, p_book_context->state);
    if (mmi_ebr_frm_book_is_in_converting_state(book_id))
    {        
        if (MMI_TRUE == p_book_context->current_converting_status)            
        {
            start_line_offset = p_book_context->convert_line_offset;
            start_offset_in_buffer = p_book_context->total_converted_characters;
            *buffer = &p_dest_buffer[(start_line_offset - start_offset_in_buffer) * ENCODING_LENGTH];
            *buf_len = p_book_context->total_characters_in_start_buffer - (start_line_offset - start_offset_in_buffer);
            if (p_book_context->current_record_id > p_book_context->num_records)
            {
                *buf_len += 1;
            }            
        }
        else 
        {
			if(start_line > p_book_context->total_line_num)
			{
				start_line = p_book_context->total_line_num;
			}
            if (start_line <= p_book_context->total_line_num)
            {
                if ((0 == p_book_context->total_line_num)&&
                    (MMI_EBR_FRM_BOOK_STATE_GENERATE_LINE_INDEX == p_book_context->state))
                {
                    if (MMI_EBR_FRM_OP_RESULT_FAILURE == mmi_ebr_frm_convert_record_and_line_index(book_id, &fs_error))
                    {
                        goto error;
                    }
                }
                else
                {
                    p_nfo_file->start_line = start_line;
                    p_nfo_file->end_line = end_line;
                    p_nfo_file->start_line_offset = 0;

                    /* Get the begin position in line_index file */
                    fs_error = FS_Seek(
                                p_book_context->convert_line_file_hnd, 
                                start_line * sizeof(gui_line_info_struct),
                                FS_FILE_BEGIN);
                    if (fs_error < 0)
                    {
                        goto error;
                    }
                    fs_error = FS_Read(
                                p_book_context->convert_line_file_hnd,
                                &line_info_struct,
                                sizeof(gui_line_info_struct),
                                NULL);
                    if (fs_error < 0)
                    {
                        goto error;
                    }
                    start_line_offset = line_info_struct.offset * ENCODING_LENGTH;

                    /* Get the total length of the data between start_line and end_line */
                    if (end_line < (p_book_context->total_line_num - 1))
                    {
                        fs_error = FS_Seek(
                                    p_book_context->convert_line_file_hnd, 
                                    (end_line + 1) * sizeof(gui_line_info_struct),
                                    FS_FILE_BEGIN);
                        if (fs_error < 0)
                        {
                            goto error;
                        }
                        fs_error = FS_Read(
                                    p_book_context->convert_line_file_hnd,
                                    &line_info_struct,
                                    sizeof(gui_line_info_struct),
                                    NULL);
                        if (fs_error < 0)
                        {
                            goto error;
                        }
                        total_length = line_info_struct.offset * ENCODING_LENGTH - start_line_offset;
                    }
                    else
                    {
                        end_line = p_book_context->total_line_num - 1;
                        if (end_line > start_line)
                        {
                            fs_error = FS_Seek(
                                        p_book_context->convert_line_file_hnd, 
                                        end_line * sizeof(gui_line_info_struct),
                                        FS_FILE_BEGIN);
                            if (fs_error < 0)
                            {
                                goto error;
                            }
                            fs_error = FS_Read(
                                        p_book_context->convert_line_file_hnd,
                                        &line_info_struct,
                                        sizeof(gui_line_info_struct),
                                        NULL);
                            if (fs_error < 0)
                            {
                                goto error;
                            }
                            total_length = (line_info_struct.offset + CHARACTERS_IN_ONE_LINE) * ENCODING_LENGTH - start_line_offset;
                        }
                        else
                        {
                            total_length = CHARACTERS_IN_ONE_LINE * ENCODING_LENGTH;
                        }
                    }

                    fs_error = FS_Seek(
                                p_book_context->convert_temp_file_hnd,
                                start_line_offset,
                                FS_FILE_BEGIN);
                    if (fs_error < 0)
                    {
                        goto error;
                    }

                    if (total_length > sizeof(p_book_context->src_buffer))
                    {
						total_length = sizeof(p_book_context->src_buffer);
                    }

                    memset(p_src_buffer, 0x00, sizeof(p_book_context->src_buffer));

                    fs_error = FS_Read(
                                p_book_context->convert_temp_file_hnd,
                                p_src_buffer,
                                total_length,
                                &read_length);

                    if (FS_NO_ERROR != fs_error)
                    {
                        goto error;
                    }

                    *buffer = p_src_buffer;
                    *buf_len = read_length / ENCODING_LENGTH;
                }
            }
            else
            {
                 MMI_ASSERT(0);
            }
        }   
    }
    else
    {
        p_nfo_file->start_line = start_line;
        p_nfo_file->end_line = end_line;
        p_nfo_file->start_line_offset = 0;

       op_error = mmi_ebr_frm_get_data_len(book_id, start_line, end_line, &total_offset_from_file_head, buf_len, &fs_error);
        if (MMI_FALSE == op_error)
        {
            goto error;
        }
        op_error = mmi_ebr_frm_get_data_context(book_id, buffer, total_offset_from_file_head, *buf_len, &fs_error);
        if (MMI_FALSE == op_error)
        {
            goto error;
        }
    }
    return MMI_TRUE;
error:
#ifdef EBOOK_DEBUG_ERROR_ASSERT
    MMI_ASSERT(0);  
#endif
    if (NULL != p_error)
    {
        *p_error = fs_error;
    }
    return MMI_FALSE;
}


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
void srv_ebr_book_set_convert_speed(S32 book_id, srv_ebr_book_convert_speed_enum convert_speed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_book_context *p_book_context = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOK_SET_CONVERT_SPEED, book_id, convert_speed);
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    if (p_book_context->convert_speed != convert_speed)
    {
        p_book_context->convert_speed = convert_speed;
        if (MMI_TRUE == mmi_ebr_frm_book_is_in_converting_state(book_id))
        {
            StopTimer(EBOOK_RECURSIVE_TIMER);
            if (SRV_EBR_BOOK_CONVERT_SPEED_SLOW == p_book_context->convert_speed)
            {
                StartTimerEx(EBOOK_RECURSIVE_TIMER, EBOOK_RECURSIVE_LONG_TIMER_DURATION, mmi_ebr_frm_convert_record_and_line_index_fsm, (void*)book_id);
            }
            else
            {
                StartNonAlignTimerEx(EBOOK_RECURSIVE_TIMER, EBOOK_RECURSIVE_SHORT_TIMER_DURATION, mmi_ebr_frm_convert_record_and_line_index_fsm, (void*)book_id);
            }
        }
    }
}


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
srv_ebr_op_result_enum srv_ebr_book_close(S32 book_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *file_name = NULL;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_book_nfo_file = NULL;
    S32 save_error = -1;
//    srv_ebr_bookshelf_setting *p_bookshelf_setting;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(book_id >= 0);
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_book_nfo_file = &p_book_context->nfo_book_struct;

    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOK_CLOSE, book_id, p_book_context->state);
    if (mmi_ebr_frm_book_is_in_converting_state(book_id))
    {
        StopTimer(EBOOK_RECURSIVE_TIMER);
        p_book_context->state = MMI_EBR_FRM_BOOK_STATE_IDLE;

        mmi_ebr_frm_free_file_handles(book_id);
        p_book_nfo_file->convert_complete = MMI_FALSE;

  /*      file_name = mmi_ebr_frm_malloc_memory(SRV_EBR_MAX_PATH_LEN * ENCODING_LENGTH);
        p_bookshelf_setting = srv_ebr_bookshelf_get_setting(0);
        
        mmi_ebr_frm_get_line_file_name(
            p_book_context->book_full_path_name, 
            file_name,
            p_bookshelf_setting->font_size);
        
        mmi_ebr_frm_async_delete((const WCHAR*)file_name);

        mmi_ebr_frm_get_temp_file_name(p_book_context->book_full_path_name, file_name);
        mmi_ebr_frm_async_delete((const WCHAR*)file_name);
        mmi_ebr_frm_free_memory((void **)&file_name); 
        
        p_book_nfo_file->temp_encoding_file_format = 0;
        memset(p_book_nfo_file->book_marks, 0x00, sizeof(p_book_nfo_file->book_marks));*/
    }
    if (MMI_FALSE == mmi_ebr_frm_async_save_settings_in_nfo_file(
                        book_id,
                        &save_error))
    {
        /* if the error's reason is not file system's error, no need to delete the .nfo file */
        if ((FS_WRITE_PROTECTION == save_error) || (FS_READ_ONLY_ERROR == save_error))
        {
        }
        else
        {
            file_name = mmi_ebr_frm_malloc_memory(SRV_EBR_MAX_PATH_LEN * ENCODING_LENGTH);
            mmi_ebr_frm_get_nfo_file_name(p_book_context->book_full_path_name, file_name);
            mmi_ebr_frm_async_delete((const WCHAR*)file_name);
            mmi_ebr_frm_free_memory((void **)&file_name);
        }
    }
	mmi_ebr_frm_free_async_file_handles(book_id);

    if (IsMyTimerExist(EBR_SEARCH_BLOCK_TIMER))
    {
        srv_ebr_book_abort_search(book_id);
    }
    p_book_context->in_use = MMI_FALSE;
    return SRV_EBR_OP_RESULT_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ebr_book_async_open
 * DESCRIPTION
 *  Open the book
 * PARAMETERS
 *  full_book_path_name   [IN] The full path book name
 *  p_book_setting        [IN] The setting for the book
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_ebr_book_async_open(
                CHAR *full_book_path_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 book_id = 0;
    mmi_ebr_frm_op_result_enum create_result;
    
    S32 return_value = 0;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    U8 asc_file[SRV_FMGR_PATH_MAX_LEN + 1];  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    book_id = mmi_ebr_frm_get_first_available_book_id();
    if (book_id < 0)
    {
        return_value = SRV_EBR_BOOK_OPEN_ERROR_GENERAL;
        goto end;
    }
    else
    {
        return_value = book_id;
    }

    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    mmi_ucs2cpy(p_book_context->book_full_path_name , (const CHAR*)full_book_path_name);
    mmi_ucs2cpy(p_book_context->book_name, (const CHAR*)srv_fmgr_path_get_filename_ptr((WCHAR*)full_book_path_name));
    p_book_context->state = MMI_EBR_FRM_BOOK_STATE_IDLE;

    create_result = mmi_ebr_frm_open_source_file(book_id);
    if (MMI_EBR_FRM_OP_RESULT_SUCCESS != create_result)
    {
        return_value = mmi_ebr_frm_error_to_srv_error(create_result);      
        goto end;
    }

end:                         
    mmi_ucs2_to_asc((CHAR *)asc_file, (CHAR *)full_book_path_name);
	MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_SRV_BOOK_ASYNC_OPEN, asc_file, return_value);
    if ((return_value < 0) && (book_id >= 0))
    {
        p_book_context->in_use = MMI_FALSE;
    }
    return return_value;   
}


#endif /* __MMI_EBOOK_READER__ */
