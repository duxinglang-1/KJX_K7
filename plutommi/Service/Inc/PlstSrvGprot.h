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
 *  PlstSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  player list service head file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PLST_SERVICE_GPROT_H__
#define __PLST_SERVICE_GPROT_H__

#include "FileMgrSrvGProt.h"
#include "meta_tag_api.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "mmi_rp_file_type_def.h"
#include "MMI_features.h"
#include "mmi_frm_events_gprot.h"

#ifdef __PLST_SERVICE_DB_SUPPORT__

#if defined(__MMI_MAINLCD_320X480__) && defined(__MMI_VUI_SHELL_MEDIA_PLAYER__)
#define SRV_PLST_ARTWORK_RESIZED_WIDTH   176
#define SRV_PLST_ARTWORK_RESIZED_HEIGHT  176  //The size must be even number
#else
#define SRV_PLST_ARTWORK_RESIZED_WIDTH   150
#define SRV_PLST_ARTWORK_RESIZED_HEIGHT  150
#endif

#define SRV_PLST_USE_CRC_GEN_UNQIUE  


#define SRV_PLST_MAX_SERVICE_SUPPORT         (20)

/* max length of each meta info */
#define SRV_PLST_META_INFO_MAX_LEN            (META_TAG_FRAME_MAX_LEN)

#define SRV_PLST_MAX_TEMP_FILE_LENGTH          41
/* max file length */
#define SRV_PLST_MAX_FILE_LEN                 (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1)
/* max filepath length */
#define SRV_PLST_MAX_PATH_LEN                 ((SRV_FMGR_PATH_MAX_LEN+1))
/* max file extension length*/
#define SRV_PLST_MAX_EXT_LEN                  (SRV_FMGR_PATH_MAX_FILE_EXT_LEN)
#define SRV_PLST_MAX_GROUP_NUM                 30


#define SRV_PLST_VIEW_LIST_DEPTH                    (6)
#define SRV_PLST_VIEW_LIST_CACHE                    (100)
#define SRV_PLST_MAX_FOLDER_DEPTH                   (16)
#define SRV_PLST_MIN_DB_SPACE                       (100)
#define SRV_PLST_MAX_ALL_TRACKS_ITEM                (5000)
#define SRV_PLST_MAX_PLST_ITEM                      (5000)
#define SRV_PLST_RECENT_LIST_MAX_COUNT              (20)
#define SRV_PLST_MOST_PLAYED_COUNT                  (20)
#define SRV_PLST_MAX_REORDER_STEP                   (SRV_PLST_VIEW_LIST_CACHE/2)

/* min memory size list service need */
#define SRV_PLST_MIN_MEM_SQLITE               (240 * 1024)  /* Memory reserve for SQLite database */
#define SRV_PLST_MIN_MEM_CONTROL              (20 *1024)    /* Foreground, consider sizeof(srv_plst_main_context_struct) + sizeof(srv_plst_gen_lib_context_struct) + meta parser memory */
#define SRV_PLST_MIN_MEM_CONTROL_BACKGROUND   (11 *1024)    /* Not add songs in background, only consider sizeof(srv_plst_main_context_struct) */
#define SRV_PLST_MIN_MEM_CONTROL_GEN_DB       (4500)        /* sizeof(srv_plst_gen_lib_context_struct), accurate size is 4416 */

#define SRV_PLST_MIN_MEM_SIZE                 (SRV_PLST_MIN_MEM_SQLITE + SRV_PLST_MIN_MEM_CONTROL)


#if defined(__MMI_CSTAR__) || defined(__MMI_T9__)
//#define  __SRV_PLST_SUPPORT_PINYIN_SORT__
#endif


/* configue default playlist, app need check to prevent create another playlist name same as default playlist */
typedef enum
{
    /* default playlist all kuro list */
    SRV_PLST_DEF_ALL_KURO_LIST       = 0X0001,
    /* default playlist my favourite */
    SRV_PLST_DEF_MY_FAVOURITE        = 0X0002,
    /* default playlist recent playlist */
    SRV_PLST_DEF_RECENTLY_PLST       = 0X0004,
    /* default playlist most played list */
    SRV_PLST_DEF_MOST_PLST           = 0X0008,
    /* default playlist on the fly list */
    SRV_PLST_DEF_ON_THE_FLY          = 0X0010,
    SRV_PLST_DEF_LIST_ENUM_END,   /* config info end */
    /* default playlist  */
    SRV_PLST_DEF_ACTIVE_LIST         = 0X8000    
}srv_plst_default_playlist_enum;


/* three type repeat mode */
typedef enum
{
    SRV_PLST_REPEAT_OFF, /* repeat off */
    SRV_PLST_REPEAT_ONE, /* repeat one */
    SRV_PLST_REPEAT_ALL, /* repeat all */
    SRV_PLST_REPEAT_END   /* end of enum */
}srv_plst_repeat_enum;

/* teo type shuffle mode*/
typedef enum
{
    SRV_PLST_SHUFFLE_OFF, /* shulffe off */
    SRV_PLST_SHUFFLE_ON,  /* shulffe on */
    SRV_PLST_SHUFFLE_END   /* end of enum */
}srv_plst_shuffle_enum;


/* view type in the data lib */
typedef enum
{
     SRV_PLST_VIEW_DUMMY = 0,	 /* DUMMY */
     SRV_PLST_VIEW_AUDIO,
     SRV_PLST_VIEW_VIDEO,
     SRV_PLST_VIEW_STREM_LINK,
     SRV_PLST_VIEW_ARTIST, /* artist  type */
     SRV_PLST_VIEW_ALBUM,  /* album type */
     SRV_PLST_VIEW_GENRE,  /* genre  type */
     SRV_PLST_VIEW_MEDIA,  /* media file type */
     SRV_PLST_VIEW_IMAGE_FLOW,
     SRV_PLST_VIEW_PLST,   /* play list type */
     SRV_PLST_VIEW_PLST_ADDTO,
     SRV_PLST_VIEW_PLST_ACTIVE, /* view active list, not use for entry default list directly */
     SRV_PLST_VIEW_PREFIX_SEARCH, /* app won't set this enum */
     SRV_PLST_VIEW_PLST_DEFAULT,  /* For shell or cube only, already phase out */
     SRV_PLST_VIEW_END,    /* end of enum */
     SRV_PLST_VIEW_ROOT = 0XFFFFFFFF
}srv_plst_view_type_enum;

