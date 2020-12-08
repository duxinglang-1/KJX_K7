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
 * UMSrvInterface.c
 *
 * Project:
 * --------
 * MAUI
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/**********  KAL Layer Header **************/
#include "stdio.h"
#include "string.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "lcd_sw_inc.h"
#include "customer_ps_inc.h"
#include "mmi_msg_context.h"
#include "custom_wap_config.h"
#include "app_str.h" /* app_ucs2_str_to_asc_str */
#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "che_api.h"

/**********  MMI Layer Header **************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "gui_switch.h"
#include "Gui_Setting.h"
#include "wgui.h"
#include "Custom_ProvBox.h"
#include "custom_phb_config.h"
#include "UmSrvGprot.h"
#include "UmSrvprot.h"
#include "UmSrvStruct.h"
#include "PhbSrvGprot.h" /* srv_phb_sse_convert_number_to_int */
#include "SmsSrvGprot.h"
#ifdef __MMI_MMS_IN_UM__
#include "MmsSrvGprot.h"
#endif
#ifdef __MMI_PUSH_IN_UM__
#include "WapPushSrvGprots.h"
#endif
#ifdef __MMI_PROV_IN_UM__
#include "ProvBoxSrvGProt.h"
#endif

#define SRV_UM_PEEK_MSG_SIZE     MMI_MAX_MENUITEMS_IN_CONTENT    /* Max number of messages */

/*********************************
 *  Blocking Interface
 ********************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_um_check_ready
 * DESCRIPTION
 *  Check if all msg types UM supports are ready
 * PARAMETERS
 *  void
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  MMI_TRUE:   all ready
 *  MMI_FALSE:  only partial ready
 *****************************************************************************/
MMI_BOOL srv_um_check_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CHECK_READY, g_ums_p->support_type, g_ums_p->ready_type);

    return (g_ums_p->support_type == g_ums_p->ready_type ? MMI_TRUE : MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_check_support_type
 * DESCRIPTION
 *  Check specific msg types are supported by UM.
 * PARAMETERS
 *  msg_type:       [IN]    Message type, bit mask
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  MMI_TRUE:   all support
 *  MMI_FALSE:  only partial support
 *****************************************************************************/
MMI_BOOL srv_um_check_support_type(srv_um_msg_enum msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_type == SRV_UM_MSG_ALL)
    {
        msg_type = srv_um_support_msg_type();
    }

    if ((g_ums_p->support_type & msg_type) == msg_type)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_check_ready_type
 * DESCRIPTION
 *  Check specific message types are ready or not.
 * PARAMETERS
 *  msg_type:       [IN]    Message type, bit mask
 * RETURNS
 *  a boolean value
 * RETURN VALUES
 *  MMI_TRUE:   all ready
 *  MMI_FALSE:  only partial ready
 *****************************************************************************/
MMI_BOOL srv_um_check_ready_type(srv_um_msg_enum msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_type == SRV_UM_MSG_ALL)
    {
        msg_type = srv_um_support_msg_type();
    }

    if ((g_ums_p->ready_type & msg_type) == msg_type)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_support_msg_type
 * DESCRIPTION
 *  To get the message types that UM supports.
 * PARAMETERS
 *  void
 * RETURNS
 *  message types that are supported by UM, bit mask
 * RETURN VALUES
 *  srv_um_msg_enum
 *****************************************************************************/
srv_um_msg_enum srv_um_support_msg_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_um_msg_enum)g_ums_p->support_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_ready_msg_type
 * DESCRIPTION
 *  To get the message types that are ready now.
 * PARAMETERS
 *  void
 * RETURNS
 *  message types that are ready, bit mask
 * RETURN VALUES
 *  srv_um_msg_enum
 *****************************************************************************/
srv_um_msg_enum srv_um_ready_msg_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_ums_p->ready_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_clear_msg_info_cache
 * DESCRIPTION
 *  To clean the cache buffer in UM service.
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_clear_msg_info_cache(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* For special issue, when UI need to clean cache, that means all the data
       is unreliable until next get request, therefore we do not peek message
       at this time */

    if (g_ums_p->peek_msg_pid)
    {
        srv_um_cancel_request(g_ums_p->peek_msg_pid);
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI, g_ums_p->peek_msg_pid);

    return srv_um_cache_clean(SRV_UM_MSG_ALL, SRV_UM_MSG_BOX_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_cancel_request
 * DESCRIPTION
 * PARAMETERS
 *  pid:    [IN]    The process id
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_cancel_request(S32 pid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_1, pid);

    return srv_um_cancel_process(pid);
}

/*****************************************************************************
 * FUNCTION
 *   srv_um_get_request_progress
 * Description
 *   This function is to get the progress of a request
 * Parameters
 *  pid :           [IN] The process id
 *  finish_number:  [OUT] number of finished item
 *  total_number:   [OUT] number of total items
 * Returns
 *  srv_um_result_enum
 *  Please check the total_number when you get the result. It may be zero
 *  in some special situation that we cannot get the information.
 * Return Values
 *   0 :           success
 *   Neg. Value :  error code
 *
 *****************************************************************************/
S32 srv_um_get_request_progress(S32 pid, S32 *finish_number, S32 *total_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_2, pid);

    return srv_um_get_process_progress(pid, finish_number, total_number);
}

#ifndef __MMI_MSG_UM_LOW_MEMORY_COST__

