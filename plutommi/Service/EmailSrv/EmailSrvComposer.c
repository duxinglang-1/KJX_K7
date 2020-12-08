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
 *  EmailSrvComposer.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *
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
 * removed!
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#include "ctype.h"

#include <time.h>
#include "app_mine.h"
#include "dcl.h"
#include "Conversions.h"
#include "soc_api.h"

#include "EmailSrvGprot.h"
#include "EmailSrvIprot.h"
#include "EmailSrvProt.h"
#include "EmailSrvStorage.h"
#include "EmailSrvComposer.h"
#include "EmailSrvMessage.h"
#include "email_ps_public.h"
#include "customer_ps_inc.h"

#include "mmi_inet_app_trc.h"
#include "mmi_frm_mem_gprot.h"
#include "Unicodexdcl.h"
#include "DebugInitDef_Int.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "app_datetime.h"
#include "stack_config.h"
#include "fs_gprot.h"
#include "FileMgrSrvGProt.h"
#include "app_base64.h"

#include "string.h"
#include "stdio.h"
#include "stdlib.h"

#define EMAIL_COMP_BOUNDARY_LEN                 (16)
#define EMAIL_COMP_MSG_ID_STR_MAX_LEN           (50)
#define EMAIL_COMP_FILE_NAME_MAX_LEN            (90)
#define EMAIL_COMP_ENCODE_TMP_STR_LEN           (2048)  /* MUST large enough for Base/QP encode and Frame message */
#define EMAIL_COMP_EXCEED_WRITE_BUFF_LEN        (800)   /* If buffer's length exceed this value, write to FS */
#define EMAIL_COMP_DATE_STR_LEN                 (50)
#define EMAIL_COMP_ADDR_ENCODED_FULL_LEN        (200)   // TODO:revise
#define EMAIL_COMP_LINE_BUF_LEN                 (1000)  /* 998+2 :\r\n */

#define EMAIL_COMP_ONCE_READ_CONT_LEN           (EMAIL_CHSET_BUFF_LEN / 2)      /* UCS2 to UTF8 */

#define BASE_64_PATTERN                         (711)   /* multiple of 3 */
#define BASE_64_BUFFER                          (1024)

#define EMAIL_COMP_SYS_PATH_LEN                 (SRV_EMAIL_MAX_FILE_NAME_LEN + 1)
#define EMAIL_COMP_MAX_ENC_LINE_LIMIT           (75)

#define email_comp_malloc                       srv_email_mem_alloc
#define email_comp_mfree                        srv_email_mem_free

#define EMAIL_COMP_TRACE_START(type)    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_COMP_START, __LINE__, type)
#define EMAIL_COMP_TRACE_DESTORY()      MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_COMP_DESTORY, __LINE__)
#define EMAIL_COMP_TRACE_STOP()         MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_COMP_STOP, __LINE__)
#define EMAIL_COMP_TRACE_CHK_DESTORY(d) MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_COMP_CHK_DESTORY, __LINE__, d)
#define EMAIL_COMP_TRACE_DONE(r)        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_COMP_DONE, __LINE__, r)

static MMI_BOOL is_rtc_handler_inited = MMI_FALSE;
static DCL_HANDLE email_comp_rtc_handler;

typedef struct
{
    EMAIL_ACCT_ID acct_id;  /* temporary, used to query acct_info */
    EMAIL_MSG_PRIO priority;
    U32 created_date;
    U16 attch_num;
    U16 addr_to_num;
    U16 addr_cc_num;
    U16 addr_bcc_num;
    MMI_BOOL addr_reply_to;
    MMI_BOOL addr_from;
} email_comp_msg_header_struct;

typedef struct
{
    MMI_BOOL multipart;
    U32 text_len;       /* content length */
    U32 html_len;       /* NOT supported now!!! */
    U8 text_encoding;   /* content-transfer-encoding */
    S32 text_charset;   /* char set */
} email_comp_msg_body_struct;

typedef struct
{
    EMAIL_ATTCH_ID attch_id;
    CHAR file_name[EMAIL_STOR_ENCOD_FILE_NAME_LEN];
    CHAR mime[EMAIL_STOR_CONT_TYPE_STR_LEN];
} email_comp_attch_struct;

typedef struct _comp_linked_list_sturct
{
    MMI_BOOL running;
    MMI_BOOL abort;
    MMI_BOOL destroy;
    MMI_BOOL output_fs;
    U32 output_size;
    email_comp_type_enum comp_type;
    EMAIL_MSG_HANDLE msg_handle;
    EMAIL_MSG_ID msg_id;
    srv_email_comp_funcptr_type callback;
    void *user_data;

    email_comp_op_enum op;  /* current operation */

    FS_HANDLE output_hd;

    /* for composing attachment */
    U32 attch_handled_cnt;
    FS_HANDLE attch_fs_hd;
    EMAIL_STOR_HANDLE attch_hd;
    srv_email_stor_attch_struct *attch_stor;
    email_comp_attch_struct *attch;
    srv_email_attach_struct *attch_app;
    CHAR *line_buf;
    U32 encoded_left_len;

    CHAR boundary[EMAIL_COMP_BOUNDARY_LEN + 1];
    U32 read_limit; // refer to BASE_64_PATTERN

    email_comp_msg_header_struct *msg_header;
    email_comp_msg_body_struct *msg_body;
    WCHAR *output_path;
    CHAR *buffer;   // used to hold the content that will be writtern to FS immediately
    struct _comp_linked_list_sturct *next;
} srv_email_comp_struct;

typedef struct
{
    EMAIL_COMP_HANDLE comp_hd;
    srv_email_comp_funcptr_type callback;
    void *user_data;
} srv_email_comp_msg_size_struct;

typedef struct
{
    S32 err_major;
    S32 err_minor;
    srv_email_comp_struct *header;
} srv_email_comp_cntx_struct;

srv_email_comp_cntx_struct email_comp_cnxt = {0};
srv_email_comp_cntx_struct *comp_cnxt_p = &email_comp_cnxt;

const CHAR B64Chars[64] =
    { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
    'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
    't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/'
};

const static CHAR *EMAIL_COMP_FLDR_NAME = "Composer";
const CHAR *const base64_encode = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
const CHAR *const Weekdays[] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
const CHAR *const Months[]   = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

#define EMAIL_COMP_BASE64_ENCODE_1(dst,src) do {                                                                  \
    *dst++ = base64_encode[src[0] >> 2];                            /* byte 1: high 6 bits (1) */                 \
    *dst++ = base64_encode[((src[0] << 4) + (src[1] >> 4)) & 0x3f]; /* byte 2: low 2 bits (1), high 4 bits (2) */ \
    *dst++ = base64_encode[((src[1] << 2) + (src[2] >> 6)) & 0x3f]; /* byte 3: low 4 bits (2), high 2 bits (3) */ \
    *dst++ = base64_encode[src[2] & 0x3f];                          /* byte 4: low 6 bits (3) */ } while(0);

#define EMAIL_COMP_BASE64_ENCODE_2(dst,src,buflen) do {                                                                                           \
    *dst++ = base64_encode[src[0] >> 2];                                            /* byte 1: high 6 bits (1) */                                 \
    *dst++ = base64_encode[((src[0] << 4) + (--buflen ? (src[1] >> 4) : 0)) & 0x3f];/* byte 2: low 2 bits (1), high 4 bits (2) */                 \
    *dst++ = buflen ? base64_encode[((src[1] << 2) + (--buflen ? (src[2] >> 6) : 0)) & 0x3f] : '='; /* byte 3: low 4 bits (2), high 2 bits (3) */ \
    *dst++ = buflen ? base64_encode[src[2] & 0x3f] : '=';                   /* byte 4: low 6 bits (3) */ } while(0);

void email_comp_fsm(srv_email_comp_struct *email_comp_p);
srv_email_result_enum email_comp_run_init(srv_email_comp_struct *email_comp_p);

srv_email_result_enum email_comp_output_file_write(srv_email_comp_struct *email_comp_p, CHAR *buff, U32 buff_len);
void email_comp_output_file_close(srv_email_comp_struct *email_comp_p);

srv_email_result_enum email_comp_write_header(srv_email_comp_struct *email_comp_p);
srv_email_result_enum email_comp_write_mime_body_header(srv_email_comp_struct *email_comp_p);
srv_email_result_enum email_comp_addr_single_get(
                        srv_email_comp_struct *email_comp_p,
                        CHAR *buff,
                        U32 buff_len,
                        srv_email_addr_type_enum type,
                        U32 *com_len);
srv_email_result_enum email_comp_addr_list_get(
                        srv_email_comp_struct *email_comp_p,
                        CHAR *buff,
                        U32 buff_len,
                        srv_email_addr_type_enum type, U32 *com_len);
srv_email_result_enum email_comp_subj_get(srv_email_comp_struct *email_comp_p, CHAR *buff, U32 buff_len, U32 *written);

void email_comp_cntx_free(srv_email_comp_struct *email_comp_p);

srv_email_result_enum email_comp_write_attch(
    srv_email_comp_struct *email_comp_p);

srv_email_result_enum  email_comp_write_cont(
    srv_email_comp_struct *email_comp_p);

U32 email_comp_write_boundary_content_type(
    srv_email_comp_struct *email_comp_p, CHAR *buff, U32 buff_len);

srv_email_result_enum email_comp_message_encode_and_copy(
    srv_email_comp_struct *email_comp_p, FS_HANDLE hd, U8 encoding_type, MMI_BOOL async_mode);

CHAR *email_comp_base64_encode(
    CHAR *src, S32 srcl, CHAR *dest, U32 *destl, U32 *left_len);
CHAR *email_comp_get_encode_type_str(U8 encoding);

void email_comp_gen_boundary(CHAR *s);
U32 email_comp_gen_msgid(CHAR *buf);
U32 email_comp_gen_date(srv_email_comp_struct *email_comp_p, CHAR* buffer);

#define email_comp_check_abort_destory(comp_p) email_comp_check_abort_destory_internal(comp_p, __LINE__)


/*****************************************************************************
 * FUNCTION
 *  email_comp_stop_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  handle      [IN]
 * RETURNS
 *
 *****************************************************************************/
