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
 *   jma_internal.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements JMA internal header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/**
 * @(#)  jma_internal.h    1.00 05/11/28
 *
 * Copyright (c) 2003 Institute for Information Industry.  All rights reserved.
 */

#ifndef _JMA_INTERNAL_H_
#define _JMA_INTERNAL_H_

/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "mmi_frm_gprot.h"

/* JAVA */
#include "jal.h"
#include "jal_internal.h"
#include "jvm_adaptor.h"
#include "jam_mvm_manager.h"
#include "jam_msg_handler.h"
#include "jvm_def.h"

/* GDI */
#include "gdi_include.h" 

/* MDI */
#include "mdi_datatype.h"
#include "mdi_video.h"  
#include "mdi_audio.h"
#include "mdi_camera.h"
#include "mdi_include.h"

/* DRM */
#include "drm_def.h"

/* cosmos memory */
#include "mmi_frm_mem_gprot.h"

#if !defined(__MTK_TARGET__)
#include <stdio.h>
#include <stdarg.h>
#endif /* !defined(__MTK_TARGET__) */ 

#include "JavaAgencyDef.h" /* GRP_ID_JAVA_APP */
/*************************************************************************
 * Define
 ************************************************************************/
#ifdef __COSMOS_MMI_PACKAGE__
#define JAVA_APP_ID_PLUTO (GRP_ID_JAVA_APP)
#define JAVA_APP_ID_COSMOS (VAPP_JAVA_TEXTBOX)
#define JAVA_APP_ID_MED (ASM_ANONYMOUS_ID)
#else
#define JAVA_APP_ID_PLUTO (0) 
#define JAVA_APP_ID_COSMOS (0)
#define JAVA_APP_ID_MED (0)
#endif /* __COSMOS_MMI_PACKAGE__ */

//#ifdef __COSMOS_MMI_PACKAGE__
#define VDOPLY_BUFFER_DEPTH         (2) /* RGB565 = 16 bits */
#define JMA_VDOPLY_LAYER_BUFFER_SIZE    (LCD_WIDTH*LCD_HEIGHT*VDOPLY_BUFFER_DEPTH)
//#endif /* __COSMOS_MMI_PACKAGE__ */

#define jma_app_id(vm_id) jma_video_get_active_app_id(vm_id)

#if !defined(J2ME_SLIM_MEMORY_SUPPORT) || !defined(__COSMOS_MMI_PACKAGE__)
#define __JMA_PREEMPT_PLAYER__
#endif

#ifdef SUPPORT_MMAPI
#ifndef JSR135_AUDIO_BASIC_FEATURE
#define JSR135_AUDIO_BASIC_FEATURE
#endif
#ifndef JSR135_AUDIO_ADVANCED_FEATURE
#define JSR135_AUDIO_ADVANCED_FEATURE
#endif
#endif
#define DEFAULT_AUDIO_VOLUME                    (100)
#define DEFAULT_VIDEO_VOLUME                    (100)

#define MAX_MIDI_PLAYER         (4)
#define MAX_TONE_PLAYER         (3)

#define MAX_AUDIO_RECORDER      (1)
#define MAX_VIDEO_RECORDER      (1)

#define J2ME_PATH_BUFFER_SIZE   (512)

#define MMA_TIMER_OFFSET   0x1000
#define INVALID_NPLAYER_ID    (-1)
#define INVALID_JVM_ID        (INVALIDE_VM_ID)
#define INVALID_JPLAYER_ID    (-1)
#define INVALID_RECORDER_ID   (-1)
#define INVALID_MMA_TYPE      (-1)
#define MAX_MIDI_CHANNEL 16

#define JVM_RUNNING_NUM_1       (1)
#define INVALID_JAVA_PLAYER     (-1)

#define DYNPLAYER_CS_ENTER()  kal_take_mutex(g_jam_dynamic_player_mutex)
#define DYNPLAYER_CS_LEAVE()  kal_give_mutex(g_jam_dynamic_player_mutex)

/* protect jma_media_enable and jma_audio_enable */
#define PARAM_CS_ENTER()  kal_take_mutex(g_jam_param_mutex) 
#define PARAM_CS_LEAVE()  kal_give_mutex(g_jam_param_mutex)

