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
 *  DLAgentPush.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Push procedure which splitted from DLAgentSrc.c
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
 *============================================================================
 ****************************************************************************/
 
/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_DOWNLOAD_AGENT__

//#include "ProtocolEvents.h"
#include "app_mine.h"
//#include "FileMgr.h"
//#include "CommonScreens.h"

#include "drm_def.h"                    /* DRM_PROC_RESULT_OK */
//#include "drm_gprot.h"
//#include "RightsMgrGProt.h"

#include "DLAgentSrvDef.h"
#include "DLAgentSrvGprot.h"
#include "DLAgentSrvIProt.h"
#include "DLAgentSrvProt.h"
#ifdef __MMI_DOWNLOAD_AGENT__
#include "mmi_rp_srv_downloadagent_def.h"
#endif

//#include "SimDetectionDef.h"            /* SCR_SIM_INSERTION and SCR_SIM_BLOCK */
#include "IdleGprot.h"
//#include "MessagesResourceData.h"       /* IMG_NEW_MESSAGE_NOTIFICATION_MSG */
//#include "FileManagerGProt.h"           /* GetFileSystemErrorString */
//#include "FileManagerDef.h"
#include "FileMgrSrvGprot.h"
//#include "SettingDefs.h"

//#include "Conversions.h"

#ifdef __USB_IN_NORMAL_MODE__
//#include "ExtDeviceDefs.h"
#endif 
#include "USBDeviceGprot.h"             /* mmi_usb_is_in_mass_storage_mode */
//#include "gpioInc.h"                    /* TurnOnBacklight */




    #include "kal_general_types.h"
    
    #include "mmi_conn_app_trc.h"
    #include "DebugInitDef_Int.h"
    #include "kal_public_api.h"
    #include "app_ltlcom.h"
    #include "mmi_frm_mem_gprot.h"
    #include "string.h"
    #include "MMI_conn_app_trc.h"
    #include "kal_trace.h"
    #include "Unicodexdcl.h"
    #include "app_str.h"
    #include "mmi_res_range_def.h"
    #include "fs_func.h"
    #include "CustDataRes.h"
    #include "mmi_frm_events_gprot.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "mmi_rp_srv_downloadagent_def.h"
    #include "NotificationGprot.h"
    #include "GlobalResDef.h"
    #include "mmi_frm_history_gprot.h"
    #include "drm_errcode.h"
    #include "fs_type.h"
    #include "fs_errcode.h"
    #include "wgui_categories_util.h"
    #include "wgui.h"
    #include "AlertScreen.h"
    #include "CommonScreensResDef.h"
    #include "wgui_categories.h"
#ifndef __COSMOS_MMI_PACKAGE__
    #include "mmi_rp_app_sms_def.h"
#endif
    #include "GlobalConstants.h"
    #include "stack_msgs.h"
    #include "wgui_categories_list.h"
/****************************************************************************
 * Configurations
 ****************************************************************************/
 
/*
 * Number of pushes which confirm_push == MMI_TRUE can wait in queue.
 * These items need user's confirmation to decide next step.
 */
#define SRV_DA_MAX_PUSHES_IN_QUEUE_NUM          8

/*
 * Number of pushes which can be processed concurrently.
 * NOTE: Please also note that the max # of instances of select-storage
 *       should be more than this value.
 */
#define SRV_DA_MAX_PUSHES_IN_PROCESSING_NUM     4


/****************************************************************************
 * [Trace Utility]
 ****************************************************************************/


#define SRV_DA_PUSH_TRACE_BASE(trace_item, v1, v2, v3) \
    MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_PUSH_FUNC, (S32)trace_item, (S32)srv_da_push_get_number_of_processing_items(), v1, v2, v3)

#define SRV_DA_PUSH_TRACE(func)               SRV_DA_PUSH_TRACE_BASE(PUSH_TRACE_##func, 0, 0, 0)
#define SRV_DA_PUSH_TRACE_1(func, v1)         SRV_DA_PUSH_TRACE_BASE(PUSH_TRACE_##func, (S32)(v1), 0, 0)
#define SRV_DA_PUSH_TRACE_2(func, v1, v2)     SRV_DA_PUSH_TRACE_BASE(PUSH_TRACE_##func, (S32)(v1), (S32)(v2), 0)
#define SRV_DA_PUSH_TRACE_3(func, v1, v2, v3) SRV_DA_PUSH_TRACE_BASE(PUSH_TRACE_##func, (S32)(v1), (S32)(v2), (S32)(v3))


void srv_da_push_process_item(srv_da_push_item_struct *item, srv_da_setting_struct *setting);
void srv_da_push_free_item(srv_da_push_item_struct *item);
/****************************************************************************
 * [Code body]
 ****************************************************************************/



typedef struct
{
    srv_da_push_item_struct *item_in_notifying;

    srv_da_push_item_element_struct reserved_for_item_elements[SRV_DA_PUSH_MAX_PUSH_ITEM_ELEMENT_NUM];
    srv_da_push_item_element_struct *free_item_elements;

    /* Item queued, which all setting.confirm_push == MMI_TRUE, waiting for user's confirmation when enter Idle */
    srv_da_push_item_list_struct to_be_confirmed;
    
    /* Items in processing, either in foreground or background */
    srv_da_push_item_list_struct processing;
    
    /* The item stack used for dispatch confirm screen */
    srv_da_push_item_list_struct screen_stack;
} srv_da_push_context_struct;



/****************************************************************************
 * Global Variables
 ****************************************************************************/

static srv_da_push_context_struct g_srv_da_push_context;


/****************************************************************************
 * Private Functions
 ****************************************************************************/



/*****************************************************************************
 * FUNCTION
 *  srv_da_push_allocate_item_element
 * DESCRIPTION
 *  Allocate an item element from pool
 * PARAMETERS
 *  void
 * RETURNS
 *  Free element
 *****************************************************************************/
