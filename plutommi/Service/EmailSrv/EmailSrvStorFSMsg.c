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
 *  EmailSrvStorFSMsg.c
 *
 * Project:
 * --------
 *  MAUI
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
 *----------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "MMI_features.h"

#include "EmailSrvGprot.h"
#include "EmailSrvProt.h"
#include "EmailSrvStorage.h"
#include "EmailSrvStorFS.h"

#include "customer_ps_inc.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "fs_gprot.h"
#include "mmi_inet_app_trc.h"
#include "kal_trace.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "FileMgrSrvGProt.h"

#ifdef EMAIL_STOR_FILE
#undef EMAIL_STOR_FILE
#endif
#define EMAIL_STOR_FILE 'M'

typedef void (*email_stor_fs_msg_edit_part_write_ptr)(email_stor_fs_msg_edit_struct *cnxt);

typedef struct
{
    email_stor_fs_msg_edit_part_write_ptr callback;
    void *userdata;
    S32 job_id;
} email_stor_fs_msg_edit_part_write_copy_struct;

static void email_stor_fs_msg_edit_fsm(
    email_stor_fs_msg_edit_struct *cnxt);

static void email_stor_fs_attch_gen_path(
    EMAIL_ATTCH_ID attch_id, WCHAR *path);

static EMAIL_ATTCH_ID email_stor_fs_attch_path_to_id(
    WCHAR *path);

static srv_email_result_enum email_stor_fs_attch_id_create(
    EMAIL_MSG_ID msg_id,
    EMAIL_ATTCH_ID *attch_id);

static srv_email_result_enum email_stor_fs_attch_id_link_add(
    email_stor_attch_id_link_struct **header,
    EMAIL_ATTCH_ID attch_id);

static srv_email_result_enum email_stor_fs_attch_id_link_del(
    email_stor_attch_id_link_struct **header,
    EMAIL_ATTCH_ID attch_id);

static srv_email_result_enum email_stor_fs_msg_parts_rename(
    EMAIL_ACCT_ID acct_id,
    EMAIL_FLDR_ID fldr_id,
    EMAIL_STOR_OFFSET offset,
    srv_email_stor_file_enum type);


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_flag_mem_set
 * DESCRIPTION
 *  Convert a flag
 *  Example:
 *  mask = 0x01, new_flag = EMAIL_MSG_FLAG_SEEN | EMAIL_MSG_FLAG_ANSWERED = 0x03
 *  mask & new_flag = 0x01
 *  only EMAIL_MSG_FLAG_SEEN(0x01) will be cared
 * PARAMETERS
 *  flag            [OUT]       Flag to be converted
 *  mask            [IN]        Only this mask will be cared
 *  new_flag        [IN]        New flag
 * RETURNS
 *  unread number changed
 *****************************************************************************/
