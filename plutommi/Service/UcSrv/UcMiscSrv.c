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
 * UcMiscSrv.c
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
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#ifndef _UNIFIED_COMPOSER_MISC_SRV_C
#define _UNIFIED_COMPOSER_MISC_SRV_C

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))

//#include "app_base64.h"
#include "app_usedetails.h"
#include "app_str.h"
//#include "SMSAppUtil.h"
#include "PhbSrvGprot.h"
#include "Conversions.h"

//#include "SettingProfile.h"

//#include "PhoneSetupGprots.h"
#ifdef WAP_SUPPORT
#include "WAPProfileSrvType.h"
#endif 

#include "med_api.h"
//#include "MessagesresourceData.h"
#include "MessagesMiscell.h"

#ifdef __MMI_MMS_BGSR_SUPPORT__
#include "MmsSrvGprot.h"
#endif 
//#include "UmGprot.h"
#include "UcSrvGProt.h"
#include "UcSrvIprot.h"
#include "UcSrv.h"
#include "FileMgrGProt.h"
//suggested add
#include "MMI_features.h"
    #include "MMIDataType.h"
    //#include "kal_general_types.h"
    #include "string.h"
    //#include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "Unicodexdcl.h"
    #include "mma_api.h"
    #include "mms_api.h"
    //#include "MMI_common_app_trc.h"
    #include "kal_trace.h"
   // #include "mmi_common_app_trc.h"
    #include "gui_config.h"
    #include "gui_data_types.h"
    #include "custom_phb_config.h"
    //#include "ps_public_enum.h"
    #include "mma_struct.h"
    #include "UcAppGProt.h"
    #include "UmSrvDefs.h"
    #include "SmsSrvGprot.h"
    #include "mmi_frm_mem_gprot.h"
    #include "fs_type.h"
    #include "fs_func.h"
    #include "FileMgrSrvGProt.h"
    #include "fs_errcode.h"
    #include "custom_wap_config.h"
    #include "app_datetime.h"
    #include "custom_em.h"
    #include "gdi_const.h"
    #include "gdi_datatype.h"
    #include "lcd_sw_rnd.h"
    #include "gdi_include.h"
    #include "mmi_rp_file_type_def.h"
    #include "FileMgrType.h"
    
    #include "UmSrvStruct.h"
    #include "stack_ltlcom.h"
    #include "kal_public_defs.h"
    #include "mmi_frm_queue_gprot.h"
#include "Stack_msgs.h"

srv_uc_context_struct *g_srv_uc_p[SRV_MAX_UC_INSTANCES];
srv_uc_context_struct g_srv_uc_cntx[SRV_MAX_UC_INSTANCES];


/*****************************************************************************
 * FUNCTION
 *  srv_uc_select_instance
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_uc_select_instance(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_MAX_UC_INSTANCES; i++)
    {
        if (g_srv_uc_p[i] == NULL)
        {
            g_srv_uc_p[i] = &g_srv_uc_cntx[i];
            memset(g_srv_uc_p[i], 0, sizeof(srv_uc_context_struct));
            return i;
        }
    }
    return 0xffffffff;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance                [IN]        
 *  app_registered_data     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_uc_create(srv_uc_app_registered_data_struct app_registered_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 srv_instance = srv_uc_select_instance();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(srv_instance != 0xffffffff)
    {
        g_srv_uc_p[srv_instance]->alloc = app_registered_data.app_mem_alloc_fun;
        g_srv_uc_p[srv_instance]->free = app_registered_data.app_mem_free_fun;
        g_srv_uc_p[srv_instance]->user_data = app_registered_data.user_data;
        g_srv_uc_p[srv_instance]->text_buffer_alloc = app_registered_data.app_text_buffer_mem_alloc_fun;
        g_srv_uc_p[srv_instance]->text_buffer_free = app_registered_data.app_text_buffer_mem_free_fun;
        srv_uc_init_uc_folder(srv_instance);
    }
    return srv_instance;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance                [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_uc_delete(U32 instance)
{
    g_srv_uc_p[instance] = NULL;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_srv_main_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_uc_main_struct *srv_uc_get_srv_main_context(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_srv_uc_p[instance]->main;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_srv_msg_type_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_uc_msg_type_struct *srv_uc_get_srv_msg_type_context(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_srv_uc_p[instance]->msg_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_srv_mms_info_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_uc_mms_info_struct *srv_uc_get_srv_mms_info_context(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_srv_uc_p[instance]->mms_info;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_srv_sms_info_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_uc_sms_info_struct *srv_uc_get_srv_sms_info_context(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_srv_uc_p[instance]->sms_info;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_srv_msg_info_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_uc_msg_struct *srv_uc_get_srv_msg_info_context(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_srv_uc_p[instance]->msg;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_srv_send_info_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_uc_send_info_struct *srv_uc_get_srv_send_info_context(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_srv_uc_p[instance]->send_info;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_srv_xml_info_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
srv_uc_xml_struct *srv_uc_get_srv_xml_info_context(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_srv_uc_p[instance]->xml;
}
#endif

 //#if (MMI_MAX_SIM_NUM >=2)kuldeep_nosim


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_srv_sim_info_context
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_uc_dual_sim_info *srv_uc_get_srv_sim_info_context(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_srv_uc_p[instance]->sim_info;
}
//#endif /* MMI_MAX_SIM_NUM */ 


/*****************************************************************************
 * FUNCTION
 *  srv_uc_free_addr_memory
 * DESCRIPTION
 *  free address memory
 * PARAMETERS
 *  instance        [IN]        
 *  addr            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uc_free_addr_memory(U32 instance, srv_uc_addr_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(addr);

    if (addr->addr)
    {
        g_srv_uc_p[instance]->free(addr->addr, g_srv_uc_p[instance]->user_data);
    }

    g_srv_uc_p[instance]->free(addr, g_srv_uc_p[instance]->user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_new_ref_object_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  id              [IN]        
 *  begin           [IN]        
 *  end             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_slide_ref_object_struct *srv_uc_new_ref_object_info(U32 instance, U32 id, U32 begin, U32 end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_ref_object_struct *new_ref_obj_info;
    U32 ref_obj_info_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ref_obj_info_size = sizeof(mma_mms_slide_ref_object_struct);

    new_ref_obj_info = g_srv_uc_p[instance]->alloc(ref_obj_info_size, g_srv_uc_p[instance]->user_data);
    MMI_ASSERT(new_ref_obj_info);

    memset(new_ref_obj_info, 0, ref_obj_info_size);
    new_ref_obj_info->id = id;
    new_ref_obj_info->begin = begin;
    new_ref_obj_info->end = end;

    return new_ref_obj_info;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_check_duplicate_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  filePath        [?]         
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_object_struct *srv_uc_check_duplicate_object(U32 instance, U16 *filePath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj = g_srv_uc_p[instance]->msg.msg_body.objects;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_uc_p[instance]->msg.msg_body.obj_no == 0)
    {
        MMI_ASSERT(obj == NULL);
        return obj;
    }
    else
    {
        for (; i < g_srv_uc_p[instance]->msg.msg_body.obj_no; i++)
        {
            MMI_ASSERT(obj);

            if (mmi_ucs2cmp((S8*) obj->file_path_ucs, (S8*) filePath) == 0)
            {
                return obj;
            }
            else
            {
                obj = obj->next;
            }
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_check_duplicate_object_by_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  file_name       [?]         
 *  start_obj       [?]         
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_object_struct *srv_uc_check_duplicate_object_by_filename(
                        U32 instance,
                        U16 *file_name,
                        mma_mms_object_struct *start_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (start_obj == NULL)
    {
        obj = g_srv_uc_p[instance]->msg.msg_body.objects;
    }
    else
    {
        obj = start_obj;
    }

    for (; obj != NULL; obj = obj->next)
    {
        MMI_ASSERT(obj);

        if (mmi_ucs2cmp((S8*) obj->file_name_ucs, (S8*) file_name) == 0)
        {
            return obj;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_check_if_exceed_MMS_size_limitation
 * DESCRIPTION
 *  Insert object
 * PARAMETERS
 *  instance                            [IN]        
 *  size                                [IN]        
 *  fail_in_restricted_size_check       [OUT]       
 *  Size(?)                             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_uc_check_if_exceed_MMS_size_limitation(U32 instance, U32 size, MMI_BOOL *fail_in_restricted_size_check)
{
	#ifdef __MMI_MMS_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL flag_for_restricted_popup = (g_srv_uc_p[instance]->mms_info.creation_mode == MMA_CREATION_MODE_RESTRICTED
                                          && mms_get_max_msg_size_in_restricted_mode() <=
                                          g_srv_uc_p[instance]->mms_info.max_mms_size) ? MMI_TRUE : MMI_FALSE;
    U32 max_mms_size =
        (flag_for_restricted_popup) ? mms_get_max_msg_size_in_restricted_mode() : g_srv_uc_p[instance]->mms_info.
        max_mms_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CHECK_IF_MMS_EXCEED_SIZE_P2, size, max_mms_size);

    if (size <= max_mms_size)
    {
        *fail_in_restricted_size_check = MMI_FALSE;
        return MMI_FALSE;
    }
    else
    {
        *fail_in_restricted_size_check = flag_for_restricted_popup;
        return MMI_TRUE;
    }
	#else
    U32 max_mms_size = g_srv_uc_p[instance]->mms_info.max_mms_size;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CHECK_IF_MMS_EXCEED_SIZE_P2, size, max_mms_size);

    if (size <= max_mms_size)
    {
        *fail_in_restricted_size_check = MMI_FALSE;
        return MMI_FALSE;
    }
    else
    {
        *fail_in_restricted_size_check = MMI_FALSE;
        return MMI_TRUE;
    }
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_file_extension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filePath        [?]     
 * RETURNS
 *  
 *****************************************************************************/
U16 *srv_uc_get_file_extension(U16 *filePath)
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
    mmi_asc_n_to_ucs2((S8*) pattern, ".", 1);

    for (; i > 0; i--)
    {
        cur_position = &(filePath[i]);
        pre_position = cur_position - 1;
        if (mmi_ucs2ncmp((S8*) pre_position, (S8*) pattern, 1) == 0)
        {
            return cur_position;
        }
    }

    return NULL;
}

