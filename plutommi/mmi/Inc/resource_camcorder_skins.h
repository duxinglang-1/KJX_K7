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
 *	 resource_camcorder_skins.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Camera customization file.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/ 
#ifndef _CAMCORDER_SKIN_H_
#define _CAMCORDER_SKIN_H_

#include "MMI_features.h"
#ifdef __MMI_CAMCORDER__

#include "gdi_lcd_config.h"

#define CAMCO_SOUND_DUMMY_BG_LEN	(94)
#define CAMCO_SOUND_COUNTDOWN_LEN	(1374)
#define CAMCO_SOUND_AF_SUCCEED_LEN (3695)
/***************************************************************************** 
* Struct
*****************************************************************************/
#if defined(__MMI_FTE_SUPPORT__) && defined (__MMI_TOUCH_SCREEN__)
    #define __MMI_ZOOM_SLIDER_BAR__
#endif

#if (defined(__MMI_FTE_SUPPORT__) && defined(__MMI_CAMCO_FTE_SWITCH__))

//#ifdef __MMI_FTE_SUPPORT__

typedef struct 
{
    S32 offset_x;
    S32 offset_y;    

} mmi_camco_skin_pos_struct;


typedef struct 
{
    mmi_camco_skin_pos_struct capmode;
    mmi_camco_skin_pos_struct camscenemode;
    mmi_camco_skin_pos_struct capsize;
    mmi_camco_skin_pos_struct flash;
    mmi_camco_skin_pos_struct highlight;
    mmi_camco_skin_pos_struct afrange;
    mmi_camco_skin_pos_struct selftimer;
    mmi_camco_skin_pos_struct iso;    
    mmi_camco_skin_pos_struct wb;        
    mmi_camco_skin_pos_struct storage;  
    mmi_camco_skin_pos_struct capqty;  
    mmi_camco_skin_pos_struct aemeter; 
    mmi_camco_skin_pos_struct timestamp;
    mmi_camco_skin_pos_struct facedetect;
    mmi_camco_skin_pos_struct panorama_hor;
    mmi_camco_skin_pos_struct panorama_ver;    

    mmi_camco_skin_pos_struct corner_hint;
    
} mmi_camco_camera_preview_skin_struct;


typedef struct 
{
    mmi_camco_skin_pos_struct vdoscenemode;
    mmi_camco_skin_pos_struct recsize;
    mmi_camco_skin_pos_struct highlight;
    mmi_camco_skin_pos_struct afrange;
    mmi_camco_skin_pos_struct wb;      
    mmi_camco_skin_pos_struct limit;     
    mmi_camco_skin_pos_struct storage;  
    mmi_camco_skin_pos_struct visqty;  
    mmi_camco_skin_pos_struct afmode;   
    mmi_camco_skin_pos_struct aemeter;
    mmi_camco_skin_pos_struct recaud;

    mmi_camco_skin_pos_struct corner_hint;
    
} mmi_camco_video_preview_skin_struct;


typedef struct 
{
    mmi_camco_skin_pos_struct zoom;
    mmi_camco_skin_pos_struct flash;
    mmi_camco_skin_pos_struct scenemode;
    mmi_camco_skin_pos_struct capturemode;
    mmi_camco_skin_pos_struct imgviewer;
    mmi_camco_skin_pos_struct advance_setting;
    mmi_camco_skin_pos_struct back;
    mmi_camco_skin_pos_struct switch_mode_top; 
    mmi_camco_skin_pos_struct switch_mode_botton; 

    mmi_camco_skin_pos_struct direct_setting_menu_title;    
    mmi_camco_skin_pos_struct direct_setting_menu_sub_title2;        
    mmi_camco_skin_pos_struct direct_setting_menu_body;  
    mmi_camco_skin_pos_struct direct_setting_menu_item[12];      

    mmi_camco_skin_pos_struct direct_setting_slider_top;        
    mmi_camco_skin_pos_struct direct_setting_slider_bar;            
    mmi_camco_skin_pos_struct direct_setting_slider_botton;            
    mmi_camco_skin_pos_struct direct_setting_slider_location;                
  
    
} mmi_camco_camera_preview_setting_skin_struct;


