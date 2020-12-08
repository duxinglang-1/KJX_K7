/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
* permission of MediaTek Inc. (C) 2005
*
* BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
* NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
* SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
* BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
* WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
* LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
* RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
* THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   j2me_msg_util.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements J2ME message handler utilities
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
 *
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
 *============================================================================
  ****************************************************************************/

/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "kal_release.h"
#include "jam_msg_handler.h"
#include "jam_internal.h"
#include "jma_internal.h"
#include "j2me_trace.h"

#include "JavaAgencyDef.h"
#include "JavaAgencyGProt.h"
#include "wgui_categories.h"
#include "MMI_features.h"
#include "gdi_include.h"
#include "jvm_interface.h"
#include "jvm_internal.h"
#include "jam_internal.h"
#include "gdi_image_gif.h"

#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#include "drm_def.h"
#endif /* __DRM_SUPPORT__ */ 
#include "GlobalDefs.h"
#include "mexe_struct.h"
#ifdef WAP_SEC_SUPPORT
#include "wps_struct.h"
#endif 
#include "FileManagerDef.h"
#include "app_str.h"
#include "jam_mvm_manager.h"


extern kal_mutexid g_jam_drm_mutex;
jam_drm_sd_callback_struct_t g_jam_drm_sd_callback_state;
kal_wchar* g_jam_drm_current_install_jar_path = NULL;

/*****************************************************************************
 * FUNCTION
 *  jam_drm_is_drm_file
 * DESCRIPTION
 *  to check if it is a drm file
 * PARAMETERS
 *  storage_name        [IN]        The filename in UCS2 format
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool jam_drm_is_drm_file(kal_wchar *storage_name)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DRM_get_object_method(0, storage_name) != DRM_METHOD_NONE)
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
#else /* __DRM_SUPPORT__ */ 
    return KAL_FALSE;
#endif /* __DRM_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_check_right
 * DESCRIPTION
 *  to check if this file have suitable permission.
 * PARAMETERS
 *  storage_name        [IN]        The filename in UCS2 format
 *  permission          [IN]        Permission
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool jam_drm_check_right(kal_wchar *storage_name, kal_uint8 permission)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DRM_validate_permission(0, storage_name, permission);
#else /* __DRM_SUPPORT__ */ 
    return KAL_TRUE;
#endif /* __DRM_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_start_consume
 * DESCRIPTION
 *  Use thie function to consume right.
 * PARAMETERS
 *  storage_name        [IN]        Filename
 *  permission          [IN]        
 *  callback            [IN]        This callback will be invoke when the right is invalid
 *  permissione(?)      [IN]        Permission
 * RETURNS
 *  > 0  sucess, return consume_id
 *  = 0  not drm file
 *  < 0  fail
 *****************************************************************************/
kal_int32 jam_drm_start_consume(
            kal_wchar *storage_name,
            kal_uint8 permission,
            void (*callback) (kal_int32 result, kal_int32 id))
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    kal_int32 consume_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!jam_drm_is_drm_file(storage_name))
    {
        /* not drm file */
        return -1;
    }

    handle = DRM_open_file(storage_name, FS_READ_ONLY | FS_OPEN_SHARED, permission);

    if (handle >= 0)
    {
        consume_id = DRM_consume_rights(handle, permission, callback);
        kal_trace(TRACE_INFO, FUNC_JAM_DRM_START,consume_id);
        DRM_close_file(handle);
        return consume_id;
    }
    else
    {
        DRM_close_file(handle);
        return -1;
    }

#else /* __DRM_SUPPORT__ */ 
    return 0;
#endif /* __DRM_SUPPORT__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_stop_consume
 * DESCRIPTION
 *  Use this function to stop consume
 * PARAMETERS
 *  consume_id      [IN]        
 *  drm_id(?)       [IN]        Consume id
 * RETURNS
 *  J2ME_NO_ERROR
 *****************************************************************************/
kal_int32 jam_drm_stop_consume(kal_int32 consume_id)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, FUNC_JAM_DRM_STOP,consume_id);
    DRM_stop_consume(consume_id);
    return J2ME_NO_ERROR;
#else /* __DRM_SUPPORT__ */ 
    return J2ME_NO_ERROR;
#endif /* __DRM_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_pause_consume
 * DESCRIPTION
 *  Use this function to pause consume
 * PARAMETERS
 *  consume_id      [IN]        
 *  drm_id(?)       [IN]        Drm_id
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jam_drm_pause_consume(kal_int32 consume_id)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, FUNC_JAM_DRM_PAUSE,consume_id);
    DRM_pause_consume(consume_id);
    return J2ME_NO_ERROR;
#else /* __DRM_SUPPORT__ */ 
    return J2ME_NO_ERROR;
#endif /* __DRM_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_resume_consume
 * DESCRIPTION
 *  Use this function to resume consume
 * PARAMETERS
 *  consume_id      [IN]        
 *  drm_id(?)       [IN]        Drm_id
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jam_drm_resume_consume(kal_int32 consume_id)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, FUNC_JAM_DRM_RESUME,consume_id);

    DRM_resume_consume(consume_id);
    return J2ME_NO_ERROR;
#else /* __DRM_SUPPORT__ */ 
    return J2ME_NO_ERROR;
#endif /* __DRM_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_get_content_ext
 * DESCRIPTION
 *  Use this function to get extension name of odf file.
 *  Caller should prepare the memory space for ext
 * PARAMETERS
 *  storage_name        [?]         
 *  ext                 [?]         
 *  drm_id(?)           [IN]        Drm_id
 * RETURNS
 *  void
 *****************************************************************************/
void jam_drm_get_content_ext(kal_wchar *storage_name, kal_wchar *ext)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *ansii_ext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, FUNC_JAM_DRM_GET_CONTEXT);

    ansii_ext = DRM_get_content_ext(NULL, storage_name);

    if (ansii_ext != NULL)
    {
        app_asc_str_to_ucs2_str((kal_int8*) ext, (kal_int8*) ansii_ext);
    }
    else
    {
        app_ucs2_strcpy((kal_int8*) ext, (kal_int8*) "");
    }

