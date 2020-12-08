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
 *  DLAgentDRM.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Provide DRM wrapper and utilities.
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
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/

#include "MMI_include.h"

#ifdef __MMI_DOWNLOAD_AGENT__
#ifdef __DRM_SUPPORT__

#include "MMI_conn_app_trc.h"
#include "app_mine.h"
//#include "FileMgrSrvGprot.h"

#include "drm_def.h"                    /* DRM_PROC_RESULT_OK */
#include "drm_gprot.h"
#include "RightsMgrGProt.h"

#include "DLAgentSrvDef.h"
#include "DLAgentSrvGprot.h"
#include "DLAgentSrvIProt.h"
#ifdef __MMI_DOWNLOAD_AGENT__
#include "mmi_rp_srv_downloadagent_def.h"
#endif
#include "DLAgentSrvWPS.h"

    #include "MMI_features.h"
    #include "kal_general_types.h"
    #include "MMIDataType.h"
    #include "mmi_conn_app_trc.h"
    #include "DebugInitDef_Int.h"
    #include "kal_trace.h"
    #include "drm_errcode.h"
    #include "fs_type.h"
    #include "mmi_frm_mem_gprot.h"
    #include "kal_public_api.h"
    #include "Unicodexdcl.h"

/****************************************************************************
 * [DRM Processing API]
 ****************************************************************************/

/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct srv_da_drm_process_context_struct_s
{
    kal_uint8 drm_serial;
    U16 *filepath;
    void *arg;
    void (*result_callback)(
        void *arg,
        S32 result,
        const U16 *new_filepath,
        const applib_mime_type_struct *new_mime_type,
        drm_method_enum method,
        const srv_da_drm_result_info_struct* info);

    struct srv_da_drm_process_context_struct_s *next;
} srv_da_drm_process_context_struct;


/****************************************************************************
 * Global Variables
 ****************************************************************************/

static srv_da_drm_process_context_struct *g_srv_da_drm_processing_list = NULL;


/****************************************************************************
 * Private Functions
 ****************************************************************************/
 
/*****************************************************************************
 * FUNCTION
 *  srv_da_drm_install_result_callback
 * DESCRIPTION
 *  Callback function for DRM installation result. This function will extract
 *  necessary information from the result and pass to the client by result_callback().
 * PARAMETERS
 *  serial      [IN] DRM serial
 *  result      [IN] Result
 *  mime_type   [IN] Result MIME type
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_da_drm_install_result_callback(
    kal_uint8 serial,
    kal_int32 result,
    applib_mime_type_struct *mime_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_drm_process_context_struct *prev;
    srv_da_drm_process_context_struct *cntx;
    srv_da_drm_result_info_struct info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (result >= 0)
    {
        MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_DRM_PROCESS_RESULT, serial, ' ', result,
            (mime_type != NULL ? mime_type->mime_subtype : 0));
    }
    else
    {
        MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_DRM_PROCESS_RESULT, serial, '-', (-result),
            (mime_type != NULL ? mime_type->mime_subtype : 0));
    }
    
    if (result == DRM_RESULT_OK && srv_da_is_drm_file(mime_type))
    {
        result = DRM_RESULT_INVALID_FORMAT;
    }

    prev = NULL;
    cntx = g_srv_da_drm_processing_list;
    for ( ; cntx != NULL; cntx = cntx->next)
    {
        if (cntx->drm_serial == serial)
        {
            break;
        }
    
        prev = cntx;
    }

    if (cntx == NULL)
    {
        return;
    }

    DA_TRACE_FUNC1(srv_da_drm_install_result_callback, 1);

    /* Remove from list */
    if (cntx == g_srv_da_drm_processing_list)
    {
        g_srv_da_drm_processing_list = cntx->next;
    }
    else
    {
        prev->next = cntx->next;
    }

    info.is_archive = MMI_FALSE;
    info.waiting = MMI_FALSE;

    if (result != DRM_RESULT_OK)
    {
        srv_da_util_file_delete(cntx->filepath);

        cntx->result_callback(
            cntx->arg,
            result,
            NULL,
            (const applib_mime_type_struct*)mime_type,
            DRM_METHOD_NONE,
            &info);
    }
    else
    {
        drm_method_enum method;
        FS_HANDLE f_hdlr;
        
        method = DRM_METHOD_NONE;

        f_hdlr = DRM_open_file(cntx->filepath, FS_READ_ONLY, DRM_PERMISSION_NONE);
        if (f_hdlr > 0)
        {
            method = DRM_get_object_method(f_hdlr, NULL);
#ifdef __DRM_V02__
            info.is_archive = DRM_is_archive(f_hdlr, NULL);
#endif /* __DRM_V02__ */
            DRM_close_file(f_hdlr);
        }

        info.waiting = DRM_sd_callback_status(serial);

        DA_TRACE_FUNC3(srv_da_drm_install_result_callback, 2, method, info.waiting);
        
        cntx->result_callback(cntx->arg,
            result,
            cntx->filepath,
            (const applib_mime_type_struct*)mime_type,
            method,
            &info);
    }

    OslMfree(cntx->filepath);
    OslMfree(cntx);
}


