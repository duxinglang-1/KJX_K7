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
 *  EmailSrvProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to define the Email service internal functions.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef EMAILSRVPROT_H
#define EMAILSRVPROT_H

#include "app_datetime.h"

#include "kal_public_api.h"
#include "emailsrvgprot.h"
#include "MMIDataType.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "fs_type.h"
#include "Conversions.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__

#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif

#define FS_FIND_HANDLE FS_HANDLE

#define FS_INVALID_HANDLE   (-1)

#define EMAIL_CHSET_BUFF_LEN    2048

#define EMAILSRV_ASSERT(x)                      ASSERT(x)
#define EMAILSRV_EXT_ASSERT(x, y1, y2, y3)      ASSERT(x)

#define EMAILSRV_ASSERT_DBG(x)                  ASSERT(x)
#define EMAILSRV_EXT_ASSERT_DBG(x, y1, y2, y3)  ASSERT(x)

#define SRV_EMAIL_MAX(a, b)         (((a) > (b)) ? (a) : (b))
#define SRV_EMAIL_MIN(a, b)         (((a) < (b)) ? (a) : (b))

/* Macros for MIME encoding */
#define EMAIL_MIME_ENC7BIT          0       /* 7 bit SMTP semantic data */
#define EMAIL_MIME_ENC8BIT          1       /* 8 bit SMTP semantic data */
#define EMAIL_MIME_ENCBINARY        2       /* 8 bit binary data */
#define EMAIL_MIME_ENCBASE64        3       /* base-64 encoded data */
#define EMAIL_MIME_ENCQUOTPRINT     4       /* human-readable 8-as-7 bit data */
#define EMAIL_MIME_ENCOTHER         5       /* unknown */
#define EMAIL_MIME_ENCMAX           5

#define EMAIL_MAX_ENCODED_DISP_NAME_LEN (SRV_EMAIL_MAX_DISP_NAME_LEN * 4 + 20)
#define EMAIL_MAX_ENCODED_ADDR_LEN      (SRV_EMAIL_MAX_ADDR_LEN)
#define EMAIL_CHARSET_ENCODE_STRING_LEN (20)

#ifdef __COSMOS_MMI_PACKAGE__
#define EMAIL_MAX_LIST_SUBJ_LEN (140)
#else
#define EMAIL_MAX_LIST_SUBJ_LEN (40)
#endif /* __COSMOS_MMI_PACKAGE__ */

typedef struct
{
    EMAIL_REQ_ID req_id;
    S32 action;
    void *operation_info;
} srv_email_req_id_action_map_struct;

extern void srv_email_init_errno_set(S32 _errno);

extern srv_email_result_enum srv_email_acct_init(void);
extern srv_email_result_enum srv_email_fldr_init(void);

typedef void (*srv_email_msg_init_callback)(srv_email_result_enum res, void *user_data);
srv_email_result_enum srv_email_msg_init(srv_email_msg_init_callback init_callback, void* user_data);

extern srv_email_result_enum srv_email_nwk_init(void);
extern srv_email_result_enum srv_email_emn_init(void);
extern srv_email_result_enum srv_email_otap_init(void);
extern mmi_ret srv_email_nwk_evt_proc_hdlr(mmi_event_struct *evt);

extern void *srv_email_mem_alloc_dbg(U32 size, CHAR *filename, U32 line);
extern void srv_email_mem_free_dbg(void *ptr);

#define srv_email_mem_alloc(size)   srv_email_mem_alloc_dbg(size, __FILE__, __LINE__)
#define srv_email_mem_free(ptr)     if (ptr != NULL) {srv_email_mem_free_dbg((void*)ptr);ptr = NULL;}

extern KAL_ADM_ID srv_email_get_adm_id(void);
extern void srv_email_mem_check(void);

extern srv_email_malloc_funcptr_type srv_email_get_malloc_funcptr(EMAIL_SRV_HANDLE srv_handle);
extern srv_email_mfree_funcptr_type srv_email_get_mfree_funcptr(EMAIL_SRV_HANDLE srv_handle);

extern void srv_email_msg_get_file_path_comp(
                EMAIL_MSG_HANDLE msg_handle,
                srv_email_msg_save_part_enum part,
                WCHAR *buff,
                U32 len);