S32 email_stor_fs_flag_mem_set(EMAIL_MSG_FLAG *flag,
                               U8 mask,
                               EMAIL_MSG_FLAG new_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL orig_flag_unseen = MMI_FALSE;
    MMI_BOOL new_flag_unseen = MMI_FALSE;
    S32 unread_num_change = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mask & EMAIL_MSG_FLAG_SEEN)
    {
        if (((*flag) & EMAIL_MSG_FLAG_SEEN) != EMAIL_MSG_FLAG_SEEN)
        {
            orig_flag_unseen = MMI_TRUE;
        }
        if ((new_flag & EMAIL_MSG_FLAG_SEEN) != EMAIL_MSG_FLAG_SEEN)
        {
            new_flag_unseen = MMI_TRUE;
        }

        if (orig_flag_unseen && !new_flag_unseen)
        {
            unread_num_change = -1;
        }
        if (!orig_flag_unseen && new_flag_unseen)
        {
            unread_num_change = 1;
        }
    }
    new_flag &= mask;   /* clear new_flag's NO NEED CARE bit */
    *flag &= (~mask);   /* clear old flag's mask bit */
    *flag |= new_flag;  /* set old flag's mask bit */

    return unread_num_change;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_flag_mem_get
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag        [IN]        
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL email_stor_fs_flag_mem_get(EMAIL_MSG_FLAG flag,
                                    srv_email_stor_set_flag_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case SRV_EMAIL_STOR_SET_FLAG_SEEN:
            if (((flag) & EMAIL_MSG_FLAG_SEEN) == EMAIL_MSG_FLAG_SEEN)
            {
                /* means orig_flag is seen */
                return MMI_TRUE;
            }
            break;

        case SRV_EMAIL_STOR_SET_FLAG_UNSEEN:
            if (((flag) & EMAIL_MSG_FLAG_SEEN) != EMAIL_MSG_FLAG_SEEN)
            {
                /* means orig_flag is seen */
                return MMI_TRUE;
            }
            break;

        case SRV_EMAIL_STOR_SET_FLAG_ANSWERED:
            if (((flag) & EMAIL_MSG_FLAG_ANSWERED) == EMAIL_MSG_FLAG_ANSWERED)
            {
                /* means orig_flag is answered */
                return MMI_TRUE;
            }
            break;

        case SRV_EMAIL_STOR_SET_FLAG_UNANSWERED:
            if (((flag) & EMAIL_MSG_FLAG_ANSWERED) != EMAIL_MSG_FLAG_ANSWERED)
            {
                /* means orig_flag is seen unanswered */
                return MMI_TRUE;
            }
            break;

        case SRV_EMAIL_STOR_SET_FLAG_FLAGGED:
            if (((flag) & EMAIL_MSG_FLAG_FLAGGED) == EMAIL_MSG_FLAG_FLAGGED)
            {
                /* means orig_flag is seen unanswered */
                return MMI_TRUE;
            }
            break;

        case SRV_EMAIL_STOR_SET_FLAG_UNFLAGGED:
            if (((flag) & EMAIL_MSG_FLAG_FLAGGED) != EMAIL_MSG_FLAG_FLAGGED)
            {
                /* means orig_flag is seen unanswered */
                return MMI_TRUE;
            }
            break;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_record_write_by_hd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd              [IN]        
 *  offset          [IN]        
 *  msg             [?]         [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
static srv_email_result_enum email_stor_fs_msg_record_write_by_hd(
                                FS_HANDLE hd,
                                EMAIL_STOR_OFFSET offset,
                                email_stor_fs_msg_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 rw = 0;
    U32 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAIL_FS_SEEK(hd, EMAIL_STOR_MSG_RECORD_POS(offset), FS_FILE_BEGIN);
    ret = FS_Write(hd, msg, sizeof(email_stor_fs_msg_struct), &rw);
    if (ret == FS_NO_ERROR && rw == sizeof(email_stor_fs_msg_struct))
    {
        return SRV_EMAIL_RESULT_SUCC;
    }
    
    EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
    if (rw != 0)
    {
        ret = FS_GetFileSize(hd, &size);
        if (ret >= FS_NO_ERROR)
        {
            if (size > EMAIL_STOR_MSG_RECORD_POS(offset) &&
                size < EMAIL_STOR_MSG_RECORD_POS(offset + 1))
            {   
                /* it's the last offset, so MUST truncate it */
                EMAIL_FS_SEEK(
                    hd, EMAIL_STOR_MSG_RECORD_POS(offset), FS_FILE_BEGIN);
                FS_Truncate(hd);
            }
        }
    }
    return SRV_EMAIL_RESULT_FS_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_id_create
 * DESCRIPTION
 *  Create a MSG id
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  fldr_id     [IN]        Folder id
 *  msg_id      [OUT]       MSG id
 * RETURNS
 *  result code
 *****************************************************************************/
static srv_email_result_enum email_stor_fs_msg_id_create(
                                EMAIL_ACCT_ID acct_id,
                                EMAIL_FLDR_ID fldr_id,
                                EMAIL_MSG_ID *msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    S32 dir_exist;
    srv_email_result_enum result;
    WCHAR *path;
    FS_HANDLE hd;
    MMI_BOOL valid;
    U32 rw;
    EMAIL_STOR_OFFSET offset;
    U32 total_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_fldr_gen_path(acct_id, fldr_id, EMAIL_STOR_FLDR_INDEX, path);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    EMAIL_FS_SEEK(hd, EMAIL_STOR_FLDR_TOTAL_NUM_POS, FS_FILE_BEGIN);
    ret = FS_Read(hd, &total_num, sizeof(U32), &rw);
    if (ret != FS_NO_ERROR || 
        rw != sizeof(U32) || 
        total_num >= EMAIL_STOR_MAX_MSG_NUM_PER_FLDR)
    {
        EMAIL_FS_CLOSE(hd);
        email_stor_path_mfree(path);
        if (ret != FS_NO_ERROR || rw != sizeof(U32))
        {
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        return SRV_EMAIL_RESULT_MSG_REACH_MAX_NUM;
    }

    offset = 0;

    while (MMI_TRUE)
    {
        EMAIL_FS_SEEK(hd, EMAIL_STOR_MSG_RECORD_POS(offset), FS_FILE_BEGIN);
        ret = FS_Read(hd, &valid, sizeof(MMI_BOOL), &rw);
        if (rw != sizeof(MMI_BOOL))
        {
            /* reach the end of INDEX file */
            *msg_id = email_stor_fs_msg_id_gen(acct_id, fldr_id, offset);
            result = SRV_EMAIL_RESULT_SUCC;
            break;
        }

        if (!valid)
        {
            /* this MSG offset is unused */
            *msg_id = email_stor_fs_msg_id_gen(acct_id, fldr_id, offset);
            result = SRV_EMAIL_RESULT_SUCC;
            break;
        }

        /* to check next offset */
        offset++;

        if (offset >= EMAIL_STOR_MAX_MSG_NUM_PER_FLDR)
        {
            /* exceed the maximum number */
            EMAIL_STOR_TRACE_OFST_REACH_MAX(acct_id, fldr_id, offset);
            result = SRV_EMAIL_RESULT_MSG_REACH_MAX_NUM;
            break;
        }
    }

    EMAIL_FS_CLOSE(hd);

    if (result == SRV_EMAIL_RESULT_SUCC)
    {
        if (offset == 0)
        {
            /* parts dir */
            email_stor_fs_fldr_parts_root_gen_path(acct_id, fldr_id, path);
            dir_exist = srv_email_util_dir_exist(path);
            if (dir_exist < 0)
            {
                EMAIL_STOR_TRACE_FS_CREATE_DIR(dir_exist);
                result = SRV_EMAIL_RESULT_FS_ERROR;
                goto STOR_EXIT_HANDLE;
            }
            if (!dir_exist)
            {
                ret = FS_CreateDir(path);
                if (ret != FS_NO_ERROR && ret != FS_FILE_EXISTS)
                {
                    EMAIL_STOR_TRACE_FS_CREATE_DIR(ret);
                    result = SRV_EMAIL_RESULT_FS_ERROR;
                    goto STOR_EXIT_HANDLE;
                }
            }

            /* attach dir */
            email_stor_fs_fldr_attch_root_gen_path(acct_id, fldr_id, path);
            dir_exist = srv_email_util_dir_exist(path);
            if (dir_exist < 0)
            {
                EMAIL_STOR_TRACE_FS_CREATE_DIR(dir_exist);
                result = SRV_EMAIL_RESULT_FS_ERROR;
                goto STOR_EXIT_HANDLE;
            }
            if (!dir_exist)
            {
                ret = FS_CreateDir(path);
                if (ret != FS_NO_ERROR && ret != FS_FILE_EXISTS)
                {
                    EMAIL_STOR_TRACE_FS_CREATE_DIR(ret);
                    result = SRV_EMAIL_RESULT_FS_ERROR;
                    goto STOR_EXIT_HANDLE;
                }
            }
        }
        
        if (offset % EMAIL_STOR_MSG_NUM_PER_PARTS_DIR == 0)
        {
            email_stor_fs_fldr_parts_branch_gen_path(
                acct_id, fldr_id, offset, path);

            ret = FS_CreateDir(path);
            if (ret != FS_NO_ERROR && ret != FS_FILE_EXISTS)
            {
                EMAIL_STOR_TRACE_FS_CREATE_DIR(ret);
                result = SRV_EMAIL_RESULT_FS_ERROR;
                goto STOR_EXIT_HANDLE;
            }
        }

        if (offset % EMAIL_STOR_MSG_NUM_PER_ATTCH_DIR == 0)
        {
            email_stor_fs_fldr_attch_branch_gen_path(
                acct_id, fldr_id, offset, path);

            ret = FS_CreateDir(path);
            if (ret != FS_NO_ERROR && ret != FS_FILE_EXISTS)
            {
                EMAIL_STOR_TRACE_FS_CREATE_DIR(ret);
                result = SRV_EMAIL_RESULT_FS_ERROR;
                goto STOR_EXIT_HANDLE;
            }
        }
    }

STOR_EXIT_HANDLE:
    email_stor_path_mfree(path);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_parts_write
 * DESCRIPTION
 *  Write MSG parts file
 * PARAMETERS
 *  acct_id         [IN]        Account id
 *  fldr_id         [IN]        Folder id
 *  offset          [IN]        Offset
 *  text_type       [IN]        Text type
 *  read_path       [IN]        It's path, NOT buffer!
 *  output_tmp      [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_parts_write(
    EMAIL_ACCT_ID acct_id,
    EMAIL_FLDR_ID fldr_id,
    EMAIL_STOR_OFFSET offset,
    srv_eamil_msg_text_type_enum text_type,
    WCHAR *read_path, MMI_BOOL output_tmp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    WCHAR *write_path;
    srv_email_stor_file_enum file_type = SRV_EMAIL_STOR_FILE_TOTAL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (text_type)
    {
        case SRV_EMAIL_MSG_TEXT_CONT_TEXT:
            file_type = SRV_EMAIL_STOR_FILE_CONT_TEXT;
            break;
        case SRV_EMAIL_MSG_TEXT_CONT_HTML:
            file_type = SRV_EMAIL_STOR_FILE_CONT_HTML;
            break;
        default:
            MMI_ASSERT(0);
            break;
    }

    write_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN);
    if (write_path == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_msg_parts_gen_path(
        acct_id, fldr_id, offset, file_type, write_path);

    if (output_tmp)
    {
        mmi_wcscat(write_path, EMAIL_STOR_MSG_UPDATE_TMP_FILE_SUFFIX);
    }

    ret = FS_Rename(read_path, write_path);
    if (ret == FS_FILE_EXISTS)
    {
        ret = FS_Delete(write_path);
        if (ret != FS_NO_ERROR)
        {
            EMAIL_STOR_TRACE_FS_DEL(ret);
        }
        ret = FS_Rename(read_path, write_path);
    }
    if (ret != FS_NO_ERROR)
    {
        EMAIL_STOR_TRACE_FS_RENAME(ret);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    email_stor_path_mfree(write_path);

    return SRV_EMAIL_RESULT_SUCC;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_parts_write_proc_func
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
mmi_ret email_stor_fs_msg_parts_write_proc_func(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_async_done_event_struct *async_evt = (srv_fmgr_async_done_event_struct*)param;
    email_stor_fs_msg_edit_part_write_copy_struct *copy_cnxt;
    email_stor_fs_msg_edit_struct *cnxt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SRV_FMGR_ASYNC_DONE:
        {
            copy_cnxt = (email_stor_fs_msg_edit_part_write_copy_struct*)
                        async_evt->user_data;
            cnxt = (email_stor_fs_msg_edit_struct*)copy_cnxt->userdata;

            MMI_ASSERT(async_evt->job_id == copy_cnxt->job_id);

            if (async_evt->result == 0)
            {
                cnxt->result = SRV_EMAIL_RESULT_SUCC;
            }
            else
            {
                cnxt->result = SRV_EMAIL_RESULT_FS_ERROR;
            }
            
            copy_cnxt->callback(cnxt);
            email_stor_mfree(copy_cnxt);
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_parts_write_async
 * DESCRIPTION
 *  Write MSG parts file
 * PARAMETERS
 *  acct_id         [IN]        Account id
 *  fldr_id         [IN]        Folder id
 *  offset          [IN]        Offset
 *  text_type       [IN]        Text type
 *  read_path       [IN]        It's path, NOT buffer!
 *  output_tmp      [IN]        
 *  callback        [IN]
 *  userdata        [IN]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_parts_write_async(
    EMAIL_ACCT_ID acct_id,
    EMAIL_FLDR_ID fldr_id,
    EMAIL_STOR_OFFSET offset,
    srv_eamil_msg_text_type_enum text_type,
    WCHAR *read_path,
    MMI_BOOL output_tmp,
    email_stor_fs_msg_edit_part_write_ptr callback,
    void *userdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *write_path;
    srv_email_stor_file_enum file_type = SRV_EMAIL_STOR_FILE_TOTAL;
    email_stor_fs_msg_edit_part_write_copy_struct *copy_cnxt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    copy_cnxt = (email_stor_fs_msg_edit_part_write_copy_struct *)
                email_stor_malloc(sizeof(*copy_cnxt));
    if (copy_cnxt == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(*copy_cnxt));
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    switch (text_type)
    {
        case SRV_EMAIL_MSG_TEXT_CONT_TEXT:
            file_type = SRV_EMAIL_STOR_FILE_CONT_TEXT;
            break;
        case SRV_EMAIL_MSG_TEXT_CONT_HTML:
            file_type = SRV_EMAIL_STOR_FILE_CONT_HTML;
            break;
        default:
            MMI_ASSERT(0);
            break;
    }

    write_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN);
    if (write_path == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_msg_parts_gen_path(acct_id, fldr_id, offset, file_type, write_path);

    if (output_tmp)
    {
        mmi_wcscat(write_path, EMAIL_STOR_MSG_UPDATE_TMP_FILE_SUFFIX);
    }

    copy_cnxt->callback = callback;
    copy_cnxt->userdata = userdata;
    copy_cnxt->job_id = srv_fmgr_async_copy(
                        read_path, write_path, FS_MOVE_OVERWRITE | FS_MOVE_COPY,
                        email_stor_fs_msg_parts_write_proc_func, copy_cnxt);

    if (copy_cnxt->job_id < FS_NO_ERROR)
    {
        EMAIL_STOR_TRACE_FS_COPY(copy_cnxt->job_id);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    email_stor_path_mfree(write_path);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_edit_handle_isvalid
 * DESCRIPTION
 *  Find the specified handle, check whether it is valid
 * PARAMETERS
 *  create_handle   [IN]        storage handle
 * RETURNS
 *  If the specified handle found, return ture; otherwise return false.
 *****************************************************************************/
MMI_BOOL email_stor_fs_msg_edit_handle_isvalid(
    EMAIL_STOR_HANDLE create_handle, email_stor_msg_edit_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == EMAIL_CREATE)
    {
        for (; i < EMAIL_STOR_MAX_MSG_CREATE_HANDLE; ++i)
        {
            if (email_stor_p->msg_create_cntx[i] == create_handle)
            {
                return MMI_TRUE;
            }
        }
    }
    else if (type == EMAIL_UPDATE)
    {
        // for update
        if (email_stor_p->msg_update_cntx == create_handle)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_edit_handle_set_null
 * DESCRIPTION
 *  Find the matched handle, set the position to NULL
 * PARAMETERS
 *  create_handle   [IN]        storage handle
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_msg_edit_handle_set_null(
    EMAIL_STOR_HANDLE create_handle, email_stor_msg_edit_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == EMAIL_CREATE)
    {
        for (; i < EMAIL_STOR_MAX_MSG_CREATE_HANDLE; ++i)
        {
            if (email_stor_p->msg_create_cntx[i] == create_handle)
            {
                email_stor_p->msg_create_cntx[i] = NULL;
                return;
            }
        }
    }
    else if (type == EMAIL_UPDATE)
    {
        email_stor_p->msg_update_cntx = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_edit_handle_add
 * DESCRIPTION
 *  Find an empty position, set it to input handle
 * PARAMETERS
 *  create_handle   [IN]        storage handle
 * RETURNS
 *  If an empty position found, return ture; otherwise return false.
 *****************************************************************************/
MMI_BOOL email_stor_fs_msg_edit_handle_add(
    EMAIL_STOR_HANDLE create_handle, email_stor_msg_edit_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == EMAIL_CREATE)
    {
        for (i = 0; i < EMAIL_STOR_MAX_MSG_CREATE_HANDLE; ++i)
        {
            if (email_stor_p->msg_create_cntx[i] == NULL)
            {
                email_stor_p->msg_create_cntx[i] = create_handle;
                return MMI_TRUE;
            }
        }
    }
    else if (type == EMAIL_UPDATE)
    {
        if (email_stor_p->msg_update_cntx == NULL)
        {
            email_stor_p->msg_update_cntx = create_handle;
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_edit_abort
 * DESCRIPTION
 *  Cancel MSG creating
 * PARAMETERS
 *  msg_create_handle       [IN]    MSG handle
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_edit_abort(
    EMAIL_STOR_HANDLE msg_edit_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, ret;
    WCHAR *tmp_orig_path;
    email_stor_fs_msg_edit_struct *cnxt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnxt = (email_stor_fs_msg_edit_struct*) msg_edit_handle;

    if (!email_stor_fs_msg_edit_handle_isvalid(msg_edit_handle, cnxt->edit_type))
    {
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }
    if (cnxt->saa_hd != EMAIL_STOR_INVALID_FS_HANDLE)
    {
        EMAIL_FS_CLOSE(cnxt->saa_hd);
    }
    if (cnxt->get_msg_id_hd != EMAIL_STOR_INVALID_FS_HANDLE)
    {
        EMAIL_FS_CLOSE(cnxt->get_msg_id_hd);
    }
    email_stor_fs_msg_edit_handle_set_null(msg_edit_handle, cnxt->edit_type);

    /* Rename back temp file. */
    tmp_orig_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN);
    if (tmp_orig_path == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        /* No need error handling, fatal error will happen */
    }

    for (i = 0; i < EMAIL_STOR_MAX_ATTACH_NUM; i++)
    {
        if (cnxt->attch_path[i].attch_id == 0)
        {
            continue;
        }

        email_stor_fs_attch_gen_path(cnxt->attch_path[i].attch_id,
                                     tmp_orig_path);

        ret = FS_Rename(tmp_orig_path,
                        &cnxt->attch_path[i].attch_original_path[0]);
        if (ret != FS_NO_ERROR)
        {
            EMAIL_STOR_TRACE_FS_RENAME(ret);
        }
    }
    email_stor_path_mfree(tmp_orig_path);
    email_stor_mfree(cnxt);
    return SRV_EMAIL_RESULT_SUCC;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_edit
 * DESCRIPTION
 *  Create a new msg.
 * PARAMETERS
 *  header                      [In]        MSG header info pointer
 *  query_text_callback         [IN]        If (text/addr/attch) query callback 
 *                                          is NULL, means this part is NULL
 *  query_addr_callback         [IN]        Used to query addresses
 *  query_attch_callback        [IN]        Used to query addresses
 *  callback                    [IN]        Callback
 *  user_data                   [IN]        User data
 *  msg_create_handle           [OUT]       Storage handle
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_edit(
    srv_email_stor_msg_create_header_struct *header,
    srv_email_stor_msg_query_text_funcptr_type query_text_callback,
    srv_email_stor_msg_query_addr_funcptr_type query_addr_callback,
    srv_email_stor_msg_query_attch_funcptr_type query_attch_callback,
    srv_email_stor_msg_create_funcptr_type callback,
    void *userdata,
    EMAIL_STOR_HANDLE *msg_edit_handle,
    email_stor_msg_edit_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* if (text/addr/attch) query callback is NULL, means this part is NULL */
    srv_email_result_enum result;
    email_stor_fs_msg_edit_struct *cnxt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(header != NULL);

    cnxt = email_stor_malloc(sizeof(*cnxt));
    if (cnxt == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(*cnxt));
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    if (!email_stor_fs_msg_edit_handle_add(cnxt, type))
    {
        email_stor_mfree(cnxt);
        EMAIL_STOR_TRACE_MSG_EDIT(header->acct_id, header->fldr_id, 0, type,
                                  SRV_EMAIL_RESULT_CREATE_INSTANCE_FAIL);
        return SRV_EMAIL_RESULT_CREATE_INSTANCE_FAIL;
    }

    memset(cnxt, 0, sizeof(*cnxt));

    cnxt->edit_type = type;
    if (type == EMAIL_CREATE)
    {
        cnxt->acct_id = header->acct_id;
        cnxt->fldr_id = header->fldr_id;
        cnxt->offset  = email_stor_fs_msg_next_valid_offset_get(cnxt->acct_id, cnxt->fldr_id);
        cnxt->edit_state = EMAIL_STOR_MSG_EDIT_GET_MSG_ID;
    }
    else
    {
        cnxt->acct_id = email_stor_fs_msg_id_to_acct_id(header->msg_id);
        cnxt->fldr_id = email_stor_fs_msg_id_to_fldr_id(header->msg_id);
        cnxt->offset = email_stor_fs_msg_id_to_offset(header->msg_id);
        cnxt->edit_state = EMAIL_STOR_MSG_EDIT_COPY_ATTACH;
    }
    EMAIL_STOR_TRACE_MSG_EDIT(cnxt->acct_id, cnxt->fldr_id, cnxt->offset, type, 0);
    cnxt->query_addr_callback = query_addr_callback;
    cnxt->query_attch_callback = query_attch_callback;
    cnxt->query_text_callback = query_text_callback;
    cnxt->callback = callback;
    cnxt->user_data = userdata;

    cnxt->remain_attach_num = header->remain_attach_num;
    cnxt->addr_to_num = header->addr_to_num;
    cnxt->remain_addr_to_num = header->remain_addr_to_num;
    cnxt->addr_cc_num = header->addr_cc_num;
    cnxt->remain_addr_cc_num = header->remain_addr_cc_num;
    cnxt->addr_bcc_num = header->addr_bcc_num;
    cnxt->remain_addr_bcc_num = header->remain_addr_bcc_num;
    cnxt->subj_len = header->subj_len;
    cnxt->text_len = header->text_len;
    cnxt->html_len = header->html_len;
    cnxt->msg_type = header->msg_type;

    cnxt->header.valid = MMI_TRUE;
    cnxt->header.flag_latest = header->flag;
    cnxt->header.flag_orig = header->flag;
    cnxt->header.priority = header->priority;
    cnxt->header.state = header->state;
    cnxt->header.uid_validity = header->uid_validity;
    cnxt->header.uid = header->uid;
    
    memcpy(cnxt->header.uidl, header->uidl, SRV_EMAIL_MD5_DIGEST_LEN);
    memcpy(cnxt->header.acct_digest,
           header->acct_digest,
           SRV_EMAIL_MD5_DIGEST_LEN);

    cnxt->header.created_date = header->created_date;
    cnxt->header.received_date = header->received_date;
    cnxt->header.local_size = EMAIL_STOR_SAA_PART_MIN_SIZE_TOTAL + 
                                 sizeof(srv_email_stor_addr_struct) *
                                    (cnxt->addr_to_num
                                     + cnxt->addr_cc_num
                                     + cnxt->addr_bcc_num);

    cnxt->header.server_size = header->server_size;
    cnxt->header.attch_num = header->attch_num;
    if (header->subj_len > 0)
    {
        mmi_wcscpy(cnxt->header.list_subj, header->list_subj);
    }
    cnxt->saa_hd = EMAIL_STOR_INVALID_FS_HANDLE;
    cnxt->get_msg_id_hd = EMAIL_STOR_INVALID_FS_HANDLE;

    if (type == EMAIL_UPDATE)
    {
        /* Init attach id linked list */
        result = email_stor_fs_msg_get_attch_id(cnxt->acct_id,
                                                cnxt->fldr_id,
                                                cnxt->offset,
                                                &cnxt->attch_del_header);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            email_stor_fs_attch_id_link_free(cnxt->attch_del_header);
            email_stor_mfree(cnxt);
            return result;
        }
    }

    *msg_edit_handle = (EMAIL_STOR_HANDLE) cnxt;

    srv_email_schdl_start_job(
        (srv_email_schdl_funcptr_type) email_stor_fs_msg_edit_fsm, cnxt);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_edit_get_msg_id
 * DESCRIPTION
 *  Get a valid msg ID
 * PARAMETERS
 *  cnxt     [IN]     MSG create context
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_edit_get_msg_id(
    email_stor_fs_msg_edit_struct *cnxt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret, dir_exist;
    U32 rw;
    WCHAR *path = NULL;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    switch (cnxt->get_msg_id_state)
    {
        case EMAIL_STOR_MSG_EDIT_GET_MSG_ID_INIT:
        {
            U32 total_num = 0;

            email_stor_fs_fldr_gen_path(cnxt->acct_id, cnxt->fldr_id, EMAIL_STOR_FLDR_INDEX, path);
            if (EMAIL_STOR_FS_HANDLE_INVALID(cnxt->get_msg_id_hd = EMAIL_FS_OPEN(path, FS_READ_ONLY | FS_OPEN_SHARED)))
            {
                EMAIL_STOR_TRACE_FS_OPEN(cnxt->get_msg_id_hd);
                result = SRV_EMAIL_RESULT_FS_ERROR;
                goto STOR_EXIT;
            }

            EMAIL_FS_SEEK(cnxt->get_msg_id_hd, EMAIL_STOR_FLDR_TOTAL_NUM_POS, FS_FILE_BEGIN);
            ret = FS_Read(cnxt->get_msg_id_hd, &total_num, sizeof(U32), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(U32) || 
                total_num >= EMAIL_STOR_MAX_MSG_NUM_PER_FLDR)
            {
                EMAIL_FS_CLOSE(cnxt->get_msg_id_hd);
                if (ret != FS_NO_ERROR || rw != sizeof(U32))
                {
                    result = SRV_EMAIL_RESULT_FS_ERROR;
                }
                result = SRV_EMAIL_RESULT_MSG_REACH_MAX_NUM;
                goto STOR_EXIT;
            }

            cnxt->get_msg_id_state++;

            result = SRV_EMAIL_RESULT_SUCC;
            goto STOR_EXIT;
        }

        case EMAIL_STOR_MSG_EDIT_GET_MSG_ID_FIND:
        {
            U32 loop_cnt = 0;
            MMI_BOOL valid = MMI_FALSE;
            #define EMAIL_STOR_MSG_EDIT_GET_MSG_ID_LOOP_NUM (20)
            EMAIL_STOR_OFFSET init_offset = email_stor_fs_msg_next_valid_offset_get(cnxt->acct_id, cnxt->fldr_id);

            while (loop_cnt < EMAIL_STOR_MSG_EDIT_GET_MSG_ID_LOOP_NUM)
            {
                EMAIL_FS_SEEK(cnxt->get_msg_id_hd, EMAIL_STOR_MSG_RECORD_POS(cnxt->offset), FS_FILE_BEGIN);
                ret = FS_Read(cnxt->get_msg_id_hd, &valid, sizeof(MMI_BOOL), &rw);
                if (rw != sizeof(MMI_BOOL))
                {
                    /* reach the end of INDEX file */
                    result = SRV_EMAIL_RESULT_SUCC;
                    break;
                }

                if (!valid)
                {
                    /* this MSG offset is unused */
                    result = SRV_EMAIL_RESULT_SUCC;
                    break;
                }

                /* to check next offset */
                cnxt->offset++;

                if (cnxt->offset == init_offset ||
                    (init_offset == 0 && cnxt->offset >= EMAIL_STOR_MAX_MSG_NUM_PER_FLDR))
                {
                    /* exceed the maximum number */
                    EMAIL_STOR_TRACE_OFST_REACH_MAX(cnxt->acct_id, cnxt->fldr_id, cnxt->offset);
                    result = SRV_EMAIL_RESULT_MSG_REACH_MAX_NUM;
                    break;
                }

                if (cnxt->offset >= EMAIL_STOR_MAX_MSG_NUM_PER_FLDR)
                {
                    cnxt->offset = 0;
                }

                ++loop_cnt;
            }

            if (loop_cnt == EMAIL_STOR_MSG_EDIT_GET_MSG_ID_LOOP_NUM)
            {
                // not found, loop again
                result = SRV_EMAIL_RESULT_SUCC;
            }
            else
            {
                // find one, go to next state
                cnxt->get_msg_id_state++;
            }
            goto STOR_EXIT;
        }

        case EMAIL_STOR_MSG_EDIT_GET_MSG_ID_CREATE_PARTS_DIR:
        {
            EMAIL_FS_CLOSE(cnxt->get_msg_id_hd);

            cnxt->get_msg_id_state++;

            if (cnxt->offset == 0)
            {
                /* parts dir */
                email_stor_fs_fldr_parts_root_gen_path(cnxt->acct_id, cnxt->fldr_id, path);
                dir_exist = srv_email_util_dir_exist(path);
                if (dir_exist < 0)
                {
                    EMAIL_STOR_TRACE_FS_CREATE_DIR(dir_exist);
                    result = SRV_EMAIL_RESULT_FS_ERROR;
                }
                else if (!dir_exist)
                {
                    ret = FS_CreateDir(path);
                    if (ret != FS_NO_ERROR && ret != FS_FILE_EXISTS)
                    {
                        EMAIL_STOR_TRACE_FS_CREATE_DIR(ret);
                        result = SRV_EMAIL_RESULT_FS_ERROR;
                    }
                }
                goto STOR_EXIT;
            }

            // NO break here
        }

        case EMAIL_STOR_MSG_EDIT_GET_MSG_ID_CREATE_ATTCH_DIR:
        {
            cnxt->get_msg_id_state++;

            if (cnxt->offset == 0)
            {
                /* attach dir */
                email_stor_fs_fldr_attch_root_gen_path(cnxt->acct_id, cnxt->fldr_id, path);
                dir_exist = srv_email_util_dir_exist(path);
                if (dir_exist < 0)
                {
                    EMAIL_STOR_TRACE_FS_CREATE_DIR(dir_exist);
                    result = SRV_EMAIL_RESULT_FS_ERROR;
                }
                else if (!dir_exist)
                {
                    ret = FS_CreateDir(path);
                    if (ret != FS_NO_ERROR && ret != FS_FILE_EXISTS)
                    {
                        EMAIL_STOR_TRACE_FS_CREATE_DIR(ret);
                        result = SRV_EMAIL_RESULT_FS_ERROR;
                    }
                }
                goto STOR_EXIT;
            }

            // NO break here
        }

        case EMAIL_STOR_MSG_EDIT_GET_MSG_ID_CREATE_PARTS_BRANCH_IDR:
        {
            cnxt->get_msg_id_state++;

            if (cnxt->offset % EMAIL_STOR_MSG_NUM_PER_PARTS_DIR == 0)
            {
                email_stor_fs_fldr_parts_branch_gen_path(
                    cnxt->acct_id, cnxt->fldr_id, cnxt->offset, path);

                ret = FS_CreateDir(path);
                if (ret != FS_NO_ERROR && ret != FS_FILE_EXISTS)
                {
                    EMAIL_STOR_TRACE_FS_CREATE_DIR(ret);
                    result = SRV_EMAIL_RESULT_FS_ERROR;
                }
                goto STOR_EXIT;
            }

            // NO break here
        }

        case EMAIL_STOR_MSG_EDIT_GET_MSG_ID_CREATE_ATTCH_BRANCH_IDR:
        {
            cnxt->get_msg_id_state++;

            if (cnxt->offset % EMAIL_STOR_MSG_NUM_PER_ATTCH_DIR == 0)
            {
                email_stor_fs_fldr_attch_branch_gen_path(
                    cnxt->acct_id, cnxt->fldr_id, cnxt->offset, path);

                ret = FS_CreateDir(path);
                if (ret != FS_NO_ERROR && ret != FS_FILE_EXISTS)
                {
                    EMAIL_STOR_TRACE_FS_CREATE_DIR(ret);
                    result = SRV_EMAIL_RESULT_FS_ERROR;
                    goto STOR_EXIT;
                }
            }

            cnxt->edit_state = EMAIL_STOR_MSG_EDIT_GET_MSG_ID_DONE;
        }
    }

STOR_EXIT:
    email_stor_path_mfree(path);
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_edit_attch_copy
 * DESCRIPTION
 *  To copy attachment
 * PARAMETERS
 *  cnxt     [IN]     MSG create context
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_edit_attch_copy(
    email_stor_fs_msg_edit_struct *cnxt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *to_path;
    WCHAR *from_path;
    EMAIL_ATTCH_ID attch_id;
    S32 attch_keep_src = 0;
    S32 ret;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    FS_HANDLE hd;
    U32 attch_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    from_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN);
    if (from_path == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    to_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN);
    if (to_path == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        email_stor_path_mfree(from_path);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    *from_path = 0;
    *to_path = 0;

    cnxt->query_attch_callback(cnxt->attch_index_to_deal,
                                        from_path,
                                        EMAIL_STOR_WCS_SYS_PATH_LEN,
                                        &attch_keep_src,
                                        SRV_EMAIL_STOR_ATTCH_QUERY_PATH,
                                        cnxt->user_data);

    /* this attach in SYSTEM */
    attch_id = email_stor_fs_attch_path_to_id(from_path);
    if (attch_id != EMAIL_ATTCH_INVALID_ID)
    {
        email_stor_fs_attch_id_link_add(&(cnxt->attch_new_header), attch_id);
        email_stor_fs_attch_id_link_del(&(cnxt->attch_del_header), attch_id);

        hd = EMAIL_FS_OPEN(from_path, FS_READ_ONLY);
        if (EMAIL_STOR_FS_HANDLE_INVALID(hd))
        {
            EMAIL_STOR_TRACE_FS_OPEN(hd);
            email_stor_path_mfree(from_path);
            email_stor_path_mfree(to_path);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        FS_GetFileSize(hd, &attch_size);
        cnxt->header.local_size += attch_size;
        EMAIL_FS_CLOSE(hd);
    }
    else
    {
        email_stor_fs_attch_id_create(email_stor_fs_msg_id_gen(
                                    cnxt->acct_id,
                                    cnxt->fldr_id,
                                    cnxt->offset),
                                    &attch_id);

        email_stor_fs_attch_id_link_add(&(cnxt->attch_new_header), attch_id);

        if (*from_path != 0)
        {
            email_stor_fs_attch_gen_path(attch_id, to_path);

            if (attch_keep_src)
            {
                ret = FS_Move(from_path,
                              to_path,
                              FS_MOVE_COPY | FS_MOVE_OVERWRITE,
                              NULL, NULL, 0);
            }
            else
            {
                ret = FS_Rename(from_path, to_path);
                if (cnxt->attch_index_to_deal < EMAIL_STOR_MAX_ATTACH_NUM)
                {
                    email_stor_fs_original_attch_struct *orig_attch;
                    orig_attch = &(cnxt->attch_path[cnxt->attch_index_to_deal]);

                    orig_attch->attch_id = attch_id;
                    mmi_wcscpy(orig_attch->attch_original_path, from_path);
                }
            }

            if (ret != FS_NO_ERROR)
            {
                EMAIL_STOR_TRACE_FS_RENAME(ret);
                result = SRV_EMAIL_RESULT_FS_ERROR;
                goto STOR_EXIT_HANDLE;
            }

            hd = EMAIL_FS_OPEN(to_path, FS_READ_ONLY);
            if (EMAIL_STOR_FS_HANDLE_INVALID(hd))
            {
                EMAIL_STOR_TRACE_FS_OPEN(hd);
                result = SRV_EMAIL_RESULT_FS_ERROR;
                goto STOR_EXIT_HANDLE;
            }

            FS_GetFileSize(hd, &attch_size);
            cnxt->header.local_size += attch_size;
            EMAIL_FS_CLOSE(hd);
        }
    }

    ++(cnxt->attch_index_to_deal);
    if (cnxt->attch_index_to_deal >= cnxt->header.attch_num)
    {
        cnxt->edit_state = EMAIL_STOR_MSG_EDIT_COPY_ATTACH_DONE;
    }

STOR_EXIT_HANDLE:
    email_stor_path_mfree(from_path);
    email_stor_path_mfree(to_path);
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_edit_init_saa
 * DESCRIPTION
 *  Write text to FS
 * PARAMETERS
 *  cnxt     [IN]     MSG create context
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_edit_init_saa(
    email_stor_fs_msg_edit_struct *cnxt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 rw;
    WCHAR* saa_path;
    U32 header_pos[4];
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    header_pos[0] = EMAIL_STOR_SAA_CONT_HEADER_POS;
    header_pos[1] = EMAIL_STOR_SAA_ADDR_POS;
    header_pos[2] = header_pos[1] +
                    6 * sizeof(U16) +
                    sizeof(srv_email_stor_addr_struct) * 2 +
                    sizeof(srv_email_stor_addr_struct) * cnxt->addr_to_num +
                    sizeof(srv_email_stor_addr_struct) * cnxt->addr_cc_num +
                    sizeof(srv_email_stor_addr_struct) * cnxt->addr_bcc_num ;
    header_pos[3] = header_pos[2] +
                    2 * sizeof(U32) + // attach num & attach remain num
                    sizeof(srv_email_stor_attch_struct) * cnxt->header.attch_num;

    saa_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN);
    if (saa_path == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        result = SRV_EMAIL_RESULT_NO_MEMORY;
        goto STOR_EXIT_HANDLE;
    }

    /* write TEXT content header */
    email_stor_fs_msg_parts_gen_path(
        cnxt->acct_id,
        cnxt->fldr_id,
        cnxt->offset,
        SRV_EMAIL_STOR_FILE_SAA,
        saa_path);

    if (cnxt->edit_type == EMAIL_UPDATE)
    {
        mmi_wcscat(saa_path, EMAIL_STOR_MSG_UPDATE_TMP_FILE_SUFFIX);
    }

    cnxt->saa_hd = EMAIL_FS_OPEN(saa_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (EMAIL_STOR_FS_HANDLE_INVALID(cnxt->saa_hd))
    {
        EMAIL_STOR_TRACE_FS_OPEN(cnxt->saa_hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }

    ret = FS_Write(cnxt->saa_hd, header_pos, sizeof(header_pos), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(header_pos))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }
    
    cnxt->edit_state = EMAIL_STOR_MSG_EDIT_SAA_INIT_DONE;
STOR_EXIT_HANDLE:
    if (saa_path != NULL)
    {
        email_stor_path_mfree(saa_path);
    }
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_edit_text_write
 * DESCRIPTION
 *  Write text to FS
 * PARAMETERS
 *  cnxt     [IN]     MSG create context
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_edit_text_write(
    email_stor_fs_msg_edit_struct *cnxt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 rw;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    U32 text_html_len = 0;
    srv_eamil_msg_text_type_enum text_type = SRV_EMAIL_MSG_TEXT_CONT_TEXT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cnxt->edit_state == EMAIL_STOR_MSG_EDIT_WRITE_TEXT)
    {
        text_html_len = cnxt->text_len;
        text_type = SRV_EMAIL_MSG_TEXT_CONT_TEXT;
    }
    else if (cnxt->edit_state == EMAIL_STOR_MSG_EDIT_WRITE_HTML)
    {
        text_html_len = cnxt->html_len;
        text_type = SRV_EMAIL_MSG_TEXT_CONT_HTML;
    }
    else {MMI_ASSERT(0);}

    switch (cnxt->write_text_state)
    {
        case EMAIL_STOR_MSG_EDIT_WRITE_TEXT_INIT:
            cnxt->text_write_cnxt = email_stor_malloc(sizeof(*cnxt->text_write_cnxt));
            if (cnxt->text_write_cnxt == NULL)
            {
                EMAIL_STOR_TRACE_MALLOC(sizeof(*cnxt->text_write_cnxt));
                result = SRV_EMAIL_RESULT_NO_MEMORY;
                goto STOR_EXIT_HANDLE;
            }
            memset(cnxt->text_write_cnxt, 0, sizeof(*cnxt->text_write_cnxt));

            cnxt->text_write_cnxt->from_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN);
            if (cnxt->text_write_cnxt->from_path == NULL)
            {
                EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
                result = SRV_EMAIL_RESULT_NO_MEMORY;
                goto STOR_EXIT_HANDLE;
            }

            *cnxt->text_write_cnxt->from_path = 0;

            if (text_html_len != 0 && cnxt->query_text_callback != NULL)
            {
                cnxt->query_text_callback(text_type,
                                          &cnxt->text_write_cnxt->cont_header,
                                          cnxt->text_write_cnxt->from_path,
                                          EMAIL_STOR_WCS_SYS_PATH_LEN,
                                          &cnxt->text_write_cnxt->keep_file_src,
                                          cnxt->user_data);
            }
            cnxt->write_text_state = EMAIL_STOR_MSG_EDIT_WRITE_TEXT_CONT_GET_SIZE;
            result = SRV_EMAIL_RESULT_SUCC;
            goto DONE;

        case EMAIL_STOR_MSG_EDIT_WRITE_TEXT_CONT_GET_SIZE:
            if (text_html_len != 0 && *cnxt->text_write_cnxt->from_path != 0)
            {
                cnxt->text_write_cnxt->hd = EMAIL_FS_OPEN(cnxt->text_write_cnxt->from_path, FS_READ_ONLY);
                if (EMAIL_STOR_FS_HANDLE_INVALID(cnxt->text_write_cnxt->hd))
                {
                    EMAIL_STOR_TRACE_FS_OPEN(cnxt->text_write_cnxt->hd);
                    result = SRV_EMAIL_RESULT_FS_ERROR;
                    goto STOR_EXIT_HANDLE;
                }
                FS_GetFileSize(cnxt->text_write_cnxt->hd, &cnxt->text_write_cnxt->cont_header.local_size);
                cnxt->header.local_size += cnxt->text_write_cnxt->cont_header.local_size;
                EMAIL_FS_CLOSE(cnxt->text_write_cnxt->hd);

                cnxt->write_text_state = EMAIL_STOR_MSG_EDIT_WRITE_TEXT_CONT_ASYNC;
                result = SRV_EMAIL_RESULT_SUCC;
                goto DONE;
            }

        case EMAIL_STOR_MSG_EDIT_WRITE_TEXT_CONT_ASYNC:
            /* write content */
            if (text_html_len != 0 && *cnxt->text_write_cnxt->from_path != 0)
            {
                if (cnxt->text_write_cnxt->keep_file_src)
                {
                    // keep src file, need copy file async
                    result = email_stor_fs_msg_parts_write_async(cnxt->acct_id,
                                                           cnxt->fldr_id,
                                                           cnxt->offset,
                                                           text_type,
                                                           cnxt->text_write_cnxt->from_path,
                                                           cnxt->edit_type == EMAIL_UPDATE ? MMI_TRUE : MMI_FALSE,
                                                           email_stor_fs_msg_edit_fsm,
                                                           cnxt);
                    if (result != SRV_EMAIL_RESULT_WOULDBLOCK)
                    {
                        goto STOR_EXIT_HANDLE;
                    }
                    cnxt->write_text_state = EMAIL_STOR_MSG_EDIT_WRITE_TEXT_CONT_HEADER;
                    goto DONE;
                }
                else
                {
                    // no need to keep src file, just rename it
                    result = email_stor_fs_msg_parts_write(cnxt->acct_id,
                                cnxt->fldr_id,
                                cnxt->offset,
                                text_type,
                                cnxt->text_write_cnxt->from_path,
                                cnxt->edit_type == EMAIL_UPDATE ? MMI_TRUE : MMI_FALSE);
                    if (result != SRV_EMAIL_RESULT_SUCC)
                    {
                        goto STOR_EXIT_HANDLE;
                    }
                    cnxt->write_text_state = EMAIL_STOR_MSG_EDIT_WRITE_TEXT_CONT_HEADER;
                    goto DONE;
                }
            }

        case EMAIL_STOR_MSG_EDIT_WRITE_TEXT_CONT_HEADER:
            /* write content header */
            ret = FS_Write(cnxt->saa_hd,
                           &cnxt->text_write_cnxt->cont_header,
                           sizeof(cnxt->text_write_cnxt->cont_header),
                           &rw);
            if (ret != FS_NO_ERROR ||
                rw != sizeof(cnxt->text_write_cnxt->cont_header))
            {
                EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
                result = SRV_EMAIL_RESULT_FS_ERROR;
                goto STOR_EXIT_HANDLE;
            }
            cnxt->write_text_state = EMAIL_STOR_MSG_EDIT_WRITE_TEXT_INIT;
            if (cnxt->edit_state == EMAIL_STOR_MSG_EDIT_WRITE_TEXT)
            {
                cnxt->edit_state = EMAIL_STOR_MSG_EDIT_WRITE_TEXT_DONE;
            }
            else
            {
                cnxt->edit_state = EMAIL_STOR_MSG_EDIT_WRITE_HTML_DONE;
            }
            break;
    }

STOR_EXIT_HANDLE:
    if (cnxt->text_write_cnxt != NULL)
    {
    if (cnxt->text_write_cnxt->from_path != NULL)
    {
        email_stor_path_mfree(cnxt->text_write_cnxt->from_path);
    }

        email_stor_mfree(cnxt->text_write_cnxt);
    }
DONE:
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_edit_async_write_callback
 * DESCRIPTION
 *  Write text to FS
 * PARAMETERS
 *  job_id      [IN]    FS job id
 *  result      [IN]    result
 *  data        [IN]    userdata
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
S32 email_stor_fs_msg_edit_async_write_callback(
    fs_job_id job_id, kal_int64 result, fs_async_callback_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    email_stor_fs_msg_edit_struct *cnxt = (email_stor_fs_msg_edit_struct*)data->param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!email_stor_fs_msg_edit_handle_isvalid(cnxt, EMAIL_CREATE) &&
        !email_stor_fs_msg_edit_handle_isvalid(cnxt, EMAIL_UPDATE))
    {
        return 0;
    }
    
    ASSERT(cnxt->edit_state == EMAIL_STOR_MSG_EDIT_WRITE_ADDR ||
           cnxt->edit_state == EMAIL_STOR_MSG_EDIT_WRITE_ATTACH);

    if (result >= FS_NO_ERROR)
    {
        cnxt->result = SRV_EMAIL_RESULT_SUCC;
    }
    else
    {
        cnxt->result = SRV_EMAIL_RESULT_FS_ERROR;
        EMAIL_STOR_TRACE_FS_WRITE((S32)result, cnxt->fs_rw);
    }

    cnxt->edit_state++;

    email_stor_mfree(cnxt->fs_buf);
    email_stor_mfree(cnxt->fs_overlapped.buf);

    email_stor_fs_msg_edit_fsm(cnxt);
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_edit_addr_write
 * DESCRIPTION
*  Write addresses part to FS
 * PARAMETERS
 *  cnxt     [IN]     MSG create context
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_edit_addr_write(
    email_stor_fs_msg_edit_struct *cnxt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_stor_addr_struct *addr;
    U32 addr_note_size;
    U16 *addr_nums;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnxt->edit_state = EMAIL_STOR_MSG_EDIT_WRITE_ADDR;
    addr_note_size = 2 + cnxt->addr_to_num + cnxt->addr_cc_num + cnxt->addr_bcc_num;

    cnxt->fs_buf_size = sizeof(*addr_nums) * 6 + sizeof(*addr) * addr_note_size;
    cnxt->fs_buf = email_stor_malloc(cnxt->fs_buf_size);
    if (cnxt->fs_buf == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(cnxt->fs_buf_size);
        goto STOR_EXIT_HANDLE_WRITE;
    }
    memset(cnxt->fs_buf, 0, cnxt->fs_buf_size);

    addr_nums = (U16*)cnxt->fs_buf;
    addr = (srv_email_stor_addr_struct*)(cnxt->fs_buf + sizeof(*addr_nums) * 6);

    /* addr number */
    *(addr_nums + 0) = cnxt->addr_to_num;
    *(addr_nums + 1) = cnxt->addr_cc_num;
    *(addr_nums + 2) = cnxt->addr_bcc_num;
    *(addr_nums + 3) = cnxt->remain_addr_to_num;
    *(addr_nums + 4) = cnxt->remain_addr_cc_num;
    *(addr_nums + 5) = cnxt->remain_addr_bcc_num;

    if (cnxt->query_addr_callback != NULL)
    {
        U32 i, cnt = 0;

        /* FROM & REPLY_TO */
        cnxt->query_addr_callback(SRV_EMAIL_ADDR_TYPE_FROM, 0, addr + cnt++, cnxt->user_data);
        cnxt->query_addr_callback(SRV_EMAIL_ADDR_TYPE_REPLY_TO, 0, addr + cnt++, cnxt->user_data);

        /* write TO */
        for (i = 0; i < cnxt->addr_to_num; i++)
        {
            cnxt->query_addr_callback(SRV_EMAIL_ADDR_TYPE_TO, i, addr + cnt++, cnxt->user_data);
        }

        /* write CC */
        for (i = 0; i < cnxt->addr_cc_num; i++)
        {
            cnxt->query_addr_callback(SRV_EMAIL_ADDR_TYPE_CC, i, addr + cnt++, cnxt->user_data);
        }

        /* write BCC */
        for (i = 0; i < cnxt->addr_bcc_num; i++)
        {
            cnxt->query_addr_callback(SRV_EMAIL_ADDR_TYPE_BCC, i, addr + cnt++, cnxt->user_data);
        }
    }

    cnxt->fs_overlapped.priority = FS_PRIORITY_DEFAULT;
    cnxt->fs_overlapped.priority_value = 0;
    cnxt->fs_overlapped.response_flag = 0;
    cnxt->fs_overlapped.callback = (fs_async_callback)email_stor_fs_msg_edit_async_write_callback;
    cnxt->fs_overlapped.param = cnxt;
    cnxt->fs_overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
    cnxt->fs_overlapped.buf = email_stor_malloc(cnxt->fs_overlapped.buf_size);
    if (cnxt->fs_overlapped.buf == NULL)
    {
        email_stor_mfree(cnxt->fs_buf);
        result = SRV_EMAIL_RESULT_NO_MEMORY;
        EMAIL_STOR_TRACE_MALLOC(cnxt->fs_overlapped.buf_size);
        goto STOR_EXIT_HANDLE_WRITE;
    }

    cnxt->fs_job_id = fs_async_write(
                        cnxt->saa_hd,
                        cnxt->fs_buf,
                        cnxt->fs_buf_size,
                        &cnxt->fs_rw,
                        &cnxt->fs_overlapped);
    if (cnxt->fs_job_id < FS_NO_ERROR)
    {
        email_stor_mfree(cnxt->fs_buf);
        email_stor_mfree(cnxt->fs_overlapped.buf);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        EMAIL_STOR_TRACE_FS_WRITE(cnxt->fs_job_id, cnxt->fs_rw);
        goto STOR_EXIT_HANDLE_WRITE;
    }

    return SRV_EMAIL_RESULT_WOULDBLOCK;

STOR_EXIT_HANDLE_WRITE:
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_edit_attch_write
 * DESCRIPTION
*  Write attachments index part to FS
 * PARAMETERS
 *  cnxt     [IN]     MSG create context
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_edit_attch_write(
    email_stor_fs_msg_edit_struct *cnxt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    U32 i;
    U32 *attch_num; // attach num & remain num;
    srv_email_stor_attch_struct *attch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cnxt->edit_state = EMAIL_STOR_MSG_EDIT_WRITE_ATTACH;
    cnxt->fs_buf_size = sizeof(*attch_num) * 2 + sizeof(*attch) * cnxt->header.attch_num;
    cnxt->fs_buf = email_stor_malloc(cnxt->fs_buf_size);
    if (cnxt->fs_buf == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(cnxt->fs_buf_size);
        result = SRV_EMAIL_RESULT_NO_MEMORY;
        goto STOR_EXIT_HANDLE_WRITE;
    }
    memset(cnxt->fs_buf, 0, cnxt->fs_buf_size);

    attch_num = (U32*)cnxt->fs_buf;
    attch = (srv_email_stor_attch_struct*)(cnxt->fs_buf + sizeof(*attch_num) * 2);

    // fill attach number
    *(attch_num + 0) = (U32)cnxt->header.attch_num;
    *(attch_num + 1) = (U32)cnxt->remain_attach_num;

    // fill attach header
    if (cnxt->header.attch_num > 0)
    {
        email_stor_attch_id_link_struct *attch_header = cnxt->attch_new_header;

        for (i = 0; i < cnxt->header.attch_num && attch_header != NULL; i++)
        {
            cnxt->query_attch_callback(i, attch + i, sizeof(*attch), NULL,
                                       SRV_EMAIL_STOR_ATTCH_QUERY_HEADER,
                                       cnxt->user_data);
            (attch + i)->attch_id = attch_header->attch_id;
            attch_header = attch_header->next;
        }

        email_stor_fs_attch_id_link_free(cnxt->attch_new_header);
        cnxt->attch_new_header = NULL;
    }

    cnxt->fs_overlapped.priority = FS_PRIORITY_DEFAULT;
    cnxt->fs_overlapped.priority_value = 0;
    cnxt->fs_overlapped.response_flag = 0;
    cnxt->fs_overlapped.callback = (fs_async_callback)email_stor_fs_msg_edit_async_write_callback;
    cnxt->fs_overlapped.param = cnxt;
    cnxt->fs_overlapped.buf_size = FS_ASYNC_WORKING_BUFFER_SIZE;
    cnxt->fs_overlapped.buf = email_stor_malloc(cnxt->fs_overlapped.buf_size);
    if (cnxt->fs_overlapped.buf == NULL)
    {
        email_stor_mfree(cnxt->fs_buf);
        EMAIL_STOR_TRACE_MALLOC(cnxt->fs_overlapped.buf_size);
        result = SRV_EMAIL_RESULT_NO_MEMORY;
        goto STOR_EXIT_HANDLE_WRITE;
    }
    cnxt->fs_job_id = fs_async_write(
                        cnxt->saa_hd,
                        cnxt->fs_buf,
                        cnxt->fs_buf_size,
                        &cnxt->fs_rw,
                        &cnxt->fs_overlapped);
    if (cnxt->fs_job_id < FS_NO_ERROR)
    {
        email_stor_mfree(cnxt->fs_buf);
        email_stor_mfree(cnxt->fs_overlapped.buf);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        EMAIL_STOR_TRACE_FS_WRITE(cnxt->fs_job_id, cnxt->fs_rw);
        goto STOR_EXIT_HANDLE_WRITE;
    }

    return SRV_EMAIL_RESULT_WOULDBLOCK;

STOR_EXIT_HANDLE_WRITE:
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_edit_subj_write
 * DESCRIPTION
 *  Write subject part to FS
 * PARAMETERS
 *  cnxt     [IN]     MSG create context
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_edit_subj_write(
    email_stor_fs_msg_edit_struct *cnxt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    U32 rw;
    WCHAR *subj_buff;
    U32 file_pose;
    U32 subj_real_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get current Seek, it's the offset of ATTCH */
    FS_GetFilePosition(cnxt->saa_hd, &file_pose);

    /* write subject length later */
    EMAIL_FS_SEEK(cnxt->saa_hd, sizeof(U32), FS_FILE_CURRENT);

    if (cnxt->subj_len != 0)
    {
        if ((subj_buff = email_stor_malloc(cnxt->subj_len + 1)) == NULL)
        {
            EMAIL_STOR_TRACE_MALLOC(cnxt->subj_len + 1);
            result = SRV_EMAIL_RESULT_NO_MEMORY;
            goto STOR_EXIT_HANDLE;
        }
        memset(subj_buff, 0, cnxt->subj_len + 1);

        cnxt->query_text_callback(SRV_EMAIL_MSG_TEXT_SUBJ, NULL, subj_buff,
                                  cnxt->subj_len + 1, NULL, cnxt->user_data);
        subj_real_len = strlen((CHAR*) subj_buff);

        if (subj_real_len > 0)
        {
            /* write subject */
            ret = FS_Write(cnxt->saa_hd, subj_buff, subj_real_len, &rw);
            if (ret != FS_NO_ERROR || rw != subj_real_len)
            {
                EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
                result = SRV_EMAIL_RESULT_FS_ERROR;
                email_stor_mfree(subj_buff);
                goto STOR_EXIT_HANDLE;
            }
        }
        email_stor_mfree(subj_buff);
    }

    cnxt->header.local_size += subj_real_len;

    /* write subject length */
    EMAIL_FS_SEEK(cnxt->saa_hd, file_pose, FS_FILE_BEGIN);
    ret = FS_Write(cnxt->saa_hd, &subj_real_len, sizeof(U32), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        result = SRV_EMAIL_RESULT_NO_MEMORY;
        goto STOR_EXIT_HANDLE;
    }

    cnxt->edit_state = EMAIL_STOR_MSG_EDIT_WRITE_SUBJ_DONE;

    // here is the last position {saa_hd} is used.
    EMAIL_FS_CLOSE(cnxt->saa_hd);
    
STOR_EXIT_HANDLE:
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_edit_index_write
 * DESCRIPTION
 *  Update index/backup files
 * PARAMETERS
 *  cnxt     [IN]     MSG create context
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_edit_index_write(
    email_stor_fs_msg_edit_struct *cnxt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE index_hd;
    FS_HANDLE backup_hd;
    WCHAR *path;
    srv_email_stor_addr_struct *addr;
    srv_email_addr_type_enum addr_type;
    srv_email_fldr_type_enum fldr_type;
    srv_email_result_enum result;
    U32 file_size = 0;
    EMAIL_MSG_FLAG latest_flag;
    email_stor_fs_inbox_index_struct note;
    U64 disk_total_size, disk_free_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cnxt->write_index_state)
    {
    case EMAIL_STOR_MSG_EDIT_WRITE_INDEX_INIT:
        if (cnxt->msg_type == SRV_EMAIL_STOR_MSG_TYPE_RECV)
        {
            addr_type = SRV_EMAIL_ADDR_TYPE_FROM;
        }
        else  // SRV_EMIAL_STOR_MSG_TYPE_SENT
        {
            if (cnxt->addr_to_num != 0)
            {
                addr_type = SRV_EMAIL_ADDR_TYPE_TO;
            }
            else if (cnxt->addr_cc_num != 0)
            {
                addr_type = SRV_EMAIL_ADDR_TYPE_CC;
            }
            else if (cnxt->addr_bcc_num != 0)
            {
                addr_type = SRV_EMAIL_ADDR_TYPE_BCC;
            }
            else
            {
                addr_type = SRV_EMAIL_ADDR_TYPE_TOTAL;
            }
        }

        if ((addr = email_stor_malloc(sizeof(*addr))) == NULL)
        {
            EMAIL_STOR_TRACE_MALLOC(sizeof(*addr));
            return SRV_EMAIL_RESULT_NO_MEMORY;
        }
        memset(addr, 0, sizeof(*addr));

        if (cnxt->query_addr_callback != NULL && addr_type < SRV_EMAIL_ADDR_TYPE_TOTAL)
        {
            (*(cnxt->query_addr_callback)) (addr_type, 0, addr, cnxt->user_data);
            addr->disp_name[EMAIL_MAX_ENCODED_DISP_NAME_LEN] = 0;
            addr->email_addr[EMAIL_MAX_ENCODED_ADDR_LEN] = 0;
        }

        strcpy(cnxt->header.addr_disp_name, addr->disp_name);
        strcpy(cnxt->header.addr_email, addr->email_addr);
        email_stor_mfree(addr);

        if (cnxt->edit_type == EMAIL_UPDATE)
        {   /* delete invalid attch */
            email_stor_fs_attch_del(cnxt->attch_del_header);
            email_stor_fs_attch_id_link_free(cnxt->attch_del_header);
            cnxt->attch_del_header = NULL;
            
            email_stor_fs_msg_parts_rename(
                cnxt->acct_id,
                cnxt->fldr_id,
                cnxt->offset,
                SRV_EMAIL_STOR_FILE_CONT_TEXT);
            email_stor_fs_msg_parts_rename(
                cnxt->acct_id,
                cnxt->fldr_id,
                cnxt->offset,
                SRV_EMAIL_STOR_FILE_CONT_HTML);
            email_stor_fs_msg_parts_rename(
                cnxt->acct_id,
                cnxt->fldr_id,
                cnxt->offset,
                SRV_EMAIL_STOR_FILE_SAA);
        }

        if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
        {
            EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
            return SRV_EMAIL_RESULT_NO_MEMORY;
        }

        fldr_type = srv_email_fldr_id_to_fldr_type(cnxt->acct_id, cnxt->fldr_id);
        if (fldr_type != SRV_EMAIL_FLDR_TYPE_INBOX &&
            fldr_type != SRV_EMAIL_FLDR_TYPE_REMOTE)
        {
            // if it's local MSG, make server_size equal to local_size,
            // it's our APP's require
            cnxt->header.server_size = cnxt->header.local_size;
        }

        email_stor_fs_fldr_gen_path(cnxt->acct_id,
                                    cnxt->fldr_id,
                                    EMAIL_STOR_FLDR_INDEX, path);

        index_hd = EMAIL_FS_OPEN(path, FS_READ_WRITE);
        email_stor_path_mfree(path);
        if (EMAIL_STOR_FS_HANDLE_INVALID(index_hd))
        {
            EMAIL_STOR_TRACE_FS_OPEN(index_hd);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }

        if (FS_GetFileSize(index_hd, &file_size) >= FS_NO_ERROR &&
            file_size == EMAIL_STOR_MSG_RECORD_POS(cnxt->offset))
        {
            // it's last offset
            srv_fmgr_drv_get_size(srv_email_get_drive(),
                                  &disk_total_size, &disk_free_size);
            if (disk_free_size < 2 * sizeof(email_stor_fs_msg_struct))
            {
                EMAIL_STOR_TRACE_FS_OPEN(FS_DISK_FULL);
                EMAIL_FS_CLOSE(index_hd);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }
        }

        if (cnxt->edit_type == EMAIL_CREATE)
        {
            cnxt->msg_unread_num_chg = (S32)email_stor_fs_flag_mem_get(
                                        cnxt->header.flag_latest,
                                        SRV_EMAIL_STOR_SET_FLAG_UNSEEN);
        }
        else // EMAIL_UPDATE
        {
            S32 ret;
            U32 rw;

            EMAIL_FS_SEEK(index_hd,
                          EMAIL_STOR_MSG_LATEST_FLAG_POS(cnxt->offset),
                          FS_FILE_BEGIN);
            ret = FS_Read(index_hd, &latest_flag, sizeof(EMAIL_MSG_FLAG), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_FLAG))
            {
                EMAIL_STOR_TRACE_FS_READ(ret, rw);
                EMAIL_FS_CLOSE(index_hd);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }
        
            cnxt->msg_unread_num_chg = email_stor_fs_flag_mem_set(&latest_flag,
                                                            EMAIL_MSG_FLAG_SEEN,
                                                            cnxt->header.flag_latest);
        }

        result = email_stor_fs_msg_record_write_by_hd(index_hd,
                                                      cnxt->offset,
                                                      &cnxt->header);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            EMAIL_FS_CLOSE(index_hd);
            return result;
        }

        result = email_stor_fs_msg_num_update(index_hd,
                                              &cnxt->new_unread_num,
                                              cnxt->msg_unread_num_chg,
                                              EMAIL_STOR_MSG_UNREAD_NUM);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            EMAIL_FS_CLOSE(index_hd);
            return result;
        }

        // if (create new mail), total number++
        result = email_stor_fs_msg_num_update(index_hd,
                                              &cnxt->new_total_num,
                                              cnxt->edit_type == EMAIL_CREATE ? 1 : 0,
                                              EMAIL_STOR_MSG_TOTAL_NUM);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            EMAIL_FS_CLOSE(index_hd);
            return result;
        }

        cnxt->new_unread_num += cnxt->msg_unread_num_chg;
        if (cnxt->edit_type == EMAIL_CREATE)
        {
            cnxt->new_total_num++;
        }

        if (cnxt->edit_type == EMAIL_CREATE)
        {
            /* add the note to index array */
            note.offset = (U16) cnxt->offset;
            note.flag = cnxt->header.flag_latest;
            note.date = cnxt->header.created_date;

            /* -1, because it's new number, not orignal number */
            email_stor_p->inbox_index_size = cnxt->new_total_num - 1;
            email_stor_fs_inbox_index_read(index_hd);
            email_stor_fs_inbox_index_add(&note);
            result = email_stor_fs_inbox_index_write(index_hd);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                EMAIL_FS_CLOSE(index_hd);
                return result;
            }
        }
        else // UPDATE
        {
            if (latest_flag != cnxt->header.flag_latest)
            {
                email_stor_p->inbox_index_size = cnxt->new_total_num;
                email_stor_fs_inbox_index_read(index_hd);
                email_stor_fs_inbox_index_update((U16)cnxt->offset,
                                                 cnxt->header.flag_latest);
                email_stor_fs_inbox_index_write(index_hd);

                if (email_stor_fs_fldr_type_is_inbox(cnxt->acct_id, cnxt->fldr_id))
                {
                    email_stor_fs_acct_cache_update_msg_unread_chg(cnxt->acct_id,
                                                                   cnxt->msg_unread_num_chg);
                }
            }
        }

        if (email_stor_fs_fldr_type_is_inbox(cnxt->acct_id, cnxt->fldr_id))
        {
            email_stor_fs_acct_cache_update_msg_unread_chg(cnxt->acct_id,
                                                           cnxt->msg_unread_num_chg);
        }

        cnxt->index_checksum = srv_email_checksum_compute_by_hd(index_hd, sizeof(cnxt->index_checksum));
        result = srv_email_checksum_write_by_hd(index_hd, 0, cnxt->index_checksum);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            EMAIL_FS_CLOSE(index_hd);
            return result;
        }
        EMAIL_FS_CLOSE(index_hd);

        cnxt->write_index_state = EMAIL_STOR_MSG_EDIT_WRITE_INDEX_BAK;

    /* comment the following lines to resolve CR MAUI_03146106
        return SRV_EMAIL_RESULT_SUCC;

    case EMAIL_STOR_MSG_EDIT_WRITE_INDEX_BAK:
    */
        /* write BACKUP file */
        if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
        {
            EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
            return SRV_EMAIL_RESULT_NO_MEMORY;
        }
        email_stor_fs_fldr_gen_path(cnxt->acct_id,
                                    cnxt->fldr_id,
                                    EMAIL_STOR_FLDR_BACKUP,
                                    path);

        backup_hd = EMAIL_FS_OPEN(path, FS_READ_WRITE);
        email_stor_path_mfree(path);
        if (EMAIL_STOR_FS_HANDLE_INVALID(backup_hd))
        {
            EMAIL_STOR_TRACE_FS_OPEN(backup_hd);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }

        result = email_stor_fs_msg_record_write_by_hd(backup_hd,
                                                      cnxt->offset,
                                                      &cnxt->header);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            EMAIL_FS_CLOSE(backup_hd);
            return result;
        }

        if (cnxt->msg_unread_num_chg)
        {
            result = email_stor_fs_msg_num_update(backup_hd,
                                                  NULL, cnxt->msg_unread_num_chg,
                                                  EMAIL_STOR_MSG_UNREAD_NUM);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                EMAIL_FS_CLOSE(backup_hd);
                return result;
            }
        }

        result = email_stor_fs_msg_num_update(backup_hd, NULL,
                                              cnxt->edit_type == EMAIL_CREATE ? 1 : 0,
                                              EMAIL_STOR_MSG_TOTAL_NUM);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            EMAIL_FS_CLOSE(backup_hd);
            return result;
        }

        result = srv_email_checksum_write_by_hd(backup_hd, 0, cnxt->index_checksum);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            EMAIL_FS_CLOSE(backup_hd);
            return result;
        }

        result = email_stor_fs_inbox_index_write(backup_hd);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            EMAIL_FS_CLOSE(backup_hd);
            return result;
        }

        EMAIL_FS_CLOSE(backup_hd);

        email_stor_fs_msg_next_valid_offset_set(cnxt->acct_id, cnxt->offset);

        cnxt->edit_state = EMAIL_STOR_MSG_EDIT_WRITE_INDEX_DONE;
        return SRV_EMAIL_RESULT_SUCC;

    default:
        return SRV_EMAIL_RESULT_FAIL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_edit_finish
 * DESCRIPTION
 *  Last step of edit msg, notify app the change
 * PARAMETERS
 *  cnxt     [IN]     MSG create context
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_edit_change_notify(
    email_stor_fs_msg_edit_struct *cnxt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_om_notify_msg_struct msg_notify_data;
    srv_email_om_notify_fldr_struct fldr_notify_data;
    srv_email_om_notify_acct_struct acct_notify_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Notify MSG */
    msg_notify_data.msg_id = email_stor_fs_msg_id_gen(cnxt->acct_id, cnxt->fldr_id, cnxt->offset);
    if (cnxt->edit_type == EMAIL_CREATE)
    {
        srv_email_om_nofity_msg_from_stor(SRV_EMAIL_OM_NOTIFY_MSG_ADD, &msg_notify_data);
        srv_email_om_nofity_fldr_from_stor(SRV_EMAIL_OM_NOTIFY_MSG_ADD, &msg_notify_data);
    }
    else // UPDATE
    {
        msg_notify_data.chg_mask = 0xFF;  // include all state
        msg_notify_data.flag = cnxt->header.flag_latest;
        msg_notify_data.state = cnxt->header.state;
        msg_notify_data.priority = cnxt->header.priority;
        msg_notify_data.attch_num = (U8)cnxt->header.attch_num;
        msg_notify_data.server_size = cnxt->header.server_size;
        msg_notify_data.local_size = cnxt->header.local_size;
        srv_email_om_nofity_msg_from_stor(SRV_EMAIL_OM_NOTIFY_MSG_UPDATE, &msg_notify_data);
        srv_email_om_nofity_fldr_from_stor(SRV_EMAIL_OM_NOTIFY_MSG_UPDATE, &msg_notify_data);
    }

    /* Notify FLDR */
    fldr_notify_data.acct_id = cnxt->acct_id;
    fldr_notify_data.fldr_id = cnxt->fldr_id;
    fldr_notify_data.msg_total_num = cnxt->new_total_num;
    fldr_notify_data.msg_unread_num = cnxt->new_unread_num;
    srv_email_om_nofity_fldr_from_stor(SRV_EMAIL_OM_NOTIFY_FLDR_MSG_NUM_CHG, &fldr_notify_data);

    /* Notify ACCT, only Inbox change need this */
    if (email_stor_fs_fldr_type_is_inbox(cnxt->acct_id, cnxt->fldr_id))
    {
        acct_notify_data.acct_id = cnxt->acct_id;
        acct_notify_data.msg_total_num = cnxt->new_total_num;
        acct_notify_data.msg_unread_num = cnxt->new_unread_num;
        srv_email_om_nofity_acct_from_stor(SRV_EMAIL_OM_NOTIFY_ACCT_MSG_NUM_CHG, &acct_notify_data);
    }

    cnxt->edit_state = EMAIL_STOR_MSG_EIDT_NOTIFY_CHANGE_DONE;
    return SRV_EMAIL_RESULT_SUCC;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_edit_finish
 * DESCRIPTION
 *  Last step of edit msg, notify app the change
 * PARAMETERS
 *  cnxt     [IN]     MSG create context
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_edit_done(
    email_stor_fs_msg_edit_struct *cnxt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_stor_msg_create_funcptr_type callback = cnxt->callback;
    void *user_data = cnxt->user_data;
    EMAIL_MSG_ID created_msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    created_msg_id = email_stor_fs_msg_id_gen(cnxt->acct_id, cnxt->fldr_id, cnxt->offset);
    
    email_stor_fs_msg_edit_handle_set_null(cnxt, cnxt->edit_type);
    email_stor_mfree(cnxt);

    if (callback != NULL)
    {
        callback(SRV_EMAIL_RESULT_SUCC, created_msg_id, user_data);
    }
    return SRV_EMAIL_RESULT_SUCC;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_edit_run
 * DESCRIPTION
 *  Main process function of creating MSG
 * PARAMETERS
 *  cnxt     [IN]     MSG create context
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_msg_edit_error_handle(
    email_stor_fs_msg_edit_struct *cnxt, srv_email_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    WCHAR *tmp_orig_path;
    srv_email_stor_msg_create_funcptr_type callback = cnxt->callback;
    void *user_data = cnxt->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cnxt->saa_hd != EMAIL_STOR_INVALID_FS_HANDLE)
    {
        EMAIL_FS_CLOSE(cnxt->saa_hd);
    }
    if (cnxt->get_msg_id_hd != EMAIL_STOR_INVALID_FS_HANDLE)
    {
        EMAIL_FS_CLOSE(cnxt->get_msg_id_hd);
    }
    email_stor_fs_attch_id_link_free(cnxt->attch_new_header);
    cnxt->attch_new_header = NULL;
    if (cnxt->edit_type == EMAIL_UPDATE)
    {
        email_stor_fs_attch_id_link_free(cnxt->attch_del_header);
        cnxt->attch_del_header = NULL;
    }

    email_stor_fs_msg_edit_handle_set_null(cnxt, cnxt->edit_type);

    // Rename attach to original name
    tmp_orig_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN);
    if (tmp_orig_path == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
    }
    for (i = 0; i < EMAIL_STOR_MAX_ATTACH_NUM; i++)
    {
        if (cnxt->attch_path[i].attch_id != 0)
        {
            email_stor_fs_attch_gen_path(cnxt->attch_path[i].attch_id,
                                         tmp_orig_path);
            FS_Rename(tmp_orig_path,
                      &cnxt->attch_path[i].attch_original_path[0]);
            // Ignore error code
        }
    }
    email_stor_path_mfree(tmp_orig_path);

    email_stor_mfree(cnxt);

    if (callback != NULL)
    {
        callback(result, EMAIL_MSG_INVALID_ID, user_data);
    }
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_edit_fsm
 * DESCRIPTION
 *  FSM function of creating MSG
 * PARAMETERS
 *  cnxt     [IN]     MSG create context
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_msg_edit_fsm(email_stor_fs_msg_edit_struct *cnxt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!email_stor_fs_msg_edit_handle_isvalid(cnxt, cnxt->edit_type))
    {
        return; /* means creating has been aborted */
    }

    // in some cases, error happens in the async process
    if (cnxt->result != SRV_EMAIL_RESULT_SUCC)
    {
        email_stor_fs_msg_edit_error_handle(cnxt, cnxt->result);
        return;
    }

    
    EMAIL_STOR_TRACE_MSG_EDIT_FSM(cnxt->edit_state, 0, result);
    switch (cnxt->edit_state)
    {
        /* get new MSG ID */
        case EMAIL_STOR_MSG_EDIT_INIT:
        case EMAIL_STOR_MSG_EDIT_GET_MSG_ID:
            result = email_stor_fs_msg_edit_get_msg_id(cnxt);
            break;

        /* copy attachments */
        case EMAIL_STOR_MSG_EDIT_GET_MSG_ID_DONE:
        case EMAIL_STOR_MSG_EDIT_COPY_ATTACH:
            if (cnxt->attch_index_to_deal < cnxt->header.attch_num)
            {
                result = email_stor_fs_msg_edit_attch_copy(cnxt);
                break;
            }
            else
            {
                cnxt->edit_state = EMAIL_STOR_MSG_EDIT_COPY_ATTACH_DONE;
            }

        /* init SAA file */
        case EMAIL_STOR_MSG_EDIT_COPY_ATTACH_DONE:
        case EMAIL_STOR_MSG_EDIT_SAA_INIT:
            result = email_stor_fs_msg_edit_init_saa(cnxt);
            break;

        /* write TEXT */
        case EMAIL_STOR_MSG_EDIT_SAA_INIT_DONE:
        case EMAIL_STOR_MSG_EDIT_WRITE_TEXT:
            cnxt->edit_state = EMAIL_STOR_MSG_EDIT_WRITE_TEXT;
            result = email_stor_fs_msg_edit_text_write(cnxt);
            break;

        /* write HTML */
        case EMAIL_STOR_MSG_EDIT_WRITE_TEXT_DONE:
        case EMAIL_STOR_MSG_EDIT_WRITE_HTML:
            cnxt->edit_state = EMAIL_STOR_MSG_EDIT_WRITE_HTML;
            result = email_stor_fs_msg_edit_text_write(cnxt);
            break;

        /* write ADDR */
        case EMAIL_STOR_MSG_EDIT_WRITE_HTML_DONE:
        case EMAIL_STOR_MSG_EDIT_WRITE_ADDR:
            result = email_stor_fs_msg_edit_addr_write(cnxt);
            break;

        /* write ATTCH */
        case EMAIL_STOR_MSG_EDIT_WRITE_ADDR_DONE:
        case EMAIL_STOR_MSG_EDIT_WRITE_ATTACH:
            result = email_stor_fs_msg_edit_attch_write(cnxt);
            break;

        /* write Subject */
        case EMAIL_STOR_MSG_EDIT_WRITE_ATTACH_DONE:
        case EMAIL_STOR_MSG_EDIT_WRITE_SUBJ:
            result = email_stor_fs_msg_edit_subj_write(cnxt);
            break;

        /* write Index */
        case EMAIL_STOR_MSG_EDIT_WRITE_SUBJ_DONE:
        case EMAIL_STOR_MSG_EDIT_WRITE_INDEX:
            result = email_stor_fs_msg_edit_index_write(cnxt);
        /*
            break;

        case EMAIL_STOR_MSG_EDIT_WRITE_INDEX_DONE:
        case EMAIL_STOR_MSG_EIDT_NOTIFY_CHANGE:
        */
        // TO-NOTICE: modify for MAUI_03156440
            if (result == SRV_EMAIL_RESULT_SUCC)
            {
            result = email_stor_fs_msg_edit_change_notify(cnxt);
            }
            break;

        /* release resource and execute callback */
        case EMAIL_STOR_MSG_EIDT_NOTIFY_CHANGE_DONE:
        case EMAIL_STOR_MSG_EDIT_WRITE_DONE:
            result = email_stor_fs_msg_edit_done(cnxt);
            return;
    }

    EMAIL_STOR_TRACE_MSG_EDIT_FSM(cnxt->edit_state, 1, result);

    if (result != SRV_EMAIL_RESULT_SUCC &&
        result != SRV_EMAIL_RESULT_WOULDBLOCK)
    {
        email_stor_fs_msg_edit_error_handle(cnxt, result);
        return;
    }

    if (result == SRV_EMAIL_RESULT_SUCC)
    {
        srv_email_schdl_start_job(
            (srv_email_schdl_funcptr_type) email_stor_fs_msg_edit_fsm, cnxt);
    }

    // if it's SRV_EMAIL_RESULT_WOULDBLOCK, means NO NEED to run fsm
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_move
 * DESCRIPTION
 *  Move a MSG from one folder to another
 * PARAMETERS
 *  from_msg_id     [IN]        Source MSG id
 *  to_acct_id      [IN]        Destination account id
 *  to_fldr_id      [IN]        Destination folder id
 *  to_msg_id       [OUT]       Destination MSG id  
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_move(
                        EMAIL_MSG_ID from_msg_id,
                        EMAIL_ACCT_ID to_acct_id,
                        EMAIL_FLDR_ID to_fldr_id,
                        EMAIL_MSG_ID *to_msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_msg_struct *msg_header;
    WCHAR *from_path;
    WCHAR *to_path;
    EMAIL_STOR_OFFSET to_offset;
    EMAIL_ACCT_ID from_acct_id = email_stor_fs_msg_id_to_acct_id(from_msg_id);
    EMAIL_FLDR_ID from_fldr_id = email_stor_fs_msg_id_to_fldr_id(from_msg_id);
    EMAIL_STOR_OFFSET from_offset = email_stor_fs_msg_id_to_offset(from_msg_id);
    FS_HANDLE from_hd;
    FS_HANDLE to_hd;
    U32 rw;
    MMI_BOOL valid;
    MMI_BOOL from_is_inbox;
    EMAIL_CHECKSUM from_checksum;
    EMAIL_CHECKSUM to_checksum;
    U32 from_new_total_num;
    U32 from_new_unread_num;
    U32 to_new_total_num;
    U32 to_new_unread_num;
    S32 ret;
    srv_email_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(from_acct_id == to_acct_id);
    if (from_fldr_id == to_fldr_id)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }

    from_is_inbox = email_stor_fs_fldr_type_is_inbox(
                        from_acct_id, from_fldr_id);

    result = email_stor_fs_msg_id_create(to_acct_id, to_fldr_id, to_msg_id);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }
    to_offset = email_stor_fs_msg_id_to_offset(*to_msg_id);

    from_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN);
    if (from_path == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    to_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN);
    if (to_path == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        email_stor_path_mfree(from_path);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    msg_header = (email_stor_fs_msg_struct*)
                    email_stor_malloc(sizeof(*msg_header));
    if (msg_header == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(email_stor_fs_msg_struct));
        email_stor_path_mfree(from_path);
        email_stor_path_mfree(to_path);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    /* rename SAA */
    email_stor_fs_msg_parts_gen_path(from_acct_id, from_fldr_id, from_offset,
                                     SRV_EMAIL_STOR_FILE_SAA, from_path);
    email_stor_fs_msg_parts_gen_path(to_acct_id, to_fldr_id, to_offset,
                                     SRV_EMAIL_STOR_FILE_SAA, to_path);
    ret = FS_Rename(from_path, to_path);
    if (ret == FS_FILE_EXISTS)
    {
        FS_Delete(to_path);        
        ret = FS_Rename(from_path, to_path);
    }
    if(ret != FS_NO_ERROR)
    {
        EMAIL_STOR_TRACE_FS_RENAME(ret);
        goto STOR_EXIT_HANDLE;
    }

    /* rename TEXT */
    email_stor_fs_msg_parts_gen_path(from_acct_id,
                                     from_fldr_id,
                                     from_offset,
                                     SRV_EMAIL_STOR_FILE_CONT_TEXT,
                                     from_path);
    email_stor_fs_msg_parts_gen_path(to_acct_id,
                                     to_fldr_id,
                                     to_offset,
                                     SRV_EMAIL_STOR_FILE_CONT_TEXT,
                                     to_path);
    ret = FS_Rename(from_path, to_path);

    /* rename HTML */
    email_stor_fs_msg_parts_gen_path(from_acct_id,
                                     from_fldr_id,
                                     from_offset,
                                     SRV_EMAIL_STOR_FILE_CONT_HTML,
                                     from_path);
    email_stor_fs_msg_parts_gen_path(to_acct_id,
                                     to_fldr_id,
                                     to_offset,
                                     SRV_EMAIL_STOR_FILE_CONT_HTML,
                                     to_path);
    ret = FS_Rename(from_path, to_path);

    /* update INDEX file */
    email_stor_fs_fldr_gen_path(from_acct_id,
                                from_fldr_id,
                                EMAIL_STOR_FLDR_INDEX,
                                from_path);
    email_stor_fs_fldr_gen_path(to_acct_id,
                                to_fldr_id,
                                EMAIL_STOR_FLDR_INDEX,
                                to_path);

    from_hd = EMAIL_FS_OPEN(from_path, FS_READ_WRITE);
    if (EMAIL_STOR_FS_HANDLE_INVALID(from_hd))
    {
        EMAIL_STOR_TRACE_FS_OPEN(from_hd);
        goto STOR_EXIT_HANDLE;
    }

    to_hd = EMAIL_FS_OPEN(to_path, FS_READ_WRITE);
    if (EMAIL_STOR_FS_HANDLE_INVALID(to_hd))
    {
        EMAIL_STOR_TRACE_FS_OPEN(to_hd);
        EMAIL_FS_CLOSE(from_hd);
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_SEEK(from_hd,
                  EMAIL_STOR_MSG_RECORD_POS(from_offset),
                  FS_FILE_BEGIN);
    ret = FS_Read(from_hd, msg_header, sizeof(email_stor_fs_msg_struct), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(email_stor_fs_msg_struct))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        goto STOR_EXIT_HANDLE_CLOSE;
    }

    EMAIL_FS_SEEK(to_hd, EMAIL_STOR_MSG_RECORD_POS(to_offset), FS_FILE_BEGIN);
    ret = FS_Write(to_hd, msg_header, sizeof(email_stor_fs_msg_struct), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(email_stor_fs_msg_struct))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        goto STOR_EXIT_HANDLE_CLOSE;
    }

    valid = MMI_FALSE;
    EMAIL_FS_SEEK(from_hd,
                  EMAIL_STOR_MSG_RECORD_POS(from_offset),
                  FS_FILE_BEGIN);
    ret = FS_Write(from_hd, &valid, sizeof(MMI_BOOL), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(MMI_BOOL))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        goto STOR_EXIT_HANDLE_CLOSE;
    }

    if (!(msg_header->flag_latest & EMAIL_MSG_FLAG_SEEN))   /* unread */
    {
        result = email_stor_fs_msg_num_update(from_hd,
                                              &from_new_unread_num,
                                              -1, EMAIL_STOR_MSG_UNREAD_NUM);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            goto STOR_EXIT_HANDLE_CLOSE;
        }
        
        result = email_stor_fs_msg_num_update(to_hd,
                                              &to_new_unread_num,
                                              1, EMAIL_STOR_MSG_UNREAD_NUM);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            goto STOR_EXIT_HANDLE_CLOSE;
        }

        from_new_unread_num -= 1;
        to_new_unread_num += 1;
    }
    else
    {
        result = email_stor_fs_msg_num_update(from_hd,
                                              &from_new_unread_num,
                                              0, EMAIL_STOR_MSG_UNREAD_NUM);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            goto STOR_EXIT_HANDLE_CLOSE;
        }

        result = email_stor_fs_msg_num_update(to_hd, &to_new_unread_num,
                                              0, EMAIL_STOR_MSG_UNREAD_NUM);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            goto STOR_EXIT_HANDLE_CLOSE;
        }
    }

    result = email_stor_fs_msg_num_update(from_hd, &from_new_total_num,
                                          -1, EMAIL_STOR_MSG_TOTAL_NUM);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        goto STOR_EXIT_HANDLE_CLOSE;
    }

    result = email_stor_fs_msg_num_update(to_hd, &to_new_total_num,
                                          1, EMAIL_STOR_MSG_TOTAL_NUM);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        goto STOR_EXIT_HANDLE_CLOSE;
    }

    from_new_total_num -= 1;
    to_new_total_num += 1;

    // from
    {
        email_stor_p->inbox_index_size = from_new_total_num + 1;
        email_stor_fs_inbox_index_read(from_hd);
        email_stor_fs_inbox_index_del((U16) from_offset);
        email_stor_fs_inbox_index_write(from_hd);

        if (from_is_inbox &&
            !(msg_header->flag_latest & EMAIL_MSG_FLAG_SEEN)
            && from_acct_id != to_acct_id)
        {
            /* unread */
            email_stor_fs_acct_cache_update_msg_unread_chg(from_acct_id, -1);
            email_stor_fs_acct_cache_update_msg_unread_chg(to_acct_id, 1);
        }
    }

    // to
    {
        email_stor_fs_inbox_index_struct note;

        note.offset = (U16) to_offset;
        note.flag = msg_header->flag_latest;
        note.date = msg_header->created_date;

        email_stor_p->inbox_index_size = to_new_total_num - 1;
        email_stor_fs_inbox_index_read(to_hd);
        email_stor_fs_inbox_index_add(&note);
        email_stor_fs_inbox_index_write(to_hd);
    }

    from_checksum = srv_email_checksum_compute_by_hd(from_hd,
                                                     sizeof(EMAIL_CHECKSUM));
    ret = srv_email_checksum_write_by_hd(from_hd, 0, from_checksum);
    if (ret != SRV_EMAIL_RESULT_SUCC)
    {
        goto STOR_EXIT_HANDLE_CLOSE;
    }
    
    to_checksum = srv_email_checksum_compute_by_hd(to_hd,
                                                   sizeof(EMAIL_CHECKSUM));
    ret = srv_email_checksum_write_by_hd(to_hd, 0, to_checksum);
    if (ret != SRV_EMAIL_RESULT_SUCC)
    {
        goto STOR_EXIT_HANDLE_CLOSE;
    }
    
    EMAIL_FS_CLOSE(from_hd);
    EMAIL_FS_CLOSE(to_hd);

    /* update BACKUP file */
    email_stor_fs_fldr_gen_path(from_acct_id,
                                from_fldr_id,
                                EMAIL_STOR_FLDR_BACKUP,
                                from_path);

    email_stor_fs_fldr_gen_path(to_acct_id,
                                to_fldr_id,
                                EMAIL_STOR_FLDR_BACKUP,
                                to_path);

    from_hd = EMAIL_FS_OPEN(from_path, FS_READ_WRITE);
    if (EMAIL_STOR_FS_HANDLE_INVALID(from_hd))
    {
        EMAIL_STOR_TRACE_FS_OPEN(from_hd);
        goto STOR_EXIT_HANDLE;
    }

    to_hd = EMAIL_FS_OPEN(to_path, FS_READ_WRITE);
    if (EMAIL_STOR_FS_HANDLE_INVALID(to_hd))
    {
        EMAIL_STOR_TRACE_FS_OPEN(to_hd);
        EMAIL_FS_CLOSE(from_hd);
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_SEEK(to_hd, EMAIL_STOR_MSG_RECORD_POS(to_offset), FS_FILE_BEGIN);
    ret = FS_Write(to_hd, msg_header, sizeof(email_stor_fs_msg_struct), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(email_stor_fs_msg_struct))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        goto STOR_EXIT_HANDLE_CLOSE;
    }

    valid = MMI_FALSE;
    EMAIL_FS_SEEK(from_hd,
                  EMAIL_STOR_MSG_RECORD_POS(from_offset),
                  FS_FILE_BEGIN);
    ret = FS_Write(from_hd, &valid, sizeof(MMI_BOOL), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(MMI_BOOL))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        goto STOR_EXIT_HANDLE_CLOSE;
    }

    if (!(msg_header->flag_latest & EMAIL_MSG_FLAG_SEEN))   /* unread */
    {
        ret = email_stor_fs_msg_num_update(from_hd, NULL,
                                           -1, EMAIL_STOR_MSG_UNREAD_NUM);
        if (ret != SRV_EMAIL_RESULT_SUCC)
        {
            goto STOR_EXIT_HANDLE_CLOSE;
        }
        ret = email_stor_fs_msg_num_update(to_hd, NULL,
                                           1, EMAIL_STOR_MSG_UNREAD_NUM);
        if (ret != SRV_EMAIL_RESULT_SUCC)
        {
            goto STOR_EXIT_HANDLE_CLOSE;
        }
    }

    ret = email_stor_fs_msg_num_update(
            from_hd, NULL, -1, EMAIL_STOR_MSG_TOTAL_NUM);
    if (ret != SRV_EMAIL_RESULT_SUCC)
    {
        goto STOR_EXIT_HANDLE_CLOSE;
    }
    
    ret = email_stor_fs_msg_num_update(
            to_hd, NULL, 1, EMAIL_STOR_MSG_TOTAL_NUM);
    if (ret != SRV_EMAIL_RESULT_SUCC)
    {
        goto STOR_EXIT_HANDLE_CLOSE;
    }

    ret = srv_email_checksum_write_by_hd(from_hd, 0, from_checksum);
    if (ret != SRV_EMAIL_RESULT_SUCC)
    {
        goto STOR_EXIT_HANDLE_CLOSE;
    }
    ret = srv_email_checksum_write_by_hd(to_hd, 0, to_checksum);
    if (ret != SRV_EMAIL_RESULT_SUCC)
    {
        goto STOR_EXIT_HANDLE_CLOSE;
    }

    // from
    {
        email_stor_p->inbox_index_size = from_new_total_num + 1;
        email_stor_fs_inbox_index_read(from_hd);
        email_stor_fs_inbox_index_del((U16) from_offset);
        email_stor_fs_inbox_index_write(from_hd);

        if (from_is_inbox &&
            !(msg_header->flag_latest & EMAIL_MSG_FLAG_SEEN)
            && from_acct_id != to_acct_id)
        {
            /* unread */
            email_stor_fs_acct_cache_update_msg_unread_chg(from_acct_id, -1);
            email_stor_fs_acct_cache_update_msg_unread_chg(to_acct_id, 1);
        }
    }

    // to
    {
        email_stor_fs_inbox_index_struct note;

        note.offset = (U16) to_offset;
        note.flag = msg_header->flag_latest;
        note.date = msg_header->created_date;

        email_stor_p->inbox_index_size = to_new_total_num - 1;
        email_stor_fs_inbox_index_read(to_hd);
        email_stor_fs_inbox_index_add(&note);
        email_stor_fs_inbox_index_write(to_hd);
    }

    EMAIL_FS_CLOSE(from_hd);
    EMAIL_FS_CLOSE(to_hd);

    /* Notify MSG */
    {
        srv_email_om_notify_msg_struct notify;

        notify.msg_id = from_msg_id;
        srv_email_om_nofity_msg_from_stor(
            SRV_EMAIL_OM_NOTIFY_MSG_DEL, &notify);
        srv_email_om_nofity_fldr_from_stor(
            SRV_EMAIL_OM_NOTIFY_MSG_DEL, &notify);

        notify.msg_id = *to_msg_id;
        srv_email_om_nofity_msg_from_stor(
            SRV_EMAIL_OM_NOTIFY_MSG_ADD, &notify);
        srv_email_om_nofity_fldr_from_stor(
            SRV_EMAIL_OM_NOTIFY_MSG_ADD, &notify);
    }

    /* Notify FLDR */
    {
        srv_email_om_notify_fldr_struct notify;

        notify.acct_id = from_acct_id;
        notify.fldr_id = from_fldr_id;
        notify.msg_unread_num = from_new_unread_num;
        notify.msg_total_num = from_new_total_num;
        srv_email_om_nofity_fldr_from_stor(
            SRV_EMAIL_OM_NOTIFY_FLDR_MSG_NUM_CHG, &notify);

        notify.acct_id = to_acct_id;
        notify.fldr_id = to_fldr_id;
        notify.msg_unread_num = to_new_unread_num;
        notify.msg_total_num = to_new_total_num;
        srv_email_om_nofity_fldr_from_stor(
            SRV_EMAIL_OM_NOTIFY_FLDR_MSG_NUM_CHG, &notify);
    }

    /* Notify ACCT */
    if (from_is_inbox)
    {
        srv_email_om_notify_acct_struct notify;

        notify.acct_id = from_acct_id;
        notify.msg_unread_num = from_new_unread_num;
        notify.msg_total_num = from_new_total_num;
        srv_email_om_nofity_acct_from_stor(
            SRV_EMAIL_OM_NOTIFY_ACCT_MSG_NUM_CHG, &notify);
    }

    email_stor_path_mfree(from_path);
    email_stor_path_mfree(to_path);
    email_stor_mfree(msg_header);
    return SRV_EMAIL_RESULT_SUCC;

STOR_EXIT_HANDLE_CLOSE:
    EMAIL_FS_CLOSE(from_hd);
    EMAIL_FS_CLOSE(to_hd);

STOR_EXIT_HANDLE:
    email_stor_path_mfree(from_path);
    email_stor_path_mfree(to_path);
    email_stor_mfree(msg_header);
    return SRV_EMAIL_RESULT_FS_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_get_addr_open
 * DESCRIPTION
 *  Prepare to get MSG address(s)
 * PARAMETERS
 *  msg_id          [IN]        MSG id
 *  base_index      [IN]        Start index
 *  addr_type       [IN]        Address type
 *  handle          [OUT]       Handle
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_get_addr_open(
                        EMAIL_MSG_ID msg_id,
                        U32 base_index,
                        srv_email_addr_type_enum addr_type,
                        EMAIL_STOR_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    EMAIL_ACCT_ID acct_id = email_stor_fs_msg_id_to_acct_id(msg_id);
    EMAIL_FLDR_ID fldr_id = email_stor_fs_msg_id_to_fldr_id(msg_id);
    EMAIL_STOR_OFFSET offset = email_stor_fs_msg_id_to_offset(msg_id);
    email_stor_fs_msg_get_addr_handle_struct *hd;
    EMAIL_STOR_OFFSET seek_offset;
    U16 to_num;
    U16 cc_num;
    U32 rw;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        *handle = EMAIL_STOR_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    if ((hd = email_stor_malloc(sizeof(*hd))) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(*hd));
        *handle = EMAIL_STOR_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    *handle = hd;

    email_stor_fs_msg_parts_gen_path(acct_id, fldr_id, offset,
                                     SRV_EMAIL_STOR_FILE_SAA, path);

    hd->hd = EMAIL_FS_OPEN(path, FS_READ_ONLY);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd->hd))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd->hd);
        email_stor_path_mfree(path);
        email_stor_mfree(hd);
        *handle = EMAIL_STOR_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    email_stor_path_mfree(path);

    EMAIL_FS_SEEK(hd->hd, EMAIL_STOR_SAA_OFFSET_ADDR_OFFSET, FS_FILE_BEGIN);
    ret = FS_Read(hd->hd, &seek_offset, sizeof(EMAIL_STOR_OFFSET), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_STOR_OFFSET))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    EMAIL_FS_SEEK(hd->hd, seek_offset, FS_FILE_BEGIN);

    switch (addr_type)
    {
        case SRV_EMAIL_ADDR_TYPE_FROM:
            hd->total_num = 1;
            hd->start_offset = seek_offset + 6 * sizeof(U16);
            break;
        case SRV_EMAIL_ADDR_TYPE_REPLY_TO:
            hd->total_num = 1;
            hd->start_offset = seek_offset + 6 * sizeof(U16) +
                               sizeof(srv_email_stor_addr_struct);
            break;
        case SRV_EMAIL_ADDR_TYPE_TO:
            ret = FS_Read(hd->hd, &hd->total_num, sizeof(U16), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(U16))
            {
                EMAIL_STOR_TRACE_FS_READ(ret, rw);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }

            hd->start_offset = seek_offset + 6 * sizeof(U16) +
                               2 * sizeof(srv_email_stor_addr_struct);
            break;
        case SRV_EMAIL_ADDR_TYPE_CC:
            ret = FS_Read(hd->hd, &to_num, sizeof(U16), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(U16))
            {
                EMAIL_STOR_TRACE_FS_READ(ret, rw);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }

            hd->start_offset = seek_offset + 6 * sizeof(U16) +
                               (2+to_num) * sizeof(srv_email_stor_addr_struct);
            ret = FS_Read(hd->hd, &hd->total_num, sizeof(U16), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(U16))
            {
                EMAIL_STOR_TRACE_FS_READ(ret, rw);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }
            break;
        case SRV_EMAIL_ADDR_TYPE_BCC:
            ret = FS_Read(hd->hd, &to_num, sizeof(U16), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(U16))
            {
                EMAIL_STOR_TRACE_FS_READ(ret, rw);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }

            ret = FS_Read(hd->hd, &cc_num, sizeof(U16), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(U16))
            {
                EMAIL_STOR_TRACE_FS_READ(ret, rw);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }

            hd->start_offset = seek_offset + 6 * sizeof(U16) +
                                (2 + to_num + cc_num) *
                                    sizeof(srv_email_stor_addr_struct);
            ret = FS_Read(hd->hd, &hd->total_num, sizeof(U16), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(U16))
            {
                EMAIL_STOR_TRACE_FS_READ(ret, rw);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }

            break;
        default:
            MMI_ASSERT(0);
            break;
    }

    hd->current_index = 0;
    hd->base_index = base_index;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_get_addr_next
 * DESCRIPTION
 *  Get address
 * PARAMETERS
 *  handle                  [IN]        Handle
 *  disp_name_buff_len      [IN]        
 *  addr_buff_len           [IN]        
 *  disp_name               [OUT]       Display name buffer
 *  addr                    [OUT]       Address buffer
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_get_addr_next(
                        EMAIL_STOR_HANDLE handle,
                        U32 disp_name_buff_len,
                        U32 addr_buff_len,
                        CHAR *disp_name,
                        CHAR *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_msg_get_addr_handle_struct *hd;
    srv_email_stor_addr_struct *temp_addr;
    U32 rw;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hd = (email_stor_fs_msg_get_addr_handle_struct*) handle;

    if ((temp_addr = email_stor_malloc(sizeof(*temp_addr))) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(*temp_addr));
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    if (hd->base_index + hd->current_index >= hd->total_num)
    {
        return SRV_EMAIL_RESULT_NO_MORE_RESULT;
    }
    EMAIL_FS_SEEK(
        hd->hd,
        hd->start_offset +(hd->current_index+hd->base_index)*sizeof(*temp_addr),
        FS_FILE_BEGIN);
    ret = FS_Read(hd->hd, temp_addr, sizeof(*temp_addr), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(*temp_addr))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    strncpy(disp_name, temp_addr->disp_name, disp_name_buff_len - 1);
    *(disp_name + disp_name_buff_len - 1) = '\0';
    strncpy(addr, temp_addr->email_addr, addr_buff_len - 1);
    *(addr + addr_buff_len - 1) = '\0';
    hd->current_index++;

    email_stor_mfree(temp_addr);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_get_addr_close
 * DESCRIPTION
 *  Close
 * PARAMETERS
 *  handle      [IN]        Handle
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_get_addr_close(EMAIL_STOR_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_msg_get_addr_handle_struct *hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle == NULL)
    {
        return SRV_EMAIL_RESULT_FAIL;
    }

    hd = (email_stor_fs_msg_get_addr_handle_struct*) handle;
        
    EMAIL_FS_CLOSE(hd->hd);
    email_stor_mfree(hd);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_get_attch_open
 * DESCRIPTION
 *  Prepare for get attach(s)
 * PARAMETERS
 *  msg_id          [IN]        MSG id
 *  base_index      [IN]        Start index
 *  handle          [OUT]       Handle
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_get_attch_open(
    EMAIL_MSG_ID msg_id,
    U32 base_index,
    EMAIL_STOR_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    WCHAR *path;
    U32 rw;
    EMAIL_STOR_OFFSET seek_offset;
    email_stor_fs_msg_get_attch_handle_struct *hd;
    EMAIL_ACCT_ID acct_id = email_stor_fs_msg_id_to_acct_id(msg_id);
    EMAIL_FLDR_ID fldr_id = email_stor_fs_msg_id_to_fldr_id(msg_id);
    EMAIL_STOR_OFFSET offset = email_stor_fs_msg_id_to_offset(msg_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        *handle = EMAIL_STOR_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    if ((hd = email_stor_malloc(sizeof(*hd))) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(*hd));
        email_stor_path_mfree(path);
        *handle = EMAIL_STOR_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    *handle = hd;

    email_stor_fs_msg_parts_gen_path(acct_id, fldr_id, offset,
                                     SRV_EMAIL_STOR_FILE_SAA, path);

    hd->hd = EMAIL_FS_OPEN(path, FS_READ_ONLY);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd->hd))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd->hd);
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_SEEK(hd->hd, EMAIL_STOR_SAA_OFFSET_ATTCH_OFFSET, FS_FILE_BEGIN);
    ret = FS_Read(hd->hd, &seek_offset, sizeof(EMAIL_STOR_OFFSET), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_STOR_OFFSET))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd->hd);
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_SEEK(hd->hd, seek_offset, FS_FILE_BEGIN);
    ret = FS_Read(hd->hd, &hd->total_num, sizeof(U32), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd->hd);
        goto STOR_EXIT_HANDLE;
    }

    /* sizeof(U32) * 2, for attch_num, remain_attach_num */
    hd->start_offset = seek_offset + sizeof(U32) * 2;
    hd->base_index = base_index;

    hd->current_index = 0;

    email_stor_path_mfree(path);
    
    return SRV_EMAIL_RESULT_SUCC;

