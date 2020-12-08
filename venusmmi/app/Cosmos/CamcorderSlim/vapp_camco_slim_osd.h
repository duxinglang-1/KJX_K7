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

#ifndef __VAPP_CAMCO_SLIM_OSD__
#define __VAPP_CAMCO_SLIM_OSD__

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "mdi_camera.h"
#include "mdi_video.h"
#include "MMI_include.h"
#include "mmi_features_camcorder.h"
#include "vapp_camco_slim_setting_item.h"

#ifdef __VAPP_CAMCO_SLIM__

#define VAPP_CAMCO_PREVIEW_SETTING_LIST_ITEM_COUNT  (9)
#define VAPP_CAMCO_SUPPORT_FACE_NUM                 (MDI_CAMERA_FD_MAX_NO)

#if defined(__MMI_CAMCO_FEATURE_CAM_BURSTSHOT_SELECT__) || defined(__MMI_CAMCO_FEATURE_CAM_AEBSHOT_SELECT__)
    #if (MMI_CAMCO_FEATURE_CAM_BURSTSHOT_IMAGE_COUNT > MMI_CAMCO_FEATURE_CAM_AEBSHOT_IMAGE_COUNT)
        #define MMI_CAMCO_OSD_MULTI_SHOT_COUNT          (MMI_CAMCO_FEATURE_CAM_BURSTSHOT_IMAGE_COUNT)
    #else
        #define MMI_CAMCO_OSD_MULTI_SHOT_COUNT          (MMI_CAMCO_FEATURE_CAM_AEBSHOT_IMAGE_COUNT)
    #endif
#else
    #define MMI_CAMCO_OSD_MULTI_SHOT_COUNT          (1)
#endif

typedef enum
{

    VAPP_CAMCO_OSD_SETTING_NONE,
    VAPP_CAMCO_OSD_SETTING_COMMON_ONLY,
    VAPP_CAMCO_OSD_SETTING_FULL,
    VAPP_CAMCO_OSD_SETTING_END

}vapp_camco_osd_level_enum;

typedef enum
{
    VAPP_CAMCO_OSD_STATE_HIDE,
    VAPP_CAMCO_OSD_STATE_HINT,
    VAPP_CAMCO_OSD_STATE_CAMERA_PREVIEW,
    VAPP_CAMCO_OSD_STATE_VIDEO_PREVIEW,
    VAPP_CAMCO_OSD_STATE_VIDEO_RECORDING,
    VAPP_CAMCO_OSD_STATE_VIDEO_PAUSE,
    VAPP_CAMCO_OSD_STATE_QUICK_VIEW,

    VAPP_CAMCO_OSD_STATE_EXIT,

    VAPP_CAMCO_OSD_STATE_END
} vapp_camco_osd_state_enum;

typedef enum
{
    VAPP_CAMCO_OSD_STATE_STATUS_NORMAL = 0,
    VAPP_CAMCO_OSD_STATE_STATUS_INACTIVE,
    VAPP_CAMCO_OSD_STATE_STATUS_ISAPPBUSY,
    VAPP_CAMCO_OSD_STATE_STATUS_ISOSDBUSY,
    VAPP_CAMCO_OSD_STATE_STATUS_ISPENPROCESSING,
    VAPP_CAMCO_OSD_STATE_STATUS_ISKEYPROCESSING,
    VAPP_CAMCO_OSD_STATE_STATUS_ISANIMATING,

    VAPP_CAMCO_OSD_STATE_STATUS_END
} vapp_camco_osd_state_status_enum;

