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
 *  PlstSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  player list service source file
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 
#include "FileMgrSrvGProt.h"
#if defined(__PLST_SERVICE_DB_SUPPORT__) 
#include "PlstSrvGprot.h"
#include "PlstSrv.h"
#include "PlstSrvpls.h"

#include "MMIDataType.h"
#include "MMI_media_app_trc.h"
#include "mmi_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "gui_data_types.h"
#include "Unicodexdcl.h"
#include "fs_type.h"
#include "fs_func.h"
#include "kal_public_api.h"
#include "fs_errcode.h"
#include "string.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "mmi_rp_srv_plst_def.h"
#include "sqlite3.h"
#include "MMI_features.h"
#include "mmi_rp_file_type_def.h"
#include "stdlib.h"

#define SRV_PLST_MIN_DRV_LEFT_SIZE 10*1024

static srv_plst_control_struct g_srv_plst_control;
srv_plst_control_struct *g_srv_plst_control_ptr = &g_srv_plst_control;

static srv_plst_main_context_struct *g_srv_plst_main;
U32 g_srv_plst_query_album_id = 0;       //stamp currently artwork id, in order to avoid not sync case.


/*****************************************************************************
 * FUNCTION
 *  srv_plst_default_playlist_configure
 * DESCRIPTION
 *   set the configure of default playlist, set it before SRV_PLST_CMD_LIBRARY_OPEN, and only call once after service created    
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 *  default_flag :         [IN]   default play list configure info  
 * Sample
 *     default_flag   SRV_PLST_DEFAULT_RECENTLY_PLST|SRV_PLST_DEFAULT_MOST_PLST
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_default_playlist_configure(U32 srv_plst_hdr, U32 default_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_DEFAULT_PLST_CONFIGRE, default_flag);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    srv_plst_base->default_plst_config = default_flag;
    return SRV_PLST_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_default_playlist_get_type
 * DESCRIPTION
 *   get the default playlist type by index that selected index from lib   
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 *  index        :         [IN]   index in current   
 *  default_type :         [OUT]   SRV_PLST_DEFAULT_RECENTLY_PLST or SRV_PLST_DEFAULT_MOST_PLST etc
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 srv_plst_default_playlist_get_type(U32 srv_plst_hdr, U32 index, U32* default_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    U32 id;
    U32 id_start = 1;
    U32 i;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_DEFAULT_PLST_GET_TYPE, srv_plst_hdr, index);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    

    ret = srv_plst_plst_get_plst_id(srv_plst_hdr, index, &id); 
    *default_type = 0;
    
    for(i = 1; i < SRV_PLST_DEF_LIST_ENUM_END ; i = i<<1)
    {
        if (i & srv_plst_base->default_plst_config)
        {
            U32 temp_id;
            switch(i)
            {
                case SRV_PLST_DEF_MY_FAVOURITE:
                case SRV_PLST_DEF_MOST_PLST:
                case SRV_PLST_DEF_RECENTLY_PLST:
                case SRV_PLST_DEF_ON_THE_FLY:
                    temp_id = id_start|0X8000;  
                    if(temp_id == id)
                    {
                        *default_type = i;
                        break;
                    }
                    id_start++;
                    break;
                    
                default :
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_DEFAULT_PLST_GET_TYPE_RET, SRV_PLST_RET_ERR_PARAM_ERR, __LINE__);
                    return SRV_PLST_RET_ERR_PARAM_ERR;
            }
        }
        if(*default_type)
        {
            break;
        }
    }
    if(i >= SRV_PLST_DEF_LIST_ENUM_END && *default_type)
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_DEFAULT_PLST_GET_TYPE_RET, *default_type, __LINE__);
    
    return ret;
}


S32 srv_plst_default_playlist_get_type_info_by_id(U32 srv_plst_hdr, U32 id, srv_plst_default_playlist_enum *type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PLST_OK;
    U32 i;
    U32 id_start = 1;
    srv_plst_base_info_struct *srv_plst_base;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    *type = SRV_PLST_DEF_LIST_ENUM_END;
    for(i = 1; i < SRV_PLST_DEF_LIST_ENUM_END ; i = i<<1)
    {
        if (i & srv_plst_base->default_plst_config)
        {
            U32 temp_id;
            switch(i)
            {
                case SRV_PLST_DEF_MY_FAVOURITE:
                case SRV_PLST_DEF_MOST_PLST:
                case SRV_PLST_DEF_RECENTLY_PLST:
                case SRV_PLST_DEF_ON_THE_FLY:
                    temp_id = id_start|0X8000;  
                    if(temp_id == id)
                    {
                        *type = (srv_plst_default_playlist_enum)i;
                        return SRV_PLST_OK;
                    }
                    id_start++;
                    break;
                default :
                    return SRV_PLST_OK;
            }
        }
    }
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_plst_library_open
 * DESCRIPTION
 *   open the DB library and create/check DB, table, fill the default,after service is created, this action only do once time
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 *  name         :         [IN]   db name
 *  open_flag    :         [IN]   see srv_plst_open_flag_enum
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 srv_plst_library_open(U32 srv_plst_hdr, UI_string_type name, srv_plst_open_flag_enum open_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_db_context_struct *db_info;
    srv_plst_playing_context_struct *playing_info;
    srv_plst_list_view_history_struct *list_view_history;
    S32 ret = SRV_PLST_OK;
    S32 fs_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_LIB_OPEN, srv_plst_hdr, open_flag);       
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    db_info = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->db_info);    
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->playing_info);
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);
    mmi_ucs2ncpy((CHAR*) srv_plst_base->title, (const CHAR*) name, SRV_PLST_MAX_FILE_LEN - 1);

    kal_wsprintf((U16*)&db_info->db_card_path, "%c:\\%w\\%w%w.%w",SRV_FMGR_CARD_DRV,
                 SRV_PLST_DB_DEFAULT_FOLDER, name,SRV_PLST_DB_VERSION,SRV_PLST_DB_EXTENSION);
#if defined(__PLST_DUAL_DB_SUPPORT__)
    kal_wsprintf((U16*)&db_info->db_phone_path, "%c:\\%w\\%w%w.%w",SRV_FMGR_PUBLIC_DRV,
                 SRV_PLST_DB_DEFAULT_FOLDER, name,SRV_PLST_DB_VERSION,SRV_PLST_DB_EXTENSION);

    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        g_srv_plst_control_ptr->card_state = SRV_PLST_DRIVE_PHONE_ONLY;
    }
    else
    {
        g_srv_plst_control_ptr->card_state = SRV_PLST_DRIVE_CARD_EXIST;
    }
#else
    /* Use phone path variable to store card path */
    kal_wsprintf((U16*)&db_info->db_phone_path, "%c:\\%w\\%w%w.%w", SRV_FMGR_CARD_DRV,
                 SRV_PLST_DB_DEFAULT_FOLDER, name,SRV_PLST_DB_VERSION,SRV_PLST_DB_EXTENSION);

    if ((fs_result = FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM)) == FS_NO_ERROR)
    {
        /* Check if disk is busy */
        if ((fs_result = FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_FEATURE_STATE_ENUM)) == FS_NO_ERROR)
        {
            g_srv_plst_control_ptr->card_state = SRV_PLST_DRIVE_CARD_ONLY;
        }
        else
        {
            srv_plst_base->ture_err_code = fs_result;
            return SRV_PLST_RET_ERR_FS_ERROR;
        }
    }
    else
    {
        srv_plst_base->ture_err_code = fs_result;
        return SRV_PLST_RET_ERR_FS_ERROR;
    }
#endif /* __PLST_DUAL_DB_SUPPORT__ */

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_LIB_OPEN, g_srv_plst_control_ptr->card_state, 0);       
    if (open_flag == SRV_PLST_OPEN_NEW)
    {
        if (list_view_history)
        {
            /* MAUI_02451274 */
            srv_plst_view_type_enum type = list_view_history->view_type[0];
            memset(list_view_history, 0, sizeof(srv_plst_list_view_history_struct));
            list_view_history->view_type[0] = type;
        }

        if(playing_info)
        {
            memset(playing_info, 0, sizeof(srv_plst_playing_context_struct));
        }
        
        FS_Delete((U16*)&db_info->db_phone_path);
        if (IS_CARD_EXIST)
        {
            FS_Delete((U16*)&db_info->db_card_path);
        }
		db_info->open_flag = open_flag;
        srv_plst_base->is_open_cancel = MMI_FALSE;
        ret = srv_plst_pls_open_lib(srv_plst_base, open_flag);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_LIB_OPEN, ret, __LINE__);		
        return ret;

    }
    else if(open_flag == SRV_PLST_OPEN_ONLY)
    {
        FS_HANDLE fs_hdr;
//bql: MAUI_02661984
        fs_hdr = FS_Open((U16*)db_info->db_phone_path, FS_READ_ONLY);
        if(fs_hdr < FS_NO_ERROR)
        {
            MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_ERROR_HAPPEN, __LINE__);
            srv_plst_base->error_code =  SRV_PLST_RET_ERR_DB_NOT_FOUND;
            srv_plst_base->db_open_error = SRV_PLST_RET_ERR_DB_NOT_FOUND;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_LIB_OPEN, srv_plst_base->error_code, __LINE__);		             
            return srv_plst_base->error_code;
        }
        FS_Close(fs_hdr);

    #if defined(__PLST_DUAL_DB_SUPPORT__)
        if(IS_CARD_EXIST)
        {
            fs_hdr = FS_Open((U16*)db_info->db_card_path, FS_READ_ONLY);
            if(fs_hdr < FS_NO_ERROR)
            {
                MMI_TRACE(TRACE_GROUP_2, MMI_PLS_PLS_ERROR_HAPPEN, __LINE__);
                srv_plst_base->error_code =  SRV_PLST_RET_ERR_DB_NOT_FOUND;
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_LIB_OPEN, srv_plst_base->error_code, __LINE__);                  
                srv_plst_base->db_open_error = SRV_PLST_RET_ERR_DB_NOT_FOUND;
                return srv_plst_base->error_code;
            }
            FS_Close(fs_hdr);
        }
    #endif /* __PLST_DUAL_DB_SUPPORT__ */
        db_info->open_flag = open_flag;
        ret = srv_plst_pls_open_lib(srv_plst_base, open_flag);
        srv_plst_base->db_open_error = srv_plst_base->error_code;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_LIB_OPEN, srv_plst_base->error_code, __LINE__);                  
    }
    else if(open_flag == SRV_PLST_OPEN_AUTO)
    {
        srv_plst_base->is_open_cancel = MMI_FALSE;
        db_info->open_flag = open_flag;
        ret = srv_plst_pls_open_lib(srv_plst_base, SRV_PLST_OPEN_AUTO);                          
    }
    else if(open_flag == SRV_PLST_OPEN_AFTER_MEDIA_CHANGE)
    {   
        db_info->open_flag = open_flag;
        ret = srv_plst_pls_open_lib(srv_plst_base, open_flag);
        srv_plst_base->db_open_error = srv_plst_base->error_code;
    } 
    else
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
        srv_plst_base->error_code = ret;
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_LIB_OPEN, srv_plst_base->error_code, __LINE__);                  
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_library_stop_open
 * DESCRIPTION
 *   stop open lib after last open return is SRV_PLST_ASYNC
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 *  name         :         [IN]   db name
 *  open_flag    :         [IN]   see srv_plst_open_flag_enum
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 srv_plst_library_stop_open(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_LIB_STOP_OPEN, srv_plst_hdr, __LINE__);                  
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    srv_plst_base->is_open_cancel = MMI_TRUE;
    ret = srv_plst_pls_stop_open_lib(srv_plst_base);      
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_LIB_STOP_OPEN, ret, __LINE__);                  
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_library_close
 * DESCRIPTION
 *   close the DB library before destory service
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_library_close(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_LIB_CLOSE, srv_plst_hdr, __LINE__);                  
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    ret = srv_plst_pls_close_lib(srv_plst_base);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_LIB_CLOSE, ret, __LINE__);                  
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_library_update
 * DESCRIPTION
 *   add/update DB data (sync in another task PLS), scan the file system to find all media file 
 *        and then add to library by the class of audio/video. It need a long time, so use internal msg in the PLS 
 *       the find operation 
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_library_update(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_gen_lib_context_struct *gen;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_LIB_UPDATE, srv_plst_hdr, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)srv_plst_hdr)->gen); 
    memset(gen, 0, sizeof(srv_plst_gen_lib_context_struct));
    gen->run_type = SRV_PLST_GEN_SYNC_ALL;
    ret = srv_plst_pls_update_lib(srv_plst_base);    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_LIB_UPDATE, ret, __LINE__);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_library_stop_udpate
 * DESCRIPTION
 *   stop udpate DB, stop the udpate, use current data state when app query 
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_library_stop_udpate(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_db_context_struct* db;
    srv_plst_gen_lib_context_struct *gen;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_LIB_STOP_UPDATE, srv_plst_hdr, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->db_info);
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)srv_plst_hdr)->gen);
    ret = srv_plst_pls_stop_update_lib(srv_plst_base); 
    if(ret == SRV_PLST_OK)
    {
        if (gen->search_handle && gen->search_handle != FS_INVALID_FILE_HANDLE)
        {
            FS_FindClose(gen->search_handle);
            gen->search_handle = FS_INVALID_FILE_HANDLE;
        }
        if(db->enable_flag)
        {
            pls_sql_begin_transaction(db);
            pls_sql_rollback_transaction(db);
            pls_sql_end_transaction(db);
        }
        gen->run_type = SRV_PLST_GEN_NONE;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_LIB_STOP_UPDATE, ret, __LINE__);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_library_add
 * DESCRIPTION
 *   add file or add from folder to library,  similiar like srv_plst_library_udpate, but this cmd is only scan the input path,not all drives
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 *  path         :         [IN]   filepath or folder path
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_library_add(U32 srv_plst_hdr, UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_gen_lib_context_struct *gen;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_ADD, ret, __LINE__);
    if (path == NULL)
    {
        return SRV_PLST_OK;
    }
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)srv_plst_hdr)->gen);    
    memset(gen, 0, sizeof(srv_plst_gen_lib_context_struct));
    gen->run_type = SRV_PLST_GEN_ADD;
    mmi_ucs2ncpy((CHAR*)gen->path_cache, (const CHAR*)path, SRV_FMGR_PATH_MAX_LEN);
    gen->is_short = MMI_FALSE;   
    ret = srv_plst_pls_update_lib(srv_plst_base);    
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_ADD, ret, __LINE__);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_library_stop_add
 * DESCRIPTION
 *   stop add, smiliar like srv_plst_library_stop_udpate
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
S32 srv_plst_library_stop_add(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_db_context_struct* db;
    srv_plst_gen_lib_context_struct *gen;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_STOP_ADD, srv_plst_hdr, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->db_info);
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)srv_plst_hdr)->gen);
    ret = srv_plst_pls_stop_update_lib(srv_plst_base); 
    if(ret == SRV_PLST_OK)
    {
        if (gen->search_handle && gen->search_handle != FS_INVALID_FILE_HANDLE)
        {
            FS_FindClose(gen->search_handle);
            gen->search_handle = FS_INVALID_FILE_HANDLE;
        }
        if(db->enable_flag)
        {
            pls_sql_begin_transaction(db);
            pls_sql_rollback_transaction(db);
            pls_sql_end_transaction(db);
        }
        gen->run_type = SRV_PLST_GEN_NONE;
    }   
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_STOP_ADD, srv_plst_hdr, __LINE__);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_library_pause_update
 * DESCRIPTION
 *   pause udpate DB, between pause and resume, no any other service api can be called
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_library_pause_update(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_gen_lib_context_struct *gen;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_PAUSE_UPDATE, srv_plst_hdr, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)srv_plst_hdr)->gen); 
    ret = srv_plst_pls_pause_update_lib(srv_plst_base); 
    if (gen)
    {
        gen->run_type = SRV_PLST_GEN_NONE;
    }
    else
    {
        ret = SRV_PLST_RET_ERR_MEMORY_CONRRUPT;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_PAUSE_UPDATE, ret, __LINE__);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_library_stop_udpate
 * DESCRIPTION
 *   resume  udpate DB, between pause and resume, no any other service api can be called
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
extern S32 srv_plst_library_resume_update(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_gen_lib_context_struct *gen;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_RESUME_UPDATE, srv_plst_hdr, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    gen = (srv_plst_gen_lib_context_struct*)(((srv_plst_main_context_struct*)srv_plst_hdr)->gen);    
    ret = srv_plst_pls_resume_update_lib(srv_plst_base); 
    if (gen)
    {
        gen->run_type = SRV_PLST_GEN_NONE;
    }
    else
    {
        ret = SRV_PLST_RET_ERR_MEMORY_CONRRUPT;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_RESUME_UPDATE, ret, __LINE__);
    return ret;
}

