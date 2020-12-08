/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

#ifndef __VAPP_AUTOCAP_OSD__
#define __VAPP_AUTOCAP_OSD__

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "mdi_camera.h"
#include "mdi_video.h"
#include "MMI_include.h"
#include "vapp_autocap_setting_item.h"
#if defined(__MMI_CAMCORDER__) && (defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) || defined(__MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__))


#define VAPP_AUTOCAP_PREVIEW_SETTING_LIST_ITEM_COUNT  (9)
#define VAPP_AUTOCAP_SUPPORT_FACE_NUM                 (MDI_CAMERA_FD_MAX_NO)

#if defined(__MMI_AUTOCAP_FEATURE_CAM_BURSTSHOT_SELECT__) || defined(__MMI_AUTOCAP_FEATURE_CAM_AEBSHOT_SELECT__)
    #if (MMI_AUTOCAP_FEATURE_CAM_BURSTSHOT_IMAGE_COUNT > MMI_AUTOCAP_FEATURE_CAM_AEBSHOT_IMAGE_COUNT)
        #define MMI_AUTOCAP_OSD_MULTI_SHOT_COUNT          (MMI_AUTOCAP_FEATURE_CAM_BURSTSHOT_IMAGE_COUNT)    
    #else
        #define MMI_AUTOCAP_OSD_MULTI_SHOT_COUNT          (MMI_AUTOCAP_FEATURE_CAM_AEBSHOT_IMAGE_COUNT)    
    #endif
#else
    #define MMI_AUTOCAP_OSD_MULTI_SHOT_COUNT          (1)
#endif

typedef enum
{

    VAPP_AUTOCAP_OSD_SETTING_NONE,
    VAPP_AUTOCAP_OSD_SETTING_COMMON_ONLY,    
    VAPP_AUTOCAP_OSD_SETTING_FULL,    
    VAPP_AUTOCAP_OSD_SETTING_END
    
}vapp_autocap_osd_level_enum;

typedef enum
{
    VAPP_AUTOCAP_OSD_STATE_HIDE,
    VAPP_AUTOCAP_OSD_STATE_HINT,
    VAPP_AUTOCAP_OSD_STATE_CAMERA_PREVIEW,
    VAPP_AUTOCAP_OSD_STATE_CAMERA_QUICK_VIEW,    
    VAPP_AUTOCAP_OSD_STATE_PANORAMA_SHOT,
    VAPP_AUTOCAP_OSD_STATE_PANORAMA_CLIP,    

    VAPP_AUTOCAP_OSD_STATE_EXIT,

    VAPP_AUTOCAP_OSD_STATE_END
} vapp_autocap_osd_state_enum;

typedef enum
{
    // need to restart preview
    VAPP_AUTOCAP_EVT_RESTART,                 /* 0 */

    // rotate the App coord
    VAPP_AUTOCAP_EVT_FORCE_HORZ,              /* 1 */
    VAPP_AUTOCAP_EVT_DE_FORCE_HORZ,           /* 2 */            

    // preview btn event
    VAPP_AUTOCAP_EVT_ENTER_GALLERY,           /* 3 */
    VAPP_AUTOCAP_EVT_CAPTURE,                 /* 4 */
    VAPP_AUTOCAP_EVT_SWITCH_SENSOR,           /* 5 */

    // single shot quick view animate finish eveny
    VAPP_AUTOCAP_EVT_VIEW_STOP,               /* 6 */

    // panorama sticth event (not take 3 pic yet)
    VAPP_AUTOCAP_EVT_STITCH,                  /* 7 */
    VAPP_AUTOCAP_EVT_CLIP,                    /* 8 */    

    // focus key press event
    VAPP_AUTOCAP_EVT_FOCUS,                   /* 9 */
    VAPP_AUTOCAP_EVT_FOCUS_STOP,              /* 10 */
    
    // notify popup event
    VAPP_AUTOCAP_EVT_BACK,                    /* 11 */
    
    // confirm popup event
    VAPP_AUTOCAP_EVT_OK,                      /* 12 */
    VAPP_AUTOCAP_EVT_CANCEL,                  /* 13 */

    // auto exit timeout event
    VAPP_AUTOCAP_EVT_AUTO_EXIT,               /* 14 */

    // background calculation event 
    VAPP_AUTOCAP_EVT_BG_CAL_START,            /* 15 */
    VAPP_AUTOCAP_EVT_BG_CAL_STOP,             /* 16 */
    
    // MAV switch the Horz/Vert
    VAPP_AUTOCAP_EVT_VIEW_SWITCH,             /* 17 */
    //----------------------------------
    VAPP_AUTOCAP_EVT_END
} mmi_cameco_evt_type_enum;



