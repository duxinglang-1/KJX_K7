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
 * BrowserSrvMain.c
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"
#ifndef MMI_BROWSERSRVMAIN_C
#define MMI_BROWSERSRVMAIN_C

/*  Include: MMI header file */

#ifdef __MMI_BROWSER_2__

#include "app_ltlcom.h"
#include "BrowserSrvMain.h"
#include "app_url.h"
#include "Cbm_api.h"
#include "BrowserSrvProts.h"
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "Unicodexdcl.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "string.h"
#include "WAPProfileSrvType.h"
#include "MMI_inet_app_trc.h"
#include "kal_trace.h"
#include "WAPProfileSrvGProt.h"
#include "custom_wap_config.h"
#include "common_nvram_editor_data_item.h"
#include "mmi_frm_nvram_gprot.h"
#include "nvram_common_defs.h"
#include "wps_struct.h"
#include "custom_mmi_default_value.h"
#include "bam_struct.h"
#include "fs_type.h"
#include "fs_func.h"
#include "BrowserSrvBookmarks.h"
#include "FileMgrSrvGProt.h"
#include "stdio.h"
#include "BrowserSrvConfig.h"
#include "DtcntSrvGprot.h"
#include "BrowserSrvInterface.h"

srv_brw_context_struct g_srv_brw_cntx;
void *g_srv_brw_memory_pool = NULL;
/*****************************************************************************
 * FUNCTION
 *  srv_brw_malloc_ex
 * DESCRIPTION
 *  This function is used to allocate memory chunk 
 * PARAMETERS
 *  void
 * RETURNS
 *  Pointer to memory or NULL otherwise
 *****************************************************************************/
#ifdef BRW_MEM_LEAK_DEBUG_MODE
void *srv_brw_malloc_ex(U32 mem_size, S8 *filename, U32 line_num)
#else
void *srv_brw_malloc_ex(U32 mem_size)
#endif /* BRW_MEM_LEAK_DEBUG_MODE */
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *pMemory;
    U32 avail_mem;
#ifdef BRW_MEM_LEAK_DEBUG_MODE
    S8 *file_name_ptr;
    U32 index;
#endif /* BRW_MEM_LEAK_DEBUG_MODE */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mem_size);
    MMI_ASSERT(g_srv_brw_cntx.brw_adm_id);

    avail_mem = kal_adm_get_total_left_size(g_srv_brw_cntx.brw_adm_id);
    MMI_ASSERT(avail_mem >= mem_size);

    pMemory = kal_adm_alloc(g_srv_brw_cntx.brw_adm_id, mem_size);
    MMI_ASSERT(pMemory);

#ifdef BRW_MEM_LEAK_DEBUG_MODE
    for (index = 0; index < BRW_MEM_ALLOC_MAX_LIST_SIZE; index++)
    {
        if (g_srv_brw_mem_alloc_cntx[index].mem_ptr == NULL)
        {
            file_name_ptr = (S8*) strrchr((const S8*)filename, (S8) '\\');
            strncpy(
                (S8*) g_srv_brw_mem_alloc_cntx[index].filename,
                (S8*) file_name_ptr + 1,
                BRW_MEM_ALLOC_FILENAME_SIZE - 1);
            g_srv_brw_mem_alloc_cntx[index].filename[BRW_MEM_ALLOC_FILENAME_SIZE - 1] = '\0';
            g_srv_brw_mem_alloc_cntx[index].line_num = line_num;
            g_srv_brw_mem_alloc_cntx[index].mem_size = mem_size;
            g_srv_brw_mem_alloc_cntx[index].mem_ptr = pMemory;
            break;
        }
    }
#endif /* BRW_MEM_LEAK_DEBUG_MODE */ 
	return pMemory;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_free
 * DESCRIPTION
 *  This function is used to de - allocate the given memory chunk 
 * PARAMETERS
 *  Memory pointer to be free
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_free(void *pMemory)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef BRW_MEM_LEAK_DEBUG_MODE
    U32 index;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pMemory)
    {
        MMI_ASSERT(g_srv_brw_cntx.brw_adm_id);

    #ifdef BRW_MEM_LEAK_DEBUG_MODE
        for (index = 0; index < BRW_MEM_ALLOC_MAX_LIST_SIZE; index++)
        {
            if (g_srv_brw_mem_alloc_cntx[index].mem_ptr == pMemory)
            {
                g_srv_brw_mem_alloc_cntx[index].mem_ptr = NULL;
                break;
            }
        }
    #endif /* BRW_MEM_LEAK_DEBUG_MODE */ 

        kal_adm_free(g_srv_brw_cntx.brw_adm_id, pMemory);
        pMemory = NULL;
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_dynamic_list_free_memory
 * DESCRIPTION
 *  This function is used to de - allocate a given type of dynamic list 
 * PARAMETERS
 *  Memory pointer to be free
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_dynamic_list_free_memory(srv_brw_list_type_enum list_type)
{
	switch (list_type)
	{
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
        case SRV_BRW_LIST_TYPE_ADDRESS_LIST:
        {
            srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p));
			srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p));
            break;
        }
