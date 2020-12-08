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
 *  SmsFolderListSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Folder List Hanlder
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MOD_SMSAL__
/**************************************************************
* Header Files Include
**************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "MMIDataType.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_mem_gprot.h"
#include "string.h"

#include "MMI_common_app_trc.h"
#include "Mmi_msg_context.h"
#include "SmsSrvGprot.h"
#include "SmsStorageSrv.h"
#include "SmsUtilSrv.h"
#include "SmsStorageCoreSrv.h"

#ifdef __SRV_SMS_ARCHIVE__
#include "SmsArchiveSrv.h"
#ifdef __MMI_USB_SUPPORT__
#include "UsbSrvGProt.h"
#endif /* __MMI_USB_SUPPORT__ */
#endif /* __SRV_SMS_ARCHIVE__ */


/**************************************************************
* MARCO
**************************************************************/
#ifdef __SRV_SMS_ARCHIVE__
#define SRV_SMS_MAX_MSG_NUM             (SRV_SMS_MAX_SMS_ENTRY + SRV_SMS_MAX_ARCH_ENTRY)
#else /* __SRV_SMS_ARCHIVE__ */
#define SRV_SMS_MAX_MSG_NUM             SRV_SMS_MAX_SMS_ENTRY
#endif
#define SRV_SMS_FISRT_BOX_TYPE          SRV_SMS_BOX_INBOX

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
#define SRV_SMS_MAX_MSG_BITMAP_SIZE     ((SRV_SMS_MAX_TOTAL_SMS_ENTRY + 7) / 8)
#else
#define SRV_SMS_MAX_MSG_BITMAP_SIZE     ((SRV_SMS_MAX_MSG_NUM + 7) / 8)
#endif

/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_del_list_cntx_struct;

typedef struct
{
    srv_sms_storage_enum dest_storage;
	MMI_BOOL flag;
    U16 curr_msg_id;
    U16 msg_num;
    U8 *msg_bitmap;
    U16 *msg_id_list;
    U16 *msg_list_size;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_move_copy_list_cntx_struct;


/**************************************************************
* Global Variables Declaration
**************************************************************/ 


/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static U16 srv_sms_inbox_size;
static U16 srv_sms_outbox_size;
static U16 srv_sms_drafts_size;
#ifdef __SRV_SMS_UNSENT_LIST__
static U16 srv_sms_unsent_size;
#endif

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
U16 srv_sms_inbox_total_size;
U16 srv_sms_outbox_total_size;
U16 srv_sms_drafts_total_size;
#ifdef __SRV_SMS_UNSENT_LIST__
U16 srv_sms_unsent_total_size;
#endif
#endif

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
U16 srv_sms_inbox_tcard_size;
U16 srv_sms_outbox_tcard_size;
U16 srv_sms_drafts_tcard_size;
#ifdef __SRV_SMS_UNSENT_LIST__
U16 srv_sms_unsent_tcard_size;
#endif
#endif

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
U16 srv_sms_inbox_show_size;
U16 srv_sms_outbox_show_size;
U16 srv_sms_drafts_show_size;
#ifdef __SRV_SMS_UNSENT_LIST__
U16 srv_sms_unsent_show_size;
#endif
#endif

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
U16 srv_sms_inbox_show_list[SRV_SMS_MAX_TOTAL_SMS_ENTRY];
U16 srv_sms_outbox_show_list[SRV_SMS_MAX_TOTAL_SMS_ENTRY];
U16 srv_sms_drafts_show_list[SRV_SMS_MAX_TOTAL_SMS_ENTRY];
#ifdef __SRV_SMS_UNSENT_LIST__
U16 srv_sms_unsent_show_list[SRV_SMS_MAX_TOTAL_SMS_ENTRY];
#endif /* __SRV_SMS_UNSENT_LIST__ */
#endif



#ifdef __SRV_SMS_SIMBOX_SUPPORT__
 U16 srv_sms_sim_size;
#endif

#ifdef __SRV_SMS_ARCHIVE__
U16 srv_sms_archive_size;
#endif /* __SRV_SMS_ARCHIVE__ */

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
U16 srv_sms_inbox_total_list[SRV_SMS_MAX_TOTAL_SMS_ENTRY];
U16 srv_sms_outbox_total_list[SRV_SMS_MAX_TOTAL_SMS_ENTRY];
U16 srv_sms_drafts_total_list[SRV_SMS_MAX_TOTAL_SMS_ENTRY];
#ifdef __SRV_SMS_UNSENT_LIST__
U16 srv_sms_unsent_total_list[SRV_SMS_MAX_TOTAL_SMS_ENTRY];
#endif /* __SRV_SMS_UNSENT_LIST__ */
#endif

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
U16 srv_sms_inbox_tcard_list[SRV_SMS_MAX_TCARD_ENTRY];
U16 srv_sms_outbox_tcard_list[SRV_SMS_MAX_TCARD_ENTRY];
U16 srv_sms_drafts_tcard_list[SRV_SMS_MAX_TCARD_ENTRY];
#ifdef __SRV_SMS_UNSENT_LIST__
U16 srv_sms_unsent_tcard_list[SRV_SMS_MAX_TCARD_ENTRY];
#endif /* __SRV_SMS_UNSENT_LIST__ */
#endif


static U16 srv_sms_inbox_list[SRV_SMS_MAX_SMS_ENTRY];
static U16 srv_sms_outbox_list[SRV_SMS_MAX_SMS_ENTRY];
static U16 srv_sms_drafts_list[SRV_SMS_MAX_SMS_ENTRY];
#ifdef __SRV_SMS_UNSENT_LIST__
static U16 srv_sms_unsent_list[SRV_SMS_MAX_SMS_ENTRY];
#endif /* __SRV_SMS_UNSENT_LIST__ */
#ifdef __SRV_SMS_SIMBOX_SUPPORT__
static U16 srv_sms_sim_list[SRV_SMS_MAX_SMS_ENTRY];
#endif /* __SRV_SMS_SIMBOX_SUPPORT__ */
#ifdef __SRV_SMS_ARCHIVE__
static U16 srv_sms_archive_list[SRV_SMS_MAX_ARCH_ENTRY];
#endif /* __SRV_SMS_ARCHIVE__ */


/**************************************************************
* Static Function Declaration
**************************************************************/
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
static void srv_sms_move_copy_msg_list_tcard(
                srv_sms_copy_move_tcard_struct *act_cntx,
                SrvSmsCallbackFunc callback_func,
                void* user_data,
                MMI_BOOL flag);



static void srv_sms_add_list_to_total_list(void);
static void srv_sms_total_list_reset_folder(void);

static void srv_sms_tcard_list_reset_folder(void);

#endif
static void srv_sms_move_copy_msg_list(
                srv_sms_box_enum msg_box_type,
                srv_sms_storage_enum dest_storage,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void* user_data,
                MMI_BOOL flag);


static U16 srv_sms_get_unread_sms_num_int(MMI_BOOL flag);


static MMI_BOOL srv_sms_list_sms_event_handler(srv_sms_event_struct *event_data);
static void srv_sms_list_create_folder(void);
static MMI_BOOL srv_sms_is_folder_list_support(srv_sms_box_enum msg_box_type);
static void srv_sms_list_reset_folder(void);
static void srv_sms_list_set_msg_change_event(void);
static void srv_sms_list_clear_msg_change_event(void);
static void srv_sms_list_add_event_handler(srv_sms_event_add_struct *event_info);
static void srv_sms_list_del_event_handler(srv_sms_event_delete_struct *event_info);
static void srv_sms_list_update_event_handler(srv_sms_event_update_struct *event_info);
#ifdef __SRV_SMS_ARCHIVE__
static void srv_sms_list_clear_folder_event_handler(srv_sms_event_clear_folder_struct *event_info);
#endif /* __SRV_SMS_ARCHIVE__ */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
static U16 srv_sms_get_list_and_size_pointer(
                U16 **msg_id_list,
                U16 **msg_list_size,
                srv_sms_box_enum msg_box_type);

static void srv_sms_delete_msg_list_callback(srv_sms_callback_struct *callback_data);
//static void srv_sms_copy_msg_list_callback(srv_sms_callback_struct *callback_data);
static void srv_sms_move_copy_msg_list_callback(srv_sms_callback_struct *callback_data);
#if (defined(__SRV_SMS_ARCHIVE__) && defined(__MMI_USB_SUPPORT__))
static void srv_sms_clear_list(srv_sms_box_enum msg_box_type);
#endif
static void srv_sms_create_list(srv_sms_box_enum msg_box_type);
static void srv_sms_get_list_query_data(
                srv_sms_query_struct *query_data,
                srv_sms_box_enum msg_box_type);

static U16 srv_sms_get_unread_sms_num_int(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count = 0;
    U16 size;
    U32 i;
	srv_sms_status_enum status;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(flag == MMI_TRUE)
    {
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        size = srv_sms_inbox_show_size;
    #else
        size = srv_sms_inbox_size; 
    #endif
    }
	#ifdef __SRV_SMS_SIMBOX_SUPPORT__  
    else
    {
        size = srv_sms_sim_size; 
    }
	#endif
    for (i = 0; i < size; i++)
    {
        U16 msg_id;
        if(flag == MMI_TRUE)
        {
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            msg_id = srv_sms_inbox_show_list[i];
    #else
            msg_id = srv_sms_inbox_list[i];
    #endif
            
        }
		#ifdef __SRV_SMS_SIMBOX_SUPPORT__ 
        else
        {
            msg_id = srv_sms_sim_list[i];
        }
		#endif

        status = srv_sms_get_msg_status(msg_id);
    
        if (status & SRV_SMS_STATUS_UNREAD)
        {
            count++;
        }
    }

    return count;
}

static void srv_sms_move_copy_msg_list(
                srv_sms_box_enum msg_box_type,
                srv_sms_storage_enum dest_storage,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void* user_data,
                MMI_BOOL flag)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *msg_id_list;
    U16 *msg_list_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(flag == MMI_TRUE)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MOVE_MSG_LIST, msg_box_type, dest_storage, sim_id);
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_COPY_MSG_LIST, msg_box_type, dest_storage, sim_id);
    }
    srv_sms_get_list_and_size_pointer(&msg_id_list, &msg_list_size, msg_box_type);

    if (*msg_list_size > 0)
    {
        U16 first_msg_id = SRV_SMS_INVALID_MSG_ID;
        U8 *msg_bitmap;
        U32 i;

        msg_bitmap = OslMalloc(SRV_SMS_MAX_MSG_BITMAP_SIZE);
        memset(msg_bitmap, 0, SRV_SMS_MAX_MSG_BITMAP_SIZE);

        for (i = 0; i < *msg_list_size; i++)
        {
            U16 msg_id = msg_id_list[i];
        #ifdef __SRV_SMS_MULTI_SIM__
            srv_sms_sim_enum msg_sim_id;

            msg_sim_id = srv_sms_get_msg_sim_id(msg_id);

            if (((msg_sim_id & sim_id) == msg_sim_id) &&
                (srv_sms_get_msg_storage_type(msg_id) != dest_storage))
        #else /* __SRV_SMS_MULTI_SIM__ */
            if (srv_sms_get_msg_storage_type(msg_id) != dest_storage)
        #endif /* __SRV_SMS_MULTI_SIM__ */
            {
                if (first_msg_id == SRV_SMS_INVALID_MSG_ID)
                {
                    first_msg_id = msg_id;
                }
            
                srv_sms_set_bitmap_index(msg_id, msg_bitmap);
            }
        }

        if (first_msg_id != SRV_SMS_INVALID_MSG_ID)
        {
            srv_sms_move_copy_list_cntx_struct *list_cntx;

            list_cntx = (srv_sms_move_copy_list_cntx_struct*)OslMalloc(sizeof(srv_sms_move_copy_list_cntx_struct));

            list_cntx->msg_bitmap = msg_bitmap;
            list_cntx->dest_storage = dest_storage;
            list_cntx->curr_msg_id = first_msg_id;
            list_cntx->msg_num = 0;
            list_cntx->msg_id_list = msg_id_list;
            list_cntx->msg_list_size = msg_list_size;
            list_cntx->callback_func = callback_func;
            list_cntx->user_data = user_data;
            list_cntx->flag = flag;
            if(flag == MMI_TRUE)
                srv_sms_move_msg(
                    first_msg_id,
                    dest_storage,
                    srv_sms_move_copy_msg_list_callback,
                    list_cntx);
            else
                srv_sms_copy_msg(
                first_msg_id,
                dest_storage,
                srv_sms_move_copy_msg_list_callback,
                list_cntx);
        }
        else
        {
                         
            OslMfree(msg_bitmap);
            
            if(flag == MMI_TRUE)
            {
                srv_sms_move_msg_list_cb_struct move_list_cb_data;
                move_list_cb_data.moved_msg_num = 0;
                srv_sms_succ_callback(
                    SRV_SMS_ACTION_MOVE,
                    &move_list_cb_data,
                    user_data,
                    callback_func);
            }
            else  
            {   
                srv_sms_copy_msg_list_cb_struct copy_list_cb_data;    
                copy_list_cb_data.copied_msg_num = 0;          
                srv_sms_succ_callback(
                    SRV_SMS_ACTION_COPY,
                    &copy_list_cb_data,
                    user_data,
                    callback_func);
            }
        }
    }
    else
    {

        if(flag == MMI_TRUE)
        {
            srv_sms_move_msg_list_cb_struct move_list_cb_data; 
            move_list_cb_data.moved_msg_num = 0;
            srv_sms_succ_callback(
                SRV_SMS_ACTION_MOVE,
                &move_list_cb_data,
                user_data,
                callback_func);
        }    
        else
        {
            srv_sms_copy_msg_list_cb_struct copy_list_cb_data; 
            copy_list_cb_data.copied_msg_num = 0;
            srv_sms_succ_callback(
                SRV_SMS_ACTION_COPY,
                &copy_list_cb_data,
                user_data,
                callback_func);
        }
    }
}