typedef enum 
{
    VAPP_AUTOCAP_DRAW_IMG_SRC_BUFF,
    VAPP_AUTOCAP_DRAW_IMG_SRC_JPEG,        
    VAPP_AUTOCAP_DRAW_IMG_SRC_FILE,
    VAPP_AUTOCAP_DRAW_IMG_SRC_COLOR,    
    VAPP_AUTOCAP_DRAW_IMG_SRC_END    
    
}vapp_autocap_osd_draw_image_src_enum;

typedef enum 
{
    VAPP_AUTOCAP_OSD_SETTING_MODE_SLIDER,
    VAPP_AUTOCAP_OSD_SETTING_MODE_MULTI_SLIDER,
    VAPP_AUTOCAP_OSD_SETTING_MODE_ROTATOR,
    VAPP_AUTOCAP_OSD_SETTING_MODE_MENU,
    VAPP_AUTOCAP_OSD_SETTING_MODE_END
    
}vapp_autocap_osd_setting_mode_enum;

typedef enum
{
    VAPP_AUTOCAP_OSD_FOCUS_REGION_1,
    VAPP_AUTOCAP_OSD_FOCUS_REGION_2,
    VAPP_AUTOCAP_OSD_FOCUS_REGION_3,
    VAPP_AUTOCAP_OSD_FOCUS_REGION_4,
    VAPP_AUTOCAP_OSD_FOCUS_REGION_5,

    VAPP_AUTOCAP_OSD_FOCUS_REGION_END
} vapp_autocap_osd_focus_region_enum;

typedef enum
{
    VAPP_AUTOCAP_OSD_FOCUS_TYPE_NULL,
    VAPP_AUTOCAP_OSD_FOCUS_TYPE_FOCUSING,
    VAPP_AUTOCAP_OSD_FOCUS_TYPE_FOCUSED,
    VAPP_AUTOCAP_OSD_FOCUS_TYPE_FOCUSING_FAIL,
    VAPP_AUTOCAP_OSD_FOCUS_TYPE_MACRO,

    VAPP_AUTOCAP_OSD_FOCUS_TYPE_END
} vapp_autocap_osd_focus_type_enum;

typedef enum
{
    VAPP_AUTOCAP_OSD_FACEDETECT_TYPE_NULL,
    VAPP_AUTOCAP_OSD_FACEDETECT_TYPE_TRACKING,
    VAPP_AUTOCAP_OSD_FACEDETECT_TYPE_FOCUSED,

    VAPP_AUTOCAP_OSD_FACEDETECT_TYPE_END
} vapp_autocap_osd_facedetect_type_enum;

typedef enum
{
    VAPP_AUTOCAP_OSD_HINT_EVT_CAM_STITCHING,
    VAPP_AUTOCAP_OSD_HINT_EVT_CAM_NO_CARD,
    VAPP_AUTOCAP_OSD_HINT_EVT_ERROR,    
    VAPP_AUTOCAP_OSD_HINT_EVT_OTHERS,
    
    VAPP_AUTOCAP_OSD_HINT_EVT_END
    
} vapp_autocap_osd_hint_event_enum;