extern S32 srv_plst_list_reset_all_list(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_view_history_struct* list_view_history;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_RESET_ALL_LIST, srv_plst_hdr, __LINE__);
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);
    if (list_view_history)
    {
        memset(list_view_history, 0, sizeof(srv_plst_list_view_history_struct));
    }
    else
    {
        ret = SRV_PLST_RET_ERR_MEMORY_NOT_ENOUGH; 
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_RESET_ALL_LIST, srv_plst_hdr, __LINE__);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_entry
 * DESCRIPTION
 *   use it as a first filter type, such as all audio list, all video list, artist list, album list
                   entry list type , set it each entry a filter, artist, artist'album ,album,all audio etc
                   but if you need entry artist first and then entry artist'album, you need code as below: 
                   SRV_PLST_CMD_LIST_ENTRY (SRV_PLST_VIEW_ROOT, SRV_PLST_VIEW_ARTIST )
                   SRV_PLST_CMD_LIST_ENTRY ( 2 ,SRV_PLST_VIEW_ALBUM)
                   SRV_PLST_CMD_LIST_EXIT
                   SRV_PLST_CMD_LIST_EXIT	
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  list_view_param    :         [IN]   see srv_plst_list_view_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
S32 srv_plst_list_entry(U32 srv_plst_hdr, srv_plst_list_view_struct *list_view_param )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* plst_view_history;
    srv_plst_view_type_enum view_type[SRV_PLST_VIEW_LIST_DEPTH];
    S32 ret = SRV_PLST_OK;
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if(list_view_param->is_id_used)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_ENTRY,srv_plst_hdr,list_view_param->id,list_view_param->view_type, __LINE__);
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_ENTRY,srv_plst_hdr,list_view_param->index,list_view_param->view_type, __LINE__);
    }
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    plst_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);
    ret = srv_plst_pls_entry_list(srv_plst_base);
    if(ret == SRV_PLST_OK)
    {
        /* check default list type if entry default playlist */
        if(plst_view_history->view_type[plst_view_history->current_index] == SRV_PLST_VIEW_PLST &&
           list_view_param->view_type == SRV_PLST_VIEW_MEDIA)
        {
            srv_plst_default_playlist_get_type(srv_plst_hdr, list_view_param->index, &plst_view_history->default_type);
        }    
        for(i = 0; i < SRV_PLST_VIEW_LIST_DEPTH; i++)
        {
            if(plst_view_history->view_type[i] == SRV_PLST_VIEW_DUMMY)
            {
                break;
            }  
        }
   
        if (i == SRV_PLST_VIEW_LIST_DEPTH)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_ENTRY,srv_plst_hdr,i,ret, __LINE__);
            return SRV_PLST_RET_ERR_MEMORY_NOT_ENOUGH;
        }
         
        plst_view_history->view_type[i] = (srv_plst_view_type_enum)list_view_param->view_type;
        plst_view_history->index[i] = list_view_param->index;
        plst_view_history->id[i] = list_view_param->id;
        plst_view_history->is_id_used[i] = list_view_param->is_id_used;
        plst_view_history->current_index = i;
        view_type[0] = plst_view_history->view_type[0];
        for (i = 0; i <= plst_view_history->current_index; i++)
        {
            view_type[i] = plst_view_history->view_type[i];
        }
        i--;

    #if defined(__PLST_DUAL_DB_SUPPORT__)
        ret = pls_db_util_check_disk_space_and_get_error(srv_plst_base, SRV_FMGR_PUBLIC_DRV, SRV_PLST_MIN_DRV_LEFT_SIZE);
        if(ret != SRV_PLST_OK)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_ENTRY,srv_plst_hdr,i,ret, __LINE__);
            return ret;
        }

        if(IS_CARD_EXIST)
    #endif /* __PLST_DUAL_DB_SUPPORT__ */
        {
            ret = pls_db_util_check_disk_space_and_get_error(srv_plst_base, SRV_FMGR_CARD_DRV, SRV_PLST_MIN_DRV_LEFT_SIZE);
            if(ret != SRV_PLST_OK)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_ENTRY,srv_plst_hdr,i,ret, __LINE__);
                return ret;
            }
        }

        if(plst_view_history->view_type[plst_view_history->current_index] == SRV_PLST_VIEW_IMAGE_FLOW)
        {
        }    
        else if(plst_view_history->current_index > 1 && plst_view_history->view_type[plst_view_history->current_index] == SRV_PLST_VIEW_MEDIA &&
            plst_view_history->view_type[plst_view_history->current_index - 1] == SRV_PLST_VIEW_IMAGE_FLOW)
        {
        }
        else if(plst_view_history->view_type[0] == SRV_PLST_VIEW_PLST_ADDTO)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_ENTRY,srv_plst_hdr,plst_view_history->current_index, 0, __LINE__);
            return SRV_PLST_RET_ERR_PARAM_ERR;
        }
        else if(plst_view_history->view_type[plst_view_history->current_index] == SRV_PLST_VIEW_PLST_ACTIVE)
        {
        }
        else if(!plst_view_history->current_index)
        {
            if(view_type[0] == SRV_PLST_VIEW_PLST_ADDTO)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_ENTRY,srv_plst_hdr,plst_view_history->current_index, 0, __LINE__);
                return SRV_PLST_RET_ERR_PARAM_ERR;
            }
        }
        else if(plst_view_history->current_index == 1)
        {
            if ((view_type[0] == SRV_PLST_VIEW_ARTIST && view_type[1] == SRV_PLST_VIEW_ALBUM) ||
                (view_type[0] == SRV_PLST_VIEW_ARTIST && view_type[1] == SRV_PLST_VIEW_MEDIA) ||
                (view_type[0] == SRV_PLST_VIEW_ALBUM && view_type[1] == SRV_PLST_VIEW_MEDIA) ||
                (view_type[0] == SRV_PLST_VIEW_GENRE && view_type[1] == SRV_PLST_VIEW_MEDIA) ||
                (view_type[0] == SRV_PLST_VIEW_PLST && view_type[1] == SRV_PLST_VIEW_MEDIA) ||
                (view_type[0] == SRV_PLST_VIEW_AUDIO  && view_type[1] == SRV_PLST_VIEW_PLST_ADDTO) ||
                (view_type[0] == SRV_PLST_VIEW_ALBUM  && view_type[1] == SRV_PLST_VIEW_PLST_ADDTO) ||
                (view_type[0] == SRV_PLST_VIEW_ARTIST && view_type[1] == SRV_PLST_VIEW_PLST_ADDTO) ||
                (view_type[0] == SRV_PLST_VIEW_GENRE  && view_type[1] == SRV_PLST_VIEW_PLST_ADDTO))
            {
            }
            else 
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_ENTRY,srv_plst_hdr,plst_view_history->current_index, 0, __LINE__);
                return SRV_PLST_RET_ERR_PARAM_ERR;
            }
        }
        else if(plst_view_history->current_index == 2)
        {
            if ((view_type[0] == SRV_PLST_VIEW_ARTIST && view_type[1] == SRV_PLST_VIEW_ALBUM && view_type[2] == SRV_PLST_VIEW_MEDIA) ||
                (view_type[0] == SRV_PLST_VIEW_ARTIST && view_type[1] == SRV_PLST_VIEW_ALBUM && view_type[2] == SRV_PLST_VIEW_PLST_ADDTO) ||
                (view_type[0] == SRV_PLST_VIEW_ARTIST && view_type[1] == SRV_PLST_VIEW_MEDIA && view_type[2] == SRV_PLST_VIEW_PLST_ADDTO) ||
                (view_type[0] == SRV_PLST_VIEW_ALBUM && view_type[1] == SRV_PLST_VIEW_MEDIA && view_type[2] == SRV_PLST_VIEW_PLST_ADDTO) ||
                (view_type[0] == SRV_PLST_VIEW_GENRE && view_type[1] == SRV_PLST_VIEW_MEDIA && view_type[2] == SRV_PLST_VIEW_PLST_ADDTO) ||
                (view_type[0] == SRV_PLST_VIEW_PLST && view_type[1] == SRV_PLST_VIEW_MEDIA && view_type[2] == SRV_PLST_VIEW_PLST_ADDTO) ||
                (view_type[0] == SRV_PLST_VIEW_PLST && view_type[1] == SRV_PLST_VIEW_MEDIA && view_type[2] == SRV_PLST_VIEW_AUDIO) || /* add from audio  lib */
                (view_type[0] == SRV_PLST_VIEW_PLST && view_type[1] == SRV_PLST_VIEW_MEDIA && view_type[2] == SRV_PLST_VIEW_ARTIST) || /* add from artist list*/
                (view_type[0] == SRV_PLST_VIEW_PLST && view_type[1] == SRV_PLST_VIEW_MEDIA && view_type[2] == SRV_PLST_VIEW_ALBUM) || /* add from album list */
                (view_type[0] == SRV_PLST_VIEW_PLST && view_type[1] == SRV_PLST_VIEW_MEDIA && view_type[2] == SRV_PLST_VIEW_GENRE) || /* add from genre list */
                (view_type[0] == SRV_PLST_VIEW_ARTIST && view_type[1] == SRV_PLST_VIEW_PREFIX_SEARCH && view_type[2] == SRV_PLST_VIEW_PLST_ADDTO) ||
                (view_type[0] == SRV_PLST_VIEW_ALBUM && view_type[1] == SRV_PLST_VIEW_PREFIX_SEARCH && view_type[2] == SRV_PLST_VIEW_PLST_ADDTO) ||
                (view_type[0] == SRV_PLST_VIEW_GENRE && view_type[1] == SRV_PLST_VIEW_PREFIX_SEARCH && view_type[2] == SRV_PLST_VIEW_PLST_ADDTO) ||
                (view_type[0] == SRV_PLST_VIEW_ARTIST && view_type[1] == SRV_PLST_VIEW_PREFIX_SEARCH && view_type[2] == SRV_PLST_VIEW_ALBUM) ||
                (view_type[0] == SRV_PLST_VIEW_ARTIST && view_type[1] == SRV_PLST_VIEW_PREFIX_SEARCH && view_type[2] == SRV_PLST_VIEW_MEDIA) ||
                (view_type[0] == SRV_PLST_VIEW_ALBUM && view_type[1] == SRV_PLST_VIEW_PREFIX_SEARCH && view_type[2] == SRV_PLST_VIEW_MEDIA) ||
                (view_type[0] == SRV_PLST_VIEW_GENRE && view_type[1] == SRV_PLST_VIEW_PREFIX_SEARCH && view_type[2] == SRV_PLST_VIEW_MEDIA) ||
                (view_type[0] == SRV_PLST_VIEW_AUDIO && view_type[1] == SRV_PLST_VIEW_PREFIX_SEARCH && view_type[2] == SRV_PLST_VIEW_PLST_ADDTO))
            {
            }
            else
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_ENTRY,srv_plst_hdr,plst_view_history->current_index, 0, __LINE__);                        
                return SRV_PLST_RET_ERR_PARAM_ERR;
            }        
        }
        else if(plst_view_history->current_index == 3)
        {
            if ((view_type[0] == SRV_PLST_VIEW_ARTIST && view_type[1] == SRV_PLST_VIEW_ALBUM &&
                view_type[2] == SRV_PLST_VIEW_MEDIA && view_type[3] == SRV_PLST_VIEW_PLST_ADDTO) ||
                (view_type[0] == SRV_PLST_VIEW_PLST && view_type[1] == SRV_PLST_VIEW_MEDIA &&
                view_type[2] == SRV_PLST_VIEW_ARTIST && view_type[3] == SRV_PLST_VIEW_MEDIA) || /* add from artist song llist */
                (view_type[0] == SRV_PLST_VIEW_PLST && view_type[1] == SRV_PLST_VIEW_MEDIA &&
                view_type[2] == SRV_PLST_VIEW_ALBUM && view_type[3] == SRV_PLST_VIEW_MEDIA) || /* add from album song llist */
               (view_type[0] == SRV_PLST_VIEW_PLST && view_type[1] == SRV_PLST_VIEW_MEDIA &&
                view_type[2] == SRV_PLST_VIEW_GENRE && view_type[3] == SRV_PLST_VIEW_MEDIA) || /* add from genre song llist */
               (view_type[0] == SRV_PLST_VIEW_PLST && view_type[1] == SRV_PLST_VIEW_MEDIA &&
                view_type[2] == SRV_PLST_VIEW_ARTIST && view_type[3] == SRV_PLST_VIEW_ALBUM) || /* add from artist album llist */
               (view_type[0] == SRV_PLST_VIEW_ARTIST && view_type[1] == SRV_PLST_VIEW_ALBUM &&
                view_type[2] == SRV_PLST_VIEW_PREFIX_SEARCH && view_type[3] == SRV_PLST_VIEW_PLST_ADDTO) ||
                (view_type[0] == SRV_PLST_VIEW_ARTIST && view_type[1] == SRV_PLST_VIEW_ALBUM &&
                view_type[2] == SRV_PLST_VIEW_PREFIX_SEARCH && view_type[3] == SRV_PLST_VIEW_MEDIA) ||
               (view_type[0] == SRV_PLST_VIEW_ARTIST && view_type[1] == SRV_PLST_VIEW_MEDIA  && view_type[2] == SRV_PLST_VIEW_PREFIX_SEARCH  && view_type[3] == SRV_PLST_VIEW_PLST_ADDTO) ||
                (view_type[0] == SRV_PLST_VIEW_ALBUM && view_type[1] == SRV_PLST_VIEW_MEDIA && view_type[2] == SRV_PLST_VIEW_PREFIX_SEARCH && view_type[3] == SRV_PLST_VIEW_PLST_ADDTO) ||
                (view_type[0] == SRV_PLST_VIEW_GENRE && view_type[1] == SRV_PLST_VIEW_MEDIA && view_type[2] == SRV_PLST_VIEW_PREFIX_SEARCH && view_type[3] == SRV_PLST_VIEW_PLST_ADDTO) ||
                (view_type[0] == SRV_PLST_VIEW_PLST && view_type[1] == SRV_PLST_VIEW_MEDIA && view_type[2] == SRV_PLST_VIEW_PREFIX_SEARCH && view_type[3] == SRV_PLST_VIEW_PLST_ADDTO) )
            {
            }
            else
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_ENTRY,srv_plst_hdr,plst_view_history->current_index, 0, __LINE__);
                return SRV_PLST_RET_ERR_PARAM_ERR;
            } 
        }
        else if(plst_view_history->current_index == 4)
        {
            if ((view_type[0] == SRV_PLST_VIEW_ARTIST && view_type[1] == SRV_PLST_VIEW_ALBUM &&
                view_type[2] == SRV_PLST_VIEW_MEDIA && view_type[3] == SRV_PLST_VIEW_PREFIX_SEARCH && view_type[4] == SRV_PLST_VIEW_PLST_ADDTO)||
               (view_type[0] == SRV_PLST_VIEW_PLST && view_type[1] == SRV_PLST_VIEW_MEDIA &&
                view_type[2] == SRV_PLST_VIEW_ARTIST && view_type[3] == SRV_PLST_VIEW_ALBUM && view_type[4] == SRV_PLST_VIEW_MEDIA) /* add from artist'album song llist */)
            {
            }
            else
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_ENTRY,srv_plst_hdr,plst_view_history->current_index, 0, __LINE__);
                return SRV_PLST_RET_ERR_PARAM_ERR;
            } 
        }
        else 
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_ENTRY,srv_plst_hdr,plst_view_history->current_index, 0, __LINE__);
            return SRV_PLST_RET_ERR_PARAM_ERR;
        }

        
        memset(&plst_view_history->list_cache[i], 0 , sizeof(srv_plst_list_context_struct)); 
        plst_view_history->query_index = 0;
        plst_view_history->total_count = 0;    

   
        if(i && list_view_param->index != SRV_PLST_VIEW_ROOT && !list_view_param->is_id_used &&
           (plst_view_history->view_type[plst_view_history->current_index] != SRV_PLST_VIEW_IMAGE_FLOW &&
           plst_view_history->view_type[plst_view_history->current_index] != SRV_PLST_VIEW_PLST_ADDTO))
        {
            U32 temp_id;

            ret = pls_db_util_get_id(&(plst_view_history->list_cache[i - 1]), list_view_param->index, &temp_id);
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_ENTRY,srv_plst_hdr,i, ret, __LINE__);
            if(ret == SRV_PLST_OK)
            {
                plst_view_history->list_cache[i].parent_id = temp_id;
                plst_view_history->id[i] = temp_id;
            } 
            else
            {
                return ret;
            }
        }
        else if(list_view_param->is_id_used)
        {
            plst_view_history->list_cache[i].parent_id = list_view_param->id;
        }
        else
        {
            plst_view_history->list_cache[0].parent_id = 0; /* phone id > 0X8000 */
            plst_view_history->id[0] = 0;
        }
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_ENTRY,srv_plst_hdr,ret, 0, __LINE__);
    return ret;    
}

   
/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_exit
 * DESCRIPTION
 *   set this cmd when exit the filter type, include the sub filter, such as artist'album
                      exit current list type, deinit
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
S32 srv_plst_list_exit(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* plst_view_history;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_EXIT,srv_plst_hdr,0, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    plst_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);
    ret = srv_plst_pls_exit_list(srv_plst_base);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_EXIT,ret, plst_view_history->current_index, __LINE__);
    if(plst_view_history->view_type[0] == SRV_PLST_VIEW_PLST &&
       plst_view_history->view_type[1] == SRV_PLST_VIEW_MEDIA)
    {
        plst_view_history->default_type = 0;
    } 
    if(ret == SRV_PLST_OK)
    {
        if (plst_view_history->current_index < SRV_PLST_VIEW_LIST_DEPTH && plst_view_history->current_index >= 0)
        {
            plst_view_history->view_type[plst_view_history->current_index] = SRV_PLST_VIEW_DUMMY ;
            plst_view_history->index[plst_view_history->current_index] = 0;
            plst_view_history->id[plst_view_history->current_index] = 0;
            plst_view_history->is_id_used[plst_view_history->current_index] = MMI_FALSE;
            plst_view_history->first_view_media_id[plst_view_history->current_index] = 0;
            plst_view_history->last_view_media_id[plst_view_history->current_index] = 0;
            memset(&(plst_view_history->list_cache[plst_view_history->current_index]), 0, sizeof(srv_plst_list_context_struct));
            plst_view_history->current_index -=1;

        #ifdef __COSMOS_MMI_PACKAGE__
            /* MAUI_03101796, when exit list, query_index will not clear and will cause pls_db_util_check_item_if_in_cache() get wrong direction to fill cache for first time
               Set query_index to current list cache head to make sure it can find correct asc or dsc direction */
            {
                U32 head = plst_view_history->list_cache[plst_view_history->current_index].head;
                plst_view_history->query_index = plst_view_history->list_cache[plst_view_history->current_index].cache[head].idx_in_list;
            }
        #else
            /* This is to make sure app will get count when list entry. In cosmos project, app will get count when change view type, so no need to get here */
            if(plst_view_history->current_index >= 0)
            {
                U32 count = 0;
                srv_plst_list_get_item_count(srv_plst_hdr, &count);
            }        
        #endif
        }
        else
        {
            ret = SRV_PLST_RET_ERR_PARAM_ERR;
        }
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_EXIT,ret, 0, __LINE__);
    return ret;
}
 


/*****************************************************************************
 * FUNCTION
 *  srv_plst_set_temp_memory
 * DESCRIPTION
 *   set temp memory for list cache to speed up the view
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  mem_ptr            :         [IN]   temp memory ptr
 *  mem_size           :         [IN]   temp_mem_size
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
extern S32 srv_plst_set_temp_memory(U32 srv_plst_hdr, void** mem_ptr, U32 mem_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_SET_MEMORY,srv_plst_hdr, mem_size, __LINE__);    
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    srv_plst_base->temp_memory_ptr = mem_ptr;
    srv_plst_base->temp_memory_size = mem_size;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_SET_MEMORY,srv_plst_hdr, 0, __LINE__); 
    return SRV_PLST_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_set_temp_memory
 * DESCRIPTION
 *   clear temp memory for list cache to speed up the view
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  mem_ptr            :         [IN]   temp memory ptr
 *  mem_size           :         [IN]   temp_mem_size
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
extern S32 srv_plst_clear_temp_memory(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_SET_MEMORY,srv_plst_hdr, 0, __LINE__);    
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    srv_plst_base->temp_memory_ptr = NULL;
    srv_plst_base->temp_memory_size = 0;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIB_SET_MEMORY,srv_plst_hdr, 0, __LINE__);    
    return ret;
}

    
/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_fixed_count
 * DESCRIPTION
 *   to get the count of fixed view
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  count              :         [IN]   count of selected
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
S32 srv_plst_list_get_fixed_count(U32 srv_plst_hdr, srv_plst_fixed_count_struct *view,  U32* count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* lv_history;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    lv_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ITEM_COUNT,srv_plst_hdr, 0, __LINE__);  

    // Count the song number for a specific artist
    if (view->view_stack[0].view_type == SRV_PLST_VIEW_ARTIST &&
        view->view_stack[1].view_type == SRV_PLST_VIEW_DUMMY &&
        view->view_stack[0].is_id_used == MMI_TRUE)
    {
        lv_history->bg_loading = MMI_FALSE;
        lv_history->nb_blocking_artwork = MMI_FALSE;
        ret = srv_plst_pls_get_show_data(srv_plst_base, lv_history, SRV_PLST_GET_ARTIST_MEDIA_COUNT_BY_ID,view->view_stack[0].id, count);
    }
    // Get count from active play list, no need to get from SQL command again. (Need to make sure active list has been set)
    else if (view->view_stack[0].view_type == SRV_PLST_VIEW_PLST_ACTIVE)
    {
        srv_plst_playing_context_struct *playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->playing_info);
        *count = playing_info->total;

        // Assign count value to history as pls_db_get_show_data() does
        lv_history->list_cache[lv_history->current_index].total = playing_info->total;
        lv_history->total_count = playing_info->total;

        return SRV_PLST_OK;
    }
    else
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ITEM_COUNT,ret, *count, __LINE__);    
    return ret;    
}
/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_item_count
 * DESCRIPTION
 *   to get the count of current list,artist id , album id or playlist id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  count              :         [IN]   count of selected
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
S32 srv_plst_list_get_item_count(U32 srv_plst_hdr, U32* count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* lv_history;
    S32 ret;
     /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    lv_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ITEM_COUNT,srv_plst_hdr, lv_history->current_index, __LINE__);    
    lv_history->bg_loading = MMI_FALSE;
    lv_history->nb_blocking_artwork = MMI_FALSE;

#if defined(__PLST_DUAL_DB_SUPPORT__)
    ret = pls_db_util_check_disk_space_and_get_error(srv_plst_base, SRV_FMGR_PUBLIC_DRV, SRV_PLST_MIN_DRV_LEFT_SIZE);
    if(ret != SRV_PLST_OK)
    {
        *count = 0;
        return ret;
    }
 
    if(IS_CARD_EXIST)
#endif /* __PLST_DUAL_DB_SUPPORT__*/
    {
        ret = pls_db_util_check_disk_space_and_get_error(srv_plst_base, SRV_FMGR_CARD_DRV, SRV_PLST_MIN_DRV_LEFT_SIZE);
        if(ret != SRV_PLST_OK)
        {
            *count = 0;
            return ret;
        }
    }

    /* For cosmos project, play trick to enhance the get count speed of back to tab page from now playing screen. 
       Use count in cache, if the list has changed, this value will be reset */