/**************************************************************
* Function Defination
**************************************************************/


#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
static void srv_sms_move_copy_msg_list_tcard(
                srv_sms_copy_move_tcard_struct *act_cntx,
                SrvSmsCallbackFunc callback_func,
                void* user_data,
                MMI_BOOL flag)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *msg_id_list;
    U16 *msg_list_size;
    srv_sms_storage_enum dest_storage;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_storage = act_cntx->dest_storage;
    srv_sms_get_total_list_and_size(&msg_id_list, &msg_list_size, act_cntx->msg_box_type);

    if (*msg_list_size > 0)
    {
        U16 first_msg_id = SRV_SMS_INVALID_MSG_ID;
        U8 *msg_bitmap;
        U32 i;

        msg_bitmap = OslMalloc(SRV_SMS_MAX_MSG_BITMAP_SIZE);
        memset(msg_bitmap, 0, SRV_SMS_MAX_MSG_BITMAP_SIZE);
        copy_move_list = MMI_TRUE;
        for (i = 0; i < *msg_list_size; i++)
        {
            U16 msg_id = msg_id_list[i];
            if(srv_sms_get_msg_storage_type(msg_id) == act_cntx->src_storage)
            {
            #ifdef __SRV_SMS_MULTI_SIM__
                srv_sms_sim_enum msg_sim_id;

                msg_sim_id = srv_sms_get_msg_sim_id(msg_id);

                if (((msg_sim_id & act_cntx->sim_id) == msg_sim_id) &&
                    (srv_sms_get_msg_storage_type(msg_id) != dest_storage))
            #else /* __SRV_SMS_MULTI_SIM__ */
                if (srv_sms_get_msg_storage_type(msg_id) != dest_storage)
            #endif /* __SRV_SMS_MULTI_SIM__ */
                {
                    if (first_msg_id == SRV_SMS_INVALID_MSG_ID)
                    {
                        first_msg_id = msg_id;
                    }
                
                    srv_sms_set_bitmap_index(msg_id, msg_bitmap);
                }
            }
        
        }

        if (first_msg_id != SRV_SMS_INVALID_MSG_ID)
        {
            srv_sms_move_copy_list_cntx_struct *list_cntx;

            list_cntx = (srv_sms_move_copy_list_cntx_struct*)OslMalloc(sizeof(srv_sms_move_copy_list_cntx_struct));

            list_cntx->msg_bitmap = msg_bitmap;
            list_cntx->dest_storage = dest_storage;
            list_cntx->curr_msg_id = first_msg_id;
            list_cntx->msg_num = 0;
            list_cntx->msg_id_list = msg_id_list;
            list_cntx->msg_list_size = msg_list_size;
            list_cntx->callback_func = callback_func;
            list_cntx->user_data = user_data;
            list_cntx->flag = flag;
            if(flag == MMI_TRUE)
                srv_sms_move_msg(
                    first_msg_id,
                    dest_storage,
                    srv_sms_move_copy_msg_list_callback,
                    list_cntx);
            else
                srv_sms_copy_msg(
                    first_msg_id,
                    dest_storage,
                    srv_sms_move_copy_msg_list_callback,
                    list_cntx);
        }
        else
        {
                         
            OslMfree(msg_bitmap);
            
            if(flag == MMI_TRUE)
            {
                srv_sms_move_msg_list_cb_struct move_list_cb_data;
                move_list_cb_data.moved_msg_num = 0;
                srv_sms_succ_callback(
                    SRV_SMS_ACTION_MOVE,
                    &move_list_cb_data,
                    user_data,
                    callback_func);
            }
            else  
            {   
                srv_sms_copy_msg_list_cb_struct copy_list_cb_data;    
                copy_list_cb_data.copied_msg_num = 0;          
                srv_sms_succ_callback(
                    SRV_SMS_ACTION_COPY,
                    &copy_list_cb_data,
                    user_data,
                    callback_func);
            }
        }
    }
    else
    {

        if(flag == MMI_TRUE)
        {
            srv_sms_move_msg_list_cb_struct move_list_cb_data; 
            move_list_cb_data.moved_msg_num = 0;
            srv_sms_succ_callback(
                SRV_SMS_ACTION_MOVE,
                &move_list_cb_data,
                user_data,
                callback_func);
        }    
        else
        {
            srv_sms_copy_msg_list_cb_struct copy_list_cb_data; 
            copy_list_cb_data.copied_msg_num = 0;
            srv_sms_succ_callback(
                SRV_SMS_ACTION_COPY,
                &copy_list_cb_data,
                user_data,
                callback_func);
        }
    }
}
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_list_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_list_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_INIT);

    srv_sms_list_reset_folder();

    srv_sms_set_interrupt_event_handler(
        EVT_ID_SRV_SMS_READY,
        srv_sms_list_sms_event_handler,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_unread_sms_num
 * DESCRIPTION
 *  Get Unread Message's number
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_sms_get_unread_sms_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    return srv_sms_get_unread_sms_num_int(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_unread_sim_sms_num
 * DESCRIPTION
 *  Get Unread SIM Box Message's number
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_sms_get_unread_sim_sms_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_SIMBOX_SUPPORT__
    return srv_sms_get_unread_sms_num_int(MMI_FALSE);
#else /* __SRV_SMS_SIMBOX_SUPPORT__ */
    return 0;
#endif /* __SRV_SMS_SIMBOX_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_id
 * DESCRIPTION
 *  Get message ID of the message in the box list
 * PARAMETERS
 *  msg_box_type    [IN]        Message Box List Type
 *  list_index      [IN]        The position of message in the Box List
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_sms_get_msg_id(srv_sms_box_enum msg_box_type, U16 list_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id = SRV_SMS_INVALID_MSG_ID;
    U16 *msg_id_list = NULL;
    U16 msg_list_size;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    U16 *total_msg_list_size;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if (srv_sms_get_show_list_and_size(&msg_id_list, &total_msg_list_size, msg_box_type))
        {
            if (list_index < *total_msg_list_size)
            {
                msg_id = msg_id_list[list_index];
            }
        }
#else
    if (srv_sms_get_list_and_size(&msg_id_list, &msg_list_size, msg_box_type))
    {
        if (list_index < msg_list_size)
        {
            msg_id = msg_id_list[list_index];
        }
    }
#endif

    return msg_id;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_id
 * DESCRIPTION
 *  Get message ID of the message in the box list
 * PARAMETERS
 *  msg_box_type    [IN]        Message Box List Type
 *  list_index      [IN]        The position of message in the Box List
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_sms_get_msg_id_for_send(srv_sms_box_enum msg_box_type, U16 list_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_id = SRV_SMS_INVALID_MSG_ID;
    U16 *msg_id_list = NULL;
    U16 msg_list_size;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    U16 *total_msg_list_size;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if (srv_sms_get_total_list_and_size(&msg_id_list, &total_msg_list_size, msg_box_type))
        {
            if (list_index < *total_msg_list_size)
            {
                msg_id = msg_id_list[list_index];
            }
        }
#else
    if (srv_sms_get_list_and_size(&msg_id_list, &msg_list_size, msg_box_type))
    {
        if (list_index < msg_list_size)
        {
            msg_id = msg_id_list[list_index];
        }
    }
#endif

    return msg_id;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_list_size
 * DESCRIPTION
 *  Get number of the messages in a box list
 * PARAMETERS
 *  msg_box_type    [IN]        Message Box List Type
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_sms_get_list_size(srv_sms_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_list_size = 0;
    //S32 i;
    //U16 msg_id;
    //srv_sms_storage_enum storage_type;
    //srv_sms_msg_node_struct *msg_node;
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    srv_sms_filter_enum storage_filter;
    srv_sms_tcard_msg_node_struct *tcard_msg_node;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    storage_filter = srv_sms_get_storage_filter();
 //   kal_prompt_trace(MOD_MMI,"srv_sms_get_list_size storage_filter = %d",storage_filter);
#endif
    switch (msg_box_type)
    {
        case SRV_SMS_BOX_INBOX:
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            msg_list_size = srv_sms_inbox_show_size;
        #else
            msg_list_size = srv_sms_inbox_size;
        #endif
            break;

        case SRV_SMS_BOX_OUTBOX:
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
           msg_list_size = srv_sms_outbox_show_size;
        #else
            msg_list_size = srv_sms_outbox_size;
        #endif
            break;

        case SRV_SMS_BOX_DRAFTS:
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            msg_list_size = srv_sms_drafts_show_size;
        #else
            msg_list_size = srv_sms_drafts_size;
            
        #endif
            break;

    #ifdef __SRV_SMS_UNSENT_LIST__
        case SRV_SMS_BOX_UNSENT:
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            msg_list_size = srv_sms_unsent_show_size;
        #else
            msg_list_size = srv_sms_unsent_size;
        #endif
            break;
    #endif /* __SRV_SMS_UNSENT_LIST__ */

    #ifdef __SRV_SMS_SIMBOX_SUPPORT__
        case SRV_SMS_BOX_SIM:
            msg_list_size = srv_sms_sim_size;
            break;
    #endif /* __SRV_SMS_SIMBOX_SUPPORT__ */

    #ifdef __SRV_SMS_ARCHIVE__
        case SRV_SMS_BOX_ARCHIVE:
            msg_list_size = srv_sms_archive_size;
            break;
    #endif /* __SRV_SMS_ARCHIVE__ */

        default:
            break;
    }

    return msg_list_size;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_list_size_for_send
 * DESCRIPTION
 *  Get number of the messages in a box list
 * PARAMETERS
 *  msg_box_type    [IN]        Message Box List Type
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_sms_get_list_size_for_send(srv_sms_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 msg_list_size = 0;
    //S32 i;
    //U16 msg_id;
    //srv_sms_storage_enum storage_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (msg_box_type)
    {
        case SRV_SMS_BOX_INBOX:
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            msg_list_size = srv_sms_inbox_total_size;
        #else
            msg_list_size = srv_sms_inbox_size;
        #endif
            break;

        case SRV_SMS_BOX_OUTBOX:
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
           msg_list_size = srv_sms_outbox_total_size;
        #else
            msg_list_size = srv_sms_outbox_size;
        #endif
            break;

        case SRV_SMS_BOX_DRAFTS:
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            msg_list_size = srv_sms_drafts_total_size;
        #else
            msg_list_size = srv_sms_drafts_size;
            
        #endif
            break;

    #ifdef __SRV_SMS_UNSENT_LIST__
        case SRV_SMS_BOX_UNSENT:
        #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            msg_list_size = srv_sms_unsent_total_size;
        #else
            msg_list_size = srv_sms_unsent_size;
        #endif
            break;
    #endif /* __SRV_SMS_UNSENT_LIST__ */

    #ifdef __SRV_SMS_SIMBOX_SUPPORT__
        case SRV_SMS_BOX_SIM:
            msg_list_size = srv_sms_sim_size;
            break;
    #endif /* __SRV_SMS_SIMBOX_SUPPORT__ */

    #ifdef __SRV_SMS_ARCHIVE__
        case SRV_SMS_BOX_ARCHIVE:
            msg_list_size = srv_sms_archive_size;
            break;
    #endif /* __SRV_SMS_ARCHIVE__ */

        default:
            break;
    }

    return msg_list_size;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_list_type
 * DESCRIPTION
 *  Get a message(with specific status, storage tpye, folder type)'s Box the Box List Type
 * PARAMETERS
 *  status          [IN]        Message Status
 *  storage_type    [IN]        Storage Type
 *  folder_id       [IN]        Folder Type
 * RETURNS
 *  srv_sms_box_enum
 *****************************************************************************/
srv_sms_box_enum srv_sms_get_list_type(
                    srv_sms_status_enum status,
                    srv_sms_storage_enum storage_type,
                    srv_sms_folder_enum folder_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_box_enum msg_box_type = SRV_SMS_BOX_RESERVED;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_LIST_TYPE, status, storage_type, folder_id);

#ifdef __SRV_SMS_ARCHIVE__
    if (folder_id == SRV_SMS_FOLDER_ARCHIVE)
    {
        msg_box_type = SRV_SMS_BOX_ARCHIVE;
    }
    else
#endif /* __SRV_SMS_ARCHIVE__ */
#ifdef __SRV_SMS_SIMBOX_SUPPORT__
    if (storage_type == SRV_SMS_STORAGE_SIM)
    {
        msg_box_type = SRV_SMS_BOX_SIM;
    }
    else
#endif /* __SRV_SMS_SIMBOX_SUPPORT__ */
    {
        U32 temp_status;

        /* Remove other Flag (Unsupported Flag) */
        temp_status = status & (~SRV_SMS_STATUS_UNSUPPORTED);

        switch (temp_status)
        {
            case SRV_SMS_STATUS_UNREAD:
            case SRV_SMS_STATUS_READ:
                msg_box_type = SRV_SMS_BOX_INBOX;
                break;

            case SRV_SMS_STATUS_DRAFT:
                msg_box_type = SRV_SMS_BOX_DRAFTS;
                break;

        #ifndef __SRV_SMS_UNSENT_LIST__
            case SRV_SMS_STATUS_UNSENT:
        #endif /* __SRV_SMS_UNSENT_LIST__ */
            case SRV_SMS_STATUS_SENT:
                msg_box_type = SRV_SMS_BOX_OUTBOX;
                break;

        #ifdef __SRV_SMS_UNSENT_LIST__
            case SRV_SMS_STATUS_UNSENT:
                msg_box_type = SRV_SMS_BOX_UNSENT;
                break;
        #endif /* __SRV_SMS_UNSENT_LIST__ */

            default:
                msg_box_type = SRV_SMS_BOX_NONE;
                break;
        }
    }

    return msg_box_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_list_index
 * DESCRIPTION
 *  Get position (list index) and box list type of the message
 * PARAMETERS
 *  msg_box_type    [OUT]       Message Box List type
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_sms_get_msg_list_index(srv_sms_box_enum* msg_box_type, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 list_index = SRV_SMS_INVALID_LIST_INDEX;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_LIST_INDEX, msg_id);

    *msg_box_type = SRV_SMS_BOX_NONE;

#ifdef __MMI_UM_REPORT_BOX__
    if (srv_sms_is_report_msg(msg_id))
    {
        U16 report_id = srv_sms_msg_id_to_report_id(msg_id);

        *msg_box_type = SRV_SMS_BOX_REPORT;

        list_index = srv_sms_get_report_list_index(report_id);
    }
    else
#endif /* __MMI_UM_REPORT_BOX__ */
    {
        U16 *msg_id_list;
        U16 *msg_list_size;
        srv_sms_box_enum curr_box_type = SRV_SMS_FISRT_BOX_TYPE;

        while (curr_box_type < SRV_SMS_BOX_RESERVED)
        {
            if (srv_sms_is_folder_list_support(curr_box_type) == MMI_TRUE)
            {
                U32 i;
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__ 
                if(storage_cntx.is_tsms_ready)
                {
                    if (msg_id >= SRV_SMS_MAX_MSG_NUM)
                    {
                        srv_sms_get_tcard_list_and_size(&msg_id_list, &msg_list_size, curr_box_type);

                        for (i = 0; i < *msg_list_size; i++)
                        {
                            if (msg_id_list[i] == msg_id)
                            {
            					*msg_box_type = curr_box_type;

            					MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_LIST_INDEX_1, *msg_box_type, i);

            					return i;
                            }
                        }
                    }
                    else
                    {
                        srv_sms_get_list_and_size_pointer(&msg_id_list, &msg_list_size, curr_box_type);

                        for (i = 0; i < *msg_list_size; i++)
                        {
                            if (msg_id_list[i] == msg_id)
                            {
            					*msg_box_type = curr_box_type;

            					MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_LIST_INDEX_1, *msg_box_type, i);

            					return i;
                            }
                        }
                    }
                    
                }
                else
                {
                    srv_sms_get_list_and_size_pointer(&msg_id_list, &msg_list_size, curr_box_type);

                    for (i = 0; i < *msg_list_size; i++)
                    {
                        if (msg_id_list[i] == msg_id)
                        {
        					*msg_box_type = curr_box_type;

        					MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_LIST_INDEX_1, *msg_box_type, i);

        					return i;
                        }
                    }
                }
            #else
                srv_sms_get_list_and_size_pointer(&msg_id_list, &msg_list_size, curr_box_type);

                for (i = 0; i < *msg_list_size; i++)
                {
                    if (msg_id_list[i] == msg_id)
                    {
    					*msg_box_type = curr_box_type;

    					MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_LIST_INDEX_1, *msg_box_type, i);

    					return i;
                    }
                }
            #endif
                srv_sms_get_list_and_size_pointer(&msg_id_list, &msg_list_size, curr_box_type);

                for (i = 0; i < *msg_list_size; i++)
                {
                    if (msg_id_list[i] == msg_id)
                    {
    					*msg_box_type = curr_box_type;

    					MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_LIST_INDEX_1, *msg_box_type, i);

    					return i;
                    }
                }
            }

            curr_box_type <<= 1;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_LIST_INDEX_1, *msg_box_type, list_index);

    return list_index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_msg_list
 * DESCRIPTION
 *  1. Delete all of the messages in the Message Box List.
 *  2. The Callback Action Data Structure is srv_sms_delete_msg_list_cb_struct.
 * PARAMETERS
 *  msg_box_type    [IN]        Message Box List Type
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_delete_msg_list(
        srv_sms_box_enum msg_box_type,
        srv_sms_sim_enum sim_id,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_del_list_cntx_struct *del_list_cntx;
    U8 *msg_bitmap;
    U16 *msg_id_list;
    U16 *msg_list_size;
    srv_sms_box_enum curr_box_type = SRV_SMS_FISRT_BOX_TYPE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_LIST, msg_box_type);

    msg_bitmap = OslMalloc(SRV_SMS_MAX_MSG_BITMAP_SIZE);

    memset(msg_bitmap, 0, SRV_SMS_MAX_MSG_BITMAP_SIZE);

    while (curr_box_type < SRV_SMS_BOX_RESERVED)
    {
        if ((msg_box_type & curr_box_type) && 
            (srv_sms_is_folder_list_support(curr_box_type) == MMI_TRUE))
        {
            U32 i;
        #ifndef __SRV_SMS_TCARD_STORAGE_SUPPORT__
            srv_sms_get_list_and_size_pointer(&msg_id_list, &msg_list_size, curr_box_type);
        #else
            srv_sms_get_show_list_and_size(&msg_id_list, &msg_list_size, curr_box_type);
        #endif

        #ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
            if (curr_box_type == SRV_SMS_BOX_UNSENT)
            {                
                for (i = 0; i < *msg_list_size; i++)
                {
                    U16 msg_id = msg_id_list[i];
                #ifdef __SRV_SMS_MULTI_SIM__
                    srv_sms_sim_enum msg_sim_id;

                    msg_sim_id = srv_sms_get_msg_sim_id(msg_id);

                    if ((msg_sim_id & sim_id) == msg_sim_id)
                #endif /* __SRV_SMS_MULTI_SIM__ */
                    {
                        srv_sms_send_status_enum send_status;

                        send_status = srv_sms_get_unsent_msg_status(msg_id);

                        if (send_status != SRV_SMS_SEND_SENDING)
                        {
                            if (send_status == SRV_SMS_SEND_WAITING)
                            {
                                srv_sms_set_unsent_msg_status(msg_id, SRV_SMS_SEND_FAIL);
                            }

                            srv_sms_set_bitmap_index(msg_id, msg_bitmap);
                        }
                    }
                }
            }
            else
        #endif /* __SRV_SMS_BACKGROUND_SEND_SUPPORT__ */
            {
                for (i = 0; i < *msg_list_size; i++)
                {
                    U16 msg_id = msg_id_list[i];
                #ifdef __SRV_SMS_MULTI_SIM__
                    srv_sms_sim_enum msg_sim_id;

                    msg_sim_id = srv_sms_get_msg_sim_id(msg_id);

                    if ((msg_sim_id & sim_id) == msg_sim_id)
                #endif /* __SRV_SMS_MULTI_SIM__ */
                    {
                        srv_sms_set_bitmap_index(msg_id, msg_bitmap);
                    }
                }
            }
        }

        curr_box_type <<= 1;
    }

    del_list_cntx = OslMalloc(sizeof(srv_sms_del_list_cntx_struct));

    del_list_cntx->callback_func = callback_func;
    del_list_cntx->user_data = user_data;

    srv_sms_delete_msg_bitmap(
        msg_bitmap,
        SRV_SMS_MAX_MSG_BITMAP_SIZE,
        srv_sms_delete_msg_list_callback,
        del_list_cntx);

    OslMfree(msg_bitmap);
}

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__


void srv_sms_tcard_list_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_total_list_reset_folder();
    srv_sms_tcard_list_reset_folder();
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_total_list_reset_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_tcard_list_reset_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_RESET_FOLDER);

    srv_sms_inbox_tcard_size = 0;
    srv_sms_outbox_tcard_size = 0;
    srv_sms_drafts_tcard_size = 0;
