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
 * RightsMgrSrv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements Alarm service management.
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



****************************************************************************/
#include "MMI_include.h"

/*****************************************************************************
* Header files
*****************************************************************************/
#ifdef __MMI_RMGR__

#include "nvram_common_defs.h"
#include "RightsMgrGProt.h"
/*Akhil*/
#include "Drm_errcode.h"
#ifdef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_vapp_rmgr_def.h"
#else
#include "Mmi_rp_app_rmgr_def.h"
#endif
#include "FileMgrSrvGProt.h"  //Akhil
#include "RightsMgrSrv.h"
#include "FileMgrGProt.h"
#include "FileManagerDef.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "Drm_trace.h"
#include "drm_gprot.h"
//#include "drm_msg.h"
#include "drm_memory.h"
#include "drm_ui.h"
#include "drm_util.h"
#include "drm_trace.h"

#define RMGR_UTIL_TRC DRM_UI_DEBUG

static const mmi_fmgr_fs_error_info_struct mmi_rmgr_err_table[] =
{
    {DRM_RESULT_NON_DRM,             STR_GLOBAL_DRM_NON_DRM},
    {DRM_RESULT_FS_ERROR,            STR_GLOBAL_DRM_FS_ERROR},
    {DRM_RESULT_INVALID_FORMAT,      STR_GLOBAL_DRM_INVALID_FORMAT},
    {DRM_RESULT_NO_PERMISSION,       STR_GLOBAL_DRM_PROHIBITED},
#ifndef __MMI_SLIM_FILE_MANAGER__
    {DRM_RESULT_SIZE_TOO_BIG,        FMGR_FS_FILE_TOO_LARGE_TEXT},
    {DRM_RESULT_FILE_EXISTS,         FMGR_FS_FILE_EXISTS_TEXT},
#endif
    {DRM_RESULT_INVALID_PARA,        FMGR_FS_PARAM_ERROR_TEXT},
#ifndef __MMI_SLIM_FILE_MANAGER__
    {DRM_RESULT_TOO_MANY_FILES,      FMGR_FS_TOO_MANY_FILES_TEXT},
#endif
    {DRM_RESULT_NOT_SUPPORT,         STR_GLOBAL_NOT_SUPPORTED},
    
    {DRM_RESULT_BAD_CONTENT_TYPE,    STR_GLOBAL_INVALID_FORMAT},
    {DRM_RESULT_INVALID_KEY,         STR_ID_DRM_INVALID_KEY},
    {DRM_RESULT_INVALID_RIGHT,       STR_ID_DRM_INVALID_RO},


    {DRM_RESULT_EOF,                 STR_ID_DRM_EOF},
    {DRM_RESULT_TRUNCATED,           STR_ID_DRM_TRUNCATED},
    {DRM_RESULT_BUSY,                STR_GLOBAL_BUSY_TRY_LATER},
    {DRM_RESULT_CANCELED,            FMGR_FS_ABORTED_ERROR_TEXT},

#if __DRM_V02__    
    {DRM_RESULT_KEY_NOT_FOUND,       STR_ID_DRM_KEY_NOT_FOUND},
    {DRM_RESULT_CERT_NOT_FOUND,      STR_ID_DRM_CERT_NOT_FOUND},
    {DRM_RESULT_CERT_ROOT_NOT_FOUND, STR_ID_DRM_CERT_ROOT_NOT_FOUND},
    {DRM_RESULT_CERT_EXPIRED,        STR_ID_DRM_CERT_EXPIRED},
    {DRM_RESULT_INVALID_CERT,        STR_ID_DRM_INVALID_CERT},
    {DRM_RESULT_DOMAIN_EXPIRED,      STR_ID_DRM_DOMAIN_EXPIRED},
    {DRM_RESULT_NEED_DOMAIN_UPGD,    STR_ID_DRM_NEED_DOMAIN_UPGD},
    {DRM_RESULT_INVALID_DRMTIME,     STR_ID_DRM_INVALID_DRMTIME},
    {DRM_RESULT_NETWORK_ERROR,       STR_ID_DRM_NETWORK_ERROR},
    {DRM_RESULT_DATABASE_ERROR,      STR_ID_DRM_DATABASE_ERROR},
    {DRM_RESULT_TIME_UNTRUSTED,      STR_ID_DRM_TIME_UNTRUSTED},
    {DRM_RESULT_DATA_NOT_FOUND,      STR_ID_DRM_NOT_FOUND},
    {DRM_RESULT_NO_MEMORY,           STR_ID_DRM_NO_MEMORY},
    {DRM_RESULT_NOT_ARCHIVE,         STR_ID_DRM_NOT_ARCHIVE},
    {DRM_RESULT_NOT_IN_DOMAIN,       STR_ID_DRM_NOT_IN_DOMAIN},
    {DRM_RESULT_NOT_REGISTERED,      STR_ID_DRM_NOT_REGISTERED},
    {DRM_RESULT_REGISTRATION_FAILED, STR_ID_DRM_REG_FAILED},
    {DRM_RESULT_JOIN_DOMAIN_FAILED,  STR_ID_DRM_DOMAIN_JOIN_FAILED},
    {DRM_RESULT_LEAVE_DOMAIN_FAILED, STR_ID_DRM_DOMAIN_LEAVE_FAILED},
#endif

    {DRM_RESULT_DB_LOCKED,           STR_ID_DRM_DB_LOCKED_BY_APP},
    {DRM_RESULT_NO_RIGHTS_SPACE,     STR_ID_DRM_NO_RIGHT_SPACE},
    {DRM_RESULT_UNKNOWN_ERROR,       STR_ID_DRM_PROCESS_ERROR},
    {0, 0}
};



