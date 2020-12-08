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
 * BrowserSrvInterface.c
 *
 * Project:
 * --------
 *   MAUI
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "MMI_features.h"
#ifndef MMI_BROWSERSRVINTERFACE_C
#define MMI_BROWSERSRVINTERFACE_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__
#include "app_ltlcom.h"
#include "BrowserSrvInterface.h"
#include "BrowserSrvMain.h"
#include "BrowserSrvMsgHdlr.h"
#include "MMIDataType.h"
#include "WAPProfileSrvType.h"
#include "BrowserSrvBookmarks.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "Conversions.h"
#include "FileMgrSrvGProt.h"
#include "Unicodexdcl.h"
#include "MMI_inet_app_trc.h"
#include "kal_trace.h"
#include "BrowserSrvProts.h"
#include "browser_api.h"
#include "fs_type.h"
#include "fs_func.h"
#include "gui_data_types.h"
#include "vBookmark.h"
#include "BrowserSrvGprot.h"
#include "custom_wap_config.h"
#include "common_nvram_editor_data_item.h"
#include "mmi_frm_nvram_gprot.h"
#include "nvram_common_defs.h"
#include "app_ltlcom.h"
#include "bam_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_msgs.h"
#include "DLAgentSrvDef.h"
#include "stack_config.h"
#include "stack_common.h"
#include "BrowserSrvConfig.h"
#include "stdio.h"
#include "mmi_frm_input_gprot.h"
#include "wps_struct.h"
#include "mmi_frm_events_gprot.h"
#include "WAPPushSrvTypes.h"
#include "WAPProfileSrvGProt.h"
#include "DtcntSrvGprot.h"
#include "BrowserSrvSettings.h"

extern char* bam_main_getVrsnNo(void);
#ifdef OBIGO_Q03C
extern void bam_handle_pen_event_ext(int instance_id, int pos_x, int pos_y, int type);
extern const char* bam_cfg_default_accept_header(void);
#else
extern const char* bam_cfg_brs_default_accept_header(void);
#endif

extern char* bam_url_escape_string(const char* s, wap_bam_alloc_func malloc_func);

#define srv_brw_to_hex_char(val) (CHAR)((val) < 10 ? ('0' + (val)) : ('A' + ((val) - 10)))
#define srv_brw_is_alphabet(ch)  (((ch) >= 'A' && (ch) <= 'Z') || ((ch) >= 'a' && (ch) <= 'z'))
#define srv_brw_is_digit(ch)     ((ch) >= '0' && (ch) <= '9')


#ifdef __MMI_VBOOKMARK__
#ifdef __MMI_CCA_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_add_bookmark_provisioning
 * DESCRIPTION
 *  This function is an external interface for adding a bookmark without user
 *  interface
 * PARAMETERS
 *  title_p         [IN]        Bookmark title in UCS2
 *  url_p           [IN]        Bookmark URL in utf-8
 *  callback        [IN]        
 * RETURNS
 *  Error of type srv_brw_bkm_error_code_enum
 *****************************************************************************/
void srv_brw_add_bookmark_provisioning(U8 *title_p, U8 *url_p, srv_wap_prof_response_funcptr_type callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 err;
    srv_brw_bookmark_file_struct *obj;
    MMI_BOOL is_asm_memory_taken = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(url_p);

    if (strlen((S8*) url_p) > SRV_BRW_MAX_URL_LEN)
    {
        callback(SRV_WAP_PROF_URL_VALIDATION_ERR);
        return;
    }

#ifdef __COSMOS_MMI_PACKAGE__
    if(!g_srv_brw_memory_pool)
#else
    if(!g_srv_brw_cntx.brw_adm_id)
#endif
    {
    #ifdef __COSMOS_MMI_PACKAGE__
        g_srv_brw_memory_pool = applib_asm_alloc_r(VAPP_BROWSER, SRV_BRW_APP_POOL_SIZE);
    #else
        g_srv_brw_memory_pool = applib_asm_alloc_r(APP_BROWSER, SRV_BRW_APP_POOL_SIZE);
    #endif
        if(!g_srv_brw_memory_pool)
        {
            callback(SRV_WAP_PROF_ERR);
            return;
        }
        g_srv_brw_cntx.brw_adm_id = kal_adm_create(
                                    (char*)g_srv_brw_memory_pool,
                                    SRV_BRW_APP_POOL_SIZE,
                                    NULL,
                                    KAL_FALSE);
        MMI_ASSERT(g_srv_brw_cntx.brw_adm_id);
        is_asm_memory_taken = MMI_TRUE;
    }
    if (srv_brw_bkm_initialize_bookmark_context() < 0)
    {
        if(is_asm_memory_taken)
        {
            kal_adm_delete(g_srv_brw_cntx.brw_adm_id);
            g_srv_brw_cntx.brw_adm_id = NULL;

        #ifdef __COSMOS_MMI_PACKAGE__
            applib_asm_free_r(VAPP_BROWSER, g_srv_brw_memory_pool);
        #else
            applib_asm_free_r(APP_BROWSER, g_srv_brw_memory_pool);
        #endif
            g_srv_brw_memory_pool = NULL;
        }
        callback(SRV_WAP_PROF_ERR);
        return;
    }
    obj = (srv_brw_bookmark_file_struct*) srv_brw_malloc(sizeof(srv_brw_bookmark_file_struct));
    memset(obj, 0, sizeof(srv_brw_bookmark_file_struct));

    mmi_chset_utf8_to_ucs2_string((U8*) obj->file_url, (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH, (U8*) url_p);

    if (title_p)
    {
        mmi_ucs2ncpy((S8*) obj->file_name, (S8*) title_p, SRV_BRW_BKM_MAX_INPUT_FILE_NAME_LEN);
    }

    err = srv_brw_bookmarks_add_to_bookmark_silently(obj);
    srv_brw_free(obj);
    if(is_asm_memory_taken)
    {
        srv_brw_bkm_deinitialize_bookmark_context();
        kal_adm_delete(g_srv_brw_cntx.brw_adm_id);
        g_srv_brw_cntx.brw_adm_id = NULL;

    #ifdef __COSMOS_MMI_PACKAGE__
        applib_asm_free_r(VAPP_BROWSER, g_srv_brw_memory_pool);
    #else
        applib_asm_free_r(APP_BROWSER, g_srv_brw_memory_pool);
    #endif
        g_srv_brw_memory_pool = NULL;
    }
    switch (err)
    {
        case SRV_BRW_BKM_PROVISIONING_SUCCESS:
        {
            callback(SRV_WAP_PROF_SUCCESS);
            break;
        }
        case SRV_BRW_BKM_PROVISIONING_INVALID_URL:
        {
            callback(SRV_WAP_PROF_URL_VALIDATION_ERR);
            break;
        }
        case SRV_BRW_BKM_PROVISIONING_INVALID_TITLE:
        {
            callback(SRV_WAP_PROF_BKM_TITLE_ERR);
            break;
        }
        case SRV_BRW_BKM_PROVISIONING_MEMORY_FULL:
        {
            callback(SRV_WAP_PROF_MEM_FULL_ERR);
            break;
        }
        case SRV_BRW_BKM_PROVISIONING_FILE_SYSTEM_ERROR:
        default:
        {
            callback(SRV_WAP_PROF_ERR);
            break;
        }
    }
}
#endif /* #ifdef __MMI_CCA_SUPPORT__ */
#endif /* __MMI_VBOOKMARK__ */


/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_active_sim_id
 * DESCRIPTION
 *  This API is for UPP to get active SIM card
 * PARAMETERS
 *  void
 * RETURNS
 *  Active profile of type srv_brw_active_sim_setting_enum
 *****************************************************************************/
mmi_brw_sim_id_enum srv_brw_get_active_sim_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_sim_type_enum sim_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dtcnt_get_sim_preference(&sim_id);
    return srv_brw_convert_sim_setting_to_browser_sim_id(srv_brw_convert_dtcnt_sim_id_to_sim_setting(sim_id));
}


#ifdef __MMI_VBOOKMARK__
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_default_bookmark_by_index
 * DESCRIPTION
 *  This function is an external interface for getting the operator's default
	bookmark information
 * PARAMETERS
 *  index - The index of the specified operator default bookmark, ranges from 
		0 to (total_op_bookmarks ¨C 1) [IN]
	title_buf  - The buffer provided by the caller to store the title 
		information of the specified operator default bookmark, valued NULL means 
		caller doesn¡¯t require title information [OUT]
	title_buf_len - The buffer length of title_buf [IN]
	url_buf - The buffer provided by the caller to store the URL information 
		of the specified operator default bookmark, valued NULL means 
		caller doesn¡¯t require URL information [OUT]
	url_buf_len - The buffer length of url_buf [IN]
 * RETURNS
 *  The execution result to get the operator's default bookmark information. 
	The value would be KAL_TRUE or KAL_FALSE

 *****************************************************************************/
kal_bool srv_brw_get_default_bookmark_by_index (int index, 
									kal_uint8 *title_buf, kal_uint16 title_buf_len, 
									kal_uint8 *url_buf, kal_uint16 url_buf_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 nBytes = 0;
    FS_HANDLE file_handle = 0;
    WCHAR *root_file_path;
    U8* buffer;
    srv_brw_bkm_types_enum file_type;
    S32 count = 0;
    S32 result;
    U8* buffer_ptr;
    U8 current_index = 0;
    U8 temp[SRV_BRW_BKM_TIMESTAMP_SIZE + 1] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    root_file_path = (WCHAR*)OslMalloc((mmi_ucs2strlen((S8*) g_srv_brw_cntx.default_folder_path) + mmi_ucs2strlen((S8*)SRV_BRW_BKM_ROOT_FILE_NAME) + 2) * ENCODING_LENGTH);
    mmi_ucs2cpy((S8*) root_file_path, (S8*) g_srv_brw_cntx.default_folder_path);
    mmi_ucs2cat((S8*) root_file_path, (S8*) L"\\");
    mmi_ucs2cat((S8*) root_file_path, (S8*) SRV_BRW_BKM_ROOT_FILE_NAME);

    file_handle = FS_Open((const WCHAR*) root_file_path, FS_READ_WRITE | FS_CREATE);
    if(file_handle < 0)
    {
        OslMfree(root_file_path);
        return file_handle;
    }
    OslMfree(root_file_path);
    buffer = (U8*)OslMalloc(SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE);
    memset(buffer, 0, SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE);
    FS_Seek(file_handle, 0, SEEK_SET);
    while((result = FS_Read(file_handle, buffer, SRV_BRW_BKM_BOOKMARK_ENTRY_SIZE, &nBytes)) == FS_NO_ERROR && nBytes != 0)
    {
        buffer_ptr = buffer;
        memset(temp, 0, SRV_BRW_BKM_TIMESTAMP_SIZE + 1);
        strncpy((S8*)temp, (S8*)buffer, SRV_BRW_BKM_TYPE_SIZE);
        file_type = atoi((const S8*)temp);
        if(file_type == SRV_BRW_BKM_TYPE_DEFAULT_FILE)
        {
            if(current_index == index)
            {
                S8* token_location;
                buffer_ptr += SRV_BRW_BKM_TYPE_SIZE +  SRV_BRW_BKM_TIMESTAMP_SIZE + (2 *SRV_BRW_BKM_LINE_BREAK_SIZE);
                if(title_buf != NULL)
                {
                    U8 *temp_title;
                    temp_title = (U8*)OslMalloc(SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1);
                    memset(temp_title, 0, SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1);
                    strncpy((S8*)temp_title, (S8*)buffer_ptr, SRV_BRW_BKM_MAX_FILE_NAME_LEN);
                    token_location = strchr(temp_title, SRV_BRW_BKM_TITLE_PADDING_TOKEN);
                    if(token_location)
                    {
                        *token_location = '\0';
                    }
                    mmi_chset_utf8_to_ucs2_string((U8*) title_buf, title_buf_len * ENCODING_LENGTH, (U8*) temp_title);
                    OslMfree(temp_title);
                }
                if(url_buf != NULL)
                {
                    U8 *temp_url;
                    buffer_ptr = buffer_ptr + SRV_BRW_BKM_MAX_FILE_NAME_LEN + SRV_BRW_BKM_LINE_BREAK_SIZE;
                    temp_url = (U8*)OslMalloc(SRV_BRW_MAX_URL_LEN + 1);
                    memset(temp_url, 0, SRV_BRW_MAX_URL_LEN + 1);
                    strncpy((S8*)temp_url, (S8*)buffer_ptr, SRV_BRW_MAX_URL_LEN);
                    token_location = strchr(temp_url, SRV_BRW_BKM_URL_PADDING_TOKEN);
                    if(token_location)
                    {
                        *token_location = '\0';
                    }
                    mmi_asc_n_to_ucs2((S8*) url_buf, (S8*) temp_url, url_buf_len);
                    OslMfree(temp_url);
                }
                break;
            }
            else
            {
                current_index++;
            }
        }
    }
    FS_Close(file_handle);
    OslMfree(buffer);
    return count;
}

/*****************************************************************************
 * FUNCTION
 *  wap_browser_get_num_of_op_default_bookmarks
 * DESCRIPTION
 *  This function is an external interface to get the Total number of 
	operator's default bookmarks
 * PARAMETERS
 *  void
 * RETURNS
 *  Total number of operator's default bookmarks
 *****************************************************************************/
S32 srv_brw_get_num_of_default_bookmarks (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_brw_bkm_get_bookmarks_count_for_op_hs(SRV_BRW_BKM_TYPE_DEFAULT_FILE));
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_num_of_user_defined_bookmarks
 * DESCRIPTION
 *  This function is an external interface to get the Total number 
	of User - defined bookmarks
 * PARAMETERS
 *  void
 * RETURNS
 *  Total number of User - defined bookmarks
 *****************************************************************************/
S32 srv_brw_get_num_of_user_defined_bookmarks (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_brw_bkm_get_bookmarks_count_for_op_hs(SRV_BRW_BKM_TYPE_USER_CREATED_FILE));
}
#endif /* #if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__) */
#endif /* __MMI_VBOOKMARK__ */


/*****************************************************************************
 * FUNCTION
 *  srv_brw_set_as_homepage
 * DESCRIPTION
 *  This function is used to set a given URL as the homepage for currently 
	active profile 
 * PARAMETERS
 *  url_ascii -- URL(ascii) to be set as the homepage of active profile[IN]
 * RETURNS
 *  Add as homepage result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_set_as_homepage (U8 *url_p)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 url_ascii[SRV_BRW_MAX_URL_LEN + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_brw_validate_url((U8*)url_p, (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH) < 0)
    {
        return SRV_BRW_ERROR_INVALID_URL;
    }
    mmi_chset_ucs2_to_utf8_string((U8*) url_ascii, SRV_BRW_MAX_URL_LENGTH + 1, (U8*) url_p);
#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
    srv_brw_update_user_defined_homepage(url_ascii);
    g_srv_brw_cntx.homepage_setting = SRV_BRW_HOMEPAGE_SETTING_USER_DEFINED;
    srv_brw_update_settings_data(SRV_BRW_NVRAM_SETTINGS_HOMEPAGE);
    return SRV_BRW_ERROR_OK;
#else
    {
        srv_wap_prof_profile_content_struct *profile_content_p;
        MMI_BOOL ret = MMI_FALSE;
        U8* ascii_url;
        U16 url_len;
        srv_brw_get_profile_content((void **)&profile_content_p);
        ascii_url = (U8*) OslMalloc(SRV_BRW_MAX_URL_LEN);
        memset(ascii_url, 0, SRV_BRW_MAX_URL_LEN);
        url_len = mmi_ucs2_to_asc((S8*) ascii_url, (S8*) url_p);
        ret = srv_dtcnt_set_homepage(profile_content_p->data_account_primary_id, (CHAR *)ascii_url, url_len);
        OslMfree(profile_content_p);
        if(ret)
        {
            return SRV_BRW_ERROR_OK;
        }
        else
        {
            return SRV_BRW_ERROR;
        }
    }
#endif /* #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__ */

}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_homepage
 * DESCRIPTION
 *  This function is used to get the currently set homepage of the browser 
 * PARAMETERS
 *  url_ascii -- URL(ascii) to be set as the homepage of browser[IN|OUT]
 * RETURNS
 *  Add as homepage result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_get_homepage (U8 *url_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(url_p);
#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
    return (srv_brw_get_user_defined_homepage(url_p));
#else
    {
        srv_wap_prof_profile_content_struct *profile_content_p;
        srv_brw_get_profile_content((void **)&profile_content_p);
        strncpy((S8*)url_p, (S8 *) profile_content_p->url, SRV_BRW_MAX_URL_LEN);
        return SRV_BRW_ERROR_OK;
    }
#endif /* #ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__ */
}
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_read_address_list_data
 * DESCRIPTION
 *  This interface is for getting the Address List from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  NVRAM read operation error
 *****************************************************************************/
S16 srv_brw_read_address_list_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_count;
    S16 NvramError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ((g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p == NULL) && (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p == NULL))
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p =
            (nvram_brw_hist_title_struct*) srv_brw_malloc(NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS *
                                                           NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE);
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p =
            (nvram_brw_hist_url_struct*) srv_brw_malloc(NVRAM_BRW_NUM_ADDRESS_HISTORY_URL_RECORDS *
                                                         NVRAM_BRW_ADDRESS_HISTORY_URL_SIZE);

        memset(
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p,
            0,
            (NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE * NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS));
        memset(
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p,
            0,
            (NVRAM_BRW_ADDRESS_HISTORY_URL_SIZE * NVRAM_BRW_NUM_ADDRESS_HISTORY_URL_RECORDS));
    }
    for (record_count = 1; record_count <= NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS; record_count++)
    {
        ReadRecord(
            NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_LID,
            record_count,
            &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[(record_count - 1) * TITLES_PER_RECORD],
            NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE,
            &NvramError);
    }

    for (record_count = 1; record_count <= NVRAM_BRW_NUM_ADDRESS_HISTORY_URL_RECORDS; record_count++)
    {
        ReadRecord(
            NVRAM_EF_BRW_ADDRESS_HISTORY_URL_LID,
            record_count,
            &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[(record_count - 1) * URLS_PER_RECORD],
            NVRAM_BRW_ADDRESS_HISTORY_URL_SIZE,
            &NvramError);
    }
    srv_brw_address_list_get_number_of_items();
    return NvramError;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_address_list_get_number_of_items
 * DESCRIPTION
 *  This interface is for getting the number of Address history items
 * PARAMETERS
 *  void
 * RETURNS
 *  Address history items count
 *****************************************************************************/