STOR_EXIT_HANDLE:
    email_stor_path_mfree(path);
    email_stor_mfree(hd);
    *handle = EMAIL_STOR_INVALID_HANDLE;
    return SRV_EMAIL_RESULT_FS_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_get_attch_next
 * DESCRIPTION
 *  Get attach info
 * PARAMETERS
 *  handle      [IN]        Handle
 *  attch       [OUT]       Attach info
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_get_attch_next(
    EMAIL_STOR_HANDLE handle,
    srv_email_stor_attch_struct *attch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_msg_get_addr_handle_struct *hd;
    U32 rw;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hd = (email_stor_fs_msg_get_addr_handle_struct*) handle;
    if (hd->base_index + hd->current_index + 1 > hd->total_num)
    {
        return SRV_EMAIL_RESULT_NO_MORE_RESULT;
    }
    EMAIL_FS_SEEK(
        hd->hd,
        hd->start_offset + (hd->current_index+hd->base_index) * sizeof(*attch),
        FS_FILE_BEGIN);
    ret = FS_Read(hd->hd, attch, sizeof(*attch), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(*attch))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    hd->current_index++;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_get_attch_close
 * DESCRIPTION
 *  Close
 * PARAMETERS
 *  handle      [IN]        Handle
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_get_attch_close(
    EMAIL_STOR_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_msg_get_attch_handle_struct *hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle == NULL)
    {
        return SRV_EMAIL_RESULT_FAIL;
    }

    hd = (email_stor_fs_msg_get_attch_handle_struct*) handle;
    EMAIL_FS_CLOSE(hd->hd);
    email_stor_mfree(hd);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_get_attch_path
 * DESCRIPTION
 *  Get a attach file path by attach id
 * PARAMETERS
 *  attch_id        [IN]        Attach id
 *  attch_path      [OUT]       Attach file path
 *  buff_size       [IN]        Buffer size
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_get_attch_path(
    EMAIL_ATTCH_ID attch_id,
    WCHAR *attch_path,
    U32 buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    srv_email_result_enum res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_attch_gen_path(attch_id, path);
    if (buff_size >= ((U32) mmi_wcslen(path) + 1) * sizeof(WCHAR))
    {
        mmi_wcscpy(attch_path, path);
        res = SRV_EMAIL_RESULT_SUCC;
    }
    else
    {
        res = SRV_EMAIL_RESULT_FAIL;
    }

    email_stor_path_mfree(path);
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_get_attch_id
 * DESCRIPTION
 *  Get a MSG's attach id(s), add these id(s) to the linked list
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  fldr_id     [IN]        Folder id
 *  offset      [IN]        Offset
 *  header      [IN]        Attach id note linked list header
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_get_attch_id(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        EMAIL_STOR_OFFSET offset,
                        email_stor_attch_id_link_struct **header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 ret;
    U32 rw;
    U32 attch_bgn_offset;
    U32 attch_record_num;
    WCHAR *path;
    FS_HANDLE hd;
    email_stor_attch_id_link_struct *tail = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_msg_parts_gen_path(acct_id, fldr_id, offset,
                                     SRV_EMAIL_STOR_FILE_SAA, path);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        email_stor_path_mfree(path);
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    email_stor_path_mfree(path);

    EMAIL_FS_SEEK(hd, EMAIL_STOR_SAA_OFFSET_ATTCH_OFFSET, FS_FILE_BEGIN);
    ret = FS_Read(hd, &attch_bgn_offset, sizeof(U32), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    EMAIL_FS_SEEK(hd, attch_bgn_offset, FS_FILE_BEGIN);

    ret = FS_Read(hd, &attch_record_num, sizeof(U32), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    /* for attch_remain_num */
    EMAIL_FS_SEEK(hd, sizeof(U32), FS_FILE_CURRENT);

    if (attch_record_num > 0)
    {
        if (*header == NULL)
        {
            if ((tail = *header = email_stor_malloc(sizeof(*tail))) == NULL)
            {
                EMAIL_STOR_TRACE_MALLOC(sizeof(*tail));
                EMAIL_FS_CLOSE(hd);
                return SRV_EMAIL_RESULT_NO_MEMORY;
            }
        }
        else
        {
            tail = *header;
            while (tail->next != NULL)
            {
                tail = tail->next;
            }
            if ((tail->next = email_stor_malloc(sizeof(*(tail->next)))) == NULL)
            {
                EMAIL_STOR_TRACE_MALLOC(sizeof(*(tail->next)));
                EMAIL_FS_CLOSE(hd);
                return SRV_EMAIL_RESULT_NO_MEMORY;
            }
            tail = tail->next;
        }
    }

    for (i = 0; i < attch_record_num; i++)
    {
        if (i != 0)
        {
            if ((tail->next = email_stor_malloc(sizeof(*(tail->next)))) == NULL)
            {
                EMAIL_STOR_TRACE_MALLOC(sizeof(*(tail->next)));
                EMAIL_FS_CLOSE(hd);
                return SRV_EMAIL_RESULT_NO_MEMORY;
            }
            tail = tail->next;
        }
        ret = FS_Read(hd, &tail->attch_id, sizeof(EMAIL_ATTCH_ID), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_ATTCH_ID))
        {
            EMAIL_STOR_TRACE_FS_READ(ret, rw);
            tail->attch_id = EMAIL_STOR_ATTCH_INVALID_ID;
            EMAIL_FS_CLOSE(hd);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        tail->next = NULL;
        if (i + 1 == attch_record_num)
        {
            break;
        }
        EMAIL_FS_SEEK(
            hd, sizeof(srv_email_stor_attch_struct) - sizeof(EMAIL_ATTCH_ID),
            FS_FILE_CURRENT);
    }
    EMAIL_FS_CLOSE(hd);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_get_cont
 * DESCRIPTION
 *  Get content
 * PARAMETERS
 *  msg_id          [IN]            MSG id
 *  type            [IN]            Content type
 *  cont_header     [OUT]           Content header
 *  cont_path       [OUT]           Content file path in FS
 *  size            [IN/OUT]        Buffer size
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_get_cont(
                        EMAIL_MSG_ID msg_id,
                        srv_email_stor_msg_cont_type type,
                        srv_email_stor_cont_header_struct *cont_header,
                        WCHAR *cont_path,
                        U32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 rw;
    U32 cont_header_pos;
    WCHAR *path;
    FS_HANDLE hd;
    EMAIL_ACCT_ID acct_id = email_stor_fs_msg_id_to_acct_id(msg_id);
    EMAIL_FLDR_ID fldr_id = email_stor_fs_msg_id_to_fldr_id(msg_id);
    EMAIL_STOR_OFFSET offset = email_stor_fs_msg_id_to_offset(msg_id);
    srv_email_stor_cont_header_struct *cont_header_temp;
    srv_email_stor_file_enum file_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(!(cont_header == NULL && cont_path == NULL && size == NULL));
    MMI_ASSERT((cont_path != NULL && size != NULL) ||
               (cont_path == NULL && size == NULL));

    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    cont_header_temp = email_stor_malloc(sizeof(*cont_header_temp));
    if (cont_header_temp == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(srv_email_stor_cont_header_struct));
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    /* open SAA to get this numbers */
    email_stor_fs_msg_parts_gen_path(acct_id, fldr_id, offset,
                                     SRV_EMAIL_STOR_FILE_SAA, path);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    EMAIL_FS_SEEK(hd, EMAIL_STOR_SAA_OFFSET_CONT_HEADER_OFFSET, FS_FILE_BEGIN);
    ret = FS_Read(hd, &cont_header_pos, sizeof(U32), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        
    }

    EMAIL_FS_SEEK(hd, cont_header_pos, FS_FILE_BEGIN);

    /* for HTML */
    if (type == SRV_EMAIL_STOR_MSG_CONT_HTML)
    {
        EMAIL_FS_SEEK(hd, sizeof(*cont_header_temp), FS_FILE_CURRENT);
    }

    /* read header */
    ret = FS_Read(hd, cont_header_temp, sizeof(*cont_header_temp), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(*cont_header_temp))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        
    }

    EMAIL_FS_CLOSE(hd);

    /* fill header */
    if (cont_header != NULL)
    {
        memcpy(cont_header, cont_header_temp, sizeof(*cont_header_temp));
    }

    /* NOT downloaded */
    if (!(cont_header_temp->download_flag))
    {
        email_stor_path_mfree(path);
        email_stor_mfree(cont_header_temp);
        if (cont_path != NULL)
        {
            *cont_path = 0;
            *size = 0;
        }
        return SRV_EMAIL_RESULT_SUCC;
    }
    email_stor_mfree(cont_header_temp);

    switch (type)
    {
        case SRV_EMAIL_STOR_MSG_CONT_TEXT:
            file_type = SRV_EMAIL_STOR_FILE_CONT_TEXT;
            break;
        case SRV_EMAIL_STOR_MSG_CONT_HTML:
            file_type = SRV_EMAIL_STOR_FILE_CONT_HTML;
            break;
        default:
            file_type = SRV_EMAIL_STOR_FILE_TOTAL;
            MMI_ASSERT(0);
    }

    /* open Cont file (TEXT/HTML) */
    email_stor_fs_msg_parts_gen_path(acct_id, fldr_id, offset, file_type, path);
    if (cont_path != NULL)
    {
        if (mmi_wcslen(path) >= (S32) * size)
        {
            email_stor_path_mfree(path); /* buff size is not enough */
            return SRV_EMAIL_RESULT_FAIL;
        }
        mmi_wcscpy(cont_path, path);
        *size = mmi_wcslen(path);
    }
    email_stor_path_mfree(path);

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_get_flag_state
 * DESCRIPTION
 *  Set a flag to MSG
 * PARAMETERS
 *  msg_id      [IN]        MSG id
 *  flag        [IN]        MSG Flag
 *  state       [OUT]       MSG state
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_get_flag_state(
                        EMAIL_MSG_ID msg_id,
                        EMAIL_MSG_FLAG *flag,
                        EMAIL_MSG_STATE *state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    MMI_BOOL valid;
    U32 rw;
    WCHAR *path;
    FS_HANDLE hd;
    EMAIL_ACCT_ID acct_id = email_stor_fs_msg_id_to_acct_id(msg_id);
    EMAIL_FLDR_ID fldr_id = email_stor_fs_msg_id_to_fldr_id(msg_id);
    EMAIL_STOR_OFFSET offset = email_stor_fs_msg_id_to_offset(msg_id);
    EMAIL_STOR_OFFSET pos_end = 0;
    EMAIL_STOR_OFFSET pos_new = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(flag != NULL || state != NULL);

    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_fldr_gen_path(acct_id, fldr_id, EMAIL_STOR_FLDR_INDEX, path);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    email_stor_path_mfree(path);

    if ((ret = FS_GetFileSize(hd, &pos_end)) < FS_NO_ERROR)
    {
        EMAIL_STOR_TRACE_FS_OPEN(ret);
        goto STOR_EXIT_HANDLE;
    }
    pos_new = EMAIL_STOR_MSG_RECORD_POS(offset);
    if (pos_new >= pos_end)
    {
        EMAIL_FS_CLOSE(hd);
        return SRV_EMAIL_RESULT_INVALID_MSG;
    }

    EMAIL_FS_SEEK(hd, pos_new, FS_FILE_BEGIN);
    ret = FS_Read(hd, &valid, sizeof(MMI_BOOL), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(MMI_BOOL))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        goto STOR_EXIT_HANDLE;
    }

    if (rw != sizeof(MMI_BOOL) || (!valid))
    {
        EMAIL_FS_CLOSE(hd);
        return SRV_EMAIL_RESULT_INVALID_MSG;   /* this offset not exist */
    }

    if (flag != NULL)
    {
        EMAIL_FS_SEEK(hd, EMAIL_STOR_MSG_LATEST_FLAG_POS(offset),FS_FILE_BEGIN);
        ret = FS_Read(hd, flag, sizeof(EMAIL_MSG_FLAG), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_FLAG))
        {
            EMAIL_STOR_TRACE_FS_READ(ret, rw);
            goto STOR_EXIT_HANDLE;
        }
    }

    if (state != NULL)
    {
        EMAIL_FS_SEEK(hd, EMAIL_STOR_MSG_STATE_POS(offset), FS_FILE_BEGIN);
        ret = FS_Read(hd, state, sizeof(EMAIL_MSG_STATE), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_STATE))
        {
            EMAIL_STOR_TRACE_FS_READ(ret, rw);
            goto STOR_EXIT_HANDLE;
        }
    }
    EMAIL_FS_CLOSE(hd);
    return SRV_EMAIL_RESULT_SUCC;

STOR_EXIT_HANDLE:
    EMAIL_FS_CLOSE(hd);
    return SRV_EMAIL_RESULT_FS_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_get_header
 * DESCRIPTION
 *  Get MSG header
 * PARAMETERS
 *  msg_id      [IN]        MSG id
 *  header      [OUT]       MSG header
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_get_header(
    EMAIL_MSG_ID msg_id,
    srv_email_stor_msg_get_header_struct *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_email_result_enum result;
    MMI_BOOL valid;
    U32 rw;
    WCHAR *path;
    FS_HANDLE hd;
    EMAIL_ACCT_ID acct_id = email_stor_fs_msg_id_to_acct_id(msg_id);
    EMAIL_FLDR_ID fldr_id = email_stor_fs_msg_id_to_fldr_id(msg_id);
    EMAIL_STOR_OFFSET offset = email_stor_fs_msg_id_to_offset(msg_id);
    email_stor_fs_msg_struct *temp_msg;
    srv_email_stor_addr_struct *addr;
    U32 addr_start_pos;
    U32 attch_start_pos;
    U32 attch_remain_num;
    U32 cont_size;
    EMAIL_STOR_OFFSET pos_end = 0;
    EMAIL_STOR_OFFSET pos_new = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    if ((temp_msg = email_stor_malloc(sizeof(*temp_msg))) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(*temp_msg));
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    if ((addr = email_stor_malloc(sizeof(*addr))) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(*addr));
        email_stor_path_mfree(path);
        email_stor_mfree(addr);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    
    email_stor_fs_fldr_gen_path(acct_id, fldr_id, EMAIL_STOR_FLDR_INDEX, path);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }

    if ((ret = FS_GetFileSize(hd, &pos_end)) < FS_NO_ERROR)
    {
        EMAIL_STOR_TRACE_FS_OPEN(ret);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }

    pos_new = EMAIL_STOR_MSG_RECORD_POS(offset);

    /* this offset exceed max position */
    if (pos_new >= pos_end)
    {
        EMAIL_FS_CLOSE(hd);
        result = SRV_EMAIL_RESULT_INVALID_MSG;
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_SEEK(hd, pos_new, FS_FILE_BEGIN);
    ret = FS_Read(hd, &valid, sizeof(MMI_BOOL), &rw);

    /* this offset not exist */
    if (ret != FS_NO_ERROR || rw != sizeof(MMI_BOOL))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }

    /* this offset NOT valid */
    if (!valid)
    {
        EMAIL_FS_CLOSE(hd);
        result = SRV_EMAIL_RESULT_INVALID_MSG;
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_SEEK(hd, pos_new, FS_FILE_BEGIN);
    ret = FS_Read(hd, temp_msg, sizeof(email_stor_fs_msg_struct), &rw);
    EMAIL_FS_CLOSE(hd);
    if (ret != FS_NO_ERROR || rw != sizeof(email_stor_fs_msg_struct))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }

    header->msg_id = msg_id;
    header->uid_validity = temp_msg->uid_validity;
    header->uid = temp_msg->uid;
    memcpy(header->uidl, temp_msg->uidl, SRV_EMAIL_MD5_DIGEST_LEN);
    memcpy(header->acct_digest, temp_msg->acct_digest,SRV_EMAIL_MD5_DIGEST_LEN);
    temp_msg->addr_disp_name[EMAIL_MAX_ENCODED_DISP_NAME_LEN] = 0;
    temp_msg->addr_email[EMAIL_MAX_ENCODED_ADDR_LEN] = 0;
    strcpy(header->disp_name, temp_msg->addr_disp_name);
    strcpy(header->email_addr, temp_msg->addr_email);
    header->flag = temp_msg->flag_latest;
    header->state = temp_msg->state;
    header->priority = temp_msg->priority;
    header->created_date = temp_msg->created_date;
    header->received_date = temp_msg->received_date;
    header->local_size = temp_msg->local_size;
    header->server_size = temp_msg->server_size;
    header->attch_num = temp_msg->attch_num;

    /* open SAA */
    email_stor_fs_msg_parts_gen_path(acct_id, fldr_id, offset,
                                     SRV_EMAIL_STOR_FILE_SAA, path);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }

    /* addr start position */
    EMAIL_FS_SEEK(hd, EMAIL_STOR_SAA_OFFSET_ADDR_OFFSET, FS_FILE_BEGIN);
    ret = FS_Read(hd, &addr_start_pos, sizeof(U32), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }

    /* attch start position */
    EMAIL_FS_SEEK(hd, EMAIL_STOR_SAA_OFFSET_ATTCH_OFFSET, FS_FILE_BEGIN);
    ret = FS_Read(hd, &attch_start_pos, sizeof(U32), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }

    /* to num */
    EMAIL_FS_SEEK(hd, addr_start_pos, FS_FILE_BEGIN);
    ret = FS_Read(hd, &header->addr_to_num, sizeof(U16), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U16))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }

    /* cc num */
    ret = FS_Read(hd, &header->addr_cc_num, sizeof(U16), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U16))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }

    /* bcc num */
    ret = FS_Read(hd, &header->addr_bcc_num, sizeof(U16), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U16))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }

    /* remain to num */
    ret = FS_Read(hd, &header->remain_addr_to_num, sizeof(U16), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U16))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }

    /* remain cc num */
    ret = FS_Read(hd, &header->remain_addr_cc_num, sizeof(U16), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U16))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }

    /* remain bcc num */
    ret = FS_Read(hd, &header->remain_addr_bcc_num, sizeof(U16), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U16))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }

    /* from addr */
    ret = FS_Read(hd, addr, sizeof(srv_email_stor_addr_struct), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(srv_email_stor_addr_struct))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }
    header->addr_from = (strlen(addr->email_addr) != 0 ? MMI_TRUE : MMI_FALSE);

    /* reply_to addr */
    ret = FS_Read(hd, addr, sizeof(srv_email_stor_addr_struct), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(srv_email_stor_addr_struct))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }

    header->addr_reply_to = (strlen(addr->email_addr) ? MMI_TRUE : MMI_FALSE);

    /* remain attch num */
    EMAIL_FS_SEEK(hd, attch_start_pos + sizeof(U32), FS_FILE_BEGIN);
    ret = FS_Read(hd, &attch_remain_num, sizeof(U32), &rw);
    header->remain_attach_num = (U16)attch_remain_num;
    if (ret != FS_NO_ERROR || rw != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }
    
    /* read TEXT size */
    EMAIL_FS_SEEK(
        hd,
        EMAIL_STOR_SAA_CONT_HEADER_POS +
        EMAIL_STOR_POS_IN_STRUCT(srv_email_stor_cont_header_struct,server_size),
        FS_FILE_BEGIN);
    ret = FS_Read(hd, &cont_size, sizeof(U32), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }
    header->has_text = (cont_size != 0 ? MMI_TRUE : MMI_FALSE);

    /* read HTML size */
    EMAIL_FS_SEEK(hd,
                  sizeof(srv_email_stor_cont_header_struct) - sizeof(U32),
                  FS_FILE_CURRENT);
    ret = FS_Read(hd, &cont_size, sizeof(U32), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }
    header->has_html = (cont_size != 0 ? MMI_TRUE : MMI_FALSE);
    EMAIL_FS_CLOSE(hd);
    result = SRV_EMAIL_RESULT_SUCC;
    
