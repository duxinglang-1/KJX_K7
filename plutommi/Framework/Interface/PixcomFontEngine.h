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
 *  PixcomFontEngine.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/

#include "MMIDataType.h"
#include "FontRes.h"

#ifndef _PIXCOMFONTENGINE_H
#define _PIXCOMFONTENGINE_H

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include "MMI_features.h"

#include "lcd_sw_inc.h"
#include "kal_general_types.h"

#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
#include "Fs_gprot.h"
#endif

#define ZWNJ     0x200C
#define ZWJ       0x200D   

/* to check the control chars
   add 0x0A,0x0D~0x0F for displaying control characters as space
   add 0xA0 for NBSP in Vietnamese as space */
#define FONT_TEST_CONTROL_CHAR(c)      \
(     (c=='\t'/* 0x09 */)                \
   || (c==0x08)                        \
   || (c==0x0A)                        \
   || (c==0x0D)                        \
   || (c==0x0E)                        \
   || (c==0x0F)                        \
   || (c==0xA0)                        \
   || (c== 0x2028)                    \
   || (c == 0x2029)                   \
)

#define FONT_TEST_FORMATTING_CHARS(c)   (((c) >= 0x200C && (c)<= 0x200f) || ((c) >= 0x202a && (c)<= 0x202f))
#define FONT_TEST_DATE_CHARS(c)   ((c) >= 0x87 && (c)<= 0x94)    
#define FONT_TEST_CRLF_ANF_SPACE_PROPRIETARY_SYMBOL(c) ((c) >= 133 & (c)<=134) /* for new line and space symbol used in symbol table */
#define FONT_TEST_SPACE_CHAR(c) (((c) >= 0x2000 && (c)<= 0x200A) || ((c) == 0xfeff)) /* 0x200B is zero space but we treat it as null character. */
#define FONT_TEST_ZERO_WIDTH_SPACE(c) ((c) == 0x200B)
#define FONT_TEST_ZERO_WIDTH_CHAR(c) ((c)<= 0x1F)

/* for R2L characters */
#define MAX_SHOW_STRING_TEXT_LENGTH          700

#ifdef __SLIM_PROJECT_128_32__
#define MAX_NUM_OF_CHAR_FOR_EACH_LINE         (UI_DEVICE_WIDTH/2)     // in slim project, to save memory size
#else
#define MAX_NUM_OF_CHAR_FOR_EACH_LINE         ((UI_DEVICE_WIDTH/2)*2) /*(in bytes).  assume LCD width fill with 1 pixel text and 1 pixel gap */
#endif

#define FONT_TEST_BIDI_CONTROL_CHAR(c) ((c==0x06)||(c==0x07)||(c==0x08)||(c==0x09)||(c==0x0A)||(c==0x0D))
#define FONT_TEST_WORD_WRAPPING_BREAK_CHARACTER(c) (c == 0x20 ? 1:0)
#define FONT_TEST_NEW_LINE_CHAR(c) (((c) == 0x0a || (c) == 0x0d || (c) == 0x2028 || (c) == 0x2029) ? (1) : (0))
#define FONT_TEST_ASCII_CHARACTER(c)   (((UI_character_type)(c)<=(UI_character_type)0xFF)?(1):(0))

// test if operator character like '+', '-', '*', '/'
#define FONT_TEST_OPERATOR_CHAR(c) (((c) == 0x002B) || ((c) == 0x002D) || ((c) == 0x002F) || ((c) == 0x00D7))

// convert the size to pixel
#define FONT_PIXEL_SIZE(size)  (((size)|(0x80)))

#ifdef  __MMI_VECTOR_FONT_SUPPORT__
#define __MMI_FONT_EFFECTS__
#if defined(FONT_ENGINE_FREETYPE) || defined(FONT_ENGINE_FREETYPE_DEMO)
#define __MMI_VECTOR_FONT_KERNING__
#endif
#define __MMI_FE_RICH_TEXT_SUPPORT__
#endif

#if defined(__MMI_FONT_EFFECTS__)
#define MMI_FE_FONT_EFFECT_DIM_SIZE MMI_MENUITEM_HEIGHT
#define MMI_FE_FONT_EFFECT_POOL_SIZE (MMI_FE_FONT_EFFECT_DIM_SIZE * MMI_FE_FONT_EFFECT_DIM_SIZE)

#define GAUSS_WIDTH_DROP_SHADOW 7
#define GAUSS_WIDTH_OUTER_GLOW 5
#define GAUSS_WIDTH_BORDERE_MAX 11
#define GAUSS_WIDTH_BORDERED 5


#define ANGLE_ROTATION 45
#define MAX_GRAY_LEVEL 255
#define FONTS_EFFECT_NODE_START 3

#define  HLSMAX   255  
#define  RGBMAX   255  
#define UNDEFINED (HLSMAX*2/3)

#endif /* __MMI_FONT_EFFECTS__ */


#define FONT_TYPE_FIXED_WIDTH                0x80

#define FONT_FAMILY_NORMAL                  0
#define FONT_FAMILY_FIXED_WIDTH             1

/*****************************************************************************
*  Typedef
*****************************************************************************/
typedef struct
{
    U16 normal_data_size;
    U16 border_data_size;
    U8  data[1];
    U8  padding[3];
} mmi_fe_render_data_struct;

/* Font engine color type */
typedef struct mmi_fe_color
{
    U8 a;    /* alpha */
    U8 r;    /* red   */
    U8 g;    /* green */
    U8 b;    /* blue  */
} mmi_fe_color;

#if defined(__MMI_FONT_EFFECTS__)
/* Color group for font effect */
typedef struct stFontColor
{
    //mmi_fe_color text_color;                /* The text color */
    mmi_fe_color bordered_color;        /* The bordered color */
    mmi_fe_color first_gradient_color;        /* The text color for gradient effect. It works with existing text color to present the gradient effect */
    mmi_fe_color second_gradient_color;        /* The text color for gradient effect. It works with existing text color to present the gradient effect */
    mmi_fe_color shadow_color;          /* The shadow color */
    mmi_fe_color outerglow_color;   /* The shadow color */
    mmi_fe_color upper_engraved_color;  /* The engraved color  */
    mmi_fe_color lower_engraved_color;  /* The engraved color  */
} stFontColor;

/* Advace font attribute */
typedef struct stAdvanceFontAttribute
{
    S16 shadow_degree;  /* The degree of change of shadow color. It presents the direction of the light. The degree is limited to 0¢X, 45¢X, 90¢X, 135¢X, 180¢X, 225¢X, 270¢X, 315¢X */
    S16 engraved_degree;    /* The degree of change of shadow */
    U8 shadow_distant;  /* The distant between the shadow original to the text original */
    U8 shadow_range;    /* The shadow range */
    U8 shadow_transparency;    /* The shadow intensity */
    U8 border_size; /* The size of the border */
    U8 gradient_direction;  /* The direction of gradient */
    U8 gradient_transparency;  /* The direction of gradient */
    U8 outerglow_range; /* The outer glow range */
    U8 outerglow_transparency;    /* The shadow intensity */
    U8 engraved_transparency;    /* The shadow intensity */
    U8 border_transparency;    /* The shadow intensity */
} stAdvanceFontAttribute;

