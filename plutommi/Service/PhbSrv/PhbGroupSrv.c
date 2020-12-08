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
 *  PhbGroupSrv.c
 *
 * Project:
 * --------
 *  MAUI
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_PHB_CALLER_GROUP__

/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_include.h"
#include "PhbSrvGprot.h"
#include "PhbSrv.h"
#include "mmi_rp_srv_phb_def.h"
#include "FileMgrSrvGProt.h"
#include "nvram_common_defs.h"

/*****************************************************************************
 * structure and enum
 *****************************************************************************/

typedef enum
{
    SRV_PHB_GROUP_MEMBER_OP_ADD,
    SRV_PHB_GROUP_MEMBER_OP_REMOVE
}srv_phb_group_member_op_type;

typedef struct 
{
    U16 group_count;
    U8 group_id[MMI_PHB_GROUP_TOTAL_COUNT];
}srv_phb_group_sse_cntx;

typedef struct
{
    mmi_phb_group_info_struct group_info[MMI_PHB_GROUP_COUNT];
    MMI_BOOL is_init;
}srv_phb_phone_group_cntx;

typedef struct
{
    mmi_phb_contact_id* id_array;
    U16 entry_count;
    U16 finish_count;
    U16 op_index;
    U8 group_id;
    phb_storage_enum storage;
    srv_phb_group_member_op_type op_type;
    MMI_BOOL is_reset;
    MMI_BOOL is_canceled;
    srv_phb_group_callback_type cb;
    void * user_data;
}srv_phb_group_member_op_cntx;

typedef struct
{
    srv_phb_group_op_type_enum op;
    srv_phb_group_callback_type cb;
    void * user_data;
}srv_phb_group_op_struct;

static srv_phb_group_sse_cntx g_srv_phb_group_sse_cntx;
static srv_phb_phone_group_cntx g_srv_phb_phone_group_cache;
static srv_phb_group_member_op_cntx g_srv_phb_group_member_op_cntx;
static srv_phb_group_op_struct g_srv_phb_group_op_cntx;


