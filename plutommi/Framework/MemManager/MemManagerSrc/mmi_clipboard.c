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

/*******************************************************************************
 * Filename:
 * ---------
 *  mmi_clipboard.c
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
 *==============================================================================
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include                                                                     
 *****************************************************************************/
#include "mmi_frm_gprot.h"
#include "mmi_frm_prot.h"
#include "GlobalDefs.h"     /* For string id */
#include "mmi_clipboard_gprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "mmi_frm_remutex_gprot.h"
#include "app_mem.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_clipboard_prot.h"
#include "kal_trace.h"
#include "mmi_fw_trc.h"
#include "string.h"
/*****************************************************************************
 * Define                                                                      
 *****************************************************************************/
#undef MMI_CLIPBOARD_UNIT_TEST

/*****************************************************************************
 * Typedef                                                                     
 *****************************************************************************/

typedef struct
{
    mmi_clipboard_handle cpbd_hdl;
    mmi_clipboard_cb_func cpbd_cb_func;
} mmi_clipboard_entry_struct;

typedef struct
{
    MMI_BOOL pool_initialized;
    KAL_ADM_ID adm_pool_id;
    mmi_clipboard_entry_struct cpbd_entry[MMI_CLIPBOARD_FORMAT_COUNT];
    mmi_frm_recursive_mutex_struct  recursive_mutex;
} mmi_clipboard_cntx_struct;

/*****************************************************************************
 * Local Variable                                                              
 *****************************************************************************/
static mmi_clipboard_cntx_struct mmi_clipboard_cntx;

/*****************************************************************************
 * Extern Global Variable                                                      
 *****************************************************************************/

/*****************************************************************************
 * Local Function                                                              
 *****************************************************************************/
#ifdef MMI_CLIPBOARD_UNIT_TEST
extern MMI_BOOL mmi_clipboard_unit_test_requirement_empty(void);
#endif
static U32 mmi_clipboard_mem_pool[(MMI_CLIPBOARD_BUFF_SIZE + 3) / 4];
/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_construct_memory_pool
 * DESCRIPTION
 *  Allocate app asm and create ADM pool
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *    Return MMI_TRUE if ADM pool is created successfully
 *    Return MMI_FALSE if can't allocate memory from ASM pool
 *****************************************************************************/
static MMI_BOOL mmi_clipboard_construct_memory_pool(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Contruct ADM pool to manage memory */
    mmi_clipboard_cntx.adm_pool_id = kal_adm_create(
                                        mmi_clipboard_mem_pool,
                                        MMI_CLIPBOARD_BUFF_SIZE,
                                        NULL,
                                        KAL_FALSE);
    /* Postcondition */
    MMI_ASSERT(mmi_clipboard_cntx.adm_pool_id != NULL);
    return MMI_TRUE;
}


#if (MMI_CLIPBOARD_GUARDPAT_LEN == 1)
/*****************************************************************************
 * FUNCTION
 *  MMI_CLIPBOARD_SET_PATTERN
 * DESCRIPTION
 *  Fill guard pattern
 * PARAMETERS
 *  ptr         [OUT]       data pointer
 *  pattern     [IN]        guard pattern
 * RETURNS
 *  void
 *****************************************************************************/
#define MMI_CLIPBOARD_SET_PATTERN(ptr, pattern)  do {(*ptr) = (pattern);} while (0)
/*****************************************************************************
 * FUNCTION
 *  MMI_CLIPBOARD_COMP_PATTERN
 * DESCRIPTION
 *  Compare if the guard pattern is correct
 * PARAMETERS
 *  ptr         [IN]        data pointer
 *  pattern     [IN]        guard pattern
 * RETURNS
 *  return MMI_FALSE if the guard pattern is corrupted
 *****************************************************************************/
#define MMI_CLIPBOARD_COMP_PATTERN(ptr, pattern)	((MMI_BOOL)((*ptr) == (pattern)))

#else /* MMI_CLIPBOARD_GUARDPAT_LEN == 1 */
static void MMI_CLIPBOARD_SET_PATTERN(U32 *ptr, U32 pattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CLIPBOARD_GUARDPAT_LEN; i++)
    {
        ptr[i] = pattern;
    }
}