#define JMA_VOID
#define JMA_AUDIO_CS_ENTER(vm_id, return_value)                    \
    do                                                      \
    {                                                       \
        if(!jma_mvm_media_player_cs_check_and_enter(vm_id, KAL_TRUE))  \
        {                                                   \
            return return_value;                            \
        }                                                   \
    } while (0)

#define JMA_CS_ENTER(vm_id, return_value)                          \
    do                                                      \
    {                                                       \
        if(!jma_mvm_media_player_cs_check_and_enter(vm_id, KAL_FALSE)) \
        {                                                   \
            return return_value;                            \
        }                                                   \
    } while (0)
    
#define JMA_CS_LEAVE(return_value)      \
    do                                  \
    {                                   \
        jma_media_player_cs_leave();    \
        return return_value;            \
    } while (0)


/* preview rotation */
#if defined(SENSOR_ON_BODY)
    #if defined(SENSOR_ROTATE_0)
        #define J2ME_PREVIEW_MAINLCD_ROTATE MDI_CAMERA_PREVIEW_ROTATE_0
    #elif defined(SENSOR_ROTATE_180)
        #define J2ME_PREVIEW_MAINLCD_ROTATE MDI_CAMERA_PREVIEW_ROTATE_180
    #else
            /* rotate 90, 270 not used yet */
        #define J2ME_PREVIEW_MAINLCD_ROTATE MDI_CAMERA_PREVIEW_ROTATE_0
    #endif
#elif defined(SENSOR_ON_COVER)
    #if defined(SENSOR_ROTATE_0)
        #define J2ME_PREVIEW_MAINLCD_ROTATE   MDI_CAMERA_PREVIEW_ROTATE_0
    #elif defined(SENSOR_ROTATE_180)
        #define J2ME_PREVIEW_MAINLCD_ROTATE   MDI_CAMERA_PREVIEW_ROTATE_180
    #else
            /* rotate 90, 270 not used yet */
        #define J2ME_PREVIEW_MAINLCD_ROTATE   MDI_CAMERA_PREVIEW_ROTATE_0
    #endif
#elif defined(SENSOR_INSIDE_CLAM)
    #if defined(SENSOR_ROTATE_0)
        #define J2ME_PREVIEW_MAINLCD_ROTATE   MDI_CAMERA_PREVIEW_ROTATE_180
    #elif defined(SENSOR_ROTATE_180)
        #define J2ME_PREVIEW_MAINLCD_ROTATE   MDI_CAMERA_PREVIEW_ROTATE_0
    #else
            /* rotate 90, 270 not used yet */
        #define J2ME_PREVIEW_MAINLCD_ROTATE   MDI_CAMERA_PREVIEW_ROTATE_0
    #endif    
#else /* not define SENSOR_LCATION */
    #if defined(SENSOR_ROTATE_0)
        #define J2ME_PREVIEW_MAINLCD_ROTATE   MDI_CAMERA_PREVIEW_ROTATE_0
    #elif defined(SENSOR_ROTATE_180)
        #define J2ME_PREVIEW_MAINLCD_ROTATE   MDI_CAMERA_PREVIEW_ROTATE_180
    #else
            /* rotate 90, 270 not used yet */
        #define J2ME_PREVIEW_MAINLCD_ROTATE   MDI_CAMERA_PREVIEW_ROTATE_0
    #endif				
#endif /* SENSOR_LOCATION */	


/*************************************************************************
 * Typedef Enum  
 ************************************************************************/


typedef enum
{
    JAVA_DRM_STATE_NORMAL_FILE = -1,     /* -1 */ /* Not DRM file */
    JAVA_DRM_STATE_NULL,                 /* 0 */ 
    JAVA_DRM_STATE_PERMITTED,            /* 1 */ 
    JAVA_DRM_STATE_CONSUMING,            /* 2 */
    JAVA_DRM_STATE_PAUSED,               /* 3 */
    JAVA_DRM_STATE_EXPIRED               /* 4 */
} java_drm_state_enum;

typedef enum
{
    JAVA_MED_DEVICE_NONACTIVE,
    JAVA_MED_DEVICE_ACTIVE
} java_med_device_status;