/*****************************************************************************
 * FUNCTION
 *  srv_um_peek_msg_callback
 * DESCRIPTION
 *  The callback function for peeking message
 * PARAMETERS
 *  pid:        [IN]    The process id
 *  rsp:        [IN]    Resopnse message
 *  para:       [IN]    A magic number for callback function, no used now.
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
static S32 srv_um_peek_msg_callback(S32 pid, srv_um_get_msg_info_result *rsp, S32 para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_PEEK_MSG_CALLBACK);

    g_ums_p->peek_msg_pid = 0;
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_peak_msg
 * DESCRIPTION
 *  To peak message at background. In generally speaking,
 *  start entry ~ satrt entry + message number
 *  are in cache. UM service will try to peek the message arround the start entry
 *  and add them into cahce. When AP try to get next message information,
 *  UM service can provide these information in cache directly. It speeds up the
 *  performance and user feeling.
 * PARAMETERS
 *  msg_box:            [IN]    The message box information
 *  msg_list:           [IN]    The message list
 *  list_info_size:     [IN]    Size of the message list
 *  start_entry:        [IN]    The start entry
 *  msg_number:         [IN]    The message number in cache
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
static S32 srv_um_peak_msg(
            srv_um_box_identity_struct msg_box,
            srv_um_list_type_enum list_type,
            void *msg_list, //srv_um_msg_node_struct msg_list[],
            U16 list_info_size,
            U16 start_entry,
            U16 msg_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S32 peek_array[3] = {1, 2, -1};
    S32 peek, peek_start_entry;
    U16 peek_msg_number;
    MMI_BOOL found = MMI_FALSE;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_ums_p->peek_msg_pid)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CHECK_MSG_INFO, 101, start_entry, msg_number);
        return SRV_UM_RESULT_OK;
    }

    if (list_info_size == 1)
    {
        return SRV_UM_RESULT_OK;
    }


    /* peek -1 ~ 2 */
    for (i = 0; i < 3; i++)
    {
        peek = peek_array[i];

        if (peek == 0 || peek >= list_info_size)
        {
            continue;
        }

        if (peek > 0 && peek < msg_number)
        {
            /* these messages must in cache */
            continue;
        }

        if (start_entry + peek >= list_info_size)
        {
            peek_start_entry = start_entry + peek - list_info_size;
        }
        else if (start_entry + peek < 0)
        {
            peek_start_entry = start_entry + peek + list_info_size;
        }
        else
        {
            peek_start_entry = start_entry + peek;
        }

        if (peek_start_entry >= start_entry && peek_start_entry < start_entry + msg_number)
        {
            continue;
        }

        /* cannot find the nebhorhood */
        if (list_type == SRV_UM_LIST_TYPE_MSG_NODE && !srv_um_cache_search(SRV_UM_LIST_TYPE_MSG_NODE, (srv_um_msg_node_struct*)msg_list + peek_start_entry, MMI_FALSE))
        {
            found = MMI_FALSE;
        }
        else if (list_type == SRV_UM_LIST_TYPE_THREAD && !srv_um_cache_search(SRV_UM_LIST_TYPE_THREAD, (srv_um_thread_id_struct*)msg_list + peek_start_entry, MMI_FALSE))
        {
            found = MMI_FALSE;
        }
        else
        {
            found = MMI_TRUE;
        }

        if (!found)
        {
            if (peek > 0)
            {
                if (peek_start_entry < start_entry && peek_start_entry + SRV_UM_PEEK_MSG_SIZE > start_entry)
                {
                    peek_msg_number = start_entry - peek_start_entry;
                }
                else if (peek_start_entry + SRV_UM_PEEK_MSG_SIZE > list_info_size)
                {
                    peek_msg_number = list_info_size - peek_start_entry;
                }
                else
                {
                    peek_msg_number = SRV_UM_PEEK_MSG_SIZE;
                }
            }
            else
            {
                if(peek_start_entry > start_entry && peek_start_entry - (start_entry + msg_number) <= SRV_UM_PEEK_MSG_SIZE)
                {
                    peek_msg_number = peek_start_entry - (start_entry + msg_number - 1);
                    peek_start_entry = start_entry + msg_number;

                }
                else if (peek_start_entry - SRV_UM_PEEK_MSG_SIZE + 1 < 0)
                {
                    peek_msg_number = peek_start_entry + 1;
                    peek_start_entry = 0;
                }
                else
                {
                    peek_msg_number = SRV_UM_PEEK_MSG_SIZE;
                    peek_start_entry = peek_start_entry - SRV_UM_PEEK_MSG_SIZE + 1;
                }
            }

            if (peek_start_entry + peek_msg_number > list_info_size)
            {
                EXT_ASSERT(0, 0, 0, 0);
            }

            if (list_type == SRV_UM_LIST_TYPE_MSG_NODE)
            {
                g_ums_p->peek_msg_pid = srv_um_get_msg_info(msg_box, (srv_um_msg_node_struct*)msg_list + peek_start_entry, peek_msg_number, srv_um_peek_msg_callback, 0);
            }
            else
            {
            #ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
                g_ums_p->peek_msg_pid = srv_um_get_thread_info(msg_box, (srv_um_thread_id_struct*)msg_list + peek_start_entry, peek_msg_number, (srv_um_get_thread_info_cb) srv_um_peek_msg_callback, 0);
            #else
                EXT_ASSERT(0,0,0,0);
            #endif
            } // for (peek = -1; peek <=2; peek++)

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CHECK_MSG_INFO, peek, peek_start_entry, peek_msg_number);
            return SRV_UM_RESULT_OK;
        }
    }

    /* MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CHECK_MSG_INFO, 102, start_entry, msg_number); */
    return SRV_UM_RESULT_OK;
}
#endif /* __MMI_MSG_UM_LOW_MEMORY_COST__ */


/*****************************************************************************
 * FUNCTION
 *  srv_um_check_msg_info_by_ref
 * DESCRIPTION
 *  To get the message information but the UM service return the pointers in cache
 *  directly.
 * PARAMETERS
 *  msg_box:            [IN]    The message box information
 *  msg_list:           [IN]    The message list
 *  list_info_size:     [IN]    Size of message list
 *  start_entry:        [IN]    The start entry in message list to get information
 *  msg_number:         [IN]    How much message to get
 *  msg_info:           [OUT]   A pointer array contains message information pointers
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_check_msg_info_by_ref(
        srv_um_box_identity_struct msg_box,
        srv_um_msg_node_struct msg_list[],
        U16 list_info_size,
        U16 start_entry,
        U16 msg_number,
        srv_um_msg_info_struct *msg_info[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_MSG_TYPE_VALID(msg_box.msg_type);
    CHECK_PARA_VALID(msg_list);
    CHECK_PARA_VALID(list_info_size);
    CHECK_PARA_VALID(msg_number);
    CHECK_PARA_VALID(start_entry + msg_number <= list_info_size);

    if (msg_info != NULL)
    {
        memset(msg_info, 0, sizeof(srv_um_msg_info_struct*) * msg_number);
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_3, msg_box.msg_type, msg_box.msg_box_type, start_entry, msg_number);

    for (i = msg_number - 1; i >= 0; i--)
    {
        srv_um_msg_info_struct *tmp;

        tmp = srv_um_cache_search(SRV_UM_LIST_TYPE_MSG_NODE, msg_list + start_entry + i, MMI_FALSE);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_4, msg_list[start_entry + i].msg_type, msg_list[start_entry + i].msg_id, tmp);

        if (tmp)
        {
            if (msg_info != NULL)
            {
                msg_info[i] = tmp;
            }
        }
        else
        {
            return SRV_UM_RESULT_DATA_NOT_FOUND;
        }
    }

    /*******************************************
     *  SMS need to send message to SMS task when enter option menu in low memory cost project.
     *  If we peek message at background, SMS will return busy error code when enter option menu.
     *  So, we turn off this function in low memory cost project.
     ******************************************************************/
#ifndef __MMI_MSG_UM_LOW_MEMORY_COST__
    srv_um_peak_msg(msg_box, SRV_UM_LIST_TYPE_MSG_NODE, msg_list, list_info_size, start_entry, msg_number);