static MMI_BOOL MMI_CLIPBOARD_COMP_PATTERN(const U32 *ptr, U32 pattern)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_CLIPBOARD_GUARDPAT_LEN; i++)
    {
        if (ptr[i] != pattern)
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}
#endif /* MMI_CLIPBOARD_GUARDPAT_LEN == 1 */


/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_check_guard_pattern
 * DESCRIPTION
 *  Check guard pattern for memory block of clipboard
 * PARAMETERS
 *  mem_p    [IN]
 * RETURNS
 *  MMI_TURE    guard pattern is correct
 *  MMI_FALSE   guard pattern is wrong, need to check memory overlap
 *****************************************************************************/
static MMI_BOOL mmi_clipboard_check_guard_pattern(void *mem_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clipboard_head_struct *head;
    mmi_clipboard_foot_struct *foot;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    head = MMI_CLIPBOARD_GET_HEAD(mem_p);
    foot = MMI_CLIPBOARD_GET_FOOT(mem_p, head);
    result = (MMI_CLIPBOARD_COMP_PATTERN(head->guard_pattern, MMI_CLIPBOARD_HEAD_PATTERN1) &&
             MMI_CLIPBOARD_COMP_PATTERN(foot->guard_pattern, MMI_CLIPBOARD_FOOT_PATTERN1)) ? MMI_TRUE : MMI_FALSE;
    MMI_ASSERT(result);
    return result;
}


/*****************************************************************************
 * Extern Global Function                                                      
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_get_memory
 * DESCRIPTION
 *  Get memory from clipboard pool
 * PARAMETERS
 *  mem_size    [IN]    memory size
 *  type        [IN]    format type
 * RETURNS
 *  Clipboard memory pointer
 *  NULL pointer    1. memory size is zero or negtive
 *                  2. type is invalid
 *****************************************************************************/
void *mmi_clipboard_get_memory(U32 mem_size, mmi_clipboard_content_format_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *mem_p;
    U32 adm_block_size;
    mmi_clipboard_head_struct *head;
    mmi_clipboard_foot_struct *foot;
    U32 chunk_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_recursive_mutex_lock(&mmi_clipboard_cntx.recursive_mutex);
    MMI_ASSERT(type >= MMI_CLIPBOARD_FORMAT_BEGIN && type < MMI_CLIPBOARD_FORMAT_COUNT);
    MMI_ASSERT(mmi_clipboard_cntx.adm_pool_id != NULL);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_GET_MEMORY_BEGIN, mem_size, type);
    /* 
     * Allocated memory size should be greater than zero
     * Process error handling of assert case for release version
     */
    if (mem_size == 0 || type < MMI_CLIPBOARD_FORMAT_BEGIN || type >= MMI_CLIPBOARD_FORMAT_COUNT)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_GET_MEMORY_WRONG_ARG, mem_size, type);
        mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
        return NULL;
    }
    
    /* Round to multiple of 4 to make sure footer address is 4bytes alignment */
    chunk_size = (((mem_size + 3) >> 2) << 2);

    /* Allocate more meory for head & foot structure */
    adm_block_size = chunk_size + sizeof(mmi_clipboard_head_struct) + sizeof(mmi_clipboard_foot_struct);

    mem_p = kal_adm_alloc(mmi_clipboard_cntx.adm_pool_id, (kal_uint32)adm_block_size);
    /* Should call MMI_FRM_ADM_ALLOC_FRAMEBUFFER for cachable buffer */
    if (NULL == mem_p)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_GET_MEMORY_NO_MEMORY, chunk_size, mmi_clipboard_query_free_space());
        mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
        return NULL;
    }
    head = (mmi_clipboard_head_struct *)mem_p;
    mem_p = head + 1;
    foot = (mmi_clipboard_foot_struct *)((U8 *)mem_p + chunk_size);

    head->entry_format = type;
    head->entry_status = MMI_CLIPBOARD_STATUS_COPY;
    head->entry_size = chunk_size;
    MMI_CLIPBOARD_SET_PATTERN(head->guard_pattern, MMI_CLIPBOARD_HEAD_PATTERN1);
    MMI_CLIPBOARD_SET_PATTERN(foot->guard_pattern, MMI_CLIPBOARD_FOOT_PATTERN1);
    mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_GET_MEMORY_END, mem_p);
    return mem_p;
    
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_init
 * DESCRIPTION
 *  Initialize clipboard context and register app-asm
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_clipboard_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_clipboard_cntx.adm_pool_id = NULL;
    mmi_clipboard_cntx.pool_initialized = MMI_FALSE;
    mmi_frm_recursive_mutex_init(&mmi_clipboard_cntx.recursive_mutex, "Clipboard_mutex");
