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
 *  BookmarkCuiOpera.c
 *
 * Project:
 * -------- 
 *  Bookmark CUI
 *
 * Description:
 * ------------
 *  This file contains bookmark CUI for Opera browser solution.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef OPERA_BROWSER

/* Bookmark CUI */
#include "BookmarkCuiGprot.h"
#include "BookmarkCuiOpera.h"

/* Bookmark CUI resource ID */
#include "mmi_rp_cui_bkm_def.h"

/* Opera header */
#include "opera_api.h"
#include "opera_adp_cfg.h"

/* Pop up */
#include "CommonScreens.h"

/* Charset conversion */
#include "Conversions.h"

/* Inline CUI */
#include "InlineCuiGprot.h"

/* FSEditor CUI */
#include "FSEditorCuiGprot.h"

/* Menu CUI */
#include "Menucuigprot.h"

/* USB mass storage mode */
#ifdef __MMI_USB_SUPPORT__
#include "USBDeviceGprot.h"
#include "USBSrvGProt.h"
#endif

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "wgui_touch_screen.h"
#include "OpDevBookmark.h"
#include "string.h"
#include "GlobalResDef.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"
#include "CommonScreensResDef.h"
#include "gui_typedef.h"
#include "wgui_categories_list.h"
#include "GlobalConstants.h"
#include "mmi_frm_mem_gprot.h"
#include "gdi_const.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "wgui_categories_inputs.h"
#include "ImeGprot.h"
#include "wgui_categories.h"
#include "wgui_categories_popup.h"
#include "mmi_frm_input_gprot.h"
#include "kal_public_api.h"
#include "GlobalMenuItems.h"

/***************************************************************************** 
 * Constant
 *****************************************************************************/

/***************************************************************************** 
 * Macro
 *****************************************************************************/

/***************************************************************************** 
 * Enum
 *****************************************************************************/
typedef enum
{
    CUI_BKM_ADD_BKM_INLINE_TITLE_CAPTION = CUI_INLINE_ITEM_ID_BASE + 0,
    CUI_BKM_ADD_BKM_INLINE_TITLE = CUI_INLINE_ITEM_ID_BASE + 1,
    CUI_BKM_ADD_BKM_INLINE_ADDRESS_CAPTION = CUI_INLINE_ITEM_ID_BASE + 2,
    CUI_BKM_ADD_BKM_INLINE_ADDRESS = CUI_INLINE_ITEM_ID_BASE + 3,
    CUI_BKM_ADD_BKM_INLINE_FOLDER_CAPTION = CUI_INLINE_ITEM_ID_BASE + 4,
    CUI_BKM_ADD_BKM_INLINE_FOLDER = CUI_INLINE_ITEM_ID_BASE + 5,
    CUI_BKM_ADD_BKM_INLINE_TOTAL = 6
} cui_bkm_add_bkm_inline_item;

/***************************************************************************** 
 * Structure
 *****************************************************************************/

/***************************************************************************** 
 * Type Definition
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static cui_bkm_sel_bkm_cntx_struct g_cui_bkm_sel_bkm_cntx;
static cui_bkm_add_bkm_cntx_struct g_cui_bkm_add_bkm_cntx;

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
/* Select bookmark */
/* Logic */
static void cui_bkm_sel_bkm_init_cntx(cui_bkm_sel_bkm_cntx_struct *sel_bkm_cntx);
static mmi_ret cui_bkm_sel_bkm_proc(mmi_event_struct *evt);
static void cui_bkm_sel_bkm_post_result_to_parent(MMI_BOOL return_url);
static void cui_bkm_sel_bkm_get_bookmark_list(S32 folder_id);
static mmi_ret cui_bkm_sel_bkm_get_bookmark_list_empty_popup_proc(mmi_event_struct *param);
static void cui_bkm_sel_bkm_opera_bookmark_changed_cb(void);

/* UI */
static void cui_bkm_sel_bkm_entry_select_bookmark_list(void);
static void cui_bkm_sel_bkm_exit_select_bookmark_list(void);