#endif

    return SRV_UM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_check_msg_info
 * DESCRIPTION
 *  To search the message information in cache. If find it, return it directly.
 * PARAMETERS
 *  msg_box:            [IN]    The message box information
 *  msg_list:           [IN]    The message list
 *  list_info_size:     [IN]    Size of message list
 *  start_entry:        [IN]    The start entry in message list to get information
 *  msg_number:         [IN]    How much message to get
 *  msg_info:           [OUT]   A buffer contains message information
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_check_msg_info(
        srv_um_box_identity_struct msg_box,
        srv_um_msg_node_struct msg_list[],
        U16 list_info_size,
        U16 start_entry,
        U16 msg_number,
        srv_um_msg_info_struct msg_info[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_MSG_TYPE_VALID(msg_box.msg_type);
    CHECK_PARA_VALID(msg_list);
    CHECK_PARA_VALID(list_info_size);
    CHECK_PARA_VALID(msg_number);
    CHECK_PARA_VALID(start_entry + msg_number <= list_info_size);

    if (msg_info != NULL)
    {
        memset(msg_info, 0, sizeof(srv_um_msg_info_struct) * msg_number);
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_5, msg_box.msg_type, msg_box.msg_box_type, start_entry, msg_number);

    for (i = msg_number - 1; i >= 0; i--)
    {
        srv_um_msg_info_struct *tmp;

        tmp = srv_um_cache_search(SRV_UM_LIST_TYPE_MSG_NODE, msg_list + start_entry + i, MMI_FALSE);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_6, msg_list[start_entry + i].msg_type, msg_list[start_entry + i].msg_id, tmp);

        if (tmp)
        {
            if (msg_info != NULL)
            {
                memcpy(&msg_info[i], tmp, sizeof(srv_um_msg_info_struct));
            }
        }
        else
        {
            return SRV_UM_RESULT_DATA_NOT_FOUND;
        }
    }

    /*******************************************
     *  SMS need to send message to SMS task when enter option menu in low memory cost project.
     *  If we peek message at background, SMS will return busy error code when enter option menu.
     *  So, we turn off this function in low memory cost project.
     ******************************************************************/
#ifndef __MMI_MSG_UM_LOW_MEMORY_COST__
    srv_um_peak_msg(msg_box, SRV_UM_LIST_TYPE_MSG_NODE, msg_list, list_info_size, start_entry, msg_number);
#endif

    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_check_list
 * DESCRIPTION
 *  To get the mesage list. (Synchronize way)
 * PARAMETERS
 *  msg_box:            [IN]    The message box information
 *  filter:             [IN]    A filter to decide which message should be excluded
 *  cb_func:            [IN]    The callback function to notify the list is changed.
 *  user_data:            [IN]    A callback parameter in callback function
 *  list_cntx:          [OUT]   pionter to the list context
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  > 0: List CID
 *  = 0: impossible value
 *  < 0: error
 *****************************************************************************/
S32 srv_um_check_list(
        srv_um_list_type_enum list_type,
        srv_um_box_identity_struct msg_box,
        srv_um_list_filter_struct *filter,
        srv_um_notify_list_handler cb_func,
        S32 user_data,
        srv_um_list_cntx_struct **list_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_cid;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_box.msg_type == SRV_UM_MSG_ALL)
    {
        msg_box.msg_type = srv_um_support_msg_type();
    }

    CHECK_MSG_TYPE_VALID(msg_box.msg_type);
    CHECK_PARA_VALID(cb_func);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_7, msg_box.msg_type, msg_box.msg_box_type, cb_func);

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    if (filter)
    {
        srv_um_update_thread_id(&(filter->thread_id));
    }
#endif

    if (SRV_UM_RESULT_OK > (result = list_cid = srv_um_listmgr_search(list_type, msg_box, filter, list_cntx)))
    {
        return result;
    }

    if (SRV_UM_RESULT_OK > (result = srv_um_listmgr_register(list_cid, cb_func, user_data)))
    {
        return result;
    }

    return list_cid;
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_check_msg_num
 * DESCRIPTION
 *  currently, only can get all SIM in each box message number,
 *  please set sim_id = SRV_UM_SIM_ALL
 *  msg_type must has value, other wise no message number can be got.
 *  If need get all message type number, set msg_type = SRV_UM_MSG_ALL
 *  If return FALSE, data->error will indicate error casue using srv_um_result_enum
 *  and data->msg_type will indicate success got type message number
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_check_msg_num(srv_um_sim_enum sim_id, srv_um_msg_enum msg_type, srv_um_get_msg_num_result *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    data->error = SRV_UM_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CHECK_PARA_VALID(data);
    CHECK_PARA_VALID(sim_id == SRV_UM_SIM_ALL);

    if (sim_id != SRV_UM_SIM_ALL)
    {
        data->error = SRV_UM_RESULT_INVALID_PARA;
    }
    else if (srv_um_ready_msg_type() == SRV_UM_MSG_NONE)
    {
        data->error = SRV_UM_RESULT_NOT_READY;
    }
    else
    {
        memset(data, 0x00, sizeof(srv_um_get_msg_num_result));

        data->sim_id = SRV_UM_SIM_ALL;

        if (msg_type == SRV_UM_MSG_ALL)
        {
            msg_type = srv_um_support_msg_type();
        }

        if ((srv_um_ready_msg_type()& msg_type) != msg_type)
        {
            data->error = SRV_UM_RESULT_PARTIAL_READY;
        }

        if ((msg_type & SRV_UM_MSG_SMS) && srv_um_check_ready_type(SRV_UM_MSG_SMS))
        {
            data->inbox_unread_msg_number = srv_sms_get_unread_sms_num();
            data->inbox_msg_number = srv_sms_get_list_size(SRV_SMS_BOX_INBOX);
            data->unsent_msg_number = srv_sms_get_list_size(SRV_SMS_BOX_UNSENT);
            data->sent_msg_number = srv_sms_get_list_size(SRV_SMS_BOX_OUTBOX);
            data->draft_msg_number = srv_sms_get_list_size(SRV_SMS_BOX_DRAFTS);
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            data->archive_msg_number = srv_sms_get_list_size(SRV_SMS_BOX_ARCHIVE);
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
        #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
            data->sim_msg_number = srv_sms_get_list_size(SRV_SMS_BOX_SIM);
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
        #ifdef __MMI_UM_REPORT_BOX__
            data->report_msg_number = srv_sms_get_list_size(SRV_SMS_BOX_REPORT);
        #endif /* __MMI_UM_REPORT_BOX__ */

            data->msg_type |= SRV_UM_MSG_SMS;
        }

    #ifdef __MMI_MMS_IN_UM__
        if ((msg_type & SRV_UM_MSG_MMS) && srv_um_check_ready_type(SRV_UM_MSG_MMS))
        {
            srv_mms_get_msg_count_struct msg_count_req;

            memset(&msg_count_req, 0x00, sizeof(srv_mms_get_msg_count_struct));

            msg_count_req.req_tb[0] = SRV_MMS_QUERY_TOTAL_UNREAD_INBOX_MSG;
            msg_count_req.req_tb[1] = SRV_MMS_QUERY_TOTAL_INBOX_MSG;
            msg_count_req.req_tb[2] = SRV_MMS_QUERY_TOTAL_OUTBOX_MSG;
            msg_count_req.req_tb[3] = SRV_MMS_QUERY_TOTAL_SENT_MSG;
            msg_count_req.req_tb[4] = SRV_MMS_QUERY_TOTAL_DRAFT_MSG;
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            msg_count_req.req_tb[5] = SRV_MMS_QUERY_TOTAL_ARCHIVE_MSG;
            msg_count_req.count = 6;
        #else
            msg_count_req.count = 5;
        #endif

            if (srv_mms_get_msg_count(&msg_count_req) == SRV_MMS_RESULT_OK)
            {
                data->inbox_unread_msg_number += msg_count_req.rsp_tb[0];
                data->inbox_msg_number += msg_count_req.rsp_tb[1];
                data->unsent_msg_number += msg_count_req.rsp_tb[2];
                data->sent_msg_number += msg_count_req.rsp_tb[3];
                data->draft_msg_number += msg_count_req.rsp_tb[4];
            #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
                data->archive_msg_number += msg_count_req.rsp_tb[5];
            #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

                data->msg_type |= SRV_UM_MSG_MMS;
            }
            else
            {
                data->error = SRV_UM_RESULT_UNKNOWN_ERROR;
            }
        }
    #endif

    #ifdef __MMI_PUSH_IN_UM__
        if ((msg_type & SRV_UM_MSG_WAP_PUSH) && srv_um_check_ready_type(SRV_UM_MSG_WAP_PUSH))
        {
            data->inbox_unread_msg_number += srv_get_push_unread_count();
            data->msg_type |= SRV_UM_MSG_WAP_PUSH;
        }
    #endif

    #ifdef __MMI_PROV_IN_UM__
        if ((msg_type & SRV_UM_MSG_PROV) && srv_um_check_ready_type(SRV_UM_MSG_PROV))
        {
            data->inbox_unread_msg_number += srv_provbox_get_unread_msg_num(SRV_PROVBOX_BOX_TYPE_INBOX, MMI_SIM_ALL);
            data->msg_type |= SRV_UM_MSG_PROV;
        }
    #endif
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_8, data->error, msg_type, data->msg_type);

    return data->error;
}