#ifdef __COSMOS_MMI_PACKAGE__
    if(lv_history->current_index == 0 && 
       (lv_history->view_type[0] == SRV_PLST_VIEW_AUDIO || lv_history->view_type[0] == SRV_PLST_VIEW_ARTIST || lv_history->view_type[0] == SRV_PLST_VIEW_ALBUM) &&
       lv_history->list_cache[0].total > 0)
    {
        lv_history->total_count = lv_history->list_cache[0].total;
        *count = lv_history->list_cache[0].total;
        ret = SRV_PLST_OK;
    }
    else
#endif
    {
        ret = srv_plst_pls_get_show_data(srv_plst_base, lv_history, SRV_PLST_GET_COUNT,0, count);
    }    

    if(ret == SRV_PLST_OK && lv_history->view_type[0] == SRV_PLST_VIEW_PLST &&
        lv_history->view_type[1] == SRV_PLST_VIEW_MEDIA && 
        (lv_history->default_type == SRV_PLST_DEF_MOST_PLST ||
        lv_history->default_type == SRV_PLST_DEF_RECENTLY_PLST ||
        lv_history->default_type == SRV_PLST_DEF_MY_FAVOURITE))
    {
        memset(lv_history->list_cache[1].cache, 0, SRV_PLST_VIEW_LIST_CACHE * sizeof(srv_plst_list_cache_struct));
        lv_history->list_cache[1].cache_num = 0;
        lv_history->list_cache[1].head = 0;
        lv_history->list_cache[1].tail = 0;
        lv_history->list_cache[1].first_index = 0;
        lv_history->list_cache[1].last_index = 0;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ITEM_COUNT,ret, *count, __LINE__);    
     return ret;    
}

#ifdef __PLST_SRV_FEATURE_GROUP_LIST__
S32 srv_plst_list_item_get_group_count(U32 srv_plst_hdr, srv_plst_list_group_item_info_struct* group_c)
{
    /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     srv_plst_base_info_struct* srv_plst_base;
     srv_plst_list_view_history_struct* lv_history;
     S32 ret;
      /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/ 
     MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_GROUP_COUNT,srv_plst_hdr, __LINE__);    
     srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
     lv_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
     ret = srv_plst_pls_get_group_data(srv_plst_base, lv_history, group_c);
     MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_GROUP_COUNT_RET,ret, group_c->group, lv_history->current_index, __LINE__);    
     return ret;
}
#endif

S32 srv_plst_media_get_id_in_group(U32 srv_plst_hdr, U32 group, U32 sub_index, U32 *id)
{
    /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     srv_plst_base_info_struct* srv_plst_base;
     srv_plst_list_view_history_struct* lv_history;
     S32 ret;
     U32 index = 0;
     U16 i = 0;
      /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/ 
     MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_PLST_MEDIA_GET_ID_IN_GROUP, srv_plst_hdr, group, sub_index);
     srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
     lv_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
     for(i = 0; i < group; i++)
     {
        index = lv_history->group[lv_history->current_index].group[i];
     }
     index += sub_index;
     ret = srv_plst_pls_get_show_data(srv_plst_base, lv_history, SRV_PLST_GET_MEDIA_ID, index, (U32*)id);     
     MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_PLST_MEDIA_GET_ID_IN_GROUP, ret, *id);
     return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_item_display
 * DESCRIPTION
 *  get the item display info such as name, set this action when need get item info to show 
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  item_display       :         [IN]   see srv_plst_list_get_display_struct idx:[IN] item index , buff_size: [IN]  buffer size buff_ptr:[out] buffer_point
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
S32 srv_plst_list_get_item_display(U32 srv_plst_hdr, srv_plst_list_get_display_struct* item_display)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ITEM_DISPLAY,srv_plst_hdr, item_display->index, __LINE__);    
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->bg_loading = MMI_FALSE;
    list_view_history->nb_blocking_artwork = MMI_FALSE;    
    ret = srv_plst_pls_get_show_data(srv_plst_base, list_view_history, SRV_PLST_GET_TITLE,item_display->index, (U32*)item_display);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ITEM_DISPLAY,srv_plst_hdr,ret, __LINE__);    
    return ret;   
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_item_id
 * DESCRIPTION
 *  get the item id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index       :         [IN]   
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
S32 srv_plst_list_get_item_id(U32 srv_plst_hdr, S32 index, U32 *id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ITEM_ID,srv_plst_hdr, index, __LINE__);    
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->bg_loading = MMI_FALSE;
    list_view_history->nb_blocking_artwork = MMI_FALSE;    
    ret = srv_plst_pls_get_show_data(srv_plst_base, list_view_history, SRV_PLST_GET_ITEM_ID, index, id);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ITEM_ID,srv_plst_hdr,ret, __LINE__);    
    return ret;   
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_prefix_search_begin
 * DESCRIPTION
 *  prefix search for input text for artist/ album/all tracks
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  item_display       :         [IN]   string searched           
 *  count              :         [OUT]  count                                               
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_prefix_search_begin(U32 srv_plst_hdr)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* plst_view_history;
    srv_plst_view_type_enum view_type;
    S32 ret = SRV_PLST_OK;
    U16 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_PREFIX_SEARCH_BEGIN,srv_plst_hdr, __LINE__);    
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    plst_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    ret = srv_plst_pls_entry_list(srv_plst_base);
    if(ret ==SRV_PLST_OK)
    {
        for(i = 0; i < SRV_PLST_VIEW_LIST_DEPTH; i++)
        {
            if(plst_view_history->view_type[i] == SRV_PLST_VIEW_DUMMY)
            {
                break;
            }  
        }

        if (i == SRV_PLST_VIEW_LIST_DEPTH)
        {
            return SRV_PLST_RET_ERR_MEMORY_NOT_ENOUGH;
        }

        plst_view_history->view_type[i] = SRV_PLST_VIEW_PREFIX_SEARCH;
        plst_view_history->current_index = i;
        plst_view_history->is_id_used[i] = MMI_FALSE;

        if(!i)
        {
            return SRV_PLST_RET_ERR_PARAM_ERR;
        }
        view_type = plst_view_history->view_type[i];
        
        if(view_type == SRV_PLST_VIEW_PLST_ADDTO)
        {
            return SRV_PLST_RET_ERR_PARAM_ERR;
        }   
        
        memset(&plst_view_history->list_cache[i], 0 , sizeof(srv_plst_list_context_struct)); 
        plst_view_history->query_index = 0;
        plst_view_history->total_count = 0; 
        plst_view_history->list_cache[i].parent_id = plst_view_history->list_cache[i - 1].parent_id;
    } 
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_prefix_search_do_search
 * DESCRIPTION
 *  prefix search for input text for artist/ album/all tracks
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  item_display       :         [IN]   string searched           
 *  count              :         [OUT]  count                                               
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_prefix_search_do_search(U32 srv_plst_hdr, U32 string, U32* count)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* plst_view_history;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_PREFIX_DO_SEARCH,srv_plst_hdr, __LINE__);    
    if(count == NULL)
    {
        return SRV_PLST_RET_ERR_PARAM_ERR;
    }
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    plst_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    mmi_ucs2ncpy((CHAR*)&plst_view_history->search, (const CHAR*)string, SRV_PLST_MAX_FILE_LEN - 1);  
   // if(srv_plst_base->config_search == SRV_PLST_SEARCH_BY_PREFIX_NEW_LIST)
    {
    memset(&plst_view_history->list_cache[plst_view_history->current_index], 0 , sizeof(srv_plst_list_context_struct)); 
    plst_view_history->list_cache[plst_view_history->current_index].parent_id = plst_view_history->list_cache[plst_view_history->current_index - 1].parent_id;
    }
   /*
    else
    {
        U32 id_parent;
        id_parent = plst_view_history->list_cache[plst_view_history->current_index].parent_id;
        memset(&plst_view_history->list_cache[plst_view_history->current_index], 0 , sizeof(srv_plst_list_context_struct)); 
        plst_view_history->list_cache[plst_view_history->current_index].parent_id = id_parent;
    }
    */
    plst_view_history->query_index = 0;
    plst_view_history->total_count = 0;  
    if(!mmi_ucs2strlen((const CHAR*)string))
    {
        *count = 0;
    }
    else
    {
        ret = srv_plst_pls_get_prefix_search_count(srv_plst_base, count);  
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_LIST_PREFIX_DO_SEARCH_RET, ret, *count);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_prefix_search_get_display
 * DESCRIPTION
 *  get the tile for show the prefix search result
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  param_display      :         [IN/OUT]   see srv_plst_list_get_display_struct idx:[IN] item index , buff_size: [IN]  buffer size buff_ptr:[out] buffer_point          
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_prefix_search_get_display(U32 srv_plst_hdr, srv_plst_list_get_display_struct * param_display)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/     
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->bg_loading = MMI_FALSE;
    list_view_history->nb_blocking_artwork = MMI_FALSE;
    ret = srv_plst_pls_get_show_data(srv_plst_base, list_view_history, SRV_PLST_GET_TITLE,param_display->index, (U32*)param_display);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_prefix_search_end
 * DESCRIPTION
 *  exit the prefix search
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_prefix_search_end(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* plst_view_history;
    S32 ret = SRV_PLST_RET_ERR_PARAM_ERR;
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_PREFIX_SEARCH_END,srv_plst_hdr, __LINE__);    
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    plst_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    ret = srv_plst_pls_exit_list(srv_plst_base);
    if(ret == SRV_PLST_OK )
    {
        if (plst_view_history->current_index < SRV_PLST_VIEW_LIST_DEPTH && 
            plst_view_history->current_index > 0 )
        {
            for(i = 1; i <= plst_view_history->current_index; i++)
            {
                if(plst_view_history->view_type[i] == SRV_PLST_VIEW_PREFIX_SEARCH)
                {
                    U8 j;
                    for( j = i; j < plst_view_history->current_index; j++)
                    {
                        plst_view_history->view_type[j] = plst_view_history->view_type[j + 1];
                        plst_view_history->index[j] = plst_view_history->index[j + 1];
                        plst_view_history->id[j] = plst_view_history->id[j + 1];
                        plst_view_history->is_id_used[i] = plst_view_history->is_id_used[j + 1];
                        plst_view_history->first_view_media_id[j] = plst_view_history->first_view_media_id[j + 1];
                        plst_view_history->last_view_media_id[j] = plst_view_history->last_view_media_id[j + 1];
                        memcpy(&(plst_view_history->list_cache[j]), &(plst_view_history->list_cache[j+ 1]), sizeof(srv_plst_list_context_struct));
                    }
                    plst_view_history->view_type[j] = SRV_PLST_VIEW_DUMMY;
                    plst_view_history->index[j] = 0;
                    plst_view_history->id[j] = 0;
                    plst_view_history->is_id_used[j] = MMI_FALSE;
                    plst_view_history->first_view_media_id[j] = 0;
                    plst_view_history->last_view_media_id[j] = 0;
                    memset(&(plst_view_history->list_cache[j]), 0, sizeof(srv_plst_list_context_struct));
                    plst_view_history->current_index -=1;
                    plst_view_history->search[0] = 0;
                    ret = SRV_PLST_OK;
                    break;
                }                
            }
        }
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_hint_count
 * DESCRIPTION
 *   to get the count of sub item for hint show
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   sub item index 
 *  count              :         [IN]   count of selected
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
S32 srv_plst_list_get_hint_count(U32 srv_plst_hdr, U32 index, U32* count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ITEM_HINE_COUNT,srv_plst_hdr, index, __LINE__);    
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->nb_blocking_artwork = MMI_FALSE;
    list_view_history->hint_type = SRV_PLST_VIEW_MEDIA;
    ret = srv_plst_pls_get_show_data(srv_plst_base, list_view_history, SRV_PLST_GET_HINT_COUNT,index, count);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ITEM_HINE_COUNT,ret, *count, __LINE__);    
    return ret; 
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_prefix_search_begin
 * DESCRIPTION
 *  prefix search for input text for artist/ album/all tracks
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  item_display       :         [IN]   string searched           
 *  count              :         [OUT]  count                                               
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_search_begin(U32 srv_plst_hdr)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* plst_view_history;
    srv_plst_view_type_enum view_type;
    S32 ret = SRV_PLST_OK;
    U16 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_PREFIX_SEARCH_BEGIN,srv_plst_hdr, __LINE__);    
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    plst_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    ret = srv_plst_pls_entry_list(srv_plst_base);
    
    if(ret ==SRV_PLST_OK )
    {
        for(i = 0; i < SRV_PLST_VIEW_LIST_DEPTH; i++)
        {
            if(plst_view_history->view_type[i] == SRV_PLST_VIEW_DUMMY)
            {
                break;
            }  
        }

        if (i == SRV_PLST_VIEW_LIST_DEPTH)
        {
            return SRV_PLST_RET_ERR_MEMORY_NOT_ENOUGH;
        }

        plst_view_history->view_type[i] = SRV_PLST_VIEW_PREFIX_SEARCH;
        plst_view_history->current_index = i;
        plst_view_history->is_id_used[i] = MMI_FALSE;

        if(!i)
        {
            return SRV_PLST_RET_ERR_PARAM_ERR;
        }
        view_type = plst_view_history->view_type[i];
        
        if(view_type == SRV_PLST_VIEW_PLST_ADDTO)
        {
            return SRV_PLST_RET_ERR_PARAM_ERR;
        }   
        
        memset(&plst_view_history->list_cache[i], 0 , sizeof(srv_plst_list_context_struct)); 
        plst_view_history->query_index = 0;
        plst_view_history->total_count = 0; 
        plst_view_history->list_cache[i].parent_id = plst_view_history->list_cache[i - 1].parent_id;
    }
    return ret;
}


S32 srv_plst_list_search_sync(U32 srv_plst_hdr, U32 string, U32* count)
{
    /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     srv_plst_base_info_struct* srv_plst_base;
     srv_plst_list_view_history_struct* plst_view_history;
     S32 ret = SRV_PLST_OK;
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/ 
     MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_PREFIX_DO_SEARCH,srv_plst_hdr, __LINE__);    
     if(count == NULL)
     {
         return SRV_PLST_RET_ERR_PARAM_ERR;
     }
     srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
     plst_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
     mmi_ucs2ncpy((CHAR*)&plst_view_history->search, (const CHAR*)string, SRV_PLST_MAX_FILE_LEN - 1);  
     memset(&plst_view_history->list_cache[plst_view_history->current_index], 0 , sizeof(srv_plst_list_context_struct)); 
     plst_view_history->list_cache[plst_view_history->current_index].parent_id = plst_view_history->list_cache[plst_view_history->current_index - 1].parent_id;
     plst_view_history->query_index = 0;
     plst_view_history->total_count = 0;  
    if(!mmi_ucs2strlen((const CHAR*)string))
    {
        *count = 0;
    }
    else
    {
         ret = srv_plst_pls_get_prefix_search_count(srv_plst_base, count);  
    }
     MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_LIST_PREFIX_DO_SEARCH_RET, ret, *count);
     return ret;
}


S32 srv_plst_list_search_async(U32 srv_plst_hdr, U32 string)
{
    /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     srv_plst_base_info_struct* srv_plst_base;
     srv_plst_list_view_history_struct* plst_view_history;
     S32 ret = SRV_PLST_OK;
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/ 
     MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_PREFIX_DO_SEARCH,srv_plst_hdr, __LINE__);    
  
     srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
     plst_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
     mmi_ucs2ncpy((CHAR*)&plst_view_history->search, (const CHAR*)string, SRV_PLST_MAX_FILE_LEN - 1);  
     memset(&plst_view_history->list_cache[plst_view_history->current_index], 0 , sizeof(srv_plst_list_context_struct)); 
     plst_view_history->list_cache[plst_view_history->current_index].parent_id = plst_view_history->list_cache[plst_view_history->current_index - 1].parent_id;
     plst_view_history->query_index = 0;
     plst_view_history->total_count = 0;  
     ret = srv_plst_pls_search(srv_plst_base);  
     MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_MMI_LIST_PREFIX_DO_SEARCH_RET, ret);
     return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_prefix_search_end
 * DESCRIPTION
 *  exit the prefix search
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_search_end(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* plst_view_history;
    S32 ret = SRV_PLST_RET_ERR_PARAM_ERR;
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_PREFIX_SEARCH_END,srv_plst_hdr, __LINE__);    
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    plst_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    ret = srv_plst_pls_exit_list(srv_plst_base);
    if(ret == SRV_PLST_OK )
    {
        if (plst_view_history->current_index < SRV_PLST_VIEW_LIST_DEPTH && 
            plst_view_history->current_index > 0 )
        {
            for(i = 1; i <= plst_view_history->current_index; i++)
            {
                if(plst_view_history->view_type[i] == SRV_PLST_VIEW_PREFIX_SEARCH)
                {
                    U8 j;
                    for( j = i; j < plst_view_history->current_index; j++)
                    {
                        plst_view_history->view_type[j] = plst_view_history->view_type[j + 1];
                        plst_view_history->index[j] = plst_view_history->index[j + 1];
                        plst_view_history->id[j] = plst_view_history->id[j + 1];
                        plst_view_history->is_id_used[i] = plst_view_history->is_id_used[j + 1];
                        plst_view_history->first_view_media_id[j] = plst_view_history->first_view_media_id[j + 1];
                        plst_view_history->last_view_media_id[j] = plst_view_history->last_view_media_id[j + 1];
                        memcpy(&(plst_view_history->list_cache[j]), &(plst_view_history->list_cache[j+ 1]), sizeof(srv_plst_list_context_struct));
                    }
                    plst_view_history->view_type[j] = SRV_PLST_VIEW_DUMMY;
                    plst_view_history->index[j] = 0;
                    plst_view_history->id[j] = 0;
                    plst_view_history->is_id_used[j] = MMI_FALSE;
                    plst_view_history->first_view_media_id[j] = 0;
                    plst_view_history->last_view_media_id[j] = 0;
                    memset(&(plst_view_history->list_cache[j]), 0, sizeof(srv_plst_list_context_struct));
                    plst_view_history->current_index -=1;
                    plst_view_history->search[0] = 0;
                    ret = SRV_PLST_OK;
                    break;
                }                
            }
            
        }
    }
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_hint_count_ex
 * DESCRIPTION
 *   to get the count of sub item for hint show
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   sub item index 
 *  count              :         [IN]   count of selected
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
S32 srv_plst_list_get_hint_count_ex(U32 srv_plst_hdr, U32 index, srv_plst_view_type_enum get_count_type, U32* count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ITEM_HINE_COUNT_EX,srv_plst_hdr, index, __LINE__);    
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->nb_blocking_artwork = MMI_FALSE;
    list_view_history->hint_type = get_count_type;
    ret = srv_plst_pls_get_show_data(srv_plst_base, list_view_history, SRV_PLST_GET_HINT_COUNT,index, count);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ITEM_HINE_COUNT_EX,ret, *count, __LINE__);    
    return ret; 
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_artwork_parser_path_by_media_id
 * DESCRIPTION
 *  get the path the file path that used to parse artwork
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index       :         [IN]   
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/  
S32 srv_plst_list_get_artwork_parser_path_by_media_id(U32 srv_plst_hdr, srv_plst_list_get_display_struct* param_artwork_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_PLST_LIST_GET_ARTWORK_BY_MEDIA_ID, srv_plst_hdr, param_artwork_path->index, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->bg_loading = MMI_FALSE;
    list_view_history->nb_blocking_artwork = MMI_FALSE;
    ret = srv_plst_pls_get_show_data(srv_plst_base, list_view_history, SRV_PLST_GET_ARTWORK_PARSER_PATH_BY_ID,param_artwork_path->index, (U32*)param_artwork_path);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLS_PLST_LIST_GET_ARTWORK_BY_MEDIA_ID, srv_plst_hdr, ret, __LINE__);
    return ret; 
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_artwork_by_media_id
 * DESCRIPTION
 *   get the artwokdata of selected media id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  param_artwork      :         [OUT]  see srv_plst_list_get_display_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_get_artwork_by_media_id(U32 srv_plst_hdr, srv_plst_list_get_display_struct* param_artwork)
{
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ARTWORK_BY_ID,srv_plst_hdr,param_artwork->index, __LINE__);    
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->bg_loading = MMI_FALSE;
    list_view_history->nb_blocking_artwork = MMI_FALSE;
    ret = srv_plst_pls_get_show_data(srv_plst_base, list_view_history, SRV_PLST_GET_ARTWORK_BY_ID,param_artwork->index, (U32*)param_artwork);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ARTWORK_BY_ID,srv_plst_hdr,ret, __LINE__);    
    return ret; 
}