#endif /* __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */
        case SRV_BRW_LIST_TYPE_DYNAMIC_LIST:
		{
			U32 index;
			for (index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count; index++)
			{
				srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].name));
				srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].host));
			}
			srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list));
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count = 0;
			break;
		}
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
		case SRV_BRW_LIST_TYPE_RECENT_PAGES_LIST:
		{
			srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_list));
			srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_info_p));
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_count = 0;
			break;
		}
#endif
#ifdef OBIGO_Q05A
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
		case SRV_BRW_LIST_TYPE_RECENT_PAGES_HOST_LIST:
		{
			U32 index;
			for (index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_count; index++)
			{
				srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_list[index]));
			}
			srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_list));
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->recent_page_host_count = 0;
			break;
		}
#endif
		case SRV_BRW_LIST_TYPE_PAGE_OBJECTS_LIST:
		{
			srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_image_list));
			srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_bg_image_list));
			srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_sound_list));
			srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_others_list));

			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->page_objs_images_count = 0;
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->page_objs_bg_images_count = 0;
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->page_objs_sounds_count = 0;
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->page_objs_others_count = 0;
			break;
		}
#endif /* OBIGO_Q05A */
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
        case SRV_BRW_LIST_TYPE_SAVED_PAGES_LIST:
		{
			U32 index;
			for (index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_list_item_count; index++)
			{
				srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_pages_list_p[index].name));
			}
			srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_pages_list_p));
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_list_item_count = 0;
			break;
		}
#endif
#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
        case SRV_BRW_LIST_TYPE_SEARCH_LIST:
        {
            srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p));
            break;
        }
#endif /* #if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__) */
#ifdef __COSMOS_MMI_PACKAGE__
        case SRV_BRW_LIST_TYPE_GLOBAL_SHORTCUTS:
		{
            srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->global_shortcuts_p));
			break;
		}
    #ifndef __MMI_BRW_SLIM__
        case SRV_BRW_LIST_TYPE_LOCAL_SHORTCUTS:
		{
            srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->local_shortcuts_p));
			break;
		}
    #endif
#endif /* __COSMOS_MMI_PACKAGE__ */
#ifdef __MMI_Q05A_LAUNCH_SCREEN__
        case SRV_BRW_LIST_TYPE_SHORTCUT_LIST:
        {
            srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->shortcuts_p));
            break;
        }