/****************************************************************************
 * Public Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_da_drm_process
 * DESCRIPTION
 *  Process a DRM file.
 * PARAMETERS
 *  filepath        [IN]  File to be processed
 *  mime_type       [IN]  Original MIME type, it must be one of DRM MIME types
 *  need_to_wait    [OUT] If we have to wait for result asynchronously,
 *                        this value will be set to MMI_TRUE. The client can
 *                        show, for exmaple, "Please wait" to user in this peroid.
 *                        If its value is MMI_FALSE after called, result_callback()
 *                        will be called immediately.
 *  arg             [IN]  Will be passed to the result_callback()
 *  result_callback [IN]  Callback function to notify result.
 * RETURNS
 *  Session data, can be used for cancellation
 *****************************************************************************/
void* srv_da_drm_process(
    const U16 *filepath,
    const applib_mime_type_struct *mime_type,
    MMI_BOOL *need_to_wait,
    void *arg,
    void (*result_callback)(
        void *arg,
        S32 result,
        const U16 *new_filepath,
        const applib_mime_type_struct *new_mime_type,
        drm_method_enum method,
        const srv_da_drm_result_info_struct* info))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *temp_file;
    U32 temp_file_path_len = 0;
    drm_proc_enum install_result;
    kal_uint8 drm_serial;
    void *session;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    session = NULL;

    DA_TRACE_FUNC1(srv_da_drm_process, 0);
    
#ifdef __DRM_V01__
    if( mime_type->mime_subtype == MIME_SUBTYPE_DRM_CONTENT ||
        mime_type->mime_subtype == MIME_SUBTYPE_DRM_MESSAGE )
    {
        U16 *folder_path;
        U16 *ptr;
        U32 filepath_len;
        

        filepath_len = mmi_wcslen(filepath);
        
        /* Get folder path */
        folder_path = (U16*)srv_da_adp_mem_allocate((filepath_len + 1) * sizeof(U16));
        mmi_wcscpy(folder_path, filepath);
        ptr = srv_da_util_get_filename(folder_path);
        MMI_ASSERT(ptr != folder_path && ptr != NULL);
        *ptr = L'\0';

        /* Get temp file path */
        temp_file_path_len = filepath_len + 40; /* Reserve 40 bytes for filename additionally */
        temp_file = (U16*)srv_da_adp_mem_allocate((temp_file_path_len + 1) * sizeof(U16));
        srv_da_util_get_temp_filename(folder_path, temp_file, temp_file_path_len);

        OslMfree(folder_path);
    }
    else
