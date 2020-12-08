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
 *   jui_editor.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements Font adaption APIs
 *
 * Author:
 * -------
 * -------
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
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/*************************************************************************
 * Include header files
 *************************************************************************/
#include "kal_release.h"
#include "FontRes.h"
#include "gdi_include.h"
#include "gui_buttons.h"
#include "wgui_categories_inputs.h"
#include "mmu.h"
#include "cp15.h"
#include "cache_sw.h"

/*************************************************************************
 * Use log string buffer to reduce memory usage
 *************************************************************************/

#include "jal.h"
#include "jal_internal.h"
#include "jvm_internal.h"
#include "jui_interface.h"      /* JUI MVM */
#include "jvm_trace_interface.h"

/* reference point locations, from Graphics.java */
#define HCENTER   1
#define VCENTER   2
#define LEFT      4
#define RIGHT     8
#define TOP      16
#define BOTTOM   32
#define BASELINE 64

/* flags for font descriptors */
#define STYLE_PLAIN         0
#define STYLE_BOLD          1
#define STYLE_ITALIC        2
#define STYLE_UNDERLINED    4

/* flags for line types */
#define SOLID 0
#define DOTTED 1

#define SIZE_SMALL          8
#define SIZE_MEDIUM         0
#define SIZE_LARGE         16

#define FACE_SYSTEM         0
#define FACE_MONOSPACE     32
#define FACE_PROPORTIONAL  64

#define MAX_MIDP_FONT_DISPLAY                128

#ifdef ENABLE_JUI_CACHE_FONT
#define JUI_CACHED_FONT_NUM                  128

#ifdef __MMI_MAINLCD_480X800__
#define CACHED_FONT_WIDTH                     32
#elif  defined(__MMI_VECTOR_FONT_SUPPORT__)
#define CACHED_FONT_WIDTH                     24
#else /* __MMI_VECTOR_FONT_SUPPORT__ */
#define CACHED_FONT_WIDTH                     32
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */
#define CACHED_FONT_NUM                      115
#if defined (__MMI_MAINLCD_128X128__) || defined (__MMI_MAINLCD_128X160__) || defined (__MMI_MAINLCD_176X220__)
#define CACHED_FONT_MAX_HEIGHT               20
#elif defined(__MMI_MAINLCD_480X800__)
#define CACHED_FONT_MAX_HEIGHT               44 
#else
#ifndef __MMI_VECTOR_FONT_SUPPORT__
#define CACHED_FONT_MAX_HEIGHT               28
#else
#define CACHED_FONT_MAX_HEIGHT               30
#endif /* __MMI_VECTOR_FONT_SUPPORT__ */
#endif 
#endif /* ENABLE_JUI_CACHE_FONT */ 

static char jui_text_buffer[MAX_MIDP_FONT_DISPLAY * sizeof(kal_uint16)];


extern void UI_set_current_text_color(color c);
extern void j2me_lcd_mutex_lock(void);
extern void j2me_lcd_mutex_unlock(void);
void jui_string_set_font(stFontAttribute *J2ME_font, kal_int32 face, kal_int32 style, kal_int32 size);

extern kal_uint16 gCurrLangIndex;
extern kal_uint32 gnCurrentFont;
extern const kal_uint16 gMaxDeployedLangs;
extern BOOL r2lMMIFlag;
extern gdi_handle jui_layer_handle;

static kal_uint16 jui_default_font_height = 0;
static kal_uint16 jui_small_font_height = 0;    /* 020207 java font */
static kal_uint16 jui_large_font_height = 0;

void j2me_custom_hw_to_mmi_color(kal_uint32 RGB, kal_int32 alpha, color *c);

void jui_init_cached_font(void);

#ifdef __MMI_VECTOR_FONT_SUPPORT__

#define __SUPPORT_VECTOR_FONT_ALPHA_BIT_4__     /* this should be always open,else need 5 bits to store alpha */
#define __SUPPORT_VECTOR_FONT_MEDIUM_BOLD__     /* need 38KB to store */
// #define __SUPPORT_VECTOR_FONT_SMALL__         //need 38KB to store

#if (CACHED_FONT_WIDTH > 24)
#define WORD_NUM_IN_ONE_LINE    4          /* 32 / (WIDTH / 4 ) */
#else
#define WORD_NUM_IN_ONE_LINE    3          /* 32 / (WIDTH / 4 ) */

#endif /* CACHED_FONT_WIDTH > 24 */
#else

#define __SUPPORT_BITMAP_FONT_MEDIUM_BOLD__

#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 

#ifdef ENABLE_JUI_CACHE_FONT

typedef struct
{
    kal_int32 font_type;
    kal_int32 font_style;
    kal_int32 font_size;
    kal_int32 font_height;

    kal_uint32 *cached_data[JUI_CACHED_FONT_NUM];
    kal_int32 cached_width[JUI_CACHED_FONT_NUM];

    kal_int32 cached_adv_width[JUI_CACHED_FONT_NUM];
    
} jui_cached_font_struct;

jui_cached_font_struct g_jui_cached_font;

#if defined(__SUPPORT_VECTOR_FONT_MEDIUM_BOLD__) || defined(__SUPPORT_BITMAP_FONT_MEDIUM_BOLD__)
jui_cached_font_struct g_jui_cached_bold_font;
#endif /* __SUPPORT_VECTOR_FONT_MEDIUM_BOLD__ */

#ifdef __SUPPORT_VECTOR_FONT_SMALL__
jui_cached_font_struct g_jui_cached_small_font;
#endif /* __SUPPORT_VECTOF_FONT_SMALL__ */

#ifdef __MMI_VECTOR_FONT_SUPPORT__

#ifdef __SUPPORT_VECTOR_FONT_ALPHA_BIT_4__

#define JUI_FONT_BUFFER_SIZE (CACHED_FONT_NUM * CACHED_FONT_MAX_HEIGHT * WORD_NUM_IN_ONE_LINE)

#else /* __SUPPORT_VECTOR_FONT_ALPHA_BIT_4__ */ 

#define JUI_FONT_BUFFER_SIZE (CACHED_FONT_NUM * CACHED_FONT_MAX_HEIGHT * 4/* 6 */)

#endif /* __SUPPORT_VECTOR_FONT_ALPHA_BIT_4__ */ 

#else  /* __MMI_VECTOR_FONT_SUPPORT__ */

#define JUI_FONT_BUFFER_SIZE (CACHED_FONT_NUM * CACHED_FONT_MAX_HEIGHT)

#endif /* __MMI_VECTOR_FONT_SUPPORT__ */


#ifdef __SUPPORT_FONT_MEMORY_FROM_SCREEN_MEMORY__

kal_uint32 * jui_local_cached_data;

#if defined(__SUPPORT_VECTOR_FONT_MEDIUM_BOLD__) || defined(__SUPPORT_BITMAP_FONT_MEDIUM_BOLD__)
kal_uint32 * jui_local_cached_bold_data;
#endif 

#ifdef __SUPPORT_VECTOR_FONT_SMALL__
kal_uint32 *jui_local_cached_small_data;
#endif 

#else /* __SUPPORT_FONT_MEMORY_FROM_SCREEN_MEMORY__ */

kal_uint32 jui_local_cached_data[JUI_FONT_BUFFER_SIZE];

#if defined(__SUPPORT_BITMAP_FONT_MEDIUM_BOLD__) || defined(__SUPPORT_BITMAP_FONT_MEDIUM_BOLD__)
kal_uint32 jui_local_cached_bold_data[JUI_FONT_BUFFER_SIZE];
#endif 

#ifdef __SUPPORT_VECTOR_FONT_SMALL__
kal_uint32 jui_local_cached_small_data[JUI_FONT_BUFFER_SIZE];
#endif 

#endif /* __SUPPORT_FONT_MEMORY_FROM_SCREEN_MEMORY__ */


static kal_bool jui_enable_cached_font = KAL_FALSE;
static kal_bool jui_enable_cached_bold_data = KAL_FALSE; 

