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
 *   wgui_categories_MMS_viewer.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header File for the MMS Viewer Category
 *
 *
 * Author:
 * -------
 * -------
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __WGUI_CATEGORIES_MMS_VIEWER_H__
#define __WGUI_CATEGORIES_MMS_VIEWER_H__

#include "MMI_features.h"
#ifdef __UI_MMS_VIEWER_CATEGORY__

/* <hExpand noExpand> DO NOT REMOVE THIS LINE */
#ifdef __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__
#include "wgui_draw_manager.h"
#endif /* __MMI_FRAMEWORK_BACKWARD_COMPATIBLE__ */
/* </hExpand> DO NOT REMOVE THIS LINE */

#include "wgui_inputs.h"

#include "MMIDataType.h"
#include "gui_inputs.h"
#include "fs_type.h"
#include "wgui_draw_manager.h"
#include "gdi_datatype.h"
#include "CustThemesRes.h"
#include "gdi_const.h"
#include "mma_api.h"
#include "mma_struct.h"

/* Slide Related Data structures */

/* 
 * Extern Global Variable
 */

/* category 630 detail list structure */



typedef struct 
{
	 S32 x;
	 S32 y;
	 S32 width;
	 S32 height;
} wgui_mv_image_point;

typedef struct 
{
	 S32 x;
	 S32 y;
	 S32 width;
	 S32 height;
} wgui_mv_video_point;


/* Internal Category Data Structures */
/* Layout Related */
/* Both ProgressBar and Infobar need to be of same height as they may overlap */

#if defined(__MMI_FTE_SUPPORT__)    /* 240x320, 240x400, 320x480 */
#define CAT630_MIN_LINE_HEIGHT 26
#define CAT630_ARROW_GAP 2
#define CAT630_HMARGIN 6
#define CAT630_VMARGIN 6
#define CAT630_PBAR_VMARGIN 2
#define CAT630_PBAR_HMARGIN 2
#define CAT630_FONT        (&MMI_medium_font)

#elif defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_320X480__)
#define CAT630_MIN_LINE_HEIGHT 26
#define CAT630_ARROW_GAP 6
#define CAT630_HMARGIN 6
#define CAT630_VMARGIN 6
#define CAT630_PBAR_VMARGIN 4
#define CAT630_PBAR_HMARGIN 10
#define CAT630_FONT        (&MMI_medium_font)

#elif defined(__MMI_MAINLCD_240X320__)
#define CAT630_MIN_LINE_HEIGHT 26
#define CAT630_ARROW_GAP 2
#define CAT630_HMARGIN 6
#define CAT630_VMARGIN 6
#define CAT630_PBAR_VMARGIN 4
#define CAT630_PBAR_HMARGIN 6
#define CAT630_FONT        (&MMI_medium_font)

#elif defined(__MMI_MAINLCD_176X220__)
#define CAT630_MIN_LINE_HEIGHT 20
#define CAT630_ARROW_GAP 2
#define CAT630_HMARGIN 6
#define CAT630_VMARGIN 6
#define CAT630_PBAR_VMARGIN 4
#define CAT630_PBAR_HMARGIN 6
#define CAT630_FONT        (&MMI_medium_font)

#elif defined(__MMI_MAINLCD_128X160__)
#define CAT630_MIN_LINE_HEIGHT 19
#define CAT630_ARROW_GAP 2
#define CAT630_HMARGIN 3
#define CAT630_VMARGIN 6
#define CAT630_PBAR_VMARGIN 4
#define CAT630_PBAR_HMARGIN 6
#define CAT630_FONT        (&MMI_medium_font)

#else /* 128x128 display */
#define CAT630_MIN_LINE_HEIGHT 19
#define CAT630_ARROW_GAP 2
#define CAT630_HMARGIN 3
#define CAT630_VMARGIN 6
#define CAT630_PBAR_VMARGIN 4
#define CAT630_PBAR_HMARGIN 6
#define CAT630_FONT        (&MMI_medium_font)

#endif 

#define CAT630_ERROR_TEXT_HEIGHT (MMI_MENUITEM_HEIGHT * 3)

#define CAT630_PBAR_BG_COLOR    UI_COLOR_GREY
#define CAT630_PBAR_FONT_COLOR  UI_COLOR_BLACK
#define CAT630_IBAR_FONT_COLOR  UI_COLOR_WHITE
#define CAT630_SLIDE_TIME_UNIT (100)
#define CAT630_SLIDE_SWITCH_GAP_TIME (200)
/* num of characters supplied directly to multiline */

/* WARNING:: MMI_MV_TXT_INPUTBOX_BUFFER_SIZE is affected by CAT630_MAIN_TXT_BUFFER_SIZE */
#define CAT630_MAIN_TXT_BUFFER_SIZE (GUI_PAGE_SIZE * PAGE_MAX + (GUI_SHARED_BYTES))

