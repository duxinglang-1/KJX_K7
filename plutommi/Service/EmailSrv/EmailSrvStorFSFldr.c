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
 *  EmailSrvStorFSFldr.c
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "Conversions.h"
#include "EmailSrvGprot.h"
#include "EmailSrvProt.h"
#include "EmailSrvStorage.h"
#include "EmailSrvStorFS.h"

#include "mmi_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "string.h"
#include "fs_gprot.h"
#include "customer_ps_inc.h"
#include "Unicodexdcl.h"

#ifdef EMAIL_STOR_FILE
#undef EMAIL_STOR_FILE
#endif
#define EMAIL_STOR_FILE 'F'



/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_flag_link_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  header          [IN]        
 *  offset          [IN]        
 *  new_flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_msg_flag_link_add(
        email_stor_fs_msg_flag_link_struct **header,
        EMAIL_STOR_OFFSET offset,
        EMAIL_MSG_FLAG new_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_msg_flag_link_struct *tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*header == NULL)
    {
        *header = email_stor_malloc(sizeof(**header));
        if (*header == NULL)
        {
            EMAIL_STOR_TRACE_MALLOC(sizeof(**header));
            MMI_ASSERT(0);
            return; /* SRV_EMAIL_RESULT_NO_MEMORY; */
        }
        (*header)->next = NULL;
        (*header)->offset = offset;
        (*header)->new_flag = new_flag;
    }
    else
    {
        tail = *header;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }

        tail->next = email_stor_malloc(sizeof(*(tail->next)));
        if (tail->next == NULL)
        {
            EMAIL_STOR_TRACE_MALLOC(sizeof(*(tail->next)));
            MMI_ASSERT(0);
            return; /* SRV_EMAIL_RESULT_NO_MEMORY; */
        }
        tail = tail->next;
        tail->next = NULL;
        tail->offset = offset;
        tail->new_flag = new_flag;
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_del_link_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  header          [IN]        
 *  offset          [IN]        
 *  new_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_msg_del_link_add(
        email_stor_fs_msg_del_link_struct **header,
        EMAIL_STOR_OFFSET offset,
        EMAIL_MSG_STATE new_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_msg_del_link_struct *tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*header == NULL)
    {
        if ((*header = email_stor_malloc(sizeof(**header))) == NULL)
        {
            EMAIL_STOR_TRACE_MALLOC(sizeof(**header));
            MMI_ASSERT(0);
            return; /* SRV_EMAIL_RESULT_NO_MEMORY; */
        }
        (*header)->next = NULL;
        (*header)->offset = offset;
        (*header)->new_state = new_state;
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
            MMI_ASSERT(0);
            return; /* SRV_EMAIL_RESULT_NO_MEMORY; */
        }
        tail = tail->next;
        tail->next = NULL;
        tail->offset = offset;
        tail->new_state = new_state;
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_sync_link_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  header              [IN]        
 *  offset              [IN]        
 *  del_server_flag     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_msg_sync_link_add(
        email_stor_fs_msg_sync_link_struct **header,
        EMAIL_STOR_OFFSET offset,
        MMI_BOOL del_server_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_msg_sync_link_struct *tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*header == NULL)
    {
        if ((*header = email_stor_malloc(sizeof(**header))) == NULL)
        {
            EMAIL_STOR_TRACE_MALLOC(sizeof(**header));
            return; /* SRV_EMAIL_RESULT_NO_MEMORY; */
        }
        (*header)->next = NULL;
        (*header)->offset = offset;
        (*header)->del_server_flag = del_server_flag;
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
            return; /* SRV_EMAIL_RESULT_NO_MEMORY; */
        }
        tail = tail->next;
        tail->next = NULL;
        tail->offset = offset;
        tail->del_server_flag = del_server_flag;
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_offset_link_free
 * DESCRIPTION
 *  Free MSG offset linked list
 * PARAMETERS
 *  header      [IN]        MSG offset linked list header
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_msg_offset_link_free(
    email_stor_fs_msg_offset_link_struct *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_msg_offset_link_struct *temp;

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
 *  email_stor_fs_msg_flag_link_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  header      [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_msg_flag_link_free(
    email_stor_fs_msg_flag_link_struct *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_msg_flag_link_struct *temp;

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
 *  email_stor_fs_msg_sync_link_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  header      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_msg_sync_link_free(
    email_stor_fs_msg_sync_link_struct *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_msg_sync_link_struct *temp;

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
 *  email_stor_fs_fldr_create_simple
 * DESCRIPTION
 *  create a folder
 * PARAMETERS
 *  acct_id         [IN]        Account id
 *  fldr_id         [IN]        Folder id
 *  fldr_type       [IN]        Folder type
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_create_simple(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        srv_email_fldr_type_enum fldr_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_stor_fldr_create_info_struct fldr_info = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fldr_info.fldr_type = fldr_type;

    return email_stor_fs_fldr_create(acct_id, fldr_id, &fldr_info);
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_create
 * DESCRIPTION
 *  create a folder
 * PARAMETERS
 *  acct_id         [IN]        Account id
 *  fldr_id         [IN]        Folder id
 *  fldr_info       [IN]        Folder info
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_create(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        const srv_email_stor_fldr_create_info_struct *fldr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_stor_fldr_struct *fldr_header;
    WCHAR *index_path;
    WCHAR *backup_path;
    FS_HANDLE hd;
    U32 rw;
    S32 ret;
    EMAIL_CHECKSUM checksum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((fldr_info->fldr_type >= SRV_EMAIL_FLDR_TYPE_BASICS_BGN &&
                fldr_info->fldr_type <= SRV_EMAIL_FLDR_TYPE_BASICS_END) ||
               fldr_info->fldr_type == SRV_EMAIL_FLDR_TYPE_REMOTE);

    EMAIL_STOR_TRACE_FLDR_CREATE(0);

    if ((fldr_header = email_stor_malloc(sizeof(*fldr_header))) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(*fldr_header));
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    index_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN);
    if (index_path == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        email_stor_mfree(fldr_header);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    backup_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN);
    if (backup_path == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        email_stor_mfree(fldr_header);
        email_stor_path_mfree(index_path);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    /* init the written data */
    fldr_header->total_count = 0;
    fldr_header->unread_count = 0;
    fldr_header->uid_validity = fldr_info->uid_validity;
    strncpy(fldr_header->fldr_name, fldr_info->fldr_name, EMAIL_FLDR_NAME_LEN);
    fldr_header->fldr_name[EMAIL_FLDR_NAME_LEN] = 0;
    fldr_header->fldr_name_separator = fldr_info->fldr_name_separator;
    fldr_header->fldr_type = fldr_info->fldr_type;

    /* delete original folder */
    email_stor_fs_fldr_del_dir_files(acct_id, fldr_id, MMI_FALSE);

    email_stor_fs_fldr_gen_path(
        acct_id, fldr_id, EMAIL_STOR_FLDR_INDEX, index_path);

    /* write Index file */
    hd = EMAIL_FS_OPEN(index_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        goto STOR_EXIT_HANDLE;
    }

    /* checksum */
    EMAIL_FS_SEEK(hd, sizeof(EMAIL_CHECKSUM), FS_FILE_BEGIN);

    /* folder header */
    ret = FS_Write(hd,
                   fldr_header,
                   sizeof(srv_email_stor_fldr_struct),
                   &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(srv_email_stor_fldr_struct))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;
    }

    /* index */
    email_stor_fs_inbox_index_memset();
    email_stor_p->inbox_index_size = EMAIL_STOR_MAX_MSG_NUM_PER_FLDR;
    email_stor_fs_inbox_index_write(hd);

    checksum = srv_email_checksum_compute_by_hd(hd, sizeof(EMAIL_CHECKSUM));

    EMAIL_FS_SEEK(hd, 0, FS_FILE_BEGIN);
    ret = FS_Write(hd, &checksum, sizeof(EMAIL_CHECKSUM), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_CHECKSUM))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        EMAIL_FS_CLOSE(hd);
        goto STOR_EXIT_HANDLE;
    }
    EMAIL_FS_CLOSE(hd);

    /* write Backup file */
    email_stor_fs_fldr_gen_path(
        acct_id, fldr_id, EMAIL_STOR_FLDR_BACKUP, backup_path);

    ret = FS_Move(index_path,
                  backup_path,
                  FS_MOVE_OVERWRITE | FS_MOVE_COPY, NULL, NULL, 0);
    if (ret != FS_NO_ERROR)
    {
        EMAIL_STOR_TRACE_FS_COPY(ret);
        goto STOR_EXIT_HANDLE;
    }

    email_stor_path_mfree(index_path);
    email_stor_path_mfree(backup_path);
    email_stor_mfree(fldr_header);

    EMAIL_STOR_TRACE_FLDR_CREATE(1);

    return SRV_EMAIL_RESULT_SUCC;

STOR_EXIT_HANDLE:
    email_stor_fs_fldr_del_dir_files(acct_id, fldr_id, MMI_FALSE);
    email_stor_path_mfree(index_path);
    email_stor_path_mfree(backup_path);
    email_stor_mfree(fldr_header);
    EMAIL_STOR_TRACE_FLDR_CREATE(1);
    return SRV_EMAIL_RESULT_FS_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_del
 * DESCRIPTION
 *  Delete a folder
 * PARAMETERS
 *  acct_id         [IN]        Account id
 *  fldr_id_arr     [?]         
 *  fldr_id_num     [IN]        
 *  callback        [IN]        Callback
 *  user_data       [IN]        User data
 *  req_id(?)       [IN]        Request id
 *  fldr_id(?)      [IN]        Folder id
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_del(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID *fldr_id_arr,
                        U32 fldr_id_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < fldr_id_num; i++)
    {
        EMAIL_STOR_TRACE_FLDR_DEL(acct_id, *(fldr_id_arr + i), 0);
        email_stor_fs_fldr_del_dir_files(acct_id, *(fldr_id_arr+i), MMI_FALSE);
        *(fldr_id_arr + i) = EMAIL_FLDR_INVALID_ID;
        EMAIL_STOR_TRACE_FLDR_DEL(acct_id, *(fldr_id_arr + i), 1);
    }   // TODO: 

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_del_dir_files
 * DESCRIPTION
 *  Delete an folder's directories and files
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  fldr_id     [IN]        Folder id
 *  care_error  [IN]        if care error, when error hanppen, exit;
 *                          otherwise, deleting all files/DIR(s)0
 * RETURNS
 *  void
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_del_dir_files(
    EMAIL_ACCT_ID acct_id, EMAIL_FLDR_ID fldr_id, MMI_BOOL care_error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    WCHAR *path;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_fldr_gen_path(acct_id, fldr_id, EMAIL_STOR_FLDR_INDEX, path);
    ret = FS_Delete(path);
    if (ret != FS_NO_ERROR && care_error)
    {
        goto STOR_EXIT_HANDLE;
    }

    email_stor_fs_fldr_gen_path(acct_id, fldr_id, EMAIL_STOR_FLDR_BACKUP, path);
    ret = FS_Delete(path);
    if (ret != FS_NO_ERROR && care_error)
    {
        goto STOR_EXIT_HANDLE;
    }
    
    email_stor_fs_fldr_parts_root_gen_path(acct_id, fldr_id, path);
    ret = FS_XDelete(path,
                     FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE,
                     NULL, 0);
    if (ret < FS_NO_ERROR && care_error)
    {
        goto STOR_EXIT_HANDLE;
    }
    
    email_stor_fs_fldr_attch_root_gen_path(acct_id, fldr_id, path);
    ret = FS_XDelete(path,
                     FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    if (ret < FS_NO_ERROR && care_error)
    {
        goto STOR_EXIT_HANDLE;
    }
    
    email_stor_path_mfree(path);
    return SRV_EMAIL_RESULT_SUCC;
    
STOR_EXIT_HANDLE:
    email_stor_path_mfree(path);
    return SRV_EMAIL_RESULT_FS_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_del_msg_link_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  header      [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void email_stor_fs_fldr_del_msg_link_free(
    email_stor_fs_msg_del_link_struct *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_msg_del_link_struct *temp;

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
 *  email_stor_fs_fldr_del_msg_open
 * DESCRIPTION
 *  Prepare to delete a MSG
 * PARAMETERS
 *  fldr_type               [IN]        Folder type
 *  acct_id                 [IN]        Account id
 *  fldr_id                 [IN]        Folder id
 *  del_header              [IN]        Whether delete header
 *  del_server_later        [IN]        Mark whether delete form server later
 *  handle                  [OUT]       Handle
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_del_msg_open(
                        srv_email_fldr_type_enum fldr_type,
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        MMI_BOOL del_header,
                        MMI_BOOL del_server_later,
                        EMAIL_STOR_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    email_stor_fs_fldr_del_msg_struct *hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAIL_STOR_TRACE_MSG_DEL(acct_id, fldr_id, 0);

    hd = email_stor_malloc(sizeof(*hd));
    if (hd == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(*hd));
        *handle = EMAIL_STOR_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    *handle = (EMAIL_STOR_HANDLE)hd;

    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        *handle = EMAIL_STOR_INVALID_HANDLE;
        email_stor_mfree(hd);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_fldr_gen_path(acct_id, fldr_id, EMAIL_STOR_FLDR_INDEX, path);

    hd->hd = EMAIL_FS_OPEN(path, FS_READ_WRITE);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd->hd))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd->hd);
        email_stor_path_mfree(path);
        email_stor_mfree(hd);
        *handle = EMAIL_STOR_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    email_stor_path_mfree(path);

    /* get file size */
    EMAIL_FS_SEEK(hd->hd, 0, FS_FILE_END);
    FS_GetFilePosition(hd->hd, &hd->pos_end);

    hd->acct_id = acct_id;
    hd->fldr_id = fldr_id;
    hd->del_header = del_header;
    hd->del_server_later = del_server_later;
    hd->offset_header = NULL;
    hd->total_num_chg = 0;
    hd->unread_num_chg = 0;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_del_msg_next
 * DESCRIPTION
 *  Delete a MSG
 * PARAMETERS
 *  handle      [IN]        Handle
 *  offset      [IN]        Offset
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_del_msg_next(
    EMAIL_STOR_HANDLE handle, EMAIL_STOR_OFFSET offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_fldr_del_msg_struct *hd = 
        (email_stor_fs_fldr_del_msg_struct*) handle;
    email_stor_attch_id_link_struct *attch_id_header = NULL;
    MMI_BOOL valid;
    EMAIL_MSG_FLAG flag;
    EMAIL_MSG_STATE state;
    U32 rw = 0;
    S32 ret;
    U32 seek_pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    seek_pos = EMAIL_STOR_MSG_RECORD_POS(offset);
    if (seek_pos > hd->pos_end)
    {
        return SRV_EMAIL_RESULT_INVALID_MSG;
    }
    EMAIL_FS_SEEK(hd->hd, seek_pos, FS_FILE_BEGIN);
    ret = FS_Read(hd->hd, &valid, sizeof(MMI_BOOL), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(MMI_BOOL))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    if (!valid)
    {
        return SRV_EMAIL_RESULT_INVALID_MSG;   /* this MSG not valid */
    }

    /* read original flag */
    EMAIL_FS_SEEK(hd->hd, EMAIL_STOR_MSG_LATEST_FLAG_POS(offset),FS_FILE_BEGIN);
    ret = FS_Read(hd->hd, &flag, sizeof(EMAIL_MSG_FLAG), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_FLAG))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    if (hd->del_header || hd->del_server_later)
    {
        /* calculate changed unread number */
        if (!(flag & EMAIL_MSG_FLAG_SEEN))
        {
            hd->unread_num_chg--;
        }
        hd->total_num_chg--;
    }

    if (hd->del_header) /* delete Header & Body */
    {
        EMAIL_FS_SEEK(hd->hd, EMAIL_STOR_MSG_RECORD_POS(offset), FS_FILE_BEGIN);
        valid = MMI_FALSE;
        ret = FS_Write(hd->hd, &valid, sizeof(MMI_BOOL), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(MMI_BOOL))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        email_stor_fs_msg_del_link_add(&hd->offset_header, offset, 0);
    }
    else    /* just delete Body */
    {
        /* read original state */
        EMAIL_FS_SEEK(hd->hd, EMAIL_STOR_MSG_STATE_POS(offset), FS_FILE_BEGIN);
        ret = FS_Read(hd->hd, &state, sizeof(EMAIL_MSG_STATE), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_STATE))
        {
            EMAIL_STOR_TRACE_FS_READ(ret, rw);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }

        state |= SRV_EMAIL_MSG_STATE_HEADER_ONLY;
        state |= (hd->del_server_later ? SRV_EMAIL_MSG_STATE_DEL_SERVER : 0);
        EMAIL_FS_SEEK(hd->hd, EMAIL_STOR_MSG_STATE_POS(offset), FS_FILE_BEGIN);
        ret = FS_Write(hd->hd, &state, sizeof(EMAIL_MSG_STATE), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_STATE))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        email_stor_fs_msg_del_link_add(&hd->offset_header, offset, state);
    }

    email_stor_fs_msg_get_attch_id(
        hd->acct_id, hd->fldr_id, offset, &attch_id_header);
    /* MUST ignore the result */
    
    email_stor_fs_attch_del(attch_id_header);
    email_stor_fs_attch_id_link_free(attch_id_header);

    email_stor_fs_msg_parts_del(
        hd->acct_id, hd->fldr_id, offset, SRV_EMAIL_STOR_FILE_CONT_TEXT);
    email_stor_fs_msg_parts_del(
        hd->acct_id, hd->fldr_id, offset, SRV_EMAIL_STOR_FILE_CONT_HTML);
    email_stor_fs_msg_parts_del(
        hd->acct_id, hd->fldr_id, offset, SRV_EMAIL_STOR_FILE_SAA);

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_del_msg_close
 * DESCRIPTION
 *  Close
 * PARAMETERS
 *  handle      [IN]        Handle
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_del_msg_close(EMAIL_STOR_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_fldr_del_msg_struct *hd =
        (email_stor_fs_fldr_del_msg_struct*) handle;
    email_stor_fs_msg_del_link_struct *offset_header;
    srv_email_result_enum result;
    U32 rw = 0;
    MMI_BOOL valid;
    WCHAR *path;
    EMAIL_CHECKSUM checksum;
    U32 new_total_num;
    U32 new_unread_num;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* write INDEX file */
    result = email_stor_fs_msg_num_update(
        hd->hd, &new_unread_num, hd->unread_num_chg, EMAIL_STOR_MSG_UNREAD_NUM);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_FS_CLOSE(hd->hd);
        goto STOR_EXIT_HANDLE;
    }
    
    result = email_stor_fs_msg_num_update(
        hd->hd, &new_total_num, hd->total_num_chg, EMAIL_STOR_MSG_TOTAL_NUM);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_FS_CLOSE(hd->hd);
        goto STOR_EXIT_HANDLE;
    }
    
    new_unread_num += hd->unread_num_chg;
    new_total_num += hd->total_num_chg;

    if (hd->del_header || hd->del_server_later)
    {
        email_stor_p->inbox_index_size = new_total_num - hd->total_num_chg;
        email_stor_fs_inbox_index_read(hd->hd);
        offset_header = hd->offset_header;
        while (offset_header != NULL)
        {
            email_stor_fs_inbox_index_del((U16) offset_header->offset);
            offset_header = offset_header->next;
        }
        email_stor_fs_inbox_index_write(hd->hd);

        if (email_stor_fs_fldr_type_is_inbox(hd->acct_id, hd->fldr_id))
        {
            email_stor_fs_acct_cache_update_msg_unread_chg(
                hd->acct_id, hd->unread_num_chg);
        }
    }

    checksum = srv_email_checksum_compute_by_hd(hd->hd, sizeof(EMAIL_CHECKSUM));
    result = srv_email_checksum_write_by_hd(hd->hd, 0, checksum);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_FS_CLOSE(hd->hd);
        goto STOR_EXIT_HANDLE;
    }
    EMAIL_FS_CLOSE(hd->hd);

    /* write BACKUP file */
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        result = SRV_EMAIL_RESULT_NO_MEMORY;
        goto STOR_EXIT_HANDLE;
    }

    email_stor_fs_fldr_gen_path(
        hd->acct_id, hd->fldr_id, EMAIL_STOR_FLDR_BACKUP, path);

    hd->hd = EMAIL_FS_OPEN(path, FS_READ_WRITE);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd->hd))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd->hd);
        email_stor_path_mfree(path);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }
    email_stor_path_mfree(path);

    offset_header = hd->offset_header;
    while (offset_header != NULL)
    {
        if (hd->del_header)
        {
            valid = MMI_FALSE;
            EMAIL_FS_SEEK(hd->hd,
                          EMAIL_STOR_MSG_RECORD_POS(offset_header->offset),
                          FS_FILE_BEGIN);
            ret = FS_Write(hd->hd, &valid, sizeof(MMI_BOOL), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(MMI_BOOL))
            {
                EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
                result = SRV_EMAIL_RESULT_FS_ERROR;
                EMAIL_FS_CLOSE(hd->hd);
                goto STOR_EXIT_HANDLE;
            }
        }
        else
        {
            EMAIL_FS_SEEK(hd->hd,
                          EMAIL_STOR_MSG_STATE_POS(offset_header->offset),
                          FS_FILE_BEGIN);
            ret = FS_Write(hd->hd,
                           &offset_header->new_state,
                           sizeof(EMAIL_MSG_STATE),
                           &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_STATE))
            {
                EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
                EMAIL_FS_CLOSE(hd->hd);
                result = SRV_EMAIL_RESULT_FS_ERROR;
                goto STOR_EXIT_HANDLE;
            }
        }
        offset_header = offset_header->next;
    }

    if (hd->del_header || hd->del_server_later)
    {
        result = email_stor_fs_inbox_index_write(hd->hd);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            EMAIL_FS_CLOSE(hd->hd);
            goto STOR_EXIT_HANDLE;
        }
    }

    result = email_stor_fs_msg_num_update(
        hd->hd, NULL, hd->unread_num_chg, EMAIL_STOR_MSG_UNREAD_NUM);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_FS_CLOSE(hd->hd);
        goto STOR_EXIT_HANDLE;
    }
    
    result = email_stor_fs_msg_num_update(
        hd->hd, NULL, hd->total_num_chg, EMAIL_STOR_MSG_TOTAL_NUM);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_FS_CLOSE(hd->hd);
        goto STOR_EXIT_HANDLE;
    }
    
    result = srv_email_checksum_write_by_hd(hd->hd, 0, checksum);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_FS_CLOSE(hd->hd);
        goto STOR_EXIT_HANDLE;
    }
    
    EMAIL_FS_CLOSE(hd->hd);

    /* Notify MSG */
    offset_header = hd->offset_header;
    while (offset_header != NULL)
    {
        srv_email_om_notify_msg_struct notify_data;

        notify_data.msg_id = email_stor_fs_msg_id_gen(
            hd->acct_id, hd->fldr_id, offset_header->offset);
        if (hd->del_header)
        {
            srv_email_om_nofity_msg_from_stor(
                SRV_EMAIL_OM_NOTIFY_MSG_DEL, &notify_data);
            srv_email_om_nofity_fldr_from_stor(
                SRV_EMAIL_OM_NOTIFY_MSG_DEL, &notify_data);
        }
        else
        {
            notify_data.chg_mask = SRV_EMAIL_OM_NOTIFY_MSG_CHG_STATE;
            notify_data.state = offset_header->new_state;
            srv_email_om_nofity_msg_from_stor(
                SRV_EMAIL_OM_NOTIFY_MSG_UPDATE, &notify_data);
            srv_email_om_nofity_fldr_from_stor(
                SRV_EMAIL_OM_NOTIFY_MSG_UPDATE, &notify_data);
        }
        offset_header = offset_header->next;
    }

    /* Notify FLDR */
    if (hd->total_num_chg != 0 || hd->unread_num_chg != 0)
    {
        srv_email_om_notify_fldr_struct notify_data;

        notify_data.acct_id = hd->acct_id;
        notify_data.fldr_id = hd->fldr_id;
        notify_data.msg_unread_num = new_unread_num;
        notify_data.msg_total_num = new_total_num;
        srv_email_om_nofity_fldr_from_stor(
            SRV_EMAIL_OM_NOTIFY_FLDR_MSG_NUM_CHG, &notify_data);
    }
    /* Notify ACCT */
    if (email_stor_fs_fldr_type_is_inbox(hd->acct_id, hd->fldr_id)
        && (hd->total_num_chg != 0 || hd->unread_num_chg != 0))
    {
        srv_email_om_notify_acct_struct notify_data;

        notify_data.acct_id = hd->acct_id;
        notify_data.msg_unread_num = new_unread_num;
        notify_data.msg_total_num = new_total_num;
        srv_email_om_nofity_acct_from_stor(
            SRV_EMAIL_OM_NOTIFY_ACCT_MSG_NUM_CHG, &notify_data);
    }

    /************** for home screen recent list update ****************/
    if (email_stor_p->recent_list_query_callback != NULL
        && email_stor_p->recent_list_query_callback != NULL)
    {
        EMAIL_MSG_ID *ids;
        U32 i, num;
        MMI_BOOL chg = MMI_FALSE;

        email_stor_p->recent_list_query_callback(&ids, &num);
        EMAIL_STOR_TRACE_MSG_DEL(hd->acct_id, hd->fldr_id, num);
        for (i = 0; i < num; i++)
        {
            if (email_stor_fs_msg_id_to_acct_id(*(ids + i)) != hd->acct_id
                || email_stor_fs_msg_id_to_fldr_id(*(ids + i)) != hd->fldr_id)
            {
                continue;
            }
            offset_header = hd->offset_header;
            while (offset_header != NULL)
            {
                if (email_stor_fs_msg_id_to_offset(*(ids + i)) ==
                    offset_header->offset)
                {
                    *(ids + i) = EMAIL_MSG_INVALID_ID;
                    chg = MMI_TRUE;
                    EMAIL_STOR_TRACE_MSG_DEL(hd->acct_id, hd->fldr_id, i);
                }
                offset_header = offset_header->next;
            }
        }
        (email_stor_p->recent_list_answer_callback)(ids, chg);
    }
    /************** for home screen recent list update ****************/
    email_stor_fs_fldr_del_msg_link_free(hd->offset_header);
    EMAIL_STOR_TRACE_MSG_DEL(hd->acct_id, hd->fldr_id, 1);
    email_stor_mfree(hd);

    return SRV_EMAIL_RESULT_SUCC;
