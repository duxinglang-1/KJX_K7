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
 *  mslt.c
 *
 * Project:
 * --------
 *  PlutoMMI
 *
 * Description:
 * ------------
 *  MoDIS String Length Tool, MoDIS only.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#if defined(__MSLT__)
#ifndef __MTK_TARGET__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mslt.h"
#include "mslt_table.h"

#include "mmi_include.h"
#include "Wgui_tab_bars.h"
#include "wgui_icon_bar.h"
//RHR
#include "wgui_title.h"
#ifdef __PLUTO_MMI_PACKAGE__
#include "mmi_rp_app_phonesetting_new_def.h"
#endif
#include "Gui_tab_bars.h"
#include "wgui_fixed_menus.h"
#include "wgui_categories_util.h"

#include "mmi_rp_app_uiframework_def.h"
#include "mmi_rp_srv_status_icons_def.h"

#include "SettingResDef.h"
#include "FileMgrResDef.h"
#include "gui_font_size.h"
#include "wgui_virtual_keyboard.h"
#include "wgui_categories.h"
#include "resource_mediaplayer_skins.h"
#include "SettingResDef.h"
#ifndef __COSMOS_MMI__
#include "mmi_rp_app_calibration_def.h"
#ifdef __MMI_CAMCORDER__
#include "mmi_features_camcorder.h"
#include "CamcorderResDef.h"
#endif
#else

#define IMG_SCR_SETTING_CAPTION 0
#define IMG_ID_FMGR_DRIVE_SPACE_0 0
#define IMG_ID_FMGR_DRIVE_SPACE_0 0
#define IMG_ID_CAMCO_MENULIST_TITLE 0
#define IMG_ID_CAMCO_MENUITEM_BG_1 0
#define IMG_ID_CAMCO_RADIO_EMPTY 0
#define IMG_ID_CAMCO_REF_STATUS_ICON_SIZE 0
#define IMG_ID_CAMCO_MENUITEM_BG_1 0
#define IMG_CALIBRATION_TOP_LEFT 0
#endif
#if defined(__MMI_MOTIONGAME_DJ__)
#include "MotionDJGprots.h"
#endif
#if defined(__MMI_SOUND_RECORDER__) && defined(__MMI_SNDREC_SKIN__) && defined(__PLUTO_MMI_PACKAGE__)
#include "mdi_datatype.h"
#include "SndrecGProt.h"
#endif
#if defined(__MMI_PHOTOEDITOR__) && defined(__PHOEDT_FEATURE_PHOART__)
#include "PhotoEditorGProt.h"
#endif

#ifdef __MMI_BARCODEREADER__
#include "mmi_features_barcodereader.h"
#include "resource_barcodereader_skins.h"
#endif

#ifdef __MMI_BCR__
#include "MMI_features_BCR.h"
#include "BCRResDef.h"
#include "gdi_include.h"
#include "resource_bcr_skins.h"
/*we add this for I do not want to include others in the gui_inputs_internal.h which contains this function*/
extern S32 gui_inputs_get_char_info_for_all_lang(U8 size, S32 *ascent_p, S32 *dscent_p);
#endif

#ifdef __MMI_LANGLN_LK__
#include "langlnResDef.h"
#include "gdi_include.h"
#endif

#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
#include "HomeScreenOp11V32Gprot.h"
#endif

/***************************************************************************** 
 * Global Variables
 *****************************************************************************/
static mmi_mslt_font_struct g_mmi_mslt_font_table[MMI_MSLT_REGION_ID_NUM] = {0};
static mmi_mslt_editor_struct g_mmi_mslt_editor_table[MMI_MSLT_REGION_ID_NUM] = {0};
static S32 g_mmi_mslt_width_table[MMI_MSLT_REGION_ID_NUM] = {0};
static mmi_mslt_editor_struct g_mmi_mslt_editor_info = {0};


/***************************************************************************** 
 * Global Function: for MoDIS UI usage
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_check_string
 * DESCRIPTION
 *  check the string length for a specific string with regions, for MoDIS UI usage only
 * PARAMETERS
 *  string_id           [IN]    string ID enum value
 *  string              [IN]    string content, UCS2 encoding, null terminated
 *  number_of_regions   [IN]    number of region IDs
 *  region_ids          [IN]    array of region IDs
 *  display_string      [OUT]   display-able sub-string, the buffer size is the same as the "string"
 * RETURNS
 *  >= 0 : display successfully, < 0 : display failed
 *****************************************************************************/
void mmi_mslt_check_string(
        int number_of_strings,      /* in */
        int string_ids[],           /* in */
        char *strings[],            /* in */
        int number_of_regions[],    /* in */
        int *region_ids[],          /* in */
        int ret[],                  /* out */
        char *display_string[])     /* out */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* init */
    memset(ret, 0, number_of_strings*sizeof(int));
    for (i = 0 ; i < MMI_MSLT_REGION_ID_NUM ; i ++)
    {
        memset(&g_mmi_mslt_font_table[i].trunc_symbol, 0, (MAX_TRUNC_SYMBOL_LEN + 1)*ENCODING_LENGTH*sizeof(U8));
        mmi_ucs2ncpy(g_mmi_mslt_font_table[i].trunc_symbol, (PS8)L"..", MAX_TRUNC_SYMBOL_LEN);
        g_mmi_mslt_font_table[i].type = &MMI_medium_font;
        g_mmi_mslt_font_table[i].is_bordered = MMI_FALSE;
        g_mmi_mslt_width_table[i] = MMI_MSLT_STR_UNLIM;

        if (g_mmi_mslt_query_func_ptrs[i].func != NULL)
        {
            memset(&g_mmi_mslt_editor_info, 0, sizeof(mmi_mslt_editor_struct));
            g_mmi_mslt_width_table[i] = g_mmi_mslt_query_func_ptrs[i].func(i, &g_mmi_mslt_font_table[i]);
            if (g_mmi_mslt_width_table[i] == MMI_MSLT_STR_IN_EDITOR)
            {
                memcpy(&g_mmi_mslt_editor_table[i], &g_mmi_mslt_editor_info, sizeof(mmi_mslt_editor_struct));
            }
        }
    }

    /* dump region id information to mmi_region.txt */
    {
        FILE *fp = NULL;

        fp = fopen("mmi_region.txt", "w");
        if (fp != NULL)
        {
            fprintf(fp, "%s\t%s\n", "region ID", "width (in pixel)");
            for (i = 0 ; i < MMI_MSLT_REGION_ID_NUM ; i ++)
            {
                switch(g_mmi_mslt_width_table[i])
                {
                    case MMI_MSLT_STR_UNLIM:
                        fprintf(fp, "%s\tUnlimited\n", g_mmi_mslt_query_func_ptrs[i].name);
                        break;

                    case MMI_MSLT_STR_IN_EDITOR:
                        fprintf(fp, "%s\t%dx%d\n", g_mmi_mslt_query_func_ptrs[i].name, g_mmi_mslt_editor_table[i].w, g_mmi_mslt_editor_table[i].h);
                        break;

                    default:
                        fprintf(fp, "%s\t%d\n", g_mmi_mslt_query_func_ptrs[i].name, g_mmi_mslt_width_table[i]);
                        break;
                }
            }
            fclose(fp);
        }
    }

    /* check each string */
    for (i = 0 ; i < number_of_strings ; i ++)
    {
        S32 j, str_len = mmi_ucs2strlen((S8*)strings[i]), min_str_len = -1;

        /* check each region */
        for (j = 0 ; j < number_of_regions[i] ; j++)
        {
            S32 width = MMI_MSLT_STR_UNLIM, str_width = MMI_MSLT_STR_UNLIM, id = (S32)region_ids[i][j], w, h;
            mmi_mslt_font_struct *font;

            /* init */
            width = g_mmi_mslt_width_table[id];
            font = &g_mmi_mslt_font_table[id];

            if (width > 0)
            {
                width -= (width && font->is_bordered) ? (4) : (0);

                if (font->type != NULL)
                {
                    gui_set_font(font->type);
                    str_width = gui_get_string_width((UI_string_type)strings[i]);
                }

                if (width < str_width)
                {
                    S32 len = 0;

                    width -= gui_get_string_width((UI_string_type)g_mmi_mslt_font_table[id].trunc_symbol);
                    width = (width < 0) ? (0) : (width);

                    len = Get_StringWidthHeight_variant((PU8)strings[i], 0, str_len, &w, &h, width, 0, 0);

                    if ((min_str_len == -1) || (len < min_str_len))
                    {
                        min_str_len = len;
                        memset(display_string[i], 0, (str_len + 1)*sizeof(UI_character_type));
                        mmi_ucs2ncpy((S8*)display_string[i], (S8*)strings[i], len);
                        mmi_ucs2cat((S8*)display_string[i], (S8*)g_mmi_mslt_font_table[id].trunc_symbol);
                    }
                }
                ret[i] = str_width * 100 / width;
            }
            else if (width == MMI_MSLT_STR_IN_EDITOR)
            {
                S32 l = gui_strlen((UI_string_type)strings[i]);

                create_multiline_inputbox_set_buffer((UI_string_type)strings[i], l, l, 0);
                MMI_multiline_inputbox.flags |= g_mmi_mslt_editor_table[id].flags;
                MMI_multiline_inputbox.ext_flags |= g_mmi_mslt_editor_table[id].ext_flags;
                resize_multiline_inputbox_fit(g_mmi_mslt_editor_table[id].w, g_mmi_mslt_editor_table[id].h, &w, &h);
                if (g_mmi_mslt_editor_table[id].h < h)
                {
                    resize_multiline_inputbox(g_mmi_mslt_editor_table[id].w, g_mmi_mslt_editor_table[id].h);
                    min_str_len = 0;
                    memset(display_string[i], 0, (str_len + 1)*sizeof(UI_character_type));
                    mmi_ucs2ncpy((S8*)display_string[i], (S8*)strings[i], (MMI_multiline_inputbox.visible_end - 1));
                    mmi_ucs2cat((S8*)display_string[i], (S8*)g_mmi_mslt_font_table[id].trunc_symbol);
                }
                ret[i] = h * 100 / g_mmi_mslt_editor_table[id].h;
            }
        }
    }
}