typedef enum
{
    JAVA_MEDIA_TIMER_AUDIO_PDL_PLAYER = 0,  /* 0 */
    JAVA_MEDIA_TIMER_AUDIO_RECORDER,    /* 1 */
    JAVA_MEDIA_TIMER_VIDEO_RECORDER = JAVA_MEDIA_TIMER_AUDIO_RECORDER + JVM_NUM,
    JAVA_MEDIA_TIMER_STREAM_PLAYER  = JAVA_MEDIA_TIMER_VIDEO_RECORDER + JVM_NUM,
    JAVA_MEDIA_TIMER_PDL_PLAYER     = JAVA_MEDIA_TIMER_STREAM_PLAYER + JVM_NUM,
    JAVA_MEDIA_TIMER_ANIMA_PLAYER   = JAVA_MEDIA_TIMER_PDL_PLAYER + JVM_NUM,
    JAVA_MEDIA_TIMER_ANIMA_PARSE_INFO = JAVA_MEDIA_TIMER_ANIMA_PLAYER + JVM_NUM
} java_media_timer_type;

typedef enum
{
    JAVA_AUDIO_IMY = 0, /* 0 */
    JAVA_AUDIO_TONE_1,  /* 1 */
    JAVA_AUDIO_TONE_2,  /* 2 */
    JAVA_AUDIO_TONE_3,  /* 3 */
    JAVA_AUDIO_WAV_1,  /* 4 */
    JAVA_AUDIO_WAV_2,   /* 5 */
    JAVA_AUDIO_WAV_3,   /* 6 */
    JAVA_AUDIO_WAV_4,   /* 7 */
    JAVA_AUDIO_MIDI_1,  /* 8 */
    JAVA_AUDIO_MIDI_2,  /* 9 */
    JAVA_AUDIO_MIDI_3,  /* 10 */
    JAVA_AUDIO_MIDI_4,  /* 11 */
    JAVA_AUDIO_SINGLE,  /* 12 */
    JAVA_NO_OF_PLAYER   /* 13 */
} java_audio_index_enum;

typedef enum
{  
    JAVA_MEDIA_TONE_DEVICE,
    JAVA_MEDIA_TONESEQ_DEVICE,
    JAVA_MEDIA_MIDI_DEVICE,
    JAVA_MEDIA_WAV_DEVICE,
    JAVA_MEDIA_IMY_DEVICE,     
    JAVA_MEDIA_SINGLE_DEVICE,    /* 5 */
    JAVA_MEDIA_AUDIO_RECORDER,
    JAVA_MEDIA_CAM_PLAYER_DEVICE,
    JAVA_MEDIA_MPEG_PLAYER_DEVICE,  
    JAVA_MEDIA_MPEG_RECORDER_DEVICE, 
    JAVA_MEDIA_STREAM_PLAYER_DEVICE,   /* 10 */ 
    JAVA_MEDIA_ANIMA_PLAYER_DEVICE,
    JAVA_MEDIA_INVALID_DEVICE
} java_media_device_enum;

typedef enum
{
    JMA_FORCE_BLT,
    JMA_FORCE_NO_BLT,
    JMA_BLT_DEPEND
} java_video_blt_param;

typedef enum
{
    JMA_AUDIO_PREEMPT_NONE = 0,         /* do not needs to preempt others */
    JMA_AUDIO_PREEMPT_SINGLE_PLAYER,    /* preempt single player */
    JMA_AUDIO_PREEMPT_MULTI_PLAYER,     /* preempt multiple players */
    JMA_AUDIO_PREEMPT_PLAYER,           /* preempt the player which take the specific resource */
    JMA_AUDIO_PREEMPT_NOT_RERMITED,     /* FG VM can not preempt itself */
    
    JMA_AUDIO_PREEMPT_TOTAL
}jma_audio_preemption_type;

typedef enum
{
    JMA_AUDIO_RESUME_NONE = 0,          /* there is no player needs to be resumed */
    JMA_AUDIO_RESUME_SINGLE_PLAYER,     /* resume sigle player */
    JMA_AUDIO_RESUME_MULTI_PLAYER,      /* resume multiple players */

    JMA_AUDIO_RESUME_TOTAL
}jma_audio_resume_type;