typedef enum
{
    SRV_PLST_TYPE_ID_NONE,
    SRV_PLST_TYPE_ID_AUDIO,
    SRV_PLST_TYPE_ID_VIDEO,
    SRV_PLST_TYPE_ID_ARTIST,
    SRV_PLST_TYPE_ID_ALBUM,
    SRV_PLST_TYPE_ID_GENRE,
    SRV_PLST_TYPE_ID_MEDIA,
    SRV_PLST_TYPE_ID_PLST,
    SRV_PLST_TYPE_END
}srv_plst_storage_type_id_enum;

typedef enum
{
    SRV_PLST_CNTX_TYPE_FILENAME,
    SRV_PLST_CNTX_TYPE_TITLE,
    SRV_PLST_CNTX_TYPE_ARTISTNAME,
    SRV_PLST_CNTX_TYPE_ALBUMNAME,
    SRV_PLST_CNTX_TYPE_GENRENAME,
  //  SRV_PLST_CNTX_TYPE_PLSTNAME,
   // SRV_PLST_CNTX_TYPE_PATH,
  //  SRV_PLST_CNTX_TYPE_DETAILS,
    SRV_PLST_CNTX_TYPE_END
}srv_plst_get_context_type_enum;

typedef enum
{
    SRV_PLST_ACTIVE_LIST_TYPE_NONE,
    SRV_PLST_ACTIVE_LIST_TYPE_AUDIO,
    SRV_PLST_ACTIVE_LIST_TYPE_VIDEO,
    SRV_PLST_ACTIVE_LIST_TYPE_AUDIO_DYNAMIC_LIST,
    SRV_PLST_ACTIVE_LIST_TYPE_END
}srv_plst_active_list_media_type_enum;

typedef enum
{
    SRV_PLST_ACTIVE_LIST_NONE,
    SRV_PLST_ACTIVE_LIST_AUDIO,
    SRV_PLST_ACTIVE_LIST_VIDEO,
    SRV_PLST_ACTIVE_LIST_PLST,
    SRV_PLST_ACTIVE_LIST_TEMP_AUDIO,  /* for mark serval play */
    SRV_PLST_ACTIVE_LIST_TEMP_VIDEO,
    SRV_PLST_ACTIVE_LIST_TEMP_PLST,
    SRV_PLST_ACTIVE_LIST_STREAM_LINK,  /* current no support */
    SRV_PLST_ACTIVE_LIST_ENUM_END
}srv_plst_active_list_enum;

typedef enum
{
    SRV_PLST_LIST_SORT_BY_UNICODE,   /* default type */  
    SRV_PLST_LIST_SORT_BY_PINYIN,  
    SRV_PLST_LIST_SORT_BY_MODIFY_TIME, /* only for playlist */
    SRV_PLST_LIST_SORT_BY_INDEX,       /* only for playlist item, by added index */
    SRV_PLST_LIST_SORT_END
}srv_plst_list_sort_type_enum;

typedef enum
{
    SRV_PLST_SEARCH_BY_PREFIX_NEW_LIST,  /* default type */
    SRV_PLST_SEARCH_BY_PREFIX_CURRENT_LIST,
    SRV_PLST_SEARCH_BY_WORD_FIX,
    SRV_PLST_SEARCH_END
}srv_plst_search_type_enum;

typedef enum
{
    SRV_PLST_PLST_REORDER_CONTINUE, /* default type, can cancelreorder action*/
    SRV_PLST_PLST_REORDER_DERECTLY, /* can't cacnel the reorder action */
    SRV_PLST_PLST_REORDER_END
}srv_plst_plst_reorder_enum;

typedef enum
{
    SRV_PLST_VIEW_SORT_BY_FILENAME,
    SRV_PLST_VIEW_SORT_BY_TITLE,
    SRV_PLST_VIEW_SROT_END
}srv_plst_view_sort_type;


typedef enum
{
    SRV_PLST_PLAY_INFO_STORE,
    SRV_PLST_PLAY_INFO_NOT_STORE,
    SRV_PLST_PLAY_INFO_STORE_MANUAL,    /* store playing info in database, but update action triggered by caller */
    SRV_PLST_PLAY_INFO_ENUM,
}srv_plst_playing_info_store_enum;

typedef enum
{
    SRV_PLST_HAVE_PLAY_CYCLE_INFO, /* Application will cotrol repeat all cycle */
    SRV_PLST_NO_PLAY_CYCLE_INFO,   /* List service control repeat all (do not return empty)  */
    SRV_PLST_PLAY_CYCLE_INFO_END
}srv_plst_play_cycle_info_enum;

typedef enum
{
    SRV_PLST_CONFIG_LIST_VIEW_SORT_TYPE,
    SRV_PLST_CONFIG_PLST_VIEW_SORT_TYPE,
    SRV_PLST_CONFIG_VIEW_SORT_CONTEXT,
    SRV_PLST_CONFIG_SEARCH_TYPE,
    SRV_PLST_CONFIG_REORDER_TYPE,
    SRV_PLST_CONFIG_PLAY_INFO,
    SRV_PLST_CONFIG_RET_PLAY_CYCLE_INFO,
    SRV_PLST_CONFIG_END
}srv_plst_config_type_enum;

/* player list service caller handler return value */
typedef enum
{
    /* api execute OK, no error */
    SRV_PLST_OK = 0,
    /* need more time to return result */
    SRV_PLST_ASYNC,  
    SRV_PLST_RET_ERR_BEGIN = -5000,
    /* version wrong, api can popup or recall open */
    SRV_PLST_VERSION_WRONG,
    SRV_PLST_RET_ERR_MEMORY_NOT_ENOUGH,
    SRV_PLST_RET_ERR_DISK_NOT_ENOUGH,
    SRV_PLST_RET_ERR_SERVICE_MAX_SUPPORT,
    SRV_PLST_RET_ERR_MEMORY_CONRRUPT,
    SRV_PLST_RET_ERR_DB_CONRRUPT,
    SRV_PLST_RET_ERR_DESTROY_FAIL,
    SRV_PLST_RET_ERR_SQLITE_ERR,
    SRV_PLST_RET_ERR_PARAM_ERR,
    SRV_PLST_RET_ERR_UNKOWN_ERR, //-4990
    SRV_PLST_RET_ERR_FS_ERROR,
    SRV_PLST_RET_ERR_FATAL_ERROR,
    SRV_PLST_RET_ITEM_EXIST,
    SRV_PLST_RET_CONTINUE,
    SRV_PLST_RET_EMPTY,
    SRV_PLST_RET_ERR_META_PAESER,
    SRV_PLST_RET_ERR_GDI_ERR,
    SRV_PLST_RET_ERR_DB_NOT_FOUND,
    SRV_PLST_RET_ERR_DB_CRASH,
    SRV_PLST_RET_DELETE_ACTIVE,
    SRV_PLST_RET_CANCEL_ACTION,
    SRV_PLST_RET_DB_FULL,
    SRV_PLST_RET_DB_AUDIO_FULL,
    SRV_PLST_RET_DB_VIDEO_FULL,
    SRV_PLST_RET_PLST_FULL,
    SRV_PLST_RET_ERR_IMG_FORMAT_ERROR,    
   /* end of enum */
    SRV_PLST_RET_END  
}srv_plst_caller_handler_enum;