/***************************************************************************** 
 * Global Function: for query functions
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_set_editor_info
 * DESCRIPTION
 *  set editor related information for string check
 * PARAMETERS
 *  info    [IN]    editor information
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mslt_set_editor_info(mmi_mslt_editor_struct info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&g_mmi_mslt_editor_info, &info, sizeof(mmi_mslt_editor_struct));
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_test1_query_function
 * DESCRIPTION
 *  string length query function for test 1 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_dummy_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0   /* following is an example of MSLT query function */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_lsk_query_function
 * DESCRIPTION
 *  string length query function for LSK region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for LSK
 *****************************************************************************/
S32 mmi_mslt_lsk_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_LSK)
    {
        width = MMI_SOFTKEY_WIDTH - MMI_UI_SOFTKEY_GAP;
        font->type = (UI_font_type)gui_font_get_type(GUI_FONT_SIZE_BUTTON);
        font->is_bordered = MMI_TRUE;
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_rsk_query_function
 * DESCRIPTION
 *  string length query function for RSK region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for RSK
 *****************************************************************************/
S32 mmi_mslt_rsk_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_RSK)
    {
        width = MMI_SOFTKEY_WIDTH - MMI_UI_SOFTKEY_GAP;
        font->type = (UI_font_type)gui_font_get_type(GUI_FONT_SIZE_BUTTON);
        font->is_bordered = MMI_TRUE;
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_csk_query_function
 * DESCRIPTION
 *  string length query function for CSK region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for CSK
 *****************************************************************************/
S32 mmi_mslt_csk_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_CSK)
    {
        width = MMI_CENTER_SOFTKEY_WIDTH;
        font->type = (UI_font_type)gui_font_get_type(GUI_FONT_SIZE_BUTTON);
        font->is_bordered = MMI_TRUE;        
    }
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_icon_bar_hint_query_function
 * DESCRIPTION
 *  string length query function for icon bar hint
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for RSK
 *****************************************************************************/
S32 mmi_mslt_icon_bar_hint_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_UI_ICON_BAR__)
    if (id == MMI_MSLT_REGION_ICON_BAR_HINT)
    {
        width = GUI_ICON_BAR_HINT_WIDTH - 2 * GUI_ICON_BAR_HINT_GAP;
        font->type = (UI_font_type)gui_font_get_type(GUI_FONT_SIZE_ICONBAR_HINT);
        font->is_bordered = MMI_FALSE;
    }
#endif /* __MMI_UI_ICON_BAR__ */
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_idle_day_query_function
 * DESCRIPTION
 *  string length query function for day string on techno bar
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for RSK
 *****************************************************************************/
S32 mmi_mslt_idle_day_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    S32 x1 = 0, x2 = 0, x3 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
    if (id == MMI_MSLT_REGION_IDLE_DAY)
    {
        x3 = MAIN_LCD_DEVICE_WIDTH - MMI_SIGNAL_WIDTH;
        x1 = ANALOG_BACKGROUND_X + ANALOG_BACKGROUND_WIDTH + 1;
        x2 = DIGITAL_BACKGROUND_X + DIGITAL_BACKGROUND_WIDTH + 1;
        if (x2 > x1)
        {
            width = x3 - x2 + 1;
        }
        else
        {
            width = x3 - x1 + 1;
        }
        font->type = (UI_font_type)gui_font_get_type(GUI_FONT_SIZE_DAY);
        font->is_bordered = MMI_TRUE;
    }
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_title_query_function
 * DESCRIPTION
 *  string length query function for title region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_title_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    S32 w1, h1, w2, h2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_TITLE)
    {
        font->type = g_wgui_title_bar.normal_font;
        font->is_bordered = MMI_TRUE;

        g_wgui_title_bar.icon = (PU8)GetImage(IMG_SCR_SETTING_CAPTION);
        g_wgui_title_bar.icon2 = (PU8)GetImage(IMG_SCR_SETTING_CAPTION);

        gui_title_measure_area1(&g_wgui_title_bar, &w1, &h1);
        gui_title_measure_area2(&g_wgui_title_bar, &w2, &h2);
        
        width = MMI_TITLE_WIDTH - w1 - w2 - GUI_TITLE_TEXT_GAP * 2;
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_tab_query_function
 * DESCRIPTION
 *  string length query function for tab region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_tab_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_TAB)
    {
        font->type = current_horizontal_tab_bar_theme->tab_text_font;
        width = MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH;
    }

    return width;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_get_mainmenu_info
 * DESCRIPTION
 *  string length query function for test 1 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_get_mainmenu_info(S32 id, mmi_mslt_font_struct* font)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(id)
    {
    case MMI_MSLT_REGION_MATRIX:
        width = UI_device_width;        
        font->type = (UI_font_type)gui_font_get_type(GUI_FONT_SIZE_MATRIX);
        break;
        
    case MMI_MSLT_REGION_LISTMAIN:
        width = UI_device_width - GUI_ICONTEXT_MENUITEM_TEXT_X - GUI_MENUITEM_TEXT_RIGHT_GAP - UI_SCROLLBAR_WIDTH -
            GUI_MENUITEM_X2_GAP;
        font->type = (UI_font_type)gui_font_get_type(GUI_FONT_SIZE_MATRIX);
        break;
        
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
    case MMI_MSLT_REGION_BDTITLE:
        width = UI_device_width - MMI_BI_DEGREE_MAIN_MENU_LIST_WIDTH;
        font->type = (UI_font_type)gui_font_get_type(GUI_FONT_SIZE_MATRIX);
        break;
        
    case MMI_MSLT_REGION_BDITEM:
        width = ((UI_device_width - MMI_BI_DEGREE_MAIN_MENU_LIST_WIDTH) / MMI_BI_DEGREE_MAIN_MENU_COLUMN_COUNT) -
            MMI_BI_DEGREE_MAIN_MENU_GAP  - UI_SCROLLBAR_WIDTH;
        font->type = (UI_font_type)gui_font_get_type(GUI_FONT_SIZE_MATRIX);
        break;
#endif
        
    case MMI_MSLT_REGION_PAGEITEM:
        width = MAIN_LCD_DEVICE_WIDTH - MAIN_MENU_CONTROL_AREA_X_GAP * 2;
        font->type = &MMI_large_font;  
        break;

    default:
        break;
    }
    return width;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_get_mainmenu_info
 * DESCRIPTION
 *  string length query function for test 1 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_get_list_info(S32 id, mmi_mslt_font_struct* font)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM, arrow_width, arrow_height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(id)
    {
    case MMI_MSLT_REGION_TEXT:
        width = UI_device_width - GUI_TEXT_MENUITEM_TEXT_X - GUI_MENUITEM_TEXT_RIGHT_GAP - UI_SCROLLBAR_WIDTH -
            GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP;
        break;
        
    case MMI_MSLT_REGION_ICONTEXT:
        width = UI_device_width - GUI_ICONTEXT_MENUITEM_TEXT_X - GUI_MENUITEM_TEXT_RIGHT_GAP - UI_SCROLLBAR_WIDTH -
            GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP;
        break;
        
    case MMI_MSLT_REGION_TWOSTATE:
        width = UI_device_width - GUI_ICONTEXT_MENUITEM_TEXT_X - GUI_MENUITEM_TEXT_RIGHT_GAP - UI_SCROLLBAR_WIDTH -
            GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP;
        break;
        
    case MMI_MSLT_REGION_TWOLINE:
        gui_measure_image((PU8)get_image(LEFT_RED_ARROW), &arrow_width, &arrow_height);
        width = UI_device_width - GUI_ICONTEXT_MENUITEM_TEXT_X - GUI_MENUITEM_TEXT_RIGHT_GAP - UI_SCROLLBAR_WIDTH -
            GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - arrow_width * 2 - MMI_MENUITEM_HEIGHT;
        break;
        
    case MMI_MSLT_REGION_STEXT:
        width = MMI_SMALL_LIST_SCREEN_WIDTH - GUI_TEXT_MENUITEM_TEXT_X - GUI_MENUITEM_TEXT_RIGHT_GAP - UI_SCROLLBAR_WIDTH -
            GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP;
        break;
        
    case MMI_MSLT_REGION_SICONTEXT:
        width = MMI_SMALL_LIST_SCREEN_WIDTH - GUI_ICONTEXT_MENUITEM_TEXT_X - GUI_MENUITEM_TEXT_RIGHT_GAP - UI_SCROLLBAR_WIDTH -
            GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP;
        break;
        
    case MMI_MSLT_REGION_STWOSTATE:
        width = MMI_SMALL_LIST_SCREEN_WIDTH - GUI_ICONTEXT_MENUITEM_TEXT_X - GUI_MENUITEM_TEXT_RIGHT_GAP - UI_SCROLLBAR_WIDTH -
            GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP;
        break;

	case MMI_MSLT_REGION_HINT:
        width = UI_device_width - GUI_ICONTEXT_MENUITEM_TEXT_X - GUI_MENUITEM_TEXT_RIGHT_GAP - UI_SCROLLBAR_WIDTH -
            GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP;
        break;

    case MMI_MSLT_REGION_CASCADE:
        width = UI_device_width - CASCADING_MENU_FIRST_LEVEL_X_OFFSET - CASCADING_MENU_BORDER_SIZE * 2 - 
            CASCADING_MENU_SHADOW_DEPTH - GUI_MENUITEM_TEXT_RIGHT_GAP - UI_SCROLLBAR_WIDTH -
            GUI_MENUITEM_X2_GAP - GUI_MENUITEM_X1_GAP;
        break;
    }
    font->type = (UI_font_type)gui_font_get_type(GUI_FONT_SIZE_LIST);
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c230_query_function
 * DESCRIPTION
 *  string length query function for C230_1 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c230_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
