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
 *  PlstSrvpls.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  player list service
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PLAY_LIST_SERVICE_PLS_H__
#define __PLAY_LIST_SERVICE_PLS_H__
#ifdef __PLST_SERVICE_DB_SUPPORT__
#include "PlstSrvGprot.h"
#include "PlstSrv.h"
#include "PlstSrvMsgStruct.h"

#include "gdi_include.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "FileMgrSrvGProt.h"
#include "gui_data_types.h"
#include "kal_public_defs.h"
#include "meta_tag_api.h"
#include "sqlite3ex.h"
#define SRV_PLS_MIN_ARTWORK_SIZE     (SRV_PLST_ARTWORK_RESIZED_WIDTH*SRV_PLST_ARTWORK_RESIZED_HEIGHT*(GDI_MAINLCD_BIT_PER_PIXEL / 8))
#define SRV_PLST_SELECT_SQL_MIN_NUM  (20)


typedef enum
{
    PLS_DB_EVT_INIT            = 0X00000001,
    PLS_DB_EVT_DEINIT          = 0X00000002,
    PLS_DB_EVT_GET_DATA        = 0X00000004,
    PLS_DB_EVT_MARK            = 0X00000008,
    PLS_DB_EVT_DETAILS         = 0X00000010,
    PLS_DB_EVT_GET_ID          = 0X00000020,
    PLS_DB_EVT_CLOSE           = 0X00000040,
    PLS_DB_EVT_STOP_UPDATE     = 0X00000080,
    PLS_DB_EVT_PAUSE           = 0X00000100,
    PLS_DB_EVT_RESUME          = 0X00000200,
    PLS_DB_EVT_GET_ID2         = 0X00000400,
    PLS_DB_EVT_CREATE_PLST     = 0X00000800,
    PLS_DB_EVT_RENAME_PLST     = 0X00001000,
    PLS_DB_EVT_CREATE_MARK_TBL = 0X00002000,
    PLS_DB_EVT_GET_MARK        = 0X00004000,
    PLS_DB_EVT_SET_ACTIVE      = 0X00008000,
    PLS_DB_EVT_REORDER_PLST    = 0X00010000,
    PLS_DB_EVT_LOAD_ACTIVE_INO = 0X00020000,
    PLS_DB_EVT_GET_ACTIVE      = 0X00040000,
    PLS_DB_EVT_ACTION_CANCEL   = 0X00080000,
    PLS_DB_EVT_ADD_SINGLE      = 0X00100000,
    PLS_DB_EVT_DELETE_SINGLE   = 0X00200000,
    PLS_DB_EVT_OPEN_ONLY       = 0X00400000,
    PLS_DB_EVT_REORDER_RET     = 0X00800000,
    PLS_DB_EVT_ENTRY_LIST      = 0X01000000,
    PLS_DB_EVT_EXIT_LIST       = 0X02000000,
    PLS_DB_EVT_PLAY_CONFIG_RST = 0X04000000,
    PLS_DB_EVT_UPDATE_PLAY_INFO= 0X08000000,
    PLS_DB_EVT_GET_PLST_INDEX  = 0X10000000,
    PLS_DB_EVT_UPDATE_ACT_INDX,
    PLS_DB_EVT_CHECK_IN_PLST,
    PLS_DB_EVT_ACT_MED_AR_PLST,
    PLS_DB_EVT_CHECK_PLST_EXIST,
    PLS_DB_EVT_LIST_JUMP,
    PLS_DB_EVT_LIST_GROUP_DATA,
    PLS_DB_EVT_ENUM_END
}pls_db_event_enum;