static pBOOL cui_bkm_sel_bkm_select_bookmark_list_get_item_fn(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static void cui_bkm_sel_bkm_select_bookmark_list_flush_data_cb(void);
static void cui_bkm_sel_bkm_select_bookmark_list_highlight_hdlr(S32 item_index);
static void cui_bkm_sel_bkm_select_bookmark_list_open(void);
static void cui_bkm_sel_bkm_select_bookmark_list_select(void);
static void cui_bkm_sel_bkm_select_bookmark_list_back(void);

/* Add bookmark */
/* Logic */
static void cui_bkm_add_bkm_init_cntx(cui_bkm_add_bkm_cntx_struct *add_bkm_cntx);
static mmi_ret cui_bkm_add_bkm_proc(mmi_event_struct *evt);
static void cui_bkm_add_bkm_post_result_to_parent(void);
static void cui_bkm_add_bkm_get_folder_list(S32 folder_id);
static mmi_ret cui_bkm_add_bkm_get_folder_list_empty_popup_proc(mmi_event_struct *param);
static void cui_bkm_add_bkm_save_bookmark_result_callback(S32 retval);
static mmi_ret cui_bkm_add_bkm_save_bookmark_popup_proc(mmi_event_struct *param);
static mmi_ret cui_bkm_add_bkm_add_bookmark_confirm_proc(mmi_event_struct *param);
static void cui_bkm_add_bkm_opera_bookmark_changed_cb(void);

/* UI */
static void cui_bkm_add_bkm_entry_add_bookmark(void);
static void cui_bkm_add_bkm_pre_entry_edit_address(void);
static void cui_bkm_add_bkm_entry_edit_address(void);
static void cui_bkm_add_bkm_entry_select_folder_list(void);
static void cui_bkm_add_bkm_entry_select_folder_list_options(void);
static void cui_bkm_add_bkm_entry_progressing(void);

static void cui_bkm_add_bkm_add_bookmark_highlight_hdlr(S32 item_index);
static void cui_bkm_add_bkm_add_bookmark_select_folder(void);
static void cui_bkm_add_bkm_add_bookmark_confirm(void);
static void cui_bkm_add_bkm_add_bookmark_confirm_yes(void);
static void cui_bkm_add_bkm_add_bookmark_confirm_no(void);
static pBOOL cui_bkm_add_bkm_select_folder_list_get_item_fn(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask);
static void cui_bkm_add_bkm_select_folder_list_highlight_hdlr(S32 item_index);
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
static void cui_bkm_add_bkm_select_folder_list_tap_callback(mmi_tap_type_enum tap_type, S32 index);
#endif /*__MMI_FTE_SUPPORT__*/
static void cui_bkm_add_bkm_select_folder_list_back(void);
static void cui_bkm_add_bkm_select_folder_list_options_open(void);
static void cui_bkm_add_bkm_select_folder_list_options_select(void);

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
#define SELECT_BOOKMARK_LOCAL_FUNCTION
/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_init_cntx
 * DESCRIPTION
 *  This function is used to initialize select bookmark context.
 * PARAMETERS
 *  *sel_bkm_cntx:  [IN/OUT]    Select bookmark context
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_sel_bkm_init_cntx(cui_bkm_sel_bkm_cntx_struct *sel_bkm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sel_bkm_cntx == NULL)
    {
        return;
    }
    
    sel_bkm_cntx->select_item_index = 0;
    sel_bkm_cntx->select_item_id = OPERA_BOOKMARK_ROOT_FOLDER_PARENT_ID;
    sel_bkm_cntx->parent_id_to_go_back = CUI_BKM_INVALID_ID;
    sel_bkm_cntx->is_first_enter = MMI_FALSE;
    sel_bkm_cntx->is_bkm_data_changed = MMI_FALSE;
    sel_bkm_cntx->select_title = NULL;
    sel_bkm_cntx->select_url = NULL;
    sel_bkm_cntx->cached_favicon_resource_idx = 0;
    memset(sel_bkm_cntx->cached_favicon_resource, 0, sizeof(U8*) * CUI_BKM_CACHED_FAVICON_RESOURCE_NUM);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_proc
 * DESCRIPTION
 *  This function is used to handle event from framework on select bookmark common UI
 * PARAMETERS
 *  evt:    [IN]    mmi event
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret cui_bkm_sel_bkm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt == NULL)
    {
        return MMI_RET_ERR;
    }
    
    switch (evt->evt_id)
    {
        /* Group event */
        case EVT_ID_GROUP_ENTER:
            g_cui_bkm_sel_bkm_cntx.is_first_enter = MMI_TRUE;
            break;
            
        case EVT_ID_GROUP_ACTIVE:
            if (!g_cui_bkm_sel_bkm_cntx.is_first_enter)
            {
                OperaApi_GetBookmarkListWithinFolder(g_cui_bkm_sel_bkm_cntx.select_bookmark_list.this_folder_id,
                                                     OPERA_BOOKMARK_LIST_ALL,
                                                     &g_cui_bkm_sel_bkm_cntx.select_bookmark_list);
            }
            break;

        case EVT_ID_GROUP_INACTIVE:
            g_cui_bkm_sel_bkm_cntx.is_first_enter = MMI_FALSE;
            break;
            
        case EVT_ID_GROUP_DEINIT:
            OperaApi_BookmarkExit(cui_bkm_sel_bkm_opera_bookmark_changed_cb);
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_post_result_to_parent
 * DESCRIPTION
 *  This function is used to post result event to caller application.
 * PARAMETERS
 *  result: [IN]    Return URL or not. If MMI_TRUE,  selected_utf8_url is not NULL.
 *                  Otherwise, selected_utf8_url is NULL.
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_sel_bkm_post_result_to_parent(MMI_BOOL return_url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_bkm_sel_bkm_result_evt_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, TRC_CUI_BKM_SEL_BKM_POST_RESULT_TO_PARENT, return_url, g_cui_bkm_sel_bkm_cntx.select_url);
    
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_BKM_SEL_BKM_RESULT, GRP_ID_CUI_OPERA_BKM_SELECT_BOOKMARK);
    if (return_url)
    {
        evt.selected_utf8_title = g_cui_bkm_sel_bkm_cntx.select_title;
        evt.selected_utf8_url = g_cui_bkm_sel_bkm_cntx.select_url;
    }
    else
    {
        evt.selected_utf8_url = NULL;
    }
    mmi_frm_group_post_to_parent(GRP_ID_CUI_OPERA_BKM_SELECT_BOOKMARK, (mmi_group_event_struct*)&evt);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_get_bookmark_list
 * DESCRIPTION
 *  This function is used to get bookmark list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_sel_bkm_get_bookmark_list(S32 folder_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    S32 item_id;
    Opera_BookmarkItemType item_type;
    mmi_popup_property_struct arg;
    MMI_ID active_gid;
    MMI_ID active_sid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, TRC_CUI_BKM_SEL_BKM_GET_BOOKMARK_LIST, folder_id);
    
    if (OperaApi_GetBookmarkListWithinFolder(folder_id,
                                             OPERA_BOOKMARK_LIST_ALL,
                                             &g_cui_bkm_sel_bkm_cntx.select_bookmark_list) == OPERA_API_OK)
    {
        /* Bookmark list is empty */
        if (g_cui_bkm_sel_bkm_cntx.select_bookmark_list.num_of_items == 0)
        {
            if (!g_cui_bkm_sel_bkm_cntx.select_bookmark_list.this_folder_id == OPERA_BOOKMARK_ROOT_FOLDER_ID)
            {
                g_cui_bkm_sel_bkm_cntx.parent_id_to_go_back = g_cui_bkm_sel_bkm_cntx.select_bookmark_list.this_folder_id;
            }

            mmi_popup_property_init(&arg);
            arg.callback = cui_bkm_sel_bkm_get_bookmark_list_empty_popup_proc;
            arg.parent_id = GRP_ID_CUI_OPERA_BKM_SELECT_BOOKMARK;
            mmi_popup_display((WCHAR *)get_string(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, &arg);
        }
        else
        {
            /* Get child level bookmark list, set select_item_index as 0 to highlight first item. */
            if (g_cui_bkm_sel_bkm_cntx.parent_id_to_go_back == CUI_BKM_INVALID_ID)
            {
                g_cui_bkm_sel_bkm_cntx.select_item_index = 0;
            }
            /* Get parent level bookmark list, use folder id to find correct item to be highlighted. */
            else
            {
                for (index = 0; index < g_cui_bkm_sel_bkm_cntx.select_bookmark_list.num_of_items; index++)
                {
                    if (OperaApi_GetBookmarkItemIdAndTypeByIndex(
                            g_cui_bkm_sel_bkm_cntx.select_bookmark_list.this_folder_id,
                            index,
                            &item_id,
                            &item_type) == OPERA_API_OK)
                    {
                        if (g_cui_bkm_sel_bkm_cntx.parent_id_to_go_back == item_id)
                        {
                            g_cui_bkm_sel_bkm_cntx.select_item_index = index;
                            break;
                        }
                    }
                }
                g_cui_bkm_sel_bkm_cntx.parent_id_to_go_back = CUI_BKM_INVALID_ID;
            }
            
            if (!mmi_frm_scrn_is_present(GRP_ID_CUI_OPERA_BKM_SELECT_BOOKMARK,
                                         SCR_ID_CUI_OPERA_BKM_BOOKMARK_LIST,
                                         MMI_FRM_NODE_ALL_FLAG))
            {
                /* First time to enter bookmark list. */
                cui_bkm_sel_bkm_entry_select_bookmark_list();
            }
            else
            {
                mmi_frm_get_active_scrn_id(&active_gid, &active_sid);
                if (active_gid == GRP_ID_CUI_OPERA_BKM_SELECT_BOOKMARK &&
                    active_sid == SCR_ID_CUI_OPERA_BKM_BOOKMARK_LIST)
                {
                    /* Refresh bookmark list screen */
                    mmi_frm_display_dummy_screen();
                    mmi_frm_scrn_close_active_id();
                }
            }
        }
    }
    else
    {
        mmi_popup_display_simple((WCHAR *)get_string(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, GRP_ID_ROOT, 0);
        cui_bkm_sel_bkm_post_result_to_parent(MMI_FALSE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_get_bookmark_list_empty_popup_proc
 * DESCRIPTION
 *  This function is a popup callback for empty bookmark list.
 * PARAMETERS
 *  *param: [IN]    Event structure.
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_bkm_sel_bkm_get_bookmark_list_empty_popup_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_popoupcallback_result_struct *evt_result = (mmi_event_popoupcallback_result_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param == NULL)
    {
        return MMI_RET_ERR;
    }
    
    /* If END case, do nothing. */
    if (!mmi_frm_group_is_present(GRP_ID_CUI_OPERA_BKM_SELECT_BOOKMARK))
    {
        return MMI_RET_OK;
    }
    
    switch(param->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
            if (evt_result->result == MMI_ALERT_NORMAL_EXIT ||
                evt_result->result == MMI_ALERT_INTERRUPT_EXIT)
            {
                /* Bookmark list within root folder is empty, so close CUI*/
                if (g_cui_bkm_sel_bkm_cntx.select_bookmark_list.parent_folder_id == OPERA_BOOKMARK_ROOT_FOLDER_PARENT_ID)
                {
                    cui_bkm_sel_bkm_post_result_to_parent(MMI_FALSE);
                }
                else
                {
                    cui_bkm_sel_bkm_get_bookmark_list(g_cui_bkm_sel_bkm_cntx.select_bookmark_list.parent_folder_id);
                }
            }
            break;
            
        default:
            break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_opera_bookmark_changed_cb
 * DESCRIPTION
 *  This function is a callback for Opera bookmark init/exit function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_sel_bkm_opera_bookmark_changed_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_cui_bkm_sel_bkm_cntx.is_first_enter)
    {
        cui_bkm_sel_bkm_post_result_to_parent(MMI_FALSE);
        
        g_cui_bkm_sel_bkm_cntx.is_bkm_data_changed = MMI_TRUE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_entry_select_bookmark_list
 * DESCRIPTION
 *  This function is used to enter select bookmark list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_sel_bkm_entry_select_bookmark_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    list_menu_category_history *gui_buff;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cui_bkm_sel_bkm_cntx.is_bkm_data_changed)
    {
        g_cui_bkm_sel_bkm_cntx.is_bkm_data_changed = MMI_FALSE;
        return;
    }
    
    MMI_TRACE(MMI_INET_TRC_G4_BRW, TRC_CUI_BKM_SEL_BKM_ENTRY_SELECT_BOOKMARK_LIST);

    if (mmi_frm_scrn_enter(GRP_ID_CUI_OPERA_BKM_SELECT_BOOKMARK,
                           SCR_ID_CUI_OPERA_BKM_BOOKMARK_LIST,
                           cui_bkm_sel_bkm_exit_select_bookmark_list,
                           cui_bkm_sel_bkm_entry_select_bookmark_list,
                           MMI_FRM_FULL_SCRN))
    {
        g_cui_bkm_sel_bkm_cntx.cached_favicon_resource_idx = 0;
        
        guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_CUI_OPERA_BKM_SELECT_BOOKMARK, SCR_ID_CUI_OPERA_BKM_BOOKMARK_LIST);
        if (guiBuffer)
        {
            gui_buff = (list_menu_category_history*)guiBuffer;
            gui_buff->highlighted_item = g_cui_bkm_sel_bkm_cntx.select_item_index;
        }

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);

        RegisterHighlightHandler(cui_bkm_sel_bkm_select_bookmark_list_highlight_hdlr);

        wgui_cat184_set_icon_center_justify(MMI_TRUE);
        
    #ifdef __MMI_FTE_SUPPORT__
        ShowCategory185Screen(
            STR_ID_CUI_OPERA_BKM_BOOKMARKS,
            0,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_cui_bkm_sel_bkm_cntx.select_bookmark_list.num_of_items,
            cui_bkm_sel_bkm_select_bookmark_list_get_item_fn,
            NULL,
            g_cui_bkm_sel_bkm_cntx.select_item_index,
            MMI_TRUE,
            cui_bkm_sel_bkm_select_bookmark_list_flush_data_cb,
            guiBuffer);
    #else /* __MMI_FTE_SUPPORT__ */
        ShowCategory185Screen(
            STR_ID_CUI_OPERA_BKM_BOOKMARKS,
            IMG_ID_CUI_OPERA_BKM_BOOKMARKS,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_cui_bkm_sel_bkm_cntx.select_bookmark_list.num_of_items,
            cui_bkm_sel_bkm_select_bookmark_list_get_item_fn,
            NULL,
            g_cui_bkm_sel_bkm_cntx.select_item_index,
            MMI_TRUE,
            cui_bkm_sel_bkm_select_bookmark_list_flush_data_cb,
            guiBuffer);
    #endif /* __MMI_FTE_SUPPORT__ */

        SetRightSoftkeyFunction(cui_bkm_sel_bkm_select_bookmark_list_back, KEY_EVENT_UP);
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_exit_select_bookmark_list
 * DESCRIPTION
 *  This function is used to exit select bookmark list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_sel_bkm_exit_select_bookmark_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cached_favicon_resource_idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Release screen-base memory */
    for (cached_favicon_resource_idx = 0;
         cached_favicon_resource_idx < CUI_BKM_CACHED_FAVICON_RESOURCE_NUM;
         cached_favicon_resource_idx++)
    {
        if (g_cui_bkm_sel_bkm_cntx.cached_favicon_resource[cached_favicon_resource_idx] != NULL)
        {
            mmi_frm_scrmem_free(g_cui_bkm_sel_bkm_cntx.cached_favicon_resource[cached_favicon_resource_idx]);
            g_cui_bkm_sel_bkm_cntx.cached_favicon_resource[cached_favicon_resource_idx] = NULL;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_select_bookmark_list_get_item_fn
 * DESCRIPTION
 *  This function is used to get bookmark item to display in bookmark list.
 * PARAMETERS
 *  item_index:     [IN]    The index of menu item.
 *  str_buff:       [OUT]   The string buffer to store the text.
 *  *img_buff_p:    [OUT]   A pointer of parameter to store the icon image.
 *  str_img_mask:   [IN]    The mask of image.
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE  : Return MMI_TRUE always
 *****************************************************************************/
static pBOOL cui_bkm_sel_bkm_select_bookmark_list_get_item_fn(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_id;
    Opera_BookmarkItemType item_type;
    U8 *item_txt;
    U8 *favicon_data;
    U32 data_size;
    S32 favicon_width = opera_adp_cfg_bookmark_favicon_size();
    S32 favicon_height = opera_adp_cfg_bookmark_favicon_size();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (OperaApi_GetBookmarkItemIdAndTypeByIndex(
            g_cui_bkm_sel_bkm_cntx.select_bookmark_list.this_folder_id,
            item_index,
            &item_id,
            &item_type) == OPERA_API_OK)
    {
        if (item_type == OPERA_BOOKMARK_ITEM_TYPE_FOLDER)
        {
            OperaApi_GetFolderNameById(item_id, &item_txt);
            if (item_txt != NULL)
            {
                mmi_chset_utf8_to_ucs2_string((U8*)str_buff, (CUI_BKM_MAX_FOLDER_LEN + 1) * ENCODING_LENGTH, item_txt);
            }
            *img_buff_p = get_image(IMG_ID_CUI_OPERA_BKM_FOLDER_ICON);
        }
        else if (item_type == OPERA_BOOKMARK_ITEM_TYPE_BOOKMARK)
        {
            OperaApi_GetBookmarkTitleById(item_id, &item_txt);
            if (item_txt != NULL)
            {
                mmi_chset_utf8_to_ucs2_string((U8*)str_buff, (CUI_BKM_MAX_TITLE_LEN + 1) * ENCODING_LENGTH, item_txt);
            }
            OperaApi_GetBookmarkFaviconById(item_id, &favicon_data, &data_size);
            if (favicon_data != NULL)
            {
                if (g_cui_bkm_sel_bkm_cntx.cached_favicon_resource[g_cui_bkm_sel_bkm_cntx.cached_favicon_resource_idx] == NULL)
                {
                    g_cui_bkm_sel_bkm_cntx.cached_favicon_resource[g_cui_bkm_sel_bkm_cntx.cached_favicon_resource_idx] = 
                        mmi_frm_scrmem_alloc(CUI_BKM_CACHED_FAVICON_RESOURCE_HEADER_SIZE + CUI_BKM_CACHED_FAVICON_RESOURCE_SIZE);
                }

                if (g_cui_bkm_sel_bkm_cntx.cached_favicon_resource[g_cui_bkm_sel_bkm_cntx.cached_favicon_resource_idx] != NULL)
                {
                    memset(g_cui_bkm_sel_bkm_cntx.cached_favicon_resource[g_cui_bkm_sel_bkm_cntx.cached_favicon_resource_idx],
                           0x0, 
                           CUI_BKM_CACHED_FAVICON_RESOURCE_HEADER_SIZE + CUI_BKM_CACHED_FAVICON_RESOURCE_SIZE);
                    
                    /* MMI image header */
                    g_cui_bkm_sel_bkm_cntx.cached_favicon_resource[g_cui_bkm_sel_bkm_cntx.cached_favicon_resource_idx][0] = GDI_IMAGE_TYPE_PNG;
                    g_cui_bkm_sel_bkm_cntx.cached_favicon_resource[g_cui_bkm_sel_bkm_cntx.cached_favicon_resource_idx][1] = 1;
                    
                    /* total size */
                    g_cui_bkm_sel_bkm_cntx.cached_favicon_resource[g_cui_bkm_sel_bkm_cntx.cached_favicon_resource_idx][2] = (data_size) & 0xff;
                    g_cui_bkm_sel_bkm_cntx.cached_favicon_resource[g_cui_bkm_sel_bkm_cntx.cached_favicon_resource_idx][3] = ((data_size) >> 8) & 0xff;
                    g_cui_bkm_sel_bkm_cntx.cached_favicon_resource[g_cui_bkm_sel_bkm_cntx.cached_favicon_resource_idx][4] = ((data_size) >> 16) & 0xff;
                    
                    /* width, height */
                    g_cui_bkm_sel_bkm_cntx.cached_favicon_resource[g_cui_bkm_sel_bkm_cntx.cached_favicon_resource_idx][5] = favicon_width & 0xff;
                    g_cui_bkm_sel_bkm_cntx.cached_favicon_resource[g_cui_bkm_sel_bkm_cntx.cached_favicon_resource_idx][6] = ((favicon_width & 0xf00) >> 8) + ((favicon_height & 0xf) << 4);
                    g_cui_bkm_sel_bkm_cntx.cached_favicon_resource[g_cui_bkm_sel_bkm_cntx.cached_favicon_resource_idx][7] = (favicon_height >> 4) & 0xff;
                    
                    /* favicon raw data */
                    memcpy(g_cui_bkm_sel_bkm_cntx.cached_favicon_resource[g_cui_bkm_sel_bkm_cntx.cached_favicon_resource_idx] + CUI_BKM_CACHED_FAVICON_RESOURCE_HEADER_SIZE,
                           favicon_data,
                           data_size);
                    
                    *img_buff_p = g_cui_bkm_sel_bkm_cntx.cached_favicon_resource[g_cui_bkm_sel_bkm_cntx.cached_favicon_resource_idx];
                    
                    if (g_cui_bkm_sel_bkm_cntx.cached_favicon_resource_idx == CUI_BKM_CACHED_FAVICON_RESOURCE_NUM - 1)
                    {
                        g_cui_bkm_sel_bkm_cntx.cached_favicon_resource_idx = 0;
                    }
                    else
                    {
                        g_cui_bkm_sel_bkm_cntx.cached_favicon_resource_idx++;
                    }
                }
            }
            else
            {
                *img_buff_p = get_image(IMG_ID_CUI_OPERA_BKM_DEFAULT_FAVICON);
            }
        }
    }
    
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_select_bookmark_list_flush_data_cb
 * DESCRIPTION
 *  This callback function is used to flush data in bookmark list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_sel_bkm_select_bookmark_list_flush_data_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_select_bookmark_list_highlight_hdlr
 * DESCRIPTION
 *  This function is a highlight handler of selecting a bookmark from the list.
 * PARAMETERS
 *  item_index: [IN]    The index of highlighted item.
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_sel_bkm_select_bookmark_list_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_id;
    Opera_BookmarkItemType item_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (OperaApi_GetBookmarkItemIdAndTypeByIndex(
            g_cui_bkm_sel_bkm_cntx.select_bookmark_list.this_folder_id,
            item_index,
            &item_id,
            &item_type) == OPERA_API_OK)
    {
        if (item_type == OPERA_BOOKMARK_ITEM_TYPE_FOLDER)
        {
            ChangeLeftSoftkey(STR_GLOBAL_OPEN, 0);
            SetLeftSoftkeyFunction(cui_bkm_sel_bkm_select_bookmark_list_open, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(cui_bkm_sel_bkm_select_bookmark_list_open, KEY_EVENT_UP);
        }
        else
        {
            ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
            SetLeftSoftkeyFunction(cui_bkm_sel_bkm_select_bookmark_list_select, KEY_EVENT_UP);
            SetCenterSoftkeyFunction(cui_bkm_sel_bkm_select_bookmark_list_select, KEY_EVENT_UP);
        }
    }
    g_cui_bkm_sel_bkm_cntx.select_item_index = item_index;
    g_cui_bkm_sel_bkm_cntx.select_item_id = item_id;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_select_bookmark_list_open
 * DESCRIPTION
 *  This function is a softkey handler to open folder.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_sel_bkm_select_bookmark_list_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_bkm_sel_bkm_get_bookmark_list(g_cui_bkm_sel_bkm_cntx.select_item_id);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_select_bookmark_list_select
 * DESCRIPTION
 *  This function is a softkey handler to select bookmark.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_sel_bkm_select_bookmark_list_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (OperaApi_GetBookmarkUrlById(g_cui_bkm_sel_bkm_cntx.select_item_id, 
                                    &(g_cui_bkm_sel_bkm_cntx.select_url)))
    {
        mmi_popup_display_simple((WCHAR *)get_string(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, GRP_ID_ROOT, 0);
        cui_bkm_sel_bkm_post_result_to_parent(MMI_FALSE);
    }
    else
    {
        OperaApi_GetBookmarkTitleById(g_cui_bkm_sel_bkm_cntx.select_item_id, 
                                      &(g_cui_bkm_sel_bkm_cntx.select_title));
        cui_bkm_sel_bkm_post_result_to_parent(MMI_TRUE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_select_bookmark_list_back
 * DESCRIPTION
 *  This function is a softkey handler to go back history in select folder list screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_sel_bkm_select_bookmark_list_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 parent_folder_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cui_bkm_sel_bkm_cntx.select_bookmark_list.this_folder_id == OPERA_BOOKMARK_ROOT_FOLDER_ID)
    {
        cui_bkm_sel_bkm_post_result_to_parent(MMI_FALSE);
    }
    else
    {
        parent_folder_id = g_cui_bkm_sel_bkm_cntx.select_bookmark_list.parent_folder_id;
        g_cui_bkm_sel_bkm_cntx.parent_id_to_go_back = g_cui_bkm_sel_bkm_cntx.select_bookmark_list.this_folder_id;
        
        cui_bkm_sel_bkm_get_bookmark_list(parent_folder_id);
    }
}

#define ADD_BOOKMARK_LOCAL_FUNCTION
/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_init_cntx
 * DESCRIPTION
 *  This function is used to initialize add bookmark context.
 * PARAMETERS
 *  *add_bkm_cntx:  [IN/OUT]    add bookmark context
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_init_cntx(cui_bkm_add_bkm_cntx_struct *add_bkm_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (add_bkm_cntx == NULL)
    {
        return;
    }
    
    add_bkm_cntx->select_folder_index = 0;
    add_bkm_cntx->select_folder_id = OPERA_BOOKMARK_ROOT_FOLDER_ID;
    add_bkm_cntx->parent_id_to_go_back = CUI_BKM_INVALID_ID;
    add_bkm_cntx->add_folder_id = OPERA_BOOKMARK_ROOT_FOLDER_ID;
    add_bkm_cntx->add_bookmark_result = CUI_BKM_INVALID_ID;
    add_bkm_cntx->is_first_enter = MMI_FALSE;
    add_bkm_cntx->is_bkm_data_changed = MMI_FALSE;
    add_bkm_cntx->add_bkm_inline_gid = GRP_ID_INVALID;
    add_bkm_cntx->address_fseditor_gid = GRP_ID_INVALID;
    add_bkm_cntx->folder_option_menu_gid = GRP_ID_INVALID;
    memset(add_bkm_cntx->title, 0, (CUI_BKM_MAX_TITLE_LEN+1) * ENCODING_LENGTH);
    memset(add_bkm_cntx->url, 0, (CUI_BKM_MAX_URL_LEN+1) * ENCODING_LENGTH);
    memset(add_bkm_cntx->temp_url, 0, (CUI_BKM_MAX_URL_LEN+1) * ENCODING_LENGTH);
    memset(add_bkm_cntx->folder, 0, (CUI_BKM_MAX_FOLDER_LEN+1) * ENCODING_LENGTH);
    mmi_ucs2ncpy((CHAR *)g_cui_bkm_add_bkm_cntx.folder, (const CHAR *)GetString(STR_ID_CUI_OPERA_BKM_BOOKMARKS), CUI_BKM_MAX_FOLDER_LEN);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_proc
 * DESCRIPTION
 *  This function is used to handle event from framework on add bookmark common UI
 * PARAMETERS
 *  evt:    [IN]    mmi event
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret cui_bkm_add_bkm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt == NULL)
    {
        return MMI_RET_ERR;
    }
    
    switch (evt->evt_id)
    {
        /* Group event */
        case EVT_ID_GROUP_ENTER:
            g_cui_bkm_add_bkm_cntx.is_first_enter = MMI_TRUE;
            break;
            
        case EVT_ID_GROUP_ACTIVE:
            if (!g_cui_bkm_add_bkm_cntx.is_first_enter)
            {
                OperaApi_GetBookmarkListWithinFolder(g_cui_bkm_add_bkm_cntx.select_folder_list.this_folder_id,
                                                     OPERA_BOOKMARK_LIST_FOLDER_ONLY,
                                                     &g_cui_bkm_add_bkm_cntx.select_folder_list);
            }
            break;

        case EVT_ID_GROUP_INACTIVE:
            g_cui_bkm_add_bkm_cntx.is_first_enter = MMI_FALSE;
            break;
            
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        case EVT_ID_GROUP_DELETE_REQ:
        case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            if (g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid != GRP_ID_INVALID)
            {
                cui_inline_close(g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid);
                g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid = GRP_ID_INVALID;
            }
            if (g_cui_bkm_add_bkm_cntx.address_fseditor_gid != GRP_ID_INVALID)
            {
                cui_fseditor_close(g_cui_bkm_add_bkm_cntx.address_fseditor_gid);
                g_cui_bkm_add_bkm_cntx.address_fseditor_gid = GRP_ID_INVALID;
            }
            if (g_cui_bkm_add_bkm_cntx.folder_option_menu_gid != GRP_ID_INVALID)
            {
                cui_menu_close(g_cui_bkm_add_bkm_cntx.folder_option_menu_gid);
                g_cui_bkm_add_bkm_cntx.folder_option_menu_gid = GRP_ID_INVALID;
            }
            break;
            
        case EVT_ID_GROUP_DEINIT:
            OperaApi_BookmarkExit(cui_bkm_add_bkm_opera_bookmark_changed_cb);
            break;
            
        /* Inline CUI event */
        case EVT_ID_CUI_INLINE_ABORT:
			if (g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid != GRP_ID_INVALID)
            {
                cui_inline_close(g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid);
                g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid = GRP_ID_INVALID;
            }
            cui_bkm_add_bkm_post_result_to_parent();
	        break;

        case EVT_ID_CUI_INLINE_SUBMIT:
            cui_inline_get_value(g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid, CUI_BKM_ADD_BKM_INLINE_TITLE, (void*)g_cui_bkm_add_bkm_cntx.title);
            cui_bkm_add_bkm_add_bookmark_confirm();
            break;

        case EVT_ID_CUI_INLINE_NOTIFY:
            if (((cui_event_inline_notify_struct*)evt)->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
            {
                cui_bkm_add_bkm_add_bookmark_highlight_hdlr(((cui_event_inline_notify_struct*)evt)->item_id);
            }
            break;

        /* FSEditor CUI event */
        case EVT_ID_CUI_FSEDITOR_SUBMMIT:
            cui_fseditor_get_text(g_cui_bkm_add_bkm_cntx.address_fseditor_gid, (WCHAR*)g_cui_bkm_add_bkm_cntx.url, (CUI_BKM_MAX_URL_LEN+1) * ENCODING_LENGTH);
            cui_fseditor_close(g_cui_bkm_add_bkm_cntx.address_fseditor_gid);
            g_cui_bkm_add_bkm_cntx.address_fseditor_gid = GRP_ID_INVALID;
            break;

        case EVT_ID_CUI_FSEDITOR_ABORT:
            mmi_ucs2cpy((S8*)g_cui_bkm_add_bkm_cntx.url, (S8*)g_cui_bkm_add_bkm_cntx.temp_url);
            cui_fseditor_close(g_cui_bkm_add_bkm_cntx.address_fseditor_gid);
            g_cui_bkm_add_bkm_cntx.address_fseditor_gid = GRP_ID_INVALID;
            break;

        /* Menu CUI event */
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            switch (((cui_menu_event_struct*)evt)->highlighted_menu_id)
            {
                case MENU_ID_CUI_OPERA_BKM_SELECT_FOLDER_OPTIONS_OPEN:
                    cui_bkm_add_bkm_select_folder_list_options_open();
                    break;
                    
                case MENU_ID_CUI_OPERA_BKM_SELECT_FOLDER_OPTIONS_SELECT:
                    cui_bkm_add_bkm_select_folder_list_options_select();
                    break;

                default:
                    break;
            }
            if (g_cui_bkm_add_bkm_cntx.folder_option_menu_gid != GRP_ID_INVALID)
            {
                cui_menu_close(g_cui_bkm_add_bkm_cntx.folder_option_menu_gid);
                g_cui_bkm_add_bkm_cntx.folder_option_menu_gid = GRP_ID_INVALID;
            }
            break;
            
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(g_cui_bkm_add_bkm_cntx.folder_option_menu_gid);
            g_cui_bkm_add_bkm_cntx.folder_option_menu_gid = GRP_ID_INVALID;
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_post_result_to_parent
 * DESCRIPTION
 *  This function is used to post result event to caller application.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_post_result_to_parent(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_bkm_add_bkm_result_evt_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, TRC_CUI_BKM_ADD_BKM_POST_RESULT_TO_PARENT);
    
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_CUI_BKM_ADD_BKM_CLOSE, GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK);
    mmi_frm_group_post_to_parent(GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK, (mmi_group_event_struct*)&evt);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_get_folder_list
 * DESCRIPTION
 *  This function is used to get bookmark list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_get_folder_list(S32 folder_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    S32 item_id;
    Opera_BookmarkItemType item_type;
    mmi_popup_property_struct arg;
    MMI_ID active_gid;
    MMI_ID active_sid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, TRC_CUI_BKM_ADD_BKM_GET_FOLDER_LIST, folder_id);
    
    /* Enter to folder list which display root folder only. */
    if (folder_id == OPERA_BOOKMARK_ROOT_FOLDER_PARENT_ID)
    {
        g_cui_bkm_add_bkm_cntx.select_folder_index = 0;
        g_cui_bkm_add_bkm_cntx.select_folder_id = OPERA_BOOKMARK_ROOT_FOLDER_ID;
        g_cui_bkm_add_bkm_cntx.select_folder_list.this_folder_id = OPERA_BOOKMARK_ROOT_FOLDER_PARENT_ID;
        g_cui_bkm_add_bkm_cntx.select_folder_list.num_of_items = 1;
        
        if (!mmi_frm_scrn_is_present(GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK,
                                    SCR_ID_CUI_OPERA_BKM_BOOKMARK_FOLDER_LIST,
                                    MMI_FRM_NODE_ALL_FLAG))
        {
            /* First time to enter folder list. */
            cui_bkm_add_bkm_entry_select_folder_list();
        }
        else
        {
            mmi_frm_get_active_scrn_id(&active_gid, &active_sid);
            if (active_gid == GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK &&
                active_sid == SCR_ID_CUI_OPERA_BKM_BOOKMARK_FOLDER_LIST)
            {
                /* Refresh bookmark list screen */
                mmi_frm_display_dummy_screen();
                mmi_frm_scrn_close_active_id();
            }
        }
    }
    /* Enter to child folder */
    else
    {
        if (OperaApi_GetBookmarkListWithinFolder(folder_id,
                                                 OPERA_BOOKMARK_LIST_FOLDER_ONLY,
                                                 &g_cui_bkm_add_bkm_cntx.select_folder_list) == OPERA_API_OK)
        {
            /* Bookmark list is empty */
            if (g_cui_bkm_add_bkm_cntx.select_folder_list.num_of_items == 0)
            {
                if (!g_cui_bkm_add_bkm_cntx.select_folder_list.this_folder_id == OPERA_BOOKMARK_ROOT_FOLDER_ID)
                {
                    g_cui_bkm_add_bkm_cntx.parent_id_to_go_back = g_cui_bkm_add_bkm_cntx.select_folder_list.this_folder_id;
                }
                
                mmi_popup_property_init(&arg);
                arg.callback = cui_bkm_add_bkm_get_folder_list_empty_popup_proc;
                arg.parent_id = GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK;
                mmi_popup_display((WCHAR *)get_string(STR_GLOBAL_EMPTY), MMI_EVENT_FAILURE, &arg);
            }
            else
            {
                /* Get child level folder list, set select_item_index as 0 to highlight first item. */
                if (g_cui_bkm_add_bkm_cntx.parent_id_to_go_back == CUI_BKM_INVALID_ID)
                {
                    g_cui_bkm_add_bkm_cntx.select_folder_index = 0;
                }
                /* Get parent level folder list, use folder id to find correct item to be highlighted. */
                else
                {
                    for (index = 0; index < g_cui_bkm_add_bkm_cntx.select_folder_list.num_of_items; index++)
                    {
                        if (OperaApi_GetBookmarkItemIdAndTypeByIndex(
                                g_cui_bkm_add_bkm_cntx.select_folder_list.this_folder_id,
                                index,
                                &item_id,
                                &item_type) == OPERA_API_OK)
                        {
                            if (g_cui_bkm_add_bkm_cntx.parent_id_to_go_back == item_id)
                            {
                                g_cui_bkm_add_bkm_cntx.select_folder_index = index;
                                break;
                            }
                        }
                    }
                    g_cui_bkm_add_bkm_cntx.parent_id_to_go_back = CUI_BKM_INVALID_ID;
                }
                
                if (!mmi_frm_scrn_is_present(GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK,
                                             SCR_ID_CUI_OPERA_BKM_BOOKMARK_FOLDER_LIST,
                                             MMI_FRM_NODE_ALL_FLAG))
                {
                    /* First time to enter folder list. */
                    cui_bkm_add_bkm_entry_select_folder_list();
                }
                else
                {
                    mmi_frm_get_active_scrn_id(&active_gid, &active_sid);
                    if (active_gid == GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK &&
                        active_sid == SCR_ID_CUI_OPERA_BKM_BOOKMARK_FOLDER_LIST)
                    {
                        /* Refresh bookmark list screen */
                        mmi_frm_display_dummy_screen();
                        mmi_frm_scrn_close_active_id();
                    }
                }
            }
        }
        else
        {
            mmi_popup_display_simple((WCHAR *)get_string(STR_GLOBAL_ERROR), MMI_EVENT_FAILURE, GRP_ID_ROOT, 0);
            cui_bkm_add_bkm_post_result_to_parent();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_get_folder_list_empty_popup_proc
 * DESCRIPTION
 *  This function is a popup callback for empty bookmark list.
 * PARAMETERS
 *  *param: [IN]    Event structure.
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_bkm_add_bkm_get_folder_list_empty_popup_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_popoupcallback_result_struct *evt_result = (mmi_event_popoupcallback_result_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param == NULL)
    {
        return MMI_RET_ERR;
    }
    
    /* If END case, do nothing. */
    if (!mmi_frm_group_is_present(GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK))
    {
        return MMI_RET_OK;
    }
    
    switch(param->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
            if (evt_result->result == MMI_ALERT_NORMAL_EXIT ||
                evt_result->result == MMI_ALERT_INTERRUPT_EXIT)
            {
                cui_bkm_add_bkm_get_folder_list(g_cui_bkm_add_bkm_cntx.select_folder_list.parent_folder_id);
            }
            break;
            
        default:
            break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_save_bookmark_result_callback
 * DESCRIPTION
 *  This callback function is used to return the result of saving bookmark.
 * PARAMETERS
 *  retval: [IN]    Result of saving bookmark.
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_save_bookmark_result_callback(S32 retval)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_popup_property_init(&arg);
    arg.callback = cui_bkm_add_bkm_save_bookmark_popup_proc;
    arg.parent_id = GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK;

    g_cui_bkm_add_bkm_cntx.add_bookmark_result = retval;
    if (g_cui_bkm_add_bkm_cntx.add_bookmark_result == OPERA_ADD_BOOKMARK_SUCCESS)
    {
        mmi_popup_display((WCHAR *)get_string(STR_GLOBAL_SAVED), MMI_EVENT_SUCCESS, &arg);
    }
    else if (g_cui_bkm_add_bkm_cntx.add_bookmark_result == OPERA_ADD_BOOKMARK_INVALID_URL)
    {
        mmi_popup_display((WCHAR *)get_string(STR_GLOBAL_INVALID_URL), MMI_EVENT_FAILURE, &arg);
    }
    else if (g_cui_bkm_add_bkm_cntx.add_bookmark_result == OPERA_ADD_BOOKMARK_INVALID_TITLE)
    {
        mmi_popup_display((WCHAR *)get_string(STR_GLOBAL_INVALID_FILENAME), MMI_EVENT_FAILURE, &arg);
    }
    else if (g_cui_bkm_add_bkm_cntx.add_bookmark_result == OPERA_ADD_BOOKMARK_FILE_SYSTEM_ERROR)
    {
        mmi_popup_display((WCHAR *)get_string(STR_GLOBAL_FAILED_TO_SAVE), MMI_EVENT_FAILURE, &arg);
    }
    else if (g_cui_bkm_add_bkm_cntx.add_bookmark_result == OPERA_ADD_BOOKMARK_FULL)
    {
        mmi_popup_display((WCHAR *)get_string(STR_GLOBAL_MEMORY_FULL), MMI_EVENT_FAILURE, &arg);
    }
    else if (g_cui_bkm_add_bkm_cntx.add_bookmark_result == OPERA_ADD_BOOKMARK_CANCELED)
    {
        mmi_popup_display((WCHAR *)get_string(STR_GLOBAL_FAILED_TO_SAVE), MMI_EVENT_FAILURE, &arg);
    }
    else if (g_cui_bkm_add_bkm_cntx.add_bookmark_result == OPERA_ADD_BOOKMARK_ERROR)
    {
        mmi_popup_display((WCHAR *)get_string(STR_GLOBAL_FAILED_TO_SAVE), MMI_EVENT_FAILURE, &arg);
    }
    else
    {
        mmi_popup_display((WCHAR *)get_string(STR_GLOBAL_FAILED_TO_SAVE), MMI_EVENT_FAILURE, &arg);
    }
    
    mmi_frm_scrn_close(GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK, SCR_ID_CUI_OPERA_BKM_PROGRESSING);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_save_bookmark_popup_proc
 * DESCRIPTION
 *  This function is a popup callback for saving bookmark.
 * PARAMETERS
 *  *param: [IN]    Event structure.
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_bkm_add_bkm_save_bookmark_popup_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_popoupcallback_result_struct *evt_result = (mmi_event_popoupcallback_result_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param == NULL)
    {
        return MMI_RET_ERR;
    }

    switch(param->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
            /* This is not END case. If END case, do nothing. */
            if (evt_result->result == MMI_ALERT_NORMAL_EXIT ||
                evt_result->result == MMI_ALERT_INTERRUPT_EXIT)
            {
                if (g_cui_bkm_add_bkm_cntx.add_bookmark_result == OPERA_ADD_BOOKMARK_SUCCESS ||
                    g_cui_bkm_add_bkm_cntx.add_bookmark_result == OPERA_ADD_BOOKMARK_FILE_SYSTEM_ERROR ||
                    g_cui_bkm_add_bkm_cntx.add_bookmark_result == OPERA_ADD_BOOKMARK_FULL)
                {
                    if (g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid != GRP_ID_INVALID)
                    {
                        cui_inline_close(g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid);
                        g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid = GRP_ID_INVALID;
                    }
                    cui_bkm_add_bkm_post_result_to_parent();
                }
            }
            break;
            
        default:
            break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_add_bookmark_confirm_proc
 * DESCRIPTION
 *  This function is a confirm callback for saving bookmark.
 * PARAMETERS
 *  *param: [IN]    Event structure.
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret cui_bkm_add_bkm_add_bookmark_confirm_proc(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_popoupcallback_result_struct *evt_result = (mmi_event_popoupcallback_result_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (param == NULL)
    {
        return MMI_RET_ERR;
    }

    switch(param->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
            switch(evt_result->result)
            {
                case MMI_ALERT_CNFM_YES:
                    cui_bkm_add_bkm_add_bookmark_confirm_yes();
                    break;
                case MMI_ALERT_CNFM_NO:
                    cui_bkm_add_bkm_add_bookmark_confirm_no();
                    break;
                default:
                    break;
            }
            break;
            
        default:
            break;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_opera_bookmark_changed_cb
 * DESCRIPTION
 *  This function is a callback for Opera bookmark init/exit function.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_opera_bookmark_changed_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_cui_bkm_add_bkm_cntx.is_first_enter)
    {
        if (mmi_frm_scrn_is_present(GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK,
                                    SCR_ID_CUI_OPERA_BKM_BOOKMARK_FOLDER_LIST,
                                    MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_frm_scrn_close(GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK, SCR_ID_CUI_OPERA_BKM_BOOKMARK_FOLDER_LIST);
            
            g_cui_bkm_add_bkm_cntx.is_bkm_data_changed = MMI_TRUE;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_entry_add_bookmark
 * DESCRIPTION
 *  This function is used to enter screen for adding bookmark.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_entry_add_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const cui_inline_item_caption_struct title_caption =
    {
        STR_ID_CUI_OPERA_BKM_TITLE
    };
    static const cui_inline_item_fullscreen_edit_struct title =
    {
        STR_ID_CUI_OPERA_BKM_TITLE,
        0,
        STR_GLOBAL_EDIT,
#ifdef __MMI_FTE_SUPPORT__
        0,
#else
        IMG_ID_CUI_OPERA_BKM_BOOKMARKS,
#endif /* __MMI_FTE_SUPPORT__ */
        INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL,
        (IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_ONE_LESS_CHARACTER),
        CUI_BKM_MAX_TITLE_LEN + 1,
        NULL
    };
    static const cui_inline_item_caption_struct address_caption =
    {
        STR_GLOBAL_ADDRESS
    };
    static const cui_inline_item_display_only_struct address =
    {
        0
    };
    static const cui_inline_item_caption_struct folder_caption =
    {
        STR_ID_CUI_OPERA_BKM_FOLDER
    };
    static const cui_inline_item_display_only_struct folder =
    {
        0
    };
    
    static const cui_inline_set_item_struct add_bkm_inline_item[CUI_BKM_ADD_BKM_INLINE_TOTAL] =
    {
        {CUI_BKM_ADD_BKM_INLINE_TITLE_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L1, (void*)(&title_caption)},
        {CUI_BKM_ADD_BKM_INLINE_TITLE, CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT, 0, (void*)(&title)},
        {CUI_BKM_ADD_BKM_INLINE_ADDRESS_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L2, (void*)(&address_caption)},
        {CUI_BKM_ADD_BKM_INLINE_ADDRESS, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, (void*)(&address)},
        {CUI_BKM_ADD_BKM_INLINE_FOLDER_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, IMG_GLOBAL_L3, (void*)(&folder_caption)},
        {CUI_BKM_ADD_BKM_INLINE_FOLDER, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, (void*)(&folder)}
    };

    static const cui_inline_struct add_bkm_inline_scr = 
    {
        CUI_BKM_ADD_BKM_INLINE_TOTAL,
        STR_ID_CUI_OPERA_BKM_ADD_BOOKMARK,
#ifdef __MMI_FTE_SUPPORT__
        0,
#else
        IMG_ID_CUI_OPERA_BKM_BOOKMARKS,
#endif /* __MMI_FTE_SUPPORT__ */
        CUI_INLINE_SCREEN_CHANGED,
        NULL,
        add_bkm_inline_item
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, TRC_CUI_BKM_ADD_BKM_ENTRY_ADD_BOOKMARK);
    
    g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid = cui_inline_create(GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK, &add_bkm_inline_scr);
    if (g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid != GRP_ID_INVALID)
    {
        cui_inline_set_title_icon(g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid, GetRootTitleIcon(SERVICES_WAP_MENU_ID));
        cui_inline_set_value(g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid, CUI_BKM_ADD_BKM_INLINE_TITLE, (void*)g_cui_bkm_add_bkm_cntx.title);
        cui_inline_set_value(g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid, CUI_BKM_ADD_BKM_INLINE_ADDRESS, (void*)g_cui_bkm_add_bkm_cntx.url);
        cui_inline_set_value(g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid, CUI_BKM_ADD_BKM_INLINE_FOLDER, (void*)g_cui_bkm_add_bkm_cntx.folder);
        cui_inline_run(g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid);
    }    
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_pre_entry_edit_address
 * DESCRIPTION
 *  This function is used to pre enter full screen editor to edit address.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_pre_entry_edit_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((S8*)g_cui_bkm_add_bkm_cntx.temp_url, (S8*)g_cui_bkm_add_bkm_cntx.url);
    cui_bkm_add_bkm_entry_edit_address();
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_entry_edit_address
 * DESCRIPTION
 *  This function is used to enter full screen editor to edit address.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_entry_edit_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, TRC_CUI_BKM_ADD_BKM_ENTRY_EDIT_ADDRESS);
    
    g_cui_bkm_add_bkm_cntx.address_fseditor_gid = cui_fseditor_create(GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK);
    if (g_cui_bkm_add_bkm_cntx.address_fseditor_gid != GRP_ID_INVALID)
    {
        cui_fseditor_set_title(g_cui_bkm_add_bkm_cntx.address_fseditor_gid,
                               STR_GLOBAL_EDIT,
    #ifdef __MMI_FTE_SUPPORT__
                               0);
    #else
                               IMG_ID_CUI_OPERA_BKM_BOOKMARKS);
    #endif /* __MMI_FTE_SUPPORT__ */
        cui_fseditor_set_text(g_cui_bkm_add_bkm_cntx.address_fseditor_gid, (WCHAR*)g_cui_bkm_add_bkm_cntx.url, (CUI_BKM_MAX_URL_LEN+1) * ENCODING_LENGTH, CUI_BKM_MAX_URL_LEN);
        cui_fseditor_set_input_method(g_cui_bkm_add_bkm_cntx.address_fseditor_gid, IMM_INPUT_TYPE_URL, NULL, INPUT_TYPE_EXT_NO_SHOW_NEW_LINE_SYMBOL);
        cui_fseditor_run(g_cui_bkm_add_bkm_cntx.address_fseditor_gid);
    }    
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_entry_select_folder_list
 * DESCRIPTION
 *  This function is used to enter select folder list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_entry_select_folder_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    list_menu_category_history *gui_buff;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cui_bkm_add_bkm_cntx.is_bkm_data_changed)
    {
        g_cui_bkm_add_bkm_cntx.is_bkm_data_changed = MMI_FALSE;
        return;
    }
    
    MMI_TRACE(MMI_INET_TRC_G4_BRW, TRC_CUI_BKM_ADD_BKM_ENTRY_SELECT_FOLDER_LIST);
    
    if (mmi_frm_scrn_enter(GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK,
                           SCR_ID_CUI_OPERA_BKM_BOOKMARK_FOLDER_LIST,
                           NULL,
                           cui_bkm_add_bkm_entry_select_folder_list,
                           MMI_FRM_FULL_SCRN))
    {
        guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK, SCR_ID_CUI_OPERA_BKM_BOOKMARK_FOLDER_LIST);
        if (guiBuffer)
        {
            gui_buff = (list_menu_category_history*)guiBuffer;
            gui_buff->highlighted_item = g_cui_bkm_add_bkm_cntx.select_folder_index;
        }

        EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        
        RegisterHighlightHandler(cui_bkm_add_bkm_select_folder_list_highlight_hdlr);

    #ifdef __MMI_FTE_SUPPORT__
        ShowCategory184Screen(
            STR_ID_CUI_OPERA_BKM_FOLDER,
            0,
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_cui_bkm_add_bkm_cntx.select_folder_list.num_of_items,
            cui_bkm_add_bkm_select_folder_list_get_item_fn,
            0,
            g_cui_bkm_add_bkm_cntx.select_folder_index,
            guiBuffer);
    #else /* __MMI_FTE_SUPPORT__ */
        ShowCategory184Screen(
            STR_ID_CUI_OPERA_BKM_FOLDER,
            GetRootTitleIcon(SERVICES_WAP_MENU_ID),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            g_cui_bkm_add_bkm_cntx.select_folder_list.num_of_items,
            cui_bkm_add_bkm_select_folder_list_get_item_fn,
            0,
            g_cui_bkm_add_bkm_cntx.select_folder_index,
            guiBuffer);
    #endif /* __MMI_FTE_SUPPORT__ */

        SetRightSoftkeyFunction(cui_bkm_add_bkm_select_folder_list_back, KEY_EVENT_UP);
            
    #if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
        wgui_register_tap_callback(cui_bkm_add_bkm_select_folder_list_tap_callback);
    #endif /*__MMI_FTE_SUPPORT__*/
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_entry_select_folder_list_options
 * DESCRIPTION
 *  This function is used to enter option menu of select folder list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_entry_select_folder_list_options(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, TRC_CUI_BKM_ADD_BKM_ENTRY_SELECT_FOLDER_LIST_OPTIONS);
    
    g_cui_bkm_add_bkm_cntx.folder_option_menu_gid = cui_menu_create(GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK,
                                                                    CUI_MENU_SRC_TYPE_RESOURCE,
                                                                    CUI_MENU_TYPE_FROM_RESOURCE,
                                                                    MENU_ID_CUI_OPERA_BKM_SELECT_FOLDER_OPTIONS,
                                                                    MMI_TRUE,
                                                                    NULL);
    if (g_cui_bkm_add_bkm_cntx.folder_option_menu_gid != GRP_ID_INVALID)
    {
        cui_menu_run(g_cui_bkm_add_bkm_cntx.folder_option_menu_gid);
    }    
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_entry_progressing
 * DESCRIPTION
 *  This function is used to enter progressing screen for selecting folder.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_entry_progressing(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, TRC_CUI_BKM_ADD_BKM_ENTRY_PROGRESSING);
    
    if (mmi_frm_scrn_enter(GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK, 
                           SCR_ID_CUI_OPERA_BKM_PROGRESSING, 
                           NULL, 
                           cui_bkm_add_bkm_entry_progressing, 
                           MMI_FRM_FULL_SCRN))
    {
    #ifdef __MMI_FTE_SUPPORT__
        ShowCategory66Screen(STR_GLOBAL_PLEASE_WAIT, 
                             0,
                             0,
                             0,
                             0,
                             0,
                             (U8*)GetString(STR_GLOBAL_PLEASE_WAIT),
                             IMG_GLOBAL_PROGRESS,
                             NULL);
    #else /* __MMI_FTE_SUPPORT__ */
        ShowCategory66Screen(STR_GLOBAL_PLEASE_WAIT, 
                             GetRootTitleIcon(SERVICES_WAP_MENU_ID),
                             0,
                             0,
                             0,
                             0,
                             (U8*)GetString(STR_GLOBAL_PLEASE_WAIT),
                             IMG_GLOBAL_PROGRESS,
                             NULL);
    #endif /* __MMI_FTE_SUPPORT__ */
        
        mmi_frm_clear_all_key_handler();
        mmi_frm_clear_key_handler(KEY_END, KEY_EVENT_DOWN);
        mmi_frm_clear_key_handler(KEY_END, KEY_EVENT_UP);
        mmi_frm_clear_key_handler(KEY_END, KEY_LONG_PRESS);
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_add_bookmark_highlight_hdlr
 * DESCRIPTION
 *  This function is a highlight handler of adding bookmark screen.
 * PARAMETERS
 *  item_index: [IN]    The index of highlighted item.
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_add_bookmark_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (item_index)
    {
        case CUI_BKM_ADD_BKM_INLINE_TITLE:
            break;
            
        case CUI_BKM_ADD_BKM_INLINE_ADDRESS:
            cui_inline_set_softkey_text(g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid, CUI_BKM_ADD_BKM_INLINE_ADDRESS, MMI_LEFT_SOFTKEY, STR_GLOBAL_EDIT);
            cui_inline_set_softkey_icon(g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid, CUI_BKM_ADD_BKM_INLINE_ADDRESS, MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);
            wgui_inline_set_lsk_function(cui_bkm_add_bkm_pre_entry_edit_address);
            SetCenterSoftkeyFunction(cui_bkm_add_bkm_pre_entry_edit_address, KEY_EVENT_UP);
            break;
        
        case CUI_BKM_ADD_BKM_INLINE_FOLDER:
            cui_inline_set_softkey_text(g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid, CUI_BKM_ADD_BKM_INLINE_FOLDER, MMI_LEFT_SOFTKEY, STR_GLOBAL_SELECT);
            cui_inline_set_softkey_icon(g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid, CUI_BKM_ADD_BKM_INLINE_FOLDER, MMI_CENTER_SOFTKEY, IMG_GLOBAL_COMMON_CSK);
            wgui_inline_set_lsk_function(cui_bkm_add_bkm_add_bookmark_select_folder);
            SetCenterSoftkeyFunction(cui_bkm_add_bkm_add_bookmark_select_folder, KEY_EVENT_UP);
            break;
        
        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_add_bookmark_select_folder
 * DESCRIPTION
 *  This function is a softkey handler to select folder.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_add_bookmark_select_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_bkm_add_bkm_get_folder_list(OPERA_BOOKMARK_ROOT_FOLDER_PARENT_ID);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_add_bookmark_confirm
 * DESCRIPTION
 *  This function is a softkey handler to confirm with user if adding bookmark.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_add_bookmark_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
    arg.parent_id = GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK;
    arg.callback = cui_bkm_add_bkm_add_bookmark_confirm_proc;
    mmi_confirm_display((WCHAR *)get_string(STR_ID_CUI_OPERA_BKM_SAVE_BOOKMARK), MMI_EVENT_QUERY, &arg);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_add_bookmark_confirm_yes
 * DESCRIPTION
 *  This function is a softkey handler to add bookmark.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_add_bookmark_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *title_utf8 = NULL;
    int title_utf8_len = 0;
    kal_uint8 *url_utf8 = NULL;
    int url_utf8_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    title_utf8_len = mmi_charset_ucs2_to_utf8_length_in_bytes((const kal_uint8 *)g_cui_bkm_add_bkm_cntx.title);
    title_utf8 = (kal_uint8*) get_ctrl_buffer((kal_uint16) (title_utf8_len + 1));
    mmi_chset_ucs2_to_utf8_string((kal_uint8*) title_utf8, title_utf8_len + 1, (kal_uint8 *)g_cui_bkm_add_bkm_cntx.title);
    title_utf8[title_utf8_len] = '\0';
    
    url_utf8_len = mmi_charset_ucs2_to_utf8_length_in_bytes((const kal_uint8 *)g_cui_bkm_add_bkm_cntx.url);
    url_utf8 = (kal_uint8*) get_ctrl_buffer((kal_uint16) (url_utf8_len + 1));
    mmi_chset_ucs2_to_utf8_string((kal_uint8*) url_utf8, url_utf8_len + 1, (kal_uint8 *)g_cui_bkm_add_bkm_cntx.url);
    url_utf8[url_utf8_len] = '\0';
    
    cui_bkm_add_bkm_entry_progressing();

    g_cui_bkm_add_bkm_cntx.add_bookmark_result = OperaApi_AddNewBookmark((const char *)title_utf8,
                                                                         (const char *)url_utf8,
                                                                         g_cui_bkm_add_bkm_cntx.add_folder_id,
                                                                         cui_bkm_add_bkm_save_bookmark_result_callback);
    if (g_cui_bkm_add_bkm_cntx.add_bookmark_result != OPERA_API_OK)
    {
        cui_bkm_add_bkm_save_bookmark_result_callback(g_cui_bkm_add_bkm_cntx.add_bookmark_result);
    }

    free_ctrl_buffer(title_utf8);
    free_ctrl_buffer(url_utf8);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_add_bookmark_confirm_no
 * DESCRIPTION
 *  This function is a softkey handler to cancel adding bookmark.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_add_bookmark_confirm_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid != GRP_ID_INVALID)
    {
        cui_inline_close(g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid);
        g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid = GRP_ID_INVALID;
    }
    cui_bkm_add_bkm_post_result_to_parent();
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_select_folder_list_get_item_fn
 * DESCRIPTION
 *  This function is used to get folder item to display in folder list.
 * PARAMETERS
 *  item_index:     [IN]    The index of menu item.
 *  str_buff:       [OUT]   The string buffer to store the text.
 *  *img_buff_p:    [OUT]   A pointer of parameter to store the icon image.
 *  str_img_mask:   [IN]    The mask of image.
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE  : Return MMI_TRUE always
 *****************************************************************************/
static pBOOL cui_bkm_add_bkm_select_folder_list_get_item_fn(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_id;
    Opera_BookmarkItemType item_type;
    U8 *item_txt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Root folder */
    if (g_cui_bkm_add_bkm_cntx.select_folder_list.this_folder_id == OPERA_BOOKMARK_ROOT_FOLDER_PARENT_ID)
    {
        MMI_ASSERT(item_index == 0);
        *img_buff_p = get_image(IMG_ID_CUI_OPERA_BKM_FOLDER_ICON);
        mmi_ucs2ncpy((CHAR *)str_buff, (const CHAR *)GetString(STR_ID_CUI_OPERA_BKM_BOOKMARKS), CUI_BKM_MAX_FOLDER_LEN);
    }
    else
    {
        if (OperaApi_GetBookmarkItemIdAndTypeByIndex(
                g_cui_bkm_add_bkm_cntx.select_folder_list.this_folder_id,
                item_index,
                &item_id,
                &item_type) == OPERA_API_OK)
        {
            if (item_type == OPERA_BOOKMARK_ITEM_TYPE_FOLDER)
            {
                OperaApi_GetFolderNameById(item_id, &item_txt);
                if (item_txt != NULL)
                {
                    mmi_chset_utf8_to_ucs2_string((U8*)str_buff, (CUI_BKM_MAX_FOLDER_LEN + 1) * ENCODING_LENGTH, item_txt);
                }
                *img_buff_p = get_image(IMG_ID_CUI_OPERA_BKM_FOLDER_ICON);
            }
            else if (item_type == OPERA_BOOKMARK_ITEM_TYPE_BOOKMARK)
            {
                MMI_ASSERT(0);
            }
        }
    }
    
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_select_folder_list_highlight_hdlr
 * DESCRIPTION
 *  This function is a highlight handler of selecting a folder from the list.
 * PARAMETERS
 *  item_index: [IN]    The index of highlighted item.
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_select_folder_list_highlight_hdlr(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 item_id;
    Opera_BookmarkItemType item_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Root folder */
    if (g_cui_bkm_add_bkm_cntx.select_folder_list.this_folder_id == OPERA_BOOKMARK_ROOT_FOLDER_PARENT_ID)
    {
        MMI_ASSERT(item_index == 0);
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        SetLeftSoftkeyFunction(cui_bkm_add_bkm_entry_select_folder_list_options, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(cui_bkm_add_bkm_select_folder_list_options_open, KEY_EVENT_UP);
    }
    else
    {
        if (OperaApi_GetBookmarkItemIdAndTypeByIndex(
                g_cui_bkm_add_bkm_cntx.select_folder_list.this_folder_id,
                item_index,
                &item_id,
                &item_type) == OPERA_API_OK)
        {
            if (item_type == OPERA_BOOKMARK_ITEM_TYPE_FOLDER)
            {
                ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
                SetLeftSoftkeyFunction(cui_bkm_add_bkm_entry_select_folder_list_options, KEY_EVENT_UP);
                SetCenterSoftkeyFunction(cui_bkm_add_bkm_select_folder_list_options_open, KEY_EVENT_UP);
            }
            else
            {
                MMI_ASSERT(0);
            }
        }
        g_cui_bkm_add_bkm_cntx.select_folder_index = item_index;
        g_cui_bkm_add_bkm_cntx.select_folder_id = item_id;
    }
}

#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_select_folder_list_tap_callback
 * DESCRIPTION
 *  This function is a tap handler for FTE.
 * PARAMETERS
 *  tap_type:   [IN]    tap type
 *  index:      [IN]    highlight index
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_select_folder_list_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM, only change highlight and do nothing in tap callback function. */
    if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        cui_bkm_add_bkm_select_folder_list_options_open();
    }
}
#endif /*__MMI_FTE_SUPPORT__*/

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_select_folder_list_back
 * DESCRIPTION
 *  This function is a softkey handler to go back history in select folder list screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_select_folder_list_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 parent_folder_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Root folder */
    if (g_cui_bkm_add_bkm_cntx.select_folder_list.this_folder_id == OPERA_BOOKMARK_ROOT_FOLDER_PARENT_ID)
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        parent_folder_id = g_cui_bkm_add_bkm_cntx.select_folder_list.parent_folder_id;
        g_cui_bkm_add_bkm_cntx.parent_id_to_go_back = g_cui_bkm_add_bkm_cntx.select_folder_list.this_folder_id;
        
        cui_bkm_add_bkm_get_folder_list(parent_folder_id);
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_select_folder_list_options_open
 * DESCRIPTION
 *  This function is a softkey handler to open folder.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_select_folder_list_options_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_bkm_add_bkm_get_folder_list(g_cui_bkm_add_bkm_cntx.select_folder_id);
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_select_folder_list_options_select
 * DESCRIPTION
 *  This function is a softkey handler to select folder.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_bkm_add_bkm_select_folder_list_options_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *item_txt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Root folder */
    if (g_cui_bkm_add_bkm_cntx.select_folder_list.this_folder_id == OPERA_BOOKMARK_ROOT_FOLDER_PARENT_ID)
    {
        mmi_ucs2ncpy((CHAR *)g_cui_bkm_add_bkm_cntx.folder, (const CHAR *)GetString(STR_ID_CUI_OPERA_BKM_BOOKMARKS), CUI_BKM_MAX_FOLDER_LEN);
    }
    else
    {
        /* Get selected folder name */
        OperaApi_GetFolderNameById(g_cui_bkm_add_bkm_cntx.select_folder_id, &item_txt);
        if (item_txt != NULL)
        {
            mmi_chset_utf8_to_ucs2_string(g_cui_bkm_add_bkm_cntx.folder, (CUI_BKM_MAX_FOLDER_LEN + 1) * ENCODING_LENGTH, item_txt);
        }
    }

    g_cui_bkm_add_bkm_cntx.add_folder_id = g_cui_bkm_add_bkm_cntx.select_folder_id;
    
    mmi_frm_scrn_close(GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK, SCR_ID_CUI_OPERA_BKM_BOOKMARK_FOLDER_LIST);
}

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
#define SELECT_BOOKMARK_GLOBAL_FUNCTION
/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_create
 * DESCRIPTION
 *  This function is used to create selecting bookmark common UI.
 *  If the common UI cannot be entered, it will return GRP_ID_INVALID.
 *  Caller need to check the returned group id to see if the common UI can be entered.
 * PARAMETERS
 *  parent_gid: [IN]    Group ID of parent
 * RETURNS
 *  Return group id of CUI if CUI can be entered or return GRP_ID_INVALID if CUI can not be entered.
 *****************************************************************************/
mmi_id cui_bkm_sel_bkm_create(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, TRC_CUI_BKM_SEL_BKM_CREATE, parent_gid);

#ifdef __USB_IN_NORMAL_MODE__
    /* check is in mass storage mode */
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* phone drive is exported, cant use this app */
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        cui_gid = GRP_ID_INVALID;
        return cui_gid;
    }
#endif /* __USB_IN_NORMAL_MODE__ */
    
    if (mmi_frm_scrn_is_present(GRP_ID_CUI_OPERA_BKM_SELECT_BOOKMARK, 
                                SCR_ID_CUI_OPERA_BKM_BOOKMARK_LIST, 
                                MMI_FRM_NODE_ALL_FLAG))
    {
        cui_gid = GRP_ID_INVALID;
        mmi_popup_display_simple((WCHAR *)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), MMI_EVENT_FAILURE, GRP_ID_ROOT, 0);
    }
    else
    {
        cui_bkm_sel_bkm_init_cntx(&g_cui_bkm_sel_bkm_cntx);
        cui_gid = mmi_frm_group_create(parent_gid, GRP_ID_CUI_OPERA_BKM_SELECT_BOOKMARK, cui_bkm_sel_bkm_proc, &g_cui_bkm_sel_bkm_cntx);
    }
    
    return cui_gid;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_run
 * DESCRIPTION
 *  This function is used to run selecting bookmark common UI.
 *  It will entry a screen group and entry selecting bookmark screen.
 * PARAMETERS
 *  cui_gid:    [IN]    Group ID of CUI
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bkm_sel_bkm_run(mmi_id cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, TRC_CUI_BKM_SEL_BKM_RUN, cui_gid);

    mmi_frm_group_enter(cui_gid, MMI_FRM_NODE_NONE_FLAG);

    if (OperaApi_BookmarkInit(cui_bkm_sel_bkm_opera_bookmark_changed_cb) == OPERA_API_OK)
    {
        cui_bkm_sel_bkm_get_bookmark_list(OPERA_BOOKMARK_ROOT_FOLDER_ID);
    }
    else
    {
        mmi_popup_display_simple((WCHAR *)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), MMI_EVENT_FAILURE, GRP_ID_ROOT, 0);
        cui_bkm_sel_bkm_post_result_to_parent(MMI_FALSE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_sel_bkm_close
 * DESCRIPTION
 *  This function is used to close selecting bookmark common UI
 * PARAMETERS
 *  cui_gid:    [IN]    Group ID of CUI
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bkm_sel_bkm_close(mmi_id cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, TRC_CUI_BKM_SEL_BKM_CLOSE, cui_gid);
    
    mmi_frm_group_close(cui_gid);
}

#define ADD_BOOKMARK_GLOBAL_FUNCTION
/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_create
 * DESCRIPTION
 *  This function is used to create adding bookmark common UI.
 *  If the common UI cannot be entered, it will return GRP_ID_INVALID.
 *  Caller need to check the returned group id to see if the common UI can be entered.
 * PARAMETERS
 *  parent_gid: [IN]    Group ID of parent
 * RETURNS
 *  Return group id of CUI if CUI can be entered or return GRP_ID_INVALID if CUI can not be entered.
 *****************************************************************************/
mmi_id cui_bkm_add_bkm_create(mmi_id parent_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id cui_gid = GRP_ID_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, TRC_CUI_BKM_ADD_BKM_CREATE, parent_gid);
    
#ifdef __USB_IN_NORMAL_MODE__
    /* check is in mass storage mode */
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* phone drive is exported, cant use this app */
        mmi_usb_app_unavailable_popup(0);   /* pass 0 will show default string */
        cui_gid = GRP_ID_INVALID;
        return cui_gid;
    }
#endif /* __USB_IN_NORMAL_MODE__ */

    if (g_cui_bkm_add_bkm_cntx.add_bkm_inline_gid != GRP_ID_INVALID)
    {
        cui_gid = GRP_ID_INVALID;
        mmi_popup_display_simple((WCHAR *)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), MMI_EVENT_FAILURE, GRP_ID_ROOT, 0);
    }
    else
    {
        cui_bkm_add_bkm_init_cntx(&g_cui_bkm_add_bkm_cntx);
        cui_gid = mmi_frm_group_create(parent_gid, GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK, cui_bkm_add_bkm_proc, &g_cui_bkm_add_bkm_cntx);
    }

    return cui_gid;
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_run
 * DESCRIPTION
 *  This function is used to run adding bookmark common UI.
 *  It will entry a screen group and entry adding bookmark screen.
 * PARAMETERS
 *  cui_gid:            [IN]    Group ID of CUI
 *  *added_utf8_url:    [IN]    URL of bookmark which will be added to bookmarks
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bkm_add_bkm_run(mmi_id cui_gid, const U8 *added_utf8_url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, TRC_CUI_BKM_ADD_BKM_RUN, cui_gid, *added_utf8_url);

    mmi_chset_utf8_to_ucs2_string(g_cui_bkm_add_bkm_cntx.url, (CUI_BKM_MAX_URL_LEN + 1) * ENCODING_LENGTH, (U8*)added_utf8_url);
    
    mmi_frm_group_enter(cui_gid, MMI_FRM_NODE_NONE_FLAG);

    if (OperaApi_BookmarkInit(cui_bkm_add_bkm_opera_bookmark_changed_cb) == OPERA_API_OK)
    {
        cui_bkm_add_bkm_entry_add_bookmark();
    }
    else
    {
        mmi_popup_display_simple((WCHAR *)get_string(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE), MMI_EVENT_FAILURE, GRP_ID_ROOT, 0);
        cui_bkm_add_bkm_post_result_to_parent();
    }
}

/*****************************************************************************
 * FUNCTION
 *  cui_bkm_add_bkm_close
 * DESCRIPTION
 *  This function is used to close adding bookmark common UI
 * PARAMETERS
 *  cui_gid:    [IN]    Group ID of CUI
 * RETURNS
 *  void
 *****************************************************************************/
void cui_bkm_add_bkm_close(mmi_id cui_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G4_BRW, TRC_CUI_BKM_ADD_BKM_CLOSE, cui_gid);
    
    mmi_frm_group_close(cui_gid);
}

#endif /* OPERA_BROWSER */

