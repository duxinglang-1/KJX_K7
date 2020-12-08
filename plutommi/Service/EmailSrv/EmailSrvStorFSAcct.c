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
 *  EmailSrvStorFSAcct.c
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "EmailSrvGprot.h"
#include "EmailSrvProt.h"
#include "EmailSrvStorage.h"
#include "EmailSrvStorFS.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "customer_ps_inc.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "Unicodexdcl.h"
#include "mmi_inet_app_trc.h"
#include "kal_trace.h"
#include "fs_gprot.h"
#include "string.h"

#ifdef EMAIL_STOR_FILE
#undef EMAIL_STOR_FILE
#endif
#define EMAIL_STOR_FILE 'A'

typedef struct
{
    S32 i;
} email_stor_fs_acct_pre_install_struct;

typedef struct
{
    MMI_BOOL check_before_create_fldr;
    MMI_BOOL add_acct;  //otherwise it's update
    S32 current_fldr_index;
    WCHAR path[EMAIL_STOR_WCS_SYS_PATH_LEN];
    EMAIL_ACCT_ID acct_id_fs[EMAIL_STOR_ACCT_NUM_MAX];
    srv_email_stor_fldr_create_info_struct fldr_info;
    srv_email_acct_info_struct *acct_info;
    srv_email_stor_acct_write_funcptr_type callback;
    void* user_data;
} email_stor_fs_acct_info_write_async_struct;

static void email_stor_fs_acct_info_write_async_run(
    email_stor_fs_acct_info_write_async_struct *acct_info_write_async);

static srv_email_result_enum email_stor_fs_acct_info_del_id(
    EMAIL_ACCT_ID acct_id);

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_id_mem_global_get
 * DESCRIPTION
 *  Get acct_id state from Global Mem
 * PARAMETERS
 *  acct_id     [IN]        Account id
 * RETURNS
 *  whether account id used(valid)
 *****************************************************************************/
