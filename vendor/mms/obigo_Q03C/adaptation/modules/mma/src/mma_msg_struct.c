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
 * mma_msg_struct.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains utility functions used for message structure.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef _MMA_MSG_STRUCT_C
#define _MMA_MSG_STRUCT_C

#if defined(MMS_SUPPORT)
#include "MMI_features.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h" 
#include "stack_ltlcom.h"
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "custom_wap_config.h"
#include "mmsadp.h"
#include "mma_api.h"
#include "mms_api.h"
#include "mma_struct.h"
#include "mmc_struct.h"
#include "mms_adp_struct.h"
#include "mms_sap_struct.h"

#include "EngineerModeInetAppGprot.h"  /* Added for Engineer Mode */

/* APPLIB */
#include "app_str.h"
#include "app_mine.h"
#include "app_usedetails.h"
#include "app_datetime.h"

/* FS service */
#include "fat_fs.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"

#include "drm_def.h"
#include "drm_gprot.h"

/* PLUTOMMI / GDI */
#include "MMIDataType.h"
#include "gdi_include.h"
#include "gdi_const.h"
#include "Conversions.h"

#include "msf_lib.h"    /* MSF: ANSI Standard libs allowed to use */
#include "msf_cfg.h"    /* MSF: Module definition */
#include "msf_def.h"    /* MSF: Global definitions */
#include "msf_core.h"   /* MSF: System core call */
#include "msf_dcvt.h"   /* MSF: Type conversion routines */
#include "msf_mem.h"    /* MSF: Memory handling */
#include "msf_log.h"    /* MSF: Signal logging */
#include "msf_cmmn.h"   /* MSF: MSF common functions, e.g. string handling */
#include "msf_file.h"   /* MSF: File handling */
#include "msf_chrs.h"   /* MSF: Charset handling */
#include "msf_mime.h"

#include "mms_cfg.h"    /* MMS: Configuration definitions */
#include "mms_def.h"    /* MMS: Exported types in adapter/connector functions */
#include "mms_if.h"     /* MMS: Exported signal interface */
#include "mutils.h"
#include "mmsl_if.h"
/* SLS */
#include "mma_smil.h"
//#include "sls_cfg.h"
//#include "sls_def.h"
//#include "sls_if.h"
//#include "sls_main.h"

/* MMA Service */
#include "mma_smil.h"
#include "mma_cfg.h"
#include "mma_def.h"
#include "mma_mime.h"
#include "mma_msg_struct.h"
#include "mma_utilities.h"
#include "mma_msgmgr.h"
#include "mma_parse.h"
#include "mma_main.h"
#include "app_ua.h"
/***************************************************************************** 
* Define
*****************************************************************************/
#define MMA_CHARSET_CHECK_BOM_SIZE 100

#define MMA_TEXT_SIZE_NAME_STR      "fontsize"
#define MMA_TEXT_COLOR_NAME_STR     "foregroundcolor"
#define MMA_TEXT_COLOR__NAME_STR    "foreground-color"
#define MMA_TEXT_STYLE_NAME_STR     "fontstyle"
/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local static Variable
*****************************************************************************/

static const SlsCharsetItem supportedCharsets[] = SLS_CFG_SUPPORTED_CHARSET;
static const mma_charset_item supportedCharsetsStr[] = MMA_SUPPORTED_CHARSET;

static const mma_text_size_parse_struct supported_mma_text_size[] = 
{
    {"large", MMA_TEXT_SIZE_LARGE},
    {"normal", MMA_TEXT_SIZE_MEDIUM},
    {"small", MMA_TEXT_SIZE_SMALL},
    {NULL, MMA_TEXT_SIZE_MEDIUM}
};

static const mma_text_style_parse_struct supported_mma_text_style[] = 
{
    {"bold", MMA_TEXT_STYLE_BOLD},
    {"italic", MMA_TEXT_STYLE_ITALIC},
    {NULL, MMA_TEXT_STYLE_BOLD}
};

/***************************************************************************** 
* Local Function
*****************************************************************************/



/*****************************************************************************
 * FUNCTION
 *  mma_get_mmi_file_size
 * DESCRIPTION
 *  Get file size by using MMI UCS2 filename
 * PARAMETERS
 *  file_handle   [IN] DRM_open_file() return value. If < 0, use filepath instead
 *  filepath        [IN]        
 * RETURNS
 *  file size
 *****************************************************************************/
kal_uint32 mma_get_mmi_file_size(FS_HANDLE file_handle, const kal_wchar *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 fh;
    kal_uint32 size = 0;
	/* we should not used DRM api to get size as discussed with Eric the DRM Owner.*/
	/* DRM Api not return proper size. In FS use no use of file_handle. As its DRM file_handle.*/
	kal_bool need_fs_api_to_get_size = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(need_fs_api_to_get_size)
	{
		fh = FS_Open((kal_wchar *)filepath, FS_READ_ONLY | FS_OPEN_SHARED);
    
		if(fh >= 0)
		{
			FS_GetFileSize(fh, &size);
			FS_Close(fh);
		}
	}
	else
    {
        if (file_handle >= 0)
        {
            fh = file_handle;
        }
        else
        {
            fh = DRM_open_file((kal_wchar *)filepath, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_NONE);
        }
        
        if(fh >= 0)
        {
            DRM_file_size(fh, &size);
            if (file_handle < 0)
            {
                DRM_close_file(fh);
            }
        }
    }

    return size;
}


/*****************************************************************************
 * FUNCTION
 *  translate_fs_result_to_mma
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_result_enum translate_fs_result_to_mma(int result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case MSF_FILE_OK:
            return MMA_RESULT_OK;
        case MSF_FILE_ERROR_ACCESS:
            return MMA_RESULT_FAIL_FILE_IN_USE;
        case MSF_FILE_ERROR_DELAYED:
            return MMA_RESULT_DELAYED;
        case MSF_FILE_ERROR_PATH:
            return MMA_RESULT_FAIL_FILE_NOT_FOUND;
        case MSF_FILE_ERROR_FULL:
            return MMA_RESULT_FAIL_INSUFFICIENT_STORAGE;
        case MSF_FILE_ERROR_ROOT_DIR_FULL:
            return MMA_RESULT_FAIL_ROOT_DIR_FULL;
        case MSF_FILE_ERROR_INVALID:
        case MSF_FILE_ERROR_EOF:
        case MSF_FILE_ERROR_EXIST:
        case MSF_FILE_ERROR_SIZE:
        default:
            return MMA_RESULT_FAIL_FILE_IO; /* An unknown error */
    }
}


/*****************************************************************************
 * FUNCTION
 *  translate_mms_result_to_mma
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_result_enum translate_mms_result_to_mma(MmsResult result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case MMS_RESULT_OK:
        case MMS_RESULT_OK_MEM_FULL:
            return MMA_RESULT_OK;

        case MMS_RESULT_DELAYED:
            return MMA_RESULT_DELAYED;

        case MMS_RESULT_BUSY:
            return MMA_RESULT_FAIL_BUSY;

        case MMS_RESULT_BUFFER_FULL:
        case MMS_RESULT_INSUFFICIENT_MEMORY:
            return MMA_RESULT_FAIL_INSUFFICIENT_MEMORY;

        case MMS_RESULT_INSUFFICIENT_PERSISTENT_STORAGE:
            return MMA_RESULT_FAIL_INSUFFICIENT_STORAGE;
        
        case MMS_RESULT_ERROR_ROOT_DIR_FULL:
            return MMA_RESULT_FAIL_ROOT_DIR_FULL;

        case MMS_RESULT_COMM_FILE_NOT_FOUND:
        case MMS_RESULT_FILE_NOT_FOUND:
        case MMS_RESULT_MESSAGE_ID_NOT_FOUND:
        case MMS_RESULT_WRONG_FILE_TYPE:
            return MMA_RESULT_FAIL_FILE_NOT_FOUND;

        case MMS_RESULT_INDEX_FILE_ERROR:
        case MMS_RESULT_INFO_FILE_ERROR:
        case MMS_RESULT_MESSAGE_CORRUPT:
        case MMS_RESULT_MESSAGE_EMPTY:
            return MMA_RESULT_FAIL_FILE_CORRUPTED;

        case MMS_RESULT_FILE_READ_ERROR:
        case MMS_RESULT_FILE_WRITE_ERROR:
        case MMS_RESULT_EOF:
            return MMA_RESULT_FAIL_FILE_IO;

        case MMS_RESULT_FOLDER_NOT_FOUND:
            return MMA_RESULT_FAIL_FOLDER_NOT_FOUND;

        case MMS_RESULT_INVALID_ADDRESS:
        case MMS_RESULT_INVALID_APPLICATION_HEADER:
        case MMS_RESULT_INVALID_CONTENT_ID:
        case MMS_RESULT_INVALID_CONTENT_LOCATION:
        case MMS_RESULT_INVALID_CONTENT_TYPE:
        case MMS_RESULT_INVALID_EXPIRY_TIME:
        case MMS_RESULT_INVALID_HEADER_SIZE:
        case MMS_RESULT_INVALID_MSG_CLASS:
        case MMS_RESULT_INVALID_REPLY_CHARGING_DEADLINE:
        case MMS_RESULT_INVALID_SIZE:
        case MMS_RESULT_INVALID_SUBJECT:
        case MMS_RESULT_INVALID_VERSION:
        case MMS_RESULT_INVALID_DATE:
        case MMS_RESULT_TRANSACTION_ID_MISSING:
            return MMA_RESULT_FAIL_UNSUPPORT_CONTENT;

        case MMS_RESULT_COMM_ENTITY_TOO_LARGE:
            return MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED;
        case MMS_RESULT_BODY_PART_NOT_FOUND:
        case MMS_RESULT_COMM_HEADER_TAG:
        case MMS_RESULT_COMM_ILLEGAL_PDU:
        case MMS_RESULT_COMM_LIMITATIONS_NOT_MET:
        case MMS_RESULT_COMM_UNEXPECTED_MESSAGE:
        case MMS_RESULT_COMM_UNSUPPORTED_MEDIA_TYPE:
        case MMS_RESULT_COMM_UNSUPPORTED_VERSION:
        case MMS_RESULT_COMM_URI_TOO_LARGE:
            return MMA_RESULT_FAIL_COMM_UNSUPPORT_CONTENT;

        case MMS_RESULT_CONFIG_ERROR:
            return MMA_RESULT_FAIL_COMM_CONFIG_ERROR;

        case MMS_RESULT_COMM_ADDRESS_UNRESOLVED:
        case MMS_RESULT_COMM_BAD_GATEWAY:
        case MMS_RESULT_COMM_PROXY_ERROR:
        case MMS_RESULT_COMM_SECURITY_ERROR:
        case MMS_RESULT_COMM_TRANSACTION_ID:
            return MMA_RESULT_FAIL_COMM_CONNECT_ERROR;

        case MMS_RESULT_COMM_TIMEOUT:
            return MMA_RESULT_FAIL_COMM_SERVER_TIMEOUT;

        case MMS_RESULT_COMM_SERVER_ERROR:
        case MMS_RESULT_COMM_MMSC_VERSION:
            return MMA_RESULT_FAIL_COMM_SERVER_ERROR;

        case MMS_RESULT_COMM_UNAUTHORIZED:
            return MMA_RESULT_FAIL_COMM_UNAUTHORIZED;

        case MMS_RESULT_COMM_UNAVAILABLE:
        case MMS_RESULT_COMM_FORBIDDEN:
            return MMA_RESULT_FAIL_COMM_SERVICE_DENIED;

        case MMS_RESULT_COMM_FAILED:
            return MMA_RESULT_FAIL_COMM_CONNECT_ERROR;

        case MMS_RESULT_CANCELLED_BY_USER:
            return MMA_RESULT_FAIL_USER_CANCEL;

        case MMS_RESULT_MAX_RETRIEVAL_SIZE_EXCEEDED:
            return MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED;

        case MMS_RESULT_TOO_MANY_MSG:
            return MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED;

		case MMS_RESULT_MSG_EXPIRED:
            return MMA_RESULT_FAIL_MSG_EXPIRED;

        case MMS_RESULT_MESSAGE_UNSUPPORTED:
            return MMA_RESULT_FAIL_UNSUPPORT_MMS_TYPE;

        case MMS_RESULT_ERROR_MEM_CARD_PLUG_OUT:
            return MMA_RESULT_FAIL_MEM_CARD_PLUG_OUT;

        default:
            return MMA_RESULT_FAIL; /* An unknown error */
    }
}


/*****************************************************************************
 * FUNCTION
 *  translate_sls_result_to_mma
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
 /*
mma_result_enum translate_sls_result_to_mma(SlsResult result)
{
    switch (result)
    {
        case SLS_RESULT_OK:
            return MMA_RESULT_OK;

        case SLS_RESULT_BUSY:
            return MMA_RESULT_FAIL_BUSY;

        case SLS_RESULT_FILE_DELAY:
            return MMA_RESULT_DELAYED;

        case SLS_RESULT_FILE_READ_FAILURE:
            return MMA_RESULT_FAIL_FILE_IO;

        case SLS_RESULT_BUFFER_FULL:
            return MMA_RESULT_FAIL_INSUFFICIENT_MEMORY;

        case SLS_RESULT_MISSING_BODY_PART:
        case SLS_RESULT_MISSING_MEDIA_OBJECTS:
        case SLS_RESULT_MISSING_MEDIA_OBJECT_SRC:
        case SLS_RESULT_SMIL_INVALID:
        case SLS_RESULT_SMIL_NOT_CREATED:
        case SLS_RESULT_PARSING_FAILED:
            return MMA_RESULT_FAIL_FILE_CORRUPTED;

        case SLS_RESULT_TO_MANY_SLIDES:
            return MMA_RESULT_FAIL_MAX_SLIDE_NUM_REACHED;

        case SLS_RESULT_ERROR:
        default:
            return MMA_RESULT_FAIL; 
    }
}
*/

/*****************************************************************************
 * FUNCTION
 *  translate_mms_folder_to_mma
 * DESCRIPTION
 *  This function is used to convert MMA folder definition to MMS folder definition
 * CALLS
 *  
 * PARAMETERS
 *  box     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_folder_enum translate_mms_folder_to_mma(MmsFolderType box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_folder_enum folder = MMA_FOLDER_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((box & MMS_INBOX) || box & MMS_NOTIFY)
    {
        folder |= MMA_FOLDER_INBOX;
    }

    if (box & MMS_SENT)
    {
        folder |= MMA_FOLDER_SENT;
    }

    if (box & MMS_OUTBOX)
    {
        folder |= MMA_FOLDER_OUTBOX;
    }

    if (box & MMS_DRAFTS)
    {
        folder |= MMA_FOLDER_DRAFT;
    }

    if (box & MMS_TEMPLATES)
    {
        folder |= MMA_FOLDER_TEMPLATE;
    }

    if (box & MMS_USRDEF_TEMPLATES)
    {
        folder |= MMA_FOLDER_USRDEF_TEMPLATE;
    }

    if (box & MMS_ARCHIVE)
    {
        folder |= MMA_FOLDER_ARCHIVE;
    }

    if (box & MMS_HIDDEN)
    {
        folder |= MMA_FOLDER_HIDDEN;
    } 

    return folder;
}


/*****************************************************************************
 * FUNCTION
 *  translate_mma_folder_to_mms
 * DESCRIPTION
 *  This function is used to convert MMA folder definition to MMS folder definition
 * CALLS
 *  
 * PARAMETERS
 *  box     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MmsFolderType translate_mma_folder_to_mms(mma_folder_enum box)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsFolderType folder = MMS_NO_FOLDER;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (box & MMA_FOLDER_INBOX)
    {
        folder |= MMS_INBOX;
    }

    if (box & MMA_FOLDER_SENT)
    {
        folder |= MMS_SENT;
    }

    if (box & MMA_FOLDER_OUTBOX)
    {
        folder |= MMS_OUTBOX;
    }

    if (box & MMA_FOLDER_DRAFT)
    {
        folder |= MMS_DRAFTS;
    }

    if (box & MMA_FOLDER_TEMPLATE)
    {
        folder |= MMS_TEMPLATES;
    }

    if (box & MMA_FOLDER_USRDEF_TEMPLATE)
    {
        folder |= MMS_USRDEF_TEMPLATES;
    }

    if (box & MMA_FOLDER_ARCHIVE)
    {
        folder |= MMS_ARCHIVE;
    }

    return folder;
}


/*****************************************************************************
 * FUNCTION
 *  translate_mms_priority_to_mma
 * DESCRIPTION
 *  This function is used to convert MMS priority definition to MMA priority definition
 * CALLS
 *  
 * PARAMETERS
 *  prio        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_priority_enum translate_mms_priority_to_mma(MmsPriority prio)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (prio)
    {
        case MMS_PRIORITY_NOT_SET:
            return MMA_PRIORITY_NOT_SET;
        case MMS_PRIORITY_LOW:
            return MMA_PRIORITY_LOW;
        case MMS_PRIORITY_NORMAL:
            return MMA_PRIORITY_MEDIUM;
        case MMS_PRIORITY_HIGH:
            return MMA_PRIORITY_HIGH;
        default:
            return MMA_PRIORITY_MEDIUM;
    }
}


/*****************************************************************************
 * FUNCTION
 *  translate_mma_priority_to_mms
 * DESCRIPTION
 *  This function is used to convert MMA priority definition to MMS priority definition
 * CALLS
 *  
 * PARAMETERS
 *  prio        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MmsPriority translate_mma_priority_to_mms(mma_priority_enum prio)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (prio)
    {
        case MMA_PRIORITY_NOT_SET:
            return MMS_PRIORITY_NOT_SET;
        case MMA_PRIORITY_LOW:
            return MMS_PRIORITY_LOW;
        case MMA_PRIORITY_MEDIUM:
            return MMS_PRIORITY_NORMAL;
        case MMA_PRIORITY_HIGH:
            return MMS_PRIORITY_HIGH;
        default:
            return MMS_PRIORITY_NORMAL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  translate_mms_expiry_to_mma
 * DESCRIPTION
 *  This function is used to convert MMS absolute/relative expiry definition to MMA relative expiry definition
 * CALLS
 *  
 * PARAMETERS
 *  type        [IN]        
 *  expiry      [IN]        
 *  then        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_expiry_time_enum translate_mms_expiry_to_mma(MmsTimeType type, MmsTimeSec expiry, MmsTimeSec then)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long diff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMS_TIME_ABSOLUTE == type)
    {
        diff = (long)(expiry - then);
    }
    else if (MMS_TIME_RELATIVE == type)
    {
        diff = (long)expiry;
    }
    else    /* ex. The field is absent: type = 0 */
    {
        return MMA_EXPIRY_MAX;
    }

    /*  Only positive values please */
    if (diff < 0)
    {
        diff = -diff;
    }

    if (diff <= MMA_1_HOUR_IN_SEC)
    {
        return MMA_EXPIRY_1_HOUR;
    }
    else if (diff > MMA_1_HOUR_IN_SEC && diff <= MMA_12_HOURS_IN_SEC)
    {
        return MMA_EXPIRY_12_HOURS;
    }
    else if (diff > MMA_12_HOURS_IN_SEC && diff <= MMA_1_DAY_IN_SEC)
    {
        return MMA_EXPIRY_1_DAY;
    }
    else if (diff > MMA_1_DAY_IN_SEC && diff <= MMA_1_WEEK_IN_SEC)
    {
        return MMA_EXPIRY_1_WEEK;
    }
    else
    {
        return MMA_EXPIRY_MAX;
    }
}


/*****************************************************************************
 * FUNCTION
 *  translate_mma_expiry_to_mms
 * DESCRIPTION
 *  This function is used to convert MMA relative expiry definition to MMS absolute/relative expiry definition
 * CALLS
 *  
 * PARAMETERS
 *  expiry      [IN]        
 *  now         [IN]        
 *  type        [OUT]       
 *  sec         [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void translate_mma_expiry_to_mms(mma_expiry_time_enum expiry, MmsTimeSec now, MmsTimeType *type, MmsTimeSec *sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsTimeSec base_sec = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*type == MMS_TIME_RELATIVE)
    {
        base_sec = 0;
    }
    else
    {
        base_sec = now;
    }

    *sec = base_sec + expiry;
}


/*****************************************************************************
 * FUNCTION
 *  translate_mms_delivery_to_mma
 * DESCRIPTION
 *  This function is used to convert MMS absolute/relative delivery time definition to
 *  MMA relative delivery time definition
 * CALLS
 *  
 * PARAMETERS
 *  type            [IN]        
 *  delivery        [IN]        
 *  then            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_delivery_time_enum translate_mms_delivery_to_mma(MmsTimeType type, MmsTimeSec delivery, MmsTimeSec then)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    long diff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMS_TIME_ABSOLUTE == type)
    {
        diff = (long)(delivery - then);
    }
    else if (MMS_TIME_RELATIVE == type)
    {
        diff = (long)delivery;
    }
    else    /* ex. The field is absent: type = 0 */
    {
        return MMA_DELIVERY_IMMEDIATE;
    }

    /*  Only positive values please */
    if (diff < 0)
    {
        diff = -diff;
    }

    if (diff <= MMA_1_HOUR_IN_SEC)
    {
        return MMA_DELIVERY_1_HOUR;
    }
    else if (diff > MMA_1_HOUR_IN_SEC && diff <= MMA_12_HOURS_IN_SEC)
    {
        return MMA_DELIVERY_12_HOURS;
    }
    else if (diff > MMA_12_HOURS_IN_SEC && diff <= MMA_1_DAY_IN_SEC)
    {
        return MMA_DELIVERY_24_HOURS;
    }
    else
    {
        return MMA_DELIVERY_24_HOURS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  translate_mma_delivery_to_mms
 * DESCRIPTION
 *  This function is used to convert MMA relative delivery definition to MMs relative/absolute expiry definition
 * CALLS
 *  
 * PARAMETERS
 *  delivery        [IN]        
 *  now             [IN]        
 *  type            [OUT]       
 *  sec             [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void translate_mma_delivery_to_mms(
        mma_delivery_time_enum delivery,
        MmsTimeSec now,
        MmsTimeType *type,
        MmsTimeSec *sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsTimeSec base_sec = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*type == MMS_TIME_RELATIVE)
    {
        base_sec = 0;
    }
    else
    {
        base_sec = now;
    }

    *sec = base_sec + delivery;
}


/*****************************************************************************
 * FUNCTION
 *  translate_mms_version_to_mma
 * DESCRIPTION
 *  This function is used to convert MMS version definition to MMA version definition
 * PARAMETERS
 *  version     [IN]        
 * RETURNS
 *  mma_version_enum
 *****************************************************************************/
mma_version_enum translate_mms_version_to_mma(MmsVersion version)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (version)
    {
        case MMS_VERSION_PREVIOUS_MAJOR:
            return MMA_VERSION_10;
        case MMS_VERSION_10:
            return MMA_VERSION_10;
        case MMS_VERSION_11:
            return MMA_VERSION_11;
        case MMS_VERSION_12:
            return MMA_VERSION_12;
        case MMS_VERSION_NEXT_MAJOR:
            return MMA_VERSION_12;
        default:
            return MMA_VERSION_10;
    }
}


/*****************************************************************************
 * FUNCTION
 *  translate_mma_version_to_mms
 * DESCRIPTION
 *  This function is used to convert MMA version definition to MMS version definition
 * PARAMETERS
 *  version     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MmsVersion translate_mma_version_to_mms(mma_version_enum version)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (version)
    {
        case MMA_VERSION_10:
            return MMS_VERSION_10;
        case MMA_VERSION_11:
            return MMS_VERSION_11;
        case MMA_VERSION_12:
            return MMS_VERSION_12;
        default:
            return MMS_VERSION_10;
    }
}


/*****************************************************************************
 * FUNCTION
 *  translate_mms_class_to_mma
 * DESCRIPTION
 *  This function is used to convert MMS message class definition to MMA message class definition
 * CALLS
 *  
 * PARAMETERS
 *  version     [IN]        
 *  prio(?)
 * RETURNS
 *  
 *****************************************************************************/