typedef enum
{
    // need to restart preview
    VAPP_CAMCO_EVT_RESTART_PREVIEW,         /* 0 */

    // preview btn event
    VAPP_CAMCO_EVT_ENTER_GALLERY,           /* 1 */
    VAPP_CAMCO_EVT_CAPTURE,                 /* 2 */
    VAPP_CAMCO_EVT_RECORD,                  /* 3 */
    VAPP_CAMCO_EVT_SWITCH_SENSOR,           /* 4 */
    VAPP_CAMCO_EVT_SWITCH_APP,              /* 5 */

    // single shot quick view animate finish eveny
    VAPP_CAMCO_EVT_VIEW_STOP,               /* 6 */

    // recording event
    VAPP_CAMCO_EVT_REC_STOP,                /* 7 */
    VAPP_CAMCO_EVT_REC_STOP_EXIT,           /* 8 */
    VAPP_CAMCO_EVT_REC_PAUSE,               /* 9 */
    VAPP_CAMCO_EVT_REC_RESUME,              /* 10 */

    // focus key press event
    VAPP_CAMCO_EVT_FOCUS,                   /* 11 */
    VAPP_CAMCO_EVT_FOCUS_STOP,              /* 12 */

    VAPP_CAMCO_EVT_BG_CAL_START,            /* 13 */
    VAPP_CAMCO_EVT_BG_CAL_STOP,             /* 14 */

    // smile detect event
    VAPP_CAMCO_EVT_SD_START,                /* 15 */
    VAPP_CAMCO_EVT_SD_STOP,                 /* 16 */

    // notify popup event
    VAPP_CAMCO_EVT_BACK,                    /* 17 */

    // confirm popup event
    VAPP_CAMCO_EVT_OK,                      /* 18 */
    VAPP_CAMCO_EVT_CANCEL,                  /* 19 */

    // auto exit timeout event
    VAPP_CAMCO_EVT_AUTO_EXIT,               /* 20 */
    //----------------------------------
    VAPP_CAMCO_EVT_END
} mmi_cameco_evt_type_enum;

typedef enum
{
    VAPP_CAMCO_DRAW_IMG_SRC_BUFF,
    VAPP_CAMCO_DRAW_IMG_SRC_JPEG,
    VAPP_CAMCO_DRAW_IMG_SRC_FILE,
    VAPP_CAMCO_DRAW_IMG_SRC_COLOR,
    VAPP_CAMCO_DRAW_IMG_SRC_END

}vapp_camco_osd_draw_image_src_enum;

typedef enum
{
    VAPP_CAMCO_OSD_SETTING_MODE_SLIDER,
    VAPP_CAMCO_OSD_SETTING_MODE_MULTI_SLIDER,
    VAPP_CAMCO_OSD_SETTING_MODE_ROTATOR,
    VAPP_CAMCO_OSD_SETTING_MODE_MENU,
    VAPP_CAMCO_OSD_SETTING_MODE_END

}vapp_camco_osd_setting_mode_enum;

typedef enum
{
    VAPP_CAMCO_OSD_FOCUS_REGION_1,
    VAPP_CAMCO_OSD_FOCUS_REGION_2,
    VAPP_CAMCO_OSD_FOCUS_REGION_3,
    VAPP_CAMCO_OSD_FOCUS_REGION_4,
    VAPP_CAMCO_OSD_FOCUS_REGION_5,

    VAPP_CAMCO_OSD_FOCUS_REGION_END
} vapp_camco_osd_focus_region_enum;

typedef enum
{
    VAPP_CAMCO_OSD_FOCUS_TYPE_NULL,
    VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSING,
    VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSED,
    VAPP_CAMCO_OSD_FOCUS_TYPE_FOCUSING_FAIL,
    VAPP_CAMCO_OSD_FOCUS_TYPE_MACRO,

    VAPP_CAMCO_OSD_FOCUS_TYPE_END
} vapp_camco_osd_focus_type_enum;

typedef enum
{
    VAPP_CAMCO_OSD_FACEDETECT_TYPE_NULL,
    VAPP_CAMCO_OSD_FACEDETECT_TYPE_TRACKING,
    VAPP_CAMCO_OSD_FACEDETECT_TYPE_FOCUSED,

    VAPP_CAMCO_OSD_FACEDETECT_TYPE_END
} vapp_camco_osd_facedetect_type_enum;

typedef enum
{
    VAPP_CAMCO_OSD_HINT_EVT_CAM_COUNT_DOWN,
    VAPP_CAMCO_OSD_HINT_EVT_CAM_NO_CARD,
    VAPP_CAMCO_OSD_HINT_EVT_REC_NO_CARD,
    VAPP_CAMCO_OSD_HINT_EVT_ERROR,
    VAPP_CAMCO_OSD_HINT_EVT_OTHERS,

    VAPP_CAMCO_OSD_HINT_EVT_END

} vapp_camco_osd_hint_event_enum;

typedef enum
{
    VAPP_CAMCO_OSD_HINT_TYPE_PROCESSING,
    VAPP_CAMCO_OSD_HINT_TYPE_HINT,
    VAPP_CAMCO_OSD_HINT_TYPE_HINT_TEXT,
    VAPP_CAMCO_OSD_HINT_TYPE_HINT_ICON,
    VAPP_CAMCO_OSD_HINT_TYPE_CONFIRM,
    VAPP_CAMCO_OSD_HINT_TYPE_NOTIFY,
    VAPP_CAMCO_OSD_HINT_TYPE_NONE,

    VAPP_CAMCO_OSD_HINT_TYPE_END

} vapp_camco_osd_hint_type_enum;