#ifdef __SRV_SMS_UNSENT_LIST__
    srv_sms_unsent_tcard_size = 0;
#endif /* __SRV_SMS_UNSENT_LIST__ */

    memset(srv_sms_inbox_tcard_list, 0xFF, sizeof(U16) * SRV_SMS_MAX_SMS_ENTRY);
    memset(srv_sms_outbox_tcard_list, 0xFF, sizeof(U16) * SRV_SMS_MAX_SMS_ENTRY);
    memset(srv_sms_drafts_tcard_list, 0xFF, sizeof(U16) * SRV_SMS_MAX_SMS_ENTRY);
#ifdef __SRV_SMS_UNSENT_LIST__
    memset(srv_sms_unsent_tcard_list, 0xFF, sizeof(U16) * SRV_SMS_MAX_SMS_ENTRY);
#endif /* __SRV_SMS_UNSENT_LIST__ */
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_total_list_reset_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_total_list_reset_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_RESET_FOLDER);

    srv_sms_inbox_total_size = 0;
    srv_sms_outbox_total_size = 0;
    srv_sms_drafts_total_size = 0;
#ifdef __SRV_SMS_UNSENT_LIST__
    srv_sms_unsent_total_size = 0;
#endif /* __SRV_SMS_UNSENT_LIST__ */

    memset(srv_sms_inbox_total_list, 0xFF, sizeof(U16) * SRV_SMS_MAX_SMS_ENTRY);
    memset(srv_sms_outbox_total_list, 0xFF, sizeof(U16) * SRV_SMS_MAX_SMS_ENTRY);
    memset(srv_sms_drafts_total_list, 0xFF, sizeof(U16) * SRV_SMS_MAX_SMS_ENTRY);