email_stor_acct_id_used_type_enum email_stor_fs_acct_id_mem_global_get(
    EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = acct_id - EMAIL_STOR_ACCT_VALID_ID_MIN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(EMAIL_STOR_ACCT_ID_IS_VALID(acct_id));
    return email_stor_p->acct[index].acct_id_used;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_id_mem_global_set
 * DESCRIPTION
 *  Set acct_id state to Global Mem
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  type        [IN]        Whether used(valid)
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_acct_id_mem_global_set(
    EMAIL_ACCT_ID acct_id, email_stor_acct_id_used_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = acct_id - EMAIL_STOR_ACCT_VALID_ID_MIN;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(EMAIL_STOR_ACCT_ID_IS_VALID(acct_id));
    email_stor_p->acct[index].acct_id_used = type;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_info_cache_cnt_msg_unread
 * DESCRIPTION
 *  Get all account's total unread number
 * PARAMETERS
 *  void
 * RETURNS
 *  Unread number
 *****************************************************************************/
U32 email_stor_fs_acct_info_cache_cnt_msg_unread(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U32 cnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < EMAIL_STOR_ACCT_NUM_MAX; i++)
    {
        if (email_stor_p->acct[i].acct_id_used == EMAIL_STOR_ACCT_ID_USED)
        {
            cnt += email_stor_p->acct[i].acct_info_cache.unread_num;
        }
    }
    MMI_ASSERT(cnt <= EMAIL_STOR_ACCT_NUM_MAX * EMAIL_STOR_MAX_MSG_NUM_PER_FLDR);
    return cnt;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_unread_set_directly
 * DESCRIPTION
 *  Just set the account's unread number
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_acct_unread_set_directly(
    EMAIL_ACCT_ID acct_id, U32 unread_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = acct_id - EMAIL_STOR_ACCT_VALID_ID_MIN;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(EMAIL_STOR_ACCT_ID_IS_VALID(acct_id));
    MMI_ASSERT(unread_num <= EMAIL_STOR_MAX_MSG_NUM_PER_FLDR);
    email_stor_p->acct[index].acct_info_cache.unread_num = unread_num;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_info_cache_get
 * DESCRIPTION
 *  Get account cache info
 * PARAMETERS
 *  acct_id             [IN]        Account id
 *  acct_info_cache     [OUT]       Account cache info
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_acct_info_cache_get(
    EMAIL_ACCT_ID acct_id, srv_email_acct_info_cache_struct *acct_info_cache)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = acct_id - EMAIL_STOR_ACCT_VALID_ID_MIN;
    srv_email_acct_info_cache_struct *acct_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(EMAIL_STOR_ACCT_ID_IS_VALID(acct_id));
    acct_info = &(email_stor_p->acct[index].acct_info_cache);
    acct_info_cache->is_cloud_acct  = acct_info->is_cloud_acct;
    acct_info_cache->protocol = acct_info->protocol;
    acct_info_cache->unread_num = acct_info->unread_num;
    mmi_wcscpy(acct_info_cache->acct_name, acct_info->acct_name);
    mmi_wcscpy(acct_info_cache->acct_addr, acct_info->acct_addr);
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_info_cache_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id         [IN]        
 *  protocol        [IN]        
 *  acct_name       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_acct_info_cache_set(
        EMAIL_ACCT_ID acct_id,
        MMI_BOOL is_cloud_acct,
        srv_email_prot_type_enum protocol,
        const WCHAR *acct_name,
        const WCHAR *address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_acct_info_cache_struct *acct_info;
    U32 index = acct_id - EMAIL_STOR_ACCT_VALID_ID_MIN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(EMAIL_STOR_ACCT_ID_IS_VALID(acct_id));
    acct_info = &(email_stor_p->acct[index].acct_info_cache);
    acct_info->is_cloud_acct = is_cloud_acct;

    if (protocol != SRV_EMAIL_PROT_TOTAL)
    {
    acct_info->protocol = protocol;
    }

    if (acct_name != NULL)
    {
        mmi_wcsncpy(acct_info->acct_name, acct_name, SRV_EMAIL_MAX_ACCT_NAME_LEN);
    }

    if (address != NULL)
    {
        mmi_wcsncpy(acct_info->acct_addr, address, MMI_EMAIL_MAX_ADDR_LEN);
    }
}

void email_stor_fs_msg_next_valid_offset_set(EMAIL_ACCT_ID acct_id, EMAIL_STOR_OFFSET offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = acct_id - EMAIL_STOR_ACCT_VALID_ID_MIN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(EMAIL_STOR_ACCT_ID_IS_VALID(acct_id));
    email_stor_p->acct[index].next_search_offset = offset;
}

EMAIL_STOR_OFFSET email_stor_fs_msg_next_valid_offset_get(
    EMAIL_ACCT_ID acct_id, EMAIL_FLDR_ID fldr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = acct_id - EMAIL_STOR_ACCT_VALID_ID_MIN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_stor_fs_fldr_id_to_fldr_type(acct_id, fldr_id) != SRV_EMAIL_FLDR_TYPE_INBOX)
    {
        return 0;
    }

    MMI_ASSERT(EMAIL_STOR_ACCT_ID_IS_VALID(acct_id));
    return email_stor_p->acct[index].next_search_offset;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_cache_notify_set
 * DESCRIPTION
 *  Set account cache notify callback, if the unread number changed,
 *  this callback will be executed.
 * PARAMETERS
 *  callback        [IN]        callback
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_acct_cache_notify_set(
    srv_email_all_msg_unread_notify_funcptr callback,
    void *userdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MMI_BOOL callback_exist = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < EMAIL_STOR_MAX_ACCT_CACHE_NOTIFY; ++i)
    {
        if (email_stor_p->msg_unread_notify_callback[i] == callback)
        {
            callback_exist = MMI_TRUE;
            break;
        }
    }

    if (!callback_exist)
    {
        for (i = 0; i < EMAIL_STOR_MAX_ACCT_CACHE_NOTIFY; ++i)
        {
            if (email_stor_p->msg_unread_notify_callback[i] == NULL)
            {
                email_stor_p->msg_unread_notify_callback[i] = callback;
                email_stor_p->msg_unread_notify_userdata[i] = userdata;
                break;
        }
    }
}

    if (email_stor_fs_acct_info_cache_cnt_msg_unread())
    {
        email_stor_fs_acct_cache_notify_msg_unread_chg(
            SRV_EMAIL_ALL_MSG_UNREAD_NONE_TO_SOME,
            email_stor_fs_acct_info_cache_cnt_msg_unread());
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_cache_notify_msg_unread_chg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type                [IN]        notify type
 *  new_unread_num      [IN]        new unread number
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_acct_cache_notify_msg_unread_chg(
                srv_email_all_msg_unread_notify_type type,
                U32 new_unread_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < EMAIL_STOR_MAX_ACCT_CACHE_NOTIFY; ++i)
    {
        if (email_stor_p->msg_unread_notify_callback[i] != NULL)
    {
            email_stor_p->msg_unread_notify_callback[i](
                type,
                new_unread_num,
                email_stor_p->msg_unread_notify_userdata[i]);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_cache_update_msg_unread_chg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id             [IN]        account id
 *  unread_num_chg      [IN]        unread number changed
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_acct_cache_update_msg_unread_chg(
    EMAIL_ACCT_ID acct_id, S32 unread_num_chg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 cnt_old, cnt_new;
    U32 index = acct_id - EMAIL_STOR_ACCT_VALID_ID_MIN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(EMAIL_STOR_ACCT_ID_IS_VALID(acct_id));
    if (unread_num_chg == 0)
    {
        return;
    }

    cnt_old = email_stor_fs_acct_info_cache_cnt_msg_unread();
    cnt_new = cnt_old + unread_num_chg;
    
    email_stor_fs_acct_unread_set_directly(
        acct_id,
        email_stor_p->acct[index].acct_info_cache.unread_num + unread_num_chg);

    if (cnt_old == 0 && cnt_new > 0)
    {
        email_stor_fs_acct_cache_notify_msg_unread_chg(
            SRV_EMAIL_ALL_MSG_UNREAD_NONE_TO_SOME, cnt_new);
    }
    
    if (cnt_old)
    {
        if (cnt_new == 0)
        {
            email_stor_fs_acct_cache_notify_msg_unread_chg(
                SRV_EMAIL_ALL_MSG_UNREAD_SOME_TO_NONE, cnt_new);
        }
        else
        {
            email_stor_fs_acct_cache_notify_msg_unread_chg(
                SRV_EMAIL_ALL_MSG_UNREAD_SOME_TO_SOME, cnt_new);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_cache_update_msg_unread_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id             [IN]        
 *  unread_num_chg      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_acct_cache_update_msg_unread_reset(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 cnt_old, cnt_new, i;
    U32 index = acct_id - EMAIL_STOR_ACCT_VALID_ID_MIN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(EMAIL_STOR_ACCT_ID_IS_VALID(acct_id));
    for (cnt_old = 0, i = 0; i < EMAIL_STOR_ACCT_NUM_MAX; i++)
    {
        cnt_old += email_stor_p->acct[i].acct_info_cache.unread_num;
    }
    cnt_new = cnt_old - email_stor_p->acct[index].acct_info_cache.unread_num;

    email_stor_fs_acct_unread_set_directly(acct_id, 0);
    
    if (cnt_old > 0)
    {
        if (cnt_new == 0)
        {
            email_stor_fs_acct_cache_notify_msg_unread_chg(
                SRV_EMAIL_ALL_MSG_UNREAD_SOME_TO_NONE, cnt_new);
        }
        else
        {
            email_stor_fs_acct_cache_notify_msg_unread_chg(
                SRV_EMAIL_ALL_MSG_UNREAD_SOME_TO_SOME, cnt_new);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_gen_path
 * DESCRIPTION
 *  from acct-id to acct-dir-path, such as: "sys_dir\index\1"
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  path        [OUT]       Account directory path
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_acct_gen_path(EMAIL_ACCT_ID acct_id, WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(path,
                 "%s%s\\%s\\%d",
                 srv_email_get_root_path(),
                 EMAIL_STOR_SYS_DIR,
                 EMAIL_INDEX_FILE_FLDR,
                 acct_id);
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_create_request
 * DESCRIPTION
 *  Create an account. Create the account directory, update acct.info
 * PARAMETERS
 *  acct_id     [OUT]       Account id
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_acct_create_request(EMAIL_ACCT_ID *acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_ACCT_ID i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = EMAIL_STOR_ACCT_VALID_ID_MIN;
         i <= EMAIL_STOR_ACCT_VALID_ID_MAX; ++i)
    {
        if (email_stor_fs_acct_id_mem_global_get(i) ==
            EMAIL_STOR_ACCT_ID_UNUSED)
        {
            *acct_id = i;
            email_stor_fs_acct_id_mem_global_set(i, EMAIL_STOR_ACCT_ID_LOCK);
            return SRV_EMAIL_RESULT_SUCC;
        }
    }
    return SRV_EMAIL_RESULT_ACCT_ID_REACH_MAX_NUM;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_create_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum email_stor_fs_acct_create_cancel(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_stor_fs_acct_id_mem_global_get(acct_id) ==
        EMAIL_STOR_ACCT_ID_LOCK)
    {
        email_stor_fs_acct_id_mem_global_set(acct_id,EMAIL_STOR_ACCT_ID_UNUSED);
        return SRV_EMAIL_RESULT_SUCC;
    }
    else
    {
        // TODO: delete acct 
    }
    return SRV_EMAIL_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_pre_install_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum email_stor_fs_acct_pre_install_open(
    EMAIL_STOR_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_acct_pre_install_struct *acct_pre_install;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!email_stor_p->need_pre_installed_acct)
    {
        *handle = EMAIL_STOR_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_FAIL;
    }

    acct_pre_install = email_stor_malloc(
                        sizeof(email_stor_fs_acct_pre_install_struct));
    if (acct_pre_install == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(email_stor_fs_acct_pre_install_struct));
        *handle = EMAIL_STOR_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    *handle = acct_pre_install;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_pre_install_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  acct_info       [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum email_stor_fs_acct_pre_install_create(
                        EMAIL_STOR_HANDLE handle,
                        srv_email_acct_info_struct *acct_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_ACCT_ID acct_id;
    srv_email_result_enum res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle == EMAIL_STOR_INVALID_HANDLE)
    {
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    res = email_stor_fs_acct_create_request(&acct_id);
    if (res == SRV_EMAIL_RESULT_SUCC)
    {
        acct_info->acct_id = acct_id;
        return email_stor_fs_acct_info_write(acct_info);
    }
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_pre_install_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum email_stor_fs_acct_pre_install_close(
    EMAIL_STOR_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_acct_pre_install_struct *acct_pre_install;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    acct_pre_install = (email_stor_fs_acct_pre_install_struct*)(handle);
    if (handle == EMAIL_STOR_INVALID_HANDLE)
    {
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    email_stor_mfree(acct_pre_install);
    email_stor_p->need_pre_installed_acct = MMI_FALSE;

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_del
 * DESCRIPTION
 *  Delete an account
 * PARAMETERS
 *  acct_id     [IN]        Account id
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_acct_del(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    S32 dir_exist;
    srv_email_result_enum result;
    WCHAR *acct_dir_orgi_path;
    WCHAR *acct_dir_temp_path;
    email_stor_acct_id_used_type_enum acct_state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAIL_STOR_TRACE_ACCT_DEL(acct_id, 0);

    acct_state = email_stor_fs_acct_id_mem_global_get(acct_id);
    if (acct_state == EMAIL_STOR_ACCT_ID_UNUSED)
    {
        return SRV_EMAIL_RESULT_INVALID_ACCT;
    }
    
    if (acct_state == EMAIL_STOR_ACCT_ID_LOCK)
    {
        email_stor_fs_acct_id_mem_global_set(acct_id,EMAIL_STOR_ACCT_ID_UNUSED);
        return SRV_EMAIL_RESULT_INVALID_ACCT;
    }

    result = email_stor_fs_acct_info_del_id(acct_id);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        return result;
    }

    acct_dir_orgi_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN);
    if (acct_dir_orgi_path == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    acct_dir_temp_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN);
    if (acct_dir_temp_path == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        email_stor_path_mfree(acct_dir_orgi_path);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_acct_gen_path(acct_id, acct_dir_orgi_path);
    dir_exist = srv_email_util_dir_exist(acct_dir_orgi_path);
    if (dir_exist < 0)
    {
        EMAIL_STOR_TRACE_FS_CREATE_DIR(dir_exist);
        email_stor_path_mfree(acct_dir_orgi_path);
        email_stor_path_mfree(acct_dir_temp_path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    if (!dir_exist)
    {
        FS_CreateDir(acct_dir_orgi_path);
        // ignore the return value
        email_stor_path_mfree(acct_dir_orgi_path);
        email_stor_path_mfree(acct_dir_temp_path);
        return SRV_EMAIL_RESULT_SUCC;
    }

    kal_wsprintf(acct_dir_temp_path,
                 "%w%w",
                 acct_dir_orgi_path,
                 EMAIL_STOR_TMP_SUFFIX);
    ret = FS_Rename(acct_dir_orgi_path, acct_dir_temp_path);
    FS_CreateDir(acct_dir_orgi_path);
    // ignore the return value
    email_stor_path_mfree(acct_dir_orgi_path);
    if (ret != FS_NO_ERROR)
    {
        EMAIL_STOR_TRACE_FS_RENAME(ret);
        email_stor_path_mfree(acct_dir_temp_path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    srv_email_fs_xdelete(acct_dir_temp_path,
                         FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE,
                         NULL, 0);
    email_stor_path_mfree(acct_dir_temp_path);

    /************** for home screen recent list update ****************/
    if (email_stor_p->recent_list_query_callback != NULL
        && email_stor_p->recent_list_query_callback != NULL)
    {
        EMAIL_MSG_ID *ids;
        U32 i, num;
        MMI_BOOL chg = MMI_FALSE;

        (email_stor_p->recent_list_query_callback)(&ids, &num);
        EMAIL_STOR_TRACE_ACCT_DEL(acct_id, num);
        for (i = 0; i < num; i++)
        {
            if (email_stor_fs_msg_id_to_acct_id(*(ids + i)) == acct_id)
            {
                *(ids + i) = EMAIL_MSG_INVALID_ID;
                chg = MMI_TRUE;
                EMAIL_STOR_TRACE_ACCT_DEL(acct_id, i);
            }
        }
        (email_stor_p->recent_list_answer_callback)(ids, chg);
    }
    /************** for home screen recent list update ****************/

    EMAIL_STOR_TRACE_ACCT_DEL(acct_id, 1);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_default_id_get
 * DESCRIPTION
 *  Get default account id
 * PARAMETERS
 *  void
 * RETURNS
 *  valid account id, or EMAIL_ACCT_INVALID_ID
 *****************************************************************************/
srv_email_result_enum email_stor_fs_acct_default_id_get(
    EMAIL_ACCT_ID *default_acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hd;
    WCHAR *path;
    U32 rw;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *default_acct_id = EMAIL_ACCT_INVALID_ID;

    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_acct_info_gen_path(path, EMAIL_STOR_FS_ACCT_INFO_ORIG);

    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    email_stor_path_mfree(path);

    EMAIL_FS_SEEK(hd, EMAIL_STOR_ACCT_INFO_DEFAULT_ID_POS, FS_FILE_BEGIN);
    ret = FS_Read(hd, default_acct_id, sizeof(EMAIL_ACCT_ID), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_ACCT_ID))
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
 *  email_stor_fs_acct_default_id_set
 * DESCRIPTION
 *  Set default account id
 * PARAMETERS
 *  acct_id     [IN]        Account id
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_acct_default_id_set_ext(
    EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    FS_HANDLE hd;
    WCHAR *path;
    U32 rw;
    EMAIL_ACCT_ID orig_default_acct_id;
    EMAIL_CHECKSUM acct_info_checksum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    /************************* ORIGINAL file ************************/
    email_stor_fs_acct_info_gen_path(path, EMAIL_STOR_FS_ACCT_INFO_ORIG);

    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_SEEK(hd, EMAIL_STOR_ACCT_INFO_DEFAULT_ID_POS, FS_FILE_BEGIN);
    ret = FS_Read(hd, &orig_default_acct_id, sizeof(EMAIL_ACCT_ID), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_ACCT_ID))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;
    }

    if (orig_default_acct_id == acct_id)
    {
        EMAIL_FS_CLOSE(hd);
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_SUCC;
    }
    
    EMAIL_FS_SEEK(hd, 0 - (S32)sizeof(EMAIL_ACCT_ID), FS_FILE_CURRENT);
    ret = FS_Write(hd, &acct_id, sizeof(EMAIL_ACCT_ID), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_ACCT_ID))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;
    }

    acct_info_checksum = srv_email_checksum_compute_by_hd(
                            hd, sizeof(EMAIL_CHECKSUM));
    srv_email_checksum_write_by_hd(hd, 0, acct_info_checksum);
    EMAIL_FS_CLOSE(hd);

    /************************* ORIGINAL file ************************/
    email_stor_fs_acct_info_gen_path(path, EMAIL_STOR_FS_ACCT_INFO_BAK);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_SEEK(hd, EMAIL_STOR_ACCT_INFO_DEFAULT_ID_POS, FS_FILE_BEGIN);
    ret = FS_Write(hd, &acct_id, sizeof(EMAIL_ACCT_ID), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_ACCT_ID))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;
    }

    srv_email_checksum_write_by_hd(hd, 0, acct_info_checksum);
    EMAIL_FS_CLOSE(hd);
    email_stor_path_mfree(path);
    
    return SRV_EMAIL_RESULT_SUCC;

STOR_EXIT_HANDLE:
    email_stor_path_mfree(path);
    return SRV_EMAIL_RESULT_FS_ERROR;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_default_id_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id     [IN]        Account id
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_acct_default_id_set(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!email_stor_fs_acct_id_valid(acct_id))
    {
        return SRV_EMAIL_RESULT_INVALID_ACCT;
    }
    
    return email_stor_fs_acct_default_id_set_ext(acct_id);
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_default_id_del
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_acct_default_id_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return email_stor_fs_acct_default_id_set_ext(EMAIL_ACCT_INVALID_ID);
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_get_fldr_id_open
 * DESCRIPTION
 *  Open for getting folder id from an account
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  type        [IN]        Folder type
 *  handle      [OUT]       Handle
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_acct_get_fldr_id_open(
                        EMAIL_ACCT_ID acct_id,
                        srv_email_fldr_type_enum type,
                        EMAIL_STOR_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *pattern;
    email_stor_fs_acct_get_fldr_handle_struct *hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAIL_STOR_TRACE_FLDR_LIST_ID(acct_id, 0);

    if ((*handle = (EMAIL_STOR_HANDLE) email_stor_malloc(sizeof(*hd))) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(*hd));
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    if ((pattern = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        email_stor_mfree(handle);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    hd = (email_stor_fs_acct_get_fldr_handle_struct*) (*handle);

    hd->first = MMI_TRUE;
    hd->acct_id = acct_id;
    hd->type = type;

    switch (type)
    {
        case SRV_EMAIL_FLDR_TYPE_REMOTE:
        case SRV_EMAIL_FLDR_TYPE_ALL:
        {
            EMAIL_FLDR_ID temp_fldr_id;
            U32 filename_len;
            FS_DOSDirEntry email_stor_file_info;

            kal_wsprintf(
                pattern,
                "%s%s\\%s\\%u\\*%s",
                srv_email_get_root_path(),
                EMAIL_STOR_SYS_DIR,
                EMAIL_INDEX_FILE_FLDR,
                acct_id,
                EMAIL_FLDR_SUFFIX_INDEX);
            hd->find_hd = FS_FindFirst(
                            pattern,
                            0,//FS_ATTR_DIR,
                            0,
                            &email_stor_file_info,
                            (WCHAR*) & hd->filename,
                            EMAIL_STOR_ASC_SYS_PATH_LEN);
            email_stor_path_mfree(pattern);

            if (EMAIL_STOR_FS_HANDLE_INVALID(hd->find_hd))
            {
                email_stor_mfree(hd);
                *handle = NULL;
                return SRV_EMAIL_RESULT_FS_ERROR;
            }

            hd->first_fldr_id = EMAIL_FLDR_INVALID_ID;
            filename_len = mmi_wcslen((WCHAR*)&hd->filename);
            if (filename_len > strlen(EMAIL_FLDR_SUFFIX_INDEX))
            {
                hd->filename[filename_len-strlen(EMAIL_FLDR_SUFFIX_INDEX)] = 0;
                email_stor_fs_util_wcs_to_u32((WCHAR*)&hd->filename,
                                              &temp_fldr_id, 10);
                hd->first_fldr_id = temp_fldr_id;
            }
        }
            break;
        default:
            /* Not supported!! Please use email_stor_fs_acct_get_basic_fildr_id
               to get the BASIC folder id */
            MMI_ASSERT(0);
            break;
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_get_fldr_id_next
 * DESCRIPTION
 *  Get next valid folder id from an account
 * PARAMETERS
 *  handle      [IN]        Handle
 *  fldr_id     [OUT]       Folder id
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_acct_get_fldr_id_next(
    EMAIL_STOR_HANDLE handle, EMAIL_FLDR_ID *fldr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 filename_len;
    EMAIL_FLDR_ID temp_fldr_id;
    email_stor_fs_acct_get_fldr_handle_struct *hd = handle;
    FS_DOSDirEntry email_stor_file_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(handle != EMAIL_STOR_INVALID_HANDLE);
    MMI_ASSERT(!EMAIL_STOR_FS_HANDLE_INVALID(hd->find_hd));

    if (hd->first)
    {
        hd->first = MMI_FALSE;
        if (hd->type == SRV_EMAIL_FLDR_TYPE_ALL ||
            hd->first_fldr_id >= EMAIL_STOR_FLDR_REMOTE_ID_MIN)
        {
            *fldr_id = hd->first_fldr_id;
            return SRV_EMAIL_RESULT_SUCC;
        }
    }

    while (FS_FindNext(hd->find_hd,
                       &email_stor_file_info,
                       (WCHAR*)&hd->filename,
                       EMAIL_STOR_ASC_SYS_PATH_LEN) >= FS_NO_ERROR)
    {
        temp_fldr_id = EMAIL_FLDR_INVALID_ID;
        filename_len = mmi_wcslen((WCHAR*)&hd->filename);
        if (filename_len > strlen(EMAIL_FLDR_SUFFIX_INDEX))
        {
            hd->filename[filename_len - strlen(EMAIL_FLDR_SUFFIX_INDEX)] = 0;
            email_stor_fs_util_wcs_to_u32(
                (WCHAR*)&hd->filename, &temp_fldr_id, 10);
        }

        if (hd->type == SRV_EMAIL_FLDR_TYPE_ALL ||
            temp_fldr_id >= EMAIL_STOR_FLDR_REMOTE_ID_MIN)
        {
            *fldr_id = temp_fldr_id;
            return SRV_EMAIL_RESULT_SUCC;
        }
    }

    return SRV_EMAIL_RESULT_NO_MORE_RESULT;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_get_fldr_id_close
 * DESCRIPTION
 *  Close
 * PARAMETERS
 *  handle      [IN]        Handle
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_acct_get_fldr_id_close(
    EMAIL_STOR_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_acct_get_fldr_handle_struct *hd = handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(handle != EMAIL_STOR_INVALID_HANDLE);
    FS_FindClose(hd->find_hd);
    EMAIL_STOR_TRACE_FLDR_LIST_ID(hd->acct_id, 1);
    email_stor_mfree(handle);

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_id_valid_range
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL email_stor_fs_acct_id_valid_range(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (EMAIL_STOR_ACCT_ID_IS_VALID(acct_id) ? MMI_TRUE : MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_id_valid
 * DESCRIPTION
 *  Check whether account id valid
 * PARAMETERS
 *  a       [IN]        
 * RETURNS
 *  MMI_TRUE if valid, otherwise MMI_FALSE
 *****************************************************************************/
MMI_BOOL email_stor_fs_acct_id_valid(EMAIL_ACCT_ID a)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!email_stor_fs_acct_id_valid_range(a) ||
        email_stor_fs_acct_id_mem_global_get(a) == EMAIL_STOR_ACCT_ID_UNUSED)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_info_gen_path
 * DESCRIPTION
 *  Get account info file path
 *  File structre as bellow:
 *  [CHECKSUM        : sizeof(EMAIL_CHECKSUM)   : CHECKSUM]
 *  [EMAIL_ACCT_ID   : sizeof(EMAIL_ACCT_ID)    : Default acct id]
 *  [EMAIL_ACCT_ID   : EMAIL_STOR_ACCT_NUM_MAX * sizeof(EMAIL_ACCT_ID),
 *                      Acct id, ordered by created time]
 *  [ACCT_INFO       : EMAIL_STOR_ACCT_NUM_MAX *
 *                      sizeof(srv_email_acct_info_struct)  : Acct info]
 * PARAMETERS
 *  path        [OUT]       File path
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_acct_info_gen_path(
    WCHAR *path, email_stor_fs_acct_info_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const CHAR *filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(type == EMAIL_STOR_FS_ACCT_INFO_ORIG ||
               type == EMAIL_STOR_FS_ACCT_INFO_BAK);

    if (type == EMAIL_STOR_FS_ACCT_INFO_ORIG)
    {
        filename = EMAIL_ACCT_INFO_FILE_ORIG;
    }
    else
    {
        filename = EMAIL_ACCT_INFO_FILE_BAK;
    }

    kal_wsprintf(path,
                 "%s%s\\%s",
                 srv_email_get_root_path(),
                 EMAIL_STOR_SYS_DIR,
                 filename);
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_info_file_create
 * DESCRIPTION
 *  Create account info file
 * PARAMETERS
 *  orig_path       [IN]        Original path
 *  bak_path        [IN]        Backup path
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_acct_info_file_create(
    const WCHAR *orig_path, const WCHAR *bak_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    EMAIL_ACCT_ID i, default_acct_id = EMAIL_ACCT_INVALID_ID;
    EMAIL_ACCT_ID acct_id[EMAIL_STOR_ACCT_NUM_MAX];
    U32 rw;
    FS_HANDLE orig_hd;
    FS_HANDLE bak_hd;
    EMAIL_CHECKSUM checksum;
    srv_email_acct_info_struct *acct_info;
    EMAIL_ACCT_VERNO acct_info_verno = EMAIL_STOR_ACCT_VERNO;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((acct_info = email_stor_malloc(sizeof(*acct_info))) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(srv_email_acct_info_struct));
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    
    memset(acct_info, 0, sizeof(*acct_info));
    acct_info->acct_id = EMAIL_ACCT_INVALID_ID;
    
    /* ordered account id */
    for (i = 0; i < EMAIL_STOR_ACCT_NUM_MAX; i++)
    {
        acct_id[i] = EMAIL_ACCT_INVALID_ID;
    }

    orig_hd = EMAIL_FS_OPEN(orig_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (EMAIL_STOR_FS_HANDLE_INVALID(orig_hd))
    {
        EMAIL_STOR_TRACE_FS_OPEN(orig_hd);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    bak_hd = EMAIL_FS_OPEN(bak_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (EMAIL_STOR_FS_HANDLE_INVALID(bak_hd))
    {
        EMAIL_STOR_TRACE_FS_OPEN(bak_hd);
        EMAIL_FS_CLOSE(orig_hd);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    /************************* ORIGINAL file START **************************/
    EMAIL_FS_SEEK(orig_hd, EMAIL_STOR_ACCT_INFO_VERNO_POS, FS_FILE_BEGIN);
    ret = FS_Write(orig_hd, &acct_info_verno, sizeof(EMAIL_ACCT_VERNO), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_ACCT_VERNO))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_SEEK(orig_hd, EMAIL_STOR_ACCT_INFO_DEFAULT_ID_POS, FS_FILE_BEGIN);
    ret = FS_Write(orig_hd, &default_acct_id, sizeof(EMAIL_ACCT_ID), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_ACCT_ID))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_SEEK(orig_hd,
                  EMAIL_STOR_ACCT_INFO_ACCT_ID_ORDER_POS,
                  FS_FILE_BEGIN);
    ret = FS_Write(orig_hd, &acct_id[0], EMAIL_STOR_ACCT_ID_ARR_SIZE, &rw);
    if (ret != FS_NO_ERROR || rw != EMAIL_STOR_ACCT_ID_ARR_SIZE)
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        goto STOR_EXIT_HANDLE;
    }

    /* account info */
    EMAIL_FS_SEEK(orig_hd, EMAIL_STOR_ACCT_INFO_FIRST_INFO_POS, FS_FILE_BEGIN);
    for (i = EMAIL_STOR_ACCT_VALID_ID_MIN;
         i <= EMAIL_STOR_ACCT_VALID_ID_MAX; i++)
    {
        ret = FS_Write(orig_hd, acct_info, sizeof(*acct_info), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(srv_email_acct_info_struct))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            goto STOR_EXIT_HANDLE;
        }
    }

    checksum = srv_email_checksum_compute_by_hd(orig_hd,sizeof(EMAIL_CHECKSUM));
    EMAIL_FS_SEEK(orig_hd, EMAIL_STOR_ACCT_INFO_CHECKSUM_POS, FS_FILE_BEGIN);
    ret = FS_Write(orig_hd, &checksum, sizeof(EMAIL_CHECKSUM), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_CHECKSUM))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        goto STOR_EXIT_HANDLE;
    }
    /************************* ORIGINAL file DONE **************************/
    
    /************************* BACKUP file START **************************/
    EMAIL_FS_SEEK(bak_hd, EMAIL_STOR_ACCT_INFO_VERNO_POS, FS_FILE_BEGIN);
    ret = FS_Write(bak_hd, &acct_info_verno, sizeof(EMAIL_ACCT_VERNO), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_ACCT_VERNO))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        goto STOR_EXIT_HANDLE;
    }
    
    EMAIL_FS_SEEK(bak_hd, EMAIL_STOR_ACCT_INFO_DEFAULT_ID_POS, FS_FILE_BEGIN);
    ret = FS_Write(bak_hd, &default_acct_id, sizeof(EMAIL_ACCT_ID), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_ACCT_ID))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_SEEK(bak_hd, EMAIL_STOR_ACCT_INFO_ACCT_ID_ORDER_POS,FS_FILE_BEGIN);
    ret = FS_Write(bak_hd, &acct_id[0], EMAIL_STOR_ACCT_ID_ARR_SIZE, &rw);
    if (ret != FS_NO_ERROR || rw != EMAIL_STOR_ACCT_ID_ARR_SIZE)
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        goto STOR_EXIT_HANDLE;
    }

    /* account info */
    EMAIL_FS_SEEK(bak_hd, EMAIL_STOR_ACCT_INFO_FIRST_INFO_POS, FS_FILE_BEGIN);
    for (i = EMAIL_STOR_ACCT_VALID_ID_MIN;
         i <= EMAIL_STOR_ACCT_VALID_ID_MAX; ++i)
    {
        ret = FS_Write(bak_hd, acct_info, sizeof(*acct_info), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(*acct_info))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            goto STOR_EXIT_HANDLE;
        }
    }

    EMAIL_FS_SEEK(bak_hd, EMAIL_STOR_ACCT_INFO_CHECKSUM_POS, FS_FILE_BEGIN);
    ret = FS_Write(bak_hd, &checksum, sizeof(EMAIL_CHECKSUM), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_CHECKSUM))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        goto STOR_EXIT_HANDLE;
    }
    /************************* BACKUP file DONE **************************/
    EMAIL_FS_CLOSE(orig_hd);
    EMAIL_FS_CLOSE(bak_hd);
    email_stor_mfree(acct_info);
    email_stor_p->need_pre_installed_acct = MMI_TRUE;
    return SRV_EMAIL_RESULT_SUCC;

STOR_EXIT_HANDLE:
    EMAIL_FS_CLOSE(orig_hd);
    EMAIL_FS_CLOSE(bak_hd);
    email_stor_mfree(acct_info);
    return SRV_EMAIL_RESULT_FS_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_id_get
 * DESCRIPTION
 *  Get account id(s)
 * PARAMETERS
 *  acct_id     [OUT]       Account id array pointer
 * RETURNS
 *  account id number
 *****************************************************************************/
U32 email_stor_fs_acct_id_get(EMAIL_ACCT_ID *acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_ACCT_ID i;
    U32 total_valid_acct = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(acct_id,
           &email_stor_p->acct_id_sort,
           sizeof(EMAIL_ACCT_ID) * EMAIL_STOR_ACCT_NUM_MAX);

    for (i = 0; i < EMAIL_STOR_ACCT_NUM_MAX; ++i)
    {
        if (acct_id[i] != EMAIL_ACCT_INVALID_ID)
        {
            ++total_valid_acct;
        }
    }
    return total_valid_acct;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_info_del_id
 * DESCRIPTION
 *  Delete an account form account info file
 * PARAMETERS
 *  acct_id     [IN]        Account id
 * RETURNS
 *  result code
 *****************************************************************************/
static srv_email_result_enum email_stor_fs_acct_info_del_id(
    EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_ACCT_ID i;
    EMAIL_ACCT_ID *acct_id_fs;
    FS_HANDLE hd;
    WCHAR *path;
    U32 rw;
    srv_email_acct_info_struct *acct_info;
    S32 ret;
    EMAIL_ACCT_ID orig_default_acct_id;
    EMAIL_CHECKSUM acct_checksum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(EMAIL_STOR_ACCT_ID_IS_VALID(acct_id));
    MMI_ASSERT(email_stor_fs_acct_id_mem_global_get(acct_id) ==
               EMAIL_STOR_ACCT_ID_USED);

    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    if ((acct_id_fs = email_stor_malloc(EMAIL_STOR_ACCT_ID_ARR_SIZE)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_ACCT_ID_ARR_SIZE);
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    if ((acct_info = email_stor_malloc(sizeof(*acct_info))) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(*acct_info));
        email_stor_path_mfree(path);
        email_stor_mfree(acct_id_fs);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    memset(acct_info, 0, sizeof(srv_email_acct_info_struct));

    /************************* ORIGINAL file START *************************/
    email_stor_fs_acct_info_gen_path(path, EMAIL_STOR_FS_ACCT_INFO_ORIG);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE)))
    {
        /* account info file not exist */
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_SEEK(hd, EMAIL_STOR_ACCT_INFO_DEFAULT_ID_POS, FS_FILE_BEGIN);
    ret = FS_Read(hd, &orig_default_acct_id, sizeof(EMAIL_ACCT_ID), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_ACCT_ID))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;
    }
    if (orig_default_acct_id == acct_id)
    {
        EMAIL_FS_SEEK(hd, 0 - (S32)sizeof(EMAIL_ACCT_ID), FS_FILE_CURRENT);
        orig_default_acct_id = EMAIL_ACCT_INVALID_ID;
        ret = FS_Write(hd, &orig_default_acct_id, sizeof(EMAIL_ACCT_ID), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_ACCT_ID))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            EMAIL_FS_CLOSE(hd);
            goto STOR_EXIT_HANDLE;
        }
    }

    EMAIL_FS_SEEK(hd, EMAIL_STOR_ACCT_INFO_ACCT_ID_ORDER_POS, FS_FILE_BEGIN);
    ret = FS_Read(hd, acct_id_fs, EMAIL_STOR_ACCT_ID_ARR_SIZE, &rw);
    if (ret != FS_NO_ERROR || rw != EMAIL_STOR_ACCT_ID_ARR_SIZE)
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;
    }

    for (i = 0; i < EMAIL_STOR_ACCT_NUM_MAX; i++)
    {
        if (acct_id_fs[i] == acct_id)
        {
            for (; i < EMAIL_STOR_ACCT_NUM_MAX - 1; i++)
            {
                acct_id_fs[i] = acct_id_fs[i + 1];
            }
            acct_id_fs[i] = EMAIL_ACCT_INVALID_ID;
            break;
        }
    }

    EMAIL_FS_SEEK(hd, EMAIL_STOR_ACCT_INFO_ACCT_ID_ORDER_POS, FS_FILE_BEGIN);
    ret = FS_Write(hd, acct_id_fs, EMAIL_STOR_ACCT_ID_ARR_SIZE, &rw);
    if (ret != FS_NO_ERROR || rw != EMAIL_STOR_ACCT_ID_ARR_SIZE)
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;
    }
    
    EMAIL_FS_SEEK(hd, EMAIL_STOR_ACCT_INFO_POS(acct_id), FS_FILE_BEGIN);
    ret = FS_Write(hd, acct_info, sizeof(srv_email_acct_info_struct), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(srv_email_acct_info_struct))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;
    }

    acct_checksum = srv_email_checksum_compute_by_hd(hd,sizeof(EMAIL_CHECKSUM));
    ret = srv_email_checksum_write_by_hd(hd,
                                         EMAIL_STOR_ACCT_INFO_CHECKSUM_POS,
                                         acct_checksum);
    if (ret != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;
    }
    EMAIL_FS_CLOSE(hd);
    /************************* ORIGINAL file DONE *************************/

    /************************* BACKUP file START *************************/
    email_stor_fs_acct_info_gen_path(path, EMAIL_STOR_FS_ACCT_INFO_BAK);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE)))
    {
        /* account info file not exist */
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_SEEK(hd, EMAIL_STOR_ACCT_INFO_DEFAULT_ID_POS, FS_FILE_BEGIN);
    if (orig_default_acct_id == acct_id)
    {
        orig_default_acct_id = EMAIL_ACCT_INVALID_ID;
        ret = FS_Write(hd, &orig_default_acct_id, sizeof(EMAIL_ACCT_ID), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_ACCT_ID))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            EMAIL_FS_CLOSE(hd);
            goto STOR_EXIT_HANDLE;
        }
    }

    EMAIL_FS_SEEK(hd, EMAIL_STOR_ACCT_INFO_ACCT_ID_ORDER_POS, FS_FILE_BEGIN);
    ret = FS_Write(hd, acct_id_fs, EMAIL_STOR_ACCT_ID_ARR_SIZE, &rw);
    if (ret != FS_NO_ERROR || rw != EMAIL_STOR_ACCT_ID_ARR_SIZE)
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_SEEK(hd, EMAIL_STOR_ACCT_INFO_POS(acct_id), FS_FILE_BEGIN);
    ret = FS_Write(hd, acct_info, sizeof(srv_email_acct_info_struct), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(srv_email_acct_info_struct))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;
    }

    ret = srv_email_checksum_write_by_hd(hd,
                                         EMAIL_STOR_ACCT_INFO_CHECKSUM_POS,
                                         acct_checksum);
    if (ret != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;
    }
    EMAIL_FS_CLOSE(hd);
    /************************* BACKUP file DONE *************************/

    /* update memory acct info */
    memcpy(&email_stor_p->acct_id_sort,
           acct_id_fs,
           EMAIL_STOR_ACCT_ID_ARR_SIZE);

    email_stor_fs_acct_info_cache_set(
        acct_id,
        acct_info->is_cloud_acct,
        acct_info->protocol, 
        acct_info->acct_name,
        acct_info->email_addr.email_addr);

    email_stor_fs_acct_id_mem_global_set(acct_id, EMAIL_STOR_ACCT_ID_UNUSED);

    email_stor_fs_msg_next_valid_offset_set(acct_id, 0);

    email_stor_path_mfree(path);
    email_stor_mfree(acct_id_fs);
    email_stor_mfree(acct_info);

    email_stor_fs_acct_cache_update_msg_unread_reset(acct_id);
    return SRV_EMAIL_RESULT_SUCC;

STOR_EXIT_HANDLE:
    email_stor_path_mfree(path);
    email_stor_mfree(acct_id_fs);
    email_stor_mfree(acct_info);
    return SRV_EMAIL_RESULT_FS_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_info_read
 * DESCRIPTION
 *  Get account info
 * PARAMETERS
 *  acct_info       [IN/OUT]        Account info
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_acct_info_read(
    srv_email_acct_info_struct *acct_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hd;
    WCHAR *path;
    U32 rw;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (acct_info == NULL || !email_stor_fs_acct_id_valid(acct_info->acct_id))
    {
        return SRV_EMAIL_RESULT_FAIL;
    }

    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_acct_info_gen_path(path, EMAIL_STOR_FS_ACCT_INFO_ORIG);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        /* account info file does not exist */
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    email_stor_path_mfree(path);

    EMAIL_FS_SEEK(hd,
                  EMAIL_STOR_ACCT_INFO_POS(acct_info->acct_id),
                  FS_FILE_BEGIN);
    ret = FS_Read(hd, acct_info, sizeof(srv_email_acct_info_struct), &rw);
    if(ret != FS_NO_ERROR || rw != sizeof(srv_email_acct_info_struct))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        EMAIL_FS_CLOSE(hd);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    EMAIL_FS_CLOSE(hd);
    return SRV_EMAIL_RESULT_SUCC;
}


static MMI_BOOL email_stor_write_async_abort = MMI_FALSE;
static EMAIL_ACCT_ID email_stor_write_async_acct_id = EMAIL_ACCT_INVALID_ID;

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_info_write_async_abort
 * DESCRIPTION
 *  Abort acct info write activity
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_acct_info_write_async_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_stor_write_async_abort = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_info_write_async
 * DESCRIPTION
 *  Write account info (async)
 * PARAMETERS
 *  acct_info   [IN]    account basic info
 *  callback    [IN]    callback
 *  user_data   [IN]    user data
 * RETURNS
 *  srv_email_result_enum
 *****************************************************************************/
srv_email_result_enum email_stor_fs_acct_info_write_async(
                        const srv_email_acct_info_struct *acct_info,
                        srv_email_stor_acct_write_funcptr_type callback, 
                        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_add_acct = MMI_FALSE;
    email_stor_fs_acct_info_write_async_struct *acct_info_write_async;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (acct_info == NULL ||
        !email_stor_fs_acct_id_valid_range(acct_info->acct_id))
    {
        MMI_ASSERT(0);
    }

    if (email_stor_fs_acct_id_mem_global_get(acct_info->acct_id) ==
        EMAIL_STOR_ACCT_ID_LOCK)
    {
        is_add_acct = MMI_TRUE;
    }

    if (!is_add_acct)   // is UPDATE, not ADD
    {
        return email_stor_fs_acct_info_write(acct_info);
    }

    acct_info_write_async = email_stor_malloc(sizeof(*acct_info_write_async));
    if (acct_info_write_async == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(*acct_info_write_async));
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    memset(acct_info_write_async, 0, sizeof(*acct_info_write_async));
    acct_info_write_async->add_acct = is_add_acct;
    acct_info_write_async->acct_info = (srv_email_acct_info_struct*)acct_info;
    acct_info_write_async->current_fldr_index = SRV_EMAIL_FLDR_TYPE_BASICS_BGN;
    acct_info_write_async->callback = callback;
    acct_info_write_async->user_data = user_data;

    email_stor_write_async_abort = MMI_FALSE;
    email_stor_write_async_acct_id = acct_info->acct_id;

    srv_email_schdl_start_job(
        (srv_email_schdl_funcptr_type)email_stor_fs_acct_info_write_async_run,
        (void*)acct_info_write_async);
    return SRV_EMAIL_RESULT_WOULDBLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_info_write_async_run
 * DESCRIPTION
 *  Main process of writing account info (async)
 * PARAMETERS
 *  acct_info_write_async   [IN]    account basic info
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_acct_info_write_async_run(
    email_stor_fs_acct_info_write_async_struct *acct_info_write_async)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    S32 dir_exist;
    U32 rw;
    srv_email_result_enum result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_stor_write_async_abort)
    {
        email_stor_write_async_abort = MMI_FALSE;
        email_stor_fs_acct_gen_path(email_stor_write_async_acct_id,
                                    (WCHAR*)&acct_info_write_async->path);
        email_stor_fs_acct_id_mem_global_set(email_stor_write_async_acct_id,
                                             EMAIL_STOR_ACCT_ID_UNUSED);
        email_stor_write_async_acct_id = EMAIL_ACCT_INVALID_ID;
        FS_XDelete(acct_info_write_async->path,
                   FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
        return;
    }

    if (!acct_info_write_async->check_before_create_fldr)
    {
        email_stor_fs_acct_gen_path(acct_info_write_async->acct_info->acct_id,
                                    acct_info_write_async->path);
        dir_exist = srv_email_util_dir_exist(acct_info_write_async->path);
        if (dir_exist < 0)
        {
            EMAIL_STOR_TRACE_FS_CREATE_DIR(dir_exist);
            result = SRV_EMAIL_RESULT_FS_ERROR;
            goto STOR_EXIT_HANDLE;
        }
        if (!dir_exist)
        {
            ret = FS_CreateDir((WCHAR*)&acct_info_write_async->path);
            if (ret != FS_NO_ERROR)
            {
                EMAIL_STOR_TRACE_FS_CREATE_DIR(ret);
                result = SRV_EMAIL_RESULT_FS_ERROR;
                goto STOR_EXIT_HANDLE;
            }
        }
        acct_info_write_async->check_before_create_fldr = MMI_TRUE;
        
        srv_email_schdl_start_job((srv_email_schdl_funcptr_type)
            email_stor_fs_acct_info_write_async_run,
            (void*)acct_info_write_async);
        return;
    }
    else if (acct_info_write_async->current_fldr_index <=
             SRV_EMAIL_FLDR_TYPE_BASICS_END)
    {
        acct_info_write_async->fldr_info.fldr_type = 
            (srv_email_fldr_type_enum)acct_info_write_async->current_fldr_index;

        result = srv_email_stor_fldr_create(
                    acct_info_write_async->acct_info->acct_id,
                    &acct_info_write_async->fldr_info, 
                    NULL);

        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            /* NO EMAIL_STOR_TRACE_FS_CREATE_DIR(result),
               because errno has already been set */
            result = SRV_EMAIL_RESULT_FS_ERROR;
            goto STOR_EXIT_HANDLE;
        }

        acct_info_write_async->current_fldr_index++;

        srv_email_schdl_start_job((srv_email_schdl_funcptr_type)
            email_stor_fs_acct_info_write_async_run,
            (void*)acct_info_write_async);
        return;
    }
    else
    {
        FS_HANDLE hd;
        EMAIL_ACCT_ID i;
        EMAIL_CHECKSUM acct_info_checksum;
        
        /************************* ORIGINAL file START ************************/
        email_stor_fs_acct_info_gen_path((WCHAR*)&acct_info_write_async->path,
                                         EMAIL_STOR_FS_ACCT_INFO_ORIG);

        hd = EMAIL_FS_OPEN((WCHAR*)&acct_info_write_async->path, FS_READ_WRITE);
        if (EMAIL_STOR_FS_HANDLE_INVALID(hd))
        {
            EMAIL_STOR_TRACE_FS_OPEN(hd);
            result = SRV_EMAIL_RESULT_FS_ERROR;
            goto STOR_EXIT_HANDLE;
        }

        EMAIL_FS_SEEK(hd, EMAIL_STOR_ACCT_INFO_ACCT_ID_ORDER_POS,FS_FILE_BEGIN);
        ret = FS_Read(hd,
                      &acct_info_write_async->acct_id_fs,
                      EMAIL_STOR_ACCT_ID_ARR_SIZE, &rw);
        if (ret != FS_NO_ERROR || rw != EMAIL_STOR_ACCT_ID_ARR_SIZE)
        {
            EMAIL_STOR_TRACE_FS_READ(ret, rw);
            EMAIL_FS_CLOSE(hd);
            result = SRV_EMAIL_RESULT_FS_ERROR;
            goto STOR_EXIT_HANDLE;
        }

        for (i = 0; i < EMAIL_STOR_ACCT_NUM_MAX; i++)
        {
            if (acct_info_write_async->acct_id_fs[i] == EMAIL_ACCT_INVALID_ID)
            {
                acct_info_write_async->acct_id_fs[i] =
                    acct_info_write_async->acct_info->acct_id;
                break;
            }
        }
        MMI_ASSERT(i < EMAIL_STOR_ACCT_NUM_MAX);   /* no unused pos found */
        memcpy(&email_stor_p->acct_id_sort,
               &acct_info_write_async->acct_id_fs,
               EMAIL_STOR_ACCT_ID_ARR_SIZE);

        EMAIL_FS_SEEK(hd, EMAIL_STOR_ACCT_INFO_ACCT_ID_ORDER_POS,FS_FILE_BEGIN);
        ret = FS_Write(hd,
                       &acct_info_write_async->acct_id_fs,
                       EMAIL_STOR_ACCT_ID_ARR_SIZE, &rw);
        if (ret != FS_NO_ERROR || rw != EMAIL_STOR_ACCT_ID_ARR_SIZE)
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            EMAIL_FS_CLOSE(hd);
            result = SRV_EMAIL_RESULT_FS_ERROR;
            goto STOR_EXIT_HANDLE;
        }

        email_stor_fs_acct_id_mem_global_set(
            acct_info_write_async->acct_info->acct_id, EMAIL_STOR_ACCT_ID_USED);

        EMAIL_FS_SEEK(hd,
                      EMAIL_STOR_ACCT_INFO_POS(
                        acct_info_write_async->acct_info->acct_id),
                      FS_FILE_BEGIN);
        ret = FS_Write(hd,
                       acct_info_write_async->acct_info,
                       sizeof(srv_email_acct_info_struct), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(srv_email_acct_info_struct))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            EMAIL_FS_CLOSE(hd);
            result = SRV_EMAIL_RESULT_FS_ERROR;
            goto STOR_EXIT_HANDLE;
        }

        acct_info_checksum = srv_email_checksum_compute_by_hd(
                                hd, sizeof(EMAIL_CHECKSUM));
        srv_email_checksum_write_by_hd(hd,
                                       EMAIL_STOR_ACCT_INFO_CHECKSUM_POS,
                                       acct_info_checksum);
        EMAIL_FS_CLOSE(hd);
        /************************* ORIGINAL file DONE *************************/

        /************************* BACKUP file START *************************/
        email_stor_fs_acct_info_gen_path((WCHAR*)&acct_info_write_async->path,
                                         EMAIL_STOR_FS_ACCT_INFO_BAK);

        hd = EMAIL_FS_OPEN((WCHAR*)&acct_info_write_async->path, FS_READ_WRITE);
        if (EMAIL_STOR_FS_HANDLE_INVALID(hd))
        {
            EMAIL_STOR_TRACE_FS_OPEN(hd);
            result = SRV_EMAIL_RESULT_FS_ERROR;
            goto STOR_EXIT_HANDLE;
        }

        EMAIL_FS_SEEK(hd, EMAIL_STOR_ACCT_INFO_ACCT_ID_ORDER_POS,FS_FILE_BEGIN);
        ret = FS_Write(hd,
                       &acct_info_write_async->acct_id_fs,
                       EMAIL_STOR_ACCT_ID_ARR_SIZE, &rw);
        if (ret != FS_NO_ERROR || rw != EMAIL_STOR_ACCT_ID_ARR_SIZE)
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            EMAIL_FS_CLOSE(hd);
            result = SRV_EMAIL_RESULT_FS_ERROR;
            goto STOR_EXIT_HANDLE;
        }

        EMAIL_FS_SEEK(hd,
            EMAIL_STOR_ACCT_INFO_POS(acct_info_write_async->acct_info->acct_id),
            FS_FILE_BEGIN);
        ret = FS_Write(hd,
                       acct_info_write_async->acct_info,
                       sizeof(srv_email_acct_info_struct), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(srv_email_acct_info_struct))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            EMAIL_FS_CLOSE(hd);
            result = SRV_EMAIL_RESULT_FS_ERROR;
            goto STOR_EXIT_HANDLE;
        }

        srv_email_checksum_write_by_hd(hd,
                                       EMAIL_STOR_ACCT_INFO_CHECKSUM_POS,
                                       acct_info_checksum);
        EMAIL_FS_CLOSE(hd);
        /************************* BACKUP file DONE *************************/
        
        email_stor_fs_acct_info_cache_set(
            acct_info_write_async->acct_info->acct_id,
            acct_info_write_async->acct_info->is_cloud_acct,
            acct_info_write_async->acct_info->protocol,
            acct_info_write_async->acct_info->acct_name,
            acct_info_write_async->acct_info->email_addr.email_addr);
        email_stor_fs_acct_unread_set_directly(
            acct_info_write_async->acct_info->acct_id, 0);

        result = SRV_EMAIL_RESULT_SUCC;
        /* NO return here!!! */
    }

STOR_EXIT_HANDLE:
    {
        srv_email_stor_acct_write_funcptr_type callback =
            acct_info_write_async->callback;
        void* user_data = acct_info_write_async->user_data;

        email_stor_mfree(acct_info_write_async);
        if (callback != NULL)
        {
            callback(result, user_data);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_acct_info_write
 * DESCRIPTION
 *  Write account info
 * PARAMETERS
 *  acct_info       [IN]        Account info
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_acct_info_write(
    const srv_email_acct_info_struct *acct_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_ACCT_ID *acct_id_fs;
    FS_HANDLE hd;
    WCHAR *path;
    U32 rw;
    S32 ret;
    S32 dir_exist;
    srv_email_result_enum result;
    EMAIL_CHECKSUM acct_info_checksum;
    MMI_BOOL is_add_acct = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (acct_info == NULL ||
        !email_stor_fs_acct_id_valid_range(acct_info->acct_id))
    {
        MMI_ASSERT(0);
        return SRV_EMAIL_RESULT_INVALID_ACCT;
    }

    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    if ((acct_id_fs = email_stor_malloc(EMAIL_STOR_ACCT_ID_ARR_SIZE)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_ACCT_ID_ARR_SIZE);
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    /* it's ADD account, NOT UPDATE account */
    if (email_stor_fs_acct_id_mem_global_get(acct_info->acct_id) ==
        EMAIL_STOR_ACCT_ID_LOCK)
    {
        is_add_acct = MMI_TRUE;
    }
    if (is_add_acct)
    {
        srv_email_fldr_type_enum i;
        srv_email_stor_fldr_create_info_struct fldr_info;

        email_stor_fs_acct_gen_path(acct_info->acct_id, path);
        dir_exist = srv_email_util_dir_exist(path);
        if (dir_exist < 0)
        {
            EMAIL_STOR_TRACE_FS_CREATE_DIR(dir_exist);
            goto STOR_EXIT_HANDLE;
        }
        if (!dir_exist)
        {
            if ((ret = FS_CreateDir(path)) != FS_NO_ERROR)
            {
                EMAIL_STOR_TRACE_FS_CREATE_DIR(ret);
                goto STOR_EXIT_HANDLE;
            }
        }

        for (i = SRV_EMAIL_FLDR_TYPE_BASICS_BGN;
             i <= SRV_EMAIL_FLDR_TYPE_BASICS_END; ++i)
        {
            fldr_info.fldr_type = i;
            result = srv_email_stor_fldr_create(acct_info->acct_id,
                                                &fldr_info, NULL);
            if (result != SRV_EMAIL_RESULT_SUCC)
            {
                /* NO EMAIL_STOR_TRACE_FS_CREATE_DIR(result),
                   because errno has already been set */
                email_stor_path_mfree(path);
                return result;
            }
        }
    }

    /************************* ORIGINAL file START *************************/
    email_stor_fs_acct_info_gen_path(path, EMAIL_STOR_FS_ACCT_INFO_ORIG);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE)))
    {
        /* account info file not exist */
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        goto STOR_EXIT_HANDLE;
    }

    if (is_add_acct) /* it's ADD account, NOT UPDATE account */
    {
        EMAIL_ACCT_ID i;
        
        EMAIL_FS_SEEK(hd, EMAIL_STOR_ACCT_INFO_ACCT_ID_ORDER_POS,FS_FILE_BEGIN);
        ret = FS_Read(hd, acct_id_fs, EMAIL_STOR_ACCT_ID_ARR_SIZE, &rw);
        if (ret != FS_NO_ERROR || rw != EMAIL_STOR_ACCT_ID_ARR_SIZE)
        {
            EMAIL_STOR_TRACE_FS_READ(ret, rw);
            EMAIL_FS_CLOSE(hd);
            goto STOR_EXIT_HANDLE;
        }

        for (i = 0; i < EMAIL_STOR_ACCT_NUM_MAX; i++)
        {
            if (acct_id_fs[i] == EMAIL_ACCT_INVALID_ID)
            {
                acct_id_fs[i] = acct_info->acct_id;
                break;
            }
        }
        MMI_ASSERT(i < EMAIL_STOR_ACCT_NUM_MAX);   /* no unused pos found */
        memcpy(&email_stor_p->acct_id_sort,
               acct_id_fs,
               EMAIL_STOR_ACCT_ID_ARR_SIZE);

        EMAIL_FS_SEEK(hd, EMAIL_STOR_ACCT_INFO_ACCT_ID_ORDER_POS,FS_FILE_BEGIN);
        ret = FS_Write(hd, acct_id_fs, EMAIL_STOR_ACCT_ID_ARR_SIZE, &rw);
        if (ret != FS_NO_ERROR || rw != EMAIL_STOR_ACCT_ID_ARR_SIZE)
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            EMAIL_FS_CLOSE(hd);
            goto STOR_EXIT_HANDLE;
        }

        email_stor_fs_acct_id_mem_global_set(
            acct_info->acct_id, EMAIL_STOR_ACCT_ID_USED);
        email_stor_fs_acct_unread_set_directly(acct_info->acct_id, 0);
    }

    EMAIL_FS_SEEK(hd,
                  EMAIL_STOR_ACCT_INFO_POS(acct_info->acct_id),
                  FS_FILE_BEGIN);
    ret = FS_Write(hd, (void*)acct_info, sizeof(*acct_info), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(*acct_info))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;
    }

    acct_info_checksum = srv_email_checksum_compute_by_hd(
                            hd, sizeof(EMAIL_CHECKSUM));
    srv_email_checksum_write_by_hd(
        hd, EMAIL_STOR_ACCT_INFO_CHECKSUM_POS, acct_info_checksum);
    EMAIL_FS_CLOSE(hd);
    /************************* ORIGINAL file DONE *************************/

    /************************* BACKUP file START *************************/
    email_stor_fs_acct_info_gen_path(path, EMAIL_STOR_FS_ACCT_INFO_BAK);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE)))
    {
        /* account info file not exist */
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        goto STOR_EXIT_HANDLE;
    }

    if (is_add_acct) /* it's ADD account, NOT UPDATE account */
    {
        EMAIL_FS_SEEK(hd, EMAIL_STOR_ACCT_INFO_ACCT_ID_ORDER_POS,FS_FILE_BEGIN);
        ret = FS_Write(hd, acct_id_fs, EMAIL_STOR_ACCT_ID_ARR_SIZE, &rw);
        if (ret != FS_NO_ERROR || rw != EMAIL_STOR_ACCT_ID_ARR_SIZE)
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            EMAIL_FS_CLOSE(hd);
            goto STOR_EXIT_HANDLE;
        }
    }

    EMAIL_FS_SEEK(hd,
                  EMAIL_STOR_ACCT_INFO_POS(acct_info->acct_id),
                  FS_FILE_BEGIN);
    ret = FS_Write(hd, (void*)acct_info, sizeof(*acct_info), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(*acct_info))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;
    }
    
    srv_email_checksum_write_by_hd(
        hd, EMAIL_STOR_ACCT_INFO_CHECKSUM_POS, acct_info_checksum);
    EMAIL_FS_CLOSE(hd);

    /************************* BACKUP file DONE *************************/

    email_stor_fs_acct_info_cache_set(
        acct_info->acct_id, 
        acct_info->is_cloud_acct,
        acct_info->protocol, 
        acct_info->acct_name,
        acct_info->email_addr.email_addr);

    email_stor_path_mfree(path);
    email_stor_mfree(acct_id_fs);
    return SRV_EMAIL_RESULT_SUCC;