typedef enum
{
    SRV_PLST_PLST_SHOW_NONE,
    SRV_PLST_PLST_DEFAULT_SHOW_FIRST,
    //SRV_PLST_PLST_DEFAULT_SHOW_LAST, /* OBSOLETE */
    SRV_PLST_PLST_SHOW_END,
}srv_plst_plst_show_sequeue_enum;


typedef enum
{
    SRV_PLST_ACTIVE_ALBUM,
    SRV_PLST_ACTIVE_MEDIA,
    SRV_PLST_ACTIVE_END
}srv_plst_active_type_enum;

/* enum for open libarary  */
typedef enum
{
    SRV_PLST_OPEN_ONLY,   /* open directly, failed return */
    SRV_PLST_OPEN_AUTO,   /* only update the damaged */
    SRV_PLST_OPEN_NEW,   /* open, delete old db and create new one  */ 
    SRV_PLST_OPEN_AFTER_MEDIA_CHANGE,  /* call when plug in SD card during service already in using  */
    SRV_PLST_OPEN_REOPEN,  /* reopen database for memory shrink, everything is the same as original config  */
    SRV_PLST_OPEN_END
}srv_plst_open_flag_enum;

/* player list operation strcture */
typedef struct
{
    S32 index;         /* index of selected, */
    U32 id;            /* id of selected */
    U16 view_type;     /* see srv_plst_view_type_enum */
    MMI_BOOL is_id_used;  /* the index and id only use one param, is_id_used: TRUE: used id param  FALSE: use index */
}srv_plst_list_view_struct;
/*
sample if op artist all                 (SRV_PLST_VIEW_ROOT, SRV_PLST_VIEW_ARTIST )
          op second artist'slbum          ( 2 ,SRV_PLST_VIEW_ALBUM)  
          op selected artist all tracks     (2, SRV_PLST_VIEW_MEDIA )            
          op selected album's all song           (2, SRV_PLST_VIEW_MEDIA )
          
          op album's second song        (2, SRV_PLST_VIEW_MEDIA)
          op all audio                  (SRV_PLST_VIEW_ROOT, SRV_PLST_VIEW_AUDIO) 
          op all plst                  (SRV_PLST_VIEW_ROOT, SRV_PLST_VIEW_PLST)
          op second play list           (2,SRV_PLST_VIEW_MEDIA)
*/

/* player list get fixed count strcture */
typedef struct
{
    srv_plst_list_view_struct view_stack[SRV_PLST_VIEW_LIST_DEPTH];

}srv_plst_fixed_count_struct;

/* get item display structure */
typedef struct
{
    U32 index;   /* in :item index */
    U32 buff_size;    /* in:  buff_size */
    U32 string_ptr;   /* in/out: context */
}srv_plst_list_get_display_struct;


typedef struct
{
    U32 param_a;  /* unique id in db, or index1 */
    U32 param_b; /* storage info or index2 */    
}srv_plst_list_item_info;


/* time stucture */
typedef struct
{
   U16  year;  /*  year */
   U8   month; /*  mouth */
   U8   day;  /* day*/
   U8   hour; /*  hour */
   U8   min;	 /*  minites */
}srv_plst_time_struct;

/* player list service details structure */
typedef struct
{
    U32 media_id;
    UI_character_type filename[SRV_PLST_META_INFO_MAX_LEN + 1];  /* filename */
    UI_character_type title[SRV_PLST_META_INFO_MAX_LEN + 1];     /* title */
    UI_character_type artist[SRV_PLST_META_INFO_MAX_LEN + 1];    /* artist name */
    UI_character_type album[SRV_PLST_META_INFO_MAX_LEN + 1];     /* album name */
    UI_character_type author[SRV_PLST_META_INFO_MAX_LEN + 1];    /* author name */
    UI_character_type genre[SRV_PLST_META_INFO_MAX_LEN + 1];     /* genre */
    UI_character_type copyrights[SRV_PLST_META_INFO_MAX_LEN + 1];   /* copyrights */
    UI_character_type description[SRV_PLST_META_INFO_MAX_LEN + 1];   /*description */
    S32 artwork_type;
    S32 duration;   /* secend */
    U32 bits_rate;
    U16 sample_rate;
    S16 track_num;    /* traks number */
    S16 year;         /* year */
    U8 channel_num;     /* channel num */
    U16 play_count;    /* 65536 */ 
    S16 volume;/* 65535 */
    U8  user_rating;    /* user rating */
    U8 sample_bits;
    srv_plst_time_struct last_played;  /*last played time */
    srv_plst_time_struct last_modified;   /* last modifyed name */ 
}srv_plst_media_details_struct;

typedef union
{
    UI_character_type name[SRV_PLST_MAX_PATH_LEN + 1];  /* filename */
   // UI_character_type path[SRV_PLST_MAX_PATH_LEN];   
}srv_plst_get_context_struct;

typedef struct
{
    U32 id;
    srv_plst_storage_type_id_enum id_enum;    
    srv_plst_get_context_type_enum get_type;
}srv_plst_get_cntx_param_struct;

typedef struct
{
    U32 group_count;  /* the group count will only return 1 or 27, 1: show no sub group only one  27: A-Z/# */
    U32 group[SRV_PLST_MAX_GROUP_NUM];
}srv_plst_list_group_item_info_struct;

typedef struct
{
    U32 buff_size;   /* in */
    U32 buff_ptr;    /* in/out: buff to get info*/
}srv_plst_get_cntx_output_struct;

typedef struct
{
    CHAR *path;
    S8 is_folder;
    MMI_BOOL is_delete_all;
    FMGR_FILTER filter;
}srv_plst_delete_file_from_fmgr_struct;

