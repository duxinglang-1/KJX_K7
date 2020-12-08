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
 * MmsExtSrv.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

// #include "MMI_include.h"
#include "MMI_features.h"
#ifdef __MMI_MMS_2__

#include "MMIDataType.h"
#include "string.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

#include "UcSrvGprot.h"
#include "MmsSrvExt.h"
#include "MmsSrvGProt.h"
#include "MmsSrvProt.h"
#include "MMSMemoryManagerSrv.h"
#ifdef __MMI_MMS_URI_AGENT__
#include "UriAgentSrvGprot.h"
#include "app_str.h"
#include "ctype.h"      /* isdigit */
// #include "stdlib.h"     /* atoi */
#endif /* __MMI_MMS_URI_AGENT__ */ 
#include "ProfilesSrvGprot.h"
#include "app_asyncfile.h"
#include "UcSrvGprot.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_history_gprot.h"
#include "customer_email_num.h"
#include "Unicodexdcl.h"
#include "app_usedetails.h"
#include "mms_sap_struct.h"
#include "mma_api.h"
#include "mma_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_ltlcom.h" 

#include "kal_public_defs.h" 
#include "mms_adp.h"

#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
srv_mms_vendor_struct umms_vendor_context;
srv_mms_vendor_struct *g_umms_vendor_context = &umms_vendor_context;
#endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 

#ifdef __MMI_MMS_URI_AGENT__
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
static srv_mms_current_uri_info_struct current_uri_info;
static srv_mms_current_uri_info_struct *g_current_uri_info_list = &current_uri_info;
static srv_mms_entry_write_struct s_uc_data;
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ 
#endif /* __MMI_MMS_URI_AGENT__ */ 

extern void srv_prof_stop_tone(srv_prof_tone_enum tone_type);
extern BOOL g_is_wap_ready;

extern void srv_mms_bgsr_vendor_send_msg_req (U32 msg_id, U8 sim_id);
extern U8 srv_mms_bgsr_cancel_send_req(U32 msg_id);

#ifdef __MMI_MMS_URI_AGENT__
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))

static MMI_BOOL srv_mms_uri_parser(char *text, srv_mms_entry_write_struct *uc_data, U32 *total_to_field);