kal_bool jui_enable_lazy_cached_font = KAL_FALSE;
kal_bool jui_cached_font_is_initialized = KAL_FALSE;

#endif /* ENABLE_JUI_CACHE_FONT */ 

/*****************************************************************************
 * FUNCTION
 *  jui_string_init_height_int
 * DESCRIPTION
 *  initialize font info.
 * PARAMETERS
 *  J2ME_font       [IN]        
 *  height          [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void jui_string_init_height_int(stFontAttribute J2ME_font, kal_uint16 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 maxAscent = 0, maxDescent = 0, maxHeight = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // MAUI_02239696 
    /*for (i = 0; i < gMaxDeployedLangs; i++)
    {
        SetFont(J2ME_font, (kal_uint8)i);
        tmp = Get_CharAscent();
        if (tmp > maxAscent)
        {
            maxAscent = tmp;
        }
        tmp = Get_CharDescent();
        if (tmp > maxDescent)
        {
            maxDescent = tmp;
        }
    }*/

    /*for (i = 0; i < gMaxDeployedLangs; i++)
    {
        SetFont(J2ME_font, (U8) i);
        tmp = Get_CharDisplayAscentOfAllType();
        if (tmp > maxAscent)
        {
            maxAscent = tmp;
        }
        tmp = Get_CharDisplayDescentOfAllType();
        if (tmp > maxDescent)
        {
            maxDescent = tmp;
        }
    }*/
    mmi_fe_get_char_info_of_all_lang(J2ME_font.size, &maxHeight, &maxAscent, &maxDescent);
    // MAUI_02239696
    *height = maxHeight;
}
/*****************************************************************************
 * FUNCTION
 *  jui_string_init
 * DESCRIPTION
 *  initialize font info.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_string_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stFontAttribute J2ME_font = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    J2ME_font.type = 1;
    J2ME_font.bold = 0;
    J2ME_font.italic = 0;
    J2ME_font.underline = 0;
    J2ME_font.type = 1; /* re assign */
    J2ME_font.oblique = 0;

    J2ME_font.size = MEDIUM_FONT;
    jui_string_init_height_int(J2ME_font, &jui_default_font_height);

    J2ME_font.size = SMALL_FONT;
    jui_string_init_height_int(J2ME_font, &jui_small_font_height);

    J2ME_font.size = LARGE_FONT;
    jui_string_init_height_int(J2ME_font, &jui_large_font_height);

    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_FONT_INIT,jui_small_font_height,jui_default_font_height,jui_large_font_height);
}

#ifdef ENABLE_JUI_CACHE_FONT


/*****************************************************************************
 * FUNCTION
 *  jui_do_alpha_blending
 * DESCRIPTION
 *  draw alpha blending
 * PARAMETERS
 *  dst     [?]         
 *  src     [IN]        
 *  a       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
__inline void jui_do_alpha_blending(kal_uint16 *dst, kal_uint16 src, kal_uint16 a)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    register kal_uint32 temp;
    register kal_uint32 s = src;
    register kal_uint32 d = *dst;
    register kal_uint32 alpha = a;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SUPPORT_VECTOR_FONT_ALPHA_BIT_4__

    temp = (((((((s << 16) | s) & 0x7e0f81f) - (((d << 16) | d) & 0x7e0f81f)) * alpha) >> 4)
            + (((d << 16) | d) & 0x7e0f81f)) & 0x7e0f81f;

#else /* __SUPPORT_VECTOR_FONT_ALPHA_BIT_4__ */ 

    temp = (((((((s << 16) | s) & 0x7e0f81f) - (((d << 16) | d) & 0x7e0f81f)) * alpha) >> 5)
            + (((d << 16) | d) & 0x7e0f81f)) & 0x7e0f81f;

#endif /* __SUPPORT_VECTOR_FONT_ALPHA_BIT_4__ */ 
    s = temp >> 16;             /* rgb-->g */
    d = temp << 16 >> 16;       /* rgb-->rb */
    *dst = (kal_uint16) s | d;  /* rgb */
}


/*****************************************************************************
 * FUNCTION
 *  jui_draw_cached_font
 * DESCRIPTION
 *  draw cached font
 * PARAMETERS
 *  dst                 [?]         
 *  dst_width           [IN]        
 *  dst_height          [IN]        
 *  index               [IN]        
 *  clip                [?]         
 *  dstX                [IN]        
 *  dstY                [IN]        
 *  color               [IN]        
 *  cache_font_ptr      [?]         
 * RETURNS
 *  void
 *****************************************************************************/
__inline void jui_draw_cached_font(
                kal_uint16 *dst,
                kal_int32 dst_width,
                kal_int32 dst_height,
                kal_uint16 index,
                kal_int32 *clip,
                kal_int32 dstX,
                kal_int32 dstY,
                kal_uint16 color,
                jui_cached_font_struct *cache_font_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 w, h, srcXoffset = 0, srcYoffset = 0, width;
    kal_uint32 *srcptr;
    register kal_uint32 srcdata;
    kal_int32 bitcnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dstX > clip[2])
    {
        return;
    }
    if (dstY > clip[3])
    {
        return;
    }

    /* check clip region */
    h = cache_font_ptr->font_height;
    w = *(cache_font_ptr->cached_width + index);
    if (dstX < clip[0])
    {
        if ((dstX + w - 1) < clip[0])
        {
            return;
        }
        if ((dstX + w - 1) > clip[2])
        {
            w = clip[2] - clip[0] + 1;
        }
        else
        {
            w = dstX + w - clip[0];
        }
        srcXoffset = clip[0] - dstX;
        dstX = clip[0];
    }
    else if ((dstX + w - 1) > clip[2])
    {
        w = clip[2] - dstX + 1;
    }

    if (dstY < clip[1])
    {
        if ((dstY + h - 1) < clip[1])
        {
            return;
        }
        if ((dstY + h - 1) > clip[3])
        {
            h = clip[3] - clip[1] + 1;
        }
        else
        {
            h = dstY + h - clip[1];
        }
        srcYoffset = clip[1] - dstY;
        dstY = clip[1];
    }
    else if ((dstY + h - 1) > clip[3])
    {
        h = clip[3] - dstY + 1;
    }

    if (h <= 0)
    {
        return;
    }

    /* check font bit to draw each pixel */
    dst += dstY * dst_width + dstX;

#ifndef __MMI_VECTOR_FONT_SUPPORT__
    srcptr = cache_font_ptr->cached_data[index] + srcYoffset;
    bitcnt = srcXoffset;

    do
    {
        srcdata = *srcptr++;
        if (srcdata)
        {
            width = w;
            /* check two bits */
            while (width >= 2)
            {
                width -= 2;
                switch ((srcdata & (0x3 << (bitcnt + width))) >> (bitcnt + width))
                {
                    case 0x3:
                        *(dst + width) = color;
                        *(dst + 1 + width) = color;
                        break;
                    case 0x2:
                        *(dst + 1 + width) = color;
                        break;
                    case 0x1:
                        *(dst + width) = color;
                        break;
                    default:
                        break;
                }
            }

            /* check one bit if exist */
            if (width > 0)
            {
                if (srcdata & (1 << bitcnt))
                {
                    *dst = color;
                }
            }
        }
        dst += dst_width;
    } while (--h != 0);

#else /* __MMI_VECTOR_FONT_SUPPORT__ */ 

#ifdef __SUPPORT_VECTOR_FONT_ALPHA_BIT_4__

    srcptr = cache_font_ptr->cached_data[index] + srcYoffset * WORD_NUM_IN_ONE_LINE /*(srcYoffset << 1) + srcYoffset*/;
    while (h > 0)
    {
        width = srcXoffset;
        bitcnt = 0;

        while(bitcnt < w)
        {
            srcdata = srcptr[width >> 3];
            if (srcdata != 0)
            {
                srcdata = (srcdata >> ((width % 8) << 2)) & 0x0F;
                if (srcdata == 0x0F)
                    *(dst+bitcnt) = color;
                else if (srcdata != 0)
                    jui_do_alpha_blending(dst+bitcnt,color,(kal_uint16)(srcdata));
            }
            bitcnt++;
            width++;
        }
        srcptr = srcptr +  WORD_NUM_IN_ONE_LINE;
        dst += dst_width;
        h--;
    }

