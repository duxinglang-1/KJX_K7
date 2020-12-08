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
 *  vadp_v2p_hs_widget_memo.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file provides the adaptation functions of Baidu search widget from
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/**********************************************************************
 * Include
 **********************************************************************/
#include "MMI_features.h"
#ifdef __MMI_VUI_HOMESCREEN_BAIDU_SEARCH__

/* Pluto headers: */
#include "MMI_include.h"
#include "nvram_common_defs.h"
#include "CommonScreens.h"
#include "FSEditorCuiGprot.h"
#ifdef __MMI_SCREEN_SWITCH_EFFECT__    
#include "gui_effect_oem.h"
#endif 

/* Venus headers: */
#include "vapp_hs_res.h"
#include "Vadp_p2v_hs.h"

#include "vadp_v2p_hs_widget_baidu_search.h"

#include "mmi_rp_srv_editor_def.h"
#include "MenuCuiGprot.h"
#include "InlineCuiGprot.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "SearchWebBaiduProt.h"
#include "mmi_rp_app_venus_hs_wg_baidu_def.h"
#include "vfx_datatype.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"
#include "common_nvram_editor_data_item.h"
#include "Unicodexdcl.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_inputs.h"
#include "GlobalResDef.h"
#include "mmi_frm_history_gprot.h"
#include "gui_data_types.h"
#include "gui_virtual_keyboard_language_type.h"
#include "mmi_frm_events_gprot.h"
#include "ImeGprot.h"
#include "wgui_categories_util.h"
#include "wgui_categories_inputs.h"
#include "GlobalConstants.h"

/**********************************************************************
 * Define
 **********************************************************************/
#define BAIDU_SEARCH_WIDGET_INPUT_MAX_LENGTH    NVRAM_EF_SEARCH_WEB_HISTORY_MAX_STRING_LEN

/**********************************************************************
 * Global variables
 **********************************************************************/
extern S32 UI_strlen(UI_string_type text);

static U16 g_vadp_v2p_hs_widget_baidu_search_buffer[NVRAM_EF_SEARCH_WEB_HISTORY_MAX_STRING_LEN + 1] = {0};
static U8 g_vadp_v2p_hs_widget_baidu_search_category_count = 0;
static MMI_BOOL g_vadp_v2p_hs_widget_baidu_search_reserve_input = MMI_FALSE;
#if !(defined(__MMI_QWERTY_KEYPAD_SUPPORT__))
static U16 g_vadp_v2p_hs_widget_baidu_search_edit_buffer[NVRAM_EF_SEARCH_WEB_HISTORY_MAX_STRING_LEN + 1] = {0};
static MMI_ID g_vadp_v2p_hs_widget_baidu_search_option_grp_id;
#endif
/* g_vadp_v2p_hs_widget_baidu_search_category is a map table of category enum and its corresponding
 * logo icon and string. The category enum should keep the same as mmi_search_web_baidu_category_enum
 */
static vadp_v2p_hs_baidu_search_category_struct g_vadp_v2p_hs_widget_baidu_search_category[] =
{
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_NEWS,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_NEWS,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_NEWS_TEXT_UP,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_NEWS_TEXT_DOWN
    },
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_INTERNET,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB_TEXT_UP,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB_TEXT_DOWN
    },
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_FORUM,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_FORUM,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_FORUM_TEXT_UP,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_FORUM_TEXT_DOWN
    },
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_KNOWLEDGE,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_KNOWLEDGE,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_KNOWLEDGE_TEXT_UP,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_KNOWLEDGE_TEXT_DOWN
    },
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_IMAGE,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_IMAGE,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_IMAGE_TEXT_UP,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_IMAGE_TEXT_DOWN
    },
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_WEATHER,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB_TEXT_UP,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB_TEXT_DOWN
    },
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_DICTIONARY,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB_TEXT_UP,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB_TEXT_DOWN
    },
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_SPACE,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB_TEXT_UP,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB_TEXT_DOWN
    },
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_MAP,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB_TEXT_UP,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB_TEXT_DOWN
    },
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_OTHERS,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB_TEXT_UP,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB_TEXT_DOWN
    },
    {
        MMI_SEARCH_WEB_BAIDU_CATEGORY_WEB_HELP,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB_TEXT_UP,
        VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB_TEXT_DOWN
    }
};

#define BAIDU_SEARCH_WIDGET_CATEGORY_NUM    (sizeof(g_vadp_v2p_hs_widget_baidu_search_category) / sizeof(vadp_v2p_hs_baidu_search_category_struct))