static srv_da_push_item_element_struct *srv_da_push_allocate_item_element(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_element_struct *element;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    element = g_srv_da_push_context.free_item_elements;

    /* If insufficient of elements, please increase SRV_DA_PUSH_MAX_PUSH_ITEM_ELEMENT_NUM */
    MMI_ASSERT(element != NULL);
    
    g_srv_da_push_context.free_item_elements = element->next;

    return element;
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_free_item_element
 * DESCRIPTION
 *  Free an item element.
 * PARAMETERS
 *  element_p   [IN] Pointer of the element
 * RETURNS
 *  void
 *****************************************************************************/
#define srv_da_push_free_item_element(element_p) \
    do { \
        (element_p)->next = g_srv_da_push_context.free_item_elements; \
        g_srv_da_push_context.free_item_elements = (element_p); \
    } while (0)


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_init_item_elements_pool
 * DESCRIPTION
 *  Initialize element pool. Before allocate item elements, the pool should be
 *  initialized first.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_push_init_item_elements_pool(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_da_push_item_element_struct *element;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    element = g_srv_da_push_context.reserved_for_item_elements;

    g_srv_da_push_context.free_item_elements = NULL;
    for (i = SRV_DA_PUSH_MAX_PUSH_ITEM_ELEMENT_NUM; i != 0; i--)
    {
        srv_da_push_free_item_element(element);
        element++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_init_list
 * DESCRIPTION
 *  Initialize an item list
 * PARAMETERS
 *  list_p      [IN/OUT] srv_da_push_item_list_struct*
 * RETURNS
 *  void
 *****************************************************************************/
#define srv_da_push_init_list(list_p) \
    do { \
        (list_p)->head = NULL; \
        (list_p)->number = 0;  \
    } while(0)


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_get_head_item
 * DESCRIPTION
 *  Get head(front) item of the list.
 * PARAMETERS
 *  list        [IN] List
 * RETURNS
 *  Head item
 *****************************************************************************/
srv_da_push_item_struct* srv_da_push_get_head_item(srv_da_push_item_list_struct *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list->head != NULL)
    {
        return list->head->item;
    }

    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  srv_da_push_get_top_screen_stack_item
 * DESCRIPTION
 *  Get head(front) item of the list.
 * PARAMETERS
 *  list        [IN] List
 * RETURNS
 *  Head item
 *****************************************************************************/
srv_da_push_item_struct* srv_da_push_get_top_screen_stack_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_da_push_get_head_item(&(g_srv_da_push_context.to_be_confirmed));
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_get_head_item
 * DESCRIPTION
 *  Get head(front) item of the list.
 * PARAMETERS
 *  list        [IN] List
 * RETURNS
 *  Head item
 *****************************************************************************/
void srv_da_push_remove_item_processed(srv_da_push_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_da_push_remove_from_list(&(g_srv_da_push_context.to_be_confirmed), item);
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_append_to_list
 * DESCRIPTION
 *  Append an item to the list; that is, put the item at list tail.
 * PARAMETERS
 *  list    [IN/OUT] List
 *  item    [IN]     Item to be append
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_push_append_to_list(srv_da_push_item_list_struct *list, srv_da_push_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_element_struct *prev;
    srv_da_push_item_element_struct *element;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check whether the item already exists */
    prev = NULL;
    for (element = list->head; element != NULL; element = element->next)
    {
        if (element->item == item)
        {
            /* item already exists */
            return;
        }
    
        prev = element;
    }

    element = srv_da_push_allocate_item_element();
    element->item = item;
    element->next = NULL;

    if (prev != NULL)
    {
        prev->next = element;
    }
    else
    {
        list->head = element;
    }
    
    list->number++;
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_prepend_to_list
 * DESCRIPTION
 *  Prepend an item to the list; that is, insert the item on the list front.
 * PARAMETERS
 *  list    [IN/OUT] List
 *  item    [IN]     Item to be append
 * RETURNS
 *  void
 *****************************************************************************/
void srv_da_push_prepend_to_list(srv_da_push_item_list_struct *list, srv_da_push_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_element_struct *prev;
    srv_da_push_item_element_struct *element;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check whether the item already exists */
    prev = NULL;
    for (element = list->head; element != NULL; element = element->next)
    {
        if (element->item == item)
        {
            /* Remove from list first, we will move it to the front */
            if (list->head == element)
            {
                list->head = element->next;
            }
            else
            {
                prev->next = element->next;
            }
            break;
        }

        prev = element;
    }

    if (element == NULL)
    {
        element = srv_da_push_allocate_item_element();
        list->number++;
    }
    
    element->item = item;
    element->next = list->head;
    list->head = element;
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_remove_from_list
 * DESCRIPTION
 *  Remove an item from list. If the item is not found in the list, nothing
 *  will be done.
 * PARAMETERS
 *  list    [IN/OUT] List
 *  item    [IN]     Item to be removed
 * RETURNS
 *  void
 *****************************************************************************/
void srv_da_push_remove_from_list(srv_da_push_item_list_struct *list, srv_da_push_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_element_struct *prev;
    srv_da_push_item_element_struct *element;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check whether the item already exists */
    prev = NULL;
    for (element = list->head; element != NULL; element = element->next)
    {
        if (element->item == item)
        {
            break;
        }
    
        prev = element;
    }

    if (element == NULL)
    {
        return;
    }

    if (list->head == element)
    {
        list->head = element->next;
    }
    else
    {
        prev->next = element->next;
    }

    list->number--;

    srv_da_push_free_item_element(element);
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_is_item_in_list
 * DESCRIPTION
 *  To check whether an item is in the list or not.
 * PARAMETERS
 *  list    [IN] List
 *  item    [IN] Item to be checked
 * RETURNS
 *  MMI_TRUE if in the list
 *****************************************************************************/
MMI_BOOL srv_da_push_is_item_in_list(srv_da_push_item_list_struct *list, srv_da_push_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_element_struct *element;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (element = list->head; element != NULL; element = element->next)
    {
        if (element->item == item)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_get_item_by_id
 * DESCRIPTION
 *  Get the item in the list which its unique_id matches
 * PARAMETERS
 *  list        [IN] List
 *  unique_id   [IN] Unique ID
 * RETURNS
 *  The item, NULL if not found.
 *****************************************************************************/
srv_da_push_item_struct* srv_da_push_get_item_by_id(srv_da_push_item_list_struct *list, U16 unique_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_element_struct *element;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (element = list->head; element != NULL; element = element->next)
    {
        if (element->item->unique_id == unique_id)
        {
            return element->item;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_get_new_unique_id
 * DESCRIPTION
 *  Allocate a unique ID
 * PARAMETERS
 *  void
 * RETURNS
 *  An unique ID
 *****************************************************************************/
static U16 srv_da_push_get_new_unique_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U16 next_id = 0;
    U16 return_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return_id = next_id;
    next_id = (next_id + 1) & 0x7fff;

    return return_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_parse_dispatch_request
 * DESCRIPTION
 *  New a push item from DISPATCH_FILE_REQ.
 * PARAMETERS
 *  msg             [IN] mmi_da_dispatch_file_req_struct*
 *  peer_buff_ptr   [IN] Peer buffer
 * RETURNS
 *  Push item; this item is allocated by OslMalloc()
 *****************************************************************************/
static srv_da_push_item_struct* srv_da_push_parse_dispatch_request(mmi_da_dispatch_file_req_struct* msg,
                                                              peer_buff_struct *peer_buff_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_struct *item;
    S8                      *mime_str;
    U16                     *ext;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    item = (srv_da_push_item_struct *)srv_da_adp_mem_allocate(sizeof(srv_da_push_item_struct));
    memset(item, 0, sizeof(srv_da_push_item_struct));

    item->unique_id = srv_da_push_get_new_unique_id();

    mime_str = NULL;
    if(msg->mime_type_string[0])
        mime_str = msg->mime_type_string;

    ext = srv_da_util_get_extension(msg->filename);
    if(!ext)
        ext = srv_da_util_get_extension(msg->filepath);

    item->mime_type = srv_da_util_lookup_mime_type((U8*)mime_str, ext, (applib_mime_type_enum)msg->mime_type, (applib_mime_subtype_enum)msg->mime_subtype);

    // special case
    if (msg->mime_type == MIME_TYPE_UNKNOWN &&
        msg->mime_subtype == MIME_SUBTYPE_UNRECOGNIZED)
    {
        item->mime_type = NULL;
    }

    MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_MIMETYPE, (item->mime_type != NULL ? item->mime_type->mime_subtype : 0));

    item->type_handler = srv_da_search_mime_type_handler(item->mime_type);

    UCS2_STR_MALLOC_COPY(item->filepath, msg->filepath);
    UCS2_STR_MALLOC_COPY(item->filename, msg->filename);
    
    ANSI_STR_MALLOC_COPY(item->mime_type_string, msg->mime_type_string, sizeof(msg->mime_type_string));
    ANSI_STR_MALLOC_COPY(item->url, msg->url, sizeof(msg->url));

    item->file_length = srv_da_util_get_file_size(item->filepath);

    item->action = msg->action;

    /* header */
    item->header_len = 0;
    item->header = NULL;

    if (peer_buff_ptr)
    {
        kal_uint16 len;
        mmi_da_dispatch_file_var_struct *buffer = (mmi_da_dispatch_file_var_struct *) get_pdu_ptr(peer_buff_ptr, &len);

        if( buffer->header_len > 0 )
        {
            item->header_len = buffer->header_len;
            item->header = (S8*)get_ctrl_buffer(buffer->header_len+1);
            memset(item->header, 0, buffer->header_len+1);
            memcpy(item->header, buffer->header, buffer->header_len);
        }

    }

    if (msg->ui_setting.title_icon_id != 0)
    {
        memcpy(&(item->ui), &(msg->ui_setting), sizeof(srv_da_ui_setting_struct));
    }
    else
    {
        item->ui.title_string_id = 0;
        
        if (item->url && strncmp(item->url, "mms", 3) == 0)
        {
            item->ui.title_icon_id = srv_da_util_get_icon_from_appid(APP_MESSAGES);
        }
        else
        {
            item->ui.title_icon_id = srv_da_util_get_icon_from_appid(APP_WAP);
        }
    }

    if (msg->extra_info.size > 0 && msg->extra_info.size <= SRV_DA_MAX_EXTRA_INFO_DATA_SIZE)
    {
        item->extra_info = (srv_da_extra_info_struct*)srv_da_adp_mem_allocate(sizeof(srv_da_extra_info_struct));
        memcpy(item->extra_info, &(msg->extra_info), sizeof(srv_da_extra_info_struct));
    }
    else
    {
        item->extra_info = NULL;
    }
    
    return item;
}


/*****************************************************************************
* FUNCTION
* DESCRIPTION
* PARAMETERS
* RETURNS
*****************************************************************************/
void srv_da_push_recv_dispatch_file_req(void *MsgStruct, int mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_dispatch_file_req_struct *msg;
    ilm_struct                      *mmi_ilm_ptr = (ilm_struct*) ilm_p;
    MMI_BOOL                        can_popup;
    srv_da_push_item_struct         *item;
    srv_da_setting_struct           *setting;
    U32                             n_to_be_notified, n_processing, n_screen_stack;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg = (mmi_da_dispatch_file_req_struct*) MsgStruct;

    MMI_ASSERT(msg);
    MMI_ASSERT(msg->action == MMI_DA_PUSH || msg->action == MMI_DA_PUSH_SIM2 || msg->action == MMI_DA_SAVE_AS || msg->action == MMI_DA_PUSH_SIM3 || msg->action == MMI_DA_PUSH_SIM4);
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	n_to_be_notified = g_srv_da_push_context.to_be_confirmed.number;
    n_processing = g_srv_da_push_context.processing.number;
    n_screen_stack = g_srv_da_push_context.screen_stack.number;
    
    SRV_DA_PUSH_TRACE_3(srv_da_push_recv_dispatch_file_req, n_to_be_notified, n_processing, n_screen_stack);

    can_popup = MMI_TRUE;

#ifdef __USB_IN_NORMAL_MODE__
    /* check is in mass storage mode */
    if(srv_usb_is_in_mass_storage_mode())
    {
        /* phone drive is exported, cant use this app */
        can_popup = MMI_FALSE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    if(!srv_da_is_popup_allowed())
    {
        can_popup = MMI_FALSE;
    }
    
    if(msg->action == MMI_DA_SAVE_AS && !can_popup)
    {
        DA_TRACE_FUNC1(srv_da_push_recv_dispatch_file_req, 0xFF);

        FS_Delete(msg->filepath);
        
#ifdef __USB_IN_NORMAL_MODE__
        if(srv_usb_is_in_mass_storage_mode())
        {
            mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        }
#endif

        return;
    }

    /* parse content */
    item = srv_da_push_parse_dispatch_request(msg, mmi_ilm_ptr->peer_buff_ptr);

    item->is_normal_save = MMI_FALSE;
    item->user_selected_storage = MMI_FALSE;

    /* retrieve setting */
    setting = srv_da_get_setting_buffer();
    MMI_ASSERT(item->type_handler->setting_hdlr != NULL);
    item->type_handler->setting_hdlr(
            SRV_DA_PUSH_ID(item),
            item->mime_type ? item->mime_type->mime_type: 0,
            item->mime_type ? item->mime_type->mime_subtype: 0,
            item->action,
            item->file_length,
            item->url,
            item->mime_type_string,
            0, NULL,
            setting);

    MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_SETTING, setting->storage, (char)setting->drv,
        setting->confirm_push, setting->confirm_dispatch, setting->do_dispatch);

    if((item->action == MMI_DA_PUSH || item->action == MMI_DA_PUSH_SIM2 || item->action == MMI_DA_PUSH_SIM3 || item->action == MMI_DA_PUSH_SIM4) && setting->confirm_push == MMI_TRUE)
    {
        if(n_to_be_notified < SRV_DA_MAX_PUSHES_IN_QUEUE_NUM)
        {
            /* Put into queue, to be confirmed when go back to Idle */
			mmi_event_struct evt;
            srv_da_push_append_to_list(&(g_srv_da_push_context.to_be_confirmed), item);
            /* If already in Idle screen, this will cause entey Idle screen */
#ifndef MMI_DA_PLUTO_SLIM            
            srv_da_adp_show_ncenter (item, SRV_DA_JOB_TYPE_PUSH);
#endif
            //TODO check for cosmos
#ifndef __COSMOS_MMI_PACKAGE__
#ifndef __MMI_NCENTER_SUPPORT__
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_DLA_SRV_SHOW_NMGR_POPUP);
			MMI_FRM_CB_EMIT_EVENT(&evt);
#endif
#endif //
            //mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO, (WCHAR *)GetString(STR_ID_DA_NEW_PUSH)); //Commented for cosmos only
        }
        else
        {
            srv_da_push_free_item(item);
        }

        return;
    }

    srv_da_push_process_item(item, setting);
}



/*****************************************************************************
 * FUNCTION
 *  srv_da_push_dispatch
 * DESCRIPTION
 *  Try to dispatch the push item. After dispatched, the item will be freed.
 * PARAMETERS
 *  item        [IN] Push item
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_push_dispatch(srv_da_push_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_setting_struct           *setting;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    setting = srv_da_get_setting_buffer();
    
    MMI_ASSERT(item->type_handler->setting_hdlr);
    item->type_handler->setting_hdlr(
            SRV_DA_PUSH_ID(item),
            item->mime_type ? item->mime_type->mime_type: 0,
            item->mime_type ? item->mime_type->mime_subtype: 0,
            item->action,
            item->file_length,
            item->url,
            item->mime_type_string,
            0,
            NULL,
            setting);

    if (setting->do_dispatch &&
        item->type_handler->dispatch_hdlr == srv_da_get_default_mime_type_handler()->dispatch_hdlr)
    {
        if (!srv_da_util_is_supported_by_fmgr(item->filepath))
        {
            setting->do_dispatch = MMI_FALSE;
        }
    }

    if (!setting->do_dispatch || 
        !item->type_handler->dispatch_hdlr || 
        (setting->confirm_dispatch && !srv_da_is_new_screen_allowed()))
    {
        if (item->user_selected_storage ||
            srv_da_get_max_number_of_drives() <= 1)
        {
            srv_da_adp_popup(SRV_DA_GLOBAL_SAVED, 0, SRV_DA_POPUP_TYPE_SAVED);
        }
        else
        {
            if (item->filepath[0] == SRV_FMGR_PHONE_DRV)
            {
                srv_da_adp_popup(SRV_DA_GLOBAL_SAVED_TO_PHONE, 0, SRV_DA_POPUP_TYPE_SAVED);
            }
            else
            {
                srv_da_adp_popup(SRV_DA_SAVED_TO_CARD, 0, SRV_DA_POPUP_TYPE_SAVED);
            }
        }

        srv_da_push_free_item(item);

        return;
    }

    if (item->type_handler->dispatch_hdlr)
    {
        if (item->mime_type)
        {
            srv_da_dispatch_to_app(
                SRV_DA_PUSH_ID(item),
                item->mime_type,
                item->action,
                item->filepath,
                item->url,
                item->mime_type_string,
                item->type_handler);
        }
        else
        {
            if (item->filepath[0] == SRV_FMGR_PHONE_DRV)
            {
                srv_da_adp_popup(SRV_DA_GLOBAL_SAVED_TO_PHONE, 0, SRV_DA_POPUP_TYPE_SAVED);
            }
            else
            {
                srv_da_adp_popup(SRV_DA_SAVED_TO_CARD, 0, SRV_DA_POPUP_TYPE_SAVED);
            }
        }

        if ((item->action == MMI_DA_PUSH || item->action == MMI_DA_PUSH_SIM2 || item->action == MMI_DA_PUSH_SIM3 || item->action == MMI_DA_PUSH_SIM4) &&
            setting->storage == SRV_DA_STORAGE_PUSH_TEMP &&
            srv_da_util_does_file_exist(item->filepath))
        {
            MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_PUSH_TEMP_WARNING, (U32)(item->type_handler->dispatch_hdlr));
        }
        
        srv_da_push_free_item(item);
    }
    else
    {
        srv_da_push_free_item(item);
    }
}





#ifdef __DRM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_drm_process_to_process_item
 * DESCRIPTION
 *  Process the DRM-processed item again according to the new MIME type.
 * PARAMETERS
 *  arg        [IN] srv_da_push_item_struct*
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_push_drm_process_to_process_item(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_struct *item;
    srv_da_setting_struct *setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item = (srv_da_push_item_struct*)arg;

    /* After DRM processing, we let it go through normal push processing prodecure as normal MIME type */
 #ifndef __COSMOS_MMI_PACKAGE__ 
    #ifndef MMI_DA_PLUTO_SLIM
    srv_da_adp_scr_progressing_close(SRV_DA_ACTION_SCR_DRM_PROCESSING);

#endif
#endif

    /* retrieve setting */
    setting = srv_da_get_setting_buffer();
    
    item->type_handler->setting_hdlr(
            SRV_DA_PUSH_ID(item),
            (item->mime_type != NULL ? item->mime_type->mime_type : 0),
            (item->mime_type != NULL ? item->mime_type->mime_subtype : 0),
            item->action,
            item->file_length,
            item->url,
            item->mime_type_string,
            0,
            NULL,
            setting);

    MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_SETTING, setting->storage, (char)setting->drv,
        setting->confirm_push, setting->confirm_dispatch, setting->do_dispatch);

    srv_da_push_process_item(item, setting);
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_drm_process_callback
 * DESCRIPTION
 *  Callback function for DRM processing result.
 * PARAMETERS
 *  arg             [IN] mmi_da_job_struct*
 *  result          [IN] Processing result
 *  new_filepath    [IN] The filepath of processing result(output), it may be
 *                       the same to original path.
 *  method          [IN] DRM method
 *  is_archive      [IN] archive
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_push_drm_process_callback(
    void *arg,
    S32 result,
    const U16 *new_filepath,
    const applib_mime_type_struct *new_mime_type,
    drm_method_enum method,
    const srv_da_drm_result_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item = (srv_da_push_item_struct*)arg;
    
    if (!srv_da_push_is_item_in_list(&(g_srv_da_push_context.processing), item))
    {
        /* The item has already been freed or not in processing */
        return;
    }

    item->drm_process_session = NULL;
    
    if (result == DRM_RESULT_OK)
    {
        if (srv_da_is_drm_right(item->mime_type) || srv_da_is_drm_roap(item->mime_type))
        {
            if (!srv_da_is_drm_content(item->mime_type))
            {
                 srv_da_drm_show_process_info(result, item->mime_type, info, item->action);
            }

            srv_da_util_file_delete(item->filepath);
            srv_da_util_file_delete(new_filepath);
        }
        else
        {
            if (mmi_wcsicmp(item->filepath, new_filepath) != 0)
            {
                srv_da_util_file_delete(item->filepath); /* Delete the file before processing */

                /* Use original filepath first to keep the file name.
                   The file extension name will be corrected when the item is processed again */
                if (srv_da_util_file_move(new_filepath, item->filepath, FS_MOVE_KILL) != FS_NO_ERROR)
                {
                    /* Failed to use original filepath, use the new filepath directly */
                    OslMfree(item->filepath);
                    item->filepath = (U16*)srv_da_adp_mem_allocate((mmi_wcslen(new_filepath) + 1) * sizeof(U16));
                    mmi_wcscpy(item->filepath, new_filepath);
                }
            }

            if (info->is_archive)
            {
                item->is_normal_save = MMI_TRUE;
                item->type_handler = srv_da_get_default_mime_type_handler();
            }
            else
            {
                /* new mime_type will prevent DRM processing again */
                item->mime_type = new_mime_type;
                item->is_normal_save = MMI_FALSE;
                item->type_handler = srv_da_search_mime_type_handler(item->mime_type);
            }
            
            item->file_length = srv_da_util_get_file_size(item->filepath);
            item->drm_method = DRM_METHOD_NONE;

            /* Even if mime_type == NULL, there will be always a type handler (default handler) */
            MMI_ASSERT(item->type_handler != NULL && item->type_handler->setting_hdlr != NULL);

            srv_da_push_drm_process_to_process_item(item);
            return;
        }
    }
    else
    {
        srv_da_drm_show_process_info(result, item->mime_type, info, item->action);

        srv_da_util_file_delete(item->filepath);
    }

 #ifndef __COSMOS_MMI_PACKAGE__ 
#ifndef MMI_DA_PLUTO_SLIM
	srv_da_adp_scr_progressing_close(SRV_DA_ACTION_SCR_DRM_PROCESSING);
#endif
#endif
    srv_da_push_free_item(item);
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_drm_cancel_on_screen_deleted
 * DESCRIPTION
 *  Cancel the DRM processing if the processing screen is deleted.
 * PARAMETERS
 *  arg         [IN] Push item
 *  is_deleting [IN] Is in deleting context. This argument should be MMI_TRUE
 *                   because we don't provide cancel function on the screen.
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_push_drm_cancel_on_screen_deleted(void *arg, MMI_BOOL is_deleting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item = (srv_da_push_item_struct*)arg;

    if (!srv_da_push_is_item_in_list(&(g_srv_da_push_context.processing), item))
    {
        /* The item has already been freed */
        return;
    }

    /* The screen deletion may be triggered after the result arrived in the queue */
    if (item->drm_process_session != NULL)
    {
        srv_da_drm_process_cancel(item->drm_process_session);
        item->drm_process_session = NULL;
    }

    if (item->filepath != NULL)
    {
        srv_da_util_file_delete(item->filepath);
    }

    srv_da_push_free_item(item);
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_drm_process
 * DESCRIPTION
 *  DRM-process the item.
 * PARAMETERS
 *  item        [IN] Push item.
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_push_drm_process(srv_da_push_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL need_to_wait;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item->drm_process_session = srv_da_drm_process(
        item->filepath,
        item->mime_type,
        &need_to_wait,
        item,
        srv_da_push_drm_process_callback);

    if (item->drm_process_session != NULL && need_to_wait)
    {
        if ((item->action == MMI_DA_PUSH || item->action == MMI_DA_PUSH_SIM2 || item->action == MMI_DA_PUSH_SIM3 || item->action == MMI_DA_PUSH_SIM4)
            && (srv_da_is_drm_right(item->mime_type) || srv_da_is_drm_roap(item->mime_type)))
        {
            /* For rights push, we don't show processing screen but the final popup. */
        }
        else
        {
#ifndef MMI_DA_PLUTO_SLIM
#ifndef __COSMOS_MMI_PACKAGE__ 
            srv_da_adp_show_progressing(
                SRV_DA_ACTION_SCR_DRM_PROCESSING,
                SRV_DA_DRM_PROCESSING,
                item->ui.title_icon_id,
                SRV_DA_PLEASE_WAIT,
                MMI_FALSE,
                item,
                srv_da_push_drm_cancel_on_screen_deleted);
#endif 
#endif
        }
    }
    else
    {
        /* If no need to wait, it will call the callback function directly */
        /* Whatever the case is, the callback function will be called finally. */
    }
}

#endif /* __DRM_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_save_as_after_saved
 * DESCRIPTION
 *  After file is saved, dispatch it or do DRM processing.
 * PARAMETERS
 *  arg             [IN] srv_da_push_item_struct*
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_push_save_as_after_saved(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_struct *item;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    item = (srv_da_push_item_struct*)arg;

#ifdef __DRM_SUPPORT__
    /* parse DRM type first */
    if(!item->is_normal_save && srv_da_is_drm_require_processing(item->mime_type))
    {
        srv_da_push_drm_process(item);
    }
    else
#endif
    {
        srv_da_push_dispatch(item); // Not require for venus may be we can uncomment for Pluto
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_da_push_async_save_as_result_callback
 * DESCRIPTION
 *  Result callback function for asynchronous moving for save-as.
 * PARAMETERS
 *  arg             [IN] mmi_da_push_async_move_arg_struct*
 *  error_code      [IN] FS error code
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_push_async_save_as_result_callback(void *arg, S32 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_async_move_arg_struct *async_move_arg;
    srv_da_push_item_struct *item;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    async_move_arg = (srv_da_push_async_move_arg_struct*)arg;
#ifndef __COSMOS_MMI_PACKAGE__ 
#ifndef MMI_DA_PLUTO_SLIM
	srv_da_adp_scr_progressing_close(SRV_DA_ACTION_SCR_PUSH_MOVING);

#endif
#endif

    if (srv_da_push_get_item_by_id(&(g_srv_da_push_context.processing), async_move_arg->unique_id) == NULL)
    {
        /* The item has been removed */
        /* We don't need to free async_mov_arg->item */
        if (async_move_arg)
        {
            OslMfree(async_move_arg->dest_path);
            OslMfree(async_move_arg);
            async_move_arg = NULL;
        }
        return;
    }
    
    item = async_move_arg->item;
    srv_da_adp_handle_push_move(async_move_arg, error_code);
    if (error_code != FS_NO_ERROR)
    {
        srv_da_adp_popup(0, error_code, SRV_DA_POPUP_TYPE_FS_ERROR);
        srv_da_util_file_delete(item->filepath);
        srv_da_push_free_item(item);
    }
    else
    {
        UCS2_STR_MALLOC_COPY(item->filepath, async_move_arg->dest_path);
        srv_da_push_save_as_after_saved(item);
    }

    if (async_move_arg)
    {
        OslMfree(async_move_arg->dest_path);
        OslMfree(async_move_arg);
        async_move_arg = NULL;
    }
}

#ifndef __COSMOS_MMI_PACKAGE__ 
/*****************************************************************************
 * FUNCTION
 *  srv_da_push_async_save_as_cancel_callback
 * DESCRIPTION
 *  Cancel callback of asynchronous moving for save-as
 * PARAMETERS
 *  arg             [IN] mmi_da_push_async_move_arg_struct*
 *  is_deleted      [IN] In delete callback context
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_push_async_save_as_cancel_callback(void *arg, MMI_BOOL is_deleted)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_async_move_arg_struct *async_move_arg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_da_util_cancel_async_move();
    async_move_arg = (srv_da_push_async_move_arg_struct*)arg;
    
    if (srv_da_push_get_item_by_id(&(g_srv_da_push_context.processing), async_move_arg->unique_id) != NULL)
    {
        srv_da_push_free_item(async_move_arg->item);
    }

    if (async_move_arg)
    {
        OslMfree(async_move_arg->dest_path);
        OslMfree(async_move_arg);
        async_move_arg = NULL;
    }
}
#endif



/*****************************************************************************
 * FUNCTION
 *  mmi_da_push_filename_done
 * DESCRIPTION
 *  Result of select-storage to save push file
 * PARAMETERS
 *  criteria        [IN] (srv_da_push_item_struct*)Push item
 *  filepath        [IN] The filepath user selected, NULL if not selected
 *  canback         [IN] Can reject the selection
 *  canpopup        [IN] Popup is allowed
 *  instance        [IN] Instance of select-storage
 * RETURNS
 *  Acceptance
 *****************************************************************************/
srv_da_acceptance_enum srv_da_push_filename_done(
                                U32 criteria,
                                U16* filepath,
                                MMI_BOOL canback,
                                MMI_BOOL canpopup,
                                void *instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_struct     *item;
	S32                         result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DA_TRACE_FUNC(mmi_da_push_filename_done);

    item = (srv_da_push_item_struct*)criteria;
    
    if (filepath == NULL)
    {
        if (srv_da_util_does_file_exist(item->filepath))
        {
            srv_da_util_file_delete(item->filepath);
        }
        if (canpopup)
        {
            srv_da_adp_popup(SRV_DA_UNABLE_TO_SAVE_FILE, 0, SRV_DA_POPUP_TYPE_ERROR);
        }
    
        srv_da_push_free_item(item);
        return SRV_DA_ACCEPTANCE_ACCEPT;
    }
/*
    if (instance != NULL)
    {
        item->user_selected_storage = mmi_da_scr_user_selected_storage(instance);
    }
*/
    /* save it to new filepath*/
    if (mmi_wcsicmp(filepath, item->filepath) != 0)
    {
        if (item->action == MMI_DA_SAVE_AS)
        {
            if (item->filepath[0] == filepath[0]) /* The same drive */
            {
                int fs_error;

                fs_error = srv_da_util_file_move(item->filepath, filepath, FS_MOVE_KILL);

                if (fs_error == FS_NO_ERROR)
                {
                    UCS2_STR_MALLOC_COPY(item->filepath, filepath);
                
                    srv_da_push_save_as_after_saved (item);
                
                    return SRV_DA_ACCEPTANCE_ACCEPT;
                }
                else
                {
                    srv_da_adp_popup(0, fs_error, SRV_DA_POPUP_TYPE_FS_ERROR);

                    if (srv_da_util_does_file_exist(item->filepath))
                    {
                        srv_da_util_file_delete(item->filepath);
                    }
                    srv_da_push_free_item(item);
                    return SRV_DA_ACCEPTANCE_ACCEPT;
                }
            }
            else
            {
                srv_da_push_async_move_arg_struct *async_move_arg;
                async_move_arg = (srv_da_push_async_move_arg_struct*)srv_da_adp_mem_allocate(sizeof(srv_da_push_async_move_arg_struct));
                async_move_arg->unique_id = item->unique_id;
                async_move_arg->dest_path = (U16*)srv_da_adp_mem_allocate((mmi_wcslen(filepath) + 1) * sizeof(U16));
                mmi_wcscpy(async_move_arg->dest_path, filepath);
                async_move_arg->item = item;
                async_move_arg->select_storage_instance = instance;
                async_move_arg->can_reject = canback;
#ifndef MMI_DA_PLUTO_SLIM
 #ifndef __COSMOS_MMI_PACKAGE__ 
                srv_da_adp_show_progressing(
                    SRV_DA_ACTION_SCR_PUSH_MOVING,
                    0,
                    0,
                    SRV_DA_GLOBAL_SAVING,
                    MMI_TRUE,
                    NULL,
                    srv_da_push_async_save_as_cancel_callback);
#endif
#endif
                srv_da_util_async_move(
                    item->filepath,
                    filepath,
                    async_move_arg,
                    srv_da_push_async_save_as_result_callback);
                return SRV_DA_ACCEPTANCE_ASYNC;
            }
        }
        else
        {
            /* Prevent Read Only */
            result = FS_Move(item->filepath, filepath, FS_MOVE_KILL | FS_MOVE_OVERWRITE, NULL, NULL, 0);
            
            if (result < 0)
            {
                srv_da_adp_popup(0, result, SRV_DA_POPUP_TYPE_FS_ERROR);
                //mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE, (WCHAR *)GetString(srv_fmgr_fs_error_get_string(result)));

                if (srv_da_util_does_file_exist(item->filepath))
                {
                    srv_da_util_file_delete(item->filepath);
                    srv_da_push_free_item(item);
                }
                return SRV_DA_ACCEPTANCE_ACCEPT;
            }
            UCS2_STR_MALLOC_COPY(item->filepath, filepath);
            DA_FREE_BUFFER(item->filename);
        }
    }
    
    srv_da_push_save_as_after_saved(item);

    return SRV_DA_ACCEPTANCE_ACCEPT;
}


void srv_da_push_get_dir (void* arg, U16 *dir)
{
    srv_da_setting_struct  *setting = NULL;
	srv_da_push_item_struct     *item;
	item = (srv_da_push_item_struct*)arg;

	if ((item->action != MMI_DA_SAVE_AS)
		&& (item->action != MMI_DA_PUSH)
		&& (item->action != MMI_DA_PUSH_SIM2)
        && (item->action != MMI_DA_PUSH_SIM3)
        && (item->action != MMI_DA_PUSH_SIM4))
	{
		MMI_ASSERT(0);
	}

    setting = srv_da_get_setting_buffer();
    MMI_ASSERT(item->type_handler->setting_hdlr);
    item->type_handler->setting_hdlr(
            SRV_DA_PUSH_ID(item),
            item->mime_type ? item->mime_type->mime_type: 0,
            item->mime_type ? item->mime_type->mime_subtype: 0,
            item->action,
            item->file_length,
            item->url,
            item->mime_type_string,
            0, NULL,
            setting);

	mmi_wcscpy(dir, setting->folder);
}


U32 srv_da_push_get_download_size (void *arg)
{
    srv_da_push_item_struct     *item;
    item = (srv_da_push_item_struct*)arg;

    if (item)
    {
        return srv_da_util_get_file_size (item->filepath);
    }
    return 0;
}


void srv_da_push_get_filename (void* arg, U16 *temp_filename, U16 *ext)
{
	srv_da_push_item_struct     *item;
    U16                         *filename = NULL;
	item = (srv_da_push_item_struct*)arg;

	if ((item->action != MMI_DA_SAVE_AS)
		&& (item->action != MMI_DA_PUSH)
		&& (item->action != MMI_DA_PUSH_SIM2)
        && (item->action != MMI_DA_PUSH_SIM3)
        && (item->action != MMI_DA_PUSH_SIM4))
	{
		MMI_ASSERT(0);
	}

    if(item->filename)
        filename = srv_da_util_get_filename(item->filename);
    else if(item->filepath)
        filename = srv_da_util_get_filename(item->filepath);

    srv_da_extract_filepath((U16*)filename, temp_filename, ext);

	if(item->mime_type != NULL && !item->is_normal_save)
    {
        mmi_asc_n_to_wcs(ext, item->mime_type->file_ext, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
    }

}



void srv_da_push_confirm_start_to_download_callback(void *arg, U16 *filepath)
{
	srv_da_push_filename_done((U32)arg, filepath, MMI_FALSE, MMI_FALSE, NULL);
}


void srv_da_push_confirm_cancel_callback(void *arg)
{
	srv_da_push_filename_done((U32)arg, NULL, MMI_FALSE, MMI_FALSE, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_select_storage
 * DESCRIPTION
 *  To select storage for the item by the given setting.
 * PARAMETERS
 *  item        [IN] Push item
 *  setting     [IN] Setting
 * RETURNS
 *  void
 *****************************************************************************/
void srv_da_push_select_storage(srv_da_push_item_struct *item, srv_da_setting_struct *setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_storage_parameter_struct *para;
    U16                             *filename;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!setting)
    {
        setting = srv_da_get_setting_buffer();
        MMI_ASSERT(item->type_handler->setting_hdlr);
        item->type_handler->setting_hdlr(
                SRV_DA_PUSH_ID(item),
                item->mime_type ? item->mime_type->mime_type: 0,
                item->mime_type ? item->mime_type->mime_subtype: 0,
                item->action,
                item->file_length,
                item->url,
                item->mime_type_string,
                0, NULL,
                setting);
    }

    para = (srv_da_storage_parameter_struct*)srv_da_adp_mem_allocate(sizeof(srv_da_storage_parameter_struct));
    
    memset(para, 0, sizeof(srv_da_storage_parameter_struct));

    para->drv = setting->drv;
    para->storage = setting->storage;
    para->select_storage = (setting->storage == SRV_DA_STORAGE_NONE) ? MMI_TRUE : MMI_FALSE;

    mmi_wcscpy(para->folder, setting->folder);

    if(!setting->default_filename && setting->filename[0])  // Use setting given
        filename = setting->filename;
    else if(item->filename)                                 // Default
        filename = srv_da_util_get_filename(item->filename);
    else if(item->filepath)
        filename = srv_da_util_get_filename(item->filepath);
    else
    {
        MMI_ASSERT(0);
        return;
    }

    srv_da_extract_filepath(filename, para->filename, para->fileext);

    if(item->mime_type != NULL && !item->is_normal_save)
    {
        mmi_asc_n_to_wcs(para->fileext, item->mime_type->file_ext, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
    }
        
    para->select_filename = (!setting->default_filename && setting->filename[0] == 0) ? MMI_TRUE : MMI_FALSE;
    para->filesize = item->file_length;
    para->original_filepath = item->filepath;

    if (!(para->select_storage || para->select_filename)) /* Vikas: need to stop redundant event firing from service */
    {
        srv_da_decide_filepath_auto ((U32) item, para, item->action, srv_da_push_filename_done);
        OslMfree(para);
        return;
    }
#ifdef __COSMOS_MMI_PACKAGE__
    srv_da_adp_show_choice_screen(
        MMI_FALSE,
        item,
        sizeof (srv_da_push_item_struct),
        srv_da_push_confirm_start_to_download_callback,
        srv_da_push_confirm_cancel_callback,
        srv_da_push_confirm_cancel_callback, 
        MMI_TRUE);
#else
    srv_da_adp_display_select_storage((U32) item, para, item->action);
#endif /* __COSMOS_MMI_PACKAGE__ */
    OslMfree(para);
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_process_item
 * DESCRIPTION
 *  Start to process item. The item will be added into processing list.
 * PARAMETERS
 *  item    [IN] item
 *  setting [IN] setting
 * RETURNS
 *  void
 *****************************************************************************/
void srv_da_push_process_item(srv_da_push_item_struct *item, srv_da_setting_struct *setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 n_processing;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Push into processing list */
    srv_da_push_prepend_to_list(&(g_srv_da_push_context.processing), item);

    //n_processing = (U32)srv_da_push_get_number_of_elements(&(g_srv_da_push_context.processing));
	
    n_processing = g_srv_da_push_context.processing.number;


    if (n_processing >= SRV_DA_MAX_PUSHES_IN_PROCESSING_NUM)
    {
        if (item->action == MMI_DA_PUSH || item->action == MMI_DA_PUSH_SIM2 || item->action == MMI_DA_PUSH_SIM3 || item->action == MMI_DA_PUSH_SIM4)
        {
            srv_da_adp_popup(SRV_DA_GLOBAL_INSUFFICIENT_MEMORY, 0, SRV_DA_POPUP_TYPE_INFO);
        }
        else
        {
        	srv_da_adp_popup(SRV_DA_GLOBAL_INSUFFICIENT_MEMORY, 0, SRV_DA_POPUP_TYPE_ERROR);
        }
        srv_da_push_free_item(item);
        return;
    }

#ifdef __USB_IN_NORMAL_MODE__
    if (srv_usb_is_in_mass_storage_mode())
    {
        if (setting->storage == SRV_DA_STORAGE_PUSH_TEMP)
        {
            srv_da_push_filename_done((U32)item, item->filepath, MMI_FALSE, MMI_FALSE, NULL);
        }
        else
        {
            srv_da_push_free_item(item);
        }
        
        return;
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    srv_da_push_select_storage(item, setting);
}

/*****************************************************************************
 * FUNCTION
 *  srv_da_push_free_item
 * DESCRIPTION
 *  Remove an item from ALL lists and free it.
 * PARAMETERS
 *  item    [IN] Item to be freed.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_da_push_free_item(srv_da_push_item_struct *item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 n_to_be_notified, n_processing, n_screen_stack;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (item == NULL)
    {
        return;
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	n_to_be_notified = g_srv_da_push_context.to_be_confirmed.number;
    n_processing = g_srv_da_push_context.processing.number;
    n_screen_stack = g_srv_da_push_context.screen_stack.number;

    MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_PUSH_FREE_ITEM,
        item->unique_id, n_to_be_notified, n_processing, n_screen_stack);


    /* Remove from all lists */
    srv_da_push_remove_from_list(&(g_srv_da_push_context.screen_stack), item);
    srv_da_push_remove_from_list(&(g_srv_da_push_context.processing), item);
    srv_da_push_remove_from_list(&(g_srv_da_push_context.to_be_confirmed), item);

    /* free it */
    DA_FREE_BUFFER(item->filepath);
    DA_FREE_BUFFER(item->filename);
    DA_FREE_BUFFER(item->url);
    DA_FREE_BUFFER(item->mime_type_string);
    DA_FREE_BUFFER(item->header);
    DA_FREE_BUFFER(item->extra_info);
    DA_FREE_BUFFER(item);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	n_to_be_notified = g_srv_da_push_context.to_be_confirmed.number;
    n_processing = g_srv_da_push_context.processing.number;
    n_screen_stack = g_srv_da_push_context.screen_stack.number;
    SRV_DA_PUSH_TRACE_3(srv_da_push_free_item, n_to_be_notified, n_processing, n_screen_stack);
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_da_push_init
 * DESCRIPTION
 *  Initialize push module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_da_push_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_da_push_init_item_elements_pool();

    srv_da_push_init_list(&(g_srv_da_push_context.to_be_confirmed));
    srv_da_push_init_list(&(g_srv_da_push_context.processing));
    srv_da_push_init_list(&(g_srv_da_push_context.screen_stack));
    g_srv_da_push_context.item_in_notifying = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  srv_da_push_enter_idle_screen_callback
 * DESCRIPTION
 *  Callback for notification of entering Idle. Cancel all push items
 *  occupy screens. This callback is only a protection to avoid leaks.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_da_push_enter_idle_screen_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        item = srv_da_push_get_head_item(&(g_srv_da_push_context.screen_stack));

        if (item != NULL)
        {
            srv_da_push_free_item(item);
        }
        else
        {
            break;
        }
    } while (MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_get_number_of_processing_items
 * DESCRIPTION
 *  Get the number of the push items which is in processing.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of the items in processing.
 *****************************************************************************/
U32 srv_da_push_get_number_of_processing_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //return ((U32)srv_da_push_get_number_of_elements(&(g_srv_da_push_context.to_be_confirmed)));
	return g_srv_da_push_context.to_be_confirmed.number;
   
}


#define ____EXPORTED_APIS____


/*****************************************************************************
 * FUNCTION
 *  srv_da_push_get_header
 * DESCRIPTION
 *  Get the header follows the push.
 * PARAMETERS
 *  session_id      [IN] Session ID
 *  header_len      [OUT] Header length
 * RETURNS
 *  Header content, may be NULL.
 *****************************************************************************/
const S8* srv_da_push_get_header(S32 session_id, U32* header_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_push_item_struct *item;
    U16 local_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    local_id = (U16)DA_GET_LOCAL_ID(SRV_DA_JOB_TYPE_PUSH, session_id);
    item = srv_da_push_get_item_by_id(&(g_srv_da_push_context.processing), local_id);

    if (item != NULL)
    {
        if (header_len != NULL)
        {
            if (item->header != NULL)
            {
                *header_len = item->header_len;
            }
            else
            {
                *header_len = 0;
            }
        }
    
        return item->header;
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_save_file
 * DESCRIPTION
 *  Please refer to DLAgentGProt.h
 *****************************************************************************/
void srv_da_save_file(
    U16 app_id,
    const U16 *filepath,
    const U16 *default_filename,
    const S8 *mime_type_string,
    U32 extra_info_size,
    const void *extra_info_data,
    const srv_da_ui_setting_struct *ui_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 n_processing;
    srv_da_push_item_struct *item;
    const U16 *ext;
    srv_da_setting_struct *setting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(filepath != NULL && ui_setting != NULL);

    MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_SAVE_FILE, app_id,
        (U32)mime_type_string, extra_info_size, (U32)extra_info_data);

    //n_processing = (U32)srv_da_push_get_number_of_elements(&(g_srv_da_push_context.processing));
	n_processing = g_srv_da_push_context.processing.number;

    if (n_processing >= SRV_DA_MAX_PUSHES_IN_PROCESSING_NUM)
    {
        srv_da_adp_popup(SRV_DA_GLOBAL_INSUFFICIENT_MEMORY, 0, SRV_DA_POPUP_TYPE_ERROR);
        return;
    }

    item = (srv_da_push_item_struct*)srv_da_adp_mem_allocate(sizeof(srv_da_push_item_struct));

    memset(item, 0, sizeof(srv_da_push_item_struct));

    item->unique_id = srv_da_push_get_new_unique_id();
    item->mime_type_string = NULL;
    
    if (mime_type_string != NULL)
    {
        item->mime_type = srv_da_util_lookup_mime_type((U8*)mime_type_string, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_NONE);
        item->mime_type_string = (S8 *)srv_da_adp_mem_allocate(strlen(mime_type_string) + 1);
        strcpy(item->mime_type_string, mime_type_string);
    }
    else
    {
        ext = srv_da_util_get_extension((U16*)filepath);
        /*
         * MAUI_02656227 : Email does not have valid filepath, 
         * It is COSMOS specific because Email only use on COSMOS. Other applications [except IMPS] switched to message based communication
         */
        if (!ext)
        {
            ext = srv_da_util_get_extension((U16*)default_filename);
        }
        item->mime_type = srv_da_util_lookup_mime_type(NULL, (U16*)ext, MIME_TYPE_NONE, MIME_SUBTYPE_NONE);
        item->mime_type_string = NULL;
    }

    MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_MIMETYPE, (item->mime_type != NULL ? item->mime_type->mime_subtype : 0));
    
    item->type_handler = srv_da_search_mime_type_handler(item->mime_type);
    item->filepath = (U16*)srv_da_adp_mem_allocate((mmi_wcslen(filepath) + 1) * sizeof(U16));
    mmi_wcscpy(item->filepath, filepath);

    if (default_filename == NULL)
    {
        default_filename = srv_da_util_get_filename((U16*)filepath);
    }
    
    item->filename = (U16*)srv_da_adp_mem_allocate((mmi_wcslen(default_filename) + 1) * sizeof(U16));
    mmi_wcscpy(item->filename, default_filename);
    
    item->file_length = srv_da_util_get_file_size((U16*)filepath);
    item->url = NULL;
    item->header_len = 0;
    item->header = NULL;
    item->action = MMI_DA_SAVE_AS;
    item->is_normal_save = MMI_FALSE;
    item->user_selected_storage = MMI_FALSE;
#ifdef __DRM_SUPPORT__
    item->drm_method = DRM_METHOD_NONE;
    item->drm_process_session = NULL;
#endif

    if (extra_info_size > 0 && extra_info_data != NULL)
    {
        MMI_EXT_ASSERT(extra_info_size <= SRV_DA_MAX_EXTRA_INFO_DATA_SIZE, extra_info_size, SRV_DA_MAX_EXTRA_INFO_DATA_SIZE, 0);
        
        item->extra_info = (srv_da_extra_info_struct*)srv_da_adp_mem_allocate(sizeof(srv_da_extra_info_struct));
        item->extra_info->size = extra_info_size;
        memcpy(item->extra_info->data, extra_info_data, extra_info_size);
    }
    else
    {
        item->extra_info = NULL;
    }
    
    memcpy(&(item->ui), ui_setting, sizeof(srv_da_ui_setting_struct));

    setting = srv_da_get_setting_buffer();
    
    item->type_handler->setting_hdlr(
            SRV_DA_PUSH_ID(item),
            item->mime_type ? item->mime_type->mime_type: 0,
            item->mime_type ? item->mime_type->mime_subtype: 0,
            item->action,
            item->file_length,
            item->url,
            item->mime_type_string,
            0,
            NULL,
            setting);

    srv_da_push_process_item(item, setting);
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_get_extra_info
 * DESCRIPTION
 *  Please refer to DLAgentGProt.h
 *****************************************************************************/
const srv_da_extra_info_struct* srv_da_get_extra_info(S32 session_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 local_id;
    srv_da_push_item_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    local_id = (U16)DA_GET_LOCAL_ID(SRV_DA_JOB_TYPE_PUSH, session_id);
    item = srv_da_push_get_item_by_id(&(g_srv_da_push_context.processing), local_id);

    if (item != NULL && session_id == SRV_DA_PUSH_ID(item))
    {
        return item->extra_info;
    }

    return NULL;
}

srv_da_push_item_list_struct* srv_da_get_top_dispatch_item (void)
{
    return &(g_srv_da_push_context.screen_stack);
}

srv_da_push_item_list_struct* srv_da_get_item_to_be_confirm (void)
{
    return &(g_srv_da_push_context.to_be_confirmed);
}

U32 srv_da_get_item_to_be_confirm_num (void)
{
	return g_srv_da_push_context.to_be_confirmed.number;
}
srv_da_push_item_list_struct* srv_da_get_top_processing_list_item (void)
{
    return &(g_srv_da_push_context.processing);
}

srv_da_push_item_struct* srv_da_get_item_in_notifying (void)
{
    return (g_srv_da_push_context.item_in_notifying);
}

void srv_da_set_item_in_notifying (srv_da_push_item_struct *item_in_notifying)
{
    g_srv_da_push_context.item_in_notifying = item_in_notifying;
}

#endif /* !defined (__MMI_DOWNLOAD_AGENT__) */