/*********************************
 *  Non-Blocking Interface
 ********************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_um_get_msg_num
 * DESCRIPTION
 *  To get the message number
 * PARAMETERS
 *  msg_type:       [IN]    The message type, bit mask
 *  sim_id:         [IN]    The sim id, set as SRV_UM_SIM_ALL if no use.
 *  cb_func:        [IN]    The callback function when the response message back
 *  user_data:        [IN]    A callback parameter in callback function
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  > 0: the process id
 *  < 0: error
 *****************************************************************************/
S32 srv_um_get_msg_num(
        srv_um_msg_enum msg_type,
        srv_um_sim_enum sim_id,
        srv_um_get_msg_num_cb cb_func,
        S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_get_msg_num_para_struct *para;
    S32 pid;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_type == SRV_UM_MSG_ALL)
    {
        msg_type = srv_um_support_msg_type();
    }

    CHECK_MSG_TYPE_VALID(msg_type);
    CHECK_PARA_VALID(cb_func);

    pid = result = srv_um_create_process(UMS_PROCESS_TYPE_GET_MSG_NUM, (void **)&para);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_9, msg_type, sim_id, pid, cb_func);

    if (result < SRV_UM_RESULT_OK)
    {
        return result;
    }

    para->msg_type = msg_type;
    para->sim_id = sim_id;
    para->cb_func = cb_func;
    para->user_data = user_data;

    result = srv_um_start_process(pid);

    if (result < SRV_UM_RESULT_OK)
    {
        return result;
    }
    else
    {
        return pid;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_get_list
 * DESCRIPTION
 *  To get the mesage list.
 * PARAMETERS
 *  msg_box:            [IN]    The message box information
 *  msg_list:           [OUT]   The buffer to fill in message list
 *  msg_list_size:      [IN]    Size of message list
 *  filter:             [IN]    A filter to decide which message should be excluded
 *  cb_func:            [IN]    The callback function when the response message back
 *  user_data:            [IN]    A callback parameter in callback function
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  > 0: the process id
 *  < 0: error
 *****************************************************************************/
S32 srv_um_get_list(
        srv_um_list_type_enum list_type,
        srv_um_box_identity_struct msg_box,
        srv_um_list_filter_struct *filter,
        srv_um_get_list_cb cb_func,
        S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_get_list_para_struct *para;
    S32 pid=0;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_um_check_ready())
    {
        return SRV_UM_RESULT_NOT_READY;
    }
    
    if (msg_box.msg_type == SRV_UM_MSG_ALL)
    {
        msg_box.msg_type = srv_um_support_msg_type();
    }

    CHECK_MSG_TYPE_VALID(msg_box.msg_type);
    CHECK_PARA_VALID(cb_func);

    if (list_type == SRV_UM_LIST_TYPE_MSG_NODE)
    {
        /* create a process to get list */
        pid = result = srv_um_create_process(UMS_PROCESS_TYPE_GET_MSG_LIST, (void **)&para);
    }
    else
    {
    #ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
        if (filter)
        {
            srv_um_update_thread_id(&(filter->thread_id));
        }

        /* create a process to get list */
        pid = result = srv_um_create_process(UMS_PROCESS_TYPE_GET_THREAD_LIST, (void **)&para);
    #else
        ASSERT(0);
        result = SRV_UM_RESULT_NOT_SUPPORT;
    #endif
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_10, list_type, msg_box.msg_type, msg_box.msg_box_type, pid);

    if (result < SRV_UM_RESULT_OK)
    {
        return result;
    }

    /* Create a list first */
    para->msg_box = msg_box;

    if (filter)
    {
        kal_mem_cpy(&para->filter, filter, sizeof(srv_um_list_filter_struct));
    }
    else
    {
        memset(&para->filter, 0, sizeof(srv_um_list_filter_struct));
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_11, cb_func);

    para->cb_func = cb_func;
    para->user_data = user_data;

    result = srv_um_start_process(pid);

    if (result < SRV_UM_RESULT_OK)
    {
        return result;
    }
    else
    {
        return pid;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_release_list
 * DESCRIPTION
 *  To release a message list
 * PARAMETERS
 *  list_cntx:      [IN]   pionter to the list context
 *  out_of_date:    [IN]   the message list is out of data or not, if yes,
 *                         service will clean the message list or reserve it.
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  = 0: success
 *  < 0: error
 *****************************************************************************/
S32 srv_um_release_list(S32 list_cid, MMI_BOOL out_of_date)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_12, list_cid, out_of_date);

    if (out_of_date)
    {
        return srv_um_listmgr_delete(list_cid);
    }
    else
    {
        return srv_um_listmgr_unregister(list_cid);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_get_msg_info
 * DESCRIPTION
 *  To get the message info via asynchronous way
 * PARAMETERS
 *  msg_box:        [IN]    The message box information
 *  msg_list:       [IN]    The message list need to get message information
 *  msg_number:     [IN]    How much message to get message information
 *  cb_func:        [IN]    The callback function when the response message back
 *  user_data:        [IN]    A callback parameter in callback function
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  > 0: the process id
 *  < 0: error
 *****************************************************************************/
S32 srv_um_get_msg_info(
        srv_um_box_identity_struct msg_box,
        srv_um_msg_node_struct msg_list[],
        U16 msg_number,
        srv_um_get_msg_info_cb cb_func,
        S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_get_msg_info_para_struct *para;
    S32 pid;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_box.msg_type == SRV_UM_MSG_ALL)
    {
        msg_box.msg_type = srv_um_support_msg_type();
    }

    CHECK_MSG_TYPE_VALID(msg_box.msg_type);
    CHECK_PARA_VALID(msg_list);
    CHECK_PARA_VALID(msg_number > 0 && msg_number <= SRV_UM_MIN_MSG_DETAIL_NUM);
    CHECK_PARA_VALID(cb_func);

    pid = result = srv_um_create_process(UMS_PROCESS_TYPE_GET_MSG_INFO, (void **)&para);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_13, msg_box.msg_type, msg_box.msg_box_type, msg_number, pid, cb_func);

    if (result < SRV_UM_RESULT_OK)
    {
        return result;
    }
    para->msg_box = msg_box;
    para->msg_list = msg_list;
    para->msg_number = msg_number;
    para->cb_func = cb_func;
    para->user_data = user_data;

    result = srv_um_start_process(pid);

    if (result < SRV_UM_RESULT_OK)
    {
        return result;
    }
    else
    {
        return pid;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_um_delete_folder
 * DESCRIPTION
 *  To delete message folder via asynchronous way.
 * PARAMETERS
 *  msg_box:    [IN]    The message box information
 *  cb_func:    [IN]    The callback function when the response message back
 *  user_data:    [IN]    A callback parameter in callback function
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  > 0: the process id
 *  < 0: error
 *****************************************************************************/
S32 srv_um_delete_folder(
    srv_um_box_identity_struct msg_box,
    srv_um_delete_folder_cb cb_func,
    S32 user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_delete_folder_para_struct *para;
    S32 pid;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_box.msg_type == SRV_UM_MSG_ALL)
    {
        msg_box.msg_type = srv_um_support_msg_type();
    }

    CHECK_MSG_TYPE_VALID(msg_box.msg_type);
    CHECK_PARA_VALID(cb_func);

    pid = result = srv_um_create_process(UMS_PROCESS_TYPE_DELETE_FOLDER, (void **)&para);
    if (result < SRV_UM_RESULT_OK)
    {
        return result;
    }

    para->msg_box = msg_box;
    para->cb_func = cb_func;
    para->user_data = user_data;

    result = srv_um_start_process(pid);

    if (result < SRV_UM_RESULT_OK)
    {
        return result;
    }
    else
    {
        return pid;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_um_mark_several_op
 * DESCRIPTION
 *  To do mark several operation via asynchronous way.
 * PARAMETERS
 *  msg_box:            [IN]    The message box information
 *  msg_list:           [IN]    The message list to do mark several operation
 *  msg_list_size:      [IN]    The size of message list
 *  mark_status:        [IN]    The mark status of each message node in list. Each bit
 *                              is corresponed to one message node. The left-most bit (MSB) in
 *                              mark_status[0] is corresponded to the first message node.
 *                              The right-most bit (LSB) in mark_Status[0] is corresponed to
 *                              32th message node.
 *  action_type:        [IN]    The type of action
 *  cb_func:            [IN]    The callback function when the response message back
 *  user_data:            [IN]    a callback parameter in callback function
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  > 0: the process id
 *  < 0: error
 *****************************************************************************/
S32 srv_um_mark_several_op(
        srv_um_box_identity_struct msg_box,
        srv_um_msg_node_struct msg_list[],
        U16 msg_list_size,
        U32 mark_status[],
        srv_um_mark_several_op_action_enum action_type,
        srv_um_mark_several_op_cb cb_func,
        S32 user_data)
{
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_mark_several_op_para_struct *para;
    S32 pid;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_box.msg_type == SRV_UM_MSG_ALL)
    {
        msg_box.msg_type = srv_um_support_msg_type();
    }

    CHECK_MSG_TYPE_VALID(msg_box.msg_type);
    CHECK_PARA_VALID(msg_list);
    CHECK_PARA_VALID(msg_list_size);
    CHECK_PARA_VALID(mark_status);
    CHECK_PARA_VALID(cb_func);
    CHECK_PARA_VALID(msg_list_size <= SRV_UM_MAX_MSG_NUM);

    pid = result = srv_um_create_process(UMS_PROCESS_TYPE_MARK_SEVERAL_OP, (void **)&para);
    if (result < SRV_UM_RESULT_OK)
    {
        return result;
    }

    para->msg_box = msg_box;
    para->msg_list = msg_list;
    para->msg_list_size = msg_list_size;

    memcpy(para->mark_status, mark_status, ((msg_list_size + 31) >> 5) * sizeof(U32));

    para->action_type = action_type;
    para->cb_func = cb_func;
    para->user_data = user_data;

    result = srv_um_start_process(pid);

    if (result < SRV_UM_RESULT_OK)
    {
        return result;
    }
    else
    {
        return pid;
    }
#else /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
    return SRV_UM_RESULT_NOT_SUPPORT;
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
}

/************************************************************************************
  * FUNCTION
  *   srv_um_traverse_msg
  * Description
  *   This function is for application to traverse function.
  * Parameters
  *   msg_box :             [IN] The message box information
  *   msg_list:             [IN] Only traverse these message, can be NULL, then traverse all
  *   msg_number:           [IN] message number in message list
  *   traverse_func:        [IN] The callback function when traverse message
  *   field :               [IN] bitwise field, indicate which field is required.
  *   cb_func :             [IN] The callback function when the response message back
  *   user_data :           [IN] A callback parameter in callback function
  * Returns
  *   srv_um_result_enum
  * Return Values
  *   Pos. Value :  A process identifier that use to control the whole process
  *   0 :           Impossible Value
  *   Neg. Value :  Error code
  * See Also
  *   Callback Function: srv_um_traverse_msg_cb
  *   Callback Function Argument: srv_um_traverse_msg_result
  ************************************************************************************/
S32 srv_um_traverse_msg(
    srv_um_box_identity_struct msg_box,
    srv_um_msg_node_struct *msg_list,
    U16 msg_number,
    srv_um_traverse_func traverse_func,
    srv_um_detail_field_enum field,
    srv_um_traverse_msg_cb cb_func,
    S32 user_data)
{
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_traverse_msg_para_struct *para;
    S32 pid;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (msg_box.msg_type == SRV_UM_MSG_ALL)
    {
        msg_box.msg_type = srv_um_support_msg_type();
    }

    CHECK_MSG_TYPE_VALID(msg_box.msg_type);
    CHECK_PARA_VALID(cb_func);
    CHECK_PARA_VALID(traverse_func);

    /* create a process to get list */
    pid = result = srv_um_create_process(UMS_PROCESS_TYPE_TRAVERSE_MSG, (void **)&para);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_14, msg_box.msg_type, msg_box.msg_box_type, msg_number, pid, traverse_func);

    if (result < SRV_UM_RESULT_OK)
    {
        return result;
    }

    /* Create a list first */
    para->msg_box = msg_box;
    para->msg_list = msg_list;
    para->traverse_func = traverse_func;
    para->msg_number = msg_number;
    para->field = field;
    para->cb_func = cb_func;
    para->user_data = user_data;

    result = srv_um_start_process(pid);

    if (result < SRV_UM_RESULT_OK)
    {
        return result;
    }
    else
    {
        return pid;
    }

#else
    return SRV_UM_RESULT_NOT_SUPPORT;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_check_thread_info
 * DESCRIPTION
 *  To get the thread information but the UM service return the pointers in cache
 *  directly.
 * PARAMETERS
 *  thread_list:        [IN]    The thread list
 *  list_info_size:     [IN]    Size of thread list
 *  start_entry:        [IN]    The start entry in thread list to get information
 *  thread_number:      [IN]    How many thread information to get
 *  thread_info:        [OUT]   A pointer array contains thread information pointers
 *  msg_info:           [OUT]   If you want to get the message info of the first message
 *                              in each message thread. This is the pointer array contains
 *                              message information pointers.
 *                              You also can set it as NULL to get the simple thread information
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
extern S32 srv_um_check_thread_info(
        srv_um_box_identity_struct msg_box,
        srv_um_thread_id_struct thread_list[],
        U16 list_info_size,
        U16 start_entry,
        U16 thread_number,
        srv_um_thread_info_struct *thread_info[],
        srv_um_msg_info_struct *msg_info[])
{

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_box.msg_type == SRV_UM_MSG_ALL)
    {
        msg_box.msg_type = srv_um_support_msg_type();
    }

    CHECK_MSG_TYPE_VALID(msg_box.msg_type);
    CHECK_PARA_VALID(thread_list);
    CHECK_PARA_VALID(list_info_size);
    CHECK_PARA_VALID(thread_number);
    CHECK_PARA_VALID(start_entry + thread_number <= list_info_size);

    if (thread_info != NULL)
    {
        memset(thread_info, 0, sizeof(srv_um_thread_info_struct*) * thread_number);
    }

    if (msg_info != NULL)
    {
        memset(msg_info, 0, sizeof(srv_um_msg_info_struct*) * thread_number);
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_15, msg_box.msg_type, msg_box.msg_box_type, start_entry, thread_number);

    for (i = thread_number - 1; i >= 0; i--)
    {
        srv_um_thread_info_struct *tmp_thread_info;
        srv_um_msg_info_struct *tmp_msg_info;

        srv_um_update_thread_id(thread_list + start_entry + i);

        tmp_thread_info = srv_um_thread_info_search(thread_list[start_entry + i]);

        EXT_ASSERT(tmp_thread_info, 0, 0, 0);

        tmp_msg_info = srv_um_cache_search(SRV_UM_LIST_TYPE_THREAD, thread_list + start_entry + i, MMI_FALSE);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_16, (U32)((U64)thread_list[start_entry + i].value>>32), (U32)thread_list[start_entry + i].value, tmp_msg_info);

        if (tmp_msg_info)
        {
            if (thread_info)
            {
                thread_info[i] = tmp_thread_info;
            }

            if (msg_info)
            {
                msg_info[i] = tmp_msg_info;
            }
        }
        else
        {
            return SRV_UM_RESULT_DATA_NOT_FOUND;
        }
    }

    /*******************************************
     *  SMS need to send message to SMS task when enter option menu in low memory cost project.
     *  If we peek message at background, SMS will return busy error code when enter option menu.
     *  So, we turn off this function in low memory cost project.
     ******************************************************************/
#ifndef __MMI_MSG_UM_LOW_MEMORY_COST__
    srv_um_peak_msg(msg_box, SRV_UM_LIST_TYPE_THREAD, thread_list, list_info_size, start_entry, thread_number);
#endif

    return SRV_UM_RESULT_OK;

#else
    return SRV_UM_RESULT_NOT_SUPPORT;
#endif
}

