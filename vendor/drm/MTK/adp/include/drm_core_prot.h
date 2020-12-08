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
 * drm_core_port.h
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
 *******************************************************************************/
#ifndef DRM_CORE_PROT_H
#define DRM_CORE_PROT_H

#ifdef __DRM_MTK__

#include "drm_core_def.h"
#include "che_api.h"
#include "fs_type.h"
#include "kal_general_types.h"
#include "drm_errcode.h"
#include "drm_def.h"
#include "app_datetime.h"

#define  DRM_RESULT(x, v, g) x=v;goto g;

#define DRM_MTK_TRACE(x,y)   kal_trace y

typedef enum
{
    DRM_CHK_FLT_NONE        = 0x00,
    DRM_CHK_FLT_DL_ONLY     = 0x01,
    DRM_CHK_FLT_TIME_ONLY   = 0x02,
    DRM_CHK_FLT_FUTURE      = 0x04,
    DRM_CHK_FLT_TOTAL    
}drm_chk_flt_enum;

extern kal_int32 drm_core_encrypt(kal_uint8 *myKey, FS_HANDLE dest, FS_HANDLE source, kal_uint32 file_len);
extern kal_int32 drm_core_decrypt_block(
                    drm_handle_struct *source,
                    kal_int32 curr_blk,
                    kal_uint8 *workn_buf,
                    STCHE *che_str,
                    kal_uint32 is_last_block);
extern kal_int32 drm_core_decrypt_buffer(
                    kal_uint8 *myKey,
                    kal_uint8 key_len,
                    kal_uint32 offset,
                    kal_uint8 *buffer,
                    kal_uint32 size,
                    kal_uint32 start,
                    kal_uint8 *workn_buf);
extern kal_int32 drm_parse_method(FS_HANDLE input);
extern void drm_parse_hash(kal_uint8 *seed, kal_int32 seed_len, kal_char *value_str, kal_bool value_in_wchar);
extern drm_proc_enum drm_core_add_object(
                        kal_uint8 serial,
                        drm_object_type_enum type,
                        kal_wchar *file_path,
                        kal_wchar *new_path,
                        kal_uint32 *offset,
                        kal_uint32 *len);
extern drm_proc_enum drm_parse_content(
                        FS_HANDLE input,
                        drm_rights_struct *rights,
                        kal_uint8 *encoding,
                        kal_char *cid);
extern void drm_parse_base64(FS_HANDLE input, FS_HANDLE output, drm_rights_struct *rights, kal_uint32 out_offset);
extern drm_proc_enum drm_core_add_fl_sd_object(
                        kal_wchar *file_path,
                        FS_HANDLE input,
                        drm_info_struct *info,
                        kal_wchar *new_path,
                        kal_uint32 offset);
extern void drm_core_gen_cid(kal_char *cid, kal_char *seed, kal_int32 seed_len);
extern kal_int32 drm_parse_uintvar(void *start, kal_uint32 *value, kal_uint32 size);

extern void drm_core_get_key(kal_uint8 *key_buf);
extern int drm_core_rm_padding(kal_uint8 *buff, kal_uint32 *len);
extern drm_proc_enum drm_core_encode_dcf(
                        FS_HANDLE input,
                        drm_info_struct *info,
                        kal_uint8 append,
                        kal_uint32 offset,
                        kal_uint8 encoding);
extern FS_HANDLE drm_core_slim_open(kal_wchar *file_path);
extern FS_HANDLE drm_core_open_rights_object(kal_uint32 flags, kal_char *cid, kal_bool hide);
extern kal_int32 drm_core_create_rights_object(FS_HANDLE ro, drm_rights_struct *rights, kal_wchar *content_path);
extern void drm_core_update_constraint(FS_HANDLE ro, drm_rights_struct *rights, kal_uint8 permission);
extern drm_proc_enum drm_parse_rights(FS_HANDLE input, drm_rights_struct *rights, kal_char *cid, kal_uint8 type);
extern drm_proc_enum drm_parse_dcf(FS_HANDLE input, drm_info_struct *info);
extern kal_bool drm_core_load_rights_dcf(FS_HANDLE ro, drm_rights_struct *rights);
extern drm_proc_enum drm_parse_wb_rights(FS_HANDLE input, drm_rights_struct *rights, kal_char *cid);
extern kal_bool drm_core_rights_in_future(drm_rights_struct *rights, kal_uint8 permission);
extern kal_bool drm_core_check_rights(drm_rights_struct *rights, kal_uint8 permission);
extern kal_uint8 drm_core_check_rights_aux(
                    drm_rights_struct *rights,
                    kal_uint8 permission,
                    kal_uint8 filter);