#else /* __SUPPORT_VECTOR_FONT_ALPHA_BIT_4__ */ 

    srcptr = cache_font_ptr->cached_data[index] + srcYoffset << 2;
    while (h > 0)
    {
        width = srcXoffset;
        bitcnt = 0;

        while(bitcnt < w)
        {
            srcdata = srcptr[width / 6];
            if (srcdata != 0)
            {
                srcdata = (srcdata >> ((width % 6) * 5)) & 0x1F;
                if(srcdata == 0x0F)
                    *(dst+bitcnt) = color;
                else if(srcdata != 0)
                    jui_do_alpha_blending(dst+bitcnt,color,(kal_uint16)srcdata);
            }

            bitcnt ++;
            width++;
        }
        srcptr = srcptr + /* 6 */ 4;
        dst += dst_width;
        h--;
    }
#endif /* __SUPPORT_VECTOR_FONT_ALPHA_BIT_4__ */ 

#endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 
}

#ifdef J2ME_SLIM_MEMORY_SUPPORT
extern void* jui_widget_mvm_gditempmemory_allocate(kal_int32 size);
extern void  jui_widget_mvm_gditempmemory_free(void* buffer);
#endif

/*****************************************************************************
 * FUNCTION
 *  jui_init_cached_font_internal
 * DESCRIPTION
 *  initialize font info.
 * PARAMETERS
 *  cache_font_ptr      [?]         
 *  cached_data         [?]         
 *  font_type           [IN]        
 *  font_style          [IN]        
 *  font_size           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool jui_init_cached_font_internal(
                jui_cached_font_struct *cache_font_ptr,
                kal_uint32 *cached_data,
                kal_int32 font_type,
                kal_int32 font_style,
                kal_int32 font_size)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 i;
    kal_uint16 s[2] = {0, 0};
    kal_int32 h, font_ascent, font_descent, font_leading;
    kal_int32 maxWidth = 0;
    kal_bool is_space;
    short mtk_clip[4];
    kal_uint8 *tmpBuf;
    kal_uint32 *invalidPtr;
    kal_uint32 *dstptr = cached_data;
    kal_uint16 *src, *srcptr;
    kal_int32 w, width, bitcnt;
    kal_int32 cntCache = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* only cache for these font settings. */
    cache_font_ptr->font_type = font_type;
    cache_font_ptr->font_style = font_style;
    cache_font_ptr->font_size = font_size;

    jui_string_get_font_info(
        cache_font_ptr->font_type,
        cache_font_ptr->font_style,
        cache_font_ptr->font_size,
        &font_ascent,
        &font_descent,
        &font_leading);

    cache_font_ptr->font_height = font_leading + font_ascent + font_descent;

    h = cache_font_ptr->font_height;
    if (h > CACHED_FONT_MAX_HEIGHT)
    {
        return KAL_FALSE;
    }

    /* memset(jui_local_cached_data, 0, sizeof(jui_local_cached_data)); */

    /* get width for each char */
    for (i = 0; i < JUI_CACHED_FONT_NUM; i++)
    {
        s[0] = i;
        cache_font_ptr->cached_width[i] = jui_string_get_width_ext(cache_font_ptr->font_type,
                                            cache_font_ptr->font_style,
                                            cache_font_ptr->font_size,
                                            (kal_uint16*) s,
                                                                 1,NULL,& cache_font_ptr->cached_adv_width[i]);
        if (cache_font_ptr->cached_width[i] == 0)
        {
            cache_font_ptr->cached_data[i] = NULL;
        }
        else
        {
            if (maxWidth < cache_font_ptr->cached_width[i])
            {
                maxWidth = cache_font_ptr->cached_width[i];
            }
        }
    }

    /* if max width of char is bigger than our define, stop init cache flow */
    if (maxWidth > CACHED_FONT_WIDTH)
    {
        return KAL_FALSE;
    }

    maxWidth = CACHED_FONT_WIDTH;
    mtk_clip[0] = 0;
    mtk_clip[1] = 0;
    mtk_clip[3] = cache_font_ptr->font_height;
    mtk_clip[2] = maxWidth;
    maxWidth *= cache_font_ptr->font_height * 2;
#ifndef J2ME_SLIM_MEMORY_SUPPORT
    tmpBuf = jvm_malloc(maxWidth);
#else
    tmpBuf = jui_widget_mvm_gditempmemory_allocate(maxWidth);
#endif
    invalidPtr = (kal_uint32*) tmpBuf;
    ASSERT(invalidPtr != NULL);
        
#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
    invalidPtr =
        (kal_uint32*) jvm_l1_cache_invalidate_and_clean_region_by_line(
                        tmpBuf,
                        mtk_clip[0],
                        mtk_clip[1],
                        mtk_clip[2],
                        mtk_clip[3],
                        mtk_clip[2],
                        maxWidth);
#endif /* #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) */
 

#if DATACACHE_FBBR_ON
    invalidPtr =
        (kal_uint32*) FBBR_invalid_l1_cache_img(tmpBuf, mtk_clip[0], mtk_clip[1], mtk_clip[2], mtk_clip[3], maxWidth);