#ifdef __SRV_SMS_UNSENT_LIST__
    memset(srv_sms_unsent_total_list, 0xFF, sizeof(U16) * SRV_SMS_MAX_SMS_ENTRY);
#endif /* __SRV_SMS_UNSENT_LIST__ */
}

static void srv_sms_add_list_to_total_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    memcpy(srv_sms_inbox_total_list,srv_sms_inbox_list,SRV_SMS_MAX_SMS_ENTRY*2);
    srv_sms_inbox_total_size = srv_sms_inbox_size;
    memcpy(srv_sms_outbox_total_list,srv_sms_outbox_list,SRV_SMS_MAX_SMS_ENTRY*2);
    srv_sms_outbox_total_size = srv_sms_outbox_size;
    memcpy(srv_sms_drafts_total_list,srv_sms_drafts_list,SRV_SMS_MAX_SMS_ENTRY*2);
    srv_sms_drafts_total_size = srv_sms_drafts_size;
#ifdef __SRV_SMS_UNSENT_LIST__
    memcpy(srv_sms_unsent_total_list,srv_sms_unsent_list,SRV_SMS_MAX_SMS_ENTRY*2);
    srv_sms_unsent_total_size = srv_sms_unsent_size;
#endif /* __SRV_SMS_UNSENT_LIST__ */
    srv_sms_set_show_list(SRV_SMS_BOX_INBOX);
    srv_sms_set_show_list(SRV_SMS_BOX_OUTBOX);
    srv_sms_set_show_list(SRV_SMS_BOX_DRAFTS);
#ifdef __SRV_SMS_UNSENT_LIST__
    srv_sms_set_show_list(SRV_SMS_BOX_UNSENT);
#endif


}

void srv_sms_copy_msg_list_tcard(
                srv_sms_copy_move_tcard_struct *act_cntx,
                SrvSmsCallbackFunc callback_func,
                void* user_data)
{
    srv_sms_move_copy_msg_list_tcard(
                act_cntx,
                callback_func,
                user_data,
                MMI_FALSE);
}


void srv_sms_move_msg_list_tcard(
                srv_sms_copy_move_tcard_struct *act_cntx,
                SrvSmsCallbackFunc callback_func,
                void* user_data)
{
    srv_sms_move_copy_msg_list_tcard(
                act_cntx,
                callback_func,
                user_data,
                MMI_TRUE);
}