mma_msg_class_enum translate_mms_class_to_mma(MmsClassIdentifier version)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (version)
    {
        case MMS_MESSAGE_CLASS_PERSONAL:
            return MMA_MSG_CLASS_PERSONAL;
        case MMS_MESSAGE_CLASS_ADVERTISEMENT:
            return MMA_MSG_CLASS_ADVERTISEMENT;
        case MMS_MESSAGE_CLASS_INFORMATIONAL:
            return MMA_MSG_CLASS_INFORMATIONAL;
        case MMS_MESSAGE_CLASS_AUTO:
            return MMA_MSG_CLASS_AUTO;
        default:
            return MMA_MSG_CLASS_PERSONAL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  translate_mma_class_to_mms
 * DESCRIPTION
 *  This function is used to convert MMA message class definition to MMS message class definition
 * CALLS
 *  
 * PARAMETERS
 *  version     [IN]        
 *  prio(?)
 * RETURNS
 *  
 *****************************************************************************/
MmsClassIdentifier translate_mma_class_to_mms(mma_msg_class_enum classidentifier)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (classidentifier)
    {
        case MMA_MSG_CLASS_NOT_SET:
            return MMS_MESSAGE_CLASS_NOT_SET;

        case MMA_MSG_CLASS_PERSONAL:
            return MMS_MESSAGE_CLASS_PERSONAL;

        case MMA_MSG_CLASS_ADVERTISEMENT:
            return MMS_MESSAGE_CLASS_ADVERTISEMENT;

        case MMA_MSG_CLASS_INFORMATIONAL:
            return MMS_MESSAGE_CLASS_INFORMATIONAL;

        case MMA_MSG_CLASS_AUTO:
            return MMS_MESSAGE_CLASS_AUTO;

        default:
            return MMS_MESSAGE_CLASS_NOT_SET;
    }
}

/*****************************************************************************
 * FUNCTION
 *  trnslate_mma_type_to_mms
 * DESCRIPTION
 *  This function is used to convert MMA type to MMS type
 * CALLS
 *  
 * PARAMETERS
 *  version     [IN]        
 *  prio(?)
 * RETURNS
 *  
 *****************************************************************************/
MmsTimeType trnslate_mma_type_to_mms(mma_mms_time_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMA_MMS_TIME_ABSOLUTE:
            return MMS_TIME_ABSOLUTE;
        case MMA_MMS_TIME_RELATIVE:
            return MMS_TIME_RELATIVE;
        
        default:
            return MMS_TIME_RELATIVE;
    }
}
/*****************************************************************************
 * FUNCTION
 *  mma_str_to_text_size
 * DESCRIPTION
 *  This function is used to convert SLS text size definition to MMA text size definition
 * CALLS
 *  
 * PARAMETERS
 *  text_size_str       [IN]        
 *  size(?)
 * RETURNS
 *  
 *****************************************************************************/
mma_text_size_enum mma_str_to_text_size(const char *text_size_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mma_text_size_parse_struct *curr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr = supported_mma_text_size;

    while (curr->text_name != NULL)
    {
        if (msf_cmmn_strcmp_nc(curr->text_name, text_size_str) == 0)
        {
            return curr->text_size;
        }
        ++curr;
    }
    return MMA_TEXT_SIZE_MEDIUM;
}


/*****************************************************************************
 * FUNCTION
 *  mma_str_to_text_style
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text_style_str      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_text_style_enum mma_str_to_text_style(const char *text_style_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mma_text_style_parse_struct *curr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr = supported_mma_text_style;

    while (curr->text_name != NULL)
    {
        if (msf_cmmn_strcmp_nc(curr->text_name, text_style_str) == 0)
        {
            return curr->text_style;
        }
        ++curr;
    }
    return MMA_TEXT_STYLE_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_enum_to_text_size_str
 * DESCRIPTION
 *  This function is used to convert MMA text size definition to SLS text size definition
 * CALLS
 *  
 * PARAMETERS
 *  text_size       [IN]        
 *  size(?)
 * RETURNS
 *  
 *****************************************************************************/
const char *mma_enum_to_text_size_str(mma_text_size_enum text_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mma_text_size_parse_struct *curr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr = supported_mma_text_size;

    while (curr->text_name != NULL)
    {
        if (curr->text_size == text_size)
        {
            return curr->text_name;
        }
        ++curr;
    }
    return curr->text_name;
}


/*****************************************************************************
 * FUNCTION
 *  mma_enum_to_text_style_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  text_style      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const char *mma_enum_to_text_style_str(mma_text_style_enum text_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const mma_text_style_parse_struct *curr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    curr = supported_mma_text_style;

    while (curr->text_name != NULL)
    {
        if (curr->text_style == text_style)
        {
            return curr->text_name;
        }
        ++curr;
    }
    return curr->text_name;
}


/*****************************************************************************
 * FUNCTION
 *  translate_mms_address_type_to_mma
 * DESCRIPTION
 *  This function is used to convert MMS address type definition to MMA address type definition
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_addr_type_enum translate_mms_address_type_to_mma(MmsAddressType type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMS_PLMN:
            return MMA_ADDR_TYPE_PHONE_NUMBER;
        case MMS_EMAIL:
            return MMA_ADDR_TYPE_EMAIL;
        case MMS_IPV4:
            return MMA_ADDR_TYPE_IPV4;
        case MMS_UNSUPPORTED:
        default:
            return MMA_ADDR_TYPE_NONE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  translate_mma_address_type_to_mms
 * DESCRIPTION
 *  This function is used to convert  MMA address type definition to MMS address type definition  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MmsAddressType translate_mma_address_type_to_mms(mma_addr_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMA_ADDR_TYPE_PHONE_NUMBER:
            return MMS_PLMN;
        case MMA_ADDR_TYPE_EMAIL:
            return MMS_EMAIL ;
        case MMA_ADDR_TYPE_IPV4:
            return MMS_IPV4;       
        default:
            return MMS_PLMN;
    }
}
/*****************************************************************************
 * FUNCTION
 *  translate_mms_msg_type_to_mma
 * DESCRIPTION
 *  This function is used to convert MMS message type definition to MMA message type definition
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_msg_type_enum translate_mms_msg_type_to_mma(MmsFileType type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMS_SUFFIX_TEMPLATE:
            return MMA_MSG_TYPE_MMS; /*MMA_MSG_TYPE_TEMPLATE;*/
        case MMS_SUFFIX_SEND_REQ:
        case MMS_SUFFIX_MSG:
            return MMA_MSG_TYPE_MMS;
        case MMS_SUFFIX_IMMEDIATE:
        case MMS_SUFFIX_NOTIFICATION:
            return MMA_MSG_TYPE_NOTIFICATION;
        case MMS_SUFFIX_READREPORT:
            return MMA_MSG_TYPE_READ_REPORT;
        case MMS_SUFFIX_DELIVERYREPORT:
            return MMA_MSG_TYPE_DELIVERY_REPORT;
        default:
            return MMA_MSG_TYPE_MMS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  translate_applib_obj_type_to_sls
 * DESCRIPTION
 *  This function is used to convert applib obj mime type definition to SLS obj type definition
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
SlsMediaObjectType translate_applib_obj_type_to_sls(applib_mime_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MIME_TYPE_TEXT:
            return SLS_OBJECT_TYPE_TEXT;
        case MIME_TYPE_IMAGE:
            return SLS_OBJECT_TYPE_IMAGE;
        case MIME_TYPE_AUDIO:
            return SLS_OBJECT_TYPE_AUDIO;
        case MIME_TYPE_VIDEO:
#ifdef __MMI_MMS_VIDEO_FEATURE__
            return SLS_OBJECT_TYPE_VIDEO;
#endif
        default:
            return SLS_OBJECT_TYPE_ATTACMENT;
    }
}


/*****************************************************************************
 * FUNCTION
 *  translate_sls_fit_to_mma
 * DESCRIPTION
 *  This function is used to convert SLS fit defition to MMA fit defition
 * PARAMETERS
 *  fit     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
 /*
mma_region_fit_enum translate_sls_fit_to_mma(SlsFit fit)
{
    switch (fit)
    {
        case SLS_ATTR_NOT_USED:
            return MMA_REGION_FIT_NONE;
        case SLS_ATTR_MEET:
            return MMA_REGION_FIT_MEET;
        case SLS_ATTR_SCROLL:
            return MMA_REGION_FIT_SCROLL;
        case SLS_ATTR_HIDDEN:
            return MMA_REGION_FIT_HIDDEN;
        case SLS_ATTR_FILL:
            return MMA_REGION_FIT_FILL;
        case SLS_ATTR_SLICE:
            return MMA_REGION_FIT_SLICE;
        default:
            return MMA_REGION_FIT_NONE;
    }
}
*/

/*****************************************************************************
 * FUNCTION
 *  translate_mma_fit_to_sls
 * DESCRIPTION
 *  This function is used to convert applib obj mime type definition to SLS obj type definition
 * PARAMETERS
 *  fit     [IN]        
 *  type(?)
 * RETURNS
 *  
 *****************************************************************************/
 /*
SlsFit translate_mma_fit_to_sls(mma_region_fit_enum fit)
{
    switch (fit)
    {
        case MMA_REGION_FIT_NONE:
            return SLS_ATTR_NOT_USED;
        case MMA_REGION_FIT_MEET:
            return SLS_ATTR_MEET;
        case MMA_REGION_FIT_SCROLL:
            return SLS_ATTR_SCROLL;
        case MMA_REGION_FIT_HIDDEN:
            return SLS_ATTR_HIDDEN;
        case MMA_REGION_FIT_FILL:
            return SLS_ATTR_FILL;
        case MMA_REGION_FIT_SLICE:
            return SLS_ATTR_SLICE;
        default:
            return SLS_ATTR_NOT_USED;
    }
}
*/

/*****************************************************************************
 * FUNCTION
 *  translate_mms_charset_to_mma
 * DESCRIPTION
 *  This function is used to convert MSF charset definition to MMA charset definition
 * PARAMETERS
 *  charset     [IN]        
 * RETURNS
 *  mma_charset_enum
 *****************************************************************************/
mma_charset_enum translate_mms_charset_to_mma(MmsCharset charset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charset)
    {
        case MMS_US_ASCII:
            return MMA_CHARSET_ASCII;
        case MMS_ISO_8859_1:
            return MMA_CHARSET_ISO_8859_1;
        case MMS_UTF8:
            return MMA_CHARSET_UTF8;
        case MMS_UCS2:
            return MMA_CHARSET_UCS2;
        case MMS_UTF16BE:
            return MMA_CHARSET_UTF16BE;
        case MMS_UTF16LE:
            return MMA_CHARSET_UTF16LE;
        case MMS_UTF16:
            return MMA_CHARSET_UTF16;
        default:
            return MMA_CHARSET_UNKNOWN;
    }
}


/*****************************************************************************
 * FUNCTION
 *  translate_mma_charset_to_mms
 * DESCRIPTION
 *  This function is used to convert MSF charset definition to MMA charset definition
 * PARAMETERS
 *  charset     [IN]        
 * RETURNS
 *  mma_charset_enum
 *****************************************************************************/
MmsCharset translate_mma_charset_to_mms(mma_charset_enum charset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charset)
    {
        case MMA_CHARSET_ASCII:
            return MMS_US_ASCII;
        case MMA_CHARSET_ISO_8859_1:
            return MMS_ISO_8859_1;
        case MMA_CHARSET_UTF8:
            return MMS_UTF8;
        case MMA_CHARSET_UCS2:
            return MMS_UCS2;
        case MMA_CHARSET_UTF16BE:
            return MMS_UTF16BE;
        case MMA_CHARSET_UTF16LE:
            return MMS_UTF16LE;
        case MMA_CHARSET_UTF16:
            return MMS_UTF16;
        default:
            return MMS_UNKNOWN_CHARSET;
    }
}


/*****************************************************************************
 * FUNCTION
 *  translate_mmi_charset_to_mma
 * DESCRIPTION
 *  This function is used to convert MSF charset definition to MMA charset definition
 * PARAMETERS
 *  charset     [IN]        
 * RETURNS
 *  mma_charset_enum
 *****************************************************************************/
mma_charset_enum translate_mmi_charset_to_mma(mmi_chset_enum charset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (charset)
    {
        case MMI_CHSET_ASCII:
            return MMA_CHARSET_ASCII;
        case MMI_CHSET_UTF8:
            return MMA_CHARSET_UTF8;
        case MMI_CHSET_UCS2:
            return MMA_CHARSET_UCS2;
        case MMI_CHSET_UTF16BE:
            return MMA_CHARSET_UTF16BE;
        case MMI_CHSET_UTF16LE:
            return MMA_CHARSET_UTF16LE;
        case MMI_CHSET_GB2312:
            return MMA_CHARSET_GB2312;
        case MMI_CHSET_BIG5:
            return MMA_CHARSET_BIG5;
        case MMI_CHSET_WESTERN_ISO:
            return MMA_CHARSET_ISO_8859_1;
        default:
            return MMA_CHARSET_UNKNOWN;
    }
}

#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
/*****************************************************************************
 * FUNCTION
 *  mma_mms_convert_visibility_enum_value_to_bool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slide           [?]         
 *  object_type     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool mma_mms_convert_visibility_enum_value_to_bool(mma_mms_sender_visibility_enum hide_sender)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_bool visibility ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


	switch(hide_sender)
	{
	case MMA_MMS_SENDER_HIDE:
		visibility = KAL_FALSE ;
			break;
	case MMA_MMS_SENDER_SHOW:
		visibility = KAL_TRUE ;
			break;
	default :
		visibility = KAL_TRUE ;
			break;
	}
	return visibility ;
}
#endif	/* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__  */
/*****************************************************************************
 * FUNCTION
 *  mma_trim_utf8_string
 * DESCRIPTION
 *  Strip whitespace (space, tab and newline) from the beginning and end of a string
 * PARAMETERS
 *  str     [IN/OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_trim_utf8_string(char *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *start = NULL, *end = NULL;
    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str == NULL || *str == NULL)
    {
        return;
    }

    start = str;
    while (*start == ' ' || *start == '\t' || *start == '\n')
    {
        start++;
    }

    end = str + strlen(str) - 1;
    while (*end == ' ' || *end == '\t' || *end == '\n')
    {
        end--;
    }

    *(end + 1) = '\0';
    if (end < start || strlen(start) == strlen(str))
    {
        return;
    }

    while (*(start + i) != '\0')
    {
        *(str + i) = *(start + i);
        i++;
    }
    *(str + i) = '\0';
}


/*****************************************************************************
 * FUNCTION
 *  mma_unicode_to_utf8_len
 * DESCRIPTION
 *  Get UTF8 string len from UCS2 string.
 * PARAMETERS
 *  ucs2        [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 mma_unicode_to_utf8_len(kal_wchar *ucs2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar temp;
    kal_int32 length = 0;
    kal_wchar *str = ucs2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	temp = *str;
    while (temp != NULL)
    {
        temp = *str;
        if (temp < (kal_wchar) 0x80)
            length += 1;
        else if (temp < (kal_wchar) 0x800)
            length += 2;
        else
            length += 3;
        str++;
    }
    return length;
}


/*****************************************************************************
 * FUNCTION
 *  mma_ucs2_to_utf8_string
 * DESCRIPTION
 *  Get UTF8 string from UCS2 string, caller should release the returned UTF8 string
 * PARAMETERS
 *  ucs2_str        [IN]        
 * RETURNS
 *  UTF8 string
 *****************************************************************************/
