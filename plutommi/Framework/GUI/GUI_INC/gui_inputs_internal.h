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
 *   gui_inputs_internal.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Input box - UI component
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __GUI_INPUTS_INTERNAL_H__
#define __GUI_INPUTS_INTERNAL_H__
#include "MMI_features.h"
#include "LangModuleGProt.h"
#include "BIDIDEF.h"
#include "BIDIProt.h"
//#include "gdi_mutex.h"

#ifdef __MMI_VUI_ENGINE__
#include "gui\vadp_p2v_inputbox.h"
#include "framework\vadp_p2v_uc.h"
#endif

#if defined(__MMI_LANG_HINDI__) || defined(__MMI_LANG_MARATHI__) || defined(__MMI_LANG_BENGALI__) || defined(__MMI_LANG_ASSAMESE__)
#include "IndicRuleEngineCommon.h"
extern indic_rules_ligature_enum indic_rules_current_set_language;
#endif

    #include "gui_inputs.h"
    #include "gui_data_types.h"
    #include "MMIDataType.h"
    #include "gui_config.h"
    #include "PixcomFontEngine.h"
    #include "ems.h"
    #include "gdi_datatype.h"
    #include "lcd_sw_inc.h"
    #include "wgui_inputs.h"
    #include "kal_general_types.h"
    #include "gui_ems.h"

#undef GUI_INPUTBOX_ALIGNMENT_WHEN_EXIST_R2L_CHAR

#define UI_MULTI_LINE_INPUT_BOX_NUMBER_OF_BREAK_CHARACTERS     2        /* 15 */
#define MULTILINE_INPUTBOX_DISPLAY_WHOLE_LINES              1
#define MULTILINE_INPUTBOX_USE_CRLF_COMBINATION             1
/* To use this flag, turn ON EMS_DISPLAY_SPECIAL_CHARACTERS also (outside this file)   */
#define MULTILINE_INPUTBOX_DISPLAY_SPECIAL_CHARACTERS       0
#define MULTILINE_INPUTBOX_USE_GSM_EXTENDED                 1

/* The addition area adjoin to the inputbox visible area */
#define GUI_INPUT_BOX_ADDITION_AREA  30

/* The substitute character for the EMS object */
#define EMS_INPUT_BOX_EMS_OBJECT_REPLACE_CHARACTER 0x0021


/* highlight type */
#define EDITOR_COMMON_HIGHLIGHT              1
#define EDITOR_MULTITAP_HIGHLIGHT            2
#define EDITOR_OVERWRITE_HIGHLIGHT 	         3
#define EDITOR_HILITE_LIST_HIGHLIGHT         4
#define EDITOR_HILITE_LIST_COMMON_HIGHLIGHT  5

#ifdef __MMI_LANG_THAI__
#define isThaiChar(ch)  (((ch >= 0x0E01) && (ch <= 0x0E7F))? (1):(0))
#endif 

#ifdef __MMI_FTE_SUPPORT__
#define GUI_SINGLE_LINE_TOP_DOWN_MARGIN            6
#define GUI_SINGLE_LINE_LEFT_RIGHT_MARGIN          7
#define GUI_MULTI_LINE_TOP_DOWN_MARGIN             12
#define GUI_MULTI_LINE_LEFT_RIGHT_MARGIN           6
#define GUI_SINGLE_LINE_LEFT_TEXT_MARGIN_NO_BG     2 /* For datatime/IP... controls */
#else /* __MMI_FTE_SUPPORT__ */
#define GUI_SINGLE_LINE_TOP_DOWN_MARGIN            1
#define GUI_SINGLE_LINE_LEFT_RIGHT_MARGIN          2
#define GUI_MULTI_LINE_TOP_DOWN_MARGIN             2
#define GUI_MULTI_LINE_LEFT_RIGHT_MARGIN           2
#endif /* __MMI_FTE_SUPPORT__ */

#ifdef __COSMOS_MMI_PACKAGE__
#define GUI_INPUTS_MAX_NUM_OF_CHAR_FOR_EACH_LINE    (MAX_NUM_OF_CHAR_FOR_EACH_LINE/2)
#else /* __COSMOS_MMI_PACKAGE__ */
#define GUI_INPUTS_MAX_NUM_OF_CHAR_FOR_EACH_LINE    MAX_NUM_OF_CHAR_FOR_EACH_LINE
#endif /* __COSMOS_MMI_PACKAGE__ */

#define GUI_INPUTS_MAX_NUM_OF_CHAR_FOR_BIDI_IN_ONE_LINE         512

typedef enum
{
    GUI_INPUT_ALIGN_LEFT,
    GUI_INPUT_ALIGN_CENTER,
    GUI_INPUT_ALIGN_RIGHT
} gui_input_alignment_enum;

#define GUI_INPUT_IS_MARKER(ch) \
                  ((ch)>= GUI_INPUT_MARKER_BEGIN && (ch) <= GUI_INPUT_MARKER_END)

#define GUI_INPUT_IS_FORMAT_MARKER(ch) \
                  (((ch) & GUI_INPUT_MARKER_FORMAT_MASK) == GUI_INPUT_MARKER_FORMAT)

