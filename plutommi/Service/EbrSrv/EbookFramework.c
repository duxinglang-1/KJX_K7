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
 * EbookFramework.c
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
 *============================================================================== 
 *******************************************************************************/

/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */
/***************** Ebook Application implementation *********************/

/**************************************************************

   FILENAME : EbookFramework.c

   PURPOSE     : Framework Application Functions

   REMARKS     : nil

   AUTHOR      : Rajat Kumar

   DATE     : 

**************************************************************/
#include "MMI_features.h"
#ifdef __MMI_EBOOK_READER__

#include "mmi_rp_app_ebook_def.h"

#include "Conversions.h"
#include "app_crc.h"
//#include "LangModuleGProt.h"
/*PMT IRE START*/
#if defined ( __MMI_INDIC_ALG__)
#include "IndicEngineGprot.h"
#endif
/*PMT IRE END*/
#include "EbookProt.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "string.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "ebrsrvgprot.h"
#include "FileMgrSrvGProt.h"
#include "Unicodexdcl.h"
#include "fs_func.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "MMI_common_app_trc.h"
#include "mmi_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_gprot.h"
#include "sim_common_enums.h"
#include "EbookGprot.h"
#include "wgui_inputs.h"
#include "kal_public_api.h"
#include "gui_inputs.h"
#include "lcd_sw_inc.h"
#include "PixcomFontEngine.h"
#include "Gui_Setting.h"
#include "stdio.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_common_app_trc.h"
#include "nvram_common_defs.h"
#include "fs_gprot.h"
#include "imeisrvgprot.h"
#include "ebooksrc.h"

//mmi_ebr_frm_bookshelf_context g_ebr_frm_bookshelf_context_array[EBOOK_MAX_BOOKSHELF];
//static mmi_ebr_frm_bookshelf_context *g_ebr_frm_bookshelf_context_p = g_ebr_frm_bookshelf_context_array;
//mmi_ebr_frm_book_context g_ebr_frm_book_context_array[EBOOK_MAX_OPEN_BOOK];
//static mmi_ebr_frm_book_context *g_ebr_frm_book_context_p = g_ebr_frm_book_context_array;
 

static S32 g_ebr_frm_memory_malloc_count = 0;

