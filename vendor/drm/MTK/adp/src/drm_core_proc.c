/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * drm_interface.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for DRM service, wrapper layer.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#ifdef __DRM_MTK__

#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "fs_type.h"

#include "app_mine.h"
#include "app_str.h"
#include "app_base64.h"

#include "drm_prot.h"
#include "drm_def.h"
#include "drm_core_prot.h"
#include "drm_main.h"
#include "drm_util.h"
#include "drm_memory.h"
#include "drm_gprot.h"
#include "drm_trace.h"

#include "app_datetime.h"

#include "custom_mmi_default_value.h"
#include "tst_sap.h"

/*NEW*/
#include "drm_core_def.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"
#include "drm_errcode.h"
#include "fs_func.h"
#include "kal_public_api.h"
#include "fs_errcode.h"
#include "kal_trace.h"
#include "string.h"
#include "che_api.h"
#include "custom_em.h"


#ifndef __MTK_TARGET__
#define __align(x)
#endif 

/*
 * macro
 */
#define DRM_UPDATE_CACHE_POSITION(i, x, v)                                                                                              \
    {                                                                                                                                   \
        g_drm_handles[i].position = v;                                                                                                  \
        DRM_MTK_TRACE(("handle = %d: start/@position/end = %d/%d/%d -%d"),                                                              \
        (TRACE_GROUP_8, DRM_MTK_FILE_UPDATE_01, x, g_drm_handles[i].start, g_drm_handles[i].position, g_drm_handles[i].end, __LINE__)); \
    }

#define DRM_UPDATE_CACHE_START(i, x, v)                                                                                                 \
    {                                                                                                                                   \
        g_drm_handles[i].start = v;                                                                                                     \
        DRM_MTK_TRACE(("handle = %d: @start/position/end = %d/%d/%d -%d"),                                                              \
        (TRACE_GROUP_8, DRM_MTK_FILE_UPDATE_00, x, g_drm_handles[i].start, g_drm_handles[i].position, g_drm_handles[i].end, __LINE__)); \
    }

#define DRM_TAG(X, Y)
#define DRM_PROTECT  kal_take_mutex(g_drm_read_mutex);
#define DRM_UNPROTECT  kal_give_mutex(g_drm_read_mutex);
/*
 * local variable
 */
static drm_cntx_struct general_drm_context;
static kal_mutexid g_drm_read_mutex = NULL;

/*
 * global variable
 */
kal_uint8 current_serial;
kal_uint32 g_drm_cache_size = 0;
drm_cntx_struct *g_drm_cntx = &general_drm_context;

/*
 * external variable
 */
drm_handle_struct g_drm_handles[DRM_MAX_FILE_HANDLE] = {0};