typedef struct stFontAttributeNode
{
    stAdvanceFontAttribute advance_font_attribute;
    stFontColor font_color;
    U8 attribute_id;
    U8 effect_type;
    U8 node_type;   /* 0: static node, 1: dynamic node */
    struct stFontAttributeNode *next;
}stFontAttributeNode;

typedef enum
{
    MMI_FE_GRADIENT_DIRECTION_NONE = 0,
    MMI_FE_GRADIENT_DIRECTION_VERTICAL,
    MMI_FE_GRADIENT_DIRECTION_HORIZONTAL,
	MMI_FE_GRADIENT_DIRECTION_MAX,
} mmi_fe_gradient_direction_enum;

#if 0//defined(__MMI_FONT_EFFECTS__)		//move to pixcomfontengine.c
/* under construction !*/
#endif

#endif /* __MMI_FONT_EFFECTS__ */

/* Font attribute */
typedef struct stFontAttribute
{
    U8 bold;       /* bold style */
    U8 italic;     /* italic style */
    U8 underline;  /* underline style */
    U8 size;       /* font size */
    U8 color;      /* font color */
    U8 type;       /* font type */
    U8 oblique;    /* oblique style */
    U8 smallCaps;  /* smallCaps style */
} stFontAttribute;

/* font engine show string struct */
typedef struct
{
    S32 x;               /* Top left x coordinate */
    S32 y;               /* Top left y coordinate */ 
    S32 char_gap;        /* Gap between each character */
    U8 *String;          /* string point */
    S32 len;             /* string length */
    U32 BaseLineHeight;  /* string base line */
    U32 Bordered;        /* show border or not */
    MMI_BOOL enable_truncated; /* truncate or not */
    U8 *truncated_symbol;      /* truncate symbol, like "..."*/
    S32 truncated_width; /* truncated width */
    U8 assign_direction; /* assign direction */
    U32 render_flag;     /* render flag */
}mmi_fe_showstring_info_struct, *mmi_fe_showstring_info_struct_p;

typedef struct mmi_fe_text_format_struct
{
    S32 start, end;
    stFontAttribute font;
    mmi_fe_color c;
    struct mmi_fe_text_format_struct *next;
}mmi_fe_text_format_struct, *mmi_fe_text_format_struct_p;

/* font engine get string info param struct */
typedef struct
{
    U8 *String;   /* String pointer */
    S32 w;        /* gap between character */
    S32 n;        /* character counter to query */
    S32 pWidth;   /* string width */
    S32 pHeight;  /* string height */
    MMI_BOOL enableTruncated; /* truncate or not */
    S32 targetWidth;          /* target width */
    U8 checklinebreak;        /* if need to check new line symbol */
    U8 checkCompleteWord;     /* word wrap or not*/
    S32 baseline;             /* base line */
    S32 maxAscent;            /* max ascent */
    S32 maxDescent;           /* max descent */
    S32 adv_w;                /* advance width */
    S32 adv_h;                /* advance height */
    U8 assign_direction; /* assign direction */
    mmi_fe_text_format_struct_p format;
}mmi_fe_get_string_info_param_struct, *mmi_fe_get_string_info_param_struct_p;

typedef struct
{
    PU8 string;    /* string buffer */
    S32 len;       /* len of the string */
    S32 subarray_start : 16; /* the start index of the string */
    S32 subarray_len : 16;   /* the lenght of the show segment */
    S32 x;                   /* x position */     
    S32 y;                   /* y position */
    S32 baseline;            /* baseline */
    U8 bordered;             /* bordered or not */
    U8 langid;               /* language id */
} mmi_fe_show_one_cluster_param_struct, *mmi_fe_show_one_cluster_param_struct_p;

typedef struct
{
    S16 ascent;   /* glyph ascent */
    S16 descent;  /* glyph descent */
    S16 adv_x;    /* glyph DWidth */
    U16 width;    /* the font image width. It is considered with font attribute. */
    U16 height;   /* the font imag height. It is considered with font attribute. */
}mmi_fe_glyph_metrics_struct, *mmi_fe_glyph_metrics_struct_p;

typedef struct
{
    U32 index;    /* cluster index in text buffer */
    S32 x;        /* cluster x position */
    U8 len;       /* Cluster length */
    U8 width;     /* cluster width. */
    U8 adv_w;     /* cluster adv_w. */
    U8 bidi_type;  /* is arabic char */
}mmi_fe_cluster_metrics_struct, *mmi_fe_cluster_metrics_struct_p;

typedef void (*fe_save_cluster_info_cb) (mmi_fe_cluster_metrics_struct metric, void *user_data);

/* for R2L characters */
typedef struct stL2RLangSSC
{
    S8 *sscString;    /* SSC string */
} L2RLangSSC;

typedef enum
{
    MMI_FE_ALIGN_BOTTOM,
    MMI_FE_ALIGN_CENTER,
    MMI_FE_ALIGN_TOP
} mmi_fe_align_type;

typedef enum
{
    MMI_FE_ELLIPSIS_TAIL,     /* ellipsis from tail, ex: ABCDEFG  -> ABCD... */
    MMI_FE_ELLIPSIS_MIDDLE,   /* ellipsis from tail, ex: ABCDEFG  -> AB...FG */
    MMI_FE_ELLIPSIS_END
} mmi_fe_ellipsis_type;

typedef enum
{
    MMI_FONT_ENGINE_NO_ERROR = 0,
    MMI_FONT_ENGINE_NO_TRUNCATION,
    MMI_FONT_ENGINE_TRUNCATION,
    MMI_FONT_ENGINE_ERROR_NULL_STRING,
    MMI_FONT_ENGINE_ZERO_LENGTH,
    MMI_FONT_ENGINE_ERROR_NO_TRUNCATION_AVAILABLE,
    MMI_FONT_ENGINE_END_OF_ENUM
} mmi_font_engine_error_message_enum;

#ifndef LOW_COST_SUPPORT
#define __MMI_FONT_CACHE_SUPPORT__
#else
#define __FONT_ENGINE_SLIM__
#endif

#ifdef __MMI_FONT_CACHE_SUPPORT__
#define LATIN_CHAR_HT_SIZE 		128
#define LATIN_CHAR_HT_MASK		0x007f
#define OTHERS_CHAR_HT_SIZE 	256
#define OTHERS_CHAR_HT_MASK		0x00ff
#else
#define LATIN_CHAR_HT_SIZE 		2
#define LATIN_CHAR_HT_MASK		0x0001
#define OTHERS_CHAR_HT_SIZE 	2
#define OTHERS_CHAR_HT_MASK		0x0001
#endif

/* Char cache hash table */
typedef struct
{
    U32 gnCurrentFont; /* current font */
    U32 unicode;   /* char unicode */
    U16 Width;     /* char width */
    U16 Height;    /* char height */
    U16 Ascent;    /* char ascent */
    U16 Descent;   /* char descent */
    U8 *CharData;  /* char raw data */
    U32 NumChar;   /* char data bytes */
    S32 index;     /* char index */
    U16 DWidth;    /* char DWidth */
    U8 count;      /* char count */
} CharHashTable;