U8 srv_brw_address_list_get_number_of_items (void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 history_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p)
    {
        return 0;
    }
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items = 0;

    for (history_count = 0; history_count < SRV_BRW_ADDRESS_LIST_MAX_ITEMS; history_count++)
    {
        /* If length of url is '0' then exit the loop */
        if ((g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p) && (strlen((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[history_count].url)) == 0)
        {
            break;
        }
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items++;
    }
	return (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items);
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_address_list_add_item
 * DESCRIPTION
 *  This interface is for getting the number of Address history items
 * PARAMETERS
 *  url_p(UCS2) -- URL to be added to address history
 * RETURNS
 *  Add item result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_address_list_add_item (S8* url_p)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hist_count;
    S8 url_string[NVRAM_BRW_ADDRESS_HISTORY_MAX_URL_LENGTH * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_brw_validate_url((U8*)url_p, SRV_BRW_ADDRESS_LIST_URL_LENGTH - 1) < 0)
    {
		// handle in callback
        return SRV_BRW_ERROR_INVALID_URL;
    }
#ifdef __COSMOS_MMI_PACKAGE__
#ifndef __MMI_BRW_SLIM__
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcut_item_flag = MMI_TRUE;
#endif
#endif
    for (hist_count = 0; hist_count < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items; ++hist_count)
    {
        mmi_asc_to_ucs2((S8*) url_string, (S8*) & g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[hist_count].url);

        if (!mmi_ucs2cmp((S8*) url_p, (S8*) url_string))
        {
            if(hist_count)
            {
                srv_brw_address_list_set_item_at_top(hist_count);
                srv_brw_address_list_update_data(SRV_BRW_LIST_ACTION_UPDATE_ENTIRE_LIST, NULL);
            }
            return SRV_BRW_ERROR_OK;
        }
    }

    if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[0].dcs = SRV_BRW_DCS_ASCII;
        strcpy((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[0].title, (S8*) "");
        mmi_ucs2_to_asc((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[0].url, (S8*) url_p);
    }
    else
    {
        for (hist_count = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items; hist_count >= 1; hist_count--)
        {
            if (hist_count < SRV_BRW_ADDRESS_LIST_MAX_ITEMS)
            {
                memcpy(
                    &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[hist_count],
                    &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[hist_count - 1],
                    sizeof(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[hist_count]));
                memcpy(
                    &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[hist_count],
                    &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[hist_count - 1],
                    sizeof(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[hist_count]));
            }
        }

        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[0].dcs = SRV_BRW_DCS_ASCII;
        strcpy((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[0].title, (S8*) "");
        mmi_ucs2_to_asc((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[0].url, (S8*) url_p);
    }

    srv_brw_address_list_update_data(SRV_BRW_LIST_ACTION_UPDATE_ENTIRE_LIST, NULL); //write list to NVRAM

    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items < SRV_BRW_ADDRESS_LIST_MAX_ITEMS)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items++;
    }
	return SRV_BRW_ERROR_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_address_list_delete_item
 * DESCRIPTION
 *  This interface is for deleting Nth address history item
 * PARAMETERS
 *  item_index -- Item Index of the address history items to be deleted
 * RETURNS
 *  Delete item result of type srv_brw_error_enum
 *****************************************************************************/

srv_brw_error_enum srv_brw_address_list_delete_item (S32 item_index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = item_index; count < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items - 1; ++count)
    {
        memcpy(
            &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[count],
            &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[count + 1],
            sizeof(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[count]));
        memcpy(
            &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[count],
            &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[count + 1],
            sizeof(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[count]));
    }

    memset(
        &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items - 1],
        0,
        sizeof(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items - 1]));
    memset(
        &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items - 1],
        0,
        sizeof(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items - 1]));

    srv_brw_address_list_update_data(SRV_BRW_LIST_ACTION_UPDATE_ENTIRE_LIST, NULL);

    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items--;
	return SRV_BRW_ERROR_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_address_list_set_item_at_top
 * DESCRIPTION
 *  Interface to set a selected item at the top of address history
 * PARAMETERS
 *  selected_item_index     [IN]        
 * RETURNS
 *  Operation Result
 *****************************************************************************/