char *mma_ucs2_to_utf8_string(const kal_wchar *ucs2_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *utf8_str = NULL;
    long src_len = (long)app_ucs2_strlen((kal_int8*) ucs2_str) * ENCODING_LENGTH;
    long dst_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dst_len = (long)mma_unicode_to_utf8_len((kal_wchar*) ucs2_str);
    if (src_len > 0)
    {
        utf8_str = (char*)MMA_CALLOC(dst_len + 1);
        msf_charset_ucs2le_to_utf8((const char*)ucs2_str, &src_len, utf8_str, &dst_len);
    }
    return utf8_str;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_multipart_type
 * DESCRIPTION
 *  Get mms multipart type
 * PARAMETERS
 *  bodyInfoList        [IN]         
 * RETURNS
 *  The type of message presentation
 *****************************************************************************/
mma_mms_multipart_enum mma_get_multipart_type(MmsBodyInfoList *bodyInfoList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsBodyInfoList *biList = bodyInfoList;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (NULL != biList)  /* Traverse all body-parts in hunt of a SMIL presentation */
    {
        /* Check params for current body-part - is it a SMIL ? */
        if ((MMS_VALUE_AS_STRING == biList->contentType->knownValue) &&
            (NULL != biList->contentType->strValue) &&
            (0 == msf_cmmn_strcmp_nc((char*)biList->contentType->strValue, MMS_MEDIA_TYPE_STRING_SMIL)))
        {
            return MMA_SMIL;
        }
        biList = biList->next;
    }

    if (NULL != bodyInfoList)
    {
        if (0 == bodyInfoList->numOfEntries)
        {
            return MMA_PLAIN_TEXT;
        }
        else if ((MMS_VND_WAP_MULTIPART_RELATED == bodyInfoList->contentType->knownValue) ||
                 (MMS_VND_WAP_MULTIPART_MIXED == bodyInfoList->contentType->knownValue) ||
                 (MMS_VND_WAP_MULTIPART_ALTERNATIVE == bodyInfoList->contentType->knownValue))
        {
            return MMA_MULTIPART_MIXED;
        }
    }
    return MMA_UNSUPPORTED;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_message_media_type
 * DESCRIPTION
 *  Get mms multipart type
 * PARAMETERS
 *  body                [IN]         
 * RETURNS
 *  The type of message presentation
 *****************************************************************************/
mma_media_msg_enum mma_get_message_media_type(mma_mms_description_body_struct *body)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj = NULL;
    mma_media_msg_enum type = MMA_MEDIA_MSG_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(body != NULL);
    obj = body->objects;
    if (obj && obj->next == NULL && obj->is_attachment == FALSE)
    {
        applib_mime_type_enum app_type = MIME_TYPE_NONE;

        if (obj->drm_process_type == MMA_DRM_NO_PROTECTION)
        {
            app_type = mma_get_mime_group_from_mime_type(obj->mime_str);
        }
        else
        {
        #ifdef __DRM_SUPPORT__
            app_type = mma_get_mime_group_from_mime_type(obj->drm_mime_type);
        #else 
            app_type = mma_get_mime_group_from_mime_type(obj->mime_str);
        #endif 
        }

        switch (app_type)
        {
            case MIME_TYPE_TEXT:
                type = MMA_MEDIA_MSG_TEXT;
                break;
            case MIME_TYPE_IMAGE:
                type = MMA_MEDIA_MSG_PHOTO;
                break;
            case MIME_TYPE_AUDIO:
                type = MMA_MEDIA_MSG_AUDIO;
                break;
#ifdef __MMI_MMS_VIDEO_FEATURE__
            case MIME_TYPE_VIDEO:
                type = MMA_MEDIA_MSG_VIDEO;
                break;
#endif
            default:
                break;
        }
    }
    return type;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_recipient_num
 * DESCRIPTION
 *  Get number of recipient
 * PARAMETERS
 *  header          [IN]        
 * RETURNS
 *  Number of recipient
 *****************************************************************************/
kal_uint32 mma_get_recipient_num(MmsGetHeader *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 ret = 0;
    MmsAddressList *addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Address */
    if (header->to != NULL || header->cc != NULL || header->bcc != NULL)
    {
        /* To */
        addr = header->to;
        while(addr != NULL)
        {
            ret++;
            addr = addr->next;
        }
    
        /* Cc */
        addr = header->cc;
        while(addr != NULL)
        {
            ret++;
            addr = addr->next;
        }
    
        /* Bcc */
        addr = header->bcc;
        while(addr != NULL)
        {
            ret++;
            addr = addr->next;
        }
    }
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_mime_type_from_mmsContentType
 * DESCRIPTION
 *  Get mime type string from MmsContentType info
 * PARAMETERS
 *  contentType     [IN]        
 * RETURNS
 *  mime type string
 *****************************************************************************/
const char *mma_get_mime_type_from_mmsContentType(const MmsContentType *contentType)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const char *tempType = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (contentType == NULL)
    {
        return NULL;
    }

    if (contentType->knownValue == MMS_VALUE_AS_STRING)
    {
        return (const char*)contentType->strValue;
    }
    else
    {
        tempType = msf_int_to_mime(contentType->knownValue);
        return tempType;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_mime_type_from_filename_and_mime_string
 * DESCRIPTION
 *  Get mime type from file name (extension)
 * PARAMETERS
 *  filename        [IN]     
 *  mime_string     [IN]
 * RETURNS
 *  mime type string
 *****************************************************************************/
const char *mma_get_mime_type_from_filename_and_mime_string(const char *filename, char *mime_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename != NULL)
    {
        char *ext = NULL;
        applib_mime_type_struct *entry = NULL;

        ext = strrchr(filename, '.');
        if (ext != NULL)
        {
            ext++;
            entry = applib_mime_type_look_up(mime_string, ext, MIME_TYPE_NONE, MIME_SUBTYPE_NONE);
            if (entry == NULL)
            {
                return MMA_UNKNOWN_MIME_STR;
            }
            return entry->mime_string;
        }
    }
    return MMA_UNKNOWN_MIME_STR;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_mime_type_from_filename_and_type
 * DESCRIPTION
 *  Get mime type from file name (extension)
 * PARAMETERS
 *  filename        [IN]        
 *  type            [IN]        
 * RETURNS
 *  mime type string
 *****************************************************************************/
const char *mma_get_mime_type_from_filename_and_type(const char *filename, applib_mime_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename != NULL)
    {
        char *ext = NULL;
        applib_mime_type_struct *entry = NULL;

        ext = strrchr(filename, '.');
        if (ext != NULL)
        {
            ext++;
            entry = applib_mime_type_look_up(NULL, ext, type, MIME_SUBTYPE_NONE);
            if (entry == NULL)
            {
                return MMA_UNKNOWN_MIME_STR;
            }
            return entry->mime_string;
        }
    }
    return MMA_UNKNOWN_MIME_STR;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_mmsKnownMediaType_from_mime_type
 * DESCRIPTION
 *  Get mmsKnownMediaType from mime
 * PARAMETERS
 *  mime        [IN]        
 * RETURNS
 *  mmsKnownMediaType
 *****************************************************************************/
MSF_INT32 mma_get_mmsKnownMediaType_from_mime_type(const char *mime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_INT32 knownValue = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* may be this is extra vikas */
#ifdef MMS_HEADER_CODING_VERSION
    knownValue = msf_mime_to_int_encoding_version(mime, MMS_HEADER_CODING_VERSION);
#else 
    knownValue = msf_mime_to_int(mime);
#endif 

    if (knownValue < MSF_MIME_TYPE_AUDIO_ANY)
    {
        return knownValue;
    }

    return MSF_MIME_TYPE_UNKNOWN;
}

#ifdef __DRM_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  mma_drm_check_right
 * DESCRIPTION
 *  Check if DRM right is valid for a processed DRM file
 * PARAMETERS
 *  filename        [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mma_drm_check_right(const char *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *mime = NULL;
    kal_uint8 *externalFileName = NULL;
    kal_bool is_valid_right = KAL_FALSE;
    applib_mime_type_enum drmGType = MIME_TYPE_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(filename);
    externalFileName = (kal_uint8*) MSF_FILE_GET_EXTERNAL_FILENAME_EXT(MSF_MODID_MMA, filename, MSF_MMS_STORAGE_NONE);
    mime = (char*)DRM_get_content_type(0, (kal_wchar*) externalFileName);
    drmGType = mma_get_mime_group_from_mime_type(mime);

    if (drmGType == MIME_TYPE_TEXT || drmGType == MIME_TYPE_IMAGE || drmGType == MIME_TYPE_AUDIO ||
        drmGType == MIME_TYPE_VIDEO)
    {
        MSF_UINT8 permission = (kal_uint8) ((drmGType == MIME_TYPE_TEXT || drmGType == MIME_TYPE_IMAGE) ?
                                            DRM_PERMISSION_DISPLAY : DRM_PERMISSION_PLAY);
        FS_HANDLE fh = DRM_open_file((kal_wchar *)externalFileName, FS_READ_ONLY, permission);
        if (fh >= FS_NO_ERROR)
        {
           /*is_valid_right = DRM_validate_permission(0, (kal_wchar*) externalFileName, permission); */
            is_valid_right = DRM_validate_permission(fh, NULL, permission);
            DRM_close_file(fh);
        }
    }

    MMA_FREE(externalFileName);
    return is_valid_right;
}


/*****************************************************************************
 * FUNCTION
 *  mma_drm_check_right_vf
 * DESCRIPTION
 *  Check if DRM right is valid for DRM virtual file
 * PARAMETERS
 *  type            [IN]        
 *  filename        [IN]        
 *  offset          [IN]        
 *  size            [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
mma_drm_type_enum mma_drm_check_right_vf(mma_drm_type_for_process_enum type, const char *filename, int offset, int size, kal_uint8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(filename != NULL);
    if (size == 0 || (type != MMA_DRM_PROCESS_FORWARD_LOCK_CD && type != MMA_DRM_PROCESS_SEPERATE_DELIVERY))
    {
        return MMA_DRM_NONE;
    }
    else if (type == MMA_DRM_PROCESS_FORWARD_LOCK_CD)   /* MMS doesn't consume right, so FL and CD always ok */
    {
        return MMA_DRM_FL_CD;
    }
    else if (type == MMA_DRM_PROCESS_SEPERATE_DELIVERY) /* Check if SD right present */
    {
        char *v_file_name = NULL;   /* virtual file name */
        MSF_INT32 handle = 0;
        kal_bool is_valid_right = KAL_FALSE;

        if ((handle = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, filename, MSF_FILE_SET_RDONLY, 0, storage)) >= 0)
        {
            /* generate virtual file */
            v_file_name = (char*)MMA_CALLOC(MMA_MAX_VIRTUAL_FILE_PATH_SIZE);
            ASSERT(v_file_name != NULL);
            if (MSF_FILE_GEN_VIRTUAL_FILENAME
                (MSF_MODID_MMA, handle, v_file_name, MMA_MAX_VIRTUAL_FILE_PATH_SIZE, offset, size) == MSF_FILE_OK)
            {
                is_valid_right = mma_drm_check_right(v_file_name);
            }
            MMA_FREE(v_file_name);
            MSF_FILE_CLOSE(handle);

            return (is_valid_right ? MMA_DRM_SD : MMA_DRM_SD_NO_RIGHT);
        }
        else
        {
        }
    }
    return MMA_DRM_NONE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_drm_get_method_type
 * DESCRIPTION
 *  Get DRM method for a processed DRM file, ex. files in file manager
 * PARAMETERS
 *  fh          [IN] DRM_open_file() return value. If < 0, use filepath instead
 *  filename        [IN]        
 * RETURNS
 *  mma_drm_method_enum
 *****************************************************************************/
mma_drm_method_enum mma_drm_get_method_type(FS_HANDLE fh, const char *filepath, kal_uint8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_method_enum drmMethod = DRM_METHOD_NONE;
    kal_uint8 *externalFilePath = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(fh >= 0 || filepath != NULL);
    if (fh >= 0)
    {
        drmMethod = DRM_get_object_method(fh, NULL);
    }
    else
    {
        externalFilePath = (kal_uint8*) MSF_FILE_GET_EXTERNAL_FILENAME_EXT(MSF_MODID_MMA, filepath, translate_mma_storage_to_mms_storage_enum(storage));
        drmMethod = DRM_get_object_method(0, (kal_wchar *) externalFilePath);
        MMA_FREE(externalFilePath);
    }

    if ((drmMethod & DRM_METHOD_FORWARD_LOCK) == DRM_METHOD_FORWARD_LOCK)
    {
        return MMA_DRM_METHOD_FORWARD_LOCK;
    }
    else if ((drmMethod & DRM_METHOD_COMBINED_DELIVERY) == DRM_METHOD_COMBINED_DELIVERY)
    {
        return MMA_DRM_METHOD_COMBINED_DELIVERY;
    }
    else if ((drmMethod & DRM_METHOD_SEPARATE_DELIVERY) == DRM_METHOD_SEPARATE_DELIVERY)
    {
        return MMA_DRM_METHOD_SEPARATE_DELIVERY;
    }

    switch (drmMethod)
    {
        case DRM_METHOD_NONE:
            return MMA_DRM_METHOD_NONE;
        case DRM_METHOD_FORWARD_LOCK:
            return MMA_DRM_METHOD_FORWARD_LOCK;
        case DRM_METHOD_COMBINED_DELIVERY:
            return MMA_DRM_METHOD_COMBINED_DELIVERY;
        case DRM_METHOD_SEPARATE_DELIVERY:
            return MMA_DRM_METHOD_SEPARATE_DELIVERY;
        default:
            return MMA_DRM_METHOD_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_drm_get_content_type
 * DESCRIPTION
 *  Get mime type string for processed DRM file
 * PARAMETERS
 *  type            [IN]        
 *  fh          [IN] DRM_open_file() return value. If < 0, use filepath instead
 *  filename        [IN]        
 * RETURNS
 *  mime type string
 *****************************************************************************/
const char *mma_drm_get_content_type(mma_drm_type_for_process_enum type, FS_HANDLE fh, const char *filename, kal_uint8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned char *externalFileName = NULL; /* translated UCS2 vitual file name */
    char *mime = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT((fh >= 0 || filename != NULL) && (type == MMA_DRM_PROCESS_FORWARD_LOCK_CD || type == MMA_DRM_PROCESS_SEPERATE_DELIVERY));
    if (fh >= 0)
    {
        mime = (char *)DRM_get_content_type(fh, NULL);
    }
    else
    {
    externalFileName = (kal_uint8*) MSF_FILE_GET_EXTERNAL_FILENAME_EXT(MSF_MODID_MMA, filename, storage);
    mime = (char*)DRM_get_content_type(0, (kal_wchar*) externalFileName);
    MMA_FREE(externalFileName);
    }
    return mime;
}


/*****************************************************************************
 * FUNCTION
 *  mma_drm_get_content_type_vf
 * DESCRIPTION
 *  Get mime type string for DRM virtual file
 * PARAMETERS
 *  type            [IN]        
 *  filepath        [IN]        
 *  offset          [IN]        
 *  size            [IN]        
 *  filename(?)     [IN]        
 * RETURNS
 *  mime type string
 *****************************************************************************/
const char *mma_drm_get_content_type_vf(
				mma_mms_object_struct *obj,
                mma_drm_type_for_process_enum type,
                const char *filepath,
                kal_uint32 offset,
                kal_uint32 size,
                kal_uint8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *v_file_name = NULL;   /* vitual file name */
    MSF_INT32 handle = 0;
    const char *mime = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(filepath != NULL);
    if (size == 0 || (type != MMA_DRM_PROCESS_FORWARD_LOCK_CD && type != MMA_DRM_PROCESS_SEPERATE_DELIVERY))
    {
        return NULL;
    }

    if ((handle = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, filepath, MSF_FILE_SET_RDONLY, 0, storage)) >= 0)
    {
        /* generate virtual file */
        v_file_name = (char*)MMA_CALLOC(MMA_MAX_VIRTUAL_FILE_PATH_SIZE);
        ASSERT(v_file_name != NULL);
        if (MSF_FILE_GEN_VIRTUAL_FILENAME
            (MSF_MODID_MMA, handle, v_file_name, MMA_MAX_VIRTUAL_FILE_PATH_SIZE, offset, size) == MSF_FILE_OK)
        {
            unsigned char *externalFileName = NULL; /* translated UCS2 vitual file name */

            externalFileName = (kal_uint8*) MSF_FILE_GET_EXTERNAL_FILENAME_EXT(MSF_MODID_MMA, v_file_name, (mma_msg_storage_type_enum)storage);
            if (type == MMA_DRM_PROCESS_SEPERATE_DELIVERY)
            {
                kal_char* temp_str = DRM_get_content_ext(0, (kal_wchar*) externalFileName);
                mime = (char*)DRM_get_content_type(0, (kal_wchar*) externalFileName);
				if(obj)
				{
					if(temp_str != NULL)
					{
						app_asc_str_n_to_ucs2_str((kal_int8 *) obj->drm_ext, (kal_int8 *)temp_str, SRV_FMGR_PATH_MAX_FILE_EXT_LEN );
						obj->is_drm_processed = KAL_TRUE;
					}
				}
            }
#ifndef __MMI_MMS_MMA_DRM_ENCODING__
            else if (type == MMA_DRM_PROCESS_FORWARD_LOCK_CD)    /* FL, CD */
            {
				kal_int32 result;
                kal_int32 serial = 0;
                kal_uint8 *seed = NULL;
                drm_message_info_struct info;
                kal_uint8 *filepath_ucs2 = (kal_uint8*) MSF_FILE_GET_EXTERNAL_FILENAME_EXT(MSF_MODID_MMA, filepath, (mma_msg_storage_type_enum)storage);
                char *filepath_utf8 = mma_ucs2_to_utf8_string((kal_wchar *)filepath_ucs2);

                seed = (kal_uint8*) MMA_CALLOC(strlen(filepath_utf8) + mma_get_value_digit_number(offset) + 1);
                sprintf((char*)seed, "%s%x", filepath_utf8, offset);
                result = DRM_parse_drm_message(
                            (kal_wchar*) externalFileName,
                            seed,
                            strlen((char*)seed),
                            &serial,
                            &info,
                            NULL);

                if (result >= 0 && info.mime_type != NULL)
                {
					/*changes done to set the DRM size offset and CID*/
					if(obj)
					{
						obj->drm_size = info.plaintext_len;
						obj->drm_offset = obj->offset + info.plaintext_offset;
						obj->cid = (drm_cid_struct*)MMA_CALLOC(sizeof(drm_cid_struct));
						ASSERT(obj->cid);
						memcpy(obj->cid, &info.cid, sizeof(drm_cid_struct));
						app_asc_str_n_to_ucs2_str((kal_int8 *) obj->drm_ext, (kal_int8 *) info.mime_type->file_ext, SRV_FMGR_PATH_MAX_FILE_EXT_LEN );
     					obj->is_drm_processed = KAL_TRUE;
					}
					/*changes done to set the DRM size offset and CID*/
                    mime = info.mime_type->mime_string;
                }
		else
                 {
                    if(obj)
					{
						mmi_ucs2ncpy((kal_char*) obj->drm_ext, (kal_char*) L"tmp", SRV_FMGR_PATH_MAX_FILE_EXT_LEN );
					}
                 }
                MMA_FREE(filepath_ucs2);
                MMA_FREE(filepath_utf8);
				MMA_FREE(seed);
            }
#endif
            MMA_FREE(externalFileName);
        }

        MMA_FREE(v_file_name);
        MSF_FILE_CLOSE(handle);
    }
    else
    {
    }
    return mime;
}
#endif /* __DRM_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  mma_transform_illegal_name
 * DESCRIPTION
 *  Replace characters which are not supported on MTK file system
 * PARAMETERS
 *  name        [IN/OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_transform_illegal_name(char *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const char *illegal_chars = "\\/:*?\"<>|";
    char *ch = name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*ch)
    {
        if (strchr(illegal_chars, *ch))
        {
            *ch = '_';
        }
        ch += 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_uintvar_length_bytes
 * DESCRIPTION
 *  Get converted uintvar length byte count (Ref. WAP-230-WSP-20010705-a 8.1.2)
 * PARAMETERS
 *  n       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mma_get_uintvar_length_bytes(kal_uint32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n < 0x80)
    {
        return 1;
    }
    else if (n < 0x4000)
    {
        return 2;
    }
    else if (n < 0x200000)
    {
        return 3;
    }
    else if (n < 0x10000000)
    {
        return 4;
    }
    else
    {
        return 5;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_value_length_bytes
 * DESCRIPTION
 *  Get converted value length byte count (Ref. WAP-230-WSP-20010705-a 8.4.2.2)
 *  Value-length = <Any octet 0-30> | (<Oct 31> Uintvar-integer)
 * PARAMETERS
 *  n       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 mma_get_value_length_bytes(kal_uint32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n > 30)
    {
        size += mma_get_uintvar_length_bytes(n);
        size++; /* Length-quote */
    }
    else
    {
        size = 1;
    }

    return size;
}


/*****************************************************************************
 * FUNCTION
 *  mma_convert_size_to_uintvar
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data_size       [IN]        
 *  buf             [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
void mma_convert_size_to_uintvar(MSF_UINT32 data_size, void *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT8 len = mma_get_uintvar_length_bytes(data_size);
    unsigned char b;
    unsigned char *ptr = (unsigned char*)buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; len > 0; --len)
    {
        b = (MSF_UINT8) ((data_size >> ((len - 1) * 7)) & 0x7f);
        if (len > 1)
        {
            b = (b | (unsigned char)0x80);
        }

        *ptr++ = b;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_value_digit_number
 * DESCRIPTION
 *  Get positive value digit number
 * PARAMETERS
 *  n       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 mma_get_value_digit_number(kal_uint32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 digit = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (n > 0)
    {
        n = n / 10;
        digit++;
    }

    return digit;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_slide_layout
 * DESCRIPTION
 *  Get slide layout
 * PARAMETERS
 *  slide       [IN]        
 * RETURNS
 *****************************************************************************/
mma_slide_layout_enum mma_get_slide_layout(mma_mms_slide_struct *slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_object_struct *image = NULL;
	mma_mms_slide_text_object_struct *text = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(slide != NULL);

  
    
    if (slide->txt.object != NULL)
        {
            text = &slide->txt;
        }
	if(slide->vid.object != NULL)
        {
            image = &slide->vid;
        }
   if (slide->img.object != NULL)
    {
            image = &slide->img;
    }

    
    if (text && image)
    {
        if (image->region_area == NULL || text->region_area == NULL)
        {
            return MMA_LAYOUT_IMAGE_ON_TOP;
        }
        if (image->region_area->x.value < text->region_area->x.value)
        {
            return MMA_LAYOUT_IMAGE_AT_LEFT;
        }
        else if (image->region_area->x.value > text->region_area->x.value)
        {
            return MMA_LAYOUT_TEXT_AT_LEFT;
        }
        else if (image->region_area->y.value < text->region_area->y.value)
        {
            return MMA_LAYOUT_IMAGE_ON_TOP;
        }
        else
        {
            return MMA_LAYOUT_TEXT_ON_TOP;
        }
    }
    else
    {
        return MMA_LAYOUT_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_unref_item_count
 * DESCRIPTION
 *  Get attchment number
 * PARAMETERS
 *  list        [IN]        
 * RETURNS
 *  Attchment number
 *****************************************************************************/
kal_uint32 mma_get_unref_item_count(mma_mms_attachment_info_struct *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int obj_no = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; list != NULL; list = list->next, obj_no++);
    return obj_no;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_total_item_count
 * DESCRIPTION
 *  Get slide object + attchment object number
 * PARAMETERS
 *  body        [IN]        
 * RETURNS
 *  Total object number
 *****************************************************************************/
kal_uint32 mma_get_total_item_count(mma_mms_description_body_struct *body)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj = NULL;
    kal_uint32 count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(body != NULL);
    obj = body->objects;
    for (; obj != NULL; obj = obj->next)
	{
		if(!obj->is_invallid)
		{
			count++;		
		}
	
	}
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_app_id_from_params
 * DESCRIPTION
 *  Get application ID from content type parameters
 * PARAMETERS
 *  params      [IN]        
 * RETURNS
 *  application ID string
 *****************************************************************************/
char *mma_get_app_id_from_params(const MmsAllParams *params)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (params)
    {
        if (params->key != NULL && msf_cmmn_strcmp_nc((char*)params->key, MMA_HEADER_APPLICATION_ID_STR) == 0)
        {
            return (char*)(params->value.string);
        }
        params = params->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_reply_app_id_from_params
 * DESCRIPTION
 *  Get application ID from content type parameters
 * PARAMETERS
 *  params      [IN]        
 * RETURNS
 *  application ID string
 *****************************************************************************/
char *mma_get_reply_app_id_from_params(const MmsAllParams *params)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (params)
    {
        if (params->key != NULL && msf_cmmn_strcmp_nc((char*)params->key, MMA_HEADER_REPLY_APPLICATION_ID_STR) == 0)
        {
            return (char*)(params->value.string);
        }
        params = params->next;
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_charset_from_params
 * DESCRIPTION
 *  Get text charset from content type parameters
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  MmsCharset
 *****************************************************************************/
MmsCharset mma_get_charset_from_params(const MmsAllParams *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    unsigned int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (param != NULL)
    {
        if (param->param == MMS_CHARSET)
        {
            if (param->type == MMS_PARAM_INTEGER)
            {
                const SlsCharsetItem *items = supportedCharsets;

                i = 0;
                while (MSF_CHARSET_UNKNOWN != items[i].msfCharset)
                {
                    if ((unsigned)items[i].mmsCharset == param->value.integer)
                    {
                        return (MmsCharset)items[i].mmsCharset;
                    }
                    ++i;
                }
            }
            else if (param->type == MMS_PARAM_STRING && param->value.string != NULL)
            {
                const mma_charset_item *items = supportedCharsetsStr;

                i = 0;
                while (MMS_UNKNOWN_CHARSET != items[i].mmsCharset)
                {
                    if (msf_cmmn_strcmp_nc(items[i].charsetStr, (const char*)param->value.string) == 0)
                    {
                        return (MmsCharset)items[i].mmsCharset;
                    }
                    ++i;
                }
            }
        }
        param = param->next;
    }
    return MMS_UNKNOWN_CHARSET;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_name_from_params
 * DESCRIPTION
 *  Get multipart object filename from content type parameters
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  filename
 *****************************************************************************/
char *mma_get_name_from_params(kal_uint8 modid, const MmsAllParams *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (param != NULL)
    {
        if ((param->type == MMS_PARAM_STRING) && (param->param == MMS_FILENAME || param->param == MMS_NAME)
            && param->value.string != NULL && strlen((char*)param->value.string) > 0)
        {
            char *to = msf_cmmn_strdup(modid, (const char*)param->value.string);
           /* Transform the file name only when writing to XML*/
          //  mma_transform_illegal_name(to);
            return to;
        }
        param = param->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_presentation_from_params
 * DESCRIPTION
 *  Get presentation part content ID from content type parameters
 * PARAMETERS
 *  param       [IN]        
 * RETURNS
 *  filename
 *****************************************************************************/
char *mma_get_presentation_from_params(const MmsAllParams *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (param != NULL)
    {
        if (param->type == MMS_PARAM_STRING && param->param == MMS_START_REL)
        {
            return (char*)param->value.string;
        }
        param = param->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_content_id_from_entry_header
 * DESCRIPTION
 *  Get multipart object content ID
 * PARAMETERS
 *  entries     [IN]        
 * RETURNS
 *  content ID string
 *****************************************************************************/
char *mma_get_content_id_from_entry_header(const MmsEntryHeader *entries, kal_uint8 modid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (entries)
    {
        if ((MMS_WELL_KNOWN_CONTENT_ID == entries->headerType) && (NULL != entries->value.wellKnownFieldName))
        {
            char *str = msf_cmmn_strdup(modid, (char*)entries->value.wellKnownFieldName);

            return str;
        }
		
		else if (MMS_APPLICATION_HEADER == entries->headerType)
            {
                if (strcmp((char *)entries->value.applicationHeader.name, "Content-ID") == 0 && (NULL != entries->value.applicationHeader.value))
                {
                    char *str = msf_cmmn_strdup(modid, (char*)entries->value.applicationHeader.value);
					return str;
                } 
            }
		
		

        entries = entries->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_content_location_from_entry_header
 * DESCRIPTION
 *  Get multipart object content location
 * PARAMETERS
 *  entries     [IN]        
 * RETURNS
 *  content location string
 *****************************************************************************/
char *mma_get_content_location_from_entry_header(const MmsEntryHeader *entries, kal_uint8 modid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (entries)
    {
        if ((MMS_WELL_KNOWN_CONTENT_LOCATION == entries->headerType) && (NULL != entries->value.wellKnownFieldName))
        {
            char *str = msf_cmmn_strdup(modid, (char*)entries->value.wellKnownFieldName);

            return str;
        }

		
		else if (MMS_APPLICATION_HEADER == entries->headerType)
           {
               if (strcmp((char *)entries->value.applicationHeader.name, "Content-Location") == 0 && (NULL != entries->value.applicationHeader.value))
               {
                   char *str = msf_cmmn_strdup(modid, (char*)entries->value.applicationHeader.value);
				   return str;
               } 
           }
		
        entries = entries->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_name_from_entry_header
 * DESCRIPTION
 *  Get multipart object filename from header field, ex. content id and content location
 * PARAMETERS
 *  entries     [IN]        
 * RETURNS
 *  filename
 *****************************************************************************/
char *mma_get_name_from_entry_header(kal_uint8 modid, const MmsEntryHeader *entries)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *name = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (entries)
    {
        if ((MMS_WELL_KNOWN_CONTENT_LOCATION == entries->headerType ||
             MMS_WELL_KNOWN_CONTENT_ID == entries->headerType) &&
            NULL != entries->value.wellKnownFieldName && strlen((char*)entries->value.wellKnownFieldName) > 0)
        {
            char *to = msf_cmmn_strdup(modid, (char*)entries->value.wellKnownFieldName);
            /* Transform the file name only when writing to XML*/
            //mma_transform_illegal_name(to);
            if (name == NULL || strrchr(to, '.') != NULL)
            {
                if (name != NULL)
                {
                    MSF_MEM_FREE(modid, name);
                }
                name = to;
            }
            else
            {
                MSF_MEM_FREE(modid, to);                
            }
        }
        entries = entries->next;
    }
    return name;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_name_from_path
 * DESCRIPTION
 *  Get filename from filepath
 * PARAMETERS
 *  path        [IN]        
 * RETURNS
 *  filename
 *****************************************************************************/
const char *mma_get_name_from_path(char *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *c = strrchr(path, '\\');
    char *c1 = strrchr(path, '/');

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (c == NULL && c1 == NULL)
    {
        return path;
    }
    else
    {
        c = (c1 > c) ? c1 : c;  /* find the last / or \ */
    }

    /* Skip past "\" */
    return (++c);
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_object_by_name
 * DESCRIPTION
 *  Get object from name
 * PARAMETERS
 *  body        [IN]         
 *  name        [IN]        
 * RETURNS
 *  mma_object_struct
 *****************************************************************************/
mma_mms_object_struct *mma_get_object_by_name(mma_mms_description_body_struct *body, const char *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj = body->objects;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name != NULL)
    {
        while (obj)
        {
            if (obj->file_name != NULL && strcmp(obj->file_name, name) == 0)
            {
                return obj;
            }
            obj = obj->next;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_screen_size
 * DESCRIPTION
 *  Get screen size
 * PARAMETERS
 *  void
 * RETURNS
 *  MsfSize
 *****************************************************************************/
MsfSize mma_get_screen_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MsfSize size;
    extern int UI_device_width;
    extern int UI_device_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size.width = UI_device_width;
    size.height = UI_device_height;
    return size;
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_user_element_size
 * DESCRIPTION
 *  Get user element size
 * PARAMETERS
 *  header          [IN]     
 *  skeleton        [IN]     
 * RETURNS
 *  size in bytes
 *****************************************************************************/
kal_uint32 mma_get_user_element_size(mma_header_struct *header, MmsBodyInfoList *skeleton)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0;
    MmsBodyInfoList *mo = skeleton;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(header != NULL && header->header.g_header != NULL);
    if (header->header.g_header->subject.text)
    {
        size += strlen(header->header.g_header->subject.text);
    }

    while (mo)
    {
        if (mo->numOfEntries == 0)
        {
            size += mo->size;
        }
        mo = mo->next;
    }
    return size;
}


/*****************************************************************************
 * FUNCTION
 *  mma_add_param_int
 * DESCRIPTION
 *  Inserts a string param first in the list of params
 * PARAMETERS
 *  allParams       [OUT]       The current list
 *  param           [IN]        The param to insert
 *  value           [IN]        The integer value for the param to insert.
 * RETURNS
 *  void
 *****************************************************************************/
void mma_add_param_int(struct MmsAllParamsStruct **allParams, MmsParam param, MSF_UINT32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsAllParams *newParam = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newParam = (MmsAllParams*) MMA_CALLOC(sizeof(MmsAllParams));
    newParam->param = param;
    newParam->type = MMS_PARAM_INTEGER;
    newParam->value.integer = value;
    newParam->next = *allParams;    /* Insert param. Insert first in the list */
    *allParams = (struct MmsAllParamsStruct*)newParam;
}


/*****************************************************************************
 * FUNCTION
 *  mma_add_param_string
 * DESCRIPTION
 *  Inserts a string param first in the list of params
 * PARAMETERS
 *  allParams       [OUT]       The current list
 *  param           [IN]        The param to insert
 *  strKeyValue     [IN]        
 *  strValue        [IN]        The string value for the param to insert. The strValue can be released after the call to this function
 * RETURNS
 *  void
 *****************************************************************************/
void mma_add_param_string(MmsAllParams **allParams, MmsParam param, const char *strKeyValue, const char *strValue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsAllParams *newParam = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newParam = (MmsAllParams*) MMA_CALLOC(sizeof(MmsAllParams));
    newParam->param = param;
    newParam->type = MMS_PARAM_STRING;
    if (param == MMS_TEXT_KEY)
    {
        ASSERT(strKeyValue != NULL);
        newParam->key = (unsigned char*)msf_cmmn_strdup(MSF_MODID_MMA, strKeyValue);
    }
    newParam->value.string = (unsigned char*)msf_cmmn_strdup(MSF_MODID_MMA, strValue);
    newParam->next = *allParams;    /* Insert param. Insert first in the list */
    *allParams = (MmsAllParams*) newParam;
}


/*****************************************************************************
 * FUNCTION
 *  mma_add_entry_string
 * DESCRIPTION
 *  Inserts a string entry first in the list of entries
 * PARAMETERS
 *  entryHeads      [OUT]       The current list
 *  type            [IN]        The type of entry to insert
 *  strValue        [IN]        The string value for the entry to insert. The strValue can be released after the call to this function
 * RETURNS
 *  void
 *****************************************************************************/
void mma_add_entry_string(MmsEntryHeader **entryHeads, MmsEntryHeaderValueType type, const char *strValue)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsEntryHeader *newEntry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    newEntry = (MmsEntryHeader*) MMA_CALLOC(sizeof(MmsEntryHeader));
    newEntry->headerType = type;
    newEntry->value.wellKnownFieldName = (unsigned char*)msf_cmmn_strdup(MSF_MODID_MMA, strValue);
    newEntry->next = *entryHeads;   /* Insert entry. Insert first in the list */
    *entryHeads = newEntry;
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_body_params
 * DESCRIPTION
 *  Creates a MmsBodyParams
 * PARAMETERS
 *  mediaType               [IN]        The media type to add as a integer, see MmsKnownMediaType.
 *  mediaString             [IN]        The media type to add as a string.
 *  name                    [IN]        The name of the body-part.
 *  cnt_id                  [IN]        Content ID of the body-part.
 *  cnt_loc                 [IN]        Content location of the body-part.
 *  charset                 [IN]        Charset of the text body-part.
 *  currContentType(?)      [IN]        The content type if it already exists, otherwise NULL.
 *  targetType(?)           [IN]        The type of message that are created, see MmsBodyPartTarget
 * RETURNS
 *  The created MmsBodyParams
 *****************************************************************************/
MmsBodyParams *mma_create_body_params(
                MmsKnownMediaType mediaType,
                char *mediaString,
                char *name,
                char *cnt_id,
                char *cnt_loc,
                MmsCharset charset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsBodyParams *bp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bp = (MmsBodyParams*) MMA_CALLOC(sizeof(MmsBodyParams));
    bp->targetType = MMS_MULTIPART_MESSAGE;

    if (MMS_VALUE_AS_STRING != mediaType)
    {
        bp->contentType.knownValue = mediaType;
        bp->contentType.strValue = NULL;
    }
    else if (NULL != mediaString)
    {
        bp->contentType.knownValue = MMS_VALUE_AS_STRING;
        bp->contentType.strValue = (unsigned char*)msf_cmmn_strdup(MSF_MODID_MMA, mediaString);
    }

    /* Add the name of the body-part */
    if (NULL != name)
    {
    #if MMA_USE_NAME_PARMS
        mma_add_param_string(&bp->contentType.params, MMS_NAME, NULL, name);    /* Always set the file name */
    #else 
        mma_add_param_string(&bp->contentType.params, MMS_FILENAME, NULL, name);        /* Always set the file name */
    #endif 
    }

    /* Add the content ID of the body-part */
    if (NULL != cnt_id)
    {
        mma_add_entry_string(&bp->entryHeader, MMS_WELL_KNOWN_CONTENT_ID, cnt_id);
    }

    /* Add the content ID of the body-part */
    if (NULL != cnt_loc)
    {
        mma_add_entry_string(&bp->entryHeader, MMS_WELL_KNOWN_CONTENT_LOCATION, cnt_loc);
    }

    /* Add charset of the body-part */
    if (MMS_TYPE_TEXT_PLAIN == mediaType || mma_get_mime_group_from_mime_type(mediaString) == MIME_TYPE_TEXT)
    {
        mma_add_param_int(&bp->contentType.params, MMS_CHARSET, charset);
    }
    else if (mediaString && (0 == strcmp(mediaString, MMS_MEDIA_TYPE_STRING_SMIL)))
    {
        mma_add_param_int(&bp->contentType.params, MMS_CHARSET, MMS_UTF8);
    }

    return bp;
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_name_from_mime_type
 * DESCRIPTION
 *  Create filename from mime type
 * PARAMETERS
 *  o_name      [IN]        if provided, use name part instead of generating all
 *  mime        [IN]        
 * RETURNS
 *  filename
 *****************************************************************************/
char *mma_create_name_from_mime_type(kal_uint8 mod_id, const char *o_name, const char *mime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_mime_type_struct *entry = NULL;
    char *ext = NULL, *name = NULL;
    kal_uint32 ext_size = 0, current_time = 0;
    static kal_uint32 counter = 0;  /* Initialized to zero at start-up */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry = applib_mime_type_look_up((kal_char*) mime, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_NONE);
    if (entry != NULL && entry->file_ext != NULL && strlen(entry->file_ext) > 0)
    {
        ext = entry->file_ext;
        ext_size = strlen(ext);
    }
    else if (o_name != NULL)
    {
        return msf_cmmn_strdup(mod_id, o_name);
    }

    if (o_name != NULL)
    {
        char *str = strrchr(o_name, '.');

        if (str != NULL)
        {
            *str = '\0';
        }

        /* prefix + "." + extension + NULL */
        name = (char*)MSF_MEM_CALLOC(mod_id, 1,strlen(o_name) + 1 + ext_size + 1);
        if (NULL != ext)
        {
            sprintf(name, "%s.%s", o_name, ext);
        }
        else
        {
            sprintf(name, "%s", o_name);
        }
    }
    else    /* generate name part */
    {
        /* current-time + "." + extension + NULL */
        name = (char*)MSF_MEM_CALLOC(mod_id, 1,sizeof(MSF_UINT32) * 2 + 1 + ext_size + 1);
        current_time = MSF_TIME_GET_CURRENT();

        if (NULL != ext)
        {
            sprintf(name, "%lx.%s", (long)(current_time << 8) | (counter & 0xff), ext);
        }
        else    /* w/o extension */
        {
            sprintf(name, "%lx", (long)(current_time << 8) | (counter & 0xff));
        }

        /* Use a counter to prevent problems if the CPU is to fast, i.e., 
           the timer has not been increased between two calls, 256 calls
           to meaCreatefileName during the same time is not likely */
        ++counter;
    }
    return name;
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_name_from_nonascii_name
 * DESCRIPTION
 *  Create ASCII name from non-ASCII object name
 * PARAMETERS
 *  name                    [IN]        Non-ASCII name
 *  with_random_suffix      [IN]        
 * RETURNS
 *  generated name
 *****************************************************************************/
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
char *mma_create_name_from_nonascii_name(const char *name, int counter)
#else
char *mma_create_name_from_nonascii_name(const char *name, kal_bool with_random_suffix)
#endif
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
    char *ext = NULL;
    char *new_name = NULL;
#else
    char *ch = NULL, *new_name = NULL;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name == NULL)
    {
        return NULL;
    }
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
    ext = strrchr(name, '.');

    if (ext)
    {

        new_name =(char*)MMA_CALLOC(mma_get_value_digit_number(counter) + strlen(ext) + 2);

        sprintf(new_name, "%d%s",counter, ext);
    }
    else
    {
        new_name =(char*)MMA_CALLOC(mma_get_value_digit_number(counter) + 1);

        sprintf(new_name, "%d",counter);

    }
#else
    new_name = msf_cmmn_strdup(MSF_MODID_MMA, name);
    ch = new_name;
    while (*ch != '\0')
    {
        if (*ch & 0x80)
        {
            *ch = '_';  /* use '_' to replace non-ASCII char */
        }
        ch += 1;
    }

    if (with_random_suffix) /* name.ext => name[random_part].ext */
    {
        char *new_name2 = (char*)MMA_ALLOC(strlen(new_name) + sizeof(MSF_UINT32) * 2 + 2);
        char *ext = NULL;

        ext = strrchr(new_name, '.');
        if (ext)
        {
            *ext = '\0';
            if (*(ext + 1))
            {
                ext += 1;
            }
        }

        if (ext)
        {
            sprintf(new_name2, "%s_%lx.%s", new_name, MSF_TIME_GET_CURRENT(), ext);
        }
        else
        {
            sprintf(new_name2, "%s_%lx", new_name, MSF_TIME_GET_CURRENT());
        }

        MMA_FREE(new_name);
        new_name = new_name2;
    }
#endif 

    return new_name;
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_object_from_mo
 * DESCRIPTION
 *  Create an object from multipart header information
 * PARAMETERS
 *  mode        [IN]        
 *  msg_id      [IN]        
 *  suffix      [IN]        
 *  mo          [IN]        
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_mms_object_struct *mma_create_object_from_mo(
                   kal_uint8 modid,
                    mma_app_mode_enum mode,
                    kal_uint32 msg_id,
                    MmsFileType suffix,
                    MmsBodyInfoList *mo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj = NULL;
    const char *mime_from_type = NULL, *mime_from_name = NULL;
    char *mime = NULL;
    kal_uint8 storage = mma_get_message_storage(msg_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(mo != NULL);
    mime_from_type = mma_get_mime_type_from_mmsContentType(mo->contentType);
    mime = (char*)mime_from_type;

    obj = (mma_mms_object_struct*) MSF_MEM_CALLOC(modid, 1, sizeof(mma_mms_object_struct));
    ASSERT(obj != NULL);

    /* Get file name */
    if ((obj->file_name = mma_get_name_from_params(modid, mo->contentType->params)) == NULL &&
        (obj->file_name = mma_get_name_from_entry_header(modid, mo->entryHeader)) == NULL)
    {
        obj->file_name = mma_create_name_from_mime_type(modid, NULL, mime);
    }
    mime_from_name = mma_get_mime_type_from_filename_and_mime_string(obj->file_name, NULL);

    if (mime_from_type == NULL)
    {
        /* Fault tolerance: no content type provided. use filename rather than content type to get mimetype */
        mime = (char*)mime_from_name;
    }
    else
    {
        applib_mime_type_struct *entry = NULL;

        if ((entry = applib_mime_type_look_up((char*)mime_from_type, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_NONE)) == NULL ||
            entry->file_ext == NULL || strlen(entry->file_ext) == 0)
        {
            /* Fault tolerance: content type not supported. use filename rather than content type to get mimetype */
            if (applib_mime_type_look_up((char*)mime_from_name, NULL, MIME_TYPE_NONE, MIME_SUBTYPE_NONE) != NULL)
            {
                mime = (char*)mime_from_name;
            }
        }
        else
        {
            /* content type may be wrong so use file extension to find the correct content type 
			   Donot rename the file name, as we used filenames to match object on slides and 
			   if we change file names then mismatch will occur and object will move to attachment*/
            const char *mime_from_name_and_type = NULL;
            mime_from_name_and_type = mma_get_mime_type_from_filename_and_mime_string(obj->file_name, (char *)mime_from_type);

            if (msf_cmmn_strcmp_nc(MMA_UNKNOWN_MIME_STR, mime_from_name) != 0 && msf_cmmn_strcmp_nc(mime_from_type, mime_from_name_and_type) != 0)
            {
                if (msf_cmmn_strcmp_nc(mime_from_type, MMA_MEDIA_TYPE_STRING_DRM1) == 0 ||
                    msf_cmmn_strcmp_nc(mime_from_type, MMA_MEDIA_TYPE_STRING_DRM2) == 0)
                {
                }
                else
                {                    
                    mime = (char*)mime_from_name;
                }
            }
        }
    }
	obj->is_attachment = KAL_TRUE;
    obj->size = mo->size;
    obj->offset = mo->startPos;
    obj->id = mo->number;
    obj->file_path = (char*)MMAlib_getMessagePath(modid, msg_id);

    if (mma_get_mime_group_from_mime_type(mime) == MIME_TYPE_TEXT)
    {
        int fh = 0;

        obj->encoding = obj->charset = translate_mms_charset_to_mma(mma_get_charset_from_params(mo->contentType->params));
		
		/* Fault tolerance: get charset from text content */
        if (obj->charset == MMA_CHARSET_UNKNOWN)
		{		
			/* Fault tolerance: get charset from text content */
		   if ((fh = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, obj->file_path, MSF_FILE_SET_RDONLY, 0, (mma_msg_storage_type_enum)storage)) >= 0)
			{
				kal_int8 bom[MMA_CHARSET_CHECK_BOM_SIZE] = {0};

				if (MSF_FILE_SEEK(fh, obj->offset, MSF_FILE_SEEK_SET) == obj->offset)
				{
					kal_int32 read_size = 0;
					kal_int32 bytes_read = 0;
					if (obj->size < MMA_CHARSET_CHECK_BOM_SIZE)
					{
						read_size = obj->size;
					}
					else
					{
						read_size = MMA_CHARSET_CHECK_BOM_SIZE;
					}
					bytes_read = MSF_FILE_READ(fh, bom, read_size);
					if (bytes_read > 0)
					{
						mma_charset_enum charset = translate_mmi_charset_to_mma(mmi_chset_guess((const char*)bom, bytes_read, CHSET_BASE, CHSET_GUESS_ALL));
						obj->charset = (charset != MMA_CHARSET_UNKNOWN) ? charset : MMA_CHARSET_UTF8;
						obj->encoding = obj->charset;
					}
				}
				MSF_FILE_CLOSE(fh);
			}
		}
    }

    /* Get mime type */
    if (mime != NULL)
    {
        obj->mime_str = msf_cmmn_strdup(modid, mime);
    }
    if (mime_from_type != NULL)
    {

        if (msf_cmmn_strcmp_nc(mime_from_type, MMA_MEDIA_TYPE_STRING_DRM1) == 0)
        {
            obj->drm_process_type = MMA_DRM_PROCESS_FORWARD_LOCK_CD;
        }
        else if (msf_cmmn_strcmp_nc(mime_from_type, MMA_MEDIA_TYPE_STRING_DRM2) == 0)
        {
            obj->drm_process_type = MMA_DRM_PROCESS_SEPERATE_DELIVERY;
        }
        else
        {
            obj->drm_process_type = MMA_DRM_NO_PROTECTION;
        }
    }
    else
    {
        obj->drm_process_type = MMA_DRM_NO_PROTECTION;
    }
#ifdef __DRM_SUPPORT__
    if (obj->drm_process_type != MMA_DRM_NO_PROTECTION)
    {
        const char *mime = mma_drm_get_content_type_vf(obj,obj->drm_process_type, obj->file_path, obj->offset, obj->size, storage);

        if (mime == NULL)
        {
            obj->drm_mime_type = msf_cmmn_strdup(modid, MMA_UNKNOWN_MIME_STR);
        }
        else    /* use the real object type */
        {
			/* replace with actual file name */
			obj->file_name = mma_replace_file_ext_with_input(modid, obj->file_name, mime);
            obj->drm_mime_type = msf_cmmn_strdup(modid, mime);
        }
    }
#endif /* __DRM_SUPPORT__ */ 
/*transform illegal filenames here and set the extentions here*/
	mma_transform_illegal_name(obj->file_name);
	mma_parse_check_and_correct_filename(obj);
    /* obj->is_attachment: no need to give value */
    obj->is_virtual_file = KAL_TRUE;
    obj->is_restricted = mma_is_restricted_type_vf(
                            mms_get_content_class(),
                            obj->file_path,
                            obj->mime_str,
                            obj->offset,
                            obj->size,
                            storage);
    /* obj->xmlId: no need to give value */
    /* obj->xmlDrmType: no need to give value */
#ifdef __DRM_SUPPORT__
    if (mode == MMA_MODE_EDIT || mode == MMA_MODE_VIEW || mode == MMA_MODE_SEND || mode == MMA_MODE_FORWARD)
    {
        obj->drm_type = mma_drm_check_right_vf(obj->drm_process_type, obj->file_path, obj->offset, obj->size, storage);
    }

#endif
   // if (mode == MMA_MODE_RAW)					chetan:need this for all types of objects
   // {
        obj->content_id = mma_get_content_id_from_entry_header(mo->entryHeader, modid);
        obj->content_location = mma_get_content_location_from_entry_header(mo->entryHeader, modid);
  //  }

    return obj;
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_sls_object_from_mma_slide_object
 * DESCRIPTION
 *  Create a SLS object from mma object informaion
 * PARAMETERS
 *  type                        [IN]        
 *  slide                       [IN]        
 *  SlsMediaObjectType(?)       [IN]        
 *  mma_slide_struct(?)         [IN]        
 * RETURNS
 *  SlsMediaObject
 *****************************************************************************/
SlsMediaObject *mma_create_sls_object_from_mma_slide_object(SlsMediaObjectType type, const mma_mms_slide_struct *slide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   // const mma_slide_object_struct *s_obj = NULL;
    SlsMediaObject *obj = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Sanity check */
    if (slide == NULL)
    {
        return NULL;
    }

    obj = (SlsMediaObject*) MMA_CALLOC(sizeof(SlsMediaObject));
    switch (type)
        {
        case SLS_OBJECT_TYPE_TEXT:
            if(!slide->txt.object || slide->txt.object->is_invallid)
    {
			  MMA_FREE(obj);
        return NULL;
    }
			 if (slide->txt.begin > 0 || (slide->txt.end > 0 && slide->txt.end * MMA_1_SEC_IN_MSEC != slide->duration * MMA_1_SEC_IN_MSEC))
    {
					 obj->beginT = slide->txt.begin * MMA_1_SEC_IN_MSEC; /* Begin and end time */
					 obj->endT = slide->txt.end * MMA_1_SEC_IN_MSEC;
				}
		    obj->src = msf_cmmn_strdup(MSF_MODID_MMA, slide->txt.object->file_name);
            obj->region = msf_cmmn_strdup(MSF_MODID_MMA, MMA_CFG_TEXT_REGION_NAME);
            obj->color = slide->txt.fg_color;
			if((SLS_COLOR_NOT_USED | slide->txt.fg_color) == SLS_COLOR_NOT_USED)
			{
				obj->color = SLS_COLOR_NOT_USED;
			}
            obj->slsparamList = (SlsParameterList*) MMA_CALLOC(sizeof(SlsParameterList));
            obj->slsparamList->param.name = (char*)MMA_TEXT_SIZE_NAME_STR;
            obj->slsparamList->param.value = (char*)mma_enum_to_text_size_str((mma_text_size_enum)slide->txt.text_size);
            if (slide->txt.text_style != 0)
            {

                obj->slsparamList->next = (SlsParameterList*) MMA_CALLOC(sizeof(SlsParameterList));
                obj->slsparamList->next->param.name = (char*)MMA_TEXT_STYLE_NAME_STR;
                obj->slsparamList->next->param.value = (char*)mma_enum_to_text_style_str((mma_text_style_enum)slide->txt.text_style);
                obj->slsparamList->next->next = NULL;

            }
            break;
        case SLS_OBJECT_TYPE_IMAGE:
			if(!slide->img.object || slide->img.object->is_invallid)
    {
			 MMA_FREE(obj);
			 return NULL;
			}
			if (slide->img.begin > 0 || (slide->img.end > 0 && slide->img.end * MMA_1_SEC_IN_MSEC != slide->duration * MMA_1_SEC_IN_MSEC))
        {
					obj->beginT = slide->img.begin * MMA_1_SEC_IN_MSEC; /* Begin and end time */
					obj->endT = slide->img.end * MMA_1_SEC_IN_MSEC;
				}
  	       obj->src = msf_cmmn_strdup(MSF_MODID_MMA, slide->img.object->file_name);
           obj->region = msf_cmmn_strdup(MSF_MODID_MMA, MMA_CFG_IMAGE_REGION_NAME);
            break;
        case SLS_OBJECT_TYPE_VIDEO:
			if(!slide->vid.object || slide->vid.object->is_invallid)
			{
			 MMA_FREE(obj);
			 return NULL;
			}
			if (slide->vid.begin > 0 || (slide->vid.end > 0 && slide->vid.end * MMA_1_SEC_IN_MSEC != slide->duration * MMA_1_SEC_IN_MSEC))
				{
					obj->beginT = slide->vid.begin * MMA_1_SEC_IN_MSEC; /* Begin and end time */
					obj->endT = slide->vid.end * MMA_1_SEC_IN_MSEC;
        }
  	       obj->src = msf_cmmn_strdup(MSF_MODID_MMA, slide->vid.object->file_name);
            obj->region = msf_cmmn_strdup(MSF_MODID_MMA, MMA_CFG_IMAGE_REGION_NAME);
           break;
        case SLS_OBJECT_TYPE_AUDIO:
			if(!slide->aud.object || slide->aud.object->is_invallid)
			{
			  MMA_FREE(obj);
			 return NULL;
    }
			if (slide->aud.begin > 0 || (slide->aud.end > 0 && slide->aud.end * MMA_1_SEC_IN_MSEC != slide->duration * MMA_1_SEC_IN_MSEC))
    {
					obj->beginT = slide->aud.begin * MMA_1_SEC_IN_MSEC; /* Begin and end time */
					obj->endT = slide->aud.end * MMA_1_SEC_IN_MSEC;
				}
  	       obj->src = msf_cmmn_strdup(MSF_MODID_MMA, slide->aud.object->file_name);
            break;
        default:
           MMA_FREE(obj->src);
            MMA_FREE(obj);
            return NULL;
    }



    


    return obj;
}


/*****************************************************************************
 * FUNCTION
 *  mma_create_sls_object_list_from_mma_slide_object
 * DESCRIPTION
 *  Create a SLS object list from mma object informaion
 * PARAMETERS
 *  SlsMediaObjectType  [IN]
 *  mma_slide_struct    [IN]
 * RETURNS
 *  SlsMediaObject
 *****************************************************************************/
SlsMediaObject *mma_create_sls_object_list_from_mma_slide_object(SlsMediaObjectType type, 
    const mma_mms_slide_struct *slide)
{
    const mma_mms_slide_ref_object_struct *s_obj = NULL;
    SlsMediaObject *obj = NULL, *head = NULL, *tail = NULL;

    ASSERT(type == SLS_OBJECT_TYPE_REF);

    /* Sanity check */
    if (slide == NULL || slide->ref_items == NULL)
    {
        return NULL;
    }

    s_obj = slide->ref_items;
    while (s_obj)
    {
        if (/*type == s_obj->type && */s_obj->object != NULL && s_obj->object->file_name != NULL && !s_obj->object->is_invallid)
        {
            obj = MMA_CALLOC(sizeof(SlsMediaObject));
	        obj->src = msf_cmmn_strdup(MSF_MODID_MMA, s_obj->object->file_name);
        
            if (s_obj->begin > 0 || (s_obj->end > 0 && s_obj->end * MMA_1_SEC_IN_MSEC != slide->duration * MMA_1_SEC_IN_MSEC))
            {
                obj->beginT = s_obj->begin * MMA_1_SEC_IN_MSEC;  /* Begin and end time */
                obj->endT = s_obj->end * MMA_1_SEC_IN_MSEC;
            }

            /* append to tail */
            if (head == NULL)
            {
                head = obj;
            }
            if (tail)
            {
                tail->next = obj;
            }
            tail = obj;
        }
        s_obj = s_obj->next;
    }
    return head;
}



/*****************************************************************************
 * FUNCTION
 *  mma_copy_sls_root_layout
 * DESCRIPTION
 *  Copies an SlsRootLayout struct
 * PARAMETERS
 *  source      [IN]        Source data
 *  dest        [OUT]       Destination data
 * RETURNS
 *  void
 *****************************************************************************/
void mma_copy_sls_root_layout(const SlsRootLayout *source, SlsRootLayout *dest, mma_mms_description_body_struct *body)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (source == NULL || dest == NULL)
    {
        return;
    }

    if (source->bgColor != SLS_COLOR_NOT_USED)
    {
        body->bgColor = source->bgColor;
    }
    else
    {
        body->bgColor = MMA_CFG_SMIL_BG_COLOR;
    }

    dest->bgColor = body->bgColor;

    dest->cx.type = source->cx.type;
    dest->cx.value = source->cx.value;
    dest->cy.type = source->cy.type;
    dest->cy.value = source->cy.value;
}


/*****************************************************************************
 * FUNCTION
 *  mma_copy_sls_region
 * DESCRIPTION
 *  Copies an sls region
 * PARAMETERS
 *  source          [IN]        The source region
 *  destination     [OUT]       The destination region
 * RETURNS
 *  void
 *****************************************************************************/
void mma_copy_sls_region(const SlsRegion *source, mma_mms_object_area_struct **destination)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (source == NULL || *destination == NULL)
    {
        return;
    }

    (*destination)->x.type = source->position.cx.type;
    (*destination)->x.value = source->position.cx.value;
    (*destination)->y.type = source->position.cy.type;
    (*destination)->y.value = source->position.cy.value;

    (*destination)->h.type = source->size.cy.type;
    (*destination)->h.value = source->size.cy.value;
    (*destination)->w.type = source->size.cx.type;
    (*destination)->w.value = source->size.cx.value;

  //  (*destination)->fit = source->fit;
                }



/*****************************************************************************
 * FUNCTION
 *  mma_insert_addr_to_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list            [IN/OUT]        
 *  addrType        [IN]            
 *  name            [IN]            
 *  address         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mma_insert_addr_to_list(MmsAddressList **list, MmsAddressType addrType, char *name, char *address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsAddressList *item = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (address == NULL || list == NULL)
    {
        return;
    }

    item = (MmsAddressList*) MMA_CALLOC(sizeof(MmsAddressList));
    item->current.addrType = addrType;
    if (item->current.addrType == MMS_EMAIL && name != NULL)
    {
        item->current.name.charset = mma_is_ascii_string(name) ? MMS_US_ASCII : MMS_UTF8;
        /* item->current.name.size = strlen(name); */
        item->current.name.text = msf_cmmn_strdup(MSF_MODID_MMA, name);
    }
    item->current.address = msf_cmmn_strdup(MSF_MODID_MMA, address);
    ASSERT(item->current.address);

    if (*list == NULL)
    {
        *list = item;
    }
    else
    {
        MmsAddressList *ptr = *list;

        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = item;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_append_addr_to_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  list            [IN/OUT]        
 *  addrType        [IN]            
 *  name                [IN]         
 *  address         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mma_append_addr_to_list(kal_uint8 mod_id, mma_mms_addr_list_struct **list, mma_addr_type_enum addr_type, char *name, char *address, mma_address_group_type_enum group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_addr_list_struct *item = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (address == NULL || list == NULL)
    {
        return;
    }

    item = (mma_mms_addr_list_struct*) MSF_MEM_CALLOC(mod_id, 1, sizeof(mma_mms_addr_list_struct));
    item->addr_type = addr_type;
	item->group = group;
 /*   if (item->.addr_type == MMA_ADDR_TYPE_EMAIL && name != NULL)
    {
        item->current.name.charset = mma_is_ascii_string(name) ? MMS_US_ASCII : MMS_UTF8;
        item->current.name.text = msf_cmmn_strdup(mod_id, name);
    }*/
    item->address = msf_cmmn_strdup(mod_id, address);
    //item->me.charset = MMA_CHARSET_UTF8;
    ASSERT(item->address);

    if (*list == NULL)
    {
        *list = item;
    }
    else
    {
        mma_mms_addr_list_struct *ptr = *list;

        while (ptr->next)
        {
            ptr = ptr->next;
        }
        ptr->next = item;
		item->prev = ptr;
    }
}







/*****************************************************************************
 * FUNCTION
 *  mma_insert_slide
 * DESCRIPTION
 *  Append an empty slide to body->current_slide
 * PARAMETERS
 *  body            [IN]        
 *  duration        [IN]        
 * RETURNS
 *  mma_slide_struct
 *****************************************************************************/

mma_mms_slide_struct *mma_insert_slide(MSF_UINT8 mod_id, mma_mms_description_body_struct *body, kal_uint32 duration)
{

    mma_mms_slide_struct *slide = NULL;

   
    slide = (mma_mms_slide_struct*) MSF_MEM_CALLOC(mod_id, 1, sizeof(mma_mms_slide_struct));
    if (body->curr_slide != NULL)
    {
        slide->next = body->curr_slide->next;
		slide->prev = body->curr_slide;
        body->curr_slide->next = slide;
    }
    else
    {
        body->slides = slide;
        slide->next = NULL;
    }

    slide->duration = duration;
    body->slide_no++;
    body->curr_slide = slide;
    return slide;
}   /* mma_insert_slide */


/*****************************************************************************
 * FUNCTION
 *  mma_insert_object_to_tail
 * DESCRIPTION
 *  Insert an empty slide
 * PARAMETERS
 *  body        [IN]        
 *  obj         [IN]         
 * RETURNS
 *  mma_slide_struct
 *****************************************************************************/
mma_mms_object_struct *mma_insert_object_to_tail(MSF_UINT8 mod_id, mma_mms_description_body_struct *body, mma_mms_object_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(body != NULL);

    if (obj == NULL)
    {
        obj = (mma_mms_object_struct*) MSF_MEM_CALLOC(mod_id, 1,sizeof(mma_mms_object_struct));
    }

    if (body->objects != NULL)
    {
        mma_mms_object_struct *ptr = body->objects;

        for (; ptr->next != NULL; ptr = ptr->next);
        ptr->next = obj;
    }
    else
    {
        body->objects = obj;
    }

    return obj;
}


/*****************************************************************************
 * FUNCTION
 *  mma_insert_unref_item_to_tail
 * DESCRIPTION
 *  Insert an attachment (mainly for mixed-to-SMIL conversion)
 * PARAMETERS
 *  body        [IN/OUT]        
 *  obj         [IN]            
 * RETURNS
 *  mma_result_enum
 *****************************************************************************/
mma_mms_attachment_info_struct *mma_insert_unref_item_to_tail(MSF_UINT8 mod_id, mma_mms_description_body_struct *body, mma_mms_object_struct *obj)
{

    mma_mms_attachment_info_struct *curr = NULL;

    ASSERT(body != NULL && obj != NULL);

    curr = (mma_mms_attachment_info_struct*) MSF_MEM_CALLOC(mod_id, 1, sizeof(mma_mms_attachment_info_struct));
    curr->object = obj;
    curr->next = NULL;

    if (body->attachment == NULL)
    {
        body->attachment = curr;
    }
    else    
    {
        mma_mms_attachment_info_struct *ptr = NULL;

        for (ptr = body->attachment; ptr->next != NULL; ptr = ptr->next);
        ptr->next = curr;
		curr->prev = ptr;
    }
    return curr;
}


/*****************************************************************************
 * FUNCTION
 *  mma_insert_slide_obj
 * DESCRIPTION
 *  Insert an object to the slide (mainly for mixed-to-SMIL conversion)
 * PARAMETERS
 *  gType                       [IN]        
 *  slide                       [IN]        
 *  obj                         [IN]         
 * RETURNS
 *  mma_slide_object_struct
 *****************************************************************************/
mma_mms_slide_ref_object_struct *mma_insert_slide_obj(MSF_UINT8 mod_id,
                            applib_mime_type_enum gType,
                            mma_mms_slide_struct *slide,
                            mma_mms_object_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_ref_object_struct *s_obj = NULL, *temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(slide != NULL && (gType == MIME_TYPE_TEXT || gType == MIME_TYPE_IMAGE ||
                             gType == MIME_TYPE_VIDEO || gType == MIME_TYPE_AUDIO || gType == MIME_TYPE_APPLICATION));

	
  
    switch (gType)
    {
        case MIME_TYPE_TEXT:
           // slide->txt = SLS_OBJECT_TYPE_TEXT;
            slide->txt.bg_color = MMA_CFG_SMIL_BG_COLOR;
            slide->txt.fg_color = MMA_CFG_SMIL_FG_COLOR;
            slide->txt.text_size = SLS_TEXT_SIZE_DEFAULT;
            slide->txt.object = obj;
            slide->txt.id = obj->id;
            break;
        case MIME_TYPE_AUDIO:
			slide->aud.object = obj; 
			slide->aud.id = obj->id;        
            break;
        case MIME_TYPE_IMAGE:
			slide->img.object = obj; 
			slide->img.id = obj->id;            
            break;
        case MIME_TYPE_VIDEO:
#ifdef __MMI_MMS_VIDEO_FEATURE__
			slide->vid.object = obj;   
			slide->vid.id = obj->id; 
            break;
#endif
        case MIME_TYPE_APPLICATION:
		    s_obj = (mma_mms_slide_ref_object_struct*) MSF_MEM_CALLOC(mod_id, 1, sizeof(mma_mms_slide_ref_object_struct));            
			s_obj->object = obj;
			s_obj->id = obj->id;
			if(slide->ref_items == NULL)
			{
			 slide->ref_items = s_obj;
			 s_obj->next = NULL;
			}
			else
			{			
			temp = slide->ref_items;
			while(temp->next)
			{
			 temp = temp->next;
			 
			}
			temp->next = s_obj;
			}
            break;
    }
   // s_obj->obj = obj;


    return s_obj;
}


/*****************************************************************************
 * FUNCTION
 *  mma_is_ascii_string
 * DESCRIPTION
 *  Check if the string is all ASCII char
 * PARAMETERS
 *  str     [IN]        
 * RETURNS
 *  TRUE/FALSE
 *****************************************************************************/
kal_bool mma_is_ascii_string(const char *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str == NULL)
    {
        return KAL_TRUE;
    }

    len = strlen(str);
    for (i = 0; i < len; i++)
    {
        if (*(str + i) & 0x80)
        {
            return KAL_FALSE;
        }
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_is_ascii_file
 * DESCRIPTION
 *  Check if the text file is all ASCII char
 * PARAMETERS
 *  filepath        [IN]        
 *  filename(?)     [IN]        
 * RETURNS
 *  TRUE/FALSE
 *****************************************************************************/
kal_bool mma_is_ascii_file(const char *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int fh = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((fh = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, filepath, MSF_FILE_SET_RDONLY, 0, MMA_MSG_STORAGE_NONE)) >= 0)
    {
        char *buffer = NULL;
        int filesize = MSF_FILE_GETSIZE_EXT(filepath, (msf_mms_storage_enum)MMA_MSG_STORAGE_NONE);
        int i = 0, buffer_size = 0;

        while (filesize)
        {
            buffer_size = (filesize > MMS_MAX_CHUNK_SIZE) ? MMS_MAX_CHUNK_SIZE : filesize;
            buffer = (char*)MMA_CALLOC(buffer_size);
            buffer_size = MSF_FILE_READ(fh, buffer, buffer_size);
            filesize -= buffer_size;

            for (i = 0; i < buffer_size; i++)
            {
                if (*(buffer + i) & 0x80)
                {
                    MMA_FREE(buffer);
                    MSF_FILE_CLOSE(fh);
                    return KAL_FALSE;
                }
            }
            MMA_FREE(buffer);
        }
        MSF_FILE_CLOSE(fh);
    }
    else
    {
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_is_drm_message
 * DESCRIPTION
 *  Check if the message contains any DRM objects
 * PARAMETERS
 *  body        [IN]        
 * RETURNS
 *  MSF_BOOL
 *****************************************************************************/
kal_bool mma_is_drm_message(mma_mms_description_body_struct *body)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *obj = body->objects;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (obj)
    {
        if (obj->drm_process_type == MMA_DRM_PROCESS_FORWARD_LOCK_CD || obj->drm_process_type == MMA_DRM_PROCESS_SEPERATE_DELIVERY)
        {
            return KAL_TRUE;
        }
        obj = obj->next;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_is_follow_content_class
 * DESCRIPTION
 *  Check if the message follows content class
 * PARAMETERS
 *  body        [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mma_is_follow_content_class(mma_mms_description_body_struct *body)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (body)
    {
        mma_mms_object_struct *obj = body->objects;

        while (obj)
        {
            if (obj->is_restricted == KAL_FALSE)
            {
                return KAL_FALSE;
            }
            obj = obj->next;
        }
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_is_valid_address
 * DESCRIPTION
 *  Check if the address is valid address for editor
 * PARAMETERS
 *  addr        [IN]        
 * RETURNS
 *  TRUE if the address is valid
 *****************************************************************************/
MSF_BOOL mma_is_valid_address(MmsAddress *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr == NULL || addr->address == NULL)
    {
        return FALSE;
    }

    switch (addr->addrType)
    {
        case MMS_PLMN:
    #if MMA_CFG_PLMN_STRICT_CHECK
         if (applib_is_valid_number((kal_uint8 *)addr->address) == APPLIB_INVALID_NUMBER)
         {
            return FALSE;
         }     
    #endif /* MMA_CFG_PLMN_STRICT_CHECK */ 
            break;

        case MMS_EMAIL:
         if (applib_is_valid_email_address(addr->address) == KAL_FALSE)
         {
            return FALSE;
         }
         break;

        case MMS_IPV4:
            return TRUE;
          
        default:
            return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mma_is_restricted_type_vf
 * DESCRIPTION
 *  Check if the virtual file is restricted type
 * PARAMETERS
 *  content_class       [IN]        
 *  filename            [IN]        Parent filename
 *  mime                [IN]        Virtual file mime type
 *  offset              [IN]        Offset in parent file
 *  size                [IN]        Virtual file size
 *  class(?)            [IN]        
 * RETURNS
 *  TRUE: restricted; FALSE: non-restricted
 *****************************************************************************/
kal_bool mma_is_restricted_type_vf(
            mms_content_class_enum content_class,
            const char *filename,
            const char *mime,
            kal_uint32 offset,
            kal_uint32 size,
            kal_uint8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const char *restricted_types = mma_get_restricted_attachment_type();
    const char *restricted_image_types = mma_get_restricted_image_type();

#ifdef __DRM_SUPPORT__
    mma_drm_type_for_process_enum drmType = MMA_DRM_NO_PROTECTION;
#endif 
    kal_bool is_restricted = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(filename != NULL);
    if (size > mms_get_max_msg_size_in_restricted_mode())
    {
        return KAL_FALSE;
    }
    else if (mime == NULL)
    {
        return KAL_FALSE;
    }

    /* DRM check  */
#ifdef __DRM_SUPPORT__
    if (msf_cmmn_strcmp_nc(mime, MMA_MEDIA_TYPE_STRING_DRM2) == 0)      /* check *.dcf file or DRM segment in MMS */
    {
#ifdef __MMI_MMS_MMA_DRM_ENCODING__
        char *vFileName = NULL;
        MSF_INT32 handle = 0;
        mma_drm_method_enum drm_method = MMA_DRM_METHOD_NONE;

        if ((handle = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, filename, MSF_FILE_SET_RDONLY, 0, storage)) >= 0)
        {
            vFileName = MMA_CALLOC(MMA_MAX_VIRTUAL_FILE_PATH_SIZE);
            ASSERT(vFileName != NULL);
            if (MSF_FILE_GEN_VIRTUAL_FILENAME(MSF_MODID_MMA, handle, vFileName, MMA_MAX_VIRTUAL_FILE_PATH_SIZE, offset, size) == HDI_FILE_OK)
            {                            
                drm_method = mma_drm_get_method_type(-1, vFileName, storage);
            }                            
            MMA_FREE(vFileName);
            MSF_FILE_CLOSE(handle);
        }

        if(drm_method == MMA_DRM_METHOD_FORWARD_LOCK)
        {
            if (content_class == MMS_CONTENT_CLASS_TEXT || content_class == MMS_CONTENT_CLASS_IMAGE_BASIC)
            {
                return KAL_FALSE;
            }
            drmType = MMA_DRM_PROCESS_FORWARD_LOCK_CD;
            mime = mma_drm_get_content_type_vf(NULL, MMA_DRM_PROCESS_FORWARD_LOCK_CD, filename, offset, size, storage);  /* processed */
        }
        else
        {
            return KAL_FALSE;
        }
#else
        return KAL_FALSE;
#endif /* __MMI_MMS_MMA_DRM_ENCODING__ */
    }
    else if (msf_cmmn_strcmp_nc(mime, MMA_MEDIA_TYPE_STRING_DRM1) == 0) /* check *.dm file or DRM segment in MMS */
    {
        if (content_class == MMS_CONTENT_CLASS_TEXT || content_class == MMS_CONTENT_CLASS_IMAGE_BASIC)
        {
            return KAL_FALSE;
        }
        drmType = MMA_DRM_PROCESS_FORWARD_LOCK_CD;
        mime = mma_drm_get_content_type_vf(NULL, MMA_DRM_PROCESS_FORWARD_LOCK_CD, filename, offset, size, storage);    /* processed */
    }

    if (mime == NULL)
    {
        return KAL_FALSE;
    }
#endif /* __DRM_SUPPORT__ */ 

    /* Format check  */
    if (strstr(restricted_types, mime) == NULL)
    {
        return KAL_FALSE;
    }

    /* Image resolution check: we don't check FL/CD image  */
#ifdef __DRM_SUPPORT__
    if (size > 0 && restricted_image_types != NULL && drmType != MMA_DRM_PROCESS_FORWARD_LOCK_CD && strstr(restricted_image_types, mime))
#else 
    if (size > 0 && restricted_image_types != NULL && strstr(restricted_image_types, mime))
#endif 
    {
        char *v_file_name = NULL;
        int fileHandle = 0;

        /* generate virtual file */
        if ((fileHandle = mma_msf_file_open_in_blocking_mode(MSF_MODID_MMA, filename, MSF_FILE_SET_RDONLY, 0, (mma_msg_storage_type_enum)storage)) < 0)
        {
            return KAL_FALSE;
        }

        v_file_name = (char*)MMA_CALLOC(MMA_MAX_VIRTUAL_FILE_PATH_SIZE);
        ASSERT(v_file_name != NULL);
        if (MSF_FILE_GEN_VIRTUAL_FILENAME
            (MSF_MODID_MMA, fileHandle, v_file_name, MMA_MAX_VIRTUAL_FILE_PATH_SIZE, offset, size) == MSF_FILE_OK)
        {
            /* change virtual file extension .r to original extension */
#ifndef __OP12_MMS_CONTENT_CLASS_IMAGE_RESOLUTION_CHECK_OFF__
            kal_int32 width = 0, height = 0, r_width = 0, r_height = 0;
#endif
            char *filename_ucs2 = NULL, *name = NULL;
            kal_bool is_progressive;

            name = mma_create_name_from_mime_type(MSF_MODID_MMA, v_file_name, mime);
            MMA_FREE(v_file_name);
            v_file_name = name;
            filename_ucs2 = (char*)MSF_FILE_GET_EXTERNAL_FILENAME_EXT(MSF_MODID_MMA, v_file_name, MSF_MMS_STORAGE_PHONE);

#ifndef __OP12_MMS_CONTENT_CLASS_IMAGE_RESOLUTION_CHECK_OFF__
            mms_get_max_image_resolution_in_restricted_mode(&r_width, &r_height);            
            if (gdi_image_get_dimension_file(filename_ucs2, &width, &height) != GDI_SUCCEED ||
                width * height > r_width * r_height)
            {
                is_restricted = KAL_FALSE;
            }
#endif /* __OP12_MMS_CONTENT_CLASS_IMAGE_RESOLUTION_CHECK_OFF__ */

            
            if (gdi_image_jpeg_is_progressive((char *)filename_ucs2, &is_progressive) != GDI_SUCCEED ||
                is_progressive == TRUE)
            {
                is_restricted = KAL_FALSE;
            }
            MMA_FREE(filename_ucs2);
        }
        MMA_FREE(v_file_name);
        MSF_FILE_CLOSE(fileHandle);
    }
    return is_restricted;
}


/*****************************************************************************
 * FUNCTION
 *  mma_remove_invalid_address
 * DESCRIPTION
 *  Remove illegal and unsupported addresses
 * PARAMETERS
 *  header      [IN/OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_remove_invalid_address(MSF_UINT8 mod_id, MmsGetHeader *header, mma_app_mode_enum mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern void freeMmsAddressList(MSF_UINT8 modId, MmsAddressList * addressList);
    MmsAddressList *list = NULL, *prev = NULL;
    kal_bool email_len_chk = (kal_bool)(!(mode == MMA_MODE_HEADER || mode == MMA_MODE_VIEW || mode == MMA_MODE_RAW));

    if (header == NULL)
    {
        return;
    }

    /* From */
    if (mma_is_valid_address(&header->from) == FALSE  ||
        (email_len_chk && header->from.addrType == MMS_EMAIL  && strlen(header->from.address) > MMA_MAX_ADDR_LEN))
    {
        MSF_MEM_FREE(mod_id, header->from.address);
        header->from.address = NULL;
    }

    /* To */
    list = header->to;
    prev = NULL;
    while (list)
    {
        /* Remove non-PLMN/EMAIL type address */
        if (mma_is_valid_address(&list->current) == FALSE  ||
        (email_len_chk && list->current.addrType == MMS_EMAIL  && strlen(list->current.address) > MMA_MAX_ADDR_LEN))
        {
            if (prev == NULL)
            {
                header->to = list->next;
                list->next = NULL;
                freeMmsAddressList(mod_id, list);
                list = header->to;
            }
            else
            {
                prev->next = list->next;
                list->next = NULL;
                freeMmsAddressList(mod_id, list);
                list = prev->next;
            }
        }
        else
        {
            prev = list;
            list = list->next;
        }
    }

    /* Cc */
    list = header->cc;
    prev = NULL;
    while (list)
    {
        /* Remove non-PLMN/EMAIL type address */
        if (mma_is_valid_address(&list->current) == FALSE || 
        (email_len_chk && list->current.addrType == MMS_EMAIL  && strlen(list->current.address) > MMA_MAX_ADDR_LEN))
        {
            if (prev == NULL)
            {
                header->cc = list->next;
                list->next = NULL;
                freeMmsAddressList(mod_id, list);
                list = header->cc;
            }
            else
            {
                prev->next = list->next;
                list->next = NULL;
                freeMmsAddressList(mod_id, list);
                list = prev->next;
            }
        }
        else
        {
            prev = list;
            list = list->next;
        }
    }

    /* Bcc */
    list = header->bcc;
    prev = NULL;
    while (list)
    {
        /* Remove non-PLMN/EMAIL type address */
        if (mma_is_valid_address(&list->current) == FALSE ||
        (email_len_chk && list->current.addrType == MMS_EMAIL  && strlen(list->current.address) > MMA_MAX_ADDR_LEN))
        {
            if (prev == NULL)
            {
                header->bcc = list->next;
                list->next = NULL;
                freeMmsAddressList(mod_id, list);
                list = header->bcc;
            }
            else
            {
                prev->next = list->next;
                list->next = NULL;
                freeMmsAddressList(mod_id, list);
                list = prev->next;
            }
        }
        else
        {
            prev = list;
            list = list->next;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_remove_slide_by_index
 * DESCRIPTION
 *  Remove a slide by index (0~)
 * PARAMETERS
 *  body        [IN]        
 *  index       [IN]        
 * RETURNS
 *  mma_slide_struct(?)
 *****************************************************************************/
/*
void mma_remove_slide_by_index(mma_body_struct *body, kal_uint32 index)
{
    
    mma_slide_struct *curr = NULL, *prev = NULL;
    mma_slide_object_struct *list = NULL, *o_ptr = NULL;
    kal_uint32 i = 0;

  
    if (body->slides == NULL)
    {
        return;
    }

    curr = body->slides;
    while (curr != NULL)
    {
        if (i == index)
        {
            break;
        }
        prev = curr;
        curr = curr->next;
        i++;
    }

    if (curr == NULL)   
    {
        return;
    }

    if (prev == NULL)
    {
        body->slides = curr->next;
    }
    else
    {
        prev->next = curr->next;
    }

    list = curr->slide_objs;
    while (list)   
    {
        o_ptr = list;
        list = list->next;
        o_ptr->obj = NULL;
        MMA_FREE(o_ptr->region);
        o_ptr->region = NULL;
        MMA_FREE(o_ptr->alt);
        MMA_FREE(o_ptr);
    }

    MMA_FREE(curr);
    body->slide_no--;
    body->current_slide = body->slides;
}  */ /* mma_remove_slide_by_index */


/*****************************************************************************
 * FUNCTION
 *  mma_remove_object_in_slide
 * DESCRIPTION
 *  Remove object reference in slide structure
 * PARAMETERS
 *  list        [IN/OUT]        
 *  obj         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mma_remove_object_in_slide(mma_mms_slide_struct *list, mma_mms_object_struct *obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *slide = list;
    mma_mms_slide_ref_object_struct *s_obj = slide->ref_items, *prev = NULL, *next = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(obj != NULL);
    while (slide != NULL)
    {
       // mma_slide_object_struct *s_obj = slide->slide_objs, *prev = NULL, *next = NULL;

         
            if (slide->txt.object == obj)
            {
                slide->txt.object = NULL;
                MMA_FREE(slide->txt.region_area);
                slide->txt.region_area = NULL;
                MMA_FREE(slide->txt.alt);
               
            }
			
			if (slide->img.object == obj)
            {
                slide->img.object = NULL;
                MMA_FREE(slide->img.region_area);
                slide->img.region_area = NULL;
                MMA_FREE(slide->img.alt);
               
            }

			if (slide->vid.object == obj)
            {
                slide->vid.object = NULL;
                MMA_FREE(slide->vid.region_area);
                slide->vid.region_area = NULL;
                MMA_FREE(slide->vid.alt);
               
            }

			if (slide->aud.object == obj)
            {
                slide->aud.object = NULL;
             //   MMA_FREE(slide->aud.region_area);
                slide->aud.region_area = NULL;
                MMA_FREE(slide->aud.alt);
               
            }


			

        while (s_obj)
        {
            next = s_obj->next;
				if (s_obj->object == obj)
            {
                if (prev == NULL)
                {
					    slide->ref_items = s_obj->next;
                }
                else
                {
                    prev->next = s_obj->next;
                }

					s_obj->object = NULL;
					MMA_FREE(s_obj->region_area);
					s_obj->region_area = NULL;
                s_obj->next = NULL;
                MMA_FREE(s_obj->alt);
                MMA_FREE(s_obj);
             }
            else
            {
                prev = s_obj;
            }
            s_obj = next;

        }

          
        slide = slide->next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_update_subject_text
 * DESCRIPTION
 *  Truncates the subject text to 40 characters only
 * PARAMETERS
 *  subject         [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void mma_update_subject_text(MSF_UINT8 mod_id, MmsEncodedText *subject)
{
    kal_uint32 length = 0;
    kal_char* temp_buf = NULL;

    length = msf_cmmn_utf8_strlen(subject->text);

    if (length > MMA_MAX_SUBJECT_LEN)
    {
        temp_buf = mms_msf_cmmn_utf8_strncpy(mod_id, subject->text, MMA_MAX_SUBJECT_LEN);
        MSF_MEM_FREE(mod_id, subject->text);
        subject->text = temp_buf;
    }

}

/*****************************************************************************
 * FUNCTION
 *  mma_update_address_list
 * DESCRIPTION
 *  Update address list
 * PARAMETERS
 *  header      [IN/OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_update_address_list(MSF_UINT8 mod_id, MmsGetHeader *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern void freeMmsAddressList(MSF_UINT8 modId, MmsAddressList * addressList);
    MmsAddressList *list = NULL, *prev = NULL;

    if (header == NULL)
    {
        return;
    }

    /* From */
    mma_trim_utf8_string(header->from.address);
    if (header->from.address != NULL && *header->from.address == '\0')
    {
        MSF_MEM_FREE(mod_id, header->from.address);
        header->from.address = NULL;
    }

    /* To */
    list = header->to;
    prev = NULL;
    while (list)
    {
        mma_trim_utf8_string(list->current.address);

        /* Remove empty address */
        if (list->current.address != NULL && *list->current.address == '\0')
        {
            if (prev == NULL)
            {
                header->to = list->next;
                list->next = NULL;
                freeMmsAddressList(mod_id, list);
                list = header->to;
            }
            else
            {
                prev->next = list->next;
                list->next = NULL;
                freeMmsAddressList(mod_id, list);
                list = prev->next;
            }
        }
        else
        {
            prev = list;
            list = list->next;
        }
    }

    /* Cc */
    list = header->cc;
    prev = NULL;
    while (list)
    {
        mma_trim_utf8_string(list->current.address);

        /* Remove empty address */
        if (list->current.address != NULL && *list->current.address == '\0')
        {
            if (prev == NULL)
            {
                header->cc = list->next;
                list->next = NULL;
                freeMmsAddressList(mod_id, list);
                list = header->to;
            }
            else
            {
                prev->next = list->next;
                list->next = NULL;
                freeMmsAddressList(mod_id, list);
                list = prev->next;
            }
        }
        else
        {
            prev = list;
            list = list->next;
        }
    }

    /* Bcc */
    list = header->bcc;
    prev = NULL;
    while (list)
    {
        mma_trim_utf8_string(list->current.address);

        /* Remove empty address */
        if (list->current.address != NULL && *list->current.address == '\0')
        {
            if (prev == NULL)
            {
                header->bcc = list->next;
                list->next = NULL;
                freeMmsAddressList(mod_id, list);
                list = header->to;
            }
            else
            {
                prev->next = list->next;
                list->next = NULL;
                freeMmsAddressList(mod_id, list);
                list = prev->next;
            }
        }
        else
        {
            prev = list;
            list = list->next;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mma_update_unref_list
 * DESCRIPTION
 *  Sync unref list and slide info (sometimes slide object cannot be displayed and become attachment)
 * PARAMETERS
 *  body        [IN/OUT]        
 * RETURNS
 *  void
 *****************************************************************************/
/*
void mma_update_unref_list(MSF_UINT8 mod_id, mma_mms_description_body_struct *body, mma_app_mode_enum mode, kal_uint8 *ref_attach_count, kal_uint8 *content_truncate_info)
{

    mma_mms_object_struct *obj = NULL;


    obj = body->objects;

    while (obj)
    {
        mma_mms_slide_struct *slide = body->slides;
        kal_bool is_attachment = KAL_TRUE;

        while (slide && is_attachment)
        {
          //  mma_mms_slide_object_struct *slide_obj = slide->slide_objs;
			mma_mms_slide_ref_object_struct *temp_top_ref = slide->ref_items;


                if (slide->img.object == obj)
            {
                    is_attachment = KAL_FALSE;
                    break;
                }

				if (slide->txt.object == obj)
                {
                    is_attachment = KAL_FALSE;
                    break;
                }
               
				if (slide->aud.object == obj)
                {
                    is_attachment = KAL_FALSE;
                    break;
            }

				if (slide->vid.object == obj)
                {
                    is_attachment = KAL_FALSE;
                    break;
            }
            
			while(temp_top_ref)
			{
				if(temp_top_ref->object == obj)
				{
					is_attachment = KAL_FALSE;
					break;				
				}
				temp_top_ref = temp_top_ref->next;
			}
            slide = slide->next;
        }

        if (is_attachment == KAL_TRUE && obj->is_attachment == KAL_FALSE)
        {
            obj->is_attachment = KAL_TRUE;
			if(mode == MMA_MODE_EDIT)
			{
				if((*ref_attach_count) >= wap_custom_get_max_mms_attachment())
				{
                  *content_truncate_info |= MMA_TRUNCATED_ATTACHMENT;
				  obj = obj->next;
                  continue;				
				}
				else
				{
				  (*ref_attach_count)++;
				}
			}

            mma_insert_unref_item_to_tail(mod_id, body, obj);
        }
        else if (is_attachment == KAL_FALSE && obj->is_attachment == KAL_TRUE)
        {
            ASSERT(0);
        }

        obj = obj->next;
    }
}

*/


/*****************************************************************************
 * FUNCTION
 *  mma_free_sls_media_object
 * DESCRIPTION
 *  Dealloctes the SlsMediaObject structure
 * PARAMETERS
 *  object      [IN]        
 *  obj(?)      [IN]        The media object to free
 * RETURNS
 *  void
 *****************************************************************************/
void mma_free_sls_media_object(SlsMediaObject **object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SlsParameterList *temp_param_list = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (object == NULL || *object == NULL)
    {
        return;
    }

    temp_param_list = (*object)->slsparamList;
    MMA_FREE((*object)->region);
    MMA_FREE((*object)->src);
    while (temp_param_list)
    {
        SlsParameterList *temp = temp_param_list->next;

        MMA_FREE(temp_param_list) temp_param_list = temp;
    }
    MMA_FREE(*object);
    *object = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_free_sls_media_object_list
 * DESCRIPTION
 *  Dealloctes the SlsMediaObject structure
 * PARAMETERS
 *  obj        [IN] The media object to free
 * RETURNS
 *****************************************************************************/
void mma_free_sls_media_object_list(SlsMediaObject **list)
{
    SlsMediaObject *mo = NULL;
    if (list == NULL || *list == NULL)
    {
        return;
    }

    mo = *list;
    while (mo)
    {
        SlsMediaObject *tmp = mo->next;
        MMA_FREE(mo->src);
        MMA_FREE(mo);
        mo = tmp;
    }
    *list = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  mma_mms_free_slide_list
 * DESCRIPTION
 *  Dealloctes the slide structure
 * PARAMETERS
 *  slides          [IN]        
 *  slide(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_mms_free_slide_list(MSF_UINT8 mod_id, mma_mms_slide_struct **slides)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *slide = NULL, *s_ptr = NULL;
	mma_mms_slide_ref_object_struct *list =NULL, *o_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slides != NULL && *slides != NULL)
    {
        slide = *slides;
        while (slide != NULL)   /* free slide */
        {
         //   mma_slide_object_struct *o_ptr = NULL, *list = slide->slide_objs;

           if(slide->img.object)
            {
			   slide->img.object = NULL;
			   MSF_MEM_FREE(mod_id, slide->img.alt);
			   slide->img.alt = NULL;
               MSF_MEM_FREE(mod_id, slide->img.region_area);
			   slide->img.region_area = NULL;
			   
		   }

		   if(slide->txt.object)
		   {
			   slide->img.object = NULL;
			   MSF_MEM_FREE(mod_id, slide->txt.alt);
			   slide->txt.alt = NULL;
               MSF_MEM_FREE(mod_id, slide->txt.region_area);
			   slide->txt.region_area = NULL;
			  
		   }

		   if(slide->aud.object)
            {
			   slide->aud.object = NULL;
			   MSF_MEM_FREE(mod_id, slide->aud.alt);
			   slide->txt.alt = NULL;
               MSF_MEM_FREE(mod_id, slide->aud.region_area);
			   slide->aud.region_area = NULL;
			   
            }

		   if(slide->vid.object)
		   {
			   slide->vid.object = NULL;
			   MSF_MEM_FREE(mod_id, slide->vid.alt);
			   slide->vid.alt = NULL;
               MSF_MEM_FREE(mod_id, slide->vid.region_area);
			   slide->vid.region_area = NULL;
			   
            }


			/* free slide ref item list */
			list = slide->ref_items;
			while (list)    
            {
               o_ptr = list;
               list = list->next;
               o_ptr->object = NULL;   
               MSF_MEM_FREE(mod_id, o_ptr->alt);
			   o_ptr->alt = NULL;
               MSF_MEM_FREE(mod_id, o_ptr->region_area);
			    o_ptr->region_area = NULL;
			  
            }

            s_ptr = slide;
            slide = slide->next;
            MSF_MEM_FREE(mod_id, s_ptr);
        }
        *slides = NULL;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mma_free_body_params
 * DESCRIPTION
 *  Dealloctes a #MmsBodyParams data structure
 * PARAMETERS
 *  bodyParams      [IN]        The body param to release. The pointer is set to NULL
 * RETURNS
 *  void
 *****************************************************************************/
void mma_free_body_params(MmsBodyParams **bodyParams)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MmsAllParams *param;
    MmsAllParams *tmpParam;
    MmsEntryHeader *entry;
    MmsEntryHeader *tmpEntry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != *bodyParams)
    {
        /* Free params */
        param = (*bodyParams)->contentType.params;
        MMA_FREE((*bodyParams)->contentType.strValue);
        while (NULL != param)
        {
            if (MMS_PARAM_STRING == param->type)
            {
                MMA_FREE(param->value.string);
            }
            tmpParam = param;
            param = param->next;
            MMA_FREE(tmpParam);
        }
        /* Free entries */
        entry = (*bodyParams)->entryHeader;
        while (NULL != entry)
        {
            /* Free content ID or content location string */
            if ((MMS_WELL_KNOWN_CONTENT_ID == entry->headerType) ||
                (MMS_WELL_KNOWN_CONTENT_LOCATION == entry->headerType))
            {
                MMA_FREE(entry->value.wellKnownFieldName);
            }
            tmpEntry = entry;
            entry = entry->next;
            MMA_FREE(tmpEntry);
        }
        MMA_FREE(*bodyParams);
        *bodyParams = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_get_mms_version_from_em
 * DESCRIPTION
 *  This function is used to get the mms version from engineer-mode and converts that to 
 *  MMS version definition
 * PARAMETERS
 *  version     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MmsVersion mma_get_mms_version_from_em(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (applib_inet_get_active_mms_version())
    {
        case APPLIB_INET_MMS_VERSION_10:
            return MMS_VERSION_10;
        case APPLIB_INET_MMS_VERSION_11:
            return MMS_VERSION_11;
        case APPLIB_INET_MMS_VERSION_12:
            return MMS_VERSION_12;
        default:
            return MMS_VERSION_11;
    }
}




/*****************************************************************************
 * FUNCTION
 *  mma_get_mms_slide_count
 * DESCRIPTION
 *  Get the number of slides which would be listed in xml
 * PARAMETERS
 *  body        [IN]        
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
kal_uint32 mma_get_mms_slide_count(mma_mms_description_body_struct *body)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 count = 0;
    mma_mms_slide_struct *slides = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(body != NULL);
    slides = body->slides;
    while (slides)
    {
        if (slides->slide_num > 0)
        {
            count++;
        }

        slides = slides->next;
    }
    return count;
}

/*****************************************************************************
 * FUNCTION
 *  mma_mms_free_unref_list
 * DESCRIPTION
 *  Get the number of slides which would be listed in xml
 * PARAMETERS
 *  body        [IN]        
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
void mma_mms_free_unref_list(MSF_UINT8 mod_id, mma_mms_attachment_info_struct **list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_attachment_info_struct *current;
    mma_mms_attachment_info_struct *tmp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((NULL != list) && (NULL != *list))
    {
        current = *list;
        while (NULL != current)
        {
            current->object = NULL;
            /* Next item */
            tmp = current;
            current = current->next;
            MSF_MEM_FREE(mod_id, tmp);
        }
        *list = NULL;
    }
}




/*****************************************************************************
 * FUNCTION
 *  mma_mms_free_object_list
 * DESCRIPTION
 *  Dealloctes the object list structure
 * PARAMETERS
 *  obj             [IN]        
 *  slide(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_mms_free_object_list(MSF_UINT8 mod_id, mma_mms_object_struct **obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_object_struct *curr = NULL, *tmp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (obj != NULL && *obj != NULL)
    {
        curr = *obj;
        while (curr != NULL)
        {
            tmp = curr->next;
            mma_mms_free_object(mod_id, &curr);
            /* Next item */
            curr = tmp;
        }
        curr = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mma_mms_free_object
 * DESCRIPTION
 *  Dealloctes the object structure
 * PARAMETERS
 *  obj     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_mms_free_object(MSF_UINT8 mod_id, mma_mms_object_struct **obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (obj != NULL && *obj != NULL)
    {
        MSF_MEM_FREE(mod_id, (*obj)->file_name);
        MSF_MEM_FREE(mod_id, (*obj)->file_path);
        MSF_MEM_FREE(mod_id, (*obj)->file_path_ucs);
        MSF_MEM_FREE(mod_id, (*obj)->file_name_ucs);
        MSF_MEM_FREE(mod_id, (*obj)->mime_str);
        MSF_MEM_FREE(mod_id, (*obj)->content_id);
        MSF_MEM_FREE(mod_id, (*obj)->content_location);
        MSF_MEM_FREE(mod_id, (*obj)->content_type);
    #ifdef __DRM_SUPPORT__
        MSF_MEM_FREE(mod_id, (*obj)->drm_mime_type);
        MSF_MEM_FREE(mod_id, (*obj)->cid);
    #endif 
        MSF_MEM_FREE(mod_id, *obj);
        *obj = NULL;
    }
}
/*****************************************************************************
 * FUNCTION
 * mma_free_mms_encoded_text
 * DESCRIPTION
 * deallocates the address struct
 * PARAMETERS
 *  obj             [IN]        
 *  slide(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/

void mma_free_mms_encoded_text( MSF_UINT8 mod_id, mma_mms_encoded_text_struct *encodedText)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (encodedText != NULL && encodedText->text != NULL) 
    {
        MSF_MEM_FREE( mod_id, encodedText->text);
        encodedText->text = NULL;
    }  
} 

/*****************************************************************************
 * FUNCTION
 * mma_free_mms_address
 * DESCRIPTION
 * Dealloctes the mms_description address
 * PARAMETERS
 *  obj             [IN]        
 *  slide(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_free_mms_address( MSF_UINT8 mod_id, mma_mms_address_struct *address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (address != NULL && address->address != NULL)
    {
        mma_free_mms_encoded_text( mod_id, &address->name);
        MSF_MEM_FREE( mod_id, address->address);
        address->address = NULL;
    } 
} 

/*****************************************************************************
 * FUNCTION
 * mma_free_mms_address_list
 * DESCRIPTION
 * Dealloctes the mms_description address list
 * PARAMETERS
 *  obj             [IN]        
 *  slide(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_free_mms_address_list( MSF_UINT8 mod_id, mma_mms_addr_list_struct *addressList)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mma_mms_addr_list_struct *listPointer = NULL;
    mma_mms_addr_list_struct *aList = NULL;

    MSF_MEM_FREE( mod_id, addressList->address);

    
    aList = addressList->next;
    while (aList != NULL)
    {
        listPointer = aList->next;
     //   mma_free_mms_address(mod_id, &aList->current);
        MSF_MEM_FREE( mod_id, aList->address);
        MSF_MEM_FREE( mod_id, aList);
        aList = listPointer;
    } 

    memset( addressList, 0x00, sizeof(mma_mms_addr_list_struct));

} 


/*****************************************************************************
 * FUNCTION
 * mma_free_app_mms_header
 * DESCRIPTION
 * Dealloctes the mms_description header
 * PARAMETERS
 *  obj             [IN]        
 *  slide(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_free_app_mms_header(kal_uint8 mod_id, mma_mms_header_struct *header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ( !header)
    {
        return;
    } 
    if(header->from)
	{
		mma_free_mms_address_list( mod_id, header->from);
		MSF_MEM_FREE( mod_id, header->from);
		header->from = NULL;
	}
    if ( header->to)
    {
        mma_free_mms_address_list( mod_id, header->to);
        MSF_MEM_FREE( mod_id, header->to);
		header->to = NULL;
    } 
    if ( header->cc)
    {
        mma_free_mms_address_list( mod_id, header->cc);
        MSF_MEM_FREE( mod_id, header->cc);
		header->cc = NULL;
    } 
    if ( header->bcc)
    {
        mma_free_mms_address_list( mod_id, header->bcc);
        MSF_MEM_FREE( mod_id, header->bcc);
		header->bcc = NULL;
    } 
    mma_free_mms_encoded_text( mod_id, &(header->subject));
    if(header->msg_class.text_string)
	{
		MSF_MEM_FREE(mod_id, header->msg_class.text_string);
		header->msg_class.text_string = NULL;
	}
	if(header->presentation)
	{
		MSF_MEM_FREE(mod_id, header->presentation);
		header->presentation = NULL;
	}
	if(header->app_id)
	{
		MSF_MEM_FREE(mod_id, header->app_id);
		header->app_id = NULL;
	}
	if(header->reply_app_id)
	{
		MSF_MEM_FREE(mod_id, header->reply_app_id);
		header->reply_app_id = NULL;
	}
	if(header->content_location)
	{
		MSF_MEM_FREE(mod_id, header->content_location);
		header->content_location = NULL;

	}


}

/*****************************************************************************
 * FUNCTION
 * mma_mms_free_mms_descriptor 
 * DESCRIPTION
 * Dealloctes the mms_description structure
 * PARAMETERS
 *  obj             [IN]        
 *  slide(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mma_mms_free_mms_descriptor(kal_uint8 mod_id, mma_mms_description_struct *mms_dsr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mms_dsr)
	{
			if(mms_dsr->header)
				{
	              if (mms_dsr->header->header != NULL)
		            {						
			           (void)mma_free_app_mms_header(mod_id, mms_dsr->header->header);
	   				   MSF_MEM_FREE(mod_id, mms_dsr->header->header);
					   mms_dsr->header->header = NULL;
					}
					
					 MSF_MEM_FREE(mod_id, mms_dsr->header);
					 mms_dsr->header = NULL;
					
				}
           
                if (mms_dsr->body != NULL)
                {
                    if (mms_dsr->body->attachment != NULL)
                    {
                        mma_mms_free_unref_list(mod_id, &mms_dsr->body->attachment);
                    }
                    if (mms_dsr->body->slides != NULL)
                    {
                        mma_mms_free_slide_list(mod_id, &mms_dsr->body->slides);
                    }
                    if (mms_dsr->body->objects != NULL)
                    {
                        mma_mms_free_object_list(mod_id, &mms_dsr->body->objects);
                    }
                    
                    MSF_MEM_FREE(mod_id, mms_dsr->body);
					mms_dsr->body = NULL;
                }
		MMA_FREE(mms_dsr);

	}


}

/*****************************************************************************
 * FUNCTION
 *  mma_replace_file_ext_with_input
 * DESCRIPTION
 * Replace the DRM extention with media actual extention 
 *  MMS version definition
 * PARAMETERS
 *  version     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
char *mma_replace_file_ext_with_input(MSF_UINT8 mod_Id, char *filename, const char *mime_string)
{
        
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 char *ext = NULL ,*new_name = NULL, *mime_str_temp = NULL;
	 applib_mime_type_struct *entry = NULL;
	 kal_uint8 temp_len = 0; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename != NULL && mime_string != NULL)
    {    
        ext = strrchr(filename, '.');
        if (ext != NULL)
        {
          ext++;
		  if(strcmp(ext, "dcf") == 0 || strcmp(ext, "dm") == 0)
		 { 			
 			mime_str_temp = msf_cmmn_strdup(mod_Id, mime_string);
            entry = applib_mime_type_look_up(mime_str_temp, NULL, MIME_TYPE_TEXT, MIME_SUBTYPE_NONE);				
            if (entry == NULL)
            {
				MSF_MEM_FREE(mod_Id, mime_str_temp);
				mime_str_temp = NULL;
                return NULL;
            }
			temp_len = strlen(entry->file_ext);
			if(strlen(ext)  >  temp_len)
			{
				memcpy(ext,  entry->file_ext, temp_len);
				ext[temp_len] = '\0';			
				ext = NULL;
				entry = NULL;
				MSF_MEM_FREE(mod_Id, mime_str_temp);
				mime_str_temp = NULL;
				return filename;
			}
			else
			{
				new_name = MSF_MEM_ALLOC(mod_Id, (strlen(filename) - strlen(ext) + temp_len  + 1));
				memset(new_name, 0 ,(strlen(filename) - strlen(ext) + temp_len  + 1));
				memcpy(new_name,  filename, strlen(filename));
				ext = strrchr(new_name, '.');
				ext++;
				//temp_len = 0;
				memcpy(ext, entry->file_ext, temp_len);
				ext[temp_len] = '\0';
				/*free memory of old name of file */
				MSF_MEM_FREE(mod_Id, filename);
				filename = NULL;
				MSF_MEM_FREE(mod_Id, mime_str_temp);
				mime_str_temp = NULL;
				ext = NULL;
				entry = NULL;
				return new_name;
			}
		  }
		  else
		  {
			  ext = NULL;
		  	return filename;					  
		  }
        }
    }
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mma_copy_create_address_info
 * DESCRIPTION
 * Copy the app address list to mms address list  
 *  MMS version definition
 * PARAMETERS
 *  version     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mma_copy_create_address_info(mma_mms_addr_list_struct *addr_list, MmsSetHeader *dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
			MmsAddressList **list = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	while(addr_list)
	{
		if (addr_list->addr_type == MMA_ADDR_TYPE_PHONE_NUMBER || addr_list->addr_type == MMA_ADDR_TYPE_EMAIL)
		{

			switch (addr_list->group)
			{
				case MMA_ADDRESS_GROUP_TYPE_TO:
					list = &dest->to;
					break;

				case MMA_ADDRESS_GROUP_TYPE_CC:
					list = &dest->cc;
					break;

				case MMA_ADDRESS_GROUP_TYPE_BCC:
					list = &dest->bcc;
					break;

				case MMA_ADDRESS_GROUP_TYPE_FROM:
					/* do not set manually 
					prs_info->info->header->header.s_header->from; */
					return;

				default:
					ASSERT(0);
					break;
			}

			mma_insert_addr_to_list(list, translate_mma_address_type_to_mms((mma_addr_type_enum)addr_list->addr_type), NULL, (char*)addr_list->address);
		}
		else
		{
			ASSERT(0);
		}

	addr_list = addr_list->next;
	}


}


/*****************************************************************************
 * FUNCTION
 *  mma_copy_parse_address_info
 * DESCRIPTION
 * mms parsed address to application header list 
 *  MMS version definition
 * PARAMETERS
 *  version     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mma_copy_parse_address_info(kal_uint8 mod_id, MmsAddressList *addr_list, mma_address_group_type_enum group, mma_mms_header_struct *dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
			mma_mms_addr_list_struct **list = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


		if (addr_list->current.addrType == MMS_PLMN || addr_list->current.addrType == MMS_EMAIL || addr_list->current.addrType == MMS_IPV4)
		{
			list = &dest->to;
/*			
			switch (group)
			{
				case MMA_ADDRESS_GROUP_TYPE_TO:
					list = &dest->to;
					break;

				case MMA_ADDRESS_GROUP_TYPE_CC:
					list = &dest->to;
					break;

				case MMA_ADDRESS_GROUP_TYPE_BCC:
					list = &dest->to;
					break;

				case MMA_ADDRESS_GROUP_TYPE_FROM:
					
					return;

				default:
					ASSERT(0);
					break;*/
			

			mma_append_addr_to_list(mod_id, list, translate_mms_address_type_to_mma(addr_list->current.addrType), NULL, (char*)addr_list->current.address, group);
		}
		else
		{
			ASSERT(0);
		}

}

/*****************************************************************************
 * FUNCTION
 *  mma_copy_app_to_mms_header
 * DESCRIPTION
 * Copy the information from Appliaction to mms_header   
 *  MMS version definition
 * PARAMETERS
 *  version     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_result_enum mma_copy_app_to_mms_header(mma_mms_header_struct *source, mma_header_struct *header)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MmsSetHeader *dest = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	dest = header->header.s_header; 
	if(!source || !dest)
	{
		return MMA_RESULT_FAIL;
	}

	if(source->to)
			{
			    mma_copy_create_address_info(source->to,  dest);
			}				
	if(source->cc)
			{
			    mma_copy_create_address_info(source->cc,  dest);
			}				
	if(source->bcc)
			{
			    mma_copy_create_address_info(source->bcc,  dest);
			}
	if(source->from)
			{
				 dest->fromType = MMS_FROM_ADDRESS_PRESENT;
				 dest->from.addrType = MMS_PLMN;
	  		    /* if (addr_type == MMS_EMAIL && name != NULL)
					 {
				          dest->from.name.charset = mma_is_ascii_string(name) ? MMS_US_ASCII : MMS_UTF8;
						  item->current.name.size = strlen(name); 
					      dest->from.name.text = msf_cmmn_strdup(MSF_MODID_MMA, name);
				     }*/
				 dest->from.address = msf_cmmn_strdup(MSF_MODID_MMA, source->from->address); 
			}
	
	dest->expiryTimeType = trnslate_mma_type_to_mms((mma_mms_time_type_enum)source->expiry_time_type);
	translate_mma_expiry_to_mms(
            (mma_expiry_time_enum)source->expiry_time,
            dest->date,
            &dest->expiryTimeType,
            &dest->expiryTime);


	dest->deliveryTimeType = trnslate_mma_type_to_mms((mma_mms_time_type_enum)source->delivery_time_type);
	translate_mma_delivery_to_mms(
            (mma_delivery_time_enum)source->delivery_time,
            dest->date,
            &dest->deliveryTimeType,
            &dest->deliveryTime);

	if(source->subject.text)
	{
	   int len = strlen(source->subject.text);
	   dest->subject.charset = MMS_UTF8;
      /*  if (len > 0)
        {
            int size = msf_cmmn_base64_decode_len(source->subject.text, len) + 1;

            dest->subject.text = (char*)MMA_CALLOC(size);
            msf_cmmn_base64_decode(source->subject.text, len, dest->subject.text, &size);
        }
        else
        {
            dest->subject.text = NULL;
        }*/
	   dest->subject.text = msf_cmmn_strdup(MSF_MODID_MMA, source->subject.text);

	}

	if(source->read_reply == MMA_MMS_READ_REPLY_YES)
	{
		dest->readReply = MMS_READ_REPLY_YES;
	}
	else
	{
		dest->readReply = MMS_READ_REPLY_NO;
	}

	if(source->delivery_report == MMA_MMS_DELIVERY_REPORT_YES)
	{
		dest->deliveryReport = MMS_DELIVERY_REPORT_YES;
	}
	else
	{
		dest->deliveryReport = MMS_DELIVERY_REPORT_NO;
	}
	
    dest->priority = translate_mma_priority_to_mms((mma_priority_enum)source->priority);

    if (source->visibility == MMA_MMS_SENDER_HIDE)
        {
            dest->visibility = MMS_SENDER_HIDE;
        }
		
	/* header->s_version = translate_mma_version_to_mms(source->version);	would also be set already */
		
    dest->msgClass.classIdentifier = 
                                translate_mma_class_to_mms((mma_msg_class_enum)source->msg_class.class_identifier);

	/*appid reply app id presentation */

	  if (source->presentation)
      {
        mma_add_param_string(&dest->contentType->params, MMS_START_REL, NULL, source->presentation);
        mma_add_param_string(
            &dest->contentType->params,
            MMS_TYPE_REL,
            NULL,
            MMS_MEDIA_TYPE_STRING_SMIL);
      }

	if (source->app_id)
    {
        mma_add_param_string(
            &dest->contentType->params,
            MMS_TEXT_KEY,
            MMA_HEADER_APPLICATION_ID_STR,
            source->app_id);
    }

	if (source->reply_app_id)
    {
       mma_add_param_string(
            &dest->contentType->params,
            MMS_TEXT_KEY,
            MMA_HEADER_REPLY_APPLICATION_ID_STR,
           source->reply_app_id);
	}
	return MMA_RESULT_OK;

}
/*****************************************************************************
 * FUNCTION
 *  mma_copy_mms_to_app_header
 * DESCRIPTION
 * Copy the information from Appliaction to mms_header   
 *  MMS version definition
 * PARAMETERS
 *  version     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
mma_result_enum mma_copy_mms_to_app_header(kal_uint8 mod_id, mma_header_struct *src_header, mma_mms_header_struct *dest, mma_app_mode_enum mode, MmsFileType suffix, mma_msg_type_enum msg_type,  kal_uint32 msg_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 //char *utf8_str = NULL;
	 //int size = 0;
	 int i = 0;
	 kal_bool all;
	 MmsAddressList *list;
	 MmsGetHeader *header = NULL;
	 MmsNotification *notif = NULL;
	 //MmaReport *report = NULL;
	 int max = wap_custom_get_max_mms_address();
	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 if(!src_header || !src_header->header.g_header || !dest)
	 {
		return MMA_RESULT_FAIL;
	 }
	  all = (kal_bool)(mode == MMA_MODE_HEADER || mode == MMA_MODE_VIEW || mode == MMA_MODE_RAW);

	switch(suffix)
    {
        case MMS_SUFFIX_SEND_REQ:
        case MMS_SUFFIX_MSG:
        case MMS_SUFFIX_TEMPLATE:
			header = src_header->header.g_header;
			if(msg_type != MMA_MSG_TYPE_POSTCARD && mma_get_box(msg_id) != MMA_FOLDER_USRDEF_TEMPLATE)
			   {
				list = header->to;
				while ((all || i < max) && list != NULL)
				  {
					 mma_copy_parse_address_info(mod_id, list, MMA_ADDRESS_GROUP_TYPE_TO, dest);
					 i++;
					 list = list->next;
				  }


				list = header->cc;
				while ((all || i < max) && list != NULL)
				  {
					 mma_copy_parse_address_info(mod_id, list, MMA_ADDRESS_GROUP_TYPE_CC, dest);
					 i++;
					 list = list->next;
				  }

				list = header->bcc;
				while ((all || i < max) && list != NULL)
				  {
					 mma_copy_parse_address_info(mod_id, list, MMA_ADDRESS_GROUP_TYPE_BCC, dest);
					 i++;
					 list = list->next;
				  }
				}

			    if (header->from.address != NULL)
					{
						dest->from = (mma_mms_addr_list_struct*) MSF_MEM_ALLOC(mod_id, sizeof(mma_mms_addr_list_struct));
						dest->from->address = (char*)msf_cmmn_strdup(mod_id, (char*)header->from.address);
						dest->from->addr_type = translate_mms_address_type_to_mma(header->from.addrType);
						dest->from->group = MMA_ADDRESS_GROUP_TYPE_FROM;
						dest->from->next = NULL;
					}	

				if (header->msgClass.classIdentifier != MMS_MESSAGE_CLASS_NOT_SET ||
										header->msgClass.classIdentifier != MMS_MESSAGE_CLASS_IS_TEXT)
					{
						dest->msg_class.class_identifier = translate_mms_class_to_mma( header->msgClass.classIdentifier);
					}
				if (header->priority != MMS_PRIORITY_NOT_SET)
					{
						dest->priority = translate_mms_priority_to_mma(header->priority);
					}
				if (header->readReply != MMS_READ_REPLY_NOT_SET)
					{
						dest->read_reply = header->readReply;
					}
				if (header->deliveryReport  != MMS_DELIVERY_REPORT_NOT_SET)
					{
						dest->delivery_report  = header->deliveryReport ;
					}
			    if (header->deliveryTime != 0)
					{
						dest->delivery_time_type = (header->deliveryTimeType == MMS_TIME_ABSOLUTE) ?  MMA_MMS_TIME_ABSOLUTE: ((header->deliveryTimeType == MMS_TIME_RELATIVE) ? MMA_MMS_TIME_RELATIVE : 0);
						dest->delivery_time = translate_mms_delivery_to_mma(header->deliveryTimeType, header->deliveryTime, header->date);
					}
			    if (header->expiryTime != 0)
					{
						dest->expiry_time_type = (header->expiryTimeType == MMS_TIME_ABSOLUTE) ?  MMA_MMS_TIME_ABSOLUTE: ((header->expiryTimeType == MMS_TIME_RELATIVE) ? MMA_MMS_TIME_RELATIVE : 0);
						dest->expiry_time = translate_mms_expiry_to_mma(header->expiryTimeType, header->expiryTime, header->date);
					}

				if (header->visibility != MMS_SENDER_VISIBILITY_NOT_SET)
				 {
					if(header->visibility == MMS_SENDER_HIDE)
					{
						dest->visibility = MMA_MMS_SENDER_HIDE;
					}
					else
					{
						dest->visibility = MMA_MMS_SENDER_SHOW;
					}
				 }
				/*MSg date and version*/
				dest->date = header->date;
				dest->version = header->version;

	     	   if (header->subject.text)
				{
				/*
					utf8_str = mma_ucs2_to_utf8_string((const kal_wchar *)header->subject.text);
					size = msf_cmmn_base64_encode_len(strlen(utf8_str)) + 1;
					dest->subject.text = (char*)MMA_CALLOC(size);
					msf_cmmn_base64_encode(utf8_str, strlen(utf8_str), dest->subject.text , &size);				
					MMA_FREE(utf8_str);*/
					dest->subject.text = msf_cmmn_strdup(mod_id, header->subject.text);
					dest->subject.charset = MMA_CHARSET_UTF8;

				}

			   if (header->bodyInfoList.contentType && header->bodyInfoList.contentType->params)
				{
					dest->presentation = msf_cmmn_strdup(mod_id, 
																(char*)mma_get_presentation_from_params(
																			header->bodyInfoList.contentType->params)); 

					dest->app_id = msf_cmmn_strdup(mod_id, 
																(char*)mma_get_app_id_from_params(
																			header->bodyInfoList.contentType->params)); 

					dest->reply_app_id = msf_cmmn_strdup(mod_id, 
																(char*)mma_get_reply_app_id_from_params(
																			header->bodyInfoList.contentType->params)); 
				}






			
			
			
					



		break;
		case MMS_SUFFIX_IMMEDIATE:
        case MMS_SUFFIX_NOTIFICATION:
			//(void)mma_copy_mms_header_notif(msg, info->header->header.notif);	/*not needed so far*/
			notif = src_header->header.notif;
			if (notif->from.address != NULL)
			{
					dest->from = (mma_mms_addr_list_struct*) MSF_MEM_ALLOC(mod_id, sizeof(mma_mms_addr_list_struct));
					dest->from->address = (char*)msf_cmmn_strdup(mod_id, (char*)notif->from.address);
					dest->from->addr_type = translate_mms_address_type_to_mma(notif->from.addrType);
					dest->from->group = MMA_ADDRESS_GROUP_TYPE_FROM;
					dest->from->next = NULL;
			}	
	     	if (notif->subject.text)
			{
				/*
					utf8_str = mma_ucs2_to_utf8_string((const kal_wchar *)header->subject.text);
					size = msf_cmmn_base64_encode_len(strlen(utf8_str)) + 1;
					dest->subject.text = (char*)MMA_CALLOC(size);
					msf_cmmn_base64_encode(utf8_str, strlen(utf8_str), dest->subject.text , &size);				
					MMA_FREE(utf8_str);*/
				dest->subject.text = msf_cmmn_strdup(mod_id, notif->subject.text);
				dest->subject.charset = MMA_CHARSET_UTF8;
			}
			if (notif->deliveryReport  != MMS_DELIVERY_REPORT_NOT_SET)
			{
				dest->delivery_report  = notif->deliveryReport;
			}
			if (notif->priority != MMS_PRIORITY_NOT_SET)
			{
				dest->priority = translate_mms_priority_to_mma(notif->priority);
			}
			if (notif->expiryTime != 0)
			{
				//dest->expiry_time_type = (notif->expiryTimeType == MMS_TIME_ABSOLUTE) ?  MMA_MMS_TIME_ABSOLUTE: ((notif->expiryTimeType == MMS_TIME_RELATIVE) ? MMA_MMS_TIME_RELATIVE : 0);
				dest->expiry_time = /*translate_mms_expiry_to_mma(notif->expiryTimeType, notif->expiryTime, notif->date)*/notif->expiryTime;
			}
			if (notif->msgClass.classIdentifier != MMS_MESSAGE_CLASS_NOT_SET ||
					notif->msgClass.classIdentifier != MMS_MESSAGE_CLASS_IS_TEXT)
			{
				dest->msg_class.class_identifier = translate_mms_class_to_mma(notif->msgClass.classIdentifier);
			}
			/*dl_size*/
			dest->download_size = notif->length;
			
			/* download URL content location */
			dest->content_location = (char*)msf_cmmn_strdup(mod_id, (char*)notif->contentLocation);
		break;
		case MMS_SUFFIX_DELIVERYREPORT:
        case MMS_SUFFIX_READREPORT:
		default:
		ASSERT(0);//	(void)mma_copy_mms_header_report(msg, info->header->header.report);	/*not needed so far*/
	    break;		
	 }
	 return MMA_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mma_str_trnslt_utf8_to_ucs2le
 * DESCRIPTION
 *  Get UCS2 string from UTF8 string, caller should release the returned UCS2 string
 * PARAMETERS
 *  ucs2_str        [IN]        
 * RETURNS
 *  UTF8 string
 *****************************************************************************/
kal_wchar* mma_str_trnslt_utf8_to_ucs2(kal_uint8 mod_id, const char *src_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *dest_buffer = NULL;
    long dest_len = 0, src_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    src_len = strlen(src_str);
    src_len++;

    dest_len = src_len * ENCODING_LENGTH;

    dest_buffer = (kal_char*)MSF_MEM_ALLOC(mod_id, dest_len);
    memset(dest_buffer, 0, dest_len);
    if (dest_buffer)
    {
		msf_charset_utf8_to_ucs2le(src_str, &src_len, dest_buffer, &dest_len);
    }
    
    return (kal_wchar*)dest_buffer;
}




/*****************************************************************************
 * FUNCTION
 *  mma_update_object_list
 * DESCRIPTION
 * translate utfs file names of objects to UCS2 string   
 *  MMS version definition
 * PARAMETERS
 *  version     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mma_update_object_list(kal_uint8 mod_id, mma_mms_description_body_struct *body, kal_uint8 storage)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //long dest_len = 0, src_len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(body != NULL)
	{
	 mma_mms_object_struct *obj = body->objects;
	 while(obj)
	 {
		if(obj->file_name)
		{

			obj->file_name_ucs = mma_str_trnslt_utf8_to_ucs2(mod_id, obj->file_name);
		}
		MSF_MEM_FREE(mod_id, obj->file_name);
		obj->file_name = NULL;

		if(obj->file_path)
		{
			obj->file_path_ucs = /*mma_str_trnslt_utf8_to_ucs2(mod_id, obj->file_path);*/ (kal_wchar*)MSF_FILE_GET_EXTERNAL_FILENAME_EXT(mod_id, obj->file_path, translate_mma_storage_to_mms_storage_enum((mma_msg_storage_type_enum)storage));
		}
		MSF_MEM_FREE(mod_id, obj->file_path);
		obj->file_path = NULL;

		obj = obj->next;
	 }
	}



}


/*****************************************************************************
 * FUNCTION
 *  mma_assign_slide_index
 * DESCRIPTION
 * assign slide index  
 *  
 * PARAMETERS
 *  body     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mma_assign_slide_index(mma_mms_description_body_struct *body)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *slide = NULL;
	kal_uint32 id = 1;  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


	if (body == NULL)
    {
        return;
    }

    slide = body->slides;

    /* 1. assign slide ID */
    while (slide)
    {
        slide->slide_num = id++;
        slide = slide->next;
    }


}

/*****************************************************************************
 * FUNCTION
 *  mma_generate_slide_info
 * DESCRIPTION
 * manipulates slide information  
 *  
 * PARAMETERS
 *  body     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mma_generate_slide_info(mma_mms_slide_struct *slide, SmilMediaObject *mobj, mma_mms_object_struct *obj, mma_mms_description_body_struct *body, InstanceData *ctx)
{
		
		SlsMediaObjectType type = SLS_OBJECT_TYPE_NONE;
		kal_bool media_is_on_slide = KAL_FALSE;
		SlsParameterList *param_list = NULL;
		mma_mms_slide_ref_object_struct *temp_top_ref = NULL, *s_ref_obj = NULL;      

		 
		//mma_mms_description_body_struct *body = info->mms_dsr->body;

 
        type = translate_applib_obj_type_to_sls(mma_get_mime_group_from_mime_type(obj->mime_str));

		
		if (obj->drm_process_type != MMA_DRM_NO_PROTECTION)
        {
        #ifdef __DRM_SUPPORT__
            type = translate_applib_obj_type_to_sls(mma_get_mime_group_from_mime_type(obj->drm_mime_type));
        #endif 		
		  }
		
        
	//	ASSERT(obj->is_attachment == KAL_TRUE);
				
            if (obj != NULL && type != SLS_OBJECT_TYPE_ATTACMENT && SMIL_MEDIA_OBJECT_REF != mobj->mediaObjectElement)
            {	
				obj->is_attachment = KAL_FALSE;
              //  media_is_on_slide = TRUE;
               
               switch(type)
                {
                case SLS_OBJECT_TYPE_TEXT:
                    {
						media_is_on_slide = KAL_TRUE;
						if(slide->txt.object)
						{
							slide->txt.object->is_attachment = KAL_TRUE;
							slide->txt.object = NULL;
						}
						/*set object in slide*/
						slide->txt.object = obj;
						slide->txt.id = obj->id;
                        param_list = mobj->tmpParamList;

                        if (mobj->color == SLS_COLOR_NOT_USED)
                        {
                            slide->txt.fg_color = MMA_CFG_SMIL_FG_COLOR;
                        }
                        else
                        {
                            slide->txt.fg_color = mobj->color;
                        }
                        while (param_list)
                        {
                            if (msf_cmmn_strcmp_nc(param_list->param.name, MMA_TEXT_SIZE_NAME_STR) == 0)
                            {
                                slide->txt.text_size = mma_str_to_text_size(param_list->param.value);
                            }
                           



                            else if (msf_cmmn_strcmp_nc(param_list->param.name, MMA_TEXT_STYLE_NAME_STR) == 0)
                            {
                                slide->txt.text_style = mma_str_to_text_style(param_list->param.value);
                            }
                            param_list = param_list->next;
                        }

						slide->txt.bg_color = body->bgColor;
							/*region information*/
						slide->txt.region_area = (mma_mms_object_area_struct*) MSF_MEM_CALLOC(ctx->memId, 1, sizeof(mma_mms_object_area_struct));

						if(!mma_generate_region_from_SMILctx(mobj->region, slide->txt.region_area, ctx))
						{
							MSF_MEM_FREE(ctx->memId, slide->txt.region_area);
							slide->txt.region_area = NULL;
						}

						slide->txt.begin = mobj->begin;
						slide->txt.end = mobj->end;

						if(slide->txt.end == 0)
						{
							slide->txt.end = slide->duration;
						}

						if (slide->txt.end == 0 && slide->txt.begin != 0)
						{
								slide->txt.end = slide->duration;
						}
						if (slide->txt.begin + mobj->dur > slide->txt.end)
						{
								slide->txt.end = slide->txt.begin + mobj->dur;
						}
					
						if (slide->txt.end > slide->duration && slide->duration != 0)
						{
		        				slide->txt.end = slide->duration;
						}
						else
						{
							if(slide->txt.end > MMA_MAX_SLIDE_TIMING)
							{
							  slide->txt.end = MMA_MAX_SLIDE_TIMING;
							}
						}

						if (slide->txt.begin > slide->txt.end)
						{
							if (mobj->dur > slide->txt.end)
							{
							   slide->txt.begin = 0;
							}
							else
							{
							   slide->txt.begin = slide->txt.end - mobj->dur;
							}
						}
                    slide->txt.alt = msf_cmmn_strdup(ctx->memId, mobj->alt);
					}
					break;

                case SLS_OBJECT_TYPE_IMAGE:
					{
					 if(!slide->vid.object)
					   {
						media_is_on_slide = KAL_TRUE;
						if(slide->img.object)
						{
							slide->img.object->is_attachment = KAL_TRUE;
							slide->img.object = NULL;
						}
						/*set object in slide*/
						slide->img.object = obj;
						slide->img.id = obj->id;
						slide->img.object->is_attachment = KAL_FALSE;
						slide->img.region_area = (mma_mms_object_area_struct*) MSF_MEM_CALLOC(ctx->memId, 1, sizeof(mma_mms_object_area_struct));

						if(!mma_generate_region_from_SMILctx(mobj->region, slide->img.region_area, ctx))
						{
							MSF_MEM_FREE(ctx->memId, slide->img.region_area);
							slide->img.region_area = NULL;
						}

						slide->img.begin = mobj->begin;
						slide->img.end = mobj->end;

						if(slide->img.end == 0)
						{
							slide->img.end = slide->duration;
						}

						if (slide->img.end == 0 && slide->img.begin != 0)
						{
								slide->img.end = slide->duration;
						}
						if (slide->img.begin + mobj->dur > slide->img.end)
						{
								slide->img.end = slide->img.begin + mobj->dur;
						}
					
						if (slide->img.end > slide->duration && slide->duration != 0)
						{
		        				slide->img.end = slide->duration;
						}
						else
						{
							if(slide->img.end > MMA_MAX_SLIDE_TIMING)
							{
							  slide->img.end = MMA_MAX_SLIDE_TIMING;
							}
						}

						if (slide->img.begin > slide->img.end)
						{
							if (mobj->dur > slide->img.end)
							{
							   slide->img.begin = 0;
							}
							else
							{
							   slide->img.begin = slide->img.end - mobj->dur;
							}
						}
                    slide->img.alt = msf_cmmn_strdup(ctx->memId, mobj->alt);
					}
				   }
					break;
                case SLS_OBJECT_TYPE_VIDEO:
					{
					 if(!slide->img.object)
					   {
					    media_is_on_slide = KAL_TRUE;
						if(slide->vid.object)
						{
							slide->vid.object->is_attachment = KAL_TRUE;
							slide->vid.object = NULL;
						}
						/*set object in slide*/
						slide->vid.object = obj;
						slide->vid.id = obj->id;
						slide->vid.object->is_attachment = KAL_FALSE;
						slide->vid.region_area = (mma_mms_object_area_struct*) MSF_MEM_CALLOC(ctx->memId, 1, sizeof(mma_mms_object_area_struct));

						if(!mma_generate_region_from_SMILctx(mobj->region, slide->vid.region_area, ctx))
						{
							MSF_MEM_FREE(ctx->memId, slide->vid.region_area);
							slide->vid.region_area = NULL;
						}

						slide->vid.begin = mobj->begin;
						slide->vid.end = mobj->end;

						if(slide->vid.end == 0)
						{
							slide->vid.end = slide->duration;
						}

						if (slide->vid.end == 0 && slide->vid.begin != 0)
						{
								slide->vid.end = slide->duration;
						}
						if (slide->vid.begin + mobj->dur > slide->vid.end)
						{
								slide->vid.end = slide->vid.begin + mobj->dur;
						}
					
						if (slide->vid.end > slide->duration && slide->duration != 0)
						{
		        				slide->vid.end = slide->duration;
						}
						else
						{
							if(slide->vid.end > MMA_MAX_SLIDE_TIMING)
							{
							  slide->vid.end = MMA_MAX_SLIDE_TIMING;
							}
						}

						if (slide->vid.begin > slide->vid.end)
						{
							if (mobj->dur > slide->vid.end)
							{
							   slide->vid.begin = 0;
							}
							else
							{
							   slide->vid.begin = slide->vid.end - mobj->dur;
							}
						}
                    slide->vid.alt = msf_cmmn_strdup(ctx->memId, mobj->alt);

					}
				   }
					break;					
    /*                s_obj->bg_color = body->bgColor;
					
						s_obj->region_area = (mma_mms_object_area_struct*) MSF_MEM_CALLOC(info->ctx.memId, 1, sizeof(mma_mms_object_area_struct));
						//mma_copy_sls_region(&slsInfo->text.region, &s_obj->region);
						mma_generate_region_from_SMILctx(mobj->region, s_obj->region, info);
					if(s_obj->region->is_valid)
					{
						mma_insert_region(info->ctx.memId, &body->regions, NULL, MMA_REGION_FIT_NONE, s_obj->region, MMA_SUBMODULE_MSG_PARSE);
					}
					else
				    {
					MSF_MEM_FREE(info->ctx.memId, s_obj->region);
					s_obj->region = NULL;
					}*/
                case SLS_OBJECT_TYPE_AUDIO:                   
					{
						media_is_on_slide = KAL_TRUE;
						if(slide->vid.object)
						{
							slide->vid.object->is_attachment = KAL_TRUE;
							slide->vid.object = NULL;
						}
						/*set object in slide*/
						slide->aud.object = obj;
						slide->aud.id = obj->id;
						slide->aud.begin = mobj->begin;
						slide->aud.end = mobj->end;

						if(slide->aud.end == 0)
						{
							slide->aud.end = slide->duration;
						}

						if (slide->aud.end == 0 && slide->aud.begin != 0)
						{
								slide->aud.end = slide->duration;
						}
						if (slide->aud.begin + mobj->dur > slide->aud.end)
						{
								slide->aud.end = slide->aud.begin + mobj->dur;
						}
					
						if (slide->aud.end > slide->duration && slide->duration != 0)
						{
		        				slide->aud.end = slide->duration;
						}
						else
						{
							if(slide->aud.end > MMA_MAX_SLIDE_TIMING)
							{
							  slide->aud.end = MMA_MAX_SLIDE_TIMING;
							}
						}

						if (slide->aud.begin > slide->aud.end)
						{
							if (mobj->dur > slide->aud.end)
							{
							   slide->aud.begin = 0;
							}
							else
							{
							   slide->aud.begin = slide->aud.end - mobj->dur;
							}
						}
                    slide->aud.alt = msf_cmmn_strdup(ctx->memId, mobj->alt);					
					}	
					break;					
					default:
					ASSERT(0);
					
                }
            }
        
		if(media_is_on_slide)
			{	
				/*need not do anything as the slide object is already populated */
			}
		else
		{
		//	 ASSERT(type == SLS_OBJECT_TYPE_ATTACMENT || type == SLS_OBJECT_TYPE_IMAGE || type == SLS_OBJECT_TYPE_VIDEO);
		
           
             if(SMIL_MEDIA_OBJECT_REF == mobj->mediaObjectElement || SMIL_MEDIA_OBJECT_IMG == mobj->mediaObjectElement || SMIL_MEDIA_OBJECT_VIDEO == mobj->mediaObjectElement)
			 { 
                    s_ref_obj = (mma_mms_slide_ref_object_struct*) MSF_MEM_CALLOC(ctx->memId, 1, sizeof(mma_mms_slide_ref_object_struct));
                    s_ref_obj->object = obj;
                    s_ref_obj->id = obj->id;
					s_ref_obj->bg_color = body->bgColor;
                   obj->is_attachment = KAL_FALSE;
                   s_ref_obj->region_area = (mma_mms_object_area_struct*) MSF_MEM_CALLOC(ctx->memId, 1, sizeof(mma_mms_object_area_struct));
						if(!mma_generate_region_from_SMILctx(mobj->region, s_ref_obj->region_area, ctx))
						{
							MSF_MEM_FREE(ctx->memId, s_ref_obj->region_area);
							s_ref_obj->region_area = NULL;
						}
			/*	if(s_ref_obj->region->is_valid)
					{
                        mma_insert_region(info->ctx.memId, 
                            &body->regions,
                            NULL,
                            MMA_REGION_FIT_NONE,
                            s_ref_obj->region,
                            MMA_SUBMODULE_MSG_PARSE);
						     
					}
					else
				    {
						MSF_MEM_FREE(info->ctx.memId, s_ref_obj->region);
						s_ref_obj->region = NULL;
					}
                    s_ref_obj->type = SLS_OBJECT_TYPE_REF;
						*/
                    
                    s_ref_obj->begin = mobj->begin;
                    s_ref_obj->end = mobj->end;

					if(s_ref_obj->end == 0)
					{
						s_ref_obj->end = slide->duration;
					}

                    if (s_ref_obj->end == 0 && s_ref_obj->begin != 0)
                    {
                        s_ref_obj->end = slide->duration;
                    }
                    if (s_ref_obj->begin + mobj->dur > s_ref_obj->end)
                    {
                        s_ref_obj->end = s_ref_obj->begin + mobj->dur;
                    }
                    s_ref_obj->alt = msf_cmmn_strdup(ctx->memId, mobj->alt);
					
					if (s_ref_obj->end > slide->duration && slide->duration != 0)
					{
		        			s_ref_obj->end = slide->duration;
					}
                    else
                    {
                        if(s_ref_obj->end > MMA_MAX_SLIDE_TIMING)
                        {
                            s_ref_obj->end = MMA_MAX_SLIDE_TIMING;
                        }
                    }

                    if (s_ref_obj->begin > s_ref_obj->end)
                    {
                        if (mobj->dur > s_ref_obj->end)
                        {
                            s_ref_obj->begin = 0;
                        }
                        else
                        {
                            s_ref_obj->begin = s_ref_obj->end - mobj->dur;
                        }
                    }
                   
					
					
					if (slide->ref_items == NULL)
                    {
                        slide->ref_items = s_ref_obj;
                        temp_top_ref = slide->ref_items;
                    }
                    else 
                    {
							temp_top_ref = slide->ref_items;
							while(temp_top_ref->next)
								{
									temp_top_ref = temp_top_ref->next;
								}               
							temp_top_ref->next =  s_ref_obj;
							temp_top_ref->next->prev = temp_top_ref;
							temp_top_ref = temp_top_ref->next;
							temp_top_ref->next = NULL;
                    }
                   
		}	
	}
}

/*****************************************************************************
 * FUNCTION
 *  mma_populate_unref_item_list
 * DESCRIPTION
 * genereate the attachment list present in the message   
 *  
 * PARAMETERS
 *  body     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mma_populate_unref_item_list(MSF_UINT8 mod_id, mma_mms_description_body_struct *body, mma_mms_object_struct *attach_obj, mma_app_mode_enum mode, kal_uint8 *ref_attach_count, kal_uint8 *content_truncate_info)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//mma_mms_description_body_struct *body = info->mms_dsr->body;
    mma_mms_attachment_info_struct *dest = body->attachment;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  
    if(body->attachment == NULL) 
    {
		dest = (mma_mms_attachment_info_struct*) MSF_MEM_CALLOC(mod_id, 1, sizeof(mma_mms_attachment_info_struct));
		dest->object =attach_obj;
		dest->next = NULL;
		attach_obj->is_attachment = KAL_TRUE;
		body->attachment = dest;
		(*ref_attach_count)++;
	}
	else
	{
	  if(mode == MMA_MODE_EDIT)
		{
		 if((*ref_attach_count) >= wap_custom_get_max_mms_attachment())
			{
			 *content_truncate_info |= MMA_TRUNCATED_ATTACHMENT;
			  return;				
			}
		 else
			{
			 (*ref_attach_count)++;
			}
		}
		while(dest->next)
		{
			dest = dest->next;
		}
		dest->next = (mma_mms_attachment_info_struct*) MSF_MEM_CALLOC(mod_id, 1, sizeof(mma_mms_attachment_info_struct));
		dest->next->prev = dest;
		dest = dest->next;
		dest->object =attach_obj;
		attach_obj->is_attachment = KAL_TRUE;
		dest->next = NULL;
   }
}


/*****************************************************************************
 * FUNCTION
 *  mma_is_presentation_part
 * DESCRIPTION
 * identification of smil as the presentation part of the MMS, the header's start parameter contains the content id of smil   
 *  
 * PARAMETERS
 *  body     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MSF_BOOL mma_is_presentation_part(char *param,  MmsEntryHeader *eHeader)
{
	while(eHeader && param)
	{
		if (eHeader->headerType == MMS_WELL_KNOWN_CONTENT_ID)
		{
				if(0 == msf_cmmn_strcmp_nc(
								(char*)param, 
                                (const char*)eHeader->value.wellKnownFieldName))
								{
								return TRUE;
								}
		
		}
		else if (MMS_APPLICATION_HEADER == eHeader->headerType)
            {
                if (strcmp((char *)eHeader->value.applicationHeader.name, "Content-ID") == 0)
                {
                    if (0 == msf_cmmn_strcmp_nc(
						(char*)param,
						(char*)eHeader->value.applicationHeader.value))
                    {
                        return TRUE;
                    } 
                } 
            }
	eHeader = eHeader->next;	
	}
  return FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mma_is_slide_object
 * DESCRIPTION
 * identifies if an object is slide object,matching the src string of smil with the content id, content location of the objects
 *  
 * PARAMETERS
 *  body     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MSF_BOOL mma_is_slide_object(const SmilMediaObject *mediaObj, 
	const mma_mms_object_struct *obj)
{
  
	
    if (0 == msf_cmmn_strncmp_nc(mediaObj->src, "cid:", 4))
    {
        
        if (mediaObj->src[4] == 0)
        {
            return FALSE;
        } 
				
			if(obj->content_id)
				{
                    if (0 == msf_cmmn_strncmp_nc(
						(char*)obj->content_id, 
						(char*)mediaObj->src + 4, 
                        (int)strlen((char*)mediaObj->src + 4)))
                    {
                        return TRUE;
                    } 
			}				
           
				if(obj->content_location)
				{  	
				 if (0 == msf_cmmn_strncmp_nc(
							(char*)obj->content_location, 
							(char*)mediaObj->src + 4, 
						    (int)strlen((char*)mediaObj->src + 4)))
						{
							return TRUE;
						} 
				}     
    }     
	else 
    {
        
        if (mediaObj->src[0] == 0)
        {
            return FALSE;
        } 

					
				if(obj->content_id)
				{
                    if (0 == msf_cmmn_strncmp_nc(
						(char*)obj->content_id,
                        (char*)mediaObj->src,
                        (int)strlen((char*)mediaObj->src)))
                    {
                        return TRUE;
                    } 
       	
				}
				if(obj->content_location)
				{  
					if (0 == msf_cmmn_strncmp_nc(
						(char*) obj->content_location, 
						(char*)mediaObj->src,
						(int)strlen((char*)mediaObj->src)))
                    {
                        return TRUE;
                    }        
				}

    } 
    return FALSE;
}

#ifdef MMS_CONTENT_DUMP_DATA 
/*****************************************************************************
 * FUNCTION
 *  mma_trace_mms_content_info
 * DESCRIPTION
 * Prints the MMS content information in LOGS
 *  
 * PARAMETERS
 *  body     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void mma_trace_mms_content_info(mma_mms_description_struct *content_info)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (content_info)
	{
	    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_MMS_INFO_START, "(mma_msg_struct.c)mms_info starts\n"));
		if(content_info->header)
		{
			if(content_info->header->header)
			{
				MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_MMS_HEADER_INFO, "(mma_msg_struct.c)mms_header_info\n"));
				if(content_info->header->header->to)
				{	/*all addresses*/
					mma_mms_addr_list_struct *addr = content_info->header->header->to;
					
					while(addr)
					{
						MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_MMS_ADDRESS, "(mma_msg_struct.c)address string = %s, address_type = %d, address_group_type = %d\n",addr->address, addr->addr_type, addr->group));
						addr = addr->next;
					}
				
				}
				if(content_info->header->header->subject.text)
				{
					/* subject of the message */
					MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_MMS_SUBJECT, "(mma_msg_struct.c)subject: %s\n", content_info->header->header->subject.text));
				}
				if(content_info->header->header->presentation)
				{
					/*presentation part SMIL*/
					MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_MMS_PRESENTATION, "(mma_msg_struct.c)presentation: %s\n", content_info->header->header->presentation));
				}
				if(content_info->header->header->app_id)
				{
					/*application ID in case of JAVA MMS*/
					MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_MMS_APP_ID, "(mma_msg_struct.c)app_id: %s\n", content_info->header->header->app_id));
				}
				if(content_info->header->header->reply_app_id)
				{
					/*reply application id in case of JAVA MMS*/
					MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_MMS_REPLY_APP_ID, "(mma_msg_struct.c)reply_app_id: %s\n", content_info->header->header->reply_app_id));
				}
					/*read report, delivery report, priority, version, Date, Msg class, visibility*/
					    MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_MMS_RR_DR_DT_VBLTY_VRN_PRT_CLASS,
                      "(mma_msg_struct.c)(read_report = %d, delivery_report = %d, date = %d, visibility = %d, version = %d, priority = %d, message_class = %d)\n", content_info->header->header->read_reply, content_info->header->header->delivery_report, content_info->header->header->date, content_info->header->header->visibility, content_info->header->header->version, content_info->header->header->priority, content_info->header->header->msg_class.class_identifier));



			}
		}

		if(content_info->body)
		{
			/*printing body information*/
			MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_MMS_BODY_ELEMENT_INFO, "(mma_msg_struct.c)body: slide no = %d, obj no  = %d, imgfit = %d, txtfit = %d, bgcolor = %d, fgcolor = %d, layout = %d\n", content_info->body->slide_no, content_info->body->obj_no, content_info->body->image_fit, content_info->body->text_fit, content_info->body->bgColor, content_info->body->fgColor, content_info->body->layout));
			if(content_info->body->slides)
			{
				mma_mms_slide_struct *slides = content_info->body->slides;
				while(slides)
				{
					/*Printing slide index and duration */
					MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_SLIDE_INFO, "(mma_msg_struct.c)slide: id = %d, dur = %d\n", slides->slide_num, slides->duration));
					if(slides->txt.object)
					{
						/*text*/
						MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_SLIDE_TEXT_OBJ_INFO, "(mma_msg_struct.c)txt: id = %d, begin  = %d, end = %d, bgcolor = %d, fgcolor = %d, textsize = %d, textstyle = %d\n", slides->txt.id, slides->txt.begin, slides->txt.end, slides->txt.bg_color, slides->txt.fg_color, slides->txt.text_size, slides->txt.text_style));
						if(slides->txt.region_area)
						{

							MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_SLIDE_OBJ_REGION_INFO, "(mma_msg_struct.c)slide_obj_region: x = %d, y  = %d, h = %d, w = %d", slides->txt.region_area->x, slides->txt.region_area->y, slides->txt.region_area->h, slides->txt.region_area->w));
						
						}
					
					}
					if(slides->img.object)
					{
						/*image*/
						MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_SLIDE_IMAGE_OBJ_INFO, "(mma_msg_struct.c)img: id = %d, begin  = %d, end = %d\n", slides->img.id, slides->img.begin, slides->img.end));
						if(slides->img.region_area)
						{

							MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_SLIDE_OBJ_REGION_INFO, "(mma_msg_struct.c)slide_obj_region: x = %d, y  = %d, h = %d, w = %d", slides->img.region_area->x, slides->img.region_area->y, slides->img.region_area->h, slides->img.region_area->w));
						
						}
					
					}
					if(slides->aud.object)
					{
						/*audio*/
						MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_SLIDE_AUDIO_OBJ_INFO, "(mma_msg_struct.c)aud: id = %d, begin  = %d, end = %d\n", slides->aud.id, slides->aud.begin, slides->aud.end));
						if(slides->aud.region_area)
						{

							MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_SLIDE_OBJ_REGION_INFO, "(mma_msg_struct.c)slide_obj_region: x = %d, y  = %d, h = %d, w = %d", slides->aud.region_area->x, slides->aud.region_area->y, slides->aud.region_area->h, slides->aud.region_area->w));
						
						}
					
					}
					if(slides->vid.object)
					{
						/*video*/
						MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_SLIDE_VIDEO_OBJ_INFO, "(mma_msg_struct.c)vid: id = %d, begin  = %d, end = %d\n", slides->vid.id, slides->vid.begin, slides->vid.end));
						if(slides->vid.region_area)
						{

							MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_SLIDE_OBJ_REGION_INFO, "(mma_msg_struct.c)slide_obj_region: x = %d, y  = %d, h = %d, w = %d", slides->vid.region_area->x, slides->vid.region_area->y, slides->vid.region_area->h, slides->vid.region_area->w));
						
						}
					}
					if(slides->ref_items)
					{
						mma_mms_slide_ref_object_struct *ref_items = slides->ref_items;
						while(ref_items)
						{
							MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_SLIDE_REF_OBJ_INFO, "(mma_msg_struct.c)ref: id = %d, begin  = %d, end = %d, bgcolor = %d, fgcolor = %d, textsize = %d, textstyle = %d\n", ref_items->id, ref_items->begin, ref_items->end, ref_items->bg_color, ref_items->fg_color, ref_items->text_size, ref_items->text_style));

							if(ref_items->region_area)
							{

								MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_SLIDE_OBJ_REGION_INFO, "(mma_msg_struct.c)slide_obj_region: x = %d, y  = %d, h = %d, w = %d", ref_items->region_area->x, ref_items->region_area->y, ref_items->region_area->h, ref_items->region_area->w));
						
							}
							ref_items = ref_items->next;
						}
					
					}
				
				slides = slides->next;
				}
			
			}
			if(content_info->body->objects)
			{
				mma_mms_object_struct *objs = content_info->body->objects;
				while(objs)
				{
					MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_MMS_BODY_OBJECT_INFO, "(mma_msg_struct.c)obj: id = %d, attach  = %d, vf = %d, drm = %d, size = %d, offset = %d, encoding = %d\n", objs->id, objs->is_attachment, objs->is_virtual_file, objs->drm_type, objs->size, objs->offset, objs->encoding));
					if(objs->file_name)
					{
						MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_MMS_BODY_OBJECT_FILE_NAME, "(mma_msg_struct.c)obj file name : %s\n", objs->file_name));
					}
					if(objs->file_path)
					{
						MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_MMS_BODY_OBJECT_FILE_PATH, "(mma_msg_struct.c)obj file path : %s\n", objs->file_path));
					}
					if(objs->content_id)
					{
						MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_MMS_BODY_OBJECT_CONTENT_ID, "(mma_msg_struct.c)obj content id : %s\n", objs->content_id));
					}
					if(objs->content_location)
					{
						MSF_LOG_MSG_ARGS((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_MMS_BODY_OBJECT_CONTENT_LOCATION, "(mma_msg_struct.c)obj content location : %s\n", objs->content_location));
					}
					objs = objs->next;
				}
			
			}
		}
    MSF_LOG_MSG_NOARG((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MMA, MMA_MMS_STRUCT_MMS_INFO_END, "(mma_msg_struct.c)mms_info ends\n"));
	} 
    
}
#endif	/* MMS_CONTENT_DUMP_DATA */
#endif /* defined(MMS_SUPPORT) */ 
#endif /* _MMA_MSG_STRUCT_C */ 