/* player list service callback event */
typedef enum
{
    /* DONE/FAILED
       when open down, will call caller callback*/
    SRV_PLST_CB_EVT_OPEN,
    /* DONE/CANCElED/FAILED 
       when finished completed, response this event and done info
       when canceled completed, response this event and cacenled ino
       when gen failed, response this event and failed info*/    
    SRV_PLST_CB_EVT_UPDATE, 
    /* DONE/FAILED */  
    SRV_PLST_CB_EVT_SEARCH, 
    /* DONE /FAILED/CANCELED*/
    SRV_PLST_CB_EVT_DELETE_LIST,
    SRV_PLST_CB_EVT_DELETE_ACTIVE_MEDIA,
    SRV_PLST_CB_EVT_ADD_TO_PLST,
    SRV_PLST_CB_EVT_GET_IMAGE,
    SRV_PLST_CB_EVT_USB_PLUG_IN,
    SRV_PLST_CB_EVT_USB_PLUG_OUT,
    SRV_PLST_CB_EVT_MSDC_PLUG_OUT,
    SRV_PLST_CB_EVT_MSDC_PLUG_IN,
    SRV_PLST_CB_EVT_PRE_FORMAT,
    SRV_PLST_CB_EVT_AFT_FORMAT,
    SRV_PLST_CB_EVT_NOTIFY_DEFAULT_STORAGE_CHANGE,
    SRV_PLST_CB_EVT_MSDC_ENTRY_UNMOUNT,
    SRV_PLST_CB_EVT_MSDC_EXIT_UNMOUNT,
    SRV_PLST_CB_EVT_ACTIVE_LIST_INVALID,
    SRV_PLST_CB_EVT_DELETE_FROM_FMGR,
    SRV_PLST_CB_EVT_UPDATE_ARTWORK,
    SRV_PLST_CB_EVT_ADD_PROGRESS,
    SRV_PLST_CB_EVT_DELETE_PROGRESS,
    SRV_PLST_CB_EVT_STORE_ACTIVE,
    SRV_PLST_CB_EVT_TOTAL	
}srv_plst_cb_evt_enum;


/*call back function for notify events
  user_data:reserve for caller, normal used in multi-instanace
  cb_event:see srv_list_cb_evt_enum
  cb_para   :events attached parameter
*/
typedef S32 (*cb_func)(void* user_data, srv_plst_cb_evt_enum cb_event, S32 cb_para_1, U32 cb_para_2);

/* player list service create structure */
typedef struct
{
    void  *mem_ptr;     /* memory for create service handle, it should be the KAL_ADM_ID return by kal_adm_create() */
    U32   mem_size;     /* total memory size */
    U32   db_mem_size;  /* memory size reserve for SQLite database */
    U32   gen_mem_size; /* memory size reserve for generate database, ie. sizeof(srv_plst_gen_lib_context_struct) */
    U32   max_item_support;  /* max list item support */
}srv_plst_create_struct;


/*****************************************************************************
 * FUNCTION
 *  srv_plst_default_playlist_configure
 * DESCRIPTION
 *   set the configure of default playlist, set it before SRV_PLST_CMD_LIBRARY_OPEN, and only call once after service created    
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 *  default_flag :         [IN]   default play list configure info  
 * Sample
 *     default_flag   SRV_PLST_DEFAULT_RECENTLY_PLST|SRV_PLST_DEFAULT_MOST_PLST
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_default_playlist_configure(U32 srv_plst_hdr, U32 default_flag);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_default_playlist_configure
 * DESCRIPTION
 *   get the default playlist type by index that selected index from lib   
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 *  index        :         [IN]   index in current   
 *  default_type :         [OUT]   SRV_PLST_DEFAULT_RECENTLY_PLST or SRV_PLST_DEFAULT_MOST_PLST etc
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
extern S32 srv_plst_default_playlist_get_type(U32 srv_plst_hdr, U32 index, U32* default_type);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_library_open
 * DESCRIPTION
 *   open the DB library and create/check DB, table, fill the default,after service is created, this action only do once time
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 *  name         :         [IN]   db name
 *  open_flag    :         [IN]   see srv_plst_open_flag_enum
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
extern S32 srv_plst_library_open(U32 srv_plst_hdr, UI_string_type name, srv_plst_open_flag_enum open_flag);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_library_stop_open
 * DESCRIPTION
 *   stop open lib after last open return is SRV_PLST_ASYNC
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 *  name         :         [IN]   db name
 *  open_flag    :         [IN]   see srv_plst_open_flag_enum
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
extern S32 srv_plst_library_stop_open(U32 srv_plst_hdr);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_library_close
 * DESCRIPTION
 *   close the DB library before destory service
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_library_close(U32 srv_plst_hdr);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_library_update
 * DESCRIPTION
 *   add/update DB data (sync in another task PLS), scan the file system to find all media file 
 *        and then add to library by the class of audio/video. It need a long time, so use internal msg in the PLS 
 *       the find operation 
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_library_update(U32 srv_plst_hdr);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_library_stop_udpate
 * DESCRIPTION
 *   stop udpate DB, stop the udpate, use current data state when app query 
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_library_stop_udpate(U32 srv_plst_hdr);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_library_pause_update
 * DESCRIPTION
 *   pause udpate DB, between pause and resume, no any other service api can be called
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_library_pause_update(U32 srv_plst_hdr);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_library_stop_udpate
 * DESCRIPTION
 *   resume  udpate DB, between pause and resume, no any other service api can be called
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_library_resume_update(U32 srv_plst_hdr);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_library_add
 * DESCRIPTION
 *   add file or add from folder to library,  similiar like srv_plst_library_udpate, but this cmd is only scan the input path,not all drives
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 *  path         :         [IN]   filepath or folder path
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_library_add(U32 srv_plst_hdr, UI_string_type path);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_library_stop_add
 * DESCRIPTION
 *   stop add, smiliar like srv_plst_library_stop_udpate
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
extern S32 srv_plst_library_stop_add(U32 srv_plst_hdr);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_reset_all_list
 * DESCRIPTION
 *   clear service list info (temp function for APP)
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_reset_all_list(U32 srv_plst_hdr);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_set_temp_memory
 * DESCRIPTION
 *   set temp memory for list cache to speed up the view
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  mem_ptr            :         [IN]   temp memory ptr
 *  mem_size           :         [IN]   temp_mem_size
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
extern S32 srv_plst_set_temp_memory(U32 srv_plst_hdr, void** mem_ptr, U32 mem_size);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_set_temp_memory
 * DESCRIPTION
 *   clear temp memory for list cache to speed up the view
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  mem_ptr            :         [IN]   temp memory ptr
 *  mem_size           :         [IN]   temp_mem_size
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
extern S32 srv_plst_clear_temp_memory(U32 srv_plst_hdr);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_clear_curr_view_cache
 * DESCRIPTION
 *  clear up current view stack cache for the skip query data from pls
 *  notes: this api will not effect parent_id and total num for curr view
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_clear_curr_view_cache(U32 srv_plst_hdr, MMI_BOOL clear_count);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_clear_active_list
 * DESCRIPTION
 *  clear up active playing list info
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_clear_active_list(U32 srv_plst_hdr);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_entry
 * DESCRIPTION
 *   use it as a first filter type, such as all audio list, all video list, artist list, album list
                   entry list type , set it each entry a filter, artist, artist'album ,album,all audio etc
                   but if you need entry artist first and then entry artist'album, you need code as below: 
                   SRV_PLST_CMD_LIST_ENTRY (SRV_PLST_VIEW_ROOT, SRV_PLST_VIEW_ARTIST )
                   SRV_PLST_CMD_LIST_ENTRY (2 ,SRV_PLST_VIEW_ALBUM)
                   SRV_PLST_CMD_LIST_EXIT
                   SRV_PLST_CMD_LIST_EXIT	
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  list_view_param    :         [IN]   see srv_plst_list_view_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
extern S32 srv_plst_list_entry(U32 srv_plst_hdr, srv_plst_list_view_struct *list_view_param );


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_exit
 * DESCRIPTION
 *   set this cmd when exit the filter type, include the sub filter, such as artist'album
                      exit current list type, deinit
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
extern S32 srv_plst_list_exit(U32 srv_plst_hdr);   
 
    
/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_fixed_count
 * DESCRIPTION
 *   to get the count of fixed view
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  count              :         [IN]   count of selected
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
extern S32 srv_plst_list_get_fixed_count(U32 srv_plst_hdr, srv_plst_fixed_count_struct *view,  U32* count);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_item_count
 * DESCRIPTION
 *   to get the count of current list,artist id , album id or playlist id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  count              :         [IN]   count of selected
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
extern S32 srv_plst_list_get_item_count(U32 srv_plst_hdr, U32 *count);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_item_display
 * DESCRIPTION
 *  get the item display info such as name, set this action when need get item info to show 
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  item_display       :         [IN]   see srv_plst_list_get_display_struct idx:[IN] item index , buff_size: [IN]  buffer size buff_ptr:[out] buffer_point
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
extern S32 srv_plst_list_get_item_display(U32 srv_plst_hdr, srv_plst_list_get_display_struct* item_display);


#ifdef __PLST_SRV_FEATURE_GROUP_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_item_jumpto
 * DESCRIPTION
 *  during show list, make the list jump to the special location
 *  it's a special function, for list service performance not so good to any index, only can to specical prefix alphabet
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  jump_to_info       :         [IN]   such as "A - Z" "a - z" "#" and # is specail for not belong to "A- Z" "a - z"
 *  index              :         [OUT]  the index of the specical alphabet in the list
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
extern S32 srv_plst_list_item_jumpto(U32 srv_plst_hdr, U32 jump_to_info, U32* index);
#endif /* __PLST_SRV_FEATURE_GROUP_LIST__ */