#endif /* __DRM_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_midlet_consume_callback
 * DESCRIPTION
 * PARAMETERS
 *  result      [IN]        
 *  id          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void jam_drm_midlet_consume_callback(kal_int32 result, kal_int32 consume_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 vm_id = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_id = jam_mvm_get_vm_id_by_drm_consume_id(consume_id);
    if (vm_id >= 0)
    {
        jam_stopVMExternal(vm_id);
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_midlet_start_consume
 * DESCRIPTION
 *  Use this function to check if the input file is a DRM file with
 *  executable prmission and consume the executino right.
 * PARAMETERS
 *  storage_name        [IN]        Filename
 *  permission(?)       [IN]        Permission
 * RETURNS
 *  KAL_FALSE : the file dose not have executable permission
 *  KAL_TRUE : the file does not exist or the file can be executed.
 *****************************************************************************/
kal_int32 jam_drm_midlet_start_consume(kal_wchar *storage_name,kal_int32* error_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 handler = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DRM_SUPPORT__
    kal_take_mutex(g_jam_drm_mutex);

    if (jam_drm_is_drm_file(storage_name))
    {
        if (jam_drm_check_right(storage_name, DRM_PERMISSION_EXECUTE))
        {
            handler = jam_drm_start_consume(storage_name, DRM_PERMISSION_EXECUTE, jam_drm_midlet_consume_callback);
            if (handler >= 0)
            {
                kal_trace(TRACE_INFO, FUNC_JAM_DRM_MIDLET_START_CONSUME_1, handler);
                kal_give_mutex(g_jam_drm_mutex);
                *error_code = J2ME_NO_ERROR;
                return -1;
            }
            kal_trace(TRACE_INFO,FUNC_JAM_DRM_MIDLET_START_CONSUME_2,handler);
        }
        kal_trace(TRACE_INFO, FUNC_JAM_DRM_MIDLET_START_CONSUME_3, handler);
        kal_give_mutex(g_jam_drm_mutex);
        *error_code = J2ME_DRM_PROHIBIT;
        return -1;
    }
    kal_give_mutex(g_jam_drm_mutex);
    *error_code = J2ME_NO_ERROR;
    return handler;
#else /* __DRM_SUPPORT__ */ 
    *error_code = J2ME_NO_ERROR;
    return handler;
#endif /* __DRM_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_midlet_stop_consume
 * DESCRIPTION
 *  Use this function to stop consume
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jam_drm_midlet_stop_consume(kal_int32 consume_id)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_jam_drm_mutex);

    if (consume_id >= 0)
    {
        kal_trace(TRACE_INFO, FUNC_JAM_DRM_MIDLET_STOP_CONSUME, consume_id);
        DRM_stop_consume(consume_id);
        consume_id = -1;
    }

    kal_give_mutex(g_jam_drm_mutex);

    return J2ME_NO_ERROR;
#else /* __DRM_SUPPORT__ */ 
    return J2ME_NO_ERROR;
#endif /* __DRM_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_midlet_pause_consume
 * DESCRIPTION
 *  Use this function to pause consume
 * PARAMETERS
 *  void
 *  drm_id(?)       [IN]        Drm_id
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jam_drm_midlet_pause_consume(kal_int32 consume_id)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_jam_drm_mutex);

    if (consume_id >= 0)
    {
        kal_trace(TRACE_INFO, FUNC_JAM_DRM_MIDLET_PAUSE_CONSUME, consume_id);
        DRM_pause_consume(consume_id);
    }
    kal_give_mutex(g_jam_drm_mutex);

    return J2ME_NO_ERROR;
#else /* __DRM_SUPPORT__ */ 
    return J2ME_NO_ERROR;
#endif /* __DRM_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_midlet_resume_consume
 * DESCRIPTION
 *  Use this function to resume consume
 * PARAMETERS
 *  void
 *  drm_id(?)       [IN]        Drm_id
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jam_drm_midlet_resume_consume(kal_int32 consume_id)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_take_mutex(g_jam_drm_mutex);

    if (consume_id >= 0)
    {
        kal_trace(TRACE_INFO, FUNC_JAM_DRM_MIDLET_RESUME_CONSUME, consume_id);
        DRM_resume_consume(consume_id);
    }

    kal_give_mutex(g_jam_drm_mutex);

    return J2ME_NO_ERROR;
#else /* __DRM_SUPPORT__ */ 
    return J2ME_NO_ERROR;
#endif /* __DRM_SUPPORT__ */ 
}

#ifdef __DRM_SUPPORT__
#define JAVA_RIGHT_FILENAME "j#a#v#a#_#r#i#g#h#t.dr"


/*****************************************************************************
 * FUNCTION
 *  jam_drm_process_callback
 * DESCRIPTION
 * PARAMETERS
 *  serial          [IN]        
 *  result          [IN]        
 *  mime_type       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static kal_int32 g_jam_drm_process_serial = -1;
static kal_int32 g_jam_drm_process_result = DRM_RESULT_OK;

static void jam_drm_process_callback(kal_uint8 serial, kal_int32 result, applib_mime_type_struct *mime_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (serial != g_jam_drm_process_serial)
    {
        return;
    }
    g_jam_drm_process_result = result;
}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_process
 * DESCRIPTION
 *  This function is only used by jam_drm_decode_jar_file for asynchronous DRM processing.
 * PARAMETERS
 *  file_path       [IN]        Not processed DRM file.
 *  new_path        [IN]        The file path to put processed DRM file.
 *  buffer_size     [IN]        
 * RETURNS
 *  J2ME_USER_CANCEL if user cancel the DRM decoding process
 *  DRM_PROC_RESULT_OK if the DRM file is processed successfully.
 *  Other DRM error code may be returned also.
 *****************************************************************************/