#if defined(__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__)
typedef struct
{
    FS_HANDLE handle;
    U16 res_id;
}mmi_preload_font_struct;
#endif

    /* --------------------------- Public Functions and Variables ------------------------- */

    /* DOM-NOT_FOR_SDK-BEGIN */
  
    /*****************************************************************************
     * FUNCTION
     *  TestDiffFonts
     * DESCRIPTION
     *  To test the different fonts with diferent sizes.
     *  This is used to test the different fonts with diferent sizes.
     * PARAMETERS
     *  void
     * RETURNS
     *  void
     *****************************************************************************/
    extern void TestDiffFonts(void);

    /* -------------------------- Private Functions and Variables ------------------------- */

    /* Public functions                                        */

     /*****************************************************************************
     * FUNCTION
     *  mmi_fe_init
     * DESCRIPTION
     *  Init font engine.
     *  Internal use
     * PARAMETERS
     *  void
     * RETURNS
     *  void
     *****************************************************************************/
    extern void mmi_fe_init(void);

/* DOM-NOT_FOR_SDK-END */

    /**************************************************************
    * FUNCTION 
    *  Get_CharBoundingBox()
    * Description
    *  To get the bounding box of "drawn area" of a character.
    *     1. It does not handle Hindi properly.
    *     2. The function is slow because it process internal font data.
    *     3. This function can be used to align a character in a better way because the "drawn area" is aligned
    *         differently for different font database.
    * PARAMETERS
    *  Ch              : [IN] The character ucs2 code.
    *  pCharWidth      : [OUT] Width of character.
    *  pCharHeight     : [OUT] Height of character.
    *  pBoxXoffset     : [OUT] X offset of the bounding box of drawn area relative to the top-left corner.
    *  pBoxYoffset     : [OUT] Y offset of the bounding box of drawn area  relative to the top-left corner.
    *  pBoxWidth       : [OUT] Width of the bounding box of drawn area. 
    *  pBoxHeight      : [OUT] Height of the bounding box of drawn area. 
    * RETURNS
    *  void
    **************************************************************/
    extern void Get_CharBoundingBox(
                    U32 Ch,
                    S32 *pCharWidth,
                    S32 *pCharHeight,
                    S32 *pBoxXoffset,
                    S32 *pBoxYoffset,
                    S32 *pBoxWidth,
                    S32 *pBoxHeight);

    /*****************************************************************************
     * FUNCTION
     *  Get_CharNumInWidth
     * DESCRIPTION
     *  To get char number in specified width.
     *  This function only works for non-complicated language.
     *  Complicated language is include Arabic series, Indic series, Thai and Vietnamese language.
     *  It means that the language process is not processed in the function.
     * PARAMETERS
     *  String             : [IN] The string content.        
     *  width              : [IN] The specifed width to display the string.       
     *  checklinebreak     : [IN] To check line break or not.       
     * RETURNS
     *  The number of character could be displayed in the specified width.
     *****************************************************************************/
    extern U32 Get_CharNumInWidth(U8 *String, U32 width, U8 checklinebreak);

    /*****************************************************************************
     * FUNCTION
     *  Get_CharNumInWidth_w
     * DESCRIPTION
     *  To get char number in specified width, gap and font effect feature.
     *  This function only work for non-complicated language. 
     *  Complicated language is include Arabic series, Indic series, Thai and Vietnamese language.
     *  It means that the language process is not processed in the function.
     * PARAMETERS
     *  String            : [IN] The string content.        
     *  width             : [IN] The specifed width to display the string.       
     *  checklinebreak    : [IN] To check line break or not.       
     *  gap               : [IN] The gap between each character.  
     * RETURNS
     *  The number of character could be displayed in the specified width.
     *****************************************************************************/
    extern U32 Get_CharNumInWidth_w(U8 *String, U32 width, U8 checklinebreak, U32 gap);

    /*****************************************************************************
     * FUNCTION
     *  Get_CharNumInWidth_internal
     * DESCRIPTION
     *  To get char number in specified width and gap.
     *  This function only work for non-complicated language. 
     *  Complicated language is include Arabic series, Indic series, Thai and Vietnamese language.
     *  It means that the language process is not processed in the function.
     * PARAMETERS
     *  String             : [IN] The string content.        
     *  width              : [IN] The specifed width to display the string.       
     *  checklinebreak     : [IN] To check line break or not.       
     *  gap                : [IN] The gap between each character.  
     * RETURNS
     *  The number of character could be displayed in the specified width.
     *****************************************************************************/
    extern U32 Get_CharNumInWidth_internal(U8 *String, U32 width, U8 checklinebreak, U32 gap);

    /*****************************************************************************
     * FUNCTION
     *  Get_CharWidthHeight
     * DESCRIPTION
     *  To get char width and height. 
     *  The font attribute is not considered as the propriety to influence the return value.
     *  Before using the API, please setup font.
     * PARAMETERS
     *  Ch              : [IN]     The character.
     *  pWidth          : [OUT]    The character width. If the character is non-India character, the width would be returned. 
     *                             Othrewise, the dwidth (advance width) would be returned.  
     *  pHeight         : [OUT]    The height of the character.
     * RETURNS
     *  void
    *****************************************************************************/
    extern void Get_CharWidthHeight(U32 Ch, S32 *pWidth, S32 *pHeight);

    /*****************************************************************************
     * FUNCTION
     *  Get_CharHeight
     * DESCRIPTION
     *  To get char height with current selected Font and font size.
     *  Font means a collection of char glyph that can be used to display or print text.
     * PARAMETERS
     *  void
     * RETURNS
     *  S32    the char height.
     *****************************************************************************/
    extern S32 Get_CharHeight(void);

    /*****************************************************************************
     * FUNCTION
     *  Get_CharAscent
     * DESCRIPTION
     *  To get char ascent with current selected Font and font size.
     *  Font means a collection of char glyph that can be used to display or print text.
     * PARAMETERS
     *  void
     * RETURNS
     *  S32  the ascent for the char.
     *****************************************************************************/
    extern S32 Get_CharAscent(void);

    /*****************************************************************************
     * FUNCTION
     *  Get_CharDescent
     * DESCRIPTION
     *  To get char descent with current selected Font and font size.
     *  Font means a collection of char glyph that can be used to display or print text.
     * PARAMETERS
     *  void
     * RETURNS
     *  S32  the descent for the char.
     *****************************************************************************/
    extern S32 Get_CharDescent(void);
    
    
    /*****************************************************************************
     * FUNCTION
     *  Get_CharHeightOfAllLang
     * DESCRIPTION
     *  To get maximum char height in all languages supported by current system with font size.
     *  This function is not include with font attributes except for font effect features.
     * PARAMETERS
     *  size        : [IN]        The font size.
     * RETURNS
     *  S32  the char height.
     *****************************************************************************/
    extern S32 Get_CharHeightOfAllLang(U8 size);

    /*****************************************************************************
     * FUNCTION
     *  Get_StringWidthHeight
     * DESCRIPTION
     *  To get string width and height. 
     *  The bordered attribute is not considered as an attribute to influence the string width & height.
     * PARAMETERS
     *  String      : [IN]         The string content.
     *  pWidth      : [OUT]        The string width.         
     *  pHeight     : [OUT]        The string height.    
     * RETURNS
     *  void
     *****************************************************************************/
    extern void Get_StringWidthHeight(U8 *String, S32 *pWidth, S32 *pHeight);


    /*****************************************************************************
     * FUNCTION
     *  Get_StringWidthHeight_n
     * DESCRIPTION
     *  To get string width and height with a given number of characters.
     * PARAMETERS
     *  String       : [IN]   The string content.        
     *  n            : [IN]   The given number of characters.     
     *  pWidth       : [OUT]  The string width.      
     *  pHeight      : [OUT]  The string height.      
     * RETURNS
     *  void
     *****************************************************************************/
    extern void Get_StringWidthHeight_n(U8 *String, S32 n, S32 *pWidth, S32 *pHeight);

    /*****************************************************************************
     * FUNCTION
     *  Get_StringWidthHeight_w
     * DESCRIPTION
     *  To get string width and height with the given gap.
     * PARAMETERS
     *  String       : [IN]   The string content.        
     *  w            : [IN]   The gap between each character.     
     *  pWidth       : [OUT]  The string width.      
     *  pHeight      : [OUT]  The string height.      
     * RETURNS
     *  void
     *****************************************************************************/
    extern void Get_StringWidthHeight_w(U8 *String, S32 w, S32 *pWidth, S32 *pHeight);

    /*****************************************************************************
     * FUNCTION
     *  Get_Current_Lang_CountryCode
     * DESCRIPTION
     *  To get current language's country code.
     *  This is used to get current language's country code.
     * PARAMETERS
     *  void
     * RETURNS
     *  Current language country code.
     *****************************************************************************/
    extern U8 *Get_Current_Lang_CountryCode(void);

    /*****************************************************************************
     * FUNCTION
     *  Get_CharDisplayHeightOfAllLangAndType
     * DESCRIPTION
     *  To get maximum char height in all languages with font size.
     *  This function assumes that all font attributes is set. 
     *  All languages means the languages which supported by current system.
     * PARAMETERS
     *  size       : [IN]   The font size.     
     * RETURNS
     *  S32  the height.
     *****************************************************************************/
    extern S32 Get_CharDisplayHeightOfAllLangAndType(U8 size);

    /*****************************************************************************
     * FUNCTION
     *  Get_CharDisplayHeightOfAllLangAndType
     * DESCRIPTION
     *  To get maximum char ascent in all languages and all font attributes with current font size.
     *  This function assumes that all font attributes is set, except that font effect feature.
     * PARAMETERS
     *  void
     * RETURNS
     *  S32  the ascent.
     *****************************************************************************/
    extern S32 Get_CharDisplayAscentOfAllType(void);

    /*****************************************************************************
     * FUNCTION
     *  Get_CharDisplayHeightOfAllLangAndType
     * DESCRIPTION
     *  To get maximum char descent in all languages and all font attributes with current font size. 
     *  This function assumes that all font attributes is set, except the font effect feature. 
     * PARAMETERS
     *  void
     * RETURNS
     *  S32  the descent.
     *****************************************************************************/
    extern S32 Get_CharDisplayDescentOfAllType(void);

    /*****************************************************************************
     * FUNCTION
     *  Get_CharDisplayHeightofAllType
     * DESCRIPTION
     *  To get char height of current selected Font with all font attributes with current font size.
     *  This function assumes that all font attributes is set.
     * PARAMETERS
     *  void
     * RETURNS
     *  S32 the height.
     *****************************************************************************/
    extern S32 Get_CharDisplayHeightofAllType(void);

    /*****************************************************************************
     * FUNCTION
     *  Get_StringWidthHeight_multitap
     * DESCRIPTION
     *  To get the multitap string width and height.
     *  The language process would not applied in the string. 
     *  We consider each character as a separate character to query its parameters.
     * PARAMETERS
     *  String      : [IN]      The string content.    
     *  w           : [IN]      The gap between each character.  
     *  pWidth      : [OUT]     The string width.       
     *  pHeight     : [OUT]     The string height.       
     * RETURNS
     *  void
     *****************************************************************************/
    extern void Get_StringWidthHeight_multitap(U8 *String, S32 w, S32 *pWidth, S32 *pHeight);

    /*****************************************************************************
     * FUNCTION
     *  Get_StringWidthHeight_variant
     * DESCRIPTION
     *  To get string width, height and how many character could be displayed in the spefied width with a given number of characters and the given gap between each character.
     * PARAMETERS
     *  string                    : [IN]    The string content.     
     *  w                         : [IN]    The gap between each character.     
     *  n                         : [IN]    The given number of characters.     
     *  pWidth                    : [OUT]   The string width.      
     *  pHeight                   : [OUT]   The string height. 
     *  max_width                 : [IN]    The specified width to display the string.
     *  checkLineBreak            : [IN]    To indicate if the line break character should be considered as an end.
     *  checkCompleteWord         : [IN]    To indicate if the complete word should be considered.
     * RETURNS
     *  U32 how many characters is counted.
     *****************************************************************************/
    extern U32 Get_StringWidthHeight_variant(U8 *string, S32 w, S32 n, S32 *pWidth, S32 *pHeight, S32 max_width, U8 checkLineBreak, U8 checkCompleteWord);

    /*****************************************************************************
     * FUNCTION
     *  Get_StringWidthHeight_wn
     * DESCRIPTION
     *  To get string widths and height with a given number of characters and the given gap between each character.
     * PARAMETERS
     *  String       : [IN]      The string content.     
     *  w            : [IN]      The gap between each character.     
     *  n            : [IN]      The given number of characters.     
     *  pWidth       : [OUT]     The string width.      
     *  pHeight      : [OUT]     The string height.      
     * RETURNS
     *  void
     *****************************************************************************/
    extern void Get_StringWidthHeight_wn(U8 *String, S32 w, S32 n, S32 *pWidth, S32 *pHeight);

    /*****************************************************************************
     * FUNCTION
     *  Get_StringHeight
     * DESCRIPTION
     *  To get Font max height  with current selected font size.
     * PARAMETERS
     *  void
     * RETURNS
     *  S32  the string height.
     *****************************************************************************/
    extern S32 Get_StringHeight(void);

    

    /*****************************************************************************
     * FUNCTION
     *  SetFont
     * DESCRIPTION
     *  To set the font.  
     *  This is used to set all different type of font and different sizes.
     * PARAMETERS
     *  Font           : [IN] The font attribute.        
     *  arrCount       : [IN] The font family.       
     * RETURNS
     *  Not used, always 0.
     *****************************************************************************/
    extern U8 SetFont(stFontAttribute Font, U8 arrCount);

    /*****************************************************************************
     * FUNCTION
     *  GetFont
     * DESCRIPTION
     *  To get the current font.
     *  This is used to get current font attributes.
     * PARAMETERS
     *  Font           : [IN/OUT]        Font attribute.
     *  arrCount       : [IN/OUT]        Fhe font family.
     * RETURNS
     *  void
     *****************************************************************************/
    extern void GetFont(stFontAttribute *Font, U8* arrCount);

    #define ShowString(X,Y,DUMMY_FONT,BACKGROUND,STRING,LINEHEIGHT)                                         mmi_fe_show_string_ext(X,Y,STRING)
    #define ShowString_n(X,Y,DUMMY_FONT,BACKGROUND,STRING,LEN,LINEHEIGHT)                                   mmi_fe_show_string_n(X,Y,STRING,LEN)
    #define ShowStringBordered(X,Y,DUMMY_FONT,BACKGROUND,STRING,LINEHEIGHT)                                            mmi_fe_show_string_bordered(X,Y,STRING)        
    #define ShowStringBordered_n(X,Y,DUMMY_FONT,BACKGROUND,STRING,LEN,LINEHEIGHT)                                      mmi_fe_show_string_bordered_n(X,Y,STRING,LEN)        
    #define ShowString_baseline(X,Y,DUMMY_FONT,BACKGROUND,STRING,BASELINE,DEFAULT_DIR,LINEHEIGHT)           mmi_fe_show_string_baseline(X,Y,STRING,BASELINE,DEFAULT_DIR)
    #define ShowStringBordered_baseline(X,Y,DUMMY_FONT,BACKGROUND,STRING,BASELINE,DEFAULT_DIR,LINEHEIGHT)   mmi_fe_show_string_bordered_baseline(X,Y,STRING,BASELINE,DEFAULT_DIR)
    #define ShowString_by_direction(X,Y,DUMMY_FONT,BACKGROUND,STRING,LINEHEIGHT,DEFAULT_DIR)                mmi_fe_show_string_by_direction(X,Y,STRING,DEFAULT_DIR)
    #define ShowStringBordered_by_direction(X,Y,DUMMY_FONT,BACKGROUND,STRING,LINEHEIGHT,DEFAULT_DIR)        mmi_fe_show_string_bordered_by_direction(X,Y,STRING,DEFAULT_DIR)
    #define ShowString_n_baseline(X, Y, DUMMY_FONT, BACKGROUND, STRING, LEN, BASELINE) mmi_fe_show_string_n_baseline((X), (Y), (STRING), (LEN), (BASELINE))


    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_show_string_ext
     * DESCRIPTION
     *  To display a string by x,y position. The simplest version of show string.
     * PARAMETERS
     *  x              : [IN]      X coordinate.  
     *  y              : [IN]      Y coordinate.
     *  String         : [IN]      String.
     * RETURNS
     *  The number of character been showed.
     *****************************************************************************/
    extern U32 mmi_fe_show_string_ext(S32 x, S32 y, U8 *String);


    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_show_char_at_xy
     * DESCRIPTION
     *  To display the character at a specifed position. 
     *  Rendering rule would not be considered to adjuest the x, y position.
     * PARAMETERS
     *  x:       [IN]  The x position.
     *  y:       [IN]  The y position.
     *  ch:      [IN]  The specified character.
     * RETURNS
     *  void
     *****************************************************************************/
    extern void mmi_fe_show_char_at_xy(S32 x, S32 y, U16 ch);


    

    /*****************************************************************************
    * FUNCTION
    *  mmi_fe_show_string
    * DESCRIPTION
    *  To display string in the screen.
    * PARAMETERS
    *  param                  : [IN]        The input parameter for string display.
    * RETURNS
    *  UNIT32  how many character is diaplyed.
    *****************************************************************************/
    extern U32 mmi_fe_show_string(mmi_fe_showstring_info_struct_p param);
    

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_show_string_n_baseline
     * DESCRIPTION
     *  To display a string by the assigned baseline and assigned string length.
     * PARAMETERS
     *  x_unsigned        : [IN]         X coordinate.   
     *  y_unsigned        : [IN]         Y coordinate.     
     *  String            : [IN]         String.
     *  Len               : [IN]         String length to show. You can set this argument to -1 if you wish to show the whole string.
     *  baseline          : [IN]         String baseline.
     * RETURNS
     *  U32 The number of character been showed.
     *****************************************************************************/
    extern U32  mmi_fe_show_string_n_baseline(
            U32 x_unsigned,
            U32 y_unsigned,
            U8 *String,
            S32 Len,
            S32 baseline);

    
    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_show_string_bordered_n_baseline
     * DESCRIPTION
     *  To display a string with border by the assigned baseline and assigned string length.
     * PARAMETERS
     *  x_unsigned        : [IN]         X coordinate.   
     *  y_unsigned        : [IN]         Y coordinate.     
     *  String            : [IN]         String.
     *  Len               : [IN]         String length to show.
     *  baseline          : [IN]         String baseline.
     * RETURNS
     *  S32 The number of character been showed.
     *****************************************************************************/
    extern U32  mmi_fe_show_string_bordered_n_baseline(
            U32 x_unsigned,
            U32 y_unsigned,
            U8 *String,
            S32 Len,
            S32 baseline);


    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_show_string_n
     * DESCRIPTION
     *  To display a string by the assigned baseline and assigned string length.
     * PARAMETERS
     *  x_unsigned        : [IN]         X coordinate.   
     *  y_unsigned        : [IN]         Y coordinate.     
     *  String            : [IN]         String.
     *  Len               : [IN]         String length to show.      
     * RETURNS
     *  The number of character been showed.
     *****************************************************************************/
    extern U32 mmi_fe_show_string_n(
                U32 x_unsigned,
                U32 y_unsigned,
                U8 *String,
                int Len);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_show_string_bordered
     * DESCRIPTION
     *  To display string with  bordered attribute.
     * PARAMETERS
     *  x              : [IN]      X coordinate.  
     *  y              : [IN]      Y coordinate.
     *  String         : [IN]      String.
     * RETURNS
     *  The number of character been showed.
     *****************************************************************************/
    extern U32 mmi_fe_show_string_bordered(S32 x, S32 y, U8 *String);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_show_string_bordered_n
     * DESCRIPTION
     *  To display a bordered string by assigned string length.  
     * PARAMETERS
     *  x_unsigned        : [IN]         X coordinate.   
     *  y_unsigned        : [IN]         Y coordinate.     
     *  String            : [IN]         String.
     *  Len               : [IN]         String length to show.      
     * RETURNS
     *  The number of character been showed.
     *****************************************************************************/
    extern U32 mmi_fe_show_string_bordered_n(
                U32 x_unsigned,
                U32 y_unsigned,
                U8 *String,
                int Len);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_show_string_baseline
     * DESCRIPTION
     *  To display a string by the assigned baseline.
     * PARAMETERS
     *  x                 : [IN]         X coordinate.   
     *  y                 : [IN]         Y coordinate.     
     *  String            : [IN]         String.
     *  baseline          : [IN]         String baseline.
     *  default_direction : [IN]         The direction to read the string (R2L or L2R)
     * RETURNS
     *  The number of character been showed.
     *****************************************************************************/
    extern U32 mmi_fe_show_string_baseline(S32 x, S32 y, U8 *String, S32 baseline, U8 default_direction);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_show_string_bordered_baseline
     * DESCRIPTION
     *  To display a bordered string by the assigned baseline.
     * PARAMETERS
     *  x                 : [IN]         X coordinate.   
     *  y                 : [IN]         Y coordinate.     
     *  String            : [IN]         String.
     *  baseline          : [IN]         String baseline.
     *  default_direction : [IN]         The direction to read the string (R2L or L2R)
     * RETURNS
     *  The number of character been showed.
     *****************************************************************************/
    extern U32 mmi_fe_show_string_bordered_baseline(S32 x, S32 y, U8 *String, S32 baseline, U8 default_direction);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_show_string_by_direction
     * DESCRIPTION
     *  To display a string by the assigned direction.
     * PARAMETERS
     *  x                 : [IN]         X coordinate.   
     *  y                 : [IN]         Y coordinate.     
     *  String            : [IN]         String.
     *  default_direction : [IN]         The direction to read the string (R2L or L2R)
     * RETURNS
     *  The number of character been showed.
     *****************************************************************************/
    extern U32 mmi_fe_show_string_by_direction(S32 x, S32 y, U8 *String, U8 default_direction);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_show_string_bordered_by_direction
     * DESCRIPTION
     *  To display a bordered string by the assigned direction.
     * PARAMETERS
     *  x                 : [IN]         X coordinate.   
     *  y                 : [IN]         Y coordinate.     
     *  String            : [IN]         String.
     *  default_direction : [IN]         The direction to read the string (R2L or L2R)
     * RETURNS
     *  The number of character been showed. 
     *****************************************************************************/
    extern U32 mmi_fe_show_string_bordered_by_direction(S32 x, S32 y, U8 *String, U8 default_direction);

    /*****************************************************************************
     * FUNCTION
     *  Get_FontHeight
     * DESCRIPTION
     *  Get font height by assigned font and current language index.
     *  Not used
     * PARAMETERS
     *  Font              : [IN]        Font.
     *  arrCount          : [IN]        Current language index.    
     * RETURNS
     *  Font height.
     *****************************************************************************/
    extern S32 Get_FontHeight(stFontAttribute Font, U8 arrCount);

    /*****************************************************************************
     * FUNCTION
     *  Get_StringLength_InCluster
     * DESCRIPTION
     *  Get the string length in cluster. 
     * PARAMETERS
     *  input_str       : [IN]   String to mesure length.     
     *  len             : [IN]   The character length of string.     
     *  base_len        : [IN]   The base length of string.     
     * RETURNS
     *  The string length according the clusters.
     *****************************************************************************/
    extern U32 Get_StringLength_InCluster(U8* input_str, U32 len, U32 base_len);

    /*****************************************************************************
     * FUNCTION
     *  IsL2RMMIStyle
     * DESCRIPTION
     *  To check if current language should be rendered from R2L or L2R.
     * PARAMETERS
     *  void
     * RETURNS
     *  TRUE or FALSE.
     *****************************************************************************/
    extern BOOL IsL2RMMIStyle(void);

    /*****************************************************************************
     * FUNCTION
     *  mmi_font_engine_show_truncated_text
     * DESCRIPTION
     *  Print truncated text.
     *  If length of text is greater  than screen width then the text is truncated. 
     *  The assign truncated symbol are shown at end of text.
     * PARAMETERS
     *  x                      : [IN]        Start x positoin.
     *  y                      : [IN]        Start Y position.
     *  xwidth                 : [IN]        Width of text in pixels to display. The border width is not included.
     *  st                     : [IN]        Text to display.
     *  truncated_symbol       : [IN]        The truncated symbol, it would be show at the end of text if truncation is necessary.
     *  bordered               : [IN]        To indicate if it is border or not.
     * RETURNS
     *  For checking if the string has been truncated.
     *****************************************************************************/
    extern mmi_font_engine_error_message_enum mmi_font_engine_show_truncated_text(
                S32 x, 
                S32 y,
                S32 xwidth, 
                U8* st, 
                U8* truncated_symbol,
                MMI_BOOL bordered);

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_show_ellipsis_text
 * DESCRIPTION
 *  Print truncated text.
 *  If length of text is greater than screen width then the text is truncated. 
 *  Current we support truncated from middle and from tail according to ellipsis_type.
 * PARAMETERS
 *  x:                       [IN]        Start x positoin.
 *  y:                       [IN]        Start Y position.
 *  xwidth:                  [IN]        Width of text in pixels to display. The border width is not included.
 *  st:                      [IN]        Text to display.
 *  truncated_symbol:        [IN]        The truncated symbol, it would be show at the end of text if truncation is necessary.
 *  bordered:                [IN]        To indicate if it is border or not.
 *  mmi_fe_ellipsis_type:    [IN]        Ellipsis_type.
 * RETURNS
 *  S32                      [OUT]   for checking if the string has been truncated.
 *****************************************************************************/
