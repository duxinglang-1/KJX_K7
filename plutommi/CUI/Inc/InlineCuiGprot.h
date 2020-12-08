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
 *  InlineCuiGprot.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MMI_INLINECUIGPROT_H
#define MMI_INLINECUIGPROT_H

#ifdef __cplusplus
extern "C"{
#endif 

#include "wgui_inline_edit.h"


#include "MMIDataType.h"
#include "ImeGprot.h"
#include "gui_data_types.h"
#include "gui_typedef.h"
#include "mmi_res_range_def.h"
#include "MMI_features.h"
#include "kal_general_types.h"
#include "gui_virtual_keyboard_language_type.h"
#include "mmi_frm_mem_gprot.h"
#include "gui_inputs.h"

#ifdef __cplusplus
}
#endif


/*****************************************************************************  
*   Macro 
*****************************************************************************/
#define INLINE_EVENT_BASE                       100
#define CUI_INLINE_ITEM_ID_BASE                 1000
#define CUI_INLINE_INVALID_ID                   0xFFFF

#define CUI_INLINE_SET_ATTRIBUTE                0
#define CUI_INLINE_RESET_ATTRIBUTE              1

#define CUI_INLINE_SET_EXT_ATTRIBUTE            2
#define CUI_INLINE_RESET_EXT_ATTRIBUTE          3

#define CUI_INLINE_ITEM_LEFT_JUSTIFY            0x00000100
#define CUI_INLINE_ITEM_RIGHT_JUSTIFY           0x00000200                    /* item right align */
#define CUI_INLINE_ITEM_CENTER_JUSTIFY          0x00000400                    /* item center align */
#define CUI_INLINE_ITEM_DISABLE_LIST_HIGHLIGHT  0x00000800                    /* item  have no highlight background color */
#define CUI_INLINE_ITEM_BOUNDARY                0x00001000                    /* item have  border frame */
#define CUI_INLINE_ITEM_DISABLE                 0x00002000                    /* item can not be highlight */                             
#define CUI_INLINE_ITEM_DRAW_AS_CONTROL         0x00004000                    /* this flag is just for select, color select, image text */
#define CUI_INLINE_ITEM_FULL_WIDTH              0x00008000                    /* item text is align to left screen  frame*/
#ifndef __MMI_INLINE_SLIM__
#define CUI_INLINE_ITEM_DOTTED_UNDERLINE        0x00010000                    /* item have special bottom line */
#endif
#define CUI_INLINE_ITEM_DEFAULT_TEXT            0x00080000                    /* item default text */
#ifndef __MMI_INLINE_SLIM__
#define CUI_INLINE_ITEM_IS_FULLSCREEN_OPEN      0x00100000                    /* Fullscreen item status, just use by inline internal */  
#define CUI_INLINE_ITEM_IS_FULLSCREEN_CHANGE    0x00200000                    /* Fullscreen item status, just use by inline internal */
#define CUI_INLINE_ITEM_DISABLE_CURSOR          0x00400000                    /* Disable singleline item cursor. */
#endif
#define CUI_INLINE_ITEM_NO_LEADING_ZERO		0X00800000					  /* Allow singleline input begin with zero. just use by Textedit item. */	
#define CUI_INLINE_ITEM_DEFAULT_ICON            0X01000000                    /* Default icon for singleline item */
#ifndef __MMI_INLINE_SLIM__
#define CUI_INLINE_ITEM_SELECT_NO_LOOP          0x02000000                    /* Just for selector, set item show loop or not. */  
#endif
#define CUI_INLINE_ITEM_DISPLAY_NO_RESPONSE_NUMKEY  0x02000000
#define CUI_INLINE_ITEM_TEXTEDIT_FIRST_CURSOR   0x02000000
#define CUI_INLINE_ITEM_DISPLAY_ONLY_SHOW       0x04000000                    /* In FTE, disable icon indicator for displayonly item. */  
#define CUI_INLINE_ITEM_YEAR_ONLY				0x08000000					  /* In BWFWT, only show year with date component. */


#define CUI_INLINE_SCREEN_LOOP                  0x00000100                    /* the inline menu list can loop show */   
#define CUI_INLINE_SCREEN_DEFAULT_TEXT          0x00000200                    /* the inline menu item support default text */
#define CUI_INLINE_SCREEN_DISABLE_DONE          0x00000400                    /* the inline screen  is disable done style */
#define CUI_INLINE_SCREEN_CHANGED               0x00000800                    /* set inline  screen status to ¡®changed¡¯*/
#define CUI_INLINE_SCREEN_DISABLE_LOOP          0x00001000

#define CUI_INLINE_INSERT_TAIL                  0xFFFF                        /* Insert item to last position  */

#define CUI_INLINE_SOFTKEY_DEFAULT_VALUE        0XFFFF

#define CUI_INLINE_TEXT_BUFFER_SIZE             256

#define CUI_INLINE_RETURN_ERROR         -1


