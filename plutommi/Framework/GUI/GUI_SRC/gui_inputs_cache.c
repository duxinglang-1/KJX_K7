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
 *   gui_inputs_cache.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Editor Cache Management modul
 *
 *   
 *   [Multi-line input box]
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "gui_inputs.h"
//#include "gui_themes.h"
#include "MMI_features.h"
//#include "gui_theme_struct.h"
//#include "gdi_include.h"
//#include "lcd_sw_rnd.h"
#include "gui_ems.h"
#include "BIDIDEF.h"
#include "BIDIProt.h"
#include "gui_inputs_internal.h"
#include "med_utility.h"

    #include "lcd_sw_inc.h"
    #include "MMIDataType.h"
    #include "PixcomFontEngine.h"
    #include "gdi_mutex.h"
    #include "kal_general_types.h"
    #include "gui.h"
    #include "MMI_fw_trc.h"
    #include "mmi_fw_trc.h"
    #include "DebugInitDef_Int.h"
    #include "kal_trace.h"
    #include "string.h"
    #include "kal_public_api.h"
    #include "ems.h"
    #include "IndicRuleEngineCommon.h"

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
/* Global variable */
input_box_line_cache_struct g_line_cache;
input_box_line_cache_struct *g_line_cache_p = &g_line_cache;

U32 editor_visible_line_count = UI_DEVICE_HEIGHT/10;

gui_editor_character_unit_struct g_line_char[GUI_INPUTS_MAX_NUM_OF_CHAR_FOR_EACH_LINE/2];
gui_editor_character_unit_struct* temp_line_char = g_line_char; 

static S32 g_cache_off = 0;
static gdi_mutex_struct g_cache_mutext;

static void gui_inputs_cache_free_mem(void);

/* Defination */
#define PARTIAL_UPDATE_TIMER            50
#define PARTIAL_UPDATE_LINE_MAX         30
#define PARTIAL_UPDATE_PREVIOUS_LINE    2


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_cache_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [IN]        
 *  mem_p           [?]         
 *  mem_size        [IN]        
 * RETURNS
 *  MMI_BOOL 
 *****************************************************************************/
MMI_BOOL gui_inputs_cache_create(void *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    g_line_cache_p->b = b;
    g_line_cache_p->b_create = ERROR_CACHE_INVALID;
    gui_inputs_cache_destroy();
        
    if (g_cache_off)
    {
        return MMI_FALSE;
    }

    if (g_line_cache_p->visible_line_cache_p == NULL)
    {
        g_line_cache_p->visible_cache_size = size = gui_inputs_cache_visible_size_get();
        g_line_cache_p->visible_line_cache_p = (void *)med_alloc_temp_ext_mem(size, gui_inputs_cache_free);
        if (g_line_cache_p->visible_line_cache_p == NULL)
        {
            g_line_cache_p->visible_cache_size = 0;
            return MMI_FALSE;
        }
        /* Add cleanup hook, when exit category (UI_common_screen_exit), free med memory */
        gui_add_cleanup_hook(gui_inputs_cache_free_mem);
    }

    if (g_line_cache_p->all_line_cache_p == NULL)
    {
        g_line_cache_p->all_line_cache_size = size = gui_inputs_cache_all_line_size_get();
        g_line_cache_p->all_line_cache_p = (void *)med_alloc_temp_ext_mem(size, gui_inputs_cache_free);
        if (g_line_cache_p->all_line_cache_p == NULL)
        {
			if (g_line_cache_p->visible_line_cache_p != NULL)
			{
				med_free_temp_ext_mem((void**)&g_line_cache_p->visible_line_cache_p);
				g_line_cache_p->visible_cache_size = 0;
				g_line_cache_p->visible_line_cache_p = NULL;
			}

            g_line_cache_p->all_line_cache_size = 0;
            return MMI_FALSE;
        }
        else
        {
            #ifdef UI_EMS_SUPPORT
            g_line_cache_p->ems_all_line_cache_p = (void*)(g_line_cache_p->all_line_cache_p);
            #endif
            g_line_cache_p->all_line_max_count = GUI_INPUT_BOX_ALL_LINE_MAX;
        }
        /* Add cleanup hook, when exit category (UI_common_screen_exit), free med memory */
        gui_add_cleanup_hook(gui_inputs_cache_free_mem);
    }

    g_line_cache_p->visible_start_y = 0;
    g_line_cache_p->visible_end_y = 0;
    g_line_cache_p->visible_start_index = 0;
    g_line_cache_p->visible_end_index = 0;
    g_line_cache_p->updating_line_index = 0;
    g_line_cache_p->all_line_count = 0;
    g_line_cache_p->total_height = 0;
    g_line_cache_p->visible_line_ok = 0;
    g_line_cache_p->max_line_height = 0;
    g_line_cache_p->update_visible_only = 0;
    g_line_cache_p->updating_line_y = 0;
    g_line_cache_p->b_create = 1;
    g_line_cache_p->flags = 0;
    g_line_cache_p->ext_flags = 0;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_cache_destroy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void            
 * RETURNS
 *  void 
 *****************************************************************************/
void gui_inputs_cache_destroy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_line_cache_p->b_create = ERROR_CACHE_INVALID;
    gui_cancel_timer(gui_mlc_partial_line_update);
#ifdef UI_EMS_SUPPORT
    gui_cancel_timer(gui_emsc_partial_line_update);
#endif
    g_line_cache_p->timer_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
*  gui_inputs_cache_switch
* DESCRIPTION
*  
* PARAMETERS
*  S32        
* RETURNS
*  void 
*****************************************************************************/
void gui_inputs_cache_switch(S32 b_off)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cache_off = b_off;
    if (g_cache_off)
    {
        g_line_cache_p->b_create = ERROR_CACHE_INVALID;
    }
}


/*****************************************************************************
* FUNCTION
*  gui_inputs_cache_is_not_in_update
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
S32 gui_inputs_cache_is_not_in_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_line_cache_p->b_create <= 0)
    {
        return 0;
    }
    
    return (g_line_cache_p->updating_line_index == -1);
}


/*****************************************************************************
 * FUNCTION
*  gui_inputs_cache_invalid
* DESCRIPTION
*  
* PARAMETERS
*  void        
* RETURNS
*  void 
*****************************************************************************/
void gui_inputs_cache_invalid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_line_cache_p->b_create = ERROR_CACHE_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_cache_visible_size_get
 * DESCRIPTION
 *  
 * PARAMETERS
 * void        
 * RETURNS
 *  S32 
 *****************************************************************************/
S32 gui_inputs_cache_visible_size_get(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(input_box_visible_line_struct) * GUI_INPUT_BOX_VISIBLE_LINE_COUNT;
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_cache_all_line_size_get
 * DESCRIPTION
 *  
 * PARAMETERS
 * void        
 * RETURNS
 *  S32 
 *****************************************************************************/
S32 gui_inputs_cache_all_line_size_get(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(input_box_all_line_struct) * GUI_INPUT_BOX_ALL_LINE_MAX;
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_cache_all_line_realloc
 * DESCRIPTION
 *  
 * PARAMETERS
 * void        
 * RETURNS
 *  S32 
 *****************************************************************************/
S32 gui_inputs_cache_all_line_realloc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 new_line, new_size;
    void *p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_line = g_line_cache_p->all_line_max_count + GUI_INPUT_BOX_ALL_LINE_MAX;
    new_size = g_line_cache_p->all_line_cache_size + gui_inputs_cache_all_line_size_get();

    p = (void *)med_alloc_temp_ext_mem(new_size, gui_inputs_cache_free);
    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_CACHE_REALLOC_ALL_LINE, p);
    if (p)
    {
        /* enlarge the all line buffer */
        if (g_line_cache_p->all_line_cache_p != NULL)
        {
            memcpy(p, g_line_cache_p->all_line_cache_p, g_line_cache_p->all_line_cache_size);
            med_free_temp_ext_mem((void**)&g_line_cache_p->all_line_cache_p);
        }
        
        g_line_cache_p->all_line_cache_p = p;
#ifdef UI_EMS_SUPPORT
        g_line_cache_p->ems_all_line_cache_p = p;
#endif
        g_line_cache_p->all_line_cache_size = new_size;
        g_line_cache_p->all_line_max_count = new_line;
        g_line_cache_p->b_create = (g_line_cache_p->b_create > ERROR_CACHE_INVALID) ? 
                                     g_line_cache_p->b_create + 1 : 1;
        return g_line_cache_p->all_line_cache_size;
    }
    else
    {
        /* realloc fail */
		if (g_line_cache_p->all_line_cache_p != NULL)
		{
			med_free_temp_ext_mem((void**)&g_line_cache_p->all_line_cache_p);
            g_line_cache_p->all_line_cache_p = NULL;
#ifdef UI_EMS_SUPPORT
            g_line_cache_p->ems_all_line_cache_p = NULL;
#endif
		}
        
        g_line_cache_p->b_create = ERROR_CACHE_REALLOC_FAIL;
        return 0;
    }
}