/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_item_artwork
 * DESCRIPTION
 *   get the artwokdata of selected album
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   sub item index 
 *  param_artwork      :         [OUT]  see srv_plst_list_get_display_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_get_item_artwork(U32 srv_plst_hdr,srv_plst_list_get_display_struct* param_artwork)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ARTWORK,srv_plst_hdr,param_artwork->index, __LINE__);    
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->bg_loading = MMI_FALSE;
    list_view_history->nb_blocking_artwork = MMI_FALSE;
    ret = srv_plst_pls_get_show_data(srv_plst_base, list_view_history, SRV_PLST_GET_ARTWORK,param_artwork->index, (U32*)param_artwork);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ARTWORK,srv_plst_hdr,ret, __LINE__);    
    return ret; 
}

S32 srv_plst_list_update_item_artwork(U32 srv_plst_hdr, U32 index, UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_UPDATE_ARTWORK,srv_plst_hdr,index, __LINE__);    
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->bg_loading = MMI_FALSE;
    list_view_history->is_nb_update_artwork = MMI_FALSE;
    ret = srv_plst_pls_update_show_data(srv_plst_base, list_view_history, SRV_PLST_UPDATE_ARTWORK,index, path);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_UPDATE_ARTWORK,srv_plst_hdr,ret, __LINE__);    
    return ret; 
}

S32 srv_plst_list_update_item_artwork_async(U32 srv_plst_hdr, U32 index, UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_UPDATE_ARTWORK_ASYC,srv_plst_hdr,index, __LINE__);    
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->bg_loading = MMI_FALSE;
    list_view_history->is_nb_update_artwork = MMI_TRUE;
    ret = srv_plst_pls_update_show_data(srv_plst_base, list_view_history, SRV_PLST_UPDATE_ARTWORK,index, path);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_UPDATE_ARTWORK_ASYC,srv_plst_hdr,ret, __LINE__);    
    return ret; 
}


S32 srv_plst_list_stop_update_item_artwork(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_STOP_UPDATE_ARTWORK,srv_plst_hdr, __LINE__);    
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->bg_loading = MMI_FALSE;
    list_view_history->is_stop_update_artwork = MMI_TRUE;
    ret = srv_plst_pls_stop_update_artwork(srv_plst_base, list_view_history, SRV_PLST_UPDATE_ARTWORK);   
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_STOP_UPDATE_ARTWORK,srv_plst_hdr, __LINE__);    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_item_artwork_async
 * DESCRIPTION
 *   get the artwokdata of selected album(non blocking)
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   sub item index 
 *  param_artwork      :         [OUT]  see srv_plst_list_get_display_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_get_item_artwork_async(U32 srv_plst_hdr,srv_plst_list_get_display_struct* param_artwork)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ARTWORK_ASYC,srv_plst_hdr,param_artwork->index, __LINE__);    
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    if (list_view_history->view_type[list_view_history->current_index] == SRV_PLST_VIEW_ALBUM)
    {
        ret = srv_plst_media_get_id(srv_plst_hdr, param_artwork->index, &g_srv_plst_query_album_id);
    }
    else
    {
        g_srv_plst_query_album_id = 0;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_PLST_LIST_GET_ITEM_ARTWORK_ASYNC, g_srv_plst_query_album_id, ret, __LINE__);

    list_view_history->bg_loading = MMI_FALSE;
    list_view_history->nb_blocking_artwork = MMI_TRUE;
    list_view_history->is_get_data_cancel = MMI_FALSE;
    ret = srv_plst_pls_get_show_data(srv_plst_base, list_view_history, SRV_PLST_GET_ARTWORK,param_artwork->index, (U32*)param_artwork);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ARTWORK_ASYC,srv_plst_hdr,ret, __LINE__);    
    return ret; 
}



/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_get_item_artwork_async_stop
 * DESCRIPTION
 *   stop the getting the artwokdata of selected album(non blocking)
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   sub item index 
 *  param_artwork      :         [OUT]  see srv_plst_list_get_display_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_get_item_artwork_async_stop(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_STOP_ARTWORK,srv_plst_hdr, __LINE__);    
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->is_get_data_cancel = MMI_TRUE;
    ret = srv_plst_pls_stop_get_show_data(srv_plst_base, list_view_history, SRV_PLST_GET_ARTWORK);   
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_STOP_ARTWORK,srv_plst_hdr, __LINE__);    
    return ret; 
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_media_add_to_playlist
 * DESCRIPTION
 *   add the selected media/ artist id/ album id to playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   index  >=0 add selected type/index to playlist; -1  add marked server to playlist 
 *  param_artwork      :         [OUT]  see srv_plst_list_get_display_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_media_add_to_playlist(U32 srv_plst_hdr, S32 index, U32 plst_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ADD_TO_PLST,srv_plst_hdr,index, plst_idx, __LINE__); 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->is_add_cancel = MMI_FALSE;
    list_view_history->added_id = 0;
    list_view_history->sort_id = 0;
    list_view_history->mark_count = 0;
    list_view_history->prog_count = 0;
    ret = srv_plst_pls_add_media_to_plst(srv_plst_base, index, plst_idx);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ADD_TO_PLST,srv_plst_hdr,ret, 0, __LINE__);
    return ret; 
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_media_stop_add_to_playlist
 * DESCRIPTION
 *   stop to add the selected media/ artist id/ album id to playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_media_stop_add_to_playlist(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_STOP_ADD_TO_PLST,srv_plst_hdr,__LINE__); 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->is_add_cancel = MMI_TRUE;
    ret = srv_plst_pls_stop_add_media_to_plst(srv_plst_base);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_STOP_ADD_TO_PLST,ret,__LINE__); 
    return ret; 
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_media_get_id
 * DESCRIPTION
 *   get the current id in current list, and return media_id when in song list
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   index
 *  id_info            :         [OUT]  see srv_plst_list_item_info
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_media_get_id(U32 srv_plst_hdr, U32 index, U32* id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_MEDIA_GET_ID,srv_plst_hdr, index,__LINE__); 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->nb_blocking_artwork = MMI_FALSE;
    ret = srv_plst_pls_get_show_data(srv_plst_base, list_view_history, SRV_PLST_GET_MEDIA_ID,index, (U32*)id);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_MEDIA_GET_ID,ret, *id,__LINE__);   
    return ret; 
}
      
      
/*****************************************************************************
 * FUNCTION
 *  srv_plst_media_get_path
 * DESCRIPTION
 *   get the path in current list, and return media'path info
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  path_info          :         [OUT]  see srv_plst_list_get_display_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_media_get_path(U32 srv_plst_hdr, srv_plst_list_get_display_struct* path_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_MEDIA_GET_PATH,srv_plst_hdr, path_info->index,__LINE__); 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->nb_blocking_artwork = MMI_FALSE;

    if(list_view_history->view_type[list_view_history->current_index] == SRV_PLST_VIEW_MEDIA ||
        list_view_history->view_type[list_view_history->current_index] == SRV_PLST_VIEW_AUDIO ||
        list_view_history->view_type[list_view_history->current_index] == SRV_PLST_VIEW_VIDEO ||
        list_view_history->view_type[list_view_history->current_index] == SRV_PLST_VIEW_PLST_ACTIVE ||
        (list_view_history->view_type[list_view_history->current_index] == SRV_PLST_VIEW_PREFIX_SEARCH) &&
        list_view_history->current_index > 0 && (list_view_history->view_type[list_view_history->current_index - 1] == SRV_PLST_VIEW_MEDIA ||
        list_view_history->view_type[list_view_history->current_index - 1] == SRV_PLST_VIEW_AUDIO ||
        list_view_history->view_type[list_view_history->current_index - 1] == SRV_PLST_VIEW_VIDEO))
    {
        ret = srv_plst_pls_get_show_data(srv_plst_base, list_view_history, SRV_PLST_GET_PATH,path_info->index, (U32*)path_info);
    }
    else
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_MEDIA_GET_PATH,srv_plst_hdr,ret,__LINE__); 
    return ret; 
}

      
/*****************************************************************************
 * FUNCTION
 *  srv_plst_media_get_details
 * DESCRIPTION
 *   get the details of the selected media_id, the detail info check srv_plst_media_details_struct
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  id_info            :         [IN]   see srv_plst_list_item_info
 *  details            :         [OUT]  see srv_plst_media_details_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/      
S32 srv_plst_media_get_details(U32 srv_plst_hdr, U32 id, srv_plst_media_details_struct *details_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_MEDIA_GET_DETAILS,srv_plst_hdr, id,__LINE__); 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->bg_loading = MMI_FALSE;
    list_view_history->nb_blocking_artwork = MMI_FALSE;
    ret = srv_plst_pls_get_show_data(srv_plst_base, list_view_history, SRV_PLST_GET_DETAILS, (U32)id, (U32*)details_info);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_MEDIA_GET_DETAILS,ret, 0,__LINE__); 
    return ret; 
}

S32 srv_plst_media_get_details_by_filter(U32 srv_plst_hdr, U32 id, srv_plst_media_details_struct *details_info, U32 field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_MEDIA_GET_DETAILS,srv_plst_hdr, id,__LINE__); 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->bg_loading = MMI_FALSE;
    list_view_history->nb_blocking_artwork = MMI_FALSE;
    ret = srv_plst_pls_get_show_data(srv_plst_base, list_view_history, SRV_PLST_GET_DETAILS_BY_FILTER, (U32)id, (U32*)details_info);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_MEDIA_GET_DETAILS,ret, 0,__LINE__); 
    return ret; 
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_media_update_details
 * DESCRIPTION
 *  update the details of the select media_id, the detail info check srv_plst_media_details_struct
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  id_info            :         [IN]   see srv_plst_list_item_info
 *  details            :         [IN]  see srv_plst_media_details_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/      
S32 srv_plst_media_update_details(U32 srv_plst_hdr, U32 id, srv_plst_media_details_struct* details_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_MEDIA_UPDATE_DETAILS,srv_plst_hdr, id,__LINE__); 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->bg_loading = MMI_FALSE;
    list_view_history->nb_blocking_artwork = MMI_FALSE;
    ret = srv_plst_pls_get_show_data(srv_plst_base, list_view_history, SRV_PLST_GET_DETAILS_UPDATE, id, (U32*)details_info);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_MEDIA_UPDATE_DETAILS,ret, id,__LINE__); 
    return ret; 
}

#ifdef __PLST_SRV_FEATURE_MOST_RECENT_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_plst_media_update_playing_info
 * DESCRIPTION
 *  update the play count and play time of the select media_id after played in the app
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  id_info            :         [IN]   see srv_plst_list_item_info
 *  details            :         [IN]  see srv_plst_media_details_struct
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_media_update_playing_info(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_playing_context_struct* playing_info;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_MEDIA_UPDATE_PLAYING_INFO,srv_plst_hdr, 0,__LINE__); 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->playing_info);
    if(playing_info->is_load && (playing_info->active_type == SRV_PLST_ACTIVE_LIST_AUDIO ||
        playing_info->active_type == SRV_PLST_ACTIVE_LIST_PLST
     #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
        || playing_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_AUDIO ||
        playing_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_PLST
     #endif
        ))
    {
        ret = srv_plst_pls_update_playing_info(srv_plst_base, playing_info->current_picked_id);  
    }
    else
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_MEDIA_UPDATE_PLAYING_INFO_RET,srv_plst_hdr, ret,__LINE__); 
    return ret;
}
#endif /*__PLST_SRV_FEATURE_MOST_RECENT_LIST__*/

/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_multi_select_mark_begin
 * DESCRIPTION
 *  begin multi mark 
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_multi_select_mark_begin(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_MARK_BEGIN,srv_plst_hdr,__LINE__); 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->is_mark = MMI_TRUE;
    list_view_history->is_mark_all = MMI_FALSE;
    list_view_history->is_unmark_all = MMI_FALSE;
    ret = srv_plst_pls_create_mark_tbl(srv_plst_base, MMI_TRUE);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_MARK_BEGIN,ret,__LINE__); 
    if(ret != SRV_PLST_OK)
    {
        list_view_history->is_mark = MMI_FALSE;
    }

    if(ret == SRV_PLST_OK && list_view_history->view_type[0] == SRV_PLST_VIEW_PLST && !list_view_history->current_index)
    {
        memset(&(list_view_history->list_cache[0].cache), 0, SRV_PLST_VIEW_LIST_CACHE * sizeof(srv_plst_list_cache_struct));
        list_view_history->list_cache[0].cache_num = 0;
        list_view_history->list_cache[0].first_index = 0;
        list_view_history->list_cache[0].last_index = 0;
        list_view_history->list_cache[0].head = 0;
        list_view_history->list_cache[0].tail = 0;
        ret = srv_plst_list_get_item_count(srv_plst_hdr, &list_view_history->total_count);
    }
    return ret; 
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_multi_select_mark_end
 * DESCRIPTION
 *  end multi mark 
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_multi_select_mark_end(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_MARK_END,srv_plst_hdr,__LINE__); 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->is_mark = MMI_FALSE;
    list_view_history->is_mark_all = MMI_FALSE;
    list_view_history->is_unmark_all = MMI_FALSE;

    // Drop mark table (To speed up create next time)
    // Add/delete to play list will DROP mark table in the end of operation, it that case it will return fail here, so do not check error cause here
    srv_plst_pls_create_mark_tbl(srv_plst_base, MMI_FALSE);

    if(ret == SRV_PLST_OK && list_view_history->view_type[0] == SRV_PLST_VIEW_PLST && !list_view_history->current_index)
    {
        memset(&(list_view_history->list_cache[0].cache), 0, SRV_PLST_VIEW_LIST_CACHE * sizeof(srv_plst_list_cache_struct));
        list_view_history->list_cache[0].cache_num = 0;
        list_view_history->list_cache[0].first_index = 0;
        list_view_history->list_cache[0].last_index = 0;
        list_view_history->list_cache[0].head = 0;
        list_view_history->list_cache[0].tail = 0;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_MARK_END,ret,__LINE__); 
    return ret; 
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_multi_select_set_mark
 * DESCRIPTION
 *  mark the select or unmark when multi-select
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   item index
 *  is_mark            :         [IN]   MMI_TRUE:  mark   MMI_FALSE: unmark
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_multi_select_set_mark(U32 srv_plst_hdr, U32 index, MMI_BOOL is_mark)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_SET_MARK,srv_plst_hdr,index, is_mark, __LINE__); 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    ret = srv_plst_pls_multi_select_set_mark(srv_plst_base, index, is_mark);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_SET_MARK,ret, 0, 0, __LINE__); 
    return ret; 
}

    
/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_multi_select_get_mark
 * DESCRIPTION
 *  get the mark the select or unmar state when multi-select in current list
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   item index
 *  is_mark            :         [OUT]   MMI_TRUE:  mark   MMI_FALSE: unmark
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_multi_select_get_mark(U32 srv_plst_hdr, U32 index, MMI_BOOL* is_mark)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_MARK,srv_plst_hdr,index, __LINE__);     
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    ret = srv_plst_pls_multi_select_get_mark(srv_plst_base, index, is_mark);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_MARK,ret, *is_mark, __LINE__); 
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_multi_select_mark_all
 * DESCRIPTION
 *  mark/ unmark all current list when multi-select
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  is_mark            :         [OUT]   MMI_TRUE:  mark   MMI_FALSE: unmark
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_multi_select_mark_all(U32 srv_plst_hdr, MMI_BOOL is_mark)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_MARK_ALL,srv_plst_hdr, is_mark, __LINE__); 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    

    if(is_mark)
    {
        list_view_history->is_mark_all = MMI_TRUE;
        list_view_history->is_unmark_all = MMI_FALSE;
    }
    else
    {
        list_view_history->is_unmark_all = MMI_TRUE;
        list_view_history->is_mark_all = MMI_FALSE;        
    }  
    // Recreate mark table
    srv_plst_pls_create_mark_tbl(srv_plst_base, MMI_TRUE);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_MARK_ALL,ret, 0, __LINE__); 
    return ret; 
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_set_as_active
 * DESCRIPTION
 *  set the current index to active and update into database
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   active index
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_set_as_active(U32 srv_plst_hdr, U32 index)
{
    return srv_plst_list_set_as_active_ex(srv_plst_hdr, index, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_set_as_active_ex
 * DESCRIPTION
 *  set the current index to active , 
 *  if update_db is false, update to DB by using srv_plst_list_update_current_active_to_db()
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   active index
 *  update_db          :         [IN]   is update to DB after set active
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_set_as_active_ex(U32 srv_plst_hdr, U32 index, MMI_BOOL update_db)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_SET_ACTIVE,srv_plst_hdr, index, __LINE__); 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);

    if(!list_view->total_count)
    {
        return SRV_PLST_RET_EMPTY;
    }
    else
    {
        /* Use index to update active playing info, and check if need to update to database immediately */
        ret = srv_plst_pls_set_as_active(srv_plst_base, index, update_db, MMI_FALSE);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_SET_ACTIVE,ret, 0, __LINE__); 
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_update_current_active_to_db
 * DESCRIPTION
 *  Use current playing info in the context and update it to database table
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_update_current_active_to_db(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_SET_ACTIVE,srv_plst_hdr, 0, __LINE__); 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);

    if(!list_view->total_count)
    {
        return SRV_PLST_RET_EMPTY;
    }
    else
    {
        /* Use current playing list info to update it to database */
        ret = srv_plst_pls_set_as_active(srv_plst_base, 0, MMI_TRUE, MMI_TRUE);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_SET_ACTIVE,ret, 0, __LINE__); 
    return ret;
}


 /*****************************************************************************
 * FUNCTION
 *  srv_plst_list_item_delete
 * DESCRIPTION
 *  delete the selected/ multi-select item, or artist id, album id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   item index 
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_item_delete(U32 srv_plst_hdr, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_DELETE,srv_plst_hdr, index, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->is_delete_cancel = MMI_FALSE;
    list_view_history->is_add_cancel = MMI_FALSE;
    list_view_history->is_get_data_cancel = MMI_FALSE;
    list_view_history->is_cancel = MMI_FALSE;
    list_view_history->mark_count = 0;
    list_view_history->prog_count = 0;
    ret = srv_plst_pls_list_item_delete(srv_plst_base, index);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_DELETE, ret, 0, __LINE__);
    return ret;
}

 
/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_item_delete
 * DESCRIPTION
 *  delete the selected/ multi-select item, or artist id, album id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   item index 
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_item_stop_delete(U32 srv_plst_hdr, U32*count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_STOP_DELETE,srv_plst_hdr, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->is_delete_cancel = MMI_TRUE;
    ret = srv_plst_pls_list_item_stop_delete(srv_plst_base, count);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_STOP_DELETE,ret, __LINE__);
    return ret;
}
 
/*****************************************************************************
 * FUNCTION
  *  srv_plst_get_plst_index_by_name
  * DESCRIPTION
  *   To query playlist index by input playlist name
  * PARAMETERS
  *  srv_plst_hdr       :         [IN]   service handle
  *  name               :         [IN]   playlist name
  *  index            :           [OUT]  plst index
  * RETURNS
  *  return error code  S32
  *                     < 0 error code
  *                     >=0 see srv_plst_caller_handler_enum 
  *****************************************************************************/ 
 S32 srv_plst_get_plst_index_by_name(U32 srv_plst_hdr, UI_string_type name, U32* index)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     srv_plst_base_info_struct* srv_plst_base;
     S32 ret;
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/ 
     //temp log
     MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_CREATE,srv_plst_hdr, __LINE__);
     srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
     ret = srv_plst_pls_get_plst_index(srv_plst_base, name, index);
     MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_CREATE,ret, __LINE__);
     return ret;
 }
