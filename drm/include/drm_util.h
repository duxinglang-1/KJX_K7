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
 * drm_util.h
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

#ifndef DRM_UTIL_H
#define DRM_UTIL_H
#ifdef __DRM_SUPPORT__

#include "app_mine.h"

#include "kal_general_types.h"
#include "kal_trace.h"
#include "stack_config.h"
#include "kal_public_defs.h"
#include "Fs_type.h"

#define DRM_TRACE(w, x, y, z) kal_prompt_trace(MOD_DRMT, "[DRM] "w, x, y, z)

extern void toLower(kal_uint8 *str);
extern kal_int32 mime_to_int(const char *mime);
extern const char *int_to_mime(kal_int32 mime_value);
extern const char *mime_to_ext(const char *mime);
extern kal_uint32 ext_to_mimesub(char *ext);
extern const char *ext_to_mime(const char *ext);
extern void drm_trace(trace_class_enum ival, const char *arg_type, ...);
extern void drm_send_msg(
                kal_int32 src_id,
                kal_int32 dst_id,
                kal_int32 msg_id,
                void *local_para_ptr,
                void *peer_buff_ptr);
extern kal_int32 drm_get_error_string(int error);
extern void drm_replace_file_extension(kal_wchar *path, kal_uint32 mime_type);
extern kal_bool drm_replace_file_extension_secure(kal_wchar *buf, kal_int32 buf_size, applib_mime_type_struct *entry);
extern kal_bool drm_check_free_space(kal_int32 drv, kal_uint64 need_space);

extern void drm_write_nvram(kal_uint16 lid, kal_uint16 rec, void *data);
extern void drm_read_nvram(kal_uint16 lid, kal_uint16 rec, kal_uint16 amount);
extern kal_bool kal_disable_trace(module_type mod_id, trace_class_enum trc_class);
extern kal_bool drm_is_version_change(void);

extern kal_mutexid mmi_mutex_trace;
extern kal_bool drm_verno_change;

extern kal_uint8 drm_get_permission(kal_uint8 *mime_string, kal_uint32 mime_type);
extern kal_uint8 drm_get_permission_by_path(kal_wchar *filepath);
extern kal_uint8 drm_get_permission_ext(applib_mime_type_struct* entry);
extern kal_int32 drm_get_line(kal_char *strOutput, kal_uint32 length, FS_HANDLE fh);

extern void drm_stime_init();

#endif /*__DRM_SUPPORT__*/                
#endif /* DRM_UTIL_H */ 