typedef struct 
{
    mmi_camco_skin_pos_struct zoom;
    mmi_camco_skin_pos_struct dummy1;
    mmi_camco_skin_pos_struct scenemode;
    mmi_camco_skin_pos_struct dummy2;
    mmi_camco_skin_pos_struct allvideos;
    mmi_camco_skin_pos_struct advance_setting;
    mmi_camco_skin_pos_struct back;
    mmi_camco_skin_pos_struct switch_mode_top; 
    mmi_camco_skin_pos_struct switch_mode_botton; 

    mmi_camco_skin_pos_struct direct_setting_menu_title;    
    mmi_camco_skin_pos_struct direct_setting_menu_sub_title2;        
    mmi_camco_skin_pos_struct direct_setting_menu_body;  
    mmi_camco_skin_pos_struct direct_setting_menu_item[12];      
    mmi_camco_skin_pos_struct direct_setting_slider_top;        
    mmi_camco_skin_pos_struct direct_setting_slider_bar;            
    mmi_camco_skin_pos_struct direct_setting_slider_botton;        
    mmi_camco_skin_pos_struct direct_setting_slider_location;         
    
} mmi_camco_video_preview_setting_skin_struct;

typedef struct 
{
    mmi_camco_skin_pos_struct slider_top;        
    mmi_camco_skin_pos_struct slider_bar;            
    mmi_camco_skin_pos_struct slider_botton;        
    mmi_camco_skin_pos_struct slider_location; 
     
    mmi_camco_skin_pos_struct pause_resume;       
    mmi_camco_skin_pos_struct start_stop;       

} mmi_camco_video_recording_skin_struct;


typedef struct 
{
    mmi_camco_skin_pos_struct main_setting_tab;
    mmi_camco_skin_pos_struct misc_setting_tab;
    mmi_camco_skin_pos_struct main_tab_titie;
    mmi_camco_skin_pos_struct misc_tab_titie;    
    mmi_camco_skin_pos_struct back;        
    mmi_camco_skin_pos_struct select;          
    mmi_camco_skin_pos_struct Level1_setting_wnd_top1;    
    mmi_camco_skin_pos_struct Level1_setting_wnd_top2;        
    mmi_camco_skin_pos_struct Level1_setting_wnd_item;
    mmi_camco_skin_pos_struct Level1_setting_wnd_attr;    
    mmi_camco_skin_pos_struct Level1_setting_wnd_value;        
    mmi_camco_skin_pos_struct Level1_setting_wnd_icon;            
    U8 Level1_setting_item_count;
    mmi_camco_skin_pos_struct Level1_setting_wnd_botton;     
    U16 Level_setting_valuse_offset_x;
    mmi_camco_skin_pos_struct Level1_setting_wnd_scrolling_bar; 
    U16 Level1_setting_wnd_scrolling_region[2];     
    mmi_camco_skin_pos_struct Level1_setting_wnd_scrolling_ind;
    
    mmi_camco_skin_pos_struct Level2_setting_wnd_top;        
    mmi_camco_skin_pos_struct Level2_setting_wnd_item;
    mmi_camco_skin_pos_struct Level2_setting_wnd_check;    
    mmi_camco_skin_pos_struct Level2_setting_wnd_value;            
    mmi_camco_skin_pos_struct Level2_setting_wnd_icon;        
    U8 Level2_setting_item_count;
    mmi_camco_skin_pos_struct Level2_setting_wnd_botton;        
    mmi_camco_skin_pos_struct Level2_setting_wnd_scrolling_bar; 
    U16 Level2_setting_wnd_scrolling_region[2];
    mmi_camco_skin_pos_struct Level2_setting_wnd_scrolling_ind;     
    
} mmi_camco_advance_setting_skin_struct;

typedef struct 
{
    mmi_camco_skin_pos_struct option_wnd_title;
    mmi_camco_skin_pos_struct option_wnd_body;
    mmi_camco_skin_pos_struct option_wnd_content;    
    mmi_camco_skin_pos_struct option_left_softkey;
    mmi_camco_skin_pos_struct option_right_softkey;
    
} mmi_camco_confirm_skin_struct;

typedef struct 
{
    mmi_camco_skin_pos_struct toolbar[3];
    
} mmi_camco_captured_skin_struct;

typedef struct 
{
    mmi_camco_skin_pos_struct option_wnd_title;
    mmi_camco_skin_pos_struct option_wnd_sub_title;
    mmi_camco_skin_pos_struct option_wnd_body;
    mmi_camco_skin_pos_struct option_item;
    U8 option_item_count;  
    mmi_camco_skin_pos_struct back;
    mmi_camco_skin_pos_struct toolbar[3];                 
    
} mmi_camco_forward_option_skin_struct;


typedef struct
{
    mmi_camco_skin_pos_struct   record_dot;  
    U32                         progress_width;
    U32                         progress_height;
    
} mmi_camco_video_record_skin_struct;