#endif /* DATACACHE_FBBR_ON */ /* #if DATACACHE_FBBR_ON */

    for (i = 0; i < JUI_CACHED_FONT_NUM; i++)
    {
        if (cache_font_ptr->cached_width[i] == 0)
        {
            cache_font_ptr->cached_data[i] = NULL;
            continue;
        }

        kal_mem_set(invalidPtr, 0x0, maxWidth);
        h = cache_font_ptr->font_height;
        s[0] = i;
        w = cache_font_ptr->cached_width[i];

        jui_string_mvm_draw_string(
            0x00FF,
            mtk_clip,
            (unsigned short*)invalidPtr,
            mtk_clip[2],
            h,
            maxWidth,
            0,
            cache_font_ptr->font_type,
            cache_font_ptr->font_style,
            cache_font_ptr->font_size,
            0,
            0,
            0,
            (kal_uint16*) s,
            1,
            0);

        src = (kal_uint16*) invalidPtr;
        is_space = KAL_TRUE;
        cache_font_ptr->cached_data[i] = dstptr;

    #ifndef __MMI_VECTOR_FONT_SUPPORT__
        /* check the drawing buffer to set each relative cache font bit on */
        w--;
        do
        {
            width = w;
            srcptr = src;
            bitcnt = 0;
            do
            {
                /* if the pixel is not null, set the relative bit on */
                if (*(srcptr + width) != 0)
                {
                    is_space = KAL_FALSE;
                    *dstptr |= ((kal_uint32) 1 << width);
                }
            } while (--width > 0);
            src += mtk_clip[2];
            dstptr++;
        } while (--h > 0);

    #else /* __MMI_VECTOR_FONT_SUPPORT__ */ 

    #ifdef __SUPPORT_VECTOR_FONT_ALPHA_BIT_4__
        do
        {
            srcptr = src;
            width = 0;
            bitcnt = 0;
            do
            {
                if (*(srcptr + width) != 0)
                {
                    is_space = KAL_FALSE;
                    bitcnt = ((*(srcptr + width)) & 0x001F) >> 1;
                    bitcnt <<= ((width % 8) << 2);
                    dstptr[width >> 3] |= bitcnt;
                }
                width++;
            } while (width < w);

            src += mtk_clip[2];
            dstptr = dstptr +  WORD_NUM_IN_ONE_LINE;
            h--;
        } while (h > 0);
    #else /* __SUPPORT_VECTOR_FONT_ALPHA_BIT_4__ */ 
        do
        {
            srcptr = src;
            width = 0;
            bitcnt = 0;
            do
            {
                if (*(srcptr + width) != 0)
                {
                    is_space = KAL_FALSE;
                    bitcnt = (*(srcptr + width)) & 0x001F;
                    bitcnt <<= ((width % 6) * 5);
                    dstptr[width / 6] |= bitcnt;
                }
                width++;
            } while (width < w);
            src += mtk_clip[2];
            dstptr = dstptr + /* 6 */ 4;
            h--;
        } while (h > 0);
    #endif /* __SUPPORT_VECTOR_FONT_ALPHA_BIT_4__ */ 
    #endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 
        if (is_space == KAL_TRUE)
        {
            /* if char is empty, reset cached_data as null */
            dstptr = cache_font_ptr->cached_data[i];
            cache_font_ptr->cached_data[i] = NULL;
        }
        else
        {
            /* if out of cache buffer, stop init cache flow */
            if (++cntCache >= CACHED_FONT_NUM)
            {
            #ifndef J2ME_SLIM_MEMORY_SUPPORT
                jvm_free(tmpBuf);
            #else
                jui_widget_mvm_gditempmemory_free(tmpBuf);
            #endif
                return KAL_FALSE;
            }

        #ifndef __MMI_VECTOR_FONT_SUPPORT__
            dstptr = cache_font_ptr->cached_data[i] + CACHED_FONT_MAX_HEIGHT;
        #else /* __MMI_VECTOR_FONT_SUPPORT__ */ 
        #ifdef __SUPPORT_VECTOR_FONT_ALPHA_BIT_4__
            dstptr = cache_font_ptr->cached_data[i] +WORD_NUM_IN_ONE_LINE  * CACHED_FONT_MAX_HEIGHT;

        #else /* __SUPPORT_VECTOR_FONT_ALPHA_BIT_4__ */ 
            dstptr = cache_font_ptr->cached_data[i] + 4 /* 6 */  * CACHED_FONT_MAX_HEIGHT;
        #endif /* __SUPPORT_VECTOR_FONT_ALPHA_BIT_4__ */ 

        #endif /* __MMI_VECTOR_FONT_SUPPORT__ */ 
        }
    }
    #ifndef J2ME_SLIM_MEMORY_SUPPORT
        jvm_free(tmpBuf);
    #else
        jui_widget_mvm_gditempmemory_free(tmpBuf);
    #endif

    return KAL_TRUE;
 
}
#endif /* ENABLE_JUI_CACHE_FONT */ 

/*****************************************************************************
 * FUNCTION
 *  jui_init_cached_font_malloc
 * DESCRIPTION
 *  malloc memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void * jui_init_cached_font_malloc(kal_int32 size)
{
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    return jui_widget_mvm_gditempmemory_allocate(size);
#endif

#if defined(SUPPORT_CACHED_FONT_ALWAYS)
    return jvm_malloc(size);
#else
    return applib_mem_ap_alloc(APPLIB_MEM_AP_ID_JAVA,size);
#endif /* #ifdef SUPPORT_CACHED_FONT_ALWAYS */
}


/*****************************************************************************
 * FUNCTION
 *  jui_init_cached_font_free
 * DESCRIPTION
 *  free memory.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void jui_init_cached_font_free(void * buffer)
{
    if(buffer != NULL)
    {
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
        jui_widget_mvm_gditempmemory_free(buffer);
        return;
#endif
   
#if defined(SUPPORT_CACHED_FONT_ALWAYS)
        jvm_free(buffer);
#else
        applib_mem_ap_free(buffer);
#endif /* #ifdef SUPPORT_CACHED_FONT_ALWAYS */       
    }
}


/*****************************************************************************
 * FUNCTION
 *  jui_init_cached_font_fill_data
 * DESCRIPTION
 *  initialize font info.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_init_cached_font_fill_data(void)
{
#ifdef ENABLE_JUI_CACHE_FONT
        kal_mem_set(&g_jui_cached_font, 0x00, sizeof(jui_cached_font_struct));
        memset(jui_local_cached_data, 0x00, JUI_FONT_BUFFER_SIZE * sizeof(kal_uint32));
    
        jui_enable_cached_font = jui_init_cached_font_internal(&g_jui_cached_font, jui_local_cached_data, FACE_SYSTEM, STYLE_PLAIN, SIZE_MEDIUM);
    
#if defined(__SUPPORT_VECTOR_FONT_MEDIUM_BOLD__) || defined(__SUPPORT_BITMAP_FONT_MEDIUM_BOLD__)
    
        kal_mem_set(&g_jui_cached_bold_font, 0x00, sizeof(jui_cached_font_struct));
        if (jui_local_cached_bold_data != NULL)
        {
            memset(jui_local_cached_bold_data, 0x00, JUI_FONT_BUFFER_SIZE * sizeof(kal_uint32));
            jui_enable_cached_bold_data = jui_init_cached_font_internal(
                    &g_jui_cached_bold_font,
                    jui_local_cached_bold_data,
                    FACE_SYSTEM,
                    STYLE_BOLD,
                    SIZE_MEDIUM);
        }
#endif /* __SUPPORT_VECTOR_FONT_MEDIUM_BOLD__ */ 
    
#ifdef __SUPPORT_VECTOR_FONT_SMALL__
    
        kal_mem_set(&g_jui_cached_small_font, 0x00, sizeof(jui_cached_font_struct));
        if (jui_local_cached_small_data != NULL)
        {
            memset(jui_local_cached_small_data, 0x00, JUI_FONT_BUFFER_SIZE * sizeof(kal_uint32));
            jui_init_cached_font_internal(
                &g_jui_cached_small_font,
                jui_local_cached_small_data,
                FACE_SYSTEM,
                STYLE_PLAIN,
                SIZE_SMALL);
        }
#endif /* __SUPPORT_VECTOR_FONT_SMALL__ */ 

        jui_cached_font_is_initialized = KAL_TRUE;

        kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_FONT_CACHE_INIT_2, jui_enable_cached_font,jui_enable_cached_bold_data);

#endif /* ENABLE_JUI_CACHE_FONT */
}

/*****************************************************************************
 * FUNCTION
 *  jui_init_cached_font
 * DESCRIPTION
 *  initialize font info.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_init_cached_font(void)
{
#ifdef ENABLE_JUI_CACHE_FONT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_FONT_CACHE_INIT, jui_enable_cached_font,jui_enable_cached_bold_data);
    if (jui_enable_cached_font == KAL_TRUE)
    {
        return;
    }
    jui_enable_cached_font = KAL_FALSE;
    jui_enable_cached_bold_data = KAL_FALSE;

#ifdef __SUPPORT_FONT_MEMORY_FROM_SCREEN_MEMORY__

    jui_local_cached_data = (kal_uint32*) jui_init_cached_font_malloc(JUI_FONT_BUFFER_SIZE * sizeof(kal_uint32));

    ////ASSERT(jui_local_cached_data != NULL);
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_FONT_CACHE_MEDIUM_NORMAL_INIT, jui_local_cached_data);

#if defined(__SUPPORT_VECTOR_FONT_MEDIUM_BOLD__) || defined(__SUPPORT_BITMAP_FONT_MEDIUM_BOLD__) 

    if(jui_local_cached_data != NULL)
        jui_local_cached_bold_data = (kal_uint32*) jui_init_cached_font_malloc(JUI_FONT_BUFFER_SIZE * sizeof(kal_uint32));
    else
        jui_local_cached_bold_data = NULL;
    ////ASSERT(jui_local_cached_bold_data != NULL);

    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_FONT_CACHE_MEDIUM_BOLD_INIT, jui_local_cached_bold_data);
#endif 

#ifdef __SUPPORT_VECTOR_FONT_SMALL__

    if(jui_local_cached_bold_data != NULL)
        jui_local_cached_small_data = (kal_uint32*) jui_init_cached_font_malloc(JUI_FONT_BUFFER_SIZE * sizeof(kal_uint32));
    else
        jui_local_cached_small_data = NULL;
    ////ASSERT(jui_local_cached_small_data != NULL);
    
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_FONT_CACHE_SMALL_NORMAL_INIT, jui_local_cached_small_data);
#endif 

    if (jui_local_cached_data == NULL)  /* if no memory , close cached font */
    {
        kal_trace(JVM_TRACE_TYPE_JUI,FUNC_J2ME_JUI_FONT_CACHE_INIT_3);
        return;
    }
 
    jui_enable_lazy_cached_font = KAL_FALSE;

    jui_cached_font_is_initialized = KAL_FALSE;
