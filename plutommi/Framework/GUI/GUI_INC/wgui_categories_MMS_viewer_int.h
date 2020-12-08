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
 *  wgui_categories_mms_viewer_int.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Category internal header file
 *
 * Author:
 * -------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*
 * This file contains internal Category API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
*/

#ifndef __WGUI_CATEGORIES_MMS_VIEWER_INT_H__
#define __WGUI_CATEGORIES_MMS_VIEWER_INT_H__

#include "MMI_features.h"
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
#include "MmsXMLDefSrv.h"

#if defined (__MMI_MMSXMLDEF_H__) && defined (__UI_MMS_VIEWER_CATEGORY__)
#ifndef __WGUI_MV_XML__
#define __WGUI_MV_XML__
typedef void (*wgui_mv_get_use_details_on_slide) (srv_mms_viewer_use_details_list **list_head);
typedef void (*wgui_mv_set_current_highlighted_use_detail) (srv_mms_viewer_use_details_list  *current_node);
typedef struct
{
    MMI_BOOL is_media_valid;
    MMI_BOOL is_audio_start_play;
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
    MMI_BOOL is_video_open;
    MMI_BOOL is_video_play;
#ifdef __DRM_SUPPORT__
    MMI_BOOL is_video_playing;      /* for DRM to cosume right, this flag will set true after start playing for each slide */
#endif /* __DRM_SUPPORT__ */
    MMI_BOOL is_video_start_play;
	MMI_BOOL is_video_stopped;
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */
    MMI_BOOL is_audio_play;
    MMI_BOOL is_fullscreen;
    MMI_BOOL is_pause;
	MMI_BOOL is_image_decoded;

    wgui_mv_drawable_media_event_enum drawable_media_event;
    wgui_mv_drawable_media_state_enum drawable_media_state;
    wgui_mv_state_enum current_state;
    wgui_mv_display_mode_enum display_mode;

    U16 lsk_str_id;
    U16 csk_icon;
    U16 slide_time;
#if defined(__MMI_FTE_ITERATOR_VIEWER_SUPPORT__)
    U16 total_msg_num;
    U16 curr_msg_num; 
#endif

    srv_mms_viewer_xml_msg_struct current_msg;
    srv_mms_viewer_use_details_list *current_highlighted_item;
    srv_mms_viewer_use_details_list *previous_highlighted_item;

    wgui_mv_stop_application stop_app_cb;
    wgui_mv_get_filename_by_id get_filename_by_id;
    wgui_mv_load_ucs2_txt_to_buffer load_paging_txt;
    wgui_mv_check_rights_by_id is_drm_locked;
    wgui_mv_update_rights_by_id update_rights;
    wgui_mv_start_consume_rights start_consume_rights;
    wgui_mv_stop_consume_rights stop_consume_rights;
    wgui_mv_allow_audio allow_audio_play;
    wgui_mv_best_page_duration do_best_page_duration;
    wgui_mv_mid_slides_cb mid_slides_cb;                            /* non-blocking callback to application during slides */
    wgui_mv_get_use_details_on_slide get_highlighted_items;         /* get information of highlighted items */
    wgui_mv_set_current_highlighted_use_detail highlight_handler;   /* highlight handler for each highlighted items */
#ifdef __MMI_TOUCH_SCREEN__
    wgui_mv_set_current_highlighted_use_detail highlight_click_handler;   /* click handler for highlighted item */
#endif
    wgui_mv_finish_playing finish_playing;                          /* while user press stop or after finish playing MMS, callback application to do handling */
#if defined(__MMI_FTE_ITERATOR_VIEWER_SUPPORT__)
    wgui_mv_left_iterate left_iterate_func;
    wgui_mv_right_iterate right_iterate_func;
    wgui_mv_get_msg_index get_index_func;
#endif
	
	wgui_mv_app_common_action app_common_action_callback;
    
	wgui_mv_show_clean_image  decode_image_for_clear_image ;

	wgui_mv_common_fte_callback app_fte_common_cb;
    softkey_fn lsk_fn;  /* Store APP supplied lsk fn */
    softkey_fn rsk_fn;  /* Store APP supplied rsk fn */
    /* whole slide txt in UCS2 stored in this buffer */
    PU8 ptxtbuffer; 
    /* txt buffer size */
    U32 ptxtbuffersize; 
    /* Buffer supplied to multiline inputbox, always CAT630_MAIN_TXT_BUFFER_SIZE */
    PU8 pinputboxbuffer;
    
    PU16 drawable_media_file_path;
	PU16 drawable_media_file_path_ext; 
    PU16 audio_file_path;

    U32 ucs2_txt_len;
    GDI_HANDLE image_handle;

    /* CSK */
    void (*csk_func)(void);
	UI_filled_area bgfiller;
} wgui_mv_context_struct;

typedef struct
{
    /* Callbacks to APP */
    wgui_mv_get_filename_by_id get_filename_by_id_cb;
    wgui_mv_load_ucs2_txt_to_buffer load_slide_txt_cb;
    wgui_mv_check_rights_by_id check_rights_cb;
    wgui_mv_start_consume_rights consume_rights_cb;
    wgui_mv_stop_consume_rights stop_consume_rights_cb;
    wgui_mv_update_rights_by_id update_rights_cb;
    wgui_mv_stop_application stop_app_cb;
    wgui_mv_allow_audio allow_audio_cb;
    wgui_mv_best_page_duration best_page_duration_cb;
    wgui_mv_mid_slides_cb mid_slides_cb;
    wgui_mv_get_use_details_on_slide get_highlighted_items;         /* get information of highlighted items */
    wgui_mv_set_current_highlighted_use_detail highlight_handler;   /* highlight handler for each highlighted items */
#ifdef __MMI_TOUCH_SCREEN__
    wgui_mv_set_current_highlighted_use_detail highlight_click_handler;   /* click handler for highlighted item */
#endif
    wgui_mv_finish_playing finish_playing;                          /* while user press stop or after finish playing MMS, callback application to do handling */
#if defined(__MMI_FTE_ITERATOR_VIEWER_SUPPORT__)
    wgui_mv_left_iterate left_iterate_func;
    wgui_mv_right_iterate right_iterate_func;
    wgui_mv_get_msg_index get_index_func;
#endif

    wgui_mv_app_common_action  app_common_action_callback ;

	wgui_mv_common_fte_callback app_fte_common_cb;
	wgui_mv_show_clean_image  decode_image_for_clear_image ;
    /* Data Members */
    srv_mms_viewer_xml_msg_struct current_msg;
    PU8 ptxtbuffer;
    U32 ptxtbuffersize;
    PU8 pinputboxbuffer;

    /* CSK */
    void (*csk_func)(void);
    U16 csk_icon;
}wgui_mv_initialize_struct;

/*****************************************************************************
 * FUNCTION
 *  Category630Initialize
 * DESCRIPTION
 *  category 630 init function, used before ShowCategory630screen
 * PARAMETERS
 *   init                          : [IN ] (N/A) init structure
 * RETURNS
 *  void
 *****************************************************************************/
extern void Category630Initialize(wgui_mv_initialize_struct *init);
#endif /*__WGUI_MV_XML__*/
#endif/*__MMI_MMSXMLDEF_H__ && __UI_MMS_VIEWER_CATEGORY__*/

#endif /* __WGUI_CATEGORIES_MMS_VIEWER_INT_H__ */ 