/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_item_id
 * DESCRIPTION
 *  get the item id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index       :         [IN]   
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
extern S32 srv_plst_list_get_item_id(U32 srv_plst_hdr, S32 index, U32 *id);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_prefix_search_begin
 * DESCRIPTION
 *  prefix search for input text for artist/ album/all tracks
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_prefix_search_begin(U32 srv_plst_hdr);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_prefix_search_do_search
 * DESCRIPTION
 *  prefix search for input text for artist/ album/all tracks
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  item_display       :         [IN]   string searched           
 *  count              :         [OUT]  count                                               
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_prefix_search_do_search(U32 srv_plst_hdr, U32 string, U32* count);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_prefix_search_get_display
 * DESCRIPTION
 *  get the tile for show the prefix search result
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  param_display      :         [IN/OUT]   see srv_plst_list_get_display_struct idx:[IN] item index , buff_size: [IN]  buffer size buff_ptr:[out] buffer_point          
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern  S32 srv_plst_list_prefix_search_get_display(U32 srv_plst_hdr, srv_plst_list_get_display_struct* param_display);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_prefix_search_end
 * DESCRIPTION
 *  exit prefix search
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle                                    
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_prefix_search_end(U32 srv_plst_hdr);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_hint_count
 * DESCRIPTION
 *   to get the count of sub item for hint show
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   sub item index 
 *  count              :         [IN]   count of selected
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
extern S32 srv_plst_list_get_hint_count(U32 srv_plst_hdr, U32 index, U32* count);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_hint_count_ex
 * DESCRIPTION
 *   to get the count of sub item for hint show
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   sub item index 
 *  count              :         [IN]   count of selected
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
extern S32 srv_plst_list_get_hint_count_ex(U32 srv_plst_hdr, U32 index, srv_plst_view_type_enum get_count_type, U32* count);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_artwork_parser_path_by_media_id
 * DESCRIPTION
 *  get the path the file path that used to parse artwork
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index       :         [IN]   
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
S32 srv_plst_list_get_artwork_parser_path_by_media_id(U32 srv_plst_hdr, srv_plst_list_get_display_struct* param_artwork_path);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_item_artwork
 * DESCRIPTION
 *   get the artwokdata of selected album(blocking)
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   sub item index 
 *  param_artwork      :         [OUT]  see srv_plst_list_get_display_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_get_item_artwork(U32 srv_plst_hdr, srv_plst_list_get_display_struct* param_artwork);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_item_artwork_async
 * DESCRIPTION
 *   get the artwokdata of selected album(non blocking)
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   sub item index 
 *  param_artwork      :         [OUT]  see srv_plst_list_get_display_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_get_item_artwork_async(U32 srv_plst_hdr, srv_plst_list_get_display_struct* param_artwork);

extern S32 srv_plst_list_update_item_artwork(U32 srv_plst_hdr, U32 index, UI_string_type path);
extern S32 srv_plst_list_update_item_artwork_async(U32 srv_plst_hdr, U32 index, UI_string_type path);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_item_artwork_async_stop
 * DESCRIPTION
 *   stop the getting the artwokdata of selected album(non blocking)
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   sub item index 
 *  param_artwork      :         [OUT]  see srv_plst_list_get_display_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_get_item_artwork_async_stop(U32 srv_plst_hdr);