extern EMAIL_MSG_ID srv_email_msg_get_id(EMAIL_MSG_HANDLE msg_handle);
//extern void srv_email_str_decode(
//                WCHAR *src_str,
//                MMI_BOOL src_type,
//                WCHAR *dst_str,
//                MMI_BOOL dst_type,
//                S32 *len,
//                S32 *charset);
/* same function with srv_email_str_decode to avoid two task manipulate same memory pool */
extern void srv_email_string_decode(WCHAR *src_str, WCHAR *dst_str, S32 *str_len, S32 *str_charset);
extern void email_rfc2047_decode_ext(kal_uint8 **pd, kal_int32 *w_charset);
extern kal_int32 email_rfc2047_decode_word_ext(kal_int8 *d, const kal_int8 *s, U32 len, kal_int32 *w_charset);


extern kal_char *email_find_encoded_word(const kal_char *s, const kal_char **x);


/****************************************************************************/
/****************************** ASYNC FS ************************************/
/****************************************************************************/
typedef void (*srv_email_fs_open_funcptr)(FS_HANDLE handle, void *user_data);
typedef void (*srv_email_fs_res_funcptr)(S32 result, void *user_data);
typedef void (*srv_email_fs_read_funcptr)(S32 result, U32 read_len, void *user_data);
typedef void (*srv_email_fs_write_funcptr)(S32 result, U32 written, void *user_data);
typedef void (*srv_email_fs_move_funcptr)(S32 action, U32 total, U32 completed, UINT info, void *user_data);
typedef void (*srv_email_fs_find_first_funcptr) (FS_FIND_HANDLE handle, FS_DOSDirEntry *file_info, WCHAR *file_name,
                                                 void *user_data);
typedef void (*srv_email_fs_find_next_funcptr) (S32 result, FS_DOSDirEntry *file_info, WCHAR *file_name,
                                                void *user_data);
typedef void (*srv_email_fs_xdelete_acct_funcptr)(S32 *result, void *user_data);

extern srv_email_result_enum srv_email_async_fs_init(void);
extern void srv_email_fs_open(const WCHAR *file_name, U32 flags, srv_email_fs_open_funcptr callback, void *user_data);
extern void srv_email_fs_close(FS_HANDLE fh, srv_email_fs_res_funcptr callback, void *user_data);
extern void srv_email_fs_read(
                FS_HANDLE fh,
                void *data_p,
                U32 length,
                srv_email_fs_read_funcptr callback,
                void *user_data);
extern void srv_email_fs_write(
                FS_HANDLE fh,
                void *data_p,
                U32 length,
                srv_email_fs_write_funcptr callback,
                void *user_data);
extern void srv_email_fs_commit(FS_HANDLE fh, srv_email_fs_res_funcptr callback, void *user_data);
extern void srv_email_fs_delete(const WCHAR *file_name, srv_email_fs_res_funcptr callback, void *user_data);
extern void srv_email_fs_xdelete(const WCHAR *path, U32 flag, srv_email_fs_res_funcptr callback, void *user_data);
extern void srv_email_fs_xdelete_acct(const WCHAR* root_path, const EMAIL_ACCT_ID *accts, U32 flag, srv_email_fs_xdelete_acct_funcptr callback, void *user_data);
extern void srv_email_fs_rename(
                const WCHAR *file_name,
                const WCHAR *new_name,
                srv_email_fs_res_funcptr callback,
                void *user_data);
extern void srv_email_fs_move(
                const WCHAR *src_path,
                const WCHAR *dst_path,
                U32 flag,
                srv_email_fs_res_funcptr callback,
                void *user_data);

/****************************************************************************/
/**************************** Job Scheduler *********************************/
/****************************************************************************/
typedef void (*srv_email_schdl_funcptr_type)(void *data);

#ifdef __MTK_TARGET__
#define srv_email_schdl_start_job(c, d) \
    srv_email_schdl_start_job_ext(c, d, __FILE__, __func__, __LINE__);
#else
#define srv_email_schdl_start_job(c, d) \
    srv_email_schdl_start_job_ext(c, d, __FILE__, __FUNCTION__, __LINE__);
#endif
extern EMAIL_REQ_ID srv_email_schdl_start_job_ext(
    srv_email_schdl_funcptr_type callback, void *data,
    const CHAR* filename, const CHAR* function, U32 line);
extern void srv_email_schdl_stop_job(EMAIL_REQ_ID req_id);

extern U8 *srv_email_util_ucs2_to_chset(U8 *data, S32 chset, U16 *outLen);
extern U8 *srv_email_util_ucs2_to_chset_ex(U8 *data, S32 chset, U16 *outLen, U32 *pos);
typedef enum
{
    SRV_EMAIL_OM_PERMISSION_READ = 0,
    SRV_EMAIL_OM_PERMISSION_WRITE,
    SRV_EMAIL_OM_PERMISSION_TOTAL
} srv_email_om_permission_type_enum;