/*****************************************************************************  
*    
*****************************************************************************/
typedef enum
{
    CUI_INLINE_ITEM_TYPE_CAPTION = 1,
    CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY,
    CUI_INLINE_ITEM_TYPE_BUTTON,
    CUI_INLINE_ITEM_TYPE_MULTILINE_RD_ONLY,
    CUI_INLINE_ITEM_TYPE_TEXT_EDIT,
    CUI_INLINE_ITEM_TYPE_MULTILINE_EDIT,
    CUI_INLINE_ITEM_TYPE_FULLSCREEN_EDIT,
    CUI_INLINE_ITEM_TYPE_IMAGE_TEXT,
    CUI_INLINE_ITEM_TYPE_DATE,
    CUI_INLINE_ITEM_TYPE_TIME,
    CUI_INLINE_ITEM_TYPE_TIME_PEROID,
    CUI_INLINE_ITEM_TYPE_IP4,
    CUI_INLINE_ITEM_TYPE_SELECT,
    CUI_INLINE_ITEM_TYPE_COLOR_SELECT,
    CUI_INLINE_ITEM_TYPE_USER_DEFINED_SELECT,
    CUI_INLINE_ITEM_TYPE_DOW,
    CUI_INLINE_ITEM_TYPE_PROGRESS_BAR,
    CUI_INLINE_ITEM_TYPE_RADIO_LIST,
    CUI_INLINE_ITEM_TYPE_CHECKBOX,
#if defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
    CUI_INLINE_ITEM_TYPE_CAPTION_THUMBNAIL,
#endif /* __MMI_PHB_PHOTO_STICKER_SUPPORT__ */
    CUI_INLINE_ITEM_MAX_ID    
}cui_inline_item_id;

/*
typedef enum
{
    CUI_INLINE_MAIN_SCREEN_SCRN_ID = 1,
    CUI_INLINE_FULLSCREEN_EDIT_SCRN_ID,
    CUI_INLINE_FULLSCREEN_OPTION_LIST_SCRN_ID,
    CUI_INLINE_IMAGETEXT_EDIT_SCRN_ID,
    CUI_INLINE_IMAGETEXT_OPIONT_LIST_SCRN_ID,
    CUI_INLINE_SCREEN_COUNT
}cui_inline_screen_id_enum;
*/

typedef enum
{
    CUI_INLINE_STATUS_CREATE,
    CUI_INLINE_STATUS_ACTIVE,
    CUI_INLINE_STATUS_INACTIVE,
    CUI_INLINE_STATUS_CLOSE
}cui_inline_status_enum;

/* data struct for setting caption item */
typedef struct
{
    /* string id */
    U16 string_id;
}cui_inline_item_caption_struct;

typedef struct
{
    /* string id */
    U16 string_id;
}cui_inline_item_button_struct;

#if defined(__MMI_PHB_PHOTO_STICKER_SUPPORT__)
typedef struct
{
    U32 style;				// 0 text ptr : 1 image id : 2 thumbnail path
    U16 string_id;
    U16 default_id;
    PU8 thumbnail_path;
    PU8 buffer_p;
}cui_inline_item_caption_tn_struct;
#endif /* __MMI_PHB_PHOTO_STICKER_SUPPORT__ */

/* data struct for setting displayonly item */
typedef struct
{
    /* string id */
    U16 string_id;
    U16 default_text_id;
}cui_inline_item_display_only_struct;

/* data struct for setting multiline readonly item */
typedef struct
{
    /* string id */
     U16 string_id;
    /* multiline row count */
     U8 height_of_item;
}cui_inline_item_multiline_rdonly_struct;

/* data struct for setting textedit item */
typedef struct
{
    /* string id */
    U16 string_id;
    /*default text string id*/
    U16 default_text_id;
    /* string count */
    U32 buffer_size;
    /* input type */
    U32 input_type;
    /* input extended type */
    S16 input_extended_type;
    /* required input mode */
    mmi_imm_input_mode_enum *required_input_mode_set;
}cui_inline_item_text_edit_struct;

/* data struct for setting multiline edit item */
typedef struct
{
    /* string id */
    U16 string_id;
    /* string count */
    U32 buffer_size;
    /* input type */
    U32 input_type;
    U8 height_of_item;
}cui_inline_item_multiline_edit_struct;

/* data struct for setting fullscreen edit item */
typedef struct
{
    U16 string_id;          /* string id */
    U16 default_text_id;    /*default text string id*/
    U16 title;              /* title string id */
    U16 title_icon;         /* title icon id */
    S16 input_extended_type;   /* input extended type */
    U32 input_type;         /* input type */
    S32 buffer_size;        /* string count */
    mmi_imm_input_mode_enum *required_input_mode_set;
}cui_inline_item_fullscreen_edit_struct;

/* data struct for setting imagetext item */
typedef struct 
{
    U16 image1_id;  /* icon1 id */
    U16 image2_id;  /* icon2 id */
    U16 image3_id;  /* icon3 id */
    U16 string_id;  /* string id */
    U16 title;      /*string title id */
    U16 title_icon; /* title icon id */
    S32 buffer_size; /* string count */
    U32 input_type;  /* input type */
} cui_inline_item_image_text_struct; 