#endif
	}
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_validate_url
 * DESCRIPTION
 *  Utility function to validate the url.
 * PARAMETERS
 *  url_p       [IN]        Url in unicode to be validated
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_brw_validate_url(U8 *url_p, U16 url_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (srv_brw_validate_url_ex(url_p, url_length, MMI_TRUE));
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_validate_url_ex
 * DESCRIPTION
 *  Utility function to validate the url.
 * PARAMETERS
 *  url_p       [IN]        Url in unicode to be validated
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_brw_validate_url_ex(U8 *url_p, U16 url_length, MMI_BOOL is_http_scheme_needed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *temp;
    U8 *url_ascii;
    U8 uri_schm_len;
    applib_url_struct url_info;
    S32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(url_p);

    /* check the zero length and white spaces in the URL string */
    if (!mmi_ucs2strlen((S8*) url_p))
    {
        return APPLIB_URL_ERR_INVALID_PARAM;
    }

    url_ascii = OslMalloc(url_length + 1);
    memset(url_ascii, 0, url_length + 1);
    /* convert the UCS2 URL string into ASCII */
    mmi_ucs2_n_to_asc((S8*) url_ascii, (S8*) url_p, url_length * ENCODING_LENGTH);

    /* parse the URL string by using Applib API */
    if (!(S32) applib_parse_url((S8*) url_ascii, &url_info))
    {
        /* if there is an empty URI scheme in the URL then append the default ("http://") */
        /* URI scheme */
        if (url_info.scheme_type == applib_scheme_empty)
        {
            if(!is_http_scheme_needed)
            {
                OslMfree(url_ascii);
                return APPLIB_URL_ERR_INVALID_SCHEME;
            }
            temp = OslMalloc(url_length + 1);
            memset(temp, 0, url_length + 1);
            uri_schm_len = strlen((S8*) SRV_BRW_DEFAULT_URI_SCHEME);
            if (strlen((S8*) url_ascii) > (U16)(url_length - uri_schm_len))
            {
                strncpy((S8*) temp, (S8*) url_ascii, url_length - uri_schm_len);
            }
            else
            {
                strcpy((S8*) temp, (S8*) url_ascii);
            }
            strcpy((S8*) url_ascii, (S8*) SRV_BRW_DEFAULT_URI_SCHEME);
            strcat((S8*) url_ascii, (S8*) temp);
            OslMfree(temp);
            /* check whether it contain HTTP or HTTPS URI scheme with empty host */
            if (!(S32) applib_parse_url((S8*) url_ascii, &url_info))
            {
                if (url_info.scheme_type == applib_scheme_http || url_info.scheme_type == applib_scheme_https)
                {
                    if (!url_info.len[APPLIB_URL_HOST_PART])
                    {
                        result = APPLIB_URL_ERR_INVALID_HOST;
                    }
                }
            }
        }
        /* check whether it contain HTTP or HTTPS URI scheme with empty host */
        else if (url_info.scheme_type == applib_scheme_http || url_info.scheme_type == applib_scheme_https)
        {
            if (!url_info.len[APPLIB_URL_HOST_PART])
            {
                result = APPLIB_URL_ERR_INVALID_HOST;
            }
        }
    }

    if (result < 0)
    {
        OslMfree(url_ascii);
        return result;
    }

    /* validate the UTF-8 URL string by using Applib API */
    result = (S32) applib_url_is_valid((S8*) url_ascii);
    if (result >= 0)
    {
        mmi_asc_n_to_ucs2((S8*) url_p, (S8*) url_ascii, url_length);
    }
    OslMfree(url_ascii);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_bearer_type
 * DESCRIPTION
 *  On basis of account id, fill in the bearer type via Data account
 * PARAMETERS
 *  bearer_type [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_bearer_type (U8 *bearer_type_p)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_wap_prof_profile_content_struct *profile_content_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_get_profile_content((void**)&profile_content_p);
    
    *bearer_type_p = srv_dtcnt_get_bearer_type(profile_content_p->data_account_primary_id, SRV_DTCNT_ACCOUNT_PRIMARY);

    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_GET_BEARER_TYPE, SRV_DTCNT_ACCOUNT_PRIMARY, *bearer_type_p);

    OslMfree(profile_content_p);
    return;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_bearer_type
 * DESCRIPTION
 *	Ask UPP for currently active profile contents
 * PARAMETERS
 *  profile_content_p [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_profile_content (void **profile_content_p)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.srv_brw_profile_type == SRV_BRW_PROFILE_TYPE_OPERATOR)
    {
        *profile_content_p =
            (srv_wap_prof_profile_content_struct*) srv_wap_prof_get_profile_content(
                                                    srv_brw_convert_sim_setting_to_profile_sim_id(g_srv_brw_cntx.session_sim_id),
                                                    SRV_WAP_PROF_APPID_BRW,
                                                    (U8) SRV_BRW_OPERATOR_DEFAULT_PROF_INDEX,
                                                    (srv_wap_prof_dtcnt_count_enum)SRV_DTCNT_ACCOUNT_PRIMARY,
                                                    NULL);

    }
    else
    {
        *profile_content_p =
            (srv_wap_prof_profile_content_struct*) srv_wap_prof_get_profile_content(
                                                    srv_brw_convert_sim_setting_to_profile_sim_id(g_srv_brw_cntx.session_sim_id),
                                                    SRV_WAP_PROF_APPID_BRW,
                                                    (U8) - 1,
                                                    (srv_wap_prof_dtcnt_count_enum)SRV_DTCNT_ACCOUNT_PRIMARY,
                                                    NULL);
    }

    MMI_TRACE(
        MMI_INET_TRC_G4_BRW,
        MMI_BRW_GET_PROFILE_CONTENT,
        ((srv_wap_prof_profile_content_struct*) (*profile_content_p))->data_account_primary_id,
        ((srv_wap_prof_profile_content_struct*) (*profile_content_p))->conn_type);
    return;
}

#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  srv_brw_address_list_update_data
 * DESCRIPTION
 *  Function to save given data based on act_type in NVRAM
 * PARAMETERS
 *	act_type	[IN]		Type of action to be taken
 *  title_p     [IN]        Title to be saved
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_address_list_update_data(srv_brw_list_action_enum act_type, U8 *title_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_count;
    S16 NvramError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(act_type)
    {
    case SRV_BRW_LIST_ACTION_UPDATE_ENTIRE_LIST:
		/*----------------------------------------------------------------*/
		/* Code Body                                                      */
		/*----------------------------------------------------------------*/
		for (record_count = 1; record_count <= NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS; record_count++)
		{
			WriteRecord(
				NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_LID,
				record_count,
				&g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[(record_count - 1) * TITLES_PER_RECORD],
				NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE,
				&NvramError);
		}

		for (record_count = 1; record_count <= NVRAM_BRW_NUM_ADDRESS_HISTORY_URL_RECORDS; record_count++)
		{
			WriteRecord(
				NVRAM_EF_BRW_ADDRESS_HISTORY_URL_LID,
				record_count,
				&g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p[(record_count - 1) * URLS_PER_RECORD],
				NVRAM_BRW_ADDRESS_HISTORY_URL_SIZE,
				&NvramError);
		}
        break;
    case SRV_BRW_LIST_ACTION_UPDATE_TITLE_ONLY:
		if (srv_phb_check_ucs2_character((U16*) title_p))
		{
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[0].dcs = SRV_BRW_DCS_UCS;
			memset(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[0].title, 0, NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH);
			mmi_ucs2ncpy(
				(S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[0].title,
				(S8*) title_p,
				NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH / ENCODING_LENGTH);
		}
		else
		{
			g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[0].dcs = SRV_BRW_DCS_ASCII;
			memset(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[0].title, 0, NVRAM_BRW_ADDRESS_HISTORY_MAX_TITLE_LENGTH);
			mmi_ucs2_n_to_asc(
				(S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[0].title,
				(S8*) title_p,
				mmi_ucs2strlen((S8*) title_p) * ENCODING_LENGTH);
		}

		/* Only Title needs to be updated */
		for (record_count = 1; record_count <= NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS; record_count++)
		{
			WriteRecord(
				NVRAM_EF_BRW_ADDRESS_HISTORY_TITLE_LID,
				record_count,
				&g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p[(record_count - 1) * TITLES_PER_RECORD],
				NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE,
				&NvramError);
		}
		break;
	default:
		break;
	}
}
#endif /* __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  srv_brw_set_bearer
 * DESCRIPTION
 *  This func is used for holding or releasing the bearer
 * PARAMETERS
 *  hold_bearer     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_set_bearer(MMI_BOOL hold_bearer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_prof_profile_content_struct *profile_content_p;
    U8 app_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_holding_bearer = hold_bearer;

    srv_brw_get_profile_content((void **)&profile_content_p);
    app_id = cbm_get_app_id(profile_content_p->data_account_primary_id);

    MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_SET_BEARER, profile_content_p->data_account_primary_id, app_id);

    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_holding_bearer)
    {
        MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_HOLD_BEARER);
        cbm_hold_bearer(app_id);
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_RELEASE_BEARER);
        cbm_release_bearer(app_id);
    }

    OslMfree(profile_content_p);

    return;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_is_holding_bearer
 * DESCRIPTION
 *  This func is used for returning the current bearer status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_brw_is_holding_bearer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p)
    {
        MMI_TRACE(MMI_INET_TRC_G4_BRW, MMI_BRW_IS_HOLDING_BEARER, g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_holding_bearer);

        return g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_holding_bearer;
    }
    else
    {
        return MMI_FALSE;
    }
}

