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
 *  MusicPlaylist.c
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "FileMgrSrvGProt.h"

#ifdef __MMI_PLAYLIST_SERVICE_SLIM__
#include "MMIDataType.h"
#include "MMI_media_app_trc.h"
#include "mmi_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "gui_data_types.h"
#include "Unicodexdcl.h"
#include "fs_type.h"
#include "fs_func.h"
#include "kal_public_api.h"
#include "fs_errcode.h"
#include "string.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "MMI_features.h"
#include "mmi_rp_file_type_def.h"
#include "stdlib.h"
#include "Conversions.h"

#include "MusicPlaylist.h"


// global para define
U32 g_instance = 0;

//----------------------------------------------------------------------------------------
// Function dec

/* add this for resolve build warning. */
extern U8 PhnsetGetDefEncodingType(void);
static void music_playlist_generate_sort_index(music_playlist_index_node_struct* index, S32 low, S32 high);
static void music_playlist_error_handler(music_playlist_cntx_struct* list_cntx, S32 error);

//----------------------------------------------------------------------------------------
// source code

/*****************************************************************************
 * FUNCTION
 *  music_playlist_send_event
 * DESCRIPTION
 *  send event to caller
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static void music_playlist_send_event(srv_playlist_cb_evt_enum cb_event, S32 cb_para_1, U32 cb_para_2)
{
    music_playlist_cntx_struct *list_cntx = (music_playlist_cntx_struct *)g_instance;
    if (!list_cntx)
    {
        return;
    }

    if (list_cntx->callback)
    {
        list_cntx->callback(list_cntx->user_data, cb_event, cb_para_1, cb_para_2);
    }
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_check_card_state
 * DESCRIPTION
 *  check memory if exist or busy now
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
#ifndef __MMI_MUSIC_PLAYER_PHONE_DRIVE__
static MMI_BOOL music_playlist_check_card_state(void)
{
    S32 fs_ret = FS_NO_ERROR;
    MMI_BOOL ret = MMI_FALSE;

    /* check if disk exist. */
    fs_ret = FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM);
    if (FS_NO_ERROR == fs_ret)
    {
        /* Check if disk is busy */
        fs_ret = FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_FEATURE_STATE_ENUM);
        if (FS_NO_ERROR == fs_ret)
        {
            ret = MMI_TRUE;
        }
        else
        {
            ret = MMI_FALSE;
            MMI_TRACE(TRACE_GROUP_2, TRC_MUSIC_PLST_CHECK_CARD, fs_ret, __LINE__);
        }
    }
    else
    {
        ret = MMI_FALSE;
        MMI_TRACE(TRACE_GROUP_2, TRC_MUSIC_PLST_CHECK_CARD, fs_ret, __LINE__);
    }

    return ret;
}
#endif  // __MMI_MUSIC_PLAYER_PHONE_DRIVE__

/*****************************************************************************
 * FUNCTION
 *  music_playlist_set_pick_index
 * DESCRIPTION
 *  seek play list index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void music_playlist_set_pick_index(music_playlist_cntx_struct *list_cntx, S32 index)
{
    music_playlist_list_struct* list = &(list_cntx->current_list);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list->pick_index = index;
    if (!IsBitSetOn(index, list->bitset))
    {
        SetBitSet(index, list->bitset);
        list->pick_count++;
    }
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_set_start
 * DESCRIPTION
 *  seek play list index
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void music_playlist_set_start(music_playlist_cntx_struct* list_cntx, S32 index)
{
    music_playlist_list_struct* list = &(list_cntx->current_list);

    memset(list->bitset, 0x00, MUSIC_PLAYLIST_MAX_BITSET_SIZE);
    list->pick_index = index;
    list->pick_count = 0;
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_pick_random
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void music_playlist_pick_random(music_playlist_list_struct* list)
{
    S32 i = 0;
    U32 seek_count = 0;
    
    /* need find an empty slot. */
    i = (list->pick_index + (rand() % list->total) + 1) % list->total;
    
    while (1)
    {
        i = (i + 1) % list->total;
    
        if (IsBitSetOn(i, list->bitset))
        {
            MMI_ASSERT(seek_count < (U32)list->total);
            seek_count++;
        }
        else
        {
            break;
        }
    }
    
    list->pick_index = i;
    list->pick_count++;
    SetBitSet(list->pick_index, list->bitset);
}


/*****************************************************************************
 * FUNCTION
 *  music_playlist_do_pick
 * DESCRIPTION
 *  pick next song from play list
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 pick index, -1: empty of list, other wise picked index
 *****************************************************************************/
S32 music_playlist_do_pick(music_playlist_cntx_struct* list_cntx, S32* index)
{
    music_playlist_list_struct* list = &(list_cntx->current_list);
    S32 ret = SRV_PLAYLIST_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!list_cntx->list_loaded)
    {
        *index = -1;
        return SRV_PLAYLIST_END;
    }

    if (SRV_PLAYLIST_REPEAT_ONE == list->repeat_mode)
    {
        /* pick count and bistset are useless in this time. */
        *index = list->pick_index;
        ret = SRV_PLAYLIST_NEXT_LOOP;
    }
    else
    {
        /* for shuffle on mode, get a song randomly. */
        if (SRV_PLAYLIST_SHUFFLE_ON == list->shuffle_mode)
        {
            /* reached end of list. */
            if (list->pick_count >= list->total)
            {
                music_playlist_set_start(list_cntx, -1);  /* reset all context. */
                if (SRV_PLAYLIST_REPEAT_OFF == list->repeat_mode)
                {
                    *index = -1;  /* stop! */
                    ret = SRV_PLAYLIST_END;
                }
                else if (SRV_PLAYLIST_REPEAT_ALL == list->repeat_mode)
                {
                    music_playlist_pick_random(list);
                    *index = list->pick_index;  /* begin from first one. */ 
                    ret = SRV_PLAYLIST_NEXT_LOOP;
                }
                else
                {
                    MMI_ASSERT(SRV_PLAYLIST_REPEAT_ONE != list->repeat_mode);
                }
            }
            else
            {
                music_playlist_pick_random(list);
                *index = list->pick_index;
                ret = SRV_PLAYLIST_OK;
            }
        }
        else
        {
            /* "pick_count" is useless when random = OFF. */
            if (list->pick_index == list->total - 1)
            {
                /* reached end of list. */
                music_playlist_set_start(list_cntx, -1);  /* reset all context. */
                if (SRV_PLAYLIST_REPEAT_OFF == list->repeat_mode)
                {
                    *index = -1;  /* stop! */
                    ret = SRV_PLAYLIST_END;
                }
                else if (SRV_PLAYLIST_REPEAT_ALL == list->repeat_mode)
                {
                    list->pick_index = 0;
                    list->pick_count++;
                    SetBitSet(list->pick_index, list->bitset);
                    *index = list->pick_index;  /* begin from first one. */ 
                    ret = SRV_PLAYLIST_NEXT_LOOP;
                }
                else
                {
                    MMI_ASSERT(SRV_PLAYLIST_REPEAT_ONE != list->repeat_mode);
                }
            }
            else
            {
                list->pick_index++;
                list->pick_count++;
                SetBitSet(list->pick_index, list->bitset);
                *index = list->pick_index;
                ret = SRV_PLAYLIST_OK;
            }
        }
    }
    
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_pick_next
 * DESCRIPTION
 *  pick the next song from play list
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 music_playlist_pick_next(music_playlist_cntx_struct* list_cntx)
{
    music_playlist_list_struct* list = &(list_cntx->current_list);

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list->total == 0)
    {
        return -1;
    }

    if (SRV_PLAYLIST_SHUFFLE_ON == list->shuffle_mode)
    {
        if (list->pick_count >= list->total)
        {
            /* reached end of list. */
            music_playlist_set_start(list_cntx, -1);  /* reset all context. */
        }        
        
        music_playlist_pick_random(list);
    }
    else
    {
        /* "pick_count" is useless when random = OFF. */
        if (list->pick_index == list->total - 1)
        {
            /* reached end of list. */
            music_playlist_set_start(list_cntx, -1);  /* reset all context. */
        }

        list->pick_index++;
        list->pick_count++;
        SetBitSet(list->pick_index, list->bitset);
    }        

    return list->pick_index;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_pick_prev
 * DESCRIPTION
 *  pick the previous song from play list
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 music_playlist_pick_prev(music_playlist_cntx_struct* list_cntx)
{
    music_playlist_list_struct* list = &(list_cntx->current_list);
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list->total == 0)
    {
        return -1;
    }


    if (SRV_PLAYLIST_SHUFFLE_ON == list->shuffle_mode)
    {
        if (list->pick_count >= list->total)
        {
            /* reached end of list. */
            music_playlist_set_start(list_cntx, -1);  /* reset all context. */
        }        
        
        music_playlist_pick_random(list);
    }
    else
    {
        if (list->pick_index == 0)
        {
            index = list->total - 1;
        }
        else
        {
            index = list->pick_index - 1;
        }
        music_playlist_set_start(list_cntx, index);
        music_playlist_set_pick_index(list_cntx, index);
    }        

    return list->pick_index;
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_get_list
 * DESCRIPTION
 *  load item into cache, from start_index item begin
 * PARAMETERS
 *  start_index :    [IN]   cache start item index
 *  cached_num  :    [OUT]  number of item in cache
 * RETURNS
 *  void
 *****************************************************************************/