#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_msg_list
 * DESCRIPTION
 *  1. Copy all of the messages in the Message Box List to the destination storage;
 *  2. The Callback Action Data Structure is srv_sms_copy_msg_list_cb_struct.
 * PARAMETERS
 *  msg_box_type    [IN]        Message Box List Type
 *  dest_storage    [IN]        Destination Storage
 *  sim_id          [IN]        SIM Card ID
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_copy_msg_list(
        srv_sms_box_enum msg_box_type,
        srv_sms_storage_enum dest_storage,
        srv_sms_sim_enum sim_id,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    srv_sms_move_copy_msg_list(
        msg_box_type,
        dest_storage,
        sim_id,
        callback_func,
        user_data,
        MMI_FALSE);   
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_move_msg_list
 * DESCRIPTION
 *  1. Move all of the messages in the Message Box List to the destination storage;
 *  2. The Callback Action Data Structure is srv_sms_move_msg_list_cb_struct.
 * PARAMETERS
 *  msg_box_type    [IN]        Message Box List Type
 *  dest_storage    [IN]        Destination Storage
 *  sim_id          [IN]        SIM Card ID
 *  callback_func   [IN]        Callback Function
 *  user_data       [IN]        User Data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_move_msg_list(
        srv_sms_box_enum msg_box_type,
        srv_sms_storage_enum dest_storage,
        srv_sms_sim_enum sim_id,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    srv_sms_move_copy_msg_list(
        msg_box_type,
        dest_storage,
        sim_id,
        callback_func,
        user_data,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_msg_list_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_delete_msg_list_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_delete_msg_list_cb_struct del_list_cb_data;
    srv_sms_delete_msg_bitmap_cb_struct *del_bitmap_cb_data;
    srv_sms_del_list_cntx_struct *del_list_cntx;
    SrvSmsCallbackFunc callback_func;
    void *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_MSG_LIST_CALLBACK, callback_data->result);

    del_list_cntx = (srv_sms_del_list_cntx_struct*)callback_data->user_data;
    del_bitmap_cb_data = (srv_sms_delete_msg_bitmap_cb_struct*)callback_data->action_data;

    callback_func = del_list_cntx->callback_func;
    user_data = del_list_cntx->user_data;

    del_list_cb_data.deleted_msg_num = del_bitmap_cb_data->deleted_num;

    OslMfree(del_list_cntx);

    srv_sms_callback(
        SRV_SMS_ACTION_DELETE,
        callback_data->result,
        callback_data->cause,
        &del_list_cb_data,
        user_data,
        callback_func);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_copy_msg_list_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_move_copy_msg_list_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    srv_sms_move_copy_list_cntx_struct *list_cntx;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
    U8 *msg_bitmap;
    U16 msg_list_size;
    U16 *msg_id_list;
    U16 curr_msg_id = SRV_SMS_INVALID_MSG_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_cntx = (srv_sms_move_copy_list_cntx_struct*)callback_data->user_data;
    callback_func = list_cntx->callback_func;
    user_data = list_cntx->user_data;
    msg_bitmap = list_cntx->msg_bitmap;
    msg_list_size = *list_cntx->msg_list_size;
    msg_id_list = list_cntx->msg_id_list;

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    if (list_cntx->dest_storage == SRV_SMS_STORAGE_TCARD)
    {
        if(!storage_cntx.is_tsms_ready)
        {
            if(list_cntx->flag)
            {
                srv_sms_move_msg_list_cb_struct move_list_cb_data; 
                move_list_cb_data.moved_msg_num = list_cntx->msg_num;
			    OslMfree(list_cntx->msg_bitmap);
                OslMfree(list_cntx);
                srv_sms_callback(
                    SRV_SMS_ACTION_MOVE,
                    MMI_FALSE,
                    SRV_SMS_CAUSE_FS_ERROR,
                    &move_list_cb_data,
                    user_data,
                    callback_func);
            }
            else
            {
                srv_sms_copy_msg_list_cb_struct copy_list_cb_data; 
                copy_list_cb_data.copied_msg_num = list_cntx->msg_num;
			    OslMfree(list_cntx->msg_bitmap);
                OslMfree(list_cntx);
                srv_sms_callback(
                    SRV_SMS_ACTION_COPY,
                    MMI_FALSE,
                    SRV_SMS_CAUSE_FS_ERROR,
                    &copy_list_cb_data,
                    user_data,
                    callback_func);
            }
            copy_move_list = MMI_FALSE;

            return;
        }
    }
#endif
    if (callback_data->result == MMI_TRUE)
    {
        list_cntx->msg_num++;

        srv_sms_clear_bitmap_index(list_cntx->curr_msg_id, msg_bitmap);

        for (i = 0; i < msg_list_size; i++)
        {
            U16 msg_id = msg_id_list[i];

            if (srv_sms_check_bitmap_index(msg_id, msg_bitmap) == MMI_TRUE)
            {
                curr_msg_id = msg_id;
                break;
            }
        }
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__ 
        if (curr_msg_id >= SRV_SMS_MAX_MSG_NUM)
        {
            if(!storage_cntx.is_tsms_ready)
            {
                if(list_cntx->flag)
                {
                    srv_sms_move_msg_list_cb_struct move_list_cb_data; 
                    move_list_cb_data.moved_msg_num = list_cntx->msg_num;
    			    OslMfree(list_cntx->msg_bitmap);
                    OslMfree(list_cntx);
                    srv_sms_callback(
                        SRV_SMS_ACTION_MOVE,
                        MMI_FALSE,
                        SRV_SMS_CAUSE_FS_ERROR,
                        &move_list_cb_data,
                        user_data,
                        callback_func);
                }
                else
                {
                    srv_sms_copy_msg_list_cb_struct copy_list_cb_data; 
                    copy_list_cb_data.copied_msg_num = list_cntx->msg_num;
    			    OslMfree(list_cntx->msg_bitmap);
                    OslMfree(list_cntx);
                    srv_sms_callback(
                        SRV_SMS_ACTION_COPY,
                        MMI_FALSE,
                        SRV_SMS_CAUSE_FS_ERROR,
                        &copy_list_cb_data,
                        user_data,
                        callback_func);
                }
                copy_move_list = MMI_FALSE;

                return;
            }
        }
    #endif
        if (curr_msg_id != SRV_SMS_INVALID_MSG_ID)
        {
            list_cntx->curr_msg_id = curr_msg_id;
            if(list_cntx->flag == MMI_TRUE)
                srv_sms_move_msg(
                    curr_msg_id,
                    list_cntx->dest_storage,
                    srv_sms_move_copy_msg_list_callback,
                    list_cntx);
            else
                srv_sms_copy_msg(
                    curr_msg_id,
                        list_cntx->dest_storage,
                        srv_sms_move_copy_msg_list_callback,
                        list_cntx);
        }
        else
        {
            if(list_cntx->flag)
            {
                srv_sms_move_msg_list_cb_struct move_list_cb_data; 
                move_list_cb_data.moved_msg_num = list_cntx->msg_num;
				OslMfree(list_cntx->msg_bitmap);
                OslMfree(list_cntx);
                srv_sms_succ_callback(
                        SRV_SMS_ACTION_MOVE,
                        &move_list_cb_data,
                        user_data,
                        callback_func);
                
            }
            else
            {
                srv_sms_copy_msg_list_cb_struct copy_list_cb_data; 
                copy_list_cb_data.copied_msg_num = list_cntx->msg_num;
				OslMfree(list_cntx->msg_bitmap);
                OslMfree(list_cntx);
                srv_sms_succ_callback(
                    SRV_SMS_ACTION_COPY,
                    &copy_list_cb_data,
                    user_data,
                    callback_func);
            }
            copy_move_list = MMI_FALSE;
            
        }
    }
    else
    {   
        srv_sms_clear_bitmap_index(list_cntx->curr_msg_id, msg_bitmap);
        for (i = 0; i < msg_list_size; i++)
        {
            U16 msg_id = msg_id_list[i];

            if (srv_sms_check_bitmap_index(msg_id, msg_bitmap) == MMI_TRUE)
            {
                curr_msg_id = msg_id;
                break;
            }
        }
        if (curr_msg_id != SRV_SMS_INVALID_MSG_ID)
        {
            list_cntx->curr_msg_id = curr_msg_id;
            if(list_cntx->flag == MMI_TRUE)
                srv_sms_move_msg(
                    curr_msg_id,
                    list_cntx->dest_storage,
                    srv_sms_move_copy_msg_list_callback,
                    list_cntx);
            else
                srv_sms_copy_msg(
                    curr_msg_id,
                    list_cntx->dest_storage,
                    srv_sms_move_copy_msg_list_callback,
                    list_cntx);
        }
        else
        {
            if(list_cntx->flag)
            {
                srv_sms_move_msg_list_cb_struct move_list_cb_data; 
                move_list_cb_data.moved_msg_num = list_cntx->msg_num;
			    OslMfree(list_cntx->msg_bitmap);
                OslMfree(list_cntx);
                srv_sms_callback(
                    SRV_SMS_ACTION_MOVE,
                    MMI_FALSE,
                    callback_data->cause,
                    &move_list_cb_data,
                    user_data,
                    callback_func);
            }
            else
            {
                srv_sms_copy_msg_list_cb_struct copy_list_cb_data; 
                copy_list_cb_data.copied_msg_num = list_cntx->msg_num;
			    OslMfree(list_cntx->msg_bitmap);
                OslMfree(list_cntx);
                srv_sms_callback(
                    SRV_SMS_ACTION_COPY,
                    MMI_FALSE,
                    callback_data->cause,
                    &copy_list_cb_data,
                    user_data,
                    callback_func);
            }
            copy_move_list = MMI_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_list_sms_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_list_sms_event_handler(srv_sms_event_struct *event_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_SMS_EVENT_HANDLER, event_data->evt_id);

    switch (event_data->evt_id)
    {
        case EVT_ID_SRV_SMS_READY:
        {
            srv_sms_event_sms_ready_struct *event_info;

            event_info = (srv_sms_event_sms_ready_struct*)event_data->event_info;

            if (event_info->is_sms_ready)
            {
                srv_sms_list_create_folder();
                //add to default list to total list
            #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
                srv_sms_add_list_to_total_list();
            #endif
                srv_sms_list_set_msg_change_event();
            }
            else
            {
                srv_sms_list_reset_folder();
                
                srv_sms_list_clear_msg_change_event();
            }
            break;
        }

        case EVT_ID_SRV_SMS_ADD_MSG:
        {
            srv_sms_event_add_struct *event_info;

            event_info = (srv_sms_event_add_struct *)event_data->event_info;
    
            srv_sms_list_add_event_handler(event_info);
            break;
        }

        case EVT_ID_SRV_SMS_DEL_MSG:
        {
            srv_sms_event_delete_struct *event_info;

            event_info = (srv_sms_event_delete_struct *)event_data->event_info;

            srv_sms_list_del_event_handler(event_info);
            break;
        }

        case EVT_ID_SRV_SMS_UPDATE_MSG:
        {
            srv_sms_event_update_struct *event_info;

            event_info = (srv_sms_event_update_struct *)event_data->event_info;

            srv_sms_list_update_event_handler(event_info);
            break;
        }

    #ifdef __SRV_SMS_ARCHIVE__
        case EVT_ID_SRV_SMS_CLEAR_FOLDER:
        {
            srv_sms_event_clear_folder_struct *event_info;

            event_info = (srv_sms_event_clear_folder_struct*)event_data->event_info;

            srv_sms_list_clear_folder_event_handler(event_info);
            break;
        }
    #endif /* __SRV_SMS_ARCHIVE__ */

        default:
            break;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_list_create_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_list_create_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_box_type = SRV_SMS_FISRT_BOX_TYPE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (msg_box_type < SRV_SMS_BOX_RESERVED)
    {
	    if(srv_sms_is_folder_list_support((srv_sms_box_enum)msg_box_type))
        {
            srv_sms_create_list((srv_sms_box_enum)msg_box_type);
	    }
        msg_box_type = msg_box_type << 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_folder_list_support
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_sms_is_folder_list_support(srv_sms_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_IS_FOLDER_LIST_SUPPORT, msg_box_type);

    switch (msg_box_type)
    {
        case SRV_SMS_BOX_INBOX:
        case SRV_SMS_BOX_OUTBOX:
        case SRV_SMS_BOX_DRAFTS:
    #ifdef __SRV_SMS_UNSENT_LIST__
        case SRV_SMS_BOX_UNSENT:
    #endif /* __SRV_SMS_UNSENT_LIST__ */
    #ifdef __SRV_SMS_SIMBOX_SUPPORT__
        case SRV_SMS_BOX_SIM:
    #endif /* __SRV_SMS_SIMBOX_SUPPORT__ */
    #ifdef __SRV_SMS_ARCHIVE__
        case SRV_SMS_BOX_ARCHIVE:
    #endif /* __SRV_SMS_ARCHIVE__ */
            result = MMI_TRUE;
            break;

        default:
            result = MMI_FALSE;
            break;
    }

    return result;
}




/*****************************************************************************
 * FUNCTION
 *  srv_sms_list_reset_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_list_reset_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_RESET_FOLDER);
#ifdef __SRV_SMS_AT_SUPPORT__
    in_atcm_delete = 0;
    in_atcm_cmgl = 0;
#endif
    srv_sms_inbox_size = 0;
    srv_sms_outbox_size = 0;
    srv_sms_drafts_size = 0;
#ifdef __SRV_SMS_UNSENT_LIST__
    srv_sms_unsent_size = 0;
#endif /* __SRV_SMS_UNSENT_LIST__ */
#ifdef __SRV_SMS_SIMBOX_SUPPORT__
    srv_sms_sim_size = 0;
#endif /* __SRV_SMS_SIMBOX_SUPPORT__ */
#ifdef __SRV_SMS_ARCHIVE__
    srv_sms_archive_size = 0;
#endif /* __SRV_SMS_ARCHIVE__ */

    memset(srv_sms_inbox_list, 0xFF, sizeof(U16) * SRV_SMS_MAX_SMS_ENTRY);
    memset(srv_sms_outbox_list, 0xFF, sizeof(U16) * SRV_SMS_MAX_SMS_ENTRY);
    memset(srv_sms_drafts_list, 0xFF, sizeof(U16) * SRV_SMS_MAX_SMS_ENTRY);
#ifdef __SRV_SMS_UNSENT_LIST__
    memset(srv_sms_unsent_list, 0xFF, sizeof(U16) * SRV_SMS_MAX_SMS_ENTRY);
#endif /* __SRV_SMS_UNSENT_LIST__ */
#ifdef __SRV_SMS_SIMBOX_SUPPORT__
    memset(srv_sms_sim_list, 0xFF, sizeof(U16) * SRV_SMS_MAX_SMS_ENTRY);
#endif /* __SRV_SMS_SIMBOX_SUPPORT__ */
#ifdef __SRV_SMS_ARCHIVE__
    memset(srv_sms_archive_list, 0xFF, sizeof(U16) * SRV_SMS_MAX_ARCH_ENTRY);
#endif /* __SRV_SMS_ARCHIVE__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_list_set_msg_change_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_list_set_msg_change_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_SET_MSG_CHANGE_EVENT);

    srv_sms_set_interrupt_event_handler(EVT_ID_SRV_SMS_ADD_MSG, srv_sms_list_sms_event_handler, NULL);
    srv_sms_set_interrupt_event_handler(EVT_ID_SRV_SMS_DEL_MSG, srv_sms_list_sms_event_handler, NULL);
    srv_sms_set_interrupt_event_handler(EVT_ID_SRV_SMS_UPDATE_MSG, srv_sms_list_sms_event_handler, NULL);
#ifdef __SRV_SMS_ARCHIVE__
    srv_sms_set_interrupt_event_handler(EVT_ID_SRV_SMS_CLEAR_FOLDER, srv_sms_list_sms_event_handler, NULL);
#endif /* __SRV_SMS_ARCHIVE__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_list_clear_msg_change_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_list_clear_msg_change_event(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_CLEAR_MSG_CHANGE_EVENT);

    srv_sms_clear_interrupt_event_handler(EVT_ID_SRV_SMS_ADD_MSG, srv_sms_list_sms_event_handler, NULL);
    srv_sms_clear_interrupt_event_handler(EVT_ID_SRV_SMS_DEL_MSG, srv_sms_list_sms_event_handler, NULL);
    srv_sms_clear_interrupt_event_handler(EVT_ID_SRV_SMS_UPDATE_MSG, srv_sms_list_sms_event_handler, NULL);
#ifdef __SRV_SMS_ARCHIVE__
    srv_sms_clear_interrupt_event_handler(EVT_ID_SRV_SMS_CLEAR_FOLDER, srv_sms_list_sms_event_handler, NULL);
#endif /* __SRV_SMS_ARCHIVE__ */
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_exec_interrupt_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_list_add_event_handler(srv_sms_event_add_struct *event_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 add_msg_id = event_info->msg_id;
    srv_sms_msg_info_struct *msg_info = &event_info->msg_info;
    srv_sms_box_enum msg_box_type;
    U16 *msg_id_list = NULL;
    U16 *msg_list_size = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_ADD_EVENT_HANDLER, event_info);

    msg_box_type = srv_sms_get_list_type(
                    msg_info->status,
                    msg_info->storage_type,
                    msg_info->folder_id);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_ADD_EVENT_HANDLER_1, msg_box_type);
    if(add_msg_id < SRV_SMS_MAX_MSG_NUM)
    {

    srv_sms_get_list_and_size_pointer(
        &msg_id_list,
        &msg_list_size,
        msg_box_type);

    if (msg_id_list != NULL)
    {
        U16 curr_msg_num;
        U16 max_msg_num = SRV_SMS_MAX_SMS_ENTRY;
        MMI_BOOL result;

        curr_msg_num = *msg_list_size;

    #ifdef __SRV_SMS_ARCHIVE__
        if (msg_box_type == SRV_SMS_BOX_ARCHIVE)
        {
            max_msg_num = SRV_SMS_MAX_ARCH_ENTRY;
        }
    #endif /* __SRV_SMS_ARCHIVE__ */

        result = srv_sms_add_msg_into_list(
                    msg_id_list,
                    curr_msg_num,
                    max_msg_num,
                    add_msg_id,
                    SRV_SMS_SORT_TIMESTAMP,
                    SRV_SMS_ORDER_DEFAULT);

        if (result == MMI_TRUE)
        {
        #ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
            if (msg_box_type == SRV_SMS_BOX_UNSENT)
            {                
                srv_sms_set_unsent_msg_status(add_msg_id, SRV_SMS_SEND_FAIL);
            }
        #endif /* __SRV_SMS_BACKGROUND_SEND_SUPPORT__ */

            (*msg_list_size)++;
        }
    }
}

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        srv_sms_tcard_add_msg_list(MMI_FALSE, add_msg_id,msg_box_type);
#endif
  

}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_exec_interrupt_event
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_list_del_event_handler(srv_sms_event_delete_struct *event_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 del_msg_id = event_info->msg_id;
    srv_sms_msg_info_struct *msg_info = &event_info->msg_info;
    srv_sms_box_enum msg_box_type;
    U16 *msg_id_list = NULL;
    U16 *msg_list_size = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_DEL_EVENT_HANDLER, event_info);

    msg_box_type = srv_sms_get_list_type(
                    msg_info->status,
                    msg_info->storage_type,
                    msg_info->folder_id);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_DEL_EVENT_HANDLER_1, msg_box_type);
    if(del_msg_id < SRV_SMS_MAX_MSG_NUM)
    {
        srv_sms_get_list_and_size_pointer(
            &msg_id_list,
            &msg_list_size,
            msg_box_type);

        if (msg_id_list != NULL)
        {
            U16 curr_msg_num;
            MMI_BOOL result;

            curr_msg_num = *msg_list_size;

            result = srv_sms_delete_msg_from_list(msg_id_list, curr_msg_num, del_msg_id);

            if (result == MMI_TRUE)
            {
                (*msg_list_size)--;
            }
        }
    }

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
#ifdef __SRV_SMS_SIMBOX_SUPPORT__
    if(msg_box_type != SRV_SMS_BOX_SIM)
    {
        srv_sms_tcard_delete_msg_list(del_msg_id, msg_box_type);
    }
#else
    srv_sms_tcard_delete_msg_list(del_msg_id, msg_box_type);
#endif
    
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_list_update_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_list_update_event_handler(srv_sms_event_update_struct *event_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 update_msg_id = event_info->msg_id;
    srv_sms_msg_info_struct *old_msg_info = &event_info->old_msg_info;
    srv_sms_msg_info_struct *new_msg_info = &event_info->new_msg_info;
    srv_sms_box_enum src_box_type;
    srv_sms_box_enum dest_box_type;
    U16 *src_msg_id_list = NULL;
    U16 *src_msg_list_size;
    U16 *dest_msg_id_list = NULL;
    U16 *dest_msg_list_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_UPDATE_EVENT_HANDLER, event_info);

    src_box_type = srv_sms_get_list_type(
                        old_msg_info->status,
                        old_msg_info->storage_type,
                        old_msg_info->folder_id);

    dest_box_type = srv_sms_get_list_type(
                        new_msg_info->status,
                        new_msg_info->storage_type,
                        new_msg_info->folder_id);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_LIST_UPDATE_EVENT_HANDLER_1, src_box_type, dest_box_type);
    if(update_msg_id < SRV_SMS_MAX_MSG_NUM)
    {
        if (src_box_type != dest_box_type)
        {
            srv_sms_get_list_and_size_pointer(
                &src_msg_id_list,
                &src_msg_list_size,
                src_box_type);

            srv_sms_get_list_and_size_pointer(
                &dest_msg_id_list,
                &dest_msg_list_size,
                dest_box_type);

            if (src_msg_id_list != NULL)
            {
                MMI_BOOL result;

                result = srv_sms_delete_msg_from_list(src_msg_id_list, *src_msg_list_size, update_msg_id);

                if (result == MMI_TRUE)
                {
                    (*src_msg_list_size)--;
                }
            }
            
            if (dest_msg_id_list != NULL)
            {
                srv_sms_add_msg_into_list(
                    dest_msg_id_list,
                    *dest_msg_list_size,
                    SRV_SMS_MAX_SMS_ENTRY,
                    update_msg_id,
                    SRV_SMS_SORT_TIMESTAMP,
                    SRV_SMS_ORDER_DEFAULT);

            #ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
                if (dest_box_type == SRV_SMS_BOX_UNSENT)
                {
                    srv_sms_set_unsent_msg_status(update_msg_id, SRV_SMS_SEND_FAIL);
                }
            #endif /* __SRV_SMS_BACKGROUND_SEND_SUPPORT__ */

                (*dest_msg_list_size)++;
            }
        }
    }
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    srv_sms_tcard_update_msg_list(update_msg_id,src_box_type,dest_box_type);
#endif
}