/*****************************************************************************
 * FUNCTION
 *  drm_core_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_core_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return DRM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_init_engine
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_core_init_engine(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_is_version_change())
    {
        FS_CreateDir(DRM_RO_PATH);
    }
    g_drm_read_mutex = kal_create_mutex("drmread");
    
    return DRM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_is_mtk_handle
 * DESCRIPTION
 *  to check the given handle is drm file or not
 * PARAMETERS
 *  handle      [IN]        Handle to check
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool drm_core_is_mtk_handle(FS_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((kal_int32) & g_drm_handles[0] < 0)
    {
        handle = ~(handle);
    }

    if ((void*)handle >= (void*)&g_drm_handles[0] && (void*)handle <= (void*)&g_drm_handles[DRM_MAX_FILE_HANDLE]
        && (handle - (kal_uint32) & g_drm_handles[0]) % sizeof(drm_handle_struct) == 0)
    {
        return KAL_TRUE;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_parse_drm_message
 * DESCRIPTION
 *  To parse DRM message and extract necessary information
 * PARAMETERS
 *  serial          [IN]        
 *  src_path        [IN]        
 *  seed            [IN]        
 *  seed_len        [IN]        
 *  output          [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_core_parse_drm_message(
            kal_uint8 serial,
            kal_wchar *src_path,
            kal_uint8 *seed,
            kal_int32 seed_len,
            drm_message_info_struct *output)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_object_type_enum method;
    FS_HANDLE input, ro = FS_ERROR_RESERVED;
    kal_int32 obj_type, result;
    drm_info_struct *src_info = NULL;
    drm_rights_struct *rights = NULL;
    kal_uint8 *buffer;
    kal_uint8 key[DRM_MAX_KEY_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MTK_TRACE(("drm_core_parse_drm_message"), (TRACE_FUNC, DRM_MTK_API_PARSE_DB));
    
    /* parse input file */
    input = FS_OpenHint(src_path, FS_READ_ONLY, DRM_get_open_hint(src_path));
    if (input < FS_NO_ERROR)
    {
        DRM_MTK_TRACE(("FS_Open = %d"), (TRACE_INFO, DRM_MTK_OPEN_FILE, input));
        DRM_RESULT(result, input, final);
    }

    obj_type = drm_parse_method(input);

    src_info = (drm_info_struct*) drmt_mem_alloc(sizeof(drm_info_struct));
    memset(src_info, 0, sizeof(drm_info_struct));

    rights = src_info->rights = (drm_rights_struct*) drmt_mem_alloc(DRM_RIGHTS_SIZE);
    memset(rights, 0, DRM_RIGHTS_SIZE);

    src_info->content_path = (kal_wchar*) drmt_mem_alloc(DRM_MAX_PATH_LENGTH * ENCODING_LENGTH);
    memset(src_info->content_path, 0, DRM_MAX_PATH_LENGTH * ENCODING_LENGTH);
    app_ucs2_strncpy((kal_int8*) src_info->content_path, (kal_int8*) src_path, kal_wstrlen(src_path));

    rights->constraint_list =
        (drm_constraint_entry_struct*) drmt_mem_alloc(DRM_CONSTRAINT_ENTRY_SIZE * DRM_CONSTRAINT_TOTAL_INDEX);
    memset(rights->constraint_list, 0, DRM_CONSTRAINT_ENTRY_SIZE * DRM_CONSTRAINT_TOTAL_INDEX);

    src_info->meta[DRM_META_CONTENTURI] = (kal_char*) drmt_mem_alloc(DRM_MAX_CID_URL_LENGTH);
    memset(src_info->meta[DRM_META_CONTENTURI], 0, DRM_MAX_CID_URL_LENGTH);

    if (obj_type != MIME_SUBTYPE_DRM_RIGHTS_XML)
    {
        /* rights not present => forward lock */
        method = DRM_TYPE_FORWARD_LOCK;

        DRM_MTK_TRACE(("FL Obj"), (TRACE_INFO, DRM_MTK_OBJ_FL));

        rights->method = DRM_METHOD_FORWARD_LOCK;

        rights->permission = DRM_PERMISSION_ALL;
    }
    else
    {
        method = DRM_TYPE_COMBINED_DELIVERY;

        DRM_MTK_TRACE(("CD Obj"), (TRACE_INFO, DRM_MTK_OBJ_CD));

        rights->method = DRM_METHOD_COMBINED_DELIVERY;

        /* parse rights */
        result = drm_parse_rights(input, rights, src_info->meta[DRM_META_CONTENTURI], DRM_TYPE_COMBINED_DELIVERY);
        if (result != DRM_RESULT_OK)
        {
            DRM_RESULT(result, result, final);
        }

    }
    rights->status = DRM_STATUS_RIGHTS_PRESENT;

    /* parse content */
    result = drm_parse_content(input, rights, &output->encoding, NULL);
    if (result != DRM_RESULT_OK)
    {
        DRM_RESULT(result, result, final);
    }

    output->mime_type = applib_mime_type_look_up(NULL, NULL, 0, rights->mime_type);

    output->plaintext_len = rights->data_len;

    output->plaintext_offset = rights->offset;

    /* generate unique content id for forward lock */
    if (method == DRM_TYPE_FORWARD_LOCK)
        strcpy(src_info->meta[DRM_META_CONTENTURI], "MTK_FL_cid:");
    else
        strcpy(src_info->meta[DRM_META_CONTENTURI], "MTK_CD_cid:");

    drm_core_gen_cid(src_info->meta[DRM_META_CONTENTURI], (kal_char*) seed, seed_len);

    memcpy(&output->cid.id, src_info->meta[DRM_META_CONTENTURI], DRM_MAX_ID_LENGTH);

    output->cid.id_len =
        (strlen(src_info->meta[DRM_META_CONTENTURI]) >
         DRM_MAX_ID_LENGTH) ? DRM_MAX_ID_LENGTH : strlen(src_info->meta[DRM_META_CONTENTURI]);

    /* create rights file */
    if (rights->method != DRM_METHOD_FORWARD_LOCK)
    {
        ro = drm_core_open_rights_object(FS_READ_WRITE, src_info->meta[DRM_META_CONTENTURI], KAL_FALSE);
        if (ro >= FS_NO_ERROR)
        {

            kal_uint32 len;

            /* rights already present, read key to encode content with old key
               then no need to create new rights, just use old rights */
            buffer = drmt_mem_alloc(DRM_MAX_KEY_LENGTH);
            FS_Seek(ro, DRM_MAX_PATH_LENGTH * ENCODING_LENGTH, FS_FILE_BEGIN);
            FS_Read(ro, buffer, DRM_MAX_KEY_LENGTH, &len);
            /* Decrypt ro */
            drm_core_get_key(key);
            drm_core_rc4_decrypt_buff(key, 16, rights->key, buffer, len);
            drmt_mem_free(buffer);
			if(!drm_core_check_is_ro_used(ro))
			{
				FS_Close(ro);
			}
            DRM_RESULT(result, DRM_RESULT_OK, final);
        }
        else
        {
            
            rights->key_len = 16;
            
            /* create rights file */
            ro = drm_core_open_rights_object((FS_READ_WRITE | FS_CREATE_ALWAYS), src_info->meta[DRM_META_CONTENTURI], KAL_FALSE);
            if (ro >= FS_NO_ERROR)
            {
                kal_int32 ro_ret = DRM_RESULT_OK;

                ro_ret = drm_core_create_rights_object(ro, rights, src_info->content_path);
				if(!drm_core_check_is_ro_used(ro))
				{
					FS_Close(ro);
				}
                DRM_RESULT(result, ro_ret, final);
            }
            else
            {
                DRM_RESULT(result, ro, final);
            }
        }
    }

  final:

    FS_Close(input);

    drm_core_release_info(src_info);

    DRM_MTK_TRACE(("result = %x"), (TRACE_INFO, DRM_MTK_RESULT, -result));
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  drm_core_install_object
 * DESCRIPTION
 *  To install DRM objects and populate rights information
 *  Note: always output DCF if source is CD/FL
 * PARAMETERS
 *  serial                      [IN]        Serial number of process
 *  drm_type                    [IN]        MMI_SUBTYPE
 *  src_path                    [IN]        Source file path
 *  src_need_kept               [IN]        To indicate that keep the source file or not
 *  dest_path                   [IN]        Destination file path
 *  dest_buffer_len_in_byte     [IN]        Size of destination file path
 *  mime_type                   [OUT]       Type of media content
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 drm_core_install_object(
            kal_uint8 serial,
            kal_int32 drm_type,
            kal_wchar *src_path,
            kal_bool src_need_kept,
            kal_wchar *dest_path,
            kal_uint32 dest_buffer_len_in_byte,
            applib_mime_type_struct **mime_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE input, ro = FS_ERROR_RESERVED;
    kal_int32 obj_type;
    kal_int32 result = DRM_RESULT_NON_DRM, ro_ret = FS_NO_ERROR;
    kal_uint8 encoding;
    drm_info_struct *info = NULL;
    drm_rights_struct *rights = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MTK_TRACE(("drm_core_install_object"), (TRACE_FUNC, DRM_MTK_API_INSTALL));
    
    if (drmt_async_get_status(serial) == DRM_PROC_ENCRYPT_BUSY)
    {
        current_serial = serial;
    }
    else if (drmt_async_get_status(serial) == DRM_PROC_ENCRYPT_CANCELING)
    {
        drmt_async_set_status(serial, DRM_PROC_ENCRYPT_CANCELED);
        DRM_RESULT(result, DRM_RESULT_CANCELED, final);
    }
    else
    {
        DRM_RESULT(result, DRM_RESULT_INVALID, final);
    }

    if (!drm_check_free_space((kal_int32)DRM_RO_PATH[0], DRM_RIGHTS_SIZE))
    {
        DRM_MTK_TRACE("DRM_RESULT_NO_RIGHTS_SPACE", (TRACE_ERROR, DRM_API_RSP_NO_RO_SPACE));    
        DRM_RESULT(result, DRM_RESULT_NO_RIGHTS_SPACE, final);
    }

    info = (drm_info_struct*) drmt_mem_alloc(sizeof(drm_info_struct));
    memset(info, 0, sizeof(drm_info_struct));

    rights = info->rights = (drm_rights_struct*) drmt_mem_alloc(DRM_RIGHTS_SIZE);
    memset(rights, 0, DRM_RIGHTS_SIZE);
    rights->best[0] = rights->best[1] = rights->best[2] = rights->best[3] = 0xFF;
    
    info->content_path = (kal_wchar*) drmt_mem_alloc(DRM_MAX_PATH_LENGTH * ENCODING_LENGTH);
    memset(info->content_path, 0, DRM_MAX_PATH_LENGTH * ENCODING_LENGTH);
    app_ucs2_strncpy((kal_int8*) info->content_path, (kal_int8*) src_path, kal_wstrlen(src_path));

    info->meta[DRM_META_CONTENTURI] = (kal_char*) drmt_mem_alloc(DRM_MAX_CID_URL_LENGTH);
    memset(info->meta[DRM_META_CONTENTURI], 0, DRM_MAX_CID_URL_LENGTH);

    switch (drm_type)
    {
        case MIME_SUBTYPE_DRM_RIGHTS_XML:
        {
            result = drm_core_add_object(serial, DRM_TYPE_SEPARATE_DELIVERY_RIGHTS, src_path, NULL, NULL, NULL);
            break;
        }
        case MIME_SUBTYPE_DRM_RIGHTS_WBXML:
        {

            result = drm_core_add_object(serial, DRM_TYPE_SEPARATE_DELIVERY_RIGHTS_WB, src_path, NULL, NULL, NULL);
            break;
        }
        case MIME_SUBTYPE_DRM_MESSAGE:
        {
			kal_wchar *src_to_del = NULL;

            rights->constraint_list =
                    (drm_constraint_entry_struct*) drmt_mem_alloc(DRM_CONSTRAINT_ENTRY_SIZE * DRM_CONSTRAINT_TOTAL_INDEX);
                memset(rights->constraint_list, 0, DRM_CONSTRAINT_ENTRY_SIZE * DRM_CONSTRAINT_TOTAL_INDEX);

            input = FS_OpenHint(src_path, FS_READ_WRITE, DRM_get_open_hint(src_path));
            if (input < FS_NO_ERROR)
            {
                DRM_MTK_TRACE(("FS_Open = %d"), (TRACE_INFO, DRM_MTK_OPEN_FILE, input));
                DRM_RESULT(result, input, final);
            }

            obj_type = drm_parse_method(input);

            if (obj_type != MIME_SUBTYPE_DRM_RIGHTS_XML)
            {
                DRM_MTK_TRACE(("FL Obj"), (TRACE_INFO, DRM_MTK_OBJ_FL));

                /* rights not present => forward lock */
                rights->method = DRM_METHOD_FORWARD_LOCK;

                rights->permission = DRM_PERMISSION_ALL;
            }
            else
            {
                DRM_MTK_TRACE(("CD Obj"), (TRACE_INFO, DRM_MTK_OBJ_CD));

                rights->method = DRM_METHOD_COMBINED_DELIVERY;

                /* parse rights */
                result = drm_parse_rights(input, rights, info->meta[DRM_META_CONTENTURI], DRM_TYPE_COMBINED_DELIVERY);
                if (result != DRM_RESULT_OK)
                {
                    FS_Close(input);
                    DRM_RESULT(result, result, final);
                }
            }

            rights->status = DRM_STATUS_RIGHTS_PRESENT;

            /* parse content */
            result = drm_parse_content(input, rights, &encoding, NULL);
            if (result != DRM_RESULT_OK)
            {
                FS_Close(input);
                DRM_RESULT(result, result, final);
            }

            if (encoding == DRM_ENCODING_BASE64)
            {
                drm_parse_base64(input, input, rights, rights->offset);
            }

            if (rights->method == DRM_METHOD_FORWARD_LOCK)
            {
                if (rights->mime_type == MIME_SUBTYPE_DRM_CONTENT)
                {
                    result = drm_core_add_fl_sd_object(src_path, input, info, dest_path, 0);

                    *mime_type = applib_mime_type_look_up(NULL, NULL, 0, rights->mime_type);

                    if (result != DRM_RESULT_OK)
                    {
                        FS_Close(input);
                    }
                    DRM_RESULT(result, result, final);
                }

            }

            /* if content id wasn't initiated */
            if (strlen(info->meta[DRM_META_CONTENTURI]) == 0)
            {
                if (rights->method == DRM_METHOD_FORWARD_LOCK)
                {
                    strcpy(info->meta[DRM_META_CONTENTURI], "MTK_FL_cid:");
                }
                else
                {
                    strcpy(info->meta[DRM_META_CONTENTURI], "MTK_CD_cid:");
                    drm_core_gen_cid(info->meta[DRM_META_CONTENTURI], NULL, 0);
                }
            }

            if (rights->key_len == 0)
            {
                rights->key_len = 16;
                drm_core_get_key(rights->key);
            }

            *mime_type = applib_mime_type_look_up(NULL, NULL, 0, rights->mime_type);

			if (src_path && !src_need_kept)
			{
				src_to_del = (kal_wchar *)drmt_mem_alloc((app_ucs2_strlen((kal_int8 *)src_path) + 1) * sizeof(kal_wchar));
				app_ucs2_strcpy((kal_int8 *)src_to_del, (kal_int8 *)src_path);
			}

            if (rights->mime_type == 0xFF)
                drm_replace_file_extension_secure(dest_path, dest_buffer_len_in_byte, NULL);
            else
                drm_replace_file_extension_secure(dest_path, dest_buffer_len_in_byte, *mime_type);

            app_ucs2_strcpy((kal_int8*) info->content_path, (kal_int8*) dest_path);

            /* create dcf file */
            result = drm_core_encode_dcf(input, info, KAL_FALSE, KAL_FALSE, KAL_FALSE);
            if (drm_core_validate_permission_aux(input) == KAL_FALSE)
            {
                result = DRM_RESULT_NO_PERMISSION;
            }

            FS_Close(input);

            if (src_to_del && !src_need_kept)
            {
                FS_Delete(src_to_del);
				drmt_mem_free(src_to_del);
            }

            if (result != DRM_RESULT_OK)
            {
                if (result == DRM_RESULT_CANCELED)
                {

                    if (dest_path)
                    {
                        FS_Delete(dest_path);
                    }
                }

                DRM_RESULT(result, result, final);

            }

            if (ro < FS_NO_ERROR && rights->method != DRM_METHOD_FORWARD_LOCK)
            {
                /* create rights file */
                ro = drm_core_open_rights_object((FS_READ_WRITE | FS_CREATE_ALWAYS), info->meta[DRM_META_CONTENTURI], KAL_FALSE);
                if (ro >= FS_NO_ERROR)
                {
                    ro_ret = drm_core_create_rights_object(ro, rights, info->content_path);
					if(!drm_core_check_is_ro_used(ro))
					{
						FS_Close(ro);
					}
                    result = ro_ret;
                }
                else
                {
                    DRM_RESULT(result, ro, final);
                }
            }

            break;
        }
        case MIME_SUBTYPE_DRM_CONTENT:
        {
            DRM_MTK_TRACE(("SD Obj"), (TRACE_INFO, DRM_MTK_OBJ_SD_00));

            rights->method = DRM_METHOD_SEPARATE_DELIVERY;
            rights->status = DRM_STATUS_RIGHTS_PENDING;

            input = FS_OpenHint(src_path, FS_READ_ONLY, DRM_get_open_hint(src_path));

            if (input < DRM_RESULT_OK)
            {
                DRM_MTK_TRACE(("FS_Open = %d"), (TRACE_INFO, DRM_MTK_OPEN_FILE, input));
                DRM_RESULT(input, input, final);
            }

            result = drm_parse_dcf(input, info);
            if (result != DRM_RESULT_OK)
            {
                FS_Close(input);
                DRM_RESULT(result, result, final);
            }

            ro = drm_core_open_rights_object(FS_READ_WRITE, info->meta[DRM_META_CONTENTURI], KAL_FALSE);
            if (ro < FS_NO_ERROR || drm_core_load_rights_dcf(ro, rights) == KAL_FALSE)
            {
                /* cid not present => rights pending */
                DRM_MTK_TRACE(("SD w/o rights"), (TRACE_INFO, DRM_MTK_OBJ_SD_01));

                ro = drm_core_open_rights_object((FS_READ_WRITE | FS_CREATE_ALWAYS), info->meta[DRM_META_CONTENTURI], KAL_FALSE);
                rights->permission = DRM_PERMISSION_NONE;

            }

            drm_core_create_rights_object(ro, rights, info->content_path);
			if(!drm_core_check_is_ro_used(ro))
			{
				FS_Close(ro);
			}
			FS_Close(input);
            if (ro < FS_NO_ERROR)
            {
                DRM_RESULT(result, ro, final);
            }

            *mime_type = applib_mime_type_look_up(NULL, NULL, 0, rights->mime_type);

            if (dest_path)
            {
                if (rights->mime_type == 0xFF)
                    drm_replace_file_extension_secure(dest_path, dest_buffer_len_in_byte, NULL);
                else
                    drm_replace_file_extension_secure(dest_path, dest_buffer_len_in_byte, *mime_type);

                result = FS_Move(src_path, dest_path, FS_MOVE_KILL, NULL, NULL, 0);

                if (result < FS_NO_ERROR)
                {
                    if (result == FS_FILE_EXISTS)
                    {
                        result = DRM_RESULT_FILE_EXISTS;
                    }
                }
            }

            break;
        }
        default:
            break;
    }

  final:

    if (result == DRM_RESULT_OK)
    {
        drmt_async_set_status(serial, DRM_PROC_ENCRYPT_FINISHED);
    }
    else if (drmt_async_get_status(serial) == DRM_PROC_ENCRYPT_CANCELING)
    {
        drmt_async_set_status(serial, DRM_PROC_ENCRYPT_CANCELED);
        result = DRM_RESULT_CANCELED;
    }
    else
    {
        drmt_async_set_status(serial, DRM_PROC_ENCRYPT_FINISHED);
    }

    /* release drm_info_struct */
    drm_core_release_info(info);

    DRM_MTK_TRACE(("result = %x"), (TRACE_INFO, DRM_MTK_RESULT, -result));
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  drm_core_encode_drm_message
 * DESCRIPTION
 *  To install DRM objects and populate rights information
 *  Note: always output DCF if source is CD/FL
 * PARAMETERS
 *  serial                          [IN]        Serial number of process
 *  src_path                        [IN]        Source file path
 *  dest_path                       [IN]        Destination file path
 *  offset                          [IN]        
 *  dest_buffer_len_in_byte(?)      [IN]        Size of destination file path
 *  src_need_kept(?)                [IN]        To indicate that keep the source file or not
 *  mime_type(?)                    [OUT]       Type of media content
 *  drm_type(?)                     [IN]        MMI_SUBTYPE
 * RETURNS
 *  drm_proc_enum
 *****************************************************************************/
kal_int32 drm_core_encode_drm_message(kal_uint8 serial, kal_wchar *src_path, kal_wchar *dest_path, kal_uint32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE input, ro = FS_ERROR_RESERVED, new_dcf;
    kal_int32 obj_type;
    kal_int32 result = DRM_RESULT_NON_DRM, ro_ret = FS_NO_ERROR;
    kal_uint8 encoding;
    drm_info_struct *info = NULL;
    drm_rights_struct *rights = NULL;
    kal_uint8 *buffer;
    kal_uint8 key[DRM_MAX_KEY_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MTK_TRACE(("drm_core_encode_drm_message"), (TRACE_FUNC, DRM_MTK_API_ENCODE_DM));

    if (drmt_async_get_status(serial) == DRM_PROC_ENCRYPT_BUSY)
    {
        current_serial = serial;
    }
    else if (drmt_async_get_status(serial) == DRM_PROC_ENCRYPT_CANCELING)
    {
        drmt_async_set_status(serial, DRM_PROC_ENCRYPT_CANCELED);
        DRM_RESULT(result, DRM_RESULT_CANCELED, final);
    }
    else
    {
        DRM_RESULT(result, DRM_RESULT_INVALID, final);
    }

    info = (drm_info_struct*) drmt_mem_alloc(sizeof(drm_info_struct));
    memset(info, 0, sizeof(drm_info_struct));

    rights = info->rights = (drm_rights_struct*) drmt_mem_alloc(DRM_RIGHTS_SIZE);
    memset(rights, 0, DRM_RIGHTS_SIZE);
    rights->best[0] = rights->best[1] = rights->best[2] = rights->best[3] = 0xFF;

    info->content_path = (kal_wchar*) drmt_mem_alloc(DRM_MAX_PATH_LENGTH * ENCODING_LENGTH);
    memset(info->content_path, 0, DRM_MAX_PATH_LENGTH * ENCODING_LENGTH);
    app_ucs2_strncpy((kal_int8*) info->content_path, (kal_int8*) src_path, kal_wstrlen(src_path));
    rights->constraint_list =
        (drm_constraint_entry_struct*) drmt_mem_alloc(DRM_CONSTRAINT_ENTRY_SIZE * DRM_CONSTRAINT_TOTAL_INDEX);
    memset(rights->constraint_list, 0, DRM_CONSTRAINT_ENTRY_SIZE * DRM_CONSTRAINT_TOTAL_INDEX);

    info->meta[DRM_META_CONTENTURI] = (kal_char*) drmt_mem_alloc(DRM_MAX_CID_URL_LENGTH);
    memset(info->meta[DRM_META_CONTENTURI], 0, DRM_MAX_CID_URL_LENGTH);

    input = FS_OpenHint(src_path, FS_READ_ONLY, DRM_get_open_hint(src_path));
    if (input < FS_NO_ERROR)
    {
        DRM_MTK_TRACE(("FS_Open = %d"), (TRACE_INFO, DRM_MTK_OPEN_FILE, input));
        DRM_RESULT(result, input, final);
    }

    obj_type = drm_parse_method(input);

    if (obj_type != MIME_SUBTYPE_DRM_RIGHTS_XML)
    {
        DRM_MTK_TRACE(("FL Obj"), (TRACE_INFO, DRM_MTK_OBJ_FL));

        /* rights not present => forward lock */
        rights->method = DRM_METHOD_FORWARD_LOCK;
        rights->permission = DRM_PERMISSION_ALL;

    }
    else
    {
        DRM_MTK_TRACE(("CD Obj"), (TRACE_INFO, DRM_MTK_OBJ_CD));

        rights->method = DRM_METHOD_COMBINED_DELIVERY;

        /* parse rights */
        result = drm_parse_rights(input, rights, info->meta[DRM_META_CONTENTURI], DRM_TYPE_COMBINED_DELIVERY);
        if (result != DRM_RESULT_OK)
        {
            FS_Close(input);
            DRM_RESULT(result, result, final);
        }
    }

    rights->status = DRM_STATUS_RIGHTS_PRESENT;

    /* parse content */
    result = drm_parse_content(input, rights, &encoding, NULL);
    if (result != DRM_RESULT_OK)
    {
        FS_Close(input);
        DRM_RESULT(result, result, final);
    }

    if (rights->method == DRM_METHOD_FORWARD_LOCK)
    {
        if (rights->mime_type == MIME_SUBTYPE_DRM_CONTENT)
        {
            if (encoding == DRM_ENCODING_BASE64)
            {
                new_dcf = FS_Open(dest_path, FS_READ_WRITE);
                //FS_Seek(new_dcf, offset + 100, FS_FILE_BEGIN);
                drm_parse_base64(input, new_dcf, rights, offset + 10); /* MTK_FLDCF_cid */

                FS_Close(new_dcf);
                FS_Close(input);

                input = FS_Open(dest_path, FS_READ_WRITE);
                FS_Seek(input, offset + 10, FS_FILE_BEGIN); /* MTK_FLDCF_cid */
            }
            result = drm_core_add_fl_sd_object(src_path, input, info, dest_path, offset);

            if (result != DRM_RESULT_OK)
            {
                FS_Close(input);
            }
            DRM_RESULT(result, result, final);
        }
    }

    /* initiat content id */
    if (rights->method == DRM_METHOD_FORWARD_LOCK)
    {
        strcpy(info->meta[DRM_META_CONTENTURI], "MTK_FL_cid:");
    }
    else
    {
        strcpy(info->meta[DRM_META_CONTENTURI], "MTK_CD_cid:");
        drm_core_gen_cid(info->meta[DRM_META_CONTENTURI], NULL, 0);
    }   
    
    if (rights->key_len == 0)
    {
        rights->key_len = 16;
        drm_core_get_key(rights->key);
    }

    /* 
     * src_path must be deleted before dest_path be replaced,
     * or we can't find src anymore if src == dest
     */

    app_ucs2_strcpy((kal_int8*) info->content_path, (kal_int8*) dest_path);

    /* create dcf file */
    /* new SAP for MMS virtual file - start */
    result = drm_core_encode_dcf(input, info, KAL_TRUE, offset, encoding);
    /* new SAP for MMS virtual file - end */

    FS_Close(input);

    if (result != DRM_RESULT_OK)
    {
        DRM_RESULT(result, result, final);

    }

    if (rights->method != DRM_METHOD_FORWARD_LOCK)
    {
        /* check rights present */
        ro = drm_core_open_rights_object(FS_READ_WRITE, info->meta[DRM_META_CONTENTURI], KAL_FALSE);
        if (ro >= FS_NO_ERROR)
        {
            kal_uint32 len;

            /* rights already present, read key to encode content with old key
               then no need to create new rights, just use old rights */
            buffer = drmt_mem_alloc(DRM_RIGHTS_SIZE);
            FS_Seek(ro, DRM_MAX_PATH_LENGTH * ENCODING_LENGTH, FS_FILE_BEGIN);
            FS_Read(ro, buffer, DRM_RIGHTS_SIZE, &len);
            /* Decrypt ro */
            drm_core_get_key(key);
            drm_core_rc4_decrypt_buff(key, 16, (kal_uint8*) rights, buffer, len);
            drmt_mem_free(buffer);

			if(!drm_core_check_is_ro_used(ro))
			{
				FS_Close(ro);
			}
        }
        else
        {
            /* create rights file */
            ro = drm_core_open_rights_object((FS_READ_WRITE | FS_CREATE_ALWAYS), info->meta[DRM_META_CONTENTURI], KAL_FALSE);
            if (ro >= FS_NO_ERROR)
            {
                ro_ret = drm_core_create_rights_object(ro, rights, info->content_path);
				if(!drm_core_check_is_ro_used(ro))
				{
					FS_Close(ro);
				}		
				result = ro_ret;
            }
            else
            {
                DRM_RESULT(result, ro, final);
            }
        }
    }

  final:

    if (result == DRM_RESULT_OK)
    {
        drmt_async_set_status(serial, DRM_PROC_ENCRYPT_FINISHED);
    }
    else if (drmt_async_get_status(serial) == DRM_PROC_ENCRYPT_CANCELING)
    {
        drmt_async_set_status(serial, DRM_PROC_ENCRYPT_CANCELED);
        result = DRM_RESULT_CANCELED;
    }
    else
    {
        drmt_async_set_status(serial, DRM_PROC_ENCRYPT_FINISHED);
    }

    /* release drm_info_struct */
    drm_core_release_info(info);

    DRM_MTK_TRACE(("result = %x"), (TRACE_INFO, DRM_MTK_RESULT, -result));
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  drm_core_msg_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  current_ilm         [?]         [?]         [?]
 *  drm_is_blocking     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool drm_core_msg_handler(ilm_struct *current_ilm, kal_bool drm_is_blocking)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (current_ilm->msg_id)
    {
        case MSG_ID_TST_INJECT_STRING:
        {
            tst_module_string_inject_struct *tst_inject =
                (tst_module_string_inject_struct*) current_ilm->local_para_ptr;
            if (strcmp((kal_char*) tst_inject->string, "wk_size") == 0)
            {
            #ifdef __HW_CHE__
                g_drm_cache_size = tst_inject->index * 1024 - 48;
            #else 
                g_drm_cache_size = tst_inject->index * 1024 - 16;
            #endif 
            }

            break;
        }

        default:
            /* this message no one handle */
            return KAL_FALSE;
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_async_get_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_core_async_get_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DRM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_async_free_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  serial(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_core_async_free_handle(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DRM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_async_cancel_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  serial(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_core_async_cancel_handle(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DRM_RESULT_OK;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  drm_core_open_file_aux
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path               [?]         [?]         [?]
 *  flags                   [IN]        
 *  permission              [IN]        
 *  want_to_register        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
FS_HANDLE drm_core_open_file_aux(
            kal_wchar *file_path,
            kal_uint32 flags,
            kal_uint8 permission,
            kal_bool want_to_register)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return drm_core_open_file(file_path, flags, permission);
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_register_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ucs2path            [?]         
 *  flags(?)            [IN]        
 *  permission(?)       [IN]        
 *  file_path       [?]         [?](?)
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_core_register_file(kal_wchar *ucs2path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh, ro;
    kal_char *cid;
    drm_rights_struct *rights = NULL;
    kal_int32 ro_ret;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fh = drm_core_slim_open(ucs2path);

    if (fh < DRM_RESULT_OK)
    {
        return fh;
    }
    else
    {
        /* create rights file */
        cid = drmt_mem_alloc(DRM_MAX_CID_URL_LENGTH);        
        DRM_get_meta_data(fh, DRM_META_CONTENTURI, cid, DRM_MAX_CID_URL_LENGTH);
        drm_core_close_file(fh);
        /* content id is invalid or FL or CD*/
        if (!drm_core_is_mtk_handle(fh) || strlen((char*)cid) == 0 || (strncmp(cid, "MTK_FL_cid", 10) == 0))
        {
            drmt_mem_free(cid);
            return DRM_RESULT_INVALID;
        }
        ro = drm_core_open_rights_object((FS_READ_WRITE), cid, KAL_FALSE);
        drmt_mem_free(cid);
        if (ro >= FS_NO_ERROR)
        {
            ro_ret = drm_core_create_rights_object(ro, rights, (kal_wchar*)ucs2path); 
			if(!drm_core_check_is_ro_used(ro))
			{
				FS_Close(ro);
			}
            return ro_ret;
        }
        else
        {
            return (kal_int32)ro;
        }             
    }
}

/*****************************************************************************
 * FUNCTION
 *  drm_core_slim_open
 * DESCRIPTION
 *  Slim version of drm open file for registering file, not to create ro file.
 * PARAMETERS
 *  file_path               [?]         [?]         [?]
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
FS_HANDLE drm_core_slim_open(kal_wchar *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 index;
    drm_info_struct *info;
    FS_HANDLE input;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!app_ucs2_strlen((const kal_int8*)file_path))
    {
        DRM_MTK_TRACE(("drm_open_file: Empty path"), (TRACE_WARNING, DRM_MTK_FILE_OPEN_00));
        return FS_INVALID_FILENAME;
    }

    if (app_ucs2_strlen((const kal_int8*)file_path) >= DRM_MAX_PATH_LENGTH)
    {
        return FS_INVALID_FILENAME;
    }
    
    input = FS_OpenHint(file_path, FS_READ_ONLY, DRM_get_open_hint(file_path));
    if (input < FS_NO_ERROR)
    {
        return input;
    }

    index = FS_ParseFH(input);
    
    if (index < FS_NO_ERROR)
    {
        return index;
    }
    //ASSERT(index >= FS_NO_ERROR);

    g_drm_handles[index].ro = FS_ERROR_RESERVED;
    g_drm_handles[index].previous_blk = FS_ERROR_RESERVED;

    info = g_drm_handles[index].info = (drm_info_struct*) drmt_mem_alloc(sizeof(drm_info_struct));
    memset(info, 0, sizeof(drm_info_struct));

    info->rights = (drm_rights_struct*) drmt_mem_alloc(DRM_RIGHTS_SIZE);
    memset(info->rights, 0, sizeof(drm_rights_struct));

    info->content_path = (kal_wchar*) drmt_mem_alloc(DRM_MAX_PATH_LENGTH * ENCODING_LENGTH);
    app_ucs2_strcpy((kal_int8*) info->content_path, (kal_int8*) file_path);

    if (drm_core_is_dcf_format(input, info) == KAL_TRUE)
    {
        g_drm_handles[index].handle = input;
        return drm_core_traslate_file_handle((FS_HANDLE) & g_drm_handles[index]);
    }
    
    /* non DRM file */
    drm_core_release_info(info);
    memset(&g_drm_handles[index], 0, sizeof(drm_handle_struct));
    FS_Seek(input, 0, FS_FILE_BEGIN);
    return input;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_open_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [?]         [?]         [?]
 *  flags           [IN]        
 *  permission      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
FS_HANDLE drm_core_open_file(kal_wchar *file_path, kal_uint32 flags, kal_uint8 permission)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 index;
    drm_info_struct *info;
    FS_HANDLE input, ro;
    kal_int32 size1 = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!app_ucs2_strlen((const kal_int8*)file_path))
    {
        DRM_MTK_TRACE(("drm_open_file: Empty path"), (TRACE_WARNING, DRM_MTK_FILE_OPEN_00));
        return FS_INVALID_FILENAME;
    }

    if (app_ucs2_strlen((const kal_int8*)file_path) >= DRM_MAX_PATH_LENGTH)
    {
        return FS_INVALID_FILENAME;
    }

    if ((flags & FS_CREATE) || (flags & FS_CREATE_ALWAYS) || (flags & FS_READ_WRITE))
    {
        return FS_OpenHint(file_path, flags, DRM_get_open_hint(file_path));
    }

    input = FS_OpenHint(file_path, flags, DRM_get_open_hint(file_path));
    if (input < FS_NO_ERROR)
    {
        return input;
    }

    index = FS_ParseFH(input);
    
    if (index < FS_NO_ERROR)
    {
        return index;
    }
    //ASSERT(index >= FS_NO_ERROR);

    g_drm_handles[index].ro = FS_ERROR_RESERVED;
    g_drm_handles[index].previous_blk = FS_ERROR_RESERVED;

    info = g_drm_handles[index].info = (drm_info_struct*) drmt_mem_alloc(sizeof(drm_info_struct));
    memset(info, 0, sizeof(drm_info_struct));

    info->rights = (drm_rights_struct*) drmt_mem_alloc(DRM_RIGHTS_SIZE);
    memset(info->rights, 0, sizeof(drm_rights_struct));

    info->content_path = (kal_wchar*) drmt_mem_alloc(DRM_MAX_PATH_LENGTH * ENCODING_LENGTH);
    app_ucs2_strcpy((kal_int8*) info->content_path, (kal_int8*) file_path);

    if (drm_core_is_dcf_format(input, info) == KAL_TRUE)
    {
        FS_GetFileSize(input, &g_drm_handles[index].dcf_size);
        /* is DRM file */
        if (info->rights->method == DRM_METHOD_FORWARD_LOCK)
        {
            ro = FS_ERROR_RESERVED;
            if (info->rights->data_len == 0)
            {
                drm_core_release_info(info);
                memset(&g_drm_handles[index], 0, sizeof(drm_handle_struct));
                FS_Close(input);
                return DRM_RESULT_INVALID_FORMAT;
            }
        }
        else
        {
            ro = drm_core_open_rights_object(
                    (FS_READ_WRITE | FS_COMMITTED | FS_OPEN_SHARED),
                    info->meta[DRM_META_CONTENTURI], KAL_FALSE);
        }


        if (drm_core_load_rights_dcf(ro, info->rights) == KAL_TRUE)
        {
            kal_uint32 file_size;

            FS_GetFileSize(ro, &file_size);

            /* rights present */
            DRM_MTK_TRACE(
                ("drm_open_file: w/ rigths, length = %d"),
                (TRACE_GROUP_9, DRM_MTK_FILE_OPEN_00, info->rights->data_len));
            g_drm_handles[index].ro = ro;

            FS_Seek(input, info->rights->offset, FS_FILE_BEGIN);
            g_drm_handles[index].handle = input;
            g_drm_handles[index].info = info;
            //kal_prompt_trace(MOD_DRMT, "[DRM] drm_core_open_file before_calling file_size update");
            input=drm_core_traslate_file_handle((FS_HANDLE) & g_drm_handles[index]);
            drm_core_file_size(input, &size1); /*Update file size (data_len) in rights file*/
            //kal_prompt_trace(MOD_DRMT, "[DRM] drm_core_open_file ro=%d, index = %d, size = %d", ro, index, g_drm_handles[index].info->rights->data_len);
            return drm_core_traslate_file_handle((FS_HANDLE) & g_drm_handles[index]);
        }
        else
        {
            /* rights not present */
            DRM_MTK_TRACE(("drm_open_file: w/o rights"), (TRACE_GROUP_9, DRM_MTK_FILE_OPEN_02));

            if ((info->rights->method & DRM_METHOD_SEPARATE_DELIVERY) && ro != FS_ACCESS_DENIED)
            {
				ro = drm_core_open_rights_object((FS_READ_WRITE | FS_CREATE_ALWAYS), info->meta[DRM_META_CONTENTURI], KAL_TRUE);

                if (ro <= FS_NO_ERROR)
                {
                    drm_core_release_info(info);
                    memset(&g_drm_handles[index], 0, sizeof(drm_handle_struct));
                    FS_Close(input);
                    return DRM_RESULT_INVALID_FORMAT;
                }

                info->rights->best[0] = info->rights->best[1] = info->rights->best[2] = info->rights->best[3] = 0xFF;
                
                drm_core_create_rights_object(ro, info->rights, info->content_path);
                FS_Rename(file_path, info->content_path);

                g_drm_handles[index].ro = ro;
                FS_Seek(input, info->rights->offset, FS_FILE_BEGIN);
                g_drm_handles[index].handle = input;
                return drm_core_traslate_file_handle((FS_HANDLE) & g_drm_handles[index]);
            }
            /* can't open forward lock or combined delivery without rights
               because it means the content is not stored by this device */
			if(!drm_core_check_is_ro_used(ro))
			{
				FS_Close(ro);
			}
            /* memset(info->rights, 0, DRM_RIGHTS_SIZE); */
            info->rights->method = DRM_METHOD_COMBINED_DELIVERY;

            ro = drm_core_open_rights_object((FS_READ_WRITE | FS_CREATE_ALWAYS), info->meta[DRM_META_CONTENTURI], KAL_TRUE);
            drm_core_create_rights_object(ro, info->rights, info->content_path);

            if (ro == FS_ACCESS_DENIED)
            {
                drm_core_release_info(info);
				memset(&g_drm_handles[index], 0, sizeof(drm_handle_struct));
				FS_Close(input);
				return ro;
            }
            g_drm_handles[index].ro = ro;

            g_drm_handles[index].handle = input;
            return drm_core_traslate_file_handle((FS_HANDLE) & g_drm_handles[index]);
        }
    }
    /* non DRM file */
    drm_core_release_info(info);
    memset(&g_drm_handles[index], 0, sizeof(drm_handle_struct));
    FS_Seek(input, 0, FS_FILE_BEGIN);
    return input;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_close_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  object(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_core_close_file(FS_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE ro;
    kal_int32 i, index;
    kal_uint32 ref_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_core_is_mtk_handle(handle))
    {
        drm_info_struct *info;
        drm_handle_struct *nh = (drm_handle_struct*) drm_core_reverse_file_handle(handle);

        handle = nh->handle;

        index = FS_ParseFH(handle);

        /* file already closed */
        if (index < FS_NO_ERROR)
        {
            return FS_NO_ERROR;
        }

        info = g_drm_handles[index].info;

        /* release drm_info_struct */
        drm_core_release_info(info);

        /* release cache */
        if ((g_drm_handles[index].cache) && (g_drm_handles[index].previous_blk != (kal_int8)FS_ERROR_RESERVED))
        {
            DRM_MTK_TRACE(("drm_close_file: handle = %d -%d"), (TRACE_GROUP_8, DRM_MTK_FILE_CLOSE, handle, __LINE__));

            drmt_mem_free(g_drm_handles[index].cache);
        }

        /* release ro handle, if nobody else is using */
        ro = g_drm_handles[index].ro;
        if (ro != NULL)
        {
            for (i = 0; i < DRM_MAX_FILE_HANDLE; i++)
            {
                if (i == index)
                {
                    continue;
                }
                if (g_drm_handles[i].ro == ro)
                {
                    ref_count++;
                }
            }

            if (ref_count == 0)
            {
                FS_Close(ro);
            }
        }

        /* release media content handle */
        FS_Close(handle);

        memset(&g_drm_handles[index], 0, sizeof(drm_handle_struct));
        return FS_NO_ERROR;

    }
    else
    {
        return FS_Close(handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_read_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle          [IN]        
 *  buffer          [?]         [?]         [?]
 *  size            [IN]        
 *  length          [?]         [?]         [?]
 *  source(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
drm_proc_enum drm_core_read_file(FS_HANDLE handle, void *buffer, kal_uint32 size, kal_uint32 *length)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = 0, index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_core_is_mtk_handle(handle))
    {
        drm_handle_struct *source = (drm_handle_struct*) drm_core_reverse_file_handle(handle);

        handle = source->handle;

        index = FS_ParseFH(handle);

        /* card removed or unmounted */
        if (index == FS_MEDIA_CHANGED || index == FS_INVALID_FILE_HANDLE)
        {
            *length = 0;
            return index;
        }

        ASSERT(index >= FS_NO_ERROR);

        if (g_drm_handles[index].ro != NULL)
        {
            drm_rights_struct *rights;
            kal_uint32 space = 0, block_size = ((g_drm_cache_size == 0) ? DRM_CRYPTO_WKBUF_SIZE : g_drm_cache_size);
            kal_uint8 *dest;

            DRM_PROTECT
                /* is drm file */
                rights = g_drm_handles[index].info->rights;
            *length = 0;

            /* in case of separate delivery without rights, should not allow to read */
            if (rights->status == DRM_STATUS_RIGHTS_PENDING)
            {
                DRM_MTK_TRACE(("drm_read_file: Rights pending"), (TRACE_GROUP_8, DRM_MTK_FILE_READ_00));
                DRM_UNPROTECT return DRM_RESULT_NO_PERMISSION;
            }

            DRM_TAG("READ", 1);

            dest = buffer;
            if (g_drm_handles[index].cache)
            {
                /* remaining bytes in cache */
                kal_int32 expense = g_drm_handles[index].position - g_drm_handles[index].start;

                DRM_MTK_TRACE(
                    ("drm_read_file: handle = %d, size = %d, offset = %d"),
                    (TRACE_GROUP_8, DRM_MTK_FILE_READ_01, handle, size, expense, 0));

                if (expense >= (kal_int32)block_size || expense < 0)
                {
                    /*
                     * CASE 1: totally miss
                     */
                    DRM_MTK_TRACE(
                        ("drm_read_file: @Cache Total Missed! -%d"),
                        (TRACE_GROUP_8, DRM_MTK_FILE_READ_02, __LINE__));
                }
                else
                {
                    kal_uint32 len = 0;

                    if (g_drm_handles[index].position + size > rights->data_len &&
                        g_drm_handles[index].start + block_size > rights->data_len)
                    {
                        /* 
                         * CASE 2: EOF
                         */
                        size = len = rights->data_len - g_drm_handles[index].position;
                        DRM_MTK_TRACE(("@EOF! -%d"), (TRACE_GROUP_8, DRM_MTK_FILE_READ_03, __LINE__));

                    }
                    else if (g_drm_handles[index].position + size > g_drm_handles[index].start + block_size)
                    {
                        /* 
                         * CASE 3: partially miss
                         */
                        len = block_size - expense;
                        DRM_MTK_TRACE(("@Cache Partial Missed! -%d"), (TRACE_GROUP_8, DRM_MTK_FILE_READ_04, __LINE__));
                    }
                    else
                    {
                        /*
                         * CASE 4: hit
                         */
                        len = size;
                    }

                    memcpy(dest, g_drm_handles[index].cache + expense, len);
                    *length = len;
                    DRM_UPDATE_CACHE_POSITION(index, handle, (g_drm_handles[index].position + len));
                    size -= len;
                    dest += len;
                }
            }

            if (size)
            {
                kal_int32 start_blk, end_blk;   /* the 1st and last block to read this time */
                kal_uint32 req_pos, len_to_copy;
                kal_int32 dec_len;
                STCHE *che_str;
                kal_uint32 is_last_block = KAL_FALSE;
                kal_bool relaod = KAL_FALSE;

                if (g_drm_handles[index].cache == NULL)
                {
                    g_drm_handles[index].cache = (kal_uint8*) drmt_mem_alloc(16 + block_size);
                }

                ASSERT(g_drm_handles[index].cache);

                if (g_drm_handles[index].position == g_drm_handles[index].end)
                {
                    relaod = KAL_TRUE;
                }

                start_blk = g_drm_handles[index].position / block_size;

                if ((g_drm_handles[index].position + size) % block_size == 0)
                {
                    end_blk = (g_drm_handles[index].position + size) / block_size - 1;
                }
                else
                {
                    end_blk = (g_drm_handles[index].position + size) / block_size;
                }

                space = size;   /* memorize current size */

                if (relaod)
                    req_pos = 0;
                else
                    req_pos = (g_drm_handles[index].position - start_blk * block_size);

                /* Checking for last block */
                if (start_blk == end_blk)
                {
                    is_last_block = KAL_TRUE;
                }

                DRM_UPDATE_CACHE_START(index, handle, start_blk * block_size);
                che_str = (STCHE*) drmt_mem_alloc(sizeof(STCHE));

                che_init(che_str, CHE_AES);
                che_key_action(che_str, CHE_SET_KEY, rights->key, rights->key_len);

                dec_len = drm_core_decrypt_block(source, start_blk, g_drm_handles[index].cache, che_str, is_last_block);

                g_drm_handles[index].previous_blk = start_blk;

                g_drm_handles[index].end = g_drm_handles[index].start + dec_len;

                if (rights->data_len && g_drm_handles[index].end > (kal_int32)rights->data_len)
                {
                    g_drm_handles[index].end = rights->data_len;
                    dec_len = g_drm_handles[index].end - g_drm_handles[index].start;
                }

                if (dec_len > 0)
                {
                    /* 
                     * if !ext_seek
                     *  then current_in_block must = 0
                     */

                    len_to_copy = dec_len - req_pos;
                }
                else
                {
                    DRM_MTK_TRACE(("drm_read_file: fail = %d"), (TRACE_GROUP_9, DRM_MTK_FILE_READ_05, dec_len));
                    che_deinit(che_str);
                    drmt_mem_free(che_str);
                    DRM_UNPROTECT return dec_len;
                }

                if (g_drm_handles[index].position == (kal_int32)rights->data_len)
                {
                    DRM_MTK_TRACE(("@EOF! -%d"), (TRACE_GROUP_8, DRM_MTK_FILE_READ_03, __LINE__));
                }
                /*
                 * if (!ext_seek)
                 * {
                 * if (len_over_current > space)
                 * len_over_current = space;
                 * 
                 * memcpy(dest, g_drm_handles[index].cache, len_over_current);
                 * DRM_UPDATE_CACHE_POSITION(index, source, (g_drm_handles[index].start + len_over_current));
                 * 
                 * dest += len_over_current;
                 * space -= len_over_current;                    
                 * }
                 * else
                 * {
                 * if (len_over_current > space)
                 * len_over_current = space;
                 * 
                 * memcpy(dest, (g_drm_handles[index].cache + current_in_block), len_over_current);
                 * DRM_UPDATE_CACHE_POSITION(index, source, (g_drm_handles[index].start + current_in_block + len_over_current));
                 * 
                 * dest += len_over_current;
                 * space -= len_over_current;
                 * }
                 */

                if (len_to_copy > size)
                    len_to_copy = size;

                memcpy(dest, (g_drm_handles[index].cache + req_pos), len_to_copy);
                DRM_UPDATE_CACHE_POSITION(index, handle, (g_drm_handles[index].start + req_pos + len_to_copy));

                dest += len_to_copy;
                size -= len_to_copy;

                /* more than 1 block to decrypt */
                if (size && dec_len == (kal_int32)block_size)  /* prevent from eof */
                {
                    kal_int32 i;
                    
                    for (i = start_blk + 1; i <= end_blk; i++)
                    {
                        if (i == end_blk)
                        {
                            is_last_block = KAL_TRUE;
                        }
                        DRM_UPDATE_CACHE_START(index, handle, i * block_size);
                        dec_len = drm_core_decrypt_block(source, i, g_drm_handles[index].cache, che_str, is_last_block);

                        g_drm_handles[index].previous_blk = i;

                        if (dec_len < 0)
                        {
                            che_deinit(che_str);
                            drmt_mem_free(che_str);
                            DRM_UNPROTECT return DRM_RESULT_INVALID_FORMAT;
                        }

                        g_drm_handles[index].end = g_drm_handles[index].start + dec_len;

                        if (rights->data_len && g_drm_handles[index].end > (kal_int32)rights->data_len)
                        {
                            g_drm_handles[index].end = rights->data_len;
                            dec_len = g_drm_handles[index].end - g_drm_handles[index].start;
                        }

                        if (size < (kal_uint32)dec_len)
                        {
                            dec_len = size;
                        }

                        DRM_UPDATE_CACHE_POSITION(index, handle, (g_drm_handles[index].start + dec_len));
                        memcpy(dest, g_drm_handles[index].cache, dec_len);
                        dest += dec_len;
                        size -= dec_len;

                        if (g_drm_handles[index].end >= (kal_int32)rights->data_len)
                        {
                            break;
                        }
                    }
                }
                che_deinit(che_str);
                drmt_mem_free(che_str);

            }
            DRM_TAG("READ", 0);
            if (result < FS_NO_ERROR)
            {
                *length = 0;
                DRM_MTK_TRACE(("drm_read_file: fail = %d"), (TRACE_GROUP_9, DRM_MTK_FILE_READ_05, result));
                DRM_UNPROTECT return result;
            }
            else
            {
                *length += space - size;
                DRM_UNPROTECT return FS_NO_ERROR;
            }
        }
    }

    result = FS_Read(handle, buffer, size, length);
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  drm_core_seek_large_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source      [IN]        
 *  offset      [IN]        
 *  ref         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int64 drm_core_seek_large_file(FS_HANDLE source, kal_int64 offset, kal_uint8 ref)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_core_is_mtk_handle(source))
    {
        drm_handle_struct *nh = (drm_handle_struct*) drm_core_reverse_file_handle(source);

        source = nh->handle;
        DRM_MTK_TRACE(
            ("drm_seek_file: handle = %d, offset = %d, ref = %d"),
            (TRACE_GROUP_8, DRM_MTK_FILE_SEEK_00, source, offset, ref));

        index = FS_ParseFH(source);

        if (index < FS_NO_ERROR)
        {
            return index;
        }

        if (g_drm_handles[index].ro != NULL)
        {
            kal_int64 pos = 0, size = (kal_int64) g_drm_handles[index].info->rights->data_len;

            if (ref == FS_FILE_BEGIN)
            {
                pos = offset;

            }
            else if (ref == FS_FILE_CURRENT)
            {
                pos = g_drm_handles[index].position + offset;
            }
            else
            {
                pos = size + offset;
            }

            if (pos > size)
                pos = size;
            if (pos < 0)
                pos = 0;

            DRM_UPDATE_CACHE_POSITION(index, source, pos);
            DRM_MTK_TRACE(
                ("drm_seek_file: handle = %d, offset = %d, ref = %d"),
                (TRACE_GROUP_8, DRM_MTK_FILE_SEEK_00, source, pos, ref));

            return pos;
        }
    }
    return FS_SeekLargeFile(source, offset, ref);
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_seek_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source      [IN]        
 *  offset      [IN]        
 *  ref         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_core_seek_file(FS_HANDLE source, kal_int32 offset, kal_uint8 ref)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

   return (kal_int32)drm_core_seek_large_file(source, (kal_int64)offset, ref);
   
   #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
}
/*****************************************************************************
 * FUNCTION
 *  drm_core_set_seek_hint
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source      [IN]        
 *  HintNum     [IN]        
 *  Hint        [?]         [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_core_set_seek_hint(FS_HANDLE source, kal_uint32 HintNum, FS_FileLocationHint *Hint)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_core_is_mtk_handle(source))
    {
        drm_handle_struct *nh = (drm_handle_struct*) drm_core_reverse_file_handle(source);

        source = nh->handle;
    }
    return FS_SetSeekHint(source, HintNum, Hint);
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_file_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source      [IN]        
 *  size        [?]         [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_core_file_size(FS_HANDLE source, kal_uint32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = 0, index;
    STCHE *che_str;
    kal_uint8 buf[DRM_MAX_KEY_LENGTH * 2];
    kal_uint8 *last_bl_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_core_is_mtk_handle(source))
    {
        drm_handle_struct *nh = (drm_handle_struct*) drm_core_reverse_file_handle(source);
        FS_HANDLE tmp_source = source;

        source = nh->handle;

        index = FS_ParseFH(source);

        if (index < FS_NO_ERROR)
        {
            return index;
        }

        if (g_drm_handles[index].ro != NULL)
        {
            drm_rights_struct *rights;
            kal_uint8 embed_iv_len = 0;

            /* is drm file */
            rights = g_drm_handles[index].info->rights;

            if (rights->status != DRM_STATUS_RIGHTS_PENDING)
            {
                if (!(rights->method & DRM_METHOD_SEPARATE_DELIVERY))
                {
                    embed_iv_len = 16;
                }

                if (rights->data_len)
                {
                    *size = rights->data_len;
                }
                else
                {
                    kal_uint32 len, pos;
                    kal_uint8 *buffer;
                    kal_int32 fs_ret;
                    kal_uint8 key[DRM_MAX_KEY_LENGTH];

                    result = FS_GetFileSize(source, size);
                    if (result < FS_NO_ERROR)
                    {
                        return result;
                    }                    
                    
                    buffer = drmt_mem_alloc(sizeof(drm_rights_struct));

                    fs_ret = drm_core_file_pos(tmp_source, &pos);
                    /* calculate padding size */
                    fs_ret = FS_Seek(source, (g_drm_handles[index].dcf_size - 32), FS_FILE_BEGIN);
                    if (g_drm_handles[index].cache)
                    {
                        drmt_mem_free(g_drm_handles[index].cache);
                        g_drm_handles[index].cache = NULL;
                    }

                    /* len = last block size before padding */
                    //fs_ret = drm_core_read_file(tmp_source, buffer, 32, &len);

                    if (fs_ret >= FS_NO_ERROR)
                    {
                        che_str = (STCHE*) drmt_mem_alloc(sizeof(STCHE));
                        che_init(che_str, CHE_AES);
                        che_key_action(che_str, CHE_SET_KEY, rights->key, rights->key_len);

                        fs_ret = FS_Read(source, buf, rights->key_len * 2, &len);
                        if (len >= (kal_uint32)rights->key_len * 2)
                        {
                            che_set_iv(che_str, buf, rights->key_len);
                            last_bl_ptr = buf + rights->key_len;
                            len -= rights->key_len;
                            che_process(che_str, CHE_AES, CHE_CBC, CHE_DEC, last_bl_ptr, last_bl_ptr, len, KAL_FALSE);
                            drm_core_rm_padding(last_bl_ptr, (kal_uint32*) &len);
                        }
                        che_deinit(che_str);
                        drmt_mem_free(che_str);
                    
                        /*
                         * size - (16-len) - offset - iv
                         * = size - (16-len) - offset - 16
                         * = size - 32 - offset + len
                         */
                        *size -= rights->offset;
                        *size -= 32;
                        *size += len;
                        rights->data_len = *size;
                        /* Encrypt ro */
                        memset(buffer, 0, sizeof(drm_rights_struct));
                        drm_core_get_key(key);
                        drm_core_rc4_encrypt_buff(key, 16, buffer, (kal_uint8*) rights, sizeof(drm_rights_struct));

                        FS_Seek(g_drm_handles[index].ro, DRM_MAX_PATH_LENGTH * ENCODING_LENGTH, FS_FILE_BEGIN);
                        FS_Write(g_drm_handles[index].ro, buffer, sizeof(drm_rights_struct), &len);
                        fs_ret = DRM_seek_file(tmp_source, pos, FS_FILE_BEGIN);
                    }
                    drmt_mem_free(buffer);

                    if (fs_ret == DRM_RESULT_NO_PERMISSION)
                    {
                        *size = g_drm_handles[index].dcf_size;
                    }
                    else if (fs_ret < FS_NO_ERROR)
                    {
                        result = fs_ret;
                    }
                    DRM_MTK_TRACE(
                        ("drm_file_size: ret = %d, size = %d, updated = YES"),
                        (TRACE_GROUP_8, DRM_MTK_FILE_SIZE_01, result, *size));
                }
                return result;
            }
        }
    }

    return FS_GetFileSize(source, size);
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_file_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source      [IN]        
 *  pos         [?]         [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_core_file_pos(FS_HANDLE source, kal_uint32 *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result = 0, index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_core_is_mtk_handle(source))
    {
        drm_handle_struct *nh = (drm_handle_struct*) drm_core_reverse_file_handle(source);

        source = nh->handle;

        index = FS_ParseFH(source);

        if (index < FS_NO_ERROR)
        {
            return index;
        }

        if (g_drm_handles[index].ro != NULL)
        {
            *pos = g_drm_handles[index].position;
            result = FS_NO_ERROR;

            DRM_MTK_TRACE(
                ("drm_file_pos: handle = %d, position = %d"),
                (TRACE_GROUP_9, DRM_MTK_FILE_POS, source, *pos));
            return result;
        }
    }

    return FS_GetFilePosition(source, pos);
}

#define MTK_DRM_CONSUME_CONTROL


/*****************************************************************************
 * FUNCTION
 *  drm_core_consume_rights_aux
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ro              [IN]        
 *  rights          [IN]        
 *  permission      [IN]        
 *  count_minus     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool drm_core_consume_rights_aux(
            FS_HANDLE ro,
            drm_rights_struct *rights,
            kal_uint8 permission,
            kal_bool count_minus)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_constraint_struct *constraint;
    kal_bool need_update = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MTK_TRACE(("drm_core_consume_rights_aux, rights= %d, timed? %d"), (TRACE_FUNC, DRM_MTK_RO_CONSUME, permission, count_minus));
    
    if (rights->method == DRM_METHOD_FORWARD_LOCK)
    {
        return 0;
    }

    if (rights->status != DRM_STATUS_RIGHTS_PRESENT || drm_core_check_rights(rights, permission) == KAL_FALSE)
    {
        DRM_MTK_TRACE(("Consume: w/o valid rights"), (TRACE_WARNING, DRM_MTK_RO_CONSUME_FAIL));

    }

    constraint = drm_core_get_constraint_int(rights, permission, KAL_FALSE);
    if (!count_minus &&
        (constraint->type & DRM_CONSTRAINT_COUNT) && constraint->total_count > 0 && constraint->used_count > 0)
    {
        constraint->used_count--;
        DRM_MTK_TRACE(("count: %d -> %d"), (TRACE_FUNC, DRM_MTK_RO_CONSUME_COUNT, constraint->used_count + 1, constraint->used_count));
        need_update = KAL_TRUE;
    }
    if (constraint->type & DRM_CONSTRAINT_INTERVAL && constraint->start_intv == 0)
    {
        /* first use */
        applib_time_struct *time, *inc, *end_dt;
        kal_uint32 ltime;

        time = drmt_mem_alloc(sizeof(applib_time_struct));
        inc = drmt_mem_alloc(sizeof(applib_time_struct));
        end_dt = drmt_mem_alloc(sizeof(applib_time_struct));

        /* start time */
        //applib_dt_get_secure_time(time);
        drm_core_get_stime(time);
        ltime = applib_dt_mytime_2_utc_sec(time, KAL_FALSE);
        constraint->start_intv = ltime;        

        /* end time */
        drm_core_sec_to_mytime(inc, constraint->interval);
        applib_dt_increase_time(time, inc, end_dt);
        if (end_dt->nDay > applib_dt_last_day_of_mon(end_dt->nMonth, end_dt->nYear))
        {
            end_dt->nDay = applib_dt_last_day_of_mon(end_dt->nMonth, end_dt->nYear);
        }
        ltime = applib_dt_mytime_2_utc_sec(end_dt, KAL_FALSE);
        if (ltime >= 0x7FFFFFFF)
        {
            constraint->end_intv = 0x7FFFFFFF;
        }
        else
        {
            constraint->end_intv = ltime;
        }
        DRM_MTK_TRACE(("interval: %d -> %d"), (TRACE_FUNC, DRM_MTK_RO_CONSUME_INTERVAL, constraint->start_intv, constraint->end_intv));
        need_update = KAL_TRUE;
    }

    /* write  */
    if (need_update == KAL_TRUE)
    {
        drm_core_update_constraint(ro, rights, permission);
    }
    return need_update;
}

/*****************************************************************************
 * FUNCTION
 *  drm_core_sec_to_mytime
 * DESCRIPTION
 *  convert sec to mytime by rule of parsing interval
 * PARAMETERS
 *  time            [IN/OUT]        
 *  sec             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
void drm_core_sec_to_mytime(applib_time_struct *time, kal_uint32 sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* year */
    time->nYear = sec / (365 * DT_SEC_PER_DAY);
    sec %= (365 * DT_SEC_PER_DAY);

    /* month */
    time->nMonth= sec / (30 * DT_SEC_PER_DAY);
    sec %= (30 * DT_SEC_PER_DAY);    

    /* day */
    time->nDay = sec / DT_SEC_PER_DAY;
    sec %= DT_SEC_PER_DAY;    

    /* hour */
    time->nHour = sec / DT_SEC_PER_HOUR;
    sec %= DT_SEC_PER_HOUR; 

    /* min */
    time->nMin = sec / DT_SEC_PER_MIN;
    sec %= DT_SEC_PER_MIN; 

    /* sec */
    time->nSec = sec;        
}

/*****************************************************************************
 * FUNCTION
 *  drm_core_consume_rights
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source          [IN]        
 *  permission      [IN]        
 *  count_minus     [IN]        
 *  cons            [?]         
 *  callback(?)     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_core_consume_rights(
            FS_HANDLE source,
            kal_uint8 permission,
            kal_bool count_minus,
            drm_constraint_struct *cons)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 index;
    drm_rights_struct *rights;
    FS_HANDLE ro;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_core_is_mtk_handle(source))
    {
        drm_handle_struct *nh = (drm_handle_struct*) drm_core_reverse_file_handle(source);

        source = nh->handle;

        index = FS_ParseFH(source);

        if (index < FS_NO_ERROR)
        {
            return index;
        }

        ro = g_drm_handles[index].ro;
        if (ro != NULL)
        {
            /* is drm file */
            rights = g_drm_handles[index].info->rights;

            drm_core_consume_rights_aux(ro, rights, permission, count_minus);

        }
    }
    return 1;
}

