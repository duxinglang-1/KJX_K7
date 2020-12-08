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
 *   MenuCui.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Menu CUI source code file 
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/



/*******************************************************************************
* Include Header File
*******************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "gdi_include.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "CustMenuRes.h"
#include "CustDataProts.h"
#include "menucuigprot.h"
#include "string.h"
#include "gui_typedef.h"
#include "ScreenRotationGprot.h"
#include "gui_buttons.h"
#include "gui.h"
#include "MMI_features_switch.h"
#include "MMI_features_type.h"
#include "wgui_fixed_menus.h"
#include "GlobalResDef.h"
#include "wgui_categories_util.h"
#include "Unicodexdcl.h"
#include "MMI_fw_trc.h"
#include "mmi_fw_trc.h"
#include "kal_trace.h"
#include "mmi_frm_history_gprot.h"
#include "GlobalConstants.h"
#include "wgui_categories_list.h"
#include "mmi_frm_events_gprot.h"
#include "gui_data_types.h"
#include "gui_fixed_menuitems.h"
#include "GlobalMenuItems.h"
#include "wgui_touch_screen.h"
#include "wgui_include.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_res_range_def.h"
#include "mmi_frm_mem_gprot.h"
#include "gdi_const.h"
//#include "lcd_sw_inc.h"
#include "gdi_datatype.h"
#include "wgui_categories.h"
#include "MenuCui.h"
#include "commonscreens.h"
#include "Wgui_fixed_menuitems.h"
#include "gui_effect_oem.h"
#include "wgui_softkeys.h"
#include "gd_include.h"



/*******************************************************************************
* Structure Define
*******************************************************************************/

/*******************************************************************************
* Macro Define
*******************************************************************************/


/*******************************************************************************
* Function Declaration
*******************************************************************************/

/*******************************************************************************
* External Function Declaration
*******************************************************************************/


extern S32 g_mmi_cascading_menu_current_level;

extern S32 MAIN_LCD_device_width;
extern S32 MAIN_LCD_device_height;
/*******************************************************************************
* Function Realization 
*******************************************************************************/


cui_menu_obj_struct cui_menu_objs[CUI_MENU_MAX_INSTANCE];
cui_menu_current_screen_info_struct *g_cui_menu_current_screen_info = NULL;

static gdi_image_cache_bmp_struct  g_cui_menu_cascading_cache_buf;


/*******************************************************************************/
/*stub code to be integrated with new read res api's*/

extern void mmi_frm_switch_small_screen_redraw(MMI_BOOL enable);
/************************************************************************************************/

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_get_currlist_flags_from_resource
 * DESCRIPTION
 *  Is menu id hidden or not
 * PARAMETERS
 *  menu_id      : [IN] menu id                    
 * RETURNS
 *  void
 * RETURN VALUES
 *  None
*****************************************************************************/
static void cui_menu_get_currlist_flags_from_resource(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    switch(mmi_res_menu_get_flag(user_data_p->currlist_parent_id))
    {
        case MMI_RG_MENU_FLAG_NONE:
            user_data_p->currlist_flags = CUI_MENU_NORMAL_LIST;
            break;
        case MMI_RG_MENU_FLAG_RADIO:
            user_data_p->currlist_flags = CUI_MENU_NORMAL_RADIO_BUTTON_LIST;
            break;
        case MMI_RG_MENU_FLAG_CHECKBOX:
            user_data_p->currlist_flags = CUI_MENU_NORMAL_CHECK_BOX_LIST;
            break;
        default:
            user_data_p->currlist_flags = CUI_MENU_NORMAL_LIST;
            break;
    }
}



/*****************************************************************************              
 * FUNCTION
 *  cui_menu_is_menu_item_hidden
 * DESCRIPTION
 *  Is menu id hidden or not
 * PARAMETERS
 *  menu_id      : [IN] menu id                    
 * RETURNS
 *  void
 * RETURN VALUES
 *  None
*****************************************************************************/
static MMI_BOOL cui_menu_is_menu_item_hidden(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    mmi_id current_gid;
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_gid = mmi_frm_group_get_active_id();
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(current_gid);
    if(!user_data_p->is_item_flags_from_res)
    {
        for (index = 0; index < CUI_MENU_MAX_EDIT_RES; index++)
        {
            if (menu_id == user_data_p->cui_menu_item_flags[index].menu_id)
            {
                if (user_data_p->cui_menu_item_flags[index].flags & CUI_MENU_ITEM_HIDDEN)
                {
                    return MMI_TRUE;
                }
            }
        }
    }
    else
    {
        if(mmi_frm_test_menu_item_hide(menu_id))
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_is_menu_item_disabled
 * DESCRIPTION
 *  Is menu id hidden or not
 * PARAMETERS
 *  menu_id      : [IN] menu id                    
 * RETURNS
 *  void
 * RETURN VALUES
 *  None
*****************************************************************************/
static MMI_BOOL cui_menu_is_menu_item_disabled(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    mmi_id current_gid;
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_gid = mmi_frm_group_get_active_id();
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(current_gid);
    if(!user_data_p->is_item_flags_from_res)
    {
        for (index = 0; index < CUI_MENU_MAX_EDIT_RES; index++)
        {
            if (menu_id == user_data_p->cui_menu_item_flags[index].menu_id)
            {
                if (user_data_p->cui_menu_item_flags[index].flags & CUI_MENU_ITEM_DISABLED)
                {
                    return MMI_TRUE;
                }
            }
        }
    }
    else
    {
        if(IsMenuItemDimmed(menu_id))
        {
            return MMI_TRUE;
        }

    }
    return MMI_FALSE;
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_get_index_from_menu_id_list
 * DESCRIPTION
 *  Get the index for menuitem string list from menuid list
 * PARAMETERS
 *  menu_id      : [IN] menu id                    
 * RETURNS
 *  S32
 * RETURN VALUES
 *  Index of the menuitem string list 
*****************************************************************************/
static S32 cui_menu_get_index_from_menu_id_list(mmi_menu_id menu_id)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    S32 total_menu_ids = 0;
    S32 i;
    mmi_id current_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_gid = mmi_frm_group_get_active_id();
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(current_gid);
    total_menu_ids = user_data_p->currlist_no_of_items;
    for (i = 0; i < total_menu_ids; i++)
    {
        if (user_data_p->currlist_menu_ids[i] == menu_id)    
        {
        	return i;
        }    
    }
    return CUI_MENU_INDEX_NOT_FOUND;
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_get_menu_id_from_menu_id_list
 * DESCRIPTION
 *  Get the menu id from menuid list based on the index of the menuitem
 * PARAMETERS
 *  menu_id      : [IN] menu id                    
 * RETURNS
 *  S32
 * RETURN VALUES
 *  Index of the menuitem string list 
*****************************************************************************/
static mmi_menu_id cui_menu_get_menu_id_from_menu_id_list(S32 index)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    S32 total_menu_ids = 0;
    mmi_id current_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_gid = mmi_frm_group_get_active_id();
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(current_gid);
    total_menu_ids = user_data_p->currlist_no_of_items;
    if ((index < 0) || (index >= total_menu_ids))	
    {
        return (mmi_menu_id)CUI_MENU_MENUID_NOT_FOUND;  
    }
    else
    {
        return user_data_p->currlist_menu_ids[index];
    }
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_reset
 * DESCRIPTION
 *  cui menu reset
 * PARAMETERS
 *  obj  : [IN] pointer to the cui menu object
 * RETURNS
 *  void
 * RETURN VALUES
 *  none 
*****************************************************************************/
static void  cui_menu_reset(cui_menu_obj_struct* obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(obj, 0, sizeof(cui_menu_obj_struct));
}

#if defined(__MMI_CASCADED_OPTION_MENU__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MTK_INTERNAL__))
/*****************************************************************************              
 * FUNCTION
 *  cui_menu_hide_cascaded_menu_softkey
 * DESCRIPTION
 *  Hides the sofetkeys for rotated cascaded menu. 
 * PARAMETERS
 *  softkey_type  : [IN] softkey type
 * RETURNS
 *  void
 * RETURN VALUES
 *  none 
*****************************************************************************/

static void cui_menu_hide_cascaded_menu_softkey(WGUI_SOFTKEY_ENUM softkey_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                          */
    /*----------------------------------------------------------------*/
      MMI_BOOL is_rotated = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                            */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__
        is_rotated = mmi_frm_is_screen_width_height_swapped();
#endif

    gdi_layer_push_clip();
    gdi_layer_set_clip(
      MMI_softkeys[softkey_type].x,
      MMI_softkeys[softkey_type].y,
      MMI_softkeys[softkey_type].x + MMI_softkeys[softkey_type].width - 1,
      MMI_softkeys[softkey_type].y + MMI_softkeys[softkey_type].height - 1);
    if (g_cui_menu_cascading_cache_buf.buf_ptr)
    {
        gdi_image_cache_bmp_draw(0, 0, &g_cui_menu_cascading_cache_buf);   
    }

    gui_greyscale_rectangle(
      MMI_softkeys[softkey_type].x,
      MMI_softkeys[softkey_type].y,
      MMI_softkeys[softkey_type].x + MMI_softkeys[softkey_type].width - 1,
      MMI_softkeys[softkey_type].y + MMI_softkeys[softkey_type].height - 1,
      0,
      0);

    if(g_mmi_cascading_menu_current_level == 1)
    {
      if(is_rotated)
      {
  #ifdef __MMI_OP11_HOMESCREEN__
    #if (__MMI_UI_FADE_EFFECT_STYLE__ == MMI_UI_FADE_EFFECT_STYLE_DARKEN)
      #ifdef __MMI_SCREEN_ROTATE__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
      #else /* __MMI_SCREEN_ROTATE__ */
/* under construction !*/
      #endif /* __MMI_SCREEN_ROTATE__ */
    #endif
  #else
    #if (__MMI_UI_FADE_EFFECT_STYLE__ == MMI_UI_FADE_EFFECT_STYLE_DARKEN)
         gdi_draw_darken_rect(MMI_softkeys[softkey_type].x, MMI_softkeys[softkey_type].y, MMI_softkeys[softkey_type].x + MMI_softkeys[softkey_type].width - 1, MMI_softkeys[softkey_type].y + MMI_softkeys[softkey_type].height - 1, 75);
    #endif
  #endif
      }
    }

    gdi_layer_pop_clip();
}
#endif
static void cui_menu_decide_access_by_shortcut(cui_menu_obj_struct* user_data_p, WCHAR* lsk_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_list_menu_disable_access_by_shortcut();	
    if( (user_data_p->currlist_flags >= CUI_MENU_NORMAL_CHECK_BOX_LIST) 
		&& (user_data_p->currlist_flags <= CUI_MENU_RADIO_LIST_WITH_SCROLLING_TITLE) || 
		user_data_p->access_by_shortcut == CUI_MENU_ACCESS_BY_SHORTCUT_DISABLE)	
    {
        return;
    }
    if(user_data_p->access_by_shortcut == CUI_MENU_ACCESS_BY_SHORTCUT_ENABLE)
    {
        wgui_list_menu_enable_access_by_shortcut();
	 return;	
    }
    if (mmi_ucs2ncmp((CHAR *)lsk_str, (CHAR *)get_string(STR_GLOBAL_OK), mmi_ucs2strlen((CHAR *)lsk_str)) == 0)
    {
        wgui_list_menu_enable_access_by_shortcut();
	 return;
    }
    if (mmi_ucs2ncmp((CHAR *)lsk_str, (CHAR *)get_string(STR_GLOBAL_SELECT), mmi_ucs2strlen((CHAR *)lsk_str)) == 0)
    {
        wgui_list_menu_enable_access_by_shortcut();
	 return;	
    }
    	
}


/*****************************************************************************
 * FUNCTION
 *  cui_menu_list_menu_item_callback
 * DESCRIPTION
 *  Call back for setting flags for menu items
 * PARAMETERS
 *  index       [IN]    The list item index
 *  flag        [OUT]   UI Menu Item Flag
 *  flag_ex     [OUT]   UI Menu Item Extension Flag
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL cui_menu_list_menu_item_callback(S32 index, U32* flag, U32* flag_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_menu_id menu_id;
    S32 i;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_cui_menu_current_screen_info == NULL)
    {
        return MMI_FALSE;
    }
    menu_id = cui_menu_get_menu_id_from_menu_id_list(index);
    if (menu_id == (mmi_menu_id)CUI_MENU_MENUID_NOT_FOUND)
    {
        return MMI_FALSE;
    }
    if (cui_menu_is_menu_item_disabled(menu_id))
    {
        *flag |= UI_MENUITEM_STATE_DISABLED;
    }
    for (i = 0; i < CUI_MENU_MAX_SEPARATORS; i++)
    {
        if (g_cui_menu_current_screen_info->list_separator_index[i] == 0xff)
        {
            break;
        }
	    if (g_cui_menu_current_screen_info->list_separator_index[i]  == index)
        {
            *flag_ex |= UI_MENUITEM_EXT_SHOW_DOWN_SEPARATORLINE;
	        break; 		
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_refresh_list_with_new_menuitem_info
 * DESCRIPTION
 *  Refresh list for cui menu, this api will send the entry event to the APP, again for the same list menu screen
 *  so that it can again modify(refresh) the current list menu
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 * RETURNS
 *  void
 * RETURN VALUES
 *  none 
*****************************************************************************/
void cui_menu_refresh_currlist(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id current_gid;
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_REFRESH_CURRLIST, owner_gid);
    current_gid = mmi_frm_group_get_active_id();
    if ( current_gid != owner_gid)
    {
        return;    
    }
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);	
    if (!user_data_p->enable_refresh_screen )	
    {
        return;
    }
    if(user_data_p->menu_type == CUI_MENU_TYPE_OPTION)
    {
        return;
    }
    mmi_frm_display_dummy_screen();	
    GoBackHistory();	
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_refresh_list_with_new_menuitem_info
 * DESCRIPTION
 *  refresh list for cui menu
 * PARAMETERS
 *  obj           : [IN] pointer to the cui menu object
 * RETURNS
 *  void
 * RETURN VALUES
 *  none 
*****************************************************************************/
static void cui_menu_refresh_list_with_new_menuitem_info(cui_menu_obj_struct* user_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_CASCADED_OPTION_MENU__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MTK_INTERNAL__))
    S32 number_of_items;
    S32 list_index;
#endif


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_REFRESH_LIST_ITEMS_INFO_ONLY);    
#if defined(__MMI_CASCADED_OPTION_MENU__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MTK_INTERNAL__))
    number_of_items = user_data_p->currlist_no_of_items;
    for(list_index = 0; list_index < number_of_items; list_index++)
    {
	    if(user_data_p->enable_cascading_option_menu)	
        {
            if(user_data_p->currlist_flags <= CUI_MENU_NORMAL_LIST)
            {
                if(MMI_TRUE == cui_menu_is_menu_item_disabled(g_cui_menu_current_screen_info->list_menu_ids[list_index]))
                {
                    g_cui_menu_current_screen_info->list_menu_check_states[list_index] |= UI_CASCADING_MENU_DISABLED; 
		            /*check box state array used to keep the menu item flags for cascaded option menu as it cannot have check box list*/
                }
            }
        }
    }  
#endif
    switch (user_data_p->menu_type)
    {
        case CUI_MENU_TYPE_APPMAIN:
        case CUI_MENU_TYPE_APPSUB:
            switch (user_data_p->currlist_flags)
            {
                case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_TEXT_ICON:
                case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_ICON_TEXT:
                case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_TEXT_ICON_ICON:
    	        case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_ICON_TEXT_ICON:
  	            case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_ICON_ICON_TEXT:
   	            case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_TEXT_ICON_ICON:
		             Category73RedrawScreen();
					 break;
                default:
    		       RedrawCategoryFunction();  
                     break;


            }
            break;
        case CUI_MENU_TYPE_OPTION:
            switch (user_data_p->currlist_flags)
            {
                case CUI_MENU_NORMAL_CHECK_BOX_LIST:
                    MMI_ASSERT(0);
                case CUI_MENU_NORMAL_RADIO_BUTTON_LIST:
                    if (!user_data_p->enable_cascading_option_menu)
                    {
    		           RedrawCategoryFunction();  
                    }
                    else
                    {
                        MMI_ASSERT(0); 
                    }
                    break;
                case CUI_MENU_RADIO_BUTTON_LIST_WITH_HINTS:
                    if(!user_data_p->enable_cascading_option_menu)
                    {
    		           RedrawCategoryFunction();  
                    }
                    else
                    {
                        MMI_ASSERT(0);
                    }
                    break;
                case CUI_MENU_CHECK_BOX_LIST_WITHOUT_TOGGLE:
                case CUI_MENU_LIST_WITH_MENUID_DRIVEN_HIGHLIGHTER:
                    MMI_ASSERT(0);
                 case CUI_MENU_RADIO_LIST_WITH_SCROLLING_TITLE:
                    if(!user_data_p->enable_cascading_option_menu)
                    {
    		           RedrawCategoryFunction();  
                    }
                    else
                    {
                        MMI_ASSERT(0);
                    }
                    break;
                case CUI_MENU_LIST_WITH_NO_MARGIN_WHEN_NO_ICON:
                case CUI_MENU_LIST_WITH_NO_ICON:
		        case CUI_MENU_LIST_WITH_DOUBLE_TEXT_SINGLE_ICON:
                case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_TEXT_ICON:
                case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_ICON_TEXT:
		        case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_TEXT_ICON_ICON:
                case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_ICON_TEXT_ICON:
                case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_ICON_ICON_TEXT:
		        case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_TEXT_ICON_ICON:		
		        case CUI_MENU_LIST_WITH_TEXT_NUMBERED_ITEMS:
		  	        MMI_ASSERT(0); /*currently option menu will only support static fixed list or cascaded menu */
                case CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS:
                    if(!user_data_p->enable_cascading_option_menu)
                    {
                        RedrawCategoryFunction();
                    }
                    else
                    {
                        wgui_cat801_refresh_list((U8 **)subMenuDataPtrs, (U8 **)NULL, g_cui_menu_current_screen_info->list_menu_check_states);
                    }
                    break;
		      default:
                #if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
                    MMI_ASSERT(!(user_data_p->enable_fte_sublevel_option_menu));
                #endif
                    if (!user_data_p->enable_cascading_option_menu)
                    {
     		           RedrawCategoryFunction();  /* FULL screen implementation pending: tracking list item 6 */
                         break;
                    }
		            else
                    {
                        wgui_cat801_refresh_list((U8 **)subMenuDataPtrs, (U8 **)NULL, g_cui_menu_current_screen_info->list_menu_check_states);
                    }
            }
            break;
        default:
            MMI_ASSERT(0);
    }
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_show_list
 * DESCRIPTION
 *  show list for cui menu
 * PARAMETERS
 *  obj           : [IN] pointer to the cui menu object
 *  gui_buffer    : [IN] pointer to gui buffer
 * RETURNS
 *  void
 * RETURN VALUES
 *  none 