STOR_EXIT_HANDLE:
    email_stor_mfree(addr);
    email_stor_mfree(temp_msg);
    email_stor_path_mfree(path);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_get_subj_len
 * DESCRIPTION
 *  Get subject length
 * PARAMETERS
 *  msg_id      [IN]        MSG id
 * RETURNS
 *  subject length
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_get_subj_len(
    EMAIL_MSG_ID msg_id,
    U32 *subj_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 rw;
    U32 subj_offset;
    WCHAR *path;
    FS_HANDLE hd;
    EMAIL_ACCT_ID acct_id = email_stor_fs_msg_id_to_acct_id(msg_id);
    EMAIL_FLDR_ID fldr_id = email_stor_fs_msg_id_to_fldr_id(msg_id);
    EMAIL_STOR_OFFSET offset = email_stor_fs_msg_id_to_offset(msg_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    /* open SAA to get this numbers */
    email_stor_fs_msg_parts_gen_path(acct_id, fldr_id, offset,
                                     SRV_EMAIL_STOR_FILE_SAA, path);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    /* get subject's position in file */
    EMAIL_FS_SEEK(hd, EMAIL_STOR_SAA_OFFSET_SUBJ_OFFSET, FS_FILE_BEGIN);
    ret = FS_Read(hd, &subj_offset, sizeof(U32), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        goto STOR_EXIT_HANDLE;
    }

    /* seek to the position, and read the subject len */
    EMAIL_FS_SEEK(hd, subj_offset, FS_FILE_BEGIN);
    ret = FS_Read(hd, subj_len, sizeof(U32), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_CLOSE(hd);
    email_stor_path_mfree(path);
    return SRV_EMAIL_RESULT_SUCC;

STOR_EXIT_HANDLE:
    EMAIL_FS_CLOSE(hd);
    email_stor_path_mfree(path);
    return SRV_EMAIL_RESULT_FS_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_get_subj
 * DESCRIPTION
 *  Get subject
 * PARAMETERS
 *  msg_id          [IN]            MSG id
 *  subj            [OUT]           Subject buffer
 *  buffer_size     [IN/OUT]        Buffer size
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_get_subj(
    EMAIL_MSG_ID msg_id,
    CHAR *subj,
    U32 *buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 rw;
    U32 subj_offset;
    U32 subj_len;
    U32 read_len;
    WCHAR *path;
    FS_HANDLE hd;
    EMAIL_ACCT_ID acct_id = email_stor_fs_msg_id_to_acct_id(msg_id);
    EMAIL_FLDR_ID fldr_id = email_stor_fs_msg_id_to_fldr_id(msg_id);
    EMAIL_STOR_OFFSET offset = email_stor_fs_msg_id_to_offset(msg_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    /* open SAA to get this numbers */
    email_stor_fs_msg_parts_gen_path(acct_id, fldr_id, offset,
                                     SRV_EMAIL_STOR_FILE_SAA, path);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    email_stor_path_mfree(path);

    EMAIL_FS_SEEK(hd, EMAIL_STOR_SAA_OFFSET_SUBJ_OFFSET, FS_FILE_BEGIN);
    ret = FS_Read(hd, &subj_offset, sizeof(U32), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        
    }

    EMAIL_FS_SEEK(hd, subj_offset, FS_FILE_BEGIN);
    ret = FS_Read(hd, &subj_len, sizeof(U32), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        
    }

    read_len = SRV_EMAIL_MIN(subj_len, *buffer_size - 1);
    if (read_len > 0)
    {
        ret = FS_Read(hd, subj, read_len, &rw);
        if (ret != FS_NO_ERROR || rw != read_len)
        {
            EMAIL_STOR_TRACE_FS_READ(ret, rw);
            
        }
    }
    *(subj + read_len) = '\0';
    *buffer_size = read_len;
    EMAIL_FS_CLOSE(hd);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_cont_exist
 * DESCRIPTION
 *  Get whether content exist
 *  please reference [srv_email_msg_cont_exit_enum]
 * PARAMETERS
 *  msg_id              [IN]        MSG id
 *  text_exist_mask     [OUT]       text part exist mask
 *  html_exist_mask     [OUT]       HTML part exist mask
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_cont_exist(
    EMAIL_MSG_ID msg_id,
    S8 *text_exist_mask,
    S8 *html_exist_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 rw;
    WCHAR *path;
    FS_HANDLE hd;
    EMAIL_ACCT_ID acct_id = email_stor_fs_msg_id_to_acct_id(msg_id);
    EMAIL_FLDR_ID fldr_id = email_stor_fs_msg_id_to_fldr_id(msg_id);
    EMAIL_STOR_OFFSET offset = email_stor_fs_msg_id_to_offset(msg_id);
    srv_email_stor_cont_header_struct *temp_cont_header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    /* open SAA to get these numbers */
    email_stor_fs_msg_parts_gen_path(acct_id, fldr_id, offset,
                                     SRV_EMAIL_STOR_FILE_SAA, path);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    email_stor_path_mfree(path);

    temp_cont_header = email_stor_malloc(sizeof(*temp_cont_header));
    if (temp_cont_header == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(*temp_cont_header));
        EMAIL_FS_CLOSE(hd);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    /* TEXT */
    EMAIL_FS_SEEK(hd, EMAIL_STOR_SAA_CONT_HEADER_POS, FS_FILE_BEGIN);
    ret = FS_Read(hd, temp_cont_header, sizeof(*temp_cont_header), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(*temp_cont_header))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        
        email_stor_mfree(temp_cont_header);
        EMAIL_FS_CLOSE(hd);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    if (temp_cont_header->this_part_exist)
    {
        *text_exist_mask = SRV_EMAIL_MSG_CONT_PART_EXIST;
        if (temp_cont_header->download_flag)
        {
            *text_exist_mask |= SRV_EMAIL_MSG_CONT_DOWNLOADED;
        }
    }

    /* HTML */
    ret = FS_Read(hd, temp_cont_header, sizeof(*temp_cont_header), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(*temp_cont_header))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        
        email_stor_mfree(temp_cont_header);
        EMAIL_FS_CLOSE(hd);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    if (temp_cont_header->this_part_exist)
    {
        *html_exist_mask = SRV_EMAIL_MSG_CONT_PART_EXIST;
        if (temp_cont_header->download_flag)
        {
            *html_exist_mask |= SRV_EMAIL_MSG_CONT_DOWNLOADED;
        }
    }

    email_stor_mfree(temp_cont_header);
    EMAIL_FS_CLOSE(hd);

    return SRV_EMAIL_RESULT_SUCC;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_cont_size
 * DESCRIPTION
 *  Get whether content exist
 *  please reference [srv_email_msg_cont_exit_enum]
 * PARAMETERS
 *  msg_id          [IN]        MSG id
 *  text_size       [OUT]       Text part size
 *  html_size       [OUT]       HTML part size
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_cont_size(
    EMAIL_MSG_ID msg_id,
    U32 *text_size,
    U32 *html_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 rw;
    WCHAR *path;
    FS_HANDLE hd;
    EMAIL_ACCT_ID acct_id = email_stor_fs_msg_id_to_acct_id(msg_id);
    EMAIL_FLDR_ID fldr_id = email_stor_fs_msg_id_to_fldr_id(msg_id);
    EMAIL_STOR_OFFSET offset = email_stor_fs_msg_id_to_offset(msg_id);
    srv_email_stor_cont_header_struct *temp_cont_header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    /* open SAA to get this numbers */
    email_stor_fs_msg_parts_gen_path(acct_id, fldr_id, offset,
                                     SRV_EMAIL_STOR_FILE_SAA, path);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    email_stor_path_mfree(path);

    temp_cont_header = email_stor_malloc(sizeof(*temp_cont_header));
    if (temp_cont_header == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(*temp_cont_header));
        EMAIL_FS_CLOSE(hd);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    /* TEXT */
    EMAIL_FS_SEEK(hd, EMAIL_STOR_SAA_CONT_HEADER_POS, FS_FILE_BEGIN);
    ret = FS_Read(hd, temp_cont_header, sizeof(*temp_cont_header), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(*temp_cont_header))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        
        email_stor_mfree(temp_cont_header);
        EMAIL_FS_CLOSE(hd);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    if (temp_cont_header->this_part_exist)
    {
        *text_size = temp_cont_header->server_size;
    }

    /* HTML */
    ret = FS_Read(hd, temp_cont_header, sizeof(*temp_cont_header), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(*temp_cont_header))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        
        email_stor_mfree(temp_cont_header);
        EMAIL_FS_CLOSE(hd);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    if (temp_cont_header->this_part_exist)
    {
        *html_size= temp_cont_header->server_size;
    }

    email_stor_mfree(temp_cont_header);
    EMAIL_FS_CLOSE(hd);

    return SRV_EMAIL_RESULT_SUCC;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_get_cont_len
 * DESCRIPTION
 *  Get content length
 * PARAMETERS
 *  msg_id      [IN]        MSG id
 *  type        [IN]        Content type
 * RETURNS
 *  Get content length
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_get_cont_len(
    EMAIL_MSG_ID msg_id,
    srv_email_stor_msg_cont_type type,
    U32 *cont_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 rw;
    WCHAR *path;
    FS_HANDLE hd;
    EMAIL_ACCT_ID acct_id = email_stor_fs_msg_id_to_acct_id(msg_id);
    EMAIL_FLDR_ID fldr_id = email_stor_fs_msg_id_to_fldr_id(msg_id);
    EMAIL_STOR_OFFSET offset = email_stor_fs_msg_id_to_offset(msg_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(type == SRV_EMAIL_STOR_MSG_CONT_TEXT ||
               type == SRV_EMAIL_STOR_MSG_CONT_HTML);

    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    /* open SAA to get this numbers */
    email_stor_fs_msg_parts_gen_path(acct_id, fldr_id, offset,
                                     SRV_EMAIL_STOR_FILE_SAA, path);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    email_stor_path_mfree(path);

    EMAIL_FS_SEEK(hd, EMAIL_STOR_SAA_CONT_HEADER_POS, FS_FILE_BEGIN);

    if (type == SRV_EMAIL_STOR_MSG_CONT_TEXT)
    {
        EMAIL_FS_SEEK(
            hd,
            sizeof(srv_email_stor_cont_header_struct) * 0 +
            EMAIL_STOR_POS_IN_STRUCT(srv_email_stor_cont_header_struct,
                                     local_size),
            FS_FILE_CURRENT);
    }
    else if (type == SRV_EMAIL_STOR_MSG_CONT_HTML)
    {
        EMAIL_FS_SEEK(
            hd,
            sizeof(srv_email_stor_cont_header_struct) * 1 +
            EMAIL_STOR_POS_IN_STRUCT(srv_email_stor_cont_header_struct,
                                     local_size),
            FS_FILE_CURRENT);
    }

    ret = FS_Read(hd, cont_len, sizeof(U32), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    EMAIL_FS_CLOSE(hd);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_check_cont_download_all
 * DESCRIPTION
 *  Check whether text & html downloaded
 * PARAMETERS
 *  hd                  [IN]        FS handle
 *  download_all        [OUT]       Whether text & html has been downloaded,
 *                                  if any one not, it will be set as MMI_FALSE
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_check_cont_download_all(
    FS_HANDLE hd, MMI_BOOL *download_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 rw;
    U32 seek_offset;
    srv_email_stor_cont_header_struct *cont_header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((cont_header = email_stor_malloc(sizeof(*cont_header))) == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    EMAIL_FS_SEEK(hd, EMAIL_STOR_SAA_OFFSET_CONT_HEADER_OFFSET, FS_FILE_BEGIN);
    ret = FS_Read(hd, &seek_offset, sizeof(EMAIL_STOR_OFFSET), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_STOR_OFFSET))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_SEEK(hd, seek_offset, FS_FILE_BEGIN);

    /* handle TEXT */
    ret = FS_Read(hd, cont_header, sizeof(*cont_header), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(*cont_header))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        goto STOR_EXIT_HANDLE;
    }

    if (cont_header->this_part_exist && !cont_header->download_flag)
    {
        *download_all = MMI_FALSE;
        email_stor_mfree(cont_header);
        return SRV_EMAIL_RESULT_SUCC;
    }

    /* handle HTML */
    ret = FS_Read(hd, cont_header, sizeof(*cont_header), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(*cont_header))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        goto STOR_EXIT_HANDLE;
    }

    if (cont_header->this_part_exist && !cont_header->download_flag)
    {
        *download_all = MMI_FALSE;
        email_stor_mfree(cont_header);
        return SRV_EMAIL_RESULT_SUCC;
    }

    *download_all = MMI_TRUE;
    email_stor_mfree(cont_header);
    return SRV_EMAIL_RESULT_SUCC;

STOR_EXIT_HANDLE:
    email_stor_mfree(cont_header);
    return SRV_EMAIL_RESULT_FS_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_check_download_all_for_load_attch
 * DESCRIPTION
 *  Check whether text & HTML & ATTCHs downloaded
 * PARAMETERS
 *  hd                  [IN]        FS handle
 *  attch_total_num     [IN]        Attach total num
 *  start_pos           [IN]        ATTCH index started position in SAA
 *  download_all        [OUT]       Whether ALL downloaded
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_check_download_all_for_load_attch(
                        FS_HANDLE hd,
                        U32 attch_total_num,
                        U32 start_pos,
                        MMI_BOOL *download_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 rw;
    MMI_BOOL part_downloaded;
    srv_email_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* sizeof(U32) * 2, for attch_num, remain_attach_num */
    EMAIL_FS_SEEK(hd, start_pos + sizeof(U32) * 2, FS_FILE_BEGIN);
    if (attch_total_num > 0)
    {
        EMAIL_FS_SEEK(
            hd,
            EMAIL_STOR_POS_IN_STRUCT(srv_email_stor_attch_struct,download_flag),
            FS_FILE_CURRENT);

        /* loop all attch */
        while (1)
        {
            ret = FS_Read(hd, &part_downloaded, sizeof(MMI_BOOL), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(MMI_BOOL))
            {
                if (rw == 0)    /* reach file end */
                {
                    *download_all = MMI_TRUE;
                    return SRV_EMAIL_RESULT_SUCC;
                }
                EMAIL_STOR_TRACE_FS_READ(ret, rw);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }

            if (!part_downloaded)
            {
                *download_all = MMI_FALSE;
                return SRV_EMAIL_RESULT_SUCC;
            }
            attch_total_num--;
            if (attch_total_num <= 0)
            {
                break;
            }
            EMAIL_FS_SEEK(hd,
                          sizeof(srv_email_stor_attch_struct) -sizeof(MMI_BOOL),
                          FS_FILE_CURRENT);
        }
    }

    result = email_stor_fs_msg_check_cont_download_all(hd, download_all);
    if ((result) != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_check_download_all_for_load_cont
 * DESCRIPTION
 *  Check whether the MSG has download all flag
 * PARAMETERS
 *  hd                  [IN]        FS handle
 *  download_all        [OUT]       MSG Download all flag
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_check_download_all_for_load_cont(
    FS_HANDLE hd, MMI_BOOL *download_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 rw;
    U32 start_pos;
    U32 attch_total_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *download_all = MMI_FALSE;

    EMAIL_FS_SEEK(hd, EMAIL_STOR_SAA_OFFSET_ATTCH_OFFSET, FS_FILE_BEGIN);
    ret = FS_Read(hd, &start_pos, sizeof(EMAIL_STOR_OFFSET), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_STOR_OFFSET))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    EMAIL_FS_SEEK(hd, start_pos, FS_FILE_BEGIN);
    ret = FS_Read(hd, &attch_total_num, sizeof(U32), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    return email_stor_fs_msg_check_download_all_for_load_attch(hd,
                                                               attch_total_num,
                                                               start_pos,
                                                               download_all);
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_load_attch
 * DESCRIPTION
 *  Load an attachment to FS
 * PARAMETERS
 *  msg_id                  [IN]        MSG id
 *  attch_id                [IN]        Attach id
 *  attch_path              [IN]        Attach file path
 *  keep_src                [IN]        Whether source file need kept
 *                                      if NOT, will rename, not copy
 *  drm                     [IN]        drm flag
 *  drm_content_type        [IN]        drm type
 *  new_filename            [IN]        file name
 *  new_charset             [IN]        charset
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_load_attch(
                        EMAIL_MSG_ID msg_id,
                        EMAIL_ATTCH_ID attch_id,
                        const WCHAR *attch_path,
                        MMI_BOOL keep_src,
                        MMI_BOOL drm,
                        const CHAR *drm_content_type,
                        const CHAR *new_filename,
                        const CHAR *new_charset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    srv_email_stor_attch_struct *attch_info;
    EMAIL_ACCT_ID acct_id = email_stor_fs_msg_id_to_acct_id(msg_id);
    EMAIL_FLDR_ID fldr_id = email_stor_fs_msg_id_to_fldr_id(msg_id);
    EMAIL_STOR_OFFSET offset = email_stor_fs_msg_id_to_offset(msg_id);
    EMAIL_ATTCH_ID attch_id_read;
    U32 seek_offset, rw, total_num, attch_local_size;
    FS_HANDLE hd;
    S32 i, ret;
    MMI_BOOL download_all;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    if ((attch_info = email_stor_malloc(sizeof(*attch_info))) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(srv_email_stor_attch_struct));
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    hd = EMAIL_FS_OPEN(attch_path, FS_READ_ONLY);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        goto STOR_EXIT_HANDLE;
    }
    ret = FS_GetFileSize(hd, &attch_local_size);
    if (ret < 0)
    {
        goto STOR_EXIT_HANDLE_CLOSE;
    }
    EMAIL_FS_CLOSE(hd);

    email_stor_fs_attch_gen_path(attch_id, path);

    if (!keep_src)
    {
        /* source file can be removed, so just rename it */
        ret = FS_Rename(attch_path, path);
    }
    else
    {
        /* source file need kept, so make a duplicate */
        ret = FS_Move(attch_path,
                      path,
                      FS_MOVE_COPY | FS_MOVE_OVERWRITE,
                      NULL, NULL, 0);
    }
    if (ret != FS_NO_ERROR)
    {
        EMAIL_STOR_TRACE_FS_RENAME(ret);
        goto STOR_EXIT_HANDLE;
    }

    email_stor_fs_msg_parts_gen_path(acct_id, fldr_id, offset,
                                     SRV_EMAIL_STOR_FILE_SAA, path);

    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_SEEK(hd, EMAIL_STOR_SAA_OFFSET_ATTCH_OFFSET, FS_FILE_BEGIN);
    ret = FS_Read(hd, &seek_offset, sizeof(EMAIL_STOR_OFFSET), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_STOR_OFFSET))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        goto STOR_EXIT_HANDLE_CLOSE;
    }

    EMAIL_FS_SEEK(hd, seek_offset, FS_FILE_BEGIN);
    ret = FS_Read(hd, &total_num, sizeof(U32), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        goto STOR_EXIT_HANDLE_CLOSE;
    }
    /* remain_attach_num */
    EMAIL_FS_SEEK(hd, sizeof(U32), FS_FILE_CURRENT);
    
    /* loop all the attach index to find the attch id */
    for (i = total_num; i > 0; i--)
    {
        ret = FS_Read(hd, &attch_id_read, sizeof(EMAIL_ATTCH_ID), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_ATTCH_ID))
        {
            EMAIL_STOR_TRACE_FS_READ(ret, rw);
            goto STOR_EXIT_HANDLE_CLOSE;
        }

        if (attch_id == attch_id_read)
        {
            memset(attch_info, 0, sizeof(srv_email_stor_attch_struct));
            EMAIL_FS_SEEK(hd, 0 - (S32)sizeof(EMAIL_ATTCH_ID), FS_FILE_CURRENT);
            ret = FS_Read(hd, attch_info, sizeof(*attch_info), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(*attch_info))
            {
                EMAIL_STOR_TRACE_FS_READ(ret, rw);
                goto STOR_EXIT_HANDLE_CLOSE;
            }

            attch_info->download_flag = MMI_TRUE;
            attch_info->local_size = attch_local_size;
            attch_info->drm = drm;

            if (new_filename != NULL)
            {
                strncpy(attch_info->file_name,
                        new_filename,
                        EMAIL_STOR_ENCOD_FILE_NAME_LEN);
                attch_info->file_name[EMAIL_STOR_ENCOD_FILE_NAME_LEN] = 0;
            }

            if (new_charset != NULL)
            {
                strncpy(attch_info->charset,
                        new_charset,
                        EMAIL_STOR_CONT_CHARSET_STR_LEN);
                attch_info->charset[EMAIL_STOR_CONT_CHARSET_STR_LEN] = 0;
            }

            if (drm_content_type != NULL)
            {
                strncpy(attch_info->drm_content_type,
                        drm_content_type,
                        EMAIL_STOR_CONT_TYPE_STR_LEN);
                attch_info->drm_content_type[EMAIL_STOR_CONT_TYPE_STR_LEN] = 0;
            }

            EMAIL_FS_SEEK(hd,
                          0 - (S32)sizeof(*attch_info),
                          FS_FILE_CURRENT);
            ret = FS_Write(hd, attch_info, sizeof(*attch_info), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(*attch_info))
            {
                EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
                goto STOR_EXIT_HANDLE_CLOSE;
            }

            break;
        }
        EMAIL_FS_SEEK(hd,
                      sizeof(*attch_info) - sizeof(EMAIL_ATTCH_ID),
                      FS_FILE_CURRENT);
    }

    if ((ret = email_stor_fs_msg_check_download_all_for_load_attch(
                hd,
                total_num,
                seek_offset,
                &download_all)) != SRV_EMAIL_RESULT_SUCC)
    {
        goto STOR_EXIT_HANDLE_CLOSE;
    }

    EMAIL_FS_CLOSE(hd);

    /* update STATE to NOT header_only */
    {
        U32 msg_new_local_size;
        EMAIL_MSG_STATE state;
        MMI_BOOL need_update_state;
        EMAIL_CHECKSUM index_checksum = 0;

        /* INDEX */
        email_stor_fs_fldr_gen_path(acct_id,
                                    fldr_id,
                                    EMAIL_STOR_FLDR_INDEX,
                                    path);

        hd = EMAIL_FS_OPEN(path, FS_READ_WRITE);
        if (EMAIL_STOR_FS_HANDLE_INVALID(hd))
        {
            EMAIL_STOR_TRACE_FS_OPEN(hd);
            
            email_stor_path_mfree(path);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }

        /* INDEX: read original local size */
        EMAIL_FS_SEEK(hd, EMAIL_STOR_MSG_LOCAL_SIZE_POS(offset), FS_FILE_BEGIN);
        ret = FS_Read(hd, &msg_new_local_size, sizeof(U32), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(U32))
        {
            EMAIL_STOR_TRACE_FS_READ(ret, rw);
            goto STOR_EXIT_HANDLE_CLOSE;
        }

        /* INDEX: write new local size */
        msg_new_local_size += attch_local_size;
        EMAIL_FS_SEEK(hd, 0 - (S32)sizeof(U32), FS_FILE_CURRENT);
        ret = FS_Write(hd, &msg_new_local_size, sizeof(U32), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(U32))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            goto STOR_EXIT_HANDLE_CLOSE;
        }

        EMAIL_FS_SEEK(hd, EMAIL_STOR_MSG_STATE_POS(offset), FS_FILE_BEGIN);
        ret = FS_Read(hd, &state, sizeof(EMAIL_MSG_STATE), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_STATE))
        {
            EMAIL_STOR_TRACE_FS_READ(ret, rw);
            goto STOR_EXIT_HANDLE_CLOSE;
        }

        need_update_state = MMI_FALSE;
        if (state & SRV_EMAIL_MSG_STATE_HEADER_ONLY)
        {
            need_update_state = MMI_TRUE;
            state &= (~SRV_EMAIL_MSG_STATE_HEADER_ONLY);
        }

        /* it's original state is NOT download_all */
        if ((state & SRV_EMAIL_MSG_STATE_DOWN_ALL) !=
             SRV_EMAIL_MSG_STATE_DOWN_ALL &&
            download_all)
        {
            need_update_state = MMI_TRUE;
            state |= SRV_EMAIL_MSG_STATE_DOWN_ALL;
        }

        /* INDEX: write new state */
        if (need_update_state)
        {
            EMAIL_FS_SEEK(hd, EMAIL_STOR_MSG_STATE_POS(offset), FS_FILE_BEGIN);
            ret = FS_Write(hd, &state, sizeof(EMAIL_MSG_STATE), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_STATE))
            {
                EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
                goto STOR_EXIT_HANDLE_CLOSE;
            }
        }

        index_checksum = srv_email_checksum_compute_by_hd(
                            hd, sizeof(EMAIL_CHECKSUM));
        ret = srv_email_checksum_write_by_hd(hd, 0, index_checksum);
        if (ret != SRV_EMAIL_RESULT_SUCC)
        {
            goto STOR_EXIT_HANDLE_CLOSE;
        }
        EMAIL_FS_CLOSE(hd);

        /* BACKUP */
        email_stor_fs_fldr_gen_path(
            acct_id, fldr_id, EMAIL_STOR_FLDR_BACKUP, path);

        hd = EMAIL_FS_OPEN(path, FS_READ_WRITE);
        if (EMAIL_STOR_FS_HANDLE_INVALID(hd))
        {
            EMAIL_STOR_TRACE_FS_OPEN(hd);
            goto STOR_EXIT_HANDLE;
        }

        EMAIL_FS_SEEK(hd, EMAIL_STOR_MSG_LOCAL_SIZE_POS(offset), FS_FILE_BEGIN);
        ret = FS_Write(hd, &msg_new_local_size, sizeof(U32), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(U32))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            goto STOR_EXIT_HANDLE_CLOSE;
        }

        if (need_update_state)
        {
            EMAIL_FS_SEEK(hd, EMAIL_STOR_MSG_STATE_POS(offset), FS_FILE_BEGIN);
            ret = FS_Write(hd, &state, sizeof(EMAIL_MSG_STATE), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_STATE))
            {
                EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
                goto STOR_EXIT_HANDLE_CLOSE;
            }
        }

        srv_email_checksum_write_by_hd(hd, 0, index_checksum);
        if (ret != SRV_EMAIL_RESULT_SUCC)
        {
            goto STOR_EXIT_HANDLE_CLOSE;
        }

        EMAIL_FS_CLOSE(hd);

        if (need_update_state)
        {
            /* Notify MSG */
            {
                srv_email_om_notify_msg_struct notify_data;

                memset(&notify_data, 0, sizeof(notify_data));
                notify_data.msg_id = email_stor_fs_msg_id_gen(acct_id,
                                                              fldr_id,
                                                              offset);
                notify_data.chg_mask = SRV_EMAIL_OM_NOTIFY_MSG_CHG_STATE;
                notify_data.state = state;
                srv_email_om_nofity_msg_from_stor(
                    SRV_EMAIL_OM_NOTIFY_MSG_UPDATE, &notify_data);
                srv_email_om_nofity_fldr_from_stor(
                    SRV_EMAIL_OM_NOTIFY_MSG_UPDATE, &notify_data);
            }
        }
    }

    email_stor_mfree(attch_info);
    email_stor_path_mfree(path);
    return SRV_EMAIL_RESULT_SUCC;

STOR_EXIT_HANDLE_CLOSE:
    EMAIL_FS_CLOSE(hd);
STOR_EXIT_HANDLE:
    email_stor_mfree(attch_info);
    email_stor_path_mfree(path);
    return SRV_EMAIL_RESULT_FS_ERROR;   /* attch id not found */
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_load_cont
 * DESCRIPTION
 *  Load an attachment to FS
 * PARAMETERS
 *  msg_id          [IN]        MSG id
 *  type            [IN]        MSG content type
 *  cont_path       [IN]        Attach file path
 *  keep_src        [IN]        Whether source file need kept
 *                              if NOT, will rename, not copy
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_load_cont(
                        EMAIL_MSG_ID msg_id,
                        srv_email_stor_msg_cont_type type,
                        const WCHAR *cont_path,
                        MMI_BOOL keep_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    EMAIL_ACCT_ID acct_id = email_stor_fs_msg_id_to_acct_id(msg_id);
    EMAIL_FLDR_ID fldr_id = email_stor_fs_msg_id_to_fldr_id(msg_id);
    EMAIL_STOR_OFFSET offset = email_stor_fs_msg_id_to_offset(msg_id);
    U32 seek_offset;
    U32 rw;
    U32 cont_size;
    MMI_BOOL download;
    FS_HANDLE hd;
    srv_email_stor_file_enum file_type;
    S32 ret;
    MMI_BOOL download_all;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(type == SRV_EMAIL_STOR_MSG_CONT_TEXT ||
               type == SRV_EMAIL_STOR_MSG_CONT_HTML);

    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    if (type == SRV_EMAIL_STOR_MSG_CONT_TEXT)
    {
        file_type = SRV_EMAIL_STOR_FILE_CONT_TEXT;
    }
    else
    {
        file_type = SRV_EMAIL_STOR_FILE_CONT_HTML;
    }

    email_stor_fs_msg_parts_gen_path(acct_id, fldr_id, offset, file_type, path);

    FS_Delete(path); // ADD by Hongjing, please check
    if (!keep_src)
    {
        ret = FS_Rename(cont_path, path);
    }
    else
    {
        ret = FS_Move(cont_path, path,
                      FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0);
    }
    if (ret != FS_NO_ERROR)
    {
        EMAIL_STOR_TRACE_FS_RENAME(ret);
        goto STOR_EXIT_HANDLE;
    }

    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        goto STOR_EXIT_HANDLE;
    }
    FS_GetFileSize(hd, &cont_size);
    EMAIL_FS_CLOSE(hd);

    email_stor_fs_msg_parts_gen_path(acct_id, fldr_id, offset,
                                     SRV_EMAIL_STOR_FILE_SAA, path);

    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);        
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_SEEK(hd, EMAIL_STOR_SAA_OFFSET_CONT_HEADER_OFFSET, FS_FILE_BEGIN);
    ret = FS_Read(hd, &seek_offset, sizeof(EMAIL_STOR_OFFSET), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_STOR_OFFSET))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        goto STOR_EXIT_HANDLE_CLOSE;
    }

    EMAIL_FS_SEEK(hd, seek_offset, FS_FILE_BEGIN);

    if (type == SRV_EMAIL_STOR_MSG_CONT_HTML)
    {
        EMAIL_FS_SEEK(hd,
                      sizeof(srv_email_stor_cont_header_struct),
                      FS_FILE_CURRENT);
    }

    EMAIL_FS_SEEK(hd,
                  EMAIL_STOR_POS_IN_STRUCT(srv_email_stor_cont_header_struct,
                                           download_flag),
                  FS_FILE_CURRENT);

    download = MMI_TRUE;
    ret = FS_Write(hd, &download, sizeof(MMI_BOOL), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(MMI_BOOL))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        goto STOR_EXIT_HANDLE_CLOSE;
    }

    EMAIL_FS_SEEK(
        hd,
        EMAIL_STOR_POS_IN_STRUCT(srv_email_stor_cont_header_struct,
                                 local_size) -
            EMAIL_STOR_POS_IN_STRUCT(srv_email_stor_cont_header_struct,
                                     download_flag) -
            sizeof(MMI_BOOL),
        FS_FILE_CURRENT);
    ret = FS_Write(hd, &cont_size, sizeof(U32), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        goto STOR_EXIT_HANDLE_CLOSE;
    }

    email_stor_fs_msg_check_download_all_for_load_cont(hd, &download_all);
    EMAIL_FS_CLOSE(hd);

    /* update STATE to NOT header_only */
    {
        U32 msg_new_local_size;
        EMAIL_MSG_STATE state;
        MMI_BOOL need_update_state;
        EMAIL_CHECKSUM index_checksum;

        /* INDEX */
        email_stor_fs_fldr_gen_path(acct_id, fldr_id,
                                    EMAIL_STOR_FLDR_INDEX, path);

        hd = EMAIL_FS_OPEN(path, FS_READ_WRITE);
        if (EMAIL_STOR_FS_HANDLE_INVALID(hd))
        {
            EMAIL_STOR_TRACE_FS_OPEN(hd);
            goto STOR_EXIT_HANDLE;
        }

        EMAIL_FS_SEEK(hd, EMAIL_STOR_MSG_LOCAL_SIZE_POS(offset), FS_FILE_BEGIN);
        ret = FS_Read(hd, &msg_new_local_size, sizeof(U32), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(U32))
        {
            EMAIL_STOR_TRACE_FS_READ(ret, rw);
            goto STOR_EXIT_HANDLE_CLOSE;
        }
        msg_new_local_size += cont_size;
        EMAIL_FS_SEEK(hd, 0 - (S32)sizeof(U32), FS_FILE_CURRENT);
        ret = FS_Write(hd, &msg_new_local_size, sizeof(U32), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(U32))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            goto STOR_EXIT_HANDLE_CLOSE;
        }

        EMAIL_FS_SEEK(hd, EMAIL_STOR_MSG_STATE_POS(offset), FS_FILE_BEGIN);
        ret = FS_Read(hd, &state, sizeof(EMAIL_MSG_STATE), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_STATE))
        {
            EMAIL_STOR_TRACE_FS_READ(ret, rw);
            goto STOR_EXIT_HANDLE_CLOSE;
        }

        need_update_state = MMI_FALSE;
        if ((state & SRV_EMAIL_MSG_STATE_HEADER_ONLY) ==
            SRV_EMAIL_MSG_STATE_HEADER_ONLY)
        {
            need_update_state = MMI_TRUE;
            state &= (~SRV_EMAIL_MSG_STATE_HEADER_ONLY);
        }
        if (type == SRV_EMAIL_STOR_MSG_CONT_TEXT)
        {
            if ((state & SRV_EMAIL_MSG_STATE_DOWN_NOT_FINISH) ==
                SRV_EMAIL_MSG_STATE_DOWN_NOT_FINISH)
            {
                 need_update_state = MMI_TRUE;
                 state &= (~SRV_EMAIL_MSG_STATE_DOWN_NOT_FINISH);
        }
    }
        if ((state & SRV_EMAIL_MSG_STATE_DOWN_ALL) !=
                SRV_EMAIL_MSG_STATE_DOWN_ALL &&
            download_all)
        {
            need_update_state = MMI_TRUE;
            state |= SRV_EMAIL_MSG_STATE_DOWN_ALL;
        }

        if (need_update_state)
        {
            EMAIL_FS_SEEK(hd, EMAIL_STOR_MSG_STATE_POS(offset), FS_FILE_BEGIN);
            ret = FS_Write(hd, &state, sizeof(EMAIL_MSG_STATE), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_STATE))
            {
                EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
                goto STOR_EXIT_HANDLE_CLOSE;
            }
        }
        index_checksum = srv_email_checksum_compute_by_hd(
                            hd, sizeof(EMAIL_CHECKSUM));
        ret = srv_email_checksum_write_by_hd(hd, 0, index_checksum);
        if (ret != SRV_EMAIL_RESULT_SUCC)
        {
            goto STOR_EXIT_HANDLE_CLOSE;
        }
        EMAIL_FS_CLOSE(hd);

        /* BACKUP */
        email_stor_fs_fldr_gen_path(acct_id, fldr_id,
                                    EMAIL_STOR_FLDR_BACKUP, path);

        hd = EMAIL_FS_OPEN(path, FS_READ_WRITE);
        if (EMAIL_STOR_FS_HANDLE_INVALID(hd))
        {
            EMAIL_STOR_TRACE_FS_OPEN(hd);
            goto STOR_EXIT_HANDLE;
        }

        if (need_update_state)
        {
            EMAIL_FS_SEEK(hd, EMAIL_STOR_MSG_STATE_POS(offset), FS_FILE_BEGIN);
            ret = FS_Write(hd, &state, sizeof(EMAIL_MSG_STATE), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_STATE))
            {
                EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
                goto STOR_EXIT_HANDLE_CLOSE;
            }

        }
        EMAIL_FS_SEEK(hd, EMAIL_STOR_MSG_LOCAL_SIZE_POS(offset), FS_FILE_BEGIN);
        ret = FS_Write(hd, &msg_new_local_size, sizeof(U32), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(U32))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            goto STOR_EXIT_HANDLE_CLOSE;
        }
        ret = srv_email_checksum_write_by_hd(hd, 0, index_checksum);
        if (ret != SRV_EMAIL_RESULT_SUCC)
        {
            goto STOR_EXIT_HANDLE_CLOSE;
        }
        EMAIL_FS_CLOSE(hd);

        if (need_update_state)
        {
            /* Notify MSG */
            srv_email_om_notify_msg_struct notify_data;

            memset(&notify_data, 0, sizeof(srv_email_om_notify_msg_struct));
            notify_data.msg_id = email_stor_fs_msg_id_gen(
                                    acct_id, fldr_id, offset);
            notify_data.chg_mask = SRV_EMAIL_OM_NOTIFY_MSG_CHG_STATE;
            notify_data.state = state;
            srv_email_om_nofity_msg_from_stor(
                SRV_EMAIL_OM_NOTIFY_MSG_UPDATE, &notify_data);
            srv_email_om_nofity_fldr_from_stor(
                SRV_EMAIL_OM_NOTIFY_MSG_UPDATE, &notify_data);
        }
    }

    email_stor_path_mfree(path);
    return SRV_EMAIL_RESULT_SUCC;