mmi_font_engine_error_message_enum mmi_fe_show_ellipsis_text(
                                        S32 x, 
                                        S32 y,
                                        S32 xwidth, 
                                        U8 *st, 
                                        U8 *truncated_symbol, 
                                        MMI_BOOL bordered, 
                                        mmi_fe_ellipsis_type ellipsis_type);

    /* DOM-NOT_FOR_SDK-BEGIN */

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_show_ellipsis_text_ext
     * DESCRIPTION
     *  Print ellipsis text
     *  If length of text is greater than screen width then the text is truncated.
     *  Current we support ellipsis from middle and from tail according to ellipsis_type
     * PARAMETERS
     *  x                           [IN]        Start x positoin
     *  y                           [IN]        Start Y position
     *  xwidth                      [IN]        Width of text in pixels to display. The border width is not included.
     *  st                          [IN]        Text to display
     *  truncated_symbol            [IN]        The truncated symbol, it would be show at the end of text if truncation is necessary
     *  bordered                    [IN]        To indicate if it is border or not
     *  ellipsis_type               [IN]        ellipsis type
     *  assigned_baseline           [IN]        assigned baseline, -1 mean use string default base line
     * RETURNS
     *  S32                     [OUT]   for checking if the string has been truncated
     *****************************************************************************/
    extern mmi_font_engine_error_message_enum mmi_fe_show_ellipsis_text_ext(
                                        S32 x,
                                        S32 y,
                                        S32 xwidth,
                                        U8 *st,
                                        U8 *truncated_symbol,
                                        MMI_BOOL bordered,
                                        mmi_fe_ellipsis_type ellipsis_type,
                                        S32 assigned_baseline);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_enable_date_char_display
     * DESCRIPTION
     *  To enable special date character (133~147 0x85~0x93) display. 
     * PARAMETERS
     *  void
     * RETURNS
     *  void
     *****************************************************************************/
    extern void mmi_fe_enable_date_char_display(void);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_disable_date_char_display
     * DESCRIPTION
     *  To disable special date character (133~147 0x85~0x93) display. 
     * PARAMETERS
     *  void
     * RETURNS
     *  void
     *****************************************************************************/
    extern void mmi_fe_disable_date_char_display(void);
    

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_enable_proprietary_symbol_display
     * DESCRIPTION
     *  To enable special CR-LF and SPACE symbol used in symbol table (133~134 0x85~0x86) display. 
     * PARAMETERS
     *  void
     * RETURNS
     *  void
     *****************************************************************************/
    extern void mmi_fe_enable_proprietary_symbol_display(void);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_disable_proprietary_symbol_display
     * DESCRIPTION
     *  To disable special CR-LF and SPACE symbol used in symbol table (133~134 0x85~0x86) display. 
     * PARAMETERS
     *  void
     * RETURNS
     *  void
     *****************************************************************************/
    extern void mmi_fe_disable_proprietary_symbol_display(void);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_enable_ucs2_proprietary_display
     * DESCRIPTION
     *  To enable UCS2 proprietary range (0xE000 - 0xF8FF) 
     * PARAMETERS
     *  void
     * RETURNS
     *  void
     *****************************************************************************/
    extern void mmi_fe_enable_ucs2_proprietary_display(void);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_disable_ucs2_proprietary__display
     * DESCRIPTION
     *  To disable UCS2 proprietary range (0xE000 - 0xF8FF) 
     * PARAMETERS
     *  void
     * RETURNS
     *  void
     *****************************************************************************/
    extern void mmi_fe_disable_ucs2_proprietary_display(void);

    /* DOM-NOT_FOR_SDK-END */

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_measure_string_by_char_num
     * DESCRIPTION
     *  To get string width by the fixed char width.
     *  the fixed char width is count by the max width of the character.
     *  And the string width is the max char width multiple the numofchar.
     *  The characte of Arabic series, Indic series, Thai and Vietnamese language is not allowed
     *  to be the input. 
     * PARAMETERS
     *  numofchar   : [IN]     The number of character of the string.
     *  st          : [IN]     All the character would be displayed as a char in the string. 
     *  width       : [OUT]    The width.
     *  height      : [OUT]    The height.
     * RETURNS
     *  void
     *****************************************************************************/
    extern void mmi_fe_measure_string_by_char_num(U8* st, S32 numofchar, S32* width, S32* height);


    /*****************************************************************************
    * FUNCTION
    *  mmi_fe_get_char_info_of_lang
    * DESCRIPTION
    *  To get maximum char height, ascent and descent for a specifed size and specifed language.
    * PARAMETERS
    *  size       : [IN]       The specified size.
    *  pheight     : [OUT]      The height.
    *  pascent     : [OUT]      The ascent.
    *  pdescent    : [OUT]      The descent.
    * RETURNS
    *  void
    *****************************************************************************/
    MMI_BOOL mmi_fe_get_char_info_of_lang(char *lang_ssc, U8 size, S32* pheight, S32* pascent, S32* pdescent);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_get_char_info_of_all_lang
     * DESCRIPTION
     *  To get maximum char height, ascent and descent for a specifed size regardless of language.
     * PARAMETERS
     *  size       : [IN]       The specified size.
     *  pheight     : [OUT]      The height.
     *  pascent     : [OUT]      The ascent.
     *  pdescent    : [OUT]      The descent.
     * RETURNS
     *  void
     *****************************************************************************/
    extern void mmi_fe_get_char_info_of_all_lang(U8 size, S32* pheight, S32* pascent, S32* pdescent);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_get_char_info_of_simply_lang
     * DESCRIPTION
     *  To get maximum char height, ascent and descent for a simply language (English, SC) with specific font size.
     * PARAMETERS
     *  size            : [IN]    The specified size.
     *  pHeight         : [IN]    Height.         
     *  pAscent         : [IN]    Ascent. 
     *  pDescent        : [IN]    Descent. 
     * RETURNS
     *  void
     *****************************************************************************/
    extern void mmi_fe_get_char_info_of_simply_lang(U8 size, S32 *pHeight, S32 *pAscent, S32 *pDescent);