#endif
    {
        /* Use original file directly */
        temp_file_path_len = mmi_wcslen(filepath) + 10;
        temp_file = (U16*)srv_da_adp_mem_allocate((temp_file_path_len + 1) * sizeof(U16));
        mmi_wcsncpy(temp_file, filepath, temp_file_path_len);
    }

    drm_serial = 0;

    install_result = (drm_proc_enum)DRM_install_object((kal_uint8*)mime_type->mime_string,
                                     (kal_wchar*)filepath,
                                     KAL_FALSE,
                                     temp_file,
                                     (temp_file_path_len + 1) * sizeof(U16), /* in bytes */
                                     &drm_serial,
                                     NULL,
                                     srv_da_drm_install_result_callback);

    if (install_result >= 0)
    {
        MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_DRM_PROCESS, drm_serial, ' ', install_result);
    }
    else
    {
        MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_DRM_PROCESS, drm_serial, '-', (-install_result));
    }

    if (install_result == DRM_PROC_ENCRYPT_BUSY || install_result == DRM_PROC_ENCRYPT_OCCUPIED)
    {
        srv_da_drm_process_context_struct *drm_process_cntx;
    
        /* Processing */
        *need_to_wait = MMI_TRUE;

        /* Add to list */
        drm_process_cntx = (srv_da_drm_process_context_struct*)srv_da_adp_mem_allocate(sizeof(srv_da_drm_process_context_struct));
        
        drm_process_cntx->drm_serial = drm_serial;
        drm_process_cntx->filepath = temp_file;
        drm_process_cntx->arg = arg;
        drm_process_cntx->result_callback = result_callback;
        drm_process_cntx->next = g_srv_da_drm_processing_list;
        g_srv_da_drm_processing_list = drm_process_cntx;

        session = (void*)drm_process_cntx;
    }
    else
    {
        const applib_mime_type_struct *mime_type;
        drm_method_enum method;
        srv_da_drm_result_info_struct info;
    
        /* Completed / ready */
        *need_to_wait = MMI_FALSE;
        mime_type = NULL;
        method = DRM_METHOD_NONE;
        info.is_archive = MMI_FALSE;
        info.waiting = DRM_sd_callback_status(drm_serial);

        if (install_result == DRM_RESULT_OK)
        {
            S32 f_hdlr;
            kal_uint8 *content_type;
        
            f_hdlr = DRM_open_file(temp_file, FS_READ_ONLY, DRM_PERMISSION_NONE);

            if (f_hdlr < 0) /* File system error */
            {
                install_result = DRM_RESULT_INVALID;
            }
            else
            {
                content_type = DRM_get_content_type(f_hdlr, NULL);
                mime_type = applib_mime_type_look_up((kal_char*)content_type, NULL, 0,0);
                method = DRM_get_object_method(f_hdlr, NULL);
#ifdef __DRM_V02__
                info.is_archive = DRM_is_archive(f_hdlr, NULL);
#endif

                DRM_close_file(f_hdlr);
            }
        }

        DA_TRACE_FUNC3(srv_da_drm_process, 2, method, info.waiting);

        result_callback(arg, install_result, temp_file, mime_type, method, &info);
        
        OslMfree(temp_file);
    }

    return session;
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_drm_process_cancel
 * DESCRIPTION
 *  Cancel a processing session.
 *  NOTE: Either cancel successfully or not the result_callback() will be invoked
 *  finally. If cancel successfully, the processing result will be 
 *  DRM_RESULT_CANCELLED to the result_callback().
 * PARAMETERS
 *  session     [IN] Session to cancel
 * RETURNS
 *  Successfully cancelled.
 *****************************************************************************/
MMI_BOOL srv_da_drm_process_cancel(void *session)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_drm_process_context_struct *cntx;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(session != NULL);

    DA_TRACE_FUNC1(srv_da_drm_process_cancel, 0);

    /* Checn whether the session in the list */
    cntx = g_srv_da_drm_processing_list;
    for ( ; cntx != NULL; cntx = cntx->next)
    {
        if (cntx == session)
        {
            break;
        }
    }

    if (cntx == NULL)
    {
        DA_TRACE_FUNC1(srv_da_drm_process_cancel, 1);
        return MMI_FALSE;
    }

    result = (MMI_BOOL)DRM_async_cancel_process(cntx->drm_serial);

    MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_DRM_PROCESS_CANCEL, cntx->drm_serial, result);

    /* It always calls the callback even if cancelled.
       So we release the resource only in the callback function. */

    return result;
}


#ifdef __DRM_SUPPORT_SD_CALLBACK__


/****************************************************************************
 * [DRM API for Separate Delivery]
 ****************************************************************************/