typedef enum
{
    JMA_AUDIO_ACTIVE,           /* VM'S player is active */
    JMA_AUDIO_NON_ACTIVE,       /* Non of VM's multi-player is active */
    JMA_AUDIO_ALL_NON_ACTIVE,   /* Non of the players active */

    JMA_AUDIO_STATE_TOTAL
}jma_audio_state;

/*************************************************************************
 * Typedef struct  
 ************************************************************************/
typedef struct dynamic_player_node_t
{
    struct dynamic_player_node_t *next;
    struct dynamic_player_node_t *prev;
    kal_bool flag_on_list;
} mma_player_node;

typedef struct dynamic_player_list_t
{
    mma_player_node *head;
    kal_uint32 player_count;
} mma_player_list;

typedef struct audio_player_struct_t
{
    mma_player_node next_node;
    kal_int32 vm_id;
    kal_int32 id; /* Java layer player id */
    kal_uint32 aud_id;  
    kal_uint32 sequence_id; 
    kal_int32 cache_handle;
    kal_int32 pitch;
    kal_int32 rate;
    kal_int32 tempo;
    kal_int32 channel;
    kal_int32 program;
    kal_int32 bank;

    /* Native information */
    kal_int32 handle;

    kal_int32 stoptime;          /* Saved stoptime if have */
    kal_int32 duration;
    kal_int32 current_time;
    kal_int32 play_finish_time;

    kal_int16 play_speed;
    kal_uint16 channel_volume_sets;
    kal_uint8 channel_volume[MAX_MIDI_CHANNEL];
    
    /* For Audio File Player: DRM */
    kal_int32 drm_id;
    java_drm_state_enum drm_state;
    
    kal_bool support_time_stretch;
    kal_bool is_eom;
    /* byte fields */
    kal_bool is_midi_device;      /* Open MIDI device for file or MIDIControl */
    kal_bool is_setpitch;
    kal_bool is_setprogram;
    kal_bool is_setrate;
    kal_bool is_settempo;
    
    java_media_device_enum device_type;
    java_media_state_enum state;
    kal_uint8 volume;

    mma_player_struct player;
} audio_player_struct;

#ifdef SUPPORT_MMAPI
typedef struct 
{
    kal_bool set_display_location;
    kal_bool set_display_size;
    kal_bool is_full_screen;
    kal_bool fullscreen_rotate;
    kal_bool is_visible;
    kal_int32 offset_x;
    kal_int32 offset_y;
    kal_int32 width;
    kal_int32 height;  
    /* Actual region */
    kal_int32 region_x;
    kal_int32 region_y;
    kal_int32 region_width;
    kal_int32 region_height;
}video_ctrl_struct;


typedef struct 
{
    kal_uint32 delay_time;
    kal_uint32 current_frame;
    kal_uint32 start_tick;
    kal_uint32 current_tick;

    /* For the mapping between time and frame */
    kal_uint32 frame_number; 

    /* IMPORTANT: The type MUST syncronize with the unit size of jvm_malloc() */
    kal_uint32 *time_index;
    kal_uint32 time_index_length;
} anima_info_struct;