STOR_EXIT_HANDLE_CLOSE:
    EMAIL_FS_CLOSE(hd);
STOR_EXIT_HANDLE:
    email_stor_path_mfree(path);
    return SRV_EMAIL_RESULT_FS_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_id_valid_ext
 * DESCRIPTION
 *  Check whether MSG id is valid
 * PARAMETERS
 *  msg_id      [IN]        MSG id
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_id_valid_ext(
    EMAIL_MSG_ID msg_id,
    MMI_BOOL chk_attch,
    MMI_BOOL *is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_ACCT_ID acct_id = email_stor_fs_msg_id_to_acct_id(msg_id);
    EMAIL_FLDR_ID fldr_id = email_stor_fs_msg_id_to_fldr_id(msg_id);
    EMAIL_STOR_OFFSET offset = email_stor_fs_msg_id_to_offset(msg_id);
    EMAIL_STOR_OFFSET pos_end = 0;
    EMAIL_STOR_OFFSET pos_new = 0;
    U32 rw;
    FS_HANDLE hd;
    WCHAR *path;
    MMI_BOOL valid;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *is_valid = MMI_FALSE;
    
    if (!email_stor_fs_acct_id_valid(acct_id))
    {
        return SRV_EMAIL_RESULT_INVALID_ACCT;
    }

    /* no need to check whether the folder id is valid */

    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_fldr_gen_path(acct_id, fldr_id, EMAIL_STOR_FLDR_INDEX, path);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        goto STOR_EXIT_HANDLE;
    }

    if ((ret = FS_GetFileSize(hd, &pos_end)) < FS_NO_ERROR)
    {
        EMAIL_STOR_TRACE_FS_OPEN(ret);
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;
    }

    pos_new = EMAIL_STOR_MSG_RECORD_POS(offset);
    if (pos_new >= pos_end)
    {
        EMAIL_FS_CLOSE(hd);
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_INVALID_MSG;
    }

    valid = MMI_FALSE;
    EMAIL_FS_SEEK(hd, pos_new, FS_FILE_BEGIN);
    ret = FS_Read(hd, &valid, sizeof(MMI_BOOL), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(MMI_BOOL))
    {
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;       
    }
    EMAIL_FS_CLOSE(hd);

    if (valid == MMI_FALSE)
    {
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_SUCC;
    }

    /* check SAA parts */
    email_stor_fs_msg_parts_gen_path(acct_id, fldr_id, offset,
                                     SRV_EMAIL_STOR_FILE_SAA, path);

    if (!EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        S8 text_exist_mask = 0;
        S8 html_exist_mask = 0;
        U32 subj_len = 0;
        srv_email_result_enum result;

        pos_end = 0;
        if ((ret = FS_GetFileSize(hd, &pos_end)) < FS_NO_ERROR ||
            pos_end < EMAIL_STOR_SAA_ADDR_POS)
        {
            EMAIL_FS_CLOSE(hd);
            email_stor_path_mfree(path);
            return SRV_EMAIL_RESULT_SUCC;
        }

        EMAIL_FS_SEEK(hd, EMAIL_STOR_SAA_OFFSET_SUBJ_OFFSET, FS_FILE_BEGIN);
        ret = FS_Read(hd, &pos_new, sizeof(EMAIL_STOR_OFFSET), &rw);
        if (ret != FS_NO_ERROR ||
            rw != sizeof(EMAIL_STOR_OFFSET) ||
            pos_end < pos_new)
        {
            EMAIL_FS_CLOSE(hd);
            email_stor_path_mfree(path);
            return SRV_EMAIL_RESULT_SUCC;
        }

        EMAIL_FS_SEEK(hd, pos_new, FS_FILE_BEGIN);
        ret = FS_Read(hd, &subj_len, sizeof(U32), &rw);
        if (ret != FS_NO_ERROR ||
            rw != sizeof(U32) ||
            pos_end < pos_new + sizeof(subj_len) + subj_len)
        {
            EMAIL_FS_CLOSE(hd);
            email_stor_path_mfree(path);
            return SRV_EMAIL_RESULT_SUCC;
        }
        EMAIL_FS_CLOSE(hd);
    
        result = email_stor_fs_msg_cont_exist(
            msg_id, &text_exist_mask, &html_exist_mask);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            email_stor_path_mfree(path);
            if (result == SRV_EMAIL_RESULT_FS_ERROR)
                return SRV_EMAIL_RESULT_SUCC;
            return result;
        }

        *is_valid = MMI_TRUE;
        if ((text_exist_mask & SRV_EMAIL_MSG_CONT_PART_EXIST) &&
            (text_exist_mask& SRV_EMAIL_MSG_CONT_DOWNLOADED))
        {
            email_stor_fs_msg_parts_gen_path(
                acct_id, fldr_id, offset, SRV_EMAIL_STOR_FILE_CONT_TEXT, path);
            *is_valid = srv_email_util_file_exist(path);
        }
        if (*is_valid &&
            (html_exist_mask & SRV_EMAIL_MSG_CONT_PART_EXIST) &&
            (html_exist_mask & SRV_EMAIL_MSG_CONT_DOWNLOADED))
        {
            email_stor_fs_msg_parts_gen_path(
                acct_id, fldr_id, offset, SRV_EMAIL_STOR_FILE_CONT_HTML, path);
            *is_valid = srv_email_util_file_exist(path);
        }
        if (*is_valid && chk_attch) // check attachments
        {
            EMAIL_STOR_HANDLE handle;
            srv_email_result_enum result;
            srv_email_stor_attch_struct *attch;
            
            if ((attch = email_stor_malloc(sizeof(*attch))) == NULL)
            {
                *is_valid = MMI_FALSE;
                EMAIL_STOR_TRACE_MALLOC(sizeof(srv_email_stor_attch_struct));
                email_stor_path_mfree(path);
                return SRV_EMAIL_RESULT_NO_MEMORY;
            }
            
            result = email_stor_fs_msg_get_attch_open(msg_id, 0, &handle);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                *is_valid = MMI_FALSE;
                email_stor_mfree(attch);
                email_stor_path_mfree(path);
                if (result == SRV_EMAIL_RESULT_FS_ERROR)
                    return SRV_EMAIL_RESULT_SUCC;
                return result;
            }
            while ((result = email_stor_fs_msg_get_attch_next(handle, attch)) ==
                    SRV_EMAIL_RESULT_SUCC)
            {                
                if (!attch->download_flag)
                {
                    continue;
                }
                email_stor_fs_attch_gen_path(attch->attch_id, path);
                if (!srv_email_util_file_exist(path))
                {
                    *is_valid = MMI_FALSE;
                    break;
                }
            }
            email_stor_fs_msg_get_attch_close(handle);
            email_stor_mfree(attch);
            
            if (result != SRV_EMAIL_RESULT_NO_MORE_RESULT)
            {
                email_stor_path_mfree(path);
                return result;
            }
        }
    }
    email_stor_path_mfree(path);
    return SRV_EMAIL_RESULT_SUCC;
    
