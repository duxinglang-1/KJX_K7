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
 * drm_proc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for DRM service, internal use.
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
 *******************************************************************************/
#ifdef __DRM_MTK__
#include <stdio.h>
#include <string.h>

#include "fs_type.h"
#include "app_mine.h"

#include "drm_prot.h"
#include "drm_def.h"
#include "drm_gprot.h"
#include "drm_core_prot.h"
#include "drm_main.h"
#include "drm_util.h"
#include "drm_memory.h"
#include "drm_trace.h"

#include "app_datetime.h"
#include "app_str.h"
#include "custom_mmi_default_value.h"
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

#include "che_api.h"

#include "kal_general_types.h"
#include "drm_core_def.h"
#include "kal_public_api.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "drm_errcode.h"
#include "kal_trace.h"
#include "custom_em.h"
#include "nvram_interface.h"
#include "app_datetime.h"

/*
 * extern variable
 */
extern kal_uint8 current_serial;

extern drm_handle_struct g_drm_handles[];
extern kal_uint32 g_drm_cache_size;
extern drm_core_is_mtk_handle(FS_HANDLE handle);
extern drm_cntx_struct *g_drm_cntx;

/*
 * External functions
 */

extern kal_bool nvram_get_imei_value(kal_uint8 length, kal_uint8 *imei_buf, kal_uint16 rec_index);
extern kal_bool drm_core_get_stime(applib_time_struct *time);
/*
 * Local variables
 */

static kal_char db_version[] = "__DRM_MTK__.__DRM_V01__.0912";
static kal_char verno_str[sizeof(db_version) + DRM_MAX_KEY_LENGTH + 1];
static kal_char *imei_string;

/*****************************************************************************
 * FUNCTION
 *  drm_core_release_verno
 * DESCRIPTION
 *  To provide 
 * PARAMETERS
 *  void
 * RETURNS
 *  string consists of drm version&IMEI
 *****************************************************************************/
kal_char *drm_core_release_verno(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_sprintf(verno_str, "%s", db_version);
    
    verno_str[strlen(db_version)] = '.';

    imei_string = verno_str + sizeof(db_version);
    
    drm_core_get_key(NULL);
    
    return verno_str;
}



/*****************************************************************************
 * FUNCTION
 *  drm_core_release_info
 * DESCRIPTION
 *  get rights object of a DRM content
 * PARAMETERS
 *  info            [?]         
 *  input(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drm_core_release_info(drm_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (info)
    {
        if (drmt_mem_valid((kal_uint32) info->rights))
        {
            if (drmt_mem_valid((kal_uint32) info->rights->constraint_list))
            {
                drmt_mem_free(info->rights->constraint_list);
                info->rights->constraint_list = NULL;
            }
            drmt_mem_free(info->rights);
        }

        if (drmt_mem_valid((kal_uint32) info->content_path))
        {
            drmt_mem_free(info->content_path);
        }

        for (i = 0; i < DRM_META_01_TOTAL; i++)
        {
            if (drmt_mem_valid((kal_uint32) info->meta[i]))
            {
                drmt_mem_free(info->meta[i]);
            }
        }

        if (drmt_mem_valid((kal_uint32) info))
        {
            memset(info, 0, sizeof(drm_info_struct));
            drmt_mem_free(info);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_get_rights
 * DESCRIPTION
 *  get rights object of a DRM content
 * PARAMETERS
 *  input       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
drm_rights_struct *drm_core_get_rights(FS_HANDLE input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drm_handle_struct *nh = (drm_handle_struct*) drm_core_reverse_file_handle(input);

    if (drm_core_is_mtk_handle(input))
    {
        input = nh->handle;

        index = FS_ParseFH(input);

        if (index >= FS_NO_ERROR && g_drm_handles[index].ro != 0)
        {
            /* is DRM file */
            return g_drm_handles[index].info->rights;
        }

    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_add_object
 * DESCRIPTION
 *  parse DRM content and populate rights information
 * PARAMETERS
 *  type            [IN]        
 *  file_path       [IN]        
 *  new_path        [OUT]       
 *  offset          [IN]        
 *  len             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
drm_proc_enum drm_core_add_object(
                kal_uint8 serial,
                drm_object_type_enum type,
                kal_wchar *file_path,
                kal_wchar *new_path,
                kal_uint32 *offset,
                kal_uint32 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE input, ro = 0;
    drm_info_struct *info;
    drm_rights_struct *rights;
    drm_proc_enum result = DRM_RESULT_OK;
    kal_uint32 fs_options = 0;
    kal_int32 ro_ret = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == DRM_TYPE_SEPARATE_DELIVERY_CONTENT)
    {
        /* no need to modify original file */
        fs_options = FS_READ_ONLY;
    }
    else if (offset != NULL)
    {
        /*
         * direct file; must be a virtual file
         * that means the calling appliction provide a multi-part
         * file and DRM engine must process from the given offset
         */
        fs_options = FS_READ_ONLY;
    }
    else
    {
        /* normal file, comparing with direct file */
        fs_options = FS_READ_WRITE;
    }

    input = FS_OpenHint(file_path, fs_options, DRM_get_open_hint(file_path));

    if (input < FS_NO_ERROR)
    {
        DRM_MTK_TRACE(("FS_Open = %d"), (TRACE_INFO, DRM_MTK_OPEN_FILE, input));
        return input;
    }
    info = (drm_info_struct*) drmt_mem_alloc(sizeof(drm_info_struct));
    memset(info, 0, sizeof(drm_info_struct));

    rights = info->rights = (drm_rights_struct*) drmt_mem_alloc(DRM_RIGHTS_SIZE);
    memset(rights, 0, DRM_RIGHTS_SIZE);

    rights->constraint_list =
        (drm_constraint_entry_struct*) drmt_mem_alloc(DRM_CONSTRAINT_ENTRY_SIZE * DRM_CONSTRAINT_TOTAL_INDEX);
    memset(rights->constraint_list, 0, DRM_CONSTRAINT_ENTRY_SIZE * DRM_CONSTRAINT_TOTAL_INDEX);

    info->content_path = (kal_wchar*) drmt_mem_alloc(DRM_MAX_PATH_LENGTH * ENCODING_LENGTH);
    memset(info->content_path, 0, DRM_MAX_PATH_LENGTH * ENCODING_LENGTH);
    app_ucs2_strcpy((kal_int8*) info->content_path, (kal_int8*) file_path);

    info->meta[DRM_META_CONTENTURI] = (kal_char*) drmt_mem_alloc(DRM_MAX_CID_URL_LENGTH);
    memset(info->meta[DRM_META_CONTENTURI], 0, DRM_MAX_CID_URL_LENGTH);

    switch (type)
    {
        case DRM_TYPE_SEPARATE_DELIVERY_RIGHTS:
        case DRM_TYPE_SEPARATE_DELIVERY_RIGHTS_WB:
        {
            drm_rights_status_enum status;

            DRM_MTK_TRACE(("RO Obj"), (TRACE_INFO, DRM_MTK_ADD_OBJ_RO));

            rights->method = DRM_METHOD_SEPARATE_DELIVERY;
            rights->status = DRM_STATUS_CONTENT_PENDING;
            rights->best[0] = rights->best[1] = rights->best[2] = rights->best[3] = 0xFF;

            if (type == DRM_TYPE_SEPARATE_DELIVERY_RIGHTS)
            {
                result = drm_parse_rights(input, rights, info->meta[DRM_META_CONTENTURI], DRM_TYPE_SEPARATE_DELIVERY_RIGHTS);
            }
            else
            {
                result = drm_parse_wb_rights(input, rights, info->meta[DRM_META_CONTENTURI]);
            }

            if (result != DRM_RESULT_OK)
            {
                FS_Close(input);
                break;
            }
            status = drm_core_check_rights_aux(rights, rights->permission, DRM_CHK_FLT_DL_ONLY);
            if (status == DRM_STATUS_RIGHTS_PRESENT || status == DRM_STATUS_RIGHTS_IN_FUTURE)
            {
                ro = drm_core_open_rights_object(FS_READ_WRITE, info->meta[DRM_META_CONTENTURI], KAL_FALSE);
                if (ro >= FS_NO_ERROR)
                {
                    /* rights present */
                    kal_bool allow;

                    /* merge rights for content awaiting rights */
                    allow = drm_core_load_rights_ro(ro, rights);
                    if (allow == KAL_FALSE)
                    {
                        FS_Close(input);
						if(!drm_core_check_is_ro_used(ro))
						{
							FS_Close(ro);
						}
                        result = DRM_RESULT_FILE_EXISTS;
                        break;
                    }
                }
                else
                {
                    /* rights arrive first */
                    ro = drm_core_open_rights_object(
                            (FS_READ_WRITE | FS_CREATE_ALWAYS),
                            info->meta[DRM_META_CONTENTURI], KAL_FALSE);
                    ro_ret = drm_core_create_rights_object(ro, rights, info->content_path);
                }


				if(!drm_core_check_is_ro_used(ro))
				{
					FS_Close(ro);
				}

                if (ro_ret == FS_NO_ERROR)
                {
                    result = DRM_RESULT_OK;
                }
                else
                {
                    result = ro_ret;
                }
            }
            else
            {
                FS_Close(input);
				if(!drm_core_check_is_ro_used(ro))
				{
					FS_Close(ro);
				}
                result = DRM_RESULT_INVALID_RIGHT;
                break;
            }

            FS_Close(input);
            if (ro < FS_NO_ERROR)
            {
                result = ro;
                break;
            }

            if (ro_ret < FS_NO_ERROR)
            {
                result = ro_ret;
                break;
            }
            FS_Delete(file_path);
            break;
        }
    }