STOR_EXIT_HANDLE:
    email_stor_fs_fldr_del_msg_link_free(hd->offset_header);
    EMAIL_STOR_TRACE_MSG_DEL(hd->acct_id, hd->fldr_id, 1);
    email_stor_mfree(hd);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_list_msg_open
 * DESCRIPTION
 *  Prepare to get folder's MSG
 * PARAMETERS
 *  fldr_type           [IN]        Folder type
 *  acct_id             [IN]        Account id
 *  fldr_id             [IN]        Folder id
 *  text_type           [IN]        Text type
 *  text_buff_len       [IN]        
 *  date_type           [IN]        MSG date type
 *  base_index          [IN]        Start index
 *  handle              [OUT]       Handle
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_list_msg_open(
                        srv_email_fldr_type_enum fldr_type,
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        srv_eamil_msg_text_type_enum text_type,
                        srv_email_msg_date_type_enum date_type,
                        S32 base_index,
                        EMAIL_STOR_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    email_stor_fs_fldr_get_list_msg_struct *hd;
    S32 i;
    U32 rw;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAIL_STOR_TRACE_MSG_LIST(acct_id, fldr_id, 0);

    if ((hd = (EMAIL_STOR_HANDLE) email_stor_malloc(sizeof(*hd))) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(*hd));
        *handle = EMAIL_STOR_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    *handle = (EMAIL_STOR_HANDLE*) (hd);

    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        email_stor_mfree(hd);
        *handle = EMAIL_STOR_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_fldr_gen_path(acct_id, fldr_id, EMAIL_STOR_FLDR_INDEX, path);
    hd->hd = EMAIL_FS_OPEN(path, FS_READ_ONLY);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd->hd))
    {
        email_stor_path_mfree(path);
        EMAIL_STOR_TRACE_FS_OPEN(hd->hd);
        email_stor_mfree(hd);
        *handle = EMAIL_STOR_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    email_stor_path_mfree(path);

    hd->acct_id = acct_id;
    hd->fldr_id = fldr_id;
    hd->text_type = text_type;
    hd->date_type = date_type;
    hd->base_index = base_index;
    hd->current_offset = 0;

    /* get file size */
    EMAIL_FS_SEEK(hd->hd, 0, FS_FILE_END);
    FS_GetFilePosition(hd->hd, &hd->pos_end);

    if (base_index > 0)
    {
        EMAIL_FS_SEEK(hd->hd, EMAIL_STOR_MSG_RECORD_POS(0), FS_FILE_BEGIN);
        for (i = 0; i < base_index;)
        {
            S32 ret;

            ret = FS_Read(hd->hd, &hd->temp_msg, sizeof(hd->temp_msg), &rw);
            if (ret != FS_NO_ERROR)
            {
                EMAIL_STOR_TRACE_FS_READ(ret, rw);
                EMAIL_FS_CLOSE(hd->hd);
                email_stor_mfree(hd);
                *handle = EMAIL_STOR_INVALID_HANDLE;
                return SRV_EMAIL_RESULT_FS_ERROR;
            }
            if (rw != sizeof(email_stor_fs_msg_struct))
            {
                EMAIL_STOR_TRACE_MSG_LIST(acct_id, fldr_id, 0);
                return SRV_EMAIL_RESULT_SUCC;
            }
            if (hd->temp_msg.valid &&
                (hd->temp_msg.state & SRV_EMAIL_MSG_STATE_DEL_SERVER) !=
                    SRV_EMAIL_MSG_STATE_DEL_SERVER)
            {
                i++;
            }
            hd->current_offset++;
        }
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_list_msg_next
 * DESCRIPTION
 *  Get a MSG info
 * PARAMETERS
 *  handle      [IN]        Handle
 *  header      [OUT]       MSG header
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_list_msg_next(
                        EMAIL_STOR_HANDLE handle,
                        srv_email_stor_msg_list_header_struct *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_fldr_get_list_msg_struct *hd =
        (email_stor_fs_fldr_get_list_msg_struct*) handle;
    S32 ret;
    U32 rw = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hd->base_index == -1)
    {
        hd->current_offset = email_stor_fs_msg_id_to_offset(header->msg_id);
        
        if (email_stor_fs_msg_id_to_acct_id(header->msg_id) != hd->acct_id ||
            email_stor_fs_msg_id_to_fldr_id(header->msg_id) != hd->fldr_id)
        {
            EMAIL_STOR_TRACE_MSG_LIST(
                hd->acct_id, hd->fldr_id, hd->current_offset);
            return SRV_EMAIL_RESULT_INVALID_MSG;
        }
    }
    while (MMI_TRUE)
    {
        U32 seek_pos = EMAIL_STOR_MSG_RECORD_POS(hd->current_offset);
        if (hd->pos_end < seek_pos)
        {
            EMAIL_STOR_TRACE_MSG_LIST(
                hd->acct_id,hd->fldr_id, hd->current_offset);
            EMAIL_STOR_TRACE_MSG_LIST(
                hd->acct_id, hd->fldr_id, SRV_EMAIL_RESULT_INVALID_MSG);
            return SRV_EMAIL_RESULT_INVALID_MSG;
        }
        EMAIL_FS_SEEK(hd->hd, seek_pos, FS_FILE_BEGIN);
        ret = FS_Read(hd->hd, &hd->temp_msg, sizeof(hd->temp_msg), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(hd->temp_msg))
        {
            if (ret == FS_NO_ERROR && rw == 0)
            {
                EMAIL_STOR_TRACE_MSG_LIST(hd->acct_id,
                                          hd->fldr_id,
                                          SRV_EMAIL_RESULT_NO_MORE_RESULT);
                return SRV_EMAIL_RESULT_NO_MORE_RESULT;
            }
            EMAIL_STOR_TRACE_FS_READ(ret, rw);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }

        if (!hd->temp_msg.valid ||
            (hd->temp_msg.state & SRV_EMAIL_MSG_STATE_DEL_SERVER) ==
                SRV_EMAIL_MSG_STATE_DEL_SERVER)
        {
            if (hd->base_index == -1)
            {
                EMAIL_STOR_TRACE_MSG_LIST(
                    hd->acct_id, hd->fldr_id, hd->temp_msg.valid);
                EMAIL_STOR_TRACE_MSG_LIST(
                    hd->acct_id,
                    hd->fldr_id,
                    (hd->temp_msg.state & SRV_EMAIL_MSG_STATE_DEL_SERVER) ==
                        SRV_EMAIL_MSG_STATE_DEL_SERVER);
                EMAIL_STOR_TRACE_MSG_LIST(
                    hd->acct_id, hd->fldr_id, hd->current_offset);
                EMAIL_STOR_TRACE_MSG_LIST(
                    hd->acct_id, hd->fldr_id, SRV_EMAIL_RESULT_INVALID_MSG);
                return SRV_EMAIL_RESULT_INVALID_MSG;
            }
            hd->current_offset++;
            continue;
        }

        header->msg_id = email_stor_fs_msg_id_gen(
                            hd->acct_id, hd->fldr_id, hd->current_offset);
        hd->temp_msg.addr_disp_name[EMAIL_MAX_ENCODED_DISP_NAME_LEN] = 0;
        hd->temp_msg.addr_email[EMAIL_MAX_ENCODED_ADDR_LEN] = 0;
        strcpy(header->disp_name, hd->temp_msg.addr_disp_name);
        strcpy(header->email_addr, hd->temp_msg.addr_email);
        header->server_size = hd->temp_msg.server_size;
        header->local_size = hd->temp_msg.local_size;
        header->has_attach = hd->temp_msg.attch_num;
        if (hd->date_type == SRV_EMAIL_MSG_CREATED_DATE)
        {
            header->time = hd->temp_msg.created_date;
        }
        else
        {
            header->time = hd->temp_msg.received_date;
        }
        header->flag = hd->temp_msg.flag_latest;
        header->priority = hd->temp_msg.priority;
        header->state = hd->temp_msg.state;
        if (hd->text_type == SRV_EMAIL_MSG_TEXT_SUBJ)
        {
            hd->temp_msg.list_subj[EMAIL_MAX_LIST_SUBJ_LEN] = 0;
            mmi_wcscpy(header->list_subj, hd->temp_msg.list_subj);
        }
        hd->current_offset++;
        return SRV_EMAIL_RESULT_SUCC;
    }
    // here is unreachable
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_list_msg_close
 * DESCRIPTION
 *  Close
 * PARAMETERS
 *  handle      [IN]        Handle
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_list_msg_close(
    EMAIL_STOR_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_fldr_get_list_msg_struct* hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hd = ((email_stor_fs_fldr_get_list_msg_struct*) handle);
    EMAIL_FS_CLOSE(hd->hd);
    
    EMAIL_STOR_TRACE_MSG_LIST(hd->acct_id, hd->fldr_id, 1);
    
    email_stor_mfree(handle);

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_set_msg_flag_open
 * DESCRIPTION
 *  Prepare to set MSG flag
 * PARAMETERS
 *  fldr_type       [IN]        Folder type
 *  acct_id         [IN]        Account id
 *  fldr_id         [IN]        Folder id
 *  mask            [IN]        
 *  flag            [IN]        Type
 *  handle          [OUT]       Handle
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_set_msg_flag_open(
                        srv_email_fldr_type_enum fldr_type,
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        U8 mask,
                        EMAIL_MSG_FLAG flag,
                        EMAIL_STOR_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_fldr_set_msg_flag_struct *hd;
    WCHAR *path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAIL_STOR_TRACE_MSG_SET_FLAG(acct_id, fldr_id, 0);

    if ((*handle = (EMAIL_STOR_HANDLE) email_stor_malloc(sizeof(*hd))) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(*hd));
        *handle = EMAIL_STOR_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    hd = (email_stor_fs_fldr_set_msg_flag_struct*) (*handle);

    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        *handle = EMAIL_STOR_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    email_stor_fs_fldr_gen_path(acct_id, fldr_id, EMAIL_STOR_FLDR_INDEX, path);

    hd->hd = EMAIL_FS_OPEN(path, FS_READ_WRITE);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd->hd))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd->hd);
        email_stor_path_mfree(path);
        email_stor_mfree(hd);
        *handle = EMAIL_STOR_INVALID_HANDLE;
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    email_stor_path_mfree(path);

    /* get file size */
    EMAIL_FS_SEEK(hd->hd, 0, FS_FILE_END);
    FS_GetFilePosition(hd->hd, &hd->pos_end);

    hd->offset_header = NULL;
    hd->acct_id = acct_id;
    hd->fldr_id = fldr_id;
    hd->mask = mask;
    hd->flag = flag;
    hd->unread_num_chg = 0;
    hd->index_backup_file_updated = MMI_FALSE;

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_set_msg_flag_next
 * DESCRIPTION
 *  Set a MSG flag
 * PARAMETERS
 *  handle      [IN]        Handle
 *  offset      [IN]        Offset
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_set_msg_flag_next(
    EMAIL_STOR_HANDLE handle, EMAIL_STOR_OFFSET offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_fldr_set_msg_flag_struct *hd;
    EMAIL_MSG_FLAG flag;
    U32 rw = 0;
    MMI_BOOL valid = MMI_FALSE;
    S32 ret;
    U32 seek_pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hd = (email_stor_fs_fldr_set_msg_flag_struct*) handle;

    EMAIL_STOR_TRACE_MSG_SET_FLAG(hd->acct_id, hd->fldr_id, offset);

    seek_pos = EMAIL_STOR_MSG_RECORD_POS(offset);
    if (seek_pos > hd->pos_end)
    {
        return SRV_EMAIL_RESULT_INVALID_MSG;
    }
    EMAIL_FS_SEEK(hd->hd, seek_pos, FS_FILE_BEGIN);
    ret = FS_Read(hd->hd, &valid, sizeof(MMI_BOOL), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(MMI_BOOL))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        return SRV_EMAIL_RESULT_FS_ERROR;   /* this offset not exist */
    }

    if (!valid)
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        return SRV_EMAIL_RESULT_FAIL;
    }

    EMAIL_FS_SEEK(hd->hd, EMAIL_STOR_MSG_LATEST_FLAG_POS(offset),FS_FILE_BEGIN);
    ret = FS_Read(hd->hd, &flag, sizeof(EMAIL_MSG_FLAG), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_FLAG))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        
        return SRV_EMAIL_RESULT_FS_ERROR;   /* this offset not exist */
    }

    if ((hd->mask & flag) == (hd->mask & hd->flag))
    {
        return SRV_EMAIL_RESULT_SUCC;
    }

    hd->index_backup_file_updated = MMI_TRUE;

    hd->unread_num_chg += email_stor_fs_flag_mem_set(&flag, hd->mask, hd->flag);

    EMAIL_FS_SEEK(hd->hd, EMAIL_STOR_MSG_LATEST_FLAG_POS(offset),FS_FILE_BEGIN);
    ret = FS_Write(hd->hd, &flag, sizeof(EMAIL_MSG_FLAG), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_FLAG))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    email_stor_fs_msg_flag_link_add(&hd->offset_header, offset, flag);

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_set_msg_flag_close
 * DESCRIPTION
 *  Close
 * PARAMETERS
 *  handle      [IN]        Handle
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_set_msg_flag_close(
    EMAIL_STOR_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 new_unread_num;
    U32 new_total_num;
    srv_email_result_enum result;
    email_stor_fs_fldr_set_msg_flag_struct *hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hd = (email_stor_fs_fldr_set_msg_flag_struct*) handle;
    if (hd->index_backup_file_updated)
    {
        email_stor_fs_msg_flag_link_struct *offset_header = hd->offset_header;
        WCHAR *path;
        EMAIL_CHECKSUM checksum;
        U32 rw;
        S32 ret;

        result = email_stor_fs_msg_num_update(hd->hd,
                                              &new_unread_num,
                                              hd->unread_num_chg,
                                              EMAIL_STOR_MSG_UNREAD_NUM);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            EMAIL_FS_CLOSE(hd->hd);
            goto STOR_EXIT_HANDLE;
        }

        result = email_stor_fs_msg_num_update(hd->hd,
                                              &new_total_num,
                                              0,
                                              EMAIL_STOR_MSG_TOTAL_NUM);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            EMAIL_FS_CLOSE(hd->hd);
            goto STOR_EXIT_HANDLE;
        }

        new_unread_num += hd->unread_num_chg;

        email_stor_p->inbox_index_size = new_total_num;
        email_stor_fs_inbox_index_read(hd->hd);
        email_stor_fs_inbox_index_update_by_list(hd->offset_header);
        email_stor_fs_inbox_index_write(hd->hd);

        /* calculate INDEX file checksum and update it */
        checksum = srv_email_checksum_compute_by_hd(hd->hd,
                                                    sizeof(EMAIL_CHECKSUM));
        srv_email_checksum_write_by_hd(hd->hd, 0, checksum);
        EMAIL_FS_CLOSE(hd->hd);

        /* update BACKUP file */
        path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN);
        if (path == NULL)
        {
            EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
            result = SRV_EMAIL_RESULT_NO_MEMORY;
            goto STOR_EXIT_HANDLE;
        }
        email_stor_fs_fldr_gen_path(
            hd->acct_id, hd->fldr_id, EMAIL_STOR_FLDR_BACKUP, path);

        hd->hd = EMAIL_FS_OPEN(path, FS_READ_WRITE);
        if (EMAIL_STOR_FS_HANDLE_INVALID(hd->hd))
        {
            EMAIL_STOR_TRACE_FS_OPEN(hd->hd);
            email_stor_path_mfree(path);
            result = SRV_EMAIL_RESULT_FS_ERROR;
            goto STOR_EXIT_HANDLE;
        }
        email_stor_path_mfree(path);

        /* update BACKUP checksum */
        ret = FS_Write(hd->hd, &checksum, sizeof(EMAIL_CHECKSUM), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_CHECKSUM))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            EMAIL_FS_CLOSE(hd->hd);
            result = SRV_EMAIL_RESULT_FS_ERROR;
            goto STOR_EXIT_HANDLE;
        }

        /* update BACKUP flag */
        while (offset_header != NULL)
        {
            EMAIL_FS_SEEK(hd->hd,
                          EMAIL_STOR_MSG_LATEST_FLAG_POS(offset_header->offset),
                          FS_FILE_BEGIN);
            ret = FS_Write(hd->hd,
                           &(offset_header->new_flag),
                           sizeof(EMAIL_MSG_FLAG), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_FLAG))
            {
                EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
                EMAIL_FS_CLOSE(hd->hd);
                result = SRV_EMAIL_RESULT_FS_ERROR;
                goto STOR_EXIT_HANDLE;
            }
            offset_header = offset_header->next;
        }

        EMAIL_FS_SEEK(hd->hd,
                      sizeof(EMAIL_CHECKSUM) + sizeof(U32),
                      FS_FILE_BEGIN);
        ret = FS_Write(hd->hd, &new_unread_num, sizeof(U32), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(U32))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            EMAIL_FS_CLOSE(hd->hd);
            goto STOR_EXIT_HANDLE;
        }

        //if (hd->is_inbox)
        {
            email_stor_fs_inbox_index_write(hd->hd);
        }

    }

    EMAIL_FS_CLOSE(hd->hd);

    if (hd->index_backup_file_updated &&
        email_stor_fs_fldr_type_is_inbox(hd->acct_id, hd->fldr_id))
    {
        email_stor_fs_acct_cache_update_msg_unread_chg(
            hd->acct_id, hd->unread_num_chg);
    }

    if (hd->index_backup_file_updated)
    {
        email_stor_fs_msg_flag_link_struct *offset_header = hd->offset_header;

        /* Notify MSG */
        if (offset_header != NULL)
        {
            srv_email_om_notify_msg_struct notify_data;

            memset(&notify_data, 0, sizeof(srv_email_om_notify_msg_struct));
            notify_data.chg_mask = SRV_EMAIL_OM_NOTIFY_MSG_CHG_FLAG;
            do
            {
                notify_data.msg_id = email_stor_fs_msg_id_gen(
                    hd->acct_id, hd->fldr_id, offset_header->offset);
                notify_data.flag = offset_header->new_flag;
                srv_email_om_nofity_msg_from_stor(
                    SRV_EMAIL_OM_NOTIFY_MSG_UPDATE, &notify_data);
                srv_email_om_nofity_fldr_from_stor(
                    SRV_EMAIL_OM_NOTIFY_MSG_UPDATE, &notify_data);
                offset_header = offset_header->next;
            } while (offset_header != NULL);
        }

        /* Notify FLDR */
        if (hd->unread_num_chg != 0)
        {
            srv_email_om_notify_fldr_struct notify_data;

            notify_data.acct_id = hd->acct_id;
            notify_data.fldr_id = hd->fldr_id;
            notify_data.msg_unread_num = new_unread_num;
            notify_data.msg_total_num = new_total_num;
            srv_email_om_nofity_fldr_from_stor(
                SRV_EMAIL_OM_NOTIFY_FLDR_MSG_NUM_CHG, &notify_data);
        }

        /* Notify ACCT */
        if (email_stor_fs_fldr_type_is_inbox(hd->acct_id, hd->fldr_id) &&
            hd->unread_num_chg != 0)
        {
            srv_email_om_notify_acct_struct notify_data;

            notify_data.acct_id = hd->acct_id;
            notify_data.msg_unread_num = new_unread_num;
            notify_data.msg_total_num = new_total_num;
            srv_email_om_nofity_acct_from_stor(
                SRV_EMAIL_OM_NOTIFY_ACCT_MSG_NUM_CHG, &notify_data);
        }
    }

    email_stor_fs_msg_flag_link_free(hd->offset_header);
    EMAIL_STOR_TRACE_MSG_SET_FLAG(hd->acct_id, hd->fldr_id, 1);
    email_stor_mfree(hd);
    return SRV_EMAIL_RESULT_SUCC;
    
