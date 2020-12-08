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
 *  vapp_music_player_datatype.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  FTO Music Player Data Type
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

#ifndef __VAPP_MUSIC_PLAYER_DATATYPE_H__
#define __VAPP_MUSIC_PLAYER_DATATYPE_H__

#ifdef __LOW_COST_SUPPORT_COMMON__
#define __COSMOS_MUSICPLY_CARD_ONLY__
#endif

#include "MediaCacheSrvMem.h"

/***************************************************************************** 
 * Definition
 *****************************************************************************/

#define VAPP_MUSICPLY_PLSV_MAX_ITEM 100000
#define VAPP_MUSICPLY_PLAYLIST_NAME_MAX 40
#define VAPP_MUSICPLY_DEF_LARGE_NUM 0xFFFFFFFF

#if defined(__MMI_MAINLCD_240X320__)
#define VAPP_MUSICPLY_LISTMENU_THUMB_WIDTH  40
#define VAPP_MUSICPLY_LISTMENU_THUMB_HEIGHT 40
#define VAPP_MUSICPLY_CF_CELL_WIDTH  95
#define VAPP_MUSICPLY_CF_CELL_HEIGHT 95
#define VAPP_MUSICPLY_LARGE_ALBUM_COVER_WIDTH 240
#define VAPP_MUSICPLY_LARGE_ALBUM_COVER_HEIGHT 240

#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_MUSICPLY_LISTMENU_THUMB_WIDTH  40
#define VAPP_MUSICPLY_LISTMENU_THUMB_HEIGHT 40
#define VAPP_MUSICPLY_CF_CELL_WIDTH  95
#define VAPP_MUSICPLY_CF_CELL_HEIGHT 95
#define VAPP_MUSICPLY_LARGE_ALBUM_COVER_WIDTH 240
#define VAPP_MUSICPLY_LARGE_ALBUM_COVER_HEIGHT 240

#elif defined(__MMI_MAINLCD_320X480__)
#define VAPP_MUSICPLY_LISTMENU_THUMB_WIDTH  48
#define VAPP_MUSICPLY_LISTMENU_THUMB_HEIGHT 48
#ifdef __COSMOS_3D_V10__
#define VAPP_MUSICPLY_CF_CELL_WIDTH  150
#define VAPP_MUSICPLY_CF_CELL_HEIGHT 150
#else
#define VAPP_MUSICPLY_CF_CELL_WIDTH  90
#define VAPP_MUSICPLY_CF_CELL_HEIGHT 90
#endif
#define VAPP_MUSICPLY_LARGE_ALBUM_COVER_WIDTH 320
#define VAPP_MUSICPLY_LARGE_ALBUM_COVER_HEIGHT 320

#else //(__MMI_MAINLCD_480X800__)
#define VAPP_MUSICPLY_LISTMENU_THUMB_WIDTH  72
#define VAPP_MUSICPLY_LISTMENU_THUMB_HEIGHT 72
#ifdef __COSMOS_3D_V10__
#define VAPP_MUSICPLY_CF_CELL_WIDTH  150
#define VAPP_MUSICPLY_CF_CELL_HEIGHT 150
#else
#define VAPP_MUSICPLY_CF_CELL_WIDTH  138
#define VAPP_MUSICPLY_CF_CELL_HEIGHT 138
#endif
#define VAPP_MUSICPLY_LARGE_ALBUM_COVER_WIDTH 480
#define VAPP_MUSICPLY_LARGE_ALBUM_COVER_HEIGHT 480
#endif

#define VAPP_MUSICPLY_META_FILE_IMAGE_SIZE 600 * 1024

#define VAPP_MUSICPLY_PLST_DB_MEM_SIZE    (500*1024) // Should equal or larger than SRV_PLST_MIN_MEM_SQLITE size, used for SQLite dabase
#ifdef __LOW_COST_SUPPORT_COMMON__
#define VAPP_MUSICPLY_PLST_DB_BACKGROUND_MEM_SIZE (100*1024) // Widget does not have cover, can use less memory when query data from DB in background
#else
#define VAPP_MUSICPLY_PLST_DB_BACKGROUND_MEM_SIZE (200*1024)
#endif

#define VAPP_MUSICPLY_MEDIACACHE_CACHE_COUNT 100
#define VAPP_MUSICPLY_MEDIACACHE_WORKING_SIZE SRV_MEDIACACHE_RUN_BUF_SIZE(VAPP_MUSICPLY_MEDIACACHE_CACHE_COUNT)

