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
 * fmt_main.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _FMT_MAIN_H
#define _FMT_MAIN_H

#ifndef FMT_NOT_PRESENT

/****************************************************************************
* Include Files                                                                
*****************************************************************************/

#include "fmt_def.h"

#include "kal_general_types.h"
#include "syscomp_config.h"
#include "stack_config.h"
#include "app_ltlcom.h"
// by RHR //#include "task_main_func.h"
#include "stack_msgs.h"
#if defined(PLUTO_MMI)  /* temp solution for FS */
#include "fs_type.h"
#endif

/****************************************************************************
* Define
*****************************************************************************/
typedef enum
{
    FMT_MSDC_STATE_UNINIT,
    FMT_MSDC_STATE_PLUG_IN,
    FMT_MSDC_STATE_PLUG_OUT
} fmt_msdc_state_enum;

typedef kal_bool (*CheckFilterFuncPtr) (void* delete_filter_type, kal_uint16 type, kal_int8 *ext);
typedef kal_int8 (*GetDeletePathFuncPtr) (kal_int8** file_path);
typedef kal_int8 (*GetCopyPathFuncPtr) (kal_int8** src_path, kal_int8** dest_path);

/****************************************************************************
* Export API
*****************************************************************************/
extern kal_bool fmt_create(comptask_handler_struct **handle);
extern kal_bool fmt_init(task_indx_type task_indx);
extern kal_bool fmt_reset(task_indx_type task_indx);
extern void fmt_init_drive(void);
extern void fmt_main(ilm_struct *ilm_ptr);
extern void fmt_task_main(task_entry_struct *task_entry_ptr);

#if defined(NEPTUNE_MMI)
extern void fmt_copy_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_delete_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif
#ifdef __DRM_SUPPORT__
extern void fmt_delete_ro_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_process_drm_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif

extern void fmt_calculate_free_space(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_format_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_format_done_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_check_drive_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_get_msdc_status_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

#if defined(NEPTUNE_MMI)
extern kal_int32 fmt_delete_by_filter_hdlr(kal_uint8 *path, void *filter_mask, CheckFilterFuncPtr check_callback);
extern kal_int32 fmt_delete_several_files_hdlr(kal_int8 *path, GetDeletePathFuncPtr check_callback);

extern int fmt_copy_rsp_hdlr(int action, UINT total, UINT completed, UINT handle);
extern void fmt_abort_copy(void);
extern kal_bool fmt_get_abort_copy(void);

extern void fmt_reset_abort_copy(void);
#endif
#ifdef __FS_CARD_SUPPORT__
extern void fmt_card_detect_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_unmount_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif /* __FS_CARD_SUPPORT__ */ 

#ifdef __OTG_ENABLE__
extern void fmt_otg_card_detect_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_otg_remove_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_otg_insert_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_otg_display_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif /* __OTG_ENABLE__ */ 

#ifdef __SIM_PLUS__
extern void fmt_sim_plus_detect_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif

#if defined(__FOTA_DM__)
extern void fmt_fota_init_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_fota_write_data_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void fmt_fota_finalize_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif /* #if defined(__FOTA_DM__)*/

#if defined(__FS_SORT_SUPPORT__) && defined(PLUTO_MMI)
extern void fmt_load_dir_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern kal_bool fmt_load_dir_cancel(void);
#endif

/*FS Test*/
#if defined (__MMI_EM_PROFILING_FS_TEST__)
extern void fmt_test_start_handler(local_para_struct *local_para_ptr,peer_buff_struct * peer_buff_ptr);

extern kal_bool fmt_test_save_file_handler(local_para_struct *local_para_ptr,peer_buff_struct * peer_buff_ptr);
#endif
/*FS Test*/

#ifdef PLUTO_MMI
extern kal_uint32 fmt_adv_send_message(msg_type msg_id, local_para_struct* local_para, peer_buff_struct* peer_buff);
extern kal_bool fmt_adv_abort_message(kal_uint32 msg_seq, kal_bool wait, kal_bool cancel_rsp);
extern fmt_adv_seq_state_enum fmt_adv_get_message_state(kal_uint32 msg_seq);

extern kal_int32 fmt_adv_load_folder_check_changed(const WCHAR* folderpath);
extern void fmt_adv_load_folder_check_release(const WCHAR* folderpath);

extern void fmt_move_ext_q_to_int_q(kal_msgqid task_ext_qid, kal_bool wait);
extern void fmt_clear_invalid_ilm_from_int_q(void);
extern kal_bool fmt_adv_int_queue_abort_hdlr(ilm_struct *ilm_ptr);
#endif

#endif /* FMT_NOT_PRESENT */ 

#endif /* _FMT_MAIN_H */ 