typedef enum
{
    VAPP_CAMCO_OSD_QV_EVT_NORMAL_SHOT,
    VAPP_CAMCO_OSD_QV_EVT_RECORD,

    VAPP_CAMCO_OSD_QV_EVT_END

} vapp_camco_osd_quick_view_event_enum;

typedef enum
{
    VAPP_CAMCO_OSD_SCR_PARAM_SET_FD,
    VAPP_CAMCO_OSD_SCR_PARAM_SET_SD,
    VAPP_CAMCO_OSD_SCR_PARAM_SET_FOCUS,

    VAPP_CAMCO_OSD_SCR_PARAM_RESET_FD,
    VAPP_CAMCO_OSD_SCR_PARAM_RESET_SD,
    VAPP_CAMCO_OSD_SCR_PARAM_RESET_FOCUS,

    VAPP_CAMCO_OSD_SCR_PARAM_SCN_UPDATE,

    VAPP_CAMCO_OSD_SCR_PARAM_ZOOM_UPDATE,

    VAPP_CAMCO_OSD_SCR_PARAM_RECORDING_UPDATE,

    VAPP_CAMCO_OSD_SCR_PARAM_CAM_REMAIN_SIZE_UPDATE,
    VAPP_CAMCO_OSD_SCR_PARAM_REC_REMAIN_SIZE_UPDATE,

    VAPP_CAMCO_OSD_SCR_PARAM_CAM_THUMBNAIL_UPDATE,
    VAPP_CAMCO_OSD_SCR_PARAM_REC_THUMBNAIL_UPDATE,

    VAPP_CAMCO_OSD_SCR_PARAM_IND_MSG_UPDATE,

    VAPP_CAMCO_OSD_SCR_PARAM_SET_BUSY,

    VAPP_CAMCO_OSD_SCR_PARAM_SET_ROT,

    VAPP_CAMCO_OSD_SCR_PARAM_END

} vapp_camco_osd_scr_param_enum;

typedef struct
{
    vapp_camco_osd_draw_image_src_enum      drawingType;
    // pure color case
    VfxColor                                bgColor;
    // fill from file case
    WCHAR                                  *srcFileName;
    // fill from mem case
    void*                                   srcBuffAdress;
    VfxU32                                  srcWidth;
    VfxU32                                  srcHeight;
    // fill from jpeg buffer case
    void*                                   srcJpgBuffAdress;
    void*                                   cacheBuffAdress;
    VfxU32                                  srcSize;
}vapp_camco_osd_draw_image_struct;

typedef struct
{
    S32                                     center_x;
    S32                                     center_y;
    S32                                     w;
    S32                                     h;
    vapp_camco_osd_focus_type_enum          type;

} vapp_camco_osd_focus_struct;

typedef struct
{
    S32                                     offset_x;
    S32                                     offset_y;
    MMI_ID_TYPE                             img_id;
    MMI_BOOL                                is_processing;
    MMI_BOOL                                is_hint_show;

} vapp_camco_osd_focus_hint_struct;

typedef struct
{
    S32                                     x;
    S32                                     y;
    S32                                     w;
    S32                                     h;
    vapp_camco_osd_facedetect_type_enum     type;

} vapp_camco_osd_facedetect_region_struct;

typedef struct
{
    S32                                     x;
    S32                                     y;
    S32                                     w;
    S32                                     h;
    vapp_camco_osd_facedetect_type_enum     type;

} vapp_camco_osd_smiledetect_region_struct;

typedef struct
{
    VfxBool                                 isCamera;
    VfxBool                                 isOSDHorz;
    VfxBool                                 isOSDMirror;
    VfxScrRotateTypeEnum                    scrnAngle;
    VfxBool                                 isExtCalling;

}vapp_camco_osd_starting_param_struct;

typedef struct
{
    VfxBool                                 isCleanBG;

}vapp_camco_osd_hide_param_struct;

typedef struct
{
    CamcoSettingMgr                        *setting;

    vapp_camco_osd_hint_event_enum          event;         //valid if need user interaction
    vapp_camco_osd_hint_type_enum           type;

    VfxWString                              hintText;
    VfxS32                                  hintIcon;
    VfxBool                                 isPreviewON;
    vapp_camco_osd_draw_image_struct        bgContent;

}vapp_camco_osd_hint_param_struct;

