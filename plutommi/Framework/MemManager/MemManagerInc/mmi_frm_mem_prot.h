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
 *  mmi_frm_mem_prot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  header file for ASM core related.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef __MMI_FRM_MEM_PROT_H__
#define __MMI_FRM_MEM_PROT_H__
    
#ifdef __cplusplus
    extern "C"
    {
#endif

#include "mmidatatype.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define MMI_FRM_ASM_SCENARIO_ID    (MMI_SCENARIO_ID_HIGH_SCRN)

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/* asm internal event */
typedef enum {
    EVT_ID_ASMI_STOP_FINISHED = EVT_ID_ASM_END + 1, /* mmi_frm_asmi_stop_finished_evt_struct */
    EVT_ID_ASMI_APP_FREE_ALL_MEM,
    EVT_ID_ASMI_END
} mmi_frm_asmi_evt_enum;


/* post event struct for auto-prompt */
typedef struct {
    MMI_EVT_PARAM_HEADER
    mmi_id app_id;
    U32 required_size;  /*total required size ( = non-continuous part + continuous part)*/
    U32 required_subsize_continuous; /*the sub size of continuous part, useful for MMv2 case*/
    mmi_proc_func callback;
    MMI_BOOL f_force_prompt;
} mmi_frm_appmem_auto_prompt_evt_struct;


typedef struct {
    MMI_EVT_PARAM_HEADER
    U32 str_id;
    mmi_id app_id;
    MMI_BOOL result;
} mmi_frm_asmi_stop_finished_evt_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    mmi_id app_id;
} mmi_frm_asmi_app_all_mem_freed_evt_struct;

typedef enum
{
    /* Normal case */
    MMI_FRM_ASM_MANAGER_STATE_NORMAL,
    /* After user choose yes in confirm screen, update state to waiting */
    MMI_FRM_ASM_MANAGER_STATE_WAITING,
    /* Atfer call notify stop finish, update state to finish */
    MMI_FRM_ASM_MANAGER_STATE_FINISHED,
    /* After execute cancel callback, update state to canceled */
    MMI_FRM_ASM_MANAGER_STATE_CANCELED
} mmi_frm_asm_manager_state_enum;

typedef enum
{
    /* asm is preparing memory */
    MMI_FRM_ASM_IS_PREPARING_MEMORY,
    /* asm is waiting for app release memory */
    MMI_FRM_ASM_IS_WAITING_APP_STOP,    
    /* asm does not prepare memory */
    MMI_FRM_ASM_NOT_PREPARE_MEMORY
} mmi_frm_asm_state_enum;

/***************************************************************************** 
 * interface 
 *****************************************************************************/

extern mmi_id mmi_frm_asm_manager_launch(mmi_id caller_id);
extern void mmi_frm_asm_manager_close(mmi_id asm_mgr_id);
extern MMI_BOOL mmi_frm_asm_manager_is_launched(mmi_id *id_ptr);
extern mmi_id mmi_frm_asm_manager_get_app_id(void);

extern mmi_ret mmi_frm_appmem_auto_prompt_screen(mmi_frm_appmem_auto_prompt_evt_struct *evt);
extern void mmi_frm_appmem_stop_finished(kal_uint32 app_id, kal_uint32 string_id, kal_bool result);
extern U16 mmi_frm_asm_get_manger_state(void);
extern U16 mmi_frm_asm_get_asm_state(void);
extern void mmi_frm_asm_stop_app_by_MMI_task(kal_uint32 app_id, applib_mem_ap_stop_type stop_type);
extern void mmi_frm_asm_get_applist_in_pool(applib_mem_ap_usage_struct* app_list, U32 num);
extern void mmi_frm_asm_get_reserve_size(U32* total_reserve, U32* global_reserve );
extern U32 mmi_frm_asm_get_asm_commom_pool_reserve_qouta(void);
extern MMI_BOOL mmi_frm_asmi_invoke_cancel_callback(mmi_id app_id, mmi_frm_appmem_event_type_enum type);
extern void mmi_frm_asmi_invoke_success_callback(mmi_id app_id);
extern MMI_BOOL mmi_frm_appmem_is_in_first_stage(void);
extern MMI_BOOL mmi_frm_is_app_hide_in_oom(MMI_ID app_id);
extern MMI_BOOL mmi_frm_asmi_check_enough_memory(mmi_id app_id);
extern void mmi_frm_appmem_stage1_init(void);
#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif /* __MMI_FRM_MEM_PROT_H__ */ 


