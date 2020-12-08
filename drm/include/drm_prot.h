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
 * drm_prot.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef DRM_PROT_H
#define DRM_PROT_H

#include "app_mine.h"
#include "app_datetime.h"
#include "kal_general_types.h"
#include "fs_type.h"
#include "drm_def.h"
#include "app_ltlcom.h"
#include "drm_errcode.h"

#define DRM_DEBUG(x, y) kal_trace y
#define DRM_DEBUGP(x) drm_trace x
#define DRM_STIME_EXPIRE_PERIOD 3600*12*1000

extern void *drmt_start_timer(kal_uint32 time_in_millisec, void *arg, kal_timer_func_ptr callback);

extern kal_int32 drm_core_init(void);
extern kal_int32 drm_core_init_engine(void);
extern kal_int32 drm_core_async_get_handle(void);
extern kal_int32 drm_core_async_free_handle(kal_int32 handle);
extern kal_int32 drm_core_async_cancel_handle(kal_int32 handle);
extern kal_int32 drm_core_close_file(FS_HANDLE object);
extern kal_int32 drm_core_file_pos(FS_HANDLE source, kal_uint32 *pos);
extern kal_int32 drm_core_file_size(FS_HANDLE source, kal_uint32 *size);
extern kal_int32 drm_core_get_constraint(FS_HANDLE handle, kal_uint8 permission, drm_constraint_struct *cons);
extern kal_uint8 drm_core_get_object_method(FS_HANDLE input);
extern kal_int32 drm_core_get_rights_issuer(FS_HANDLE input, kal_char *buffer, kal_uint32 *size);
extern kal_bool drm_core_msg_handler(ilm_struct *current_ilm, kal_bool drm_is_blocking);
extern kal_int32 drm_core_register_file(kal_wchar *ucs2path);
extern FS_HANDLE drm_core_open_file(kal_wchar *file_path, kal_uint32 flags, kal_uint8 permission);
extern FS_HANDLE drm_core_open_file_aux(
                    kal_wchar *file_path,
                    kal_uint32 flags,
                    kal_uint8 permission,
                    kal_bool want_to_register);
extern kal_int32 drm_core_install_object(
                    kal_uint8 serial,
                    kal_int32 drm_type,
                    kal_wchar *src_path,
                    kal_bool src_need_kept,
                    kal_wchar *dest_path,
                    kal_uint32 dest_buffer_len_in_byte,
                    applib_mime_type_struct **mime_type);

extern kal_int32 drm_core_delete_ro_by_seed(kal_uint8 *seed, kal_int32 seed_len);

extern kal_int32 drm_core_parse_drm_message(
                    kal_uint8 serial,
                    kal_wchar *src_path,
                    kal_uint8 *seed,
                    kal_int32 seed_len,
                    drm_message_info_struct *info);

extern kal_int32 drm_core_encode_drm_message(
                    kal_uint8 serial,
                    kal_wchar *src_path,
                    kal_wchar *dest_path,
                    kal_uint32 offset);

extern kal_int32 drm_core_predict_encoded_size(kal_wchar *src_path);

/*
 * extern drm_proc_enum drm_core_read_buffer(drm_rights_struct *rights, kal_uint8 *buffer, kal_uint32 size);
 */

extern drm_proc_enum drm_core_read_file(FS_HANDLE source, void *buffer, kal_uint32 size, kal_uint32 *length);

extern kal_int32 drm_core_consume_rights(
                    FS_HANDLE source,
                    kal_uint8 permission,
                    kal_bool count_minus,
                    drm_constraint_struct *cons);

extern kal_int32 drm_core_update_consumer(
                    kal_int32 handle,
                    kal_uint32 time_passed,
                    kal_bool count_minus,
                    drm_rights_status_enum *status);
extern kal_int32 drm_core_update_consumer_by_cid(
                    kal_int32 handle,
                    kal_uint32 time_passed,
                    kal_bool count_minus,
                    drm_rights_status_enum *status);

extern void drm_core_stop_consume(kal_int32 handle);
extern void drm_core_stop_consume_by_cid(kal_int32 handle);

extern kal_int32 drm_core_seek_file(FS_HANDLE source, kal_int32 offset, kal_uint8 ref);
extern kal_int64 drm_core_seek_large_file(FS_HANDLE source, kal_int64 offset, kal_uint8 ref);
extern kal_int32 drm_core_set_seek_hint(FS_HANDLE handle, kal_uint32 HintNum, FS_FileLocationHint *Hint);

extern kal_bool drm_core_validate_permission(FS_HANDLE input, kal_uint8 permission);
extern kal_bool drm_core_validate_timed_permission(FS_HANDLE input, kal_uint8 permission);
extern kal_bool drm_core_validate_future_permission(FS_HANDLE input, kal_uint8 permission);
extern kal_bool drm_core_validate_permission_by_cid(drm_cid_struct *cid, kal_uint8 permission, kal_bool time_only);

extern drm_proc_enum drm_core_get_content_type(FS_HANDLE input, applib_mime_type_struct **entry);
extern kal_bool drm_core_interdev_movable(FS_HANDLE handle);
extern kal_char *drm_core_release_verno(void);

/*
 * extern void drm_core_set_delivery_time(drm_info_struct *info, kal_uint32 delta);
 * extern kal_uint32 drm_core_get_delivery_time(FS_HANDLE handle);
 */