#if defined ( __MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__)
    S32 w,h;
#endif /* defined ( __MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__) */


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C230_1)
    {
#if defined ( __MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__)
#ifdef __MMI_SLIM_IMG_RES__
	    gui_measure_image(get_image(LEFT_RED_ARROW), &w, &h);
#else
        gui_measure_image(get_image(LEFT_ARROW_DOWN), &w, &h);
#endif
        width = UI_device_width - CAT230_ARROW_OFFSET * 2 - w * 2;
#endif /* defined ( __MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_320X240__) || defined (__MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__) */
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c017_query_function
 * DESCRIPTION
 *  string length query function for C017 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c017_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C017_1)
    {
#if defined(__MMI_MAINLCD_320X480__)
        width = 260 /* WGUI_CAT016_CONTENT_W */;
#else /* defined(__MMI_MAINLCD_320X480__) */
        width = UI_device_width - 2;
#endif /* defined(__MMI_MAINLCD_320X480__) */
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c018_query_function
 * DESCRIPTION
 *  string length query function for C018 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c018_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C018_1)
    {
        width = mmi_mslt_c017_query_function(MMI_MSLT_REGION_C017_1, font);
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c019_query_function
 * DESCRIPTION
 *  string length query function for C019 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c019_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C019_1)
    {
        width = UI_device_width - GUI_ICONTEXT_MENUITEM_TEXT_X - MMI_MENUITEM_HEIGHT - 2;
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c403_query_function
 * DESCRIPTION
 *  string length query function for C403 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c403_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C403_1)
    {
        width = mmi_mslt_get_list_info(MMI_MSLT_REGION_ICONTEXT, font);
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c129_query_function
 * DESCRIPTION
 *  string length query function for C129 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c129_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C129_1)
    {
        width = MMI_COMMON_TITLE_WIDTH - (MMI_TITLEBAR_BUTTON_GAP << 1) - (MMI_TITLEBAR_BUTTON_WIDTH << 1);
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c222_query_function
 * DESCRIPTION
 *  string length query function for C222 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c222_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C222_1)
    {
        width = mmi_mslt_lsk_query_function(MMI_MSLT_REGION_LSK, font);
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c426_query_function
 * DESCRIPTION
 *  string length query function for C426 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c426_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_MAINLCD_128X128__)
    if ((id == MMI_MSLT_REGION_C426_1) ||
        (id == MMI_MSLT_REGION_C426_2))
    {
        font->type = (id == MMI_MSLT_REGION_C426_1) ? (&MMI_medium_font) : (&MMI_small_font);
        width = LCD_WIDTH - UI_SCROLLBAR_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - (WGUI_CAT426_IMAGE_X + WGUI_CAT426_IMAGE_WIDTH + WGUI_CAT426_IMAGE_TEXT_GAP) - WGUI_CAT426_TEXT_SCROLLBAR_GAP;
    }
