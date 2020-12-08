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
 *  vadp_p2v_mm.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Venus main menu application. This file is in mmi_framework module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "Mainmenu/vapp_mm_scr.h"
#ifdef __cplusplus
extern "C"
{
#endif
#include "MainMenuDef.h"
#include "nvram_common_defs.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "wgui_categories_enum.h"
#include "gui_typedef.h"
#include "gui_fixed_menus.h"
#include "CustMenuRes.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "wgui_categories_util.h"
#include "mmi_frm_nvram_gprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "wgui_categories_list.h"
#include "custom_mmi_default_value.h"



#ifdef __cplusplus
}   /* extern "C" */
#endif
#include "vfx_datatype.h"
#include "vcp_app_scr.h"
#include "vfx_app_cat_scr.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_string.h"
#ifdef __MMI_VUI_MAINMENU__
/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
typedef struct
{
    /* History ID */
    U16 history_ID;
    /* The index of highlight item */
    S16 highlighted_item;
    /* Highlighted column */
    S16 highlighted_column;
    /* Highlighted row */
    S16 highlighted_row;
    /* The number of columns can be displayed in the current LCD */
    S16 displayed_columns;
    /* The number of rows can be displayed in the current LCD */
    S16 displayed_rows;
    /* The index of first displayed column */
    S16 first_displayed_column;
    /* The index of first displayed row */
    S16 first_displayed_row;
    /* MMI_fixed_matrix_menu`s flag */
    U32 flags;
} mm_style1_history_struct;
#define MATRIX_MAIN_MENU_ROWS           4
#define MATRIX_MAIN_MENU_COLUMNS        3
#define MATRIX_MAIN_MENU_ITEMS          12

/***************************************************************************** 
 * Local Variable
 *****************************************************************************/
static VappMmScr *g_vapp_mm_component = NULL;

#ifdef __cplusplus
extern "C"
{
#endif
/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern S32 main_menu_index;

/***************************************************************************** 
 * Local Function
 *****************************************************************************/
/***************************************************************************** 
 * Global Function
 *****************************************************************************/

extern U8 mmi_phnset_get_vui_mm_effect_status(void);
#ifdef __cplusplus
}   /* extern "C" */
#endif

/*
 * Porting Venus UI to Plutommi
 */ 
/*
 * Porting Plutommi to Venus UI
 */ 
VfxU32 vadp_p2v_main_menu_get_highlight_index(void)
{
    return g_vapp_mm_component->m_matrix->getCurrentHighlightIndex();
}

void vadp_p2v_main_menu_get_index_order(VfxU8* menuOrder, VfxU32 count)
{
    VfxU32 i;
    for (i = 0; i < count; i ++)
    {
        menuOrder[i] = (VfxU8)g_vapp_mm_component->m_matrix->m_menuPreOrder[i];
    }
}

void vapt_p2v_main_menu_init(S32 nitems, U16* string_id, U16* iconId, S32 highlight_id, U8* menuOrder, VfxU8 Style)
{
    VcpAppScr::initalize();

    
    VFX_UNUSED(nitems);
    
    VFX_OBJ_CREATE_EX(
        g_vapp_mm_component,
        VappMmScr, 
        VcpAppScr::getContext(), 
        ((VfxU16*)string_id, (VfxU16*)iconId, (VfxS32)highlight_id, (VfxU8*)menuOrder, Style));    /* constructor parameters */
    
}


void vapt_p2v_main_menu_deinit()
{
    /*
     * Leave the screen
     */
    VFX_OBJ_CLOSE(g_vapp_mm_component);
    
    VcpAppScr::deinitalize();
}

/*****************************************************************************
 * FUNCTION
 *  GetCategory14HistorySize
 * DESCRIPTION
 *  Gets the history buffer size for the category14 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8s of the history buffer
 *****************************************************************************/
S32 get_mm_history_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((S32)sizeof(mm_style1_history_struct));
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory14History
 * DESCRIPTION
 *  Gets the history buffer for the category14 screen
 * PARAMETERS
 *  history_buffer      [IN]        Is the buffer into which the history data is stored (pre-allocated)
 * RETURNS
 *  pointer to the history buffer
 *****************************************************************************/