typedef struct
{
    S32 n_items;
    S32 selected_item;
    PU8 *list_of_string;
}cui_inline_item_radio_list_struct;

typedef struct
{
    MMI_BOOL IsSelected;
    PU8 *text_p;
}cui_inline_item_checkbox_struct;

/* data struct for setting   selector item */
typedef struct
{
    U8 n_items;             /* item count */
    U8 highlighted_item;    /* highlighted item index */
    const U16 *list_of_item_id;   /* list of item id */
}cui_inline_item_select_struct;

#define cui_inline_item_user_defined_select_struct NULL

/* data struct for setting  color selector item */
typedef struct 
{
    U8 n_color;             /* item count */
    U8 highlight_index;     /* highlighted item index */
    const color *list_of_color;   /* list of item color */
}cui_inline_item_color_select_struct;

/* data struct for setting  dow selector item */
typedef struct
{
    PU8 list_of_states;     /* list of item status */
}cui_inline_item_dow_select_struct;

/* data struct for setting date and time item */
typedef struct 
{
     U16 year;          /* year */
     U16 month;         /* month */
     U16 day;           /* day */
     U16 hour;          /* hour */
     U16 minute;        /* minute */
     U16 second;        /* second */
} cui_inline_item_date_time_struct;

/* data struct for setting time period item */
typedef struct 
{
    cui_inline_item_date_time_struct date_time1;    /* date item struct */
    cui_inline_item_date_time_struct date_time2;    /* date item struct */
    /* 12 hours or 24 hours*/
    U8 date_format;    
} cui_inline_item_time_period_struct;

/* data struct for setting ip4 item */
typedef struct 
{
    U8 b1;  /* ip field */
    U8 b2;  /* ip field */
    U8 b3;  /* ip field */
    U8 b4;  /* ip field */
} cui_inline_item_ip4_struct;

/* data struct for setting time item */
typedef struct 
{
   cui_inline_item_date_time_struct date_time;  /* date item struct */
   /* 12 hours or 24 hours*/
   U8 date_format;     
} cui_inline_item_time_struct;

typedef struct
{
    U16 value;      /* value of progress bar */
    U16 max_value;  /* The max value of progress bar */
    U16 step_size;  /* value per step */
} cui_inline_item_progress_bar_struct;

/* items common structure */
typedef struct 
{
    U16 item_id;            /* item id*/
    U32 item_flag;          /* item flag */
    U16 image_id;           /* image id  */
    const void *item_data;  /* item data */
}cui_inline_set_item_struct;

/* items softkey attributes structure */
typedef struct
{
    U16 string_id;      /* string id */
    U16 image_id;       /* image id */
} cui_inline_softkey_attr_struct; 

/* items three softkey attributes structure */
typedef struct 
{
    cui_inline_softkey_attr_struct softkey[WGUI_MAX_SOFTKEYS];  /* softkey struct */
}cui_inline_item_softkey_struct ;

/* inline setting structure */
typedef struct
{
    U8  items_count;    /* item count */
    U16 title;          /* title string id */
    U16 title_icon;     /* title icon id */
    U32 screen_flag;    /* screen attribute */
    const cui_inline_item_softkey_struct * softkey;   /*  */
    const cui_inline_set_item_struct *  items;  /*  */
}cui_inline_struct;

/* CUI_INLINE_ITEM_SETTING_STRUCTURE_FOR_API */


/* DOM-NOT_FOR_SDK-BEGIN */
typedef struct 
{
    PU8 buffer;
    PU8 image1;
    PU8 image2;  
    PU8 image3; 
    S32 buffer_size; 
    U16 title;
    U16 title_icon;
    U32 input_type;
} cui_inline_set_item_image_text_struct; 

typedef struct
{
    PU8 buffer;
    U16 default_text_id;
    S32 buffer_size; 
    U16 title;
    U16 title_icon;
    U32 input_type;
    S16 input_extended_type;
    mmi_imm_input_mode_enum *required_input_mode_set;
}cui_inline_set_item_fullscreen_edit_struct;

typedef struct
{
    PU8 image1;
    PU8 image2; 
    PU8 image3; 
    U8 highlight_image;
}cui_inline_set_item_attachment_struct; 

typedef struct 
{
     U16 year;
     U16 month;
     U16 day;
     U16 hour;
     U16 minute;
     U16 second;
} cui_inline_set_item_date_time_struct;

typedef struct 
{
    cui_inline_item_date_time_struct date_time1;
    cui_inline_item_date_time_struct date_time2;
    /* 12 hours or 24 hours*/
    U8 date_format;    
} cui_inline_set_item_time_period_struct;

typedef struct 
{
    U8 b1;
    U8 b2;
    U8 b3;
    U8 b4;
} cui_inline_set_item_ip4_struct;

