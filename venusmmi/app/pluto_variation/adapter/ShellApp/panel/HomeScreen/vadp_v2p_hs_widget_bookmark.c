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
 *  vadp_v2p_hs_widget_bookmark.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions of bookmark widget from 
 *  Venus MMI to PlutoMMI.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_VUI_HOMESCREEN_BOOKMARK__

#include "stdlib.h"
#include "Vadp_v2p_hs_widget_bookmark.h"
#include "Browser_api.h"
#include "Conversions.h"
#include "app_str.h"
#include "opera_api.h"
#include "opera_adp_cfg.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif
#include "kal_release.h"
#include "MMIDataType.h"
#include "OpDevBookmark.h"
#include "kal_non_specific_general_types.h"
#include "string.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_mem_gprot.h"
#include "gdi_const.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"

/***************************************************************************** 
 * Structure
 *****************************************************************************/
typedef struct
{
    void                        *app_asm_pool;
    KAL_ADM_ID                  adm_pool_id;
    S32                         num_of_bookmarks;
    Opera_BookmarkSortingMethod sorting_method;
    MMI_BOOL                    is_bookmark_data_dirty;
    U8                          cached_favicon_resource_idx;
    U8                          *cached_favicon_resource[VADP_HS_WIDGET_BOOKMARK_CACHED_THUMBNAIL_RESOURCE_NUM];
} vadp_v2p_hs_bkm_cntx_struct;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static vadp_v2p_hs_bkm_cntx_struct g_vadp_v2p_hs_bkm_cntx;

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static void vadp_v2p_hs_bkm_opera_bookmark_changed_cb(void);

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_bkm_opera_bookmark_changed_cb
 * DESCRIPTION
 *  This function is a callback for Opera bookmark init/exit function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vadp_v2p_hs_bkm_opera_bookmark_changed_cb(void)
{
    g_vadp_v2p_hs_bkm_cntx.is_bookmark_data_dirty = MMI_TRUE;
}

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_bkm_init_cntx
 * DESCRIPTION
 *  This function is used to initialize global context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_bkm_init_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Initialize global context */
    g_vadp_v2p_hs_bkm_cntx.app_asm_pool = NULL;
    g_vadp_v2p_hs_bkm_cntx.adm_pool_id = NULL;
    g_vadp_v2p_hs_bkm_cntx.is_bookmark_data_dirty = MMI_FALSE;
    g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource_idx = 0;
    memset(g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource, 0, sizeof(U8*) * VADP_HS_WIDGET_BOOKMARK_CACHED_THUMBNAIL_RESOURCE_NUM);
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_bkm_init_bookmark
 * DESCRIPTION
 *  This function is used to initialize bookmark service.
 * PARAMETERS
 *  result_callback:    [IN]    Result callback
 *  user_data:          [IN]    User data for getting bookmark widget object in result callback
 * RETURNS
 *  void
 *****************************************************************************/
S32 vadp_v2p_hs_bkm_init_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return OperaApi_BookmarkInit(vadp_v2p_hs_bkm_opera_bookmark_changed_cb);
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_bkm_get_bookmark
 * DESCRIPTION
 *  This function is used to get bookmark list.
 * PARAMETERS
 *  sorting_method:     [IN]    Sorting method of bookmark list caller want to get
 * RETURNS
 *  void
 *****************************************************************************/
S32 vadp_v2p_hs_bkm_get_bookmark(Opera_BookmarkSortingMethod sorting_method)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vadp_v2p_hs_bkm_cntx.sorting_method = sorting_method;
#ifdef OPERA_V10_BROWSER
    return OperaApi_GetSortedBookmarkList(sorting_method, &g_vadp_v2p_hs_bkm_cntx.num_of_bookmarks);
