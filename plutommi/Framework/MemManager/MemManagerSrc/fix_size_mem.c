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
 *    fix_size_mem.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is used for MMI fix size memory management
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include header file
 *****************************************************************************/
#include "kal_public_defs.h"
#include "MMIDataType.h"
#include "wndrv_cnst.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "MMI_fw_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_fw_trc.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_afm.h"
#include "fix_size_mem.h"
//#define __MMI_AFM_TEST__

#if defined(__MMI_AFM_TEST__) && !defined(MMI_AFM_DEBUG)
#error "Please define MMI_AFM_DEBUG to do the UT"
#endif

/***************************************************************************** 
* typedef
*****************************************************************************/
typedef struct
{
    KAL_AFM_ID afm_id;
} mmi_fix_mem_struct;

/***************************************************************************** 
* Global Variable
*****************************************************************************/
static kal_uint32 g_mmi_afm_pool[(MMI_AFM_POOL_SIZE + 3) / 4];
static kal_uint32 g_mmi_afm_sub_pools_size[] = SUB_POOL_SIZE_DATA;
static kal_uint32 g_mmi_afm_sub_pools_num[]  = SUB_POOL_NUM;
static mmi_fix_mem_struct g_mmi_fix_mem_cntx = {0};

/***************************************************************************** 
* Local Functions
*****************************************************************************/
static MMI_BOOL is_in_fix_size_buf_pool(void *p);
#ifdef __MMI_AFM_TEST__
static void mmi_frm_fix_mem_test(void);
#endif /* __MMI_AFM_TEST__ */

/*****************************************************************************
 * FUNCTION
 *  is_in_fix_size_buf_pool
 * DESCRIPTION
 *  This function is used to judge an pointer if it is in the fix size buffer pool
 * 
 * PARAMETERS
 *  p          : [IN]  address value
 * RETURNS
 *  MMI TRUE if the pointer belong to the fix size buffer pool
 *****************************************************************************/
