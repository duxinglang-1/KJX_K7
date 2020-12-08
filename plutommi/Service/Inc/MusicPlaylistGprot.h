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
 *  MusicPlaylistGprot.h
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

#ifndef __MUSIC_PLAY_LIST_GPROT_H__
#define __MUSIC_PLAY_LIST_GPROT_H__

#include "FileMgrSrvGProt.h"
#include "meta_tag_api.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_data_types.h"
#include "mmi_rp_file_type_def.h"
#include "MMI_features.h"
#include "mmi_frm_events_gprot.h"


/* max length of each meta info */
#define SRV_PAYLIST_META_INFO_MAX_LEN      (META_TAG_FRAME_MAX_LEN)

// TODO:
#define SRV_PLAYLIST_MIN_MEM_SIZE          (25 * 1024)

/* playlist max item supported. */
#define SRV_PLAYLIST_MAX_PLAYLIST_ITEM     (1024)

/* max length of each meta info */
#define SRV_PLAYLIST_META_INFO_MAX_LEN     (META_TAG_FRAME_MAX_LEN)

#define SRV_PLAYLIST_MAX_FILE_LEN          (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1)
/* max filepath length */
#define SRV_PLAYLIST_MAX_PATH_LEN          (SRV_FMGR_PATH_MAX_LEN+1)
/* max file extension length*/
#define SRV_PLAYLIST_MAX_EXT_LEN           (SRV_FMGR_PATH_MAX_FILE_EXT_LEN)


//----------------------------------------------------------------------------------------
// data struct

typedef U32 plst_handle; /* play list service handle type. */

/* teo type shuffle mode*/
typedef enum
{
    SRV_PLAYLIST_SHUFFLE_OFF, /* shulffe off */
    SRV_PLAYLIST_SHUFFLE_ON,  /* shulffe on */
    SRV_PLAYLIST_SHUFFLE_MAX  /* end of enum */
}srv_playlist_shuffle_enum;

/* three type repeat mode */
typedef enum
{
    SRV_PLAYLIST_REPEAT_OFF, /* repeat off */
    SRV_PLAYLIST_REPEAT_ONE, /* repeat one */
    SRV_PLAYLIST_REPEAT_ALL, /* repeat all */
    SRV_PLAYLIST_REPEAT_MAX  /* end of enum */
}srv_playlist_repeat_enum;

/* play list service callback event */
typedef enum
{
    SRV_PLAYLIST_CB_EVT_OPEN,
    SRV_PLAYLIST_CB_EVT_ADD,
    SRV_PLAYLIST_CB_EVT_DELETE,
    SRV_PLAYLIST_CB_EVT_DELETE_ACTIVE,
    SRV_PLAYLIST_CB_EVT_DELETE_PROGRESS,
    SRV_PLAYLIST_CB_EVT_MSDC_PLUG_OUT,
    SRV_PLAYLIST_CB_EVT_MSDC_PLUG_IN,
    SRV_PLAYLIST_CB_EVT_PRE_FORMAT,
    SRV_PLAYLIST_CB_EVT_AFT_FORMAT,
    SRV_PLAYLIST_CB_EVT_MAX
}srv_playlist_cb_evt_enum;

/* play list service return value */
typedef enum
{
    SRV_PLAYLIST_OK = 0,                    /* api execute OK, no error */
    SRV_PLAYLIST_ASYNC,                     /* async mode, return result from user callback func */
    SRV_PLAYLIST_NEXT_LOOP,                 /* for repeat(all\one), one loop done, continue next. */
    SRV_PLAYLIST_FAILED = -1,
    SRV_PLAYLIST_ERR_BEGIN = -5000,
    SRV_PLAYLIST_ERR_VERSION_WRONG,         /* version wrong, api can popup or recall open */
    SRV_PLAYLIST_ERR_MEMORY_NOT_ENOUGH,
    SRV_PLAYLIST_ERR_FS_ERROR,
    SRV_PLAYLIST_ERR_BAD_PARA,
    SRV_PLAYLIST_ERR_UNSUPPORTED_FILE,      /* not supported file format. */
    SRV_PLAYLIST_ERR_FILE_DAMAGE,
    
    SRV_PLAYLIST_END  = -4980,
    SRV_PLAYLIST_PLST_FULL,                 /* playlist reach max items(1024). */
    SRV_PLAYLIST_DELETE_ACTIVE,    
    SRV_PLAYLIST_MSDC_NOTEXIST,             /* memory card not exit or in mass storage mode. */
    SRV_PLAYLIST_MAX                        /* end of enum */
}srv_playlist_return_value_enum;


