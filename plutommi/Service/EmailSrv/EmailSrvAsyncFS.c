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
 *  EmailSrvAsyncFS.c
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

/* Task Message Communication */
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "stack_ltlcom.h"

#include "emlst_async_fs.h"

#include "EmailSrvGprot.h"
#include "EmailSrvProt.h"

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "stack_config.h"
#include "Unicodexdcl.h"
#include "fs_type.h"
#include "customer_ps_inc.h"
#include "string.h"
#include "kal_public_api.h"

/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_async_proc_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_async_proc_open(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_open_rsp_struct *rsp = (email_fs_open_rsp_struct*) inMsg;
    srv_email_fs_open_funcptr callback = (srv_email_fs_open_funcptr) rsp->callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback != NULL)
    {
        (callback) (rsp->fs_hd, rsp->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_async_proc_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_async_proc_close(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_close_rsp_struct *rsp = (email_fs_close_rsp_struct*) inMsg;
    srv_email_fs_res_funcptr callback = (srv_email_fs_res_funcptr) rsp->callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback != NULL)
    {
        (callback) (rsp->res, rsp->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_async_proc_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_async_proc_read(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_read_rsp_struct *rsp = (email_fs_read_rsp_struct*) inMsg;
    srv_email_fs_read_funcptr callback = (srv_email_fs_read_funcptr) rsp->callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback != NULL)
    {
        (callback) (rsp->res, rsp->read_len, rsp->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_async_proc_write
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_async_proc_write(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_write_rsp_struct *rsp = (email_fs_write_rsp_struct*) inMsg;
    srv_email_fs_write_funcptr callback = (srv_email_fs_write_funcptr) rsp->callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback != NULL)
    {
        (callback) (rsp->res, rsp->write_len, rsp->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_async_proc_commit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_async_proc_commit(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_commit_rsp_struct *rsp = (email_fs_commit_rsp_struct*) inMsg;
    srv_email_fs_res_funcptr callback = (srv_email_fs_res_funcptr) rsp->callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback != NULL)
    {
        (callback) (rsp->res, rsp->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_async_proc_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_async_proc_delete(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_delete_rsp_struct *rsp = (email_fs_delete_rsp_struct*) inMsg;
    srv_email_fs_res_funcptr callback = (srv_email_fs_res_funcptr) rsp->callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback != NULL)
    {
        (callback) (rsp->res, rsp->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_async_proc_xdelete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_async_proc_xdelete(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_xdelete_rsp_struct *rsp = (email_fs_xdelete_rsp_struct*) inMsg;
    srv_email_fs_res_funcptr callback = (srv_email_fs_res_funcptr) rsp->callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback != NULL)
    {
        (callback) (rsp->res, rsp->user_data);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_async_proc_xdelete_acct
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_async_proc_xdelete_acct(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_xdelete_acct_rsp_struct *rsp = (email_fs_xdelete_acct_rsp_struct*) inMsg;
    srv_email_fs_xdelete_acct_funcptr callback = (srv_email_fs_xdelete_acct_funcptr) rsp->callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback != NULL)
    {
        (callback) (&rsp->res[0], rsp->user_data);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_async_proc_rename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_async_proc_rename(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_rename_rsp_struct *rsp = (email_fs_rename_rsp_struct*) inMsg;
    srv_email_fs_res_funcptr callback = (srv_email_fs_res_funcptr) rsp->callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback != NULL)
    {
        (callback) (rsp->res, rsp->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_async_proc_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_async_proc_move(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_move_rsp_struct *rsp = (email_fs_move_rsp_struct*) inMsg;
    srv_email_fs_res_funcptr callback = (srv_email_fs_res_funcptr) rsp->callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback != NULL)
    {
        (callback) (rsp->res, rsp->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_async_fs_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_email_result_enum srv_email_async_fs_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_email_fs_async_proc_open, MSG_ID_EMAIL_ASYNC_FS_OPEN_RSP);
    SetProtocolEventHandler(srv_email_fs_async_proc_close, MSG_ID_EMAIL_ASYNC_FS_CLOSE_RSP);
    SetProtocolEventHandler(srv_email_fs_async_proc_read, MSG_ID_EMAIL_ASYNC_FS_READ_RSP);
    SetProtocolEventHandler(srv_email_fs_async_proc_write, MSG_ID_EMAIL_ASYNC_FS_WRITE_RSP);
    SetProtocolEventHandler(srv_email_fs_async_proc_commit, MSG_ID_EMAIL_ASYNC_FS_COMMIT_RSP);
    SetProtocolEventHandler(srv_email_fs_async_proc_delete, MSG_ID_EMAIL_ASYNC_FS_DELETE_RSP);
    SetProtocolEventHandler(srv_email_fs_async_proc_xdelete, MSG_ID_EMAIL_ASYNC_FS_XDELETE_RSP);
    SetProtocolEventHandler(srv_email_fs_async_proc_rename, MSG_ID_EMAIL_ASYNC_FS_RENAME_RSP);
    SetProtocolEventHandler(srv_email_fs_async_proc_move, MSG_ID_EMAIL_ASYNC_FS_MOVE_RSP);
    
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_fs_send_ilm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  para        [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void email_fs_send_ilm(msg_type msg_id, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *send_ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_ilm = allocate_ilm(MOD_MMI);
    send_ilm->src_mod_id = MOD_MMI;
    send_ilm->dest_mod_id = MOD_EMLST;
    send_ilm->msg_id = msg_id;
    send_ilm->local_para_ptr = para;
    msg_send_ext_queue(send_ilm);
}


/*****************************************************************************
 * FUNCTION
 *  email_fs_construct_ilm_para
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *email_fs_construct_ilm_para(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return construct_local_para((kal_uint16) (size), TD_CTRL | TD_RESET);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [IN]        
 *  flags           [IN]        
 *  callback        [IN]        
 *  user_data       [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_open(const WCHAR *file_name, U32 flags, srv_email_fs_open_funcptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_open_req_struct *para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para = email_fs_construct_ilm_para(sizeof(email_fs_open_req_struct));
    para->callback = (void*)callback;
    mmi_wcsncpy(para->file_name, file_name, EMLST_ASC_SYS_PATH_LEN - 1);
    para->flags = flags;
    para->user_data = user_data;
    email_fs_send_ilm(MSG_ID_EMAIL_ASYNC_FS_OPEN_REQ, para);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_handle     [IN]        
 *  callback        [IN]        
 *  user_data       [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_close(FS_HANDLE file_handle, srv_email_fs_res_funcptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_close_req_struct *para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para = email_fs_construct_ilm_para(sizeof(email_fs_close_req_struct));
    para->callback = (void*)callback;
    para->user_data = user_data;
    para->fs_hd = file_handle;
    email_fs_send_ilm(MSG_ID_EMAIL_ASYNC_FS_CLOSE_REQ, para);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fs_hd               [IN]        
 *  data_p              [?]         [?]
 *  length              [IN]        
 *  callback            [IN]        
 *  user_data           [?]         [?]
 *  file_handle(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_read(FS_HANDLE fs_hd, void *data_p, U32 length, srv_email_fs_read_funcptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_read_req_struct *para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para = email_fs_construct_ilm_para(sizeof(email_fs_read_req_struct));
    para->callback = (void*)callback;
    para->user_data = user_data;
    para->fs_hd = fs_hd;
    para->length = length;
    para->data_p = data_p;
    email_fs_send_ilm(MSG_ID_EMAIL_ASYNC_FS_READ_REQ, para);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_write
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fs_hd               [IN]        
 *  data_p              [?]         [?]
 *  length              [IN]        
 *  callback            [IN]        
 *  user_data           [?]         [?]
 *  file_handle(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_write(FS_HANDLE fs_hd, void *data_p, U32 length, srv_email_fs_write_funcptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_write_req_struct *para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para = email_fs_construct_ilm_para(sizeof(email_fs_write_req_struct));
    para->callback = (void*)callback;
    para->user_data = user_data;
    para->fs_hd = fs_hd;
    para->length = length;
    para->data_p = data_p;
    email_fs_send_ilm(MSG_ID_EMAIL_ASYNC_FS_WRITE_REQ, para);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_commit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_handle     [IN]        
 *  callback        [IN]        
 *  user_data       [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_commit(FS_HANDLE file_handle, srv_email_fs_res_funcptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_commit_req_struct *para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para = email_fs_construct_ilm_para(sizeof(email_fs_commit_req_struct));
    para->callback = (void*)callback;
    para->user_data = user_data;
    para->fs_hd = file_handle;
    email_fs_send_ilm(MSG_ID_EMAIL_ASYNC_FS_COMMIT_REQ, para);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [IN]        
 *  callback        [IN]        
 *  user_data       [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_delete(const WCHAR *file_name, srv_email_fs_res_funcptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_delete_req_struct *para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para = email_fs_construct_ilm_para(sizeof(email_fs_delete_req_struct));
    para->callback = (void*)callback;
    para->user_data = user_data;
    mmi_wcsncpy(para->file_name, file_name, EMLST_ASC_SYS_PATH_LEN - 1);
    email_fs_send_ilm(MSG_ID_EMAIL_ASYNC_FS_DELETE_REQ, para);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_xdelete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path                [IN]        
 *  flag                [IN]        
 *  callback            [IN]        
 *  user_data           [?]         [?]
 *  full_path(?)        [IN]        
 *  stack_size(?)       [IN]        
 *  recursive_stack     [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_xdelete(const WCHAR *path, U32 flag, srv_email_fs_res_funcptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_xdelete_req_struct *para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para = email_fs_construct_ilm_para(sizeof(email_fs_xdelete_req_struct));
    para->callback = (void*)callback;
    para->user_data = user_data;
    mmi_wcsncpy(para->full_path, path, EMLST_ASC_SYS_PATH_LEN - 1);
    para->flag = flag;
    email_fs_send_ilm(MSG_ID_EMAIL_ASYNC_FS_XDELETE_REQ, para);
}

void srv_email_fs_xdelete_acct(const WCHAR* root_path, const EMAIL_ACCT_ID *accts, U32 flag, srv_email_fs_xdelete_acct_funcptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;
    email_fs_xdelete_acct_req_struct *para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para = email_fs_construct_ilm_para(sizeof(email_fs_xdelete_acct_req_struct));
    para->callback = (void*)callback;
    para->user_data = user_data;
    memcpy(&para->acct_id[0], accts, sizeof(EMAIL_ACCT_ID) * MMI_EMAIL_MAX_ACCTS);

    len = mmi_wcslen(root_path);
    kal_wsprintf(para->root_path, root_path[len - 1] == L'\\' ? "%w" : "%w\\", root_path);
    
    para->flag = flag;
    email_fs_send_ilm(MSG_ID_EMAIL_ASYNC_FS_XDELETE_ACCT_REQ, para);
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_rename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_name       [IN]        
 *  new_name        [IN]        
 *  callback        [IN]        
 *  user_data       [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_rename(
        const WCHAR *file_name,
        const WCHAR *new_name,
        srv_email_fs_res_funcptr callback,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_rename_req_struct *para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para = email_fs_construct_ilm_para(sizeof(email_fs_rename_req_struct));
    para->callback = (void*)callback;
    para->user_data = user_data;
    mmi_wcsncpy(para->file_name, file_name, EMLST_ASC_SYS_PATH_LEN - 1);
    mmi_wcsncpy(para->new_name, new_name, EMLST_ASC_SYS_PATH_LEN - 1);
    email_fs_send_ilm(MSG_ID_EMAIL_ASYNC_FS_RENAME_REQ, para);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fs_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_path                [IN]        
 *  dst_path                [IN]        
 *  flag                    [IN]        
 *  callback                [IN]        
 *  user_data               [?]         [?]
 *  dst_full_path(?)        [IN]        
 *  src_full_path(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_fs_move(
        const WCHAR *src_path,
        const WCHAR *dst_path,
        U32 flag,
        srv_email_fs_res_funcptr callback,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_fs_move_req_struct *para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para = email_fs_construct_ilm_para(sizeof(email_fs_move_req_struct));
    para->callback = (void*)callback;
    para->user_data = user_data;
    mmi_wcsncpy(para->src_path, src_path, EMLST_ASC_SYS_PATH_LEN - 1);
    mmi_wcsncpy(para->dst_path, dst_path, EMLST_ASC_SYS_PATH_LEN - 1);
    para->flag = flag;
    email_fs_send_ilm(MSG_ID_EMAIL_ASYNC_FS_MOVE_REQ, para);
}