#define GUI_INPUT_IS_PARAGRAPH_MARKER(ch) \
                  (((ch) & GUI_INPUT_MARKER_PARAGRAPH_MASK) == GUI_INPUT_MARKER_PARAGRAPH)

/* test 1-bit flag */
#define GUI_INPUT_CHECK_FORMAT_MARKER(ch, flag) \
                   (((ch) & (flag)) == (flag))

/* test multiple-bit flag */
#define GUI_INPUT_CHECK_SIZE_MARKER(ch,  flag)  \
                  (((ch) & GUI_INPUT_MARKER_SIZE_MASK) == (flag))

/* test 1-bit flag */
#define GUI_INPUT_CHECK_PARAGRAPH_MARKER(ch, flag) \
                   (((ch) & (flag)) == (flag))

/* test multiple-bit flag */
#define GUI_INPUT_CHECK_ALIGN_MARKER(ch, flag) \
                  (((ch) & GUI_INPUT_MARKER_ALIGN_MASK) == (flag))

#define GUI_INPUT_CHECK_LINE_SPACING_MARKER(ch, flag) \
                  (((ch) & GUI_INPUT_MARKER_LINE_SPACING_MASK) == (flag))

#define UI_MULTI_LINE_INPUT_BOX_ALPHABETIC_CHARACTER(c)                                                              \
   (( ((UI_character_type)(c)>=(UI_character_type)0x2180) && ((UI_character_type)(c)<=(UI_character_type)0x9FAF) )?0:1) // only CJK will not word wrapping

#define UI_MULTI_LINE_INPUT_BOX_SPACE_CHARACTER(c) (((UI_character_type)(c)==(UI_character_type)' ')?(1):(0))

#define MULTI_LINE_INPUT_BOX_CHARACTER_WIDTH_CACHE_SIZE  ((UI_device_width)>>1)
#define UI_TEST_GRP_SEP_CHARACTER(c)            (((UI_character_type)(c)==(UI_character_type)0x1D)?(1):(0))

#define UI_TEST_FILE_SEP_CHARACTER(c)           (((UI_character_type)(c)==(UI_character_type)0x1C)?(1):(0))
#define UI_TEST_SENDER_TRUNCATE_SEP_CHARACTER(c)   (((UI_character_type)(c)==(UI_character_type)0x1E)?(1):(0))
#define UI_TEST_RECEIVER_TRUNCATE_SEP_CHARACTER(c)  (((UI_character_type)(c)==(UI_character_type)0x1F)?(1):(0))

#define UI_MULTI_LINE_INPUT_BOX_MOVE_TEXT_CURSOR(x,y)                                        \
{                                                                                      \
    UI_text_x=x;                                                                        \
    UI_text_y=y;                                                                        \
}

extern void UI_set_current_text_color(color c);
extern color UI_get_text_color(void);


#define UI_MULTI_LINE_INPUT_BOX_SET_TEXT_COLOR(c)                                            \
{                                                                                      \
    UI_set_current_text_color(c);                                                                    \
}

#define UI_MULTI_LINE_INPUT_BOX_DRAW_CURSOR(x,y,height,c)                                       \
{                                                                                         \
    gui_fill_rectangle((x)-1,( y),(x),(y)+(height)-1,c);                                   \
}


#define EMS_SET_FONT(f)             \
      {  UI_font=(f);               \
         SetFont(*(f),0);           \
      }

#define EMS_MOVE_TEXT_CURSOR(x,y)      \
      {  UI_text_x=x;                  \
         UI_text_y=y;                  \
      }

#define EMS_SET_TEXT_COLOR(c)                     \
      {  \
          UI_set_current_text_color(c);\
      }
#ifdef __MMI_SCRIPT_EASY__

#ifdef UI_MULTI_LINE_INPUT_BOX_MOVE_TEXT_CURSOR
    #undef UI_MULTI_LINE_INPUT_BOX_MOVE_TEXT_CURSOR
#endif

#define UI_MULTI_LINE_INPUT_BOX_MOVE_TEXT_CURSOR(x,y)   gui_move_text_cursor(x,y)

#ifdef UI_MULTI_LINE_INPUT_BOX_SET_TEXT_COLOR
    #undef UI_MULTI_LINE_INPUT_BOX_SET_TEXT_COLOR
#endif

#define UI_MULTI_LINE_INPUT_BOX_SET_TEXT_COLOR(c)                                            \
{                                                                                      \
    gui_set_text_color(c);                                                                     \
}

#ifdef EMS_MOVE_TEXT_CURSOR
    #undef EMS_MOVE_TEXT_CURSOR
#endif

#define EMS_MOVE_TEXT_CURSOR(x,y)     gui_move_text_cursor(x,y)

#ifdef EMS_SET_TEXT_COLOR
    #undef EMS_SET_TEXT_COLOR
#endif

#define EMS_SET_TEXT_COLOR(c)                     \
      {  gui_set_text_color(c);                         \
         UI_set_current_text_color(c);\
      }

#ifdef EMS_SET_FONT
    #undef EMS_SET_FONT
#endif

extern void se_mtk_set_font(UI_font_type f);
#define EMS_SET_FONT(f)             se_mtk_set_font(f)

#endif /* __MMI_SCRIPT_EASY__ */