#define WGUI_MV_REDRAW_NEEDED 1
#define WGUI_MV_REDRAW_NOT_NEEDED 0
#define WGUI_MV_BUTTON_PRESSED_STATE 1
#define WGUI_MV_BUTTON_RELEASED_STATE 0
#define WGUI_MV_VFN_LEN (FS_GenVFN_SIZE+12) /* SRV_FMGR_PATH_MAX_FILE_EXT_LEN =5 plus one for '.' dot */

#define WGUI_MV_MAX_HILITE_NUMBER   45

#ifdef __MMI_MMS_ITERATOR_VIEWER__
#define __MMI_FTE_ITERATOR_VIEWER_SUPPORT__
#endif

#define CAT630_TIMER_STR_GAP 3
/* Enumerations */
typedef enum 
{
    WGUI_MV_LAYOUT_TYPE_INDEPENDENT_PROGRESS_BAR,
    WGUI_MV_LAYOUT_TYPE_OVERLAPPING_PROGRESS_BAR,
    WGUI_MV_LAYOUT_MAX
} wgui_mv_layout_type_enum;

typedef enum 
{
    WGUI_MV_EVENT_SHOW_START,
    WGUI_MV_EVENT_PLAY_SHOW_NEXT_SLIDE,
    WGUI_MV_EVENT_PLAY_SHOW_PREVIOUS_SLIDE,
    WGUI_MV_EVENT_PLAY_SHOW_ACTIVE_SLIDE,        /* trigger from APP for non-blocking callback */
    WGUI_MV_EVENT_PLAY_START,
    WGUI_MV_EVENT_STOP_PLAY_START_SHOW,
    WGUI_MV_EVENT_PLAY_NEXT_SLIDE,
    WGUI_MV_EVENT_STOP_EVENT,
    WGUI_MV_EVENT_PAUSE_EVENT,
    WGUI_MV_EVENT_RESUME_FROM_PAUSE,
    WGUI_MV_EVENT_MAX
} wgui_mv_event_enum;

typedef enum 
{
    WGUI_MV_STATE_INIT_SLIDE,
    WGUI_MV_STATE_DEINIT_SLIDE,
    WGUI_MV_STATE_PLAYING,
    WGUI_MV_STATE_SHOWING,
    WGUI_MV_STATE_ERROR,
    WGUI_MV_STATE_MAX
} wgui_mv_state_enum;

typedef enum 
{
    WGUI_MV_AUDIO_STATE_INIT,
    WGUI_MV_AUDIO_STATE_PLAY,
    WGUI_MV_AUDIO_STATE_PAUSE,
    WGUI_MV_AUDIO_STATE_PAUSE_FAIL,
    WGUI_MV_AUDIO_STATE_FINISH,
    WGUI_MV_AUDIO_STATE_MAX
} wgui_mv_audio_state_enum;

typedef enum 
{
    WGUI_MV_DRAWABLE_MEDIA_EVENT_HIDE,
    WGUI_MV_DRAWABLE_MEDIA_EVENT_PLAY,
    WGUI_MV_DRAWABLE_MEDIA_EVENT_SHOW_STOPPED,
    WGUI_MV_DRAWABLE_MEDIA_EVENT_SCROLL,
    WGUI_MV_DRAWABLE_MEDIA_EVENT_REDRAW,
    /*
     * The media's draw function maybe called by multiline incase it is redrawing the text control
     * * at which time no of the other events would be cause of the redraw. The category can decide based on
     * * current state if redraw needs to be handled or not. 
     */
    WGUI_MV_DRAWABLE_MEDIA_EVENT_MAX
} wgui_mv_drawable_media_event_enum;

typedef enum 
{
    WGUI_MV_DRAWABLE_MEDIA_STATE_HIDDEN,
    WGUI_MV_DRAWABLE_MEDIA_STATE_PLAYING,
    WGUI_MV_DRAWABLE_MEDIA_STATE_SHOWING,
    WGUI_MV_DRAWABLE_MEDIA_STATE_SROLLING,
    WGUI_MV_DRAWABLE_MEDIA_STATE_MAX
} wgui_mv_drawable_media_state_enum;

typedef enum 
{
    WGUI_MV_CAT_PEN_INFOBAR_EVENT,
    WGUI_MV_CAT_PEN_VIEW_EVENT,
    WGUI_MV_CAT_PEN_IGNORE_EVENT
} wgui_mv_cat_pen_event_enum;