srv_brw_error_enum srv_brw_address_list_set_item_at_top(U32 selected_item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 list_index;
    U8 title_dcs;
	U8 title_temp[(SRV_BRW_ADDRESS_LIST_TITLE_LENGTH) * ENCODING_LENGTH]; 
    U8 url_temp[(SRV_BRW_ADDRESS_LIST_URL_LENGTH) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (selected_item_index >= SRV_BRW_ADDRESS_LIST_MAX_ITEMS)
    {
        ASSERT(0);
    }

    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[selected_item_index].dcs == SRV_BRW_DCS_UCS)
    {
        title_dcs = SRV_BRW_DCS_UCS;
        mmi_ucs2cpy(
            (S8*) title_temp,
            (S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[selected_item_index].title);
    }
    else
    {
        title_dcs = SRV_BRW_DCS_ASCII;
        mmi_asc_to_ucs2(
            (S8*) title_temp,
            (S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[selected_item_index].title);
    }

    mmi_asc_to_ucs2((S8*) url_temp, (S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[selected_item_index].url);

    for (list_index = selected_item_index; list_index >= 1; list_index--)
    {
        if (list_index < SRV_BRW_ADDRESS_LIST_MAX_ITEMS)
        {
            memcpy(
                &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[list_index],
                &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[list_index - 1],
                sizeof(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[list_index]));
            memcpy(
                &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[list_index],
                &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[list_index - 1],
                sizeof(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[list_index]));
        }
    }

    if (title_dcs == SRV_BRW_DCS_UCS)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[0].dcs = SRV_BRW_DCS_UCS;
        memset(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[0].title, 0, NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH);
        mmi_ucs2ncpy(
            (S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[0].title,
            (S8*) title_temp,
            NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH / ENCODING_LENGTH);
    }
    else
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[0].dcs = SRV_BRW_DCS_ASCII;
        memset(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[0].title, 0, NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH);
        mmi_ucs2_n_to_asc(
            (S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[0].title,
            (S8*) title_temp,
            mmi_ucs2strlen((S8*) title_temp) * ENCODING_LENGTH);
    }

    mmi_ucs2_to_asc((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[0].url, (S8*) url_temp);
	return SRV_BRW_ERROR_OK;
}
 

/*****************************************************************************
 * FUNCTION
 *  srv_brw_address_list_delete_all_items
 * DESCRIPTION
 *  Deletes the Browser Address History(Enter address list)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_brw_error_enum srv_brw_address_list_delete_all_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p =
            (nvram_brw_hist_title_struct*) srv_brw_malloc(NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS *
                                                           NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE);
    }
    if(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p =
            (nvram_brw_hist_url_struct*) srv_brw_malloc(NVRAM_BRW_NUM_ADDRESS_HISTORY_URL_RECORDS *
                                                         NVRAM_BRW_ADDRESS_HISTORY_URL_SIZE);
    }
    memset(
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p,
        0,
        NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE * NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS);
    memset(
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p,
        0,
        NVRAM_BRW_ADDRESS_HISTORY_URL_SIZE * NVRAM_BRW_NUM_ADDRESS_HISTORY_URL_RECORDS);

    srv_brw_address_list_update_data(SRV_BRW_LIST_ACTION_UPDATE_ENTIRE_LIST, NULL);

    srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p));
    srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p));

    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items = 0;

	return SRV_BRW_ERROR_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_address_list_get_url
 * DESCRIPTION
 *  returns the URL at the nth index in Browser Address History(Enter address list)
 * PARAMETERS
 *  index -- Item Index for which URL is to be returned
 * RETURNS
 *  URL at the specified index
 *****************************************************************************/
S8 *srv_brw_address_list_get_url (U8 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (index >= SRV_BRW_ADDRESS_LIST_MAX_ITEMS)
    {
        ASSERT(0);
    }
	return (S8*) (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[index].url);
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_address_list_get_title
 * DESCRIPTION
 *  returns the title at the nth index in Browser Address History(Enter address list)
 * PARAMETERS
 *  index -- Item index whose title is to be returned[IN]
	is_ascii -- title is in Ascii, then true else false[OUT]
 * RETURNS
 *  title at the specified index
 *****************************************************************************/
S8 *srv_brw_address_list_get_title (U8 index, U8* is_ucs2)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (index >= SRV_BRW_ADDRESS_LIST_MAX_ITEMS)
    {
        ASSERT(0);
    }
	if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[index].dcs == SRV_BRW_DCS_ASCII)
	{
		*is_ucs2 = 0;
	}
	else
	{
		*is_ucs2 = 1;
	}
	return (S8*)(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[index].title);
}
#endif /* __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */

#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_address_list_find_entry
 * DESCRIPTION
 *  Interface for getting the matched items list,from Address history, 
	corresponding to a given input URL string
 * PARAMETERS
 *  input_str       [IN]     
 * RETURNS
 *  Number of matched items in address history
 *****************************************************************************/
S32 srv_brw_address_list_find_entry(U8 *input_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ip_address;
    MMI_BOOL list_ip_address;
    U8 *search_str1;
    U8 *search_str2;
    U8 temp_str[(SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH];
    U8 temp_str2[(SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH];
    U8 *pos = NULL;
    U16 len;
    S32 num_of_matched_items = 0;
    S32 index;
    S32 add_list_index;
    S32 matched_item_index = 0;
#ifdef __COSMOS_MMI_PACKAGE__
    U8 is_ucs2 = 0;
    U8 title_str[(SRV_BRW_ADDRESS_LIST_TITLE_LENGTH + 1) * ENCODING_LENGTH];
    S8* title_ptr;
#endif
    U8 *temp_input_str = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check the URL string */
    if (!input_str || !g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_items = 0;
        return 0;
    }
    /* Skip the URI scheme */
    pos = (U8*) mmi_ucs2str((const S8*)input_str, (const S8*)L"://");
    if (pos)
    {
        temp_input_str = pos + 3 * ENCODING_LENGTH;
    }

    /* Display the complete address list if input URL host part is empty */
    if (temp_input_str && !mmi_ucs2strlen((S8*) temp_input_str))
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_items = 0;
        for (index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items; index++)
        {
            U8 *temp_pos = NULL;
            mmi_asc_to_ucs2(
                (S8*) temp_str,
                (S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[index].url);
            temp_pos = (U8*) mmi_ucs2str((const S8*)temp_str, (const S8*)input_str);
            if(temp_pos)
            {
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_items_list[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_items++] = index;
            }
        }
        return g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_items;
    }
    else
    {
        if(temp_input_str)
        {
            input_str = temp_input_str;
        }
    }

    /* Check if it is a IP address */
    ip_address = MMI_TRUE;
    len = mmi_ucs2strlen((S8*) input_str);
    mmi_ucs2_to_asc(
        (S8*) temp_str,
        (S8*) input_str);
    for (index = 0; index < len; index++)
    {
        if(temp_str[index] == '/')
        {
            break;
        }
        if(!((temp_str[index] >= 48 && temp_str[index] <= 57) || temp_str[index] == '.' || temp_str[index] == ':'))
        {
            ip_address = MMI_FALSE;
            break;
        }
    }

    /* Search the matched URLs */
    for (index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_address_list_items; index++)
    {
        mmi_asc_to_ucs2(
            (S8*) temp_str,
            (S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[index].url);

        /* Skip the URI scheme and extract & save the URL starting from first part */
        pos = (U8*) mmi_ucs2str((const S8*)temp_str, (const S8*)L"://");
        if (pos)
        {
            search_str1 = pos + 3 * ENCODING_LENGTH;
        }
        else
        {
            search_str1 = NULL;
        }
        /*Check if the address list URL is a IP address*/
        list_ip_address = MMI_TRUE;
        if(ip_address && search_str1)
        {
            len = mmi_ucs2strlen((S8*)search_str1);
            mmi_chset_ucs2_to_utf8_string((U8*) temp_str2, len + 1, (U8*) search_str1);
            for(add_list_index = 0; add_list_index < len; add_list_index++)
            {
                if(temp_str2[add_list_index] == '/')
                {
                    break;
                }
                if(!((temp_str2[add_list_index] >= 48 && temp_str2[add_list_index] <= 57) || temp_str2[add_list_index] == '.' || temp_str2[add_list_index] == ':'))
                {
                    list_ip_address = MMI_FALSE;
                    break;
                }
            }
        }

        /* Skip the URI scheme and extract & save the URL starting from second part if not an IP address */
        if(!(ip_address && list_ip_address) && search_str1)
        {
            pos = (U8*) mmi_ucs2chr((const S8*)search_str1, (U16) '.');
            if (pos)
            {
                search_str2 = pos + ENCODING_LENGTH;
            }
            else
            {
                search_str2 = NULL;
            }
        }
        else
        {
            search_str2 = NULL;
        }
#ifdef __COSMOS_MMI_PACKAGE__
        title_ptr = srv_brw_address_list_get_title(index, &is_ucs2);
        if(is_ucs2)
        {
                mmi_ucs2cpy((S8*) title_str, (S8*) title_ptr);
        }
        else
        {
            mmi_asc_to_ucs2((S8*) title_str,(S8*) title_ptr);
        }
#endif
        /* Compare the input URL with first and second part URL strings */
        if ((search_str1 && !mmi_ucs2nicmp((S8*) search_str1, (S8*) input_str, mmi_ucs2strlen((S8*) input_str))) ||
            (search_str2 && !mmi_ucs2nicmp((S8*) search_str2, (S8*) input_str, mmi_ucs2strlen((S8*) input_str)))
        #ifdef __COSMOS_MMI_PACKAGE__
            ||(!mmi_ucs2nicmp((S8*) title_str, (S8*)input_str, mmi_ucs2strlen((S8*) input_str)))
        #endif
            )
        {
            /* Save the matched URL indices into matched URL list */
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_items_list[matched_item_index++] = index;
            ++num_of_matched_items;
        }
    }

    /* Update the total matched URL number */
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_items = num_of_matched_items;

    return num_of_matched_items;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_address_list_get_matched_item_count
 * DESCRIPTION
 *  API to get the count of matched items in the address list
 * PARAMETERS
 *  void
 * RETURNS
 *  count
 *****************************************************************************/
S32 srv_brw_address_list_get_matched_item_count(void)
{
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p)
    {
        return g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_items;
    }
    else
    {
        return 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_address_list_get_matched_item
 * DESCRIPTION
 *  Item call back function for Matched items list
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 * RETURNS
 *  The matched item URL
 *****************************************************************************/
S8* srv_brw_address_list_get_matched_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((item_index >= 0) && (item_index <= SRV_BRW_ADDRESS_LIST_MAX_ITEMS));
    return (S8*)(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_items_list[item_index]].url);
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_address_list_get_matched_item_title
 * DESCRIPTION
 *  Item call back function for getting the title of Matched items list entry
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 * RETURNS
 *  The matched item Title
 *****************************************************************************/
S8* srv_brw_address_list_get_matched_item_title(S32 item_index, MMI_BOOL *is_ascii)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((item_index >= 0) && (item_index <= SRV_BRW_ADDRESS_LIST_MAX_ITEMS));
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_items_list[item_index]].dcs == SRV_BRW_DCS_ASCII)
    {
        *is_ascii = MMI_TRUE;
    }
    else
    {
        *is_ascii = MMI_FALSE;
    }
    return (S8*)(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_items_list[item_index]].title);

}
#endif /* __MMI_BRW_URL_AUTO_COMPLETION__ */


#ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_read_last_web_address
 * DESCRIPTION
 *  This Interface is used for the reading the last web address
 * PARAMETERS
 *  void
 * RETURNS
 *  Read result of NVRAM
 *****************************************************************************/
S16 srv_brw_read_last_web_address(U8* last_web_address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 NvramError;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(last_web_address);

    ReadRecord(
        NVRAM_EF_BRW_LAST_WEB_ADDR_LID,
        1,
        last_web_address,
        NVRAM_EF_BRW_LAST_WEB_ADDR_SIZE,
        &NvramError);
    return NvramError;
}
#endif /* __MMI_BRW_ADVANCED_APP_FEATURES__ */


/******************Message request interfaces******************************/

/*****************************************************************************
 * FUNCTION
 *  srv_brw_navigation_change_req
 * DESCRIPTION
 *  This Interface is used for requesting change of navigation to BAM
 * PARAMETERS
 *  selectable_items -- updated navigation item ID
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_navigation_change_req (U16 selectable_items)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_navigation_change_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (wap_bam_navigation_change_req_struct*) OslConstructDataPtr(sizeof(wap_bam_navigation_change_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->elements = selectable_items;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_NAVIGATION_CHANGE_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_navigate_req
 * DESCRIPTION
 *  This Interface is used for Requesting Navigation on Rendered page
 * PARAMETERS
 *  direction -- Navigation type
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_navigate_req (U8 direction)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_move_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_move_req_struct*) OslConstructDataPtr(sizeof(wap_bam_move_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->direction = direction;
    myMsgPtr->steps = 1;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_MOVE_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_reload_req
 * DESCRIPTION
 *  This Interface is used for Requesting Reload on Rendered page
 * PARAMETERS
 *  void
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_reload_req(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_reload_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_reload_req_struct*) OslConstructDataPtr(sizeof(wap_bam_reload_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;

#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.launch_type = SRV_BRW_LAUNCH_REFRESH;
#endif
    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_RELOAD_REQ, myMsgPtr, NULL);
    
	return SRV_BRW_ERROR_OK;
}

#ifndef SLIM_WAP_MMS
/*****************************************************************************
 * FUNCTION
 *  srv_brw_activate_do_element_req
 * DESCRIPTION
 *  This Interface is used for Activating a do - element on Rendered page
 * PARAMETERS
 *  item_index -- From do elements list for which action needs to be taken by BAM
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_activate_do_element_req (S32 item_index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_activate_do_element_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (wap_bam_activate_do_element_req_struct*) OslConstructDataPtr(sizeof(wap_bam_activate_do_element_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->element_id = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_list[item_index].element_id;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_ACTIVATE_DO_ELEMENT_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_brw_stop_page_fetching_req
 * DESCRIPTION
 *  This Interface is used for Stop page fetching
 * PARAMETERS
 *  void
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_stop_page_fetching_req (void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_stop_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_stop_req_struct*) OslConstructDataPtr(sizeof(wap_bam_stop_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_STOP_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_background_downloads_req
 * DESCRIPTION
 *  This Interface is used for Requesting background downloads to DL Agent
 * PARAMETERS
 *  notify -- Action command for Download agent
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_background_downloads_req (mmi_da_wap_notify_enum notify)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_da_wap_notify_ind_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (mmi_da_wap_notify_ind_struct*) OslConstructDataPtr(sizeof(mmi_da_wap_notify_ind_struct));
    myMsgPtr->notify = notify;
    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_DA_WAP_NOTIFY_IND, (oslParaType*)myMsgPtr, NULL);
    return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_stored_pages_list_start_req
 * DESCRIPTION
 *  This Interface is used for Requesting Stored pages list
 * PARAMETERS
 *  req_data -- Application filled in request structure
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_get_stored_pages_list_start_req(srv_brw_act_req_struct *req_data)
{
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_saved_pages_list_start_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_save_user_app_req_data(MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_CONTINUE_CNF, req_data);
    myMsgPtr =
        (wap_bam_get_saved_pages_list_start_req_struct*)
        OslConstructDataPtr(sizeof(wap_bam_get_saved_pages_list_start_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;

    srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_SAVED_PAGES_LIST);

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_START_REQ, myMsgPtr, NULL);
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
	return SRV_BRW_ERROR_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_stored_page_req
 * DESCRIPTION
 *  Interface for getting stored page information
 * PARAMETERS
 *  app_data -- Application filled in request structure        
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_get_stored_page_req(srv_brw_act_req_struct *app_data)
{
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_saved_page_req_struct *myMsgPtr;
	srv_brw_list_element_req_struct *ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* showing the busy screen */
    srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p));
    srv_brw_save_user_app_req_data(MSG_ID_WAP_BAM_SAVE_PAGE_CNF, app_data);
    ptr = (srv_brw_list_element_req_struct*)(app_data->req_data);
    myMsgPtr = (wap_bam_get_saved_page_req_struct*) OslConstructDataPtr(sizeof(wap_bam_get_saved_page_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->index = ptr->index;
    g_srv_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_GET_SAVED_PAGE_REQ;
    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_SAVED_PAGE_REQ, myMsgPtr, NULL);
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_save_as_stored_page_req
 * DESCRIPTION
 *  This Interface is used for Requesting to save a page as offline/stored page
 * PARAMETERS
 *  app_data -- Application filled in request structure
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_save_as_stored_page_req(srv_brw_act_req_struct *app_data)
{
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_save_page_req_struct *myMsgPtr;
	srv_brw_stored_page_operation_req_struct *ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_save_user_app_req_data(MSG_ID_WAP_BAM_SAVE_PAGE_CNF, app_data);
    ptr = (srv_brw_stored_page_operation_req_struct*)(app_data->req_data);

    myMsgPtr = (wap_bam_save_page_req_struct*) OslConstructDataPtr(sizeof(wap_bam_save_page_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    mmi_chset_ucs2_to_utf8_string((U8*) myMsgPtr->label, SRV_BRW_MAX_TITLE_LENGTH + 1, (U8*) ptr->page_label);

#ifdef OBIGO_Q03C
    strncpy ((S8*)myMsgPtr->url, (S8*)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url, strlen(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->url));
#endif /* OBIGO_Q03C */
    myMsgPtr->overwrite = MMI_FALSE;
    g_srv_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_SAVE_PAGE_REQ;
    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_SAVE_PAGE_REQ, myMsgPtr, NULL);
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_load_stored_page_req
 * DESCRIPTION
 *  This Interface is used for Requesting to load a stored page at nth index
 * PARAMETERS
 *  index -- Item index of the stored page to load
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_load_stored_page_req(U32 index)
{
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_load_saved_page_req_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    myMsgPtr = (wap_bam_load_saved_page_req_struct*) OslConstructDataPtr(sizeof(wap_bam_load_saved_page_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->index = index;

    g_srv_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_LOAD_SAVED_PAGE_REQ;
#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.launch_type = SRV_BRW_LAUNCH_STORED_PAGE;
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.page_id = index;
#endif

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_LOAD_SAVED_PAGE_REQ, myMsgPtr, NULL);
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_rename_stored_page_req
 * DESCRIPTION
 *  This Interface is used for Requesting rename of a particular stored page
 * PARAMETERS
 *  app_data -- Application filled in request structure
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_rename_stored_page_req(srv_brw_act_req_struct *app_data)
{
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_rename_saved_page_req_struct *myMsgPtr;
	srv_brw_stored_page_operation_req_struct *ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_save_user_app_req_data(MSG_ID_WAP_BAM_SAVE_PAGE_CNF, app_data);
    ptr = (srv_brw_stored_page_operation_req_struct*)(app_data->req_data);

    myMsgPtr =
        (wap_bam_rename_saved_page_req_struct*) OslConstructDataPtr(sizeof(wap_bam_rename_saved_page_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->index = ptr->index;
    mmi_chset_ucs2_to_utf8_string((U8*) myMsgPtr->new_label, SRV_BRW_MAX_TITLE_LENGTH + 1, (U8*) ptr->page_label);

    g_srv_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_RENAME_SAVED_PAGE_REQ;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_RENAME_SAVED_PAGE_REQ, myMsgPtr, NULL);
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_delete_stored_page_req
 * DESCRIPTION
 *  This Interface is used for Requesting deletion of a particular stored page
 * PARAMETERS
 *  app_data -- Application filled in request structure
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_delete_stored_page_req(srv_brw_act_req_struct *app_data)
{
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_delete_saved_page_req_struct *myMsgPtr;
	srv_brw_list_element_req_struct *ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_save_user_app_req_data(MSG_ID_WAP_BAM_SAVE_PAGE_CNF, app_data);
    ptr = (srv_brw_list_element_req_struct*)(app_data->req_data);
    myMsgPtr =
        (wap_bam_delete_saved_page_req_struct*) OslConstructDataPtr(sizeof(wap_bam_delete_saved_page_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->index = ptr->index;

    g_srv_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_DELETE_SAVED_PAGE_REQ;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_DELETE_SAVED_PAGE_REQ, myMsgPtr, NULL);
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_delete_all_stored_pages_req
 * DESCRIPTION
 *  This Interface is used for Requesting deletion of all the stored pages
 * PARAMETERS
 *  app_data -- Application filled in request structure
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_delete_all_stored_pages_req(srv_brw_act_req_struct *app_data)
{
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_delete_all_saved_pages_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_save_user_app_req_data(MSG_ID_WAP_BAM_SAVE_PAGE_CNF, app_data);
    myMsgPtr =
        (wap_bam_delete_all_saved_pages_req_struct*)
        OslConstructDataPtr(sizeof(wap_bam_delete_all_saved_pages_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;

    g_srv_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_DELETE_ALL_SAVED_PAGES_REQ;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_DELETE_ALL_SAVED_PAGES_REQ, myMsgPtr, NULL);
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_stored_pages_list_end_req
 * DESCRIPTION
 *  This Interface is used for Requesting End of Stored pages list
 * PARAMETERS
 *  void
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_stored_pages_list_end_req(void)
{
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_saved_pages_list_end_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (wap_bam_get_saved_pages_list_end_req_struct*)
        OslConstructDataPtr(sizeof(wap_bam_get_saved_pages_list_end_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_SAVED_PAGES_LIST_END_REQ, myMsgPtr, NULL);
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
	return SRV_BRW_ERROR_OK;
}

/***************************Generic***********************************/
/*****************************************************************************
 * FUNCTION
 *  srv_brw_create_instance_req
 * DESCRIPTION
 *  This Interface is used for Requesting background downloads to DL Agent
 * PARAMETERS
 *  app_data -- Application filled in request structure[IN]
	memptr	 -- Pointer to ASM allocated memory [IN]
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_create_instance_req(srv_brw_act_req_struct *app_data, void* memptr)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wap_bam_create_instance_req_struct *myMsgPtr;
	srv_brw_screen_info_struct *ptr;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_save_user_app_req_data(MSG_ID_WAP_BAM_CREATE_INSTANCE_CNF, app_data);
    ptr = (srv_brw_screen_info_struct*)(app_data->req_data);
	myMsgPtr = 
		(wap_bam_create_instance_req_struct*) 
		OslConstructDataPtr(sizeof(wap_bam_create_instance_req_struct));
#ifndef __COSMOS_MMI_PACKAGE__
	g_srv_brw_memory_pool = memptr;
#endif /* #ifdef __COSMOS_MMI_PACKAGE__ */
	MMI_ASSERT(g_srv_brw_memory_pool);
#ifdef OBIGO_Q03C_BROWSER
    wapadp_set_wap_app_mem((void*)((char*)g_srv_brw_memory_pool + SRV_BRW_APP_POOL_SIZE), KAL_FALSE);
#elif OBIGO_Q05A
    setAppMemPool((void*)((char*)g_srv_brw_memory_pool + SRV_BRW_APP_POOL_SIZE));
#endif /* OBIGO_Q05A */
	myMsgPtr->src = MOD_MMI;
    myMsgPtr->is_full_screen = (kal_bool) g_srv_brw_cntx.screen_size_status;
    myMsgPtr->window_position_x = ptr->x;
    myMsgPtr->window_position_y = ptr->y;
    myMsgPtr->window_size_height = ptr->h;
    myMsgPtr->window_size_width = ptr->w;
    myMsgPtr->category_lyr_a_hndl = ptr->title_layer;
    myMsgPtr->category_lyr_b_hndl = ptr->bottom_layer;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_CREATE_INSTANCE_REQ, myMsgPtr, NULL);
    g_srv_brw_cntx.is_create_instance_processing = MMI_TRUE;
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_delete_instance_req
 * DESCRIPTION
 *  This Interface is used for Requesting background downloads to DL Agent
 * PARAMETERS
 *  req_data -- Application filled in request structure[IN]
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_delete_instance_req(srv_brw_act_req_struct *req_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_delete_instance_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_save_user_app_req_data(MSG_ID_WAP_BAM_DELETE_INSTANCE_CNF, req_data);
    myMsgPtr =
        (wap_bam_delete_instance_req_struct*) OslConstructDataPtr(sizeof(wap_bam_delete_instance_req_struct));
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_DELETE_INSTANCE_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_settings_resize_screen_req
 * DESCRIPTION
 *  This Interface is used for Requesting Resize screen request
 * PARAMETERS
 *  scr_info -- Screen info structure to be filled by application
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
#ifdef OBIGO_Q05A
srv_brw_error_enum srv_brw_resize_screen_req(srv_brw_screen_info_struct *scr_info)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	wap_bam_resize_window_req_struct *myMsgPtr;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	myMsgPtr = 
		(wap_bam_resize_window_req_struct*) 
		OslConstructDataPtr(sizeof(wap_bam_resize_window_req_struct));
	myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->is_full_screen = (kal_bool) g_srv_brw_cntx.screen_size_status;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->window_position_x = scr_info->x;
    myMsgPtr->window_position_y = scr_info->y;
    myMsgPtr->window_size_height = scr_info->h;
    myMsgPtr->window_size_width = scr_info->w;
    myMsgPtr->category_lyr_a_hndl = scr_info->title_layer;
    myMsgPtr->category_lyr_b_hndl = scr_info->bottom_layer;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_RESIZE_WINDOW_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}
#endif /* OBIGO_Q05A */

/*****************************************************************************
 * FUNCTION
 *  srv_brw_load_url_req
 * DESCRIPTION
 *  This Interface is used for Requesting URL to load
 * PARAMETERS
 *  url --      URL to load
 * charset      The charset to be used for loading
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_load_url_req(U8 *url, U32 charset)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_load_url_req_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	myMsgPtr = (wap_bam_load_url_req_struct*) OslConstructDataPtr(sizeof(wap_bam_load_url_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->options = WAP_BAM_OPTION_KEEP_WML_CONTEXT;
    myMsgPtr->charset = charset; /* g_srv_brw_cntx.charset_list_p[g_srv_brw_cntx.encoding_method_index].id */
    mmi_chset_ucs2_to_utf8_string((U8*) myMsgPtr->url, sizeof(myMsgPtr->url), (U8*) url);
#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.launch_type = SRV_BRW_LAUNCH_URL;
    if(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.data)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.data = (U8*)srv_brw_malloc((WAP_MAX_SEARCH_URL_LENGTH + 1) * ENCODING_LENGTH);
        memset(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.data, 0,(WAP_MAX_SEARCH_URL_LENGTH + 1) * ENCODING_LENGTH);
    }
    mmi_ucs2cpy((CHAR*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.data, (CHAR*) url);
#endif
    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_LOAD_URL_REQ, myMsgPtr, NULL);

	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_load_data_req
 * DESCRIPTION
 *  This Interface is used for Requesting opening of a file from a given path
 * PARAMETERS
 *  file_path -- From which file needs to be opened
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_load_data_req(U8 *file_path)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_load_data_req_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	myMsgPtr = (wap_bam_load_data_req_struct*) OslConstructDataPtr(sizeof(wap_bam_load_data_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->options = 0;
    myMsgPtr->charset = WAP_BAM_UNKNOWN_CHARSET /* g_srv_brw_cntx.charset_list_p[g_srv_brw_cntx.encoding_method_index].id */ ;
    mmi_chset_ucs2_to_utf8_string
        ((U8*) myMsgPtr->content_path, WAP_BAM_MAX_FILE_PATH_LEN + 1, (U8*) file_path);

#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.launch_type = SRV_BRW_LAUNCH_OPEN_FILE;
    if(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.data)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.data = (U8*)srv_brw_malloc((WAP_MAX_SEARCH_URL_LENGTH + 1) * ENCODING_LENGTH);
        memset(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.data, 0,(WAP_MAX_SEARCH_URL_LENGTH + 1) * ENCODING_LENGTH);
    }
    mmi_ucs2cpy((CHAR*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.data, (CHAR*) file_path);
#endif

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_LOAD_DATA_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}



/**************************Resource***********************/
#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_resource_list_start_req
 * DESCRIPTION
 *  This Interface is used for Requesting Resources list
 * PARAMETERS
 *  app_data -- Application sent request data
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_get_resource_list_start_req(srv_brw_act_req_struct *app_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_resources_list_start_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_save_user_app_req_data(MSG_ID_WAP_BAM_GET_RESOURCES_LIST_CONTINUE_CNF, app_data);
    
    /* de-allocate memory for all page objects */
    //mmi_brw_dynamic_list_free_memory();
    //mmi_brw_this_page_page_objects_free_memory();

    myMsgPtr = (wap_bam_get_resources_list_start_req_struct*)
        OslConstructDataPtr(sizeof(wap_bam_get_resources_list_start_req_struct));
    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_RESOURCES_LIST_START_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_resource_list_end_req
 * DESCRIPTION
 *  This Interface is used for Requesting end of Resources list
 * PARAMETERS
 *  void
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_get_resource_list_end_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_resources_list_end_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (wap_bam_get_resources_list_end_req_struct*)
        OslConstructDataPtr(sizeof(wap_bam_get_resources_list_end_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_RESOURCES_LIST_END_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_resource_req
 * DESCRIPTION
 *  Request function for getting the complete info of a particular resource
 * PARAMETERS
 *  app_data -- Application sent request data
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_get_resource_req(srv_brw_act_req_struct *app_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_resource_req_struct *myMsgPtr;
	srv_brw_list_element_req_struct *ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* showing the busy screen */
    srv_brw_save_user_app_req_data(MSG_ID_WAP_BAM_GET_RESOURCE_CNF, app_data);
    ptr = (srv_brw_list_element_req_struct*)(app_data->req_data);
    
    myMsgPtr = (wap_bam_get_resource_req_struct*) OslConstructDataPtr(sizeof(wap_bam_get_resource_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->index = ptr->index;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_RESOURCE_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_page_objects_get_actual_index
 * DESCRIPTION
 *  This function is used for getting the actual resource list index of a
 *  selected page object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_brw_page_objects_get_actual_index(U16 hilited_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 actual_res_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->selected_page_object_type)
    {
        case SRV_BRW_PAGE_OBJECT_TYPE_IMAGE:
            actual_res_index = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_image_list[hilited_index].res_list_index;
            break;

        case SRV_BRW_PAGE_OBJECT_TYPE_BG_IMAGE:
            actual_res_index = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_bg_image_list[hilited_index].res_list_index;
            break;

        case SRV_BRW_PAGE_OBJECT_TYPE_SOUNDS:
            actual_res_index = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_sound_list[hilited_index].res_list_index;
            break;

        case SRV_BRW_PAGE_OBJECT_TYPE_OTHERS:
            actual_res_index = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_others_list[hilited_index].res_list_index;
            break;

        default:
            actual_res_index = 0;
    }

    return actual_res_index;
}
#endif /* OBIGO_Q05A */

/*****************************************************************************
 * FUNCTION
 *  srv_brw_activate_resource_req
 * DESCRIPTION
 *  This is the request function for viewing the selected rendered page resource
 * PARAMETERS
 *  res_index       [IN]        
 * RETURNS
 *   Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_activate_resource_req(U32 res_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_activate_resource_req_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (wap_bam_activate_resource_req_struct*) OslConstructDataPtr(sizeof(wap_bam_activate_resource_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->index = res_index;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_ACTIVATE_RESOURCE_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}

// #if (defined(OBIGO_Q05A) || defined(__MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__))
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_settings_change_setting_value_req
 * DESCRIPTION
 *  This func is used for changing the setting value
 * PARAMETERS
 *  data_type       [IN]        
 *  setting_id      [IN]        
 *  value_i         [IN]        
 *  value_bv        [IN]        
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_change_setting_value_req(U8 data_type, U32 setting_id, U32 value_i, U8 *value_bv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_change_setting_value_req_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (wap_bam_change_setting_value_req_struct*)
        OslConstructDataPtr(sizeof(wap_bam_change_setting_value_req_struct));
    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->type = data_type;
    myMsgPtr->setting_id = setting_id;
    myMsgPtr->value_i = value_i;
    if (value_bv)
    {
        mmi_chset_ucs2_to_utf8_string(
            (U8*) myMsgPtr->value_bv,
            WAP_BAM_MAX_SETTING_STR_VALUE_LEN + 1,
            (U8*)value_bv);
    }

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_CHANGE_SETTING_VALUE_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}
// #endif /* (defined(OBIGO_Q05A) || defined(__MMI_WAP_9W_NAVIGATION_KBRD_SIMULATION__)) */

/*****************************************************************************
 * FUNCTION
 *  srv_brw_set_profile_req
 * DESCRIPTION
 *  This Interface is used for sending the set profile req to BAM
 * PARAMETERS
 *  ptr -- profile structure containing the profile information to be sent
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_set_profile_req(srv_brw_set_profile_req_struct *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_set_profile_req_struct *myMsgPtr;
    U8 current_hmpage[(SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH];
    U32 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_set_profile_req_struct *) OslConstructDataPtr(sizeof(wap_bam_set_profile_req_struct));
    myMsgPtr->profile = (wap_bam_profile_setting_t *) OslMalloc(sizeof(wap_bam_profile_setting_t));
    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->request_id = 0;

    memset(myMsgPtr->profile->int_value_table, -1, wap_bam_setting_id_total * sizeof(kal_int32));
    memset(myMsgPtr->profile->str_value_table, 0, wap_bam_setting_id_total * sizeof(char *));

    mmi_asc_to_ucs2((S8 *) current_hmpage, (S8 *) ptr->currprof->url);

    myMsgPtr->profile->int_value_table[wap_bam_setting_id_images] = g_srv_brw_cntx.show_images_status;
#ifdef OBIGO_Q05A
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_movies] = g_srv_brw_cntx.show_videos_status;
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_sounds] = g_srv_brw_cntx.play_sounds_status;
#endif /* OBIGO_Q05A */
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_history] = SRV_BRW_RECENT_PAGES_COUNT;
#endif
#ifdef BRW_KEYPAD_SHORTCUTS_SUPPORT
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_shortcuts] = g_srv_brw_cntx.shortcuts_status;
#endif 

#ifdef OBIGO_Q05A
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_rendering] = g_srv_brw_cntx.rendering_mode;
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_thumbnail] = g_srv_brw_cntx.thumbnail_status;
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_css] = g_srv_brw_cntx.css_status;
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_script] = g_srv_brw_cntx.script_status;
#endif /* OBIGO_Q05A */
#ifdef __COSMOS_MMI_PACKAGE__
	if(g_srv_brw_cntx.private_mode_setting)
		myMsgPtr->profile->int_value_table[wap_bam_setting_id_cache] = wap_bam_setting_val_cache_disable;
	else
		myMsgPtr->profile->int_value_table[wap_bam_setting_id_cache] = g_srv_brw_cntx.cache_status;
#else
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_cache] = g_srv_brw_cntx.cache_status;
#endif /* __COSMOS_MMI_PACKAGE__ */

#ifdef OBIGO_Q05A
#ifdef BRW_SECURITY_WARNINGS_SUPPORT
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_sec_warning] = g_srv_brw_cntx.security_warnings_status;
#endif 
#ifdef BRW_SEND_DEVICE_ID_SUPPORT
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_imei] = g_srv_brw_cntx.send_device_id_status;
#endif 
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_no_mime] = g_srv_brw_cntx.load_unknown_media_status;
#ifdef __MMI_VECTOR_FONT_SUPPORT__
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_font_size] = g_srv_brw_cntx.font_size;
#else
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_font_size] = WAP_CUSTOM_CFG_DEFAULT_FONT_SIZE;
#endif 
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_navigation] = g_srv_brw_cntx.navigation_mode;
#endif /* OBIGO_Q05A */
#ifdef __COSMOS_MMI_PACKAGE__
	if(g_srv_brw_cntx.private_mode_setting)
		myMsgPtr->profile->int_value_table[wap_bam_setting_id_cookies] = wap_bam_setting_val_cookies_disable;
	else
		myMsgPtr->profile->int_value_table[wap_bam_setting_id_cookies] = g_srv_brw_cntx.cookie_status;
#else
	myMsgPtr->profile->int_value_table[wap_bam_setting_id_cookies] = g_srv_brw_cntx.cookie_status;
#endif /* __COSMOS_MMI_PACKAGE__ */
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_con_account] = ptr->currprof->data_account_primary_id;
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_con_addr_type] = wap_bam_setting_val_conn_addr_type_ipv4;
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_con_port] = ptr->currprof->proxy_port;
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_con_timeout] = g_srv_brw_cntx.timeout_value;

    switch (ptr->currprof->conn_type)
    {
        case SRV_WAP_PROF_CONN_TYPE_HTTP:
        {
            myMsgPtr->profile->int_value_table[wap_bam_setting_id_con_type] = wap_bam_setting_val_conn_type_http;
#ifdef __BAIDU_TRANSCODING_SUPPORT__
            g_srv_brw_cntx.is_http_conn = 1;
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
            break;
        }
        case SRV_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED:
        {
            myMsgPtr->profile->int_value_table[wap_bam_setting_id_con_type] =
                wap_bam_setting_val_conn_type_connection_oreinted;
#ifdef __BAIDU_TRANSCODING_SUPPORT__
            g_srv_brw_cntx.is_http_conn = 0;
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
            break;
        }
        case SRV_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE:
        {
            myMsgPtr->profile->int_value_table[wap_bam_setting_id_con_type] =
                wap_bam_setting_val_conn_type_connection_oreinted_secure;
#ifdef __BAIDU_TRANSCODING_SUPPORT__
            g_srv_brw_cntx.is_http_conn = 0;
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
            break;
        }
        default:
            MMI_ASSERT(0);
    }
#ifdef __BAIDU_TRANSCODING_SUPPORT__
    if(g_srv_brw_cntx.is_http_conn)
        myMsgPtr->profile->int_value_table[wap_bam_setting_id_transcode_proxy] = g_srv_brw_cntx.baidu_proxy_status;
    else
        myMsgPtr->profile->int_value_table[wap_bam_setting_id_transcode_proxy] = 0;