#define EMS_EDITOR_DRAW_DOTTED_LINE(x1,x2,y,c)                       \
{  S32 i,xx1=(x1),xx2=(x2),yy=(y);                                   \
   for(i=xx1;i<=xx2;i++)                                             \
   {  if(i&1) gui_putpixel(i,yy,c);                                  \
   }                                                                 \
}

#define EMS_EDITOR_DRAW_LINE(x1,x2,y,c)                              \
{  S32 i,xx1=(x1),xx2=(x2),yy=(y);                                   \
   for(i=xx1;i<=xx2;i++)                                             \
   {  gui_putpixel(i,yy,c);                                          \
   }                                                                 \
}

#define EMS_SHOW_HORIZONTAL_RULE_FOR_NEWLINE       0
/* START PMT NEERAJ 20050916 */
#define EMS_SHOW_HORIZONTAL_RULE_FOR_ALL_LINES        1
/* END PMT NEERAJ 20050916 */
#define EMS_ENABLE_EDITOR_OBJECT_PLAYBACK          0
#define EMS_PREVENT_CRLF_DISPLAY                1
#define EMS_USE_CRLF_COMBINATION                1
#define EMS_USE_ESC_COMBINATION                    1
#define EMS_USE_GSM_EXTENDED                    0
#define EMS_ENABLE_GRAPHICAL_CURSOR_MOVEMENT       1
#define EMS_INPUTBOX_PARAGRAPH_BREAK_CHARACTER        0x0A
#define EMS_ENABLE_SPECIAL_FONT_DISPLAY               1
#define EMS_HEADER_SCROLL_SIZE                     20
#define EMS_ENABLE_TESTFIX_OBJECT_ORDERING            1

/* one pixtel gap - characater - font underline  - horizontal line*/
#define EDITOR_LINE_UPPER_PIXTEL        1
#define EDITOR_LINE_LOWER_PIXTEL        2
#define EDITOR_LINE_ADDITION_PIXTEL     (EDITOR_LINE_UPPER_PIXTEL + EDITOR_LINE_LOWER_PIXTEL)
#define EDITOR_STRIKETHOUGH_LINE_PIXTEL 4
//#define EMS_ADDITION_PIXTEL_UNDER_CHARACTER 3

extern BOOL cancelWidth;
#define FONT_CANCEL_WIDTH(X)    cancelWidth = (X)

#define INPUTBOX_TRUNCATE_STRING   GUI_TEXT_TRUNCATE_SUFFIX
#define INPUTBOX_TRUNCATE_DOT_NUM  GUI_TEXT_TRUNCATE_SUFFIX_COUNT

typedef struct
{
    color default_color;
    color curr_color;
    color default_text_bg_color;
    color curr_text_bg_color;
    color line_begin_color;
    color line_end_color;
    stFontAttribute curr_font;
    stFontAttribute line_begin_font;    /* backup the font used at the beginning of a line */
    stFontAttribute line_end_font;
    gui_input_alignment_enum default_alignment;
    gui_input_alignment_enum curr_alignment;
    U8 curr_border;         /* border not part of font attribute */
    U8 curr_strikethrough;  /* strikethrough not part of font attribute */
    U8 line_begin_border;
    U8 line_begin_strikethrough;
    U8 draw_text_bg_color;
    U8 line_end_border;
    U8 line_end_strikethrough;
    /* attributes that are only active in the current line */
    U8 more_line_spacing;
    U8 line_separator;
} gui_input_richtext_struct;

extern color gui_richtext_strikethrough_color;
extern color gui_richtext_default_text_bg_color;
extern color gui_hilite_underline_color;

// for total text shaping
extern U16 shaping_str[];
extern U16 OrgToSha[];
extern S32 unshaped_text_len ;
extern S32 shaped_text_len;

#ifdef UI_EMS_SUPPORT
extern S32 wgui_EMS_inputbox_information_bar_height;
extern stFontAttribute UI_EMS_inputbox_medium_font;
extern stFontAttribute UI_EMS_inputbox_current_font;
extern color UI_EMS_inputbox_text_color;
extern EMSALIGNMENT UI_EMS_current_alignment;
extern EMSALIGNMENT lastest_EMS_alignment;
extern U8 UI_EMS_strikethrough;
extern U8 EMS_view_mode;

#if(!UI_DISABLE_EMS_INPUT_BOX)
extern EMSObject UI_EMS_normal_text_format_object;
#endif
#endif

#if defined(__MMI_INSCREEN_MULTILINE_TEXTBOX__)
extern S8 MMI_multi_line_inputbox_present;
#endif

extern U8 wgui_inputbox_information_flag;
extern S32 wgui_inputbox_information_bar_height;
extern U8 MMI_bidi_input_type;

extern gui_inputs_draw_back_ground_funcptr g_inputs_background_filler;

extern S8 g_mmi_wgui_halfline_marquee_scroll_enable;
#define MMI_HALF_LINE_MARQUEE_SCROLLING_ENABLE     1

#ifdef __MMI_INDIC_ALG__
#define MAX_EDITOR_DISP_LEN      60
#endif
#define MAX_CLUSTER_LEN 60