typedef struct srv_da_drm_wait_for_rights_callback_s
{
    kal_int32 serial;
    U16 *filepath;
    void *arg;
    void (*rights_arrived_callback)(void *arg);
    void (*fail_to_wait_callback)(void *arg, drm_sd_expiry_type_enum cause, MMI_BOOL can_continue_waiting, MMI_BOOL *continue_waiting);

    struct srv_da_drm_wait_for_rights_callback_s *next;
} srv_da_drm_wait_for_rights_context_struct;


/****************************************************************************
 * Global Variables
 ****************************************************************************/

static srv_da_drm_wait_for_rights_context_struct *g_srv_da_drm_waiting_for_rights_list = NULL;


/****************************************************************************
 * Private Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_da_drm_wait_for_rights_callback
 * DESCRIPTION
 *  Callback function to be notified of rights arrival.
 * PARAMETERS
 *  arg     [IN] Session context: srv_da_drm_wait_for_rights_context_struct
 *  result  [IN] Result: drm_sd_expiry_type_enum
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool srv_da_drm_wait_for_rights_callback(void *arg, kal_uint8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_drm_wait_for_rights_context_struct *prev;
    srv_da_drm_wait_for_rights_context_struct *cntx;
    MMI_BOOL continue_waiting;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DA_TRACE_FUNC2(srv_da_drm_wait_for_rights_callback, 1, result);

    prev = NULL;
    cntx = g_srv_da_drm_waiting_for_rights_list;
    for ( ; cntx != NULL; cntx = cntx->next)
    {
        if (arg == cntx)
        {
            break;
        }

        prev = cntx;
    }

    if (cntx == NULL)
    {
        return KAL_TRUE;
    }

    MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_DRM_WAIT_FOR_RIGHTS_RESULT, cntx->serial, result);
    
    continue_waiting = MMI_FALSE;
    cntx->serial = -1;
    
    switch (result)
    {
        case DRM_SD_EXPIRY_RIGHTS_ARRIVE:
            if (cntx->rights_arrived_callback != NULL)
            {
                cntx->rights_arrived_callback(cntx->arg);
            }
        
            break;
    
        case DRM_SD_EXPIRY_TIMEOUT:
        case DRM_SD_EXPIRY_ERROR:
            cntx->fail_to_wait_callback(cntx->arg, result, MMI_TRUE, &continue_waiting);
            break;
            
        case DRM_SD_EXPIRY_RECORD_REPLACE:
            cntx->fail_to_wait_callback(cntx->arg, result, MMI_FALSE, &continue_waiting);
            MMI_ASSERT(continue_waiting == MMI_FALSE);
            break;

        default:
            break;
    }


    DA_TRACE_FUNC2(srv_da_drm_wait_for_rights_callback, 2, continue_waiting);

    if (!continue_waiting)
    {
        /* Remove from list */
        if (cntx == g_srv_da_drm_waiting_for_rights_list)
        {
            g_srv_da_drm_waiting_for_rights_list = cntx->next;
        }
        else
        {
            prev->next = cntx->next;
        }

        OslMfree(cntx->filepath);
        OslMfree(cntx);
        
        return KAL_TRUE;
    }

    return KAL_FALSE; /* continue_waiting == MMI_TRUE */
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_drm_wait_for_rights
 * DESCRIPTION
 *  Wait for rights arrival.
 *  NOTE: Sometimes maybe we already have the rights. However, the RMGR will
 *  try to wait for a new rights arrival. So if we let RMGR to wait but not
 *  check the rights first, it may be we can already use the object but also
 *  wait for the rights.
 * PARAMETERS
 *  filepath        [IN] DRM file that requires rights
 *  time_to_wait    [IN] Time to wait for rights in seconds
 *  arg             [IN] Will be passed to the callback functions.
 *  rights_arrived_callback [IN] When the rights arrived this function will
 *                               be called.
 *  fail_to_wait_callback   [IN] If rights did not arrive, this function will be called.
 *                               If can_continue_waiting == MMI_TRUE, we can set
 *                               continue_waiting = MMI_TRUE to continue waiting.
 *                               Otherwise, we shall stop waiting.
 * RETURNS
 *  Session data, can be used for cancellation
 *****************************************************************************/