/* play list instance create structure */
typedef struct
{
    void*  mem_ptr;           /* memory for create service handle, it should be the KAL_ADM_ID return by kal_adm_create() */
    U32    mem_size;          /* total memory size */
    U32    gen_mem_size;      /* memory size reserve for generate database, ie. sizeof(srv_plst_gen_lib_context_struct) */
    U32    max_item_support;  /* max list item support, defined by service. */
}srv_playlist_create_struct;

typedef struct
{
    UI_character_type filename[SRV_PLAYLIST_META_INFO_MAX_LEN + 1];    /* filename */
    UI_character_type title[SRV_PLAYLIST_META_INFO_MAX_LEN + 1];       /* title */
    UI_character_type artist[SRV_PLAYLIST_META_INFO_MAX_LEN + 1];      /* artist name */
    UI_character_type album[SRV_PLAYLIST_META_INFO_MAX_LEN + 1];       /* album name */
    UI_character_type author[SRV_PLAYLIST_META_INFO_MAX_LEN + 1];      /* author name */
    UI_character_type genre[SRV_PLAYLIST_META_INFO_MAX_LEN + 1];       /* genre */
    UI_character_type copyrights[SRV_PLAYLIST_META_INFO_MAX_LEN + 1];  /* copyrights */
    UI_character_type description[SRV_PLAYLIST_META_INFO_MAX_LEN + 1]; /* description */
    S32 duration;                                                      /* secend */
}srv_playlist_media_details_info_struct;


/*call back function for notify events
  user_data:reserve for caller, normal used in multi-instanace
  cb_event:see srv_list_cb_evt_enum
  cb_para   :events attached parameter
*/
typedef S32 (*cb_func)(void* user_data, srv_playlist_cb_evt_enum cb_event, S32 cb_para_1, U32 cb_para_2);

//----------------------------------------------------------------------------------------
// functions definition

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_create_instance
 * DESCRIPTION
 *  create list service, get memory from caller
 * PARAMETERS
 *  pPara  :  [IN]      service create stucture
 *  pHandle:  [OUT]     service handle
 * RETURNS
 *  return error code
 *****************************************************************************/ 
extern S32 srv_playlist_create_instance(srv_playlist_create_struct* pPara, U32* pHandle);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_destroy_instance
 * DESCRIPTION
 *  reset, destory list service
 * PARAMETERS
 *  srv_handle :  [IN]   service handle
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 srv_playlist_destroy_instance(U32 srv_handle);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_register_callback
 * DESCRIPTION
 *  register service callback, events about play list
 * PARAMETERS
 *  srv_handle:  [IN]     service handle
 *  callback  :  [IN]     service call back
 *  user_data :  [IN]     user data
 * RETURNS
 *  return void
 *****************************************************************************/ 