static kal_int32 jam_drm_process(kal_wchar *file_path, kal_wchar *new_path, kal_int32 buffer_size)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 serial;
    kal_int32 process_result;
    kal_bool first = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  process:

    /* process two times */
    if (first)
    {
        kal_int32 attr = FS_GetAttributes((const WCHAR*)file_path);
        if (attr & FS_ATTR_READ_ONLY)
        {
            FS_SetAttributes((const WCHAR*)file_path, (kal_uint8) (attr & ~(FS_ATTR_READ_ONLY)));
        }
        process_result = DRM_install_object(
                            (kal_uint8*) "application/vnd.oma.drm.message",
                            file_path,
                            KAL_FALSE,
                            new_path,
                            buffer_size,
                            &serial,
                            NULL,
                            jam_drm_process_callback);

    }
    else
    {
        process_result = DRM_install_object(
                            (kal_uint8*) "application/vnd.oma.drm.content",
                            file_path,
                            KAL_FALSE,
                            new_path,
                            buffer_size,
                            &serial,
                            NULL,
                            jam_drm_process_callback);

    }

    g_jam_drm_process_serial = serial;

    if (process_result == DRM_PROC_ENCRYPT_BUSY)
    {
        g_jam_drm_process_result = DRM_PROC_ENCRYPT_BUSY;

        while (1)
        {

            if (clean_event() == J2ME_GET_NEXT_EVENT_ABORT)
            {
                if (DRM_async_cancel_process(serial) == KAL_FALSE)
                {
                    kal_trace(TRACE_INFO, FUNC_JAM_DRM_PROCESS_1, serial);
                }

                kal_sleep_task(10);

                if (new_path)
                {
                    FS_Delete(new_path);
                }

                g_jam_drm_process_serial = -1;
                return -(J2ME_USER_CANCEL);
            }

            if (g_jam_drm_process_result != DRM_PROC_ENCRYPT_BUSY)
            {
                process_result = g_jam_drm_process_result;
                break;
            }
            /* sleep a while to give FMT CPU resource for processing file */
            kal_sleep_task(100);
        }
    }

    g_jam_drm_process_serial = -1;

    if (process_result == DRM_RESULT_OK)
    {
        return DRM_RESULT_OK;
    }

    if (first)
    {
        kal_trace(TRACE_INFO, FUNC_JAM_DRM_PROCESS_2, process_result);
        first = KAL_FALSE;
        goto process;
    }
    kal_trace(TRACE_INFO, FUNC_JAM_DRM_PROCESS_3, process_result);
    return process_result;
}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_check_and_get_right
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 jam_drm_check_and_get_right(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool permission = KAL_TRUE;
    kal_wchar *rights_issuer = NULL;
    kal_wchar *right_filename = NULL;
    kal_char *buffer = NULL;
    kal_uint32 buffer_size = 0;
    kal_int32 returnCode = FS_NO_ERROR;
    kal_uint8 serial;
    kal_bool need_to_close_http = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(handle >= 0);

    permission = DRM_validate_permission(handle, NULL, DRM_PERMISSION_EXECUTE);

    if (permission)
    {
        /* permission OK */
        returnCode = J2ME_NO_ERROR;
        kal_trace(TRACE_INFO, FUNC_JAM_DRM_CHECK_AND_GET_RIGHT_1);
        goto success;
    }

    if (DRM_get_object_method(handle, NULL) != DRM_METHOD_SEPARATE_DELIVERY &&
        DRM_get_object_method(handle, NULL) != DRM_METHOD_V2)
    {
        /* no permission , and cannot get rihgt */
        returnCode = DRM_PROCESS_ERROR;
        kal_trace(TRACE_INFO, FUNC_JAM_DRM_CHECK_AND_GET_RIGHT_2);
        goto fail;
    }

    if (DRM_get_rights_issuer(handle, NULL, &buffer_size) != DRM_RESULT_OK || buffer_size == 0)
    {
        returnCode = DRM_PROCESS_ERROR;
        kal_trace(TRACE_INFO, FUNC_JAM_DRM_CHECK_AND_GET_RIGHT_3);
        goto fail;
    }

    buffer = (kal_char*) get_ctrl_buffer(buffer_size);
    DRM_get_rights_issuer(handle, buffer, &buffer_size);

    if (strncmp(buffer, "http", 4) != 0)    /* no http:// */
    {
        rights_issuer = (kal_wchar*) get_ctrl_buffer((buffer_size + 7) * 2);
        kal_wsprintf(rights_issuer, "%s%s", "http://", buffer);
    }
    else
    {
        rights_issuer = (kal_wchar*) get_ctrl_buffer(buffer_size * 2);
        kal_wsprintf(rights_issuer, "%s", buffer);
    }

    right_filename =
        (kal_wchar*) get_ctrl_buffer((strlen(work_sys_dir_path) + strlen(JAVA_RIGHT_FILENAME) + 1 + 1) *
                                      ENCODING_LENGTH);

    kal_wsprintf(right_filename, "%s\\%s", work_sys_dir_path, JAVA_RIGHT_FILENAME);

    if (!jnw_http_active(KAL_TRUE, J2ME_HTTP_INSTALL_APP_ID))
    {
        /* it means we will open http channel for this function */
        need_to_close_http = KAL_TRUE;
        jnw_http_initialize(J2ME_HTTP_INSTALL_APP_ID);
    }

    returnCode = jam_request_http_and_save_to_file(0, rights_issuer, right_filename, NULL, 0, 0);

    if (need_to_close_http)
    {
        jnw_http_finalize(J2ME_HTTP_INSTALL_APP_ID);
    }

    if (returnCode != JAM_HTTP_NO_ERROR)
    {
        kal_trace(TRACE_INFO, FUNC_JAM_DRM_CHECK_AND_GET_RIGHT_4,returnCode);
        if (returnCode == JAM_HTTP_USER_CANCEL)
        {
            returnCode = -J2ME_USER_CANCEL;
        }
        else
        {
            returnCode = DRM_PROCESS_ERROR;
        }
        goto fail;
    }
    /* process right */

    returnCode = DRM_install_object(
                    (kal_uint8*) "application/vnd.oma.drm.rights+wbxml",
                    (kal_wchar*) right_filename,
                    KAL_FALSE,
                    NULL,
                    0,
                    &serial,
                    NULL,
                    NULL);
    if (returnCode == DRM_RESULT_OK)
    {
        kal_trace(TRACE_INFO, FUNC_JAM_DRM_CHECK_AND_GET_RIGHT_5);

        goto success;
    }
    kal_trace(TRACE_INFO, FUNC_JAM_DRM_CHECK_AND_GET_RIGHT_6,returnCode);
    returnCode = DRM_install_object(
                    (kal_uint8*) "application/vnd.oma.drm.rights+xml",
                    (kal_wchar*) right_filename,
                    KAL_FALSE,
                    NULL,
                    0,
                    &serial,
                    NULL,
                    NULL);

    if (returnCode != DRM_RESULT_OK)
    {
        kal_trace(TRACE_INFO, FUNC_JAM_DRM_CHECK_AND_GET_RIGHT_7,returnCode);
        returnCode = DRM_PROCESS_ERROR;
        goto fail;
    }
    kal_trace(TRACE_INFO, FUNC_JAM_DRM_CHECK_AND_GET_RIGHT_8);

  success:
    returnCode = J2ME_NO_ERROR;

  fail:

    if (buffer)
    {
        free_ctrl_buffer(buffer);
    }
    if (rights_issuer)
    {
        free_ctrl_buffer(rights_issuer);
    }
    if (right_filename)
    {
        free_ctrl_buffer(right_filename);
    }

    return returnCode;

}