typedef struct
{
    BOOL                        is_horizontal_display;
    U8                          display_count;
    mmi_camco_skin_pos_struct   img_list_offset;      
    mmi_camco_skin_pos_struct   img_frame;
    U8 img_w;
    U8 img_h;
    mmi_camco_skin_pos_struct hilite_img_pos;
    U32 hilite_img_w;
    U32 hilite_img_h;    
    mmi_camco_skin_pos_struct toolbar[3];    
    
} mmi_camco_multi_select_cache_skin_struct;

typedef struct
{
    mmi_camco_skin_pos_struct   left_arrow;  
    mmi_camco_skin_pos_struct   right_arrow;  
    mmi_camco_skin_pos_struct   file_index;
    
} mmi_camco_add_frame_skin_struct;

typedef struct
{
    U8  offset_y_from_bottom;  
    U32 offset_x_from_right;
    
} mmi_camco_time_stamp_pos_struct;


typedef struct
{
    mmi_camco_time_stamp_pos_struct wallpaper;
    mmi_camco_time_stamp_pos_struct HLCD;
    mmi_camco_time_stamp_pos_struct VGA_to_2M;
    mmi_camco_time_stamp_pos_struct Three_M;
    mmi_camco_time_stamp_pos_struct Four_M;
    mmi_camco_time_stamp_pos_struct Five_M;
    U8  date_interval;
    U8  offset_to_time;
    
} mmi_camco_time_stamp_skin_struct;


typedef struct
{
    mmi_camco_camera_preview_skin_struct camera_preview;
    mmi_camco_video_preview_skin_struct video_preview;

    mmi_camco_camera_preview_setting_skin_struct camera_direct_setting;
    mmi_camco_video_preview_setting_skin_struct video_direct_setting;
    
    mmi_camco_advance_setting_skin_struct advance_setting;
    mmi_camco_forward_option_skin_struct forward_option;
    mmi_camco_confirm_skin_struct confirm;    

    mmi_camco_captured_skin_struct captured;    
        
    mmi_camco_video_record_skin_struct  video_record;
    mmi_camco_multi_select_cache_skin_struct multiselect_cache;
    mmi_camco_add_frame_skin_struct add_frame;
    mmi_camco_time_stamp_skin_struct time_stamp;
    mmi_camco_skin_pos_struct xenon_status;
   

    mmi_camco_video_recording_skin_struct recording_screen;

    mmi_camco_skin_pos_struct sensor_switcher;
 
} mmi_camco_skin_struct;

#else

typedef struct 
{
    S32 offset_x;
    S32 offset_y;    

} mmi_camco_skin_pos_struct;


typedef struct 
{
    mmi_camco_skin_pos_struct capmode;
    mmi_camco_skin_pos_struct camscenemode;
    mmi_camco_skin_pos_struct capsize;
    mmi_camco_skin_pos_struct flash;
    mmi_camco_skin_pos_struct highlight;
    mmi_camco_skin_pos_struct afrange;
    mmi_camco_skin_pos_struct selftimer;
    mmi_camco_skin_pos_struct iso;    
    mmi_camco_skin_pos_struct wb;        
    mmi_camco_skin_pos_struct storage;  
    mmi_camco_skin_pos_struct capqty;  
    mmi_camco_skin_pos_struct aemeter; 
    mmi_camco_skin_pos_struct timestamp;
    mmi_camco_skin_pos_struct facedetect;
    mmi_camco_skin_pos_struct corner_hint;
    
} mmi_camco_camera_preview_skin_struct;


typedef struct 
{
    mmi_camco_skin_pos_struct vdoscenemode;
    mmi_camco_skin_pos_struct recsize;
    mmi_camco_skin_pos_struct highlight;
    mmi_camco_skin_pos_struct afrange;
    mmi_camco_skin_pos_struct wb;      
    mmi_camco_skin_pos_struct limit;     
    mmi_camco_skin_pos_struct storage;  
    mmi_camco_skin_pos_struct visqty;  
    mmi_camco_skin_pos_struct afmode;   
    mmi_camco_skin_pos_struct aemeter;
    mmi_camco_skin_pos_struct recaud;
	mmi_camco_skin_pos_struct timelaps;
    mmi_camco_skin_pos_struct corner_hint;
    
} mmi_camco_video_preview_skin_struct;


typedef struct
{
    mmi_camco_skin_pos_struct   iconlist;
    U8                          icon_count;

    mmi_camco_skin_pos_struct   menulist; /* left bottom position */
    U8                          menu_count;
    
} mmi_camco_setting_skin_struct;

typedef struct
{
    mmi_camco_skin_pos_struct   menulist;   /* right up position */
    U8                          menu_count;
    
} mmi_camco_option_skin_struct;

typedef struct
{
    mmi_camco_skin_pos_struct   record_dot;  
    U32                         progress_width;
    U32                         progress_height;
    
} mmi_camco_video_record_skin_struct;