/***********************************************************************************
  * FUNCTION
  *   srv_um_get_thread_info
  * Description
  *   This function gets the thread information. Due to this is a non-blocking
  *   process, application needs to register a callback function. After UMS finishes
  *   this process, UMS would invoke the callback function and return the result.
  * Parameters
  *   thread_list :   [IN] The message list need to get message information
  *   thread_number : [IN] How much message to get message information
  *   cb_func :       [IN] The callback function when the response message back
  *   user_data :     [IN] A callback parameter in callback function
  * Returns
  *   srv_um_result_enum
  * Return Values
  *   Pos. Value :  A process identifier that use to control the whole process
  *   0 :           Impossible value
  *   Neg. Value :  Error code
  * See Also
  *   Callback Function: srv_um_get_msg_info_cb
  *   Callback Function Argument: srv_um_get_msg_info_result
  ***********************************************************************************/
S32 srv_um_get_thread_info(
    srv_um_box_identity_struct msg_box,
    srv_um_thread_id_struct thread_list[],
    U16 thread_number,
    srv_um_get_thread_info_cb cb_func,
    S32 user_data)
{
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_get_thread_info_para_struct *para;
    S32 pid;
    S32 result;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_box.msg_type == SRV_UM_MSG_ALL)
    {
        msg_box.msg_type = srv_um_support_msg_type();
    }

    CHECK_MSG_TYPE_VALID(msg_box.msg_type);
    CHECK_PARA_VALID(thread_list);
    CHECK_PARA_VALID(thread_number > 0 && thread_number <= SRV_UM_MIN_MSG_DETAIL_NUM);
    CHECK_PARA_VALID(cb_func);

    for (i = thread_number - 1; i >=0 ; i--)
    {
        srv_um_update_thread_id(&thread_list[i]);
    }

    pid = result = srv_um_create_process(UMS_PROCESS_TYPE_GET_THREAD_INFO, (void **)&para);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_17, msg_box.msg_type, msg_box.msg_box_type, thread_number, pid, cb_func);

    if (result < SRV_UM_RESULT_OK)
    {
        return result;
    }

    para->msg_box = msg_box;

    if (thread_number <= SRV_UM_MAX_TRAVERSE_MSG_NUMBER)
    {
        memcpy(para->backup_thread_list, thread_list, sizeof(srv_um_thread_id_struct)* thread_number);
        para->thread_list = para->backup_thread_list;
    }
    else
    {
        para->thread_list = thread_list;
    }

    para->thread_number = thread_number;
    para->cb_func = cb_func;
    para->user_data = user_data;

    result = srv_um_start_process(pid);

    if (result < SRV_UM_RESULT_OK)
    {
        return result;
    }
    else
    {
        return pid;
    }