#endif /* __DRM_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  jam_drm_decode_file
 * DESCRIPTION
 *  Use this function to decode the downloaded DRM file
 *  and get file size of the original file (decrypted file size).
 * PARAMETERS
 *  file_name                   [?]         [?]        Input the UCS2 jar file path (full path)
 *  force_encoded_as_dcf        [IN]        Deprecated!!! Please do not set this to KAL_TRUE.
 * RETURNS
 *  the decrypted file size, or
 *  DRM_INVALID_FORMAT if it is not a DRM file
 *  DRM_PROCESS_ERROR if it is a DRM file but decoding failed.
 *  J2ME_USER_CANCEL if user cancel this procedure.
 *****************************************************************************/
kal_int32 jam_drm_decode_file(kal_wchar *file_name, kal_bool force_encoded_as_dcf)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 returnValue = DRM_INVALID_FORMAT;
    kal_int32 str_len;
    kal_wchar *temp_path = NULL;
    kal_int32 i;
    kal_int32 handle = FS_FILE_NOT_FOUND;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str_len = get_ucs2_len(file_name);
    temp_path = get_ctrl_buffer((str_len + 1) << 1);
    memcpy(temp_path, file_name, (str_len + 1) << 1);

    /* renaming */
    i = str_len;
    while (temp_path[i] != '\\' && i > 0)
    {
        i--;
    }
    if (temp_path[i] == '\\')
    {
        temp_path[i + 1] = '-';
    }
    else
    {
        returnValue = DRM_INVALID_FORMAT;
        kal_trace(TRACE_INFO, FUNC_JAM_DRM_DECODE_FILE_1);
        goto final;
    }

    /* many case here
       1. this is a drm file and not process yet
       a. success
       b. fail   => to case 3
       2. this is a drm file but processed
       a. forward lock         -- will process fail
       b. combine delivery     -- will process fail
       c. seperate             -- will process success
       3. this is not a drm file   -- will process fail   */

    handle = DRM_open_file(file_name, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_EXECUTE);
    if (handle < FS_NO_ERROR)
    {
        returnValue = DRM_INVALID_FORMAT;
        kal_trace(TRACE_INFO, FUNC_JAM_DRM_DECODE_FILE_2);
        goto final;
    }

    if ((DRM_get_object_method(handle, NULL)) != DRM_METHOD_NONE)
    {
        /* case 2 */
        kal_uint8 *content_type;
        kal_uint32 org_file_size;

        /* if we use SD callback we don't need to acquire right here */
    #ifdef __JBLENDIA__ 
    /* because Jblendia doesn't support SD call back, they will use original method to get right*/
        returnValue = jam_drm_check_and_get_right(handle);
        if (returnValue != J2ME_NO_ERROR)
        {
            goto final;
        }
    #endif 
        /* reload the information */
        DRM_close_file(handle);
        handle = DRM_open_file(file_name, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_EXECUTE);
        content_type = DRM_get_content_type(handle, NULL);

        if (content_type != NULL &&
            (strcmp((char*)content_type, "application/java-archive") == 0 ||
             strcmp((char*)content_type, "text/vnd.sun.j2me.app-descriptor") == 0))
        {
            returnValue = DRM_file_size(handle, (kal_uint32*) & org_file_size);

            if (returnValue == FS_NO_ERROR)
            {
                kal_trace(TRACE_INFO, FUNC_JAM_DRM_DECODE_FILE_3,org_file_size);
                returnValue = org_file_size;
                goto final;
            }
            else
            {
                kal_trace(TRACE_INFO, FUNC_JAM_DRM_DECODE_FILE_4,returnValue);
                returnValue = DRM_PROCESS_ERROR;
                goto final;
            }
        }
        else
        {
            if (content_type)
            {
                kal_trace(TRACE_INFO, FUNC_JAM_DRM_DECODE_FILE_5);
            }
            else
            {
                kal_trace(TRACE_INFO, FUNC_JAM_DRM_DECODE_FILE_6);
            }

            returnValue = DRM_PROCESS_ERROR;
            goto final;
        }
    }

    DRM_close_file(handle);
    handle = FS_FILE_NOT_FOUND;

    if ((returnValue = jam_drm_process(file_name, temp_path, (str_len + 1) << 1)) == DRM_RESULT_OK)
    {
        /* case 1 , rarely come here */
        kal_uint8 *content_type;
        kal_int32 org_file_size = DRM_PROCESS_ERROR;

        kal_trace(TRACE_INFO, FUNC_JAM_DRM_DECODE_FILE_7);

        returnValue = FS_Move(temp_path, file_name, FS_MOVE_KILL | FS_MOVE_OVERWRITE, NULL, NULL, 0);

        if (returnValue < FS_NO_ERROR)
        {
            kal_trace(TRACE_INFO, FUNC_JAM_DRM_DECODE_FILE_8);
            goto final;
        }

        handle = DRM_open_file(file_name, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_EXECUTE);

        ASSERT(handle >= FS_NO_ERROR);
        /* get right */
        returnValue = jam_drm_check_and_get_right(handle);
        if (returnValue != J2ME_NO_ERROR)
        {
            goto final;
        }
        /* reload the information */
        DRM_close_file(handle);
        handle = DRM_open_file(file_name, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_EXECUTE);

        content_type = DRM_get_content_type(handle, NULL);

        if (content_type != NULL &&
            (strcmp((char*)content_type, "application/java-archive") == 0 ||
             strcmp((char*)content_type, "text/vnd.sun.j2me.app-descriptor") == 0))
        {
            returnValue = DRM_file_size(handle, (kal_uint32*) & org_file_size);

            if (returnValue == FS_NO_ERROR)
            {
                kal_trace(TRACE_INFO, FUNC_JAM_DRM_DECODE_FILE_9,org_file_size);
                returnValue = org_file_size;
                goto final;
            }
            else
            {
                kal_trace(TRACE_INFO, FUNC_JAM_DRM_DECODE_FILE_10,returnValue);
                returnValue = DRM_PROCESS_ERROR;
                goto final;
            }
        }
        else
        {
            if (content_type)
            {
                kal_trace(TRACE_INFO, FUNC_JAM_DRM_DECODE_FILE_11,content_type);
            }
            else
            {
                kal_trace(TRACE_INFO, FUNC_JAM_DRM_DECODE_FILE_12);
            }

            returnValue = DRM_PROCESS_ERROR;
            goto final;
        }

    }
    else
    {
        /* user cancel */
        if (returnValue == -(J2ME_USER_CANCEL))
        {
            kal_trace(TRACE_INFO, FUNC_JAM_DRM_DECODE_FILE_13);
            goto final;
        }

        /* case 3 */
        returnValue = DRM_INVALID_FORMAT;
        goto final;
    }

  final:
    if (temp_path)
    {
        free_ctrl_buffer(temp_path);
    }
    if (handle >= FS_NO_ERROR)
    {
        DRM_close_file(handle);
    }
    return returnValue;