#endif /* __SUPPORT_FONT_MEMORY_FROM_SCREEN_MEMORY__ */

    if(jui_enable_lazy_cached_font)
        return;
    jui_init_cached_font_fill_data();
#endif /* ENABLE_JUI_CACHE_FONT */ 
}


/*****************************************************************************
 * FUNCTION
 *  jui_deinit_cached_font
 * DESCRIPTION
 *  de-initialize font info.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jui_deinit_cached_font()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef ENABLE_JUI_CACHE_FONT
    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_FONT_CACHE_DEINIT, jui_enable_cached_font,jui_enable_cached_bold_data);
#ifdef __SUPPORT_FONT_MEMORY_FROM_SCREEN_MEMORY__

    if (jui_local_cached_data != NULL)
    {
        jui_init_cached_font_free(jui_local_cached_data);
        jui_local_cached_data = NULL;
    }

#if defined(__SUPPORT_VECTOR_FONT_MEDIUM_BOLD__) || defined(__SUPPORT_BITMAP_FONT_MEDIUM_BOLD__)
    if (jui_local_cached_bold_data != NULL)
    {
        jui_init_cached_font_free(jui_local_cached_bold_data);
        jui_local_cached_bold_data = NULL;
    }
#endif /* __SUPPORT_VECTOR_FONT_MEDIUM_BOLD__ */ 

#ifdef __SUPPORT_VECTOR_FONT_SMALL__
    if (jui_local_cached_small_data != NULL)
    {
        jui_init_cached_font_free(jui_local_cached_small_data);
        jui_local_cached_small_data = NULL;
    }
#endif /* __SUPPORT_VECTOR_FONT_SMALL__ */ 

    jui_enable_cached_font = KAL_FALSE;
    jui_enable_cached_bold_data = KAL_FALSE;

    jui_enable_lazy_cached_font = KAL_FALSE;
    jui_cached_font_is_initialized = KAL_FALSE;
#endif /* __SUPPORT_FONT_MEMORY_FROM_SCREEN_MEMORY__ */

    kal_trace(JVM_TRACE_TYPE_JUI, FUNC_J2ME_JUI_FONT_CACHE_DEINIT_2, jui_enable_cached_font,jui_enable_cached_bold_data);
#endif /* ENABLE_JUI_CACHE_FONT */ 
}
extern kal_int32 jui_lcd_buffer_size;


/*****************************************************************************
 * FUNCTION
 *  jui_string_mvm_draw_string
 * DESCRIPTION
 *  Draw the first n characters in chararray, with the anchor point of the
 *  entire (sub)string located at x, y.
 * PARAMETERS
 *  pixel               [IN]        
 *  clip                [?]         [?]
 *  dst                 [?]         [?]
 *  dst_width           [IN]        
 *  dst_height          [IN]        
 *  buffer_size         [IN]        
 *  dotted              [IN]        
 *  face                [IN]        
 *  style               [IN]        
 *  size                [IN]        
 *  x                   [IN]        
 *  y                   [IN]        
 *  anchor              [IN]        
 *  charArray2          [IN]        
 *  n                   [IN]        
 *  display_id          [IN]        
 *  chararray(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jui_string_mvm_draw_string(
        kal_int32 pixel,
        short *clip,
        unsigned short *dst,
        kal_int32 dst_width,
        kal_int32 dst_height,
        kal_int32 buffer_size,
        kal_int32 dotted,
        kal_int32 face,
        kal_int32 style,
        kal_int32 size,
        kal_int32 x,
        kal_int32 y,
        kal_int32 anchor,
        const kal_uint16 *charArray2,
        kal_int32 n,
        kal_int32 display_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stFontAttribute J2ME_font = {0};
    color font_color, org_color = gui_get_text_color();
    kal_int32 width, height;
    kal_int32 x_pos, y_pos;
    kal_int32 clip_reg[4];
    stFontAttribute org_font = {0};
    mmi_fe_showstring_info_struct param;
    S32 maxAscent = 0, maxDescent = 0, maxHeight = 0;
    kal_uint32 *invalidPtr;
    kal_uint16 *chararray = (kal_uint16*) charArray2;
    gdi_handle org_src_layer_handle;

    kal_uint16 *dest_buff;
    kal_int32 dest_width, dest_height;


#ifdef ENABLE_JUI_CACHE_FONT
    jui_cached_font_struct *cached_font_ptr = &g_jui_cached_font;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef ENABLE_JUI_CACHE_FONT
    kal_trace(JVM_TRACE_TYPE_JUI_DEBUG, FUNC_J2ME_JUI_FONT_DRAW_STRING,anchor, x, y, n,face,style,size,jui_enable_cached_font,jui_enable_cached_bold_data);
#endif

    if (n <= 0  ||(n==1 && chararray[0] == 0))
    {
        return;
    }

    /* Check and set clip region */
    clip_reg[0] = (clip[0] < 0) ? 0 : clip[0];
    clip_reg[1] = (clip[1] < 0) ? 0 : clip[1];

    if (dst)
    {
        clip_reg[2] = ((clip[0] + clip[2] - 1) >= dst_width) ? (dst_width - 1) : (clip[0] + clip[2] - 1);
        clip_reg[3] = ((clip[1] + clip[3] - 1) >= dst_height) ? (dst_height - 1) : (clip[1] + clip[3] - 1);
    }
    else
    {
        clip_reg[2] =
            ((clip[0] + clip[2] - 1) >= jui_ui_device_width) ? (jui_ui_device_width - 1) : (clip[0] + clip[2] - 1);
        clip_reg[3] =
            ((clip[1] + clip[3] - 1) >= jui_widget_get_display_height_id(display_id)) ? (jui_widget_get_display_height_id(display_id) - 1) : (clip[1] + clip[3] - 1);
    }