#ifdef __DRM_SUPPORT_SD_CALLBACK__
    //cid_ptr = strstr(info->meta[DRM_META_CONTENTURI], "cid:");
    //cid_ptr += 4; /*cid:*/
    if (result == DRM_RESULT_OK)
    {
        drmt_sd_callback_rights_arrive(serial, info->meta[DRM_META_CONTENTURI]);
    }
#endif

    drm_core_release_info(info);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_add_fl_sd_object
 * DESCRIPTION
 *  parse separate delivery content in a forward locked message
 * PARAMETERS
 *  file_path       [IN]        
 *  input           [IN]        
 *  info            [IN]        
 *  new_path        [IN]        
 *  offset          [IN]        For writing dcf in the middle of the destination file
 * RETURNS
 *  void
 *****************************************************************************/
drm_proc_enum drm_core_add_fl_sd_object(
                kal_wchar *file_path,
                FS_HANDLE input,
                drm_info_struct *info,
                kal_wchar *new_path,
                kal_uint32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE ro, new_dcf;
    kal_int32 ro_ret = FS_NO_ERROR;
    drm_proc_enum result;
    drm_rights_struct *rights = info->rights;
    kal_uint8 key[DRM_MAX_KEY_LENGTH];
    kal_uint8 *encrypted_cid, *original_cid;
    kal_uint32 sd_pos, cid_length;
    kal_char *cid_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rights->method |= DRM_METHOD_SEPARATE_DELIVERY;
    rights->status = DRM_STATUS_RIGHTS_PENDING;

    FS_GetFilePosition(input, &sd_pos);
    rights->offset = 0;

    result = drm_parse_dcf(input, info);
    if (result != DRM_RESULT_OK)
    {
        FS_Close(input);
        return result;
    }

    ro = drm_core_open_rights_object(FS_READ_WRITE, info->meta[DRM_META_CONTENTURI], KAL_FALSE);
    if (ro < FS_NO_ERROR || drm_core_load_rights_dcf(ro, rights) == KAL_FALSE)
    {
        /* cid not present => rights pending */
        ro = drm_core_open_rights_object((FS_READ_WRITE | FS_CREATE_ALWAYS), info->meta[DRM_META_CONTENTURI], KAL_FALSE);

        rights->permission = DRM_PERMISSION_NONE;

    }

    /* Encrypt cid */
    encrypted_cid = drmt_mem_alloc(DRM_MAX_CID_URL_LENGTH);
    original_cid = drmt_mem_alloc(DRM_MAX_CID_URL_LENGTH);
    memset(encrypted_cid, 0, DRM_MAX_CID_URL_LENGTH);

    /* keep "MTK_FLDCF_cid:" */
    strcpy((kal_char*) original_cid, &(info->meta[DRM_META_CONTENTURI][4]));

    drm_core_get_key(key);
    drm_core_rc4_encrypt_buff(key, 16, encrypted_cid, original_cid, strlen((kal_char*) original_cid));

    cid_ptr = info->meta[DRM_META_CONTENTURI];
    strcpy(cid_ptr, "MTK_FLDCF_cid:");
    cid_ptr += strlen("MTK_FLDCF_cid:");
    memcpy(cid_ptr, (kal_char*) encrypted_cid, strlen((kal_char*) original_cid));
    cid_length = strlen((kal_char*) original_cid) + strlen("MTK_FLDCF_cid:");

    drmt_mem_free(original_cid);
    drmt_mem_free(encrypted_cid);

    rights->offset += 10;   /* cid -> MTK_FLDCF_cid */

    if (new_path != NULL)   /* Others */
    {
        if (offset != 0)    /* drm_core_encode_drm_message */
        {
            new_dcf = FS_Open(new_path, FS_READ_WRITE);
            if (new_dcf == FS_ACCESS_DENIED)
            {
                new_dcf = input;
            }
            if (new_dcf >= FS_NO_ERROR)
            {
                FS_Seek(new_dcf, offset, FS_FILE_BEGIN);
            }
        }
        /* virtual file */
        else
        {
            drm_replace_file_extension(new_path, rights->mime_type);
            new_dcf = FS_Open(new_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
        }
    }
    else    /* normal file */
    {
        new_dcf = FS_Open(info->content_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    }

    /* Write DCF */
    if (new_dcf >= FS_NO_ERROR)
    {
        drm_core_parse_dcf_in_fl(input, new_dcf, rights, info, sd_pos, info->meta[DRM_META_CONTENTURI], cid_length);
    }

    FS_Close(new_dcf);
    FS_Close(input);

    if (new_dcf < FS_NO_ERROR)
    {
        if (new_dcf == FS_FILE_EXISTS)
        {
            return DRM_RESULT_FILE_EXISTS;
        }
        else
        {
            return DRM_RESULT_FS_ERROR;
        }
    }
    
    /* Create RO */
    ro_ret = drm_core_create_rights_object(ro, rights, info->content_path);
	if(!drm_core_check_is_ro_used(ro))
	{
		FS_Close(ro);
	}

    if (ro < FS_NO_ERROR)
    {
        return ro;
    }

    if (ro_ret < FS_NO_ERROR)
    {
        return ro_ret;
    }

    return DRM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_validate_permission_aux
 * DESCRIPTION
 *  check DRM rights with specific permission
 * PARAMETERS
 *  source      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool drm_core_validate_permission_aux(FS_HANDLE source)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_rights_struct *rights;
    kal_bool result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rights = drm_core_get_rights(source);
    if (rights != NULL)
    {
        kal_uint8 permission = DRM_PERMISSION_NONE;
        applib_mime_type_struct *mime;

        mime = applib_mime_type_look_up(NULL, NULL, 0, rights->mime_type);
        if(mime)
        {
            switch (mime->mime_type)
            {
                case MIME_TYPE_IMAGE:
                    permission = DRM_PERMISSION_DISPLAY;
                    result = drm_core_check_rights(rights, permission);
                    if (result == KAL_FALSE)
                    {
                        permission = DRM_PERMISSION_PRINT;
                        result = drm_core_check_rights(rights, permission);
                    }
                    return result;
                case MIME_TYPE_AUDIO:
                case MIME_TYPE_VIDEO:
                    permission = DRM_PERMISSION_PLAY;
                    break;
                case MIME_TYPE_APPLICATION:
                    permission = DRM_PERMISSION_EXECUTE;
                    break;
                default:
                    break;
            }
        }

        return drm_core_check_rights(rights, permission);
    }
    else    /* non DRM file, always allow to use */
    {
        return KAL_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_check_rights
 * DESCRIPTION
 *  check rights with a specific permission
 * PARAMETERS
 *  rights          [IN]        
 *  permission      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool drm_core_check_rights(drm_rights_struct *rights, kal_uint8 permission)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = drm_core_check_rights_aux(rights, permission, DRM_CHK_FLT_NONE);

    DRM_MTK_TRACE(("drm_core_check_rights = %d"), (TRACE_INFO, DRM_MTK_RO_VALIDATE, result));
    if (result == DRM_STATUS_NO_RIGHTS || result == DRM_STATUS_RIGHTS_IN_FUTURE)
    {
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_rights_in_future
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rights          [?]         [?]         [?]
 *  permission      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool drm_core_rights_in_future(drm_rights_struct *rights, kal_uint8 permission)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rights != NULL)
    {
        /* third para: in future constraint shall not be skipped */
        kal_uint8 result = drm_core_check_rights_aux(rights, permission, DRM_CHK_FLT_DL_ONLY);

        DRM_MTK_TRACE(("drm_core_rights_in_future: %d"), (TRACE_INFO, DRM_MTK_RO_FUTURE, result));

        if (result == DRM_STATUS_RIGHTS_IN_FUTURE)
        {
            return KAL_TRUE;
        }
        else
        {
            return KAL_FALSE;
        }
    }
    else    /* non DRM file, always allow to use */
    {
        return KAL_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_check_rights_aux
 * DESCRIPTION
 *  check rights with a specific permission
 * PARAMETERS
 *  rights          [IN]        
 *  permission      [IN]        
 *  dl_only         [IN]        
 *  time_only       [IN]        
 *  future_only     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 drm_core_check_rights_aux(
            drm_rights_struct *rights,
            kal_uint8 permission,
            kal_uint8 filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_constraint_struct *constraint;
    applib_time_struct time;
    kal_uint32 ltime;
    kal_uint8 check_cons, i, best_cons, prev_cons;
    kal_bool future_exist = KAL_FALSE;
    kal_bool stime_status = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stime_status = drm_core_get_stime(&time);

    ltime = applib_dt_mytime_2_utc_sec(&time, KAL_FALSE);

    DRM_MTK_TRACE(("drm_core_check_rights_aux: ltime = %d"), (TRACE_INFO, DRM_MTK_CHECK_RO, ltime));
    
    /* No rights if permission is DRM_PERMISSION_NONE */
    if (permission == DRM_PERMISSION_NONE)
    {
        DRM_MTK_TRACE(("Right status = %d"), (TRACE_INFO, DRM_MTK_CHECK_RO_STATUS, DRM_STATUS_NO_RIGHTS));
        return DRM_STATUS_NO_RIGHTS;
    }

    if (rights->permission == DRM_PERMISSION_ALL)
    {
        DRM_MTK_TRACE(("Right status = %d"), (TRACE_INFO, DRM_MTK_CHECK_RO_STATUS, DRM_STATUS_NO_RIGHTS));
        return DRM_STATUS_RIGHTS_PRESENT;
    }
    else if (rights->permission & permission)
    {
        for (i = DRM_PERMISSION_NONE; (1 << i) <= DRM_PERMISSION_ALL; i++)
        {
            if (permission == (1 << i))
            {
                break;
            }
        }

        if ((1 << i) == DRM_PERMISSION_ALL) /* There's no matched permission */
        {
            return DRM_STATUS_NO_RIGHTS;            
        }
        /* constraint = &(rights->constraint_list[rights->best[permission]]); */
        constraint = drm_core_get_constraint_int(rights, permission, KAL_TRUE);
        prev_cons = best_cons = rights->best[i];
        while (best_cons != 0xFF)
        {            
            check_cons = drm_core_is_constraint_valid(constraint, (filter & DRM_CHK_FLT_TIME_ONLY));
            if (filter & DRM_CHK_FLT_DL_ONLY)
            {
                DRM_MTK_TRACE(("Right status = %d"), (TRACE_INFO, DRM_MTK_CHECK_RO_STATUS, check_cons));
                return check_cons;
            }
            
            if (check_cons == DRM_STATUS_NO_RIGHTS)
            {
                if (best_cons != rights->best[i]) 
                {
                    DRM_MTK_TRACE(("constraint datetime in future"), (TRACE_INFO, DRM_MTK_CONS_DATETIME_IN_FUTURE));
                    rights->constraint_list[best_cons].status = KAL_FALSE;
                    best_cons = rights->constraint_list[best_cons].next;
                    rights->constraint_list[prev_cons].next = best_cons;
                    constraint = &(rights->constraint_list[best_cons].cons);                    
                }
                else
                {                              
                    rights->constraint_list[rights->best[i]].status = KAL_FALSE;                    
                    rights->best[i] = rights->constraint_list[rights->best[i]].next;
                    constraint = &(rights->constraint_list[rights->best[i]].cons);                    
                    best_cons = rights->constraint_list[best_cons].next;
                }
                rights->num[i]--;
            }
            else if (check_cons == DRM_STATUS_RIGHTS_IN_FUTURE)
            {
                /* Do not modify the best index of rights */
                prev_cons = best_cons;
                best_cons = rights->constraint_list[best_cons].next;
                constraint = &(rights->constraint_list[best_cons].cons);
                if (filter & DRM_CHK_FLT_FUTURE)
                {
                    future_exist = KAL_TRUE;
                }
            }
            else
            {
                DRM_MTK_TRACE(("Right status = %d"), (TRACE_INFO, DRM_MTK_CHECK_RO_STATUS, check_cons));
                return check_cons;
            }
        }

        DRM_MTK_TRACE(("Right status = %d"), (TRACE_INFO, DRM_MTK_CHECK_RO_STATUS, DRM_STATUS_NO_RIGHTS));
        if (future_exist)
        {
            return DRM_STATUS_RIGHTS_IN_FUTURE;
        }
        else
        {
            return DRM_STATUS_NO_RIGHTS;
        }
    }
    else
    {
        /* no permission => can't use */
        DRM_MTK_TRACE(("Right status = %d"), (TRACE_INFO, DRM_MTK_CHECK_RO_STATUS, DRM_STATUS_NO_RIGHTS));
        return DRM_STATUS_NO_RIGHTS;
    }
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_is_constraint_valid
 * DESCRIPTION
 *  check if constraint is valid
 * PARAMETERS
 *  constraint      [?]         [in]
 *  time_only       [IN]        
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
kal_uint8 drm_core_is_constraint_valid(drm_constraint_struct *constraint, kal_bool time_only)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct time;
    kal_int32 ltime;
    kal_bool stime_status = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!constraint)
    {
        return DRM_STATUS_NO_RIGHTS;
    }
    DRM_MTK_TRACE(("check constraint, type = %d"), (TRACE_INFO, DRM_MTK_CONS_VALIDATE_TYPE, constraint->type));

    stime_status = drm_core_get_stime(&time);

    ltime = (kal_int32)applib_dt_mytime_2_utc_sec(&time, KAL_FALSE);

    if (constraint->type == DRM_CONSTRAINT_NONE)
    {
        return DRM_STATUS_RIGHTS_PRESENT;
    }
    if (!time_only && (constraint->type & DRM_CONSTRAINT_COUNT) && constraint->used_count <= 0)
    {
        DRM_MTK_TRACE(("constraint used_count = %d"), (TRACE_INFO, DRM_MTK_CONS_COUNT_VALIDATE, constraint->used_count));        
        return DRM_STATUS_NO_RIGHTS;
    }
    else
    {
        DRM_MTK_TRACE(("constraint used_count = %d"), (TRACE_INFO, DRM_MTK_CONS_COUNT_VALIDATE, constraint->used_count));        
    }

    if (constraint->type & DRM_CONSTRAINT_DATETIME)
    {
        DRM_MTK_TRACE(("constraint constraint current time = %d, start_time = %d, end_time = %d"), 
            (TRACE_INFO, DRM_MTK_CONS_DATETIME_VALIDATE, ltime, constraint->start_time, constraint->end_time));
        if(!stime_status)
        {
            return DRM_STATUS_NO_RIGHTS;
        }
        if (constraint->start_time < 0 || constraint->end_time < 0 || (constraint->start_time > constraint->end_time && constraint->end_time != 0))
        {
            return DRM_STATUS_NO_RIGHTS;
        }
        /* already expired rights */
        if (constraint->end_time > 0 && (ltime > constraint->end_time))
        {
            return DRM_STATUS_NO_RIGHTS;
        }
    }
    if (constraint->type & DRM_CONSTRAINT_INTERVAL)
    {
        DRM_MTK_TRACE(("constraint current time = %d, interval = %d, start_intv = %d, end_intv = %d"), 
            (TRACE_INFO, DRM_MTK_CONS_INTERVAL_VALIDATE, ltime, constraint->interval, constraint->start_intv, constraint->end_intv));
        if(!stime_status)
        {
            return DRM_STATUS_NO_RIGHTS;
        }
        if (constraint->interval <= 0)
        {
            return DRM_STATUS_NO_RIGHTS;
        }

        if (constraint->start_intv > 0 && (constraint->start_intv > ltime ||    /* SYSTEM TIME HAS BEEN CHANGED */
                                           ltime > constraint->end_intv))
        {
            return DRM_STATUS_NO_RIGHTS;
        }
    }
    if (constraint->type & DRM_CONSTRAINT_DATETIME && ltime < constraint->start_time)
    {
        DRM_MTK_TRACE(("constraint datetime in future"), (TRACE_INFO, DRM_MTK_CONS_DATETIME_IN_FUTURE));
        if(!stime_status)
        {
            return DRM_STATUS_RIGHTS_IN_FUTURE;
        }
        else
        {
            return DRM_STATUS_NO_RIGHTS;
        }
    }
    else
    {
        return DRM_STATUS_RIGHTS_PRESENT;
    }
}

/******************************************************************/
/*                                                                */
/*       encrypt / decrypt utility                                */
/*                                                                */
/******************************************************************/


/*****************************************************************************
 * FUNCTION
 *  drm_core_get_key
 * DESCRIPTION
 *  generate key for forward lock and combined delivery content
 * PARAMETERS
 *  key_buf     [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
void drm_core_get_key(kal_uint8 *key_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!g_drm_cntx->key_assigned)
    {
        kal_uint8 *tmp_buff = NULL, *imei_buff = NULL;
        int i;
        long v, s;

        tmp_buff = drmt_mem_alloc(DRM_MAX_KEY_LENGTH);
        s = 0x3D4FAD6A;;
        v = ~(0xA9832DC6 ^ s);
        for (i = 0; i < 4; i++)
        {
            tmp_buff[i] = (char)(0xFF & (v >> (i * 8)));
        }

        v = 0x16F0D768 ^ s;
        for (i = 0; i < 4; i++)
        {
            tmp_buff[i + 4] = (char)(0xFF & (v >> (i * 8)));
        }

        v = ~(0x278FB1EA ^ s);
        for (i = 0; i < 4; i++)
        {
            tmp_buff[i + 8] = (char)(0xFF & (v >> (i * 8)));
        }

        v = 0x5F3C54EC ^ s;
        for (i = 0; i < 4; i++)
        {
            tmp_buff[i + 12] = (char)(0xFF & (v >> (i * 8)));
        }

        imei_buff = drmt_mem_alloc(DRM_MAX_KEY_LENGTH);
        memset(imei_buff, 0, DRM_MAX_KEY_LENGTH);
        nvram_get_imei_value(DRM_MAX_KEY_LENGTH, imei_buff, 1);

        for (i = 0; i < 7; i++)
        {
            kal_sprintf(imei_string + i * 2, "%c%c", (imei_buff[i] & 0x0F) + '0', ((imei_buff[i] & 0xF0) >> 4) + '0');
        }
        
        kal_sprintf(imei_string + 14, "%c", (imei_buff[7] & 0x0F) + '0');
        
        imei_string[15] = 0;

        
        drm_core_rc4_decrypt_buff(tmp_buff, DRM_MAX_KEY_LENGTH, (kal_uint8*) g_drm_cntx->key_buf, imei_buff, DRM_MAX_KEY_LENGTH);
        drmt_mem_free(tmp_buff);
        drmt_mem_free(imei_buff);
        g_drm_cntx->key_assigned = KAL_TRUE;
        
    }

    if (key_buf)
    {
        memcpy(key_buf, g_drm_cntx->key_buf, DRM_MAX_KEY_LENGTH);
    }
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_add_padding
 * DESCRIPTION
 *  add padding when encrypt content
 * PARAMETERS
 *  buff        [IN/OUT]        
 *  len         [OUT]           
 * RETURNS
 *  void
 *****************************************************************************/
void drm_core_add_padding(kal_uint8 *buff, kal_uint32 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const char padding = (char)(16 - (*len % 16));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(buff + *len, padding, padding);
    *len += padding;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_rm_padding
 * DESCRIPTION
 *  remove padding when decrypt content
 * PARAMETERS
 *  buff        [IN]        
 *  len         [OUT]       
 * RETURNS
 *  void
 *****************************************************************************/
int drm_core_rm_padding(kal_uint8 *buff, kal_uint32 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const kal_uint8 padding = buff[*len - 1];
    kal_uint8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < padding; i++)
    {
        if (buff[*len - 1 - i] != padding)
        {
            return 0;
        }
    }

    *len -= padding;

    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_encrypt
 * DESCRIPTION
 *  encrypt forward lock and combined delivery content
 * PARAMETERS
 *  myKey           [IN]        
 *  dest            [IN]        
 *  source          [IN]        
 *  file_len        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 drm_core_encrypt(kal_uint8 *myKey, FS_HANDLE dest, FS_HANDLE source, kal_uint32 file_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    __align(4) kal_uint8 iv[16];
    kal_uint8 *in, *out;
    kal_uint8 round = 0;
    kal_bool done = KAL_FALSE;
    kal_uint32 q, i = 0, size, len;
    kal_int32 fs_ret = 0, pos;
    STCHE *che_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    che_str = (STCHE*) drmt_mem_alloc(sizeof(STCHE) + 16);

    ASSERT(((kal_int32) che_str & 0x03) == 0);

    q = ((g_drm_cache_size == 0) ? DRM_CRYPTO_WKBUF_SIZE : g_drm_cache_size);

    in = drmt_mem_alloc(q + 32);
    out = drmt_mem_alloc(q + 32);

    che_init(che_str, CHE_AES);
    che_key_action(che_str, CHE_SET_KEY, myKey, 16);

    memcpy(iv, "4074BCC61602B5BE5EDF3586C1C7E90905D", 16);

    /* write iv */
    FS_Write(dest, iv, 16, &len);

    che_set_iv(che_str, iv, 16);
    while (i < file_len)
    {
        if (drmt_async_get_status(current_serial) == DRM_PROC_ENCRYPT_CANCELING)
        {
            che_deinit(che_str);
            drmt_mem_free(in);
            drmt_mem_free(out);
            drmt_mem_free(che_str);
            return DRM_PROC_ENCRYPT_CANCELED;
        }

        size = (file_len - i) > q ? q : file_len - i;
        pos = (kal_int32)size;
        
        FS_Read(source, in, size, &len);
        i += len;

        if (i == file_len)
        {
            drm_core_add_padding(in, (kal_uint32*) & len);
            done = KAL_TRUE;
        }

        che_process(che_str, CHE_AES, CHE_CBC, CHE_ENC, in, out, len, done);

        round++;

        if (dest == source)
        {
            FS_Seek(dest, -pos, FS_FILE_CURRENT);
        }
        fs_ret = FS_Write(dest, out, len, &size);
        if (fs_ret < FS_NO_ERROR)
        {
            break;
        }
    }

    che_deinit(che_str);
    drmt_mem_free(in);
    drmt_mem_free(out);
    drmt_mem_free(che_str);
    return fs_ret;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_decrypt_block
 * DESCRIPTION
 *  
 * PARAMETERS
 *  source              [IN]        
 *  curr_blk            [IN]        
 *  workn_buf           [?]         [?]         [?]
 *  che_str             [?]         
 *  is_last_block       [IN]        
 *  key_len(?)          [IN]        
 *  start(?)            [IN]        
 *  offset(?)           [IN]        
 *  myKey           [?]         [?](?)
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_core_decrypt_block(
            drm_handle_struct *source,
            kal_int32 curr_blk,
            kal_uint8 *workn_buf,
            STCHE *che_str,
            kal_uint32 is_last_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *in, *out;
    kal_int32 ret;
    kal_uint32 len, block_size;
    kal_uint32 offset = source->info->rights->offset;
    kal_int32 previous_blk = source->previous_blk;
    kal_uint8 *cek = source->info->rights->key;
    kal_uint8 cek_len = source->info->rights->key_len;
    kal_uint8 iv[DRM_MAX_KEY_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cek || !cek_len)
    {
        return FS_ERROR_RESERVED;
    }

    if (cek_len != DRM_MAX_KEY_LENGTH)
    {
        return FS_ERROR_RESERVED;
    }

    block_size = ((g_drm_cache_size == 0) ? DRM_CRYPTO_WKBUF_SIZE : g_drm_cache_size);

    in = workn_buf;
    out = workn_buf;
    DRM_MTK_TRACE(("previous_blk = %d, curr_blk = %d"), (TRACE_GROUP_8, DRM_MTK_DEC, previous_blk, curr_blk));    

    //if (previous_blk < 0 || (previous_blk + 1) != curr_blk)
    {
        ret = FS_Seek(source->handle, offset + (curr_blk * block_size), FS_FILE_BEGIN);
        DRM_MTK_TRACE(("handle = %d, offset = %d"), (TRACE_GROUP_8, DRM_MTK_DEC_OFFSET, source->handle, ret)); 

        ret = FS_Read(source->handle, in, DRM_MAX_KEY_LENGTH + block_size, &len);
        DRM_MTK_TRACE(("handle = %d, len = %d"), (TRACE_GROUP_8, DRM_MTK_DEC_LEN, source->handle, len));    

        memcpy(iv, in, DRM_MAX_KEY_LENGTH);
        memcpy(source->info->rights->iv, in + block_size, DRM_MAX_KEY_LENGTH);
        in += DRM_MAX_KEY_LENGTH;
        len -= DRM_MAX_KEY_LENGTH;
    }
    /*else
    {
        memcpy(iv, source->info->rights->iv, DRM_MAX_KEY_LENGTH);

        ret = FS_Read(source->handle, in, block_size, &len);
        DRM_MTK_TRACE(("handle = %d, len = %d"), (TRACE_GROUP_8, DRM_MTK_DEC_LEN, source->handle, len));    

        memcpy(source->info->rights->iv, in + block_size - DRM_MAX_KEY_LENGTH, DRM_MAX_KEY_LENGTH);
    }*/

    if (ret >= FS_NO_ERROR && len > 0)
    {
        che_set_iv(che_str, iv, cek_len);
        DRM_MTK_TRACE(("handle = %d, in = %x%x"), (TRACE_GROUP_8, DRM_MTK_DEC_IN, source->handle, in[0], in[1]));    

        che_process(che_str, CHE_AES, CHE_CBC, CHE_DEC, in, out, len, KAL_FALSE);
        DRM_MTK_TRACE(("handle = %d, out = %x%x"), (TRACE_GROUP_8, DRM_MTK_DEC_OUT, source->handle, out[0], out[1]));    

        /* last block, remove padding */
        if (is_last_block)
        {
            drm_core_rm_padding(out, (kal_uint32*) & len);
        }
    }

    return len;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_decrypt_buffer
 * DESCRIPTION
 *  decrypt DCF content
 * PARAMETERS
 *  myKey           [IN]            
 *  key_len         [IN]            
 *  offset          [IN]            Offset of real content in DCF
 *  buffer          [IN/OUT]        
 *  size            [IN]            
 *  start           [IN]            Start decrypt block number
 *  workn_buf       [IN]            Working buffer
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 drm_core_decrypt_buffer(
            kal_uint8 *myKey,
            kal_uint8 key_len,
            kal_uint32 offset,
            kal_uint8 *buffer,
            kal_uint32 size,
            kal_uint32 start,
            kal_uint8 *workn_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    __align(4) kal_uint8 iv[16];
    kal_uint8 *in, *out, *bp;
    kal_uint32 len, last;
    kal_uint32 q = ((g_drm_cache_size == 0) ? DRM_CRYPTO_WKBUF_SIZE : g_drm_cache_size);
    STCHE *che_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!myKey || !key_len)
    {
        return FS_ERROR_RESERVED;
    }

    in = workn_buf;
    out = workn_buf;
    bp = buffer;
    che_str = (STCHE*) drmt_mem_alloc(sizeof(STCHE));

    ASSERT(((kal_int32) che_str & 0x03) == 0);

    che_init(che_str, CHE_AES);
    che_key_action(che_str, CHE_SET_KEY, myKey, key_len);

    /* ret = FS_Seek(source, offset + start * q, FS_FILE_BEGIN); */
    bp += offset + start * q;

    /* ret = FS_Read(source, iv, 16, &len); */
    len = 16;
    memcpy(iv, bp, len);
    bp += len;

    /* ret = FS_Read(source, in, q, &len); */
    len = (size < q) ? size : q;
    memcpy(in, bp, len);
    bp += len;

    if (len > 0)
    {
        che_set_iv(che_str, iv, key_len);
        che_process(che_str, CHE_AES, CHE_CBC, CHE_DEC, in, out, len, KAL_FALSE);

        if ((size - offset) % q == 0)
        {
            last = (size - offset) / q - 1;
        }
        else
        {
            last = (size - offset) / q;
        }
        /* last block, remove padding */
        if (start == last)
        {
            drm_core_rm_padding(out, (kal_uint32*) & len);
        }
    }

    che_deinit(che_str);
    drmt_mem_free(che_str);

    return len;
}


/*****************************************************************************
 * FUNCTION
 *  drm_get_consumer_by_evid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_get_consumer_by_evid(kal_uint32 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_search_db
 * DESCRIPTION
 *  RO dbms
 * PARAMETERS
 *  serial          [IN]        async tbl serial
 *  index           [IN]        Start index to search
 *  rights          [OUT]       Target RO
 *  valid_count     [OUT]       Number of valid/invalid
 *  path            [IN]        Path
 *  flags           [IN]        Bit mask of request
 * RETURNS
 *  error code
 *****************************************************************************/
kal_int32 drm_core_search_db(kal_uint8 serial, kal_int32 index, drm_rights_struct *rights, kal_uint32 *total_count, kal_uint32 *valid_count, kal_wchar *path, kal_uint8 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE ro = FS_NO_ERROR;
    kal_wchar *pattern = NULL;
    kal_wchar *file_name = NULL, *file_name_ptr;
    FS_DOSDirEntry *file_info = NULL;
    kal_int32 ret = DRM_RESULT_NON_DRM;
    kal_uint8 *buffer = NULL, *key = NULL;
    drm_constraint_entry_struct *appending = NULL;
    kal_uint8 j, cons_num, cons_index;
    kal_uint8 mask_filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(total_count)
	*total_count = 0;
	if(valid_count)
	*valid_count = 0;
    if ((flags & DRM_DB_ALL) && drmt_async_get_status(serial) == DRM_PROC_ENCRYPT_CANCELING)
    {
        drmt_async_set_status(serial, DRM_PROC_ENCRYPT_CANCELED);
        return DRM_RESULT_CANCELED;
    }

    if (flags & DRM_DB_ALL)
    {
        index = 0;
    }

    if (flags & DRM_DB_HIDDEN)
    {
        mask_filter = FS_ATTR_DIR;        
    }
    else
    {        
        mask_filter = FS_ATTR_DIR | FS_ATTR_HIDDEN;
    }
    
    pattern = (kal_wchar*) drmt_mem_alloc((kal_wstrlen(DRM_RO_PATH) + 42) * ENCODING_LENGTH);
    file_name = (kal_wchar*) drmt_mem_alloc(DRM_MAX_PATH_LENGTH * ENCODING_LENGTH);
    app_ucs2_strcpy((kal_int8*)file_name, (kal_int8*)DRM_RO_PATH);
    file_name_ptr = file_name + app_ucs2_strlen((kal_int8*)file_name);
    kal_wsprintf(pattern, "%w*.*", DRM_RO_PATH);
    file_info = (FS_DOSDirEntry *)drmt_mem_alloc(sizeof(FS_DOSDirEntry));
    key = (kal_uint8 *)drmt_mem_alloc(DRM_MAX_KEY_LENGTH);
    drm_core_get_key(key);
        
    ro = FS_FindFirstN(
            pattern,
            NULL,
            0,
            0,
            0,
            mask_filter,
            file_info,
            file_name_ptr,
            (DRM_MAX_PATH_LENGTH * ENCODING_LENGTH),
            (kal_uint32)index,
            FS_FIND_DEFAULT);

    if (ro >= FS_NO_ERROR)
    {
        kal_uint32 len;
        kal_int32 fs_ret, delete_ret = FS_NO_ERROR;

        ret = FS_SetCurrentDir((kal_wchar*) DRM_RO_PATH);

        if (rights == NULL && (flags & DRM_DB_INVALID || flags & DRM_DB_VALID))
        {
            buffer = (kal_uint8*) drmt_mem_alloc(DRM_RIGHTS_SIZE);
            rights = (drm_rights_struct*) buffer;
        }

        do
        {
            kal_bool to_kill = (flags & DRM_DB_KILL) ? KAL_TRUE : KAL_FALSE;
            kal_uint8 valid_flag = KAL_FALSE;

            if ((flags & DRM_DB_ALL) && drmt_async_get_status(serial) == DRM_PROC_ENCRYPT_CANCELING)
            {
                drmt_async_set_status(serial, DRM_PROC_ENCRYPT_CANCELED);
                FS_FindClose(ro);
                drmt_mem_free(pattern);
                drmt_mem_free(file_name);
                drmt_mem_free((void *)file_info);
                drmt_mem_free(key);
                return DRM_RESULT_CANCELED;
            }

            if (flags & DRM_DB_INVALID || flags & DRM_DB_VALID)
            {
                FS_HANDLE fh = FS_Open((kal_wchar*) file_name, FS_READ_ONLY | FS_OPEN_SHARED);

                if (fh >= FS_NO_ERROR)
                {
                    kal_bool activate_yet = KAL_FALSE;
                    kal_wchar *content_path = (kal_wchar*) drmt_mem_alloc(DRM_MAX_PATH_LENGTH * ENCODING_LENGTH);

                    fs_ret = FS_Read(fh, content_path, DRM_MAX_PATH_LENGTH * ENCODING_LENGTH, &len);

                    
                    if (kal_wstrlen(content_path) == 0)
                    {
                        activate_yet = KAL_TRUE;
                    }

                    if (path && app_ucs2_strncmp((kal_int8*)content_path, (kal_int8*)path, 3) != 0)
                    {
                        drmt_mem_free(content_path);
                        FS_Close(fh);
                        continue;
                    }
                    drmt_mem_free(content_path);

                    fs_ret = FS_Read(fh, rights, DRM_RIGHTS_SIZE, &len);

                    if (fs_ret >= FS_NO_ERROR)
                    {
                        kal_uint8 permission;
                        kal_uint8 i;
                        kal_uint8 *tmp_cons;

                        /* check ro size */
                        if (file_info->FileSize < DRM_MAX_PATH_LENGTH * ENCODING_LENGTH + DRM_RIGHTS_SIZE)
                        {
                            FS_SetCurrentDir((kal_wchar *)DRM_RO_PATH);
                            FS_Close(fh);
                            FS_Delete((kal_wchar*) file_name);
                            ret = FS_FindNextN(
                                    ro,
                                    NULL,
                                    0,
                                    0,
                                    file_info,
                                    file_name_ptr,
                                    (DRM_MAX_PATH_LENGTH * ENCODING_LENGTH),
                                    FS_FIND_DEFAULT);
                            continue;
                        }

                        /* calculate constraint number */
                        cons_num =
                            (file_info->FileSize - DRM_RIGHTS_SIZE -
                             (DRM_MAX_PATH_LENGTH * ENCODING_LENGTH)) / DRM_CONSTRAINT_ENTRY_SIZE;
                        tmp_cons = (kal_uint8*)drmt_mem_alloc(DRM_CONSTRAINT_ENTRY_SIZE);
                        /* Decrypt ro */
                        drm_core_rc4_decrypt_buff(key, DRM_MAX_KEY_LENGTH, (kal_uint8*) rights, (kal_uint8*) rights, DRM_RIGHTS_SIZE);

                        /* to ensure the rights could be decrypted correctly */
                        if (rights->key_len != DRM_MAX_KEY_LENGTH)
                        {
                            to_kill = KAL_TRUE;
                        }
                        else
                        {
                            /* 
                             * WARNING! constraint_list will be released by calling drm_core_free_ro_detail for !DRM_DB_ALL cases
                             */
                            if(total_count)
		                         (*total_count)++;
                            appending = rights->constraint_list =
                                (drm_constraint_entry_struct*) drmt_mem_alloc(cons_num * DRM_CONSTRAINT_ENTRY_SIZE);

                            for (i = DRM_PERMISSION_NONE; (1 << i) <= DRM_PERMISSION_PRINT; i++)
                            {
                                permission = (1 << i);

                                /* Decrypt constraint */
                                
                                if (appending == NULL)
                                {
                                    break; /* invalid rights; delete */
                                }
                                
                                cons_index = rights->best[i];

                                for (j = 0; j < rights->num[i]; j++)
                                {
                                    FS_Seek(
                                        fh,
                                        DRM_MAX_PATH_LENGTH * ENCODING_LENGTH + DRM_RIGHTS_SIZE + (cons_index * DRM_CONSTRAINT_ENTRY_SIZE),
                                        FS_FILE_BEGIN);
                                    
                                    FS_Read(fh, tmp_cons, DRM_CONSTRAINT_ENTRY_SIZE, &len);

                                    appending = rights->constraint_list + cons_index;

                                    drm_core_rc4_decrypt_buff(
                                        key,
                                        DRM_MAX_KEY_LENGTH,
                                        (kal_uint8*) appending,
                                        tmp_cons,
                                        DRM_CONSTRAINT_ENTRY_SIZE);

                                    cons_index = appending->next;
                                }
                                
                                if (activate_yet == KAL_TRUE ||
                                    drm_core_check_rights(rights, permission) == KAL_TRUE ||
                                    drm_core_rights_in_future(rights, permission) == KAL_TRUE)
                                {

                                    if (valid_count && !valid_flag)
                                        (*valid_count)++;

                                    to_kill = KAL_FALSE;
                                    valid_flag = KAL_TRUE;
                                }
                                
                            }

                            if (flags & DRM_DB_ALL)
                            {
                                drmt_mem_free(rights->constraint_list);
                            }

                        }
                        FS_Close(fh);
                        drmt_mem_free(tmp_cons);

                    }

                }
            }

            if (to_kill)
            {
                fs_ret = FS_Delete(file_name);
                if (fs_ret < FS_NO_ERROR)
                {
                    delete_ret = fs_ret;
                }              
                else
                {
                    /* notice the modification of ro database */
                    drm_core_update_ro_db();
                }
            }
            else
            {
                kal_int32 attr = FS_GetAttributes((const WCHAR*)file_name);
                if (!valid_flag)
                {
                    FS_SetAttributes((const WCHAR*)file_name, (kal_uint8) (attr | FS_ATTR_HIDDEN));                
                }
                else if (attr & FS_ATTR_HIDDEN)
                {
                    FS_SetAttributes((const WCHAR*)file_name, (kal_uint8) (attr & ~(FS_ATTR_HIDDEN)));                
                }
            }

            if (!(flags & DRM_DB_ALL))
            {
                ret = delete_ret;
                break;
            }

            ret = FS_FindNextN(
                    ro,
                    NULL,
                    0,
                    0,
                    file_info,
                    file_name_ptr,
                    (DRM_MAX_PATH_LENGTH * ENCODING_LENGTH),
                    FS_FIND_DEFAULT);

        } while (ret >= FS_NO_ERROR);

        if (buffer)
            drmt_mem_free(buffer);

        FS_FindClose(ro);

        if (flags & (DRM_DB_KILL | DRM_DB_ALL | DRM_DB_HIDDEN))
            FS_CompactDir(DRM_RO_PATH, FS_CMPCT_RECURSIVE);
            
        if (ret == FS_NO_MORE_FILES)
        {
            if (delete_ret >= FS_NO_ERROR)
            {
                ret = FS_NO_ERROR;
            }
            else
            {
                ret = delete_ret;
            }
        }

    }
    else
    {
        ret = ro;
    }
    drmt_mem_free(pattern);
    drmt_mem_free(file_name);
    drmt_mem_free((void *)file_info);
    drmt_mem_free(key);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  drm_core_check_ro_db
 * DESCRIPTION
 *  Check if ro database has been updated
 * PARAMETERS
 *       
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool drm_core_check_ro_db(void)
{
    if (g_drm_cntx->is_ro_update == KAL_TRUE)
    {
        g_drm_cntx->is_ro_update = KAL_FALSE;
        return KAL_TRUE;
    }
    return KAL_FALSE;    
}

/*****************************************************************************
 * FUNCTION
 *  drm_core_check_ro_db
 * DESCRIPTION
 *  Check if ro database has been updated
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void drm_core_update_ro_db(void)
{
    g_drm_cntx->is_ro_update = KAL_TRUE;
    
}

/*****************************************************************************
 * FUNCTION
 *  drm_core_process_db
 * DESCRIPTION
 *  
 * PARAMETERS
 *  serial      [IN]        
 *  type        [IN]        
 *  index       [IN]        
 *  path        [?]         
 *  id(?)       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 drm_core_process_db(kal_uint8 serial, kal_uint8 type, kal_int32 index, kal_wchar *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == DRM_PROCESS_DATABASE_SWEEP)
    {
        return drm_core_search_db(serial, index, NULL, NULL, NULL, NULL, (DRM_DB_KILL | DRM_DB_ALL | DRM_DB_INVALID | DRM_DB_HIDDEN));;
    }
    else if (type == DRM_PROCESS_DATABASE_DELETE_SINGLE_FROM_VALID)
    {
        return drm_core_search_db(serial, index, NULL, NULL, NULL, NULL, DRM_DB_KILL);
    }
	else if (type == DRM_PROCESS_DATABASE_DELETE_SINGLE_FROM_ALL)
	{
	    return drm_core_search_db(serial, index, NULL, NULL, NULL, NULL, DRM_DB_KILL | DRM_DB_HIDDEN);
	}
    else if (type == DRM_PROCESS_DATABASE_DELETE_ALL)
    {
        return drm_core_search_db(serial, index, NULL, NULL, NULL, path, (DRM_DB_KILL | DRM_DB_ALL | DRM_DB_HIDDEN));
    }

    return DRM_RESULT_DATA_NOT_FOUND;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_get_stime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  time        [?]     [?]
 * RETURNS
 *  
 *****************************************************************************/
kal_bool drm_core_get_stime(applib_time_struct *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __DRM_SEC_CLK_NITZ__
    applib_dt_get_rtc_time((applib_time_struct*) time);
    return KAL_TRUE;
#else /*__DRM_SEC_CLK_NITZ__*/
	return drm_stime_get_secure_time(time);
#endif /*__DRM_SEC_CLK_NITZ__*/
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_get_ro_num
 * DESCRIPTION
 *  To get rights objects number
 * PARAMETERS
 *  serial      [IN]        
 * RETURNS
 *  Number of RO; -1 means error
 *****************************************************************************/
kal_int32 drm_core_get_ro_num(kal_uint8 serial, drm_proc_db_ro_count_flag_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result;
    kal_int32 valid_ro_count, total_ro_count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_drm_cntx->ro_count != 0)
    {
        drm_core_free_ro_list();
    }

    result = drm_core_search_db(serial, 0, NULL, &total_ro_count, &valid_ro_count, NULL, (DRM_DB_VALID | DRM_DB_INVALID | DRM_DB_ALL | DRM_DB_HIDDEN));

    if (result == DRM_RESULT_CANCELED)
    {
        return DRM_RESULT_CANCELED;
    }
    else if(flag == DRM_DB_GET_ALL)
    {
        return g_drm_cntx->ro_count = total_ro_count;
    }
	else if(flag == DRM_DB_GET_VALID)
	{
		return g_drm_cntx->ro_count = valid_ro_count;
	}
	else if(flag == DRM_DB_GET_INVALID)
    {
		return g_drm_cntx->ro_count = total_ro_count - valid_ro_count;
    }

}


/*****************************************************************************
 * FUNCTION
 *  drm_core_get_ro
 * DESCRIPTION
 *  To get rights objects list
 * PARAMETERS
 *  index       [IN]        Index of ro list
 *  alias       [OUT]       Alias string of the specific ro
 *  size        [IN]        
 * RETURNS
 *  is dcf or not
 *****************************************************************************/
kal_int32 drm_core_get_ro(kal_int32 index, char *alias, kal_uint32 size, drm_proc_db_ro_count_flag_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *pattern = NULL, *file_name = NULL;
    FS_DOSDirEntry file_info;
    FS_HANDLE ro = FS_ERROR_RESERVED;
    kal_int32 ret = FS_NO_ERROR;
    kal_uint32 len = 0;
    kal_uint8 mask_filter = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(flag == DRM_DB_GET_VALID)
	{
	    mask_filter = FS_ATTR_DIR | FS_ATTR_HIDDEN;
	}
	else if(flag == DRM_DB_GET_ALL)
	{
        mask_filter = FS_ATTR_DIR;
	}
    if (g_drm_cntx->ro_count > (kal_uint32)index )
    {
        kal_wchar *content_path;
        drm_rights_struct *rights;

        pattern = (kal_wchar*) drmt_mem_alloc((kal_wstrlen(DRM_RO_PATH) + 42) * ENCODING_LENGTH);
        file_name = (kal_wchar*) drmt_mem_alloc(DRM_MAX_PATH_LENGTH * ENCODING_LENGTH);
        kal_wsprintf(pattern, "%w*.*", DRM_RO_PATH);
        ro = FS_FindFirstN(
                pattern,
                NULL,
                0,
                0,
                0,
                mask_filter,
                &file_info,
                file_name,
                (DRM_MAX_PATH_LENGTH * ENCODING_LENGTH),
                (kal_uint32)index,
                FS_FIND_DEFAULT);
        drmt_mem_free(pattern);

        if (ro >= FS_NO_ERROR)
        {
            FS_FindClose(ro);

            FS_SetCurrentDir((kal_wchar*) DRM_RO_PATH);

            ro = FS_OpenHint(file_name, FS_READ_ONLY | FS_OPEN_SHARED, DRM_get_open_hint(file_name));

            content_path = (kal_wchar*) drmt_mem_alloc(DRM_MAX_PATH_LENGTH * ENCODING_LENGTH);
            /* 1. read content path */
            ret = FS_Read(ro, content_path, DRM_MAX_PATH_LENGTH * ENCODING_LENGTH, &len);
            if (kal_wstrlen(content_path) > 0)
            {
                kal_wchar *tmp = kal_wstrrchr(content_path, (kal_int32) '\\') + 1;

                kal_wsprintf((kal_wchar*) alias, "%w", tmp);
            }
            else
            {
                kal_wsprintf((kal_wchar*) alias, "RO%03d", index);
            }
            drmt_mem_free(content_path);

            /* 2. read the rights *//*
            rights = (drm_rights_struct*) drmt_mem_alloc(DRM_RIGHTS_SIZE);
            ret = FS_Read(ro, rights, DRM_RIGHTS_SIZE, &len);*/
	   ret = FS_GetAttributes(file_name);
           if (ret & FS_ATTR_HIDDEN)
            {
                ret = DRM_RESULT_NO_PERMISSION;
                }
                else
                {
	        ret = DRM_RESULT_OK;                
            }
            //drmt_mem_free(rights);
            FS_Close(ro);
        }

        drmt_mem_free(file_name);
        if (ret == DRM_RESULT_OK)
        {
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_free_ro_list
 * DESCRIPTION
 *  To free rights objects list
 * PARAMETERS
 *  void
 * RETURNS
 *  is dcf or not(?)(?)
 *****************************************************************************/
void drm_core_free_ro_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_drm_cntx->ro_count = 0;
}




/*****************************************************************************
 * FUNCTION
 *  drm_core_check_is_ro_used
 * DESCRIPTION
 *  to check if the ro is being used in current drm handles
 * PARAMETERS
 *  void
 * RETURNS
 *  true    if is bing used else False
 *****************************************************************************/
kal_bool drm_core_check_is_ro_used(FS_HANDLE ro)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	kal_int32 i, ref_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ro != NULL)
    {
        for (i = 0; i < DRM_MAX_FILE_HANDLE; i++)
        {                
            if (g_drm_handles[i].ro == ro)
            {
                ref_count++;
            }
        }

        if (ref_count == 0)
        {
            return KAL_FALSE;
        }
		else
		{
			return KAL_TRUE;
		}
    }

	return KAL_FALSE;		/* default or if null callling function should delete RO file handle */	
}



#endif /* __DRM_MTK__ */ /* __DRM_SUPPORT__ */

