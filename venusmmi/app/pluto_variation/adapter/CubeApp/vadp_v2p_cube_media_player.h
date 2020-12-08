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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vadp_v2p_cube_media_player.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 * Media Player Cube Screen
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_Features.h"

#ifdef __MMI_VUI_3D_CUBE_APP_MEDIA_PLAYER__

#ifndef __VADP_V2P_CUBE_MEDIA_PLAYER_H__
#define __VADP_V2P_CUBE_MEDIA_PLAYER_H__



#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

#include "ui_core\base\vfx_datatype.h"
#include "mmi_include.h"

#define VAPP_CUBE_MEDIA_PLAYER_STATE_INIT    (0)

#define VAPP_CUBE_MEDIA_PLAYER_STATE_PLAY    (1)

#define VAPP_CUBE_MEDIA_PLAYER_STATE_PROCESS (2)

#if 1
#if defined(__MMI_MAINLCD_240X320__) || \
    defined(__MMI_MAINLCD_240X400__) || \
    defined(__MMI_MAINLCD_320X480__)
#else
    #error "Venus Media Wall does not support this LCD resolution."
#endif
#endif


#ifdef __MMI_MAINLCD_240X320__
#define VAPP_CUBE_MEDPLY_S_COVER_W  47 
#define VAPP_CUBE_MEDPLY_S_COVER_H  48
#define VAPP_CUBE_MEDPLY_L_COVER_W  135
#define VAPP_CUBE_MEDPLY_L_COVER_H  137
#endif

#ifdef __MMI_MAINLCD_240X400__
#define VAPP_CUBE_MEDPLY_S_COVER_W 62
#define VAPP_CUBE_MEDPLY_S_COVER_H 64
#define VAPP_CUBE_MEDPLY_L_COVER_W 135
#define VAPP_CUBE_MEDPLY_L_COVER_H 137
#endif

#ifdef __MMI_MAINLCD_320X480__
#define VAPP_CUBE_MEDPLY_S_COVER_W 77
#define VAPP_CUBE_MEDPLY_S_COVER_H 79
#define VAPP_CUBE_MEDPLY_L_COVER_W 179
#define VAPP_CUBE_MEDPLY_L_COVER_H 181
#endif

/* @TODO: Yaling will remove it to  MediaCacheSrvGprot.h , delete later */
#define SRV_PLST_ARTWORK_RESIZED_WIDTH   150
#define SRV_PLST_ARTWORK_RESIZED_HEIGHT  150



#define VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM       9
#define VAPP_CUBE_MEDPLY_S_COVER_BUF_SIZE      (((VAPP_CUBE_MEDPLY_S_COVER_W * VAPP_CUBE_MEDPLY_S_COVER_H*2)/4 + 1)*4)
#define VAPP_CUBE_MEDPLY_L_COVER_BUF_NUM       1
#define VAPP_CUBE_MEDPLY_L_COVER_BUF_SIZE      (((VAPP_CUBE_MEDPLY_L_COVER_W * VAPP_CUBE_MEDPLY_L_COVER_H*2)/4 + 1)*4)
#define VAPP_CUBE_MEDPLY_ARTWORK_IMAGE_SIZE    (((SRV_PLST_ARTWORK_RESIZED_WIDTH*SRV_PLST_ARTWORK_RESIZED_HEIGHT*2)/4 + 1)*4)

#define VAPP_CUBE_MEDIA_PLAYER_MEDIA_CACHE_NUM    13
#define VAPP_CUBE_MEDPLY_RUN_BUF_SIZE_MIN      (SRV_MEDIACACHE_RUN_BUF_SIZE(VAPP_CUBE_MEDIA_PLAYER_MEDIA_CACHE_NUM))
#define VAPP_CUBE_MEDPLY_L2_CACHE_SIZE         (LCD_HEIGHT*LCD_WIDTH*2*VAPP_CUBE_MEDIA_PLAYER_MEDIA_CACHE_NUM/4)

#define VAPP_CUBE_MEDPLY_MEM_SIZE    ((VAPP_CUBE_MEDPLY_S_COVER_BUF_NUM*VAPP_CUBE_MEDPLY_S_COVER_BUF_SIZE)\
                                     +(VAPP_CUBE_MEDPLY_L_COVER_BUF_NUM*VAPP_CUBE_MEDPLY_L_COVER_BUF_SIZE)\
                                     +VAPP_CUBE_MEDPLY_ARTWORK_IMAGE_SIZE\
                                     +VAPP_CUBE_MEDPLY_RUN_BUF_SIZE_MIN\
                                     +VAPP_CUBE_MEDPLY_L2_CACHE_SIZE)



/* pen event enumeration */
typedef enum
{
    VAPP_CUBE_MEDIA_PLAYER_PEN_EVENT_DOWN,  /* Pen down */
    VAPP_CUBE_MEDIA_PLAYER_PEN_EVENT_UP,    /* Pen up */
    VAPP_CUBE_MEDIA_PLAYER_PEN_EVENT_CANCEL /* Pen cancel */
} vapp_cube_medply_pentype_enum;

/* button type enumeration */
typedef enum
{
    VAPP_CUBE_MEDIA_PLAYER_BUTTON_PLAY,     /* Play button */
    VAPP_CUBE_MEDIA_PLAYER_BUTTON_STOP,     /* Stop button */
    VAPP_CUBE_MEDIA_PLAYER_BUTTON_PAUSE,    /* Pause button */
    VAPP_CUBE_MEDIA_PLAYER_BUTTON_PREV,     /* Prev button */
    VAPP_CUBE_MEDIA_PLAYER_BUTTON_NEXT      /* Next button */
} vapp_cube_medply_button_type_enum;