#ifdef ENABLE_JUI_CACHE_FONT
    if (jui_enable_cached_font == KAL_TRUE)
    {
        if ((style == g_jui_cached_font.font_style && size == g_jui_cached_font.font_size)
#if defined(__SUPPORT_VECTOR_FONT_MEDIUM_BOLD__) || defined(__SUPPORT_BITMAP_FONT_MEDIUM_BOLD__)
            || (jui_enable_cached_bold_data && style == g_jui_cached_bold_font.font_style && size == g_jui_cached_bold_font.font_size)
#endif /* __SUPPORT_VECTOR_FONT_MEDIUM_BOLD__ */
            
    #ifdef __SUPPORT_VECTOR_FONT_SMALL__
            || (style == g_jui_cached_small_font.font_style && size == g_jui_cached_small_font.font_size)
#endif /* __SUPPORT_VECTOR_FONT_SMALL__ */
            )
        {
            if (!((anchor & HCENTER) || (anchor & RIGHT) || r2lMMIFlag || (style & STYLE_UNDERLINED)))
            {
                height = jui_default_font_height;
#if defined(__SUPPORT_VECTOR_FONT_MEDIUM_BOLD__) || defined(__SUPPORT_BITMAP_FONT_MEDIUM_BOLD__)
                if(jui_enable_cached_bold_data && style == g_jui_cached_bold_font.font_style && size == g_jui_cached_bold_font.font_size)
                {
                    cached_font_ptr = &g_jui_cached_bold_font;
                }
            #endif /* __SUPPORT_VECTOR_FONT_MEDIUM_BOLD__ */ 

            #ifdef __SUPPORT_VECTOR_FONT_SMALL__
                if (style == g_jui_cached_small_font.font_style && size == g_jui_cached_small_font.font_size)
                {
                    cached_font_ptr = &g_jui_cached_small_font;
                    height = jui_small_font_height;
                }
            #endif /* __SUPPORT_VECTOR_FONT_SMALL__ */ 

                //height = cached_font_ptr->font_height;

                if (anchor & VCENTER)
                {
                    y_pos = y - height / 2;
                }
                else if (anchor & TOP)
                {
                    y_pos = y;
                }
                else if (anchor & BOTTOM)
                {
                    y_pos = y - height;
                }
                else if (anchor & BASELINE)
                {
                    y_pos = y - height;
                }
                else
                {
                    y_pos = y;
                }

                if (dst)
                {
                    dest_buff = dst;
                    dest_width = dst_width;
                    dest_height = dst_height;
                }
                else
                {
                    dest_buff = g_jui_screen_data[JUI_WIDGET_DEFAULT_DISPLAY_ID].lcd_buffer;        /* JUI MVM */
                    dest_width = jui_ui_device_width;
                    dest_height = jui_widget_get_display_height_id(display_id);
                }
                do
                {
                    if ((*chararray) < JUI_CACHED_FONT_NUM)
                    {
                        if (cached_font_ptr->cached_width[(*chararray)] > 0)
                        {
                            if (cached_font_ptr->cached_data[(*chararray)] != NULL)
                            {
                                jui_draw_cached_font(
                                    dest_buff,
                                    dest_width,
                                    dest_height,
                                    *chararray,
                                    clip_reg,
                                    x,
                                    y_pos,
                                    (kal_uint16) pixel,
                                    cached_font_ptr);
                            }
                            x += cached_font_ptr->cached_width[*chararray];
                        }
                        n--;
                        chararray++;
                    }
                    else
                    {
                        break;
                    }
                } while (n > 0);

                if (0 >= n)
                {
                    return;
                }
            }
        }
    }
#endif /* ENABLE_JUI_CACHE_FONT */ 

    memset(&param, 0, sizeof(mmi_fe_showstring_info_struct));
    jui_lcd_mutex_lock();
    gdi_layer_lock_frame_buffer();


    //jui_string_get_font_info(face,style,size,&ascent,&descent,&leading);
    //height = ascent + descent + leading;

    if (!jam_is_in_fg_screen(jui_widget_active_display_id))
    {
        if (UI_font)
        {
            memcpy(&org_font, UI_font, sizeof(stFontAttribute));
        }
        org_color = gui_get_text_color();
    }

    j2me_custom_hw_to_mmi_color(pixel, 100, &font_color);

    jui_string_set_font(&J2ME_font, face, style, size);

    /*for (i = 0; i < gMaxDeployedLangs; i++)
    {
        SetFont(J2ME_font, (U8) i);
        tmp = Get_CharAscent();
        if (tmp > maxAscent)
        {
            maxAscent = tmp;
        }
        tmp = Get_CharDescent();
        if (tmp > maxDescent)
        {
            maxDescent = tmp;
        }
        tmp = Get_CharHeight();
        if (tmp > maxHeight)
        {
            maxHeight = tmp;
        } 
    }*/

    mmi_fe_get_char_info_of_all_lang(J2ME_font.size, &maxHeight, &maxAscent, &maxDescent);

    /* Copy to temp string buffer, and append NULL */
    if (n >= (MAX_MIDP_FONT_DISPLAY - 1))
    {
        n = MAX_MIDP_FONT_DISPLAY - 2;
    }

    kal_mem_cpy(jui_text_buffer, chararray, n * sizeof(kal_uint16));
    jui_text_buffer[n * sizeof(kal_uint16)] = '\0';
    jui_text_buffer[n * sizeof(kal_uint16) + 1] = '\0';

    /* MAUI_02085939 */
    /*if (size == SIZE_SMALL)
    {
        height = jui_small_font_height;   
    }
    else if (size == SIZE_LARGE)
    {
        height = jui_large_font_height;
    }
    else
    {
        height = jui_default_font_height;
    }*/
    height = maxHeight;

    width = gui_get_string_width_n((UI_string_type) chararray, n);

    /* Determine position */
    if (anchor & HCENTER)
    {
        x_pos = x - width / 2;
    }
    else if (anchor & LEFT)
    {
        x_pos = x;
    }
    else if (anchor & RIGHT)
    {
        x_pos = x - width;
    }
    else
    {
        x_pos = x;
    }

    if (anchor & VCENTER)
    {
        y_pos = y - height / 2;
    }
    else if (anchor & TOP)
    {
        y_pos = y;
    }
    else if (anchor & BOTTOM)
    {
        y_pos = y - height/* - 1*/ /* why need to -1???*/;
    }
    else if (anchor & BASELINE)
    {
        y_pos = y - maxAscent;
    }
    else
    {
        y_pos = y;
    }

    if (r2lMMIFlag)
    {
        param.x = x_pos + width - 1;
    }
    else
    {
        param.x = x_pos;
    }
    param.y = y_pos;
    param.char_gap = 0;
    param.String = (U8*) jui_text_buffer;
    param.BaseLineHeight = maxAscent;
    param.assign_direction = 1;
    param.enable_truncated = MMI_FALSE;
    param.Bordered = MMI_FALSE;
    param.render_flag = 1;
    param.len = mmi_ucs2strlen((const S8*)(jui_text_buffer));

    gdi_get_alpha_blending_source_layer(&org_src_layer_handle);
    if (jui_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_push_and_set_active(jui_layer_handle);
        gdi_set_alpha_blending_source_layer(jui_layer_handle);
    }

    if (dst)
    {
        /* using one layer to display the text */
        {
            gdi_handle text_handle;
            gdi_handle orgsrc_layer_handle;

            invalidPtr = (kal_uint32*) dst;
        #if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
                        
            if(y_pos < clip_reg[1] )
            {
                //kal_prompt_trace(MOD_J2ME,"[JUI]draw_string,set y = clip_reg,y_pos=%d,clip_reg[1]=%d",y_pos,clip_reg[1]);
                y_pos = clip_reg[1];
            }
            
            invalidPtr =
                (kal_uint32*) jvm_l1_cache_invalidate_and_clean_region_by_line(
                                dst,
                                (kal_uint32) x_pos,
                                (kal_uint32) y_pos,
                                (kal_uint32) width,
                                (kal_uint32) height,
                                (kal_uint32) dst_width,
                                (kal_uint32) buffer_size);
        #endif /* #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) */

        #if DATACACHE_FBBR_ON
            invalidPtr = (kal_uint32*) FBBR_invalid_l1_cache_img(dst, x_pos, y_pos, width, height, dst_width);
        #endif /* #if DATACACHE_FBBR_ON */

            gdi_layer_create_using_outside_memory(
                0,
                0,
                dst_width,
                dst_height,
                &text_handle,
                (U8*) invalidPtr,
                (kal_int32) buffer_size);

            gdi_layer_push_and_set_active(text_handle);
            orgsrc_layer_handle = gdi_set_alpha_blending_source_layer(text_handle);
            gdi_layer_set_clip(clip_reg[0], clip_reg[1], clip_reg[2], clip_reg[3]);
            UI_set_current_text_color(font_color);
            mmi_fe_show_string(&param);
            if (style & STYLE_UNDERLINED)
            {
                gdi_draw_line(param.x, param.y + height - 2, param.x + width - 1, param.y + height - 2, pixel);
            }
            gdi_set_alpha_blending_source_layer(orgsrc_layer_handle);
            gdi_layer_pop_and_restore_active();
            gdi_layer_free(text_handle);
        }

    }
    else
    {
        if (!jam_is_in_fg_screen(jui_widget_active_display_id))
        {
            gdi_handle text_handle;
            gdi_handle orgsrc_layer_handle;

            invalidPtr = (kal_uint32*) g_jui_screen_data[JUI_WIDGET_DEFAULT_DISPLAY_ID].lcd_buffer;        /* JUI MVM */
        #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && !defined (J2ME_SLIM_MEMORY_SUPPORT)
            invalidPtr =
                (kal_uint32*) jvm_l1_cache_invalidate_and_clean_region_by_line(
                                g_jui_screen_data[JUI_WIDGET_DEFAULT_DISPLAY_ID].lcd_buffer,
                                (kal_uint32) x_pos,
                                (kal_uint32) y_pos,
                                (kal_uint32) width,
                                (kal_uint32) height,
                                (kal_uint32) jui_ui_device_width,
                                (kal_uint32) jui_lcd_buffer_size);
        #endif /* #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) */

            gdi_layer_create_using_outside_memory(
                0,
                0,
                jui_ui_device_width,
                jui_widget_get_display_height_id(display_id),
                &text_handle,
                (U8*) invalidPtr,
                (kal_int32) ((jui_ui_device_width * jui_widget_get_display_height_id(display_id)) << 1));

            gdi_layer_push_and_set_active(text_handle);
            orgsrc_layer_handle = gdi_set_alpha_blending_source_layer(text_handle);
            gdi_layer_set_clip(clip_reg[0], clip_reg[1], clip_reg[2], clip_reg[3]);
            UI_set_current_text_color(font_color);
            mmi_fe_show_string(&param);
            if (style & STYLE_UNDERLINED)
            {
                gdi_draw_line(param.x, param.y + height - 2, param.x + width - 1, param.y + height - 2, pixel);
            }
            gdi_set_alpha_blending_source_layer(orgsrc_layer_handle);
            gdi_layer_pop_and_restore_active();
            gdi_layer_free(text_handle);
        }
        else
        {
        #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) && !defined (J2ME_SLIM_MEMORY_SUPPORT)
            invalidPtr =
                (kal_uint32*) jvm_l1_cache_invalidate_and_clean_region_by_line(
                                g_jui_screen_data[JUI_WIDGET_DEFAULT_DISPLAY_ID].lcd_buffer,
                                (kal_uint32) x_pos,
                                (kal_uint32) y_pos,
                                (kal_uint32) width,
                                (kal_uint32) height,
                                (kal_uint32) jui_ui_device_width,
                                (kal_uint32) jui_lcd_buffer_size);
        #endif /* #if defined(__DYNAMIC_SWITCH_CACHEABILITY__) */
            UI_set_current_text_color(font_color);
            gdi_layer_set_clip(clip_reg[0], clip_reg[1], clip_reg[2], clip_reg[3]);
            mmi_fe_show_string(&param);
            if (style & STYLE_UNDERLINED)
            {
                gdi_draw_line(param.x, param.y + height - 2, param.x + width - 1, param.y + height - 2, pixel);
            }
            gdi_layer_reset_clip();
        }
    }

    if (jui_layer_handle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_pop_and_restore_active();
        gdi_set_alpha_blending_source_layer(org_src_layer_handle);
    }

    if (!jam_is_in_fg_screen(jui_widget_active_display_id))
    {
        if (UI_font)
        {
            gui_set_font(&org_font);
        }
        gui_set_text_color(org_color);
    }


    gdi_layer_unlock_frame_buffer();
    jui_lcd_mutex_unlock();
}


