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
 *  wgui_categories_UCE.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Unified Composer Category 
 *
 *  [Category280]       UCE Category
 *
 * Author:
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef __WGUI_CATEGORIES_UCE_H__
#define __WGUI_CATEGORIES_UCE_H__

//#if defined (__UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__)

#if defined (__UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__) && defined (__MMI_MSG_EDITOR_WITH_RECIPIENT__)
    #ifndef __WGUI_CAT280_ENHANCED_UI__
        #define __WGUI_CAT280_ENHANCED_UI__
    #endif
#endif

#if defined (__UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__)
    #ifndef __WGUI_CAT280_SUPPORT_MMS__
        #define __WGUI_CAT280_SUPPORT_MMS__
    #endif
#endif

#if defined (__MMI_MSG_EDITOR_WITH_RECIPIENT__)
    #ifndef __WGUI_CAT280_SUPPORT_RECIPIENTS__
        #define __WGUI_CAT280_SUPPORT_RECIPIENTS__
    #endif
#endif


#include "Gdi_include.h" 								/* Bits Per Pixel*/
#include "ImeGprot.h"

//RHR
    #include "lcd_sw_inc.h"
    #include "wgui.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "fs_type.h"
    #include "gui_data_types.h"

/* <hExpand noExpand> DO NOT REMOVE THIS LINE */
#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
#include "lcd_sw_rnd.h"
#include "gdi_lcd_config.h" 
#endif /* __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ */
/* </hExpand> DO NOT REMOVE THIS LINE */

/***************************************************************************** 
* Define
*****************************************************************************/

/* DOM-NOT_FOR_SDK-BEGIN */
/* thumbnail height */
#if defined(__MMI_MAINLCD_128X128__)
    #define CAT280_THUMBNAIL_FRAME_HEIGHT (45)
#elif defined(__MMI_MAINLCD_128X160__)
    #define CAT280_THUMBNAIL_FRAME_HEIGHT (50)
#elif defined(__MMI_MAINLCD_320X480__)
    #define CAT280_THUMBNAIL_FRAME_HEIGHT (87)
#else /* 176x220, 240x320, 320x240, 240x400 */ 
    #define CAT280_THUMBNAIL_FRAME_HEIGHT (80)
#endif

#ifdef __WGUI_CAT280_SUPPORT_RECIPIENTS__
#define CAT280_RECIPIENTS_MAX_CHAR_COUNT  (13)
#define CAT280_RECIPIENTS_MAX_NUM         (20)
#endif /* __WGUI_CAT280_SUPPORT_RECIPIENTS__ */

#define CAT280_THUMBNAIL_BUFFER_SIZE ((CAT280_THUMBNAIL_FRAME_HEIGHT*LCD_WIDTH*GDI_MAINLCD_BIT_PER_PIXEL)>>3)

/* information bar height */
#ifdef __MMI_FTE_SUPPORT__
    #if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
        #define CAT280_INFORMATION_BAR_HEIGHT                   (50) 
        #define CAT280_INFORMATION_BAR_GAP_X                     (5) 
        #define CAT280_INFORMATION_BAR_GAP_MIDDLE              (0)
        #define CAT280_INFORMATION_BAR_MMS_PAGE_TEXT_MIX_W  (46)
        #define CAT280_INFORMATION_BAR_MSG_SIZE_GAP_X         (3)
        #define CAT280_INFORMATION_BAR_MSG_SIZE_GAP_Y         (2)
        #define CAT280_INFORMATION_BAR_IMG_BORDER              (1)
        #define CAT280_INFORMATION_BAR_BUTTON_GAP_Y            (3)
    #elif defined(__MMI_MAINLCD_320X480__)
        #define CAT280_INFORMATION_BAR_HEIGHT                    (54)
        #define CAT280_INFORMATION_BAR_GAP_X                     (6) 
        #define CAT280_INFORMATION_BAR_GAP_MIDDLE               (20)
        #define CAT280_INFORMATION_BAR_MMS_PAGE_TEXT_MIX_W  (66)
        #define CAT280_INFORMATION_BAR_MSG_SIZE_GAP_X         (6)
        #define CAT280_INFORMATION_BAR_MSG_SIZE_GAP_Y         (4)
        #define CAT280_INFORMATION_BAR_IMG_BORDER              (2)
        #define CAT280_INFORMATION_BAR_BUTTON_GAP_Y            (6)
    #elif defined(__MMI_MAINLCD_320X240__)
        #define CAT280_INFORMATION_BAR_HEIGHT                    (54)
        #define CAT280_INFORMATION_BAR_GAP_X                     (6) 
        #define CAT280_INFORMATION_BAR_GAP_MIDDLE               (20)
        #define CAT280_INFORMATION_BAR_MMS_PAGE_TEXT_MIX_W  (66)
        #define CAT280_INFORMATION_BAR_MSG_SIZE_GAP_X         (6)
        #define CAT280_INFORMATION_BAR_MSG_SIZE_GAP_Y         (4)
        #define CAT280_INFORMATION_BAR_IMG_BORDER              (2)
        #define CAT280_INFORMATION_BAR_BUTTON_GAP_Y            (6)
    #else
        #define CAT280_INFORMATION_BAR_HEIGHT                    (0)
        #define CAT280_INFORMATION_BAR_GAP_X                     (0) 
        #define CAT280_INFORMATION_BAR_GAP_MIDDLE               (0)
        #define CAT280_INFORMATION_BAR_MMS_PAGE_TEXT_MIX_W  (0)
        #define CAT280_INFORMATION_BAR_MSG_SIZE_GAP_X         (0)
        #define CAT280_INFORMATION_BAR_MSG_SIZE_GAP_Y         (0)
        #define CAT280_INFORMATION_BAR_IMG_BORDER              (0)
        #define CAT280_INFORMATION_BAR_BUTTON_GAP_Y            (0)
    #endif
