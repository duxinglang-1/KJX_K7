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
 *  EmailSrvStorage.c
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#include "EmailSrvGprot.h"
#include "EmailSrvStorage.h"
#include "EmailSrvStorFS.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_state_available
 * DESCRIPTION
 *  Used to query whether storage is available now.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL srv_email_stor_state_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return email_stor_fs_state_available();
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_create_request
 * DESCRIPTION
 *  Create an account. Create the account directory, update acct.info
 * PARAMETERS
 *  acct_id     [OUT]       Account id
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_acct_create_request(EMAIL_ACCT_ID *acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_acct_create_request(acct_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_create_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum srv_email_stor_acct_create_cancel(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_acct_create_cancel(acct_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_del
 * DESCRIPTION
 *  Delete an account
 * PARAMETERS
 *  acct_id     [IN]        Account id
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_acct_del(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_acct_del(acct_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_get_fldr_id_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id     [IN]        
 *  type        [IN]        
 *  handle      
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_acct_get_fldr_id_open(
                        EMAIL_ACCT_ID acct_id,
                        srv_email_fldr_type_enum type,
                        EMAIL_STOR_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_acct_get_fldr_id_open(acct_id, type, handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_get_fldr_id_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  fldr_id     [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_acct_get_fldr_id_next(EMAIL_STOR_HANDLE handle, EMAIL_FLDR_ID *fldr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_acct_get_fldr_id_next(handle, fldr_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_get_fldr_id_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_acct_get_fldr_id_close(EMAIL_STOR_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_acct_get_fldr_id_close(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_get_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id         [IN]        
 *  fldr_id         [IN]        
 *  fldr_info       [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_get_by_id(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        srv_email_stor_fldr_struct *fldr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_fldr_get_info(acct_id, fldr_id, fldr_info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_get_by_type
 * DESCRIPTION
 *  NOT SUPPORTED NOW, ONLY FOR UM!
 * PARAMETERS
 *  fldr_type       [IN]        
 *  fldr_info       [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_get_by_type(
                        srv_email_fldr_type_enum fldr_type,
                        srv_email_stor_fldr_struct *fldr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* EMAIL_FLDR_ID fldr_id; */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * if (!srv_email_stor_state_available())
     * {
     * return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
     * }
     * 
     * fldr_id = email_stor_fs_fldr_get_basic_id(acct_id, fldr_type);
     * return email_stor_fs_fldr_get_info(acct_id, fldr_id, fldr_info);
     */
    return SRV_EMAIL_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_sync_msg_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  fldr_id     [IN]        
 *  handle      [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_sync_msg_open(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        EMAIL_STOR_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_fldr_sync_msg_open(acct_id, fldr_id, handle, EMAIL_MSG_INVALID_ID);
}

srv_email_result_enum srv_email_stor_fldr_sync_msg_open_ext(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        EMAIL_STOR_HANDLE *handle,
                        EMAIL_MSG_ID last_msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_fldr_sync_msg_open(acct_id, fldr_id, handle, last_msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_sync_msg_get_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  msg_info        [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_sync_msg_get_next(
                        EMAIL_STOR_HANDLE handle,
                        srv_email_stor_fldr_get_msg_id_struct *msg_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_fldr_sync_msg_get_next(handle, msg_info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_sync_msg_set_flag
 * DESCRIPTION
 *  Set a msg's flag, it must belong to the current floder.
 * PARAMETERS
 *  handle          [IN]        Handle
 *  msg_id          [IN]        MSG id
 *  new_flag        [IN]        New flag
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_sync_msg_set_flag(
                        EMAIL_STOR_HANDLE handle,
                        EMAIL_MSG_ID msg_id,
                        EMAIL_MSG_FLAG new_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_fldr_sync_msg_set_flag(handle, msg_id, new_flag);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_sync_msg_del
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_sync_msg_del(EMAIL_STOR_HANDLE handle, EMAIL_MSG_ID msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_fldr_sync_msg_del(handle, msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_sync_msg_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_sync_msg_close(EMAIL_STOR_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_fldr_sync_msg_close(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_del
 * DESCRIPTION
 *  Delete all the MSG under this folder, include the Folder.
 * PARAMETERS
 *  acct_id             [IN]        The account id
 *  fldr_id_array       [IN]        The folder id array pointer
 *  fldr_id_num         [IN]        The folder id array's size
 *  callback            [IN]        The pointer point to the callback function
 *  user_data           [IN]        User data
 *  req_id(?)           [OUT]       Used to return the request id
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_del(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID *fldr_id_array,
                        U32 fldr_id_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_fldr_del(acct_id, fldr_id_array, fldr_id_num);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id         [IN]        
 *  fldr_info       [IN]        
 *  fldr_id         [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_create(
                        EMAIL_ACCT_ID acct_id,
                        const srv_email_stor_fldr_create_info_struct *fldr_info,
                        EMAIL_FLDR_ID *fldr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum ret;
    EMAIL_FLDR_ID fldr_id_tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    if (fldr_info->fldr_type >= SRV_EMAIL_FLDR_TYPE_BASICS_BGN && fldr_info->fldr_type <= SRV_EMAIL_FLDR_TYPE_BASICS_END)
    {
        fldr_id_tmp = email_stor_fs_fldr_gen_basic_id(acct_id, fldr_info->fldr_type);
    }
    else
    {
        if ((ret = email_stor_fs_fldr_gen_remote_id(&fldr_id_tmp)) != SRV_EMAIL_RESULT_SUCC)
        {
            return ret;
        }
    }

    if (fldr_id != NULL)
    {
        *fldr_id = fldr_id_tmp;
    }

    return email_stor_fs_fldr_create(acct_id, fldr_id_tmp, fldr_info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_list_msg_open
 * DESCRIPTION
 *  List MSG(s) from the specified folder
 * PARAMETERS
 *  fldr_type           [IN]    Folder type
 *  acct_id             [IN]    Account id
 *  fldr_id             [IN]    Folder id
 *  text_type           [IN]    Text wanted
 *  date_type           [IN]        
 *  base_index          [IN]    if (base_index == -1), means in fldr_list_next() msg_id is required
 *  handle              [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_list_msg_open(
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_fldr_list_msg_open(
            fldr_type,
            acct_id,
            fldr_id,
            text_type,
            date_type,
            base_index,
            handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_list_msg_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  header      [IN/OUT]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_list_msg_next(
                        EMAIL_STOR_HANDLE handle,
                        srv_email_stor_msg_list_header_struct *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_fldr_list_msg_next(handle, header);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_list_msg_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_list_msg_close(EMAIL_STOR_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_fldr_list_msg_close(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_del_msg_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fldr_type       [IN]        
 *  acct_id         [IN]        
 *  fldr_id         [IN]        
 *  del_header      [IN]        
 *  del_server      [IN]        
 *  handle          [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_del_msg_open(
                        srv_email_fldr_type_enum fldr_type,
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        MMI_BOOL del_header,
                        MMI_BOOL del_server,
                        EMAIL_STOR_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_fldr_del_msg_open(fldr_type, acct_id, fldr_id, del_header, del_server, handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_del_msg_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_del_msg_next(EMAIL_STOR_HANDLE handle, EMAIL_MSG_ID msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_fldr_del_msg_next(handle, email_stor_fs_msg_id_to_offset(msg_id));
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_del_msg_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_del_msg_close(EMAIL_STOR_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_fldr_del_msg_close(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_set_msg_flag_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fldr_type       [IN]        
 *  acct_id         [IN]        
 *  fldr_id         [IN]        
 *  mask            [IN]        
 *  flag            [IN]        
 *  handle          [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_set_msg_flag_open(
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_fldr_set_msg_flag_open(fldr_type, acct_id, fldr_id, mask, flag, handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_set_msg_flag_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  msg_id      [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_set_msg_flag_next(EMAIL_STOR_HANDLE handle, EMAIL_MSG_ID msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_fldr_set_msg_flag_next(handle, email_stor_fs_msg_id_to_offset(msg_id));
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_set_msg_flag_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_fldr_set_msg_flag_close(EMAIL_STOR_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_fldr_set_msg_flag_close(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_create_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_create_handle       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_create_abort(EMAIL_STOR_HANDLE msg_create_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }
    return email_stor_fs_msg_edit_abort(msg_create_handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  header                      [?]
 *  query_text_callback         [IN]        
 *  query_addr_callback         [IN]        
 *  query_attch_callback        [IN]        
 *  callback                    [IN]        
 *  user_data                   [?]
 *  msg_create_handle           
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_create(
                        srv_email_stor_msg_create_header_struct *header,
                        srv_email_stor_msg_query_text_funcptr_type query_text_callback,
                        srv_email_stor_msg_query_addr_funcptr_type query_addr_callback,
                        srv_email_stor_msg_query_attch_funcptr_type query_attch_callback,
                        srv_email_stor_msg_create_funcptr_type callback,
                        void *user_data,
                        EMAIL_STOR_HANDLE *msg_create_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_edit(
            header,
            query_text_callback,
            query_addr_callback,
            query_attch_callback,
            callback,
            user_data,
            msg_create_handle,
            EMAIL_CREATE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_fldr_get_id_by_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
EMAIL_FLDR_ID srv_email_stor_fldr_get_id_by_type(EMAIL_ACCT_ID acct_id, srv_email_fldr_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return EMAIL_FLDR_INVALID_ID;
    }

    return email_stor_fs_fldr_gen_basic_id(acct_id, type);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_get_detail_errno
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res     [IN]        
 * RETURNS
 *  error number
 *****************************************************************************/
S32 srv_email_stor_get_detail_errno(srv_email_result_enum res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return email_stor_fs_errno_detail_get(res);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_update_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_update_handle       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_update_abort(EMAIL_STOR_HANDLE msg_update_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }
    return email_stor_fs_msg_edit_abort(msg_update_handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  header                      [?]
 *  query_text_callback         [IN]        
 *  query_addr_callback         [IN]        
 *  query_attch_callback        [IN]        
 *  callback                    [IN]        
 *  user_data                   [?]
 *  msg_update_handle           [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_update(
                        srv_email_stor_msg_create_header_struct *header,
                        srv_email_stor_msg_query_text_funcptr_type query_text_callback,
                        srv_email_stor_msg_query_addr_funcptr_type query_addr_callback,
                        srv_email_stor_msg_query_attch_funcptr_type query_attch_callback,
                        srv_email_stor_msg_update_funcptr_type callback,
                        void *user_data,
                        EMAIL_STOR_HANDLE msg_update_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_edit(
            header,
            query_text_callback,
            query_addr_callback,
            query_attch_callback,
            callback,
            user_data,
            msg_update_handle,
            EMAIL_UPDATE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_move
 * DESCRIPTION
 *  
 * PARAMETERS
 *  from_msg_id     [IN]        
 *  to_acct_id          [IN]        
 *  to_fldr_id          [IN]        
 *  to_msg_id       [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_move(
                        EMAIL_MSG_ID from_msg_id,
                        EMAIL_ACCT_ID to_acct_id,
                        EMAIL_FLDR_ID to_fldr_id,
                        EMAIL_MSG_ID *to_msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_move(from_msg_id, to_acct_id, to_fldr_id, to_msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_header
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  header          [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_header(
                        EMAIL_MSG_ID msg_id,
                        srv_email_stor_msg_get_header_struct *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_get_header(msg_id, header);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_subj_len
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_subj_len(EMAIL_MSG_ID msg_id, U32 *subj_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_get_subj_len(msg_id, subj_len);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_subj
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  subj            [?]
 *  buffer_size     [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_subj(EMAIL_MSG_ID msg_id, CHAR *subj, U32 *buffer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_get_subj(msg_id, subj, buffer_size);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_cont_len
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  type            [IN]        
 * RETURNS
 *  content length
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_cont_len(EMAIL_MSG_ID msg_id, srv_email_stor_msg_cont_type type, U32 *cont_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_get_cont_len(msg_id, type, cont_len);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_cont
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  type            [IN]        
 *  cont_header     [?]
 *  path            
 *  size            [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_cont(
                        EMAIL_MSG_ID msg_id,
                        srv_email_stor_msg_cont_type type,
                        srv_email_stor_cont_header_struct *cont_header,
                        WCHAR *path,
                        U32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_get_cont(msg_id, type, cont_header, path, size);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_addr_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  base_index      [IN]        
 *  addr_type       [IN]        
 *  handle          [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_addr_open(
                        EMAIL_MSG_ID msg_id,
                        U32 base_index,
                        srv_email_addr_type_enum addr_type,
                        EMAIL_STOR_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_get_addr_open(msg_id, base_index, addr_type, handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_addr_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle              [IN]        
 *  disp_name_len       [IN]        
 *  addr_len            [IN]        
 *  disp_name           [?]
 *  addr                [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_addr_next(
                        EMAIL_STOR_HANDLE handle,
                        U32 disp_name_len,
                        U32 addr_len,
                        CHAR *disp_name,
                        CHAR *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_get_addr_next(handle, disp_name_len, addr_len, disp_name, addr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_addr_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_addr_close(EMAIL_STOR_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_get_addr_close(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_attch_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  base_index      [IN]        
 *  handle          [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_attch_open(
                        EMAIL_MSG_ID msg_id,
                        U32 base_index,
                        EMAIL_STOR_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_get_attch_open(msg_id, base_index, handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_attch_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  attch       [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_attch_next(EMAIL_STOR_HANDLE handle, srv_email_stor_attch_struct *attch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_get_attch_next(handle, attch);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_attch_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_attch_close(EMAIL_STOR_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_get_attch_close(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_attch_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  attch_id        [IN]        
 *  attch           
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_attch_info(
                        EMAIL_MSG_ID msg_id,
                        EMAIL_ATTCH_ID attch_id,
                        srv_email_stor_attch_struct *attch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_STOR_HANDLE hd;
    srv_email_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    result = email_stor_fs_msg_get_attch_open(msg_id, 0, &hd);

    if (result == SRV_EMAIL_RESULT_SUCC)
    {
        while ((result = email_stor_fs_msg_get_attch_next(hd, attch)) == SRV_EMAIL_RESULT_SUCC)
        {
            if (attch->attch_id == attch_id)
            {
                email_stor_fs_msg_get_attch_close(hd);
                return SRV_EMAIL_RESULT_SUCC;
            }
        }
        email_stor_fs_msg_get_attch_close(hd);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_attch_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  attch_id        [IN]        Attach id
 *  attch_path      [?]
 *  buff_size       [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_attch_path(EMAIL_ATTCH_ID attch_id, WCHAR *attch_path, U32 buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_get_attch_path(attch_id, attch_path, buff_size);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_load_attch
 * DESCRIPTION
 *  Load an attachment
 * PARAMETERS
 *  msg_id                  [IN]        MSG id
 *  attch_id                [IN]        Attach id
 *  attch_path              [IN]        Attach path
 *  keep_src                [IN]        Whether source file need kept, if NOT, will rename, not copy
 *  drm                     [IN]        
 *  drm_content_type        [IN]        [?]
 *  new_filename            [IN]        
 *  new_charset             [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_load_attch(
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_load_attch(
            msg_id,
            attch_id,
            attch_path,
            keep_src,
            drm,
            drm_content_type,
            new_filename,
            new_charset);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_init
 * DESCRIPTION
 *  Initialize EMAIL storage
 * PARAMETERS
 *  callback        [IN]        
 *  user_data       
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_init(srv_email_stor_res_funcptr_type callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return email_stor_fs_init(callback, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_init_state
 * DESCRIPTION
 *  Query whether storage initialization complete.
 * PARAMETERS
 *  void
 * RETURNS
 *  storage state
 *****************************************************************************/
srv_email_stor_state_enum srv_email_stor_init_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return email_stor_fs_state_get();
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_is_reset_during_init
 * DESCRIPTION
 *  Whether storage is reset (including ACCT & MSG) during INIT.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 ****************************************************************************/
MMI_BOOL srv_email_storage_is_reset_during_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return email_stor_p->is_storage_reset;
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_id_get
 * DESCRIPTION
 *  Get account id(s)
 * PARAMETERS
 *  acct_id     [OUT]       Account id
 * RETURNS
 *  result code
 *****************************************************************************/
U32 srv_email_stor_acct_id_get(EMAIL_ACCT_ID *acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return 0;
    }

    return email_stor_fs_acct_id_get(acct_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_default_id_get
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_acct_default_id_get(EMAIL_ACCT_ID *default_acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        *default_acct_id = EMAIL_ACCT_INVALID_ID;
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_acct_default_id_get(default_acct_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_default_id_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id     [IN]        Account id
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_acct_default_id_set(EMAIL_ACCT_ID acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_acct_default_id_set(acct_id);
}

srv_email_result_enum srv_email_stor_acct_default_id_del(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_acct_default_id_del();
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_info_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_info       [?]     [?]     [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_acct_info_read(srv_email_acct_info_struct *acct_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_acct_info_read(acct_info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_info_write
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_info       [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_acct_info_write(const srv_email_acct_info_struct *acct_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_acct_info_write(acct_info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_info_write_async
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_info       [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_acct_info_write_async(const srv_email_acct_info_struct *acct_info,
                         srv_email_stor_acct_write_funcptr_type callback, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_acct_info_write_async(acct_info, callback, user_data);
}

void srv_email_stor_acct_info_write_async_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return;
    }

    email_stor_fs_acct_info_write_async_abort();
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_id_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_id_valid(EMAIL_MSG_ID msg_id, MMI_BOOL *is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_id_valid_ext(msg_id, MMI_FALSE, is_valid);
}

srv_email_result_enum srv_email_stor_msg_id_valid_ext(EMAIL_MSG_ID msg_id, MMI_BOOL chk_attch, MMI_BOOL *is_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_id_valid_ext(msg_id, chk_attch, is_valid);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_load_cont
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  type            [IN]        
 *  cont_path       [IN]        
 *  keep_src        [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_load_cont(
                        EMAIL_MSG_ID msg_id,
                        srv_email_stor_msg_cont_type type,
                        const WCHAR *cont_path,
                        MMI_BOOL keep_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_load_cont(msg_id, type, cont_path, keep_src);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_get_fldr_num
 * DESCRIPTION
 *  Query folder number by folder type
 * PARAMETERS
 *  acct_id     [IN]        
 *  type        [IN]        Folder type
 * RETURNS
 *  folder number, negative means error occurs.
 *****************************************************************************/
S32 srv_email_stor_acct_get_fldr_num(EMAIL_ACCT_ID acct_id, srv_email_fldr_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_STOR_HANDLE handle;
    EMAIL_FLDR_ID fldr_id;
    S32 cnt = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return -1;
    }

    MMI_ASSERT(type == SRV_EMAIL_FLDR_TYPE_BASICS || type == SRV_EMAIL_FLDR_TYPE_ALL ||
               type == SRV_EMAIL_FLDR_TYPE_REMOTE);
    if (type == SRV_EMAIL_FLDR_TYPE_BASICS)
    {
        cnt = SRV_EMAIL_FLDR_TYPE_BASICS_CNT;
    }
    else
    {
        if (email_stor_fs_acct_get_fldr_id_open(acct_id, type, &handle) == SRV_EMAIL_RESULT_SUCC)
        {
            cnt = 0;
            while (email_stor_fs_acct_get_fldr_id_next(handle, &fldr_id) == SRV_EMAIL_RESULT_SUCC)
            {
                cnt++;
            }
            email_stor_fs_acct_get_fldr_id_close(handle);

            if (type == SRV_EMAIL_FLDR_TYPE_REMOTE)
            {
                MMI_ASSERT(cnt >= 0);
            }
        }
    }
    return cnt;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_cont_exist
 * DESCRIPTION
 *  To query whether TEXT/HTML exist
 * PARAMETERS
 *  msg_id              [OUT]       MSG id
 *  text_exist_mask     
 *  html_exist_mask     
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_cont_exist(EMAIL_MSG_ID msg_id, S8 *text_exist_mask, S8 *html_exist_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_cont_exist(msg_id, text_exist_mask, html_exist_mask);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_cont_size
 * DESCRIPTION
 *  To query whether TEXT/HTML exist
 * PARAMETERS
 *  msg_id              [OUT]       MSG id
 *  text_exist_mask     
 *  html_exist_mask     
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_cont_size(EMAIL_MSG_ID msg_id, U32 *text_size, U32 *html_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_msg_cont_size(msg_id, text_size, html_size);
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_copy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  from_msg_id     [IN]        
 *  to_acct_id      [IN]        
 *  to_fldr_id      [IN]        
 *  to_msg_id       
 *  req_id          
 *  callback        [IN]        
 *  user_data       
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_copy(
                        EMAIL_MSG_ID from_msg_id,
                        EMAIL_ACCT_ID to_acct_id,
                        EMAIL_FLDR_ID to_fldr_id,
                        EMAIL_MSG_ID *to_msg_id,
                        EMAIL_REQ_ID *req_id,
                        srv_email_stor_msg_copy_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    // TODO: NOT supported now
    return SRV_EMAIL_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_copy_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_copy_abort(EMAIL_REQ_ID req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    // TODO: NOT supported now
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_inbox_get_recent_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id             [IN]        
 *  start_index         [IN]        
 *  count               
 *  flag_mask           [IN]        
 *  matched_flag        [IN]        
 *  msg_array           
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum srv_email_stor_inbox_get_recent_list(
                        EMAIL_ACCT_ID acct_id,
                        S32 start_index,
                        U32 *count,
                        U8 flag_mask,
                        EMAIL_MSG_FLAG matched_flag,
                        srv_email_inbox_index_msg_struct *msg_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_inbox_get_recent_list(acct_id, start_index, count, flag_mask, matched_flag, msg_array);
}

srv_email_result_enum srv_email_stor_get_all_msg_id(
                        EMAIL_ACCT_ID acct_id,
                                EMAIL_FLDR_ID fldr_id,
                        U8 flag_mask, 
                        EMAIL_MSG_FLAG matched_flag,
                                U32 *count,
                                EMAIL_MSG_ID *msg_id)
{
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_get_all_msg_id(
        acct_id, fldr_id, flag_mask, matched_flag, count, msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_id_to_acct_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
EMAIL_ACCT_ID srv_email_stor_msg_id_to_acct_id(EMAIL_MSG_ID msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return EMAIL_ACCT_INVALID_ID;
    }

    return email_stor_fs_msg_id_to_acct_id(msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_id_to_fldr_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
EMAIL_FLDR_ID srv_email_stor_msg_id_to_fldr_id(EMAIL_MSG_ID msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return EMAIL_FLDR_INVALID_ID;
    }

    return email_stor_fs_msg_id_to_fldr_id(msg_id);
}

EMAIL_MSG_ID srv_email_stor_attch_id_to_msg_id(EMAIL_ATTCH_ID attch_id)
{
    return email_stor_fs_attch_id_to_msg_id(attch_id);
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_cache_notify_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_stor_acct_cache_notify_set(
    srv_email_all_msg_unread_notify_funcptr callback, void* userdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_stor_fs_acct_cache_notify_set(callback, userdata);
}

srv_email_result_enum srv_email_acct_total_unread_num_get(U32 *total_unread_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        *total_unread_num = 0;
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    *total_unread_num = email_stor_fs_acct_info_cache_cnt_msg_unread();

	return SRV_EMAIL_RESULT_SUCC;
}



/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_acct_cache_get
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id             [IN]        
 *  acct_info_cache     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_stor_acct_cache_get(EMAIL_ACCT_ID acct_id, srv_email_acct_info_cache_struct *acct_info_cache)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return;
    }
    email_stor_fs_acct_info_cache_get(acct_id, acct_info_cache);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_stor_msg_get_flag_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  flag        
 *  state       
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum srv_email_stor_msg_get_flag_state(
                        EMAIL_MSG_ID msg_id,
                        EMAIL_MSG_FLAG *flag,
                        EMAIL_MSG_STATE *state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }
    return email_stor_fs_msg_get_flag_state(msg_id, flag, state);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_fldr_id_to_fldr_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id     [IN]        
 *  fldr_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_email_fldr_type_enum srv_email_fldr_id_to_fldr_type(EMAIL_ACCT_ID acct_id, EMAIL_FLDR_ID fldr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_FLDR_TYPE_INVALID;
    }
    return email_stor_fs_fldr_id_to_fldr_type(acct_id, fldr_id);
}


EMAIL_FLDR_ID srv_email_fldr_type_to_fldr_id(EMAIL_ACCT_ID acct_id, srv_email_fldr_type_enum fldr_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return EMAIL_FLDR_INVALID_ID;
    }
    return srv_email_stor_fldr_get_id_by_type(acct_id, fldr_type);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_pre_install_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum srv_email_acct_pre_install_open(EMAIL_SRV_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_STOR_HANDLE stor_hd;
    srv_email_result_enum res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    res = email_stor_fs_acct_pre_install_open(&stor_hd);
    if (res == SRV_EMAIL_RESULT_SUCC)
    {
        *handle = (EMAIL_SRV_HANDLE) stor_hd;
    }
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_pre_install_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  acct_info       
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum srv_email_acct_pre_install_create(EMAIL_SRV_HANDLE handle, srv_email_acct_info_struct *acct_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_STOR_HANDLE stor_hd = (EMAIL_STOR_HANDLE) handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_acct_pre_install_create(stor_hd, acct_info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_acct_pre_install_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum srv_email_acct_pre_install_close(EMAIL_SRV_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_STOR_HANDLE stor_hd = (EMAIL_STOR_HANDLE) handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return SRV_EMAIL_RESULT_STOR_NOT_AVAILABLE;
    }

    return email_stor_fs_acct_pre_install_close(stor_hd);
}

void srv_email_recent_list_notify_set(
        srv_email_recent_list_query_funcptr_type query,
        srv_email_recent_list_answer_funcptr_type answer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_email_stor_state_available())
    {
        return;
    }
    email_stor_p->recent_list_query_callback = query;
    email_stor_p->recent_list_answer_callback = answer;
}

MMI_BOOL srv_email_recent_envent_unread_query(U32 count, EMAIL_MSG_ID *msg_id, S8 *unread)
{
    return email_stor_fs_recent_envent_unread_query(count, msg_id, unread);
}

srv_email_result_enum srv_email_recent_envent_info_query(srv_email_msg_prio_read_struct *msg, U32 count)
{
    return email_stor_fs_recent_envent_info_query(msg, count);
}


srv_email_result_enum srv_email_stor_acct_set_cloud_acct(EMAIL_ACCT_ID acct_id, MMI_BOOL is_cloud_acct)
{
    return email_stor_acct_set_cloud_acct(acct_id, is_cloud_acct);
}