/*****************************************************************************
 * FUNCTION
 *  jui_string_get_font_info
 * DESCRIPTION
 *  Get the ascent, descent and leading info for the J2ME_font indicated
 *  by FONTPARAMS.
 * PARAMETERS
 *  face        [IN]        
 *  style       [IN]        
 *  size        [IN]        
 *  ascent      [?]         [?]
 *  descent     [?]         [?]
 *  leading     [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
void jui_string_get_font_info(
        kal_int32 face,
        kal_int32 style,
        kal_int32 size,
        kal_int32 *ascent,
        kal_int32 *descent,
        kal_int32 *leading)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //stFontAttribute font = {0};
    //stFontAttribute org_font = {0};
    U8 font_size = MEDIUM_FONT;
    S32 maxAscent = 0, maxDescent = 0, maxHeight = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //jui_lcd_mutex_lock();
    //gdi_layer_lock_frame_buffer();

    /*if (!jam_is_in_fg_screen(jui_widget_active_display_id) && UI_font)
    {
        memcpy(&org_font, UI_font, sizeof(stFontAttribute));
    }

    jui_string_set_font(&font, face, style, size);

    for (i = 0; i < gMaxDeployedLangs; i++)
    {
        SetFont(font, (U8) i);
        tmp = Get_CharAscent();
        if (tmp > maxAscent)
        {
            maxAscent = tmp;
        }
        tmp = Get_CharDescent();
        if (tmp > maxDescent)
        {
            maxDescent = tmp;
        }
    }*/
    if (size == SIZE_SMALL)
    {
        font_size = SMALL_FONT;
    }
    else if (size == SIZE_MEDIUM)
    {
        font_size = MEDIUM_FONT;
    }
    else if (size == SIZE_LARGE)
    {
        font_size = LARGE_FONT;
    }
    mmi_fe_get_char_info_of_all_lang(font_size, &maxHeight, &maxAscent, &maxDescent);
    *ascent = maxAscent;
    *descent = maxDescent;

    /* REMIND: is there a way to get the leading from an X J2ME_font? */
    *leading = 0;

    /*if (!jam_is_in_fg_screen(jui_widget_active_display_id) && UI_font)
    {
        gui_set_font(&org_font);
    }*/

    //gdi_layer_unlock_frame_buffer();
    //jui_lcd_mutex_unlock();
}


/*****************************************************************************
 * FUNCTION
 *  jui_string_get_width
 * DESCRIPTION
 *  Get the width for the first n characters in charArray if
 *  they were to be drawn in the J2ME_font indicated by given font attributes.
 * PARAMETERS
 *  face                [IN]        Font attribute-face
 *  style               [IN]        Font attribute-style
 *  size                [IN]        Font attribute-size
 *  charArray2          [IN]        
 *  n                   [IN]        Size of the array
 *  charArray(?)        [IN]        Array of chars
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 jui_string_get_width(
            kal_int32 face,
            kal_int32 style,
            kal_int32 size,
            const kal_uint16 *charArray2,
            kal_int32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stFontAttribute font = {0};
    stFontAttribute org_font = {0};
    kal_int32 string_width = 0;
    kal_uint16 *chararray = (kal_uint16*) charArray2;

#ifdef ENABLE_JUI_CACHE_FONT
    jui_cached_font_struct *cached_font_ptr = NULL;
#endif 

    mmi_fe_get_string_info_param_struct query;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n <= 0)
        return 0;

#ifdef ENABLE_JUI_CACHE_FONT
    if (jui_enable_cached_font == KAL_TRUE  && !r2lMMIFlag)
    {
        if ((style == g_jui_cached_font.font_style) && (size == g_jui_cached_font.font_size))
        {
            cached_font_ptr = &g_jui_cached_font;
        }
#if defined(__SUPPORT_VECTOR_FONT_MEDIUM_BOLD__) || defined(__SUPPORT_BITMAP_FONT_MEDIUM_BOLD__)
        if (jui_enable_cached_bold_data && (style == g_jui_cached_bold_font.font_style ) && (size == g_jui_cached_bold_font.font_size))
        {
            cached_font_ptr = &g_jui_cached_bold_font;
        }

    #endif /* __SUPPORT_VECTOR_FONT_MEDIUM_BOLD__ */ 

    #ifdef __SUPPORT_VECTOR_FONT_SMALL__
        if ((style == g_jui_cached_small_font.font_style) && (size == g_jui_cached_small_font.font_size))
        {
            cached_font_ptr = &g_jui_cached_small_font;
        }