/* Utility API */


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_attachment_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  index           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_attachment_info_struct *srv_uc_get_attachment_by_index(U32 instance, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_attachment_info_struct *att = g_srv_uc_p[instance]->msg.msg_body.attachment;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_srv_uc_p[instance]->msg.msg_body.attachment);

    for (; i < index; i++)
    {
        MMI_ASSERT(att);
        att = att->next;
    }
    return att;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_ref_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  index           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_slide_ref_object_struct *srv_uc_get_ref_by_index(U32 instance, U16 index)
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
        if (slide->ref_items!= NULL)
        {
            curr_ref = slide->ref_items;
            while (curr_ref != NULL)
            {
                if (curr_index == index)
                {
                    return curr_ref;
                }
                curr_index++;
                curr_ref = curr_ref->next;
            }
        }
        slide = slide->next;
    }
    MMI_ASSERT(0);  /* should be found in ref list */
    return curr_ref;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_reset_text_buffer
 * DESCRIPTION
 *  Reset text buffer
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uc_reset_text_buffer(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_srv_uc_p[instance]->main.text_buffer, 0, SRV_UC_TEXT_BUFFER_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_encoding_type_to_chset
 * DESCRIPTION
 *  convert encoding type (MSF_CHARSET_XXXX in mms module to MMI_CHSET_XXX in mmi module)
 * PARAMETERS
 *  encoding        [IN]        
 *  U32(?)
 * RETURNS
 *  U32
 *****************************************************************************/
mmi_chset_enum srv_uc_convert_encoding_type_to_chset(U32 encoding)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_charset_enum MMS_encoding = (mma_charset_enum) encoding;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (MMS_encoding)
    {
        case MMA_CHARSET_ASCII:
            return MMI_CHSET_ASCII;

        case MMA_CHARSET_ISO_8859_1:
            return MMI_CHSET_WESTERN_ISO;

        case MMA_CHARSET_UTF8:
            return MMI_CHSET_UTF8;

        case MMA_CHARSET_UCS2:
            return MMI_CHSET_UCS2;

        case MMA_CHARSET_UTF16BE:
            return MMI_CHSET_UTF16BE;

        case MMA_CHARSET_UTF16LE:
            return MMI_CHSET_UTF16LE;

        case MMA_CHARSET_UTF16:
            return MMI_CHSET_UTF16LE;   /* MMS can not diff LE or BE, here we treat it as LE */

        case MMA_CHARSET_GB2312:
            return MMI_CHSET_GB2312;
		
		case MMA_CHARSET_BIG5 :
			return MMI_CHSET_BIG5 ;

        default:
            return MMI_CHSET_UTF8;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_object_in_slide
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slide           [?]         
 *  object_type     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_mms_object_struct *srv_uc_get_object_in_slide(mma_mms_slide_struct *slide, srv_uc_object_type object_type)
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
            return slide->img.object;
        }
            

        case SRV_UC_OBJECT_TYPE_AUDIO:
        {
            return slide->aud.object;
        }
           

        case SRV_UC_OBJECT_TYPE_VIDEO:
        {
            return slide->vid.object;
        }
            

        default:
        {
            MMI_ASSERT(0);
        }
            
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_setting_msg_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
srv_uc_msg_type_enum srv_uc_get_setting_msg_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //S8 index = 0;
    //S16 errorCode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_STANDALONE_COMPOSER__
    return SRV_UC_MSG_TYPE_MMS_PREFER;
#else 
    return SRV_UC_MSG_TYPE_SMS_PREFER;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  index           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_uc_addr_struct *srv_uc_get_addr(U32 instance, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i = 0;
    srv_uc_addr_struct *addr = g_srv_uc_p[instance]->msg.to_head;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; i < index; i++)
    {
        MMI_ASSERT(addr->next);
        addr = addr->next;
    }
    return addr;
}

srv_uc_addr_struct *srv_uc_cpy_address(mma_mms_addr_list_struct *mms_address, U32 instance)
{
	//mma_mms_addr_list_struct *mms_address_head = mms_address ;
	srv_uc_addr_struct *uc_addr_head = NULL ;
	srv_uc_addr_struct *new_addr_allocated = NULL ;
	srv_uc_addr_struct *previous_addr = NULL ;

	while(mms_address)
	{
		new_addr_allocated = g_srv_uc_p[instance]->alloc(sizeof(srv_uc_addr_struct), g_srv_uc_p[instance]->user_data);
		MMI_ASSERT(new_addr_allocated);
		memset(new_addr_allocated, 0 ,sizeof(srv_uc_addr_struct));

		new_addr_allocated->addr =(kal_uint8 *) g_srv_uc_p[instance]->alloc((SRV_UC_MAX_EMAIL_LEN + 1)*ENCODING_LENGTH, g_srv_uc_p[instance]->user_data);
		MMI_ASSERT(new_addr_allocated->addr);
		memset(new_addr_allocated->addr, 0 ,(SRV_UC_MAX_EMAIL_LEN + 1)*ENCODING_LENGTH);

		//mmi_ucs2cpy((S8 *)new_addr_allocated->addr ,(S8 *)mms_address->address);
		//mmi_ucs2cpy((S8 *)new_addr_allocated->addr,(S8 *)mms_address->address);
		if(mms_address->addr_type == MMA_ADDR_TYPE_PHONE_NUMBER)
		{
			memcpy(new_addr_allocated->addr , mms_address->address ,(strlen((S8*)mms_address->address)+1));
		}
		else
		{
			mmi_chset_utf8_to_ucs2_string(new_addr_allocated->addr ,(SRV_UC_MAX_EMAIL_LEN + 1)*ENCODING_LENGTH , (kal_uint8*)mms_address->address);
		}
		new_addr_allocated->type = srv_uc_convert_mma_addr_type_to_uc_addr_type((mma_addr_type_enum)mms_address->addr_type) ;
		new_addr_allocated->group = srv_uc_convert_mma_addr_group_to_uc_addr_group((mma_address_group_type_enum)mms_address->group); 
		new_addr_allocated->next = NULL ;
		//first entry
		if(!uc_addr_head)
		{
			uc_addr_head = new_addr_allocated ;
			previous_addr = new_addr_allocated ;
		}
		else
		{
			//link list management
			previous_addr->next = new_addr_allocated;
			new_addr_allocated->previous = previous_addr ;
			previous_addr = new_addr_allocated ;
		}

		mms_address = mms_address->next;
	}
	return uc_addr_head ;
}