typedef struct
{
    mmi_camco_skin_pos_struct   border;  
    U32                         interval;
    BOOL                        is_horizontal_display;
    U8                          display_count;
    U32                         arrow_interval;
    
} mmi_camco_multi_select_cache_skin_struct;


typedef struct
{
    mmi_camco_skin_pos_struct   left_arrow;  
    mmi_camco_skin_pos_struct   right_arrow;  
    mmi_camco_skin_pos_struct   file_index;
    
} mmi_camco_add_frame_skin_struct;

typedef struct
{
    mmi_camco_skin_pos_struct   left_softkey;  
    mmi_camco_skin_pos_struct   center_softkey;
    mmi_camco_skin_pos_struct   right_softkey;  

} mmi_camco_softkey_skin_struct;

typedef struct
{
    U8  offset_y_from_bottom;  
    U32 offset_x_from_right;
    
} mmi_camco_time_stamp_pos_struct;

typedef struct
{
    mmi_camco_time_stamp_pos_struct wallpaper;
    mmi_camco_time_stamp_pos_struct HLCD;
    mmi_camco_time_stamp_pos_struct VGA_to_2M;
    mmi_camco_time_stamp_pos_struct Three_M;
    mmi_camco_time_stamp_pos_struct Four_M;
    mmi_camco_time_stamp_pos_struct Five_M;
    U8  date_interval;
    U8  offset_to_time;
    
} mmi_camco_time_stamp_skin_struct;

typedef struct
{
    mmi_camco_skin_pos_struct ua;
    mmi_camco_skin_pos_struct da;
    mmi_camco_skin_pos_struct la;
    mmi_camco_skin_pos_struct ra;
    mmi_camco_skin_pos_struct shot_up;  
    mmi_camco_skin_pos_struct shot_da;
    mmi_camco_skin_pos_struct shot_la;
    mmi_camco_skin_pos_struct shot_ra;
} mmi_camco_autorama_skin_struct;

typedef struct
{
    mmi_camco_skin_pos_struct lattice;
	U32                       interval;
} mmi_camco_mav_skin_struct;
typedef struct
{
    mmi_camco_camera_preview_skin_struct camera_preview;
    mmi_camco_video_preview_skin_struct video_preview;
    mmi_camco_setting_skin_struct setting;
    mmi_camco_option_skin_struct option;
    mmi_camco_video_record_skin_struct  video_record;
    mmi_camco_multi_select_cache_skin_struct multiselect_cache;
    mmi_camco_add_frame_skin_struct add_frame;
    mmi_camco_time_stamp_skin_struct time_stamp;
    mmi_camco_skin_pos_struct xenon_status;
    mmi_camco_autorama_skin_struct autorama;
	mmi_camco_mav_skin_struct mav_shot;
    #ifdef __MMI_FTE_SUPPORT__
    mmi_camco_softkey_skin_struct softkey;
    #endif
#ifdef __MMI_ZOOM_SLIDER_BAR__
	mmi_camco_skin_pos_struct zoom_slider_top;		
	mmi_camco_skin_pos_struct zoom_slider_bar;			
	mmi_camco_skin_pos_struct zoom_slider_botton; 		   
	mmi_camco_skin_pos_struct zoom_slider_location; 
#else
    mmi_camco_skin_pos_struct zoom;      
    mmi_camco_skin_pos_struct zoom_out;  
    mmi_camco_skin_pos_struct zoom_in; 
#endif  
} mmi_camco_skin_struct;

#endif
/***************************************************************************** 
* Local Variable
*****************************************************************************/
extern mmi_camco_skin_struct mmi_camco_main_skin_cntx;
#ifdef DUAL_CAMERA_SUPPORT
extern mmi_camco_skin_struct mmi_camco_sub_skin_cntx;
#endif
#ifdef __MTK_TARGET__
extern __align(2) const U8 camco_sound_dummy_bg[CAMCO_SOUND_DUMMY_BG_LEN];
extern __align(2) const U8 camco_sound_countdown[CAMCO_SOUND_COUNTDOWN_LEN];
extern __align(2) const U8 camco_af_succeed[CAMCO_SOUND_AF_SUCCEED_LEN];
#else
extern const U8 camco_sound_dummy_bg[CAMCO_SOUND_DUMMY_BG_LEN];
extern const U8 camco_sound_countdown[CAMCO_SOUND_COUNTDOWN_LEN];
extern const U8 camco_af_succeed[CAMCO_SOUND_AF_SUCCEED_LEN];
#endif

#endif /* __MMI_CAMCORDER__ */
#endif /* _CAMCORDER_SKIN_H_ */