/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_create
 * DESCRIPTION
 *   create new playlist, unable to create a exist name 
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  name               :         [IN]   playlist name
 *  id_info            :         [OUT]  playlist id info in the db  see srv_plst_list_item_info
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_create(U32 srv_plst_hdr, UI_string_type name, U32* id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_CREATE,srv_plst_hdr, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    ret = srv_plst_pls_plst_create(srv_plst_base, name, id_info);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_CREATE,ret, __LINE__);
    #if 0 //for test
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    return ret;
}

 
 /*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_delete
 * DESCRIPTION
 *  delete the selected playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   index
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_delete(U32 srv_plst_hdr, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    srv_plst_view_type_enum view_type;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_DELETE,srv_plst_hdr,index, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    view_type = list_view_history->view_type[0];
    list_view_history->is_delete_cancel = MMI_FALSE;
    list_view_history->is_add_cancel = MMI_FALSE;
    list_view_history->is_get_data_cancel = MMI_FALSE;
    list_view_history->is_cancel = MMI_FALSE;
    list_view_history->mark_count = 0;
    list_view_history->prog_count = 0;
    if((view_type == SRV_PLST_VIEW_PLST && !list_view_history->current_index) ||
       (list_view_history->current_index == 1 && view_type == SRV_PLST_VIEW_PLST && 
        list_view_history->view_type[1] == SRV_PLST_VIEW_PREFIX_SEARCH))
    {
        list_view_history->is_delete_cancel = MMI_FALSE;
        ret = srv_plst_pls_plst_delete(srv_plst_base, index);
    }
    else
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_DELETE,ret,0, __LINE__);
    return ret;
}



/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_stop_delete
 * DESCRIPTION
 *  delete the selected playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   index
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_stop_delete(U32 srv_plst_hdr, U32 *count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_STOP_DELETE,srv_plst_hdr, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    list_view_history->is_delete_cancel = MMI_TRUE;
    ret = srv_plst_pls_plst_stop_delete(srv_plst_base, count);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_STOP_DELETE,ret, __LINE__);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_rename
 * DESCRIPTION
 *  rename the selected playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  name               :         [IN]   new name 
 *  index              :         [IN]   index
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_rename(U32 srv_plst_hdr, UI_string_type name, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    srv_plst_view_type_enum view_type;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_RENAME,srv_plst_hdr,index, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    view_type = list_view_history->view_type[list_view_history->current_index];

    // Rename in play list, play list songs, and add to play list
    if(view_type == SRV_PLST_VIEW_PLST || 
       view_type == SRV_PLST_VIEW_PLST_ADDTO ||
       ((list_view_history->current_index > 0) && (list_view_history->view_type[list_view_history->current_index - 1] == SRV_PLST_VIEW_PLST)))
    {
        ret = srv_plst_pls_plst_rename(srv_plst_base, name, index);
    }
    else
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_RENAME,ret,0, __LINE__);
    return ret;
}
 

//bql: MAUI_02455062
/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_clear_curr_view_cache
 * DESCRIPTION
 *  clear up current view stack cache for the skip query data from pls
 *  notes: this api will not effect parent_id and total num for curr view
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_clear_curr_view_cache(U32 srv_plst_hdr, MMI_BOOL clear_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_context_struct *list_cache;
    srv_plst_list_view_history_struct* list_view_history;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_PLST_CLEAR_CURR_VIEW_CACHE, srv_plst_hdr, __LINE__);
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);
    list_cache = &(list_view_history->list_cache[list_view_history->current_index]);
    list_cache->first_index = 0;
    list_cache->last_index = 0;
    list_cache->head = 0;
    list_cache->tail = 0;
    list_cache->cache_num = 0;
    if(clear_count)
    {
        list_cache->total = 0;
    }
    memset(&(list_cache->cache[0]), 0 , sizeof(srv_plst_list_cache_struct)*SRV_PLST_VIEW_LIST_CACHE);

    return SRV_PLST_OK;    
}

/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_clear_active_list
 * DESCRIPTION
 *  clear up active playing list info
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_clear_active_list(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_playing_context_struct *playing_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    playing_ptr= (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->playing_info);    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_PLST_CLEAR_ACTIVE_LIST, srv_plst_hdr,playing_ptr->is_load, __LINE__);
    memset(playing_ptr, 0 ,sizeof(srv_plst_playing_context_struct));
    return SRV_PLST_OK;    
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_get_plst_id
 * DESCRIPTION
 *   get plst_id of the selected  playlist
 *       this action only used in all playlist's list
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   index
 *  id_info            :         [OUT]  U32
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_get_plst_id(U32 srv_plst_hdr, U32 index, U32* id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    srv_plst_view_type_enum view_type;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_GET_PLST_ID,srv_plst_hdr,index, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);    
    view_type = list_view_history->view_type[list_view_history->current_index];
    if(view_type == SRV_PLST_VIEW_PLST || view_type == SRV_PLST_VIEW_PLST_ADDTO)
    {
        ret = srv_plst_pls_get_plst_id(srv_plst_base, index, id);
    }
    else
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_GET_PLST_ID,ret,*id, __LINE__);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_get_active_plst_item_index
 * DESCRIPTION
 *   get active playing list item index
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [OUT]  U32 
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/
S32 srv_plst_plst_get_active_plst_item_index(U32 srv_plst_hdr, U32 *index)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_playing_context_struct *playing_ptr;
    srv_plst_base_info_struct *srv_plst_base;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_GET_ACTIVE_LIST_INDEX,srv_plst_hdr, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);
    playing_ptr= (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->playing_info);    
    if(playing_ptr->is_load && playing_ptr->is_playing_change)
    {
        ret = srv_plst_pls_get_active_index(srv_plst_base, SRV_PLST_ACTIVE_MEDIA, index); 
        if(ret == SRV_PLST_OK)
        {
            *index = playing_ptr->pick_index;
            playing_ptr->is_playing_change = MMI_FALSE;
        }
    }
    else        
    {
        *index = playing_ptr->pick_index;
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_GET_ACTIVE_LIST_INDEX,*index, __LINE__);
    return SRV_PLST_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_get_active_index
 * DESCRIPTION
 *   get active index in current list, currently only support for cover flow active album index
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [OUT]  U32 
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/
S32 srv_plst_plst_get_active_index(U32 srv_plst_hdr, srv_plst_active_type_enum type,  U32 *index)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_GET_ACTIVE_LIST_INDEX,srv_plst_hdr, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);
    ret = srv_plst_pls_get_active_index(srv_plst_base, type, index);    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_GET_ACTIVE_LIST_INDEX,*index, __LINE__);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_get_active_plst_id
 * DESCRIPTION
 *   get active playing list id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  id                 :         [OUT]  U32 
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_get_active_plst_id(U32 srv_plst_hdr, U32 *id)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_playing_context_struct *playing_ptr;
    srv_plst_playing_context_struct playing;
    S32 ret = SRV_PLST_OK; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_GET_ACTIVE_LIST_ID,srv_plst_hdr, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    playing_ptr = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->playing_info);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_GET_ACTIVE_LIST_INDEX,playing_ptr->is_load, __LINE__);
    *id = 0;
    if(!playing_ptr->is_load)
    {
    	memset(&playing, 0 ,sizeof(srv_plst_playing_context_struct));
        if(srv_plst_base->config_store_play_info == SRV_PLST_PLAY_INFO_STORE ||
           srv_plst_base->config_store_play_info == SRV_PLST_PLAY_INFO_STORE_MANUAL)
        {
    	    ret = srv_plst_pls_get_playing_info(srv_plst_base, &playing);    
    	    if(ret == SRV_PLST_OK)
            {
                playing.is_load = MMI_TRUE;
                memcpy((srv_plst_playing_context_struct*)playing_ptr, (srv_plst_playing_context_struct*)&playing, 
                    sizeof(srv_plst_playing_context_struct));
                *id = playing_ptr->plst_id;
    	    }
        }
    }
	else
    {
    	*id = playing_ptr->plst_id;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_GET_ACTIVE_LIST_INDEX,ret,*id);
    return ret;
}


S32 srv_plst_get_active_plst_item_count(U32 srv_plst_hdr, U32 *count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_playing_context_struct *playing_ptr;
    srv_plst_playing_context_struct playing;
    S32 ret = SRV_PLST_OK; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    playing_ptr = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->playing_info);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_GET_ACTIVE_LIST_LIEM_COUNT,srv_plst_hdr, playing_ptr->is_load, __LINE__);
    *count = 0;
    if(!playing_ptr->is_load)
    {
    	memset(&playing, 0 ,sizeof(srv_plst_playing_context_struct));
        if(srv_plst_base->config_store_play_info == SRV_PLST_PLAY_INFO_STORE ||
           srv_plst_base->config_store_play_info == SRV_PLST_PLAY_INFO_STORE_MANUAL)
        {
    	    ret = srv_plst_pls_get_playing_info(srv_plst_base, &playing);    
    	    if(ret == SRV_PLST_OK)
    	    {
               playing.is_load = MMI_TRUE;
                memcpy((srv_plst_playing_context_struct*)playing_ptr, (srv_plst_playing_context_struct*)&playing, 
                    sizeof(srv_plst_playing_context_struct));
                *count = playing_ptr->total;
    	    }
        }
    }
	else
    {
    	*count = playing_ptr->total;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_PLST_GET_ACTIVE_LIST_LIEM_COUNT,ret, *count, __LINE__);
    return ret;
}

#ifdef __PLST_SRV_DEFAULT_LIST__
/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_default_list_entry
 * DESCRIPTION
 *  exit default playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  def_list           :         [IN]   see srv_plst_default_playlist_enum
 *  id                 :         [OUT]  U32
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_default_list_entry(U32 srv_plst_hdr,srv_plst_default_playlist_enum def_list)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* plst_view_history;
    srv_plst_playing_context_struct *playing_info;
    S32 ret = SRV_PLST_OK;
    U32 id_start = 1;
    U32 i;
    U32 tmp_num = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ENTRY_DEFAULT_LIST,srv_plst_hdr, def_list, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    plst_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->playing_info);
    ret = srv_plst_pls_entry_list(srv_plst_base);
    if(ret == SRV_PLST_OK)
    {
    for(i = 0; i < SRV_PLST_VIEW_LIST_DEPTH; i++)
    {
        if(plst_view_history->view_type[i] == SRV_PLST_VIEW_DUMMY)
        {
            break;
        }  
    }

    plst_view_history->view_type[i] = SRV_PLST_VIEW_PLST_DEFAULT;
    plst_view_history->is_id_used[i] = MMI_FALSE;
    plst_view_history->current_index = i;
    
    memset(&plst_view_history->list_cache[i], 0 , sizeof(srv_plst_list_context_struct)); 
    plst_view_history->query_index = 0;
    plst_view_history->total_count = 0;
    plst_view_history->plst_id = 0;
    plst_view_history->default_type = SRV_PLST_DEF_ACTIVE_LIST;
    if(def_list == SRV_PLST_DEF_ACTIVE_LIST)
    {
        ret = srv_plst_plst_get_active_plst_id(srv_plst_hdr,&plst_view_history->plst_id);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ENTRY_DEFAULT_LIST,ret, plst_view_history->plst_id, __LINE__);
            if(playing_info->is_load)
            {
                srv_plst_list_get_item_count(srv_plst_hdr, &tmp_num);
                srv_plst_pls_get_show_data(srv_plst_base, plst_view_history, SRV_PLST_GET_MEDIA_ID, playing_info->pick_index, &tmp_num);
            }
        if(plst_view_history->plst_id)
        {
            return ret;
        }
        else
	{
            return SRV_PLST_OK;
        }
    }
    
    for(i = 1; i < SRV_PLST_DEF_LIST_ENUM_END ; i = i<<1)
    {
        if (i & srv_plst_base->default_plst_config)
        {
            U32 temp_id ;
            switch(i)
            {
                case SRV_PLST_DEF_MY_FAVOURITE:
                case SRV_PLST_DEF_MOST_PLST:
                case SRV_PLST_DEF_RECENTLY_PLST:
                    temp_id = id_start|0X8000;  
                    if(i == def_list)
                    {
                        plst_view_history->plst_id = temp_id;
                        break;
                    }
                    id_start++;
                    break;
                    
                default :
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ENTRY_DEFAULT_LIST,SRV_PLST_RET_ERR_PARAM_ERR,0, __LINE__);
                    return SRV_PLST_RET_ERR_PARAM_ERR;
            }
        }
    }   
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ENTRY_DEFAULT_LIST,ret,0, __LINE__);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_plst_list_default_list_exit
 * DESCRIPTION
 *  exit default playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_list_default_list_exit(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* plst_view_history;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    plst_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_EXIT_DEFAULT_LIST,srv_plst_hdr,plst_view_history->current_index, __LINE__);
    ret = srv_plst_pls_exit_list(srv_plst_base);
    if(ret == SRV_PLST_OK)
    {
        if (plst_view_history->current_index < SRV_PLST_VIEW_LIST_DEPTH && 
            plst_view_history->current_index >= 0                        && 
            plst_view_history->view_type[plst_view_history->current_index] == SRV_PLST_VIEW_PLST_DEFAULT)
        {
            plst_view_history->view_type[(U16)plst_view_history->current_index] = SRV_PLST_VIEW_DUMMY;
            plst_view_history->index[(U16)plst_view_history->current_index] = 0;
            plst_view_history->first_view_media_id[(U16)plst_view_history->current_index] = 0;
            plst_view_history->last_view_media_id[(U16)plst_view_history->current_index] = 0;
            memset(&(plst_view_history->list_cache[(U16)plst_view_history->current_index]), 0, sizeof(srv_plst_list_context_struct));
            plst_view_history->current_index -=1;
            plst_view_history->search[0] = 0;
        }
        else
        {
            ret = SRV_PLST_RET_ERR_PARAM_ERR;
        }
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_EXIT_DEFAULT_LIST,ret,0, __LINE__);
    return ret;
}

#endif /* __PLST_SRV_DEFAULT_LIST__ */

/*****************************************************************************
 * FUNCTION
 *  srv_plst_get_active_list_media_type
 * DESCRIPTION
 *  get media type of active list
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  srv_plst_active_list_media_type_enum  
 *****************************************************************************/ 
srv_plst_active_list_media_type_enum srv_plst_get_active_list_media_type(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables 											   */
    /*----------------------------------------------------------------*/
    srv_plst_playing_context_struct* play_info;	 
    srv_plst_active_list_media_type_enum ret = SRV_PLST_ACTIVE_LIST_TYPE_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body													   */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ACITVE_LIST_TYPE,srv_plst_hdr, __LINE__);
    play_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->playing_info);

    if(play_info->active_type == SRV_PLST_ACTIVE_LIST_VIDEO || 
        #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
        play_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_VIDEO ||
        #endif
        play_info->active_type == SRV_PLST_ACTIVE_LIST_STREAM_LINK )
    {
        ret =  SRV_PLST_ACTIVE_LIST_TYPE_VIDEO;
    }
    else if(play_info->active_type == SRV_PLST_ACTIVE_LIST_AUDIO ||
        #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
        play_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_AUDIO ||
        play_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_PLST|| 
        #endif
        play_info->active_type == SRV_PLST_ACTIVE_LIST_PLST)
    {
        if(play_info->active_type == SRV_PLST_ACTIVE_LIST_PLST 
            #ifdef __MARK_SEVERAL_PLAY_SUPPORT__
            || play_info->active_type == SRV_PLST_ACTIVE_LIST_TEMP_PLST
            #endif
           )
        {
            srv_plst_default_playlist_enum  type;

            srv_plst_default_playlist_get_type_info_by_id(srv_plst_hdr, play_info->plst_id, &type);
            if(type == SRV_PLST_DEF_MOST_PLST || type == SRV_PLST_DEF_RECENTLY_PLST)
            {
                ret = SRV_PLST_ACTIVE_LIST_TYPE_AUDIO_DYNAMIC_LIST;
            }
            else
            {
                ret = SRV_PLST_ACTIVE_LIST_TYPE_AUDIO;
            }
        }
        else
        {
            ret=  SRV_PLST_ACTIVE_LIST_TYPE_AUDIO;
        }
    }
    else
    {
        ret = SRV_PLST_ACTIVE_LIST_TYPE_NONE;
     }
     MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ACITVE_LIST_TYPE,ret, __LINE__);
     return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_get_active_list_type
 * DESCRIPTION
 *  get media type of active list
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  srv_plst_active_list_media_type_enum  
 *****************************************************************************/ 
srv_plst_active_list_enum srv_plst_get_active_list_type(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables 											   */
    /*----------------------------------------------------------------*/
    srv_plst_playing_context_struct* play_info;	 
    srv_plst_active_list_enum ret = SRV_PLST_ACTIVE_LIST_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body													   */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ACITVE_LIST_TYPE,srv_plst_hdr, __LINE__);
    play_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->playing_info);
    ret = play_info->active_type;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ACITVE_LIST_TYPE,ret, __LINE__);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_remove
 * DESCRIPTION
 *  remove the item form the playlist 
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   index
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_item_remove(U32 srv_plst_hdr, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    srv_plst_view_type_enum view_type, view_type1,view_type2;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_REMOVE,srv_plst_hdr,index, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);
    view_type = list_view_history->view_type[list_view_history->current_index];
    list_view_history->is_delete_cancel = MMI_FALSE;
    list_view_history->is_add_cancel = MMI_FALSE;
    list_view_history->is_get_data_cancel = MMI_FALSE;
    list_view_history->is_cancel = MMI_FALSE;
    list_view_history->mark_count = 0;
    list_view_history->prog_count = 0;
    if(list_view_history->current_index == 2)
    {
        view_type1 = list_view_history->view_type[0];
        view_type2 = list_view_history->view_type[1];
    }
    else
    {
        view_type1 = SRV_PLST_VIEW_DUMMY;
        view_type2 = SRV_PLST_VIEW_DUMMY;
    }
    if(view_type == SRV_PLST_VIEW_MEDIA || view_type == SRV_PLST_VIEW_PLST_ACTIVE ||
        (view_type == SRV_PLST_VIEW_PREFIX_SEARCH &&
         view_type1 == SRV_PLST_VIEW_PLST          &&
         view_type2 == SRV_PLST_VIEW_MEDIA         &&
         list_view_history->current_index == 2 ))

    {
        list_view_history->is_clear = MMI_FALSE;
        ret = srv_plst_pls_remove(srv_plst_base, index);
    }
    else
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_REMOVE,ret,list_view_history->current_index, __LINE__);
    return ret;
}