#ifdef __COSMOS_MUSICPLY_COVER_FLOW__
#define VAPP_MUSICPLY_DECODE_COVER_BUFFER_NUM 2
#define VAPP_MUSICPLY_MEDIACACHE_CACHE_SIZE (VAPP_MUSICPLY_MEDIACACHE_CACHE_COUNT * VAPP_MUSICPLY_CF_CELL_WIDTH * VAPP_MUSICPLY_CF_CELL_HEIGHT * 2)
#define VAPP_MUSICPLY_COVER_FLOW_EXTRA_HEAP_SIZE (200)
#else
#define VAPP_MUSICPLY_DECODE_COVER_BUFFER_NUM 1
#define VAPP_MUSICPLY_MEDIACACHE_CACHE_SIZE (VAPP_MUSICPLY_MEDIACACHE_CACHE_COUNT * VAPP_MUSICPLY_LISTMENU_THUMB_WIDTH * VAPP_MUSICPLY_LISTMENU_THUMB_HEIGHT * 2)
#define VAPP_MUSICPLY_COVER_FLOW_EXTRA_HEAP_SIZE (0)
#endif

/***************************************************************************** 
 * Enumeration
 *****************************************************************************/

enum ViewTypeEnum
{
    VIEW_TYPE_TAB_PAGE,                 // 0

    VIEW_TYPE_ALL_SONGS,                // 1
    
    VIEW_TYPE_ARTIST,                   // 2
    VIEW_TYPE_ARTIST_SONG,              // 3
    VIEW_TYPE_ARTIST_ALBUM,             // 4
    VIEW_TYPE_ARTIST_ALBUM_SONG,        // 5

    VIEW_TYPE_ALBUM,                    // 6
    VIEW_TYPE_ALBUM_SONG,               // 7

    VIEW_TYPE_PLAYLIST,                 // 8
    VIEW_TYPE_PLAYLIST_SONG,            // 9

    VIEW_TYPE_PLAYLIST_SELECT,          // 10

    VIEW_TYPE_VIEW_SELECT,              // 11
    VIEW_TYPE_PLAYLIST_ADD_ALL_SONG,    // 12
    VIEW_TYPE_PLAYLIST_ADD_ARTIST,      // 13
    VIEW_TYPE_PLAYLIST_ADD_ARTIST_SONG, // 14
    VIEW_TYPE_PLAYLIST_ADD_ALBUM,       // 15
    VIEW_TYPE_PLAYLIST_ADD_ALBUM_SONG,  // 16

    VIEW_TYPE_NOW_PLAYING,              // 17
    VIEW_TYPE_NOW_PLAYING_LIST,         // 18

    VIEW_TYPE_SETTING,                  // 19
    VIEW_TYPE_SETTING_SOUND_EFFECT,     // 20

    VIEW_TYPE_COVER_FLOW,               // 21
    VIEW_TYPE_COVER_FLOW_SONG,          // 22

    VIEW_TYPE_NONE,                     // 23
  
    VIEW_TYPE_END_OF_ENUM
};

enum ChangeViewMode
{
    CHANGE_VIEW_MODE_ENTER,             // 0
    CHANGE_VIEW_MODE_BACK,              // 1
    CHANGE_VIEW_MODE_SWITCH,            // 2
    CHANGE_VIEW_MODE_NONE               // 3
};

enum ActionEnum
{
    ACTION_LAUNCHING,                   // 0
    ACTION_LAUNCHING_FROM_BG,           // 1
    ACTION_REOPENING_DB,                // 2
    ACTION_REOPENING_DB_REALLOC,        // 3
    ACTION_FATAL_ERROR,                 // 4
    ACTION_REFRESH,                     // 5
    ACTION_RESET,                       // 6
    ACTION_DELETE,                      // 7
    ACTION_ADD_TO_PLAYLIST,             // 8
    ACTION_PLAYLIST_NEW,                // 9
    ACTION_PLAYLIST_ADD_SONG,           // 10
    ACTION_PLAYLIST_REMOVE,             // 11
    ACTION_PLAYLIST_RENAME,             // 12
    ACTION_PLAYLIST_SONG_ARRANGE,       // 13

    ACTION_NONE                         // 14
};

#endif /*   __VAPP_MUSIC_PLAYER_DATATYPE_H__    */

#endif //__COSMOS_MUSICPLY__