typedef struct video_player_struct_t
{
    kal_int64 duration;
    kal_int64 stoptime;
    kal_uint64 current_time;
    kal_int64 record_size_limit; /* Video Record size limit */
    kal_uint64 play_finish_time;         /* For streaming player */    
    kal_int32 id; //java_player_id
    kal_uint32 buffer_length;
    kal_int32 video_width;
    kal_int32 video_height;
    kal_int32 cache_handle;
    kal_uint32 scr_mem_max_size;
    kal_uint8 *buffer;
    /* For Audio File Player: DRM */
    kal_int32 drm_id;
    java_drm_state_enum drm_state;
    
    java_media_device_enum device_type;
    java_media_state_enum prev_state;
    java_media_state_enum state;
    kal_uint8 volume;
    kal_bool progressive_dl;    /* Progressive download */
    
    kal_int16 play_speed;
    mdi_video_track_enum track; 
    
    mdi_video_stream_type_enum stream_type;
    kal_bool need_redraw; /* For animation player */
    kal_bool seek_error; /* For video player */
    kal_bool is_double_buffer;
    kal_bool is_stream_opened;    /* For streaming player */
    kal_bool is_seekable;         /* For streaming player */
    kal_bool is_play_requested;   /* For streaming player: set at play(), pause(), play_finish() */

    kal_wchar filename[J2ME_PATH_BUFFER_SIZE + 1];
    kal_wchar title_name[MDI_VIDEO_INFO_TITLE_CHAR_COUNT]; 
    /* For video player meta data */
    kal_char title_desc[MDI_VIDEO_CONTENT_BUFFER_SIZE];
    kal_char author_desc[MDI_VIDEO_CONTENT_BUFFER_SIZE];
    kal_char copyright_desc[MDI_VIDEO_CONTENT_BUFFER_SIZE];    
    kal_char date_desc[MDI_VIDEO_CONTENT_BUFFER_SIZE]; 
} video_player_struct;

#endif /* SUPPORT_MMAPI */ 

#ifdef JSR135_AUDIO_RECORDER
typedef struct audio_recorder_struct_t
{
    kal_int32 record_size_limit;
    kal_int32 id;
    kal_int32 current_time;
    stack_timer_struct *record_timer;
    kal_wchar filename[J2ME_PATH_BUFFER_SIZE + 1];
    java_media_state_enum state;
    med_type_enum format;
} audio_recorder_struct;

#endif /* SUPPORT_MMAPI */ 

/*************************************************************************
 * Extern Global Variable
 *************************************************************************/
extern kal_mutexid g_jam_dynamic_player_mutex;
extern kal_mutexid g_jam_media_mutex;
extern kal_mutexid g_jam_param_mutex;
extern kal_bool jma_audio_enable;
extern kal_bool jma_media_enable[JVM_NUM];
extern kal_bool is_vm_suspend_audio;
extern kal_bool is_vm_suspend_media[JVM_NUM];
extern kal_bool is_video_suspend_audio;

extern kal_bool is_med_suspend_audio;
extern module_type jma_mimic_module_id;

#ifdef SUPPORT_MMAPI
extern video_ctrl_struct video_ctrl_info[JVM_NUM];
extern video_player_struct video_player[JVM_NUM];
extern anima_info_struct anima_info[JVM_NUM];
extern kal_uint32 preview_layer_flag;
extern kal_uint32 blt_layer_flag;
extern kal_uint16 *preview_buf_ptr;
extern GDI_HANDLE preview_layer_handle;
extern kal_int32 preview_buf_size;
#endif /* SUPPORT_MMAPI */ 
extern stack_timer_struct java_media_timer;

/*************************************************************************
 * Extern Global Function
 *************************************************************************/
/* Resource Switch */
extern void jma_media_player_clear_parameter(kal_bool is_init);
extern void jma_media_player_vm_notfy_suspend(kal_int32 vm_id);
extern void jma_media_player_vm_notfy_resume(kal_int32 vm_id);
extern void jma_media_player_vm_notfy_terminate(kal_int32 vm_id);
extern void jma_audio_player_vm_notify_suspend(void);
extern void jma_audio_player_vm_notify_resume(void);
extern kal_bool jma_audio_player_is_mdi_audio_usable(void);
#ifdef __JMA_PREEMPT_PLAYER__
extern void jma_video_notify_suspend_audio_player(kal_int32 vm_id);
extern void jma_video_notify_resume_audio_player(kal_int32 vm_id);
#endif
extern kal_bool jma_mvm_audio_resume_vm_players(kal_int32 vm_id);
extern void jma_audio_player_do_terminate_job(jvm_state_enum src_state, kal_int32 vm_id);
extern void jma_audio_player_interrupt_callback(MDI_RESULT result, void *user_data);
extern BOOL jma_audio_player_background_callback(MDI_RESULT result, void *user_data);
extern void jma_media_player_check_critical_section(void);
extern void jma_media_player_leave_critical_section(void);
#ifdef SUPPORT_JSR_135_VIDEO
extern void jma_media_player_exit_screen_hdlr(kal_int32 vm_id);
extern void jma_media_player_entry_screen_hdlr(kal_int32 vm_id);
#endif
extern kal_bool jma_mutex_lock_no_wait(kal_bool wait_gdi_lock);
extern void jma_media_player_dependency_mutex_unlock(void);