#else
    return 0;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_bkm_get_bookmark_title_by_index
 * DESCRIPTION
 *  This function is used to get bookmark title by index.
 * PARAMETERS
 *  index:  [IN]    Index of bookmark item
 *  title:  [OUT]   Title of bookmark item
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_bkm_get_bookmark_title_by_index(S32 index, U8 *title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_id;
    U8 *title_utf8;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vadp_v2p_hs_bkm_cntx.is_bookmark_data_dirty == MMI_TRUE)
    {
        g_vadp_v2p_hs_bkm_cntx.is_bookmark_data_dirty = MMI_FALSE;
#ifdef OPERA_V10_BROWSER
        OperaApi_GetSortedBookmarkList(g_vadp_v2p_hs_bkm_cntx.sorting_method, &g_vadp_v2p_hs_bkm_cntx.num_of_bookmarks);
#endif
    }
    
#ifdef OPERA_V10_BROWSER
    if (OperaApi_GetSortedBookmarkItemIdByIndex(g_vadp_v2p_hs_bkm_cntx.sorting_method, index, &item_id) == OPERA_API_OK)
    {
        if (OperaApi_GetBookmarkTitleById(item_id, &title_utf8) != OPERA_API_OK)
        {
            title[0] = title[1] = '\0';
        }
        else
        {
            if (title_utf8 != NULL)
            {
                mmi_chset_utf8_to_ucs2_string(title, (VADP_HS_WIDGET_BOOKMARK_MAX_TITLE_LEN + 1) * ENCODING_LENGTH, title_utf8);
            }
            else
            {
                title[0] = title[1] = '\0';
            }
        }
    }
    else
    {
        MMI_ASSERT(0);
    }
#else
    title[0] = title[1] = '\0';
#endif /* OPERA_V10_BROWSER */
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_bkm_get_bookmark_thumbnail_by_index
 * DESCRIPTION
 *  This function is used to get bookmark thumbnail by index.
 * PARAMETERS
 *  index:          [IN]    Index of bookmark item
 *  rawDataMemory:  [OUT]   Thumbnail raw data
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_bkm_get_bookmark_thumbnail_by_index(S32 index, U8 **rawDataMemory)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_id;
    U8 *thumbnail_data;
    U32 data_size;
    S32 thumbnail_width = opera_adp_cfg_bookmark_thumbnail_icon_size();
    S32 thumbnail_height = opera_adp_cfg_bookmark_thumbnail_icon_size();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vadp_v2p_hs_bkm_cntx.is_bookmark_data_dirty == MMI_TRUE)
    {
        g_vadp_v2p_hs_bkm_cntx.is_bookmark_data_dirty = MMI_FALSE;
#ifdef OPERA_V10_BROWSER
        OperaApi_GetSortedBookmarkList(g_vadp_v2p_hs_bkm_cntx.sorting_method, &g_vadp_v2p_hs_bkm_cntx.num_of_bookmarks);
#endif
    }
    
#ifdef OPERA_V10_BROWSER
    if (OperaApi_GetSortedBookmarkItemIdByIndex(g_vadp_v2p_hs_bkm_cntx.sorting_method, index, &item_id) == OPERA_API_OK)
    {
        if (OperaApi_GetBookmarkThumbnailById(item_id, &thumbnail_data, &data_size) != OPERA_API_OK)
        {
            *rawDataMemory = NULL;
        }
        else
        {
            if (thumbnail_data != NULL)
            {
                if (g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource[g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource_idx] == NULL)
                {
                    g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource[g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource_idx] = 
                        mmi_frm_scrmem_alloc(VADP_HS_WIDGET_BOOKMARK_CACHED_THUMBNAIL_RESOURCE_HEADER_SIZE + VADP_HS_WIDGET_BOOKMARK_CACHED_THUMBNAIL_RESOURCE_SIZE);
                }

                if (g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource[g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource_idx] != NULL)
                {
                    memset(g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource[g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource_idx],
                           0x0, 
                           VADP_HS_WIDGET_BOOKMARK_CACHED_THUMBNAIL_RESOURCE_HEADER_SIZE + VADP_HS_WIDGET_BOOKMARK_CACHED_THUMBNAIL_RESOURCE_SIZE);
                    
                    /* MMI image header */
                    g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource[g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource_idx][0] = GDI_IMAGE_TYPE_PNG;
                    g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource[g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource_idx][1] = 1;
                    
                    /* total size */
                    g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource[g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource_idx][2] = (data_size) & 0xff;
                    g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource[g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource_idx][3] = ((data_size) >> 8) & 0xff;
                    g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource[g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource_idx][4] = ((data_size) >> 16) & 0xff;
                    
                    /* width, height */
                    g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource[g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource_idx][5] = thumbnail_width & 0xff;
                    g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource[g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource_idx][6] = ((thumbnail_width & 0xf00) >> 8) + ((thumbnail_height & 0xf) << 4);
                    g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource[g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource_idx][7] = (thumbnail_height >> 4) & 0xff;
                    
                    /* favicon raw data */
                    memcpy(g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource[g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource_idx] + VADP_HS_WIDGET_BOOKMARK_CACHED_THUMBNAIL_RESOURCE_HEADER_SIZE,
                           thumbnail_data,
                           data_size);
                    
                    *rawDataMemory = g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource[g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource_idx];
                    
                    if (g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource_idx == VADP_HS_WIDGET_BOOKMARK_CACHED_THUMBNAIL_RESOURCE_NUM - 1)
                    {
                        g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource_idx = 0;
                    }
                    else
                    {
                        g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource_idx++;
                    }
                }
                else
                {
                    *rawDataMemory = NULL;
                }
            }
            else
            {
                *rawDataMemory = NULL;
            }
        }
    }
    else
    {
        MMI_ASSERT(0);
    }