*****************************************************************************/
static void cui_menu_show_list(cui_menu_obj_struct* user_data_p, U8* gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* title_string = user_data_p->default_title_string;
    UI_image_type title_image = user_data_p->default_title_image;
    WCHAR* lsk_str = user_data_p->default_lsk_string;
    WCHAR* rsk_str = user_data_p->default_rsk_string;
    S32 number_of_items;
    S32 initial_index =0;
    S32 list_index;
    U8 *list_of_icons[MAX_FIXED_ICONTEXT_MENU_ITEMS];
    MMI_BOOL is_list_icons_set = MMI_FALSE;	


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_SHOW_LIST);
	user_data_p->is_in_show_func = MMI_TRUE;
#ifdef __MMI_SCREEN_ROTATE__    
    mmi_frm_screen_rotate(user_data_p->rotate_type);
 #endif
    if (user_data_p->currlist_title_string)
    {
        title_string = user_data_p->currlist_title_string;
	    if(user_data_p->currlist_title_image)
        {
            title_image = user_data_p->currlist_title_image;
        }
    }
    if (!title_string)
    {
        if ((user_data_p->menu_type == CUI_MENU_TYPE_OPTION) && (user_data_p->current_level_index == 0))
        {
            title_string =  get_string(STR_GLOBAL_OPTIONS);      
        }
	    else
        {
            if (user_data_p->mode ==  CUI_MENU_SRC_TYPE_RESOURCE)
            {
                title_string =  get_string((MMI_ID_TYPE)GetStringIdOfItem(user_data_p->currlist_parent_id));
            }
        }
    }
    if (user_data_p->currlist_lsk_string) 
    {
        lsk_str = user_data_p->currlist_lsk_string;
    }
    cui_menu_decide_access_by_shortcut(user_data_p, lsk_str);
    if (user_data_p->currlist_rsk_string)
    {
        rsk_str = user_data_p->currlist_rsk_string;
    }
    number_of_items = user_data_p->currlist_no_of_items;
    if (user_data_p->currlist_highlighted_id > 0)
    {
        gui_buffer = NULL;
        initial_index = cui_menu_get_index_from_menu_id_list(user_data_p->currlist_highlighted_id);
	    MMI_ASSERT(initial_index != CUI_MENU_INDEX_NOT_FOUND);	
    }
    for(list_index = 0; list_index < number_of_items; list_index++)
    {
        subMenuDataPtrs[list_index] = subMenuData[list_index];
        hintDataPtrs[list_index] = hintData[list_index];
#if defined(__MMI_CASCADED_OPTION_MENU__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MTK_INTERNAL__))
	    if(user_data_p->enable_cascading_option_menu)	
        {
            if(user_data_p->currlist_flags <= CUI_MENU_NORMAL_LIST)
            {
                if(MMI_TRUE == cui_menu_is_menu_item_disabled(g_cui_menu_current_screen_info->list_menu_ids[list_index]))
                {
                    g_cui_menu_current_screen_info->list_menu_check_states[list_index] |= UI_CASCADING_MENU_DISABLED; 
		            /*check box state array used to keep the menu item flags for cascaded option menu as it cannot have check box list*/
                }
	            list_of_icons[list_index] = get_image(g_cui_menu_current_screen_info->list_menu_icons[list_index]);
            }
        }
#endif
        if((user_data_p->currlist_flags == CUI_MENU_LIST_WITH_NO_MARGIN_WHEN_NO_ICON)
        #if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
            || (user_data_p->enable_fte_sublevel_option_menu)
        #endif
            )
        {
            list_of_icons[list_index] = get_image(g_cui_menu_current_screen_info->list_menu_icons[list_index]);
        }
	    if(g_cui_menu_current_screen_info->list_menu_icons[list_index])	
        {
            is_list_icons_set = MMI_TRUE;
        }
    } 
    MMI_ASSERT(number_of_items);
    switch (user_data_p->menu_type)
    {
        case CUI_MENU_TYPE_APPMAIN:
        case CUI_MENU_TYPE_APPSUB:
            switch (user_data_p->currlist_flags)
            {
                case CUI_MENU_NORMAL_CHECK_BOX_LIST:
                    SetCheckboxToggleRightSoftkeyFunctions(cui_menu_lsk_handler, cui_menu_rsk_handler);
                    wgui_fixed_list_register_get_flags_handler(cui_menu_list_menu_item_callback);
                    ShowCategory140Screen_ext((U8*)title_string,
                        title_image,
                        number_of_items,
                        (U8 **)subMenuDataPtrs,
                        g_cui_menu_current_screen_info->list_menu_check_states,
                        initial_index,
                        gui_buffer);
                    break;
                case CUI_MENU_NORMAL_RADIO_BUTTON_LIST:
                    ShowCategory36Screen_ext((U8*)title_string,
                        title_image,
                        (U8*)lsk_str,
                        (U8*)0,
                        (U8*)rsk_str,
                        (U8*)0,
                        number_of_items,
                        (U8 **)subMenuDataPtrs,
                        (U16)initial_index,
                        gui_buffer);
                    break;
                case CUI_MENU_RADIO_BUTTON_LIST_WITH_HINTS:
                    ShowCategory109Screen_ext((U8*)title_string,
                        title_image,
                        (U8*)lsk_str,
                        (U8*)0,
                        (U8*)rsk_str,
                        (U8*)0,
                        number_of_items,
                        (U8 **)subMenuDataPtrs,
                        (U8 **)hintDataPtrs,
                        (U16)initial_index,
                        gui_buffer);
                    break;
	             case CUI_MENU_CHECK_BOX_LIST_WITHOUT_TOGGLE:
                     ShowCategory12Screen_ext((U8*)title_string,
                         title_image,
                         (U8*)lsk_str,
                         (U8*)0,
                         (U8*)rsk_str,
                         (U8*)0,
                         number_of_items,
                         (U8 **)subMenuDataPtrs,
                         g_cui_menu_current_screen_info->list_menu_check_states,
                         (U16)initial_index,
                         gui_buffer);
                     break;
                 case CUI_MENU_LIST_WITH_MENUID_DRIVEN_HIGHLIGHTER:
#ifndef __MMI_CATEGORY_LIST_SLIM__
                     ShowCategory155Screen(title_string,
                         title_image,
                         lsk_str,
                         (U8*)0,
                         rsk_str,
                         (U8*)0,
                         user_data_p->currlist_parent_id, /* get item count and item string */
                         (U16 *)g_cui_menu_current_screen_info->list_menu_icons,
                         (U8 **)hintDataPtrs,
                         0,
                         (U16)initial_index,
                         gui_buffer);
#else 
                    MMI_ASSERT(0);
#endif
                         break;
                 case CUI_MENU_RADIO_LIST_WITH_SCROLLING_TITLE:
                     ShowCategory172Screen((U8*)title_string,
                         title_image,
                         (U8*)lsk_str,
                         (U8*)0,
                         (U8*)rsk_str,
                         (U8*)0,
                         number_of_items,
                         (U8 **)subMenuDataPtrs,
                         0,
                         (U16)initial_index,
                         gui_buffer);
			             break;
                 case CUI_MENU_LIST_WITH_NO_MARGIN_WHEN_NO_ICON:
                     ShowCategory174Screen((U8*)title_string,
                         title_image,
                         (U8*)lsk_str,
                         (U8*)0,
                         (U8*)rsk_str,
                         (U8*)0,
                         number_of_items,
                         (U8 **)subMenuDataPtrs,
                         (U8 **)list_of_icons,
                         (U8 **)hintDataPtrs,
                         0,
                         (U16)initial_index,
                         gui_buffer);
			             break;
                 case CUI_MENU_LIST_WITH_NO_ICON:
                     ShowCategory6Screen_ext((U8*)title_string,
                         title_image,
                         (U8*)lsk_str,
                         (U8*)0,
                         (U8*)rsk_str,
                         (U8*)0,
                         number_of_items,
                         (U8 **)subMenuDataPtrs,
                         (U8 **)hintDataPtrs,
                         (U16)initial_index,
                         gui_buffer);
			             break;
                 case CUI_MENU_LIST_WITH_DOUBLE_TEXT_SINGLE_ICON:
                     ShowCategory354Screen_ext((U8*)title_string,
                         title_image,
                         (U8*)lsk_str,
                         (U8*)0,
                         (U8*)rsk_str,
                         (U8*)0,
                         number_of_items,
                         (U8 **)subMenuDataPtrs,
                         (U8 **)hintDataPtrs,
                         (U16 *)g_cui_menu_current_screen_info->list_menu_icons,
                         initial_index,
                         gui_buffer);
                         break;
                 case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_TEXT_ICON:
                     ShowCategory73Screen_ext((U8*)title_string,
                         title_image,
                         (U8*)lsk_str,
                         (U8*)0,
                         (U8*)rsk_str,
                         (U8*)0,
                         number_of_items,
                         (U8 **)subMenuDataPtrs,
                         (U16 *)g_cui_menu_current_screen_info->list_menu_icons,
                         (U16 *)g_cui_menu_current_screen_info->list_menu_icons2,
                         initial_index,
                         gui_buffer,
                         ICON_TEXT_ICON);
     		  	         break;
	   	         case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_ICON_TEXT:
			         ShowCategory73Screen_ext((U8*)title_string,
                         title_image,
                         (U8*)lsk_str,
                         (U8*)0,
                         (U8*)rsk_str,
                         (U8*)0,
                         number_of_items,
                         (U8 **)subMenuDataPtrs,
                         (U16 *)g_cui_menu_current_screen_info->list_menu_icons,
                         (U16 *)g_cui_menu_current_screen_info->list_menu_icons2,
                         initial_index,
                         gui_buffer,
                         ICON_ICON_TEXT);
     		  	         break;
                 case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_TEXT_ICON_ICON:
                     ShowCategory73Screen_ext((U8*)title_string,
                         title_image,
                         (U8*)lsk_str,
                         (U8*)0,
                         (U8*)rsk_str,
                         (U8*)0,
                         number_of_items,
                         (U8 **)subMenuDataPtrs,
                         (U16 *)g_cui_menu_current_screen_info->list_menu_icons,
                         (U16 *)g_cui_menu_current_screen_info->list_menu_icons2,
                         initial_index,
                         gui_buffer,
                         TEXT_ICON_ICON);
     		  	         break;	
	   	         case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_ICON_TEXT_ICON:
			         ShowCategory73ScreenExt(title_string,
                        title_image,
                        lsk_str,
                        (U8*)0,
                        rsk_str,
                        (U8*)0,
                        number_of_items,
                        (U8 **)subMenuDataPtrs,
                        (U16 *)g_cui_menu_current_screen_info->list_menu_icons,
                        (U16 *)g_cui_menu_current_screen_info->list_menu_icons2,
                        (U8**)hintDataPtrs,
                        initial_index,
                        gui_buffer,
                        ICON_TEXT_ICON);
     		  	   break;
	   	         case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_ICON_ICON_TEXT:
			         ShowCategory73ScreenExt(title_string,
                         title_image,
                         lsk_str,
                         (U8*)0,
                         rsk_str,
                         (U8*)0,
                         number_of_items,
                         (U8 **)subMenuDataPtrs,
                         (U16 *)g_cui_menu_current_screen_info->list_menu_icons,
                         (U16 *)g_cui_menu_current_screen_info->list_menu_icons2,
                         (U8**)hintDataPtrs,
                         initial_index,
                         gui_buffer,
                         ICON_ICON_TEXT);
     		  	         break;
	   	         case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_TEXT_ICON_ICON:
			         ShowCategory73ScreenExt(title_string,
                         title_image,
                         lsk_str,
                         (U8*)0,
                         rsk_str,
                         (U8*)0,
                         number_of_items,
                         (U8 **)subMenuDataPtrs,
                         (U16 *)g_cui_menu_current_screen_info->list_menu_icons,
                         (U16 *)g_cui_menu_current_screen_info->list_menu_icons2,
                         (U8**)hintDataPtrs,
                         initial_index,
                         gui_buffer,
                         TEXT_ICON_ICON);
     		  	     break;		
			     case CUI_MENU_LIST_WITH_TEXT_NUMBERED_ITEMS:
			         ShowCategory89Screen_ext((U8*)title_string,
                         title_image,
                         (U8*)lsk_str,
                         (U8*)0,
                         (U8*)rsk_str,
                         (U8*)0,
                         number_of_items,
                         (U8 **)subMenuDataPtrs,
                         (U8**)hintDataPtrs,
                         0,
                         initial_index,
                         gui_buffer);
			         break;
                 case CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS:
                     wgui_fixed_list_register_get_flags_handler(cui_menu_list_menu_item_callback);
                     ShowCategory353Screen_ext((U8*)title_string,
                         title_image,
                         (U8*)lsk_str,
                         (U8*)0,
                         (U8*)rsk_str,
                         (U8*)0,
                         number_of_items,
                         (U8 **)subMenuDataPtrs,
                         (U16 *)gIndexIconsImageList,
                         (U8 **)hintDataPtrs,
                         0,
                         initial_index,
                         gui_buffer);
                     break;
 		         default:
                     wgui_fixed_list_register_get_flags_handler(cui_menu_list_menu_item_callback);
                     ShowCategory353Screen_ext((U8*)title_string,
                         title_image,
                         (U8*)lsk_str,
                         (U8*)0,
                         (U8*)rsk_str,
                         (U8*)0,
                         number_of_items,
                         (U8 **)subMenuDataPtrs,
                         (U16 *)g_cui_menu_current_screen_info->list_menu_icons,
                         (U8 **)hintDataPtrs,
                         0,
                         initial_index,
                         gui_buffer);
                     break;


            }
            break;
        case CUI_MENU_TYPE_OPTION:
            switch (user_data_p->currlist_flags)
            {
                case CUI_MENU_NORMAL_CHECK_BOX_LIST:
                    if (!user_data_p->enable_cascading_option_menu)
                    {
                        SetCheckboxToggleRightSoftkeyFunctions(cui_menu_lsk_handler, cui_menu_rsk_handler);
                        ShowCategory140Screen_ext((U8*)title_string,
                            title_image,
                            number_of_items,
                            (U8 **)subMenuDataPtrs,
                            g_cui_menu_current_screen_info->list_menu_check_states,
                            initial_index,
                            gui_buffer);

                    }
#if defined(__MMI_CASCADED_OPTION_MENU__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MTK_INTERNAL__))
                    else
                    {
#ifndef __MMI_CATEGORY_LIST_SLIM__
                        /* This has to be the leaf level of cascaded menu */
			            g_mmi_cascading_menu_current_level = (S32)user_data_p->current_level_index;			
						wgui_cascading_menu_register_hide_softkey(cui_menu_hide_cascaded_menu_softkey);
			            SetCheckboxToggleRightSoftkeyFunctions(cui_menu_lsk_handler, cui_menu_rsk_handler);
    		            ShowCategory803Screen_ext((U8*)title_string,
                            title_image,
                            number_of_items,
                            (U8 **)subMenuDataPtrs,
                            g_cui_menu_current_screen_info->list_menu_check_states,
                            (S32)user_data_p->current_level_index,
                            2,
                            initial_index,
                            gui_buffer);
#else
                         MMI_ASSERT(0); // For SLIM project MT6060, Cascade Check box list is not supported           
#endif
                    }
#endif
                    break;  
                case CUI_MENU_NORMAL_RADIO_BUTTON_LIST:
                    if (!user_data_p->enable_cascading_option_menu)
                    {
                        ShowCategory36Screen_ext((U8*)title_string,
                            title_image,
                            (U8*)lsk_str,
                            (U8*)0,
                            (U8*)rsk_str,
                            (U8*)0,
                            number_of_items,
                            (U8 **)subMenuDataPtrs,
                            (U16)initial_index,
                            gui_buffer);
                    }
#if defined(__MMI_CASCADED_OPTION_MENU__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MTK_INTERNAL__))
                    else
                    {
#ifndef __MMI_CATEGORY_LIST_SLIM__
                        /* This has to be the leaf level of cascaded menu */
			            g_mmi_cascading_menu_current_level = (S32)user_data_p->current_level_index;	
						wgui_cascading_menu_register_hide_softkey(cui_menu_hide_cascaded_menu_softkey);
			            ShowCategory802Screen_ext(
                           (U8*)title_string,
                            title_image,
                            (U8*)lsk_str,
                            (U8*)0,
                            (U8*)rsk_str,
                            (U8*)0,
                            number_of_items,
                            (U8 **)subMenuDataPtrs,
                            (S32)user_data_p->current_level_index,
                            2,
                            initial_index,
                            gui_buffer);
#else   
                            MMI_ASSERT(0); // For SLIM project MT6060, Cascade option Radio list is not supported           
#endif
                    }
#endif
                    break;
                case CUI_MENU_RADIO_BUTTON_LIST_WITH_HINTS:
                    if(!user_data_p->enable_cascading_option_menu)
                    {
                        ShowCategory109Screen_ext((U8*)title_string,
                            title_image,
                            (U8*)lsk_str,
                            (U8*)0,
                            (U8*)rsk_str,
                            (U8*)0,
                            number_of_items,
                            (U8 **)subMenuDataPtrs,
                            (U8 **)hintDataPtrs,
                            (U16)initial_index,
                            gui_buffer);
                    }
                    else
                    {
                        MMI_ASSERT(0);
                    }
                    break;
                 case CUI_MENU_RADIO_LIST_WITH_SCROLLING_TITLE:
                    if(!user_data_p->enable_cascading_option_menu)
                    {
                        ShowCategory172Screen((U8*)title_string,
                            title_image,
                            (U8*)lsk_str,
                            (U8*)0,
                            (U8*)rsk_str,
                            (U8*)0,
                            number_of_items,
                            (U8 **)subMenuDataPtrs,
                            0,
                            (U16)initial_index,
                            gui_buffer);
                    }
                    else
                    {
                        MMI_ASSERT(0);
                    }
                    break;
				case CUI_MENU_CHECK_BOX_LIST_WITHOUT_TOGGLE:
                case CUI_MENU_LIST_WITH_MENUID_DRIVEN_HIGHLIGHTER:
                case CUI_MENU_LIST_WITH_NO_MARGIN_WHEN_NO_ICON:
                case CUI_MENU_LIST_WITH_NO_ICON:
		        case CUI_MENU_LIST_WITH_DOUBLE_TEXT_SINGLE_ICON:
                case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_TEXT_ICON:
                case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_ICON_TEXT:
		        case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_TEXT_ICON_ICON:
                case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_ICON_TEXT_ICON:
                case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_ICON_ICON_TEXT:
		        case CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_TEXT_ICON_ICON:		
		        case CUI_MENU_LIST_WITH_TEXT_NUMBERED_ITEMS:
		  	        MMI_ASSERT(0); /*currently option menu will only support static fixed list*/
                 case CUI_MENU_NORMAL_LIST_WITH_NUMBERED_ICONS:
                     if (!user_data_p->enable_cascading_option_menu)
                     {
                         wgui_fixed_list_register_get_flags_handler(cui_menu_list_menu_item_callback);
                         ShowCategory353Screen_ext((U8*)title_string,
                             title_image,
                             (U8*)lsk_str,
                             (U8*)0,
                             (U8*)rsk_str,
                             (U8*)0,
                             number_of_items,
                             (U8 **)subMenuDataPtrs,
                             (U16 *)gIndexIconsImageList,
                             (U8 **)hintDataPtrs,
                             0,
                             initial_index,
                             gui_buffer);
                     }
#if defined(__MMI_CASCADED_OPTION_MENU__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MTK_INTERNAL__))
                     else
                     {
                        g_mmi_cascading_menu_current_level = (S32)user_data_p->current_level_index;
						wgui_cascading_menu_register_hide_softkey(cui_menu_hide_cascaded_menu_softkey);
                        wgui_fixed_list_register_get_flags_handler(cui_menu_list_menu_item_callback);
                        ShowCategory801Screen_ext(
                            (U8*)title_string,
                            title_image,
                            (U8*)lsk_str,
                            (U8*)0,
                            (U8*)rsk_str,
                            (U8*)0,
                            number_of_items,
                            (U8 **)subMenuDataPtrs,
                            (U8 **)NULL,
                            g_cui_menu_current_screen_info->list_menu_check_states,
                            (S32)user_data_p->current_level_index,
                            2,
                            initial_index,
                            gui_buffer);
                     }
#endif
					 break;
                default:
                #if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
                    if (user_data_p->enable_fte_sublevel_option_menu)
                    {
                        wgui_fixed_list_register_get_flags_handler(cui_menu_list_menu_item_callback);
						if (is_list_icons_set)
						{
   							wgui_cat1003_show(
								(U8*)title_string,
								title_image,
								(U8*)lsk_str,
								(U8*)0,
								(U8*)rsk_str,
								(U8*)0,
								number_of_items,
								(U8 **)subMenuDataPtrs,
								(U8 **)list_of_icons,
								 0,
								initial_index,
								gui_buffer);
						}
						else
						{
							wgui_cat1003_show(
								(U8*)title_string,
								title_image,
								(U8*)lsk_str,
								(U8*)0,
								(U8*)rsk_str,
								(U8*)0,
								number_of_items,
								(U8 **)subMenuDataPtrs,
								NULL,
								 0,
								initial_index,
								gui_buffer);
						}
                        wgui_cat1003_goback_callback(cui_menu_rsk_handler);
			            break;     
                    }
                #endif
                    if (!user_data_p->enable_cascading_option_menu)
                    {
                        wgui_fixed_list_register_get_flags_handler(cui_menu_list_menu_item_callback);
			            if(is_list_icons_set)
                        {
                            ShowCategory353Screen_ext((U8*)title_string,
                                title_image,
                                (U8*)lsk_str,
                                (U8*)0,
                                (U8*)rsk_str,
                                (U8*)0,
                                number_of_items,
                                (U8 **)subMenuDataPtrs,
                                (U16 *)g_cui_menu_current_screen_info->list_menu_icons,
                                (U8 **)hintDataPtrs,
                                0,
                                initial_index,
                                gui_buffer);
                        }
			            else
                        {
                            ShowCategory353Screen_ext((U8*)title_string,
                            title_image,
                            (U8*)lsk_str,
                            (U8*)0,
                            (U8*)rsk_str,
                            (U8*)0,
                            number_of_items,
                            (U8 **)subMenuDataPtrs,
                            (U16 *)gIndexIconsImageList,
                            (U8 **)hintDataPtrs,
                            0,
                            initial_index,
                            gui_buffer);
			   	
                        }
                        break;
                    }
#if defined(__MMI_CASCADED_OPTION_MENU__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MTK_INTERNAL__))
			        else
                    {
                        g_mmi_cascading_menu_current_level = (S32)user_data_p->current_level_index;
						wgui_cascading_menu_register_hide_softkey(cui_menu_hide_cascaded_menu_softkey);
                        wgui_fixed_list_register_get_flags_handler(cui_menu_list_menu_item_callback);
                        ShowCategory801Screen_ext(
                            (U8*)title_string,
                            title_image,
                            (U8*)lsk_str,
                            (U8*)0,
                            (U8*)rsk_str,
                            (U8*)0,
                            number_of_items,
                            (U8 **)subMenuDataPtrs,
                            (U8 **)NULL,
                            g_cui_menu_current_screen_info->list_menu_check_states,
                            (S32)user_data_p->current_level_index,
                            2,
                            initial_index,
                            gui_buffer);
                    }
#endif
            }
            break;
        default:
            MMI_ASSERT(0);
    }
	user_data_p->is_in_show_func = MMI_FALSE;
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_filter_current_menu_list
 * DESCRIPTION
 *  FIltering the menu list after show event 
 * PARAMETERS
 *  menu_id        : [IN] menu id for which resource needs to be loaded
 *RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static void cui_menu_filter_current_menu_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    mmi_id current_gid;
    S32 separator_index = 0;
    mmi_menu_id child_menu_id;
    S32 i = 0, j = 0, k = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_FILTER_LIST);
    current_gid = mmi_frm_group_get_active_id();
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(current_gid);	
    for (k = 0; k < CUI_MENU_MAX_SEPARATORS; k++)
    {
        g_cui_menu_current_screen_info->list_separator_index[k] = 0xff;      
    }
    while ( i < user_data_p->currlist_no_of_items)
    {
        child_menu_id = g_cui_menu_current_screen_info->list_menu_ids[i];
	    if (cui_menu_is_menu_item_hidden(child_menu_id))
        {
            for (j = i + 1; j < user_data_p->currlist_no_of_items; j++)
            {
                g_cui_menu_current_screen_info->list_menu_ids[j -1] = g_cui_menu_current_screen_info->list_menu_ids[j];
	            mmi_ucs2ncpy((CHAR *)subMenuData[j - 1], (CHAR *)subMenuData[j], MAX_SUBMENU_CHARACTERS);
		        g_cui_menu_current_screen_info->list_menu_icons[j-1] = g_cui_menu_current_screen_info->list_menu_icons[j];
	            mmi_ucs2ncpy((CHAR *)hintData[j - 1], (CHAR *)hintData[j], MAX_SUBMENU_CHARACTERS);
		        g_cui_menu_current_screen_info->list_menu_check_states[j -1] = g_cui_menu_current_screen_info->list_menu_check_states[j]; 	  
				if((user_data_p->currlist_flags >= CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_TEXT_ICON) 
					&& (user_data_p->currlist_flags <= CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_TEXT_ICON_ICON) )
				{
				    g_cui_menu_current_screen_info->list_menu_icons2[j-1] = g_cui_menu_current_screen_info->list_menu_icons2[j];
				
				}
            }
            g_cui_menu_current_screen_info->list_menu_ids[user_data_p->currlist_no_of_items - 1] = 0;
	        mmi_ucs2ncpy((CHAR *)subMenuData[user_data_p->currlist_no_of_items - 1], (CHAR *)L"", 1);
	        g_cui_menu_current_screen_info->list_menu_icons[user_data_p->currlist_no_of_items - 1] = 0;	 
	        mmi_ucs2ncpy((CHAR *)hintData[user_data_p->currlist_no_of_items - 1], (CHAR *)L"", 1);	
	        g_cui_menu_current_screen_info->list_menu_check_states[user_data_p->currlist_no_of_items - 1] = 0; 	 
    		if((user_data_p->currlist_flags >= CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_TEXT_ICON) 
    			&& (user_data_p->currlist_flags <= CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_TEXT_ICON_ICON) )
    		{
    		    g_cui_menu_current_screen_info->list_menu_icons2[user_data_p->currlist_no_of_items - 1] = 0;
    		}
    	    user_data_p->currlist_no_of_items--;	 
        }
        else if (child_menu_id == MMI_MENU_ID_SEPARATOR)
        {
            if (i  >  0)
            {
                MMI_BOOL separator_index_found = MMI_FALSE;		
		        MMI_ASSERT(separator_index < CUI_MENU_MAX_SEPARATORS); 		
                for (k = 0; k < separator_index; k++)
                {
                    if (g_cui_menu_current_screen_info->list_separator_index[k] == i - 1)
                    {
                        separator_index_found = MMI_TRUE;
			            break;			
                    }
                }
		        if (!separator_index_found)
                {
                    g_cui_menu_current_screen_info->list_separator_index[separator_index++] = i - 1;
                }
            }
            for (j = i + 1; j < user_data_p->currlist_no_of_items; j++)
            {
                g_cui_menu_current_screen_info->list_menu_ids[j -1] = g_cui_menu_current_screen_info->list_menu_ids[j];
	            mmi_ucs2ncpy((CHAR *)subMenuData[j - 1], (CHAR *)subMenuData[j], MAX_SUBMENU_CHARACTERS);
		        g_cui_menu_current_screen_info->list_menu_icons[j-1] = g_cui_menu_current_screen_info->list_menu_icons[j];
	            mmi_ucs2ncpy((CHAR *)hintData[j - 1], (CHAR *)hintData[j], MAX_SUBMENU_CHARACTERS);
		        g_cui_menu_current_screen_info->list_menu_check_states[j -1] = g_cui_menu_current_screen_info->list_menu_check_states[j]; 	  
				if((user_data_p->currlist_flags >= CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_TEXT_ICON) 
					&& (user_data_p->currlist_flags <= CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_TEXT_ICON_ICON) )
				{
				    g_cui_menu_current_screen_info->list_menu_icons2[j-1] = g_cui_menu_current_screen_info->list_menu_icons2[j];
				
				}
            }
            g_cui_menu_current_screen_info->list_menu_ids[user_data_p->currlist_no_of_items - 1] =0;
	        mmi_ucs2ncpy((CHAR *)subMenuData[user_data_p->currlist_no_of_items - 1], (CHAR *)L"", 1);
	        g_cui_menu_current_screen_info->list_menu_icons[user_data_p->currlist_no_of_items - 1] = 0;	 
	        mmi_ucs2ncpy((CHAR *)hintData[user_data_p->currlist_no_of_items - 1], (CHAR *)L"", 1);	
	        g_cui_menu_current_screen_info->list_menu_check_states[user_data_p->currlist_no_of_items - 1] = 0; 	 
	        g_cui_menu_current_screen_info->list_menu_check_states[user_data_p->currlist_no_of_items - 1] = 0; 	 
    		if((user_data_p->currlist_flags >= CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_TEXT_ICON) 
    			&& (user_data_p->currlist_flags <= CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_TEXT_ICON_ICON) )
    		{
    		    g_cui_menu_current_screen_info->list_menu_icons2[user_data_p->currlist_no_of_items - 1] = 0;
    		}
    	    user_data_p->currlist_no_of_items--;	 
        }
	    else
        {
            i++;
        }
    }
	if(user_data_p->mode == CUI_MENU_SRC_TYPE_RESOURCE)
	{
        if((user_data_p->is_item_flags_from_res == MMI_TRUE) && (user_data_p->override_non_leaf_by_app == MMI_FALSE))
	    {
            if( (user_data_p->currlist_flags >= CUI_MENU_NORMAL_CHECK_BOX_LIST) 
		        && (user_data_p->currlist_flags <= CUI_MENU_RADIO_LIST_WITH_SCROLLING_TITLE))	
            {
                return; /*Menu items in Radio and check box lists are always leaf nodes so no need to set submenu flag*/
            }
			for (i = 0;i < user_data_p->currlist_no_of_items; i++)
			{
                S32 sub_menu_flag = 0;
				sub_menu_flag = GetNumOfChild_Ext(g_cui_menu_current_screen_info->list_menu_ids[i]);
#if defined(__MMI_CASCADED_OPTION_MENU__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MTK_INTERNAL__))
			    if(user_data_p->enable_cascading_option_menu)
                {
                    if (sub_menu_flag)
					{
					    g_cui_menu_current_screen_info->list_menu_check_states[i] |= (UI_CASCADING_MENU_WITH_SUBMENU);
                    }
                    else
                    {
                        g_cui_menu_current_screen_info->list_menu_check_states[i] &= (~UI_CASCADING_MENU_WITH_SUBMENU);
	
                    }
                }
                else
#endif
                {
                    if (sub_menu_flag)
                    {
                        g_cui_menu_current_screen_info->list_menu_check_states[i] |= (CUI_MENU_ITEM_WITH_SUB_MENU);
                    }
                    else
                    {
                        g_cui_menu_current_screen_info->list_menu_check_states[i] &= (~CUI_MENU_ITEM_WITH_SUB_MENU);
	
                     }
                }
            }
        }
    }

	    
	            
		
	
}
/*****************************************************************************              
 * FUNCTION
 *  cui_menu_load_res
 * DESCRIPTION
 *  set root id of menu cui
 * PARAMETERS
 *  menu_id        : [IN] menu id for which resource needs to be loaded
 *RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static void cui_menu_load_res(mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    mmi_id current_gid;

    mmi_menu_id child_menu_id;
    S32 i;
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_LOAD_RES_LIST);
    current_gid = mmi_frm_group_get_active_id();
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(current_gid);
    GetSequenceItemIds(menu_id, g_cui_menu_current_screen_info->list_menu_ids);
    user_data_p->currlist_no_of_items = GetNumOfChild(menu_id);
    for (i = 0; i < user_data_p->currlist_no_of_items; i++)
    {
        child_menu_id = g_cui_menu_current_screen_info->list_menu_ids[i];
	 if (child_menu_id != MMI_MENU_ID_SEPARATOR)
        {
            WCHAR* menu_string = NULL;
	     menu_string = get_string((MMI_ID_TYPE)GetStringIdOfItem(child_menu_id));		
	     if (menu_string)
	     {
	         mmi_ucs2ncpy((CHAR *)subMenuData[i], (CHAR *)menu_string, MAX_SUBMENU_CHARACTERS);
	     }
	     else
	     {
	         mmi_ucs2ncpy((CHAR *)subMenuData[i], (CHAR *)L"", 1);
	     }
	     memset(hintData[i], 0x00, ENCODING_LENGTH);		
            g_cui_menu_current_screen_info->list_menu_icons[i] = GetImageIdOfItem(child_menu_id);
            if(GetNumOfChild(child_menu_id))
            {
#if defined(__MMI_CASCADED_OPTION_MENU__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MTK_INTERNAL__))
                if(user_data_p->enable_cascading_option_menu)
                {
                    g_cui_menu_current_screen_info->list_menu_check_states[i] |= UI_CASCADING_MENU_WITH_SUBMENU; 
                }
                else
#endif
                {
                    g_cui_menu_current_screen_info->list_menu_check_states[i] |= (CUI_MENU_ITEM_WITH_SUB_MENU);
                }
            }
        }
    }

}


static void cui_menu_post_action_handling(cui_menu_obj_struct* user_data_p, S32 menu_item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_POST_ACTION_HANDLING);
    if( (user_data_p->currlist_flags >= CUI_MENU_NORMAL_CHECK_BOX_LIST) 
		&& (user_data_p->currlist_flags <= CUI_MENU_RADIO_LIST_WITH_SCROLLING_TITLE))	
    {
        return;  /*check box and radio button list items has to be the leaf nodes */
    }
