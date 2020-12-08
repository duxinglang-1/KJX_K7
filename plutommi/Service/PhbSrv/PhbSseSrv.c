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
 *  PhbSseSrv.c
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef PHBSSESRV_C
#define PHBSSESRV_C


/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_include.h"
#include "PhbSrvGprot.h"
#include "PhbSrv.h"
#include <ctype.h>      /* isdigit, isspace */
#include "FileMgrSrvGprot.h"
#include "MMIDataType.h"
#include "nvram_common_defs.h"
#include "custom_phb_config.h"
#include "wgui_categories_list.h"
#include "kal_general_types.h"
#include "MMI_features.h"
#include "gui.h"
#include "Gsm7BitNationalLang.h"
#include "Unicodexdcl.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_common_app_trc.h"
#include "mmi_frm_nvram_gprot.h"
#include "nvram_data_items.h"
#include "string.h"
#include "PhbSrvIprot.h"
#include "ps_public_enum.h"
#include "kal_public_api.h"
#include "stdlib.h"
#include "CallLogSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "ImeGprot.h"
#include "GlobalConstants.h"
#include "PhbOPSrv.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGprot.h"
#endif


#define SRV_PHB_SORT_LENGTH                     (10)
#define SRV_PHB_NUM_CACHE_LEN                   (8)

#define SRV_PHB_NUMBER_COUNT (MMI_PHB_TOTAL_SIM_ENTRIES * MMI_PHB_SIM_NUM_COUNT + MMI_PHB_NUMBER_FIELD_COUNT * (MMI_PHB_PHONE_ENTRIES + MMI_PHB_TCARD_ENTRIES))


typedef struct
{
    mmi_phb_contact_id id;
    FuncPtr cb;
} srv_phb_sse_sort_number_cntx;


typedef struct
{
    U16 word[MMI_PHB_ENTRIES];           /* first word */
    U16 input_mode;                            /* input mode */
} srv_phb_sse_qsearch_cache_struct;


typedef struct
{
    U16 ori_char;                               /* original char */
    U16 convert[MMI_PHB_QSEARCH_LENGTH];        /* converted string */
    U16 len;
} srv_phb_sse_qsearch_convert_struct;


typedef struct
{
    srv_phb_lookup_number_node_struct number_node[SRV_PHB_NUMBER_COUNT];
    MMI_BOOL number_ready;
    MMI_BOOL cancel_sorting;
    U8  number_compare_length;
    U16 number_count;
    U16 entry_count;
    U16 fdn_count;
    mmi_phb_contact_id name_index[MMI_PHB_ENTRIES + MMI_PHB_FDN_TOTAL_ENTRIES];
    #if defined(__MMI_PHB_PINYIN_SORT__)
    U16 pinyin_cache[MMI_PHB_ENTRIES + MMI_PHB_FDN_TOTAL_ENTRIES][(SRV_PHB_SORT_LENGTH + 1)];
    #endif
#if defined(__MMI_PHB_QUICK_SEARCH__)
    srv_phb_sse_qsearch_cache_struct* q_cache;
#endif
    U8 num_cache[MMI_PHB_PHONE_ENTRIES * MMI_PHB_NUMBER_FIELD_COUNT][(SRV_PHB_NUM_CACHE_LEN + 1) / 2]; /* bcd num cache */
    U16* alpha_table;
} srv_phb_sse_cntx_struct;

typedef struct
{
    U16* ime_table;
    WCHAR* keymap[10];                        //key 0-9 map char
    U16 keysize[10];                        //key 0-9 map char size
} srv_phb_ds_key_info_struct;


typedef struct
{
    U32 pid;
    srv_phb_query_req_struct *req;
    srv_phb_query_struct *handle;
    void *user_data;
} srv_phb_sse_query_async_struct;


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
/* Define your local variable here */

static srv_phb_sse_cntx_struct g_srv_phb_sse_cntx;


/* Declare your local function here */


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/


/***************************************************************************** 
 * Local Function
 *****************************************************************************/