void* srv_da_drm_wait_for_rights(
    const U16 *filepath,
    U32 time_to_wait,
    void *arg,
    void (*rights_arrived_callback)(void *arg),
    void (*fail_to_wait_callback)(void *arg, drm_sd_expiry_type_enum cause, MMI_BOOL can_continue_waiting, MMI_BOOL *continue_waiting))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_drm_wait_for_rights_context_struct *cntx;
    void *session;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    session = NULL;
    
    cntx = (srv_da_drm_wait_for_rights_context_struct*)srv_da_adp_mem_allocate(sizeof(srv_da_drm_wait_for_rights_context_struct));

    cntx->serial = DRM_register_sd_callback((kal_wchar*)filepath, time_to_wait, cntx, srv_da_drm_wait_for_rights_callback);

    MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_DRM_WAIT_FOR_RIGHTS, cntx->serial, time_to_wait);

    if (cntx->serial >= 0)
    {
        /* Fill fields and add to list */
        cntx->filepath = (U16*)srv_da_adp_mem_allocate((mmi_wcslen(filepath) + 1) * sizeof(U16));
        mmi_wcscpy(cntx->filepath, filepath);
        cntx->arg = arg;
        cntx->rights_arrived_callback = rights_arrived_callback;
        cntx->fail_to_wait_callback = fail_to_wait_callback;
        cntx->next = g_srv_da_drm_waiting_for_rights_list;
        g_srv_da_drm_waiting_for_rights_list = cntx;

        session = (void*)cntx;
    }
    else
    {
        OslMfree(cntx);
        cntx = NULL;
        session = NULL;
    }

    return session;
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_drm_wait_for_rights_cancel
 * DESCRIPTION
 *  Cancel to wait for rights. If a session is cancelled, the callback function
 *  won't be called even if the rights arrives later.
 * PARAMETERS
 *  session     [IN] Session to cancel
 * RETURNS
 *  void
 *****************************************************************************/
void srv_da_drm_wait_for_rights_cancel(void *session)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_da_drm_wait_for_rights_context_struct *prev;
    srv_da_drm_wait_for_rights_context_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev = NULL;
    cntx = g_srv_da_drm_waiting_for_rights_list;
    for ( ; cntx != NULL; cntx = cntx->next)
    {
        if (session == cntx)
        {
            break;
        }

        prev = cntx;
    }

    if (cntx == NULL || cntx->serial < 0)
    {
        return;
    }

    MMI_TRACE(MMI_DA_TRACE_GROUP, MMI_DA_TRC_DRM_WAIT_FOR_RIGHTS_CANCEL, cntx->serial);

    DRM_cancel_sd_callback(cntx->serial);

    /* Remove from list */
    if (cntx == g_srv_da_drm_waiting_for_rights_list)
    {
        g_srv_da_drm_waiting_for_rights_list = cntx->next;
    }
    else
    {
        prev->next = cntx->next;
    }

    OslMfree(cntx->filepath);
    OslMfree(cntx);
}

#endif /* __DRM_SUPPORT_SD_CALLBACK__ */


/****************************************************************************
 * [DRM Utilities]
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_da_drm_show_process_info
 * DESCRIPTION
 *  Call DRM API to popup proper message.
 * PARAMETERS
 *  result      [IN] Process result
 *  mime_type   [IN] Result MIME type
 *  info        [IN] Additional information of DRM result
 * RETURNS
 *  void
 *****************************************************************************/
void srv_da_drm_show_process_info(
    S32 result,
    const applib_mime_type_struct *mime_type,
    const srv_da_drm_result_info_struct *info,
    srv_da_action_enum action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_rmgr_src_enum rmgr_src;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    rmgr_src = MMI_RMGR_SRC_SAVE_AS;

    switch (action)
    {
        case MMI_DA_PUSH:
        case MMI_DA_PUSH_SIM2:
        case MMI_DA_PUSH_SIM3:
        case MMI_DA_PUSH_SIM4:
            rmgr_src = MMI_RMGR_SRC_PUSH;
            break;

        case MMI_DA_WAP_DOWNLOAD:
        case MMI_DA_OMA_DOWNLOAD:
            rmgr_src = MMI_RMGR_SRC_WAP_DOWNLOAD;
            break;

        case MMI_DA_SAVE_AS:
            rmgr_src = MMI_RMGR_SRC_SAVE_AS;
            break;

        default:
            break;
    }
    
    srv_rmgr_show_process_info(result, info->waiting, rmgr_src, (applib_mime_type_struct*)mime_type); 
}
    