typedef struct
{
    LOCAL_PARA_HDR
    srv_plst_db_context_struct *db_handle;
    cb_func callback;    
} pls_db_start_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srv_plst_db_context_struct *db_handle;    
    cb_func callback;    
    S32 result;
} pls_db_start_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srv_plst_db_context_struct *db_handle;
} pls_db_close_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srv_plst_db_context_struct *db_handle;
    srv_plst_security sec_ver;
    U8 drv_letter;
}pls_db_read_ver_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srv_plst_db_context_struct *db_handle;
    U8  drv_letter;
}pls_db_gen_lib_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srv_plst_db_context_struct *db_handle;
    UI_character_type path[(SRV_FMGR_PATH_MAX_LEN+1)];
    U32* ret_value;
    U32 index;
    U32 value;
    U8  drv_letter;
    cb_func callback;
} pls_db_exec_single_db_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srv_plst_db_context_struct *db_handle;
    srv_plst_get_cntx_param_struct *in_param;
    srv_plst_get_context_struct *out_param;
} pls_db_get_cntx_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srv_plst_db_context_struct *db_handle;
    srv_plst_active_type_enum type;
    U32 *index;
}pls_db_get_active_idx_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srv_plst_db_context_struct *db_handle;
    srv_plst_default_playlist_enum type;
} pls_db_act_media_op_plst_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srv_plst_db_context_struct *db_handle;
    U32 jump_info;
    U32 *ret_value;
} pls_db_list_jump_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srv_plst_db_context_struct *db_handle;
    UI_string_type  name;
} pls_db_check_plst_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srv_plst_db_context_struct *db_handle;
    U32 progress;
    U32 index;
    U32 value;
    cb_func callback;
    MMI_BOOL is_remove;
} pls_db_act_ar_media_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srv_plst_db_context_struct *db_handle;
} pls_db_exec_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srv_plst_db_context_struct *db_handle;
    S32 result;
    U32 index;
    U32 id;
    cb_func callback;
} pls_db_exec_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srv_plst_db_context_struct *db_handle;
    S32 index;
    U32 id;
    MMI_BOOL is_nblock;
    srv_plst_get_data_enum get_type;
    U32 *ret_value;
} pls_db_exec_get_data_struct;

typedef struct
{
    LOCAL_PARA_HDR
    srv_plst_db_context_struct *db_handle;
    U32 count;
    S32 ret;
} pls_db_search_data_struct;


typedef struct
{
    LOCAL_PARA_HDR
    srv_plst_db_context_struct *db_handle;
    srv_plst_list_group_item_info_struct *data;
} pls_db_get_group_data_struct;


typedef struct
{
    LOCAL_PARA_HDR
    srv_plst_db_context_struct *db_handle;
    U32 id;
    U32 *ret_value;
} pls_db_exec_update_play_info_struct;

typedef struct
{
    U32 file_type;
    UI_character_type ext_name[6];
}srv_plst_support_format_struct;


typedef enum
{
    SRV_PLST_FORMAT_DAF,
    SRV_PLST_FORMAT_MP2,
    SRV_PLST_FORMAT_AMR,
    SRV_PLST_FORMAT_AAC, 
    SRV_PLST_FORMAT_AWB,
    SRV_PLST_FORMAT_BSAC,
    SRV_PLST_FORMAT_ODF, 
    SRV_PLST_FORMAT_WAV, 
    SRV_PLST_FORMAT_MID, 
    SRV_PLST_FORMAT_MIDI, 
    SRV_PLST_FORMAT_IMY, 
    SRV_PLST_FORMAT_AIFF, 
    SRV_PLST_FORMAT_AIF,
    SRV_PLST_FORMAT_AIFC, 
    SRV_PLST_FORMAT_AU, 
    SRV_PLST_FORMAT_SND,
    SRV_PLST_FORMAT_MMF, 
    SRV_PLST_FORMAT_WMA,
    SRV_PLST_FORMAT_M4A,
    SRV_PLST_FORMAT_3GP_AUDIO,
    SRV_PLST_FORMAT_MP4_VIDEO, 
    SRV_PLST_FORMAT_3G2A,
    SRV_PLST_FORMAT_3GA,
    SRV_PLST_FORMAT_APE,
    SRV_PLST_FORMAT_3GP,
    SRV_PLST_FORMAT_MP4, 
    SRV_PLST_FORMAT_MPG, 
    SRV_PLST_FORMAT_3G2,
    SRV_PLST_FORMAT_RM,
    SRV_PLST_FORMAT_RMVB,
    SRV_PLST_FORMAT_RV,
    SRV_PLST_FORMAT_AVI, 
    SRV_PLST_FORMAT_FLV,
    SRV_PLST_FORMAT_F4V,
    SRV_PLST_FORMAT_SDP, 
    SRV_PLST_FORMAT_RAM,
    SRV_PLST_FORMAT_RA,
    SRV_PLST_FORMAT_OGG,    
    SRV_PLST_FORMAT_MKV,
    SRV_PLST_FORMAT_WEBM,
    SRV_PLST_FORMAT_MK3D,
    SRV_PLST_FORMAT_FLAC,
    SRV_PLST_FORMAT_MOT,    
    SRV_PLST_FORMAT_NUM
}srv_plst_support_format_enum;