typedef enum
{
    SINGLE_CHAR,
    MASK_CHAR,
    MARKER_CHAR,                        /* marker character */
    EMS_OBJECT_UNIT,                    /* ems object */
    ICON_CALLBACK_CLUSTER,              /* a group of icon back control character */
    VIET_CLUSTER,                       /* a Vi cluster */
    INDIC_CLUSTER,                      /* a INDIC cluster */
    THAI_CLUSTER,                       /* a THAI cluster */
    CRLF_CLUSTER,                       /* CR and LF combination */
    EMS_EXT_CHARSET_CLUSTER,            /* Ems extention charset combination. 0x1B-0xXX*/
    OTHER_CLUSTER                       /* others cluster */
}gui_editor_unit_type_enum;

typedef enum
{
    NORMAL_CURSOR = 0,                  /* b->cursor_p is valid and draw the cursor normally */
	FINDING_CURSOR,                     /* b->cursor_p is invalid and we need to find its value */
	FOUND_CURSOR                        /* b->cursor_p is found after FINDING_CURSOR */
}gui_cursor_state_enum;

typedef struct
{
    U8  char_type;                      /* this unit type: gui_editor_chartype_enum */
    U8  obj_width;
    U8  obj_height;
    U8  highlight_flag;                 /* whether the current object needs highlight*/
    U16 hilite_idx;                     /* the hilite index of the current unit */
    
#ifdef UI_EMS_SUPPORT
    U16 offset_text;                     /* the ems text offset to the current line start */
    EMSObject *object_unit;             /* the ems object */
#endif

    mmi_lm_cluster_info c_info;         /* this char_unit information */
}gui_editor_character_unit_struct;

typedef struct
{
    U16 line_width;                     /* the line width  */
    U16 line_height;                    /* the line height */
    S32 line_ascent;                    /* the line ascent */
    S32 line_dscent;                    /* the line dscent */
    U16 line_unit_count;                /* the count of the unit at the line */
    U16 line_char_count;                /* the count of the character at the line */
    U16 cursor_unit_index;              /* indicate to which unit the cursor is located on the left*/
    U16 cur_read;                       /* the index of the current unit to be handling */
#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    gui_editor_character_unit_struct* line_char;
#else
    gui_editor_character_unit_struct line_char[GUI_INPUTS_MAX_NUM_OF_CHAR_FOR_EACH_LINE/2];  /* the unit structure at the line */ 
#endif
    UI_buffer_type line_start_p;        /* the start address of this line based on the b->text */
    
#ifdef __MMI_BIDI_ALG__
    U16 visual_to_logic_map[GUI_INPUTS_MAX_NUM_OF_CHAR_FOR_BIDI_IN_ONE_LINE/2];       /* the map from the bidi text to the original text */
    U16 logic_to_visual_map[GUI_INPUTS_MAX_NUM_OF_CHAR_FOR_BIDI_IN_ONE_LINE/2];       /* the map from the original text to the bidi text */
    U16 cur_v_read;
    U16 visual_unit_count;
    U8 visual_str[GUI_INPUTS_MAX_NUM_OF_CHAR_FOR_BIDI_IN_ONE_LINE];                 /* the buffer to save the bidi text */
#endif
    U8 cursor_line_flag;                /* indicate whether the cursor is at this line */
    U8 bidi_done_flag;                  /* indicate whether this line has been applied BIDI */
    U8 marker_flag;                     /* indicate whether the second pass need to handle the marker specially */
    U8 override_flag;                   /* indicate whether this line need override mode to BIDI */
    U8 highlight_flag;
}gui_editor_line_unit_struct;

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
typedef struct
{
    S32 offset;
    S32 index;
    S32 offset_y;
} input_box_line_index_struct;

#ifdef UI_EMS_SUPPORT
typedef struct
{
    EMSPosition current_position;
    EMSPosition end_position;
    S32 index;
    S32 offset_y;
} ems_line_index_struct;
#endif /* UI_EMS_SUPPORT */
#endif

typedef struct 
{
    S32 x1, y1;      /* x1,y1 -> left-top corner of the editor windows */
    S32 x2, y2;      /* x2,y2 -> right-bottom of the editor windows */
    S32 backup_x1, backup_x2;
    S32 xtx, yty;
    S32 move_to_x, move_to_y;
    S32 l_clip, highlight_end_y;
    UI_buffer_type current_text_p;
    UI_buffer_type current_cursor_p;  /* points to the character at which the cursor is positioned */
    UI_buffer_type previous_cursor_p;
    S32 tx, ty, xx, yy;
    color selector_color;
    color selected_text_color;
    S32 reserve_line_height_for_hilite; /* using in barcode */
    S32 cursor_line_height;
    S32 previous_line_height;
    S32 edit_width, edit_height;
    U32 flags;
    S32 set_cursor_flag;
    S32 line_counter;
    PMT_BIDI_TYPES default_direction;
    gui_input_richtext_struct rich_text;
    BOOL draw_separator;    /* Used by UI_MULTI_LINE_INPUT_BOX_DRAW_SEPARATOR */
    gdi_handle scr_layer;
    U8 locate_cursor, border_y;
    U8 multitap_flag, overwrite_flag;
    U8 word_highlight;
    U8 next_line_found_flag;
    U8 cursor_line_found_flag;
    U8 find_new_cursor_flag;
    U8 end_line;
    U8 is_truncate;
#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
    U8  check_flag;
    U8  adjust_view;
#endif 

#ifdef __MMI_BIDI_ALG__
    U16 logical_cur_pos;
    U16 visual_str_len;
    U16 visual_cur_pos;
    pBOOL arabic_char_flag ;
#endif 

#if defined(__UI_PAGING_IN_MULTILINE_EDITOR__)
    S32 total_page_height;  /* ritesh */
    S32 char_count;
#endif /* defined(__UI_PAGING_IN_MULTILINE_EDITOR__) */ 

#if defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__)
    UI_buffer_type backup_text;
    U8 cursor_moved_by_shaping;
#endif

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    input_box_line_index_struct sl, el;
#endif
}multi_line_input_box_show_struct;