extern kal_bool drm_core_validate_permission_aux(FS_HANDLE source);
extern kal_bool drm_core_load_rights_ro(FS_HANDLE ro, drm_rights_struct *rights);
extern drm_proc_enum drm_parse_buffer_dcf(kal_uint8 *input, drm_info_struct *info);
extern kal_bool drm_core_is_dcf_format(FS_HANDLE input, drm_info_struct *info);
extern drm_rights_struct *drm_core_get_rights(FS_HANDLE input);
extern drm_constraint_struct *drm_core_get_constraint_int(drm_rights_struct *rights, kal_uint8 permission, kal_bool is_download);
extern void drm_core_release_info(drm_info_struct *info);
extern kal_int32 drm_core_search_db(
                    kal_uint8 serial,
                    kal_int32 index,
                    drm_rights_struct *rights,
                    kal_uint32 *total_count,
                    kal_uint32 *valid_count,
                    kal_wchar *path,
                    kal_uint8 flags);
extern void drm_core_rc4_encrypt_buff(
                kal_uint8 *myKey,
                kal_uint8 key_len,
                kal_uint8 *out_buf,
                kal_uint8 *in_buf,
                kal_uint32 length);
extern void drm_core_rc4_decrypt_buff(
                kal_uint8 *myKey,
                kal_uint8 key_len,
                kal_uint8 *out_buf,
                kal_uint8 *in_buf,
                kal_uint32 length);
extern void drm_core_parse_dcf_in_fl(
                FS_HANDLE input,
                FS_HANDLE new_dcf,
                drm_rights_struct *rights,
                drm_info_struct *info,
                kal_uint32 sd_pos,
                kal_char *cid,
                kal_uint32 cid_length);

extern kal_uint8 drm_core_is_constraint_valid(drm_constraint_struct *constraint, kal_bool time_only);
extern kal_bool drm_core_is_trivail_constraint(drm_constraint_struct *constraints);
extern kal_bool drm_core_insert_multiro_constraint(
                    drm_constraint_struct *new_cons,
                    drm_rights_struct *old_rights,
                    kal_uint8 permission,
                    kal_uint8 *perv_cons,
                    kal_uint8 *next_cons);
extern void drm_core_update_multiro_order(
                drm_constraint_struct *new_cons,
                drm_constraint_entry_struct *appending,
                kal_uint8 base_cons,
                kal_uint8 *perv_cons,
                kal_uint8 *next_cons);
extern kal_uint8 drm_core_compare_constraint(drm_constraint_struct *compare, drm_constraint_struct *reference);
extern kal_uint8 drm_core_merge_dt_constraint(
                    drm_constraint_struct *cons,
                    drm_rights_struct *old_rights,
                    kal_uint8 permission,
                    kal_uint8 *perv_cons,
                    kal_uint8 *next_cons);
extern FS_HANDLE drm_core_traslate_file_handle(FS_HANDLE fh);
extern FS_HANDLE drm_core_reverse_file_handle(FS_HANDLE fh);
extern void drm_core_gen_fl_signature(kal_char *sign, FS_HANDLE seed_fl, kal_uint32 seed_len, kal_uint32 offset);
extern kal_bool drm_core_varify_fl_signature(kal_char *sign, FS_HANDLE seed_fl, kal_int32 seed_len, kal_uint32 offset);
extern void drm_core_sec_to_mytime(applib_time_struct *time, kal_uint32 sec);
extern kal_bool drm_core_check_ro_db(void);
extern void drm_core_update_ro_db(void);
extern kal_bool drm_core_check_is_ro_used(FS_HANDLE ro);    /* to check if the ro being closed is used by any of the curent opened files */

#endif /* __DRM_MTK__ */ 
#endif /* DRM_CORE_PROT_H */ 