#else
    *rawDataMemory = NULL;
#endif /* OPERA_V10_BROWSER */
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_bkm_tap_bookmark_thumbnail
 * DESCRIPTION
 *  This function is used to launch browser and go to URL of selected bookmark.
 * PARAMETERS
 *  index:  [IN]    Index of selected bookmark
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_bkm_tap_bookmark_thumbnail(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_id;
    U8 *utf8_url;
    U8 ucs2_url[(VADP_HS_WIDGET_BOOKMARK_MAX_URL_LEN + 1) * ENCODING_LENGTH] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vadp_v2p_hs_bkm_cntx.is_bookmark_data_dirty == MMI_TRUE)
    {
        g_vadp_v2p_hs_bkm_cntx.is_bookmark_data_dirty = MMI_FALSE;
#ifdef OPERA_V10_BROWSER
        OperaApi_GetSortedBookmarkList(g_vadp_v2p_hs_bkm_cntx.sorting_method, &g_vadp_v2p_hs_bkm_cntx.num_of_bookmarks);
#endif
    }
    
#ifdef OPERA_V10_BROWSER
    if (OperaApi_GetSortedBookmarkItemIdByIndex(g_vadp_v2p_hs_bkm_cntx.sorting_method, index, &item_id) == OPERA_API_OK)
    {
        if (OperaApi_GetBookmarkUrlById(item_id, &utf8_url) == OPERA_API_OK)
        {
            mmi_frm_display_dummy_screen();
            mmi_chset_utf8_to_ucs2_string(ucs2_url, (VADP_HS_WIDGET_BOOKMARK_MAX_URL_LEN + 1) * ENCODING_LENGTH, utf8_url);
            wap_start_browser(WAP_BROWSER_GOTO_URL, ucs2_url);
        }
    }
    else
    {
        MMI_ASSERT(0);
    }
#endif /* OPERA_V10_BROWSER */
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_bkm_get_bookmark_index_by_id
 * DESCRIPTION
 *  This function is used to bookmark index by ID.
 * PARAMETERS
 *  id:     [IN]    ID of bookmark item
 *  index:  [OUT]   Index of bookmark item
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL vadp_v2p_hs_bkm_get_bookmark_index_by_id(S32 id, S32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ind;
    S32 item_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == 0)
    {
        return MMI_FALSE;
    }
    
    if (g_vadp_v2p_hs_bkm_cntx.is_bookmark_data_dirty == MMI_TRUE)
    {
        g_vadp_v2p_hs_bkm_cntx.is_bookmark_data_dirty = MMI_FALSE;
#ifdef OPERA_V10_BROWSER
        OperaApi_GetSortedBookmarkList(g_vadp_v2p_hs_bkm_cntx.sorting_method, &g_vadp_v2p_hs_bkm_cntx.num_of_bookmarks);
#endif
    }
    