#ifdef __SRV_SMS_ARCHIVE__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_list_clear_folder_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_list_clear_folder_event_handler(srv_sms_event_clear_folder_struct *event_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event_info->folder_id == SRV_SMS_FOLDER_ARCHIVE)
    {
        MMI_ASSERT(srv_sms_archive_size <= SRV_SMS_MAX_ARCH_ENTRY);

        if (srv_sms_archive_size > 0)
        {
            memset(srv_sms_archive_list, 0xFF, (sizeof(U16) * srv_sms_archive_size));
            srv_sms_archive_size = 0;
        }
    }
}
#endif /* __SRV_SMS_ARCHIVE__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_list_and_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_get_list_and_size(U16 **msg_id_list, U16 *msg_list_size, srv_sms_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_box_type)
    {
        case SRV_SMS_BOX_INBOX:
            *msg_id_list = srv_sms_inbox_list;
            *msg_list_size = srv_sms_inbox_size;
            break;

        case SRV_SMS_BOX_OUTBOX:
            *msg_id_list = srv_sms_outbox_list;
            *msg_list_size = srv_sms_outbox_size;
            break;

        case SRV_SMS_BOX_DRAFTS:
            *msg_id_list = srv_sms_drafts_list;
            *msg_list_size = srv_sms_drafts_size;
            break;

    #ifdef __SRV_SMS_UNSENT_LIST__
        case SRV_SMS_BOX_UNSENT:
            *msg_id_list = srv_sms_unsent_list;
            *msg_list_size = srv_sms_unsent_size;
            break;
    #endif /* __SRV_SMS_UNSENT_LIST__ */

    #ifdef __SRV_SMS_SIMBOX_SUPPORT__
        case SRV_SMS_BOX_SIM:
            *msg_id_list = srv_sms_sim_list;
            *msg_list_size = srv_sms_sim_size;
            break;
    #endif /* __SRV_SMS_SIMBOX_SUPPORT__ */

    #ifdef __SRV_SMS_ARCHIVE__
        case SRV_SMS_BOX_ARCHIVE:
            *msg_id_list = srv_sms_archive_list;
            *msg_list_size = srv_sms_archive_size;
            break;
    #endif /* __SRV_SMS_ARCHIVE__ */

        default:
            result = MMI_FALSE;
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_list_and_size_pointer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U16 srv_sms_get_list_and_size_pointer(
                U16 **msg_id_list,
                U16 **msg_list_size,
                srv_sms_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 max_list_size = SRV_SMS_MAX_SMS_ENTRY;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_LIST_AND_SIZE_POINTER, msg_box_type);

    switch (msg_box_type)
    {
        case SRV_SMS_BOX_INBOX:
            *msg_id_list = srv_sms_inbox_list;
            *msg_list_size = &srv_sms_inbox_size;
            break;

        case SRV_SMS_BOX_OUTBOX:
            *msg_id_list = srv_sms_outbox_list;
            *msg_list_size = &srv_sms_outbox_size;
            break;

        case SRV_SMS_BOX_DRAFTS:
            *msg_id_list = srv_sms_drafts_list;
            *msg_list_size = &srv_sms_drafts_size;
            break;

    #ifdef __SRV_SMS_UNSENT_LIST__
        case SRV_SMS_BOX_UNSENT:
            *msg_id_list = srv_sms_unsent_list;
            *msg_list_size = &srv_sms_unsent_size;
            break;
    #endif /* __SRV_SMS_UNSENT_LIST__ */

    #ifdef __SRV_SMS_SIMBOX_SUPPORT__
        case SRV_SMS_BOX_SIM:
            *msg_id_list = srv_sms_sim_list;
            *msg_list_size = &srv_sms_sim_size;
            break;
    #endif /* __SRV_SMS_SIMBOX_SUPPORT__ */

    #ifdef __SRV_SMS_ARCHIVE__
        case SRV_SMS_BOX_ARCHIVE:
            *msg_id_list = srv_sms_archive_list;
            *msg_list_size = &srv_sms_archive_size;
            max_list_size = SRV_SMS_MAX_ARCH_ENTRY;
            break;
    #endif /* __SRV_SMS_ARCHIVE__ */

        default:
            *msg_id_list = NULL;
            *msg_list_size = NULL;
            max_list_size = 0;
            break;
    }

    return max_list_size;
}