/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_stop_remove
 * DESCRIPTION
 *  stop remove the item form the playlist 
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index              :         [IN]   index
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_item_stop_remove(U32 srv_plst_hdr, U32 *count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    srv_plst_view_type_enum view_type, view_type1,view_type2;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_STOP_REMOVE,srv_plst_hdr, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);
    view_type = list_view_history->view_type[list_view_history->current_index];
    if(list_view_history->current_index == 2)
    {
        view_type1 = list_view_history->view_type[0];
        view_type2 = list_view_history->view_type[1];
    }
    else
    {
        view_type1 = SRV_PLST_VIEW_DUMMY;
        view_type2 = SRV_PLST_VIEW_DUMMY;
    }
    if(view_type == SRV_PLST_VIEW_MEDIA || 
        (view_type == SRV_PLST_VIEW_PREFIX_SEARCH &&
         view_type1 == SRV_PLST_VIEW_PLST          &&
         view_type2 == SRV_PLST_VIEW_MEDIA         &&
         list_view_history->current_index == 2 ))

    {
        ret = srv_plst_pls_stop_remove(srv_plst_base, count);
    }
    else
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_STOP_REMOVE,ret, __LINE__);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_check_exist_in_plst
 * DESCRIPTION
 *  check the selected if exist in playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  flag               :         [IN]   MMI_TRUE/ MMI_FALSE
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_config_set_media_unique_in_plst(U32 srv_plst_hdr, MMI_BOOL flag)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_list_view_history_struct* plst_view_history;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    plst_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);
    plst_view_history->is_media_in_plst_unique = flag;
    return SRV_PLST_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_reorder_begin
 * DESCRIPTION
 *  begin reorder play list item
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_item_reorder_begin(U32 srv_plst_hdr)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;
    srv_plst_list_context_struct *list_cache;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_REORDER_BEGIN,srv_plst_hdr, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);
    list_view_history->is_reorder = MMI_TRUE;
    ret = srv_plst_pls_entry_list(srv_plst_base);
    
    if(ret == SRV_PLST_OK && srv_plst_base->config_reorder == SRV_PLST_PLST_REORDER_CONTINUE)
    {
        if(!( list_view_history->view_type[0] == SRV_PLST_VIEW_PLST && list_view_history->view_type[1] == SRV_PLST_VIEW_MEDIA))
        {
            ret = SRV_PLST_RET_ERR_PARAM_ERR;
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_REORDER_BEGIN,ret, __LINE__);
            return ret;
        }
        
        list_cache = &(list_view_history->list_cache[list_view_history->current_index]);
        list_cache->first_index = 0;
        list_cache->last_index = 0;
        list_cache->head = 0;
        list_cache->tail = 0;
        list_cache->cache_num = 0;
        memset(&(list_cache->cache[0]), 0 , sizeof(srv_plst_list_cache_struct)*SRV_PLST_VIEW_LIST_CACHE);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_REORDER_BEGIN,ret, __LINE__);
    return ret;    
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_reorder_get_display
 * DESCRIPTION
 *  get reorder display
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_item_reorder_get_display(U32 srv_plst_hdr,srv_plst_list_get_display_struct * param_display)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_REORDER_GET_DISPLAY,srv_plst_hdr, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);
    list_view_history->bg_loading = MMI_FALSE;
    list_view_history->nb_blocking_artwork = MMI_FALSE;
    ret = srv_plst_pls_get_show_data(srv_plst_base, list_view_history, SRV_PLST_GET_TITLE,param_display->index, (U32*)param_display);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_REORDER_GET_DISPLAY,ret, __LINE__);
    return ret;   
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_reorder_action
 * DESCRIPTION
 *  reorder action
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  index_orign        :         [IN]   origin location index
 *  index_dest         :         [IN]   destination location idnex   
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_item_reorder_action(U32 srv_plst_hdr, U32 index_orign, U32 index_dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_REORDER_ACTION,srv_plst_hdr,index_orign, index_dest, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);
    if(list_view_history->current_index == 1 && list_view_history->view_type[0] == SRV_PLST_VIEW_PLST &&
       list_view_history->view_type[1] == SRV_PLST_VIEW_MEDIA && list_view_history->is_reorder == MMI_TRUE)
    {
        ret = srv_plst_pls_plst_item_reorder(srv_plst_base, index_orign, index_dest);
    }
    else 
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_REORDER_ACTION,ret,0, 0, __LINE__);
    return ret; 
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_reorder_action_set_result
 * DESCRIPTION
 *  reorder playlist result, only used when config as SRV_PLST_PLST_REORDER_CONTINUE
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_item_reorder_action_set_result(U32 srv_plst_hdr, MMI_BOOL save_notice)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_REORDER_RESULT,srv_plst_hdr,save_notice, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);
    if(list_view_history->current_index == 1 && list_view_history->view_type[0] == SRV_PLST_VIEW_PLST &&
       list_view_history->view_type[1] == SRV_PLST_VIEW_MEDIA && list_view_history->is_reorder == MMI_TRUE)
    {
        if(srv_plst_base->config_reorder == SRV_PLST_PLST_REORDER_CONTINUE)
        {
            ret = srv_plst_pls_plst_item_reorder_set_result(srv_plst_base, save_notice);
        }
        else 
        {
            ret = SRV_PLST_OK;
        }
    }
    else 
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_REORDER_RESULT,ret,0, __LINE__);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_reorder_end
 * DESCRIPTION
 *  reorder playlist end
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_item_reorder_end(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;
	srv_plst_list_context_struct *list_cache;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_REORDER_END,srv_plst_hdr, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);
	list_cache = &(list_view_history->list_cache[list_view_history->current_index]);
    ret = srv_plst_pls_exit_list(srv_plst_base);
    list_view_history->is_reorder = MMI_FALSE;

    if(ret == SRV_PLST_OK && srv_plst_base->config_reorder == SRV_PLST_PLST_REORDER_CONTINUE)
    {
	    list_cache->first_index = 0;
	    list_cache->last_index = 0;
	    list_cache->head = 0;
	    list_cache->tail = 0;
	    list_cache->cache_num = 0;
	    memset(&(list_cache->cache[0]), 0 , sizeof(srv_plst_list_cache_struct)*SRV_PLST_VIEW_LIST_CACHE);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ITEM_REORDER_END,ret, __LINE__);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_clear
 * DESCRIPTION
 *  clear current playlist's all item
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_item_clear(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    srv_plst_view_type_enum view_type;
    S32 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);
    view_type = list_view_history->view_type[list_view_history->current_index];
    list_view_history->is_delete_cancel = MMI_FALSE;
    list_view_history->is_add_cancel = MMI_FALSE;
    list_view_history->is_get_data_cancel = MMI_FALSE;
    list_view_history->is_cancel = MMI_FALSE;
    if(view_type == SRV_PLST_VIEW_MEDIA)
    {
        ret = srv_plst_pls_item_clear(srv_plst_base);
    }
    else
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    } 
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_stop_clear
 * DESCRIPTION
 *  cancel the clear current playlist's all items action
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_item_stop_clear(U32 srv_plst_hdr, U32 *count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    srv_plst_list_view_history_struct* list_view_history;    
    srv_plst_view_type_enum view_type;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view_history = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);
    view_type = list_view_history->view_type[list_view_history->current_index];
    if(view_type == SRV_PLST_VIEW_MEDIA)
    {
        ret = srv_plst_pls_item_stop_clear(srv_plst_base, count);
    }
    else
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    } 
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_udpate_active_info_after_change_index
 * DESCRIPTION
 *  update current picked file to PLS database playinfo table
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  param_struct       :         [OUT]  see srv_plst_list_item_info  param_a: media_id, param_b:  storage_id
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_store_active_info(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct* srv_plst_base;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ACTIVE_MEDIA_AUTO,srv_plst_hdr, 123, ret, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    ret = srv_plst_pls_store_active_info(srv_plst_base);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ACTIVE_MEDIA_AUTO,srv_plst_hdr, 123, ret, __LINE__);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_get_active_media_info_auto
 * DESCRIPTION
 *  get the previouse playing media info: id, storage_id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  param_struct       :         [OUT]  see srv_plst_list_item_info  param_a: media_id, param_b:  storage_id
 *  path               :         [OUT]  media's filepath
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_item_get_active_media_info_auto(U32 srv_plst_hdr, U32* id , U32* index, UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    srv_plst_playing_context_struct *playing_info;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ACTIVE_MEDIA_AUTO,srv_plst_hdr, path, 0, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->playing_info);
    if(id == NULL)
    {
        return SRV_PLST_RET_ERR_PARAM_ERR;
    }
    if(index)
    {
        playing_info->is_update_index = MMI_TRUE;
    }  
    else 
    {
        playing_info->is_update_index = MMI_FALSE;
    }

    if(playing_info->is_load && !playing_info->total)
    {
        return SRV_PLST_RET_EMPTY;
    }
    ret = srv_plst_pls_get_active_playing_media(srv_plst_base, playing_info,SRV_PLST_GET_ACTIVE_AUTO, id, path);
    if(index)
    {       
        *index = playing_info->pick_index;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ACTIVE_MEDIA_AUTO,ret, *id,*index, __LINE__);
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ACTIVE_MEDIA_AUTO,ret, *id, playing_info->pick_index, __LINE__);
    }   

    if(ret == SRV_PLST_OK && !index && srv_plst_base->shuffle == SRV_PLST_SHUFFLE_ON)
    {
        playing_info->is_playing_change = MMI_TRUE;
    }
    playing_info->is_update_index = MMI_FALSE;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_get_active_media_info_manul_prev
 * DESCRIPTION
 *  get the previouse playing media info: id, storage_id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  param_struct       :         [OUT]  see srv_plst_list_item_info  param_a: media_id, param_b:  storage_id
 *  path               :         [OUT]  media's filepath
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_item_get_active_media_info_manul_prev(U32 srv_plst_hdr, U32* id , U32* index, UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    srv_plst_playing_context_struct *playing_info;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ACTIVE_MEDIA_MANUL_PREV,srv_plst_hdr, path, 0, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->playing_info);
    if(id == NULL)
    {
        return SRV_PLST_RET_ERR_PARAM_ERR;
    }
    if(index)
    {
        playing_info->is_update_index = MMI_TRUE;
    }
    if(playing_info->is_load && !playing_info->total)
    {
        return SRV_PLST_RET_EMPTY;
    }
    ret = srv_plst_pls_get_active_playing_media(srv_plst_base, playing_info,SRV_PLST_GET_ACTIVE_PREV, id, path);
    if(index)
    {       
        *index = playing_info->pick_index;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ACTIVE_MEDIA_MANUL_PREV,ret, *id,*index, __LINE__);
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ACTIVE_MEDIA_MANUL_PREV,ret, *id, playing_info->pick_index, __LINE__);
    }   
    if(ret == SRV_PLST_OK && !index && srv_plst_base->shuffle == SRV_PLST_SHUFFLE_ON)
    {
        playing_info->is_playing_change = MMI_TRUE;
    }
    playing_info->is_update_index = MMI_FALSE;
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_get_active_media_info_manul_next
 * DESCRIPTION
 *  get the next playing media info: id, storage_id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  param_struct       :         [OUT]  see srv_plst_list_item_info  param_a: media_id, param_b:  storage_id
 *  path               :         [OUT]  media's filepath
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_item_get_active_media_info_manul_next(U32 srv_plst_hdr,U32* id, U32* index, UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    srv_plst_playing_context_struct *playing_info;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ACTIVE_MEDIA_MANUL_NEXT,srv_plst_hdr, path, 0, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->playing_info);

    if(id == NULL)
    {
        return SRV_PLST_RET_ERR_PARAM_ERR;
    }
    if(index)
    {
        playing_info->is_update_index = MMI_TRUE;
    }
    if(playing_info->is_load && !playing_info->total)
    {
        return SRV_PLST_RET_EMPTY;
    }
    ret = srv_plst_pls_get_active_playing_media(srv_plst_base, playing_info,SRV_PLST_GET_ACTIVE_NEXT, id, path);

    if(index)
    {
        *index = playing_info->pick_index;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ACTIVE_MEDIA_MANUL_NEXT,ret, *id,*index, __LINE__);
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ACTIVE_MEDIA_MANUL_NEXT,ret, *id, playing_info->pick_index, __LINE__);
    }

    if(ret == SRV_PLST_OK && !index && srv_plst_base->shuffle == SRV_PLST_SHUFFLE_ON)
    {
        playing_info->is_playing_change = MMI_TRUE;
    }
    playing_info->is_update_index = MMI_FALSE;
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_plst_item_get_active_media_info_curr
 * DESCRIPTION
 *  get current playing media info: id, storage_id
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  param_struct       :         [OUT]  see srv_plst_list_item_info  param_a: media_id, param_b:  storage_id
 *  path               :         [OUT]  media's filepath
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_plst_item_get_active_media_info_curr(U32 srv_plst_hdr, U32* id, U32* index,UI_string_type path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    srv_plst_playing_context_struct *playing_info;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ACTIVE_MEDIA_CURR,srv_plst_hdr, path, 0, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->playing_info);
    if(id == NULL)
    {
        return SRV_PLST_RET_ERR_PARAM_ERR;
    }
    if(index)
    {
        playing_info->is_update_index = MMI_TRUE;
    }
    if(playing_info->is_load && !playing_info->total)
    {
        return SRV_PLST_RET_EMPTY;
    }
    ret = srv_plst_pls_get_active_playing_media(srv_plst_base, playing_info,SRV_PLST_GET_ACTIVE_CURR, id, path);
    if(index)
    {
        *index = playing_info->pick_index;    
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ACTIVE_MEDIA_CURR,ret, *id,*index, __LINE__);
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_GET_ACTIVE_MEDIA_CURR,ret, *id, playing_info->pick_index, __LINE__);
    }
    playing_info->is_update_index = MMI_FALSE;
    return ret;
}


MMI_BOOL srv_plst_check_playlist_is_exist(U32 srv_plst_hdr, UI_string_type name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_CHECK_PLST_EXIST,srv_plst_hdr, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info); 
    ret = srv_plst_pls_check_plst_is_exist(srv_plst_base, name);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_CHECK_PLST_EXIST_RET,ret, __LINE__);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_plst_check_active_media_is_in_playlist
 * DESCRIPTION
 *  check if active media in default playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  type               :         [IN]  see srv_plst_default_playlist_enum  
 * RETURNS
 *  return error code  MMI_BOOL 
 *                     MMI_TRUE   in
 *                     MMI_FALSE  not in
 *****************************************************************************/ 
MMI_BOOL srv_plst_check_active_media_is_in_playlist(U32 srv_plst_hdr, srv_plst_default_playlist_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_CHECK_ACTIVE_IN_PLST,srv_plst_hdr, type, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info); 
    ret = srv_plst_pls_check_active_media_is_in_plst(srv_plst_base, type);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_CHECK_ACTIVE_IN_PLST_RET,ret, __LINE__);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_active_media_remove_from_playlist
 * DESCRIPTION
 *  remove active media from default playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  type               :         [IN]  see srv_plst_default_playlist_enum  
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_active_media_remove_from_playlist(U32 srv_plst_hdr, srv_plst_default_playlist_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_DEL_ACTIVE_FROM_PLST,srv_plst_hdr, type, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info); 
    ret = srv_plst_pls_active_media_remove_from_plst(srv_plst_base, type);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_DEL_ACTIVE_FROM_PLST_RET,ret, __LINE__);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_media_add_to_playlist
 * DESCRIPTION
 *  add active media to default playlist
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  type               :         [IN]  see srv_plst_default_playlist_enum  
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_active_media_add_to_playlist(U32 srv_plst_hdr, srv_plst_default_playlist_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ADD_ACTIVE_TO_PLST,srv_plst_hdr, type, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);
    ret = srv_plst_pls_active_media_add_to_plst(srv_plst_base, type);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_ADD_ACTIVE_TO_PLST_RET,ret, __LINE__);
    return ret;
}

#ifdef __PLST_SRV_FEATURE_GROUP_LIST__
S32 srv_plst_list_item_jumpto(U32 srv_plst_hdr, U32 jump_to_info, U32* index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    srv_plst_list_view_history_struct *list_view;
    S32 ret = SRV_PLST_OK;
    U32 id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_JUMPTO,srv_plst_hdr, (S8*)jump_to_info,__LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->list_view_history);
    id = list_view->list_cache[list_view->current_index].parent_id;
    memset(&(list_view->list_cache[list_view->current_index]),0 ,sizeof(srv_plst_list_context_struct));
    list_view->list_cache[list_view->current_index].parent_id = id;
    list_view->list_cache[list_view->current_index].total = list_view->total_count;
    ret = srv_plst_pls_list_item_jumpto(srv_plst_base, jump_to_info, index);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_JUMPTO_RET,ret, *index,__LINE__);
    return ret;
}
#endif /* __PLST_SRV_FEATURE_GROUP_LIST__ */
 
S32 srv_plst_list_get_context_by_id(U32 srv_plst_hdr, srv_plst_get_cntx_param_struct *in_param, srv_plst_get_context_struct *out_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_GET_CONTX,srv_plst_hdr, in_param->id, in_param->id_enum, in_param->get_type,__LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    ret = srv_plst_pls_get_cntx_by_id(srv_plst_base, in_param, out_param);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_GET_CONTX_RET,ret, __LINE__);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_plst_config_set_plst_order
 * DESCRIPTION
 *  confige the playlist show sequeues, it can be default list show at first or default list show at last
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  order              :         [IN]   see srv_plst_plst_show_sequeue_enum  
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_config_set_plst_order(U32 srv_plst_hdr, srv_plst_plst_show_sequeue_enum order)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_CONFIG_PLST_SEQUEUE,srv_plst_hdr, order, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    srv_plst_base->config_play_sequeue = order;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_CONFIG_PLST_SEQUEUE,srv_plst_hdr, 0, __LINE__);    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_config_shuffle
 * DESCRIPTION
 *  set shuffle info
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  shuffle            :         [IN]   see srv_plst_shuffle_enum  
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_config_shuffle(U32 srv_plst_hdr, srv_plst_shuffle_enum shuffle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    srv_plst_playing_context_struct *play_info;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_CONFIG_SHUFFLE,srv_plst_hdr, shuffle, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    play_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->playing_info);
    if(play_info->is_load && play_info->is_playing_change &&
        srv_plst_base->shuffle == SRV_PLST_SHUFFLE_ON && shuffle == SRV_PLST_SHUFFLE_OFF)
    {
        play_info->is_update_index = MMI_TRUE;
    }
    srv_plst_base->shuffle = shuffle;
    if(play_info->is_load)
    {
        ret = srv_plst_pls_play_config_reset(srv_plst_base);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_CONFIG_SHUFFLE,ret, play_info->is_load, __LINE__);
    return SRV_PLST_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_config_repeat
 * DESCRIPTION
 *  set repeat info
 * PARAMETERS
 *  srv_plst_hdr       :         [IN]   service handle
 *  shuffle            :         [IN]   see srv_plst_repeat_enums  
 * RETURNS
 *  return error code  S32
 *                     < 0 error code
 *                     >=0 see srv_plst_caller_handler_enum 
 *****************************************************************************/ 
