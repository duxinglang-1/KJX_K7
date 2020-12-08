/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *	 resource_mediaplayer_skins.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Video App customization file.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _MEDIA_PLAYER_SKIN_H_
#define _MEDIA_PLAYER_SKIN_H_

#include "MMI_features.h"

#if defined(__MMI_MEDIA_PLAYER__)

#include "MMIDataType.h"
#include "gdi_lcd_config.h"
#include "mmi_features_mediaplayer.h"

#define MMI_MEDPLY_COMP_DISPLAY_META_MIDDLE 

#if defined(__MMI_FTE_SUPPORT_SLIM__) || defined(__MMI_FTE_SUPPORT__) 
#define MMI_MEDPLY_COMP_ICONBAR_SHOW  
/* FTE has background img , so that do not need to has border text */
#define MMI_MEDPLY_COMP_TEXT_WITHOUT_BORDER

#endif

#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_176X220__) || defined (__MMI_MAINLCD_320X240__)

#define MMI_MEDPLY_COMP_SOFTKEY_USE_SKIN_REGN 

#endif


#if /*defined(__MMI_MAINLCD_128X160__) ||*/ defined(__MMI_MAINLCD_128X128__)
#define MMI_MEDPLY_COMP_META_WITHOUT_ARTWORK
#endif

#if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__)
#endif

#if defined (__MMI_FTE_SUPPORT__) && defined (__MMI_MEDIA_PLAYER_PLST_MULTIPLE_STYLE__)
/* FTE has background img , so that do not use theme color */
#define MMI_MEDPLY_COMP_TEXT_FIXED_COLOR
#endif


#define MMI_MEDPLY_COMP_TITLE_FILE_NAME 

