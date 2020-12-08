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
 *  adv_asm_defs.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  Memory monitor header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef MMI_MEM_MONITOR_H
#define MMI_MEM_MONITOR_H
#include "MMI_features.h"
#include "MMIDataType.h"

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
#ifdef __MMI_MEMORY_MONITOR__


typedef struct
{
    U32 maximal_alloc_size;
    U32 current_alloc_size;
    U32 total_alloc_count;
    U32 total_alloc_size;
} partition_mem_alloc_struct;

typedef struct
{
    U32 register_scr_mem_size;
    U32 current_scr_alloc_size;
    U32 maximal_scr_alloc_size;
    U32 scr_alloc_count;
    U32 register_app_mem_size;
    U32 current_app_alloc_size;
    U32 maximal_app_alloc_size;
    U32 app_alloc_count;
} asm_mem_alloc_info_struct;

typedef enum
{
    MEM_MON_DYNAMIC_DATA,
    MEM_MON_STATIC_DATA,
    MEM_MON_DATA_TYPE_TOTAL
} mmi_mem_monitor_data_type;

typedef enum
{
    MMI_EM_MEMORY_MONITOR_OFF,
    MMI_EM_MEMORY_MONITOR_OSL,
    MMI_EM_MEMORY_MONITOR_ASM,
    MMI_EM_MEMORY_MONITOR_TOTAL
} mmi_mem_monitor_type_enum;


/*****************************************************************************
 * Global Function                                                              
 *****************************************************************************/
extern void mmi_mem_mon_profiling_memory_monitor(mmi_frm_mem_type mem_type);
extern void mmi_mem_mon_update_detail_info(mmi_frm_mem_type monitor_type);
extern mmi_mem_monitor_type_enum mmi_mem_mon_profiling_get_enable(void);
extern void mmi_mem_mon_profiling_set_enable(mmi_mem_monitor_type_enum enable);
extern void mmi_mem_mon_construct_static_statistic(U16 *unicode_buff, U32 buff_size);

#endif /* __MMI_MEMORY_MONITOR__ */
#endif /* MMI_MEM_MONITOR_H */