STOR_EXIT_HANDLE:
    email_stor_fs_msg_flag_link_free(hd->offset_header);
    email_stor_mfree(hd);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_del_remove_record_for_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd              [IN]        
 *  header          [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_del_remove_record_for_sync(
                        FS_HANDLE hd,
                        email_stor_fs_msg_sync_link_struct *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 rw;
    MMI_BOOL valid = MMI_FALSE;
    U32 pos_end = 0;
    U32 pos_new;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (header != NULL)
    {
        if ((ret = FS_GetFileSize(hd, &pos_end)) < FS_NO_ERROR)
        {
            EMAIL_STOR_TRACE_FS_OPEN(ret);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        pos_new = EMAIL_STOR_MSG_RECORD_POS(header->offset);
        if (pos_new < pos_end)
        {
            EMAIL_FS_SEEK(hd, pos_new, FS_FILE_BEGIN);
            ret = FS_Write(hd, &valid, sizeof(MMI_BOOL), &rw);
            if (ret != FS_NO_ERROR || rw != sizeof(MMI_BOOL))
            {
                EMAIL_STOR_TRACE_FS_WRITE(ret, rw);                
                return SRV_EMAIL_RESULT_FS_ERROR;
            }
        }
        header = header->next;
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_sync_msg_open
 * DESCRIPTION
 *  Open to get a handle
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  fldr_id     [IN]        Folder id
 *  handle      [OUT]       Handle
 *  last_msg_id [IN]        Last MSG ID
 *                          if not used, fill it with EMAIL_MSG_INVALID_ID
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_sync_msg_open(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        EMAIL_STOR_HANDLE *handle,
                        EMAIL_MSG_ID last_msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    email_stor_fs_fldr_sync_struct *hd;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = EMAIL_STOR_INVALID_HANDLE;
    if ((*handle = (EMAIL_STOR_HANDLE) email_stor_malloc(sizeof(*hd))) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(*hd));
        result = SRV_EMAIL_RESULT_NO_MEMORY;
        goto EXIT;
    }

    hd = (email_stor_fs_fldr_sync_struct*) (*handle);

    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        email_stor_mfree(hd);
        result = SRV_EMAIL_RESULT_NO_MEMORY;
        goto EXIT;
    }

    email_stor_fs_fldr_gen_path(acct_id, fldr_id, EMAIL_STOR_FLDR_INDEX, path);

    hd->hd = EMAIL_FS_OPEN(path, FS_READ_WRITE);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd->hd))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd->hd);
        email_stor_path_mfree(path);
        email_stor_mfree(hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto EXIT;
    }
    email_stor_path_mfree(path);

    /* get file size */
    EMAIL_FS_SEEK(hd->hd, 0, FS_FILE_END);
    FS_GetFilePosition(hd->hd, &hd->pos_end);

    hd->acct_id = acct_id;
    hd->fldr_id = fldr_id;
    hd->current_offset = (last_msg_id == EMAIL_MSG_INVALID_ID ? 0 : 
        email_stor_fs_msg_id_to_offset(last_msg_id) + 1);
    hd->msg_total_num_chg = 0;
    hd->msg_unread_num_chg = 0;
    hd->del_offset_list_header = NULL;
    hd->set_flag_list_header = NULL;