typedef enum
{
    VAPP_AUTOCAP_OSD_HINT_TYPE_PROCESSING,
    VAPP_AUTOCAP_OSD_HINT_TYPE_HINT,        
    VAPP_AUTOCAP_OSD_HINT_TYPE_HINT_TEXT,   
    VAPP_AUTOCAP_OSD_HINT_TYPE_HINT_ICON,        
    VAPP_AUTOCAP_OSD_HINT_TYPE_CONFIRM,
    VAPP_AUTOCAP_OSD_HINT_TYPE_NOTIFY,                    
    VAPP_AUTOCAP_OSD_HINT_TYPE_NONE,          
    
    VAPP_AUTOCAP_OSD_HINT_TYPE_END
    
} vapp_autocap_osd_hint_type_enum;

typedef enum
{
    VAPP_AUTOCAP_OSD_QV_EVT_NORMAL_SHOT,
    VAPP_AUTOCAP_OSD_QV_EVT_PANORAMA_SHOT,
    VAPP_AUTOCAP_OSD_QV_EVT_CONT_SHOT,
    VAPP_AUTOCAP_OSD_QV_EVT_BURST_SHOT,
    VAPP_AUTOCAP_OSD_QV_EVT_EV_BEST_SHOT,

    VAPP_AUTOCAP_OSD_QV_EVT_END
    
} vapp_autocap_osd_quick_view_event_enum;

typedef enum
{ 
    VAPP_AUTOCAP_OSD_SCR_PARAM_SET_FOCUS,            
    VAPP_AUTOCAP_OSD_SCR_PARAM_RESET_FOCUS, 

    VAPP_AUTOCAP_OSD_SCR_PARAM_ZOOM_UPDATE,
    
    VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_DIR_UPDATE,
    VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_RATIO_UPDATE,    
    VAPP_AUTOCAP_OSD_SCR_PARAM_CAM_AUTORAMA_MV_UPDATE,        

    VAPP_AUTOCAP_OSD_SCR_PARAM_SET_BUSY,

    VAPP_AUTOCAP_OSD_SCR_PARAM_END
    
} vapp_autocap_osd_scr_param_enum;



typedef struct
{
    vapp_autocap_osd_draw_image_src_enum    drawingType;
    // pure color case
    VfxColor                                bgColor;
    // fill from file case        
    WCHAR                                  *srcFileName;
    // fill from mem case            
    void                                   *srcBuffAdress;    
    VfxU32                                  srcWidth;
    VfxU32                                  srcHeight;    
    // fill from jpeg buffer case       
    void                                   *srcJpgBuffAdress;        
    void                                   *cacheBuffAdress;        
    VfxU32                                  srcSize;
}vapp_autocap_osd_draw_image_struct;


typedef struct
{
    S32                                     center_x;
    S32                                     center_y;
    S32                                     w;
    S32                                     h;
    vapp_autocap_osd_focus_type_enum        type;
    
} vapp_autocap_osd_focus_struct;

typedef struct
{
    S32                                     offset_x;
    S32                                     offset_y;
    MMI_ID_TYPE                             img_id;
    MMI_BOOL                                is_processing;
    MMI_BOOL                                is_hint_show;

} vapp_autocap_osd_focus_hint_struct;

typedef struct
{
    S32                                     x;
    S32                                     y;
    S32                                     w;
    S32                                     h;
    vapp_autocap_osd_facedetect_type_enum   type;
    
} vapp_autocap_osd_facedetect_region_struct;

typedef struct
{
    S32                                     x;
    S32                                     y;
    S32                                     w;
    S32                                     h;
    vapp_autocap_osd_facedetect_type_enum   type;

} vapp_autocap_osd_smiledetect_region_struct;


typedef struct
{
    vapp_autocap_osd_facedetect_region_struct trackingRegion[VAPP_AUTOCAP_SUPPORT_FACE_NUM];
    VfxColor                                trackingColor;
    VfxColor                                trackingBorderColor;
    VfxColor                                focusedColor;
    VfxColor                                focusedBorderColor;

    VfxU8                                   opacity; /* 255 = no opacity, 0 = full opacity */

    VfxBool                                 isTracking;

} vapp_autocap_osd_facedetect_struct;

