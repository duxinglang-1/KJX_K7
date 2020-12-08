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
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH´Ë
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
 *  MusicPlaylist.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include header file
 *****************************************************************************/
#include "mmi_features.h"
#ifdef __MMI_PLAYLIST_SERVICE_SLIM__

#ifndef __MUSIC_PLAY_LIST_H__
#define __MUSIC_PLAY_LIST_H__

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "FileMgrSrvGProt.h"
#include "gui_data_types.h"
#include "fs_type.h"
#include "kal_public_defs.h"
#include "MusicPlaylistGprot.h"

// macro define
#define MUSIC_PLAYLIST_TYPE_ID                   "ALST"
#define MUSIC_PLAYLIST_VERSION                   "01"
#define MUSIC_PLAYLIST_DATA_OFFSET               (sizeof(music_playlist_header_struct))
#define MUSIC_PLAYLIST_FOOTER_PATTERN            0xFEFEFEFE
#define MUSIC_PLAYLIST_BLOCK_PATTERN_1           0x3F3F3F3F
#define MUSIC_PLAYLIST_BLOCK_PATTERN_2           0x4F4F4F4F


#define MUSIC_PLAYLIST_MAX_PICK_PER_SLICE        (20)
#define MUSIC_PLAYLIST_MAX_DEPTH_DIRECTORY       (16)
#define MUSIC_PLAYLIST_BLOCK_DATA_SIZE           (128)
#define MUSIC_PLAYLIST_MAX_BITSET_SIZE           (SRV_PLAYLIST_MAX_PLAYLIST_ITEM / 8)

#define MUSIC_PLAYLIST_LIST_BUFF_SIZE            (20)

#define MUSIC_PLAYLIST_LIB_FOLDER                 L"@Playlists"
#define MUSIC_PLAYLIST_LIB_FILE_NAME              L"audio_play_list"
#define MUSIC_PLAYLIST_LIB_FILE_EXT               L"mal"

#define ClrBitSet( index, bitset )     ((bitset)[(index)>>3] &= ~(1<<((index)&0x07)))
#define SetBitSet( index, bitset )     ((bitset)[(index)>>3] |= (1<<((index)&0x07)))
#define IsBitSetOn( index, bitset )    ((bitset)[(index)>>3] & (1<<((index)&0x07)))
#define EOS(nob)                       ((nob)>1 ? ((nob)>>1)-1: 0)


/* 
**  mp3 mp2 amr aac awb bsac are the four audio types which
**  requires building cache to seek, so we put them in the frist six items
**  for build cache deciding api to reference.
*/
const static UI_character_type audio_format_table[][5] = 
{
#ifdef DAF_DECODE
    L"mp3",
#ifdef MUSICAM_DECODE    
    L"mp2",
#endif    
#endif 
    L"amr", 
#ifdef AAC_DECODE
    L"aac",
#endif 
#ifdef AMRWB_DECODE
    L"awb",
#endif 
#ifdef BSAC_DECODE
/* under construction !*/
#endif
#ifdef __DRM_V02__
    L"odf",
#endif
    L"wav",   
    L"mid",
    L"midi", 
    L"imy",
//    L"vm ",
#ifdef AIFF_DECODE
    L"aif",
    L"aiff",
    L"aifc",
#endif
#ifdef AU_DECODE
    L"au",
#endif
#ifdef SND_DECODE
    L"snd",
#endif
#ifdef M4A_DECODE
    L"m4a",
#endif 
#ifdef YAMAHA_MA3
    L"mmf",
#endif 
#ifdef WMA_DECODE
    L"wma",
#endif 
#if defined(__MMI_PURE_AUDIO__)
    L"3gp",
    L"3g2",
    L"mp4",
#endif

#ifdef __RM_DEC_SUPPORT__
    L"ra",
#endif

#ifdef __APE_DECODE__
    L"ape",
#endif    
#ifdef __FLAC_DECODE__
    L"flac",
#endif

#if defined(__VORBIS_DECODE__) && !defined(__VORBIS_DECODE_SLIM__)
    L"OGG",
#endif

    L"\0"   /* end of list */
};

typedef enum
{
    MUSIC_PLAYLIST_GEN_PHASE_INIT,
    MUSIC_PLAYLIST_GEN_PHASE_SET_DRV,
    MUSIC_PLAYLIST_GEN_PHASE_SEARCH_FIRST,
    MUSIC_PLAYLIST_GEN_PHASE_SEARCH_NEXT,
    MUSIC_PLAYLIST_GEN_PHASE_SEARCH_FOLDER,
    MUSIC_PLAYLIST_GEN_PHASE_FORWARDS,
    MUSIC_PLAYLIST_GEN_PHASE_BACKWARDS,
    MUSIC_PLAYLIST_GEN_PHASE_FINISH,
    MUSIC_PLAYLIST_GEN_PHASE_ERR_HDLR,
    MUSIC_PLAYLIST_GEN_PHASE_SEARCH_ODF,
    MUSIC_PLAYLIST_GEN_PHASE_BACKWARDS_ODF,
    MUSIC_PLAYLIST_GEN_PHASE_CANCEL,
    MUSIC_PLAYLIST_GEN_PHASE_END
}music_playlist_generate_phase_enum;