#else
    #if defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__)
        #if defined(__MMI_TOUCH_SCREEN__)
        #define CAT280_INFORMATION_BAR_HEIGHT (34) /* This value must be even number */
        #else
        #define CAT280_INFORMATION_BAR_HEIGHT (30) /* This value must be even number */
        #endif
    #elif defined(__MMI_MAINLCD_320X240__)
        #define CAT280_INFORMATION_BAR_HEIGHT (30) /* about 2 times of small font height */
    #elif defined(__MMI_MAINLCD_320X480__)
        #define CAT280_INFORMATION_BAR_HEIGHT (48) //(36)
    #else /* 176x220, 240x320, 240x400 */
        #define CAT280_INFORMATION_BAR_HEIGHT (INFORMATION_BAR_HEIGHT << 1)
    #endif
#endif /* __MMI_FTE_SUPPORT__ */

#define CAT280_SUBJECT_H (Get_CharDisplayHeightOfAllLangAndType(MMI_medium_font.size) + 2)

#if defined(__MMI_MAINLCD_240X400__)  || defined(__MMI_MAINLCD_320X240__) 
    #define CAT280_INFORMATION_BAR_HEIGHT_SMS                      (26)
    #define CAT280_INFORMATION_BAR_GAP_X_SMS                       (6)
    #define CAT280_INFORMATION_BAR_GAP_Y_SMS                       (4)
#elif defined(__MMI_MAINLCD_240X320__)   
    #define CAT280_INFORMATION_BAR_HEIGHT_SMS                      (27)
    #define CAT280_INFORMATION_BAR_GAP_X_SMS                       (6)
    #define CAT280_INFORMATION_BAR_GAP_Y_SMS                       (4)
#elif defined(__MMI_MAINLCD_320X480__)
    #define CAT280_INFORMATION_BAR_HEIGHT_SMS                      (28)
    #define CAT280_INFORMATION_BAR_GAP_X_SMS                       (6)
    #define CAT280_INFORMATION_BAR_GAP_Y_SMS                       (3)
#elif defined(__MMI_MAINLCD_96X64__)
    #define CAT280_INFORMATION_BAR_HEIGHT_SMS                      (9)
    #define CAT280_INFORMATION_BAR_GAP_X_SMS                       (4)
    #define CAT280_INFORMATION_BAR_GAP_Y_SMS                       (1)    
#else
    #define CAT280_INFORMATION_BAR_HEIGHT_SMS                      (22)
    #define CAT280_INFORMATION_BAR_GAP_X_SMS                       (4)
    #define CAT280_INFORMATION_BAR_GAP_Y_SMS                       (4)
#endif