/***************************************************************************** 
* Struct
*****************************************************************************/
#if defined(__MMI_MEDIA_PLAYER_FTE__)
typedef struct
{
    /*base background image*/
    //U16 audio_bg_img_id;
    U16 video_bg_img_id;
    /*three layer region*/
    S16 top_layer_rgn_x, top_layer_rgn_y;
    S16 top_layer_rgn_w, top_layer_rgn_h;    
    S16 view_layer_rgn_x, view_layer_rgn_y;
    S16 view_layer_rgn_w, view_layer_rgn_h;
    S16 panel_layer_rgn_x, panel_layer_rgn_y;
    S16 panel_layer_rgn_w, panel_layer_rgn_h;
 
    /*Region without image*/
    S16 title_txt_rgn_x, title_txt_rgn_y, title_txt_rgn_w, title_txt_rgn_h;     /*title text*/
    S16 album_txt_rgn_x, album_txt_rgn_y, album_txt_rgn_w, album_txt_rgn_h;     /*album text*/
    S16 artist_txt_rgn_x, artist_txt_rgn_y, artist_txt_rgn_w, artist_txt_rgn_h; /*Artist text*/
    S16 spectrum_rgn_x, spectrum_rgn_y, spectrum_rgn_w, spectrum_rgn_h;         /*spectrum region*/
    S16 lyrics_rgn_x, lyrics_rgn_y, lyrics_rgn_w, lyrics_rgn_h;                 /*lyrics region*/
    S16 meta_img_rgn_x, meta_img_rgn_y, meta_img_rgn_w, meta_img_rgn_h;         /*meta image region*/
    S16 time_txt_rgn_x, time_txt_rgn_y, time_txt_rgn_w, time_txt_rgn_h;         /*time text*/
    S16 duration_txt_rgn_x, duration_txt_rgn_y, duration_txt_rgn_w, duration_txt_rgn_h;   /*duration text*/
    S16 popup_txt_rgn_x, popup_txt_rgn_y, popup_txt_rgn_w, popup_txt_rgn_h;     /*duration text*/
    
    /*region with image*/
    S16 meta_sep_line1_x,meta_sep_line1_y,meta_sep_line1_w,meta_sep_line1_h;     /*seprate line 1*/   
    U16 meta_sep1_img_id;
    
    S16 meta_sep_line2_x,meta_sep_line2_y,meta_sep_line2_w,meta_sep_line2_h;     /*seprate line 2*/
    U16 meta_sep2_img_id;
    
    S16 wait_ani_bg_x, wait_ani_bg_y, wait_ani_bg_w, wait_ani_bg_h;              /*processing animation*/
    U16 wait_img_bg_id;

    S16 wait_ani_fg_x, wait_ani_fg_y;
    U16 wait_ani_fg_id;
    
    U16 unsupport_video_def_ani_id;
    
    /*button*/                        
    S16 duration_bar_pos_x, duration_bar_pos_y;                 /*duration bar display*/ 
    U16 duration_bar_fg_img_id;
    U16 duration_bar_mg_img_id;
    U16 duration_bar_bg_disable_img_id;

    S16 duration_btn_pos_x, duration_btn_pos_y;                 /*progress bar button*/
    S16 duration_btn_rgn_x, duration_btn_rgn_y, duration_btn_rgn_w, duration_btn_rgn_h;
    U16 duration_btn_img_id;
    U16 duration_btn_img_hl_id;

    S16 play_pause_pos_x, play_pause_pos_y;                     /*play and pause button*/
    S16 play_pause_rgn_x, play_pause_rgn_y, play_pause_rgn_w, play_pause_rgn_h;
    U16 play_img_id;
    U16 play_disable_img_id;
    U16 pause_img_id;
    U16 pause_disable_img_id;

#ifdef MMI_MEDPLY_FTE_STOP_SUPPORT_ICON    
    S16 stop_pos_x, stop_pos_y;         /*stop button*/
    S16 stop_rgn_x, stop_rgn_y, stop_rgn_w, stop_rgn_h;
    U16 stop_img_id;
    U16 stop_disable_img_id;    
#endif

    S16 prev_pos_x, prev_pos_y;         /*prev button*/
    S16 prev_rgn_x, prev_rgn_y, prev_rgn_w, prev_rgn_h;
    U16 prev_img_id;
    U16 prev_disable_img_id;
    
    S16 next_pos_x, next_pos_y;         /*next button*/
    S16 next_rgn_x, next_rgn_y, next_rgn_w, next_rgn_h;
    U16 next_img_id;
    U16 next_disable_img_id;

    /*mode button*/
#ifdef __MMI_VIDEO_3D_ANAGLYPH__
    S16 mode_pos_x, mode_pos_y;
    S16 mode_rgn_x, mode_rgn_y, mode_rgn_w, mode_rgn_h;
    U16 mode_2d_up_img_id;
    U16 mode_2d_down_img_id;
    U16 mode_2d_disable_img_id;
	U16 mode_3d_up_img_id;
    U16 mode_3d_down_img_id;
    U16 mode_3d_disable_img_id;
#endif

    S16 lsk_pos_x, lsk_pos_y;           /*left soft key*/
    S16 lsk_rgn_x, lsk_rgn_y, lsk_rgn_w, lsk_rgn_h;
    U16 lsk_img_id;

    S16 rsk_pos_x, rsk_pos_y;           /*right soft key*/
    S16 rsk_rgn_x, rsk_rgn_y, rsk_rgn_w, rsk_rgn_h;
    U16 rsk_img_id;
    
    S16 zoom_pos_x, zoom_pos_y;         /*zoom button*/
    S16 zoom_rgn_x, zoom_rgn_y, zoom_rgn_w, zoom_rgn_h;
    U16 zoom_img_id;
    U16 zoom_disable_img_id;    
    
    S16 shuffle_pos_x, shuffle_pos_y;   /*shuffle button*/
    S16 shuffle_rgn_x, shuffle_rgn_y, shuffle_rgn_w, shuffle_rgn_h;
    U16 shuffle_on_img_id;
    U16 shuffle_off_img_id;
    
    S16 repeat_pos_x, repeat_pos_y;     /*repeat button*/
    S16 repeat_rgn_x, repeat_rgn_y, repeat_rgn_w, repeat_rgn_h;
    U16 repeat_off_img_id;
    U16 repeat_one_img_id;
    U16 repeat_all_img_id;

    S16 rating_pos_x, rating_pos_y;     /*user rating button*/
    S16 rating_rgn_x, rating_rgn_y, rating_rgn_w, rating_rgn_h;
    U16 rating_btn_img_id;

    /*volume popup setting*/
    S16 volume_set_regn_x, volume_set_regn_y, volume_set_regn_w, volume_set_regn_h;    /*volume setting bg*/
    U16 volume_set_bg_img_id;
    
    S16 mute_rgn_x, mute_rgn_y, mute_rgn_w, mute_rgn_h; /*mute image*/
    U16 mute_on_img_id;
    U16 mute_off_img_id;

    S16 volume_bar_rgn_x, volume_bar_rgn_y, volume_bar_rgn_w, volume_bar_rgn_h;             /*volume bar*/
    U16 volume_bar_bg_img_id;
    U16 volume_bar_fg_img_id;

    S16 volume_btn_pos_x, volume_btn_pos_y;                 /*progress bar button*/
    S16 volume_btn_rgn_x, volume_btn_rgn_y, volume_btn_rgn_w, volume_btn_rgn_h;
    U16 volume_btn_img_id;
    U16 volume_btn_img_hl_id;

    /*User rating popup setting*/
    S16 rating_set_regn_x, rating_set_regn_y, rating_set_regn_w, rating_set_regn_h;    /*user rating bg*/
    U16 rating_set_bg_img_id;

    S16 rating_star_pos_x, rating_star_pos_y;           /*Star highligh image*/
    U16 rating_star_fg_img_id;

    /*kuro setting*/
    S16 kuro_set_regn_x, kuro_set_regn_y, kuro_set_regn_w, kuro_set_regn_h;    /*kuro setting bg*/
    U16 kuro_set_bg_img_id;

    S16 cursor_regn_x, cursor_regn_y;                  /*indicator image*/
    U16 kuro_cursor_img_id;

    S16 vocal_remove_pos_x, vocal_remove_pos_y;         /*vocal remov button*/
    S16 vocal_remove_rgn_x, vocal_remove_rgn_y, vocal_remove_rgn_w, vocal_remove_rgn_h;
    U16 vocal_remove_on_up_img_id;
    U16 vocal_remove_on_down_img_id;
    U16 vocal_remove_off_up_img_id;
    U16 vocal_remove_off_down_img_id;
    U16 vocal_remove_disable_img_id;

    S16 rising_pos_x, rising_pos_y;                     /*pitch shift up button*/
    S16 rising_rgn_x, rising_rgn_y, rising_rgn_w, rising_rgn_h;
    U16 rising_up_img_id;
    U16 rising_down_img_id;
    U16 rising_disable_img_id;  

    S16 falling_pos_x, falling_pos_y;                     /*pitch shift down button*/
    S16 falling_rgn_x, falling_rgn_y, falling_rgn_w, falling_rgn_h;
    U16 falling_up_img_id;
    U16 falling_down_img_id;
    U16 falling_disable_img_id; 

    S16 active_pos_x, active_pos_y;                     /*active button*/
    S16 active_rgn_x, active_rgn_y, active_rgn_w, active_rgn_h;
    U16 active_up_img_id;
    U16 active_down_img_id;
    U16 active_disable_img_id;
    
} medply_fte_skin_struct;