/*****************************************************************************
 * FUNCTION
 *  gui_inputs_cache_get_error_code
 * DESCRIPTION
 *  
 * PARAMETERS
 * void        
 * RETURNS
 *  S32 
 *****************************************************************************/
S32 gui_inputs_cache_get_error_code(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_line_cache_p->b_create;
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_cache_free_mem
 * DESCRIPTION
 *  Free Med memory and clear cache variable
 * PARAMETERS
 *  void        
 * RETURNS
 *  void 
 *****************************************************************************/
static void gui_inputs_cache_free_mem(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_line_cache_p->visible_line_cache_p)
    {
        med_free_temp_ext_mem((void**)&g_line_cache_p->visible_line_cache_p);
        gui_inputs_cache_free(g_line_cache_p->visible_line_cache_p);
    }
    if (g_line_cache_p->all_line_cache_p)
    {
        med_free_temp_ext_mem((void**)&g_line_cache_p->all_line_cache_p);
        gui_inputs_cache_free(g_line_cache_p->all_line_cache_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_inputs_cache_free
 * DESCRIPTION
 *  
 * PARAMETERS
 * void        
 * RETURNS
 *  MMI_BOOL 
 *****************************************************************************/
void gui_inputs_cache_free(void* p)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* one cache need to release, invalid cache */
    
    EDITOR_LOCK;
    
    MMI_TRACE(MMI_FW_TRC_G4_EDITOR, MMI_GUI_EDITOR_CACHE_FORCED_FREE);
    if (g_line_cache_p->visible_line_cache_p == p)
    {
        g_line_cache_p->visible_line_cache_p = NULL;
    }
    else if (g_line_cache_p->all_line_cache_p == p)
    {
        g_line_cache_p->all_line_cache_p = NULL;
    }

    g_line_cache_p->b_create = ERROR_CACHE_INVALID;
    
    EDITOR_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  gui_create_multi_line_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [IN]        
 *  mem_p           [?]         
 *  mem_size        [IN]        
 * RETURNS
 *  MMI_BOOL 
 *****************************************************************************/
MMI_BOOL gui_inputs_cache_is_valid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_line_cache_p->b_create > ERROR_CACHE_INVALID)
        return MMI_TRUE;
    else
    {
        if (g_line_cache_p->b_create == ERROR_CACHE_REALLOC_FAIL)
        {
            if (gui_inputs_cache_all_line_realloc() > 0)
            {
                gui_mlc_all_line_update();
                return MMI_TRUE;
            }
            else
                g_line_cache_p->b_create = ERROR_CACHE_INVALID;
            
        }
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_mlc_is_dirty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b            [IN]         
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_mlc_is_dirty(multi_line_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 care_flags, care_ext_flags;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_line_cache_p->b != (void*)b
        || ((multi_line_input_box*)g_line_cache_p->b)->text != b->text)
        return MMI_TRUE;
    else
    {
        care_flags = UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR 
            | UI_MULTI_LINE_INPUT_BOX_RICHTEXT | UI_MULTI_LINE_INPUT_BOX_MASK_CHARACTERS;
/* slim_2_2 */ //        care_ext_flags = GUI_MULTI_LINE_INPUT_BOX_CHAT_ICON_DISPLAY;
        
        if ((g_line_cache_p->flags & care_flags) != (b->flags & care_flags)
       /* slim_2_2 */ //     ||  (g_line_cache_p->ext_flags & care_ext_flags) != (b->ext_flags & care_ext_flags)
            )
            return MMI_TRUE;
        
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_mlc_text_format_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  richtext            [?]     
 *  format_cache        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_mlc_text_format_set(gui_input_richtext_struct *richtext, input_box_line_format_struct *format_cache)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    format_cache->alignment = richtext->curr_alignment;
    format_cache->border = richtext->curr_border;
    format_cache->font = richtext->curr_font;
    format_cache->strikethrough = richtext->curr_strikethrough;
    format_cache->text_bg_color = richtext->curr_text_bg_color;
    format_cache->text_color = richtext->curr_color;
    format_cache->more_line_spacing = richtext->more_line_spacing;
    format_cache->line_separator = richtext->line_separator;
}


/*****************************************************************************
 * FUNCTION
 *  gui_mlc_text_format_get
 * DESCRIPTION
 *  
 * PARAMETERS
 *  richtext            [?]     
 *  format_cache        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_mlc_text_format_get(gui_input_richtext_struct *richtext, input_box_line_format_struct *format_cache)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    richtext->curr_border = format_cache->border;
    richtext->curr_font = format_cache->font;
    richtext->curr_strikethrough = format_cache->strikethrough;
    richtext->curr_text_bg_color = format_cache->text_bg_color;
    richtext->curr_color = format_cache->text_color;
    richtext->more_line_spacing = format_cache->more_line_spacing;
}

/*****************************************************************************
 * FUNCTION
 *  gui_mlc_line_cache_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]     
 *  line_unit       [?]     
 *  line_cache      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_mlc_line_cache_set(
        multi_line_input_box *b,
        gui_editor_line_unit_struct *line_unit,
        input_box_all_line_struct *line_cache)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    line_cache->start_offset = line_unit->line_start_p - b->text;
    line_cache->line_height = line_unit->line_height;
    line_cache->line_width = line_unit->line_width;
    line_cache->char_count = line_unit->line_char_count;
    line_cache->line_ascent = line_unit->line_ascent;
    line_cache->line_dscent = line_unit->line_dscent;
}


/*****************************************************************************
 * FUNCTION
 *  gui_mlc_total_line_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_mlc_total_line_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_line_cache_p->total_height;
}

/*****************************************************************************
 * FUNCTION
 *  gui_mlc_total_line_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_mlc_total_line_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_line_cache_p->all_line_count;
}


/*****************************************************************************
 * FUNCTION
 *  gui_mlc_visible_line_cache_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                       [?]     
 *  line_unit               [?]     
 *  visible_line_cache      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_mlc_visible_line_cache_set(
        multi_line_input_box *b,
        gui_editor_line_unit_struct *line_unit,
        input_box_visible_line_struct *visible_line_cache)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    visible_line_cache->highlight_flag = line_unit->highlight_flag;
    visible_line_cache->line_char_count = line_unit->line_char_count;
    visible_line_cache->line_unit_count = line_unit->line_unit_count;
    visible_line_cache->override_flag = line_unit->override_flag;
    visible_line_cache->marker_flag = line_unit->marker_flag;
    memcpy(
        visible_line_cache->line_char,
        line_unit->line_char,
        sizeof(gui_editor_character_unit_struct) * (line_unit->line_unit_count));
}


/*****************************************************************************
 * FUNCTION
 *  gui_mlc_is_line_visible
 * DESCRIPTION
 *  
 * PARAMETERS
 *  y1      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_mlc_is_line_visible(S32 y1, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (y1 > g_line_cache_p->visible_end_y + GUI_INPUT_BOX_ADDITION_AREA)
    {
        /* under the visible area */
        return 1;
    }
    else if (y2 < g_line_cache_p->visible_start_y - GUI_INPUT_BOX_ADDITION_AREA)
    {
        /* upper the visible area */
        return -1;
    }
    else
        return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_mlc_visible_start_line_get
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_s       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_mlc_visible_start_line_get(input_box_line_index_struct *idx_s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx_s->index = g_line_cache_p->visible_start_index;
    if (idx_s->index < 0)
    {
        idx_s->offset = g_line_cache_p->all_line_cache_p[g_line_cache_p->all_line_count-1].start_offset;
        idx_s->offset_y = gui_mlc_line_cache_one_line_offset_y(g_line_cache_p->all_line_count-1);
    }
    else
    {
        idx_s->offset = g_line_cache_p->all_line_cache_p[idx_s->index].start_offset;
        idx_s->offset_y = gui_mlc_line_cache_one_line_offset_y(idx_s->index);
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_mlc_visible_end_line_get
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_e       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_mlc_visible_end_line_get(input_box_line_index_struct *idx_e)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx_e->index = g_line_cache_p->visible_end_index;
    if (idx_e->index < 0)
    {
        idx_e->offset = g_line_cache_p->all_line_cache_p[g_line_cache_p->all_line_count-1].start_offset;
        idx_e->offset_y = gui_mlc_line_cache_one_line_offset_y(g_line_cache_p->all_line_count-1);
    }
    else
    {
        idx_e->offset = g_line_cache_p->all_line_cache_p[idx_e->index].start_offset;
        idx_e->offset_y = gui_mlc_line_cache_one_line_offset_y(idx_e->index);
    }


    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_mlc_visible_info_get
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
input_box_visible_line_struct *gui_mlc_visible_info_get(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_line_cache_p->updating_line_index < 0 || idx < g_line_cache_p->updating_line_index);
    ASSERT(idx >= g_line_cache_p->visible_start_index);

    return &(g_line_cache_p->visible_line_cache_p[idx - g_line_cache_p->visible_start_index]);
}

/*****************************************************************************
 * FUNCTION
 *  gui_mlc_text_format_info_get
 * DESCRIPTION
 *  
 * PARAMETERS
 *  richtext        [?]         
 *  idx             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_mlc_text_format_info_get(gui_input_richtext_struct *richtext, S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_line_cache_p->updating_line_index < 0 || idx < g_line_cache_p->updating_line_index);

    if (idx > 0)
    {
        gui_mlc_text_format_get(richtext, &(g_line_cache_p->all_line_cache_p[idx - 1].line_end_format));
    }

    /* line separator, use current line format */
    richtext->line_separator = g_line_cache_p->all_line_cache_p[idx].line_end_format.line_separator;
    /* alignment, use current line format */
    richtext->curr_alignment = (gui_input_alignment_enum)(g_line_cache_p->all_line_cache_p[idx].line_end_format.alignment);

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  gui_mlc_visible_line_range_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  y1      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_mlc_visible_line_range_set(S32 *sl, S32 *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, y_start = 0, y_end = 0, in_visible;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *sl = -1;
    *el = -1;
    
    for (i=0; i<g_line_cache_p->all_line_count; i++)
    {
        y_end = y_start + g_line_cache_p->all_line_cache_p[i].line_height;
        in_visible = gui_mlc_is_line_visible(y_start, y_end);
        if (in_visible == 0)
        {
            if (*sl < 0)
                *sl = i;
            
            *el = i;
        }
        else if (in_visible > 0)
        {
            break;
        }
        y_start = y_end;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_mlc_character_line_index_find
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_mlc_character_line_index_find(S32 char_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, r = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    j = (g_line_cache_p->updating_line_index < 0) ? (g_line_cache_p->all_line_count) : g_line_cache_p->updating_line_index;
    for (i = 0; i < j; i++)
    {
        r = (g_line_cache_p->all_line_cache_p[i].start_offset)/ENCODING_LENGTH;
        if (char_index < r + g_line_cache_p->all_line_cache_p[i].char_count)
            return i;
        else if(i == j - 1)
        {
            if (char_index <= r + g_line_cache_p->all_line_cache_p[i].char_count + 1)
            return i;
        }
    }

    return -1;    
}

/*****************************************************************************
 * FUNCTION
 *  gui_mlc_line_cache_one_line_offset_y
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_mlc_line_cache_one_line_offset_y(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_line_cache_p->updating_line_index < 0 || idx <= g_line_cache_p->updating_line_index);

    for (i = 0; i < idx; i++)
    {
        y += g_line_cache_p->all_line_cache_p[i].line_height;
    }

    return y;

}


/*****************************************************************************
 * FUNCTION
 *  gui_mlc_line_info_get
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
input_box_all_line_struct *gui_mlc_line_info_get(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_line_cache_p->updating_line_index < 0 || idx < g_line_cache_p->updating_line_index);

    return &(g_line_cache_p->all_line_cache_p[idx]);
}


/*****************************************************************************
 * FUNCTION
 *  gui_mlc_line_cache_max_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_mlc_line_cache_max_height(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_line_cache_p->updating_line_index < 0 || idx <= g_line_cache_p->updating_line_index);

    for (i = 0; i < idx; i++)
    {
        if(y < g_line_cache_p->all_line_cache_p[i].line_height)
            y = g_line_cache_p->all_line_cache_p[i].line_height;
    }

    return y;

}

S32 gui_mlc_line_context_set(multi_line_input_box* b, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multi_line_input_box_show_struct *bs = param;
    input_box_all_line_struct *all_line_start_p; 
    S32 y, text_offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (g_line_cache_p->line_query_begin == 0)
        return 0;
    
    all_line_start_p = &g_line_cache_p->all_line_cache_p[g_line_cache_p->line_query_begin-1];
    
    y = gui_mlc_line_cache_one_line_offset_y(g_line_cache_p->line_query_begin);
    bs->ty += y;
    
    b->max_line_height = gui_mlc_line_cache_max_height(g_line_cache_p->line_query_begin);

    g_editor_line.line_height = all_line_start_p->line_height;

    text_offset = all_line_start_p->start_offset + ENCODING_LENGTH * all_line_start_p->char_count;
    bs->current_text_p = b->text + text_offset;

    bs->rich_text.line_end_font = all_line_start_p->line_end_format.font;
    bs->rich_text.line_end_border = all_line_start_p->line_end_format.border;
    bs->rich_text.line_end_strikethrough = all_line_start_p->line_end_format.strikethrough;
    bs->rich_text.line_end_color = all_line_start_p->line_end_format.text_color;
    bs->line_counter = g_line_cache_p->line_query_begin;
    return 0;
}


/*****************************************************************************
* FUNCTION
*  gui_mlc_change_request
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
S32 gui_mlc_change_request(S32 char_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_line_cache_p->b_create <= 0)
    {
        return 0;
    }
    
    EDITOR_LOCK;
    
    if (g_line_cache_p->updating_line_index == 0)
    {
        /* all data is not updated, just waiting for partial update */
        EDITOR_UNLOCK;
        return 0;
    }
    
    n = gui_mlc_character_line_index_find(char_index);
    
    /* we update line from the index before PARTIAL_UPDATE_PREVIOUS_LINE*/
    n -= PARTIAL_UPDATE_PREVIOUS_LINE;
    if (n < 0)
        n = 0;
    
    if (g_line_cache_p->updating_line_index >= 0)
    {
        /* the update process is running */
        if (n >= g_line_cache_p->updating_line_index)
        {
            /* the change data is not updated , just waiting for partial update*/
            EDITOR_UNLOCK;
            return 0;
        }
    }
    
    g_line_cache_p->updating_line_index = n;
    g_line_cache_p->updating_line_y = gui_mlc_line_cache_one_line_offset_y(g_line_cache_p->updating_line_index);
    g_line_cache_p->visible_line_ok = 0;
    
    if (g_line_cache_p->timer_callback == NULL)
    {
        gui_start_timer(PARTIAL_UPDATE_TIMER, gui_mlc_partial_line_update);
        g_line_cache_p->timer_callback = (void*)gui_mlc_partial_line_update;
    }

    EDITOR_UNLOCK;
    return 1;
    
}

/*****************************************************************************
 * FUNCTION
 *  gui_mlc_all_line_info_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 gui_mlc_all_line_info_save(multi_line_input_box* b, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 in_visible, cur_line_index, new_size;
    multi_line_input_box_show_struct *bs = param;
    input_box_all_line_struct *current_line_cache_p;
    static S32 visible_write = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_line_index = bs->line_counter;
    if (bs->line_counter == 0)
        visible_write= 0;
    
    if (cur_line_index >= g_line_cache_p->all_line_max_count)
    {
        new_size = gui_inputs_cache_all_line_realloc();
        if (new_size == 0)
            return 0;
    }
    
    current_line_cache_p = &g_line_cache_p->all_line_cache_p[cur_line_index];
    
    /* save the line end format */
    gui_mlc_text_format_set(&(bs->rich_text), &(current_line_cache_p->line_end_format));

    /* save this line to cache */
    gui_mlc_line_cache_set(b, &g_editor_line, current_line_cache_p);


    /* if it's visible, save it to the visible line */
    in_visible = gui_mlc_is_line_visible(g_line_cache_p->total_height, g_line_cache_p->total_height + current_line_cache_p->line_height);
    if (in_visible < 0)
    {
        g_line_cache_p->visible_start_index = cur_line_index + 1;
    }
    else if (in_visible == 0)
    {
        gui_mlc_visible_line_cache_set(b, &g_editor_line, 
            &g_line_cache_p->visible_line_cache_p[visible_write++]);
        g_line_cache_p->visible_end_index = cur_line_index;
    }

    g_line_cache_p->total_height += current_line_cache_p->line_height;

    if (bs->end_line)
    {
        /* the last line */
        if (g_line_cache_p->visible_end_index >= g_line_cache_p->visible_start_index)
        {
            g_line_cache_p->visible_line_ok = 1;
        }
        
        g_line_cache_p->all_line_count = cur_line_index + 1;
        g_line_cache_p->updating_line_index = -1;
    }

    return 1;
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_mlc_partial_line_info_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 gui_mlc_partial_line_info_save(multi_line_input_box* b, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 in_visible, cur_line_index, new_size;
    multi_line_input_box_show_struct *bs = param;
    input_box_all_line_struct *current_line_cache_p;
    input_box_visible_line_struct *current_visible_line_cache_p = g_line_cache_p->visible_line_cache_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_line_index = bs->line_counter;

    if (cur_line_index >= g_line_cache_p->all_line_max_count)
    {
        new_size = gui_inputs_cache_all_line_realloc();
        if (new_size == 0)
            return 0;
    }
        
    current_line_cache_p = &g_line_cache_p->all_line_cache_p[cur_line_index];
    
    /* save the line end format */
    gui_mlc_text_format_set(&(bs->rich_text), &(current_line_cache_p->line_end_format));

    /* save this line to cache */
    gui_mlc_line_cache_set(b, &g_editor_line, current_line_cache_p);

    /* if it's visible, save it to the visible line */
    in_visible = gui_mlc_is_line_visible(g_line_cache_p->total_height, g_line_cache_p->total_height + current_line_cache_p->line_height);
    if (in_visible < 0)
    {
        g_line_cache_p->visible_start_index = -1;
        g_line_cache_p->visible_line_ok = 0;
    }
    else if (in_visible == 0)
    {
        if (g_line_cache_p->visible_line_ok)
        {
            /* visible info last time */
            if (cur_line_index <= g_line_cache_p->visible_end_index 
                && cur_line_index >= g_line_cache_p->visible_start_index)
            {
                g_line_cache_p->visible_line_ok = 0;
            }
        }
        else
        {
            if (g_line_cache_p->visible_start_index == -1)
                g_line_cache_p->visible_start_index = cur_line_index;
            current_visible_line_cache_p = &g_line_cache_p->visible_line_cache_p[cur_line_index - g_line_cache_p->visible_start_index];

            gui_mlc_visible_line_cache_set(b, &g_editor_line, current_visible_line_cache_p);
            g_line_cache_p->visible_end_index = cur_line_index;
        }
    }
    else if (in_visible > 0)
    {
        g_line_cache_p->visible_line_ok = 1;
    }

    g_line_cache_p->updating_line_index++;
    g_line_cache_p->total_height += current_line_cache_p->line_height;
    g_line_cache_p->updating_line_y = g_line_cache_p->total_height;
    if (bs->end_line)
    {
        g_line_cache_p->all_line_count = g_line_cache_p->updating_line_index;
        b->n_lines = g_line_cache_p->all_line_count;
        g_line_cache_p->updating_line_index = -1;
        g_line_cache_p->visible_line_ok = 1;
        if (g_line_cache_p->visible_start_index == -1)
        {
            g_line_cache_p->visible_start_index = -1;
            g_line_cache_p->visible_end_index = -1;
        }
        return 0;
    }

    if (g_line_cache_p->updating_line_index >= g_line_cache_p->line_query_end)
    {
        if (g_line_cache_p->timer_callback == NULL)
        {
             gui_start_timer(PARTIAL_UPDATE_TIMER, gui_mlc_partial_line_update);
             g_line_cache_p->timer_callback = (void*)gui_mlc_partial_line_update;
        }

        return 0;
    }
        
    return 1;        
}


/*****************************************************************************
 * FUNCTION
 *  gui_mlc_visible_line_info_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_mlc_visible_line_info_save(multi_line_input_box* b, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cur_line_index;
    multi_line_input_box_show_struct *bs = param;
    input_box_visible_line_struct *current_visible_line_cache_p = g_line_cache_p->visible_line_cache_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_line_index = bs->line_counter;
    
    current_visible_line_cache_p = &g_line_cache_p->visible_line_cache_p[cur_line_index - g_line_cache_p->visible_start_index]; 
    
    gui_mlc_visible_line_cache_set(b, &g_editor_line, current_visible_line_cache_p);

    if (cur_line_index >= g_line_cache_p->line_query_end)
    {
        g_line_cache_p->visible_line_ok = 1;
        return 0;
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_mlc_all_line_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_mlc_all_line_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multi_line_input_box *b = g_line_cache_p->b;
    S32 flags;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EDITOR_LOCK;
    
    if (g_line_cache_p->b_create > 0)
    {
        g_line_cache_p->b_create++;

        /* get visible area */
        gui_get_multi_line_visible_area(b, &(g_line_cache_p->visible_start_y), &(g_line_cache_p->visible_end_y));
        g_line_cache_p->visible_start_index = 0;
        g_line_cache_p->visible_end_index = 0;
        g_line_cache_p->updating_line_y = 0;
        g_line_cache_p->total_height = 0;

        
        /* prepare all update*/
        b->cache_begin_callback = NULL;
        b->cache_line_ready_callback = gui_mlc_all_line_info_save;
        b->cache_update_type = GUI_INPUT_BOX_CACHE_UPDATE_ALL;
        
        flags = b->flags;
        b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        g_editor_line.line_char = temp_line_char;
        gui_show_multi_line_input_box_basic(b, -1, -1);
        if (!g_line_cache_p->visible_line_ok)
        {
            /* can't parse correctly, set the line counter to 0 */
            g_line_cache_p->visible_line_ok = 1;
            g_line_cache_p->updating_line_index = -1;
            g_line_cache_p->visible_start_index = -1;
            g_line_cache_p->visible_end_index = -1;
        }
        
        b->flags = flags;
        b->cache_line_ready_callback = NULL;        
        g_line_cache_p->flags = b->flags;
        g_line_cache_p->ext_flags = b->ext_flags;
    }

    EDITOR_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  gui_mlc_partial_line_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_mlc_partial_line_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    multi_line_input_box *b = g_line_cache_p->b;
    S32 flags;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_line_cache_p->b_create == 1)
    {
        /* the line cache is created, but never updated */
        gui_mlc_all_line_update();
        return;
    }
    
    gui_cancel_timer(gui_mlc_partial_line_update);
    g_line_cache_p->timer_callback = NULL;

    if (g_line_cache_p->b_create <= 0)
    {
        return;
    }
    
    if (g_line_cache_p->updating_line_index == -1)
    {  
        return;
    }
    
    EDITOR_LOCK;
    /* prepare partial update*/
    g_line_cache_p->line_query_begin = g_line_cache_p->updating_line_index;
    g_line_cache_p->line_query_end = g_line_cache_p->updating_line_index + PARTIAL_UPDATE_LINE_MAX;
    g_line_cache_p->total_height = gui_mlc_line_cache_one_line_offset_y(g_line_cache_p->updating_line_index);
    b->cache_begin_callback = gui_mlc_line_context_set;
    b->cache_line_ready_callback = gui_mlc_partial_line_info_save;
    b->cache_update_type = GUI_INPUT_BOX_CACHE_UPDATE_PARTIAL;

    flags = b->flags;
    b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
    g_editor_line.line_char = temp_line_char;
    gui_show_multi_line_input_box_basic(b, -1, -1);
    b->flags = flags;
    b->cache_begin_callback = NULL;
    b->cache_line_ready_callback = NULL;
    
    EDITOR_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  gui_mlc_visible_line_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  y1      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_mlc_visible_line_update(S32 y1, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sl, el, tsl, tel = 0;
    S32 ready_s = -1, ready_e = -1;
    S32 dst = 0, src = 0, count = 0;
    S32 flags;
    multi_line_input_box *b = g_line_cache_p->b;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(g_line_cache_p->updating_line_index == -1 || g_line_cache_p->updating_line_y > (y2 + GUI_INPUT_BOX_ADDITION_AREA)))
        return -1;

    if (y1 != g_line_cache_p->visible_start_y || y2 != g_line_cache_p->visible_end_y
        || (!g_line_cache_p->visible_line_ok))
    {
        EDITOR_LOCK;

        g_line_cache_p->visible_start_y = y1;
        g_line_cache_p->visible_end_y = y2;

        gui_mlc_visible_line_range_set(&sl, &el);

        if(!g_line_cache_p->visible_line_ok)
        {
            /* do nothing */
        }
        else if (sl < 0 || el < 0)
        {
            g_line_cache_p->visible_start_index = -1;
            g_line_cache_p->visible_end_index = -1;
            EDITOR_UNLOCK;
            return 0;
        }
        else if (g_line_cache_p->visible_start_index < 0
            || g_line_cache_p->visible_end_index < 0)
        {
            /* do nothing */
        }
        else if (sl == g_line_cache_p->visible_start_index
            && el == g_line_cache_p->visible_end_index)
        {
            /* no visible line changed */
            EDITOR_UNLOCK;
            return 0;
        }
        else if ((sl >= g_line_cache_p->visible_start_index && sl<= g_line_cache_p->visible_end_index)
            ||(el >= g_line_cache_p->visible_start_index && el<= g_line_cache_p->visible_end_index))
        {
            tsl = (g_line_cache_p->visible_start_index > sl) ? g_line_cache_p->visible_start_index : sl;
            tel = (g_line_cache_p->visible_end_index < el) ? g_line_cache_p->visible_end_index : el;

            /* the range between tsl and tel can be reused */
            count = tel - tsl;
            src = tsl - g_line_cache_p->visible_start_index;
            dst = tsl - sl;

            if (src == dst)
            {
                /* no need to move reused data */
            }
            else
            {
                /* move reused data */
                S32 size;

                size = sizeof(input_box_visible_line_struct) * (count + 1);
                memmove(&g_line_cache_p->visible_line_cache_p[dst], &g_line_cache_p->visible_line_cache_p[src], size);
            }
            ready_s = dst;
            ready_e = dst + count;
        }

        /* prepare partial update*/
        if (ready_s == 0)
        {
            /* the upper visible cache is reused */
            g_line_cache_p->line_query_begin = sl + ready_e - ready_s + 1;
            g_line_cache_p->line_query_end = el;
        }
        else if (ready_s > 0)
        {
            /* the lower visible cache is reused */
            g_line_cache_p->line_query_begin = sl;
            g_line_cache_p->line_query_end = sl + ready_s - 1;
        }
        else
        {
            g_line_cache_p->line_query_begin = sl;
            g_line_cache_p->line_query_end = el;
        }

        g_line_cache_p->visible_start_index = sl;
        g_line_cache_p->visible_end_index = el;
        
        b->cache_begin_callback = gui_mlc_line_context_set;
        b->cache_line_ready_callback = gui_mlc_visible_line_info_save;
        b->cache_update_type = GUI_INPUT_BOX_CACHE_UPDATE_VISIBLE;

        flags = b->flags;
        b->flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_DRAW;
        g_editor_line.line_char = temp_line_char;
        gui_show_multi_line_input_box_basic(b, -1, -1);
        b->flags = flags;
        b->cache_begin_callback = NULL;
        b->cache_line_ready_callback = NULL;
        
        EDITOR_UNLOCK;
        return 1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_mlc_visible_line_shown_request
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_mlc_visible_line_shown_request(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 y1, y2;
    multi_line_input_box *b = g_line_cache_p->b;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (b->text == NULL)
    {
        g_line_cache_p->b_create = ERROR_CACHE_INVALID;
        return -1;
    }
    
    if (g_line_cache_p->b_create == 1)
    {
        /* the line cache is created, but never updated */
        gui_mlc_all_line_update();
        return 1;
    }
    
    gui_get_multi_line_visible_area(b, &y1, &y2);

    return gui_mlc_visible_line_update(y1, y2);
}


#ifdef UI_EMS_SUPPORT
/****************************EMS Cache****************************************/

/*****************************************************************************
 * FUNCTION
 *  gui_emsc_is_dirty
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b            [IN]         
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL gui_emsc_is_dirty(UI_EMS_input_box *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_line_cache_p->b != (void*)b)
        return MMI_TRUE;
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_emsc_is_line_visible
 * DESCRIPTION
 *  
 * PARAMETERS
 *  y1      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_emsc_is_line_visible(S32 y1, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (y1 > g_line_cache_p->visible_end_y + GUI_INPUT_BOX_ADDITION_AREA)
    {
        /* under the visible area */
        return 1;
    }
    else if (y2 < g_line_cache_p->visible_start_y - GUI_INPUT_BOX_ADDITION_AREA)
    {
        /* upper the visible area */
        return -1;
    }
    else
        return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_emsc_visible_line_range_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  y1      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_emsc_visible_line_range_set(S32 *sl, S32 *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, y_start = 0, y_end = 0, in_visible;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *sl = -1;
    *el = -1;
    
    for (i=0; i<g_line_cache_p->all_line_count; i++)
    {
        y_end = y_start + g_line_cache_p->ems_all_line_cache_p[i].line_height;
        in_visible = gui_emsc_is_line_visible(y_start, y_end);
        if (in_visible == 0)
        {
            if (*sl < 0)
                *sl = i;
            
            *el = i;
        }
        else if (in_visible > 0)
        {
            break;
        }
        y_start = y_end;
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  gui_emsc_line_cache_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b               [?]     
 *  line_unit       [?]     
 *  line_cache      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_emsc_line_cache_set(
        UI_EMS_input_box *b,
        ems_input_box_show_struct* bs,
        gui_editor_line_unit_struct *line_unit,
        ems_all_line_struct *line_cache)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    line_cache->current_position = bs->line_start_position;
    line_cache->end_position = bs->line_end_position;
    line_cache->line_height = line_unit->line_height;
    line_cache->line_width = line_unit->line_width;
    line_cache->char_count = line_unit->line_char_count;
    line_cache->line_ascent = line_unit->line_ascent;
    line_cache->line_dscent = line_unit->line_dscent;
}


/*****************************************************************************
 * FUNCTION
 *  gui_emsc_visible_line_cache_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                       [?]     
 *  line_unit               [?]     
 *  visible_line_cache      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void gui_emsc_visible_line_cache_set(
        UI_EMS_input_box *b,
        gui_editor_line_unit_struct *line_unit,
        input_box_visible_line_struct *visible_line_cache)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    visible_line_cache->highlight_flag = line_unit->highlight_flag;
    visible_line_cache->line_char_count = line_unit->line_char_count;
    visible_line_cache->line_unit_count = line_unit->line_unit_count;
    visible_line_cache->override_flag = line_unit->override_flag;
    memcpy(
        visible_line_cache->line_char,
        line_unit->line_char,
        sizeof(gui_editor_character_unit_struct) * (line_unit->line_unit_count));
}



/*****************************************************************************
 * FUNCTION
 *  gui_emsc_line_info_get
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
ems_all_line_struct *gui_emsc_line_info_get(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ASSERT(g_line_cache_p->updating_line_index < 0 || idx < g_line_cache_p->updating_line_index);*/

    if (g_line_cache_p->updating_line_index >= 0
        && idx >= g_line_cache_p->updating_line_index)
    {
        return NULL;
    }

    return &(g_line_cache_p->ems_all_line_cache_p[idx]);
}


/*****************************************************************************
 * FUNCTION
 *  gui_emsc_visible_info_get
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
input_box_visible_line_struct *gui_emsc_visible_info_get(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_line_cache_p->updating_line_index < 0 || idx < g_line_cache_p->updating_line_index);
    ASSERT(idx >= g_line_cache_p->visible_start_index);

    return &(g_line_cache_p->visible_line_cache_p[idx - g_line_cache_p->visible_start_index]);
}

/*****************************************************************************
 * FUNCTION
 *  gui_emsc_visible_start_line_get
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_s       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_emsc_visible_start_line_get(ems_line_index_struct *idx_s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx_s->index = g_line_cache_p->visible_start_index;
    if (idx_s->index < 0)
    {
        idx_s->current_position = g_line_cache_p->ems_all_line_cache_p[g_line_cache_p->all_line_count-1].current_position;
        idx_s->end_position = g_line_cache_p->ems_all_line_cache_p[g_line_cache_p->all_line_count-1].end_position;
        idx_s->offset_y = gui_emsc_line_cache_one_line_offset_y(g_line_cache_p->all_line_count-1);
    }
    else
    {
        idx_s->current_position = g_line_cache_p->ems_all_line_cache_p[idx_s->index].current_position;
        idx_s->end_position = g_line_cache_p->ems_all_line_cache_p[idx_s->index].end_position;
        idx_s->offset_y = gui_emsc_line_cache_one_line_offset_y(idx_s->index);
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_emsc_visible_end_line_get
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx_e       [?]     
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_emsc_visible_end_line_get(ems_line_index_struct *idx_e)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    idx_e->index = g_line_cache_p->visible_end_index;
    if (idx_e->index < 0)
    {
        idx_e->current_position = g_line_cache_p->ems_all_line_cache_p[g_line_cache_p->all_line_count-1].current_position;
        idx_e->end_position = g_line_cache_p->ems_all_line_cache_p[g_line_cache_p->all_line_count-1].end_position;
        idx_e->offset_y = gui_emsc_line_cache_one_line_offset_y(g_line_cache_p->all_line_count-1);
    }
    else
    {
        idx_e->current_position = g_line_cache_p->ems_all_line_cache_p[idx_e->index].current_position;
        idx_e->end_position = g_line_cache_p->ems_all_line_cache_p[idx_e->index].end_position;
        idx_e->offset_y = gui_emsc_line_cache_one_line_offset_y(idx_e->index);
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_emsc_total_line_height
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_emsc_total_line_height(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_line_cache_p->total_height;
}

/*****************************************************************************
 * FUNCTION
 *  gui_emsc_total_line_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_emsc_total_line_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_line_cache_p->all_line_count;
}


/*****************************************************************************
 * FUNCTION
 *  gui_emsc_all_line_info_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 gui_emsc_all_line_info_save(UI_EMS_input_box* b, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 in_visible, cur_line_index, new_size;
    ems_input_box_show_struct *bs = param;
    ems_all_line_struct *current_line_cache_p;
    static S32 visible_write = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_line_index = bs->n_lines;
    if (bs->n_lines == 0)
        visible_write = 0;

    if (cur_line_index >= g_line_cache_p->all_line_max_count)
    {
        new_size = gui_inputs_cache_all_line_realloc();
        if (new_size == 0)
            return 0;
    }
        
    current_line_cache_p = &g_line_cache_p->ems_all_line_cache_p[cur_line_index];

    /* save this line to cache */
    gui_emsc_line_cache_set(b, bs, &g_editor_line, current_line_cache_p);

    /* if it's visible, save it to the visible line */
    in_visible = gui_emsc_is_line_visible(g_line_cache_p->total_height, g_line_cache_p->total_height + current_line_cache_p->line_height);
    if (in_visible < 0)
    {
        g_line_cache_p->visible_start_index = cur_line_index + 1;
    }
    else if (in_visible == 0)
    {
        gui_emsc_visible_line_cache_set(b, &g_editor_line, 
            &g_line_cache_p->visible_line_cache_p[visible_write++]);
        g_line_cache_p->visible_end_index = cur_line_index;
    }

    g_line_cache_p->total_height += current_line_cache_p->line_height;

    if (bs->end_line)
    {
        /* the last line */
        g_line_cache_p->visible_line_ok = 1;
        g_line_cache_p->all_line_count = cur_line_index + 1;
        g_line_cache_p->updating_line_index = -1;
    }

    return 1;
    
}