#if defined(__MMI_CASCADED_OPTION_MENU__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MTK_INTERNAL__))
    if(user_data_p->enable_cascading_option_menu)
    {
        if ( !(g_cui_menu_current_screen_info->list_menu_check_states[menu_item_index] & UI_CASCADING_MENU_WITH_SUBMENU) )
        {
           return; /* selected menu id is a leaf node*/
        }
    }
    else
#endif
    {
        if ( !(g_cui_menu_current_screen_info->list_menu_check_states[menu_item_index] & CUI_MENU_ITEM_WITH_SUB_MENU) )
        {
            return; /* selected menu id is a leaf node*/
        }
    }    	
	
    user_data_p->new_scrn_id++;
    user_data_p->prevlist_parent_id = user_data_p->currlist_parent_id;
    user_data_p->currlist_parent_id = user_data_p->currlist_highlighted_id; /* move to level n+1 from n */
    user_data_p->current_level_index++;
    user_data_p->tree_path[user_data_p->current_level_index] = user_data_p->currlist_parent_id;	
	user_data_p->next_level_fw_scenario = MMI_TRUE;
    cui_menu_screen_entry();
}


#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_tap_hdlr
 * DESCRIPTION
 *  It is the tap event hdlr for the list.
 *  It send the tap on highlighted item to
 * PARAMETERS
 *  tap_type             :  [IN] type of tap event mmi_tap_type_enum 
 *  index                  : [IN] index in list
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static void cui_menu_tap_hdlr(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    mmi_id current_gid;
    cui_menu_event_struct evt;
    S32 menu_item_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_TAP_HANDLER);
    if (tap_type == ENUM_TAP_ON_NONHIGHLIGHTED_ITEM) 
    {
        /* only change highlight.  do nothing in tap callback function */
        return;
    }
    /*Send the tap on highlighted item event to APP */	
    current_gid = mmi_frm_group_get_active_id();
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(current_gid);
	if (user_data_p->currlist_highlighted_id == (mmi_menu_id)CUI_MENU_MENUID_NOT_FOUND)
	{
	    return;
	}
    menu_item_index = cui_menu_get_index_from_menu_id_list(user_data_p->currlist_highlighted_id);
    if(menu_item_index == CUI_MENU_INDEX_NOT_FOUND)
    {
        return;
    }
	user_data_p->scenario = CUI_MENU_FW_SCENARIO;
    MMI_FRM_INIT_GROUP_EVENT(&evt, sizeof(cui_menu_event_struct), current_gid);
    evt.evt_id = EVT_ID_CUI_MENU_ITEM_TAP;
    evt.parent_menu_id = user_data_p->currlist_parent_id;
    evt.highlighted_menu_id = user_data_p->currlist_highlighted_id;
    evt.app_data = user_data_p->app_data;
    evt.cui_menu_event_flags = 0;	
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_ITEM_TAP_EVT_START);
    mmi_frm_group_send_to_caller(current_gid, (mmi_group_event_struct *)&evt);
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_ITEM_TAP_EVT_END);
    if (user_data_p->is_pause ==  MMI_TRUE)
    {
        return; /* If the APP has called cui_menu_pause during the tap event then we will return and wait for APP to call cui_menu_play */
    }
    if (current_gid != mmi_frm_group_get_active_id()) /* Either the CUI Menu group got closed or went into history or may be we are on non-leaf node */
    {
        return; /* Either the CUI Menu group got closed or went into history */
    }
    cui_menu_post_action_handling(user_data_p, menu_item_index);
}
#endif


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_lsk_handler
 * DESCRIPTION
 *  lsk hanlder for cui menu screen
 * PARAMETERS
 *  void     
 *RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static void cui_menu_csk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    mmi_id current_gid;
    cui_menu_event_struct evt;
    S32 menu_item_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_CSK_HANDLER);
    current_gid = mmi_frm_group_get_active_id();
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(current_gid);
	
	if (user_data_p->currlist_highlighted_id == (mmi_menu_id)CUI_MENU_MENUID_NOT_FOUND)
	{
	    return;
	}
    menu_item_index = cui_menu_get_index_from_menu_id_list(user_data_p->currlist_highlighted_id);
    if(menu_item_index == CUI_MENU_INDEX_NOT_FOUND)
    {
        return;
    }
	user_data_p->scenario = CUI_MENU_FW_SCENARIO;
    MMI_FRM_INIT_GROUP_EVENT(&evt, sizeof(cui_menu_event_struct), current_gid);
    evt.evt_id = EVT_ID_CUI_MENU_ITEM_CSK_SELECT;
    evt.parent_menu_id = user_data_p->currlist_parent_id;
    evt.highlighted_menu_id = user_data_p->currlist_highlighted_id;
    evt.app_data = user_data_p->app_data;
    evt.cui_menu_event_flags = 0;
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_ITEM_CSK_SELECT_EVT_START);
    mmi_frm_group_send_to_caller(current_gid, (mmi_group_event_struct *)&evt);
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_ITEM_CSK_SELECT_EVT_END);
    if (user_data_p->is_pause ==  MMI_TRUE)
    {
        return; /* If the APP has called cui_menu_pause during the select event then we will return and wait for APP to call cui_menu_play */
    }
    if (current_gid != mmi_frm_group_get_active_id()) /* Either the CUI Menu group got closed or went into history or may be we are on non-leaf node */
    {
        return; /* Either the CUI Menu group got closed or went into history */
    }
    cui_menu_post_action_handling(user_data_p, menu_item_index);
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_lsk_handler
 * DESCRIPTION
 *  lsk hanlder for cui menu screen
 * PARAMETERS
 *  void     
 *RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static void cui_menu_lsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    mmi_id current_gid;
    cui_menu_event_struct evt;
    S32 menu_item_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_LSK_HANDLER);
    current_gid = mmi_frm_group_get_active_id();
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(current_gid);
	if (user_data_p->currlist_highlighted_id == (mmi_menu_id)CUI_MENU_MENUID_NOT_FOUND)
	{
	    return;
	}
    menu_item_index = cui_menu_get_index_from_menu_id_list(user_data_p->currlist_highlighted_id);
    if(menu_item_index == CUI_MENU_INDEX_NOT_FOUND)
    {
        return;
    }
	user_data_p->scenario = CUI_MENU_FW_SCENARIO;
    MMI_FRM_INIT_GROUP_EVENT(&evt, sizeof(cui_menu_event_struct), current_gid);
    evt.evt_id = EVT_ID_CUI_MENU_ITEM_SELECT;
    evt.parent_menu_id = user_data_p->currlist_parent_id;
    evt.highlighted_menu_id = user_data_p->currlist_highlighted_id;
    evt.app_data = user_data_p->app_data;
    evt.cui_menu_event_flags = 0;	
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_ITEM_SELECT_EVT_START);
    mmi_frm_group_send_to_caller(current_gid, (mmi_group_event_struct *)&evt);
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_ITEM_SELECT_EVT_END);
    if (user_data_p->is_pause ==  MMI_TRUE)
    {
        return; /* If the APP has called cui_menu_pause during the select event then we will return and wait for APP to call cui_menu_play */
    }
    if (current_gid != mmi_frm_group_get_active_id()) /* Either the CUI Menu group got closed or went into history or may be we are on non-leaf node */
    {
        return; /* Either the CUI Menu group got closed or went into history */
    }
    cui_menu_post_action_handling(user_data_p, menu_item_index);
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_rsk_handler
 * DESCRIPTION
 *  rsk hanlder for cui menu screen
 * PARAMETERS
 *  void     
 *RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static void cui_menu_rsk_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    mmi_id current_gid;
    cui_menu_event_struct evt;
    MMI_BOOL is_first_level = MMI_FALSE;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_RSK_HANDLER);
    current_gid = mmi_frm_group_get_active_id();
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(current_gid);
	user_data_p->scenario = CUI_MENU_BK_SCENARIO;
    if(((user_data_p->enable_cascading_option_menu)
    #if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
        || (user_data_p->enable_fte_sublevel_option_menu)
    #endif
        ) && (user_data_p->current_level_index))
    {
        mmi_frm_switch_small_screen_redraw(MMI_FALSE);	
    }