#else
    return SRV_UM_RESULT_NOT_SUPPORT;
#endif
}

/************************************************************************************
  * FUNCTION
  *   srv_um_mark_several_thread_op
  * Description
  *   This function is for application to do some operation on multiple thread.
  * Parameters
  *   thread_list :       [IN] The message list to do mark several operation
  *   thread_list_size :  [IN] The size of message list
  *   mark_status :    [IN] The mark status of each message node in list. Each bit is
  *                    corresponed to one message node. The left-most bit (MSB) in
  *                    mark_status[0] is corresponded to the first message node. The
  *                    right-most bit (LSB) in mark_Status[0] is corresponed to 32th
  *                    message node.
  *   action_type :    [IN] The type of action
  *   cb_func :        [IN] The callback function when the response message back
  *   user_data :      [IN] a callback parameter in callback function
  * Returns
  *   srv_um_result_enum
  * Return Values
  *   Pos. Value :  A process identifier that use to control the whole process
  *   0 :           Impossible Value
  *   Neg. Value :  Error code
  * See Also
  *   Callback Function: srv_um_mark_several_op_cb
  *   Callback Function Argument: srv_um_mark_several_op_result
  ************************************************************************************/
S32 srv_um_mark_several_thread_op(
    srv_um_box_identity_struct msg_box,
    srv_um_thread_id_struct thread_list[],
    U16 thread_list_size,
    U32 mark_status[],
    srv_um_mark_several_op_action_enum action_type,
    srv_um_mark_several_thread_op_cb cb_func,
    S32 user_data)
{
#if defined(__SRV_UM_THREAD_MESSAGE_SUPPORT__) && defined(__UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ums_mark_several_thread_op_para_struct *para;
    S32 pid;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_box.msg_type == SRV_UM_MSG_ALL)
    {
        msg_box.msg_type = srv_um_support_msg_type();
    }

    CHECK_MSG_TYPE_VALID(msg_box.msg_type);
    CHECK_PARA_VALID(thread_list);
    CHECK_PARA_VALID(thread_list_size);
    CHECK_PARA_VALID(mark_status);
    CHECK_PARA_VALID(cb_func);
    CHECK_PARA_VALID(thread_list_size <= SRV_UM_MAX_MSG_NUM);

    pid = result = srv_um_create_process(UMS_PROCESS_TYPE_MARK_SEVERAL_THREAD_OP, (void **)&para);
    if (result < SRV_UM_RESULT_OK)
    {
        return result;
    }

    para->msg_box = msg_box;

    if (thread_list_size <= SRV_UM_MAX_TRAVERSE_MSG_NUMBER)
    {
        memcpy(para->backup_thread_list, thread_list, sizeof(srv_um_thread_id_struct)* thread_list_size);
        para->thread_list = para->backup_thread_list;
    }
    else
    {
        para->thread_list = thread_list;
    }

    para->thread_list_size = thread_list_size;

    memcpy(para->mark_status, mark_status, ((thread_list_size + 31) >> 5) * sizeof(U32));

    para->action_type = action_type;
    para->cb_func = cb_func;
    para->user_data = user_data;

    result = srv_um_start_process(pid);

    if (result < SRV_UM_RESULT_OK)
    {
        return result;
    }
    else
    {
        return pid;
    }