typedef struct
{
    vapp_autocap_osd_smiledetect_region_struct trackingRegion[VAPP_AUTOCAP_SUPPORT_FACE_NUM];        /* to do: define VAPP_AUTOCAP_SUPPORT_SMILEFACE_NUM */
    VfxColor                                 trackingColor;
    VfxColor                                 trackingBorderColor;
    VfxColor                                 focusedColor;
    VfxColor                                 focusedBorderColor;

    VfxU8                                    opacity; /* 255 = no opacity, 0 = full opacity */

    VfxBool                                  isTracking;
    VfxBool                                  isZoomable;

} vapp_autocap_osd_smiledetect_struct;

typedef struct
{
    vapp_autocap_osd_focus_struct           focusRegion[VAPP_AUTOCAP_OSD_FOCUS_REGION_END];
    VfxColor                                focusedColor;
    VfxColor                                focusedBorderColor;
    VfxColor                                focusingColor;
    VfxColor                                focusingBorderColor;
    VfxColor                                focusingFailColor;
    VfxColor                                focusingFailBorderColor;
    VfxU8                                   focusOpacity;   /* 255 = no opacity, 0 = full opacity */
    
} vapp_autocap_osd_focuse_struct;

typedef struct
{
    VfxBool                                 isCleanBG;        
    
}vapp_autocap_osd_hide_param_struct;

typedef struct
{
    AutoCapSettingMgr                      *setting;   

    VfxBool                                 isHorzUI;       
    vapp_autocap_osd_hint_event_enum        event;         //valid if need user interaction
    vapp_autocap_osd_hint_type_enum         type;
 
    VfxWString                              hintText;
    VfxS32                                  hintIcon;    
    VfxBool                                 isPreviewON;
    vapp_autocap_osd_draw_image_struct      bgContent;

        
}vapp_autocap_osd_hint_param_struct;



typedef struct
{    
    AutoCapSettingMgr                      *setting;   
    
    // anchor : (0.5,0.5);
    VfxRect                                 previewWindow;

    VfxBool                                 isMavMode;
    VfxBool                                 is3DCameraMode;

    VfxBool                                 isCleanModeEnter;    
    VfxBool                                 isRestartEnter;     

    VfxU32                                  capturableNumber;

    vapp_autocap_osd_level_enum             settingLevel;

    VfxWChar                               *previousFileName;    

    MMI_ID                                  indicatorStringID;    
}vapp_autocap_osd_cam_preview_param_struct;


typedef struct
{
    VfxBool                                 isHorzUI;      
    vapp_autocap_osd_quick_view_event_enum  type;   
    
    // for single shot use       
    vapp_autocap_osd_draw_image_struct      savedImg;

    VfxU32                                  hiliteIdx;
    
}vapp_autocap_osd_cam_quick_view_param_struct;

typedef struct
{
    VfxBool                                 isHorzUI;   
    VfxBool                                 isCamera;
    
}vapp_autocap_osd_focuse_param_struct;

typedef struct
{
    VfxBool                                 isHorzUI;   
    VfxBool                                 isCamera;

}vapp_autocap_osd_focuse_hint_param_struct;


typedef struct
{
    VfxBool                                 isHorzUI;   
    VfxBool                                 isMavMode;

    // anchor : (0.5,0.5);
    VfxRect                                 previewWindow;
    
    VfxU32                                  count;    
    VfxU32                                  totalCount;
    vapp_autocap_panorama_direction_enum    direction;

    VfxFloat                                overlapRatio;    

    // when in MAV only project
    // 0 cannot be a size of array
#if defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__)
    vapp_autocap_osd_draw_image_struct      capturedPicture[MMI_CAMCO_FEATURE_CAM_PANORAMA_SHOT_IMAGE_COUNT];
#else
    vapp_autocap_osd_draw_image_struct      capturedPicture[1];
#endif
}vapp_autocap_osd_cam_panoramashot_param_struct;