extern S32 srv_playlist_register_callback(U32 srv_handle, cb_func callback, void* user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_deregister_callback
 * DESCRIPTION
 *  deregister service callback, events about play list
 * PARAMETERS
 *  srv_handle:  [IN]     service handle
 * RETURNS
 *  return void
 *****************************************************************************/ 
extern void srv_playlist_deregister_callback(U32 srv_handle);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_open_library
 * DESCRIPTION
 *  open the input play list file
 * PARAMETERS
 *  srv_handle:  [IN]     service handle
 * RETURNS
 *  return error code
 *****************************************************************************/ 
S32 srv_playlist_open_library(U32 srv_handle);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_close_library
 * DESCRIPTION
 *  close play list file
 * PARAMETERS
 *  srv_handle:  [IN]     service handle
 * RETURNS
 *  return error code
 *****************************************************************************/ 
S32 srv_playlist_close_library(U32 srv_handle);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_get_item_title
 * DESCRIPTION
 *  get current viewed play list item title
 * PARAMETERS
 *  srv_handle:  [IN]     service handle
 *  index     :  [IN]     item index
 *  title     :  [OUT]    index item music title
 * RETURNS
 *  return error code
 *****************************************************************************/ 
S32 srv_playlist_get_item_title(U32 srv_handle, S32 index, UI_string_type title);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_get_item_title
 * DESCRIPTION
 *  get current viewed play list item full file path
 * PARAMETERS
 *  srv_handle:  [IN]     service handle
 *  index     :  [IN]     item index
 *  path      :  [OUT]    full file path
 * RETURNS
 *  return  short name: is_active == 2
            long name : is_active == 1
 *****************************************************************************/ 
S32 srv_playlist_get_item_path(U32 srv_handle, S32 index, UI_string_type path);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_get_list_count
 * DESCRIPTION
 *  get current played list item count
 * PARAMETERS
 *  srv_handle:  [IN]     service handle
 * RETURNS
 *  return  item count
 *****************************************************************************/ 
S32 srv_playlist_get_list_count(U32 srv_handle);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_get_active_index
 * DESCRIPTION
 *  get current played item index
 * PARAMETERS
 *  srv_handle:  [IN]     service handle
 * RETURNS
 *  return  item index
 *****************************************************************************/ 
S32 srv_playlist_get_active_index(U32 srv_handle);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_set_active_index
 * DESCRIPTION
 *  set index item as played
 * PARAMETERS
 *  srv_handle:  [IN]     service handle
 * RETURNS
 *  return  item index
 *****************************************************************************/ 
S32 srv_playlist_set_as_active(U32 srv_handle, S32 index);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_get_active_info
 * DESCRIPTION
 *  get next music info
 * PARAMETERS
 *  srv_handle:  [IN]     service handle
 *  index     :  [OUT]    next item index
 *  path      :  [OUT]    next item file full path
 * RETURNS
 *  return  item index
 *****************************************************************************/ 
S32 srv_playlist_get_active_info(U32 srv_handle, S32* index, UI_string_type path);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_get_next_item_info
 * DESCRIPTION
 *  auto get next music info and set as active
 * PARAMETERS
 *  srv_handle:  [IN]     service handle
 *  index     :  [OUT]    next item index
 *  path      :  [OUT]    next item file full path
 * RETURNS
 *  return  item index
 *****************************************************************************/ 
S32 srv_playlist_get_next_auto(U32 srv_handle, S32* index, UI_string_type path);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_get_next_item_info
 * DESCRIPTION
 *  get next music info and set as active
 * PARAMETERS
 *  srv_handle:  [IN]     service handle
 *  index     :  [OUT]    next item index
 *  path      :  [OUT]    next item file full path
 * RETURNS
 *  return  item index
 *****************************************************************************/ 
S32 srv_playlist_get_next_manul(U32 srv_handle, S32* index, UI_string_type path);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_get_prev_manul
 * DESCRIPTION
 *  get prev music info and set as active
 * PARAMETERS
 *  srv_handle:  [IN]     service handle
 *  index     :  [OUT]    prev item index
 *  path      :  [OUT]    prev item file full path
 * RETURNS
 *  return  item index
 *****************************************************************************/ 
S32 srv_playlist_get_prev_manul(U32 srv_handle, S32* index, UI_string_type path);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_multi_mark_begin
 * DESCRIPTION
 *  begin multi mark
 * PARAMETERS
 *  srv_handle:  [IN]   service handle
 * RETURNS
 *  return error code:   < 0 error code
 *                       >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_playlist_multi_select_mark_begin(U32 srv_handle);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_multi_mark_end
 * DESCRIPTION
 *  end multi mark
 * PARAMETERS
 *  srv_handle:  [IN]   service handle
 * RETURNS
 *  return error code:   < 0 error code
 *                       >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_playlist_multi_select_mark_end(U32 srv_handle);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_multi_select_set_mark
 * DESCRIPTION
 *  mark the select or unmark when multi-select
 * PARAMETERS
 *  srv_handle:   [IN]   service handle
 *  index     :   [IN]   item index
 *  is_mark   :   [IN]   MMI_TRUE:  mark   MMI_FALSE: unmark
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_playlist_multi_select_set_mark(U32 srv_handle, U32 index, MMI_BOOL is_mark);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_multi_select_get_mark
 * DESCRIPTION
 *  get the mark the select or unmar state when multi-select in current list
 * PARAMETERS
 *  srv_handle:    [IN]   service handle
 *  index     :    [IN]   item index
 *  is_mark   :    [OUT]  MMI_TRUE:  mark   MMI_FALSE: unmark
 * RETURNS
 *  MMI_TRUE  :    marked  
 *  MMI_FALSE :    unmarked
 *****************************************************************************/ 
MMI_BOOL srv_playlist_multi_select_get_mark(U32 srv_handle, U32 index);

/*****************************************************************************
* FUNCTION
*  srv_playlist_multi_select_get_mark_all
* DESCRIPTION
*  get if marked all items
* PARAMETERS
*  srv_handle:    [IN]   service handle
* RETURNS
* RETURNS
*  MMI_TRUE  :    marked all  
*  MMI_FALSE :    unmarked all
*****************************************************************************/ 
MMI_BOOL srv_playlist_multi_select_get_mark_all(U32 srv_handle);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_multi_select_mark_all
 * DESCRIPTION
 *  mark/ unmark all current list when multi-select
 * PARAMETERS
 *  srv_handle:    [IN]   service handle
 *  is_mark   :    [OUT]  MMI_TRUE:  mark   MMI_FALSE: unmark
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_playlist_multi_select_mark_all(U32 srv_handle, MMI_BOOL is_mark);

 /*****************************************************************************
 * FUNCTION
 *  srv_playlist_delete_item
 * DESCRIPTION
 *  delete the selected item
 * PARAMETERS
 *  srv_handle:    [IN]   service handle
 *  index     :    [IN]   item index
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_playlist_delete_item(U32 srv_handle, U32 index);

 /*****************************************************************************
 * FUNCTION
 *  srv_playlist_delete_marked_item
 * DESCRIPTION
 *  delete the multi marked item
 * PARAMETERS
 *  srv_handle:    [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_playlist_delete_marked_item(U32 srv_handle);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_delete_cancel
 * DESCRIPTION
 *  cancel current delete operation
 * PARAMETERS
 *  srv_handle:    [IN]   service handle
 *  count     :    [OUT]  current list item count after delete
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_playlist_delete_cancel(U32 srv_handle);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_add_file
 * DESCRIPTION
 *   add a input file to current viewed library
 * PARAMETERS
 *  srv_handle:    [IN]   service handle
 *  file_path :    [IN]   filepath or folder path
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_playlist_add_file(U32 srv_handle, UI_string_type file_path);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_add_from_folder
 * DESCRIPTION
 *   search and add files from input folder to library, not all drivers
 * PARAMETERS
 *  srv_handle :    [IN]   service handle
 *  folder_path:    [IN]   filepath or folder path
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_playlist_add_from_folder(U32 srv_handle, UI_string_type folder_path);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_add_file_cancel
 * DESCRIPTION
 *   cancel search file
 * PARAMETERS
 *  srv_handle :    [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_playlist_add_file_cancel(U32 srv_handle);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_config_shuffle
 * DESCRIPTION
 *  set shuffle info
 * PARAMETERS
 *  srv_handle:    [IN]   service handle
 *  shuffle   :    [IN]   see srv_playlist_shuffle_enum  
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_playlist_config_shuffle(U32 srv_handle, srv_playlist_shuffle_enum shuffle);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_config_repeat
 * DESCRIPTION
 *  set repeat info
 * PARAMETERS
 *  srv_handle:     [IN]   service handle
 *  shuffle   :     [IN]   see srv_playlist_repeat_enum  
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_playlist_config_repeat(U32 srv_handle, srv_playlist_repeat_enum repeat);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_get_shuffle
 * DESCRIPTION
 *  set shuffle info
 * PARAMETERS
 *  srv_handle:    [IN]   service handle
 * RETURNS
 *  return srv_playlist_shuffle_enum
 *****************************************************************************/ 
srv_playlist_shuffle_enum srv_playlist_get_shuffle(U32 srv_handle);

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_get_repeat
 * DESCRIPTION
 *  set repeat info
 * PARAMETERS
 *  srv_handle:     [IN]   service handle
 *  shuffle   :     [IN]   see srv_playlist_repeat_enum  
 * RETURNS
 *  return srv_playlist_repeat_enum
 *****************************************************************************/ 
srv_playlist_repeat_enum srv_playlist_get_repeat(U32 srv_handle);

#endif  //__MMI_PLAYLIST_SERVICE_SLIM__
#endif  //__MUSIC_PLAY_LIST_GPROT_H__