#if (defined(__SRV_SMS_ARCHIVE__) && defined(__MMI_USB_SUPPORT__))

/*****************************************************************************
 * FUNCTION
 *  srv_sms_clear_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_clear_list(srv_sms_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *msg_id_list = NULL;
    U16 *msg_list_size = NULL;
    U16 max_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CLEAR_LIST, msg_box_type);

    max_size = srv_sms_get_list_and_size_pointer(&msg_id_list, &msg_list_size, msg_box_type);

    if ((max_size > 0) && ((*msg_list_size) > 0))
    {
        memset(msg_id_list, 0xFF, sizeof(U16) * (*msg_list_size));
        *msg_list_size = 0;
    }
}

#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_create_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_create_list(srv_sms_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *msg_id_list;
    U16 *list_size;
    U16 max_list_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CREATE_LIST, msg_box_type);

    max_list_size = srv_sms_get_list_and_size_pointer(
                        &msg_id_list,
                        &list_size,
                        msg_box_type);

    if (max_list_size > 0)
    {
        srv_sms_query_struct *query_data;
        U16 msg_num;

        query_data = OslMalloc(sizeof(srv_sms_query_struct));

        srv_sms_get_list_query_data(query_data, msg_box_type);

        msg_num = srv_sms_query_msg_int(query_data, msg_id_list, max_list_size);

        *list_size = msg_num;

    #ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
        if (msg_box_type == SRV_SMS_BOX_UNSENT)
        {
            U32 i;

            for (i = 0; i < msg_num; i++)
            {
                U16 msg_id = msg_id_list[i];
            
                srv_sms_set_unsent_msg_status(msg_id, SRV_SMS_SEND_FAIL);
            }
        }
    #endif /* __SRV_SMS_BACKGROUND_SEND_SUPPORT__ */

        OslMfree(query_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_list_query_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_get_list_query_data(
                srv_sms_query_struct *query_data,
                srv_sms_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_box_type)
    {
        case SRV_SMS_BOX_INBOX:
        {
            query_data->folder_id = SRV_SMS_FOLDER_DEFAULT;
            query_data->query_flag = SRV_SMS_QUERY_STATUS;
            query_data->status = (srv_sms_status_enum)(SRV_SMS_STATUS_UNREAD | SRV_SMS_STATUS_READ);
        #ifdef __SRV_SMS_SIMBOX_SUPPORT__
            query_data->query_flag |= SRV_SMS_QUERY_STORAGE_TYPE;
            query_data->storage_type = SRV_SMS_STORAGE_ME;
        #endif /* __SRV_SMS_SIMBOX_SUPPORT__ */
            query_data->sort_flag = SRV_SMS_SORT_TIMESTAMP;
            query_data->order_flag = SRV_SMS_ORDER_DEFAULT;
            break;
        }

        case SRV_SMS_BOX_OUTBOX:
        {
            query_data->folder_id = SRV_SMS_FOLDER_DEFAULT;
            query_data->query_flag = SRV_SMS_QUERY_STATUS;
        #ifdef __SRV_SMS_UNSENT_LIST__
            query_data->status = SRV_SMS_STATUS_SENT;
        #else /* __SRV_SMS_UNSENT_LIST__ */
            query_data->status = SRV_SMS_STATUS_SENT | SRV_SMS_STATUS_UNSENT;
        #endif /* __SRV_SMS_UNSENT_LIST__ */
        #ifdef __SRV_SMS_SIMBOX_SUPPORT__
            query_data->query_flag |= SRV_SMS_QUERY_STORAGE_TYPE;
            query_data->storage_type = SRV_SMS_STORAGE_ME;
        #endif /* __SRV_SMS_SIMBOX_SUPPORT__ */
            break;
        }
        
        case SRV_SMS_BOX_DRAFTS:
        {
            query_data->folder_id = SRV_SMS_FOLDER_DEFAULT;
            query_data->query_flag = SRV_SMS_QUERY_STATUS;
            query_data->status = SRV_SMS_STATUS_DRAFT;
        #ifdef __SRV_SMS_SIMBOX_SUPPORT__
            query_data->query_flag |= SRV_SMS_QUERY_STORAGE_TYPE;
            query_data->storage_type = SRV_SMS_STORAGE_ME;
        #endif /* __SRV_SMS_SIMBOX_SUPPORT__ */
            break;
        }

    #ifdef __SRV_SMS_UNSENT_LIST__
        case SRV_SMS_BOX_UNSENT:
        {
            query_data->folder_id = SRV_SMS_FOLDER_DEFAULT;
            query_data->query_flag = SRV_SMS_QUERY_STATUS;
            query_data->status = SRV_SMS_STATUS_UNSENT;
        #ifdef __SRV_SMS_SIMBOX_SUPPORT__
            query_data->query_flag |= SRV_SMS_QUERY_STORAGE_TYPE;
            query_data->storage_type = SRV_SMS_STORAGE_ME;
        #endif /* __SRV_SMS_SIMBOX_SUPPORT__ */
            break;
        }
    #endif /* __SRV_SMS_UNSENT_LIST__ */

    #ifdef __SRV_SMS_SIMBOX_SUPPORT__
        case SRV_SMS_BOX_SIM:
        {
            query_data->folder_id = SRV_SMS_FOLDER_DEFAULT;
            query_data->query_flag = SRV_SMS_QUERY_STORAGE_TYPE;
            query_data->storage_type = SRV_SMS_STORAGE_SIM;
            break;
        }
    #endif /* __SRV_SMS_UNSENT_LIST__ */

    #ifdef __SRV_SMS_ARCHIVE__
        case SRV_SMS_BOX_ARCHIVE:
        {
            query_data->folder_id = SRV_SMS_FOLDER_ARCHIVE;
            break;
        }
    #endif /* __SRV_SMS_UNSENT_LIST__ */

        default:
            MMI_ASSERT(0);
            break;
    }

    query_data->sort_flag = SRV_SMS_SORT_TIMESTAMP;
    query_data->order_flag = SRV_SMS_ORDER_DEFAULT;
}


#if defined(__MMI_OP11_HOMESCREEN__) || defined(__MMI_VUI_HOMESCREEN__)
/*****************************************************************************
 * FUNCTION
 *  srv_sms_clear_all_sms_recent_event_flag
 * DESCRIPTION
 *  Clear All SMS Recent Event Flag
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_clear_all_sms_recent_event_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CLEAR_ALL_SMS_RECENT_EVENT_FLAG, srv_sms_inbox_size);

    for (i = 0; i < srv_sms_inbox_size; i++)
    {
        U16 msg_id = srv_sms_inbox_list[i];
    
        srv_sms_clear_msg_recent_event_flag(msg_id);
    }
}
#endif /* __MMI_OP11_HOMESCREEN_ || __MMI_VUI_HOMESCREEN___ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_list_usb_evt_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_sms_list_usb_evt_proc(mmi_event_struct *evt)
{
#if (defined(__SRV_SMS_ARCHIVE__) && defined(__MMI_USB_SUPPORT__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_hide_list_struct hide_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_FOLDER_LIST_USB_EVT_PROC, evt->evt_id);
    
    switch (evt->evt_id)
    {
        case EVT_ID_USB_ENTER_MS_MODE:
        {
            srv_sms_clear_list(SRV_SMS_BOX_ARCHIVE);
            hide_info.is_hidden = MMI_TRUE;
            break;
        }

        case EVT_ID_USB_EXIT_MS_MODE:
        {


            srv_sms_create_list(SRV_SMS_BOX_ARCHIVE);

            hide_info.is_hidden = MMI_FALSE;

            break;
        }

        default:
            return MMI_RET_OK;
    }
    
    hide_info.list_type = SRV_SMS_BOX_ARCHIVE;
    srv_sms_emit_event(EVT_ID_SRV_SMS_HIDE_LIST, &hide_info);
#endif /* (defined(__SRV_SMS_ARCHIVE__) && defined(__MMI_USB_SUPPORT__)) */

    return MMI_RET_OK;
}