#endif // #ifdef __BAIDU_TRANSCODING_SUPPORT__
    if (mmi_ucs2strlen((S8 *) current_hmpage))
    {
        length = (mmi_ucs2strlen((S8 *) current_hmpage) + 1) * ENCODING_LENGTH;
        myMsgPtr->profile->str_value_table[wap_bam_setting_id_homepage] = OslMalloc(length * sizeof(U8));
        mmi_chset_ucs2_to_utf8_string((U8 *) myMsgPtr->profile->str_value_table[wap_bam_setting_id_homepage],
                                      length, (U8 *) current_hmpage);
    }
    else
    {
        myMsgPtr->profile->str_value_table[wap_bam_setting_id_homepage] = NULL;
    }

    /* Proxy IP */
#ifdef __SAT__
    if ((g_srv_brw_cntx.srv_brw_profile_type == SRV_BRW_PROFILE_TYPE_SAT) && g_srv_brw_cntx.sat_gateway_ascii)
    {
        length = strlen((const char *)g_srv_brw_cntx.sat_gateway_ascii) + 1;
        myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_addr] = OslMalloc(length * sizeof(U8));
        strcpy((char *)myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_addr], (const char *)g_srv_brw_cntx.sat_gateway_ascii);
    }
    else
#endif /* __SAT__ */ 
    {
        length = strlen((const char *)ptr->currprof->proxy_ip) + 1;
        myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_addr] = OslMalloc(length * sizeof(U8));
        strcpy((char *)myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_addr], (const char *)ptr->currprof->proxy_ip);
    }

    if (strlen((S8 *) ptr->currprof->password))
    {
        length = strlen((S8 *) ptr->currprof->password) + 1;
        myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_pwd] = OslMalloc(length * sizeof(U8));
        strcpy((S8 *) myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_pwd], (S8 *) ptr->currprof->password);
    }
    else
    {
        myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_pwd] = NULL;
    }

    if (strlen((S8 *) ptr->currprof->username))
    {
        length = strlen((S8 *) ptr->currprof->username) + 1;
        myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_user] = OslMalloc(length * sizeof(U8));
        strcpy((S8 *) myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_user], (S8 *) ptr->currprof->username);
    }
    else
    {
        myMsgPtr->profile->str_value_table[wap_bam_setting_id_con_user] = NULL;
    }
#ifdef OBIGO_Q03C
	myMsgPtr->setting_id = ptr->setting_id;
#endif /* OBIGO_Q03C */
#ifdef __COSMOS_MMI_PACKAGE__
	if(g_srv_brw_cntx.private_mode_setting)
		myMsgPtr->profile->int_value_table[wap_bam_setting_id_add_history] = 0;
	else
		myMsgPtr->profile->int_value_table[wap_bam_setting_id_add_history] = g_srv_brw_cntx.history_setting;
#else
    myMsgPtr->profile->int_value_table[wap_bam_setting_id_add_history] = 1;
