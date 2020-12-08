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
 *    mmi_frm_temp_mem.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Temp memory mechanism
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_frm_gprot.h"
/*************Header and footer guard pattern in each block*****/
#define FRM_TEMP_HEADER_GARDPATTERN  (0xAAAAAAAA)
#define FRM_TEMP_FOOTER_GARDPATTERN  (0xCCCCCCCC)
/******Assume that each application max allocates ten times******/
#define FRM_TEMP_ALLOCATE_MAX_NUM    (10)
/***** Header and footer guard pattern size*******/
#define FRM_TEMP_CHUNK_OVERHEAD       (12)
/**************8 is ADM over head*********************/
#define FRM_TEMP_CHUNK_EXTRA_SIZE     (8 + FRM_TEMP_CHUNK_OVERHEAD)
#define FRM_TEMP_GET_POOL_EXTRA_SIZE(n)  (168 + (n) * FRM_TEMP_CHUNK_EXTRA_SIZE) 

#define MMI_FRM_TEMP_MEM_POOL_SIZE (20*1024 + FRM_TEMP_GET_POOL_EXTRA_SIZE(FRM_TEMP_ALLOCATE_MAX_NUM))

/**** make sure 4byte align*******/
static S32 g_mmi_frm_temp_pool[(MMI_FRM_TEMP_MEM_POOL_SIZE + 3)/4];

/*******temp memory context *********/
typedef struct
{
   KAL_ADM_ID pool_id;
   U32 allocate_num;
} mmi_frm_temp_mem_cntx;

/*******temp memory header *********/
typedef struct
{
    U32 guard_pattern;
    U32 size;
} mmi_frm_temp_header;

/*******temp memory footer *********/
typedef struct
{
    U32 guard_pattern;
} mmi_frm_temp_footer;

static mmi_frm_temp_mem_cntx g_frm_temp_mem_cntx;



/*****************************************************************************
 * FUNCTION
 *  mmi_frm_temp_mem_init
 * DESCRIPTION
 *  init temp memory during boot up process, this is used by framework only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_temp_mem_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_frm_temp_mem_cntx.pool_id)
    {
        g_frm_temp_mem_cntx.pool_id = kal_adm_create((void *)g_mmi_frm_temp_pool, sizeof(g_mmi_frm_temp_pool), NULL, KAL_FALSE);
        g_frm_temp_mem_cntx.allocate_num = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_temp_check_all_free
 * DESCRIPTION
 *  check if all temp memory is free after a primitive. The temp memory life cycle is 
 *  during a primitive. If it's not free all , it will be assert. This function is used
 *  by framework only.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_temp_check_all_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if(g_frm_temp_mem_cntx.allocate_num > 0)
    {
        MMI_ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_temp_alloc
 * DESCRIPTION
 *  Temp memory allocate function. Temp memory life cyle is in a primitive. And the
 *  size is 20K. You must free the memory when the primitive is end. When allocate fail,
 *  it will be assert just like control buffer. Temp memory can only be used in MMI Task.
 * PARAMETERS
 *  size   : [IN] allocate size.
 * RETURNS
 *  The address of the allocated memory.
 *****************************************************************************/
void* mmi_frm_temp_alloc_int(U32 size, U32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr = NULL;
    U32 block_size;
    mmi_frm_temp_header *header;
    mmi_frm_temp_footer *footer;
    void *ptrRe;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //size need to 4 bytes align.
    if (size == 0)
    {
        return NULL;
    }
    block_size = ((size + 3) >> 2) << 2;
    ptr = kal_adm_alloc(g_frm_temp_mem_cntx.pool_id, block_size + FRM_TEMP_CHUNK_OVERHEAD);
    if (ptr)
    {
        header = (mmi_frm_temp_header*)ptr; 
        header->guard_pattern = FRM_TEMP_HEADER_GARDPATTERN;
        header->size = block_size;
        ptrRe = header + 1;
        footer = (mmi_frm_temp_footer*)((S8*)ptrRe + block_size);
        footer->guard_pattern = FRM_TEMP_FOOTER_GARDPATTERN;
        g_frm_temp_mem_cntx.allocate_num++;
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_TEMP_MEM_ALLOC, ptrRe, line);
    }
    else
    {
        MMI_ASSERT(0);
    }
    return ptrRe;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_temp_free
 * DESCRIPTION
 *  Temp memory free function. 
 * PARAMETERS
 *  ptr    : [IN] The free memory pointer.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_temp_free_int(void* ptr, U32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_temp_header *header;
    mmi_frm_temp_footer *footer;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_frm_temp_mem_cntx.allocate_num > 0);
    if (ptr)
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, MMI_FRM_TEMP_MEM_FREE, ptr, line);
        header = (mmi_frm_temp_header*)ptr - 1;
        footer = (mmi_frm_temp_footer*)((S8*)ptr + (header->size));
        MMI_ASSERT((header->guard_pattern) == FRM_TEMP_HEADER_GARDPATTERN);
        MMI_ASSERT((footer->guard_pattern) == FRM_TEMP_FOOTER_GARDPATTERN);
        kal_adm_free(g_frm_temp_mem_cntx.pool_id, header);
        g_frm_temp_mem_cntx.allocate_num--;
    }
    else
    {
       /*when allocate fail, it will be assert.*/
       MMI_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_temp_get_allocate_num
 * DESCRIPTION
 *  Get the allocate number of temp memory. This function is used by framework.
 * PARAMETERS
 *  void
 * RETURNS
 *  The allocate number.
 *****************************************************************************/
U32 mmi_frm_temp_get_allocate_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_frm_temp_mem_cntx.allocate_num;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_temp_get_max_left_size
 * DESCRIPTION
 *  The max allocated size of temp memory. You can use this function to query, if
 *  you could use temp memory
 * PARAMETERS
 *  void
 * RETURNS
 *  The max allocate size.
 *****************************************************************************/
U32 mmi_frm_temp_get_max_left_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 size;
    U32 overhead;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size = kal_adm_get_max_alloc_size(g_frm_temp_mem_cntx.pool_id);
    overhead = sizeof(mmi_frm_temp_header) + sizeof(mmi_frm_temp_footer);
    if (size < overhead)
    {
        return 0;
    }
    size -= overhead;

    return size;
}



 