extern void drm_core_write_nvram(kal_uint16 lid, kal_uint16 rec, void *data);
extern void drm_core_read_nvram(kal_uint16 lid, kal_uint16 rec, kal_uint16 amount);

extern kal_uint8 drm_core_get_object_method_by_ref(kal_int32 ro_index, drm_proc_db_ro_count_flag_enum flag);
extern kal_int32 drm_core_get_constraint_by_ref(kal_int32 ro_index, kal_uint8 permission, drm_constraint_struct *cons);
extern void drm_core_free_ro_detail(void);
extern kal_int32 drm_core_get_meta_size(FS_HANDLE input, drm_meta_enum meta_id);
extern kal_int32 drm_core_get_meta_data(FS_HANDLE input, drm_meta_enum meta_id, kal_char *buffer, kal_int32 size);

extern kal_int32 drm_core_get_ro_num(kal_uint8 serial, drm_proc_db_ro_count_flag_enum flag);
extern kal_int32 drm_core_get_ro(kal_int32 index, char *alias, kal_uint32 size, drm_proc_db_ro_count_flag_enum flag);
extern void drm_core_free_ro_list(void);
extern kal_int32 drm_core_get_ro_dbsize(kal_int32 *max);
extern kal_bool drm_core_get_stime(applib_time_struct *time);
extern kal_int32 drm_core_process_db(kal_uint8 serial, kal_uint8 type, kal_int32 index, kal_wchar *path);
extern void drmt_sd_callback_insert_timer_id(kal_uint8 serial, void *timer_id);

#ifdef __DRM_V02__
#ifndef __APP_DATETIME_H__
#error "Please include app_datetime.h first!"
#endif 
#ifndef DRM_GPROT_H
#error "Please include drm_gprot.h first!"
#endif 

/* Multi-part DCF */
extern void *drm_core_get_find_cntx(void);
extern FS_HANDLE drm_core_find_firstN(
                    void *context,
                    kal_wchar *file_path,
                    FS_Pattern_Struct *PatternArray,
                    kal_uint32 PatternNum,
                    drm_file_info_struct *FileInfo,
                    kal_wchar *FileName,
                    kal_uint32 MaxLen,
                    kal_int32 EntryIndex);
extern kal_int32 drm_core_find_nextN(
                    void *context,
                    FS_HANDLE handle,
                    drm_file_info_struct *FileInfo,
                    kal_wchar *FileName,
                    kal_uint32 MaxLen,
                    kal_int32 distance);
extern kal_int32 drm_core_find_close(void *context, FS_HANDLE object);
extern kal_bool drm_core_toggle_tracking(kal_bool to_get);
extern kal_int32 drm_core_get_domain_num(void);
extern kal_bool drm_core_get_trust_state(void);
extern kal_bool drm_core_is_archive(FS_HANDLE handle);
extern kal_bool drm_core_is_archive_object(FS_HANDLE handle);
extern void drm_core_update_local_time(applib_time_struct *old_time, applib_time_struct *new_time, kal_bool reliable);

extern kal_int32 drm_core_init_whitelist(void);
extern kal_bool drm_core_get_whitelist(kal_char *list_buffer, kal_uint8 index);
extern kal_int32 drm_core_add_whitelist(kal_char *list_buffer);
extern kal_bool drm_core_del_whitelist(kal_char *list_buffer);
extern void drm_core_free_whitelist(void);

extern kal_bool drm_core_is_ro_shareable(kal_int32 index);
extern kal_int32 drm_core_import_cer(kal_wchar *path);

#if defined(__DRM_PDCF__)
extern kal_int32 drm_core_construct_pdcf(kal_int32 file_handle);
extern kal_int32 drm_core_init_track_by_kms(
                    kal_int32 pdcf_handle,
                    kal_int32 trackID,
                    kal_uint8 permission,
                    drm_track_kms_struct *kms);
extern kal_int32 drm_core_init_track_by_meta(
                    kal_int32 pdcf_handle,
                    kal_int32 trackID,
                    kal_uint8 permission,
                    drm_track_meta_struct *meta);
extern kal_int32 drm_core_destruct_pdcf(kal_int32 pdcf_handle);
extern kal_int32 drm_core_decode_track(
                    kal_int32 track_handle,
                    kal_uint8 *src,
                    kal_uint32 srcSize,
                    kal_uint8 *out,
                    kal_uint32 *outSize,
                    kal_bool is_streaming);
#endif /* defined(__DRM_PDCF__) */ 

extern kal_int32 drm_core_activate_file(kal_uint8 serial, kal_uint8 permission, kal_wchar *file_path);
extern kal_int32 drm_core_activate_file_by_handle(kal_uint8 serial, FS_HANDLE handle);

#endif /* __DRM_V02__ */ 

#define FS_PUBLIC_DRV  FS_GetDrive(FS_DRIVE_V_NORMAL, 2, FS_DRIVE_V_NORMAL | FS_DRIVE_V_REMOVABLE)
#define FS_CARD_DRV    FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE)
#define FS_CARD2_DRV    FS_GetDrive(FS_DRIVE_V_REMOVABLE, 2, FS_NO_ALT_DRIVE)

#endif /* DRM_PROT_H */ 