#endif /* !defined(__MMI_MAINLCD_128X128__) */

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c061_query_function
 * DESCRIPTION
 *  string length query function for C061 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c061_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    mmi_mslt_editor_struct info = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C061_1)
    {
        info.w = CAT61_INFO_W;
        info.h = CAT61_INFO_H;
        info.flags = UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
                        UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR |
                        UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;
        info.ext_flags = GUI_MULTI_LINE_INPUT_BOX_USE_BORDER_FONT;

        mmi_mslt_set_editor_info(info);

        width = MMI_MSLT_STR_IN_EDITOR;
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c088_query_function
 * DESCRIPTION
 *  string length query function for C088 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c088_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C088_1)
    {
        S32 img_w = 0, img_h = 0;

#ifdef __MMI_FTE_SUPPORT__
        gdi_image_get_dimension(current_MMI_theme->slide_bar_background_image, &img_w, &img_h);
#else
        gdi_image_get_dimension_id(WGUI_SLIDE_CONTROL_BG_IMAGE_ID, &img_w, &img_h);
#endif

        width = img_w;
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c090_query_function
 * DESCRIPTION
 *  string length query function for C090_1 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c090_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((id == MMI_MSLT_REGION_C090_1) ||
        (id == MMI_MSLT_REGION_C090_2) ||
        (id == MMI_MSLT_REGION_C090_3))
    {    
        font->type = &MMI_default_font;

        switch(id)
        {
            case MMI_MSLT_REGION_C090_1:
                width = UI_device_width - 8;
                break;

            case MMI_MSLT_REGION_C090_2:
            case MMI_MSLT_REGION_C090_3:
                width = (UI_device_width >> 1) - 4;
                break;

            default:
                break;
        }
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c120_query_function
 * DESCRIPTION
 *  string length query function for C120 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c120_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    mmi_mslt_editor_struct info = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C120_1)
    {
        info.w = MAIN_LCD_DEVICE_WIDTH - (MMI_IDLE_STRING_MARGIN_GAP << 1);
        info.h = MMI_SINGLELINE_INPUTBOX_HEIGHT + 3;
        info.flags = UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
                        UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR;
        info.ext_flags = GUI_MULTI_LINE_INPUT_BOX_TRUNCATE_CONTENT;

        mmi_mslt_set_editor_info(info);

        width = MMI_MSLT_STR_IN_EDITOR;
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c205_query_function
 * DESCRIPTION
 *  string length query function for C205 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c205_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    mmi_mslt_editor_struct info = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C205_1)
    {
        info.w = MAIN_LCD_DEVICE_WIDTH;
        info.h = MAIN_LCD_DEVICE_HEIGHT >> 1;
        info.flags = UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
                        UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR;
        info.ext_flags = 0;

        mmi_mslt_set_editor_info(info);

        width = MMI_MSLT_STR_IN_EDITOR;
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c620_query_function
 * DESCRIPTION
 *  string length query function for C620 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c620_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C620_1)
    {
        width = MMI_COMMON_CONTENT_WIDTH;
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c420_query_function
 * DESCRIPTION
 *  string length query function for C420 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c420_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    S32 iw, ih;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((id == MMI_MSLT_REGION_C420_1) ||
        (id == MMI_MSLT_REGION_C420_2) ||
        (id == MMI_MSLT_REGION_C420_3))
    {
        gdi_image_get_dimension_id(IMG_GLOBAL_L1, &iw, &ih);

        switch(id)
        {
            case MMI_MSLT_REGION_C420_1:
                width = UI_device_width - (CAT420_LINE_EXTRA_PIXEL << 1);
                break;

#if defined(CAT420_DISP_INFO_TEXT)
            case MMI_MSLT_REGION_C420_2:
#endif /* defined(CAT420_DISP_INFO_TEXT) */
            case MMI_MSLT_REGION_C420_3:
                width = UI_device_width - current_MMI_theme->scrollbar_size - CAT420_LEFT_MARGIN - CAT420_RIGHT_MARGIN - CAT420_IMAGE_AREA_MIN_WIDTH;
                width -= (id == MMI_MSLT_REGION_C420_2) ? (CAT420_CAPTION_IMAGE_H_SPACING + iw) : (0);
                break;

            default:
                break;
        }
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c425_query_function
 * DESCRIPTION
 *  string length query function for C425 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c425_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(id)
    {
        case MMI_MSLT_REGION_C425_1:
        case MMI_MSLT_REGION_C425_2:
            width = UI_device_width - current_MMI_theme->scrollbar_size - CAT425_ICON_X - CAT425_DEFAULT_ICON_WIDTH - CAT425_ICON_TEXT_GAP - CAT425_TEXT_SCROLLBAR_GAP;
            width -= (id == MMI_MSLT_REGION_C425_2) ? ((gui_get_string_width((UI_string_type)L"[") + CAT425_TEXT2_BRACKET_GAP) << 1) : (0);
            break;

        default:
            break;
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c430_query_function
 * DESCRIPTION
 *  string length query function for C430 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c430_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C430_1)
    {
#if !defined(CAT430_NAME_IN_LOG)
        width = UI_device_width - (CAT430_HORIZONTAL_GAP << 1);
#endif /* !defined(CAT430_NAME_IN_LOG) */
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c433_query_function
 * DESCRIPTION
 *  string length query function for C433 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c433_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_OP11_CAT433_SUPPORT__)
    if (id == MMI_MSLT_REGION_C433_1)
    {
        width = WGUI_CAT433_STRING_MAX_OPNAME_W;
        font->is_bordered = MMI_TRUE;
    }
#endif /* defined(__MMI_OP11_CAT433_SUPPORT__) */

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c435_query_function
 * DESCRIPTION
 *  string length query function for C435 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c435_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C435_1)
    {
        width = mmi_mslt_title_query_function(MMI_MSLT_REGION_TITLE, font);
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c057_query_function
 * DESCRIPTION
 *  string length query function for c057 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c057_query_function(S32 id, mmi_mslt_font_struct* font)
{

#ifdef __MMI_MSLT_SCROLLING_WARNING__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    S32 left_image_width = 0;
	S32 right_image_width = 0;
	S32 height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_measure_image((U8*) GetImage(IMG_H_SELECT_LEFT), &left_image_width, &height);
	gui_measure_image((U8*) GetImage(IMG_H_SELECT_RIGHT), &right_image_width, &height);

    if (id == MMI_MSLT_REGION_C057_1)
    {
        width = UI_device_width - UI_SCROLLBAR_WIDTH - GUI_ICONTEXT_MENUITEM_TEXT_X - right_image_width - 4 - left_image_width - 4;
    }
    return width;    
#else
    return MMI_MSLT_STR_UNLIM;
#endif /* __MMI_MSLT_SCROLLING_WARNING__ */

}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c069_query_function
 * DESCRIPTION
 *  string length query function for C069_1 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c069_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    mmi_mslt_editor_struct info = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C069_1)
    {   
        width = MMI_MSLT_STR_IN_EDITOR;
        
        info.w = MMI_COMMON_CONTENT_WIDTH - (CAT69_MARGIN << 1);
        info.h = CAT69_ALIGNED_AREA_H;
        info.flags = (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | 
                      UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY |
                      UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND | 
                      UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR);
        info.ext_flags = 0;

        mmi_mslt_set_editor_info(info);        
    }
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c111_query_function
 * DESCRIPTION
 *  string length query function for C111_1 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c111_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    mmi_mslt_editor_struct info = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C111_1)
    {           
        width = MMI_MSLT_STR_IN_EDITOR;

        info.w = MMI_COMMON_CONTENT_WIDTH - (CAT111_MARGIN << 1);
#ifdef __MMI_TOUCH_SCREEN__
    #ifdef __MMI_MAINLCD_320X240__        
        info.h = (MMI_MENUITEM_HEIGHT) + 6;
    #else
        info.h = (MMI_MENUITEM_HEIGHT << 1) + 6;
    #endif
#else  /* __MMI_TOUCH_SCREEN__ */  
        info.h = MMI_COMMON_CONTENT_HEIGHT - (MMI_MENUITEM_HEIGHT << 1) - (MMI_TITLE_HEIGHT >> 1) - MMI_MENUITEM_HEIGHT;
#endif /* __MMI_TOUCH_SCREEN__ */

        info.flags = (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | 
                      UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND |
                      UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR | 
                      UI_MULTI_LINE_INPUT_BOX_VIEW_MODE);
        info.ext_flags = GUI_MULTI_LINE_INPUT_BOX_TRUNCATE_CONTENT;

        mmi_mslt_set_editor_info(info);
    }
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c112_query_function
 * DESCRIPTION
 *  string length query function for C112_1 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c112_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    mmi_mslt_editor_struct info = {0};
    S32 content_w = 0, vk_h = 0, aligned_area_h = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C112_1)
    {           
        width = MMI_MSLT_STR_IN_EDITOR;
        
        content_w = MMI_POP_UP_DIALOG_WIDTH - MMI_POP_UP_CONTENT_MARGIN_X*2;

#if defined (__MMI_MAINLCD_320X480__)
#if defined(__MMI_VIRTUAL_KEYBOARD__)
        vk_h = 38;
#elif defined(__MMI_TOUCH_SCREEN__)    
        vk_h = 0;
#endif    
#endif
    
#if defined (__MMI_VIRTUAL_KEYBOARD__) && (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_320X240__))
        aligned_area_h = MMI_POP_UP_DIALOG_HEIGHT - MMI_POP_UP_CONTENT_MARGIN_Y*2 - MMI_SINGLELINE_INPUTBOX_HEIGHT - MMI_VKBD_TRAY_HEIGHT - 5;
#elif defined (__MMI_TOUCH_SCREEN__) && (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_320X240__))
        aligned_area_h = MMI_POP_UP_DIALOG_HEIGHT - MMI_POP_UP_CONTENT_MARGIN_Y*2 - MMI_SINGLELINE_INPUTBOX_HEIGHT - 5;
#elif defined (__MMI_TOUCH_SCREEN__) && defined (__MMI_MAINLCD_320X480__)
        aligned_area_h = MMI_POP_UP_DIALOG_HEIGHT - MMI_POP_UP_CONTENT_MARGIN_Y - MMI_BUTTON_BAR_HEIGHT - vk_h - 5 - MMI_SINGLELINE_INPUTBOX_HEIGHT - 5;
#else
        aligned_area_h = MMI_POP_UP_DIALOG_HEIGHT - MMI_POP_UP_CONTENT_MARGIN_Y*2 - MMI_SINGLELINE_INPUTBOX_HEIGHT;
#endif /* defined (__MMI_TOUCH_SCREEN__) && (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_320X240__)) */        
        
        info.w = content_w;
        info.h = aligned_area_h - MMI_MENUITEM_HEIGHT;
        info.flags = (UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW | 
                      UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND | 
                      UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR | 
                      UI_MULTI_LINE_INPUT_BOX_VIEW_MODE);
        info.ext_flags = 0;

        mmi_mslt_set_editor_info(info);
    }
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c033_1_query_function
 * DESCRIPTION
 *  string length query function for c033_1 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c033_1_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    S32 img_width = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM_MASTER__
    {
        S32 h;
        gui_measure_image(get_image(WGUI_IMG_IDLE_SIM1), &img_width, &h);
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    if (id == MMI_MSLT_REGION_C033_1)
    {
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__    
        width = UI_device_width - MMI_SIGNAL_WIDTH - DIGITAL_BACKGROUND_X - DIGITAL_BACKGROUND_WIDTH - img_width + 1;
#else
        width = UI_device_width - (MMI_IDLE_STRING_MARGIN_GAP * 2) - img_width;
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */
    }

    font->type = gui_font_get_type(GUI_FONT_SIZE_IDLE_NETWORK_NAME);
    font->is_bordered = MMI_TRUE;
  
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c033_2_query_function
 * DESCRIPTION
 *  string length query function for c033_1 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c033_2_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C033_2)
    {
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__    
        width = UI_device_width - MMI_SIGNAL_WIDTH - DIGITAL_BACKGROUND_X - DIGITAL_BACKGROUND_WIDTH + 1;
#else
        width = UI_device_width - (MMI_IDLE_STRING_MARGIN_GAP * 2);
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */
    }

    font->type = gui_font_get_type(GUI_FONT_SIZE_IDLE_NETWORK_STATUS);
    font->is_bordered = MMI_TRUE;
  
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c280_query_function
 * DESCRIPTION
 *  string length query function for c280_1 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c280_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
	static stFontAttribute mslt_c280_font = {1,1,0,MEDIUM_FONT,0,1};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C280_1)
    {
        width = MMI_content_width - current_MMI_theme->scrollbar_size - (CAT280_HMARGIN << 1);
    }

    font->type = &mslt_c280_font;
    font->is_bordered = MMI_FALSE;
  
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_button_title_query_function
 * DESCRIPTION
 *  string length query function for button title region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_button_title_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM, image_width, image_height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(id)
    {
    case MMI_MSLT_REGION_C130_1:
    case MMI_MSLT_REGION_C229_1:
        #if  !(defined(__MMI_FWUI_SLIM__)&& defined(__MMI_FTE_SUPPORT__)) 
        gui_measure_image((PU8)get_image(IMAGE_VIEW_TITLEBAR_BG), &image_width, &image_height);
        width = image_width - 2*2/* border of image */; 
        #endif
        break;
    }        
    font->type = g_wgui_title_bar.normal_font;
    font->is_bordered = MMI_TRUE; 
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c122_query_function
 * DESCRIPTION
 *  string length query function for category122 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c122_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(id)
    {
    case MMI_MSLT_REGION_C122_1:
        width = (UI_device_width >> 1);
        break;
        
    case MMI_MSLT_REGION_C122_2:
        width = (UI_device_width / 7) * 2 + 5;
        break;
        
    case MMI_MSLT_REGION_C122_3:
        width = (UI_device_width / 3);
        break;
    }        
    font->type = &MMI_medium_font;
    font->is_bordered = MMI_TRUE; 
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c402_query_function
 * DESCRIPTION
 *  string length query function for category402 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c402_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(id)
    {
    case MMI_MSLT_REGION_C402_1:
        break;

    case MMI_MSLT_REGION_C402_2:
        width = UI_device_width;
        break;
    }
    font->type = &MMI_medium_font;
    font->is_bordered = MMI_FALSE; 
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c144_query_function
 * DESCRIPTION
 *  string length query function for category144 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c144_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(id)
    {
    case MMI_MSLT_REGION_C144_1:
        break;
    }
    font->type = &MMI_medium_font;
    font->is_bordered = MMI_FALSE; 
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c145_query_function
 * DESCRIPTION
 *  string length query function for category145 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c145_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(id)
    {
    case MMI_MSLT_REGION_C145_1:
        width = UI_device_width;
        break;
    }
    font->type = &MMI_medium_font;
    font->is_bordered = MMI_FALSE; 
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_fmgr_query_function
 * DESCRIPTION
 *  string length query function for category filemanager region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_fmgr_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM, temp_width, temp_height;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(id)
    {
    case MMI_MSLT_REGION_C211_1:
        width = UI_device_width;
        mmi_fe_measure_string_by_char_num((U8*)(L"0123456789"), 4, &temp_width, &temp_height);
        width -= temp_width;
        mmi_fe_measure_string_by_char_num((U8*)(L"KMG"), 1, &temp_width, &temp_height);
        width -= temp_width;
        
        /* cut space and image area */
#if !defined(__MMI_SLIM_FILE_MANAGER__)
        gdi_image_get_dimension_id(IMG_ID_FMGR_DRIVE_SPACE_0, &temp_width, &temp_height);
        width -= (temp_width - 2);
#else
        width -= (2 * MMI_ICONTEXT_MENUITEM_HEIGHT - 1 + 2 * FMGR_UI_IMAGE_BOX_SPACING); 
#endif
        break;

    case MMI_MSLT_REGION_C213_1:
#if !defined(__MMI_SLIM_FILE_MANAGER__)
        gdi_image_get_dimension_id(IMG_ID_FMGR_DRIVE_SPACE_0, &temp_width, &temp_height);
        width = UI_device_width - UI_SCROLLBAR_WIDTH - temp_width - 2;
#else
        width = UI_device_width - UI_SCROLLBAR_WIDTH - (2 * MMI_ICONTEXT_MENUITEM_HEIGHT - 1 + 2 * FMGR_UI_IMAGE_BOX_SPACING);
#endif
        break;
    }
    font->type = &MMI_medium_font;
    font->is_bordered = MMI_FALSE; 
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c211_2_asm_query_function
 * DESCRIPTION
 *  string length query function for category 211 asm prompt region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c211_2_asm_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C211_2)
    {
        width = UI_device_width - MMI_FRM_APPMEM_PROMPT_INFO_START_PIXEL_OFFSET;
    }
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_medply_lsk_query_function
 * DESCRIPTION
 *  string length query function for media Player LSK region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for LSK
 *****************************************************************************/