#define MTK_DRM_CONSUME_CONTROL_CID


/*****************************************************************************
 * FUNCTION
 *  drm_core_consume_rights_by_cid
 * DESCRIPTION
 *  consume DRM rights
 * PARAMETERS
 *  cid             [IN]        
 *  permission      [IN]        
 *  count_minus     [IN]        
 *  cons            [?]         
 *  callback(?)     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 drm_core_consume_rights_by_cid(
            drm_cid_struct *cid,
            kal_uint8 permission,
            kal_bool count_minus,
            drm_constraint_struct *cons)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE ro;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ro = drm_core_open_rights_object(FS_READ_WRITE, cid->id, KAL_FALSE);

    if (ro >= FS_NO_ERROR)
    {
        drm_rights_struct *rights = drmt_mem_alloc(DRM_RIGHTS_SIZE);

        memset(rights, 0x00, DRM_RIGHTS_SIZE);
        if (drm_core_load_rights_dcf(ro, rights) == KAL_TRUE)
        {
            drm_core_consume_rights_aux(ro, rights, permission, count_minus);
			if(!drm_core_check_is_ro_used(ro))
			{
				FS_Close(ro);
			}
            drmt_mem_free(rights->constraint_list);
            drmt_mem_free(rights);
            return 1;
        }
        else
        {
            if(!drm_core_check_is_ro_used(ro))
			{
				FS_Close(ro);
			}
            drmt_mem_free(rights->constraint_list);
            drmt_mem_free(rights);
            return DRM_RESULT_NO_PERMISSION;
        }
    }
    else
    {
        return ro;
    }
}

#define MTK_DRM_CONSUME_CONTROL_DUMMY


/*****************************************************************************
 * FUNCTION
 *  drm_core_stop_consume
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  id(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drm_core_stop_consume(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_get_content_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input       [IN]        
 *  entry       [IN]        [?]         [?]
 *  index(?)        [IN](?)
 *  path        [?](?)(?)
 * RETURNS
 *  
 *****************************************************************************/