/* player info enumeration */
typedef enum
{
    VAPP_CUBE_MEDIA_PLAYER_INFO_STATE,      /* State */
    VAPP_CUBE_MEDIA_PLAYER_INFO_TITLE,      /* Title */
    VAPP_CUBE_MEDIA_PLAYER_INFO_DURATION,   /* Duration */
    VAPP_CUBE_MEDIA_PLAYER_INFO_CURR_TIME   /* Current time */
} vapp_cube_medply_info_type_enum;

/* Audio player callback type enumeration */
typedef enum
{
    VAPP_CUBE_MEDIA_PLAYER_STATUS_CHANGE,   /* Status change */
    VAPP_CUBE_MEDIA_PLAYER_MEDIA_CHANGE     /* Media change */
} vapp_cube_medply_cb_type_enum;

typedef enum
{
    VAPP_CUBE_MEDIA_PLAYER_STATE_IDLE = 0,
    VAPP_CUBE_MEDIA_PLAYER_STATE_LOADING,
    VAPP_CUBE_MEDIA_PLAYER_STATE_DECODING,

    VAPP_CUBE_MEDIA_PLAYER_STATE_END
} vadp_cube_media_player_decode_state_enum;

typedef struct
{
    S32 offset_x;
    S32 offset_y;
    S32 width;
    S32 height;
} cube_medply_obj_struct;

typedef struct
{
    S32 offset_x;
    S32 offset_y;
} cube_medply_point_struct;

typedef struct
{
    S32 width;
    S32 height;
} cube_medply_size_struct;

typedef struct
{
    cube_medply_obj_struct play_panel;
    cube_medply_obj_struct cover;
    cube_medply_obj_struct song_name;
    cube_medply_obj_struct cur_time;
    cube_medply_obj_struct progress;
    cube_medply_obj_struct total_time;
    cube_medply_obj_struct stop_btn;
    cube_medply_obj_struct play_btn;
    cube_medply_obj_struct close_btn;
    cube_medply_obj_struct repeat_panel;
    cube_medply_obj_struct shuffle_btn;
    cube_medply_obj_struct repeat_btn;
    cube_medply_obj_struct up_btn;
    cube_medply_obj_struct down_btn;
} cube_medply_plymode_layout_struct;

typedef struct
{
    cube_medply_point_struct menu;
    cube_medply_size_struct cell;
    cube_medply_size_struct cd;
    cube_medply_obj_struct cover;
    cube_medply_obj_struct cur_play;

} cube_medply_navmode_layout_struct;

/* Extern cache service declerations */
extern S32 vadp_v2p_cube_media_player_init_cache_srv(S32 num_all);
extern void vadp_v2p_cube_media_player_deinit_cache_srv(void);
extern void vadp_v2p_cube_media_player_register_cache_callback(void *user_data,
                                                               void (*callback) (void *user_data, S32 index));
extern void vadp_v2p_cube_media_player_unregister_cache_callback(void);
extern S32 vadp_v2p_cube_media_player_set_focus_index(S32 index);
extern void vadp_v2p_cube_media_player_pause_cache(void);
extern void vadp_v2p_cube_media_player_resume_cache(void);

/* extern media player list service declerations */
extern S32 vadp_v2p_cube_media_player_init(void);
extern void vadp_v2p_cube_media_player_deinit(void);
extern void vadp_v2p_cube_media_player_reset(void);
extern S32 vadp_v2p_cube_media_player_get_item_count();
extern S32 vadp_v2p_cube_media_player_get_song_title(S32 index, U16 *title);
extern MMI_BOOL vadp_v2p_cube_media_player_get_cover(S32 index, U8 *buf, S32 flag);
extern S32 vadp_v2p_cube_media_player_get_active_index(void);
extern void vadp_v2p_cube_media_player_get_repeat(S32 *p_one, S32 *p_all, S32 *p_off);
extern void vadp_v2p_cube_media_player_set_repeat(S32 one, S32 all, S32 off);
extern void vadp_v2p_cube_media_player_set_shuffle(S32 shuf);
extern void vadp_v2p_cube_media_player_store_repeat(S32 one, S32 all, S32 off);
extern void vadp_v2p_cube_media_player_store_shuffle(S32 shuf);
extern void vadp_v2p_cube_media_player_get_shuffle(S32 *p_shuf);



/* extern play control declerations */
extern void vadp_v2p_cube_media_player_apply(S32 index);
extern void vadp_v2p_cube_media_player_get_info(vapp_cube_medply_info_type_enum info_type, void *result_ptr);
extern void vadp_v2p_cube_media_player_button_process(
                vapp_cube_medply_button_type_enum button_type,
                vapp_cube_medply_pentype_enum key_event);
extern void vadp_v2p_cube_media_player_register_callback(void *userdata, void (*callback) (void *, U32, void *));
extern void vadp_v2p_cube_media_player_deregister_callback(void);
extern MMI_BOOL vadp_v2p_cube_media_player_is_back_light_on(void);
extern void vadp_v2p_cube_media_player_set_back_light_on(void);
extern void vadp_v2p_cube_media_player_continue_play_after_exit(void);
/**********************************************************************
 * Structure Definitions
 **********************************************************************/

/**********************************************************************
 * External Interfaces
 **********************************************************************/

extern cube_medply_plymode_layout_struct g_cube_medply_plymode_layout;
extern cube_medply_navmode_layout_struct g_cube_medply_navmode_layout;
extern U8* vapp_cube_medply_s_cover_buf[];
extern U8* vapp_cube_medply_l_cover_buf[];
extern U16 test_string[][128];
extern gdi_handle cubeimagehandle[];
extern void init_test_image(void);
extern void free_test_image(void);

#ifdef __cplusplus
}   /* extern "C" */
#endif 

#endif /* __VADP_V2P_CUBE_MEDIA_PLAYER_H__ */ 
#endif