#ifdef MMI_CLIPBOARD_UNIT_TEST
    while (1)
    {
        MMI_ASSERT(mmi_clipboard_unit_test_requirement_empty());
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_query_free_space
 * DESCRIPTION
 *  Query left memory in clipboard
 * PARAMETERS
 *  void
 * RETURNS
 *  Free space
 *****************************************************************************/
U32 mmi_clipboard_query_free_space(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_recursive_mutex_lock(&mmi_clipboard_cntx.recursive_mutex);
    result = MMI_CLIPBOARD_CONTENT_SIZE - (sizeof(mmi_clipboard_head_struct) + sizeof(mmi_clipboard_foot_struct));
    mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_set_data
 * DESCRIPTION
 *  Fill the content data into clipboard
 *  This API will invoke callback function if app registered new clipboard type
 *  Please remember call mmi_clipboard_register_new_content(...) firstly.
 * PARAMETERS
 *  type    [IN]    content format type
 *  data    [OUT]   content struct pointer
 * RETURNS
 *  Clipboard content handler
 *  Null pointer    1. memory is not enough
 *                  2. memory overlap happens found in mmi_clipboard_check_guard_pattern
 *                  3. type is invalid
 *                  4. data pointer is NULL
 *                  5. fail to empty data
 *****************************************************************************/
mmi_clipboard_handle mmi_clipboard_set_data(mmi_clipboard_content_format_enum type, void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clipboard_handle cpbd_hdl = NULL;
    U32 struct_size, str_content_size, clip_data_size;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_recursive_mutex_lock(&mmi_clipboard_cntx.recursive_mutex);
    MMI_ASSERT(type >= MMI_CLIPBOARD_FORMAT_BEGIN && type < MMI_CLIPBOARD_FORMAT_COUNT);
    MMI_ASSERT(data != NULL);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_SET_DATA_BEGIN, type, data);

    /*
     * Process error handling of assert case for release version
     */
    if (data == NULL || type < MMI_CLIPBOARD_FORMAT_BEGIN || type >= MMI_CLIPBOARD_FORMAT_COUNT)
    {
        mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_SET_DATA_WRONG_ARG, type, data);
        return NULL;
    }

	/* 
	 * Clipboard buffer would look like this
	 *  ----------------------
	 * | header guard pattern | (4 byte)
	 *  ----------------------
	 * |  entry_format        | (enum " )
	 *  ----------------------
     * |  entry_status        | (enum " )
	 *  ----------------------
	 * |  entry_size          | (4 " )
	 *  ----------------------
	 * | structure(raw data)  | ( mmi_clipboard_xxx_data_struct bytes )
	 *  ----------------------
	 * | footer guard pattern | (4 " )
	 *  ---------------------
	 */
    if (MMI_FALSE == mmi_clipboard_cntx.pool_initialized)
    {
        if (MMI_FALSE == mmi_clipboard_construct_memory_pool())
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_SET_DATA_MEM_POOL_FAIL);
            mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
            return NULL;
        }
        mmi_clipboard_cntx.pool_initialized = MMI_TRUE;
    }

    /* 
     * Only one entry could be copied for every type of format, 
     * so the former should be freed when user set same type again.
     */
    if (mmi_clipboard_cntx.cpbd_entry[type].cpbd_hdl != NULL)
    {
        result = mmi_clipboard_empty_data_by_type(type);
        if (!result)
        {
            MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_SET_DATA_EMPTY_FAIL, type);
            mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
            return NULL;
        }
    }

    /* Register new format mechanism */
    if (mmi_clipboard_cntx.cpbd_entry[type].cpbd_cb_func != NULL)
    {
        mmi_clipboard_cntx.cpbd_entry[type].cpbd_hdl = 
            (mmi_clipboard_handle)mmi_clipboard_cntx.cpbd_entry[type].cpbd_cb_func(data);
        result = mmi_clipboard_check_guard_pattern(mmi_clipboard_cntx.cpbd_entry[type].cpbd_hdl);
        /* Return NULL if fail to check guard pattern since MMI_ASSERT maybe closed sometime! */
        mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
        return (result ? mmi_clipboard_cntx.cpbd_entry[type].cpbd_hdl : NULL);
    }

    /* Process default format */
    switch (type)
    {
        case MMI_CLIPBOARD_FORMAT_UNICODETEXT:
        {
            mmi_clipboard_unicodetext_data_struct *unicodetext_struct_p = (mmi_clipboard_unicodetext_data_struct *)data;
            struct_size = sizeof(mmi_clipboard_unicodetext_data_struct);
            /* App should input string length, clipboard mutiple ENCODING_LENGTH for unicode */
            str_content_size = unicodetext_struct_p->len * ENCODING_LENGTH;
            clip_data_size = struct_size + str_content_size;

            cpbd_hdl = (mmi_clipboard_handle)mmi_clipboard_get_memory(clip_data_size, MMI_CLIPBOARD_FORMAT_UNICODETEXT);

            if (cpbd_hdl)
            {
                /* Copy structure elements */
                memcpy(cpbd_hdl, unicodetext_struct_p, struct_size);
                ((mmi_clipboard_unicodetext_data_struct *)cpbd_hdl)->data = (S8 *)((U32)cpbd_hdl + struct_size);
                /* Copy data cotent */
                memcpy((void *)((mmi_clipboard_unicodetext_data_struct *)cpbd_hdl)->data, (void *)unicodetext_struct_p->data, str_content_size);
            }
            break;
        }
        case MMI_CLIPBOARD_FORMAT_FILE:
        {
            mmi_clipboard_file_format_data_struct *file_struct_p = (mmi_clipboard_file_format_data_struct *)data;
            clip_data_size = sizeof(mmi_clipboard_file_format_data_struct);
            cpbd_hdl =  (mmi_clipboard_handle)mmi_clipboard_get_memory(clip_data_size, MMI_CLIPBOARD_FORMAT_FILE);
            if (cpbd_hdl)
            {
                /* Copy structure elements */
                memcpy(cpbd_hdl, file_struct_p, clip_data_size);
            }
            break;
        }
        default:
        {
            MMI_ASSERT(MMI_FALSE);
            break;
        }
    }

    mmi_clipboard_cntx.cpbd_entry[type].cpbd_hdl = cpbd_hdl;
    mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_SET_DATA_END, cpbd_hdl);
    return cpbd_hdl;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_get_data_by_type
 * DESCRIPTION
 *  Get the content data from clipboard by type
 *  
 * PARAMETERS
 *  type    [IN]    content format type
 * RETURNS
 *  Clipboard handler
 *  NULL pointer 1. this type of clipboard has not been set
 *               2. fail to check guard pattern
 *               3. invalid type
 *****************************************************************************/