/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_search_get_categories
 * DESCRIPTION
 *  Get the all need display category enum.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_hs_baidu_search_get_categories(
        VfxU32 count,
        mmi_search_web_baidu_category_enum* categories)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < count; i++)
    {
        if (i == BAIDU_SEARCH_WIDGET_CATEGORY_NUM)
        {
            break;
        }
        categories[i] = g_vadp_v2p_hs_widget_baidu_search_category[i].category;
    }
    /* record the category count of Baidu Search Widget */
    g_vadp_v2p_hs_widget_baidu_search_category_count = i;
    return (VfxS32)i;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_search_get_current_category
 * DESCRIPTION
 *  Get the current category of Baidu Search.
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_search_web_baidu_category_enum
 *****************************************************************************/
mmi_search_web_baidu_category_enum vadp_v2p_hs_baidu_search_get_current_category(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_search_web_baidu_category_enum default_category;
    S32 i;
    MMI_BOOL is_found = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    default_category = mmi_sweb_baidu_get_default_category();
    for (i = 0;  i < g_vadp_v2p_hs_widget_baidu_search_category_count; i++)
    {
        if (default_category ==
            g_vadp_v2p_hs_widget_baidu_search_category[i].category)
        {
            is_found = MMI_TRUE;
            break;
        }
    }
    if (is_found == MMI_FALSE)
    {
        default_category = MMI_SEARCH_WEB_BAIDU_CATEGORY_INTERNET;
    }
    return default_category;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_search_get_category_icon
 * DESCRIPTION
 *  Get the Baidu logo icon of one specific category.
 * PARAMETERS
 *  void
 * RETURNS
 *  VfxResId
 *****************************************************************************/
VfxResId vadp_v2p_hs_baidu_search_get_category_icon(
          mmi_search_web_baidu_category_enum category)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_vadp_v2p_hs_widget_baidu_search_category_count; i++)
    {
        if (category ==
            g_vadp_v2p_hs_widget_baidu_search_category[i].category)
        {
            return (VfxResId)(g_vadp_v2p_hs_widget_baidu_search_category[i].category_icon);
        }
    }
    /* If not find the logo icon, assert */
    MMI_ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_search_get_category_string
 * DESCRIPTION
 *  Get the category string of one specific category.
 * PARAMETERS
 *  void
 * RETURNS
 *  VfxResId
 *****************************************************************************/