STOR_EXIT_HANDLE:
    email_stor_path_mfree(path);
    return SRV_EMAIL_RESULT_FS_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_parts_del
 * DESCRIPTION
 *  Delete MSG parts file
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  fldr_id     [IN]        Folder id
 *  offset      [IN]        MSG offset
 *  type        [IN]        File type
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_parts_del(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        EMAIL_STOR_OFFSET offset,
                        srv_email_stor_file_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    switch (type)
    {
        case SRV_EMAIL_STOR_FILE_CONT_TEXT:
        case SRV_EMAIL_STOR_FILE_CONT_HTML:
        case SRV_EMAIL_STOR_FILE_SAA:
            email_stor_fs_msg_parts_gen_path(
                acct_id, fldr_id, offset, type, path);
            if (FS_Delete(path) != FS_NO_ERROR)
            {
                email_stor_path_mfree(path);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }   // TODO: performance
            break;
        default:
            MMI_ASSERT(0);
            break;
    }
    email_stor_path_mfree(path);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_id_gen
 * DESCRIPTION
 *  generate a MSG id
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  fldr_id     [IN]        Folder id
 *  offset      [IN]        MSG offset
 * RETURNS
 *  MSG id
 *****************************************************************************/
EMAIL_MSG_ID email_stor_fs_msg_id_gen(
    EMAIL_ACCT_ID acct_id, EMAIL_FLDR_ID fldr_id, EMAIL_STOR_OFFSET offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((acct_id >> EMAIL_STOR_ACCT_BIT_NUM) == 0);
    MMI_ASSERT((fldr_id >> EMAIL_STOR_FLDR_BIT_NUM) == 0);
    MMI_ASSERT((offset >> EMAIL_STOR_OFFSET_BIT_NUM) == 0);

    return (acct_id << (EMAIL_STOR_FLDR_BIT_NUM + EMAIL_STOR_OFFSET_BIT_NUM)) |
           (fldr_id << EMAIL_STOR_OFFSET_BIT_NUM) | offset;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_id_to_offset
 * DESCRIPTION
 *  Convert MSG id to offset
 * PARAMETERS
 *  id      [IN]        MSG id
 * RETURNS
 *  offset
 *****************************************************************************/
EMAIL_STOR_OFFSET email_stor_fs_msg_id_to_offset(EMAIL_MSG_ID id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 move_bit_num = sizeof(EMAIL_MSG_ID) * 8 - EMAIL_STOR_OFFSET_BIT_NUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (id << move_bit_num) >> move_bit_num;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_id_to_acct_id
 * DESCRIPTION
 *  Convert MSG id to account id
 * PARAMETERS
 *  msg_id      [IN]        MSG id
 * RETURNS
 *  account id
 *****************************************************************************/
EMAIL_ACCT_ID email_stor_fs_msg_id_to_acct_id(EMAIL_MSG_ID msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 move_bit_num = sizeof(EMAIL_MSG_ID) * 8 - EMAIL_STOR_ACCT_BIT_NUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (msg_id >> move_bit_num);
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_id_to_fldr_id
 * DESCRIPTION
 *  Convert MSG id to folder id
 * PARAMETERS
 *  msg_id  [IN]        MSG id
 * RETURNS
 *  fldr id
 *****************************************************************************/
EMAIL_FLDR_ID email_stor_fs_msg_id_to_fldr_id(EMAIL_MSG_ID msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 move_bit_num = sizeof(EMAIL_MSG_ID) * 8 - EMAIL_STOR_FLDR_BIT_NUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (msg_id << EMAIL_STOR_ACCT_BIT_NUM) >> move_bit_num;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_parts_gen_path
 * DESCRIPTION
 *  Generate a MSG parts file path
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  fldr_id     [IN]        Folder id
 *  offset      [IN]        Offset
 *  type        [IN]        File type
 *  path        [OUT]       File path
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_msg_parts_gen_path(
        EMAIL_ACCT_ID acct_id,
        EMAIL_FLDR_ID fldr_id,
        EMAIL_STOR_OFFSET offset,
        srv_email_stor_file_enum type,
        WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 part_dir_id = (offset) / EMAIL_STOR_MSG_NUM_PER_PARTS_DIR;
    EMAIL_MSG_ID msg_id = email_stor_fs_msg_id_gen(acct_id, fldr_id, offset);
    CHAR *parts_suffix_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case SRV_EMAIL_STOR_FILE_CONT_TEXT:
            parts_suffix_p = (CHAR*) EMAIL_PARTS_SUFFIX_TXT;
            break;
        case SRV_EMAIL_STOR_FILE_CONT_HTML:
            parts_suffix_p = (CHAR*) EMAIL_PARTS_SUFFIX_HTML;
            break;
        case SRV_EMAIL_STOR_FILE_SAA:
            parts_suffix_p = (CHAR*) EMAIL_PARTS_SUFFIX_SAA;
            break;
        default:
            MMI_ASSERT(0);
            break;
    }

    kal_wsprintf(
        path,
        "%s%s\\%s\\%u\\%s%u\\%u\\%08X%s",
        srv_email_get_root_path(),
        EMAIL_STOR_SYS_DIR,
        EMAIL_INDEX_FILE_FLDR,
        acct_id,
        EMAIL_PARTS_FLDR,
        fldr_id,
        part_dir_id,
        msg_id,
        parts_suffix_p);
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_parts_read
 * DESCRIPTION
 *  read MSG parts info
 * PARAMETERS
 *  acct_id             [IN]        Account id
 *  fldr_id             [IN]        Folder id
 *  offset              [IN]        Offset
 *  text_type           [IN]        Text type
 *  text_buff_len       [IN]        
 *  buffer              [OUT]       Buffer
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_parts_read(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        EMAIL_STOR_OFFSET offset,
                        srv_eamil_msg_text_type_enum text_type,
                        U32 text_buff_len,
                        CHAR *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    srv_email_stor_file_enum file_type = SRV_EMAIL_STOR_FILE_TOTAL;
    FS_HANDLE hd;
    U32 rw;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(text_buff_len > 0);

    switch (text_type)
    {
        case SRV_EMAIL_MSG_TEXT_SUBJ:
            file_type = SRV_EMAIL_STOR_FILE_SAA;
            break;
        case SRV_EMAIL_MSG_TEXT_CONT_TEXT:
            file_type = SRV_EMAIL_STOR_FILE_CONT_TEXT;
            break;
        case SRV_EMAIL_MSG_TEXT_CONT_HTML:
            file_type = SRV_EMAIL_STOR_FILE_CONT_HTML;
            break;
        default:
            MMI_ASSERT(0);
            break;
    }

    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_msg_parts_gen_path(acct_id, fldr_id, offset, file_type, path);

    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    email_stor_path_mfree(path);

    switch (text_type)
    {
        case SRV_EMAIL_MSG_TEXT_SUBJ:
        {
            U32 subj_offset;
            U32 subj_real_len;
            U32 subj_read_len;

            EMAIL_FS_SEEK(hd, EMAIL_STOR_SAA_OFFSET_SUBJ_OFFSET, FS_FILE_BEGIN);
            ret = FS_Read(hd, &subj_offset, sizeof(U32), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(U32))
            {
                EMAIL_STOR_TRACE_FS_READ(ret, rw);
                EMAIL_FS_CLOSE(hd);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }

            EMAIL_FS_SEEK(hd, subj_offset, FS_FILE_BEGIN);
            ret = FS_Read(hd, &subj_real_len, sizeof(U32), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(U32))
            {
                EMAIL_STOR_TRACE_FS_READ(ret, rw);
                EMAIL_FS_CLOSE(hd);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }

            if (text_buff_len > subj_real_len)
            {
                subj_read_len = subj_real_len;
            }
            else
            {
                subj_read_len = text_buff_len - 1;
            }
            rw = 0;
            ret = FS_Read(hd, buffer, subj_read_len, &rw);
            if (ret != FS_NO_ERROR || rw != subj_read_len)
            {
                EMAIL_STOR_TRACE_FS_READ(ret, rw);
                *(buffer + rw) = '\0';
            }
            else
            {
                *(buffer + subj_read_len) = '\0';
            }
            break;
        }
        case SRV_EMAIL_MSG_TEXT_CONT_TEXT:
        case SRV_EMAIL_MSG_TEXT_CONT_HTML:
        {
            rw = 0;
            ret = FS_Read(hd, buffer, text_buff_len - 1, &rw);
            if (ret != FS_NO_ERROR || rw != text_buff_len - 1)
            {
                EMAIL_STOR_TRACE_FS_READ(ret, rw);
                *(buffer + rw) = '\0';
            }
            else
            {
                *(buffer + text_buff_len) = '\0';
            }
            break;
        }
    }
    EMAIL_FS_CLOSE(hd);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_parts_rename
 * DESCRIPTION
 *  Rename MSG parts file
 * PARAMETERS
 *  acct_id     [IN]        Account id   
 *  fldr_id     [IN]        Fldr id  
 *  offset      [IN]        MSG Offset
 *  type        [IN]        File type
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_parts_rename(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        EMAIL_STOR_OFFSET offset,
                        srv_email_stor_file_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *tmp_path;
    WCHAR *real_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case SRV_EMAIL_STOR_FILE_CONT_TEXT:
            break;
        case SRV_EMAIL_STOR_FILE_CONT_HTML:
            break;
        case SRV_EMAIL_STOR_FILE_SAA:
            break;
        default:
            MMI_ASSERT(0);
            break;
    }

    tmp_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN);
    if (tmp_path == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    real_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN);
    if (real_path == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        email_stor_path_mfree(tmp_path);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_msg_parts_gen_path(acct_id, fldr_id, offset, type, real_path);
    mmi_wcscpy(tmp_path, real_path);
    mmi_wcscat(tmp_path, EMAIL_STOR_MSG_UPDATE_TMP_FILE_SUFFIX);

    FS_Delete(real_path);
    FS_Rename(tmp_path, real_path);

    email_stor_path_mfree(tmp_path);
    email_stor_path_mfree(real_path);

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_attch_id_create
 * DESCRIPTION
 *  Create an attach id
 * PARAMETERS
 *  msg_id          [IN]        
 *  attch_id        [OUT]       Attach id
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_attch_id_create(
    EMAIL_MSG_ID msg_id, EMAIL_ATTCH_ID *attch_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum result;
    U32 attch_id_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = email_stor_fs_cntx_info_write(
               ++(email_stor_p->attch_index_next_avlid), EMAIL_FLDR_INVALID_ID);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }

    attch_id_index = email_stor_p->attch_index_next_avlid - 1;
    *attch_id = msg_id;
    *attch_id <<= (sizeof(EMAIL_MSG_ID) * 8);
    *attch_id |= attch_id_index;

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_attch_id_link_add
 * DESCRIPTION
 *  Add a attach_id_note to linked list
 * PARAMETERS
 *  header          [IN]        Attach id note linked list header
 *  attch_id        [IN]        Attach id
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_attch_id_link_add(
                        email_stor_attch_id_link_struct **header,
                        EMAIL_ATTCH_ID attch_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_attch_id_link_struct *tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*header == NULL)
    {
        if ((*header = email_stor_malloc(sizeof(**header))) == NULL)
        {
            EMAIL_STOR_TRACE_MALLOC(sizeof(**header));
            return SRV_EMAIL_RESULT_NO_MEMORY;
        }
        tail = *header;
    }
    else
    {
        tail = *header;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        if ((tail->next = email_stor_malloc(sizeof(*(tail->next)))) == NULL)
        {
            EMAIL_STOR_TRACE_MALLOC(sizeof(*(tail->next)));
            return SRV_EMAIL_RESULT_NO_MEMORY;
        }
        tail = tail->next;
    }
    tail->attch_id = attch_id;
    tail->next = NULL;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_attch_id_link_del
 * DESCRIPTION
 *  Remove specified attachment id from linked list
 * PARAMETERS
 *  header          [IN]        Pointer to Linked list header pointer
 *  attch_id        [IN]        Attachment id
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
srv_email_result_enum email_stor_fs_attch_id_link_del(
                        email_stor_attch_id_link_struct **header,
                        EMAIL_ATTCH_ID attch_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_attch_id_link_struct *prev, *curr = *header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (curr == NULL)
    {
        return SRV_EMAIL_RESULT_FAIL;
    }
    if (curr->attch_id == attch_id)
    {
        email_stor_attch_id_link_struct *temp = curr->next;

        email_stor_mfree(curr);
        *header = temp;
        return SRV_EMAIL_RESULT_SUCC;
    }
    else
    {
        prev = curr;
        curr = curr->next;

        while (curr != NULL)
        {
            if (curr->attch_id == attch_id)
            {
                email_stor_attch_id_link_struct *temp = curr->next;

                email_stor_mfree(curr);
                prev->next = temp;
                return SRV_EMAIL_RESULT_SUCC;
            }
            prev = curr;
            curr = curr->next;
        }
    }
    return SRV_EMAIL_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_attch_id_link_free
 * DESCRIPTION
 *  Free linked list
 * PARAMETERS
 *  header      [IN]        Attach id note
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_attch_id_link_free(email_stor_attch_id_link_struct *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_attch_id_link_struct *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (header != NULL)
    {
        temp = header->next;
        email_stor_mfree(header);
        header = temp;
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_attch_id_to_msg_id
 * DESCRIPTION
 *  Convert attchment id to MSG id
 * PARAMETERS
 *  attch_id        [IN]        Attach id
 * RETURNS
 *  MSG id
 *****************************************************************************/
EMAIL_MSG_ID email_stor_fs_attch_id_to_msg_id(EMAIL_ATTCH_ID attch_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (EMAIL_MSG_ID) (attch_id >> 32);
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_attch_gen_path
 * DESCRIPTION
 *  (Attach.NO % MOD) / DIV
 * PARAMETERS
 *  attch_id        [IN]        Attach id
 *  path            [OUT]       Attach path
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_attch_gen_path(EMAIL_ATTCH_ID attch_id, WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_MSG_ID msg_id = (EMAIL_MSG_ID) (attch_id >> 32);
    U32 attch_id_index = (EMAIL_MSG_ID) (attch_id & 0xFFFFFFFF);
    EMAIL_ACCT_ID acct_id = email_stor_fs_msg_id_to_acct_id(msg_id);
    EMAIL_FLDR_ID fldr_id = email_stor_fs_msg_id_to_fldr_id(msg_id);
    EMAIL_STOR_OFFSET offset = email_stor_fs_msg_id_to_offset(msg_id);
    U32 attch_dir_id = offset / EMAIL_STOR_MSG_NUM_PER_ATTCH_DIR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(
        path,
        "%s%s\\%s\\%u\\%s%u\\%u\\%08X%08X%s",
        srv_email_get_root_path(),
        EMAIL_STOR_SYS_DIR,
        EMAIL_INDEX_FILE_FLDR,
        acct_id,
        EMAIL_ATTCH_FLDR,
        fldr_id,
        attch_dir_id,
        msg_id,
        attch_id_index,
        EMAIL_ATTCH_SUFFIX_ATTCH);
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_attch_del
 * DESCRIPTION
 *  Delete all the attachments whose id in this linked list.
 * PARAMETERS
 *  header      [IN]        Attach id note linked list header
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_attch_del(
    email_stor_attch_id_link_struct *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (header == NULL)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }

    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    while (header != NULL)
    {
        email_stor_fs_attch_gen_path(header->attch_id, path);
        header = header->next;
        if (FS_Delete(path) < FS_NO_ERROR)
        {
            // TODO: performance
        }
    }

    email_stor_path_mfree(path);
    return SRV_EMAIL_RESULT_SUCC;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_attch_path_to_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
EMAIL_ATTCH_ID email_stor_fs_attch_path_to_id(WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 prefix_len;
    U32 path_len;
    U32 tmp_len_1, tmp_len_2;
    EMAIL_ATTCH_ID attch_id;
    WCHAR attch_id_str[EMAIL_STOR_ATTCH_ID_STR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prefix_len = strlen(srv_email_get_root_path()) +
                 strlen(EMAIL_STOR_SYS_DIR) + 1 +
                 strlen(EMAIL_INDEX_FILE_FLDR) + 1;
    path_len = mmi_wcslen(path);

    if (path_len <= prefix_len + 1 + 1 + 1 + 
                    strlen(EMAIL_ATTCH_FLDR) + 1 + 8 + 8 +
                    strlen(EMAIL_ATTCH_SUFFIX_ATTCH))
    {
        return EMAIL_ATTCH_INVALID_ID;
    }

    tmp_len_1 = strlen(srv_email_get_root_path());
    if (email_stor_fs_util_ucs2_cmp_asc(path,
                                        srv_email_get_root_path(),
                                        tmp_len_1) != 0)
    {
        return EMAIL_ATTCH_INVALID_ID;
    }

    // TODO: may be this convertor should be more strict

    tmp_len_2 = strlen(EMAIL_STOR_SYS_DIR);
    if (email_stor_fs_util_ucs2_cmp_asc(path + tmp_len_1,
                                        EMAIL_STOR_SYS_DIR,
                                        tmp_len_2) != 0)
    {
        return EMAIL_ATTCH_INVALID_ID;
    }

    mmi_wcsncpy(attch_id_str,
                path + (path_len -
                        EMAIL_STOR_ATTCH_ID_STR_LEN -
                        strlen(EMAIL_ATTCH_SUFFIX_ATTCH)),
                EMAIL_STOR_ATTCH_ID_STR_LEN);
    attch_id_str[EMAIL_STOR_ATTCH_ID_STR_LEN] = 0;
    if (!email_stor_fs_util_wcs_to_u64(&attch_id_str[0], &attch_id, 16))
    {
        attch_id = EMAIL_ATTCH_INVALID_ID;
    }
    return attch_id;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_recent_envent_unread_query
 * DESCRIPTION
 *  query unread msg id, for recent event (pluto op related code)
 * PARAMETERS
 *  count       [IN]    total MSG number
 *  msg_id      [IN]    MSG id buffer pointer
 *  unread      [OUT]   it's -1 if this MSG id is invalid, -2 means not updated
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL email_stor_fs_recent_envent_unread_query(
    U32 count, EMAIL_MSG_ID *msg_id, S8 *unread)
{
    S32 ret;
    U32 i, rw, pos_end, pos_new;
    EMAIL_ACCT_ID acct_tmp;
    EMAIL_FLDR_ID fldr_tmp;
    EMAIL_STOR_OFFSET offset;
    FS_HANDLE hd = FS_INVALID_HANDLE;
    WCHAR *path;
    MMI_BOOL is_hd_opened = MMI_FALSE;
    MMI_BOOL valid = MMI_FALSE;
    EMAIL_MSG_FLAG latest_flag = 0;
    
    for (i = 0; i < count; ++i)
    {
        *(unread + i) = (S8)-2;
    }   

    if (email_stor_p->acct_reset == EMAIL_ACCT_INVALID_ID ||
        email_stor_p->fldr_reset == EMAIL_FLDR_INVALID_ID)
    {
        return MMI_FALSE;
    }
    
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return MMI_FALSE;
    }

    for (i = 0; i < count; ++i)
    {
        acct_tmp = email_stor_fs_msg_id_to_acct_id(*(msg_id + i));
        fldr_tmp = email_stor_fs_msg_id_to_fldr_id(*(msg_id + i));
        if (acct_tmp != email_stor_p->acct_reset ||
            fldr_tmp != email_stor_p->fldr_reset)
        {
            continue;
        }
        
        if (!is_hd_opened)
        {
            // open hd
            email_stor_fs_fldr_gen_path(acct_tmp,
                                        fldr_tmp,
                                        EMAIL_STOR_FLDR_INDEX,
                                        path);

            hd = EMAIL_FS_OPEN(path, FS_READ_ONLY);
            if (EMAIL_STOR_FS_HANDLE_INVALID(hd))
            {
                EMAIL_STOR_TRACE_FS_OPEN(hd);
                goto STOR_EXIT_HANDLE;
            }
            if ((ret = FS_GetFileSize(hd, &pos_end)) < FS_NO_ERROR)
            {
                EMAIL_STOR_TRACE_FS_OPEN(ret);
                goto STOR_EXIT_HANDLE;
            }
            is_hd_opened = MMI_TRUE;
        }        
        
        // read file, and get unread flag, and fill the arg3
        offset = email_stor_fs_msg_id_to_offset(*(msg_id + i));
        pos_new = EMAIL_STOR_MSG_RECORD_POS(offset);
        if (pos_new >= pos_end)
        {
            *(unread + i) = (S8)-1;
            continue;
        }
    
        EMAIL_FS_SEEK(hd, pos_new, FS_FILE_BEGIN);
        ret = FS_Read(hd, &valid, sizeof(MMI_BOOL), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(MMI_BOOL))
        {
            goto STOR_EXIT_HANDLE;
        }
        if (!valid)
        {
            /* this offset not exist */
            *(unread + i) = (S8)-1;
            continue;
        }

        pos_new = EMAIL_STOR_MSG_LATEST_FLAG_POS(offset);
        EMAIL_FS_SEEK(hd, pos_new, FS_FILE_BEGIN);
        ret = FS_Read(hd, &latest_flag, sizeof(EMAIL_MSG_FLAG), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_FLAG))
        {
            goto STOR_EXIT_HANDLE;
        }

        *(unread + i) = (latest_flag & EMAIL_MSG_FLAG_SEEN) ? 0 : 1;
    }
    
STOR_EXIT_HANDLE:
    if (is_hd_opened)
    {
        EMAIL_FS_CLOSE(hd);
    }
    email_stor_path_mfree(path);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_recent_envent_unread_query
 * DESCRIPTION
 *  query unread msg id, for recent event (pluto op related code)
 * PARAMETERS
 *  count       [IN]    total MSG number
 *  msg_id      [IN]    MSG id buffer pointer
 *  unread      [OUT]   it's -1 if this MSG id is invalid, -2 means not updated
 * RETURNS
 *  void
 *****************************************************************************/
srv_email_result_enum email_stor_fs_recent_envent_info_query(
    srv_email_msg_prio_read_struct *msg, U32 count)
{
    S32 ret;
    U32 i, rw, pos_end, pos_new;
    FS_HANDLE hd = 0;
    WCHAR *path;
    email_stor_fs_msg_struct *msg_info;
    EMAIL_ACCT_ID curr_acct = EMAIL_ACCT_INVALID_ID;
    EMAIL_FLDR_ID curr_fldr = EMAIL_FLDR_INVALID_ID;
    EMAIL_ACCT_ID temp_acct = EMAIL_ACCT_INVALID_ID;
    EMAIL_FLDR_ID temp_fldr = EMAIL_FLDR_INVALID_ID;
    EMAIL_STOR_OFFSET offset;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    if ((msg_info = email_stor_malloc(sizeof(*msg_info))) == NULL)
    {
        email_stor_path_mfree(path);
        EMAIL_STOR_TRACE_MALLOC(sizeof(email_stor_fs_msg_struct));
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    for (i = 0; i < count; ++i)
    {
        MMI_BOOL need_open_hd = MMI_FALSE;
        if (hd == 0)    // the first time to run
        {
            curr_acct = email_stor_fs_msg_id_to_acct_id((msg + i)->msg_id);
            curr_fldr = email_stor_fs_msg_id_to_fldr_id((msg + i)->msg_id);
            need_open_hd = MMI_TRUE;
        }
        else
        {
            temp_acct = email_stor_fs_msg_id_to_acct_id((msg + i)->msg_id);
            temp_fldr = email_stor_fs_msg_id_to_fldr_id((msg + i)->msg_id);
            if (temp_acct != curr_acct || temp_fldr != curr_fldr)
            {
                curr_acct = temp_acct;
                curr_fldr = temp_fldr;
                EMAIL_FS_CLOSE(hd);
                need_open_hd = MMI_TRUE;
            }
        }
        
        if (need_open_hd)
        {
            // open hd
            email_stor_fs_fldr_gen_path(curr_acct, curr_fldr,
                                        EMAIL_STOR_FLDR_INDEX, path);

            hd = EMAIL_FS_OPEN(path, FS_READ_ONLY);
            if (EMAIL_STOR_FS_HANDLE_INVALID(hd))
            {
                EMAIL_STOR_TRACE_FS_OPEN(hd);
                result = SRV_EMAIL_RESULT_FS_ERROR;
                goto STOR_EXIT_HANDLE;
            }
            if ((ret = FS_GetFileSize(hd, &pos_end)) < FS_NO_ERROR)
            {
                EMAIL_STOR_TRACE_FS_OPEN(ret);
                result = SRV_EMAIL_RESULT_FS_ERROR;
                goto STOR_EXIT_HANDLE;
            }
        }

        (msg + i)->unread    = MMI_FALSE;
        (msg + i)->prio      = EMAIL_MSG_PRIO_MED;
        (msg + i)->has_attch = MMI_FALSE;
        
        // read file, and get unread flag, and fill the arg3
        offset = email_stor_fs_msg_id_to_offset((msg + i)->msg_id);
        pos_new = EMAIL_STOR_MSG_RECORD_POS(offset);
        if (pos_new >= pos_end)
        {
            continue;
        }
    
        EMAIL_FS_SEEK(hd, pos_new, FS_FILE_BEGIN);
        ret = FS_Read(hd, msg_info, sizeof(email_stor_fs_msg_struct), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(email_stor_fs_msg_struct))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            result = SRV_EMAIL_RESULT_FS_ERROR;
            goto STOR_EXIT_HANDLE;
        }
        if (!msg_info->valid) /* this offset not exist */
        {
            continue;
        }
        
        (msg + i)->unread    = (msg_info->flag_latest & EMAIL_MSG_FLAG_SEEN)
                                ? MMI_FALSE : MMI_TRUE;
        (msg + i)->prio      = msg_info->priority;
        (msg + i)->has_attch = msg_info->attch_num > 0 ? MMI_TRUE : MMI_FALSE;
    }
    
STOR_EXIT_HANDLE:
    if (hd > 0)
    {
        EMAIL_FS_CLOSE(hd);
    }
    email_stor_path_mfree(path);
    email_stor_mfree(msg_info);
    return result;
}