void *mmi_clipboard_get_data_by_type(mmi_clipboard_content_format_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_recursive_mutex_lock(&mmi_clipboard_cntx.recursive_mutex);
    MMI_ASSERT(type >= MMI_CLIPBOARD_FORMAT_BEGIN && type < MMI_CLIPBOARD_FORMAT_COUNT);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_GET_DATA_BY_TYPE_BEGIN, type);
    /* 
     * Process error handling of assert case for release version
     */
    if (type < MMI_CLIPBOARD_FORMAT_BEGIN || type >= MMI_CLIPBOARD_FORMAT_COUNT)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_GET_DATA_BY_TYPE_WRONG_ARG, type);
        mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
        return NULL;
    }
    if (mmi_clipboard_cntx.cpbd_entry[type].cpbd_hdl)
    {
        result = mmi_clipboard_check_guard_pattern(mmi_clipboard_cntx.cpbd_entry[type].cpbd_hdl);
    }
    mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_GET_DATA_BY_TYPE_END, result);
    return (result ? (void *)mmi_clipboard_cntx.cpbd_entry[type].cpbd_hdl : NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_get_data_by_handle
 * DESCRIPTION
 *  Get the content data from clipboard by handler
 *  
 * PARAMETERS
 *  handle    [IN]  clipboard content handler
 * RETURNS
 *  Clipboard handler
 *  NULL pointer meanse fail to check guard pattern
 *****************************************************************************/
void *mmi_clipboard_get_data_by_handle(mmi_clipboard_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_GET_DATA_BY_HANDLE_BEGIN, handle);
    mmi_frm_recursive_mutex_lock(&mmi_clipboard_cntx.recursive_mutex);
    if (handle)
    {
        result = mmi_clipboard_check_guard_pattern(handle);
    }
    mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_GET_DATA_BY_HANDLE_END, result);
    return (result ? (void *)handle : NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_empty_data_by_type
 * DESCRIPTION
 *  Empty clipboard data by type
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE    empty successfully
 *  MMI_FALSE   1. NULL handle
 *              2. invalid type 
 *              3. fail to check guard pattern
 *****************************************************************************/
MMI_BOOL mmi_clipboard_empty_data_by_type(mmi_clipboard_content_format_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clipboard_head_struct *head;
    mmi_clipboard_foot_struct *foot;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_recursive_mutex_lock(&mmi_clipboard_cntx.recursive_mutex);
    MMI_ASSERT(type >= MMI_CLIPBOARD_FORMAT_BEGIN && type < MMI_CLIPBOARD_FORMAT_COUNT);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_EMPTY_DATA_BY_TYPE_BEGIN, type);

    /*
     * Process error handling of assert case for release version
     */
    if (type < MMI_CLIPBOARD_FORMAT_BEGIN || type >= MMI_CLIPBOARD_FORMAT_COUNT)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_EMPTY_DATA_BY_TYPE_WRONG_ARG, type);
        mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
        return MMI_FALSE;
    }

    if (NULL == mmi_clipboard_cntx.cpbd_entry[type].cpbd_hdl)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_EMPTY_DATA_BY_TYPE_NULL_HDL);
        mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
        return MMI_FALSE;
    }

    result = mmi_clipboard_check_guard_pattern(mmi_clipboard_cntx.cpbd_entry[type].cpbd_hdl);
    if (!result)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_EMPTY_DATA_BY_TYPE_PATTERN_FAIL);
        mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
        return MMI_FALSE;
    }
    
    head = MMI_CLIPBOARD_GET_HEAD(mmi_clipboard_cntx.cpbd_entry[type].cpbd_hdl);
    foot = MMI_CLIPBOARD_GET_FOOT(mmi_clipboard_cntx.cpbd_entry[type].cpbd_hdl, head);

    MMI_CLIPBOARD_SET_PATTERN(head->guard_pattern, MMI_CLIPBOARD_HEAD_PATTERN2);
    MMI_CLIPBOARD_SET_PATTERN(foot->guard_pattern, MMI_CLIPBOARD_FOOT_PATTERN2);

    kal_adm_free(mmi_clipboard_cntx.adm_pool_id, (void *)head);
    mmi_clipboard_cntx.cpbd_entry[type].cpbd_hdl = NULL;
    mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_EMPTY_DATA_BY_TYPE_END);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_empty_data_by_handle
 * DESCRIPTION
 *  Empty clipboard data by handle
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE    empty successfully
 *  MMI_FALSE   NULL handle, ERROR format
 *****************************************************************************/