#else /* __DRM_SUPPORT__ */ 
    return DRM_INVALID_FORMAT;
#endif /* __DRM_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_send_waiting_right_start
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jam_drm_send_waiting_right_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_waiting_right_start_req_struct *waiting_right_start_msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* kal_sleep_task(5000); */
    waiting_right_start_msg = construct_local_para(sizeof(mmi_java_waiting_right_start_req_struct), TD_CTRL);
    check_incoming_call_and_block();
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_WAITING_RIGHT_START_REQ,waiting_right_start_msg);
}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_send_waiting_right_end
 * DESCRIPTION
 *  
 * PARAMETERS
 *  success     [IN]        
 * RETURNS
 *  kal_bool  the sending success or not(?)
 *****************************************************************************/
void jam_drm_send_waiting_right_end(kal_bool success)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_waiting_right_end_req_struct *waiting_right_end_msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    waiting_right_end_msg = construct_local_para(sizeof(mmi_java_waiting_right_end_req_struct), TD_CTRL);
    waiting_right_end_msg->success = success;
    java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_WAITING_RIGHT_END_REQ,waiting_right_end_msg);    
}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_copy_to_receive
 * DESCRIPTION
 *  This function will copy a DRM jar file to "Received" folder with it's MIDlet suite name.
 * PARAMETERS
 *  midlet_name     [IN]        MIDlet name
 *  source_path     [IN]        The source path of the downloaded DRM jar file
 * RETURNS
 *  0 if success
 *  -1 if error
 *****************************************************************************/
kal_int32 jam_drm_copy_to_receive(kal_wchar *midlet_name, kal_wchar *source_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *dest_path = jvm_malloc(MAX_WCHAR_FILENAME_LEN);
    kal_int32 temp_len = strlen("Received");
    kal_int32 midlet_len = get_ucs2_len(midlet_name);
    kal_int32 return_code = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (midlet_len > MAX_WCHAR_FILENAME_LEN - 20)
        return -1;
    dest_path[0] = source_path[0];
    dest_path[1] = ':';
    dest_path[2] = '\\';
    trans_utf8_to_ucs2(dest_path + 3, "Received");
    FS_CreateDir(dest_path);    /* don't care if it has been created successfully */
    dest_path[3 + temp_len] = '\\';
    memcpy(dest_path + 4 + temp_len, midlet_name, midlet_len << 1);
    trans_utf8_to_ucs2(dest_path + 4 + temp_len + midlet_len, ".jar");
    return_code = FS_Move(source_path, dest_path, FS_MOVE_KILL | FS_MOVE_OVERWRITE, NULL, NULL, 0);
    jvm_free(dest_path);
    return return_code;
}


/*****************************************************************************
 * FUNCTION
 *  encrypt_jar_file
 * DESCRIPTION
 *  Use this function to encode JAR file to protect the JAR from copying.
 *  The raw data without decoding will be only noise file.
 * PARAMETERS
 *  jar_file        [?]     [?]         Input the UCS2 jar file path (full path)
 *  return_size     [?]     Size to be returned.
 * RETURNS
 *  error code
 *****************************************************************************/
#ifdef ENCRYPT_JAR_FILE
kal_int32 encrypt_jar_file(kal_wchar *jar_file, kal_int32 *return_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 handle;
    kal_int32 file_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = FS_Open(jar_file, FS_OPEN_SHARED | FS_READ_WRITE);
    if (handle >= 0)
    {
        kal_int32 return_code;

        file_size = FS_Seek(handle, 0, SEEK_END);
        return_code = encrypt_file(handle);
        FS_Close(handle);
        if (return_code == J2ME_NO_ERROR)
        {
            *return_size = file_size;
        }
        else
        {
            *return_size = -1;
        }
        return return_code;
    }
    else
    {
        return J2ME_ACTION_FAILE;
    }
}
#endif /* ENCRYPT_JAR_FILE */ 


