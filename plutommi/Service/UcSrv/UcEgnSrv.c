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
 * UcEgnSrv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements .......... Unified Composer.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_include.h"

#ifndef _UNIFIED_COMPOSER_ENGINE_SRV_C
#define _UNIFIED_COMPOSER_ENGINE_SRV_C

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

//#include "app_base64.h"
//#include "app_usedetails.h"
#include "app_str.h"

#include "mdi_datatype.h"
#include "mdi_audio.h"
#if defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_VIDEO_RECORDER__)
#include "mdi_video.h"
#endif 
#include "Conversions.h"
#include "SmsSrvGprot.h"
#include "Phbsrvgprot.h"
#include "med_api.h"
#include "app_oppostcard.h"
//#include "UmGprot.h"
#include "UcSrvGProt.h"
#include "UcSrvIprot.h"
#include "UcSrv.h"
#include "FileMgrGProt.h"
//suggested add
#include "MMIDataType.h"
    //#include "kal_general_types.h"
   // #include "customer_email_num.h"
    //#include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "string.h"
    #include "custom_phb_config.h"
    #include "Unicodexdcl.h"
    #include "MMI_features.h"
    #include "custom_uc_config.h"
    #include "mma_api.h"
    #include "kal_trace.h"
   // #include "MMI_common_app_trc.h"
    //#include "mmi_common_app_trc.h"
    #include "mma_struct.h"
    #include "fs_type.h"
    #include "fs_func.h"
    #include "FileMgrSrvGProt.h"
    #include "fs_errcode.h"
    #include "gui_config.h"
    #include "gdi_const.h"
    #include "gdi_datatype.h"
    #include "gdi_include.h"
    #include "lcd_sw_rnd.h"
    #include "kal_public_defs.h"


/*****************************************************************************
 * FUNCTION
 *  srv_uc_add_address
 * DESCRIPTION
 *  add address function
 * PARAMETERS
 *  instance        [IN]        
 *  ucs2_addr       [?]         
 *  type            [IN]        
 *  group           [IN]        
 * RETURNS
 *  TRUE means add successfully. Otherwise FALSE.
 *****************************************************************************/