#ifdef __MMI_SCREEN_ROTATE__    
    if (mmi_frm_is_screen_width_height_swapped())
    {
        mmi_frm_enable_clear_rotated_screen(MMI_FALSE);
    }	
#endif		
    user_data_p ->prevlist_parent_id = user_data_p->currlist_parent_id;
    user_data_p->tree_path[user_data_p->current_level_index] = 0;
    if(user_data_p->current_level_index)
    {
        user_data_p->current_level_index--;
    }
    else
    {
        is_first_level = MMI_TRUE;
    }
    user_data_p->currlist_parent_id = user_data_p->tree_path[user_data_p->current_level_index];
    user_data_p->new_scrn_id--;
    if(!is_first_level)
    {
        mmi_frm_scrn_close(current_gid, (mmi_id)(user_data_p->new_scrn_id + 1));
    }
    else
    {
        MMI_FRM_INIT_GROUP_EVENT(&evt, sizeof(cui_menu_event_struct), current_gid);
	    evt.evt_id = EVT_ID_CUI_MENU_CLOSE_REQUEST;
	    evt.parent_menu_id = 0;
	    evt.highlighted_menu_id = 0;	
	    evt.app_data = user_data_p->app_data;
	    evt.cui_menu_event_flags = 0;	
        MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_CLOSE_REQUEST_EVT_START);
        mmi_frm_group_send_to_caller(current_gid, (mmi_group_event_struct *)&evt);
        MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_CLOSE_REQUEST_EVT_END);
    }
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_checkbox_change_state_handler
 * DESCRIPTION
 *  Left softkey handler for checkbox list. 
 * PARAMETERS
 *  void     
 *RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static void cui_menu_checkbox_change_state_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    mmi_id current_gid;
    cui_menu_event_struct evt;
    S32 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_CHECKBOX_CN_STATE_HANDLER);
    current_gid = mmi_frm_group_get_active_id();
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(current_gid);
    MMI_FRM_INIT_GROUP_EVENT(&evt, sizeof(cui_menu_event_struct), current_gid);
    evt.evt_id = EVT_ID_CUI_MENU_CHECKBOX_CHANGE_STATE;
    evt.parent_menu_id = user_data_p->currlist_parent_id;
    evt.highlighted_menu_id = user_data_p->currlist_highlighted_id;
    evt.app_data = user_data_p->app_data;
    evt.cui_menu_event_flags = 0;	
    toggle_check_list_handle_left_softkey_up();	
    mmi_frm_group_send_to_caller(current_gid, (mmi_group_event_struct *)&evt);
    for(index = 0; index < user_data_p->currlist_no_of_items; index++)
    {
        if (g_cui_menu_current_screen_info->list_menu_check_states[index])
        {
            select_fixed_twostate_item(index);
        }
        else
        {
            unselect_fixed_twostate_item(index);
        }
    }
    redraw_fixed_list();	
}

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_hilite_handler
 * DESCRIPTION
 *  hilite handler for the list menu of cui menu
 * PARAMETERS
 *  index     : [IN] index in list
 *RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static void cui_menu_hilite_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    mmi_id current_gid;
    cui_menu_event_struct evt;
    WCHAR* lsk_str; 
#ifndef __MMI_WGUI_DISABLE_CSK__ 
    PU8 img; 	
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_HILITE_HANDLER, index);
    current_gid = mmi_frm_group_get_active_id();
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(current_gid);
    user_data_p->currlist_highlighted_id = cui_menu_get_menu_id_from_menu_id_list(index);
    gui_lock_double_buffer();
    if(user_data_p->currlist_highlighted_id != ((mmi_menu_id)CUI_MENU_MENUID_NOT_FOUND))
    {
        if (!(user_data_p->currlist_flags & CUI_MENU_NORMAL_CHECK_BOX_LIST)) 
        {
            lsk_str = user_data_p->default_lsk_string;	
            if (user_data_p->currlist_lsk_string) 
            {
                lsk_str = user_data_p->currlist_lsk_string;
            } 
			set_left_softkey_label(lsk_str);
            set_left_softkey_icon(NULL);
	        register_left_softkey_handler();	
#ifndef __MMI_WGUI_DISABLE_CSK__ 
            if (user_data_p->app_csk)
            {
                if (user_data_p->currlist_csk_string)
                {
                    set_softkey_label(user_data_p->currlist_csk_string, MMI_CENTER_SOFTKEY);
                }
	            else
	            {
                    set_softkey_label(NULL, MMI_CENTER_SOFTKEY);    
	            }
	            if (user_data_p->currlist_csk_image)
                {
                    set_softkey_icon(user_data_p->currlist_csk_image, MMI_CENTER_SOFTKEY);
                }
	            else
                {
                    img = get_image(IMG_GLOBAL_COMMON_CSK);
                    set_softkey_icon(img, MMI_CENTER_SOFTKEY);
                }
            }
            else
            {
                img = get_image(IMG_GLOBAL_COMMON_CSK);
	            set_softkey_label(NULL, MMI_CENTER_SOFTKEY);  
                set_softkey_icon(img, MMI_CENTER_SOFTKEY);
            }
#endif
	        register_softkey_handler(MMI_CENTER_SOFTKEY);
			if(user_data_p->is_in_show_func == MMI_FALSE)
			{
			    redraw_left_softkey();
			    redraw_center_softkey();	
			}
#if defined(__MMI_CASCADED_OPTION_MENU__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MTK_INTERNAL__))
	        if(user_data_p->enable_cascading_option_menu)
	        {
                U16 keyCode;
#if defined (__MMI_BIDI_ALG__)            
                if (mmi_fe_get_r2l_state())
                {
                    keyCode = KEY_LEFT_ARROW;
                }
                else
#endif
                {
                    keyCode = KEY_RIGHT_ARROW;
                }
                if ((g_cui_menu_current_screen_info->list_menu_check_states[index] & UI_CASCADING_MENU_WITH_SUBMENU)
                    && (user_data_p->current_level_index == 0))
	            {
                    SetKeyHandler(cui_menu_lsk_handler, keyCode, KEY_EVENT_DOWN);
	            }
	            else
	            {
                    ClearKeyHandler(keyCode, KEY_EVENT_DOWN);
	            }
	        }
#endif
        }
    }
    else
    {
		set_left_softkey_label(NULL);
        set_left_softkey_icon(NULL);
#ifndef __MMI_WGUI_DISABLE_CSK__
        set_softkey_label(NULL, MMI_CENTER_SOFTKEY);
        set_softkey_icon(NULL, MMI_CENTER_SOFTKEY);
#endif
		ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
		if(user_data_p->is_in_show_func == MMI_FALSE)
		{
		    redraw_left_softkey();
			redraw_center_softkey();
		}
    }
	MMI_FRM_INIT_GROUP_EVENT(&evt, sizeof(cui_menu_event_struct), current_gid);
    evt.evt_id = EVT_ID_CUI_MENU_ITEM_HILITE;
    evt.highlighted_menu_id = user_data_p->currlist_highlighted_id;
    evt.parent_menu_id = user_data_p->currlist_parent_id;
    evt.app_data = user_data_p->app_data;
    evt.cui_menu_event_flags = 0;	
    user_data_p->highlight_evt_handler = MMI_TRUE;
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_ITEM_HILITE_EVT_START);
    mmi_frm_group_send_to_caller(current_gid, (mmi_group_event_struct *)&evt);
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_ITEM_HILITE_EVT_END);
    user_data_p->highlight_evt_handler = MMI_FALSE;
    gui_unlock_double_buffer();
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
#endif

static void cui_menu_screen_entry_internal(mmi_id current_gid, cui_menu_obj_struct* user_data_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct evt;
    U8 *guiBuffer = NULL;
    S32 ret_entry_event = 0;	
    MMI_BOOL  isAllItemDisabled = MMI_FALSE;
    S32 index = 0;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_SCREEN_ENTRY_INTERNAL, current_gid);
    if(user_data_p->menu_type != CUI_MENU_TYPE_OPTION)
    {
        if ((user_data_p->new_scrn_id < CUI_MENU_BASE) ||
            (user_data_p->new_scrn_id > (CUI_MENU_BASE + CUI_MENU_MAX_SCREEN_COUNT_APP_MENU - 1)))
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
        if ((user_data_p->new_scrn_id < CUI_MENU_BASE) ||
            (user_data_p->new_scrn_id > (CUI_MENU_BASE + CUI_MENU_MAX_SCREEN_COUNT_OPTION_MENU - 1)))
        {
            MMI_ASSERT(0);
        }
    }
#ifdef __MMI_SCREEN_ROTATE__    
    mmi_frm_screen_rotate(user_data_p->rotate_type);
    if (mmi_frm_is_screen_width_height_swapped())
    {
        mmi_frm_enable_clear_rotated_screen(MMI_FALSE);
    }	
#endif	
    if (!mmi_frm_scrn_enter(current_gid, (mmi_id)(user_data_p->new_scrn_id), cui_menu_screen_exit, cui_menu_screen_entry, MMI_FRM_UNKNOW_SCRN))
    {
        return;
    }	
#ifdef __MMI_SCREEN_ROTATE__  
    mmi_frm_enable_clear_rotated_screen(MMI_TRUE);
#endif
    user_data_p->enable_refresh_screen = MMI_FALSE;  /* Disable the refresh screen before creating the new menu list and sending the show event */		
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();

    user_data_p->prevlist_parent_id = user_data_p->currlist_parent_id;
    g_cui_menu_current_screen_info = (cui_menu_current_screen_info_struct *)mmi_frm_scrmem_alloc(CUI_MENU_SCREEN_INFO_SIZE);
    MMI_ASSERT(g_cui_menu_current_screen_info != NULL);
    memset(g_cui_menu_current_screen_info, 0, sizeof(cui_menu_current_screen_info_struct));
    user_data_p->currlist_menu_ids = g_cui_menu_current_screen_info->list_menu_ids;

    if (user_data_p->mode == CUI_MENU_SRC_TYPE_RESOURCE)
    {
        cui_menu_load_res(user_data_p->currlist_parent_id);
    }

    if (user_data_p->mode == CUI_MENU_SRC_TYPE_RESOURCE)
    {
        cui_menu_get_currlist_flags_from_resource(current_gid);
    }	

    MMI_FRM_INIT_GROUP_EVENT(&evt, sizeof(cui_menu_event_struct), current_gid);
    evt.evt_id = EVT_ID_CUI_MENU_LIST_ENTRY;
    if(guiBuffer)
    {
        evt.cui_menu_event_flags = CUI_MENU_LIST_FROM_HISTORY; 
    }
    else
    {
        evt.cui_menu_event_flags = 0;	
    }
    evt.parent_menu_id = user_data_p->currlist_parent_id;
    evt.highlighted_menu_id = 0;
    evt.app_data = user_data_p->app_data;
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_LIST_ENTRY_EVT_START);
    ret_entry_event = mmi_frm_group_send_to_caller(current_gid, (mmi_group_event_struct *)&evt);
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_LIST_ENTRY_EVT_END);
    if(ret_entry_event == MMI_RET_ERR)
    {
        MMI_FRM_INIT_GROUP_EVENT(&evt, sizeof(cui_menu_event_struct), current_gid);
        evt.evt_id = EVT_ID_CUI_MENU_CLOSE_REQUEST;
        evt.parent_menu_id = 0;
        evt.highlighted_menu_id = 0;	
        evt.app_data = user_data_p->app_data;
        evt.cui_menu_event_flags = 0;	
        MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_CLOSE_REQUEST_EVT_START);
        mmi_frm_group_send_to_caller(current_gid, (mmi_group_event_struct *)&evt);
        MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_CLOSE_REQUEST_EVT_END);
        return; 
    }	
    cui_menu_filter_current_menu_list();
    if(!user_data_p->currlist_no_of_items)
    {
        MMI_FRM_INIT_GROUP_EVENT(&evt, sizeof(cui_menu_event_struct), current_gid);
        evt.evt_id = EVT_ID_CUI_MENU_CLOSE_REQUEST;
        evt.parent_menu_id = 0;
        evt.highlighted_menu_id = 0;	
        evt.app_data = user_data_p->app_data;
        evt.cui_menu_event_flags = 0;	
        MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_CLOSE_REQUEST_EVT_START);
        mmi_frm_group_send_to_caller(current_gid, (mmi_group_event_struct *)&evt);
        MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_CLOSE_REQUEST_EVT_END);
        return; 
    }
    if((user_data_p->menu_type == CUI_MENU_TYPE_OPTION) && (user_data_p->current_level_index == 0))
    {
        mmi_frm_switch_small_screen_redraw(MMI_TRUE);
        if (!g_cui_menu_cascading_cache_buf.buf_ptr)
        {
            g_cui_menu_cascading_cache_buf.buf_ptr = (U8*) mmi_frm_scrmem_alloc(CUI_MENU_CASCADING_ASM_BUFFER_SIZE);
            MMI_DBG_ASSERT(g_cui_menu_cascading_cache_buf.buf_ptr); 
            mmi_frm_scrmem_disable_debug_leak_check();
            if(!guiBuffer)
            {
                S32 layer_width, layer_height;
                gdi_color_format cf;
                gdi_image_cache_bmp_get(0, 0, MAIN_LCD_device_width - 1, MAIN_LCD_device_height - 1, &g_cui_menu_cascading_cache_buf); 	 
                /* replace GDI_COLOR_TRANSPARENT source key */
                gdi_layer_get_dimension(&layer_width, &layer_height);
                gdi_layer_get_color_format(&cf);

                gd_replace_src_key[cf](
                    g_cui_menu_cascading_cache_buf.buf_ptr,
                    layer_width,
                    0,
                    0,
                    0,
                    0,
                    layer_width - 1,
                    layer_height - 1,
                    GDI_COLOR_TRANSPARENT,
                    layer_width,
                    layer_height);

            }
        }
    }

    RegisterHighlightHandler(cui_menu_hilite_handler);

