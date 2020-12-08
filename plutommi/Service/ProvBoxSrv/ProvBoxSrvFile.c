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
*  ProvBoxFile.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  This file implements all kinds of file operations used internally.
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
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__

#include "gui_data_types.h"
#include "kal_general_types.h"
#include "mmi_inet_app_trc.h"
#include "kal_public_api.h"
#include "MMIDataType.h"
#include "kal_trace.h"
#include "MMI_inet_app_trc.h"
#include "Unicodexdcl.h"
#include "fs_func.h"
#include "string.h"
#include "stdio.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "DebugInitDef_Int.h"
#include "ProvBoxSrvConfig.h"
#include "ProvBoxSrvProt.h"
   
/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
#define SRV_PROVBOX_FILE_MAX_RECURSION_LEVEL (10)
#define SRV_PROVBOX_FILE_INIT_SIZE          (512)
#define SRV_PROVBOX_FILE_DEFRAG_SIZE        (512)
#define SRV_PROVBOX_FILE_INC_SIZE           (512)
#define SRV_PROVBOX_FILE_FREE_ZERO_SIZE     (512)

#define SRV_PROVBOX_FILE_FLAG_NEED_DEFRAG   (0x00000001)
#define SRV_PROVBOX_FILE_FLAG_FINDING_PACK  (0x00000002)

#define SRV_PROVBOX_FILE_REC_TYPE_USE       (0xF7F7F7F7)
#define SRV_PROVBOX_FILE_REC_TYPE_FREE      (0xD5D5D5D5)

#define SRV_PROVBOX_FILE_REC_FOOTER_USE     (0xE7E7E7E7)
#define SRV_PROVBOX_FILE_REC_FOOTER_FREE    (0xD3D3D3D3)

#define SRV_PROVBOX_FILE_MAX_RW_SIZE        (5 * 1025)

#define SRV_PROVBOX_FILE_CUR_DIR            L"."
#define SRV_PROVBOX_FILE_PARENT_DIR         L".."

#define SRV_PROVBOX_FILE_CHECK_FILENAME_MAX_CHAR_LEN    (20)
#define SRV_PROVBOX_FILE_CHECK_FILE_NAME_MSG            "%d.ck"
#define SRV_PROVBOX_FILE_CHECK_FILENAME_DELETEALL       L"DeleteAll.ck"
#define SRV_PROVBOX_FILE_CHECK_FILENAME_RESTORE         L"Restore.ck"

#define SRV_PROVBOX_FILE_GET_REC_SIZE(data_size)        ((data_size) + SRV_PROVBOX_FILE_REC_PACK_SIZE)
#define MMI_PROVOBOX_FILE_GET_FOOTER_POS(rec)           ((rec)->start_pos + (rec)->rec_size - SRV_PROVBOX_FILE_REC_FOOTER_SIZE)

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

typedef enum
{
    SRV_PROVBOX_APPFILE_TAG_VERTION = 0xA0,
    SRV_PROVBOX_APPFILE_TAG_BASE_INFO = 0xA1,
    SRV_PROVBOX_APPFILE_TAG_MAX_ITEM
} srv_provbox_appfile_tag_enum;

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------App info file-----------------------------------------*/

typedef struct
{
    U32 tag_id;
    U32 value_len;
    CHAR version[SRV_PROVBOX_VERSION_MAX_CHAR_LEN + 4];   /* 4-bytes aligned */
} srv_provbox_appfile_version_tag_struct;

typedef struct
{

    U32 max_msg_id;
} srv_provbox_appfile_base_info_struct;

typedef struct
{

    U32 tag_id;
    U32 value_len;
    srv_provbox_appfile_base_info_struct info;
} srv_provbox_appfile_base_info_tag_struct;

typedef struct
{
    srv_provbox_appfile_version_tag_struct ver_tag;
    srv_provbox_appfile_base_info_tag_struct base_info_tag;
} srv_provbox_appfile_struct;

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/

/*----------------------Folder Management-------------------------------------*/

static srv_provbox_result_enum srv_provbox_create_folder_by_id(srv_provbox_dir_id_enum dir_id);

static srv_provbox_result_enum srv_provbox_clean_folder_by_id(
                                srv_provbox_dir_id_enum dir_id,
                                MMI_BOOL clean_sub,
                                MMI_BOOL del_sub,
                                S32 max_del_num,
                                S32 *total_del_num);

static srv_provbox_result_enum srv_provbox_clean_folder(
                                const WCHAR *folder,
                                MMI_BOOL clean_sub,
                                MMI_BOOL del_sub,
                                S32 max_del_num,
                                S32 *total_del_num,
                                S32 *level);

static const CHAR * srv_provbox_get_dir_by_box_type(srv_provbox_box_type_enum box_type);

static const CHAR * srv_provbox_get_file_by_id(srv_provbox_file_id_enum file_id);

/*----------------------Appfile-------------------------------------------------*/

static srv_provbox_result_enum srv_provbox_delete_version(srv_provbox_cntx_struct *cntx);

static srv_provbox_result_enum srv_provbox_load_appfile(srv_provbox_appfile_struct *appfile);

static MMI_BOOL srv_provbox_is_right_version(const char *version);

static srv_provbox_result_enum srv_provbox_save_appfile(srv_provbox_appfile_struct *appfile);

static srv_provbox_result_enum srv_provbox_prepare_appfile_data(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_appfile_struct *appfile);

static srv_provbox_result_enum srv_provbox_file_write_file(U16 *filename, void *data_buf, S32 buf_size);

/*----------------------Prov Data File-----------------------------------------*/

static srv_provbox_result_enum srv_provbox_file_create_prov_data_file_name(U32 msg_id, U16 *filename, S32 name_size);

/*----------------------Check File---------------------------------------------*/

static U32 srv_provbox_file_get_check_info_check_sum(srv_provbox_check_info_struct *check_info);

static srv_provbox_result_enum srv_provbox_file_get_check_file_name(
                                srv_provbox_check_type_enum check_type,
                                U32 msg_id,
                                void *buf,
                                S32 buf_size);

/*----------------------Record File Management--------------------------------*/

static srv_provbox_box_type_enum srv_provbox_file_get_box_type_by_file_id(srv_provbox_file_id_enum file_id);

static void srv_provbox_file_free_rec_node(srv_provbox_file_rec_struct *rec_node);

static void srv_provbox_file_free_record_list(S32 hfile);

static srv_provbox_result_enum srv_provbox_file_delete_file(S32 hfile);

static U32 srv_provbox_file_get_next_free_rec_id(srv_provbox_file_mgr_struct *mgr);

static U32 srv_provbox_file_get_max_rec_id(srv_provbox_file_rec_struct *rec_list);

static U32 srv_provbox_file_get_record_check_sum(U32 rec_id, U32 rec_type, U8 *rec_value, S32 value_size);

static srv_provbox_result_enum srv_provbox_file_get_free_record_by_size(
                                srv_provbox_file_mgr_struct *mgr,
                                S32 data_size,
                                srv_provbox_file_rec_struct **rec);

static srv_provbox_result_enum srv_provbox_file_open_file(srv_provbox_file_mgr_struct *mgr, int *ret);

static srv_provbox_result_enum srv_provbox_file_close_file(srv_provbox_file_mgr_struct *mgr);

static srv_provbox_result_enum srv_provbox_file_init_multi_record_node(S32 hfile, S32 load_rec_num);

static srv_provbox_result_enum srv_provbox_file_init_open_file(srv_provbox_file_mgr_struct *mgr);

static srv_provbox_result_enum srv_provbox_file_init_load_record_head(srv_provbox_file_mgr_struct *mgr);

static srv_provbox_result_enum srv_provbox_file_init_load_pack_data(
                                srv_provbox_file_mgr_struct *mgr,
                                srv_provbox_file_rec_head_struct *rec_head);

static srv_provbox_result_enum srv_provbox_file_init_find_next_pack_data(srv_provbox_file_mgr_struct *mgr);

static srv_provbox_result_enum mmi_provox_file_init_create_free_record(
                                srv_provbox_file_mgr_struct *mgr,
                                U32 start_pos,
                                U32 rec_size);

static srv_provbox_result_enum srv_provbox_file_check_record_pack_data(
                                srv_provbox_file_mgr_struct *mgr,
                                srv_provbox_file_rec_head_struct *rec_head,
                                srv_provbox_file_rec_footer_struct *rec_footer);

static srv_provbox_file_rec_struct *srv_provbox_file_create_record(U32 rec_id, U32 start_pos, U32 rec_size);

static srv_provbox_result_enum srv_provbox_file_create_record_and_preappend(
                                srv_provbox_file_mgr_struct *mgr,
                                U32 rec_type,
                                U32 rec_id,
                                U32 start_pos,
                                U32 size);

static srv_provbox_cmp_result_enum srv_provbox_file_find_feasible_free_node_by_size(
                                    srv_provbox_slist_struct *node,
                                    S32 data_size);

static srv_provbox_cmp_result_enum srv_provbox_file_find_node_by_id(srv_provbox_slist_struct *node, void *rec_id);

static srv_provbox_cmp_result_enum srv_provbox_file_find_prev_node_by_pos(srv_provbox_slist_struct *node, void *pos);

static srv_provbox_cmp_result_enum srv_provbox_file_find_next_node_by_pos(srv_provbox_slist_struct *node, void *pos);

static srv_provbox_cmp_result_enum srv_provbox_file_sort_node_by_pos(
                                    srv_provbox_file_rec_struct *rec1,
                                    srv_provbox_file_rec_struct *rec2);

static srv_provbox_result_enum srv_provbox_file_merge_free_record(
                                srv_provbox_file_mgr_struct *mgr,
                                srv_provbox_file_rec_struct *rec);

static srv_provbox_result_enum srv_provbox_file_read_use_record_data(
                                FS_HANDLE fd,
                                U32 rec_id,
                                U32 start_pos,
                                U32 rec_size,
                                void *buf,
                                S32 buf_size);

static srv_provbox_result_enum srv_provbox_file_write_record_data(
                                FS_HANDLE fd,
                                U32 start_pos,
                                void *data,
                                S32 data_size);

static srv_provbox_result_enum srv_provbox_file_write_free_record_data(
                                FS_HANDLE fd,
                                U32 free_rec_id,
                                U32 start_pos,
                                S32 rec_size,
                                U32 *write_size,
                                MMI_BOOL fill_zero);