EXIT:
    EMAIL_STOR_TRACE_FLDR_SYNC(acct_id, fldr_id, 0, 0);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_sync_msg_get_next
 * DESCRIPTION
 *  Get next MSG info
 * PARAMETERS
 *  handle          [IN]        Handle
 *  msg_info        [OUT]       MSG info
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_sync_msg_get_next(
                        EMAIL_STOR_HANDLE handle,
                        srv_email_stor_fldr_get_msg_id_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_fldr_sync_struct *hd;
    email_stor_fs_msg_struct *temp_msg;
    U32 rw = 0;
    S32 ret;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT (msg_info != NULL);

    hd = (email_stor_fs_fldr_sync_struct*) handle;

    if ((temp_msg = email_stor_malloc(sizeof(*temp_msg))) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(*temp_msg));
        result = SRV_EMAIL_RESULT_NO_MEMORY;
        goto EXIT;
    }

    while (MMI_TRUE)
    {
        U32 seek_pos = EMAIL_STOR_MSG_RECORD_POS(hd->current_offset);
        if (seek_pos >= hd->pos_end)
        {
            email_stor_mfree(temp_msg);
            result = SRV_EMAIL_RESULT_NO_MORE_RESULT;
            goto EXIT;
        }
        EMAIL_FS_SEEK(hd->hd, seek_pos, FS_FILE_BEGIN);
        ret = FS_Read(hd->hd, temp_msg, sizeof(email_stor_fs_msg_struct), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(email_stor_fs_msg_struct))
        {
            email_stor_mfree(temp_msg);
            if (ret == FS_NO_ERROR)// || rw == 0)
            {
                result = SRV_EMAIL_RESULT_NO_MORE_RESULT;
                goto EXIT;
            }
            EMAIL_STOR_TRACE_FS_READ(ret, rw);
            result = SRV_EMAIL_RESULT_FS_ERROR;
            goto EXIT;
        }

        if (temp_msg->valid)
        {
            msg_info->msg_id = email_stor_fs_msg_id_gen(
                hd->acct_id, hd->fldr_id, hd->current_offset);
            msg_info->flag_latest = temp_msg->flag_latest;
            msg_info->flag_orig = temp_msg->flag_orig;
            msg_info->uid_validity = temp_msg->uid_validity;
            msg_info->uid = temp_msg->uid;
            memcpy(msg_info->uidl, temp_msg->uidl, SRV_EMAIL_MD5_DIGEST_LEN);
            memcpy(msg_info->acct_digest,
                   temp_msg->acct_digest,
                   SRV_EMAIL_MD5_DIGEST_LEN);
            msg_info->state = temp_msg->state;
            msg_info->created_date = temp_msg->created_date;
            msg_info->received_date = temp_msg->received_date;
            hd->current_offset++;
            break;
        }
        hd->current_offset++;
    }
    email_stor_mfree(temp_msg);

