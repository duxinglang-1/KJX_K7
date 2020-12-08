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
 *  EmailSrvStorFS.c
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

#include "EmailSrvGprot.h"
#include "EmailSrvProt.h"
#include "EmailSrvStorage.h"
#include "EmailSrvStorFS.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "fs_gprot.h"
#include "mmi_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "kal_public_api.h"
#include "app_datetime.h"
#include "customer_ps_inc.h"
#include "stdlib.h"
#include "FileMgrSrvGProt.h"
#include "mmi_cb_mgr_gprot.h"

#ifdef EMAIL_STOR_FILE
#undef EMAIL_STOR_FILE
#endif
#define EMAIL_STOR_FILE 'S'


const CHAR *EMAIL_STOR_SYS_DIR = "s";

const CHAR *EMAIL_ACCT_INFO_FILE_ORIG = "a.o";
const CHAR *EMAIL_ACCT_INFO_FILE_BAK = "a.b";

const CHAR *EMAIL_STOR_MSG_CNTX = "m.cnt";   /* MSG cntx*/

const CHAR *EMAIL_INDEX_FILE_FLDR = "i";
const CHAR *EMAIL_FLDR_SUFFIX_INDEX = ".ind";
const CHAR *EMAIL_FLDR_SUFFIX_BACKUP = ".bak";

const CHAR *EMAIL_PARTS_FLDR = "p";
const CHAR *EMAIL_PARTS_SUFFIX_SAA = ".saa";
const CHAR *EMAIL_PARTS_SUFFIX_TXT = ".txt";
const CHAR *EMAIL_PARTS_SUFFIX_HTML = ".htm";

const CHAR *EMAIL_ATTCH_FLDR = "a";
const CHAR *EMAIL_ATTCH_SUFFIX_ATTCH = ".att";

const CHAR *EMAIL_STOR_RESTOR_FILE = "r.i";

const WCHAR *EMAIL_STOR_TMP_SUFFIX = L"tmp";

const WCHAR *EMAIL_STOR_MSG_UPDATE_TMP_FILE_SUFFIX = L".tmp";

#if (EMAIL_STOR_MAX_MSG_NUM_PER_FLDR > 100)
    #define EMAIL_STOR_FS_INIT_HD_OFST_ONCE     (50)
#else
    #define EMAIL_STOR_FS_INIT_HD_OFST_ONCE     (20)
#endif

email_stor_cntx_struct email_stor_cntx = {0};
email_stor_cntx_struct *email_stor_p = &email_stor_cntx;

/* for FS_Open debug */
typedef struct
{
    U8 in_use;
    CHAR called_file;
    U8 file_md5[SRV_EMAIL_MD5_DIGEST_LEN];
    S32 called_line;    
    FS_HANDLE hd;
} email_stor_fs_open_dbg_struct;

#define EMAIL_STOR_FS_OPEN_INSTANCE_MAX (10)
static email_stor_fs_open_dbg_struct email_stor_fs_open_dbg[EMAIL_STOR_FS_OPEN_INSTANCE_MAX] = {0};