extern S32 srv_plst_list_stop_update_item_artwork(U32 srv_plst_hdr);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_artwork_by_media_id
 * DESCRIPTION
 *   get the artwokdata of selected media id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  param_artwork      :         [OUT]  see srv_plst_list_get_display_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_get_artwork_by_media_id(U32 srv_plst_hdr, srv_plst_list_get_display_struct* param_artwork);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_media_add_to_playlist
 * DESCRIPTION
 *   add the selected media/ artist id/ album id to playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   index  >=0 add selected type/index to playlist; -1  add marked server to playlist 
 *  param_artwork      :         [OUT]  see srv_plst_list_get_display_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_media_add_to_playlist(U32 srv_plst_hdr, S32 index, U32 plst_idx);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_media_stop_add_to_playlist
 * DESCRIPTION
 *   stop add the selected media/ artist id/ album id to playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   index  >=0 add selected type/index to playlist; -1  add marked server to playlist 
 *  param_artwork      :         [OUT]  see srv_plst_list_get_display_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_media_stop_add_to_playlist(U32 srv_plst_hdr);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_media_get_id
 * DESCRIPTION
 *   get the current id in current list, and return media_id when in song list
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   index
 *  id_info            :         [OUT]  see srv_plst_list_item_info
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_media_get_id(U32 srv_plst_hdr, U32 index, U32* id);
      
      
/*****************************************************************************
 * FUNCTION
 *  srv_plst_media_get_path
 * DESCRIPTION
 *  get the path of select media
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  param_display      :         [IN/OUT]   see srv_plst_list_get_display_struct idx:[IN] item index , buff_size: [IN]  buffer size buff_ptr:[out] buffer_point          
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_media_get_path(U32 srv_plst_hdr, srv_plst_list_get_display_struct* path_info);
      
/*****************************************************************************
 * FUNCTION
 *  srv_plst_media_get_details
 * DESCRIPTION
 *   get the details of the selected media_id, the detail info check srv_plst_media_details_struct
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  id_info            :         [IN]   see srv_plst_list_item_info
 *  details            :         [OUT]  see srv_plst_media_details_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/
extern S32 srv_plst_media_get_details(U32 srv_plst_hdr, U32 id, srv_plst_media_details_struct *details_info);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_media_get_details
 * DESCRIPTION
 *   get the details of the selected media_id, the detail info check srv_plst_media_details_struct
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  id_info            :         [IN]   see srv_plst_list_item_info
 *  details            :         [OUT]  see srv_plst_media_details_struct
 *  field              :         [IN]   only get specific fields (under construction)
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/
extern S32 srv_plst_media_get_details_by_filter(U32 srv_plst_hdr, U32 id, srv_plst_media_details_struct *details_info, U32 field);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_media_get_details
 * DESCRIPTION
 *  update the details of the select media_id, the detail info check srv_plst_media_details_struct
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  id_info            :         [IN]   see srv_plst_list_item_info
 *  details            :         [IN]  see srv_plst_media_details_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/      
extern S32 srv_plst_media_update_details(U32 srv_plst_hdr, U32 id_info, srv_plst_media_details_struct* details_info);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_store_active_info
 * DESCRIPTION
 *  update the current playing info to service database
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/      
extern S32 srv_plst_plst_store_active_info(U32 srv_plst_hdr);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_media_update_playing_info
 * DESCRIPTION
 *  update the play count and play time of the select media_id(current playing media) after played in the app
 *   use applib_dt_get_date_time get current time and use applib_dt_mytime_2_utc_sec to store db as current playing time
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_media_update_playing_info(U32 srv_plst_hdr);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_multi_select_mark_begin
 * DESCRIPTION
 *  begin multi mark 
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_multi_select_mark_begin(U32 srv_plst_hdr);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_multi_select_mark_end
 * DESCRIPTION
 *  end multi mark 
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_multi_select_mark_end(U32 srv_plst_hdr);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_multi_select_set_mark
 * DESCRIPTION
 *  mark the select or unmark when multi-select
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   item index
 *  is_mark            :         [IN]   MMI_TRUE:  mark   MMI_FALSE: unmark
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_multi_select_set_mark(U32 srv_plst_hdr, U32 index, MMI_BOOL is_mark);

    
/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_multi_select_get_mark
 * DESCRIPTION
 *  get the mark the select or unmar state when multi-select in current list
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   item index
 *  is_mark            :         [OUT]   MMI_TRUE:  mark   MMI_FALSE: unmark
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_multi_select_get_mark(U32 srv_plst_hdr, U32 index, MMI_BOOL* is_mark);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_multi_select_mark_all
 * DESCRIPTION
 *  mark/ unmark all current list when multi-select
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  is_mark            :         [OUT]   MMI_TRUE:  mark   MMI_FALSE: unmark
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_multi_select_mark_all(U32 srv_plst_hdr, MMI_BOOL is_mark);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_set_as_active
 * DESCRIPTION
 *  set the current index to active and update into database
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   active index
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_set_as_active(U32 srv_plst_hdr, U32 index);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_set_as_active_ex
 * DESCRIPTION
 *  set the current index to active , 
 *  if update_db is false, update to DB by using srv_plst_list_update_current_active_to_db()
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   active index
 *  update_db          :         [IN]   is update to DB after set active
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_set_as_active_ex(U32 srv_plst_hdr, U32 index, MMI_BOOL update_db);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_update_current_active_to_db
 * DESCRIPTION
 *  Use current playing info in the context and update it to database table
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_update_current_active_to_db(U32 srv_plst_hdr);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_item_delete
 * DESCRIPTION
 *  delete the selected/ multi-select item, or artist id, album id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   item index 
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_item_delete(U32 srv_plst_hdr, U32 index);  

/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_item_stop_delete
 * DESCRIPTION
 *  stop delete the selected/ multi-select item, or artist id, album id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   item index 
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_item_stop_delete(U32 srv_plst_hdr, U32 *count); 
 
/*****************************************************************************
 * FUNCTION
 *  srv_plst_get_plst_index_by_name
 * DESCRIPTION
 *   To query playlist index by input playlist name
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  name               :         [IN]   playlist name
 *  index            :           [OUT]  plst index
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_get_plst_index_by_name(U32 srv_plst_hdr, UI_string_type name, U32* index);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_create
 * DESCRIPTION
 *   create new playlist, unable to create a exist name 
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  name               :         [IN]   playlist name
 *  id_info            :         [OUT]  playlist id info in the db  see srv_plst_list_item_info
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_create(U32 srv_plst_hdr, UI_string_type name, U32* id_info);    

 
/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_delete
 * DESCRIPTION
 *  delete the selected playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   index
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_delete(U32 srv_plst_hdr, U32 index);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_stop_delete
 * DESCRIPTION
 *  delete the selected playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   index
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_stop_delete(U32 srv_plst_hdr, U32 *count);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_rename
 * DESCRIPTION
 *  rename the selected playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  name               :         [IN]   new name 
 *  index              :         [IN]   index
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_rename(U32 srv_plst_hdr, UI_string_type name, U32 index);
 

/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_get_plst_id
 * DESCRIPTION
 *   get plst_id of the selected  playlist
 *       this action only used in all playlist's list
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   index
 *  id_info            :         [OUT]  U32 
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_get_plst_id(U32 srv_plst_hdr, U32 index, U32 *id_info);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_get_active_plst_id
 * DESCRIPTION
 *   get active playing list id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  id                 :         [OUT]  U32 
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_get_active_plst_id(U32 srv_plst_hdr, U32 *id);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_get_active_plst_item_index
 * DESCRIPTION
 *  get playing item index
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [OUT]  U32
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/
extern S32 srv_plst_plst_get_active_plst_item_index(U32 srv_plst_hdr, U32* index);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_get_active_plst_item_count
 * DESCRIPTION
 *  get playing item count
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  count              :         [OUT]  U32
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/
extern S32 srv_plst_get_active_plst_item_count(U32 srv_plst_hdr, U32 *count);

#ifdef __PLST_SRV_DEFAULT_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_default_list_entry
 * DESCRIPTION
 *  entry default list
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_default_list_entry(U32 srv_plst_hdr,srv_plst_default_playlist_enum def_list);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_default_list_exit
 * DESCRIPTION
 *  exit default list
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_default_list_exit(U32 srv_plst_hdr);
#endif /* __PLST_SRV_DEFAULT_LIST__ */