#endif
    myMsgPtr->type = ptr->type;
    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_SET_PROFILE_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_set_profile_req_by_data
 * DESCRIPTION
 *  This Interface is used for setting profile content data req to BAM
 * PARAMETERS
 *  app_data -- Application sent request data
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_set_profile_req_by_data(srv_brw_act_req_struct *app_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_set_profile_req_struct *ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_save_user_app_req_data(MSG_ID_WAP_BAM_SET_PROFILE_CNF, app_data);
    ptr = (srv_brw_set_profile_req_struct*)(app_data->req_data);
    return (srv_brw_set_profile_req(ptr));
}

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_recent_pages_list_start_req
 * DESCRIPTION
 *  This Interface is used for Requesting recent pages list to BAM
 * PARAMETERS
 *  app_data -- Application sent request data
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_get_recent_pages_list_start_req(srv_brw_act_req_struct *req_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_recent_pages_list_start_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_save_user_app_req_data(MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_CONTINUE_CNF, req_data);
	myMsgPtr =
        (wap_bam_get_recent_pages_list_start_req_struct*)
        OslConstructDataPtr(sizeof(wap_bam_get_recent_pages_list_start_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;

#ifdef OBIGO_Q05A
    myMsgPtr->sort_option = g_srv_brw_cntx.sorting_method;
#endif /* OBIGO_Q05A */

    //srv_brw_dynamic_list_free_memory();
    //srv_brw_recent_pages_free_memory();

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_START_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_recent_pages_list_end_req
 * DESCRIPTION
 *  This Interface is used for Requesting end to recent pages list
 * PARAMETERS
 *  void
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_recent_pages_list_end_req(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_recent_pages_list_end_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (wap_bam_get_recent_pages_list_end_req_struct*)
        OslConstructDataPtr(sizeof(wap_bam_get_recent_pages_list_end_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_RECENT_PAGES_LIST_END_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_recent_page_req
 * DESCRIPTION
 *  This Interface is used for Requesting information for a selected recent page
 * PARAMETERS
 *  app_data -- Application sent request data
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_get_recent_page_req(srv_brw_act_req_struct *app_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_get_recent_page_req_struct *myMsgPtr;
	srv_brw_list_element_req_struct *ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_save_user_app_req_data(MSG_ID_WAP_BAM_RECENT_PAGE_CNF, app_data);
    ptr = (srv_brw_list_element_req_struct*)(app_data->req_data);
    
    myMsgPtr = (wap_bam_get_recent_page_req_struct*) OslConstructDataPtr(sizeof(wap_bam_get_recent_page_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->index = ptr->index;

    g_srv_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_GET_RECENT_PAGE_REQ;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_GET_RECENT_PAGE_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_load_recent_page_req
 * DESCRIPTION
 *  This function is an interface to load a recent page at given index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_load_recent_page_req(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_load_recent_page_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_load_recent_page_req_struct*) OslConstructDataPtr(sizeof(wap_bam_load_recent_page_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->index = index;
    myMsgPtr->charset = WAP_BAM_UNKNOWN_CHARSET /* g_srv_brw_cntx.charset_list_p[g_srv_brw_cntx.encoding_method_index].id */ ;
#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.launch_type = SRV_BRW_LAUNCH_RECENT_PAGE;
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.page_id = index;
#endif

    g_srv_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_LOAD_RECENT_PAGE_REQ;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_LOAD_RECENT_PAGE_REQ, myMsgPtr, NULL);
}


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  srv_brw_delete_recent_host_req
 * DESCRIPTION
 *  This Interface is used for Requesting deletion of a particular recent page
 * host(i.e. to delete all the recent pages under a host)
 * PARAMETERS
 *  app_data -- Application sent request data
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_delete_recent_host_req(U8 selected_host_index, srv_brw_rsp_funcptr_type rsp_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    U8 *strSelectedHost;
    srv_brw_act_req_struct obj = {0};
    srv_brw_list_element_req_struct data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strSelectedHost = (U8*) srv_brw_malloc(1000);
    memset(strSelectedHost, 0, 1000);

    strcpy((S8*) strSelectedHost, (S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_list[selected_host_index]);
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_delete_count = 0;

    /* creating the recent page list that has to be deleted corresponding to the selected host */
    for (index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count; index++)
    {
        if (!strcmp((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].host, (S8*) strSelectedHost))
        {
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_list[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_delete_count++].actual_index = index;
        }
    }
    srv_brw_free(strSelectedHost);
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_delete_callback = rsp_callback;

    /* sending the request to delete the first page in the list */
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_delete_count > 0)
    {
        obj.rsp_callback = srv_brw_recent_page_host_delete_callback;
        data.index = srv_brw_recent_page_get_actual_index(--g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_delete_count);
        obj.req_data = (void*)&data;
        srv_brw_delete_recent_page_req(&obj);
        return SRV_BRW_ERROR_OK;
    }
	return SRV_BRW_ERROR;

}
#endif /* OBIGO_Q05A */


/*****************************************************************************
 * FUNCTION
 *  srv_brw_delete_recent_page_req
 * DESCRIPTION
 *  This Interface is used for Requesting deletion of a particular recent page
 * PARAMETERS
 *  app_data -- Application sent request data
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_delete_recent_page_req(srv_brw_act_req_struct *app_data)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_delete_recent_page_req_struct *myMsgPtr;
	srv_brw_list_element_req_struct *ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_save_user_app_req_data(MSG_ID_WAP_BAM_RECENT_PAGE_CNF, app_data);
    ptr = (srv_brw_list_element_req_struct*)(app_data->req_data);
    myMsgPtr =
        (wap_bam_delete_recent_page_req_struct*) OslConstructDataPtr(sizeof(wap_bam_delete_recent_page_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->index = ptr->index;

    g_srv_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_DELETE_RECENT_PAGE_REQ;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_DELETE_RECENT_PAGE_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}



/*****************************************************************************
 * FUNCTION
 *  srv_brw_delete_all_recent_pages_req
 * DESCRIPTION
 *  This Interface is used for Requesting deletion of all recent pages
 * PARAMETERS
 *  app_data -- Application sent request data
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_delete_all_recent_pages_req(srv_brw_act_req_struct *app_data)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_delete_all_recent_pages_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_save_user_app_req_data(MSG_ID_WAP_BAM_RECENT_PAGE_CNF, app_data);
    myMsgPtr =
        (wap_bam_delete_all_recent_pages_req_struct*)
        OslConstructDataPtr(sizeof(wap_bam_delete_all_recent_pages_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;

    g_srv_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_DELETE_ALL_SAVED_PAGES_REQ;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_DELETE_ALL_RECENT_PAGES_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_brw_handle_pen_event_req
 * DESCRIPTION
 *  This is the request function for pen event on the rendered page
 * PARAMETERS
 *  point           [IN]        
 *  event_type      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_brw_error_enum srv_brw_handle_pen_event_req(mmi_pen_point_struct point, mmi_pen_event_type_enum event_type)
{
#ifdef __MMI_TOUCH_SCREEN__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q03C
 bam_handle_pen_event_ext(
                g_srv_brw_cntx.brw_instance_id,
                point.x,
                point.y,
                event_type);
#else /* OBIGO_Q03C */
    wap_bam_handle_pen_event_req_struct *myMsgPtr;
    myMsgPtr = (wap_bam_handle_pen_event_req_struct*) OslConstructDataPtr(sizeof(wap_bam_handle_pen_event_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->pos_x = point.x;
    myMsgPtr->pos_y = point.y;
    myMsgPtr->type = event_type;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_HANDLE_PEN_EVENT_REQ, myMsgPtr, NULL);
    
#endif /* OBIGO_Q03C */    
#endif /*__MMI_TOUCH_SCREEN__ */
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_ren_page_object_action_req
 * DESCRIPTION
 *  This is the generic request function to take some action on the selected
 *  rendered page item
 * PARAMETERS
 *  sel_obj_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_brw_error_enum srv_brw_ren_page_object_action_req(U16 sel_obj_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_object_action_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_object_action_req_struct*) OslConstructDataPtr(sizeof(wap_bam_object_action_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->type = sel_obj_type;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_OBJECT_ACTION_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_select_file_rsp
 * DESCRIPTION
 *  Response function for the select file indication
 * PARAMETERS
 *  select_file_result      [IN]        
 *  file_path               [?]         
 *  options(?)              [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
srv_brw_error_enum srv_brw_select_file_rsp(U16 select_file_result, U8 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_select_file_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_SELECT_FILE_RSP, select_file_result);
    myMsgPtr = (wap_bam_select_file_rsp_struct*) OslConstructDataPtr(sizeof(wap_bam_select_file_rsp_struct));

    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->request_id = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->sap_request_id;
    myMsgPtr->error_code = select_file_result;
    if (file_path)
    {
        mmi_chset_ucs2_to_utf8_string((U8*) myMsgPtr->filename, WAP_BAM_MAX_FULL_FILENAME_LEN, (U8*) file_path);
    }

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_SELECT_FILE_RSP, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_recent_pages_list_get_item
 * DESCRIPTION
 *  Item call back function for dynamic list of recent pages
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 * RETURNS
 *  void
 *****************************************************************************/
U8* srv_brw_recent_pages_list_get_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_list[item_index].actual_index].name);
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_create_recent_page_list
 * DESCRIPTION
 *  This function is to map the recent page list index to actual indexes in the
 * dynamic_list 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_create_recent_page_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count; index++)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_list[index].actual_index = index;
    }
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_count = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count;
}


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  srv_brw_create_recent_page_list_for_selected_host
 * DESCRIPTION
 *  This fucntion is for creating a list of recent pages present under the 
 * host selected by the user in the host list screen to be displayed in the
 * recent page list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_create_recent_page_list_for_selected_host(U16 selected_host)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    U8 *strSelectedHost;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strSelectedHost = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_list[selected_host];
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_count = 0;

    for (index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count; index++)
    {
        if (!strcmp((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].host, (S8*) strSelectedHost))
        {
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_list[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_count++].actual_index = index;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_create_recent_page_host_list
 * DESCRIPTION
 *  This function is to create a list of the different recent page hosts before
 * displaying the hosts in the recent page host list screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_create_recent_page_host_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    U32 host_index;
    MMI_BOOL isHostAlreadyAdded;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_list = srv_brw_malloc(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count * sizeof(U32));

    for (index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count; index++)
    {
        isHostAlreadyAdded = MMI_FALSE;
        for (host_index = 0; host_index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_count; host_index++)
        {
            if (!strcmp
                ((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_list[host_index], (S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].host))
            {
                isHostAlreadyAdded = MMI_TRUE;
                break;
            }
        }
        if (!isHostAlreadyAdded)
        {
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_list[host_index] = srv_brw_malloc((strlen((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].host) + 1) * sizeof(U8));
            strcpy(
                (S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_list[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_count++],
                (S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].host);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_recent_pages_host_list_get_item
 * DESCRIPTION
 *  Item call back function for dynamic list of recent pages
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 *  str_buff            [IN]        Buffer to be shown
 *  img_buff_p          [IN]        Image to be shown
 *  str_img_mask        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8* srv_brw_recent_pages_host_list_get_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_list[item_index]);
}
#endif /* OBIGO_Q05A */
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_brw_stored_pages_list_get_item
 * DESCRIPTION
 *  Item call back function for dynamic list of Stored pages
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 * RETURNS
 *  void
 *****************************************************************************/
U8* srv_brw_stored_pages_list_get_item(S32 item_index)
{
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_pages_list_p[item_index].name);
#else
    return NULL;
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_trusted_certificate_list_get_item
 * DESCRIPTION
 *  Item call back function for dynamic list of Trusted certificates
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 * RETURNS
 *  void
 *****************************************************************************/
U8* srv_brw_trusted_certificate_list_get_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[item_index].name);
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_settings_clear_data_req
 * DESCRIPTION
 *  This func is used for sending clear data request to WPS
 * PARAMETERS
 *  operation       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_settings_clear_data_req(srv_brw_act_req_struct *app_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_clear_req_struct *myMsgPtr;
	srv_brw_list_element_req_struct	*ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler(srv_brw_settings_clear_data_rsp, MSG_ID_WPS_CLEAR_RSP);
    srv_brw_save_user_app_req_data(MSG_ID_WPS_CLEAR_RSP, app_data);
    ptr = (srv_brw_list_element_req_struct*)(app_data->req_data);
    myMsgPtr = (wps_clear_req_struct*) OslConstructDataPtr(sizeof(wps_clear_req_struct));
    myMsgPtr->channel_id = 0;
    myMsgPtr->request_id = 0;
    myMsgPtr->operation = ptr->index;

    srv_brw_event_hdlr_send_ilm_to_wps(MSG_ID_WPS_CLEAR_REQ, myMsgPtr, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_trusted_certificates_delete_req
 * DESCRIPTION
 *  This func is used to send delete request of selected trusted certificate
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_trusted_certificates_delete_req(srv_brw_act_req_struct *app_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_delete_ca_cert_req_struct *myMsgPtr;
	srv_brw_list_element_req_struct	*ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_save_user_app_req_data(MSG_ID_WPS_SEC_DELETE_CA_CERT_RSP, app_data);
    ptr = (srv_brw_list_element_req_struct*)(app_data->req_data);
    myMsgPtr = (wps_sec_delete_ca_cert_req_struct*) OslConstructDataPtr(sizeof(wps_sec_delete_ca_cert_req_struct));
    myMsgPtr->idx = ptr->index;

    srv_brw_event_hdlr_send_ilm_to_wps(MSG_ID_WPS_SEC_DELETE_CA_CERT_REQ, myMsgPtr, NULL);
}
/*****************************************************************************
 * FUNCTION
 *  srv_brw_post_event_callback
 * DESCRIPTION
 *  The callback function after post event is done
 *  Including action response, action notify and confirm indication
 * PARAMETERS
 *  result_evt:        [IN]        result structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_brw_post_event_callback(mmi_post_result_event_struct *result_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (result_evt->user_data != NULL)
    {
        OslMfree(result_evt->user_data);
        result_evt->user_data = NULL;
    }

    return MMI_RET_OK;
}
#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_trusted_certificate_ids_req
 * DESCRIPTION
 *  This func is used for requesting the ID's of trusted certificates
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_trusted_certificate_ids_req(srv_brw_act_req_struct *app_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_cert_ids_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* showing the busy screen */
    srv_brw_save_user_app_req_data(MSG_ID_WPS_SEC_GET_CERT_IDS_RSP, app_data);

    myMsgPtr = (wps_sec_get_cert_ids_req_struct*) OslConstructDataPtr(sizeof(wps_sec_get_cert_ids_req_struct));
    myMsgPtr->cert_options = WPS_SEC_GET_ROOT_CERT;

    srv_brw_event_hdlr_send_ilm_to_wps(MSG_ID_WPS_SEC_GET_CERT_IDS_REQ, myMsgPtr, NULL);
}
/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_trusted_certificate_req
 * DESCRIPTION
 *  This func is used for sending request to get a particular certificate
 * PARAMETERS
 *  cert_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_trusted_certificate_req(srv_brw_act_req_struct *app_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_cert_req_struct *myMsgPtr;
	srv_brw_list_element_req_struct	*ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_save_user_app_req_data(MSG_ID_WPS_SEC_GET_CERT_RSP, app_data);
    ptr = (srv_brw_list_element_req_struct*)(app_data->req_data);
    myMsgPtr = (wps_sec_get_cert_req_struct*) OslConstructDataPtr(sizeof(wps_sec_get_cert_req_struct));
    myMsgPtr->cert_id = (U32)ptr->index;

    /* saving the ID of requested certificate */
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->req_cert_id = ptr->index;

    srv_brw_event_hdlr_send_ilm_to_wps(MSG_ID_WPS_SEC_GET_CERT_REQ, myMsgPtr, NULL);
}
#endif /* WAP_SEC_SUPPORT */
#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_session_info_req
 * DESCRIPTION
 *  This func is used for requesting session information
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_session_info_req(srv_brw_act_req_struct *app_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_session_info_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_save_user_app_req_data(MSG_ID_WPS_SEC_GET_SESSION_INFO_RSP, app_data);
    myMsgPtr = (wps_sec_get_session_info_req_struct*) OslConstructDataPtr(sizeof(wps_sec_get_session_info_req_struct));

    myMsgPtr->channel_id = 0;
    srv_brw_event_hdlr_send_ilm_to_wps(MSG_ID_WPS_SEC_GET_SESSION_INFO_REQ, myMsgPtr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_current_certificate_req
 * DESCRIPTION
 *  This func is used for requesting info of current certificate
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_current_certificate_req(srv_brw_act_req_struct *app_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_sec_get_current_cert_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    srv_brw_save_user_app_req_data(MSG_ID_WPS_SEC_GET_CURRENT_CERT_RSP, app_data);
    myMsgPtr = (wps_sec_get_current_cert_req_struct*) OslConstructDataPtr(sizeof(wps_sec_get_current_cert_req_struct));
    myMsgPtr->channel_id = 0;

    srv_brw_event_hdlr_send_ilm_to_wps(MSG_ID_WPS_SEC_GET_CURRENT_CERT_REQ, myMsgPtr, NULL);
}
#endif /* OBIGO_Q05A */


/*****************************************************************************
 * FUNCTION
 *  srv_brw_convert_sim_setting_to_profile_sim_id
 * DESCRIPTION
 *  This function is to convert the sim setting to the corresponding profile
 * SIM Id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_wap_prof_sim_id_enum srv_brw_convert_sim_setting_to_profile_sim_id(srv_brw_active_sim_setting_enum sim_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_setting)
    {
        case SRV_BRW_ACTIVE_SIM_SETTING_SIM1:
        {
            return SRV_WAP_PROF_SIMID_SIM1;
        }
#if (MMI_MAX_SIM_NUM >= 2)
        case SRV_BRW_ACTIVE_SIM_SETTING_SIM2:
        {
            return SRV_WAP_PROF_SIMID_SIM2;
        }

#endif /* (MMI_MAX_SIM_NUM >= 2) */
#if (MMI_MAX_SIM_NUM >= 3)
        case SRV_BRW_ACTIVE_SIM_SETTING_SIM3:
        {
            return SRV_WAP_PROF_SIMID_SIM3;
        }
#endif /* (MMI_MAX_SIM_NUM >= 3) */

#if (MMI_MAX_SIM_NUM >= 4)
        case SRV_BRW_ACTIVE_SIM_SETTING_SIM4:
        {
            return SRV_WAP_PROF_SIMID_SIM4;
        }
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#ifdef __MMI_WLAN_FEATURES__
        case SRV_BRW_ACTIVE_SIM_SETTING_WLAN:
        {
            return SRV_WAP_PROF_SIMID_WLAN;
        }
#endif /* __MMI_WLAN_FEATURES__ */

        default:
        {
            return SRV_WAP_PROF_SIMID_SIM1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_convert_profile_sim_id_to_sim_setting
 * DESCRIPTION
 *  This function is to convert the profile SIM Id to corresponding sim setting 
 * in Browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_brw_active_sim_setting_enum srv_brw_convert_profile_sim_id_to_sim_setting(srv_wap_prof_sim_id_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {
        case SRV_WAP_PROF_SIMID_SIM1:
        {
            return SRV_BRW_ACTIVE_SIM_SETTING_SIM1;
        }
#if (MMI_MAX_SIM_NUM >= 2)
        case SRV_WAP_PROF_SIMID_SIM2:
        {
            return SRV_BRW_ACTIVE_SIM_SETTING_SIM2;
        }

#endif /* (MMI_MAX_SIM_NUM >= 2) */
#if (MMI_MAX_SIM_NUM >= 3)
        case SRV_WAP_PROF_SIMID_SIM3:
        {
            return SRV_BRW_ACTIVE_SIM_SETTING_SIM3;
        }
#endif /* (MMI_MAX_SIM_NUM >= 3) */

#if (MMI_MAX_SIM_NUM >= 4)
        case SRV_WAP_PROF_SIMID_SIM4:
        {
            return SRV_BRW_ACTIVE_SIM_SETTING_SIM4;
        }
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#ifdef __MMI_WLAN_FEATURES__
        case SRV_WAP_PROF_SIMID_WLAN:
        {
            return SRV_BRW_ACTIVE_SIM_SETTING_WLAN;
        }
#endif /* __MMI_WLAN_FEATURES__ */
        default:
        {
            return SRV_BRW_ACTIVE_SIM_SETTING_SIM1;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_convert_sim_setting_to_browser_sim_id
 * DESCRIPTION
 *  This function is to convert the sim setting to the corresponding Browser
 * global SIM setting
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_brw_sim_id_enum srv_brw_convert_sim_setting_to_browser_sim_id(srv_brw_active_sim_setting_enum sim_setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_setting)
    {
        case SRV_BRW_ACTIVE_SIM_SETTING_SIM1:
        {
            return MMI_BRW_SIM_ID_SIM1;
        }
#if (MMI_MAX_SIM_NUM >= 2)
        case SRV_BRW_ACTIVE_SIM_SETTING_SIM2:
        {
            return MMI_BRW_SIM_ID_SIM2;
        }

#ifdef __MMI_WLAN_FEATURES__
        case SRV_BRW_ACTIVE_SIM_SETTING_WLAN:
        {
            return MMI_BRW_SIM_ID_WLAN;
        }
#endif /* __MMI_WLAN_FEATURES__ */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
#if (MMI_MAX_SIM_NUM >= 3)
        case SRV_BRW_ACTIVE_SIM_SETTING_SIM3:
        {
            return MMI_BRW_SIM_ID_SIM3;
        }
#endif /* (MMI_MAX_SIM_NUM >= 3) */

#if (MMI_MAX_SIM_NUM >= 4)
        case SRV_BRW_ACTIVE_SIM_SETTING_SIM4:
        {
            return MMI_BRW_SIM_ID_SIM4;
        }
#endif /* (MMI_MAX_SIM_NUM >= 4) */
        default:
        {
            return MMI_BRW_SIM_ID_SIM1;
        }
    }
}


#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_recent_page_get_actual_index
 * DESCRIPTION
 *  This function is to provide the actual recent page index for the recent page
 * currently highlighted
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_brw_recent_page_get_actual_index(U32 highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_list[highlighted_item].actual_index;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_brw_is_backward_navigation
 * DESCRIPTION
 *  This function is used for checking the backward status of the page navigation
 *  list
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : If a page exists before the current page in the page navigation list
 *  MMI_FALSE : otherwise
 *****************************************************************************/
MMI_BOOL srv_brw_is_backward_navigation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p)
    {
        if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->flags & WAP_BAM_INFO_FLAG_ENABLE_BACK)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_is_forward_navigation
 * DESCRIPTION
 *  This function is used for checking the forward status of the page navigation
 *  list
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : If a page exists next to the current page in the page navigation list
 *  MMI_FALSE : otherwise
 *****************************************************************************/
MMI_BOOL srv_brw_is_forward_navigation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p)
    {
        if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->flags & WAP_BAM_INFO_FLAG_ENABLE_FORWARD)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

#ifdef OBIGO_Q03C
/*****************************************************************************
 * FUNCTION
 *  srv_brw_clear_focused_element
 * DESCRIPTION
 *  This function is used for reset of focused element structure
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : If a page exists next to the current page in the page navigation list
 *  MMI_FALSE : otherwise
 *****************************************************************************/
void srv_brw_clear_focused_element(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p)
    {
        memset(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p, 0, sizeof(srv_brw_element_focused_ind_struct));
    }
}
#endif /* OBIGO_Q03C */

/*****************************************************************************
 * FUNCTION
 *  srv_brw_convert_dtcnt_sim_id_to_sim_setting
 * DESCRIPTION
 *  This function is to convert the dtcnt SIM Id to corresponding sim setting 
 * in Browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_brw_active_sim_setting_enum srv_brw_convert_dtcnt_sim_id_to_sim_setting(srv_dtcnt_sim_type_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {
        case SRV_DTCNT_SIM_TYPE_1:
        {
            return SRV_BRW_ACTIVE_SIM_SETTING_SIM1;
        }
#if (MMI_MAX_SIM_NUM >= 2)
        case SRV_DTCNT_SIM_TYPE_2:
        {
            return SRV_BRW_ACTIVE_SIM_SETTING_SIM2;
        }
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        case SRV_DTCNT_SIM_TYPE_3:
        {
            return SRV_BRW_ACTIVE_SIM_SETTING_SIM3;
        }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        case SRV_DTCNT_SIM_TYPE_4:
        {
            return SRV_BRW_ACTIVE_SIM_SETTING_SIM4;
        }
#endif
        default:
        {
            return SRV_BRW_ACTIVE_SIM_SETTING_SIM1;
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_brw_sim_preference_update_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 * RETURNS
 *  0.
 *****************************************************************************/
mmi_ret srv_brw_sim_preference_update_handler(mmi_event_struct *evt) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_sim_preference_update_ind_evt_struct *sim_preference = (srv_dtcnt_sim_preference_update_ind_evt_struct*) evt;
    srv_brw_active_sim_setting_enum dtcnt_sim_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dtcnt_sim_id = srv_brw_convert_dtcnt_sim_id_to_sim_setting(sim_preference->sim_id);
    g_srv_brw_cntx.session_sim_id = dtcnt_sim_id;
    srv_brw_set_profile_content();
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_init
 * DESCRIPTION
 *  To Initialize Browser app. Service at Boot up
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : If a page exists next to the current page in the page navigation list
 *  MMI_FALSE : otherwise
 *****************************************************************************/
void srv_brw_init(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* Initializing service global context */
	srv_brw_global_context_init();
	/* Registering all the ILM handlers for service */
	srv_brw_register_all_ilm_handlers();
	/* Initializing all the NVRAM data contents */
	srv_brw_settings_nvram_data_init();
}

#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  srv_brw_trusted_certificate_get_actual_index
 * DESCRIPTION
 *  This function is to provide the actual trusted cert ID  for the certificate
 * currently highlighted
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_brw_trusted_certificate_get_actual_id(U32 highlighted_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.cert_ids[highlighted_item];
}
#endif /* WAP_SEC_SUPPORT */

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_active_profile_changed_hdlr
 * DESCRIPTION
 *  This func is used for displaying the session info
 * PARAMETERS
 *  profile_content_p       [?]         
 *  sim_id                  [IN]        
 *  callback                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_active_profile_changed_hdlr(
        srv_wap_prof_profile_content_struct *profile_content_p,
        srv_wap_prof_sim_id_enum sim_id,
        srv_wap_prof_response_funcptr_type callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_act_req_struct obj = {0};
    srv_brw_set_profile_req_struct prof = {0};
    srv_dtcnt_sim_type_enum global_sim_id;
    srv_brw_active_sim_setting_enum global_sim_setting;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dtcnt_get_sim_preference(&global_sim_id);
    global_sim_setting = srv_brw_convert_dtcnt_sim_id_to_sim_setting(global_sim_id);
    MMI_TRACE (MMI_INET_TRC_G4_BRW, MMI_BRW_ACTIVE_PROFILE_CHANGED_HDLR, 
               global_sim_setting, 
               g_srv_brw_cntx.session_sim_id, 
               sim_id);

    if (srv_brw_convert_profile_sim_id_to_sim_setting(sim_id) == global_sim_setting)
    {
        MMI_ASSERT(callback);
        g_srv_brw_cntx.session_sim_id = global_sim_setting;
        g_srv_brw_cntx.actv_prof_changed_cb = callback;

        obj.rsp_callback = srv_brw_active_profile_change_handler;
        prof.currprof = profile_content_p;
        prof.setting_id = wap_bam_setting_type_profile;
        obj.req_data = (void*)&prof;
        srv_brw_set_profile_req_by_data(&obj);
    }
#if (MMI_MAX_SIM_NUM >= 2)
    else
    {
        callback(SRV_WAP_PROF_SUCCESS);
    }
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    OslMfree(profile_content_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_is_in_transaction
 * DESCRIPTION
 *  This function is used check if Browser is currently fetching a page
 *  or not
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_brw_is_in_transaction(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p)
    {
        return (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching);
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_stricmp
 * DESCRIPTION
 *  This function is to compare two utf-8 strings in lower case
 * PARAMETERS
 *  string1     [IN]        First string in utf-8
 *  string2     [IN]        Second string in utf-8
 * RETURNS
 *  void
 *****************************************************************************/
S8 srv_brw_stricmp(S8 *string1, S8 *string2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *temp_str1;
    S8 *temp_str2;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(string1);
    MMI_ASSERT(string2);
    MMI_ASSERT((strlen((S8*) string1) + 1) * ENCODING_LENGTH <= SRV_BRW_MAX_CONTROL_BUFFER_SIZE);
    MMI_ASSERT((strlen((S8*) string2) + 1) * ENCODING_LENGTH <= SRV_BRW_MAX_CONTROL_BUFFER_SIZE);

    temp_str1 = OslMalloc((strlen((S8*) string1) + 1) * ENCODING_LENGTH);
    temp_str2 = OslMalloc((strlen((S8*) string2) + 1) * ENCODING_LENGTH);

    mmi_chset_utf8_to_ucs2_string((U8*) temp_str1, (strlen((S8*) string1) + 1) * ENCODING_LENGTH, (U8*) string1);
    mmi_chset_utf8_to_ucs2_string((U8*) temp_str2, (strlen((S8*) string2) + 1) * ENCODING_LENGTH, (U8*) string2);

    result = (S32) mmi_ucs2icmp((S8*) temp_str1, (S8*) temp_str2);

    OslMfree(temp_str1);
    OslMfree(temp_str2);

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_create_dynamic_service
 * DESCRIPTION
 *  This function is to create a dynamic instance of service by APP
 * PARAMETERS
 *  void
 * RETURNS
 *  Error code of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_create_dynamic_service(void)
{
	srv_brw_dynamic_context_init();
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_destroy_dynamic_service
 * DESCRIPTION
 *  This function is to destroy a dynamic instance of service by APP
 * PARAMETERS
 *  void
 * RETURNS
 *  Error code of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_destroy_dynamic_service(void)
{
	g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching = MMI_FALSE;
	srv_brw_dynamic_context_deinit();
	return SRV_BRW_ERROR_OK;
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
#endif //0


/*****************************************************************************
 * FUNCTION
 *  srv_brw_convert_int_to_unicode_string
 * DESCRIPTION
 *  Function to make the string from a integer value
 * PARAMETERS
 *  StringVal       [IN]        
 *  value           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_convert_int_to_unicode_string(U8 *StringVal, U32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 StrVal[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(StrVal, "%d", value);
    mmi_asc_to_ucs2((S8*) StringVal, (S8*) StrVal);
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_active_browser_profile
 * DESCRIPTION
 *  This function is to return the active profile content to DLAgent
 * PARAMETERS
 *  void 
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool srv_brw_get_active_browser_profile(srv_brw_profile_content_struct *active_prof)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_prof_profile_content_struct *profile_content_p;
    MMI_BOOL is_reset_needed = MMI_FALSE;
    U32 length;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(active_prof);
#if (MMI_MAX_SIM_NUM >= 2)
    if(g_srv_brw_cntx.session_sim_id == SRV_BRW_ACTIVE_SIM_SETTING_TOTAL)
    {
        srv_dtcnt_sim_type_enum sim_id;
        srv_dtcnt_get_sim_preference(&sim_id);
        g_srv_brw_cntx.session_sim_id = srv_brw_convert_dtcnt_sim_id_to_sim_setting(sim_id);
        is_reset_needed = MMI_TRUE;
    }
#endif
    srv_brw_get_profile_content((void **)&profile_content_p);
    if(is_reset_needed)
    {
        g_srv_brw_cntx.session_sim_id = SRV_BRW_ACTIVE_SIM_SETTING_TOTAL;
    }
    memset(active_prof, 0, sizeof(srv_brw_profile_content_struct));
    length = strlen((const char *)profile_content_p->proxy_ip) + 1;
    active_prof->proxy_ip = OslMalloc(length * sizeof(U8));
    strcpy((char *)active_prof->proxy_ip, (const char *)profile_content_p->proxy_ip);

    memcpy(active_prof->username, profile_content_p->username, SRV_BRW_PROF_USERNAME_LEN);
    memcpy(active_prof->password, profile_content_p->password, SRV_BRW_PROF_USERNAME_LEN);
    memcpy(active_prof->url, profile_content_p->url, SRV_BRW_PROF_URL_LEN);

    active_prof->data_account_primary_id = profile_content_p->data_account_primary_id;
    active_prof->data_account_secondary_id = profile_content_p->data_account_secondary_id;
    active_prof->proxy_port = profile_content_p->proxy_port;
    switch(profile_content_p->conn_type)
    {
        case SRV_WAP_PROF_CONN_TYPE_HTTP:
            active_prof->conn_type = SRV_BRW_PROF_CONN_TYPE_HTTP;
            break;

        case SRV_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED:
            active_prof->conn_type = SRV_BRW_PROF_CONN_TYPE_CONNECTION_OREINTED;
            break;

        case SRV_WAP_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE:
            active_prof->conn_type = SRV_BRW_PROF_CONN_TYPE_CONNECTION_OREINTED_SECURE;
            break;

        default:
            active_prof->conn_type = SRV_BRW_PROF_CONN_TYPE_NONE;        
    }

    OslMfree(profile_content_p);
    return KAL_TRUE;
}


#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_user_defined_homepage
 * DESCRIPTION
 *  This function is used to get the user defined homepage URL
 * stored in the NVRAM
 * PARAMETERS
 *  url_p -- The pointer of the buffer in which URL will be returned
 * RETURNS
 *  result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_get_user_defined_homepage (U8 *url_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 NvramError;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_LID,
        1,
        url_p,
        NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_SIZE,
        &NvramError);
    return SRV_BRW_ERROR_OK;
}
#endif

#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_recent_page_list_count
 * DESCRIPTION
 *  This Interface is getting the recent page list count
 * PARAMETERS
 *  void
 * RETURNS
 *  number of the recent pages in the recent page list
 *****************************************************************************/
U32 srv_brw_get_recent_page_list_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_count);
}
#endif

#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_stored_page_list_count
 * DESCRIPTION
 *  This Interface is getting the stored page list count
 * PARAMETERS
 *  void
 * RETURNS
 *  number of the stored pages in the stored page list
 *****************************************************************************/
U32 srv_brw_get_stored_page_list_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_list_item_count);
}
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */


#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_trusted_certificate_list_count
 * DESCRIPTION
 *  This Interface is getting the trusted certificate list count
 * PARAMETERS
 *  void
 * RETURNS
 *  number of the certificates in the trusted certificate list
 *****************************************************************************/
U32 srv_brw_get_trusted_certificate_list_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->trusted_cert_ids.total);
}
#endif /* WAP_SEC_SUPPORT */

#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_stored_page_label
 * DESCRIPTION
 *  This Interface to get the label of the stored page
 * PARAMETERS
 *  void
 * RETURNS
 *  the label of the stored page
 *****************************************************************************/
U8* srv_brw_get_stored_page_label(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p->label);
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_stored_page_URL
 * DESCRIPTION
 *  This Interface to get the URL of the stored page
 * PARAMETERS
 *  void
 * RETURNS
 *  the URL of the stored page
 *****************************************************************************/
U8* srv_brw_get_stored_page_URL(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p->url);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_brw_is_wap_ready
 * DESCRIPTION
 *  This Interface is to check if the wap is ready or not
 * PARAMETERS
 *  void
 * RETURNS
 *  wap is ready or not
 *****************************************************************************/
MMI_BOOL srv_brw_is_wap_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_brw_cntx.isWapReady);
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_screen_size_status
 * DESCRIPTION
 *  This Interface is to get the current screen size status of Browser
 * PARAMETERS
 *  void
 * RETURNS
 *  current screen size status
 *****************************************************************************/
MMI_BOOL srv_brw_get_screen_size_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((MMI_BOOL)g_srv_brw_cntx.screen_size_status);
}
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  srv_brw_set_address_list_entry_flag
 * DESCRIPTION
 *  This Interface is to set the address list flag
 * PARAMETERS
 *  status
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_set_address_list_entry_flag(MMI_BOOL is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_flag = is_set;
}
#endif /* __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */
/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_authentication_username
 * DESCRIPTION
 *  This Interface is to get the authentication username
 * PARAMETERS
 *  status
 * RETURNS
 *  void
 *****************************************************************************/
U8* srv_brw_get_authentication_username(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   if(g_srv_brw_cntx.http_auth_info_p)
   {
       return ((U8*)g_srv_brw_cntx.http_auth_info_p->username);
   }
   else
   {
       return (U8*)NULL;
   }
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_authentication_password
 * DESCRIPTION
 *  This Interface is to get the authentication passwrod
 * PARAMETERS
 *  status
 * RETURNS
 *  void
 *****************************************************************************/
U8* srv_brw_get_authentication_password(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   if(g_srv_brw_cntx.http_auth_info_p)
   {
       return ((U8*)g_srv_brw_cntx.http_auth_info_p->password);
   }
   else
   {
       return (U8*)NULL;
   }
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_is_page_valid_for_saving
 * DESCRIPTION
 *  This Interface is to check if the opened page is valid for saving
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_brw_is_page_valid_for_saving(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching)
    {
        return MMI_FALSE;
    }
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p)
    {
        if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->protocol != WAP_BAM_PROTOCOL_FILE ||
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->protocol != WAP_BAM_PROTOCOL_OTHER)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_is_page_url_valid
 * DESCRIPTION
 *  This Interface is to check if the opened page url is valid
 * PARAMETERS
 *  status
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_brw_is_page_url_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p)
    {
        if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->protocol != WAP_BAM_PROTOCOL_FILE &&
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p->protocol != WAP_BAM_PROTOCOL_OTHER)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_is_page_valid_for_add
 * DESCRIPTION
 *  This Interface is to check if the opened page is valid for adding as bookmark
 * or storing as saved page.
 * PARAMETERS
 *  status
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_brw_is_page_valid_for_add(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(srv_brw_is_page_url_valid() || srv_brw_is_page_valid_for_saving())
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_default_accept_header
 * DESCRIPTION
 *  This Interface is to check if the opened page is valid for adding as bookmark
 * or storing as saved page.
 * PARAMETERS
 *  void
 * RETURNS
 *  const U8*(accept header of browser)
 *****************************************************************************/
const U8* srv_brw_get_default_accept_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef OBIGO_Q03C
    return((const U8*)bam_cfg_default_accept_header());
#else
    return((const U8*)bam_cfg_brs_default_accept_header());
#endif
}

#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  srv_brw_read_search_item_list_data
 * DESCRIPTION
 *  This interface is for getting the search item List from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  NVRAM read operation error
 *****************************************************************************/
S16 srv_brw_read_search_item_list_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_count;
    S16 NvramError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p == NULL)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p =
            (nvram_brw_search_item_struct*) srv_brw_malloc(NVRAM_EF_BRW_SEARCH_ITEMS_RECORDS *
                                                           NVRAM_EF_BRW_SEARCH_ITEM_RECORD_SIZE);
        memset(
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p,
            0,
            (NVRAM_EF_BRW_SEARCH_ITEM_RECORD_SIZE * NVRAM_EF_BRW_SEARCH_ITEMS_RECORDS));
    }
    for (record_count = 1; record_count <= NVRAM_EF_BRW_SEARCH_ITEMS_RECORDS; record_count++)
    {
        ReadRecord(
            NVRAM_EF_BRW_SEARCH_ITEM_LID,
            record_count,
            &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[(record_count - 1) * SEARCH_ITEMS_PER_RECORD],
            NVRAM_EF_BRW_SEARCH_ITEM_RECORD_SIZE,
            &NvramError);
    }
    srv_brw_search_list_count_number_of_items();
	return NvramError;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_search_item_list_add_item
 * DESCRIPTION
 *  This interface is for adding a new search item string into the NVRAM
 * PARAMETERS
 *  search_string(UCS2) -- search string to be added into NVRAM
 * RETURNS
 *  Add item result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_search_item_list_add_item (S8* search_string, srv_brw_search_engines_enum search_engine)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 search_index;
    S8 search_item[(SRV_BRW_SEARCH_ITEM_LENGTH + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (search_index = 0; search_index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_search_list_items; ++search_index)
    {
        mmi_chset_utf8_to_ucs2_string((U8*)search_item, (SRV_BRW_SEARCH_ITEM_LENGTH + 1) * ENCODING_LENGTH, 
                (U8*)&g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[search_index].search_item);

        if (!mmi_ucs2ncmp((S8*) search_string, (S8*) search_item, SRV_BRW_SEARCH_ITEM_LENGTH) && search_engine == g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[search_index].search_engine)
        {
            if(search_index)
            {
                srv_brw_search_list_set_item_at_top(search_index);
                srv_brw_search_list_update_data();
            }
            return SRV_BRW_ERROR_OK;
        }
    }

    if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_search_list_items)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[0].search_engine = search_engine;
        mmi_chset_ucs2_to_utf8_string((U8*)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[0].search_item, SRV_BRW_SEARCH_ITEM_LENGTH, (U8*)search_string);
    }
    else
    {
        for (search_index = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_search_list_items; search_index >= 1; search_index--)
        {
            if (search_index < SRV_BRW_ADDRESS_LIST_MAX_ITEMS)
            {
                memcpy(
                    &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[search_index],
                    &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[search_index - 1],
                    sizeof(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[search_index]));
            }
        }

        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[0].search_engine = search_engine;
        memset(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[0].search_item, 0, SRV_BRW_SEARCH_ITEM_LENGTH);
        mmi_chset_ucs2_to_utf8_string((U8*)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[0].search_item, SRV_BRW_SEARCH_ITEM_LENGTH, (U8*)search_string);
    }

    srv_brw_search_list_update_data(); //write list to NVRAM

    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_search_list_items < SRV_BRW_SEARCH_LIST_MAX_ITEMS)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_search_list_items++;
    }
#ifdef __COSMOS_MMI_PACKAGE__
#ifndef __MMI_BRW_SLIM__
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcut_item_flag = MMI_TRUE;
#endif
#endif
    return SRV_BRW_ERROR_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_launch_search_item
 * DESCRIPTION
 *  This interface is for launching the search item present in the search list
 * PARAMETERS
 *  item_index  -   index of the search item in the search list
 * RETURNS
 *  Add item result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_launch_search_item(U8 search_item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(!(search_item_index >= SRV_BRW_SEARCH_LIST_MAX_ITEMS));
    if(strlen((S8*)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[search_item_index].search_item))
    {
        return (srv_brw_launch_search_string(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[search_item_index].search_item,
                (srv_brw_search_engines_enum)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[search_item_index].search_engine));
    }
    else
    {
        return SRV_BRW_ERROR;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_search_list_set_item_at_top
 * DESCRIPTION
 *  Interface to set a selected item at the top of search list
 * PARAMETERS
 *  selected_item_index     [IN]        
 * RETURNS
 *  Operation Result
 *****************************************************************************/
srv_brw_error_enum srv_brw_search_list_set_item_at_top(U32 selected_item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 list_index;
    srv_brw_search_engines_enum search_engine;
    U8 search_item_temp[(SRV_BRW_SEARCH_ITEM_LENGTH) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (selected_item_index >= SRV_BRW_SEARCH_LIST_MAX_ITEMS)
    {
        ASSERT(0);
    }
    search_engine = (srv_brw_search_engines_enum)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[selected_item_index].search_engine;
    mmi_chset_utf8_to_ucs2_string((U8*)search_item_temp, (SRV_BRW_SEARCH_ITEM_LENGTH + 1) * ENCODING_LENGTH, 
            (U8*)&g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[selected_item_index].search_item);

    for (list_index = selected_item_index; list_index >= 1; list_index--)
    {
        if (list_index < SRV_BRW_SEARCH_LIST_MAX_ITEMS)
        {
            memcpy(
                &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[list_index],
                &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[list_index - 1],
                sizeof(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[list_index]));
        }
    }
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[0].search_engine = search_engine;
    mmi_chset_ucs2_to_utf8_string((U8*)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[0].search_item, SRV_BRW_SEARCH_ITEM_LENGTH, (U8*)search_item_temp);
	return SRV_BRW_ERROR_OK;
}
 

/*****************************************************************************
 * FUNCTION
 *  srv_brw_search_list_delete_all_items
 * DESCRIPTION
 *  Deletes all the Browser search item list
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_brw_error_enum srv_brw_search_list_delete_all_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p =
            (nvram_brw_search_item_struct*) srv_brw_malloc(NVRAM_EF_BRW_SEARCH_ITEMS_RECORDS *
                                                           NVRAM_EF_BRW_SEARCH_ITEM_RECORD_SIZE);
    }
    memset(
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p,
        0,
        (NVRAM_EF_BRW_SEARCH_ITEM_RECORD_SIZE * NVRAM_EF_BRW_SEARCH_ITEMS_RECORDS));

    srv_brw_search_list_update_data();
    srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p));
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_search_list_items = 0;
	return SRV_BRW_ERROR_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_address_list_get_title
 * DESCRIPTION
 *  Returns the search entry at the nth index in Browser search list
 * PARAMETERS
 *  index -- Item index whose search item is to be returned [IN]
	search_item --the structure in which the requested data will be 
                            returned [OUT]
 * RETURNS
 * service error code
 *****************************************************************************/
srv_brw_error_enum srv_brw_search_list_get_item (U8 index, nvram_brw_search_item_struct *search_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (index >= SRV_BRW_SEARCH_LIST_MAX_ITEMS)
    {
        ASSERT(0);
    }
    ASSERT(search_item);
    search_item->search_engine  = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[index].search_engine;
    strcpy((S8*) search_item->search_item, (S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[index].search_item);
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_search_list_get_number_of_items
 * DESCRIPTION
 *  This interface is for getting the number of search list items
 * PARAMETERS
 *  void
 * RETURNS
 *  Search list items count
 *****************************************************************************/
U8 srv_brw_search_list_get_number_of_items (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p)
    {
        return (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_search_list_items);
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_search_list_find_entry
 * DESCRIPTION
 *  Interface for getting the matched items list,from search list, 
	corresponding to a given input string
 * PARAMETERS
 *  input_str       [IN]     
 * RETURNS
 *  Number of matched items in address history
 *****************************************************************************/
S32 srv_brw_search_list_find_entry(U8 *input_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 matched_item_index = 0;
    U8 search_item_temp[(SRV_BRW_SEARCH_ITEM_LENGTH + 1)*ENCODING_LENGTH] = {0};
    U8 input_str_temp[(SRV_BRW_SEARCH_ITEM_LENGTH + 1)*ENCODING_LENGTH] = {0};
    U8 num_of_matched_items = 0;
    U8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check the URL string */
    if (!input_str || !g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_search_list_items)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_search_items = 0;
        return 0;
    }

    mmi_ucs2ncpy((CHAR*) input_str_temp, (CHAR*) input_str, SRV_BRW_SEARCH_ITEM_LENGTH);
    for (index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_search_list_items; index++)
    {
        mmi_chset_utf8_to_ucs2_string((U8*) search_item_temp, (SRV_BRW_SEARCH_ITEM_LENGTH) * ENCODING_LENGTH, (U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[index].search_item);
        /* Compare the input URL with first and second part URL strings */
        if (mmi_ucs2str((const S8*)mmi_ucs2lwr((CHAR*)search_item_temp), (const S8*)mmi_ucs2lwr((CHAR*)input_str_temp)))
        {
            /* Save the matched URL indices into matched URL list */
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_search_items_list[matched_item_index++] = index;
            ++num_of_matched_items;
        }
    }
    /* Update the total matched URL number */
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_search_items = num_of_matched_items;
    return num_of_matched_items;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_search_list_get_matched_item_count
 * DESCRIPTION
 *  API to get the count of matched items in the search items list
 * PARAMETERS
 *  void
 * RETURNS
 *  count
 *****************************************************************************/
S32 srv_brw_search_list_get_matched_item_count(void)
{
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p)
    {
        return g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_search_items;
    }
    else
    {
        return 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_search_list_get_matched_item
 * DESCRIPTION
 *  Item call back function for Matched items list
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 * RETURNS
 *  The matched item URL
 *****************************************************************************/
S8* srv_brw_search_list_get_matched_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((item_index >= 0) && (item_index <= SRV_BRW_SEARCH_LIST_MAX_ITEMS));
    return ((S8*)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_search_items_list[item_index]].search_item);
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_search_list_get_matched_item_search_engine
 * DESCRIPTION
 *  Item call back function for Matched items list
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 * RETURNS
 *  Search engine for the selected URL
 *****************************************************************************/
srv_brw_search_engines_enum srv_brw_search_list_get_matched_item_search_engine(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT((item_index >= 0) && (item_index <= SRV_BRW_SEARCH_LIST_MAX_ITEMS));
    return ((srv_brw_search_engines_enum)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_search_items_list[item_index]].search_engine);
}
#endif /* #if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)  */


/*****************************************************************************
 * FUNCTION
 *  srv_brw_launch_search_string
 * DESCRIPTION
 *  This interface is for launching a search string with the search engine specified
 * PARAMETERS
 *  item_index  -   index of the search item in the search list
 * RETURNS
 *  Add item result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_launch_search_string(U8* saerch_string, srv_brw_search_engines_enum search_engine)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_load_url_req_struct *myMsgPtr;
    U32 prefix_len = 0;
    U32 suffix_len = 0;
    CHAR* prefix = NULL;
    CHAR* suffix = NULL;
    CHAR* encoded_keyword;
    MMI_BOOL is_truncated;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(search_engine)
    {
#ifdef __COSMOS_MMI_PACKAGE__
        case SRV_BRW_SEARCH_ENGINE_BAIDU:
        {
            prefix = SRV_BRW_BAIDU_SEARCH_BEGINING_STRING;
            suffix = SRV_BRW_BAIDU_SEARCH_ENDING_STRING;
            prefix_len = strlen(SRV_BRW_BAIDU_SEARCH_BEGINING_STRING);
            suffix_len = strlen(SRV_BRW_BAIDU_SEARCH_ENDING_STRING);
            break;
        }
#endif
        case SRV_BRW_SEARCH_ENGINE_GOOGLE:
        {
            prefix = SRV_BRW_GOOGLE_SEARCH_BEGINING_STRING;
            prefix_len = strlen(SRV_BRW_GOOGLE_SEARCH_BEGINING_STRING);
            break;
        }

#ifdef __COSMOS_MMI_PACKAGE__
        case SRV_BRW_SEARCH_ENGINE_YAHOO:
        {
            prefix = SRV_BRW_YAHOO_SEARCH_BEGINING_STRING;
            suffix = SRV_BRW_YAHOO_SEARCH_ENDING_STRING;
            prefix_len = strlen(SRV_BRW_YAHOO_SEARCH_BEGINING_STRING);
            suffix_len = strlen(SRV_BRW_YAHOO_SEARCH_ENDING_STRING);
            break;
        }

        case SRV_BRW_SEARCH_ENGINE_BING:
        {
            prefix = SRV_BRW_BING_SEARCH_BEGINING_STRING;
            suffix = SRV_BRW_BING_SEARCH_ENDING_STRING;
            prefix_len = strlen(SRV_BRW_BING_SEARCH_BEGINING_STRING);
            suffix_len = strlen(SRV_BRW_BING_SEARCH_ENDING_STRING);
            break;
        }
#endif
        default:
        {
            return SRV_BRW_ERROR;
        }
    }
    encoded_keyword = (CHAR*)srv_brw_malloc(WAP_BAM_MAX_URL_LEN - (prefix_len + suffix_len));
    memset(encoded_keyword, 0, WAP_BAM_MAX_URL_LEN - (prefix_len + suffix_len));
    srv_brw_encode_url((CHAR*)encoded_keyword, WAP_BAM_MAX_URL_LEN, (CHAR*)saerch_string, strlen((S8*)saerch_string), &is_truncated);
    myMsgPtr = (wap_bam_load_url_req_struct*) OslConstructDataPtr(sizeof(wap_bam_load_url_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->options = WAP_BAM_OPTION_KEEP_WML_CONTEXT;
    myMsgPtr->charset = WAP_BAM_UNKNOWN_CHARSET; /* g_srv_brw_cntx.charset_list_p[g_srv_brw_cntx.encoding_method_index].id */
    strcpy((S8*) myMsgPtr->url, (S8*) prefix);
    strcat((S8*) myMsgPtr->url, (S8*) encoded_keyword);
    if(suffix)
    {
        strcat((S8*) myMsgPtr->url, (S8*) suffix);
    }

#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.launch_type = SRV_BRW_LAUNCH_URL;
    if(!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.data)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.data = (U8*)srv_brw_malloc((WAP_MAX_SEARCH_URL_LENGTH + 1) * ENCODING_LENGTH);
        memset(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.data, 0,(WAP_MAX_SEARCH_URL_LENGTH + 1) * ENCODING_LENGTH);
    }
    mmi_ucs2cpy((CHAR*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.data, (CHAR*) myMsgPtr->url);
#endif
    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_LOAD_URL_REQ, myMsgPtr, NULL);
    srv_brw_free(encoded_keyword);
    return SRV_BRW_ERROR_OK;
}

#ifdef __COSMOS_MMI_PACKAGE__
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_recent_page_count_by_time
 * DESCRIPTION
 *  function to get the count of the recent pages with timestamp
 * between the given range
 * PARAMETERS
 *  upper_utc_time          [IN]       upper limit on timestamp
 *  lower_utc_time           [IN]       lower limit on timestamp
 * RETURNS
 *  The matched item URL
 *****************************************************************************/
U32 srv_brw_get_recent_page_count_by_time(U32 upper_utc_time , U32 lower_utc_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0;
    U8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count; index++)
    {
        if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].type >= lower_utc_time
            && g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].type <= upper_utc_time)
        {
            count ++;
        }
    }
    return count;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_recent_pages_count_by_day
 * DESCRIPTION
 *  function to get the count of the number of recent pages by day
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 * RETURNS
 *  The matched item URL
 *****************************************************************************/
U32 srv_brw_get_recent_pages_count_by_day(srv_brw_recent_pages_day_enum day)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct  curr_rtc_time;
    U32 curr_utc_time;
    U32 lower_utc_time;
    U32 upper_utc_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr_utc_time = srv_brw_get_current_utc_time();
    lower_utc_time = 0;
    upper_utc_time = 0;
    switch(day)
    {
        case SRV_BRW_RECENT_PAGES_DAY_TODAY:
        {
            upper_utc_time = (U32)-1;
            applib_dt_utc_sec_2_mytime(curr_utc_time, &curr_rtc_time, MMI_FALSE);
            curr_rtc_time.nHour = 0;
            curr_rtc_time.nMin = 0;
            curr_rtc_time.nSec = 0;
            lower_utc_time = applib_dt_mytime_2_utc_sec(&curr_rtc_time, MMI_FALSE);
            break;
        }
        case SRV_BRW_RECENT_PAGES_DAY_YESTERDAY:
        {
            applib_time_struct  yesterday_rtc_time;
            applib_time_struct  decrease_time = {0};
            decrease_time.nDay = 1;
            applib_dt_utc_sec_2_mytime(curr_utc_time, &curr_rtc_time, MMI_FALSE);
            curr_rtc_time.nHour = 0;
            curr_rtc_time.nMin = 0;
            curr_rtc_time.nSec = 0;
            applib_dt_decrease_time(&curr_rtc_time, &decrease_time, &yesterday_rtc_time);
            lower_utc_time = applib_dt_mytime_2_utc_sec(&yesterday_rtc_time, MMI_FALSE);
            yesterday_rtc_time.nHour = 23;
            yesterday_rtc_time.nMin = 59;
            yesterday_rtc_time.nSec = 59;
            upper_utc_time = applib_dt_mytime_2_utc_sec(&yesterday_rtc_time, MMI_FALSE);
            break;
        }
        case SRV_BRW_RECENT_PAGES_DAY_BEFORE_YESTERDAY:
        {
            applib_time_struct  yesterday_rtc_time;
            applib_time_struct  decrease_time = {0};
            decrease_time.nDay = 2;
            applib_dt_utc_sec_2_mytime(curr_utc_time, &curr_rtc_time, MMI_FALSE);
            curr_rtc_time.nHour = 23;
            curr_rtc_time.nMin = 59;
            curr_rtc_time.nSec = 59;
            applib_dt_decrease_time(&curr_rtc_time, &decrease_time, &yesterday_rtc_time);
            upper_utc_time = applib_dt_mytime_2_utc_sec(&yesterday_rtc_time, MMI_FALSE);
            lower_utc_time = 0;
            break;
        }
    }
    return (srv_brw_get_recent_page_count_by_time(upper_utc_time, lower_utc_time));
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_delete_recent_host_req
 * DESCRIPTION
 *  This Interface is used for Requesting deletion of a particular recent page
 * host(i.e. to delete all the recent pages under a host)
 * PARAMETERS
 *  app_data -- Application sent request data
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_delete_recent_page_by_day_req(U8 day_type, srv_brw_act_req_struct *app_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 lower_utc_time;
    U32 upper_utc_time;
    applib_time_struct  curr_rtc_time;
    U8 pages_count;
    U8 index;
    U8 list_index = 0;
    wap_bam_delete_n_recent_page_req_struct *myMsgPtr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    upper_utc_time = srv_brw_get_current_utc_time();
    if(day_type == SRV_BRW_RECENT_PAGES_DELETE_TODAYS)
    {
        applib_dt_utc_sec_2_mytime(upper_utc_time, &curr_rtc_time, MMI_FALSE);
        upper_utc_time = (U32)-1;
        curr_rtc_time.nHour = 0;
        curr_rtc_time.nMin = 0;
        curr_rtc_time.nSec = 0;
        lower_utc_time = applib_dt_mytime_2_utc_sec(&curr_rtc_time, MMI_FALSE);
    }
    else
    {
        applib_time_struct  yesterday_rtc_time;
        applib_time_struct  decrease_time = {0};
        decrease_time.nDay = 1;
        applib_dt_utc_sec_2_mytime(upper_utc_time, &curr_rtc_time, MMI_FALSE);
        upper_utc_time = (U32)-1;
        curr_rtc_time.nHour = 0;
        curr_rtc_time.nMin = 0;
        curr_rtc_time.nSec = 0;
        applib_dt_decrease_time(&curr_rtc_time, &decrease_time, &yesterday_rtc_time);
        lower_utc_time = applib_dt_mytime_2_utc_sec(&yesterday_rtc_time, MMI_FALSE);
    }
    pages_count = srv_brw_get_recent_page_count_by_time(upper_utc_time, lower_utc_time);
    srv_brw_save_user_app_req_data(MSG_ID_WAP_BAM_RECENT_PAGE_CNF, app_data);
    //Todo create array and send indexes
    myMsgPtr =
        (wap_bam_delete_n_recent_page_req_struct*) OslConstructDataPtr(sizeof(wap_bam_delete_n_recent_page_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->index_array = (U32*) OslMalloc(sizeof(U32) * pages_count);
    myMsgPtr->count = pages_count;
    for (index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count && list_index < pages_count; index++)
    {
        if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].type >= lower_utc_time &&
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].type <= upper_utc_time)
        {
            myMsgPtr->index_array[list_index] = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_list[index].actual_index;
            list_index++;
        }
    }
    g_srv_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_DELETE_N_RECENT_PAGE_REQ;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_DELETE_N_RECENT_PAGE_REQ, myMsgPtr, NULL);
	return SRV_BRW_ERROR_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_brw_delete_multiple_stored_page_req
 * DESCRIPTION
 *  This Interface is used for Requesting deletion of a multiple stored 
 * page
 * PARAMETERS
 *  app_data -- Application filled in request structure
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_delete_multiple_stored_page_req(srv_brw_act_req_struct *app_data, U8* selected_indexes)
{
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_delete_n_saved_page_req_struct *myMsgPtr;
    U8 index;
    U8 list_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_save_user_app_req_data(MSG_ID_WAP_BAM_SAVE_PAGE_CNF, app_data);
    myMsgPtr =
        (wap_bam_delete_n_saved_page_req_struct*) OslConstructDataPtr(sizeof(wap_bam_delete_n_saved_page_req_struct));

    myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->count = 0; 
    for(index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_list_item_count; index++)
    {
        if(selected_indexes[index] != 0)
        {
            myMsgPtr->count++;
        }
    }

    myMsgPtr->index_array = (U32*) OslMalloc(sizeof(U32) * myMsgPtr->count);

    for (index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_list_item_count && list_index <  myMsgPtr->count; index++)
    {
        if(selected_indexes[index] != 0)
        {
            myMsgPtr->index_array[list_index] = index;
            list_index++;
        }
    }

    g_srv_brw_cntx.sap_msg_id = MSG_ID_WAP_BAM_DELETE_N_SAVED_PAGE_REQ;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_DELETE_N_SAVED_PAGE_REQ, myMsgPtr, NULL);
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
	return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_update_search_engine
 * DESCRIPTION
 *  Item call back function for Matched items list
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 * RETURNS
 *  The matched item URL
 *****************************************************************************/
 void srv_brw_update_search_engine(srv_brw_search_engines_enum search_engine)
 {
	 g_srv_brw_cntx.sel_search_engine = search_engine;
 }

 /*****************************************************************************
 * FUNCTION
 *  srv_brw_read_search_engine
 * DESCRIPTION
 *  Item call back function for Matched items list
 * PARAMETERS
 *  item_index          [IN]        Highlighted item index
 * RETURNS
 *  The matched item URL
 *****************************************************************************/
 srv_brw_search_engines_enum srv_brw_read_search_engine(void)
 {
	 return g_srv_brw_cntx.sel_search_engine;
 }

 /*****************************************************************************
 * FUNCTION
 *  srv_brw_read_global_list_data
 * DESCRIPTION
 *  This interface is for getting the global shortcuts List from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  NVRAM read operation error
 *****************************************************************************/
S16 srv_brw_read_global_list_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_count;
    S16 NvramError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p == NULL)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p =
            (nvram_brw_global_shortcuts_item_struct*) srv_brw_malloc(NVRAM_EF_BRW_GLOBAL_SHORTCUTS_LIST_RECORDS *
                                                           NVRAM_EF_BRW_GLOBAL_SHORTCUTS_LIST_SIZE);
        memset(
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p,
            0,
            (NVRAM_EF_BRW_GLOBAL_SHORTCUTS_LIST_SIZE * NVRAM_EF_BRW_GLOBAL_SHORTCUTS_LIST_RECORDS));
    }
    for (record_count = 1; record_count <= NVRAM_EF_BRW_GLOBAL_SHORTCUTS_LIST_RECORDS; record_count++)
    {
        ReadRecord(
            NVRAM_EF_BRW_GLOBAL_SHORTCUTS_LIST_LID,
            record_count,
            &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[(record_count - 1) * GLOBAL_SHORTCUT_ENTERIES_PER_RECORD],
            NVRAM_EF_BRW_GLOBAL_SHORTCUTS_LIST_SIZE,
            &NvramError);
    }
    srv_brw_global_shortcuts_list_get_number_of_items();
	return NvramError;
}


#ifndef __MMI_BRW_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_read_global_list_data
 * DESCRIPTION
 *  This interface is for getting the local shortcuts List from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  NVRAM read operation error
 *****************************************************************************/
S16 srv_brw_read_local_list_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_count;
    S16 NvramError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p == NULL)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p =
            (nvram_brw_local_shortcuts_item_struct*) srv_brw_malloc(NVRAM_EF_BRW_LOCAL_SHORTCUTS_LIST_RECORDS *
                                                           NVRAM_EF_BRW_LOCAL_SHORTCUTS_LIST_SIZE);
        memset(
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p,
            0,
            (NVRAM_EF_BRW_LOCAL_SHORTCUTS_LIST_SIZE * NVRAM_EF_BRW_LOCAL_SHORTCUTS_LIST_RECORDS));
    }
    for (record_count = 1; record_count <= NVRAM_EF_BRW_LOCAL_SHORTCUTS_LIST_RECORDS; record_count++)
    {
        ReadRecord(
            NVRAM_EF_BRW_LOCAL_SHORTCUTS_LIST_LID,
            record_count,
            &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[(record_count - 1) * LOCAL_SHORTCUT_ENTERIES_PER_RECORD],
            NVRAM_EF_BRW_LOCAL_SHORTCUTS_LIST_SIZE,
            &NvramError);
    }
	return NvramError;
}
#endif /* #ifndef __MMI_BRW_SLIM__ */

 /*****************************************************************************
 * FUNCTION
 *  srv_brw_read_global_list_data
 * DESCRIPTION
 *  This interface is for getting the local shortcuts List from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  NVRAM read operation error
 *****************************************************************************/
void srv_brw_read_shortcuts_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_BRW_SLIM__
    srv_brw_read_local_list_data();
    srv_brw_local_shortcuts_list_get_number_of_items();
#endif
    srv_brw_read_global_list_data();
    srv_brw_global_shortcuts_list_get_number_of_items();
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_global_shortcuts_list_get_number_of_items
 * DESCRIPTION
 *  This interface is for getting the number of global shortcuts items
 * PARAMETERS
 *  void
 * RETURNS
 *  Address history items count
 *****************************************************************************/
U8 srv_brw_global_shortcuts_list_get_number_of_items (void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_global_list_items = 0;

    for (index = 0; index < SRV_BRW_GLOBAL_SHORTCUTS_LIST_MAX_ITEMS; index++)
    {
        /* If length of url is '0' then exit the loop */
        if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p && (strlen((S8*)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index].url) == 0))
        {
            break;
        }
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_global_list_items++;
    }
	return (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_global_list_items);
}

#ifndef __MMI_BRW_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_local_shortcuts_list_get_number_of_items
 * DESCRIPTION
 *  This interface is for getting the number of local shortcuts items
 * PARAMETERS
 *  void
 * RETURNS
 *  Address history items count
 *****************************************************************************/
U8 srv_brw_local_shortcuts_list_get_number_of_items (void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_local_list_items = 0;

    for (index = 0; index < SRV_BRW_LOCAL_SHORTCUTS_LIST_MAX_ITEMS; index++)
    {
        /* If length of url is '0' then exit the loop */
        if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p && (strlen((S8*)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[index].url) == 0))
        {
            break;
        }
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_local_list_items++;
    }
	return (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_local_list_items);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_brw_global_shortcuts_list_update_data
 * DESCRIPTION
 *  This interface is for saving the global shortcuts list item into NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_global_shortcuts_list_update_data (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_count;
    S16 NvramError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (record_count = 1; record_count <= NVRAM_EF_BRW_GLOBAL_SHORTCUTS_LIST_RECORDS; record_count++)
    {
	    WriteRecord(
		    NVRAM_EF_BRW_GLOBAL_SHORTCUTS_LIST_LID,
		    record_count,
           &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[(record_count - 1) * GLOBAL_SHORTCUT_ENTERIES_PER_RECORD],
		    NVRAM_EF_BRW_GLOBAL_SHORTCUTS_LIST_SIZE,
		    &NvramError);
    }
}


#ifndef __MMI_BRW_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_local_shortcuts_list_update_data
 * DESCRIPTION
 *  This interface is for saving the local shortcuts list item into NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_local_shortcuts_list_update_data (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_count;
    S16 NvramError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (record_count = 1; record_count <= NVRAM_EF_BRW_LOCAL_SHORTCUTS_LIST_RECORDS; record_count++)
    {
	    WriteRecord(
		    NVRAM_EF_BRW_LOCAL_SHORTCUTS_LIST_LID,
		    record_count,
           &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[(record_count - 1) * LOCAL_SHORTCUT_ENTERIES_PER_RECORD],
		    NVRAM_EF_BRW_LOCAL_SHORTCUTS_LIST_SIZE,
		    &NvramError);
    }
}
#endif

 
/*****************************************************************************
 * FUNCTION
 *  srv_brw_is_shortcut_index_empty
 * DESCRIPTION
 *  This interface is for checking if the item in the global shortcuts list
 * at the given index is empty or filled.
 * PARAMETERS
 *  
 * RETURNS
 *  Add item result of type srv_brw_error_enum
 *****************************************************************************/
MMI_BOOL srv_brw_is_shortcut_index_empty (U8 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < SRV_BRW_GLOBAL_SHORTCUTS_LIST_MAX_ITEMS);
    if(strlen((S8*)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index].url))
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_find_available_shortcut_id
 * DESCRIPTION
 *  This interface is for finding a free id for the image file corresponding to the global shortcut
 * PARAMETERS
 *  
 * RETURNS
 *  free item id
 *****************************************************************************/