typedef struct 
{
   cui_inline_item_date_time_struct date_time;
   /* 12 hours or 24 hours*/
   U8 date_format;     
} cui_inline_set_item_time_struct;

typedef struct
{
    U16 value;
    U16 max_value;
    U16 step_size;
} cui_inline_set_item_progress_bar_struct;

typedef struct
{
    EDITOR_HILITE_TYPE hilite_type;
    U16   length;
	U32   str_offset;
} cui_inline_hilite_str_struct;


typedef struct 
{
    cui_inline_hilite_str_struct * hilite_list;
    U16 count;
    U16 curr_hilite_idx;
}cui_inline_set_multiline_rd_highlight_list_struct;  //HILITE_STR




/* DOM-NOT_FOR_SDK-END */


/*****************************************************************************  
*   Event
*****************************************************************************/
typedef enum
{
    EVT_ID_CUI_INLINE_SUBMIT = (INLINE_EDITOR_BASE + 1),
    EVT_ID_CUI_INLINE_ABORT,
    EVT_ID_CUI_INLINE_CSK_PRESS,
    EVT_ID_CUI_INLINE_SET_KEY,
    EVT_ID_CUI_INLINE_NOTIFY,
    EVT_ID_CUI_INLINE_REDRAW,   /* Use by inline CUI internal*/
    EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE,
    EVT_ID_CUI_INLINE_GROUP_DEINIT,
    EVT_ID_CUI_INLINE_MAIN_SCREEN_INACTIVE,
    EVT_ID_CUI_INLINE_MAIN_SCREEN_SHOWN,
    EVT_ID_CUI_INLINE_MAX
} cui_inline_event_enum;

typedef enum
{
    CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM,
    CUI_INLINE_NOTIFY_ITEM_ACTIVATED,
    
    CUI_INLINE_NOTIFY_ITEM_CHANGED,
    CUI_INLINE_NOTIFY_TEXT_NOT_EMPTY,
    CUI_INLINE_NOTIFY_TEXT_EMPTY,
#ifdef __MMI_INLINE_SLIM__    
    CUI_INLINE_NOTIFY_SUB_GROUP_SUBMIT,
    CUI_INLINE_NOTIFY_SUB_GROUP_DEINIT,
#endif
    CUI_INLINE_NOTIFY_BACK_WITHOUT_CHANGE,
    CUI_INLINE_NOTIFY_IMAGE_TEXT_PEN_DOWN,
    CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED,
    CUI_INLINE_NOTIFY_ATTACHMENT_FOCUS_CHANGED,
    CUI_INLINE_NOTIFY_COLOR_SELECT_FOCUS_CHANGED,
    CUI_INLINE_NOTIFY_USER_DEFINED_SELECT_SET_FOCUS,
    CUI_INLINE_NOTIFY_PROGRESS_BAR_VALUE_CHANGED,
    CUI_INLINE_NOTIFY_CHECKBOX_CHANGED,
    CUI_INLINE_NOTIFY_RADIO_SELECTED,
    CUI_INLINE_NOTIFY_ML_RDLY_HIGHLIGHT_LIST_CHANGE_INDEX,
    CUI_INLINE_NOTIFY_ML_RDLY_HIGHLIGHT_LIST_CLICK
    
} cui_inline_event_notify_type_enum;

typedef enum
{
    CUI_INLINE_USERDEFINEDSELECT_CUR,
    CUI_INLINE_USERDEFINEDSELECT_PRE,
    CUI_INLINE_USERDEFINEDSELECT_NEXT
} cui_inline_user_defined_select_highlight_enum;


typedef struct
{
	/* DOM-NOT_FOR_SDK-BEGIN */
   MMI_EVT_GROUP_PARAM_HEADER
   /* DOM-NOT_FOR_SDK-END */
}cui_event_inline_common_struct;

/* notify event which contains cui_inline_event_notify_type_enum sub type */
typedef struct
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    U8   event_type;    /* event sub type */
    U16  item_id;       /* item id */
    S32 param;          /* reserve for extend */
    S32 param_ext;
} cui_event_inline_notify_struct;

/* submit event struct */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    U16 item_id;    /* item id */
    U8 sofktey_type;
}  cui_event_inline_submit_struct; 

/* abort event struct */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    U16 item_id;    /* item id */
}  cui_event_inline_abort_struct; 

/* csk press event struct */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    U16 item_id;    /* item id */
}  cui_event_inline_csk_press_struct; 

/* set key event struct */
typedef struct 
{
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_GROUP_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    U16 item_id;    /* item id */
} cui_event_inline_set_key_struct; 

/* pen down on imagetext's image event struct */
typedef struct
{
    U16 image_index;    /* highlight image index */
} cui_event_inline_image_text_pen_down_struct; 

/* user defined selector highlight change event struct */
typedef struct
{
    cui_inline_user_defined_select_highlight_enum  locate_measure;  /* current item, pre item, next item */
}  cui_event_inline_user_defined_select_highlight_struct; 