/***************************************************************************** 
 * FUNCTIONS
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_all_group_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_phb_read_all_group_info(void* group_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_PHB_GROUP_INFO_LID,
        (U16)1,
        group_info,
        NVRAM_EF_PHB_GROUP_INFO_SIZE,
        &p_error);
    return SRV_PHB_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_all_group_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_phb_write_all_group_info(void* group_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_PHB_GROUP_INFO_LID,
        (U16)1,
        group_info,
        NVRAM_EF_PHB_GROUP_INFO_SIZE,
        &p_error);
    return SRV_PHB_NO_ERROR;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_build_app_group_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_build_app_group_info(srv_phb_group_info_struct* dest, const mmi_phb_group_info_struct* src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(dest->group_name, src->group_name);
    dest->res_type = src->res_type;
    dest->ringtone_id = src->ringtone_id;
    dest->storage = PHB_STORAGE_NVRAM;
    if (!srv_phb_datamgr_get_res_path(
            MMI_PHB_CONTACT_FIELD_RING,
            dest->ringtone_id, 
            (U16)(dest->res_type & SRV_PHB_RES_TYPE_RING_FILE),
            dest->ringtone_path))
    {
        dest->ringtone_id = 0;
        dest->res_type &= ~SRV_PHB_RES_TYPE_RING_FILE;
    }
    
    dest->image_id = src->image_id;
    if (!srv_phb_datamgr_get_res_path(
            MMI_PHB_CONTACT_FIELD_IMAGE,
            dest->image_id, 
            (U16)(dest->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE),
            dest->image_path))
    {
        dest->image_id = 0;
        dest->res_type &= ~SRV_PHB_RES_TYPE_IMAGE_FILE;
    }
    if (!dest->image_id)
    {
        dest->image_id = IMG_PHB_DEFAULT;
    }

#ifdef __MMI_PHB_CALLER_VIDEO__
    dest->video_id = src->video_id;
    if (!srv_phb_datamgr_get_res_path(
            MMI_PHB_CONTACT_FIELD_VIDEO,
            dest->video_id, 
            (U16)(dest->res_type & SRV_PHB_RES_TYPE_VIDEO_FILE),
            dest->video_path))
    {
        dest->video_id = 0;
        dest->res_type &= ~SRV_PHB_RES_TYPE_VIDEO_FILE;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_build_nvram_group_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_phb_build_nvram_group_info(mmi_phb_group_info_struct* dest, srv_phb_group_info_struct* src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = SRV_PHB_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(dest->group_name, src->group_name);
    
    if (!srv_phb_datamgr_update_res_path(
            MMI_PHB_CONTACT_FIELD_IMAGE,
            dest->ringtone_id,
            (dest->res_type & SRV_PHB_RES_TYPE_RING_FILE) ? MMI_TRUE : MMI_FALSE,
            &src->ringtone_id,
            (src->res_type & SRV_PHB_RES_TYPE_RING_FILE) ? MMI_TRUE : MMI_FALSE,
            src->ringtone_path))
    {
        src->res_type &= ~SRV_PHB_RES_TYPE_RING_FILE;
        result += SRV_PHB_RING_ERROR;
    }
    if ((src->res_type & SRV_PHB_RES_TYPE_RING_ID) && !src->ringtone_id)
    {
        src->res_type &= ~SRV_PHB_RES_TYPE_RING_ID;
    }
    dest->ringtone_id = src->ringtone_id;

    if (!srv_phb_datamgr_update_res_path(
            MMI_PHB_CONTACT_FIELD_RING,
            dest->image_id,
            (dest->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE) ? MMI_TRUE : MMI_FALSE,
            &src->image_id,
            (src->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE) ? MMI_TRUE : MMI_FALSE,
            src->image_path))
    {
        src->res_type &= ~SRV_PHB_RES_TYPE_IMAGE_FILE;
        result += SRV_PHB_IMAGE_ERROR;
    }
    dest->image_id = src->image_id;

#ifdef __MMI_PHB_CALLER_VIDEO__
    if (!srv_phb_datamgr_update_res_path(
            MMI_PHB_CONTACT_FIELD_VIDEO,
            dest->video_id,
            (dest->res_type & SRV_PHB_RES_TYPE_VIDEO_FILE) ? MMI_TRUE : MMI_FALSE,
            &src->video_id,
            (src->res_type & SRV_PHB_RES_TYPE_VIDEO_FILE) ? MMI_TRUE : MMI_FALSE,
            src->video_path))

    {
        src->res_type &= ~SRV_PHB_RES_TYPE_VIDEO_FILE;
        result += SRV_PHB_VIDEO_ERROR;
    }
    if ((src->res_type & SRV_PHB_RES_TYPE_VIDEO_ID) && !src->video_id)
    {
        src->res_type &= ~(SRV_PHB_RES_TYPE_VIDEO_ID | SRV_PHB_RES_TYPE_VIDEO_SOUND_ON);
    }
    dest->video_id= src->video_id;
#endif
    dest->res_type = src->res_type;
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_group_check_name_dup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_phb_group_check_name_dup(phb_storage_enum storage, U8 src_group_id, U16 *group_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U8 group_id;
    srv_phb_group_info_struct group_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < g_srv_phb_group_sse_cntx.group_count; i ++)
    {
        group_id = g_srv_phb_group_sse_cntx.group_id[i];
        if (srv_phb_get_storage_by_group_id(group_id) == storage && group_id != src_group_id)
        {
            srv_phb_get_group_info(group_id, &group_info);
            if (mmi_wcscmp(group_info.group_name, group_name) == 0)
            {
                return MMI_TRUE;
            }
        }        
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_op_group_members_cb
 * DESCRIPTION
 *  add contacts to a group
 * PARAMETERS
 *  result            :   [IN]   op result
 *  id                 :   [IN]    contact id
 *  user_data      :   [IN]    user data
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_phb_get_group_store_index(U16 group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (group_id >= MMI_PHB_GROUP_TOTAL_COUNT)
    {
        return SRV_PHB_INVALID_INDEX;
    }
    else if (group_id >= MMI_PHB_GROUP_COUNT)
    {
        return (group_id - MMI_PHB_GROUP_COUNT) % PHB_MAX_ASSOCIATE_GRP;
    }
    else
    {
        return group_id;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_group_order_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_phb_get_group_sort_index(S32 low, S32 high, U16* group_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 group_id;
    S32 mid = 0;
    S32 distance = 0;
    U16 *dest_name;
    #if defined(__MMI_PHB_PINYIN_SORT__)
    U16 count;
    U16 src_buffer[SRV_PHB_PINYIN_LEN + 1];
    U16 dest_buffer[SRV_PHB_PINYIN_LEN + 1];
    #endif
    srv_phb_group_info_struct group_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (low <= high)
    {
        mid = (low + high) / 2;

        group_id = g_srv_phb_group_sse_cntx.group_id[mid];
        srv_phb_get_group_info(group_id, &group_info);
        dest_name = group_info.group_name;
        #if defined(__MMI_PHB_PINYIN_SORT__)
        if (srv_phb_check_ucs2_character(group_name))
        {
            count = srv_phb_convert_to_pinyin(group_name, src_buffer, SRV_PHB_PINYIN_LEN);
            src_buffer[count++] = 0x00;
            group_name = src_buffer;
        }
        if (srv_phb_check_ucs2_character(dest_name))
        {
            count = srv_phb_convert_to_pinyin(dest_name, dest_buffer, SRV_PHB_PINYIN_LEN);
            dest_buffer[count++] = 0x00;
            dest_name = dest_buffer;
        }
        distance = srv_phb_compare_pinyin_string(group_name, dest_name);
        #else
        distance = srv_phb_compare_ucs2_string(group_name, dest_name);
        #endif 
        if (distance == 0)
        {
            distance = mmi_wcscmp(group_name, dest_name);
        }
        if (distance > 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (distance > 0)
    {
        return mid + 1;
    }
    else
    {
        return mid;
    }
}


/*****************************************************************************
 * FUNCTION
*  srv_phb_sse_insert_group_index
 * DESCRIPTION
*  Insert a group to group sort array
 * PARAMETERS
*  group_id                : [IN]            group store index :group_id < MMI_PHB_GROUP_COUNT -->phone
                                                                   group_id >= MMI_PHB_GROUP_COUNT-->USIM
*  group_name           : [IN]            group name
 * RETURNS
*  insert postion
 *****************************************************************************/