/*****************************************************************************
 * FUNCTION
 *  srv_mms_uri_insert_hdlr
 * DESCRIPTION
 *  Start MMS in editor with a URI scheme
 * CALLS
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  url             [?]         [?]         [?]         [?]
 *  param           [?]         [?]         [?]         [?]
 *  options         [IN]        
 *  cb              [IN]        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_uri_insert_hdlr(
        srv_uriagent_appid_enum ura_appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_set_uri_parameters(ura_appid, param, cb);
    if (options == SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP)
    {
        srv_mms_send_events(EVT_ID_SRV_URI_CONFIRM_POPUP, NULL);
        /* Display Popup for Confirmation */
    }
    else
    {
        srv_mms_uri_insert_hdlr_ext(ura_appid, param, cb);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_uri_insert_hdlr_ext
 * DESCRIPTION
 *  Start MMS in editor with a param
 * CALLS
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  param           [?]         [?]         [?]         [?]
 *  cb              [IN]        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_uri_insert_hdlr_ext(kal_uint32 ura_appid, char *param, srv_uriagent_uri_request_hdlr_cb cb)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
    {

        U32 total_num = 0;
        MMI_BOOL is_invalid;

        memset(&s_uc_data, 0x00, sizeof(srv_mms_entry_write_struct));

        is_invalid = srv_mms_uri_parser(param, &s_uc_data, &total_num);
        if ((is_invalid == MMI_TRUE) && (s_uc_data.addr_num == 0))
        {
            if (g_current_uri_info_list->cb != NULL)
            {
                g_current_uri_info_list->cb(g_current_uri_info_list->ura_appid, SRV_URIAGENT_APPID_MMS, MMI_FALSE);
                g_current_uri_info_list->cb = NULL;
            }
            srv_mms_de_init_uri();
            srv_mms_send_events(EVT_ID_SRV_INVALID_POPUP, NULL);
            /* Call Here the Call Back Function with result as False; */
            return;
        }
        if ((is_invalid == MMI_FALSE) && (s_uc_data.addr_num == 0))
        {
            if (g_current_uri_info_list->cb != NULL)
            {
                g_current_uri_info_list->cb(g_current_uri_info_list->ura_appid, SRV_URIAGENT_APPID_MMS, MMI_FALSE);
                g_current_uri_info_list->cb = NULL;
            }
            srv_mms_de_init_uri();
            srv_mms_send_events(EVT_ID_SRV_INVALID_POPUP, NULL);
            /* Call Here the Call Back Function with result as False; */
            return;
        }
        /* uc_data.msg_type = MMI_UC_MSG_TYPE_MMS_ONLY;
           uc_data.info_type = MMI_UC_INFO_TYPE_MMS; */
        if (g_current_uri_info_list->cb != NULL)
        {
            g_current_uri_info_list->cb(g_current_uri_info_list->ura_appid, SRV_URIAGENT_APPID_MMS, MMI_TRUE);
            g_current_uri_info_list->cb = NULL;
        }
        srv_mms_send_events(EVT_ID_SRV_URI_CONFIRM_POPUP, &s_uc_data);
        /* mmi_uc_entry_write_msg_with_content(MMI_UC_STATE_WRITE_NEW_MSG, &uc_data); */

    }
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ 

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_uri_addr_enqueue
 * DESCRIPTION
 *  Start MMS in editor with a mms_content_entry_struct is filled
 * CALLS
 *  
 * PARAMETERS
 *  addr_data       [?]         [?]         [?]         [?]
 *  addr_queue      [IN]        
 *  data(?)         [IN]        The mms_content_entry_struct data(?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_uri_addr_enqueue(srv_uc_addr_struct *addr_data, srv_uc_addr_struct **addr_queue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    srv_uc_addr_struct *insert = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    if (addr_data == NULL)
    {
        return;
    }

    if (*addr_queue == NULL)
    {
        *addr_queue = addr_data;
        return;
    }

    insert = *addr_queue;
    while (insert->next != NULL)
    {
        insert = insert->next;
    }
    if (insert->next != addr_data)
    {
        insert->next = addr_data;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_uri_is_new_header
 * DESCRIPTION
 *  
 * CALLS
 *  
 * PARAMETERS
 *  str             [?]         
 *  cur_header      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_uri_is_new_header(char *str, srv_mms_header_enum cur_header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMS_URI_IS_SEPARATOR(*str))
    {
        if (cur_header == MMS_URI_HEADER_TO || cur_header == MMS_URI_HEADER_CC)
        {
            return KAL_TRUE;
        }
        str++;
    }
    else
    {
        return KAL_FALSE;
    }

    if (*str)
    {
        if (strncmp(str, MMS_URI_TO, 3) == 0 || strncmp(str, MMS_URI_CC, 3) == 0
            || strncmp(str, MMS_URI_BODY, 5) == 0 || strncmp(str, MMS_URI_SUBJECT, 8) == 0)
        {
            return KAL_TRUE;
        }
    }
    return KAL_FALSE;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_uri_parser
 * DESCRIPTION
 *  Start MMS in editor with a mms_content_entry_struct is filled
 * CALLS
 *  
 * PARAMETERS
 *  text                [?]         [?]         [?]         [?]         [?]
 *  uc_data             [IN]        The mms_content_entry_struct data
 *  total_to_field      [?]         [?]         [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mms_uri_parser(char *text, srv_mms_entry_write_struct *uc_data, U32 *total_to_field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 start = 0;
    U32 end = 0;
    U32 subject_length = 0;
    srv_mms_header_enum cur_header = MMS_URI_HEADER_TO;
    char *str = NULL;
    char *tmp_str = NULL;
    char *tmp_str2 = NULL;
    char *body = NULL;
    char *subject = NULL;
    MMI_BOOL is_invalid = MMI_FALSE;
    U8 count = 0;
    U8 count2 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_uc_addr_struct *addr_data;
    srv_uc_addr_struct *node;

    if (text == NULL)
    {
        return MMI_FALSE;
    }

    uc_data->text_buffer = NULL;
    uc_data->subject = NULL;
    if (strstr(text, MMS_URI_BODY) != NULL)
    {
        str = srv_mms_stristr((const kal_char*)text, (const kal_char*)MMS_URI_BODY);
        str += 5;
        tmp_str = str;
        end = 0;
        while (tmp_str != NULL)
        {
            if (srv_mms_uri_is_new_header((tmp_str + end), MMS_URI_HEADER_BODY) || tmp_str[end] == 0)
            {
                g_current_uri_info_list->text_buffer = (kal_uint8*) srv_mms_mem_mgr_app_adm_alloc((end + 1) * 2);
                MMI_ASSERT(g_current_uri_info_list->text_buffer);
                memset(g_current_uri_info_list->text_buffer, 0, (end + 1) * 2);
                uc_data->text_buffer = g_current_uri_info_list->text_buffer;
                mmi_chset_utf8_to_ucs2_string(uc_data->text_buffer, (end + 1) * 2, (U8*) str);
                uc_data->text_num = end;
                body = srv_mms_strdup((const char*)str);
                break;
            }
            end++;
        }
    }
    if (strstr(text, MMS_URI_SUBJECT) != NULL)
    {
        str = srv_mms_stristr((const kal_char*)text, (const kal_char*)MMS_URI_SUBJECT);
        str += 8;
        tmp_str = str;
        end = 0;
        while (tmp_str != NULL)
        {
            if (MMS_URI_IS_SUBJECT_SEPERATOR(tmp_str[end]) || tmp_str[end] == 0)
            {
                g_current_uri_info_list->uc_subject = (kal_uint8*) srv_mms_mem_mgr_app_adm_alloc((end + 1) * 2);
                MMI_ASSERT(g_current_uri_info_list->uc_subject);
                memset(g_current_uri_info_list->uc_subject, 0, (end + 1) * 2);
                uc_data->subject = g_current_uri_info_list->uc_subject;

                subject = (char*)srv_mms_mem_mgr_app_adm_alloc(end + 1);
                memset(subject, 0, end + 1);
                memcpy(subject, str, end);
                subject_length = (U32) mmi_chset_utf8_strlen((kal_uint8*) subject);
                srv_mms_mem_mgr_app_adm_free(subject);
                subject = NULL;
                mmi_chset_utf8_to_ucs2_string(uc_data->subject, (subject_length + 1) * 2, (U8*) str);

                subject_length = end + 1;
                /* uc_data->text_num = end; */
                subject = srv_mms_strdup((const char*)str);
                break;
            }
            end++;
        }
    }
    str = text;
    end = 0;
    while (str != NULL && str[end] != 0)
    {
        if (MMS_URI_IS_SEPARATOR(str[end]))
        {
            if (cur_header == MMS_URI_HEADER_SUBJECT)
            {
                end++;
                continue;
            }
            if (end - start != 0)
            {
                if (MMS_URI_IS_SEPARATOR(str[0]))
                {
                    tmp_str = srv_mms_strndup((const char*)(str + 1), (int)end - start - 1);
                }
                else
                {
                    tmp_str = srv_mms_strndup((const char*)str, (int)end - start);
                }
                if (tmp_str == NULL)
                {
                    str += (end - start) + 1;
                    start = end = 0;
                    end++;
                    srv_mms_mem_mgr_app_adm_free(tmp_str);
                    continue;
                }
                switch (cur_header)
                {
                    case MMS_URI_HEADER_TO:
                    case MMS_URI_HEADER_CC:
                    {
                        uc_data->addr_num++;

                        addr_data = (srv_uc_addr_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_uc_addr_struct));
                        MMI_ASSERT(addr_data);
                        memset(addr_data, 0, sizeof(srv_uc_addr_struct));
                        if (strstr((S8*) tmp_str, "@") == NULL)
                        {
                            addr_data->type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
                        }
                        else
                        {
                            addr_data->type = SRV_UC_ADDRESS_TYPE_EMAIL;
                        }
                        if (cur_header == MMS_URI_HEADER_TO)
                        {
                            addr_data->group = SRV_UC_ADDRESS_GROUP_TYPE_TO;
                        }
                        else
                        {
                            addr_data->group = SRV_UC_ADDRESS_GROUP_TYPE_CC;
                        }

                        /* remove separator '-' from number */
                        if (addr_data->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
                        {
                            count = 0;
                            count2 = 0;

                            tmp_str2 = (char*)srv_mms_mem_mgr_app_adm_alloc(end + 1);
                            MMI_ASSERT(tmp_str2);
                            memset(tmp_str2, 0, end + 1);

                            while (count <= end)
                            {
                                if (tmp_str[count] != '-')
                                {
                                    tmp_str2[count2] = tmp_str[count];
                                    ++count2;
                                }
                                ++count;
                            }
                        }

                        addr_data->addr = (kal_uint8*) srv_mms_mem_mgr_app_adm_alloc((end + 1) * 2);
                        if (addr_data->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
                        {
                            mmi_chset_utf8_to_ucs2_string(addr_data->addr, (end + 1) * 2, (U8*) tmp_str2);
                        }
                        else
                        {
                            mmi_chset_utf8_to_ucs2_string(addr_data->addr, (end + 1) * 2, (U8*) tmp_str);
                        }
                        addr_data->next = NULL;
                        if (tmp_str2 != NULL)
                        {
                            srv_mms_mem_mgr_app_adm_free(tmp_str2);
                            tmp_str2 = NULL;
                        }

                        if (addr_data->type != SRV_UC_ADDRESS_TYPE_EMAIL)
                        {
                            if (srv_mms_check_is_num_or_email_valid
                                (SRV_UC_ADDRESS_TYPE_PHONE_NUMBER, (char*)addr_data->addr))
                            {

                                /* srv_mms_uri_addr_enqueue(addr_data, &(uc_data->addr)); */
                                if (g_current_uri_info_list->addr_buffer == NULL)
                                {
                                    g_current_uri_info_list->addr_buffer = addr_data;
                                }
                                else
                                {
                                    node = g_current_uri_info_list->addr_buffer;
                                    while (node != NULL)
                                    {
                                        if (node->next != NULL)
                                        {
                                            node = node->next;
                                        }
                                        else
                                        {
                                            node->next = addr_data;
                                            break;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                srv_mms_mem_mgr_app_adm_free(addr_data->addr);
                                addr_data->addr = NULL;
                                srv_mms_mem_mgr_app_adm_free(addr_data);
                                addr_data = NULL;
                                uc_data->addr_num--;
                                is_invalid = MMI_TRUE;
                            }
                        }
                        else
                        {
                            if (srv_mms_check_is_num_or_email_valid(SRV_UC_ADDRESS_TYPE_EMAIL, (char*)addr_data->addr))
                            {
                                /* srv_mms_uri_addr_enqueue(addr_data, &(uc_data->addr)); */
                                if (g_current_uri_info_list->addr_buffer == NULL)
                                {
                                    g_current_uri_info_list->addr_buffer = addr_data;
                                }
                                else
                                {
                                    node = g_current_uri_info_list->addr_buffer;
                                    while (node != NULL)
                                    {
                                        if (node->next != NULL)
                                        {
                                            node = node->next;
                                        }
                                        else
                                        {
                                            node->next = addr_data;
                                            break;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                srv_mms_mem_mgr_app_adm_free(addr_data->addr);
                                addr_data->addr = NULL;
                                srv_mms_mem_mgr_app_adm_free(addr_data);
                                addr_data = NULL;
                                uc_data->addr_num--;
                                is_invalid = MMI_TRUE;
                            }
                        }
                        /* uc_data->addr = g_current_uri_info_list->addr_buffer; */
                        break;
                    }
                    case MMS_URI_HEADER_SUBJECT:
                    {
                        if (g_current_uri_info_list->uc_subject)
                        {
                            srv_mms_mem_mgr_app_adm_free(g_current_uri_info_list->uc_subject);
                            g_current_uri_info_list->uc_subject = NULL;
                        }
                        g_current_uri_info_list->uc_subject =
                            (kal_uint8*) srv_mms_mem_mgr_app_adm_alloc((end + 1) * 2);
                        memset(g_current_uri_info_list->uc_subject, 0, (end + 1) * 2);
                        uc_data->subject = g_current_uri_info_list->uc_subject;
                        mmi_chset_utf8_to_ucs2_string(uc_data->subject, (end + 1) * 2, (U8*) tmp_str);
                        break;
                    }
                }
                str += (end - start) + 1;
                start = end = 0;
                end++;
                srv_mms_mem_mgr_app_adm_free(tmp_str);
                continue;
            }
        }
        
        if (app_strnicmp(str, MMS_URI_EXT_TO, 4) == 0)
        {
            str += 4;
            tmp_str += 4;
            start = end = 0;
            continue;
        }
        if (app_strnicmp(str, MMS_URI_TO, 3) == 0)
        {
            str += 3;
            tmp_str += 3;
            start = end = 0;
            continue;
        }
        if (app_strnicmp(str, MMS_URI_CC, 3) == 0)
        {
            cur_header = MMS_URI_HEADER_CC;
            str += 3;
            tmp_str += 3;
            start = end = 0;
            continue;
        }
        if (app_strnicmp(str, MMS_URI_SUBJECT_AMPERSAND_SYMB, 9) == 0)
        {
            /* cur_header = MMS_URI_HEADER_SUBJECT; */
            str += 9;
            tmp_str += 9;
            tmp_str += subject_length;
            str += subject_length;
            start = end = 0;
            continue;
        }
        if (app_strnicmp(str, MMS_URI_SUBJECT_AND_SYMB, 9) == 0)
        {
            /* cur_header = MMS_URI_HEADER_SUBJECT; */
            str += 9;
            tmp_str += 9;
            tmp_str += subject_length;
            str += subject_length;
            start = end = 0;
            continue;
        }
        if (app_strnicmp(str, MMS_URI_SUBJECT, 8) == 0)
        {
            /* cur_header = MMS_URI_HEADER_SUBJECT; */
            str += 8;
            tmp_str += 8;
            tmp_str += subject_length;
            str += subject_length;
            start = end = 0;
            continue;
        }
        if (app_strnicmp(str, MMS_URI_BODY, 5) == 0)
        {
            str += 5;
            tmp_str += 5;
            if (body)
            {
                str += strlen((const char*)body);
                tmp_str += strlen((const char*)body);
            }
            start = end = 0;
            continue;
        }
        if (strncmp((char*)str, " ", 1) == 0)
        {
            str += 1;
            tmp_str += 1;
            start = end = 0;
            continue;
        }
        end++;
    }
    /* To get the numbers if Left in the end */
    if (str != NULL)
    {
        switch (cur_header)
        {
            case MMS_URI_HEADER_TO:
            case MMS_URI_HEADER_CC:
            {
                uc_data->addr_num++;
                /* if(g_current_uri_info_list->addr_buffer != NULL)
                   {
                   srv_mms_mem_mgr_app_adm_free(g_current_uri_info_list->addr_buffer);
                   } */
                addr_data = (srv_uc_addr_struct*) srv_mms_mem_mgr_app_adm_alloc(sizeof(srv_uc_addr_struct));
                memset(addr_data, 0, sizeof(srv_uc_addr_struct));
                MMI_ASSERT(addr_data);
                if (strstr((S8*) str, "@") == NULL)
                {
                    addr_data->type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
                }
                else
                {
                    addr_data->type = SRV_UC_ADDRESS_TYPE_EMAIL;
                }
                if (cur_header == MMS_URI_HEADER_TO)
                {
                    addr_data->group = SRV_UC_ADDRESS_GROUP_TYPE_TO;
                }
                else
                {
                    addr_data->group = SRV_UC_ADDRESS_GROUP_TYPE_CC;
                }
                if (addr_data->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
                {
                    count = 0;
                    count2 = 0;

                    tmp_str2 = (char*)srv_mms_mem_mgr_app_adm_alloc(end + 1);
                    MMI_ASSERT(tmp_str2);
                    memset(tmp_str2, 0, end + 1);

                    while (count <= end)
                    {
                        if (str[count] != '-')
                        {
                            tmp_str2[count2] = str[count];
                            ++count2;
                        }
                        ++count;
                    }
                }
                addr_data->addr = (kal_uint8*) srv_mms_mem_mgr_app_adm_alloc((end + 1) * 2);
                if (addr_data->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
                {
                    mmi_chset_utf8_to_ucs2_string(addr_data->addr, (end + 1) * 2, (U8*) tmp_str2);
                }
                else
                {
                    mmi_chset_utf8_to_ucs2_string(addr_data->addr, (end + 1) * 2, (U8*) str);
                }
                addr_data->next = NULL;

                if (tmp_str2 != NULL)
                {
                    srv_mms_mem_mgr_app_adm_free(tmp_str2);
                    tmp_str2 = NULL;
                }

                if (addr_data->type != SRV_UC_ADDRESS_TYPE_EMAIL)
                {
                    if (srv_mms_check_is_num_or_email_valid(SRV_UC_ADDRESS_TYPE_PHONE_NUMBER, (char*)addr_data->addr))
                    {
                        /* srv_mms_uri_addr_enqueue(addr_data, &(uc_data->addr)); */
                        if (g_current_uri_info_list->addr_buffer == NULL)
                        {
                            g_current_uri_info_list->addr_buffer = addr_data;
                        }
                        else
                        {
                            node = g_current_uri_info_list->addr_buffer;
                            while (node != NULL)
                            {
                                if (node->next != NULL)
                                {
                                    node = node->next;
                                }
                                else
                                {
                                    node->next = addr_data;
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        srv_mms_mem_mgr_app_adm_free(addr_data->addr);
                        addr_data->addr = NULL;
                        srv_mms_mem_mgr_app_adm_free(addr_data);
                        addr_data = NULL;
                        uc_data->addr_num--;
                        is_invalid = MMI_TRUE;
                    }
                }
                else
                {
                    if (srv_mms_check_is_num_or_email_valid(SRV_UC_ADDRESS_TYPE_EMAIL, (char*)addr_data->addr))
                    {
                        /* srv_mms_uri_addr_enqueue(addr_data, &(uc_data->addr)); */
                        if (g_current_uri_info_list->addr_buffer == NULL)
                        {
                            g_current_uri_info_list->addr_buffer = addr_data;
                        }
                        else
                        {
                            node = g_current_uri_info_list->addr_buffer;
                            while (node != NULL)
                            {
                                if (node->next != NULL)
                                {
                                    node = node->next;
                                }
                                else
                                {
                                    node->next = addr_data;
                                    break;
                                }
                            }
                        }
                    }
                    else
                    {
                        srv_mms_mem_mgr_app_adm_free(addr_data->addr);
                        addr_data->addr = NULL;
                        srv_mms_mem_mgr_app_adm_free(addr_data);
                        addr_data = NULL;
                        uc_data->addr_num--;
                        is_invalid = MMI_TRUE;
                    }
                }
                break;
            }
        }
    }
    if (body != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(body);
    }
    if (subject != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(subject);
    }
    uc_data->callback = srv_mms_uri_scheme_cb;
    uc_data->addr = g_current_uri_info_list->addr_buffer;
    return is_invalid;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_uri_scheme_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  param       [?]     [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_uri_scheme_cb(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *temp;
    srv_uc_addr_struct *temp1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Free the memory allocated to UC Data Structure */
    if (g_current_uri_info_list->text_buffer != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(g_current_uri_info_list->text_buffer);
        g_current_uri_info_list->text_buffer = NULL;
    }
    if (g_current_uri_info_list->uc_subject != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(g_current_uri_info_list->uc_subject);
        g_current_uri_info_list->uc_subject = NULL;
    }

    /* if (g_current_uri_info_list->addr_buffer != NULL)
       {
       srv_mms_mem_mgr_app_adm_free(g_current_uri_info_list->addr_buffer);
       g_current_uri_info_list->addr_buffer = NULL;
       } */
    if (g_current_uri_info_list->param != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(g_current_uri_info_list->param);
        g_current_uri_info_list->param = NULL;
    }
    if (g_current_uri_info_list->cb != NULL)
    {
        g_current_uri_info_list->cb(g_current_uri_info_list->ura_appid, SRV_URIAGENT_APPID_MMS, MMI_FALSE);
        g_current_uri_info_list->cb = NULL;
    }
    if (g_current_uri_info_list->addr_buffer != NULL)
    {
        while (g_current_uri_info_list->addr_buffer != NULL)
        {
            temp = g_current_uri_info_list->addr_buffer->addr;
            srv_mms_mem_mgr_app_adm_free(temp);
            temp = NULL;
            temp1 = g_current_uri_info_list->addr_buffer;
            g_current_uri_info_list->addr_buffer = g_current_uri_info_list->addr_buffer->next;
            srv_mms_mem_mgr_app_adm_free(temp1);
            temp1 = NULL;

        }
    }
    memset(g_current_uri_info_list, 0, sizeof(srv_mms_current_uri_info_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_strdup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
char *srv_mms_strdup(const char *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *s_new = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s != NULL)
    {
        s_new = (char*)srv_mms_mem_mgr_app_adm_alloc(strlen(s) + 1);
        if (s_new != NULL)
        {
            strcpy(s_new, s);
        }
    }

    return s_new;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_strndup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s           [IN]        
 *  length      [IN]        
 *  len(?)      [IN](?)
 * RETURNS
 *  
 *****************************************************************************/
char *srv_mms_strndup(const char *s, int length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *s_new;
    U32 len = (U32) (length);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (s != NULL)
    {
        s_new = (char*)srv_mms_mem_mgr_app_adm_alloc(len + 1);
        MMI_ASSERT(s_new);
        memset(s_new, 0, len + 1);
        if (s_new != NULL)
        {
            strncpy(s_new, s, len);
            s_new[len] = '\0';
        }
    }
    else
    {
        s_new = (char*)srv_mms_mem_mgr_app_adm_alloc(1);
        MMI_ASSERT(s_new);
        if (s_new != NULL)
        {
            s_new[0] = '\0';
        }
    }

    return s_new;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_set_uri_parameters
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ura_appid       [IN]        
 *  param           [?]         [?]         [?]         [?]
 *  cb              [IN]        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_set_uri_parameters(kal_uint32 ura_appid, char *param, srv_uriagent_uri_request_hdlr_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_current_uri_info_list, 0, sizeof(srv_mms_current_uri_info_struct));
    g_current_uri_info_list->ura_appid = ura_appid;
    len = (U32) strlen(param);
    MMI_ASSERT(len < SRV_MMS_MAX_URI_LENGTH);
    g_current_uri_info_list->param = (char*)srv_mms_mem_mgr_app_adm_alloc(SRV_MMS_MAX_URI_LENGTH);
    MMI_ASSERT(g_current_uri_info_list->param);
    memset(g_current_uri_info_list->param, 0, SRV_MMS_MAX_URI_LENGTH);
    strncpy(g_current_uri_info_list->param, param, SRV_MMS_MAX_URI_LENGTH - 1);
    g_current_uri_info_list->cb = cb;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_uri_exit_hndlr_for_confirm_popup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_uri_exit_hndlr_for_confirm_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_prof_stop_tone(SRV_PROF_TONE_WARNING);
    if (g_current_uri_info_list->cb != NULL)
    {
        g_current_uri_info_list->cb(g_current_uri_info_list->ura_appid, SRV_URIAGENT_APPID_MMS, MMI_FALSE);
        g_current_uri_info_list->cb = NULL;
    }
    if (g_current_uri_info_list->param != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(g_current_uri_info_list->param);
        g_current_uri_info_list->param = NULL;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_launch_write_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_launch_write_msg(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_uri_insert_hdlr_ext(
        g_current_uri_info_list->ura_appid,
        g_current_uri_info_list->param,
        g_current_uri_info_list->cb);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_send_call_back_to_uri_agnt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_send_call_back_to_uri_agnt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_current_uri_info_list->cb != NULL)
    {
        g_current_uri_info_list->cb(g_current_uri_info_list->ura_appid, SRV_URIAGENT_APPID_MMS, MMI_FALSE);
        g_current_uri_info_list->cb = NULL;
        /* Call the Callback Function registered with result as FALSE */
    }
    if (g_current_uri_info_list->param != NULL)
    {
        srv_mms_mem_mgr_app_adm_free(g_current_uri_info_list->param);
        g_current_uri_info_list->param = NULL;
    }
#ifndef __COSMOS_MMI_PACKAGE__
    GoBackHistory();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_de_init_uri
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_de_init_uri(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_uri_scheme_cb(NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_stristr
 * DESCRIPTION
 *  This function performs strstr in case-insensitive way.
 * PARAMETERS
 *  src_str     [IN]        Source string
 *  tbf_str     [IN]        String to be found
 * RETURNS
 *  NULL: not found
 *  non-NULL: pointer of 1st found substring
 *****************************************************************************/
kal_char *srv_mms_stristr(const kal_char *src_str, const kal_char *tbf_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 match_flag = 0;   /* reset */
    kal_int32 i = 0;            /* reset */
    kal_int32 j = 0;            /* reset */
    kal_int32 reset_i = -1;     /* reset */
    kal_int32 left, left_fixed;
    kal_char s1, s2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!src_str || !tbf_str || !strlen(tbf_str) || !strlen(src_str) || strlen(tbf_str) > strlen(src_str))
    {
        return NULL;
    }

    left = left_fixed = strlen(tbf_str);

    while (*(src_str + i) && *(tbf_str + j) && left)
    {
        /* both convert to lower case */
        s1 = (kal_char) (islower((kal_int32) * (src_str + i)) ? *(src_str + i) : tolower((kal_int32) * (src_str + i)));
        s2 = (kal_char) (islower((kal_int32) * (tbf_str + j)) ? *(tbf_str + j) : tolower((kal_int32) * (tbf_str + j)));

        if (s1 != s2)
        {
            if (reset_i >= 0)
            {
                i = reset_i + 1;
                reset_i = -1;
            }
            else
            {
                i++;
            }

            j = 0;
            match_flag = 0;
            left = left_fixed;
        }
        else
        {
            if (match_flag == 0)
            {
                /* 1st matched */
                reset_i = i;
                match_flag = 1;
            }

            i++;
            j++;
            left--;
        }
    }

    if (left == 0)
    {
        /* return 1st matched substring */
        return (kal_char*) src_str + i - left_fixed;
    }

    return NULL;
}
#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ /* #ifdef __UNIFIED_COMPOSER_SUPPORT__ */
#endif /* __MMI_MMS_URI_AGENT__ */ 

#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))


/*****************************************************************************
 * FUNCTION
 *  srv_mms_check_is_num_or_email_valid
 * DESCRIPTION
 *  Check if number or Email id is valid
 * PARAMETERS
 *  type        [IN]        
 *  addr        [?]         [?]         [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
BOOL srv_mms_check_is_num_or_email_valid(srv_uc_address_type_enum type, char *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == SRV_UC_ADDRESS_TYPE_EMAIL)
    {
        if (mmi_ucs2strlen((S8*) addr) > MMI_EMAIL_MAX_ADDR_LEN)
        {
            return MMI_FALSE;
        }
        if (applib_is_valid_email_address_unicode((kal_wchar*) addr))
        {
            return MMI_TRUE;
        }

    }
    else
    {
        if (applib_is_valid_number_unicode((kal_wchar*) addr))
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

#endif /* (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__)) */ 

#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_vendor_create_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_msg      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_vendor_create_req_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_create_req_struct msg_req;
    mmi_mms_vendor_create_req_struct *vendor_req = (mmi_mms_vendor_create_req_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_vendor_context->app_id = vendor_req->app_id;
    if (g_is_wap_ready == MMI_FALSE)
    {
        /* Can not use API mma_get_request_id if mma is not ready */
        srv_mms_send_create_rsp_to_vendor(0, MMI_MMS_VENDOR_FAIL);
        return;
    }
    memset(&msg_req, 0, sizeof(srv_mms_create_req_struct));
    msg_req.msg_id = 0;
    msg_req.app_id = MMI_MMS_VENDOR_CVM_APP_ID;

    if (vendor_req->mms_type == MMI_MMS_VENDOR_TYPE_SMIL_MMS)
    {
        msg_req.mode = MMA_MODE_EDIT;
    }
    else if (vendor_req->mms_type == MMI_MMS_VENDOR_TYPE_MIXED_MMS)
    {
        msg_req.mode = MMA_MODE_MIXED;
    }
    else
    {
        MMI_ASSERT(0);
    }

    if (vendor_req->sim_id == MMI_MMS_VENDOR_SIM_ID_SIM1)
    {
        msg_req.sim_id = MMA_SIM_ID_SIM1;
    }
    else if (vendor_req->sim_id == MMI_MMS_VENDOR_SIM_ID_SIM2)
    {
        msg_req.sim_id = MMA_SIM_ID_SIM2;
    }
    else
    {
        MMI_ASSERT(0);
    }

    mmi_ucs2cpy((PS8) msg_req.xml_filepath, (PS8) vendor_req->xml_filepath);
    msg_req.xml_size = applib_get_file_size(vendor_req->xml_filepath);

    if (0 == msg_req.xml_size)
    {
        srv_mms_send_create_rsp_to_vendor(0, MMI_MMS_VENDOR_FAIL);
        return;
    }
    msg_req.user_data = 0;
    msg_req.call_back = srv_mms_vendor_create_rsp;
    srv_mms_create(&msg_req);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_vendor_create_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_result      [IN]        
 *  rsp_data        [?]         
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_vendor_create_rsp(srv_mms_result_enum srv_result, void *rsp_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;
    U8 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_result != SRV_MMS_RESULT_OK)
    {
        result = MMI_MMS_VENDOR_FAIL;
        srv_mms_send_create_rsp_to_vendor(0, result);
        return;
    }

    if (msg_rsp->result != MMA_RESULT_OK)
    {
        if (msg_rsp->result == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE)
        {
            result = MMI_MMS_VENDOR_MEMORY_NOT_ENOUGH;
        }
        else
        {
            result = MMI_MMS_VENDOR_FAIL;
        }
        srv_mms_send_create_rsp_to_vendor(0, result);
    }
    else
    {
        srv_mms_send_create_rsp_to_vendor(msg_rsp->msg_id, MMI_MMS_VENDOR_PASS);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_send_create_rsp_to_vendor
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_send_create_rsp_to_vendor(U32 msg_id, U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mms_vendor_create_rsp_struct *msg_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_rsp = (mmi_mms_vendor_create_rsp_struct*) OslConstructDataPtr(sizeof(mmi_mms_vendor_create_rsp_struct));

    msg_rsp->app_id = g_umms_vendor_context->app_id;
    msg_rsp->msg_id = msg_id;
    msg_rsp->result = result;

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_MMI_MMS_VENDOR_CREATE_RSP),
        0,
        MSG_ID_MMI_MMS_VENDOR_CREATE_RSP,
        (oslParaType*) msg_rsp,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_vendor_send_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_msg      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_vendor_send_req_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = 0;
    mmi_mms_vendor_send_req_struct *vendor_req = (mmi_mms_vendor_send_req_struct*) in_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_umms_vendor_context->app_id = vendor_req->app_id;
    if (vendor_req->sim_id == MMI_MMS_VENDOR_SIM_ID_SIM1)
    {
        sim_id = (U8) MMA_SIM_ID_SIM1;
    }
    else if (vendor_req->sim_id == MMI_MMS_VENDOR_SIM_ID_SIM2)
    {
        sim_id = (U8) MMA_SIM_ID_SIM2;
    }
    else
    {
        MMI_ASSERT(0);
    }
    srv_mms_bgsr_vendor_send_msg_req(vendor_req->msg_id, sim_id);
}

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
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_vendor_cancel_send_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_msg      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_vendor_cancel_send_req_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mms_vendor_cancel_send_req_struct *vendor_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vendor_req = (mmi_mms_vendor_cancel_send_req_struct*) in_msg;

    srv_mms_bgsr_cancel_send_req(vendor_req->msg_id);

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_vendor_delete_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in_msg      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_vendor_delete_req_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mms_vendor_delete_req_struct *vendor_req = (mmi_mms_vendor_delete_req_struct*) in_msg;
    mmi_mms_vendor_delete_rsp_struct *msg_rsp;
    U8 error = 0;
    U8 result = 0;
    U8 srv_result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_rsp = (mmi_mms_vendor_delete_rsp_struct*) OslConstructDataPtr(sizeof(mmi_mms_vendor_delete_rsp_struct));

    msg_rsp->app_id = vendor_req->app_id;
    msg_rsp->msg_id = vendor_req->msg_id;
    if (g_is_wap_ready == MMI_FALSE)
    {
        msg_rsp->result = MMI_MMS_VENDOR_FAIL;
        srv_mms_send_message(
            MOD_MMI,
            mms_get_service_module(MSG_ID_MMI_MMS_VENDOR_DELETE_RSP),
            0,
            MSG_ID_MMI_MMS_VENDOR_DELETE_RSP,
            (oslParaType*) msg_rsp,
            NULL);
        return;
    }

    srv_result = (U8) srv_mms_delete_msg(vendor_req->msg_id, &error);

    if (srv_result != SRV_MMS_RESULT_OK)
    {
        msg_rsp->result = MMI_MMS_VENDOR_FAIL;
        srv_mms_send_message(
            MOD_MMI,
            mms_get_service_module(MSG_ID_MMI_MMS_VENDOR_DELETE_RSP),
            0,
            MSG_ID_MMI_MMS_VENDOR_DELETE_RSP,
            (oslParaType*) msg_rsp,
            NULL);
        return;
    }

    if (error == MMA_RESULT_OK)
    {
        result = MMI_MMS_VENDOR_PASS;
    }
    else if (error == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE)
    {
        result = MMI_MMS_VENDOR_MEMORY_NOT_ENOUGH;
    }
    else
    {
        result = MMI_MMS_VENDOR_FAIL;
    }

    msg_rsp->result = result;

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_MMI_MMS_VENDOR_DELETE_RSP),
        0,
        MSG_ID_MMI_MMS_VENDOR_DELETE_RSP,
        (oslParaType*) msg_rsp,
        NULL);
}

#endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 

#endif /* __MMI_MMS_2__ */ 