#endif /* __SUPPORT_VECTOR_FONT_MEDIUM_BOLD__ */
        if (cached_font_ptr != NULL)
        {
            while (n > 0)   /* do */
            {
                if ((*chararray) < JUI_CACHED_FONT_NUM)
                {
                    if (*(cached_font_ptr->cached_width + (*chararray)) != 0)
                    {
                        string_width += *(cached_font_ptr->cached_adv_width+(*chararray));
                    }
                    chararray++;
                    n--;
                }
                else
                {
                    break;
                }
            };  /* while (n > 0); */

            if (0 >= n)
            {
                return string_width;
            }
        }

    }
#endif /* ENABLE_JUI_CACHE_FONT */ 

    jui_lcd_mutex_lock();
    gdi_layer_lock_frame_buffer();


    if (!jam_is_in_fg_screen(jui_widget_active_display_id)&& UI_font)
    {
        memcpy(&org_font, UI_font, sizeof(stFontAttribute));
    }
    jui_string_set_font(&font, face, style, size);
    //string_width += gui_get_string_width_n((UI_string_type) chararray, n);

    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (kal_uint8 *)chararray;
    query.n = n;
    query.enableTruncated = MMI_FALSE;
    query.w = 0;
    mmi_fe_get_string_widthheight(&query);
    
    string_width += query.adv_w;

    if (!jam_is_in_fg_screen(jui_widget_active_display_id) && UI_font)
    {
        gui_set_font(&org_font);
    }

    gdi_layer_unlock_frame_buffer();
    jui_lcd_mutex_unlock();

    return string_width;
}

/*****************************************************************************
* FUNCTION
*  jui_string_get_width_ext
* DESCRIPTION
*  Get the width for the first n characters in charArray if
*  they were to be drawn in the J2ME_font indicated by given font attributes.
* PARAMETERS
*  face            [IN]        Font attribute-face
*  style           [IN]        Font attribute-style
*  size            [IN]        Font attribute-size
*  charArray       [IN]        Array of chars
*  n               [IN]        Size of the array
* RETURNS
*  
 *****************************************************************************/
int jui_string_get_width_ext(int face,int style,int size,const kal_uint16 * charArray2,int n , int * width,int * adv_w)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    stFontAttribute font = {0};
    stFontAttribute org_font = {0};
    kal_int32 string_width = 0;
    kal_uint16 *chararray = (kal_uint16 *)charArray2;
    
#ifdef ENABLE_JUI_CACHE_FONT
    jui_cached_font_struct * cached_font_ptr = NULL;
#endif /* ENABLE_JUI_CACHE_FONT */

    mmi_fe_get_string_info_param_struct query;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(n <=0)
    {
        if( width != NULL) *width = 0;
        if( adv_w != NULL) *adv_w = 0;
        return 0;
    }
    
#ifdef ENABLE_JUI_CACHE_FONT
    if (jui_enable_cached_font == KAL_TRUE)
    {
        if ((style == g_jui_cached_font.font_style ) && (size == g_jui_cached_font.font_size))
        {
            cached_font_ptr = &g_jui_cached_font;
        }
#if defined(__SUPPORT_VECTOR_FONT_MEDIUM_BOLD__) || defined(__SUPPORT_BITMAP_FONT_MEDIUM_BOLD__)
        if (jui_enable_cached_bold_data && (style == g_jui_cached_bold_font.font_style ) && (size == g_jui_cached_bold_font.font_size))
        {
            cached_font_ptr = &g_jui_cached_bold_font;
        }
        
#endif /* __SUPPORT_VECTOR_FONT_MEDIUM_BOLD__ */
        
#ifdef __SUPPORT_VECTOR_FONT_SMALL__
        if ((style == g_jui_cached_small_font.font_style ) && (size == g_jui_cached_small_font.font_size))
        {
            cached_font_ptr = &g_jui_cached_small_font;
        }
#endif /* __SUPPORT_VECTOR_FONT_MEDIUM_BOLD__ */
        if(cached_font_ptr != NULL)
        {
            while(n>0)//do
            {
                if ((*chararray) < JUI_CACHED_FONT_NUM)
                {
                    if (*(cached_font_ptr->cached_width+(*chararray)) != 0)
                    {
                        string_width += *(cached_font_ptr->cached_adv_width+(*chararray));
                    }
                    chararray++;
                    n--;
                }
                else
                {
                    break;
                }
            } ;//while (n > 0);
            
            if (0 >= n)
            {
                return string_width;
            }
        }
        
    }
#endif /* ENABLE_JUI_CACHE_FONT */
    
    jui_lcd_mutex_lock();
    gdi_layer_lock_frame_buffer();
    
    if (!jam_is_own_java_screen(jam_mvm_get_current_vm_id()) && UI_font)
    {
        memcpy(&org_font, UI_font, sizeof(stFontAttribute));
    }
    jui_string_set_font(&font, face, style, size);
    //string_width += gui_get_string_width_n((UI_string_type) chararray, n);
    
    memset(&query, 0, sizeof(mmi_fe_get_string_info_param_struct));
    query.String = (kal_uint8 *)chararray;
    query.n = n;
    query.enableTruncated = MMI_FALSE;
    query.w = 0;
    mmi_fe_get_string_widthheight(&query);
    
    string_width += query.pWidth;

    if(width != NULL)
        *width = string_width;
    if(adv_w != NULL)
        *adv_w = string_width; //query.adv_w;

    if (!jam_is_own_java_screen(jam_mvm_get_current_vm_id()) && UI_font)
    {
        gui_set_font(&org_font);
    }
    
    gdi_layer_unlock_frame_buffer();
    jui_lcd_mutex_unlock();
    
    return string_width;  
}

/*****************************************************************************
 * FUNCTION
 *  jui_string_set_font
 * DESCRIPTION
 *  set font using given font attribute
 * PARAMETERS
 *  J2ME_font       [?]         [?]
 *  face            [IN]        Font attribute-face
 *  style           [IN]        Font attribute-style
 *  size            [IN]        Font attribute-size
 * RETURNS
 *  void
 *****************************************************************************/
void jui_string_set_font(stFontAttribute *J2ME_font, kal_int32 face, kal_int32 style, kal_int32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 language_index = 0;  /* 020207 java font */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Dotted not used. Need MMI support */
    kal_mem_set(J2ME_font, 0, sizeof(stFontAttribute));

    if (face == FACE_SYSTEM)
    {
        J2ME_font->type = 1;
    }
    else if (face == FACE_MONOSPACE)
    {
        J2ME_font->type = 2;
    }
    else
    {
        J2ME_font->type = 3;
    }

    if (style & STYLE_BOLD)
    {
        J2ME_font->bold = 1;
    }
    else
    {
        J2ME_font->bold = 0;
    }

    if (style & STYLE_ITALIC)
    {
        J2ME_font->italic = 1;
    }
    else
    {
        J2ME_font->italic = 0;
    }

    /* Draw underline in JAL instead of font engine */
    /*
    if (style & STYLE_UNDERLINED)
    {
        J2ME_font->underline = 1;
    }
    else
    {
        J2ME_font->underline = 0;
    }
    */
    if (size == SIZE_SMALL)
    {
        J2ME_font->size = SMALL_FONT;
    }
    else if (size == SIZE_MEDIUM)
    {
        J2ME_font->size = MEDIUM_FONT;
    }
    else if (size == SIZE_LARGE)
    {
        J2ME_font->size = LARGE_FONT;
    }

    SetFont(*J2ME_font, (kal_uint8) language_index);
}


/*****************************************************************************
 * FUNCTION
 *  jui_string_get_default_font_info
 * DESCRIPTION
 *  get the default font attribute
 * PARAMETERS
 *  ascent      [?]     
 *  descent     [?]     
 *  leading     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void jui_string_get_default_font_info(kal_int32 *ascent, kal_int32 *descent, kal_int32 *leading)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    jui_string_get_font_info(FACE_SYSTEM, STYLE_PLAIN, SIZE_MEDIUM, ascent, descent, leading);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