U8 *get_mm_history(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 nvram_buf[NVRAM_EF_VENUS_MM_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (history_buffer != NULL)
    {
#if defined(__MMI_MAINLCD_240X400__)
        U16 hID = (U16) (MMI_CATEGORY14_MATRIX_PAGE_ID | 0x8000);
#else
        U16 hID = (U16) (MMI_CATEGORY14_MATRIX_ID | 0x8000);
#endif
        mm_style1_history_struct *h = (mm_style1_history_struct*) history_buffer;

        h->history_ID = hID;
        vadp_p2v_main_menu_get_index_order((VfxU8*)nvram_buf, MATRIX_MAIN_MENU_ITEMS);
        h->highlighted_item = vadp_p2v_main_menu_get_highlight_index();
        h->highlighted_item = nvram_buf[h->highlighted_item];
        main_menu_index = h->highlighted_item;
        h->highlighted_column = h->highlighted_item % MATRIX_MAIN_MENU_COLUMNS;
        h->highlighted_row = h->highlighted_item / MATRIX_MAIN_MENU_COLUMNS;
        h->displayed_rows = MATRIX_MAIN_MENU_ROWS;
        h->displayed_columns = MATRIX_MAIN_MENU_COLUMNS;
        h->first_displayed_row = 0;
        h->first_displayed_column = 0;
        h->flags = UI_MATRIX_MENU_LOOP | UI_MATRIX_MENU_FOR_MAINMENU|current_fixed_matrix_menu_theme->flags;
#if defined(__MMI_MAINMENU_MATRIX_LOOP__)
        h->flags |= UI_MATRIX_MENU_VERTICAL_LOOP;
#endif /* defined(__MMI_MAINMENU_MATRIX_LOOP__) */ 

    } 
    return history_buffer;
}

#ifdef __cplusplus
extern "C"
{
#endif
/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_main_menu_style1_entry
 * DESCRIPTION
 *  Venus application main menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_main_menu_style1_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n_items, i, j;
    U16 mm_stringIDs[MATRIX_MAIN_MENU_ITEMS], mm_string_tree[MATRIX_MAIN_MENU_ITEMS];
    U16 mm_iconIDs[MATRIX_MAIN_MENU_ITEMS],mm_icon_tree[MATRIX_MAIN_MENU_ITEMS];
    U8 *history_buffer;
    mm_style1_history_struct *h;
    list_menu_category_history *h_list;
    U8 nvram_buf[NVRAM_EF_VENUS_MM_SIZE];
    S16 error, highlighted_index = 0;
    U8 Style;
    MMI_MENU_ID mmi_menuitem_list[MAX_MAIN_MENU_ITEMS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    n_items = GetNumOfChild(IDLE_SCREEN_MENU_ID);
    GetSequenceItemIds(IDLE_SCREEN_MENU_ID, mmi_menuitem_list);
    GetSequenceStringIds(IDLE_SCREEN_MENU_ID, (MMI_ID_TYPE*)mm_string_tree);
    GetSequenceImageIds(IDLE_SCREEN_MENU_ID, (MMI_ID_TYPE*)mm_icon_tree);
    for (i = 0; i < n_items; i++)
    {
        mm_icon_tree[i] = mmi_res_get_mainmenu_img(mmi_menuitem_list[i], MMI_RG_MM_IMG_VENUS1);
    }

    GetCategoryHistory = get_mm_history;
    GetCategoryHistorySize = get_mm_history_size;
    
   // history_buffer = GetCurrGuiBuffer(MAIN_MENU_SCREENID);
    history_buffer = mmi_frm_scrn_get_active_gui_buf();
    h_list = NULL;
    if (history_buffer != NULL)
    {
        h = (mm_style1_history_struct*) history_buffer;
#if defined(__MMI_MAINLCD_240X400__)
        if (!history_valid(h->history_ID, MMI_CATEGORY14_MATRIX_PAGE_ID))
        {
            h = NULL;
            h_list = (list_menu_category_history*)history_buffer;
            if (!history_valid(h_list->history_ID, MMI_CATEGORY14_LIST_ID))
                h_list = NULL;
        }

#else   
        if (!history_valid(h->history_ID, MMI_CATEGORY14_MATRIX_ID))
        {
            h = NULL;
            h_list = (list_menu_category_history*)history_buffer;
            if (!history_valid(h_list->history_ID, MMI_CATEGORY14_LIST_ID))
                h_list = NULL;
        }
#endif
    }
    else
    {
        h = NULL;
    }
    
    ReadRecord(
        NVRAM_EF_VENUS_MM_LID, 
        1, 
        nvram_buf, 
        NVRAM_EF_VENUS_MM_SIZE, 
        &error);

    MMI_ASSERT(error == NVRAM_READ_SUCCESS);
   
    error = 0;
    for (i = 0; i < MATRIX_MAIN_MENU_ITEMS; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (nvram_buf[i] == nvram_buf[j])
            {
                error = 1;
            }
        }
    }
    if (error == 1)
    {
        for (i = 0; i < MATRIX_MAIN_MENU_ITEMS; i++)
        {
            nvram_buf[i] = i;
        }
        WriteRecord(
            NVRAM_EF_VENUS_MM_LID,
            1,
            nvram_buf,
            NVRAM_EF_VENUS_MM_SIZE,
            &error);
        MMI_ASSERT(error == NVRAM_WRITE_SUCCESS);
    }

    for (i = 0; i < MATRIX_MAIN_MENU_ITEMS; i++)
    {
        j = nvram_buf[i];
        mm_stringIDs[i] = mm_string_tree[j];
        mm_iconIDs[i] = mm_icon_tree[j];
        if (h != NULL && h->highlighted_item == j)
        {
            highlighted_index = i; 
        }
        else if (h == NULL && h_list != NULL &&  h_list->highlighted_item == j)
        {
            highlighted_index = i; 
        }
    }
    
    Style = mmi_phnset_get_vui_mm_effect_status();
    
    if (h != NULL)
    {
        vapt_p2v_main_menu_init(n_items, mm_stringIDs, mm_iconIDs, highlighted_index, nvram_buf, Style);
    }
    else if (h_list != NULL)
    {
        vapt_p2v_main_menu_init(n_items, mm_stringIDs, mm_iconIDs, highlighted_index, nvram_buf, Style);
    }
    else
    {
        vapt_p2v_main_menu_init(n_items, mm_stringIDs, mm_iconIDs, -1, nvram_buf, Style);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vadp_p2v_main_menu_style1_exit
 * DESCRIPTION
 *  Venus application main menu screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vadp_p2v_main_menu_style1_exit(void)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 nvram_buf[NVRAM_EF_VENUS_MM_SIZE];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    
    vadp_p2v_main_menu_get_index_order((VfxU8*)nvram_buf, MATRIX_MAIN_MENU_ITEMS);
    
    WriteRecord(
        NVRAM_EF_VENUS_MM_LID,
        1,
        nvram_buf,
        NVRAM_EF_VENUS_MM_SIZE,
        &error);
    MMI_ASSERT(error == NVRAM_WRITE_SUCCESS);
    
    vapt_p2v_main_menu_deinit();
} 
#ifdef __cplusplus
}   /* extern "C" */
#endif
#endif /* __MMI_VUI_MAINMENU__*/

//  3D mainmenu
#ifdef __MMI_VUI_3D_MAINMENU__
#include "Mainmenu/vcp_fancy_mode_menu.h"
typedef struct
{
    /* History ID */
    U16 history_ID;
    /* The display page of 3d mainmenu */
    U16 current_page;
	U16 app_index;
	/* current focus app index */
    S32 focus_index;
	/* The total items of 3d mainmenu */
	U16 num;
	/* mode */
    U8 mode;
	U8 fancy_style;
} mm_3d_main_menu_history_struct;

static Vapp3DMmScr *g_vapp_3d_mm_component = NULL;

S32 get_3d_mm_history_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((S32)sizeof(mm_3d_main_menu_history_struct));
}