typedef struct
{
    VfxBool                                 isHorzUI;  
    vapp_autocap_panorama_direction_enum    direction;    
    VfxU32                                 *leftBound;
    VfxU32                                 *rightBound;

    void                                   *quickViewBuffer;
    void                                   *quickViewSourceBuffer;    
    VfxU32                                  quickViewStartPoint[2];
    VfxU32                                  quickViewSize[2];

    // anchor : (0.5,0.5);
    VfxRect                                 previewWindow;    
     
}vapp_autocap_osd_cam_panoramashot_clip_param_struct;

typedef struct
{
    vapp_autocap_osd_scr_param_enum               type;   
    
    VfxU32 index;
    // set face detect result / auto focus result case   
    vapp_autocap_osd_focus_struct                 focus;

    // update zoom case
    VfxU32                                        zoom_value;
    
    // update remain size case    
    VfxU32                                        remain_size;  
    MMI_ID                                        indicator_string;

    // update autorama direction case
    vapp_autocap_panorama_direction_enum          direction;    
    VfxS32                                        motionX;
    VfxS32                                        motionY;    
    VfxFloat                                      ratio;

    // tell OSD, AP is busy cannot recv next instrution
    VfxBool                                       isBusy;
    
}vapp_autocap_osd_screen_param_struct;


typedef struct
{
    //all pos is set by center of icon / left center of text
    
    // settingBar:
    VfxU32                              SideBarSize[2];              // width,height on H screen

    //zoomControl:
    VfxU32                              zoomControlPos[2];           // x,y of zoom control
    VfxU32                              zoomCurveR;                  // R of zoom control curve
    VfxU32                              zoomIndBetweeR;              // distance of inner and outer cycle of zoomer indicator
    VfxU32                              zoomIndR;                    // R of zoomer indicator

    // right side btn
    VfxU32                              galleryPos[2];               // x,y of gallery btn
    VfxU32                              switchSensorPos[2];          // x,y of switchSensor btn
    VfxU32                              switchAppPos[2];             // x,y of switchApp btn
    VfxU32                              capturePos[2];               // x,y of capture btn
    VfxU32                              storagePos[2];               // x,y of storage btn

    VfxU32                              previousIconSize[2];         // width,height on H screen
    VfxU32                              nextFocusSize[2];            // width,height on H screen

    // direction icon
    VfxU32                              leftDirection[2];
    VfxU32                              rightDirection[2];
    VfxU32                              upDirection[2];
    VfxU32                              downDirection[2];    

    // direction indicator icon
    VfxU32                              leftIndicatorDirection[2];
    VfxU32                              rightIndicatorDirection[2];
    VfxU32                              upIndicatorDirection[2];
    VfxU32                              downIndicatorDirection[2];    

    // capture process
    VfxU32                              captureHorzDirBar[2];
    VfxU32                              captureVertDirBar[2];    
    VfxU32                              captureHorzDirStitch[2];
    VfxU32                              captureHorzDirback[2];
    VfxU32                              captureVertDirStitch[2];        
    VfxU32                              captureVertDirBack[2];        
    
    // clip process
    VfxU32                              clipHorzDirBar[2];
    VfxU32                              clipVertDirBar[2];    
    VfxU32                              clipBg[2];    
    
}vapp_autocap_osd_skin;

#if( (GDI_LCD_WIDTH == 320) && (GDI_LCD_HEIGHT == 480) )
#define VAPP_AUTOCAP_OSD_LAYOUT_HVGA
#elif( (GDI_LCD_WIDTH == 480) && (GDI_LCD_HEIGHT == 800) )
#define VAPP_AUTOCAP_OSD_LAYOUT_WVGA
#elif( (GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 400) )
#define VAPP_AUTOCAP_OSD_LAYOUT_WQVGA
#elif( (GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 320) )
#define VAPP_AUTOCAP_OSD_LAYOUT_QVGA
#else
#define VAPP_AUTOCAP_OSD_LAYOUT_HVGA
#endif

#endif
#endif