#ifdef UI_EMS_SUPPORT
typedef struct 
{
    S32 x1, y1;      /* x1,y1 -> left-top corner of the editor windows */
    S32 x2, y2;      /* x2,y2 -> right-bottom of the editor windows */
    S32 xtx, yty;
    S32 tx, ty, xx, yy;
    U32 flags;
    S32 move_to_x, move_to_y;
    S32 edit_width, edit_height, nlines;
    EMSPosition line_start_position;
    EMSPosition line_end_position;
    EMSPosition current_position;
    EMSPosition mapped_cursor_position;
    EMSObject *line_start_text_format;
    EMSObject *line_end_text_format;
    S32 text_format_count;
    S32 previous_text_format_count;
    UI_buffer_type current_text_p;

    S32 n_lines;
    S32 set_cursor_flag;
    U8 multitap_flag, overwrite_flag;
    U8 line_alignment;
    U8 end_line;
    U8 word_highlight;
    U8 next_line_found_flag;
    U8 cursor_line_found_flag;
    U8 find_new_cursor_flag;
    U8 total_str[GUI_INPUTS_MAX_NUM_OF_CHAR_FOR_EACH_LINE];
    PMT_BIDI_TYPES default_direction;
    
#ifdef __MMI_BIDI_ALG__
    U16 logical_cur_pos;
    U16 visual_str_len;
    U16 visual_cur_pos;
    pBOOL arabic_char_flag ;
#endif 

#if defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__)
    UI_buffer_type backup_text;
    U8 cursor_moved_by_shaping;
#endif

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT
    ems_line_index_struct sl, el;
#endif
}ems_input_box_show_struct;
#endif /* UI_EMS_SUPPORT */

typedef struct 
{
    S32 x1, y1;      /* x1,y1 -> left-top corner of the editor windows */
    S32 x2, y2;      /* x2,y2 -> right-bottom of the editor windows */
    S32 text_x, text_y;
    S32 move_to_x, move_to_y;
    S32 edit_width;
    S32 sy1, sy2;
    color text_color;
    U32 flags;
    
    UI_buffer_type current_text_p;
    UI_buffer_type current_cursor_p;  /* points to the character at which the cursor is positioned */
    UI_buffer_type previous_cursor_p;
    PMT_BIDI_TYPES default_direction;
    color selector_color;
    color selected_text_color;
    S32 character_width;
    S32 character_height;
    S32 base_line;
    mmi_lm_cluster_info pre2_cluster, pre_cluster, cur_cluster;
#ifdef __MMI_BIDI_ALG__
    U16 logical_cur_pos;
    U16 visual_str_len;
    U16 visual_cur_pos;
    pBOOL arabic_char_flag ;
#endif 
#if defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__)
    UI_buffer_type backup_text;
#endif
    U8 text_gap;
    U8 word_highlight;
    U8 find_new_cursor_flag;
    U8 multitap_flag, overwrite_flag;
    U8 cluster_type;
}single_line_input_box_show_struct;

extern gui_editor_line_unit_struct g_editor_line;