#else /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */
        return SRV_UM_RESULT_NOT_SUPPORT;
#endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_entry_mark_several_rsp
 * DESCRIPTION
 *  To send response message of MSG_ID_SRV_UM_ENTRY_MARK_SEVERAL_REQ
 * PARAMETERS
 *  msg_box:    [IN]    The message box information
 *  result:     [IN]    The result
 * RETURNS
 *  srv_um_result_enum
 * RETURN VALUES
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_entry_mark_several_rsp(srv_um_box_identity_struct msg_box, MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_entry_mark_several_rsp_struct *rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp =
        (srv_um_entry_mark_several_rsp_struct*) construct_local_para(
                                                    sizeof(srv_um_entry_mark_several_rsp_struct),
                                                    TD_CTRL | TD_RESET);
    rsp->app_id = 0;
    rsp->msg_type = msg_box.msg_type;
    rsp->msg_box_type = msg_box.msg_box_type;
    rsp->result = result;

    srv_um_send_message(msg_box.msg_type, MSG_ID_MMI_UM_ENTRY_MARK_SEVERAL_RSP, rsp, NULL);

    return SRV_UM_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_tsfr_msg_type_to_idx
 * DESCRIPTION
 *
 * PARAMETERS
 *  msg_type        [IN]
 * RETURNS
 *
 *****************************************************************************/
S32 srv_um_tsfr_address_to_thread_id(srv_um_addr_enum type, U16* ucs2_str, srv_um_sim_enum sim_id, srv_um_thread_id_struct *thread_id)
{
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U64 number;
    STCHE che_str;
    kal_uint8 hash_array[16];
    U8 compare_length, str_length;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CACHE_TSFR_ADDRESS_TO_THREAD_ID_1, type, sim_id, mmi_ucs2strlen((CHAR*)ucs2_str));

    if (type == SRV_UM_ADDR_PHONE_NUMBER || type == SRV_UM_ADDR_EMPTY)
    {
    #ifndef __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
        U16 store_index;
        if (srv_phb_get_store_index_by_number(ucs2_str, &store_index))
        {
            thread_id->type = SRV_UM_HASH_PHONEBOOK_ID;
            thread_id->value = store_index;

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CACHE_TSFR_ADDRESS_TO_THREAD_ID_2, (U32)((U64)thread_id->value>>32), (U32)thread_id->value);

            return SRV_UM_RESULT_OK;
        }
    #endif

        /********************************************************
         *  "00123" & "123" is different in phonebook
         *  but srv_phb_convert_number_to_int64 return the same value
         *  therefore, we append the compare length at the end of the number
         *  another case
         *  "091245678" is the same as "+886912345678"
         *******************************************************/

        compare_length = srv_phb_read_compare_length();

        str_length = app_ucs2_strlen((kal_int8*)ucs2_str);

        if (compare_length > str_length)
        {
            compare_length = str_length;
        }

        number = srv_phb_convert_number_to_int64(ucs2_str);

        if (number != SRV_PHB_INVALID_INT64_NUMBER)
        {
            thread_id->type = SRV_UM_HASH_INTEGER64;
            thread_id->value = number << 4 | compare_length;
            thread_id->sim_id = sim_id;

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CACHE_TSFR_ADDRESS_TO_THREAD_ID_3, (U32)((U64)thread_id->value>>32), (U32)thread_id->value);

            return SRV_UM_RESULT_OK;
        }
    }
    else if (type == SRV_UM_ADDR_EMPTY)
    {
        thread_id->type = SRV_UM_HASH_STRING;
        thread_id->value = 0;
        thread_id->sim_id = SRV_UM_SIM_UNCLASSIFIED;
        return SRV_UM_RESULT_OK;
    }

    che_init(&che_str, CHE_MD5);
    che_process(&che_str, CHE_MD5, CHE_MODE_NULL, CHE_HASH, (kal_uint8*)ucs2_str,
                (kal_uint8*)hash_array, app_ucs2_strlen((kal_int8*)ucs2_str) * 2, KAL_TRUE);
    che_deinit(&che_str);

    thread_id->type = SRV_UM_HASH_STRING;
    thread_id->value = ((kal_uint64)hash_array[ 0] <<  0) | ((kal_uint64)hash_array[ 1] <<  8) |
                       ((kal_uint64)hash_array[ 2] << 16) | ((kal_uint64)hash_array[ 3] << 24) |
                       ((kal_uint64)hash_array[ 4] << 32) | ((kal_uint64)hash_array[ 5] << 40) |
                       ((kal_uint64)hash_array[ 6] << 48) | ((kal_uint64)hash_array[ 7] << 56) |
                       ((kal_uint64)hash_array[ 8] <<  0) | ((kal_uint64)hash_array[ 9] <<  8) |
                       ((kal_uint64)hash_array[10] << 16) | ((kal_uint64)hash_array[11] << 24) |
                       ((kal_uint64)hash_array[12] << 32) | ((kal_uint64)hash_array[13] << 40) |
                       ((kal_uint64)hash_array[14] << 48) | ((kal_uint64)hash_array[15] << 56);
    thread_id->sim_id = sim_id;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_CACHE_TSFR_ADDRESS_TO_THREAD_ID_4, (U32)((U64)thread_id->value>>32), (U32)thread_id->value);

    return SRV_UM_RESULT_OK;
