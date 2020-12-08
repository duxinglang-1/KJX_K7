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
 * drm_main.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef DRM_MAIN_H
#define DRM_MAIN_H

#ifdef __DRM_SUPPORT__
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "app_ltlcom.h"
#include "drm_def.h"
#include "drm_errcode.h"
#include "fs_type.h"

#define DRM_REGULAR_CHECK_PERIOD 500    /* MS */

#if !defined(__DRM_EXTERNAL__)
#if defined(__DRM_V02__) 
#define DRM_CHECK_TIME_PERIODICALLY
#endif 

typedef struct
{
    kal_int32 handle;
#ifdef DRM_CHECK_TIME_PERIODICALLY
    drm_cid_struct *cid;
    kal_uint32 chkpoint;
    kal_uint32 time_passed;
    kal_int32 *evid;
    module_type source;
    drm_constraint_struct cons;
    void (*callback) (kal_int32 result, kal_int32 id);
    kal_bool is_paused;
    kal_bool is_waiting_clean;
    kal_bool cb_executed;
#endif /* DRM_CHECK_TIME_PERIODICALLY */ 
    kal_bool count_minus;
} drm_consumer_struct;
#endif /* __DRM_EXTERNAL__ */

extern kal_bool drmt_engine_is_ready(void);
extern void drmt_check_engine_ready(void);

#if !defined(__DRM_EXTERNAL__)
extern kal_bool drmt_engine_is_busy(void);
extern void drmt_engine_set_busy(kal_bool is_busy);
extern kal_bool drmt_engine_is_process_database(void);
extern void drmt_engine_set_process_database(kal_bool is_process_database);
extern void *drmt_start_timer(kal_uint32 time_in_millisec, void *arg, kal_timer_func_ptr callback);
extern void drmt_stop_timer(void *id);

extern void drmt_evshed_expiry_hdlr(void *local_para_ptr, void *peer_buff_ptr);

extern kal_bool drmt_get_next_msg(kal_bool(*current_msg_handler) (ilm_struct *ilm_ptr),
                                  kal_bool wait_forever, kal_bool *abort_msg_received, kal_bool abort_skip);

extern kal_int32 drmt_create_consumer(void);
extern void drmt_clean_consume(kal_int32 id);
extern kal_int32 drmt_get_consumer_by_ref(void *arg);
extern void drmt_consume_set_cb_executed(kal_int32 id);
extern kal_bool drmt_consume_is_cb_executed(kal_int32 id);
extern kal_bool drmt_update_consumer(kal_int32 consumer);
extern void drmt_consume_timeout_hdlr(void *arg);

#define DRM_SDB_HEADER_PATTERN 0x6221
#define DRM_SDB_FOOTER_PATTERN 0x6248

#define DRM_SDB_ATTR_DELETED (0)
#define DRM_SDB_ATTR_VALID (1)
#define DRM_SDB_ATTR_RESERVED (2)

#define DRM_CID_DB_FILEPATH DRM_PATH L"cid.db"
#define DRM_CID_DB_BACKUP_FILEPATH DRM_PATH L"cid._b"

typedef struct
{
    kal_int16 header;
    kal_int16 attr;
    kal_uint8 *data;
    kal_uint16 data_len;
    kal_int16 footer;
} drm_sdb_struct;

extern kal_bool drmt_sdb_check_pattern(drm_sdb_struct *entry);
extern kal_int32 drmt_sdb_delete(kal_wchar *db_path, kal_uint8 *data, kal_uint16 data_len,
                                 kal_bool(*compare_func) (kal_uint8 *, kal_uint16, drm_sdb_struct *));
extern kal_int32 drmt_sdb_add(kal_wchar *db_path, kal_uint8 *data, kal_uint16 data_len, kal_int16 attr);
extern kal_int32 drmt_sdb_search(kal_wchar *db_path, kal_uint8 *data, kal_uint16 data_len,
                                 kal_bool(*compare_func) (kal_uint8 *, kal_uint16, drm_sdb_struct *));
extern kal_int32 drmt_sdb_restore(kal_wchar *db_path, kal_wchar *backup_path);
extern kal_int32 drmt_sdb_backup(kal_wchar *db_path, kal_wchar *backup_path);
extern kal_int32 drmt_sdb_check(kal_wchar *db_path);
extern kal_int32 drmt_sdb_sweep(kal_wchar *db_path, kal_wchar *backup_path);

extern void drmt_async_set_current_serial(kal_uint8 serial);
extern kal_uint8 drmt_async_get_current_serial(void);
extern kal_uint8 drmt_async_get_serial(void);
extern kal_bool drmt_async_free_serial(kal_uint8 serial);
extern kal_bool drmt_async_set_status(kal_uint8 serial, drm_proc_enum status);
extern kal_int32 drmt_async_get_status(kal_uint8 serial);
extern kal_int32 drmt_async_get_operate_handle(kal_uint8 serial);
extern kal_int32 drmt_async_cancel_process(kal_uint8 serial);

extern kal_int32 drmt_scan_enqueue(kal_wchar *file_path, kal_bool first_child);
extern kal_int32 drmt_scan_dequeue(kal_wchar *file_path);
extern kal_int32 drmt_scan_sweep_queue(void);
extern kal_int32 drmt_scan_init_queue(kal_bool reset_queue);
extern kal_int32 drmt_scan_disk(kal_uint8 serial, kal_uint8 type, kal_wchar *path);

extern kal_bool drmt_msg_handler(ilm_struct *current_ilm, kal_bool drm_is_blocking);

#ifdef __DRM_SUPPORT_SD_CALLBACK__
extern kal_int32 drmt_sd_callback_register(
                    FS_HANDLE input,
                    kal_uint32 timer,
                    void *para,
                    drm_sd_callback callback);
extern void drmt_sd_callback_timer_expiry(void *serial);
extern void drmt_sd_callback_clear_entry(kal_uint8 serial);
extern void drmt_sd_callback_update(kal_uint8 serial);
extern void drmt_sd_callback_rights_arrive(kal_uint8 serial, kal_char *cid);
extern void drmt_sd_callback_exec_cb(kal_uint8 serial, kal_uint8 type);
extern kal_bool drmt_sd_callback_status(kal_uint8 serial);
#endif /* __DRM_SUPPORT_SD_CALLBACK__ */ 
#endif /* __DRM_EXTERNAL__ */
#endif /* __DRM_SUPPORT__ */ 

#endif /* DRM_MAIN_H */ 