MMI_BOOL mmi_clipboard_empty_data_by_handle(mmi_clipboard_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clipboard_content_format_enum type;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_EMPTY_DATA_BY_HANDLE_BEGIN, handle);
    if (NULL == handle)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_EMPTY_DATA_BY_HANDLE_WRONG_ARG, handle);
        return MMI_FALSE;
    }
    type = mmi_clipboard_get_type_by_handle(handle);
    if (type == MMI_CLIPBOARD_FORMAT_ERROR)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_EMPTY_DATA_BY_HANDLE_GET_TYPE_FAIL, type);
        return MMI_FALSE;
    }

    result = mmi_clipboard_empty_data_by_type(type);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_EMPTY_DATA_BY_HANDLE_END, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_get_type_by_handle
 * DESCRIPTION
 *  Get clipboard format type by handle
 * PARAMETERS
 *  void
 * RETURNS
 *  Clipboard format type
 *  MMI_CLIPBOARD_FORMAT_ERROR  1. NULL handle
 *                              2. can't find type 
 *                              3. invalid type
 *****************************************************************************/
mmi_clipboard_content_format_enum mmi_clipboard_get_type_by_handle(mmi_clipboard_handle handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clipboard_content_format_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_recursive_mutex_lock(&mmi_clipboard_cntx.recursive_mutex);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_GET_TYPE_FROM_HANDLE_BEGIN, handle);
    if (NULL == handle)
    {
        mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
        return MMI_CLIPBOARD_FORMAT_ERROR;
    }
    for (type = MMI_CLIPBOARD_FORMAT_BEGIN; type < MMI_CLIPBOARD_FORMAT_COUNT; type++)
    {
        if (handle == mmi_clipboard_cntx.cpbd_entry[type].cpbd_hdl)
        {
            MMI_ASSERT(type >= MMI_CLIPBOARD_FORMAT_BEGIN && type < MMI_CLIPBOARD_FORMAT_COUNT);
            /* 
             * Process error handling of assert case for release version
             */
            if (type < MMI_CLIPBOARD_FORMAT_BEGIN || type >= MMI_CLIPBOARD_FORMAT_COUNT)
            {
                MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_GET_TYPE_FROM_HANDLE_END, type);
                mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
                return MMI_CLIPBOARD_FORMAT_ERROR;
            }
            mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
            return type;
        }
    }
    mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_GET_TYPE_FROM_HANDLE_FAIL);
    return MMI_CLIPBOARD_FORMAT_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_register_new_content
 * DESCRIPTION
 *  Register callback function for new clipboard format type
 *
 * How to register new clipboard format 
 * 1. User should add new format in mmi_clipboard_content_format_enum in mmi_clipboard_gprot.h
 * 2. Design new format data structure in mmi_clipboard_gprot.h
 * 3. Register callback function by mmi_clipboard_register_new_content for new type
 * 4. Copy raw data to memory in callback function, please refer mmi_clipboard_unit_test_set_cb
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE    register successfully
 *  MMI_FALSE   1. callback function is NULL 
 *              2. type is invalid
 *****************************************************************************/