typedef enum 
{
    WGUI_MV_DISPLAY_MODE_PLAY,
    WGUI_MV_DISPLAY_MODE_SHOW,
    WGUI_MV_DISPLAY_MODE_MAX
} wgui_mv_display_mode_enum;
typedef enum
{
WGUI_MV_USED_BY_UC,
WGUI_MV_USED_BY_VIEWER,
WGUI_MV_USED_BY_MAX
}WGUI_MV_USED_BY_ENUM;

typedef enum 
{
    WGUI_MV_HIGHLIGHTED_ITEM_EVENT_NEXT,
    WGUI_MV_HIGHLIGHTED_ITEM_EVENT_PREVIOUS,
    WGUI_MV_HIGHLIGHTED_ITEM_EVENT_MAX
} wgui_mv_highlighted_item_event_enum;

typedef enum
{
	WGUI_MV_TOUCH_AREA_NONE,
	WGUI_MV_TOUCH_AREA_ATTACHMENT,
    WGUI_MV_TOUCH_AREA_TOGGLE_SCRN,
	WGUI_MV_TOUCH_AREA_IMG_HLITE,
	WGUI_MV_TOUCH_AREA_VDO_HLITE,
	WGUI_MV_TOUCH_AREA_TXT_HLITE,
	WGUI_MV_TOUCH_AREA_AUD_HLITE,
    WGUI_MV_TOUCH_AREA_TOTAL
} wgui_mv_touch_area_type;

typedef enum
{
	WGUI_MV_ACTION_NONE,
	WGUI_MV_IMAGE_TYPE_ACTION,
	WGUI_MV_DISABLE_ENABLE_ACTION,
	WGUI_MV_STOP_IMAGE_DECODE_ACTION,
	WGUI_MV_ACTION_TOTAL
}wgui_mv_action_type ;

typedef enum 
{
	WGUI_MV_IMAGE_DECODED_FAILED,
	WGUI_MV_IMAGE_ALREADY_DECODED,
    WGUI_MV_IMAGE_DECODED_FAILED_INTERRUPT,
	WGUI_MV_IMAGE_DECODED_SUCCESS,
	WGUI_MV_IMAGE_DECODED_MAX
}wgui_mv_image_decode_status_enum;

/* Function Pointers */
typedef void (*wgui_mv_drawable_media_cb) (MMI_BOOL is_draw, S32 yoffset, S32 height, S32 clip_x1, S32 clip_y1,
                                              S32 clip_x2, S32 clip_y2);
typedef void (*softkey_fn) (void);

/* Callbacks to APP */
typedef MMI_BOOL (*wgui_mv_get_filename_by_id)(mma_mms_slide_object_struct *media, PU16 vf, PU16* file_path, PS32 vf_parent_file_handle);
typedef MMI_BOOL (*wgui_mv_load_ucs2_txt_to_buffer)(PU8 dest_buffer, U32 dest_buffer_size, mma_mms_slide_text_object_struct *media);
typedef MMI_BOOL (*wgui_mv_check_rights_by_id)(mma_mms_slide_object_struct *media);
typedef MMI_BOOL (*wgui_mv_start_consume_rights)(mma_mms_slide_object_struct *media, PU16 file_path);
typedef MMI_BOOL (*wgui_mv_allow_audio) (void);
typedef void (*wgui_mv_stop_consume_rights)(mma_mms_slide_object_struct *media);
typedef void (*wgui_mv_update_rights_by_id)(mma_mms_slide_object_struct *media, MMI_BOOL rights_expired);
typedef void (*wgui_mv_stop_application) (void);
typedef void (*wgui_mv_best_page_duration)(U64 playing_time, kal_uint32 * slide_duration, kal_uint32 * obj_start_time, kal_uint32 * obj_end_time);
typedef void (*wgui_mv_mid_slides_cb) (void);
typedef void (*wgui_mv_finish_playing) (void);
typedef void (*wgui_mv_left_iterate) (void);
typedef void (*wgui_mv_right_iterate) (void);
typedef void (*wgui_mv_get_msg_index)(U16 *curr_msg, U16 *total_msg);
typedef MMI_BOOL (*wgui_mv_common_fte_callback)(wgui_mv_touch_area_type);

typedef MMI_BOOL (*wgui_mv_app_common_action)(wgui_mv_action_type);

typedef wgui_mv_image_decode_status_enum (*wgui_mv_show_clean_image)(U16 *src_path, U32 width_orig, U32 height_orig, U32 width_final, U32 height_final, U16 slide_id);

