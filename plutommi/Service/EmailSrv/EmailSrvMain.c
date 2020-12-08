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
 *  EmailSrvMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email service functions.
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
 * removed!
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#define _CRT_SECURE_NO_WARNINGS

#include "MMI_features.h"
#include "kal_debug.h"
#include "FileMgrSrvGProt.h"
#include "EmailSrvGProt.h"
#include "EmailSrvProt.h"
#include "EmailSrvStorage.h"
#include "EmailSrvComposer.h"
#include "mmi_inet_app_trc.h"
#include "mmi_frm_events_gprot.h"
#include "DebugInitDef_Int.h"
#include "MMIDataType.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "kal_debug.h"
#include "fs_type.h"
#include "fs_func.h"
#include "kal_public_api.h"
#include "fs_errcode.h"
#include "kal_trace.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "mmi_frm_timer_gprot.h"
#include "customer_email_num.h"

#ifdef __MMI_EMAIL_SUPPORT_1000_MAILS__
  #define SRV_EMAIL_MEM_CONN     (55 * 1024)
#else
  #define SRV_EMAIL_MEM_CONN     (20 * 1024)
#endif

#ifdef __COSMOS_MMI_PACKAGE__
  #ifdef __MMI_EMAIL_IMAP_PUSH__
    #define SRV_EMAIL_CONN_MAX_NUM (3)
  #else
    #define SRV_EMAIL_CONN_MAX_NUM (2)
  #endif
#else /* for PLUTO */
  #ifdef __MMI_EMAIL_IMAP_PUSH__
    #define SRV_EMAIL_CONN_MAX_NUM (2)
  #else
    #define SRV_EMAIL_CONN_MAX_NUM (1)
  #endif
#endif

#define SRV_EMAIL_MEM_BASE     (10 * 1024)

#define mem_pool_SIZE (SRV_EMAIL_MEM_BASE + SRV_EMAIL_MEM_CONN * SRV_EMAIL_CONN_MAX_NUM)

#define SRV_EMAIL_MEM_POOL_SIZE

#define SRV_EMAIL_MAX_ROOT_PATH_LEN 32
#define SRV_EMAIL_MAX_INIT_CALLBACK 5

#ifdef __MTK_TARGET__
#define EMAIL_MAIN_TRACE_INIT_ERROR(ret) MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_MAIN_INIT_ERROR, __LINE__, ret)
#define EMAIL_MAIN_TRACE_INIT_DONE(ret)  MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_MAIN_INIT_DONE, ret)
#define EMAIL_MAIN_TRACE_INIT_DOING()    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_MAIN_INIT_DOING, __LINE__)
#define EMAIL_MAIN_TRACE_FS_ERROR(ret)   MMI_TRACE(MMI_INET_TRC_G9_EMAIL, MMI_EMAIL_MAIN_FS_ERROR, __LINE__, ret)
#else
#define __E_SRV_MAIN__ "*** [MAIN] LINE:[%d], "
#define EMAIL_MAIN_TRACE_INIT_ERROR(ret) kal_printf(__E_SRV_MAIN__ "INIT ERROR, error code:[%d]\n", __LINE__, ret)
#define EMAIL_MAIN_TRACE_INIT_DONE(ret)  kal_printf(__E_SRV_MAIN__ "INIT Done, result:[%d]\n", __LINE__, ret)
#define EMAIL_MAIN_TRACE_INIT_DOING()    kal_printf(__E_SRV_MAIN__ "INITING...\n", __LINE__)
#define EMAIL_MAIN_TRACE_FS_ERROR(ret)   kal_printf(__E_SRV_MAIN__ "FS ERROR, error code:[%d]\n", __LINE__, ret)
#endif

typedef enum
{
    EMAIL_MAIN_CNTX_INIT_MOD_INVALID = 0,
    EMAIL_MAIN_CNTX_INIT_MOD_MESSAGE = 1,
    EMAIL_MAIN_CNTX_INIT_MOD_STORAGE = 2,
} srv_email_main_cntx_init_mod_enum;