U8 *get_3d_mm_history(U8 *history_buffer)
{
	if (history_buffer != NULL)
    {
        mm_3d_main_menu_history_struct *h = (mm_3d_main_menu_history_struct*) history_buffer;

		h->current_page = g_vapp_3d_mm_component->getCurrentPageIndex();
		h->num = g_vapp_3d_mm_component->m_items;
		h->mode = g_vapp_3d_mm_component->m_mode;
		h->app_index = g_vapp_3d_mm_component->getCurrentAppIndex();
		h->focus_index = g_vapp_3d_mm_component->getCurrentFocusIndex();
		h->fancy_style = g_vapp_3d_mm_component->m_style;

    } 
	return history_buffer;
}

void vapt_p2v_3d_main_menu_init(S32 nitems, AppEntry* app_info, FuncPtr *launch_table, U8 *order, U8 curr_page, U8 mode, U8 style, U8 index, S32 focus_index)
{
    //VcpAppScr::initalize();
	VcpAppScr::initalize();//WithScrAsmSize(300*1024);


	VFX_OBJ_CREATE_EX(
		g_vapp_3d_mm_component,
		Vapp3DMmScr,
		VcpAppScr::getContext(),
		((VfxU16)nitems, app_info, launch_table, (VfxU8*)order, (VfxS32)curr_page, (VfxU8)mode, (VfxU8)style, (VfxU8)index, (VfxS32)focus_index));

}