MMI_BOOL srv_uc_add_address(
        U32 instance,
        U8 *ucs2_addr,
        srv_uc_address_type_enum type,
        srv_uc_address_group_type_enum group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uc_msg_struct *msg = &g_srv_uc_p[instance]->msg;
    srv_uc_addr_struct **addr_head = NULL;
    srv_uc_addr_struct *addr_tail = NULL;
    srv_uc_addr_struct *addr_new = NULL;
    U8 ascii_addr[SRV_UC_MAX_EMAIL_LEN + 1];
    U8 addr_num_calculated = 0;
    U8 *addr_num = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (group)
    {
        case SRV_UC_ADDRESS_GROUP_TYPE_TO:
        case SRV_UC_ADDRESS_GROUP_TYPE_CC:
        case SRV_UC_ADDRESS_GROUP_TYPE_BCC:
        {
            addr_tail = msg->to_head;
            addr_head = &(msg->to_head);
            addr_num = &(msg->to_num);
        }
            break;

        case SRV_UC_ADDRESS_GROUP_TYPE_FROM:
        {
            addr_tail = msg->from;
            addr_head = &(msg->from);
        }
            break;

        default:
        {
            MMI_ASSERT(0);
        }
            break;
    }

    if (type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
    {
        memset(ascii_addr, 0, sizeof(ascii_addr));
        mmi_ucs2_n_to_asc((S8*) ascii_addr, (S8*) ucs2_addr, SRV_UC_MAX_PHONE_NUMBER_LEN * ENCODING_LENGTH);
    }

    if (group != SRV_UC_ADDRESS_GROUP_TYPE_FROM)
    {
        if (addr_tail == NULL)
        {
            addr_num_calculated = 0;
        }
        else
        {
            addr_num_calculated = 1;

            for (; addr_tail->next != NULL; addr_tail = addr_tail->next)
            {
                addr_num_calculated++;
            }
        }

        MMI_ASSERT((addr_num_calculated == (*addr_num)));
    }

    addr_new = g_srv_uc_p[instance]->alloc(sizeof(srv_uc_addr_struct), g_srv_uc_p[instance]->user_data);

    MMI_ASSERT(addr_new);

    addr_new->type = type;
    addr_new->group = group;
    addr_new->next = NULL;

    if (addr_new->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
    {
        U16 len = strlen((char*)ascii_addr);

        if (len > SRV_UC_MAX_PHONE_NUMBER_LEN)
        {
            /* this path will not be run if previous mmi_ucs2_n_to_asc((S8*) ascii_addr, (S8*) ucs2_addr, SRV_UC_MAX_PHONE_NUMBER_LEN * ENCODING_LENGTH); */
            g_srv_uc_p[instance]->free(addr_new, g_srv_uc_p[instance]->user_data);
            return MMI_FALSE;
        }

        addr_new->addr = g_srv_uc_p[instance]->alloc(len + 1, g_srv_uc_p[instance]->user_data);
        MMI_ASSERT(addr_new->addr);

        memset(addr_new->addr, 0, len + 1);
        memcpy(addr_new->addr, ascii_addr, len);
    }
    else if (addr_new->type == SRV_UC_ADDRESS_TYPE_EMAIL)
    {
        U16 len = mmi_ucs2strlen((S8*) ucs2_addr);

        if (len > SRV_UC_MAX_EMAIL_LEN)
        {
            g_srv_uc_p[instance]->free(addr_new, g_srv_uc_p[instance]->user_data);
            return MMI_FALSE;
        }

        addr_new->addr = g_srv_uc_p[instance]->alloc((len + 1) * ENCODING_LENGTH, g_srv_uc_p[instance]->user_data);
        MMI_ASSERT(addr_new->addr);

        memset(addr_new->addr, 0, ((len + 1) * ENCODING_LENGTH));
        memcpy(addr_new->addr, ucs2_addr, (len * ENCODING_LENGTH));
    }
    else
    {
        MMI_ASSERT(0);
    }

    /* First entry */
    if (addr_tail == NULL)
    {
        addr_new->previous = NULL;

        *addr_head = addr_new;
    }
    else
    {
        addr_new->previous = addr_tail;
        addr_tail->next = addr_new;
    }

    if (group != SRV_UC_ADDRESS_GROUP_TYPE_FROM)
    {
        (*addr_num) = (*addr_num) + 1;
    }

    return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_change_addr_group_if_needed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  check_addr      [?]     
 *  dup_addr        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uc_change_addr_group_if_needed(srv_uc_addr_struct *check_addr, srv_uc_addr_struct *dup_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dup_addr->group == SRV_UC_ADDRESS_GROUP_TYPE_TO)
    {
        check_addr->group = SRV_UC_ADDRESS_GROUP_TYPE_TO;
    }
    else if (check_addr->group == SRV_UC_ADDRESS_GROUP_TYPE_BCC && dup_addr->group == SRV_UC_ADDRESS_GROUP_TYPE_CC)
    {
        check_addr->group = SRV_UC_ADDRESS_GROUP_TYPE_CC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_remove_duplicate_entries
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_uc_remove_duplicate_entries(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uc_addr_struct *check_addr = g_srv_uc_p[instance]->msg.to_head;
    srv_uc_addr_struct *start_addr, *delete_addr;
    //int count = 0;
    U16 addr1[SRV_UC_MAX_PHONE_NUMBER_LEN + 1] = {0,};
    U16 addr2[SRV_UC_MAX_PHONE_NUMBER_LEN + 1] = {0,};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (check_addr != NULL)
    {
        start_addr = check_addr->next;
        if (check_addr->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
        {
            while (start_addr != NULL)
            {
                if (start_addr->type != SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
                {
                    start_addr = start_addr->next;
                    continue;
                }
                else
                {
                    mmi_asc_to_ucs2((PS8) addr1, (PS8) check_addr->addr);
                    mmi_asc_to_ucs2((PS8) addr2, (PS8) start_addr->addr);
                    if (srv_phb_compare_number(addr1, addr2) == MMI_TRUE)
                    {
                        srv_uc_change_addr_group_if_needed(check_addr, start_addr);
                        delete_addr = start_addr;
                        start_addr = start_addr->next;
                        srv_uc_delete_addr(instance, delete_addr);
                    }
                    else
                    {
                        start_addr = start_addr->next;
                    }
                }
            }
        }
        else
        {
            while (start_addr != NULL)
            {
                if (start_addr->type != SRV_UC_ADDRESS_TYPE_EMAIL)
                {
                    start_addr = start_addr->next;
                    continue;
                }
                else
                {
                    if (srv_uc_compare_string_ignore_case((U16*) check_addr->addr, (U16*) start_addr->addr) ==
                        MMI_TRUE)
                    {
                        srv_uc_change_addr_group_if_needed(check_addr, start_addr);
                        delete_addr = start_addr;
                        start_addr = start_addr->next;
                        srv_uc_delete_addr(instance, delete_addr);
                    }
                    else
                    {
                        start_addr = start_addr->next;
                    }
                }
            }
        }
        check_addr = check_addr->next;
    }
	return MMI_TRUE ;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_max_mo_sms_segment
 * DESCRIPTION
 *  Determine max sms segment supported
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 srv_uc_get_max_mo_sms_segment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __EMS_DYNAMIC_SEG_NUM__
	if (srv_sms_is_long_sms_dynamic_seg_setting(SRV_SMS_SIM_1) == MMI_TRUE)
    {
        return mmi_uc_custom_get_max_mo_sms_segment();
    }
    else
    {
        return (kal_uint8) 1;   /* 1 can be change with any macro value. */
    }
#else /* __EMS_DYNAMIC_SEG_NUM__ */ 
    return mmi_uc_custom_get_max_mo_sms_segment();
#endif /* __EMS_DYNAMIC_SEG_NUM__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_update_msg_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_update_msg_size(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_uc_p[instance]->send_info.existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER &&
        (g_srv_uc_p[instance]->main.state == SRV_UC_STATE_FORWARD ||
         g_srv_uc_p[instance]->main.state == SRV_UC_STATE_SEND))
    {
        g_srv_uc_p[instance]->msg.msg_size = mma_uc_calc_header_size(
                                                &g_srv_uc_p[instance]->msg,
                                                srv_uc_get_mms_type(instance)) + g_srv_uc_p[instance]->msg.msg_body_size;
    }
    else
    {
        g_srv_uc_p[instance]->msg.msg_size = mma_uc_calc_msg_size(&g_srv_uc_p[instance]->msg, srv_uc_get_mms_type(instance));

    }

    if (g_srv_uc_p[instance]->msg.msg_body.curr_slide)
    {
        g_srv_uc_p[instance]->msg.msg_size_without_text_buffer =
            g_srv_uc_p[instance]->msg.msg_size - g_srv_uc_p[instance]->msg.msg_body.curr_slide->txt.utf8_msg_len;
    }
    else
    {
        g_srv_uc_p[instance]->msg.msg_size_without_text_buffer = g_srv_uc_p[instance]->msg.msg_size;
    }

    MMI_TRACE(
        MMI_COMMON_TRC_G6_MSG,
        TRC_MMI_UC_UPDATE_MSG_SIZE_P2,
        g_srv_uc_p[instance]->msg.msg_size,
        g_srv_uc_p[instance]->msg.msg_size_without_text_buffer);

    MMI_ASSERT(g_srv_uc_p[instance]->msg.msg_size_without_text_buffer <= g_srv_uc_p[instance]->msg.msg_size);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_delete_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  address         [?]         
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_delete_addr(kal_uint32 instance, srv_uc_addr_struct *address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uc_addr_struct *addr = address;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (addr->group)
    {
        case SRV_UC_ADDRESS_GROUP_TYPE_TO:
        case SRV_UC_ADDRESS_GROUP_TYPE_CC:
        case SRV_UC_ADDRESS_GROUP_TYPE_BCC:
        {
            if (g_srv_uc_p[instance]->msg.to_num == 1)
            {
                g_srv_uc_p[instance]->msg.to_num = 0;
                g_srv_uc_p[instance]->msg.to_head = NULL;
            }
            else
            {
                g_srv_uc_p[instance]->msg.to_num--;

                /* The first entry */
                if (addr == g_srv_uc_p[instance]->msg.to_head)
                {
                    g_srv_uc_p[instance]->msg.to_head = addr->next;
                    addr->next->previous = NULL;
                }
                /* The last entry */
                else if (addr->next == NULL)
                {
                    addr->previous->next = NULL;
                }
                else
                {
                    addr->next->previous = addr->previous;
                    addr->previous->next = addr->next;
                }
            }
        }
            break;

        case SRV_UC_ADDRESS_GROUP_TYPE_FROM:
        {
            srv_uc_free_addr_memory(instance, addr);
            g_srv_uc_p[instance]->msg.from = NULL;
            return MMI_TRUE;
        }
            

        default:
        {
            MMI_ASSERT(0);
        }
            break;
    }
    srv_uc_free_addr_memory(instance, addr);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_delete_all_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_delete_all_addr(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uc_addr_struct *addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        addr = g_srv_uc_p[instance]->msg.to_head;
        if (addr != NULL)
        {
            srv_uc_delete_addr(instance, addr);
        }
        else
        {
            break;
        }
    } while (TRUE);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_insert_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  cur_slide       [?]         
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_slide_struct *srv_uc_insert_slide(U32 instance, mma_mms_slide_struct *cur_slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *new_slide;
    U32 slide_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    slide_size = sizeof(mma_mms_slide_struct);
    new_slide = g_srv_uc_p[instance]->alloc(slide_size, g_srv_uc_p[instance]->user_data);
    MMI_ASSERT(new_slide);
    memset(new_slide, 0, slide_size);
    new_slide->txt.bg_color = SRV_UC_DEFAULT_BG_COLOR;
    new_slide->txt.fg_color = SRV_UC_DEFAULT_FG_COLOR;

    g_srv_uc_p[instance]->msg.msg_body.slide_no++;
    new_slide->duration = g_srv_uc_p[instance]->mms_info.sliding_time.value;

    MMI_ASSERT(g_srv_uc_p[instance]->msg.msg_body.slide_no <= SRV_UC_MAX_MMS_SLIDE_NUM);

    /* First slide */
    if (cur_slide == NULL)
    {
        /* MMI_ASSERT( g_srv_uc_p[instance]->msg.total_slide_num == 1 ); */
        new_slide->next = g_srv_uc_p[instance]->msg.msg_body.slides;
        new_slide->prev = NULL;

        if (g_srv_uc_p[instance]->msg.msg_body.slides)
        {
            g_srv_uc_p[instance]->msg.msg_body.slides->prev = new_slide;
        }

        g_srv_uc_p[instance]->msg.msg_body.slides = new_slide;

        new_slide->slide_num = 1;

        if (new_slide->next)
        {
            mma_mms_slide_struct *update_slide = srv_uc_get_end_slide(instance);

            while (update_slide != new_slide)
            {
                if (update_slide != NULL)
                {
                    update_slide->slide_num++;
                    srv_uc_update_text_object_path(instance, update_slide);
                    update_slide = update_slide->prev;
                }
            }
        }
    }
    else
    {
        new_slide->slide_num = cur_slide->slide_num + 1;

        new_slide->next = cur_slide->next;
        new_slide->prev = cur_slide;

        if (cur_slide->next)
        {
            mma_mms_slide_struct *update_slide = srv_uc_get_end_slide(instance);

            cur_slide->next->prev = new_slide;

            while (update_slide != new_slide)
            {
				if (update_slide != NULL)
				{
					update_slide->slide_num++;
                    srv_uc_update_text_object_path(instance, update_slide);
                    update_slide = update_slide->prev;
                }
            }
        }
        cur_slide->next = new_slide;
    }

    return new_slide;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_insert_object_to_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  object          [?]         
 *  slide           [?]         
 *  object_type     [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_insert_object_to_slide(
        U32 instance,
        mma_mms_object_struct *object,
        mma_mms_slide_struct *slide,
        srv_uc_object_type object_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (object_type)
    {
        case SRV_UC_OBJECT_TYPE_IMAGE:
        {
            slide->img.object = object;
            slide->img.begin = 0;
            slide->img.end = slide->duration;
            object->reference_count++;
        }
            break;

        case SRV_UC_OBJECT_TYPE_AUDIO:
        {
            U32 file_duration = 0;
            U16 *extension = srv_uc_get_file_extension((U16 *)object->file_path_ucs);

            slide->aud.object = object;
            /* 1. check media file duration */
            /* Put the following in app */
            if (g_srv_uc_p[instance]->msg.best_page_duration && ((g_srv_uc_p[instance]->main.state != SRV_UC_STATE_EDIT_EXISTED_MSG)    /* || 
                ((g_srv_uc_p[instance]->main.state == SRV_UC_STATE_EDIT_EXISTED_MSG) && IsScreenPresent(SCR_ID_UC_EDITOR)) */
                )
                /*&& !(extension && (app_ucs2_strcmp((const kal_int8*)extension, (const kal_int8*)L"mid") == 0 ||
                     app_ucs2_strcmp((const kal_int8*)extension, (const kal_int8*)L"aac") == 0))*/)
                /*            if ((g_srv_uc_p[instance]->msg.best_page_duration && 
                   ((g_srv_uc_p[instance]->main.state != SRV_UC_STATE_EDIT_EXISTED_MSG) || 
                   ((g_srv_uc_p[instance]->main.state == SRV_UC_STATE_EDIT_EXISTED_MSG) && IsScreenPresent(SCR_ID_UC_EDITOR))
                   && !(app_ucs2_strcmp((const kal_int8*) extension, (const kal_int8*) L"mid") == 0 || 
                   app_ucs2_strcmp((const kal_int8*) extension, (const kal_int8*) L"aac") == 0)) */
            {
                if (mdi_audio_get_duration(slide->aud.object->file_path_ucs, &(file_duration)) != MDI_AUDIO_SUCCESS)
                {
                    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_INSERT_OBJ_TO_SLIDE_AUDIO_FAIL);
                    file_duration = 0;
                }
                else
                {
                    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_INSERT_OBJ_TO_SLIDE_AUDIO_DUR_P1, file_duration);
                    file_duration = (file_duration / 1000);
                }

                /* 2. update start, duration and end time */
                slide->aud.begin = 0;
                if (slide->duration < file_duration)
                {
                    slide->duration = slide->aud.begin + file_duration;
                    slide->aud.end = slide->duration;
                }
                else
                {
                    slide->aud.end = slide->duration;
                }
            }
            else    /* If best page is disable or edit existed msg */
            {
                slide->aud.begin = SRV_UC_INVALID_VALUE;
                slide->aud.end = SRV_UC_INVALID_VALUE;
            }
            /* 3. increase ref count */
            object->reference_count++;
        }
            break;

        case SRV_UC_OBJECT_TYPE_VIDEO:
        {
        #ifdef __MMI_VIDEO_PLAY_SUPPORT__
            mdi_video_info_struct vdo_info;
            MDI_RESULT result;
        #endif /* __MMI_VIDEO_PLAY_SUPPORT__ */ 
            U32 file_duration = 0;

            slide->vid.object = object;

            /* 1. check media file duration */
            if (g_srv_uc_p[instance]->msg.best_page_duration && ((g_srv_uc_p[instance]->main.state != SRV_UC_STATE_EDIT_EXISTED_MSG)    /* || 
                                                                                                                                           ((g_srv_uc_p[instance]->main.state == SRV_UC_STATE_EDIT_EXISTED_MSG) && IsScreenPresent(SCR_ID_UC_EDITOR)) */
                                                                 ))
            {
        #ifdef __MMI_VIDEO_PLAY_SUPPORT__
                mdi_video_ply_enable_aud_only_video_clip();
            #ifdef __COSMOS_MMI_PACKAGE__
				mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_CIF);
                result = mdi_video_ply_open_clip_file(g_srv_uc_p[instance]->main.app_id, (PS8) slide->vid.object->file_path_ucs, &vdo_info);
            #else
                result = mdi_video_ply_open_clip_file(0, (PS8) slide->vid.object->file_path_ucs, &vdo_info);
            #endif /* __COSMOS_MMI_PACKAGE__ */
                if (result < 0)
                {
                    file_duration = 0;
                    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_INSERT_OBJ_TO_SLIDE_VIDEO_FAIL);
                }
                else
                {
                    mdi_video_ply_close_clip_file();
                    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_INSERT_OBJ_TO_SLIDE_VIDEO_DUR_P1, file_duration);
                    file_duration = (S32) (vdo_info.total_time_duration / 1000);
                }
        #endif /* __MMI_VIDEO_PLAY_SUPPORT__ */ 

                /* 2. update start, duration and end time */
                slide->vid.begin = 0;
                if (slide->duration < file_duration)
                {
                    slide->duration = slide->vid.begin + file_duration;
                    slide->vid.end = slide->duration;
                }
                else
                {
                    slide->vid.end = slide->duration;
                }
            }
            else    /* If best page is disable or edit existed msg */
            {
                slide->vid.begin = SRV_UC_INVALID_VALUE;
                slide->vid.end = SRV_UC_INVALID_VALUE;
            }
            object->reference_count++;
        }
            break;

        case SRV_UC_OBJECT_TYPE_TEXT:
        {
            slide->txt.object = object;
            slide->txt.begin = SRV_UC_INVALID_VALUE;
            slide->txt.end = SRV_UC_INVALID_VALUE;
            object->reference_count++;
        }
            break;

        default:
        {
            MMI_ASSERT(0);
        }
            break;
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_uc_set_media_duration
 * DESCRIPTION
 *  Set the media duration for media for which duration in not set
 * PARAMETERS
 *  mma_mms_slide_struct   [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uc_set_media_duration(mma_mms_slide_struct *slide_head)
{
	mma_mms_slide_struct *slide = slide_head ;
	while(slide)
	{
		if(slide->img.object 
            #ifndef __MMI_SLIM_MMS_2__
            && (slide->img.begin == SRV_UC_INVALID_VALUE || slide->img.end == SRV_UC_INVALID_VALUE)
            #endif
                )
		{
			slide->img.begin = 0 ;
			slide->img.end = slide->duration ;
		}

		if(slide->aud.object 
            #ifndef __MMI_SLIM_MMS_2__
            && (slide->aud.begin == SRV_UC_INVALID_VALUE || slide->aud.end == SRV_UC_INVALID_VALUE)
            #endif
                )
		{
			slide->aud.begin = 0 ;
			slide->aud.end = slide->duration ;
		}

		if(slide->vid.object
            #ifndef __MMI_SLIM_MMS_2__
            && (slide->vid.begin == SRV_UC_INVALID_VALUE || slide->vid.end == SRV_UC_INVALID_VALUE)
            #endif
                )
		{
			slide->vid.begin = 0 ;
			slide->vid.end = slide->duration ;
		}
		
		if(slide->txt.object 
            #ifndef __MMI_SLIM_MMS_2__
            && (slide->txt.begin == SRV_UC_INVALID_VALUE || slide->txt.end == SRV_UC_INVALID_VALUE)
            #endif
                )
		{
			slide->txt.begin = 0 ;
			slide->txt.end = slide->duration ;
		}
		slide = slide->next ;
	}
}
/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_to_mms_layout_type
 * DESCRIPTION
 *  Insert object
 * PARAMETERS
 *  layout_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_uc_convert_to_mms_layout_type(mma_slide_layout_enum layout_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (layout_type)
    {
        case MMA_LAYOUT_NONE:
        {
            return MMA_LAYOUT_IMAGE_ON_TOP;
        }
           

        case MMA_LAYOUT_IMAGE_ON_TOP:
        {
            return MMA_LAYOUT_IMAGE_ON_TOP;
        }
            

        case MMA_LAYOUT_TEXT_ON_TOP:
        {
            return MMA_LAYOUT_TEXT_ON_TOP;
        }
            

        default:
        {
            //MMI_ASSERT(0);
        }
            
    }

    return MMA_LAYOUT_IMAGE_ON_TOP;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_mms_layout_type_to_uc
 * DESCRIPTION
 *  Insert object
 * PARAMETERS
 *  layout_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_uc_convert_mms_layout_type_to_uc(U8 layout_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (layout_type)
    {
        case MMA_LAYOUT_NONE:
        {
            return MMA_LAYOUT_NONE;
        }
            

        case MMA_LAYOUT_IMAGE_ON_TOP:
        {
            return MMA_LAYOUT_IMAGE_ON_TOP;
        }
            

        case MMA_LAYOUT_TEXT_ON_TOP:
        {
            return MMA_LAYOUT_TEXT_ON_TOP;
        }
            

        default:
        {

        }
            break;
    }

    return MMA_LAYOUT_IMAGE_ON_TOP;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_mms_region_fit_enum_to_uc
 * DESCRIPTION
 *  convert mms region fit enum to uc fit enum
 * PARAMETERS
 *  region_fit      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_uc_convert_mms_region_fit_enum_to_uc(U8 region_fit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
return region_fit;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filePath        [?]     
 * RETURNS
 *  
 *****************************************************************************/
U16 *srv_uc_get_file_name(U16 *filePath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 file_path_len = mmi_ucs2strlen((S8*) filePath);
    U16 *cur_position;
    U16 *pre_position;
    S32 i = file_path_len - 1;
    U8 pattern[3 * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pattern, 0, sizeof(pattern));
    mmi_asc_n_to_ucs2((S8*) pattern, "\\", 1);

    for (; i >= 0; i--)
    {
        cur_position = &(filePath[i]);
        pre_position = cur_position - 1;
        if (mmi_ucs2ncmp((S8*) pre_position, (S8*) pattern, 1) == 0)
        {
            return cur_position;
        }
    }
    return filePath;
}

extern kal_uint32 applib_get_file_size(kal_wchar *filename);
/*****************************************************************************
 * FUNCTION
 *  srv_uc_insert_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  filePath        [?]         
 *  object_type     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_object_struct *srv_uc_insert_object(U32 instance, S8 *filePath, srv_uc_object_type object_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *new_object;
    U16 *file_name;
    U32 object_size;
    U16 file_path_len = mmi_ucs2strlen(filePath);
    U16 file_name_len = 0;
    U8 counter = 0;
    mma_mms_object_struct *curr_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    object_size = sizeof(mma_mms_object_struct);
    new_object = g_srv_uc_p[instance]->alloc(object_size, g_srv_uc_p[instance]->user_data);
    MMI_ASSERT(new_object);
    memset(new_object, 0, object_size);

    /* file path */
    new_object->file_path_ucs = (kal_wchar *)g_srv_uc_p[instance]->alloc((file_path_len + 1) * 2, g_srv_uc_p[instance]->user_data);
    MMI_ASSERT(new_object->file_path_ucs);
    memset(new_object->file_path_ucs, 0, (file_path_len + 1) * 2);
    mmi_ucs2ncpy((S8*) new_object->file_path_ucs, (S8*) filePath, file_path_len);

    /* file name */
    file_name = srv_uc_get_file_name((U16*) filePath);
    file_name_len = mmi_ucs2strlen((S8*) file_name);
    new_object->file_name_ucs = (kal_wchar *)g_srv_uc_p[instance]->alloc((file_name_len + 1) * 2, g_srv_uc_p[instance]->user_data);
    MMI_ASSERT(new_object->file_name_ucs);
    memset(new_object->file_name_ucs, 0, (file_name_len + 1) * 2);
    mmi_ucs2ncpy((S8*) new_object->file_name_ucs, (S8*) file_name, file_name_len);

    /* type */
#ifdef __MMI_UC_REF__
    if (srv_uc_is_in_ref_obj_type_range((S8*) filePath))
    {
        new_object->type = MMA_MMS_OBJECT_TYPE_REF;
    }
    else
#endif /* __MMI_UC_REF__ */ 
    {
        new_object->type = object_type;
    }
    /* size */
    new_object->size = applib_get_file_size((kal_wchar*) filePath);

    /* Default value! caller should update these value if necessary. */
    new_object->offset = 0;
    new_object->drm_type = MMA_DRM_NONE;
    new_object->is_virtual_file = MMI_FALSE;

    g_srv_uc_p[instance]->msg.msg_body.obj_no++;

    /* First object */
    if (g_srv_uc_p[instance]->msg.msg_body.objects == NULL)
    {
        g_srv_uc_p[instance]->msg.msg_body.objects = new_object;
        new_object->next = NULL;
        new_object->prev = NULL;
    }
    else
    {
        /* Insert new object in the list head */
        curr_object = g_srv_uc_p[instance]->msg.msg_body.objects;
        new_object->prev = NULL;
        for (; curr_object->next != NULL; curr_object = curr_object->next)
        {
            curr_object->id = counter++;
        }
        curr_object->id = counter++;
        curr_object->next = new_object;
        new_object->next = NULL;
        new_object->prev = curr_object;
        new_object->id = counter;
    }
    return new_object;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_insert_object_virtual_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  filePath        [?]         
 *  object_type     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_object_struct *srv_uc_insert_object_virtual_file(U32 instance, S8 *file_name, S8 *filePath, srv_uc_object_type object_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *new_object;
   // U16 *file_name;
    U32 object_size;
    U16 file_path_len = mmi_ucs2strlen(filePath);
    U16 file_name_len = 0;
    mma_mms_object_struct *curr_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    object_size = sizeof(mma_mms_object_struct);
    new_object = g_srv_uc_p[instance]->alloc(object_size, g_srv_uc_p[instance]->user_data);
    MMI_ASSERT(new_object);
    memset(new_object, 0, object_size);

    /* file path */
    new_object->file_path_ucs = (kal_wchar *)g_srv_uc_p[instance]->alloc((file_path_len + 1) * 2, g_srv_uc_p[instance]->user_data);
    MMI_ASSERT(new_object->file_path_ucs);
    memset(new_object->file_path_ucs, 0, (file_path_len + 1) * 2);
    mmi_ucs2ncpy((S8*) new_object->file_path_ucs, (S8*) filePath, file_path_len);

    /* file name */
  //  file_name = srv_uc_get_file_name((U16*) filePath);
    file_name_len = mmi_ucs2strlen((S8*) file_name);
    new_object->file_name_ucs = (kal_wchar *)g_srv_uc_p[instance]->alloc((file_name_len + 1) * 2, g_srv_uc_p[instance]->user_data);
    MMI_ASSERT(new_object->file_name_ucs);
    memset(new_object->file_name_ucs, 0, (file_name_len + 1) * 2);
    mmi_ucs2ncpy((S8*) new_object->file_name_ucs, (S8*) file_name, file_name_len);

    /* type */
#ifdef __MMI_UC_REF__
    if (srv_uc_is_in_ref_obj_type_range((S8*) filePath))
    {
        new_object->type = MMA_MMS_OBJECT_TYPE_REF;
    }
    else
#endif /* __MMI_UC_REF__ */ 
    {
        new_object->type = object_type;
    }

    /* Default value! caller should update these value if necessary. */
    new_object->offset = 0;
    new_object->drm_type = MMA_DRM_NONE;
    new_object->is_virtual_file = MMI_TRUE;

    g_srv_uc_p[instance]->msg.msg_body.obj_no++;

    /* First object */
    if (g_srv_uc_p[instance]->msg.msg_body.objects == NULL)
    {
        g_srv_uc_p[instance]->msg.msg_body.objects = new_object;
        new_object->next = NULL;
        new_object->prev = NULL;
    }
    else
    {
        /* Insert new object in the list head */
        curr_object = g_srv_uc_p[instance]->msg.msg_body.objects;
        new_object->prev = NULL;
        for (; curr_object->next != NULL; curr_object = curr_object->next)
        {
        }
        curr_object->next = new_object;
        new_object->next = NULL;
        new_object->prev = curr_object;

    }
    return new_object;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_insert_attachment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_attachment_info_struct *srv_uc_insert_attachment(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_attachment_info_struct *new_attach;
    U32 attach_size;
    U32 i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    attach_size = sizeof(mma_mms_attachment_info_struct);
    new_attach = g_srv_uc_p[instance]->alloc(attach_size, g_srv_uc_p[instance]->user_data);
    MMI_ASSERT(new_attach);
    memset(new_attach, 0, attach_size);

    if (g_srv_uc_p[instance]->msg.msg_body.total_attach_no == 0 || g_srv_uc_p[instance]->msg.msg_body.attachment == NULL)
    {
        MMI_ASSERT(g_srv_uc_p[instance]->msg.msg_body.attachment == NULL);
        g_srv_uc_p[instance]->msg.msg_body.attachment = new_attach;

        new_attach->next = NULL;
        new_attach->prev = NULL;
    }
    else
    {
        mma_mms_attachment_info_struct *cur_attach = g_srv_uc_p[instance]->msg.msg_body.attachment;

        MMI_ASSERT(cur_attach);

        for (; cur_attach->next != NULL; cur_attach = cur_attach->next)
        {
            i++;
        }
        cur_attach->next = new_attach;
        new_attach->next = NULL;
        new_attach->prev = cur_attach;
    }

    g_srv_uc_p[instance]->msg.msg_body.total_attach_no++;

    return new_attach;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_insert_object_to_attachment
 * DESCRIPTION
 *  
 * PARAMETERS
 *  object          [?]     
 *  attachment      [?]     
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_insert_object_to_attachment(mma_mms_object_struct *object, mma_mms_attachment_info_struct *attachment)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    attachment->object = object;
    object->reference_count++;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_delete_object_from_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  object          [?]         
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_delete_object_from_list(U32 instance, mma_mms_object_struct *object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (object == g_srv_uc_p[instance]->msg.msg_body.objects)
    {
        g_srv_uc_p[instance]->msg.msg_body.objects = object->next;

        if (object->next)
        {
            object->next->prev = NULL;
        }
    }
    else
    {
        object->prev->next = object->next;

        if (object->next)
        {
            object->next->prev = object->prev;
        }
    }
    g_srv_uc_p[instance]->msg.msg_body.obj_no--;

    if (object->file_name_ucs)
    {
        g_srv_uc_p[instance]->free(object->file_name_ucs, g_srv_uc_p[instance]->user_data);
		object->file_name_ucs = NULL ;
    }

    if (object->file_path_ucs)
    {
        if(object->auto_delete_file)
        {
            FS_Delete((WCHAR*) object->file_path_ucs);
        }
        g_srv_uc_p[instance]->free(object->file_path_ucs, g_srv_uc_p[instance]->user_data);
		object->file_path_ucs = NULL ;
    }

    g_srv_uc_p[instance]->free(object, g_srv_uc_p[instance]->user_data);
	object = NULL ;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_delete_ref_obj_info_from_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  cur_ref         [?]         
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_delete_ref_obj_info_from_list(U32 instance, mma_mms_slide_ref_object_struct *cur_ref)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_ref->prev->next = cur_ref->next;

    if (cur_ref->next)
    {
        cur_ref->next->prev = cur_ref->prev;
    }

    g_srv_uc_p[instance]->msg.msg_body.total_attach_no--;

    g_srv_uc_p[instance]->free(cur_ref, g_srv_uc_p[instance]->user_data);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_delete_ref_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  index           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_uc_delete_ref_by_index(U32 instance, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *slide = g_srv_uc_p[instance]->msg.msg_body.slides;
    mma_mms_slide_ref_object_struct *curr_ref = NULL;
    U16 i = 0;
    U16 curr_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_srv_uc_p[instance]->msg.msg_body.slides);
    MMI_ASSERT(index < g_srv_uc_p[instance]->msg.msg_body.total_ref_no);

    for (i = 0; i < g_srv_uc_p[instance]->msg.msg_body.slide_no; i++)
    {
        if (slide->ref_items != NULL)
        {
            curr_ref = slide->ref_items;
            while (curr_ref != NULL)
            {
                if (curr_index == index)
                {
                    /* should remove this ref_info_obj from ref_head list */

                    if (slide->ref_items == curr_ref)
                    {
                        slide->ref_items = curr_ref->next;

                        if (curr_ref->next)
                        {
                            curr_ref->next->prev = NULL;
                        }
                        g_srv_uc_p[instance]->msg.msg_body.total_attach_no--;
                        g_srv_uc_p[instance]->free(curr_ref, g_srv_uc_p[instance]->user_data);
                    }
                    else
                    {
                        srv_uc_delete_ref_obj_info_from_list(instance, curr_ref);
                    }
                    return MMI_TRUE;
                }
                curr_index++;
                curr_ref = curr_ref->next;
            }
        }
        slide = slide->next;
    }
    MMI_ASSERT(0);  /* should be found in ref list */
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_delete_attachment_from_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  att             [?]         
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_delete_attachment_from_list(U32 instance, mma_mms_attachment_info_struct *att)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (att == g_srv_uc_p[instance]->msg.msg_body.attachment)
    {
        g_srv_uc_p[instance]->msg.msg_body.attachment = att->next;

        if (att->next)
        {
            att->next->prev = NULL;
        }
    }
    else
    {
        att->prev->next = att->next;

        if (att->next)
        {
            att->next->prev = att->prev;
        }
    }
    g_srv_uc_p[instance]->msg.msg_body.total_attach_no--;

    g_srv_uc_p[instance]->free(att, g_srv_uc_p[instance]->user_data);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_init_uc_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_uc_init_uc_folder(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 result = FS_NO_ERROR;
    U8 srv_uc_folder_path[SRV_UC_MAX_TEMP_FILE_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(srv_uc_folder_path, 0, SRV_UC_MAX_TEMP_FILE_LEN);
    SRV_UC_MAKE_FOLDER_PATH(srv_uc_folder_path, instance);

    /* if the dir exists, delete it */
    file_handle = FS_Open((WCHAR*) srv_uc_folder_path, FS_OPEN_DIR | FS_READ_ONLY);
    if (file_handle >= 0)
    {
        FS_Close(file_handle);
		if(FS_Count((WCHAR*) srv_uc_folder_path, FS_FILE_TYPE, NULL, 0) > 0)
		{
			FS_XDelete((WCHAR*) srv_uc_folder_path, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
		}
		else
		{
			    FS_SetAttributes((unsigned short*)srv_uc_folder_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
				return result;
		}
    }

    result = FS_CreateDir((WCHAR*) srv_uc_folder_path);

    if (result < 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_INIT_UC_FOLDER_CREATE_FAIL);
    }

    FS_SetAttributes((unsigned short*)srv_uc_folder_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_check_uc_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_uc_check_uc_folder(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 srv_uc_folder_path[SRV_UC_MAX_TEMP_FILE_LEN];
    S32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CHECK_UC_FOLDER);

    memset(srv_uc_folder_path, 0, SRV_UC_MAX_TEMP_FILE_LEN);
    SRV_UC_MAKE_FOLDER_PATH(srv_uc_folder_path, instance);

    /* Check if the UC folder is created successfully. */
    /* user FS_GetAttributes, not use fs_open to check, because need to check if the it's a folder or not */
    result = FS_GetAttributes((WCHAR*) srv_uc_folder_path);

    if (result < 0)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CHECK_UC_FOLDER_NOT_EXIST);

        /* Try to create folder again besides srv_uc_init_uc_folder. */
        result = FS_CreateDir((WCHAR*) srv_uc_folder_path);

        /* Disallow to enter UC if UC folder cannot be created. */
        if (result < 0)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CHECK_UC_FOLDER_CREATE_FAIL_P1, result);
        }
        else
        {
            FS_SetAttributes((unsigned short*)srv_uc_folder_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
        }
        return result;
    }
    else if ((result & FS_ATTR_DIR) == 0x0)
    {
        /* Not directory, just a same path and name non-folder file , do error handling Here */
        FS_Delete((WCHAR*) srv_uc_folder_path);

        result = FS_CreateDir((WCHAR*) srv_uc_folder_path);

        /* Disallow to enter UC if UC folder cannot be created. */
        if (result < 0)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CHECK_UC_FOLDER_CREATE_FAIL_P1, result);

        }
        else
        {
            FS_SetAttributes((unsigned short*)srv_uc_folder_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
        }

        return result;
    }
    else
    {
        /* file exist */
        return result;

    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_delete_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  slide           [?]         
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_delete_slide(U32 instance, mma_mms_slide_struct *slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slide == g_srv_uc_p[instance]->msg.msg_body.slides)
    {
        g_srv_uc_p[instance]->msg.msg_body.slides = slide->next;

        if (slide->next)
        {
            slide->next->prev = NULL;
        }
    }
    else
    {
        slide->prev->next = slide->next;

        if (slide->next)
        {
            slide->next->prev = slide->prev;
        }
    }
    g_srv_uc_p[instance]->msg.msg_body.slide_no--;

    if (slide->next)
    {
        mma_mms_slide_struct *update_slide = slide->next;

        while (update_slide)
        {
            update_slide->slide_num--;
            srv_uc_update_text_object_path(instance, update_slide);
            update_slide = update_slide->next;
        }
    }

    g_srv_uc_p[instance]->free(slide, g_srv_uc_p[instance]->user_data);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_signature_pass_warning_mode_content_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_uc_signature_pass_warning_mode_content_check(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_insert_check_struct check_result;
    mma_insert_info_struct insert_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_uc_p[instance]->mms_info.creation_mode != MMA_CREATION_MODE_WARNING)
    {
        return MMI_TRUE;
    }

    /* Common part. */
    insert_info.creation_mode = g_srv_uc_p[instance]->mms_info.creation_mode;
    insert_info.current_msg_size = 0;   /* becasue only check warning mode, no need curr size */
    insert_info.max_msg_size = g_srv_uc_p[instance]->mms_info.max_mms_size - srv_uc_reserved_size(instance);
    insert_info.mms_type = srv_uc_get_mms_type(instance);

    /* check img file */
    memset(&check_result, 0, sizeof(mma_insert_check_struct));
    if (g_srv_uc_p[instance]->mms_info.signature.img_file)
    {
        insert_info.insert_type = (mma_insert_type_enum)srv_uc_convert_to_mms_insert_type(SRV_UC_OBJECT_TYPE_IMAGE);
        insert_info.filepath = (kal_wchar*) g_srv_uc_p[instance]->mms_info.signature.img_file;

        mma_uc_insert_object_check(&insert_info, &check_result);

        if (check_result.result && (MMA_RESULT_OK_WITH_WARNING_CONTENT == check_result.detail_result))
        {
            return MMI_FALSE;
        }
    }

    /* check audio file */
    memset(&check_result, 0, sizeof(mma_insert_check_struct));
    if (g_srv_uc_p[instance]->mms_info.signature.audio_file)
    {
        insert_info.insert_type = (mma_insert_type_enum)srv_uc_convert_to_mms_insert_type(SRV_UC_OBJECT_TYPE_AUDIO);
        insert_info.filepath = (kal_wchar*) g_srv_uc_p[instance]->mms_info.signature.audio_file;

        mma_uc_insert_object_check(&insert_info, &check_result);

        if (check_result.result && (MMA_RESULT_OK_WITH_WARNING_CONTENT == check_result.detail_result))
        {
            return MMI_FALSE;
        }

    }

    /* check video file */
    memset(&check_result, 0, sizeof(mma_insert_check_struct));
    if (g_srv_uc_p[instance]->mms_info.signature.video_file)
    {
        insert_info.insert_type = (mma_insert_type_enum)srv_uc_convert_to_mms_insert_type(SRV_UC_OBJECT_TYPE_VIDEO);
        insert_info.filepath = (kal_wchar*) g_srv_uc_p[instance]->mms_info.signature.video_file;

        mma_uc_insert_object_check(&insert_info, &check_result);

        if (check_result.result && (MMA_RESULT_OK_WITH_WARNING_CONTENT == check_result.detail_result))
        {
            return MMI_FALSE;
        }
    }

    /* check text file */
    memset(&check_result, 0, sizeof(mma_insert_check_struct));
    if (g_srv_uc_p[instance]->mms_info.signature.text_file)
    {
        insert_info.insert_type = (mma_insert_type_enum)srv_uc_convert_to_mms_insert_type(SRV_UC_OBJECT_TYPE_TEXT);
        insert_info.filepath = (kal_wchar*) g_srv_uc_p[instance]->mms_info.signature.text_file;

        mma_uc_insert_object_check(&insert_info, &check_result);

        if (check_result.result && (MMA_RESULT_OK_WITH_WARNING_CONTENT == check_result.detail_result))
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_delete_slide_with_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  slide           [?]         
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_delete_slide_with_object(U32 instance, mma_mms_slide_struct *slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mma_mms_slide_ref_object_struct *curr_ref = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slide->img.object && slide->img.object->reference_count )
    {
        slide->img.object->reference_count--;

        if (slide->img.object->reference_count == 0)
        {
            srv_uc_delete_object_from_list(instance, slide->img.object);
        }
    }

    if (slide->aud.object && slide->aud.object->reference_count )
    {
        slide->aud.object->reference_count--;

        if (slide->aud.object->reference_count == 0)
        {
            srv_uc_delete_object_from_list(instance, slide->aud.object);
        }
    }

    if (slide->vid.object && slide->vid.object->reference_count )
    {
        slide->vid.object->reference_count--;

        if (slide->vid.object->reference_count == 0)
        {
            srv_uc_delete_object_from_list(instance, slide->vid.object);
        }
    }

    if (slide->txt.object && slide->txt.object->reference_count )
    {
		S32 result ;
		slide->txt.object->reference_count-- ;

        result = FS_Delete((U16*) slide->txt.object->file_path_ucs);

        if (result != FS_NO_ERROR)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_DEL_SLIDE_WITH_OBJ_TEXT_FAIL);
        }

        srv_uc_delete_object_from_list(instance, slide->txt.object);
    }
    /* ref */
    curr_ref = slide->ref_items;
    while (curr_ref)
    {
        if (curr_ref->object && curr_ref->object->reference_count )
        {
            curr_ref->object->reference_count--;

            if (curr_ref->object->reference_count == 0)
            {
                srv_uc_delete_object_from_list(instance, curr_ref->object);
            }
        }
        curr_ref = curr_ref->next;
    }

    srv_uc_delete_slide(instance, slide);
    srv_uc_reset_layout_if_needed(instance);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_reset_mms_signature
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_reset_mms_signature(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_uc_p[instance]->mms_info.signature.text_file)
    {
        g_srv_uc_p[instance]->free(g_srv_uc_p[instance]->mms_info.signature.text_file, g_srv_uc_p[instance]->user_data);
        g_srv_uc_p[instance]->mms_info.signature.text_file = NULL;
    }
    if (g_srv_uc_p[instance]->mms_info.signature.img_file)
    {
        g_srv_uc_p[instance]->free(g_srv_uc_p[instance]->mms_info.signature.img_file, g_srv_uc_p[instance]->user_data);
        g_srv_uc_p[instance]->mms_info.signature.img_file = NULL;
    }
    if (g_srv_uc_p[instance]->mms_info.signature.audio_file)
    {
        g_srv_uc_p[instance]->free(g_srv_uc_p[instance]->mms_info.signature.audio_file, g_srv_uc_p[instance]->user_data);
        g_srv_uc_p[instance]->mms_info.signature.audio_file = NULL;
    }
    if (g_srv_uc_p[instance]->mms_info.signature.video_file)
    {
        g_srv_uc_p[instance]->free(g_srv_uc_p[instance]->mms_info.signature.video_file, g_srv_uc_p[instance]->user_data);
        g_srv_uc_p[instance]->mms_info.signature.video_file = NULL;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_reset_msg
 * DESCRIPTION
 *  Reset msg info in context
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_reset_msg(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uc_service_req_struct *srv_req;
    /* for delete postcard info */
#ifdef __MMI_MMS_POSTCARD__
    applib_oppostcard_mem_func_struct mem_funct;

    mem_funct.alloc_fn = g_srv_uc_p[instance]->alloc;
    mem_funct.free_fn = g_srv_uc_p[instance]->free;
    mem_funct.user_data = g_srv_uc_p[instance]->user_data;
#endif /* __MMI_MMS_POSTCARD__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* delete postcard recipient info */
#ifdef __MMI_MMS_POSTCARD__
    /* greeting is already freed after decode API is called */
    applib_oppostcard_free_memory(&mem_funct, NULL, g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_head);
#endif /* __MMI_MMS_POSTCARD__ */ 
    while (g_srv_uc_p[instance]->msg.to_head)
    {
        srv_uc_delete_addr(instance, g_srv_uc_p[instance]->msg.to_head);
    }
    while (g_srv_uc_p[instance]->msg.from)
    {
        srv_uc_delete_addr(instance, g_srv_uc_p[instance]->msg.from);
    }

    while (g_srv_uc_p[instance]->msg.msg_body.slides)
    {
        srv_uc_delete_slide_with_object(instance, g_srv_uc_p[instance]->msg.msg_body.slides);
    }

    while (g_srv_uc_p[instance]->msg.msg_body.attachment)
    {
        srv_uc_delete_object_from_list(instance, g_srv_uc_p[instance]->msg.msg_body.attachment->object);
        srv_uc_delete_attachment_from_list(instance, g_srv_uc_p[instance]->msg.msg_body.attachment);
    }

    while (g_srv_uc_p[instance]->msg.msg_body.objects)
    {
        srv_uc_delete_object_from_list(instance, g_srv_uc_p[instance]->msg.msg_body.objects);
    }

    memset(&(g_srv_uc_p[instance]->msg), 0, sizeof(srv_uc_msg_struct));

    if (g_srv_uc_p[instance]->main.file_handle)
    {
        FS_Close(g_srv_uc_p[instance]->main.file_handle);
        g_srv_uc_p[instance]->main.file_handle = 0;
    }

    srv_uc_init_uc_folder(instance);

    if (g_srv_uc_p[instance]->main.file_path)
    {
        g_srv_uc_p[instance]->free(g_srv_uc_p[instance]->main.file_path, g_srv_uc_p[instance]->user_data);
        g_srv_uc_p[instance]->main.file_path = NULL;
    }
    memset(&(g_srv_uc_p[instance]->send_info), 0, sizeof(g_srv_uc_p[instance]->send_info));
    srv_uc_reset_mms_signature(instance);
    g_srv_uc_p[instance]->main.mode = (srv_uc_mode_change_status_enum)0;
    while(g_srv_uc_p[instance]->srv_req)
    {
        srv_req = g_srv_uc_p[instance]->srv_req;
        g_srv_uc_p[instance]->srv_req = g_srv_uc_p[instance]->srv_req->next;
        g_srv_uc_p[instance]->free(srv_req, g_srv_uc_p[instance]->user_data);
        srv_req = NULL;
    }
    return MMI_TRUE;
}

#ifdef __MMI_MMS_POSTCARD__


/*****************************************************************************
 * FUNCTION
 *  srv_postcard_fill_recipient_info
 * DESCRIPTION
 *  index: start from 0 (ex. during handle 1st recipient, the number will be 0. after handled, the number will be 1)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_postcard_fill_recipient_info(U32 instance, srv_postcard_recipient_struct *wanted_recipient, U8 index)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_postcard_recipient_struct *index_recipient;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((index + 1) <= srv_postcard_get_total_recipient_count(instance));
    /* get wanted recipient from  g_uc_p->msg.postcard_recipient_info.recipient_head */
    memset(wanted_recipient, 0, sizeof(srv_postcard_recipient_struct));
    index_recipient = srv_postcard_get_recipient_pointer_by_index(instance, index);

    memcpy(&wanted_recipient->address, &index_recipient->address, sizeof(srv_postcard_address_struct));
    return;

}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_fill_obj_info_for_postcard_without_greeting
 * DESCRIPTION
 *  fill the object information for the following case:
 *  there is no greeting, we have to create one text obj which includes recipients info
 *  the caller should fill file path and file_name before calling this API
 * PARAMETERS
 *  instance        [IN]        
 *  obj             [?]         
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_uc_fill_obj_info_for_postcard_without_greeting(U32 instance, mma_mms_object_struct *obj)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_postcard_recipient_struct wanted_recipient_list;
    applib_oppostcard_mem_func_struct *mem_func;
		S32 result;
		
    mem_func = g_srv_uc_p[instance]->alloc(sizeof(applib_oppostcard_mem_func_struct), g_srv_uc_p[instance]->user_data);
    mem_func->alloc_fn = g_srv_uc_p[instance]->alloc;
    mem_func->free_fn = g_srv_uc_p[instance]->free;
    mem_func->user_data = g_srv_uc_p[instance]->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* fill file related info, here we should create one text for non greeting case */
    if (g_srv_uc_p[instance]->send_info.action == SRV_UC_ACTION_SEND_IN_BACKGROUND)
    {
        srv_postcard_fill_recipient_info(
            instance,
            &wanted_recipient_list,
            (U8) g_srv_uc_p[instance]->send_info.curr_send_number);
        result = applib_oppostcard_encode_text_content(mem_func, (const kal_wchar *)obj->file_path_ucs, NULL, &wanted_recipient_list);

        if ( result == MMI_FALSE)
        {
			g_srv_uc_p[instance]->free(mem_func, g_srv_uc_p[instance]->user_data);
            return FS_DISK_FULL;
        }
    }
    else
    {
        result = applib_oppostcard_encode_text_content(
            mem_func,
            (const kal_wchar *)obj->file_path_ucs,
            NULL,
            g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_head);

        if ( result == MMI_FALSE)
        {
			g_srv_uc_p[instance]->free(mem_func, g_srv_uc_p[instance]->user_data);
            return FS_DISK_FULL;
        }
    }

    obj->size = applib_get_file_size((kal_wchar*) obj->file_path_ucs);
    obj->id = g_srv_uc_p[instance]->msg.msg_body.obj_no + 1;
    obj->type = MMA_MMS_OBJECT_TYPE_TEXT;
    obj->is_virtual_file = MMI_FALSE;
    obj->drm_type = MMA_DRM_NONE;
    obj->offset = 0;
    g_srv_uc_p[instance]->free(mem_func, g_srv_uc_p[instance]->user_data);
    return FS_NO_ERROR;
}
#endif /* __MMI_MMS_POSTCARD__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_uc_insert_slide_by_number
 * DESCRIPTION
 *  Insert slide by slide number
 * PARAMETERS
 *  instance            [IN]        
 *  slide_number        [IN]        
 *  character(?)        [IN]        
 *  S8 ascii values(?)(?)
 * RETURNS
 *  U8 Decimal value.
 *****************************************************************************/
mma_mms_slide_struct *srv_uc_insert_slide_by_number(U32 instance, U8 slide_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *cur_slide = g_srv_uc_p[instance]->msg.msg_body.slides;
    mma_mms_slide_struct *pre_slide = cur_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slide_number == 1)
    {
        return srv_uc_insert_slide(instance, NULL);
    }
    else
    {
        while (cur_slide && (cur_slide->slide_num < slide_number))
        {
            pre_slide = cur_slide;
            cur_slide = cur_slide->next;
        }

        return srv_uc_insert_slide(instance, pre_slide);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_insert_ref_obj_info_to_tail
 * DESCRIPTION
 *  Insert ref object info to tail
 * PARAMETERS
 *  instance        [IN]        
 *  slide           [?]         
 *  id              [IN]        
 *  begin           [IN]        
 *  end             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_slide_ref_object_struct *srv_uc_insert_ref_obj_info_to_tail(
                                U32 instance,
                                mma_mms_slide_struct *slide,
                                U32 id,
                                U32 begin,
                                U32 end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_ref_object_struct *new_ref_obj_info;
    U32 ref_obj_info_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1. new a ref obj info node */
    ref_obj_info_size = sizeof(mma_mms_slide_ref_object_struct);

    new_ref_obj_info = g_srv_uc_p[instance]->alloc(ref_obj_info_size, g_srv_uc_p[instance]->user_data);
    MMI_ASSERT(new_ref_obj_info);

    memset(new_ref_obj_info, 0, ref_obj_info_size);
    new_ref_obj_info->id = id;
    new_ref_obj_info->begin = begin;
    new_ref_obj_info->end = end;

    /* insert the new ref node to ref_list in this slide */
    if (NULL == slide->ref_items)
    {
        slide->ref_items = new_ref_obj_info;
    }
    else
    {
        mma_mms_slide_ref_object_struct *cur_ref;

        cur_ref = slide->ref_items;

        while (cur_ref->next)
        {
            cur_ref = cur_ref->next;
        }
        cur_ref->next = new_ref_obj_info;
        new_ref_obj_info->next = NULL;
        new_ref_obj_info->prev = cur_ref;
    }

    g_srv_uc_p[instance]->msg.msg_body.total_attach_no++;
    MMI_ASSERT(g_srv_uc_p[instance]->msg.msg_body.total_attach_no <= SRV_UC_MAX_ATTACHMENT_NUM);

    return new_ref_obj_info;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_insert_object_to_list_tail
 * DESCRIPTION
 *  Insert object to object list tail
 * PARAMETERS
 *  instance            [IN]        
 *  character(?)        [IN]        
 *  S8 ascii values(?)(?)
 * RETURNS
 *  U8 Decimal value.
 *****************************************************************************/
mma_mms_object_struct *srv_uc_insert_object_to_list_tail(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *new_object;
    U32 object_size;
    U32 i = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    object_size = sizeof(mma_mms_object_struct);
    new_object = g_srv_uc_p[instance]->alloc(object_size, g_srv_uc_p[instance]->user_data);
    MMI_ASSERT(new_object);
    memset(new_object, 0, object_size);

    /* First object */
    if (g_srv_uc_p[instance]->msg.msg_body.objects == NULL)
    {
        g_srv_uc_p[instance]->msg.msg_body.objects = new_object;
        new_object->next = NULL;
        new_object->prev = NULL;
    }
    else
    {
        mma_mms_object_struct *cur_object = g_srv_uc_p[instance]->msg.msg_body.objects;

        while (cur_object->next)
        {
            MMI_ASSERT(i < g_srv_uc_p[instance]->msg.msg_body.obj_no);
            cur_object = cur_object->next;
            i++;
        }

        cur_object->next = new_object;
        new_object->next = NULL;
        new_object->prev = cur_object;
    }

    g_srv_uc_p[instance]->msg.msg_body.obj_no++;
    return new_object;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_read_file_to_text_buffer
 * DESCRIPTION
 *  Read the file to text buffer
 * PARAMETERS
 *  instance        [IN]        
 *  file_path       [?]         
 *  encoding        [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_read_file_to_text_buffer(U32 instance, U8 *file_path, U32 encoding)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    U32 result;
    U32 read_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Open the file to write, overwrite if already exists. */

    mmi_chset_enum converted_encoding = srv_uc_convert_encoding_type_to_chset(encoding);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_READ_FILE_TO_TEXT_BUF_P2, encoding, converted_encoding);

    file_handle = FS_Open((U16*) file_path, FS_READ_ONLY | FS_OPEN_SHARED);
    if (file_handle > 0)
    {
        U8 *temp_utf8_buffer = (U8*) g_srv_uc_p[instance]->text_buffer_alloc(SRV_UC_UTF8_TEXT_BUFFER_SIZE, g_srv_uc_p[instance]->user_data);

        memset(temp_utf8_buffer, 0, SRV_UC_UTF8_TEXT_BUFFER_SIZE);

        result = FS_Read(file_handle, temp_utf8_buffer, SRV_UC_UTF8_TEXT_BUFFER_SIZE, &read_len);

        FS_Close(file_handle);

        srv_uc_reset_text_buffer(instance);
        if (result == FS_NO_ERROR)
        {
            /* becasue mmi_chset_convert can not handle ASCII case right now--2007/10/26, so UC call another api to convert for ascii case */
            if (MMI_CHSET_ASCII == converted_encoding)
            {
                mmi_asc_n_to_ucs2(
                    (S8*) g_srv_uc_p[instance]->main.text_buffer,
                    (S8*) temp_utf8_buffer,
                    SRV_UC_TEXT_BUFFER_SIZE / 2);
            }
            else
            {
                mmi_chset_convert(
                    converted_encoding,
                    MMI_CHSET_UCS2,
                    (char*)temp_utf8_buffer,
                    (char*)g_srv_uc_p[instance]->main.text_buffer,
                    SRV_UC_TEXT_BUFFER_SIZE);
            }
            g_srv_uc_p[instance]->text_buffer_free((void*)temp_utf8_buffer, g_srv_uc_p[instance]->user_data);
            return MMI_TRUE;
        }
        else
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_READ_FILE_TO_TEXT_BUF_READ_ERR_P2, result, read_len);
            g_srv_uc_p[instance]->text_buffer_free(temp_utf8_buffer, g_srv_uc_p[instance]->user_data);
            return MMI_FALSE;
        }
        //g_srv_uc_p[instance]->text_buffer_free(temp_utf8_buffer, g_srv_uc_p[instance]->user_data);
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_READ_FILE_TO_TEXT_BUF_OPEN_ERR_P1, file_handle);
        //MMI_ASSERT(0);
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_save_buffer_to_file
 * DESCRIPTION
 *  Save the content of text buffer to file
 * PARAMETERS
 *  instance        [IN]        
 *  file_path       [?]         
 *  buffer          [?]         
 *  char_num        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_uc_save_buffer_to_file(U16 instance, U8 *file_path, U8 *buffer, U16 char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S32 result = FS_NO_ERROR;
    U32 write_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Open the file to write, overwrite if already exists. */
    file_handle = FS_Open((U16*) file_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (file_handle > 0)
    {
        U32 utf8_buffer_size = (char_num * 3 + ENCODING_LENGTH);
        U8 *utf8_buffer = (U8*) g_srv_uc_p[instance]->text_buffer_alloc(utf8_buffer_size, g_srv_uc_p[instance]->user_data);
        U32 utf8_len = 0;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_SAVE_BUFF_TO_FILE_P1, char_num);

        MMI_ASSERT(utf8_buffer_size <= SRV_UC_UTF8_TEXT_BUFFER_SIZE);

        memset(utf8_buffer, 0, utf8_buffer_size);
        utf8_len = mmi_chset_ucs2_to_utf8_string(utf8_buffer, utf8_buffer_size, buffer);

        result = FS_Write(
                    file_handle,
                    utf8_buffer,
                    utf8_len - 1,   /* null terminator */
                    &write_len);

        g_srv_uc_p[instance]->text_buffer_free(utf8_buffer, g_srv_uc_p[instance]->user_data);
        FS_Close(file_handle);
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_SAVE_BUFF_TO_FILE_FAIL_P1, file_handle);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_handle_text_in_current_slide
 * DESCRIPTION
 *  Save content of text buffer to file OR delete text object
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_uc_handle_text_in_current_slide(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 srv_uc_text_path[SRV_UC_MAX_TEMP_FILE_LEN];
    mma_mms_object_struct *object = NULL;
    S32 result = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(srv_uc_text_path, 0, SRV_UC_MAX_TEMP_FILE_LEN);
    SRV_UC_MAKE_TEXT_FILE_PATH(srv_uc_text_path, g_srv_uc_p[instance]->msg.current_slide_num, instance);

    /* Add text object with empty content to the slide */
    if (g_srv_uc_p[instance]->msg.msg_body.curr_slide->txt.char_count > 0)
    {
        result = srv_uc_save_buffer_to_file(
                    instance,
                    srv_uc_text_path,
                    g_srv_uc_p[instance]->main.text_buffer,
                    g_srv_uc_p[instance]->msg.msg_body.curr_slide->txt.char_count);

        if (result == FS_NO_ERROR)
        {
            if (g_srv_uc_p[instance]->msg.msg_body.curr_slide->txt.object == NULL)
            {
                object = srv_uc_insert_object(instance, (S8*) srv_uc_text_path, SRV_UC_OBJECT_TYPE_TEXT);
                srv_uc_insert_object_to_slide(
                    instance,
                    object,
                    g_srv_uc_p[instance]->msg.msg_body.curr_slide,
                    SRV_UC_OBJECT_TYPE_TEXT);
            }
            else
            {
                g_srv_uc_p[instance]->msg.msg_body.curr_slide->txt.object->size = applib_get_file_size((kal_wchar*) srv_uc_text_path);
            }
            g_srv_uc_p[instance]->msg.msg_body.curr_slide->txt.object->encoding = MMA_CHARSET_UTF8;  /* because the text's encode already UTF8 when srv_uc_save_buffer_to_file to file */
        }
        else
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_HANDLE_TEXT_IN_CURR_SLIDE_RESULT_P1, result);

        }
    }
    /* Delete the text object */
    else if (g_srv_uc_p[instance]->msg.msg_body.curr_slide->txt.char_count == 0)
    {
        if (g_srv_uc_p[instance]->msg.msg_body.curr_slide->txt.object)
        {
            if (FS_Delete((U16*) srv_uc_text_path) != FS_NO_ERROR)
            {
                MMI_ASSERT(0);
				MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
            }
            srv_uc_delete_object_from_list(instance, g_srv_uc_p[instance]->msg.msg_body.curr_slide->txt.object);
            memset(&(g_srv_uc_p[instance]->msg.msg_body.curr_slide->txt), 0, sizeof(mma_mms_slide_text_object_struct));
        }
    }
    else
    {
        MMI_ASSERT(0);
		MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_replace_duplicate_object_file_name
 * DESCRIPTION
 *  Replace duplicate object file name
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uc_replace_duplicate_object_file_name(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj = g_srv_uc_p[instance]->msg.msg_body.objects;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (obj != NULL)
    {
        mma_mms_object_struct *handle_obj = obj->next;
        U32 i,time_value;
        applib_time_struct time;
		
        applib_dt_get_secure_time(&time);
        time_value = applib_dt_mytime_2_utc_sec(&time, KAL_TRUE);
        i = (time_value%1000);

        while (handle_obj != NULL)
        {
            handle_obj = srv_uc_check_duplicate_object_by_filename(instance, (U16 *)obj->file_name_ucs, handle_obj);

            if (handle_obj != NULL)
            {
                if (handle_obj->type != SRV_UC_OBJECT_TYPE_ATTACHMENT && handle_obj->type != SRV_UC_OBJECT_TYPE_REF)
                {
                    /* replace file name */
                    U16 file_name_len = mmi_ucs2strlen((S8*) handle_obj->file_name_ucs);
                    U16 *new_file_name = g_srv_uc_p[instance]->alloc((file_name_len + 5) * ENCODING_LENGTH, g_srv_uc_p[instance]->user_data);
                    U16 file_suffix[5];
                    U16 *file_extension = srv_uc_get_file_extension(handle_obj->file_name_ucs);
                    U16 file_extension_len = 0;

                    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_RENAME_DUPLICATE_NAME);
                    if (file_extension != NULL)
                    {
                        file_extension_len = mmi_ucs2strlen((S8*) file_extension);
                        mmi_ucs2ncpy(
                            (S8*) new_file_name,
                            (S8*) handle_obj->file_name_ucs,
                            (file_name_len - file_extension_len - 1));
                    }
                    else
                    {
                        mmi_ucs2ncpy((S8*) new_file_name, (S8*) handle_obj->file_name_ucs, file_name_len);
                    }

                    memset(file_suffix, 0x00, sizeof(file_suffix));
                    kal_wsprintf((kal_uint16*) file_suffix, "%03d", i);
                    mmi_ucs2cat((PS8) new_file_name, (PS8) file_suffix);

                    if (file_extension != NULL)
                    {
                        mmi_ucs2cat((PS8) new_file_name, (PS8) L".");
                        mmi_ucs2cat((PS8) new_file_name, (PS8) file_extension);
                    }

                    g_srv_uc_p[instance]->free(handle_obj->file_name_ucs, g_srv_uc_p[instance]->user_data);
                    handle_obj->file_name_ucs = new_file_name;
                    i++;
                }
                handle_obj = handle_obj->next;
            }
        }
        obj = obj->next;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_post_handler_handle_object_insert_if_file_path_exist
 * DESCRIPTION
 *  the post handler for handle object insert in file path exist case
 * PARAMETERS
 *  instance                [IN]        
 *  mms_type                [IN]        
 *  srv_uc_image_path       [?]         
 *  filePath                [IN]        
 * RETURNS
 *  void
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_post_handler_handle_object_insert_if_file_path_exist(
        U32 instance,
        mma_insert_type_enum mms_type,
        U8 *srv_uc_image_path,
        PU16 filePath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *object;
    srv_uc_object_type uc_object_type;

    mma_insert_check_struct check_result;
    mma_insert_info_struct insert_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&check_result, 0, sizeof(check_result));

    /* Check if it is DRM file */

    insert_info.creation_mode = g_srv_uc_p[instance]->mms_info.creation_mode;
    insert_info.current_msg_size = g_srv_uc_p[instance]->msg.msg_size;
    insert_info.max_msg_size = g_srv_uc_p[instance]->mms_info.max_mms_size - srv_uc_reserved_size(instance);
    insert_info.insert_type = mms_type;
    insert_info.filepath = (kal_wchar*) filePath;
    insert_info.mms_type = srv_uc_get_mms_type(instance);

    mma_uc_insert_object_check(&insert_info, &check_result);

    uc_object_type = srv_uc_convert_mms_insert_type_to_uc(mms_type);
    object = srv_uc_insert_object(instance, (S8*) filePath, uc_object_type);
    object->auto_delete_file = (kal_bool)g_srv_uc_p[instance]->main.auto_delete_file;
    g_srv_uc_p[instance]->main.auto_delete_file = FALSE;
    object->drm_type = check_result.drm_type;

    if (uc_object_type == SRV_UC_OBJECT_TYPE_ATTACHMENT)
    {
    #ifdef __MMI_UC_REF__
        if (srv_uc_is_in_ref_obj_type_range((S8*) filePath))
        {

            mma_mms_slide_ref_object_struct *new_ref_obj_info;

            /* do not care id, so set 0 here */
            new_ref_obj_info = srv_uc_insert_ref_obj_info_to_tail(
                                instance,
                                g_srv_uc_p[instance]->msg.msg_body.curr_slide,
                                0,
                                SRV_UC_INVALID_VALUE,
                                SRV_UC_INVALID_VALUE);

            /* associate real object and the new ref obj info */
            new_ref_obj_info->object = object;
            object->reference_count++;
        }
        else
    #endif /* __MMI_UC_REF__ */ 
        {
            mma_mms_attachment_info_struct *att;

            att = srv_uc_insert_attachment(instance);
            srv_uc_insert_object_to_attachment(object, att);
        }
    }
    else
    {
        srv_uc_insert_object_to_slide(instance, object, g_srv_uc_p[instance]->msg.msg_body.curr_slide, uc_object_type);
    }

    /* Determine layout */
    if (uc_object_type == SRV_UC_OBJECT_TYPE_IMAGE || uc_object_type == SRV_UC_OBJECT_TYPE_VIDEO)
    {
        if (g_srv_uc_p[instance]->msg.msg_body.layout == MMA_LAYOUT_NONE)
        {
            if (g_srv_uc_p[instance]->msg.msg_body.curr_slide->txt.char_count)
            {
                g_srv_uc_p[instance]->msg.msg_body.layout = MMA_LAYOUT_TEXT_ON_TOP;
            }
            else
            {
                g_srv_uc_p[instance]->msg.msg_body.layout = MMA_LAYOUT_IMAGE_ON_TOP;
            }
        }
    }

    g_srv_uc_p[instance]->free(g_srv_uc_p[instance]->main.file_path, g_srv_uc_p[instance]->user_data);
    g_srv_uc_p[instance]->main.file_path = NULL;

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_set_subject
 * DESCRIPTION
 *  set the subject to teh context
 * PARAMETERS
 *  instance                [IN]            
 *  subject_str                [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_set_subject(
        U32 instance,
        S8* subject_str)
{
        memcpy(g_srv_uc_p[instance]->msg.subject, subject_str, sizeof(U16) * (SRV_UC_MAX_SUBJECT_LEN + 1));
        srv_uc_update_msg_size(instance);
		return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_subject
 * DESCRIPTION
 *  set the subject to the context
 * PARAMETERS
 *  instance                [IN]                  
 * RETURNS
 *  S8*
 *****************************************************************************/
U16* srv_uc_get_subject(
        U32 instance)
{
//   if (mmi_ucs2strlen((S8*) g_srv_uc_p[instance]->msg.subject))
    {
        return g_srv_uc_p[instance]->msg.subject;
    }
}

#ifdef __MMI_MMS_INSERT_SENDER_ADDR_FROM_SIM__

void srv_uc_get_owner_num(U32 instance, U16* owner_num)
{
  g_srv_uc_p[instance]->msg.owner=owner_num;
}
#endif

#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_uc_reset_msg
 * DESCRIPTION
 *  Reset msg info in context
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_reset_msg_ext(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uc_service_req_struct *srv_req;
    /* for delete postcard info */
#ifdef __MMI_MMS_POSTCARD__
    applib_oppostcard_mem_func_struct mem_funct;

    mem_funct.alloc_fn = g_srv_uc_p[instance]->alloc;
    mem_funct.free_fn = g_srv_uc_p[instance]->free;
    mem_funct.user_data = g_srv_uc_p[instance]->user_data;
#endif /* __MMI_MMS_POSTCARD__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* delete postcard recipient info */
#ifdef __MMI_MMS_POSTCARD__
    /* greeting is already freed after decode API is called */
    applib_oppostcard_free_memory(&mem_funct, NULL, g_srv_uc_p[instance]->msg.msg_body.postcard_recipient_info.recipient_head);
#endif /* __MMI_MMS_POSTCARD__ */ 
    while (g_srv_uc_p[instance]->msg.to_head)
    {
        srv_uc_delete_addr(instance, g_srv_uc_p[instance]->msg.to_head);
    }
    while (g_srv_uc_p[instance]->msg.from)
    {
        srv_uc_delete_addr(instance, g_srv_uc_p[instance]->msg.from);
    }

    while (g_srv_uc_p[instance]->msg.msg_body.slides)
    {
        srv_uc_delete_slide_with_object_ext(instance, g_srv_uc_p[instance]->msg.msg_body.slides);
    }

    while (g_srv_uc_p[instance]->msg.msg_body.attachment)
    {
        srv_uc_delete_object_from_list(instance, g_srv_uc_p[instance]->msg.msg_body.attachment->object);
        srv_uc_delete_attachment_from_list(instance, g_srv_uc_p[instance]->msg.msg_body.attachment);
    }

    while (g_srv_uc_p[instance]->msg.msg_body.objects)
    {
        srv_uc_delete_object_from_list(instance, g_srv_uc_p[instance]->msg.msg_body.objects);
    }

    memset(&(g_srv_uc_p[instance]->msg), 0, sizeof(srv_uc_msg_struct));

    if (g_srv_uc_p[instance]->main.file_handle)
    {
        FS_Close(g_srv_uc_p[instance]->main.file_handle);
        g_srv_uc_p[instance]->main.file_handle = 0;
    }
 
    if (g_srv_uc_p[instance]->main.file_path)
    {
        g_srv_uc_p[instance]->free(g_srv_uc_p[instance]->main.file_path, g_srv_uc_p[instance]->user_data);
        g_srv_uc_p[instance]->main.file_path = NULL;
    }
    memset(&(g_srv_uc_p[instance]->send_info), 0, sizeof(g_srv_uc_p[instance]->send_info));
    srv_uc_reset_mms_signature(instance);
    g_srv_uc_p[instance]->main.mode = (srv_uc_mode_change_status_enum)0;
    while(g_srv_uc_p[instance]->srv_req)
    {
        srv_req = g_srv_uc_p[instance]->srv_req;
        g_srv_uc_p[instance]->srv_req = g_srv_uc_p[instance]->srv_req->next;
        g_srv_uc_p[instance]->free(srv_req, g_srv_uc_p[instance]->user_data);
        srv_req = NULL;
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_uc_delete_slide_with_object_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  slide           [?]         
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_delete_slide_with_object_ext(U32 instance, mma_mms_slide_struct *slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mma_mms_slide_ref_object_struct *curr_ref = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slide->img.object && slide->img.object->reference_count )
    {
        slide->img.object->reference_count--;

        if (slide->img.object->reference_count == 0)
        {
            srv_uc_delete_object_from_list(instance, slide->img.object);
        }
    }

    if (slide->aud.object && slide->aud.object->reference_count )
    {
        slide->aud.object->reference_count--;

        if (slide->aud.object->reference_count == 0)
        {
            srv_uc_delete_object_from_list(instance, slide->aud.object);
        }
    }

    if (slide->vid.object && slide->vid.object->reference_count )
    {
        slide->vid.object->reference_count--;

        if (slide->vid.object->reference_count == 0)
        {
            srv_uc_delete_object_from_list(instance, slide->vid.object);
        }
    }

    if (slide->txt.object && slide->txt.object->reference_count )
    {
		slide->txt.object->reference_count-- ;

        srv_uc_delete_object_from_list(instance, slide->txt.object);
    }
    /* ref */
    curr_ref = slide->ref_items;
    while (curr_ref)
    {
        if (curr_ref->object && curr_ref->object->reference_count )
        {
            curr_ref->object->reference_count--;

            if (curr_ref->object->reference_count == 0)
            {
                srv_uc_delete_object_from_list(instance, curr_ref->object);
            }
        }
        curr_ref = curr_ref->next;
    }

    //srv_uc_delete_slide(instance, slide);
	/*Dont Modify Filename*/
    if (slide == g_srv_uc_p[instance]->msg.msg_body.slides)
    {
        g_srv_uc_p[instance]->msg.msg_body.slides = slide->next;

        if (slide->next)
        {
            slide->next->prev = NULL;
        }
    }
    else
    {
        slide->prev->next = slide->next;

        if (slide->next)
        {
            slide->next->prev = slide->prev;
        }
    }
    g_srv_uc_p[instance]->msg.msg_body.slide_no--;
	g_srv_uc_p[instance]->free(slide, g_srv_uc_p[instance]->user_data);
/*Dont Modify Filename*/
    srv_uc_reset_layout_if_needed(instance);
    return MMI_TRUE;
}

#endif /*__MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__*/

#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */ 
#endif /* _UNIFIED_COMPOSER_ENGINE_SRV_C */