/*****************************************************************************
 * FUNCTION
 *  gui_emsc_all_line_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_emsc_all_line_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_EMS_input_box *b = g_line_cache_p->b;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    EDITOR_LOCK;
    
    if (g_line_cache_p->b_create > 0)
    {
        g_line_cache_p->b_create++;

        /* get visible area */
        gui_get_ems_visible_area(b, &(g_line_cache_p->visible_start_y), &(g_line_cache_p->visible_end_y));
        g_line_cache_p->visible_start_index = 0;
        g_line_cache_p->visible_end_index = 0;
        g_line_cache_p->updating_line_y = 0;
        g_line_cache_p->total_height = 0;

        
        /* prepare all update*/
        b->cache_begin_callback = NULL;
        b->cache_line_ready_callback = gui_emsc_all_line_info_save;
        b->cache_update_type = GUI_INPUT_BOX_CACHE_UPDATE_ALL;
        
        b->flags |= UI_EMS_INPUT_BOX_DISABLE_DRAW;
        g_editor_line.line_char = temp_line_char;
        gui_show_EMS_input_box_basic(b, -1, -1);
        b->flags &= ~UI_EMS_INPUT_BOX_DISABLE_DRAW;
        b->cache_line_ready_callback = NULL;
    }

    EDITOR_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  gui_emsc_text_format_apply
 * DESCRIPTION
 *  
 * PARAMETERS
 *  b                       [?]     
 *  bs                      [?]     
 *  index                   [?]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_emsc_text_format_apply(UI_EMS_input_box *b, ems_input_box_show_struct *bs, S32 index)
{
    EMSObject *o;
#ifdef __MMI_MESSAGES_EMS__
    EMSObject *o_end;
#endif

    if (index == 0)
        o = gui_ems_get_current_text_format_for_position(b->data, &g_line_cache_p->ems_all_line_cache_p[index].current_position);
    else
        o = gui_ems_get_current_text_format_for_position(b->data, &g_line_cache_p->ems_all_line_cache_p[index - 1].end_position);

#ifdef __MMI_MESSAGES_EMS__   
    /* Get the aligment object of the end of the current line */
    o_end = gui_ems_get_current_text_format_for_position_ex(b->data, &g_line_cache_p->ems_all_line_cache_p[index].end_position);
#endif

    if (o == NULL)
    {
        bs->text_format_count = bs->previous_text_format_count = 0;
        o = &UI_EMS_normal_text_format_object;
    }
    else
    {
        bs->text_format_count = o->OffsetToText + o->data->text_format.textLength 
                                - g_line_cache_p->ems_all_line_cache_p[index].current_position.OffsetToText;
        bs->previous_text_format_count = bs->text_format_count >>= 1;
    }

    bs->line_end_text_format = o;
    
#ifdef __MMI_MESSAGES_EMS__
    gui_EMS_input_box_set_text_format(b, o);

    /* If there are more than one alignment object in a line, apply the last alignment object */
    if ((g_line_cache_p->ems_all_line_cache_p[index].end_position.OffsetToText != 
         g_line_cache_p->ems_all_line_cache_p[index].current_position.OffsetToText) ||
        (g_line_cache_p->ems_all_line_cache_p[index].end_position.Object != 
         g_line_cache_p->ems_all_line_cache_p[index].current_position.Object))
    {
        if (o_end != NULL)
        {
            UI_EMS_current_alignment = o_end->data->text_format.Alignment;
        }
    }
#endif

}