S32 mmi_mslt_medply_lsk_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined (__MMI_FTE_SUPPORT__) && !defined (__MMI_MEDIA_PLAYER_FTE__)
    if (id == MMI_MSLT_REGION_MEDPLY_LSK)
    {
#if defined(MMI_MEDPLY_COMP_SOFTKEY_USE_SKIN_REGN)
        width = g_medply_skin.soft_lkey_rgn_w;
#else
        width = MMI_SOFTKEY_WIDTH - MMI_UI_SOFTKEY_GAP;
#endif
        mmi_ucs2ncpy(font->trunc_symbol, (PS8)L"..", MAX_TRUNC_SYMBOL_LEN);
        font->type = gui_font_get_type(GUI_FONT_SIZE_BUTTON);
        font->is_bordered = MMI_TRUE;
    }
#endif /* __MMI_MEDIA_PLAYER_FTE__ */
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_medply_rsk_query_function
 * DESCRIPTION
 *  string length query function for RSK region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for RSK
 *****************************************************************************/
S32 mmi_mslt_medply_rsk_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined (__MMI_FTE_SUPPORT__) && !defined (__MMI_MEDIA_PLAYER_FTE__)
    if (id == MMI_MSLT_REGION_MEDPLY_RSK)
    {
#if defined(MMI_MEDPLY_COMP_SOFTKEY_USE_SKIN_REGN)
        width = g_medply_skin.soft_rkey_rgn_w;
#else
        width = MMI_SOFTKEY_WIDTH - MMI_UI_SOFTKEY_GAP;
#endif
        mmi_ucs2ncpy(font->trunc_symbol, (PS8)L"..", MAX_TRUNC_SYMBOL_LEN);
        font->type = gui_font_get_type(GUI_FONT_SIZE_BUTTON);
        font->is_bordered = MMI_TRUE;
    }