MMI_BOOL mmi_clipboard_register_new_content(mmi_clipboard_content_format_enum type, mmi_clipboard_cb_func set_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_recursive_mutex_lock(&mmi_clipboard_cntx.recursive_mutex);
    MMI_ASSERT(type >= MMI_CLIPBOARD_FORMAT_BEGIN && type < MMI_CLIPBOARD_FORMAT_COUNT);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_REGISTER_NEW_CONTENT_BEGIN, type, set_cb);
    /* 
     * Process error handling of assert case for release version
     */
    if (NULL == set_cb || type < MMI_CLIPBOARD_FORMAT_BEGIN || type >= MMI_CLIPBOARD_FORMAT_COUNT)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_REGISTER_NEW_CONTENT_WRONG_ARG, type, set_cb);
        mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
        return MMI_FALSE;
    }

    mmi_clipboard_cntx.cpbd_entry[type].cpbd_cb_func = set_cb;
    mmi_frm_recursive_mutex_unlock(&mmi_clipboard_cntx.recursive_mutex);
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_CLIPBOARD_REGISTER_NEW_CONTENT_END);
    return MMI_TRUE;
}


/*****************************************************************************
 * Requirement test
 * RD could refer these case for developing
 *****************************************************************************/
#ifdef MMI_CLIPBOARD_UNIT_TEST
#include "gdi_datatype.h"

#define CB_HDL_NUM  5
typedef struct
{
    S16 width;
    S16 height;
    gdi_color_format format;
    U32 image_size;
    U8* data;
} mmi_clipboard_image_data_struct;

/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_unit_test_set_cb
 * DESCRIPTION
 *  Callback function for registered new clipboard format
 * PARAMETERS
 *  image_struct    [IN]    structure pointer for image format
 * RETURNS
 *  Memory pointer
 *****************************************************************************/