U32 srv_phb_group_insert_group_index(U8 group_id, U16* group_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 pos = 0;
    U32 pos_start = 0;
    U32 pos_end = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!group_name || group_name[0] == 0)
    {
        return 0;
    }
    if(group_id < MMI_PHB_GROUP_TOTAL_COUNT)
    {
        if (g_srv_phb_group_sse_cntx.group_count == 0)
        {
            pos = 0;
        }
        else
        {
            pos_start = 0;
            pos_end = g_srv_phb_group_sse_cntx.group_count;
            pos = srv_phb_get_group_sort_index(pos_start, (S32)(pos_end - 1), group_name);
        }
    }
    for (i = (S32)pos_end; i > pos; i--)
    {
        g_srv_phb_group_sse_cntx.group_id[i] = g_srv_phb_group_sse_cntx.group_id[i - 1];
    }
    g_srv_phb_group_sse_cntx.group_id[pos] = group_id;
    g_srv_phb_group_sse_cntx.group_count++;
    return pos;
}

/*****************************************************************************
 * FUNCTION
*  srv_phb_group_delete_group_index
 * DESCRIPTION
*  Insert a group to group sort array
 * PARAMETERS
*  group_id                : [IN]            group store index :group_id < MMI_PHB_GROUP_COUNT -->phone
                                                                   group_id >= MMI_PHB_GROUP_COUNT-->USIM
 * RETURNS
*  insert postion
 *****************************************************************************/
U32 srv_phb_group_delete_group_index(U8 group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 pos = 0;
    U32 pos_end = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (group_id < MMI_PHB_GROUP_TOTAL_COUNT)
    {
        for (i = 0; i < g_srv_phb_group_sse_cntx.group_count; i++)
        {
            if (g_srv_phb_group_sse_cntx.group_id[i] == group_id)
            {
                pos = i;
                pos_end = g_srv_phb_group_sse_cntx.group_count;
                g_srv_phb_group_sse_cntx.group_count--;
                break;
            }
        }
        for (i = pos; i < pos_end; i ++)
        {
            g_srv_phb_group_sse_cntx.group_id[i] = g_srv_phb_group_sse_cntx.group_id[i + 1];
        }
    }    
    return pos;
}


/*****************************************************************************
 * FUNCTION
*  srv_phb_group_init
 * DESCRIPTION
*  phone group init
 * PARAMETERS
* NULL
 * RETURNS
*  insert postion
 *****************************************************************************/