/*****************************************************************************
 * FUNCTION
 *  gui_emsc_line_cache_one_line_offset_y
 * DESCRIPTION
 *  
 * PARAMETERS
 *  idx     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_emsc_line_cache_one_line_offset_y(S32 idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_line_cache_p->updating_line_index < 0 || idx <= g_line_cache_p->updating_line_index);

    for (i = 0; i < idx; i++)
    {
        y += g_line_cache_p->ems_all_line_cache_p[i].line_height;
    }

    return y;

}


S32 gui_emsc_line_context_set(UI_EMS_input_box* b, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ems_input_box_show_struct *bs = param;
    ems_all_line_struct *ems_all_line_start_p; 
    S32 y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (g_line_cache_p->line_query_begin == 0)
        return 0;
    
    ems_all_line_start_p = &g_line_cache_p->ems_all_line_cache_p[g_line_cache_p->line_query_begin-1];
    
    y = gui_emsc_line_cache_one_line_offset_y(g_line_cache_p->line_query_begin);
    bs->ty += y;

    g_editor_line.line_height = ems_all_line_start_p->line_height;
    gui_emsc_text_format_apply(b, bs, g_line_cache_p->line_query_begin);
    bs->current_position = ems_all_line_start_p->end_position;

    bs->n_lines= g_line_cache_p->line_query_begin;
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_emsc_visible_line_info_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 gui_emsc_visible_line_info_save(UI_EMS_input_box* b, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cur_line_index;
    ems_input_box_show_struct *bs = param;
    input_box_visible_line_struct *current_visible_line_cache_p = g_line_cache_p->visible_line_cache_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_line_index = bs->n_lines;
    
    current_visible_line_cache_p = &g_line_cache_p->visible_line_cache_p[cur_line_index - g_line_cache_p->visible_start_index]; 
    
    gui_emsc_visible_line_cache_set(b, &g_editor_line, current_visible_line_cache_p);

    if (cur_line_index >= g_line_cache_p->line_query_end)
    {
        g_line_cache_p->visible_line_ok = 1;
        return 0;
    }

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  gui_emsc_partial_line_info_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 gui_emsc_partial_line_info_save(UI_EMS_input_box* b, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 in_visible, cur_line_index, new_size;
    ems_input_box_show_struct *bs = param;
    ems_all_line_struct *current_line_cache_p;
    input_box_visible_line_struct *current_visible_line_cache_p = g_line_cache_p->visible_line_cache_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur_line_index = bs->n_lines;

    if (cur_line_index >= g_line_cache_p->all_line_max_count)
    {
        new_size = gui_inputs_cache_all_line_realloc();
        if (new_size == 0)
            return 0;
    }
    
    current_line_cache_p = &g_line_cache_p->ems_all_line_cache_p[cur_line_index];
    
    /* save this line to cache */
    gui_emsc_line_cache_set(b, bs, &g_editor_line, current_line_cache_p);

    gui_set_ems_line_information(b, bs);
    
    /* if it's visible, save it to the visible line */
    in_visible = gui_emsc_is_line_visible(g_line_cache_p->total_height, g_line_cache_p->total_height + current_line_cache_p->line_height);
    if (in_visible < 0)
    {
        g_line_cache_p->visible_start_index = -1;
        g_line_cache_p->visible_line_ok = 0;
    }
    else if (in_visible == 0)
    {
        if (g_line_cache_p->visible_line_ok)
        {
            /* visible info last time */
            if (cur_line_index <= g_line_cache_p->visible_end_index 
                && cur_line_index >= g_line_cache_p->visible_start_index)
            {
                g_line_cache_p->visible_line_ok = 0;
            }
        }
        else
        {
            if (g_line_cache_p->visible_start_index == -1)
                g_line_cache_p->visible_start_index = cur_line_index;
            current_visible_line_cache_p = &g_line_cache_p->visible_line_cache_p[cur_line_index - g_line_cache_p->visible_start_index];

            gui_emsc_visible_line_cache_set(b, &g_editor_line, current_visible_line_cache_p);
            g_line_cache_p->visible_end_index = cur_line_index;
        }
    }
    else if (in_visible > 0)
    {
        g_line_cache_p->visible_line_ok = 1;
    }

    g_line_cache_p->updating_line_index++;
    g_line_cache_p->total_height += current_line_cache_p->line_height;
    g_line_cache_p->updating_line_y = g_line_cache_p->total_height;
    if (bs->end_line)
    {
        g_line_cache_p->all_line_count = g_line_cache_p->updating_line_index;
        b->n_lines = g_line_cache_p->all_line_count;
        g_line_cache_p->updating_line_index = -1;
        g_line_cache_p->visible_line_ok = 1;

        if (g_line_cache_p->visible_start_index == -1)
        {
            g_line_cache_p->visible_start_index = -1;
            g_line_cache_p->visible_end_index = -1;
        }
        return 0;
    }

    if (g_line_cache_p->updating_line_index >= g_line_cache_p->line_query_end)
    {
        if (g_line_cache_p->timer_callback == NULL)
        {
            gui_start_timer(PARTIAL_UPDATE_TIMER, gui_emsc_partial_line_update);
            g_line_cache_p->timer_callback = (void*)gui_emsc_partial_line_update;
        }
        
        return 0;
    }
        
    return 1;        
}