#define PLS_WAIT_EVENT(evt_) do{                                                \
        kal_uint32 retrieved_events;                                            \
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_PLST_WAIT_EVENT, (evt_), __LINE__);  \
        kal_retrieve_eg_events(g_pls_db_cntx->g_pls_event, (evt_), \
        KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define PLS_SET_EVENT(evt_) do{                                            \
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_PLST_SET_EVENT, (evt_),  __LINE__);   \
        kal_set_eg_events(g_pls_db_cntx->g_pls_event, (evt_),KAL_OR);            \
        } while(0)

#define IS_CARD_EXIST  srv_plst_util_check_card_if_exist()

extern MMI_BOOL srv_plst_util_check_card_if_exist(void);
extern S32 srv_plst_init_instance(srv_plst_base_info_struct* base, srv_plst_db_context_struct *db_info);
extern S32 srv_plst_deinit_instance(srv_plst_base_info_struct* base, srv_plst_db_context_struct *db_info);
extern S32 srv_plst_pls_open_lib(srv_plst_base_info_struct* base, srv_plst_open_flag_enum open_flag);
extern S32 srv_plst_pls_close_lib(srv_plst_base_info_struct* base);
extern S32 srv_plst_pls_update_lib(srv_plst_base_info_struct *base);
extern S32 srv_plst_pls_stop_update_lib(srv_plst_base_info_struct *base);
extern S32 srv_plst_pls_pause_update_lib(srv_plst_base_info_struct *base);
extern S32 srv_plst_pls_resume_update_lib(srv_plst_base_info_struct *base);
extern S32 srv_plst_pls_plst_create(srv_plst_base_info_struct *base, UI_string_type name, U32 *id_info);
extern S32 srv_plst_pls_plst_rename(srv_plst_base_info_struct *base, UI_string_type name, U32 index);
extern S32 srv_plst_pls_plst_delete(srv_plst_base_info_struct *base, U32 index);
extern S32 srv_plst_pls_get_plst_id(srv_plst_base_info_struct *base, U32 index, U32* id);
extern S32 srv_plst_pls_multi_select_set_mark(srv_plst_base_info_struct *base, U32 index, MMI_BOOL is_mark);
extern S32 srv_plst_pls_multi_select_get_mark(srv_plst_base_info_struct *base, U32 index, MMI_BOOL* is_mark);
extern S32 srv_plst_pls_create_mark_tbl(srv_plst_base_info_struct *base, MMI_BOOL is_create);
extern S32 srv_plst_pls_remove(srv_plst_base_info_struct *base, U32 index);
extern S32 srv_plst_pls_stop_remove(srv_plst_base_info_struct *base, U32*count);
extern S32 srv_plst_pls_list_item_delete(srv_plst_base_info_struct *base, U32 index);
extern S32 srv_plst_pls_set_as_active(srv_plst_base_info_struct *base, U32 index, MMI_BOOL update_db, MMI_BOOL use_current_list);
extern S32 srv_plst_pls_store_active_info(srv_plst_base_info_struct *base);
extern S32 srv_plst_pls_add_media_to_plst(srv_plst_base_info_struct *base, U32 media_index, U32 plst_idx);
extern S32 srv_plst_pls_get_prefix_search_count(srv_plst_base_info_struct *base, U32* count);
extern S32 srv_plst_pls_plst_item_reorder(srv_plst_base_info_struct* base, U32 index_o,U32 index_d);
extern S32 srv_plst_pls_get_playing_info(srv_plst_base_info_struct *base, srv_plst_playing_context_struct *playing_info);
extern S32 srv_plst_pls_get_active_playing_media(srv_plst_base_info_struct *base, srv_plst_playing_context_struct *playing_info,srv_plst_get_data_enum active_type, U32* id, UI_string_type path);
extern S32 srv_plst_pls_item_clear(srv_plst_base_info_struct *base);
extern S32 srv_plst_pls_item_stop_clear(srv_plst_base_info_struct *base, U32 *count);
extern S32 srv_plst_pls_get_show_data(srv_plst_base_info_struct *base, srv_plst_list_view_history_struct *list_view_hisroty, srv_plst_get_data_enum data_flag,U32 index, U32* data);
extern S32 srv_plst_pls_plst_item_reorder_set_result(srv_plst_base_info_struct *base, MMI_BOOL save_notice);
extern S32 srv_plst_pls_entry_list(srv_plst_base_info_struct *base);
extern S32 srv_plst_pls_exit_list(srv_plst_base_info_struct *base);
extern S32 srv_plst_pls_stop_get_show_data(srv_plst_base_info_struct *base, srv_plst_list_view_history_struct *list_view_hisroty, srv_plst_get_data_enum data_flag);
extern S32 srv_plst_pls_list_item_stop_delete(srv_plst_base_info_struct *base, U32*count);
extern S32 srv_plst_pls_stop_add_media_to_plst(srv_plst_base_info_struct *base);
extern S32 srv_plst_pls_plst_stop_delete(srv_plst_base_info_struct *base, U32 *count);
extern S32 srv_plst_pls_stop_open_lib(srv_plst_base_info_struct *base);
extern S32 srv_plst_pls_play_config_reset(srv_plst_base_info_struct *base);
extern S32 srv_plst_pls_get_active_index(srv_plst_base_info_struct *base, srv_plst_active_type_enum type, U32 * index);
extern MMI_BOOL srv_plst_pls_check_active_media_is_in_plst(srv_plst_base_info_struct *base, srv_plst_default_playlist_enum type);
extern S32 srv_plst_pls_active_media_remove_from_plst(srv_plst_base_info_struct *base, srv_plst_default_playlist_enum type);
extern S32 srv_plst_pls_active_media_add_to_plst(srv_plst_base_info_struct *base, srv_plst_default_playlist_enum type);
#ifdef __PLST_SRV_FEATURE_GROUP_LIST__
extern S32 srv_plst_pls_get_group_data(srv_plst_base_info_struct *base, srv_plst_list_view_history_struct *list_view_hisroty, srv_plst_list_group_item_info_struct *data);
#endif /*__PLST_SRV_FEATURE_GROUP_LIST__*/
extern S32 srv_plst_pls_search(srv_plst_base_info_struct *base);