static S32 music_playlist_get_list(music_playlist_cntx_struct* list_cntx, U16 *cached_num, U16 start_index)
{
    music_playlist_list_struct* list = &(list_cntx->current_list);
    music_playlist_dynamic_list_data_struct* ui = &(list_cntx->list_ui);
    music_playlist_block_node_struct block;
    CHAR path_buff[SRV_FMGR_PATH_BUFFER_SIZE];
    UI_character_type ucs2_buff[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    U32 data_offset = 0;
    U32 read_size = 0;
    CHAR* file_name = NULL;
    CHAR* ext = NULL;
    U16 count = 0;
    U8 i = 0;
    S32 ret = SRV_PLAYLIST_OK;   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    memset(path_buff, 0x00, SRV_FMGR_PATH_BUFFER_SIZE);
    memset(ucs2_buff, 0x00, ((SRV_FMGR_PATH_MAX_LEN+1) + 1) * ENCODING_LENGTH);
    
    while ((count < MUSIC_PLAYLIST_LIST_BUFF_SIZE) && (start_index < list->total))
    {
        if (!list->header.index[start_index].is_active)
        {
            /* current node is an empty node, \
               this case should not happen, pass this node. */
            start_index++;
            continue;
        }

        /* seek to current offset. */
        data_offset = list->header.index[start_index].offset;        

        /* read current index node data. */
        for (i = 0; i < list->header.index[start_index].used_block; i++)
        {
            /* reach the end of current node. */
            if (data_offset == 0)
            {
                ret = SRV_PLAYLIST_OK;
                break;
            }
            
            FS_Seek(list->fs_hdlr, data_offset, FS_FILE_BEGIN);
            ret = FS_Read(list->fs_hdlr, &block,
                          sizeof(music_playlist_block_node_struct),
                          &read_size);    /* size = number of U8. */
            
            if (ret < FS_NO_ERROR)
            {
                ret = SRV_PLAYLIST_ERR_FS_ERROR;
                break;
            }
            else if (read_size != sizeof(music_playlist_block_node_struct))
            {
                ret = SRV_PLAYLIST_ERR_FILE_DAMAGE;
                break;
            }
            else if ((MUSIC_PLAYLIST_BLOCK_PATTERN_1 != block.pattern_begin)
                     || (MUSIC_PLAYLIST_BLOCK_PATTERN_2 != block.pattern_end))
            {
                ret = SRV_PLAYLIST_ERR_FILE_DAMAGE;
                break;
            }
            else
            {
                data_offset = block.next_ptr;
                memcpy(&(path_buff[i * MUSIC_PLAYLIST_BLOCK_DATA_SIZE]), &(block.data), MUSIC_PLAYLIST_BLOCK_DATA_SIZE);
            }
            
        }

        if (ret < SRV_PLAYLIST_OK)
        {
            break;
        }
        
        if (list->header.index[start_index].is_active > 1)
        {
            /* set cache data. */
            ui->cache[count].is_short = 1;
        }
        else
        {
            /* set cache data. */
            ui->cache[count].is_short = 0;
        }
        
        /* utf8 -> ucs2 */
        mmi_chset_convert(CHSET_UTF8, 
                          CHSET_UCS2,
                          (char*)path_buff, 
                          (char*)ucs2_buff, 
                          SRV_FMGR_PATH_BUFFER_SIZE);

        file_name = mmi_ucs2rchr((CHAR*)ucs2_buff, (U16)L'\\');
        if (file_name == NULL)
        {
            // TODO: add trace!!
            ret = SRV_PLAYLIST_ERR_FILE_DAMAGE;
            break;
        }

        file_name += 2;     /* skip '\\' */
        ext = mmi_ucs2rchr((CHAR*)file_name, (U16)L'.');
        if (ext == NULL)
        {
            // TODO: add trace!!
            ret = SRV_PLAYLIST_ERR_FILE_DAMAGE;
            break;
        }
        
        mmi_ucs2ncpy((CHAR*)ui->cache[count].ext,
                     (CHAR*)ext, 
                     (U32)mmi_ucs2strlen((CHAR*)ext));
        
        /* cut off ext. */
        *(ext + 1) = 0;
        *ext = 0;
        mmi_ucs2ncpy((CHAR*)ui->cache[count].filename,
                     (CHAR*)file_name, 
                      SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
        
        if (list->header.index[start_index].is_active > 1)
        {
            //U8 dec_type = PhnsetGetDefEncodingType();

            mmi_chset_mixed_text_to_ucs2_str(
                    (U8*)ui->cache[count].filename,
                    (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                    (U8*)file_name,
                    (mmi_chset_enum)PhnsetGetDefEncodingType());
        }
        else
        {
            mmi_ucs2ncpy((CHAR*)ui->cache[count].filename,
                         (CHAR*)file_name, 
                         (U32)mmi_ucs2strlen((CHAR*)file_name));
        }  

        start_index++;
        count++;
    }
    
    if (ret < SRV_PLAYLIST_OK)
    {
        music_playlist_error_handler(list_cntx, ret);
        return ret;
    }
    else
    {
        *cached_num = count;
        return count;
    }
}
/*****************************************************************************
 * FUNCTION
 *  music_playlist_load_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  start_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static S32 music_playlist_load_cache(music_playlist_cntx_struct* list_cntx, U16 start_index)
{
    music_playlist_dynamic_list_data_struct* ui = &(list_cntx->list_ui);
    U16 cache_index = 0;
    U8 i = 0;
    S32 ret = SRV_PLAYLIST_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* init some value */
    ui->cache_start_index = start_index;

    for (i = 0; i < MUSIC_PLAYLIST_LIST_BUFF_SIZE; i++)
    {
        ui->cache[i].filename[0] = 0;
        ui->cache[i].ext[0] = 0;
        ui->cache[i].file_type = 0;
        ui->cache[i].is_short = 0;
    }
   
    ret = music_playlist_get_list(list_cntx, &cache_index, start_index);
    if (ret < SRV_PLAYLIST_OK)
    {
        return ret;
    }
    else
    {
        ui->cache_start_index = start_index;
        ui->cache_end_index = start_index + cache_index;
        return ret;
    }
}


/*****************************************************************************
 * FUNCTION
 *  music_playlist_get_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [OUT]
 *  item_index      [IN]
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
S32 music_playlist_get_filename(music_playlist_cntx_struct* list_cntx, S32 item_index, UI_string_type filename)
{
    music_playlist_dynamic_list_data_struct* list_ui = &(list_cntx->list_ui);
    music_playlist_item_info_struct item_info;
    S32 load_index;
    S32 current = 0;
    S32 ret = SRV_PLAYLIST_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /* check current index item whether in cache. */
    if ((item_index < list_ui->cache_start_index)
         || (item_index >= list_ui->cache_end_index))
    {
        /* desired entry in the middle of cache */
        load_index = item_index - (MUSIC_PLAYLIST_LIST_BUFF_SIZE / 2);

        if (load_index < 0)
        {
            load_index = 0;
        }

        /* if current item not in cache, load it first. */
        ret = music_playlist_load_cache(list_cntx, (U16)load_index);
        if (ret <  SRV_PLAYLIST_OK)
        {
            return ret;
        }
    }

    current = item_index - list_ui->cache_start_index;
    memcpy(&item_info, 
            &(list_ui->cache[current]), 
            sizeof(music_playlist_item_info_struct));
    
    mmi_ucs2ncpy((CHAR*)filename, (CHAR*)item_info.filename, SRV_FMGR_PATH_MAX_FILE_NAME_LEN);

    /* if its ext is not blank, extra ext name. */
    if (item_info.ext[0] != 0)
    {
        if (!mmi_ucs2rchr((CHAR*)item_info.ext, (U16)L'.'))
        {
            mmi_ucs2cat((CHAR*)filename, (CHAR*)L".");
        }
        mmi_ucs2cat((CHAR*)filename, (CHAR*)item_info.ext);
    }

    return SRV_PLAYLIST_OK;
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_get_path
 * DESCRIPTION
 *  get item file path
 * PARAMETERS
 *  list_cntx     [IN]   :  music_playlist_cntx_struct
 *  index         [IN]   :  item index
 *  fullfilename  [OUT]  :  file path
 * RETURNS
 *  > 0:
 *    2, short name: is_active == 2
 *    1, long name: is_active == 1
 *  <=0: 
 *    0, error
 *****************************************************************************/
static U8 music_playlist_get_path(music_playlist_cntx_struct* list_cntx, S32 index, UI_string_type fullfilename)
{
    music_playlist_list_struct* list = &(list_cntx->current_list);
    music_playlist_block_node_struct block;
    CHAR utf8[SRV_FMGR_PATH_BUFFER_SIZE];
    FS_HANDLE fd = -1;
    U32 path_size = 0;
    U32 read_size = 0;   
    U32 next_block = 0;
    U8 i = 0;
    S32 ret = SRV_PLAYLIST_OK;
    S32 result = FS_NO_ERROR;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(list->fs_hdlr >= 0);
    fd = list->fs_hdlr;

    if ((index < 0) || (index >= list->total))
    {
        return 0;
    }
    
    next_block = list->header.index[index].offset;
    for (i = 0; i < list->header.index[index].used_block; i++)
    {
        /* reach the end of current node. */
        if (!next_block)
        {
            break;
        }

        /* seek to next blok of current node. */
        result = FS_Seek(fd, next_block, FS_FILE_BEGIN);
        if (result < FS_NO_ERROR)
        {
            ret = SRV_PLAYLIST_ERR_FS_ERROR;
            break;
        }

        /* read block data. */
        result = FS_Read(fd, &block, sizeof(music_playlist_block_node_struct), &read_size);
        if (result < FS_NO_ERROR)
        {
            ret = SRV_PLAYLIST_ERR_FS_ERROR;
            break;
        }
        else if (read_size != sizeof(music_playlist_block_node_struct))
        {
            ret = SRV_PLAYLIST_ERR_FS_ERROR;
            break;
        }
        else if ((MUSIC_PLAYLIST_BLOCK_PATTERN_1 != block.pattern_begin)
                 || (MUSIC_PLAYLIST_BLOCK_PATTERN_2 != block.pattern_end))
        {
            ret = SRV_PLAYLIST_ERR_FILE_DAMAGE;
            break;
        }
        
        memcpy(&utf8[i * MUSIC_PLAYLIST_BLOCK_DATA_SIZE], &block.data, MUSIC_PLAYLIST_BLOCK_DATA_SIZE);
        next_block = block.next_ptr;
    }

    if (ret < SRV_PLAYLIST_OK)
    {
        return 0;
    }

    /* convert data format from UTF8 to UCS2, the raw data foramt is UTF8. */
    path_size = mmi_chset_convert(
                        CHSET_UTF8,
                        CHSET_UCS2,
                        (char*)utf8, 
                        (char*)fullfilename,
                        SRV_FMGR_PATH_BUFFER_SIZE);
    if (list->header.index[index].is_active == 2)
    {
        ret = 2;
    }
    else
    {
        ret = 1;
    }
    
    fullfilename[EOS(path_size)] = 0;    /* make it must be in boundary */
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_extract_ext
 * DESCRIPTION
 *  extract filename extension
 * PARAMETERS
 *  filename        [IN]        
 *  ext             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void music_playlist_extract_ext(const UI_string_type filename, UI_string_type ext)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* ext_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL)
    {
        *ext = 0;
    }
    else
    {
        ext_ptr = mmi_ucs2rchr((CHAR*)filename, (U16)L'.');

        if (ext_ptr == NULL)
        {
            *ext = 0;
        }
        else
        {
            ext_ptr += 2;
            mmi_ucs2ncpy((CHAR*)ext, (CHAR*)ext_ptr, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_extract_filename
 * DESCRIPTION
 *  get filename without path
 * PARAMETERS
 *  filename            [IN]        
 *  fullfilename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void music_playlist_extract_filename(UI_string_type filename, const UI_string_type path)
{
    CHAR* filename_ptr = mmi_ucs2rchr((CHAR*)path, (U16)(L'\\'));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename_ptr == NULL)
    {
        *filename = 0;
    }
    else
    {
        mmi_ucs2ncpy((CHAR*)filename, (CHAR*)(filename_ptr + 2), SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
    }
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_extract_folder
 * DESCRIPTION
 *  get filename without path
 * PARAMETERS
 *  filename            [IN]        
 *  fullfilename        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void music_playlist_extract_folder(UI_string_type floder, const UI_string_type path)
{
    CHAR* filename_ptr = mmi_ucs2rchr((CHAR*)path, (U16)(L'\\'));
    U16 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename_ptr == NULL)
    {
        *floder = *path;
    }
    else
    {
        len = mmi_ucs2strlen((CHAR*)path) - mmi_ucs2strlen(filename_ptr+2);
        mmi_ucs2ncpy((CHAR*)floder, (CHAR*)(path), len);
    }
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_check_free_space
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ext        [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
static MMI_BOOL music_playlist_check_free_space(CHAR drv_letter, U32 req_size)
{
    FS_DiskInfo disk_info;
    U32 disk_free_space;
    S32 fs_ret;
    UI_character_type path[10];
    
    kal_wsprintf(path, "%c:\\", drv_letter);    
    fs_ret = FS_GetDiskInfo((kal_uint16*)path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

    if (fs_ret < 0)
    {
        return MMI_FALSE;
    }
    else
    {        
        disk_free_space = disk_info.FreeClusters * 
                          disk_info.SectorsPerCluster * 
                          disk_info.BytesPerSector;
        if (disk_free_space < req_size + disk_info.BytesPerSector)    /* more a sector free space to keep file system other operation normal. */
        {
            return MMI_FALSE;
        }
        else
        {
            return MMI_TRUE;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_write_back_to_file
 * DESCRIPTION
 *  write list header info into file
 * PARAMETERS
 *  ext        [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 music_playlist_write_back_to_file(music_playlist_list_struct* list)
{
    S32 ret = FS_NO_ERROR;
    U32 writed_size = 0;
    U32 to_write_size = 0;
    U32 seek_offset = 0;
    
    do 
    {
        ret = FS_Seek(list->fs_hdlr, 0, FS_FILE_BEGIN);
        if (ret < FS_NO_ERROR)
        {
            break;
        }

        to_write_size = sizeof(music_playlist_header_struct);
        ret = FS_Write(list->fs_hdlr, &(list->header), to_write_size, &writed_size);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
        if (to_write_size != writed_size)
        {
            ret = SRV_PLAYLIST_ERR_FS_ERROR;
            break;
        }

        seek_offset = list->header.footer_pattern_offset;
        ret = FS_Seek(list->fs_hdlr, seek_offset, FS_FILE_BEGIN);
        if (ret < FS_NO_ERROR)
        {
            break;
        }
    } while (0);

    if (ret < FS_NO_ERROR)
    {
        FS_Close(list->fs_hdlr);
        return SRV_PLAYLIST_ERR_FS_ERROR;
    }
    else
    {
        S32 fs_ret = FS_NO_ERROR;
        FS_Commit(list->fs_hdlr);
        fs_ret = FS_Close(list->fs_hdlr);
        if (FS_NO_ERROR > fs_ret)
        {
            MMI_ASSERT(FS_INVALID_FILE_HANDLE != FS_ParseFH(list->fs_hdlr));
        }
        else
        {
            list->fs_hdlr = FS_Open(list->path, FS_READ_WRITE);
            MMI_ASSERT(!(list->fs_hdlr < 0));
        }
    }
    
    return SRV_PLAYLIST_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_lookup_audio_file_format
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ext        [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 music_playlist_lookup_audio_file_format(const UI_string_type ext)
{
    UI_character_type file_ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    U32 ext_len = 0;
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ext == NULL || 0 == (ext_len = mmi_ucs2strlen((CHAR*)ext)))
    {
        return -1;
    }
    
    /* skip ".". */
    {
        CHAR* dot = mmi_ucs2rchr((CHAR*)ext, (U16)L'.');
        if (dot)
        {
            dot += 2;
        }
        else
        {
            dot = (CHAR*)ext;
        }
        mmi_ucs2ncpy((CHAR*)file_ext, (CHAR*)dot, SRV_FMGR_PATH_MAX_FILE_EXT_LEN);
        ext_len = mmi_ucs2strlen((CHAR*)dot);
    }
    
    for (i = 0; i < audio_format_table[i][0]; i++)
    {
        if (ext_len == mmi_ucs2strlen((CHAR*)audio_format_table[i]))
        {
            if (!mmi_ucs2icmp((CHAR*)file_ext, (CHAR*)audio_format_table[i]))
            {   
                return i;
            }
        }
    }

    return -1;
}

 /*****************************************************************************
 * FUNCTION
 *  music_playlist_send_msg
 * DESCRIPTION
 *  player list service send msg function 
 * PARAMETERS
 *  buffer      [IN]    buffer for sqlite database usage
 *  length      [IN]    length of buffer
 *  en_update   [IN]    enable update picture to database
 * RETURNS
 *  void
 *****************************************************************************/
static void music_playlist_send_msg(module_type src, module_type dst, U32 msg_id, void *local_param_ptr)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    msg_send5(src, dst, MMI_MMI_SAP, (msg_type)msg_id, (local_para_struct*)local_param_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_search_continue_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void music_playlist_search_continue_req(void *context)
{
    music_playlist_action_req_struct *req_param_ptr;
    
    req_param_ptr = (music_playlist_action_req_struct* )construct_local_para(sizeof(music_playlist_action_req_struct), TD_CTRL);
    req_param_ptr->context = context;
    music_playlist_send_msg(MOD_MMI, MOD_MMI, MSG_ID_PLS_LIST_SEARCH_REQ, req_param_ptr);
}

#ifdef __DRM_V02__
/*****************************************************************************
 * FUNCTION
 *  music_playlist_generate_search_odf
 * DESCRIPTION
 *  search for drm file
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void music_playlist_generate_search_odf(music_playlist_cntx_struct* list_cntx)
{
    music_playlist_generate_struct* gen_info = &(list_cntx->generate_info);
    UI_string_type odf_path = list_cntx->generate_info.path_cache;

    /* for a short variable name. */
    drm_file_info_struct drm_file_info;
    FS_HANDLE multi_part_handle;
    UI_character_type content_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1];
    UI_character_type temp_buffer[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type file_ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    S32 ret = SRV_PLAYLIST_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    gen_info->DRM_find_cntx = DRM_get_find_cntx();
    multi_part_handle = DRM_find_firstN(
                                gen_info->DRM_find_cntx,
                                (PU16)odf_path, 
                                0, 
                                0,
                                &drm_file_info,
                                content_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                0);
    if (multi_part_handle < FS_NO_ERROR)
    {
        /* because this memory will be free in DRM_find_firstN when DRM_find_firstN fail. */
        gen_info->DRM_find_cntx = NULL;
        gen_info->last_error_code = multi_part_handle;
        gen_info->phase = MMI_AUDPLY_LIST_PHASE_ERR_HDLR;
        music_playlist_search_continue_req((void*)list_cntx);
        return;
    }
    else
    {
        do
        {
            music_playlist_extract_ext(content_name, file_ext);
            if (music_playlist_lookup_audio_file_format(file_ext) >= 0)
            {
                if (mmi_ucs2strlen((CHAR*)odf_path) + mmi_ucs2strlen((CHAR*)content_name) + 1 <= (SRV_FMGR_PATH_MAX_LEN+1))
                {
                    mmi_ucs2cpy((CHAR*)temp_buffer, (CHAR*)odf_path);
                    mmi_ucs2cat((CHAR*)temp_buffer, (CHAR*)L"\\");
                    mmi_ucs2cat((CHAR*)temp_buffer, (CHAR*)content_name);

                    if (gen_info->total_number < SRV_PLAYLIST_MAX_PLAYLIST_ITEM)
                    {
                        /* append the found drm file into play list file.  */
                        ret = music_playlist_generate_append_one(list_cntx, temp_buffer, MMI_FALSE, MMI_FALSE);
                        if (ret < SRV_PLAYLIST_OK)
                        {
                            DRM_find_close(gen_info->DRM_find_cntx, multi_part_handle);
                            gen_info->DRM_find_cntx = NULL;
                            gen_info->last_error_code = ret;
                            gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_ERR_HDLR;
                            music_playlist_search_continue_req((void*)list_cntx);
                            return;
                        }      
                        else
                        {
                            gen_info->appended_number++;
                            gen_info->total_number++;
                            MMI_ASSERT(gen_info->total_number <= SRV_PLAYLIST_MAX_PLAYLIST_ITEM);
                        }
                    }
                    else
                    {
                        DRM_find_close(gen_info->DRM_find_cntx, multi_part_handle);
                        gen_info->DRM_find_cntx = NULL;
                        gen_info->last_error_code = SRV_PLAYLIST_PLST_FULL;
                        gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_ERR_HDLR;
                        music_playlist_search_continue_req((void*)list_cntx);
                        return;
                    }
                }
            }
        } while (FS_NO_ERROR == DRM_find_nextN(
                                gen_info->DRM_find_cntx,
                                multi_part_handle, 
                                &drm_file_info,
                                content_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                1));
    }

    if (gen_info->DRM_find_cntx)
    {
        DRM_find_close(gen_info->DRM_find_cntx, multi_part_handle);
        gen_info->DRM_find_cntx = NULL;
    }

    gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_BACKWARDS_ODF;
    music_playlist_search_continue_req((void*)list_cntx);
    return;
}
#endif //  __DRM_V02__

/*****************************************************************************
 * FUNCTION
 *  music_playlist_generate_append_one
 * DESCRIPTION
 *  sync, add one song info into playlist file, has three steps:
 *    1st, generate block data(block_node), and write into file
 *    2nd, update playlist header(header_struct) and node[index](index_node_struct) 
 *    3rd, write new header info into playlist file
 * PARAMETERS
 *  list_cntx                  :  [IN]
 *  path                       :  [IN]
 *  is_short                   :  [IN]
 *  write_back_file_immediately:  [IN]
 * RETURNS
 *  
 *****************************************************************************/
static S32 music_playlist_generate_append_one(music_playlist_cntx_struct* list_cntx, UI_string_type path, MMI_BOOL is_short, MMI_BOOL write_back_file_immediately)
{
    music_playlist_list_struct* list = &(list_cntx->current_list);
    music_playlist_index_node_struct new_node;
    music_playlist_block_node_struct block;
    U8 utf8_buff[SRV_FMGR_PATH_BUFFER_SIZE];

    U32 write_size = 0;
    U32 insert_offset = 0;
    U32 next_block = 0;
    U32 used_size = 0;
    S32 ret = 0;
    U16 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    memset(utf8_buff, 0x00, SRV_FMGR_PATH_BUFFER_SIZE);
    
    /* make new node data. */
    memset(&new_node, 0x00, sizeof(music_playlist_index_node_struct));
    new_node.offset = list->header.footer_pattern_offset;
    new_node.index = list->total;

    /* init isactive. */
    if (is_short)
    {
        new_node.is_active = 2;
    }
    else
    {
        new_node.is_active = 1;
    }
    /* ucs2 -> utf8 */
    used_size = mmi_chset_convert(
                    CHSET_UCS2,
                    CHSET_UTF8, 
                    (char*)path, 
                    (char*)utf8_buff, 
                    SRV_FMGR_PATH_BUFFER_SIZE);

    /* init used block to save data. */
    new_node.used_block = used_size / MUSIC_PLAYLIST_BLOCK_DATA_SIZE;
    if (used_size % MUSIC_PLAYLIST_BLOCK_DATA_SIZE > 0)
    {
        new_node.used_block++;
    }

    if (list->header.empty_node.used_block >= new_node.used_block && write_back_file_immediately)
    {
        music_playlist_index_node_struct target_node;
        
        /* backup relative variables. */
        memcpy(&target_node, &(list->header.index[list->total]), sizeof(music_playlist_index_node_struct));

        if (!list->header.empty_node.offset)
        {
            /* something wrong about link of empty nodes. */
            return SRV_PLAYLIST_ERR_FILE_DAMAGE;
        }
        
        list->header.index[list->total].index = list->total;
        list->header.index[list->total].is_active = new_node.is_active;
        list->header.index[list->total].used_block = new_node.used_block;
        list->header.index[list->total].offset = list->header.empty_node.offset;

        /* check empty nodes will be used. */
        insert_offset = list->header.empty_node.offset;
        next_block = insert_offset;
        for (i = 0; i < new_node.used_block; i++)
        {
            /* seek to blcok. */
            ret = FS_Seek(list->fs_hdlr, next_block, FS_FILE_BEGIN);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            insert_offset = next_block;
            /* read block to get next ptr. */
            ret = FS_Read(list->fs_hdlr, &block, sizeof(music_playlist_block_node_struct), &write_size);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            else if (write_size != sizeof(music_playlist_block_node_struct))
            {
                ret = SRV_PLAYLIST_ERR_FS_ERROR;
                break;
            }
            
            /* check block. */
            if (block.pattern_begin != MUSIC_PLAYLIST_BLOCK_PATTERN_1 ||
                block.pattern_end != MUSIC_PLAYLIST_BLOCK_PATTERN_2)
            {
                ret = SRV_PLAYLIST_ERR_FILE_DAMAGE;
                break;
            }
            
            next_block = block.next_ptr;
            if (!next_block && (i < new_node.used_block - 1))
            {
                ret = SRV_PLAYLIST_ERR_FILE_DAMAGE;
                break;
            }
        }

        if (ret < FS_NO_ERROR)
        {
            /* check link of empty nodes failed. */
            return ret;
        }

        /* write to file. */
        insert_offset = list->header.empty_node.offset;
        next_block = insert_offset;
        for (i = 0; i < new_node.used_block; i++)
        {           
            /* seek to block. */
            ret = FS_Seek(list->fs_hdlr, next_block, FS_FILE_BEGIN);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            insert_offset = next_block;
            
            /* read block to get next ptr. */
            ret = FS_Read(list->fs_hdlr, &block, sizeof(music_playlist_block_node_struct), &write_size);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            else if (write_size != sizeof(music_playlist_block_node_struct))
            {
                ret = SRV_PLAYLIST_ERR_FS_ERROR;
                break;
            }
            /* check block. */
            if (block.pattern_begin != MUSIC_PLAYLIST_BLOCK_PATTERN_1 ||
                block.pattern_end != MUSIC_PLAYLIST_BLOCK_PATTERN_2)
            {
                ret = SRV_PLAYLIST_ERR_FILE_DAMAGE;
                break;
            }
            
            next_block = block.next_ptr;
            if (!next_block && (i < new_node.used_block - 1))
            {
                MMI_ASSERT(next_block != 0);
            }
            
            /* make new block data. */
            memcpy(&(block.data), &(utf8_buff[i * MUSIC_PLAYLIST_BLOCK_DATA_SIZE]), MUSIC_PLAYLIST_BLOCK_DATA_SIZE);

            /* seek back to the begin of current block. */
            ret = FS_Seek(list->fs_hdlr, insert_offset, FS_FILE_BEGIN);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            
            /* write new block data. */   
            ret = FS_Write(list->fs_hdlr, &block, sizeof(music_playlist_block_node_struct), &write_size);
            if (ret < FS_NO_ERROR)
            {
                break;
            }
            if (write_size != sizeof(music_playlist_block_node_struct))
            {
                ret = SRV_PLAYLIST_ERR_FS_ERROR;
                break;
            }
        }

        if (ret < FS_NO_ERROR)
        {
            if (i > 0)
            {
                /* 
                **  some blocks have been wrote to file.
                **  because the file size has not changed.
                **  only reset index node.
                */
                memcpy(&(list->header.index[list->total]), &target_node, sizeof(music_playlist_index_node_struct));
            }
        }
        else
        {
            /* append successfully. */
            list->total++;
            list->header.total_slot++;
            list->header.empty_node.offset = next_block;
            list->header.empty_node.used_block -= new_node.used_block;
            
            if (!next_block)
            {
                list->header.empty_node.used_block = 0;
            }

            if (write_back_file_immediately)
            {
                ret = music_playlist_write_back_to_file(list);
            }
        }
                
        return ret;
    }

    /* the empty node is not enough, append node to the end of the file. */
    else
    {
        MMI_BOOL have_enough_space = MMI_FALSE;
        U32 require_size = new_node.used_block * MUSIC_PLAYLIST_BLOCK_DATA_SIZE;
        CHAR drv_letter = (CHAR)list->path[0];

        have_enough_space = music_playlist_check_free_space((CHAR)drv_letter, require_size);
        if (have_enough_space)
        {
            music_playlist_index_node_struct target_node;
            
            /* backup relative variables. */
            memcpy(&target_node, &(list->header.index[list->total]), sizeof(music_playlist_index_node_struct));

            list->header.index[list->total].index = list->total;
            list->header.index[list->total].is_active = new_node.is_active;
            list->header.index[list->total].used_block = new_node.used_block;
            list->header.index[list->total].offset = list->header.footer_pattern_offset;

            /*
            **  write map back->write new node->read new map->sort->write back new map
            **  more file system operation in order to avoid make memory flagment.
            */
            do 
            {   
                insert_offset = list->header.footer_pattern_offset;
                /* write new path. */ 
                ret = FS_Seek(list->fs_hdlr, insert_offset, FS_FILE_BEGIN);
                if (ret < FS_NO_ERROR)
                {
                    break;
                }
                
                for (i = 0; i < new_node.used_block; i++)
                {      
                    music_playlist_block_node_struct block;
                    block.pattern_begin = MUSIC_PLAYLIST_BLOCK_PATTERN_1;
                    block.pattern_end = MUSIC_PLAYLIST_BLOCK_PATTERN_2;
                    
                    insert_offset += sizeof(music_playlist_block_node_struct);
                    if (i + 1 == new_node.used_block)
                    {
                        block.next_ptr = 0;
                    }
                    else
                    {
                        block.next_ptr = insert_offset;
                    }
                    memcpy(&(block.data), &(utf8_buff[i * MUSIC_PLAYLIST_BLOCK_DATA_SIZE]), MUSIC_PLAYLIST_BLOCK_DATA_SIZE);
                    
                    /* write new path. */   
                    ret = FS_Write(list->fs_hdlr, &block, sizeof(music_playlist_block_node_struct), &write_size);
                    if (ret < FS_NO_ERROR)
                    {
                        break;
                    }
                    if (write_size != sizeof(music_playlist_block_node_struct))
                    {
                        ret = SRV_PLAYLIST_ERR_FS_ERROR;
                        break;
                    }
                }

                if (ret < FS_NO_ERROR)
                {
                    if (i > 0)
                    {
                        /* 
                        **  some blocks have been wrote to file.
                        **  because the file size has been changed.
                        **  overwrite index area from new node first block.
                        */
                        memcpy(&(list->header.index[list->total]), &target_node, sizeof(music_playlist_index_node_struct));

                        ret = music_playlist_write_back_to_file(list);
                    }
                }
                else
                {
                    /* update index area offset. */
                    list->header.footer_pattern_offset += new_node.used_block * sizeof(music_playlist_block_node_struct);
                    list->header.total_slot++;
                    list->total++;
                    if (write_back_file_immediately)
                    {
                        ret = music_playlist_write_back_to_file(list);
                    }
                }
            } while (0);

            return ret;
        }
        else
        {
            return SRV_PLAYLIST_ERR_MEMORY_NOT_ENOUGH;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_generate_cancel_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void music_playlist_generate_cancel_hdlr(music_playlist_cntx_struct* list_cntx)
{
    music_playlist_generate_struct* gen_info = &(list_cntx->generate_info);
    music_playlist_list_struct* list = &(list_cntx->current_list);
    U32 cb_para2 = 0;
    S32 ret = SRV_PLAYLIST_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(TRACE_GROUP_2, TRC_MUSIC_PLST_GENERATE_CANCEL_HDLR, gen_info->appended_number);
    
    if (!(gen_info->search_handle < 0))
    {
        FS_FindClose(gen_info->search_handle);
    }
    
    if (gen_info->appended_number)
    {
        music_playlist_generate_sort_index(list->header.index, 0, (list->header.total_slot - 1));
        MMI_ASSERT(list->header.pattern == MUSIC_PLAYLIST_FOOTER_PATTERN);
        ret = music_playlist_write_back_to_file(list);
    }

    /* play list gen finished. */
    if (SRV_PLAYLIST_OK == ret)
    {
        /* write back to file secussed, return the appended number. */
        cb_para2 = (U32)gen_info->appended_number;
    }
    else
    {
        cb_para2 = 0;
    }

    gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_END;
    music_playlist_send_event(SRV_PLAYLIST_CB_EVT_ADD, ret, cb_para2);
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_generate_error_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void music_playlist_generate_error_hdlr(music_playlist_cntx_struct* list_cntx)
{
    music_playlist_generate_struct* gen_info = &(list_cntx->generate_info);
    music_playlist_list_struct* list = &(list_cntx->current_list);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_TRACE(TRACE_GROUP_2,
              TRC_MUSIC_PLST_GENERATE_ERROR_HDLR, 
              gen_info->last_error_code,
              gen_info->appended_number);
    
    if (gen_info->search_handle)
    {
        FS_FindClose(gen_info->search_handle);
        gen_info->search_handle = -1;
    }

    if (gen_info->appended_number)
    {
        music_playlist_generate_sort_index(list->header.index, 0, (list->header.total_slot - 1));
        MMI_ASSERT(list->header.pattern == MUSIC_PLAYLIST_FOOTER_PATTERN);
        (void)music_playlist_write_back_to_file(list);
    }

    /* play list gen error. */
    gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_END;
    music_playlist_send_event(SRV_PLAYLIST_CB_EVT_ADD, gen_info->last_error_code, 0);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_finish
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void music_playlist_generate_finish(music_playlist_cntx_struct* list_cntx)
{
    music_playlist_generate_struct* gen_info = &(list_cntx->generate_info);
    music_playlist_list_struct* list = &(list_cntx->current_list);
    S32 ret = SRV_PLAYLIST_OK;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(gen_info->stack_index == 0);

    if (gen_info->search_handle)
    {
        FS_FindClose(gen_info->search_handle);
        gen_info->search_handle = -1;
    }

    if (gen_info->appended_number)
    {
        music_playlist_generate_sort_index(list->header.index, 0, (list->header.total_slot - 1));
        MMI_ASSERT(list->header.pattern == MUSIC_PLAYLIST_FOOTER_PATTERN);
        ret = music_playlist_write_back_to_file(list);  
    }

    if (ret < SRV_PLAYLIST_OK)
    {
        /* change status to "handling error" if any error. */
        gen_info->last_error_code = ret;
        gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_ERR_HDLR;
        music_playlist_search_continue_req((void*)list_cntx);
        return;
    }

    /* play list gen successed, notify the caller result,
       and the number of file added . */
    gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_END;
    if (SRV_PLAYLIST_OK == ret)
    {
        music_playlist_send_event(SRV_PLAYLIST_CB_EVT_ADD, ret, (U32)gen_info->appended_number);
    }
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_generate_backwards
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void music_playlist_generate_backwards(music_playlist_cntx_struct* list_cntx)
{
    music_playlist_generate_struct* gen_info = &(list_cntx->generate_info);

    /* for a short variable name. */
    CHAR* last_backlash = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gen_info->stack_index > 0)
    {
        memset(&(gen_info->stack[gen_info->stack_index]), 0x00, sizeof(music_playlist_stack_node_struct));

        /* update path cache. */
        last_backlash = mmi_ucs2rchr((CHAR*)gen_info->path_cache, (U16)L'\\');
        MMI_ASSERT(last_backlash != NULL);
        *(last_backlash + 1) = 0;
        *last_backlash = 0;
        
        if (gen_info->phase == MUSIC_PLAYLIST_GEN_PHASE_BACKWARDS)
        {
            last_backlash = mmi_ucs2rchr((CHAR*)gen_info->path_cache, (U16)L'\\');
            MMI_ASSERT(last_backlash != NULL);
            *(last_backlash + 1) = 0;
            *last_backlash = 0;
            
        }
        
        mmi_ucs2cat((CHAR*)gen_info->path_cache, (CHAR*)L"\\");
        gen_info->stack_index--;
        gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_FORWARDS;
    }
    else
    {
        gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_FINISH;
    }
    
    music_playlist_search_continue_req((void*)list_cntx);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  music_playlist_generate_forwards
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void music_playlist_generate_forwards(music_playlist_cntx_struct* list_cntx)
{
    music_playlist_generate_struct* gen_info = &(list_cntx->generate_info);
    CHAR buf_file_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN * ENCODING_LENGTH + ENCODING_LENGTH];
    UI_character_type temp_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    FS_HANDLE file_handle;
    FS_DOSDirEntry file_info;
    U16 counter = 0;
    S32 return_value = 0;

    /* for a short variable name. */
    U32 path_length = 0;
    U32 sub_folder_length = 0;
    U32 total_length = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(gen_info->stack_index < MUSIC_PLAYLIST_MAX_DEPTH_DIRECTORY);
    if (!gen_info->stack[gen_info->stack_index].total_sub_folder)
    {
        /* no sub-folder, go backwards. */
        gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_BACKWARDS;
        music_playlist_search_continue_req((void*)list_cntx);
        return;
    }
    else if (gen_info->stack[gen_info->stack_index].total_sub_folder == 
                                gen_info->stack[gen_info->stack_index].index)
    {
        gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_BACKWARDS;
        music_playlist_search_continue_req((void*)list_cntx);
        return;
    }
    else    /* need forwards. */
    {
        mmi_ucs2cpy((CHAR*)temp_path, (CHAR*)gen_info->path_cache);
        mmi_ucs2cat((CHAR*)temp_path, (CHAR*)L"*.*");

        file_handle = FS_FindFirstN(
                        (PU16)temp_path,
                        NULL,
                        0,
                        0,
                        0,
                        FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                        &file_info,
                        (PU16)buf_file_name,
                        (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                        gen_info->stack[gen_info->stack_index].fs_index,
                        FS_FIND_DEFAULT);
        if (file_handle >= 0)
        {
            do
            {
                counter++;
                /* test if pass the filter */
                if (file_info.Attributes & FS_ATTR_DIR)
                {
                    FS_FindClose(file_handle);
                    
                    /* check path length. */  
                    path_length = mmi_ucs2strlen((CHAR*)gen_info->path_cache);
                    sub_folder_length = mmi_ucs2strlen((CHAR*)buf_file_name);
                    total_length = 0;

                    total_length = path_length + sub_folder_length;
                    total_length++;
                    if (total_length > (SRV_FMGR_PATH_MAX_LEN - 6))
                    {
                        // TODO: too long path, add trace.
                        gen_info->stack[gen_info->stack_index].fs_index += counter;
                        gen_info->stack[gen_info->stack_index].index++;
                    }
                    else 
                    {
                        if ((gen_info->stack_index + 1) < MUSIC_PLAYLIST_MAX_DEPTH_DIRECTORY)
                        {
                            /* compose next level path. */
                            mmi_ucs2cat((CHAR*)gen_info->path_cache, (CHAR*)buf_file_name);
                            mmi_ucs2cat((CHAR*)gen_info->path_cache, (CHAR*)L"\\");

                            /* save level node info. */
                            gen_info->stack[gen_info->stack_index].fs_index += counter;
                            gen_info->stack[gen_info->stack_index].index++;

                            /* entry next level. */
                            gen_info->stack_index++;
                            gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_SEARCH_FIRST;
                            
                            music_playlist_search_continue_req((void*)list_cntx);
                            return;
                        }
                        else /* get max depth. */
                        {
                            /* to get next file, even have a sub-directory. */
                            gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_SEARCH_NEXT;

                            music_playlist_search_continue_req((void*)list_cntx);
                            return;
                        }
                    }
                }
                
                return_value = FS_FindNextN(
                                file_handle,
                                NULL,
                                0,
                                0,
                                &file_info,
                                (PU16)buf_file_name,
                                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                                FS_FIND_DEFAULT);
                
            } while (return_value == FS_NO_ERROR);
            
            FS_FindClose(file_handle);
            /* no more sub-folder, backwards. */
            gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_BACKWARDS;
            music_playlist_search_continue_req((void*)list_cntx);
            return;
        }
        else
        {
            if (gen_info->stack_index == 0)
            {
                if (file_handle == FS_NO_MORE_FILES)
                {
                    gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_BACKWARDS;
                }
                else
                {
                    gen_info->last_error_code = file_handle;
                    gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_ERR_HDLR;
                }
            }
            else
            {
                gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_BACKWARDS;
            }
            music_playlist_search_continue_req((void*)list_cntx);
            return;
        }
    }   
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_generate_search
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void music_playlist_generate_search(music_playlist_cntx_struct* list_cntx)
{
    music_playlist_generate_struct* gen_info = &(list_cntx->generate_info);
    
    CHAR buf_file_name[SRV_FMGR_PATH_MAX_FILE_NAME_LEN * ENCODING_LENGTH + ENCODING_LENGTH];
    UI_character_type file_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type file_ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    MMI_BOOL is_shortname = MMI_FALSE;
    
    FS_HANDLE ret = FS_NO_ERROR;
    FS_DOSDirEntry file_info;
    U8 i = 0;
    
#ifdef __DRM_V02__
    UI_character_type odf_path[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    UI_character_type ext_in_odf[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    PU8 ext_name_p = NULL; 
    MMI_BOOL add_audio = MMI_FALSE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_ucs2cpy((CHAR*)file_path, (CHAR*)gen_info->path_cache);
    mmi_ucs2cat((CHAR*)file_path, (CHAR*)L"*.*");
        
    if (gen_info->phase == MUSIC_PLAYLIST_GEN_PHASE_SEARCH_FIRST)
    {
        ret = FS_FindFirstN(
                (PU16)file_path,
                NULL,
                0,
                FS_ATTR_DIR,    /* only search media files in this phase. */
                0,
                FS_ATTR_SYSTEM | FS_ATTR_HIDDEN | FS_ATTR_VOLUME,
                &file_info,
                (PU16)buf_file_name,
                (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                0,
                FS_FIND_DEFAULT);
        
        if (ret >= 0)
        {
            /* fine the first file success, continue to search next. */
            gen_info->search_handle = ret;
            gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_SEARCH_NEXT;
            
            /* begin to cache sub-folder infomation. */
            if (gen_info->stack_index < MUSIC_PLAYLIST_MAX_DEPTH_DIRECTORY)
            {
                gen_info->stack[gen_info->stack_index].level = gen_info->stack_index;
                gen_info->stack[gen_info->stack_index].total_sub_folder = 0;
                gen_info->stack[gen_info->stack_index].index = 0;
                gen_info->stack[gen_info->stack_index].fs_index = 0;    /* it is invalid when this value is 0 or 1. */
            }
            else
            {
                /* max level, do not save. */
                MMI_ASSERT(gen_info->stack_index < MUSIC_PLAYLIST_MAX_DEPTH_DIRECTORY);
            }
        }
        else
        {
            /* not find file in this folder, back to uper level. */
            if (gen_info->stack_index == 0)
            {
                if (ret == FS_NO_MORE_FILES)
                {
                    gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_BACKWARDS;
                }
                else
                {
                    gen_info->last_error_code = ret;
                    gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_ERR_HDLR;
                }
            }
            else
            {
                gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_BACKWARDS;
            }

            music_playlist_search_continue_req((void*)list_cntx);
            return;
        }
    }
    else if (gen_info->phase == MUSIC_PLAYLIST_GEN_PHASE_SEARCH_NEXT)
    {
        ret = FS_FindNextN(
                        gen_info->search_handle,
                        NULL,
                        0,
                        FS_ATTR_DIR,
                        &file_info,
                        (PU16)buf_file_name,
                        (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                        FS_FIND_DEFAULT);
        if (ret < 0)
        {
            /* not more files in this folder, not find. */
            FS_FindClose(gen_info->search_handle);
            gen_info->search_handle = -1;
            
            if (ret == FS_NO_MORE_FILES)
            {
                if (!gen_info->stack[gen_info->stack_index].total_sub_folder)
                {
                    gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_BACKWARDS;
                }
                else
                {
                    if (gen_info->stack_index < MUSIC_PLAYLIST_MAX_DEPTH_DIRECTORY)
                    {
                        gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_FORWARDS;
                    }
                    else
                    {
                        gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_BACKWARDS;
                    }
                }
            }
            else
            {
                if (gen_info->stack_index == 0)
                {
                    gen_info->last_error_code = ret;
                    gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_ERR_HDLR;
                }
                else
                {
                    gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_BACKWARDS;
                }
            }
            music_playlist_search_continue_req((void*)list_cntx);
            return;
        }
    }
    else
    {
        /* these codes should never be run. */
        MMI_ASSERT(gen_info->phase == MUSIC_PLAYLIST_GEN_PHASE_SEARCH_NEXT ||
                   gen_info->phase == MUSIC_PLAYLIST_GEN_PHASE_SEARCH_FIRST);
    }

    /* for find file, continue fellowing steps. */
    do
    {
        /* if this file is a not folder, and supported format, insert it into playlist file. */
        if ((file_info.Attributes & (FS_ATTR_DIR | FS_ATTR_VOLUME | FS_ATTR_HIDDEN | FS_ATTR_SYSTEM)) == 0)
        {
            /* catch the file extent name. */
            is_shortname = (MMI_BOOL)((file_info.NTReserved & FS_SFN_MATCH) != 0);
            if (is_shortname)
            {
                U8 j = 0;
                for (j = 0; j < 3; j++)
                {
                    if (file_info.Extension[j] == L' ')
                    {
                        break;
                    }
                    file_ext[j] = (UI_character_type) file_info.Extension[j];
                }
                file_ext[j] = 0;
            }
            else
            {
                CHAR* ext = mmi_ucs2rchr((CHAR*)buf_file_name, (U16)L'.');
                if (ext != NULL)
                {
                    ext += 2;
                    mmi_ucs2ncpy((CHAR*)file_ext, (CHAR*)ext, mmi_ucs2strlen((CHAR*)ext));
                }
                else
                {
                    ext = NULL;
                    file_ext[0] = 0;
                }
            }

            /* check this file whether be supported, according to its extent name. */
            if (music_playlist_lookup_audio_file_format(file_ext) >= 0)
            {
        #ifdef __DRM_V02__
                if (!mmi_ucs2nicmp((CHAR*)file_ext, (CHAR*)L"odf", (U32)mmi_ucs2strlen((CHAR*)file_ext)))
                {
                    add_audio = MMI_FALSE;
                    mmi_ucs2cpy((CHAR*)odf_path, (CHAR*)gen_info->path_cache);
                    mmi_ucs2cat((CHAR*)odf_path, (CHAR*)buf_file_name);
                    
                    if (!DRM_is_archive(0, (PU16)odf_path))
                    {
                        ext_name_p = (PU8)DRM_get_content_ext(0, (PU16)odf_path);
                        if (ext_name_p != NULL)
                        {
                            mmi_asc_n_to_ucs2((CHAR*)ext_in_odf, (CHAR*)ext_name_p, strlen((const char *)ext_name_p));
                            ext_in_odf[strlen((const char *)ext_name_p)] = 0;
                            if (music_playlist_lookup_audio_file_format(ext_in_odf) >= 0)
                            {
                                add_audio = MMI_TRUE;
                            }
                            else
                            {
                                add_audio = MMI_FALSE;
                            }
                        }
                        else
                        {
                            file_ext[0] = 0;
                        }
                    }
                    else
                    {
                        mmi_ucs2ncpy((CHAR*)gen_info->path_cache, (CHAR*)odf_path, (SRV_FMGR_PATH_MAX_LEN+1));
                        gen_info->stack_index++;
                        gen_info->phase = MMI_AUDPLY_LIST_PHASE_SEARCH_ODF;
                        music_playlist_search_continue_req((void*)list_cntx);
                        return;
                    }
                }
                else
                {
                    add_audio = MMI_TRUE;
                }
                if (add_audio)
        #endif  /* __DRM_V02__ */
                {
                    if (mmi_ucs2strlen((CHAR*)gen_info->path_cache) + 
                        mmi_ucs2strlen((CHAR*)buf_file_name) <= (SRV_FMGR_PATH_MAX_LEN+1))
                    {
                        mmi_ucs2cpy((CHAR*)file_path, (CHAR*)gen_info->path_cache);
                        mmi_ucs2cat((CHAR*)file_path, (CHAR*)buf_file_name);

                        if (gen_info->total_number < SRV_PLAYLIST_MAX_PLAYLIST_ITEM)
                        {
                            MMI_BOOL is_short = (file_info.NTReserved == FS_SFN_MATCH) ? MMI_TRUE : MMI_FALSE;

                            /* add media file data to data file. */
                            ret = music_playlist_generate_append_one(list_cntx, file_path, is_short, MMI_FALSE);
                            if (ret < 0)
                            {
                                FS_FindClose(gen_info->search_handle);
                                gen_info->search_handle = -1;
                                gen_info->last_error_code = ret;
                                gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_ERR_HDLR;
                                music_playlist_search_continue_req((void*)list_cntx);
                                return;
                            }
                            else
                            {
                                gen_info->appended_number++;
                                gen_info->total_number++;
                                MMI_ASSERT(gen_info->total_number <= SRV_PLAYLIST_MAX_PLAYLIST_ITEM);
                            }
                        }
                        else
                        {
                            FS_FindClose(gen_info->search_handle);
                            gen_info->search_handle = -1;
                            gen_info->last_error_code = SRV_PLAYLIST_PLST_FULL;
                            gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_ERR_HDLR;
                            music_playlist_search_continue_req((void*)list_cntx);
                            return;                    
                        }
                    }
                    
                    /* skip to ask other messages. */
                    if ((++i) == MUSIC_PLAYLIST_MAX_PICK_PER_SLICE)    
                    {
                        FS_Commit(gen_info->list_file_handle);
                        music_playlist_search_continue_req((void*)list_cntx);
                        return;
                    }
                }
            }
        }
        /* the finded file is a folder. */
        else if (file_info.Attributes & FS_ATTR_DIR)
        {
            /* skip "dot" and "dot dot". */
            if (mmi_ucs2strlen((CHAR*)buf_file_name) < 3)
            {
                if (mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)L".") &&
                    mmi_ucs2cmp((CHAR*)buf_file_name, (CHAR*)L".."))
                {
                    gen_info->stack[gen_info->stack_index].total_sub_folder++;
                }
            }
            else
            {
                gen_info->stack[gen_info->stack_index].total_sub_folder++;
            }
        }

        /* continue to find next file in this folder level. */
        ret = FS_FindNextN(
                        gen_info->search_handle,
                        NULL,
                        0,
                        FS_ATTR_DIR,
                        &file_info,
                        (PU16)buf_file_name,
                        (SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH,
                        FS_FIND_DEFAULT);
    } while (ret == FS_NO_ERROR);
    
    FS_FindClose(gen_info->search_handle);
    FS_Commit(gen_info->list_file_handle);
    gen_info->search_handle = -1;
    if (gen_info->stack_index < MUSIC_PLAYLIST_MAX_DEPTH_DIRECTORY)
    {
        gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_FORWARDS;
    }
    else
    {
        gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_BACKWARDS;
    }
    
    music_playlist_search_continue_req((void*)list_cntx);
    return;
}


/*****************************************************************************
 * FUNCTION
 *  music_playlist_generate_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void music_playlist_generate_internal(void* msg)
{
    music_playlist_action_req_struct* req_msg = (music_playlist_action_req_struct*)msg;
    music_playlist_cntx_struct* list_cntx = (music_playlist_cntx_struct*)req_msg->context;

    MMI_TRACE(TRACE_GROUP_2, TRC_MUSIC_PLST_GENERATE_INTERNAL, list_cntx->generate_info.phase);

    switch (list_cntx->generate_info.phase)
    {
        case MUSIC_PLAYLIST_GEN_PHASE_SEARCH_FIRST:
        case MUSIC_PLAYLIST_GEN_PHASE_SEARCH_NEXT:
        {
            music_playlist_generate_search(list_cntx);
            break;
        }
           
        case MUSIC_PLAYLIST_GEN_PHASE_FORWARDS:
        {
            music_playlist_generate_forwards(list_cntx);
            break;
        }
            
        case MUSIC_PLAYLIST_GEN_PHASE_BACKWARDS:
        case MUSIC_PLAYLIST_GEN_PHASE_BACKWARDS_ODF:
        {
            music_playlist_generate_backwards(list_cntx);
            break;
        }
            
        case MUSIC_PLAYLIST_GEN_PHASE_FINISH:
        {
            music_playlist_generate_finish(list_cntx);
            break;
        }
            
        case MUSIC_PLAYLIST_GEN_PHASE_ERR_HDLR:
        {
            music_playlist_generate_error_hdlr(list_cntx);
            break;
        }
            
        case MUSIC_PLAYLIST_GEN_PHASE_CANCEL:
        {
            music_playlist_generate_cancel_hdlr(list_cntx);
            break;        
        }
        
        case MUSIC_PLAYLIST_GEN_PHASE_SEARCH_ODF:
        {
#ifdef __DRM_V02__
            music_playlist_generate_search_odf(list_cntx);
#endif  // __DRM_V02__
                break;
        }
        
        default:
            break;
            //MMI_ASSERT(list_cntx->generate_info.phase <= MUSIC_PLAYLIST_GEN_PHASE_ERR_HDLR);
    }

    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_audply_playlist_generate_from_folder
 * DESCRIPTION
 *  async, search and add music file into broser list
 * PARAMETERS
 *  list_cntx:      [IN]   current service instance context struct
 *  path            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static S32 music_playlist_generate_from_folder(music_playlist_cntx_struct* list_cntx, UI_string_type path, MMI_BOOL is_multi_part_odf)
{
    music_playlist_generate_struct* gen_info = &(list_cntx->generate_info);
    music_playlist_list_struct* list = &(list_cntx->current_list);

    /* init generate variables. */
    memset(gen_info, 0x00, sizeof(music_playlist_generate_struct));
    
    gen_info->footer_pattern_offset = list->header.footer_pattern_offset;
    gen_info->list_file_handle = list->fs_hdlr;
    gen_info->appended_number = 0;
    gen_info->total_number = list->total;
    gen_info->last_error_code = 0;
    gen_info->search_handle = -1;
    mmi_ucs2cpy((CHAR*)gen_info->path_cache, (CHAR*)path);

    /* init the gen phase. */
    if (is_multi_part_odf)
    {
        gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_SEARCH_ODF;
    }
    else
    {
        gen_info->phase = MUSIC_PLAYLIST_GEN_PHASE_SEARCH_FIRST;
        gen_info->stack_index = 0;
        /* max support 16 level folder. */
        memset((gen_info->stack), 0x00, MUSIC_PLAYLIST_MAX_DEPTH_DIRECTORY * sizeof(music_playlist_stack_node_struct));
    }

    /* seek to the end of current playlist file. */
    (void)FS_Seek(list->fs_hdlr, list->header.footer_pattern_offset, FS_FILE_BEGIN);
    /* cut off the footer area in list file. */
    FS_Truncate(list->fs_hdlr);

    SetProtocolEventHandler(music_playlist_generate_internal, MSG_ID_PLS_LIST_SEARCH_REQ);
    music_playlist_search_continue_req((void*)list_cntx);
    
    return SRV_PLAYLIST_OK;
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_generate_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void music_playlist_generate_cancel(music_playlist_cntx_struct* list_cntx)
{
    list_cntx->generate_info.phase = MUSIC_PLAYLIST_GEN_PHASE_CANCEL;
    music_playlist_search_continue_req((void*)list_cntx);
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_generate
 * DESCRIPTION
 *  search and add file into play list (current broswer play list)
 * PARAMETERS
 *  list_cntx:    [IN]   playlist context, which file will be added
 *  fullPath :    [IN]   file or folder full path
 *  is_short :    [IN]   short or long char
 * RETURNS
 *  return error code
 *****************************************************************************/
static S32 music_playlist_generate(music_playlist_cntx_struct* list_cntx, UI_string_type fullPath, int is_short)
{
    UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    MMI_BOOL is_multi_part_odf = MMI_FALSE;
    S32 ret = SRV_PLAYLIST_OK;

    /* check broswer list item count. */
    if (list_cntx->current_list.total >= SRV_PLAYLIST_MAX_PLAYLIST_ITEM)
    {
        ret = SRV_PLAYLIST_PLST_FULL;
        return ret;
    }

    music_playlist_extract_ext(fullPath, ext);

#ifdef __DRM_V02__
    if (!mmi_ucs2nicmp((CHAR*)ext, (CHAR*)L"odf", (U32)mmi_ucs2strlen((CHAR*)ext)))
    {
        if (DRM_is_archive(0, (PU16)fullPath))
        {
            is_multi_part_odf = MMI_TRUE;
        }
    }
#endif  /* __DRM_V02__ */

    ret = music_playlist_generate_from_folder(list_cntx, fullPath, is_multi_part_odf);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_add_file
 * DESCRIPTION
 *  search and add file into play list (current broswer play list)
 * PARAMETERS
 *  list_cntx:    [IN]   playlist context, which file will be added
 *  fullPath :    [IN]   file or folder full path
 *  is_short :    [IN]   short or long char
 * RETURNS
 *  return error code
 *****************************************************************************/
static S32 music_playlist_add_file(music_playlist_cntx_struct* list_cntx, UI_string_type fullPath, int is_short)
{
    UI_character_type ext[SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1];
    MMI_BOOL is_multi_part_odf = MMI_FALSE;
    S32 ret = SRV_PLAYLIST_OK;

    /* check broswer list item count. */
    if (list_cntx->current_list.total >= SRV_PLAYLIST_MAX_PLAYLIST_ITEM)
    {
        ret = SRV_PLAYLIST_PLST_FULL;
        return ret;
    }

    music_playlist_extract_ext(fullPath, ext);

#ifdef __DRM_V02__
    if (!mmi_ucs2nicmp((CHAR*)ext, (CHAR*)L"odf", (U32)mmi_ucs2strlen((CHAR*)ext)))
    {
        if (DRM_is_archive(0, (PU16)fullPath))
        {
            is_multi_part_odf = MMI_TRUE;
        }
    }
#endif  /* __DRM_V02__ */

    
    /* add DRM file. */
    if (is_multi_part_odf)
    {
        ret = music_playlist_generate_from_folder(list_cntx, fullPath, MMI_TRUE);
    }
    else
    {
        /* not supported file type. */
        if (music_playlist_lookup_audio_file_format(ext) < 0)
        {
            return SRV_PLAYLIST_ERR_UNSUPPORTED_FILE;
        }

        /* append to playlist directly. */
        ret = music_playlist_generate_append_one(list_cntx, fullPath, (MMI_BOOL)is_short, MMI_TRUE);
        if (ret >= FS_NO_ERROR)
        {
            ret = SRV_PLAYLIST_OK;
        }
    }

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_search_continue_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void music_playlist_delete_req(S32 index, void *context)
{
    music_playlist_action_req_struct *req_param_ptr;
    
    req_param_ptr = (music_playlist_action_req_struct* )construct_local_para(sizeof(music_playlist_action_req_struct), TD_CTRL);
    req_param_ptr->context = context;
    req_param_ptr->para_1 = index;
    music_playlist_send_msg(MOD_MMI, MOD_MMI, MSG_ID_PLS_LIST_ITEM_DELETE_REQ, req_param_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_delete
 * DESCRIPTION
 *  delete all marked items
 * PARAMETERS
 * 
 * RETURNS
 *  return error code
 *****************************************************************************/
static S32 music_playlist_delete_remove(music_playlist_cntx_struct* list_cntx, S32 index)
{
    music_playlist_list_struct* list = &(list_cntx->current_list);
    music_playlist_block_node_struct block;
    U32 backup_offset = 0;
    U32 current_offset = 0;
    U32 next_offset = 0;
    U32 fs_size = 0;
    S32 ret = SRV_PLAYLIST_OK;
    U8 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (index >= SRV_PLAYLIST_MAX_PLAYLIST_ITEM)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }
    else if (index < 0)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }
    
    /* delet current active file. */
    if (list->pick_index == index)
    {
        /* can not delete active item. */
        return SRV_PLAYLIST_DELETE_ACTIVE;
    }
    else
    {
        if (list->pick_index > index)
        {
            list->pick_index--;
        }
    }

    /* first, backup original empty node offset. */
    backup_offset = list->header.empty_node.offset;

    /* second, new empty node point to the deleting one. */
    list->header.empty_node.offset = list->header.index[index].offset;
    list->header.empty_node.used_block += list->header.index[index].used_block;

    /* clean deleting node info. */
    list->header.index[index].is_active = 0;
    list->header.index[index].index = SRV_PLAYLIST_MAX_PLAYLIST_ITEM;
    list->header.index[index].offset = 0;

    /* if current song be plaied,  */
    if (IsBitSetOn(index, list->bitset))
    {
        list->pick_count--;
        ClrBitSet(index, list->bitset);
    }
    
    current_offset = list->header.empty_node.offset;
    next_offset = current_offset;

    do
    {
        /* fine the last block of deleting node. */
        for (i = 0; i < list->header.index[index].used_block; i++)
        {
            /* reach the end of the node. */
            if (next_offset == 0)
            {
                break;
            }
            
            ret = FS_Seek(list->fs_hdlr, next_offset, FS_FILE_BEGIN);
            if (ret < FS_NO_ERROR)
            {
                ret = SRV_PLAYLIST_ERR_FS_ERROR;
                break;
            }

            /* current_offset point to the last block offset. */
            current_offset = next_offset;
            ret = FS_Read(list->fs_hdlr, &block, sizeof(music_playlist_block_node_struct), &fs_size);
            if (ret < FS_NO_ERROR)
            {
                ret = SRV_PLAYLIST_ERR_FS_ERROR;
                break;
            }

            if (fs_size != sizeof(music_playlist_block_node_struct))
            {
                ret = SRV_PLAYLIST_ERR_FS_ERROR;
                break;
            }
            
            if ((MUSIC_PLAYLIST_BLOCK_PATTERN_1 != block.pattern_begin)
                || (MUSIC_PLAYLIST_BLOCK_PATTERN_2 != block.pattern_end))
            {
                ret = SRV_PLAYLIST_ERR_FILE_DAMAGE;
                break;
            }
            
            /* clean older block data, write back into file. */
            memset(&(block.data), 0x00, MUSIC_PLAYLIST_BLOCK_DATA_SIZE);
            ret = FS_Seek(list->fs_hdlr, next_offset, FS_FILE_BEGIN);
            if (ret > FS_NO_ERROR)
            {
                (void)FS_Write(list->fs_hdlr, &block, sizeof(music_playlist_block_node_struct), &fs_size);
                if (fs_size != sizeof(music_playlist_block_node_struct))
                {
                    ret = SRV_PLAYLIST_ERR_FS_ERROR;
                    break;
                }
            }

            /* move to next block. */
            next_offset = block.next_ptr;
        }

        if (ret < SRV_PLAYLIST_OK)
        {
            break;
        }

        /* link original empty node to the end of current deleting node. */
        block.next_ptr = backup_offset;

        /* write the last block data into file. */
        ret = FS_Seek(list->fs_hdlr, current_offset, FS_FILE_BEGIN);
        ret = FS_Write(list->fs_hdlr, &block, sizeof(music_playlist_block_node_struct), &fs_size);
        if (ret < FS_NO_ERROR)
        {
            ret = SRV_PLAYLIST_ERR_FS_ERROR;
            break;
        }
        if (fs_size != sizeof(music_playlist_block_node_struct))
        {
            ret = SRV_PLAYLIST_ERR_FS_ERROR;
            break;
        }
    } while (0);
    
    if (ret >= FS_NO_ERROR)
    {
        list->header.total_slot--;
        list->total--;
        //list_cntx->list_ui.total--;
        ret = SRV_PLAYLIST_OK;
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_MUSIC_PLST_DELETE_ITEM, index, ret, list->total);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_delete_sort
 * DESCRIPTION
 *  delete all marked items
 * PARAMETERS
 * 
 * RETURNS
 *  return error code
 *****************************************************************************/
static S32 music_playlist_delete_sort(music_playlist_cntx_struct* list_cntx)
{
    music_playlist_list_struct* list = &(list_cntx->current_list);
    S32 ret = SRV_PLAYLIST_OK;
    
    music_playlist_generate_sort_index(list->header.index, 0, list->header.total_slot);
    MMI_ASSERT(MUSIC_PLAYLIST_FOOTER_PATTERN == list->header.pattern);
    
    {
        U16 i = 0;
        U16 empty = 0;
        U16 used = list->header.total_slot;
        U16 total = list->header.total_slot + 1;
        music_playlist_index_node_struct* node = list->header.index;

        for (i = 0; i < total; i++)
        {
            if (node[i].index != i)
            {
                if (SRV_PLAYLIST_MAX_PLAYLIST_ITEM == node[i].index)
                {
                    node[i].index = used + empty;
                    empty++;
                }
                else
                {
                    node[i].index = i;
                }
            }
        }
    }
    
    ret = music_playlist_write_back_to_file(list);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_delete_marked
 * DESCRIPTION
 *  delete all marked items
 * PARAMETERS
 * 
 * RETURNS
 *  return error code
 *****************************************************************************/
static void music_playlist_delete_marked(void* msg)
{
    music_playlist_action_req_struct* req_msg = (music_playlist_action_req_struct*)msg;
    music_playlist_cntx_struct* list_cntx = (music_playlist_cntx_struct*)req_msg->context;
    music_playlist_list_struct* list = &(list_cntx->current_list);
    srv_playlist_cb_evt_enum cb_event = SRV_PLAYLIST_CB_EVT_DELETE;
    S32 ret = SRV_PLAYLIST_OK;
    U32 i = 0;

    MMI_TRACE(TRACE_GROUP_2, TRC_MUSIC_PLST_DELETE_MARKED, list->mark_count, list->delete_count, __LINE__);

    do
    {
        if (0 == list->mark_count)
        {
            ret = SRV_PLAYLIST_OK;
            break;
        }
        
        while ((list->delete_count < list->mark_count)
                && (list->delete_group < MUSIC_PLAYLIST_MAX_BITSET_SIZE))
        {
            /* 1st, check whether delete be canceled. */
            if (list->delete_canceled)
            {
                list->delete_canceled = MMI_FALSE;
                break;
            }
        
            /* check whether has item be selected in current grounp . */
            if (!(list->bitMark[list->delete_group] && 0xFF))
            {
                list->delete_group ++;
                continue;
            }

            /* 2nd, delete items of current group. */
            for (i=0; i<8*sizeof(U8); i++)
            {
                U32 index = list->delete_group*8*sizeof(U8) + i;
                if (IsBitSetOn(index, list->bitMark))
                {
                    /* when an item deleted (music_playlist_delete_remove), \
                       all after items' index in playlist will -1, \
                       so need convert item index in mark table to index in playlist. */
                    U32 delete_index = index - list->delete_count;

                    ret += music_playlist_delete_remove(list_cntx, delete_index);
                    if (SRV_PLAYLIST_OK != ret)
                    {
                        if (SRV_PLAYLIST_DELETE_ACTIVE == ret)
                        {
                            cb_event = SRV_PLAYLIST_CB_EVT_DELETE_ACTIVE;
                        }
                        break;
                    }
                    
                    ClrBitSet(index, list->bitMark);
                    list->delete_count ++;

                    /* sort playlist item, must sort after delete one item. */
                    (void)music_playlist_delete_sort(list_cntx);
                    
                    /* notify caller current progress. */
                    if (list_cntx->callback)
                    {
                        U32 progress = (list->delete_count*100) / (list->mark_count);
                        music_playlist_send_event(SRV_PLAYLIST_CB_EVT_DELETE_PROGRESS, 0, progress);
                    }

                    /* delete done. */
                    if (list->delete_count == list->mark_count)
                    {
                        break;
                    }
                }
            }
            
            list->delete_group ++;

            /* 3rd, async to next group, or stop delete. */
            if (SRV_PLAYLIST_OK == ret)
            {
                /* current group items delete done, continue to next group. */
                SetProtocolEventHandler(music_playlist_delete_marked, MSG_ID_PLS_LIST_ITEM_DELETE_REQ);
                music_playlist_delete_req(-1, (void*)list_cntx);
                return;
            }
            else
            {
                /* delete item failed, stop delete, eg:active item. */
                break;
            }
        }

        /* 4th, reset list view info. */
        memset(&(list_cntx->list_ui), 0x00, sizeof(music_playlist_dynamic_list_data_struct));
    } while (0);

    /* delete mraked items done or stoped by error, notify caller. */
    music_playlist_send_event(cb_event, ret, list->delete_count);
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_delete
 * DESCRIPTION
 *  delete one song from playlist file, has three steps:
 *    1st, deinit deleting block data write to file, insert into the header of empty node 
 *    2nd, update playlist header(header_struct) and node[index](index_node_struct) 
 *    3rd, write new header info into playlist file
 * PARAMETERS
 *  index :    [IN]
 * RETURNS
 *  return error code
 *****************************************************************************/
static void music_playlist_delete(void *msg)
{
    music_playlist_action_req_struct* req_msg = (music_playlist_action_req_struct*)msg;
    music_playlist_cntx_struct* list_cntx = (music_playlist_cntx_struct*)req_msg->context;
    srv_playlist_cb_evt_enum cb_event = SRV_PLAYLIST_CB_EVT_DELETE;
    S32 index = req_msg->para_1;
    S32 ret = SRV_PLAYLIST_OK;
    U32 delete_count = 0;

    ret = music_playlist_delete_remove(list_cntx, index);
    if (SRV_PLAYLIST_OK == ret)
    {
        (void)music_playlist_delete_sort(list_cntx);

        /* reset list view info. */
        memset(&(list_cntx->list_ui), 0x00, sizeof(music_playlist_dynamic_list_data_struct));
        cb_event = SRV_PLAYLIST_CB_EVT_DELETE;
        delete_count = 1;
    }
    else if (SRV_PLAYLIST_DELETE_ACTIVE == ret)
    {
        cb_event = SRV_PLAYLIST_CB_EVT_DELETE_ACTIVE;
        delete_count = 0;
    }

    /* delete done, notify caller. */
    music_playlist_send_event(SRV_PLAYLIST_CB_EVT_DELETE_PROGRESS, 0, 100);
    music_playlist_send_event(cb_event, ret, delete_count);
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_comp
 * DESCRIPTION
 *  compare to index
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static S32 music_playlist_comp(const void* a, const void* b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((*(music_playlist_index_node_struct*)a).index - (*(music_playlist_index_node_struct*)b).index);
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_swap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void music_playlist_swap(CHAR *a, CHAR *b, U32 data_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR tmp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (a != b)
    {
        while (data_width--) 
        {
            tmp = *a;
            *a++ = *b;
            *b++ = tmp;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_qsort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void music_playlist_qsort(void *sort_base, U32 number, U32 data_width)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *low_item_ptr, *hight_item_ptr, *low_ptr, *high_ptr, *middle_ptr;
    CHAR *low_stack[30], *high_stack[30];
    S32 stack_ptr = 0;
    U32 buffer_size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(2 > number || 0 == data_width)
    {
        return;
    }

    high_ptr = (CHAR *) sort_base + data_width * (number - 1);
    low_ptr = sort_base;

recursion:
    buffer_size = (high_ptr - low_ptr) / data_width + 1;
    middle_ptr = low_ptr + (buffer_size / 2) * data_width;
    music_playlist_swap((CHAR*)middle_ptr, (CHAR*)low_ptr, data_width);
    hight_item_ptr = data_width + high_ptr;
    low_item_ptr = low_ptr;

    do
    {
        do 
        { 
            low_item_ptr += data_width; 
        } while (low_item_ptr <= high_ptr && music_playlist_comp(low_item_ptr, low_ptr) <= 0);
        
        do 
        { 
            hight_item_ptr -= data_width; 
        } while (hight_item_ptr > low_ptr && music_playlist_comp(hight_item_ptr, low_ptr) >= 0);
        
        if (low_item_ptr > hight_item_ptr) 
        {
            break;
        }
        music_playlist_swap((CHAR*)low_item_ptr, (CHAR*)hight_item_ptr, data_width);
    }while(1);

    music_playlist_swap((CHAR*)low_ptr, (CHAR*)hight_item_ptr, data_width);

    if (high_ptr - low_item_ptr > hight_item_ptr - low_ptr - 1) 
    {
        if (low_item_ptr < high_ptr) 
        {
            high_stack[stack_ptr] = high_ptr;
            low_stack[stack_ptr] = low_item_ptr;
            ++stack_ptr;
        }
        if (low_ptr + data_width < hight_item_ptr) 
        {
            high_ptr = hight_item_ptr - data_width;
            goto recursion;
        }
    }
    else
    {
        if (hight_item_ptr > low_ptr + data_width) 
        {
            high_stack[stack_ptr] = hight_item_ptr - data_width;
            low_stack[stack_ptr] = low_ptr;
            ++stack_ptr;
        }
        if (high_ptr > low_item_ptr) 
        {
            low_ptr = low_item_ptr;
            goto recursion;
        }
    }

    --stack_ptr;
    if (stack_ptr >= 0) 
    {
        high_ptr = high_stack[stack_ptr];
        low_ptr = low_stack[stack_ptr];
        goto recursion;
    }
    else
    {
        return;
    }
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_generate_sort_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void music_playlist_generate_sort_index(music_playlist_index_node_struct* index, S32 low, S32 high)
{
    music_playlist_qsort(index, high + 1, sizeof(music_playlist_index_node_struct));
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_error_handler
 * DESCRIPTION
 *  play list file error handling
 * PARAMETERS
 *  list_cntx: [IN]   list_cntx
 *  error:     [IN]   error code
 * RETURNS
 *  S32
 *****************************************************************************/
static void music_playlist_error_handler(music_playlist_cntx_struct* list_cntx, S32 error)
{
    if ((SRV_PLAYLIST_ERR_FILE_DAMAGE == error)
        || (SRV_PLAYLIST_ERR_VERSION_WRONG == error))
    {
        /* play list file damaged, delete it. */
        FS_Close(list_cntx->current_list.fs_hdlr);
        FS_Delete(list_cntx->current_list.path);
        
        list_cntx->list_loaded = MMI_FALSE;
        memset(&(list_cntx->current_list), 0x00, sizeof(music_playlist_list_struct));
        memset(&(list_cntx->list_ui), 0x00, sizeof(music_playlist_dynamic_list_data_struct));
    }
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_search_continue_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void music_playlist_open_req(UI_string_type file_path, void *context)
{
    music_playlist_action_req_struct *req_param_ptr;
    
    req_param_ptr = (music_playlist_action_req_struct* )construct_local_para(sizeof(music_playlist_action_req_struct), TD_CTRL);
    req_param_ptr->context = context;
    req_param_ptr->para_2 = (void *)file_path;
    music_playlist_send_msg(MOD_MMI, MOD_MMI, MSG_ID_PLS_LIBRARY_OPEN_REQ, req_param_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_open
 * DESCRIPTION
 *  open a list file. 
 * PARAMETERS
 *  msg: [IN]   music_playlist_action_req_struct
 * RETURNS
 *  S32
 *****************************************************************************/
static void music_playlist_open(void *msg)
{
    music_playlist_action_req_struct* req_msg = (music_playlist_action_req_struct*)msg;
    music_playlist_cntx_struct* list_cntx = (music_playlist_cntx_struct*)req_msg->context;
    music_playlist_list_struct* playlist = &(list_cntx->current_list);
    UI_string_type file_path = (UI_string_type)req_msg->para_2;

    CHAR* filename = NULL;
    CHAR* dot = NULL;
    U32 file_size = 0;
    U32 read_size = 0;
    U32 empty_size = 0;
    S32 fs_ret = FS_NO_ERROR;
    S32 ret = SRV_PLAYLIST_OK;

    mmi_ucs2ncpy((CHAR*)playlist->path, (CHAR*)file_path, mmi_ucs2strlen((CHAR*)file_path));

    do
    {
        /* open playlist file. */
        fs_ret = FS_Open(playlist->path, FS_READ_WRITE);
        if (fs_ret < FS_NO_ERROR)
        {
            ret = SRV_PLAYLIST_ERR_FS_ERROR;
            break;
        }

        /* catch the file name from the file path. */
        filename = mmi_ucs2rchr((CHAR*)file_path, (U16)L'\\');
        if (filename == NULL)
        {
            ret = SRV_PLAYLIST_ERR_BAD_PARA;
            break;
        }
        
        filename += 2;
        mmi_ucs2ncpy((CHAR*)playlist->title, (CHAR*)filename, SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
 
        /* catch the file name from the file path. */
        dot = mmi_ucs2rchr((CHAR*)playlist->title, (U16)L'.');
        if (dot == NULL)
        {
            ret = SRV_PLAYLIST_ERR_BAD_PARA;
            break;
        }
        *(dot + 1) = 0;
        *dot = 0;
        
        /* set variables. */
        playlist->fs_hdlr = fs_ret;
        playlist->pick_index = -1;
        playlist->pick_count = 0;
        playlist->total = 0;

        /* read the header info from the beging. */
        fs_ret = FS_Read(playlist->fs_hdlr, &(playlist->header), sizeof(music_playlist_header_struct), &read_size);
        if (fs_ret < FS_NO_ERROR)
        {
            FS_Close(playlist->fs_hdlr);
            ret = SRV_PLAYLIST_ERR_FS_ERROR;
            break;
        }
        
        if (read_size != sizeof(music_playlist_header_struct))
        {
            FS_Close(playlist->fs_hdlr);
            ret = SRV_PLAYLIST_ERR_FILE_DAMAGE;
            break;
        }
        
        /* check type id and version. */
        if (strncmp((CHAR*)(playlist->header.type_id), MUSIC_PLAYLIST_TYPE_ID, 4))
        {
            ret = SRV_PLAYLIST_ERR_FILE_DAMAGE;
            break;
        }

        if (strncmp((CHAR*)(playlist->header.version), MUSIC_PLAYLIST_VERSION, 2))
        {
            ret = SRV_PLAYLIST_ERR_VERSION_WRONG;
            break;
        }

        if (MUSIC_PLAYLIST_FOOTER_PATTERN != playlist->header.pattern)
        {
            ret = SRV_PLAYLIST_ERR_FILE_DAMAGE;
            break;
        }

        /* check file size. */
        fs_ret = FS_GetFileSize(playlist->fs_hdlr, &file_size);
        if (fs_ret < FS_NO_ERROR)
        {
            ret = SRV_PLAYLIST_ERR_FILE_DAMAGE;
            break;
        }

        if (playlist->header.footer_pattern_offset != file_size) 
        {
            ret = SRV_PLAYLIST_ERR_FILE_DAMAGE;
            break;
        }

        /* check data block. */
        if (((playlist->header.footer_pattern_offset - sizeof(music_playlist_header_struct)) 
             % sizeof(music_playlist_block_node_struct)) != 0)
        {
            ret = SRV_PLAYLIST_ERR_FILE_DAMAGE;
            break;        
        }
        
        /* pass file type verification. */
        playlist->total = playlist->header.total_slot;
        fs_ret = FS_Seek(playlist->fs_hdlr, MUSIC_PLAYLIST_DATA_OFFSET, FS_FILE_BEGIN);
        if (fs_ret < FS_NO_ERROR)
        {
            ret = SRV_PLAYLIST_ERR_FS_ERROR;
            break;
        }
        
        music_playlist_generate_sort_index(playlist->header.index, 0, (playlist->total - 1));
        MMI_ASSERT(playlist->header.pattern == MUSIC_PLAYLIST_FOOTER_PATTERN);
        if (playlist->total)
        {
            empty_size = sizeof(music_playlist_index_node_struct) * 
                            (SRV_PLAYLIST_MAX_PLAYLIST_ITEM - playlist->header.total_slot);
            memset(&(playlist->header.index[playlist->total]), 0x00, empty_size);
            MMI_ASSERT(playlist->header.pattern == MUSIC_PLAYLIST_FOOTER_PATTERN);
            
            music_playlist_generate_sort_index(playlist->header.index, 0, (playlist->total - 1));
            MMI_ASSERT(playlist->header.pattern == MUSIC_PLAYLIST_FOOTER_PATTERN);
        }
    } while (0);

    /* set load success flag. */
    list_cntx->list_loaded = MMI_TRUE;
    if (ret < SRV_PLAYLIST_OK)
    {
        FS_Close(playlist->fs_hdlr);
        music_playlist_error_handler(list_cntx, ret);
        list_cntx->list_loaded = MMI_FALSE;
    }

    /* async operation, notify caller. */
    music_playlist_send_event(SRV_PLAYLIST_CB_EVT_OPEN, ret, 0);
    MMI_TRACE(TRACE_GROUP_2, TRC_MUSIC_PLST_OPEN_LIB, fs_ret, ret, __LINE__);
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_create_folder
 * DESCRIPTION
 *  delete cuurent folder, and create a new one.
 *  user must sure that library file is not exit, this func will delete the lib
 * PARAMETERS
 *  path    :    [IN]  folder path
 * RETURNS
 *  return error code
 *****************************************************************************/
static S32 music_playlist_create_folder(U16 *path)
{
    S32 ret = SRV_PLAYLIST_OK;
    FS_HANDLE fs_hdr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = FS_GetAttributes(path);
    if (ret >= 0 && !(ret & FS_ATTR_DIR))
    {
        /* in a very special case: user create a file named \
           "@service_player_internal" instead of folder, media \
           player will be no entry but with a popup forever. */
        FS_Delete(path);
    }
    
    fs_hdr = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    if (fs_hdr < FS_NO_ERROR)
    {
        fs_hdr = FS_CreateDir(path);
        if(fs_hdr < FS_NO_ERROR)
        {  
            return SRV_PLAYLIST_ERR_FS_ERROR;
        }
        else
        {
            FS_SetAttributes((WCHAR*)path, FS_ATTR_DIR | FS_ATTR_HIDDEN); 
        }
    }
    else
    {
        FS_SetAttributes((WCHAR*)path, FS_ATTR_DIR | FS_ATTR_HIDDEN); 
        FS_Close(fs_hdr);
    }

    return SRV_PLAYLIST_OK;
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_create
 * DESCRIPTION
 *  create a new play list file
 * PARAMETERS
 *  path    :    [IN]  full file path
 *  playlist:    [IN]  play list
 * RETURNS
 *  return error code
 *****************************************************************************/
static S32 music_playlist_create(const UI_string_type path, music_playlist_list_struct* playlist)
{
    music_playlist_header_struct* header = NULL;
    UI_character_type folder[(SRV_FMGR_PATH_MAX_LEN+1) + 1];
    FS_HANDLE fs_hdlr = -1;
    U32 write_size = 0;
    S32 fs_ret = FS_NO_ERROR;
    S32 ret = SRV_PLAYLIST_OK;
    MMI_BOOL space_enough = MMI_FALSE;          

    /* create new playlist. */
    do
    {
        /* create the folder. */
        if (!srv_fmgr_drv_is_accessible(path[0]))
        {
            return SRV_PLAYLIST_MSDC_NOTEXIST;
        }

        /* check if has enough memory to create playlist. */
        space_enough = music_playlist_check_free_space((CHAR)path[0], sizeof(music_playlist_header_struct));
        if (!space_enough)
        {
            return SRV_PLAYLIST_ERR_MEMORY_NOT_ENOUGH;
        }

        //kal_wsprintf((U16*)&folder, "%c:\\%w\\", SRV_FMGR_CARD_DRV, MUSIC_PLAYLIST_LIB_FOLDER);
        music_playlist_extract_folder(folder, path);
        ret = music_playlist_create_folder(folder);
        if (SRV_PLAYLIST_OK != ret)
        {
            return ret;
        }

        fs_ret = FS_Open(path, FS_CREATE | FS_READ_WRITE);
        if (fs_ret < FS_NO_ERROR)
        {
            ret = SRV_PLAYLIST_ERR_FS_ERROR;
            break;
        }
        else
        {
            fs_hdlr = fs_ret;
        }

        /* init header info. */
        header = &(playlist->header);
        memset(header, 0x00, sizeof(music_playlist_header_struct));
        header->footer_pattern_offset = MUSIC_PLAYLIST_DATA_OFFSET;
        strncpy((CHAR*)header->type_id, MUSIC_PLAYLIST_TYPE_ID, 4);
        strncpy((CHAR*)header->version, MUSIC_PLAYLIST_VERSION, 2);
        header->pattern = MUSIC_PLAYLIST_FOOTER_PATTERN;

        /* write header info into file */
        fs_ret = FS_Write(fs_hdlr, header, sizeof(music_playlist_header_struct), &write_size);
        if (fs_ret < FS_NO_ERROR)
        {
            ret = SRV_PLAYLIST_ERR_FS_ERROR;
            break;
        }
        else if (write_size != sizeof(music_playlist_header_struct))
        {
            ret = SRV_PLAYLIST_ERR_FS_ERROR;
            break;
        }
    } while (0);
    
    FS_Commit(fs_hdlr);
    FS_Close(fs_hdlr);

    /* create failed, delete current file. */
    if (ret < SRV_PLAYLIST_OK)
    {
        FS_Delete(path);
    }

    MMI_TRACE(TRACE_GROUP_2, TRC_MUSIC_PLST_CREATE_PLST, fs_ret, ret);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_pre_format_hdlr
 * DESCRIPTION
 *  plug out hdlr 
 * PARAMETERS
 *  drv_num     [IN]
 *  drv         [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void music_playlist_pre_format_hdlr(music_playlist_cntx_struct *list_cntx, CHAR drv)
{
    if (!list_cntx)
    {
        return;
    }

    if (SRV_FMGR_CARD_DRV == (U8)drv)
    {
    #ifndef __MMI_MUSIC_PLAYER_PHONE_DRIVE__
        /* close list file. */
        FS_Close(list_cntx->current_list.fs_hdlr);
        
        list_cntx->list_loaded = MMI_FALSE;
        memset(&(list_cntx->current_list), 0x00, sizeof(music_playlist_list_struct));
        memset(&(list_cntx->list_ui), 0x00, sizeof(music_playlist_dynamic_list_data_struct));
    #endif  // __MMI_MUSIC_PLAYER_PHONE_DRIVE__

        music_playlist_send_event(SRV_PLAYLIST_CB_EVT_PRE_FORMAT, SRV_PLAYLIST_OK, 0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_after_format_hdlr
 * DESCRIPTION
 *  plug out hdlr 
 * PARAMETERS
 *  drv_num     [IN]
 *  drv_list    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void music_playlist_after_format_hdlr(music_playlist_cntx_struct *list_cntx, CHAR drv)
{
    if (!list_cntx)
    {
        return;
    }

    if (SRV_FMGR_CARD_DRV == (U8)drv)
    {
        music_playlist_send_event(SRV_PLAYLIST_CB_EVT_AFT_FORMAT, SRV_PLAYLIST_OK, 0);
    }
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_msdc_plug_in_hdlr
 * DESCRIPTION
 *  plug out hdlr 
 * PARAMETERS
 *  drv_num     [IN]
 *  drv_list    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void music_playlist_msdc_plug_in_hdlr(music_playlist_cntx_struct *list_cntx, U8 drv_num, PU8 drv_list)
{
    U8 i = 0;

    for(i = 0; i < drv_num; i++)
    {
        if(SRV_FMGR_CARD_DRV == drv_list[i])
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_MUSIC_PLST_MSDC_PLUG_IN);
        
            /* do nothing, just notify app. */
            music_playlist_send_event(SRV_PLAYLIST_CB_EVT_MSDC_PLUG_IN, SRV_PLAYLIST_OK, 0);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  music_playlist_msdc_plug_out_hdlr
 * DESCRIPTION
 *  plug out hdlr 
 * PARAMETERS
 *  drv_num     [IN]
 *  drv_list    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void music_playlist_msdc_plug_out_hdlr(music_playlist_cntx_struct *list_cntx, U8 drv_num, PU8 drv_list)
{
    U8 i = 0;

    if (!list_cntx)
    {
        return;
    }
    
    for (i = 0; i < drv_num; i ++)
    {
        if (SRV_FMGR_CARD_DRV == drv_list[i])
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_MUSIC_PLST_MSDC_PLUG_OUT);
            
            if (list_cntx->list_loaded)
            {
            #ifndef __MMI_MUSIC_PLAYER_PHONE_DRIVE__
                if ((MUSIC_PLAYLIST_GEN_PHASE_END != list_cntx->generate_info.phase)
                    && (MUSIC_PLAYLIST_GEN_PHASE_INIT != list_cntx->generate_info.phase))
                {
                    music_playlist_generate_cancel_hdlr(list_cntx);
                }
            
                /* close list file. */
                FS_Close(list_cntx->current_list.fs_hdlr);
                
                list_cntx->list_loaded = MMI_FALSE;
                list_cntx->current_list.delete_canceled = MMI_TRUE;
                memset(&(list_cntx->current_list), 0x00, sizeof(music_playlist_list_struct));
                memset(&(list_cntx->list_ui), 0x00, sizeof(music_playlist_dynamic_list_data_struct));
            #endif  // __MMI_MUSIC_PLAYER_PHONE_DRIVE__

                music_playlist_send_event(SRV_PLAYLIST_CB_EVT_MSDC_PLUG_OUT, SRV_PLAYLIST_OK, 0);
            }
        }
    }
}

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
S32 srv_playlist_create_instance(srv_playlist_create_struct* pPara, U32* pHandle)
{    
    music_playlist_cntx_struct *list_cntx;
    S32 ret = SRV_PLAYLIST_OK;

    /* check input para */
    if (!pPara || !pPara->mem_ptr)
    {
        ret = SRV_PLAYLIST_ERR_BAD_PARA;
        return ret;
    }
    
    if (SRV_PLAYLIST_MIN_MEM_SIZE > pPara->mem_size)
    {
        ret = SRV_PLAYLIST_ERR_BAD_PARA;
        return ret;
    }

    /* malloc context memory from adm. */
    list_cntx = kal_adm_alloc(pPara->mem_ptr, sizeof(music_playlist_cntx_struct));
    if (!list_cntx)
    {
        ret = SRV_PLAYLIST_ERR_MEMORY_NOT_ENOUGH;
        return ret;
    }

    memset(list_cntx, 0x00, sizeof(music_playlist_cntx_struct));

    /* init para. */
    list_cntx->list_loaded = MMI_FALSE;
    list_cntx->create.mem_ptr = pPara->mem_ptr;
    list_cntx->create.mem_size = pPara->mem_size;
    list_cntx->create.gen_mem_size = pPara->gen_mem_size;
    list_cntx->create.max_item_support = SRV_PLAYLIST_MAX_PLAYLIST_ITEM;

    /* create success, keep current handle info. */
    g_instance = (U32)list_cntx;
    *pHandle = (plst_handle)list_cntx;

    MMI_TRACE(TRACE_GROUP_2, TRC_MUSIC_PLST_CREATE_INST, g_instance);
    return SRV_PLAYLIST_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_destroy_instance
 * DESCRIPTION
 *  reset, destory list service
 * PARAMETERS
 *  srv_plst_hdr :  [IN]   service handle
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 srv_playlist_destroy_instance(U32 srv_handle)
{
    music_playlist_cntx_struct *list_cntx;
    S32 ret = SRV_PLAYLIST_OK;

    if (!srv_handle)
    {
        ret = SRV_PLAYLIST_ERR_BAD_PARA;
        return ret;
    }

    /* free adm memory. */
    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    kal_adm_free(list_cntx->create.mem_ptr, list_cntx);

    /* cancel current operation. */
    ClearProtocolEventHandler(MSG_ID_PLS_LIST_SEARCH_REQ);
    ClearProtocolEventHandler(MSG_ID_PLS_LIST_ITEM_DELETE_REQ);
    ClearProtocolEventHandler(MSG_ID_PLS_LIBRARY_OPEN_REQ);

    g_instance = 0;
    MMI_TRACE(TRACE_GROUP_2, TRC_MUSIC_PLST_DESTORY_INST, srv_handle);
    return SRV_PLAYLIST_OK;
}

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
 *  return error code
 *****************************************************************************/ 
S32 srv_playlist_register_callback(U32 srv_handle, cb_func callback, void* user_data)
{
    music_playlist_cntx_struct *list_cntx;
    S32 ret = SRV_PLAYLIST_OK;

    /* check input para. */
    if (!srv_handle)
    {
        ret = SRV_PLAYLIST_ERR_BAD_PARA;
        return ret;
    }

    if (!callback)
    {
        ret = SRV_PLAYLIST_ERR_BAD_PARA;
        return ret;
    }
 
    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    list_cntx->callback = callback;
    list_cntx->user_data = user_data;

    return SRV_PLAYLIST_OK;
}

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
void srv_playlist_deregister_callback(U32 srv_handle)
{
    music_playlist_cntx_struct *list_cntx;

    /* check input para. */
    if (!srv_handle)
    {
        return;
    }

    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    list_cntx->callback = NULL;
    list_cntx->user_data = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_open_library
 * DESCRIPTION
 *  async open library, open the defined play list file
 * PARAMETERS
 *  file_path:  [IN]     play list file full path
 * RETURNS
 *  return error code
 *****************************************************************************/ 
S32 srv_playlist_open_library(U32 srv_handle)
{
    music_playlist_cntx_struct *list_cntx;
    S32 ret = SRV_PLAYLIST_OK;
    U8 drv = SRV_FMGR_PHONE_DRV;

    /* check input para. */
    if (!srv_handle)
    {
        ret = SRV_PLAYLIST_ERR_BAD_PARA;
        return ret;
    }

    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    
    /* check whether is the loaded playlist. user should close \
       it firstly, currently support only one playlist. */
    if (list_cntx->list_loaded)
    {
        return SRV_PLAYLIST_OK;
    }

#ifndef __MMI_MUSIC_PLAYER_PHONE_DRIVE__
    /* check if card exist or available. */
    drv = SRV_FMGR_CARD_DRV;
    if (!music_playlist_check_card_state())
    {
        return SRV_PLAYLIST_MSDC_NOTEXIST;
    }
#endif  // __MMI_MUSIC_PLAYER_PHONE_DRIVE__

    /* generate playlist file name. */
    kal_wsprintf((U16*)&(list_cntx->current_list.path),
                  "%c:\\%w\\%w.%w",
                  drv,
                  MUSIC_PLAYLIST_LIB_FOLDER,
                  MUSIC_PLAYLIST_LIB_FILE_NAME,
                  MUSIC_PLAYLIST_LIB_FILE_EXT);

    ret = FS_GetAttributes(list_cntx->current_list.path); 
    if (ret < FS_NO_ERROR)
    {
        /* file not exit, create the file first. */
        ret = music_playlist_create(list_cntx->current_list.path, &(list_cntx->current_list));
        if (SRV_PLAYLIST_OK != ret)
        {
            return ret;
        }
    }

    /* async open the play list file. */
    SetProtocolEventHandler(music_playlist_open, MSG_ID_PLS_LIBRARY_OPEN_REQ);
    music_playlist_open_req(list_cntx->current_list.path, (void*)list_cntx);
    
    return SRV_PLAYLIST_ASYNC;
}

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_close_library
 * DESCRIPTION
 *  close current viewed play list file
 * PARAMETERS
 *  srv_handle:  [IN]     service handle
 * RETURNS
 *  return error code
 *****************************************************************************/ 
S32 srv_playlist_close_library(U32 srv_handle)
{
    music_playlist_cntx_struct *list_cntx = NULL;
    S32 ret = SRV_PLAYLIST_OK;

    /* check input para. */
    if (!srv_handle)
    {
        ret = SRV_PLAYLIST_ERR_BAD_PARA;
        return ret;
    }

    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    if (!list_cntx->list_loaded)
    {
        return SRV_PLAYLIST_OK;
    }

    /* close list file. */
    FS_Close(list_cntx->current_list.fs_hdlr);

    // TODO:
    list_cntx->list_loaded = MMI_FALSE;
    memset(&(list_cntx->current_list), 0x00, sizeof(music_playlist_list_struct));
    memset(&(list_cntx->list_ui), 0x00, sizeof(music_playlist_dynamic_list_data_struct));

    MMI_TRACE(TRACE_GROUP_2, TRC_MUSIC_PLST_CLOSE_LIB, srv_handle);
    return SRV_PLAYLIST_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_add_file
 * DESCRIPTION
 *   sync add file, add a input file to current viewed library
 * PARAMETERS
 *  srv_handle:    [IN]   service handle
 *  file_path :    [IN]   filepath or folder path
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_playlist_add_file(U32 srv_handle, UI_string_type file_path)
{
    music_playlist_cntx_struct * list_cntx = NULL;
    S32 ret = SRV_PLAYLIST_OK;

    /* check input para. */
    if (!srv_handle || !file_path)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }
    
    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    ret = music_playlist_add_file(list_cntx, file_path, MMI_FALSE);

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_add_from_folder
 * DESCRIPTION
 *   async add file, search and add files from input folder to library, not all drivers
 * PARAMETERS
 *  srv_handle :    [IN]   service handle
 *  folder_path:    [IN]   filepath or folder path
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_playlist_add_from_folder(U32 srv_handle, UI_string_type folder_path)
{
    music_playlist_cntx_struct * list_cntx = NULL;
    S32 ret = SRV_PLAYLIST_OK;

    /* check input para. */
    if (!srv_handle || !folder_path)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }
    
    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    ret = music_playlist_generate(list_cntx, folder_path, MMI_FALSE);
    if (SRV_PLAYLIST_OK == ret)
    {
        /* async process, need more time to search file, 
           then will be notify caller from user callback function.
        */
        ret = SRV_PLAYLIST_ASYNC;
    }

    return ret;
}

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
S32 srv_playlist_add_file_cancel(U32 srv_handle)
{
    music_playlist_cntx_struct* list_cntx = NULL;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }

    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    music_playlist_generate_cancel(list_cntx);

    return SRV_PLAYLIST_ASYNC;
}

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
S32 srv_playlist_multi_select_mark_begin(U32 srv_handle)
{
    music_playlist_cntx_struct* list_cntx = NULL;
    music_playlist_list_struct* list = NULL;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }

    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    list = (music_playlist_list_struct*)&list_cntx->current_list;

    /* reset the mark table. */
    list->mark_count = 0;
    list->delete_count = 0;
    list->delete_group = 0;
    list->delete_canceled = MMI_FALSE;
    memset(list->bitMark, 0x00, MUSIC_PLAYLIST_MAX_BITSET_SIZE*sizeof(U8));

    return SRV_PLAYLIST_OK;
}

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
S32 srv_playlist_multi_select_mark_end(U32 srv_handle)
{
    music_playlist_cntx_struct* list_cntx = NULL;
    music_playlist_list_struct* list = NULL;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }

    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    list = (music_playlist_list_struct*)&list_cntx->current_list;

    /* reset the mark table. */
    list->mark_count = 0;
    list->delete_count = 0;
    list->delete_group = 0;
    list->delete_canceled = MMI_FALSE;
    memset(list->bitMark, 0x00, MUSIC_PLAYLIST_MAX_BITSET_SIZE*sizeof(U8));

    return SRV_PLAYLIST_OK;
}

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
S32 srv_playlist_multi_select_set_mark(U32 srv_handle, U32 index, MMI_BOOL is_mark)
{
    music_playlist_cntx_struct* list_cntx = NULL;
    music_playlist_list_struct* list = NULL;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }

    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    list = (music_playlist_list_struct*)&list_cntx->current_list;

    if (is_mark)
    {
        if (!IsBitSetOn(index, list->bitMark))
        {
            SetBitSet(index, list->bitMark);
            list->mark_count ++;
        }
    }
    else
    {
        if (IsBitSetOn(index, list->bitMark))
        {
            ClrBitSet(index, list->bitMark);
            list->mark_count --;
        }
    }

    return SRV_PLAYLIST_OK;
}

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
MMI_BOOL srv_playlist_multi_select_get_mark(U32 srv_handle, U32 index)
{
    music_playlist_cntx_struct* list_cntx = NULL;
    music_playlist_list_struct* list = NULL;
    MMI_BOOL is_mark = MMI_FALSE;

    /* check input para. */
    if (!srv_handle)
    {
        return MMI_FALSE;
    }

    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    list = (music_playlist_list_struct*)&list_cntx->current_list;    
    is_mark = (MMI_BOOL)IsBitSetOn(index, list->bitMark);

    return is_mark;
}

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
MMI_BOOL srv_playlist_multi_select_get_mark_all(U32 srv_handle)
{
    music_playlist_cntx_struct* list_cntx = NULL;
    music_playlist_list_struct* list = NULL;
    MMI_BOOL is_mark = MMI_FALSE;

    /* check input para. */
    if (!srv_handle)
    {
        return MMI_FALSE;
    }

    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    list = (music_playlist_list_struct*)&list_cntx->current_list;  
    if (list->mark_count == list->total)
    {
        is_mark = MMI_TRUE;
    }

    return is_mark;
}

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
S32 srv_playlist_multi_select_mark_all(U32 srv_handle, MMI_BOOL is_mark)
{
    music_playlist_cntx_struct* list_cntx = NULL;
    music_playlist_list_struct* list = NULL;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }

    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    list = (music_playlist_list_struct*)&list_cntx->current_list;

    if (is_mark)
    {
        list->mark_count = list->total;
        memset(list->bitMark, 0xFF, MUSIC_PLAYLIST_MAX_BITSET_SIZE*sizeof(U8));
    }
    else
    {
        list->mark_count = 0;
        memset(list->bitMark, 0x00, MUSIC_PLAYLIST_MAX_BITSET_SIZE*sizeof(U8));
    }

    return SRV_PLAYLIST_OK;
}

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
S32 srv_playlist_delete_item(U32 srv_handle, U32 index)
 {
     music_playlist_cntx_struct* list_cntx = NULL;
     
     /* check input para. */
     if (!srv_handle)
     {
         return SRV_PLAYLIST_ERR_BAD_PARA;
     }
     
     list_cntx = (music_playlist_cntx_struct *)srv_handle;

     /* marked all items. */
     SetProtocolEventHandler(music_playlist_delete, MSG_ID_PLS_LIST_ITEM_DELETE_REQ);
     music_playlist_delete_req(index, (void*)list_cntx);

     return SRV_PLAYLIST_ASYNC;
 }

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
S32 srv_playlist_delete_marked_item(U32 srv_handle)
 {
    music_playlist_cntx_struct* list_cntx = NULL;
    music_playlist_list_struct* list = NULL;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }

    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    list = (music_playlist_list_struct*)&list_cntx->current_list;
    if (0 == list->mark_count)
    {
        return SRV_PLAYLIST_OK;
    }

    /* delete multi-selected items. */
    SetProtocolEventHandler(music_playlist_delete_marked, MSG_ID_PLS_LIST_ITEM_DELETE_REQ);
    music_playlist_delete_req(-1, (void*)list_cntx);
    return SRV_PLAYLIST_ASYNC;
 }

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
S32 srv_playlist_delete_cancel(U32 srv_handle)
{
    music_playlist_cntx_struct* list_cntx = NULL;
    music_playlist_list_struct* list = NULL;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }
    
    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    list = (music_playlist_list_struct*)&list_cntx->current_list;
    
    list->delete_canceled = MMI_TRUE;
    return SRV_PLAYLIST_OK;
}

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
S32 srv_playlist_config_shuffle(U32 srv_handle, srv_playlist_shuffle_enum shuffle)
{
    music_playlist_cntx_struct* list_cntx = NULL;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }
    
    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    list_cntx->current_list.shuffle_mode = shuffle;
    
    return SRV_PLAYLIST_OK;
}

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
S32 srv_playlist_config_repeat(U32 srv_handle, srv_playlist_repeat_enum repeat)
{
    music_playlist_cntx_struct* list_cntx = NULL;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }
    
    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    list_cntx->current_list.repeat_mode = repeat;
    
    return SRV_PLAYLIST_OK;
}

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
srv_playlist_shuffle_enum srv_playlist_get_shuffle(U32 srv_handle)
{
    music_playlist_cntx_struct* list_cntx = NULL;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_SHUFFLE_OFF;
    }
    
    list_cntx = (music_playlist_cntx_struct *)srv_handle;    
    return list_cntx->current_list.shuffle_mode;
}

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
srv_playlist_repeat_enum srv_playlist_get_repeat(U32 srv_handle)
{
    music_playlist_cntx_struct* list_cntx = NULL;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_REPEAT_OFF;
    }
    
    list_cntx = (music_playlist_cntx_struct *)srv_handle;    
    return list_cntx->current_list.repeat_mode;
}

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
S32 srv_playlist_get_item_title(U32 srv_handle, S32 index, UI_string_type title)
{
    music_playlist_cntx_struct* list_cntx = NULL;
    S32 ret = SRV_PLAYLIST_OK;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }
    
    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    if ((index < 0) || (index > list_cntx->current_list.total))
    {
        return SRV_PLAYLIST_FAILED;
    }
    
    ret = music_playlist_get_filename(list_cntx, index, title);
    return ret;
}

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
S32 srv_playlist_get_item_path(U32 srv_handle, S32 index, UI_string_type path)
{
    music_playlist_cntx_struct* list_cntx = NULL;
    S32 ret = SRV_PLAYLIST_OK;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }
    
    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    if ((index < 0) || (index > list_cntx->current_list.total))
    {
        return SRV_PLAYLIST_FAILED;
    }
    
    ret = music_playlist_get_path(list_cntx, index, path);
    if (ret <= 0)
    {
        return SRV_PLAYLIST_FAILED;
    }
    else
    {
        return SRV_PLAYLIST_OK;
    }
}

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
S32 srv_playlist_get_list_count(U32 srv_handle)
{
    music_playlist_cntx_struct* list_cntx = NULL;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }
    
    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    if (!list_cntx->list_loaded)
    {
        return 0;
    }
    else
    {
        return list_cntx->current_list.total;
    }
}

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
S32 srv_playlist_get_active_index(U32 srv_handle)
{
    music_playlist_cntx_struct* list_cntx = NULL;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }
    
    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    if (!list_cntx->list_loaded)
    {
        return -1;
    }
    else
    {
        return list_cntx->current_list.pick_index;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_set_as_active
 * DESCRIPTION
 *  set index item as played
 * PARAMETERS
 *  srv_handle:  [IN]     service handle
 * RETURNS
 *  return  item index
 *****************************************************************************/ 
S32 srv_playlist_set_as_active(U32 srv_handle, S32 index)
{
    music_playlist_cntx_struct* list_cntx = NULL;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }
    
    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    music_playlist_set_pick_index(list_cntx, index);

    return SRV_PLAYLIST_OK;
}

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
S32 srv_playlist_get_active_info(U32 srv_handle, S32* index, UI_string_type path)
{
    music_playlist_cntx_struct* list_cntx = NULL;
    S32 ret = SRV_PLAYLIST_OK;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }
    
    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    if (!list_cntx->list_loaded)
    {
        return SRV_PLAYLIST_FAILED;
    }

    *index = list_cntx->current_list.pick_index;
    ret = music_playlist_get_path(list_cntx, *index, path);
    if (ret <= 0)
    {
        return SRV_PLAYLIST_FAILED;
    }

    return SRV_PLAYLIST_OK;
}

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
 *****************************************************************************/ 
S32 srv_playlist_get_next_auto(U32 srv_handle, S32* index, UI_string_type path)
{
    music_playlist_cntx_struct* list_cntx = NULL;
    S32 result = SRV_PLAYLIST_OK;
    S32 ret = SRV_PLAYLIST_OK;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }
    
    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    result = music_playlist_do_pick(list_cntx, index);
    if (SRV_PLAYLIST_END == result)
    {
        /* reach the end of list. */
        return SRV_PLAYLIST_END;
    }
    
    /* got next song, read path. */
    ret = music_playlist_get_path(list_cntx, *index, path);
    if (ret <= 0)
    {
        ret = SRV_PLAYLIST_FAILED;
    }
    else
    {
        ret = SRV_PLAYLIST_OK;
        if (SRV_PLAYLIST_NEXT_LOOP == result)
        {
            ret = result;
        }
    }

    return ret;
}

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
S32 srv_playlist_get_next_manul(U32 srv_handle, S32* index, UI_string_type path)
{
    music_playlist_cntx_struct* list_cntx = NULL;
    S32 result = -1;
    S32 ret = SRV_PLAYLIST_OK;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }
    
    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    result = music_playlist_pick_next(list_cntx);
    if (-1 == result)
    {
        return SRV_PLAYLIST_END;
    }

    *index = result;
    ret = music_playlist_get_path(list_cntx, result, path);
    if (ret <= 0)
    {
        return SRV_PLAYLIST_FAILED;
    }

    return SRV_PLAYLIST_OK;
}

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
S32 srv_playlist_get_prev_manul(U32 srv_handle, S32* index, UI_string_type path)
{
    music_playlist_cntx_struct* list_cntx = NULL;
    S32 result = -1;
    S32 ret = SRV_PLAYLIST_OK;

    /* check input para. */
    if (!srv_handle)
    {
        return SRV_PLAYLIST_ERR_BAD_PARA;
    }
    
    list_cntx = (music_playlist_cntx_struct *)srv_handle;
    result = music_playlist_pick_prev(list_cntx);
    if (-1 == result)
    {
        return SRV_PLAYLIST_END;
    }

    *index = result;
    ret = music_playlist_get_path(list_cntx, result, path);
    if (ret <= 0)
    {
        return SRV_PLAYLIST_FAILED;
    }

    return SRV_PLAYLIST_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_usb_plug_in_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET srv_playlist_usb_plug_in_hdlr(mmi_event_struct *evt)
{
    /* do nothing. */
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_playlist_usb_plug_out_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET srv_playlist_usb_plug_out_hdlr(mmi_event_struct *evt)
{
    /* do nothing. */
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_playlist_notify_hdlr
 * DESCRIPTION
 *  notify event handler
 * PARAMETERS
 *  event:     [IN]   event
 * RETURNS
 *  return mmi_ret
 *****************************************************************************/ 
mmi_ret srv_playlist_notify_hdlr(mmi_event_struct *event)
{
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
    srv_fmgr_notification_set_def_storage_event_struct *fmgr_storage;
#endif /* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */

    srv_fmgr_notification_format_event_struct *fmgr_format;
    srv_fmgr_notification_dev_plug_event_struct *fmgr_plug;
    srv_fmgr_notification_dev_soft_mount_event_struct *fmgr_mount;
    srv_fmgr_notification_adv_action_event_struct *fmgr_act;
    music_playlist_cntx_struct * list_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body */
    /*----------------------------------------------------------------*/
    list_cntx = (music_playlist_cntx_struct *)g_instance;
    if (!list_cntx)
    {
        return MMI_RET_OK;
    }

    switch (event->evt_id)
    {
    #ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
        case EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE:
        {
            break;
        }
    #endif /* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */

        case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
        {
            fmgr_format = (srv_fmgr_notification_format_event_struct*)event;
            if (SRV_FMGR_NOTIFICATION_STATE_BEFORE == fmgr_format->state)
            {
                /* MMI_FMGR_NOTIFY_DRV_PRE_FORMAT */
                music_playlist_pre_format_hdlr(list_cntx, ((CHAR)fmgr_format->drv_letter));
            }
            else if (SRV_FMGR_NOTIFICATION_STATE_AFTER == fmgr_format->state)
            {
                /* MMI_FMGR_NOTIFY_DRV_PRE_FORMAT */
                music_playlist_after_format_hdlr(list_cntx, ((CHAR)fmgr_format->drv_letter));
            }
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
            /* MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT */
            fmgr_plug = (srv_fmgr_notification_dev_plug_event_struct*)event;
            music_playlist_msdc_plug_out_hdlr(list_cntx, fmgr_plug->count, fmgr_plug->drv_letters);
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        {
            /*MMI_FMGR_NOTIFY_DRV_POST_MOUNT*/
            fmgr_plug = (srv_fmgr_notification_dev_plug_event_struct*)event;
            music_playlist_msdc_plug_in_hdlr(list_cntx, fmgr_plug->count, fmgr_plug->drv_letters);
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT:
        {
            fmgr_mount = (srv_fmgr_notification_dev_soft_mount_event_struct*)event;
            
            if(fmgr_mount->mount == MMI_FALSE)
            {
                /*MMI_FMGR_NOTIFY_ENTRY_UNMOUNT*/
            }
            else
            {
                /*MMI_FMGR_NOTIFY_EXIT_UNMOUNT*/
            }
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
        {
            fmgr_act = (srv_fmgr_notification_adv_action_event_struct*)event;
            
            if (SRV_FMGR_NOTIFICATION_STATE_QUERY == fmgr_act->state)
            {
                if ((SRV_FMGR_NOTIFICATION_ACTION_MOVE == fmgr_act->action) /*MMI_FMGR_NOTIFY_PRE_DELETE, MMI_FMGR_NOTIFY_PRE_MOVE */
                     || (SRV_FMGR_NOTIFICATION_ACTION_DELETE == fmgr_act->action) 
                     || (SRV_FMGR_NOTIFICATION_ACTION_RENAME == fmgr_act->action))
                {
                
                }
                else if (SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL == fmgr_act->action)
                {
                    /* MMI_FMGR_NOTIFY_PRE_DEL_ALL */
                }
            }
            break;
        }
        
        default:
            break;
    }

    return MMI_RET_OK;
}

#endif  //__PLAYLIST_SERVICE__