U8 srv_brw_find_available_shortcut_id (void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 item_id = 0;
    U8 id_array[SRV_BRW_GLOBAL_SHORTCUTS_LIST_MAX_ITEMS + 1] = {0};
    U8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(index = 0; index < SRV_BRW_GLOBAL_SHORTCUTS_LIST_MAX_ITEMS; index++)
    {
        id_array[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index].id] = 1;
    }
    for(index = 1; index <= SRV_BRW_GLOBAL_SHORTCUTS_LIST_MAX_ITEMS; index++)
    {
        if(id_array[index] == 0)
        {
            item_id =  index;
            break;
        }
    }
    return item_id;    
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_global_shortcuts_list_add_item_at
 * DESCRIPTION
 *  This interface is for adding a new entry into the global shortcuts list
 * at the specified index
 * PARAMETERS
 *  
 * RETURNS
 *  Add item result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_global_shortcuts_list_add_item_at (nvram_brw_global_shortcuts_item_struct *item, U8 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(item);
    MMI_ASSERT(index < SRV_BRW_GLOBAL_SHORTCUTS_LIST_MAX_ITEMS);

    if(srv_brw_is_shortcut_index_empty(index))
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_global_list_items++;
    }
    memcpy(&g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index], item, sizeof(nvram_brw_global_shortcuts_item_struct));
    srv_brw_global_shortcuts_list_update_data(); //write list to NVRAM

	return SRV_BRW_ERROR_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_global_shortcuts_list_add_item
 * DESCRIPTION
 *  This interface is for adding a new entry into the global shortcuts list
 * PARAMETERS
 *  
 * RETURNS
 *  Add item result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_global_shortcuts_list_add_item(nvram_brw_global_shortcuts_item_struct *item)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    U8 empty_index = SRV_BRW_GLOBAL_SHORTCUTS_LIST_MAX_ITEMS;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(item);
    /* check if the URL already exists in the global list */
    for(index = 0; index < SRV_BRW_GLOBAL_SHORTCUTS_LIST_MAX_ITEMS; index++)
    {
        if(!srv_brw_is_shortcut_index_empty(index))
        {
            if (!strcmp((S8*)item->url, (S8*)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index].url))
            {
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index].points = 
                    ((g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index].points * SRV_BRW_GLOBAL_SHORTCUT_MULTIPLIER) + item->points);
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index].time = item->time;
                memcpy(&g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index].title,
                    &(item->title),
                    sizeof(nvram_brw_hist_title_struct));
            	return SRV_BRW_ERROR_OK;
            }
        }
        else
        {
            if(empty_index == SRV_BRW_GLOBAL_SHORTCUTS_LIST_MAX_ITEMS)
            {
                empty_index = index;
            }
        }
    }
    if(empty_index != SRV_BRW_GLOBAL_SHORTCUTS_LIST_MAX_ITEMS)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_global_list_items++;
        memcpy(&g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[empty_index], item, sizeof(nvram_brw_global_shortcuts_item_struct));
    	return SRV_BRW_ERROR_OK;
    }
    else
    {
        U8 selected_index = empty_index - 1;
        if(!srv_brw_is_global_shortcut_locked(selected_index))
        {
            if(item->points > g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[selected_index].points)
            {
                memcpy(&g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[selected_index], item, sizeof(nvram_brw_global_shortcuts_item_struct));
        	    return SRV_BRW_ERROR_OK;
            }
            else
            {
                return SRV_BRW_ERROR;
            }
        }
        else
        {
            return SRV_BRW_ERROR;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_global_shortcuts_set_item_lock
 * DESCRIPTION
 *  This interface is for locking the shortcut at the specified index
 * PARAMETERS
 *  
 * RETURNS
 *  result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_global_shortcuts_set_item_lock (U8 index, MMI_BOOL is_locked)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < SRV_BRW_GLOBAL_SHORTCUTS_LIST_MAX_ITEMS);
    if(srv_brw_is_shortcut_index_empty(index))
    {
        return SRV_BRW_ERROR;
    }
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index].is_locked = is_locked;
    return SRV_BRW_ERROR_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_is_global_shortcut_locked
 * DESCRIPTION
 *  This interface is for checking if the shortcut at the specified index is
 * locked
 * PARAMETERS
 *  
 * RETURNS
 *  result of type srv_brw_error_enum
 *****************************************************************************/