mma_mms_addr_list_struct *srv_uc_convert_uc_addr_to_mms_addr(srv_uc_addr_struct *uc_address, U32 instance)
{
	//mma_mms_addr_list_struct *mms_address_head = mms_address ;
	mma_mms_addr_list_struct *mms_addr_head = NULL ;
	mma_mms_addr_list_struct *new_addr_allocated = NULL ;
	mma_mms_addr_list_struct *previous_addr = NULL ;

	while(uc_address)
	{
		new_addr_allocated = g_srv_uc_p[instance]->alloc(sizeof(mma_mms_addr_list_struct), g_srv_uc_p[instance]->user_data);
		MMI_ASSERT(new_addr_allocated);
		memset(new_addr_allocated, 0 ,sizeof(mma_mms_addr_list_struct));

		new_addr_allocated->address =(kal_char *) g_srv_uc_p[instance]->alloc((SRV_UC_MAX_EMAIL_LEN + 1)*ENCODING_LENGTH, g_srv_uc_p[instance]->user_data);
		MMI_ASSERT(new_addr_allocated->address);
		memset(new_addr_allocated->address, 0 ,(SRV_UC_MAX_EMAIL_LEN + 1)*ENCODING_LENGTH);

		if(uc_address->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
		{
			memcpy((S8 *)new_addr_allocated->address ,(S8 *)uc_address->addr, (strlen((S8*)uc_address->addr)+1));
		}
		else
		{
			mmi_chset_ucs2_to_utf8_string((kal_uint8 *)new_addr_allocated->address,(SRV_UC_MAX_EMAIL_LEN + 1)*ENCODING_LENGTH,(kal_uint8 *)uc_address->addr);
		}
		new_addr_allocated->addr_type = srv_uc_convert_uc_addrtype_to_mma(uc_address->type) ;
		new_addr_allocated->group = srv_uc_convert_uc_addr_group_to_mma_addr_group(uc_address->group); 
		new_addr_allocated->next = NULL ;
		//first entry
		if(!mms_addr_head)
		{
			mms_addr_head = new_addr_allocated ;
			previous_addr = new_addr_allocated ;
		}
		else
		{
			//link list management
			previous_addr->next = new_addr_allocated;
			new_addr_allocated->prev = previous_addr ;
			previous_addr = new_addr_allocated ;
		}

		uc_address = uc_address->next;
	}
	return mms_addr_head ;
}

void srv_uc_free_mem_alloc_for_mma_addr(mma_mms_addr_list_struct *addr_head, U32 instance)
{
	mma_mms_addr_list_struct *temp_addr = NULL ;
	while(addr_head)
	{
		temp_addr = addr_head ;
		addr_head = addr_head->next ;
		g_srv_uc_p[instance]->free(temp_addr->address, g_srv_uc_p[instance]->user_data); 
		g_srv_uc_p[instance]->free(temp_addr, g_srv_uc_p[instance]->user_data); 
		temp_addr = NULL ;
	}

}
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_UCS2_phone_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  addr_group_type     [IN]        
 *  index               [IN]        
 *  pOutBuffer          [?]         
 *  max_buf_len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_uc_get_UCS2_phone_number(
            srv_uc_address_group_type_enum addr_group_type,
            U16 index,
            U8 *pOutBuffer,
            U32 max_buf_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uc_addr_struct *addr = NULL;
    U32 digit_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addr = srv_uc_get_addr(addr_group_type, index);
    /* addr->addr: ascii for phone number while ucs2 for email address. NULL terminator is needed */
    if (addr->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
    {
        U32 ascii_addr_len = strlen((S8*) addr->addr);

        digit_num =
            (ascii_addr_len * ENCODING_LENGTH <= max_buf_len) ? ascii_addr_len : (max_buf_len / ENCODING_LENGTH);
        mmi_asc_n_to_ucs2((s8*) pOutBuffer, (S8*) addr->addr, digit_num);
    }
    else
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__


/*****************************************************************************
 * FUNCTION
 *  srv_uc_phb_notify_check_by_addr_group_type
 * DESCRIPTION
 *  check and add address to phb notify list based on addr group type (to/cc/bcc)
 * PARAMETERS
 *  instance            [IN]        
 *  addr_group_type     [IN]        
 * RETURNS
 *  return how many addresses are added
 *****************************************************************************/
U32 srv_uc_phb_notify_check_by_addr_group_type(U32 instance, srv_uc_address_group_type_enum addr_group_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ucs2_phb_num_tmp_buff[(SRV_UC_MAX_PHONE_NUMBER_LEN + 1 + 1) * ENCODING_LENGTH]; /* 1 for null terminate, 1 for + */
    U32 added_num = 0;
    U8 i;
    U8 group_addr_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_UC_ADDRESS_GROUP_TYPE_TO == addr_group_type)
    {
        group_addr_num = g_srv_uc_p[instance]->msg.to_num;
    }
    for (i = 0; i < group_addr_num; i++)
    {
        memset(ucs2_phb_num_tmp_buff, 0, sizeof(ucs2_phb_num_tmp_buff));
        /* the max_buf_len should not include the null terminater */

        if (srv_uc_get_UCS2_phone_number(addr_group_type, i, ucs2_phb_num_tmp_buff, (MMI_PHB_NUMBER_LENGTH + 1) * ENCODING_LENGTH))      /* 1 for + */
        {
            if (!mmi_phb_is_num_in_phb((U16 *)ucs2_phb_num_tmp_buff))
            {
                srv_phb_contact_data_struct phb_data;

                memset(&phb_data, 0, sizeof(srv_phb_contact_data_struct));
                mmi_phb_unsaved_data_init(&phb_data);
				phb_data.number = (U16 *) ucs2_phb_num_tmp_buff;
	        	mmi_phb_add_data_to_unsaved_list(PHB_STORAGE_MAX, SRV_PHB_ENTRY_FIELD_NUMBER, &phb_data);
                added_num++;
            }
        }
    }
    return added_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_check_and_add_addr_to_phb_notify_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 *  type            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_uc_check_and_add_addr_to_phb_notify_list(U32 instance, srv_uc_phb_list_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 total_added_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if the number is in phb, if not, will add it to pbh notify list */
    switch (type)
    {
        case (SRV_UC_PHB_LIST_TYPE_SMS):
        {
            total_added_num = srv_uc_phb_notify_check_by_addr_group_type(instance, SRV_UC_ADDRESS_GROUP_TYPE_TO);
            break;
        }

        case (SRV_UC_PHB_LIST_TYPE_NORMAL_MMS):
        {
            total_added_num = srv_uc_phb_notify_check_by_addr_group_type(instance, SRV_UC_ADDRESS_GROUP_TYPE_TO);
            total_added_num += srv_uc_phb_notify_check_by_addr_group_type(instance, SRV_UC_ADDRESS_GROUP_TYPE_CC);
            total_added_num += srv_uc_phb_notify_check_by_addr_group_type(instance, SRV_UC_ADDRESS_GROUP_TYPE_BCC);
            break;
        }

        case (SRV_UC_PHB_LIST_TYPE_POSTCARD_MMS):
        {

            break;
        }

        default:
        {
            MMI_ASSERT(0);
            break;
        }

    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CHECK_AND_ADD_ADDR_TO_PHB_NOTIFY_LIST_P2, type, total_added_num);
    return total_added_num;
}

#endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_uc_update_object_id
 * DESCRIPTION
 *  Update object ID
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_update_object_id(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 1;
    mma_mms_object_struct *object = g_srv_uc_p[instance]->msg.msg_body.objects;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; i <= g_srv_uc_p[instance]->msg.msg_body.obj_no; i++)
    {
        MMI_ASSERT(object);
        object->id = i;
        object = object->next;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_to_mms_insert_type
 * DESCRIPTION
 *  Insert object
 * PARAMETERS
 *  object_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_uc_convert_to_mms_insert_type(srv_uc_object_type object_type)
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
            return MMA_INSERT_IMAGE;
        }
           

        case SRV_UC_OBJECT_TYPE_AUDIO:
        {
            return MMA_INSERT_AUDIO;
        }
            

        case SRV_UC_OBJECT_TYPE_VIDEO:
        {
            return MMA_INSERT_VIDEO;
        }
            

        case SRV_UC_OBJECT_TYPE_ATTACHMENT:
        {
            return MMA_INSERT_ATTACHMENT;
        }
           

        case SRV_UC_OBJECT_TYPE_TEXT:
        {
            return MMA_INSERT_TEXT;
        }
           

        case SRV_UC_OBJECT_TYPE_REF:
        {
            return MMA_INSERT_ATTACHMENT;   /* MMA will treat ref to be a attachment. */
        }
            
        default:
        {
            MMI_ASSERT(0);
        }
            
    }

    return MMA_INSERT_UNKNOWN;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_mms_insert_type_to_uc
 * DESCRIPTION
 *  Insert object
 * PARAMETERS
 *  object_type     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_uc_object_type srv_uc_convert_mms_insert_type_to_uc(U32 object_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (object_type)
    {
        case MMA_INSERT_IMAGE:
        {
            return SRV_UC_OBJECT_TYPE_IMAGE;
        }
           

        case MMA_INSERT_AUDIO:
        {
            return SRV_UC_OBJECT_TYPE_AUDIO;
        }
            

        case MMA_INSERT_VIDEO:
        {
            return SRV_UC_OBJECT_TYPE_VIDEO;
        }
           

        case MMA_INSERT_ATTACHMENT:
        {
            return SRV_UC_OBJECT_TYPE_ATTACHMENT;
        }
            

        case MMA_INSERT_TEXT:
        {
            return SRV_UC_OBJECT_TYPE_TEXT;
        }
           

        default:
        {
            MMI_ASSERT(0);
        }
            
    }

   return SRV_UC_OBJECT_TYPE_UNKNOWN;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_mms_app_mode_to_uc_state
 * DESCRIPTION
 *  Convert mma_app_mode_enum to srv_uc_state_enum
 * PARAMETERS
 *  app_mode        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_uc_convert_mms_app_mode_to_uc_state(U16 app_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 uc_state = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (app_mode)
    {
        case MMA_MODE_SEND:
        {
            uc_state = SRV_UC_STATE_SEND;
        }
            break;
        case MMA_MODE_FORWARD:
        {
            uc_state = SRV_UC_STATE_FORWARD;
        }
            break;
        case MMA_MODE_REPLY:
        {
            uc_state = SRV_UC_STATE_REPLY;
        }
            break;
        case MMA_MODE_REPLY_ALL:
        {
            uc_state = SRV_UC_STATE_REPLY_ALL;
        }
            break;
        case MMA_MODE_EDIT:
        {
            uc_state = SRV_UC_STATE_EDIT_EXISTED_MSG;
        }
            break;
        default:
        {
            MMI_ASSERT(0);
        }
            break;
    }

    return uc_state;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_uc_state_to_mms_app_mode
 * DESCRIPTION
 *  Convert srv_uc_state_enum to mma_app_mode_enum
 * PARAMETERS
 *  state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_uc_convert_uc_state_to_mms_app_mode(U16 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 app_mode = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (state)
    {
        case SRV_UC_STATE_SEND:
        {
            app_mode = MMA_MODE_SEND;
        }
            break;
        case SRV_UC_STATE_FORWARD:
        {
            app_mode = MMA_MODE_FORWARD;
        }
            break;
        case SRV_UC_STATE_REPLY:
        {
            app_mode = MMA_MODE_REPLY;
        }
            break;
        case SRV_UC_STATE_REPLY_ALL:
        {
            app_mode = MMA_MODE_REPLY_ALL;
        }
            break;
        case SRV_UC_STATE_EDIT_EXISTED_MSG:
        {
            app_mode = MMA_MODE_EDIT;
        }
            break;
        default:
        {
            MMI_ASSERT(0);
        }
            break;
    }

    return app_mode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_uc_sim_id_to_mma
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_uc_convert_uc_sim_id_to_mma(srv_uc_sim_id sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 mma_sim_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {
        case SRV_UC_SIM_ID_GSM_SIM1:
        {
            mma_sim_id = MMA_SIM_ID_SIM1;
        }
            break;
        case SRV_UC_SIM_ID_GSM_SIM2:
        {
            mma_sim_id = MMA_SIM_ID_SIM2;
        }
            break;
	case SRV_UC_SIM_ID_GSM_SIM3:
        {
            mma_sim_id = MMA_SIM_ID_SIM3;
        }
            break;
	case SRV_UC_SIM_ID_GSM_SIM4:
        {
            mma_sim_id = MMA_SIM_ID_SIM4;
        }
            break;
        default:
        {
            ASSERT(0);
        }
    }
    return mma_sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_mms_check_result
 * DESCRIPTION
 *  Translate mms_uc_insert_check_struct to srv_uc_result
 * PARAMETERS
 *  check_result        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
srv_uc_result srv_uc_convert_mms_check_result(mma_insert_check_struct *check_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (check_result->result)
    {
        return SRV_UC_OK;
    }
    else
    {
        MMI_TRACE(
            MMI_COMMON_TRC_G6_MSG,
            TRC_MMI_UC_CONVERT_MMS_CHECK_RESULT_P3,
            check_result->oversize,
            check_result->creation_mode_violate,
            check_result->drm_type);

        if (check_result->detail_result == MMA_RESULT_FAIL_INSUFFICIENT_MEMORY)
        {
            return SRV_UC_INSUFFICIENT_MEMORY;
        }
    #ifdef __MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__
        if (check_result->detail_result == MMA_RESULT_FAIL_WAP_CONN_MAX_MSG_SIZE_REACHED)
        {
            return SRV_UC_WAP_CONN_MAX_MSG_SIZE_REACHED;
        }
    #endif /* __MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__ */ 

        if ((check_result->oversize) && (check_result->detail_result == MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED))
        {
            return SRV_UC_SIZE_EXCEEDS;
        }

        if ((check_result->oversize) &&
            (check_result->detail_result == MMA_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED))
        {
            return SRV_UC_CREATION_MODE_SIZE_EXCEEDS;
        }
        if (check_result->creation_mode_violate)
        {
            return SRV_UC_PROHIBIT_BY_CREATION_MODE;
        }

        if (check_result->drm_type == MMA_DRM_FL_CD || check_result->drm_type == MMA_DRM_SD_NO_RIGHT)
        {
            return SRV_UC_PROHIBIT_BY_DRM;
        }
        if ((check_result->detail_result == MMA_RESULT_FAIL_FILE_IO) ||
            (check_result->detail_result == MMA_RESULT_FAIL_FILE_CORRUPTED))
        {
            return SRV_UC_FILE_CORRUPT;
        }

        if (check_result->detail_result == MMA_RESULT_FAIL_FILE_EMPTY)
        {
            return SRV_UC_FILE_EMPTY;
        }
        if (check_result->detail_result == MMA_RESULT_FAIL_FILE_NOT_FOUND)
        {
            return SRV_UC_FILE_NOT_FOUND;
        }
        if (check_result->detail_result == MMA_RESULT_FAIL_FOLDER_NOT_FOUND)
        {
            return SRV_UC_FOLDER_NOT_FOUND;
        }
        if (check_result->detail_result == MMA_RESULT_FAIL_IN_VIDEO_CALL)
        {
            return SRV_UC_FAIL_IN_VIDEO_CALL;
        }
        if (check_result->detail_result == MMA_RESULT_FAIL_IMAGE_TOO_LARGE)
        {
            return SRV_UC_FAIL_IMAGE_TOO_LARGE;
        }
    }

    return SRV_UC_NOT_SUPPORT;
}

#ifdef __MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_uc_fit_text_for_ut8_length_to_subject
 * DESCRIPTION
 *  Function to take only buffer upto limit
 * PARAMETERS
 *  instance        [IN]            
 *  buffer(?)       [IN/OUT]        To change the string buffer to the passed size
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uc_fit_text_for_ut8_length_to_subject(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 char_len;
    U16 ucs2_char;
    S32 text_length = 0, buffer_size = (SRV_UC_MAX_SUBJECT_LEN + 1);
    U8 *buffer = (kal_uint8*) g_srv_uc_p[instance]->msg.subject;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ucs2_char = (buffer[i]) | ((buffer[i + 1] << 8));
    char_len = app_unicode_to_utf8_len(ucs2_char);
    while (ucs2_char && (text_length + char_len <= (buffer_size - 1)))
    {
        text_length += char_len;
        i += ENCODING_LENGTH;
        ucs2_char = (buffer[i]) | ((buffer[i + 1] << 8));
        char_len = app_unicode_to_utf8_len(ucs2_char);
    }
    buffer[i] = 0;
    buffer[i + 1] = 0;
}
#endif /* __MMI_MMS_OMA_SUBJECT_LENGTH_SUPPORT__ */ 

#ifdef __MMI_MMS_CHARACTER_NUM_SUBJECT_LENGTH_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_uc_ucs2_to_gb_len
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ucs2_char       [IN]        
 *  buffer(?)       [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_uc_ucs2_to_gb_len(U16 ucs2_char)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ucs2_char <= 255)
        return 1;
    else
        return 2;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_fit_text_for_gb_length_to_subject
 * DESCRIPTION
 *  Function to take only buffer upto limit
 * PARAMETERS
 *  instance        [IN]            
 *  buffer(?)       [IN/OUT]        To change the string buffer to the passed size
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uc_fit_text_for_gb_length_to_subject(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 char_len;
    U16 ucs2_char;
    S32 text_length = 0, buffer_size = (SRV_UC_MAX_SUBJECT_LEN + 1);
    U8 *buffer = (kal_uint8*) g_srv_uc_p[instance]->msg.subject;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ucs2_char = (buffer[i]) | ((buffer[i + 1] << 8));
    char_len = srv_uc_ucs2_to_gb_len(ucs2_char);
    while (ucs2_char && (text_length + char_len <= (buffer_size - 1)))
    {
        text_length += char_len;
        i += ENCODING_LENGTH;
        ucs2_char = (buffer[i]) | ((buffer[i + 1] << 8));
        char_len = srv_uc_ucs2_to_gb_len(ucs2_char);
    }
    buffer[i] = 0;
    buffer[i + 1] = 0;
}
#endif /* __MMI_MMS_CHARACTER_NUM_SUBJECT_LENGTH_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_ascii_hex_to_dec
 * DESCRIPTION
 *  Converts Ascii value to Decimal value
 * PARAMETERS
 *  character       [IN]        
 *  S8 ascii values(?)(?)
 * RETURNS
 *  U8 Decimal value.
 *****************************************************************************/
U32 srv_uc_convert_ascii_hex_to_dec(U8 *character)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 value = 0;
    U8 c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Skip prefix "0x" or "0X" */
    if (character[0] == '0' && (character[1] == 'x' || character[1] == 'X'))
    {
        i = 2;
    }

    while ((c = character[i]) != 0)
    {
        value = value * 16;

        if (c > 47 && c < 58)   /* Digits 0..9 */
        {
            value += (c - 48);
        }
        else if (c > 64 && c < 71)  /* Characters A..F */
        {
            value += (c - 55);
        }
        else if (c > 96 && c < 103) /* Characters a..f */
        {
            value += (c - 87);
        }
        i++;
    }
    return value;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_object_by_id
 * DESCRIPTION
 *  Get object pointer by object id
 * PARAMETERS
 *  instance        [IN]        
 *  object_id       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mma_mms_object_struct *srv_uc_get_object_by_id(U32 instance, U32 object_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *cur_object = g_srv_uc_p[instance]->msg.msg_body.objects;
    U32 object_num = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; cur_object != NULL; cur_object = cur_object->next, object_num++)
    {
        MMI_ASSERT(object_num <= g_srv_uc_p[instance]->msg.msg_body.obj_no);

        if (cur_object->id == object_id)
        {
            return cur_object;
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_check_only_attachment
 * DESCRIPTION
 *  Only attachments and one empty slide.
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
BOOL srv_uc_check_only_attachment(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* No use now so have empty body. But can be write on requirement bases. */
    return MMI_FALSE;
}

#ifndef __MMI_MMS_STANDALONE_COMPOSER__


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_sms_setting
 * DESCRIPTION
 *  Get SMS setting
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uc_get_sms_setting(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_uc_p[instance]->sms_info.max_gsm7bit_char_num = (srv_sms_get_usable_text_len(SMSAL_DEFAULT_DCS) / 2);
    g_srv_uc_p[instance]->sms_info.max_ucs2_char_num = (srv_sms_get_usable_text_len(SMSAL_UCS2_DCS) / 2);
}
#endif /* __MMI_MMS_STANDALONE_COMPOSER__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_uc_reset_layout_if_needed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_reset_layout_if_needed(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *object = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (object = g_srv_uc_p[instance]->msg.msg_body.objects; object != NULL; object = object->next)
    {
        if (object->type == MMA_MMS_OBJECT_TYPE_IMAGE || object->type == MMA_MMS_OBJECT_TYPE_VIDEO)
        {
            break;
        }
    }

    if (object == NULL)
    {
        g_srv_uc_p[instance]->msg.msg_body.layout =  MMA_LAYOUT_NONE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_is_phone_number_valid
 * DESCRIPTION
 *  return T if the phone number is valid
 * PARAMETERS
 *  strNumber       [IN]        
 * RETURNS
 *  pBOOL
 *****************************************************************************/
BOOL srv_uc_is_phone_number_valid(S8 *strNumber)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8 ucs2_string[(APPLIB_MAX_PHONE_NUM_LEN +1) * ENCODING_LENGTH] = {0,};
	S8 acs_string[APPLIB_MAX_PHONE_NUM_LEN + 1] = {0,};
	S8 *number = NULL;
	S32 numberlen = 0;
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	numberlen = mmi_ucs2strlen(strNumber);
    if (numberlen == 0)
    {
        return MMI_FALSE;
    }
    if (applib_is_valid_number_unicode((kal_wchar*) strNumber) != APPLIB_INVALID_NUMBER)
    {
		memcpy(ucs2_string, strNumber, APPLIB_MAX_PHONE_NUM_LEN*ENCODING_LENGTH);
		app_ucs2_str_to_asc_str((kal_int8 *)acs_string, (kal_int8 *) ucs2_string);
		number = acs_string;
        if (acs_string[0] == '+')
        {
            numberlen = numberlen - 1;
            number++;
        }
        if (numberlen == 0)
        {
            return FALSE;
        }
        for (i = 0; i < numberlen; i++)
        {
            U8 digit = number[i];
        
            if ((digit < '0' || digit > '9') && digit != '*' && digit != '#')
            {
                return MMI_FALSE;
            }
        }
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_is_email_addr_valid
 * DESCRIPTION
 *  Return if email address valid
 * PARAMETERS
 *  addr                [?]         
 *  screen_id(?)        [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
BOOL srv_uc_is_email_addr_valid(U8 *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 email_addr_len = mmi_ucs2strlen((S8*) addr);
    U16 i = 0;
    U16 *email_addr = (U16*) addr;
    U16 j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; i < email_addr_len; i++)
    {
        if (mmi_ucs2ncmp((S8*) & email_addr[i], (S8*) L"@", 1) == 0)
        {
            if (i == 0 || i == (email_addr_len - 1))
            {
                return FALSE;
            }
            else
            {
                U8 *ascii_addr = NULL;

                for (; j < email_addr_len; j++)
                {
                    U16 ucs2_char = email_addr[j];

                    /* non-ascii char */
                    if ((ucs2_char & 0xFF00) > 0)
                    {
                        return FALSE;
                    }
                }

                ascii_addr = OslMalloc(email_addr_len + 1);
                memset(ascii_addr, 0, (email_addr_len + 1));

                mmi_ucs2_n_to_asc((S8*) ascii_addr, (S8*) addr, email_addr_len * ENCODING_LENGTH);

                if (applib_is_valid_email_address((char*)ascii_addr) == KAL_TRUE)
                {
                    OslMfree(ascii_addr);
                    return TRUE;
                }

                OslMfree(ascii_addr);
                return FALSE;
            }
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_compare_string_ignore_case
 * DESCRIPTION
 *  Compare string by ignoring case.
 * PARAMETERS
 *  addr_1      [?]     
 *  addr_2      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_uc_compare_string_ignore_case(U16 *addr_1, U16 *addr_2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 addr_index = 0;
    U16 char_A = 0x0041;
    U16 char_Z = 0x005A;
    U16 char_a = 0x0061;
    U16 addr_1_len = mmi_ucs2strlen((S8*) addr_1);
    U16 addr_2_len = mmi_ucs2strlen((S8*) addr_2);
    U16 addr_1_char = 0;
    U16 addr_2_char = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr_1_len != addr_2_len)
    {
        return MMI_FALSE;
    }

    while (addr_index < addr_1_len)
    {
        if (addr_1[addr_index] >= char_A && addr_1[addr_index] <= char_Z)
        {
            addr_1_char = char_a + addr_1[addr_index] - char_A;
        }
        else
        {
            addr_1_char = addr_1[addr_index];
        }
        if (addr_2[addr_index] >= char_A && addr_2[addr_index] <= char_Z)
        {
            addr_2_char = char_a + addr_2[addr_index] - char_A;
        }
        else
        {
            addr_2_char = addr_2[addr_index];
        }

        if (addr_1_char != addr_2_char)
        {
            return MMI_FALSE;
        }
        addr_index++;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_update_text_object_path
 * DESCRIPTION
 *  Update text object file path
 * PARAMETERS
 *  instance        [IN]        
 *  slide           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uc_update_text_object_path(U32 instance, mma_mms_slide_struct *slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 srv_uc_text_path[SRV_UC_MAX_TEMP_FILE_LEN];
    mma_mms_object_struct *object = NULL;
    U16 *file_name;
    U16 file_path_len = 0;
    U16 file_name_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(slide != NULL);
    memset(srv_uc_text_path, 0, SRV_UC_MAX_TEMP_FILE_LEN);
    SRV_UC_MAKE_TEXT_FILE_PATH(srv_uc_text_path, slide->slide_num, instance);
    file_path_len = mmi_ucs2strlen((S8*) srv_uc_text_path);

    if ((object = slide->txt.object) != NULL)
    {
        if (FS_Rename((U16*) object->file_path_ucs, (U16*) srv_uc_text_path) != FS_NO_ERROR)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_UPDATE_TEXT_OBJ_PATH_FAIL);
            return;
        }

        /* file path */
        if (object->file_path_ucs != NULL)
        {
            g_srv_uc_p[instance]->free(object->file_path_ucs, g_srv_uc_p[instance]->user_data);
            object->file_path_ucs = NULL;
        }
        object->file_path_ucs = g_srv_uc_p[instance]->alloc((file_path_len + 1) * 2, g_srv_uc_p[instance]->user_data);
        MMI_ASSERT(object->file_path_ucs);
        memset(object->file_path_ucs, 0, (file_path_len + 1) * 2);
        mmi_ucs2ncpy((S8*) object->file_path_ucs, (S8*) srv_uc_text_path, file_path_len);

        /* file name */
        if (object->file_name_ucs != NULL)
        {
            g_srv_uc_p[instance]->free(object->file_name_ucs, g_srv_uc_p[instance]->user_data);
            object->file_name_ucs = NULL;
        }
        file_name = srv_uc_get_file_name((U16*) srv_uc_text_path);
        file_name_len = mmi_ucs2strlen((S8*) file_name);
        object->file_name_ucs = g_srv_uc_p[instance]->alloc((file_name_len + 1) * 2, g_srv_uc_p[instance]->user_data);
        MMI_ASSERT(object->file_name_ucs);
        memset(object->file_name_ucs, 0, (file_name_len + 1) * 2);
        mmi_ucs2ncpy((S8*) object->file_name_ucs, (S8*) file_name, file_name_len);
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_end_slide
 * DESCRIPTION
 *  get the last slide
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mma_mms_slide_struct *srv_uc_get_end_slide(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *slide = g_srv_uc_p[instance]->msg.msg_body.slides;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slide == NULL)
    {
        return NULL;
    }

    while (slide->next != NULL)
    {
        slide = slide->next;
    }
    return slide;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_is_pending_action
 * DESCRIPTION
 *  Check if uc has pending action
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool srv_uc_is_pending_action(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_IS_PENDING_ACTION_P1, g_srv_uc_p[instance]->send_info.action);
    if (g_srv_uc_p[instance]->send_info.action != SRV_UC_ACTION_IDLE)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_check_number_length_for_sms
 * DESCRIPTION
 *  Check if number length exceeds SMS limitation
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_uc_check_number_length_for_sms(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 plus_char = '+';
    S32 number_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    number_len = strlen((S8*)g_srv_uc_p[instance]->msg.to_head->addr);
    
    if ((number_len < SRV_SMS_MAX_ADDR_LEN) ||
        ((number_len == SRV_SMS_MAX_ADDR_LEN) && (strncmp((S8*)g_srv_uc_p[instance]->msg.to_head->addr, &plus_char, 1) == 0)))
    {
        return (U8)MMI_TRUE;
    }
    else
    {
        return (U8)MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_check_number_length_for_sms_in_send_case
 * DESCRIPTION
 *  Check if number length exceeds SMS limitation
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_uc_check_number_length_for_sms_in_send_case(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 plus_char = '+';
    S32 number_len;
	S32 i;
	U8 addr_result = MMI_TRUE;
	srv_uc_addr_struct *temp_addr;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	temp_addr = g_srv_uc_p[instance]->msg.to_head;
	for ( i=0; i< g_srv_uc_p[instance]->msg.to_num && temp_addr != NULL; i++, temp_addr = temp_addr->next)
	{
		number_len = strlen((S8*)temp_addr->addr);//g_srv_uc_p[instance]->msg.to_head->addr);
    
		if ((number_len < SRV_SMS_MAX_ADDR_LEN) ||
			((number_len == SRV_SMS_MAX_ADDR_LEN) && (strncmp((S8*)temp_addr->addr, &plus_char, 1) == 0)))
		{
			addr_result = MMI_TRUE;
		}
		else
		{
			addr_result = MMI_FALSE;
			break;
		}
	}

	return addr_result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_uc_check_virtual_file_object_for_creation_mode
 * DESCRIPTION
 *  Check if the virtual file can be inserted into existed msg
 * PARAMETERS
 *  instance        [IN]        
 *  obj             [?]         
 *  type            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_uc_check_virtual_file_object_for_creation_mode(
        U32 instance,
        mma_mms_object_struct *obj,
        srv_uc_object_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_insert_check_struct check_result;
    mma_mms_object_struct *object = obj;
    S32 file_handle = 0;
    mma_insert_type_enum mms_type = (mma_insert_type_enum)srv_uc_convert_to_mms_insert_type(type);
    U32 temp_max_size = 0;
    mma_insert_info_struct insert_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&check_result, 0, sizeof(mma_insert_check_struct));

    if (object->is_virtual_file)
    {
        U8 virtual_file_name[(FS_GenVFN_SIZE + SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1) * ENCODING_LENGTH];
        S32 result;
        U16 virtual_file_name_len = sizeof(virtual_file_name);

        memset(virtual_file_name, 0, virtual_file_name_len);

        file_handle = FS_Open((const WCHAR *)object->file_path_ucs, FS_READ_ONLY | FS_OPEN_SHARED);

        if (file_handle <= 0)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CHECK_VF_OBJ_FILE_HANDLE, file_handle);
            return MMI_FALSE;
            //MMI_ASSERT(0);
        }

        result = FS_GenVirtualFileName(
                    file_handle,
                    (U16*) virtual_file_name,
                    (unsigned int)FS_GenVFN_SIZE,
                    object->offset,
                    object->size);

        if (result < 0)
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CHECK_VF_OBJ_VIR_FILE, result);
            return MMI_FALSE;
            //MMI_ASSERT(0);
        }

        mmi_ucs2cat((PS8) virtual_file_name, (PS8) L".");
        if (srv_uc_get_file_extension((U16 *)object->file_name_ucs))
        {
            mmi_ucs2ncat(
                (PS8) virtual_file_name,
                (PS8) srv_uc_get_file_extension((U16 *)object->file_name_ucs),
                virtual_file_name_len / ENCODING_LENGTH);
        }
        else
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CHECK_VF_OBJ_NO_EXT_NAME);
        }

        insert_info.creation_mode = g_srv_uc_p[instance]->mms_info.creation_mode;
        insert_info.current_msg_size = 0;
    #ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
        temp_max_size = wap_custom_get_max_mms_msg_size();
    #else 
        temp_max_size = g_srv_uc_p[instance]->mms_info.max_mms_size;
    #endif 
        insert_info.max_msg_size = temp_max_size - srv_uc_reserved_size(instance);
        insert_info.insert_type = mms_type;
        insert_info.filepath = (kal_wchar*) virtual_file_name;
        insert_info.mms_type = srv_uc_get_mms_type(instance);

        mma_uc_insert_object_check(&insert_info, &check_result);

        FS_Close(file_handle);

        if (check_result.result == MMI_FALSE && check_result.creation_mode_violate == MMI_TRUE)
        {
            return MMI_FALSE;
        }
        object->drm_type = check_result.drm_type;
    }
    else
    {
        MMI_ASSERT(0);
		MMI_PRINT(MOD_MMI_COMMON_APP,MMI_COMMON_TRC_G6_MSG, TRC_SRV_UC_ASSERT, __LINE__, __FILE__);
    }

    return MMI_TRUE;
}
 /*****************************************************************************
 * FUNCTION
 *  srv_uc_make_vcard_file_path
 * DESCRIPTION
 *  Check if the image is the resize image which created by UC
 * PARAMETERS
 *  srv_uc_image_path       [?]     
 *  U8*(?)
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_make_vcard_file_path(U8 *srv_uc_image_path, U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct time;
    U32 time_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_secure_time(&time);
    time_value = applib_dt_mytime_2_utc_sec(&time, KAL_TRUE);
    kal_wsprintf(
        (kal_uint16*) srv_uc_image_path,
        "%c:\\%s%03d\\%s%d.%s",
        SRV_UC_FOLDER_DRV,
        SRV_UC_FOLDER_NAME,
        instance,
        SRV_UC_VCARD_FILENAME,
        time_value,
        SRV_UC_VCARD_FILEEXT);
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_uc_make_image_file_path
 * DESCRIPTION
 *  Check if the image is the resize image which created by UC
 * PARAMETERS
 *  srv_uc_image_path       [?]     
 *  U8*(?)
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_make_image_file_path(U8 *srv_uc_image_path, U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct time;
    U32 time_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_secure_time(&time);
    time_value = applib_dt_mytime_2_utc_sec(&time, KAL_TRUE);
    kal_wsprintf(
        (kal_uint16*) srv_uc_image_path,
        "%c:\\%s%03d\\%s%d.%s",
        SRV_UC_FOLDER_DRV,
        SRV_UC_FOLDER_NAME,
        instance,
        SRV_UC_IMAGE_FILENAME,
        time_value,
        SRV_UC_IMAGE_FILEEXT);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_make_signature_image_file_path
 * DESCRIPTION
 *  Check if the image is the resize image which created by UC
 * PARAMETERS
 *  srv_uc_image_path       [?]     
 *  U8*(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uc_make_signature_image_file_path(U8 *srv_uc_image_path, U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct time;
    U32 time_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_secure_time(&time);
    time_value = applib_dt_mytime_2_utc_sec(&time, KAL_TRUE);
    kal_wsprintf(
        (kal_uint16*) srv_uc_image_path,
        "%c:\\%s%03d\\%s%d.%s",
        SRV_UC_FOLDER_DRV,
        SRV_UC_FOLDER_NAME,
        instance,
        SRV_UC_SIGNATURE_IMAGE_FILENAME,
        time_value,
        SRV_UC_IMAGE_FILEEXT);
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_is_resized_image
 * DESCRIPTION
 *  Check if the image is the resize image which created by UC
 * PARAMETERS
 *  file_path       [?]     
 * RETURNS
 *  TRUE means the image is the resize image which created by UC.
 *****************************************************************************/
MMI_BOOL srv_uc_is_resized_image(U16 *file_path, U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 srv_uc_image_path[SRV_UC_MAX_TEMP_FILE_LEN];
    //U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(srv_uc_image_path, 0, SRV_UC_MAX_TEMP_FILE_LEN);
    kal_wsprintf(
        (kal_uint16*) srv_uc_image_path,
        "%c:\\%s%03d\\%s",
        SRV_UC_FOLDER_DRV,
        SRV_UC_FOLDER_NAME,
        instance,
        SRV_UC_IMAGE_FILENAME);

    if (app_ucs2_strstr((kal_wchar*) file_path, (kal_wchar*) srv_uc_image_path))
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_IS_RESIZED_IMG_YES);
        return MMI_TRUE;
    }
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_IS_RESIZED_IMG_NO);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_to_mms_expiry_time
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  uc_expiry_time      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_uc_convert_to_mms_expiry_time(srv_uc_expiry_time_enum uc_expiry_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (uc_expiry_time)
    {
        case SRV_UC_EXPIRY_NOT_SET:
        {
            return MMA_EXPIRY_NOT_SET;
        }
            

        case SRV_UC_EXPIRY_1_HOUR:
        {
            return MMA_EXPIRY_1_HOUR;
        }
            

        case SRV_UC_EXPIRY_6_HOURS:
        {
            return MMA_EXPIRY_6_HOURS;
        }
            

        case SRV_UC_EXPIRY_12_HOURS:
        {
            return MMA_EXPIRY_12_HOURS;
        }
            

        case SRV_UC_EXPIRY_1_DAY:
        {
            return MMA_EXPIRY_1_DAY;
        }
            

        case SRV_UC_EXPIRY_1_WEEK:
        {
            return MMA_EXPIRY_1_WEEK;
        }
            

        case SRV_UC_EXPIRY_MAX:
        {
            return MMA_EXPIRY_MAX;
        }
            

        default:
        {
            MMI_ASSERT(0);
        }
            
    }
    return MMA_EXPIRY_NOT_SET;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_mms_expiry_time_to_uc
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  mms_expiry_time     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_uc_expiry_time_enum srv_uc_convert_mms_expiry_time_to_uc(U32 mms_expiry_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mms_expiry_time)
    {
        case MMA_EXPIRY_1_HOUR:
        {
            return SRV_UC_EXPIRY_1_HOUR;
        }
           

        case MMA_EXPIRY_6_HOURS:
        {
            return SRV_UC_EXPIRY_6_HOURS;
        }
            

        case MMA_EXPIRY_12_HOURS:
        {
            return SRV_UC_EXPIRY_12_HOURS;
        }
            

        case MMA_EXPIRY_1_DAY:
        {
            return SRV_UC_EXPIRY_1_DAY;
        }
            

        case MMA_EXPIRY_1_WEEK:
        {
            return SRV_UC_EXPIRY_1_WEEK;
        }
           

        case MMA_EXPIRY_MAX:
        {
            return SRV_UC_EXPIRY_MAX;
        }
            

        default:
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CONVERT_MMS_EXP_TIME_TO_UC_P1, mms_expiry_time);
            return SRV_UC_EXPIRY_NOT_SET;
        }
            
    }

   // return SRV_UC_EXPIRY_NOT_SET;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_to_mms_delivery_time
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  uc_delivery_time        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_uc_convert_to_mms_delivery_time(srv_uc_delivery_time_enum uc_delivery_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (uc_delivery_time)
    {
        case SRV_UC_DELIVERY_NOT_SET:
        {
            return MMA_DELIVERY_NOT_SET;
        }
            

        case SRV_UC_DELIVERY_IMMEDIATE:
        {
            return MMA_DELIVERY_IMMEDIATE;
        }
            

        case SRV_UC_DELIVERY_1_HOUR:
        {
            return MMA_DELIVERY_1_HOUR;
        }
            

        case SRV_UC_DELIVERY_12_HOURS:
        {
            return MMA_DELIVERY_12_HOURS;
        }
            

        case SRV_UC_DELIVERY_24_HOURS:
        {
            return MMA_DELIVERY_24_HOURS;
        }
            

        default:
        {
            MMI_ASSERT(0);
        }
            
    }

    return MMA_DELIVERY_NOT_SET;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_mms_delivery_time_to_uc
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  mms_delivery_time       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_uc_delivery_time_enum srv_uc_convert_mms_delivery_time_to_uc(U32 mms_delivery_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mms_delivery_time)
    {
        case MMA_DELIVERY_IMMEDIATE:
        {
            return SRV_UC_DELIVERY_IMMEDIATE;
        }
            

        case MMA_DELIVERY_1_HOUR:
        {
            return SRV_UC_DELIVERY_1_HOUR;
        }
            

        case MMA_DELIVERY_12_HOURS:
        {
            return SRV_UC_DELIVERY_12_HOURS;
        }
            

        case MMA_DELIVERY_24_HOURS:
        {
            return SRV_UC_DELIVERY_24_HOURS;
        }
            

        default:
        {
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_CONVERT_MMS_DELIVERY_TIME_TO_UC_P1, mms_delivery_time);
            return SRV_UC_DELIVERY_NOT_SET;
        }
            
    }

   //return SRV_UC_DELIVERY_NOT_SET;
}
/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_mma_group_to_mms
 * DESCRIPTION
 *  void
 * PARAMETERS
 *  mms_delivery_time       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mma_mms_address_group_type_enum srv_uc_convert_mma_group_to_mms(U8 mma_grp_type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mma_address_group_type_enum addr_grp = (mma_address_group_type_enum)mma_grp_type ;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(addr_grp)
	{
		case MMA_ADDRESS_GROUP_TYPE_TO:
			return MMA_MMS_ADDRESS_GROUP_TYPE_TO;
		case MMA_ADDRESS_GROUP_TYPE_CC:
			return MMA_MMS_ADDRESS_GROUP_TYPE_CC;
		case MMA_ADDRESS_GROUP_TYPE_BCC:
			return MMA_MMS_ADDRESS_GROUP_TYPE_BCC;
		case MMA_ADDRESS_GROUP_TYPE_FROM:
			return MMA_MMS_ADDRESS_GROUP_TYPE_FROM;
		default:
			return MMA_MMS_ADDRESS_GROUP_TYPE_TOTAL_NUM;
		
	}
}

srv_uc_address_group_type_enum srv_uc_convert_mma_addr_group_to_uc_addr_group(mma_address_group_type_enum mma_grp)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(mma_grp)
	{
		case MMA_ADDRESS_GROUP_TYPE_TO:
			return SRV_UC_ADDRESS_GROUP_TYPE_TO;
		case MMA_ADDRESS_GROUP_TYPE_CC:
			return SRV_UC_ADDRESS_GROUP_TYPE_CC;
		case MMA_ADDRESS_GROUP_TYPE_BCC:
			return SRV_UC_ADDRESS_GROUP_TYPE_BCC;
		case MMA_ADDRESS_GROUP_TYPE_FROM:
			return SRV_UC_ADDRESS_GROUP_TYPE_FROM;
		default:
			return SRV_UC_ADDRESS_GROUP_TYPE_TOTAL_NUM;
		
	}
}

mma_address_group_type_enum srv_uc_convert_uc_addr_group_to_mma_addr_group(srv_uc_address_group_type_enum uc_grp)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(uc_grp)
	{
		case SRV_UC_ADDRESS_GROUP_TYPE_TO:
			return MMA_ADDRESS_GROUP_TYPE_TO;
		case SRV_UC_ADDRESS_GROUP_TYPE_CC:
			return MMA_ADDRESS_GROUP_TYPE_CC;
		case SRV_UC_ADDRESS_GROUP_TYPE_BCC:
			return MMA_ADDRESS_GROUP_TYPE_BCC;
		case SRV_UC_ADDRESS_GROUP_TYPE_FROM:
			return MMA_ADDRESS_GROUP_TYPE_FROM;
		default:
			return MMA_ADDRESS_GROUP_TYPE_TOTAL_NUM;
		
	}
}



srv_uc_address_type_enum srv_uc_convert_mma_addr_type_to_uc_addr_type(mma_addr_type_enum type)
{
	srv_uc_address_type_enum addr_type ;
		switch(type)
		{
		case MMA_ADDR_TYPE_PHONE_NUMBER: 
			 addr_type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
			 break;
		case MMA_ADDR_TYPE_EMAIL:
			 addr_type = SRV_UC_ADDRESS_TYPE_EMAIL;
			 break;
		case MMA_ADDR_TYPE_IPV4:
			 addr_type = SRV_UC_ADDRESS_TYPE_IP;
			 break;
		case MMA_ADDR_TYPE_NONE :
			 addr_type = SRV_UC_ADDRESS_TYPE_TOTAL_NUM;
			 break;
		default :
			 addr_type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
			 break;
		}
	 return  addr_type;

}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_is_mms_in_use
 * DESCRIPTION
 *  Check if the msg_id is in used (highlight on it, this will aslo can cover UC,
 *  because before enter UC, need to select one msg)
 *  Why UC need provide this only for Q05A, it's because different mms slution has
 *  different architecture.
 * PARAMETERS
 *  instance        [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool srv_uc_is_mms_in_use(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 instance = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(instance < SRV_MAX_UC_INSTANCES)
    {
        if (g_srv_uc_p[instance] && g_srv_uc_p[instance]->send_info.existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
        {
            if (g_srv_uc_p[instance]->send_info.existed_msg_id == msg_id)
            {
                return KAL_TRUE;
            }
        }
		instance++;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_is_no_recepient
 * DESCRIPTION
 *  return T if there is no recepient
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_is_no_recepient(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_POSTCARD__
    if (g_srv_uc_p[instance]->msg_type.MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    {
        if (srv_postcard_get_total_recipient_count(instance) == 0)
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
#endif /* __MMI_MMS_POSTCARD__ */ 

    if (g_srv_uc_p[instance]->msg.to_num > 0)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}

#ifdef __MMI_UC_MMS_IMG_RESOLUTION__


/*****************************************************************************
 * FUNCTION
 *  srv_uc_img_resolution_exceed_limitation
 * DESCRIPTION
 *  check if the file's resolution exceed the mms class limitataion
 * PARAMETERS
 *  file_path       [?]     
 *  MMI_BOOL(?)
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_img_resolution_exceed_limitation(U16 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT gdi_ret = GDI_FAILED;
    S32 width = 0, height = 0;
    kal_int32 max_width = 0, max_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check image resolution */
    gdi_ret = gdi_image_get_dimension_file((PS8) file_path, (S32*) & width, (S32*) & height);
    mms_get_max_image_resolution_in_restricted_mode(&max_width, &max_height);

    if (gdi_ret < 0 || width <= 0 || height <= 0)
    {
        return MMI_FALSE;   /* can not detemine if the img file exceeds limitation */
    }
    else if ((width > max_width) || (height > max_height))
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}

#endif /* __MMI_UC_MMS_IMG_RESOLUTION__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_uc_is_in_ref_obj_type_range
 * DESCRIPTION
 *  Check if the type of selected file is in ref oject range
 *  void
 * RETURNS
 *  MMI_BOOL. MMI_TRUE means that the selected file path's type belong
 *  to ref object.
 *****************************************************************************/
MMI_BOOL srv_uc_is_in_ref_obj_type_range(S8 *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmgr_filetype_enum file_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    file_type = srv_fmgr_types_find_type_by_filename_str((WCHAR*) filepath);

    if ((FMGR_TYPE_JAD == file_type) || (FMGR_TYPE_JAR == file_type))
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_IS_IN_REF_OBJ_TYPE_RANGE_P1, 1);
        return MMI_TRUE;
    }
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_IS_IN_REF_OBJ_TYPE_RANGE_P1, 0);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_mms_type
 * DESCRIPTION
 *  mms's content type is mixed or smil
 * RETURNS
 *  mixed or smil
 *****************************************************************************/
mma_mms_type_enum srv_uc_get_mms_type(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_POSTCARD__
    if (g_srv_uc_p[instance]->msg_type.MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    {
        return MMA_MMS_TYPE_MIXED_MMS;
    }
#endif /* __MMI_MMS_POSTCARD__ */ 
#ifdef __MMI_EMAIL__
    if (g_srv_uc_p[instance]->msg_type.MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
    {
        return MMA_MMS_TYPE_MIXED_MMS;
    }
#endif /* __MMI_EMAIL__ */ 
    return MMA_MMS_TYPE_SMIL_MMS;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_reserved_size
 * DESCRIPTION
 *  get reserved size, if it's a postcard mms, should reserve recipients info
 *  if editing mms is not postcard, will return 0
 * RETURNS
 *  the msg size which need to be reserved in advance
 *  if editing mms is not postcard, will return 0
 *****************************************************************************/
U32 srv_uc_reserved_size(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 reserved_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_POSTCARD__
    U8 srv_uc_text_path[SRV_UC_MAX_TEMP_FILE_LEN];

    if (g_srv_uc_p[instance]->msg_type.MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_POSTCARD_MMS)
    {
        return 0;
    }
    else
    {
        memset(srv_uc_text_path, 0, sizeof(srv_uc_text_path));
        SRV_UC_MAKE_TEXT_FILE_PATH(srv_uc_text_path, 1, instance);    /* 1: current slide number, only one slide for postcard */
        /* reserve recipient's info -- worst case */
        /* value 3 -- UTF8 occupies 1~3 bytes for one character, use worst case */
        reserved_size = mma_uc_calc_object_multipart_size((U16*) srv_uc_text_path) +
            mma_uc_calc_text_uintvar_overhead_size(SRV_POSTCARD_SAVE_MAX_CONTENT * 3) +
            (SRV_POSTCARD_SAVE_MAX_CONTENT - SRV_POSTCARD_MAX_GREETING) * 3;
        /* we don't care about subtracting obj header multiplely */
    }
#endif /* __MMI_MMS_POSTCARD__ */ 

    return reserved_size;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_sim_id
 * DESCRIPTION
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_uc_sim_id srv_uc_convert_sim_id(srv_uc_sim_id sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (sim_id == SRV_UC_SIM_ID_GSM_SIM1 || sim_id == SRV_UC_SIM_ID_GSM_SIM2 ||sim_id == SRV_UC_SIM_ID_GSM_SIM3 ||sim_id == SRV_UC_SIM_ID_GSM_SIM4)
    {
        return sim_id;
    }
    else
    {
        return SRV_UC_SIM_ID_GSM_SIM1;
    }
}



#ifdef WAP_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_uc_sim_id_to_wap_prof
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_uc_convert_uc_sim_id_to_wap_prof(srv_uc_sim_id sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 wap_prof_sim_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {
        case SRV_UC_SIM_ID_GSM_SIM1:
        {
            wap_prof_sim_id = SRV_WAP_PROF_SIMID_SIM1;
        }
            break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case SRV_UC_SIM_ID_GSM_SIM2:
        {
            wap_prof_sim_id = SRV_WAP_PROF_SIMID_SIM2;
        }
            break;
    #if (MMI_MAX_SIM_NUM >=3)
        case SRV_UC_SIM_ID_GSM_SIM3:
        {
            wap_prof_sim_id = SRV_WAP_PROF_SIMID_SIM3;
        }
            break;
    #if (MMI_MAX_SIM_NUM ==4)
			case SRV_UC_SIM_ID_GSM_SIM4:
        {
            wap_prof_sim_id = SRV_WAP_PROF_SIMID_SIM4;
        }
            break;
#endif
#endif
#endif        
        default:
        {
            ASSERT(0);
        }
    }
    return wap_prof_sim_id;
}
#endif /* (defined(WAP_SUPPORT) && defined (WAP_SUPPORT)) */

/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_ucsim_to_mmisim
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_uc_sim_id        
 * BOOL
 * RETURNS
 *  mmi_sim_enum
 *****************************************************************************/
mmi_sim_enum srv_uc_convert_ucsim_to_mmisim(srv_uc_sim_id sim)
{
  switch(sim)
  {
  case SRV_UC_SIM_ID_GSM_SIM1:
	return MMI_SIM1;
 #if (MMI_MAX_SIM_NUM >= 2)
  case SRV_UC_SIM_ID_GSM_SIM2:
	return MMI_SIM2;
 #if (MMI_MAX_SIM_NUM >= 3)
  case SRV_UC_SIM_ID_GSM_SIM3:
	return MMI_SIM3;
 #if (MMI_MAX_SIM_NUM >= 4)
  case SRV_UC_SIM_ID_GSM_SIM4:
	return MMI_SIM4;
#endif
#endif
#endif
   default:
	return MMI_SIM_NONE;
  }
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_set_valid_sim
 * DESCRIPTION
 *  Set the valid SIM available for saving SMS during end key
 * PARAMETERS
 *  instance        [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_set_valid_sim(U32 instance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #if (MMI_MAX_SIM_NUM ==2)
    if (!(g_srv_uc_p[instance]->sim_info.valid_sim_id_info & SRV_UC_SIM_ID_GSM_SIM1))
    {
        if (g_srv_uc_p[instance]->sim_info.valid_sim_id_info & SRV_UC_SIM_ID_GSM_SIM2)
        {
            g_srv_uc_p[instance]->send_info.send_sim_id = SRV_UC_SIM_ID_GSM_SIM2;
        }
        else
        {
            g_srv_uc_p[instance]->send_info.send_sim_id = SRV_UC_SIM_ID_UNCLASSIFIED;
        }
    }
    else if (!(g_srv_uc_p[instance]->sim_info.valid_sim_id_info & SRV_UC_SIM_ID_GSM_SIM2))
    {
        if (g_srv_uc_p[instance]->sim_info.valid_sim_id_info & SRV_UC_SIM_ID_GSM_SIM1)
        {
            g_srv_uc_p[instance]->send_info.send_sim_id = SRV_UC_SIM_ID_GSM_SIM1;
        }
        else
        {
            g_srv_uc_p[instance]->send_info.send_sim_id = SRV_UC_SIM_ID_UNCLASSIFIED;
        }
    }
    return MMI_TRUE;
#else
    return MMI_FALSE;
#endif /* MMI_MAX_SIM_NUM */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_is_sms_in_use
 * DESCRIPTION
 *  Check if the msg_id is in used (Other application need to check for this before use a msg.
 *  Because same message can not be used by two applications simultaneously)
 *  msg_id : [IN] Msg id.
 * RETURNS
 *  KAL_FALSE  : Not in use.
 *  KAL_TRUE  : In use.
 *****************************************************************************/
kal_bool srv_uc_is_sms_in_use(U32 instance, kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_uc_p[instance]->send_info.existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
    {
        if (g_srv_uc_p[instance]->send_info.existed_msg_id == msg_id)
        {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;
}

#ifdef __MMI_MMS_BGSR_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_mma_folder_to_bgsr_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folderID        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_uc_convert_mma_folder_to_bgsr_folder(S32 folderID)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_bgsr_msg_box_enum ret = SRV_MMS_BGSR_FOLDER_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (folderID)
    {
        case MMA_FOLDER_INBOX:
            ret = SRV_MMS_BGSR_FOLDER_INBOX;
        case MMA_FOLDER_OUTBOX:
            ret = SRV_MMS_BGSR_FOLDER_OUTBOX;
        case MMA_FOLDER_ARCHIVE:
            ret = SRV_MMS_BGSR_FOLDER_ARCHIVE;
        default:
            ret = SRV_MMS_BGSR_FOLDER_NONE;
    }
    return (S32) ret;
}
#endif /* __MMI_MMS_BGSR_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_uc_convert_mma_folder_to_um_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folder_id       [IN]        
 *  folderID(?)     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_um_msg_box_enum srv_uc_convert_mma_folder_to_um_folder(mma_folder_enum folder_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (folder_id)
    {
        case MMA_FOLDER_INBOX:
            return SRV_UM_MSG_BOX_INBOX;

        case MMA_FOLDER_OUTBOX:
            return SRV_UM_MSG_BOX_UNSENT;

        case MMA_FOLDER_SENT:
            return SRV_UM_MSG_BOX_SENT;

        case MMA_FOLDER_TEMPLATE:
            return SRV_UM_MSG_BOX_PREDEF_TEMPLATES;

        case MMA_FOLDER_USRDEF_TEMPLATE:
            return SRV_UM_MSG_BOX_USRDEF_TEMPLATES;

    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        case MMA_FOLDER_ARCHIVE:
            return SRV_UM_MSG_BOX_ARCHIVE;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 

        case MMA_FOLDER_DRAFT:
        default:
            return SRV_UM_MSG_BOX_DRAFT;
    }
    //return SRV_UM_MSG_BOX_DRAFT;   
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_update_filepath_with_string
 * DESCRIPTION
 *  update the name for inserted file
 * PARAMETERS
 *  instance            [IN]        
 *  srv_uc_new_path     [IN]        
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_uc_update_filepath_with_string(U32 instance, S8 *srv_uc_new_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 flie_path_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* use self parameter to save file name info */
    if (g_srv_uc_p[instance]->main.file_path)
    {
        g_srv_uc_p[instance]->free(g_srv_uc_p[instance]->main.file_path, g_srv_uc_p[instance]->user_data);
        g_srv_uc_p[instance]->main.file_path = NULL;
    }
    flie_path_len = mmi_ucs2strlen((S8*) srv_uc_new_path);

    g_srv_uc_p[instance]->main.file_path = g_srv_uc_p[instance]->alloc((flie_path_len + 1) * ENCODING_LENGTH, g_srv_uc_p[instance]->user_data);

    MMI_ASSERT(g_srv_uc_p[instance]->main.file_path);
    mmi_ucs2ncpy((S8*) g_srv_uc_p[instance]->main.file_path, (S8*) srv_uc_new_path, flie_path_len);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_handle_extra_information_from_mma
 * DESCRIPTION
 *  Handle extra information passed by MMA to UC
 * PARAMETERS
 *  instance        [IN]        
 *  flag            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_uc_handle_extra_information_from_mma(U32 instance, S32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & MMA_TRUNCATED_ATTACHMENT)
    {
        g_srv_uc_p[instance]->send_info.content_truncated_type |= SRV_UC_TRUNCATED_TYPE_ATTACHMENT;
    }
    if (flag & MMA_TRUNCATED_SLIDE)
    {
        g_srv_uc_p[instance]->send_info.content_truncated_type |= SRV_UC_TRUNCATED_TYPE_SLIDE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_highlighted_index
 * DESCRIPTION
 *  get current highlighted address index
 * PARAMETERS
 *  instance        [IN]        
 *  addr            [?]         
 * RETURNS
 *  current highlighted address index
 *****************************************************************************/
U16 srv_uc_get_highlighted_index(U32 instance, srv_uc_addr_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;
    srv_uc_addr_struct *check_addr = g_srv_uc_p[instance]->msg.to_head;
    U16 addr1[SRV_UC_MAX_PHONE_NUMBER_LEN + 1] = {0,};
    U16 addr2[SRV_UC_MAX_PHONE_NUMBER_LEN + 1] = {0,};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (check_addr != NULL)
    {
        if (check_addr->type == addr->type)
        {
            if (addr->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
            {
                mmi_asc_to_ucs2((PS8) addr1, (PS8) check_addr->addr);
                mmi_asc_to_ucs2((PS8) addr2, (PS8) addr->addr);
                if (srv_phb_compare_number(addr1, addr2) == MMI_TRUE)
                {
                    return index;
                }
            }
            else if (addr->type == SRV_UC_ADDRESS_TYPE_EMAIL)
            {
                if (srv_uc_compare_string_ignore_case((U16*) check_addr->addr, (U16*) addr->addr) == MMI_TRUE)
                {
                    return index;
                }
            }
        }
        index++;
        check_addr = check_addr->next;
    }
    return (U16) 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_copy_address
 * DESCRIPTION
 *  Make a copy of address node
 * PARAMETERS
 *  instance        [IN]        
 *  addr            [?]         
 * RETURNS
 *  void
 *****************************************************************************/
srv_uc_addr_struct *srv_uc_copy_address(U32 instance, srv_uc_addr_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uc_addr_struct *addr_new = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    addr_new = g_srv_uc_p[instance]->alloc(sizeof(srv_uc_addr_struct), g_srv_uc_p[instance]->user_data);
    MMI_ASSERT(addr_new);

    if (addr->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
    {
        U16 len = strlen((char*)addr->addr);

        addr_new->addr = g_srv_uc_p[instance]->alloc(len + 1, g_srv_uc_p[instance]->user_data);
        MMI_ASSERT(addr_new->addr);
        memset(addr_new->addr, 0, len + 1);
        memcpy(addr_new->addr, addr->addr, len);
    }
    else if (addr->type == SRV_UC_ADDRESS_TYPE_EMAIL)
    {
        U16 len = mmi_ucs2strlen((S8*) addr->addr);

        addr_new->addr = g_srv_uc_p[instance]->alloc(((len + 1) * ENCODING_LENGTH), g_srv_uc_p[instance]->user_data);
        MMI_ASSERT(addr_new->addr);
        memset(addr_new->addr, 0, ((len + 1) * ENCODING_LENGTH));
        memcpy(addr_new->addr, addr->addr, (len * ENCODING_LENGTH));
    }
    else
    {
        MMI_ASSERT(0);
    }
    addr_new->type = addr->type;
    addr_new->group = addr->group;
    addr_new->next = addr->next;
    addr_new->previous = addr->previous;
    return addr_new;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_send_um_msg_refresh_ind
 * DESCRIPTION
 *  Send msg refresh indication to UM.
 * PARAMETERS
 *  instance        [IN]        
 *  msg_box         [IN]        
 *  msg_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uc_send_um_msg_refresh_ind(U32 instance, U8 msg_box, U16 msg_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_refresh_ind_struct *um_refresh_ind = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    um_refresh_ind =
        (srv_um_refresh_ind_struct*) construct_local_para(
                                        (kal_uint16) sizeof(srv_um_refresh_ind_struct),
                                        TD_CTRL | TD_RESET);
    um_refresh_ind->msg_type = (srv_um_msg_enum)msg_type;
    um_refresh_ind->msg_box_type = (srv_um_msg_box_enum)msg_box;
    srv_uc_send_message_ext_queue(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_UM_REFRESH_IND, (oslParaType*) um_refresh_ind, NULL);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uc_send_message_ext_queue
 * DESCRIPTION
 *  Common function for sending message
 * PARAMETERS
 *  MOD_SRC         [IN]        Source module
 *  MOD_DEST        [IN]        Destination module
 *  MSG_SAP         [IN]        Message SAP
 *  MSG_ID          [IN]        Message ID
 *  LOCAL           [IN]        Local parameter
 *  PEER            [IN]        Peer buffer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_uc_send_message_ext_queue(
        module_type MOD_SRC,
        module_type MOD_DEST,
        U8 MSG_SAP,
        const U16 MSG_ID,
        void *LOCAL,
        void *PEER)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_SRC;
    Message.oslDestId = MOD_DEST;
    Message.oslSapId = (sap_type)MSG_SAP;
    Message.oslMsgId = (msg_type)MSG_ID;
    Message.oslDataPtr = LOCAL;
    Message.oslPeerBuffPtr = PEER;
    OslMsgSendExtQueue(&Message);
}

void srv_uc_copy_filename_filepath(U32 instance)
{
	mma_mms_object_struct *obj = g_srv_uc_p[instance]->msg.msg_body.objects;
	while(obj != NULL)
	{
		if(obj->file_name_ucs)
		{
			U16 slen = 0 ;
			if(obj->file_name)
			{
				g_srv_uc_p[instance]->free(obj->file_name, g_srv_uc_p[instance]->user_data);
				obj->file_name = NULL ;
			}
			slen = (mmi_ucs2strlen((S8 *)obj->file_name_ucs)*3)+1;
			obj->file_name = (S8 *)g_srv_uc_p[instance]->alloc(slen, g_srv_uc_p[instance]->user_data);
			memset(obj->file_name, 0, slen);
			mmi_chset_ucs2_to_utf8_string((kal_uint8 *)obj->file_name, slen , (kal_uint8 *)obj->file_name_ucs);
			srv_mms_convert_file_name_to_ascii(obj, g_srv_uc_p[instance]->alloc,  g_srv_uc_p[instance]->free, g_srv_uc_p[instance]->user_data);
		}
		if(obj->file_path_ucs)
		{
			U16 slen = 0 ;
			if(obj->file_path)
			{
				g_srv_uc_p[instance]->free(obj->file_path, g_srv_uc_p[instance]->user_data);
				obj->file_path = NULL ;
			}
			slen = (mmi_ucs2strlen((S8 *)obj->file_path_ucs)*3)+1;
			obj->file_path = (S8 *)g_srv_uc_p[instance]->alloc(slen, g_srv_uc_p[instance]->user_data);
			memset(obj->file_path, 0, slen);
			mmi_chset_ucs2_to_utf8_string((kal_uint8 *)obj->file_path, slen , (kal_uint8 *)obj->file_path_ucs);
		}
		obj = obj->next;
	}
}


#ifdef __XML_REMOVAL__
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_address
 * DESCRIPTION
 *  takes input from app and set the UC context
 * PARAMETERS
 *  instance        [IN]        
 *  mma_mms_addr_list_struct [IN]
 *	srv_uc_address_group_type_enum [IN]
 *	mma_mms_addr_list_struct [IN]
 *	
 * RETURNS
 * mma_mms_addr_list_struct
 *****************************************************************************/
mma_mms_read_reply_enum srv_uc_convert_mms_rr_to_mma_rr(BOOL read_report)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  switch(read_report)
  {
	  case 0:
		  return MMA_MMS_READ_REPLY_NO ;
	  case 1:
		  return MMA_MMS_READ_REPLY_YES ;
	  default:
		  return MMA_MMS_READ_REPLY_NOT_SET ;
  }
}
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_address
 * DESCRIPTION
 *  takes input from app and set the UC context
 * PARAMETERS
 *  instance        [IN]        
 *  mma_mms_addr_list_struct [IN]
 *	srv_uc_address_group_type_enum [IN]
 *	mma_mms_addr_list_struct [IN]
 *	
 * RETURNS
 * mma_mms_addr_list_struct
 *****************************************************************************/
mma_mms_delivery_report_enum srv_uc_convert_mms_dr_to_mma_dr(BOOL delivery_report)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(delivery_report)
	{
	  case 0:
	    return MMA_MMS_DELIVERY_REPORT_NO ;
      case 1:
	    return MMA_MMS_DELIVERY_REPORT_YES ;
      default:
	    return MMA_MMS_DELIVERY_REPORT_NOT_SET ;
	}
}
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_address
 * DESCRIPTION
 *  takes input from app and set the UC context
 * PARAMETERS
 *  instance        [IN]        
 *  mma_mms_addr_list_struct [IN]
 *	srv_uc_address_group_type_enum [IN]
 *	mma_mms_addr_list_struct [IN]
 *	
 * RETURNS
 * mma_mms_addr_list_struct
 *****************************************************************************/
mma_mms_sender_visibility_enum srv_uc_convert_mms_vis_to_mma_vis(BOOL visibility)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   switch(visibility)
	{
		case 0:
			return MMA_MMS_SENDER_SHOW ;
		case 1:
			return MMA_MMS_SENDER_HIDE ;
		default:
			return MMA_MMS_SENDER_VISIBILITY_NOT_SET ;
	}
}
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_address
 * DESCRIPTION
 *  takes input from app and set the UC context
 * PARAMETERS
 *  instance        [IN]        
 *  mma_mms_addr_list_struct [IN]
 *	srv_uc_address_group_type_enum [IN]
 *	mma_mms_addr_list_struct [IN]
 *	
 * RETURNS
 * mma_mms_addr_list_struct
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
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_address
 * DESCRIPTION
 *  takes input from app and set the UC context
 * PARAMETERS
 *  instance        [IN]        
 *  mma_mms_addr_list_struct [IN]
 *	srv_uc_address_group_type_enum [IN]
 *	mma_mms_addr_list_struct [IN]
 *	
 * RETURNS
 * mma_mms_addr_list_struct
 *****************************************************************************/
mma_addr_type_enum srv_uc_convert_uc_addrtype_to_mma(srv_uc_address_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	mma_addr_type_enum addr_type ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(type)
	{
	case SRV_UC_ADDRESS_TYPE_PHONE_NUMBER: 
		 addr_type = MMA_ADDR_TYPE_PHONE_NUMBER;
		 break;
	case SRV_UC_ADDRESS_TYPE_EMAIL:
         addr_type = MMA_ADDR_TYPE_EMAIL;
         break;
	case SRV_UC_ADDRESS_TYPE_IP :
		 addr_type = MMA_ADDR_TYPE_IPV4;
		 break;
	case SRV_UC_ADDRESS_TYPE_TOTAL_NUM:
		 addr_type = MMA_ADDR_TYPE_NONE;
		 break;
	default :
		 addr_type = MMA_ADDR_TYPE_PHONE_NUMBER;
		 break;
	}
 return  addr_type;
}
/*****************************************************************************
 * FUNCTION
 *  srv_uc_get_address
 * DESCRIPTION
 *  takes input from app and set the UC context
 * PARAMETERS
 *  instance        [IN]        
 *  mma_mms_addr_list_struct [IN]
 *	srv_uc_address_group_type_enum [IN]
 *	mma_mms_addr_list_struct [IN]
 *	
 * RETURNS
 * mma_mms_addr_list_struct
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
/*****************************************************************************
 * FUNCTION
 *  srv_uc_address_data_hdlr
 * DESCRIPTION
 *  takes input from app and set the UC context
 * PARAMETERS
 *  instance        [IN]        
 *  mma_mms_addr_list_struct [IN]
 *	srv_uc_address_group_type_enum [IN]
 *	mma_mms_addr_list_struct [IN]
 *	
 * RETURNS
 * void
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /*__XML_REMOVAL__*/
#endif /* (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */ 
#endif /* _UNIFIED_COMPOSER_MISC_SRV_C */ /* _MMI_UNIFIED_COMPOSER_MAIN_C */