typedef struct
{
    CHAR root_path[SRV_EMAIL_MAX_ROOT_PATH_LEN + 1];

    /* for ADM */
    KAL_ADM_ID adm_id;
    U8 mem_pool[mem_pool_SIZE];
    S32 malloc_cnt;

    /* for app init callback */
    void *                          app_init_userdata[SRV_EMAIL_MAX_INIT_CALLBACK];
    srv_email_app_init_funcptr_type app_init_callback[SRV_EMAIL_MAX_INIT_CALLBACK];
    srv_email_init_state_enum init_state;
    srv_email_main_cntx_init_mod_enum init_mod;
    S32 init_err_type;
    S32 init_errno;
    S32 srv_errno;
    srv_email_malloc_funcptr_type malloc_func;
    srv_email_mfree_funcptr_type mfree_func;
} srv_email_main_cntx_struct;

srv_email_main_cntx_struct g_email_main_cntx = {0};
srv_email_main_cntx_struct *email_main_cntx_p = &g_email_main_cntx;
const char * EMAIL_SYS_DRIVE_ROOT_DIR_NAME = "@email_sys";
const char * EMAIL_SYS_DRIVE_FILE_NAME = "drive";
const char * EMAIL_USR_DRIVE_ROOT_DIR_PREFIX = "@email";

MMI_BOOL srv_email_create_mem_pool(void);
void srv_email_delete_mem_pool(void);

/*****************************************************************************
 * FUNCTION
 *  srv_email_init_errno_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  errno           [?]     
 * RETURNS
 *  
 *****************************************************************************/