void *mmi_clipboard_unit_test_set_cb(void *image_struct)
{
    U32 cb_mem_size;
    void *mem_p;
    mmi_clipboard_image_data_struct *image_struct_p = (mmi_clipboard_image_data_struct *)image_struct;

    /* This solution is prefered to reduce fragmentation */
    /* Must be struct size add data size */
    cb_mem_size = sizeof(mmi_clipboard_image_data_struct) + image_struct_p->image_size;

    mem_p = mmi_clipboard_get_memory(cb_mem_size, MMI_CLIPBOARD_FORMAT_IMAGE);
    /* 
	 *  ---------------------
	 * |  structure data     | (mmi_clipboard_xxx_data_struct)
 	 *  ---------------------
	 * |  raw data           | 
	 *  ---------------------
	 */
    if (mem_p != NULL)
    {
        memcpy(mem_p, (void *)image_struct_p, sizeof(mmi_clipboard_image_data_struct));
        /* 
         * Must reset position if structure has pointer, 
         * don't need to reset pointer if structure use array
         */
        ((mmi_clipboard_image_data_struct *)mem_p)->data = (void *)((U32)mem_p + sizeof(mmi_clipboard_image_data_struct));
        memcpy((void *)((mmi_clipboard_image_data_struct *)mem_p)->data, image_struct_p->data, image_struct_p->image_size);

        return mem_p;
    }
    else
    {
        return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_unit_test_requirement_set_and_get
 * DESCRIPTION
 *  Requirement test for set and get data
 * PARAMETERS
 *  hdl_addr    handle address
 * RETURNS
 *  MMI_TURE    set and get data successfully
 *  MMI_FALSE   fail to set or get data
 *****************************************************************************/
MMI_BOOL mmi_clipboard_unit_test_requirement_set_and_get(mmi_clipboard_handle *hdl_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clipboard_unicodetext_data_struct unicode_stuct;
    mmi_clipboard_unicodetext_data_struct *unicode_struct_by_type, *unicode_struct_by_hdl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    unicode_stuct.data = (S8 *)L"Hello world!";
    unicode_stuct.len = mmi_wcslen((U16 *)unicode_stuct.data);  /* Include end char */

    /* Set data */
    *hdl_addr = mmi_clipboard_set_data(MMI_CLIPBOARD_FORMAT_UNICODETEXT, (void *)&unicode_stuct);
    if (*hdl_addr == NULL)
    {
       // TODO: Display error popup screen to notify user memory is not enough
       return MMI_FALSE;
    }
    
    /* Get data by type */
    unicode_struct_by_type = (mmi_clipboard_unicodetext_data_struct *)mmi_clipboard_get_data_by_type(MMI_CLIPBOARD_FORMAT_UNICODETEXT);
    if (unicode_struct_by_type != NULL)
    {
        // TODO: Process clipboard data
        if (mmi_wcsncmp((U16 *)unicode_stuct.data, (U16 *)unicode_struct_by_type->data, unicode_stuct.len))
        {
            /* Copied data should be as same as the original data! */
            return MMI_FALSE;
        }
    }
    else
    {
        // TODO: Display error popup screen to notify user memory is not enough
        return MMI_FALSE;
    }

    unicode_struct_by_hdl = (mmi_clipboard_unicodetext_data_struct *)mmi_clipboard_get_data_by_handle(*hdl_addr);
    /* Get data by handle */
    if (unicode_struct_by_hdl != NULL)
    {
        // TODO: Process clipboard data
        if (mmi_wcsncmp((U16 *)unicode_stuct.data, (U16 *)unicode_struct_by_type->data, unicode_stuct.len))
        {
            /* Copied data should be as same as the original data! */
            return MMI_FALSE;
        }
    }
    else
    {
        // TODO: Display error popup screen to notify user memory is not enough
        return MMI_FALSE;
    }

    if (!(unicode_struct_by_type == unicode_struct_by_hdl))
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_unit_test_requirement_register_mechanism
 * DESCRIPTION
 *  Requirement function for register mechanism
 * PARAMETERS
 *  hdl_addr    handle address
 * RETURNS
 *  MMI_TRUE    register successfully
 *  MMI_FALSE   fail to register
 *****************************************************************************/
MMI_BOOL mmi_clipboard_unit_test_requirement_register_mechanism(mmi_clipboard_handle *hdl_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    U32 data_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* New type register mechanism */
    mmi_clipboard_image_data_struct image_struct, *image_struct_p;

    image_struct.data = (U8 *)L"Hello image!";   /* Fake row image data */
    image_struct.height = 5;
    image_struct.width = 6;
    image_struct.format = 3;
    data_length = (U32)mmi_wcslen((U16 *)image_struct.data);
    image_struct.image_size =  data_length * ENCODING_LENGTH;    /* Fake image sizes */

    /* Set data */
    result = mmi_clipboard_register_new_content(MMI_CLIPBOARD_FORMAT_IMAGE, mmi_clipboard_unit_test_set_cb);
    if (!result)
    {
        return MMI_FALSE;
    }
    *hdl_addr = mmi_clipboard_set_data(MMI_CLIPBOARD_FORMAT_IMAGE, (void *)&image_struct);
    if (!(*hdl_addr))
    {
        return MMI_FALSE;
    }

    /* Get data by type */
    image_struct_p = mmi_clipboard_get_data_by_type(MMI_CLIPBOARD_FORMAT_IMAGE);
    if (!(*hdl_addr) || mmi_wcsncmp((U16 *)image_struct.data, (U16 *)image_struct_p->data, data_length))
    {
       /* Copied data should be as same as the original data! */
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_unit_test_requirement_empty
 * DESCRIPTION
 *  Requirement function for empty operation
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_clipboard_unit_test_requirement_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_clipboard_handle hdl;
    mmi_clipboard_content_format_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!mmi_clipboard_unit_test_requirement_set_and_get(&hdl))
    {
        return MMI_FALSE;
    }
    if (!mmi_clipboard_empty_data_by_handle(hdl))
    {
        return MMI_FALSE;
    }

    if (!mmi_clipboard_unit_test_requirement_register_mechanism(&hdl))
    {
        return MMI_FALSE;
    }
    
    type = mmi_clipboard_get_type_by_handle(hdl);
    if (MMI_CLIPBOARD_FORMAT_ERROR == type)
    {
        return MMI_FALSE;
    }

    return mmi_clipboard_empty_data_by_type(type);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_unit_test_requirement_fuction_ext
 * DESCRIPTION
 *  Get memory from clipboard pool
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE    
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_clipboard_unit_test_requirement_fuction_ext(void)
{
    U32 i;
    mmi_clipboard_unicodetext_data_struct unicode_struct;
    mmi_clipboard_handle hdls[CB_HDL_NUM];
    mmi_clipboard_content_format_enum hdl_type[CB_HDL_NUM];
    mmi_clipboard_unicodetext_data_struct *unocode_struct_arr[CB_HDL_NUM];

    unicode_struct.data = (S8 *)L"Hello world!";
    unicode_struct.len = mmi_wcslen((U16 *)unicode_struct.data);
    /* For furture extenstion */
    /* set serials same type of data */
    for (i = 0; i < CB_HDL_NUM; i++)
    {
        hdls[i] = mmi_clipboard_set_data(MMI_CLIPBOARD_FORMAT_UNICODETEXT, (void *)&unicode_struct);
    }

    /* get serials same type of data and corresponding type */
    for (i = 0; i < CB_HDL_NUM; i++)
    {
        if (hdls[i] != NULL)
        {
            unocode_struct_arr[i] = mmi_clipboard_get_data_by_handle(hdls[i]);
            hdl_type[i] = mmi_clipboard_get_type_by_handle(hdls[i]);
        }
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_clipboard_unit_test_requirement_fuction_ext
 * DESCRIPTION
 *  Get memory from clipboard pool
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE    
 *  MMI_FALSE
 *****************************************************************************/
MMI_BOOL mmi_clipboard_unit_test_set_data(void)
{
    //mmi_clipboard_set_data(mmi_clipboard_content_format_enum type,void * data)


    return MMI_TRUE;
}

#endif /* MMI_CLIPBOARD_UNIT_TEST */