extern const medply_fte_skin_struct   g_medply_fte_skin;
#else //__MMI_MEDIA_PLAYER_FTE__
typedef struct
{
    /*base background image*/
    U16 base_bg_img_id;
    /*button background image*/
    #if defined(__MMI_FTE_SUPPORT_SLIM__)
    U16 button_bg_img_id;
    S16 button_bg_x, button_bg_y;
    #endif
    /*content text color*/
    U8  text_bg_color_r, text_bg_color_g, text_bg_color_b;
    U8  text_fg_color_r, text_fg_color_g, text_fg_color_b;
    /*three layer region*/
    S16 title_layer_rgn_x, title_layer_rgn_y;
    S16 title_layer_rgn_w, title_layer_rgn_h;    
    S16 view_layer_rgn_x, view_layer_rgn_y;
    S16 view_layer_rgn_w, view_layer_rgn_h;
    S16 ctrl_layer_rgn_x, ctrl_layer_rgn_y;
    S16 ctrl_layer_rgn_w, ctrl_layer_rgn_h;
#if !defined (__MMI_FTE_SUPPORT__) 
    /*soft key region*/
    S16 soft_lkey_rgn_x, soft_lkey_rgn_y;
    S16 soft_lkey_rgn_w, soft_lkey_rgn_h; 
    S16 soft_rkey_rgn_x, soft_rkey_rgn_y;
    S16 soft_rkey_rgn_w, soft_rkey_rgn_h; 
#endif    
    /*title layer content*/
    S16 title_txt_rgn_x, title_txt_rgn_y;
    S16 title_txt_rgn_w, title_txt_rgn_h;   
    /*view layer content*/
    S16 meta_txt_rgn_x, meta_txt_rgn_y, meta_txt_rgn_w, meta_txt_rgn_h;
    S16 spectrum_rgn_x, spectrum_rgn_y, spectrum_rgn_w, spectrum_rgn_h;
    S16 lyrics_rgn_x, lyrics_rgn_y, lyrics_rgn_w, lyrics_rgn_h;

    S16 meta_img_rgn_x, meta_img_rgn_y, meta_img_rgn_w, meta_img_rgn_h;
    U16 meta_def_img_id;
    #if defined(__MMI_FTE_SUPPORT_SLIM__) || defined(__MMI_FTE_SUPPORT__) 
    S16 line_x, line_y;
    U16 line_img_id;
    #endif
        /*processing animation*/
    S16 wait_ani_x, wait_ani_y, wait_ani_w, wait_ani_h;
    #if defined(__MMI_FTE_SUPPORT_SLIM__) || defined(__MMI_FTE_SUPPORT__) 
    U16 wait_ani_fg_x, wait_ani_fg_y;
    #endif
    U16 wait_open_ani_id;
    U16 wait_bt_connect_ani_id;
    U16 wait_rtp_connect_ani_id;
    U16 wait_snap_shot_ani_id;   
    U16 unsupport_video_def_ani_id;
        /*processing percentage bar image*/
    S16 load_pecentage_bg_x, load_pecentage_bg_y;
    U16 load_pecentage_bg_img_id;  
    S16 load_pecentage_fg_x, load_pecentage_fg_y;
    #if defined(__MMI_FTE_SUPPORT_SLIM__) || defined(__MMI_FTE_SUPPORT__) 
    U16 load_pecentage_fg_w, load_pecentage_fg_h;
    #endif
    U16 load_pecentage_fg_img_id;  
        /*user rate image display*/
    S16 rate_img_pos_x, rate_img_pos_y;
    U16 rate_bg_img_id;
    U16 rate_fg_img_id;
    /*ctrl layer content*/
        /*timing display*/
    S16 time_pos_x, time_pos_y;
    U16 time_base_number_img_id;
    U16 time_colon_img_id;
    U16 time_bias_img_id;    
        /*duration bar display*/
    S16 duration_bar_pos_x, duration_bar_pos_y;
    S16 duration_bar_rgn_x, duration_bar_rgn_y, duration_bar_rgn_w, duration_bar_rgn_h;
    U16 duration_bar_bg_img_id;
    U16 duration_bar_fg_img_id;
	U16 duration_bar_md_img_id;
    U16 duration_bar_bg_disable_img_id;
        /*play and pause button*/
    S16 play_pause_pos_x, play_pause_pos_y;
    S16 play_pause_rgn_x, play_pause_rgn_y, play_pause_rgn_w, play_pause_rgn_h;
    U16 play_up_img_id;
    U16 play_down_img_id;
    U16 play_disable_img_id;
    U16 pause_up_img_id;
    U16 pause_down_img_id;
    U16 pause_disable_img_id;
        /*prev button*/
    S16 prev_pos_x, prev_pos_y;
    S16 prev_rgn_x, prev_rgn_y, prev_rgn_w, prev_rgn_h;
    U16 prev_up_img_id;
    U16 prev_down_img_id;
    U16 prev_disable_img_id;
        /*next button*/
    S16 next_pos_x, next_pos_y;
    S16 next_rgn_x, next_rgn_y, next_rgn_w, next_rgn_h;
    U16 next_up_img_id;
    U16 next_down_img_id;
    U16 next_disable_img_id;
        /*stop button*/
    S16 stop_pos_x, stop_pos_y;
    S16 stop_rgn_x, stop_rgn_y, stop_rgn_w, stop_rgn_h;
    U16 stop_up_img_id;
    U16 stop_down_img_id;
    U16 stop_disable_img_id;
	    /*mode button*/
#ifdef __MMI_VIDEO_3D_ANAGLYPH__
    S16 mode_pos_x, mode_pos_y;
    S16 mode_rgn_x, mode_rgn_y, mode_rgn_w, mode_rgn_h;
    U16 mode_2d_up_img_id;
    U16 mode_2d_down_img_id;
    U16 mode_2d_disable_img_id;
	U16 mode_3d_up_img_id;
    U16 mode_3d_down_img_id;
    U16 mode_3d_disable_img_id;
#endif
    
#if defined (__MMI_FTE_SUPPORT__) 
        /*left soft key*/
    S16 lsk_pos_x, lsk_pos_y;           
    S16 lsk_rgn_x, lsk_rgn_y, lsk_rgn_w, lsk_rgn_h;
    U16 lsk_up_img_id;
    U16 lsk_down_img_id;
    U16 lsk_disable_img_id;
    
        /*right soft key*/
    S16 rsk_pos_x, rsk_pos_y;           
    S16 rsk_rgn_x, rsk_rgn_y, rsk_rgn_w, rsk_rgn_h;
    U16 rsk_up_img_id;
    U16 rsk_down_img_id;
    U16 rsk_disable_img_id;
#endif    
        /*zoom button*/
    S16 zoom_pos_x, zoom_pos_y;
    S16 zoom_rgn_x, zoom_rgn_y, zoom_rgn_w, zoom_rgn_h;
    U16 zoom_up_img_id;
    U16 zoom_down_img_id;
    U16 zoom_disable_img_id;
        /*shuffle button*/
    S16 shuffle_pos_x, shuffle_pos_y;
    S16 shuffle_rgn_x, shuffle_rgn_y, shuffle_rgn_w, shuffle_rgn_h;
    U16 shuffle_on_up_img_id;
    U16 shuffle_on_down_img_id;
    U16 shuffle_off_up_img_id;
    U16 shuffle_off_down_img_id;
        /*repeat button*/
    S16 repeat_pos_x, repeat_pos_y;
    S16 repeat_rgn_x, repeat_rgn_y, repeat_rgn_w, repeat_rgn_h;
    U16 repeat_off_up_img_id;
    U16 repeat_off_down_img_id;
    U16 repeat_one_up_img_id;
    U16 repeat_one_down_img_id;
    U16 repeat_all_up_img_id;
    U16 repeat_all_down_img_id;
        /*snap_shot button*/
    S16 snap_shot_pos_x, snap_shot_pos_y;
    S16 snap_shot_rgn_x, snap_shot_rgn_y, snap_shot_rgn_w, snap_shot_rgn_h;
    U16 snap_shot_up_img_id;
    U16 snap_shot_down_img_id;
    U16 snap_shot_disable_img_id;
    U16 act_key_up_img_id;  /*active key image for music online register*/
    U16 act_key_down_img_id;
    U16 act_key_disable_img_id;
        /*volume bar display*/
    S16 volume_bar_pos_x, volume_bar_pos_y;
    U16 volume_bar_bg_img_id;  
    U16 volume_bar_fg_img_id; 
    
    S16 volume_inc_pos_x, volume_inc_pos_y;
    S16 volume_inc_rgn_x, volume_inc_rgn_y, volume_inc_rgn_w, volume_inc_rgn_h;
    U16 volume_inc_up_img_id;
    U16 volume_inc_down_img_id;
    U16 volume_inc_disable_img_id;

    S16 volume_dec_pos_x, volume_dec_pos_y;
    S16 volume_dec_rgn_x, volume_dec_rgn_y, volume_dec_rgn_w, volume_dec_rgn_h;
    U16 volume_dec_up_img_id;
    U16 volume_dec_down_img_id;
    U16 volume_dec_disable_img_id;

    S16 volume_spk_pos_x, volume_spk_pos_y;
    S16 volume_spk_rgn_x, volume_spk_rgn_y, volume_spk_rgn_w, volume_spk_rgn_h;
    U16 volume_spk_out_up_img_id;  
    U16 volume_spk_out_down_img_id;  
    U16 volume_spk_mute_up_img_id; 
    U16 volume_spk_mute_down_img_id; 

} medply_skin_struct;

extern const medply_skin_struct   g_medply_skin;

#endif /*#if defined(__MMI_MEDIA_PLAYER__)*/
#endif /* _MEDIA_PLAYER_SKIN_H_ */
#endif