#endif /* __MMI_MEDIA_PLAYER_FTE__ */
    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_popup_query_function
 * DESCRIPTION
 *  string length query function for popup region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_popup_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    mmi_mslt_editor_struct info = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_POPUP)
    {
        info.w = MMI_pop_up_dialog_width - 2*UI_POPUP_BORDER_SIZE;
        info.h = 2*MMI_MENUITEM_HEIGHT;
        info.flags = UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
                        UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR |
                        UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;
        info.ext_flags = GUI_MULTI_LINE_INPUT_BOX_TRUNCATE_CONTENT;

        mmi_mslt_set_editor_info(info);

        width = MMI_MSLT_STR_IN_EDITOR;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_popupconfirm_query_function
 * DESCRIPTION
 *  string length query function for popup region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_popupconfirm_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    mmi_mslt_editor_struct info = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_POPUPCONFIRM)
    {
        info.w = MMI_pop_up_dialog_width - 2*UI_POPUP_BORDER_SIZE;
        info.h = 2*MMI_MENUITEM_HEIGHT;
        info.flags = UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
                        UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR |
                        UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;
        info.ext_flags = GUI_MULTI_LINE_INPUT_BOX_TRUNCATE_CONTENT;

        mmi_mslt_set_editor_info(info);

        width = MMI_MSLT_STR_IN_EDITOR;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c009_query_function
 * DESCRIPTION
 *  string length query function for popup region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c009_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    mmi_mslt_editor_struct info = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C009_1)
    {
        info.w = UI_device_width;
        info.h = MMI_MENUITEM_HEIGHT;
        info.flags = UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
                        UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR;
        info.ext_flags = 0;

        mmi_mslt_set_editor_info(info);

        width = MMI_MSLT_STR_IN_EDITOR;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c032_query_function
 * DESCRIPTION
 *  string length query function for popup region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c032_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    mmi_mslt_editor_struct info = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C032_1)
    {
        info.w = UI_device_width;
        info.h = (MMI_MENUITEM_HEIGHT << 1) + 6;
        info.flags = UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
                        UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;
        info.ext_flags = 0;

        mmi_mslt_set_editor_info(info);

        width = MMI_MSLT_STR_IN_EDITOR;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c073_query_function
 * DESCRIPTION
 *  string length query function for popup region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c073_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    S32 iw = 0, ih = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C073_1)
    {
        gdi_image_get_dimension_id(IMG_GLOBAL_L1, &iw, &ih);
        width = UI_device_width - MMI_fixed_list_menu.vbar.width  - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP - 2*iw - 2;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c085_query_function
 * DESCRIPTION
 *  string length query function for popup region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c085_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    S32 iw = 0, ih = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C085_1)
    {
        gdi_image_get_dimension_id(IMG_GLOBAL_L1, &iw, &ih);
        width = UI_device_width - MMI_fixed_list_menu.vbar.width - iw - CAT85_MENUITEM_OFFSET*3 - 3;
        font->type = &MMI_small_font;
    }
    else if (id == MMI_MSLT_REGION_C085_2)
    {
        gdi_image_get_dimension_id(IMG_GLOBAL_L1, &iw, &ih);
        width = UI_device_width - MMI_fixed_list_menu.vbar.width - iw - CAT85_MENUITEM_OFFSET*3 - 3;
        font->type = &MMI_medium_font;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c089_query_function
 * DESCRIPTION
 *  string length query function for popup region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c089_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    U16 temp[] = L"0123456789.";
    S32 w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C089_1)
    {
        gui_set_font(&MMI_medium_font);
        mmi_fe_measure_string_by_char_num((U8*)temp, 3 /* 00. */, &w, &h);
        width = UI_device_width - MMI_fixed_list_menu.vbar.width - w - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - GUI_MENUITEM_TEXT_RIGHT_GAP;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c125_query_function
 * DESCRIPTION
 *  string length query function for popup region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c125_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    U16 temp[] = L"0123456789.";
   // S32 w, h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((id == MMI_MSLT_REGION_C125_1) || (id == MMI_MSLT_REGION_C125_2))
    {
        width = (UI_device_width - MMI_fixed_list_menu.vbar.width)>>1;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c150_query_function
 * DESCRIPTION
 *  string length query function for popup region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c150_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C150_1)
    {
        width = (UI_device_width - MMI_fixed_list_menu.vbar.width - 4)>>1;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c154_query_function
 * DESCRIPTION
 *  string length query function for popup region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c154_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C154_1)
    {
        width = MMI_MSLT_STR_UNLIM;     /* scroll text */
    }
    else if (id == MMI_MSLT_REGION_C154_2)
    {
        width = UI_device_width - 4;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c165_query_function
 * DESCRIPTION
 *  string length query function for popup region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c165_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    mmi_mslt_editor_struct info = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C165_1)
    {
        info.w = MMI_pop_up_dialog_width - 2*UI_POPUP_BORDER_SIZE;
        info.h = MMI_MENUITEM_HEIGHT;
        info.flags = UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
                        UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR |
                        UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;
        info.ext_flags = GUI_MULTI_LINE_INPUT_BOX_TRUNCATE_CONTENT;

        mmi_mslt_set_editor_info(info);

        width = MMI_MSLT_STR_IN_EDITOR;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c261_query_function
 * DESCRIPTION
 *  string length query function for popup region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c261_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    S32 iw = 0, ih = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C261_1)
    {
        gdi_image_get_dimension_id(IMG_GLOBAL_L1, &iw, &ih);
        width = UI_device_width - MMI_fixed_list_menu.vbar.width - iw - 10;
        font->type = &MMI_medium_font;
    }
    else if (id == MMI_MSLT_REGION_C261_2)
    {
        gdi_image_get_dimension_id(IMG_GLOBAL_L1, &iw, &ih);
        width = UI_device_width - MMI_fixed_list_menu.vbar.width - iw - 10;
        font->type = &MMI_small_font;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c264_query_function
 * DESCRIPTION
 *  string length query function for c264 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c264_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    mmi_mslt_editor_struct info = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C264_1)
    {
        info.w = MMI_pop_up_dialog_width - 2*UI_POPUP_BORDER_SIZE;
        info.h = MMI_MENUITEM_HEIGHT;
        info.flags = UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
                        UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR |
                        UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;
        info.ext_flags = GUI_MULTI_LINE_INPUT_BOX_TRUNCATE_CONTENT;

        mmi_mslt_set_editor_info(info);

        width = MMI_MSLT_STR_IN_EDITOR;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c267_query_function
 * DESCRIPTION
 *  string length query function for c267_1 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c267_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C267_1)
    {
        width = UI_device_width - MMI_fixed_list_menu.vbar.width - GUI_ICONTEXT_MENUITEM_TEXT_X/*w*/ - 2 - GUI_MENUITEM_X2_GAP - MMI_ICONTEXT_MENUITEM_HEIGHT - GUI_MENUITEM_TEXT_RIGHT_GAP;
    }
    else if(id == MMI_MSLT_REGION_C267_2)
    {
        width = UI_device_width - 3;
    }
    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c311_query_function
 * DESCRIPTION
 *  string length query function for c311_1 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c311_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C311_1)
    {
        width = UI_device_width - 1;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c312_query_function
 * DESCRIPTION
 *  string length query function for c312_1 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c312_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C312_1)
    {
        width = UI_device_width;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c354_query_function
 * DESCRIPTION
 *  string length query function for c354 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c354_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    S32 iw = 0, ih = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((id == MMI_MSLT_REGION_C354_1) || (id == MMI_MSLT_REGION_C354_2))
    {
        gdi_image_get_dimension_id(IMG_GLOBAL_L1, &iw, &ih);
        width = UI_device_width - MMI_fixed_list_menu.vbar.width - iw - 10;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c384_query_function
 * DESCRIPTION
 *  string length query function for c384 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c384_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C384_1)
    {
        width = UI_device_width - 4;
    }
    else if (id == MMI_MSLT_REGION_C384_2)
    {
        width = UI_device_width - MMI_fixed_list_menu.vbar.width - 2*MMI_ICONTEXT_MENUITEM_HEIGHT - 3;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c428_query_function
 * DESCRIPTION
 *  string length query function for c428_1 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c428_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C428_1)
    {
        width = UI_device_width - 10;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c429_query_function
 * DESCRIPTION
 *  string length query function for c429 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c429_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(id)
        {
            case MMI_MSLT_REGION_C429_1:
            {
                width = UI_device_width>>1;
                break;
            }
            case MMI_MSLT_REGION_C429_2:
            {
                width = UI_device_width>>1;
                break;
            }
            case MMI_MSLT_REGION_C429_3:
            {
                width = UI_device_width>>1;
                break;
            }
            default:
                break;
        }
 
    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_cems_query_function
 * DESCRIPTION
 *  string length query function for c428_1 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_ems_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_CEMS_1)
    {
        width = UI_device_width;
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_get_camcorder_info
 * DESCRIPTION
 *  Get the appropriate width of camcorder items 
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_get_camcorder_info(S32 id, mmi_mslt_font_struct* font)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = -1;
    S32 img_width = 0, img_height = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAMCORDER__

#define MMI_CAMCO_BORDER    (2)

#ifdef HORIZONTAL_CAMERA
    font->type = &MMI_medium_font;
#else
    font->type = &MMI_small_font;
#endif /* HORIZONTAL_CAMERA */
    font->is_bordered = MMI_TRUE;

    if (id == MMI_MSLT_REGION_CAMCO_TITLE)
    {
       gdi_image_get_dimension_id(IMG_ID_CAMCO_MENULIST_TITLE, &img_width, &img_height);
       width = img_width - 2 * MMI_CAMCO_BORDER;
    }
    else if (id == MMI_MSLT_REGION_CAMCO_ITEM)
    {
        S32 radio_width, radio_height, icon_width, icon_height;
		S32 interval;
        
        gdi_image_get_dimension_id(IMG_ID_CAMCO_MENUITEM_BG_1, &img_width, &img_height);
        gdi_image_get_dimension_id(IMG_ID_CAMCO_RADIO_EMPTY, &radio_width, &radio_height);
        gdi_image_get_dimension_id(IMG_ID_CAMCO_REF_STATUS_ICON_SIZE, &icon_width, &icon_height);

		interval = ((img_height - radio_height) >> 1) + ((img_height - icon_height) >> 1);

        width = img_width - radio_width - icon_width - interval - 2 * MMI_CAMCO_BORDER;
    }
    else if (id == MMI_MSLT_REGION_CAMCO_OPTION)
    {
        gdi_image_get_dimension_id(IMG_ID_CAMCO_MENUITEM_BG_1, &img_width, &img_height);
        width = img_width - 2 * MMI_CAMCO_BORDER;
    }
    else if (id == MMI_MSLT_REGION_CAMCO_HINT)
    {
    #ifdef HORIZONTAL_CAMERA
        width = GDI_LCD_HEIGHT - 2 * MMI_CAMCO_BORDER;
    #else
        width = GDI_LCD_WIDTH - 2 * MMI_CAMCO_BORDER;
    #endif
    }
#endif /* __MMI_CAMCORDER__ */    
    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_ime_hint_query_function
 * DESCRIPTION
 *  string length query function for input method hint in information bar
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_ime_hint_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_IME_HINT)
    {
        width = UI_device_width>>1;
        
    #if !defined(__MMI_TOUCH_SCREEN__)
        font->type = &MMI_small_font;
    #else /* !defined(__MMI_TOUCH_SCREEN__) */ 
        font->type = &MMI_medium_font;
    #endif /* !defined(__MMI_TOUCH_SCREEN__) */ 
    
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_ime_cand_query_function
 * DESCRIPTION
 *  string width query function for Input method candidate which can not be cut
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_ime_cand_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_IME_CAND)
    {
        width = mmi_imc_get_max_candidate_width();
        
        font->type = gui_font_get_type(GUI_FONT_SIZE_IME_TEXT);
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_get_djitem_info
 * DESCRIPTION
 *  string length query function for DJITEM region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_get_djitem_info(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_DJITEM)
    {
        mmi_ucs2ncpy(font->trunc_symbol, (S8 *)L"..", MAX_TRUNC_SYMBOL_LEN);
        font->type = &MMI_medium_font;
        font->is_bordered = MMI_FALSE;
    #if defined(__MMI_MOTIONGAME_DJ__)
        width = mmi_motion_dj_get_string_width();
    #else
        width = 80;
    #endif
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_camera_query_function
 * DESCRIPTION
 *  string length query function for camera application region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_camera_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    font->type = &MMI_medium_font;
    font->is_bordered = MMI_FALSE;
    mmi_ucs2ncpy(font->trunc_symbol, (S8 *)L"..", MAX_TRUNC_SYMBOL_LEN);

    if (id == MMI_MSLT_REGION_CAMERA_HINT)
    {
        width = UI_device_width - 70; /* 70 is for icon list */
    }
    else if (id == MMI_MSLT_REGION_CAMERA_TITLE)
    {
        width = UI_device_width;
    }
    else if (id == MMI_MSLT_REGION_CAMERA_SUB_HINT)
    {
#ifdef __MMI_SUBLCD__
        width = SUB_LCD_device_width;
#else
        width = UI_device_width;
#endif /* __MMI_SUBLCD__ */ 
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_get_mtv_info
 * DESCRIPTION
 *  string length query function for mobile tv player
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_get_mtv_info(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_MTV_HINT)
    {
        width = (LCD_WIDTH < LCD_HEIGHT) ? LCD_WIDTH : LCD_HEIGHT;    
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_sndrec_title_query_function
 * DESCRIPTION
 *  string length query function for title region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_sndrec_title_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_SNDREC_TITLE)
    {
#if defined(__MMI_SOUND_RECORDER__) && defined(__MMI_SNDREC_SKIN__) && defined(__PLUTO_MMI_PACKAGE__) 
    width = mmi_sndrec_mslt_skin_title();
    mmi_ucs2ncpy(font->trunc_symbol, (PS8)L"..", MAX_TRUNC_SYMBOL_LEN);
    font->type = gui_font_get_type(GUI_FONT_SIZE_TITLE);
    font->is_bordered = MMI_TRUE;
#endif 
    }
        
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_sndrec_state_query_function
 * DESCRIPTION
 *  string length query function for state region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_sndrec_state_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_SNDREC_STATE)
    {
#if defined(__MMI_SOUND_RECORDER__) && defined(__MMI_SNDREC_SKIN__) && !defined(__MMI_FTE_SUPPORT__) && defined(__PLUTO_MMI_PACKAGE__)
    width = mmi_sndrec_mslt_skin_state();
    mmi_ucs2ncpy(font->trunc_symbol, (PS8)L"..", MAX_TRUNC_SYMBOL_LEN);
    font->type = &MMI_medium_font;
    font->is_bordered = MMI_TRUE;
#endif/*defined(__MMI_SOUND_RECORDER__) && defined(__MMI_SNDREC_SKIN__) && defined(__MMI_FTE_SUPPORT__)*/
    }
              
    return width;

}
/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_sndrec_sk_query_function
 * DESCRIPTION
 *  string length query function for soft key region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_sndrec_sk_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
       
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_SNDREC_SK)
    {
#if defined(__MMI_SOUND_RECORDER__) && defined(__MMI_SNDREC_SKIN__)
    width = UI_DEVICE_WIDTH / 2;
    mmi_ucs2ncpy(font->trunc_symbol, (PS8)L"..", MAX_TRUNC_SYMBOL_LEN);
    font->type = gui_font_get_type(GUI_FONT_SIZE_BUTTON);
    font->is_bordered = MMI_TRUE;
#endif
    }              
    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c409_query_function
 * DESCRIPTION
 *  string length query function for c409_1 and c409_2region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c409_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    mmi_mslt_editor_struct info = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C409_1)
	{
		width = MMI_pop_up_dialog_width - 2*UI_POPUP_BORDER_SIZE;

	}
	else if(id == MMI_MSLT_REGION_C409_2)
    {
        info.w = MMI_pop_up_dialog_width - 2*UI_POPUP_BORDER_SIZE;
        info.h = MMI_MENUITEM_HEIGHT;
        info.flags = UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
                        UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR |
                        UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;
        info.ext_flags = GUI_MULTI_LINE_INPUT_BOX_TRUNCATE_CONTENT;

        mmi_mslt_set_editor_info(info);

        width = MMI_MSLT_STR_IN_EDITOR;
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c407_query_function
 * DESCRIPTION
 *  string length query function for c407_1 and c407_2region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c407_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    S32 iw =0, ih= 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C407_1)
	{
		gdi_image_get_dimension_id(IMG_GLOBAL_L1, &iw, &ih);
		width = UI_device_width - iw - 10;

	}
	else if(id == MMI_MSLT_REGION_C407_2)
    {
        width = UI_device_width;
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c265_query_function
 * DESCRIPTION
 *  string length query function for C265 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c265_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CAT265_SUPPORT__
    switch(id)
    {
        case MMI_MSLT_REGION_C265_1:
            font->type = gui_font_get_type(GUI_FONT_SIZE_TITLE);
            width = CAT265_NAME_WIDTH;
            break;
        case MMI_MSLT_REGION_C265_2:
            font->type = &MMI_medium_font;
            width = CAT265_TEXT_0_WIDTH-(CAT265_TEXT_0_OFFSET*2);
            break;
        case MMI_MSLT_REGION_C265_3:
            font->type = &MMI_medium_font;
            width = UI_device_width - MMI_fixed_list_menu.vbar.width - CAT265_TEXT_0_WIDTH - CAT265_ICON_WIDTH - (CAT265_TEXT_1_OFFSET*2) - 2 /* gap */;
            break;

        default:
            break;
    }

#endif /* __MMI_CAT265_SUPPORT__ */
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_get_vdoedt_info
 * DESCRIPTION
 *  string length query function for video editor
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_get_vdoedt_info(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    switch (id)
    {
        case MMI_MSLT_REGION_VDOEDT_PWIN_TXT:
        	width = 176;
        	break;
        default:
        	break;
    }
   
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_get_vdorec_info
 * DESCRIPTION
 *  string length query function for video editor
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_get_vdorec_info(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (id)
    {
        case MMI_MSLT_REGION_VDOREC_OSD_HINT:
    #if   ((LCD_WIDTH == 128) && (LCD_HEIGHT == 160))
            width = 104;
    #elif ((LCD_WIDTH == 176) && (LCD_HEIGHT == 220))
            width = 110;
    #elif ((LCD_WIDTH == 240) && (LCD_HEIGHT == 320))
            width = 189;
    #elif ((LCD_WIDTH == 320) && (LCD_HEIGHT == 240))
            width = 189;    
    #elif ((LCD_WIDTH == 240) && (LCD_HEIGHT == 400))
            width = 189;
    #elif ((LCD_WIDTH == 320) && (LCD_HEIGHT == 480))
            width = 189;
    #endif
        	break;
        default:
        	break;    	
    }
   
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c072_query_function
 * DESCRIPTION
 *  string length query function for C072 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c072_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MENSTRUAL__)
    if (id == MMI_MSLT_REGION_C072_1)
    {    
        mmi_mslt_editor_struct info = {0};

        info.w = MMI_MULTILINE_INPUTBOX_WIDTH;
        info.h = MMI_MULTILINE_INPUTBOX_HEIGHT - 20 /* image height */ - 5 /* image-text gap */- Get_CharDisplayHeightOfAllLangAndType(MMI_medium_font.size);
        info.flags = UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW |
                        UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND |
                        UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR;

        mmi_mslt_set_editor_info(info);

        width = MMI_MSLT_STR_IN_EDITOR;
    }
#endif /* defined(__MMI_MENSTRUAL__) */

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c113_query_function
 * DESCRIPTION
 *  string length query function for C113 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c113_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((id == MMI_MSLT_REGION_C113_1) ||
        (id == MMI_MSLT_REGION_C113_2) ||
        (id == MMI_MSLT_REGION_C113_3))
    {
        width = MMI_COMMON_CONTENT_WIDTH;
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c412_query_function
 * DESCRIPTION
 *  string length query function for C412 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c412_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(id)
    {
        case MMI_MSLT_REGION_C412_1:
            {
                U16 temp[] = L"0123456789%";
                S32 w, h;

                gui_set_font(&MMI_medium_font);
                mmi_fe_measure_string_by_char_num((U8*)temp, 4 /* 100% */, &w, &h);
                width = MMI_content_width - w - GUI_TEXT_MENUITEM_TEXT_X * 3 /* gap */;
            }
            break;

        case MMI_MSLT_REGION_C412_2:
            width = MMI_COMMON_CONTENT_WIDTH;
            break;

        default:
            break;
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c427_query_function
 * DESCRIPTION
 *  string length query function for C427 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c427_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    S32 text0_width, text1_width, text2_width;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    {
        U16 temp[] = L"0123456789K/%";
        S32 w, h;

        gui_set_font(&MMI_small_font);
        mmi_fe_measure_string_by_char_num((U8*)temp, 4/* text1 can only show 4 characters, eg. 100% */, &w, &h);
        text1_width = w;

        /* text2 can only show 10 characters, eg. 9999/9999K */
        text2_width = LCD_WIDTH - UI_SCROLLBAR_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - text1_width - (GUI_TEXT_MENUITEM_TEXT_X * 3);

        /* may need error control about text width */

        text0_width = LCD_WIDTH - UI_SCROLLBAR_WIDTH - GUI_MENUITEM_X1_GAP - GUI_MENUITEM_X2_GAP - MMI_MENUITEM_HEIGHT /* icon widh */ - (GUI_TEXT_MENUITEM_TEXT_X * 3) /* gap */;
    }

    switch(id)
    {
        case MMI_MSLT_REGION_C427_1:
            width = text0_width;
            break;

        case MMI_MSLT_REGION_C427_2:
            width = text1_width;
            break;

        case MMI_MSLT_REGION_C427_3:
            width = text2_width;
            break;

        default:
            break;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c627_query_function
 * DESCRIPTION
 *  string length query function for category627 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c627_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    S32 iw = 0, ih = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C627_1)
    {
        gdi_image_get_dimension_id(IMG_GLOBAL_L1, &iw, &ih);
        width = UI_device_width - MMI_fixed_list_menu.vbar.width - GUI_ICONTEXT_MENUITEM_ICON_X - GUI_MENUITEM_TEXT_RIGHT_GAP;
        font->type = &MMI_small_font;
    }
    else if (id == MMI_MSLT_REGION_C627_2)
    {
        gdi_image_get_dimension_id(IMG_GLOBAL_L1, &iw, &ih);
        width = UI_device_width - MMI_fixed_list_menu.vbar.width - iw - 2*GUI_ICONTEXT_MENUITEM_ICON_X - GUI_MENUITEM_TEXT_RIGHT_GAP;
        font->type = &MMI_medium_font;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_subicontext_query_function
 * DESCRIPTION
 *  string length query function for SUBICONTEXT region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_subicontext_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_SUBICONTEXT)
    {
        width = UI_device_width - GUI_ICONTEXT_MENUITEM_TEXT_X;
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_get_photo_editor_title
 * DESCRIPTION
 *  string length query function for PHOEDT_TITLE region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_get_photo_editor_title(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_DJITEM)
    {
        mmi_ucs2ncpy(font->trunc_symbol, (S8 *)L"..", MAX_TRUNC_SYMBOL_LEN);
        font->type = &MMI_medium_font;
        font->is_bordered = MMI_TRUE;
        width = UI_device_width;
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_get_photo_editor_spin
 * DESCRIPTION
 *  string length query function for PHOEDT_SPIN region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_get_photo_editor_spin(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_DJITEM)
    {
        mmi_ucs2ncpy(font->trunc_symbol, (S8 *)L"..", MAX_TRUNC_SYMBOL_LEN);
        font->type = &MMI_medium_font;
        font->is_bordered = MMI_TRUE;
    #if defined(__MMI_PHOTOEDITOR__) && defined(__PHOEDT_FEATURE_PHOART__)
        width = mmi_phoedt_get_spin_width();
    #else
        width = 90;
    #endif
    }

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_get_photo_editor_sk
 * DESCRIPTION
 *  string length query function for PHOEDT_SK region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_get_photo_editor_sk(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_DJITEM)
    {
        mmi_ucs2ncpy(font->trunc_symbol, (S8 *)L"..", MAX_TRUNC_SYMBOL_LEN);
        font->type = &MMI_medium_font;
        font->is_bordered = MMI_TRUE;
        width = (UI_device_width - 15) / 2;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_get_calibriation_info
 * DESCRIPTION
 *  string length query function for calibriation region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_get_calibriation_info(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
    mmi_mslt_editor_struct info = {0};
    S32 iw = 0, ih = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_TOUCH_SCREEN__) || defined(__MMI_HANDWRITING_PAD__)
    gdi_image_get_dimension_id(IMG_CALIBRATION_TOP_LEFT, &iw, &ih);
    info.w = UI_device_width - 2;
    info.flags = UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW
        | UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY
        | UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND
        | UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;
    switch(id)
    {
        case MMI_MSLT_REGION_CALIBRIATION_WELCOME_TEXT:
            info.h = UI_device_height - 2*ih;
            break;

        case MMI_MSLT_REGION_CALIBRIATION_TOP_LEFT_TEXT:
            info.h = (UI_device_height - 2*ih)>>1;
            break;

        case MMI_MSLT_REGION_CALIBRIATION_BOTTOM_RIGHT_TEXT:
            info.h = (UI_device_height - 2*ih)>>1;
            break;
            
        case MMI_MSLT_REGION_CALIBRIATION_CENTER_TEXT:
            info.h = (UI_device_height - 2*ih)>>1;
            break;

        case MMI_MSLT_REGION_CALIBRIATION_TEST_WELCOME_TEXT:
            info.h = (UI_device_height - 2*ih)>>1;
            break;
        
        default:
            break;
    }
    mmi_mslt_set_editor_info(info);
    width = MMI_MSLT_STR_IN_EDITOR;
#endif
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_barcodereader_query_function
 * DESCRIPTION
 *  string length query function for calibriation region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_barcodereader_query_function(S32 id, mmi_mslt_font_struct* font)
{
	  /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;
 //  S32 iw = 0, ih = 0;


#ifdef __MMI_BARCODEREADER__

#if defined(__MMI_OP00_BARCODEREADER__) || defined(__MMI_OP11_BARCODEREADER__)
    S32 temp_width, temp_height;
    if (id == MMI_MSLT_REGION_BARCODE_HINT)
    {
        width = g_barcodereader_osd_cntx.hint_box.width;
        mmi_ucs2ncpy(font->trunc_symbol, (PS8)L"..", MAX_TRUNC_SYMBOL_LEN);
        font->type = &MMI_medium_font;
        font->is_bordered = MMI_TRUE;
    }
    else if(id == MMI_MSLT_REGION_BARCODE_HINT_BRACKET)
    {
        gui_set_font(&MMI_medium_font);
        mmi_fe_measure_string_by_char_num((U8*)(L"[]"), 2, &temp_width, &temp_height);
        width = g_barcodereader_osd_cntx.hint_box.width - temp_width; /*should reserve the location of '[', ']'*/
        mmi_ucs2ncpy(font->trunc_symbol, (PS8)L"..", MAX_TRUNC_SYMBOL_LEN);
        font->type = &MMI_medium_font;
        font->is_bordered = MMI_TRUE;
    }
#endif

#endif

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bcr_query_function
 * DESCRIPTION
 *  string length query function for BCR region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_bcr_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = -1;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BCR__
#endif

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_langln_lk_query_function
 * DESCRIPTION
 *  string length query function for langln listening region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_langln_lk_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = -1;
		S32 height = -1;
		
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_LANGLN_LK__
    if (id == MMI_MSLT_REGION_LK_TIPS)
    {
        
        font->type = &MMI_small_font;    
        font->is_bordered = MMI_FALSE;
        
        /*get the capture image width*/
        gdi_image_get_dimension_id(
            (U16)IMG_ID_LANGLN_LK_RECORD_INFO_BG, 
            &width,
            &height);
            
        width = width - 3;
    }
#endif

    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_c126_query_function
 * DESCRIPTION
 *  string length query function for C017 region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_c126_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_C126_1)
    {
        width = UI_device_width - 2;
    }

    return width;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_iconbar_query_function
 * DESCRIPTION
 *  string length query function for icon bar hint region
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for icon bar hint
 *****************************************************************************/
S32 mmi_mslt_iconbar_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id == MMI_MSLT_REGION_ICONBAR)
    {
#ifdef __MMI_FTE_SUPPORT__
        width = WGUI_ICONBAR_ITEM_WIDTH_1 - WGUI_ICONBAR_ITEM_HEIGHT;
        font->type = (UI_font_type)gui_font_get_type(GUI_FONT_SIZE_ICONBAR_ITEM_TEXT);
        font->is_bordered = MMI_TRUE;
#else /* __MMI_FTE_SUPPORT__ */
        width = MAIN_LCD_DEVICE_WIDTH;
        font->type = (UI_font_type)gui_font_get_type(GUI_FONT_SIZE_ICONBAR_HINT);
        font->is_bordered = MMI_FALSE;
#endif /* __MMI_FTE_SUPPORT__ */
    }
    return width;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mslt_op11_hs32_query_function
 * DESCRIPTION
 *  string length query function for OP11 HS31/32
 * PARAMETERS
 *  id          [IN]    region ID
 *  font        [OUT]   font related attributes
 * RETURNS
 *  width in pixel for this region ID
 *****************************************************************************/
S32 mmi_mslt_op11_hs32_query_function(S32 id, mmi_mslt_font_struct* font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width = MMI_MSLT_STR_UNLIM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__)
    switch(id)
    {
        case MMI_MSLT_REGION_HS32_SHCT_LABEL_LARGE:
            #if !defined(__MMI_MAINLCD_128X160__)
                width = MMI_OP11_HS32_SHCT_LABEL_PIXEL;
            #else
                width = MMI_MSLT_STR_UNLIM;
            #endif
            break;

        case MMI_MSLT_REGION_HS32_SHCT_LABEL_SMALL:
            width = MMI_OP11_HS32_SHCT_LABEL_PIXEL;
            break;

        case MMI_MSLT_REGION_HS32_SHCT_CONTENT:
            width = MMI_OP11_HS32_SHCT_CONTENT_PIXEL;
            break;

        default:
            break;
    }
#endif

    font->type = &MMI_medium_font;
    font->is_bordered = MMI_FALSE;
    return width;
}


#else /* __MTK_TARGET__ */

/* avoid the target compilation warning */
void mmi_mslt_dummy(void){}

#endif /* __MTK_TARGET__ */

#else /* defined(__MSLT__) */

/* avoid the target compilation warning */
void mmi_mslt_dummy(void){}

#endif /* defined(__MSLT__) */