#if defined (__MMI_MAINLCD_240X320__)
#define SPECIAL_GAP 1
#else /*__MMI_MAINLCD_240X320__*/ 
#define SPECIAL_GAP 0
#endif /*__MMI_MAINLCD_240X320__*/
/* multiline editor line height */
#if defined(__MMI_MAINLCD_128X128__)
#define CAT280_MIN_LINE_HEIGHT 19
#define CAT280_VMARGIN 6
#define CAT280_HMARGIN 3
#ifdef __WGUI_CAT280_SUPPORT_RECIPIENTS__
#define CAT280_INLINE_SL_HEIGHT 27
#endif /* __WGUI_CAT280_SUPPORT_RECIPIENTS__ */
#elif defined(__MMI_MAINLCD_96X64__)
#define CAT280_MIN_LINE_HEIGHT 9
#define CAT280_VMARGIN 6
#define CAT280_HMARGIN 3
#ifdef __WGUI_CAT280_SUPPORT_RECIPIENTS__
#define CAT280_INLINE_SL_HEIGHT 27
#endif /* __WGUI_CAT280_SUPPORT_RECIPIENTS__ */
#elif defined(__MMI_MAINLCD_128X160__)
#define CAT280_MIN_LINE_HEIGHT 19
#define CAT280_VMARGIN 6
#define CAT280_HMARGIN 3
#ifdef __WGUI_CAT280_SUPPORT_RECIPIENTS__
#define CAT280_INLINE_SL_HEIGHT 27
#endif /* __WGUI_CAT280_SUPPORT_RECIPIENTS__ */
#elif defined(__MMI_MAINLCD_176X220__)
#define CAT280_MIN_LINE_HEIGHT 21
#define CAT280_VMARGIN 6
#define CAT280_HMARGIN 6
#ifdef __WGUI_CAT280_SUPPORT_RECIPIENTS__
#define CAT280_INLINE_SL_HEIGHT 27
#endif /* __WGUI_CAT280_SUPPORT_RECIPIENTS__ */
#elif defined(__MMI_MAINLCD_320X480__)
#define CAT280_MIN_LINE_HEIGHT 29
#define CAT280_VMARGIN 6
#define CAT280_HMARGIN 4
#ifdef __WGUI_CAT280_SUPPORT_RECIPIENTS__
#define CAT280_INLINE_SL_HEIGHT 35
#endif /* __WGUI_CAT280_SUPPORT_RECIPIENTS__ */
#else /* 240x320, 320x240, 240x400 */
#define CAT280_MIN_LINE_HEIGHT 27
#define CAT280_VMARGIN 6
#define CAT280_HMARGIN 4
#ifdef __WGUI_CAT280_SUPPORT_RECIPIENTS__
#define CAT280_INLINE_SL_HEIGHT 35
#endif /* __WGUI_CAT280_SUPPORT_RECIPIENTS__ */
#endif 

#ifdef __WGUI_CAT280_SUPPORT_RECIPIENTS__
#define WGUI_CAT280_INLINE_SL_OFFSET_Y                (3)
#define WGUI_CAT280_INLINE_SL_TEXT_DEFAULT_HEIGHT   ((CAT280_INLINE_SL_HEIGHT >> 1) + (CAT280_INLINE_SL_HEIGHT >> 2))
#endif /* __WGUI_CAT280_SUPPORT_RECIPIENTS__ */

/* DOM-NOT_FOR_SDK-END */

#ifdef __WGUI_CAT280_ENHANCED_UI__
#define CAT280_INFORMATION_BAR_ATTACH_BUTTON_GAP    (8)
#endif /* __WGUI_CAT280_ENHANCED_UI__ */

#ifdef __WGUI_CAT280_SUPPORT_RECIPIENTS__
/* cat28 recipients flag */
#define WGUI_UCE_DEFAULT_FLAGS                          (0x00000000)
#define WGUI_UCE_HIGHLIGHT_RECIPIENT                    (0x00000001)
#define WGUI_UCE_WRAPPING_DELETE_RECIPIENT            (0x00000002)
#endif /* __WGUI_CAT280_SUPPORT_RECIPIENTS__ */

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/* Unified composer type */
typedef enum
{
    WGUI_UCE_MSG_TYPE_SMS, /* SMS */
    WGUI_UCE_MSG_TYPE_MMS, /* MMS */
    WGUI_UCE_MSG_TYPE_TOTAL
} wgui_uce_msg_type_enum;

/* Thumbmail layout position */
typedef enum
{
    WGUI_UCE_LAYOUT_TYPE_THUMBNAIL_AT_TOP,      /* thumbnail at top */
    WGUI_UCE_LAYOUT_TYPE_THUMBNAIL_AT_BOTTOM,   /* thumbnail at bottom */
    WGUI_UCE_LAYOUT_TYPE_THUMBNAIL_TOTAL
} wgui_uce_layout_type_enum;

#ifdef __WGUI_CAT280_SUPPORT_RECIPIENTS__
typedef enum
{
    WGUI_UCE_TO_RECIPIENTS = 1,
    WGUI_UCE_CC_RECIPIENTS,
    WGUI_UCE_BCC_RECIPIENTS,
    WGUI_UCE_SUBJECT,
    WGUI_UCE_THUMBNAIL,
    WGUI_UCE_AUDIO,
    WGUI_UCE_EDITOR,
    WGUI_UCE_EMPTY,
    WGUI_UCE_TO_LABEL,
    WGUI_UCE_CC_LABEL,
    WGUI_UCE_BCC_LABEL,
    WGUI_UCE_TOTAL
} wgui_uce_region_id_enum;