/*****************************************************************************
 * FUNCTION
 *  srv_da_drm_has_rights
 * DESCRIPTION
 *  Check whether the file has rights.
 * PARAMETERS
 *  filepath    [IN] The file to check
 * RETURNS
 *  Has rights
 *****************************************************************************/
MMI_BOOL srv_da_drm_has_rights(const U16 *filepath, const applib_mime_type_struct* mime_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool has_rights;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    has_rights = DRM_has_valid_rights((kal_wchar*)filepath);

    DA_TRACE_FUNC1(srv_da_drm_has_rights, has_rights);
    
    return (MMI_BOOL)has_rights;
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_drm_presetting
 * DESCRIPTION
 *  Set the presetting according to the DRM type.
 * PARAMETERS
 *  param       [IN]  Parameters to determine pre-setting
 *  presetting  [OUT] Pre-setting
 * RETURNS
 *  void
 *****************************************************************************/
void srv_da_drm_presetting(
    const srv_da_presetting_param_struct *param,
    srv_da_presetting_struct *presetting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_da_default_presetting(param, presetting);
    
    if(srv_da_is_drm_right(param->mime_type) ||
        srv_da_is_drm_roap(param->mime_type))
    {
        /* Don't confirm with user */
        presetting->confirm_download = MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_da_drm_content_setting
 * DESCRIPTION
 *  Please refer to the comments for further detail.
 * PARAMETERS
 *  session_id          [IN]    Session ID
 *  mime_type           [IN]    applib_mime_type_enum
 *  mime_subtype        [IN]    applib_mime_subtype_enum
 *  action              [IN]    srv_da_action_enum
 *  filesize            [IN]    File size
 *  url                 [IN]    URL: url[WAP_DL_MAX_URL_LEN]
 *  mime_type_string    [IN]    MIME type string: mime_type_string[WAP_DL_MAX_MIME_TYPE_LEN]
 *  content_len         [IN]    Content-Length in HTTP header, may be 0.
 *  content             [IN]    Content in HTTP response, may be NULL
 *  setting             [OUT]   Appropriate behavior setting by previous information.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_da_drm_content_setting(
    S32	session_id,
    S32	mime_type,
    S32	mime_subtype,
    S32 action,
    U32	filesize,
    PS8	url,
    PS8	mime_type_string,
    U32	content_len,
    PS8	content,
    srv_da_setting_struct *setting)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_da_bypass_setting(
        session_id,
        mime_type,
        mime_subtype,
        action,
        filesize,
        url,
        mime_type_string,
        content_len,
        content,
        setting);

    setting->can_minimize = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_da_drm_extract_info_from_http_header
 * DESCRIPTION
 *  Read informations from HTTP header.
 * PARAMETERS
 *  header                      [IN]  HTTP header
 *  time_to_wait_for_rights     [OUT] Value from X-Oma-Drm-Separate-Delivery
 *                                    -1 if not present.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_da_drm_extract_info_from_http_header(
    const S8 *header,
    S32 *time_to_wait_for_rights)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    *time_to_wait_for_rights = -1;

    if (header == NULL)
    {
        return;
    }

    buffer = (S8*)srv_da_adp_mem_allocate(40);
    
    if (srv_da_util_extract_from_header(
        header,
        "X-Oma-Drm-Separate-Delivery",
        buffer,
        40) != NULL)
    {
        if (buffer[0] == '\0') /* No value is specified */
        {
            *time_to_wait_for_rights = DRM_DEFAULT_WAIT;
        }
        else if (!srv_da_util_atoi(buffer, time_to_wait_for_rights))
        {
            *time_to_wait_for_rights = DRM_DEFAULT_WAIT;
        }

        if (*time_to_wait_for_rights < 0)
        {
            *time_to_wait_for_rights = DRM_DEFAULT_WAIT;
        }
    }

    OslMfree(buffer);
}


/*****************************************************************************
* FUNCTION
*   srv_da_is_drm_file
* DESCRIPTION
*   check if it is a drm_file which require pre-processing
* PARAMETERS
*   Void
* RETURNS
*   MMI_TRUE/MMI_FALSE
*****************************************************************************/
MMI_BOOL srv_da_is_drm_require_processing( const applib_mime_type_struct *type )
{
    return srv_da_is_drm_file(type);
}


/*****************************************************************************
* FUNCTION
*   srv_da_is_drm_file
* DESCRIPTION
*   check if it is a drm_file
* PARAMETERS
*   Void
* RETURNS
*   MMI_TRUE/MMI_FALSE
*****************************************************************************/

MMI_BOOL srv_da_is_drm_file( const applib_mime_type_struct *type )
{
    if (type &&
        (
    #ifdef __DRM_V01__
         type->mime_subtype == MIME_SUBTYPE_DRM_MESSAGE ||
         type->mime_subtype == MIME_SUBTYPE_DRM_RIGHTS_XML ||
         type->mime_subtype == MIME_SUBTYPE_DRM_RIGHTS_WBXML ||
         type->mime_subtype == MIME_SUBTYPE_DRM_CONTENT ||
    #endif
    #ifdef __DRM_V02__
         type->mime_subtype == MIME_SUBTYPE_DRM_CONTENT_V2 ||
         type->mime_subtype == MIME_SUBTYPE_ROAP_PDU ||
         type->mime_subtype == MIME_SUBTYPE_ROAP_TRIGGER ||
         type->mime_subtype == MIMI_SUBTYPE_PROTECTED_RO ||
    #endif
         MMI_FALSE ))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*   srv_da_is_drm_right
* DESCRIPTION
*   check if it is a drm_file
* PARAMETERS
*   Void
* RETURNS
*   MMI_TRUE/MMI_FALSE
*****************************************************************************/
MMI_BOOL srv_da_is_drm_right( const applib_mime_type_struct *type )
{
    if (type &&
        (
    #ifdef __DRM_V01__
          type->mime_subtype == MIME_SUBTYPE_DRM_RIGHTS_XML ||
          type->mime_subtype == MIME_SUBTYPE_DRM_RIGHTS_WBXML ||
    #endif
    #ifdef __DRM_V02__
          type->mime_subtype == MIMI_SUBTYPE_PROTECTED_RO ||
    #endif
          MMI_FALSE ))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*   srv_da_is_drm_content
* DESCRIPTION
*   check if it is a drm_file
* PARAMETERS
*   Void
* RETURNS
*   MMI_TRUE/MMI_FALSE
*****************************************************************************/
MMI_BOOL srv_da_is_drm_content( const applib_mime_type_struct *type )
{
    if (type &&
        (
    #ifdef __DRM_V01__
          type->mime_subtype == MIME_SUBTYPE_DRM_MESSAGE ||
          type->mime_subtype == MIME_SUBTYPE_DRM_CONTENT ||
    #endif
     #ifdef __DRM_V02__
          type->mime_subtype == MIME_SUBTYPE_DRM_CONTENT_V2 ||
     #endif
          MMI_FALSE))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*   srv_da_is_drm_roap
* DESCRIPTION
*   check if it is a drm_file
* PARAMETERS
*   Void
* RETURNS
*   MMI_TRUE/MMI_FALSE
*****************************************************************************/
MMI_BOOL srv_da_is_drm_roap(const applib_mime_type_struct *type )
{
    if (type && (
     #ifdef __DRM_V02__
          type->mime_subtype == MIME_SUBTYPE_ROAP_PDU ||
          type->mime_subtype == MIME_SUBTYPE_ROAP_TRIGGER ||
     #endif
          MMI_FALSE))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


#endif /* __DRM_SUPPORT__ */

#endif /* __MMI_DOWNLOAD_AGENT__ */