void srv_email_init_errno_set(S32 init_errno)
{
    email_main_cntx_p->init_errno = init_errno;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_read_root_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  root_path       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static srv_email_result_enum srv_email_read_root_path(CHAR *root_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;
    U32 read_write;
    WCHAR filepath[SRV_EMAIL_MAX_ROOT_PATH_LEN + 1] = {0};
    FS_HANDLE fs_handle;
    CHAR drive = (CHAR) FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_DRIVE_I_SYSTEM);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(filepath, "%c:\\%s", drive, EMAIL_SYS_DRIVE_ROOT_DIR_NAME);
    if ((fs_handle = FS_Open(filepath, FS_READ_ONLY | FS_OPEN_DIR)) < FS_NO_ERROR)      /* if directory not exist */
    {
        if ((ret = FS_CreateDir(filepath)) < 0)
        {
            EMAIL_MAIN_TRACE_INIT_ERROR(ret);
            srv_email_init_errno_set(ret);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
    }
    else
    {
        FS_Close(fs_handle);
    }

    kal_wsprintf(filepath, "%c:\\%s\\%s", drive, EMAIL_SYS_DRIVE_ROOT_DIR_NAME, EMAIL_SYS_DRIVE_FILE_NAME);
    if ((fs_handle = FS_Open(filepath, FS_READ_WRITE)) < FS_NO_ERROR)   /* if file not exist */
    {
        if ((fs_handle = FS_Open(filepath, FS_READ_WRITE | FS_CREATE_ALWAYS)) < FS_NO_ERROR)
        {
            EMAIL_MAIN_TRACE_INIT_ERROR(ret);
            srv_email_init_errno_set(fs_handle);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        drive = (CHAR)custom_email_using_card_memory() ? SRV_FMGR_CARD_DRV : SRV_FMGR_PUBLIC_DRV;
        ret = FS_Write(fs_handle, &drive, sizeof(CHAR), &read_write);
        FS_Close(fs_handle);
        if (ret != FS_NO_ERROR || sizeof(CHAR) != read_write)
        {
            EMAIL_MAIN_TRACE_INIT_ERROR(ret);
            srv_email_init_errno_set(ret);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
        sprintf(root_path, "%c:\\%s%d\\", drive, EMAIL_USR_DRIVE_ROOT_DIR_PREFIX, SRV_EMAIL_GLOBAL_MAX_MSG_NUM);        
        return SRV_EMAIL_RESULT_SUCC;
    }

    ret = FS_Read(fs_handle, &drive, sizeof(CHAR), &read_write);
    if (ret != FS_NO_ERROR || sizeof(CHAR) != read_write)
    {
        EMAIL_MAIN_TRACE_INIT_ERROR(ret);
        srv_email_init_errno_set(ret);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    FS_Close(fs_handle);

    sprintf(root_path, "%c:\\%s%d\\", drive, EMAIL_USR_DRIVE_ROOT_DIR_PREFIX, SRV_EMAIL_GLOBAL_MAX_MSG_NUM);
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_main_cntx_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static srv_email_result_enum srv_email_main_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_main_cntx_p->malloc_cnt = 0;
    email_main_cntx_p->init_state = SRV_EMAIL_INIT_STATE_INITING;
    email_main_cntx_p->init_mod = EMAIL_MAIN_CNTX_INIT_MOD_INVALID;
    /* app's callback MUST not be cleared! */

    if ((res = srv_email_read_root_path(email_main_cntx_p->root_path)) != SRV_EMAIL_RESULT_SUCC)
    {
        return res;
    }

    if (!srv_email_create_mem_pool())
    {
        return SRV_EMAIL_RESULT_FAIL;
    }
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_app_init_set_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback        [IN]        
 *  user_data       [?]         
 * RETURNS
 *  
 *****************************************************************************/
srv_email_result_enum srv_email_app_init_set_callback(srv_email_app_init_funcptr_type callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_EMAIL_MAX_INIT_CALLBACK; ++i)
    {
        if (email_main_cntx_p->app_init_callback[i] == callback)
        {
            email_main_cntx_p->app_init_userdata[i] = user_data;
    return SRV_EMAIL_RESULT_SUCC;
}
    }

    for (i = 0; i < SRV_EMAIL_MAX_INIT_CALLBACK; ++i)
    {
        if (email_main_cntx_p->app_init_callback[i] == NULL)
        {
            email_main_cntx_p->app_init_callback[i] = callback;
            email_main_cntx_p->app_init_userdata[i] = user_data;
    return SRV_EMAIL_RESULT_SUCC;
}
    }

    return SRV_EMAIL_RESULT_FAIL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_root_dir_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static srv_email_result_enum srv_email_root_dir_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR filepath[32];
    WCHAR filename[32];
    FS_DOSDirEntry info;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(filepath, "%s", email_main_cntx_p->root_path);
    filepath[mmi_wcslen(filepath) - 1] = 0; /* remove the last '\' */

    ret = FS_FindFirst(filepath, 0, 0, &info, filename, 32);
    if (ret < 0)
    {
        ret = FS_CreateDir(filepath);
        if (ret < 0)
        {
            EMAIL_MAIN_TRACE_INIT_ERROR(ret);
            srv_email_init_errno_set(ret);
            return SRV_EMAIL_RESULT_FS_ERROR;
        }
    }
    else
    {
        FS_FindClose(ret);
    }

    FS_SetAttributes(filepath, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    return SRV_EMAIL_RESULT_SUCC;
}


static void srv_email_main_init_notify_app(void *user_data)
{
    S32 i;
    for (i = 0; i < SRV_EMAIL_MAX_INIT_CALLBACK; ++i)
    {
        if (email_main_cntx_p->app_init_callback[i] != NULL)
        {
            email_main_cntx_p->app_init_callback[i](
              email_main_cntx_p->init_state,
              email_main_cntx_p->init_err_type,
              email_main_cntx_p->app_init_userdata[i]);
        }
    }
}
/*****************************************************************************
 * FUNCTION
 *  srv_email_main_init_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  res             [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_main_init_callback(srv_email_result_enum res, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_main_cntx_init_mod_enum init_mod;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (user_data != NULL)
    {
        init_mod = *(srv_email_main_cntx_init_mod_enum*)(user_data);
    }
    else
    {
        init_mod = EMAIL_MAIN_CNTX_INIT_MOD_INVALID;
    }
    
    if (init_mod == EMAIL_MAIN_CNTX_INIT_MOD_MESSAGE)
    {
        if (res != SRV_EMAIL_RESULT_SUCC)
        {
            email_main_cntx_p->init_state = SRV_EMAIL_INIT_STATE_ERROR;
            EMAIL_MAIN_TRACE_INIT_DONE(res);
            goto MAIN_EXIT_HANDLE;
        }
        EMAIL_MAIN_TRACE_INIT_DOING();
        email_main_cntx_p->init_mod = EMAIL_MAIN_CNTX_INIT_MOD_STORAGE;
        srv_email_stor_init(srv_email_main_init_callback, &email_main_cntx_p->init_mod);    /* storage ASYNC init */
        return;
    }
    
    if (res == SRV_EMAIL_RESULT_SUCC)
    {
        email_main_cntx_p->init_state = SRV_EMAIL_INIT_STATE_READY;
    }
    else
    {
        email_main_cntx_p->init_state = SRV_EMAIL_INIT_STATE_ERROR;
        if (res == SRV_EMAIL_RESULT_FS_ERROR)
        {
            email_main_cntx_p->srv_errno = email_main_cntx_p->init_errno;
        }
    }

    EMAIL_MAIN_TRACE_INIT_DONE(res);

MAIN_EXIT_HANDLE:
    email_main_cntx_p->init_err_type = res;
    srv_email_schdl_start_job(srv_email_main_init_notify_app, email_main_cntx_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_get_srv_init_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
srv_email_init_state_enum srv_email_get_srv_init_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return email_main_cntx_p->init_state;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_result_enum res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // call fs_async_msg_handler when receive  async msg
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_OPEN_RSP);
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_FIND_FIRST_RSP);
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_GET_FOLDER_SIZE_RSP);
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_WRITE_RSP);
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_READ_RSP);
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_DELETE_RSP);
    SetProtocolEventHandler(fs_async_msg_handler, MSG_ID_FS_SEEK_RSP);

    srv_email_om_init();

    if ((res = srv_email_main_cntx_init()) != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_MAIN_TRACE_INIT_ERROR(res);
        srv_email_main_init_callback(res, NULL);
        return;
    }
    EMAIL_MAIN_TRACE_INIT_DOING();

    if ((res = srv_email_root_dir_create()) != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_MAIN_TRACE_INIT_ERROR(res);
        srv_email_main_init_callback(res, NULL);
        return;
    }
    EMAIL_MAIN_TRACE_INIT_DOING();

    if ((res = srv_email_acct_init()) != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_MAIN_TRACE_INIT_ERROR(res);
        srv_email_main_init_callback(res, NULL);
        return;
    }
    EMAIL_MAIN_TRACE_INIT_DOING();

    if ((res = srv_email_fldr_init()) != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_MAIN_TRACE_INIT_ERROR(res);
        srv_email_main_init_callback(res, NULL);
        return;
    }
    EMAIL_MAIN_TRACE_INIT_DOING();

    if ((res = srv_email_comp_init()) != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_MAIN_TRACE_INIT_ERROR(res);
        srv_email_main_init_callback(res, NULL);
        return;
    }
    EMAIL_MAIN_TRACE_INIT_DOING();
    
    if ((res = srv_email_async_fs_init()) != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_MAIN_TRACE_INIT_ERROR(res);
        srv_email_main_init_callback(res, NULL);
        return;
    }
    EMAIL_MAIN_TRACE_INIT_DOING();

    if ((res = srv_email_nwk_init()) != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_MAIN_TRACE_INIT_ERROR(res);
        srv_email_main_init_callback(res, NULL);
        return;
    }
    EMAIL_MAIN_TRACE_INIT_DOING();

    if ((res = srv_email_emn_init()) != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_MAIN_TRACE_INIT_ERROR(res);
        srv_email_main_init_callback(res, NULL);
        return;
    }
    EMAIL_MAIN_TRACE_INIT_DOING();

    if ((res = srv_email_otap_init()) != SRV_EMAIL_RESULT_SUCC)
    {
        EMAIL_MAIN_TRACE_INIT_ERROR(res);
        srv_email_main_init_callback(res, NULL);
        return;
    }
    EMAIL_MAIN_TRACE_INIT_DOING();

    email_main_cntx_p->init_mod = EMAIL_MAIN_CNTX_INIT_MOD_MESSAGE;
    srv_email_msg_init(srv_email_main_init_callback, &email_main_cntx_p->init_mod);
}