/*****************************************************************************
 * FUNCTION
 *  jam_drm_right_ready
 * DESCRIPTION
 *  query if get right completed.
 * PARAMETERS
 *  void
 * RETURNS
 *  error code
 *****************************************************************************/
kal_bool jam_drm_right_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_bool)g_jam_drm_sd_callback_state.get_right_completed;
}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_set_waiting_time
 * DESCRIPTION
 *  query if get right completed.
 * PARAMETERS
 *  time            [IN]        
 *  time_string     [?]         
 * RETURNS
 *  error code(?)
 *****************************************************************************/
void jam_drm_set_waiting_time(kal_int32 time, kal_char *time_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_jam_drm_sd_callback_state.wait_time = -1;
    if (time)
    {
        g_jam_drm_sd_callback_state.wait_time = time;
    }
    else
    {
        if (time_string)
        {
            g_jam_drm_sd_callback_state.wait_time = jvm_util_atoi(time_string);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_register_SD_callback
 * DESCRIPTION
 *  when install a DRM protect JAR file, but no right. It can call this function
 *  to register SD call back for waiting right.
 * PARAMETERS
 *  file_name       [IN]        Drm file path
 *  jad_url         [?]         
 * RETURNS
 *  error code
 *****************************************************************************/ 
kal_int32 jam_drm_register_SD_callback(kal_wchar *temp_jad_file_name, kal_wchar *temp_jar_file_name, kal_wchar *jad_url, kal_wchar *jar_url)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 return_code = J2ME_NO_ERROR;
    kal_wchar *input_file_name = NULL;
    kal_int32 input_file_name_len = 0;
    kal_int32 r1 = 0;
    kal_int32 r2 = 0;
    kal_wchar *source_file_name = NULL;
    kal_int32 source_file_name_len = 0;
    kal_int32 drm_file_handle = -1;
    kal_bool is_future_right = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, JAM_DRM_REGISTER_SD_CALLBACK);
    input_file_name_len = get_ucs2_len(temp_jar_file_name);
    /*  */
    if ((temp_jar_file_name[1] == ':' || temp_jar_file_name[0] == '\\') && (temp_jar_file_name[input_file_name_len-1] == 'r' || temp_jar_file_name[input_file_name_len-1] == 'R'))
    {
        input_file_name = get_ctrl_buffer((input_file_name_len + 1) << 1);
        memcpy(input_file_name, temp_jar_file_name, (input_file_name_len + 1) << 1);
    }
    else
    {
        source_file_name_len = strlen(work_dir_path) + get_ucs2_len(temp_jar_file_name);
        source_file_name = get_ctrl_buffer((source_file_name_len + 2) << 1);
        if (temp_jar_file_name[1] == ':' || temp_jar_file_name[0] == '\\')
        {
            kal_wsprintf(source_file_name, "\0");
        }
        else
        {
            kal_wsprintf(source_file_name, "%s\\\0", work_dir_path);
        }
        mmi_ucs2cat((CHAR *) source_file_name, (const CHAR *) temp_jar_file_name);
        /* need to rename here, because all jad installation jar name _temp.jar */
        if (jad_url)
        {
            input_file_name_len = get_ucs2_len(jad_url);
            input_file_name = get_ctrl_buffer((input_file_name_len + 1) << 1);
            mmi_ucs2cpy((CHAR *) input_file_name, (CHAR *) jad_url);
            if (input_file_name[input_file_name_len - 2]  == 'a')
            {
                input_file_name[input_file_name_len - 1] = 'r';
            }
            else
            {
                input_file_name[input_file_name_len - 1] = 'R';
            }
            if (FS_Move(source_file_name, input_file_name, FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0) != FS_NO_ERROR)
            {
                free_ctrl_buffer(source_file_name);
                free_ctrl_buffer(input_file_name);
                return DISK_OPERATION_FAIL;
            }
            else
            {
                kal_int32 attribute = FS_GetAttributes(input_file_name);
                FS_SetAttributes(input_file_name, (BYTE) (attribute | (FS_ATTR_HIDDEN)));
            }
            free_ctrl_buffer(source_file_name);
            /* we will set mmi_jar_file_name here, so that mmi will help java to delete file */
            mmi_java_set_jar_file_name(input_file_name);
        }
        else
        {
            /* midlet message format */
            drm_file_handle = DRM_open_file(source_file_name, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_EXECUTE);
            is_future_right = DRM_validate_future_permission(drm_file_handle,DRM_PERMISSION_EXECUTE);
            r2 = DRM_validate_permission(drm_file_handle, NULL, DRM_PERMISSION_EXECUTE);
            DRM_close_file(drm_file_handle);
            if (is_future_right || r2)
            {
                return J2ME_NO_ERROR;
            }
            input_file_name_len = get_ucs2_len(jar_url);
            input_file_name = get_ctrl_buffer((input_file_name_len + 1) << 1);
            mmi_ucs2cpy((CHAR *) input_file_name, (CHAR *) jar_url);            
            if (FS_Move(source_file_name, input_file_name, FS_MOVE_KILL | FS_MOVE_OVERWRITE, NULL, NULL, 0) != FS_NO_ERROR)
            {
                free_ctrl_buffer(source_file_name);
                free_ctrl_buffer(input_file_name);
                return DISK_OPERATION_FAIL;
            }

            if (input_file_name[input_file_name_len - 2]  == 'a')
            {
                input_file_name[input_file_name_len - 1] = 'd';
            }
            else
            {
                input_file_name[input_file_name_len - 1] = 'D';
            }
            if (FS_Move(temp_jad_file_name, input_file_name, FS_MOVE_KILL | FS_MOVE_OVERWRITE, NULL, NULL, 0) != FS_NO_ERROR)
            {
                free_ctrl_buffer(source_file_name);
                free_ctrl_buffer(input_file_name);
                return DISK_OPERATION_FAIL;
            }
            /* we will set mmi_jad_file_name here, so that mmi will help java to delete file */
            mmi_java_set_jad_file_name(input_file_name);

            if (input_file_name[input_file_name_len - 2]  == 'a')
            {
                input_file_name[input_file_name_len - 1] = 'r';
            }
            else
            {
                input_file_name[input_file_name_len - 1] = 'R';
            }
            
        }
        free_ctrl_buffer(source_file_name);
        source_file_name = NULL;
    }


    r1 = DRM_is_drm_file(NULL, input_file_name);

    if (!r1)
    {
        kal_trace(TRACE_INFO, JAM_DRM_REGISTER_SD_CALLBACK_NO_WAIT, r1, r2);
        free_ctrl_buffer(input_file_name);
		input_file_name = NULL;
        return J2ME_NO_ERROR;
    }
    else
    {
        /* we will set mmi_jar_file_name here, so that mmi will help java to delete file */
        mmi_java_set_jar_file_name(input_file_name);
        if ((DRM_METHOD_SEPARATE_DELIVERY & DRM_get_object_method(NULL, input_file_name)))
        {
            drm_file_handle = DRM_open_file(input_file_name, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_EXECUTE);
            is_future_right = DRM_validate_future_permission(drm_file_handle,DRM_PERMISSION_EXECUTE);
            DRM_close_file(drm_file_handle);

            if (is_future_right)
            {
                kal_trace(TRACE_INFO,JAM_DRM_REGISTER_SD_CALLBACK_FUTURE_RIGHT);
                free_ctrl_buffer(input_file_name);
				input_file_name = NULL;
                return J2ME_NO_ERROR;
            }
            
           
            r2 = DRM_validate_permission(NULL, input_file_name, DRM_PERMISSION_EXECUTE);
            if (r2)
            {
                kal_trace(TRACE_INFO, JAM_DRM_REGISTER_SD_CALLBACK_NO_WAIT, r1, r2);
                free_ctrl_buffer(input_file_name);
				input_file_name = NULL;
                return J2ME_NO_ERROR;
            }
        }
        else
        {
            kal_trace(TRACE_INFO, JAM_DRM_REGISTER_SD_CALLBACK_NO_WAIT, r1, r2);
            free_ctrl_buffer(input_file_name);
			input_file_name = NULL;
            return J2ME_NO_ERROR;
        }
        
    }
    
    if (g_jam_drm_current_install_jar_path)
    {
        jam_listmem_free(g_jam_drm_current_install_jar_path);
    }
    g_jam_drm_current_install_jar_path = jam_listmem_malloc((input_file_name_len + 1) << 1);
    memcpy(g_jam_drm_current_install_jar_path,input_file_name,(input_file_name_len + 1) << 1);
    g_jam_drm_sd_callback_state.need_acquire_right = KAL_FALSE;


    if (g_jam_drm_sd_callback_state.wait_time != -1 && jad_url)
    {
        g_jam_drm_sd_callback_state.waiting_right_serial = DRM_register_sd_callback(
                                                                input_file_name,
                                                                g_jam_drm_sd_callback_state.wait_time,
                                                                input_file_name,
                                                                jam_drm_recv_right_handler);
        kal_trace(TRACE_INFO, JAM_DRM_REGISTER_SD_CALLBACK_RESULT, g_jam_drm_sd_callback_state.waiting_right_serial);
        if (g_jam_drm_sd_callback_state.waiting_right_serial >= 0)
        {
            jam_drm_send_waiting_right_start();
            g_jam_drm_sd_callback_state.get_right_completed = JAM_DRM_WAIT_RIGHT;
            /* R005 Justin: indent */
            while (!g_jam_drm_sd_callback_state.get_right_completed)
            {
                if (clean_event() == J2ME_GET_NEXT_EVENT_ABORT)
                {
                    return_code = J2ME_DRM_NO_RIGHT;
                    break;
                }
                kal_sleep_task(10);
            }
        }
        else
        {
            return_code = J2ME_DRM_NO_RIGHT;
        }
    }
    else
    {
        g_jam_drm_sd_callback_state.waiting_right_serial = DRM_register_sd_callback(
                                                                input_file_name,
                                                                DRM_DEFAULT_UNLIMITED_WAIT,
                                                                input_file_name,
                                                                jam_drm_recv_right_handler);
        g_jam_drm_sd_callback_state.need_acquire_right = KAL_TRUE;
        return_code = J2ME_DRM_NO_RIGHT;
    }

    if (g_jam_drm_sd_callback_state.get_right_completed == JAM_DRM_NO_RIGHT)
    {
        return_code = J2ME_DRM_NO_RIGHT;
        jam_drm_send_waiting_right_end(KAL_FALSE);
    }
    else
    {
        jam_drm_send_waiting_right_end(KAL_TRUE);
    }
    return return_code;
#else
    return J2ME_NO_ERROR;
#endif /* __DRM_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  jam_drm_recv_right_handler
 * DESCRIPTION
 *  when right is received by DRM manager, it will call this callback function.
 * PARAMETERS
 *  para        [IN]        Drm file path
 *  type        [IN]        Condition of DRM SD call back
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jam_drm_recv_right_handler(void *para, kal_uint8 type)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_push_install_ind_struct *push_install_ind_ptr;
    FS_HANDLE drm_file_handle;
    kal_bool is_future_right= KAL_FALSE;
    kal_bool is_valided = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, JAM_DRM_RECV_RIGHT_HANDLER, type);

    drm_file_handle = DRM_open_file(para, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_EXECUTE);
    is_future_right = DRM_validate_future_permission(drm_file_handle,DRM_PERMISSION_EXECUTE);
    is_valided = DRM_validate_permission(drm_file_handle, NULL, DRM_PERMISSION_EXECUTE);
    DRM_close_file(drm_file_handle);
    if (!is_future_right || !is_valided)
    {
         return KAL_FALSE;
    }

    if (g_jam_drm_current_install_jar_path &&
        (mmi_ucs2cmp((CHAR *) para, (CHAR *) g_jam_drm_current_install_jar_path)) == 0)
    {
        if (type == DRM_SD_EXPIRY_RIGHTS_ARRIVE)
        {
            /* do nothing */
            g_jam_drm_sd_callback_state.get_right_completed = JAM_DRM_RIGHT_RECIEVED;
            jam_listmem_free(para);
            return KAL_TRUE;
        }
        else if (type == DRM_SD_EXPIRY_TIMEOUT)
        {
            /* ask user acquire right or not */
            /* eric function */
            g_jam_drm_sd_callback_state.get_right_completed = JAM_DRM_NO_RIGHT;
            g_jam_drm_sd_callback_state.need_acquire_right = KAL_TRUE;
            /* register again waiting forever */
            return KAL_FALSE;
        }
        else if (type == DRM_SD_EXPIRY_RECORD_REPLACE)
        {
            /* ask Eric what to do */
            g_jam_drm_sd_callback_state.get_right_completed = JAM_DRM_NO_RIGHT;
            return KAL_FALSE;
        }
        else if (type == DRM_SD_EXPIRY_ERROR)
        {
            g_jam_drm_sd_callback_state.get_right_completed = JAM_DRM_NO_RIGHT;
            /* register again waiting forever */
            return KAL_FALSE;
        }
        
    }
    else
    {
        if (type == DRM_SD_EXPIRY_RIGHTS_ARRIVE)
        {
            /* send message to MMI */

            push_install_ind_ptr = (mmi_java_push_install_ind_struct*)
                construct_local_para(sizeof(mmi_java_push_install_ind_struct), TD_CTRL);
            push_install_ind_ptr->push_install_type = 1;
            push_install_ind_ptr->drm_file_path =
                (kal_wchar*) get_ctrl_buffer((get_ucs2_len((kal_wchar*) para) + 1) << 1);
            mmi_ucs2cpy((CHAR *) push_install_ind_ptr->drm_file_path, (CHAR *) para);
            java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_PUSH_INSTALL_IND,push_install_ind_ptr);    
            jam_listmem_free(para);
            return KAL_TRUE;
        }
        else if (type == DRM_SD_EXPIRY_TIMEOUT || type == DRM_SD_EXPIRY_ERROR)
        {
            /* register again waiting forever */
            return KAL_FALSE;
        }
    }