EXIT:
    EMAIL_STOR_TRACE_FLDR_SYNC(hd->acct_id, hd->fldr_id, hd->current_offset - 1, 2);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_sync_msg_del
 * DESCRIPTION
 *  Delete a MSG
 * PARAMETERS
 *  handle      [IN]        Handle
 *  msg_id      [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_sync_msg_del(
    EMAIL_STOR_HANDLE handle, EMAIL_MSG_ID msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 rw;
    MMI_BOOL valid = MMI_FALSE;
    EMAIL_MSG_FLAG orig_flag;
    EMAIL_MSG_STATE state;
    email_stor_attch_id_link_struct *attch_id_header = NULL;
    email_stor_fs_fldr_sync_struct *hd;
    EMAIL_ACCT_ID acct_id = email_stor_fs_msg_id_to_acct_id(msg_id);
    EMAIL_FLDR_ID fldr_id = email_stor_fs_msg_id_to_fldr_id(msg_id);
    EMAIL_STOR_OFFSET offset = email_stor_fs_msg_id_to_offset(msg_id);
    U32 seek_pos;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hd = (email_stor_fs_fldr_sync_struct*) handle;
    if (hd->acct_id != acct_id || hd->fldr_id != fldr_id)
    {
        result = SRV_EMAIL_RESULT_FAIL;
        goto EXIT;
    }
    
    seek_pos = EMAIL_STOR_MSG_RECORD_POS(offset);
    if (seek_pos >= hd->pos_end)
    {
        result = SRV_EMAIL_RESULT_INVALID_MSG;
        goto EXIT;
    }

    /* check whether this OFFSET is valid */
    EMAIL_FS_SEEK(hd->hd, seek_pos, FS_FILE_BEGIN);
    ret = FS_Read(hd->hd, &valid, sizeof(MMI_BOOL), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(MMI_BOOL))
    {
        /* this offset not exist */
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto EXIT;
    }

    if (!valid)
    {
        result = SRV_EMAIL_RESULT_INVALID_MSG;
        goto EXIT;
    }

    /* mark this OFFSET invalid */
    valid = MMI_FALSE;
    EMAIL_FS_SEEK(hd->hd, EMAIL_STOR_MSG_RECORD_POS(offset), FS_FILE_BEGIN);
    ret = FS_Write(hd->hd, &valid, sizeof(MMI_BOOL), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(MMI_BOOL))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto EXIT;
    }

    /* read old State */
    EMAIL_FS_SEEK(hd->hd, EMAIL_STOR_MSG_STATE_POS(offset), FS_FILE_BEGIN);
    ret = FS_Read(hd->hd, &state, sizeof(EMAIL_MSG_STATE), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_STATE))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto EXIT;
    }
    if ((state & SRV_EMAIL_MSG_STATE_DEL_SERVER) ==
        SRV_EMAIL_MSG_STATE_DEL_SERVER)
    {
        email_stor_fs_msg_sync_link_add(
            &hd->del_offset_list_header, offset, MMI_TRUE);
    }
    else
    {
        /* delete attch */
        email_stor_fs_msg_get_attch_id(
            acct_id, fldr_id, offset, &attch_id_header);
        email_stor_fs_attch_del(attch_id_header);
        email_stor_fs_attch_id_link_free(attch_id_header);

        /* delete parts */
        email_stor_fs_msg_parts_del(
            acct_id, fldr_id, offset, SRV_EMAIL_STOR_FILE_CONT_TEXT);
        email_stor_fs_msg_parts_del(
            acct_id, fldr_id, offset, SRV_EMAIL_STOR_FILE_CONT_HTML);
        email_stor_fs_msg_parts_del(
            acct_id, fldr_id, offset, SRV_EMAIL_STOR_FILE_SAA);

        /* read old flag */
        EMAIL_FS_SEEK(hd->hd,
                      EMAIL_STOR_MSG_LATEST_FLAG_POS(offset),
                      FS_FILE_BEGIN);
        ret = FS_Read(hd->hd, &orig_flag, sizeof(EMAIL_MSG_FLAG), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_FLAG))
        {
            EMAIL_STOR_TRACE_FS_READ(ret, rw);
            result = SRV_EMAIL_RESULT_FS_ERROR;
            goto EXIT;
        }

        /* compute changed Unread/Total number */
        if (!((orig_flag & EMAIL_MSG_FLAG_SEEN) == EMAIL_MSG_FLAG_SEEN))
        {
            /* unread */
            hd->msg_unread_num_chg--;
        }
        hd->msg_total_num_chg--;
        email_stor_fs_msg_sync_link_add(
            &hd->del_offset_list_header, offset, MMI_FALSE);
    }