#if defined(__MMI_PHB_PINYIN_SORT__)
/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_make_pinyin_cache
 * DESCRIPTION
 *  make pinyin cache for name sort
 * PARAMETERS
 *  store_index     : [IN]  contact's store_index
 *  name            : [IN]  contact's name
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sse_make_pinyin_cache(mmi_phb_contact_id id, U16* name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name && srv_phb_check_ucs2_character(name))
    {
        count = srv_phb_convert_to_pinyin(
                    name,
                    &g_srv_phb_sse_cntx.pinyin_cache[id][0],
                    SRV_PHB_SORT_LENGTH);
        g_srv_phb_sse_cntx.pinyin_cache[id][count++] = 0;
    }
    else
    {
        g_srv_phb_sse_cntx.pinyin_cache[id][0] = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_get_first_pinyin_char
 * DESCRIPTION
 *  get a contact's first pinyin char
 * PARAMETERS
 *  store_index     : [IN]      contact's store_index
 * RETURNS
 *  first_char
 *****************************************************************************/
static U16 srv_phb_sse_get_first_pinyin_char(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_phb_sse_cntx.pinyin_cache[id][0];
}
#endif /* defined(__MMI_PHB_PINYIN_SORT__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_compare_name_index
 * DESCRIPTION
 *  Compare two phonebook by name string. If name is empty use number instead.
 * PARAMETERS
 *  first           :[IN]            Store_index of first compare element
 *  second          :[IN]            Store_index of second compare element
 *  distance        :[OUT]           Difference of two element
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sse_compare_name_index(U16 first, U16 second, S32 *distance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 buffer1[MMI_PHB_NAME_LENGTH + 1];
    U16 buffer2[MMI_PHB_NAME_LENGTH + 1];
    U16* string1;
    U16* string2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_PINYIN_SORT__)
    if (g_srv_phb_sse_cntx.pinyin_cache[first][0] != 0)
    {
        string1 = g_srv_phb_sse_cntx.pinyin_cache[first];
    }
    else
#endif
    {
        srv_phb_datamgr_get_name(first, buffer1, MMI_PHB_NAME_LENGTH);
        string1 = buffer1;
    }

#if defined(__MMI_PHB_PINYIN_SORT__)
    if (g_srv_phb_sse_cntx.pinyin_cache[second][0] != 0)
    {
        string2 = g_srv_phb_sse_cntx.pinyin_cache[second];
    }
    else
#endif
    {
        srv_phb_datamgr_get_name(second, buffer2, MMI_PHB_NAME_LENGTH);
        string2 = buffer2;
    }

#ifndef __MMI_PHB_EMPTY_NAME_TOP__
    /* if name empty */
    if (!string1[0])
    {
        string1[0] = 0x7B;
        string1[1] = 0;
    }

    /* if name empty */
    if (!string2[0])
    {
        string2[0] = 0x7B;
        string2[1] = 0;
    }
#endif

    /* Compare two strings */
#if defined(__MMI_PHB_PINYIN_SORT__)
    *distance = srv_phb_compare_pinyin_string(string1, string2);
#else
    *distance = srv_phb_compare_ucs2_string(string1, string2);
#endif
    if (*distance == 0)
    {
        *distance = mmi_wcscmp(string1, string2);
    }

    /* sort according storage location, let entry in NVRAM put before in SIM. (store_index can decide store location) */
    if (*distance == 0)
    {
        if (first < second)
        {
            *distance = -1;
        }
        else if (first > second)
        {
            *distance = 1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_name_swap
 * DESCRIPTION
 *  swap two index for name sort
 * PARAMETERS
 *  a       : [IN]        index a
 *  b       : [IN]        index b
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sse_name_swap(U16 a, U16 b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tmp = g_srv_phb_sse_cntx.name_index[a];
    g_srv_phb_sse_cntx.name_index[a] = g_srv_phb_sse_cntx.name_index[b];
    g_srv_phb_sse_cntx.name_index[b] = tmp;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_name_quicksort
 * DESCRIPTION
 *  name quick sort when phonebook init
 * PARAMETERS
 *  left        : [IN]            left index
 *  right       : [IN]            right index
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sse_name_quicksort(U16 left, U16 right)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 const Min = 4;  /* Lower bound to sort */
    U16 i;
    U16 j;
    U16 pivot;
    S32 distance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((right - left) > Min)
    {
        i = (right + left) / 2;

        /* left > mid */
        srv_phb_sse_compare_name_index(g_srv_phb_sse_cntx.name_index[left], g_srv_phb_sse_cntx.name_index[i], &distance);
        if (distance > 0)
        {
            srv_phb_sse_name_swap(left, i);
        }

        /* left > right */
        srv_phb_sse_compare_name_index(g_srv_phb_sse_cntx.name_index[left], g_srv_phb_sse_cntx.name_index[right], &distance);
        if (distance > 0)
        {
            srv_phb_sse_name_swap(left, right);
        }

        /* mid > right */
        srv_phb_sse_compare_name_index(g_srv_phb_sse_cntx.name_index[i], g_srv_phb_sse_cntx.name_index[right], &distance);
        if (distance > 0)
        {
            srv_phb_sse_name_swap(i, right);
        }

        j = right - 1;
        srv_phb_sse_name_swap(i, j);

        i = left;

        pivot = g_srv_phb_sse_cntx.name_index[j];    /* kal_mem_cpy(&v, (void const*)&a[j], sizeof(pindex_struct)); */

        for (;;)
        {
            do  /* ++i < pivot */
            {
                srv_phb_sse_compare_name_index(g_srv_phb_sse_cntx.name_index[++i], pivot, &distance);
            }
            while (distance < 0);

            do  /* --j > pivot */
            {
                srv_phb_sse_compare_name_index(g_srv_phb_sse_cntx.name_index[--j], pivot, &distance);
            }
            while (distance > 0);

            if (j < i)
            {
                break;
            }

            srv_phb_sse_name_swap(i, j);
        }

        srv_phb_sse_name_swap(i, (U16) (right - 1));
        srv_phb_sse_name_quicksort(left, j);
        srv_phb_sse_name_quicksort((U16)(i + 1), right);
    }
}   /* end of phb_quicksort */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_name_insertionsort
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  low         : [IN]         low index
 *  high        : [IN]         high index
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sse_name_insertionsort(U16 low, U16 high)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 j;
    U16 pivot;
    S32 distance;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = low + 1; i <= high; ++i)
    {
        pivot = g_srv_phb_sse_cntx.name_index[i];

        j = i;
        while (j > low)
        {
            srv_phb_sse_compare_name_index(g_srv_phb_sse_cntx.name_index[j - 1], pivot, &distance);
            if (distance <= 0)
            {
                break;
            }

            g_srv_phb_sse_cntx.name_index[j] = g_srv_phb_sse_cntx.name_index[j - 1];

            j--;
        }

        g_srv_phb_sse_cntx.name_index[j] = pivot;
    }
}   /* end of phb_insertion_sort */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_get_name_pos
 * DESCRIPTION
 *  get a name's pos in name index array
 * PARAMETERS
 *  low             : [IN]            low index
 *  high            : [IN]            high index
 *  src_name        : [IN]            name to inset
 *  in_id           : [IN]            store_index of the name
 * RETURNS
 *  pos
 *****************************************************************************/
static U16 srv_phb_sse_get_name_pos(S32 low, S32 high, U16* src_name, mmi_phb_contact_id in_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 mid = low;
    S32 distance = 0;
    mmi_phb_contact_id id;
    U16 out_index;
    U16* dest_name;
    U16* string;
#ifdef __MMI_PHB_EMPTY_NAME_TOP__
    U16 empty_name[2] = {0, 0};
#else
    U16 empty_name[2] = {0x7B, 0};
#endif
#if defined(__MMI_PHB_PINYIN_SORT__)
    U16 buffer[SRV_PHB_PINYIN_LEN + 1];
    U16 count;
#endif /* defined(__MMI_PHB_PINYIN_SORT__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!src_name || !src_name[0])
    {
        src_name = empty_name;
    }
#if defined(__MMI_PHB_PINYIN_SORT__)
    if (srv_phb_check_ucs2_character(src_name))
    {
        count = srv_phb_convert_to_pinyin(src_name, buffer, SRV_PHB_PINYIN_LEN);
        buffer[count++] = 0x00;
        src_name = buffer;
    }
#endif /* defined(__MMI_PHB_PINYIN_SORT__) */
    dest_name = srv_phb_mem_malloc((MMI_PHB_NAME_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_CTR);
    /*
     * Use binary search to find nearest name.
     */
    while (low <= high)
    {
        mid = (low + high) / 2;

        /*
         * Prepare entry data to compare
         */
        id = g_srv_phb_sse_cntx.name_index[mid];
        srv_phb_datamgr_get_name(id, dest_name, MMI_PHB_NAME_LENGTH);
    #if defined(__MMI_PHB_PINYIN_SORT__)
        if (srv_phb_check_ucs2_character(dest_name))
        {
            string = g_srv_phb_sse_cntx.pinyin_cache[id];
        }
        else
    #endif /* defined(__MMI_PHB_PINYIN_SORT__) */ 
        {
            string = dest_name;
        }

    #ifndef __MMI_PHB_EMPTY_NAME_TOP__
        /* if name empty */
        if (!string[0])
        {
            string[0] = 0x7B;
            string[1] = 0;
        }
    #endif

        /*
         * Compare search pattern with entry
         */
    #if defined(__MMI_PHB_PINYIN_SORT__)
        distance = srv_phb_compare_pinyin_string(src_name, string);
    #else
        distance = srv_phb_compare_ucs2_string(src_name, string);
    #endif
        if (distance == 0)
        {
            distance = mmi_wcscmp(src_name, string);
        }

        if (distance == 0)
        {
            if (in_id > id)
            {
                distance = 1;
            }
            else
            {
                distance = -1;
            }
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
        out_index = mid + 1;
    }
    else
    {
        out_index = mid;
    }
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_INSERT_NAME, out_index);
    srv_phb_mem_free(dest_name);
    return out_index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_binary_search_name
 * DESCRIPTION
 *  search a name in phonebook
 * PARAMETERS
 *  low             : [IN]            low index
 *  high            : [IN]            high inex
 *  src_name        : [IN]            name to search
 *  out_index       : [OUT]           matched contact's store_index
 * RETURNS
 *  S32
 * RETURN VALUES
 *  SRV_PHB_NOT_FOUND          :                    not found
 *  SRV_PHB_NO_ERROR           :                    found
 *****************************************************************************/
static S32 srv_phb_sse_binary_search_name(S32 low, S32 high, U16* src_name, U16* out_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 mid = 0;
    S32 distance = 0;
    mmi_phb_contact_id id;
    WCHAR* dest_name;
    WCHAR* string;
#if defined(__MMI_PHB_PINYIN_SORT__)
    U16 buffer[SRV_PHB_PINYIN_LEN + 1];
    U16 count;
#endif /* defined(__MMI_PHB_PINYIN_SORT__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!src_name[0])
    {
        return SRV_PHB_NOT_FOUND;
    }
#if defined(__MMI_PHB_PINYIN_SORT__)
    if (srv_phb_check_ucs2_character(src_name))
    {
        count = srv_phb_convert_to_pinyin(src_name, buffer, SRV_PHB_PINYIN_LEN);
        buffer[count++] = 0x00;
        src_name = buffer;
    }
#endif /* defined(__MMI_PHB_PINYIN_SORT__) */
    dest_name = srv_phb_mem_malloc((MMI_PHB_NAME_LENGTH + 1) * sizeof(WCHAR), SRV_PHB_MEMORY_TYPE_CTR);
    /*
     * Use binary search to find nearest name.
     */
    while (low <= high)
    {
        mid = (low + high) / 2;

        /*
         * Prepare entry data to compare
         */
        id = g_srv_phb_sse_cntx.name_index[mid];
        srv_phb_datamgr_get_name(id, dest_name, MMI_PHB_NAME_LENGTH);
    #if defined(__MMI_PHB_PINYIN_SORT__)
        if (srv_phb_check_ucs2_character(dest_name))
        {
            string = g_srv_phb_sse_cntx.pinyin_cache[id];
        }
        else
    #endif /* defined(__MMI_PHB_PINYIN_SORT__) */ 
        {
            string = dest_name;
        }

        /* if name empty */
        if (!string[0])
        {
            high = mid - 1;
            continue;
        }

        /*
         * Compare search pattern with entry
         */
    #if defined(__MMI_PHB_PINYIN_SORT__)
        distance = srv_phb_compare_pinyin_string(src_name, string);
    #else
        distance = srv_phb_compare_ucs2_string(src_name, string);
    #endif

        if (distance == 0)
        {
            *out_index = mid;
            srv_phb_mem_free(dest_name);
            MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_SEARCH_NAME, 1, *out_index);
            return SRV_PHB_NO_ERROR;
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
    srv_phb_mem_free(dest_name);
    return SRV_PHB_NOT_FOUND;
}

#if defined(__MMI_PHB_ADV_NUM_MATCH_MOBILE__)
/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_remove_number_prefix
 * DESCRIPTION
 *  remove number prefix
 * PARAMETERS
 *  number_in            : [IN] input number               
 * RETURNS
 *  number without prefix
 *****************************************************************************/
CHAR* srv_phb_sse_remove_number_prefix(CHAR* number_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ext_len;
    CHAR* temp_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_number = number_in;

    /* Ignore  *31# and #31# case */
    while (((temp_number[0] == '*') && (temp_number[1] == '3') && (temp_number[2] == '1') && (temp_number[3] == '#')) ||
           ((temp_number[0] == '#') && (temp_number[1] == '3') && (temp_number[2] == '1') && (temp_number[3] == '#')))
    {
        temp_number += 4;
    }

    /* Skip the first plus sign */
    if (temp_number[0] == '+')
    {
        temp_number++;
    }

    /* number empty */
    if (temp_number[0] == '\0')
    {
        return temp_number;
    }

    /* Find the position of extension number and remove that part */
    ext_len = strcspn(temp_number, "+pPwW*#");
    if (ext_len)
    {
        /* Read compare length from NVRAM */
        if (!g_srv_phb_sse_cntx.number_compare_length)
        {
            g_srv_phb_sse_cntx.number_compare_length = srv_phb_read_compare_length();
        }

        /* Convert at most 9 digits integer */
        if (ext_len > g_srv_phb_sse_cntx.number_compare_length)
        {
            temp_number += ext_len - g_srv_phb_sse_cntx.number_compare_length;
        }
    }
    return temp_number;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_compare_number
 * DESCRIPTION
 *  compare two number
 * PARAMETERS
 *  number1        :   [IN]      number to search
 *  number2        :   [IN]      number from phonebook            
 * RETURNS
 *  S32
 * RETURN VALUES
 *  SRV_PHB_NO_ERROR           :    number is same
 *  SRV_PHB_ERROR              :    number not same
 *  SRV_PHB_HALF_MARTCHED      :    the same mean with SRV_PHB_ERROR for other app, 
                                    mean half martched for lookup number search
 *****************************************************************************/
S32 srv_phb_sse_compare_number(CHAR* number1, CHAR* number2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = SRV_PHB_HALF_MARTCHED;
    CHAR char1, char2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*number1 && *number2)
    {
        if (*number1 == 'P')
        {
            char1 = 'p';
        }
        else if (*number1 == 'W')
        {
            char1 = 'w';
        }
        else
        {
            char1 = *number1;
        }
        if (*number2 == 'P')
        {
            char2 = 'p';
        }
        else if (*number2 == 'W')
        {
            char2 = 'w';
        }
        else
        {
            char2 = *number2;
        }
        if (char1 != char2)
        {
            return SRV_PHB_ERROR;
        }
        if (char2 == '+' || char2 == 'p' || char2 == 'w' || char2 == '*' || char2 == '#')
        {
            result = SRV_PHB_ERROR;
        }
        number1++;
        number2++;
    }
    if (*number1 == 'P' || *number1 == 'p' || *number1 == 'w' || *number1 == 'W')
    {
        return result;
    }
    if (*number1 || *number2)
    {
        return SRV_PHB_ERROR;
    }
    return SRV_PHB_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_adv_number_compare
 * DESCRIPTION
 *  compare two number
 * PARAMETERS
 *  dest_store_index       :    [IN]  dest contact's store_inde        
 *  src_number             :    [IN]  src number       
 *  dest_number            :    [OUT] matched number  
 *  dest_type              :    [OUT] matched number type
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE            :                    matched or half matched
 *  MMI_FALSE           :                    not matched
 *****************************************************************************/
static MMI_BOOL srv_phb_sse_adv_number_compare(mmi_phb_contact_id dest_id, CHAR* src_number, CHAR* dest_number, U32* dest_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* number1; 
    CHAR* number2;
    CHAR* tmp;
    S32 result;
    U32 count;
    U8 i;
    mmi_phb_optional_fields_struct *optional_fields = NULL;
    phb_storage_enum storage = (phb_storage_enum)(srv_phb_get_storage(dest_id));
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    number1 = srv_phb_sse_remove_number_prefix(src_number);
    if (storage == PHB_STORAGE_NVRAM)
    {
        count = MMI_PHB_NUMBER_FIELD_COUNT;
        optional_fields = srv_phb_get_phone_optional_field(dest_id);
    }
    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    else if (storage == PHB_STORAGE_TCARD)
    {
        count = MMI_PHB_NUMBER_FIELD_COUNT;
    }
    #endif
    else
    {
        count = srv_phb_get_sim_support_field_count(storage, MMI_PHB_CONTACT_FIELD_ID_NUMBER);
    }
    for (i = 0; i < count; i++)
    {
        if (storage == PHB_STORAGE_NVRAM)
        {
            tmp = (CHAR*)(optional_fields->num[i].number);
        }
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        else if (storage == PHB_STORAGE_TCARD)
        {
            tmp = srv_phb_get_tcard_number(dest_id, i, NULL, NULL, NULL);
        }
        #endif
        else
        {
            tmp = srv_phb_get_sim_number(dest_id, i, NULL);
        }        
        if (tmp[0])
        {
            number2 = srv_phb_sse_remove_number_prefix(tmp);
            result = srv_phb_sse_compare_number(number1, number2);
            if (result == SRV_PHB_NO_ERROR)
            {
                *dest_index = i;
                return MMI_TRUE;
            }
            else if (result == SRV_PHB_HALF_MARTCHED && *dest_number == 0)
            {
                *dest_index = i;
                strcpy(dest_number, tmp);
            }
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_adv_number_search
 * DESCRIPTION
 *  advance number search
 * PARAMETERS
 *  mid             : [IN]     search begin index
 *  number          : [IN]     number to search(convert result)
 *  number_in       : [IN]     number to search(ascii)
 *  number_type     : [OUT]    matched number's type
 * RETURNS
 *  S32
 * RETURN VALUES
 *  -1                  :                    not found
 *  >=0                 :                    matched number's index
 *****************************************************************************/
static S32 srv_phb_sse_adv_number_search(S32 mid, U32 number, CHAR *number_in, U32* number_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i, new_mid, min_index, counter;
    CHAR number_list[MMI_PHB_NUMBER_PLUS_LENGTH + 1] = {0};
    U16 j;
    srv_phb_lookup_number_node_struct* node = g_srv_phb_sse_cntx.number_node;
    U32 tmp_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_mid = mid;
    min_index = MMI_PHB_ENTRIES;
    counter = 0;

    /* Compare number before mid */
    i = mid;
    while ((i >= 0) && (node[i].number == number))
    {
        if (srv_phb_sse_adv_number_compare(node[i].id, number_in, number_list, &tmp_index))
        {
            for (j = 0; j < g_srv_phb_sse_cntx.entry_count; j++)
            {
                if (g_srv_phb_sse_cntx.name_index[j] == node[i].id)
                {
                    break;
                }
            }
            if (j < min_index)
            {
                if (number_index)
                {
                     *number_index = tmp_index;
                }
                min_index = j;
                new_mid = i;
            }
        }
        i--;
        counter++;
        if (counter >= SRV_PHB_NUM_ADV_COMP_COUNT)
        {
            break;
        }
    }

    /* Compare number after mid */
    i = mid + 1;
    while ((i < g_srv_phb_sse_cntx.number_count) && (g_srv_phb_sse_cntx.number_node[i].number == number))
    {
        if (srv_phb_sse_adv_number_compare(node[i].id, number_in, number_list, &tmp_index))
        {
            for (j = 0; j < g_srv_phb_sse_cntx.entry_count; j++)
            {
                if (g_srv_phb_sse_cntx.name_index[j] == node[i].id)
                {
                    break;
                }
            }
            if (j < min_index)
            {
                if (number_index)
                {
                    *number_index = tmp_index;
                }
                min_index = j;
                new_mid = i;
            }
        }
        i++;
        counter++;
        if (counter >= SRV_PHB_NUM_ADV_COMP_COUNT)
        {
            break;
        }
    }

    if (min_index == MMI_PHB_ENTRIES)
    {
        if ((counter <= 1) && *number_list)
        {
            return mid;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return new_mid;
    }
}
#endif /* defined(__MMI_PHB_ADV_NUM_MATCH_MOBILE__) */ 


/*****************************************************************************
* FUNCTION
*  srv_phb_sse_populate_number
* DESCRIPTION
*  populate a number to lookup table
* PARAMETERS
*  store_index     : [IN]        number's store_index
*  number          : [IN]        number
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_sse_populate_number(mmi_phb_contact_id id, CHAR* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number != NULL)
    {
        U32 temp = srv_phb_sse_convert_number_to_int(number);
        if (temp < SRV_PHB_INVALID_NUMBER && g_srv_phb_sse_cntx.number_count < SRV_PHB_NUMBER_COUNT)
        {
            g_srv_phb_sse_cntx.number_node[g_srv_phb_sse_cntx.number_count].id = id;
            g_srv_phb_sse_cntx.number_node[g_srv_phb_sse_cntx.number_count].number = temp;
            g_srv_phb_sse_cntx.number_count++;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_lookup_table_swap_node
 * DESCRIPTION
 *  Swaps the look-up table nodes
 * PARAMETERS
 *  i       : [IN]         index i
 *  j       : [IN]         index j
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sse_lookup_table_swap_node(U16 i, U16 j)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_lookup_number_node_struct temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&temp, &g_srv_phb_sse_cntx.number_node[i], sizeof(srv_phb_lookup_number_node_struct));
    memcpy(&g_srv_phb_sse_cntx.number_node[i], &g_srv_phb_sse_cntx.number_node[j], sizeof(srv_phb_lookup_number_node_struct));
    memcpy(&g_srv_phb_sse_cntx.number_node[j], &temp, sizeof(srv_phb_lookup_number_node_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_lookup_table_quicksort
 * DESCRIPTION
 *  Sorts the lookup table using quick sort algorithm
 * PARAMETERS
 *  l      : [IN]        left index
 *  r      : [IN]        right index
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sse_lookup_table_quicksort(U16 l, U16 r)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    U32 pivot;
    srv_phb_lookup_number_node_struct* node = g_srv_phb_sse_cntx.number_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((r - l) > 4)
    {
        i = (r + l) / 2;
        if (node[l].number > node[i].number)
        {
            srv_phb_sse_lookup_table_swap_node(l, i);
        }
        if (node[l].number > node[r].number)
        {
            srv_phb_sse_lookup_table_swap_node(l, r);
        }
        if (node[i].number > node[r].number)
        {
            srv_phb_sse_lookup_table_swap_node(i, r);
        }

        j = r - 1;
        srv_phb_sse_lookup_table_swap_node(i, j);
        i = l;
        pivot = node[j].number;

        for (;;)
        {
            do
            {
            } while (node[++i].number < pivot);
            do
            {
            } while (node[--j].number > pivot);

            if (j < i)
            {
                break;
            }

            srv_phb_sse_lookup_table_swap_node(i, j);
        }

        srv_phb_sse_lookup_table_swap_node(i, (U16)(r - 1));
        srv_phb_sse_lookup_table_quicksort(l, j);
        srv_phb_sse_lookup_table_quicksort((U16)(i + 1), r);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_lookup_table_insertionsort
 * DESCRIPTION
 *  Sorts the lookup table using insertion sort algorithm
 * PARAMETERS
 *  lo      : [IN]        low index
 *  hi      : [IN]        high index      
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sse_lookup_table_insertionsort(U16 lo, U16 hi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    srv_phb_lookup_number_node_struct* node = g_srv_phb_sse_cntx.number_node;
    srv_phb_lookup_number_node_struct temp;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = lo + 1; i <= hi; ++i)
    {
        memcpy(&temp, &node[i], sizeof(srv_phb_lookup_number_node_struct));

        j = i;
        while (j > lo)
        {
            if (node[j - 1].number <= temp.number)
            {
                break;
            }
            memcpy(&node[j], &node[j - 1], sizeof(srv_phb_lookup_number_node_struct));
            j--;
        }
        memcpy(&node[j], &temp, sizeof(srv_phb_lookup_number_node_struct));
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_lookup_table_sort
 * DESCRIPTION
 *  Sorts the look-up table
 *  
 *  This is a fast Quick-Sort as suggested by
 *  Pluto. It will perform insertion sort for
 *  array chunks of size less than 4 and quick
 *  sort for size greater than 4.
 * PARAMETERS
 *  cb   : [IN]   call back function to call after sort
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sse_lookup_table_sort(FuncPtr cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_NUMBER_SORT, g_srv_phb_sse_cntx.number_count);

    if (g_srv_phb_sse_cntx.number_count)
    {
        /* Begin to sort. */
        srv_phb_sse_lookup_table_quicksort(0, (U16)(g_srv_phb_sse_cntx.number_count - 1));
        srv_phb_sse_lookup_table_insertionsort(0, (U16)(g_srv_phb_sse_cntx.number_count - 1));
    }
    g_srv_phb_sse_cntx.number_ready = MMI_TRUE;
    cb();
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_read_numbers
 * DESCRIPTION
 *  This function populates the lookup table with home/fax/mobile/office numbers after
 *  converting the last 7(or 9) characters of the phone number into digits.
 * PARAMETERS
 *  info   : [IN]  number sort cntx
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sse_read_numbers(void* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_sse_sort_number_cntx* sort_cntx = info;
    mmi_phb_optional_fields_struct* optional_fields = srv_phb_get_phone_optional_field(sort_cntx->id);
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_sse_cntx.cancel_sorting)
    {
        return;
    }

    for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
    {
        srv_phb_sse_populate_number(sort_cntx->id, (CHAR*)optional_fields->num[i].number);
        srv_phb_sse_set_number_cache(sort_cntx->id, (CHAR*)optional_fields->num[i].number, i);
    }
    sort_cntx->id = srv_phb_get_next_phone_contact(++(sort_cntx->id), SRV_PHB_ENTRY_FIELD_OPTIONAL_NUM);

    if (sort_cntx->id != SRV_PHB_INVALID_INDEX) /* More entries to populate */
    {
        srv_phb_async_event_interface(srv_phb_sse_read_numbers, sort_cntx);
    }
    else    /* All entries populated, begin to sort it. */
    {
        srv_phb_sse_lookup_table_sort(sort_cntx->cb);
        srv_phb_mem_free(sort_cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_lookup_table_find_pos
 * DESCRIPTION
 *  find postion for insert a number to lookup table
 * PARAMETERS
 *  low             : [IN]   low index
 *  high            : [IN]   high index
 *  number          : [IN]   number to insert
 * RETURNS
 *  postion
 *****************************************************************************/
static U16 srv_phb_sse_lookup_table_find_pos(S32 low, S32 high, U32 number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 mid = low;
    srv_phb_lookup_number_node_struct* node = g_srv_phb_sse_cntx.number_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (number == node[mid].number)
        {
            return (U16)(mid + 1);
        }
        else if (number < node[mid].number)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (high < mid)
    {
        return (U16)mid;
    }
    else
    {
        return (U16)(mid + 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_lookup_table_add_num
 * DESCRIPTION
 *  add one number of a contact into lookup table
 * PARAMETERS
 *  store_index     : [IN]        number's store_index
 *  number          : [IN]        number after convert
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sse_lookup_table_add_num(mmi_phb_contact_id id, U32 number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pos;
    S32 i;
    srv_phb_lookup_number_node_struct* node = g_srv_phb_sse_cntx.number_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pos = srv_phb_sse_lookup_table_find_pos(0, (S32)(g_srv_phb_sse_cntx.number_count - 1), number);

    for (i = g_srv_phb_sse_cntx.number_count; i > pos; i--)
    {
        node[i].id = node[i - 1].id;
        node[i].number = node[i - 1].number;
    }
    node[pos].id = id;
    node[pos].number = number;

    g_srv_phb_sse_cntx.number_count++;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_normal_filter
 * DESCRIPTION
 *  filter a contact by storage & field
 * PARAMETERS
 *  store_index      : [IN]      contact's store_index
 *  storage          : [IN]      storage filter
 *  field_filter     : [IN]      field filter
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE                  :                    matched
 *  MMI_FALSE                 :                    not matched
 *****************************************************************************/
static MMI_BOOL srv_phb_sse_normal_filter(U16 store_index, U8 storage, U32 field_filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if ((storage == PHB_STORAGE_MAX || srv_phb_get_storage(store_index) == storage) &&
        (field_filter & srv_phb_datamgr_get_field_mask(store_index)))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_name_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE                  :                    matched
 *  MMI_FALSE                 :                    not matched
 *****************************************************************************/
static MMI_BOOL srv_phb_sse_name_filter(U16 store_index, srv_phb_name_filter_struct* name_filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 name[MMI_PHB_NAME_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    srv_phb_datamgr_get_name(store_index, name, MMI_PHB_NAME_LENGTH);
    if (srv_phb_compare_ucs2_string(name, name_filter->key_word) == 0)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


#ifdef __MMI_PHB_CALLER_GROUP__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_group_filter
 * DESCRIPTION
 *  filter a contact by group
 * PARAMETERS
 *  store_index      : [IN]      contact's store_index
 *  group_filter     : [IN]      group filter
 *  group_field      : [IN]      all contact's group field info
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE                  :                    matched
 *  MMI_FALSE                 :                    not matched
 *****************************************************************************/
static MMI_BOOL srv_phb_sse_group_filter(U16 store_index, phb_storage_enum storage, srv_phb_group_filter_struct* group_filter, U8* group_field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U32 grou_mask = 0;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (srv_phb_get_storage(store_index) != storage && storage != PHB_STORAGE_MAX)
    {
        return MMI_FALSE;
    }
    if (group_filter->is_equal)
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }
#ifdef __MMI_PHB_USIM_SUPPORT__
    if (storage >= PHB_STORAGE_SIM && storage <= PHB_STORAGE_SIM4)
    {
        U16 record_index, offset;
        U8 phb_storage;
        srv_phb_store_index_to_record_index(store_index, &phb_storage, &record_index);
        offset = (record_index - 1) * sizeof(srv_phb_sim_grp_struct);
        grou_mask = group_field[offset + 1];
        grou_mask = grou_mask << 8;
        grou_mask |= group_field[offset];
    }
    else
#endif /* __MMI_PHB_USIM_SUPPORT__ */
#ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    if (storage == PHB_STORAGE_TCARD)
    {
        U8 tmp_storage;
        U16 tmp_record_index;
        srv_phb_store_index_to_record_index(store_index, &tmp_storage, &tmp_record_index);
        grou_mask = ((U32 *)group_field)[tmp_record_index];
    }
    else
#endif /* __SRV_PHB_TCARD_STORAGE_SUPPORT__ */
    {        
        for (i = 0; i < MMI_PHB_GROUP_FIELD_SIZE && i < 4; i++)
        {
            grou_mask |= (group_field[store_index * MMI_PHB_GROUP_FIELD_SIZE + i] << (i * 8));
        }
    }
    if (grou_mask & group_filter->group_mask)
    {
        return result;
    }
    else
    {
        return (MMI_BOOL)(!result);
    }
}
#endif /* __MMI_PHB_CALLER_GROUP__ */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_bcd_num_cmp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_phb_bcd_num_cmp(U8* bcd_dest, WCHAR* dest, U32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U8 dest_int;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < length && dest[i]; i++)
    {
        dest_int = dest[i] - '0';
        if (i % 2)
        {
            if ((bcd_dest[i / 2] & 0x0F) != dest_int)
            {
                return MMI_FALSE;
            }
        }
        else if ((bcd_dest[i / 2] & 0xF0) != (dest_int << 4))
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


#if defined(__MMI_PHB_QUICK_SEARCH__)

/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_qsearch_filter
 * DESCRIPTION
 *  filter a contact by quick search filter
 * PARAMETERS
 *  store_index      : [IN]      contact's store_index
 *  qsearch_filter   : [IN]      quick search filter
 *  convert_buffer   : [IN]      name convert buffer         
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE                  :                    matched
 *  MMI_FALSE                 :                    not matched
 *****************************************************************************/
static MMI_BOOL srv_phb_sse_qsearch_filter(U16 store_index, srv_phb_qsearch_filter_struct* qsearch_filter, srv_phb_sse_qsearch_convert_struct* convert_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* string;
    U16 name[MMI_PHB_NAME_LENGTH + 1];
    U16 convert_string[MMI_PHB_QSEARCH_LENGTH  + 1];
    U16 first_char[MMI_PHB_QSEARCH_LENGTH + 1];
    S32 i, j;
    U16 key_length = (qsearch_filter->key_len > MMI_PHB_QSEARCH_LENGTH ? MMI_PHB_QSEARCH_LENGTH : qsearch_filter->key_len);
    U16* keyword = qsearch_filter->key_word;
    U16 cache = g_srv_phb_sse_cntx.q_cache->word[store_index];
    U16 left_len = key_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * search length == 1, compare whole list with first character only.
     */
    /*if (key_length == 1)
    {
        if (srv_phb_compare_wchar(cache, keyword[0]) == 0)
        {
            return MMI_TRUE;
        }
        #ifdef __OP01__
        for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
        {
            if (srv_phb_bcd_num_cmp(
                    g_srv_phb_sse_cntx.num_cache[MMI_PHB_NUMBER_FIELD_COUNT * store_index + i],
                    keyword,
                    1))
            {
                return MMI_TRUE;
            }
        }
        #endif
    }*/
    /*
     * search length > 1, compare subset list with maximum search character.
     else */
    if (key_length >= 1)
    {
        /* Compare character in cache first. If match, compare the rest part. */
        if (srv_phb_compare_wchar(cache, keyword[0]) == 0)
        {
            srv_phb_datamgr_get_name(store_index, name, MMI_PHB_NAME_LENGTH);
            if (srv_phb_check_ucs2_character(name))
            {
                string = convert_string;
                for (i = 0; i < key_length && name[i]; i++)
                {
                    if (name[i] != convert_buffer[i].ori_char)
                    {
                        convert_buffer[i].ori_char = name[i];
                        convert_buffer[i].len = srv_phb_convert_to_spelling(
                                                    qsearch_filter->input_mode,
                                                    name[i],
                                                    convert_buffer[i].convert,
                                                    MMI_PHB_QSEARCH_LENGTH);
                    }
                    for (j = 0; left_len > 0 && j < convert_buffer[i].len;j++)
                    {
                        *string++ = convert_buffer[i].convert[j];
                        left_len--;
                    }
                    first_char[i] = convert_buffer[i].convert[0];
                }
                first_char[i] = 0;
                *string = 0;
                string = convert_string;
            }
            else    /* ASCII */
            {
                string = name;
                srv_phb_convert_to_initial(name, first_char, key_length);
                string[key_length] = 0;
            }

            if (srv_phb_compare_ucs2_string(first_char, keyword) == 0)
            {
                return MMI_TRUE;
            }

            if (srv_phb_compare_ucs2_string(string, keyword) == 0)
            {
                return MMI_TRUE;
            }            
        }
        #ifdef __OP01__
        if (store_index < MMI_PHB_PHONE_ENTRIES)
        {
            mmi_phb_optional_fields_struct *optional_field = srv_phb_get_phone_optional_field(store_index);
            if (optional_field != NULL)
            {
                for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
                {
                    if (srv_phb_acs_wcs_n_cmp(optional_field->num[i].number, keyword, key_length) == 0)
                    {
                        return MMI_TRUE;
                    }
                }
            }
        }
        else
        {
            for (i = 0; i < MMI_PHB_SIM_NUM_COUNT; i++)
            {
                CHAR* sim_number;
                sim_number = srv_phb_get_sim_number(store_index, i, NULL);
                if (sim_number == NULL)
                {
                    continue;
                }
                if (srv_phb_acs_wcs_n_cmp(
                        sim_number,
                        keyword,
                        key_length) == 0)
                {
                    return MMI_TRUE;
                }
            }
        }
        #endif
    }
    /*
     *search length == 0, display whole list.
     */
    else
    {
        return MMI_TRUE;
    }        
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_updata_qcache
 * DESCRIPTION
 *  quick search cache update function 
 * PARAMETERS
 *  param     : [IN]   event data
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_phb_sse_updata_qcache(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_evt_struct* evt = (srv_phb_op_evt_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->update_field & MMI_PHB_CONTACT_FIELD_NAME)
    {
        if (g_srv_phb_sse_cntx.q_cache)
        {
            //WCHAR* name = srv_phb_contact_get_name(evt->contact);
            WCHAR name[2];
            srv_phb_datamgr_get_name(evt->id, name, 1);
            if (UI_TEST_UCS2_CHARACTER(name[0]))
            {
                srv_phb_convert_to_spelling(
                    g_srv_phb_sse_cntx.q_cache->input_mode,
                    name[0], 
                    &g_srv_phb_sse_cntx.q_cache->word[evt->store_index],
                    1);
            }
            else
                /* This is an ASCII char */
            {
                g_srv_phb_sse_cntx.q_cache->word[evt->store_index] = name[0];
            }
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_delete_qcache
 * DESCRIPTION
 *  quick search cache update function 
 * PARAMETERS
 *  param     : [IN]   event data
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_phb_sse_delete_qcache(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_op_evt_struct* evt = (srv_phb_op_evt_struct*)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_sse_cntx.q_cache)
    {
        g_srv_phb_sse_cntx.q_cache->word[evt->store_index] = 0;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_make_qsearch_cache
 * DESCRIPTION
 *  make quick cache
 * PARAMETERS
 *  cache        : [OUT]      quick search cache
 *  input_mode   : [IN]       input mode
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sse_make_qsearch_cache(U16* cache, U16 input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 pre_name = 0;
    U16 pre_index = 0;
    U16 store_index;
    U16 name[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Begin to convert first character of name field to associated input method string. */
    for (i = 0; i < g_srv_phb_sse_cntx.entry_count; i++)
    {
        store_index = g_srv_phb_sse_cntx.name_index[i];

        if (MMI_PHB_CONTACT_FIELD_NAME & srv_phb_datamgr_get_field_mask(store_index))
        {
            srv_phb_datamgr_get_name(store_index, name, 1);
            if (UI_TEST_UCS2_CHARACTER(name[0]))
            {
                if (i != 0)
                {
                    /* If character is the same, do not convert again. */
                    if (name[0] == pre_name)
                    {
                        cache[store_index] = cache[pre_index];
                        continue;
                    }
                }

                srv_phb_convert_to_spelling(input_mode, name[0], &cache[store_index], 1);
                pre_index = store_index;
                pre_name = name[0];
            }
            else
                /* This is an ASCII char */
            {
                cache[store_index] = name[0];
            }
        }
        /* The name field is Empty */
        else
        {
            cache[store_index] = 0;
        }
    }
}

#endif /* __MMI_PHB_QUICK_SEARCH__ */


#define EXTERNAL_FUNCTION
/***************************************************************************** 
 * Global Function 
 *****************************************************************************/

 
/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_convert_number_to_int
 * DESCRIPTION
 *  Converts the last n characters of a phone number to digits
 * PARAMETERS
 *  ascii_number       : [IN]        Input ascii number
 * RETURNS
 *  interger of input number
 *****************************************************************************/
U32 srv_phb_sse_convert_number_to_int(CHAR *ascii_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num_len;
    U16 ext_len;
    U16 buff_len = MMI_PHB_NUMBER_PLUS_LENGTH;
    CHAR *number;
    CHAR temp_number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    U8 compare_length = 9;  /* Maximum convert number length is 9 digits. (4 bytes integer) */
    U32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ascii_number != NULL)
    {
        strncpy(temp_number, ascii_number, buff_len);
        temp_number[buff_len] = 0;  /* Makre sure there will be terminator */
    }
    else
    {
        return SRV_PHB_INVALID_NUMBER;
    }

    number = temp_number;

    /* Ignore  *31# and #31# case */
    while (((number[0] == '*') && (number[1] == '3') && (number[2] == '1') && (number[3] == '#')) ||
           ((number[0] == '#') && (number[1] == '3') && (number[2] == '1') && (number[3] == '#')))
    {
        number += 4;
    }

    /* Skip the first plus sign */
    if (number[0] == '+')
    {
        number++;
    }

    /* number empty */
    if (number[0] == '\0')
    {
        return SRV_PHB_INVALID_NUMBER;
    }

    /* Find the position of extension number and remove that part */
    ext_len = strcspn(number, "+pPwW*#");
    if (!ext_len)
    {
        return SRV_PHB_EMPTY_NUMBER;
    }
    else
    {
        MMI_ASSERT(ext_len <= buff_len);

        number[ext_len] = '\0';

        /* Read compare length from NVRAM */
        if (!g_srv_phb_sse_cntx.number_compare_length)
        {
            g_srv_phb_sse_cntx.number_compare_length = srv_phb_read_compare_length();
        }

        num_len = strlen(number);

        /* May compare less number than 9 digits */
        if (g_srv_phb_sse_cntx.number_compare_length < 9)
        {
            compare_length = g_srv_phb_sse_cntx.number_compare_length;
        }

        /* Convert at most 9 digits integer */
        if (num_len > compare_length)
        {
            number += num_len - compare_length;
        }

        /* return a 32 bits integer by atol() */
        result = atol(number);
        
        MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_NUMBER_CONVERT, result);
        return result;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_build_name_index
 * DESCRIPTION
 *  build name sorted array
 * PARAMETERS
 *  cb   :  [IN] call back function
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_phb_sse_build_name_index(srv_phb_async_func_type cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #if defined(__MMI_PHB_PINYIN_SORT__)
    U32 id = 0;
    U16 full_name[MMI_PHB_NAME_LENGTH + 1];
    #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_NAME_SORT, g_srv_phb_sse_cntx.entry_count);

    if (g_srv_phb_sse_cntx.entry_count >= 1)
    {
    #if defined(__MMI_PHB_PINYIN_SORT__)
        for (id = 0; id < g_srv_phb_sse_cntx.entry_count; id++)
        {
            srv_phb_datamgr_get_name(id, full_name, MMI_PHB_NAME_LENGTH);
            srv_phb_sse_make_pinyin_cache(id, full_name);
        }
    #endif /* defined(__MMI_PHB_PINYIN_SORT__) */
        srv_phb_sse_name_quicksort(0, (U16)(g_srv_phb_sse_cntx.entry_count - 1));
        srv_phb_sse_name_insertionsort(0, (U16)(g_srv_phb_sse_cntx.entry_count - 1));
        srv_phb_sse_name_quicksort(MMI_PHB_ENTRIES, (U16)(MMI_PHB_ENTRIES + g_srv_phb_sse_cntx.fdn_count - 1));
        srv_phb_sse_name_insertionsort(MMI_PHB_ENTRIES, (U16)(MMI_PHB_ENTRIES + g_srv_phb_sse_cntx.fdn_count - 1));
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_build_lookup_table
 * DESCRIPTION
 *  This function builds the lookup table for cross-referencing during MO/MT calls.
 *  This table contains the home/mobile/fax/office number(s) of a phonebook entry.
 * PARAMETERS
 *  cb   :  [IN] call back function
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sse_build_lookup_table(FuncPtr cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_contact_id id;
    S32 count = 0;
#ifdef __MMI_PHB_USIM_SUPPORT__
    U8 i;
#endif
    CHAR* num_ascii;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_sse_cntx.number_ready = MMI_FALSE;
    g_srv_phb_sse_cntx.number_count = 0;
    g_srv_phb_sse_cntx.cancel_sorting = MMI_FALSE;
    memset(g_srv_phb_sse_cntx.num_cache, 0xFF, sizeof(g_srv_phb_sse_cntx.num_cache));
    while (count < g_srv_phb_sse_cntx.entry_count)
    {
        id = g_srv_phb_sse_cntx.name_index[count];
        if ((id >= MMI_PHB_PHONE_ENTRIES) && (srv_phb_get_sim_field_mask(id) & MMI_PHB_CONTACT_FIELD_NUMBER))
        {
        #ifdef __MMI_PHB_USIM_SUPPORT__
            for (i = 0; i < MMI_PHB_SIM_NUM_COUNT; i++)
            {
                num_ascii = srv_phb_get_sim_number(id, i, NULL);
                srv_phb_sse_populate_number(id, num_ascii);
            }
        #else
            num_ascii = srv_phb_get_sim_number(id, 0, NULL);
            srv_phb_sse_populate_number(id, num_ascii);
        #endif
        }
        count++;
    }

    id = srv_phb_get_next_phone_contact(0, MMI_PHB_CONTACT_FIELD_NUMBER);
    if (id != SRV_PHB_INVALID_INDEX)
    {
        srv_phb_sse_sort_number_cntx* sort_cntx = 
            srv_phb_mem_malloc(sizeof(srv_phb_sse_sort_number_cntx), SRV_PHB_MEMORY_TYPE_ADM);
        sort_cntx->id = id;
        sort_cntx->cb = cb;
        srv_phb_async_event_interface(srv_phb_sse_read_numbers, sort_cntx);
    }
    else
    {
        srv_phb_sse_lookup_table_sort(cb);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_store_index_to_sort_index
 * DESCRIPTION
 *  convet store_index to name sort index
 * PARAMETERS
 *  storage     :  [IN]    storage
 *  id          :  [IN]    store_index
 * RETURNS
 *  S32  
 * RETURN VALUES
 *  >=0                      :                    name sort index
 *  SRV_PHB_OUT_OF_INDEX     :                    input index out of index
 *  SRV_PHB_NOT_FOUND        :                    input index not exist
 *****************************************************************************/
S32 srv_phb_sse_store_index_to_sort_index(U8 storage, mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, sort_index = 0;
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id > MMI_PHB_ENTRIES)
    {
        return SRV_PHB_OUT_OF_INDEX;
    }

    for (i = 0; i < g_srv_phb_sse_cntx.entry_count; i++)
    {
        index = g_srv_phb_sse_cntx.name_index[i];
        if (srv_phb_check_store_index_in_storage(index, storage))
        {
            sort_index++;
        }
        if (id == index)
        {
            return sort_index;
        }
    }
    return SRV_PHB_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_sort_index_to_store_index
 * DESCRIPTION
 *  convet name sort index to store_index
 * PARAMETERS
 *  storage     : [IN]   storage
 *  sort_index  : [IN]   name sort index
 * RETURNS
 *  S32  
 * RETURN VALUES
 *  >=0                      :                    store index
 *  SRV_PHB_OUT_OF_INDEX     :                    input index out of index
 *  SRV_PHB_NOT_FOUND        :                    input index not exist
 *****************************************************************************/
S32 srv_phb_sse_sort_index_to_store_index(U8 storage, U16 sort_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, index = 0;
    mmi_phb_contact_id id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sort_index > g_srv_phb_sse_cntx.entry_count)
    {
        return SRV_PHB_OUT_OF_INDEX;
    }

    if (storage == PHB_STORAGE_MAX)
    {
        return g_srv_phb_sse_cntx.name_index[sort_index];
    }

    for (i = 0; i < g_srv_phb_sse_cntx.entry_count; i++)
    {
        id = g_srv_phb_sse_cntx.name_index[i];

        if (storage == srv_phb_get_storage(id))
        {
            index++;
        }

        if (sort_index == index)
        {
            return id;
        }
    }
    return SRV_PHB_NOT_FOUND;
}

 
 /*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_lookup_table_remove_contact
 * DESCRIPTION
 *  clear all/a number of a contact in lookup table
 * PARAMETERS
 *  store_index   :  [IN]      contact's store_index
 *  number        :  [IN]      number to remove if NULL remove all number
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sse_lookup_table_remove_contact(mmi_phb_contact_id id, CHAR* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_lookup_number_node_struct* node = g_srv_phb_sse_cntx.number_node;
    S32 k, j = 0;
    U32 temp = SRV_PHB_INVALID_NUMBER;
    MMI_BOOL remove_all = MMI_TRUE;
    MMI_BOOL need_remove = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_srv_phb_sse_cntx.number_count)
    {
        return;
    }

    if (number != NULL)
    {
        temp = srv_phb_sse_convert_number_to_int(number);
        if (temp < SRV_PHB_INVALID_NUMBER)
        {
            remove_all = MMI_FALSE;
        }
        else
        {
            return;
        }
    }

    for (k = 0; k < g_srv_phb_sse_cntx.number_count; k++)
    {
        if ((node[k].id == id) &&
            (remove_all || (need_remove && temp == node[k].number)))
        {
            need_remove = MMI_FALSE;
        }
        else
        {
            node[j].id = node[k].id;
            node[j].number = node[k].number;
            j++;
        }
    }
    g_srv_phb_sse_cntx.number_count = j;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_sse_lookup_table_add_contact
* DESCRIPTION
*  add a number into lookup table
* PARAMETERS
*  store_index    : [IN]        number's store_index
*  number         : [IN]        number
* RETURNS
*  void
*****************************************************************************/
void srv_phb_sse_lookup_table_add_contact(mmi_phb_contact_id id, CHAR* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number != NULL)
    {
        temp = srv_phb_sse_convert_number_to_int(number);
        if (temp < SRV_PHB_INVALID_NUMBER && g_srv_phb_sse_cntx.number_count < SRV_PHB_NUMBER_COUNT)
        {
            srv_phb_sse_lookup_table_add_num(id, temp);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  srv_phb_sse_remove_number_cache
* DESCRIPTION
*  populate a number to lookup table
* PARAMETERS
*  store_index     : [IN]        number's store_index
*  number          : [IN]        number
* RETURNS
*  void
*****************************************************************************/
void srv_phb_sse_remove_number_cache(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *bcd_num = g_srv_phb_sse_cntx.num_cache[MMI_PHB_NUMBER_FIELD_COUNT * id];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(bcd_num, 0xFF, (SRV_PHB_NUM_CACHE_LEN + 1) / 2 * MMI_PHB_NUMBER_FIELD_COUNT);
}

/*****************************************************************************
* FUNCTION
*  srv_phb_sse_add_number_cache
* DESCRIPTION
*  populate a number to lookup table
* PARAMETERS
*  store_index     : [IN]        number's store_index
*  number          : [IN]        number
* RETURNS
*  void
*****************************************************************************/
void srv_phb_sse_set_number_cache(mmi_phb_contact_id id, CHAR* number, U32 order_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *bcd_num = g_srv_phb_sse_cntx.num_cache[MMI_PHB_NUMBER_FIELD_COUNT * id + order_id];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number != NULL && number[0])
    {
        S32 i = 0;
        U8 num_ch;
        while ((num_ch = *(number + i)) != 0)
        {
            if (i == 0 && num_ch == '+')
            {
                num_ch = '0';
            }
            else
            {
                if (!isdigit(num_ch))
                {
                    break;
                }
            }
            if ((i % 2) == 0)
            {
                bcd_num[i / 2] = (((num_ch - '0') << 4) | 0x0F);
            }
            else
            {
                bcd_num[i / 2] &= 0xF0;
                bcd_num[i / 2] |= ((num_ch - '0') & 0x0F);
            }
            if (++i >= SRV_PHB_NUM_CACHE_LEN)
            {
                break;
            }
        }
    }
    else
    {
        memset(bcd_num, 0xFF, (SRV_PHB_NUM_CACHE_LEN + 1) / 2);
    }
}

/*****************************************************************************
* FUNCTION
*  srv_phb_sse_insert_name_index
* DESCRIPTION
*  Insert a contact to name sort array
* PARAMETERS
*  store_index    : [IN]            contact store_index
*  name           : [IN]            contact name
* RETURNS
*  insert postion
*****************************************************************************/
U16 srv_phb_sse_insert_name_index(mmi_phb_contact_id id, WCHAR* name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 pos;
    U16 pos_start = 0;
    U16 pos_end = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(id < MMI_PHB_ENTRIES)
    {

        pos_start = 0;
        pos_end = g_srv_phb_sse_cntx.entry_count;
        pos = srv_phb_sse_get_name_pos(pos_start, (S32)(pos_end - 1), name, id);
        g_srv_phb_sse_cntx.entry_count++;
    }
    else
    {
        pos_start = MMI_PHB_ENTRIES;
        pos_end = MMI_PHB_ENTRIES + g_srv_phb_sse_cntx.fdn_count;
        pos = srv_phb_sse_get_name_pos(pos_start, (S32)(pos_end - 1), name, id);
        g_srv_phb_sse_cntx.fdn_count++;
    }
    for (i = (S32)pos_end; i > pos; i--)
    {
        g_srv_phb_sse_cntx.name_index[i] = g_srv_phb_sse_cntx.name_index[i - 1];
    }
    g_srv_phb_sse_cntx.name_index[pos] = id;
    return pos;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_sse_populate_name_index
* DESCRIPTION
*  populate a conact to name_index array
* PARAMETERS
*  store_index     : [IN]            contact store_index
* RETURNS
*  void
*****************************************************************************/
void srv_phb_sse_populate_name_index(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id >= MMI_PHB_ENTRIES)
    {
        g_srv_phb_sse_cntx.name_index[MMI_PHB_ENTRIES + g_srv_phb_sse_cntx.fdn_count++] = id;
    }
    else
    {
        g_srv_phb_sse_cntx.name_index[g_srv_phb_sse_cntx.entry_count++] = id;
    }
}

/*****************************************************************************
* FUNCTION
*  srv_phb_sse_clear_fdn_name_index
* DESCRIPTION
*  clear fdn name_index array
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_phb_sse_clear_fdn_name_index(sim_interface_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_contact_id id;
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = MMI_PHB_ENTRIES + g_srv_phb_sse_cntx.fdn_count - 1; i >= MMI_PHB_ENTRIES; i --)
    {
        id = g_srv_phb_sse_cntx.name_index[i];
        if (id != 0 && (id - MMI_PHB_ENTRIES) / MMI_PHB_FDN_ENTRIES == sim_id)
        {
            srv_phb_sse_delete_name_index(id);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  srv_phb_sse_delete_name_index
* DESCRIPTION
*  delete a contact from name sort array
* PARAMETERS
*  store_index    :  [IN]          contact's store_index
* RETURNS
*  void
*****************************************************************************/
void srv_phb_sse_delete_name_index(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 pos, i, total;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id >= MMI_PHB_ENTRIES)
    {
        pos = MMI_PHB_ENTRIES;
        total = MMI_PHB_ENTRIES + g_srv_phb_sse_cntx.fdn_count;
    }
    else
    {
        pos = 0;
        total = g_srv_phb_sse_cntx.entry_count;
    }
    
    for (; pos < total; pos++)
    {
        if (g_srv_phb_sse_cntx.name_index[pos] == id)
        {
            if (id >= MMI_PHB_ENTRIES)
            {
                g_srv_phb_sse_cntx.fdn_count--;
            }
            else
            {
                g_srv_phb_sse_cntx.entry_count--;
            }            
            break;
        }
    }

    for (i = pos; i < total; i++)
    {
        g_srv_phb_sse_cntx.name_index[i] = g_srv_phb_sse_cntx.name_index[i + 1];
    }
}


/*****************************************************************************
* FUNCTION
*  srv_phb_sse_delete_name_index_by_storage
* DESCRIPTION
*  clear name index array by storage
* PARAMETERS
*  storage    :     [IN]        storage
* RETURNS
*  void
*****************************************************************************/
void srv_phb_sse_delete_name_index_by_storage(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_sse_cntx.cancel_sorting = MMI_TRUE;
    for (i = 0; i < g_srv_phb_sse_cntx.entry_count; i++)
    {
        if (srv_phb_get_storage(g_srv_phb_sse_cntx.name_index[i]) != storage)
        {
            g_srv_phb_sse_cntx.name_index[j] = g_srv_phb_sse_cntx.name_index[i];
            j++;
        }
    }
    g_srv_phb_sse_cntx.entry_count = j;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_build_contact_list
 * DESCRIPTION
 *  build contact store_index array by filter
 * PARAMETERS
 *  filter        : [IN]    filter
 *  entry_array   : [IN]    contcat list array
 *  max_count     : [IN]    max count of entry array
 * RETURNS
 *  entry count
 *****************************************************************************/
S32 srv_phb_sse_build_contact_list(srv_phb_filter_struct* filter, U16* entry_array, U32 max_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 entry_count = 0;
    S32 i;
    U16 store_index;
#ifdef __MMI_PHB_CALLER_GROUP__
    U8* group_field = NULL;
#endif
#if defined(__MMI_PHB_QUICK_SEARCH__)
    srv_phb_sse_qsearch_convert_struct* convert_buffer = NULL;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!filter)
    {
        if (max_count > g_srv_phb_sse_cntx.entry_count)
        {
            max_count = g_srv_phb_sse_cntx.entry_count;
        }
        memcpy(entry_array, g_srv_phb_sse_cntx.name_index, max_count * sizeof(U16));
        return max_count;
    }

#ifdef __MMI_PHB_CALLER_GROUP__
    if (filter->group_filter)
    {
     #ifdef __MMI_PHB_USIM_SUPPORT__
        if (filter->storage >= PHB_STORAGE_SIM && filter->storage <= PHB_STORAGE_SIM4)
        {
            group_field = srv_phb_mem_malloc(
                              srv_phb_get_sim_total(filter->storage) * sizeof(srv_phb_sim_grp_struct), 
                              SRV_PHB_MEMORY_TYPE_ADM);
            srv_phb_sim_get_grp_cache(srv_phb_get_sim_id(filter->storage), group_field);
        }
        else
     #endif /* __MMI_PHB_USIM_SUPPORT__ */
     #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        if (filter->storage == PHB_STORAGE_TCARD)
        {
            group_field = srv_phb_mem_malloc(
                              MMI_PHB_TCARD_ENTRIES * sizeof(U32), 
                              SRV_PHB_MEMORY_TYPE_ADM);
            srv_phb_get_tcard_all_group_field((U32 *)(group_field));
        }
        else
     #endif /* __SRV_PHB_TCARD_STORAGE_SUPPORT__ */
        {
            group_field = srv_phb_mem_malloc(
                              NVRAM_EF_PHB_GROUP_FIELD_TOTAL * NVRAM_EF_PHB_GROUP_FIELD_SIZE, 
                              SRV_PHB_MEMORY_TYPE_ADM);
            memset(group_field, 0, sizeof(group_field));
            srv_phb_get_all_phone_group_field(group_field);
        }
    }
#endif /* __MMI_PHB_CALLER_GROUP__ */

#if defined(__MMI_PHB_QUICK_SEARCH__)
    if (filter->qsearch_filter && filter->qsearch_filter->key_len)
    {
        convert_buffer = srv_phb_mem_malloc(
                            MMI_PHB_QSEARCH_LENGTH * sizeof(srv_phb_sse_qsearch_convert_struct), 
                            SRV_PHB_MEMORY_TYPE_CTR);
        memset(convert_buffer, 0, MMI_PHB_QSEARCH_LENGTH * sizeof(srv_phb_sse_qsearch_convert_struct));
        do
        {
            if (!g_srv_phb_sse_cntx.q_cache)
            {
                g_srv_phb_sse_cntx.q_cache = 
                    srv_phb_mem_malloc(sizeof(srv_phb_sse_qsearch_cache_struct), SRV_PHB_MEMORY_TYPE_ADM);
                memset(g_srv_phb_sse_cntx.q_cache->word, 0, MMI_PHB_ENTRIES);
            }
            /*else if (g_srv_phb_sse_cntx.q_cache->input_mode == filter->qsearch_filter->input_mode)
            {
                break;
            }*/
            g_srv_phb_sse_cntx.q_cache->input_mode = filter->qsearch_filter->input_mode;
            srv_phb_sse_make_qsearch_cache(
                g_srv_phb_sse_cntx.q_cache->word, 
                g_srv_phb_sse_cntx.q_cache->input_mode);
        } while (0);
    }
#endif /* __MMI_PHB_QUICK_SEARCH__ */

    for (i = 0; i < (g_srv_phb_sse_cntx.entry_count) && (entry_count < (U16)max_count); i++)
    {
        store_index = g_srv_phb_sse_cntx.name_index[i];
        if (!srv_phb_sse_normal_filter(store_index, filter->storage, filter->field_filter))
        {
            continue;
        }
        
        if (filter->name_filter && !srv_phb_sse_name_filter(store_index, filter->name_filter))
        {
            continue;
        }

    #ifdef __MMI_PHB_CALLER_GROUP__
        if (filter->group_filter && !srv_phb_sse_group_filter(store_index, (phb_storage_enum)(filter->storage), filter->group_filter, group_field))
        {
            continue;
        }
    #endif /* __MMI_PHB_CALLER_GROUP__ */
    #if defined(__MMI_PHB_QUICK_SEARCH__)
        if (filter->qsearch_filter && filter->qsearch_filter->key_len && !srv_phb_sse_qsearch_filter(store_index, filter->qsearch_filter, convert_buffer))
        {
            continue;
        }
    #endif /* __MMI_PHB_QUICK_SEARCH__ */
        if ((phb_storage_enum)(srv_phb_get_storage(store_index)) >= PHB_STORAGE_SIM
            && (phb_storage_enum)(srv_phb_get_storage(store_index)) <= PHB_STORAGE_SIM4
            && !srv_sim_ctrl_is_available(mmi_frm_index_to_sim(srv_phb_get_sim_id((phb_storage_enum)(srv_phb_get_storage(store_index))))))
        {
            continue;
        }
    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        if (srv_phb_get_storage(store_index) == PHB_STORAGE_TCARD
            && (!srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV)
            #ifdef __MMI_USB_SUPPORT__
            || srv_usb_is_in_mass_storage_mode_ext()
            #endif
            ))
        {
            continue;
        }
    #endif /* __SRV_PHB_TCARD_STORAGE_SUPPORT__ */
        entry_array[entry_count++] = store_index;

    }
#ifdef __MMI_PHB_QUICK_SEARCH__
    if (convert_buffer)
    {
        srv_phb_mem_free(convert_buffer);
    }
#endif /* __MMI_PHB_QUICK_SEARCH__ */
#ifdef __MMI_PHB_CALLER_GROUP__
    if (group_field)
    {
        srv_phb_mem_free(group_field);
    }
#endif /* __MMI_PHB_CALLER_GROUP__ */
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_FILTER_CONTACT, filter->storage, filter->field_filter, entry_count);
    return entry_count;
}



/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_build_alpha_jump_table
 * DESCRIPTION
 *  build alpha jump table
 * PARAMETERS
 *  entry_array              : [IN]        store_index array
 *  entry_count              : [IN]        contacts count
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sse_build_alpha_jump_table(U16* entry_array, U16 entry_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j, count = 0;
    MMI_BOOL valid_ch;
    U8 index = 0xff;
    U16 store_index;
    U16 name[2];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_srv_phb_sse_cntx.alpha_table)
    {
        g_srv_phb_sse_cntx.alpha_table = 
            srv_phb_mem_malloc(SRV_PHB_ALPHA_LIST_COUNT * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
    }
    memset(g_srv_phb_sse_cntx.alpha_table, 0, SRV_PHB_ALPHA_LIST_COUNT * sizeof(U16));

    for (i = 0; i < entry_count; i++)
    {
        store_index = entry_array[i];
        srv_phb_datamgr_get_name(store_index, name, 1);

        if ((name[0] >= L'a') && (name[0] <= L'z'))    /* lower case */
        {
            index = (U8)(name[0] - L'a');
            valid_ch = MMI_TRUE;
        }
        else if ((name[0] >= L'A') && (name[0] <= L'Z'))       /* upper case */
        {
            index = (U8)(name[0] - L'A');
            valid_ch = MMI_TRUE;
        }
    #if defined(__MMI_PHB_PINYIN_SORT__)
        else if (name[0])    /* A 2-bytes character */
        {
            name[0] = srv_phb_sse_get_first_pinyin_char(store_index);
            if ((name[0] >= L'a') && (name[0] <= L'z'))
            {
                index = (U8)(name[0] - L'a');
                valid_ch = MMI_TRUE;
            }
            else
            {
                valid_ch = MMI_FALSE;
            }
        }
    #endif /* defined(__MMI_PHB_PINYIN_SORT__) */ 
        else
        {
            valid_ch = MMI_FALSE;
        }

        /* Assign alpha index */
        if (index < SRV_PHB_ALPHA_LIST_COUNT && g_srv_phb_sse_cntx.alpha_table[index] == 0 && valid_ch)
        {
            for (j = 0; j < index; j++)
            {
                if (g_srv_phb_sse_cntx.alpha_table[j] == 0)
                {
                    g_srv_phb_sse_cntx.alpha_table[j] = count + 1;
                }
            }
            g_srv_phb_sse_cntx.alpha_table[index] = count + 1;
            MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_ALPHA_TABLE, index, g_srv_phb_sse_cntx.alpha_table[index]);
        }

        count++;
    }

    /* Handle unassigned index */
    count = 1;
    for (j = 0; j < SRV_PHB_ALPHA_LIST_COUNT; j++)
    {
        if (g_srv_phb_sse_cntx.alpha_table[j] == 0)
        {
            g_srv_phb_sse_cntx.alpha_table[j] = count;
        }
        else
        {
            count = g_srv_phb_sse_cntx.alpha_table[j];
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_get_alpha_index
 * DESCRIPTION
 *  get alpha jump index
 * PARAMETERS
 *  input_char               : [IN]        input char
 * RETURNS
 *  U16
 * RETURN VALUES
 *  >=0             :          jump index
 *  <0              :          refer phb error result
 *****************************************************************************/
U16 srv_phb_sse_get_alpha_index(U16 input_char)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_sse_cntx.alpha_table)
    {
        if (input_char >= L'A' && input_char <= L'Z')
        {
            return g_srv_phb_sse_cntx.alpha_table[input_char - L'A'] - 1;
        }
        else if(input_char >= L'a' && input_char <= L'z')
        {
            return g_srv_phb_sse_cntx.alpha_table[input_char - L'a'] - 1;
        }
    }
    return SRV_PHB_INVALID_INDEX;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_lookup_table_search
 * DESCRIPTION
 *  Search for the number in the lookup table
 *  and returns the index of the matched entry.
 * PARAMETERS
 *  number              : [IN]        number to search(after convert)
 *  low                 : [IN]        low index
 *  high                : [IN]        high index
 *  number_ASCII        : [IN]        number to search(ascii number)
 *  number_index         : [OUT]       matched number's type
 * RETURNS
 *  S32
 * RETURN VALUES
 *  >=0                      :                    store index
 *  SRV_PHB_NOT_FOUND        :                    no number matched
 *****************************************************************************/
static S32 srv_phb_sse_lookup_table_search(U32 number, S16 low, S16 high, CHAR *number_ascii, U32* number_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 mid;
    srv_phb_lookup_number_node_struct* node = g_srv_phb_sse_cntx.number_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (number == node[mid].number)
        {
            /*
             * Advanced Compare - Compare number longer than 9 digit,
             * with extension, find out the prior one if numbers are the same, and etc.
             */
        #if defined(__MMI_PHB_ADV_NUM_MATCH_MOBILE__)
            mid = srv_phb_sse_adv_number_search(mid, number, number_ascii, number_index);

            if (mid < 0)
            {
                return SRV_PHB_NOT_FOUND;  /* an invalid number */
            }
            else
        #endif /* defined(__MMI_PHB_ADV_NUM_MATCH_MOBILE__) */ 
            {
                MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_SEARCH_NUMBER, number, node[mid].id, number_index);
                return node[mid].id;
            }
        }
        else if (number < node[mid].number)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return SRV_PHB_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_search_num
 * DESCRIPTION
 *  search number
 * PARAMETERS
 *  num_wcs     :   [IN]     number to search
 *  number_index :   [OUT]    matched number's type
 * RETURNS
 *  S32
 * RETURN VALUES
 *  >=0                      :                    store index
 *  SRV_PHB_NOT_FOUND        :                    no number matched
 *  SRV_PHB_NUM_NOT_READY    :                    lookup table not ready
 *****************************************************************************/
S32 srv_phb_sse_search_num(U16* num_wcs, U32* number_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 num;
    CHAR number_ascii[MMI_PHB_NUMBER_PLUS_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (num_wcs[0] == 0)
    {
        return SRV_PHB_NOT_FOUND;
    }

    /* Lookup into table when (1) lookup table not empty (3)All Entries populated and sorted */
    if (g_srv_phb_sse_cntx.number_ready && g_srv_phb_sse_cntx.number_count)
    {
        mmi_wcs_n_to_asc(number_ascii, num_wcs, MMI_PHB_NUMBER_PLUS_LENGTH * sizeof(U16));
        num = srv_phb_sse_convert_number_to_int(number_ascii);
        if (num < SRV_PHB_INVALID_NUMBER)
        {
            return srv_phb_sse_lookup_table_search(num, (S16)0, (S16)(g_srv_phb_sse_cntx.number_count - 1), (CHAR*)number_ascii, number_index);            
        }
    }
    else
    {
        return SRV_PHB_NUM_NOT_READY;
    }
    return SRV_PHB_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_search_name
 * DESCRIPTION
 *  search contact by name
 * PARAMETERS
 *  name_wcs     : [IN]    name to search
 * RETURNS
 *  S32
 * RETURN VALUES
 *  >=0                      :                    store index
 *  SRV_PHB_NOT_FOUND        :                    no name matched
 *****************************************************************************/
S32 srv_phb_sse_search_name(U16* name_wcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    U16 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name_wcs[0] == 0)
    {
        return SRV_PHB_NOT_FOUND;
    }

    result = srv_phb_sse_binary_search_name(0, (S32)(g_srv_phb_sse_cntx.entry_count - 1), name_wcs, &index);
    if (result != SRV_PHB_NO_ERROR)
    {
        return result;

    }
    else
    {
        return index;
    }
}


#define SRV_PHB_FIELD_FILTER

typedef struct
{
    U32 field_type;
    U8 number_type;
    MMI_BOOL default_number;
} srv_phb_field_filter_struct;


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_number_by_feild_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_check_number_by_feild_filter(srv_phb_field_filter filter, U8 number_type, MMI_BOOL is_default)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_field_filter_struct* op_filter = (srv_phb_field_filter_struct*)filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!op_filter)
    {
        return MMI_TRUE;
    }
    else if ((op_filter->number_type == MMI_PHB_NUM_TYPE_NONE || op_filter->number_type == number_type) &&
             (!(op_filter->default_number) || is_default))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_field_by_feild_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_check_field_by_feild_filter(srv_phb_field_filter filter, U32 filed_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_field_filter_struct* op_filter = (srv_phb_field_filter_struct*)filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!op_filter || (op_filter->field_type & filed_type))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_create_field_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_field_filter srv_phb_create_field_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_field_filter_struct* filter = srv_phb_mem_malloc(sizeof(srv_phb_field_filter_struct), SRV_PHB_MEMORY_TYPE_CTR);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filter->field_type = MMI_PHB_CONTACT_FIELD_ALL;
    filter->number_type = MMI_PHB_NUM_TYPE_NONE;
    filter->default_number = MMI_FALSE;
    return filter;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_create_field_filter_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_field_filter srv_phb_create_field_filter_ext(U32 field_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_field_filter_struct* filter = srv_phb_mem_malloc(sizeof(srv_phb_field_filter_struct), SRV_PHB_MEMORY_TYPE_CTR);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filter->field_type = field_type;
    filter->number_type = MMI_PHB_NUM_TYPE_NONE;
    filter->default_number = MMI_FALSE;
    return filter;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_create_field_filter_ext2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_field_filter srv_phb_create_field_filter_ext2(U32 field_type, U8 number_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_field_filter_struct* filter = srv_phb_mem_malloc(sizeof(srv_phb_field_filter_struct), SRV_PHB_MEMORY_TYPE_CTR);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filter->field_type = field_type;
    filter->number_type = number_type;
    filter->default_number = MMI_FALSE;
    return filter;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_free_field_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_free_field_filter(srv_phb_field_filter filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filter)
    {
        srv_phb_mem_free(filter);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_filed_filter_set_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_filed_filter_set_field(srv_phb_field_filter filter, U32 field_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_field_filter_struct* op_filter = (srv_phb_field_filter_struct*)filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    op_filter->field_type = field_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_filed_filter_set_number_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_filed_filter_set_number_type(srv_phb_field_filter filter, U8 number_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_field_filter_struct* op_filter = (srv_phb_field_filter_struct*)filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    op_filter->number_type = number_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_filed_filter_set_default_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_filed_filter_set_default_number(srv_phb_field_filter filter, MMI_BOOL only_default)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_field_filter_struct* op_filter = (srv_phb_field_filter_struct*)filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    op_filter->default_number = only_default;
}


#define SRV_PHB_CONTACT_FIELTER

#define SRV_PHB_CIRCLE_INCREASE_ID(_id, _add, _max)  (((_id + _add) >= _max) ? (_id + _add - _max): (_id + _add))

#define SRV_PHB_SET_BIT_MASK(_mask, _index)  (_mask[_index / 8] |= (1 << (_index % 8)))


/*****************************************************************************
 * FUNCTION
 *  srv_phb_filter_contact_by_normal
 * DESCRIPTION
 *  filter a contact by field & storage & block filter
 * PARAMETERS
 *  id                 : [IN]      contact's store_index
 *  filter          : [IN]      storage filter
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE                  :                    matched
 *  MMI_FALSE                 :                    not matched
 *****************************************************************************/
static MMI_BOOL srv_phb_filter_contact_by_normal(mmi_phb_contact_id id, srv_phb_contact_filter_struct* filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 mask = srv_phb_datamgr_get_field_mask(id);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(filter->field_type & mask))
    {
        return MMI_FALSE;
    }
    if (!(filter->storage_mask & (1 << srv_phb_get_storage(id))))
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


#ifdef __MMI_PHB_CALLER_GROUP__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_filter_contact_by_group
 * DESCRIPTION
 *  filter a contact by group filter
 * PARAMETERS
 *  id                       : [IN]      contact's store_index
 *  group_cntx          : [IN]      group condition
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE                  :                    matched
 *  MMI_FALSE                 :                    not matched
 *****************************************************************************/
static MMI_BOOL srv_phb_filter_contact_by_group(mmi_phb_contact_id id, srv_phb_group_cntx_struct* group_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    MMI_BOOL result;
#ifdef __MMI_PHB_USIM_SUPPORT__
    U16 record_index;
    U16 offset;
    U8 storage;
#endif /* __MMI_PHB_USIM_SUPPORT__ */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !(defined(__MMI_PHB_USIM_SUPPORT__) || defined(__SRV_PHB_TCARD_STORAGE_SUPPORT__))
    if (id >= MMI_PHB_PHONE_ENTRIES)
    {
        return MMI_FALSE;
    }
#endif
    if (group_cntx->is_equal)
    {
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }
#if defined( __MMI_PHB_USIM_SUPPORT__) || defined (__SRV_PHB_TCARD_STORAGE_SUPPORT__)
    if (srv_phb_get_storage(id) != group_cntx->storage)
    {
        return (MMI_BOOL)(!result);
    }
#endif /* defined( __MMI_PHB_USIM_SUPPORT__) || defined (__SRV_PHB_TCARD_STORAGE_SUPPORT__) */
#ifdef __MMI_PHB_USIM_SUPPORT__
    if (group_cntx->storage >= PHB_STORAGE_SIM && group_cntx->storage <= PHB_STORAGE_SIM4)
    {
        srv_phb_store_index_to_record_index(id, &storage, &record_index);
        offset = (record_index - 1) * sizeof(srv_phb_sim_grp_struct);
        if ((group_cntx->group_field[offset] & group_cntx->group_mask[0]) ||
            (group_cntx->group_field[offset + 1] & group_cntx->group_mask[1]))
        {
            return result;
        }
    }
    else
#endif /* __MMI_PHB_USIM_SUPPORT__ */
#ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    if (group_cntx->storage == PHB_STORAGE_TCARD)
    {
        U8 tmp_storage;
        U16 tmp_record_index;
        S32 i;
        U32 group_mask = 0;
        U32 *group_field = (U32 *)group_cntx->group_field;
        srv_phb_store_index_to_record_index(id, &tmp_storage, &tmp_record_index);
        for (i = MMI_PHB_GROUP_FIELD_SIZE - 1; i >= 0; i --)
        {
            group_mask = group_mask << 8;
            group_mask |= group_cntx->group_mask[i];
        }
        if (group_mask & group_field[tmp_record_index])
        {
            return result;
        }
    }
    else
#endif /* __SRV_PHB_TCARD_STORAGE_SUPPORT__ */
    {
        for (i = 0; i < MMI_PHB_GROUP_FIELD_SIZE; i++)
        {
            if (group_cntx->group_field[id * MMI_PHB_GROUP_FIELD_SIZE + i] & group_cntx->group_mask[i])
            {
                return result;
            }
        }
    }
    return (MMI_BOOL)(!result);
}
#endif /* __MMI_PHB_CALLER_GROUP__ */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_wcs_cirlcle_ncmp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_phb_wcs_cirlcle_ncmp(
            WCHAR* cirlcle,
            U8 circle_start,
            U8 circle_size,
            WCHAR* pattern,
            U16 cmp_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < cmp_len; i++)
    {
        /* First and second are not identical, return distance */
        if (srv_phb_compare_wchar(cirlcle[circle_start], pattern[i]) != 0)
        {
            return MMI_FALSE;
        }
        circle_start = SRV_PHB_CIRCLE_INCREASE_ID(circle_start, 1, circle_size);
    }
    return MMI_TRUE;
}


#ifdef __MMI_DIALER_SEARCH__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_ds_wcs_cirlcle_ncmp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_phb_ds_wcs_cirlcle_ncmp(
            WCHAR* cirlcle,
            U8 circle_start,
            U8 circle_size,
            WCHAR* pattern,
            U16 cmp_len,
            srv_phb_key_cache_struct* key_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, j;
    MMI_BOOL result;
    U16 key_int; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < cmp_len; i++)
    {
        result = MMI_FALSE;
        key_int = pattern[i] - '0';

        for (j = 0; j < key_info->keysize[key_int]; j++)
        {                   
            if (srv_phb_towupper(cirlcle[circle_start]) == key_info->keymap[key_int][j])
            {
                result = MMI_TRUE;
                break;
            }
        }
        if (result)
        {
            circle_start = SRV_PHB_CIRCLE_INCREASE_ID(circle_start, 1, circle_size);
        }
        else
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_calllog
 * DESCRIPTION
 *  
 * PARAMETERS
 *  UI_buffer_type
 * RETURNS
 *  S32
 *****************************************************************************/
static void srv_phb_query_calllog(srv_phb_query_handle handle, srv_phb_contact_filter filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_filter_struct* contact_filter = (srv_phb_contact_filter_struct*)filter;
    srv_phb_query_struct* query_handle = (srv_phb_query_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (contact_filter && contact_filter->query_cntx && (contact_filter->query_cntx->type == SRV_PHB_QUERY_TYPE_DS))
    {
        srv_clog_get_list_log_ids_req_struct req_data;
        srv_clog_get_list_log_ids_cnf_struct cnf_data;
        srv_clog_log_struct log;
        U16 i, len;
        WCHAR *src, *dest;
        srv_clog_init_para(SRV_CLOG_PARA_GET_LIST_LOG_IDS_REQ, &req_data);
        srv_clog_init_para(SRV_CLOG_PARA_GET_LIST_LOG_IDS_CNF, &cnf_data);

        req_data.start_by = SRV_CLOG_BY_ID;
        req_data.log_num = SRV_CLOG_LOG_ID_LIST_MAX_NUM;
        req_data.cate = SRV_CLOG_CATE_CALL;

        while(1)
        {
            req_data.start_elm = cnf_data.next_start_elm;
            if (srv_clog_get_list_log_ids(0, &req_data, &cnf_data) != SRV_CLOG_RET_OK)
            {
                break;
            }

            for (i = 0; i < cnf_data.log_num; i++)
            {
                srv_clog_get_log_by_id(0, cnf_data.log_ids[i], SRV_CLOG_LOG_FIELD_CID, &log);
                src = log.data.call_log.cid;
                dest = contact_filter->query_cntx->pattern;
                len = contact_filter->query_cntx->pattern_len;
                if (src[0] == '+' && dest[0] == '0')
                {
                    src++;
                    dest++;
                    len--;
                }
                if (mmi_wcsncmp(src, dest, len) == 0)
                {
                    srv_phb_query_add_match_clg(handle, cnf_data.log_ids[i]);
                    if (contact_filter->query_cntx->query_field & MMI_PHB_CONTACT_FIELD_NUMBER)
                    {
                        query_handle->match_info.matched_field = MMI_PHB_CONTACT_FIELD_ID_NUMBER;
                    }
                    else
                    {
                        query_handle->match_info.matched_field = MMI_PHB_CONTACT_FIELD_ID_NAME;
                    }
                    query_handle->match_info.is_sequence = MMI_TRUE;
                    query_handle->match_info.sequence_start = 0;
                    query_handle->match_info.sequence_len = (U8)contact_filter->query_cntx->pattern_len;
                }
            }
            if (cnf_data.next_start_elm == SRV_CLOG_INVALID_ELM)
            {
                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_contact_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  UI_buffer_type
 * RETURNS
 *  S32
 *****************************************************************************/
static MMI_BOOL srv_phb_check_contact_filter(srv_phb_contact_filter filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_filter_struct* contact_filter = (srv_phb_contact_filter_struct*)filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (contact_filter
        && contact_filter->query_cntx
        && (contact_filter->query_cntx->type == SRV_PHB_QUERY_TYPE_DS)
        && !contact_filter->query_cntx->pattern_len)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

#endif


/*****************************************************************************
 * FUNCTION
 *  srv_phb_filter_convert_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_phb_filter_convert_name(
            WCHAR* name,
            srv_phb_cov_name_cntx_struct* cntx,
            srv_phb_query_cache_struct* cache,
            U16 pattern_len,
            srv_phb_query_match_info_struct* match_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR code;
    MMI_BOOL new_word;
    srv_phb_pinyin_cache_struct* pinyin;
    S32 i;
    U8 index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx->conv_len >= pattern_len)
    {
        cntx->wait_new = MMI_TRUE;
        do
        {
            cntx->conv_start = SRV_PHB_CIRCLE_INCREASE_ID(
                                    cntx->conv_start,
                                    1,
                                    (SRV_PHB_QUERY_PATTERN_LEN * MMI_PHB_MAX_PINYIN_LENGTH));
            cntx->conv_len--;
            if (cntx->conv_char_pos[cntx->conv_start])
            {
                match_info->sequence_len -= (cntx->conv_char_pos[cntx->conv_start] - 1 - match_info->sequence_start);
                match_info->sequence_start = cntx->conv_char_pos[cntx->conv_start] - 1;
                cntx->wait_new = MMI_FALSE;
                break;
            }
        } while (cntx->conv_len);
    }
    
    if (cntx->f_char_len >= pattern_len)
    {
        cntx->f_char_start = SRV_PHB_CIRCLE_INCREASE_ID(cntx->f_char_start, 1, SRV_PHB_QUERY_PATTERN_LEN);
        cntx->f_char_len--;

        /* set the last mask as 0 */
        for (i = 0; i < ((SRV_PHB_QUERY_PATTERN_LEN + 7) / 8); i++)
        {
            if (match_info->mask[i])
            {
                match_info->mask[i] &= (match_info->mask[i] - 1);
                break;
            }
        }
    }

    while (cntx->conv_len < pattern_len && cntx->f_char_len < pattern_len)
    {
        code = name[cntx->name_offset];
        
        if (!code)
        {
            return MMI_FALSE;
        }
        
        if (cache->cov_pinyin && srv_phb_check_chinese_char(code))
        {
            cntx->is_new = MMI_TRUE;
            new_word = MMI_TRUE;
            pinyin = NULL;
            for (i = 0; i < MMI_PHB_PINYIN_CACHE_COUNT; i++)
            {
                if (code == cache->pinyin_cache[i].ori_char || !(cache->pinyin_cache[i].ori_char))
                {
                    pinyin = &(cache->pinyin_cache[i]);
                    if (code == pinyin->ori_char)
                    {
                        break;
                    }
                }
            }
            if (!pinyin)
            {
                pinyin = &(cache->pinyin_cache[min(cntx->name_offset, (MMI_PHB_PINYIN_CACHE_COUNT - 1))]);
            }
            if (code != pinyin->ori_char)
            {
                pinyin->ori_char = code;
                pinyin->len = srv_phb_convert_to_spelling(
                                                IMM_INPUT_MODE_QUICK_SEARCH_PINYIN,
                                                code,
                                                (WCHAR*)(pinyin->pinyin),
                                                MMI_PHB_QSEARCH_LENGTH);
            }
            if (cntx->conv_char_pos[cntx->conv_start])
            {
                match_info->sequence_len++;
            }
            else
            {
                match_info->sequence_len = 1;
                match_info->sequence_start = cntx->name_offset;
            }
            for (i = 0; i < pinyin->len; i++)
            {             
                index = SRV_PHB_CIRCLE_INCREASE_ID(
                                cntx->conv_start,
                                cntx->conv_len,
                                (SRV_PHB_QUERY_PATTERN_LEN * MMI_PHB_MAX_PINYIN_LENGTH));
                cntx->conv_buffer[index] = pinyin->pinyin[i];
                if (i)
                {
                    cntx->conv_char_pos[index] = 0;
                }
                else
                {
                    cntx->conv_char_pos[index] = cntx->name_offset + 1;
                }   
                cntx->conv_len++;
            }

            index = SRV_PHB_CIRCLE_INCREASE_ID(cntx->f_char_start, cntx->f_char_len, SRV_PHB_QUERY_PATTERN_LEN);
            cntx->f_char_buffer[index] = pinyin->pinyin[0];
            cntx->f_char_len++;
            SRV_PHB_SET_BIT_MASK(match_info->mask, cntx->name_offset);
            cntx->wait_new = MMI_FALSE;
        }
        else
        {
            if (!cntx->wait_new || cntx->is_new)
            {
                index = SRV_PHB_CIRCLE_INCREASE_ID(
                                cntx->conv_start,
                                cntx->conv_len,
                                (SRV_PHB_QUERY_PATTERN_LEN * MMI_PHB_MAX_PINYIN_LENGTH));
                
                cntx->conv_buffer[index] = code;
                if (cntx->is_new)
                {
                    if (cntx->conv_char_pos[cntx->conv_start])
                    {
                        match_info->sequence_len++;
                    }
                    else
                    {
                        match_info->sequence_len = 1;
                        match_info->sequence_start = cntx->name_offset;
                    }
                    cntx->wait_new = MMI_FALSE;
                    cntx->conv_char_pos[index] = cntx->name_offset + 1;
                }
                else
                {
                    match_info->sequence_len++;
                    cntx->conv_char_pos[index] = 0;
                }
                cntx->conv_len++;
            }
            if (cntx->is_new)
            {
                index = SRV_PHB_CIRCLE_INCREASE_ID(cntx->f_char_start, cntx->f_char_len, SRV_PHB_QUERY_PATTERN_LEN);
                cntx->f_char_buffer[index] = code;
                SRV_PHB_SET_BIT_MASK(match_info->mask, cntx->name_offset);
                cntx->f_char_len++;
            }
            if ((code == L' ') || (code == L';') || (code == L',') || srv_phb_check_punctuation_char(code))
            {
                new_word = MMI_TRUE;
            }
            else
            {
                new_word = MMI_FALSE;
            }
        }
        cntx->is_new = new_word;
        if (cntx->conv_len != 0 || new_word == MMI_FALSE)
        {
            cntx->name_offset++;
        }
    }
    if (cntx->conv_len < pattern_len && cntx->f_char_len < pattern_len)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_filter_compare_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_phb_filter_compare_name(
                WCHAR* name,
                WCHAR* pattern,
                U16 pattern_len,
                srv_phb_query_cache_struct* cache,
                srv_phb_query_type_enum type,
                srv_phb_query_match_info_struct* match_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case SRV_PHB_QUERY_TYPE_PARTIAL:
    #ifdef __MMI_DIALER_SEARCH__
        case SRV_PHB_QUERY_TYPE_DS:
    #endif
        {
            srv_phb_cov_name_cntx_struct cntx;
            memset(&cntx, 0, sizeof(srv_phb_cov_name_cntx_struct));
            memset(match_info, 0, sizeof(srv_phb_query_match_info_struct));
            cntx.is_new = MMI_TRUE;
            while (srv_phb_filter_convert_name(name, &cntx, cache, pattern_len, match_info))
            {
                if (type == SRV_PHB_QUERY_TYPE_PARTIAL)
                {
                    if ((cntx.conv_len >= pattern_len) &&
                        srv_phb_wcs_cirlcle_ncmp(
                            cntx.conv_buffer,
                            cntx.conv_start,
                            (SRV_PHB_QUERY_PATTERN_LEN * MMI_PHB_MAX_PINYIN_LENGTH),
                            pattern,
                            pattern_len))
                    {
                        match_info->is_sequence = MMI_TRUE;
                        return MMI_TRUE;
                    }
                    if ((cntx.f_char_len >= pattern_len) &&
                        srv_phb_wcs_cirlcle_ncmp(
                            cntx.f_char_buffer,
                            cntx.f_char_start,
                            SRV_PHB_QUERY_PATTERN_LEN,
                            pattern,
                            pattern_len))
                    {
                        match_info->is_sequence = MMI_FALSE;
                        return MMI_TRUE;
                    }
                }
            #ifdef __MMI_DIALER_SEARCH__
                else
                {
                    if ((cntx.conv_len >= pattern_len) &&
                        srv_phb_ds_wcs_cirlcle_ncmp(
                            cntx.conv_buffer,
                            cntx.conv_start,
                            (SRV_PHB_QUERY_PATTERN_LEN * MMI_PHB_MAX_PINYIN_LENGTH),
                            pattern,
                            pattern_len,
                            &(cache->key_info)))
                    {
                        match_info->is_sequence = MMI_TRUE;
                        return MMI_TRUE;
                    }
                    if ((cntx.f_char_len >= pattern_len) &&
                        srv_phb_ds_wcs_cirlcle_ncmp(
                            cntx.f_char_buffer,
                            cntx.f_char_start,
                            SRV_PHB_QUERY_PATTERN_LEN,
                            pattern,
                            pattern_len,
                            &(cache->key_info)))
                    {
                        match_info->is_sequence = MMI_FALSE;
                        return MMI_TRUE;
                    }
                }
            #endif /* __MMI_DIALER_SEARCH__ */
            }
            break;
        }
        case SRV_PHB_QUERY_TYPE_FULL:
            if (srv_phb_wcs_n_cmp(name, pattern, pattern_len) == 0)
            {
                match_info->is_sequence = MMI_TRUE;
                match_info->sequence_start = 0;
                match_info->sequence_len = (U8)pattern_len;
                return MMI_TRUE;
            }
            break;
            
        default:
            break;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_filter_contact_by_pattern
 * DESCRIPTION
 *  filter a contact by query pattern
 * PARAMETERS
 *  id                       : [IN]      contact's store_index
 *  group_cntx          : [IN]      group condition
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE                  :                    matched
 *  MMI_FALSE                 :                    not matched
 *****************************************************************************/
static MMI_BOOL srv_phb_filter_contact_by_query(mmi_phb_contact_id id, srv_phb_query_cntx_struct* query_cntx, srv_phb_query_result_struct* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 field_mask = srv_phb_datamgr_get_field_mask(id);
    MMI_BOOL result = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((query_cntx->query_field & MMI_PHB_CONTACT_FIELD_NAME) &&
        (field_mask & MMI_PHB_CONTACT_FIELD_NAME))
    {
        WCHAR name[MMI_PHB_NAME_LENGTH + 1];
        srv_phb_datamgr_get_name(id, (WCHAR*)name, MMI_PHB_NAME_LENGTH);
        if (srv_phb_filter_compare_name(
                (WCHAR*)name,
                (WCHAR*)query_cntx->pattern,
                query_cntx->pattern_len,
                &(query_cntx->cache),
                query_cntx->type,
                &(info->match_info)))
        {
            info->match_info.matched_field = MMI_PHB_CONTACT_FIELD_ID_NAME;
            return MMI_TRUE;
        }
    }

    if ((query_cntx->query_field & MMI_PHB_CONTACT_FIELD_NUMBER) &&
        (field_mask & MMI_PHB_CONTACT_FIELD_NUMBER))
    {
        U8 i;
        CHAR* src;
        U16 len = query_cntx->pattern_len;
        WCHAR* dest = query_cntx->pattern;
        info->number_count = 0;
        info->match_info.matched_field = MMI_PHB_CONTACT_FIELD_ID_NUMBER;
        info->match_info.is_sequence = MMI_TRUE;
        info->match_info.sequence_start = 0;
        info->match_info.sequence_len = (U8)query_cntx->pattern_len;
        if (id < MMI_PHB_PHONE_ENTRIES)
        {
            mmi_phb_optional_fields_struct* optional_fields_data = NULL;
            for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
            {
                if (g_srv_phb_sse_cntx.num_cache[MMI_PHB_NUMBER_FIELD_COUNT * id + i][0] != 0xFF &&
                    srv_phb_bcd_num_cmp(
                        g_srv_phb_sse_cntx.num_cache[MMI_PHB_NUMBER_FIELD_COUNT * id + i],
                        (WCHAR*)(query_cntx->pattern),
                        query_cntx->pattern_len > SRV_PHB_NUM_CACHE_LEN ? SRV_PHB_NUM_CACHE_LEN : query_cntx->pattern_len))
                {
                    if (query_cntx->pattern_len > SRV_PHB_NUM_CACHE_LEN)
                    {
                        if (!optional_fields_data)
                        {
                            optional_fields_data = srv_phb_get_phone_optional_field(id);
                        }
                        src = (CHAR *)(optional_fields_data->num[i].number);
                        if (src[0] == '+' && dest[0] == '0')
                        {
                            src++;
                            dest++;
                            len--;
                        }
                        if (srv_phb_acs_wcs_n_cmp(src, dest, len) != 0)
                        {
                            continue;
                        }
                    }

                    info->number_id[info->number_count++] = i;
                    result = MMI_TRUE;
                }
            }
        }
    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        else if (id >= MMI_PHB_BASIC_ENTRIES && id < MMI_PHB_ENTRIES)
        {
            for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i ++)
            {
                src = srv_phb_get_tcard_number(id, i, NULL, NULL, NULL);
                if (!src)
                {
                    continue;
                }
                if (src[0] == '+' && dest[0] == '0')
                {
                    src++;
                    dest++;
                    len--;
                }
                if (srv_phb_acs_wcs_n_cmp(src, dest, len) != 0)
                {
                    continue;
                }
                info->number_id[info->number_count++] = i;
                result = MMI_TRUE;

            }
        }
    #endif /* __SRV_PHB_TCARD_STORAGE_SUPPORT__ */
        else
        {
            for (i = 0; i < MMI_PHB_SIM_NUM_COUNT; i++)
            {
                src = srv_phb_get_sim_number(id, i, NULL);
                if (!src)
                {
                    continue;
                }
                if (src[0] == '+' && dest[0] == '0')
                {
                    src++;
                    dest++;
                    len--;
                }
                if (srv_phb_acs_wcs_n_cmp(src, dest, len) != 0)
                {
                    continue;
                }
                info->number_id[info->number_count++] = i;
                result = MMI_TRUE;
            }
        }
    }    
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_init_contact_filter_ex
 * DESCRIPTION
 *  init query async context & query mem entry
 * PARAMETERS
 *  filter                       : [IN]      srv_phb_contact_filter_struct
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sse_init_contact_filter_ex(srv_phb_contact_filter_struct *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    // init query async context
    memset(&(filter->query_async_cntx), 0x00, sizeof(srv_phb_query_async_context_struct));

    // init query mem entry
    memset(&(filter->mem_entry), 0x00, sizeof(srv_phb_query_mem_entry_struct));
}


/* extern api */

/*****************************************************************************
 * FUNCTION
 *  srv_phb_create_contact_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_contact_filter srv_phb_create_contact_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_filter_struct* filter = srv_phb_mem_malloc(sizeof(srv_phb_contact_filter_struct), SRV_PHB_MEMORY_TYPE_ADM);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filter->field_type = MMI_PHB_CONTACT_FIELD_ALL;
    filter->storage_mask = SRV_PHB_STORAGE_MASK_ALL;
    filter->query_cntx = NULL;
#ifdef __MMI_PHB_CALLER_GROUP__
    filter->group_cntx = NULL;
#endif

    srv_phb_sse_init_contact_filter_ex(filter);

    return filter;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_create_contact_filter_by_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_contact_filter srv_phb_create_contact_filter_by_storage(U8 storage_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_filter_struct* filter = srv_phb_mem_malloc(sizeof(srv_phb_contact_filter_struct), SRV_PHB_MEMORY_TYPE_ADM);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filter->field_type = MMI_PHB_CONTACT_FIELD_ALL;
    filter->storage_mask = storage_mask;
    filter->query_cntx = NULL;
#ifdef __MMI_PHB_CALLER_GROUP__
    filter->group_cntx = NULL;
#endif

    srv_phb_sse_init_contact_filter_ex(filter);

    return filter;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_create_contact_filter_by_filed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_contact_filter srv_phb_create_contact_filter_by_filed(U32 field_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_filter_struct* filter = srv_phb_mem_malloc(sizeof(srv_phb_contact_filter_struct), SRV_PHB_MEMORY_TYPE_ADM);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filter->field_type = field_type;
    filter->storage_mask = SRV_PHB_STORAGE_MASK_ALL;
    filter->query_cntx = NULL;
#ifdef __MMI_PHB_CALLER_GROUP__
    filter->group_cntx = NULL;
#endif

    srv_phb_sse_init_contact_filter_ex(filter);

    return filter;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_free_contact_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_free_contact_filter(srv_phb_contact_filter filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_filter_struct* temp = (srv_phb_contact_filter_struct*)filter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (temp)
    {
        if (temp->query_cntx)
        {
            if (temp->query_cntx->cache.buffer_len)
            {
                srv_phb_mem_free(temp->query_cntx->cache.buffer_1);
                srv_phb_mem_free(temp->query_cntx->cache.buffer_2);
            }
            if (temp->query_cntx->cache.key_info.ime_table)
            {
                srv_phb_mem_free(temp->query_cntx->cache.key_info.ime_table);
            }
            srv_phb_mem_free(temp->query_cntx);
        }
    #ifdef __MMI_PHB_CALLER_GROUP__
        if (temp->group_cntx)
        {
            if (temp->group_cntx->group_field)
            {
                srv_phb_mem_free(temp->group_cntx->group_field);
            }
            srv_phb_mem_free(temp->group_cntx);
        }
    #endif /* __MMI_PHB_CALLER_GROUP__ */
        srv_phb_mem_free(temp);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_free_query_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_free_query_entry(srv_phb_contact_filter filter, srv_phb_query_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_free_query_handle(handle);
    srv_phb_free_contact_filter(filter);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_contact_filter_set_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_contact_filter_set_storage(srv_phb_contact_filter filter, U8 storage_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filter)
    {
        ((srv_phb_contact_filter_struct*)filter)->storage_mask = storage_mask;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_storage_condition
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_contact_filter_set_field(srv_phb_contact_filter filter, U32 field_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filter)
    {
        ((srv_phb_contact_filter_struct*)filter)->field_type = field_type;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_contact_filter_set_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_contact_filter_set_query(srv_phb_contact_filter filter, WCHAR* pattern, U32 query_field, srv_phb_query_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filter && pattern)
    {
        srv_phb_query_cntx_struct* query_cntx = ((srv_phb_contact_filter_struct*)filter)->query_cntx;
        if (!query_cntx)
        {
            query_cntx = srv_phb_mem_malloc(sizeof(srv_phb_query_cntx_struct), SRV_PHB_MEMORY_TYPE_ADM);
            ((srv_phb_contact_filter_struct*)filter)->query_cntx = query_cntx;
            memset(&(query_cntx->cache), 0, sizeof(srv_phb_query_cache_struct));
        }
        query_cntx->type = type;
        query_cntx->query_field = (query_field & MMI_PHB_CONTACT_FIELD_QUERY);
        mmi_wcsncpy((WCHAR*)(query_cntx->pattern), pattern, SRV_PHB_QUERY_PATTERN_LEN);
    #ifdef __MMI_DIALER_SEARCH__
        if (query_cntx->type == SRV_PHB_QUERY_TYPE_DS)
        {
            U32 i = 0, j = 0;
            while (query_cntx->pattern[i])
            {
                if (isdigit(query_cntx->pattern[i]))
                {
                     query_cntx->pattern[j++] = query_cntx->pattern[i];
                }
                else if (i == 0 && query_cntx->pattern[i] == '+')
                {
                    query_cntx->pattern[j++] = '0';
                }
                i++;
            }
            query_cntx->pattern[j] = 0;
        }
    #endif /* __MMI_DIALER_SEARCH__ */
        query_cntx->pattern_len = mmi_wcslen((WCHAR*)(query_cntx->pattern));
        
        if (query_cntx->cache.buffer_len < (query_cntx->pattern_len + MMI_PHB_MAX_PINYIN_LENGTH))
        {
            if (query_cntx->cache.buffer_len)
            {
                srv_phb_mem_free(query_cntx->cache.buffer_1);
                srv_phb_mem_free(query_cntx->cache.buffer_2);
            }
            query_cntx->cache.buffer_len = query_cntx->pattern_len  + MMI_PHB_MAX_PINYIN_LENGTH;
            query_cntx->cache.buffer_1 = 
                srv_phb_mem_malloc(sizeof(WCHAR) * query_cntx->cache.buffer_len, SRV_PHB_MEMORY_TYPE_ADM);
            
            query_cntx->cache.buffer_2 =
                srv_phb_mem_malloc(sizeof(WCHAR) * query_cntx->cache.buffer_len, SRV_PHB_MEMORY_TYPE_ADM);
        }
        if (srv_phb_is_chinese_string((WCHAR*)(query_cntx->pattern)))
        {
            query_cntx->cache.cov_pinyin = MMI_FALSE; /* if pattern have chinese, not convert to pinyin */
        }
        else
        {
            query_cntx->cache.cov_pinyin = MMI_TRUE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_contact_filter_set_mem_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_contact_filter_set_mem_entry(srv_phb_contact_filter filter, srv_phb_query_mem_alloc_func_type alloc_func, 
                        srv_phb_query_mem_free_func_type free_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_mem_entry_struct *mem_entry_p = &(((srv_phb_contact_filter_struct *) filter)->mem_entry);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_SET_MEM_ENTRY, filter, alloc_func, free_func, user_data);
    mem_entry_p->mem_alloc_func = alloc_func;
    mem_entry_p->mem_free_func = free_func;
    mem_entry_p->user_data = user_data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_contact_filter_set_mem_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_contact_filter_set_query_entry(srv_phb_contact_filter filter, srv_phb_query_async_func_type callback_func,
                        U16 start_index, U16 query_time, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_query_async_context_struct *query_async_cntx_p = &(((srv_phb_contact_filter_struct *) filter)->query_async_cntx);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_SET_QUERY_ENTRY, filter, callback_func, start_index, query_time, user_data);
    query_async_cntx_p->callback_func = callback_func;
    query_async_cntx_p->start_index = start_index;
    query_async_cntx_p->query_time = query_time;
    query_async_cntx_p->user_data = user_data;
}


#ifdef __MMI_PHB_CALLER_GROUP__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_contact_filter_set_group
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_contact_filter_set_group(srv_phb_contact_filter filter, U8 group_id, MMI_BOOL is_equal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filter)
    {
        srv_phb_group_cntx_struct* group_cntx = ((srv_phb_contact_filter_struct*)filter)->group_cntx;
        if (!group_cntx)
        {
            group_cntx = srv_phb_mem_malloc(sizeof(srv_phb_group_cntx_struct), SRV_PHB_MEMORY_TYPE_ADM);
            ((srv_phb_contact_filter_struct*)filter)->group_cntx = group_cntx;
            group_cntx->group_field = NULL;
        }
        group_cntx->is_equal = is_equal;
        memset(group_cntx->group_mask, 0, sizeof(group_cntx->group_mask));
    #if defined(__MMI_PHB_USIM_SUPPORT__) || defined(__SRV_PHB_TCARD_STORAGE_SUPPORT__)
        group_cntx->storage = srv_phb_get_storage_by_group_id(group_id);
        if (group_id >= MMI_PHB_GROUP_COUNT + MMI_PHB_GROUP_USIM_COUNT)
        {
            group_id -= (MMI_PHB_GROUP_COUNT + MMI_PHB_GROUP_USIM_COUNT);
        }
        else if (group_id >= MMI_PHB_GROUP_COUNT)
        {
            group_id -= (MMI_PHB_GROUP_COUNT + PHB_MAX_ASSOCIATE_GRP * srv_phb_get_sim_id(group_cntx->storage));
        }
    #endif /* defined(__MMI_PHB_USIM_SUPPORT__) || defined(__SRV_PHB_TCARD_STORAGE_SUPPORT__) */
        group_cntx->group_mask[group_id / 8] |= (1 << (group_id % 8));
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_contact_filter_set_group_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_contact_filter_set_group_ex(srv_phb_contact_filter filter, srv_phb_group_struct* group_ids, MMI_BOOL is_equal)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filter && group_ids)
    {
        srv_phb_group_cntx_struct* group_cntx = ((srv_phb_contact_filter_struct*)filter)->group_cntx;
        S32 i = 0;
        if (!group_cntx)
        {
            group_cntx = srv_phb_mem_malloc(sizeof(srv_phb_group_cntx_struct), SRV_PHB_MEMORY_TYPE_ADM);
            ((srv_phb_contact_filter_struct*)filter)->group_cntx = group_cntx;
            group_cntx->group_field = NULL;
        }
        group_cntx->is_equal = is_equal;
        memset(group_cntx->group_mask, 0, sizeof(group_cntx->group_mask));
        if (group_ids->group_count > MMI_PHB_GROUP_COUNT)
        {
            group_ids->group_count = MMI_PHB_GROUP_COUNT;
        }
        for (; i < group_ids->group_count; i++)
        {
            if (group_ids->group_id[i] < MMI_PHB_GROUP_COUNT)
            {
                group_cntx->group_mask[group_ids->group_id[i] / 8] |= (1 << (group_ids->group_id[i] % 8));
            }
        }
    }

}
#endif /* __MMI_PHB_CALLER_GROUP__ */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_contact_filter_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filter                 : [IN]      filter
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_init_contact_filter_cache(srv_phb_contact_filter filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_filter_struct* contact_filter = (srv_phb_contact_filter_struct*)filter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (contact_filter)
    {
    #ifdef __MMI_PHB_CALLER_GROUP__
        if (contact_filter->group_cntx)
        {
            srv_phb_group_cntx_struct* group_cntx = contact_filter->group_cntx;
        #ifdef __MMI_PHB_USIM_SUPPORT__
            if (group_cntx->storage >= PHB_STORAGE_SIM && group_cntx->storage <= PHB_STORAGE_SIM4)
            {
                if (!(group_cntx->group_field))
                {
                    group_cntx->group_field = srv_phb_mem_malloc(
                                                    srv_phb_get_sim_total(group_cntx->storage) * sizeof(srv_phb_sim_grp_struct), 
                                                    SRV_PHB_MEMORY_TYPE_ADM);
                }
                srv_phb_sim_get_grp_cache(srv_phb_get_sim_id(group_cntx->storage), group_cntx->group_field);
            }
            else
        #endif /* __MMI_PHB_USIM_SUPPORT__ */
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
            if (group_cntx->storage == PHB_STORAGE_TCARD)
            {
                if (!(group_cntx->group_field))
                {
                    group_cntx->group_field = srv_phb_mem_malloc(
                                                    MMI_PHB_TCARD_ENTRIES * sizeof(U32), 
                                                    SRV_PHB_MEMORY_TYPE_ADM);
                }
                srv_phb_get_tcard_all_group_field((U32 *)(group_cntx->group_field));
            }
            else
        #endif /* __SRV_PHB_TCARD_STORAGE_SUPPORT__ */
            {
                if (!(group_cntx->group_field))
                {
                    group_cntx->group_field = srv_phb_mem_malloc(
                                                    NVRAM_EF_PHB_GROUP_FIELD_TOTAL * NVRAM_EF_PHB_GROUP_FIELD_SIZE, 
                                                    SRV_PHB_MEMORY_TYPE_ADM);
                }
                srv_phb_get_all_phone_group_field(group_cntx->group_field);
            }  
        }
    #endif /* __MMI_PHB_CALLER_GROUP__ */
    #if defined(__MMI_DIALER_SEARCH__) && !defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        if (contact_filter->query_cntx && contact_filter->query_cntx->type == SRV_PHB_QUERY_TYPE_DS)
        {
            srv_phb_key_cache_struct* key_cache = &(contact_filter->query_cntx->cache.key_info);
            if (!(key_cache->ime_table))
            {
                U32 size = mmi_ime_multitap_get_alphabetic_keymap_table_size();
                S32 i;
                key_cache->ime_table = srv_phb_mem_malloc(
                                                size,
                                                SRV_PHB_MEMORY_TYPE_ADM);
                mmi_ime_multitap_create_alphabetic_keymap_table(key_cache->ime_table, size);
            
                for (i = 0; i < 10; i++)
                {
                    key_cache->keymap[i] = 
                        mmi_ime_multitap_get_keymap((U16*)key_cache->ime_table, (U16)(KEY_0 + i), size);
                    key_cache->keysize[i] = mmi_wcslen(key_cache->keymap[i]);
                }
            }
        }
    #endif /* defined(__MMI_DIALER_SEARCH__) && !defined(__MMI_QWERTY_KEYPAD_SUPPORT__) */
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_filter_contact
 * DESCRIPTION
 *  filter a contact
 * PARAMETERS
 *  id                 : [IN]      contact's store_index
 *  filter             : [IN]      contact filter
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE                  :                    matched
 *  MMI_FALSE                 :                    not matched
 *****************************************************************************/
MMI_BOOL srv_phb_filter_contact(mmi_phb_contact_id id, srv_phb_contact_filter filter, srv_phb_query_result_struct* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_filter_struct* contact_filter = (srv_phb_contact_filter_struct*)filter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //info->match_info.matched_field = 0;
    //info->match_info.sequence_start = 0;
    //info->match_info.sequence_len = 0;
    memset(&info->match_info, 0x0, sizeof(srv_phb_query_match_info_struct));

    if (contact_filter)
    {
        // async query
        if (contact_filter->query_cntx)
        {
            contact_filter->query_cntx->match_field = contact_filter->query_async_cntx.now_match_field;
        }
        if (!srv_phb_filter_contact_by_normal(id, contact_filter))
        {
            return MMI_FALSE;
        }
    #ifdef __MMI_PHB_CALLER_GROUP__
        if (contact_filter->group_cntx && !srv_phb_filter_contact_by_group(id, contact_filter->group_cntx))
        {
            return MMI_FALSE;
        }
    #endif /* __MMI_PHB_CALLER_GROUP__ */
        if (contact_filter->query_cntx && contact_filter->query_cntx->pattern[0] && !srv_phb_filter_contact_by_query(id, contact_filter->query_cntx, info))
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_gen_alpha_index
 * DESCRIPTION
 *  gen a contact's alpha index
 * PARAMETERS
 *  id              : [IN]        contact id
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_phb_sse_gen_alpha_index(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = 0;
    U16 name[2];
    U16 temp_name[2];    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_datamgr_get_name(id, name, 1);
    temp_name[0] = srv_phb_convert_to_latin(name[0]);
    if ((temp_name[0] >= L'A') && (temp_name[0] <= L'Z'))
    {
        index = ((U8)(temp_name[0] - L'A')) + 1;
    }
    if ((name[0] >= L'a') && (name[0] <= L'z'))    /* lower case */
    {
        index = ((U8)(name[0] - L'a')) + 1;
    }
    else if ((name[0] >= L'A') && (name[0] <= L'Z'))       /* upper case */
    {
        index = ((U8)(name[0] - L'A')) + 1;
    }
#if defined(__MMI_PHB_PINYIN_SORT__)
    else if (name[0])    /* A 2-bytes character */
    {
        name[0] = srv_phb_sse_get_first_pinyin_char(id);
        if ((name[0] >= L'a') && (name[0] <= L'z'))
        {
            index = ((U8)(name[0] - L'a')) + 1;
        }
    }
#endif /* defined(__MMI_PHB_PINYIN_SORT__) */
    return index;
}


void srv_phb_sse_query(srv_phb_query_req_struct* req, srv_phb_query_handle handle);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_async_query_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_sse_async_query_hdlr(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_sse_query_async_struct *query_async_handle_p = (srv_phb_sse_query_async_struct *) user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // don't query continue if pid is removed
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_QUERY_ASYNC_HDLR_DATA, user_data, query_async_handle_p->pid, query_async_handle_p->req,
                query_async_handle_p->handle, query_async_handle_p->user_data);
    if (srv_phb_query_search_pid(query_async_handle_p->pid))
    {
        MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_QUERY_ASYNC_HDLR_CD);
        srv_phb_sse_query(query_async_handle_p->req, query_async_handle_p->handle);
    }
    else
    {
        MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_QUERY_ASYNC_HDLR_CANCEL, query_async_handle_p->pid);
    }

    srv_phb_mem_free(query_async_handle_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_start_async_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_sse_start_async_query(srv_phb_query_req_struct *req, srv_phb_query_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_sse_query_async_struct *query_async_handle = NULL;
    srv_phb_query_struct *handle_p = (srv_phb_query_struct *) handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    query_async_handle = srv_phb_mem_malloc(sizeof(srv_phb_sse_query_async_struct), SRV_PHB_MEMORY_TYPE_CTR);

    // set async event user data
    query_async_handle->handle = handle_p;
    query_async_handle->req = req;
    query_async_handle->pid = handle_p->pid;
    query_async_handle->user_data = NULL;

    srv_phb_async_event_interface(srv_phb_sse_async_query_hdlr, query_async_handle);

    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_START_ASYNC_QUERY, req, handle, handle_p->pid, query_async_handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_async_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_sse_async_query(srv_phb_query_req_struct *req, srv_phb_query_struct *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_sse_query_async_struct *query_async_handle = NULL;
    srv_phb_query_async_context_struct *query_async_cntx_p = NULL;
    srv_phb_contact_filter_struct *filter = (srv_phb_contact_filter_struct *) req->filter;
    srv_phb_query_async_cb_result_struct ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    query_async_handle = srv_phb_mem_malloc(sizeof(srv_phb_sse_query_async_struct), SRV_PHB_MEMORY_TYPE_CTR);

    // set async event user data
    query_async_handle->handle = handle;
    query_async_handle->req = req;
    query_async_handle->pid = handle->pid;
    query_async_handle->user_data = NULL;

    query_async_cntx_p = &(filter->query_async_cntx);
    // call back
    ret.user_data = query_async_cntx_p->user_data;
    ret.result = 0;

    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_QUERY_ASYNC_CB, ret.result, ret.user_data, query_async_cntx_p->callback_func);
    query_async_cntx_p->callback_func(&ret);

    srv_phb_async_event_interface(srv_phb_sse_async_query_hdlr, query_async_handle);
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_QUERY_ASYNC_PROCESS, query_async_handle->pid, query_async_handle->req,
                query_async_handle->handle, query_async_handle->user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_phb_query_req_struct        : [IN]    req
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sse_query(srv_phb_query_req_struct* req, srv_phb_query_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 count;
    S32 i, j, start_index = 0;
    U32 query_time = 0;
    mmi_phb_contact_id id;
    srv_phb_query_result_struct info;
    mmi_phb_contact_field_id_enum align_field;
    srv_phb_query_async_context_struct *query_async_handle = NULL;
    srv_phb_contact_filter_struct *filter = (srv_phb_contact_filter_struct *) req->filter;
    srv_phb_query_struct *query_handle = (srv_phb_query_struct *)handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_QUERY, req->alpha_table, req->align_field, req->item_order);
    if (!req)
    {
        return;
    }

    // asm copy mem entry
    query_handle->mem_entry.mem_alloc_func = filter->mem_entry.mem_alloc_func;
    query_handle->mem_entry.mem_free_func = filter->mem_entry.mem_free_func;
    query_handle->mem_entry.user_data = filter->mem_entry.user_data;
    // async query
    query_async_handle = &(filter->query_async_cntx);
    query_async_handle->now_match_field = query_handle->match_field;
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_QUERY_ASYNC_HANDLE_START, query_async_handle->query_index, query_async_handle->start_index,
                query_async_handle->query_time, query_async_handle->now_match_field, query_async_handle->callback_func, query_async_handle->user_data);
#ifdef __MMI_DIALER_SEARCH__
    if (!srv_phb_check_contact_filter(req->filter))
    {
        if (query_async_handle->callback_func)
        {
            srv_phb_query_async_cb_result_struct ret;
            S32 ret_pid = -1;

            ret.user_data = query_async_handle->user_data;
            ret.result = 1;

            MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_QUERY_N_DIALER_SEARCH, ret.result, ret.user_data, query_async_handle->callback_func);
            query_async_handle->callback_func(&ret);

            ret_pid = srv_phb_query_remove_pid(query_handle->pid); // finish query, then remove pid
            query_handle->pid = 0;
            MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_QUERY_NDS, query_handle->pid, ret_pid);
        }
        MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_QUERY_NDS_NULL);
        return;
    }

    if (query_async_handle->callback_func)
    {
        if (query_async_handle->query_index < query_async_handle->query_time && query_async_handle->now_match_field == 0 /* now match name field*/)
        {
           srv_phb_query_calllog(handle, req->filter);
           MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_QUERY_DS_CALLBACK);
        }
    }
    else
    {
        srv_phb_query_calllog(handle, req->filter);
        MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_QUERY_DS_N_CALLBACK);
    }
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_QUERY_CLG_END);
#endif /* __MMI_DIALER_SEARCH__ */

    if (query_async_handle->callback_func)
    {
        start_index = query_async_handle->query_index;
    }

    // now_match_field = 0, match name field
    if (query_async_handle->now_match_field == 0)
    {
        for (i = start_index; i < g_srv_phb_sse_cntx.entry_count; i++)
        {
            id = g_srv_phb_sse_cntx.name_index[i];
            if (srv_phb_filter_contact(id, req->filter, &info))
            {
                switch (info.match_info.matched_field)
                {
                    case MMI_PHB_CONTACT_FIELD_ID_NUMBER:
                        break;

                    case MMI_PHB_CONTACT_FIELD_ID_NAME:
                    default:
                        if (req->align_field == MMI_PHB_CONTACT_FIELD_NAME)
                        {
                            if (srv_phb_datamgr_get_num_count(id))
                            {
                                align_field = MMI_PHB_CONTACT_FIELD_ID_NUMBER;
                            }
                            else if (srv_phb_datamgr_get_email_count(id))
                            {
                                align_field = MMI_PHB_CONTACT_FIELD_ID_EMAIL;
                            }
                            else
                            {
                                align_field = MMI_PHB_CONTACT_FIELD_ID_NAME;
                            }
                            srv_phb_query_add_match_item(
                                    handle,
                                    id,
                                    align_field,
                                    0,
                                    &(info.match_info),
                                    req->item_order);
                        }
                        else
                        {
                            MMI_BOOL add_flag = MMI_FALSE;
                            if (req->align_field & MMI_PHB_CONTACT_FIELD_NUMBER)
                            {
                                count = srv_phb_datamgr_get_num_count(id);
                                for (j = 0; j < count; j++)
                                {
                                    srv_phb_query_add_match_item(
                                        handle,
                                        id,
                                        MMI_PHB_CONTACT_FIELD_ID_NUMBER,
                                        j,
                                        &(info.match_info),
                                        req->item_order);
                                    add_flag = MMI_TRUE;
                                }
                            }
                            if (req->align_field & MMI_PHB_CONTACT_FIELD_EMAIL)
                            {
                                count = srv_phb_datamgr_get_email_count(id);
                                for (j = 0; j < count; j++)
                                {
                                    srv_phb_query_add_match_item(
                                        handle,
                                        id,
                                        MMI_PHB_CONTACT_FIELD_ID_EMAIL,
                                        j,
                                        &(info.match_info),
                                        req->item_order);
                                    add_flag = MMI_TRUE;
                                }
                            }
                            if (!add_flag && (req->align_field & MMI_PHB_CONTACT_FIELD_NAME))
                            {
                                srv_phb_query_add_match_item(
                                    handle,
                                    id,
                                    MMI_PHB_CONTACT_FIELD_ID_NAME,
                                    0,
                                    &(info.match_info),
                                    req->item_order);
                            }
                        }
                        break;
                }
            }

            query_time++;
            if (query_time >= query_async_handle->query_time && query_async_handle->callback_func)
            {
                query_async_handle->query_index += query_time;
                MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_QUERY_NEED_CB, query_async_handle->query_index, query_time, 
                            req, handle, query_async_handle->now_match_field);
                srv_phb_sse_async_query(req, handle);
                return ;
            }
        }
        // call back, finsh name match
        query_handle->match_field = 1;
        query_async_handle->now_match_field = 1;
        start_index = 0; // reset start_index
        if (query_async_handle->callback_func)
        {
            srv_phb_query_async_cb_result_struct ret;
            ret.user_data = query_async_handle->user_data;
            ret.result = 0;

            MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_QUERY_ASYNC_NAME_DONE, ret.result, ret.user_data, query_handle->total_item,
                        query_handle->number_item, query_handle->contact_item, query_async_handle->start_index);
            query_async_handle->callback_func(&ret);

            //srv_phb_query_remove_pid(query_handle->pid); // finish query, then remove pid
            //query_handle->pid = 0;

            query_async_handle->query_index = query_async_handle->start_index; // reset query index, begin to query number field
            srv_phb_sse_async_query(req, handle);

            return;
        }
    }

    if (query_async_handle->now_match_field == 1)
    {
        // now_match_field = 1, match number field
        for (i = start_index; i < g_srv_phb_sse_cntx.entry_count; i++)
        {
            id = g_srv_phb_sse_cntx.name_index[i];
            if (srv_phb_filter_contact(id, req->filter, &info))
            {
                switch (info.match_info.matched_field)
                {
                    case MMI_PHB_CONTACT_FIELD_ID_NUMBER:
                        if (req->align_field & MMI_PHB_CONTACT_FIELD_NUMBER)
                        {
                            count = info.number_count;
                            for (j = 0; j < info.number_count; j++)
                            {
                                srv_phb_query_add_match_item(
                                    handle,
                                    id,
                                    MMI_PHB_CONTACT_FIELD_ID_NUMBER,
                                    info.number_id[j],
                                    &(info.match_info),
                                    req->item_order);
                            }
                        }
                        else
                        {
                            srv_phb_query_add_match_item(
                                handle,
                                id,
                                MMI_PHB_CONTACT_FIELD_ID_NUMBER,
                                info.number_id[0],
                                &(info.match_info),
                                    req->item_order);
                        }
                        break;

                    case MMI_PHB_CONTACT_FIELD_ID_NAME:
                    default:
                        break;
                }
            }

            query_time++;
            if (query_time >= query_async_handle->query_time && query_async_handle->callback_func)
            {
                query_async_handle->query_index += query_time;
                MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_QUERY_NEED_CB, query_async_handle->query_index, query_time, 
                            req, handle, query_async_handle->now_match_field);
                srv_phb_sse_async_query(req, handle);
                return ;
            }
        }
        // call back
        if (query_async_handle->callback_func)
        {
            srv_phb_query_async_cb_result_struct ret;
            ret.user_data = query_async_handle->user_data;
            ret.result = 1;

            MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_QUERY_ASYNC_NUMBER_DONE, ret.result, ret.user_data, query_handle->total_item,
                        query_handle->number_item, query_handle->contact_item, query_handle->pid, query_handle->malloc_count, query_handle->number_malloc);
            query_async_handle->callback_func(&ret);

            srv_phb_query_remove_pid(query_handle->pid); // finish query, then remove pid
            query_handle->pid = 0;
        }
    }

    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_SSE_QUERY_END, g_srv_phb_sse_cntx.entry_count);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_get_fdn_by_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface        : [IN]    sim id
 *  index                   : [OUT]  index array
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sse_get_fdn_by_sim_id(U8 sim_interface, U16 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  

    for (i = MMI_PHB_ENTRIES; i < MMI_PHB_FDN_TOTAL_ENTRIES + MMI_PHB_ENTRIES; i++)
    {
        if ((g_srv_phb_sse_cntx.name_index[i] - MMI_PHB_ENTRIES) / MMI_PHB_FDN_ENTRIES == sim_interface)
        {
            *index ++ = g_srv_phb_sse_cntx.name_index[i]; 
        }
    }
}


#ifdef __MMI_DIALER_SEARCH__

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
WCHAR srv_phb_ds_key_info_g[10] = {'0','1','2','3','4','5','6','7','8','9'};
#endif

#if defined(__MMI_PHB_OPTIONAL_FIELD__) && defined(__MMI_PHB_DS_SEARCH_OP_NUMBER__)
/*****************************************************************************
 * FUNCTION
 *  srv_phb_ds_compare_halfbyte
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_phb_ds_compare_halfbyte(void *a, void *b, U32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    if (length == 0)
    {
        return 0;
    }
    else if ((length % 2) == 0)
    {
        return memcmp(a, b, length / 2);
    }
    else
    {
        S32 result;
        U8 * bcd_a;
        U8 * bcd_b;
        bcd_a = (U8*)a;
        bcd_b = (U8*)b;
        if (length == 1)
        {
            result = 0;
        }
        else
        {
            result = memcmp(a, b, (length - 1) / 2);
        }
        if (result == 0)
        {
            return (bcd_a[(length - 1) / 2] & 0xF0) - (bcd_b[(length - 1) / 2] & 0xF0);
            
        }
        else
        {
            //return result;
            ret = result;
        }
    }
    return ret;
}


#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) && defined(__MMI_PHB_DS_SEARCH_OP_NUMBER__) */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_ds_convert_input_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  UI_buffer_type
 * RETURNS
 *  S32
 *****************************************************************************/
void srv_phb_ds_convert_input_key(U16* key_length, U8* keyword, U8 * key_int, U8 * key_bcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < *key_length; i++)
    {
        if (isdigit(keyword[2 * i]) && keyword[2 * i + 1] == 0)
        {
            key_int[i] = keyword[2 * i] - '0';  
        #if defined(__MMI_PHB_OPTIONAL_FIELD__) && defined(__MMI_PHB_DS_SEARCH_OP_NUMBER__)
            if (i < SRV_PHB_NUM_CACHE_LEN)
            {
                if ((i % 2) == 0)
                {
                    key_bcd[i / 2] = ((key_int[i] << 4) | 0x0F);
                }
                else
                {
                    key_bcd[i / 2] &= 0xF0;
                    key_bcd[i / 2] |= (key_int[i] & 0x0F);
                }
            }       
        #endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) && defined(__MMI_PHB_DS_SEARCH_OP_NUMBER__) */
        }
        else
        {
            *key_length = i;
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_ds_wcs_number_cmp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  UI_buffer_type
 * RETURNS
 *  S32
 *****************************************************************************/
static MMI_BOOL srv_phb_ds_wcs_number_cmp(WCHAR* number, srv_phb_ds_input_struct* input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* temp = input->key_word;
    U32 len = (U32)input->key_len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (temp[0] == '0' && number[0] == '+')
    {
        temp++;
        number++;
        len--;
    }

    if (mmi_wcsncmp(temp, number, len) == 0)
    {
       return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_ds_find_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  UI_buffer_type
 * RETURNS
 *  S32
 *****************************************************************************/
U32 srv_phb_ds_compare_phb_number(
            mmi_phb_contact_id id,
            srv_phb_ds_input_struct* input,
            srv_phb_ds_phb_entry_struct* entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    WCHAR* src;
    CHAR* dest;
    U16 len;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id < MMI_PHB_PHONE_ENTRIES)
    {
        mmi_phb_optional_fields_struct* optional_fields_data = NULL;
        for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
        {
            if (srv_phb_bcd_num_cmp(
                    g_srv_phb_sse_cntx.num_cache[MMI_PHB_NUMBER_FIELD_COUNT * id + i],
                    (WCHAR*)(input->key_word),
                    input->key_len > SRV_PHB_NUM_CACHE_LEN ? SRV_PHB_NUM_CACHE_LEN : input->key_len))
            {
                if (input->key_len > SRV_PHB_NUM_CACHE_LEN)
                {
                    if (!optional_fields_data)
                    {
                        optional_fields_data = srv_phb_get_phone_optional_field(id);
                    }
                    src = input->key_word;
                    dest = (CHAR *)(optional_fields_data->num[i].number);
                    len = input->key_len;
                    if (dest[0] == '+' && src[0] == L'0')
                    {
                        src++;
                        dest++;
                        len--;
                    }

                    if (srv_phb_acs_wcs_n_cmp(
                            dest,
                            src,
                            len) != 0)
                    {
                        continue;
                    }
                }
                entry->store_index = id;
                if (i)
                {
                    entry->u.num_index |= (U8)(SRV_PHB_ENTRY_FIELD_OPT_NUM_1 << (i - 1));
                }
                else
                {
                    entry->u.num_index = (U8)SRV_PHB_ENTRY_FIELD_NUMBER;
                }
                entry->count++;
            }
        }
    }
#ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    else if (id >= MMI_PHB_BASIC_ENTRIES)
    {
        for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i ++)
        {
            dest = srv_phb_get_tcard_number(id, i, NULL, NULL, NULL);
            src = input->key_word;
            len = input->key_len;
            if (dest == NULL)
            {
                continue;
            }
            if (dest[0] == '+' && src[0] == L'0')
            {
                src++;
                dest++;
                len--;
            }
            if (srv_phb_acs_wcs_n_cmp(
                    dest,
                    src,
                    len) != 0)
            {
                continue;
            }
            entry->store_index = id;
            if (i)
            {
                entry->u.num_index |= (U8)(SRV_PHB_ENTRY_FIELD_OPT_NUM_1 << (i - 1));
            }
            else
            {
                entry->u.num_index = (U8)SRV_PHB_ENTRY_FIELD_NUMBER;
            }
            entry->count++;
        }
    }
#endif /* __SRV_PHB_TCARD_STORAGE_SUPPORT__ */
    else
    {
        for (i = 0; i < MMI_PHB_SIM_NUM_COUNT; i++)
        {
            dest = srv_phb_get_sim_number(id, i, NULL);
            src = input->key_word;
            len = input->key_len;
            if (dest == NULL)
            {
                continue;
            }
            if (dest[0] == '+' && src[0] == L'0')
            {
                src++;
                dest++;
                len--;
            }
            if (srv_phb_acs_wcs_n_cmp(
                    dest,
                    src,
                    len) != 0)
            {
                continue;
            }
            entry->store_index = id;
            entry->u.num_index = (U8)SRV_PHB_ENTRY_FIELD_NUMBER;
            entry->count = 1;
        }
    }

    return (U32)(entry->count);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_ds_find_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  UI_buffer_type
 * RETURNS
 *  S32
 *****************************************************************************/
MMI_BOOL srv_phb_ds_compare_phb_name(
            U16 store_index,
            srv_phb_ds_input_struct* input,
            srv_phb_ds_key_info_struct* key_info,
            srv_phb_ds_phb_entry_struct* entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 name_len;
    WCHAR name[MMI_PHB_NAME_LENGTH + 1];
    U16 state = 0;
    U8 start = 0;
    U32 j,k;
    MMI_BOOL is_matched = MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_datamgr_get_name(store_index, name, MMI_PHB_NAME_LENGTH);
    name_len = mmi_wcslen(name);
    for (j = 0; j < name_len; j++)
    {
        if (state == 0)
        {
            if (name_len - j < input->key_len)
            {
                break;
            }
            if (name[j] == L' ' || name[j] == L',')
            {
                continue;
            }
            start = j;
            state = 1;
            j--;
        }
        else if (state == 1)
        {
            U32 flag = 0;
            
            if (name[j] == L' ' || name[j] == L',')
            {
                state = 0;
                continue;
            }
                
            for (k = 0; k < key_info->keysize[input->key_int[j - start]]; k++)
            {                   
                if (srv_phb_towupper(name[j]) == key_info->keymap[input->key_int[j - start]][k])
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                state = 2;                    
            }
            else
            {
                if (j - start + 1 == input->key_len)
                {
                    entry->mask[start / 8] |= 1 << (start % 8);
                    entry->count++;
                    if (!is_matched)
                    {
                        entry->count = 1;
                        entry->store_index = store_index;
                        is_matched = MMI_TRUE;
                        entry->u.first = start;
                    #ifdef __MMI_PHB_DS_SEARCH_NAME_ONCE__
                        break;
                    #endif /* __MMI_PHB_DS_SEARCH_NAME_ONCE__ */    
                    }
                    state = 2;
                }
            }
        }
        else if (state == 2)
        {
            if (name[j] == L' ' || name[j] == L',')
            {
                state = 0;
            }
        }     
    }
    return is_matched;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_ds_find_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  UI_buffer_type
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_phb_ds_search_phb_contact(srv_phb_ds_input_struct* key_input, srv_phb_ds_key_info_struct* key_info, srv_phb_ds_list_cntx_struct* output)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, number_index, name_index;
    U16 store_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    name_index = 0;
    number_index = MMI_PHB_ENTRIES - 1;
    memset(&output->entry[name_index], 0, sizeof(srv_phb_ds_phb_entry_struct));
    memset(&output->entry[number_index], 0, sizeof(srv_phb_ds_phb_entry_struct));
    output->name_count = 0;
    output->number_count = 0;
    //phone find first
    for (i = 0; i < g_srv_phb_sse_cntx.entry_count; i++)
    {
        store_index = g_srv_phb_sse_cntx.name_index[i];

        if (srv_phb_ds_compare_phb_name(store_index, key_input, key_info, &(output->entry[name_index])))
        {
            name_index++;
            output->name_count++;
            memset(&output->entry[name_index], 0, sizeof(srv_phb_ds_phb_entry_struct));
            continue;
        }
        
        if (key_input->key_len == 1 && key_input->key_word[0] == L'0')
        {
            continue;
        }

        output->number_count += srv_phb_ds_compare_phb_number(store_index, key_input, &(output->entry[number_index]));
        if (output->entry[number_index].count)
        {
            number_index--;
            memset(&output->entry[number_index], 0, sizeof(srv_phb_ds_phb_entry_struct));
        }
    }
    return (output->name_count + output->number_count);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_ds_find_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  UI_buffer_type
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_phb_ds_search_calllog(srv_phb_ds_input_struct* key_input, srv_phb_ds_list_cntx_struct* output)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_clog_get_list_log_ids_req_struct req_data;
    srv_clog_get_list_log_ids_cnf_struct cnf_data;
    srv_clog_log_struct log;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    output->callog_count = 0;
    srv_clog_init_para(SRV_CLOG_PARA_GET_LIST_LOG_IDS_REQ, &req_data);
    srv_clog_init_para(SRV_CLOG_PARA_GET_LIST_LOG_IDS_CNF, &cnf_data);

    req_data.start_by = SRV_CLOG_BY_ID;
    req_data.log_num = SRV_CLOG_LOG_ID_LIST_MAX_NUM;
    req_data.cate = SRV_CLOG_CATE_CALL;

    while(1)
    {
        req_data.start_elm = cnf_data.next_start_elm;
        if (srv_clog_get_list_log_ids(0, &req_data, &cnf_data) != SRV_CLOG_RET_OK)
        {
            break;
        }
        for (i = 0; i < cnf_data.log_num; i++)
        {
            srv_clog_get_log_by_id(0, cnf_data.log_ids[i], SRV_CLOG_LOG_FIELD_CID, &log);
            if (srv_phb_ds_wcs_number_cmp(log.data.call_log.cid, key_input))
            {
                output->calllog_id[output->callog_count++] = cnf_data.log_ids[i];
            }
        }
        if (cnf_data.next_start_elm == SRV_CLOG_INVALID_ELM)
        {
            break;
        }
    }
    return output->callog_count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_ds_find_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  UI_buffer_type
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_phb_ds_search_entry(WCHAR* key_word, srv_phb_ds_list_cntx_struct* output)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_ds_input_struct key_input;
    WCHAR key_src[51];
    U8 key_int[50];
#if defined(__MMI_PHB_OPTIONAL_FIELD__) && defined(__MMI_PHB_DS_SEARCH_OP_NUMBER__)
    U8 key_bcd[SRV_PHB_NUM_CACHE_LEN / 2];
#endif /* defined(__MMI_PHB_OPTIONAL_FIELD__) && defined(__MMI_PHB_DS_SEARCH_OP_NUMBER__) */
    U32 ime_keymap_size;
    srv_phb_ds_key_info_struct key_info;
    S32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_phb_startup_is_phb_ready())
    {
        return SRV_PHB_NOT_READY;
    }
    mmi_wcsncpy(key_src, key_word, 50);
    key_input.key_len = (U16)mmi_wcslen(key_src);
    key_input.key_word = key_src;
    key_input.key_int = key_int;
#if defined(__MMI_PHB_OPTIONAL_FIELD__) && defined(__MMI_PHB_DS_SEARCH_OP_NUMBER__)
    memset(key_bcd, 0xFF, sizeof(key_bcd));
    key_input.key_bcd = key_bcd;
#else
    key_input.key_bcd = NULL;
#endif

    srv_phb_ds_convert_input_key(&(key_input.key_len), (U8*)key_word, key_input.key_int, key_input.key_bcd);

    /* key_length == 0 has two cases: */
    /* 1. The keyword is null. */
    /* 2. The first byte of keyword is not number. */
    if (!key_input.key_len)
    {
        return 0;
    }
    key_input.key_word[key_input.key_len] = 0;
    output->key_len = key_input.key_len;

#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__    
    ime_keymap_size = mmi_ime_multitap_get_alphabetic_keymap_table_size();
    key_info.ime_table = srv_phb_mem_malloc(ime_keymap_size, SRV_PHB_MEMORY_TYPE_ADM);
    mmi_ime_multitap_create_alphabetic_keymap_table(key_info.ime_table, ime_keymap_size);

    for (i = 0; i < 10; i++)
    {
        key_info.keymap[i] =
            mmi_ime_multitap_get_keymap((U16*)key_info.ime_table, (U16)(KEY_0 + i), ime_keymap_size);
        key_info.keysize[i] = mmi_wcslen(key_info.keymap[i]);
    }
#else
    for (i = 0; i < 10; i++)
    {
        key_info.keymap[i] = &srv_phb_ds_key_info_g[i];
        key_info.keysize[i] = 1;
    }    
#endif
    srv_phb_ds_search_phb_contact(&key_input, &key_info, output);

#ifndef __MMI_QWERTY_KEYPAD_SUPPORT__
    srv_phb_mem_free(key_info.ime_table);
#endif
    srv_phb_ds_search_calllog(&key_input, output);
    return (output->name_count + output->number_count + output->callog_count);
}
#endif /* __MMI_DIALER_SEARCH__ */

#endif /* PHBSSESRV_C */
