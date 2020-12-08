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
 *    fix_size_mem.h
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
#ifndef FIX_SIZE_MEM_H
#define FIX_SIZE_MEM_H

//RHR Add
#include "kal_afm.h"
#include "MMIDataType.h"
#include "mmi_features.h"
/***************************************************************************** 
* Define
*****************************************************************************/
#define MMI_AFM_SUB_POOL_NUM  (4)

#define SUB_POOL_SIZE1    (16)
#ifdef __COSMOS_MMI_PACKAGE__
#define SUB_POOL_NUM1     (220)

#elif defined(__MMI_VUI_WIDGET_KEY_MESSAGE__)
#define SUB_POOL_NUM1     (130)

#else
#define SUB_POOL_NUM1     (100)
#endif

#define SUB_POOL_SIZE2    (36)
#define SUB_POOL_NUM2     (30)

#define SUB_POOL_SIZE3    (92)
#define SUB_POOL_NUM3     (60)

#define SUB_POOL_SIZE4    (128)
#define SUB_POOL_NUM4     (15)

#ifdef MMI_AFM_DEBUG
#define MMI_AFM_OPTION  (AFM_OPT_DBG | AFM_OPT_CUSLOG | AFM_OPT_NOFALLBACK_ALLOC)
#else
#define MMI_AFM_OPTION  (AFM_OPT_NOFALLBACK_ALLOC)
#endif

#define MMI_AFM_POOL_SIZE     (KAL_AFM_POOL_OVERHEAD(MMI_AFM_OPTION, MMI_AFM_SUB_POOL_NUM) +\
                              KAL_AFM_SUBPOOL_OVERHEAD(MMI_AFM_OPTION, SUB_POOL_SIZE1, SUB_POOL_NUM1) +\
                              KAL_AFM_SUBPOOL_OVERHEAD(MMI_AFM_OPTION, SUB_POOL_SIZE2, SUB_POOL_NUM2) +\
                              KAL_AFM_SUBPOOL_OVERHEAD(MMI_AFM_OPTION, SUB_POOL_SIZE3, SUB_POOL_NUM3) +\
                              KAL_AFM_SUBPOOL_OVERHEAD(MMI_AFM_OPTION, SUB_POOL_SIZE4, SUB_POOL_NUM4))

#define SUB_POOL_SIZE_DATA  {SUB_POOL_SIZE1, SUB_POOL_SIZE2, SUB_POOL_SIZE3, SUB_POOL_SIZE4, AFM_SUBPOOL_END_PATTERN}
#define SUB_POOL_NUM        {SUB_POOL_NUM1, SUB_POOL_NUM2, SUB_POOL_NUM3, SUB_POOL_NUM4, AFM_SUBPOOL_END_PATTERN}

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
extern void mmi_frm_fix_mem_init(void);

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
extern void* mmi_frm_fix_mem_alloc(U32 size);

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
extern void mmi_frm_fix_mem_free(void *p);

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
extern void mmi_frm_fix_mem_check_intigrity(void);

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
extern U32 mmi_frm_fix_mem_get_info(U32 *size, U32 *total_num, U32 *left_num, U32 *min_lef_num, U32 entry_num);

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
extern void *mmi_frm_malloc(U32 size);

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
extern void mmi_frm_free(void *p);

#endif /* FIX_SIZE_MEM_H */