/*****************************************************************************
 * FUNCTION
 *  gui_emsc_visible_line_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  y1      [IN]        
 *  y2      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_emsc_visible_line_update(S32 y1, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 sl, el, tsl, tel = 0;
    S32 ready_s = -1, ready_e = -1;
    S32 dst = 0, src = 0, count = 0;
	UI_EMS_input_box *b = g_line_cache_p->b;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_line_cache_p->b_create <= 0)
    {
        return 0 ;
    }
        
    if (!(g_line_cache_p->updating_line_index == -1 || g_line_cache_p->updating_line_y > (y2 + GUI_INPUT_BOX_ADDITION_AREA)))
    {
        return -1;
    }
    
    if (y1 != g_line_cache_p->visible_start_y || y2 != g_line_cache_p->visible_end_y
        || (!g_line_cache_p->visible_line_ok))
    {
        EDITOR_LOCK;

        g_line_cache_p->visible_start_y = y1;
        g_line_cache_p->visible_end_y = y2;

        gui_emsc_visible_line_range_set(&sl, &el);

        if(!g_line_cache_p->visible_line_ok)
        {
            /* do nothing */
        }
        else if (sl < 0 || el < 0)
        {
            g_line_cache_p->visible_start_index = -1;
            g_line_cache_p->visible_end_index = -1;
            EDITOR_UNLOCK;
            return 0;
        }
        else if (g_line_cache_p->visible_start_index < 0
            || g_line_cache_p->visible_end_index < 0)
        {
            /* do nothing */
        }
        else if (sl == g_line_cache_p->visible_start_index
            && el == g_line_cache_p->visible_end_index)
        {
            /* no visible line changed */
            EDITOR_UNLOCK;
            return 0;
        }
        else if ((sl >= g_line_cache_p->visible_start_index && sl<= g_line_cache_p->visible_end_index)
            ||(el >= g_line_cache_p->visible_start_index && el<= g_line_cache_p->visible_end_index))
        {
            tsl = (g_line_cache_p->visible_start_index > sl) ? g_line_cache_p->visible_start_index : sl;
            tel = (g_line_cache_p->visible_end_index < el) ? g_line_cache_p->visible_end_index : el;

            /* the range between tsl and tel can be reused */
            count = tel - tsl;
            src = tsl - g_line_cache_p->visible_start_index;
            dst = tsl - sl;

            if (src == dst)
            {
                /* no need to move reused data */
            }
            else
            {
                /* move reused data */
                S32 size;

                size = sizeof(input_box_visible_line_struct) * (count + 1);
                memmove(&g_line_cache_p->visible_line_cache_p[dst], &g_line_cache_p->visible_line_cache_p[src], size);
            }
            ready_s = dst;
            ready_e = dst + count;
        }

        /* prepare partial update*/
        if (ready_s == 0)
        {
            /* the upper visible cache is reused */
            g_line_cache_p->line_query_begin = sl + ready_e - ready_s + 1;
            g_line_cache_p->line_query_end = el;
        }
        else if (ready_s > 0)
        {
            /* the lower visible cache is reused */
            g_line_cache_p->line_query_begin = sl;
            g_line_cache_p->line_query_end = sl + ready_s - 1;
        }
        else
        {
            g_line_cache_p->line_query_begin = sl;
            g_line_cache_p->line_query_end = el;
        }

        g_line_cache_p->visible_start_index = sl;
        g_line_cache_p->visible_end_index = el;
        
        b->cache_begin_callback = gui_emsc_line_context_set;
        b->cache_line_ready_callback = gui_emsc_visible_line_info_save;
        b->cache_update_type = GUI_INPUT_BOX_CACHE_UPDATE_VISIBLE;

        b->flags |= UI_EMS_INPUT_BOX_DISABLE_DRAW;
        g_editor_line.line_char = temp_line_char;
        gui_show_EMS_input_box_basic(b, -1, -1);
        b->flags &= ~UI_EMS_INPUT_BOX_DISABLE_DRAW;
        b->cache_begin_callback = NULL;
        b->cache_line_ready_callback = NULL;
        
        EDITOR_UNLOCK;
        return 1;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  gui_emsc_partial_line_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_emsc_partial_line_update(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_EMS_input_box *b = g_line_cache_p->b;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_line_cache_p->b_create == 1)
    {
        /* the line cache is created, but never updated */
        gui_emsc_all_line_update();
        return;
    }

    gui_cancel_timer(gui_emsc_partial_line_update);
    g_line_cache_p->timer_callback = NULL;
    
    if (g_line_cache_p->b_create <= 0)
    {
        return;
    }
    
    if (g_line_cache_p->updating_line_index == -1)
    {
        return;
    }

    EDITOR_LOCK;
    /* prepare partial update*/
    g_line_cache_p->line_query_begin = g_line_cache_p->updating_line_index;
    g_line_cache_p->line_query_end = g_line_cache_p->updating_line_index + PARTIAL_UPDATE_LINE_MAX;
    g_line_cache_p->total_height = gui_emsc_line_cache_one_line_offset_y(g_line_cache_p->updating_line_index);
    b->cache_begin_callback = gui_emsc_line_context_set;
    b->cache_line_ready_callback = gui_emsc_partial_line_info_save;
    b->cache_update_type = GUI_INPUT_BOX_CACHE_UPDATE_PARTIAL;

    b->flags |= UI_EMS_INPUT_BOX_DISABLE_DRAW;
    g_editor_line.line_char = temp_line_char;
    gui_show_EMS_input_box_basic(b, -1, -1);
    b->flags &= ~UI_EMS_INPUT_BOX_DISABLE_DRAW;
    b->cache_begin_callback = NULL;
    b->cache_line_ready_callback = NULL;
    
    EDITOR_UNLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  gui_emsc_character_line_index_find
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_emsc_character_line_index_find(EMSPosition pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j, r = 0;
    EMSObject *o = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    j = (g_line_cache_p->updating_line_index < 0) ? (g_line_cache_p->all_line_count) : g_line_cache_p->updating_line_index;
    for (i = 0; i < j; i++)
    {
        r = g_line_cache_p->ems_all_line_cache_p[i].end_position.OffsetToText;
        o = g_line_cache_p->ems_all_line_cache_p[i].end_position.Object;
        if (o != NULL)
        {
            if (pos.OffsetToText <= o->OffsetToText)
                return i;
        }

        if (pos.OffsetToText <= r)
            return i;
        else if(i == j - 1)
        {
            if (pos.OffsetToText <= r + ENCODING_LENGTH)
            return i;
        }
    }

    return 0;    
}