EXIT:
    EMAIL_STOR_TRACE_FLDR_SYNC(acct_id, fldr_id, offset, 3);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_sync_msg_set_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  msg_id          [IN]        
 *  new_flag        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_sync_msg_set_flag(
                        EMAIL_STOR_HANDLE handle,
                        EMAIL_MSG_ID msg_id,
                        EMAIL_MSG_FLAG new_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 rw;
    MMI_BOOL valid = MMI_FALSE;
    EMAIL_MSG_FLAG orig_flag;
    email_stor_fs_fldr_sync_struct *hd;
    EMAIL_ACCT_ID acct_id = email_stor_fs_msg_id_to_acct_id(msg_id);
    EMAIL_FLDR_ID fldr_id = email_stor_fs_msg_id_to_fldr_id(msg_id);
    EMAIL_STOR_OFFSET offset = email_stor_fs_msg_id_to_offset(msg_id);
    U32 seek_pos;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hd = (email_stor_fs_fldr_sync_struct*) handle;
    if (hd->acct_id != acct_id || hd->fldr_id != fldr_id)
    {
        MMI_ASSERT(0);
        result = SRV_EMAIL_RESULT_FAIL;
        goto EXIT;
    }
    
    seek_pos = EMAIL_STOR_MSG_RECORD_POS(offset);
    if (seek_pos >= hd->pos_end)
    {
        result = SRV_EMAIL_RESULT_INVALID_MSG;
        goto EXIT;
    }

    EMAIL_FS_SEEK(hd->hd, seek_pos, FS_FILE_BEGIN);
    ret = FS_Read(hd->hd, &valid, sizeof(MMI_BOOL), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(MMI_BOOL))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        result = SRV_EMAIL_RESULT_FAIL;   /* this offset not exist */
        goto EXIT;
    }

    if (!valid) /* this offset is not valid */
    {
        result = SRV_EMAIL_RESULT_FAIL;
        goto EXIT;
    }

    EMAIL_FS_SEEK(hd->hd,
                  EMAIL_STOR_MSG_LATEST_FLAG_POS(offset),
                  FS_FILE_BEGIN);
    ret = FS_Read(hd->hd, &orig_flag, sizeof(EMAIL_MSG_FLAG), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_FLAG))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, rw);
        result = SRV_EMAIL_RESULT_FAIL;   /* this offset not exist */
        goto EXIT;
    }

    /* update flag_latest */
    EMAIL_FS_SEEK(hd->hd, 0 - (S32)sizeof(EMAIL_MSG_FLAG), FS_FILE_CURRENT);
    ret = FS_Write(hd->hd, &new_flag, sizeof(EMAIL_MSG_FLAG), &rw);
    if (ret != FS_NO_ERROR || sizeof(EMAIL_MSG_FLAG) != rw)
    {
        /* this offset not exist */
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        result = SRV_EMAIL_RESULT_FAIL;
        goto EXIT;
    }

    /* update flag_orig */
    ret = FS_Write(hd->hd, &new_flag, sizeof(EMAIL_MSG_FLAG), &rw);
    if (ret != FS_NO_ERROR || sizeof(EMAIL_MSG_FLAG) != rw)
    {
        /* this offset not exist */
        EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
        result = SRV_EMAIL_RESULT_FAIL;
        goto EXIT;
    }

    hd->msg_unread_num_chg += email_stor_fs_flag_mem_set(&orig_flag,
                                                         (U8)0xff,
                                                         new_flag);

    email_stor_fs_msg_flag_link_add(
        &hd->set_flag_list_header, offset, new_flag);