/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_bookshelf_init
 * DESCRIPTION
 *  Initialize the bookshelf context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebr_frm_bookshelf_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < EBOOK_MAX_OPEN_BOOK; i++)
    {
        g_ebr_app_context_array_p->g_ebr_frm_bookshelf_context.in_use = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_get_first_available_bookshelf_id
 * DESCRIPTION
 *  Get first available bookshelf id
 * PARAMETERS
 *  void        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_ebr_frm_get_first_available_bookshelf_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < EBOOK_MAX_BOOKSHELF; i++)
    {
        if (MMI_FALSE == g_ebr_app_context_array_p->g_ebr_frm_bookshelf_context.in_use)
        {
            memset(&g_ebr_app_context_array_p->g_ebr_frm_bookshelf_context, 0, sizeof(mmi_ebr_frm_bookshelf_context));
            g_ebr_app_context_array_p->g_ebr_frm_bookshelf_context.in_use = MMI_TRUE;
            return i;
        }
    }
    return (-1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_get_bookshelf_context
 * DESCRIPTION
 *  Get bookshelf context
 * PARAMETERS
 *  bookshelf_id    [IN] The identifier of the bookshelf     
 * RETURNS
 *  mmi_ebr_frm_bookshelf_context *
 *****************************************************************************/
mmi_ebr_frm_bookshelf_context *mmi_ebr_frm_get_bookshelf_context(S32 bookshelf_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    return &g_ebr_app_context_array_p->g_ebr_frm_bookshelf_context_p[bookshelf_id];
    if(g_ebr_app_context_array_p)
    {
	    return &g_ebr_app_context_array_p->g_ebr_frm_bookshelf_context;
    }
	else
	{
		return NULL;
	}

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_refresh_book_operation
 * DESCRIPTION
 *  Refresh the specified file
 * PARAMETERS
 *  book_path     [IN] The path of the nfo file
 *  nfo_file_name [IN] The name of the nfo file
 * RETURNS
 *  mmi_ebr_frm_op_result_enum
 *****************************************************************************/
mmi_ebr_frm_op_result_enum mmi_ebr_frm_refresh_book_operation(CHAR *book_path, CHAR *nfo_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *file_path = NULL;
    CHAR *p_ext_name = NULL;
    CHAR file_ext_name[8];
    fs_overlapped_struct overlapped;
    CHAR *fs_async_buffer = NULL;
    kal_int32 job_id = -1;
	mmi_ebr_frm_op_result_enum ret = MMI_EBR_FRM_OP_RESULT_SUCCESS;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_path = mmi_ebr_frm_malloc_memory(SRV_EBR_MAX_PATH_LEN * ENCODING_LENGTH);
    mmi_ucs2cpy(file_path, (const CHAR*)book_path);
    mmi_ucs2cat(file_path, (const CHAR*)nfo_file_name);
    p_ext_name = (CHAR*)srv_fmgr_path_get_extension_ptr((WCHAR*)file_path);
    mmi_asc_to_ucs2(file_ext_name, EBR_TXT_EBOOK_NFO_FILE_EXT);
    if (mmi_ucs2cmp((const CHAR*)p_ext_name, (const CHAR*)file_ext_name))
    {
        ret = MMI_EBR_FRM_OP_RESULT_FAILURE; 
		goto END;
    }

    mmi_asc_to_ucs2(file_ext_name, EBR_FILE_TYPE_TXT);
    mmi_ucs2cpy(p_ext_name, file_ext_name);

    fs_async_buffer = mmi_ebr_frm_malloc_memory(FS_ASYNC_WORKING_BUFFER_SIZE);
    overlapped.callback = mmi_ebr_frm_async_refresh_file_callback;
	overlapped.response_flag = FS_RESPONSE_MESSAGE;
    overlapped.param = file_path;
    overlapped.priority = FS_PRIORITY_DEFAULT;
    overlapped.buf = (void *)fs_async_buffer;
    overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
    job_id = fs_async_open((const WCHAR*)file_path,FS_READ_WRITE, &overlapped);
	if(job_id < 0)
    {
		mmi_ebr_frm_free_memory((void **)&fs_async_buffer);
        ret = MMI_EBR_FRM_OP_RESULT_FAILURE;            
    }
    else
    {
        ret = MMI_EBR_FRM_OP_RESULT_SUCCESS; 
    }
END:
	if(ret == MMI_EBR_FRM_OP_RESULT_FAILURE)
	{
		mmi_ebr_frm_free_memory((void **)&file_path);
	}
	MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_REFRESH_BOOK_OPERATION, job_id, ret);
	return ret;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_async_refresh_file_callback
 * DESCRIPTION
 *  callback function of refresh the specified file
 * PARAMETERS
 *  async_job_id     [IN] job id
 *  result           [IN] async_XXX callback result
 *  data             [IN] buffer pointer
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 mmi_ebr_frm_async_refresh_file_callback(fs_job_id async_job_id, kal_int64 result, fs_async_callback_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    CHAR *file_path = NULL;
    CHAR *p_ext_name = NULL;
    CHAR file_ext_name[8];
	mmi_ebr_frm_op_result_enum ret = MMI_EBR_FRM_OP_RESULT_SUCCESS;
    CHAR *txt_file_name_array[] = {EBR_TXT_EBOOK_NFO_FILE_EXT,
                                 EBR_EBOOK_TXZ,
                                 EBR_TXT_EBOOK_LARGE_FONT_LINE_FILE_EXT,
                                 EBR_TXT_EBOOK_MEDIUM_FONT_LINE_FILE_EXT,
                                 EBR_TXT_EBOOK_SMALL_FONT_LINE_FILE_EXT};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_REFRESH_BOOK_CALLBACK, async_job_id, result);
    if(result >= 0)
    {  
       
       FS_Close(result);
       goto end;
    }

    file_path = data->param;
    p_ext_name = (CHAR*)srv_fmgr_path_get_extension_ptr((WCHAR*)file_path);
    mmi_asc_to_ucs2(file_ext_name, EBR_FILE_TYPE_TXT);
    if (mmi_ucs2cmp((const CHAR*)p_ext_name, (const CHAR*)file_ext_name))
    {
		ret = MMI_EBR_FRM_OP_RESULT_FAILURE;
        goto end;
    }

    for (i = 0; i < (sizeof(txt_file_name_array) / sizeof(CHAR*)); i++)
    {
        mmi_asc_to_ucs2(file_ext_name, txt_file_name_array[i]);
        mmi_ucs2cpy(p_ext_name, file_ext_name);
        mmi_ebr_frm_async_delete((const WCHAR*)file_path);
    }
    
end:
    mmi_ebr_frm_free_memory((void **)&data->param);
    mmi_ebr_frm_free_memory((void **)&data);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_refresh_bookshelf_timeout_handler
 * DESCRIPTION
 *  The timer out handler of the refresh bookshelf
 * PARAMETERS
 *  arg              [IN] The id of the bookshelf
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebr_frm_refresh_bookshelf_timeout_handler(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_hnd;
    FS_DOSDirEntry file_info;
    CHAR *path = NULL;
    CHAR *filename = NULL;
    S32 fs_error = FS_NO_ERROR;
    S32 bookshelf_id = -1; 
    CHAR *nfo_ext_name = NULL;
    MMI_BOOL refresh_complete = MMI_FALSE; /* the refresh operation is complete or not */
    srv_ebr_op_result_enum op_result = SRV_EBR_OP_RESULT_SUCCESS;
    srv_ebr_bookshelf_refresh_result_struct final_refresh_result;
    mmi_ebr_frm_bookshelf_context *p_bookshelf_context = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(EBOOK_REFRESH_BOOK_SHELF_TIMER);
    bookshelf_id = (S32)arg;
    p_bookshelf_context = mmi_ebr_frm_get_bookshelf_context(bookshelf_id);

    filename = mmi_ebr_frm_malloc_memory((SRV_EBR_MAX_FILE_LEN + 1) * ENCODING_LENGTH);
    nfo_ext_name = mmi_ebr_frm_malloc_memory((strlen(EBR_EBOOK_SEARCH_NFO_STR) + 1) * ENCODING_LENGTH);
    path = mmi_ebr_frm_malloc_memory(SRV_EBR_MAX_PATH_LEN * ENCODING_LENGTH);
        
    /* Get the universal nfo file name */
    mmi_ucs2cpy(path, (const CHAR*)p_bookshelf_context->path_name);
    mmi_asc_to_ucs2(nfo_ext_name, EBR_EBOOK_SEARCH_NFO_STR);
    mmi_ucs2cat(path, nfo_ext_name);

    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_REFRESH_BOOKSHELF_TIMEOUT_HANDLER_LOG1, bookshelf_id, p_bookshelf_context->refresh_handle);
    if ((FS_HANDLE)-1 == p_bookshelf_context->refresh_handle)
    {
        file_hnd = FS_FindFirst(
                    (const WCHAR*)path,
                    0,
                    0,
                    &file_info,
                    (WCHAR*)filename,
                    (SRV_EBR_MAX_FILE_LEN + 1) * ENCODING_LENGTH);
        if (file_hnd >= 0)
        {
            p_bookshelf_context->refresh_handle = file_hnd;
            if (!(file_info.Attributes & FS_ATTR_DIR))
            {
                if (MMI_EBR_FRM_OP_RESULT_SUCCESS != mmi_ebr_frm_refresh_book_operation(p_bookshelf_context->path_name, filename))
                {
                    op_result = SRV_EBR_OP_RESULT_FAILURE;
                    refresh_complete = MMI_TRUE;
                    goto end;
                }
            }
        }
        else
        {
            if (FS_NO_MORE_FILES == file_hnd)
            {
                op_result = SRV_EBR_OP_RESULT_SUCCESS;
            }
            else
            {
                op_result = SRV_EBR_OP_RESULT_FAILURE;
            }
            refresh_complete = MMI_TRUE;
            goto end;
        }
    }

    while ((mmi_frm_check_wait_to_run() < MMI_STATUS_FEW_WANT_TO_RUN) &&
           (MMI_STATUS_INPUT_EVENTS_WANT_TO_RUN != mmi_frm_check_wait_to_run()))
    {
        fs_error = FS_FindNext(
                    p_bookshelf_context->refresh_handle, 
                    &file_info, 
                    (WCHAR*)filename, 
                    (SRV_EBR_MAX_FILE_LEN + 1) * ENCODING_LENGTH);
        if (FS_NO_ERROR == fs_error)
        {
            if (MMI_EBR_FRM_OP_RESULT_SUCCESS != mmi_ebr_frm_refresh_book_operation(p_bookshelf_context->path_name, filename))
            {
                op_result = SRV_EBR_OP_RESULT_FAILURE;
                refresh_complete = MMI_TRUE;
                goto end;
            }
            else
            {
                refresh_complete = MMI_FALSE;
                goto end;
            }
        }
        else
        {
            if (FS_NO_MORE_FILES == fs_error)
            {
                op_result = SRV_EBR_OP_RESULT_SUCCESS;
            }
            else
            {
                op_result = SRV_EBR_OP_RESULT_FAILURE;
            }
            refresh_complete = MMI_TRUE;
            goto end;
        }
    }
    
end:
    mmi_ebr_frm_free_memory((void **)&filename);
    mmi_ebr_frm_free_memory((void **)&path);
    mmi_ebr_frm_free_memory((void **)&nfo_ext_name);

    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_REFRESH_BOOKSHELF_TIMEOUT_HANDLER_LOG2, refresh_complete, p_bookshelf_context->state);
    if (MMI_TRUE == refresh_complete)
    {
        if (MMI_EBR_FRM_BOOKSHELF_STATE_REFRESH == p_bookshelf_context->state)
        {
            if (p_bookshelf_context->refresh_handle >= 0)
            {
                FS_FindClose(p_bookshelf_context->refresh_handle);
                p_bookshelf_context->refresh_handle = (FS_HANDLE)-1;
            }
            p_bookshelf_context->state = MMI_EBR_FRM_BOOKSHELF_STATE_IDLE;
            final_refresh_result.bookshelf_id = bookshelf_id;
            final_refresh_result.refresh_result = op_result;
            p_bookshelf_context->refresh_complete_handler(&final_refresh_result);
        }
    }
    else
    {
        StartTimerEx(EBOOK_REFRESH_BOOK_SHELF_TIMER, EBOOK_REFRESH_BOOKSHELF_TIMER_DURATION, mmi_ebr_frm_refresh_bookshelf_timeout_handler, (void*)bookshelf_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_book_init
 * DESCRIPTION
 *  Initialize the book context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebr_frm_book_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < EBOOK_MAX_OPEN_BOOK; i++)
    {
        g_ebr_app_context_array_p->g_ebr_frm_book_context.in_use = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_get_first_available_book_id
 * DESCRIPTION
 *  Get the first available book id
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_ebr_frm_get_first_available_book_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < EBOOK_MAX_OPEN_BOOK; i++)
    {
        if (MMI_FALSE == g_ebr_app_context_array_p->g_ebr_frm_book_context.in_use)
        {
            memset(&(g_ebr_app_context_array_p->g_ebr_frm_book_context), 0x00, sizeof(mmi_ebr_frm_book_context));
            g_ebr_app_context_array_p->g_ebr_frm_book_context.in_use = MMI_TRUE;
			g_ebr_app_context_array_p->g_ebr_frm_book_context.src_file_hnd = -1;
			g_ebr_app_context_array_p->g_ebr_frm_book_context.convert_temp_file_hnd = -1;			
			g_ebr_app_context_array_p->g_ebr_frm_book_context.convert_line_file_hnd = -1;
			g_ebr_app_context_array_p->g_ebr_frm_book_context.async_nfo_file_handle = -1;

            mmi_ebr_frm_reset_line_base_data(i);
            return i;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_compare_book_last_modify_time
 * DESCRIPTION
 *  compare the ebook last modify time and the time recorded in the nfo file, 
 *  return false if they are equal, else return true
 * PARAMETERS
 *          
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
 MMI_BOOL mmi_ebr_frm_compare_book_last_modify_time(FS_DOSDateTime *book_last_modify_time, FS_DOSDateTime *nfo_file_record_time)
{
    if (book_last_modify_time->Second2 != nfo_file_record_time->Second2
        || book_last_modify_time->Minute != nfo_file_record_time->Minute
        || book_last_modify_time->Hour != nfo_file_record_time->Hour
        || book_last_modify_time->Day != nfo_file_record_time->Day
        || book_last_modify_time->Month != nfo_file_record_time->Month
        || book_last_modify_time->Year1980 != nfo_file_record_time->Year1980)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_is_empty_file
 * DESCRIPTION
 *  Check if it is an empty file
 * PARAMETERS
 *  book_id        [IN]  The identifier of the book
 *  file_hnd       [IN]  The handle of the file
 *  type           [IN]  The type of the file
 *  is_empty       [OUT] Identify whether the file is empty
 * RETURNS
 *  mmi_ebr_frm_op_result_enum
 *****************************************************************************/
mmi_ebr_frm_op_result_enum mmi_ebr_frm_is_empty_file(
                            S32 book_id, 
                            FS_HANDLE file_hnd, 
                            mmi_ebr_frm_file_type_enum type,
                            MMI_BOOL *is_empty)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define  TXT_FOOTER_START_SIZE   3
    U32 filesize, size;
    CHAR file_header[TXT_FOOTER_START_SIZE];
    CHAR UCS2empty[2] = {(CHAR)0xFF, (CHAR)0xFE};
    CHAR UCS2BEempty[2] = {(CHAR)0xFE, (CHAR)0xFF};
    CHAR UTF8empty[3] = {(CHAR)0xEF, (CHAR)0xBB, (CHAR)0xBF};   
    mmi_ebr_frm_op_result_enum op_result = MMI_EBR_FRM_OP_RESULT_SUCCESS;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(file_header, 0, sizeof(file_header));
    
    if (MMI_EBR_FRM_FILE_TYPE_TXT == type)
    {               
        if (FS_NO_ERROR != FS_GetFileSize(file_hnd, &filesize))
        {
            op_result = MMI_EBR_FRM_OP_RESULT_FAILURE;
            goto end;
        }
        if (0 == filesize)
        {
            *is_empty = MMI_TRUE;
            goto end;
        }
        if (FS_NO_ERROR != FS_Read(file_hnd, &file_header, TXT_FOOTER_START_SIZE, &size))
        {
            op_result = MMI_EBR_FRM_OP_RESULT_FAILURE;
            goto end;
        }
        
        if ((2 == filesize) && (strncmp(file_header, UCS2empty, 2) == 0 || strncmp(file_header, UCS2BEempty, 2) == 0))
        {
            *is_empty = MMI_TRUE;
            goto end;
        }
        else if ((3 == filesize) && (strncmp(file_header, UTF8empty, 3) == 0))
        {
            *is_empty = MMI_TRUE;
            goto end;
        }
        *is_empty = MMI_FALSE;
    }
end:
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_IS_EMPTY_FILE, type, *is_empty, op_result);
    return op_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_get_number_of_records
 * DESCRIPTION
 *  Set number of records
 * PARAMETERS
 *  book_size    [IN]  the size of the book
 *  record_size  [IN]  the size of the record
 * RETURNS
 *  the number of the records
 *****************************************************************************/
S32 mmi_ebr_frm_get_number_of_records(U32 book_size, U32 record_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == (book_size % record_size))
    {
        return (book_size / record_size);
    }
    else
    {
        return (book_size / record_size + 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_get_record_context
 * DESCRIPTION
 *  Convert the record 
 * PARAMETERS
 *  file_hnd            [IN]  the handle of the file       
 *  record_id           [IN]  the index of the record     
 *  file_type           [IN]  the type of the file
 *  buffer_start        [IN]  the buffer which is used to hold the context
 *  p_content_size      [OUT] the pointer points the number of bytes in buffer_start
 * RETURNS
 *  S32
 *  >= 0 : success
 *  < 0  : error
 *****************************************************************************/
S32 mmi_ebr_frm_get_record_context(
            S32 book_id,
            FS_HANDLE file_hnd, 
            S32 record_id, 
            mmi_ebr_frm_file_type_enum file_type, 
            U8 *buffer,
            S32 *p_content_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rec_size = 0;
    S32 fs_error = FS_NO_ERROR;
    S32 size = 0;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;

    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_GET_RECORD_CONTEXT_LOG1, file_type, record_id, buffer);
    
    if (MMI_EBR_FRM_FILE_TYPE_TXT == file_type)
    {
        rec_size = mmi_ebr_frm_get_record_size_txt(book_id, record_id);        
        fs_error = FS_Read(file_hnd, buffer, rec_size, (U32*)&size);
    }
    if (NULL != p_content_size)
    {
        *p_content_size = size;
    }
    
    return fs_error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_convert_record
 * DESCRIPTION
 *  Convert the record and write in temp file
 * PARAMETERS
 *  file_hnd            [IN]        
 *  new_file_hnd        [IN]        
 *  record_id           [IN]
 *  file_type           [IN]
 * RETURNS
 *  int
 *  >= 0 : success
 *  < 0  : error
 *****************************************************************************/
int mmi_ebr_frm_convert_record(S32 book_id, FS_HANDLE file_hnd, FS_HANDLE new_file_hnd, S32 record_id, mmi_ebr_frm_file_type_enum file_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size = 0;
    S32 total_bytes_converted = 0;
    U8 mmiEncoding = 0;
    U32 src_using_size;
    U32 src_end_pos;
    U8* buffer_start;
    S32 fs_error= 0;
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

    mmiEncoding = p_nfo_file->temp_encoding_file_format;

    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_CONVERT_RECORD_LOG1, mmiEncoding, record_id, p_book_context->over_the_record_border, p_book_context->total_characters_in_start_buffer, p_book_context->remain_unconverted_characters);
    if (record_id == 1)
    {
        p_book_context->over_the_record_border = 0;
    }

    memset(p_src_buffer, 0x00, sizeof(p_book_context->src_buffer));

    if (p_book_context->over_the_record_border > 0)
    {
        memcpy(p_src_buffer, p_book_context->tempArray, p_book_context->over_the_record_border);
    }
    
    buffer_start = p_src_buffer + p_book_context->over_the_record_border;

    if (FS_NO_ERROR != (fs_error = mmi_ebr_frm_get_record_context(book_id, file_hnd, record_id, file_type, buffer_start, &size)))
    {
        p_book_context->current_record_id = p_book_context->num_records;
        goto end;
    }
    
    mmi_chset_use_space_for_unknown_character();

    if (0 != p_book_context->remain_unconverted_characters)
    {
        memcpy(p_book_context->dest_buffer,
            p_nfo_file->left_chars,
            p_book_context->remain_unconverted_characters * ENCODING_LENGTH);
    }
    
    memset(
        p_dest_buffer + p_book_context->remain_unconverted_characters * (ENCODING_LENGTH), 
        0x00, 
        sizeof(p_book_context->dest_buffer) - p_book_context->remain_unconverted_characters * (ENCODING_LENGTH));

    total_bytes_converted = mmi_chset_convert_ex(
                                (mmi_chset_enum)mmiEncoding,
                                MMI_CHSET_UCS2,
                                (char*)p_src_buffer,
                                (char*)(p_dest_buffer + p_book_context->remain_unconverted_characters * 2),
                                sizeof(p_book_context->dest_buffer) - p_book_context->remain_unconverted_characters * (ENCODING_LENGTH),
                                &src_end_pos);
    src_using_size = src_end_pos - (U32)(p_src_buffer);

    /* translate the string cluster */
    if(((total_bytes_converted - 2) / 2) > 0)
    {
        S32 convert_len = total_bytes_converted;
        convert_len = mmi_lm_cluster_translate((U16*)(p_dest_buffer + p_book_context->remain_unconverted_characters * 2), (total_bytes_converted - 2) / 2);
        MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_CONVERT_RECORD_LOG2, size, src_using_size, total_bytes_converted, convert_len);
        (p_dest_buffer + p_book_context->remain_unconverted_characters * 2)[convert_len * 2] = 0; 
        (p_dest_buffer + p_book_context->remain_unconverted_characters * 2)[convert_len * 2 + 1] = 0;
        total_bytes_converted = (convert_len + 1) * 2;
    }
    
    if (record_id == p_book_context->num_records)
    {
        fs_error = FS_Write(new_file_hnd, (p_dest_buffer + p_book_context->remain_unconverted_characters * 2), total_bytes_converted, (U32*)&size);        
    }
    else
    {
        if (src_using_size < size + p_book_context->over_the_record_border)
        {
            /* some content doesn't convert from src buffer, we seek the file pointer */
            p_book_context->over_the_record_border = (p_book_context->over_the_record_border + size) - src_using_size;
            if (p_book_context->over_the_record_border <= EBR_MAX_OVER_THE_RECORD_BORDER)
            {
                memcpy (p_book_context->tempArray, p_src_buffer + src_using_size, p_book_context->over_the_record_border);
                fs_error = FS_Write(new_file_hnd, (p_dest_buffer + p_book_context->remain_unconverted_characters * 2), total_bytes_converted - 2, (U32*)&size);
            }
            else
            {
                p_book_context->over_the_record_border = 0;
                p_book_context->current_record_id = p_book_context->num_records;
                fs_error = FS_Write(new_file_hnd, (p_dest_buffer + p_book_context->remain_unconverted_characters * 2), total_bytes_converted, (U32*)&size);
            }
        }
        else
        {
            p_book_context->over_the_record_border = 0;
            fs_error = FS_Write(new_file_hnd, (p_dest_buffer + p_book_context->remain_unconverted_characters * 2), total_bytes_converted - 2, (U32*)&size);
        }
    }
    mmi_chset_do_not_use_space_for_unknown_character();

    if (FS_NO_ERROR != fs_error)
    {
        p_book_context->current_record_id = p_book_context->num_records;
        goto end;        
    }
    
end:
    p_book_context->open_book_handler(SRV_EBR_OPEN_BOOK_CONVERT_RECORD, NULL);
    return fs_error;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_get_record_size_txt
 * DESCRIPTION
 *  Get the record size for text file.
 * PARAMETERS
 *  rec_num     [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 mmi_ebr_frm_get_record_size_txt(S32 book_id, S32 rec_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 rec_size;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;
    if (rec_num < p_book_context->num_records)
    {
        rec_size = EBR_RECORD_SIZE_MAX;
    }
    else
    {
        rec_size = p_nfo_file->book_size % EBR_RECORD_SIZE_MAX;
        if (rec_size == 0 && p_nfo_file->book_size > 0)
        {
            rec_size = EBR_RECORD_SIZE_MAX;
        }
    }
    return rec_size;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_start_decompression
 * DESCRIPTION
 *  Start decompression
 * PARAMETERS
 *  decompressed_buffer     [IN]        
 *  compressed_buffer       [IN]        
 *  size                    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebr_frm_start_decompression(U8 *decompressed_buffer, U8 *compressed_buffer, U32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define  COUNT_BITS  3
    U32 i, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < *size;)
    {
        unsigned c = compressed_buffer[i++];

        if (c >= 1 && c <= 8)
        {
            while (c--)
                /* copy 'c' bytes */
            {
                if (j >= EBR_RECORD_SIZE_MAX)
                {
                    goto end;
                }
                decompressed_buffer[j++] = compressed_buffer[i++];
            }
        }
        else if (c <= 0x7F)
            /* 0,09-7F = self */
        {
            if (j >= EBR_RECORD_SIZE_MAX)
            {
                goto end;
            }
            decompressed_buffer[j++] = c;
        }

        else if (c >= 0xC0) /* space + ASCII char */
        {
            if (j >= EBR_RECORD_SIZE_MAX - 1)
            {
                goto end;
            }
            decompressed_buffer[j++] = ' ', decompressed_buffer[j++] = c ^ 0x80;
        }

        else
        {   /* 80-BF = sequences */
            S32 di, n;

            c = (c << 8) + compressed_buffer[i++];
            di = (c & 0x3FFF) >> COUNT_BITS;
            for (n = (c & ((1 << COUNT_BITS) - 1)) + 3; n--; ++j)
            {
                if (j >= EBR_RECORD_SIZE_MAX)
                {
                    goto end;
                }
                decompressed_buffer[j] = decompressed_buffer[j - di];
            }
        }
    }
  end:
    *size = j;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_bm_search
 * DESCRIPTION
 *  Search Algo
 * PARAMETERS
 *  text_in_UCS2        [IN]   the buffer which is used to search the string    
 *  pat                 [IN]   the searched string 
 *  start_pos           [IN]   the start search position
 *  size                [In] 
 * RETURNS
 *  MMI_BOOL 
 *  MMI_TRUE : the wanted string is searched in the buffer
 *  MMI_FALSE: the wanted string is not searched in the buffer
 *****************************************************************************/
MMI_BOOL mmi_ebr_frm_bm_search(S16 *text_in_UCS2, S16 *pat, S32 *start_pos, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 len; /* the length of the pat */
    S32 buffer_length; /* the length of the text_in_UCS2 */
    S32 start; /* the begin search position (from the last character to the first character) */
    S32 clus_len = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = mmi_ucs2strlen((const CHAR*)pat);
    buffer_length = mmi_ucs2strlen((const CHAR*)text_in_UCS2);
    start = len - 1 + (*start_pos + 1);
    
    if (buffer_length < len)
    {
        return MMI_FALSE;
    }
    
    /* begin to search */
    while (start < buffer_length)
    {
        S32 count = 0;

        while (count < len)
        {
            if (text_in_UCS2[start - count] != pat[(len - 1) - count])
            {
                break;
            }
            else
            {
                /* MTI START MAUI_00066860 */
                #ifdef  __MMI_INDIC_ALG__
                if ((IRE_IS_CHAR_TYPE_HALANT(text_in_UCS2[start - count -1])) && (!(len - 1 - count)))
                {
                    break;
                }
                #endif
                /* MTI END MAUI_00066860 */ 

                count++;
            }
        }
    #ifdef  __MMI_INDIC_ALG__
        if (count == len)
        {
            U16 cluster_buffer[SRV_EBR_MAX_SEARCH_STRING_LENGTH + 1];  /* just to fill the cluster for the purpose of getting its length */

            clus_len = 0;
            ire_init_cluster_start_p((PU8) (text_in_UCS2 + start));
            /* MTI START MAUI_00070099 */
            ire_init_cluster_end_p((PU8) (text_in_UCS2 + start + (( SRV_EBR_MAX_SEARCH_STRING_LENGTH + 1)/ 2)));
            /* MTI END MAUI_00070099 */
            clus_len = ire_get_cluster(cluster_buffer);
            /* MTI START MAUI_00066860 */
            if (IRE_IS_CHAR_TYPE_HALANT(cluster_buffer[0]))
            {
                count =0;
            }
            /* MTI END MAUI_00066860 */

        }
    #endif /*  __MMI_INDIC_ALG__ */ 
        /* search success !*/
        if (count == len && clus_len == 1)
        {
            *start_pos = (start - count + 1);
            break;
        }
        /* not found */
        else
        {
            /* length is the moving length */
            S32 length = 0;
            
            /* for __MMI_INDIC_ALG__, the string is not found, countinue search*/
            #ifdef  __MMI_INDIC_ALG__
            if (clus_len != 1)
            {
                count--;
            }
            #endif /*  __MMI_INDIC_ALG__ */ 
            
            /* length is the moving length */
            length = (len - 1) - count;
            for (i = ((len - 1) - count - 1); i >= 0; i--)
            {
                if (text_in_UCS2[start - count] == pat[i])
                {
                    length = (len - 1) - count - 1 - i;
                    break;
                }
            }
            start += (length + 1);
        }

    }
    if (start >= buffer_length)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_async_save_settings_in_nfo_file
 * DESCRIPTION
 *  Save settings in Nfo file.
 * PARAMETERS
 *  book_id              [IN]  the opened id of the book
 *  nfo_book_struct   [IN]  the pointer points the nfo struct
 *  p_fs_error        [OUT] the pointer points to the FS error
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_ebr_frm_async_save_settings_in_nfo_file(S32 book_id, S32 *p_fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fs_error = 0;
    FS_HANDLE nfo_hnd = -1;
    MMI_BOOL ret_value = MMI_TRUE;

	mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *nfo_book_struct = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	p_book_context = mmi_ebr_frm_get_book_context(book_id);
    nfo_book_struct = &p_book_context->nfo_book_struct;
	nfo_hnd = p_book_context->async_nfo_file_handle;
	
    if (nfo_hnd < 0)
    {
        ret_value = MMI_FALSE;
        if (NULL != p_fs_error)
        {
            *p_fs_error = nfo_hnd;
        }
        goto end;
    }
    fs_error = FS_Seek(nfo_hnd, 0, FS_FILE_BEGIN);
    if (fs_error < 0)
    {
        ret_value = MMI_FALSE;
        if (NULL != p_fs_error)
        {
            *p_fs_error = fs_error;
        }
        goto end;
    }
    nfo_book_struct->final_check = applib_crc_update(
                                    EBOOK_CHECK_SUM_ACK, 
                                    (U8*)nfo_book_struct, 
                                    sizeof(*nfo_book_struct) - sizeof(nfo_book_struct->final_check));
    fs_error = FS_Write(nfo_hnd, nfo_book_struct, sizeof(*nfo_book_struct), NULL);
    if (FS_NO_ERROR != fs_error)
    {
        ret_value = MMI_FALSE;
        if (NULL != p_fs_error)
        {
            *p_fs_error = fs_error;
        }
        goto end;
    }    
end:
	MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_SAVE_SETTINGS_IN_NFO_FILE, ret_value);
    return ret_value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_get_book_context
 * DESCRIPTION
 *  Get the book context
 * PARAMETERS
 *  book_id    [IN] The identifier of the book
 * RETURNS
 *  mmi_ebr_frm_book_context *
 *****************************************************************************/
mmi_ebr_frm_book_context *mmi_ebr_frm_get_book_context(S32 book_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_ebr_app_context_array_p)
	{
        return &g_ebr_app_context_array_p->g_ebr_frm_book_context;
	}
	else
		return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_get_line_file_name
 * DESCRIPTION
 *  Get the file name of line file
 * PARAMETERS
 *  ebook_name         [IN]   the name of the book 
 *  line_file_name     [IN]   the memory which holds the name of the line_index file
 *  font_size          [IN]   the font size of the book
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebr_frm_get_line_file_name(CHAR *ebook_name, CHAR *line_file_name, WGUI_FONT_SIZE font_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *ext_name = NULL;
    CHAR line_file_ext[8];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(line_file_ext, 0x00, sizeof(line_file_ext));
    mmi_ucs2cpy(line_file_name, ebook_name);

    ext_name = (CHAR*)srv_fmgr_path_get_extension_ptr((WCHAR*)line_file_name);

    if (NULL != ext_name)
    {
        if (('t' == ext_name[0]) || ('T' == ext_name[0]))
        {
            if (FONT_SIZE_SMALL == font_size)
            {
                mmi_asc_to_ucs2(line_file_ext, (CHAR*)EBR_TXT_EBOOK_SMALL_FONT_LINE_FILE_EXT);
            }
            else if (FONT_SIZE_MEDIUM == font_size)
            {
                mmi_asc_to_ucs2(line_file_ext, (CHAR*)EBR_TXT_EBOOK_MEDIUM_FONT_LINE_FILE_EXT);
            }
            else if (FONT_SIZE_LARGE == font_size)
            {
                mmi_asc_to_ucs2(line_file_ext, (CHAR*)EBR_TXT_EBOOK_LARGE_FONT_LINE_FILE_EXT);
            }
            else
            {
                MMI_ASSERT(0);
            }
        }
    }

    mmi_ucs2cpy(ext_name, line_file_ext);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_get_temp_file_name
 * DESCRIPTION
 *  Get the file name of temp file
 * PARAMETERS
 *  ebook_name         [IN]   the name of the book 
 *  temp_file_name     [IN]   the memory which holds the name of the temp file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebr_frm_get_temp_file_name(CHAR *ebook_name, CHAR *temp_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *ext_name = NULL;
    CHAR temp_file_ext[10];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(temp_file_ext, 0x00, sizeof(temp_file_ext));
    mmi_ucs2cpy(temp_file_name, ebook_name);

    ext_name = (CHAR*)srv_fmgr_path_get_extension_ptr((WCHAR*)temp_file_name);
    if (('t' == ext_name[0]) || ('T' == ext_name[0]))
    {
        mmi_asc_to_ucs2(temp_file_ext, (CHAR*)TXT_TEMP_EXT_STR);
    }
    
    ext_name -= 2;
    mmi_ucs2cpy(ext_name, temp_file_ext);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_get_nfo_file_name
 * DESCRIPTION
 *  Get the file name of nfo file
 * PARAMETERS
 *  ebook_name         [IN]   the name of the book 
 *  nfo_file_name      [IN]   the memory which holds the name of the nfo file
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebr_frm_get_nfo_file_name(CHAR *ebook_name, CHAR *nfo_file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *ext_name = NULL;
    CHAR temp_file_ext[8];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*)nfo_file_name, (const CHAR*)ebook_name);
    ext_name = (CHAR*)srv_fmgr_path_get_extension_ptr((WCHAR*)nfo_file_name);
    
    if (('t' == ext_name[0]) || ('T' == ext_name[0]))
    {
        mmi_asc_to_ucs2((CHAR*)temp_file_ext, (CHAR*)EBR_TXT_EBOOK_NFO_FILE_EXT);
    }

    mmi_ucs2cpy((CHAR*)ext_name, (CHAR*)temp_file_ext);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_convert_context_into_line
 * DESCRIPTION
 *  Get the data between start_line and end_line
 * PARAMETERS
 *  remain_unconverted_characters  [IN/OUT] the left unconverted characters
 *  end_flag                       [OUT]    identify whether the whole line_index file has been generated
 *  p_fs_error                     [OUT]    identify the error code
 * RETURNS
 *  MMI_BOOL 
 *  MMI_TRUE : Indicate this operation is successful.
 *  MMI_FALSE: Indicate this operation is failure.
 *****************************************************************************/
MMI_BOOL mmi_ebr_frm_convert_context_into_line(S32 book_id, S32 *remain_unconverted_characters, MMI_BOOL *end_flag, S32 *p_fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;
    S32 error = 0;
    S32 convert_characters_one_time = 0;
    gui_line_struct *line_info_struct = NULL;
    S32 buffer_index = 0;
    S32 i = 0;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    FS_HANDLE file_hnd = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *end_flag = MMI_FALSE;
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;

    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_CONVERT_CONTEXT_INTO_LINE_LOG1, p_book_context->total_line_num);
    if (0 == p_book_context->total_line_num)
    {
        file_hnd = p_book_context->convert_line_file_hnd;
        if (file_hnd < 0)
        {
            error = file_hnd;
            goto error_handle;
        }
        else
        {
            p_book_context->convert_line_file_hnd = file_hnd;
        }
    }
    
    memset(p_book_context->gui_line_info_struct_buffer, 0x00, sizeof(p_book_context->gui_line_info_struct_buffer));
    buffer_index = 0;
    
    while ((MMI_TRUE == mmi_ebr_frm_check_convert_context_into_line_loop()) || 
           (0 == p_book_context->total_line_num))
    {
        wgui_inputs_ml_jump_to_line_bg(p_book_context->total_line_num);
        line_info_struct = wgui_inputs_ml_get_layout_info_bg();

        MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_CONVERT_CONTEXT_INTO_LINE_LOG2, buffer_index, line_info_struct->line_count, line_info_struct->b_to_end);
        for (i = 0; i < line_info_struct->line_count; i++)
        {
            line_info_struct->array[i].offset += p_book_context->convert_line_offset;
        }

        if (line_info_struct->b_to_end == MMI_TRUE)
        {
            if(p_book_context->index_continue == MMI_TRUE)
            {
                p_book_context->index_continue = MMI_FALSE;
                error = FS_Seek(p_book_context->convert_line_file_hnd, p_nfo_file->index_file_convert_offset, FS_FILE_BEGIN);
            }
            else
            {
                error = FS_Seek(p_book_context->convert_line_file_hnd, 0, FS_FILE_END);
            }
            if (error < 0)
            {
                goto error_handle;
            }
            if (0 != buffer_index)
            {
                error = FS_Write(
                            p_book_context->convert_line_file_hnd, 
                            p_book_context->gui_line_info_struct_buffer, 
                            buffer_index * sizeof(gui_line_info_struct), 
                            NULL);
                if (FS_NO_ERROR != error)
                {
                    goto error_handle;
                }
            }
            error = FS_Write(
                        p_book_context->convert_line_file_hnd,
                        line_info_struct->array,
                        line_info_struct->line_count * sizeof(gui_line_info_struct),
                        NULL);
            if (FS_NO_ERROR != error)
            {
                goto error_handle;
            }

            *end_flag = MMI_TRUE;
            p_book_context->total_line_num += line_info_struct->line_count;
            p_book_context->convert_line_offset = 0;

            return MMI_TRUE;
        }
        
        if ((buffer_index + (line_info_struct->line_count - 1)) <= GUI_LINE_INFO_STRUCT_BUFFER_LENGTH / sizeof(gui_line_info_struct))
        {
            memcpy(&p_book_context->gui_line_info_struct_buffer[buffer_index], line_info_struct->array, (line_info_struct->line_count - 1) * sizeof(gui_line_info_struct));
            buffer_index += (line_info_struct->line_count - 1);
        }
        else
        {
            if(p_book_context->index_continue == MMI_TRUE)
            {
                p_book_context->index_continue = MMI_FALSE;
                error = FS_Seek(p_book_context->convert_line_file_hnd, p_nfo_file->index_file_convert_offset, FS_FILE_BEGIN);
            }
            else
            {
                error = FS_Seek(p_book_context->convert_line_file_hnd, 0, FS_FILE_END);
            }
            if (error < 0)
            {
                goto error_handle;
            }

            error = FS_Write(
                        p_book_context->convert_line_file_hnd, 
                        p_book_context->gui_line_info_struct_buffer, 
                        buffer_index * sizeof(gui_line_info_struct), 
                        NULL);
            if (FS_NO_ERROR != error)
            {
                goto error_handle;
            }
           
            memset(p_book_context->gui_line_info_struct_buffer, 0x00, sizeof(p_book_context->gui_line_info_struct_buffer));
            buffer_index = 0;
            
            memcpy(&p_book_context->gui_line_info_struct_buffer[buffer_index], line_info_struct->array, (line_info_struct->line_count - 1) * sizeof(gui_line_info_struct));
            buffer_index += (line_info_struct->line_count - 1);
            
        }

        p_book_context->total_line_num = line_info_struct->start_line_index + line_info_struct->line_count - 1;
        p_book_context->convert_line_offset = line_info_struct->array[line_info_struct->line_count - 1].offset;
        
        convert_characters_one_time = line_info_struct->array[line_info_struct->line_count - 1].offset - line_info_struct->array[0].offset;
        *remain_unconverted_characters = *remain_unconverted_characters - convert_characters_one_time;
        if (*remain_unconverted_characters < CHARACTERS_IN_ONE_LINE)
        {
            if(p_book_context->index_continue == MMI_TRUE)
            {
                p_book_context->index_continue = MMI_FALSE;
                error = FS_Seek(p_book_context->convert_line_file_hnd, p_nfo_file->index_file_convert_offset, FS_FILE_BEGIN);
            }
            else
            {
                error = FS_Seek(p_book_context->convert_line_file_hnd, 0, FS_FILE_END);
            }
            if (error < 0)
            {
                goto error_handle;
            }
            error = FS_Write(
                        p_book_context->convert_line_file_hnd, 
                        p_book_context->gui_line_info_struct_buffer, 
                        buffer_index * sizeof(gui_line_info_struct), 
                        NULL);
            if (FS_NO_ERROR != error)
            {
                goto error_handle;
            }
            return MMI_TRUE;
        }
        count++;
    }
    
    if(p_book_context->index_continue == MMI_TRUE)
    {
        p_book_context->index_continue = MMI_FALSE;
        error = FS_Seek(p_book_context->convert_line_file_hnd, p_nfo_file->index_file_convert_offset, FS_FILE_BEGIN);
    }
    else
    {
        error = FS_Seek(p_book_context->convert_line_file_hnd, 0, FS_FILE_END);
    }

    if (error < 0)
    {
        goto error_handle;
    }
    error = FS_Write(
                p_book_context->convert_line_file_hnd, 
                p_book_context->gui_line_info_struct_buffer, 
                buffer_index * sizeof(gui_line_info_struct), 
                NULL);
    if (FS_NO_ERROR != error)
    {
        goto error_handle;
    }
    return MMI_TRUE;
    
error_handle:
    if (NULL != p_fs_error)
    {
        *p_fs_error = error;
    }
    if (p_book_context->convert_line_file_hnd >= 0)
    {
        FS_Close(p_book_context->convert_line_file_hnd);
    }
    p_book_context->convert_line_file_hnd = (FS_HANDLE)-1;
        
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_init_line_info_cache
 * DESCRIPTION
 *  Init line info cache
 * PARAMETERS
 *  ebook_name        [IN]  the name of the Ebook
 *  start_line        [IN]  the start line of the Ebook
 *  start_line_offset [OUT] the offset of the start line in word (2 bytes)
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_ebr_frm_init_line_info_cache(S32 book_id, S32 start_line, S32 *start_line_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE line_file_hnd = -1;
    U32 actual_read_line_num = 0;
    S32 fs_error = -1;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    gui_line_info_struct *p_line_info_cache = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(start_line >= 0);
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;
    p_line_info_cache = p_book_context->line_info_cache;
    
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_INIT_LINE_INFO_CACHE_LOG1, start_line, p_book_context->total_line_num);
    line_file_hnd = p_book_context->convert_line_file_hnd;
    if (line_file_hnd < 0)
    {
        FS_Close(line_file_hnd);
        return MMI_FALSE;
    }

    memset(p_line_info_cache, 0x00, LINE_INFO_CACHE_LENGTH * sizeof(gui_line_info_struct));
    
    if (p_book_context->total_line_num <= LINE_INFO_CACHE_LENGTH)
    {
        fs_error = FS_Seek(line_file_hnd, 0, FS_FILE_BEGIN);
        if (fs_error < 0)
        {
            goto error;
        }
        fs_error = FS_Read(line_file_hnd, p_line_info_cache, LINE_INFO_CACHE_LENGTH * sizeof(gui_line_info_struct), &actual_read_line_num);
        if (FS_NO_ERROR != fs_error)
        {
            goto error;
        }
        *start_line_offset = p_line_info_cache[start_line].offset;
    }
    else
    {
        if (start_line < HALF_LINE_INFO_CACHE_LENGTH)
        {
            fs_error = FS_Seek(line_file_hnd, 0, FS_FILE_BEGIN);
            if (fs_error < 0)
            {
                goto error;
            }
            fs_error = FS_Read(line_file_hnd, p_line_info_cache, LINE_INFO_CACHE_LENGTH * sizeof(gui_line_info_struct), &actual_read_line_num);
            if (FS_NO_ERROR != fs_error)
            {
                goto error;
            }
            p_book_context->line_cache_start = 0;
            *start_line_offset = p_line_info_cache[start_line].offset;
        }
        else if (start_line >= (p_book_context->total_line_num - HALF_LINE_INFO_CACHE_LENGTH))
        {
            fs_error = FS_Seek(line_file_hnd, (p_book_context->total_line_num - LINE_INFO_CACHE_LENGTH) * sizeof(gui_line_info_struct), FS_FILE_BEGIN);
            if (fs_error < 0)
            {
                goto error;
            }
            fs_error = FS_Read(line_file_hnd, p_line_info_cache, LINE_INFO_CACHE_LENGTH * sizeof(gui_line_info_struct), &actual_read_line_num);
            if (FS_NO_ERROR != fs_error)
            {
                goto error;
            }
            p_book_context->line_cache_start = p_book_context->total_line_num - LINE_INFO_CACHE_LENGTH;
            *start_line_offset = p_line_info_cache[start_line - p_book_context->total_line_num + LINE_INFO_CACHE_LENGTH].offset;
        }
        else
        {
            fs_error = FS_Seek(line_file_hnd, (start_line - HALF_LINE_INFO_CACHE_LENGTH) * sizeof(gui_line_info_struct), FS_FILE_BEGIN);
            if (fs_error < 0)
            {
                goto error;
            }
            fs_error = FS_Read(line_file_hnd, p_line_info_cache, LINE_INFO_CACHE_LENGTH * sizeof(gui_line_info_struct), &actual_read_line_num);
            if (FS_NO_ERROR != fs_error)
            {
                goto error;
            }
            p_book_context->line_cache_start = start_line - HALF_LINE_INFO_CACHE_LENGTH;
            *start_line_offset = p_line_info_cache[HALF_LINE_INFO_CACHE_LENGTH].offset;
        }
        
        mmi_ebr_frm_set_line_info_catch_id(book_id, p_book_context->line_cache_start);
    }
    return MMI_TRUE;
error:
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_INIT_LINE_INFO_CACHE_LOG2, fs_error);
    FS_Close(line_file_hnd);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_set_line_info_catch_id
 * DESCRIPTION
 *  Set the line_catche_info flag
 * PARAMETERS
 *  cache_start
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebr_frm_set_line_info_catch_id(S32 book_id, S32 cache_start)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_book_context *p_book_context = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_book_context->line_cache_start = cache_start;
    p_book_context->line_cache_end = cache_start + LINE_INFO_CACHE_LENGTH - 1;
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_SET_LINE_INFO_CATCH_ID, p_book_context->line_cache_start, p_book_context->line_cache_end);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_get_data_offset
 * DESCRIPTION
 *  Get the offset from file header to start line, and the data len
 * PARAMETERS
 *  start_line                         [IN]  The start line of the screen
 *  end_line                           [IN]  The end line screen
 *  p_data_offset                      [OUT] The offset from file header in byte
 *  p_data_len                         [OUT] The length between start_line and end_line in word(2 bytes)
 *  p_fs_error                         [OUT] The pointer points the error code if an error occurs
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_ebr_frm_get_data_offset(kal_int64 line_file_handle, kal_int64 temp_file_handle, 
                                     S32 start_line, S32 end_line, S32 *p_data_offset, 
                                     S32 *p_data_len, S32 *p_fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_error = -1;
    U32 line_file_size, temp_file_size, total_line;
    S32 start_line_offset, end_line_offset;
    S32 actual_read_line_num;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fs_error = FS_GetFileSize(line_file_handle, &line_file_size);
    if (fs_error < 0)
    {
        goto error;
    }
    ASSERT(line_file_size % EBOOK_DATA_OFFSET_BYTE_LEN == 0);
    total_line = line_file_size / EBOOK_DATA_OFFSET_BYTE_LEN;
    ASSERT(start_line <= total_line);
    if(end_line > total_line - 1)
    {
        end_line = total_line - 1;
    }
    fs_error = FS_Seek(line_file_handle, start_line * EBOOK_DATA_OFFSET_BYTE_LEN, FS_FILE_BEGIN);
    if (fs_error < 0)
    {
        goto error;
    }
    fs_error = FS_Read(line_file_handle, &start_line_offset, EBOOK_DATA_OFFSET_BYTE_LEN, &actual_read_line_num);
    if (fs_error < 0)
    {
        goto error;
    }
    ASSERT(actual_read_line_num == EBOOK_DATA_OFFSET_BYTE_LEN);

    *p_data_offset = start_line_offset * ENCODING_LENGTH;
       
    if(end_line < total_line - 1)
    {
        fs_error = FS_Seek(line_file_handle, (end_line + 1) * EBOOK_DATA_OFFSET_BYTE_LEN, FS_FILE_BEGIN);
        if (fs_error < 0)
        {
            goto error;
        }
        fs_error = FS_Read(line_file_handle, &end_line_offset, EBOOK_DATA_OFFSET_BYTE_LEN, &actual_read_line_num);
        if (fs_error < 0)
        {
            goto error;
        }
        ASSERT(actual_read_line_num == EBOOK_DATA_OFFSET_BYTE_LEN);
        *p_data_len = end_line_offset - start_line_offset;
    }
    else  // end_line == total_line - 1
    {
        fs_error = FS_GetFileSize(temp_file_handle, &temp_file_size);    
        if (fs_error < 0)
        {
            goto error;
        }
        temp_file_size = temp_file_size / ENCODING_LENGTH;        
        *p_data_len = temp_file_size - start_line_offset;
    }   
    return MMI_TRUE;
    
error:
    if (NULL != p_fs_error)
    {
        *p_fs_error = fs_error;
    }
    return MMI_FALSE;    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_get_data_len
 * DESCRIPTION
 *  Get the offset from file header to start line, and the data len
 * PARAMETERS
 *  start_line                         [IN]  The start line of the screen
 *  end_line                           [IN]  The end line screen
 *  p_total_offset_from_file_header    [OUT] The offset from file header in byte
 *  p_data_len                         [OUT] The length between start_line and end_line in word(2 bytes)
 *  p_fs_error                         [OUT] The pointer points the error code if an error occurs
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_ebr_frm_get_data_len(S32 book_id, S32 start_line, S32 end_line, S32 *p_total_offset_from_file_header, S32 *p_data_len, S32 *p_fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE line_file_handle = -1;
    U32 actual_read_line_num = 0;
    S32 book_size_in_ucs2 = 0;
    S32 fs_error = -1;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    gui_line_info_struct *p_line_info_cache = NULL;
    U32 line_file_size = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;
    p_line_info_cache = p_book_context->line_info_cache;

    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_GET_DATA_LEN_LOG1, start_line, end_line, p_book_context->total_line_num, p_book_context->line_cache_start, p_book_context->line_cache_end);
    line_file_handle = p_book_context->convert_line_file_hnd;
    if (line_file_handle < 0)
    {
        fs_error = line_file_handle;
        goto error;
    }
    if(p_book_context->total_line_num == 0)
	{
	     fs_error = FS_GetFileSize(line_file_handle, &line_file_size);
		 if(fs_error < 0)
		 {
		     goto error;
		 }
		 p_nfo_file->total_line_num = line_file_size / 4;
	     p_book_context->total_line_num = p_nfo_file->total_line_num;
	}
    if (end_line > (p_book_context->total_line_num - 1))
    {
        end_line = p_book_context->total_line_num - 1;
    }
    if (p_book_context->total_line_num <= LINE_INFO_CACHE_LENGTH)
    {
        *p_total_offset_from_file_header = p_line_info_cache[start_line].offset * ENCODING_LENGTH;
        if (end_line <= (p_book_context->total_line_num - 2))
        {
            *p_data_len = p_line_info_cache[end_line + 1].offset- p_line_info_cache[start_line].offset;
        }
        else
        {        
            book_size_in_ucs2 = p_nfo_file->temp_book_size / ENCODING_LENGTH;    
            *p_data_len = book_size_in_ucs2 - p_line_info_cache[start_line].offset;
        }
    }
    else
    {
        if ((start_line < p_book_context->line_cache_start) && ((end_line + 1) > p_book_context->line_cache_end))
        {
            MMI_ASSERT(0);
        }
        else if (start_line < p_book_context->line_cache_start)  //page up
        {
           if ((start_line - HALF_LINE_INFO_CACHE_LENGTH) >= 0)
           {
                fs_error = FS_Seek(line_file_handle, (start_line - HALF_LINE_INFO_CACHE_LENGTH) * sizeof(gui_line_info_struct), FS_FILE_BEGIN);
                if (fs_error < 0)
                {
                    goto error;
                }
                fs_error = FS_Read(line_file_handle, p_line_info_cache, LINE_INFO_CACHE_LENGTH * sizeof(gui_line_info_struct), &actual_read_line_num);
                if (FS_NO_ERROR != fs_error)
                {
                    goto error;
                }
                mmi_ebr_frm_set_line_info_catch_id(book_id, start_line - HALF_LINE_INFO_CACHE_LENGTH);
           }
           else
           {
                fs_error = FS_Seek(line_file_handle, 0, FS_FILE_BEGIN);
                if (fs_error < 0)
                {
                    goto error;
                }
                fs_error = FS_Read(line_file_handle, p_line_info_cache, LINE_INFO_CACHE_LENGTH * sizeof(gui_line_info_struct), &actual_read_line_num);
                if (FS_NO_ERROR != fs_error)
                {
                    goto error;
                }
                mmi_ebr_frm_set_line_info_catch_id(book_id, 0);
           }
        }
        else if ((end_line + 1) > p_book_context->line_cache_end) // page down
        {
            if ((end_line + HALF_LINE_INFO_CACHE_LENGTH) <= (p_book_context->total_line_num - 1))
            {
                fs_error = FS_Seek(line_file_handle, (end_line + 1 - HALF_LINE_INFO_CACHE_LENGTH) * sizeof(gui_line_info_struct), FS_FILE_BEGIN);
                if (fs_error < 0)
                {
                    goto error;
                }
                fs_error = FS_Read(line_file_handle, p_line_info_cache, LINE_INFO_CACHE_LENGTH * sizeof(gui_line_info_struct), &actual_read_line_num);
                if (FS_NO_ERROR != fs_error)
                {
                    goto error;
                }
                mmi_ebr_frm_set_line_info_catch_id(book_id, end_line + 1 - HALF_LINE_INFO_CACHE_LENGTH);
            }
            else
            {
                fs_error = FS_Seek(line_file_handle, (p_book_context->total_line_num - LINE_INFO_CACHE_LENGTH) * sizeof(gui_line_info_struct), FS_FILE_BEGIN);
                if (fs_error < 0)
                {
                    goto error;
                }
                fs_error = FS_Read(line_file_handle, p_line_info_cache, LINE_INFO_CACHE_LENGTH * sizeof(gui_line_info_struct), &actual_read_line_num);
                if (FS_NO_ERROR != fs_error)
                {
                    goto error;
                }
                mmi_ebr_frm_set_line_info_catch_id(book_id, p_book_context->total_line_num - LINE_INFO_CACHE_LENGTH);
            }
        }
        *p_total_offset_from_file_header = (p_line_info_cache[start_line - p_book_context->line_cache_start].offset) * ENCODING_LENGTH;
        if (end_line <= (p_book_context->total_line_num - 2))
        {
            *p_data_len = p_line_info_cache[end_line + 1 - p_book_context->line_cache_start].offset - p_line_info_cache[start_line - p_book_context->line_cache_start].offset; 
        }
        else
        {        
            book_size_in_ucs2 = p_nfo_file->temp_book_size / 2;
            *p_data_len = book_size_in_ucs2 - p_line_info_cache[start_line - p_book_context->line_cache_start].offset;
        }        
    }
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_GET_DATA_LEN_LOG2, *p_total_offset_from_file_header, *p_data_len);
    return MMI_TRUE;
error:
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_GET_DATA_LEN_LOG3, fs_error);
    if (line_file_handle >= 0)
    {
        FS_Close(line_file_handle);
    }
    if (NULL != p_fs_error)
    {
        *p_fs_error = fs_error;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_get_data_context
 * DESCRIPTION
 *  Get the data context from total_offset_from_file_head
 * PARAMETERS
 *  buffer                         [OUT]  This pointer points the start memory of the data context
 *  total_offset_from_file_head    [IN]   The offset from file head in byte
 *  p_data_len                     [IN]   The length of the data in word(2 bytes)
 *  p_fs_error                         [OUT] The pointer points the error code if an error occurs
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_ebr_frm_get_data_context(S32 book_id, U8 **buffer, S32 total_offset_from_file_head, S32 p_data_len, S32 *p_fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 record_size_in_buffer = EBOOK_SRC_BUFFER_SIZE;
    S32 page_size_in_buffer = record_size_in_buffer / 2;
    S32 num_records = 0;
    FS_HANDLE temp_file_handle = -1;
    S32 current_record_id = 0;
    S32 current_page_id = 0;
    S32 current_record_offset = 0;
    S32 page_num_in_one_record = record_size_in_buffer / page_size_in_buffer;
    UINT actual_read_num = 0;
    S32 book_size_in_ucs2 = 0;

    int fs_error = -1;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    U8 *p_dest_buffer = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    MMI_ASSERT(p_data_len <= (record_size_in_buffer / 2 + record_size_in_buffer / 4));
    if(p_data_len > (record_size_in_buffer / 2 + record_size_in_buffer / 4))
    {
		p_data_len = (record_size_in_buffer / 2 + record_size_in_buffer / 4);
    }
	
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;
    p_dest_buffer = p_book_context->dest_buffer;
    temp_file_handle = p_book_context->convert_temp_file_hnd; 
 
    book_size_in_ucs2 = p_nfo_file->temp_book_size;

    if (temp_file_handle < 0)
    {
        fs_error = temp_file_handle;
        goto error;
    }

    if (book_size_in_ucs2 % record_size_in_buffer)
    {
        num_records = book_size_in_ucs2 / record_size_in_buffer + 1;
    }
    else
    {
        num_records = book_size_in_ucs2 / record_size_in_buffer;
    }
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_GET_DATA_CONTEXT_LOG1, book_size_in_ucs2, record_size_in_buffer, num_records);
    
    if (num_records <= 2)
    {
        *buffer = &p_dest_buffer[total_offset_from_file_head];
        return MMI_TRUE;
    }
    
    current_record_id = total_offset_from_file_head / record_size_in_buffer;
    current_record_offset = total_offset_from_file_head % record_size_in_buffer;
    current_page_id = total_offset_from_file_head / page_size_in_buffer;
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_GET_DATA_CONTEXT_LOG2, p_book_context->first_record_id, current_record_id, current_record_offset, current_page_id);
    
    if (current_record_id == p_book_context->first_record_id)
    {
        /* the first page in the first record */
        if (current_page_id == (current_record_id * page_num_in_one_record))
        {
            if (0 == current_record_id)
            {
                *buffer = &p_dest_buffer[current_record_offset];
            }
            else
            {
                if ((current_record_offset + p_data_len * ENCODING_LENGTH) < record_size_in_buffer)
                {
                    memcpy(&p_dest_buffer[record_size_in_buffer], p_dest_buffer, record_size_in_buffer);
                    fs_error = FS_Seek(temp_file_handle, (current_record_id - 1) * record_size_in_buffer, FS_FILE_BEGIN);
                    if (fs_error < 0)
                    {
                        goto error;
                    }
                    fs_error = FS_Read(temp_file_handle, p_dest_buffer, record_size_in_buffer, &actual_read_num);
                    if (FS_NO_ERROR != fs_error)
                    {
                        goto error;
                    }
                    *buffer = &p_dest_buffer[record_size_in_buffer + current_record_offset];
                    p_book_context->first_record_id = current_record_id - 1;
                }
                else
                {
                    *buffer = &p_dest_buffer[current_record_offset];
                }
            }
        }
        /* the second page in the first record */
        else
        {
            if ((current_record_offset + p_data_len * ENCODING_LENGTH) >= record_size_in_buffer * 2)
            {
                memset(p_dest_buffer, 0x00, sizeof(p_book_context->dest_buffer));
                fs_error = FS_Seek(temp_file_handle, total_offset_from_file_head, FS_FILE_BEGIN);
                if (fs_error < 0)
                {
                    goto error;
                }
                fs_error = FS_Read(temp_file_handle, p_dest_buffer, p_data_len * ENCODING_LENGTH, &actual_read_num);
                if (FS_NO_ERROR != fs_error)
                {
                    goto error;
                }
                *buffer = p_dest_buffer;
                p_book_context->first_record_id = -1;
            }
            else
            {
                *buffer = &p_dest_buffer[current_record_offset];
            }
        }
    }
    else if (current_record_id == (p_book_context->first_record_id + 1))
    {        
        /* the second record is the last record */
        if ((num_records - 1) == current_record_id)
        {
            *buffer = &p_dest_buffer[record_size_in_buffer + current_record_offset];
        }
        else
        {
            /* the first page in the second record */
            if (current_page_id == ((p_book_context->first_record_id + 1) * page_num_in_one_record))
            {
                if ((current_record_offset + p_data_len * 2) >= record_size_in_buffer)
                {
                    memcpy(p_dest_buffer, &p_dest_buffer[record_size_in_buffer], record_size_in_buffer);
                    fs_error = FS_Seek(temp_file_handle, (current_record_id + 1) * record_size_in_buffer, FS_FILE_BEGIN);
                    if (fs_error < 0)
                    {
                        goto error;
                    }
                    fs_error = FS_Read(temp_file_handle, &p_dest_buffer[record_size_in_buffer], record_size_in_buffer, &actual_read_num);
                    if (FS_NO_ERROR != fs_error)
                    {
                        goto error;
                    }
                    *buffer = &p_dest_buffer[current_record_offset];
                    p_book_context->first_record_id = current_record_id;
                }
                else
                {
                    *buffer = &p_dest_buffer[record_size_in_buffer + current_record_offset];
                }
            }
            /* the second page in the second record */
            else
            {
                if ((current_record_offset + p_data_len * ENCODING_LENGTH) >= record_size_in_buffer * 2)
                {
                    memset(p_dest_buffer, 0x00, sizeof(p_book_context->dest_buffer));
                    fs_error = FS_Seek(temp_file_handle, total_offset_from_file_head, FS_FILE_BEGIN);
                    if (fs_error < 0)
                    {
                        goto error;
                    }
                    fs_error = FS_Read(temp_file_handle, p_dest_buffer, p_data_len * ENCODING_LENGTH, &actual_read_num);
                    if (FS_NO_ERROR != fs_error)
                    {
                        goto error;
                    }
                    *buffer = p_dest_buffer;
                    p_book_context->first_record_id = -1;
                }
                else
                {
                    memcpy(p_dest_buffer, &p_dest_buffer[record_size_in_buffer], record_size_in_buffer);
                    fs_error = FS_Seek(temp_file_handle, (current_record_id + 1) * record_size_in_buffer, FS_FILE_BEGIN);
                    if (fs_error < 0)
                    {
                        goto error;
                    }
                    fs_error = FS_Read(temp_file_handle, &p_dest_buffer[record_size_in_buffer], record_size_in_buffer, &actual_read_num);
                    if (FS_NO_ERROR != fs_error)
                    {
                        goto error;
                    }
                    *buffer = &p_dest_buffer[current_record_offset];
                    p_book_context->first_record_id = current_record_id;
                }
            }
        }
    }
    else
    {
        if ((current_record_id == (num_records - 1)) || (current_record_id == (num_records - 2)))
        {
            memset(p_dest_buffer, 0x00, sizeof(p_book_context->dest_buffer));
            fs_error = FS_Seek(temp_file_handle, (num_records - 2) * record_size_in_buffer, FS_FILE_BEGIN);
            if (fs_error < 0)
            {
                goto error;
            }
            fs_error = FS_Read(temp_file_handle, p_dest_buffer, record_size_in_buffer * 2, &actual_read_num);
            if (FS_NO_ERROR != fs_error)
            {
                goto error;
            }
            *buffer = &p_dest_buffer[(current_record_id + 2 - num_records) * record_size_in_buffer + current_record_offset];
            p_book_context->first_record_id = num_records - 2;
        }
        else
        {
            if ((current_record_offset + p_data_len * ENCODING_LENGTH) >= record_size_in_buffer * 2)
            {
                memset(p_dest_buffer, 0x00, sizeof(p_book_context->dest_buffer));
                fs_error = FS_Seek(temp_file_handle, total_offset_from_file_head, FS_FILE_BEGIN);
                if (fs_error < 0)
                {
                    goto error;
                }
                fs_error = FS_Read(temp_file_handle, p_dest_buffer, p_data_len * ENCODING_LENGTH, &actual_read_num);
                if (FS_NO_ERROR != fs_error)
                {
                    goto error;
                }
                *buffer = p_dest_buffer;
                p_book_context->first_record_id = -1;
            }
            else
            {               
                memset(p_dest_buffer, 0x00, sizeof(p_book_context->dest_buffer));
                fs_error = FS_Seek(temp_file_handle, current_record_id * record_size_in_buffer, FS_FILE_BEGIN);
                if (fs_error < 0)
                {
                    goto error;
                }
                fs_error = FS_Read(temp_file_handle, p_dest_buffer, record_size_in_buffer * 2, &actual_read_num);
                if (FS_NO_ERROR != fs_error)
                {
                    goto error;
                }
                *buffer = &p_dest_buffer[current_record_offset];
                p_book_context->first_record_id = current_record_id;
            }
        }
    }
    return MMI_TRUE;
error:
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_GET_DATA_CONTEXT_LOG3, fs_error);
    if (temp_file_handle >= 0)
    {
        FS_Close(temp_file_handle);
    }
    if (NULL != p_fs_error)
    {
        *p_fs_error = fs_error;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_get_searched_string_start_line
 * DESCRIPTION
 *  Get the start line of the searched string
 * PARAMETERS
 *  book_id            [IN]  The identifier of the book
 *  total_offset       [IN]  The offset from file header to searched string(in word)
 *  search_string_len  [IN]  The length of the searched string
 *  start_line         [OUT] The pointer points to the start line of the searched string
 *  start_line_offset  [OUT] The pointer points to the offset from start line to the searched string
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_ebr_frm_get_searched_string_start_line(S32 book_id, S32 total_offset, S32 search_string_len, S32 *start_line, S32 *start_line_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE line_file_handle = -1;
    
    S32 current_cache_start_line = 0;
    gui_line_info_struct current_cache_start_line_offset;
    S32 current_cache_end_line = 0;
    gui_line_info_struct current_cache_end_line_offset;

    S32 fs_error = -1;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    gui_line_info_struct *p_line_info_cache = NULL;
    gui_line_struct *p_gui_line_struct = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_gui_line_struct = wgui_inputs_ml_get_visible_info();
    p_nfo_file = &p_book_context->nfo_book_struct;
    p_line_info_cache = p_book_context->line_info_cache;

    if (p_book_context->total_line_num <= LINE_INFO_CACHE_LENGTH)
    {
        mmi_ebr_frm_bm_get_searched_string_offset(book_id, 0, (p_book_context->total_line_num - 1), total_offset, start_line, start_line_offset);
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_GET_SEARCHED_STRING_START_LINE_LOG2, p_book_context->line_cache_start, p_line_info_cache[0].offset, p_line_info_cache[LINE_INFO_CACHE_LENGTH - 1].offset);
        if (total_offset < p_line_info_cache[0].offset)
        {
			line_file_handle = p_book_context->convert_line_file_hnd;
            if (line_file_handle < 0)
            {
                goto error;
            }
            
            current_cache_start_line = p_book_context->line_cache_start;
            current_cache_start_line_offset = p_line_info_cache[0];
            
            while(total_offset < current_cache_start_line_offset.offset)
            {
                if ((current_cache_start_line - LINE_INFO_CACHE_LENGTH) >= 0)
                {
                    current_cache_start_line = current_cache_start_line - LINE_INFO_CACHE_LENGTH;
                    
                    fs_error = FS_Seek(line_file_handle, current_cache_start_line * sizeof(gui_line_info_struct), FS_FILE_BEGIN);
                    if (fs_error < 0)
                    {
                        goto error;
                    }
                    
                    fs_error = FS_Read(line_file_handle, &current_cache_start_line_offset, sizeof(gui_line_info_struct), NULL);
                    if (FS_NO_ERROR != fs_error)
                    {
                        goto error;
                    }

                    if (total_offset > current_cache_start_line_offset.offset)
                    {
                        fs_error = FS_Seek(line_file_handle, current_cache_start_line * sizeof(gui_line_info_struct), FS_FILE_BEGIN);
                        if (fs_error < 0)
                        {
                            goto error;
                        }
                        
                        fs_error = FS_Read(line_file_handle, p_line_info_cache, LINE_INFO_CACHE_LENGTH * sizeof(gui_line_info_struct), NULL);
                        if (FS_NO_ERROR != fs_error)
                        {
                            goto error;
                        }
                        
                        mmi_ebr_frm_set_line_info_catch_id(book_id, current_cache_start_line);
                        break;
                    }
                }
                else
                {
                    fs_error = FS_Seek(line_file_handle, 0, FS_FILE_BEGIN);
                    if (fs_error < 0)
                    {
                        goto error;
                    }
                    fs_error = FS_Read(line_file_handle, p_line_info_cache, LINE_INFO_CACHE_LENGTH * sizeof(gui_line_info_struct), NULL);
                    if (FS_NO_ERROR != fs_error)
                    {
                        goto error;
                    }
                    mmi_ebr_frm_set_line_info_catch_id(book_id, 0);
                    break;
                }
            }
        }
        else if ((total_offset >= p_line_info_cache[0].offset) && (total_offset < p_line_info_cache[LINE_INFO_CACHE_LENGTH - 1].offset))
        {
        }
        else
        {
			line_file_handle = p_book_context->convert_line_file_hnd;
            if (line_file_handle < 0)
            {                        
                goto error;
            }

            current_cache_end_line = p_book_context->line_cache_end;
            current_cache_end_line_offset = p_line_info_cache[LINE_INFO_CACHE_LENGTH - 1];

            while (total_offset >= current_cache_end_line_offset.offset)
            {
                if ((current_cache_end_line + LINE_INFO_CACHE_LENGTH - 1) >= (p_book_context->total_line_num - 1))
                {
                    fs_error = FS_Seek(line_file_handle, (0 - LINE_INFO_CACHE_LENGTH) * (S32)sizeof(gui_line_info_struct), SEEK_END);
                    if (fs_error < 0)
                    {
                        goto error;
                    }
                    
                    fs_error = FS_Read(line_file_handle, p_line_info_cache, LINE_INFO_CACHE_LENGTH * sizeof(gui_line_info_struct), NULL);
                    if (FS_NO_ERROR != fs_error)
                    {
                        goto error;
                    }
                    mmi_ebr_frm_set_line_info_catch_id(book_id, p_book_context->total_line_num - LINE_INFO_CACHE_LENGTH);
                    break;
                    
                }
                else
                {
                    current_cache_end_line = current_cache_end_line + LINE_INFO_CACHE_LENGTH - 1;
                    fs_error = FS_Seek(line_file_handle, (current_cache_end_line * sizeof(gui_line_info_struct)), FS_FILE_BEGIN);
                    if (fs_error < 0)
                    {
                        goto error;
                    }
                    fs_error = FS_Read(line_file_handle, &current_cache_end_line_offset, sizeof(gui_line_info_struct), NULL);
                    if (FS_NO_ERROR != fs_error)
                    {
                        goto error;
                    }
                    if (total_offset < current_cache_end_line_offset.offset)
                    {
                        fs_error = FS_Seek(line_file_handle, (current_cache_end_line - LINE_INFO_CACHE_LENGTH + 1) * sizeof(gui_line_info_struct), FS_FILE_BEGIN);
                        if (fs_error < 0)
                        {
                            goto error;
                        }
                        fs_error = FS_Read(line_file_handle, p_line_info_cache, LINE_INFO_CACHE_LENGTH * sizeof(gui_line_info_struct), NULL);
                        if (FS_NO_ERROR != fs_error)
                        {
                            goto error;
                        }
                        mmi_ebr_frm_set_line_info_catch_id(book_id, current_cache_end_line - LINE_INFO_CACHE_LENGTH + 1);
                        break;
                    }
                }
            }
        }

        mmi_ebr_frm_bm_get_searched_string_offset(book_id, 0, (LINE_INFO_CACHE_LENGTH - 1), total_offset, start_line, start_line_offset);
    }

    return MMI_TRUE;
error:
#ifdef EBOOK_DEBUG_ERROR_ASSERT
    MMI_ASSERT(0);
#endif
    if (line_file_handle >= 0)
    {
        FS_Close(line_file_handle);
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_bm_get_searched_string_offset
 * DESCRIPTION
 *  Use the binary search algo to get the start line and the offset of the searched string
 * PARAMETERS
 *  start_id          [IN]  the start_id of the g_line_info_cache
 *  end_id            [IN]  the end_id of the g_line_info_cache
 *  total_offset      [IN]  the offset from file header to searched string
 *  start_line        [OUT] the pointer points to the start line of the searched string
 *  start_line_offset [OUT] the pointer points to the offset from the start line to the searched string
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebr_frm_bm_get_searched_string_offset(S32 book_id, S32 start_id, S32 end_id, S32 total_offset, S32 *start_line, S32 *start_line_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 low = 0;
    S32 mid = 0;
    S32 high = 0;
    gui_line_info_struct *p_line_info_cache = NULL;
    mmi_ebr_frm_book_context *p_book_context = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    low = start_id;
    high = end_id;
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_line_info_cache = p_book_context->line_info_cache;
    
    if (total_offset >= p_line_info_cache[end_id].offset)
    {
        if (p_book_context->total_line_num <= LINE_INFO_CACHE_LENGTH)
        {
            *start_line = end_id;
        }
        else
        {
            *start_line = p_book_context->line_cache_end;
        }
        *start_line_offset = total_offset - p_line_info_cache[end_id].offset;
        return;
    }
    while(low <= high)
    {
        mid = (low + high) / 2;
        if ((total_offset >= p_line_info_cache[mid].offset) && (total_offset < p_line_info_cache[mid + 1].offset))
        {
            if (p_book_context->total_line_num <= LINE_INFO_CACHE_LENGTH)
            {
                *start_line = mid;
            }
            else
            {
                *start_line = p_book_context->line_cache_start + mid;
            }
            *start_line_offset = total_offset - p_line_info_cache[mid].offset;
            return;
        }
        else if (total_offset < p_line_info_cache[mid].offset)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_reset_line_base_data
 * DESCRIPTION
 *  Reset the line base related data
 * PARAMETERS
 *  para         [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_ebr_frm_reset_line_base_data(S32 book_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_book_context *p_book_context = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);

    p_book_context->convert_line_offset = 0;
    p_book_context->src_file_hnd = (FS_HANDLE)-1;
    p_book_context->convert_temp_file_hnd = (FS_HANDLE)-1;
    p_book_context->convert_line_file_hnd = (FS_HANDLE)-1;
    p_book_context->async_nfo_file_handle = (FS_HANDLE)-1;

    p_book_context->current_converting_status = MMI_FALSE;

    p_book_context->line_cache_start = -1;
    p_book_context->line_cache_end = -1;
    p_book_context->first_record_id = -1;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_malloc_memory
 * DESCRIPTION
 *  The generalized malloc memory function
 * PARAMETERS
 *  size        [IN]  The length of the malloced buffer
 * RETURNS
 *  void
 *****************************************************************************/
void *mmi_ebr_frm_malloc_memory(S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_ebr_frm_memory_malloc_count++;
    ptr = OslMalloc(size);
    memset(ptr, 0, size);
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_MALLOC_MEMORY, g_ebr_frm_memory_malloc_count, ptr, size);
    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_free_memory
 * DESCRIPTION
 *  The generalized free memory function
 * PARAMETERS
 *  void **     [IN]  The pointer points the memory 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebr_frm_free_memory(void **arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != *arg)
    {
        g_ebr_frm_memory_malloc_count--;
        MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_FREE_MEMORY, g_ebr_frm_memory_malloc_count, *arg);
        OslMfree(*arg);
        *arg = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_free_file_handles
 * DESCRIPTION
 *  Free the file handles
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebr_frm_free_file_handles(S32 book_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_book_context *p_book_context = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_FREE_FILE_HANDLES, p_book_context->src_file_hnd, p_book_context->convert_temp_file_hnd, p_book_context->convert_line_file_hnd);
    if (p_book_context->src_file_hnd >= 0)
    {
        FS_Close(p_book_context->src_file_hnd);
        p_book_context->src_file_hnd = (FS_HANDLE)-1;
    }
    if (p_book_context->convert_temp_file_hnd >= 0)
    {
        FS_Close(p_book_context->convert_temp_file_hnd);
        p_book_context->convert_temp_file_hnd = (FS_HANDLE)-1;
    }
    if (p_book_context->convert_line_file_hnd >= 0)
    {
        FS_Close(p_book_context->convert_line_file_hnd);
        p_book_context->convert_line_file_hnd = (FS_HANDLE)-1;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_free_async_file_handles
 * DESCRIPTION
 *  Free the file handles
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebr_frm_free_async_file_handles(S32 book_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_book_context *p_book_context = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
	if(!p_book_context)
	{
		return;
	}
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_FREE_ASYNC_FILE_HANDLES, 
		             p_book_context->src_file_hnd, 
		             p_book_context->convert_temp_file_hnd,
		             p_book_context->convert_line_file_hnd,
		             p_book_context->async_nfo_file_handle);

    // fs_async_open() have not receive callback message
    if(p_book_context->job_id > 0 )
    {
      fs_async_abort(p_book_context->job_id);  
      p_book_context->async_book_open_state = MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_ABORT;
      p_book_context->job_id = -1;
      
    }
    
    if (p_book_context->convert_line_file_hnd >= 0)
    {
        FS_Close(p_book_context->convert_line_file_hnd);
        p_book_context->convert_line_file_hnd = (FS_HANDLE)-1;
    }
    if (p_book_context->async_nfo_file_handle >= 0)
    {
        FS_Close(p_book_context->async_nfo_file_handle);
        p_book_context->async_nfo_file_handle = (FS_HANDLE)-1;
    }
    if (p_book_context->src_file_hnd >= 0)
    {
        FS_Close(p_book_context->src_file_hnd);
        p_book_context->src_file_hnd = (FS_HANDLE)-1;
    }
	if (p_book_context->convert_temp_file_hnd >= 0)
    {
        FS_Close(p_book_context->convert_temp_file_hnd);
        p_book_context->convert_temp_file_hnd = (FS_HANDLE)-1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_delete_line_index_file
 * DESCRIPTION
 *  Delete the line_index file
 * PARAMETERS
 *  book_id      [IN]  The identifier of the book  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebr_frm_delete_line_index_file(S32 book_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_book_context *p_book_context = NULL;
    CHAR *line_file_name = NULL;
    WGUI_FONT_SIZE font_size = FONT_SIZE_SMALL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
	if(!p_book_context)
	{
		return;
	}
    line_file_name = mmi_ebr_frm_malloc_memory(SRV_EBR_MAX_PATH_LEN * ENCODING_LENGTH);
    
    for (font_size = FONT_SIZE_SMALL; font_size <= FONT_SIZE_LARGE; font_size++)
    {
        mmi_ebr_frm_get_line_file_name(
            (CHAR*)p_book_context->book_full_path_name, 
            line_file_name,
            font_size);
              
 //       FS_Delete((const WCHAR*)line_file_name);  
        mmi_ebr_frm_async_delete((const WCHAR*)line_file_name);
    } 
    mmi_ebr_frm_free_memory((void **)&line_file_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_delete_temp_file
 * DESCRIPTION
 *  Delete the line_index file
 * PARAMETERS
 *  book_id      [IN]  The identifier of the book  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebr_frm_delete_temp_file(S32 book_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_book_context *p_book_context = NULL;
    CHAR *temp_file_name = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
	if(!p_book_context)
	{
		return;
	}
    temp_file_name = mmi_ebr_frm_malloc_memory(SRV_EBR_MAX_PATH_LEN * ENCODING_LENGTH);
    
    mmi_ebr_frm_get_temp_file_name(
        (CHAR*)p_book_context->book_full_path_name, 
        temp_file_name);
    
    mmi_ebr_frm_async_delete((const WCHAR*)temp_file_name);
    mmi_ebr_frm_free_memory((void **)&temp_file_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_reset_nfo_line_element
 * DESCRIPTION
 *  Reset the line-based element in .nfo file
 * PARAMETERS
 *  void 
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_ebr_frm_reset_nfo_line_element(S32 book_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
//    S32 i = 0;
    MMI_BOOL retval = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;
    p_nfo_file->total_line_num = 0;
    p_nfo_file->start_line = 0;
    p_nfo_file->end_line = 0;
    p_nfo_file->start_line_offset = 0;
/*    for (i = 0; i < SRV_EBR_MAX_BOOKMARK_NUMBER; i++)
    {
        p_nfo_file->book_marks[i].start_line = 0;
        memset(
            p_nfo_file->book_marks[i].bookmark_name, 
            0x00,
            (SRV_EBR_MAX_BOOKMARK_NAME_SIZE + 1) * ENCODING_LENGTH);
    }*/

    retval = mmi_ebr_frm_async_save_settings_in_nfo_file(
                book_id,
                NULL);

    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_RESET_NFO_LINE_ELEMENT, retval);
    return retval;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_guess_book_charset
 * DESCRIPTION
 *  Guess the charset of the book
 * PARAMETERS
 *  file_hnd      [IN]  the file handle of the book
 *  file_type     [IN]  the file_type of the book
 *  book_charset  [OUT] pointes the charset of the book
 * RETURNS
 *  MMI_BOOL:
 *  MMI_TRUE  : the function is successful, the book_charset is valid
 *  MMI_FALSE : the function is fail, the book_charset is invalid
 *****************************************************************************/
MMI_BOOL mmi_ebr_frm_guess_book_charset(
            S32 book_id,
            FS_HANDLE file_hnd, 
            mmi_ebr_frm_file_type_enum file_type, 
            mmi_chset_enum *book_charset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#define GUESS_DATA_LENGTH 200 /* define the wanted guess data's length */
    S32 fs_error = -1;
    U32 data_len = 0;
    U8 *p_src_buffer = NULL;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_src_buffer = p_book_context->src_buffer;
    
    fs_error = FS_Seek(file_hnd, 0, FS_FILE_BEGIN);
    if (fs_error < 0)
    {
        goto end;
    }

    if (MMI_EBR_FRM_FILE_TYPE_TXT == file_type)
    {
        fs_error = FS_Read(
                        file_hnd, 
                        p_src_buffer, 
                        GUESS_DATA_LENGTH,
                        &data_len);
        if (FS_NO_ERROR != fs_error)
        {
            goto end;
        }
    }
  
    if (data_len > GUESS_DATA_LENGTH)
    {
        data_len = GUESS_DATA_LENGTH;
    }

    *book_charset = mmi_chset_guess(
                        (const char*)p_src_buffer,
                        data_len,
                        0,
                        CHSET_GUESS_ALL);
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_GUESS_BOOK_CHARSET_LOG1, *book_charset);
    return MMI_TRUE;
 end:
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_GUESS_BOOK_CHARSET_LOG2);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_change_imei_value
 * DESCRIPTION
 *  Change the imei value
 * PARAMETERS
 *  imei_value   [IN] the imei value of the phone
 *  count        [IN] the count of imei_Value
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void mmi_ebr_frm_change_imei_value(U8 *imei_value, S32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < count; i++)
    {
        imei_value[i] += 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_search_string_in_record
 * DESCRIPTION
 *  Search the string in the record
 * PARAMETERS
 *  file_hnd      [IN]     the file handle
 *  record_id     [IN]     identify the search begin with which record, if search
 *                         successfully, this variable records the record which has
 *                         the string
 *  record_offset [IN/OUT] identify the search begin with record's offset, if search
 *                         successfully, this variable records the offset in record,
 *                         in word (two bytes)
 *  search_type   [IN]     identify the search type
 *  search_string [IN]     identify the search string
 * RETURNS
 *  mmi_ebr_app_search_result_enum
 *  MMI_EBR_APP_SEARCH_RESULT_INVALID : there is some error in finding the wanted string
 *  MMI_EBR_APP_SEARCH_RESULT_SUCCESS : the wanted string is searched in the buffer
 *  MMI_EBR_APP_SEARCH_RESULT_FAIL    : the wanted string is not searched in the buffer
 *****************************************************************************/
mmi_ebr_app_search_result_enum mmi_ebr_frm_search_string_in_record(
                                S32 book_id,
                                FS_HANDLE file_hnd,
                                S32 record_id,
                                S32 *record_offset,
                                srv_ebr_search_type_enum search_type,
                                CHAR *search_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_error = 0;
    S32 seek_length = 0;
    S32 read_length = 0;
    S32 string_length = 0;
    S32 record_size = 0;
    S32 buffer_offset = -1;
    mmi_ebr_app_search_result_enum search_result = MMI_EBR_APP_SEARCH_RESULT_NOT_COMPLETE;
    U8 *p_src_buffer = NULL;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;
    p_src_buffer = p_book_context->src_buffer;
    
    string_length = mmi_ucs2strlen((const CHAR*)search_string);
    if (record_id < p_book_context->num_records)
    {
        record_size = EBR_RECORD_SIZE_MAX;
    }
    else
    {
        record_size = p_nfo_file->temp_book_size % EBR_RECORD_SIZE_MAX;
        if ((0 == record_size) && (p_book_context->num_records > 1))
        {
            record_size = EBR_RECORD_SIZE_MAX;
        }
    }

    record_id -= 1;

    seek_length = record_id * EBR_RECORD_SIZE_MAX + *record_offset * ENCODING_LENGTH;
    read_length = (record_id + 1) * EBR_RECORD_SIZE_MAX - seek_length;

    fs_error = FS_Seek(file_hnd, seek_length, FS_FILE_BEGIN);
    if (fs_error < 0)
    {
        search_result = MMI_EBR_APP_SEARCH_RESULT_FAIL;
        return search_result;
    }

    memset(p_src_buffer, 0x00, sizeof(p_book_context->src_buffer));

    fs_error = FS_Read(file_hnd, p_src_buffer, read_length, NULL);
    if (FS_NO_ERROR != fs_error)
    {
        search_result = MMI_EBR_APP_SEARCH_RESULT_FAIL;
        return search_result;        
    }
    
    if (SRV_EBR_SEARCH_TYPE_CASE_INSENSITIVE == search_type)
    {
        mmi_ucs2upr((CHAR*)search_string);
        mmi_ucs2upr((CHAR*)p_src_buffer);
    }

    if (MMI_TRUE == mmi_ebr_frm_bm_search(
                        (S16*)p_src_buffer, 
                        (S16*)search_string, 
                        &buffer_offset, 
                        0))
    {
        *record_offset += buffer_offset;
        search_result = MMI_EBR_APP_SEARCH_RESULT_SUCCESS;
    }

    return search_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_search_timeout_handler
 * DESCRIPTION
 *  The search string algorithm
 * PARAMETERS
 *  arg        [IN] the argument for searching string algorithm     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebr_frm_search_timeout_handler(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_search_struct *p_search_struct = NULL;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    FS_HANDLE file_hnd = -1;
    S32 book_id = 0;
    S32 record_id = 0;
    S32 record_offset = 0;
    srv_ebr_search_type_enum search_type = SRV_EBR_SEARCH_TYPE_CASE_SENSITIVE;
    mmi_ebr_app_search_result_enum search_result = MMI_EBR_APP_SEARCH_RESULT_FAIL;
    MMI_BOOL search_complete = MMI_FALSE;
    srv_ebr_book_search_result final_search_result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_search_struct = (mmi_ebr_frm_search_struct *)arg;
    book_id = p_search_struct->book_id;
    file_hnd = p_search_struct->file_hnd;
    record_id = p_search_struct->record_id;
    record_offset = p_search_struct->record_offset;
    search_type = p_search_struct->search_type;

    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;
    do
    {
        search_result = mmi_ebr_frm_search_string_in_record(book_id, file_hnd, record_id, &record_offset, search_type, p_book_context->last_search_string_input);
        if (MMI_EBR_APP_SEARCH_RESULT_FAIL == search_result)
        {
            search_complete = MMI_TRUE;
            break;
        }
        else if (MMI_EBR_APP_SEARCH_RESULT_SUCCESS == search_result)
        {
            S32 search_string_start_line = 0;
            S32 search_string_start_line_offset = 0;

            S32 string_length = 0;
            S32 total_offset = 0;

            S32 fs_error = FS_NO_ERROR;
            
            string_length = mmi_ucs2strlen((const CHAR*)p_book_context->last_search_string_input);
            total_offset = (record_id - 1) * EBR_RECORD_SIZE_MAX / ENCODING_LENGTH + record_offset;
            if (MMI_FALSE == mmi_ebr_frm_get_searched_string_start_line(
                                book_id,
                                total_offset, 
                                string_length,
                                &search_string_start_line,
                                &search_string_start_line_offset))
            {
                search_result = MMI_EBR_APP_SEARCH_RESULT_FAIL;
                search_complete = MMI_TRUE;
                break;
            }

            p_nfo_file->start_line = search_string_start_line;
            p_nfo_file->start_line_offset = search_string_start_line_offset;

            if (MMI_FALSE == mmi_ebr_frm_async_save_settings_in_nfo_file(
                                book_id, 
                                &fs_error))
            {
                if ((FS_WRITE_PROTECTION == fs_error) || (FS_READ_ONLY_ERROR == fs_error))
                {
                    MMI_EBR_SET_SEARCH_STRING_FLAG(p_book_context->search_string_flag, MMI_EBR_HIGHLIGHT_STRING_FLAG);
                }
                else
                {
                    search_result = MMI_EBR_APP_SEARCH_RESULT_FAIL;
                }
            }
            else
            {
                MMI_EBR_SET_SEARCH_STRING_FLAG(p_book_context->search_string_flag, MMI_EBR_HIGHLIGHT_STRING_FLAG);
            }
            search_complete = MMI_TRUE;
            break;
        }
        else
        {
            S32 string_length = 0;
            string_length = mmi_ucs2strlen((const CHAR*)p_book_context->last_search_string_input);
            record_offset = 1 - string_length;
        }

        MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_SEARCH_TIMEOUT_HANDLER, search_result, record_id, record_offset);
        record_id++;
        if (record_id > p_book_context->num_records)
        {
            if(MMI_EBR_CHECK_SEARCH_STRING_FLAG_IS_SET(p_book_context->search_string_flag, MMI_EBR_LAST_RECORD_FLAG))
            {
                search_result = MMI_EBR_APP_SEARCH_RESULT_FAIL;
                search_complete = MMI_TRUE;
                break;
            }
            else
            {
                MMI_EBR_SET_SEARCH_STRING_FLAG(p_book_context->search_string_flag, MMI_EBR_LAST_RECORD_FLAG);

                record_id = 1;
                record_offset = 0;
            }
        }
    }while((mmi_frm_check_wait_to_run() < MMI_STATUS_FEW_WANT_TO_RUN) &&
                       (MMI_STATUS_INPUT_EVENTS_WANT_TO_RUN != mmi_frm_check_wait_to_run()));


    if (MMI_TRUE == search_complete)
    {
        mmi_ebr_frm_free_memory((void **)&p_search_struct);

        MMI_EBR_RESET_SEARCH_STRING_FLAG(p_book_context->search_string_flag, MMI_EBR_LAST_RECORD_FLAG);

        p_book_context->search_arg = NULL;
        if (MMI_EBR_APP_SEARCH_RESULT_SUCCESS == search_result)
        {
            final_search_result.book_id = book_id;
            final_search_result.offset = (record_id - 1) * EBR_RECORD_SIZE_MAX + record_offset;
            final_search_result.search_result = SRV_EBR_OP_RESULT_SUCCESS;
        }
        else
        {
            final_search_result.book_id = book_id;
            final_search_result.offset = 0;
            final_search_result.search_result = SRV_EBR_OP_RESULT_FAILURE;
        }
        p_book_context->search_complete_hdlr(&final_search_result);
    }
    else
    {
        p_search_struct->book_id = book_id;
        p_search_struct->file_hnd = file_hnd;
        p_search_struct->record_id = record_id;
        p_search_struct->record_offset = record_offset;
        StartTimerEx(EBR_SEARCH_BLOCK_TIMER, EBR_FRM_SEARCH_BREAK_TIMER, mmi_ebr_frm_search_timeout_handler, p_search_struct);
    }

    return;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_convert_record_and_line_index
 * DESCRIPTION
 *  Converting book and generating line_index file
 * PARAMETERS
 *  book_id        [IN] The identifier of the book
 *  p_fs_error     [IN] Pointer the variable which stores the error
 * RETURNS
 *  mmi_ebr_frm_op_result_enum
 *****************************************************************************/
mmi_ebr_frm_op_result_enum mmi_ebr_frm_convert_record_and_line_index(S32 book_id, S32 *p_fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_op_result_enum operate_result = MMI_EBR_FRM_OP_RESULT_FAILURE;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    S32 fs_error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    switch (p_book_context->state)
    {        
        case MMI_EBR_FRM_BOOK_STATE_CONVERT_RECORD:
        {
            operate_result = mmi_ebr_frm_convert_record_and_line_index_in_convert_record(book_id, &fs_error);
            break;
        }
        case MMI_EBR_FRM_BOOK_STATE_GENERATE_LINE_INDEX:
        {
            operate_result = mmi_ebr_frm_convert_record_and_line_index_in_generate_line_index(book_id, &fs_error);
            break;
        }
        case MMI_EBR_FRM_BOOK_STATE_LOAD_DATA:
        {
            p_book_context->nfo_book_struct.convert_complete = MMI_TRUE;
            p_book_context->nfo_book_struct.temp_file_exist = MMI_TRUE;
            
            operate_result = mmi_ebr_frm_convert_record_and_line_index_in_load_data(book_id, &fs_error);
            break;
        }
        default:
            break;
    }
    if (MMI_EBR_FRM_OP_RESULT_FAILURE == operate_result)
    {
        if (NULL != p_fs_error)
        {
            *p_fs_error = fs_error;
        }
    }
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_CONVERT_RECORD_AND_LINE_INDEX, p_book_context->state, operate_result);
    return operate_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_convert_record_and_line_index_fsm
 * DESCRIPTION
 *  The fsm of converting book and generating line_index file
 * PARAMETERS
 *  arg        [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ebr_frm_convert_record_and_line_index_fsm(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_op_result_enum operate_result = MMI_EBR_FRM_OP_RESULT_FAILURE;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    S32 fs_error = 0;
    S32 book_id = (S32)arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    StopTimer(EBOOK_RECURSIVE_TIMER);
    operate_result = mmi_ebr_frm_convert_record_and_line_index(book_id, &fs_error);
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_CONVERT_RECORD_AND_LINE_INDEX_FSM, operate_result);
    if (MMI_EBR_FRM_OP_RESULT_FAILURE == operate_result)
    {
        #ifdef EBOOK_DEBUG_ERROR_ASSERT
        MMI_ASSERT(0);
        #else
        srv_ebr_book_open_error_struct open_error;

        open_error.book_id = book_id;
        open_error.fs_error = fs_error;
        p_book_context->open_book_handler(SRV_EBR_OPEN_BOOK_ERROR, &open_error);
        #endif
    }
    else if (MMI_EBR_FRM_OP_RESULT_BLOCKING == operate_result)
    {
        if (SRV_EBR_BOOK_CONVERT_SPEED_SLOW == p_book_context->convert_speed)
        {
            StartTimerEx(EBOOK_RECURSIVE_TIMER, EBOOK_RECURSIVE_LONG_TIMER_DURATION, mmi_ebr_frm_convert_record_and_line_index_fsm, (void*)book_id);
        }
        else
        {
            StartNonAlignTimerEx(EBOOK_RECURSIVE_TIMER, EBOOK_RECURSIVE_SHORT_TIMER_DURATION, mmi_ebr_frm_convert_record_and_line_index_fsm, (void*)book_id);
        }
    }
    else
    {
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_convert_record_and_line_index_in_convert_record
 * DESCRIPTION
 *  Convertt book's record
 * PARAMETERS
 *  book_id        [IN] The identifier of the book 
 *  p_fs_error     [OUT]The error while converting record
 * RETURNS
 *  mmi_ebr_frm_op_result_enum
 *****************************************************************************/
mmi_ebr_frm_op_result_enum mmi_ebr_frm_convert_record_and_line_index_in_convert_record(S32 book_id, S32 *p_fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 fs_error = FS_NO_ERROR;
    S32 strlen_file_name = 0;
    CHAR *p_book_name = NULL;
    FS_HANDLE convert_temp_file_hnd = -1;
    FS_HANDLE src_file_hnd = -1;
    S32 convert_characters_last_time = 0;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;


    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_CONVERT_RECORD_AND_LINE_INDEX_IN_CONVERT_RECORD_LOG1, p_book_context->current_record_id);
    if (1 == p_book_context->current_record_id)
    {
        p_book_name = p_book_context->book_name;
        strlen_file_name = mmi_ucs2strlen((const CHAR*)p_book_name);
        if (!mmi_ucs2icmp((const CHAR*)&p_book_name[strlen_file_name * 2 - 6], (const CHAR*)L"TXT"))
        {
            p_book_context->file_type = MMI_EBR_FRM_FILE_TYPE_TXT;
        }
        
        fs_error = FS_GetFileSize(p_book_context->convert_temp_file_hnd, &p_nfo_file->temp_book_size);
    
        if(p_nfo_file->temp_book_size == 0)
        {
            p_book_context->temp_file_exist = MMI_FALSE;
        }
        else if(p_nfo_file->temp_book_size > 0)
        {
            p_book_context->temp_file_exist = MMI_TRUE;
        }

        p_book_context->convert_line_offset = 0;
        p_nfo_file->temp_file_exist = p_book_context->temp_file_exist;
    }
    
    if (MMI_FALSE == p_nfo_file->temp_file_exist)  // not convert complete last time, continue convert
    {
        fs_error = FS_Seek(
            p_book_context->src_file_hnd,
            p_book_context->current_file_offset,
            FS_FILE_BEGIN);
        if (fs_error < 0)
        {
            goto error;                
        }  

         convert_characters_last_time = p_book_context->total_characters_in_start_buffer - p_book_context->remain_unconverted_characters;
         p_book_context->total_converted_characters += convert_characters_last_time;

         if(p_book_context->continue_convert == MMI_TRUE)
         {
             // new add for continue converting
             p_book_context->convert_line_offset = p_nfo_file->total_converted_characters;
             p_book_context->remain_unconverted_characters = p_nfo_file->remain_unconverted_characters;
             p_book_context->total_converted_characters = p_nfo_file->total_converted_characters;
             p_book_context->over_the_record_border = p_nfo_file->over_the_record_border;
             memcpy(p_book_context->tempArray, p_nfo_file->tempArray, p_book_context->over_the_record_border); 
             
             p_book_context->continue_convert = MMI_FALSE;
         }
         else
         {
             // new add for continue converting
             p_nfo_file->current_record_id = p_book_context->current_record_id; 
             p_nfo_file->source_file_convert_offset = p_book_context->current_file_offset;
             p_nfo_file->over_the_record_border = p_book_context->over_the_record_border;
             memcpy(p_nfo_file->tempArray, p_book_context->tempArray,p_book_context->over_the_record_border); 
             p_nfo_file->remain_unconverted_characters = p_book_context->remain_unconverted_characters;
             p_nfo_file->total_converted_characters = p_book_context->total_converted_characters;
             memcpy(p_nfo_file->left_chars,
                   p_book_context->dest_buffer + (p_book_context->total_characters_in_start_buffer - p_book_context->remain_unconverted_characters) * (ENCODING_LENGTH),
                   p_book_context->remain_unconverted_characters * ENCODING_LENGTH);
             FS_GetFileSize(p_book_context->convert_temp_file_hnd, &p_nfo_file->temp_file_convert_offset);  
             FS_GetFileSize(p_book_context->convert_line_file_hnd, &p_nfo_file->index_file_convert_offset);
			 p_nfo_file->total_line_num = p_book_context->total_line_num;
         }

         fs_error = FS_Seek(p_book_context->convert_temp_file_hnd, 
                           p_nfo_file->temp_file_convert_offset, 
                           FS_FILE_BEGIN);
        if (fs_error < 0)
        {
            goto error;            
        }
        
        fs_error = mmi_ebr_frm_convert_record(
                    book_id,
                    p_book_context->src_file_hnd, 
                    p_book_context->convert_temp_file_hnd,
                    p_book_context->current_record_id,
                    p_book_context->file_type);
        
        if (fs_error < 0)
        {
            goto error;
        }

        p_book_context->remain_unconverted_characters = mmi_ucs2strlen((const CHAR*)p_book_context->dest_buffer);
        p_book_context->total_characters_in_start_buffer = p_book_context->remain_unconverted_characters;

        p_book_context->current_record_id++;
        fs_error = FS_Seek(p_book_context->src_file_hnd, 0, FS_FILE_CURRENT);
        if (fs_error < 0)
        {
            goto error;
        }
        p_book_context->current_file_offset = fs_error;
        
        if (p_book_context->current_record_id > p_book_context->num_records)
        {
            fs_error = FS_GetFileSize(p_book_context->convert_temp_file_hnd, &p_nfo_file->temp_book_size);
            if (FS_NO_ERROR != fs_error)
            {
                goto error;
            }
        }
    }
    else   // convert complete once a time, then change font size, and re-convert index file
    {
        U32 read_length = 0;
        S32 buffer_data_length = 0;
        S32 actual_data_len = 0;
        U32 book_size = 0;
        U8 *p_dest_buffer = NULL;
        
        p_dest_buffer = p_book_context->dest_buffer;
        fs_error = FS_Seek(
                    p_book_context->convert_temp_file_hnd,
                    p_book_context->current_file_offset,
                    FS_FILE_BEGIN);
        if (fs_error < 0)
        {
            goto error;                
        }

        convert_characters_last_time = p_book_context->total_characters_in_start_buffer - p_book_context->remain_unconverted_characters;
        p_book_context->total_converted_characters += convert_characters_last_time;

        if(p_book_context->continue_convert == MMI_TRUE)
        {
            // new add for continue converting
            p_book_context->total_converted_characters = p_nfo_file->total_converted_characters;
            p_book_context->convert_line_offset = p_nfo_file->total_converted_characters;
            p_book_context->remain_unconverted_characters = p_nfo_file->remain_unconverted_characters;
             
            p_book_context->continue_convert = MMI_FALSE;
        }
        else
        {
            p_nfo_file->current_record_id = p_book_context->current_record_id; 
            p_nfo_file->temp_file_convert_offset = p_book_context->current_file_offset;
            p_nfo_file->remain_unconverted_characters = p_book_context->remain_unconverted_characters;
            p_nfo_file->total_converted_characters = p_book_context->total_converted_characters;
			p_nfo_file->total_line_num = p_book_context->total_line_num;
            memcpy(p_nfo_file->left_chars,
               p_book_context->dest_buffer + (p_book_context->total_characters_in_start_buffer - p_book_context->remain_unconverted_characters) * (ENCODING_LENGTH),
               p_book_context->remain_unconverted_characters * ENCODING_LENGTH);
            FS_GetFileSize(p_book_context->convert_line_file_hnd, &p_nfo_file->index_file_convert_offset);
        } 

        if (0 != p_book_context->remain_unconverted_characters)
        {
            memcpy(p_book_context->dest_buffer,
                p_nfo_file->left_chars,
                p_book_context->remain_unconverted_characters * ENCODING_LENGTH);
        }
        
        memset(
            p_dest_buffer + p_book_context->remain_unconverted_characters * (ENCODING_LENGTH), 
            0x00, 
            sizeof(p_book_context->dest_buffer) - p_book_context->remain_unconverted_characters * (ENCODING_LENGTH));

        book_size = p_nfo_file->temp_book_size;
                    
        if ((book_size - p_book_context->current_file_offset) >= (EBR_RECORD_SIZE_MAX * 2))
        {
            fs_error = FS_Read(
                          p_book_context->convert_temp_file_hnd, 
                          p_dest_buffer + p_book_context->remain_unconverted_characters * 2,
                          EBR_RECORD_SIZE_MAX * 2,
                          &read_length);
        }
        else
        {
            fs_error = FS_Read(
                          p_book_context->convert_temp_file_hnd, 
                          p_dest_buffer + p_book_context->remain_unconverted_characters * 2,
                          book_size - p_book_context->current_file_offset,
                          &read_length);
        }

        if (FS_NO_ERROR != fs_error)
        {
            goto error;
        }

        p_book_context->current_record_id += 2;
        fs_error = FS_Seek(p_book_context->convert_temp_file_hnd, 0, FS_FILE_CURRENT);

        if (fs_error < 0)
        {
            goto error;
        }
        else
        {
            p_book_context->current_file_offset = fs_error;
        }
        
        if (read_length % ENCODING_LENGTH)
        {
            actual_data_len = (read_length / ENCODING_LENGTH) + 1;
        }
        else
        {
            actual_data_len = read_length / ENCODING_LENGTH;
        }
        buffer_data_length = mmi_ucs2strlen((const CHAR*)p_dest_buffer);
        if (buffer_data_length != (actual_data_len + p_book_context->remain_unconverted_characters))
        {
            p_book_context->current_record_id = p_book_context->num_records + 1;
        }
        p_book_context->remain_unconverted_characters += actual_data_len;
        p_book_context->total_characters_in_start_buffer = p_book_context->remain_unconverted_characters;        
    }
    p_book_context->state = MMI_EBR_FRM_BOOK_STATE_GENERATE_LINE_INDEX;	
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_CONVERT_RECORD_AND_LINE_INDEX_IN_CONVERT_RECORD_LOG2, convert_characters_last_time, p_book_context->total_converted_characters, p_book_context->remain_unconverted_characters, p_book_context->current_file_offset);
    return MMI_EBR_FRM_OP_RESULT_BLOCKING;
error:
    if (NULL != p_fs_error)
    {
        *p_fs_error = fs_error;
    }
    mmi_ebr_frm_free_file_handles(book_id);
    return MMI_EBR_FRM_OP_RESULT_FAILURE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_convert_record_and_line_index_in_generate_line_index
 * DESCRIPTION
 *  Generate line_index file
 * PARAMETERS
 *  book_id        [IN] The identifier of the book 
 *  p_fs_error     [OUT]The error while generating line_index file
 * RETURNS
 *  mmi_ebr_frm_op_result_enum
 *****************************************************************************/
mmi_ebr_frm_op_result_enum mmi_ebr_frm_convert_record_and_line_index_in_generate_line_index(S32 book_id, S32 *p_fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL op_error = MMI_FALSE;
    MMI_BOOL end_flag = MMI_FALSE;
    S32 fs_error = -1;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    srv_ebr_book_refresh_screen_struct refresh_screen_struct;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;

    p_book_context->current_converting_status = MMI_TRUE;    
    op_error = mmi_ebr_frm_convert_context_into_line(book_id, &p_book_context->remain_unconverted_characters, &end_flag, &fs_error);
    p_book_context->current_converting_status = MMI_FALSE;    

    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_CONVERT_RECORD_AND_LINE_INDEX_IN_GENERATE_LINE_INDEX, op_error, p_book_context->remain_unconverted_characters);
    if (MMI_FALSE == op_error)
    {
        if (NULL != p_fs_error)
        {
            *p_fs_error = fs_error;
        }
        goto end;
    }

    if ((p_book_context->remain_unconverted_characters < CHARACTERS_IN_ONE_LINE) &&
        (p_book_context->current_record_id <= p_book_context->num_records))
    {
        p_book_context->state = MMI_EBR_FRM_BOOK_STATE_CONVERT_RECORD;
    }
    else
    {
        if (MMI_TRUE == end_flag)
        {
            p_book_context->num_records = mmi_ebr_frm_get_number_of_records(p_nfo_file->temp_book_size, EBR_RECORD_SIZE_MAX);

            p_book_context->total_characters_in_start_buffer = 0;
            p_book_context->remain_unconverted_characters = 0;
            p_book_context->total_converted_characters = 0;

            p_nfo_file->total_line_num = p_book_context->total_line_num;
            if (MMI_FALSE == mmi_ebr_frm_async_save_settings_in_nfo_file(
                                book_id, 
                                &fs_error))
            {
                if (NULL != p_fs_error)
                {
                    *p_fs_error = fs_error;
                }
                goto end;
            }
            p_book_context->state = MMI_EBR_FRM_BOOK_STATE_LOAD_DATA;
        }
        else
        {
            p_book_context->state = MMI_EBR_FRM_BOOK_STATE_GENERATE_LINE_INDEX;
        }
    }
    refresh_screen_struct.book_id = book_id;
    refresh_screen_struct.line_number = p_book_context->total_line_num;
    p_book_context->open_book_handler(SRV_EBR_OPEN_BOOK_REFRESH_SCREEN, &refresh_screen_struct);
    return MMI_EBR_FRM_OP_RESULT_BLOCKING;

end:
    mmi_ebr_frm_free_file_handles(book_id);
    return MMI_EBR_FRM_OP_RESULT_FAILURE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_convert_record_and_line_index_in_load_data
 * DESCRIPTION
 *  Load data into the buffer
 * PARAMETERS
 *  book_id        [IN] The identifier of the book 
 *  p_fs_error     [OUT]The error while generating line_index file
 * RETURNS
 *  mmi_ebr_frm_op_result_enum
 *****************************************************************************/
mmi_ebr_frm_op_result_enum mmi_ebr_frm_convert_record_and_line_index_in_load_data(S32 book_id, S32 *p_fs_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 start_line_offset = 0;
    S32 book_size_in_ucs2 = 0;
    
    MMI_BOOL op_error = MMI_FALSE;
    S32 fs_error = -1;
    CHAR *temp_book_name_path = NULL;
    
    S32 num_records = 0;
    S32 record_size_in_buffer = EBOOK_SRC_BUFFER_SIZE;
    S32 page_size_in_buffer = record_size_in_buffer / 2;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    U8 *p_dest_buffer = NULL;
    mmi_ebr_frm_op_result_enum return_value = MMI_EBR_FRM_OP_RESULT_SUCCESS;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);

    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_CONVERT_RECORD_AND_LINE_INDEX_IN_LOAD_DATA_LOG1, p_book_context->first_record_id, p_book_context->load_data_current_record_id, p_book_context->load_data_next_record_id);
    /* the data is in buffer , no need to load the data */
    if ((p_book_context->first_record_id == p_book_context->load_data_current_record_id) && 
        ((p_book_context->first_record_id + 1) == p_book_context->load_data_next_record_id))
    {
        p_book_context->load_data_total_page_num = 0;
        return_value = MMI_EBR_FRM_OP_RESULT_SUCCESS;
        goto end;
    }

    p_nfo_file = &p_book_context->nfo_book_struct;
    p_dest_buffer = p_book_context->dest_buffer;

    book_size_in_ucs2 = p_nfo_file->temp_book_size;

    if (book_size_in_ucs2 % record_size_in_buffer)
    {
        num_records = book_size_in_ucs2 / record_size_in_buffer + 1;
    }
    else
    {
        num_records = book_size_in_ucs2 / record_size_in_buffer;
    }

    if (p_book_context->convert_temp_file_hnd < 0)
    {
        return_value = MMI_EBR_FRM_OP_RESULT_FAILURE;
        goto end;
    }
    op_error = mmi_ebr_frm_init_line_info_cache(book_id, p_nfo_file->start_line, &start_line_offset);
    if (MMI_FALSE == op_error)
    {
        return_value = MMI_EBR_FRM_OP_RESULT_FAILURE;
        goto end;        
    }
    start_line_offset = start_line_offset * ENCODING_LENGTH;  
    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_CONVERT_RECORD_AND_LINE_INDEX_IN_LOAD_DATA_LOG2, book_size_in_ucs2, num_records, start_line_offset);

    memset(p_dest_buffer, 0x00, sizeof(p_book_context->dest_buffer));
    
    if (num_records <= 2)  // small file, <= 8k
    {
        p_book_context->load_data_current_record_id = 0;
        
        fs_error = FS_Seek(p_book_context->convert_temp_file_hnd, 0, FS_FILE_BEGIN);
        if (fs_error < 0)
        {
            return_value = MMI_EBR_FRM_OP_RESULT_FAILURE;
            goto end;
        } 
        fs_error = FS_Read(
                    p_book_context->convert_temp_file_hnd, 
                    p_dest_buffer, 
                    book_size_in_ucs2, 
                    NULL);
        if (fs_error < 0)
        {
            return_value = MMI_EBR_FRM_OP_RESULT_FAILURE;
            goto end;
        }
    }
    else
    {
        /* calculate the first record and next record which will be loaded into buffer*/
        p_book_context->load_data_current_record_id = start_line_offset / record_size_in_buffer;
        p_book_context->load_data_current_page_id = start_line_offset / page_size_in_buffer;
        
        if (0 == p_book_context->load_data_current_record_id)
        {
            p_book_context->load_data_current_record_id = 0;
            p_book_context->load_data_current_page_id = 0;
        }
        else if (num_records == (p_book_context->load_data_current_record_id + 1))
        {
            p_book_context->load_data_current_record_id = p_book_context->load_data_current_record_id - 1;
            p_book_context->load_data_current_page_id = p_book_context->load_data_current_record_id * 2;
        }
        else
        {
            if (p_book_context->load_data_current_page_id & 1)
            {
                p_book_context->load_data_current_page_id--;
            }
            else
            {
                p_book_context->load_data_current_record_id--;
                p_book_context->load_data_current_page_id = p_book_context->load_data_current_record_id * 2;
            }
        }
        p_book_context->load_data_next_record_id = p_book_context->load_data_current_record_id + 1;
        
        fs_error = FS_Seek(
                    p_book_context->convert_temp_file_hnd, 
                    (p_book_context->load_data_current_record_id * record_size_in_buffer), 
                    FS_FILE_BEGIN);
        if (fs_error < 0)
        {
            return_value = MMI_EBR_FRM_OP_RESULT_FAILURE;
            goto end;
        }

        if ((p_book_context->load_data_next_record_id + 1) == num_records)
        {                 
             fs_error = FS_Read(
                         p_book_context->convert_temp_file_hnd, 
                         p_dest_buffer, 
                         book_size_in_ucs2 - p_book_context->load_data_current_record_id * record_size_in_buffer, 
                         NULL);
             if (fs_error < 0)
             {
                return_value = MMI_EBR_FRM_OP_RESULT_FAILURE;
                goto end;
             }
        }
        else
        {                 
             fs_error = FS_Read(
                             p_book_context->convert_temp_file_hnd, 
                             p_dest_buffer, 
                             record_size_in_buffer * 2, 
                             NULL);
             if (fs_error < 0)
             {
                return_value = MMI_EBR_FRM_OP_RESULT_FAILURE;
                goto end;
             }
        }
    }

    p_book_context->first_record_id = p_book_context->load_data_current_record_id;
    
end:
    p_book_context->state = MMI_EBR_FRM_BOOK_STATE_IDLE;
    p_book_context->open_book_handler(SRV_EBR_OPEN_BOOK_COMPLETE, NULL);
    if(return_value == MMI_EBR_FRM_OP_RESULT_FAILURE)
    {
        if (NULL != p_fs_error)
        {
            *p_fs_error = fs_error;
        } 
    }
    return return_value;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_book_is_in_converting_state
 * DESCRIPTION
 *  Check whether the ebook app is in converting state
 * PARAMETERS
 *  void       
 * RETURNS
 *  MMI_BOOL :
 *  MMI_TRUE : it allows to loop
 *  MMI_FALSE: it doesnot allow to loop
 *****************************************************************************/
MMI_BOOL mmi_ebr_frm_book_is_in_converting_state(S32 book_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_book_context *p_book_context = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    return ((MMI_EBR_FRM_BOOK_STATE_LOAD_DATA == p_book_context->state) ||
            (MMI_EBR_FRM_BOOK_STATE_CONVERT_RECORD == p_book_context->state) ||
            (MMI_EBR_FRM_BOOK_STATE_GENERATE_LINE_INDEX == p_book_context->state));
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_check_convert_context_into_line_loop
 * DESCRIPTION
 *  Check the convert context into line loop
 * PARAMETERS
 *  book_id        [IN] The identifier of the book 
 * RETURNS
 *  MMI_BOOL 
 *****************************************************************************/
MMI_BOOL mmi_ebr_frm_check_convert_context_into_line_loop(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_status_enum mmi_queue_status = MMI_STATUS_NONE_WANT_TO_RUN;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_queue_status = mmi_frm_check_wait_to_run();
    
    if((mmi_queue_status < MMI_STATUS_MANY_WANT_TO_RUN) && 
       (MMI_STATUS_INPUT_EVENTS_WANT_TO_RUN != mmi_queue_status))
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
 *  mmi_ebr_frm_op_result_to_srv_result
 * DESCRIPTION
 *  Convert the framework operate result to service operate result
 * PARAMETERS
 *  op_result        [IN] The framework operate result 
 * RETURNS
 *  srv_ebr_op_result_enum 
 *****************************************************************************/
srv_ebr_op_result_enum mmi_ebr_frm_op_result_to_srv_result(mmi_ebr_frm_op_result_enum op_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ebr_op_result_enum srv_result = SRV_EBR_OP_RESULT_SUCCESS;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (op_result)
    {
        case MMI_EBR_FRM_OP_RESULT_SUCCESS:
        {
            srv_result = SRV_EBR_OP_RESULT_SUCCESS;
            break;
        }
        case MMI_EBR_FRM_OP_RESULT_FAILURE:
        {
            srv_result = SRV_EBR_OP_RESULT_FAILURE;
            break;
        }
        case MMI_EBR_FRM_OP_RESULT_BLOCKING:
        {
            srv_result = SRV_EBR_OP_RESULT_BLOCKING;
            break;
        }
        default:
        {
            break;
        }
    }
    return srv_result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ebr_frm_error_to_srv_error
 * DESCRIPTION
 *  Convert the framework operate result to open book result
 * PARAMETERS
 *  op_result        [IN] The framework operate result 
 * RETURNS
 *  srv_ebr_book_open_error_enum 
 *****************************************************************************/
srv_ebr_book_open_error_enum mmi_ebr_frm_error_to_srv_error(mmi_ebr_frm_op_result_enum op_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ebr_book_open_error_enum srv_error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (op_error)
    {
        case MMI_EBR_FRM_OP_RESULT_FILE_TYPE_NOT_SUPPORTED:
        {
            srv_error = SRV_EBR_BOOk_OPEN_ERROR_FIYE_TYPE_NOT_SUPPORTED;
            break;
        }
        case MMI_EBR_FRM_OP_RESULT_FILE_EMPTY:
        {
            srv_error = SRV_EBR_BOOk_OPEN_ERROR_FIYE_EMPTY;
            break;
        }
        case MMI_EBR_FRM_OP_RESULT_MEMORY_NOT_ENOUGH:
        {
            srv_error = SRV_EBR_BOOK_OPEN_ERROR_MEMORY_NOT_ENOUGH;
            break;
        }
        default:
        {
            srv_error = SRV_EBR_BOOK_OPEN_ERROR_GENERAL;
            break;
        }
    }
    return srv_error;
}

/* async new API */
mmi_ebr_frm_op_result_enum mmi_ebr_frm_open_source_file(S32 book_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_file_type_enum file_type;
    CHAR *ext_name = NULL;
    CHAR *fs_async_buffer = NULL;
    mmi_ebr_frm_book_context *p_book_context = NULL;   
	fs_job_id job_id = -1;
    fs_overlapped_struct overlapped;
	mmi_ebr_frm_op_result_enum ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    
    ext_name = (CHAR*)srv_fmgr_path_get_extension_ptr((WCHAR*)p_book_context->book_name);
    if (!mmi_ucs2icmp((const CHAR*)ext_name, (const CHAR*)L"TXT"))
    {
        file_type = MMI_EBR_FRM_FILE_TYPE_TXT;
    }
    else
    {
        ret =  MMI_EBR_FRM_OP_RESULT_FILE_TYPE_NOT_SUPPORTED;
		goto END;
    } 
	/* save the source file type */
	p_book_context->file_type = file_type;

    // async open source file
    fs_async_buffer = mmi_ebr_frm_malloc_memory(FS_ASYNC_WORKING_BUFFER_SIZE);
    overlapped.callback = mmi_ebr_frm_async_open_fsm;
	overlapped.response_flag = FS_RESPONSE_MESSAGE;
	overlapped.param = (void *)book_id;
	overlapped.priority = FS_PRIORITY_DEFAULT;
    overlapped.buf = (void *)fs_async_buffer;
    overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
	job_id = fs_async_open((const WCHAR*)p_book_context->book_full_path_name, FS_READ_ONLY, &overlapped);
    if(job_id < 0)
    {
		 mmi_ebr_frm_free_memory((void **)&fs_async_buffer);
         ret = MMI_EBR_FRM_OP_RESULT_FAILURE;
    }
	else
	{
		 p_book_context->job_id = job_id;
		 ret = MMI_EBR_FRM_OP_RESULT_SUCCESS;
	}
    p_book_context->async_book_open_state = MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_SRC_OPEN;
END:
	MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_ASYNC_OPEN_SOURCE, job_id, ret);
	return ret;
}


mmi_ebr_frm_op_result_enum mmi_ebr_frm_async_open_nfo_file(S32 book_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_op_result_enum ret = MMI_EBR_FRM_OP_RESULT_SUCCESS;
	mmi_ebr_frm_book_context *p_book_context = NULL;
	CHAR *p_nfo_file_name = NULL;
    fs_job_id job_id = -1;
    fs_overlapped_struct overlapped;
    CHAR *fs_async_buffer = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    
    p_nfo_file_name = mmi_ebr_frm_malloc_memory(SRV_EBR_MAX_PATH_LEN * ENCODING_LENGTH);
    mmi_ebr_frm_get_nfo_file_name(p_book_context->book_full_path_name, p_nfo_file_name);            

    fs_async_buffer = mmi_ebr_frm_malloc_memory(FS_ASYNC_WORKING_BUFFER_SIZE);
    overlapped.callback = mmi_ebr_frm_async_open_fsm;
	overlapped.response_flag = FS_RESPONSE_MESSAGE;
    overlapped.param = (void *)p_nfo_file_name;
    overlapped.priority = FS_PRIORITY_DEFAULT;
    overlapped.buf = (void *)fs_async_buffer;
    overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
    job_id = fs_async_open((const WCHAR*)p_nfo_file_name, FS_READ_WRITE, &overlapped);
    if(job_id < 0)
    {
		mmi_ebr_frm_free_memory((void **)&p_nfo_file_name);
		mmi_ebr_frm_free_memory((void **)&fs_async_buffer);
        ret = MMI_EBR_FRM_OP_RESULT_FAILURE;          
    }
    else
    {
        p_book_context->job_id = job_id;
		ret = MMI_EBR_FRM_OP_RESULT_SUCCESS;
    }
END:
	MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_ASYNC_OPEN_NFO, job_id, ret);
    return ret;    
}


mmi_ebr_frm_op_result_enum mmi_ebr_frm_async_open_temp_file(S32 book_id, kal_int32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_op_result_enum ret = MMI_EBR_FRM_OP_RESULT_SUCCESS;
	mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
	CHAR *p_temp_file_name = NULL;
    int fs_error;    
    fs_job_id job_id = -1;
    fs_overlapped_struct overlapped;
    CHAR *fs_async_buffer = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;
    
    // check if have enough memory when creat temp file
    if((flag & FS_CREATE) || (flag & FS_CREATE_ALWAYS))
    {
        FS_DiskInfo disk_info;
        U64 disk_free_space = 0;
        U64 disk_total_space = 0;
        CHAR file_path_in_ascii[5];
        CHAR file_path[10];

        sprintf((char*)file_path_in_ascii, "%c", (*(CHAR*)p_book_context->book_full_path_name));
        strcat((char*)file_path_in_ascii, ":\\");
        mmi_asc_to_ucs2(file_path, file_path_in_ascii);
        fs_error = FS_GetDiskInfo((const WCHAR*)file_path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

        if (fs_error >= 0)
        {
            disk_free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
            disk_total_space = disk_info.TotalClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
            if ((disk_free_space <= p_nfo_file->book_size * 2) || (disk_info.FreeClusters < 2))
            {
                ret = MMI_EBR_FRM_OP_RESULT_MEMORY_NOT_ENOUGH;
                goto END;
            }
        }
        else
        {                
            ret = MMI_EBR_FRM_OP_RESULT_FAILURE;
            goto END;
        }
    }
    
    p_temp_file_name = mmi_ebr_frm_malloc_memory(SRV_EBR_MAX_PATH_LEN * ENCODING_LENGTH);
    mmi_ebr_frm_get_temp_file_name(p_book_context->book_full_path_name, p_temp_file_name);

    fs_async_buffer = mmi_ebr_frm_malloc_memory(FS_ASYNC_WORKING_BUFFER_SIZE);
    overlapped.callback = mmi_ebr_frm_async_open_fsm;
	overlapped.response_flag = FS_RESPONSE_MESSAGE;
    overlapped.param = (void *)p_temp_file_name;
    overlapped.priority = FS_PRIORITY_DEFAULT;
    overlapped.buf = (void *)fs_async_buffer;
    overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
    job_id = fs_async_open((const WCHAR*)p_temp_file_name, flag, &overlapped);
    if(job_id < 0)
    {
		mmi_ebr_frm_free_memory((void **)&p_temp_file_name);
		mmi_ebr_frm_free_memory((void **)&fs_async_buffer);
        ret = MMI_EBR_FRM_OP_RESULT_FAILURE;;            
    }
    else
    {
		ret = MMI_EBR_FRM_OP_RESULT_SUCCESS;
        p_book_context->job_id = job_id;
    }
END:	
	MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_ASYNC_OPEN_TEMP, job_id, ret);
    return ret; 
}


mmi_ebr_frm_op_result_enum mmi_ebr_frm_async_open_index_file(S32 book_id, kal_int32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ebr_frm_op_result_enum ret = MMI_EBR_FRM_OP_RESULT_SUCCESS;
	mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
	CHAR *p_index_file_name = NULL;
        
    fs_job_id job_id = -1;
    fs_overlapped_struct overlapped;
    CHAR *fs_async_buffer = NULL;
    srv_ebr_bookshelf_setting setting;
    S16 error = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;
    p_index_file_name = mmi_ebr_frm_malloc_memory(SRV_EBR_MAX_PATH_LEN * ENCODING_LENGTH);
    
    ReadRecord(NVRAM_EF_EBOOK_SETTINGS_LID, 1, (void*)&setting, NVRAM_EF_EBOOK_SETTING_SIZE, &error);
   
    if(p_nfo_file->font_size != setting.font_size)
    {
        mmi_ebr_frm_delete_line_index_file(0);
    }
    
    p_nfo_file->font_size = setting.font_size;  
    mmi_ebr_frm_get_line_file_name(
        p_book_context->book_full_path_name, 
        p_index_file_name,
        setting.font_size);
    
    fs_async_buffer = mmi_ebr_frm_malloc_memory(FS_ASYNC_WORKING_BUFFER_SIZE);
    overlapped.callback = mmi_ebr_frm_async_open_fsm;
	overlapped.response_flag = FS_RESPONSE_MESSAGE;
    overlapped.param = (void *)p_index_file_name;
    overlapped.priority = FS_PRIORITY_DEFAULT;
    overlapped.buf = (void *)fs_async_buffer;
    overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
    job_id = fs_async_open((const WCHAR*)p_index_file_name, flag, &overlapped);
    if(job_id < 0)
    {
		mmi_ebr_frm_free_memory((void **)&p_index_file_name);
		mmi_ebr_frm_free_memory((void **)&fs_async_buffer);
        ret = MMI_EBR_FRM_OP_RESULT_FAILURE;;            
    }
    else
    {
        p_book_context->job_id = job_id;
		ret = MMI_EBR_FRM_OP_RESULT_SUCCESS;
    }
	MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_ASYNC_OPEN_INDEX, job_id, ret);
    return ret; 
}



MMI_BOOL mmi_ebr_frm_async_check_nfo_vaild(S32 book_id)
{
  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_hnd = -1;
    FS_HANDLE nfo_hnd = -1;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    mmi_ebr_frm_book_context *p_book_context = NULL;
    S32 fs_result = FS_NO_ERROR;
    FS_DOSDateTime last_modify_time;
    U32 nfo_file_size, book_file_size;
    U32 checksum = 0;
    S32 compare_type = 0;
    FS_FileInfo file_info;
    U8 imei_num[EBOOK_IMEI_NUM];
    U32 size = 0;
    MMI_BOOL valid;
    srv_ebr_bookshelf_setting setting;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_ASYNC_CHECK_NFO_VALID_BEGIN);
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;
    file_hnd = p_book_context->src_file_hnd;
    nfo_hnd = p_book_context->async_nfo_file_handle;
    
    /* Get the IMEI number of the phone */  
    srv_imei_get_imei(MMI_SIM1, imei_num, EBOOK_IMEI_NUM);
    mmi_ebr_frm_change_imei_value(imei_num, EBOOK_IMEI_NUM);

    fs_result = FS_Read(nfo_hnd, p_nfo_file, sizeof(*p_nfo_file), &size);
    if (FS_NO_ERROR != fs_result)
    {
        return MMI_FALSE;
    }
    fs_result = FS_GetFileSize(nfo_hnd, &nfo_file_size);
    if (FS_NO_ERROR != fs_result)
    {
        return MMI_FALSE;
    }
    fs_result = FS_GetFileSize(file_hnd, &book_file_size);
    if (FS_NO_ERROR != fs_result)
    {
        return MMI_FALSE;
    }
    fs_result = FS_GetFileInfo(file_hnd,&file_info);
    if (FS_NO_ERROR != fs_result)
    {
        return MMI_FALSE;
    }
    
    last_modify_time = file_info.DirEntry->DateTime;
    compare_type = mmi_ucs2cmp((const CHAR*)p_nfo_file->file_name, (const CHAR*)p_book_context->book_name);        
    checksum = applib_crc_update(EBOOK_CHECK_SUM_ACK, (U8*)p_nfo_file, sizeof(*p_nfo_file) - sizeof(p_nfo_file->final_check));

    ReadRecord(NVRAM_EF_EBOOK_SETTINGS_LID, 1, (void*)&setting, NVRAM_EF_EBOOK_SETTING_SIZE, &error);

    /* check if nfo file valid */
    if (((p_nfo_file->font_size != setting.font_size) && (p_nfo_file->temp_file_exist == MMI_FALSE)) ||
        (compare_type != 0) ||
        (nfo_file_size != sizeof(*p_nfo_file)) ||
        (book_file_size != p_nfo_file->book_size) ||
        (checksum != p_nfo_file->final_check) ||
        (p_nfo_file->current_record_id == 0) ||
 //       (0 != memcmp(imei_num, p_nfo_file->imei_value, EBOOK_IMEI_NUM)) ||
        (!mmi_ebr_frm_compare_book_last_modify_time(&last_modify_time, &p_nfo_file->last_modify_time)))
    {
        valid = MMI_FALSE;
    }
    else
    { 
        valid = MMI_TRUE;
    }
	MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_ASYNC_CHECK_NFO_VALID_END,valid);
    return valid;
}

mmi_ebr_frm_op_result_enum mmi_ebr_frm_async_creat_nfo_file(S32 book_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_hnd = -1;
	mmi_ebr_frm_book_struct *p_nfo_file = NULL;
	mmi_ebr_frm_book_context *p_book_context = NULL;
	S32 fs_result = FS_NO_ERROR;
    FS_FileInfo file_info;
	FS_DOSDateTime last_modify_time;
	U32 book_file_size;
    CHAR *p_nfo_file_name = NULL;	
    U8 imei_num[EBOOK_IMEI_NUM];
	srv_ebr_bookshelf_setting bookshelf_setting;
	mmi_ebr_frm_file_type_enum file_type;
//	mmi_ebr_frm_database_hdr_type file_header;
	U8 *display_name = NULL; 
	U32 strlength = 0;
	mmi_chset_enum charset_value;
	fs_job_id job_id = -1;
    fs_overlapped_struct overlapped;
    CHAR *fs_async_buffer = NULL;
	U32 size = 0;
	U32 offset = 0;
	S16 error = 0;
	MMI_BOOL is_empty = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	p_book_context = mmi_ebr_frm_get_book_context(book_id);
    p_nfo_file = &p_book_context->nfo_book_struct;
	file_hnd = p_book_context->src_file_hnd;
 
    memset(p_nfo_file, 0x00, sizeof(*p_nfo_file));
//	ReadRecord(NVRAM_EF_EBOOK_SETTINGS_LID, 1, (void*)&bookshelf_setting, sizeof(srv_ebr_bookshelf_setting), &error);
    fs_result = FS_GetFileInfo(file_hnd,&file_info);
    if (FS_NO_ERROR != fs_result)
    {
        return MMI_EBR_FRM_OP_RESULT_FAILURE;   
    }
    last_modify_time = file_info.DirEntry->DateTime;
 //   memcpy(&p_nfo_file->settings, &bookshelf_setting, sizeof(srv_ebr_bookshelf_setting));      
    memcpy(&p_nfo_file->last_modify_time, &last_modify_time, sizeof(FS_DOSDateTime));

	file_type = p_book_context->file_type;
    if (MMI_EBR_FRM_FILE_TYPE_TXT == file_type)
    {
        fs_result = FS_GetFileSize(file_hnd, &p_nfo_file->book_size);
        if (FS_NO_ERROR != fs_result)
        {
            return MMI_EBR_FRM_OP_RESULT_FAILURE;
        }
        if (MMI_EBR_FRM_OP_RESULT_SUCCESS != mmi_ebr_frm_is_empty_file(0, file_hnd, MMI_EBR_FRM_FILE_TYPE_TXT, &is_empty))
        {
            return MMI_EBR_FRM_OP_RESULT_FAILURE;
        }
        if (MMI_TRUE == is_empty)
        {
            return MMI_EBR_FRM_OP_RESULT_FILE_EMPTY;
        } 
        mmi_ucs2cpy((CHAR*)p_nfo_file->file_name, p_book_context->book_name);
        strlength = mmi_ucs2strlen((const CHAR*)p_nfo_file->file_name);
    }

    if (MMI_TRUE == mmi_ebr_frm_guess_book_charset(0, file_hnd, file_type, &charset_value))
    {
        p_nfo_file->temp_encoding_file_format = charset_value;
    }
    else
    {
        return MMI_EBR_FRM_OP_RESULT_FAILURE;
    }

    // compute source file records num
    p_book_context->num_records = mmi_ebr_frm_get_number_of_records(p_nfo_file->book_size, EBR_RECORD_SIZE_MAX);
    p_nfo_file->total_records_num = p_book_context->num_records;
    
    /* Get the IMEI number of the phone */    
    srv_imei_get_imei(MMI_SIM1, imei_num, EBOOK_IMEI_NUM);
    mmi_ebr_frm_change_imei_value(imei_num, EBOOK_IMEI_NUM);
    memcpy(p_nfo_file->imei_value, imei_num, EBOOK_IMEI_NUM);

    /* Calculate the whole final_check of nfo file */
    p_nfo_file->final_check = 
        applib_crc_update(EBOOK_CHECK_SUM_ACK, (U8*)p_nfo_file, sizeof(*p_nfo_file) - sizeof(p_nfo_file->final_check));
    
    /* Write the global nfo struct into file */ 
    p_nfo_file_name = mmi_ebr_frm_malloc_memory(SRV_EBR_MAX_PATH_LEN * ENCODING_LENGTH);
    mmi_ebr_frm_get_nfo_file_name(p_book_context->book_full_path_name, p_nfo_file_name);

	// async creat nfo file
	fs_async_buffer = mmi_ebr_frm_malloc_memory(FS_ASYNC_WORKING_BUFFER_SIZE);
	overlapped.callback = mmi_ebr_frm_async_open_fsm;
	overlapped.response_flag = FS_RESPONSE_MESSAGE;
	overlapped.param = (void *)p_nfo_file_name;
	overlapped.priority = FS_PRIORITY_DEFAULT;
    overlapped.buf = (void *)fs_async_buffer;
    overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
	job_id = fs_async_open((const WCHAR*)p_nfo_file_name, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN, &overlapped);
    if(job_id < 0)
    {
		mmi_ebr_frm_free_memory((void **)&p_nfo_file_name);
		mmi_ebr_frm_free_memory((void **)&fs_async_buffer);
        return MMI_EBR_FRM_OP_RESULT_FAILURE;
    }
    else
    {
        p_book_context->job_id = job_id;
    }
    return MMI_EBR_FRM_OP_RESULT_SUCCESS;
}


kal_int32 mmi_ebr_frm_async_open_fsm(fs_job_id async_job_id, kal_int64 result, fs_async_callback_data_struct *data)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S32 book_id = -1;
    mmi_ebr_frm_op_result_enum return_value = MMI_EBR_FRM_OP_RESULT_SUCCESS;
	mmi_ebr_frm_book_context *p_book_context = NULL;
    mmi_ebr_frm_book_struct *p_nfo_file = NULL;
    MMI_BOOL is_valid;
    int fs_result;
    U32 book_file_size;
    mmi_ebr_frm_bookshelf_context *p_bookshelf;
    srv_ebr_bookshelf_setting setting;
    mmi_event_struct evt;  

    U32 line_file_size = 0;
    S32 total_line_num = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(book_id == -1)
	{
		book_id = (S32)data->param;
	}  
	mmi_ebr_frm_free_memory((void **)&data->param);
    mmi_ebr_frm_free_memory((void **)&data); 
	
    p_book_context = mmi_ebr_frm_get_book_context(book_id);
	if(!p_book_context)
	{
        return_value = MMI_EBR_FRM_OP_RESULT_FAILURE;
        goto end;
	}
    p_nfo_file = &p_book_context->nfo_book_struct;
    p_book_context->job_id = -1;

	MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_ASYNC_OPEN_FSM_CALLBACK,p_book_context->async_book_open_state, result);
    switch(p_book_context->async_book_open_state)
    {
        case MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_SRC_OPEN:            
            if (result < 0)
            {
                return_value = MMI_EBR_FRM_OP_RESULT_FAILURE;
                goto end;
            }
        	else
        	{  
        	    fs_result = FS_GetFileSize(result, &book_file_size);
                if (FS_NO_ERROR != fs_result)
                {
                    return_value = MMI_EBR_FRM_OP_RESULT_FAILURE;
                    FS_Close(result);
                    goto end;
                }
                if(book_file_size == 0)
                {
                    return_value = MMI_EBR_FRM_OP_RESULT_FILE_EMPTY;
                    FS_Close(result);
                    goto end;
                }   
                
        	    if(p_book_context->src_file_hnd == -1)
        		{
        		    p_book_context->src_file_hnd = result;
        		}
        		else
        		{
        		    ASSERT(0);
        		}    	
        	}
            return_value = mmi_ebr_frm_async_open_nfo_file(book_id);
            if(return_value != MMI_EBR_FRM_OP_RESULT_SUCCESS)
            {
                goto end;
            }
            p_book_context->async_book_open_state = MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_NFO_OPEN;        
            break;

        case MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_NFO_OPEN:
            if (result < 0)
            {
                return_value = mmi_ebr_frm_async_creat_nfo_file(book_id);
                if(return_value != MMI_EBR_FRM_OP_RESULT_SUCCESS)
                {
                    goto end;
                }
                p_book_context->async_book_open_state = MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_NFO_CREAT;           
                break;
            }
            else
            {
                if(p_book_context->async_nfo_file_handle == -1)
        		{
        		    p_book_context->async_nfo_file_handle = result;
        		}
        		else
        		{
        		    ASSERT(0);
        		}
                is_valid = mmi_ebr_frm_async_check_nfo_vaild(book_id);
                 /* nfo file is invalid, creat new nfo file */
                if(is_valid == MMI_FALSE)
                {                 
                    FS_Close(result);
                    p_book_context->async_nfo_file_handle = -1;
                    return_value = mmi_ebr_frm_async_creat_nfo_file(book_id);
                    if(return_value != MMI_EBR_FRM_OP_RESULT_SUCCESS)
                    {
                        goto end;
                    }
                    p_book_context->async_book_open_state = MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_NFO_CREAT;           
                    break;
                }
                /* nfo file is valid, then open the temp file */
                else
                {               
                    return_value = mmi_ebr_frm_async_open_temp_file(book_id, FS_READ_WRITE);
                    if(return_value != MMI_EBR_FRM_OP_RESULT_SUCCESS)
                    {
                        goto end;
                    }
                    p_book_context->async_book_open_state = MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_TEMP_OPEN;
                }
             }
             break;

         case MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_NFO_CREAT:
            
            if (result >= 0)
            {   
                if (p_book_context->async_nfo_file_handle == -1)
                {
                     p_book_context->async_nfo_file_handle = result;
                }
                else
                {
                    ASSERT(0);
                }
                
                fs_result = FS_Write(result, p_nfo_file, sizeof(*p_nfo_file), NULL);
                if (FS_NO_ERROR == fs_result)
                {
                    // creat temp file if nfo file creat success
                    return_value = mmi_ebr_frm_async_open_temp_file(book_id, FS_CREATE_ALWAYS| FS_ATTR_HIDDEN);
                    if(return_value != MMI_EBR_FRM_OP_RESULT_SUCCESS)
                    {
                        goto end;
                    }
                    p_book_context->async_book_open_state = MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_TEMP_CREAT; 
                    return_value = MMI_EBR_FRM_OP_RESULT_SUCCESS;
                }
                else
                {
                    if (FS_DISK_FULL == fs_result || FS_ROOT_DIR_FULL == fs_result)
                    {
                        return_value = MMI_EBR_FRM_OP_RESULT_MEMORY_NOT_ENOUGH;
                    }
                    else
                    {
                        return_value = MMI_EBR_FRM_OP_RESULT_FAILURE;
                    }
                }
            }
            /* creat nfo file failed */
            else
            {
                if (FS_DISK_FULL == result || FS_ROOT_DIR_FULL == result)
                {
                    return_value = MMI_EBR_FRM_OP_RESULT_MEMORY_NOT_ENOUGH;
                }
                else
                {
                    return_value = MMI_EBR_FRM_OP_RESULT_FAILURE;
                }
            }
            break;

         case MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_TEMP_OPEN:

            if (result >= 0)
            {
                if(p_book_context->convert_temp_file_hnd == -1)
                {
                    p_book_context->convert_temp_file_hnd = result;
                }
                else
                {
                    ASSERT(0);
                }       
                p_book_context->num_records = mmi_ebr_frm_get_number_of_records(p_nfo_file->temp_book_size, EBR_RECORD_SIZE_MAX);
                
                // open index file if open temp file success
                mmi_ebr_frm_async_open_index_file(book_id, FS_READ_WRITE);
                p_book_context->async_book_open_state = MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_INDEX_OPEN;                
            }
            // open temp file failed, creat it
            else
            {
                mmi_ebr_frm_delete_line_index_file(book_id);
                p_book_context->num_records = mmi_ebr_frm_get_number_of_records(p_nfo_file->book_size, EBR_RECORD_SIZE_MAX);
                
                return_value = mmi_ebr_frm_async_open_temp_file(book_id, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN);
                if(return_value != MMI_EBR_FRM_OP_RESULT_SUCCESS)
                {
                    goto end;
                }
                p_book_context->async_book_open_state = MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_TEMP_CREAT;           
             }
             break;

         case MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_TEMP_CREAT:
            
             if (result >= 0)
             {
                 /* save the handle of line index file into struct mmi_ebr_frm_book_context */
                 if(p_book_context->convert_temp_file_hnd == -1)
                 {
                     p_book_context->convert_temp_file_hnd = result;
                 }
                 else
                 {
                     ASSERT(0);
                 }
                 p_book_context->num_records = mmi_ebr_frm_get_number_of_records(p_nfo_file->book_size, EBR_RECORD_SIZE_MAX);
                 mmi_ebr_frm_delete_line_index_file(book_id);

                 return_value = mmi_ebr_frm_async_open_index_file(book_id, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN); 
                 if(return_value != MMI_EBR_FRM_OP_RESULT_SUCCESS)
                 {
                     goto end;
                 }
                 p_book_context->async_book_open_state = MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_INDEX_CREAT;  
             }
             else
             {
                 return_value = MMI_EBR_FRM_OP_RESULT_FAILURE;
                 goto end;
             }
             break;

         case MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_INDEX_OPEN:    
             if (result >= 0)
             {   
                if(p_book_context->convert_line_file_hnd == -1)
                {
                    p_book_context->convert_line_file_hnd = result;
                }
                else
                {
                    ASSERT(0);
                }
                fs_result = FS_GetFileSize(result, &line_file_size);
                if (FS_NO_ERROR != fs_result)
                {
                    FS_Close(result);
                    p_book_context->convert_line_file_hnd = -1;
                    return_value = MMI_EBR_FRM_OP_RESULT_FAILURE;

                }

           //     if(total_line_num == p_nfo_file->total_line_num)    
                {
                    p_book_context->total_line_num = p_nfo_file->total_line_num;
                    p_book_context->load_data_total_page_num = 0;

                    if(p_nfo_file->convert_complete == MMI_FALSE )
                    {  
                        if(p_nfo_file->temp_file_exist == MMI_FALSE)
                        {
                            p_book_context->current_record_id = p_nfo_file->current_record_id;
                            p_book_context->num_records = p_nfo_file->total_records_num;
                            p_book_context->current_file_offset = p_nfo_file->source_file_convert_offset;
                            p_book_context->total_line_num = p_nfo_file->index_file_convert_offset/4;   
                        }
                        else
                        {        
                            p_book_context->current_record_id = p_nfo_file->current_record_id; 
                            p_book_context->current_file_offset = p_nfo_file->temp_file_convert_offset;
                            p_book_context->total_line_num = p_nfo_file->index_file_convert_offset/4;
                        }

                        p_book_context->index_continue = MMI_TRUE;
                        p_book_context->continue_convert = MMI_TRUE;
                        p_book_context->state = MMI_EBR_FRM_BOOK_STATE_CONVERT_RECORD;     
                    }
                    else
                    {
                        p_book_context->state = MMI_EBR_FRM_BOOK_STATE_LOAD_DATA;
                    }
                    
                    MMI_FRM_INIT_EVENT(&evt, EVT_ID_EBOOK_ASYNC_OPEN_SUCCESS_RSP);
                    mmi_frm_cb_emit_event(&evt);

                    // begin load data
       //             mmi_ebr_app_entry_open_book(NULL);
                    goto end;
                } 
            }
            // index file not exist, creat a new one
            else
            {   
                 
                return_value = mmi_ebr_frm_async_open_index_file(book_id, FS_CREATE_ALWAYS | FS_ATTR_HIDDEN); 
                if(return_value != MMI_EBR_FRM_OP_RESULT_SUCCESS)
                {
                    goto end;
                }
                p_book_context->async_book_open_state = MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_INDEX_CREAT;                  
            }         
            break;

         case MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_INDEX_CREAT:
            if (result >= 0)
            {
                if(p_book_context->convert_line_file_hnd == -1)
                {
                    p_book_context->convert_line_file_hnd = result;
                }
                else
                {
                    ASSERT(0);
                }
                fs_result = mmi_ebr_frm_reset_nfo_line_element(book_id);
                if (MMI_FALSE == fs_result)
                {
                    return_value = MMI_EBR_FRM_OP_RESULT_FAILURE;
                    goto end;
                }
                p_book_context->current_record_id = 1;        
                p_book_context->total_line_num = 0;
                p_book_context->load_data_total_page_num = 0;

                p_book_context->state = MMI_EBR_FRM_BOOK_STATE_CONVERT_RECORD; 
				p_nfo_file->convert_complete = MMI_FALSE;

              
                MMI_FRM_INIT_EVENT(&evt, EVT_ID_EBOOK_ASYNC_OPEN_SUCCESS_RSP);
                mmi_frm_cb_emit_event(&evt);
       //         mmi_ebr_app_entry_open_book(NULL);
            }
            else
            {
                return_value = MMI_EBR_FRM_OP_RESULT_FAILURE;
                goto end;
            }
            break;

         case MMI_EBR_FRM_ASYNC_BOOK_OPEN_STATE_ABORT:
       // free the file handle if "ebook reader" exist when fs_async_open() but has not receive the rsp message
            if(result > 0)
            {
                FS_Close(result);
            }
            break;
    }
end:
    if(return_value != MMI_EBR_FRM_OP_RESULT_SUCCESS)
    {
        // TODO: error happen, popup error
        srv_ebr_book_open_error_enum error_value = mmi_ebr_frm_error_to_srv_error(return_value);
		if(p_book_context)
		{
		    MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK,MMI_EBOOK_FRM_ASYNC_OPEN_FSM_ERROR, p_book_context->async_book_open_state, result, return_value);
		}
        mmi_ebr_frm_free_async_file_handles(book_id);
        mmi_ebr_app_async_open_error_handler(error_value);
    }
    return return_value;
}


kal_int32 mmi_ebr_frm_async_delete_file_callback(fs_job_id async_job_id, kal_int64 result, fs_async_callback_data_struct *data)
{
    mmi_ebr_frm_free_memory((void **)&data->param);
    mmi_ebr_frm_free_memory((void **)&data); 
    // delete file failed
    if ((FS_NO_ERROR != result) && (FS_FILE_NOT_FOUND != result))
    {
        MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_ASYNC_DELETE_CALLBACK, async_job_id, result);
        return MMI_EBR_FRM_OP_RESULT_FAILURE;
        //TODO: popup error
    }
	return 0;
}


kal_int32 mmi_ebr_frm_async_delete(const kal_wchar* filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    fs_job_id job_id = -1;
    fs_overlapped_struct overlapped;
    CHAR *fs_async_buffer = NULL;
    U8 asc_file[SRV_FMGR_PATH_MAX_LEN + 1]; 
    WCHAR *temp_filename = NULL;
	mmi_ebr_frm_op_result_enum ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    temp_filename = mmi_ebr_frm_malloc_memory(SRV_EBR_MAX_PATH_LEN * ENCODING_LENGTH);
    mmi_ucs2cpy((CHAR*)temp_filename, (char *)filename);
    
    fs_async_buffer = mmi_ebr_frm_malloc_memory(FS_ASYNC_WORKING_BUFFER_SIZE);
    overlapped.callback = mmi_ebr_frm_async_delete_file_callback;
    overlapped.param = (void *)temp_filename;
    overlapped.priority = FS_PRIORITY_DEFAULT;
    overlapped.buf = (void *)fs_async_buffer;
    overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
    job_id = fs_async_delete((const WCHAR*)temp_filename, &overlapped);
                        
    mmi_ucs2_to_asc((CHAR *)asc_file, (CHAR *)filename);	
	MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_ASYNC_DELETE, asc_file, job_id);
	if(job_id < 0)
    {
		mmi_ebr_frm_free_memory((void **)&temp_filename);
        mmi_ebr_frm_free_memory((void **)&fs_async_buffer); 
        ret = MMI_EBR_FRM_OP_RESULT_FAILURE;           
    }
    else
    {
        ret = MMI_EBR_FRM_OP_RESULT_SUCCESS;
    }
	MMI_TRACE(MMI_COMMON_TRC_G1_EBOOK, MMI_EBOOK_FRM_ASYNC_DELETE,job_id, ret);
	return ret;
}

#endif /* __MMI_EBOOK_READER__ */ 