/*****************************************************************************
 * FUNCTION
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void srv_rmgr_show_process_info(S32 result, MMI_BOOL waiting, mmi_rmgr_src_enum src, applib_mime_type_struct *type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str;
	srv_rmgr_dlagent_evt_struct entry_dlhndlr_msg_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*---------------------------------------------------------------- */
    RMGR_UTIL_TRC("[RMGR] srv_rmgr_show_process_info %d %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_SHOW_PROCESS_INFO, result, waiting, src));

/* only in DRM V02 version, we will save some information in buffer */
#ifdef __DRM_V02__
    if (mmi_drm_need_show_info())
    {
        mmi_drm_show_info();
    }
    else
#endif
    {
        rmgr_space_check_user = 1;

        if(result == DRM_RESULT_OK)
        {
            if( type != NULL )
            {
                switch(type->mime_subtype)
                {
                    case MIME_SUBTYPE_DRM_CONTENT:
                    case MIME_SUBTYPE_DRM_MESSAGE:
                    case MIME_SUBTYPE_DRM_CONTENT_V2:
                        str = STR_GLOBAL_DONE;
                        break;
                    case MIME_SUBTYPE_DRM_RIGHTS_XML:
                    case MIME_SUBTYPE_DRM_RIGHTS_WBXML:
                    case MIMI_SUBTYPE_PROTECTED_RO:

                        /* if someone waiting, and the source is push,
                           we need not popup "Licence received" */
#ifdef __COSMOS_MMI_PACKAGE__
                        if ((waiting && src == MMI_RMGR_SRC_PUSH))
#else
						if ((waiting && src == MMI_RMGR_SRC_PUSH) || (mmi_frm_scrn_get_active_id() == SCR_ID_RMGR_USE_NOW_CONFIRM))
#endif
                        {
                            return;
                        }

                        str = STR_ID_RMGR_ACTIVATE_COMPLETED;

                        break;
                    case MIME_SUBTYPE_ROAP_PDU:
                    case MIME_SUBTYPE_ROAP_TRIGGER:
                        str = STR_GLOBAL_DONE;
                        break;
                    default:
                        str = STR_GLOBAL_DONE;
                }
            }
            else
            {
                str = STR_GLOBAL_DONE;
            }

        //Emit event for showing popup in Rights Manager app
	    MMI_FRM_INIT_EVENT(&entry_dlhndlr_msg_evt, EVT_ID_SRV_RMGR_DL_NOTIFY);
        entry_dlhndlr_msg_evt.str_id = str;
        entry_dlhndlr_msg_evt.evt_type= MMI_EVENT_SUCCESS;
        MMI_FRM_CB_EMIT_POST_EVENT(&entry_dlhndlr_msg_evt);
        }
        else
        {
           // //Emit event for showing popup in Rights Manager app
	    MMI_FRM_INIT_EVENT(&entry_dlhndlr_msg_evt, EVT_ID_SRV_RMGR_DL_NOTIFY);
        entry_dlhndlr_msg_evt.str_id = (U16)srv_fmgr_fs_error_get_string(result);
        entry_dlhndlr_msg_evt.evt_type= MMI_EVENT_FAILURE;
        MMI_FRM_CB_EMIT_POST_EVENT(&entry_dlhndlr_msg_evt);
        }
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_get_err_string
 * DESCRIPTION
 *  to provide string ID associated to error code
 * PARAMETERS
 *
 * RETURNS
 *
 *****************************************************************************/
MMI_ID_TYPE srv_rmgr_get_err_string(S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; mmi_rmgr_err_table[i].errorNo != 0; i++)
    {
        if (mmi_rmgr_err_table[i].errorNo == error)
        {
            return mmi_rmgr_err_table[i].stringId;
        }
    }

    return STR_ID_DRM_PROCESS_ERROR;

}



/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_check_forward
 * DESCRIPTION
 *  To get forward rule of input file path
 * PARAMETERS
 *  file_path       [IN]     file path
 * RETURNS
 *  combination of result (bit mask)
 *  MMI_RMGR_USAGE_DRM: this is a DRM content
 *  MMI_RMGR_USAGE_SEND: this content can be sent via network applications
 *  MMI_RMGR_USAGE_SET: this content can be set as automated usage
 *  negative value: Otherwise, error code
 *****************************************************************************/
S32 srv_rmgr_check_forward(U16 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    U8 permission = DRM_PERMISSION_NONE;
    FS_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_check_forward",
            (TRACE_GROUP_UI, RMGR_UTIL_CHECK_FORWARD));

    handle = DRM_open_file(file_path, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_NONE);

    if (handle < DRM_RESULT_OK)
    {
        return handle;
    }

    if (!DRM_is_drm_file(handle, NULL))
    {
        result |= MMI_RMGR_USAGE_SEND;
        result |= MMI_RMGR_USAGE_SET;

        DRM_close_file(handle);
    }
    else
    {
        permission = drm_get_permission_ext(DRM_get_content_type_entry(handle));

        DRM_close_file(handle);

        handle = DRM_open_file(file_path, FS_READ_ONLY | FS_OPEN_SHARED, permission);

        if (handle > FS_NO_ERROR)
        {
            if (DRM_interdev_movable(handle, NULL))
            {
                result |= MMI_RMGR_USAGE_SEND;
            }

            if (DRM_validate_forward_rule(handle, permission))
            {
                result |= MMI_RMGR_USAGE_SET;
            }

            DRM_close_file(handle);
        }
        else
        {
            /* open file fail */
            result = handle;
        }
    }


    return result;
}


#endif // __MMI_RMGR__