static srv_email_result_enum email_stor_fs_init_acct_dir_check(srv_email_stor_res_funcptr_type callback, void *user_data);
static void email_stor_fs_init_acct_check_run(void *user_data);
static void email_stor_fs_init_run(void *_user_data);
static void email_stor_fs_state_set(srv_email_result_enum res);
static srv_email_result_enum email_stor_fs_init_fldr_restore(EMAIL_ACCT_ID acct_id, EMAIL_FLDR_ID fldr_id);     /* Do restore. */
static srv_email_result_enum email_stor_fs_init_fldr_check(EMAIL_ACCT_ID acct_id, EMAIL_FLDR_ID fldr_id, srv_email_fldr_type_enum fldr_type);   /* Check Restore */

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_seek
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd          [IN]        
 *  offset      [IN]        
 *  whence      [IN]        
 *  line        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 email_stor_fs_seek(FS_HANDLE hd, S32 offset, S32 whence, CHAR file, U32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = FS_Seek(hd, offset, whence);

    if (ret < FS_NO_ERROR)
    {
        // ASSERT(0);
        EMAIL_STOR_TRACE_FS_SEEK(file, line, ret);
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd          [IN]        
 *  offset      [IN]        
 *  whence      [IN]        
 *  line        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
FS_HANDLE email_stor_fs_open(const WCHAR* file, S32 flag, CHAR file_flag, U32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hd = FS_Open(file, flag);
    if (hd >= FS_NO_ERROR)
    {
        S32 i;
        for (i = 0; i < EMAIL_STOR_FS_OPEN_INSTANCE_MAX; i++)
        {
            if (email_stor_fs_open_dbg[i].in_use == 0)
            {
                email_stor_fs_open_dbg[i].in_use = 1;
                srv_email_compute_md5((CHAR*)file, mmi_wcslen(file) * 2, (U8*)email_stor_fs_open_dbg[i].file_md5);
                email_stor_fs_open_dbg[i].called_file = file_flag;
                email_stor_fs_open_dbg[i].called_line = line;
                email_stor_fs_open_dbg[i].hd = hd;
                break;
            }
        }
    }
    else
    {
        if (hd == FS_ACCESS_DENIED)
        {            
            S32 i;
            U8 md5[SRV_EMAIL_MD5_DIGEST_LEN];
            srv_email_compute_md5((CHAR*)file, mmi_wcslen(file) * 2, (U8*)md5);

            for (i = 0; i < EMAIL_STOR_FS_OPEN_INSTANCE_MAX; i++)
            {
                if (email_stor_fs_open_dbg[i].in_use == 0)
                {
                    continue;
                }
                
                if (memcmp(md5, email_stor_fs_open_dbg[i].file_md5, SRV_EMAIL_MD5_DIGEST_LEN) == 0)
                {
                    EMAIL_STOR_TRACE_FS_ACS_DND(email_stor_fs_open_dbg[i].called_file, email_stor_fs_open_dbg[i].called_line, file);
                }
            }
        }
    }
    return hd;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd          [IN]        
 *  offset      [IN]        
 *  whence      [IN]        
 *  line        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void email_stor_fs_close(FS_HANDLE hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hd >= FS_NO_ERROR)
    {
        S32 i;
        for (i = 0; i < EMAIL_STOR_FS_OPEN_INSTANCE_MAX; i++)
        {
            if (email_stor_fs_open_dbg[i].hd == hd)
            {
                email_stor_fs_open_dbg[i].in_use = 0;
                break;
            }
        }
    }
    FS_Close(hd);
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_cntx_info_gen_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void email_stor_fs_cntx_info_gen_path(WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(path, "%s%s\\%s", srv_email_get_root_path(), EMAIL_STOR_SYS_DIR, EMAIL_STOR_MSG_CNTX);
}

static void email_stor_fs_index_dir_gen_path(WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(path, "%s%s\\%s", srv_email_get_root_path(), EMAIL_STOR_SYS_DIR, EMAIL_INDEX_FILE_FLDR);
}

static U32 email_stor_fs_get_rand_num(void)
{
    U32 ticks;
    const U8 offset = 4;
    const U8 offset_opposite = 32 - 4;
    
    kal_get_time(&ticks);
    ticks <<= offset;
    ticks >>= offset;
    ticks *= ((app_getcurrtime() << offset_opposite) >> offset_opposite);
    return ticks;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_cntx_file_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [?]     [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum email_stor_fs_cntx_file_reset(const WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    FS_HANDLE hd;
    U32 read_write;
    email_stor_fs_cntx_file_struct cntx_file = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE | FS_CREATE_ALWAYS)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    cntx_file.checksum = 0;
    cntx_file.attch_index_next_avlid = EMAIL_STOR_ATTCH_VALID_ID_MIN;
    cntx_file.remote_fldr_id_next_avlid = EMAIL_STOR_FLDR_REMOTE_ID_MIN;
    cntx_file.msg_verno = EMAIL_STOR_MSG_VERNO;
    email_stor_p->attch_index_next_avlid = EMAIL_STOR_ATTCH_VALID_ID_MIN;
    email_stor_p->remote_fldr_id_next_avlid = EMAIL_STOR_FLDR_REMOTE_ID_MIN;

    ret = FS_Write(hd, &cntx_file, sizeof(email_stor_fs_cntx_file_struct), &read_write);
    if (ret != FS_NO_ERROR || read_write != sizeof(email_stor_fs_cntx_file_struct))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, read_write);
        EMAIL_FS_CLOSE(hd);
        FS_Delete(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    /* update checksum */
    ret = srv_email_checksum_write_by_hd(hd, 0, srv_email_checksum_compute_by_hd(hd, sizeof(EMAIL_CHECKSUM)));
    if (ret != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_FS_CLOSE(hd);
        FS_Delete(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    EMAIL_FS_CLOSE(hd);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_cntx_info_write
 * DESCRIPTION
 *  
 * PARAMETERS
 *  attch_index_next_avlid          [IN]        
 *  remote_fldr_id_next_avlid       [IN]        
 *  attch_id_next_avlid(?)          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum email_stor_fs_cntx_info_write(U32 attch_index_next_avlid, EMAIL_FLDR_ID remote_fldr_id_next_avlid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    WCHAR *path;
    FS_HANDLE hd;
    U32 read_write;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_cntx_info_gen_path(path);

    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    if (attch_index_next_avlid != EMAIL_ATTCH_INVALID_ID)
    {
        EMAIL_FS_SEEK(
            hd,
            EMAIL_STOR_POS_IN_STRUCT(email_stor_fs_cntx_file_struct, attch_index_next_avlid),
            FS_FILE_BEGIN);
        ret = FS_Write(hd, &attch_index_next_avlid, sizeof(U32), &read_write);
        if (ret != FS_NO_ERROR || read_write != sizeof(U32))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, read_write);
            EMAIL_FS_CLOSE(hd);
            FS_Delete(path);
            email_stor_path_mfree(path);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
    }

    if (remote_fldr_id_next_avlid != EMAIL_FLDR_INVALID_ID)
    {
        EMAIL_FS_SEEK(
            hd,
            EMAIL_STOR_POS_IN_STRUCT(email_stor_fs_cntx_file_struct, remote_fldr_id_next_avlid),
            FS_FILE_BEGIN);
        ret = FS_Write(hd, &remote_fldr_id_next_avlid, sizeof(EMAIL_FLDR_ID), &read_write);
        if (ret != FS_NO_ERROR || read_write != sizeof(EMAIL_FLDR_ID))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, read_write);
            EMAIL_FS_CLOSE(hd);
            FS_Delete(path);
            email_stor_path_mfree(path);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
    }

    srv_email_checksum_write_by_hd(hd, 0, srv_email_checksum_compute_by_hd(hd, sizeof(EMAIL_CHECKSUM)));

    email_stor_path_mfree(path);
    EMAIL_FS_CLOSE(hd);

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_init_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static srv_email_result_enum email_stor_fs_init_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    S32 dir_exist;
    FS_HANDLE hd;
    U32 read_write;
    WCHAR *path;
    WCHAR *path_tmp;
    srv_email_result_enum res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    if ((path_tmp = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        email_stor_path_mfree(path_tmp);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_cntx_info_gen_path(path);

    /* if MSG CNTX file exist */
    if (!EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE)))
    {
        EMAIL_CHECKSUM checksum;
        email_stor_fs_cntx_file_struct cntx_file = {0};

        ret = FS_Read(hd, &cntx_file, sizeof(email_stor_fs_cntx_file_struct), &read_write);
        if (ret != FS_NO_ERROR || read_write != sizeof(email_stor_fs_cntx_file_struct))
        {
            EMAIL_STOR_TRACE_FS_READ(ret, read_write);
            EMAIL_STOR_TRACE_INIT_CNTX(ret);
            checksum = 0;
            cntx_file.checksum = 1;
        }
        else
        {
            checksum = srv_email_checksum_compute_by_hd(hd, sizeof(EMAIL_CHECKSUM));
        }
        EMAIL_FS_CLOSE(hd);

        if (checksum == cntx_file.checksum &&
            cntx_file.msg_verno == EMAIL_STOR_MSG_VERNO)
        {
            /* storage version is latest */
            email_stor_p->attch_index_next_avlid = cntx_file.attch_index_next_avlid;
            email_stor_p->remote_fldr_id_next_avlid = cntx_file.remote_fldr_id_next_avlid;

            email_stor_path_mfree(path);
            email_stor_path_mfree(path_tmp);
            return SRV_EMAIL_RESULT_SUCC;
        }
    }

    
    email_stor_p->is_storage_reset = MMI_TRUE;
    
    /* else MSG cntx file NOT exist, or checksum NOT match, or MSG version NOT match */
    if ((res = email_stor_fs_cntx_file_reset(path)) != SRV_EMAIL_RESULT_SUCC)
    {
        email_stor_path_mfree(path);
        email_stor_path_mfree(path_tmp);
        EMAIL_STOR_TRACE_INIT_CNTX(res);
        return res;
    }
    
    email_stor_fs_index_dir_gen_path(path);
    dir_exist = srv_email_util_dir_exist(path);
    if (dir_exist < 0)
    {
        email_stor_path_mfree(path);
        email_stor_path_mfree(path_tmp);
        EMAIL_STOR_TRACE_FS_CREATE_DIR(dir_exist);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    if (dir_exist)
    {
        U32 rand_num = email_stor_fs_get_rand_num();
        kal_wsprintf(path_tmp, "%s%s\\%s%u", srv_email_get_root_path(), EMAIL_STOR_SYS_DIR, EMAIL_INDEX_FILE_FLDR, rand_num);
        ret = FS_Rename(path, path_tmp);
        if (ret != FS_NO_ERROR)
        {
            email_stor_path_mfree(path);
            email_stor_path_mfree(path_tmp);
            EMAIL_STOR_TRACE_FS_RENAME(ret);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        EMAIL_STOR_TRACE_INIT_CNTX(0);
        srv_email_fs_xdelete(path_tmp, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    }
    
    email_stor_path_mfree(path);
    email_stor_path_mfree(path_tmp);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_init_acct_info_check
 * DESCRIPTION
 *  Read account info from account info file, and sync the account array "email_stor_p->acct_id"
 * PARAMETERS
 *  void
 * RETURNS
 *  result code
 *****************************************************************************/
static srv_email_result_enum email_stor_fs_init_acct_info_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_ACCT_ID i;
    EMAIL_ACCT_ID j;
    FS_HANDLE orig_hd;
    FS_HANDLE bak_hd;
    WCHAR *orig_path;
    WCHAR *bak_path;
    U32 read_write;
    S32 ret;
    EMAIL_CHECKSUM orig_storage_checksum = 0;
    EMAIL_CHECKSUM orig_calculate_checksum = 1;
    EMAIL_CHECKSUM bak_storage_checksum = 2;
    EMAIL_CHECKSUM bak_calculate_checksum = 3;
    EMAIL_ACCT_VERNO orig_acct_verno = 65535;
    EMAIL_ACCT_VERNO bak_acct_verno = 65534;
    srv_email_result_enum result;
    srv_email_acct_info_struct *acct_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((orig_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    if ((bak_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        email_stor_path_mfree(bak_path);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    if ((acct_info = email_stor_malloc(sizeof(srv_email_acct_info_struct))) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(srv_email_acct_info_struct));
        email_stor_path_mfree(orig_path);
        email_stor_path_mfree(bak_path);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    /* ORIGINAL file */
    email_stor_fs_acct_info_gen_path(orig_path, EMAIL_STOR_FS_ACCT_INFO_ORIG);
    if (!EMAIL_STOR_FS_HANDLE_INVALID(orig_hd = EMAIL_FS_OPEN(orig_path, FS_READ_ONLY)))
    {
        EMAIL_FS_SEEK(orig_hd, EMAIL_STOR_ACCT_INFO_CHECKSUM_POS, FS_FILE_BEGIN);
        ret = FS_Read(orig_hd, &orig_storage_checksum, sizeof(EMAIL_CHECKSUM), &read_write);
        if (ret != FS_NO_ERROR || read_write != sizeof(EMAIL_CHECKSUM))
        {
            EMAIL_STOR_TRACE_FS_READ(ret, read_write);
		}

        EMAIL_FS_SEEK(orig_hd, EMAIL_STOR_ACCT_INFO_VERNO_POS, FS_FILE_BEGIN);
        ret = FS_Read(orig_hd, &orig_acct_verno, sizeof(EMAIL_ACCT_VERNO), &read_write);
        if (ret != FS_NO_ERROR || read_write != sizeof(EMAIL_ACCT_VERNO))
        {
            EMAIL_STOR_TRACE_FS_READ(ret, read_write);
		}

        orig_calculate_checksum = srv_email_checksum_compute_by_hd(
            orig_hd, EMAIL_STOR_ACCT_INFO_CHECKSUM_POS + sizeof(EMAIL_CHECKSUM));
        EMAIL_FS_CLOSE(orig_hd);
    }

    /* BACKUP file */
    email_stor_fs_acct_info_gen_path(bak_path, EMAIL_STOR_FS_ACCT_INFO_BAK);
    if (!EMAIL_STOR_FS_HANDLE_INVALID(bak_hd = EMAIL_FS_OPEN(bak_path, FS_READ_ONLY)))
    {
        EMAIL_FS_SEEK(bak_hd, EMAIL_STOR_ACCT_INFO_CHECKSUM_POS, FS_FILE_BEGIN);
        ret = FS_Read(bak_hd, &bak_storage_checksum, sizeof(EMAIL_CHECKSUM), &read_write);
        if (ret != FS_NO_ERROR || read_write != sizeof(EMAIL_CHECKSUM))
        {
            EMAIL_STOR_TRACE_FS_READ(ret, read_write);
		}

        EMAIL_FS_SEEK(bak_hd, EMAIL_STOR_ACCT_INFO_VERNO_POS, FS_FILE_BEGIN);
        ret = FS_Read(bak_hd, &bak_acct_verno, sizeof(EMAIL_ACCT_VERNO), &read_write);
        if (ret != FS_NO_ERROR || read_write != sizeof(EMAIL_ACCT_VERNO))
        {
            EMAIL_STOR_TRACE_FS_READ(ret, read_write);
		}

        bak_calculate_checksum = srv_email_checksum_compute_by_hd(
            bak_hd, EMAIL_STOR_ACCT_INFO_CHECKSUM_POS + sizeof(EMAIL_CHECKSUM));
        EMAIL_FS_CLOSE(bak_hd);
    }

    if (orig_calculate_checksum == orig_storage_checksum &&
        orig_acct_verno == EMAIL_STOR_ACCT_VERNO)
    {
        if (bak_calculate_checksum != bak_storage_checksum ||
            orig_storage_checksum != bak_storage_checksum)
        {
            /* use original acct.info to replace backup acct.info */
            ret = FS_Move(orig_path, bak_path, FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0);
            if (ret != FS_NO_ERROR)
            {
                goto STOR_EXIT_HANDLE;
            }
        }
    }
    else if (bak_calculate_checksum == bak_storage_checksum &&
             bak_acct_verno == EMAIL_STOR_ACCT_VERNO)
    {
        /* use backup acct.info to replace original acct.info */
        ret = FS_Move(bak_path, orig_path, FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0);        
        if (ret != FS_NO_ERROR)
        {
            goto STOR_EXIT_HANDLE;
        }
    }
    else /* Create them!!! account info file NOT exist, or checksums do NOT match */
    {
        email_stor_p->is_storage_reset = MMI_TRUE;
        
        for (i = EMAIL_STOR_ACCT_VALID_ID_MIN; i <= EMAIL_STOR_ACCT_VALID_ID_MAX; i++)
        {
            /*
              No need to do it here: email_stor_fs_acct_unread_set_directly(i, 0);
              Account unread number will be updated in each account checking
            */
            email_stor_fs_acct_id_mem_global_set(i, EMAIL_STOR_ACCT_ID_UNUSED);
            email_stor_fs_acct_info_cache_set(i, MMI_FALSE, SRV_EMAIL_PROT_NONE, L"", L"");
            email_stor_p->acct_id_sort[i - EMAIL_STOR_ACCT_VALID_ID_MIN] = EMAIL_ACCT_INVALID_ID;
        }

        email_stor_mfree(acct_info);
        
        result = email_stor_fs_acct_info_file_create(orig_path, bak_path);
        
        email_stor_path_mfree(orig_path);
        email_stor_path_mfree(bak_path);

        return result;
    }

    if (EMAIL_STOR_FS_HANDLE_INVALID(orig_hd = EMAIL_FS_OPEN(orig_path, FS_READ_ONLY)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(orig_hd);
        goto STOR_EXIT_HANDLE;
    }

    EMAIL_FS_SEEK(orig_hd, EMAIL_STOR_ACCT_INFO_ACCT_ID_ORDER_POS, FS_FILE_BEGIN);
    ret = FS_Read(orig_hd, &email_stor_p->acct_id_sort, sizeof(EMAIL_ACCT_ID) * EMAIL_STOR_ACCT_NUM_MAX, &read_write);
    if (ret != FS_NO_ERROR || read_write != sizeof(EMAIL_ACCT_ID) * EMAIL_STOR_ACCT_NUM_MAX)
    {
        EMAIL_STOR_TRACE_FS_READ(ret, read_write);
        EMAIL_FS_CLOSE(orig_hd);
        goto STOR_EXIT_HANDLE;
    }
        
    EMAIL_FS_SEEK(orig_hd, EMAIL_STOR_ACCT_INFO_FIRST_INFO_POS, FS_FILE_BEGIN);
    for (i = EMAIL_STOR_ACCT_VALID_ID_MIN; i <= EMAIL_STOR_ACCT_VALID_ID_MAX; i++)
    {
        ret = FS_Read(orig_hd, acct_info, sizeof(srv_email_acct_info_struct), &read_write);
        if (ret != FS_NO_ERROR || read_write != sizeof(srv_email_acct_info_struct))
        {
            EMAIL_STOR_TRACE_FS_READ(ret, read_write); 
            EMAIL_FS_CLOSE(orig_hd);
            goto STOR_EXIT_HANDLE;
        }

        for (j = 0; j < EMAIL_STOR_ACCT_NUM_MAX; j++)
        {
            if (email_stor_p->acct_id_sort[j] == i)
            {
                email_stor_fs_acct_id_mem_global_set(i, EMAIL_STOR_ACCT_ID_USED);
                email_stor_fs_acct_info_cache_set(
                    acct_info->acct_id, 
                    acct_info->is_cloud_acct,
                    acct_info->protocol, 
                    acct_info->acct_name,
                    acct_info->email_addr.email_addr);
                break;
            }
        }
        
        if (j == EMAIL_STOR_ACCT_NUM_MAX)
        {
            email_stor_fs_acct_id_mem_global_set(i, EMAIL_STOR_ACCT_ID_UNUSED);
        }        
    }

    EMAIL_FS_CLOSE(orig_hd);

    email_stor_path_mfree(orig_path);
    email_stor_path_mfree(bak_path);
    email_stor_mfree(acct_info);

    return SRV_EMAIL_RESULT_SUCC;

STOR_EXIT_HANDLE:
    email_stor_path_mfree(orig_path);
    email_stor_path_mfree(bak_path);
    email_stor_mfree(acct_info);
    return SRV_EMAIL_RESULT_FS_ERROR;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_init_acct_dir_check
 * DESCRIPTION
 *  Sync account directory
 * PARAMETERS
 *  callback        [IN]        
 *  user_data       [?]         [?]         [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_init_acct_dir_check(srv_email_stor_res_funcptr_type callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_acct_dir_sync_struct *acct_check_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((acct_check_cntx = email_stor_malloc(sizeof(email_stor_fs_acct_dir_sync_struct))) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(email_stor_fs_acct_dir_sync_struct));
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    acct_check_cntx->res = SRV_EMAIL_RESULT_SUCC;
    acct_check_cntx->path[0] = 0;
    acct_check_cntx->curr_acct_id = EMAIL_STOR_ACCT_VALID_ID_MIN;
    acct_check_cntx->callback = callback;
    acct_check_cntx->user_data = user_data;
    memset(&acct_check_cntx->acct_to_xdel[0], 0, sizeof(EMAIL_ACCT_ID) * MMI_EMAIL_MAX_ACCTS);
    srv_email_schdl_start_job(email_stor_fs_init_acct_check_run, acct_check_cntx);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_init_acct_check_run
 * DESCRIPTION
 *  Account directory sync call back
 * PARAMETERS
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_init_acct_check_run(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dir_exist;
    EMAIL_STOR_HANDLE hd;
    EMAIL_FLDR_ID fldr_id;
    srv_email_result_enum res;
    srv_email_fldr_type_enum fldr_type;
    email_stor_fs_acct_dir_sync_struct *acct_check_cntx = (email_stor_fs_acct_dir_sync_struct*) user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* to find next valid account id */
    if (acct_check_cntx->curr_acct_id <= EMAIL_STOR_ACCT_VALID_ID_MAX &&
           email_stor_fs_acct_id_mem_global_get(acct_check_cntx->curr_acct_id) == EMAIL_STOR_ACCT_ID_UNUSED)
    {
        EMAIL_STOR_TRACE_INIT_ACCT(acct_check_cntx->curr_acct_id);
        
        email_stor_fs_acct_unread_set_directly(acct_check_cntx->curr_acct_id, 0);

        email_stor_fs_acct_gen_path(acct_check_cntx->curr_acct_id, (WCHAR*)&acct_check_cntx->path);
        dir_exist = srv_email_util_dir_exist((WCHAR*) & acct_check_cntx->path);
        if (dir_exist < 0)
        {
            EMAIL_STOR_TRACE_FS_CREATE_DIR(dir_exist);
            res = SRV_EMAIL_RESULT_FS_ERROR;
            goto STOR_EXIT_HANDLE;
        }
        if (dir_exist)
        {
            /* ASYNC delete files(NO DIR) in this DIR,  */
            acct_check_cntx->acct_to_xdel[acct_check_cntx->curr_acct_id - EMAIL_STOR_ACCT_VALID_ID_MIN] = acct_check_cntx->curr_acct_id;
        }
        else
        {
            FS_CreateDir((WCHAR*)&acct_check_cntx->path);
        }

        /* XDelete tmp acct dir */
        mmi_wcscat((WCHAR*)&acct_check_cntx->path, EMAIL_STOR_TMP_SUFFIX);
        dir_exist = srv_email_util_dir_exist((WCHAR*) & acct_check_cntx->path);
        if (dir_exist < 0)
        {
            EMAIL_STOR_TRACE_FS_CREATE_DIR(dir_exist);;
            res = SRV_EMAIL_RESULT_FS_ERROR;
            goto STOR_EXIT_HANDLE;
        }
        if (dir_exist)
        {
            srv_email_fs_xdelete((WCHAR*)&acct_check_cntx->path, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
        }
        acct_check_cntx->curr_acct_id++;
        srv_email_schdl_start_job(email_stor_fs_init_acct_check_run, acct_check_cntx);
        return;
    }

    if (acct_check_cntx->curr_acct_id > EMAIL_STOR_ACCT_VALID_ID_MAX)   /* Done, should return */
    {
        kal_wsprintf((WCHAR*)&acct_check_cntx->path, "%s%s\\%s\\", srv_email_get_root_path(), EMAIL_STOR_SYS_DIR, EMAIL_INDEX_FILE_FLDR);
        srv_email_fs_xdelete_acct((WCHAR*)&acct_check_cntx->path, (const EMAIL_ACCT_ID *)&acct_check_cntx->acct_to_xdel, FS_FILE_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
        res = acct_check_cntx->res;
        EMAIL_STOR_TRACE_INIT_ACCT_CHK(res);
        goto STOR_EXIT_HANDLE;
    }

    /* to check INDEX & BACKUP */
    email_stor_fs_acct_gen_path(acct_check_cntx->curr_acct_id, (WCHAR*) & acct_check_cntx->path);

    EMAIL_STOR_TRACE_INIT_ACCT(acct_check_cntx->curr_acct_id);

    dir_exist = srv_email_util_dir_exist((WCHAR*) & acct_check_cntx->path);
    if (dir_exist < 0)
    {
        EMAIL_STOR_TRACE_FS_CREATE_DIR(dir_exist);;
        res = SRV_EMAIL_RESULT_FS_ERROR;
        goto STOR_EXIT_HANDLE;
    }

    if (!dir_exist)
    {
        S32 ret;

        if ((ret = FS_CreateDir((WCHAR*) & acct_check_cntx->path)) != FS_NO_ERROR)
        {
            EMAIL_STOR_TRACE_FS_CREATE_DIR(ret);
            res = SRV_EMAIL_RESULT_FS_ERROR;
            goto STOR_EXIT_HANDLE;
        }
    }

    for (fldr_type = SRV_EMAIL_FLDR_TYPE_BASICS_BGN; fldr_type <= SRV_EMAIL_FLDR_TYPE_BASICS_END; fldr_type++)
    {
        EMAIL_FLDR_ID fldr_id = email_stor_fs_fldr_gen_basic_id(acct_check_cntx->curr_acct_id, fldr_type);

        EMAIL_STOR_TRACE_INIT_ACCT_FLDR(acct_check_cntx->curr_acct_id, fldr_id);

        res = email_stor_fs_init_fldr_check(acct_check_cntx->curr_acct_id, fldr_id, fldr_type);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            goto STOR_EXIT_HANDLE;
        }
        EMAIL_STOR_TRACE_INIT_ACCT_FLDR(acct_check_cntx->curr_acct_id, fldr_id);
    }

    if (email_stor_fs_acct_get_fldr_id_open(acct_check_cntx->curr_acct_id, SRV_EMAIL_FLDR_TYPE_REMOTE, &hd)
        == SRV_EMAIL_RESULT_SUCC)
    {
        while (email_stor_fs_acct_get_fldr_id_next(hd, &fldr_id) != SRV_EMAIL_RESULT_NO_MORE_RESULT)
        {
            res = email_stor_fs_init_fldr_check(acct_check_cntx->curr_acct_id, fldr_id, SRV_EMAIL_FLDR_TYPE_REMOTE);
            if (res != SRV_EMAIL_RESULT_SUCC)
            {
                email_stor_fs_acct_get_fldr_id_close(hd);
                goto STOR_EXIT_HANDLE;
            }
            EMAIL_STOR_TRACE_INIT_ACCT_FLDR(acct_check_cntx->curr_acct_id, fldr_id);
        }
        email_stor_fs_acct_get_fldr_id_close(hd);
        EMAIL_STOR_TRACE_INIT_ACCT(acct_check_cntx->curr_acct_id);
    }

    acct_check_cntx->curr_acct_id++;
    srv_email_schdl_start_job(email_stor_fs_init_acct_check_run, acct_check_cntx);
    return;
    
STOR_EXIT_HANDLE:
    {
        void *_user_data = acct_check_cntx->user_data;
        srv_email_stor_res_funcptr_type callback = acct_check_cntx->callback;

        email_stor_mfree(acct_check_cntx);
        EMAIL_STOR_TRACE_INIT_ACCT_CHK(res);
        if (callback != NULL)
        {
            (callback) (res, _user_data);
        }
        return;
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_init_acct_check_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res             [IN]        
 *  user_data       [?]         [?]         [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void email_stor_fs_init_acct_check_callback(srv_email_result_enum res, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (res != SRV_EMAIL_RESULT_SUCC)
    {
        email_stor_fs_init_struct *stor_init_cntx = (email_stor_fs_init_struct*) user_data;
        void *_user_data = stor_init_cntx->user_data;
        srv_email_stor_res_funcptr_type callback = stor_init_cntx->callback;

        email_stor_fs_state_set(res);
        callback(res, _user_data);
    }
    else
    {
        srv_email_schdl_start_job(email_stor_fs_init_run, user_data);
    }
}

// TODO: restore_flag_get not used now!!!


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_init_fldr_restore_flag_get
 * DESCRIPTION
 *  Get restore flag info
 * PARAMETERS
 *  restor_flag     [IN/OUT]        Restore flag
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_init_fldr_restore_flag_get(email_stor_backup_restore_flag_struct *restor_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    FS_HANDLE hd;
    U32 read_write;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    kal_wsprintf(path, "%s%s\\%s", srv_email_get_root_path(), EMAIL_STOR_SYS_DIR, EMAIL_STOR_RESTOR_FILE);

    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        restor_flag->acct_id = EMAIL_ACCT_INVALID_ID;
        restor_flag->fldr_id = EMAIL_FLDR_INVALID_ID;
        restor_flag->type = EMAIL_STOR_RESTORE_DONE;
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_SUCC;
    }
    email_stor_path_mfree(path);

    EMAIL_STOR_TRACE_RESTORE_START();
    ret = FS_Read(hd, restor_flag, sizeof(email_stor_backup_restore_flag_struct), &read_write);
    if (ret != FS_NO_ERROR || read_write != sizeof(email_stor_backup_restore_flag_struct))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, read_write);
        
    }

    EMAIL_FS_CLOSE(hd);
    if (read_write != sizeof(email_stor_backup_restore_flag_struct))
    {
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_init_fldr_restore_flag_set
 * DESCRIPTION
 *  Set restore flag info
 * PARAMETERS
 *  restor_flag     [IN]        Restore flag
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_init_fldr_restore_flag_set(email_stor_backup_restore_flag_struct *restor_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    FS_HANDLE hd;
    U32 read_write;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    kal_wsprintf(path, "%s%s\\%s", srv_email_get_root_path(), EMAIL_STOR_SYS_DIR, EMAIL_STOR_RESTOR_FILE);

    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE | FS_CREATE_ALWAYS)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        email_stor_path_mfree(path);
        // TODO:
    }
    email_stor_path_mfree(path);

    ret = FS_Write(hd, restor_flag, sizeof(email_stor_backup_restore_flag_struct), &read_write);
    if (ret != FS_NO_ERROR || read_write != sizeof(email_stor_backup_restore_flag_struct))
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, read_write);
        
    }
    EMAIL_FS_CLOSE(hd);
    if (read_write != sizeof(email_stor_backup_restore_flag_struct))
    {
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    return SRV_EMAIL_RESULT_SUCC;
}

/* Do restore. */


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_init_fldr_restore
 * DESCRIPTION
 *  Do restore
 * PARAMETERS
 *  acct_id     [IN]        Account id
 *  fldr_id     [IN]        Folder id
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_init_fldr_restore(EMAIL_ACCT_ID acct_id, EMAIL_FLDR_ID fldr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    WCHAR *path;
    WCHAR *path_backup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if (email_stor_fs_init_fldr_restore_flag_set(&restore_flag) != SRV_EMAIL_RESULT_SUCC){} */ // TODO: set restore flag

    /* copy backup file to replace index file */
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    if ((path_backup = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_fldr_gen_path(acct_id, fldr_id, EMAIL_STOR_FLDR_INDEX, path);
    email_stor_fs_fldr_gen_path(acct_id, fldr_id, EMAIL_STOR_FLDR_BACKUP, path_backup);

    ret = FS_Move(path_backup, path, FS_MOVE_OVERWRITE | FS_MOVE_COPY, NULL, NULL, 0);
        email_stor_path_mfree(path);
        email_stor_path_mfree(path_backup);
    
    if (ret != FS_NO_ERROR)
    {
        EMAIL_STOR_TRACE_FS_COPY(ret);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    
    return SRV_EMAIL_RESULT_SUCC;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_init_fldr_restore
 * DESCRIPTION
 *  Check Restore
 * PARAMETERS
 *  acct_id               [IN]        Account id
 *  fldr_id               [IN]        Folder id
 *  index_backup          [IN]
 *  invalid_offset_found  [OUT]
 *  unread_num            [OUT]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_init_fldr_index_check(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        email_stor_fldr_file_type index_backup,
                        MMI_BOOL *invalid_offset_found,
                        U32 *unread_num)
{
    WCHAR *path;
    FS_HANDLE hd;
    U32 i, k, curr_read_size, pos_end, ret, read_write, file_ofst_cnt;
    email_stor_fs_msg_struct *msg_arr;

    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    email_stor_fs_fldr_gen_path(acct_id, fldr_id, index_backup, path);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    email_stor_path_mfree(path);

    EMAIL_FS_SEEK(hd, EMAIL_STOR_FLDR_TOTAL_NUM_POS, FS_FILE_BEGIN);
    ret = FS_Read(hd, &(email_stor_p->inbox_index_size), sizeof(U32), &read_write);
    if(ret != FS_NO_ERROR || read_write != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, read_write);
        EMAIL_FS_CLOSE(hd);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    email_stor_fs_inbox_index_read(hd);

    *invalid_offset_found = MMI_FALSE;
    *unread_num = 0;

    /* get file size */
    EMAIL_FS_SEEK(hd, 0, FS_FILE_END);
    FS_GetFilePosition(hd, &pos_end);

    if (pos_end < EMAIL_STOR_MSG_RECORD_POS(0))
    {
        goto STOR_EXIT;
    }

    file_ofst_cnt = (pos_end - EMAIL_STOR_MSG_RECORD_POS(0)) / sizeof(email_stor_fs_msg_struct);
    if (file_ofst_cnt == 0)
    {
        goto STOR_EXIT;
    }

    /* filter the invalid offset */
    EMAIL_FS_SEEK(hd, EMAIL_STOR_MSG_RECORD_POS(0), FS_FILE_BEGIN);
    msg_arr = email_stor_malloc(EMAIL_STOR_FS_INIT_HD_OFST_ONCE * sizeof(email_stor_fs_msg_struct));

    for (i = 0; i < file_ofst_cnt; i += EMAIL_STOR_FS_INIT_HD_OFST_ONCE)
    {
        curr_read_size = (file_ofst_cnt - i >= EMAIL_STOR_FS_INIT_HD_OFST_ONCE) ? EMAIL_STOR_FS_INIT_HD_OFST_ONCE : file_ofst_cnt - i;
        ret = FS_Read(hd, msg_arr, curr_read_size * sizeof(email_stor_fs_msg_struct), &read_write);
        if(ret != FS_NO_ERROR || read_write != curr_read_size*sizeof(email_stor_fs_msg_struct))
        {
            continue;
        }

        for (k = 0; k < curr_read_size; ++k)
        {
            if ((msg_arr+k)->valid)
            {
                if (((msg_arr+k)->state & SRV_EMAIL_MSG_STATE_DEL_SERVER) == SRV_EMAIL_MSG_STATE_DEL_SERVER)
                {
                    if (email_stor_fs_inbox_index_del(i + k) == SRV_EMAIL_RESULT_SUCC)
                    {
                        *invalid_offset_found = MMI_TRUE;
                    }
                }
                else if(((msg_arr+k)->flag_latest & EMAIL_MSG_FLAG_SEEN) != EMAIL_MSG_FLAG_SEEN)
                {
                    ++(*unread_num);
                }
            }
            else
            {
                if (email_stor_fs_inbox_index_del(i + k) == SRV_EMAIL_RESULT_SUCC)
                {
                    *invalid_offset_found = MMI_TRUE;
                }
            }
        }
    }

    if (*invalid_offset_found)
    {
        EMAIL_CHECKSUM checksum;
        EMAIL_FS_SEEK(hd, EMAIL_STOR_FLDR_TOTAL_NUM_POS, FS_FILE_BEGIN);
        ret = FS_Write(hd, &(email_stor_p->inbox_index_size), sizeof(U32), &read_write);
        if(ret != FS_NO_ERROR || read_write != sizeof(U32))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, read_write);
        }
        email_stor_fs_inbox_index_write(hd);

        checksum = srv_email_checksum_compute_by_hd(hd, sizeof(EMAIL_CHECKSUM));
        srv_email_checksum_write_by_hd(hd, 0, checksum);
    }
    email_stor_mfree(msg_arr);

STOR_EXIT:
    EMAIL_FS_CLOSE(hd);
    return SRV_EMAIL_RESULT_SUCC;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_init_fldr_check
 * DESCRIPTION
 *  Restore check
 * PARAMETERS
 *  acct_id         [IN]        Account id
 *  fldr_id         [IN]        Folder id
 *  fldr_type       [IN]        Folder type (INBOX/OUTBOX/...)
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_init_fldr_check(
                        EMAIL_ACCT_ID acct_id,
                        EMAIL_FLDR_ID fldr_id,
                        srv_email_fldr_type_enum fldr_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    EMAIL_CHECKSUM index_storage_checksum    = 0;
    EMAIL_CHECKSUM index_calculate_checksum  = 1;
    EMAIL_CHECKSUM backup_storage_checksum   = 2;
    EMAIL_CHECKSUM backup_calculate_checksum = 3;
    U32 index_unread_num = 0;
    U32 backup_unread_num = 0;
    srv_email_result_enum res = SRV_EMAIL_RESULT_SUCC;
    S32 ret;
    WCHAR *path;
    WCHAR *new_path;
    FS_HANDLE hd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    email_stor_fs_fldr_gen_path(acct_id, fldr_id, EMAIL_STOR_FLDR_INDEX, path);
    if (email_stor_fs_fldr_type_is_basic(fldr_type))
    {
        if (!srv_email_util_file_exist(path))   /* if index file do NOT exist */
        {
            res = email_stor_fs_fldr_create_simple(acct_id, fldr_id, fldr_type);
            if (fldr_type == SRV_EMAIL_FLDR_TYPE_INBOX)
            {
                email_stor_fs_acct_unread_set_directly(acct_id, 0);
            }
            goto STOR_EXIT_HANDLE;
        }
    }

    /* read INDEX checksum */
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
    }
    else
    {
        if ((res = srv_email_checksum_read_by_hd(hd, 0, &index_storage_checksum)) == SRV_EMAIL_RESULT_SUCC)
        {
            /* calculate INDEX checksum */
            index_calculate_checksum = srv_email_checksum_compute_by_hd(hd, sizeof(EMAIL_CHECKSUM));
        }
        else
        {
            index_storage_checksum = 0;
            index_calculate_checksum = 1;
        }
        EMAIL_FS_CLOSE(hd);
    }

    /* read BACKUP checksum */
    email_stor_fs_fldr_gen_path(acct_id, fldr_id, EMAIL_STOR_FLDR_BACKUP, path);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
    }
    else
    {
        if ((res = srv_email_checksum_read_by_hd(hd, 0, &backup_storage_checksum)) == SRV_EMAIL_RESULT_SUCC)
        {
            /* calculate INDEX checksum */
            backup_calculate_checksum = srv_email_checksum_compute_by_hd(hd, sizeof(EMAIL_CHECKSUM));
        }
        else
        {
            backup_storage_checksum = 0;
            backup_calculate_checksum = 1;
        }
        EMAIL_FS_CLOSE(hd);
    }

    if (index_storage_checksum == index_calculate_checksum)
    {
        MMI_BOOL invalid_offset_found = MMI_FALSE;
        res = email_stor_fs_init_fldr_index_check(
                acct_id, fldr_id, EMAIL_STOR_FLDR_INDEX, 
                &invalid_offset_found, &index_unread_num);
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            EMAIL_STOR_TRACE_MALLOC(res);
            goto STOR_EXIT_HANDLE;
        }

        if (fldr_type == SRV_EMAIL_FLDR_TYPE_INBOX)
        {
            email_stor_fs_acct_unread_set_directly(acct_id, index_unread_num);
        }
        
        if (!invalid_offset_found && 
            backup_storage_checksum == backup_calculate_checksum)
        {
            if (index_storage_checksum == backup_storage_checksum)
            {
                res = SRV_EMAIL_RESULT_SUCC;   /* everything is OK */
                goto STOR_EXIT_HANDLE;
            }
        }

        email_stor_p->acct_reset = acct_id;
        email_stor_p->fldr_reset = fldr_id;

        /* else copy index file to replace backup file */
        if ((new_path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
        {
            EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
            res = SRV_EMAIL_RESULT_NO_MEMORY;
            goto STOR_EXIT_HANDLE;
        }
        email_stor_fs_fldr_gen_path(acct_id, fldr_id, EMAIL_STOR_FLDR_INDEX, new_path);
        if ((ret = FS_Move(new_path, path, FS_MOVE_OVERWRITE | FS_MOVE_COPY, NULL, NULL, 0)) != FS_NO_ERROR)
        {
            EMAIL_STOR_TRACE_FS_COPY(ret);
            email_stor_path_mfree(new_path);
            res = SRV_EMAIL_RESULT_FS_ERROR;
            goto STOR_EXIT_HANDLE;
        }
        email_stor_path_mfree(new_path);
    }
    else
    {
        email_stor_p->acct_reset = acct_id;
        email_stor_p->fldr_reset = fldr_id;

        if (backup_storage_checksum == backup_calculate_checksum)       /* backup file is valid */
        {
            MMI_BOOL invalid_offset_found = MMI_FALSE;
            res = email_stor_fs_init_fldr_index_check(
                    acct_id, fldr_id, EMAIL_STOR_FLDR_BACKUP, 
                    &invalid_offset_found, &backup_unread_num);
            if (res != SRV_EMAIL_RESULT_SUCC)
            {
                EMAIL_STOR_TRACE_MALLOC(res);
                goto STOR_EXIT_HANDLE;
            }
            if (fldr_type == SRV_EMAIL_FLDR_TYPE_INBOX)
            {
                email_stor_fs_acct_unread_set_directly(acct_id, backup_unread_num);
            }
            res = email_stor_fs_init_fldr_restore(acct_id, fldr_id);
        }
        else
        {
            if (fldr_type == SRV_EMAIL_FLDR_TYPE_INBOX)
            {
                email_stor_fs_acct_unread_set_directly(acct_id, 0);
            }
            res =  email_stor_fs_fldr_create_simple(acct_id, fldr_id, fldr_type);
        }
    }

STOR_EXIT_HANDLE:
    email_stor_path_mfree(path);
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_init_sys_dir_check
 * DESCRIPTION
 *  Check system directory
 * PARAMETERS
 *  root_dir        [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
static srv_email_result_enum email_stor_fs_init_sys_dir_check(MMI_BOOL root_dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *path;
    S32 ret;
    S32 dir_exist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    /* storage's root dir */
    if (root_dir)
    {
        kal_wsprintf(path, "%s%s", srv_email_get_root_path(), EMAIL_STOR_SYS_DIR);
        dir_exist = srv_email_util_dir_exist(path);
        if (dir_exist < 0)
        {
            EMAIL_STOR_TRACE_FS_CREATE_DIR(dir_exist);
            email_stor_path_mfree(path);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        if (!dir_exist)
        {
            if ((ret = FS_CreateDir(path)) != FS_NO_ERROR)
            {
                EMAIL_STOR_TRACE_FS_CREATE_DIR(ret);
                email_stor_path_mfree(path);
                return SRV_EMAIL_RESULT_FS_ERROR;
            }
        }
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_SUCC;
    }

    /* index */
    email_stor_fs_index_dir_gen_path(path);
    dir_exist = srv_email_util_dir_exist(path);
    if (dir_exist < 0)
    {
        EMAIL_STOR_TRACE_FS_CREATE_DIR(dir_exist);
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    if (!dir_exist)
    {
        if ((ret = FS_CreateDir(path)) != FS_NO_ERROR)
        {
            EMAIL_STOR_TRACE_FS_CREATE_DIR(ret);
            email_stor_path_mfree(path);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
    }

    email_stor_path_mfree(path);
    return SRV_EMAIL_RESULT_SUCC;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_drive_plug_proc
 * DESCRIPTION
 *  Handle drive plug event
 * PARAMETERS
 *  event          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret email_stor_fs_drive_plug_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
            srv_fmgr_notification_dev_plug_event_struct *plugInfo =
                (srv_fmgr_notification_dev_plug_event_struct*)event;


            for (i = 0; i < plugInfo->count; ++i)
            {
                if (plugInfo->drv_letters[i] == srv_email_get_drive())
                {
                    EMAIL_ACCT_ID acct = EMAIL_STOR_ACCT_VALID_ID_MIN;
                    email_stor_p->stor_state = SRV_EMAIL_STOR_STATE_FS_ERROR;
                    for (; acct < EMAIL_STOR_ACCT_VALID_ID_MAX; ++acct)
                    {
                        email_stor_fs_acct_unread_set_directly(acct, 0);
                    }
                    email_stor_fs_acct_cache_notify_msg_unread_chg(
                        SRV_EMAIL_ALL_MSG_UNREAD_SOME_TO_NONE, 0);
                }
            }
        }
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_init
 * DESCRIPTION
 *  Initialize FS system
 * PARAMETERS
 *  callback        [IN]        
 *  user_data       [?]         [?]         [?]
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_init(srv_email_stor_res_funcptr_type callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_init_struct *stor_init_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAIL_STOR_TRACE_INIT_START();

    /*mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,
            email_stor_fs_drive_plug_proc, NULL);*/
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
            email_stor_fs_drive_plug_proc, NULL);

    email_stor_p->stor_state = SRV_EMAIL_STOR_STATE_INITING;
    email_stor_p->is_storage_reset = MMI_FALSE;
    email_stor_p->acct_reset = EMAIL_ACCT_INVALID_ID;
    email_stor_p->fldr_reset = EMAIL_FLDR_INVALID_ID;
    memset(&email_stor_p->acct, 0, sizeof(email_stor_p->acct));

    if ((stor_init_cntx = email_stor_malloc(sizeof(email_stor_fs_init_struct))) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(sizeof(email_stor_fs_init_struct));
        EMAIL_STOR_TRACE_INIT(SRV_EMAIL_RESULT_NO_MEMORY);
        email_stor_fs_state_set(SRV_EMAIL_RESULT_NO_MEMORY);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }

    memset(stor_init_cntx, 0, sizeof(email_stor_fs_init_struct));
    stor_init_cntx->callback = callback;
    stor_init_cntx->user_data = user_data;

    srv_email_schdl_start_job(email_stor_fs_init_run, stor_init_cntx);

    return SRV_EMAIL_RESULT_WOULDBLOCK;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_init_run
 * DESCRIPTION
 *  
 * PARAMETERS
 *  _user_data      [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_init_run(void *_user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum res = SRV_EMAIL_RESULT_SUCC;
    email_stor_fs_init_struct *stor_init_cntx = (email_stor_fs_init_struct*) _user_data;
    void *user_data = stor_init_cntx->user_data;
    srv_email_stor_res_funcptr_type callback = stor_init_cntx->callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check system root directory */
    if (!stor_init_cntx->check_root_dir)
    {
        if ((res = email_stor_fs_init_sys_dir_check(MMI_TRUE)) != SRV_EMAIL_RESULT_SUCC)
        {
            email_stor_fs_state_set(res);
            EMAIL_STOR_TRACE_INIT(res);
            goto STOR_EXIT_HANDLE;
        }
        else
        {
            stor_init_cntx->check_root_dir = MMI_TRUE;
        }
        EMAIL_STOR_TRACE_INIT_START();
        /* NO return; */
    }

    /* check storage cntx file */
    if (!stor_init_cntx->check_cntx_file)
    {
        if ((res = email_stor_fs_init_cntx()) != SRV_EMAIL_RESULT_SUCC)
        {
            email_stor_fs_state_set(res);
            EMAIL_STOR_TRACE_INIT(res);
            goto STOR_EXIT_HANDLE;
        }
        else
        {
            stor_init_cntx->check_cntx_file = MMI_TRUE;
            srv_email_schdl_start_job(email_stor_fs_init_run, stor_init_cntx);
        }
        EMAIL_STOR_TRACE_INIT_START();
        return;
    }

    /* check acct info file */
    if (!stor_init_cntx->check_acct_info)
    {
        if ((res = email_stor_fs_init_acct_info_check()) != SRV_EMAIL_RESULT_SUCC)
        {
            email_stor_fs_state_set(res);
            EMAIL_STOR_TRACE_INIT(res);
            goto STOR_EXIT_HANDLE;
        }
        else
        {
            stor_init_cntx->check_acct_info = MMI_TRUE;
            srv_email_schdl_start_job(email_stor_fs_init_run, stor_init_cntx);
        }
        EMAIL_STOR_TRACE_INIT_START();
        return;
    }

    /* check INDEX directory */
    if (!stor_init_cntx->check_other_dir)
    {
        if ((res = email_stor_fs_init_sys_dir_check(MMI_FALSE)) != SRV_EMAIL_RESULT_SUCC)
        {
            email_stor_fs_state_set(res);
            EMAIL_STOR_TRACE_INIT(res);
            goto STOR_EXIT_HANDLE;
        }
        else
        {
            stor_init_cntx->check_other_dir = MMI_TRUE;
            /* srv_email_schdl_start_job(email_stor_fs_init_run, stor_init_cntx); */
        }
        EMAIL_STOR_TRACE_INIT_START();
        /* return; */
    }

    /* sync acct dir */
    if (!stor_init_cntx->sync_acct)
    {
        if ((res = email_stor_fs_init_acct_dir_check(
                    email_stor_fs_init_acct_check_callback,
                    stor_init_cntx)) != SRV_EMAIL_RESULT_WOULDBLOCK)
        {
            email_stor_fs_state_set(res);
            EMAIL_STOR_TRACE_INIT(res);
            goto STOR_EXIT_HANDLE;
        }
        else
        {
            stor_init_cntx->sync_acct = MMI_TRUE;
            /* NO need to call schdl_start_job here! */
        }
        EMAIL_STOR_TRACE_INIT_START();
        return; /* MUST return */
    }

    email_stor_p->stor_state = SRV_EMAIL_STOR_STATE_AVAILABLE;

    EMAIL_STOR_TRACE_INIT_DONE();

    if (email_stor_fs_acct_info_cache_cnt_msg_unread())
    {
        email_stor_fs_acct_cache_notify_msg_unread_chg(
            SRV_EMAIL_ALL_MSG_UNREAD_NONE_TO_SOME,
            email_stor_fs_acct_info_cache_cnt_msg_unread());
    }

STOR_EXIT_HANDLE:
    email_stor_mfree(stor_init_cntx);
    if (callback != NULL)
    {
        callback(res, user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_state_available
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL email_stor_fs_state_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (email_stor_p->stor_state == SRV_EMAIL_STOR_STATE_AVAILABLE ? MMI_TRUE : MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_state_get
 * DESCRIPTION
 *  Query whether storage initialization complete.
 * PARAMETERS
 *  void
 * RETURNS
 *  storage state
 *****************************************************************************/
srv_email_stor_state_enum email_stor_fs_state_get(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return email_stor_p->stor_state;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_state_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_state_set(srv_email_result_enum res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (res)
    {
        case SRV_EMAIL_RESULT_NO_MEMORY:
            email_stor_p->stor_state = SRV_EMAIL_STOR_STATE_NO_MEMORY;
            break;
        case SRV_EMAIL_RESULT_FS_ERROR:
            email_stor_p->stor_state = SRV_EMAIL_STOR_STATE_FS_ERROR;
            break;
        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_offset_link_add
 * DESCRIPTION
 *  Add a msg_offset_note to linked list
 * PARAMETERS
 *  header      [IN]        Header pointer
 *  offset      [IN]        Offset
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_msg_offset_link_add(email_stor_fs_msg_offset_link_struct **header, EMAIL_STOR_OFFSET offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    email_stor_fs_msg_offset_link_struct *tail;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*header == NULL)
    {
        if ((*header = email_stor_malloc(sizeof(email_stor_fs_msg_offset_link_struct))) == NULL)
        {
            EMAIL_STOR_TRACE_MALLOC(sizeof(email_stor_fs_msg_offset_link_struct));
            return; /* SRV_EMAIL_RESULT_NO_MEMORY; */
        }
        (*header)->next = NULL;
        (*header)->offset = offset;
    }
    else
    {
        tail = *header;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }

        if ((tail->next = email_stor_malloc(sizeof(email_stor_fs_msg_offset_link_struct))) == NULL)
        {
            EMAIL_STOR_TRACE_MALLOC(sizeof(email_stor_fs_msg_offset_link_struct));
            return; /* SRV_EMAIL_RESULT_NO_MEMORY; */
        }
        tail = tail->next;
        tail->next = NULL;
        tail->offset = offset;
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_del_remove_record
 * DESCRIPTION
 *  remove MSG record(s) whose id included in linked list
 * PARAMETERS
 *  hd              [IN]        FS handle
 *  header          [IN]        Header
 *  is_inbox        [IN]        
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_del_remove_record(
                        FS_HANDLE hd,
                        email_stor_fs_msg_offset_link_struct *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 read_write;
    MMI_BOOL valid = MMI_FALSE;
    U32 pos_end = 0;
    U32 pos_new;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ret = FS_GetFileSize(hd, &pos_end)) < FS_NO_ERROR)
    {
        EMAIL_STOR_TRACE_FS_OPEN(ret);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    while (header != NULL)
    {
        pos_new = EMAIL_STOR_MSG_RECORD_POS(header->offset);
        if (pos_new < pos_end)
        {
            EMAIL_FS_SEEK(hd, pos_new, FS_FILE_BEGIN);
        ret = FS_Write(hd, &valid, sizeof(MMI_BOOL), &read_write);
        if (ret != FS_NO_ERROR || read_write != sizeof(MMI_BOOL))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, read_write);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        }
        header = header->next;
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_msg_num_update
 * DESCRIPTION
 *  update MSG number
 * PARAMETERS
 *  hd              [IN]        Handle
 *  orig_num        [?]         [?]         [?]         [?]     original number
 *  add             [IN]        Increment
 *  type            [IN]        MSG number update type
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_msg_num_update(
                        FS_HANDLE hd,
                        U32 *orig_num,
                        S32 add,
                        email_stor_fs_msg_num_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 read_write;
    U32 new_num;
    U32 offset = 0;
    U32 old_num;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (add == 0 && orig_num == NULL)   /* no need to update FS */
    {
        return SRV_EMAIL_RESULT_SUCC;
    }

    if (type == EMAIL_STOR_MSG_UNREAD_NUM)
    {
        offset = sizeof(EMAIL_CHECKSUM) + sizeof(U32);
    }
    else if (type == EMAIL_STOR_MSG_TOTAL_NUM)
    {
        offset = sizeof(EMAIL_CHECKSUM);
    }
    else
    {
        MMI_ASSERT(0);
    }

    EMAIL_FS_SEEK(hd, offset, FS_FILE_BEGIN);
    ret = FS_Read(hd, &old_num, sizeof(U32), &read_write);
    if (ret != FS_NO_ERROR || read_write != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, read_write);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    if (add != 0)
    {
        EMAIL_FS_SEEK(hd, offset, FS_FILE_BEGIN);
        new_num = old_num + add;
        EMAIL_STOR_TRACE_MSG_NUM_CHANGE(type, old_num, add, (S32)old_num + add);
        MMI_ASSERT((S32)old_num + add >= 0);
        MMI_ASSERT((S32)old_num + add <= EMAIL_STOR_MAX_MSG_NUM_PER_FLDR);
        ret = FS_Write(hd, &new_num, sizeof(U32), &read_write);
        if (ret != FS_NO_ERROR || read_write != sizeof(U32))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, read_write);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
    }

    if (orig_num != NULL)
    {
        *orig_num = old_num;
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_errno_detail_set
 * DESCRIPTION
 *  Set FS detail error
 * PARAMETERS
 *  hd      [IN]        FS handle
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_errno_detail_set(S32 _errno)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_email_get_srv_init_state() <= SRV_EMAIL_INIT_STATE_READY)   /* srv init done */
    {
        email_stor_p->_errno = _errno;
        srv_email_errno_set(_errno);
    }
    else
    {
        srv_email_init_errno_set(_errno);
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_errno_detail_get
 * DESCRIPTION
 *  To get a detail error number
 * PARAMETERS
 *  res     [IN]        Result number
 * RETURNS
 *  result code
 *****************************************************************************/
S32 email_stor_fs_errno_detail_get(srv_email_result_enum res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (res == SRV_EMAIL_RESULT_FS_ERROR)
    {
        return email_stor_p->_errno;
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_inbox_index_read
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_inbox_index_read(FS_HANDLE hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 read_write;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAIL_FS_SEEK(hd, EMAIL_STOR_INBOX_INDEX_POS, FS_FILE_BEGIN);
    if (email_stor_p->inbox_index_size > EMAIL_STOR_MAX_MSG_NUM_PER_FLDR)
    {
        EMAIL_STOR_TRACE_FS_READ(0 - EMAIL_STOR_MAX_MSG_NUM_PER_FLDR, email_stor_p->inbox_index_size);
        email_stor_p->inbox_index_size = EMAIL_STOR_MAX_MSG_NUM_PER_FLDR;
        // should error..
    }
    ret = FS_Read(
            hd,
            email_stor_p->inbox_index,
            sizeof(email_stor_fs_inbox_index_struct) * email_stor_p->inbox_index_size,
            &read_write);
    if (ret != FS_NO_ERROR || read_write != sizeof(email_stor_fs_inbox_index_struct) * email_stor_p->inbox_index_size)
    {
        EMAIL_STOR_TRACE_FS_READ(ret, read_write);
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_inbox_index_write
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hd      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_email_result_enum email_stor_fs_inbox_index_write(FS_HANDLE hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 read_write;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(email_stor_p->inbox_index_size <= EMAIL_STOR_MAX_MSG_NUM_PER_FLDR);
    EMAIL_FS_SEEK(hd, EMAIL_STOR_INBOX_INDEX_POS, FS_FILE_BEGIN);
    ret = FS_Write(
            hd,
            email_stor_p->inbox_index,
            sizeof(email_stor_fs_inbox_index_struct) * email_stor_p->inbox_index_size,
            &read_write);
    if (ret != FS_NO_ERROR || read_write != sizeof(email_stor_fs_inbox_index_struct) * email_stor_p->inbox_index_size)
    {
        EMAIL_STOR_TRACE_FS_WRITE(ret, read_write);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_inbox_index_memset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_inbox_index_memset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(email_stor_p->inbox_index, 0, sizeof(email_stor_fs_inbox_index_struct) * EMAIL_STOR_MAX_MSG_NUM_PER_FLDR);
    email_stor_p->inbox_index_size = 0;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_inbox_index_sort_comp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  a       [IN]        
 *  b       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 email_stor_fs_inbox_index_sort_comp(const void *a, const void *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((email_stor_fs_inbox_index_struct*) b)->date - ((email_stor_fs_inbox_index_struct*) a)->date;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_inbox_index_sort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_inbox_index_sort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(email_stor_p->inbox_index_size <= EMAIL_STOR_MAX_MSG_NUM_PER_FLDR);
    qsort(
        (void*)&email_stor_p->inbox_index[0],
        email_stor_p->inbox_index_size,
        sizeof(email_stor_fs_inbox_index_struct),
        email_stor_fs_inbox_index_sort_comp);
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_inbox_index_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  note        [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_inbox_index_add(email_stor_fs_inbox_index_struct *note)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(email_stor_p->inbox_index_size <= EMAIL_STOR_MAX_MSG_NUM_PER_FLDR);
    memcpy(&email_stor_p->inbox_index[email_stor_p->inbox_index_size], note, sizeof(email_stor_fs_inbox_index_struct));
    email_stor_p->inbox_index_size++;
    email_stor_fs_inbox_index_sort();
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_inbox_index_find
 * DESCRIPTION
 *  
 * PARAMETERS
 *  offset      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static S32 email_stor_fs_inbox_index_find(U16 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(email_stor_p->inbox_index_size <= EMAIL_STOR_MAX_MSG_NUM_PER_FLDR);
    for (i = 0; i < (S32) email_stor_p->inbox_index_size; i++)
    {
        if (email_stor_p->inbox_index[i].offset == offset)
        {
            return i;
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_inbox_index_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  offset      [IN]        
 *  flag        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_inbox_index_update(U16 offset, EMAIL_MSG_FLAG flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = email_stor_fs_inbox_index_find(offset);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // MMI_ASSERT(i >= 0);    /* if not found */

    if (i >= 0)
    {
        email_stor_p->inbox_index[i].flag = flag;
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_inbox_index_del
 * DESCRIPTION
 *  
 * PARAMETERS
 *  offset      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_email_result_enum email_stor_fs_inbox_index_del(U16 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = email_stor_fs_inbox_index_find(offset);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_ASSERT(i >= 0);    /* if not found */
    if (i < 0)  // not found
    {
        EMAIL_STOR_TRACE_MSG_DEL_IND_ERR(offset);
        return SRV_EMAIL_RESULT_INVALID_MSG;
    }
    MMI_ASSERT(email_stor_p->inbox_index_size <= EMAIL_STOR_MAX_MSG_NUM_PER_FLDR);

    if (i >= 0)
    {
        if ((U32) i != email_stor_p->inbox_index_size - 1)  /* it's not the last note in array */
        {
            memmove(
                &email_stor_p->inbox_index[i],
                &email_stor_p->inbox_index[i + 1],
                sizeof(email_stor_fs_inbox_index_struct) * (email_stor_p->inbox_index_size - i - 1));
        }
        memset(
            &email_stor_p->inbox_index[email_stor_p->inbox_index_size - 1],
            0,
            sizeof(email_stor_fs_inbox_index_struct));
        email_stor_p->inbox_index_size--;
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_inbox_index_del_by_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  del_offset_list_header      [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_inbox_index_del_by_list(email_stor_fs_msg_offset_link_struct *del_offset_list_header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (del_offset_list_header != NULL)
    {
        email_stor_fs_inbox_index_del((U16) del_offset_list_header->offset);
        del_offset_list_header = del_offset_list_header->next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_inbox_index_update_by_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  set_flag_list_header        [?]     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void email_stor_fs_inbox_index_update_by_list(email_stor_fs_msg_flag_link_struct *set_flag_list_header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (set_flag_list_header != NULL)
    {
        email_stor_fs_inbox_index_update((U16) set_flag_list_header->offset, set_flag_list_header->new_flag);
        set_flag_list_header = set_flag_list_header->next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_inbox_get_recent_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  acct_id             [IN]        
 *  start_index         [IN]        
 *  count               [?]         [?]         [?]
 *  flag_mask           [IN]        
 *  matched_flag        [IN]        
 *  msg_array           [?]         [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum email_stor_fs_inbox_get_recent_list(
                        EMAIL_ACCT_ID acct_id,
                        S32 start_index,
                        U32 *count,
                        U8 flag_mask,
                        EMAIL_MSG_FLAG matched_flag,
                        srv_email_inbox_index_msg_struct *msg_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 i;
    U32 cnt;
    WCHAR *path;
    FS_HANDLE hd;
    U32 read_write;
    EMAIL_FLDR_ID fldr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*count == 0)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }
    fldr_id = email_stor_fs_fldr_gen_basic_id(acct_id, SRV_EMAIL_FLDR_TYPE_INBOX);
    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    email_stor_fs_fldr_gen_path(acct_id, fldr_id, EMAIL_STOR_FLDR_INDEX, path);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_ONLY)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    email_stor_path_mfree(path);

    EMAIL_FS_SEEK(hd, EMAIL_STOR_FLDR_TOTAL_NUM_POS, FS_FILE_BEGIN);
    ret = FS_Read(hd, &(email_stor_p->inbox_index_size), sizeof(U32), &read_write);
    if(ret != FS_NO_ERROR || read_write != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, read_write);
        EMAIL_FS_CLOSE(hd);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    email_stor_fs_inbox_index_read(hd);
    EMAIL_FS_CLOSE(hd);

    for (cnt = 0, i = 0; i < email_stor_p->inbox_index_size; i++)
    {
        if ((email_stor_p->inbox_index[i].flag & flag_mask) == matched_flag)
        {
            if (start_index > 0)
            {
                start_index--;
                continue;
            }
            (msg_array + cnt)->msg_id = email_stor_fs_msg_id_gen(acct_id, fldr_id, email_stor_p->inbox_index[i].offset);
            (msg_array + cnt)->date = email_stor_p->inbox_index[i].date;
            cnt++;
            if (cnt >= *count)
            {
                break;
            }
        }
    }
    *count = cnt;
    return SRV_EMAIL_RESULT_SUCC;
}

srv_email_result_enum email_stor_fs_get_all_msg_id(
    EMAIL_ACCT_ID acct_id, 
    EMAIL_FLDR_ID fldr_id, 
    U8 flag_mask, 
    EMAIL_MSG_FLAG matched_flag,
    U32 *count, 
    EMAIL_MSG_ID *msg_id)
{
    S32 ret;
    U32 i;
    U32 cnt;
    WCHAR *path;
    FS_HANDLE hd;
    U32 read_write;
    U32 pos_end = 0;
    MMI_BOOL invalid_offset_found = MMI_FALSE;
    email_stor_fs_msg_struct *temp_msg_info = NULL;
    EMAIL_CHECKSUM checksum = 0;

    if (*count == 0)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }

    if ((path = email_stor_path_malloc(EMAIL_STOR_WCS_SYS_PATH_LEN)) == NULL)
    {
        EMAIL_STOR_TRACE_MALLOC(EMAIL_STOR_WCS_SYS_PATH_LEN);
        return SRV_EMAIL_RESULT_NO_MEMORY;
    }
    email_stor_fs_fldr_gen_path(acct_id, fldr_id, EMAIL_STOR_FLDR_INDEX, path);
    if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE | FS_OPEN_SHARED)))
    {
        EMAIL_STOR_TRACE_FS_OPEN(hd);
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    EMAIL_FS_SEEK(hd, EMAIL_STOR_FLDR_TOTAL_NUM_POS, FS_FILE_BEGIN);
    ret = FS_Read(hd, &(email_stor_p->inbox_index_size), sizeof(U32), &read_write);
    if(ret != FS_NO_ERROR || read_write != sizeof(U32))
    {
        EMAIL_STOR_TRACE_FS_READ(ret, read_write);
        EMAIL_FS_CLOSE(hd);
        email_stor_path_mfree(path);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    email_stor_fs_inbox_index_read(hd);

    /* get file size */
    EMAIL_FS_SEEK(hd, 0, FS_FILE_END);
    FS_GetFilePosition(hd, &pos_end);

    /* filter the invalid offset */
    temp_msg_info = email_stor_malloc(sizeof(email_stor_fs_msg_struct));
    for (i = 0; i < email_stor_p->inbox_index_size;)
    {
        U32 seek_pos = EMAIL_STOR_MSG_RECORD_POS(email_stor_p->inbox_index[i].offset);
        if (seek_pos >= pos_end)
        {
            invalid_offset_found = MMI_TRUE;
            email_stor_fs_inbox_index_del(email_stor_p->inbox_index[i].offset);
            continue;
        }
        EMAIL_FS_SEEK(hd, seek_pos, FS_FILE_BEGIN);
        ret = FS_Read(hd, temp_msg_info, sizeof(email_stor_fs_msg_struct), &read_write);
        if(ret == FS_NO_ERROR)
        {
            if (read_write != sizeof(email_stor_fs_msg_struct) ||
                !temp_msg_info->valid ||
                (temp_msg_info->state & SRV_EMAIL_MSG_STATE_DEL_SERVER) == SRV_EMAIL_MSG_STATE_DEL_SERVER
               )
            {
                invalid_offset_found = MMI_TRUE;
                email_stor_fs_inbox_index_del(email_stor_p->inbox_index[i].offset);
                continue;
            }
        }
        i++;
    }
    email_stor_mfree(temp_msg_info);

    if (invalid_offset_found)
    {
        // update INDEX
        EMAIL_FS_SEEK(hd, EMAIL_STOR_FLDR_TOTAL_NUM_POS, FS_FILE_BEGIN);
        ret = FS_Write(hd, &(email_stor_p->inbox_index_size), sizeof(U32), &read_write);
        if(ret != FS_NO_ERROR || read_write != sizeof(U32))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, read_write);
        }
        email_stor_fs_inbox_index_write(hd);

        checksum = srv_email_checksum_compute_by_hd(hd, sizeof(EMAIL_CHECKSUM));
        srv_email_checksum_write_by_hd(hd, 0, checksum);
    }
    EMAIL_FS_CLOSE(hd);

    if (invalid_offset_found)
    {
        // update BACKUP
        email_stor_fs_fldr_gen_path(acct_id, fldr_id, EMAIL_STOR_FLDR_BACKUP, path);
        if (EMAIL_STOR_FS_HANDLE_INVALID(hd = EMAIL_FS_OPEN(path, FS_READ_WRITE)))
        {
            EMAIL_STOR_TRACE_FS_OPEN(hd);
            email_stor_path_mfree(path);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }

        EMAIL_FS_SEEK(hd, EMAIL_STOR_FLDR_TOTAL_NUM_POS, FS_FILE_BEGIN);
        ret = FS_Write(hd, &(email_stor_p->inbox_index_size), sizeof(U32), &read_write);
        if(ret != FS_NO_ERROR || read_write != sizeof(U32))
        {
            EMAIL_STOR_TRACE_FS_WRITE(ret, read_write);
        }
        email_stor_fs_inbox_index_write(hd);

        srv_email_checksum_write_by_hd(hd, 0, checksum);
        EMAIL_FS_CLOSE(hd);
    }
    email_stor_path_mfree(path);

    for (cnt = 0, i = 0; i < email_stor_p->inbox_index_size; i++)
    {
        if ((email_stor_p->inbox_index[i].flag & flag_mask) == 
            (matched_flag & flag_mask))
        {
            *(msg_id + cnt) = email_stor_fs_msg_id_gen(
                acct_id, fldr_id, email_stor_p->inbox_index[i].offset);
            ++cnt;
            if (cnt >= *count)
            {
                break;
            }
        }
    }
    *count = cnt;
    return SRV_EMAIL_RESULT_SUCC;
}

/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_util_dir_del
 * DESCRIPTION
 *  
 * PARAMETERS
 *  path        [IN]        Path
 *  del_all     [IN]        Mark whether delete files under this directory
 * RETURNS
 *  result code
 *****************************************************************************/
srv_email_result_enum email_stor_fs_util_dir_del(const WCHAR *path, MMI_BOOL del_all)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dir_exist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dir_exist = srv_email_util_dir_exist(path);
    if (dir_exist < 0)
    {
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    if (dir_exist > 0)
    {
        return SRV_EMAIL_RESULT_SUCC;
    }

    if (del_all)
    {
        if (FS_XDelete(path, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0) >= FS_NO_ERROR)
        {
            return SRV_EMAIL_RESULT_SUCC;
        }
    }
    else    /* just remove directory */
    {
        if (FS_RemoveDir(path) == FS_NO_ERROR)
        {
            return SRV_EMAIL_RESULT_SUCC;
        }
    }
    return SRV_EMAIL_RESULT_FS_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_util_wcs_to_u32
 * DESCRIPTION
 *  Convert a WCS string to U32
 * PARAMETERS
 *  w           [IN]        
 *  u           [OUT]       
 *  mode        [IN]        
 * RETURNS
 *  Whether this WCS can be converted to U32, return MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL email_stor_fs_util_wcs_to_u32(const WCHAR *w, U32 *u, U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(w != NULL);
    MMI_ASSERT(mode == 10); /* only desimalism supported */

    *u = 0;

    while (*w != 0)
    {
        if (*w > '9' || *w < '0')
        {
            return MMI_FALSE;
        }
        *u *= 10;
        *u += (*w - '0');
        w++;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_util_wcs_to_u64
 * DESCRIPTION
 *  Convert a WCS string to U64
 * PARAMETERS
 *  w           [IN]        
 *  u           [OUT]       
 *  mode        [IN]        
 * RETURNS
 *  Whether this WCS can be converted to U32, return MMI_TRUE or MMI_FALSE
 *****************************************************************************/
MMI_BOOL email_stor_fs_util_wcs_to_u64(const WCHAR *w, U64 *u, U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 add;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(w != NULL);
    MMI_ASSERT(mode == 16); /* only desimalism supported */

    *u = 0;

    while (*w != 0)
    {
        *u <<= 4;

        if (*w >= '0' && *w <= '9')
        {
            add = *w - '0';
        }
        else if (*w >= 'a' && *w <= 'z')
        {
            add = *w - 'a' + 10;
        }
        else if (*w >= 'A' && *w <= 'Z')
        {
            add = *w - 'A' + 10;
        }
        else
        {
            return MMI_FALSE;
        }
        *u += add;
        w++;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  email_stor_fs_util_ucs2_cmp_asc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wstr        [IN]        
 *  str         [IN]        
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 email_stor_fs_util_ucs2_cmp_asc(const WCHAR *wstr, const CHAR *str, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    WCHAR w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len; i++)
    {
        w = (WCHAR) (*(str + i));
        if (*(wstr + i) != w)
        {
            return (S32) (*(wstr + i) - w);
        }
    }
    return 0;
}


void *email_stor_path_malloc_dbg(U32 size, const CHAR* filename, U32 line)
{
    S32 i;

    for (i = 0; i < EMAIL_STOR_RESERVED_PATH_BUFFER; i++)
    {
        if (!email_stor_p->path_buffer[i].used_now)
        {
            email_stor_p->path_buffer[i].used_now = MMI_TRUE;
            email_stor_p->path_buffer[i].filename = filename;
            email_stor_p->path_buffer[i].line = line;
            return (void*)&email_stor_p->path_buffer[i].buffer;
        }
    }
    return srv_email_mem_alloc_dbg(size, (CHAR*)filename, line);
}

void email_stor_path_free_dbg(void *ptr)
{
    S32 i;

    for (i = 0; i < EMAIL_STOR_RESERVED_PATH_BUFFER; i++)
    {
        if ((void*)&email_stor_p->path_buffer[i].buffer == ptr)
        {
            MMI_ASSERT(email_stor_p->path_buffer[i].used_now == MMI_TRUE);
            email_stor_p->path_buffer[i].used_now = MMI_FALSE;
            return;
        }
    }
    email_stor_mfree(ptr);
}

EMAIL_CHECKSUM email_stor_acct_verno_compute(void)
{
    /*
        checksum    sizeof(EMAIL_CHECKSUM)
        verno       sizeof(EMAIL_ACCT_VERNO)
        default id  sizeof(EMAIL_ACCT_ID)
        id array    sizeof(EMAIL_ACCT_ID)              * EMAIL_STOR_ACCT_NUM_MAX
        acct array  sizeof(srv_email_acct_info_struct) * EMAIL_STOR_ACCT_NUM_MAX
    */
    const U32 acct_struct_buffer[] =
    {
        sizeof(EMAIL_CHECKSUM),
        sizeof(EMAIL_ACCT_VERNO),
        sizeof(EMAIL_ACCT_ID),
        EMAIL_STOR_ACCT_NUM_MAX,
        sizeof(srv_email_acct_info_struct),
        SRV_EMAIL_MD5_DIGEST_LEN,
        SRV_EMAIL_MAX_ACCT_NAME_LEN,
        sizeof(srv_email_addr_struct),
        SRV_EMAIL_MAX_DISP_NAME_LEN,
        SRV_EMAIL_MAX_ADDR_LEN,
        sizeof(srv_email_server_struct),
        SRV_EMAIL_MAX_SERVER_NAME_LEN,
        sizeof(srv_email_auth_struct),
        SRV_EMAIL_MAX_USERNAME_LEN,
        SRV_EMAIL_MAX_PASSWORD_LEN,        
    };

    return srv_email_checksum_compute_by_buffer((const U8*)&acct_struct_buffer,
                                                sizeof(acct_struct_buffer));
}

EMAIL_CHECKSUM email_stor_msg_verno_compute(void)
{
    /*
        checksum    sizeof(EMAIL_CHECKSUM)
        verno       sizeof(EMAIL_MSG_VERNO)
        fldr header sizeof(srv_email_stor_fldr_struct)
        index       sizeof(email_stor_fs_inbox_index_struct) * \
                       EMAIL_STOR_MAX_MSG_NUM_PER_FLDR
        msg note    sizeof(email_stor_fs_msg_struct)         * \
                       EMAIL_STOR_MAX_MSG_NUM_PER_FLDR
    */
    const U32 acct_struct_buffer[] =
    {
        sizeof(EMAIL_CHECKSUM),
        sizeof(EMAIL_MSG_VERNO),
        sizeof(srv_email_stor_fldr_struct),
        EMAIL_FLDR_NAME_LEN,
        sizeof(email_stor_fs_inbox_index_struct),
        sizeof(EMAIL_MSG_FLAG),
        EMAIL_STOR_MAX_MSG_NUM_PER_FLDR,
        sizeof(email_stor_fs_msg_struct),
        sizeof(EMAIL_MSG_PRIO),
        sizeof(EMAIL_MSG_STATE),
        sizeof(EMAIL_UID),
        SRV_EMAIL_MD5_DIGEST_LEN,
        EMAIL_MAX_ENCODED_DISP_NAME_LEN,
        EMAIL_MAX_ENCODED_ADDR_LEN,
        EMAIL_MAX_LIST_SUBJ_LEN,
    };

    return srv_email_checksum_compute_by_buffer((const U8*)&acct_struct_buffer,
                                                sizeof(acct_struct_buffer));
}

