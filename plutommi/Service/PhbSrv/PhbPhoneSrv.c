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
 *  PhbPhoneSrv.c
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/


/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_include.h"
#include "PhbSrvGprot.h"
#include "PhbSrv.h"
#include "FileMgrSrvGProt.h"
#include "mmi_rp_srv_phb_def.h"
#include "nvram_common_defs.h"

#define SRV_PHB_MULTI_READ_COUNT      (2048 / (NVRAM_EF_PHB_FIELDS_SIZE + NVRAM_CHKSUM_SIZE))
#define SRV_PHB_OPTIONAL_CACHE_MAX    ((MMI_PHB_PHONE_ENTRIES + SRV_PHB_MULTI_READ_COUNT - 1) / SRV_PHB_MULTI_READ_COUNT)
#define SRV_PHB_OPTIONAL_CACHE_COUNT  ((SRV_PHB_OPTIONAL_CACHE_MAX + 5) / 6) /* change magic number to modify cache size */

#define SRV_PHB_FREE_SUB_ID_BYTES     ((MMI_PHB_NUMBER_FIELD_COUNT * 2 + 7) / 8)

#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__ 
#define SRV_PHB_FIELD_LABEL_COUNT            (MMI_PHB_FIELD_LABEL_COUNT * MMI_PHB_FIELD_LABEL_FIELD)

#define SRV_PHB_MULTI_READ_LABEL_COUNT       (2048 / (NVRAM_EF_PHB_FIELD_LABEL_SIZE+ NVRAM_CHKSUM_SIZE))
#endif

typedef struct
{
    mmi_phb_contact_id id;
    mmi_phb_optional_fields_struct optional_filed[SRV_PHB_MULTI_READ_COUNT];
} srv_phb_optional_cache_struct;

typedef struct
{
    srv_phb_optional_cache_struct cache[SRV_PHB_OPTIONAL_CACHE_COUNT];
    U16 index_table[SRV_PHB_OPTIONAL_CACHE_MAX];
    U16 current_index;
    U16 total_count;
} srv_phb_optional_cache_cntx_struct;

typedef struct
{
    mmi_phb_name_struct name_field[MMI_PHB_PHONE_ENTRIES];
    mmi_phb_phone_mask_struct phone_mask[MMI_PHB_PHONE_ENTRIES];
    srv_phb_optional_cache_cntx_struct optional_cache;
#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__ 
    WCHAR label[SRV_PHB_FIELD_LABEL_COUNT][MMI_PHB_FIELD_LABEL_LENGTH + 1];
    U8 label_index[SRV_PHB_FIELD_LABEL_COUNT];
    U8 number_label_count;
    U8 email_label_count;
#endif
    mmi_phb_info_struct* info_cache;
} srv_phb_phone_cache_struct;

typedef struct
{
    U16 used_count;
    U16 total_count;
} srv_phb_phone_cntx_struct;

typedef struct
{
    mmi_phb_name_struct* entry;
    mmi_phb_contact_id id;
} srv_phb_startup_read_phone_req_struct;

srv_phb_phone_cache_struct g_srv_phb_phone_cache;

srv_phb_phone_cntx_struct g_srv_phb_phone_cntx;

static void srv_phb_startup_read_phone(void* info);