typedef enum
{
    WGUI_UCE_HIGHLIGHT_TO_RECIPIENTS = 1,   /* highlight on "to" recipients */
    WGUI_UCE_HIGHLIGHT_CC_RECIPIENTS,       /* highlight on  "cc" recipients */
    WGUI_UCE_HIGHLIGHT_BCC_RECIPIENTS,      /* highlight on  "bcc" recipients */
    WGUI_UCE_HIGHLIGHT_SUBJECT,      /* highlight on subject */
    WGUI_UCE_HIGHLIGHT_THUMBNAIL,   /* highlight on attachment */
    WGUI_UCE_HIGHLIGHT_AUDIO,        /* highlight on audio */
    WGUI_UCE_HIGHLIGHT_EDITOR,       /* highlight on editor */   
    WGUI_UCE_HIGHLIGHT_EMPTY,
    WGUI_UCE_HIGHLIGHT_TO_LABEL,
    WGUI_UCE_HIGHLIGHT_CC_LABEL,
    WGUI_UCE_HIGHLIGHT_BCC_LABEL,
    WGUI_UCE_HIGHLIGHT_TOTAL
} wgui_uce_highlight_state_enum;
#else
typedef enum
{
    WGUI_UCE_SUBJECT,
    WGUI_UCE_THUMBNAIL,
    WGUI_UCE_AUDIO,
    WGUI_UCE_EDITOR,
    WGUI_UCE_TOTAL
} wgui_uce_region_id_enum;

typedef enum
{
    WGUI_UCE_HIGHLIGHT_SUBJECT,     /* highlight on subject */
    WGUI_UCE_HIGHLIGHT_THUMBNAIL,   /* highlight on attachment */
    WGUI_UCE_HIGHLIGHT_AUDIO,        /* highlight on audio */
    WGUI_UCE_HIGHLIGHT_EDITOR,      /* highlight on editor */       
    WGUI_UCE_HIGHLIGHT_TOTAL
} wgui_uce_highlight_state_enum;
#endif /* __WGUI_CAT280_SUPPORT_RECIPIENTS__ */

typedef enum
{
    WGUI_UCE_CHANGE_SLIDE_PREVIOUS,
    WGUI_UCE_CHANGE_SLIDE_NEXT,
    WGUI_UCE_CHANGE_SLIDE_TOTAL
} wgui_uce_change_slide_enum;

/* MMS object type */
typedef enum
{
    WGUI_UCE_OBJECT_TYPE_IMAGE,   /* image */
    WGUI_UCE_OBJECT_TYPE_AUDIO,   /* audio */
    WGUI_UCE_OBJECT_TYPE_VIDEO,   /* video */
    WGUI_UCE_OBJECT_TYPE_ATTACHMENT,  /* attachment */
    WGUI_UCE_OBJECT_TYPE_TOTAL
} wgui_uce_object_type_enum;

/* UCE text info structure */
typedef struct
{
    U16 char_count;             /* Total Character Count */
    U16 utf8_msg_len;           /* Msg Len in UTF8 */
    U16 extension_char_count;   /* EXT CHAR Count */
    U16 UCS2_count;             /* UCS2 characters count that are not also extension characters */
} wgui_uce_text_info_struct;

#ifdef __WGUI_CAT280_SUPPORT_RECIPIENTS__
/* UCE recipients info structure */
typedef struct
{
    MMI_BOOL is_valid;                   /* only valid recipient will be displayed */
    UI_buffer_type input_buf;             /* name buffer */
    U32 editor_flags;                     /* editor flags */
    wgui_uce_region_id_enum region_id;   /* in "TO" or "CC" or "BCC" */ 
    S32 app_mapping_index;
} wgui_uce_recipients_struct;


/* UCE recipients label structure */
typedef struct
{
    PU8 label_normal_image;               /* Label normal image */
    PU8 label_pressed_image;              /* Label pressed image */
    FuncPtr label_callback;                  /* Label callback function */
} wgui_uce_recipients_label_struct;


/* UCE subject info structure */
typedef struct
{
    UI_string_type label_string;             /* The labed of the current group */
    UI_buffer_type input_buf;               /* Editors buffer */
    S32 buffer_size;
    U32 input_type;                        /* Input type */
} wgui_uce_subject_struct;
#endif /* __WGUI_CAT280_SUPPORT_RECIPIENTS__ */