/* attachment highlight change event struct */
typedef struct
{
    U8 * attach_index;  /* attachment item index */
}  cui_event_inline_attach_highlight_struct;


/*****************************************************************************  
*   Others
*****************************************************************************/
typedef struct
{
       U16 num_of_info_box_rows;
       void (*draw_info_callback) (S32 idx, S32 x1, S32 y1, S32 x2, S32 y2);
       void (*hide_info_callback) (S32 idx);
       BOOL is_draw_once;
}cui_inline_draw_top_info_struct;


/*****************************************************************************  
*   Extern Functions for Apps
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  cui_inline_create
 * DESCRIPTION
 *  Create inline CUI instance
 * PARAMETERS
 *  parent_gid      : [IN] parent gid  
 *  inline_struct   : [IN] items data for initialize inline cui
 * RETURNS
 *  void
 *****************************************************************************/
mmi_id cui_inline_create(mmi_id parent_gid, const cui_inline_struct* inline_struct);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_run
 * DESCRIPTION
 *  Run inline CUI function.
 * PARAMETERS
 *  inline_id      : [IN]   inline gid           
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_run(mmi_id inline_id);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_run_with_screen_id
 * DESCRIPTION
 *  Run inline CUI function.
 * PARAMETERS
 *  inline_id      : [IN]   inline gid
 *  screen_id      : [IN]   screen id
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_run_with_screen_id(mmi_id inline_id, U16 screen_id);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_close
 * DESCRIPTION
 *  close inline cui instance.
 * PARAMETERS
 *  gid             : [IN]      inline gid          
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_close(mmi_id inline_gid);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_softkey_text
 * DESCRIPTION
 *  set softkey text. when App want to set to inline cui default default, it will pass string_id = CUI_INLINE_SOFTKEY_DEFAULT_VALUE
 * PARAMETERS
 *  gid             : [IN]      inline gid          
 *  id              : [IN]      inline item id   
 *  key             : [IN]      key type    
 *  string_id       : [IN]      string id
 * RETURNS
 *  void
 *****************************************************************************/
S32 cui_inline_set_softkey_text(mmi_id gid, U16 id, WGUI_SOFTKEY_ENUM  key, U16 string_id);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_softkey_icon
 * DESCRIPTION
 *  set softkey icon. when App want to set to inline cui default default, it will pass string_id = CUI_INLINE_SOFTKEY_DEFAULT_VALUE
 * PARAMETERS
 *  gid             : [IN]      inline gid          
 *  id              : [IN]      inline item id   
 *  key             : [IN]      key type    
 *  image_id        : [IN]      image  id      
 * RETURNS
 *  void
 *****************************************************************************/
S32 cui_inline_set_softkey_icon(mmi_id gid, U16 id, WGUI_SOFTKEY_ENUM  key, U16 image_id);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_title
 * DESCRIPTION
 *  set inline CUI screen title.
 * PARAMETERS
 *  gid                : [IN]   inline gid             
 *  string_id          : [IN]   string id 
 *  image_id           : [IN]   image  id 
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_set_title(mmi_id gid, U16 string_id, U16 image_id);  


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_title_string
 * DESCRIPTION
 *  set inline CUI screen title string. This function will be priority to cui_inline_set_title.
 * PARAMETERS
 *  gid             : [IN]      inline gid         
 *  s               : [IN]      string pointer   
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_set_title_string(mmi_id gid, UI_string_type s);  


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_title_string_with_string_id
 * DESCRIPTION
 *  set inline CUI screen title string. This function will be priority to cui_inline_set_title.
 * PARAMETERS
 *  gid                     : [IN]      inline gid         
 *  string_id               : [IN]      string id   
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_set_title_string_with_string_id(mmi_id gid, U16 string_id);  



/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_title_icon
 * DESCRIPTION
 *  set inline CUI screen title icon.
 * PARAMETERS
 *  gid             : [IN]      inline gid         
 *  s               : [IN]      image id          
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_set_title_icon(mmi_id gid, U16 image_id); 


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_characters_filter
 * DESCRIPTION
 *  set ime char filter.
 * PARAMETERS
 *  gid               : [IN]    inline gid          
 *  is_allowed        : [IN]    if allowed or not
 *  characters_list   : [IN]    characters list.
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_set_characters_filter(mmi_id gid, MMI_BOOL is_allowed, const UI_character_type *characters_list); 


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  cui_inline_disable_handwriting
 * DESCRIPTION
 *  disable handwriting.
 * PARAMETERS
 * gid                : [IN]   inline gid               
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_disable_handwriting(mmi_id gid);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_imm_events
 * DESCRIPTION
 *  set imm events.
 * PARAMETERS
 * gid                                    : [IN]   inline gid           
 * is_allowed                             : [IN]   if allowed or not
 * disable_event_keys_list                : [IN]   key list
 * RETURNS
 *  void
 *****************************************************************************/