extern jma_audio_state jma_mvm_audio_player_state(kal_int32 vm_id);
#ifdef __JMA_PREEMPT_PLAYER__
extern kal_bool jma_mvm_audio_player_preempt_players(kal_int32 vm_id, kal_int32 mma_type, kal_char *filename);
extern kal_bool jma_mvm_audio_player_resume_preempted_players(kal_int32 vm_id, kal_int32 jplayer, kal_int32 mma_type, kal_bool is_single_over);
extern kal_bool jma_audio_player_vm_resume_preempted_players(kal_int32 vm_id);
extern void jma_mvm_audio_player_remove_preempted_nodes(kal_int32 vm_id);
extern kal_uint32 jma_mvm_audio_player_get_preempted_player(void);
#endif

extern void jma_audio_player_register_callback(kal_int32 vm_id);
extern void jma_audio_player_clear_callback(kal_int32 vm_id);
extern void jma_reset_all_device(void);
extern void jma_register_device(
        kal_int32 device_type,
        kal_int32 vm_id,
        kal_int32 handle,
        kal_int32 (*suspend) (kal_int32 vm_id, kal_int32 handle),
        kal_int32 (*resume) (kal_int32 vm_id, kal_int32 handle),
        kal_int32 (*close) (kal_int32 vm_id, kal_int32 handle));
extern void jma_deregister_device(kal_int32 device_type, kal_int32 vm_id, kal_int32 handle);

extern kal_bool jma_audio_is_vm_players_active(kal_int32 vm_id);
extern kal_bool jma_audio_player_is_single_player(kal_int32 mma_type);
extern kal_int32 jma_audio_suspend_hdlr(kal_int32 vm_id, kal_int32 jplayer);
extern kal_int32 jma_audio_resume_hdlr(kal_int32 vm_id, kal_int32 jplayer);
extern kal_int32 jma_audio_close_hdlr(kal_int32 vm_id, kal_int32 jplayer);
extern void jma_audio_event_hdlr(kal_int32 handle, med_result_enum event);
extern void jma_audio_player_reset_parameter(void);
extern void jma_midi_player_deinit(void);

extern void jma_audio_player_message_hdlr(ilm_struct *ilm_ptr);

extern kal_bool jma_audio_player_cache_buffering_cyclic(void);

#ifdef JSR135_AUDIO_ADVANCED_FEATURE
extern kal_bool jma_transfer_mdi_message_hdlr(ilm_struct *ilm_ptr);
#endif

#ifdef JSR135_AUDIO_RECORDER
extern kal_int32 jma_audio_recorder_resume_hdlr(kal_int32 vm_id, kal_int32 java_recorder);
extern kal_int32 jma_audio_recorder_suspend_hdlr(kal_int32 vm_id, kal_int32 java_recorder);
extern kal_int32 jma_audio_recorder_close_hdlr(kal_int32 vm_id, kal_int32 java_recorder);
extern kal_bool jma_audio_recorder_is_really_active(kal_int32 vm_id);
extern void jma_audio_recorder_reset_parameter(kal_int32 vm_id);
extern void jma_audio_recorder_timer_expired(kal_int32 vm_id);
#endif

#ifdef SUPPORT_MMAPI
extern kal_uint16 jma_video_get_active_app_id(kal_int32 vm_id);
extern void jma_video_free_preveiw_layer_buffer(kal_int32 vm_id);
extern void jma_video_player_reset_parameter(kal_int32 vm_id);
extern void jma_video_player_update_is_title_displayed(kal_int32 vm_id, kal_bool is_title_displayed);
extern void jma_video_player_reconfig_layer(kal_int32 vm_id);
extern void jma_video_player_refine_display_info(kal_int32 vm_id);
extern kal_bool jma_video_player_process_layer(kal_int32 vm_id);
extern kal_bool jma_video_player_update_blt_flag(kal_int32 vm_id, java_video_blt_param blt_param);