S32 srv_plst_config_repeat(U32 srv_plst_hdr, srv_plst_repeat_enum repeat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    srv_plst_playing_context_struct *play_info;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_CONFIG_REPEAT,srv_plst_hdr, repeat, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    
    play_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->playing_info);
    srv_plst_base->repeat = repeat;
    if(play_info->is_load)
    {
        ret = srv_plst_pls_play_config_reset(srv_plst_base);
    }
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_CONFIG_REPEAT,ret, play_info->is_load, __LINE__);
    return SRV_PLST_OK;
}


S32 srv_plst_config_info(U32 srv_plst_hdr, srv_plst_config_type_enum config_type, U32 config_value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    S32 ret = SRV_PLST_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_CONFIG_INFO,srv_plst_hdr, config_type, config_value, __LINE__);
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);    

    if(config_type == SRV_PLST_CONFIG_LIST_VIEW_SORT_TYPE)
    {
        #if defined(__MMI_ZI__) || defined(__MMI_CSTAR__) || defined(__MMI_T9__) || defined(__MMI_ITAP__)
        srv_plst_base->config_sort_list_view = (srv_plst_list_sort_type_enum)config_value;
        #else
        srv_plst_base->config_sort_list_view = (srv_plst_list_sort_type_enum)SRV_PLST_LIST_SORT_BY_UNICODE;
        #endif
    }
    else if(config_type == SRV_PLST_CONFIG_PLST_VIEW_SORT_TYPE)
    {
        #if defined(__MMI_ZI__) || defined(__MMI_CSTAR__) || defined(__MMI_T9__) || defined(__MMI_ITAP__)
        srv_plst_base->config_plst_view = (srv_plst_list_sort_type_enum)config_value;
        #else
        if((srv_plst_list_sort_type_enum)config_value == SRV_PLST_LIST_SORT_BY_PINYIN)
        {
            srv_plst_base->config_plst_view = SRV_PLST_LIST_SORT_BY_UNICODE;
        }
        else
        {
            srv_plst_base->config_plst_view = (srv_plst_list_sort_type_enum)config_value;
        }
        #endif
    }
    else if(config_type == SRV_PLST_CONFIG_VIEW_SORT_CONTEXT)
    {
        srv_plst_base->config_view_sort_type = (srv_plst_view_sort_type)config_value;
    }
    else if(config_type == SRV_PLST_CONFIG_SEARCH_TYPE)
    {
        srv_plst_base->config_search = (srv_plst_search_type_enum)config_value;
    }
    else if(config_type == SRV_PLST_CONFIG_REORDER_TYPE)
    {
        srv_plst_base->config_reorder = (srv_plst_plst_reorder_enum)config_value;
    }
    else if(config_type == SRV_PLST_CONFIG_PLAY_INFO)
    {
        srv_plst_base->config_store_play_info = (srv_plst_playing_info_store_enum)config_value;
    }
    else if(config_type == SRV_PLST_CONFIG_RET_PLAY_CYCLE_INFO)
    {
        srv_plst_base->config_play_cycle_info = (srv_plst_play_cycle_info_enum)config_value;
    }
    else
    {
        ret = SRV_PLST_RET_ERR_PARAM_ERR;
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_LIST_CONFIG_INFO_RET, ret, __LINE__);
    return ret;
}


MMI_BOOL srv_plst_check_sort_type_support(U32 srv_plst_hdr, srv_plst_list_sort_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_CHECK_SUPPORT_SORT_TYPE,srv_plst_hdr, type, __LINE__);
#if (defined(__MMI_CSTAR__) || defined(__MMI_T9__)) && (defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_TR_CHINESE__))
    ret = MMI_TRUE;
#else
    if(type == SRV_PLST_LIST_SORT_BY_PINYIN)
    {
        ret = MMI_FALSE;
    }
#endif
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_MMI_CHECK_SUPPORT_SORT_TYPE_RET,ret, __LINE__);

    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_list_create
 * DESCRIPTION
 *  create list service, get memory from caller
 * PARAMETERS
 *  result                :  [OUT]     error code
 *  srv_list_create_struct:  [IN]      service create stucture
 *  callback              :  [IN]      see the callback define
 *  create_struct         :  [IN]      see srv_plst_create_struct
 * RETURNS
 *  return service handle
 *****************************************************************************/ 
U32 srv_plst_create(S32* result, 
                    void* user_data, 
                    S32 (*callback)(void* user_data, srv_plst_cb_evt_enum cb_event, S32 result, U32 ca_para_2), 
                    srv_plst_create_struct* create)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    srv_plst_db_context_struct *db_info;
    S32 ret;
    U32 srv_plst_hdr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_CREATE,g_srv_plst_control_ptr->number, g_srv_plst_control_ptr->card_state, __LINE__);

    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        g_srv_plst_control_ptr->card_state = SRV_PLST_DRIVE_PHONE_ONLY;
    }
    else
    {
        g_srv_plst_control_ptr->card_state = SRV_PLST_DRIVE_CARD_EXIST;
    }
    if (create->mem_size < SRV_PLST_MIN_MEM_SIZE)
    {
        *result = SRV_PLST_RET_ERR_MEMORY_NOT_ENOUGH;    
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_CREATE,g_srv_plst_control_ptr->number, g_srv_plst_control_ptr->card_state, __LINE__);
        return 0 ;
    }
    else 
    {
        *result = SRV_PLST_OK;

        g_srv_plst_main = kal_adm_alloc(create->mem_ptr, sizeof(srv_plst_main_context_struct)); 
        memset(g_srv_plst_main, 0, sizeof(srv_plst_main_context_struct));
        srv_plst_hdr = (U32)g_srv_plst_main;

        /* config gen db memory */
        g_srv_plst_main->gen = kal_adm_alloc(create->mem_ptr, sizeof(srv_plst_gen_lib_context_struct)); 

        /* config Base info */
        srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);
        db_info = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->db_info);
        srv_plst_base->create.mem_ptr = create->mem_ptr;
        srv_plst_base->create.mem_size = create->mem_size;
        srv_plst_base->create.db_mem_size = create->db_mem_size;
        srv_plst_base->create.max_item_support = create->max_item_support;
        srv_plst_base->user_data = user_data;
        srv_plst_base->callback = callback;
        srv_plst_base->srv_handle = srv_plst_hdr;
        srv_plst_base->config_play_sequeue = SRV_PLST_PLST_DEFAULT_SHOW_FIRST;
        srv_plst_base->config_sort_list_view = SRV_PLST_LIST_SORT_BY_UNICODE;
        srv_plst_base->config_plst_view = SRV_PLST_LIST_SORT_BY_UNICODE;
        srv_plst_base->config_reorder = SRV_PLST_PLST_REORDER_CONTINUE;
        srv_plst_base->config_search = SRV_PLST_SEARCH_BY_PREFIX_NEW_LIST;
        srv_plst_base->config_view_sort_type = SRV_PLST_VIEW_SORT_BY_FILENAME;
        srv_plst_base->config_store_play_info = SRV_PLST_PLAY_INFO_STORE;
        srv_plst_base->config_play_cycle_info = SRV_PLST_HAVE_PLAY_CYCLE_INFO;
        db_info->srv_hdr = srv_plst_hdr;
        ret = srv_plst_init_instance(srv_plst_base , db_info);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_CREATE,g_srv_plst_control_ptr->number, ret, __LINE__);

        if (ret == SRV_PLST_OK)
        {
            g_srv_plst_control_ptr->number += 1;
            g_srv_plst_control_ptr->service_reg[g_srv_plst_control_ptr->number] = srv_plst_hdr;
            return srv_plst_hdr;
        }
        else
        {
            return ret;
        }
    }    
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_destroy_for_realloc_memory
 * DESCRIPTION
 *  Close DB, get context memory and destroy db for later recreate
 * PARAMETERS
 *  srv_plst_hdr          :  [IN]      db handle
 *  memory_ptr            :  [IN]      memory buffer pointer
 *  memory_size           :  [IN]      memory buffer size
 * RETURNS
 *  get result
 *****************************************************************************/
S32 srv_plst_destroy_for_realloc_memory(U32 srv_plst_hdr, void* memory_ptr, U16 memory_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_main_context_struct *db_cntx;
    srv_plst_db_context_struct *db_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(memory_size < sizeof(srv_plst_main_context_struct))
    {
        return SRV_PLST_RET_ERR_MEMORY_NOT_ENOUGH;
    }

    // Close original database
    srv_plst_library_close(srv_plst_hdr);

    kal_mem_cpy(memory_ptr, (void*)srv_plst_hdr, sizeof(srv_plst_main_context_struct));

    // Close and destroy original database instance
    srv_plst_destroy(srv_plst_hdr);

    // Free gen db memory for shrink case
    db_cntx = (srv_plst_main_context_struct*)memory_ptr;
    db_cntx->gen = NULL;

    // Set flag to false
    db_info = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)memory_ptr)->db_info);
    db_info->instance_inited = MMI_FALSE; /* instance deinit in destroy function */

    return SRV_PLST_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_plst_realloc_memory
 * DESCRIPTION
 *  App close DB and free its instance, 
 *  then use this API to reopen it with new allocated memory without check integrality of DB
 * PARAMETERS
 *  result                :  [OUT]     error code
 *  srv_plst_hdr          :  [IN]      old db handle
 *  create_struct         :  [IN]      see srv_plst_create_struct
 *  original_db_context_hdr  :  [IN]      original memory context
 * RETURNS
 *  return new service handle
 *****************************************************************************/
U32 srv_plst_realloc_memory(S32* result, U32 srv_plst_hdr, srv_plst_create_struct* create, void* original_db_context_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    srv_plst_db_context_struct *db_info;
    srv_plst_main_context_struct *g_srv_plst_main_new;
    U32 srv_plst_hdr_new;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Allocate new memory and copy original db context to new memory */
    g_srv_plst_main_new = kal_adm_alloc(create->mem_ptr, sizeof(srv_plst_main_context_struct));

    if(original_db_context_ptr != NULL)
    {
        /* The original DB context is already freed, and copy to original_db_context_ptr outside */
        kal_mem_cpy(g_srv_plst_main_new, (void*)original_db_context_ptr, sizeof(srv_plst_main_context_struct));
    }
    else if(srv_plst_hdr && original_db_context_ptr == NULL)
    {
        /* The original DB is still remain, close it and copy to new memory */
        srv_plst_destroy_for_realloc_memory(srv_plst_hdr, (void*)g_srv_plst_main_new, sizeof(srv_plst_main_context_struct));
    }
    else
    {
        *result = SRV_PLST_RET_ERR_PARAM_ERR;
        return 0;
    }

    /* Reconfig memory */
    g_srv_plst_main = g_srv_plst_main_new;
    srv_plst_hdr_new = (U32)g_srv_plst_main;

    /* config gen db memory */
    if(create->gen_mem_size > 0)
    {
        g_srv_plst_main->gen = kal_adm_alloc(create->mem_ptr, sizeof(srv_plst_gen_lib_context_struct)); 
    }
    
    /* config Base info */
    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr_new)->base_info);
    db_info = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr_new)->db_info);
    srv_plst_base->create.mem_ptr = create->mem_ptr;
    srv_plst_base->create.mem_size = create->mem_size;
    srv_plst_base->create.db_mem_size = create->db_mem_size;
    srv_plst_base->create.max_item_support = create->max_item_support;
    srv_plst_base->srv_handle = srv_plst_hdr_new;
    db_info->srv_hdr = srv_plst_hdr_new;
    
    /* Init database */
    ret = srv_plst_init_instance(srv_plst_base , db_info);

    // TODO: remove after QC
    ASSERT(ret == SRV_PLST_OK);

    if(ret == SRV_PLST_OK)
    {
        g_srv_plst_control_ptr->number += 1;
        g_srv_plst_control_ptr->service_reg[g_srv_plst_control_ptr->number] = srv_plst_hdr_new;
    }
    else
    {
        if(g_srv_plst_main->gen != NULL)
        {
            kal_adm_free(create->mem_ptr, (void*)g_srv_plst_main->gen);
        }
        kal_adm_free(create->mem_ptr, (void*)g_srv_plst_main_new);
        *result = ret;
        return 0;
    }

    /* Open database */
    db_info->open_flag = SRV_PLST_OPEN_REOPEN;
    ret = srv_plst_pls_open_lib(srv_plst_base, SRV_PLST_OPEN_REOPEN);
    srv_plst_base->db_open_error = srv_plst_base->error_code;

    // TODO: Add Trace Here

    *result = ret;
    return srv_plst_hdr_new;
}

/*****************************************************************************
 * FUNCTION
 *  srv_plst_util_check_card_if_exist
 * DESCRIPTION
 *  check card exist or not
 * PARAMETERS
 
 * RETURNS
 *  return MMI_TRUE: exist  MMI_FALSE: not exist
 *****************************************************************************/ 
MMI_BOOL srv_plst_util_check_card_if_exist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(g_srv_plst_control_ptr->card_state == SRV_PLST_DRIVE_CARD_EXIST)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_list_destory
 * DESCRIPTION
 *  reset, destory list service
 * PARAMETERS
 *  srv_plst_hdr :         [IN]   service handle
 * RETURNS
 *  return error code  S32
 *****************************************************************************/ 
S32 srv_plst_destroy(U32 srv_plst_hdr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    srv_plst_db_context_struct *db_info;
    void* ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_DESTORY,srv_plst_hdr, 0, __LINE__);   

    srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->base_info);
    db_info = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)srv_plst_hdr)->db_info);

    srv_plst_deinit_instance(srv_plst_base, db_info);

    if (db_info->in_transaction || db_info->enable_flag)
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_DESTORY,db_info->in_transaction, db_info->enable_flag, __LINE__);   
        return SRV_PLST_RET_ERR_DESTROY_FAIL;
    }

    /* deinit and free memory */
    if(srv_plst_base)
    {
        ptr = srv_plst_base->create.mem_ptr;
        if(g_srv_plst_main->gen != NULL)
        {
            kal_adm_free(ptr, g_srv_plst_main->gen);
        }
        kal_adm_free(ptr, g_srv_plst_main);
    }
    if(g_srv_plst_control_ptr->number > 0)
    {
        g_srv_plst_control_ptr->service_reg[g_srv_plst_control_ptr->number] = 0;
        g_srv_plst_control_ptr->number -= 1;
    }
    return SRV_PLST_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_list_get_error_string
 * DESCRIPTION
 *  get list service error string id
 * PARAMETERS
 *  error code        :    [IN]   error code
 *  event_type        :    [OUT]  event type
 * RETURNS
 *  return error string id
 *****************************************************************************/ 