static MMI_BOOL srv_email_mem_pool_created = MMI_FALSE;
/*****************************************************************************
 * FUNCTION
 *  srv_email_create_mem_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_email_create_mem_pool(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U32 subpool_size[] = {16, 32, 64, 128, 0xffffffff, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_email_mem_pool_created)
    {
        srv_email_mem_check();
        return MMI_TRUE;
    }
    
    EMAILSRV_ASSERT(!email_main_cntx_p->adm_id);

    email_main_cntx_p->adm_id = kal_adm_create(email_main_cntx_p->mem_pool, mem_pool_SIZE, subpool_size,
#ifdef __EMAIL_DEBUG__
                                               KAL_TRUE
#else 
                                               KAL_FALSE
#endif 
        );

    if (!email_main_cntx_p->adm_id)
    {
        return MMI_FALSE;
    }

    srv_email_mem_pool_created = MMI_TRUE;

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_delete_mem_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_delete_mem_pool(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    EMAILSRV_ASSERT(email_main_cntx_p->adm_id);

    srv_email_mem_check();

    kal_adm_delete(email_main_cntx_p->adm_id);

    email_main_cntx_p->adm_id = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_mem_alloc_dbg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size            [IN]        
 *  filename        [?]         
 *  line            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_email_mem_alloc_dbg(U32 size, CHAR *filename, U32 line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = __kal_adm_alloc(email_main_cntx_p->adm_id, size, NULL, 0, filename, line);
    if (!ptr)
    {
    #ifndef __MTK_TARGET__
        kal_uint32 left_size;

        left_size = kal_adm_get_total_left_size(email_main_cntx_p->adm_id);

        kal_printf("ADM: buffer not enough, left size[%d], size[%d]\n", left_size, size);
    #endif 
    }
    else
    {
        email_main_cntx_p->malloc_cnt++;
    }

    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_mem_free_dbg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ptr     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_mem_free_dbg(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_main_cntx_p->malloc_cnt--;

    EMAILSRV_ASSERT(email_main_cntx_p->adm_id);
    kal_adm_free(email_main_cntx_p->adm_id, ptr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_get_adm_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
KAL_ADM_ID srv_email_get_adm_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return email_main_cntx_p->adm_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_mem_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_mem_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_adm_print_log(email_main_cntx_p->adm_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_get_malloc_funcptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_email_malloc_funcptr_type srv_email_get_malloc_funcptr(EMAIL_SRV_HANDLE srv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return email_main_cntx_p->malloc_func;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_get_mfree_funcptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_email_mfree_funcptr_type srv_email_get_mfree_funcptr(EMAIL_SRV_HANDLE srv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return email_main_cntx_p->mfree_func;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_create
 * DESCRIPTION
 *  This function is used to create a new service instance.
 * PARAMETERS
 *  srv_handle      [OUT]       Used to store the service instance handle
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_create(EMAIL_SRV_HANDLE *srv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_destroy
 * DESCRIPTION
 *  This function is used to destroy the specified service instance.
 * PARAMETERS
 *  srv_handle      [IN]        The service handle
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_destroy(EMAIL_SRV_HANDLE srv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_set_mem_func
 * DESCRIPTION
 *  This function is used to set the memory alloc/free functions for
 *  the specified service instance.
 * PARAMETERS
 *  srv_handle          [IN]        The service handle
 *  mem_alloc_func      [IN]        The memory alloc function
 *  mem_free_func       [IN]        The memory free function
 * RETURNS
 *  The result code.
 *****************************************************************************/