/* DOM-NOT_FOR_SDK-BEGIN */
typedef struct
{
#ifdef __WGUI_CAT280_SUPPORT_MMS__
    wgui_uce_msg_type_enum msg_type;
#endif /* __WGUI_CAT280_SUPPORT_MMS__ */

    U8 *text_buffer;        /* always UCS2. */
    U32 text_buffer_size;
    wgui_uce_text_info_struct text_info;
    U8 total_character;
    
#ifdef __WGUI_CAT280_SUPPORT_MMS__
    U8 total_slides;
    U8 current_slide;
    MMI_BOOL has_thumbnail;
    MMI_BOOL is_image;
    MMI_BOOL is_audio;
    MMI_BOOL is_video;
    MMI_BOOL is_attachment;
    wgui_uce_layout_type_enum layout;
    U16 file_path[FS_MAX_PATH/2];   /* Currently ~260 characters */
    U16 default_image_id;
    U8 *thumbnail_buffer;   /* allocated by category using screen based ASM and freed in exit category */
    U16 pre_bt;
    U16 next_bt;
    UI_string_type subject_firstline;
    UI_string_type subject_secondline;
#endif /* __WGUI_CAT280_SUPPORT_MMS__ */
    wgui_uce_region_id_enum highligh_state;

#ifdef __WGUI_CAT280_SUPPORT_RECIPIENTS__
    S32 editor_input_type;
    U16 right_softkey;
    U16 right_softkey_icon;
    wgui_uce_recipients_label_struct to_recipients;
    wgui_uce_recipients_label_struct cc_recipients;
    wgui_uce_recipients_label_struct bcc_recipients;
    S32 label_x;
    S32 label_w;
    S32 label_h;
    wgui_uce_region_id_enum button_down_region;

    MMI_BOOL inline_recipients;
    wgui_uce_recipients_struct *recipient;//replace with macro
    S32 recipient_buffer_size;   /* buffer size for one recipient */
    U32 recipient_input_type;   /* input type */

    S32 max_recipients_num;
    S32 to_recipients_num;
#ifdef __WGUI_CAT280_SUPPORT_MMS__
    S32 cc_recipients_num;
    S32 bcc_recipients_num;
    wgui_uce_subject_struct subject;
    MMI_BOOL has_editable_subject;
#endif /* __WGUI_CAT280_SUPPORT_MMS__ */

    S32 max_label_width;
    S32 highlight_index;
    UI_buffer_type sl_history;
    MMI_BOOL is_insert_semicolon;
    U16 current_inputs;

    MMI_BOOL need_to_set_sl_ime;
    mmi_imc_history sl_ime;
    MMI_BOOL need_to_set_ml_ime;
    mmi_imc_history ml_ime;
    MMI_BOOL need_to_set_subject_ime;
    mmi_imc_history subject_ime;

    MMI_BOOL add_recipient_in_background;
    MMI_BOOL add_content_in_background;
    
#ifdef __WGUI_CAT280_SUPPORT_MMS__
    MMI_BOOL in_change_slide;
#endif /* __WGUI_CAT280_SUPPORT_MMS__ */
#endif /* __WGUI_CAT280_SUPPORT_RECIPIENTS__ */

#ifdef __WGUI_CAT280_ENHANCED_UI__
    icontext_button attach_button;     
    wgui_uce_layout_type_enum audio_layout;
    U16 audio_image_id;
    wgui_uce_region_id_enum old_highlight_state;
#endif /* __WGUI_CAT280_ENHANCED_UI__ */
} wgui_uce_context_struct;
/* DOM-NOT_FOR_SDK-END */

/* uce text change result */
typedef enum
{
    WGUI_UCE_TEXT_CHANGE_ALLOWED,     /* change allowed */
    WGUI_UCE_TEXT_CHANGE_NOT_ALLOWED, /* change not allowed */
    WGUI_UCE_TEXT_CHANGE_TOTAL
} wgui_uce_text_change_result_enum;

/* uce information bar display type */
typedef enum
{
    WGUI_UCE_DISPLAY_SIZE,   /* display size */
    WGUI_UCE_DISPLAY_CHARACTER,  /* display character */
    WGUI_UCE_DISPLAY_TOTAL
} wgui_uce_display_enum;

typedef wgui_uce_text_change_result_enum(*wgui_uce_text_change_callback) (wgui_uce_text_info_struct *new_text_info);
typedef U32(*wgui_uce_get_message_size_callback) (wgui_uce_text_info_struct *current_text_info, wgui_uce_msg_type_enum uce_msg_type);
typedef wgui_uce_display_enum (*wgui_uce_get_display_type_callback) (void);
typedef U32(*wgui_uce_get_sms_remaining_character_callback) (wgui_uce_text_info_struct *current_text_info);
typedef U32(*wgui_uce_get_sms_segment_callback) (wgui_uce_text_info_struct *current_text_info);
typedef void (*wgui_uce_highlight_handler) (wgui_uce_highlight_state_enum highlight_state);
typedef void (*wgui_uce_change_slide_handler) (wgui_uce_change_slide_enum change_slide);