MMI_BOOL srv_brw_is_global_shortcut_locked (U8 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < SRV_BRW_GLOBAL_SHORTCUTS_LIST_MAX_ITEMS);
    if(srv_brw_is_shortcut_index_empty(index))
    {
        return MMI_FALSE;
    }
    return ((MMI_BOOL)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index].is_locked);
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_local_shortcuts_list_add_item
 * DESCRIPTION
 *  This interface is for adding checking making an entry into the local 
 * shortcuts list
 * PARAMETERS
 *  
 * RETURNS
 *  Add item result of type srv_brw_error_enum
 *****************************************************************************/
nvram_brw_global_shortcuts_item_struct* srv_brw_get_global_shortcut(U8 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < SRV_BRW_GLOBAL_SHORTCUTS_LIST_MAX_ITEMS);
    return ((nvram_brw_global_shortcuts_item_struct*)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index]));
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_launch_global_shortcut
 * DESCRIPTION
 *  This interface is for launching the URL of a global shortcut
 * PARAMETERS
 *  
 * RETURNS
 *  Add item result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_launch_global_shortcut(U8 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < SRV_BRW_GLOBAL_SHORTCUTS_LIST_MAX_ITEMS);
    if(srv_brw_is_shortcut_index_empty(index))
    {
        return SRV_BRW_ERROR;
    }
    else
    {
        wap_bam_load_url_req_struct *myMsgPtr;
	    myMsgPtr = (wap_bam_load_url_req_struct*) OslConstructDataPtr(sizeof(wap_bam_load_url_req_struct));
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcut_item_flag = MMI_TRUE;
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->launched_global_shortcut_index = index;

        myMsgPtr->source_id = SRV_BRW_APPLICATION_ID;
        myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
        myMsgPtr->options = WAP_BAM_OPTION_KEEP_WML_CONTEXT;
        myMsgPtr->charset = WAP_BAM_UNKNOWN_CHARSET; /* g_srv_brw_cntx.charset_list_p[g_srv_brw_cntx.encoding_method_index].id */
        strncpy((S8*) myMsgPtr->url, (S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index].url, sizeof(myMsgPtr->url));
        srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_LOAD_URL_REQ, myMsgPtr, NULL);
    #ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.launch_type = SRV_BRW_LAUNCH_SHORTCUT;
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.page_id = index;
    #endif
    }
#ifndef __MMI_BRW_SLIM__
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcut_item_flag = MMI_TRUE;
#endif
    return SRV_BRW_ERROR_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_delete_global_shortcut
 * DESCRIPTION
 *  This interface is for deleting the global shortcut at specified index
 * PARAMETERS
 *  
 * RETURNS
 *  Add item result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_delete_global_shortcut(U8 index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < SRV_BRW_GLOBAL_SHORTCUTS_LIST_MAX_ITEMS);
    if(!srv_brw_is_shortcut_index_empty(index))
    {
        memset(&g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index], 0, sizeof(nvram_brw_global_shortcuts_item_struct));
        srv_brw_global_shortcuts_list_update_data();
    }
    return SRV_BRW_ERROR_OK;
}