/* Structures */
typedef struct
{
    dm_coordinates infobar;
    dm_coordinates viewarea;
    dm_coordinates pbar_area;
    dm_coordinates larrow;
    dm_coordinates rarrow;
    dm_coordinates limage;
    dm_coordinates rimage;
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
    gdi_handle baselayer;
    gdi_handle vlayer;
    gdi_handle tlayer;
    gdi_handle blayer;
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */ 

    S32 resized_xoffset;
    S32 resized_yoffset;
    S32 resized_width;
    S32 resized_height;
    
    PU8 pbar_img;
    S32 pbar_img_width;
    S32 pbar_img_height;

    wgui_mv_cat_pen_event_enum cat_pen_event;
    wgui_mv_layout_type_enum type;
} wgui_mv_layout_struct;

typedef struct
{
    U32 page_id;
    S32 text_offset;
    S32 last_text_offset_y;
    U8 shared_bytes;
} wgui_mv_paging_context;

#if defined(__MMI_FTE_SUPPORT__)
typedef struct{
    S32 x1;
    S32 y1;
    S32 x2;
    S32 y2;
}wgui_mv_clip_struct;
#endif
extern void wgui_mv_update_info_ext(void);
/*****************************************************************************
 * FUNCTION
 *  Category630ImageRightExpiredNotify
 * DESCRIPTION
 *  Called from APP when Image rights expired an image current on slide
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
extern void Category630ImageRightExpiredNotify(void);


/*****************************************************************************
 * FUNCTION
 *  Category630AudioRightExpiredNotify
 * DESCRIPTION
 *  Called from APP when Audio rights expired an image current on slide
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
extern void Category630AudioRightExpiredNotify(void);


/*****************************************************************************
 * FUNCTION
 *  Category630VideoRightExpiredNotify
 * DESCRIPTION
 *  Called from APP when Video rights expired an image current on slide
 * PARAMETERS
 *  void      
 * RETURNS  
 *  void
 *****************************************************************************/
extern void Category630VideoRightExpiredNotify(void);


/*****************************************************************************
 * FUNCTION
 *  Category630MidSlidesCBDoneNotify
 * DESCRIPTION
 *  For applications to notifiy category that mid-slides-callback is finished
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void Category630MidSlidesCBDoneNotify(void);

/*****************************************************************************
 * FUNCTION
 *  Category630ImageDecodeDoneNotify
 * DESCRIPTION
 *  For applications to notifiy category that image decode has finished
 * PARAMETERS
 *  wgui_mv_image_decode_status_enum result 
 *  U16 *file_path
 * RETURNS
 *  void
 *****************************************************************************/

extern void Category630ImageDecodeDoneNotify(wgui_mv_image_decode_status_enum result ,U16 *file_path);

/*****************************************************************************
 * FUNCTION
 *  ShowCategory630Screen
 * DESCRIPTION
 *  Q05A and Q03C V02 MMS viewer category screen
 *  
 *  Compile option: __UI_MMS_VIEWER_CATEGORY__
 * 
 * <img name="wgui_cat630_img1" />
 * PARAMETERS
 *   mode                          : [IN ] (N/A) start to show or play
 *   lsk_function                  : [IN ] (N/A) LSK function
 *   lsk_str_id                    : [IN ] (LSK) LSK string ID
 *   rsk_function                  : [IN ] (N/A) RSK function
 *   is_fullscreen                 : [IN ] (N/A) whether it is fullscreen display
 *   guibuffer                     : [IN ] (N/A) history buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * </code>
 *****************************************************************************/
extern void ShowCategory630Screen(BOOL toggle, U16 mode, softkey_fn lsk_function, U16 lsk_str_id, softkey_fn rsk_function, MMI_BOOL is_fullscreen, PU8 guibuffer,WGUI_MV_USED_BY_ENUM used_by);


/*****************************************************************************
 * FUNCTION
 *  wgui_cat630_get_viewer_area_info
 * DESCRIPTION
 *  get the viewer area coordinates
 * PARAMETERS
 *   x                             : [OUT] (N/A) x
 *   y                             : [OUT] (N/A) y
 *   w                             : [OUT] (N/A) w
 *   h                             : [OUT] (N/A) h
 *   is_fullscreen                 : [IN ] (N/A) whether it is fullscreen display
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_cat630_get_viewer_area_info(S32 *x, S32 *y, S32 *w, S32 *h, MMI_BOOL is_fullscreen);


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_register_keys
 * DESCRIPTION
 *  Register MMS viewer keys
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void wgui_mv_register_keys(void);


/*****************************************************************************
 * FUNCTION
 *  wgui_mv_get_video_layer
 * DESCRIPTION
 *  Get video layer handle
 * PARAMETERS
 *  void
 * RETURNS
 *  gdi_handle
 *****************************************************************************/
extern gdi_handle wgui_mv_get_video_layer(void);

#endif /* __UI_MMS_VIEWER_CATEGORY__ */
#endif /* __WGUI_CATEGORIES_MMS_VIEWER_H__ */