#ifdef __WGUI_CAT280_SUPPORT_RECIPIENTS__
typedef void (*wgui_uce_highlight_handler_ext) (wgui_uce_highlight_state_enum highlight_state, S32 highlight_index);
typedef void (*wgui_uce_recipient_changed_handler) (S32 recipient_index);
#endif /* __WGUI_CAT280_SUPPORT_RECIPIENTS__ */

#ifdef __WGUI_CAT280_ENHANCED_UI__
typedef void (*wgui_uce_object_highlight_callback) (wgui_uce_region_id_enum highlight_state);
#endif /* __WGUI_CAT280_ENHANCED_UI__ */

/***************************************************************************** 
* Extern Global Variable
*****************************************************************************/

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  wgui_uce_insert_text
 * DESCRIPTION
 *  Copied text into category buffer and updates the text info of category.
 *  APP will call this to start to edit a slide whose info APP already has
 * PARAMETERS
 *  text_info      : [OUT] (N/A)    Text info buffer
 *  text_buffer    : [OUT] (N/A)    Text buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_uce_insert_text(wgui_uce_text_info_struct *text_info, U8 *text_buffer);

/*****************************************************************************
 * FUNCTION
 *  wgui_uce_insert_text_template
 * DESCRIPTION
 *  Inserts partially. Input callbacks will be called and text info will be updated.
 * PARAMETERS
 *  string         : [IN] (N/A)       String to insert
 *  no_of_char     : [IN] (N/A)       Non-used
 *  guibuffer      : [IN] (N/A)       History buffer
 * RETURNS
 *  number of characters inserted
 *****************************************************************************/
extern U32 wgui_uce_insert_text_template(U8 *string, U16 no_of_char, U8 *guibuffer);

/*****************************************************************************
 * FUNCTION
 *  wgui_uce_get_current_text_info
 * DESCRIPTION
 *  APP uses this utility function to get the text info for current buffer
 * PARAMETERS
 *  current_text_info      : [OUT] (N/A)    Current text info
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_uce_get_current_text_info(wgui_uce_text_info_struct *current_text_info);

/*****************************************************************************
 * FUNCTION
 *  wgui_uce_set_current_text_info
 * DESCRIPTION
 *  APP uses this utility function to set the text info for current buffer
 * PARAMETERS
 *  text_info              : [IN] (N/A)    Current text info
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_uce_set_current_text_info(wgui_uce_text_info_struct *text_info);

/*****************************************************************************
 * FUNCTION
 *  wgui_uce_get_text_info_for_buffer
 * DESCRIPTION
 *  APP can use this utility function to get the text info of buffer.
 *  Note: This function is used with wgui_uce_insert_text, to edit a saved text sms/mms as fresh.
 *  To insert template use wgui_uce_insert_text_template 
 * PARAMETERS
 *  text_info      : [OUT] (N/A)    Text info buffer
 *  text_buffer    : [IN] (N/A)     Text buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_uce_get_text_info_for_buffer(wgui_uce_text_info_struct *text_info, U8 *text_buffer);

/*****************************************************************************
 * FUNCTION
 *  wgui_uce_add_object
 * DESCRIPTION
 *  Used to add an object, screen has to re-enter after add object
 * PARAMETERS
 *  object                 : [IN] (N/A)       Object to add
 *  file_path              : [IN] (N/A)       File path
 *  default_image_id       : [IN] (N/A)       Default image ID
 *  alignment_type         : [IN] (N/A)       Alignment Type
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_uce_add_object(
                wgui_uce_object_type_enum object,
                U16 *file_path,
                U16 default_image_id,
                wgui_uce_layout_type_enum alignment_type);
                
/*****************************************************************************
 * FUNCTION
 *  wgui_uce_delete_object
 * DESCRIPTION
 *  This is used to delete an object, screen has to re-enter again.
 * PARAMETERS
 *  object     : [IN] (N/A)       Object to delete
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_uce_delete_object(wgui_uce_object_type_enum object);

/*****************************************************************************
 * FUNCTION
 *  wgui_uce_initialize_editor
 * DESCRIPTION
 *  Initialize the editor context called on entering new slides, editing saved msg etc
 * PARAMETERS
 *  text_buffer            : [IN] (N/A)       Text string buffer
 *  text_buffer_size       : [IN] (N/A)       Buffer size
 *  new_slide_number       : [IN] (N/A)       New slide number
 *  total_slide_number     : [IN] (N/A)       Total slide number
 *  total_character        : [IN] (N/A)       Total character 
 *  get_msg_size           : [IN] (N/A)       Get message size callback
 *  text_change            : [IN] (N/A)       Text change callback
 *  get_display_type       : [IN] (N/A)       Get display type callback
 *  get_sms_rm_character   : [IN] (N/A)       Get SMS remain character callback
 *  get_sms_segment        : [IN] (N/A)       Get SMS segment
 *  highlight_handler      : [IN] (N/A)       MMS highlight handler
 *  slide_handler          : [IN] (N/A)       MMS change slide handler
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_uce_initialize_editor(
                U8 *text_buffer,
                U16 text_buffer_size,
                U8 new_slide_number,
                U8 total_slide_number,
                U8 total_character,
                wgui_uce_get_message_size_callback get_msg_size,
                wgui_uce_text_change_callback text_change,
                wgui_uce_get_display_type_callback get_display_type,
                wgui_uce_get_sms_remaining_character_callback get_sms_rm_character,
                wgui_uce_get_sms_segment_callback get_sms_segment,
                wgui_uce_highlight_handler highlight_handler,
                wgui_uce_change_slide_handler slide_handler);

#ifdef __WGUI_CAT280_SUPPORT_RECIPIENTS__
/*****************************************************************************
 * FUNCTION
 *  wgui_uce_initialize_recipients
 * DESCRIPTION
 *  Initialize the recipients information
 * PARAMETERS
 *  to_lab                   : [IN] (N/A)       To label
 *  cc_lab                   : [IN] (N/A)       CC label
 *  bcc_lab                  : [IN] (N/A)       BCC label
 *  subject                  : [IN] (N/A)       subject information
 *  recipients_info          : [IN] (N/A)       recipients information
 *  buffer_size              : [IN] (N/A)       buffer size for one recipient
 *  input_type               : [IN] (N/A)       recipients input type
 *  highlight_handler_ext    : [IN] (N/A)       highlight handler
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_uce_initialize_recipients(
                wgui_uce_recipients_label_struct *to_lab,
                wgui_uce_recipients_label_struct *cc_lab,
                wgui_uce_recipients_label_struct *bcc_lab,
                wgui_uce_subject_struct *subject,
                wgui_uce_recipients_struct recipients_info[],
                S32 max_recipients_num,
                S32 buffer_size,
                U32 input_type,
                wgui_uce_highlight_handler_ext highlight_handler_ext);

#endif /* __WGUI_CAT280_SUPPORT_RECIPIENTS__ */