extern void pls_db_msg_handler(ilm_struct *ilm_ptr);
extern MMI_BOOL pls_db_util_check_space_is_enough(U8 drv_letter, S32 req_size, S32 *fs_error);
extern S32 pls_db_util_check_disk_space_and_get_error(srv_plst_base_info_struct* srv_plst_base, U8 drv_letter, S32 req_size);
extern void pls_db_util_get_security_info(U8 drv_letter, srv_plst_security *sec);
extern S32 pls_db_util_get_id(srv_plst_list_context_struct *list_cache, S32 index, U32* id);
extern U32 pls_db_util_get_file_type(UI_string_type ext);
extern S32 pls_db_util_get_meta_parser(srv_plst_base_info_struct *base, UI_string_type path, srv_plst_media_details_struct *details);
extern MMI_BOOL pls_db_util_get_if_is_video(UI_string_type file_ext);
extern MMI_BOOL pls_db_util_check_if_in_phone(UI_string_type path);
extern void pls_db_util_get_filename_as_title(const UI_string_type in_path, UI_string_type out_title, U16 title_len);
extern S32 pls_db_util_get_file_artwork(UI_string_type path, void* buffer, U32 buffer_size,void* resized_data, S32* resized_size);
extern S16 pls_db_util_check_item_if_in_cache(srv_plst_list_view_history_struct* list_view, S32 index, S32 *index_o);
extern S32 pls_db_util_resize_artwork(meta_tag_img_info_struct *image_info_p, void* buffer, U32 buffer_size, void* resized_data, S32 *resized_size);
extern S32 pls_db_util_get_meta_parser_all(srv_plst_base_info_struct * base, UI_string_type path, srv_plst_media_details_struct * details, void* buffer, U32 buffer_size, meta_tag_img_info_struct *image_info_p);
extern S32 srv_plst_pls_update_show_data(srv_plst_base_info_struct *base, srv_plst_list_view_history_struct *list_view, srv_plst_get_data_enum data_flag, U32 index, UI_string_type path);
extern S32 srv_plst_pls_stop_update_artwork(srv_plst_base_info_struct *base, srv_plst_list_view_history_struct *list_view_hisroty, srv_plst_get_data_enum data_flag);
extern S32 srv_plst_pls_get_cntx_by_id(srv_plst_base_info_struct *base, srv_plst_get_cntx_param_struct *in_param, srv_plst_get_context_struct *out_param);
extern MMI_BOOL pls_db_util_find_artwork_path(UI_string_type path);
extern S32 srv_plst_pls_update_playing_info(srv_plst_base_info_struct *base, U32 id);
extern MMI_BOOL srv_plst_pls_check_plst_is_exist(srv_plst_base_info_struct *base, UI_string_type name);
#ifdef __PLST_SRV_FEATURE_GROUP_LIST__
extern S32 srv_plst_pls_list_item_jumpto(srv_plst_base_info_struct *base, U32 jump_to_info, U32 *index);
#endif /* __PLST_SRV_FEATURE_GROUP_LIST__ */
/* sqlite3 execute related */