#ifndef __MMI_BRW_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_local_shortcuts_list_add_item
 * DESCRIPTION
 *  This interface is for adding checking making an entry into the local 
 * shortcuts list
 * PARAMETERS
 *  
 * RETURNS
 *  Add item result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_local_shortcuts_list_add_item (nvram_brw_local_shortcuts_item_struct *item)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(item);

    for(index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_local_list_items; index++)
    {
        if(!strcmp((S8*)item->url, g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[index].url))
        {
            srv_brw_increment_local_shortcut_points(index);
            srv_brw_local_shortcuts_list_update_data();
            return SRV_BRW_ERROR_OK;
        }
    }
   return (srv_brw_local_shortcuts_add_entry(item));
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_increment_local_shortcut_points
 * DESCRIPTION
 *  This interface is for incrementing the points of an item at the 
 * specified index and move it to appropriate index in the list
 * PARAMETERS
 *  
 * RETURNS
 *  Add item result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_increment_local_shortcut_points (U8 shortcut_index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    U8 updated_points = 0;
    S8 start_index = 0;
    nvram_brw_local_shortcuts_item_struct *item;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(shortcut_index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_local_list_items);
    updated_points = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[shortcut_index].points + 1;
    if(shortcut_index == 0)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[shortcut_index].points++;
        return SRV_BRW_ERROR_OK;
    }
    else if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[shortcut_index - 1].points > updated_points)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[shortcut_index].points++;
        return SRV_BRW_ERROR_OK;
    }

    for(index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_local_list_items; index++)
    {
        if(updated_points >= g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[index].points)
        {
            start_index = index;
            break;
        }
    }

    MMI_ASSERT(start_index >= 0);
    MMI_ASSERT(start_index < shortcut_index);
    item = (nvram_brw_local_shortcuts_item_struct*)srv_brw_malloc(sizeof(nvram_brw_local_shortcuts_item_struct));
    memcpy(item, &(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[shortcut_index]), sizeof(nvram_brw_local_shortcuts_item_struct));
    item->points++;
    for (index = shortcut_index; index > start_index; index--)
    {
        memcpy(
            &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[index],
            &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[index - 1],
            sizeof(nvram_brw_local_shortcuts_item_struct));
    }
    memcpy(
        &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[start_index],
        item,
        sizeof(nvram_brw_local_shortcuts_item_struct));
    srv_brw_free(item);
    return SRV_BRW_ERROR_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_local_shortcuts_add_entry
 * DESCRIPTION
 *  This interface is for adding a new entry into the local shortcuts list
 * PARAMETERS
 *  
 * RETURNS
 *  Add item result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_local_shortcuts_add_entry (nvram_brw_local_shortcuts_item_struct *item)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    U8 start_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(item);
    /* check for index from the end at which this new entry can be added */
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_local_list_items > 0)
    {
        if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_local_list_items == SRV_BRW_LOCAL_SHORTCUTS_LIST_MAX_ITEMS)
        {
            start_index = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_local_list_items - 1;
        }
        else
        {
            start_index = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_local_list_items;
        }
        for(index = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_local_list_items - 1; index >= 0; index--)
        {
            if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[index].points == 1)
            {
                start_index = index;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        memcpy(
            &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[0],
            item,
            sizeof(nvram_brw_local_shortcuts_item_struct));
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_local_list_items++;
        srv_brw_local_shortcuts_list_update_data();
        return SRV_BRW_ERROR_OK;
    }
    for (index = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_local_list_items; index > start_index; index--)
    {
        if (index < SRV_BRW_LOCAL_SHORTCUTS_LIST_MAX_ITEMS)
        {
            memcpy(
                &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[index],
                &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[index - 1],
                sizeof(nvram_brw_local_shortcuts_item_struct));
        }
    }
   memcpy(
       &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[start_index],
       item,
       sizeof(nvram_brw_local_shortcuts_item_struct));
   srv_brw_local_shortcuts_list_update_data();

    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_local_list_items < SRV_BRW_LOCAL_SHORTCUTS_LIST_MAX_ITEMS)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_local_list_items++;
    }
    return SRV_BRW_ERROR_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_brw_rearrange_global_shortcuts
 * DESCRIPTION
 *  This is the interface function which can be called to rearrange the position
 * of the global shortcuts on the basis of points and lock state.
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_brw_rearrange_global_shortcuts(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    U8 internal_index;
    U8 selected_shortcut_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_global_list_items < 2)
    {
        srv_brw_global_shortcuts_list_update_data();
        return;
    }

    for(index = 0; index < (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_global_list_items - 1); index++)
    {
        if(srv_brw_is_global_shortcut_locked(index))
        {
            continue;
        }
        selected_shortcut_index = index;
        for(internal_index = index + 1; internal_index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_global_list_items; internal_index++)
        {
            if(srv_brw_is_global_shortcut_locked(internal_index))
            {
                continue;
            }
            if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[selected_shortcut_index].points <
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[internal_index].points)
            {
                selected_shortcut_index = internal_index;
            }
        }
        if(selected_shortcut_index != index)
        {
            memcpy(&g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[selected_shortcut_index], 
                   &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index], 
                   sizeof(nvram_brw_global_shortcuts_item_struct));
        }
    }
    srv_brw_global_shortcuts_list_update_data();
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_rearrange_global_shortcuts
 * DESCRIPTION
 *  This is the interface function which can be called to rearrange the position
 * of the global shortcuts on the basis of points and lock state.
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_brw_reposition_global_shortcuts(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    U8 internal_index;
    U8 selected_shortcut_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(index = 0; index < SRV_BRW_GLOBAL_SHORTCUTS_LIST_MAX_ITEMS; index++)
    {
        if(srv_brw_is_global_shortcut_locked(index))
        {
            continue;
        }
        selected_shortcut_index = index;
        for(internal_index = index + 1; internal_index < SRV_BRW_GLOBAL_SHORTCUTS_LIST_MAX_ITEMS; internal_index++)
        {
            if(srv_brw_is_global_shortcut_locked(internal_index))
            {
                continue;
            }
            if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[selected_shortcut_index].points < 
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[internal_index].points)
            {
                selected_shortcut_index = internal_index;
            }
            else
            {
                if(srv_brw_is_shortcut_index_empty(selected_shortcut_index) && !srv_brw_is_shortcut_index_empty(internal_index))
                {
                    selected_shortcut_index = internal_index;
                }
            }
        }
        if(selected_shortcut_index != index)
        {
            nvram_brw_global_shortcuts_item_struct *temp;
            temp = (nvram_brw_global_shortcuts_item_struct*)  srv_brw_malloc(sizeof(nvram_brw_global_shortcuts_item_struct));

            memcpy(temp, &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index], 
                   sizeof(nvram_brw_global_shortcuts_item_struct));

            memcpy(&g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index], 
                   &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[selected_shortcut_index], 
                   sizeof(nvram_brw_global_shortcuts_item_struct));

            memcpy(&g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[selected_shortcut_index], 
                   temp, sizeof(nvram_brw_global_shortcuts_item_struct));
            srv_brw_free(temp);

        }
    }
    srv_brw_global_shortcuts_list_update_data();
}



/*****************************************************************************
 * FUNCTION
 *  srv_brw_update_global_shortcut_points
 * DESCRIPTION
 *  This is the interface function which can be called to update the global
 * shortcuts points.
 * PARAMETERS
 *  
 * RETURNS
 *  Add item result of type srv_brw_error_enum
 *****************************************************************************/
void srv_brw_update_global_shortcut_points(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    MMI_BOOL is_rearrange_needed = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_global_list_items; index++)
    {
        if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index].time != 0
            && srv_brw_is_shortcut_one_week_old(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index].time))
        {
            if(!srv_brw_is_global_shortcut_locked(index))
            {
                is_rearrange_needed = MMI_TRUE;
            }
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index].points = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index].points/2;
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p[index].time = srv_brw_get_current_utc_time();
        }
    }
    if(is_rearrange_needed)
    {
        srv_brw_reposition_global_shortcuts();
    }
}


#ifndef __MMI_BRW_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_rearrange_local_shortcuts
 * DESCRIPTION
 *  This is the interface function which can be called to rearrange the position
 * of the local shortcuts on the basis of points.
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_brw_rearrange_local_shortcuts(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    U8 head_index = 0;
    U8 tail_index = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_local_list_items; index++)
    {
        if((g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[head_index].points != 0)
           && (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[index].points == 0))
        {
            head_index = index;
        }
        else
        {
            tail_index = index;
        }
        if((tail_index == index) && (head_index != tail_index))
        {
           memcpy(
               &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[head_index],
               &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[tail_index],
               sizeof(nvram_brw_local_shortcuts_item_struct));

            memset(&g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[tail_index],
                0,
                sizeof(nvram_brw_local_shortcuts_item_struct));
            head_index++;
        }
    }
    srv_brw_local_shortcuts_list_get_number_of_items();
    srv_brw_local_shortcuts_list_update_data();
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_update_local_shortcut_points
 * DESCRIPTION
 *  This is the interface function which can be called to update the local
 * shortcuts points.
 * PARAMETERS
 *  
 * RETURNS
 *  Add item result of type srv_brw_error_enum
 *****************************************************************************/
void srv_brw_update_local_shortcut_points(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    MMI_BOOL is_rearrange_needed = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_local_list_items; index++)
    {
        if(srv_brw_is_shortcut_one_day_old(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[index].time))
        {
            nvram_brw_global_shortcuts_item_struct *newItem;
            newItem = (nvram_brw_global_shortcuts_item_struct*)  srv_brw_malloc(sizeof(nvram_brw_global_shortcuts_item_struct));
            memset(newItem, 0, sizeof(nvram_brw_global_shortcuts_item_struct));
            newItem->points = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[index].points;
            newItem->time = srv_brw_get_current_utc_time();

            memcpy(&(newItem->title),
                   &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[index].title,
                   sizeof(nvram_brw_hist_title_struct));
            strncpy((S8*) newItem->url, (S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[index].url, NVRAM_BRW_ADDRESS_HISTORY_MAX_URL_LENGTH);

            srv_brw_global_shortcuts_list_add_item(newItem);
            srv_brw_free(newItem);
            memset(&g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p[index],
                0,
                sizeof(nvram_brw_local_shortcuts_item_struct));
            is_rearrange_needed = MMI_TRUE;
        }
    }
    if(is_rearrange_needed)
    {
        srv_brw_rearrange_local_shortcuts();
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_brw_update_shortcut_points
 * DESCRIPTION
 *  This is the interface function which can be called to update the 
 * shortcuts points of both local and global shortcuts.
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_brw_update_shortcut_points(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_update_global_shortcut_points();
#ifndef __MMI_BRW_SLIM__
    srv_brw_update_local_shortcut_points();
#endif
    srv_brw_reposition_global_shortcuts();
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_is_shortcut_one_week_old
 * DESCRIPTION
 *  This function is to check if the rtc time of shortcut passed to it is more
 * than one week old.
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_brw_is_shortcut_one_week_old(U32 shortcut_time)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 prev_week_utc_time;
    applib_time_struct  curr_rtc_time;
    applib_time_struct  prev_week_rtc_time;
    applib_time_struct  decrease_time = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_rtc_time(&curr_rtc_time);
    decrease_time.nDay = 7;
    applib_dt_decrease_time(&curr_rtc_time, &decrease_time, &prev_week_rtc_time);
    prev_week_utc_time = applib_dt_mytime_2_utc_sec(&prev_week_rtc_time, MMI_FALSE);
    if(prev_week_utc_time > shortcut_time)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_is_shortcut_one_week_old
 * DESCRIPTION
 *  This function is to check if the rtc time of shortcut passed to it is more
 * than one day old.
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_brw_is_shortcut_one_day_old(U32 shortcut_time)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 prev_day_utc_time;
    applib_time_struct  curr_rtc_time;
    applib_time_struct  prev_day_rtc_time;
    applib_time_struct  decrease_time = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_rtc_time(&curr_rtc_time);
    decrease_time.nDay = 1;
    applib_dt_decrease_time(&curr_rtc_time, &decrease_time, &prev_day_rtc_time);
    prev_day_utc_time = applib_dt_mytime_2_utc_sec(&prev_day_rtc_time, MMI_FALSE);
    if(prev_day_utc_time > shortcut_time)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_wmls_dialog_rsp
 * DESCRIPTION
 *  This function is to send the response to the wmls dialog req
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_brw_error_enum srv_brw_wmls_dialog_rsp(U32 result, U8 dialog_type, U8* message)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_wmls_create_dialogue_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr = (wap_bam_wmls_create_dialogue_rsp_struct*) OslConstructDataPtr(sizeof(wap_bam_wmls_create_dialogue_rsp_struct));

    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->dialup_type = dialog_type;
    myMsgPtr->result = (kal_bool)result;
    if (message)
    {
        mmi_chset_ucs2_to_utf8_string((U8*) myMsgPtr->msg, WAP_BAM_MAX_WMLS_MSG_LENGTH, (U8*) message);
    }

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_WMLS_CREATE_DIALOGUE_RSP, myMsgPtr, NULL);
    return SRV_BRW_ERROR_OK;
}
#endif /* __COSMOS_MMI_PACKAGE__ */

/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_verno
 * DESCRIPTION
 *  This function is to send the response to the wmls dialog req
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
char* srv_brw_get_verno(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (bam_main_getVrsnNo());
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_current_utc_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void.
 * RETURNS
 *  Return the current UTC time.
 *****************************************************************************/
U32 srv_brw_get_current_utc_time (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct curr_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_rtc_time(&curr_time);
    return (applib_dt_mytime_2_utc_sec(&curr_time, MMI_FALSE));
}


#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  srv_brw_relaunch_last_browser_req
 * DESCRIPTION
 *  This function is to relaunch the last launch req made by the Browser
 * PARAMETERS
 *  void.
 * RETURNS
 *  void
 *****************************************************************************/
srv_brw_error_enum srv_brw_relaunch_last_browser_req (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_brw_error_enum ret = SRV_BRW_ERROR_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_BEARER_FALLBACK_NOTIFY, 51, 0, 0, g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.launch_type);
    switch(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.launch_type)
    {
        case SRV_BRW_LAUNCH_URL:
        {
            srv_brw_load_url_req(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.data, WAP_BAM_UNKNOWN_CHARSET);
            break;
        }

    #ifndef __MMI_BRW_RECENT_PAGES_SLIM__
        case SRV_BRW_LAUNCH_RECENT_PAGE:
        {
            srv_brw_load_recent_page_req(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.page_id);
            break;
        }
    #endif

    #ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
        case SRV_BRW_LAUNCH_STORED_PAGE:
        {
            srv_brw_load_stored_page_req(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.page_id);
            break;
        }
    #endif
    #ifdef __COSMOS_MMI_PACKAGE__
        case SRV_BRW_LAUNCH_SHORTCUT:
        {
            srv_brw_launch_global_shortcut(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.page_id);
            break;
        }
    #endif

        case SRV_BRW_LAUNCH_OPEN_FILE:
        {
            srv_brw_load_data_req(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.data);
            break;
        }

        case SRV_BRW_LAUNCH_REFRESH:
        {
            srv_brw_reload_req();
            break;
        }

        case SRV_BRW_LAUNCH_NONE:
        default:
        {
            ret = SRV_BRW_ERROR;
            break;
        }
    }
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.launch_type = SRV_BRW_LAUNCH_NONE;
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_release_sockets_req
 * DESCRIPTION
 *  This Interface is used for sending req to release the sockets
 * PARAMETERS
 *  void
 * RETURNS
 *  Request sending result of type srv_brw_error_enum
 *****************************************************************************/
srv_brw_error_enum srv_brw_release_sockets_req(srv_brw_act_req_struct *app_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_conn_closed_by_net_acc_id_req_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_save_user_app_req_data(MSG_ID_WAP_BAM_CONN_CLOSED_BY_NET_ACC_ID_RSP, app_data);
    myMsgPtr = (wap_bam_conn_closed_by_net_acc_id_req_struct*) OslConstructDataPtr(sizeof(wap_bam_conn_closed_by_net_acc_id_req_struct));

    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_closing_sockets = MMI_TRUE;
    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_CONN_CLOSED_BY_NET_ACC_ID_REQ, myMsgPtr, NULL);
    return SRV_BRW_ERROR_OK;
}

#endif


/*****************************************************************************
 * FUNCTION
 *  srv_brw_is_url_unreserved_char
 * DESCRIPTION
 *  To test a character if it is an URL-unreserved character.
 * PARAMETERS
 *  ch      [IN] Character
 * RETURNS
 *  MMI_TRUE:   Unreserved char
 *  MMI_FALSE:  Reserved
 *****************************************************************************/
static MMI_BOOL srv_brw_is_url_unreserved_char(const CHAR ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const CHAR MARK_CHARS[] = "-_.!~*'()"; /* See RFC-2396 */
    const CHAR *mark_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_brw_is_alphabet(ch) || srv_brw_is_digit(ch))
    {
        return MMI_TRUE;
    }

    for (mark_p = MARK_CHARS; *mark_p != '\0'; mark_p++)
    {
        if (*mark_p == ch)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_encode_url
 * DESCRIPTION
 *  Encode he string to the escaped encoding of URL for request form.
 * PARAMETERS
 *  dest            [OUT] Output string
 *  max_dest_len    [IN]  Maximum length of output string. NOTE this value is
 *                        not buffer size. dest[max_dest_len] may be filled
 *                        as '\0'
 *  raw_data        [IN]  Data to be encoded
 *  raw_data_size   [IN]  Data size
 *  truncated       [OUT] Will be set to MMI_TRUE if the string is truncated.
 *                        That is, the encoding should be longer than the
 *                        max_dest_len.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_encode_url(
    CHAR *dest,
    U32 max_dest_len, /* dest[max_dest_len] will be filled as '\0' in worst case */
    const CHAR* raw_data,
    U32 raw_data_size,
    MMI_BOOL *truncated)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 dest_len;
    CHAR ch;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_len = 0;
    
    for (i = 0; i < raw_data_size && (dest_len + 3) <= max_dest_len; i++)
    {
        ch = raw_data[i];

        if (srv_brw_is_url_unreserved_char(ch))
        {
            dest[dest_len++] = ch;
        }
        else if (ch == ' ') /* HTML 4.01 Specification */
        {
            dest[dest_len++] = '+';
        }
        else
        {
            U32 val;

            dest[dest_len++] = '%'; /* [0] */
            val = ((U32)ch >> 4) & 0xf;
            dest[dest_len++] = srv_brw_to_hex_char(val); /* [1] */
            val = ((U32)ch) & 0xf;
            dest[dest_len++] = srv_brw_to_hex_char(val); /* [2] */
        }
    }

    /* dest[max_dest_len] will be filled as '\0' in worst case */
    dest[dest_len] = '\0';

    if (truncated != NULL)
    {
        *truncated = (MMI_BOOL)(i >= raw_data_size);
    }
}

#ifdef __MMI_Q05A_LAUNCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_read_shortcut_list_data
 * DESCRIPTION
 *  This interface is for getting the  shortcuts List from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  NVRAM read operation error
 *****************************************************************************/
S16 srv_brw_read_shortcut_list_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_count;
    S16 NvramError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->shortcuts_p == NULL)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->shortcuts_p =
            (nvram_brw_shortcuts_item_struct*) srv_brw_malloc(NVRAM_EF_BRW_SHORTCUTS_LIST_RECORDS *
                                                           NVRAM_EF_BRW_SHORTCUTS_LIST_SIZE);
        memset(
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->shortcuts_p,
            0,
            (NVRAM_EF_BRW_SHORTCUTS_LIST_SIZE * NVRAM_EF_BRW_SHORTCUTS_LIST_RECORDS));
    }
    for (record_count = 1; record_count <= NVRAM_EF_BRW_SHORTCUTS_LIST_RECORDS; record_count++)
    {
        ReadRecord(
            NVRAM_EF_BRW_SHORTCUTS_LIST_LID,
            record_count,
            &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->shortcuts_p[(record_count - 1) * SHORTCUT_ENTERIES_PER_RECORD],
            NVRAM_EF_BRW_SHORTCUTS_LIST_SIZE,
            &NvramError);
    }
	return NvramError;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_shortcut_list_is_item_empty
 * DESCRIPTION
 *  This interface is for checking if shortcut item is empty or not
 * PARAMETERS
 *  void
 * RETURNS
 *  NVRAM read operation error
 *****************************************************************************/
MMI_BOOL srv_brw_shortcut_list_is_item_empty(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < SRV_BRW_MAX_SHORTCUTS_COUNT);
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->shortcuts_p[index].url[0] != '\0')
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_shortcuts_list_get_title
 * DESCRIPTION
 *  This interface is for getting the shortcut list item title
 * PARAMETERS
 *  void
 * RETURNS
 *  NVRAM read operation error
 *****************************************************************************/
U8* srv_brw_shortcuts_list_get_title(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < SRV_BRW_MAX_SHORTCUTS_COUNT);
    return (U8*)(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->shortcuts_p[index].title);
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_shortcuts_list_get_url
 * DESCRIPTION
 *  This interface is for getting the shortcut list item url
 * PARAMETERS
 *  void
 * RETURNS
 *  NVRAM read operation error
 *****************************************************************************/
U8* srv_brw_shortcuts_list_get_url(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < SRV_BRW_MAX_SHORTCUTS_COUNT);
    return (U8*)(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->shortcuts_p[index].url);
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_update_shortcut_info
 * DESCRIPTION
 *  This interface is for updating the information of a particular shortcut
 * PARAMETERS
 *  void
 * RETURNS
 *  NVRAM read operation error
 *****************************************************************************/
void srv_brw_update_shortcut_info(U8 index, U8* title, U8* url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(index < SRV_BRW_MAX_SHORTCUTS_COUNT);
    mmi_ucs2ncpy((S8*)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->shortcuts_p[index].title, (S8*) title, SRV_BRW_BKM_MAX_FILE_NAME_LEN);
    mmi_ucs2_to_asc((S8*)g_srv_brw_cntx.srv_brw_dynamic_cntx_p->shortcuts_p[index].url, (S8*) url);
    srv_brw_shortcuts_list_update_data();
}

#endif /* __MMI_Q05A_LAUNCH_SCREEN__ */
/*****************************************************************************
 * FUNCTION
 *  srv_brw_open_bearer_rsp
 * DESCRIPTION
 *  This interface is for updating the information of a particular shortcut
 * PARAMETERS
 *  void
 * RETURNS
 *  NVRAM read operation error
 *****************************************************************************/
void srv_brw_open_bearer_rsp(U8 error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_bam_bearer_open_response_rsp_struct *myMsgPtr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    myMsgPtr =
        (wap_bam_bearer_open_response_rsp_struct*) OslConstructDataPtr(sizeof(wap_bam_bearer_open_response_rsp_struct));

    myMsgPtr->instance_id = g_srv_brw_cntx.brw_instance_id;
    myMsgPtr->error_code = error_code;

    srv_brw_event_hdlr_send_ilm(MSG_ID_WAP_BAM_BEARER_OPEN_RSP, myMsgPtr, NULL);
}

#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERSRVINTERFACE_C */