#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_phone_label
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_read_all_phone_label(WCHAR* label)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;
    U16 rec_index = 1;
    U16 read_count;
    U16 left_count = NVRAM_EF_PHB_FIELD_LABEL_TOTAL;
    S32 read_size;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        read_count = (left_count < SRV_PHB_MULTI_READ_LABEL_COUNT) ? left_count : SRV_PHB_MULTI_READ_LABEL_COUNT;
        read_size = ReadMultiRecord(
                        NVRAM_EF_PHB_FIELD_LABEL_LID,
                        (U16)rec_index,
                        label + (rec_index - 1) * (MMI_PHB_FIELD_LABEL_LENGTH + 1),
                        (U16)(read_count * NVRAM_EF_PHB_FIELD_LABEL_SIZE),
                        read_count,
                        &p_error);
        read_count = (U16)(read_size / NVRAM_EF_PHB_FIELD_LABEL_SIZE);
        rec_index += read_count;
        left_count -= read_count;
    } while (left_count);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_phone_label
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_write_phone_label(U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_PHB_FIELD_LABEL_LID,
        (U16)(index + 1),
         g_srv_phb_phone_cache.label[index],
        NVRAM_EF_PHB_FIELD_LABEL_SIZE,
        &p_error);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_get_empty_label_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_phb_phone_get_empty_label_index(mmi_phb_contact_field_id_enum field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 low, high;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (field == MMI_PHB_CONTACT_FIELD_ID_NUMBER)
    {
        low = 0;
        high = MMI_PHB_FIELD_LABEL_COUNT;
    }
    else
    {
        low = MMI_PHB_FIELD_LABEL_COUNT;
        high = SRV_PHB_FIELD_LABEL_COUNT;
    }
    while (low < high)
    {
        if (!(g_srv_phb_phone_cache.label[low][0]))
        {
            return low;
        }
        low++;
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_insert_label_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_phb_phone_insert_label_index(WCHAR* label, U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 mid = 0;
    U8 label_id;
    U8 base;
    S32 distance = 0;
    S32 low, high, end;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < MMI_PHB_FIELD_LABEL_COUNT)
    {
        low = 0;
        high = g_srv_phb_phone_cache.number_label_count - 1;
        end = high;
        base = MMI_PHB_NUM_TYPE_USER_BASE;
        index += base;
    }
    else
    {
        low = MMI_PHB_FIELD_LABEL_COUNT;
        high = g_srv_phb_phone_cache.email_label_count + MMI_PHB_FIELD_LABEL_COUNT - 1;
        end = high;
        base = MMI_PHB_EMAIL_TYPE_USER_BASE;
        index = index - MMI_PHB_FIELD_LABEL_COUNT + base;
    }
    mid = low;
    while (low <= high)
    {
        mid = (low + high) / 2;
        label_id = g_srv_phb_phone_cache.label_index[mid] - base;
        if (base == MMI_PHB_EMAIL_TYPE_USER_BASE)
        {
            label_id = g_srv_phb_phone_cache.label_index[mid] - base + MMI_PHB_FIELD_LABEL_COUNT;
        }
        /*
         * Compare search pattern with entry
         */
        distance = srv_phb_compare_ucs2_string(label, g_srv_phb_phone_cache.label[label_id]);
        if (distance == 0)
        {
            distance = mmi_wcscmp(label, g_srv_phb_phone_cache.label[label_id]);
        }

        if (distance == 0)
        {
            return MMI_FALSE;
        }
        else if (distance > 0)
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
        mid++;
    }
    while (mid <= end)
    {
        g_srv_phb_phone_cache.label_index[end + 1] = g_srv_phb_phone_cache.label_index[end];
        end--;
    }
    g_srv_phb_phone_cache.label_index[mid] = index;
    if (low < MMI_PHB_FIELD_LABEL_COUNT)
    {
        g_srv_phb_phone_cache.number_label_count++;
    }
    else
    {
        g_srv_phb_phone_cache.email_label_count++;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_insert_label_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_phb_phone_delete_label_index(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < MMI_PHB_FIELD_LABEL_COUNT)
    {
        index += MMI_PHB_NUM_TYPE_USER_BASE;
        for (i = 0; i < g_srv_phb_phone_cache.number_label_count; i++)
        {
            if (index == g_srv_phb_phone_cache.label_index[i])
            {
                g_srv_phb_phone_cache.number_label_count--;
                while (i < g_srv_phb_phone_cache.number_label_count)
                {
                    g_srv_phb_phone_cache.label_index[i] = g_srv_phb_phone_cache.label_index[i + 1];
                    i++;
                }
                return MMI_TRUE;
            }
        }
    }
    else
    {
        index = index -  MMI_PHB_FIELD_LABEL_COUNT + MMI_PHB_EMAIL_TYPE_USER_BASE;
        for (i = MMI_PHB_FIELD_LABEL_COUNT; i < (MMI_PHB_FIELD_LABEL_COUNT + g_srv_phb_phone_cache.email_label_count); i++)
        {

            if (index == g_srv_phb_phone_cache.label_index[i])
            {
                g_srv_phb_phone_cache.email_label_count--;
                while (i < (g_srv_phb_phone_cache.email_label_count + MMI_PHB_FIELD_LABEL_COUNT))
                {
                    g_srv_phb_phone_cache.label_index[i] = g_srv_phb_phone_cache.label_index[i + 1];
                    i++;
                }
                return MMI_TRUE;
            }
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_phone_label
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_init_phone_label(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_read_all_phone_label((WCHAR*)&(g_srv_phb_phone_cache.label));
    for (i = 0; i < MMI_PHB_FIELD_LABEL_COUNT; i++)
    {
        if (g_srv_phb_phone_cache.label[i][0])
        {
            srv_phb_phone_insert_label_index(g_srv_phb_phone_cache.label[i], (U8)i);
        }
    }
    for (i = MMI_PHB_FIELD_LABEL_COUNT; i < SRV_PHB_FIELD_LABEL_COUNT; i++)
    {
        if (g_srv_phb_phone_cache.label[i][0])
        {
            srv_phb_phone_insert_label_index(g_srv_phb_phone_cache.label[i], (U8)i);
        }
    }
}
#endif /* __MMI_PHB_CUSTOM_FIELD_TYPE__ */

/*****************************************************************************
 * FUNCTION
 *  srv_phb_reset_phone_optional_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_reset_phone_optional_cache(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_phone_cache.optional_cache.index_table[(id - (id % SRV_PHB_MULTI_READ_COUNT)) / SRV_PHB_MULTI_READ_COUNT] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_phone_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        Indication from L4 PHB
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_read_phone_mask(mmi_phb_phone_mask_struct* phone_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;
    U16 rec_index = 0;
    void* temp;
    S32 left_count = MMI_PHB_PHONE_ENTRIES;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        if (left_count < MMI_PHB_FIELDS_MASK_COUNT)
        {
            temp = srv_phb_mem_malloc(NVRAM_EF_PHB_FIELDS_MASK_SIZE, SRV_PHB_MEMORY_TYPE_CTR);
        }
        else
        {
            temp = phone_mask + rec_index * MMI_PHB_FIELDS_MASK_COUNT;
        }
        ReadRecord(
            NVRAM_EF_PHB_FIELDS_MASK_LID,
            (U16)(rec_index + 1),
            temp,
            NVRAM_EF_PHB_FIELDS_MASK_SIZE,
            &p_error);
        if (left_count < MMI_PHB_FIELDS_MASK_COUNT)
        {
            memcpy((phone_mask + rec_index * MMI_PHB_FIELDS_MASK_COUNT), temp, MMI_PHB_FIELDS_MASK_SIZE * left_count);
            srv_phb_mem_free(temp);
        }
        left_count -= MMI_PHB_FIELDS_MASK_COUNT;
    } while (++rec_index < NVRAM_EF_PHB_FIELDS_MASK_TOTAL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_phone_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        Indication from L4 PHB
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_write_phone_mask(mmi_phb_phone_mask_struct* phone_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;
    U16 rec_index = 0;
    void* temp;
    S32 left_count = MMI_PHB_PHONE_ENTRIES;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        if (left_count < MMI_PHB_FIELDS_MASK_COUNT)
        {
            temp = srv_phb_mem_malloc(NVRAM_EF_PHB_FIELDS_MASK_SIZE, SRV_PHB_MEMORY_TYPE_CTR);
            memcpy(temp, (phone_mask + rec_index * MMI_PHB_FIELDS_MASK_COUNT), MMI_PHB_FIELDS_MASK_SIZE * left_count);
        }
        else
        {
            temp = phone_mask + rec_index * MMI_PHB_FIELDS_MASK_COUNT;
        }
        WriteRecord(
            NVRAM_EF_PHB_FIELDS_MASK_LID,
            (U16)(rec_index + 1),
            temp,
            NVRAM_EF_PHB_FIELDS_MASK_SIZE,
            &p_error);
        if (left_count < MMI_PHB_FIELDS_MASK_COUNT)
        {
            srv_phb_mem_free(temp);
        }
        left_count -= MMI_PHB_FIELDS_MASK_COUNT;
    } while (++rec_index < NVRAM_EF_PHB_FIELDS_MASK_TOTAL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_free_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_phb_contact_id srv_phb_get_phone_free_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_phone_cntx.used_count != g_srv_phb_phone_cntx.total_count)
    {
        U16 start, end;
        start = 0;
        end = g_srv_phb_phone_cntx.total_count;
        while (start < end)
        {
            if (!g_srv_phb_phone_cache.phone_mask[start].field_mask)
            {
                return start;
            }
            start++;
        }
    }
    return MMI_PHB_INVALID_CONTACT_ID;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_read_phone_finish
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_startup_read_phone_finish(srv_phb_startup_read_phone_req_struct* req_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_PHONE_STARTUP_READ_FINISH,
            PHB_STORAGE_NVRAM, g_srv_phb_phone_cntx.used_count, g_srv_phb_phone_cntx.total_count);
    srv_phb_mem_free(req_info->entry);
    srv_phb_mem_free(req_info);
    srv_phb_datamgr_set_startup_ready(PHB_STORAGE_NVRAM);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_read_phone_next_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_startup_read_phone_next_req(void* req_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_async_event_interface(srv_phb_startup_read_phone, req_info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_read_phone
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_startup_read_phone(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_startup_read_phone_req_struct* req_info = info;
    mmi_phb_contact_id id = req_info->id;
    mmi_phb_name_struct* entry = req_info->entry;
    S16 p_error;
    U16 count = 2000 / NVRAM_EF_PHB_SIZE;
    S32 size;
    S32 i;
#if defined(__MMI_PHB_PINYIN_SORT__)
    U16 full_name[MMI_PHB_NAME_LENGTH + 1];
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size = ReadMultiRecord(
                NVRAM_EF_PHB_LID,
                (U16) (id + 1),
                (void*)entry,
                (U16)(NVRAM_EF_PHB_SIZE * count),
                count,
                &p_error);
    count = (U16)(size / NVRAM_EF_PHB_SIZE);
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_PHONE_STARTUP_READ_PHONE, req_info->id, count);

    /* Parse and save data from indication */
    for (i = 0; i < count; i++)
    {
        if (g_srv_phb_phone_cache.phone_mask[id].field_mask)
        {
            g_srv_phb_phone_cntx.used_count++;
            MMI_ASSERT((g_srv_phb_phone_cntx.used_count <= g_srv_phb_phone_cntx.total_count) && (id < MMI_PHB_PHONE_ENTRIES));
            memcpy(&g_srv_phb_phone_cache.name_field[id], &entry[i], sizeof(mmi_phb_name_struct));
        #if defined(__MMI_PHB_PINYIN_SORT__)
            srv_phb_datamgr_get_name(id, full_name, MMI_PHB_NAME_LENGTH);
            srv_phb_sse_make_pinyin_cache(id, full_name);
        #endif
            srv_phb_sse_populate_name_index(id);
        }
        id++;
    }
    req_info->id = srv_phb_get_next_phone_contact(id, SRV_PHB_ENTRY_FIELD_ALL);
    if (req_info->id < MMI_PHB_PHONE_ENTRIES)
    {
        srv_phb_startup_read_phone_next_req(req_info);
    }
    else
    {
        srv_phb_startup_read_phone_finish(req_info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_update_phone_name_field_mask
 * DESCRIPTION
 *  update name and number fileter flag of a entry.
 * PARAMETERS
 *  store_index              [IN]                 
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_update_phone_name_field_mask(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_name_struct* entry = &g_srv_phb_phone_cache.name_field[id];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (entry->name[0]
    #if defined(__MMI_PHB_LAST_NAME_FIELD__)
        || entry->l_name[0]
    #endif
        )
    {
        g_srv_phb_phone_cache.phone_mask[id].field_mask |= MMI_PHB_CONTACT_FIELD_NAME;
    }
    else
    {
        g_srv_phb_phone_cache.phone_mask[id].field_mask &= ~MMI_PHB_CONTACT_FIELD_NAME;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_phone_name
 * DESCRIPTION
 *   
 * PARAMETERS
 *   
 * RETURNS
 *   
 *****************************************************************************/
static MMI_BOOL srv_phb_write_phone_name(mmi_phb_contact_id id, WCHAR* fname, WCHAR* lname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;
    mmi_phb_name_struct* entry = &g_srv_phb_phone_cache.name_field[id];
    MMI_BOOL name_modify = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    if (fname)
    {
        mmi_wcsncpy(entry->name, fname, MMI_PHB_NAME_FIELD_LENGTH);
        name_modify = MMI_TRUE;
    }
    else
    {
        if (entry->name[0])
        {
            name_modify = MMI_TRUE;
        }
        entry->name[0] = 0;
    }
    if (lname)
    {
        mmi_wcsncpy(entry->l_name, lname, MMI_PHB_NAME_FIELD_LENGTH);
        name_modify = MMI_TRUE;
    }
    else
    {
        if (entry->l_name[0])
        {
            name_modify = MMI_TRUE;
        }
        entry->l_name[0] = 0;
    }
#else
    if (fname || lname)
    {
        srv_phb_convert_to_name(entry->name, fname, lname, MMI_PHB_NAME_FIELD_LENGTH);
        name_modify = MMI_TRUE;
    }
    else
    {
        if (entry->name[0])
        {
            name_modify = MMI_TRUE;
        }
        entry->name[0] = 0;
    }
#endif

    WriteRecord(
        NVRAM_EF_PHB_LID,
        (U16) (id + 1),
        (void*)entry,
        NVRAM_EF_PHB_SIZE,
        &p_error);
    return name_modify;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_clear_phone_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_clear_phone_name(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;
    mmi_phb_name_struct* entry = &g_srv_phb_phone_cache.name_field[id];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry->name[0] = 0;
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    entry->l_name[0] = 0;
#endif

    WriteRecord(
        NVRAM_EF_PHB_LID,
        (U16) (id + 1),
        (void*)entry,
        NVRAM_EF_PHB_SIZE,
        &p_error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_new_sub_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static mmi_phb_sub_id srv_phb_get_new_sub_id(U8* mask, U32 field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 max = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (field == MMI_PHB_CONTACT_FIELD_NUMBER)
    {
        max = MMI_PHB_NUMBER_FIELD_COUNT * 2;
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    else if (field == MMI_PHB_CONTACT_FIELD_EMAIL)
    {
        max = MMI_PHB_CONTACT_FIELD_EMAIL * 2;
    }
#endif
    else
    {
        ASSERT(0);
    }
    for (i = 0; i < max; i++)
    {
        if (!(mask[i >> 3] & (1 << (i % 8))))
        {
            mask[i >> 3] |= 1 << (i % 8);
            return i;
        }
    }
    ASSERT(0);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_build_free_id_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_build_free_id_mask(U8* mask, mmi_phb_optional_fields_struct* optional_fields_data, U32 field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(mask, 0, sizeof(U8) * SRV_PHB_FREE_SUB_ID_BYTES);
    if (field == MMI_PHB_CONTACT_FIELD_NUMBER)
    {
        mmi_phb_asc_num_struct* number;
        for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
        {
            number = &(optional_fields_data->num[i]);
            if (number && number->number[0])
            {
                ASSERT(number->sub_id < (MMI_PHB_NUMBER_FIELD_COUNT * 2));
                mask[number->sub_id / 8] |= (1 << number->sub_id % 8);
            }
        }
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    else if (field == MMI_PHB_CONTACT_FIELD_EMAIL)
    {
        mmi_phb_email_struct* email;
        for (i = 0; i < MMI_PHB_EMAIL_FIELD_COUNT; i++)
        {
            email = &(optional_fields_data->email_address[i]);
            if (email->email[0])
            {
                ASSERT(email->sub_id < (MMI_PHB_EMAIL_FIELD_COUNT * 2));
                mask[email->sub_id / 8] |= (1 << email->sub_id % 8);
            }
        }
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_update_optional_field_mask
 * DESCRIPTION
 *  update optional fileter flag of a entry
 * PARAMETERS
 *  store_index              [IN]        
 *  optional_fields          [IN]              
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_update_optional_field_mask(mmi_phb_contact_id id, mmi_phb_optional_fields_struct* optional_fields)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U32 tmp = g_srv_phb_phone_cache.phone_mask[id].field_mask;
    U8 count = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp &= ~(MMI_PHB_CONTACT_FIELD_NUMBER | MMI_PHB_CONTACT_FIELD_EMAIL | MMI_PHB_CONTACT_FIELD_DEF);
    for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
    {
        if (optional_fields->num[i].number[0])
        {
            count++;
        }
    }
    if (count)
    {
        tmp |= MMI_PHB_CONTACT_FIELD_NUMBER;
    }
#if (MMI_PHB_NUMBER_FIELD_COUNT > 1)
    g_srv_phb_phone_cache.phone_mask[id].num_count = count;
#endif
    
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    count = 0;
    for (i = 0; i < MMI_PHB_EMAIL_FIELD_COUNT; i++)
    {
        if (optional_fields->email_address[i].email[0])
        {
            count++;
        }
    }
    if (count)
    {
        tmp |= MMI_PHB_CONTACT_FIELD_EMAIL;
    }
#ifdef __MMI_PHB_DEFAULT_NUMBER__
    if (optional_fields->default_number)
    {
        tmp |= MMI_PHB_CONTACT_FIELD_DEF;
    }
#endif
#if (MMI_PHB_EMAIL_FIELD_COUNT > 1)
    g_srv_phb_phone_cache.phone_mask[id].email_count = count;
#endif
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */
    g_srv_phb_phone_cache.phone_mask[id].field_mask = tmp;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_optional_fields
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_write_optional_fields(mmi_phb_contact_id id, srv_phb_contact contact, U32 update_fields, srv_phb_update_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_optional_fields_struct* optional_fields_data = srv_phb_get_phone_optional_field(id);
    U8 id_mask[SRV_PHB_FREE_SUB_ID_BYTES];
    srv_phb_iterator iterator;
    S32 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (update_fields & MMI_PHB_CONTACT_FIELD_NUMBER)
    {
        srv_phb_number_struct* number;
        srv_phb_build_free_id_mask((U8*)id_mask, optional_fields_data, MMI_PHB_CONTACT_FIELD_NUMBER);
        iterator = srv_phb_contact_get_number_iterator(contact);
        index = 0;
    #ifdef __MMI_PHB_DEFAULT_NUMBER__
        /* replace mode will reset default number */
        if (mode == SRV_PHB_UPDATE_MODE_REPLACE)
        {
            optional_fields_data->default_number = 0;
        }
    #endif
        while (iterator)
        {
            number = srv_phb_contact_get_number_next(&iterator);
            if (number)
            {
                if (mode == SRV_PHB_UPDATE_MODE_IMPORT)
                {
                    index = number->index;
                }
                if (number->number[0])
                {
                    if (mode == SRV_PHB_UPDATE_MODE_IMPORT)
                    {
                        if (optional_fields_data->num[index].number[0])
                        {
                            number->sub_id = optional_fields_data->num[index].sub_id;
                        }
                        else
                        {
                            number->sub_id = MMI_PHB_SUB_ID_NEW;
                        }
                    }
                    else
                    {
                        number->index = index;
                    }
                    if (number->sub_id == MMI_PHB_SUB_ID_NEW)
                    {
                        number->sub_id = srv_phb_get_new_sub_id((U8*)id_mask, MMI_PHB_CONTACT_FIELD_NUMBER);
                    }

                    if (optional_fields_data->num[index].number[0])
                    {
                        srv_phb_sse_lookup_table_remove_contact(id, (CHAR*)(optional_fields_data->num[index].number));
                    }
                    optional_fields_data->num[index].sub_id = number->sub_id;
                    optional_fields_data->num[index].type = (mmi_phb_num_type_enum)(number->type);
                    optional_fields_data->num[index].last_used_sim = number->last_used_sim;
                    mmi_wcs_n_to_asc(
                        (CHAR*)(optional_fields_data->num[index].number),
                        (WCHAR*)number->number,
                        MMI_PHB_NUMBER_PLUS_LENGTH * sizeof(U16));
                #ifdef __MMI_PHB_DEFAULT_NUMBER__
                    if (number->is_default)
                    {
                        optional_fields_data->default_number = (U8)(index + 1);
                    }
                    else if (optional_fields_data->default_number == (U8)(index + 1))
                    {
                        optional_fields_data->default_number = 0;
                    }
                #endif
                    
                    srv_phb_sse_lookup_table_add_contact(id, (CHAR*)(optional_fields_data->num[index].number));
                    srv_phb_sse_set_number_cache(id, (CHAR*)(optional_fields_data->num[index].number), index);
                    if (mode == SRV_PHB_UPDATE_MODE_REPLACE)
                    {
                        index++;
                    }
                }
                else
                {
                    if (mode == SRV_PHB_UPDATE_MODE_IMPORT)
                    {
                        if (optional_fields_data->num[index].number[0])
                        {
                            srv_phb_sse_lookup_table_remove_contact(id, (CHAR*)(optional_fields_data->num[index].number));
                            srv_phb_sse_set_number_cache(id, NULL, index);
                            optional_fields_data->num[index].number[0] = 0;
                        #ifdef __MMI_PHB_DEFAULT_NUMBER__
                            if (optional_fields_data->default_number == (U8)(index + 1))
                            {
                                optional_fields_data->default_number = 0;
                            }
                        #endif
                        }
                    }
                }
            }
        }
        if ((mode == SRV_PHB_UPDATE_MODE_REPLACE) && (index < MMI_PHB_NUMBER_FIELD_COUNT))
        {
            for (; index < MMI_PHB_NUMBER_FIELD_COUNT; index++)
            {
                if (optional_fields_data->num[index].number[0])
                {
                    srv_phb_sse_lookup_table_remove_contact(id, (CHAR*)(optional_fields_data->num[index].number));
                    srv_phb_sse_set_number_cache(id, NULL, index);
                    optional_fields_data->num[index].number[0] = 0;

                    /* for send event */
                    srv_phb_contact_add_number_ex(
                                            contact,
                                            optional_fields_data->num[index].sub_id,
                                            index,
                                            MMI_PHB_NUM_TYPE_MOBILE,
                                            NULL,
                                            NULL,
                                            MMI_FALSE);
                }
            }
        }
    }
    
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (update_fields & MMI_PHB_CONTACT_FIELD_EMAIL)
    {
        srv_phb_email_struct* email;
        srv_phb_build_free_id_mask((U8*)id_mask, optional_fields_data, MMI_PHB_CONTACT_FIELD_EMAIL);
        iterator = srv_phb_contact_get_email_iterator(contact);
        index = 0;
        while (iterator)
        {
            email = srv_phb_contact_get_email_next(&iterator);
            if (email)
            {
                if (mode == SRV_PHB_UPDATE_MODE_IMPORT)
                {
                    index = email->index;
                }
                if (email->email[0])
                {
                    if (mode == SRV_PHB_UPDATE_MODE_IMPORT)
                    {
                        if (optional_fields_data->email_address[index].email[0])
                        {
                            email->sub_id = optional_fields_data->email_address[index].sub_id;
                        }
                        else
                        {
                            email->sub_id = MMI_PHB_SUB_ID_NEW;
                        }
                    }
                    else
                    {
                        email->index = index;
                    }
                    if (email->sub_id == MMI_PHB_SUB_ID_NEW)
                    {
                        email->sub_id = srv_phb_get_new_sub_id((U8*)id_mask, MMI_PHB_CONTACT_FIELD_EMAIL);
                    }

                    optional_fields_data->email_address[index].sub_id = email->sub_id;
                    optional_fields_data->email_address[index].type = email->type;
                    mmi_wcs_n_to_asc(
                        (CHAR*)(optional_fields_data->email_address[index].email),
                        (WCHAR*)email->email,
                        MMI_PHB_EMAIL_LENGTH * sizeof(U16));

                    if (mode == SRV_PHB_UPDATE_MODE_REPLACE)
                    {
                        index++;
                    }
                }
                else
                {
                    if (mode == SRV_PHB_UPDATE_MODE_IMPORT)
                    {
                        if (optional_fields_data->email_address[index].email[0])
                        {
                            optional_fields_data->email_address[index].email[0] = 0;
                        }
                    }
                }
            }
        }
        if ((mode == SRV_PHB_UPDATE_MODE_REPLACE) && (index < MMI_PHB_EMAIL_FIELD_COUNT))
        {
            for (; index < MMI_PHB_EMAIL_FIELD_COUNT; index++)
            {
                optional_fields_data->email_address[index].email[0] = 0;
                                    /* for send event */
                srv_phb_contact_add_email_ex(
                                        contact,
                                        optional_fields_data->email_address[index].sub_id,
                                        index,
                                        0,
                                        NULL,
                                        NULL);
            }
        }
    }
#endif
    srv_phb_write_phone_optional_field(id, optional_fields_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_clear_optional_fields
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_clear_optional_fields(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_optional_fields_struct* optional_fields_data = srv_phb_get_phone_optional_field(id);
    S16 p_error;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
    {
        optional_fields_data->num[i].number[0] = 0;
    }
    srv_phb_sse_lookup_table_remove_contact(id, NULL);
    srv_phb_sse_remove_number_cache(id);
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    for (i = 0; i < MMI_PHB_EMAIL_FIELD_COUNT; i++)
    {
        optional_fields_data->email_address[i].email[0] = 0;
    }
#ifdef __MMI_PHB_DEFAULT_NUMBER__
    optional_fields_data->default_number = 0;
#endif
#endif

    WriteRecord(
        NVRAM_EF_PHB_FIELDS_LID,
        (U16) (id + 1),
        optional_fields_data,
        NVRAM_EF_PHB_FIELDS_SIZE,
        &p_error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_dup_optional_fields
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_dup_optional_fields(mmi_phb_contact_id dest_id, mmi_phb_contact_id src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_optional_fields_struct *optional_fields_data = NULL;
    S32 i = 0;
    U8 storage = srv_phb_get_storage(src_id);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (storage == PHB_STORAGE_NVRAM)
    {
        optional_fields_data = srv_phb_get_phone_optional_field(src_id);
        for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
        {
            if (optional_fields_data->num[i].number[0])
            {
                srv_phb_sse_lookup_table_add_contact(dest_id, (CHAR*)(optional_fields_data->num[i].number));
                srv_phb_sse_set_number_cache(dest_id, (CHAR*)(optional_fields_data->num[i].number), i);
            }
        }
        srv_phb_reset_phone_optional_cache(dest_id);
    }
#ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    else if (storage == PHB_STORAGE_TCARD)
    {
        CHAR *data;
        U16 sub_id;
        U8 type;
        optional_fields_data = srv_phb_get_phone_optional_field(dest_id);
        #ifdef __MMI_PHB_DEFAULT_NUMBER__
        optional_fields_data->default_number = 1;
        #endif
        for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
        {
            data = srv_phb_get_tcard_number(src_id, i, &sub_id, &type, NULL);
            if (data && data[0])
            {
                strcpy((CHAR *)(optional_fields_data->num[i].number), data);
                optional_fields_data->num[i].sub_id = sub_id;
                optional_fields_data->num[i].type = (mmi_phb_num_type_enum)type;
                srv_phb_sse_lookup_table_add_contact(dest_id, data);
                srv_phb_sse_set_number_cache(dest_id, data, i);
            }
        }
        #ifdef __MMI_PHB_OPTIONAL_FIELD__
        for (i = 0; i < MMI_PHB_EMAIL_FIELD_COUNT; i++)
        {
            data = srv_phb_get_tcard_email(src_id, i, &sub_id, &type);
            if (data && data[0])
            {
                strcpy((CHAR *)(optional_fields_data->email_address[i].email), data);
                optional_fields_data->email_address[i].sub_id = i;
                optional_fields_data->email_address[i].type = type;
            }
        }
        #endif
    }
#endif /* __SRV_PHB_TCARD_STORAGE_SUPPORT__ */
    else
    {
        S32 j = 0;
        char *data = NULL;
        optional_fields_data = srv_phb_get_phone_optional_field(dest_id);
        #ifdef __MMI_PHB_DEFAULT_NUMBER__
        optional_fields_data->default_number = 1;
        #endif
        for (i = 0, j = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
        {
            while (j <= MMI_PHB_MAX_ANR_COUNT)
            {
                data = srv_phb_get_sim_number(src_id, j++, NULL);
                if (data && data[0])
                {
                    break;
                }
            }
            if (data && data[0])
            {
                strcpy((char *)(optional_fields_data->num[i].number), data);
                optional_fields_data->num[i].type = MMI_PHB_NUM_TYPE_MOBILE;
                optional_fields_data->num[i].sub_id = i;
                optional_fields_data->num[i].last_used_sim = 0;
                srv_phb_sse_lookup_table_add_contact(dest_id, (CHAR*)(optional_fields_data->num[i].number));
                srv_phb_sse_set_number_cache(dest_id, (CHAR*)(optional_fields_data->num[i].number), i);
                data = NULL;
            }
            else
            {
                break;
            }
        }
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        for (i = 0, j = 0; i < MMI_PHB_EMAIL_FIELD_COUNT; i++)
        {
            while (j < MMI_PHB_MAX_EMAIL_COUNT)
            {
                data = srv_phb_get_sim_email(src_id, j++);
                if (data && data[0])
                {
                    break;
                }
            }
            if (data && data[0])
            {
                strcpy((char *)(optional_fields_data->email_address[i].email), data);
                optional_fields_data->email_address[i].type = MMI_PHB_NUM_TYPE_MOBILE;
                optional_fields_data->email_address[i].sub_id = i;
                data = NULL;
            }
            else
            {
                break;
            }
        }
    #endif /* __MMI_PHB_OPTIONAL_FIELD__ */
    }
    srv_phb_write_phone_optional_field(dest_id, optional_fields_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_update_info_field_mask
 * DESCRIPTION
 *  update info fileter flag of a entry
 * PARAMETERS
 *  store_index              [IN]        
 *  info_fields          [IN]              
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_update_info_field_mask(mmi_phb_contact_id id, mmi_phb_info_struct* info_fields)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 tmp = g_srv_phb_phone_cache.phone_mask[id].field_mask;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (info_fields->res_type & SRV_PHB_RES_TYPE_IMAGE)
    {
        tmp |= MMI_PHB_CONTACT_FIELD_IMAGE;
    }
    else
    {
        tmp &= ~MMI_PHB_CONTACT_FIELD_IMAGE;
    }
    
    if (info_fields->res_type & SRV_PHB_RES_TYPE_RING)
    {
        tmp |= MMI_PHB_CONTACT_FIELD_RING;
    }
    else
    {
        tmp &= ~MMI_PHB_CONTACT_FIELD_RING;
    }

#ifdef __MMI_PHB_CALLER_VIDEO__
    if (info_fields->res_type & SRV_PHB_RES_TYPE_VIDEO)
    {
        tmp |= MMI_PHB_CONTACT_FIELD_VIDEO;
    }
    else
    {
        tmp &= ~MMI_PHB_CONTACT_FIELD_VIDEO;
    }
#endif /* __MMI_PHB_CALLER_VIDEO__ */

#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    if (info_fields->company[0])
    {
        tmp |= MMI_PHB_CONTACT_FIELD_COMPANY;
    }
    else
    {
        tmp &= ~MMI_PHB_CONTACT_FIELD_COMPANY;
    }
#endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */

#if defined(__MMI_PHB_INFO_FIELD__)
    if (info_fields->url[0])
    {
        tmp |= MMI_PHB_CONTACT_FIELD_URL;
    }
    else
    {
        tmp &= ~MMI_PHB_CONTACT_FIELD_URL;
    }
    
    if (info_fields->title[0])
    {
        tmp |= MMI_PHB_CONTACT_FIELD_TITLE;
    }
    else
    {
        tmp &= ~MMI_PHB_CONTACT_FIELD_TITLE;
    }

    if (info_fields->note[0])
    {
        tmp |= MMI_PHB_CONTACT_FIELD_NOTE;
    }
    else
    {
        tmp &= ~MMI_PHB_CONTACT_FIELD_NOTE;
    }


    if (info_fields->address.pobox[0]
        || info_fields->address.extension[0]
        || info_fields->address.street[0]
        || info_fields->address.city[0]
        || info_fields->address.state[0]
        || info_fields->address.postalcode[0]
        || info_fields->address.country[0])
    {
        tmp |= MMI_PHB_CONTACT_FIELD_ADDRESS;
    }
    else
    {
        tmp &= ~MMI_PHB_CONTACT_FIELD_ADDRESS;
    }
#endif

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    if (info_fields->bday.b_year)
    {
        tmp |= MMI_PHB_CONTACT_FIELD_BDAY;
    }
    else
    {
        tmp &= ~MMI_PHB_CONTACT_FIELD_BDAY;
    }
#endif

#if defined(__MMI_VOIP__)
    if (info_fields->voip[0])
    {
        tmp |= MMI_PHB_CONTACT_FIELD_VOIP;
    }
    else
    {
        tmp &= ~MMI_PHB_CONTACT_FIELD_VOIP;
    }
#endif

#if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if defined(__MMI_PHB_MSN_FIELD__)
    if (info_fields->msn[0])
    {
        tmp |= MMI_PHB_CONTACT_FIELD_MSN;
    }
    else
    {
        tmp &= ~MMI_PHB_CONTACT_FIELD_MSN;
    }
#endif

    g_srv_phb_phone_cache.phone_mask[id].field_mask = tmp;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_info_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_write_info_nvram(mmi_phb_contact_id id, mmi_phb_info_struct* info_fields)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_PHB_INFO_LID,
        (U16) (id + 1),
        (void*)info_fields,
         NVRAM_EF_PHB_INFO_SIZE,
        &p_error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_info_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_phb_info_struct* srv_phb_get_phone_info_field(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;
    mmi_phb_info_struct* info_fields =
            (mmi_phb_info_struct*)srv_phb_mem_malloc(sizeof(mmi_phb_info_struct), SRV_PHB_MEMORY_TYPE_CTR);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_PHB_INFO_LID,
        (U16) (id + 1),
        (void*)info_fields,
         NVRAM_EF_PHB_INFO_SIZE,
        &p_error);
    return info_fields;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_info_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_phb_write_info_field(mmi_phb_contact_id id, srv_phb_contact contact, U32 update_fields)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_info_struct* info_fields = srv_phb_get_phone_info_field(id);
    S32 result = SRV_PHB_NO_ERROR;
#if defined (__MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__) || defined (__MMI_PHB_INFO_FIELD__) || defined (__MMI_PHB_BIRTHDAY_FIELD__) || defined (__MMI_VOIP__) || defined (__MMI_IMPS__) || defined (__MMI_PHB_MSN_FIELD__)
    void *data = NULL;
#endif
    srv_phb_res_struct* src_res;
#if defined(__MMI_PHB_INFO_FIELD__)
    srv_phb_iterator iterator;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (update_fields & MMI_PHB_CONTACT_FIELD_IMAGE)
    {
        src_res = srv_phb_contact_get_image(contact);
        if (src_res)
        {
            if (!srv_phb_datamgr_update_res_path(
                    MMI_PHB_CONTACT_FIELD_IMAGE,
                    info_fields->image_id,
                    (info_fields->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE) ? MMI_TRUE : MMI_FALSE,
                    &src_res->res_id,
                    src_res->res_path[0] ? MMI_TRUE : MMI_FALSE,
                    src_res->res_path))
            {
                src_res->res_path[0] = 0;
                result += SRV_PHB_IMAGE_ERROR;
            }
            info_fields->res_type &= ~SRV_PHB_RES_TYPE_IMAGE;
            if (src_res->res_path[0])
            {
                info_fields->res_type |= SRV_PHB_RES_TYPE_IMAGE_FILE;
            }
            else if (src_res->res_id && src_res->res_id != IMG_PHB_DEFAULT)
            {
                info_fields->res_type |= SRV_PHB_RES_TYPE_IMAGE_ID;
            }
            info_fields->image_id = src_res->res_id;
        }
        else
        {
            if (info_fields->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE)
            {
                srv_phb_datamgr_clear_res_path(MMI_PHB_CONTACT_FIELD_ID_IMAGE, (U16)(info_fields->image_id));
            }
            info_fields->image_id= 0;
            info_fields->res_type &= ~SRV_PHB_RES_TYPE_IMAGE;
        }
    }
    
    if (update_fields & MMI_PHB_CONTACT_FIELD_RING)
    {
        src_res = srv_phb_contact_get_ringtone(contact);
        if (src_res)
        {
            if (!srv_phb_datamgr_update_res_path(
                    MMI_PHB_CONTACT_FIELD_RING,
                    info_fields->ringtone_id,
                    (info_fields->res_type & SRV_PHB_RES_TYPE_RING_FILE) ? MMI_TRUE : MMI_FALSE,
                    &src_res->res_id,
                    (src_res->res_path[0] ? MMI_TRUE : MMI_FALSE),
                    src_res->res_path))
            {
                src_res->res_path[0] = 0;
                result += SRV_PHB_RING_ERROR;
            }
            info_fields->res_type &= ~SRV_PHB_RES_TYPE_RING;
            if (src_res->res_path[0])
            {
                info_fields->res_type |= SRV_PHB_RES_TYPE_RING_FILE;
            }
            else if (src_res->res_id)
            {
                info_fields->res_type |= SRV_PHB_RES_TYPE_RING_ID;
            }
            info_fields->ringtone_id= src_res->res_id;
        }
        else
        {
            if (info_fields->res_type & SRV_PHB_RES_TYPE_RING_FILE)
            {
                srv_phb_datamgr_clear_res_path(MMI_PHB_CONTACT_FIELD_ID_RING, (U16)(info_fields->ringtone_id));
            }
            info_fields->ringtone_id= 0;
            info_fields->res_type &= ~SRV_PHB_RES_TYPE_RING;
        }
    }

#if defined(__MMI_PHB_CALLER_VIDEO__)
    if (update_fields & MMI_PHB_CONTACT_FIELD_VIDEO)
    {
        src_res = srv_phb_contact_get_video(contact);
        if (src_res)
        {
            if (!srv_phb_datamgr_update_res_path(
                    MMI_PHB_CONTACT_FIELD_VIDEO,
                    info_fields->video_id,
                    (info_fields->res_type & SRV_PHB_RES_TYPE_VIDEO_FILE) ? MMI_TRUE : MMI_FALSE,
                    &src_res->res_id,
                    (src_res->res_path[0] ? MMI_TRUE : MMI_FALSE),
                    src_res->res_path))
            {
                src_res->res_path[0] = 0;
                result += SRV_PHB_VIDEO_ERROR;
            }
            do
            {
                info_fields->res_type &= ~SRV_PHB_RES_TYPE_VIDEO;
                if (src_res->res_path[0])
                {
                    info_fields->res_type |= SRV_PHB_RES_TYPE_VIDEO_FILE;
                }
                else if (src_res->res_id)
                {
                    info_fields->res_type |= SRV_PHB_RES_TYPE_VIDEO_ID;
                }
                else
                {
                    break;
                }
                if (src_res->flag)
                {
                    info_fields->res_type |= SRV_PHB_RES_TYPE_VIDEO_SOUND_ON;
                }
                info_fields->video_id = src_res->res_id;
            } while (0);
        }
        else
        {
            if (info_fields->res_type & SRV_PHB_RES_TYPE_VIDEO_FILE)
            {
                srv_phb_datamgr_clear_res_path(MMI_PHB_CONTACT_FIELD_ID_VIDEO, (U16)(info_fields->video_id));
            }
            info_fields->video_id= 0;
            info_fields->res_type &= ~SRV_PHB_RES_TYPE_VIDEO;
        }
    }
#endif /* __MMI_PHB_CALLER_VIDEO__ */

#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    if (update_fields & MMI_PHB_CONTACT_FIELD_COMPANY)
    {
        data = srv_phb_contact_get_company(contact);
        if (data)
        {
            mmi_wcsncpy((WCHAR*)(info_fields->company), (WCHAR*)data, MMI_PHB_COMPANY_LENGTH);
        }
        else
        {
            info_fields->company[0] = 0;
        }
    }
#endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */

#if defined(__MMI_PHB_INFO_FIELD__)
    if (update_fields & MMI_PHB_CONTACT_FIELD_URL)
    {
        iterator = srv_phb_contact_get_url_iterator(contact);
        data = srv_phb_contact_get_url_next(&iterator);
        if (data)
        {
            mmi_wcs_n_to_asc((CHAR*)(info_fields->url), ((srv_phb_url_struct*)data)->url, MMI_PHB_URL_LENGTH * sizeof(U16));
        }
        else
        {
            info_fields->url[0] = 0;
        }
    }
    
    if (update_fields & MMI_PHB_CONTACT_FIELD_TITLE)
    {
        data = srv_phb_contact_get_title(contact);
        if (data)
        {
            mmi_wcsncpy((WCHAR*)(info_fields->title), (WCHAR*)data, MMI_PHB_TITLE_LENGTH);
        }
        else
        {
            info_fields->title[0] = 0;
        }
    }
    
    if (update_fields & MMI_PHB_CONTACT_FIELD_NOTE)
    {
        iterator = srv_phb_contact_get_note_iterator(contact);
        data = srv_phb_contact_get_note_next(&iterator);
        if (data)
        {
            mmi_wcsncpy((WCHAR*)(info_fields->note), ((srv_phb_note_struct*)data)->note, MMI_PHB_NOTE_LENGTH);
        }
        else
        {
            info_fields->note[0] = 0;
        }
    }
    
    if (update_fields & MMI_PHB_CONTACT_FIELD_ADDRESS)
    {
        iterator = srv_phb_contact_get_address_iterator(contact);
        data = srv_phb_contact_get_address_next(&iterator);
        if (data)
        {
            data = (void*)&(((srv_phb_address_struct*)data)->address);
            mmi_wcsncpy(
                (WCHAR*)(info_fields->address.pobox),
                (WCHAR*)(((mmi_phb_address_struct*)data)->pobox),
                MMI_PHB_ADDRESS_LENGTH);
            
            mmi_wcsncpy(
                (WCHAR*)(info_fields->address.extension),
                (WCHAR*)(((mmi_phb_address_struct*)data)->extension),
                MMI_PHB_ADDRESS_LENGTH);
            mmi_wcsncpy(
                (WCHAR*)(info_fields->address.street),
                (WCHAR*)(((mmi_phb_address_struct*)data)->street),
                MMI_PHB_ADDRESS_LENGTH);
            
            mmi_wcsncpy(
                (WCHAR*)(info_fields->address.city),
                (WCHAR*)(((mmi_phb_address_struct*)data)->city),
                MMI_PHB_ADDRESS_LENGTH);
            mmi_wcsncpy(
                (WCHAR*)(info_fields->address.state),
                (WCHAR*)(((mmi_phb_address_struct*)data)->state),
                MMI_PHB_ADDRESS_LENGTH);
            mmi_wcsncpy(
                (WCHAR*)(info_fields->address.postalcode),
                (WCHAR*)(((mmi_phb_address_struct*)data)->postalcode),
                MMI_PHB_ADDRESS_LENGTH);
            mmi_wcsncpy(
                (WCHAR*)(info_fields->address.country),
                (WCHAR*)(((mmi_phb_address_struct*)data)->country),
                MMI_PHB_ADDRESS_LENGTH);
        }
        else
        {
            info_fields->address.pobox[0] = 0;
            info_fields->address.extension[0] = 0;
            info_fields->address.street[0] = 0;
            info_fields->address.city[0] = 0;
            info_fields->address.state[0] = 0;
            info_fields->address.postalcode[0] = 0;
            info_fields->address.country[0] = 0;
        }
    }
#endif /* defined(__MMI_PHB_INFO_FIELD__) */

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    if (update_fields & MMI_PHB_CONTACT_FIELD_BDAY)
    {
        data = srv_phb_contact_get_bday(contact);
        if (data)
        {
            memcpy(&(info_fields->bday), data, sizeof(mmi_phb_bday_struct));
        }
        else
        {
            memset(&(info_fields->bday), 0, sizeof(mmi_phb_bday_struct));
        }
    }
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */

#if defined(__MMI_VOIP__)
    if (update_fields & MMI_PHB_CONTACT_FIELD_VOIP)
    {
        data = srv_phb_contact_get_voip(contact);
        if (data)
        {
            mmi_wcs_n_to_asc((CHAR*)(info_fields->voip), (WCHAR*)data, (VOIP_URI_LEN - 1) * sizeof(U16));
        }
        else
        {
            info_fields->voip[0] = 0;
        }
    }
#endif /* defined(__MMI_VOIP__) */

#if defined(__MMI_IMPS__)
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
#endif /* defined(__MMI_IMPS__) */

#if defined(__MMI_PHB_MSN_FIELD__)
    if (update_fields & MMI_PHB_CONTACT_FIELD_MSN)
    {
        data = srv_phb_contact_get_msn(contact);
        if (data)
        {
            mmi_wcs_n_to_asc((CHAR*)(info_fields->msn), (WCHAR*)data, MMI_PHB_EMAIL_LENGTH * sizeof(U16));
        }
        else
        {
            info_fields->msn[0] = 0;
        }
    }
#endif /* defined(__MMI_PHB_MSN_FIELD__) */

    srv_phb_write_info_nvram(id, info_fields);
    srv_phb_update_info_field_mask(id, info_fields);

    srv_phb_mem_free(info_fields);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_clear_info_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_clear_info_field(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;
    mmi_phb_info_struct* info_fields;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_PHB_CALLER_RES_DATA_STORE__
    info_fields = srv_phb_get_phone_info_field(id);

    if (info_fields->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE)
    {
        srv_phb_datamgr_clear_res_path(MMI_PHB_CONTACT_FIELD_ID_IMAGE, (U16)(info_fields->image_id));
    }
    info_fields->image_id= 0;
    if (info_fields->res_type & SRV_PHB_RES_TYPE_RING_FILE)
    {
        srv_phb_datamgr_clear_res_path(MMI_PHB_CONTACT_FIELD_ID_RING, (U16)(info_fields->ringtone_id));
    }
    info_fields->ringtone_id= 0;
#if defined(__MMI_PHB_CALLER_VIDEO__)
    if (info_fields->res_type & SRV_PHB_RES_TYPE_VIDEO_FILE)
    {
        srv_phb_datamgr_clear_res_path(MMI_PHB_CONTACT_FIELD_ID_VIDEO, (U16)(info_fields->video_id));
    }
    info_fields->video_id = 0;
#endif /* __MMI_PHB_CALLER_VIDEO__ */
#else
    info_fields = (mmi_phb_info_struct*)srv_phb_mem_malloc(sizeof(mmi_phb_info_struct), SRV_PHB_MEMORY_TYPE_CTR);
#endif

    info_fields->res_type = 0;
    
#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    info_fields->company[0] = 0;
#endif

#if defined(__MMI_PHB_INFO_FIELD__)
    info_fields->title[0] = 0;
    info_fields->url[0] = 0;
    info_fields->note[0] = 0;

    info_fields->address.pobox[0] = 0;
    info_fields->address.extension[0] = 0;
    info_fields->address.street[0] = 0;
    info_fields->address.city[0] = 0;
    info_fields->address.state[0] = 0;
    info_fields->address.postalcode[0] = 0;
    info_fields->address.country[0] = 0;
#endif
    
#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    info_fields->bday.b_year = 0;
    info_fields->bday.b_month = 0;
    info_fields->bday.b_day = 0;
#endif
    
#if defined(__MMI_VOIP__)
    info_fields->voip[0] = 0;
#endif
    
#if defined(__MMI_IMPS__)
/* under construction !*/
#endif
    
#if defined(__MMI_PHB_MSN_FIELD__)
    info_fields->msn[0] = 0;
#endif

    WriteRecord(
        NVRAM_EF_PHB_INFO_LID,
        (U16) (id + 1),
        info_fields,
        NVRAM_EF_PHB_INFO_SIZE,
        &p_error);

    srv_phb_mem_free(info_fields);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_dup_info_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_phb_dup_info_field(mmi_phb_contact_id dest_id, mmi_phb_contact_id src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_info_struct* info_fields;
    S32 result = SRV_PHB_NO_ERROR;
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info_fields = srv_phb_get_phone_info_field(src_id);
    if (!srv_phb_datamgr_get_res_path(
            MMI_PHB_CONTACT_FIELD_IMAGE,
            info_fields->image_id, 
            (U16)(info_fields->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE),
            path))
    {
        info_fields->image_id = IMG_PHB_DEFAULT;
    }
    else if (!srv_phb_datamgr_update_res_path(
                MMI_PHB_CONTACT_FIELD_IMAGE,
                0,
                MMI_FALSE,
                &info_fields->image_id,
                path[0] ? MMI_TRUE : MMI_FALSE,
                path))
    {
        result += SRV_PHB_IMAGE_ERROR;
        info_fields->res_type &= ~SRV_PHB_RES_TYPE_IMAGE;
        info_fields->res_type |= SRV_PHB_RES_TYPE_IMAGE_ID;
    }
    
    if (!srv_phb_datamgr_get_res_path(
            MMI_PHB_CONTACT_FIELD_RING,
            info_fields->ringtone_id, 
            (U16)(info_fields->res_type & SRV_PHB_RES_TYPE_RING_FILE),
            path))
    {
        info_fields->image_id = IMG_PHB_DEFAULT;
    }
    else if (!srv_phb_datamgr_update_res_path(
                MMI_PHB_CONTACT_FIELD_RING,
                0,
                MMI_FALSE,
                &info_fields->ringtone_id,
                path[0] ? MMI_TRUE : MMI_FALSE,
                path))
    {
        result += SRV_PHB_RING_ERROR;
        info_fields->res_type &= ~SRV_PHB_RES_TYPE_RING;
        info_fields->res_type |= SRV_PHB_RES_TYPE_RING_ID;
    }

#if defined(__MMI_PHB_CALLER_VIDEO__)
    if (!srv_phb_datamgr_get_res_path(
            MMI_PHB_CONTACT_FIELD_VIDEO,
            info_fields->video_id, 
            (U16)(info_fields->res_type & SRV_PHB_RES_TYPE_VIDEO_FILE),
            path))
    {
        info_fields->image_id = IMG_PHB_DEFAULT;
    }
    else if (!srv_phb_datamgr_update_res_path(
                MMI_PHB_CONTACT_FIELD_VIDEO,
                0,
                MMI_FALSE,
                &info_fields->video_id,
                path[0] ? MMI_TRUE : MMI_FALSE,
                path))
    {
        result += SRV_PHB_VIDEO_ERROR;
        info_fields->res_type &= ~SRV_PHB_RES_TYPE_VIDEO;
        info_fields->res_type |= SRV_PHB_RES_TYPE_VIDEO_ID;
    }
#endif /* __MMI_PHB_CALLER_VIDEO__ */


    srv_phb_write_info_nvram(dest_id, info_fields);
    srv_phb_mem_free(info_fields);
    return result;
}

#ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_dup_tcard_info_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static S32 srv_phb_dup_tcard_info_field(mmi_phb_contact_id dest_id, mmi_phb_contact_id src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_info_struct* info_fields;
    S32 result = SRV_PHB_NO_ERROR;
    U16 res_type;
    WCHAR path[SRV_FMGR_PATH_MAX_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    info_fields = srv_phb_get_tcard_info_field(src_id);
    if (info_fields->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE)
    {
        srv_phb_get_tcard_image(src_id, NULL, path, &res_type);
    }
    if (!srv_phb_datamgr_update_res_path(
                MMI_PHB_CONTACT_FIELD_IMAGE,
                0,
                MMI_FALSE,
                &info_fields->image_id,
                path[0] ? MMI_TRUE : MMI_FALSE,
                path))
    {
        result += SRV_PHB_IMAGE_ERROR;
        info_fields->res_type &= ~SRV_PHB_RES_TYPE_IMAGE;
        info_fields->res_type |= SRV_PHB_RES_TYPE_IMAGE_ID;
    }
    path[0] = 0;
    if (info_fields->res_type & SRV_PHB_RES_TYPE_RING_FILE)
    {
        srv_phb_get_tcard_ringtone(src_id, NULL, path, &res_type);
    }
    if (!srv_phb_datamgr_update_res_path(
                MMI_PHB_CONTACT_FIELD_RING,
                0,
                MMI_FALSE,
                &info_fields->ringtone_id,
                path[0] ? MMI_TRUE : MMI_FALSE,
                path))
    {
        result += SRV_PHB_RING_ERROR;
        info_fields->res_type &= ~SRV_PHB_RES_TYPE_RING;
        info_fields->res_type |= SRV_PHB_RES_TYPE_RING_ID;
    }

    #if defined(__MMI_PHB_CALLER_VIDEO__)
    path[0] = 0;
    if (info_fields->res_type & SRV_PHB_RES_TYPE_VIDEO_FILE)
    {
        srv_phb_get_tcard_video(src_id, NULL, path, &res_type);
    }
    if (!srv_phb_datamgr_update_res_path(
                MMI_PHB_CONTACT_FIELD_VIDEO,
                0,
                MMI_FALSE,
                &info_fields->video_id,
                path[0] ? MMI_TRUE : MMI_FALSE,
                path))
    {
        result += SRV_PHB_VIDEO_ERROR;
        info_fields->res_type &= ~SRV_PHB_RES_TYPE_VIDEO;
        info_fields->res_type |= SRV_PHB_RES_TYPE_VIDEO_ID;
    }
    #endif /* __MMI_PHB_CALLER_VIDEO__ */


    srv_phb_write_info_nvram(dest_id, info_fields);
    return result;
}

#endif

#ifdef __MMI_PHB_CALLER_GROUP__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_group_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_write_group_field(mmi_phb_contact_id id, srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 group_mask[MMI_PHB_GROUP_FIELD_SIZE];
    srv_phb_group_struct* group = srv_phb_contact_get_group(contact);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(group_mask, 0, sizeof(group_mask));
    if (group)
    {
        for (i = 0; i < group->group_count; i++)
        {
            group_mask[group->group_id[i] / 8] |= (1 << (group->group_id[i] % 8));
        }
    }
#ifdef __MMI_PHB_CALLER_GROUP__
    srv_phb_set_phone_group_field(id, (U8*)group_mask, SRV_PHB_GROUP_FIELD_OP_TYPE_SET);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_clear_group_field
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_clear_group_field(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;
    U8* group_field;
    U16 index;
    U16 record_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    record_id = (id / MMI_PHB_GROUP_FIELD_COUNT) + 1;
    index = id - (record_id - 1) * MMI_PHB_GROUP_FIELD_COUNT;
    group_field = srv_phb_mem_malloc(NVRAM_EF_PHB_GROUP_FIELD_SIZE, SRV_PHB_MEMORY_TYPE_CTR);
    ReadRecord(
        NVRAM_EF_PHB_GROUP_FIELD_LID,
        record_id,
        group_field,
        NVRAM_EF_PHB_GROUP_FIELD_SIZE,
        &p_error);
    
    memset(group_field + index * MMI_PHB_GROUP_FIELD_SIZE, 0, MMI_PHB_GROUP_FIELD_SIZE);

    WriteRecord(
        NVRAM_EF_PHB_GROUP_FIELD_LID,
        record_id,
        group_field,
        NVRAM_EF_PHB_GROUP_FIELD_SIZE,
        &p_error);
    srv_phb_mem_free(group_field);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_dup_group_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_dup_group_field(mmi_phb_contact_id dest_id, mmi_phb_contact_id src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;
    U8* group_field;
    U16 index;
    U16 record_id;
    U8 group_mask[MMI_PHB_GROUP_FIELD_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    record_id = (src_id / MMI_PHB_GROUP_FIELD_COUNT) + 1;
    index = src_id - (record_id - 1) * MMI_PHB_GROUP_FIELD_COUNT;
    group_field = srv_phb_mem_malloc(NVRAM_EF_PHB_GROUP_FIELD_SIZE, SRV_PHB_MEMORY_TYPE_CTR);
    ReadRecord(
        NVRAM_EF_PHB_GROUP_FIELD_LID,
        record_id,
        group_field,
        NVRAM_EF_PHB_GROUP_FIELD_SIZE,
        &p_error);
    memcpy(group_mask, group_field + index * MMI_PHB_GROUP_FIELD_SIZE, MMI_PHB_GROUP_FIELD_SIZE);
    
    record_id = (dest_id / MMI_PHB_GROUP_FIELD_COUNT) + 1;
    index = dest_id - (record_id - 1) * MMI_PHB_GROUP_FIELD_COUNT;
    ReadRecord(
        NVRAM_EF_PHB_GROUP_FIELD_LID,
        record_id,
        group_field,
        NVRAM_EF_PHB_GROUP_FIELD_SIZE,
        &p_error);
    
    memcpy(group_field + index * MMI_PHB_GROUP_FIELD_SIZE, group_mask, MMI_PHB_GROUP_FIELD_SIZE);

    WriteRecord(
        NVRAM_EF_PHB_GROUP_FIELD_LID,
        record_id,
        group_field,
        NVRAM_EF_PHB_GROUP_FIELD_SIZE,
        &p_error);
    srv_phb_mem_free(group_field);
}
#endif /* __MMI_PHB_CALLER_GROUP__ */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_op_phone_contact_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  
 *****************************************************************************/
static void srv_phb_op_phone_contact_done(void* status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_datamgr_op_done((srv_phb_datamgr_op_status_struct*)status);
    srv_phb_mem_free(status);
}


#define EXTERNAL_FUNCTION
/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
 
/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_support_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_phone_support_field(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 field;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    field = MMI_PHB_CONTACT_FIELD_NAME
            | MMI_PHB_CONTACT_FIELD_NUMBER
            | MMI_PHB_CONTACT_FIELD_GROUP
            | MMI_PHB_CONTACT_FIELD_RING
            | MMI_PHB_CONTACT_FIELD_IMAGE
        #ifdef __MMI_PHB_OPTIONAL_FIELD__
            | MMI_PHB_CONTACT_FIELD_EMAIL
        #ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__    
            | MMI_PHB_CONTACT_FIELD_COMPANY
        #endif
        #ifdef __MMI_PHB_DEFAULT_NUMBER__
            | MMI_PHB_CONTACT_FIELD_DEF
        #endif
        #endif /*__MMI_PHB_OPTIONAL_FIELD__ */
        #ifdef __MMI_PHB_CALLER_VIDEO__
            | MMI_PHB_CONTACT_FIELD_VIDEO
        #endif
        #if defined(__MMI_PHB_INFO_FIELD__)
            | MMI_PHB_CONTACT_FIELD_URL
            | MMI_PHB_CONTACT_FIELD_TITLE
            | MMI_PHB_CONTACT_FIELD_NOTE
            | MMI_PHB_CONTACT_FIELD_ADDRESS
        #endif
        #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
            | MMI_PHB_CONTACT_FIELD_BDAY
        #endif
        #if defined(__MMI_VOIP__)
            | MMI_PHB_CONTACT_FIELD_VOIP
        #endif
        #if defined(__MMI_IMPS__)
/* under construction !*/
        #endif
        #if defined(__MMI_VIDEO_TELEPHONY__)
            | MMI_PHB_CONTACT_FIELD_VT
        #endif
        #if defined(__MMI_PHB_MSN_FIELD__)
            | MMI_PHB_CONTACT_FIELD_MSN
        #endif
            ;
    return field;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_support_field_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_phone_support_field_count(mmi_phb_contact_field_id_enum field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (field)
    {
        case MMI_PHB_CONTACT_FIELD_ID_NUMBER:
            return MMI_PHB_NUMBER_FIELD_COUNT;

        case MMI_PHB_CONTACT_FIELD_ID_EMAIL:
            return MMI_PHB_EMAIL_FIELD_COUNT;

        case MMI_PHB_CONTACT_FIELD_ID_NAME:
        case MMI_PHB_CONTACT_FIELD_ID_RING:
        case MMI_PHB_CONTACT_FIELD_ID_IMAGE:
        case MMI_PHB_CONTACT_FIELD_ID_GROUP:
    #ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
        case MMI_PHB_CONTACT_FIELD_ID_COMPANY:
    #ifdef __MMI_PHB_DEFAULT_NUMBER__
        case MMI_PHB_CONTACT_FIELD_ID_DEF:
    #endif
    #endif
    #if defined(__MMI_PHB_INFO_FIELD__)
        case MMI_PHB_CONTACT_FIELD_ID_ADDRESS:
        case MMI_PHB_CONTACT_FIELD_ID_TITLE:
        case MMI_PHB_CONTACT_FIELD_ID_URL:
        case MMI_PHB_CONTACT_FIELD_ID_NOTE:
    #endif
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        case MMI_PHB_CONTACT_FIELD_ID_BDAY:
    #endif
    #ifdef __MMI_PHB_CALLER_VIDEO__
        case MMI_PHB_CONTACT_FIELD_ID_VIDEO:
    #endif
    #if defined(__MMI_VOIP__)
        case MMI_PHB_CONTACT_FIELD_ID_VOIP:
    #endif
    #if defined(__MMI_IMPS__)
/* under construction !*/
    #endif
    #if defined(__MMI_PHB_MSN_FIELD__)
        case MMI_PHB_CONTACT_FIELD_ID_MSN:
    #endif
    #if defined(__MMI_VIDEO_TELEPHONY__)
        case MMI_PHB_CONTACT_FIELD_ID_VT:
    #endif
            return 1;
    
        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_alpha_field_len
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_phone_alpha_field_len(mmi_phb_contact_field_id_enum field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (field)
    {
        case MMI_PHB_CONTACT_FIELD_ID_NAME:
            return MMI_PHB_NAME_FIELD_LENGTH;
            
        case MMI_PHB_CONTACT_FIELD_ID_NUMBER:
            return MMI_PHB_NUMBER_PLUS_LENGTH;
            
    #if defined(__MMI_PHB_MSN_FIELD__)
        case MMI_PHB_CONTACT_FIELD_ID_MSN:
    #endif
        case MMI_PHB_CONTACT_FIELD_ID_EMAIL:
            return MMI_PHB_EMAIL_LENGTH;

    #ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
        case MMI_PHB_CONTACT_FIELD_ID_COMPANY:
            return MMI_PHB_COMPANY_LENGTH;
    #endif
    
    #if defined(__MMI_PHB_INFO_FIELD__)
        case MMI_PHB_CONTACT_FIELD_ID_ADDRESS:
            return MMI_PHB_ADDRESS_LENGTH;
            
        case MMI_PHB_CONTACT_FIELD_ID_TITLE:
            return MMI_PHB_TITLE_LENGTH;
            
        case MMI_PHB_CONTACT_FIELD_ID_URL:
            return MMI_PHB_URL_LENGTH;
            
        case MMI_PHB_CONTACT_FIELD_ID_NOTE:
            return MMI_PHB_NOTE_LENGTH;
    #endif
    
    #if defined(__MMI_VOIP__)
        case MMI_PHB_CONTACT_FIELD_ID_VOIP:
            return VOIP_URI_LEN - 1;
    #endif
    
    #if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
    #endif
    
        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_phone_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_set_phone_field_mask(mmi_phb_contact_id id, U32 filed_flag, MMI_BOOL exist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (exist)
    {
        g_srv_phb_phone_cache.phone_mask[id].field_mask |= filed_flag;
    }
    else
    {
        g_srv_phb_phone_cache.phone_mask[id].field_mask &= ~filed_flag;;
    }
    srv_phb_commit_phone_fields_mask(id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_change_phone_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_change_phone_field_mask(mmi_phb_contact_id id, U32 filed_flag, MMI_BOOL exist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (exist)
    {
        g_srv_phb_phone_cache.phone_mask[id].field_mask |= filed_flag;
    }
    else
    {
        g_srv_phb_phone_cache.phone_mask[id].field_mask &= ~filed_flag;;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_commit_phone_fields_mask
 * DESCRIPTION
 * 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_commit_phone_fields_mask(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;
    U16 rec_index = id / MMI_PHB_FIELDS_MASK_COUNT;
    void* temp;
    S32 left_count = MMI_PHB_PHONE_ENTRIES - (rec_index * MMI_PHB_FIELDS_MASK_COUNT);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (left_count < MMI_PHB_FIELDS_MASK_COUNT)
    {
        temp = srv_phb_mem_malloc(NVRAM_EF_PHB_FIELDS_MASK_SIZE, SRV_PHB_MEMORY_TYPE_CTR);
        memcpy(
            temp,
            (g_srv_phb_phone_cache.phone_mask + rec_index * MMI_PHB_FIELDS_MASK_COUNT),
            MMI_PHB_FIELDS_MASK_SIZE * left_count);
    }
    else
    {
        temp = g_srv_phb_phone_cache.phone_mask + rec_index * MMI_PHB_FIELDS_MASK_COUNT;
    }

    WriteRecord(
        NVRAM_EF_PHB_FIELDS_MASK_LID,
        (U16)(rec_index + 1),
        temp,
        NVRAM_EF_PHB_FIELDS_MASK_SIZE,
        &p_error);
    if (left_count < MMI_PHB_FIELDS_MASK_COUNT)
    {
        srv_phb_mem_free(temp);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_commit_all_phone_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_commit_all_phone_field_mask(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_write_phone_mask((mmi_phb_phone_mask_struct*)(g_srv_phb_phone_cache.phone_mask));
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_phone_field_mask(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_phb_phone_cache.phone_mask[id].field_mask;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_read_optional_nvram
 * DESCRIPTION
 *  sqlite exec
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_phone_read_optional_nvram(U16 store_index, mmi_phb_optional_fields_struct* optional_fields_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(
        NVRAM_EF_PHB_FIELDS_LID,
        (U16) (store_index + 1),
        optional_fields_data,
        NVRAM_EF_PHB_FIELDS_SIZE,
        &p_error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_multi_read_optional_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_phb_phone_multi_read_optional_nvram(U16 store_index, mmi_phb_optional_fields_struct* optional_fields_data, U16 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ReadMultiRecord(
                NVRAM_EF_PHB_FIELDS_LID,
                (U16) (store_index + 1),
                optional_fields_data,
                (U16)(count * NVRAM_EF_PHB_FIELDS_SIZE),
                count,
                &p_error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_fname
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
WCHAR* srv_phb_get_phone_fname(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_phb_phone_cache.name_field[id].name;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_lname
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
WCHAR* srv_phb_get_phone_lname(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    return g_srv_phb_phone_cache.name_field[id].l_name;
#else
    return NULL;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_num_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_phb_get_phone_num_count(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_PHB_NUMBER_FIELD_COUNT > 1)
    return g_srv_phb_phone_cache.phone_mask[id].num_count;
#else
    if (g_srv_phb_phone_cache.phone_mask[id].field_mask & MMI_PHB_CONTACT_FIELD_NUMBER)
    {
        return 1;
    }
    else
    {
        return 0;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_email_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_phb_get_phone_email_count(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_PHB_EMAIL_FIELD_COUNT > 1)
    return g_srv_phb_phone_cache.phone_mask[id].email_count;
#else
    if (g_srv_phb_phone_cache.phone_mask[id].field_mask & MMI_PHB_CONTACT_FIELD_EMAIL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_optional_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_phb_optional_fields_struct* srv_phb_get_phone_optional_field(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_optional_cache_cntx_struct* cntx = &(g_srv_phb_phone_cache.optional_cache);
    mmi_phb_contact_id base_id = id - (id % SRV_PHB_MULTI_READ_COUNT) + 1;
    U16 index = cntx->index_table[base_id / SRV_PHB_MULTI_READ_COUNT];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!index)
    {
        S16 p_error;
        mmi_phb_contact_id temp_id = cntx->cache[cntx->current_index].id;
        index = ++cntx->current_index;
        
        if (cntx->current_index >= SRV_PHB_OPTIONAL_CACHE_COUNT)
        {
            cntx->current_index = 0;
        }
        
        if (temp_id && temp_id != MMI_PHB_INVALID_CONTACT_ID)
        {
            cntx->index_table[(temp_id - 1) / SRV_PHB_MULTI_READ_COUNT] = 0;
        }
        cntx->index_table[(base_id - 1) / SRV_PHB_MULTI_READ_COUNT] = index;
        cntx->cache[index - 1].id = base_id;

        ReadMultiRecord(
                NVRAM_EF_PHB_FIELDS_LID,
                (U16)base_id,
                &(cntx->cache[index - 1].optional_filed),
                (U16)(SRV_PHB_MULTI_READ_COUNT * NVRAM_EF_PHB_FIELDS_SIZE),
                SRV_PHB_MULTI_READ_COUNT,
                &p_error);
    }
    return cntx->cache[index - 1].optional_filed + (id % SRV_PHB_MULTI_READ_COUNT);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_phone_optional_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_write_phone_optional_field(mmi_phb_contact_id id, mmi_phb_optional_fields_struct* optional_fields_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_PHB_FIELDS_LID,
        (U16) (id + 1),
        optional_fields_data,
        NVRAM_EF_PHB_FIELDS_SIZE,
        &p_error);
    srv_phb_update_optional_field_mask(id, optional_fields_data);
}


#ifdef __MMI_PHB_CALLER_GROUP__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_group_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_get_phone_group_field(mmi_phb_contact_id id, U8* group_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_id;
    U16 index;
    S16 p_error;
    U8* group_field;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    record_id = (id / MMI_PHB_GROUP_FIELD_COUNT) + 1;
    index = id - (record_id - 1) * MMI_PHB_GROUP_FIELD_COUNT;
    group_field = srv_phb_mem_malloc(NVRAM_EF_PHB_GROUP_FIELD_SIZE, SRV_PHB_MEMORY_TYPE_CTR); 
    ReadRecord(
        NVRAM_EF_PHB_GROUP_FIELD_LID,
        record_id,
        group_field,
        NVRAM_EF_PHB_GROUP_FIELD_SIZE,
        &p_error);
    memcpy(group_mask, group_field + index * MMI_PHB_GROUP_FIELD_SIZE, MMI_PHB_GROUP_FIELD_SIZE);
    srv_phb_mem_free(group_field);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_phone_group_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_set_phone_group_field(mmi_phb_contact_id id, U8* group_mask, U8 type)
{
    S16 p_error;
    U16 record_id;
    U16 index;
    U8* group_field;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    record_id = (id / MMI_PHB_GROUP_FIELD_COUNT) + 1;
    index = id - (record_id - 1) * MMI_PHB_GROUP_FIELD_COUNT;
    group_field = srv_phb_mem_malloc(NVRAM_EF_PHB_GROUP_FIELD_SIZE, SRV_PHB_MEMORY_TYPE_CTR); 
    memset(group_field, 0, sizeof(group_field));
    ReadRecord(
        NVRAM_EF_PHB_GROUP_FIELD_LID,
        record_id,
        group_field,
        NVRAM_EF_PHB_GROUP_FIELD_SIZE,
        &p_error);
    
    for (i = 0; i < MMI_PHB_GROUP_FIELD_SIZE; i++)
    {
        if (type == SRV_PHB_GROUP_FIELD_OP_TYPE_SET)
        {
            group_field[index * MMI_PHB_GROUP_FIELD_SIZE + i] = group_mask[i];
        }
        else if (type == SRV_PHB_GROUP_FIELD_OP_TYPE_ADD)
        {
            group_field[index * MMI_PHB_GROUP_FIELD_SIZE + i] |= group_mask[i];
        }
        else
        {
            group_field[index * MMI_PHB_GROUP_FIELD_SIZE + i] &= ~group_mask[i];
        }
    }

    WriteRecord(
        NVRAM_EF_PHB_GROUP_FIELD_LID,
        record_id,
        group_field,
        NVRAM_EF_PHB_GROUP_FIELD_SIZE,
        &p_error);

    g_srv_phb_phone_cache.phone_mask[id].field_mask &= ~MMI_PHB_CONTACT_FIELD_GROUP;
    for (i = 0; i < MMI_PHB_GROUP_FIELD_SIZE; i++)
    {
        if (group_field[index * MMI_PHB_GROUP_FIELD_SIZE + i])
        {
            g_srv_phb_phone_cache.phone_mask[id].field_mask |= MMI_PHB_CONTACT_FIELD_GROUP;
        }
    }
    srv_phb_mem_free(group_field);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_all_phone_group_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_get_all_phone_group_field(U8* gourp_field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;
    U16 rec_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        ReadRecord(
            NVRAM_EF_PHB_GROUP_FIELD_LID,
            (U16)(rec_index + 1),
            (gourp_field + rec_index * NVRAM_EF_PHB_GROUP_FIELD_SIZE),
            NVRAM_EF_PHB_GROUP_FIELD_SIZE,
            &p_error);
    } while (++rec_index < NVRAM_EF_PHB_GROUP_FIELD_TOTAL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_all_phone_group_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_set_all_phone_group_field(U8* gourp_field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 p_error;
    U16 rec_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    do
    {
        WriteRecord(
            NVRAM_EF_PHB_GROUP_FIELD_LID,
            (U16)(rec_index + 1),
            (gourp_field + rec_index * NVRAM_EF_PHB_GROUP_FIELD_SIZE),
            NVRAM_EF_PHB_GROUP_FIELD_SIZE,
            &p_error);
    } while (++rec_index < NVRAM_EF_PHB_GROUP_FIELD_TOTAL);
}
#endif /* __MMI_PHB_CALLER_GROUP__ */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_next_phone_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_phb_get_next_phone_contact(U16 start, U32 field_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 end = g_srv_phb_phone_cntx.total_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (start < end)
    {
        if (g_srv_phb_phone_cache.phone_mask[start].field_mask & field_mask)
        {
            return start;
        }
        start++;
    }
    return SRV_PHB_INVALID_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_used
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_phb_get_phone_used(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_phb_phone_cntx.used_count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_total
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_phb_get_phone_total(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_phb_phone_cntx.total_count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_phone_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_init_phone_name(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_contact_id id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_phone_cntx.total_count = MMI_PHB_PHONE_ENTRIES;
    srv_phb_read_phone_mask((mmi_phb_phone_mask_struct*)(g_srv_phb_phone_cache.phone_mask));
#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
    srv_phb_init_phone_label();
#endif
    id = srv_phb_get_next_phone_contact(0, SRV_PHB_ENTRY_FIELD_ALL);
    if (id < MMI_PHB_PHONE_ENTRIES)
    {
        srv_phb_startup_read_phone_req_struct* req_info;
        req_info = srv_phb_mem_malloc(sizeof(srv_phb_startup_read_phone_req_struct), SRV_PHB_MEMORY_TYPE_ADM);
        req_info->entry = srv_phb_mem_malloc((2000 / NVRAM_EF_PHB_SIZE) * NVRAM_EF_PHB_SIZE, SRV_PHB_MEMORY_TYPE_ADM);
        req_info->id = id;
        srv_phb_startup_read_phone_next_req(req_info);
    }
    else
    {
        srv_phb_datamgr_set_startup_ready(PHB_STORAGE_NVRAM);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_phone_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_read_phone_contact(mmi_phb_contact_id id, srv_phb_contact contact, srv_phb_field_filter filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 contact_mask = srv_phb_get_phone_field_mask(id);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_NAME) &&
        (contact_mask & MMI_PHB_CONTACT_FIELD_NAME))
    {
        WCHAR* name;
        name = srv_phb_get_phone_fname(id);
        if (name && name[0])
        {
            srv_phb_contact_set_fname(contact, name);
        }

    #ifdef __MMI_PHB_LAST_NAME_FIELD__
        name = srv_phb_get_phone_lname(id);
        if (name && name[0])
        {
            srv_phb_contact_set_lname(contact, name);
        }
    #endif
    }
    
    if (srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_OPTIONAL) &&
        (contact_mask & MMI_PHB_CONTACT_FIELD_OPTIONAL))
    {
        mmi_phb_optional_fields_struct* optional_fields_data = srv_phb_get_phone_optional_field(id);
        S32 i;
        
        if ((contact_mask & MMI_PHB_CONTACT_FIELD_NUMBER) &&
            srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_NUMBER))
        {
            mmi_phb_asc_num_struct* number;
            MMI_BOOL is_default;
            for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
            {
                number = &(optional_fields_data->num[i]);
            #ifdef __MMI_PHB_DEFAULT_NUMBER__
                if (optional_fields_data->default_number && (i == (U8)optional_fields_data->default_number - 1))
                {
                    is_default = MMI_TRUE;
                }
                else
            #endif
                {
                    is_default = MMI_FALSE;
                }
                if (number->number[0] && srv_phb_check_number_by_feild_filter(filter, number->type, is_default))
                {
                    srv_phb_contact_add_asc_number_ex(
                                    contact,
                                    number->sub_id,
                                    i,
                                    number->type,
                                    number->last_used_sim,
                                    (CHAR*)(number->number),
                                    srv_phb_phone_get_type_label(number->type, MMI_PHB_CONTACT_FIELD_ID_NUMBER),
                                    is_default);

                }
            }
        }
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        if ((contact_mask & MMI_PHB_CONTACT_FIELD_EMAIL) &&
            srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_EMAIL))
        {
            mmi_phb_email_struct* email;
            for (i = 0; i < MMI_PHB_EMAIL_FIELD_COUNT; i++)
            {
                email = &(optional_fields_data->email_address[i]);
                if (email->email[0])
                {
                    srv_phb_contact_add_asc_email(
                                    contact,
                                    email->sub_id,
                                    i,
                                    email->type,
                                    (CHAR*)(email->email),
                                    srv_phb_phone_get_type_label(email->type, MMI_PHB_CONTACT_FIELD_ID_EMAIL));
                }
            }
        }
    #endif
    }
    
    if (srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_INFO) &&
        (contact_mask & MMI_PHB_CONTACT_FIELD_INFO))
    {
        mmi_phb_info_struct* info_fields = srv_phb_get_phone_info_field(id);
        srv_phb_res_struct* dest;

        if ((contact_mask & MMI_PHB_CONTACT_FIELD_IMAGE) &&
            srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_IMAGE))
        {
            S32 result;
            dest = srv_phb_contact_set_image(contact, NULL);
            result = srv_phb_datamgr_get_res_path(
                    MMI_PHB_CONTACT_FIELD_IMAGE,
                    info_fields->image_id, 
                    (U16)(info_fields->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE),
                    dest->res_path);
            if (result == 0 || result == 3)
            {
                dest->res_id = IMG_PHB_DEFAULT;
                if (result == 3)
                {
                    info_fields->res_type &= ~SRV_PHB_RES_TYPE_IMAGE_FILE;
                    srv_phb_write_info_nvram(id, info_fields);
                }
            }
            else
            {
                dest->res_id = info_fields->image_id;
            }
        }
        
        if ((contact_mask & MMI_PHB_CONTACT_FIELD_RING) &&
            srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_RING))
        {
            dest = srv_phb_contact_set_ringtone(contact, NULL);
            
            if (!srv_phb_datamgr_get_res_path(
                    MMI_PHB_CONTACT_FIELD_RING,
                    info_fields->ringtone_id, 
                    (U16)(info_fields->res_type & SRV_PHB_RES_TYPE_RING_FILE),
                    dest->res_path))
            {
                dest->res_id = 0;
            }
            else
            {
            #if defined(__MMI_FILE_MANAGER__)
                if (dest->res_path[0] && srv_fmgr_fs_path_exist(dest->res_path) != 0)
                {
                    dest->res_path[0] = 0;
                    dest->res_id = 0;
                }
                else
            #endif /* defined(__MMI_FILE_MANAGER__) */
                {
                    dest->res_id = info_fields->ringtone_id;
                }
            }
        }
        
    #if defined(__MMI_PHB_CALLER_VIDEO__)
        if ((contact_mask & MMI_PHB_CONTACT_FIELD_VIDEO) &&
            srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_VIDEO))
        {
            dest = srv_phb_contact_set_video(contact, NULL);
            
            if (info_fields->res_type & SRV_PHB_RES_TYPE_VIDEO_SOUND_ON)
            {
                dest->flag = MMI_TRUE;
            }
            if (!srv_phb_datamgr_get_res_path(
                    MMI_PHB_CONTACT_FIELD_VIDEO,
                    info_fields->video_id, 
                    (U16)(info_fields->res_type & SRV_PHB_RES_TYPE_VIDEO_FILE),
                    dest->res_path))
            {
                dest->res_id = 0;
            }
            else
            {
            #if defined(__MMI_FILE_MANAGER__)
                if (srv_fmgr_fs_path_exist(dest->res_path) != 0)
                {
                    dest->res_path[0] = 0;
                }
            #endif /* defined(__MMI_FILE_MANAGER__) */
                dest->res_id = info_fields->video_id;
            }
        }
    #endif /* __MMI_PHB_CALLER_VIDEO__ */
        
    #ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
        if (info_fields->company[0] &&
            srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_COMPANY))
        {
            srv_phb_contact_set_company(contact, (WCHAR*)(info_fields->company));
        }
    #endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */

    #if defined(__MMI_PHB_INFO_FIELD__)
        if (info_fields->url[0] &&
            srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_URL))
        {
            srv_phb_contact_add_asc_url(contact, 0, 0, (CHAR*)(info_fields->url));
        }

        if (info_fields->title[0] &&
            srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_TITLE))
        {
            srv_phb_contact_set_title(contact, (WCHAR*)(info_fields->title));
        }

        if (info_fields->note[0] &&
            srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_NOTE))
        {
            srv_phb_contact_add_note_ex(contact, 0, 0, (WCHAR*)(info_fields->note));
        }

        if ((contact_mask & MMI_PHB_CONTACT_FIELD_ADDRESS) &&
            srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_ADDRESS))
        {
            srv_phb_contact_add_address_ex(contact, 0, 0, (mmi_phb_address_struct*)&(info_fields->address));
        }
    #endif
    
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
        if ((contact_mask & MMI_PHB_CONTACT_FIELD_BDAY) &&
            srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_BDAY))
        {
            srv_phb_contact_set_bday(contact, (mmi_phb_bday_struct*)&(info_fields->bday));
        }
    #endif
    
    #if defined(__MMI_VOIP__)
        if ((contact_mask & MMI_PHB_CONTACT_FIELD_VOIP) &&
            srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_VOIP))
        {
            srv_phb_contact_set_asc_voip(contact, (CHAR*)(info_fields->voip));
        }
    #endif
    
    #if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    
    #if defined(__MMI_PHB_MSN_FIELD__)
        if ((contact_mask & MMI_PHB_CONTACT_FIELD_MSN) &&
            srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_MSN))
        {
            srv_phb_contact_set_asc_msn(contact, (CHAR*)(info_fields->msn));
        }
    #endif

        srv_phb_mem_free(info_fields);
    }

#ifdef __MMI_PHB_CALLER_GROUP__
    if (srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_GROUP) &&
        (contact_mask & MMI_PHB_CONTACT_FIELD_GROUP))
    {
        S32 i;
        srv_phb_group_struct* group = NULL;
        U8 group_mask[MMI_PHB_GROUP_FIELD_SIZE];
        srv_phb_get_phone_group_field(id, (U8*)group_mask);
        for (i = 0; i < MMI_PHB_GROUP_COUNT; i++)
        {
            if (group_mask[i / 8] & (1 << (i % 8)))
            {
                if (!group)
                {
                    group = srv_phb_contact_set_group(contact, NULL);
                }
                group->group_id[group->group_count++] = i;
            }
        }
    }
#endif /* __MMI_PHB_CALLER_GROUP__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_phone_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_write_phone_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_contact_id id = MMI_PHB_INVALID_CONTACT_ID;
    S32 result = SRV_PHB_NO_ERROR;
    srv_phb_datamgr_op_status_struct* status = srv_phb_mem_malloc(sizeof(srv_phb_datamgr_op_status_struct), SRV_PHB_MEMORY_TYPE_CTR);
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->op_type == SRV_PHB_DATAMGR_OP_TYPE_ADD && cntx->pos.index == SRV_PHB_INVALID_INDEX)
    {
        id = srv_phb_get_phone_free_index();
        if (id == MMI_PHB_INVALID_CONTACT_ID)
        {
            result = SRV_PHB_STORAGE_FULL;
        }
        else
        {
            cntx->pos.index = (U16)(id + 1);
        }
    }
    else
    {
        srv_phb_record_index_to_store_index(cntx->pos.storage, cntx->pos.index, &id);
        if (cntx->op_type == SRV_PHB_DATAMGR_OP_TYPE_ADD && g_srv_phb_phone_cache.phone_mask[id].field_mask)
        {
            cntx->op_type = SRV_PHB_DATAMGR_OP_TYPE_UPD;
        }
    }
    if (result == SRV_PHB_NO_ERROR)
    {
        g_srv_phb_phone_cache.phone_mask[id].field_mask |= MMI_PHB_CONTACT_FIELD_EXIST;
        if (cntx->update_field & MMI_PHB_CONTACT_FIELD_NAME)
        {
            MMI_BOOL is_modify = srv_phb_write_phone_name(
                                            id,
                                            srv_phb_contact_get_fname(cntx->contact),
                                            srv_phb_contact_get_lname(cntx->contact));
            if ((cntx->op_type == SRV_PHB_DATAMGR_OP_TYPE_UPD) && (is_modify))
            {
                srv_phb_sse_delete_name_index(id);
            }
            if ((cntx->op_type != SRV_PHB_DATAMGR_OP_TYPE_UPD) || (is_modify))
            {
                srv_phb_sse_insert_name_index(id, srv_phb_contact_get_name(cntx->contact));
            
            #if defined(__MMI_PHB_PINYIN_SORT__)    /* Make Pinyin cache for later sorting. */
                srv_phb_sse_make_pinyin_cache(id, srv_phb_contact_get_name(cntx->contact));
            #endif
            }
            if (cntx->op_type == SRV_PHB_DATAMGR_OP_TYPE_ADD)
            {
                g_srv_phb_phone_cntx.used_count++;
                MMI_ASSERT((g_srv_phb_phone_cntx.used_count <= g_srv_phb_phone_cntx.total_count) && (id < MMI_PHB_PHONE_ENTRIES));
            }
            srv_phb_update_phone_name_field_mask(id);
        }

        if (cntx->update_field & MMI_PHB_CONTACT_FIELD_OPTIONAL) 
        {
            srv_phb_write_optional_fields(id, cntx->contact, cntx->update_field, cntx->mode);
        }

        if (cntx->update_field & MMI_PHB_CONTACT_FIELD_INFO) 
        {
            result = srv_phb_write_info_field(id, cntx->contact, cntx->update_field);
        }

    #ifdef __MMI_PHB_CALLER_GROUP__
        if (cntx->update_field & MMI_PHB_CONTACT_FIELD_GROUP) 
        {
            srv_phb_write_group_field(id, cntx->contact);
        }
    #endif /* __MMI_PHB_CALLER_GROUP__ */
        srv_phb_commit_phone_fields_mask(id);
    }
    
    status->result = result;
    status->id = id;
    srv_phb_async_event_interface(srv_phb_op_phone_contact_done, status);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_phone_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_delete_phone_contact(srv_phb_contact_pos_struct* pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_contact_id id = MMI_PHB_INVALID_CONTACT_ID;
    srv_phb_datamgr_op_status_struct* status = srv_phb_mem_malloc(sizeof(srv_phb_datamgr_op_status_struct), SRV_PHB_MEMORY_TYPE_CTR);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_record_index_to_store_index(pos->storage, pos->index, &id);
    srv_phb_clear_phone_name(id);
   
    srv_phb_clear_optional_fields(id);
    
    srv_phb_clear_info_field(id);

#ifdef __MMI_PHB_CALLER_GROUP__
    srv_phb_clear_group_field(id);
#endif
    srv_phb_set_phone_field_mask(id, MMI_PHB_CONTACT_FIELD_ALL, MMI_FALSE);
    
    MMI_ASSERT(g_srv_phb_phone_cntx.used_count> 0);
    g_srv_phb_phone_cntx.used_count--;
    
    /* Remove lookup table entry */
    srv_phb_sse_lookup_table_remove_contact(id, NULL); 

    /* clear phonebook entry and remove from index */
    srv_phb_sse_delete_name_index(id); 
    status->result = SRV_PHB_NO_ERROR;
    status->id = id;
    srv_phb_async_event_interface(srv_phb_op_phone_contact_done, status);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_copy_phone_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_copy_phone_contact(mmi_phb_contact_id src_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_contact_id dest_id = MMI_PHB_INVALID_CONTACT_ID;
    U32 field_mask = srv_phb_datamgr_get_field_mask(src_id);
    S32 result = SRV_PHB_NO_ERROR;
    srv_phb_datamgr_op_status_struct* status = srv_phb_mem_malloc(sizeof(srv_phb_datamgr_op_status_struct), SRV_PHB_MEMORY_TYPE_CTR);
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();
    U8 storage = srv_phb_get_storage(cntx->src_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dest_id = srv_phb_get_phone_free_index();
    if (dest_id == MMI_PHB_INVALID_CONTACT_ID)
    {
        result = SRV_PHB_STORAGE_FULL;
    }
    else
    {
        cntx->pos.index = (U16)(dest_id + 1);
    }
    
    if (result == SRV_PHB_NO_ERROR)
    {
        #ifdef __MMI_PHB_LAST_NAME_FIELD__
        WCHAR name[MMI_PHB_NAME_LENGTH + 1];
        #endif
        WCHAR *p_name;
        WCHAR *f_name;
        WCHAR *l_name;
        g_srv_phb_phone_cntx.used_count++;
        MMI_ASSERT((g_srv_phb_phone_cntx.used_count <= g_srv_phb_phone_cntx.total_count) && (dest_id < MMI_PHB_PHONE_ENTRIES));

        if (storage == PHB_STORAGE_NVRAM)
        {
            f_name = srv_phb_get_phone_fname(src_id);
            l_name = srv_phb_get_phone_lname(src_id);

            #ifdef __MMI_PHB_LAST_NAME_FIELD__
            srv_phb_convert_to_name(name, f_name, l_name, MMI_PHB_NAME_LENGTH);
            p_name = name;
            #else
            p_name = f_name;
            #endif
            
            #ifdef __MMI_PHB_CALLER_GROUP__
            srv_phb_dup_group_field(dest_id, src_id);
            #endif
        }
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        else if (storage == PHB_STORAGE_TCARD)
        {
            f_name = srv_phb_get_tcard_fname(src_id);
            l_name = srv_phb_get_tcard_lname(src_id);
            #ifdef __MMI_PHB_LAST_NAME_FIELD__
            srv_phb_convert_to_name(name, f_name, l_name, MMI_PHB_NAME_LENGTH);
            p_name = name;
            #else
            p_name = f_name;
            #endif
        }
        #endif
        else
        {
            f_name = srv_phb_get_sim_name(src_id);
            l_name = NULL;
            p_name = f_name;
        }
        
        srv_phb_write_phone_name(dest_id, f_name, l_name);
        srv_phb_sse_insert_name_index(dest_id, p_name);
        #ifdef __MMI_PHB_PINYIN_SORT__    /* Make Pinyin cache for later sorting. */
        srv_phb_sse_make_pinyin_cache(dest_id, p_name);
        #endif
        srv_phb_dup_optional_fields(dest_id, src_id);

        if (storage == PHB_STORAGE_NVRAM)
        {
            result = srv_phb_dup_info_field(dest_id, src_id);
        }
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        else if (storage == PHB_STORAGE_TCARD)
        {
            result = srv_phb_dup_tcard_info_field(dest_id, src_id);
        }
        #endif
        g_srv_phb_phone_cache.phone_mask[dest_id].field_mask = srv_phb_datamgr_get_field_mask(src_id);
        srv_phb_commit_phone_fields_mask(dest_id);
    }
    
    status->result = result;
    status->id = dest_id;
    srv_phb_async_event_interface(srv_phb_op_phone_contact_done, status);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_add_type
 * DESCRIPTION
 *  add a new type
 * PARAMETERS
 *  type_info          :   [IN]    type info
 * RETURNS
 *  S32
 * RETURN VALUES
 *  >=0                 :           type id
 *  -1                  :           error
 *****************************************************************************/
S32 srv_phb_phone_add_type(WCHAR* type_label, mmi_phb_contact_field_id_enum field)
{
#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 type_id;
    S32 new_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!type_label || !type_label[0])
    {
        return -1;
    }
    
    if ((new_index = srv_phb_phone_get_empty_label_index(field)) < 0)
    {
        return -1;
    }
    
    if (field == MMI_PHB_CONTACT_FIELD_ID_NUMBER)
    {
        type_id = (U8)(new_index + MMI_PHB_NUM_TYPE_USER_BASE);
    }
    else if (field == MMI_PHB_CONTACT_FIELD_ID_EMAIL)
    {
        type_id = (U8)(new_index - MMI_PHB_FIELD_LABEL_COUNT + MMI_PHB_EMAIL_TYPE_USER_BASE);
    }
    else
    {
        return -1;
    }
    if (srv_phb_phone_insert_label_index(type_label, (U8)new_index))
    {
        mmi_wcsncpy(g_srv_phb_phone_cache.label[new_index], type_label, MMI_PHB_FIELD_LABEL_LENGTH);
        srv_phb_write_phone_label(new_index);
        return type_id;
    }
#endif /* __MMI_PHB_CUSTOM_FIELD_TYPE__ */
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_type
 * DESCRIPTION
 *  delete a type
 * PARAMETERS
 *  type_id            :   [IN]    type id
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_phb_phone_delete_type(U8 type_id, mmi_phb_contact_field_id_enum field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
    if (field == MMI_PHB_CONTACT_FIELD_ID_NUMBER)
    {
        if (type_id < MMI_PHB_NUM_TYPE_USER_BASE  || type_id >= (MMI_PHB_NUM_TYPE_USER_BASE + MMI_PHB_FIELD_LABEL_COUNT))
        {
            return MMI_FALSE;
        }
        type_id -= MMI_PHB_NUM_TYPE_USER_BASE;
    }
    else if (field == MMI_PHB_CONTACT_FIELD_ID_EMAIL)
    {
        if (type_id < MMI_PHB_EMAIL_TYPE_USER_BASE  || type_id >= (MMI_PHB_EMAIL_TYPE_USER_BASE + MMI_PHB_FIELD_LABEL_COUNT))
        {
            return MMI_FALSE;
        }
        type_id = type_id - MMI_PHB_EMAIL_TYPE_USER_BASE + MMI_PHB_FIELD_LABEL_COUNT;
    }
    else
    {
        return MMI_FALSE;
    }
    if (g_srv_phb_phone_cache.label[type_id][0])
    {
        g_srv_phb_phone_cache.label[type_id][0] = 0;
        srv_phb_write_phone_label((U16)type_id);
        srv_phb_phone_delete_label_index(type_id);
        return MMI_TRUE;
    }
#endif /* __MMI_PHB_CUSTOM_FIELD_TYPE__ */
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_get_type_list
 * DESCRIPTION
 *  get type id list ordered by type name
 * PARAMETERS
 *  type_array         :   [OUT]   type id array
 * RETURNS
 *  U8
 * RETURN VALUES
 *  count               :           type count
 ****************************************************************************/
U8 srv_phb_phone_get_type_list(U8* type_array, mmi_phb_contact_field_id_enum field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (field == MMI_PHB_CONTACT_FIELD_ID_NUMBER)
    {
        for (i = 0; i < MMI_PHB_NUM_TYPE_FAX; i++)
        {
            *type_array++ = i + 1;
        }
    #ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
        memcpy(type_array, g_srv_phb_phone_cache.label_index, g_srv_phb_phone_cache.number_label_count);
        return g_srv_phb_phone_cache.number_label_count + MMI_PHB_NUM_TYPE_FAX;
    #else
        return MMI_PHB_NUM_TYPE_FAX;
    #endif
    }
    else if (field == MMI_PHB_CONTACT_FIELD_ID_EMAIL)
    {
        for (i = 0; i < MMI_PHB_EMAIL_TYPE_OFFICE; i++)
        {
            *type_array++ = i + 1;
        }
    #ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
        memcpy(
            type_array,
            g_srv_phb_phone_cache.label_index + MMI_PHB_FIELD_LABEL_COUNT,
            g_srv_phb_phone_cache.email_label_count);
        return g_srv_phb_phone_cache.email_label_count + MMI_PHB_EMAIL_TYPE_OFFICE;
    #else
        return MMI_PHB_EMAIL_TYPE_OFFICE;
    #endif
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_get_type_label
 * DESCRIPTION
 *  get a type label by id
 * PARAMETERS
 *  type_id            :   [IN]    type id
 *  field              :   [IN]    field
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
WCHAR* srv_phb_phone_get_type_label(U8 type_id, mmi_phb_contact_field_id_enum field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (field == MMI_PHB_CONTACT_FIELD_ID_NUMBER)
    {
        switch (type_id)
        {
            case MMI_PHB_NUM_TYPE_NONE:
                return NULL;
                
            case MMI_PHB_NUM_TYPE_MOBILE:
                return (WCHAR*)GetString(STR_ID_PHB_MOBILE_NUMBER);
                
            case MMI_PHB_NUM_TYPE_HOME:
                return (WCHAR*)GetString(STR_HOME_NUMBER);
                
            case MMI_PHB_NUM_TYPE_OFFICE:
                return (WCHAR*)GetString(STR_OFFICE_NUMBER);
                
            case MMI_PHB_NUM_TYPE_FAX:
                return (WCHAR*)GetString(STR_FAX_NUMBER);
                
            default:
                break;
        }
        if (type_id >= (MMI_PHB_FIELD_LABEL_COUNT + MMI_PHB_NUM_TYPE_USER_BASE))
        {
            return NULL;
        }
        type_id -= MMI_PHB_NUM_TYPE_USER_BASE;
    }
    else if (field == MMI_PHB_CONTACT_FIELD_ID_EMAIL)
    {
        switch (type_id)
        {
            case MMI_PHB_EMAIL_TYPE_NONE:
                return NULL;
                
            case MMI_PHB_EMAIL_TYPE_HOME:
                return (WCHAR*)GetString(STR_HOME_NUMBER);
                
            case MMI_PHB_EMAIL_TYPE_OFFICE:
                return (WCHAR*)GetString(STR_OFFICE_NUMBER);
                
            default:
                break;
        }
        if (type_id >= (MMI_PHB_FIELD_LABEL_COUNT + MMI_PHB_EMAIL_TYPE_USER_BASE))
        {
            return NULL;
        }
        type_id = type_id - MMI_PHB_EMAIL_TYPE_USER_BASE + MMI_PHB_FIELD_LABEL_COUNT;
    }
    else
    {
        return NULL;
    }
#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
    return (WCHAR*)(g_srv_phb_phone_cache.label[type_id]);
#else
    return NULL;
#endif /* __MMI_PHB_CUSTOM_FIELD_TYPE__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_update_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_phb_phone_update_type(U8 type_id, WCHAR* type_label, mmi_phb_contact_field_id_enum field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
    if (type_label || !type_label[0])
    {
        return -1;
    }
    if (field == MMI_PHB_CONTACT_FIELD_ID_NUMBER)
    {
        if (type_id < MMI_PHB_NUM_TYPE_USER_BASE  && type_id >= (MMI_PHB_NUM_TYPE_USER_BASE + MMI_PHB_FIELD_LABEL_COUNT))
        {
            return -1;
        }
        type_id -= MMI_PHB_NUM_TYPE_USER_BASE;
    }
    else if (field == MMI_PHB_CONTACT_FIELD_ID_EMAIL)
    {
        if (type_id < MMI_PHB_EMAIL_TYPE_USER_BASE  && type_id >= (MMI_PHB_EMAIL_TYPE_USER_BASE + MMI_PHB_FIELD_LABEL_COUNT));
        {
            return -1;
        }
        type_id = type_id - MMI_PHB_EMAIL_TYPE_USER_BASE + MMI_PHB_FIELD_LABEL_COUNT;
    }
    else
    {
        return -1;
    }
    mmi_wcsncpy(g_srv_phb_phone_cache.label[type_id], type_label, MMI_PHB_FIELD_LABEL_LENGTH);
    srv_phb_write_phone_label((U16)type_id);
    srv_phb_phone_delete_label_index(type_id);
    srv_phb_phone_insert_label_index(type_label, type_id);
#endif /* __MMI_PHB_CUSTOM_FIELD_TYPE__ */
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_get_type_max
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_phb_phone_get_type_max(mmi_phb_contact_field_id_enum field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PHB_CUSTOM_FIELD_TYPE__
    if (field == MMI_PHB_CONTACT_FIELD_ID_NUMBER)
    {
        return MMI_PHB_NUM_TYPE_USER_BASE + MMI_PHB_FIELD_LABEL_COUNT - 1;
    }
    else if (field == MMI_PHB_CONTACT_FIELD_ID_EMAIL)
    {
        return MMI_PHB_EMAIL_TYPE_USER_BASE + MMI_PHB_FIELD_LABEL_COUNT - 1;
    }
#endif /* __MMI_PHB_CUSTOM_FIELD_TYPE__ */
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_get_sim_imsi
 * DESCRIPTION
 *  get sim imsi by sim id
 * PARAMETERS
 *  sim_id      : [IN] sim index
 *  imsi         : [OUT] imsi
 *  len           : [IN] imsi length SRV_MAX_IMSI_LEN
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_phone_get_sim_imsi(U8 sim_id, CHAR *imsi, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __COSMOS_MMI_PACKAGE__
    S16 pError;
    #endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __COSMOS_MMI_PACKAGE__
    ReadRecord(
        NVRAM_EF_PHB_SIM_IMSI_LID,
        sim_id + 1,
        imsi,
        len,
        &pError);
    #else
    memset(imsi, 0x00, len * sizeof(CHAR));
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_set_sim_imsi
 * DESCRIPTION
 *  set sim imsi by sim id
 * PARAMETERS
 *  sim_id      : [IN] sim index
 *  imsi         : [IN] imsi
 *  len           : [IN] imsi length SRV_MAX_IMSI_LEN
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_phone_set_sim_imsi(U8 sim_id, CHAR *imsi, U16 len)
{
    #ifdef __COSMOS_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 pError;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    WriteRecord(
        NVRAM_EF_PHB_SIM_IMSI_LID,
        sim_id + 1,
        imsi,
        len,
        &pError);
    #endif
}