mmi_imm_message_id_enum cui_inline_set_imm_events(mmi_id gid, MMI_BOOL is_allowed, const gui_virtual_keyboard_pen_enum *disable_event_keys_list);                

#endif


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_value
 * DESCRIPTION
 *  set item value.
 *  For Caption, Displayonly, Textedit, Fullscreen, Imagetext, MultilineEdit, MultilineRdonly: value type is U16* , means
 *  text buffer.
 *  For Selector, Color Selector, value type is U8, it means highlight index.
 *  For DOW, value type is U8*, it means status list of day weeks.
 *  For Date, value type is cui_inline_item_date_time_struct.
 *  For Time, value type is cui_inline_item_time_struct.
 *  For Time_period, value type is cui_inline_item_time_period_struct.
 *  For Ip4, value type is cui_inline_item_ip4_struct.
 *  For Attachment, Userdefined Selector, this function is meanless.
 * PARAMETERS
 *  gid                 : [IN]   inline gid           
 *  id                  : [IN]   inline item id
 *  value               : [IN]   item setting value
 * RETURNS
 *  void
 *****************************************************************************/
S32 cui_inline_set_value(mmi_id gid, U16 id, void* value);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_get_value
 * DESCRIPTION
 *  get item value.
 *  For Caption, Displayonly, Textedit, Fullscreen, Imagetext, MultilineEdit, MultilineRdonly: value type is U16* , means
 *  text buffer.
 *  For Selector, Color Selector, value type is U8*, it means highlight index.
 *  For DOW, value type is U8*, it means status list of day weeks.
 *  For Date, value type is cui_inline_item_date_time_struct.
 *  For Time, value type is cui_inline_item_time_struct.
 *  For Time_period, value type is cui_inline_item_time_period_struct.
 *  For Ip4, value type is cui_inline_item_ip4_struct.
 *  For Attachment, Userdefined Selector, this function is meanless.
 * PARAMETERS
 *  gid                 : [IN]   inline gid           
 *  id                  : [IN]   inline item id       
 *  value               : [OUT]  item  value. 
 * RETURNS
 *  void
 *****************************************************************************/
S32 cui_inline_get_value(mmi_id gid, U16 item_id, void* value);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_text_len
 * DESCRIPTION
 *  set text length
 * PARAMETERS
 *  gid                  : [IN]   inline gid           
 *  id                   : [IN]   inline item id 
 *  len                  : [IN]   text length
 * RETURNS
 *  void
 *****************************************************************************/
S32 cui_inline_set_text_len(mmi_id gid, U16 item_id, U32 len);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_get_text_len
 * DESCRIPTION
 *  get text length
 * PARAMETERS
 *  gid                  : [IN]   inline gid           
 *  id                   : [IN]   inline item id        
 * RETURNS
 *  void
 *****************************************************************************/
U32 cui_inline_get_text_len(mmi_id gid, U16 id);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_item_attributes
 * DESCRIPTION
 *  set item attributes
 * PARAMETERS
 *  gid                  : [IN]   inline gid           
 *  id                   : [IN]   inline item id   
 *  operation            : [IN]   set or reset          
 *  flag                 : [IN]   inline attribute flags  
 * RETURNS
 *  void
 *****************************************************************************/
S32 cui_inline_set_item_attributes(mmi_id gid, U16 id, U8 operation, U32 flag);  


/*****************************************************************************
 * FUNCTION
 *  cui_inline_get_item_attributes
 * DESCRIPTION
 *  get item attributes
 * PARAMETERS
 *  gid                  : [IN]   inline gid           
 *  id                   : [IN]   inline item id   
 *  operation            : [IN]   set or reset              
 * RETURNS
 *  void
 *****************************************************************************/
U32 cui_inline_get_item_attributes(mmi_id gid, U16 id);      


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_screen_attributes
 * DESCRIPTION
 *  set screen attributes
 * PARAMETERS
 *  gid                  : [IN]   inline gid           
 *  operation            : [IN]   set or reset          
 *  flag                 : [IN]   inline attribute flags         
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_set_screen_attributes(mmi_id gid, U8 operation, U32 flag); 


/*****************************************************************************
 * FUNCTION
 *  cui_inline_get_screen_attributes
 * DESCRIPTION
 *  get screen attributes
 * PARAMETERS
 *  gid                 : [IN]  inline gid                  
 * RETURNS
 *  void
 *****************************************************************************/
U32 cui_inline_get_screen_attributes(mmi_id gid);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_icon_list
 * DESCRIPTION
 *  set inline item icon list
 * PARAMETERS
 *  gid            : [IN]       inline gid       
 *  icon_list      : [IN]       icon list  
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_set_icon_list(mmi_id gid, U16 *icon_list);   


/*****************************************************************************
 * FUNCTION
 *  cui_inline_insert_item
 * DESCRIPTION
 *  insert an item dynamically.
 * PARAMETERS
 *  gid            : [IN]       inline gid       
 *  pre_id          : [IN]          function will insert item to the position which is mark by pre_id.  
 *  new_item        : [IN]          inserted item's data structure.
 * RETURNS
 *  void
 *****************************************************************************/