#endif /* __DRM_SUPPORT__ */ 
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  jam_drm_recv_right_handler
 * DESCRIPTION
 *  when right is received by DRM manager, it will call this callback function.
 * PARAMETERS
 *  para        [IN]        Drm file path
 *  type        [IN]        Condition of DRM SD call back
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jam_drm_check_content_type(kal_wchar* file_name)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *input_file_name = NULL;
    kal_int32 input_file_name_len = 0;
    kal_uint8 *content_type = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (file_name[1] == ':' || file_name[0] == '\\')
    {
        input_file_name_len = get_ucs2_len(file_name);
        input_file_name = get_ctrl_buffer((input_file_name_len + 1) << 1);
        memcpy(input_file_name, file_name, (input_file_name_len + 1) << 1);
    }
    else
    {
        input_file_name_len = strlen(work_dir_path) + get_ucs2_len(file_name);
        input_file_name = get_ctrl_buffer((input_file_name_len + 2) << 1);
        kal_wsprintf(input_file_name, "%s\\\0", work_dir_path);
        mmi_ucs2cat((CHAR *) input_file_name, (CHAR *) file_name);
    }

    if (DRM_is_drm_file(NULL, input_file_name))
    {
        content_type = DRM_get_content_type(NULL, input_file_name);

        if (content_type != NULL)
        {
            if(strcmp((char*)content_type, "application/java-archive") != 0 &&
                strcmp((char*)content_type, "application/java") != 0 &&
                strcmp((char*)content_type, "application/x-java-archive") != 0)
            {
                free_ctrl_buffer(input_file_name);
                return KAL_FALSE;
            }
        }
    }
    free_ctrl_buffer(input_file_name);