MMI_BOOL srv_email_om_get_msg_permission(EMAIL_MSG_ID msg_id, srv_email_om_permission_type_enum type);
MMI_BOOL srv_email_om_get_fldr_permission(
            EMAIL_ACCT_ID acct_id,
            EMAIL_FLDR_ID fldr_id,
            srv_email_om_permission_type_enum type);
MMI_BOOL srv_email_om_get_acct_permission(EMAIL_ACCT_ID acct_id, srv_email_om_permission_type_enum type);

void srv_email_om_init(void);

void srv_email_om_nofity_msg_from_stor(srv_email_om_notify_enum type, srv_email_om_notify_msg_struct *notify_data);
void srv_email_om_nofity_fldr_from_stor(srv_email_om_notify_enum type, void *notify_data);
void srv_email_om_nofity_acct_from_stor(srv_email_om_notify_enum type, srv_email_om_notify_acct_struct *notify_data);

/****************************************************************************/
/****************************** CHECKSUM ************************************/
/****************************************************************************/
typedef U16 EMAIL_CHECKSUM;

EMAIL_CHECKSUM email_stor_acct_verno_compute(void);
EMAIL_CHECKSUM email_stor_msg_verno_compute(void);
EMAIL_CHECKSUM srv_email_checksum_compute_by_buffer(const U8* buf, U32 len);
EMAIL_CHECKSUM srv_email_checksum_compute_by_hd(FS_HANDLE hd, U32 position);
srv_email_result_enum srv_email_checksum_write_by_hd(FS_HANDLE hd, U32 position, EMAIL_CHECKSUM checksum);
srv_email_result_enum srv_email_checksum_read_by_hd(FS_HANDLE hd, U32 position, EMAIL_CHECKSUM *checksum);

extern void srv_email_msg_update_msg_by_handle(EMAIL_MSG_ID msg_id, EMAIL_MSG_HANDLE msg_handle);
extern void srv_email_msg_nwk_pre_save(EMAIL_MSG_ID msg_id, EMAIL_MSG_HANDLE msg_handle);
extern srv_email_result_enum srv_email_msg_save_for_nwk(
                                EMAIL_MSG_HANDLE msg_handle,
                                U8 *uidl,
                                U8 *acct_digest,
                                srv_email_msg_save_part_enum save_part,
                                EMAIL_REQ_ID *req_id);
extern srv_email_result_enum srv_email_msg_save_new_for_nwk(
                                EMAIL_MSG_HANDLE msg_handle,
                                U8 *uidl,
                                S32 server_size,
                                U8 *acct_digest,
                                EMAIL_ACCT_ID dest_acct_id,
                                EMAIL_FLDR_ID dest_fldr_id,
                                EMAIL_MSG_ID *msg_id,
                                EMAIL_REQ_ID *req_id);

srv_email_result_enum srv_email_file_chset_convert(
    const WCHAR *src_path, const CHAR *src_chset,
    const WCHAR *dst_path, const CHAR *dst_chset, S32 *minor_errno);

void srv_email_compute_md5(const CHAR *input, S32 input_len, U8* digest);

void srv_email_errno_set(S32 srv_errno);

S32 srv_email_util_dir_exist(const WCHAR *path);
S32 srv_email_util_file_exist_ext(const WCHAR *path);

MMI_BOOL srv_email_util_file_exist(const WCHAR *path);
void srv_email_util_get_mine_type(WCHAR *filename, S32 *mime_type, S32 *mime_subtype);

MMI_BOOL srv_email_is_date_time_valid(applib_time_struct *date_time_p);
void srv_email_set_default_date_time(applib_time_struct *date_time_p);
void srv_email_revise_date_time(applib_time_struct *date_time_p);
S32 srv_email_util_check_space_is_enough(CHAR drv_letter, S32 req_size);

void srv_email_handle_file_name(WCHAR* out, WCHAR* in, U32 limit_len);
const CHAR * srv_email_util_get_mime_type_str(chset_enum charset);

#define EVT_ID_SRV_EMAIL_FILE_CONVERT_DONE 0x1234

typedef struct
{
    U16 evt_id;
    U16 size;
    void *user_data;

    srv_email_result_enum result;
    S32 error_code;
} srv_email_file_chset_cvt_async_event_struct;

srv_email_result_enum srv_email_file_chset_convert_async(
                        WCHAR *src_path,
                        CHAR *src_chset,
                        WCHAR *dst_path,
                        mmi_proc_func callback,
                        void* userdata,
                        U32 *convert_handle,
                        S32 *minor_errno);
void srv_email_file_convert_abort(U32 handle);

#endif /* EMAILSRVPROT_H */