S32 cui_inline_insert_item(mmi_id gid, U16 pre_id, cui_inline_set_item_struct* new_item);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_delete_item
 * DESCRIPTION
 *  delete an item dynamically.
 * PARAMETERS
 *  gid            : [IN]       inline gid       
 *  item_id         : [IN]       delete item which is marked by item_id.  
 * RETURNS
 *  void
 *****************************************************************************/
S32 cui_inline_delete_item(mmi_id gid, U16 item_id);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_input_buffer_allocator
 * DESCRIPTION
 *  set inline input buffer memory malloc and free function.
 * PARAMETERS
 *  gid               : [IN]   inline gid           
 *  mallocFuncPtr     : [IN]   malloc function   
 *  mfreeFuncPtr      : [IN]   free function   
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_set_input_buffer_allocator(mmi_id gid,  mmi_malloc_func_ptr mallocFuncPtr, mmi_mfree_func_ptr mfreeFuncPtr);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_redraw_item
 * DESCRIPTION
 *  redraw inline item
 * PARAMETERS
 *  gid                  : [IN]   inline gid           
 *  id                   : [IN]   inline item id          
 * RETURNS
 *  void
 *****************************************************************************/
//void cui_inline_redraw_item(mmi_id gid, S32 id); 


/*****************************************************************************
 * FUNCTION
 *  cui_inline_redraw_screen
 * DESCRIPTION
 *  update inline screen
 * PARAMETERS
 *  gid                  : [IN]   inline gid            
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_redraw_screen(mmi_id gid);         


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_item_text_edit_default_text
 * DESCRIPTION
 *  set item default text.
 * PARAMETERS
 *  gid                  : [IN]   inline gid           
 *  id                   : [IN]   inline item id          
 * default_text_id      : [IN]  default text id.   
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_set_item_text_edit_default_text(mmi_id gid, U16 item_id, U16 default_text_id); 

/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_item_text_edit_default_text
 * DESCRIPTION
 *  set item default text.
 * PARAMETERS
 *  gid                  : [IN]   inline gid           
 *  id                   : [IN]   inline item id          
 * default_text_id      : [IN]  default text id.   
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_set_item_text_edit_default_text_with_string(mmi_id gid, U16 item_id, U8 *default_text);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_item_select
 * DESCRIPTION
 *  Set selector item attributes when initialize inline cui instance. 
 * PARAMETERS
 *  gid                 : [IN]   inline gid           
 *  id                  : [IN]   inline item id 
 *  n_items             : [In]   content count
 *  highlighted_item    : [In]   highlight content index
 * RETURNS
 *  void
 *****************************************************************************/
S32 cui_inline_set_item_select(mmi_id gid, U16 item_id, S32 n_items, PU8 *list_of_items, U8 highlighted_item);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_highlight_item
 * DESCRIPTION
 *  change highlight item dynamically. 
 * PARAMETERS
 *  gid                 : [IN]   inline gid           
 *  item_id             : [IN]   highlight inline item id 
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_set_highlight_item(mmi_id gid, U16 item_id);     


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_set_parent_data
 * DESCRIPTION
 *  Set parent data. App can set parent data and retrieve it by cui_fseditor_get_parent_data
 * PARAMETERS
 *  fseditor_gid        :[IN]        FSEditor CUI Group ID
 *  parent_data         :[IN]        Parent data
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_set_parent_data(mmi_id gid, U32 parent_data);


/*****************************************************************************
 * FUNCTION
 *  cui_fseditor_get_parent_data
 * DESCRIPTION
 *  Get parent data. App can set parent data by cui_fseditor_set_parent_data
 * PARAMETERS
 *  gid        :[IN]        Inline CUI Group ID
 * RETURNS
 *  U32
 *****************************************************************************/
U32 cui_inline_get_parent_data(mmi_id gid);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_get_default_text_id
 * DESCRIPTION
 *  Get item default text id.
 * PARAMETERS
 *  gid        : [IN]        Inline CUI Group ID
 *  item_id    : [IN]        Inline CUI item id
 * RETURNS
 *  U16
 *****************************************************************************/
U16 cui_inline_get_default_text_id(mmi_id gid, U16 item_id);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_default_icon_style
 * DESCRIPTION
 *  Draw an icon on inside of singleline item
 * PARAMETERS
 *  gid            :     [IN]        
 *  picon          :     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
 void cui_inline_set_default_icon_style(mmi_id gid, PU8 picon);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_draw_top_info_box
 * DESCRIPTION
 *  Self draw top of screen info.
 * PARAMETERS
 *  gid            :     [IN]   Inline CUI Group ID
 *  draw_struct    :     [IN]   draw top info struct     
 * RETURNS
 *  void
 *****************************************************************************/
 void cui_inline_draw_top_info_box(mmi_id gid, cui_inline_draw_top_info_struct *draw_struct);