STOR_EXIT_HANDLE:
    email_stor_path_mfree(path);
    email_stor_mfree(acct_id_fs);
    return SRV_EMAIL_RESULT_FS_ERROR;
}


extern srv_email_result_enum email_stor_acct_set_cloud_acct(
                                EMAIL_ACCT_ID acct_id,
                                MMI_BOOL is_cloud_acct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 rw;
    S32 ret;
    WCHAR *path;
    FS_HANDLE hd;
    //srv_email_result_enum result;
    EMAIL_CHECKSUM acct_info_checksum;
    //MMI_BOOL is_add_acct = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!email_stor_fs_acct_id_valid_range(acct_id))
    {
        MMI_ASSERT(0);
        return SRV_EMAIL_RESULT_INVALID_ACCT;
    }

    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    } 

    /************************* ORIGINAL file START *************************/
    email_stor_fs_acct_info_gen_path(path, EMAIL_STOR_FS_ACCT_INFO_ORIG);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE)))
    {
        /* account info file not exist */
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        goto STOR_EXIT_HANDLE;
    } 

    EMAIL_FS_SEEK(hd,
                  EMAIL_STOR_ACCT_INFO_POS(acct_id) +
                  EMAIL_STOR_POS_IN_STRUCT(srv_email_acct_info_struct, is_cloud_acct),
                  FS_FILE_BEGIN);
    ret = FS_Write(hd, (void*)&is_cloud_acct, sizeof(is_cloud_acct), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(is_cloud_acct))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;
    }

    acct_info_checksum = srv_email_checksum_compute_by_hd(
                            hd, sizeof(EMAIL_CHECKSUM));
    srv_email_checksum_write_by_hd(
        hd, EMAIL_STOR_ACCT_INFO_CHECKSUM_POS, acct_info_checksum);
    EMAIL_FS_CLOSE(hd);
    /************************* ORIGINAL file DONE *************************/

    /************************* BACKUP file START *************************/
    email_stor_fs_acct_info_gen_path(path, EMAIL_STOR_FS_ACCT_INFO_BAK);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE)))
    {
        /* account info file not exist */
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        goto STOR_EXIT_HANDLE;
    } 

    EMAIL_FS_SEEK(hd,
                  EMAIL_STOR_ACCT_INFO_POS(acct_id) +
                  EMAIL_STOR_POS_IN_STRUCT(srv_email_acct_info_struct, is_cloud_acct),
                  FS_FILE_BEGIN);
    ret = FS_Write(hd, (void*)&is_cloud_acct, sizeof(is_cloud_acct), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(is_cloud_acct))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;
    }
    
    srv_email_checksum_write_by_hd(
        hd, EMAIL_STOR_ACCT_INFO_CHECKSUM_POS, acct_info_checksum);
    EMAIL_FS_CLOSE(hd);

    /************************* BACKUP file DONE *************************/

    email_stor_fs_acct_info_cache_set(
        acct_id, 
        is_cloud_acct,
        SRV_EMAIL_PROT_TOTAL,
        NULL,
        NULL);

    email_stor_path_mfree(path); 
    return SRV_EMAIL_RESULT_SUCC;

STOR_EXIT_HANDLE:
    email_stor_path_mfree(path); 
    return SRV_EMAIL_RESULT_FS_ERROR;
}