void vapt_p2v_3d_main_menu_deinit()
{
    /*
     * Leave the screen
     */
    VFX_OBJ_CLOSE(g_vapp_3d_mm_component);
    
    VcpAppScr::deinitalize();
}

void vadp_p2v_3d_main_menu_get_index_order(VfxU8* menuOrder)
{

    for (VfxU16 i = 0; i < NVRAM_EF_VENUS_3D_MM_SIZE; i++)
    {
		if(g_vapp_3d_mm_component->m_order[i] == 0xFFFFFFFF)
		{
			menuOrder[i] = 0xFF;
		}
		else
		{
        menuOrder[i] = (VfxU8)g_vapp_3d_mm_component->m_order[i];
    }
    }

}
void vadp_p2v_3d_main_menu_leave_organization()
{
	g_vapp_3d_mm_component->leaveOrganizationMode(VFX_TRUE);
}

#ifdef __cplusplus
extern "C"
{
#endif
void vadp_p2v_3d_main_menu_exit(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 nvram_buf[NVRAM_EF_VENUS_3D_MM_SIZE];
	U8 mode;
	U8 style;

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	/* Get current page index, order */
	vadp_p2v_3d_main_menu_leave_organization();  
	vadp_p2v_3d_main_menu_get_index_order((VfxU8*)nvram_buf);
	WriteRecord(
        NVRAM_EF_VENUS_3D_MM_LID,
        1,
        nvram_buf,
        NVRAM_EF_VENUS_3D_MM_SIZE,
        &error);
    MMI_ASSERT(error == NVRAM_WRITE_SUCCESS);
	mode = g_vapp_3d_mm_component->m_mode;
	style = g_vapp_3d_mm_component->m_style;
	mode = mode<<1;
	mode = (mode | style);
	WriteValue(NVRAM_EF_VENUS_3D_MM_MODE, &mode, DS_BYTE, &error);
	vapt_p2v_3d_main_menu_deinit();
}

void vadp_p2v_3d_main_menu_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n_items;
    U16 mm_string_tree[VAPP_3D_MAINMENU_MAX_COUNT];
	MMI_MENU_ID mmi_menuitem_list[VAPP_3D_MAINMENU_MAX_COUNT];

    U8 *history_buffer;
    mm_3d_main_menu_history_struct *h;
 
    S16 error = 1;
    U8 nvram_buf[NVRAM_EF_VENUS_3D_MM_SIZE]; 
	AppEntry app_info[VAPP_3D_MAINMENU_MAX_COUNT];
	FuncPtr launch_table[VAPP_3D_MAINMENU_MAX_COUNT];

	U8 current_page = 0;
	U8 buf;
	U8 mode = 0; // default normal mode;
	U8 style = 0;
	U8 i, j;
	U8 app_index = 0;
	S32 focus_index = -1;
	S16 Err = 0;

	S32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	// Get menuitem num,  menu id, menu string;
    n_items = GetNumOfChild(IDLE_SCREEN_MENU_ID);
    MMI_ASSERT(n_items <= VAPP_3D_MAINMENU_MAX_COUNT);
    GetSequenceItemIds(IDLE_SCREEN_MENU_ID, mmi_menuitem_list);
    GetSequenceStringIds(IDLE_SCREEN_MENU_ID, (MMI_ID_TYPE*)mm_string_tree);

    GetCategoryHistory = get_3d_mm_history;
    GetCategoryHistorySize = get_3d_mm_history_size;
    
    history_buffer = mmi_frm_scrn_get_active_gui_buf();
	if(history_buffer != NULL)
	{
		h = (mm_3d_main_menu_history_struct*) history_buffer;
		current_page = h->current_page;
		mode = h->mode;
		app_index = h->app_index;
		focus_index = h->focus_index;
		style =h->fancy_style;

	}
	else
	{
		ReadValue(NVRAM_EF_VENUS_3D_MM_MODE, &buf, DS_BYTE, &Err);
		if (buf == 0xFF || Err != NVRAM_READ_SUCCESS)
		{
			mode = 0;
			style = 0;
		}
		else
		{
			mode = buf>>1;
			style = buf & 0xFD;
		}
	}
	// create default app info table
	for (i = 0; i < n_items; i++)
    {
		
		app_info[i].appTitle = VFX_WSTR_RES(mm_string_tree[i]);
		app_info[i].appIcon = mmi_res_get_mainmenu_3d_img_id(mmi_menuitem_list[i]);
		app_info[i].entry = 0;//mmi_res_get_mainmenu_launch_handler(mmi_menuitem_list[i]);
		launch_table[i] = mmi_res_get_mainmenu_launch_handler(mmi_menuitem_list[i]);
    }
	// read order from NVRAM
    ReadRecord(
        NVRAM_EF_VENUS_3D_MM_LID, 
        1, 
        nvram_buf, 
        NVRAM_EF_VENUS_3D_MM_SIZE, 
        &error);

    MMI_ASSERT(error == NVRAM_READ_SUCCESS); 
    error = 0;
	// check if first boot up
    for (i = 0; i < NVRAM_EF_VENUS_3D_MM_SIZE; i++)
    {
        for (j = 0; j < i; j++)
        {
            if ((nvram_buf[i] == nvram_buf[j]) && (nvram_buf[i] != 0xFF))
            {
                error = 1;
				break;
            }
        }
		if(nvram_buf[i] != 0xFF)
			count++;
    }

	// set default order
    if ((error == 1) || (count != n_items))
    {
 
        for (i = 0, j = 0; i < n_items; i++)
        {
			if((i + 1)%VAPP_3D_MAINMENU_NUM_IN_PAGE)
			{
				nvram_buf[j++] = i;
			}
			else
			{
				nvram_buf[j++] = i;
				nvram_buf[j++] = 0xFF;
			}
				
        }
		if(j < n_items)
			j = n_items;

		while(j < NVRAM_EF_VENUS_3D_MM_SIZE)
		{
			nvram_buf[j++] = 0xFF;
		}

        WriteRecord(
            NVRAM_EF_VENUS_3D_MM_LID,
            1,
            nvram_buf,
            NVRAM_EF_VENUS_3D_MM_SIZE,
            &error);
        MMI_ASSERT(error == NVRAM_WRITE_SUCCESS);
    }

    vapt_p2v_3d_main_menu_init(n_items, app_info, launch_table, nvram_buf, current_page, mode, style, app_index, focus_index);

}
#ifdef __cplusplus
}   /* extern "C" */
#endif
#endif