#ifdef __MMI_OP12_BRW_CLEAR_DATA_ON_SIM_CHANGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_brw_clear_session_info_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL(?)
 *****************************************************************************/
void mmi_brw_clear_session_info_handler(S32 user_data, U32 result, void *obj)
{
    if (g_srv_brw_cntx.clear_brw_data_flag)
    {
        g_srv_brw_cntx.clear_brw_data_flag = MMI_FALSE;
    }
}

#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_address_list_delete_all_items_on_sim_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL(?)
 *****************************************************************************/
void srv_brw_address_list_delete_all_items_on_sim_change(void)
{
    if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_title_p =
            (nvram_brw_hist_title_struct*) srv_brw_malloc(NVRAM_BRW_NUM_ADDRESS_HISTORY_TITLE_RECORDS *
                                                           NVRAM_BRW_ADDRESS_HISTORY_TITLE_SIZE);
    }
    if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_url_p =
            (nvram_brw_hist_url_struct*) srv_brw_malloc(NVRAM_BRW_NUM_ADDRESS_HISTORY_URL_RECORDS *
                                                         NVRAM_BRW_ADDRESS_HISTORY_URL_SIZE);
    }
    srv_brw_address_list_delete_all_items();
}
#endif /* __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  srv_brw_clear_browser_data_on_sim_change
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  pBOOL(?)
 *****************************************************************************/
void srv_brw_clear_browser_data_on_sim_change(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
    S16 error;
#endif /* __MMI_BRW_ADVANCED_APP_FEATURES__ */
    srv_brw_act_req_struct obj = {0};
	srv_brw_list_element_req_struct data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    obj.rsp_callback = mmi_brw_clear_session_info_handler;
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
    srv_brw_delete_all_recent_pages_req(&obj);
#endif
	data.index = WPS_CLEAR_CACHE_ALL;
	obj.req_data = (void*)&data;
	srv_brw_settings_clear_data_req(&obj);
 	data.index = WPS_CLEAR_COOKIES_ALL;
	obj.req_data = (void*)&data;
    srv_brw_settings_clear_data_req(&obj);
 	data.index = WPS_CLEAR_AUTH_ALL;
	obj.req_data = (void*)&data;
    srv_brw_settings_clear_data_req(&obj);
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
    srv_brw_address_list_delete_all_items_on_sim_change();
#endif /* __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */

#ifdef __MMI_BRW_ADVANCED_APP_FEATURES__
    /* Updating and writing into NMRAM the last web address */
    WriteRecord(
        NVRAM_EF_BRW_LAST_WEB_ADDR_LID,
        1,
        "",
        NVRAM_EF_BRW_LAST_WEB_ADDR_SIZE,
        &error);
#endif /* __MMI_BRW_ADVANCED_APP_FEATURES__ */
}
#endif /* __MMI_OP12_BRW_CLEAR_DATA_ON_SIM_CHANGE__ */ 