static MMI_BOOL is_in_fix_size_buf_pool(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((p > (void *)g_mmi_afm_pool) && (p < (void *)(g_mmi_afm_pool + (MMI_AFM_POOL_SIZE + 3) / 4)))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_fix_mem_init
 * DESCRIPTION
 *  This function is used to init fix size memory pool
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_fix_mem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 left_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_fix_mem_cntx.afm_id = kal_afm_create(g_mmi_afm_pool, 
                                    sizeof(g_mmi_afm_pool), 
                                    g_mmi_afm_sub_pools_size,
                                    g_mmi_afm_sub_pools_num,
                                    MMI_AFM_OPTION,
                                    &left_size);
#ifdef __MMI_AFM_TEST__
    mmi_frm_fix_mem_test();
#endif /* __MMI_AFM_TEST__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_fix_mem_alloc
 * DESCRIPTION
 *  This function is used to allocate memory from afm pool
 * 
 * PARAMETERS
 *  size        : [IN] the required memory size
 * RETURNS
 *  The address of the allocated buffer
 *****************************************************************************/
void* mmi_frm_fix_mem_alloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 actual_size;
    void *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_mmi_fix_mem_cntx.afm_id != NULL);
    p = kal_afm_alloc_dbg(g_mmi_fix_mem_cntx.afm_id, size, &actual_size, NULL, 0);
    return p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_fix_mem_free
 * DESCRIPTION
 *  This function is used to free memory to afm pool
 * 
 * PARAMETERS
 *  p        : [IN] the address that need to free
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_fix_mem_free(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_afm_free(g_mmi_fix_mem_cntx.afm_id, p);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_fix_mem_check_intigrity
 * DESCRIPTION
 *  This function is used to check the integrity of the AFM pool
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef MMI_AFM_DEBUG 
void mmi_frm_fix_mem_check_intigrity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ASSERT(kal_afm_check_integrity(g_mmi_fix_mem_cntx.afm_id) == 0);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_malloc
 * DESCRIPTION
 *  This function is used to allocate memory. First, allocate from AFM
 *  if fail, allocate from control buffer
 * 
 * PARAMETERS
 *  size        : [IN]  allocate size
 * RETURNS
 *  buffer pointer
 *****************************************************************************/
void *mmi_frm_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = mmi_frm_fix_mem_alloc(size);
    if (p == NULL)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_MEM_AFM_POOL_FULL);
        p = mmi_malloc(size);
    }
    return p;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_free
 * DESCRIPTION
 *  This function is used to free memory
 * 
 * PARAMETERS
 *  p        : [IN]  the buffer pointer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_free(void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_in_fix_size_buf_pool(p) == MMI_TRUE)
    {
        mmi_frm_fix_mem_free(p);
    }
    else
    {
        mmi_mfree(p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_fix_mem_get_info
 * DESCRIPTION
 *  This function is used to get the fix size memory info
 *  make sure the last element of the buffer is AFM_SUBPOOL_END_PATTERN
 * 
 * PARAMETERS
 *  size             :  [OUT] buffer to store the size of each sub pool
 *  total_num        :  [OUT] buffer to store the block number of each sub pool
 *  left_num         :  [OUT] buffer to store the left block number of each sub pool
 *  min_lef_num      :  [OUT] buffer to store the min left block number of each sub pool
 *  entry_num        :  [IN]  the above buffer's entry number plus 1
 * RETURNS
 *  OK return 0, fail return -1
 *****************************************************************************/
U32 mmi_frm_fix_mem_get_info(U32 *size, U32 *total_num, U32 *left_num, U32 *min_lef_num, U32 entry_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 option;
    kal_int32  ret;
    kal_uint32 total_left;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = kal_afm_custom_performance_info_get(
            g_mmi_fix_mem_cntx.afm_id,
            &option,
            size, 
            total_num, 
            left_num, 
            min_lef_num);
    ret = kal_afm_info_get(
            g_mmi_fix_mem_cntx.afm_id,
            &option,
            size,
            total_num,
            left_num,
            &total_left);
    return ret;
}

#ifdef __MMI_AFM_TEST__
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_fix_mem_test
 * DESCRIPTION
 *  This function is used to test fix memory buffer allocate and free
 * 
 * PARAMETERS
 *  index       : [IN] the required memory size
 * RETURNS
 *  The address of the allocated buffer
 *****************************************************************************/
static void mmi_frm_fix_mem_test(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    U32 i = 0;
    U32 j = 0;
    void *p;
    void *ptr[SUB_POOL_NUM1 + SUB_POOL_NUM2 + SUB_POOL_NUM3 + SUB_POOL_NUM4];
    U32 count = 0;
    U32 size[MMI_AFM_SUB_POOL_NUM + 1];
    U32 total_num[MMI_AFM_SUB_POOL_NUM + 1];
    U32 left_num[MMI_AFM_SUB_POOL_NUM + 1];
    U32 min_left_num[MMI_AFM_SUB_POOL_NUM + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size[MMI_AFM_SUB_POOL_NUM] = AFM_SUBPOOL_END_PATTERN;
    total_num[MMI_AFM_SUB_POOL_NUM] = AFM_SUBPOOL_END_PATTERN;
    left_num[MMI_AFM_SUB_POOL_NUM] = AFM_SUBPOOL_END_PATTERN;
    min_left_num[MMI_AFM_SUB_POOL_NUM] = AFM_SUBPOOL_END_PATTERN;  
    while(g_mmi_afm_sub_pools_size[i] != AFM_SUBPOOL_END_PATTERN)
    {
        for (j = 0; j < g_mmi_afm_sub_pools_num[i]; j++)
        {
            p = mmi_frm_fix_mem_alloc(g_mmi_afm_sub_pools_size[i]);
            MMI_ASSERT(p!= NULL);
            ptr[count] = p;
            count++;
        }
        i++;
    }
    mmi_frm_fix_mem_get_info(size, total_num, left_num, min_left_num, MMI_AFM_SUB_POOL_NUM + 1);
    for (i = 0; i < MMI_AFM_SUB_POOL_NUM; i++)
    {
        MMI_ASSERT(min_left_num[i] == 0);
        MMI_ASSERT(left_num[i] == 0);
    }  
    for (i = 0; i < count; i++)
    {
        mmi_frm_fix_mem_free(ptr[i]);
    } 
  
    mmi_frm_fix_mem_get_info(size, total_num, left_num, min_left_num, MMI_AFM_SUB_POOL_NUM + 1);
    for (i = 0; i < MMI_AFM_SUB_POOL_NUM; i++)
    {
        MMI_ASSERT(min_left_num[i] == 0);
        MMI_ASSERT(left_num[i] == total_num[i]);
    }
    i = 0;
    count = 0;
    while(g_mmi_afm_sub_pools_size[i] != AFM_SUBPOOL_END_PATTERN)
    {
        for (j = 0; j < g_mmi_afm_sub_pools_num[i]; j++)
        {
            p = mmi_frm_malloc(g_mmi_afm_sub_pools_size[i]);
            MMI_ASSERT(p!= NULL);
            MMI_ASSERT(is_in_fix_size_buf_pool(p) == MMI_TRUE);
            ptr[count] = p;
            count++;
        }
        i++;
    }
    mmi_frm_fix_mem_get_info(size, total_num, left_num, min_left_num, MMI_AFM_SUB_POOL_NUM + 1);
    for (i = 0; i < MMI_AFM_SUB_POOL_NUM; i++)
    {
        MMI_ASSERT(min_left_num[i] == 0);
        MMI_ASSERT(left_num[i] == 0);
    }
    for (i = 0; i < MMI_AFM_SUB_POOL_NUM; i++)
    {
        p = mmi_frm_malloc(size[i]);
        MMI_ASSERT(is_in_fix_size_buf_pool(p) == MMI_FALSE);
        mmi_frm_free(p);
    }
    for (i = 0; i < count; i++)
    {
        mmi_frm_fix_mem_free(ptr[i]);
    }
}
#endif /* __MMI_AFM_TEST__ */