typedef struct
{
    LOCAL_PARA_HDR
    void *context;
    S32 para_1;
    void *para_2;
}music_playlist_action_req_struct;

typedef struct
{
    U32 offset;
    U16 index;
    U8  used_block;
    U8  is_active;  /* short name: is_active == 2, long name: is_active == 1. */
} music_playlist_index_node_struct;

typedef struct
{
    CHAR type_id[4];
    CHAR version[2];
    U16 total_slot;             /* total item count. */
    U32 footer_pattern_offset;  /* file size. */
    music_playlist_index_node_struct empty_node;
    music_playlist_index_node_struct index[SRV_PLAYLIST_MAX_PLAYLIST_ITEM];
    U32 pattern;
} music_playlist_header_struct;

typedef struct
{
    U16 level;             /* stack level. */
    U16 total_sub_folder;  /* total sub-folder number in this level. */
    U16 index;             /* current index in all sub-folder. */
    U16 fs_index;          /* fs index for FS_FindFirst(). */
} music_playlist_stack_node_struct;

typedef struct
{
    U32 pattern_begin;
    CHAR data[MUSIC_PLAYLIST_BLOCK_DATA_SIZE];
    U32 next_ptr;
    U32 pattern_end;
} music_playlist_block_node_struct;

typedef struct
{
    UI_character_type filename[SRV_FMGR_PATH_MAX_LEN + 1];
    UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    U8 file_type;
    U8 is_short;
} music_playlist_item_info_struct;

typedef struct
{
    S32 pick_index;                               /* current played item index in this list. */
    S32 pick_count;                               /* had been played item count. */
    S32 total;                                    /* total items in this list. */

    srv_playlist_shuffle_enum shuffle_mode;       /* 0: off, 1: on. */
    srv_playlist_repeat_enum repeat_mode;         /* 0: off, 1: repeat one, 2: repeat all. */

    U32 mark_count;                               /* multi select mark count. */
    U32 delete_count;                             /* deleted count. */
    U32 delete_group;                             /* current delete search group(byte) .*/
    MMI_BOOL delete_canceled;                     /* if current delete operation be canceled. */
    U8 bitMark[MUSIC_PLAYLIST_MAX_BITSET_SIZE];   /* multi select mark bit. */
    
    U8 bitset[MUSIC_PLAYLIST_MAX_BITSET_SIZE];    /* shuffle play select bit. */
    FS_HANDLE fs_hdlr;
    
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type title[SRV_FMGR_PATH_MAX_LEN + 1];
    music_playlist_header_struct header;
} music_playlist_list_struct;

typedef struct
{
    S32 total;
    S32 highlight;
    U16 cache_start_index;
    U16 cache_end_index;
    UI_character_type title[SRV_FMGR_PATH_MAX_LEN + 1];
    music_playlist_item_info_struct cache[MUSIC_PLAYLIST_LIST_BUFF_SIZE];
} music_playlist_dynamic_list_data_struct;

typedef struct
{
    U32 appended_number;
    U32 total_number;
    S32 last_error_code;
    U32 footer_pattern_offset;
    FS_HANDLE search_handle;
    FS_HANDLE list_file_handle;
    
    U16 phase;
    U16 stack_index;     /* folder level & stack level. */
    
    UI_character_type path_cache[(SRV_FMGR_PATH_MAX_LEN+1) + 1];

    music_playlist_stack_node_struct stack[MUSIC_PLAYLIST_MAX_DEPTH_DIRECTORY];
    
#ifdef __DRM_V02__
    void* DRM_find_cntx;
#endif
} music_playlist_generate_struct;

typedef struct
{
    void *user_data;
    cb_func callback;
    srv_playlist_create_struct create;

    MMI_BOOL list_loaded;
    
    //music_playlist_list_struct browser_list;  /* temp not support multi playlist. */ 
    music_playlist_list_struct current_list;
    music_playlist_dynamic_list_data_struct list_ui;
    music_playlist_generate_struct generate_info;
} music_playlist_cntx_struct;

#endif  //__MMI_PLAYLIST_SERVICE_SLIM__
#endif  //__MUSIC_PLAY_LIST_H__