#endif /* __DRM_SUPPORT__ */ 
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  jam_drm_can_be_send
 * DESCRIPTION
 *  Query mids is DRM protected and separate dilver file.
 * PARAMETERS
 *  para        [IN]        Drm file path
 *  type        [IN]        Condition of DRM SD call back
 * RETURNS
 *  void
 *****************************************************************************/
 kal_bool jam_drm_can_be_send(kal_int32 mids_id)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *wfilename = NULL;
    kal_bool result = KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wfilename = jam_call_back_functions.jam_get_jar_storage_name_from_mids_id(jam_listmem_malloc, mids_id);
    if (wfilename != NULL)
    {

        if (DRM_is_drm_file(NULL, (kal_wchar*)wfilename) && DRM_interdev_movable(NULL, (kal_wchar*)wfilename))
        {
            result = KAL_TRUE;
        }

        jam_listmem_free(wfilename);
    }
    return result;
#else
    return KAL_FALSE;
#endif
}

#ifdef __DRM_SUPPORT__

kal_int32 jam_mvm_vm_drm_init(kal_int32 vm_id)
{
    kal_int32 consume_id = -1;
    kal_int32 returnCode = J2ME_NO_ERROR;
    kal_wchar* jar_path = jam_mvm_get_vm_jar_path(vm_id);
    if(jar_path != NULL)
    {
        consume_id = jam_drm_midlet_start_consume(jar_path,&returnCode);
        if(returnCode!= J2ME_NO_ERROR)
        {
            return DRM_PROHIBIT;
        }
    }
    jam_mvm_set_vm_consume_id(vm_id, consume_id);
    return J2ME_NO_ERROR;
}
kal_int32 jam_mvm_vm_drm_deinit(kal_int32 vm_id)
{
    kal_int32 returnCode = J2ME_NO_ERROR;
    kal_int32 consume_id = jam_mvm_get_vm_consume_id(vm_id);
    if(consume_id != -1)
        returnCode = jam_drm_midlet_stop_consume(consume_id);
    return returnCode;
}
#endif