typedef struct
{
    CamcoSettingMgr                        *setting;

    VfxBool                                 isRestartEnter;

    VfxU32                                  capturableNumber;

    vapp_camco_osd_level_enum               settingLevel;

    WCHAR                                  *previousFileName;

    // for show previous video frame
    void                                   *buffer;

    MMI_ID                                  indicatorStringID;
}vapp_camco_osd_cam_preview_param_struct;

typedef struct
{
    CamcoSettingMgr                        *setting;

    VfxBool                                 isRestartEnter;

    VfxU32                                  recordableTime;

    vapp_camco_osd_level_enum               settingLevel;

    WCHAR                                  *previousFileName;

    // for show previous video frame
    void                                   *buffer;

    MMI_ID                                  indicatorStringID;
}vapp_camco_osd_rec_preview_param_struct;

typedef struct
{
    VfxBool                                 isPreviewHorz;
    VfxBool                                 isPreviewMirror;

    CamcoSettingMgr                        *setting;

}vapp_camco_osd_rec_recording_param_struct;

typedef struct
{
    VfxBool                                 isPreviewHorz;
    VfxBool                                 isPreviewMirror;

    CamcoSettingMgr                        *setting;
    VfxU32                                  recTime;
    VfxU32                                  recSize;

}vapp_camco_osd_rec_pause_param_struct;

typedef struct
{
    vapp_camco_osd_quick_view_event_enum    type;
    vapp_camco_osd_draw_image_struct        savedImg;

}vapp_camco_osd_quick_view_param_struct;

typedef struct
{
    VfxBool                                 isCamera;

}vapp_camco_osd_focuse_param_struct;

typedef struct
{
    VfxBool                                 isCamera;

}vapp_camco_osd_focuse_hint_param_struct;

typedef struct
{
    vapp_camco_osd_scr_param_enum               type;

    VfxU32 index;
    // set face detect result / smile detect result case
    vapp_camco_osd_facedetect_region_struct     fd;
    vapp_camco_osd_smiledetect_region_struct    sd;
    // set face detect result / auto focus result case
    vapp_camco_osd_focus_struct                 focus;

    // set currect rec time/size case
    VfxU64                                      rec_time;
    VfxU64                                      rec_size;

    // update zoom case
    VfxU32                                      zoom_value;

    // update remain size case
    VfxU32                                      remain_size;

    // update the thumbnaol
    WCHAR                                      *previousFileName;

    // update ind msg
    MMI_ID                                      indicator_string;

    // tell OSD, AP is busy cannot recv next instrution
    VfxBool                                     isBusy;

    // tell OSD current target rotation angle
    VfxBool                                     isHorz;
    VfxBool                                     isMirror;
}vapp_camco_osd_screen_param_struct;


typedef struct
{
    //all pos is set by center of icon / left center of text

    // settingBar:
    VfxU32                              settingBarSize[2];           // width,height on H screen
    VfxU32                              softkeyBarSize[2];           // width,height on H screen

    //circleControl:
    VfxU32                              directControlSize[2];        // width,height on H screen
    VfxU32                              menuControlSize[2];          // width,height on H screen

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
    VfxU32                              recordPos[2];                // x,y of record btn

    // left side btn
    VfxU32                              flashSettingPos[2];          // x,y of flash btn
    VfxU32                              advanceSettingPos[2];        // x,y of advance setting btn

    VfxU32                              remainNuminfoPos[2];         // x,y of remain capture Num info

    // record related:
    VfxU32                              recPausePos[2];              // x,y of record pause btn
    VfxU32                              recIndicatorPos[2];          // x,y of record indicator
    VfxU32                              recTimePos[2];               // x,y of record time text

}vapp_camco_osd_skin;

#if( (GDI_LCD_WIDTH == 320) && (GDI_LCD_HEIGHT == 480) )
#define VAPP_CAMCO_OSD_LAYOUT_HVGA
#elif( (GDI_LCD_WIDTH == 480) && (GDI_LCD_HEIGHT == 800) )
#define VAPP_CAMCO_OSD_LAYOUT_WVGA
#elif( (GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 400) )
#define VAPP_CAMCO_OSD_LAYOUT_WQVGA
#elif( (GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 320) )
#define VAPP_CAMCO_OSD_LAYOUT_QVGA
#else
#define VAPP_CAMCO_OSD_LAYOUT_HVGA
#endif

#endif /*__VAPP_CAMCO_SLIM__*/
#endif /*__VAPP_CAMCO_SLIM_OSD__*/