extern S32 pls_sql_init_instance_int(srv_plst_db_context_struct *db, U32 db_mem_size, U32 line);
extern S32 pls_sql_deinit_instance_int(srv_plst_db_context_struct *db, U32 line);
extern S32 pls_sql_enter_instance_int(srv_plst_db_context_struct *db, U32 line);
extern S32 pls_sql_exit_instance_int(srv_plst_db_context_struct *db, U32 line);
extern S32 pls_sql_rollback_transaction_int(srv_plst_db_context_struct *db, U32 line);
extern S32 pls_sql_prepare_ex_int(srv_plst_db_context_struct *db, CHAR* cmd, sqlite3_stmt** stmt, U32 line);
extern S32 pls_sql_finalize_int(sqlite3_stmt* stmt, U32 line);


#define pls_sql_enter_instance(db) \
        pls_sql_enter_instance_int(db, __LINE__);
#define pls_sql_exit_instance(db) \
        pls_sql_exit_instance_int(db, __LINE__);
#define pls_sql_init_instance(db, mem_size) \
        pls_sql_init_instance_int(db, mem_size, __LINE__);
#define pls_sql_deinit_instance(db) \
        pls_sql_deinit_instance_int(db, __LINE__);
#define pls_sql_rollback_transaction(db) \
        pls_sql_rollback_transaction_int(db, __LINE__);
#define pls_sql_prepare_ex(db, cmd, stmt) \
        pls_sql_prepare_ex_int(db, cmd, stmt, __LINE__);
#define pls_sql_finalize(stmt) \
        pls_sql_finalize_int(stmt, __LINE__);
#define pls_sql_clear_binding(stmt) \
        pls_sql_clear_binding_int(stmt, __LINE__);
#define pls_sql_finalize_or_clear_binding(stmt, stmt_id) \
        pls_sql_finalize_or_clear_binding_int(stmt, stmt_id, __LINE__);