/*****************************************************************************
 * FUNCTION
 *  SetCategory280RightSoftkeyFunction
 * DESCRIPTION
 *  Used to set the right softkey function. This has to called by application.
 * PARAMETERS
 *  f      : [IN] (N/A)       RightSoftkey function 
 *  k      : [IN] (N/A)       Key event type
 * RETURNS
 *  void
 *****************************************************************************/
extern void SetCategory280RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k);
/* DOM-NOT_FOR_SDK-BEGIN */ 
#define SetCategory280RightSoftkeyFunction(_arg0, _arg1) wgui_inputs_category_set_rsk_func(_arg0)
/* DOM-NOT_FOR_SDK-END */

/**************************************************************************
  * FUNCTION
  * ShowCategory280Screen
  * Description
  * This the show category function, basically we set some options on basis
  * on msg type here.
  * wgui_uce_initialize_editor should be called once before we call
  * ShowCategory280Screen
  *  [FTE]: support(tool bar is avaiable)
  * 
  * <img name="wgui_cat280_img1" />
  * PARAMETERS
  *  title                  : [IN] (TITLE)      Title for the screen
  *  title_icon             : [IN] (N/A)        Icon shown with the title
  *  left_softkey           : [IN] (LSK)        Left softkey label
  *  left_softkey_icon      : [IN] (N/A)        Icon for the left softkey
  *  right_softkey          : [IN] (RSK)        Right softkey label
  *  right_softkey_icon     : [IN] (N/A)        Icon for the right softkey
  *  msg_type               : [IN] (N/A)        Msg type
  *  input_method_type      : [IN] (N/A)        Input method type
  *  gui_buffer             : [IN] (N/A)        History buffer
  * Returns
  *  void                                                                  
  **************************************************************************/
extern void ShowCategory280Screen(
                U16 title,
                U16 title_icon,
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                wgui_uce_msg_type_enum msg_type,
                U32 input_method_type,
                UI_string_type subjcet_firstline,
                UI_string_type subject_secondline,
                U8 *gui_buffer);