srv_email_result_enum srv_email_set_mem_func(
                        EMAIL_SRV_HANDLE srv_handle,
                        srv_email_malloc_funcptr_type mem_alloc_func,
                        srv_email_mfree_funcptr_type mem_free_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    email_main_cntx_p->malloc_func = mem_alloc_func;
    email_main_cntx_p->mfree_func = mem_free_func;
    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_get_root_path
 * DESCRIPTION
 *  This function is used to get Email root path.
 * PARAMETERS
 *  void
 * RETURNS
 *  root path pointer.
 *****************************************************************************/
CHAR *srv_email_get_root_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return email_main_cntx_p->root_path;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_set_drive
 * DESCRIPTION
 *  This function is used to set Email root path.
 * PARAMETERS
 *  drive       [IN]        Root path's drive
 * RETURNS
 *  Initialization state.
 *****************************************************************************/
srv_email_result_enum srv_email_set_drive(CHAR drive)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    U32 read_write;
    FS_HANDLE fs_handle;
    WCHAR filepath[SRV_EMAIL_MAX_ROOT_PATH_LEN + 1] = {0};
    CHAR sys_drive = (CHAR) FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_DRIVE_I_SYSTEM);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen(email_main_cntx_p->root_path) != 0)
    {
        email_main_cntx_p->root_path[0] = drive;
    }

    kal_wsprintf(filepath, "%c:\\%s\\%s", sys_drive, EMAIL_SYS_DRIVE_ROOT_DIR_NAME, EMAIL_SYS_DRIVE_FILE_NAME);
    if ((fs_handle = FS_Open(filepath, FS_READ_WRITE)) < FS_NO_ERROR)
    {
        return SRV_EMAIL_RESULT_FS_ERROR;
    }

    ret = FS_Write(fs_handle, &drive, sizeof(CHAR), &read_write);
    if (ret != FS_NO_ERROR || sizeof(CHAR) != read_write)
    {
        FS_Close(fs_handle);
        return SRV_EMAIL_RESULT_FS_ERROR;
    }
    FS_Close(fs_handle);

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_get_drive
 * DESCRIPTION
 *  This function is used to set Email root path.
 * PARAMETERS
 *  void
 * RETURNS
 *  root path's drive
 *****************************************************************************/
CHAR srv_email_get_drive(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen(email_main_cntx_p->root_path) != 0)
    {
        return email_main_cntx_p->root_path[0];
    }
    return 0;
}

void srv_email_errno_set(S32 srv_errno)
{
    email_main_cntx_p->srv_errno = srv_errno;
}

S32 srv_email_errno_get(void)
{
    return email_main_cntx_p->srv_errno;
}

EMAIL_ACCT_ID srv_email_msg_id_to_acct_id(EMAIL_MSG_ID msg_id)
{
    return srv_email_stor_msg_id_to_acct_id(msg_id);
}

EMAIL_FLDR_ID srv_email_msg_id_to_fldr_id(EMAIL_MSG_ID msg_id)
{
    return srv_email_stor_msg_id_to_fldr_id(msg_id);
}

EMAIL_MSG_ID srv_email_attch_id_to_msg_id(EMAIL_ATTCH_ID attch_id)
{
    return srv_email_stor_attch_id_to_msg_id(attch_id);
}


mmi_ret srv_email_evt_proc_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_nwk_evt_proc_hdlr(evt);

    return MMI_RET_OK;
}