/* DOM-NOT_FOR_SDK-BEGIN */

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_get_char_info_of_common_lang
     * DESCRIPTION
     *  To get maximum char height, ascent and descent for a specifed size of common language.
     * PARAMETERS
     *  size       : [IN]       The specified size.
     *  pheight     : [OUT]      The height.
     *  pascent     : [OUT]      The ascent.
     *  pdescent    : [OUT]      The descent.
     * RETURNS
     *  void
     *****************************************************************************/
    extern void mmi_fe_get_char_info_of_common_lang(U8 size, S32* pheight, S32* pascent, S32* pdescent);

/* DOM-NOT_FOR_SDK-END */


    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_check_string
     * DESCRIPTION
     *  To check the input string if the first character is supported in current font configuration.
     * PARAMETERS
     *  font                   : [IN]       Font.    
     *  string                 : [IN]       The desired string.
     *  len                    : [IN]       The first len character should be checked.
     * RETURNS
     *  MMI_BOOL           the validness of the string.
     *****************************************************************************/
    extern MMI_BOOL mmi_fe_check_string(stFontAttribute font, U8* string, S32 len);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_get_string_widthheight
     * DESCRIPTION
     *  To get string width height.
     * PARAMETERS
     *  query      : [IN/OUT]    The query parameter to indicate the input and output.
     * RETURNS
     *  U32   how many characters is counted.
     *****************************************************************************/
    extern U32 mmi_fe_get_string_widthheight(mmi_fe_get_string_info_param_struct_p query);


    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_get_glyph_metrics
     * DESCRIPTION
     *  This is used to get the glyph metrics for a sepcified character. 
     *  The font metrics is considered with font attribute.
     *  The caller to use this API should get GDI lock first for thread safe in font engine.
     * PARAMETERS
     *  ch                  : [IN]      The ucs2 code for the character.      
     *  matrix              : [OUT]     The metrics of the char.        
     * RETURNS
     *  MMI_BOOL to indicate if the character is valid or not. If it is invalid character, the metrics info is the info for nil character.
     *****************************************************************************/
    extern MMI_BOOL mmi_fe_get_glyph_metrics(U16 ch, mmi_fe_glyph_metrics_struct_p matrix);


    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_show_char_with_bounding_box
     * DESCRIPTION
     *  Show character inside the bounding box with the specified font size.
     * PARAMETERS
     *  x           : [IN]      The x position.
     *  y           : [IN]      The y position.
     *  width       : [IN]      The bounding box width.
     *  height      : [IN]      The bounding box height.
     *  ch          : [IN]      The specified character.
     *  type        : [IN]      Aligh type.
     *  Font        : [IN]      The max font size.
     * RETURNS
     *  void
     *****************************************************************************/
    extern void mmi_fe_show_char_with_bounding_box(S32 x, S32 y, S32 width, S32 height, U16 ch, mmi_fe_align_type type, stFontAttribute Font);

    

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_set_text_color
     * DESCRIPTION
     *  To set text color.
     * PARAMETERS
     *  c         : [IN]      Color.
     * RETURNS
     *  void
     *****************************************************************************/
    extern void mmi_fe_set_text_color(mmi_fe_color c);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_set_text_border_color
     * DESCRIPTION
     *  To set text border color.
     * PARAMETERS
     *  c        : [IN]         Color.
     * RETURNS
     *  void
     *****************************************************************************/
    extern void mmi_fe_set_text_border_color(mmi_fe_color c);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_get_text_color
     * DESCRIPTION
     *  To get text color.
     * PARAMETERS
     *  void
     * RETURNS
     *  Text color.
     *****************************************************************************/
    extern mmi_fe_color mmi_fe_get_text_color(void);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_get_text_border_color
     * DESCRIPTION
     *  To get text border color.
     * PARAMETERS
     *  void
     * RETURNS
     *  Text border color.
     *****************************************************************************/
    extern mmi_fe_color mmi_fe_get_text_border_color(void);


    

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_show_single_cluster
     * DESCRIPTION
     *  To display one cluster. The content should be in its display form.
     * PARAMETERS
     *  param    : [IN]        The parameter for one cluster.
     * RETURNS
     *  void
     *****************************************************************************/
    extern void mmi_fe_show_single_cluster(mmi_fe_show_one_cluster_param_struct_p param);