EXIT:
    EMAIL_STOR_TRACE_FLDR_SYNC(acct_id, fldr_id, offset, 4);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_sync_msg_close
 * DESCRIPTION
 *  Close
 * PARAMETERS
 *  handle      [IN]        Handle
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_sync_msg_close(
    EMAIL_STOR_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_fldr_sync_struct *hd;
    email_stor_fs_msg_flag_link_struct *set_flag_list_header;
    srv_email_result_enum result;
    EMAIL_CHECKSUM checksum;
    WCHAR *path;
    S32 ret;
    U32 rw;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hd = (email_stor_fs_fldr_sync_struct*) *handle;
    *handle = EMAIL_STOR_INVALID_HANDLE;

    EMAIL_STOR_TRACE_MSG_NUM_UPDATE(hd->acct_id,
                                    hd->fldr_id,
                                    EMAIL_STOR_MSG_UNREAD_NUM,
                                    hd->msg_unread_num_chg);
    result = email_stor_fs_msg_num_update(hd->hd,
                                          &hd->new_unread_num,
                                          hd->msg_unread_num_chg,
                                          EMAIL_STOR_MSG_UNREAD_NUM);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_FS_CLOSE(hd->hd);
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_STOR_TRACE_MSG_NUM_UPDATE(hd->acct_id,
                                    hd->fldr_id,
                                    EMAIL_STOR_MSG_TOTAL_NUM,
                                    hd->msg_total_num_chg);
    result = email_stor_fs_msg_num_update(hd->hd,
                                          &hd->new_total_num,
                                          hd->msg_total_num_chg,
                                          EMAIL_STOR_MSG_TOTAL_NUM);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_FS_CLOSE(hd->hd);
        goto STOR_EXIT_HANDLE;
    }

    hd->new_unread_num += hd->msg_unread_num_chg;
    hd->new_total_num += hd->msg_total_num_chg;

    MMI_ASSERT(hd->new_total_num >= hd->new_unread_num);
    //if (hd->is_inbox)
    {
        email_stor_fs_msg_sync_link_struct *sync_del_header =
            hd->del_offset_list_header;

        email_stor_p->inbox_index_size =
            hd->new_total_num - hd->msg_total_num_chg;
        email_stor_fs_inbox_index_read(hd->hd);
        while (sync_del_header != NULL)
        {
            if (!sync_del_header->del_server_flag)
            {
                email_stor_fs_inbox_index_del((U16) sync_del_header->offset);
            }
            sync_del_header = sync_del_header->next;
        }
        email_stor_fs_inbox_index_update_by_list(hd->set_flag_list_header);
        result = email_stor_fs_inbox_index_write(hd->hd);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            EMAIL_FS_CLOSE(hd->hd);
            goto STOR_EXIT_HANDLE;
        }

        if (email_stor_fs_fldr_type_is_inbox(hd->acct_id, hd->fldr_id))
        {
            email_stor_fs_acct_cache_update_msg_unread_chg(
                hd->acct_id, hd->msg_unread_num_chg);
        }
    }
    
    checksum = srv_email_checksum_compute_by_hd(hd->hd, sizeof(EMAIL_CHECKSUM));
    result = srv_email_checksum_write_by_hd(hd->hd, 0, checksum);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_FS_CLOSE(hd->hd);
        goto STOR_EXIT_HANDLE;
    }
    
    EMAIL_FS_CLOSE(hd->hd);
    

    /* start to update BACKUP file */
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        result = SRV_EMAIL_RESULT_NO_MEMORY;
        goto STOR_EXIT_HANDLE;
    }
    email_stor_fs_fldr_gen_path(
        hd->acct_id, hd->fldr_id, EMAIL_STOR_FLDR_BACKUP, path);

    hd->hd = EMAIL_FS_OPEN(path, FS_READ_WRITE);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd->hd))
    {
        email_stor_path_mfree(path);
        EMAIL_STOR_TRACE_FS_OPEN(hd->hd);
        result = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }
    email_stor_path_mfree(path);

    EMAIL_STOR_TRACE_MSG_NUM_UPDATE(hd->acct_id,
                                    hd->fldr_id,
                                    EMAIL_STOR_MSG_UNREAD_NUM,
                                    hd->msg_unread_num_chg);
    result = email_stor_fs_msg_num_update(
        hd->hd, NULL, hd->msg_unread_num_chg, EMAIL_STOR_MSG_UNREAD_NUM);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_FS_CLOSE(hd->hd);
        goto STOR_EXIT_HANDLE;
    }
    
    EMAIL_STOR_TRACE_MSG_NUM_UPDATE(hd->acct_id,
                                    hd->fldr_id,
                                    EMAIL_STOR_MSG_TOTAL_NUM,
                                    hd->msg_total_num_chg);
    result = email_stor_fs_msg_num_update(
        hd->hd, NULL, hd->msg_total_num_chg, EMAIL_STOR_MSG_TOTAL_NUM);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_FS_CLOSE(hd->hd);
        goto STOR_EXIT_HANDLE;
    }

    /* can not free here, used later */
    result = email_stor_fs_msg_del_remove_record_for_sync(
        hd->hd, hd->del_offset_list_header);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_FS_CLOSE(hd->hd);
        goto STOR_EXIT_HANDLE;
    }

    set_flag_list_header = hd->set_flag_list_header;
    while (set_flag_list_header != NULL)
    {
        /* update flag_latest */
        EMAIL_FS_SEEK(
            hd->hd,
            EMAIL_STOR_MSG_LATEST_FLAG_POS(set_flag_list_header->offset),
            FS_FILE_BEGIN);
        ret = FS_Write(hd->hd,
            &set_flag_list_header->new_flag,
            sizeof(EMAIL_MSG_FLAG),
            &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_FLAG))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            EMAIL_FS_CLOSE(hd->hd);
            result = SRV_EMAIL_RESULT_FS_ERROR;
            goto STOR_EXIT_HANDLE;
        }

        /* update flag_orig */
        ret = FS_Write(hd->hd,
                       &set_flag_list_header->new_flag,
                       sizeof(EMAIL_MSG_FLAG), &rw);
        if (ret != FS_NO_ERROR || rw != sizeof(EMAIL_MSG_FLAG))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, rw);
            EMAIL_FS_CLOSE(hd->hd);
            result = SRV_EMAIL_RESULT_FS_ERROR;
            goto STOR_EXIT_HANDLE;
        }

        set_flag_list_header = set_flag_list_header->next;
    }

    //if (hd->is_inbox)
    {
        result = email_stor_fs_inbox_index_write(hd->hd);
        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            EMAIL_FS_CLOSE(hd->hd);
            goto STOR_EXIT_HANDLE;
        }
    }
    result = srv_email_checksum_write_by_hd(hd->hd, 0, checksum);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_FS_CLOSE(hd->hd);
        goto STOR_EXIT_HANDLE;
    }
    EMAIL_FS_CLOSE(hd->hd);

    /* Notify MSG */
    {
        srv_email_om_notify_msg_struct notify_data;
        email_stor_fs_msg_sync_link_struct *del_offset_list_header;

        memset(&notify_data, 0, sizeof(srv_email_om_notify_msg_struct));
        notify_data.chg_mask = SRV_EMAIL_OM_NOTIFY_MSG_CHG_FLAG;
        set_flag_list_header = hd->set_flag_list_header;
        while (set_flag_list_header != NULL)
        {
            notify_data.msg_id = email_stor_fs_msg_id_gen(
                hd->acct_id, hd->fldr_id, set_flag_list_header->offset);
            notify_data.flag = set_flag_list_header->new_flag;

            srv_email_om_nofity_msg_from_stor(
                SRV_EMAIL_OM_NOTIFY_MSG_UPDATE, &notify_data);
            srv_email_om_nofity_fldr_from_stor(
                SRV_EMAIL_OM_NOTIFY_MSG_UPDATE, &notify_data);
            set_flag_list_header = set_flag_list_header->next;
        }

        del_offset_list_header = hd->del_offset_list_header;
        while (del_offset_list_header != NULL)
        {
            notify_data.msg_id = email_stor_fs_msg_id_gen(
                hd->acct_id, hd->fldr_id, del_offset_list_header->offset);
            srv_email_om_nofity_msg_from_stor(
                SRV_EMAIL_OM_NOTIFY_MSG_DEL, &notify_data);
            srv_email_om_nofity_fldr_from_stor(
                SRV_EMAIL_OM_NOTIFY_MSG_DEL, &notify_data);
            del_offset_list_header = del_offset_list_header->next;
        }
    }

    /* Notify FLDR */
    if (hd->msg_total_num_chg != 0 || hd->msg_unread_num_chg != 0)
    {
        srv_email_om_notify_fldr_struct notify_data;

        notify_data.acct_id = hd->acct_id;
        notify_data.fldr_id = hd->fldr_id;
        notify_data.msg_total_num = hd->new_total_num;
        notify_data.msg_unread_num = hd->new_unread_num;
        srv_email_om_nofity_fldr_from_stor(
            SRV_EMAIL_OM_NOTIFY_FLDR_MSG_NUM_CHG, &notify_data);
    }

    /* Notify ACCT */
    if (email_stor_fs_fldr_type_is_inbox(hd->acct_id, hd->fldr_id) 
        && (hd->msg_total_num_chg != 0 || hd->msg_unread_num_chg != 0))
    {
        srv_email_om_notify_acct_struct notify_data;

        notify_data.acct_id = hd->acct_id;
        notify_data.msg_total_num = hd->new_total_num;
        notify_data.msg_unread_num = hd->new_unread_num;
        srv_email_om_nofity_acct_from_stor(
            SRV_EMAIL_OM_NOTIFY_ACCT_MSG_NUM_CHG, &notify_data);
    }

    /************** for home screen recent list update ****************/
    if (email_stor_p->recent_list_query_callback != NULL
        && email_stor_p->recent_list_query_callback != NULL)
    {
        EMAIL_MSG_ID *ids;
        U32 i, num;
        MMI_BOOL chg = MMI_FALSE;
        email_stor_fs_msg_sync_link_struct *del_offset_list_header;

        (email_stor_p->recent_list_query_callback)(&ids, &num);
        EMAIL_STOR_TRACE_FLDR_SYNC(hd->acct_id, hd->fldr_id, num, 1);
        for (i = 0; i < num; i++)
        {
            if (email_stor_fs_msg_id_to_acct_id(*(ids + i)) != hd->acct_id
                || email_stor_fs_msg_id_to_fldr_id(*(ids + i)) != hd->fldr_id)
            {
                continue;
            }
            del_offset_list_header = hd->del_offset_list_header;
            while (del_offset_list_header != NULL)
            {
                if (email_stor_fs_msg_id_to_offset(*(ids + i)) ==
                    del_offset_list_header->offset)
                {
                    *(ids + i) = EMAIL_MSG_INVALID_ID;
                    chg = MMI_TRUE;
                    EMAIL_STOR_TRACE_FLDR_SYNC(hd->acct_id, hd->fldr_id, i, 1);
                }
                del_offset_list_header = del_offset_list_header->next;
            }
        }
        (email_stor_p->recent_list_answer_callback)(ids, chg);
    }
    /************** for home screen recent list update ****************/