#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  srv_brw_recent_page_update_sorting_method
 * DESCRIPTION
 *  This func is used for storing the sorting method if the previously selected
 *  and the newly selected sorting method are different
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_recent_page_update_sorting_method(U8 sorting_method)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_brw_cntx.sorting_method = sorting_method;
    srv_brw_update_settings_data(SRV_BRW_NVRAM_RECENT_PAGES_SORTING_METHOD);
}
#endif /* OBIGO_Q05A */
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_ren_page_select_mode_activate
 * DESCRIPTION
 *  This function is used for activating the select mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_ren_page_select_mode_activate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__
    //g_srv_brw_cntx.srv_brw_dynamic_cntx_p->select_mode_flag = MMI_TRUE;
#endif

    srv_brw_navigation_change_req(WAP_BAM_FOCUSABLE_ELEMENTS_OBJECT_MODE);
}


#ifdef OBIGO_Q05A
/*****************************************************************************
 * FUNCTION
 *  srv_brw_create_rendered_page_object_lists
 * DESCRIPTION
 *  This function is used to classify and group various page objects
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_create_rendered_page_object_lists(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    U32 tmp_img_cnt = 0;
    U32 tmp_bg_img_cnt = 0;
    U32 tmp_sound_cnt = 0;
    U32 tmp_other_cnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count; index++)
    {
        if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].type == WAP_BAM_RSRC_TYPE_IMAGE)
        {
            ++tmp_img_cnt;
        }
        else if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].type == WAP_BAM_RSRC_TYPE_BACKGROUND)
        {
            ++tmp_bg_img_cnt;
        }
        else if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].type == WAP_BAM_RSRC_TYPE_SOUND)
        {
            ++tmp_sound_cnt;
        }
        else if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].type == WAP_BAM_RSRC_TYPE_OTHER)
        {
            ++tmp_other_cnt;
        }
    }

    if (tmp_img_cnt)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_image_list = srv_brw_malloc(tmp_img_cnt * sizeof(srv_brw_page_object_struct));
    }
    if (tmp_bg_img_cnt)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_bg_image_list = srv_brw_malloc(tmp_bg_img_cnt * sizeof(srv_brw_page_object_struct));
    }
    if (tmp_sound_cnt)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_sound_list = srv_brw_malloc(tmp_sound_cnt * sizeof(srv_brw_page_object_struct));
    }
    if (tmp_other_cnt)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_others_list = srv_brw_malloc(tmp_other_cnt * sizeof(srv_brw_page_object_struct));
    }

    for (index = 0; index < g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list_count; index++)
    {
        if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].type == WAP_BAM_RSRC_TYPE_IMAGE)
        {
           g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_image_list[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->page_objs_images_count++].res_list_index = index;
        }
        else if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].type == WAP_BAM_RSRC_TYPE_BACKGROUND)
        {
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_bg_image_list[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->page_objs_bg_images_count++].res_list_index = index;
        }
        else if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].type == WAP_BAM_RSRC_TYPE_SOUND)
        {
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_sound_list[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->page_objs_sounds_count++].res_list_index = index;
        }
        else if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[index].type == WAP_BAM_RSRC_TYPE_OTHER)
        {
            g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_others_list[g_srv_brw_cntx.srv_brw_dynamic_cntx_p->page_objs_others_count++].res_list_index = index;
        }
    }

    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->page_objs_images_count)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_object_type[SRV_BRW_PAGE_OBJECT_TYPE_IMAGE] = MMI_TRUE;
    }
    else
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_object_type[SRV_BRW_PAGE_OBJECT_TYPE_IMAGE] = MMI_FALSE;
    }

    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->page_objs_bg_images_count)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_object_type[SRV_BRW_PAGE_OBJECT_TYPE_BG_IMAGE] = MMI_TRUE;
    }
    else
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_object_type[SRV_BRW_PAGE_OBJECT_TYPE_BG_IMAGE] = MMI_FALSE;
    }

    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->page_objs_sounds_count)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_object_type[SRV_BRW_PAGE_OBJECT_TYPE_SOUNDS] = MMI_TRUE;
    }
    else
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_object_type[SRV_BRW_PAGE_OBJECT_TYPE_SOUNDS] = MMI_FALSE;
    }

    if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->page_objs_others_count)
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_object_type[SRV_BRW_PAGE_OBJECT_TYPE_OTHERS] = MMI_TRUE;
    }
    else
    {
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_object_type[SRV_BRW_PAGE_OBJECT_TYPE_OTHERS] = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_page_object_types_count
 * DESCRIPTION
 *  This function is used for counting the total number of page object types
 * PARAMETERS
 *  count_p     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_page_object_types_count(U8 *count_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *count_p = 0;

    while (index < SRV_BRW_PAGE_OBJECT_TYPES_COUNT)
    {
        if (g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_object_type[index] == MMI_TRUE)
        {
            ++(*count_p);
        }
        ++index;
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_page_objects_count
 * DESCRIPTION
 *  This function is used for getting number count for a given object type
 * PARAMETERS
 *  obj_type          [IN]                  
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_brw_get_page_objects_count(srv_brw_page_object_types_enum obj_type)
{
	U8 count;
	switch(obj_type)
	{
		case SRV_BRW_PAGE_OBJECT_TYPE_IMAGE:
			count = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->page_objs_images_count;
			break;
		case SRV_BRW_PAGE_OBJECT_TYPE_BG_IMAGE:
			count = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->page_objs_bg_images_count;
			break;
		case SRV_BRW_PAGE_OBJECT_TYPE_SOUNDS:
			count = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->page_objs_sounds_count;
			break;
		case SRV_BRW_PAGE_OBJECT_TYPE_OTHERS:
			count = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->page_objs_others_count;
			break;
		default:
			count = 0;
			break;
	}
	return count;
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_page_objects_get_item
 * DESCRIPTION
 *  This function is used for getting info for an object of a given type at nth
	index
 * PARAMETERS
 *  item_index          [IN]        
 *  str_buff            [IN]                
 *          
 * RETURNS
 *  void
 *****************************************************************************/