#ifdef __MMI_VECTOR_FONT_SUPPORT__
    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_set_antialias
     * DESCRIPTION
     *  Set font antialias attributes.
     * PARAMETERS
     *  value         : [IN]     The parameter for one cluster.
     * RETURNS
     *  void
     *****************************************************************************/
    extern void mmi_fe_set_antialias(MMI_BOOL value);
#endif

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_pixel_to_size
     * DESCRIPTION
     *  Convert font pixel count to font size enum. 
     * PARAMETERS
     *  pixel            : [IN]     Pixel.
     * RETURNS
     *  U8 pixel size.
     *****************************************************************************/
    extern U8 mmi_fe_pixel_to_size(U8 pixel);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_is_vector_font_support
     * DESCRIPTION
     *  To check if vector font is supported on the platform.
     * PARAMETERS
     *  void
     * RETURNS
     *  MMI_BOOL. 
     *****************************************************************************/
    extern MMI_BOOL mmi_fe_is_vector_font_support(void);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_is_r2l_state
     * DESCRIPTION
     *  To check if it is on r2l state under current system language.
     * PARAMETERS
     *  void
     * RETURNS
     *  MMI_BOOL. 
     *****************************************************************************/
    extern MMI_BOOL mmi_fe_is_r2l_state(void);
    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_get_r2l_state
     * DESCRIPTION
     *  To get r2l state under current system language
     * PARAMETERS
     *  void
     * RETURNS
     *  MMI_BOOL
     *****************************************************************************/ 