static srv_provbox_result_enum srv_provbox_file_write_use_record_data(
                                FS_HANDLE fd,
                                U32 use_rec_id,
                                U32 start_pos,
                                void *data,
                                S32 data_size);

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------Folder Management------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_error_code_file_to_provbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  op              [IN]        
 *  file_ret        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_error_code_file_to_provbox(srv_provbox_file_op_type_enum op, int file_ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (file_ret)
    {
        case FS_NO_ERROR:
            result = SRV_PROVBOX_RESULT_OK;
            break;

        case FS_ROOT_DIR_FULL:
        case FS_DISK_FULL:
        case FS_APP_QUOTA_FULL:
            result = SRV_PROVBOX_RESULT_DISK_FULL;
            srv_provbox_mem_send_disk_full_event(srv_provbox_cntx_get_cntx());
            break;

        case FS_INVALID_FILENAME:
        case FS_FILE_NOT_FOUND:
            result = SRV_PROVBOX_RESULT_FILE_NOT_FOUND;
            break;

        case FS_FILE_EXISTS:
            result = SRV_PROVBOX_RESULT_FILE_EXIST;
            break;

        default:
            result = SRV_PROVBOX_RESULT_FILE_OP_FAIL;
            break;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_check_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  max_del_num         [IN]        
 *  total_del_num       [IN]         
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_check_folder(S32 max_del_num, S32 *total_del_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_OK;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* If not support archive feature, just delete all message in archive folder if any */
#ifndef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
    result = srv_provbox_clean_folder_by_box_type(SRV_PROVBOX_BOX_TYPE_ARCHIVE, max_del_num, total_del_num);
    if (result == SRV_PROVBOX_RESULT_CONTINUE)
        return SRV_PROVBOX_RESULT_CONTINUE;
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */ 

    srv_provbox_create_folder_by_id(SRV_PROVBOX_DIR_ID_APP);
    srv_provbox_create_folder_by_id(SRV_PROVBOX_DIR_ID_INBOX);

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
    srv_provbox_create_folder_by_id(SRV_PROVBOX_DIR_ID_ARCHIVE);
#endif

    srv_provbox_create_folder_by_id(SRV_PROVBOX_DIR_ID_EXTRA);
    srv_provbox_create_folder_by_id(SRV_PROVBOX_DIR_ID_TEMP);

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_reset_provbox
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx                [IN]        
 *  max_del_num         [IN]        
 *  total_del_num       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_reset_provbox(srv_provbox_cntx_struct *cntx, S32 max_del_num, S32 *total_del_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* first to delete the version file, so, the folder can be reset completely even power off and power on. */
    srv_provbox_delete_version(cntx);

    result = srv_provbox_clean_folder_by_id(SRV_PROVBOX_DIR_ID_APP, MMI_TRUE, MMI_TRUE, max_del_num, total_del_num);

    if (result == SRV_PROVBOX_RESULT_CONTINUE || max_del_num - *total_del_num <= 0)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_RESET_PROVBOX_CLEAN_FOLDER_CONTINUE,
            max_del_num,
            *total_del_num);
        return SRV_PROVBOX_RESULT_CONTINUE;
    }
    result = srv_provbox_check_folder(max_del_num, total_del_num);
    if (result == SRV_PROVBOX_RESULT_CONTINUE || max_del_num - *total_del_num <= 0)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_RESET_PROVBOX_CLEAN_FOLDER_CONTINUE,
            max_del_num,
            *total_del_num);
        return SRV_PROVBOX_RESULT_CONTINUE;
    }

    result = srv_provbox_reset_version(cntx);

    MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_RESET_PROVBOX_CHECK_FOLDER, max_del_num, *total_del_num, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_clean_folder_by_box_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  box_type            [IN]            
 *  max_del_num         [IN]            
 *  total_del_num       [IN/OUT]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_clean_folder_by_box_type(
                            srv_provbox_box_type_enum box_type,
                            S32 max_del_num,
                            S32 *total_del_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum ret = SRV_PROVBOX_RESULT_INVALID_PARAM;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (box_type)
    {
        case SRV_PROVBOX_BOX_TYPE_INBOX:
            ret = srv_provbox_clean_folder_by_id(
                    SRV_PROVBOX_DIR_ID_INBOX,
                    MMI_TRUE,
                    MMI_TRUE,
                    max_del_num,
                    total_del_num);
            break;


/* Should not wrap this with archive compile option 
  * as it's still used in non-archiver supported sceanrio to apply the folder clear action
  * in srv_provbox_check_folder()
  */

//#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__

        case SRV_PROVBOX_BOX_TYPE_ARCHIVE:
            ret = srv_provbox_clean_folder_by_id(
                    SRV_PROVBOX_DIR_ID_ARCHIVE,
                    MMI_TRUE,
                    MMI_TRUE,
                    max_del_num,
                    total_del_num);
            break;

//#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

        case SRV_PROVBOX_BOX_TYPE_EXTRA:
            ret = srv_provbox_clean_folder_by_id(
                    SRV_PROVBOX_DIR_ID_EXTRA,
                    MMI_TRUE,
                    MMI_TRUE,
                    max_del_num,
                    total_del_num);
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_create_folder_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dir_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_create_folder_by_id(srv_provbox_dir_id_enum dir_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    WCHAR temp[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2((CHAR*) temp, (CHAR*) srv_provbox_get_dir_by_id(dir_id));
    ret = FS_CreateDir((const WCHAR*)temp);
    if (ret != FS_NO_ERROR && ret != FS_FILE_EXISTS)
    {
        MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_CREATE_FODER_BY_ID, dir_id, ret);

        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_CREATE_FOLDER, ret);
    }
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_clean_folder_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dir_id              [IN]            
 *  clean_sub           [IN]            
 *  del_sub             [IN]            
 *  max_del_num         [IN]            
 *  total_del_num       [IN/OUT]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_clean_folder_by_id(
                                srv_provbox_dir_id_enum dir_id,
                                MMI_BOOL clean_sub,
                                MMI_BOOL del_sub,
                                S32 max_del_num,
                                S32 *total_del_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    S32 level = 0;
    WCHAR temp[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (total_del_num == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    mmi_asc_to_ucs2((CHAR*) temp, (CHAR*) srv_provbox_get_dir_by_id(dir_id));
    len = mmi_ucs2strlen((const CHAR*)temp);
    if (len >= 1 && 0 != mmi_ucs2cmp((const CHAR*)(temp + len - 1), (const CHAR*)L"\\"))
    {
        mmi_ucs2cat((CHAR*) temp, (const CHAR*)L"\\");
        len++;
    }
    mmi_asc_to_ucs2((CHAR*) (temp + len), (CHAR*) SRV_PROVBOX_FILE_MSG_INFO_DATA);
    FS_Delete((const WCHAR*)temp);
    mmi_asc_to_ucs2((CHAR*) (temp + len), (CHAR*) SRV_PROVBOX_FILE_MSG_APP_DATA);
    FS_Delete((const WCHAR*)temp);
    temp[len] = '\0';

    if (*total_del_num >= max_del_num)
        return SRV_PROVBOX_RESULT_CONTINUE;

    return srv_provbox_clean_folder((const WCHAR*)temp, clean_sub, del_sub, max_del_num, total_del_num, &level);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_clean_folder
 * DESCRIPTION
 *  
 * PARAMETERS
 *  folder              [IN]            
 *  clean_sub           [IN]            
 *  del_sub             [IN]            
 *  max_del_num         [IN]            
 *  total_del_num       [IN/OUT]        
 *  level               [IN/OUT]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_clean_folder(
                                const WCHAR *folder,
                                MMI_BOOL clean_sub,
                                MMI_BOOL del_sub,
                                S32 max_del_num,
                                S32 *total_del_num,
                                S32 *level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    int h = -1;
    S32 folder_len;
    FS_DOSDirEntry info;
    MMI_BOOL async_del = MMI_FALSE;
    WCHAR path[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];
    WCHAR filename[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (folder == NULL || total_del_num == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    /* ERROR, use must push so many folder tree in this system folder!!! */
    if (*level >= SRV_PROVBOX_FILE_MAX_RECURSION_LEVEL)
        return SRV_PROVBOX_RESULT_FAIL;

    if (*total_del_num >= max_del_num)
        return SRV_PROVBOX_RESULT_CONTINUE;

    folder_len = mmi_ucs2strlen((const CHAR*)folder);
    if (folder_len == 0)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    mmi_ucs2cpy((CHAR*) path, (const CHAR*)folder);
    if (0 != mmi_ucs2cmp((const CHAR*)(path + folder_len - 1), (const CHAR*)L"\\"))
    {
        mmi_ucs2cat((CHAR*) path, (const CHAR*)L"\\");
        folder_len++;
    }
    /* mmi_ucs2cpy shall add '\0'. */
    mmi_ucs2cpy((CHAR*) (path + folder_len), (const CHAR*)L"*");

    h = FS_FindFirst(path, 0, 0, &info, filename, SRV_PROVBOX_PATH_MAX_CHAR_LEN);
    if (h < 0)
        return SRV_PROVBOX_RESULT_OK;

    do
    {
        /* do not handle long path scenario, it's a limitation. */
        if (folder_len + 1 + mmi_ucs2strlen((const CHAR*)filename) <= SRV_PROVBOX_PATH_MAX_CHAR_LEN)
        {
            mmi_ucs2cpy((CHAR*) (path + folder_len), (const CHAR*)filename);

            if ((info.Attributes & FS_ATTR_DIR) &&
                0 != mmi_ucs2cmp((const CHAR*)filename, (const CHAR*)SRV_PROVBOX_FILE_CUR_DIR) &&
                0 != mmi_ucs2cmp((const CHAR*)filename, (const CHAR*)SRV_PROVBOX_FILE_PARENT_DIR))
            {
                if (del_sub != MMI_FALSE || clean_sub != MMI_FALSE)
                {
                    *level += 1;
                    srv_provbox_clean_folder(
                        (const WCHAR*)path,
                        clean_sub,
                        del_sub,
                        max_del_num,
                        total_del_num,
                        level);
                    *level -= 1;

                    if (max_del_num >= 0 && *total_del_num >= max_del_num)
                    {
                        async_del = MMI_TRUE;
                        break;
                    }

                }
                if (del_sub)
                {
                    if (FS_NO_ERROR == FS_RemoveDir((const WCHAR*)path))
                        *total_del_num += 1;
                }
            }
            else
            {
                if (FS_NO_ERROR == FS_Delete(path))
                    *total_del_num += 1;
            }
        }
        if (max_del_num >= 0 && *total_del_num >= max_del_num)
        {
            async_del = MMI_TRUE;
            break;
        }
        ret = FS_FindNext(h, &info, filename, SRV_PROVBOX_PATH_MAX_CHAR_LEN);
    } while (ret == FS_NO_ERROR);

    FS_FindClose(h);

    if (async_del == MMI_TRUE)
        return SRV_PROVBOX_RESULT_CONTINUE;

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_get_dir_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dir_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
const CHAR * srv_provbox_get_dir_by_id(srv_provbox_dir_id_enum dir_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dir_id)
    {
        case SRV_PROVBOX_DIR_ID_APP:
            return SRV_PROVBOX_DIR_APP;

        case SRV_PROVBOX_DIR_ID_INBOX:
            return SRV_PROVBOX_DIR_INBOX;

/* Should not wrap this with archive compile option as
 *  it's still used in non-archiver supported sceanrio to apply the folder clear action
 *  in srv_provbox_check_folder()
 */

//#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
        case SRV_PROVBOX_DIR_ID_ARCHIVE:
            return SRV_PROVBOX_DIR_ARCHIVE;
//#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

        case SRV_PROVBOX_DIR_ID_EXTRA:
            return SRV_PROVBOX_DIR_EXTRA;

        case SRV_PROVBOX_DIR_ID_TEMP:
            return SRV_PROVBOX_DIR_TEMP;

        default:
            MMI_ASSERT(0);
            break;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_get_dir_by_box_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  box_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static const CHAR * srv_provbox_get_dir_by_box_type(srv_provbox_box_type_enum box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const CHAR * dir = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (box_type)
    {
        case SRV_PROVBOX_BOX_TYPE_INBOX:
            dir = SRV_PROVBOX_DIR_INBOX;
            break;

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
        case SRV_PROVBOX_BOX_TYPE_ARCHIVE:
            dir = SRV_PROVBOX_DIR_ARCHIVE;
            break;
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

        case SRV_PROVBOX_BOX_TYPE_EXTRA:
            dir =  SRV_PROVBOX_DIR_EXTRA;
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
    return dir;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_get_file_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static const CHAR * srv_provbox_get_file_by_id(srv_provbox_file_id_enum file_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const CHAR *filename = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (file_id)
    {
        case SRV_PROVBOX_FILE_ID_APPFILE:
            filename = SRV_PROVBOX_FILE_APPFILE;
            break;

        case SRV_PROVBOX_FILE_ID_CHECKFILE:
            filename = SRV_PROVBOX_FILE_MSG_CHECK;
            break;

        case SRV_PROVBOX_FILE_ID_IMSG_INFO_DATA:
            filename = SRV_PROVBOX_FILE_IMSG_INFO_DATA;
            break;

        case SRV_PROVBOX_FILE_ID_IMSG_APP_DATA:
            filename = SRV_PROVBOX_FILE_IMSG_APP_DATA;
            break;

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
        case SRV_PROVBOX_FILE_ID_AMSG_INFO_DATA:
            filename = SRV_PROVBOX_FILE_AMSG_INFO_DATA;
            break;

        case SRV_PROVBOX_FILE_ID_AMSG_APP_DATA:
            filename = SRV_PROVBOX_FILE_AMSG_APP_DATA;
            break;
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

        case SRV_PROVBOX_FILE_ID_EMSG_INFO_DATA:
            filename = SRV_PROVBOX_FILE_EMSG_INFO_DATA;
            break;

        case SRV_PROVBOX_FILE_ID_EMSG_APP_DATA:
            filename = SRV_PROVBOX_FILE_EMSG_APP_DATA;
            break;

        default:
            MMI_ASSERT(0);
            break;
    }

    MMI_ASSERT(mmi_ucs2strlen((const CHAR*)filename) <= SRV_PROVBOX_PATH_MAX_CHAR_LEN);

    return filename;

}

/*----------------------Appfile & Check file----------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_check_version
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_check_version(srv_provbox_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    srv_provbox_appfile_struct appfile; /* it's small enough not to malloc dynmic memory now */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_provbox_load_appfile(&appfile);
    if (result != SRV_PROVBOX_RESULT_OK)
        return SRV_PROVBOX_RESULT_ERR_VERSION;
    if (MMI_FALSE == srv_provbox_is_right_version((const char*)appfile.ver_tag.version))
        return SRV_PROVBOX_RESULT_ERR_VERSION;
    cntx->max_msg_id = appfile.base_info_tag.info.max_msg_id;
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_reset_version
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_reset_version(srv_provbox_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    srv_provbox_appfile_struct appfile; /* it's small enough not to malloc dynamic memory now */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* always think the whole @ProvBox are deleted, 
       at least the MsgInfo.dat and AppData.dat are deleted,
       so, the cntx->max_msg_id can be reset now. */
    cntx->max_msg_id = 0;
    result = srv_provbox_prepare_appfile_data(cntx, &appfile);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;
    result = srv_provbox_save_appfile(&appfile);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_save_max_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_save_max_msg_id(srv_provbox_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    srv_provbox_appfile_struct appfile; /* it's small enough not to malloc dynamic memory now */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_provbox_prepare_appfile_data(cntx, &appfile);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;
    result = srv_provbox_save_appfile(&appfile);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_delete_version
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_delete_version(srv_provbox_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    WCHAR temp[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    mmi_asc_to_ucs2((CHAR*) temp, (CHAR*) srv_provbox_get_file_by_id(SRV_PROVBOX_FILE_ID_APPFILE));
    ret = FS_Delete((const WCHAR*)temp);
    return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_DELETE, ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_load_appfile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  appfile     [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_load_appfile(srv_provbox_appfile_struct *appfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    FS_HANDLE fd;
    UINT read_len;
    WCHAR temp[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (appfile == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    mmi_asc_to_ucs2((CHAR*) temp, (CHAR*) srv_provbox_get_file_by_id(SRV_PROVBOX_FILE_ID_APPFILE));

    fd = FS_Open((const WCHAR*)temp, FS_READ_ONLY);
    if (fd < 0)
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_OPEN, fd);

    ret = FS_Read(fd, (void*)appfile, (UINT) sizeof(srv_provbox_appfile_struct), (UINT*) & read_len);
    FS_Close(fd);

    if (ret != FS_NO_ERROR || read_len != sizeof(srv_provbox_appfile_struct))
    {
        if (ret == FS_NO_ERROR)
            return SRV_PROVBOX_RESULT_FILE_ERR_SIZE;
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_READ, ret);
    }

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_is_right_version
 * DESCRIPTION
 *  
 * PARAMETERS
 *  version     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_provbox_is_right_version(const char *version)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = strcmp((const char*)version, (const char*)SRV_PROVBOX_VERSION);
    if (ret != 0)
        return MMI_FALSE;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_save_appfile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  appfile     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_save_appfile(srv_provbox_appfile_struct *appfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    FS_HANDLE fd;
    UINT write_len;
    WCHAR temp[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (appfile == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    mmi_asc_to_ucs2((CHAR*) temp, (CHAR*) srv_provbox_get_file_by_id(SRV_PROVBOX_FILE_ID_APPFILE));

    fd = FS_Open((const WCHAR*)temp, FS_CREATE | FS_READ_WRITE);
    if (fd < 0)
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_OPEN, fd);

    ret = FS_Write(fd, (void*)appfile, (UINT) sizeof(srv_provbox_appfile_struct), (UINT*) & write_len);
    FS_Close(fd);

    if (ret != FS_NO_ERROR || write_len != sizeof(srv_provbox_appfile_struct))
    {
        if (ret == FS_NO_ERROR)
            return SRV_PROVBOX_RESULT_FILE_ERR_SIZE;
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_WRITE, ret);
    }

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_prepare_appfile_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cntx        [IN]        
 *  appfile     [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_prepare_appfile_data(
                                srv_provbox_cntx_struct *cntx,
                                srv_provbox_appfile_struct *appfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cntx == NULL || appfile == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    memset(appfile, 0x0, sizeof(srv_provbox_appfile_struct));
    appfile->ver_tag.tag_id = SRV_PROVBOX_APPFILE_TAG_VERTION;
    appfile->ver_tag.value_len = SRV_PROVBOX_VERSION_MAX_CHAR_LEN + 4;
    strcpy(appfile->ver_tag.version, SRV_PROVBOX_VERSION);

    appfile->base_info_tag.tag_id = SRV_PROVBOX_APPFILE_TAG_BASE_INFO;
    appfile->base_info_tag.value_len = sizeof(srv_provbox_appfile_base_info_struct);
    appfile->base_info_tag.info.max_msg_id = cntx->max_msg_id;
    return SRV_PROVBOX_RESULT_OK;
}

/*----------------------Prov Data File----------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_create_prov_data_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  filename        [OUT]       
 *  name_size       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_create_prov_data_file_name(U32 msg_id, U16 *filename, S32 name_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 tmp[30];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (name_size < SRV_PROVBOX_PATH_MAX_BUFF_SIZE)
        return SRV_PROVBOX_RESULT_SMALL_BUF;

    sprintf((char*)tmp, "%d", msg_id);

    strcat((char*)tmp, SRV_PROVBOX_FILE_MSG_PROV_DATA_POSTFIX);

    mmi_asc_to_ucs2((CHAR*) filename, (CHAR*) tmp);
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_get_file_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  size            [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_file_get_file_size(U16 *filename, S32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    FS_HANDLE fd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL || size == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;
    *size = -1;
    fd = FS_Open((const WCHAR*)filename, FS_CREATE | FS_READ_WRITE);
    if (fd < 0)
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_OPEN, fd);

    ret = FS_GetFileSize(fd, (UINT*) size);
    FS_Close(fd);
    if (ret != FS_NO_ERROR)
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_GET_FILE_SIZE, ret);
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_read_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  data_buf        [OUT]       
 *  buf_size        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_file_read_file(U16 *filename, void *data_buf, S32 *buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    FS_HANDLE fd;
    UINT read_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL || data_buf == NULL || buf_size == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    fd = FS_Open((const WCHAR*)filename, FS_READ_ONLY);
    if (fd < 0)
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_OPEN, fd);
    ret = FS_GetFileSize(fd, &read_size);
    if (ret != FS_NO_ERROR)
    {
        FS_Close(fd);
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_GET_FILE_SIZE, ret);
    }
    if (*buf_size < (S32) read_size)
    {
        FS_Close(fd);
        *buf_size = read_size;
        return SRV_PROVBOX_RESULT_SMALL_BUF;
    }
    ret = FS_Read(fd, data_buf, *buf_size, &read_size);
    FS_Close(fd);
    if (ret != FS_NO_ERROR || *buf_size != (S32) read_size)
    {
        if (ret == FS_NO_ERROR)
            return SRV_PROVBOX_RESULT_FILE_ERR_SIZE;
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_READ, ret);
    }
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_write_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]        
 *  data_buf        [IN]        
 *  buf_size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_write_file(U16 *filename, void *data_buf, S32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    FS_HANDLE fd;
    UINT write_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (filename == NULL || data_buf == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    fd = FS_Open((const WCHAR*)filename, FS_READ_WRITE | FS_CREATE);
    if (fd < 0)
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_OPEN, fd);

    ret = FS_Write(fd, data_buf, buf_size, &write_size);
    FS_Close(fd);
    if (ret != FS_NO_ERROR || buf_size != (S32) write_size)
    {
        if (ret == FS_NO_ERROR)
            return SRV_PROVBOX_RESULT_FILE_ERR_SIZE;
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_WRITE, ret);
    }
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_get_prov_data_filename
 * DESCRIPTION
 *  
 * PARAMETERS
 *  box_type        [IN]        
 *  msg_id          [IN]        
 *  filename        [OUT]       
 *  name_size       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_file_get_prov_data_filename(
                            srv_provbox_box_type_enum box_type,
                            U32 msg_id,
                            U16 *filename,
                            S32 name_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    U16 buffer[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_provbox_file_create_prov_data_file_name(msg_id, buffer, SRV_PROVBOX_PATH_MAX_BUFF_SIZE);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;

    mmi_asc_to_ucs2((CHAR*) filename, (CHAR*) srv_provbox_get_dir_by_box_type(box_type));
    mmi_ucs2cat((CHAR*) filename, (const CHAR*)buffer);
    return SRV_PROVBOX_RESULT_OK;
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
#endif /* 0 */

/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_save_prov_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  box_type            [IN]        
 *  msg_id              [IN]        
 *  prov_data           [OUT]       
 *  prov_data_size      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_file_save_prov_data(
                            srv_provbox_box_type_enum box_type,
                            U32 msg_id,
                            void *prov_data,
                            S32 prov_data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    FS_HANDLE fd;
    UINT write_len;
    U16 filename[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_provbox_file_get_prov_data_filename(box_type, msg_id, (U16*) filename, SRV_PROVBOX_PATH_MAX_BUFF_SIZE);
    fd = FS_Open((const WCHAR*)filename, FS_CREATE | FS_READ_WRITE);
    if (fd < 0)
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_OPEN, fd);

    ret = FS_Write(fd, prov_data, (UINT) prov_data_size, &write_len);
    FS_Close(fd);
    if (ret != FS_NO_ERROR || (S32) write_len != prov_data_size)
    {
        FS_Delete((const WCHAR*)filename);
        if (ret == FS_NO_ERROR)
            return SRV_PROVBOX_RESULT_FILE_ERR_SIZE;
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_WRITE, ret);
    }
    return SRV_PROVBOX_RESULT_OK;
}

/*----------------------Check File--------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_get_check_info_check_sum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  check_info      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U32 srv_provbox_file_get_check_info_check_sum(srv_provbox_check_info_struct *check_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size;
    U32 check_sum;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (check_info == NULL)
        return 0;
    size = check_info->info_pos + check_info->app_pos + check_info->app_data_size + check_info->prov_data_size;
    if (size < 0)
        size = 0 - size;
    check_sum = check_info->check_type + check_info->box_type + check_info->msg_id;
    check_sum += (U32) size + 1;
    return check_sum;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_set_check_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  check_info          [IN]        
 *  check_type          [IN]        
 *  box_type            [IN]        
 *  msg_id              [IN]        
 *  info_pos            [IN]        
 *  app_pos             [IN]        
 *  app_data_size       [IN]        
 *  prov_data_size      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_file_set_check_info(
                            srv_provbox_check_info_struct *check_info,
                            U8 check_type,
                            U8 box_type,
                            U32 msg_id,
                            S32 info_pos,
                            S32 app_pos,
                            S32 app_data_size,
                            S32 prov_data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (check_info == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    check_info->check_type = check_type;
    check_info->box_type = box_type;
    check_info->reserved = 0;
    check_info->msg_id = msg_id;
    check_info->info_pos = info_pos;
    check_info->app_pos = app_pos;
    check_info->app_data_size = app_data_size;
    check_info->prov_data_size = prov_data_size;
    check_info->valid = 1;
    check_info->check_sum = srv_provbox_file_get_check_info_check_sum(check_info);
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_get_check_file_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  check_type      [IN]        
 *  msg_id          [IN]        
 *  buf             [OUT]       
 *  buf_size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_get_check_file_name(
                                  srv_provbox_check_type_enum check_type,
                                  U32 msg_id,
                                  void *buf,
                                  S32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const CHAR *tmp_dir;
    U16 utf8_name[SRV_PROVBOX_FILE_CHECK_FILENAME_MAX_CHAR_LEN];
    U16 ucs2_name[SRV_PROVBOX_FILE_CHECK_FILENAME_MAX_CHAR_LEN] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buf == NULL || buf_size < SRV_PROVBOX_PATH_MAX_BUFF_SIZE)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    tmp_dir = srv_provbox_get_dir_by_id(SRV_PROVBOX_DIR_ID_TEMP);
    mmi_asc_to_ucs2((CHAR*) buf, (CHAR*)tmp_dir);

    switch (check_type)
    {
        case SRV_PROVBOX_CHECK_TYPE_SAVE_NEW:
        case SRV_PROVBOX_CHECK_TYPE_MOVE:
        case SRV_PROVBOX_CHECK_TYPE_DELETE:
            sprintf((char*)utf8_name, SRV_PROVBOX_FILE_CHECK_FILE_NAME_MSG, msg_id);
            mmi_asc_to_ucs2((CHAR*) ucs2_name, (CHAR*) utf8_name);
            mmi_ucs2cat((CHAR*) buf, (const CHAR*)ucs2_name);
            break;

        case SRV_PROVBOX_CHECK_TYPE_DELETE_ALL:
            mmi_ucs2cat((CHAR*) buf, (const CHAR*)SRV_PROVBOX_FILE_CHECK_FILENAME_DELETEALL);
            break;

        case SRV_PROVBOX_CHECK_TYPE_RESTORE_FACTORY:
            mmi_ucs2cat((CHAR*) buf, (const CHAR*)SRV_PROVBOX_FILE_CHECK_FILENAME_RESTORE);

            break;

        default:
            MMI_ASSERT(0);
            break;
    }

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_read_check_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename        [IN]
 *  check_type      [IN]
 *  msg_id          [IN]
 *  check_info      [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_file_read_check_file(U16 *filename, srv_provbox_check_type_enum check_type, U32 msg_id, 
                            srv_provbox_check_info_struct *check_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *name = (U16*)filename;
    srv_provbox_result_enum result;
    S32 size = sizeof(srv_provbox_check_info_struct);
    U16 new_name[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (check_info == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;
    if (filename == NULL)
    {
        srv_provbox_file_get_check_file_name(
         check_type,
         msg_id,
         new_name,
         SRV_PROVBOX_PATH_MAX_BUFF_SIZE);
        name = (U16*)new_name;
    }
   
    result = srv_provbox_file_read_file(name, check_info, &size);

    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_READ_CHECK_FILE,
            result,
            check_info->check_type,
            check_info->box_type,
            check_info->msg_id);

        srv_provbox_file_set_check_info(
            check_info,
            SRV_PROVBOX_CHECK_TYPE_UNKNOWN,
            SRV_PROVBOX_BOX_TYPE_UNKNOWN,
            SRV_PROVBOX_INVALID_MSG_ID,
            0,
            0,
            -1,
            -1);
        check_info->valid = 0;
        return result;

    }
    if (check_info->msg_id != msg_id || 
        check_info->check_sum != srv_provbox_file_get_check_info_check_sum(check_info))
    {
        srv_provbox_file_set_check_info(
            check_info,
            SRV_PROVBOX_CHECK_TYPE_UNKNOWN,
            SRV_PROVBOX_BOX_TYPE_UNKNOWN,
            SRV_PROVBOX_INVALID_MSG_ID,
            0,
            0,
            -1,
            -1);
        check_info->valid = 0;
        return SRV_PROVBOX_RESULT_PARSE_ERR;
    }
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_write_check_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  check_info      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_file_write_check_file(srv_provbox_check_info_struct *check_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    U16 filename[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_provbox_file_get_check_file_name(
        (srv_provbox_check_type_enum)check_info->check_type,
        check_info->msg_id,
        filename,
        SRV_PROVBOX_PATH_MAX_BUFF_SIZE);
    result = srv_provbox_file_write_file((U16*) filename, check_info, sizeof(srv_provbox_check_info_struct));

    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_WRITE_CHECK_FILE,
            check_info->check_type,
            check_info->box_type,
            check_info->msg_id,
            result);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_delete_check_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  check_type      [IN]        
 *  msg_id          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_file_delete_check_file(srv_provbox_check_type_enum check_type, U32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    U16 filename[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_provbox_file_get_check_file_name(check_type, msg_id, filename, SRV_PROVBOX_PATH_MAX_BUFF_SIZE);
    ret = FS_Delete((const WCHAR*)filename);
    return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_DELETE, ret);
}

/*----------------------Record File-------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_get_info_file_id_by_box_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  box_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_file_id_enum srv_provbox_file_get_info_file_id_by_box_type(srv_provbox_box_type_enum box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_file_id_enum file_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (box_type)
    {
        case SRV_PROVBOX_BOX_TYPE_INBOX:
            file_id = SRV_PROVBOX_FILE_ID_IMSG_INFO_DATA;
            break;

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__            
        case SRV_PROVBOX_BOX_TYPE_ARCHIVE:
            file_id = SRV_PROVBOX_FILE_ID_AMSG_INFO_DATA;
            break;
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

        case SRV_PROVBOX_BOX_TYPE_EXTRA:
            file_id = SRV_PROVBOX_FILE_ID_EMSG_INFO_DATA;
            break;

        default:
            MMI_ASSERT(0);
            file_id = SRV_PROVBOX_FILE_ID_IMSG_INFO_DATA;
            break;
    }
    return file_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_get_app_file_id_by_box_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  box_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_file_id_enum srv_provbox_file_get_app_file_id_by_box_type(srv_provbox_box_type_enum box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_file_id_enum file_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (box_type)
    {
        case SRV_PROVBOX_BOX_TYPE_INBOX:
            file_id = SRV_PROVBOX_FILE_ID_IMSG_APP_DATA;
            break;

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__            
        case SRV_PROVBOX_BOX_TYPE_ARCHIVE:
            file_id = SRV_PROVBOX_FILE_ID_AMSG_APP_DATA;
            break;
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

        case SRV_PROVBOX_BOX_TYPE_EXTRA:
            file_id = SRV_PROVBOX_FILE_ID_EMSG_APP_DATA;
            break;

        default:
            MMI_ASSERT(0);
            file_id = SRV_PROVBOX_FILE_ID_IMSG_INFO_DATA;
            break;
    }
    return file_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_get_box_type_by_file_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_id     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_box_type_enum srv_provbox_file_get_box_type_by_file_id(srv_provbox_file_id_enum file_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_box_type_enum box_type = SRV_PROVBOX_BOX_TYPE_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (file_id)
    {
        case SRV_PROVBOX_FILE_ID_IMSG_INFO_DATA:
        case SRV_PROVBOX_FILE_ID_IMSG_APP_DATA:
            box_type = SRV_PROVBOX_BOX_TYPE_INBOX;
            break;

#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
        case SRV_PROVBOX_FILE_ID_AMSG_INFO_DATA:
        case SRV_PROVBOX_FILE_ID_AMSG_APP_DATA:
            box_type = SRV_PROVBOX_BOX_TYPE_ARCHIVE;
            break;
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

        case SRV_PROVBOX_FILE_ID_EMSG_INFO_DATA:
        case SRV_PROVBOX_FILE_ID_EMSG_APP_DATA:
            box_type = SRV_PROVBOX_BOX_TYPE_EXTRA;
            break;

        default:
            MMI_ASSERT(0);
            break;
    }
    return box_type;
}

/*----------------------Reocord file------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_new_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  init_size       [IN]        
 *  defrag_size     [IN]        
 *  inc_size        [IN]        
 *  file_id         [IN]        
 *  max_rec_num     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_provbox_file_new_handle(
        S32 init_size,
        S32 defrag_size,
        S32 inc_size,
        srv_provbox_file_id_enum file_id,
        U32 max_rec_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_file_mgr_struct *mgr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mgr = SRV_PROVBOX_ALLOC_TYPE(srv_provbox_file_mgr_struct);

    MMI_ASSERT(mgr != NULL);

    if (mgr == NULL)
        return 0;

    mgr->flag = 0;
    mgr->init_size = init_size > 0 ? init_size : SRV_PROVBOX_FILE_INIT_SIZE;
    mgr->defrag_size = defrag_size > 0 ? defrag_size : SRV_PROVBOX_FILE_DEFRAG_SIZE;
    mgr->inc_size = inc_size > 0 ? inc_size : SRV_PROVBOX_FILE_INC_SIZE;
    mgr->file_id = file_id;

    mgr->total_size = 0;
    mgr->free_size = 0;
    mgr->file_size = 0;
    mgr->max_rec_num = max_rec_num;
    mgr->fd = -1;
    mgr->start_pos = 0;
    mgr->load_rec_num = 0;
    mgr->cur_free_rec_id = 0;

    mgr->use_rec_num = 0;
    mgr->use_list = NULL;
    mgr->free_list = NULL;
    mgr->cur_use_rec = NULL;

    return (S32) mgr;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_free_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hfile       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_file_free_handle(S32 hfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_file_mgr_struct *mgr = (srv_provbox_file_mgr_struct*) hfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hfile == 0)
        return SRV_PROVBOX_RESULT_OK;
    srv_provbox_file_free_record_list(hfile);
    srv_provbox_file_close_file(mgr);
    SRV_PROVBOX_FREE(mgr);
    return SRV_PROVBOX_RESULT_OK;
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
#endif /* 0 */

/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_get_record_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hfile       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_provbox_file_get_record_num(S32 hfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((srv_provbox_file_mgr_struct*) hfile)->use_rec_num;

}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_get_max_use_rec_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hfile       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_provbox_file_get_max_use_rec_id(S32 hfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_file_mgr_struct *mgr = (srv_provbox_file_mgr_struct*) hfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hfile == 0)
        return 0;

    return srv_provbox_file_get_max_rec_id(mgr->use_list);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_init_record_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hfile           [IN]        
 *  load_num        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_file_init_record_list(S32 hfile, S32 load_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    srv_provbox_file_mgr_struct *mgr = (srv_provbox_file_mgr_struct*) hfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mgr == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    result = srv_provbox_file_init_multi_record_node(hfile, load_num);
    if (result == SRV_PROVBOX_RESULT_CONTINUE)
        return SRV_PROVBOX_RESULT_CONTINUE;

    /* read all content success or any error, stop to read it */
    mgr->use_list =
        (srv_provbox_file_rec_struct*) srv_provbox_slist_reverse((srv_provbox_slist_struct*) mgr->use_list);
    mgr->free_list =
        (srv_provbox_file_rec_struct*) srv_provbox_slist_reverse((srv_provbox_slist_struct*) mgr->free_list);

    mgr->cur_free_rec_id = srv_provbox_file_get_max_rec_id(mgr->free_list);

    MMI_TRACE(
        SRV_PROVBOX_TRC_INFO,
        SRV_PROVBOX_TRC_FILE_INIT_RECORD_LIST,
        mgr->file_id,
        mgr->use_rec_num,
        srv_provbox_slist_get_length((srv_provbox_slist_struct*) mgr->use_list),
        mgr->file_size,
        mgr->free_size);

    /* try to remove flag again. */
    SRV_PPOVBOX_CLEAR_FLAG(mgr->flag, SRV_PROVBOX_FILE_FLAG_FINDING_PACK);
    mgr->start_pos = 0;

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_delete_record_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hfile       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_file_delete_record_list(S32 hfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_provbox_file_free_record_list(hfile);
    return srv_provbox_file_delete_file(hfile);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_cursor_read_index_record
 * DESCRIPTION
 *  can not use add/delete operation when use cursor to read a record.
 *  always use srv_provbox_file_cursor_close to close the resource.
 * PARAMETERS
 *  hfile           [IN]        
 *  rec_id          [IN]        
 *  data_buf        [OUT]       
 *  buf_size        [IN]        
 *  data_size       [OUT]       
 *  index           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_file_cursor_read_index_record(
                            S32 hfile,
                            U32 *rec_id,
                            void *data_buf,
                            S32 buf_size,
                            S32 *data_size,
                            U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    srv_provbox_result_enum result;
    srv_provbox_file_mgr_struct *mgr = (srv_provbox_file_mgr_struct*) hfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mgr == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (rec_id)
        *rec_id = 0;
    if (data_size)
        *data_size = 0;

    mgr->cur_use_rec =
        (srv_provbox_file_rec_struct*) srv_provbox_slist_get_node_by_index(
                                        (srv_provbox_slist_struct*) mgr->use_list,
                                        index);
    if (mgr->cur_use_rec == NULL)
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    if (rec_id)
        *rec_id = mgr->cur_use_rec->rec_id;
    if (data_size)
        *data_size = mgr->cur_use_rec->rec_size - SRV_PROVBOX_FILE_REC_PACK_SIZE;
    if (data_buf == NULL || buf_size < (S32) mgr->cur_use_rec->rec_size - (S32) SRV_PROVBOX_FILE_REC_PACK_SIZE)
    {
        MMI_ASSERT(data_size);
        return SRV_PROVBOX_RESULT_SMALL_BUF;
    }

    /* do not close file in this function, please close file in srv_provbox_file_cursor_read_record_close */

    MMI_ASSERT(mgr->fd < 0);

    result = srv_provbox_file_open_file(mgr, &ret);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;

    result = srv_provbox_file_read_use_record_data(
                mgr->fd,
                mgr->cur_use_rec->rec_id,
                mgr->cur_use_rec->start_pos,
                (S32) mgr->cur_use_rec->rec_size,
                data_buf,
                buf_size);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_cursor_read_next_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hfile           [IN]        
 *  rec_id          [IN]        
 *  data_buf        [OUT]       
 *  buf_size        [IN]        
 *  data_size       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_file_cursor_read_next_record(
                            S32 hfile,
                            U32 *rec_id,
                            void *data_buf,
                            S32 buf_size,
                            S32 *data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_result_enum result;
    srv_provbox_file_mgr_struct *mgr = (srv_provbox_file_mgr_struct*) hfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mgr == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (rec_id)
        *rec_id = 0;
    if (data_size)
        *data_size = 0;

    mgr->cur_use_rec = mgr->cur_use_rec->next;
    if (mgr->cur_use_rec == NULL)
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    if (rec_id)
        *rec_id = mgr->cur_use_rec->rec_id;
    if (data_size)
        *data_size = mgr->cur_use_rec->rec_size - SRV_PROVBOX_FILE_REC_PACK_SIZE;

    if (data_buf == NULL || buf_size < (S32) mgr->cur_use_rec->rec_size - (S32) SRV_PROVBOX_FILE_REC_PACK_SIZE)
    {
        MMI_ASSERT(data_size);
        return SRV_PROVBOX_RESULT_SMALL_BUF;
    }
    result = srv_provbox_file_read_use_record_data(
                mgr->fd,
                mgr->cur_use_rec->rec_id,
                mgr->cur_use_rec->start_pos,
                (S32) mgr->cur_use_rec->rec_size,
                data_buf,
                buf_size);
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_cursor_read_record_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hfile       [IN]        
 *  index       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_file_cursor_read_record_close(S32 hfile, U32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    srv_provbox_file_mgr_struct *mgr = (srv_provbox_file_mgr_struct*) hfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mgr == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    srv_provbox_file_close_file(mgr);

    if (index != NULL)
    {
        if (mgr->cur_use_rec == NULL)
            *index = 0;
        else
        {
            ret = srv_provbox_slist_get_index(
                    (srv_provbox_slist_struct*) mgr->use_list,
                    (srv_provbox_slist_struct*) mgr->cur_use_rec,
                    index);

            if (ret == MMI_FALSE)
                *index = 0;
        }
    }

    mgr->cur_use_rec = mgr->use_list;
    mgr->load_rec_num = 0;
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_read_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hfile           [IN]        
 *  rec_id          [IN]        
 *  data_buf        [OUT]       
 *  buf_size        [IN]        
 *  data_size       [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_file_read_record(
                            S32 hfile,
                            U32 rec_id,
                            void *data_buf,
                            S32 buf_size,
                            S32 *data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    srv_provbox_result_enum result;
    srv_provbox_file_rec_struct *rec;
    srv_provbox_file_mgr_struct *mgr = (srv_provbox_file_mgr_struct*) hfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mgr == NULL || data_buf == NULL || buf_size <= 0)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (data_size)
        *data_size = 0;

    rec = (srv_provbox_file_rec_struct*) srv_provbox_slist_get_node_by_data(
                                            (srv_provbox_slist_struct*) mgr->use_list,
                                            (SRV_PROVBOX_SLIST_COMPARE_NODE_FUNC) srv_provbox_file_find_node_by_id,
                                            (void*)rec_id);
    if (rec == NULL)
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    MMI_ASSERT(rec->rec_size <= SRV_PROVBOX_FILE_MAX_REC_SIZE);

    if (data_size)
        *data_size = rec->rec_size - SRV_PROVBOX_FILE_REC_PACK_SIZE;
    if ((S32) (rec->rec_size - SRV_PROVBOX_FILE_REC_PACK_SIZE) < buf_size)
        return SRV_PROVBOX_RESULT_SMALL_BUF;

    result = srv_provbox_file_open_file(mgr, &ret);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;
    result = srv_provbox_file_read_use_record_data(
                mgr->fd,
                rec->rec_id,
                rec->start_pos,
                (S32) rec->rec_size,
                data_buf,
                buf_size);
    srv_provbox_file_close_file(mgr);
    return result;
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
#endif /* 0 */

/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_write_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hfile           [IN]        
 *  rec_id          [IN]        
 *  rec_data        [IN]        
 *  data_size       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_file_write_record(S32 hfile, U32 rec_id, void *rec_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    U32 write_size;
    srv_provbox_result_enum result;
    srv_provbox_file_rec_struct *free_rec;
    srv_provbox_file_rec_struct *use_rec = NULL;
    srv_provbox_file_rec_struct new_free_rec = {0};
    srv_provbox_file_rec_head_struct empty_rec_head = {0};
    U32 need_rec_size = SRV_PROVBOX_FILE_GET_REC_SIZE(data_size);
    srv_provbox_file_mgr_struct *mgr = (srv_provbox_file_mgr_struct*) hfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mgr == NULL || rec_data == NULL || data_size <= 0 || data_size > SRV_PROVBOX_FILE_MAX_REC_SIZE)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    /* open file */
    result = srv_provbox_file_open_file(mgr, &ret);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(SRV_PROVBOX_TRC_INFO, SRV_PROVBOX_TRC_FILE_WRITE_RECORD_OPEN, mgr->file_id, rec_id, data_size);
        return result;
    }
    /* get a free record */
    result = srv_provbox_file_get_free_record_by_size(mgr, data_size, &free_rec);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        srv_provbox_file_close_file(mgr);
        return SRV_PROVBOX_RESULT_MEM_FULL;
    }

    MMI_ASSERT(free_rec && (free_rec->rec_size == need_rec_size ||
                            free_rec->rec_size >= need_rec_size + SRV_PROVBOX_FILE_REC_PACK_SIZE));

    /* create a new use record */
    if (free_rec->rec_size == need_rec_size)
    {
        use_rec = free_rec;
    }
    else if (free_rec->rec_size >= need_rec_size + SRV_PROVBOX_FILE_REC_PACK_SIZE)
    {
        use_rec = srv_provbox_file_create_record(rec_id, free_rec->start_pos, (U32) need_rec_size);
        if (use_rec == NULL)
        {
            srv_provbox_file_close_file(mgr);
            return SRV_PROVBOX_RESULT_MEM_FULL;
        }

        /* split the free record to a use record and a smaller free record, write the new free record to file */
        new_free_rec.rec_id = srv_provbox_file_get_next_free_rec_id(mgr);
        new_free_rec.start_pos = use_rec->start_pos + use_rec->rec_size;
        new_free_rec.rec_size = free_rec->rec_size - use_rec->rec_size;
        new_free_rec.next = NULL;

        result = srv_provbox_file_write_free_record_data(
                    mgr->fd,
                    new_free_rec.rec_id,
                    new_free_rec.start_pos,
                    new_free_rec.rec_size,
                    &write_size,
                    MMI_FALSE);

        if (result != SRV_PROVBOX_RESULT_OK)
        {
            MMI_TRACE(
                SRV_PROVBOX_TRC_INFO,
                SRV_PROVBOX_TRC_FILE_WRITE_RECORD_WRITE_FREE,
                mgr->file_id,
                rec_id,
                data_size,
                new_free_rec.start_pos,
                new_free_rec.rec_size,
                result);

            SRV_PROVBOX_FREE(use_rec);
            srv_provbox_file_close_file(mgr);
            return result;
        }
    }

    result = srv_provbox_file_write_use_record_data(mgr->fd, rec_id, free_rec->start_pos, rec_data, data_size);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_WRITE_RECORD_WRITE_USE,
            mgr->file_id,
            rec_id,
            free_rec->start_pos,
            data_size,
            result);

        /* try reset the new free record header */
        if (free_rec->rec_size > need_rec_size)
        {
            srv_provbox_file_write_record_data(
                mgr->fd,
                new_free_rec.start_pos,
                &empty_rec_head,
                SRV_PROVBOX_FILE_REC_HEAD_SIZE);

            /* restore the old free record */
            srv_provbox_file_write_free_record_data(
                mgr->fd,
                free_rec->rec_id,
                free_rec->start_pos,
                free_rec->rec_size,
                &write_size,
                MMI_FALSE);
            SRV_PROVBOX_FREE(use_rec);
            srv_provbox_file_close_file(mgr);
        }
        return result;
    }

    if (free_rec->rec_size == need_rec_size)
    {
        /* simple to remove the free_rec from the free_list and add it to use list. */
        mgr->free_list = (srv_provbox_file_rec_struct*) srv_provbox_slist_remove(
                                                            (srv_provbox_slist_struct*) mgr->free_list,
                                                            (srv_provbox_slist_struct*) free_rec);
        /* use_rec is the free_rec, but still need to check its rec_id. */
        use_rec->rec_id = rec_id;
    }
    else
    {
        /* simple to change the info of free_rec same as to new_free_rec. */
        free_rec->rec_id = new_free_rec.rec_id;
        free_rec->start_pos = new_free_rec.start_pos;
        free_rec->rec_size = new_free_rec.rec_size;
    }

    mgr->use_list =
        (srv_provbox_file_rec_struct*) srv_provbox_slist_insert_sorted(
                                        (srv_provbox_slist_struct*) mgr->use_list,
                                        (srv_provbox_slist_struct*) use_rec,
                                        (SRV_PROVBOX_SLIST_COMPARE_NODE_FUNC) srv_provbox_file_sort_node_by_pos);

    mgr->use_rec_num++;
    if(use_rec) /* MMI_ASSERT(use_rec); */
        mgr->free_size -= use_rec->rec_size;

    srv_provbox_file_close_file(mgr);

    return SRV_PROVBOX_RESULT_OK;
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
#endif /* 0 */

/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_update_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hfile           [IN]        
 *  rec_id          [IN]        
 *  rec_data        [IN]        
 *  data_size       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_file_update_record(S32 hfile, U32 rec_id, void *rec_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    srv_provbox_result_enum result;
    srv_provbox_file_rec_struct *cur_rec;
    srv_provbox_file_mgr_struct *mgr = (srv_provbox_file_mgr_struct*) hfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mgr == NULL || rec_data == NULL || data_size <= 0 || data_size > SRV_PROVBOX_FILE_MAX_REC_SIZE)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    cur_rec = (srv_provbox_file_rec_struct*) srv_provbox_slist_get_node_by_data(
                                                (srv_provbox_slist_struct*) mgr->use_list,
                                                (SRV_PROVBOX_SLIST_COMPARE_NODE_FUNC) srv_provbox_file_find_node_by_id,
                                                (void*)rec_id);
    if (cur_rec == NULL)
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    MMI_ASSERT(data_size + SRV_PROVBOX_FILE_REC_PACK_SIZE == (S32) cur_rec->rec_size);

    if (data_size != (S32) (cur_rec->rec_size - SRV_PROVBOX_FILE_REC_PACK_SIZE))
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_UPDATE_RECORD_WRONG_SIZE,
            mgr->file_id,
            rec_id,
            data_size,
            cur_rec->rec_size,
            cur_rec->start_pos);
        return SRV_PROVBOX_RESULT_NOT_FOUND;
    }
    result = srv_provbox_file_open_file(mgr, &ret);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;
    result = srv_provbox_file_write_use_record_data(mgr->fd, cur_rec->rec_id, cur_rec->start_pos, rec_data, data_size);
    srv_provbox_file_close_file(mgr);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_delete_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hfile       [IN]        
 *  rec_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_result_enum srv_provbox_file_delete_record(S32 hfile, U32 rec_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    U32 write_size;
    U32 free_rec_id;
    srv_provbox_result_enum result;
    srv_provbox_file_rec_struct *rec;
    srv_provbox_file_mgr_struct *mgr = (srv_provbox_file_mgr_struct*) hfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mgr == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    rec = (srv_provbox_file_rec_struct*) srv_provbox_slist_get_node_by_data(
                                            (srv_provbox_slist_struct*) mgr->use_list,
                                            (SRV_PROVBOX_SLIST_COMPARE_NODE_FUNC) srv_provbox_file_find_node_by_id,
                                            (void*)rec_id);

    if (rec == NULL)
        return SRV_PROVBOX_RESULT_NOT_FOUND;

    MMI_ASSERT(rec->rec_size > SRV_PROVBOX_FILE_REC_PACK_SIZE);

    result = srv_provbox_file_open_file(mgr, &ret);
    if (result != SRV_PROVBOX_RESULT_OK)
        return result;

    free_rec_id = srv_provbox_file_get_next_free_rec_id(mgr);
    result = srv_provbox_file_write_free_record_data(
                mgr->fd,
                free_rec_id,
                rec->start_pos,
                rec->rec_size,
                &write_size,
                MMI_TRUE);

    if (result != SRV_PROVBOX_RESULT_OK)
    {
        srv_provbox_file_close_file(mgr);
        return result;
    }
    mgr->use_list = (srv_provbox_file_rec_struct*) srv_provbox_slist_remove(
                                                    (srv_provbox_slist_struct*) mgr->use_list,
                                                    (srv_provbox_slist_struct*) rec);

    mgr->free_list =
        (srv_provbox_file_rec_struct*) srv_provbox_slist_insert_sorted(
                                        (srv_provbox_slist_struct*) mgr->free_list,
                                        (srv_provbox_slist_struct*) rec,
                                        (SRV_PROVBOX_SLIST_COMPARE_NODE_FUNC) srv_provbox_file_sort_node_by_pos);

    mgr->free_size += rec->rec_size;
    mgr->use_rec_num--;

    srv_provbox_file_merge_free_record(mgr, rec);
    srv_provbox_file_close_file(mgr);

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_delete_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hfile       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_delete_file(S32 hfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    const CHAR *filename;
    U16 buffer[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];
    srv_provbox_file_mgr_struct *mgr = (srv_provbox_file_mgr_struct*) hfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hfile == 0)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    srv_provbox_file_close_file(mgr);

    filename = srv_provbox_get_file_by_id(mgr->file_id);
    mmi_asc_to_ucs2((CHAR*) buffer, (CHAR*) filename);
    ret = FS_Delete((const WCHAR*)buffer);
    return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_DELETE, ret);
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
#endif /* 0 */

/*----------------------------------------------------------------------------*/
/* Static Function Defines                                                    */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_free_rec_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rec_node        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_provbox_file_free_rec_node(srv_provbox_file_rec_struct *rec_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_PROVBOX_FREE(rec_node);
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_free_record_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hfile       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_provbox_file_free_record_list(S32 hfile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_file_mgr_struct *mgr = (srv_provbox_file_mgr_struct*) hfile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mgr == NULL)
        return;

    mgr->use_list =
        (srv_provbox_file_rec_struct*) srv_provbox_slist_free_slist(
                                        (srv_provbox_slist_struct*) mgr->use_list,
                                        (SRV_PROVBOX_SLIST_FREE_NODE_FUNC) srv_provbox_file_free_rec_node);

    mgr->free_list =
        (srv_provbox_file_rec_struct*) srv_provbox_slist_free_slist(
                                        (srv_provbox_slist_struct*) mgr->free_list,
                                        (SRV_PROVBOX_SLIST_FREE_NODE_FUNC) srv_provbox_file_free_rec_node);

    srv_provbox_file_close_file(mgr);

    mgr->flag = 0;
    mgr->total_size = 0;
    mgr->free_size = 0;
    mgr->file_size = 0;
    mgr->max_rec_num = 0;

    mgr->start_pos = 0;
    mgr->load_rec_num = 0;

    mgr->cur_use_rec = NULL;
    mgr->use_rec_num = 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_get_next_free_rec_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mgr     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U32 srv_provbox_file_get_next_free_rec_id(srv_provbox_file_mgr_struct *mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mgr->cur_free_rec_id++;
    return mgr->cur_free_rec_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_get_max_rec_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rec_list        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U32 srv_provbox_file_get_max_rec_id(srv_provbox_file_rec_struct *rec_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 max_rec_id = 0;
    srv_provbox_file_rec_struct *rec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rec = rec_list;

    while (rec)
    {
        if (rec->rec_id > max_rec_id)
            max_rec_id = rec->rec_id;
        rec = rec->next;
    }
    return max_rec_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_get_record_check_sum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rec_id          [IN]        
 *  rec_type        [IN]        
 *  rec_value       [IN]        
 *  value_size      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U32 srv_provbox_file_get_record_check_sum(U32 rec_id, U32 rec_type, U8 *rec_value, S32 value_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U8 c1;
    U8 c2;
    U32 num;
    S32 count;
    U32 check_sum = 0;
    U16 hash_value = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(value_size >= 0);

    if (rec_type == SRV_PROVBOX_FILE_REC_TYPE_FREE)
    {
        /* only set rec_size to the free record checksum which may be large than 0xFFFF. */
        check_sum = value_size + SRV_PROVBOX_FILE_REC_PACK_SIZE;
        return check_sum;
    }

    check_sum = (SRV_PROVBOX_FILE_REC_PACK_SIZE + value_size) << 16;

    count = value_size / 2;
    for (i = 0; i < count; i++)
    {
        c1 = rec_value[i * 2];
        c2 = rec_value[i * 2 + 1];
        num = c2;
        num = num << 8;
        hash_value += c1 + num;
    }
    if (value_size - count * 2 > 0)
    {
        c1 = rec_value[count * 2];
        c2 = 0;
        num = c2;
        num = num << 8;
        hash_value += c1 + num;
    }
    hash_value += rec_id & 0xFFFF;

    check_sum += hash_value;
    return check_sum;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_get_record_size_by_check_sum
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rec_type        [IN]        
 *  check_sum       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U32 srv_provbox_file_get_record_size_by_check_sum(U32 rec_type, U32 check_sum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rec_type == SRV_PROVBOX_FILE_REC_TYPE_FREE)
        return check_sum;
    else
        return (check_sum & 0xFFFF0000) >> 16;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_get_free_record_by_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mgr             [IN]        
 *  data_size       [IN]        
 *  rec             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_get_free_record_by_size(
                                srv_provbox_file_mgr_struct *mgr,
                                S32 data_size,
                                srv_provbox_file_rec_struct **rec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    UINT file_size;
    U32 write_size;
    U32 free_rec_id;
    srv_provbox_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mgr == NULL || data_size <= 0 || rec == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    *rec =
        (srv_provbox_file_rec_struct*) srv_provbox_slist_get_node_by_data(
                                        (srv_provbox_slist_struct*) mgr->free_list,
                                        (SRV_PROVBOX_SLIST_COMPARE_NODE_FUNC) srv_provbox_file_find_feasible_free_node_by_size,
                                        (void*)data_size);
    /* check if need to increase file size */
    if (*rec != NULL)
        return SRV_PROVBOX_RESULT_OK;

    free_rec_id = srv_provbox_file_get_next_free_rec_id(mgr);
    *rec = srv_provbox_file_create_record(free_rec_id, mgr->total_size, mgr->inc_size);
    if (*rec == NULL)
        return SRV_PROVBOX_RESULT_MEM_FULL;

    result = srv_provbox_file_write_free_record_data(
                mgr->fd,
                free_rec_id,
                mgr->total_size,
                mgr->inc_size,
                &write_size,
                MMI_TRUE);

    ret = FS_GetFileSize(mgr->fd, &file_size);
    if (ret == FS_NO_ERROR)
        mgr->file_size = file_size;
    if (ret != FS_NO_ERROR || result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_GET_FREE_RECORD_BY_SIZE_FILE_SIZE,
            mgr->file_id,
            free_rec_id,
            mgr->total_size,
            mgr->inc_size,
            mgr->file_size,
            ret,
            result);

        SRV_PROVBOX_FREE(*rec);
        return result;
    }

    mgr->free_list =
        (srv_provbox_file_rec_struct*) srv_provbox_slist_insert_sorted(
                                        (srv_provbox_slist_struct*) mgr->free_list,
                                        (srv_provbox_slist_struct*) * rec,
                                        (SRV_PROVBOX_SLIST_COMPARE_NODE_FUNC) srv_provbox_file_sort_node_by_pos);
    mgr->total_size += mgr->inc_size;
    mgr->free_size += mgr->inc_size;

    srv_provbox_file_merge_free_record(mgr, *rec);
    /* find it again, must find it now. */
    *rec =
        (srv_provbox_file_rec_struct*) srv_provbox_slist_get_node_by_data(
                                        (srv_provbox_slist_struct*) mgr->free_list,
                                        (SRV_PROVBOX_SLIST_COMPARE_NODE_FUNC) srv_provbox_file_find_feasible_free_node_by_size,
                                        (void*)data_size);
    MMI_ASSERT(*rec != NULL);

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_open_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mgr     [IN]        
 *  ret     [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_open_file(srv_provbox_file_mgr_struct *mgr, int *ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR filename[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mgr && mgr->fd < 0);

    mmi_asc_to_ucs2((CHAR*) filename, (CHAR*) srv_provbox_get_file_by_id(mgr->file_id));
    mgr->fd = FS_Open((const WCHAR*)filename, (UINT) FS_CREATE | FS_READ_WRITE);

    if (ret)
        *ret = mgr->fd;

    if (mgr->fd < 0)
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_OPEN, mgr->fd);
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_close_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mgr     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_close_file(srv_provbox_file_mgr_struct *mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mgr->fd < 0)
        return SRV_PROVBOX_RESULT_OK;

    FS_Close(mgr->fd);
    mgr->fd = -1;
    return SRV_PROVBOX_RESULT_OK;
}

/* OK, END or ERROR */


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_init_multi_record_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hfile               [IN]        
 *  load_rec_num        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_init_multi_record_node(S32 hfile, S32 load_rec_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cur_rec_num = 0;
    srv_provbox_result_enum result;
    srv_provbox_file_mgr_struct *mgr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hfile == 0)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    mgr = (srv_provbox_file_mgr_struct*) hfile;

    result = srv_provbox_file_init_open_file(mgr);
    /* check open fail or empty file */
    if (mgr->fd < 0 || result != SRV_PROVBOX_RESULT_CONTINUE)
        return result;

    mgr->load_rec_num = load_rec_num;

    do
    {
        if (mgr->start_pos >= mgr->file_size)
        {
            mgr->start_pos = 0;
            result = SRV_PROVBOX_RESULT_OK;
            break;
        }
        if (load_rec_num >= 0 && cur_rec_num >= load_rec_num)
        {
            result = SRV_PROVBOX_RESULT_CONTINUE;
            break;
        }
        result = srv_provbox_file_init_load_record_head(mgr);
        if (result == SRV_PROVBOX_RESULT_OK || result == SRV_PROVBOX_RESULT_CONTINUE)
            cur_rec_num++;
    } while (result == SRV_PROVBOX_RESULT_CONTINUE);

    srv_provbox_file_close_file(mgr);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_init_open_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mgr     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_init_open_file(srv_provbox_file_mgr_struct *mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    UINT read_len;
    srv_provbox_result_enum result = SRV_PROVBOX_RESULT_OK;
    WCHAR filename[SRV_PROVBOX_PATH_MAX_CHAR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mgr == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (mgr->fd >= 0)
        return SRV_PROVBOX_RESULT_OK;

    mmi_asc_to_ucs2((CHAR*) filename, (CHAR*) srv_provbox_get_file_by_id(mgr->file_id));
    mgr->fd = FS_Open((const WCHAR*)filename, (UINT) FS_READ_WRITE);   /* need to write free record */
    if (mgr->fd < 0)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_INIT_OPEN_FILE_OPEN_FAIL,
            mgr->file_id,
            mgr->fd,
            mgr->start_pos);

        if (mgr->start_pos > 0)
            return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_OPEN, mgr->fd);
        return SRV_PROVBOX_RESULT_OK;
    }

    /* if not first time to read file */
    if (mgr->start_pos > 0)
    {
        ret = FS_Seek(mgr->fd, mgr->start_pos, FS_FILE_BEGIN);
        if (ret < 0)
        {
            MMI_TRACE(
                SRV_PROVBOX_TRC_INFO,
                SRV_PROVBOX_TRC_FILE_INIT_OPEN_FILE_SEEK_FAIL,
                mgr->file_id,
                ret,
                mgr->start_pos);

            mgr->start_pos = 0;
            srv_provbox_file_close_file(mgr);
            return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_SEEK, ret);
        }

        return SRV_PROVBOX_RESULT_CONTINUE;
    }
    /* first to read file, check file size, if not empty file */
    ret = FS_GetFileSize(mgr->fd, &read_len);
    if (ret == FS_NO_ERROR && read_len > 0)
    {
        mgr->file_size = read_len;
        return SRV_PROVBOX_RESULT_CONTINUE;
    }
    /* it's an empty file */
    srv_provbox_file_close_file(mgr);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_init_load_record_head
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mgr     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_init_load_record_head(srv_provbox_file_mgr_struct *mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    U32 first_ok_pos;
    srv_provbox_result_enum result;
    srv_provbox_file_rec_head_struct rec_head;
    srv_provbox_check_info_struct check_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mgr == NULL || mgr->fd < 0)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    /* try to load next record now.
       the file position is first_ok_pos now, should move it to mgr->start_pos. 
       seek the file position to the end position of the new record. */
    ret = FS_Seek(mgr->fd, mgr->start_pos, FS_FILE_BEGIN);
    if (ret < 0)
    {
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_SEEK, ret);
    }

    /* check if async to find next valid pack data, read a record buffer and parse it. */
    if (SRV_PROVBOX_CHECK_FLAG(mgr->flag, SRV_PROVBOX_FILE_FLAG_FINDING_PACK))
    {
        result = srv_provbox_file_init_find_next_pack_data(mgr);
        if (result == SRV_PROVBOX_RESULT_CONTINUE)
        {
            /* try to read and parse next buffer, may find or not, if find, try to check if it'a a valid one, if not, try to parse next buffer. */
            return SRV_PROVBOX_RESULT_CONTINUE;
        }
        else if (result != SRV_PROVBOX_RESULT_OK)   /* fail to continue, error or end. */
        {
            /* here, mgr->start_pos may not equal to mgr->file_size, try to find as many records as possiable. */
            if (mgr->file_size - mgr->total_size >= SRV_PROVBOX_FILE_REC_PACK_SIZE)     /* check if can create a record. */
                result = mmi_provox_file_init_create_free_record(mgr, mgr->total_size, mgr->file_size - mgr->total_size);
            MMI_ASSERT(result != SRV_PROVBOX_RESULT_CONTINUE);
            return result;
        }
    }
    /* now, just start or a valid pack data is found, try to parse it. */
    rec_head.rec_type = 0;
    rec_head.rec_id = SRV_PROVBOX_INVALID_MSG_ID;
    rec_head.rec_size = 0;
    result = srv_provbox_file_init_load_pack_data(mgr, &rec_head);
    if (result == SRV_PROVBOX_RESULT_CONTINUE)
    {
        /* only srv_provbox_file_init_find_next_pack_data return SRV_PROVBOX_RESULT_CONTINUE,
           unluckily, a new invalid record with wrong pack data is found, try to parse next one. */

        /* check if read rec_head already, 
           simple to image the message id is right or damaged but not affect other message, if not, oh, so unluckly!. */
        if (rec_head.rec_type != 0 && rec_head.rec_id != SRV_PROVBOX_INVALID_MSG_ID && rec_head.rec_size != 0)
        {
            srv_provbox_file_set_check_info(
                &check_info,
                SRV_PROVBOX_CHECK_TYPE_DELETE,
                (U8) srv_provbox_file_get_box_type_by_file_id(mgr->file_id),
                rec_head.rec_id,
                0,
                0,
                -1,
                -1);
            srv_provbox_file_write_check_file(&check_info);
        }
        return SRV_PROVBOX_RESULT_CONTINUE;
    }
    else if (result != SRV_PROVBOX_RESULT_OK)
    {
        /* here, mgr->start_pos may not equal to mgr->file_size, try to find as many records as possiable. */
        if (mgr->file_size - mgr->total_size >= SRV_PROVBOX_FILE_REC_PACK_SIZE)
            result = mmi_provox_file_init_create_free_record(mgr, mgr->total_size, mgr->file_size - mgr->total_size);
        MMI_ASSERT(result != SRV_PROVBOX_RESULT_CONTINUE);
        return result;
    }

    /* if find new use record, check if has reach the max number, 
       if so, need to discard those records still not read, and treat current one as the last one. */
    if (rec_head.rec_type == SRV_PROVBOX_FILE_REC_TYPE_USE &&
        mgr->max_rec_num > 0 && mgr->use_rec_num >= mgr->max_rec_num)
    {
        if (mgr->file_size - mgr->total_size >= SRV_PROVBOX_FILE_REC_PACK_SIZE)
            result = mmi_provox_file_init_create_free_record(mgr, mgr->total_size, mgr->file_size - mgr->total_size);
        MMI_ASSERT(result != SRV_PROVBOX_RESULT_CONTINUE);
        return result;
    }

    first_ok_pos = mgr->start_pos - rec_head.rec_size;
    MMI_ASSERT(first_ok_pos == mgr->total_size || first_ok_pos - mgr->total_size >= SRV_PROVBOX_FILE_REC_PACK_SIZE);

    /* check if any error records are read before, if so, recover them as a new free record. */
    if (first_ok_pos - mgr->total_size >= SRV_PROVBOX_FILE_REC_PACK_SIZE)
    {
        /* move file position to mgr->total_size, and write free record data. */
        result = mmi_provox_file_init_create_free_record(mgr, mgr->total_size, first_ok_pos - mgr->total_size);
        if (result != SRV_PROVBOX_RESULT_OK)
            return result;
    }

    /* a record with valid pack data is found, create a record node for it. */
    result = srv_provbox_file_create_record_and_preappend(
                mgr,
                rec_head.rec_type,
                rec_head.rec_id,
                first_ok_pos,
                rec_head.rec_size);

    if (result != SRV_PROVBOX_RESULT_OK)
        return result;

    /* check if reach the file end. */
    if (mgr->start_pos >= mgr->file_size)
    {
        MMI_ASSERT(mgr->file_size == mgr->start_pos);
        return SRV_PROVBOX_RESULT_OK;
    }

    /* it's ok, return continue to read next record. */
    return SRV_PROVBOX_RESULT_CONTINUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_init_load_pack_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mgr             [IN]        
 *  rec_head        [OUT]       
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_init_load_pack_data(
                                srv_provbox_file_mgr_struct *mgr,
                                srv_provbox_file_rec_head_struct *rec_head)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    UINT read_len;
    srv_provbox_result_enum result;
    srv_provbox_file_rec_footer_struct rec_footer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mgr == NULL || mgr->fd < 0 || rec_head == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    ret = FS_Read(mgr->fd, (void*)rec_head, SRV_PROVBOX_FILE_REC_HEAD_SIZE, &read_len);
    if (ret != FS_NO_ERROR || read_len != SRV_PROVBOX_FILE_REC_HEAD_SIZE)
    {
        if (ret == FS_NO_ERROR)
            return SRV_PROVBOX_RESULT_FILE_ERR_SIZE;
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_READ, ret);
    }

    mgr->start_pos += SRV_PROVBOX_FILE_REC_HEAD_SIZE;

    result = srv_provbox_file_check_record_pack_data(mgr, rec_head, NULL);
    if (result != SRV_PROVBOX_RESULT_OK || (int)(rec_head->rec_size - SRV_PROVBOX_FILE_REC_PACK_SIZE) < 0)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_INIT_LOAD_PACK_DATA_CHECK_HEAD,
            mgr->file_id,
            rec_head->rec_type,
            rec_head->rec_id,
            rec_head->rec_size,
            mgr->start_pos,
            result);

        if (mgr->start_pos >= mgr->file_size)
            return SRV_PROVBOX_RESULT_NOT_FOUND;
        SRV_PROVBOX_SET_FLAG(mgr->flag, SRV_PROVBOX_FILE_FLAG_FINDING_PACK);
        return SRV_PROVBOX_RESULT_CONTINUE;
    }

    ret = FS_Seek(mgr->fd, rec_head->rec_size - SRV_PROVBOX_FILE_REC_PACK_SIZE, FS_FILE_CURRENT);
    if (ret < 0)
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_SEEK, ret);

    mgr->start_pos += rec_head->rec_size - SRV_PROVBOX_FILE_REC_PACK_SIZE;

    ret = FS_Read(mgr->fd, (void*)&rec_footer, SRV_PROVBOX_FILE_REC_FOOTER_SIZE, &read_len);
    if (ret != FS_NO_ERROR || read_len != SRV_PROVBOX_FILE_REC_FOOTER_SIZE)
    {
        if (ret == FS_NO_ERROR)
            return SRV_PROVBOX_RESULT_FILE_ERR_SIZE;
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_READ, ret);
    }

    mgr->start_pos += SRV_PROVBOX_FILE_REC_FOOTER_SIZE;

    result = srv_provbox_file_check_record_pack_data(mgr, rec_head, &rec_footer);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_INIT_LOAD_PACK_DATA_CHECK_FOOTER,
            result,
            mgr->file_id,
            rec_head->rec_id,
            rec_head->rec_size,
            mgr->start_pos,
            rec_footer.check_sum,
            rec_footer.footer);
        /* back to the start pos of this record head, to avoid the error record_size. */
        ret = FS_Seek(mgr->fd, 0 - (rec_head->rec_size - SRV_PROVBOX_FILE_REC_HEAD_SIZE), FS_FILE_CURRENT);
        if (ret < 0)
            return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_SEEK, ret);

        mgr->start_pos -= rec_head->rec_size - SRV_PROVBOX_FILE_REC_HEAD_SIZE;

        if (mgr->start_pos >= mgr->file_size)
            return SRV_PROVBOX_RESULT_NOT_FOUND;

        SRV_PROVBOX_SET_FLAG(mgr->flag, SRV_PROVBOX_FILE_FLAG_FINDING_PACK);
        return SRV_PROVBOX_RESULT_CONTINUE;
    }
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_init_find_next_pack_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mgr     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_init_find_next_pack_data(srv_provbox_file_mgr_struct *mgr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    int ret;
    U32 len;
    int seek_pos;
    UINT read_len;
    MMI_BOOL find_head = MMI_FALSE;
    MMI_BOOL find_foot = MMI_FALSE;
    U32 tmp_buf[(SRV_PROVBOX_FILE_MAX_REC_SIZE + 3) / 4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mgr == NULL || mgr->fd < 0)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    /* try to read a data, and try to find the record header or footer, may reach file end. */
    ret = FS_Read(mgr->fd, (void*)tmp_buf, SRV_PROVBOX_FILE_MAX_REC_SIZE, &read_len);
    if (ret != FS_NO_ERROR || read_len > SRV_PROVBOX_FILE_MAX_REC_SIZE || read_len < sizeof(U32))
    {
        if (ret == FS_NO_ERROR)
            return SRV_PROVBOX_RESULT_FILE_ERR_SIZE;
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_READ, ret);
    }
    for (i = 0, len = 0; i < read_len / 4; i++)
    {
        /* check if can get next U32 value. */
        if (len + sizeof(U32) > read_len)
            break;

        if (tmp_buf[i] == SRV_PROVBOX_FILE_REC_FOOTER_USE || tmp_buf[i] == SRV_PROVBOX_FILE_REC_FOOTER_FREE)
        {
            find_foot = MMI_TRUE;
            break;
        }
        if (tmp_buf[i] == SRV_PROVBOX_FILE_REC_TYPE_USE || tmp_buf[i] == SRV_PROVBOX_FILE_REC_TYPE_FREE)
        {
            find_head = MMI_TRUE;
            break;
        }
        len += sizeof(U32); /* to check next U32 value. */
    }

    if (!find_head && !find_foot)
    {
        mgr->start_pos += read_len;
        if (mgr->start_pos >= mgr->file_size)
            return SRV_PROVBOX_RESULT_NOT_FOUND;
        SRV_PROVBOX_SET_FLAG(mgr->flag, SRV_PROVBOX_FILE_FLAG_FINDING_PACK);
        return SRV_PROVBOX_RESULT_CONTINUE;
    }

    /* find it, remove flag. */
    SRV_PPOVBOX_CLEAR_FLAG(mgr->flag, SRV_PROVBOX_FILE_FLAG_FINDING_PACK);

    if (find_foot)
        seek_pos = read_len - (len + sizeof(U32));
    else
        seek_pos = read_len - len;

    ret = FS_Seek(mgr->fd, 0 - seek_pos, FS_FILE_CURRENT);
    if (ret < 0)
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_SEEK, ret);

    mgr->start_pos += read_len - seek_pos;  /* seek_pos < 0 */
    if (mgr->start_pos >= mgr->file_size)
        return SRV_PROVBOX_RESULT_NOT_FOUND;
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_provox_file_init_create_free_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mgr             [IN]        
 *  start_pos       [IN]        
 *  rec_size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum mmi_provox_file_init_create_free_record(
                                srv_provbox_file_mgr_struct *mgr,
                                U32 start_pos,
                                U32 rec_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 write_size;
    U32 free_rec_id;
    srv_provbox_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mgr == NULL || mgr->fd < 0)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (rec_size < SRV_PROVBOX_FILE_REC_PACK_SIZE)
        return SRV_PROVBOX_RESULT_FAIL;

    free_rec_id = srv_provbox_file_get_next_free_rec_id(mgr);
    result = srv_provbox_file_write_free_record_data(mgr->fd, free_rec_id, start_pos, rec_size, &write_size, MMI_TRUE);

    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_INIT_CREATE_FREE_RECORD_WRITE_FREE,
            result,
            mgr->file_id,
            free_rec_id,
            start_pos,
            rec_size,
            mgr->file_size);

        return result;
    }
    result = srv_provbox_file_create_record_and_preappend(
                mgr,
                SRV_PROVBOX_FILE_REC_TYPE_FREE,
                free_rec_id,
                start_pos,
                rec_size);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_check_record_pack_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mgr             [IN]        
 *  rec_head        [IN]        
 *  rec_footer      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_check_record_pack_data(
                                srv_provbox_file_mgr_struct *mgr,
                                srv_provbox_file_rec_head_struct *rec_head,
                                srv_provbox_file_rec_footer_struct *rec_footer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rec_head == NULL && rec_footer == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (rec_head)
    {
        if (rec_head->rec_type != SRV_PROVBOX_FILE_REC_TYPE_USE && rec_head->rec_type != SRV_PROVBOX_FILE_REC_TYPE_FREE)
            return SRV_PROVBOX_RESULT_PARSE_ERR;

        if (rec_head->rec_size < SRV_PROVBOX_FILE_REC_PACK_SIZE)
            return SRV_PROVBOX_RESULT_PARSE_ERR;

        if (rec_head->rec_type == SRV_PROVBOX_FILE_REC_TYPE_USE && rec_head->rec_size > SRV_PROVBOX_FILE_MAX_REC_SIZE)
            return SRV_PROVBOX_RESULT_PARSE_ERR;

        if (rec_head->rec_type == SRV_PROVBOX_FILE_REC_TYPE_FREE && rec_head->rec_size > mgr->file_size - mgr->total_size)      /* check in reading, mgr->total is all records read now, sholl smaller than file size */
            return SRV_PROVBOX_RESULT_PARSE_ERR;
        /* already read the head, so should decrease the head size. */
        if (!rec_footer)
        {
            if (mgr->start_pos + rec_head->rec_size - SRV_PROVBOX_FILE_REC_HEAD_SIZE > mgr->file_size)
                return SRV_PROVBOX_RESULT_PARSE_ERR;
        }
        else
        {
            /* already read the record footer. */
            if (mgr->start_pos > mgr->file_size)
                return SRV_PROVBOX_RESULT_PARSE_ERR;

        }
    }

    if (rec_footer)
    {
        if (rec_footer->footer != SRV_PROVBOX_FILE_REC_FOOTER_USE &&
            rec_footer->footer != SRV_PROVBOX_FILE_REC_FOOTER_FREE)
            return SRV_PROVBOX_RESULT_PARSE_ERR;
    }

    if (rec_head && rec_footer)
    {
        if (rec_head->rec_type == SRV_PROVBOX_FILE_REC_TYPE_USE &&
            rec_head->rec_size != srv_provbox_file_get_record_size_by_check_sum(
                                    rec_head->rec_type,
                                    rec_footer->check_sum))
            return SRV_PROVBOX_RESULT_PARSE_ERR;

        if (rec_head->rec_type == SRV_PROVBOX_FILE_REC_TYPE_FREE &&
            rec_head->rec_size != srv_provbox_file_get_record_size_by_check_sum(
                                    rec_head->rec_type,
                                    rec_footer->check_sum))
            return SRV_PROVBOX_RESULT_PARSE_ERR;
    }
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_create_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rec_id          [IN]        
 *  start_pos       [IN]        
 *  rec_size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_file_rec_struct *srv_provbox_file_create_record(U32 rec_id, U32 start_pos, U32 rec_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_file_rec_struct *rec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rec = (srv_provbox_file_rec_struct*) SRV_PROVBOX_ALLOC_TYPE(srv_provbox_file_rec_struct);
    if (rec == NULL)
        return NULL;

    rec->next = NULL;
    rec->rec_id = rec_id;
    rec->start_pos = start_pos;
    rec->rec_size = rec_size;

    return rec;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_create_record_and_preappend
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mgr             [IN]        
 *  rec_type        [IN]        
 *  rec_id          [IN]        
 *  start_pos       [IN]        
 *  size            [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_create_record_and_preappend(
                                srv_provbox_file_mgr_struct *mgr,
                                U32 rec_type,
                                U32 rec_id,
                                U32 start_pos,
                                U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_file_rec_struct *new_rec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mgr == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    new_rec = srv_provbox_file_create_record(rec_id, start_pos, size);
    if (new_rec == NULL)
        return SRV_PROVBOX_RESULT_MEM_FULL;

    if (rec_type == SRV_PROVBOX_FILE_REC_TYPE_FREE)
    {
        mgr->free_list =
            (srv_provbox_file_rec_struct*) srv_provbox_slist_add_head(
                                            (srv_provbox_slist_struct*) mgr->free_list,
                                            (srv_provbox_slist_struct*) new_rec);
        mgr->free_size += new_rec->rec_size;
    }
    else if (rec_type == SRV_PROVBOX_FILE_REC_TYPE_USE)
    {
        mgr->use_list =
            (srv_provbox_file_rec_struct*) srv_provbox_slist_add_head(
                                            (srv_provbox_slist_struct*) mgr->use_list,
                                            (srv_provbox_slist_struct*) new_rec);
        mgr->use_rec_num++;
    }
    else
    {
        MMI_ASSERT(0);
    }
    mgr->total_size += new_rec->rec_size;

    if (rec_type == SRV_PROVBOX_FILE_REC_TYPE_FREE)
        srv_provbox_file_merge_free_record(mgr, new_rec);

    return SRV_PROVBOX_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_find_feasible_free_node_by_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node            [IN]        
 *  data_size       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_cmp_result_enum srv_provbox_file_find_feasible_free_node_by_size(
                                    srv_provbox_slist_struct *node,
                                    S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size = 0;
    srv_provbox_file_rec_struct *rec = (srv_provbox_file_rec_struct*) node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* one free record can be the proper one if its is same as what needed, or can be split into two free record. */
    size = (S32) (rec->rec_size - data_size);
    /* must check  size  > 0, to avoid U32 type-cast issue. */
    if (size < 0)
        return SRV_PROVBOX_CMP_RESULT_UNEQUAL;

    if (size > 0 && size == SRV_PROVBOX_FILE_REC_PACK_SIZE || size >= SRV_PROVBOX_FILE_REC_PACK_SIZE * 2)
        return SRV_PROVBOX_CMP_RESULT_EQUAL;
    else
        return SRV_PROVBOX_CMP_RESULT_UNEQUAL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_find_node_by_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node        [IN]        
 *  rec_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_cmp_result_enum srv_provbox_file_find_node_by_id(srv_provbox_slist_struct *node, void *rec_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((srv_provbox_file_rec_struct*) node)->rec_id == (U32) rec_id)
        return SRV_PROVBOX_CMP_RESULT_EQUAL;
    else
        return SRV_PROVBOX_CMP_RESULT_UNEQUAL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_find_prev_node_by_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node        [IN]        
 *  pos         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_cmp_result_enum srv_provbox_file_find_prev_node_by_pos(srv_provbox_slist_struct *node, void *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 end_pos;
    srv_provbox_file_rec_struct *rec = (srv_provbox_file_rec_struct*) node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    end_pos = rec->start_pos + rec->rec_size;
    if (end_pos == (U32) pos)
        return SRV_PROVBOX_CMP_RESULT_EQUAL;
    else
        return SRV_PROVBOX_CMP_RESULT_UNEQUAL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_find_next_node_by_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node        [IN]        
 *  pos         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_cmp_result_enum srv_provbox_file_find_next_node_by_pos(srv_provbox_slist_struct *node, void *pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_file_rec_struct *rec = (srv_provbox_file_rec_struct*) node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rec->start_pos == (U32) pos)
        return SRV_PROVBOX_CMP_RESULT_EQUAL;
    else
        return SRV_PROVBOX_CMP_RESULT_UNEQUAL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_sort_node_by_pos
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rec1        [IN]        
 *  rec2        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_cmp_result_enum srv_provbox_file_sort_node_by_pos(
                                    srv_provbox_file_rec_struct *rec1,
                                    srv_provbox_file_rec_struct *rec2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(rec1 && rec2);

    if (rec1->start_pos < rec2->start_pos)
        return SRV_PROVBOX_CMP_RESULT_BEFORE;
    else if (rec1->start_pos == rec2->start_pos)
        return SRV_PROVBOX_CMP_RESULT_EQUAL;
    else
        return SRV_PROVBOX_CMP_RESULT_AFTER;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_merge_free_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mgr     [IN]        
 *  rec     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_merge_free_record(
                                srv_provbox_file_mgr_struct *mgr,
                                srv_provbox_file_rec_struct *rec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 start_pos;
    U32 free_rec_id;
    U32 new_rec_size;
    U32 write_size;
    srv_provbox_result_enum result;
    srv_provbox_file_rec_struct *prev_rec;
    srv_provbox_file_rec_struct *next_rec;
    U8 zero_buf[SRV_PROVBOX_FILE_REC_PACK_SIZE] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mgr == NULL || rec == NULL)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    do
    {
        prev_rec =
            (srv_provbox_file_rec_struct*) srv_provbox_slist_get_node_by_data(
                                            (srv_provbox_slist_struct*) mgr->free_list,
                                            (SRV_PROVBOX_SLIST_COMPARE_NODE_FUNC) srv_provbox_file_find_prev_node_by_pos,
                                            (void*)rec->start_pos);

        MMI_ASSERT(prev_rec == NULL || prev_rec->rec_size >= SRV_PROVBOX_FILE_REC_PACK_SIZE);

        next_rec =
            (srv_provbox_file_rec_struct*) srv_provbox_slist_get_node_by_data(
                                            (srv_provbox_slist_struct*) mgr->free_list,
                                            (SRV_PROVBOX_SLIST_COMPARE_NODE_FUNC) srv_provbox_file_find_next_node_by_pos,
                                            (void*)(rec->start_pos + rec->rec_size));

        MMI_ASSERT(next_rec == NULL || next_rec->rec_size >= SRV_PROVBOX_FILE_REC_PACK_SIZE);

        /* if not need to merge, just return. */
        if (prev_rec == NULL && next_rec == NULL)
            return SRV_PROVBOX_RESULT_OK;

        free_rec_id = srv_provbox_file_get_next_free_rec_id(mgr);
        start_pos = rec->start_pos;
        new_rec_size = rec->rec_size;
        if (next_rec != NULL)
            new_rec_size += next_rec->rec_size;

        if (prev_rec != NULL)
        {
            new_rec_size += prev_rec->rec_size;
            start_pos = prev_rec->start_pos;
        }

        result = srv_provbox_file_write_free_record_data(
                    mgr->fd,
                    free_rec_id,
                    start_pos,
                    new_rec_size,
                    &write_size,
                    MMI_FALSE);
        if (result != SRV_PROVBOX_RESULT_OK)
            return result;

        if (next_rec != NULL)
        {
            srv_provbox_file_write_record_data(
                mgr->fd,
                rec->start_pos + rec->rec_size - SRV_PROVBOX_FILE_REC_FOOTER_SIZE,
                &zero_buf,
                SRV_PROVBOX_FILE_REC_PACK_SIZE);

            mgr->free_list =
                (srv_provbox_file_rec_struct*) srv_provbox_slist_delete(
                                                (srv_provbox_slist_struct*) mgr->free_list,
                                                (srv_provbox_slist_struct*) next_rec,
                                                (SRV_PROVBOX_SLIST_FREE_NODE_FUNC) srv_provbox_file_free_rec_node);
        }
        if (prev_rec != NULL)
        {
            srv_provbox_file_write_record_data(
                mgr->fd,
                prev_rec->start_pos + prev_rec->rec_size - SRV_PROVBOX_FILE_REC_FOOTER_SIZE,
                &zero_buf,
                SRV_PROVBOX_FILE_REC_PACK_SIZE);

            mgr->free_list =
                (srv_provbox_file_rec_struct*) srv_provbox_slist_delete(
                                                (srv_provbox_slist_struct*) mgr->free_list,
                                                (srv_provbox_slist_struct*) prev_rec,
                                                (SRV_PROVBOX_SLIST_FREE_NODE_FUNC) srv_provbox_file_free_rec_node);
        }

        /* should first to delete prev_rec and next_rec, then revise cur_rec */
        rec->rec_id = free_rec_id;
        rec->rec_size = new_rec_size;
        rec->start_pos = start_pos;
    } while (rec);

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_read_use_record_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fd              [IN]        
 *  rec_id          [IN]        
 *  start_pos       [IN]        
 *  rec_size        [IN]        
 *  buf             [OUT]       
 *  buf_size        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_read_use_record_data(
                                FS_HANDLE fd,
                                U32 rec_id,
                                U32 start_pos,
                                U32 rec_size,
                                void *buf,
                                S32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    UINT read_len;
    srv_provbox_file_rec_head_struct rec_header;
    srv_provbox_file_rec_footer_struct rec_footer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fd < 0 || buf == NULL || buf_size <= 0 || rec_size == 0)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    MMI_ASSERT(rec_size - (S32) SRV_PROVBOX_FILE_REC_PACK_SIZE <= (U32) buf_size);

    ret = FS_Seek(fd, start_pos, FS_FILE_BEGIN);
    if (ret < 0)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_READ_USE_RECORD_DATA,
            1,
            ret,
            rec_id,
            start_pos,
            rec_size,
            -1,
            -1);
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_SEEK, ret);
    }

    ret = FS_Read(fd, &rec_header, SRV_PROVBOX_FILE_REC_HEAD_SIZE, &read_len);
    if (ret != FS_NO_ERROR || (S32) read_len != SRV_PROVBOX_FILE_REC_HEAD_SIZE)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_READ_USE_RECORD_DATA,
            2,
            ret,
            rec_id,
            start_pos,
            rec_size,
            SRV_PROVBOX_FILE_REC_HEAD_SIZE,
            read_len);
        if (ret == FS_NO_ERROR)
            return SRV_PROVBOX_RESULT_FILE_ERR_SIZE;
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_READ, ret);
    }

    if (rec_header.rec_type != SRV_PROVBOX_FILE_REC_TYPE_USE ||
        rec_header.rec_id != rec_id || rec_header.rec_size != rec_size)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_READ_USE_RECORD_DATA,
            3,
            ret,
            rec_id,
            start_pos,
            rec_size,
            SRV_PROVBOX_FILE_REC_HEAD_SIZE,
            read_len);
        return SRV_PROVBOX_RESULT_PARSE_ERR;
    }

    ret = FS_Read(fd, buf, rec_size - SRV_PROVBOX_FILE_REC_PACK_SIZE, &read_len);
    if (ret != FS_NO_ERROR || (S32) read_len != rec_size - SRV_PROVBOX_FILE_REC_PACK_SIZE)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_READ_USE_RECORD_DATA,
            4,
            ret,
            rec_id,
            start_pos,
            rec_size,
            rec_size - SRV_PROVBOX_FILE_REC_PACK_SIZE,
            read_len);
        if (ret == FS_NO_ERROR)
            return SRV_PROVBOX_RESULT_FILE_ERR_SIZE;
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_READ, ret);
    }

    ret = FS_Read(fd, &rec_footer, SRV_PROVBOX_FILE_REC_FOOTER_SIZE, &read_len);
    if (ret != FS_NO_ERROR || (S32) read_len != SRV_PROVBOX_FILE_REC_FOOTER_SIZE)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_READ_USE_RECORD_DATA,
            5,
            ret,
            rec_id,
            start_pos,
            rec_size,
            SRV_PROVBOX_FILE_REC_FOOTER_SIZE,
            read_len);
        if (ret == FS_NO_ERROR)
            return SRV_PROVBOX_RESULT_FILE_ERR_SIZE;
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_READ, ret);
    }

    if (rec_footer.footer != SRV_PROVBOX_FILE_REC_FOOTER_USE)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_READ_USE_RECORD_DATA,
            6,
            ret,
            rec_id,
            start_pos,
            rec_size,
            SRV_PROVBOX_FILE_REC_FOOTER_SIZE,
            read_len);
        return SRV_PROVBOX_RESULT_PARSE_ERR;
    }

    if (rec_footer.check_sum != srv_provbox_file_get_record_check_sum(
                                    rec_id,
                                    SRV_PROVBOX_FILE_REC_TYPE_USE,
                                    buf,
                                    rec_size - SRV_PROVBOX_FILE_REC_PACK_SIZE))
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_READ_USE_RECORD_DATA,
            7,
            ret,
            rec_id,
            start_pos,
            rec_size,
            SRV_PROVBOX_FILE_REC_FOOTER_SIZE,
            read_len);
        return SRV_PROVBOX_RESULT_PARSE_ERR;
    }

    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_write_record_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fd              [IN]        
 *  start_pos       [IN]        
 *  data            [IN]        
 *  data_size       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_write_record_data(
                                FS_HANDLE fd,
                                U32 start_pos,
                                void *data,
                                S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    UINT write_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fd < 0 || data == NULL || data_size <= 0)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    ret = FS_Seek(fd, start_pos, FS_FILE_BEGIN);
    if (ret < 0)
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_SEEK, ret);

    ret = FS_Write(fd, data, data_size, &write_len);
    if (ret != FS_NO_ERROR || (S32) write_len != data_size)
    {
        if (ret == FS_NO_ERROR)
            return SRV_PROVBOX_RESULT_FILE_ERR_SIZE;
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_WRITE, ret);
    }
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_write_free_record_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fd              [IN]        
 *  free_rec_id     [IN]        
 *  start_pos       [IN]        
 *  rec_size        [IN]        
 *  write_size      [OUT]       
 *  fill_zero       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_write_free_record_data(
                                FS_HANDLE fd,
                                U32 free_rec_id,
                                U32 start_pos,
                                S32 rec_size,
                                U32 *write_size,
                                MMI_BOOL fill_zero)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ret;
    U32 buf_size;
    U32 total_len = 0;
    UINT write_len = 0;
    srv_provbox_file_rec_head_struct rec_head;
    srv_provbox_file_rec_footer_struct rec_footer;
    U8 buffer[SRV_PROVBOX_FILE_FREE_ZERO_SIZE] = {0};
    U32 empty_value_size = rec_size - SRV_PROVBOX_FILE_REC_PACK_SIZE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fd < 0 || rec_size < SRV_PROVBOX_FILE_REC_PACK_SIZE)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    if (write_size)
        *write_size = 0;
    ret = FS_Seek(fd, start_pos, FS_FILE_BEGIN);
    if (ret < 0)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_WRITE_FREE_RECORD_DATA,
            1,
            free_rec_id,
            start_pos,
            rec_size,
            -1,
            -1);

        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_SEEK, ret);
    }
    rec_head.rec_type = SRV_PROVBOX_FILE_REC_TYPE_FREE;
    rec_head.rec_id = free_rec_id;
    rec_head.rec_size = rec_size;

    ret = FS_Write(fd, &rec_head, SRV_PROVBOX_FILE_REC_HEAD_SIZE, &write_len);
    if (ret != FS_NO_ERROR || write_len != SRV_PROVBOX_FILE_REC_HEAD_SIZE)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_WRITE_FREE_RECORD_DATA,
            2,
            free_rec_id,
            start_pos,
            rec_size,
            SRV_PROVBOX_FILE_REC_HEAD_SIZE,
            write_len);
        if (ret == FS_NO_ERROR)
            return SRV_PROVBOX_RESULT_FILE_ERR_SIZE;
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_WRITE, ret);
    }
    total_len = write_len;
    if (write_size)
        *write_size = total_len;

    if (fill_zero == MMI_TRUE)
    {
        if (rec_size <= SRV_PROVBOX_FILE_MAX_RW_SIZE)
        {
            while (total_len < empty_value_size + SRV_PROVBOX_FILE_REC_HEAD_SIZE)
            {
                if (empty_value_size + SRV_PROVBOX_FILE_REC_HEAD_SIZE - total_len >= SRV_PROVBOX_FILE_FREE_ZERO_SIZE)
                    buf_size = SRV_PROVBOX_FILE_FREE_ZERO_SIZE;
                else
                    buf_size = empty_value_size + SRV_PROVBOX_FILE_REC_HEAD_SIZE - total_len;
                ret = FS_Write(fd, (void*)buffer, buf_size, &write_len);
                if (ret != FS_NO_ERROR || write_len != buf_size)
                {
                    MMI_TRACE(
                        SRV_PROVBOX_TRC_INFO,
                        SRV_PROVBOX_TRC_FILE_WRITE_FREE_RECORD_DATA,
                        3,
                        free_rec_id,
                        start_pos + total_len,
                        rec_size,
                        buf_size,
                        write_len);
                    if (ret == FS_NO_ERROR)
                        return SRV_PROVBOX_RESULT_FILE_ERR_SIZE;
                    return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_WRITE, ret);
                }
                total_len += write_len;
                if (write_size)
                    *write_size = total_len;
            }
        }
    }
    else
    {
        ret = FS_Seek(fd, empty_value_size, FS_FILE_CURRENT);
        if (ret < 0)
        {
            MMI_TRACE(
                SRV_PROVBOX_TRC_INFO,
                SRV_PROVBOX_TRC_FILE_WRITE_FREE_RECORD_DATA,
                4,
                free_rec_id,
                empty_value_size,
                rec_size,
                -1,
                -1);
            return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_SEEK, ret);
        }
        total_len += empty_value_size;
        if (write_size)
            *write_size = total_len;
    }
    rec_footer.check_sum = srv_provbox_file_get_record_check_sum(
                            free_rec_id,
                            SRV_PROVBOX_FILE_REC_TYPE_FREE,
                            NULL,
                            empty_value_size);
    rec_footer.footer = SRV_PROVBOX_FILE_REC_FOOTER_FREE;

    ret = FS_Write(fd, (void*)&rec_footer, SRV_PROVBOX_FILE_REC_FOOTER_SIZE, &write_len);
    if (ret != FS_NO_ERROR || write_len != SRV_PROVBOX_FILE_REC_FOOTER_SIZE)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_WRITE_FREE_RECORD_DATA,
            5,
            free_rec_id,
            start_pos + total_len,
            rec_size,
            SRV_PROVBOX_FILE_REC_FOOTER_SIZE,
            write_len);
        if (ret == FS_NO_ERROR)
            return SRV_PROVBOX_RESULT_FILE_ERR_SIZE;
        return srv_provbox_error_code_file_to_provbox(SRV_PROVBOX_FILE_OP_TYPE_WRITE, ret);
    }
    total_len += write_len;
    if (write_size)
        *write_size = total_len;
    return SRV_PROVBOX_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_file_write_use_record_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  fd              [IN]        
 *  use_rec_id      [IN]        
 *  start_pos       [IN]        
 *  data            [IN]        
 *  data_size       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static srv_provbox_result_enum srv_provbox_file_write_use_record_data(
                                FS_HANDLE fd,
                                U32 use_rec_id,
                                U32 start_pos,
                                void *data,
                                S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *buf;
    srv_provbox_result_enum result;
    srv_provbox_file_rec_head_struct *rec_head;
    srv_provbox_file_rec_footer_struct rec_footer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fd < 0 || data == NULL || data_size <= 0)
        return SRV_PROVBOX_RESULT_INVALID_PARAM;

    buf = SRV_PROVBOX_MALLOC(data_size + SRV_PROVBOX_FILE_REC_PACK_SIZE);
    if (buf == NULL)
        return SRV_PROVBOX_RESULT_MEM_FULL;
    rec_head = (srv_provbox_file_rec_head_struct*) buf;
    rec_head->rec_type = SRV_PROVBOX_FILE_REC_TYPE_USE;
    rec_head->rec_id = use_rec_id;
    rec_head->rec_size = data_size + SRV_PROVBOX_FILE_REC_PACK_SIZE;
    rec_footer.check_sum = srv_provbox_file_get_record_check_sum(use_rec_id, SRV_PROVBOX_FILE_REC_TYPE_USE, data, data_size);
    rec_footer.footer = SRV_PROVBOX_FILE_REC_FOOTER_USE;
    memcpy((U8*) rec_head + SRV_PROVBOX_FILE_REC_HEAD_SIZE, data, data_size);
    memcpy((U8*) rec_head + SRV_PROVBOX_FILE_REC_HEAD_SIZE + data_size, &rec_footer, SRV_PROVBOX_FILE_REC_FOOTER_SIZE);

    result = srv_provbox_file_write_record_data(fd, start_pos, buf, rec_head->rec_size);
    if (result != SRV_PROVBOX_RESULT_OK)
    {
        MMI_TRACE(
            SRV_PROVBOX_TRC_INFO,
            SRV_PROVBOX_TRC_FILE_WRITE_USE_RECORD_DATA,
            use_rec_id,
            start_pos,
            rec_head->rec_size);
    }
    SRV_PROVBOX_FREE(buf);
    return result;
}

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