/* Multi-line input box external function */
extern U8 gui_find_multi_line_one_line(multi_line_input_box *b, multi_line_input_box_show_struct*  bs);
extern void gui_init_multi_line_show_struct(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_init_multi_line_input_box_for_show(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_get_multi_line_text_language_type(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_prepare_multi_line_show_area(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_draw_multi_line_background_area(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_set_multi_line_text_area_range(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_setup_multi_line_text_clip(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_set_multi_line_default_font(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_adjust_multi_line_cursor_for_language(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_adjust_multi_line_cursor_for_icon_callback(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_prepare_multi_line_new_line_loop(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_prepare_multi_line_one_line_show(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_set_multi_line_cursor_information(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_calculate_multi_line_paging_information(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_translate_multi_line_bidi_text(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_draw_multi_line_one_line(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_end_multi_line_new_line_loop(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_end_multi_line_text_display(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_draw_multi_line_under_line(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_draw_multi_line_callback_area(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_set_multi_line_scroll_bar(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_show_multi_line_scroll_bar(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_update_multi_line_extern_module_infomation(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_adjust_multi_line_text_offset_y(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_retore_multi_line_buffer_from_shaping(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern S32 gui_measure_character_adv_width(UI_buffer_type text_p, U16 cluster_count);
extern void gui_adjust_former_unit_width(U16 count);
extern U8 gui_get_char_type_by_lm_lang(mmi_lm_lang_enum id);
extern void gui_convert_bidi_map_to_unit_map(S32 max_n);
extern void gui_show_multi_line_input_box_basic(multi_line_input_box *b, S32 move_to_x, S32 move_to_y);

extern void gui_multi_line_show_special_remaining_counter(multi_line_input_box *b);
extern S32 gui_save_multi_line_visible_info(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
#if defined(__MMI_VECTOR_FONT_SUPPORT__)
extern gdi_handle gui_inputs_get_source_layer(void);
#endif

#ifdef __MMI_BIDI_ALG__
void gui_translate_multi_line_bidi_text(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_set_g_editor_line_unit_by_bidi_text(UI_buffer_type visual_text_p);
#endif

#if defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__)
extern void gui_translate_multi_line_buffer_to_shaping(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
#endif

#if defined(__MMI_ARSHAPING_ENGINE__)
S32 gui_multi_line_mapping_org_to_sha(S32 position);
S32 gui_multi_line_mapping_org_to_sha_forward(S32 position);
S32 gui_multi_line_mapping_sha_to_org(S32 position);
#endif

extern void wgui_redraw_input_information_bar(void);
extern void UI_draw_horizontal_line(S32 x1, S32 x2, S32 y, color c);
extern MMI_BOOL gui_multi_line_input_box_is_pos_inside_hilite(multi_line_input_box *b, UI_buffer_type current_pos);
extern MMI_BOOL gui_multi_line_input_box_is_pos_inside_hilite_ext(
            multi_line_input_box *b,
            UI_buffer_type current_pos,
            U16 *hilite_idx);
extern void gui_multi_line_input_box_show_cursor(
        multi_line_input_box *b,
        S32 x,
        S32 y,
        S32 height,
        S32 clip_x1,
        S32 clip_y1,
        S32 clip_x2,
        S32 clip_y2);

/* Single-line input box external function */
extern void gui_init_single_line_show_struct(single_line_input_box *b, single_line_input_box_show_struct *bs);
extern PMT_BIDI_TYPES gui_get_single_line_text_language_type(single_line_input_box *b, MMI_BOOL *arabic_char_flag);
extern void gui_translate_single_line_buffer_to_shaping(single_line_input_box *b, single_line_input_box_show_struct *bs);
extern void gui_translate_single_line_bidi_text(single_line_input_box *b, single_line_input_box_show_struct *bs);
extern void gui_draw_single_line_background(single_line_input_box *b, single_line_input_box_show_struct *bs);
extern void gui_adjust_single_line_cursor_for_language(single_line_input_box *b, single_line_input_box_show_struct *bs);
extern void gui_draw_single_line_one_line(single_line_input_box *b, single_line_input_box_show_struct *bs);
extern void gui_retore_single_line_buffer_from_shaping(single_line_input_box *b, single_line_input_box_show_struct *bs);
extern void gui_draw_single_line_callback_area(single_line_input_box *b, single_line_input_box_show_struct *bs);
extern void gui_single_line_show_special_remaining_counter(single_line_input_box *b);

#ifdef UI_EMS_SUPPORT
/* Ems input box external function */
extern U8 gui_find_ems_one_line(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern void gui_init_ems_show_struct(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern void gui_prepare_ems_show_area(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern void gui_draw_ems_background_area(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern void gui_set_ems_text_area_range(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern void gui_adjust_ems_cursor_for_language(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern void gui_prepare_ems_new_line_loop(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern void gui_prepare_ems_one_line_show(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern void gui_prepare_ems_total_str(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern void gui_draw_ems_one_line(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern void gui_end_ems_new_line_loop(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern void gui_draw_ems_under_line(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern void gui_show_ems_scroll_bar(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern void gui_retore_ems_buffer_from_shaping(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern U8 TestLastPosition(EMSData *data, EMSPosition *p);
extern void gui_set_ems_line_information(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern void gui_find_ems_cursor_position_for_view_mode(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern void gui_set_ems_cursor_information(UI_EMS_input_box *b, ems_input_box_show_struct *bs, MMI_BOOL force_cursor);
extern void gui_EMS_input_box_set_text_format(UI_EMS_input_box *b, EMSObject *o);
extern void gui_show_EMS_input_box_cursor(UI_EMS_input_box *b, S32 x, S32 y, S32 width, S32 height, U32 flags);
extern U8 BackwardCurrentPositionSeekObject(EMSData *data, EMSPosition *dst);
extern U8 ForwardCurrentPositionSeekObject(EMSData *data, EMSPosition *dst);
extern void gui_show_EMS_input_box_basic(UI_EMS_input_box *b, S32 move_to_x, S32 move_to_y);
extern void gui_EMS_input_box_remove_extension_character(UI_EMS_input_box *b, EMSData *data);
extern U8 gui_EMS_input_box_insert_extension_character(UI_EMS_input_box *b, EMSData *data);
extern U8 gui_ems_auto_detection_insert_character(UI_EMS_input_box *b, UI_character_type c);
extern U8 gui_ems_auto_detection_insert_multitap_character(UI_EMS_input_box *b, UI_character_type c);
extern U8 gui_EMS_input_box_insert_multitap_character_no_draw(UI_EMS_input_box *b, UI_character_type c);

#ifdef __UI_EMS_HIGHLIGHT_LIST_SUPPORT__
/* EMS highlight support */
extern MMI_BOOL gui_EMS_input_box_is_pos_inside_hilite_ext(
                    UI_EMS_input_box *b,
                    UI_buffer_type current_pos,
                    U16 *hilite_idx);
#endif /* __UI_EMS_HIGHLIGHT_LIST_SUPPORT__ */

#ifdef __MMI_BIDI_ALG__
extern void gui_get_ems_text_language_type(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
void gui_translate_ems_bidi_text(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
#endif

#if defined(__MMI_ARSHAPING_ENGINE__) && defined(__MMI_BIDI_ALG__)
extern void gui_translate_ems_buffer_to_shaping(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern S32 gui_ems_mapping_org_to_sha(S32 position);
extern S32 gui_ems_mapping_sha_to_org(S32 position);
#endif

extern kal_uint16 BackwardCurrentPositionSkipCR(EMSData *data);
extern kal_uint16 ForwardCurrentPositionSkipCR(EMSData *data);
extern void MoveCurrentPosition(EMSData *data, EMSPosition *start, EMSPosition *end, kal_uint16 steps);
extern void EMS_map_position(EMSData *data, EMSPosition *src, EMSPosition *dst);
extern void MoveCursorToPosition(EMSData *data, EMSPosition *dst);
extern U8 TestLastPosition(EMSData *data, EMSPosition *p);
extern U8 TestFirstPosition(EMSData *data, EMSPosition *p);
extern U8 BackwardCurrentPositionObject(EMSData *data, EMSPosition *dst);
extern U8 ForwardCurrentPositionObject(EMSData *data, EMSPosition *dst);
extern void EMS_move_graphical_cursor(EMSData *data, S32 start_x, S32 cursor_x, S32 max_count);
extern void gui_ems_show_special_remaining_counter(UI_EMS_input_box *b);
#endif /* UI_EMS_SUPPORT */

#ifdef GUI_INPUT_BOX_CACHE_SUPPORT

#define EDITOR_LOCK                             gui_inputs_cache_lock_mutex()
#define EDITOR_UNLOCK                           gui_inputs_cache_unlock_mutex()

/* U32 editor_visible_line_count;
#define GUI_INPUT_BOX_VISIBLE_LINE_COUNT  editor_visible_line_count*/
#define GUI_INPUT_BOX_VISIBLE_LINE_COUNT        ((UI_DEVICE_HEIGHT + GUI_INPUT_BOX_ADDITION_AREA*2)/(8 + EDITOR_LINE_ADDITION_PIXTEL) + 1)
#define GUI_INPUT_BOX_ALL_LINE_MAX              1024

#define GUI_INPUT_BOX_CACHE_UPDATE_ALL          0
#define GUI_INPUT_BOX_CACHE_UPDATE_PARTIAL      1
#define GUI_INPUT_BOX_CACHE_UPDATE_VISIBLE      2


#define ERROR_CACHE_INVALID                     0
#define ERROR_CACHE_REALLOC_FAIL                -1

typedef struct
{
    color text_color;
    color text_bg_color;
    stFontAttribute font;
    U32 alignment : 2;
    U32 border : 1;
    U32 strikethrough : 1;
    U32 more_line_spacing : 3;
    U32 line_separator : 1; 
} input_box_line_format_struct;

/* input box line cache structure */
typedef struct
{
    U32 start_offset;
    S16 char_count;
    S16 line_ascent;
    S16 line_dscent;
    U16 line_height;
    U16 line_width;
    input_box_line_format_struct line_end_format;
} input_box_all_line_struct;

#ifdef UI_EMS_SUPPORT
/* ems line cache structure */
typedef struct
{
    EMSPosition current_position;
    EMSPosition end_position;
    S16 char_count;
    S16 line_ascent;
    S16 line_dscent;
    U16 line_height;
    U16 line_width;
} ems_all_line_struct;
#endif

/* input box visible line cache structure */
typedef struct
{
    U16 line_unit_count;                /* the count of the unit at the line */
    U16 line_char_count;                /* the count of the character at the line */
    U8 cursor_line_flag;                /* indicate whether the cursor is at this line */
    U8 marker_flag;                     /* indicate whether the second pass need to handle the marker specially */
    U8 override_flag;                   /* indicate whether this line need override mode to BIDI */
    U8 highlight_flag;
    gui_editor_character_unit_struct line_char[GUI_INPUTS_MAX_NUM_OF_CHAR_FOR_EACH_LINE/2];  /* the unit structure at the line */ 
} input_box_visible_line_struct;

/* input box line cache structure */
typedef struct
{
    S32 b_create;
    S32 visible_cache_size;
    S32 all_line_cache_size;
    S32 all_line_count;
    S32 total_height;
    S32 updating_line_index;
    S32 updating_line_y;
    S32 max_line_height;
    S32 line_query_begin;
    S32 line_query_end;
    void *timer_callback;
    
    void *b;
    S32 flags;
    S32 ext_flags;
    
    input_box_all_line_struct* all_line_cache_p;
    #ifdef UI_EMS_SUPPORT
    ems_all_line_struct* ems_all_line_cache_p;
    #endif
    /*visible information*/
    S32 update_visible_only;
    S32 visible_line_ok;
    S32 visible_start_y;
    S32 visible_end_y;
    S32 visible_start_index;
    S32 visible_end_index;
    
    input_box_visible_line_struct* visible_line_cache_p;
    
    /* only for debug */
    S32 all_line_max_count;
} input_box_line_cache_struct;

extern gui_editor_character_unit_struct* temp_line_char; 

extern S32 gui_inputs_cache_all_line_size_get(void);
extern S32 gui_inputs_cache_visible_size_get(void);
extern void gui_inputs_cache_free(void* p);

extern void gui_find_multi_line_cursor_from_cache(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_show_multi_line_input_box_ext_internal_with_cache(multi_line_input_box *b, S32 move_to_x, S32 move_to_y);
extern void gui_prepare_multi_line_one_line_context(multi_line_input_box *b, multi_line_input_box_show_struct *bs); 
extern void gui_get_multi_line_visible_area(multi_line_input_box *b, S32 *y1, S32 *y2);
extern void gui_mlc_all_line_update(void);
extern void gui_mlc_partial_line_update(void);
extern input_box_all_line_struct *gui_mlc_line_info_get(S32 idx);
extern input_box_visible_line_struct *gui_mlc_visible_info_get(S32 idx);
extern MMI_BOOL gui_inputs_cache_create(void *b);
extern S32 gui_inputs_cache_is_not_in_update(void);
extern S32 gui_mlc_change_request(S32 char_index);
extern S32 gui_mlc_visible_line_shown_request(void);
extern S32 gui_jump_multi_line_paging_visible_area(multi_line_input_box *b);
extern S32 gui_preset_multi_line_visible_line(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern void gui_set_multi_line_paging_visible_information(multi_line_input_box *b, multi_line_input_box_show_struct *bs);
extern S32 gui_mlc_total_line_height(void);
extern S32 gui_mlc_total_line_count(void);
extern S32 gui_mlc_character_line_index_find(S32 char_index);
extern S32 gui_mlc_line_cache_one_line_offset_y(S32 idx);
extern S32 gui_mlc_visible_start_line_get(input_box_line_index_struct *idx_s);
extern S32 gui_mlc_visible_end_line_get(input_box_line_index_struct *idx_e);
extern S32 gui_mlc_text_format_info_get(gui_input_richtext_struct *richtext, S32 idx);
extern MMI_BOOL gui_inputs_cache_is_valid(void);
extern MMI_BOOL gui_mlc_is_dirty(multi_line_input_box *b);
extern void gui_inputs_cache_invalid(void);

#ifdef UI_EMS_SUPPORT
extern void gui_show_EMS_input_box_with_cache(UI_EMS_input_box *b, S32 move_to_x, S32 move_to_y);
extern void gui_get_ems_visible_area(UI_EMS_input_box *b, S32 *y1, S32 *y2);
extern void gui_emsc_partial_line_update(void);
extern void gui_emsc_all_line_update(void);
extern S32 gui_emsc_visible_start_line_get(ems_line_index_struct *idx_s);
extern S32 gui_emsc_visible_end_line_get(ems_line_index_struct *idx_e);
extern ems_all_line_struct *gui_emsc_line_info_get(S32 idx);
extern input_box_visible_line_struct *gui_emsc_visible_info_get(S32 idx);
extern S32 gui_emsc_total_line_height(void);
extern S32 gui_emsc_total_line_count(void);
extern S32 gui_emsc_visible_line_shown_request(void);
extern S32 gui_emsc_change_request(EMSPosition pos);
extern void gui_set_ems_highlight_information(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern S32 gui_emsc_line_cache_one_line_offset_y(S32 idx);
extern void gui_find_ems_cursor_from_cache(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern S32 gui_preset_ems_visible_line(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern void gui_prepare_ems_one_line_context(UI_EMS_input_box *b, ems_input_box_show_struct *bs);
extern void gui_emsc_text_format_apply(UI_EMS_input_box *b, ems_input_box_show_struct *bs, S32 index);
extern MMI_BOOL gui_emsc_is_dirty(UI_EMS_input_box *b);
#endif /* UI_EMS_SUPPORT */
extern S32 gui_inputs_cache_get_error_code(void);
extern void gui_inputs_cache_init_mutex(void);
extern void gui_inputs_cache_lock_mutex(void);
extern void gui_inputs_cache_unlock_mutex(void);

#endif
#ifdef __MMI_EDITOR_SSP_SUPPORT__
extern void gui_multiline_ssp_update_client(void *user_data, S32 offset);
extern void gui_multiline_ssp_get_client_info(
                void *user_data, 
                S32 *total_offset, 
                S32 *cur_offset,
                S32 *move_type);
extern void gui_singleline_ssp_update_client(void *user_data, S32 offset);
extern void gui_singleline_ssp_get_client_info(
                void *user_data, 
                S32 *total_offset, 
                S32 *cur_offset,
                S32 *move_type);
#endif


#endif