#if defined (__MMI_BIDI_ALG__) 
    extern MMI_BOOL mmi_fe_get_r2l_state(void);
#else
    #define mmi_fe_get_r2l_state()   0
#endif
    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_set_r2l_state
     * DESCRIPTION
     *  To get r2l state under current system language
     * PARAMETERS
     *  void
     * RETURNS
     *  MMI_BOOL
     *****************************************************************************/
    
    extern void mmi_fe_set_r2l_state(MMI_BOOL state);
    
    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_get_char_info
     * DESCRIPTION
     *  To get the font info of the desired character.
     * PARAMETERS
     *  Ch          : [IN]             The unicode of desired character.
     *  pWidth      : [OUT]            The dwidth of the character. If the character is not Indic character. The dwidth is equal to width.
     *  pDwidth     : [OUT]            The width of the ch.
     *  pHeight         :[OUT]            The height of the ch.
     *  Ascent      : [OUT]            The ascent of the ch. You can pass NULL to it if you don't with to use it.
     *  Descent     : [OUT]            The descent of the ch.You can pass NULL to it if you don't with to use it.
     * RETURNS
    *  FE_GLYPH_ATTR_USING_FONT_ENGINE or 0.
    ****************************************************************************/
	extern U32 mmi_fe_get_char_info (U32 Ch, S32 *pWidth, S32 *pDwidth,S32*pHeight, S32 *Ascent, S32 *Descent);

    
    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_get_string_widthheight_ext
     * DESCRIPTION
     *  To get string width height and call callback function to save all cluster information.
     * PARAMETERS
     *  query           : [IN/OUT] The query parameter to indicate the input and output.
     *  direction       : [OUT]    String direction.
     *  f_save_info     : [IN]     Save cluster information function.
     *  user_data       : [OUT]    user defined data passed by application.
     * RETURNS
     *  U32   how many characters is counted.
     *****************************************************************************/
    extern U32 mmi_fe_get_string_widthheight_ext(mmi_fe_get_string_info_param_struct_p query, U8 *direction, fe_save_cluster_info_cb f_save_info, void *user_data);

    /*****************************************************************************
     * FUNCTION
     *  mmi_fe_get_string_direction
     * DESCRIPTION
     *  To get display direction by the content.
     * PARAMETERS
     *  string            : [IN]     The string input.   
     *  len               : [IN]     String length.
     * RETURNS
     *  PMT_BIDI_TYPES.
     *****************************************************************************/
    extern U8 mmi_fe_get_string_direction(U8* string, S32 len);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
     * FUNCTION
     *  IsChineseSet
     * DESCRIPTION
     *  This function checks whether the current language is set as Chinese or not.
     * PARAMETERS
     *  void
     * RETURNS
     *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
     *****************************************************************************/
    extern pBOOL IsChineseSet(void);

    /*****************************************************************************
     * FUNCTION
     *  IsEnglishSet
     * DESCRIPTION
     *  This function checks whether the current language is set as English or not.
     * PARAMETERS
     *  void
     * RETURNS
     *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
     *****************************************************************************/
    extern pBOOL IsEnglishSet(void);

    /*****************************************************************************
     * FUNCTION
     *  IsTrChineseSet
     * DESCRIPTION
     *  This function checks whether the current language is set as traditional.
     *  Chinese or not.
     * PARAMETERS
     *  void
     * RETURNS
     *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
     *****************************************************************************/
    extern pBOOL IsTrChineseSet(void);

    /*****************************************************************************
     * FUNCTION
     *  IsSmChineseSet
     * DESCRIPTION
     *  This function checks whether the current language is set as simplified.
     *  Chinese or not.
     * PARAMETERS
     *  void
     * RETURNS
     *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
     *****************************************************************************/
    extern pBOOL IsSmChineseSet(void);