#else
    return SRV_UM_RESULT_NOT_SUPPORT;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_update_thread_id
 * DESCRIPTION
 *  update the thread_id if the number saved into phonebook
 * PARAMETERS
 *  thread_id        [IN]   the thread_id
 * RETURNS
 *  SRV_UM_RESULT_OK
 *****************************************************************************/
S32 srv_um_update_thread_id(srv_um_thread_id_struct *thread_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_18, (U32)((U64)thread_id->value>>32), (U32)thread_id->value);

#if defined(__SRV_UM_THREAD_MESSAGE_SUPPORT__) && !defined(__SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__)
    if (thread_id->type == SRV_UM_HASH_INTEGER64)
    {
        U8* ascii_str = (U8*)get_ctrl_buffer((MMI_PHB_NUMBER_PLUS_LENGTH + 1) * sizeof(U8));
        U16* ucs2_str = (U16*)get_ctrl_buffer((MMI_PHB_NUMBER_PLUS_LENGTH + 1) * sizeof(U16));
        U16 store_index;

    #ifdef __MTK_TARGET__
        sprintf((char*)ascii_str, "%0*llu", (int)(thread_id->value & 0x0F), thread_id->value >> 4);
    #else
        sprintf((char*)ascii_str, "%0*I64u", (int)(thread_id->value & 0x0F), thread_id->value >> 4);
    #endif

        app_asc_str_to_ucs2_str((kal_int8*)ucs2_str, (kal_int8*)ascii_str);

        if (srv_phb_get_store_index_by_number(ucs2_str, &store_index))
        {
            thread_id->type = SRV_UM_HASH_PHONEBOOK_ID;
            thread_id->value = store_index;
        }

        free_ctrl_buffer(ascii_str);
        free_ctrl_buffer(ucs2_str);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_19, (U32)((U64)thread_id->value>>32), (U32)thread_id->value);

        return SRV_UM_RESULT_OK;
    }

    return SRV_UM_RESULT_OK;

#else
    return SRV_UM_RESULT_NOT_SUPPORT;
#endif
}

#if defined(PLUTO_MMI)
#include "PhoneSetupGprots.h"
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_um_receive_event
 * DESCRIPTION
 *  Receive the event from other service or App.
 *
 * PARAMETERS
 *  event                   [IN]: the message type of selected message
 *  arg                     [IN]: Argument of event
 *
 * RETURNS
 *  Handleing result
 *****************************************************************************/
mmi_ret srv_um_receive_event(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {

    #if defined(PLUTO_MMI)
        case EVT_ID_SETTING_LANGUAGE_CHANGED:
        {
            srv_um_clear_msg_info_cache();
             MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_UM_INTERFACE_FOR_MMI_20);
            break;
        }
    #endif

        default:
        {
            break;
        }
    }

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_um_tsfr_msd_id_to_thread_id
 * DESCRIPTION
 *
 * PARAMETERS
 *  msg_type        [IN]
 * RETURNS
 *
 *****************************************************************************/
S32 srv_um_tsfr_msg_id_to_thread_id(srv_um_msg_enum msg_type, U32 msg_id, srv_um_thread_id_struct *thread_id)
{
#ifdef __SRV_UM_THREAD_MESSAGE_SPLIT_MULTIPLE_ADDRESS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    thread_id->type = SRV_UM_ADDR_MULTIPLE_ADDR;
    thread_id->sim_id = SRV_UM_SIM_UNCLASSIFIED;
    thread_id->value = ((kal_uint64)msg_type << 32) | (kal_uint64)msg_id;

    return SRV_UM_RESULT_OK;

#else
    return SRV_UM_RESULT_NOT_SUPPORT;
#endif
}