/*****************************************************************************
 * FUNCTION
 *  srv_plst_get_active_list_media_type
 * DESCRIPTION
 *  get media type of active list
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  srv_plst_active_list_media_type_enum  
 *****************************************************************************/ 
extern srv_plst_active_list_media_type_enum srv_plst_get_active_list_media_type(U32 srv_plst_hdr);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_remove
 * DESCRIPTION
 *  remove the item form the playlist 
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   index
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_item_remove(U32 srv_plst_hdr, U32 index);



/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_stop_remove
 * DESCRIPTION
 *  remove the item form the playlist 
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   index
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_item_stop_remove(U32 srv_plst_hdr, U32* count);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_check_exist_in_plst
 * DESCRIPTION
 *  check the selected if exist in playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  flag               :         [IN]   MMI_TRUE/ MMI_FALSE
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_config_set_media_unique_in_plst(U32 srv_plst_hdr, MMI_BOOL flag);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_reorder_begin
 * DESCRIPTION
 *  begin reorder play list item
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_item_reorder_begin(U32 srv_plst_hdr);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_reorder_get_display
 * DESCRIPTION
 *  get reorder display
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_item_reorder_get_display(U32 srv_plst_hdr,srv_plst_list_get_display_struct * param_display);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_reorder_action
 * DESCRIPTION
 *  re_order the list sequeue 
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index_orign        :         [IN]   origin location index
 *  index_dest         :         [IN]   destination location idnex *  
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_item_reorder_action(U32 srv_plst_hdr, U32 index_orign, U32 index_dest);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_reorder_action_set_result
 * DESCRIPTION
 *  reorder playlist end
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_item_reorder_action_set_result(U32 srv_plst_hdr, MMI_BOOL save_notice);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_reorder_end
 * DESCRIPTION
 *  reorder playlist end
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_item_reorder_end(U32 srv_plst_hdr);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_clear
 * DESCRIPTION
 *  clear current playlist's all item
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_item_clear(U32 srv_plst_hdr);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_stop_clear
 * DESCRIPTION
 *  cancel the clear current playlist's all items action
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_item_stop_clear(U32 srv_plst_hdr, U32* count);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_get_active_media_info_auto
 * DESCRIPTION
 *  get the previouse playing media info: id, storage_id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  param_struct       :         [OUT]  see srv_plst_list_item_info  param_a: media_id, param_b:  storage_id
 *  path               :         [OUT]  media's filepath
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_item_get_active_media_info_auto(U32 srv_plst_hdr, U32* id , U32* index, UI_string_type path);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_get_active_media_info_manul_prev
 * DESCRIPTION
 *  get the previouse playing media info: id, storage_id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  param_struct       :         [OUT]  see srv_plst_list_item_info  param_a: media_id, param_b:  storage_id
 *  path               :         [OUT]  media's filepath
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_item_get_active_media_info_manul_prev(U32 srv_plst_hdr, U32* id, U32* index, UI_string_type path);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_get_active_media_info_manul_next
 * DESCRIPTION
 *  get the next playing media info: id, storage_id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  param_struct       :         [OUT]  see srv_plst_list_item_info  param_a: media_id, param_b:  storage_id
 *  path               :         [OUT]  media's filepath
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_item_get_active_media_info_manul_next(U32 srv_plst_hdr,U32* id, U32* index, UI_string_type path);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_get_active_media_info_curr
 * DESCRIPTION
 *  get current playing media info: id, storage_id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  param_struct       :         [OUT]  see srv_plst_list_item_info  param_a: media_id, param_b:  storage_id
 *  path               :         [OUT]  media's filepath
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_plst_item_get_active_media_info_curr(U32 srv_plst_hdr, U32* id, U32* index, UI_string_type path);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_get_active_list_type
 * DESCRIPTION
 *  get media type of active list
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  srv_plst_active_list_media_type_enum  
 *****************************************************************************/ 
srv_plst_active_list_enum srv_plst_get_active_list_type(U32 srv_plst_hdr);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_context_by_id
 * DESCRIPTION
 *  get context of input id and input type
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  in_param           :         [OUT]  see srv_plst_get_cntx_param_struct
 *  out_pram           :         [OUT]  srv_plst_get_context_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_list_get_context_by_id(U32 srv_plst_hdr, srv_plst_get_cntx_param_struct *in_param, srv_plst_get_context_struct *out_pram);
 


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_context
 * DESCRIPTION
 *  get context of input id and input type
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  in_param           :         [OUT]  see srv_plst_get_cntx_param_struct
 *  out_pram           :         [OUT]  srv_plst_get_cntx_output_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
//extern S32 srv_plst_list_get_context(U32 srv_plst_hdr, srv_plst_get_cntx_param_struct *in_param, 
                                     //          srv_plst_get_cntx_output_struct *out_pram);
 
 