extern kal_int32 jma_anima_player_suspend_hdlr(kal_int32 vm_id, kal_int32 java_player);
extern kal_int32 jma_anima_player_resume_hdlr(kal_int32 vm_id, kal_int32 java_player);
extern kal_int32 jma_anima_player_close_hdlr(kal_int32 vm_id, kal_int32 java_player);
extern void jma_anima_player_check_stop_time_cyclic(kal_int32 vm_id);
extern void jma_anima_player_draw_frame_cyclic(kal_int32 vm_id);
extern kal_bool jma_anima_player_refresh(kal_int32 vm_id, kal_int32 java_player);
extern kal_bool jma_anima_player_parse_info_cyclic(kal_int32 vm_id);

#if defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_CAMERA__) || defined(__MMI_CAMCORDER__))
extern kal_int32 jma_cam_player_suspend_hdlr(kal_int32 vm_id, kal_int32 java_player);
extern kal_int32 jma_cam_player_resume_hdlr(kal_int32 vm_id, kal_int32 java_player);
extern kal_int32 jma_cam_player_close_hdlr(kal_int32 vm_id, kal_int32 java_player);
extern kal_bool jma_cam_player_refresh(kal_int32 vm_id, kal_int32 java_player);
extern kal_bool jma_cam_player_preview_stop_keep_layer(kal_int32 vm_id); /* Do not free the layer */
#endif /* defined (SUPPORT_JSR_135_VIDEO) && defined(__MMI_CAMERA__) */

#if defined (SUPPORT_JSR_135_VIDEO) && (defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__))
extern kal_int32 jma_video_recorder_suspend_hdlr(kal_int32 vm_id, kal_int32 java_player);
extern kal_int32 jma_video_recorder_resume_hdlr(kal_int32 vm_id, kal_int32 java_player);
extern kal_int32 jma_video_recorder_close_hdlr(kal_int32 vm_id, kal_int32 java_player);
extern void jma_video_recorder_timer_expired(kal_int32 vm_id);
extern kal_bool jma_video_recorder_refresh(kal_int32 vm_id, kal_int32 java_player);
extern void jma_video_recorder_refresh_pause(kal_int32 vm_id);
extern void jma_video_recorder_refresh_resume(kal_int32 vm_id);
extern void jma_video_recorder_get_default_record_size(U16 video_size, kal_int32 * width, kal_int32 * height);
extern void jma_video_recorder_adjust_record_size(kal_int32 * width, kal_int32 * height);
#endif /* defined (SUPPORT_JSR_135_VIDEO) && defined(__MMI_VIDEO_RECORDER__) */

#if defined (SUPPORT_JSR_135_VIDEO) && defined(__MMI_VIDEO_PLAY_SUPPORT__)
extern kal_int32 jma_video_player_suspend_hdlr(kal_int32 vm_id, kal_int32 java_player);
extern kal_int32 jma_video_player_resume_hdlr(kal_int32 vm_id, kal_int32 java_player);
extern kal_int32 jma_video_player_close_hdlr(kal_int32 vm_id, kal_int32 java_player);
#ifdef __MMI_VIDEO_STREAM__
extern kal_int32 jma_stream_player_suspend_hdlr(kal_int32 vm_id, kal_int32 java_player);
extern kal_int32 jma_stream_player_resume_hdlr(kal_int32 vm_id, kal_int32 java_player);
extern kal_int32 jma_stream_player_close_hdlr(kal_int32 vm_id, kal_int32 java_player);
extern void jma_stream_player_buffering_cyclic(kal_int32 vm_id);
extern void jma_stream_player_process_bearer_event(ilm_struct * ilm_ptr);
#endif /* __MMI_VIDEO_STREAM__ */

#ifdef __MMI_VIDEO_PDL__ 
extern kal_bool jma_video_player_cache_buffering_cyclic(kal_int32 vm_id);
#endif /* __MMI_VIDEO_PDL__ */

#endif  /* defined (SUPPORT_JSR_135_VIDEO) && defined(__MMI_VIDEO_PLAY_SUPPORT__) */
#endif /* SUPPORT_MMAPI */

#endif /* _JMA_INTERNAL_H_ */ 