#ifndef __MMI_WGUI_DISABLE_CSK__
    if (!(user_data_p->currlist_flags & CUI_MENU_NORMAL_CHECK_BOX_LIST))
    {
        PU8 img;
        if (user_data_p->app_csk)
        {
            if (user_data_p->currlist_csk_string)
            {
                set_softkey_label(user_data_p->currlist_csk_string, MMI_CENTER_SOFTKEY);
            }
            if (user_data_p->currlist_csk_image)
            {
                set_softkey_icon(user_data_p->currlist_csk_image, MMI_CENTER_SOFTKEY);
            }
            else
            {
                img = get_image(IMG_GLOBAL_COMMON_CSK);
                set_softkey_icon(img, MMI_CENTER_SOFTKEY);
            }
        }
        else
        {
            img = get_image(IMG_GLOBAL_COMMON_CSK);
            set_softkey_icon(img, MMI_CENTER_SOFTKEY);
        }
    }
    else
    {
        PU8 img;
        img = get_image(IMG_GLOBAL_MARK_CSK);
        set_softkey_icon(img, MMI_CENTER_SOFTKEY);
    }	
#endif
    cui_menu_show_list(user_data_p, guiBuffer);
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
    if (user_data_p->enable_tap_highlight == MMI_TRUE)
    {
        wgui_register_tap_callback(cui_menu_tap_hdlr);
    }
#endif /*_MMI_FTE_SUPPORT__ */	 
    user_data_p->enable_refresh_screen = MMI_TRUE;	/*Enable refresh screen after the show list for the current screen */
    if (user_data_p->currlist_flags & CUI_MENU_NORMAL_CHECK_BOX_LIST)
    {
        for(index = 0; index < user_data_p->currlist_no_of_items; index++)
        {
            if (!cui_menu_is_menu_item_disabled(cui_menu_get_menu_id_from_menu_id_list(index)))
            {
                break;
            }
        }
    

        if (index == user_data_p->currlist_no_of_items)
        {
            isAllItemDisabled = MMI_TRUE;
        }
    }

    if (!(user_data_p->currlist_flags & CUI_MENU_NORMAL_CHECK_BOX_LIST))
    {
        register_softkey_handler(MMI_CENTER_SOFTKEY);	
        if (user_data_p->app_csk)
        {
            SetCenterSoftkeyFunction(cui_menu_csk_handler, KEY_EVENT_UP);
        }
        else
        {
            SetCenterSoftkeyFunction(cui_menu_lsk_handler, KEY_EVENT_UP);
        }
#ifndef __MMI_WGUI_DISABLE_CSK__ 
        redraw_center_softkey();
#endif
    }
    else
    {
        if (!isAllItemDisabled)        
        {
            register_softkey_handler(MMI_CENTER_SOFTKEY);
            SetCenterSoftkeyFunction(cui_menu_checkbox_change_state_handler, KEY_EVENT_UP);        
#ifndef __MMI_WGUI_DISABLE_CSK__ 
            redraw_center_softkey();
#endif
        }
        else
        {
            clear_softkey_handler(MMI_CENTER_SOFTKEY);
        }

    }
    if(!user_data_p->enable_cascading_option_menu)
    {
        if (!(user_data_p->currlist_flags & CUI_MENU_NORMAL_CHECK_BOX_LIST)) 
        {
            SetRightSoftkeyFunction(cui_menu_rsk_handler, KEY_EVENT_UP);
            SetLeftSoftkeyFunction(cui_menu_lsk_handler, KEY_EVENT_UP);
        }
        else
        {
            if (!isAllItemDisabled)
            {
                set_left_softkey_function(cui_menu_checkbox_change_state_handler, KEY_EVENT_UP);
            }
            else
            {
                 ChangeLeftSoftkey(NULL, NULL);
            }
        }
        ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
        ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    }
#if defined(__MMI_CASCADED_OPTION_MENU__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MTK_INTERNAL__))
    else /* in case of cascaded option menu */
    {
        if (!(user_data_p->currlist_flags & CUI_MENU_NORMAL_CHECK_BOX_LIST)) 
        {
            S32 menu_index = 0;   
            U16 keyCode;
            SetLeftSoftkeyFunction(cui_menu_lsk_handler, KEY_EVENT_UP);
            SetRightSoftkeyFunction(cui_menu_rsk_handler, KEY_EVENT_UP);
            menu_index =  cui_menu_get_index_from_menu_id_list(user_data_p->currlist_highlighted_id);
#if defined (__MMI_BIDI_ALG__)            
            if (mmi_fe_get_r2l_state())
            {
                keyCode = KEY_LEFT_ARROW;
            }
            else
#endif
            {
                keyCode = KEY_RIGHT_ARROW;
            }

            if(menu_index != CUI_MENU_INDEX_NOT_FOUND)
            {
                if ((g_cui_menu_current_screen_info->list_menu_check_states[menu_index] & UI_CASCADING_MENU_WITH_SUBMENU) && (user_data_p->current_level_index == 0))
                {
                    SetKeyHandler(cui_menu_lsk_handler, keyCode, KEY_EVENT_DOWN);
                }
                else
                {
                    ClearKeyHandler(keyCode, KEY_EVENT_DOWN);
                }
            }
            else
            {
                ClearKeyHandler(keyCode, KEY_EVENT_DOWN);
            }
#if defined (__MMI_BIDI_ALG__)            
            if (mmi_fe_get_r2l_state())
            {
                keyCode = KEY_RIGHT_ARROW;
            }
            else
#endif
            {
                keyCode = KEY_LEFT_ARROW;
            }
            if(user_data_p->current_level_index)
            {
                SetKeyHandler(cui_menu_rsk_handler, keyCode, KEY_EVENT_DOWN);
            }
            else
            {
                ClearKeyHandler(keyCode, KEY_EVENT_DOWN);
            }
        }
        else
        {
            if (!isAllItemDisabled)
            {
                set_left_softkey_function(cui_menu_checkbox_change_state_handler, KEY_EVENT_UP);
            }
            else
            {
                 ChangeLeftSoftkey(NULL, NULL);
            }
            ClearKeyHandler(KEY_LEFT_ARROW, KEY_EVENT_DOWN);
            ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
        }
    }
#endif

}

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_screen_first_entry
 * DESCRIPTION
 *  Entry Screen for menu cui for first time from run
 * PARAMETERS
 *  void
 * RETURNS
 *  None
 * RETURN VALUES
 *  None
*****************************************************************************/
static void cui_menu_screen_first_entry(mmi_scrn_essential_struct *screen_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    mmi_id current_gid = screen_data->group_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_SCREEN_FIRST_ENTRY, current_gid);
    user_data_p = (cui_menu_obj_struct*)screen_data->user_data;
	cui_menu_screen_entry_internal(current_gid, user_data_p);
}

static void cui_menu_screen_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    mmi_id current_gid;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_gid = mmi_frm_group_get_active_id();
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_SCREEN_ENTRY, current_gid);
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(current_gid);
    cui_menu_screen_entry_internal(current_gid, user_data_p);
}

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_screen_exit
 * DESCRIPTION
 *  exit screen for menu cui
 * PARAMETERS
 *  void
 * RETURNS
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static void cui_menu_screen_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    mmi_id current_gid;
    cui_menu_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_gid = mmi_frm_group_get_active_id();
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_SCREEN_EXIT, current_gid);
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(current_gid);
    MMI_FRM_INIT_GROUP_EVENT(&evt, sizeof(cui_menu_event_struct), current_gid);
    evt.evt_id = EVT_ID_CUI_MENU_LIST_EXIT;
    evt.parent_menu_id = user_data_p->prevlist_parent_id;
    evt.highlighted_menu_id = 0;
    evt.app_data = user_data_p->app_data;
    if (user_data_p->scenario == CUI_MENU_BK_SCENARIO)
    {
        evt.cui_menu_event_flags = CUI_MENU_LIST_FROM_HISTORY;	
    }
    else 
    {
        evt.cui_menu_event_flags = 0;	
    }
    mmi_frm_group_send_to_caller(current_gid, (mmi_group_event_struct *)&evt);
    if(user_data_p->menu_type == CUI_MENU_TYPE_OPTION)
    {
        if (!((user_data_p->scenario == CUI_MENU_FW_SCENARIO)
		    &&(user_data_p->next_level_fw_scenario == MMI_TRUE)))
	    {
            if (g_cui_menu_cascading_cache_buf.buf_ptr)
			{
#ifndef __MMI_UI_MENU_SLIM__
                gui_effect_slide_close();
#endif
				gdi_image_cache_bmp_draw(0, 0, &g_cui_menu_cascading_cache_buf);   
		
				/* disable SSE while go back from 2nd level of cascading menu to 1st one */
				/* otherwise, it will look like re-enter to 1st one from the previous cached screen */
				#ifdef __MMI_SCREEN_SWITCH_EFFECT__
					gui_screen_switch_effect_block(MMI_TRUE);
				#endif
			}
        }
	}
    if(g_cui_menu_current_screen_info)
    {
        mmi_frm_scrmem_free((void*)g_cui_menu_current_screen_info);
        g_cui_menu_current_screen_info = NULL;
    }
#if defined(__MMI_CASCADED_OPTION_MENU__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MTK_INTERNAL__))
    if(user_data_p->enable_cascading_option_menu)
    {
        wgui_cat800_restore_softkey_bkg();
    }
#endif
    user_data_p->currlist_highlighted_id = 0;
    user_data_p->currlist_flags = 0;
    user_data_p->currlist_no_of_items = 0;
    user_data_p->currlist_title_string = 0;
    user_data_p->currlist_title_image = 0;
    user_data_p->currlist_lsk_string = 0;
    user_data_p->currlist_rsk_string = 0;
    user_data_p->currlist_csk_string = NULL;
    user_data_p->currlist_csk_image = NULL;
    user_data_p->app_csk = MMI_FALSE;	
    user_data_p->access_by_shortcut = CUI_MENU_ACCESS_BY_SHORTCUT_DEFAULT;	
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
    user_data_p->enable_tap_highlight = MMI_FALSE;	
#endif
    user_data_p->override_non_leaf_by_app = MMI_FALSE;
    user_data_p->is_in_show_func = MMI_FALSE;
	user_data_p->scenario = CUI_MENU_NO_SCENARIO;
	user_data_p->next_level_fw_scenario = MMI_FALSE;
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_init
 * DESCRIPTION
 *  Initialize the menu CUI to be called on gui initialization
 * PARAMETERS
 *  void                   
 * RETURNS
 *  void
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(cui_menu_objs, 0, (sizeof(cui_menu_obj_struct)*CUI_MENU_MAX_INSTANCE));
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_proc
 * DESCRIPTION
 *  create cui menu
 * PARAMETERS
 *  evt            : [IN]     Receives event from framework 
 * RETURNS
 *  mmi_ret
 * RETURN VALUES
 *  error code
********************************************************************************/
mmi_ret cui_menu_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    mmi_scenario_evt_struct *evt_ext = NULL;
    cui_menu_event_struct evt_for_parent;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt_ext = (mmi_scenario_evt_struct*)evt;
    user_data_p = mmi_frm_group_get_user_data(evt_ext->targ_group);
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
        case EVT_ID_GROUP_ACTIVE:
            break;
        case EVT_ID_GROUP_INACTIVE:
            {
                
                MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_PROC_INACTIVE, evt_ext->targ_group);
                if(user_data_p != NULL)
                {
                    user_data_p->enable_refresh_screen = MMI_FALSE;  /* Disable the refresh screen when the menu group becomes inactive */		
                    if(user_data_p->menu_type == CUI_MENU_TYPE_OPTION)
                    {
                        mmi_frm_switch_small_screen_redraw(MMI_TRUE);    
                        if (g_cui_menu_cascading_cache_buf.buf_ptr)
                        {
                            mmi_frm_scrmem_free(g_cui_menu_cascading_cache_buf.buf_ptr);
                            g_cui_menu_cascading_cache_buf.buf_ptr = NULL;
							mmi_frm_scrmem_enable_debug_leak_check();
                        }
                        if(!user_data_p->closure_started_flag)
                        {
                            MMI_FRM_INIT_GROUP_EVENT(&evt_for_parent, sizeof(cui_menu_event_struct), evt_ext->targ_group);
	                        evt_for_parent.evt_id = EVT_ID_CUI_MENU_CLOSE_REQUEST;
	                        evt_for_parent.parent_menu_id = 0;
				            evt_for_parent.highlighted_menu_id = 0;
	                        evt_for_parent.app_data = user_data_p->app_data;
				            evt_for_parent.cui_menu_event_flags = 0;	
                            MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_CLOSE_REQUEST_EVT_START);
                            mmi_frm_group_send_to_caller(evt_ext->targ_group, (mmi_group_event_struct *)&evt_for_parent);
                            MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_CLOSE_REQUEST_EVT_END);
                        }
			            g_mmi_cascading_menu_current_level = 0;			
                    }
                }
            }	
            break;
        case EVT_ID_GROUP_DEINIT:
            {
                MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_PROC_DEINIT, evt_ext->targ_group);
				evt_for_parent.evt_id = EVT_ID_CUI_MENU_LIST_DEINIT;
				evt_for_parent.parent_menu_id = 0;
				evt_for_parent.highlighted_menu_id = 0;
				evt_for_parent.app_data = user_data_p->app_data;
				evt_for_parent.cui_menu_event_flags = 0;	
				
				mmi_frm_group_send_to_caller(evt_ext->targ_group, (mmi_group_event_struct *)&evt_for_parent);
				
                cui_menu_reset(user_data_p);
            }
            break; 
    }
    return MMI_RET_OK;
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_create
 * DESCRIPTION
 *  It creates the cui menu instance, cui menu group is created. 
 * PARAMETERS
 *  parent_gid              : [IN] Group ID of the parent 
 *  src_type                : [IN] Source type of the menu cui : CUI_MENU_SRC_TYPE_RESOURCE or CUI_MENU_SRC_TYPE_APPCREATE
 *  menu_type               : [IN] Menu type of cui menu instance, passed when src type is CUI_MENU_SRC_TYPE_APPCREATE, follow cui_menu_type_enum 
 *  root_menu_id            : [IN] Root id of the menu tree, passed in case the instance's source is CUI_MENU_SRC_TYPE_RESOURCE  
 *  is_item_flags_from_res  : [IN] Flag determines whether the menu item flags are set from res or cui menu instance  
 *  parent_data             : [IN] Parent's user data, only for the caller (application) usage
 * RETURNS
 *  mmi_id
 * RETURN VALUES
 *  group id of the cui menu group created