extern S32 pls_sql_open_db(UI_string_type path, srv_plst_db_context_struct *db);
extern S32 pls_sql_attach_db(UI_string_type path, srv_plst_db_context_struct *db);
extern S32 pls_sql_detach_db(UI_string_type path, srv_plst_db_context_struct *db);
extern S32 pls_sql_close_db(srv_plst_db_context_struct *db);
extern S32 pls_sql_begin_transaction(srv_plst_db_context_struct *db);
extern S32 pls_sql_commit_transaction(srv_plst_db_context_struct *db);
extern S32 pls_sql_check_file_is_exist(srv_plst_base_info_struct *base, UI_string_type path,UI_string_type file_ext, MMI_BOOL is_short);
extern S32 pls_sql_append_file_to_db(srv_plst_base_info_struct *base, UI_string_type path, UI_string_type file_ext, MMI_BOOL is_short);
extern S32 pls_sql_get_view_count(srv_plst_db_context_struct *db, S32 index, U32 *data);
extern S32 pls_sql_get_view_hint_count(srv_plst_db_context_struct *db, S32 index, U32 *data);
extern S32 pls_sql_get_view_title(srv_plst_db_context_struct *db, S32 index, U32 *data);
extern S32 pls_sql_get_item_to_fill_cache(srv_plst_db_context_struct *db, S32 index,S16 asc, S32* index_o);
extern S32 pls_sql_get_artwork_context(srv_plst_db_context_struct *db, S32 index, U32 *data);
extern S32 pls_sql_get_view_details(srv_plst_db_context_struct *db, U32 id, U32 *data);
extern S32 pls_sql_get_view_details_by_filter(srv_plst_db_context_struct *db, U32 id, U32 *data);
extern S32 pls_sql_update_view_details(srv_plst_db_context_struct *db, U32 id, U32 *data);
extern S32 pls_sql_create_plst(srv_plst_db_context_struct *db, U32 id, UI_string_type name);
extern S32 pls_sql_create_mark_tbl(srv_plst_db_context_struct *db);
extern S32 pls_sql_set_mark(srv_plst_db_context_struct *db, srv_plst_list_view_history_struct *list_view, U32 id, U32 is_mark);
extern S32 pls_sql_get_mark(srv_plst_db_context_struct *db, srv_plst_list_view_history_struct *list_view, U32 id, U32* is_mark);
extern S32 pls_sql_add_media_to_plst(srv_plst_db_context_struct *db, U32 media_id, U32 plst_id);
extern S32 pls_sql_set_active(srv_plst_db_context_struct *db, srv_plst_playing_context_struct *play_ptr);
extern S32 pls_sql_clear_plst(srv_plst_db_context_struct *db,U32 plst_id);
extern S32 pls_sql_remove_item_from_list(srv_plst_db_context_struct *db,srv_plst_list_view_history_struct *list_view, U32 plst_id, U32 media_id);
extern S32 pls_sql_set_db_parama(srv_plst_db_context_struct *db);
extern S32 pls_sql_prepare_to_create_plst(srv_plst_db_context_struct *db, U32* id, UI_string_type name);
extern S32 pls_sql_rename_plst(srv_plst_db_context_struct *db, U32 id, UI_string_type name);
extern S32 pls_sql_delete_plst(srv_plst_db_context_struct *db, U32 *plst_id);
extern S32 pls_sql_delete_media_from_list(srv_plst_db_context_struct *db, srv_plst_list_view_history_struct *list_view, U32 index);
extern S32 pls_sql_load_active_info(srv_plst_db_context_struct *db, U32* data);
extern S32 pls_sql_reset_exist_flag_for_udpate(srv_plst_db_context_struct *db);
extern S32 pls_sql_get_active_media_path_by_id(srv_plst_db_context_struct *db,srv_plst_playing_context_struct *play_ptr, srv_plst_active_list_enum active_type, U32 id, UI_string_type path, U32 *id_o);
extern S32 pls_sql_get_next_active_id(srv_plst_db_context_struct *db, srv_plst_playing_context_struct *playing_info, U32* id);
extern S32 pls_sql_get_prev_active_id(srv_plst_db_context_struct *db, srv_plst_playing_context_struct *playing_info, U32* id);
extern S32 pls_sql_plst_item_reorder(srv_plst_db_context_struct *db, U32 index_o, u32 index_d);
extern MMI_BOOL pls_sql_check_if_need_del_unexist_file(srv_plst_db_context_struct *db);
extern S32 pls_sql_del_unexist_file(srv_plst_db_context_struct *db);
extern S32 pls_sql_get_media_path_by_index(srv_plst_db_context_struct *db, U32 index, U32 *data);
extern S32 pls_sql_end_transaction(srv_plst_db_context_struct *db);
extern S32 pls_sql_util_get_media_id_by_index(srv_plst_db_context_struct *db, srv_plst_list_view_history_struct *list_view, U32 index, U32 sub_index, U32* id);
extern S32 pls_sql_util_get_hint_count(srv_plst_db_context_struct *db, srv_plst_list_view_history_struct *list_view, U32 index, U32* count);
extern S32 pls_sql_get_media_id_from_cache(srv_plst_db_context_struct *db, S32 index, U32 *id);
extern S32 pls_sql_get_auto_active_id(srv_plst_db_context_struct *db, srv_plst_playing_context_struct *playing_info, U32* id);
extern S32 pls_sql_media_for_version_wrong(srv_plst_db_context_struct *db, U8 drv_letter, MMI_BOOL single_db);
extern S32 pls_sql_delete_mark_tbl(srv_plst_db_context_struct *db);
extern S32 pls_sql_play_config_reset(srv_plst_db_context_struct * db, srv_plst_playing_context_struct * play_ptr);
extern S32 pls_sql_get_artwork_context_by_id(srv_plst_db_context_struct * db, U32 id, U32 * data);
extern S32 pls_sql_get_plst_index_by_name(srv_plst_db_context_struct *db, U16 *name, U32 *index);
extern S32 pls_sql_get_active_index_by_id(srv_plst_db_context_struct *db, srv_plst_playing_context_struct *playing_info, U32 id, U32 *ordinal);
extern S32 pls_sql_get_default_list_count(srv_plst_db_context_struct *db,srv_plst_playing_context_struct *play_info, U32 *count);
extern S32 pls_sql_get_current_active_id(srv_plst_db_context_struct *db, srv_plst_playing_context_struct *playing_info, U32* id);
extern S32 pls_sql_get_active_play_count_by_id(srv_plst_db_context_struct *db, srv_plst_playing_context_struct *playing_info, U32 id, U32 *play_count);
extern S32 pls_sql_get_playlist_item_count(srv_plst_db_context_struct *db, U32 plst_id, U32 *count);
extern S32 pls_sql_udpate_active_info_after_change_index(srv_plst_db_context_struct *db, srv_plst_playing_context_struct *playing_info);
extern S32 pls_sql_create_table(U8 drv, srv_plst_db_context_struct *db);
extern S32 pls_sql_read_version(U8 drv, srv_plst_db_context_struct* db,srv_plst_security* sec);
extern S32 pls_sql_util_get_fs_err(srv_plst_db_context_struct *db);
extern S32 pls_sql_update_artwork_context(srv_plst_db_context_struct *db, S32 index, U32 *data);
extern S32 pls_db_util_resize_artwork_by_path(UI_string_type path, void* buffer, U32 buffer_size, void* resized_data, S32 *resized_size);
extern S32 pls_sql_get_cntx_by_id(srv_plst_db_context_struct *db, srv_plst_get_cntx_param_struct *in_param, srv_plst_get_context_struct *out_param);
extern S32 pls_sql_update_media_playing_info(srv_plst_db_context_struct * db, srv_plst_playing_context_struct * playing_info, U32 id);
extern MMI_BOOL pls_sql_active_media_check_if_in_defplst(srv_plst_db_context_struct *db, 
        srv_plst_playing_context_struct *play_ptr, srv_plst_default_playlist_enum type);
extern S32 pls_sql_active_media_add_or_remove_from_defplst(srv_plst_db_context_struct *db, 
        srv_plst_playing_context_struct *play_ptr, MMI_BOOL is_add, srv_plst_default_playlist_enum type);
extern S32 pls_sql_get_mark_count(srv_plst_db_context_struct *db, srv_plst_list_view_history_struct *list_view, S32 index, U32 *count);
extern MMI_BOOL pls_sql_check_plst_is_exist(srv_plst_db_context_struct *db, UI_string_type name);
extern S32 pls_sql_list_jump(srv_plst_db_context_struct *db, U32 jump_info, U32* index);
extern S32 pls_sql_get_group_count(srv_plst_db_context_struct *db, srv_plst_list_view_history_struct *list_view, srv_plst_list_group_item_info_struct *data);
extern S32 pls_sql_search_count(srv_plst_db_context_struct *db, srv_plst_list_view_history_struct *list_view, U32* count);
extern S32 pls_sql_get_active_idx(srv_plst_db_context_struct *db, srv_plst_playing_context_struct *playing_info, U32 id, srv_plst_active_type_enum type, U32 *ordinal);
#endif  /* __PLST_SERVICE_DB_SUPPORT__ */
#endif