/*****************************************************************************
 * FUNCTION
 *  srv_plst_config_set_plst_order
 * DESCRIPTION
 *  confige the playlist show sequeues, it can be default list show at first or default list show at last
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  order              :         [IN]   see srv_plst_plst_show_sequeue_enum  
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_config_set_plst_order(U32 srv_plst_hdr, srv_plst_plst_show_sequeue_enum order);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_config_shuffle
 * DESCRIPTION
 *  set shuffle info
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  shuffle            :         [IN]   see srv_plst_shuffle_enum  
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_config_shuffle(U32 srv_plst_hdr, srv_plst_shuffle_enum shuffle);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_config_repeat
 * DESCRIPTION
 *  set repeat info
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  shuffle            :         [IN]   see srv_plst_repeat_enums  
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_config_repeat(U32 srv_plst_hdr, srv_plst_repeat_enum repeat);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_config_info
 * DESCRIPTION
 *  config infomation, if not configure, service will use default value
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  config_type        :         [IN]   see srv_plst_config_type_enum
 *  config_value       :         [IN]   differrent enum when the config type change
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_config_info(U32 srv_plst_hdr, srv_plst_config_type_enum config_type, U32 config_value);


extern MMI_BOOL srv_plst_check_sort_type_support(U32 srv_plst_hdr, srv_plst_list_sort_type_enum type);
extern S32 srv_plst_list_item_get_group_count(U32 srv_plst_hdr, srv_plst_list_group_item_info_struct* group_c);
extern S32 srv_plst_list_search_async(U32 srv_plst_hdr, U32 string);
extern S32 srv_plst_list_search_sync(U32 srv_plst_hdr, U32 string, U32* count);
extern S32 srv_plst_default_playlist_get_type_info_by_id(U32 srv_plst_hdr, U32 id, srv_plst_default_playlist_enum *type);


/*****************************************************************************
 * FUNCTION
 *  srv_list_create
 * DESCRIPTION
 *  create list service, get memory from caller
 * PARAMETERS
 *  result                :  [OUT]     error code
 *  srv_list_create_struct:  [IN]      service create stucture
 *  callback              :  [IN]      see the callback define
 *  create_struct         :  [IN]      see srv_plst_create_struct
 * RETURNS
 *  return service handle
 *****************************************************************************/ 
extern U32 srv_plst_create(S32* result, 
                    void* user_data, 
                    S32 (*callback)(void* user_data, srv_plst_cb_evt_enum cb_event, S32 result, U32 ca_para), 
                    srv_plst_create_struct* create_struct);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_destroy_for_realloc_memory
 * DESCRIPTION
 *  Close DB, get context memory and destroy db for later recreate
 * PARAMETERS
 *  srv_plst_hdr          :  [IN]      db handle
 *  memory_ptr            :  [IN]      memory buffer pointer
 *  memory_size           :  [IN]      memory buffer size
 * RETURNS
 *  get result
 *****************************************************************************/
S32 srv_plst_destroy_for_realloc_memory(U32 srv_plst_hdr, void* memory_ptr, U16 memory_size);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_realloc_memory
 * DESCRIPTION
 *  App close DB and free its instance, 
 *  then use this API to reopen it with new allocated memory without check integrality of DB
 * PARAMETERS
 *  result                :  [OUT]     error code
 *  srv_plst_hdr          :  [IN]      old db handle
 *  create_struct         :  [IN]      see srv_plst_create_struct
 *  original_db_context_hdr  :  [IN]      original memory context
 * RETURNS
 *  return new service handle
 *****************************************************************************/
extern U32 srv_plst_realloc_memory(S32* result, U32 srv_plst_hdr, srv_plst_create_struct* create, void* original_db_context_ptr);


/*****************************************************************************
 * FUNCTION
 *  srv_list_destory
 * DESCRIPTION
 *  reset, destory list service
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
extern S32 srv_plst_destroy(U32 srv_plst_hdr);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_msdc_plug_in_hdlr
 * DESCRIPTION
 *  plug in 
 * PARAMETERS
 *  drv_num     [IN]
 *  drv_list    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_plst_msdc_plug_in_hdlr(U8 drv_num, PU8 drv_list);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_msdc_plug_out_hdlr
 * DESCRIPTION
 *  plug in 
 * PARAMETERS
 *  drv_num     [IN]
 *  drv_list    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_plst_msdc_plug_out_hdlr(U8 drv_num, PU8 drv_list);

//#ifdef __MMI_USB_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_plst_usb_plug_in_hdlr
 * DESCRIPTION
 *  plug in 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_RET srv_plst_usb_plug_in_hdlr(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_usb_plug_out_hdlr
 * DESCRIPTION
 *  plug out 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_RET srv_plst_usb_plug_out_hdlr(mmi_event_struct *evt);
//#endif

/*****************************************************************************
 * FUNCTION
 *  srv_plst_pre_format_hdlr
 * DESCRIPTION
 *  pre format
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_plst_pre_format_hdlr(CHAR drv);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_aft_format_hdlr
 * DESCRIPTION
 *  pre format
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_plst_aft_format_hdlr(CHAR drv);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_msdc_entry_unmount
 * DESCRIPTION
 *  unmount 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_plst_msdc_entry_unmount(CHAR drv);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_msdc_exit_unmout
 * DESCRIPTION
 *  unmount 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_plst_msdc_exit_unmount(CHAR drv);

extern mmi_ret srv_plst_service_notify_hdlr(mmi_event_struct *event);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_check_file_is_delete
 * DESCRIPTION
 *  unmount 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

extern MMI_BOOL srv_plst_check_file_is_delete(CHAR *path, MMI_BOOL is_folder, MMI_BOOL is_delete_all, const FMGR_FILTER *filter);
    
/*****************************************************************************
 * FUNCTION
 *  srv_list_get_error_string
 * DESCRIPTION
 *  get list service error string id
 * PARAMETERS
 *  error code        :    [IN]   error code
 *  event_type        :    [OUT]  event type
 * RETURNS
 *  return error string id
 *****************************************************************************/ 
extern U32 srv_plst_get_error_string(S32 error_code, mmi_event_notify_enum *evt_type);


/*****************************************************************************
 * FUNCTION
 *  srv_plst_init
 * DESCRIPTION
 *  init when phone start, and before other app called it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
extern void srv_plst_init(void);

extern MMI_BOOL srv_plst_check_playlist_is_exist(U32 srv_plst_hdr, UI_string_type name);

extern MMI_BOOL srv_plst_check_active_media_is_in_playlist(U32 srv_plst_hdr, srv_plst_default_playlist_enum type);

extern S32 srv_plst_active_media_remove_from_playlist(U32 srv_plst_hdr, srv_plst_default_playlist_enum type);

extern S32 srv_plst_active_media_add_to_playlist(U32 srv_plst_hdr, srv_plst_default_playlist_enum type);
extern S32 srv_plst_media_get_id_in_group(U32 srv_plst_hdr, U32 group, U32 sub_index, U32 *id);

/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_get_active_index
 * DESCRIPTION
 *   get active index in current list, currently only support for cover flow active album index
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [OUT]  U32 
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/
S32 srv_plst_plst_get_active_index(U32 srv_plst_hdr, srv_plst_active_type_enum type,  U32 *index);


#endif /* __PLST_SERVICE_DB_SUPPORT__ */
#endif  /* __PLST_SERVICE_GPROT_H__ */