*****************************************************************************/
mmi_id cui_menu_create(mmi_id parent_gid,
                       cui_menu_src_type_enum src_type,
                       cui_menu_type_enum menu_type,
                       mmi_menu_id root_menu_id,
                       MMI_BOOL is_item_flags_from_res,
                       void* parent_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 free_context_index =0;
    cui_menu_obj_struct *cui_menu_obj_p = NULL;
    MMI_BOOL is_free_context = MMI_FALSE;
    mmi_id menu_gid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_CREATE, parent_gid, src_type, menu_type, root_menu_id, is_item_flags_from_res);
    cui_menu_obj_p = cui_menu_objs;
    while (free_context_index < CUI_MENU_MAX_INSTANCE)
    {
        if (!cui_menu_obj_p->is_inuse)
        {
            is_free_context = MMI_TRUE;
            break;
        }
        cui_menu_obj_p++;
        free_context_index++;
    }
    if (!is_free_context)
    {
        MMI_ASSERT(0);
    }
    cui_menu_obj_p->is_inuse = MMI_TRUE;
    cui_menu_obj_p->app_data = parent_data;
    switch (src_type)
    {
        case CUI_MENU_SRC_TYPE_RESOURCE:
        case CUI_MENU_SRC_TYPE_APPCREATE:
            break;
        default:
            MMI_ASSERT(0);
    }
    cui_menu_obj_p->is_item_flags_from_res = MMI_FALSE;	
    cui_menu_obj_p->mode = src_type;
    cui_menu_obj_p->root_id = root_menu_id;
    if(src_type == CUI_MENU_SRC_TYPE_RESOURCE)
    {
        if(menu_type == CUI_MENU_TYPE_FROM_RESOURCE)
        {
            switch(mmi_res_menu_get_type(root_menu_id))
            {
                case MMI_RG_MENU_TYPE_APP_MAIN:
                    menu_type = CUI_MENU_TYPE_APPMAIN;
                    break;
                case MMI_RG_MENU_TYPE_APP_SUB:
                    menu_type = CUI_MENU_TYPE_APPSUB;
	                break;
                case MMI_RG_MENU_TYPE_OPTION:
                    menu_type = CUI_MENU_TYPE_OPTION;
	                break;
                default:
                    menu_type = CUI_MENU_TYPE_APPSUB;
	                break;
            }
            
        }
	    if(is_item_flags_from_res)
        {
            cui_menu_obj_p->is_item_flags_from_res = MMI_TRUE; 	
        }
    }
    switch (menu_type)
    {
        case CUI_MENU_TYPE_APPMAIN:
        case CUI_MENU_TYPE_APPSUB:
        case CUI_MENU_TYPE_OPTION:
            cui_menu_obj_p->menu_type = menu_type;
            break;
        default:
            cui_menu_obj_p->menu_type = CUI_MENU_TYPE_APPSUB;
            break;
    }
    switch (cui_menu_obj_p->menu_type)
    {
        case CUI_MENU_TYPE_APPMAIN:
        case CUI_MENU_TYPE_APPSUB:
            cui_menu_obj_p->default_lsk_string = get_string(STR_GLOBAL_OK);      
	    cui_menu_obj_p->default_rsk_string = get_string(STR_GLOBAL_BACK);
	     break;		
        case CUI_MENU_TYPE_OPTION:
            cui_menu_obj_p->default_lsk_string = get_string(STR_GLOBAL_SELECT);      
	        cui_menu_obj_p->default_rsk_string = get_string(STR_GLOBAL_BACK);
            break;
        default:
            MMI_ASSERT(0);
    }
    menu_gid = mmi_frm_group_create(parent_gid, GRP_ID_AUTO_GEN, cui_menu_proc, (void*)cui_menu_obj_p);    
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_CREATE_NEW_GID, menu_gid);
#if defined(__MMI_CASCADED_OPTION_MENU__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MTK_INTERNAL__))
    if(cui_menu_obj_p->menu_type == CUI_MENU_TYPE_OPTION)
    {
        cui_menu_enable_cascading_option_menu(menu_gid);
    }
#endif
#ifdef __MMI_SCREEN_ROTATE__
    cui_menu_obj_p->rotate_type = MMI_FRM_SCREEN_ROTATE_0;
#endif
    return menu_gid;
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_run
 * DESCRIPTION
 *  cui menu run 
 * PARAMETERS
 *  owner_gid  : [IN] group ID
 * RETURNS
 *  void
 * RETURN VALUES
 *  none 
*****************************************************************************/
void  cui_menu_run(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_RUN, owner_gid);
#ifdef __MMI_SCREEN_ROTATE__    
	if (mmi_frm_is_screen_width_height_swapped())
    {
        mmi_frm_enable_clear_rotated_screen(MMI_FALSE);
    }	
#endif	
    mmi_frm_group_enter(owner_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);	
    user_data_p->current_level_index = 0;	 
    user_data_p->currlist_parent_id = user_data_p->root_id;	
    user_data_p->tree_path[user_data_p->current_level_index] = user_data_p->currlist_parent_id;    	
    user_data_p->new_scrn_id = 	CUI_MENU_BASE;
    mmi_frm_scrn_first_enter(owner_gid, CUI_MENU_BASE, (FuncPtr)cui_menu_screen_first_entry, user_data_p);
    
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_create_and_run
 * DESCRIPTION
 *  It creates and then run the cui menu instance, cui menu group is created. 
 * PARAMETERS
 *  parent_gid              : [IN] Group ID of the parent 
 *  src_type                : [IN] Source type of the menu cui : CUI_MENU_SRC_TYPE_RESOURCE or CUI_MENU_SRC_TYPE_APPCREATE
 *  menu_type               : [IN] Menu type of cui menu instance, passed when src type is CUI_MENU_SRC_TYPE_APPCREATE, follow cui_menu_type_enum 
 *  root_menu_id            : [IN] Root id of the menu tree, passed in case the instance's source is CUI_MENU_SRC_TYPE_RESOURCE  
 *  is_item_flags_from_res  : [IN] Flag determines whether the menu item flags are set from res or cui menu instance  
 *  parent_data             : [IN] Parent's user data, only for the caller (application) usage
 * RETURNS
 *  mmi_id
 * RETURN VALUES
 *  group id of the cui menu group created
*****************************************************************************/
mmi_id cui_menu_create_and_run(mmi_id parent_gid,
                       cui_menu_src_type_enum src_type,
                       cui_menu_type_enum menu_type,
                       mmi_menu_id root_menu_id,
                       MMI_BOOL is_item_flags_from_res,
                       void* parent_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	mmi_id cui_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cui_id = cui_menu_create(parent_gid,
                       src_type,
                       menu_type,
                       root_menu_id,
                       is_item_flags_from_res,
                       parent_data);

	cui_menu_run(cui_id);

	return cui_id;
}

/*****************************************************************************              
 * FUNCTION
 *   cui_menu_close
 * DESCRIPTION
 *   close menu cui
 * PARAMETERS
 *  owner_gid    : [IN] camera cui group id
 * RETURNS
 *  None
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_close(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_CLOSE, owner_gid);
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    if(user_data_p)
    {
        user_data_p->closure_started_flag = MMI_TRUE;
    }
    mmi_frm_group_close(owner_gid);
}


/****************************************************************************            
 * FUNCTION
 *  cui_menu_set_default_title
 * DESCRIPTION
 *  set default title of menu cui
 * PARAMETERS
 *  owner_gid     : [IN] menu cui owner group id
 *  str         : [IN] title string 
 *  img        : [IN] title image 
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_default_title(mmi_id owner_gid, WCHAR* str, UI_image_type img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    user_data_p->default_title_string = str;
    user_data_p->default_title_image = img;
}

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_default_title_by_id
 * DESCRIPTION
 *  It sets Default title of menu cui using string and image ids, the title will be default unless current title is set for that menu screen.
 *  This api should be called before calling the cui_menu_run api.
 * PARAMETERS
 *  owner_gid     : [IN] Menu cui group ID from cui_menu_create
 *  str_id        : [IN] title string id
 *  img_id        : [IN] title image id
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_default_title_by_id(mmi_id owner_gid, U16 str_id, U16 img_id)
{
	cui_menu_set_default_title(owner_gid, 
				  (WCHAR*)GetString(str_id), 
				  (UI_image_type)GetImage(img_id));
}
/****************************************************************************            
 * FUNCTION
 *  cui_menu_set_default_title_string
 * DESCRIPTION
 *  set default title string of menu cui
 * PARAMETERS
 *  owner_gid     : [IN] menu cui owner group id
 *  str                : [IN] title string 
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_default_title_string(mmi_id owner_gid, WCHAR* str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    user_data_p->default_title_string = str;
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_default_title_string_by_id
 * DESCRIPTION
 *  It sets default title string of menu cui, the title will be default unless current title is set for that menu screen.
 *  This api should be called before calling the cui_menu_run api.
 * PARAMETERS
 *  owner_gid          : [IN] Menu cui group ID from cui_menu_create
 *  str_id                : [IN] title string 
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_default_title_string_by_id(mmi_id owner_gid, U16 str_id)
{
	cui_menu_set_default_title_string(owner_gid, (WCHAR*)GetString(str_id));
}


/****************************************************************************            
 * FUNCTION
 *  cui_menu_set_default_title_image
 * DESCRIPTION
 *  set default title image of menu cui
 * PARAMETERS
 *  owner_gid             : [IN] menu cui owner group id
 *  img                       : [IN] title image 
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_default_title_image(mmi_id owner_gid, UI_image_type img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    user_data_p->default_title_image = img;
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_default_title_image_by_id
 * DESCRIPTION
 *  It sets default title image of menu cui using image id, the title will be default unless current title is set for that menu screen.
 *  This api should be called before calling the cui_menu_run api.
 * PARAMETERS
 *  owner_gid          : [IN] Menu cui group ID from cui_menu_create
 *  img_id             : [IN] title image id
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_default_title_image_by_id(mmi_id owner_gid, U16 img_id)
{
	cui_menu_set_default_title_image(owner_gid, (UI_image_type)GetImage(img_id));
}
/****************************************************************************            
 * FUNCTION
 *  cui_menu_get_default_title_image
 * DESCRIPTION
 *  get default title image of menu cui
 * PARAMETERS
 *  owner_gid             : [IN] menu cui owner group id
 *  img                       : [IN] title image 
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_get_default_title_image(mmi_id owner_gid, UI_image_type  *img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    *img  = user_data_p->default_title_image;
}


/****************************************************************************          
 * FUNCTION
 *  cui_menu_set_default_left_softkey
 * DESCRIPTION
 *  set default left softkey string of menu cui
 * PARAMETERS
 *  owner_gid     : [IN] menu cui owner group id
 *  lsk_str           : [IN] lsk string
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_default_left_softkey(mmi_id owner_gid, WCHAR* lsk_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    user_data_p->default_lsk_string = lsk_str;
}

/****************************************************************************          
 * FUNCTION
 *  cui_menu_set_default_left_softkey_by_id
 * DESCRIPTION
 *  It sets Default left softkey label of menu cui by string id, the left softkey label will be default unless current left softkey label
 *  is set for that menu screen.
 *  This api should be called before calling the cui_menu_run api.
 * PARAMETERS
 *  owner_gid     : [IN] Menu cui group ID from cui_menu_create
 *  lsk_str_id       : [IN] lsk string id
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_default_left_softkey_by_id(mmi_id owner_gid, U16 lsk_str_id)
{
	cui_menu_set_default_left_softkey(owner_gid, (WCHAR*)GetString(lsk_str_id));
}
/****************************************************************************          
 * FUNCTION
 *  cui_menu_set_default_right_softkey
 * DESCRIPTION
 *  set default right softkey strings of menu cui
 * PARAMETERS
 *  owner_gid     : [IN] menu cui owner group id
 *  rsk_str          : [IN] rsk string 
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_default_right_softkey(mmi_id owner_gid, WCHAR* rsk_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    user_data_p->default_rsk_string = rsk_str;
}


/****************************************************************************          
 * FUNCTION
 *  cui_menu_set_default_right_softkey_by_id
 * DESCRIPTION
 *  It sets Default right softkey label of menu cui by id, the right softkey label will be default unless current right softkey label
 *  is set for that menu screen.
 *  This api should be called before calling the cui_menu_run api.
 * PARAMETERS
 *  owner_gid     : [IN] Menu cui group ID from cui_menu_create
 *  rsk_str_id    : [IN] rsk string id
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_default_right_softkey_by_id(mmi_id owner_gid, U16 rsk_str_id)
{
	cui_menu_set_default_right_softkey(owner_gid, (WCHAR*)GetString(rsk_str_id));
}
/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_currlist_title
 * DESCRIPTION
 *  set current menu list title of menu cui
 * PARAMETERS
 *  owner_gid          : [IN] menu cui owner group id
 *  str                     : [IN] title string 
 *  img                    :  [IN] title image 
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_currlist_title(mmi_id owner_gid, WCHAR* str, UI_image_type img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    user_data_p->currlist_title_string = str;
    user_data_p->currlist_title_image = img;
}

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_currlist_title_by_id
 * DESCRIPTION
 *  It sets current title of current menu list using string and image Ids, if current list title is set then it will override the default title setting
 *  for the cui menu. Current title needs to be set for each menu list in the cui menu if default title is not to be used.
 *  This api should be called in show event handling of cui menu for a particular screen.
 * PARAMETERS
 *  owner_gid          : [IN] Menu cui group ID from cui_menu_create
 *  str_id             : [IN] title string id
 *  img_id             : [IN] title image id
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_currlist_title_by_id(mmi_id owner_gid, U16 str_id, U16 img_id)
{
	cui_menu_set_currlist_title(owner_gid, (WCHAR*)GetString(str_id), (UI_image_type)GetImage(img_id));
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_currlist_left_softkey
 * DESCRIPTION
 *  set current menu list left softkey strings of menu cui
 * PARAMETERS
 *  owner_gid             : [IN] menu cui owner group id
 *  lsk_str                  : [IN] lsk string
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_currlist_left_softkey(mmi_id owner_gid, WCHAR* lsk_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    user_data_p->currlist_lsk_string = lsk_str;
}

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_currlist_left_softkey_by_id
 * DESCRIPTION
 *  It sets current left softkey label of current menu list, if current list left softkey label is set then it will override the default left softkey label setting
 *  for the cui menu. Current left softkey label needs to be set for each menu list in the cui menu if default left softkey label is not to be used.
 *  This api should be called in show event handling of cui menu for a particular screen.
 * PARAMETERS
 *  owner_gid    : [IN] Menu cui group ID from cui_menu_create
 *  lsk_str_id   : [IN] lsk string id
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_currlist_left_softkey_by_id(mmi_id owner_gid, U16 lsk_str_id)
{
	cui_menu_set_currlist_left_softkey(owner_gid, (WCHAR*) GetString(lsk_str_id));
}
/*****************************************************************************              
 * FUNCTION
 *   cui_menu_set_currlist_right_softkey
 * DESCRIPTION
 *   set current menu list softkey strings of menu cui
 * PARAMETERS
 *  owner_gid             : [IN] menu cui owner group id
 *  lsk_str                  : [IN] rsk string
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_currlist_right_softkey(mmi_id owner_gid, WCHAR* rsk_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    user_data_p->currlist_rsk_string = rsk_str;
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_currlist_right_softkey_by_id
 * DESCRIPTION
 *  It sets current right softkey label of current menu list, if current list right softkey label is set then it will override the default right softkey label setting
 *  for the cui menu. Current right softkey label needs to be set for each menu list in the cui menu if default right softkey label is not to be used.
 *  This api should be called in show event handling of cui menu for a particular screen.
 * PARAMETERS
 *  owner_gid       : [IN] Menu cui group ID from cui_menu_create
 *  rsk_str_id         : [IN] rsk string
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_currlist_right_softkey_by_id(mmi_id owner_gid, U16 rsk_str_id)
{
	cui_menu_set_currlist_right_softkey(owner_gid, (WCHAR*)GetString(rsk_str_id));
}

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_currlist_flags
 * DESCRIPTION
 *  set current menu list flags of menu cui
 * PARAMETERS
 *  owner_gid     : [IN] Menu GID from cui_menu_create
 *  flags                : [IN] Flags of current menu list screen
 *RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_currlist_flags(mmi_id owner_gid, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    user_data_p->currlist_flags = flags;
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_currlist
 * DESCRIPTION
 *  set the data of curent menu list screen
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  number_of_items               : [IN] Number of items in current menu list screen
 *  list_of_ids                          : [IN] list of menu ids in current menu list screen
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_currlist(mmi_id owner_gid, S32 number_of_items, mmi_menu_id* list_of_ids)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    S32 menu_item_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    MMI_ASSERT(number_of_items <= MAX_SUB_MENUS);
    for (menu_item_index = 0; menu_item_index < number_of_items; menu_item_index++)
    {
        user_data_p->currlist_menu_ids[menu_item_index] = list_of_ids[menu_item_index];
	    memset(hintData[menu_item_index], 0x00, ENCODING_LENGTH);		 
    }
    user_data_p->currlist_no_of_items = number_of_items;
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_insert_currlist
 * DESCRIPTION
 *  Insert  the data in curent menu list screen after a certain menu id
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  number_of_items               : [IN] Number of items in current menu list screen
 *  list_of_ids                          : [IN] list of menu ids to be inserted in current menu list screen
 *  after_menu_id                    : [IN] menu ids after which inserted in current menu list screen
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_insert_currlist(mmi_id owner_gid, S32 number_of_items, mmi_menu_id* list_of_ids, mmi_menu_id after_menu_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    S32 menu_item_index;
    S32 after_menu_index = 0;	
    S32 insertion_index =0;	
    S32 i, j;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    MMI_ASSERT((number_of_items + user_data_p->currlist_no_of_items) <= MAX_SUB_MENUS);
    after_menu_index = cui_menu_get_index_from_menu_id_list(after_menu_id);	
    if(after_menu_index == CUI_MENU_INDEX_NOT_FOUND)
    {
        return;
    }
    /*
    Displace the current menu items by 	number_of_items: Start
    */	
    for(i= 0; i < number_of_items; i++ )
    {
        for (j = user_data_p->currlist_no_of_items ; j >  i + after_menu_index+ 1; j--)
        {
            g_cui_menu_current_screen_info->list_menu_ids[j ] = g_cui_menu_current_screen_info->list_menu_ids[j - 1];
	        mmi_ucs2ncpy((CHAR *)subMenuData[j], (CHAR *)subMenuData[j - 1], MAX_SUBMENU_CHARACTERS);
		    g_cui_menu_current_screen_info->list_menu_icons[j] = g_cui_menu_current_screen_info->list_menu_icons[j - 1];
	        mmi_ucs2ncpy((CHAR *)hintData[j], (CHAR *)hintData[j - 1], MAX_SUBMENU_CHARACTERS);
		    g_cui_menu_current_screen_info->list_menu_check_states[j] = g_cui_menu_current_screen_info->list_menu_check_states[j - 1]; 	  
		    if((user_data_p->currlist_flags >= CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_TEXT_ICON) 
		        && (user_data_p->currlist_flags <= CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_TEXT_ICON_ICON) )
            {
                g_cui_menu_current_screen_info->list_menu_icons2[j] = g_cui_menu_current_screen_info->list_menu_icons2[j - 1];
            }
        }
	    user_data_p->currlist_no_of_items++;   
    }
    /*
    Displace the current menu items by 	number_of_items: End
    */		
    for (insertion_index = after_menu_index + 1, menu_item_index = 0; menu_item_index < number_of_items; menu_item_index++, insertion_index++)
    {
        user_data_p->currlist_menu_ids[insertion_index] = list_of_ids[menu_item_index];
    	memset(subMenuData[insertion_index], 0x00, ENCODING_LENGTH);	
	    memset(hintData[insertion_index], 0x00, ENCODING_LENGTH);	
        g_cui_menu_current_screen_info->list_menu_icons[insertion_index] = 0;		
        g_cui_menu_current_screen_info->list_menu_icons2[insertion_index] = 0;
         g_cui_menu_current_screen_info->list_menu_check_states[insertion_index] = 0;		
    }
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_delete_currlist_menuid
 * DESCRIPTION
 *  Delete a menu id from the currlist
 * PARAMETERS
 *  owner_gid         : [IN] Menu GID from cui_menu_create
 *  delete_menu_id    : [IN] menu ids which needs to be deleted in current menu list screen
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_delete_currlist_menuid(mmi_id owner_gid, mmi_menu_id delete_menu_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    S32 delete_menu_index = 0;	
    S32 j;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    delete_menu_index = cui_menu_get_index_from_menu_id_list(delete_menu_id);
    if(delete_menu_index == CUI_MENU_INDEX_NOT_FOUND)
    {
        return;
    }	
    /*
    Displace the current menu items by 	number_of_items: Start
    */	
    for (j = delete_menu_index + 1; j < user_data_p->currlist_no_of_items; j++)
    {
        g_cui_menu_current_screen_info->list_menu_ids[j -1] = g_cui_menu_current_screen_info->list_menu_ids[j];
	    mmi_ucs2ncpy((CHAR *)subMenuData[j - 1], (CHAR *)subMenuData[j], MAX_SUBMENU_CHARACTERS);
	    g_cui_menu_current_screen_info->list_menu_icons[j-1] = g_cui_menu_current_screen_info->list_menu_icons[j];
	    mmi_ucs2ncpy((CHAR *)hintData[j - 1], (CHAR *)hintData[j], MAX_SUBMENU_CHARACTERS);
	    g_cui_menu_current_screen_info->list_menu_check_states[j -1] = g_cui_menu_current_screen_info->list_menu_check_states[j]; 	  
	    if((user_data_p->currlist_flags >= CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_TEXT_ICON) 
	        && (user_data_p->currlist_flags <= CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_TEXT_ICON_ICON) )
	    {
            g_cui_menu_current_screen_info->list_menu_icons2[j-1] = g_cui_menu_current_screen_info->list_menu_icons2[j];
        }
    }
    g_cui_menu_current_screen_info->list_menu_ids[user_data_p->currlist_no_of_items - 1] = 0;
    mmi_ucs2ncpy((CHAR *)subMenuData[user_data_p->currlist_no_of_items - 1], (CHAR *)L"", 1);
    g_cui_menu_current_screen_info->list_menu_icons[user_data_p->currlist_no_of_items - 1] = 0;	 
    mmi_ucs2ncpy((CHAR *)hintData[user_data_p->currlist_no_of_items - 1], (CHAR *)L"", 1);	
    g_cui_menu_current_screen_info->list_menu_check_states[user_data_p->currlist_no_of_items - 1] = 0; 	 
    if((user_data_p->currlist_flags >= CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_TEXT_ICON) 
   	    && (user_data_p->currlist_flags <= CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_TEXT_ICON_ICON) )
    {
        g_cui_menu_current_screen_info->list_menu_icons2[user_data_p->currlist_no_of_items - 1] = 0;
    }
    user_data_p->currlist_no_of_items--;	 
}