/*****************************************************************************
 * FUNCTION
 *  gui_emsc_visible_line_shown_request
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
S32 gui_emsc_visible_line_shown_request(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 y1, y2;
    UI_EMS_input_box *b = g_line_cache_p->b;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_line_cache_p->b_create == 1)
    {
        /* the line cache is created, but never updated */
        gui_emsc_all_line_update();
        return 1;
    }
    
    gui_get_ems_visible_area(b, &y1, &y2);

    return gui_emsc_visible_line_update(y1, y2);
}


/*****************************************************************************
* FUNCTION
*  gui_emsc_change_request
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
S32 gui_emsc_change_request(EMSPosition pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n;
    EMSPosition updated_position;
    UI_EMS_input_box *b = g_line_cache_p->b;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_line_cache_p->b_create <= 0 || g_line_cache_p->b != (void*)&MMI_EMS_inputbox)
    {
        return 0;
    }

    EDITOR_LOCK;

    if (g_line_cache_p->updating_line_index > 0)
    {
        /* the update process is running */
        n = g_line_cache_p->updating_line_index - 1;
        updated_position = g_line_cache_p->ems_all_line_cache_p[n].end_position;
        if (updated_position.OffsetToText < pos.OffsetToText)
        {
            /* the change data is not updated , just waiting for partial update*/
            EDITOR_UNLOCK;
            return 0;
        }
    }
    else if (g_line_cache_p->updating_line_index == 0)
    {
        /* all data is not updated, just waiting for partial update */
        EDITOR_UNLOCK;
        return 0;
    }
    else
    {
        b->last_display_height = gui_emsc_total_line_height();
    }
    
    n = gui_emsc_character_line_index_find(pos);
    
    /* we update line from the index before PARTIAL_UPDATE_PREVIOUS_LINE*/
    n -= PARTIAL_UPDATE_PREVIOUS_LINE;
    if (n < 0)
        n = 0;
    
    g_line_cache_p->updating_line_index = n;
    g_line_cache_p->updating_line_y = gui_emsc_line_cache_one_line_offset_y(g_line_cache_p->updating_line_index);
    g_line_cache_p->visible_line_ok = 0;
    
    if (g_line_cache_p->timer_callback == NULL)
    {
        gui_start_timer(PARTIAL_UPDATE_TIMER, gui_emsc_partial_line_update);
        g_line_cache_p->timer_callback = (void*)gui_emsc_partial_line_update;
    }
    
    EDITOR_UNLOCK;
    return 1;
    
}
#endif /* UI_EMS_SUPPORT */


/*****************************************************************************
* FUNCTION
*  gui_inputs_cache_init_mutex
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
void gui_inputs_cache_init_mutex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_mutex_init(&g_cache_mutext);
}

/*****************************************************************************
* FUNCTION
*  gui_inputs_cache_lock_mutex
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
void gui_inputs_cache_lock_mutex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_mutex_lock(&g_cache_mutext);
}

/*****************************************************************************
* FUNCTION
*  gui_inputs_cache_unlock_mutex
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  
*****************************************************************************/
void gui_inputs_cache_unlock_mutex(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_mutex_unlock(&g_cache_mutext);
}

#endif