/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_item_icon
 * DESCRIPTION
 *  Set item icon on side of item.
 * PARAMETERS
 *  gid             :     [IN]  Inline CUI Group ID      
 *  item_id         :     [IN]  icon id      
 * RETURNS
 *  void
 *****************************************************************************/
S32 cui_inline_set_item_icon(mmi_id gid, U16 item_id, U16 icon_id);

/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_fullscreen_edit_title_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  gid            :     [IN]        
 *  draw_struct    :     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_set_fullscreen_edit_title_icon(mmi_id gid, U16 item_id, U16 icon);
  


/*****************************************************************************
 * FUNCTION
 *  cui_inline_multiline_append_string
 * DESCRIPTION
 *  Append string for multiline edit item when it is in history.
 * PARAMETERS
 *  gid             :     [IN]        
 *  item_id         :     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_multiline_append_string(
                    mmi_id gid,
                    U16 item_id, 
                    U8 *string);

/*****************************************************************************
 * FUNCTION
 *  cui_inline_get_item_id_by_index
 * DESCRIPTION
 *  Get item id by item index.
 * PARAMETERS
 *  gid                 :     [IN]        
 *  item_index          :     [IN]        
 * RETURNS
 *  U16
 *****************************************************************************/
U16 cui_inline_get_item_id_by_index(mmi_id gid, U16 item_index);

/*****************************************************************************
 * FUNCTION
 *  cui_inline_get_instance_item_count
 * DESCRIPTION
 *  Get item count of instance.
 * PARAMETERS
 *  gid        [IN]     :   Inline CUI Group ID
 * RETURNS
 *  U8
 *****************************************************************************/
U8 cui_inline_get_instance_item_count(mmi_id gid);

/*****************************************************************************
 * FUNCTION
 *  cui_inline_lock_main_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string_buffer       [?]     
 *  hours_buffer        [?]     
 *  min_buffer          [?]     
 *  am_pm_flag          [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_lock_main_screen(mmi_id gid);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_lock_main_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  string_buffer       [?]     
 *  hours_buffer        [?]     
 *  min_buffer          [?]     
 *  am_pm_flag          [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_unlock_main_screen(mmi_id gid);

/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_date_boundary
 * DESCRIPTION
 *  Set date boundary.
 * PARAMETERS
 *  gid        [IN]        Inline CUI Group ID
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_set_date_boundary(mmi_id gid, U16 item_id, S32 date_year_max, S32 date_year_min, S32 date_month_max, S32 date_month_min);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_date_boundary
 * DESCRIPTION
 *  Set date boundary.
 * PARAMETERS
 *  gid        [IN]        Inline CUI Group ID
 * RETURNS
 *  void
 *****************************************************************************/
void cui_inline_set_input_method(
        mmi_id gid,
        U16 item_id,
        U32 input_type,
        mmi_imm_input_mode_enum *required_input_mode_set,
        S16 input_ext_type);

/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_ml_rdly_set_hilite_list
 * DESCRIPTION
 *  Set multiline readonly item highight list.
 * PARAMETERS
 *  gid        [IN]      :  Inline CUI Group ID
 * RETURNS
 *  U8
 *****************************************************************************/
void cui_inline_set_ml_rdly_set_hilite_list(mmi_id gid, U16 item_id, cui_inline_set_multiline_rd_highlight_list_struct *highlight_list);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_item_radio_string
 * DESCRIPTION
 *  set radio item string 
 * PARAMETERS
 *  gid                     [IN]        
 *  item_id                 [IN]        
 *  curr_index			[IN]		current item index of radio list.
 *  text_p	        [IN]        	the text string for current radio item.
 * RETURNS
 *  return 1 or CUI_INLINE_RETURN_ERROR
 *****************************************************************************/
S32 cui_inline_set_item_radio_string(mmi_id gid, U16 item_id, S32 curr_index, PU8 text_p);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_item_radio_select
 * DESCRIPTION
 *  set radio list flag for select 
 * PARAMETERS
 *  gid                     [IN]        
 *  item_id                 [IN]        
 *  selected_item			[IN]		selected item index of radio list.
 * RETURNS
 *  return 0, 1 or CUI_INLINE_RETURN_ERROR
 *****************************************************************************/
S32 cui_inline_set_item_radio_select(mmi_id gid, U16 item_id, S32 selected_item);


/*****************************************************************************
 * FUNCTION
 *  cui_inline_set_item_radio_string
 * DESCRIPTION
 *  set radio item string 
 * PARAMETERS
 *  gid                     [IN]        
 *  item_id                 [IN]        
 *  curr_index			[IN]		current item index of radio list.
 *  text_p	        [IN]        	the text string for current radio item.
 * RETURNS
 *  return 1 or CUI_INLINE_RETURN_ERROR
 *****************************************************************************/
S32 cui_inline_set_item_radio_string(mmi_id gid, U16 item_id, S32 curr_index, PU8 text_p);


#endif /* MMI_INLINECUIGPROT_H */