/*****************************************************************************              
 * FUNCTION
 *  cui_menu_delete_currlist
 * DESCRIPTION
 *  Delete  list of menuid  from  current menu list screen
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  number_of_items               : [IN] Number of items to be deleted
 *  list_of_ids                          : [IN] list of menu ids to be deleted in current menu list screen
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_delete_currlist(mmi_id owner_gid, S32 number_of_items, mmi_menu_id* list_of_ids)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    S32 j;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
	
    for (j =0; j < number_of_items; j++)
    {
        cui_menu_delete_currlist_menuid(owner_gid,list_of_ids[j]);
    }
}

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_item_string
 * DESCRIPTION
 *  set the data of curent menu list screen
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  menu_id                            : [IN] Menu ID of the menu-item
 *  str                                    : [IN] String of the menu-item
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_item_string(mmi_id owner_gid, mmi_menu_id menu_id, WCHAR* str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 menuitem_idx; 
    cui_menu_obj_struct* user_data_p;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);	
    menuitem_idx = cui_menu_get_index_from_menu_id_list(menu_id);
    if(menuitem_idx == CUI_MENU_INDEX_NOT_FOUND)
    {
        return;
    }
    if(str)
    {
        mmi_ucs2ncpy((CHAR *)subMenuData[menuitem_idx], (CHAR *)str, MAX_SUBMENU_CHARACTERS);
    }
    else
    {
        mmi_ucs2ncpy((CHAR *)subMenuData[menuitem_idx], (CHAR *)L"", 1);
    }
    if(user_data_p->enable_refresh_screen)
    {
        cui_menu_refresh_list_with_new_menuitem_info(user_data_p);
    }

}

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_item_string_by_id
 * DESCRIPTION
 *  It sets the sub-menu string corresponding to the menuid of the menu item of curent menu list screen.
 *  This api should be called in show event handling of cui menu for a particular screen
 *  or for refreshing the current list menu with new menuitem info without the change in the no. of menu items in the list 
 * PARAMETERS
 *  owner_gid             : [IN] Menu cui group ID from cui_menu_create
 *  menu_id               : [IN] Menu ID of the menu-item
 *  str_id                   : [IN] String id of the menu-item
 *RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_item_string_by_id(mmi_id owner_gid, mmi_menu_id menu_id, U16 str_id)
{
	cui_menu_set_item_string(owner_gid, menu_id, (WCHAR*)GetString(str_id));
}

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_item_hint
 * DESCRIPTION
 *  set the data of curent menu list screen
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  menu_id                            : [IN] Menu ID of the menu-item
 *  str                                    : [IN] Hint String of the menu-item
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_item_hint(mmi_id owner_gid, mmi_menu_id menu_id, WCHAR* str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 menuitem_idx; 
    cui_menu_obj_struct* user_data_p;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);	
    menuitem_idx = cui_menu_get_index_from_menu_id_list(menu_id);
    if(menuitem_idx == CUI_MENU_INDEX_NOT_FOUND)
    {
        return;
    }
    if(str)
    {
        mmi_ucs2ncpy((CHAR *)hintData[menuitem_idx], (CHAR *)str, MAX_SUBMENU_CHARACTERS);
    }
    else
    {
        mmi_ucs2ncpy((CHAR *)hintData[menuitem_idx], (CHAR *)L"", 1);
    }
    if (user_data_p->enable_refresh_screen)
    {
        if (user_data_p->highlight_evt_handler == MMI_FALSE)
        {
            fixed_list_goto_item_no_redraw(MMI_fixed_list_menu.highlighted_item);
        }
        cui_menu_refresh_list_with_new_menuitem_info(user_data_p);
    }
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_item_image
 * DESCRIPTION
 *  set the data of curent menu list screen
 * PARAMETERS
 *  owner_gid                          :  [IN] Menu GID from cui_menu_create
 *  menu_id                             : [IN] Menu ID of the menu-item
 *  img                                    : [IN] Image  for the menu-item
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_item_image(mmi_id owner_gid, mmi_menu_id menu_id, U16 img_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 menuitem_idx; 
    cui_menu_obj_struct* user_data_p;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);	
    menuitem_idx = cui_menu_get_index_from_menu_id_list(menu_id);
    if(menuitem_idx == CUI_MENU_INDEX_NOT_FOUND)
    {
        return;
    }
    g_cui_menu_current_screen_info->list_menu_icons[menuitem_idx] = img_icon;
    if(user_data_p->enable_refresh_screen)
    {
        if((user_data_p->currlist_flags >= CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_TEXT_ICON) 
    			&& (user_data_p->currlist_flags <= CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_TEXT_ICON_ICON) )
        {
            Category73ChangeItemIcon(menuitem_idx, 0, get_image(img_icon));
        }

        cui_menu_refresh_list_with_new_menuitem_info(user_data_p);
    }
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_item_second_image
 * DESCRIPTION
 *  set the data of curent menu list screen
 * PARAMETERS
 *  owner_gid                          :  [IN] Menu GID from cui_menu_create
 *  menu_id                             : [IN] Menu ID of the menu-item
 *  img                                    : [IN] Image  for the menu-item
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_item_second_image(mmi_id owner_gid, mmi_menu_id menu_id, U16 img_icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 menuitem_idx; 
    cui_menu_obj_struct* user_data_p;
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);	
    menuitem_idx = cui_menu_get_index_from_menu_id_list(menu_id);
    if(menuitem_idx == CUI_MENU_INDEX_NOT_FOUND)
    {
        return;
    }
    g_cui_menu_current_screen_info->list_menu_icons2[menuitem_idx] = img_icon;
    if(user_data_p->enable_refresh_screen)
    {
        if((user_data_p->currlist_flags >= CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_ICON_TEXT_ICON) 
    			&& (user_data_p->currlist_flags <= CUI_MENU_LIST_WITH_SINGLE_TEXT_DOUBLE_ICON_WITH_HINTS_TEXT_ICON_ICON) )
        {
            Category73ChangeItemIcon(menuitem_idx, 1, get_image(img_icon));
        }
        cui_menu_refresh_list_with_new_menuitem_info(user_data_p);
    }
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_item_flags
 * DESCRIPTION
 *  set the hidden /disabled flag for menu id 
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  menu_id                           : [IN] Menu ID of the menu-item
 *  is_flag_set                       : [IN] Is flag to be set 
 *  actual_flag_value                 : [IN] Actual value of the flag   
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
static void cui_menu_set_item_flags(mmi_id owner_gid, mmi_menu_id menu_id, MMI_BOOL is_flag_set, U8 actual_flag_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    S32 index = 0;
    MMI_BOOL index_found_flag = MMI_FALSE;
    MMI_BOOL new_index_flag = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p->is_item_flags_from_res == MMI_FALSE);
    while (index < CUI_MENU_MAX_EDIT_RES)
    {
        if (user_data_p->cui_menu_item_flags[index].menu_id == menu_id) 
        {
            index_found_flag = MMI_TRUE;	
	        break;
        }
	    if (user_data_p->cui_menu_item_flags[index].menu_id == 0)
        {
            new_index_flag = MMI_TRUE;
	        break;
        }
	    index++;
    }
    if ((index_found_flag == MMI_FALSE) && (new_index_flag == MMI_FALSE))
    {
        MMI_ASSERT(0);
    }
    if (new_index_flag == MMI_TRUE)	
    {
        if(is_flag_set)
        {
            user_data_p->cui_menu_item_flags[index].menu_id = menu_id;
            user_data_p->cui_menu_item_flags[index].flags |= actual_flag_value;
        }
        return;  
    }
    else if (index_found_flag == MMI_TRUE)
    {
        if (is_flag_set == MMI_FALSE)
        {
            user_data_p->cui_menu_item_flags[index].flags &= ~actual_flag_value;
        }
	    else
        {
            user_data_p->cui_menu_item_flags[index].flags |= actual_flag_value;
        }
	    if (user_data_p->cui_menu_item_flags[index].flags == 0)
        {
            user_data_p->cui_menu_item_flags[index].menu_id =0;
	        index++;
	        while (index < CUI_MENU_MAX_EDIT_RES)
            {
                if (user_data_p->cui_menu_item_flags[index].menu_id == 0)
                {
                    break;
                }
	            user_data_p->cui_menu_item_flags[index - 1].menu_id = user_data_p->cui_menu_item_flags[index].menu_id;
		        user_data_p->cui_menu_item_flags[index- 1].flags = user_data_p->cui_menu_item_flags[index].flags;
                user_data_p->cui_menu_item_flags[index].menu_id = 0;
                user_data_p->cui_menu_item_flags[index].flags = 0;
		        index++;
            }
        }
    }
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_item_hidden
 * DESCRIPTION
 *  It hides or unhides a menu id. 
 *  This api can be called anytime after the cui menu group has been created.
 * PARAMETERS
 *  owner_gid                          : [IN] Menu GID from cui_menu_create
 *  menu_id                            : [IN] Menu ID of the menu-item
 *  is_hidden_flag                     : [IN] Is the menu id need to be hidden
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_item_hidden(mmi_id owner_gid, mmi_menu_id menu_id, MMI_BOOL is_hidden_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    mmi_id current_gid;
    S32 menuitem_idx; 
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    if(!user_data_p->is_item_flags_from_res)	
    {
        cui_menu_set_item_flags(owner_gid, menu_id, is_hidden_flag, CUI_MENU_ITEM_HIDDEN);
    }
    else
    {
        if(is_hidden_flag)
        {
            mmi_frm_hide_menu_item(menu_id);
        }
	    else
        {
            mmi_frm_unhide_menu_item(menu_id);
        }
    }
    current_gid = mmi_frm_group_get_active_id();
    if ( current_gid != owner_gid)
    {
        return;    
    }
    if (!user_data_p->enable_refresh_screen )	
    {
        return;
    }
    menuitem_idx = cui_menu_get_index_from_menu_id_list(menu_id);	
    if(menuitem_idx == CUI_MENU_INDEX_NOT_FOUND)
    {
        return;
    }
    cui_menu_refresh_currlist(owner_gid);	
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_group_hidden
 * DESCRIPTION
 *  It hides or unhides a menu id group. 
 *  This api can be called anytime after the cui menu group has been created.
 * PARAMETERS
 *  owner_gid                          : [IN] Menu GID from cui_menu_create
 *  menu_id_group                   : [IN] Menu ID group
 *  is_hidden_flag                     : [IN] Is the menu group need to be hidden
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_group_hidden(mmi_id owner_gid, U16 menu_id_group, MMI_BOOL is_hidden_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    mmi_id current_gid;
    S32 menuitem_idx; 
    U16* group_menu_ids = NULL;	
    U16 group_menu_ids_count = 0;
    MMI_BOOL is_curr_list_menu_id = MMI_FALSE;	
    S32 i;	
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    group_menu_ids_count =  mmi_res_menu_group_get_menuitems(menu_id_group, &group_menu_ids);
    if(!user_data_p->is_item_flags_from_res)	
    {
        for(i = 0; i < group_menu_ids_count; i++)
        {
            cui_menu_set_item_flags(owner_gid, group_menu_ids[i], is_hidden_flag, CUI_MENU_ITEM_HIDDEN);
        }
    }
    else
    {
        mmi_res_menu_group_set_hide(menu_id_group, is_hidden_flag);
    }
    current_gid = mmi_frm_group_get_active_id();
    if ( current_gid != owner_gid)
    {
        return;    
    }
    if (!user_data_p->enable_refresh_screen )	
    {
        return;
    }
    for(i = 0; i < group_menu_ids_count; i++)
    {
        menuitem_idx = cui_menu_get_index_from_menu_id_list(group_menu_ids[i]);	
        if(menuitem_idx != CUI_MENU_INDEX_NOT_FOUND)
        {
            is_curr_list_menu_id = MMI_TRUE;
	        break;		
        }
    }
    if(is_curr_list_menu_id)	
    {
        cui_menu_refresh_currlist(owner_gid);	
    }
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_item_disabled
 * DESCRIPTION
 *  It disables or enables a menu id. 
 *  This api can be called anytime after the cui menu group has been created.
 * PARAMETERS
 *  owner_gid                          : [IN] Menu GID from cui_menu_create
 *  menu_id                            : [IN] Menu ID of the menu-item
 *  is_disabled_flag                   : [IN] Is the menu id need to be disabled
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_item_disabled(mmi_id owner_gid, mmi_menu_id menu_id, MMI_BOOL is_disabled_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    mmi_id current_gid;
    S32 menuitem_idx; 
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    if(!user_data_p->is_item_flags_from_res)	
    {
        cui_menu_set_item_flags(owner_gid, menu_id, is_disabled_flag, CUI_MENU_ITEM_DISABLED);
    }
    else
    {
        SetMenuItemDimmed(menu_id, is_disabled_flag);  
    }
    current_gid = mmi_frm_group_get_active_id();
    if ( current_gid != owner_gid)
    {
        return;    
    }
    if (!user_data_p->enable_refresh_screen )	
    {
        return;
    }
    menuitem_idx = cui_menu_get_index_from_menu_id_list(menu_id);	
    if(menuitem_idx == CUI_MENU_INDEX_NOT_FOUND)
    {
        return;
    }
    cui_menu_refresh_currlist(owner_gid);	
	
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_group_disabled
 * DESCRIPTION
 *  It disables or enables a menu id group. 
 *  This api can be called anytime after the cui menu group has been created.
 * PARAMETERS
 *  owner_gid                          : [IN] Menu GID from cui_menu_create
 *  menu_id_group                   : [IN] Menu ID group 
 *  is_disabled_flag                  : [IN] Is the menu group need to be disabled
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_group_disabled(mmi_id owner_gid, U16 menu_id_group, MMI_BOOL is_disabled_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    mmi_id current_gid;
    S32 menuitem_idx; 
    U16* group_menu_ids = NULL;	
    U16 group_menu_ids_count = 0;	
    MMI_BOOL is_curr_list_menu_id = MMI_FALSE;	
    S32 i;		
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    group_menu_ids_count =  mmi_res_menu_group_get_menuitems(menu_id_group, &group_menu_ids);
    if(!user_data_p->is_item_flags_from_res)	
    {
        for(i = 0; i < group_menu_ids_count; i++)
        {
            cui_menu_set_item_flags(owner_gid, group_menu_ids[i], is_disabled_flag, CUI_MENU_ITEM_DISABLED);
        }
    }
    else
    {
        mmi_res_menu_group_set_disable(menu_id_group, is_disabled_flag);
    }
    current_gid = mmi_frm_group_get_active_id();
    if (current_gid != owner_gid)
    {
        return;    
    }
    if (!user_data_p->enable_refresh_screen )	
    {
        return;
    }
    for(i = 0; i < group_menu_ids_count; i++)
    {
        menuitem_idx = cui_menu_get_index_from_menu_id_list(group_menu_ids[i]);	
        if(menuitem_idx != CUI_MENU_INDEX_NOT_FOUND)
        {
            is_curr_list_menu_id = MMI_TRUE;
	        break;		
        }
    }
    if(is_curr_list_menu_id)	
    {
        cui_menu_refresh_currlist(owner_gid);	
    }
	
}

/*****************************************************************************              
 * FUNCTION
 *   cui_menu_set_checkbox_state
 * DESCRIPTION
 *   set the check box 
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  list_of_states                     : [IN] pointer to the list of states
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_checkbox_state(mmi_id owner_gid, U8* list_of_states)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id current_gid;
    S32 i;
    cui_menu_obj_struct* user_data_p;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_gid = mmi_frm_group_get_active_id();
    MMI_ASSERT(current_gid == owner_gid);
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    for (i =0 ; i < user_data_p->currlist_no_of_items; i++)
    {
        g_cui_menu_current_screen_info->list_menu_check_states[i] = list_of_states[i];
    }
}


/*****************************************************************************              
 * FUNCTION
 *   cui_menu_get_checkbox_state
 * DESCRIPTION
 *   get the check box 
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  list_of_states                     : [IN] pointer to the list of states
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_get_checkbox_state(mmi_id owner_gid, U8* list_of_states)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id current_gid;
    S32 i;
    cui_menu_obj_struct* user_data_p;		

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_gid = mmi_frm_group_get_active_id();
    MMI_ASSERT(current_gid == owner_gid);
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    for (i =0 ; i < user_data_p->currlist_no_of_items; i++)
    {
        list_of_states[i] = g_cui_menu_current_screen_info->list_menu_check_states[i];
    }
}


/*****************************************************************************              
 * FUNCTION
 *   cui_menu_set_currlist_highlighted_id
 * DESCRIPTION
 *   set the current list highlighted menu id
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  menu_id                           : [IN] pointer to the list of states
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_currlist_highlighted_id(mmi_id owner_gid, mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    user_data_p->currlist_highlighted_id = menu_id;
}


/*****************************************************************************              
 * FUNCTION
 *   cui_menu_set_radio_list_item
 * DESCRIPTION
 *   set the radio list  selected menu id
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  menu_id                           : [IN] pointer to the list of states
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_radio_list_item(mmi_id owner_gid, mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   /* Currently just a wrapper, but may change in future with highlighted item*/	
    cui_menu_set_currlist_highlighted_id(owner_gid, menu_id);	
}