#ifdef __MMI_VECTOR_FONT_SUPPORT__
extern void mmi_fe_cache_print_all(void);
#endif


#if defined(__MMI_FONT_EFFECTS__)

/*****************************************************************************
 * FUNCTION
 *  addFontEffectAttributeNode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
extern U8 addFontEffectAttributeNode(stFontAttributeNode *attribute_node);


/*****************************************************************************
 * FUNCTION
 *  searchFontEffectAttribute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL removeFontEffectAttributeNode(U8 node_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_init
 * DESCRIPTION
 *  To initalize font engine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fe_init_font_effect_theme(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_init
 * DESCRIPTION
 *  To initalize font engine
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_fe_init_font_effect_theme_ext(void);

#endif /* __MMI_FONT_EFFECTS__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_size_to_pixel
 * DESCRIPTION
 *  Convert the size to pixel
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 mmi_fe_size_to_pixel(U8 size);


/*****************************************************************************
 * FUNCTION
 *  mmi_fe_get_string_widthheight_varient
 * DESCRIPTION
 *  To get string width height
 * PARAMETERS
 *  query       [IN/OUT]        The query parameter to indicate the input and output
 * RETURNS
 *  U32   how many characters is counted.
 *****************************************************************************/
extern U32 mmi_fe_get_string_widthheight_varient(mmi_fe_get_string_info_param_struct_p query);

/*****************************************************************************
 * FUNCTION
 *  mmi_fe_check_single_color_buffer_can_create
 * DESCRIPTION
 *  To check single color buffer can cteate
 * PARAMETERS
 *  border       [IN]        The font is border or not
 * RETURNS
 *  BOOL   buffer can be created or not.
 *****************************************************************************/
extern BOOL mmi_fe_check_single_color_buffer_can_create(BOOL border);

extern void mmi_fe_reset_font_boot_mode(void);

/* DOM-NOT_FOR_SDK-END */


#ifdef __cplusplus
}
#endif 

#endif /* _PIXCOMFONTENGINE_H */