static srv_email_result_enum email_comp_stop_proc(EMAIL_COMP_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comp_struct *email_comp_p = (srv_email_comp_struct*) handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_comp_p->running)
    {
        email_comp_p->running = MMI_FALSE;
        email_comp_p->abort = MMI_TRUE;

        if (email_comp_p->output_hd > FS_NO_ERROR)
        {
            FS_Close(email_comp_p->output_hd);
            email_comp_p->output_hd = FS_INVALID_HANDLE;
        }

        if (email_comp_p->attch_fs_hd > FS_NO_ERROR)
        {
            FS_Close(email_comp_p->attch_fs_hd);
            email_comp_p->attch_fs_hd = FS_INVALID_HANDLE;
        }
        if (email_comp_p->attch_hd != EMAIL_STOR_INVALID_HANDLE)
        {
            srv_email_stor_msg_get_attch_close(email_comp_p->attch_hd);
            email_comp_p->attch_hd = EMAIL_STOR_INVALID_HANDLE;
        }
        if (email_comp_p->attch_stor != NULL)
        {
            email_comp_mfree(email_comp_p->attch_stor);
            email_comp_p->attch_stor = NULL;
        }
        if (email_comp_p->attch != NULL)
        {
            email_comp_mfree(email_comp_p->attch);
            email_comp_p->attch = NULL;
        }
        if (email_comp_p->attch_app != NULL)
        {
            email_comp_mfree(email_comp_p->attch_app);
            email_comp_p->attch_app = NULL;
        }

        FS_Delete(email_comp_p->output_path);

        email_comp_cntx_free(email_comp_p);
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_destroy_proc
 * DESCRIPTION
 *
 * PARAMETERS
 *  handle      [IN]
 * RETURNS
 *
 *****************************************************************************/
static srv_email_result_enum email_comp_destroy_proc(EMAIL_COMP_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comp_struct *comp_obj = comp_cnxt_p->header;
    srv_email_comp_struct *tempHandle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(comp_cnxt_p->header != NULL);
    MMI_ASSERT(((srv_email_comp_struct*) handle)->destroy);

    email_comp_stop_proc(handle);

    if (comp_obj->next == NULL)
    {
        MMI_ASSERT(comp_obj == (srv_email_comp_struct*) handle);
        comp_cnxt_p->header = NULL;
        tempHandle = (srv_email_comp_struct*)handle;
        email_comp_mfree(tempHandle);
        return SRV_EMAIL_RESULT_SUCC;
    }
    else
    {
        while (comp_obj->next != NULL)
        {
            if (comp_obj->next == (srv_email_comp_struct*) handle)
            {
                srv_email_comp_struct *temp = comp_obj->next;

                comp_obj->next = temp->next;
                email_comp_mfree(temp);
                return SRV_EMAIL_RESULT_SUCC;
            }
            comp_obj = comp_obj->next;
        }
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_sys_dir_get
 * DESCRIPTION
 *
 * PARAMETERS
 *  sys_dir     [?]
 * RETURNS
 *
 *****************************************************************************/
static srv_email_result_enum email_comp_sys_dir_get(WCHAR *sys_dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(sys_dir != NULL);

    kal_wsprintf(sys_dir, "%s%s", srv_email_get_root_path(), EMAIL_COMP_FLDR_NAME);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_handle_exist
 * DESCRIPTION
 *
 * PARAMETERS
 *  handle      [IN]
 * RETURNS
 *
 *****************************************************************************/
static MMI_BOOL email_comp_handle_exist(EMAIL_COMP_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comp_struct *comp_obj = comp_cnxt_p->header;
    srv_email_comp_struct *to_find = (srv_email_comp_struct*) handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (comp_obj != NULL)
    {
        if (comp_obj == to_find)
        {
            return MMI_TRUE;
        }
        comp_obj = comp_obj->next;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_instance_num
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
static U32 email_comp_instance_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 num = 0;
    srv_email_comp_struct *comp_obj = comp_cnxt_p->header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (comp_obj != NULL)
    {
        comp_obj = comp_obj->next;
        num++;
    }
    return num;
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_instance_reach_max_num
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
static MMI_BOOL email_comp_instance_reach_max_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (email_comp_instance_num() >= (U32)SRV_EMAIL_COMP_INSTANCE_MAX_NUM) ?
            MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_comp_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
srv_email_result_enum srv_email_comp_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!is_rtc_handler_inited)
    {
        email_comp_rtc_handler = DclRTC_Open(DCL_RTC,FLAGS_NONE);;
    }

    if ((path = email_comp_malloc(sizeof(WCHAR) * EMAIL_COMP_SYS_PATH_LEN)) == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_comp_sys_dir_get(path);

    ret = srv_email_util_dir_exist(path);
    if (ret < 0)
    {
        srv_email_init_errno_set(ret);
        email_comp_mfree(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    if (ret == 1) /* DIR exist */
    {
        email_comp_mfree(path);
        return SRV_EMAIL_RESULT_SUCC;
    }

    ret = FS_CreateDir(path);
    email_comp_mfree(path);

    if (ret != FS_NO_ERROR)
    {
        srv_email_init_errno_set(ret);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    return SRV_EMAIL_RESULT_SUCC;
}

/*****************************************************************************
 * FUNCTION
 *  srv_email_comp_msg_size_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *  succ            [IN]
 *  err_major       [IN]
 *  err_minor       [IN]
 *  size            [IN]
 *  user_data       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_comp_msg_size_callback(MMI_BOOL succ, S32 err_major, S32 err_minor, U32 size, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comp_msg_size_struct *comp_msg_size_cntx = (srv_email_comp_msg_size_struct*) user_data;
    void *_user_data = comp_msg_size_cntx->user_data;
    srv_email_comp_funcptr_type callback = comp_msg_size_cntx->callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_comp_destroy(comp_msg_size_cntx->comp_hd);
    email_comp_mfree(comp_msg_size_cntx);

    if (callback)
    {
        callback(succ, err_major, err_minor, size, _user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_comp_msg_size
 * DESCRIPTION
 *
 * PARAMETERS
 *  msg_handle      [IN]
 *  callback        [IN]
 *  user_data       [?]
 * RETURNS
 *
 *****************************************************************************/
srv_email_result_enum srv_email_comp_msg_size(
                        EMAIL_MSG_HANDLE msg_handle,
                        srv_email_comp_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum ret;
    srv_email_comp_msg_size_struct *comp_msg_size_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((comp_msg_size_cntx = email_comp_malloc(sizeof(srv_email_comp_msg_size_struct))) == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    if ((ret = srv_email_comp_create(&comp_msg_size_cntx->comp_hd)) != SRV_EMAIL_RESULT_SUCC)
    {
        return ret;
    }

	comp_msg_size_cntx->callback = callback;
	comp_msg_size_cntx->user_data = user_data;

    srv_email_comp_start_by_msg_handle(
        comp_msg_size_cntx->comp_hd,
        msg_handle,
        MMI_TRUE,
        NULL,
        srv_email_comp_msg_size_callback,
        comp_msg_size_cntx);

    return SRV_EMAIL_RESULT_SUCC;
}

/* Create Email composer instance */

srv_email_result_enum srv_email_comp_msg_size_abort(EMAIL_MSG_HANDLE msg_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comp_struct *comp_obj = comp_cnxt_p->header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAIL_COMP_TRACE_STOP();
    while (comp_obj != NULL)
    {
        if (comp_obj->msg_handle == msg_handle)
        {
            comp_obj->abort = MMI_TRUE;
            comp_obj->destroy = MMI_TRUE;
            return SRV_EMAIL_RESULT_WOULDBLOCK;
        }
        comp_obj = comp_obj->next;
    }

    return SRV_EMAIL_RESULT_COMP_HANDLE_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_comp_create
 * DESCRIPTION
 *
 * PARAMETERS
 *  handle      [?]
 * RETURNS
 *
 *****************************************************************************/
srv_email_result_enum srv_email_comp_create(EMAIL_COMP_HANDLE *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comp_struct *comp_obj = comp_cnxt_p->header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_comp_instance_reach_max_num())
    {
        return SRV_EMAIL_RESULT_COMP_INSTANCE_REACH_MAX_NUM;
    }

    if (comp_obj == NULL)
    {
        comp_cnxt_p->header = comp_obj = email_comp_malloc(sizeof(srv_email_comp_struct));
    }
    else
    {
        while (comp_obj->next != NULL)
        {
            comp_obj = comp_obj->next;
        }
        comp_obj->next = email_comp_malloc(sizeof(srv_email_comp_struct));
        comp_obj = comp_obj->next;
    }
    if (comp_obj == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    *handle = (EMAIL_COMP_HANDLE) comp_obj;
    memset(comp_obj, 0, sizeof(srv_email_comp_struct));
    return SRV_EMAIL_RESULT_SUCC;
}

/* Compose the email */


/*****************************************************************************
 * FUNCTION
 *  srv_email_comp_start_by_msg_id
 * DESCRIPTION
 *
 * PARAMETERS
 *  handle              [IN]
 *  msg_id              [IN]
 *  comp_size_only      [IN]
 *  filename            [?]
 *  callback            [IN]
 *  user_data           [?]
 * RETURNS
 *
 *****************************************************************************/
srv_email_result_enum srv_email_comp_start_by_msg_id(
                        EMAIL_COMP_HANDLE handle,
                        EMAIL_MSG_ID msg_id,
                        MMI_BOOL comp_size_only,
                        WCHAR *filename,
                        srv_email_comp_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_comp_struct *email_comp_p = (srv_email_comp_struct*) handle;
    srv_email_stor_cont_header_struct *cont_header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAIL_COMP_TRACE_START(EMAIL_COMP_BY_ID);

    if (!email_comp_handle_exist(handle))
    {
        return SRV_EMAIL_RESULT_COMP_HANDLE_INVALID;
    }

    if (email_comp_p->running)
    {
        return SRV_EMAIL_RESULT_COMP_BUSY;
    }

    email_comp_p->buffer = email_comp_malloc(EMAIL_COMP_ENCODE_TMP_STR_LEN);
    email_comp_p->msg_header = email_comp_malloc(sizeof(email_comp_msg_header_struct));
    email_comp_p->msg_body = email_comp_malloc(sizeof(email_comp_msg_body_struct));
    email_comp_p->output_path = email_comp_malloc(sizeof(WCHAR) * EMAIL_COMP_SYS_PATH_LEN);
    MMI_ASSERT(email_comp_p->buffer != NULL && email_comp_p->msg_header != NULL
               && email_comp_p->msg_body != NULL && email_comp_p->output_path != NULL);
    if (!comp_size_only)
    {
        mmi_wcscpy(email_comp_p->output_path, filename);
    }

    email_comp_p->running = MMI_TRUE;
    email_comp_p->abort = MMI_FALSE;
    email_comp_p->output_fs = comp_size_only ? MMI_FALSE : MMI_TRUE;
    email_comp_p->comp_type = EMAIL_COMP_BY_ID;
    email_comp_p->msg_handle = EMAIL_MSG_INVALID_HANDLE;
    email_comp_p->msg_id = msg_id;
    email_comp_p->msg_body->text_encoding = EMAIL_MIME_ENCBASE64;
    email_comp_p->next = NULL;
    email_comp_p->callback = callback;
    email_comp_p->user_data = user_data;

    cont_header = email_comp_malloc(sizeof(srv_email_stor_cont_header_struct));

    if (srv_email_stor_msg_get_cont(msg_id, SRV_EMAIL_STOR_MSG_CONT_TEXT, cont_header, NULL, NULL) ==
        SRV_EMAIL_RESULT_SUCC)
    {
        mmi_chset_enum chset;

        if (!mmi_chset_get_charset_id((const kal_int8*)cont_header->charset, &chset))
        {
            email_comp_p->msg_body->text_charset = MMI_CHSET_UTF8;
        }
        else
        {
            email_comp_p->msg_body->text_charset = (S32) chset;
        }
        email_comp_p->msg_body->text_len = cont_header->local_size;
    }
    else
    {
        email_comp_p->msg_body->text_charset = MMI_CHSET_UTF8;
        email_comp_p->msg_body->text_len = 0;
    }

    email_comp_mfree(cont_header);

    email_comp_p->op = EMAIL_COMP_OP_INIT;

    srv_email_schdl_start_job((srv_email_schdl_funcptr_type) email_comp_fsm, email_comp_p);
    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_comp_start_by_msg_handle
 * DESCRIPTION
 *
 * PARAMETERS
 *  handle              [IN]
 *  msg_handle          [IN]
 *  comp_size_only      [IN]
 *  filename            [?]
 *  callback            [IN]
 *  user_data           [?]
 * RETURNS
 *
 *****************************************************************************/
srv_email_result_enum srv_email_comp_start_by_msg_handle(
                        EMAIL_COMP_HANDLE handle,
                        EMAIL_MSG_HANDLE msg_handle,
                        MMI_BOOL comp_size_only,
                        WCHAR *filename,
                        srv_email_comp_funcptr_type callback,
                        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //EMAIL_MSG_ID msg_id;
    srv_email_result_enum res;
    srv_email_comp_struct *email_comp_p = (srv_email_comp_struct*) handle;
    srv_email_stor_cont_header_struct *cont_header;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAIL_COMP_TRACE_START(EMAIL_COMP_BY_HD);

    if (!email_comp_handle_exist(handle))
    {
        return SRV_EMAIL_RESULT_COMP_HANDLE_INVALID;
    }

    if (email_comp_p->running)
    {
        return SRV_EMAIL_RESULT_COMP_BUSY;
    }

    email_comp_p->buffer = email_comp_malloc(EMAIL_COMP_ENCODE_TMP_STR_LEN);
    email_comp_p->msg_header = email_comp_malloc(sizeof(email_comp_msg_header_struct));
    email_comp_p->msg_body = email_comp_malloc(sizeof(email_comp_msg_body_struct));
    email_comp_p->output_path = email_comp_malloc(sizeof(WCHAR) * EMAIL_COMP_SYS_PATH_LEN);
    MMI_ASSERT(email_comp_p->buffer != NULL && email_comp_p->msg_header != NULL
               && email_comp_p->msg_body != NULL && email_comp_p->output_path != NULL);
    if (!comp_size_only)
    {
        mmi_wcscpy(email_comp_p->output_path, filename);
    }

    email_comp_p->running = MMI_TRUE;
    email_comp_p->abort = MMI_FALSE;
    email_comp_p->output_fs = comp_size_only ? MMI_FALSE : MMI_TRUE;
    email_comp_p->comp_type = EMAIL_COMP_BY_HD;
    email_comp_p->msg_handle = msg_handle;
    email_comp_p->msg_id = EMAIL_MSG_INVALID_ID;
    email_comp_p->next = NULL;
    email_comp_p->callback = callback;
    email_comp_p->user_data = user_data;
    email_comp_p->line_buf = NULL;
    email_comp_p->encoded_left_len = 0;
    email_comp_p->msg_body->text_encoding = EMAIL_MIME_ENCBASE64;
    email_comp_p->msg_body->text_charset = MMI_CHSET_UTF8;
    email_comp_p->msg_body->text_len = 0;

    cont_header = email_comp_malloc(sizeof(srv_email_stor_cont_header_struct));

    res = srv_email_msg_get_cont_for_comp(msg_handle,
            SRV_EMAIL_STOR_MSG_CONT_TEXT, cont_header, NULL, NULL);
    if (res == SRV_EMAIL_RESULT_SUCC)
    {
        mmi_chset_enum chset;

        if (mmi_chset_get_charset_id((const kal_int8*)cont_header->charset, &chset))
        {
            email_comp_p->msg_body->text_charset = (S32) chset;
        }
        email_comp_p->msg_body->text_len = cont_header->local_size;
    }

    email_comp_mfree(cont_header);

    email_comp_p->op = EMAIL_COMP_OP_INIT;

    srv_email_schdl_start_job((srv_email_schdl_funcptr_type) email_comp_fsm, email_comp_p);
    return SRV_EMAIL_RESULT_WOULDBLOCK;
}

/* Destroy Email composer instance */


/*****************************************************************************
 * FUNCTION
 *  srv_email_comp_destroy
 * DESCRIPTION
 *
 * PARAMETERS
 *  handle      [IN]
 * RETURNS
 *
 *****************************************************************************/
srv_email_result_enum srv_email_comp_destroy(EMAIL_COMP_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAIL_COMP_TRACE_DESTORY();
    if (!email_comp_handle_exist(handle))
    {
        return SRV_EMAIL_RESULT_COMP_HANDLE_INVALID;
    }

    ((srv_email_comp_struct*) handle)->destroy = MMI_TRUE;

    if (((srv_email_comp_struct*) handle)->running)
    {
        return SRV_EMAIL_RESULT_WOULDBLOCK;
    }
    else
    {
        return email_comp_destroy_proc(handle);
    }
}

/* Stop the composing */


/*****************************************************************************
 * FUNCTION
 *  srv_email_comp_stop
 * DESCRIPTION
 *
 * PARAMETERS
 *  handle      [IN]
 * RETURNS
 *
 *****************************************************************************/
srv_email_result_enum srv_email_comp_stop(EMAIL_COMP_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAIL_COMP_TRACE_STOP();
    if (!email_comp_handle_exist(handle))
    {
        return SRV_EMAIL_RESULT_COMP_HANDLE_INVALID;
    }

    ((srv_email_comp_struct*) handle)->abort = MMI_TRUE;

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_get_compose_error
 * DESCRIPTION
 *
 * PARAMETERS
 *  ret         [IN]
 *  major       [?]
 *  minor       [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_get_compose_error(srv_email_result_enum ret, S32 *major, S32 *minor)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *major = comp_cnxt_p->err_major;
    *minor = comp_cnxt_p->err_minor;
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_check_abort_destory
 * DESCRIPTION
 *
 * PARAMETERS
 *  email_comp_p        [?]
 * RETURNS
 *
 *****************************************************************************/
static MMI_BOOL email_comp_check_abort_destory_internal(srv_email_comp_struct *email_comp_p, U32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_comp_p->destroy)
    {
        EMAIL_COMP_TRACE_CHK_DESTORY(0);
        email_comp_destroy_proc((EMAIL_COMP_HANDLE) email_comp_p);
        return MMI_TRUE;
    }

    if (email_comp_p->abort)
    {
        EMAIL_COMP_TRACE_CHK_DESTORY(1);
        email_comp_stop_proc((EMAIL_COMP_HANDLE) email_comp_p);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_fsm
 * DESCRIPTION
 *
 * PARAMETERS
 *  email_comp_p        [?]
 * RETURNS
 *  void
 *****************************************************************************/
void email_comp_fsm(srv_email_comp_struct *email_comp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (email_comp_p->op)
    {
        case EMAIL_COMP_OP_INIT:
            if (email_comp_check_abort_destory(email_comp_p))
            {
                return;
            }
            if ((ret = email_comp_run_init(email_comp_p)) != SRV_EMAIL_RESULT_SUCC)
            {
                goto COMP_EXIT_HANDLE;
            }
            email_comp_p->op = EMAIL_COMP_OP_WRITE_HEADER_DATE;
            srv_email_schdl_start_job((srv_email_schdl_funcptr_type) email_comp_fsm, email_comp_p);
            return;

        /************ NO BREAK ***********/
        case EMAIL_COMP_OP_WRITE_HEADER_DATE:
        case EMAIL_COMP_OP_WRITE_HEADER_ADDR_REPLY_TO_FROM:
        case EMAIL_COMP_OP_WRITE_HEADER_ADDR_TO:
        case EMAIL_COMP_OP_WRITE_HEADER_ADDR_CC:
        case EMAIL_COMP_OP_WRITE_HEADER_ADDR_BCC:
        case EMAIL_COMP_OP_WRITE_HEADER_SUBJ:
        case EMAIL_COMP_OP_WRITE_HEADER_OTHERS:
            if (email_comp_check_abort_destory(email_comp_p))
            {
                return;
            }
            if ((ret = email_comp_write_header(email_comp_p)) != SRV_EMAIL_RESULT_SUCC)
            {
                goto COMP_EXIT_HANDLE;
            }
            email_comp_p->op = EMAIL_COMP_OP_FORM_BODY_HDR_INIT;
            srv_email_schdl_start_job((srv_email_schdl_funcptr_type) email_comp_fsm, email_comp_p);
            return;

        /************ NO BREAK ***********/

        case EMAIL_COMP_OP_FORM_BODY_HDR_INIT:
        case EMAIL_COMP_OP_WRITE_BODY_HEADER_TO_BUFF:
        case EMAIL_COMP_OP_WRITE_BODY_HEADER_TO_FILE:
            if (email_comp_check_abort_destory(email_comp_p))
            {
                return;
            }
            if ((ret = email_comp_write_mime_body_header(email_comp_p)) != SRV_EMAIL_RESULT_SUCC)
            {
                goto COMP_EXIT_HANDLE;
            }
            email_comp_p->op = (email_comp_p->msg_body->text_len > 0 ? EMAIL_COMP_OP_WRITE_CONT_INIT
                                : EMAIL_COMP_OP_WRITE_ATTCH_INIT);
            srv_email_schdl_start_job((srv_email_schdl_funcptr_type) email_comp_fsm, email_comp_p);
            return;

        case EMAIL_COMP_OP_WRITE_CONT_INIT:
        case EMAIL_COMP_OP_WRITE_CONT_TO_FILE:
            if (email_comp_check_abort_destory(email_comp_p))
            {
                return;
            }
            if ((ret = email_comp_write_cont(email_comp_p)) != SRV_EMAIL_RESULT_SUCC)
            {
                goto COMP_EXIT_HANDLE;
            }
            srv_email_schdl_start_job((srv_email_schdl_funcptr_type) email_comp_fsm, email_comp_p);
            return;

        case EMAIL_COMP_OP_WRITE_ATTCH_INIT:
        case EMAIL_COMP_OP_WRITE_ATTCH_HEADER_TO_BUFF:
        case EMAIL_COMP_OP_WRITE_ATTCH_HEADER_TO_FILE:
        case EMAIL_COMP_OP_ATTCH_BODY_WRITE:
        case EMAIL_COMP_OP_ATTCH_BODY_BOUNDARY:
            if (email_comp_check_abort_destory(email_comp_p))
            {
                return;
            }

            ret = email_comp_write_attch(email_comp_p);
            if (ret == SRV_EMAIL_RESULT_WOULDBLOCK)
            {
                return;
            }
            else if (ret != SRV_EMAIL_RESULT_SUCC)
            {
                goto COMP_EXIT_HANDLE;
            }
            srv_email_schdl_start_job((srv_email_schdl_funcptr_type) email_comp_fsm, email_comp_p);
            return;

        case EMAIL_COMP_OP_WRITE_END_BDRY:
            if (email_comp_check_abort_destory(email_comp_p))
            {
                return;
            }
            if (email_comp_p->msg_body->multipart)
            {
                U32 size_befor_write = 0;

                memset(email_comp_p->buffer, 0, EMAIL_COMP_ENCODE_TMP_STR_LEN);

                size_befor_write += sprintf(email_comp_p->buffer, "\r\n------%s--\r\n", email_comp_p->boundary);
                email_comp_p->output_size += size_befor_write;
                if ((ret = email_comp_output_file_write(email_comp_p, email_comp_p->buffer, size_befor_write)) != SRV_EMAIL_RESULT_SUCC)
                {
                    goto COMP_EXIT_HANDLE;
                }
            }
            email_comp_p->op = EMAIL_COMP_OP_FRAME_MSG_END;
            srv_email_schdl_start_job((srv_email_schdl_funcptr_type) email_comp_fsm, email_comp_p);
            return;

        case EMAIL_COMP_OP_FRAME_MSG_END:
            if (email_comp_check_abort_destory(email_comp_p))
            {
                return;
            }
            email_comp_cntx_free(email_comp_p);
            email_comp_output_file_close(email_comp_p);
            email_comp_p->running = MMI_FALSE;
            if (email_comp_p->callback != NULL)
            {
                EMAIL_COMP_TRACE_DONE(0);
                (email_comp_p->callback) (MMI_TRUE, 0, 0, email_comp_p->output_size, email_comp_p->user_data);
            }
            break;
    }
    return;

COMP_EXIT_HANDLE:
    email_comp_p->abort = MMI_TRUE;
    email_comp_stop_proc((EMAIL_COMP_HANDLE) email_comp_p);
    if (email_comp_p->callback != NULL)
    {
        EMAIL_COMP_TRACE_DONE(ret);
        if (ret == SRV_EMAIL_RESULT_FS_ERROR)
        {
            comp_cnxt_p->err_major = SRV_EMAIL_FS_ERROR;
            comp_cnxt_p->err_minor = srv_email_errno_get();
        }
        else
        {
            comp_cnxt_p->err_major = SRV_EMAIL_MAIL_ERROR;
            comp_cnxt_p->err_minor = ret;
        }
        email_comp_p->callback(MMI_FALSE, comp_cnxt_p->err_major, comp_cnxt_p->err_minor, email_comp_p->output_size, email_comp_p->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_run_init
 * DESCRIPTION
 *
 * PARAMETERS
 *  email_comp_p        [?]     [?]
 * RETURNS
 *
 *****************************************************************************/
srv_email_result_enum email_comp_run_init(srv_email_comp_struct *email_comp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum res = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_comp_p->output_size = 0;

    if (email_comp_p->output_fs)
    {
        email_comp_p->output_hd = FS_Open(email_comp_p->output_path,
                                          FS_READ_WRITE | FS_CREATE_ALWAYS);
        if (email_comp_p->output_hd < FS_NO_ERROR)
        {
            srv_email_errno_set(email_comp_p->output_hd);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
    }

    email_comp_gen_boundary(email_comp_p->boundary);

    if (email_comp_p->comp_type == EMAIL_COMP_BY_ID)
    {
        srv_email_stor_msg_get_header_struct *msg_header;
        msg_header = email_comp_malloc(sizeof(*msg_header));
        if (msg_header == NULL)
        {
            res = SRV_EMAIL_RESULT_NO_MEMORY;
            goto COMP_EXIT_HANDLE;
        }
        res = srv_email_stor_msg_get_header(email_comp_p->msg_id, msg_header);
        if (res == SRV_EMAIL_RESULT_SUCC)
        {
            email_comp_p->msg_header->acct_id       = EMAIL_ACCT_INVALID_ID;
            email_comp_p->msg_header->created_date  = msg_header->created_date;
            email_comp_p->msg_header->priority      = msg_header->priority;
            email_comp_p->msg_header->attch_num     = msg_header->attch_num;
            email_comp_p->msg_header->addr_to_num   = msg_header->addr_to_num;
            email_comp_p->msg_header->addr_cc_num   = msg_header->addr_cc_num;
            email_comp_p->msg_header->addr_bcc_num  = msg_header->addr_bcc_num;
            email_comp_p->msg_header->addr_reply_to = msg_header->addr_reply_to;
            email_comp_p->msg_header->addr_from     = msg_header->addr_from;
        }
        email_comp_mfree(msg_header);
    }
    else if (email_comp_p->comp_type == EMAIL_COMP_BY_HD)
    {
        srv_email_msg_get_basic_info_struct *msg_header;
        msg_header = email_comp_malloc(sizeof(*msg_header));
        if (msg_header == NULL)
        {
            res = SRV_EMAIL_RESULT_NO_MEMORY;
            goto COMP_EXIT_HANDLE;
        }
        res = srv_email_msg_get_basic_info(email_comp_p->msg_handle, msg_header);
        if (res == SRV_EMAIL_RESULT_SUCC)
        {
            email_comp_p->msg_header->acct_id       = msg_header->acct_id;
            email_comp_p->msg_header->created_date  = (U32) msg_header->mail_date;
            email_comp_p->msg_header->priority      = (EMAIL_MSG_PRIO) msg_header->priority;
            email_comp_p->msg_header->attch_num     = (U16) msg_header->attach_num;
            email_comp_p->msg_header->addr_to_num   = (U16) msg_header->to_addr_num;
            email_comp_p->msg_header->addr_cc_num   = (U16) msg_header->cc_addr_num;
            email_comp_p->msg_header->addr_bcc_num  = (U16) msg_header->bcc_addr_num;
            /* NO from/reply-to here, deal with them later. */
        }
        email_comp_mfree(msg_header);
    }

    email_comp_p->msg_body->multipart = (email_comp_p->msg_header->attch_num ? MMI_TRUE : MMI_FALSE);
    email_comp_p->msg_body->html_len = 0;   /* Not supported now */

COMP_EXIT_HANDLE:
    return res;
}

/*****************************************************************************
 * FUNCTION
 *  email_comp_output_file_write
 * DESCRIPTION
 *
 * PARAMETERS
 *  email_comp_p        [?]         [?]
 *  buff                [?]         [?]
 *  buff_len            [IN]
 * RETURNS
 *
 *****************************************************************************/
srv_email_result_enum email_comp_output_file_write(srv_email_comp_struct *email_comp_p, CHAR *buff, U32 buff_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 read_write;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!email_comp_p->output_fs)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }

    FS_Seek(email_comp_p->output_hd, 0, FS_FILE_END);
    ret = FS_Write(email_comp_p->output_hd, buff, buff_len, &read_write);
    if (ret != FS_NO_ERROR || read_write != buff_len)
    {
        srv_email_errno_set(ret);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_output_file_close
 * DESCRIPTION
 *
 * PARAMETERS
 *  email_comp_p        [?]     [?]
 * RETURNS
 *
 *****************************************************************************/
void email_comp_output_file_close(srv_email_comp_struct *email_comp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!email_comp_p->output_fs)
    {
        return;
    }
    if (email_comp_p->output_hd > FS_NO_ERROR)
    {
        FS_Close(email_comp_p->output_hd);
    }
    email_comp_p->output_hd = EMAIL_STOR_INVALID_FS_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_gen_boundary
 * DESCRIPTION
 *
 * PARAMETERS
 *  s       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void email_comp_gen_boundary(CHAR *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j, k, l;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < EMAIL_COMP_BOUNDARY_LEN; i++)
    {
        j = rand();
        k = sizeof(B64Chars);
        l = j % k;
        *s++ = B64Chars[l];
    }
    *s = '\0';
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_write_header
 * DESCRIPTION
 *
 * PARAMETERS
 *  email_comp_p        [?]     [?]
 * RETURNS
 *
 *****************************************************************************/
srv_email_result_enum email_comp_write_header(srv_email_comp_struct *email_comp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *addr_encoded_full;
    CHAR *msg_id_str;
    S32 priority;
    U32 temp_buff_len = 0;
    U32 written_len;
    srv_email_result_enum res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (email_comp_p->op)
    {
        case EMAIL_COMP_OP_WRITE_HEADER_DATE:
            memset(email_comp_p->buffer, 0, EMAIL_COMP_ENCODE_TMP_STR_LEN);
            temp_buff_len = 0;
            temp_buff_len += email_comp_gen_date(email_comp_p, email_comp_p->buffer + temp_buff_len);

            /************ NO BREAK ***********/

        case EMAIL_COMP_OP_WRITE_HEADER_ADDR_REPLY_TO_FROM:
            addr_encoded_full = email_comp_malloc(EMAIL_COMP_ADDR_ENCODED_FULL_LEN);
            if (addr_encoded_full == NULL)
            {
                return SRV_EMAIL_RESULT_NO_MEMORY;
            }

            /* Reply-To address */
            if (email_comp_p->msg_header->addr_reply_to ||
                email_comp_p->comp_type == EMAIL_COMP_BY_HD)
            {
                res = email_comp_addr_single_get(
                        email_comp_p,
                        addr_encoded_full,
                        EMAIL_COMP_ADDR_ENCODED_FULL_LEN,
                        SRV_EMAIL_ADDR_TYPE_REPLY_TO,
                        &written_len);
                if (res != SRV_EMAIL_RESULT_SUCC)
                {
                    goto COMP_EXIT_HANDLE_SINGLE_GET;
                }
                if (written_len > 0)
                {
                    temp_buff_len += sprintf(email_comp_p->buffer + temp_buff_len,
                                             "Reply-To: %s\r\n",
                                             addr_encoded_full);
                }
            }

            /* From address */
            if (email_comp_p->msg_header->addr_from ||
                email_comp_p->comp_type == EMAIL_COMP_BY_HD)
            {
                res = email_comp_addr_single_get(
                        email_comp_p,
                        addr_encoded_full,
                        EMAIL_COMP_ADDR_ENCODED_FULL_LEN,
                        SRV_EMAIL_ADDR_TYPE_FROM,
                        &written_len);

                if (res != SRV_EMAIL_RESULT_SUCC)
                {
                    goto COMP_EXIT_HANDLE_SINGLE_GET;
                }
                if (written_len > 0)
                {
                    temp_buff_len += sprintf(email_comp_p->buffer + temp_buff_len,
                                             "From: %s\r\n",
                                             addr_encoded_full);
                }
            }

            email_comp_mfree(addr_encoded_full);

            res = email_comp_output_file_write(email_comp_p, email_comp_p->buffer, temp_buff_len);
            if (res != SRV_EMAIL_RESULT_SUCC)
            {
                return res;
            }
            email_comp_p->output_size += temp_buff_len;

            /************ NO BREAK ***********/

        case EMAIL_COMP_OP_WRITE_HEADER_ADDR_TO:
            /* To address(s) */
            memset(email_comp_p->buffer, 0, EMAIL_COMP_ENCODE_TMP_STR_LEN);

            if (email_comp_p->msg_header->addr_to_num > 0)
            {
                res = email_comp_addr_list_get(
                        email_comp_p,
                        email_comp_p->buffer,
                        EMAIL_COMP_ENCODE_TMP_STR_LEN,
                        SRV_EMAIL_ADDR_TYPE_TO,
                        &written_len);
                if (res != SRV_EMAIL_RESULT_SUCC)
                {
                    return res;
                }
                email_comp_p->output_size += written_len;
            }

            /************ NO BREAK ***********/

        case EMAIL_COMP_OP_WRITE_HEADER_ADDR_CC:
            /* CC address(s) */
            memset(email_comp_p->buffer, 0, EMAIL_COMP_ENCODE_TMP_STR_LEN);

            if (email_comp_p->msg_header->addr_cc_num > 0)
            {
                res = email_comp_addr_list_get(
                        email_comp_p,
                        email_comp_p->buffer,
                        EMAIL_COMP_ENCODE_TMP_STR_LEN,
                        SRV_EMAIL_ADDR_TYPE_CC,
                        &written_len);
                if (res != SRV_EMAIL_RESULT_SUCC)
                {
                    return res;
                }
                email_comp_p->output_size += written_len;
            }

            /************ NO BREAK ***********/

        case EMAIL_COMP_OP_WRITE_HEADER_ADDR_BCC:
            /* BCC address(s) */
            memset(email_comp_p->buffer, 0, EMAIL_COMP_ENCODE_TMP_STR_LEN);

            if (email_comp_p->msg_header->addr_bcc_num > 0)
            {
                res = email_comp_addr_list_get(
                        email_comp_p,
                        email_comp_p->buffer,
                        EMAIL_COMP_ENCODE_TMP_STR_LEN,
                        SRV_EMAIL_ADDR_TYPE_BCC,
                        &written_len);
                if (res != SRV_EMAIL_RESULT_SUCC)
                {
                    return res;
                }
                email_comp_p->output_size += written_len;
            }

            /************ NO BREAK ***********/

        case EMAIL_COMP_OP_WRITE_HEADER_SUBJ:
            /* Subject */
            memset(email_comp_p->buffer, 0, EMAIL_COMP_ENCODE_TMP_STR_LEN);

            res = email_comp_subj_get(
                    email_comp_p,
                    email_comp_p->buffer,
                    EMAIL_COMP_ENCODE_TMP_STR_LEN,
                    &written_len);
            if (res != SRV_EMAIL_RESULT_SUCC)
            {
                return res;
            }
            email_comp_p->output_size += written_len;

            /************ NO BREAK ***********/

        case EMAIL_COMP_OP_WRITE_HEADER_OTHERS:
            /* Message-ID */
            memset(email_comp_p->buffer, 0, EMAIL_COMP_ENCODE_TMP_STR_LEN);
            msg_id_str = (CHAR*) email_comp_malloc(EMAIL_COMP_MSG_ID_STR_MAX_LEN);
            MMI_ASSERT(msg_id_str != NULL);
            email_comp_gen_msgid(msg_id_str);
            temp_buff_len = sprintf(email_comp_p->buffer, "Message-ID: %s\r\n", msg_id_str);
            email_comp_mfree(msg_id_str);

            /* MIME version */
            temp_buff_len += sprintf(email_comp_p->buffer + temp_buff_len, "Mime-Version: 1.0\r\n");

            /* Mail Priority */
            priority = 3;
            switch (email_comp_p->msg_header->priority)
            {
                case EMAIL_MSG_PRIO_HIGH:
                    priority = 1;
                    break;
                case EMAIL_MSG_PRIO_LOW:
                    priority = 5;
                    break;
            }

            // X-Priority
            temp_buff_len += sprintf(email_comp_p->buffer + temp_buff_len, "%s: %d\r\n", IMAP4_CMD_STR_X_PRIORITY, priority);

            /* Mailer */
            temp_buff_len += sprintf(email_comp_p->buffer + temp_buff_len, "X-Mailer: Mediatek\r\n");

        #ifdef __SMS_CLOUD_SUPPORT__
            if (email_comp_p->msg_handle != EMAIL_MSG_INVALID_HANDLE)
            {
                CHAR *buff;
                U32 len;

                // Check X-Mtk-Sync-Uid
                srv_email_msg_get_extra_field(email_comp_p->msg_handle, SRV_EMAIL_MSG_SAVE_EXTRA_SMS_UID, &buff, &len);
                if (buff)
                {
                    // X-Uniform-Type-Identifier
                    temp_buff_len += sprintf(email_comp_p->buffer + temp_buff_len, "%s: ", IMAP4_CMD_STR_X_MTK_SYNC_TID);
                    memcpy(
                        email_comp_p->buffer + temp_buff_len,
                        IMAP4_CMD_STR_X_MTK_SYNC_TID_VAL,
                        strlen(IMAP4_CMD_STR_X_MTK_SYNC_TID_VAL));
                    temp_buff_len += strlen(IMAP4_CMD_STR_X_MTK_SYNC_TID_VAL);
                    temp_buff_len += sprintf(email_comp_p->buffer + temp_buff_len, "%\r\n");

                    // X-Mtk-Sync-Uid
                    temp_buff_len += sprintf(email_comp_p->buffer + temp_buff_len, "%s: ", IMAP4_CMD_STR_X_MTK_SYNC_UID);
                    memcpy(email_comp_p->buffer + temp_buff_len, buff, len);
                    temp_buff_len += len;
                    temp_buff_len += sprintf(email_comp_p->buffer + temp_buff_len, "%\r\n");

                    // X-Mtk-Sync-Sms-Data
                    srv_email_msg_get_extra_field(email_comp_p->msg_handle, SRV_EMAIL_MSG_SAVE_EXTRA_SMS_DATA, &buff, &len);
                    if (buff)
                    {
                        CHAR *encoded_buff;
                        U32 encoded_output_len = applib_base64_encode_basic(buff, len, NULL, 0, KAL_FALSE);

                        encoded_output_len++;
                        encoded_buff = email_comp_malloc(encoded_output_len);
                        memset(encoded_buff, 0, encoded_output_len);

                        applib_base64_encode_basic(buff, len, encoded_buff, encoded_output_len, KAL_FALSE);

                        temp_buff_len += sprintf(email_comp_p->buffer + temp_buff_len, "%s: %s\r\n", IMAP4_CMD_STR_X_MTK_SYNC_SMS_DATA, encoded_buff);

                        email_comp_mfree(encoded_buff);
                    }
                }
            }
        #endif /* __SMS_CLOUD_SUPPORT__ */

            /* outer Content-Type & Boundary if needed */
            temp_buff_len += email_comp_write_boundary_content_type(
                                email_comp_p,
                                email_comp_p->buffer + temp_buff_len,
                                EMAIL_COMP_ENCODE_TMP_STR_LEN - temp_buff_len);

            MMI_ASSERT(temp_buff_len <= EMAIL_COMP_ENCODE_TMP_STR_LEN);

            email_comp_p->output_size += temp_buff_len;
            res = email_comp_output_file_write(email_comp_p, email_comp_p->buffer, temp_buff_len);
            if (res != SRV_EMAIL_RESULT_SUCC)
            {
                return res;
            }

            email_comp_p->op = EMAIL_COMP_OP_FORM_BODY_HDR_INIT;
            break;

        default:
            MMI_ASSERT(0);
            break;
    }   /* switch */
    return SRV_EMAIL_RESULT_SUCC;

COMP_EXIT_HANDLE_SINGLE_GET:
    email_comp_mfree(addr_encoded_full);
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_get_day_of_the_week
 * DESCRIPTION
 *
 * PARAMETERS
 *  year        [IN]
 *  month       [IN]
 *  day         [IN]
 * RETURNS
 *
 *****************************************************************************/
static email_comp_get_day_of_the_week(S32 year, S32 month, S32 day)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 week;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (month == 1)
    {
        month = 13;
        year -= 1;
    }
    else if (month == 2)
    {
        month = 14;
        year -= 1;
    }

    week = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;

    return (kal_uint8) (week + 1);
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_gen_date
 * DESCRIPTION
 *
 * PARAMETERS
 *  email_comp_p        [?]     [?]
 *  s                   [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
U32 email_comp_gen_date(srv_email_comp_struct *email_comp_p, CHAR *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    struct tm *l, when;
    static CHAR tz[16];
    MMI_BOOL use_curr_sys_date_time = MMI_FALSE;
    MMI_BOOL zind;
    U8 zhours;      /* Zone Hours */
    U8 zminutes;    /* Zone Minutes */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_comp_p->msg_header->created_date == 0)
    {
        use_curr_sys_date_time = MMI_TRUE;
    }

    /* sprintf(s, "Date: Fri, 01 Jan 2010 00:00:00 +8000"); */
    if (use_curr_sys_date_time)
    {
        RTC_CTRL_GET_TIME_T rtc;
        memset(&rtc, 0, sizeof(RTC_CTRL_GET_TIME_T));
    	DclRTC_Control(email_comp_rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T*)&rtc); // New API with CMD & DATA

        when.tm_sec = rtc.u1Sec;
        when.tm_min = rtc.u1Min;
        when.tm_hour = rtc.u1Hour;
        when.tm_mday = rtc.u1Day;
        when.tm_mon = (rtc.u1Mon == 0 ? 1 : rtc.u1Mon);
        when.tm_year = rtc.u1Year + 2000;
        when.tm_wday = (rtc.u1WDay == 0 ? 1 : rtc.u1WDay);
    }
    else
    {
        applib_time_struct result;

        applib_dt_utc_sec_2_mytime(applib_dt_sec_utc_to_local(email_comp_p->msg_header->created_date), &result, MMI_FALSE);
        when.tm_sec = result.nSec;
        when.tm_min = result.nMin;
        when.tm_hour = result.nHour;
        when.tm_mday = result.nDay;
        when.tm_mon = result.nMonth;
        when.tm_year = result.nYear;
        when.tm_wday = email_comp_get_day_of_the_week(result.nYear, result.nMonth, result.nDay);
    }

    when.tm_isdst = 0;

    l = &when;

    applib_dt_get_tz_string(tz);

    if (tz[0] == '+')
    {
        zind = KAL_TRUE;
    }
    else
    {
        zind = KAL_FALSE;
    }

    zhours = (tz[1] - '0') * 10 + (tz[2] - '0');
    zminutes = (tz[3] - '0') * 10 + (tz[4] - '0');

    kal_sprintf(tz, "%c%02d%02d", zind == KAL_TRUE ? '+' : '-', zhours, zminutes);      /* tz[5] = '\0'; */

    return sprintf(
            (kal_char*) buffer,
            "Date: %s, %d %s %d %02d:%02d:%02d %s\r\n",
            Weekdays[l->tm_wday - 1],
            l->tm_mday,
            Months[l->tm_mon - 1],
            l->tm_year,
            l->tm_hour,
            l->tm_min,
            l->tm_sec,
            tz);
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_addr_single_get
 * DESCRIPTION
 *
 * PARAMETERS
 *  email_comp_p        [?]         [?]
 *  buff                [?]         [?]
 *  buff_len            [IN]
 *  type                [IN]
 *  addr_info           [?]         [?]
 * RETURNS
 *
 *****************************************************************************/
srv_email_result_enum email_comp_addr_single_get(
                        srv_email_comp_struct *email_comp_p,
                        CHAR *buff,
                        U32 buff_len,
                        srv_email_addr_type_enum type,
                        U32 *comp_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *disp;
    CHAR *addr;
    U32 disp_len;
    U32 addr_len;
    U32 ret_len = 0;
    srv_email_addr_struct *addr_info = NULL;
    srv_email_result_enum res = SRV_EMAIL_RESULT_SUCC;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(type == SRV_EMAIL_ADDR_TYPE_REPLY_TO ||
               type == SRV_EMAIL_ADDR_TYPE_FROM);

    if ((disp = email_comp_malloc(EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1)) == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    if ((addr = email_comp_malloc(EMAIL_MAX_ENCODED_ADDR_LEN + 1)) == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    memset(disp, 0, EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1);
    memset(addr, 0, EMAIL_MAX_ENCODED_ADDR_LEN + 1);

    while (1)
    {
        if (email_comp_p->comp_type == EMAIL_COMP_BY_ID)
        {
            EMAIL_STOR_HANDLE hd;

            res = srv_email_stor_msg_get_addr_open(email_comp_p->msg_id, 0, type, &hd);
            if (res != SRV_EMAIL_RESULT_SUCC)
            {
                goto COMP_EXIT_HANDLE;
            }

            res = srv_email_stor_msg_get_addr_next(hd,
                    EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1,
                    EMAIL_MAX_ENCODED_ADDR_LEN + 1, disp, addr);
            srv_email_stor_msg_get_addr_close(hd);

            if (res != SRV_EMAIL_RESULT_SUCC)
            {
                goto COMP_EXIT_HANDLE;
            }
            disp_len = strlen(disp);
            addr_len = strlen(addr);
            if (addr_len == 0)
            {
                ret_len = 0;
                break;
            }

            if (disp_len > 0)
            {
                MMI_ASSERT(disp_len + addr_len < buff_len - 3);     /* [blank]<> */
                ret_len = sprintf(buff, "%s <%s>", disp, addr);
                break;
            }

            if (*addr == '@')
            {
                MMI_ASSERT(disp_len + addr_len < buff_len - 2);
                ret_len = sprintf(buff, "<%s>", addr);
                break;
            }

            MMI_ASSERT(disp_len + addr_len < buff_len);
            ret_len = sprintf(buff, "%s", addr);
            break;
        }
        else if (email_comp_p->comp_type == EMAIL_COMP_BY_HD)
        {
            addr_info = email_comp_malloc(sizeof(*addr_info));
            if (addr_info == NULL)
            {
                goto COMP_EXIT_HANDLE;
            }
            memset(addr_info, 0, sizeof(*addr_info));

            if (type == SRV_EMAIL_ADDR_TYPE_REPLY_TO)
            {
                res = srv_email_msg_get_reply_to(email_comp_p->msg_handle, addr_info);
            }
            else // SRV_EMAIL_ADDR_TYPE_FROM
            {
                res = srv_email_msg_get_sender(email_comp_p->msg_handle, addr_info);
            }

            if (res != SRV_EMAIL_RESULT_SUCC)
            {
                email_comp_mfree(addr_info);
                break;
            }
            addr_len = mmi_wcslen(addr_info->email_addr);

            if (addr_info == NULL || addr_len == 0)
            {
                ret_len = 0;
                email_comp_mfree(addr_info);
                break;
            }

            /* email address */
            mmi_wcs_to_asc(addr, addr_info->email_addr);

            /* display name */
            disp_len = 0;
            if (addr_info->disp_name_len > 0)
            {
                U16 outLen = 0;
                U8 *converted_data = NULL;
                disp_len += sprintf(disp, "=?%s?B?", chset_get_preferred_mime_name(MMI_CHSET_UTF8));
                converted_data = srv_email_util_ucs2_to_chset((U8*)addr_info->disp_name, MMI_CHSET_UTF8, &outLen);
                disp_len += sprintf(disp + disp_len, "%s?=", converted_data);
                MMI_ASSERT(disp_len <= EMAIL_MAX_ENCODED_DISP_NAME_LEN);
                OslMfree(converted_data);
                ret_len = sprintf(buff, "%s <%s>", disp, addr);
                email_comp_mfree(addr_info);
                break;
            }

            if (*addr == '@')
            {
                MMI_ASSERT(disp_len + addr_len < buff_len - 2);
                ret_len = sprintf(buff, "<%s>", addr);
                email_comp_mfree(addr_info);
                break;
            }

            MMI_ASSERT(disp_len + addr_len < buff_len);
            ret_len = sprintf(buff, "%s", addr);
            email_comp_mfree(addr_info);
            break;
        }
    }

COMP_EXIT_HANDLE:
    email_comp_mfree(disp);
    email_comp_mfree(addr);
    *comp_len = ret_len;
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_addr_list_get
 * DESCRIPTION
 *
 * PARAMETERS
 *  email_comp_p        [?]         [?]
 *  buff                [?]         [?]
 *  buff_len            [IN]
 *  type                [IN]
 * RETURNS
 *
 *****************************************************************************/
srv_email_result_enum email_comp_addr_list_get(
                        srv_email_comp_struct *email_comp_p,
                        CHAR *buff,
                        U32 buff_len,
                        srv_email_addr_type_enum type,
                        U32 *write_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 addr_total_num = 0;
    EMAIL_STOR_HANDLE hd;
    CHAR *disp;
    CHAR *addr;
    U32 disp_len;
    U32 addr_len;
    U32 total_size = 0;
    U32 size_before_write = 0;
    srv_email_result_enum res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case SRV_EMAIL_ADDR_TYPE_TO:
            addr_total_num = email_comp_p->msg_header->addr_to_num;
            break;
        case SRV_EMAIL_ADDR_TYPE_CC:
            addr_total_num = email_comp_p->msg_header->addr_cc_num;
            break;
        case SRV_EMAIL_ADDR_TYPE_BCC:
            addr_total_num = email_comp_p->msg_header->addr_bcc_num;
            break;
        default:
            MMI_ASSERT(0);  /* other TYPE(s) NOT Supported! */
            break;
    }
    *write_len = 0;

    if (addr_total_num == 0)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }

    switch (type)
    {
        case SRV_EMAIL_ADDR_TYPE_TO:
            size_before_write = sprintf(buff, "To: ");
            break;
        case SRV_EMAIL_ADDR_TYPE_CC:
            size_before_write = sprintf(buff, "Cc: ");
            break;
        case SRV_EMAIL_ADDR_TYPE_BCC:
            size_before_write = sprintf(buff, "Bcc: ");
            break;
        default:
            MMI_ASSERT(0);
    }

    disp = email_comp_malloc(EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1);
    if (disp == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    addr = email_comp_malloc(EMAIL_MAX_ENCODED_ADDR_LEN + 1);
    if (addr == NULL)
    {
        email_comp_mfree(disp);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    if (email_comp_p->comp_type == EMAIL_COMP_BY_ID)
    {
        res = srv_email_stor_msg_get_addr_open(email_comp_p->msg_id, 0, type, &hd);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            goto COMP_EXIT_HANDLE;
        }
        for (i = 0; i < addr_total_num; i++)
        {
            if (size_before_write >= EMAIL_COMP_EXCEED_WRITE_BUFF_LEN)
            {
                total_size += size_before_write;
                res = email_comp_output_file_write(email_comp_p, buff, size_before_write);
                if (res != SRV_EMAIL_RESULT_SUCC)
                {
                    goto COMP_EXIT_HANDLE;
                }
                size_before_write = 0;
                memset(buff, 0, size_before_write);
            }

            res = srv_email_stor_msg_get_addr_next(hd, EMAIL_MAX_ENCODED_DISP_NAME_LEN + 1,
                    EMAIL_MAX_ENCODED_ADDR_LEN + 1, disp, addr);
            if (res == SRV_EMAIL_RESULT_NO_MORE_RESULT)
            {
                break;
            }
            if (res != SRV_EMAIL_RESULT_SUCC)
            {
                srv_email_stor_msg_get_addr_close(hd);
                goto COMP_EXIT_HANDLE;
            }

            disp_len = strlen(disp);
            addr_len = strlen(addr);

            if (!addr_len)
            {
                continue;
            }

            if (disp_len)
            {
                MMI_ASSERT(disp_len + addr_len < buff_len - 3);     /* [blank]<> */
                size_before_write += sprintf(buff + size_before_write, "%s <%s>", disp, addr);
            }
            else if (*addr == '@')
            {
                MMI_ASSERT(disp_len + addr_len < buff_len - 2);
                size_before_write += sprintf(buff + size_before_write, "<%s>", addr);
            }
            else
            {
                MMI_ASSERT(disp_len + addr_len < buff_len);
                size_before_write += sprintf(buff + size_before_write, "%s", addr);
            }

            if (i != addr_total_num - 1)
            {
                size_before_write += sprintf(buff + size_before_write, ",\r\n ");   /* [ ] for NEXT line */
            }
        }   /* for */
        srv_email_stor_msg_get_addr_close(hd);
        size_before_write += sprintf(buff + size_before_write, "\r\n");
    }       /* if (email_comp_p->comp_type == EMAIL_COMP_BY_ID) */
    else if (email_comp_p->comp_type == EMAIL_COMP_BY_HD)
    {
        srv_email_msg_get_recipient_struct *get_recipient_p;
        srv_email_addr_struct *addr_info;

        get_recipient_p = email_comp_malloc(sizeof(srv_email_msg_get_recipient_struct));
        addr_info = email_comp_malloc(sizeof(srv_email_addr_struct));
        get_recipient_p->addr_list = addr_info;

        for (i = 0; i < addr_total_num; i++)
        {
            if (size_before_write >= EMAIL_COMP_EXCEED_WRITE_BUFF_LEN)
            {
                total_size += size_before_write;
                email_comp_output_file_write(email_comp_p, buff, size_before_write);
                size_before_write = 0;
                memset(buff, 0, size_before_write);
            }
            get_recipient_p->start_index = i;
            get_recipient_p->number = 1;
            get_recipient_p->type = type;
            if (srv_email_msg_get_recipient(email_comp_p->msg_handle, get_recipient_p) != SRV_EMAIL_RESULT_SUCC)
            {
                break;
            }

            if ((addr_len = (U32) mmi_wcslen(addr_info->email_addr)) == 0)
            {
                break;
            }

            /* email address */
            mmi_wcs_to_asc(addr, addr_info->email_addr);

            /* display name */
            disp_len = 0;
            if (addr_info->disp_name_len > 0)
            {
                U16 outLen = 0;
                U8 *converted_data = NULL;
                disp_len += sprintf(disp, "=?%s?B?", chset_get_preferred_mime_name(MMI_CHSET_UTF8));
                converted_data = srv_email_util_ucs2_to_chset((U8*)addr_info->disp_name, MMI_CHSET_UTF8, &outLen);
                disp_len += sprintf(disp, "%s?=", converted_data);
                OslMfree(converted_data);
                size_before_write += sprintf(buff + size_before_write, "%s <%s>", disp, addr);
            }
            else if (*addr == '@')
            {
                MMI_ASSERT(disp_len + addr_len < buff_len - 2);
                size_before_write += sprintf(buff + size_before_write, "<%s>", addr);
            }
            else
            {
                MMI_ASSERT(disp_len + addr_len < buff_len);
                size_before_write += sprintf(buff + size_before_write, "%s", addr);
            }

            if (i < addr_total_num - 1) /* one more to deal */
            {
                size_before_write += sprintf(buff + size_before_write, ",\r\n ");       /* [ ] for NEXT line */
            }
        }
        size_before_write += sprintf(buff + size_before_write, "\r\n");

        email_comp_mfree(get_recipient_p);
        email_comp_mfree(addr_info);
    }

    email_comp_mfree(disp);
    email_comp_mfree(addr);

    email_comp_output_file_write(email_comp_p, buff, size_before_write);
    total_size += size_before_write;
    *write_len = total_size;
    return SRV_EMAIL_RESULT_SUCC;

COMP_EXIT_HANDLE:
    email_comp_mfree(disp);
    email_comp_mfree(addr);
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_subj_get
 * DESCRIPTION
 *
 * PARAMETERS
 *  email_comp_p        [?]         [?]
 *  buff                [?]         [?]
 *  buff_len            [IN]
 * RETURNS
 *
 *****************************************************************************/
srv_email_result_enum email_comp_subj_get(srv_email_comp_struct *email_comp_p, CHAR *buff, U32 buff_len, U32 *written)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 size_before_write;
    U32 size = 0;
    srv_email_result_enum res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *written = 0;
    size_before_write = sprintf(buff, "Subject: ");

    size = buff_len - size_before_write;

    // TODO: line wrap
    if (email_comp_p->comp_type == EMAIL_COMP_BY_ID)
    {
        res = srv_email_stor_msg_get_subj(email_comp_p->msg_id, buff + size_before_write, &size);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            return res;
        }
        size_before_write += size;
    }
    else if (email_comp_p->comp_type == EMAIL_COMP_BY_HD)
    {
        WCHAR *get_subj;
        U32 get_subj_len;
        S32 charset;
        S32 dst_len;
        CHAR *encoded_buff;
        U32 encoded_output_len;
       
        res = srv_email_msg_get_subject_len(email_comp_p->msg_handle, &get_subj_len, &charset);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            return res;
        }

        if (get_subj_len > 0)
        {
            size_before_write += sprintf(buff + size_before_write, "=?UTF-8?B?");

            get_subj = email_comp_malloc((get_subj_len + 1) * sizeof(WCHAR));

            res = srv_email_msg_get_subject(email_comp_p->msg_handle, get_subj, &get_subj_len);
            if (res != SRV_EMAIL_RESULT_SUCC)
            {
                return res;
            }

            *(get_subj + get_subj_len) = L'\0';

            dst_len = buff_len - size_before_write - strlen("?=");

            mmi_chset_convert(
                (mmi_chset_enum)charset,
                CHSET_UTF8,
                (CHAR*)get_subj,
                buff + size_before_write,
                dst_len);

            email_comp_mfree(get_subj);

            encoded_output_len = applib_base64_encode_basic(
                                    buff + size_before_write,
                                    strlen(buff + size_before_write),
                                    NULL,
                                    0,
                                    KAL_FALSE);
            encoded_output_len++;
            encoded_buff = email_comp_malloc(encoded_output_len);
            memset(encoded_buff, 0, encoded_output_len);

            applib_base64_encode_basic(buff + size_before_write, strlen(buff + size_before_write),
                                       encoded_buff, encoded_output_len, KAL_FALSE);

            size_before_write += sprintf(buff + size_before_write, "%s?=", encoded_buff);

            email_comp_mfree(encoded_buff);
        }
    }

    size_before_write += sprintf(buff + size_before_write, "\r\n");

    res = email_comp_output_file_write(email_comp_p, buff, size_before_write);
    if (res != SRV_EMAIL_RESULT_SUCC)
    {
        return res;
    }

    *written = size_before_write;

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_write_boundary_content_type
 * DESCRIPTION
 *
 * PARAMETERS
 *  email_comp_p        [?]         [?]
 *  buff                [?]         [?]
 *  buff_len            [IN]
 * RETURNS
 *
 *****************************************************************************/
U32 email_comp_write_boundary_content_type(srv_email_comp_struct *email_comp_p, CHAR *buff, U32 buff_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (email_comp_p->msg_body->multipart)
    {
        U32 size_before_write;

        size_before_write = sprintf(buff, "Content-Type: multipart/mixed;\r\n");

        /* Boundary parameter */
        size_before_write += sprintf(buff + size_before_write, "\tboundary=\"----%s\"\r\n", email_comp_p->boundary);

        /* 1st boundary */
        size_before_write += sprintf(buff + size_before_write, "\r\n");
        size_before_write += sprintf(buff + size_before_write, "------%s\r\n", email_comp_p->boundary);
        return size_before_write;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_write_mime_body_header
 * DESCRIPTION
 *
 * PARAMETERS
 *  email_comp_p        [?]     [?]
 * RETURNS
 *
 *****************************************************************************/
srv_email_result_enum email_comp_write_mime_body_header(srv_email_comp_struct *email_comp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 text_before_write = 0;
    srv_email_result_enum res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(email_comp_p->buffer, 0, EMAIL_COMP_ENCODE_TMP_STR_LEN);

    while (1)
    {
        switch (email_comp_p->op)
        {
            case EMAIL_COMP_OP_FORM_BODY_HDR_INIT:
                if (email_comp_p->msg_body->text_len == 0)  /* NO text content */
                {
                    text_before_write += sprintf(email_comp_p->buffer + text_before_write, "\r\n");
                    email_comp_p->op = EMAIL_COMP_OP_WRITE_BODY_HEADER_TO_FILE;
                }
                else
                {
                    email_comp_p->op = EMAIL_COMP_OP_WRITE_BODY_HEADER_TO_BUFF;
                }
                break;

            case EMAIL_COMP_OP_WRITE_BODY_HEADER_TO_BUFF:
                text_before_write += sprintf(
                                        email_comp_p->buffer + text_before_write,
                                        "Content-Type: text/plain; charset=%s\r\n",
                                        chset_get_preferred_mime_name(MMI_CHSET_UTF8));

                text_before_write += sprintf(
                                        email_comp_p->buffer + text_before_write,
                                        "Content-Transfer-Encoding: %s\r\n",
                                        email_comp_get_encode_type_str(email_comp_p->msg_body->text_encoding));

                text_before_write += sprintf(email_comp_p->buffer + text_before_write, "\r\n");

                email_comp_p->op = EMAIL_COMP_OP_WRITE_BODY_HEADER_TO_FILE;

                /* NO BREAK */

            case EMAIL_COMP_OP_WRITE_BODY_HEADER_TO_FILE:
                res = email_comp_output_file_write(email_comp_p, email_comp_p->buffer, text_before_write);
                if (res != SRV_EMAIL_RESULT_SUCC)
                {
                    return res;
                }
                email_comp_p->output_size += text_before_write;

                return SRV_EMAIL_RESULT_SUCC;

            default:
                MMI_ASSERT(0);

        }   /* switch */
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_cntx_free
 * DESCRIPTION
 *
 * PARAMETERS
 *  email_comp_p        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void email_comp_cntx_free(srv_email_comp_struct *email_comp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_comp_mfree(email_comp_p->msg_header);
    email_comp_mfree(email_comp_p->msg_body);
    email_comp_mfree(email_comp_p->buffer);
    email_comp_mfree(email_comp_p->output_path);
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_write_cont
 * DESCRIPTION
 *
 * PARAMETERS
 *  email_comp_p        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
srv_email_result_enum email_comp_write_cont(srv_email_comp_struct *email_comp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *cont_path;
    FS_HANDLE cont_hd = EMAIL_STOR_INVALID_FS_HANDLE;
    U32 size;
    srv_email_result_enum res = SRV_EMAIL_RESULT_SUCC;
    S32 minor_errno = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_comp_p->read_limit = BASE_64_PATTERN;

    size = sizeof(WCHAR) * EMAIL_COMP_SYS_PATH_LEN;
    cont_path = email_comp_malloc(size);
    if (cont_path == NULL)
    {
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    memset(cont_path, 0, size);

    if (email_comp_p->comp_type == EMAIL_COMP_BY_ID)
    {
        res = srv_email_stor_msg_get_cont(email_comp_p->msg_id, SRV_EMAIL_STOR_MSG_CONT_TEXT, NULL, cont_path, &size);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            goto COMP_EXIT_HANDLE;
        }
    }
    else if (email_comp_p->comp_type == EMAIL_COMP_BY_HD)
    {
        res = srv_email_msg_get_cont_for_comp(email_comp_p->msg_handle, SRV_EMAIL_STOR_MSG_CONT_TEXT, NULL, cont_path, &size);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            goto COMP_EXIT_HANDLE;
        }
    }

    if (mmi_wcslen(cont_path) > 0)
    {
        WCHAR *dst_path;
        if (email_comp_p->msg_body->text_encoding == MMI_CHSET_UTF8)
        {
            dst_path = cont_path;
        }
        else
        {
            dst_path = email_comp_malloc(sizeof(WCHAR) * EMAIL_COMP_SYS_PATH_LEN);
            if (dst_path == NULL)
            {
                goto COMP_EXIT_HANDLE;
            }

            kal_wsprintf(dst_path, "%s%s\\%08X.cont", srv_email_get_root_path(), EMAIL_COMP_FLDR_NAME, (U32)dst_path);
            res = srv_email_file_chset_convert(
                    cont_path,
                    (CHAR*)chset_get_preferred_mime_name((chset_enum)email_comp_p->msg_body->text_charset),
                    dst_path,
                    (CHAR*)chset_get_preferred_mime_name(CHSET_UTF8),
                    &minor_errno);
            if (res != SRV_EMAIL_RESULT_SUCC)
            {
                srv_email_errno_set(minor_errno);
                goto COMP_EXIT_HANDLE;
            }
        }
        if (EMAIL_STOR_FS_HANDLE_INVALID(cont_hd = FS_Open(dst_path, FS_READ_ONLY)))
        {
            goto COMP_EXIT_HANDLE;
        }

        email_comp_message_encode_and_copy(email_comp_p, cont_hd, email_comp_p->msg_body->text_encoding, MMI_FALSE);
        FS_Close(cont_hd);

        if (email_comp_p->msg_body->text_encoding != CHSET_UTF8)
        {
            FS_Delete(dst_path);
            email_comp_mfree(dst_path);
        }
    }

    email_comp_p->op = EMAIL_COMP_OP_WRITE_ATTCH_INIT;

COMP_EXIT_HANDLE:
    email_comp_mfree(cont_path);
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_get_encode_type_str
 * DESCRIPTION
 *
 * PARAMETERS
 *  encoding        [IN]
 * RETURNS
 *
 *****************************************************************************/
CHAR *email_comp_get_encode_type_str(U8 encoding)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (encoding)
    {
        case EMAIL_MIME_ENC8BIT:
            return "8bit";

        case EMAIL_MIME_ENCBASE64:
            return "base64";

        case EMAIL_MIME_ENCQUOTPRINT:
            return "quoted-printable";

        case EMAIL_MIME_ENC7BIT:
        default:
            return "7bit";
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_gen_msgid
 * DESCRIPTION
 *
 * PARAMETERS
 *  buf     [?]     [?]
 * RETURNS
 *
 *****************************************************************************/
U32 email_comp_gen_msgid(CHAR *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 res_len;
    struct tm *tm, when;
    U8 lip[4];
    static CHAR MsgIdPfx = 'A';
    //t_rtc rtc;
    RTC_CTRL_GET_TIME_T rtc;
    	
    U32 my_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_my_task_index(&my_index);

    //RTC_GetTime(&rtc);
    DclRTC_Control(email_comp_rtc_handler, RTC_CMD_GET_TIME, (DCL_CTRL_DATA_T*)&rtc); // New API with CMD & DATA
    when.tm_sec = rtc.u1Sec;
    when.tm_min = rtc.u1Min;
    when.tm_hour = rtc.u1Hour;
    when.tm_mday = rtc.u1Day;
    when.tm_mon = rtc.u1Mon - 1;
    when.tm_year = rtc.u1Year + 100;
    when.tm_wday = rtc.u1WDay;
    /*when.tm_sec = rtc.rtc_sec;
    when.tm_min = rtc.rtc_min;
    when.tm_hour = rtc.rtc_hour;
    when.tm_mday = rtc.rtc_day;
    when.tm_mon = rtc.rtc_mon - 1;
    when.tm_year = rtc.rtc_year + 100;
    when.tm_wday = rtc.rtc_wday;*/
    when.tm_isdst = 0;
    tm = &when;

    if (soc_getlocalip(&lip[0]) == SOC_SUCCESS)
    {
        res_len = sprintf(
                    (kal_char*) buf,
                    "<%d%02d%02d%02d%02d%02d.G%c%d@%d.%d.%d.%d>",
                    tm->tm_year + 1900,
                    tm->tm_mon + 1,
                    tm->tm_mday,
                    tm->tm_hour,
                    tm->tm_min,
                    tm->tm_sec,
                    MsgIdPfx,
                    my_index + MOD_EMAIL,
                    lip[0],
                    lip[1],
                    lip[2],
                    lip[3]);
    }
    else
    {
        res_len = sprintf(
                    (kal_char*) buf,
                    "<%d%02d%02d%02d%02d%02d.G%c%d@%s>",
                    tm->tm_year + 1900,
                    tm->tm_mon + 1,
                    tm->tm_mday,
                    tm->tm_hour,
                    tm->tm_min,
                    tm->tm_sec,
                    MsgIdPfx,
                    my_index + MOD_EMAIL,
                    "127.0.0.1");
    }

    MsgIdPfx = (MsgIdPfx == 'Z') ? 'A' : MsgIdPfx + 1;

    return res_len;
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_message_encode_and_copy
 * DESCRIPTION
 *
 * PARAMETERS
 *  email_comp_p        [IN]        Composer context
 *  hd                  [IN]        FS handle
 *  encoding_type       [IN]        Encoding type
 *  async_mode          [IN]        Whether use ASYNC mode
 * RETURNS
 *  void
 *****************************************************************************/
srv_email_result_enum email_comp_message_encode_and_copy(
                        srv_email_comp_struct *email_comp_p,
                        FS_HANDLE hd,
                        U8 encoding_type,
                        MMI_BOOL async_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *codestream = NULL;
    U32 encoded_input_len = 0;
    U32 encoded_output_len = 0;
    S32 ret = 0;
    U32 ticks_bgn = 0;
    U32 ticks_end = 0;
    srv_email_result_enum result = SRV_EMAIL_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&ticks_bgn);

    // allocate memory when execution the first time
    if (email_comp_p->line_buf == NULL)
    {
        email_comp_p->line_buf = email_comp_malloc(email_comp_p->read_limit + 1);
        email_comp_p->encoded_left_len = 0;
        MMI_ASSERT(email_comp_p->line_buf != NULL);
    }

    while (MMI_TRUE)
    {
        U32 expected_read_len = email_comp_p->read_limit - email_comp_p->encoded_left_len;
        U32 actual_read_len = 0;

        encoded_input_len = 0;

        ret = FS_Read(hd,
                      email_comp_p->line_buf + email_comp_p->encoded_left_len,
                      expected_read_len,
                      &actual_read_len);
        if (ret == FS_NO_ERROR)
        {
            encoded_input_len = email_comp_p->encoded_left_len + actual_read_len;
        }

        if (encoded_input_len == 0)    // reach the end of input file
        {
            result = SRV_EMAIL_RESULT_SUCC;
            break;
        }

        if (encoding_type == EMAIL_MIME_ENCBASE64)
        {
            MMI_BOOL last_part = (MMI_BOOL)(!(actual_read_len == expected_read_len));

            codestream = email_comp_base64_encode(
                          email_comp_p->line_buf,
                          encoded_input_len,
                          email_comp_p->buffer,
                          &encoded_output_len,
                          last_part ? NULL : (&email_comp_p->encoded_left_len));
            if (last_part)
            {
                email_comp_p->encoded_left_len = 0;
            }
            if (email_comp_p->encoded_left_len > 0)
            {
                memmove(email_comp_p->line_buf,
                        email_comp_p->line_buf + encoded_input_len - email_comp_p->encoded_left_len,
                        email_comp_p->encoded_left_len + 1); //  1 for '\n'
            }
        }
        else
        {
            codestream = email_comp_p->line_buf;
        }

        if (encoded_output_len != 0)
        {
            email_comp_output_file_write(email_comp_p, codestream, encoded_output_len);
            email_comp_p->output_size += encoded_output_len;
        }

        kal_get_time(&ticks_end);

        if (async_mode && (ticks_end - ticks_bgn >= KAL_TICKS_100_MSEC))
        {
            result = SRV_EMAIL_RESULT_WOULDBLOCK;
            break;
        }
    }

    if (result == SRV_EMAIL_RESULT_SUCC)
    {
        email_comp_mfree(email_comp_p->line_buf);
        email_comp_p->line_buf = NULL;
    }
    else
    {
        MMI_ASSERT(result == SRV_EMAIL_RESULT_WOULDBLOCK);
        srv_email_schdl_start_job(
            (srv_email_schdl_funcptr_type) email_comp_fsm, email_comp_p);
    }
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  email_comp_base64_encode
 * DESCRIPTION
 *
 * PARAMETERS
 *  src         [?]         [?]
 *  srcl        [IN]
 *  dest        [?]         [?]
 *  destl       [?]         [?]
 * RETURNS
 *
 *****************************************************************************/
CHAR *email_comp_base64_encode(CHAR *src, S32 srcl, CHAR *dest, U32 *destl, U32 *left_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *d;
    U8 *s = (U8*) src;
    U32 i;
    U32 lines;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = ((srcl + 2) / 3) * 4;   /* 6 bit ==> 8 bit */
    lines = i / 76;
    i = lines * 78;

    d = (U8*) dest;

    memset(d, 0, BASE_64_BUFFER);   /* !!! notice here, the buffer len MUST be larger than BASE_64_BUFFER */

    /* process tuples */
    for (i = 0; lines > 0; s += 3, srcl -= 3)
    {
        EMAIL_COMP_BASE64_ENCODE_1(d, s);
        if ((++i) == 19)
        {
            i = 0;  /* restart line break count, insert CRLF */
            --lines;
            *d++ = '\015';
            *d++ = '\012';
        }
    }

    if (left_len == NULL)
    {
        for (; srcl >= 3; s += 3, srcl -= 3)
        {
            EMAIL_COMP_BASE64_ENCODE_1(d, s);
            if ((++i) == 19)
            {
                i = 0;  /* restart line break count, insert CRLF */
                *d++ = '\015';
                *d++ = '\012';
            }
        }
        if (srcl)
        {
            EMAIL_COMP_BASE64_ENCODE_2(d, s, srcl);
            if (srcl)
            {
                srcl--; // count third character if processed
            }

            if ((++i) == 19)
            {
                i = 0;  // restart line break count, insert CRLF
                *d++ = '\015';
                *d++ = '\012';
            }
        }
        *d++ = '\015';
        *d++ = '\012';  // insert final CRLF
    }
    else
    {
        *left_len = srcl;
    }

    *d = '\0';      /* tie off string */
    *destl = strlen(dest);

    return dest;    /* return the resulting string */
}


/*****************************************************************************
 * FUNCTION
 *  email_comp_write_attch
 * DESCRIPTION
 *
 * PARAMETERS
 *  email_comp_p        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
srv_email_result_enum email_comp_write_attch(srv_email_comp_struct *email_comp_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 size_before_write = 0;
    WCHAR *attch_path = NULL;
    srv_email_result_enum res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (MMI_TRUE)
    {
        switch (email_comp_p->op)
        {
            case EMAIL_COMP_OP_WRITE_ATTCH_INIT:
                email_comp_p->attch = email_comp_malloc(sizeof(email_comp_attch_struct));
                if (email_comp_p->attch == NULL)
                {
                    return SRV_EMAIL_RESULT_NO_MEMORY;
                }

                if (email_comp_p->msg_header->attch_num == 0)
                {
                    email_comp_p->op = EMAIL_COMP_OP_WRITE_END_BDRY;
                    email_comp_mfree(email_comp_p->attch);
                    email_comp_p->attch = NULL;
                    return SRV_EMAIL_RESULT_SUCC;
                }

                if (email_comp_p->comp_type == EMAIL_COMP_BY_ID)
                {
                    email_comp_p->attch_stor = email_comp_malloc(sizeof(srv_email_stor_attch_struct));
                    if (email_comp_p->attch_stor == NULL)
                    {
                        email_comp_mfree(email_comp_p->attch);
                        email_comp_p->attch = NULL;
                        return SRV_EMAIL_RESULT_NO_MEMORY;
                    }

                    res = srv_email_stor_msg_get_attch_open(email_comp_p->msg_id, 0, &email_comp_p->attch_hd);
                    if (res != SRV_EMAIL_RESULT_SUCC)
                    {
                        email_comp_mfree(email_comp_p->attch_stor);
                        email_comp_p->attch_stor = NULL;
                        email_comp_mfree(email_comp_p->attch);
                        email_comp_p->attch = NULL;
                        return res;
                    }

                    res = srv_email_stor_msg_get_attch_next(email_comp_p->attch_hd, email_comp_p->attch_stor);
                    if (res == SRV_EMAIL_RESULT_NO_MORE_RESULT)
                    {
                        srv_email_stor_msg_get_attch_close(email_comp_p->attch_hd);
                        email_comp_p->attch_hd = EMAIL_STOR_INVALID_HANDLE;
                        email_comp_mfree(email_comp_p->attch_stor);
                        email_comp_p->attch_stor = NULL;
                        email_comp_mfree(email_comp_p->attch);
                        email_comp_p->attch = NULL;
                        email_comp_p->op = EMAIL_COMP_OP_WRITE_END_BDRY;
                        return SRV_EMAIL_RESULT_SUCC;
                    }
                    if (res != SRV_EMAIL_RESULT_SUCC)
                    {
                        srv_email_stor_msg_get_attch_close(email_comp_p->attch_hd);
                        email_comp_p->attch_hd = EMAIL_STOR_INVALID_HANDLE;
                        email_comp_mfree(email_comp_p->attch_stor);
                        email_comp_p->attch_stor = NULL;
                        email_comp_mfree(email_comp_p->attch);
                        email_comp_p->attch = NULL;
                        return res;
                    }

                    email_comp_p->attch->attch_id = email_comp_p->attch_stor->attch_id;
                    email_comp_p->attch_stor->file_name[EMAIL_STOR_ENCOD_FILE_NAME_LEN] = 0;
                    email_comp_p->attch_stor->content_type[EMAIL_STOR_CONT_TYPE_STR_LEN] = 0;
                    strcpy(email_comp_p->attch->file_name, email_comp_p->attch_stor->file_name);
                    strcpy(email_comp_p->attch->mime, email_comp_p->attch_stor->content_type);
                }
                else if (email_comp_p->comp_type == EMAIL_COMP_BY_HD)
                {
                    U32 num = 1;
                    U32 file_name_len = 0;
                    U16 outLen = 0;
                    U8 *converted_data = NULL;

                    email_comp_p->attch_app = email_comp_malloc(sizeof(srv_email_attach_struct));
                    if (email_comp_p->attch_app == NULL)
                    {
                        email_comp_mfree(email_comp_p->attch);
                        email_comp_p->attch = NULL;
                        return SRV_EMAIL_RESULT_NO_MEMORY;
                    }
                    res = srv_email_msg_get_attachment_info(
                            email_comp_p->msg_handle, email_comp_p->attch_handled_cnt, (S32*)&num, email_comp_p->attch_app);
                    if (res != SRV_EMAIL_RESULT_SUCC || num < 1)
                    {
                        email_comp_mfree(email_comp_p->attch_app);
                        email_comp_p->attch_app = NULL;
                        email_comp_mfree(email_comp_p->attch);
                        email_comp_p->attch = NULL;
                        return res != SRV_EMAIL_RESULT_SUCC ? res : SRV_EMAIL_RESULT_FAIL;
                    }
                    ++(email_comp_p->attch_handled_cnt);

                    file_name_len += sprintf(email_comp_p->attch->file_name, "=?%s?B?", chset_get_preferred_mime_name(MMI_CHSET_UTF8));
                    converted_data = srv_email_util_ucs2_to_chset((U8*)email_comp_p->attch_app->name, MMI_CHSET_UTF8, &outLen);
                    strncpy(email_comp_p->attch->file_name + file_name_len, (char *)converted_data,
                           EMAIL_STOR_ENCOD_FILE_NAME_LEN - 1 - file_name_len - strlen("?="));
                    strcat(email_comp_p->attch->file_name, "%?=");
                    OslMfree(converted_data);

                    strcpy(email_comp_p->attch->mime, srv_email_util_get_mime_type_str((chset_enum)(email_comp_p->attch_app->mime_type)));
                }

                memset(email_comp_p->buffer, 0, EMAIL_COMP_ENCODE_TMP_STR_LEN);
                email_comp_p->read_limit = BASE_64_PATTERN;

                email_comp_p->op = EMAIL_COMP_OP_WRITE_ATTCH_HEADER_TO_BUFF;
                break;

            case EMAIL_COMP_OP_WRITE_ATTCH_HEADER_TO_BUFF:
                /* Write the Attachment Header (Content-Type, Encoding, etc) */
                size_before_write = sprintf(email_comp_p->buffer, "\r\n------%s\r\n", email_comp_p->boundary);

                size_before_write += sprintf(email_comp_p->buffer + size_before_write, "Content-Type: %s;\r\n", email_comp_p->attch->mime);

                size_before_write += sprintf(email_comp_p->buffer + size_before_write, "\tname=\"%s\"\r\n", email_comp_p->attch->file_name);

                size_before_write += sprintf(email_comp_p->buffer + size_before_write, "Content-Transfer-Encoding: %s\r\n",
                                        email_comp_get_encode_type_str(EMAIL_MIME_ENCBASE64));

                size_before_write += sprintf(email_comp_p->buffer + size_before_write, "Content-Disposition: %s;\r\n", "attachment");

                size_before_write += sprintf(email_comp_p->buffer + size_before_write, "\tfilename=\"%s\"\r\n\r\n", email_comp_p->attch->file_name);

                email_comp_p->op = EMAIL_COMP_OP_WRITE_ATTCH_HEADER_TO_FILE;

            case EMAIL_COMP_OP_WRITE_ATTCH_HEADER_TO_FILE:
                res = email_comp_output_file_write(email_comp_p, email_comp_p->buffer, size_before_write);
                if (res != SRV_EMAIL_RESULT_SUCC)
                {
                    goto COMP_EXIT_HANDLE;
                }
                email_comp_p->output_size += size_before_write;

                /* open attachment file */
                if (email_comp_p->comp_type == EMAIL_COMP_BY_ID)
                {
                    attch_path = email_comp_malloc(sizeof(WCHAR) * EMAIL_COMP_SYS_PATH_LEN);
                    if (attch_path == NULL)
                    {
                        res = SRV_EMAIL_RESULT_NO_MEMORY;
                        goto COMP_EXIT_HANDLE;
                    }

                    srv_email_stor_msg_get_attch_path(
                        email_comp_p->attch->attch_id, attch_path, sizeof(WCHAR) * EMAIL_COMP_SYS_PATH_LEN);
                }
                else if (email_comp_p->comp_type == EMAIL_COMP_BY_HD)
                {
                    attch_path = email_comp_p->attch_app->path;
                }

                email_comp_p->attch_fs_hd = FS_Open(attch_path, FS_READ_ONLY);
                if (email_comp_p->comp_type == EMAIL_COMP_BY_ID)
                {
                    email_comp_mfree(attch_path);
                }

                if (EMAIL_STOR_FS_HANDLE_INVALID(email_comp_p->attch_fs_hd))
                {
                    srv_email_errno_set(email_comp_p->attch_fs_hd);
                    res = SRV_EMAIL_RESULT_FS_ERROR;
                    goto COMP_EXIT_HANDLE;
                }

                email_comp_p->op = EMAIL_COMP_OP_ATTCH_BODY_WRITE;

                break;

            case EMAIL_COMP_OP_ATTCH_BODY_WRITE:
                res = email_comp_message_encode_and_copy(email_comp_p, email_comp_p->attch_fs_hd, EMAIL_MIME_ENCBASE64, MMI_TRUE);
                if (res == SRV_EMAIL_RESULT_SUCC)
                {
                    FS_Close(email_comp_p->attch_fs_hd);
                    email_comp_p->attch_fs_hd = FS_INVALID_HANDLE;
                    email_comp_p->op = EMAIL_COMP_OP_ATTCH_BODY_BOUNDARY;
                }
                else //if (res == SRV_EMAIL_RESULT_WOULDBLOCK)
                {
                    return res;
                }

                break;

            case EMAIL_COMP_OP_ATTCH_BODY_BOUNDARY:
                if (email_comp_p->comp_type == EMAIL_COMP_BY_ID)
                {
                    if ((res = srv_email_stor_msg_get_attch_next(email_comp_p->attch_hd, email_comp_p->attch_stor)) == SRV_EMAIL_RESULT_NO_MORE_RESULT)
                    {
                        srv_email_stor_msg_get_attch_close(email_comp_p->attch_hd);
                        email_comp_p->attch_hd = EMAIL_STOR_INVALID_HANDLE;
                        email_comp_mfree(email_comp_p->attch_stor);
                        email_comp_p->attch_stor = NULL;
                        email_comp_mfree(email_comp_p->attch);
                        email_comp_p->attch = NULL;
                        email_comp_p->op = EMAIL_COMP_OP_WRITE_END_BDRY;
                        return SRV_EMAIL_RESULT_SUCC;
                    }
                    if (res != SRV_EMAIL_RESULT_SUCC)
                    {
                        srv_email_stor_msg_get_attch_close(email_comp_p->attch_hd);
                        email_comp_p->attch_hd = EMAIL_STOR_INVALID_HANDLE;
                        email_comp_mfree(email_comp_p->attch_stor);
                        email_comp_p->attch_stor = NULL;
                        email_comp_mfree(email_comp_p->attch);
                        email_comp_p->attch = NULL;
                        return res;
                    }
                    email_comp_p->attch->attch_id = email_comp_p->attch_stor->attch_id;
                    email_comp_p->attch_stor->file_name[EMAIL_STOR_ENCOD_FILE_NAME_LEN] = 0;
                    email_comp_p->attch_stor->content_type[EMAIL_STOR_CONT_TYPE_STR_LEN] = 0;
                    strcpy(email_comp_p->attch->file_name, email_comp_p->attch_stor->file_name);
                    strcpy(email_comp_p->attch->mime, email_comp_p->attch_stor->content_type);
                }
                else if (email_comp_p->comp_type == EMAIL_COMP_BY_HD)
                {
                    U32 num = 1;
                    U32 file_name_len = 0;
                    U16 outLen = 0;
                    U8 *converted_data = NULL;

                    if (email_comp_p->attch_handled_cnt >= email_comp_p->msg_header->attch_num)
                    {
                        email_comp_mfree(email_comp_p->attch_app);
                        email_comp_p->attch_app = NULL;
                        email_comp_mfree(email_comp_p->attch);
                        email_comp_p->attch = NULL;
                        email_comp_p->op = EMAIL_COMP_OP_WRITE_END_BDRY;
                        return SRV_EMAIL_RESULT_SUCC;
                    }
                    res = srv_email_msg_get_attachment_info(email_comp_p->msg_handle, email_comp_p->attch_handled_cnt, (S32*) & num, email_comp_p->attch_app);
                    if (res != SRV_EMAIL_RESULT_SUCC || num < 1)
                    {
                        email_comp_mfree(email_comp_p->attch_app);
                        email_comp_p->attch_app = NULL;
                        email_comp_mfree(email_comp_p->attch);
                        email_comp_p->attch = NULL;
                        return SRV_EMAIL_RESULT_FAIL;
                    }
                    ++(email_comp_p->attch_handled_cnt);

                    file_name_len += sprintf(email_comp_p->attch->file_name, "=?%s?B?", chset_get_preferred_mime_name(MMI_CHSET_UTF8));
                    converted_data = srv_email_util_ucs2_to_chset((U8*)email_comp_p->attch_app->name, MMI_CHSET_UTF8, &outLen);
                    strncpy(email_comp_p->attch->file_name + file_name_len, (char *)converted_data,
                           EMAIL_STOR_ENCOD_FILE_NAME_LEN - 1 - file_name_len - strlen("?="));
                    strcat(email_comp_p->attch->file_name, "%s?=");
                    OslMfree(converted_data);

                    strcpy(email_comp_p->attch->mime, srv_email_util_get_mime_type_str((chset_enum)(email_comp_p->attch_app->mime_type)));
                }
                email_comp_p->op = EMAIL_COMP_OP_WRITE_ATTCH_HEADER_TO_BUFF;
                break;

            default:
                MMI_ASSERT(0);  /* shall not come to here */
                break;
        }                       /* switch */
    }

    //return SRV_EMAIL_RESULT_SUCC;

COMP_EXIT_HANDLE:
    srv_email_stor_msg_get_attch_close(email_comp_p->attch_hd);
    email_comp_p->attch_hd = EMAIL_STOR_INVALID_HANDLE;
    email_comp_mfree(email_comp_p->attch);
    email_comp_p->attch = NULL;
    if (email_comp_p->comp_type == EMAIL_COMP_BY_ID)
    {
        email_comp_mfree(email_comp_p->attch_stor);
        email_comp_p->attch_stor = NULL;
    }
    else
    {
        email_comp_mfree(email_comp_p->attch_app);
        email_comp_p->attch_app = NULL;
    }
    return res;
}   /* end of smtp_write_attachment */


/*****************************************************************************
 * FUNCTION
 *  srv_email_util_ucs2_to_chset
 * DESCRIPTION
 *
 * PARAMETERS
 *  data        [?]         [?]
 *  chset       [IN]
 *  outLen      [?]         [?]
 * RETURNS
 *
 *****************************************************************************/
U8 *srv_email_util_ucs2_to_chset(U8 *data, S32 chset, U16 *outLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *convertedData = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *outLen = 0;
    convertedData = OslMalloc(EMAIL_CHSET_BUFF_LEN);
    *outLen = (U16) mmi_chset_convert(
                        MMI_CHSET_UCS2,
                        (mmi_chset_enum) chset,
                        (char*)data,
                        (char*)convertedData,
                        EMAIL_CHSET_BUFF_LEN);
    return convertedData;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_util_ucs2_to_chset_ex
 * DESCRIPTION
 *
 * PARAMETERS
 *  data        [?]         [?]
 *  chset       [IN]
 *  outLen      [?]         [?]
 *  pos         [?]         [?]
 * RETURNS
 *
 *****************************************************************************/
U8 *srv_email_util_ucs2_to_chset_ex(U8 *data, S32 chset, U16 *outLen, U32 *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *convertedData = NULL;
    U32 temp_pos = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *outLen = 0;
    convertedData = OslMalloc(EMAIL_CHSET_BUFF_LEN);
    *outLen = (U16) mmi_chset_convert_ex(
                        MMI_CHSET_UCS2,
                        (mmi_chset_enum) chset,
                        (char*)data,
                        (char*)convertedData,
                        EMAIL_CHSET_BUFF_LEN,
                        &temp_pos);
    *pos = temp_pos - (U32) data;
    return convertedData;
}

WCHAR *srv_email_get_file_ext(WCHAR *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 length = 0;
    WCHAR *file_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = mmi_wcslen(file_name);
    if (length) /* in case empty filename */
    {
        --length;

        if (file_name[0] == L'.')
        {
            return file_name;
        }

        while (length)
        {
            if (file_name[length] == L'.')
            {
                break;
            }
            else
            {
                length -= 1;
            }
        }

        if (length) /* in case no file extension */
        {
            file_ptr = file_name + length;
        }
    }

    return file_ptr;
}

void srv_email_util_get_mine_type(WCHAR *filename, S32 *mime_type, S32 *mime_subtype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *fileExtPtr = srv_email_get_file_ext(filename);
    CHAR *fileExt = OslMalloc((SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1) * ENCODING_LENGTH);
    S32 extLen = 0;
    applib_mime_type_struct *mimeTypePtr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(fileExt, 0, (SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1) * ENCODING_LENGTH);
    if (fileExtPtr)
    {
        /* neglect "." */
        fileExtPtr = fileExtPtr + 1;
        extLen = (((SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1) > (mmi_wcslen(fileExtPtr))) ? (mmi_wcslen(fileExtPtr)) : (SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1));
        mmi_ucs2_n_to_asc(fileExt, (CHAR*)fileExtPtr, (U32)(extLen * ENCODING_LENGTH));
    }
    if (strlen(fileExt))
    {
        mimeTypePtr = applib_mime_type_look_up(NULL, fileExt, MIME_TYPE_NONE, MIME_SUBTYPE_NONE);
    }
    if (mimeTypePtr != NULL)
    {
        *mime_type = mimeTypePtr->mime_type;
        *mime_subtype = mimeTypePtr->mime_subtype;
    }
    else
    {
        *mime_type = MIME_TYPE_UNKNOWN;
        *mime_subtype = MIME_SUBTYPE_UNRECOGNIZED;
    }
    OslMfree(fileExt);
}