#if (defined(__SRV_SMS_ARCHIVE__) && defined(__MMI_USB_SUPPORT__))
/*****************************************************************************
 * FUNCTION
 *  srv_sms_re_create_arch_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
 #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* (defined(__SRV_SMS_ARCHIVE__) && defined(__MMI_USB_SUPPORT__)) */

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_list_and_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_get_total_list_and_size(U16 **msg_id_list, U16 **msg_list_size, srv_sms_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_box_type)
    {
        case SRV_SMS_BOX_INBOX:
            *msg_id_list = srv_sms_inbox_total_list;
            *msg_list_size = &srv_sms_inbox_total_size;
            break;

        case SRV_SMS_BOX_OUTBOX:
            *msg_id_list = srv_sms_outbox_total_list;
            *msg_list_size = &srv_sms_outbox_total_size;
            break;

        case SRV_SMS_BOX_DRAFTS:
            *msg_id_list = srv_sms_drafts_total_list;
            *msg_list_size = &srv_sms_drafts_total_size;
            break;

    #ifdef __SRV_SMS_UNSENT_LIST__
        case SRV_SMS_BOX_UNSENT:
            *msg_id_list = srv_sms_unsent_total_list;
            *msg_list_size = &srv_sms_unsent_total_size;
            break;
    #endif /* __SRV_SMS_UNSENT_LIST__ */

        default:
            result = MMI_FALSE;
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_tcard_list_and_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
 MMI_BOOL srv_sms_get_show_list_and_size(U16 **msg_id_list, U16 **msg_list_size, srv_sms_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_box_type)
    {
        case SRV_SMS_BOX_INBOX:
            *msg_id_list = srv_sms_inbox_show_list;
            *msg_list_size = &srv_sms_inbox_show_size;
            break;

        case SRV_SMS_BOX_OUTBOX:
            *msg_id_list = srv_sms_outbox_show_list;
            *msg_list_size = &srv_sms_outbox_show_size;
            break;

        case SRV_SMS_BOX_DRAFTS:
            *msg_id_list = srv_sms_drafts_show_list;
            *msg_list_size = &srv_sms_drafts_show_size;
            break;

    #ifdef __SRV_SMS_UNSENT_LIST__
        case SRV_SMS_BOX_UNSENT:
            *msg_id_list = srv_sms_unsent_show_list;
            *msg_list_size = &srv_sms_unsent_show_size;
            break;
    #endif /* __SRV_SMS_UNSENT_LIST__ */
    #ifdef __SRV_SMS_SIMBOX_SUPPORT__
        case SRV_SMS_BOX_SIM:
            *msg_id_list = srv_sms_sim_list;
            *msg_list_size = &srv_sms_sim_size;
            break;
    #endif /* __SRV_SMS_SIMBOX_SUPPORT__ */

    #ifdef __SRV_SMS_ARCHIVE__
        case SRV_SMS_BOX_ARCHIVE:
            *msg_id_list = srv_sms_archive_list;
            *msg_list_size = &srv_sms_archive_size;
            break;
    #endif /* __SRV_SMS_ARCHIVE__ */

        default:
            result = MMI_FALSE;
            break;
    }

    return result;
}
MMI_BOOL srv_sms_get_tcard_list_and_size(U16 **msg_id_list, U16 **msg_list_size, srv_sms_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msg_box_type)
    {
        case SRV_SMS_BOX_INBOX:
            *msg_id_list = srv_sms_inbox_tcard_list;
            *msg_list_size = &srv_sms_inbox_tcard_size;
            break;

        case SRV_SMS_BOX_OUTBOX:
            *msg_id_list = srv_sms_outbox_tcard_list;
            *msg_list_size = &srv_sms_outbox_tcard_size;
            break;

        case SRV_SMS_BOX_DRAFTS:
            *msg_id_list = srv_sms_drafts_tcard_list;
            *msg_list_size = &srv_sms_drafts_tcard_size;
            break;

    #ifdef __SRV_SMS_UNSENT_LIST__
        case SRV_SMS_BOX_UNSENT:
            *msg_id_list = srv_sms_unsent_tcard_list;
            *msg_list_size = &srv_sms_unsent_tcard_size;
            break;
    #endif /* __SRV_SMS_UNSENT_LIST__ */


        default:
            result = MMI_FALSE;
            break;
    }

    return result;
}


void srv_sms_set_show_list(srv_sms_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    srv_sms_tcard_msg_node_struct *tcard_msg_node;
    srv_sms_msg_node_struct *msg_node;
    U16 msg_id;
    U16 msg_list_size = 0;
    srv_sms_storage_enum storage_type = SRV_SMS_STORAGE_UNSPECIFIC;
    srv_sms_filter_enum storage_filter;
    U16 *total_msg_list = NULL;
    U16 *total_box_size = NULL;
    U16 *show_msg_list = NULL;
    U16 *show_box_size = NULL;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    switch (msg_box_type)
    {
        case SRV_SMS_BOX_INBOX:
            show_msg_list = srv_sms_inbox_show_list;
            memset(srv_sms_inbox_show_list,0xff,SRV_SMS_MAX_TOTAL_SMS_ENTRY*2);
            show_box_size = &srv_sms_inbox_show_size;
            total_msg_list = srv_sms_inbox_total_list;
            total_box_size = &srv_sms_inbox_total_size;
            break;            
        case SRV_SMS_BOX_OUTBOX:
            show_msg_list = srv_sms_outbox_show_list;
            memset(srv_sms_outbox_show_list,0xff,SRV_SMS_MAX_TOTAL_SMS_ENTRY*2);
            show_box_size = &srv_sms_outbox_show_size;
            total_msg_list = srv_sms_outbox_total_list;
            total_box_size = &srv_sms_outbox_total_size;
            break;            
        case SRV_SMS_BOX_DRAFTS:
            show_msg_list = srv_sms_drafts_show_list;
            memset(srv_sms_drafts_show_list,0xff,SRV_SMS_MAX_TOTAL_SMS_ENTRY*2);
            show_box_size = &srv_sms_drafts_show_size;
            total_msg_list = srv_sms_drafts_total_list;
            total_box_size = &srv_sms_drafts_total_size;
            break; 
    #ifdef __SRV_SMS_UNSENT_LIST__
        case SRV_SMS_BOX_UNSENT:
            show_msg_list = srv_sms_unsent_show_list;
            memset(srv_sms_unsent_show_list,0xff,SRV_SMS_MAX_TOTAL_SMS_ENTRY*2);
            show_box_size = &srv_sms_unsent_show_size;
            total_msg_list = srv_sms_unsent_total_list;
            total_box_size = &srv_sms_unsent_total_size;
            break;
    #endif
        default:
            
            ASSERT(0);
            break;
    }
    storage_filter = srv_sms_get_storage_filter();
    if(storage_filter & SRV_SMS_STORAGE_TCARD && !storage_cntx.is_tcard_ready)
    {
        storage_filter = storage_filter & (~(SRV_SMS_FILTER_TCARD));
    }
//    kal_prompt_trace(MOD_MMI,"srv_sms_set_show_list storage_filter = %d",storage_filter);
    for(i = 0; i < *total_box_size ; i++)
    {
        msg_id = total_msg_list[i];
        storage_type = SRV_SMS_STORAGE_UNSPECIFIC;
        if(msg_id >= SRV_SMS_MAX_MSG_NUM && storage_cntx.is_tcard_ready)
        {
            tcard_msg_node = srv_sms_get_tcard_msg_node(msg_id - SRV_SMS_MAX_MSG_NUM);
            storage_type = tcard_msg_node->storage_type;
        }
        else
        {
            msg_node = srv_sms_get_msg_node(msg_id);
            storage_type = msg_node->storage_type;
        }
      
        switch (storage_filter)
        {
            case SRV_SMS_FILTER_ME:
                if(storage_type == SRV_SMS_STORAGE_ME)
                {
                    show_msg_list[msg_list_size] = msg_id;
                    msg_list_size++;

                }
                break;
            case SRV_SMS_FILTER_SIM:
                if(storage_type == SRV_SMS_STORAGE_SIM)
                {
                    show_msg_list[msg_list_size] = msg_id;
                    msg_list_size++;

                }
                
                break;
            case SRV_SMS_FILTER_TCARD:
                if(storage_type == SRV_SMS_STORAGE_TCARD)
                {
                    show_msg_list[msg_list_size] = msg_id;
                    msg_list_size++;

                }
                break;
            case SRV_SMS_FILTER_ME | SRV_SMS_FILTER_SIM:
                if((storage_type == SRV_SMS_STORAGE_ME)||(storage_type == SRV_SMS_STORAGE_SIM))
                {
                    show_msg_list[msg_list_size] = msg_id;
                    msg_list_size++;

                }
                
                break;
            case SRV_SMS_FILTER_ME | SRV_SMS_FILTER_TCARD:
                if((storage_type == SRV_SMS_STORAGE_ME)||(storage_type == SRV_SMS_STORAGE_TCARD))
                {
                    show_msg_list[msg_list_size] = msg_id;
                    msg_list_size++;

                }                        
                break;
            case SRV_SMS_FILTER_SIM | SRV_SMS_FILTER_TCARD:
                if((storage_type == SRV_SMS_STORAGE_SIM)||(storage_type == SRV_SMS_STORAGE_TCARD))
                {
                    show_msg_list[msg_list_size] = msg_id;
                    msg_list_size++;

                }                                 
                break;
            case SRV_SMS_FILTER_ALL:
                if(storage_type != SRV_SMS_STORAGE_UNSPECIFIC)
                {
                    show_msg_list[msg_list_size] = msg_id;
                    msg_list_size++;
                }
                

                break;
            default:
                ASSERT(0);
                break;
                
        }
    }
    *show_box_size = msg_list_size;
}

#endif
#endif /* __MOD_SMSAL__ */