drm_proc_enum drm_core_get_content_type(FS_HANDLE input, applib_mime_type_struct **entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 fs_index = FS_NO_ERROR, result = DRM_RESULT_BAD_CONTENT_TYPE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_core_is_mtk_handle(input))
    {
        drm_handle_struct *nh = (drm_handle_struct*) drm_core_reverse_file_handle(input);

        input = nh->handle;

        fs_index = FS_ParseFH(input);

        if (fs_index < FS_NO_ERROR)
        {
            result = fs_index;
			return result;
        }

        if (g_drm_handles[fs_index].ro != NULL)
        {
            applib_mime_type_struct *temp;

            temp = applib_mime_type_look_up(NULL, NULL, 0, g_drm_handles[fs_index].info->rights->mime_type);
            if (!temp)
            {
                result = DRM_RESULT_BAD_CONTENT_TYPE;
            }
            else
            {
                if (entry)
                {
                    *entry = temp;
                }
                result = DRM_RESULT_OK;
            }
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_get_object_method
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input       [IN]        
 *  path        [?](?)(?)
 * RETURNS
 *  
 *****************************************************************************/
kal_uint8 drm_core_get_object_method(FS_HANDLE input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 method = DRM_METHOD_NONE;
    kal_int32 index = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_core_is_mtk_handle(input))
    {
        drm_handle_struct *nh = (drm_handle_struct*) drm_core_reverse_file_handle(input);

        input = nh->handle;

        index = FS_ParseFH(input);

        if (index < FS_NO_ERROR)
        {
            method = DRM_METHOD_NONE;
        }
        else if (g_drm_handles[index].ro != NULL)
        {
            /* is DRM file */
            method = g_drm_handles[index].info->rights->method;
        }
    }

    return method;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_get_rights_issuer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  input       [IN]        
 *  buffer      [?]         [?]         [?]
 *  size        [?]         [?]         [?]
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_core_get_rights_issuer(FS_HANDLE input, kal_char *buffer, kal_uint32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_core_is_mtk_handle(input))
    {
        drm_handle_struct *nh = (drm_handle_struct*) drm_core_reverse_file_handle(input);

        input = nh->handle;

        index = FS_ParseFH(input);

        if (index < FS_NO_ERROR)
        {
            *size = 0;
            return DRM_RESULT_UNKNOWN_ERROR;;
        }

        /* give back the rights issuer size */
        if (buffer == NULL)
        {
            if (g_drm_handles[index].ro != NULL && g_drm_handles[index].info->meta[DRM_META_RIGHTS_ISSUER])
            {
                *size = strlen((char*)g_drm_handles[index].info->meta[DRM_META_RIGHTS_ISSUER]) + 1;
            }
            else
            {
                *size = 0;
            }
            return DRM_RESULT_OK;
        }
        /*
         * if (*size < 0)
         * {
         * ASSERT(0);
         * *size = 0;
         * return DRM_RESULT_TRUNCATED;
         * }
         */
        if (g_drm_handles[index].ro != NULL)
        {
            if (!g_drm_handles[index].info->meta[DRM_META_RIGHTS_ISSUER])
            {
                return DRM_RESULT_NOT_SUPPORT;
            }
            else
            {
                kal_int32 len = strlen((char*)g_drm_handles[index].info->meta[DRM_META_RIGHTS_ISSUER]);

                if (len <= (kal_int32)*size - 1)
                {
                    strcpy((char*)buffer, (char*)g_drm_handles[index].info->meta[DRM_META_RIGHTS_ISSUER]);
                    *size = len + 1;
                    return DRM_RESULT_OK;
                }
                else
                {
                    strncpy((char*)buffer, (char*)g_drm_handles[index].info->meta[DRM_META_RIGHTS_ISSUER], *size - 1);
                    buffer[*size - 1] = 0;
                    return DRM_RESULT_TRUNCATED;
                }
            }
        }

        *size = 0;
        return DRM_RESULT_OK;
    }
    return DRM_RESULT_NON_DRM;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_get_meta_size
 * DESCRIPTION
 *  To get meta data size in DCF
 * PARAMETERS
 *  input       [IN]        File handle of the DCF
 *  meta_id     [IN]        Meta data id to query
 * RETURNS
 *  > 0 : size
 *  DRM_RESULT_DATA_NOT_FOUND: no such meta data
 *  DRM_RESULT_NON_DRM: the given file is not a DRM content
 *  otherwise: File System error code
 *****************************************************************************/
kal_int32 drm_core_get_meta_size(FS_HANDLE input, drm_meta_enum meta_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_int32 index;
    drm_info_struct *info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Check meta id */
    if (meta_id >= DRM_META_01_TOTAL)
    {
        return DRM_RESULT_DATA_NOT_FOUND;
    }

    if (drm_core_is_mtk_handle(input))
    {
        drm_handle_struct *nh = (drm_handle_struct*) drm_core_reverse_file_handle(input);

        input = nh->handle;

        index = FS_ParseFH(input);

        if (index < FS_NO_ERROR)
        {
            return index;;
        }

        info = g_drm_handles[index].info;
        if (info && info->meta[meta_id])
        {

            return strlen(info->meta[meta_id]) + 1;

        }

        return DRM_RESULT_DATA_NOT_FOUND;
    }

    return DRM_RESULT_NON_DRM;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_get_meta_data
 * DESCRIPTION
 *  To get meta data in DCF, in "UTF8" format
 * PARAMETERS
 *  input       [IN]        File handle of the DCF
 *  meta_id     [IN]        Meta data id to query
 *  buffer      [IN]        Buffer to keep meta data
 *  size        [IN]        Will be copied into buffer
 * RETURNS
 *  success: DRM_RESULT_OK
 *  DRM_RESULT_INVALID_PARA: negative error code
 *  DRM_RESULT_DATA_NOT_FOUND: no such meta data
 *  DRM_RESULT_NON_DRM: the given file is not a DRM content
 *  otherwise: File System error code
 *****************************************************************************/
kal_int32 drm_core_get_meta_data(FS_HANDLE input, drm_meta_enum meta_id, kal_char *buffer, kal_int32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 index = 0;
    drm_info_struct *info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!size || !buffer || meta_id >= DRM_META_01_TOTAL)
    {
        return DRM_RESULT_INVALID_PARA;
    }

    if (drm_core_is_mtk_handle(input))
    {
        drm_handle_struct *nh = (drm_handle_struct*) drm_core_reverse_file_handle(input);

        input = nh->handle;

        index = FS_ParseFH(input);

        if (index < FS_NO_ERROR)
        {
            return index;;
        }

        info = g_drm_handles[index].info;
        if (info && info->meta[meta_id])
        {
            memset(buffer,0, size);
            memcpy(buffer, info->meta[meta_id], size - 1);
            return DRM_RESULT_OK;
        }
        return DRM_RESULT_DATA_NOT_FOUND;
    }

    return DRM_RESULT_NON_DRM;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_validate_permission
 * DESCRIPTION
 * PARAMETERS
 *  input           [IN]        
 *  permission      [IN]        
 * RETURNS
 *****************************************************************************/
kal_bool drm_core_validate_permission(FS_HANDLE input, kal_uint8 permission)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_rights_struct *rights;
    kal_bool result = KAL_FALSE;
    kal_int32 index = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_core_is_mtk_handle(input))
    {
        drm_handle_struct *nh = (drm_handle_struct*) drm_core_reverse_file_handle(input);

        input = nh->handle;

        index = FS_ParseFH(input);

        if (index < FS_NO_ERROR)
        {
            return result;
        }

        rights = g_drm_handles[index].info->rights;

        if (rights != NULL)
        {
            result = drm_core_check_rights(rights, permission);			
			if( (rights->method == DRM_METHOD_FORWARD_LOCK) && 
				!(drm_core_varify_fl_signature(&g_drm_handles[index].info->meta[DRM_META_CONTENTURI][11], input, rights->data_len, rights->offset) ) )
			{
				result = KAL_FALSE;
			}
        }
        else    /* non DRM file, always allow to use */
        {
            result = KAL_TRUE;
        }
        return result;
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_validate_timed_permission
 * DESCRIPTION
 * PARAMETERS
 *  input           [IN]        
 *  permission      [IN]        
 * RETURNS
 *****************************************************************************/
kal_bool drm_core_validate_timed_permission(FS_HANDLE input, kal_uint8 permission)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_rights_struct *rights;
    kal_bool result = KAL_FALSE;
    kal_int32 index = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_core_is_mtk_handle(input))
    {
        drm_handle_struct *nh = (drm_handle_struct*) drm_core_reverse_file_handle(input);

        input = nh->handle;

        index = FS_ParseFH(input);

        if (index < FS_NO_ERROR)
        {
            return result;
        }

        rights = g_drm_handles[index].info->rights;

        if (rights != NULL)
        {
            kal_uint8 status = drm_core_check_rights_aux(rights, permission, DRM_CHK_FLT_TIME_ONLY);

            if (status == DRM_STATUS_RIGHTS_PRESENT)
            {
                result = KAL_TRUE;
            }
            else
            {
                result = KAL_FALSE;
            }
            
        }
        else    /* non DRM file, always allow to use */
        {
            result = KAL_TRUE;
        }

        return result;
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_validate_future_permission
 * DESCRIPTION
 * PARAMETERS
 *  input           [IN]        
 *  permission      [IN]        
 * RETURNS
 *****************************************************************************/
kal_bool drm_core_validate_future_permission(FS_HANDLE input, kal_uint8 permission)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_rights_struct *rights;
    kal_bool result = KAL_FALSE;
    kal_int32 index = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_core_is_mtk_handle(input))
    {
        drm_handle_struct *nh = (drm_handle_struct*) drm_core_reverse_file_handle(input);

        input = nh->handle;

        index = FS_ParseFH(input);

        if (index < FS_NO_ERROR)
        {
            return result;
        }

        rights = g_drm_handles[index].info->rights;

        if (rights != NULL)
        {
            kal_uint8 status = drm_core_check_rights_aux(rights, permission, DRM_CHK_FLT_FUTURE);

            if (status == DRM_STATUS_RIGHTS_PRESENT || status == DRM_STATUS_RIGHTS_IN_FUTURE)
            {
                result = KAL_TRUE;
            }
            else
            {
                result = KAL_FALSE;
            }
            
        }
        else    /* non DRM file, always allow to use */
        {
            result = KAL_TRUE;
        }

        return result;
    }
    return KAL_TRUE;
}



#define MTK_DRM_VALIDATE_CID


/*****************************************************************************
 * FUNCTION
 *  drm_core_validate_permission_by_cid
 * DESCRIPTION
 * PARAMETERS
 *  cid             [?]         
 *  permission      [IN]        
 *  time_only       [IN]        
 *  input(?)        [IN]        
 * RETURNS
 *****************************************************************************/
kal_bool drm_core_validate_permission_by_cid(drm_cid_struct *cid, kal_uint8 permission, kal_bool time_only)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE ro;
    kal_bool result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ro = drm_core_open_rights_object(FS_READ_WRITE, cid->id, KAL_FALSE);

    if (ro >= FS_NO_ERROR)
    {
        drm_rights_struct *rights = drmt_mem_alloc(DRM_RIGHTS_SIZE);

        if (drm_core_load_rights_dcf(ro, rights) == KAL_TRUE)
        {
            result = drm_core_check_rights_aux(rights, permission, (kal_uint8)(time_only?DRM_CHK_FLT_TIME_ONLY:DRM_CHK_FLT_NONE));
            drmt_mem_free(rights->constraint_list);
            drmt_mem_free(rights);
			if(!drm_core_check_is_ro_used(ro))
			{
				FS_Close(ro);
			}

            if (result == DRM_STATUS_NO_RIGHTS || result == DRM_STATUS_RIGHTS_IN_FUTURE)
            {
                return KAL_FALSE;
            }
            else
            {
                return KAL_TRUE;
            }
        }
        drmt_mem_free(rights->constraint_list);
        drmt_mem_free(rights);
		if(!drm_core_check_is_ro_used(ro))
		{
			FS_Close(ro);
		}

    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_delete_ro_by_seed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  seed            [IN]        
 *  seed_len        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_core_delete_ro_by_seed(kal_uint8 *seed, kal_int32 seed_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *content_id;
    kal_wchar *ro_path;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    content_id = (kal_char*) drmt_mem_alloc(DRM_MAX_ID_LENGTH);
    ro_path = (kal_wchar*) drmt_mem_alloc(DRM_MAX_PATH_LENGTH << 1);
    drm_core_gen_cid(content_id, (kal_char*) seed, seed_len);

    if (strncmp(content_id, "MTK_FL_cid", 10) == 0 || strncmp(content_id, "MTK_CD_cid", 10) == 0)
    {
        drm_parse_hash((kal_uint8*) & content_id[11], 0, (kal_char*) ro_path, KAL_TRUE);
    }
    else
    {
        drm_parse_hash((kal_uint8*) & content_id[4], 0, (kal_char*) ro_path, KAL_TRUE);
    }

    result = FS_Delete(ro_path);

    drmt_mem_free(ro_path);
    drmt_mem_free(content_id);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_interdev_movable
 * DESCRIPTION
 *  
 * PARAMETERS
 *  handle      [IN]        
 *  path        [?](?)(?)
 * RETURNS
 *  
 *****************************************************************************/
kal_bool drm_core_interdev_movable(FS_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 method = drm_core_get_object_method(handle);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (method)
    {
        case DRM_METHOD_FORWARD_LOCK:
        case DRM_METHOD_COMBINED_DELIVERY:
            return KAL_FALSE;
        case DRM_METHOD_SEPARATE_DELIVERY:
            return KAL_TRUE;
        default:
        {
            if (method & DRM_METHOD_FORWARD_LOCK)   /* FL + DCF */
            {
                return KAL_FALSE;
            }
            return KAL_TRUE;
        }
    }

}


#define MTK_DRM_OP_BY_REF


/*****************************************************************************
 * FUNCTION
 *  drm_core_get_object_method_by_ref
 * DESCRIPTION
 *  get DRM method of a DRM content
 * PARAMETERS
 *  ro_index        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 drm_core_get_object_method_by_ref(kal_int32 ro_index, drm_proc_db_ro_count_flag_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 method = DRM_METHOD_NONE;
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_drm_cntx->ro_index = ro_index;

    if(flag == DRM_DB_GET_VALID)
    {
    ret = drm_core_search_db(0xFF, ro_index, &g_drm_cntx->rights, NULL, NULL, NULL, (DRM_DB_GET | DRM_DB_VALID));
    }
	else if(flag == DRM_DB_GET_ALL)
	{
		ret = drm_core_search_db(0xFF, ro_index, &g_drm_cntx->rights, NULL, NULL, NULL,
			                     (DRM_DB_VALID | DRM_DB_INVALID | DRM_DB_HIDDEN));
	}
	else
	{
         ret = DRM_RESULT_INVALID;
	}
    if (ret == DRM_RESULT_OK)
        method = g_drm_cntx->rights.method;
    else
        method = DRM_METHOD_NONE;

    return method;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_get_constraint_by_ref
 * DESCRIPTION
 *  Get constraint by ref, only used by RMGR
 * PARAMETERS
 *  ro_index        [IN]        
 *  permission      [IN]        
 *  cons            [OUT]       
 * RETURNS
 *****************************************************************************/
kal_int32 drm_core_get_constraint_by_ref(kal_int32 ro_index, kal_uint8 permission, drm_constraint_struct *cons)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_constraint_struct *tmp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(ro_index == g_drm_cntx->ro_index);
    tmp = drm_core_get_constraint_int(&g_drm_cntx->rights, permission, KAL_FALSE);


    if (tmp)
    {
        tmp->status = (kal_int32)drm_core_check_rights_aux(&g_drm_cntx->rights, permission, DRM_CHK_FLT_NONE);
        memcpy(cons, tmp, DRM_CONSTRAINT_SIZE);
        return DRM_RESULT_OK;
    }
    else /* check if there's <in future> constraint */
    {
        tmp = drm_core_get_constraint_int(&g_drm_cntx->rights, permission, KAL_TRUE);    
        if (tmp)
        {
            tmp->status = (kal_int32)drm_core_check_rights_aux(&g_drm_cntx->rights, permission, DRM_CHK_FLT_DL_ONLY);
            memcpy(cons, tmp, DRM_CONSTRAINT_SIZE);
            return DRM_RESULT_OK;
        }
    }
    return DRM_RESULT_NO_PERMISSION;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_free_ro_detail
 * DESCRIPTION
 *  To free rights objects detail
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void drm_core_free_ro_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_drm_cntx->ro_index = 0;
    drmt_mem_free(g_drm_cntx->rights.constraint_list);
    memset(&g_drm_cntx->rights, 0x00, DRM_RIGHTS_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_get_constraint_int
 * DESCRIPTION
 *  get constraint in rights object with specific permission
 * PARAMETERS
 *  rights          [IN]        
 *  permission      [IN]        
 *  is_download     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
drm_constraint_struct *drm_core_get_constraint_int(drm_rights_struct *rights, kal_uint8 permission, kal_bool is_download)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 best_index;
    drm_constraint_entry_struct* cons_entry;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rights->permission == DRM_PERMISSION_ALL)
    {
        best_index = 0;
    }
    else if (rights->permission == DRM_PERMISSION_NONE)
    {
        return NULL;
    }

    if (permission & DRM_PERMISSION_EXECUTE)
    {
        best_index = rights->best[DRM_CONSTRAINT_EXECUTE_INDEX];
    }
    else if (permission & DRM_PERMISSION_DISPLAY)
    {
        best_index = rights->best[DRM_CONSTRAINT_DISPLAY_INDEX];
    }
	else if (permission & DRM_PERMISSION_PRINT)
    {
        best_index = rights->best[DRM_CONSTRAINT_PRINT_INDEX];
    }
    else if (permission & DRM_PERMISSION_PLAY)
    {
        best_index = rights->best[DRM_CONSTRAINT_PLAY_INDEX];
    }
    else if (permission & DRM_PERMISSION_EXPORT)
    {
        /* TODO */
        return NULL;
    }
    else
    {
        return NULL;
    }

    DRM_MTK_TRACE(("get constraint: best_index = %d, is_download = %d"), (TRACE_INFO, DRM_MTK_CONS_GET_CONSTRAINT, best_index, is_download));
    cons_entry = &rights->constraint_list[best_index];

    if (best_index == 0xFF || !drmt_mem_valid((kal_uint32)cons_entry))
    {
        return NULL;
    }

    if (is_download == KAL_FALSE) /* install rigths need not filter <in future> rights */
    {        
        while (drm_core_is_constraint_valid(&(cons_entry->cons), KAL_FALSE) == DRM_STATUS_RIGHTS_IN_FUTURE)
        {
            DRM_MTK_TRACE(("get in future constraint, next is %d"), (TRACE_INFO, DRM_MTK_CONS_GET_IN_FUTURE_CONS, cons_entry->next));
            if (cons_entry->next != 0xFF)
            {
                cons_entry = &rights->constraint_list[cons_entry->next];
            }
            else
            {
                cons_entry = NULL;
                break;
            }        
        }
    }   

    if (best_index == 0xFF || (is_download == KAL_FALSE && cons_entry == NULL))
    {
        return NULL;
    }
    else
    {
        return &(cons_entry->cons);
    }
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_get_constraint
 * DESCRIPTION
 *  get constraint in rights object with specific permission
 * PARAMETERS
 *  handle          [IN]        
 *  permission      [IN]        
 *  cons            [?]         [?]         [?]
 *  path            [?](?)(?)
 *  rights(?)       [IN](?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 drm_core_get_constraint(FS_HANDLE handle, kal_uint8 permission, drm_constraint_struct *cons)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 index = FS_NO_ERROR, result = DRM_RESULT_NON_DRM;
    drm_rights_struct* rights;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_core_is_mtk_handle(handle))
    {
        drm_handle_struct *nh = (drm_handle_struct*) drm_core_reverse_file_handle(handle);

        handle = nh->handle;

        index = FS_ParseFH(handle);

        if (index >= FS_NO_ERROR && g_drm_handles[index].ro != NULL)
        {
            if (drm_core_check_rights(g_drm_handles[index].info->rights, permission))
            {
                drm_constraint_struct *tmp = drm_core_get_constraint_int(g_drm_handles[index].info->rights, permission, KAL_FALSE);
                if (tmp)
                {
                    tmp->status = DRM_STATUS_RIGHTS_PRESENT;
                    memcpy(cons, tmp, sizeof(drm_constraint_struct));
                    result = DRM_RESULT_OK;
                }
                else
                {                    
                    rights = g_drm_handles[index].info->rights;
                    if (rights->method == DRM_METHOD_FORWARD_LOCK && 
                        drm_core_varify_fl_signature(&g_drm_handles[index].info->meta[DRM_META_CONTENTURI][11], handle, rights->data_len, rights->offset))
                    {
                        cons->status= DRM_STATUS_RIGHTS_PRESENT;
                        cons->type= DRM_CONSTRAINT_NONE;
                        result = DRM_STATUS_RIGHTS_PRESENT;
                    }
                    else
                    {
                        cons->status = DRM_STATUS_NO_RIGHTS;
                        result = DRM_RESULT_NON_DRM;
                    }
                }         
            }
            else
            {
                cons->status = DRM_STATUS_NO_RIGHTS;
                result = DRM_RESULT_NON_DRM;
            }            
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_update_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time            [?]         [?]         [?]
 *  reliable        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drm_core_update_time(void *time, kal_bool reliable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_traslate_file_handle
 * DESCRIPTION
 *  for virtual memory that will make drm address as negative value,
 *  we invert the address value
 * PARAMETERS
 *  fh      [IN]        [?]
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
FS_HANDLE drm_core_traslate_file_handle(FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fh < 0)
    {
        return ~(fh);
    }
    else
    {
        return fh;
    }
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_reverse_file_handle
 * DESCRIPTION
 *  for the inverted value of drm_core_traslate_file_handle,
 *  reverse to original value
 * PARAMETERS
 *  fh      [IN]        [?]
 * RETURNS
 *  FS_HANDLE
 *****************************************************************************/
FS_HANDLE drm_core_reverse_file_handle(FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((kal_int32) & g_drm_handles[0] < 0)
    {
        return ~(fh);
    }
    else
    {
        return fh;
    }
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  drm_core_activate_file
 * DESCRIPTION
 * PARAMETERS
 *  file_path       [?]         [?]         [?]         [?]
 *  serial          [?]         [?]         [?]         [?]
 *  callback        [IN]        
 *  handle(?)       [IN](?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 drm_core_activate_file(kal_wchar *file_path, kal_uint8 *serial, drm_general_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DRM_RESULT_NOT_SUPPORT;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_predict_encoded_size
 * DESCRIPTION
 *  predict dcf size before encoding
 * PARAMETERS
 *  src_path        [?]         
 *  callback(?)     [IN]        
 *  file_path       [?]         [?]         [?](?)
 *  serial          [?]         [?]         [?](?)
 *  handle(?)       [IN](?)(?)(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 drm_core_predict_encoded_size(kal_wchar *src_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE input;
    kal_int32 obj_type;
    kal_int32 result = DRM_RESULT_NON_DRM;
    kal_uint8 encoding;
    drm_info_struct *info = NULL;
    drm_rights_struct *rights = NULL;
    kal_char *cid;
    kal_char *ptr;
    kal_uint32 sd_pos;
    kal_char buffer[10];
    kal_uint32 length = 0, header_pos = 0, header_length, data_length, temp = 0, dcf_flag = KAL_FALSE, dcf_fl_ver = 0;
    kal_uint32 read_p = 0, write_p = 0;
    kal_int32 size, len = 0;
    kal_char *line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rights = (drm_rights_struct*) drmt_mem_alloc(DRM_RIGHTS_SIZE);
    memset(rights, 0, DRM_RIGHTS_SIZE);

    cid = (kal_char*) drmt_mem_alloc(DRM_MAX_CID_URL_LENGTH);
    memset(cid, 0, DRM_MAX_CID_URL_LENGTH);

    rights->constraint_list =
        (drm_constraint_entry_struct*) drmt_mem_alloc(DRM_CONSTRAINT_ENTRY_SIZE * DRM_CONSTRAINT_TOTAL_INDEX);
    memset(rights->constraint_list, 0, DRM_CONSTRAINT_ENTRY_SIZE * DRM_CONSTRAINT_TOTAL_INDEX);

    input = FS_OpenHint(src_path, FS_READ_ONLY, DRM_get_open_hint(src_path));
    if (input < FS_NO_ERROR)
    {
        DRM_MTK_TRACE(("FS_Open = %d"), (TRACE_INFO, DRM_MTK_OPEN_FILE, input));
        DRM_RESULT(result, input, final);
    }

    obj_type = drm_parse_method(input);

    if (obj_type == MIME_SUBTYPE_DRM_RIGHTS_XML)
    {
        DRM_MTK_TRACE(("CD Obj"), (TRACE_INFO, DRM_MTK_OBJ_CD));

        rights->method = DRM_METHOD_COMBINED_DELIVERY;

        /* parse rights */
        result = drm_parse_rights(input, rights, cid, DRM_TYPE_COMBINED_DELIVERY);
        if (result != DRM_RESULT_OK)
        {
            DRM_RESULT(result, result, final);
        }
    }
    else
    {
        DRM_MTK_TRACE(("FL Obj"), (TRACE_INFO, DRM_MTK_OBJ_FL));

        /* rights not present => forward lock */
        rights->method = DRM_METHOD_FORWARD_LOCK;
    }

    /* parse content */
    result = drm_parse_content(input, rights, &encoding, NULL);
    if (result != DRM_RESULT_OK)
    {
        DRM_RESULT(result, result, final);
    }

    if (encoding == DRM_ENCODING_BASE64)
    {
        /* drm_parse_base64(input, rights); */
        line = get_ctrl_buffer(DRM_MAX_LINE_LENGTH);
        FS_Seek(input, rights->offset, FS_FILE_BEGIN);

        while (read_p < rights->data_len)
        {
            kal_uint32 half = 0;

            size = drm_get_line(line, DRM_MAX_LINE_LENGTH - 3, input);
            if (size < FS_NO_ERROR)
            {
                free_ctrl_buffer(line);
                DRM_RESULT(result, size, final);
            }

            line[size++] = 0x0d;
            if (line[size] != 0x0a)
                half = 1;
            line[size++] = 0x0a;
            line[size] = 0;

            len = applib_base64_decode(line, size, line, size);

            if (rights->mime_type != MIME_SUBTYPE_DRM_CONTENT)
            {
                read_p += size - half;    
                write_p += len;
            }
            else
            {
                if (read_p == 0) /* first block of dcf */
                {                
                    header_pos = 3 + line[1] + line[2];
                    dcf_fl_ver = header_pos + 10; /*MTK_FLDCF_cid*/                     
                    ptr = (line + 3 + line[1]);                    
                    if ((strstr(ptr, "http://") != NULL) || (ptr = strstr(ptr, "HTTP://")) != NULL)
                    {
                        dcf_fl_ver -= 7;
                    }                    
                }            
                read_p += size - half;    
                write_p += len;

                if (header_pos > 0)
                {
                    if (header_pos > write_p)
                    {
                        header_pos -= write_p;
                    }
                    else
                    {
                        memcpy (buffer, line + header_pos, 10);
                        //buffer = line + (size - (read_p - header_pos));
                        temp = drm_parse_uintvar(buffer, &header_length, 10); /* header length */
                        temp += drm_parse_uintvar(&buffer[temp], &data_length, 10 - temp); /* data length */
                        temp += header_length + data_length;
                        header_pos = 0 ;
                    }
                }
            }
		    
            FS_Seek(input, rights->offset + read_p, FS_FILE_BEGIN);
        }
        rights->data_len = write_p;
        free_ctrl_buffer(line);
    }

    /* if content id wasn't initiated */
    if (rights->method == DRM_METHOD_FORWARD_LOCK)
    {
        if (rights->mime_type == MIME_SUBTYPE_DRM_CONTENT)
        {
            info = (drm_info_struct*) drmt_mem_alloc(sizeof(drm_info_struct));
            memset(info, 0, sizeof(drm_info_struct));
            info->rights = rights;

            info->meta[DRM_META_CONTENTURI] = (kal_char*) drmt_mem_alloc(DRM_MAX_CID_URL_LENGTH);
            memset(info->meta[DRM_META_CONTENTURI], 0, DRM_MAX_CID_URL_LENGTH);

            info->content_path = (kal_wchar*) drmt_mem_alloc(DRM_MAX_PATH_LENGTH * ENCODING_LENGTH);
            memset(info->content_path, 0, DRM_MAX_PATH_LENGTH * ENCODING_LENGTH);
            app_ucs2_strncpy((kal_int8*) info->content_path, (kal_int8*) src_path, kal_wstrlen(src_path));

            FS_GetFilePosition(input, &sd_pos);

            if (encoding != DRM_ENCODING_BASE64)
            {
                result = drm_parse_dcf(input, info);
                if (result != DRM_RESULT_OK)
                {
                    DRM_RESULT(result, result, final);
                }                
	            strcpy(cid, "MTK_FLDCF_cid:");
	            /* the cid has been encrypted, check if the size is the same as plaintext */
	            strcat(cid, &(info->meta[DRM_META_CONTENTURI][4]));
            }            
            dcf_flag = KAL_TRUE;
        }
        else
        {
            strcpy(cid, "MTK_FL_cid:");            
        }
    }
    else
    {
        strcpy(cid, "MTK_CD_cid:");
        drm_core_gen_cid(cid, NULL, 0);
    }

    /* calculate size */
    /* mine type */
    if (rights->mime_type == MIME_SUBTYPE_DRM_CONTENT && encoding == DRM_ENCODING_BASE64)
    {
        result += dcf_fl_ver;
    }
    else
    {
        result = 3;
        ptr = (char*)int_to_mime(rights->mime_type);
        if (!ptr)
        {
            result += 0;
        }        
        else
        {
            result += strlen(ptr);
        }
    }

    /* cid */
    result += strlen(cid);

    /* FL signature + header */
    if (rights->method == DRM_METHOD_FORWARD_LOCK)
    {
        result += (DRM_FL_SIGNATURE_LEN + DRM_DCF_FL_FIXED_HEADER_SIZE);
    }
    else if (rights->method == DRM_METHOD_COMBINED_DELIVERY)
    {
        result += DRM_DCF_CD_FIXED_HEADER_SIZE;

    }

    /* DCF in FL */
    if (dcf_flag == KAL_TRUE)
    {
        if (encoding != DRM_ENCODING_BASE64)
        {
            FS_Seek(input, sd_pos, FS_FILE_BEGIN);
            FS_Read(input, buffer, 10, &length);
            header_pos = sd_pos + 3 + buffer[1] + buffer[2];    /* content type + content rul */

            FS_Seek(input, header_pos, FS_FILE_BEGIN);  /* Start of DCF header */
            FS_Read(input, buffer, 10, &length);
            temp = drm_parse_uintvar(buffer, &header_length, length);       /* header length */
            temp += drm_parse_uintvar(&buffer[temp], &data_length, length - temp);  /* data length */
            temp += header_length + data_length;
        } 
        result += temp;
    }
    else
    {
        if ((rights->data_len) % 16 == 0)
        {
            result += rights->data_len;
        }
        else
        {
            result += ((rights->data_len / 16 + 1) * 16);
        }

        /* iv */
        result += 16;
    }

  final:

    /* release drm_info_struct */
    drmt_mem_free(rights->constraint_list);
    rights->constraint_list = NULL;
    drmt_mem_free(rights);
    drmt_mem_free(cid);
    FS_Close(input);
    return result;
}
#endif /* __DRM_MTK__ */ /* __DRM_DRM__ */