/*****************************************************************************              
 * FUNCTION
 *   cui_menu_enable_cascading_option_menu
 * DESCRIPTION
 *   Enable the cascading type option menu called before run
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_enable_cascading_option_menu(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_ENABLE_CASCADING_OPTION_MENU, owner_gid);
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    MMI_ASSERT(user_data_p->menu_type == CUI_MENU_TYPE_OPTION);
#if defined(__MMI_CASCADED_OPTION_MENU__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MTK_INTERNAL__))
    user_data_p->enable_cascading_option_menu = MMI_TRUE;
#else
    user_data_p->enable_cascading_option_menu = MMI_FALSE;
#endif
}

/*****************************************************************************              
 * FUNCTION
 *   cui_menu_disable_cascading_option_menu
 * DESCRIPTION
 *   Enable the cascading type option menu called before run
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_disable_cascading_option_menu(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_DISABLE_CASCADING_OPTION_MENU, owner_gid);
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    MMI_ASSERT(user_data_p->menu_type == CUI_MENU_TYPE_OPTION);
    user_data_p->enable_cascading_option_menu = MMI_FALSE;
}


/*****************************************************************************              
 * FUNCTION
 *   cui_menu_set_non_leaf_item_in_cascaded_menu
 * DESCRIPTION
 *   set the item as non leaf in the menu list , needs to be called in the show event
 *   Menu items in Radio and check box lists are always leaf nodes so no need to call this API
 * PARAMETERS
 *  owner_gid                          :  [IN] Menu GID from cui_menu_create
 *  menu_id                            :  [IN] Menu ID of the menu-item
 *  img                                :  [IN] Image  for the menu-item
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_non_leaf_item(mmi_id owner_gid, mmi_menu_id menu_id, MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 menuitem_idx; 
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);

    menuitem_idx = cui_menu_get_index_from_menu_id_list(menu_id);
    if(menuitem_idx == CUI_MENU_INDEX_NOT_FOUND) 	
    {
        return;    
    }
    if( (user_data_p->currlist_flags >= CUI_MENU_NORMAL_CHECK_BOX_LIST) 
		&& (user_data_p->currlist_flags <= CUI_MENU_RADIO_LIST_WITH_SCROLLING_TITLE))	
    {
        MMI_ASSERT(0); /*Menu items in Radio and check box lists are always leaf nodes so no need to call this API*/
    }
#if defined(__MMI_CASCADED_OPTION_MENU__) || (defined(__MMI_FTE_SUPPORT__) && defined(__MTK_INTERNAL__))
    if(user_data_p->enable_cascading_option_menu)
    {
        if (flag)
        {
            g_cui_menu_current_screen_info->list_menu_check_states[menuitem_idx] |= (UI_CASCADING_MENU_WITH_SUBMENU);
        }
        else
        {
            g_cui_menu_current_screen_info->list_menu_check_states[menuitem_idx] &= (~UI_CASCADING_MENU_WITH_SUBMENU);
	
        }
    }
    else
#endif
    {
        if (flag)
        {
            g_cui_menu_current_screen_info->list_menu_check_states[menuitem_idx] |= (CUI_MENU_ITEM_WITH_SUB_MENU);
        }
        else
        {
            g_cui_menu_current_screen_info->list_menu_check_states[menuitem_idx] &= (~CUI_MENU_ITEM_WITH_SUB_MENU);
	
        }
    }
	if((user_data_p->mode == CUI_MENU_SRC_TYPE_RESOURCE) && (user_data_p->is_item_flags_from_res == MMI_TRUE))
	{
	    user_data_p->override_non_leaf_by_app = MMI_TRUE;
	}
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_new_list_parent_id
 * DESCRIPTION
 *  Set the new parent id of curent CUI menu
 *  This api has to be called by APP only when it receives the select event from CUI menu
 *  This api helps the APP to connect to some other tree with in the same cui menu. 
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  parent_menu_id                : [IN] New parent menu id for the next list screen
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_new_list_parent_id(mmi_id owner_gid, mmi_menu_id parent_menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    user_data_p->currlist_highlighted_id = parent_menu_id;
}

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_get_currlist_item_count
 * DESCRIPTION
 *  It gets the current menu lists total items.
 *  This api can  be called by APP when it receives the entry, highlight or select event from CUI menu
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
S32 cui_menu_get_currlist_item_count(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    S32 i, total_menu_ids;
    mmi_menu_id child_menu_id;
    S32 actual_menu_ids = 0;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    total_menu_ids = user_data_p->currlist_no_of_items;
    for (i = 0; i < total_menu_ids; i++)
    {
        child_menu_id = user_data_p->currlist_menu_ids[i];
        if ((!cui_menu_is_menu_item_hidden(child_menu_id)) && (child_menu_id != MMI_MENU_ID_SEPARATOR))    
        {
            actual_menu_ids++;
         }    
    }
    return actual_menu_ids;
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_get_currlist_menu_id_from_index
 * DESCRIPTION
 *  It gets the menu id from current menu lists for the index passed to it.
 *  This api can  be called by APP when it receives the entry, highlight or select event from CUI menu
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  index                             : [IN] Index in the list  
 * RETURNS 
 *  mmi_menu_id 
 * RETURN VALUES
 *  None
*****************************************************************************/
mmi_menu_id cui_menu_get_currlist_menu_id_from_index(mmi_id owner_gid, S32 index )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
    S32 i = 0; 
    S32 total_menu_ids;
    mmi_menu_id child_menu_id;
    S32 actual_index; 	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    total_menu_ids = user_data_p->currlist_no_of_items;
    actual_index = index;	
    if(total_menu_ids)
    {
        for(i = 0; i <= index; i++)
        {
            child_menu_id = user_data_p->currlist_menu_ids[i];
            if ((cui_menu_is_menu_item_hidden(child_menu_id)) || (child_menu_id == MMI_MENU_ID_SEPARATOR))    
            {
                actual_index++;
            }    
        }
    }
	
    return cui_menu_get_menu_id_from_menu_id_list(actual_index);
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_get_index_in_currlist_from_menu_id
 * DESCRIPTION
 *  It gets the index in current menu lists for the menu_id passed to it.
 *  This api can  be called by APP when it receives the entry, highlight or select event from CUI menu
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  menu_id                           : [IN] Menu id of the item in the list
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
S32 cui_menu_get_index_in_currlist_from_menu_id(mmi_id owner_gid, mmi_menu_id menu_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    return cui_menu_get_index_from_menu_id_list(menu_id);
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_change_left_softkey_string
 * DESCRIPTION
 *  This api has to be called by APP only when it receives the highlight event from CUI menu
 *  This api helps the APP to change the left softkey label of the list menu of the cui menu . 
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  lsk_str                               : [IN] New lsk string label
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_change_left_softkey_string(mmi_id owner_gid, WCHAR* lsk_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
	if(user_data_p->is_in_show_func == MMI_FALSE)
	{
	    ChangeLeftSoftkeyByString(lsk_str, NULL);
	}
	else
	{
		set_left_softkey_label(lsk_str);
		set_left_softkey_icon(NULL);
	}
		
}

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_change_left_softkey_string_by_id
 * DESCRIPTION
 *  This api has to be called by APP only when it receives the highlight event from CUI menu
 *  This api helps the APP to change the left softkey label of the list menu of the cui menu . 
 * PARAMETERS
 *  owner_gid                            : [IN] Menu GID from cui_menu_create
 *  lsk_str_id                              : [IN] new lsk string label
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_change_left_softkey_string_by_id(mmi_id owner_gid, U16 lsk_str_id)
{
	cui_menu_change_left_softkey_string(owner_gid, (WCHAR*)GetString(lsk_str_id));
}

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_change_center_softkey_content
 * DESCRIPTION
 *  This api has to be called by APP only when it receives the highlight event from CUI menu
 *  This api helps the APP to change the center softkey label of the list menu of the cui menu . 
 * PARAMETERS
 *  owner_gid                         : [IN] Menu GID from cui_menu_create
 *  lsk_str                               : [IN] New lsk string label
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_change_center_softkey_content(mmi_id owner_gid, WCHAR* lsk_str, UI_image_type img )
{
#ifndef __MMI_WGUI_DISABLE_CSK__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    gui_lock_double_buffer();	
    set_softkey_label(lsk_str, MMI_CENTER_SOFTKEY);
    set_softkey_icon(img, MMI_CENTER_SOFTKEY);
	if(user_data_p->is_in_show_func == MMI_FALSE)
	{
	    redraw_center_softkey();	
	}
    gui_unlock_double_buffer();
#endif
}
/*****************************************************************************              
 * FUNCTION
 *  cui_menu_get_src_type
 * DESCRIPTION
 *  This api has to be called by APP to know r the cui menu items flags from resources 
 *   or not 
 * PARAMETERS
 *  owner_gid   : [IN] Menu GID from cui_menu_create
 * RETURNS 
 *  enum value of  cui_menu_src_type_enum which tells whether the cui menu tree is from resource or APP created
 * RETURN VALUES
 *  CUI_MENU_SRC_TYPE_RESOURCE or CUI_MENU_SRC_TYPE_APPCREATE
*****************************************************************************/
cui_menu_src_type_enum cui_menu_get_src_type(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
   return user_data_p->mode;
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_is_menu_event
 * DESCRIPTION
 *  This api has to be called by APP to know whether the current event received is from cui menu
 *   It can be called any time when it receives any event
 * PARAMETERS
 *  evt_id                         : [IN] Event id 
 * RETURNS 
 *  Bool value whether the event is cui menu defined or not 
 * RETURN VALUES
 *  ReturnValues: 0 or 1
*****************************************************************************/
MMI_BOOL cui_menu_is_menu_event (U16 evt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(evt_id >= EVT_ID_CUI_MENU_LIST_ENTRY && evt_id < EVT_ID_CUI_MENU_EVENT_ALL)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}



/*****************************************************************************              
 * FUNCTION
 *   cui_menu_enable_tap_to_highlight
 * DESCRIPTION
 *   It enables tap to highlight for FTE, needs to be called in the show event.
 * PARAMETERS
 *  owner_gid                          :  [IN] Menu GID from cui_menu_create
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_enable_tap_to_highlight(mmi_id owner_gid)
{
#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                          */
    /*----------------------------------------------------------------*/
    mmi_id current_gid;
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_ENABLE_TAP_TO_HIGHLIGHT, owner_gid);
    current_gid = mmi_frm_group_get_active_id();
    MMI_ASSERT(current_gid == owner_gid);
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    user_data_p->enable_tap_highlight =  MMI_TRUE;
#else
    UI_UNUSED_PARAMETER(owner_gid);
#endif
}
 


/***************************************************************************              
 * FUNCTION
 *   cui_menu_enable_fte_sublevel_option_menu
 * DESCRIPTION
 *   Enable the FTE sub-level option menu called before run
 * PARAMETERS
 *  owner_gid                   : [IN] Menu GID from cui_menu_create
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
****************************************************************************/
void cui_menu_enable_fte_sublevel_option_menu(mmi_id owner_gid)
{

#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    MMI_ASSERT(user_data_p->menu_type == CUI_MENU_TYPE_OPTION);
    user_data_p->enable_fte_sublevel_option_menu = MMI_TRUE;
#else
    UI_UNUSED_PARAMETER(owner_gid);
#endif
}


/*****************************************************************************              
 * FUNCTION
 *   cui_menu_pause
 * DESCRIPTION
 *   It pauses the cui menu to the current list menu screen (to the current level of the tree ),
 *   needs to be called in the select, csk select  or tap event .
 * PARAMETERS
 *  owner_gid                          :  [IN] Menu GID from cui_menu_create
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_pause(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                          */
    /*----------------------------------------------------------------*/
    mmi_id current_gid;
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_PAUSE, owner_gid);
    current_gid = mmi_frm_group_get_active_id();
    if(current_gid != owner_gid)
    {
        return;
    }
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    user_data_p->is_pause =  MMI_TRUE;
}


/*****************************************************************************              
 * FUNCTION
 *   cui_menu_play
 * DESCRIPTION
 *   It plays the cui menu to the next list menu screen (to the next level of the tree ),
 *   needs to be called when the APP is ready after it has earlier paused the cui menu during the select, csk select  or tap event .
 * PARAMETERS
 *  owner_gid                          :  [IN] Menu GID from cui_menu_create
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_play(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                          */
    /*----------------------------------------------------------------*/
    mmi_id current_gid;
    cui_menu_obj_struct* user_data_p;
    S32 menu_item_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_CUI_PLAY, owner_gid);
    current_gid = mmi_frm_group_get_active_id();
    if (current_gid != owner_gid)
    {
        return;
    }
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    if (user_data_p->is_pause ==  MMI_FALSE)
    {
        return;
    }
    user_data_p->is_pause = MMI_FALSE;	
    menu_item_index = cui_menu_get_index_from_menu_id_list(user_data_p->currlist_highlighted_id);
    if (menu_item_index == CUI_MENU_INDEX_NOT_FOUND)
    {
        return;
    }
    cui_menu_post_action_handling(user_data_p, menu_item_index);
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_override_center_softkey
 * DESCRIPTION
 *  It  overides the default csk setting and sets current APP defined label, icon and CUI will send csk event to APP
 *  This api should be called in show event handling of cui menu for a particular screen.
 * PARAMETERS
 *  owner_gid          : [IN] Menu cui group ID from cui_menu_create
 *  csk_str                : [IN] title string 
 *  csk_img                : [IN] title image 
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_override_center_softkey(mmi_id owner_gid, WCHAR* csk_str, UI_image_type csk_img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id current_gid;
    cui_menu_obj_struct* user_data_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_OVERRIDE_CSK, owner_gid);
    current_gid = mmi_frm_group_get_active_id();
    if (current_gid != owner_gid)
    {
        return;
    }
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    MMI_ASSERT(user_data_p);
    user_data_p->currlist_csk_string = csk_str;
    user_data_p->currlist_csk_image = csk_img;
    user_data_p->app_csk = MMI_TRUE;	
}
void cui_menu_enable_center_softkey(mmi_id owner_gid, U16 str_id, U16 img_id)
{
    cui_menu_override_center_softkey(owner_gid, get_string(str_id), get_image(img_id));
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_rotate_screen
 * DESCRIPTION
 *  It  set 
 *  This api should be called before calling cui_menu_run to rotate the screen
 * PARAMETERS
 *  owner_gid          : [IN] Menu cui group ID from cui_menu_create
 *  rotate_type                : [IN] Rotate type
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/

void cui_menu_set_rotate_screen(mmi_id owner_gid, mmi_frm_screen_rotate_enum rotation)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_ROTATE_SCREEN, owner_gid, rotation);
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    if (!user_data_p)
    {
        return;
    }
#ifdef __MMI_SCREEN_ROTATE__   
    user_data_p->rotate_type = rotation;
    mmi_frm_screen_rotate(user_data_p->rotate_type);
#endif 	
}

/*****************************************************************************              
 * FUNCTION
 *  cui_menu_set_access_by_shortcut
 * DESCRIPTION
 *  This api should be called in the entry event to enable or disable access by shortcut
 * PARAMETERS
 *  owner_gid          : [IN] Menu cui group ID from cui_menu_create
 *  rotate_type                : [IN] Rotate type
 * RETURNS 
 *  void 
 * RETURN VALUES
 *  None
*****************************************************************************/
void cui_menu_set_access_by_shortcut(mmi_id owner_gid,MMI_BOOL access_by_sc_flag)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G8_MENU_CUI, MMI_GUI_MENU_SET_ACCESS_BY_SHORTCUT, owner_gid, access_by_sc_flag);
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
    if (!user_data_p)
    {
        return;
    }
    if(access_by_sc_flag) 
    {
        user_data_p->access_by_shortcut = CUI_MENU_ACCESS_BY_SHORTCUT_ENABLE; 
    }
    else
    {
        user_data_p->access_by_shortcut = CUI_MENU_ACCESS_BY_SHORTCUT_DISABLE; 
    }
}


/*****************************************************************************              
 * FUNCTION
 *  cui_menu_get_app_parent_data
 * DESCRIPTION
 *  This api returns the app parent data associated by APP while creating menu cui
 * PARAMETERS
 *  owner_gid          : [IN] Menu cui group ID from cui_menu_create
 * RETURNS 
 *  void* 
 * RETURN VALUES
 *  pointer to APP parent dat
*****************************************************************************/
void * cui_menu_get_app_parent_data(mmi_id owner_gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_obj_struct* user_data_p;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data_p = (cui_menu_obj_struct*)mmi_frm_group_get_user_data(owner_gid);
   if (!user_data_p)
   {
       return NULL;
   }
   return user_data_p->app_data;

}