STOR_EXIT_HANDLE:
    email_stor_fs_msg_sync_link_free(hd->del_offset_list_header);
    email_stor_fs_msg_flag_link_free(hd->set_flag_list_header);
    EMAIL_STOR_TRACE_FLDR_SYNC(hd->acct_id, hd->fldr_id, 0, 1);
    email_stor_mfree(hd);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_get_info
 * DESCRIPTION
 *  Get a folder's information
 * PARAMETERS
 *  acct_id         [IN]        Account id
 *  fldr_id         [IN]        Folder id
 *  fldr_info       [OUT]       Folder info
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_get_info(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        srv_email_stor_fldr_struct *fldr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    FS_HANDLE hd;
    U32 rw;
    S32 ret;

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
        email_stor_path_mfree(path);
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    email_stor_path_mfree(path);

    EMAIL_FS_SEEK(hd, sizeof(EMAIL_CHECKSUM), FS_FILE_BEGIN);
    ret = FS_Read(hd, fldr_info, sizeof(srv_email_stor_fldr_struct), &rw);
    if (ret != FS_NO_ERROR || rw != sizeof(srv_email_stor_fldr_struct))
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
 *  email_stor_fs_fldr_id_to_fldr_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id     [IN]        
 *  fldr_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_email_fldr_type_enum email_stor_fs_fldr_id_to_fldr_type(
    EMAIL_ACCT_ID acct_id, EMAIL_FLDR_ID fldr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 fldr_start;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(EMAIL_STOR_ACCT_ID_IS_VALID(acct_id));
    if (fldr_id < EMAIL_STOR_FLDR_VALID_ID_MIN ||
        fldr_id > EMAIL_STOR_FLDR_VALID_ID_MAX)
    {
        return SRV_EMAIL_FLDR_TYPE_INVALID;
    }
    if (fldr_id >= EMAIL_STOR_FLDR_REMOTE_ID_MIN)
    {
        return SRV_EMAIL_FLDR_TYPE_REMOTE;
    }

    fldr_start = EMAIL_STOR_FLDR_VALID_ID_MIN +
        EMAIL_STOR_BASIC_FLDR_NUM * (acct_id - EMAIL_STOR_ACCT_VALID_ID_MIN);
    return (srv_email_fldr_type_enum) (fldr_id - fldr_start);
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_type_is_inbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id     [IN]        
 *  fldr_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL email_stor_fs_fldr_type_is_inbox(EMAIL_ACCT_ID acct_id,
                                          EMAIL_FLDR_ID fldr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_FLDR_ID inbox;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inbox = email_stor_fs_fldr_gen_basic_id(acct_id, SRV_EMAIL_FLDR_TYPE_INBOX);

    return (inbox == fldr_id ? MMI_TRUE : MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_type_is_basic
 * DESCRIPTION
 *  Check whether the folder is basic folder
 * PARAMETERS
 *  fldr_type       [IN]        Folder type
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL email_stor_fs_fldr_type_is_basic(srv_email_fldr_type_enum fldr_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fldr_type >= SRV_EMAIL_FLDR_TYPE_INBOX &&
        fldr_type < SRV_EMAIL_FLDR_TYPE_BASICS)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_parts_root_gen_path
 * DESCRIPTION
 *  Generate a folder file's path
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  fldr_id     [IN]        Folder id
 *  path        [OUT]       Folder file path
 *  type(?)     [IN]        Folder file type
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_fldr_parts_root_gen_path(
    EMAIL_ACCT_ID acct_id, EMAIL_FLDR_ID fldr_id, WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(
        path,
        "%s%s\\%s\\%u\\%s%u",
        srv_email_get_root_path(),
        EMAIL_STOR_SYS_DIR,
        EMAIL_INDEX_FILE_FLDR,
        acct_id,
        EMAIL_PARTS_FLDR,
        fldr_id);
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_parts_branch_gen_path
 * DESCRIPTION
 *  Generate a folder file's path
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  fldr_id     [IN]        Folder id
 *  offset      [IN]        
 *  path        [OUT]       Folder file path
 *  type(?)     [IN]        Folder file type
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_fldr_parts_branch_gen_path(
        EMAIL_ACCT_ID acct_id,
        EMAIL_FLDR_ID fldr_id,
        EMAIL_STOR_OFFSET offset,
        WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 part_dir_id = (offset) / EMAIL_STOR_MSG_NUM_PER_PARTS_DIR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(
        path,
        "%s%s\\%s\\%u\\%s%u\\%u",
        srv_email_get_root_path(),
        EMAIL_STOR_SYS_DIR,
        EMAIL_INDEX_FILE_FLDR,
        acct_id,
        EMAIL_PARTS_FLDR,
        fldr_id,
        part_dir_id);
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_attch_root_gen_path
 * DESCRIPTION
 *  Generate a folder file's path
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  fldr_id     [IN]        Folder id
 *  path        [OUT]       Folder file path
 *  type(?)     [IN]        Folder file type
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_fldr_attch_root_gen_path(
    EMAIL_ACCT_ID acct_id, EMAIL_FLDR_ID fldr_id, WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(
        path,
        "%s%s\\%s\\%u\\%s%u",
        srv_email_get_root_path(),
        EMAIL_STOR_SYS_DIR,
        EMAIL_INDEX_FILE_FLDR,
        acct_id,
        EMAIL_ATTCH_FLDR,
        fldr_id);
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_attch_branch_gen_path
 * DESCRIPTION
 *  Generate a folder file's path
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  fldr_id     [IN]        Folder id
 *  offset      [IN]        
 *  path        [OUT]       Folder file path
 *  type(?)     [IN]        Folder file type
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_fldr_attch_branch_gen_path(
        EMAIL_ACCT_ID acct_id,
        EMAIL_FLDR_ID fldr_id,
        EMAIL_STOR_OFFSET offset,
        WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 attch_dir_id = (offset) / EMAIL_STOR_MSG_NUM_PER_ATTCH_DIR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(
        path,
        "%s%s\\%s\\%u\\%s%u\\%u",
        srv_email_get_root_path(),
        EMAIL_STOR_SYS_DIR,
        EMAIL_INDEX_FILE_FLDR,
        acct_id,
        EMAIL_ATTCH_FLDR,
        fldr_id,
        attch_dir_id);
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_gen_path
 * DESCRIPTION
 *  Generate a folder file's path
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  fldr_id     [IN]        Folder id
 *  type        [IN]        Folder file type
 *  path        [OUT]       Folder file path
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_fldr_gen_path(
        EMAIL_ACCT_ID acct_id,
        EMAIL_FLDR_ID fldr_id,
        email_stor_fldr_file_type type,
        WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *parts_suffix_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == EMAIL_STOR_FLDR_INDEX)
    {
        parts_suffix_p = (CHAR*) EMAIL_FLDR_SUFFIX_INDEX;
    }
    else if (type == EMAIL_STOR_FLDR_BACKUP)
    {
        parts_suffix_p = (CHAR*) EMAIL_FLDR_SUFFIX_BACKUP;
    }
    else
    {
        MMI_ASSERT(0);
    }

    kal_wsprintf(
        path,
        "%s%s\\%s\\%u\\%u%s",
        srv_email_get_root_path(),
        EMAIL_STOR_SYS_DIR,
        EMAIL_INDEX_FILE_FLDR,
        acct_id,
        fldr_id,
        parts_suffix_p);
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_gen_basic_id
 * DESCRIPTION
 *  generate a folder id type folder type
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  type        [IN]        Folder type
 * RETURNS
 *  folder id
 *****************************************************************************/
EMAIL_FLDR_ID email_stor_fs_fldr_gen_basic_id(
    EMAIL_ACCT_ID acct_id, srv_email_fldr_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_FLDR_ID fldr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(type >= SRV_EMAIL_FLDR_TYPE_BASICS_BGN &&
               type <= SRV_EMAIL_FLDR_TYPE_BASICS_END);

    // fldr id minimum value
    fldr_id = EMAIL_STOR_FLDR_VALID_ID_MIN;

    // get the acct's basic fldr start value
    fldr_id += (acct_id-EMAIL_STOR_ACCT_VALID_ID_MIN)*EMAIL_STOR_BASIC_FLDR_NUM;

    fldr_id += type;

    return  fldr_id;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_fldr_gen_remote_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fldr_id     [?]     
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum email_stor_fs_fldr_gen_remote_id(EMAIL_FLDR_ID *fldr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum ret;
    EMAIL_FLDR_ID next_valid_fldr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_stor_p->remote_fldr_id_next_avlid > EMAIL_STOR_FLDR_VALID_ID_MAX)
    {
        return SRV_EMAIL_RESULT_FLDR_ID_REACH_MAX_NUM;
    }

    next_valid_fldr_id = email_stor_p->remote_fldr_id_next_avlid + 1;
    ret = email_stor_fs_cntx_info_write(EMAIL_ATTCH_INVALID_ID,
                                        next_valid_fldr_id);
    if (ret != SRV_EMAIL_RESULT_SUCC)
    {
        return ret;
    }

    *fldr_id = email_stor_p->remote_fldr_id_next_avlid;
    ++(email_stor_p->remote_fldr_id_next_avlid);

    return SRV_EMAIL_RESULT_SUCC;
}