U32 srv_plst_get_error_string(S32 error_code, mmi_event_notify_enum *event_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 string_id = STR_GLOBAL_OK;
    srv_plst_base_info_struct *base;
    srv_plst_db_context_struct *db;
    S32 sub_err = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)g_srv_plst_main)->base_info);
    db = (srv_plst_db_context_struct*)&(((srv_plst_main_context_struct*)g_srv_plst_main)->db_info);

    if(error_code == SRV_PLST_RET_ERR_FS_ERROR)
    {
        sub_err = base->ture_err_code;
        string_id = srv_fmgr_fs_error_get_string(sub_err);
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_GET_ERR_STRING,error_code, sub_err);   

         *event_type = MMI_EVENT_FAILURE;
        return string_id;
    }
    else if(error_code == SRV_PLST_RET_DB_FULL)
    {
        string_id = STR_ID_SRV_PLST_DB_ITEM_FULL;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_GET_ERR_STRING,error_code, __LINE__);   
        *event_type = MMI_EVENT_SUCCESS;
        return string_id;
    }
    else if(error_code == SRV_PLST_RET_PLST_FULL)
    {
        string_id = STR_ID_SRV_PLST_PLST_ITEM_FULL;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_GET_ERR_STRING,error_code, __LINE__);   
        *event_type = MMI_EVENT_FAILURE;
        return string_id;
    }
    else if(error_code == SRV_PLST_RET_DB_AUDIO_FULL)
    {
        string_id = STR_ID_SRV_PLST_DB_AUDIO_FULL;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_GET_ERR_STRING,error_code, __LINE__);   
        *event_type = MMI_EVENT_SUCCESS;
        return string_id;
    }
    else if(error_code == SRV_PLST_RET_DB_VIDEO_FULL)
    {
        string_id = STR_ID_SRV_PLST_DB_VIDEO_FULL;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_GET_ERR_STRING,error_code, __LINE__);   
        *event_type = MMI_EVENT_SUCCESS;
        return string_id;
    }
    else if(error_code == SRV_PLST_RET_ERR_SQLITE_ERR)
    {
        sub_err = db->err_code;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_GET_ERR_STRING,error_code, sub_err);   
        switch(sub_err)
        {
            case SQLITE_READONLY:
                string_id = STR_ID_SRV_PLST_DB_READ_ONLY;
                break;

            case SQLITE_FULL:
                string_id = srv_fmgr_fs_error_get_string(FS_DISK_FULL);
                break;

            case SQLITE_CANTOPEN:
                string_id = STR_ID_SRV_PLST_DB_CANNOT_OPEN;
                break;

            case SQLITE_EMPTY:
                string_id = STR_ID_SRV_PLST_DB_EMPTY;
                break;

            case SQLITE_NOMEM:
                string_id = STR_ID_SRV_PLST_DB_NOMEM;
                break;

            case SQLITE_PERM:
                string_id = srv_fmgr_fs_error_get_string(FS_ACCESS_DENIED);
                break;
            case SQLITE_CORRUPT:
            case SQLITE_FORMAT:
                string_id = STR_ID_SRV_PLST_DB_CONRRPUT;
                break;
                
            case SQLITE_ERROR:
            case SQLITE_INTERNAL:
               string_id = STR_ID_SRV_PLST_SQLITE_ERR;
               break;
            case SQLITE_IOERR:
               {
                    S32 temp_err;
                    temp_err = pls_sql_util_get_fs_err(db);
                    string_id = srv_fmgr_fs_error_get_string(temp_err);
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_GET_ERR_STRING,temp_err, __LINE__);   
               }
               break;
            default:
                 string_id = STR_ID_SRV_PLST_SQLITE_ERR;
                 break;
            
        }
         *event_type = MMI_EVENT_FAILURE;
        return string_id;
    }
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_GET_ERR_STRING,error_code, sub_err); 
    switch(error_code)
    {
        case SRV_PLST_VERSION_WRONG:
            string_id = STR_ID_SRV_PLST_VERSION_WRONG;
            break;
            
        case SRV_PLST_RET_ERR_MEMORY_NOT_ENOUGH:
            string_id = STR_GLOBAL_NOT_ENOUGH_MEMORY; // STR_GLOBAL_INSUFFICIENT_MEMORY
            break;
        case SRV_PLST_RET_ERR_DISK_NOT_ENOUGH:
            string_id = srv_fmgr_fs_error_get_string(FS_DISK_FULL);
            break;
        case SRV_PLST_RET_ERR_SERVICE_MAX_SUPPORT:
            string_id = STR_ID_SRV_PLST_MAX_SERVICE_SUPPORT;
            break;
               
        case SRV_PLST_RET_ERR_MEMORY_CONRRUPT:
            string_id = STR_ID_SRV_PLST_MEMORY_CORRUPT;
            break;
            
        case SRV_PLST_RET_ERR_DB_CRASH:
        case SRV_PLST_RET_ERR_DB_CONRRUPT:
            string_id = STR_ID_SRV_PLST_DB_CONRRPUT;
            break;
            
        case SRV_PLST_RET_ERR_DESTROY_FAIL:
            string_id = STR_ID_SRV_PLST_DESTORY_FAIL;
            break;
            
        case SRV_PLST_RET_ERR_SQLITE_ERR:
            string_id = STR_ID_SRV_PLST_SQLITE_ERR;
            break;
            
        case SRV_PLST_RET_ERR_PARAM_ERR:
            string_id = STR_ID_SRV_PLST_PARAM_ERR;
            break;
            
        case SRV_PLST_RET_ERR_UNKOWN_ERR:
            string_id = STR_ID_SRV_PLST_UNKNOWN_ERR;
            break;
            
        case SRV_PLST_RET_ERR_FS_ERROR:
            string_id = STR_ID_SRV_PLST_FS_ERR;
            break;

        case SRV_PLST_RET_ERR_FATAL_ERROR:
            string_id = STR_ID_SRV_PLST_UNKNOWN_ERR;
            //string_id = STR_ID_SRV_PLST_FATAL_ERR;
            break;
            
        case SRV_PLST_RET_ITEM_EXIST:
            string_id = STR_ID_SRV_PLST_ITEM_EXIST;
            break;
            
        case SRV_PLST_RET_ERR_META_PAESER:
            string_id = STR_ID_SRV_PLST_META_PARSER_ERR;
            break;
            
        case SRV_PLST_RET_ERR_GDI_ERR:
            string_id = STR_ID_SRV_PLST_GDI_ERR;
            break;     
        case SRV_PLST_RET_ERR_DB_NOT_FOUND:
            string_id = STR_ID_SRV_PLST_DB_NOT_FOUND;
            break;     
        case SRV_PLST_RET_EMPTY:
            string_id = STR_GLOBAL_EMPTY;
            break;    

        default: 
            string_id = STR_GLOBAL_ERROR;
            break;
    }
    *event_type = MMI_EVENT_FAILURE;
    return string_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_msdc_plug_in_hdlr
 * DESCRIPTION
 *  plug in 
 * PARAMETERS
 *  drv_num     [IN]
 *  drv_list    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_plst_msdc_plug_in_hdlr(U8 drv_num, PU8 drv_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_list_context_struct *list_cache;
    U8 i = 0, j,k;
    U32 drv_letter;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_INTERRUPT_MSDC_PLUG_IN,drv_num, g_srv_plst_control_ptr->card_state, __LINE__);   

    for(i = 0; i < drv_num; i++)
    {
        drv_letter = (U32) drv_list[i];
        if(drv_list[i] == SRV_FMGR_CARD_DRV)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_INTERRUPT_MSDC_PLUG_IN, i, drv_list[i], __LINE__);   
            for (k = 1; k <= g_srv_plst_control_ptr->number && g_srv_plst_control_ptr->service_reg[k]; k++)
            {
                srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)g_srv_plst_control_ptr->service_reg[k])->base_info);
                list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)g_srv_plst_control_ptr->service_reg[k])->list_view_history);

                for(j = 0; j <= list_view->current_index; j++)
                {
                    list_cache = &(list_view->list_cache[j]);
                    list_cache->first_index = 0;
                    list_cache->last_index = 0;
                    list_cache->head = 0;
                    list_cache->tail = 0;
                    list_cache->total = 0;
                    list_cache->cache_num = 0;
                    memset(&(list_cache->cache[0]), 0 , sizeof(srv_plst_list_cache_struct)*SRV_PLST_VIEW_LIST_CACHE);
                }
                if(srv_plst_base->callback)
                {
                    (srv_plst_base->callback)(srv_plst_base->user_data, SRV_PLST_CB_EVT_MSDC_PLUG_IN, SRV_PLST_OK, drv_letter);
                }
            }
        }
        else
        {
            for (k = 1; k <= g_srv_plst_control_ptr->number && g_srv_plst_control_ptr->service_reg[k]; k++)
            {
                srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)g_srv_plst_control_ptr->service_reg[k])->base_info);
                if(srv_plst_base->callback)
                {
                    (srv_plst_base->callback)(srv_plst_base->user_data, SRV_PLST_CB_EVT_MSDC_PLUG_IN, SRV_PLST_OK, drv_letter);
                }
            }
        }
        
    }    
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_msdc_plug_out_hdlr
 * DESCRIPTION
 *  plug out hdlr 
 * PARAMETERS
 *  drv_num     [IN]
 *  drv_list    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_plst_msdc_plug_out_hdlr(U8 drv_num, PU8 drv_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    srv_plst_list_view_history_struct *list_view;
    srv_plst_list_context_struct *list_cache;
    srv_plst_playing_context_struct *playing_info;
    U8 i = 0,j,k;
    U32 drv_letter;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_INTERRUPT_MSDC_PLUG_OUT, drv_num, g_srv_plst_control_ptr->card_state, __LINE__);   
    for(i = 0; i < drv_num; i++)
    {
        drv_letter = (U32)drv_list[i];
        if(drv_list[i] == SRV_FMGR_CARD_DRV)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_INTERRUPT_MSDC_PLUG_OUT, i, drv_list[i], __LINE__);   
            for (k = 1; k <= g_srv_plst_control_ptr->number &&g_srv_plst_control_ptr->service_reg[k] ; k++)
            {
                U32 count = 0;

                srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)g_srv_plst_control_ptr->service_reg[k])->base_info);
                list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)g_srv_plst_control_ptr->service_reg[k])->list_view_history);
                playing_info = (srv_plst_playing_context_struct*)&(((srv_plst_main_context_struct*)g_srv_plst_control_ptr->service_reg[k])->playing_info);
                for(j = 0; j <= list_view->current_index; j++)
                {
                    list_cache = &(list_view->list_cache[i]);
                    list_cache->first_index = 0;
                    list_cache->last_index = 0;
                    list_cache->head = 0;
                    list_cache->tail = 0;
                    list_cache->total = 0;
                    list_cache->cache_num = 0;
                    memset(&(list_cache->cache[0]), 0 , sizeof(srv_plst_list_cache_struct)*SRV_PLST_VIEW_LIST_CACHE);
                }
                g_srv_plst_control_ptr->card_state = SRV_PLST_DRIVE_PHONE_ONLY;
                list_view->nb_blocking_artwork = MMI_FALSE;
                srv_plst_pls_get_show_data(srv_plst_base, list_view, SRV_PLST_GET_ACTIVE_LIST_COUNT,0, (U32*)&count);
                if(srv_plst_base->callback)
                {
                    if(!count && playing_info->active_type != SRV_PLST_ACTIVE_LIST_NONE)
                    {                    
                       (srv_plst_base->callback)(srv_plst_base->user_data, SRV_PLST_CB_EVT_ACTIVE_LIST_INVALID, SRV_PLST_OK, 0);
                    }
                }
                
                (srv_plst_base->callback)(srv_plst_base->user_data, SRV_PLST_CB_EVT_MSDC_PLUG_OUT, SRV_PLST_OK, drv_letter);
            }
        }
        else
        {
            for (k = 1; k <= g_srv_plst_control_ptr->number && g_srv_plst_control_ptr->service_reg[k]; k++)
            {
                srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)g_srv_plst_control_ptr->service_reg[k])->base_info);
                (srv_plst_base->callback)(srv_plst_base->user_data, SRV_PLST_CB_EVT_MSDC_PLUG_OUT, SRV_PLST_OK, drv_letter);
            }
        }
    }
}

//#ifdef __MMI_USB_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_plst_usb_plug_in_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET srv_plst_usb_plug_in_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    U8 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_INTERRUPT_USB_PLUG_IN);   
    for (i = 1; i <= g_srv_plst_control_ptr->number && g_srv_plst_control_ptr->service_reg[i]; i++)
    {
        srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)g_srv_plst_control_ptr->service_reg[i])->base_info);
        if(srv_plst_base->callback)
        {
            (srv_plst_base->callback)(srv_plst_base->user_data, SRV_PLST_CB_EVT_USB_PLUG_IN, SRV_PLST_OK, 0);
        }   
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_usb_plug_out_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET srv_plst_usb_plug_out_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    U8 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_INTERRUPT_USB_PLUG_OUT);   
    for (i = 1; i <= g_srv_plst_control_ptr->number && g_srv_plst_control_ptr->service_reg[i]; i++)
    {
        srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)g_srv_plst_control_ptr->service_reg[i])->base_info);
        if(srv_plst_base->callback)
        {
            (srv_plst_base->callback)(srv_plst_base->user_data, SRV_PLST_CB_EVT_USB_PLUG_OUT, SRV_PLST_OK, 0);
        }
    }
    return MMI_RET_OK;
}
//#endif

/*****************************************************************************
 * FUNCTION
 *  srv_plst_pre_format_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_plst_pre_format_hdlr(CHAR drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    U8 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_INTERRUPT_PREFORMAT, drv);   
    for (i = 1; i <= g_srv_plst_control_ptr->number &&g_srv_plst_control_ptr->service_reg[i]; i++)
    {
        srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)g_srv_plst_control_ptr->service_reg[i])->base_info);
        if(srv_plst_base->callback)
        {
            (srv_plst_base->callback)(srv_plst_base->user_data, SRV_PLST_CB_EVT_PRE_FORMAT, SRV_PLST_OK, 0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_aft_format_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  drv   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_plst_aft_format_hdlr(CHAR drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    U8 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_INTERRUPT_AFTFORMAT, drv);   
    for (i = 1; i <= g_srv_plst_control_ptr->number &&g_srv_plst_control_ptr->service_reg[i]; i++)
    {
        srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)g_srv_plst_control_ptr->service_reg[i])->base_info);
        if(srv_plst_base->callback)
        {
            (srv_plst_base->callback)(srv_plst_base->user_data, SRV_PLST_CB_EVT_AFT_FORMAT, SRV_PLST_OK, 0);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_plst_msdc_entry_unmount
 * DESCRIPTION
 *  update driver's status.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_plst_msdc_entry_unmount(CHAR drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    srv_plst_list_view_history_struct *list_view;
    U32 drv_letter;
    U8 i = 0;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_INTERRUPT_ENTRY_UNMOUNT);  
    drv_letter = (U32)drv;
    for (i = 1; i <= g_srv_plst_control_ptr->number && g_srv_plst_control_ptr->service_reg[i]; i++)
    {
        srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)g_srv_plst_control_ptr->service_reg[i])->base_info);
        list_view = (srv_plst_list_view_history_struct*)&(((srv_plst_main_context_struct*)g_srv_plst_control_ptr->service_reg[i])->list_view_history);
        if(drv == SRV_FMGR_CARD_DRV)
        {
            U32 count = 0;
            g_srv_plst_control_ptr->card_state = SRV_PLST_DRIVE_PHONE_ONLY;
            list_view->nb_blocking_artwork = MMI_FALSE;
            srv_plst_pls_get_show_data(srv_plst_base, list_view, SRV_PLST_GET_ACTIVE_LIST_COUNT,0, (U32*)&count);
            if(srv_plst_base->callback)
            {
                if(!count)
                {                    
                   (srv_plst_base->callback)(srv_plst_base->user_data, SRV_PLST_CB_EVT_ACTIVE_LIST_INVALID, SRV_PLST_OK, 0);
                }
            }
            (srv_plst_base->callback)(srv_plst_base->user_data, SRV_PLST_CB_EVT_MSDC_ENTRY_UNMOUNT, SRV_PLST_OK, drv_letter);
        }
        else 
        {
            (srv_plst_base->callback)(srv_plst_base->user_data, SRV_PLST_CB_EVT_MSDC_ENTRY_UNMOUNT, SRV_PLST_OK, (U32)drv_letter);
        }
    }  
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_msdc_entry_unmount
 * DESCRIPTION
 *  update driver's status.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_plst_msdc_exit_unmount(CHAR drv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    U8 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_INTERRUPT_EXIT_UNMOUNT);   
    for (i = 1; i <= g_srv_plst_control_ptr->number && g_srv_plst_control_ptr->service_reg[i]; i++)
    {
        srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)g_srv_plst_control_ptr->service_reg[i])->base_info);
        if(srv_plst_base->callback)
        {
            (srv_plst_base->callback)(srv_plst_base->user_data, SRV_PLST_CB_EVT_MSDC_EXIT_UNMOUNT, SRV_PLST_OK, (U32)drv);
        }
    }  
}



/*****************************************************************************
 * FUNCTION
 *  srv_plst_check_file_is_playing
 * DESCRIPTION
 *  check before delete remove and delete all.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_plst_check_file_is_delete(CHAR *path, MMI_BOOL is_folder, MMI_BOOL is_delete_all, const FMGR_FILTER *filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_delete_file_from_fmgr_struct del;
    srv_plst_base_info_struct *srv_plst_base;
    MMI_BOOL ret = MMI_TRUE;
    U8 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    del.path = path;
    del.is_folder = is_folder;
    del.is_delete_all = is_delete_all;
    if(filter != NULL)
    {
        memcpy(&(del.filter), filter, sizeof(FMGR_FILTER));
    }
    else
    {
        memset(&del.filter, 0, sizeof(FMGR_FILTER));
    }
    for (i = 1; i <= g_srv_plst_control_ptr->number && g_srv_plst_control_ptr->service_reg[i]; i++)
    {
        srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)g_srv_plst_control_ptr->service_reg[i])->base_info);
        if(srv_plst_base->callback)
        {
            ret = (MMI_BOOL)(srv_plst_base->callback)(srv_plst_base->user_data, SRV_PLST_CB_EVT_DELETE_FROM_FMGR, SRV_PLST_OK, (U32)&del);
            if(ret)
            {
                return ret;
            }
        }
    }  
    return ret;     
}


#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
/*****************************************************************************
 * FUNCTION
 *  srv_plst_notify_default_storage_change_pre_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_storage_letter   [IN]
 * RETURNS
 *  MMI_BOOL 
 *****************************************************************************/
MMI_BOOL srv_plst_notify_default_storage_change(CHAR new_storage_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_plst_base_info_struct *srv_plst_base;
    U8 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_INTERRUPT_DEFAULT_STORAGE_CHANGE_NITOFY);   
    for (i = 1; i <= g_srv_plst_control_ptr->number && g_srv_plst_control_ptr->service_reg[i]; i++)
    {
        srv_plst_base = (srv_plst_base_info_struct*)&(((srv_plst_main_context_struct*)g_srv_plst_control_ptr->service_reg[i])->base_info);
        if(srv_plst_base->callback)
        {
            (srv_plst_base->callback)(srv_plst_base->user_data, SRV_PLST_CB_EVT_NOTIFY_DEFAULT_STORAGE_CHANGE, SRV_PLST_OK, 0);
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_plst_notify_default_storage_change_pre_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_storage_letter   [IN]
 * RETURNS
 *  MMI_BOOL 
 *****************************************************************************/
MMI_BOOL srv_plst_notify_default_storage_change_pre_check(CHAR new_storage_letter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_PLS_INTERRUPT_DEFAULT_STORAGE_CHANGE);   
    return MMI_TRUE;
}
#endif

mmi_ret srv_plst_service_notify_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
    srv_fmgr_notification_set_def_storage_event_struct *fmgr_storage;
#endif /* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */
    srv_fmgr_notification_format_event_struct *fmgr_format;
    srv_fmgr_notification_dev_plug_event_struct *fmgr_plug;
    srv_fmgr_notification_dev_soft_mount_event_struct *fmgr_mount;
    srv_fmgr_notification_adv_action_event_struct *fmgr_act;

    /*----------------------------------------------------------------*/
    /* Code Body */
    /*----------------------------------------------------------------*/

    switch(event->evt_id)
    {
    #ifdef __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__
        case EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE:
        fmgr_storage = (srv_fmgr_notification_set_def_storage_event_struct*)event;

        if(fmgr_storage->state == SRV_FMGR_NOTIFICATION_STATE_QUERY) /* MMI_FMGR_NOTIFY_SET_STORAGE_PRE_CHK */
        {
        // return srv_plst_notify_default_storage_change_pre_check(*((CHAR*)para));
        }
        else if(fmgr_storage->state == SRV_FMGR_NOTIFICATION_STATE_AFTER) /* MMI_FMGR_NOTIFY_SET_STORAGE */
        {
        // srv_plst_notify_default_storage_change(*((CHAR*)para));
        }
        break;
    #endif /* __MMI_FMGR_SUPPORT_DEFAULT_STORAGE__ */

    case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT: 
        fmgr_format = (srv_fmgr_notification_format_event_struct*)event;

        if(fmgr_format->state == SRV_FMGR_NOTIFICATION_STATE_BEFORE) /* MMI_FMGR_NOTIFY_DRV_PRE_FORMAT */
        {
            srv_plst_pre_format_hdlr((CHAR)fmgr_format->drv_letter);
        }
        else if(fmgr_format->state == SRV_FMGR_NOTIFICATION_STATE_AFTER) /* MMI_FMGR_NOTIFY_DRV_PRE_FORMAT */
        {
            srv_plst_aft_format_hdlr((CHAR)fmgr_format->drv_letter);
        }
        break;

    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT: /* MMI_FMGR_NOTIFY_DRV_POST_UNMOUNT */
        fmgr_plug = (srv_fmgr_notification_dev_plug_event_struct*)event;
        srv_plst_msdc_plug_out_hdlr(fmgr_plug->count, fmgr_plug->drv_letters);
        break;

    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN: /*MMI_FMGR_NOTIFY_DRV_POST_MOUNT*/
        fmgr_plug = (srv_fmgr_notification_dev_plug_event_struct*)event;
        srv_plst_msdc_plug_in_hdlr(fmgr_plug->count, fmgr_plug->drv_letters);
        break;

    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT:
        fmgr_mount = (srv_fmgr_notification_dev_soft_mount_event_struct*)event;

        if(fmgr_mount->mount == MMI_FALSE) /*MMI_FMGR_NOTIFY_ENTRY_UNMOUNT*/
        {
        srv_plst_msdc_entry_unmount((CHAR)fmgr_mount->drv_letter);
        }
        else /*MMI_FMGR_NOTIFY_EXIT_UNMOUNT*/
        {
            srv_plst_msdc_exit_unmount((CHAR)fmgr_mount->drv_letter);
        }
        break;

    case EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION:
        fmgr_act = (srv_fmgr_notification_adv_action_event_struct*)event;

        if(fmgr_act->state == SRV_FMGR_NOTIFICATION_STATE_QUERY)
        {
            if ((fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_MOVE) || /*MMI_FMGR_NOTIFY_PRE_DELETE, MMI_FMGR_NOTIFY_PRE_MOVE */
            (fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE) ||
            (fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_RENAME))
            {
                if(!srv_plst_check_file_is_delete((CHAR*)fmgr_act->src_filepath, (MMI_BOOL)(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR), MMI_FALSE, fmgr_act->filter))
                {
                    return MMI_RET_ERR;
                }
            }
            else if(fmgr_act->action == SRV_FMGR_NOTIFICATION_ACTION_DELETE_ALL) /* MMI_FMGR_NOTIFY_PRE_DEL_ALL */
            {
                if(!srv_plst_check_file_is_delete((CHAR*)fmgr_act->src_filepath,
                    (MMI_BOOL)(fmgr_act->src_fileinfo.attribute & FS_ATTR_DIR),
                    MMI_TRUE,
                    fmgr_act->filter))
                {
                    return MMI_RET_ERR;
                }
            }
        }
        break;
    default:
        break;
    }

    return MMI_RET_OK;
}


#ifdef __MTK_TARGET__
extern kal_uint32 INT_GetCurrentTime(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_plst_init
 * DESCRIPTION
 *  init when phone start, and before other app called it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/ 
void srv_plst_init(void)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    memset(&g_srv_plst_control, 0, sizeof(srv_plst_control_struct));
#ifdef __MTK_TARGET__
    srand(INT_GetCurrentTime());
#else
    srand((unsigned)time(0));
#endif
}

#endif