U8* srv_brw_page_objects_get_item(srv_brw_page_object_types_enum obj_type, S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 dynamic_list_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (obj_type)
    {
        case SRV_BRW_PAGE_OBJECT_TYPE_IMAGE:
            dynamic_list_index = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_image_list[item_index].res_list_index;
            break;

        case SRV_BRW_PAGE_OBJECT_TYPE_BG_IMAGE:
            dynamic_list_index = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_bg_image_list[item_index].res_list_index;
            break;

        case SRV_BRW_PAGE_OBJECT_TYPE_SOUNDS:
            dynamic_list_index = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_sound_list[item_index].res_list_index;
            break;

        case SRV_BRW_PAGE_OBJECT_TYPE_OTHERS:
            dynamic_list_index = g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_page_objs_others_list[item_index].res_list_index;
            break;
        default:
            return FALSE;
    }
	return ((U8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->dynamic_list[dynamic_list_index].name);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_brw_page_objects_get_object_res_list_index
 * DESCRIPTION
 *  This function is used for getting the actual resource list index of a
 *  selected page object
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_brw_get_page_objects_res_list_index(srv_brw_page_object_types_enum obj_type, S32 hilited_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 actual_res_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (obj_type)
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
 *  srv_brw_save_user_app_req_data
 * DESCRIPTION
 *  This function is used for saving the Request data sent by application
 * PARAMETERS
 *  app_req_data -- Application requested user data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_save_user_app_req_data(U16 rsp_msg_id, srv_brw_act_req_struct *app_req_data)
{
    U8 index;
    for(index = 0; index < SRV_BRW_RSP_CALLBACK_COUNT; index++)
    {
        if(g_srv_brw_cntx.rsp_callback[index].msg_id == 0)
        {
            break;
        }
    }
    MMI_ASSERT(index < SRV_BRW_RSP_CALLBACK_COUNT);

    g_srv_brw_cntx.rsp_callback[index].msg_id = rsp_msg_id;
    g_srv_brw_cntx.rsp_callback[index].srv_brw_rsp_cntx_p.user_data = (S32)app_req_data->user_data;
    g_srv_brw_cntx.rsp_callback[index].srv_brw_rsp_cntx_p.rsp_callback = app_req_data->rsp_callback;
    g_srv_brw_cntx.rsp_callback[index].srv_brw_rsp_cntx_p.req_data = app_req_data->req_data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_call_user_app_req_data
 * DESCRIPTION
 *  This function is used for retreiving the requested data provided by the app
 * when calling the service request sending apis and then calling the callback
 * function provided by the application
 * PARAMETERS
 *  app_req_data -- Application requested user data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_call_user_app_req_data(U16 rsp_msg_id, U32 result, void *rsp_data)
{
    U8 index;
    srv_brw_act_req_struct req_data;
    for(index = 0; index < SRV_BRW_RSP_CALLBACK_COUNT; index++)
    {
        if(g_srv_brw_cntx.rsp_callback[index].msg_id == rsp_msg_id)
        {
            break;
        }
    }
    MMI_ASSERT(index < SRV_BRW_RSP_CALLBACK_COUNT);

    g_srv_brw_cntx.rsp_callback[index].msg_id = 0;
    req_data.user_data = g_srv_brw_cntx.rsp_callback[index].srv_brw_rsp_cntx_p.user_data;
    req_data.rsp_callback = g_srv_brw_cntx.rsp_callback[index].srv_brw_rsp_cntx_p.rsp_callback;

	req_data.rsp_callback(req_data.user_data, (U16)(result), rsp_data);
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_get_user_app_req_data
 * DESCRIPTION
 *  This function is used for retreiving the requested data provided by the app
 * when calling the service request sending apis and then calling the callback
 * function provided by the application
 * PARAMETERS
 *  app_req_data -- Application requested user data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_get_user_app_req_data(U16 rsp_msg_id, srv_brw_act_req_struct* req_data)
{
    U8 index;
    for(index = 0; index < SRV_BRW_RSP_CALLBACK_COUNT; index++)
    {
        if(g_srv_brw_cntx.rsp_callback[index].msg_id == rsp_msg_id)
        {
            break;
        }
    }
    MMI_ASSERT(index < SRV_BRW_RSP_CALLBACK_COUNT);

    g_srv_brw_cntx.rsp_callback[index].msg_id = 0;
    req_data->user_data = g_srv_brw_cntx.rsp_callback[index].srv_brw_rsp_cntx_p.user_data;
    req_data->rsp_callback = g_srv_brw_cntx.rsp_callback[index].srv_brw_rsp_cntx_p.rsp_callback;    
    req_data->req_data = g_srv_brw_cntx.rsp_callback[index].srv_brw_rsp_cntx_p.req_data;    
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_free_OSL_memory
 * DESCRIPTION
 *  This func is used to free the OSL memory if allocated by the pointer
 * passed as argument to it(NULL check) and then set the pointer to NULL
 * PARAMETERS
 *  ptr        [IN|OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_free_OSL_memory(void **ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT (ptr);

    if (*ptr != NULL)
    {
        OslMfree(*ptr);
        *ptr = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_global_context_init
 * DESCRIPTION
 *  To initialize the global Service context at boot up
 * PARAMETERS
 *  ptr        [IN|OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_global_context_init(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 def_drive_str[SRV_BRW_BKM_DRIVE_NAME_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_brw_cntx.isWapReady = MMI_FALSE;
    g_srv_brw_cntx.is_resend_profile_required = MMI_FALSE;
#if (MMI_MAX_SIM_NUM >= 2)
    g_srv_brw_cntx.is_profile_req_received = MMI_TRUE;
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    g_srv_brw_cntx.http_auth_info_p = NULL;
    g_srv_brw_cntx.screen_size_status = 0;
    g_srv_brw_cntx.brw_instance_id = 0;
#ifdef __SAT__
    g_srv_brw_cntx.sat_gateway_ascii = NULL;
#endif 
    g_srv_brw_cntx.srv_brw_profile_type = SRV_BRW_PROFILE_TYPE_NONE;
#ifdef __MMI_OP12_BRW_CLEAR_DATA_ON_SIM_CHANGE__
    g_srv_brw_cntx.clear_brw_data_flag = MMI_FALSE; 
#endif
#ifdef __MMI_DOWNLOAD_AGENT_MULTI_DL__
    g_srv_brw_cntx.download_info_p = NULL;
#endif  	
    g_srv_brw_cntx.sap_msg_id = 0;
#ifdef __COSMOS_MMI_PACKAGE__
    g_srv_brw_cntx.session_sim_id = SRV_BRW_ACTIVE_SIM_SETTING_SIM1;
#else
    g_srv_brw_cntx.session_sim_id = SRV_BRW_ACTIVE_SIM_SETTING_TOTAL;
#endif

#if (defined(__SAT__) && defined(__MMI_WLAN_FEATURES__))
    g_srv_brw_cntx.app_type = SRV_BRW_APPTYPE_NONE;
#endif
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p = NULL;
    g_srv_brw_cntx.is_create_instance_processing = MMI_FALSE;
#ifdef __MMI_VBOOKMARK__
    g_srv_brw_cntx.bookmark_count = 0;
	sprintf((S8*) def_drive_str, "%c", SRV_BRW_BKM_DEFAULT_DRIVE);

    mmi_asc_to_ucs2((S8*) g_srv_brw_cntx.default_folder_path, (S8*) def_drive_str);
    mmi_ucs2cat((S8*) g_srv_brw_cntx.default_folder_path, (S8*) L":\\");
    mmi_ucs2cat((S8*) g_srv_brw_cntx.default_folder_path, (S8*) SRV_BRW_BKM_DEFAULT_FOLDER_NAME);
    srv_brw_bookmarks_create_root_folder_and_files();
#endif /* __MMI_VBOOKMARK__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_dynamic_context_init
 * DESCRIPTION
 *  To initialize the Dynamic service while entering the WAP menu
 * PARAMETERS
 *  ptr        [IN|OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_dynamic_context_init(void)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p = srv_brw_malloc(sizeof(srv_brw_dynamic_context_struct));
    memset(g_srv_brw_cntx.srv_brw_dynamic_cntx_p, 0, sizeof(srv_brw_dynamic_context_struct));

    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isBrowserFetching = MMI_FALSE;
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->address_list_flag = MMI_FALSE;
#endif /* __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->view_cert_flag = MMI_FALSE;
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->ext_obj_trans_status = MMI_FALSE;
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->isDeleteInsReqPending = MMI_FALSE;

    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_holding_bearer = MMI_FALSE;


#ifdef __MMI_BRW_POST_SESSION_INFO__
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_bytes_downloaded = 0;
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_bytes_uploaded = 0;
#endif /* __MMI_BRW_POST_SESSION_INFO__ */ 
     
   // g_srv_brw_cntx.srv_brw_dynamic_cntx_p->requested_url_p = NULL;
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->is_bearer_active = MMI_FALSE;
#ifdef __COSMOS_MMI_PACKAGE__
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->select_mode_flag = MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_brw_free_browser_memory
 * DESCRIPTION
 *  This func is used to free the Browser memory if allocated by the pointer
 * passed as argument to it and then set the pointer to NULL
 * PARAMETERS
 *  ptr        [IN|OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_free_browser_memory(void **ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT (ptr);

    if (*ptr != NULL)
    {
        srv_brw_free(*ptr);
        *ptr = NULL;
    }
} 

/*****************************************************************************
 * FUNCTION
 *  srv_brw_dynamic_context_deinit
 * DESCRIPTION
 *  To De - initialize the Dynamic service on reaching idle screen
 * PARAMETERS
 *  ptr        [IN|OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_dynamic_context_deinit(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_brw_bkm_deinitialize_bookmark_context();
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p != NULL)
    {
        srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_status_info_p));
#ifdef OBIGO_Q05A
        srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->brw_res_item_info_p));
#endif /* OBIGO_Q05A */
#ifndef SLIM_WAP_MMS
        srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_list));
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->do_element_count = 0;
#endif

        srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->document_info_p));
        srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->focused_element_info_p));
#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
       srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_SAVED_PAGES_LIST);
        srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->saved_page_properties_p));
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */
#ifdef __MMI_BRW_POST_SESSION_INFO__
        srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->start_session_data_time));
#endif
#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
		srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_ADDRESS_LIST);
#endif /* __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__ */
		srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_DYNAMIC_LIST);
#ifdef OBIGO_Q05A
#ifndef __MMI_BRW_RECENT_PAGES_SLIM__
		srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_RECENT_PAGES_HOST_LIST);