#ifdef OPERA_V10_BROWSER
    for (ind = 0; ind < g_vadp_v2p_hs_bkm_cntx.num_of_bookmarks; ind++)
    {
        if (OperaApi_GetSortedBookmarkItemIdByIndex(g_vadp_v2p_hs_bkm_cntx.sorting_method, ind, &item_id) == OPERA_API_OK)
        {
            if (id == item_id)
            {
                *index = ind;
                return MMI_TRUE;
            }
        }
    }
#endif /* OPERA_V10_BROWSER */

    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_bkm_get_bookmark_id_by_index
 * DESCRIPTION
 *  This function is used to get bookmark ID by index.
 * PARAMETERS
 *  index:  [IN]    Index of bookmark item
 *  id:     [OUT]   ID of bookmark item
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL vadp_v2p_hs_bkm_get_bookmark_id_by_index(S32 index, S32 *id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vadp_v2p_hs_bkm_cntx.is_bookmark_data_dirty == MMI_TRUE)
    {
        g_vadp_v2p_hs_bkm_cntx.is_bookmark_data_dirty = MMI_FALSE;
#ifdef OPERA_V10_BROWSER
        OperaApi_GetSortedBookmarkList(g_vadp_v2p_hs_bkm_cntx.sorting_method, &g_vadp_v2p_hs_bkm_cntx.num_of_bookmarks);
#endif
    }
    
#ifdef OPERA_V10_BROWSER
    if (OperaApi_GetSortedBookmarkItemIdByIndex(g_vadp_v2p_hs_bkm_cntx.sorting_method, index, &item_id) == OPERA_API_OK)
    {
        *id = item_id;
        return MMI_TRUE;
    }
    else
#endif
    {
        return MMI_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_bkm_exit_bookmark
 * DESCRIPTION
 *  This function is used to exit bookmark service.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_bkm_exit_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    OperaApi_BookmarkExit(vadp_v2p_hs_bkm_opera_bookmark_changed_cb);
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_bkm_deinit_cntx
 * DESCRIPTION
 *  This function is used to de-initialize global context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_bkm_deinit_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cached_favicon_resource_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Release cache thumbnail memory */
    for (cached_favicon_resource_idx = 0;
         cached_favicon_resource_idx < VADP_HS_WIDGET_BOOKMARK_CACHED_THUMBNAIL_RESOURCE_NUM;
         cached_favicon_resource_idx++)
    {
        if (g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource[cached_favicon_resource_idx] != NULL)
        {
            mmi_frm_scrmem_free(g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource[cached_favicon_resource_idx]);
            g_vadp_v2p_hs_bkm_cntx.cached_favicon_resource[cached_favicon_resource_idx] = NULL;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_bkm_get_bookmark_num
 * DESCRIPTION
 *  This function is used to get number of bookmark.
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of bookmark
 *****************************************************************************/
S32 vadp_v2p_hs_bkm_get_bookmark_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_vadp_v2p_hs_bkm_cntx.num_of_bookmarks;
}

#ifdef __USB_IN_NORMAL_MODE__
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_bkm_usb_is_in_mass_storage_mode
 * DESCRIPTION
 *  This function is used to query if phone is in USB mass storage mode
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL: TRUE if yes, FALSE if no
 *****************************************************************************/
MMI_BOOL vadp_v2p_hs_bkm_usb_is_in_mass_storage_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)srv_usb_is_in_mass_storage_mode();
}

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_bkm_usb_get_error_info
 * DESCRIPTION
 *  This function is used to get the error information includes popup type and string
 * PARAMETERS
 *  void
 * RETURNS
 *  Get the error popup string id.
 *****************************************************************************/
MMI_STR_ID vadp_v2p_hs_bkm_usb_get_error_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_notify_enum event_type;            

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_usb_get_error_info(SRV_USB_ERROR_UNAVAILABLE, &event_type);
}
#endif /* __USB_IN_NORMAL_MODE__ */

#endif /* __MMI_VUI_HOMESCREEN_BOOKMARK__ */