void vadp_v2p_hs_baidu_search_get_category_string(
          mmi_search_web_baidu_category_enum category,
          VfxResId *up_icon,
          VfxResId *down_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < g_vadp_v2p_hs_widget_baidu_search_category_count; i++)
    {
        if (category ==
            g_vadp_v2p_hs_widget_baidu_search_category[i].category)
        {
            *up_icon =
                (VfxResId)(g_vadp_v2p_hs_widget_baidu_search_category[i].category_text_icon_up);
            *down_icon =
                (VfxResId)(g_vadp_v2p_hs_widget_baidu_search_category[i].category_text_icon_down);
            return;
        }
    }
    /* If not find the logo icon, assert */
    MMI_ASSERT(0);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_search_init_cntx
 * DESCRIPTION
 *  Init the Baidu Search App context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_baidu_search_init_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vadp_v2p_hs_widget_baidu_search_category_count = 0;
    mmi_sweb_baidu_init_cntx();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_search_release_cntx
 * DESCRIPTION
 *  Deinit the Baidu Search App context.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_baidu_search_release_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sweb_baidu_release_cntx();
    g_vadp_v2p_hs_widget_baidu_search_category_count = 0;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_search_get_text
 * DESCRIPTION
 *  Get the history input of Baidu Search App.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxWChar* vadp_v2p_hs_baidu_search_get_text(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const nvram_ef_search_web_history_entry_struct *history_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    history_entry = mmi_sweb_baidu_get_history_entry(0);
    if (g_vadp_v2p_hs_widget_baidu_search_reserve_input == MMI_FALSE)
    {
        if (history_entry != NULL)
        {
            mmi_wcsncpy(
                g_vadp_v2p_hs_widget_baidu_search_buffer,
                history_entry->string,
                BAIDU_SEARCH_WIDGET_INPUT_MAX_LENGTH);
        }
        else
        {
            g_vadp_v2p_hs_widget_baidu_search_buffer[0] = L'\0';
        }
    }

    return (VfxWChar*)g_vadp_v2p_hs_widget_baidu_search_buffer;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_search_launch_browser
 * DESCRIPTION
 *  Launch the search browser
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_baidu_search_launch_browser(
      mmi_search_web_baidu_category_enum category,
      VfxWChar* buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_v2p_hs_baidu_search_set_default_category(category);
    mmi_sweb_baidu_request_browsing(
        category,
        (PU16)buffer);
}



/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_search_set_default_category
 * DESCRIPTION
 *  Set the default category
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_baidu_search_set_default_category(
      mmi_search_web_baidu_category_enum category)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0;  i < g_vadp_v2p_hs_widget_baidu_search_category_count; i++)
    {
        if (category ==
            g_vadp_v2p_hs_widget_baidu_search_category[i].category)
        {
            mmi_sweb_baidu_set_default_category(category);
            break;
        }
    }
    /* If not find the logo icon, assert */
    if (i >= g_vadp_v2p_hs_widget_baidu_search_category_count)
    {    
        MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_search_set_input_reserve
 * DESCRIPTION
 *  Set input reserve the editor buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_baidu_search_set_input_reserve(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vadp_v2p_hs_widget_baidu_search_reserve_input = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_search_reset_input_reserve
 * DESCRIPTION
 *  Reset input not reserve the editor buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_baidu_search_reset_input_reserve(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vadp_v2p_hs_widget_baidu_search_reserve_input = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_search_get_input_reserve
 * DESCRIPTION
 *  Get input reserve state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
VfxS32 vadp_v2p_hs_baidu_search_get_input_reserve(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_vadp_v2p_hs_widget_baidu_search_reserve_input == MMI_TRUE)
    {
        return 1;
    }
    return 0;
}


#if !(defined(__MMI_QWERTY_KEYPAD_SUPPORT__))
/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_search_save_edit
 * DESCRIPTION
 *  save buffer data
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vadp_v2p_hs_baidu_search_save_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcsncpy(
        g_vadp_v2p_hs_widget_baidu_search_buffer,
        g_vadp_v2p_hs_widget_baidu_search_edit_buffer,
        BAIDU_SEARCH_WIDGET_INPUT_MAX_LENGTH);
    mmi_frm_group_close(GRP_ID_BAIDU_SEARCH_WIDGET);
    /* go back to home screen */
}




/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_proc
 * DESCRIPTION
 *  proc function of baidu widget
 * PARAMETERS
 *  evt	[IN] event structure
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret vadp_v2p_hs_baidu_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
                if (menu_evt->highlighted_menu_id == MENU_ID_INLINE_EDITOR_OPT_DONE)
                {
                    vadp_v2p_hs_baidu_search_save_edit();              
                }
            }
            break;

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            {
                cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
                cui_menu_close(menu_evt->sender_id);
            }
            break;
    }
    if(cui_menu_is_menu_event(evt->evt_id))
    {
        wgui_inputs_options_menu_handler(evt, (mmi_id)g_vadp_v2p_hs_widget_baidu_search_option_grp_id);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_search_entry_edit_option
 * DESCRIPTION
 *  entry edit option screen for Baidu Search
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vadp_v2p_hs_baidu_search_entry_edit_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id option_menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_vadp_v2p_hs_widget_baidu_search_option_grp_id = mmi_frm_group_create(
                                                          GRP_ID_BAIDU_SEARCH_WIDGET,
                                                          GRP_ID_AUTO_GEN,
                                                          vadp_v2p_hs_baidu_proc,
                                                          NULL);
    if (g_vadp_v2p_hs_widget_baidu_search_option_grp_id != GRP_ID_INVALID)
    {
        mmi_frm_group_enter(g_vadp_v2p_hs_widget_baidu_search_option_grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
        option_menu_gid = cui_menu_create(
  		              g_vadp_v2p_hs_widget_baidu_search_option_grp_id,
                              CUI_MENU_SRC_TYPE_RESOURCE,
                              CUI_MENU_TYPE_OPTION,
                              MENU_ID_INLINE_EDITOR_OPT, 
                              MMI_TRUE,
                              NULL);
        cui_menu_run(option_menu_gid);
    }
    else
    {
        mmi_frm_group_close(g_vadp_v2p_hs_widget_baidu_search_option_grp_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_search_csk_handler
 * DESCRIPTION
 *  Handle the center softkey of Baidu Search widget
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vadp_v2p_hs_baidu_search_csk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_v2p_hs_baidu_search_save_edit();
    GoBackHistory();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_search_entry_edit
 * DESCRIPTION
 *  entry full screen edit for baidu search widget
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_baidu_search_entry_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    UI_string_type str;
    const UI_character_type invalid_characters[] = {'\n', '\0' };
#ifdef __MMI_TOUCH_SCREEN__
    const gui_virtual_keyboard_pen_enum invalid_vk_events[] = {GUI_VKBD_PEN_NEWLINE, GUI_VKBD_PEN_NONE};
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_frm_scrn_enter(
             GRP_ID_BAIDU_SEARCH_WIDGET,
             VAPP_HS_SCR_WG_BAIDU_SEARCH_EDIT,
             NULL,
             vadp_v2p_hs_baidu_search_entry_edit,
             MMI_FRM_FULL_SCRN))
    {
    	return;
    }

    gui_buffer = mmi_frm_scrn_get_gui_buf(
                     GRP_ID_BAIDU_SEARCH_WIDGET,
                     VAPP_HS_SCR_WG_BAIDU_SEARCH_EDIT);

    mmi_imm_set_characters(MMI_FALSE, invalid_characters);
#ifdef __MMI_TOUCH_SCREEN__
    mmi_imm_set_events(MMI_FALSE, invalid_vk_events);
#endif

    str = get_string(VAPP_HS_STR_WG_BAIDU_SEARCH_TITLE);
    if ((str != NULL) && (UI_strlen(str) != 0))
    {
    #ifndef __MMI_FTE_SUPPORT__
        ShowCategory215Screen_ext(
            VAPP_HS_STR_WG_BAIDU_SEARCH_TITLE,
            VAPP_HS_IMG_WG_BAIDU_SEARCH_EDIT_TITLE,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            IMM_INPUT_TYPE_SENTENCE,
            (PU8)g_vadp_v2p_hs_widget_baidu_search_edit_buffer,
            BAIDU_SEARCH_WIDGET_INPUT_MAX_LENGTH + 1,
            gui_buffer);
    #else        
        ShowCategory215Screen_ext(
            VAPP_HS_STR_WG_BAIDU_SEARCH_TITLE,
            NULL,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            IMM_INPUT_TYPE_SENTENCE,
            (PU8)g_vadp_v2p_hs_widget_baidu_search_edit_buffer,
            BAIDU_SEARCH_WIDGET_INPUT_MAX_LENGTH + 1,
            gui_buffer);
    #endif
    }
    else
    {
    #ifndef __MMI_FTE_SUPPORT__
        ShowCategory215Screen_ext(
            VAPP_HS_STR_WG_BAIDU_SEARCH_EDIT_TITLE,
            VAPP_HS_IMG_WG_BAIDU_SEARCH_EDIT_TITLE,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            IMM_INPUT_TYPE_SENTENCE,
            (PU8)g_vadp_v2p_hs_widget_baidu_search_edit_buffer,
            BAIDU_SEARCH_WIDGET_INPUT_MAX_LENGTH + 1,
            gui_buffer);
    #else
        ShowCategory215Screen_ext(
            VAPP_HS_STR_WG_BAIDU_SEARCH_EDIT_TITLE,
            NULL,
            STR_GLOBAL_OPTIONS,
            IMG_GLOBAL_OPTIONS,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            IMM_INPUT_TYPE_SENTENCE,
            (PU8)g_vadp_v2p_hs_widget_baidu_search_edit_buffer,
            BAIDU_SEARCH_WIDGET_INPUT_MAX_LENGTH + 1,
            gui_buffer);
    #endif
    }

    SetLeftSoftkeyFunction(vadp_v2p_hs_baidu_search_entry_edit_option, KEY_EVENT_UP);
    SetCategory5RightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    ChangeCenterSoftkey(NULL, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(vadp_v2p_hs_baidu_search_csk_handler, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_search_group_proc
 * DESCRIPTION
 *  Group event process function
 * PARAMETERS
 *  evt    :[IN] group event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret vadp_v2p_hs_baidu_search_group_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
    case EVT_ID_SCRN_DEINIT:
        vadp_v2p_hs_baidu_search_save_edit();
        break;
        
    default:
        break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mens_pre_entry_welcome_screen
 * DESCRIPTION
 *  pre entry function to menstrual welcome screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_baidu_search_pre_entry_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables												  */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_BAIDU_SEARCH_WIDGET))
    {
        return;
    }
    mmi_frm_group_create(
        GRP_ID_ROOT,
        GRP_ID_BAIDU_SEARCH_WIDGET,
        vadp_v2p_hs_baidu_search_group_proc,
        NULL);
    mmi_frm_group_enter(GRP_ID_BAIDU_SEARCH_WIDGET, MMI_FRM_NODE_SMART_CLOSE_FLAG);

#if defined(__MMI_SCREEN_SWITCH_EFFECT__) && defined(__MMI_VUI_ENGINE__)
    gui_screen_switch_effect_v2p_setup_widget();
#endif

    vadp_v2p_hs_baidu_search_entry_edit();
}


/*****************************************************************************
 * FUNCTION
 *  vadp_v2p_hs_baidu_search_start_edit
 * DESCRIPTION
 *  Start input content for baidu search widget
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_v2p_hs_baidu_search_start_edit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcsncpy(
        g_vadp_v2p_hs_widget_baidu_search_edit_buffer,
        g_vadp_v2p_hs_widget_baidu_search_buffer,
        BAIDU_SEARCH_WIDGET_INPUT_MAX_LENGTH);
    vadp_v2p_hs_baidu_search_pre_entry_edit();
}
#endif /* __MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__ */

#endif /* __MMI_VUI_HOMESCREEN_BAIDU_SEARCH__ */