#endif
		srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_PAGE_OBJECTS_LIST);
#endif /* OBIGO_Q05A */
#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
        srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_SEARCH_LIST);
#endif
#ifdef __COSMOS_MMI_PACKAGE__
		srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_GLOBAL_SHORTCUTS);
    #ifndef __MMI_BRW_SLIM__
		srv_brw_dynamic_list_free_memory(SRV_BRW_LIST_TYPE_LOCAL_SHORTCUTS);
    #endif
#endif
#ifdef MMI_BRW_BEARER_SWITCH_SUPPORT
        srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->relaunch_info.data));
#endif
        srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p));
    }
}

#ifndef __MMI_BRW_USER_DEFINED_HOMEPAGE_SLIM__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_update_user_defined_homepage
 * DESCRIPTION
 *  This function is to update the user defined homepage value in
 * the NVRAM
 * PARAMETERS
 *  ptr        [IN|OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
S16 srv_brw_update_user_defined_homepage(U8* url_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 NvramError;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_LID,
        1,
        url_p,
        NVRAM_EF_BRW_USER_DEFINED_HOMEPAGE_SIZE,
        &NvramError);
    return NvramError;
}
#endif

#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  srv_brw_search_list_update_data
 * DESCRIPTION
 *  Function to save given data based on act_type in NVRAM
 * PARAMETERS
 *	act_type	[IN]		Type of action to be taken
 *  title_p     [IN]        Title to be saved
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_search_list_update_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_count;
    S16 NvramError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (record_count = 1; record_count <= NVRAM_EF_BRW_SEARCH_ITEMS_RECORDS; record_count++)
    {
        WriteRecord(
            NVRAM_EF_BRW_SEARCH_ITEM_LID,
            record_count,
            &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[(record_count - 1) * SEARCH_ITEMS_PER_RECORD],
            NVRAM_EF_BRW_SEARCH_ITEM_RECORD_SIZE,
            &NvramError);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_brw_search_list_count_number_of_items
 * DESCRIPTION
 *  This interface is for counting the number of search list items
 * PARAMETERS
 *  void
 * RETURNS
 *  Search list items count
 *****************************************************************************/
void srv_brw_search_list_count_number_of_items (void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 search_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_search_list_items = 0;
    for (search_count = 0; search_count < SRV_BRW_ADDRESS_LIST_MAX_ITEMS; search_count++)
    {
        /* If length of url is '0' then exit the loop */
        if ((g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p) && (strlen((S8*) g_srv_brw_cntx.srv_brw_dynamic_cntx_p->search_items_list_p[search_count].search_item)) == 0)
        {
            break;
        }
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_search_list_items++;
    }
}

#endif /* #if defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_BRW_SEARCH_HISTORY_SUPPORT__)  */

#ifdef __MMI_Q05A_LAUNCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  srv_brw_shortcuts_list_update_data
 * DESCRIPTION
 *  Function to save shortcuts list data in NVRAM
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_brw_shortcuts_list_update_data(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_count;
    S16 NvramError;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (record_count = 1; record_count <= NVRAM_EF_BRW_SHORTCUTS_LIST_RECORDS; record_count++)
    {
        WriteRecord(
            NVRAM_EF_BRW_SHORTCUTS_LIST_LID,
            record_count,
            &g_srv_brw_cntx.srv_brw_dynamic_cntx_p->shortcuts_p[(record_count - 1) * SHORTCUT_ENTERIES_PER_RECORD],
            NVRAM_EF_BRW_SHORTCUTS_LIST_SIZE,
            &NvramError);
    }
}
#endif


#endif /* __MMI_BROWSER_2__ */

#endif /* MMI_BROWSERSRVMAIN_C */