void srv_phb_group_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 group_id;
    U16 *group_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_phone_group_cache.is_init != MMI_TRUE)
    {
        srv_phb_read_all_group_info(&g_srv_phb_phone_group_cache.group_info);
        for (group_id = 0; group_id < MMI_PHB_GROUP_COUNT; group_id++)
        {
            group_name = g_srv_phb_phone_group_cache.group_info[group_id].group_name;
            if (group_name[0] != 0)
            {
                srv_phb_group_insert_group_index(group_id, group_name);
            }            
        }
        g_srv_phb_phone_group_cache.is_init = MMI_TRUE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_group_op_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_group_op_done(S32 result, U8 group_id, mmi_phb_group_info_struct* group_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_group_op_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SRV_PHB_NO_ERROR)
    {
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_PHB_OP_GROUP);
        evt.group_info = group_info;
        evt.group_id = group_id;
        evt.op_type = g_srv_phb_group_op_cntx.op;
        MMI_FRM_CB_EMIT_EVENT(&evt);
        result = group_id;
    }
    if (g_srv_phb_group_op_cntx.cb != NULL)
    {
        g_srv_phb_group_op_cntx.cb(result, g_srv_phb_group_op_cntx.user_data);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_group_member_op_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_group_member_op_done(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_group_member_op_cntx.cb)
    {
        g_srv_phb_group_member_op_cntx.cb(g_srv_phb_group_member_op_cntx.group_id, g_srv_phb_group_member_op_cntx.user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_phone_group_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_set_phone_group_info(U8 group_id, srv_phb_group_info_struct* group_info, srv_phb_group_op_type_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 result = SRV_PHB_NO_ERROR;
    mmi_phb_group_info_struct *p_group_info = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (op)
    {
        case SRV_PHB_GROUP_OP_TYPE_ADD:
        {
            for (i = 0; i < MMI_PHB_GROUP_COUNT; i++)
            {
                if (g_srv_phb_phone_group_cache.group_info[i].group_name[0] == 0)
                {
                    group_id = i;
                    break;
                }
            }
            if (i == MMI_PHB_GROUP_COUNT)
            {
                result = SRV_PHB_GROUP_FULL;
                break;
            }
            p_group_info = &g_srv_phb_phone_group_cache.group_info[group_id];
            srv_phb_build_nvram_group_info(p_group_info, group_info);
            srv_phb_group_insert_group_index(group_id, group_info->group_name);
            break;
}

        case SRV_PHB_GROUP_OP_TYPE_UPD:
        {
            p_group_info = &g_srv_phb_phone_group_cache.group_info[group_id];
            srv_phb_build_nvram_group_info(p_group_info, group_info);
            srv_phb_group_delete_group_index(group_id);
            srv_phb_group_insert_group_index(group_id, group_info->group_name);
            break;
        }
        
        case SRV_PHB_GROUP_OP_TYPE_DEL:
        {
            p_group_info = &g_srv_phb_phone_group_cache.group_info[group_id];
            #ifdef __SRV_PHB_CALLER_RES_DATA_STORE__
            if (p_group_info->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE)
            {
                srv_phb_datamgr_clear_res_path(MMI_PHB_CONTACT_FIELD_ID_IMAGE, (U16)(p_group_info->image_id));
            }
            if (p_group_info->res_type & SRV_PHB_RES_TYPE_RING_FILE)
            {
                srv_phb_datamgr_clear_res_path(MMI_PHB_CONTACT_FIELD_ID_IMAGE, (U16)(p_group_info->ringtone_id));
            }
            #if defined(__MMI_PHB_CALLER_VIDEO__)
            if (p_group_info->res_type & SRV_PHB_RES_TYPE_VIDEO_FILE)
            {
                srv_phb_datamgr_clear_res_path(MMI_PHB_CONTACT_FIELD_ID_IMAGE, (U16)(p_group_info->video_id));
            }
            #endif /* __MMI_PHB_CALLER_VIDEO__ */
            #endif /* __SRV_PHB_CALLER_RES_DATA_STORE__ */
            memset(p_group_info, 0x00, sizeof(mmi_phb_group_info_struct));
            srv_phb_group_delete_group_index(group_id);
            break;
        }            
    }
    if (result == SRV_PHB_NO_ERROR)
    {
        srv_phb_write_all_group_info(g_srv_phb_phone_group_cache.group_info);
    }
    srv_phb_group_op_done(result, group_id, p_group_info); 
}


#if defined(__MMI_PHB_USIM_SUPPORT__) || defined(__SRV_PHB_TCARD_STORAGE_SUPPORT__)
static void srv_phb_remove_all_group_members_cb(S32 result, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 group_id = g_srv_phb_group_member_op_cntx.group_id;
    phb_storage_enum storage = srv_phb_get_storage_by_group_id(group_id);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    if (storage == PHB_STORAGE_TCARD)
    {
        srv_phb_set_tcard_group_info(group_id, NULL, SRV_PHB_GROUP_OP_TYPE_DEL);
        return;
    }
    #endif
    #ifdef __MMI_PHB_USIM_SUPPORT__
    if (storage == PHB_STORAGE_TCARD)
    {
        srv_phb_sim_set_gas(
            storage,
            srv_phb_get_group_store_index(group_id) + 1,
            NULL);
    }
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_op_group_members_cb
 * DESCRIPTION
 *  add contacts to a group
 * PARAMETERS
 *  result            :   [IN]   op result
 *  id                 :   [IN]    contact id
 *  user_data      :   [IN]    user data
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_op_group_members_cb(S32 result, U16 id, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_field_filter filter;
    srv_phb_contact contact;
    srv_phb_group_struct group;
    srv_phb_group_struct * old_data;
    srv_phb_datamgr_update_req_struct req;
    U16 contact_id;
    U32 i;
    S32 cb_result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (user_data)
    {
        srv_phb_free_contact(user_data);
    }
    if (result == SRV_PHB_NO_ERROR)
    {
        g_srv_phb_group_member_op_cntx.finish_count ++;
        g_srv_phb_group_member_op_cntx.op_index ++;
        g_srv_phb_group_member_op_cntx.entry_count --;
    }
    cb_result = g_srv_phb_group_member_op_cntx.finish_count;
    if (g_srv_phb_group_member_op_cntx.entry_count > 0 && !g_srv_phb_group_member_op_cntx.is_canceled)
    {
        contact_id = g_srv_phb_group_member_op_cntx.id_array[g_srv_phb_group_member_op_cntx.op_index];
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        if (srv_phb_get_storage(contact_id) ==  PHB_STORAGE_TCARD && srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV) == MMI_FALSE)
        {
            cb_result = SRV_PHB_TCARD_NOT_AVAILABLE;
        }
        else
        #endif
        {
            filter = srv_phb_create_field_filter_ext(MMI_PHB_CONTACT_FIELD_GROUP);
            contact = srv_phb_read_contact(contact_id, filter, NULL);
            old_data = srv_phb_contact_get_group(contact);
            memset(&group, 0x00, sizeof(srv_phb_group_struct));
            if (g_srv_phb_group_member_op_cntx.is_reset == MMI_FALSE && old_data)
            {
                for (i = 0; i < old_data->group_count; i ++)
                {
                    if (g_srv_phb_group_member_op_cntx.op_type == SRV_PHB_GROUP_FIELD_OP_TYPE_REMOVE &&
                        old_data->group_id[i] == g_srv_phb_group_member_op_cntx.group_id)
                    {
                        continue;
                    }
                    group.group_id[i] = old_data->group_id[i];
                    group.group_count ++;
                }
            }
            if (g_srv_phb_group_member_op_cntx.op_type == SRV_PHB_GROUP_FIELD_OP_TYPE_ADD)
            {
                group.group_id[group.group_count] = g_srv_phb_group_member_op_cntx.group_id;
                group.group_count += 1;
            }
            srv_phb_contact_set_group(contact, &group);
            req.cb = srv_phb_op_group_members_cb;
            req.contact = contact;
            req.id = contact_id;
            req.mode = SRV_PHB_UPDATE_MODE_REPLACE;
            req.update_field = MMI_PHB_CONTACT_FIELD_GROUP;
            req.user_data = contact;
            srv_phb_datamgr_update_contact(&req);
            srv_phb_free_field_filter(filter);
            return;
        }
    }
    if (g_srv_phb_group_member_op_cntx.id_array)
    {
        srv_phb_mem_free(g_srv_phb_group_member_op_cntx.id_array);
        g_srv_phb_group_member_op_cntx.id_array = NULL;
    }

    if (g_srv_phb_group_member_op_cntx.is_canceled)
    {
        cb_result  = SRV_PHB_GROUP_CANCEL_OP;
    }

    if (g_srv_phb_group_member_op_cntx.cb)
    {
        g_srv_phb_group_member_op_cntx.cb(cb_result, g_srv_phb_group_member_op_cntx.user_data);
    }

    g_srv_phb_group_member_op_cntx.is_canceled = MMI_FALSE;
}
#endif


#define EXTERNAL_FUNCTION
/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_get_group_list
 * DESCRIPTION
 *  get group id list ordered by group name
 * PARAMETERS
 *  group_array         :   [OUT]   group id array
 *  group_name          :   [IN]    group name
 * RETURNS
 *  U8
 * RETURN VALUES
 *  count               :           group count
 ****************************************************************************/
U8 srv_phb_datamgr_get_group_list(U8* group_array, U16* group_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_storage_by_group_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
phb_storage_enum srv_phb_get_storage_by_group_id(U8 group_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (group_id < MMI_PHB_GROUP_COUNT)
    {
        return PHB_STORAGE_NVRAM;
    }
    else if (MMI_PHB_GROUP_USIM_COUNT > 0 && group_id < MMI_PHB_GROUP_USIM_COUNT)
    {
        return (phb_storage_enum)(PHB_STORAGE_SIM + (group_id - MMI_PHB_GROUP_COUNT) / PHB_MAX_ASSOCIATE_GRP);
    }
    else
    {
        return PHB_STORAGE_TCARD;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_phone_group_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_group_set_group_done(S32 result, U8 group_id, WCHAR* group_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_group_info_struct group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SRV_PHB_NO_ERROR)
    {
        if (group_name != NULL)
        {
            mmi_wcscpy(group_info.group_name, group_name);
        }
        else
        {
            group_info.group_name[0] = 0;
        }
        srv_phb_group_delete_group_index(group_id);
        srv_phb_group_insert_group_index(group_id, group_name);
    }
    srv_phb_group_op_done(result, group_id, &group_info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_add_group_members
 * DESCRIPTION
 *  add contacts to a group
 * PARAMETERS
 *  id_array            :   [IN]    store_index array to add
 *  entry_count         :   [IN]    store_index count
 *  group_id            :   [IN]    group id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_add_group_members(srv_phb_group_add_members_req *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 entry_count = req->entry_count;
    U16 *id_array = req->id_array;
    U8 group_id = req->group_id;
    MMI_BOOL is_reset = req->is_reset;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if defined(__MMI_PHB_USIM_SUPPORT__) || defined(__SRV_PHB_TCARD_STORAGE_SUPPORT__) 
    if (req->group_id >= MMI_PHB_GROUP_COUNT)
    {
        U32 i;
        g_srv_phb_group_member_op_cntx.cb = req->cb;
        g_srv_phb_group_member_op_cntx.entry_count = entry_count;
        g_srv_phb_group_member_op_cntx.group_id = group_id;
        g_srv_phb_group_member_op_cntx.is_reset = is_reset;
        g_srv_phb_group_member_op_cntx.finish_count = 0;
        g_srv_phb_group_member_op_cntx.op_index = 0;
        g_srv_phb_group_member_op_cntx.op_type = SRV_PHB_GROUP_MEMBER_OP_ADD;
        g_srv_phb_group_member_op_cntx.user_data = req->user_data;
        g_srv_phb_group_member_op_cntx.is_canceled = MMI_FALSE;
        g_srv_phb_group_member_op_cntx.id_array = srv_phb_mem_malloc((req->entry_count) * sizeof(mmi_phb_contact_id),SRV_PHB_MEMORY_TYPE_ADM);
        for (i = 0; i < entry_count; i++)
        {
            g_srv_phb_group_member_op_cntx.id_array[i] = id_array[i];
        }
        srv_phb_op_group_members_cb(SRV_PHB_ERROR, SRV_PHB_INVALID_INDEX, NULL);
    }
    else
    #endif
    {
    if (entry_count > 1)
    {
        S32 i;
        mmi_phb_contact_id id;
        U8* group_field = srv_phb_mem_malloc(NVRAM_EF_PHB_GROUP_FIELD_TOTAL * NVRAM_EF_PHB_GROUP_FIELD_SIZE, SRV_PHB_MEMORY_TYPE_ADM);
        srv_phb_get_all_phone_group_field(group_field);

        for(i = 0; i < entry_count; i++)
        {
            id = id_array[i];
            if (is_reset)
            {
                memset(&(group_field[id * MMI_PHB_GROUP_FIELD_SIZE]), 0 , sizeof(U8)* MMI_PHB_GROUP_FIELD_SIZE);
            }
            group_field[id * MMI_PHB_GROUP_FIELD_SIZE + (group_id / 8)] |= (1 << (group_id % 8));
            srv_phb_change_phone_field_mask(id, MMI_PHB_CONTACT_FIELD_GROUP, MMI_TRUE);
        }

        srv_phb_set_all_phone_group_field(group_field);
        srv_phb_commit_all_phone_field_mask();
        srv_phb_mem_free(group_field);
    }
    else if (entry_count == 1)
    {
        U8 group_mask[MMI_PHB_GROUP_FIELD_SIZE];
        memset(group_mask, 0 , sizeof(group_mask));
        group_mask[group_id / 8] = (1 << (group_id % 8));
        srv_phb_set_phone_group_field(
            id_array[0],
            group_mask,
            is_reset ? SRV_PHB_GROUP_FIELD_OP_TYPE_SET : SRV_PHB_GROUP_FIELD_OP_TYPE_ADD);
        srv_phb_commit_phone_fields_mask(id_array[0]);
    }
    if (req->cb)
    {
        req->cb(req->entry_count, req->user_data);
    }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_remove_group_member
 * DESCRIPTION
 *  remove a member from a group
 * PARAMETERS
 *  id                  :   [IN]    contact's store_index
 *  group_id            :   [IN]    group id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_remove_group_member(mmi_phb_contact_id id, U8 group_id, srv_phb_group_callback_type cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 group_mask[MMI_PHB_GROUP_FIELD_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_DMGR_RMV_MEMBER, id, group_id);
    g_srv_phb_group_member_op_cntx.cb = cb;
    g_srv_phb_group_member_op_cntx.group_id = group_id;
    g_srv_phb_group_member_op_cntx.user_data = user_data;
    #if defined(__MMI_PHB_USIM_SUPPORT__) || defined(__SRV_PHB_TCARD_STORAGE_SUPPORT__)
    if (group_id >= MMI_PHB_GROUP_COUNT)
    {
        g_srv_phb_group_member_op_cntx.entry_count = 1;
        g_srv_phb_group_member_op_cntx.is_reset = MMI_FALSE;
        g_srv_phb_group_member_op_cntx.op_index = 0;
        g_srv_phb_group_member_op_cntx.op_type = SRV_PHB_GROUP_MEMBER_OP_REMOVE;
        g_srv_phb_group_member_op_cntx.id_array = srv_phb_mem_malloc(1 * sizeof(mmi_phb_contact_id),SRV_PHB_MEMORY_TYPE_CTR);
        g_srv_phb_group_member_op_cntx.id_array[0] = id;
        g_srv_phb_group_member_op_cntx.is_canceled = MMI_FALSE;
        srv_phb_op_group_members_cb(SRV_PHB_ERROR, SRV_PHB_INVALID_INDEX, NULL);
    }
    else
    #endif
    {
        memset(group_mask, 0 , sizeof(group_mask));
        group_mask[group_id / 8] = (1 << (group_id % 8));
        srv_phb_set_phone_group_field(id, group_mask, SRV_PHB_GROUP_FIELD_OP_TYPE_REMOVE);
        srv_phb_commit_phone_fields_mask(id);
        srv_phb_async_event_interface(srv_phb_group_member_op_done, NULL);
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_phb_remove_all_group_members
 * DESCRIPTION
 *  remove all members from a group
 * PARAMETERS
 *  group_id            :   [IN]    group id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_remove_all_group_members(U8 group_id, srv_phb_group_callback_type cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_contact_id id;
    U16 entry_count = srv_phb_get_phone_used();
    #if defined(__MMI_PHB_USIM_SUPPORT__) || defined(__SRV_PHB_TCARD_STORAGE_SUPPORT__)
    U32 i;
    U32 count;
    srv_phb_query_handle handle;
    srv_phb_query_req_struct req;
    srv_phb_contact_filter filter = srv_phb_create_contact_filter();
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_group_member_op_cntx.cb = cb;
    g_srv_phb_group_member_op_cntx.user_data = user_data;
    g_srv_phb_group_member_op_cntx.group_id = group_id;
    #if defined(__MMI_PHB_USIM_SUPPORT__) || defined(__SRV_PHB_TCARD_STORAGE_SUPPORT__)
    if (group_id >= MMI_PHB_GROUP_COUNT)
    {
        g_srv_phb_group_member_op_cntx.entry_count = 0;
        g_srv_phb_group_member_op_cntx.is_reset = MMI_FALSE;
        g_srv_phb_group_member_op_cntx.op_index = 0;
        g_srv_phb_group_member_op_cntx.op_type = SRV_PHB_GROUP_MEMBER_OP_REMOVE;
        g_srv_phb_group_member_op_cntx.is_canceled = MMI_FALSE;
        srv_phb_contact_filter_set_group(filter, group_id, MMI_TRUE);
        req.filter = filter;
        req.align_field = MMI_PHB_CONTACT_FIELD_NAME;
        handle = srv_phb_query(&req, NULL);
        count = srv_phb_query_get_count(handle);
        if (count > 0)
        {
            g_srv_phb_group_member_op_cntx.id_array = srv_phb_mem_malloc(count * sizeof(mmi_phb_contact_id), SRV_PHB_MEMORY_TYPE_ADM);
        }
        else
        {
            g_srv_phb_group_member_op_cntx.id_array = NULL;
        }
        for (i = 0; i < count; i ++)
        {
            g_srv_phb_group_member_op_cntx.id_array[i] = srv_phb_query_get_contact_id(handle, i);
            g_srv_phb_group_member_op_cntx.entry_count ++;
        }
        srv_phb_op_group_members_cb(SRV_PHB_ERROR, SRV_PHB_INVALID_INDEX, NULL);
    }
    else
    #endif
    {
        if (entry_count > 1)
        {
            S32 i, j;
            MMI_BOOL exist;
            U8* group_field = srv_phb_mem_malloc(NVRAM_EF_PHB_GROUP_FIELD_TOTAL * NVRAM_EF_PHB_GROUP_FIELD_SIZE, SRV_PHB_MEMORY_TYPE_ADM);
            srv_phb_get_all_phone_group_field(group_field);

            for(i = 1; i <= entry_count; i++)
            {
                id = srv_phb_sort_index_to_store_index(PHB_STORAGE_NVRAM, (U16)i);
                group_field[id * MMI_PHB_GROUP_FIELD_SIZE + (group_id / 8)] &= ~(1 << (group_id % 8));
                exist = MMI_FALSE;
                for (j = 0; j < MMI_PHB_GROUP_FIELD_SIZE; j++)
                {
                    if (group_field[id * MMI_PHB_GROUP_FIELD_SIZE + j])
                    {
                        exist = MMI_TRUE;
                        break;
                    }
                }
                srv_phb_change_phone_field_mask(id, MMI_PHB_CONTACT_FIELD_GROUP, exist);
            }
            srv_phb_set_all_phone_group_field(group_field);
            srv_phb_commit_all_phone_field_mask();
            srv_phb_mem_free(group_field);
        }
        else if (entry_count == 1)
        {
            id = srv_phb_sort_index_to_store_index(PHB_STORAGE_NVRAM, (U16)1);
            srv_phb_remove_group_member(id, group_id, cb, user_data);
        }
        srv_phb_async_event_interface(srv_phb_group_member_op_done, NULL);
    }
}


/***************************************************************************** 
 * group operation
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_phb_add_group
 * DESCRIPTION
 *  add a new group
 * PARAMETERS
 *  group_info          :   [IN]    group information->refer to srv_phb_group_info_struct
 * RETURNS
 *  S32
 * RETURN VALUES
 *  >=0                 :           group id
 *  <0                  :           error result
 *****************************************************************************/
void srv_phb_add_group(srv_phb_group_info_struct* group_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = SRV_PHB_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_group_op_cntx.op = SRV_PHB_GROUP_OP_TYPE_ADD;
    g_srv_phb_group_op_cntx.cb = group_info->cb;
    g_srv_phb_group_op_cntx.user_data = group_info->user_data;
    
    if (!group_info)
    {
        result = SRV_PHB_ERROR;
    }
    if (group_info->group_name[0] == 0)
    {
        result = SRV_PHB_GROUP_NAME_EMPTY;
    }
    if (srv_phb_group_check_name_dup(group_info->storage, 0xFF, group_info->group_name) == MMI_TRUE)
    {
        result = SRV_PHB_GROUP_NAME_DUP;
    }
    if (result == SRV_PHB_NO_ERROR)
    {
        #ifdef __MMI_PHB_USIM_SUPPORT__
        if (group_info->storage >= PHB_STORAGE_SIM && group_info->storage <= PHB_STORAGE_SIM4)
        {
            srv_phb_sim_set_gas(group_info->storage, SRV_PHB_INVALID_INDEX, group_info->group_name);
        }
        else
        #endif
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        if (group_info->storage == PHB_STORAGE_TCARD)
        {
            srv_phb_set_tcard_group_info(0xFF, group_info, SRV_PHB_GROUP_OP_TYPE_ADD);
        }
        else
        #endif
        {
            srv_phb_set_phone_group_info(0xff, group_info, SRV_PHB_GROUP_OP_TYPE_ADD);
        }
    }
    else
    {
        srv_phb_group_op_done(result, 0xFF, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_update_group_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_update_group_info(U8 group_id, srv_phb_group_info_struct* group_info)
        {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = SRV_PHB_NO_ERROR;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_group_op_cntx.op = SRV_PHB_GROUP_OP_TYPE_UPD;
    g_srv_phb_group_op_cntx.cb = group_info->cb;
    g_srv_phb_group_op_cntx.user_data = group_info->user_data;
    if ((!group_info) ||(group_id >= MMI_PHB_GROUP_TOTAL_COUNT))
    {
        result = SRV_PHB_ERROR;
    }
    if (group_info->group_name[0] == 0)
    {
        result = SRV_PHB_GROUP_NAME_EMPTY;
    }
    if (srv_phb_group_check_name_dup(group_info->storage, group_id, group_info->group_name) == MMI_TRUE)
    {
        result = SRV_PHB_GROUP_NAME_DUP;
    }
    if (result == SRV_PHB_NO_ERROR)
    {
        #ifdef __MMI_PHB_USIM_SUPPORT__
        if (group_info->storage >= PHB_STORAGE_SIM && group_info->storage <= PHB_STORAGE_SIM4)
        {
            srv_phb_sim_set_gas(
                group_info->storage,
                srv_phb_get_group_store_index(group_id) + 1,
                group_info->group_name);
        }
        else
        #endif
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        if (group_info->storage == PHB_STORAGE_TCARD)
        {
            srv_phb_set_tcard_group_info(group_id, group_info, SRV_PHB_GROUP_OP_TYPE_UPD);
        }
        else
        #endif
        {
            srv_phb_set_phone_group_info(group_id, group_info, SRV_PHB_GROUP_OP_TYPE_UPD);
        }
    }
    else
    {
        srv_phb_group_op_done(result, group_id, NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_group
 * DESCRIPTION
 *  delete a group
 * PARAMETERS
 *  group_id            :   [IN]    group id
 * RETURNS
 *  result
 *****************************************************************************/
void srv_phb_delete_group(U8 group_id, srv_phb_group_callback_type cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_group_op_cntx.op = SRV_PHB_GROUP_OP_TYPE_DEL;
    g_srv_phb_group_op_cntx.cb = cb;
    g_srv_phb_group_op_cntx.user_data = user_data;
    if (group_id < MMI_PHB_GROUP_TOTAL_COUNT)
    {
        #if defined(__MMI_PHB_USIM_SUPPORT__) || defined(__SRV_PHB_TCARD_STORAGE_SUPPORT__)
        if (group_id >= MMI_PHB_GROUP_COUNT)
        {
            srv_phb_remove_all_group_members(group_id, srv_phb_remove_all_group_members_cb, user_data);
        }
        else
        #endif
        {
            srv_phb_remove_all_group_members(group_id, NULL, NULL);    
            srv_phb_set_phone_group_info(group_id, NULL, SRV_PHB_GROUP_OP_TYPE_DEL);
        }
    }
    else
    {
        srv_phb_group_op_done(SRV_PHB_NOT_FOUND, group_id, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_group_list
 * DESCRIPTION
 *  get group id list ordered by group name
 * PARAMETERS
 *  group_array         :   [OUT]   group id array
 *  group_name          :   [IN]    group name
 * RETURNS
 *  U8
 * RETURN VALUES
 *  count               :           group count
 ****************************************************************************/
U32 srv_phb_get_group_list(U8* group_array, U16* group_name, phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0;
    U32 i;
    U8 group_id;
    phb_storage_enum tmp_storage;
    srv_phb_group_info_struct group_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!group_array && !group_name)
    {
        return 0;
    }
    for (i = 0; i < g_srv_phb_group_sse_cntx.group_count; i ++)
    {
        group_id = g_srv_phb_group_sse_cntx.group_id[i];
        tmp_storage = srv_phb_get_storage_by_group_id(group_id);
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        if (tmp_storage == PHB_STORAGE_TCARD && (srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV) == MMI_FALSE || srv_phb_tcard_is_ready() == MMI_FALSE))
        {
            continue;
        }
        #endif
        if (storage == PHB_STORAGE_MAX || storage == tmp_storage)
        {
            group_array[count] = group_id;
            if (group_name != NULL)
            {
                srv_phb_get_group_info(group_id, &group_info);
                mmi_wcscpy(group_name + count * (MMI_PHB_GROUP_NAME_LENGTH + 1), group_info.group_name);
            }
            count++;
        }
    }
    return count;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_group_info
 * DESCRIPTION
 *  get a group's info
 * PARAMETERS
 *  group_id            :   [IN]    group id
 *  group_info          :   [OUT]   group info
 * RETURNS
 *  S32
 * RETURN VALUES
 *  0                   :           get success
 *  other               :           error result
 *****************************************************************************/
S32 srv_phb_get_group_info(U8 group_id, srv_phb_group_info_struct* group_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    phb_storage_enum phb_storage;
    #ifdef __MMI_PHB_USIM_SUPPORT__
    U8 sim_id;
    U16 store_index;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!group_info)
    {
        return SRV_PHB_ERROR;
    }
    phb_storage = srv_phb_get_storage_by_group_id(group_id);
    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    if (phb_storage == PHB_STORAGE_TCARD)
    {
        srv_phb_get_tcard_group_info(group_id, group_info);
    }
    else
    #endif
    #ifdef __MMI_PHB_USIM_SUPPORT__
    if (phb_storage >= PHB_STORAGE_SIM && phb_storage <= PHB_STORAGE_SIM4)
    {
        sim_id = srv_phb_get_sim_id(phb_storage);
        store_index = srv_phb_get_group_store_index(group_id);
        srv_phb_sim_get_gas(sim_id, store_index, group_info->group_name);
        group_info->storage = phb_storage;
    }
    else
    #endif
    {
        srv_phb_build_app_group_info(group_info, &g_srv_phb_phone_group_cache.group_info[group_id]);
    }
    return SRV_PHB_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_pri_group_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_phb_get_pri_group_info(U32 group_mask, mmi_phb_group_info_struct* group_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    U8 i = 0;
    U8 group_id = 0xff;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (group_mask && i < MMI_PHB_GROUP_TOTAL_COUNT)
    {
        if (group_mask & 1)
        {
            group_id = i;
        }
        group_mask /= 2;
        i ++;
    }
    if (group_id != 0xff)
    {
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        if (group_id >= (MMI_PHB_GROUP_USIM_COUNT + MMI_PHB_GROUP_COUNT))
        {
            srv_phb_group_info_struct group;
            srv_phb_get_tcard_group_info(group_id, &group);
            group_info->res_type = group.res_type;
            group_info->image_id = group.image_id;
            group_info->ringtone_id = group.ringtone_id;
            #ifdef __MMI_PHB_CALLER_VIDEO__
            group_info->video_id = group.video_id;
            #endif
        }
        else
        #endif
        {
            memcpy(group_info, &g_srv_phb_phone_group_cache.group_info[group_id], sizeof(mmi_phb_group_info_struct));
        }
        return SRV_PHB_NO_ERROR;
    }
    return SRV_PHB_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_pri_group_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_group_cancel_operation(srv_phb_group_op_type_enum op_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_group_member_op_cntx.is_canceled = MMI_TRUE;
}


#else /* __MMI_PHB_CALLER_GROUP__ */
#include "MMIDataType.h"
#include "phbsrvgprot.h"
/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_get_group_list
 * DESCRIPTION
 *  get group id list ordered by group name
 * PARAMETERS
 *  group_array         :   [OUT]   group id array
 *  group_name          :   [IN]    group name
 * RETURNS
 *  U8
 * RETURN VALUES
 *  count               :           group count
 ****************************************************************************/
U8 srv_phb_datamgr_get_group_list(U8* group_array, U16* group_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_group_list
 * DESCRIPTION
 *  get group id list ordered by group name
 * PARAMETERS
 *  group_array         :   [OUT]   group id array
 *  group_name          :   [IN]    group name
 * RETURNS
 *  U8
 * RETURN VALUES
 *  count               :           group count
 ****************************************************************************/
U32 srv_phb_get_group_list(U8* group_array, U16* group_name, phb_storage_enum storage)
{
    return 0;
}

#endif /* __MMI_PHB_CALLER_GROUP__ */