#ifdef __WGUI_CAT280_SUPPORT_RECIPIENTS__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat280_add_recipient
 * DESCRIPTION
 *  Add a new recipient.
 * PARAMETERS
 *  region_id               : [IN] (N/A) The region for new recipient.
 *  display_text            : [IN] (N/A) The name or number of the new recipient.
 *  editor_flags            : [IN] (N/A) Editor flags.
 *  highlight               : [IN] (N/A) Need to set highlight or not.
 *  app_mapping_index       : [IN] (N/A) Index for mapping to PHB.
 * RETURNS
 *  MMI_BOOL     If the number of recipients over the top-limit, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL wgui_cat280_add_recipient(
        wgui_uce_region_id_enum region_id,
        UI_string_type display_text,
        U32 editor_flags,
        MMI_BOOL highlight,
        S32 app_mapping_index);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat280_remove_recipient
 * DESCRIPTION
 *  Remove a recipient.
 * PARAMETERS
 *  buffer_index        : [IN] (N/A) The recipient buffer index.
 * RETURNS
 *  MMI_BOOL     If the recipients over is invalid, return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL wgui_cat280_remove_recipient(S32 buffer_index);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat280_is_recipient_changed
 * DESCRIPTION
 *  Change the recipients by app.
 * PARAMETERS
 *  recipient_changed  :                [IN] (N/A) flags.
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat280_is_recipient_changed(MMI_BOOL recipient_changed);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat280_get_highlight_state
 * DESCRIPTION
 *  get current highlight state.
 * PARAMETERS
 *  void
 * RETURNS
 *  wgui_uce_region_id_enum     return the highlight state.
 *****************************************************************************/
extern wgui_uce_region_id_enum wgui_cat280_get_highlight_state(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat280_get_highlight_buffer_index
 * DESCRIPTION
 *  if highlight state on recipients area, return the current buffer index
 *  else return (-1)
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 wgui_cat280_get_highlight_buffer_index(void);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat280_get_buffer_index
 * DESCRIPTION
 *  get the buffer index, based on recipients region and index.
 * PARAMETERS
 *  region_id    [IN]    region id
 *  region_index [IN]    recipient index in the current region
 * RETURNS
 *  S32     return buffer index, if the recipient does not exist, return (-1).
 *****************************************************************************/
extern S32 wgui_cat280_get_buffer_index(wgui_uce_region_id_enum region_id, S32 region_index);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat280_get_recipients_num
 * DESCRIPTION
 *  get the recipients number in the region.
 * PARAMETERS
 *  region_id    [IN]    region id
 * RETURNS
 *  S32   return the recipients number.
 *****************************************************************************/
extern S32 wgui_cat280_get_recipients_num(wgui_uce_region_id_enum region_id);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat28_register_recipient_change_callback
 * DESCRIPTION
 *  If single line editor text changed, we will callback to app if necessary.
 * PARAMETERS
 *  func:           [IN] (N/A) the change callback function.     
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat28_register_recipient_change_callback(wgui_uce_recipient_changed_handler func);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat280_register_recipient_change_callback
 * DESCRIPTION
 *  If single line editor text changed, we will callback to app if necessary.
 * PARAMETERS
 *  func:           [IN] (N/A) the change callback function.     
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat280_register_recipient_change_callback(wgui_uce_recipient_changed_handler func);

#else /* __WGUI_CAT280_SUPPORT_RECIPIENTS__ */
/*****************************************************************************
 * FUNCTION
 *  wgui_cat280_get_highlight_state
 * DESCRIPTION
 *  get highlight state
 * PARAMETERS
 *  void
 * RETURNS
 *  wgui_uce_highlight_state_enum
 *****************************************************************************/
extern wgui_uce_highlight_state_enum wgui_cat280_get_highlight_state(void);
#endif /* __WGUI_CAT280_SUPPORT_RECIPIENTS__ */

#ifdef __WGUI_CAT280_ENHANCED_UI__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat280_register_attach_button_callback
 * DESCRIPTION
 *  Attach button call back
 * PARAMETERS
 *  func:           [IN] (N/A) the callback function.     
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat280_register_attach_button_callback(FuncPtr func);

/*****************************************************************************
 * FUNCTION
 *  wgui_cat280_register_object_callback
 * DESCRIPTION
 *  If tap on highlighted object, we will invoke this callback.
 * PARAMETERS
 *  func:           [IN] (N/A) the change callback function.     
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat280_register_object_callback(wgui_uce_object_highlight_callback func);

#endif /* __WGUI_CAT280_ENHANCED_UI__ */

//#endif /* __UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__ */

#endif /* __WGUI_CATEGORIES_UCE_H__ */ 


