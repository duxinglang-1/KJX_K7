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

/*******************************************************************************
 * Filename:
 * ---------
 *  Vapp_rmgr_service.c
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Services file for Rights Manager
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *          HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/




#include "MMI_include.h"

#ifdef __MMI_RMGR__
//#include "Vapp_rmgr_service.h"
#include "Vapp_rmgr_cntx.h"
#include "Vapp_rmgr_service.h"


#include "custom_mmi_default_value.h"
#include "RightsMgrGprot.h"
#include "RightsMgrProt.h"


#include "drm_gprot.h"
//#include "drm_msg.h"
#include "drm_memory.h"
#include "drm_ui.h"
#include "drm_util.h"
#include "drm_trace.h"
#include "mmi_rp_vapp_rmgr_def.h"
#include "TimerEvents.h"



#include "Conversions.h"
//#include "FileManagerResDef.h"
//#include "FileManagerGProt.h"           /* GetFileSystemErrorString */
#include "IdleAppProt.h"                
#include "CommonScreens.h"  /* gIndexIconsImageList */

#include "stack_msgs.h" /* MSG_ID_MMI_NW_PWROFF_DETACH_REQ*/
#include "ProtocolEvents.h" /* PRT_EQ_USB_DETECT_IND */
#include "AlarmFrameworkProt.h" /* AlmDeInit */
#include "SettingResDef.h" /* STR_SETTING_NOTICE_SUCCESS_REBOOT_TEXT */
#include "USBDeviceGprot.h"             /* mmi_usb_is_in_mass_storage_mode */
#include "FileMgrGProt.h"
#include "drm_gprot.h"
#include "drm_msg.h"
#include "app_mine.h"
#include "app_str.h"
//#include "ProtocolEvents.h"
//#include "FileManagerDef.h"
//#include "FileManagerGprot.h"

//#include "wapadp.h"
//#include "SimDetectionGprot.h"

#include "NwUsabSrvGprot.h"
#include "ModeSwitchSrvGProt.h"


#include "MMIDataType.h"
#include "fs_type.h"
#include "FileMgrGProt.h"
#include "drm_errcode.h"
#include "GlobalResDef.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "Unicodexdcl.h"
#include "drm_def.h"
#include "fs_func.h"
#include "kal_trace.h"
#include "mmi_frm_scenario_gprot.h"
#include "AlertScreen.h"
#include "CustDataRes.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#include "CommonScreensResDef.h"
#include "fs_errcode.h"
#include "kal_public_api.h"
#include "FileMgrSrvGProt.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#include "gui_typedef.h"
#include "custom_mmi_default_value.h"
#include "wgui_categories_util.h"
#include "kal_internal_api.h"
#include "string.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "RightsMgrResDef.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "browser_api.h"
#include "mmi_frm_history_gprot.h"
#include "MMI_features.h"
#include "ProfilesSrvGprot.h"
#include "gui_data_types.h"
#include "wgui_categories_text_viewer.h"


#ifdef __MMI_UCM__
#include "UcmSrvGprot.h"
#endif /*__MMI_UCM__*/

#include "mdi_datatype.h"
#include "mdi_audio.h"      /* mdi_audio_stop_all */

#ifdef __MMI_OP01_DCD__
#include "DCDGprot.h"
#endif

#ifdef __DM_LAWMO_SUPPORT__
#include "Mmiapi_dm_struct.h"
#endif /*__DM_LAWMO_SUPPORT__*/

#define RMGR_UTIL_TRC DRM_UI_DEBUG

typedef struct
{
    MMI_BOOL is_on;
    U16 *tmp_path;
}rmgr_extract_src_struct;


typedef struct
{
    U16 *content_path;
}rmgr_ro_arrival_struct;


U8  *info;
rmgr_request_rights_struct rmgr_req_ri_entry;

rmgr_list_ro_cntx_struct rmgr_list_ro_cntx;


#ifdef __DM_LAWMO_SUPPORT__  
static MMI_BOOL rmgr_phone_lock_flag;
#endif /*__DM_LAWMO_SUPPORT__*/

mmi_rmgr_cntx_struct g_mmi_rmgr_cntx;


mmi_rmgr_cntx_struct *const mmi_rmgr_p = &g_mmi_rmgr_cntx;


static FuncPtr delete_hdlr = NULL;
static kal_char content_drv;

/*
 * Local
 */
/* *FORMATTER-DISABLE* */
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

extern void vtst_rmgr_list_entry_format(void);
extern void vtst_rmgr_list_entry_format_cb(U32 i);
extern void vapp_rmgr_request_rights_confr();
extern MMI_BOOL mmi_rmgr_populate_drm_info(U16 *path, U8 app_perm, U8 *data, S32 buf_size);
extern MMI_BOOL mmi_rmgr_populate_drm_info_aux(U16 *path, U8 app_perm, U8 *data, S32 buf_size, S32 ref);
extern vtst_request_rights_confirm_ext(U32);
//extern void vapp_rmgr_show_process_info(U8 i);
extern void vapp_rmgr_db_entry_check();
extern void vcp_global_popup_cancel(VfxS32 handle);
extern s32 mmi_rmgr_extend_rights_fmgr_mod(FS_HANDLE handle, U8 permission, U16 icon, kal_int64 *left_usage, kal_int32 *left_time);

//extern S8 *mmi_rmgr_ucs2cat_secure(S8 *strDestination, const S8 *strSource, S32 destSize)

static rmgr_extract_src_struct g_rmgr_extract_src;
static rmgr_ro_arrival_struct g_rmgr_arrival;
U8 rmgr_space_check_user = 1;
extern U8 rmgr_dbchk_nv; 
extern U8 rmgr_vfx_spc_tgl;

//extern rmgr_req_rights_struct rmgr_req_ri_entry;


// commenting the code for sweep in service file

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
MMI_ID_TYPE mmi_rmgr_get_err_string(S32 error)
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
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM_MASTER__ */ 
/* under construction !*/
#ifdef WAP_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef OBIGO_Q03C_MMS_V02
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif /* WAP_SUPPORT */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_USB_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif /* if 0 */

 MMI_BOOL mmi_rmgr_db_check_status(void)
 {
	 /*----------------------------------------------------------------*/
	 /* Local Variables 											   */
	 /*----------------------------------------------------------------*/
 
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
 
	 if (rmgr_dbchk_nv)
		 return MMI_TRUE;
	 else
		 return MMI_FALSE;
 
 }


 // Need to re do this portion.
U8 mmi_rmgr_space_check()
{
   
	if (mmi_rmgr_db_check_status() && rmgr_space_check_user)
	   {
#ifdef __DRM_MTK__
		   U32 size;
    #if defined(MAX_DRM_DB_SIZE) && defined(__FS_QM_SUPPORT__) && (MAX_DRM_DB_SIZE != 0)
		   if ((size = FS_QmGetFree((BYTE *)DRM_DEFAULT_APP_PATH)) < DRM_MIN_FS_SIZE)
		   {
			   RMGR_UTIL_TRC(
				   "[RMGR] mmi_rmgr_space_check",
				   (TRACE_GROUP_UI, RMGR_UTIL_SPACE_CHECK, size, DRM_MIN_FS_SIZE));
			   return 1;
		   }
		   RMGR_UTIL_TRC("[RMGR] mmi_rmgr_space_check", (TRACE_GROUP_UI, RMGR_UTIL_SPACE_CHECK, size, DRM_MIN_FS_SIZE));
    #else /* defined(MAX_DRM_DB_SIZE) && defined(__FS_QM_SUPPORT__) && (MAX_DRM_DB_SIZE != 0) */ 
		   if ((size = FS_GetFolderSize(DRM_PATH, FS_COUNT_IN_CLUSTER, NULL, 0)) >= 256)
		   {
			   RMGR_UTIL_TRC("[RMGR] mmi_rmgr_space_check", (TRACE_GROUP_UI, RMGR_UTIL_SPACE_CHECK, size, 256));
			   return 1;
		   }
		   RMGR_UTIL_TRC("[RMGR] mmi_rmgr_space_check", (TRACE_GROUP_UI, RMGR_UTIL_SPACE_CHECK, size, 256));
    #endif /* defined(MAX_DRM_DB_SIZE) && defined(__FS_QM_SUPPORT__) && (MAX_DRM_DB_SIZE != 0) */ 
   
    #else /* __DRM_MTK__ */ 
		   S32 dbsize, dbmax;
		   dbsize = DRM_get_ro_dbsize(&dbmax);
   
		   RMGR_UTIL_TRC("[RMGR] mmi_rmgr_space_check", (TRACE_GROUP_UI, RMGR_UTIL_SPACE_CHECK, dbsize, dbmax));
   
		   if (dbsize > 0 && (dbmax - dbsize < DRM_MIN_FS_SIZE))
		   {
			   return 1;
		   }
    #endif
	   }
   
	   return 0;

 
};



U16 mmi_rmgr_get_root_icon(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // return GetRootTitleIcon(MENU_ID_RMGR);
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
#ifdef __DRM_V02__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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





void mmi_rmgr_space_check_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_space_check_cancel", (TRACE_GROUP_UI, RMGR_UTIL_SPACE_CHECK_CANCEL));

    rmgr_space_check_user = 0;

   // mmi_frm_scrn_close_active_id();
}




void mmi_rmgr_entry_db_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*mmi_display_popup_confirm_SG*/
    vapp_rmgr_db_entry_check();

    }

mmi_ret mmi_rmgr_db_check_conf_callback(mmi_event_struct *evt)
{
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
#endif 
}




S8 *mmi_rmgr_ucs2cat_secure(S8 *strDestination, const S8 *strSource, S32 destSize)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    n = mmi_ucs2strlen(strDestination);

    destSize = destSize / 2;

    if (destSize - n - 1 <= 0)
    {
        return NULL;
    }

    return mmi_ucs2ncat(strDestination, strSource, destSize - n - 1 );
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
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_list_ro_entry_detail
 * DESCRIPTION
 *  Entry function of the list ro detail screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_rmgr_list_ro_entry_detail(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //EntryNewScreen(SCR_ID_RMGR_LIST_RO_DETAIL, NULL, mmi_rmgr_list_ro_entry_detail, NULL);

    kal_wchar* p=NULL;
	p=get_detail_item_name();
    info = (PU8) subMenuData;

    memset(info, 0x00, sizeof(kal_wchar));
    mmi_ucs2cat((PS8) info, (PS8) (GetString(STR_ID_RMGR_NAME)));
	mmi_ucs2cat((PS8) info, (PS8) L"\n");
	mmi_ucs2cat((PS8) info, (PS8) (p));
	mmi_ucs2cat((PS8) info, (PS8) L"\n");
	mmi_ucs2cat((PS8) info, (PS8) L"\n");
#ifdef __DRM_V02__    
    /* Shared */
    mmi_ucs2cat((PS8) info, (PS8) GetString(STR_ID_RMGR_SHARED_RO));
    mmi_ucs2cat((PS8) info, (PS8) L"\n");

    if (DRM_get_ro_shareability(mmi_rmgr_p->ro_idx))
    {
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_GLOBAL_YES));
    }
    else
    {
        mmi_ucs2cat((PS8) info, (PS8) GetString(STR_GLOBAL_NO));
    }
    mmi_ucs2cat((PS8) info, (PS8) L"\n");
#endif /* __DRM_V02__ */

    /* Summary */
	i=get_rmgr_list_index();
    mmi_rmgr_populate_drm_info_aux(NULL, DRM_PERMISSION_ALL, info, sizeof(subMenuData), i) ;
    set_rmgr_detail_buffer(info);    
}



S32 mmi_rmgr_check_forward(U16 *file_path)
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





/*************** 22/11/10 ************************/


 static void vapp_rmgr_list_ro_del_callback(kal_uint8 serial, kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if 0
/* under construction !*/
#ifdef __DM_LAWMO_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__DM_LAWMO_SUPPORT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*0*/

vtst_rmgr_list_entry_format_cb(result);

    
}






void vapp_rmgr_list_ro_delete_all_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!DRM_consume_table_is_in_use())
    {
        kal_uint8 serial;

        /* reset the ro_num to zero, in callback function
           we will delete the list screen and go back to main menu */

        rmgr_list_ro_cntx.ro_num = 0;

        if (content_drv)
        {
            kal_wchar path[4];

            kal_wsprintf(path, "%c:\\", content_drv);
            DRM_process_database(
                DRM_PROCESS_DATABASE_DELETE_ALL,
                0,
                path,
                (kal_uint8*) & serial,
                vapp_rmgr_list_ro_del_callback);
        }
        else
        {
            DRM_process_database(
                DRM_PROCESS_DATABASE_DELETE_ALL,
                0,
                NULL,
                (kal_uint8*) & serial,
                vapp_rmgr_list_ro_del_callback);
        }
	#ifdef __DM_LAWMO_SUPPORT__   
		if (rmgr_phone_lock_flag)
		{
			/* Do not show progressing screen*/
		}
		else
	#endif /*__DM_LAWMO_SUPPORT__*/
		{
           // mmi_rmgr_entry_db_progressing(STR_GLOBAL_DELETING, serial, MMI_TRUE, MMI_FALSE);
        }
    }
    else
    {
       // mmi_popup_display((WCHAR*)GetString(STR_ID_DRM_DB_LOCKED_BY_APP), MMI_EVENT_FAILURE, NULL);
    }
    content_drv = 0;
}





void mmi_rmgr_list_ro_entry_delete(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U16 *delete_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (delete_hdlr == vtst_rmgr_list_entry_format)
    {
        //delete_str = (U16 *)GetString(STR_ID_RMGR_DELETE_ALL_QUERY);
    vtst_rmgr_list_entry_format();
    }
    //else
    //{
     //   delete_str = (U16 *)GetString(STR_ID_RMGR_DELETE_QUERY);
    //}
    
   /* {
	mmi_confirm_property_struct arg;
	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	arg.parent_id = GRP_ID_RMGR_MAIN;
	arg.callback = (mmi_proc_func)mmi_rmgr_list_ro_delete_conf_callback;
	arg.f_auto_map_empty_softkey = MMI_FALSE;
      arg.user_tag = NULL;
	mmi_confirm_display((WCHAR *)delete_str, MMI_EVENT_QUERY, &arg);
    }
*/




	}


static MMI_BOOL mmi_rmgr_format_popup_handler(mmi_scenario_id scen_id, void *arg)
{

	mmi_rmgr_list_ro_entry_delete();
	return MMI_TRUE;
}	


void mmi_rmgr_format_notify_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL block_screen = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_UCM__
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        block_screen = MMI_TRUE;

    #ifdef __MMI_BACKGROUND_CALL__
        if (srv_ucm_is_background_call())
        {
            block_screen = MMI_FALSE;
        }
    #endif /* __MMI_BACKGROUND_CALL__ */ 
    }

    if (block_screen)
    {
        return;
    }
#endif /* __MMI_UCM__ */ 
       mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_WARNING, mmi_rmgr_format_popup_handler, NULL);
   // mmi_rmgr_list_ro_entry_delete();
}






/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_format_notify_hdlr
 * DESCRIPTION
 *  Post formatting notification handler
 * PARAMETERS
 *  notify_flag        [IN]        MMI_FMGR_NOTIFY_DRV_POST_FORMAT
 *  para               [IN]        additional parameter
 * RETURNS
 *  MMI_BOOL: always return true
 *****************************************************************************/
mmi_ret mmi_rmgr_format_notify_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U8 drv_enum;
    srv_fmgr_notification_format_event_struct *format_evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    switch(param->evt_id)
	{
		case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
			format_evt = (srv_fmgr_notification_format_event_struct*)param;
            if(format_evt->result < 0)
			{
				return MMI_RET_OK;
			}
			if(format_evt->state == SRV_FMGR_NOTIFICATION_STATE_AFTER)
			{
				//mmi_fmgr_get_drive_enum_by_letter(format_evt->drv_letter, &drv_enum);
#ifdef __DM_LAWMO_SUPPORT__
        rmgr_phone_lock_flag = MMI_FALSE;   
	if (mmi_dmui_get_status(MMI_DMUI_MO_TYPE_LAWMO_LOCK) == MMI_DMUI_STATUS_LAWMO_LOCK_PARTIALLYLOCK)
	{
		rmgr_phone_lock_flag = MMI_TRUE;
		vapp_rmgr_list_ro_delete_all_entry();
	}
	else
#endif /*__DM_LAWMO_SUPPORT__*/
    {
        delete_hdlr = vtst_rmgr_list_entry_format;
        					content_drv = format_evt->drv_letter;// ((kal_char *)para)[0];

        StartTimer(RMGR_SCAN_DISK_TIMER, 1500, mmi_rmgr_format_notify_timeout_hdlr);
					}
			}
			break;
		default:
			break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 vapp_rmgr_send_rights_request
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_rmgr_send_rights_request(void)
{
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
#ifdef __DRM_V02__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __DRM_V02__ */
/* under construction !*/
/* under construction !*/
#ifdef BROWSER_SUPPORT
#if defined(__MMI_RMGR_SEAMLESS_UNLOCK__) && defined(__MMI_BROWSER_2__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
    #endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif                                                          /* my added if 0 */
}




void mmi_rmgr_entry_request_rights_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    vapp_rmgr_request_rights_confr();


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




/************************ 29/11 *****************************************/







/*****************************************************************************
* FUNCTION
 *  mmi_rmgr_get_ro_bound_path
* DESCRIPTION
 *  To get content path
* PARAMETERS
*   void
* RETURNS
*   the content path
*****************************************************************************/
U16 *mmi_rmgr_get_ro_bound_path(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_rmgr_arrival.content_path;
}


/*****************************************************************************
* FUNCTION
*   mmi_rmgr_set_ro_bound_path
* DESCRIPTION
 *  To set content path
* PARAMETERS
*   path        [IN]    the content path
* RETURNS
*   Void
*****************************************************************************/
void mmi_rmgr_set_ro_bound_path(U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rmgr_arrival.content_path)
        drmt_mem_free(g_rmgr_arrival.content_path);

    g_rmgr_arrival.content_path = (U16*)drmt_mem_alloc((kal_wstrlen((kal_wchar*)path) + 1) * ENCODING_LENGTH);

    kal_wstrcpy((kal_wchar*)g_rmgr_arrival.content_path, (kal_wchar*)path);

}


/*****************************************************************************
* FUNCTION
*   mmi_rmgr_reset_ro_bound_path
* DESCRIPTION
 *  To reset content path
* PARAMETERS
*   Void
* RETURNS
*   Void
*****************************************************************************/
U8 mmi_rmgr_reset_ro_bound_path(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_rmgr_arrival.content_path)
        drmt_mem_free(g_rmgr_arrival.content_path);

    g_rmgr_arrival.content_path = NULL;
    return 0;

}








/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_request_rights_confirm
 * DESCRIPTION
 *  The confirm to request rights
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_request_rights_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mmi_rmgr_request_rights_confirm_ext(NULL, MMI_TRUE);
}

void mmi_rmgr_clear_unlock_screen(void)
{

// TO-DO


}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_more_rits_entry_main
 * DESCRIPTION
 *  The confirm to request rights
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_more_rits_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_fmgr_fileinfo_struct file_info;
    filetypes_group_type_enum   group;
    U16 *file_path;
    U8 perm = DRM_PERMISSION_ALL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_rmgr_get_ro_bound_path())
    {
        file_path = mmi_rmgr_get_ro_bound_path();
    }
    else
    {
        file_path = (U16*) srv_fmgr_types_query_fileinfo(&file_info);
        group = srv_fmgr_types_find_group_by_type((filetypes_file_type_enum)(file_info.type));

        if (file_path == NULL)
            return;

        if (group == FMGR_GROUP_VIDEO || group == FMGR_GROUP_AUDIO)
        {
            perm = DRM_PERMISSION_PLAY;
        }
        else if (group == FMGR_GROUP_IMAGE)
        {
            perm = DRM_PERMISSION_DISPLAY;
        }
    #ifdef __J2ME__
        else if (file_info.type == FMGR_TYPE_JAD || file_info.type == FMGR_TYPE_JAR)
        {
            perm = DRM_PERMISSION_EXECUTE;
        }
    #endif /* __J2ME__ */
    }

    #ifdef __DRM_V02__
        mmi_rmgr_clear_unlock_screen();

        /* DRM 2.0 uses "activate file" */
        /* register file_path only */
        mmi_rmgr_register_unlock_session(0, file_path, perm, MMI_TRUE, NULL, 0, 0, NULL);
#else /* __DRM_V02__ */ 
        {
            S32 size = DRM_MAX_LINE_LENGTH;
            U8* url = (U8 *)drmt_mem_alloc(size);

            FS_HANDLE handle;
    
            handle = DRM_open_file((kal_wchar*)file_path, FS_READ_ONLY, DRM_PERMISSION_NONE);
            if (handle < DRM_RESULT_OK)
            {
                size = 0;
                drmt_mem_free(url);
                url = NULL;
                mmi_popup_display((WCHAR*)(get_string(srv_fmgr_fs_error_get_string(handle))), MMI_EVENT_FAILURE, NULL);
                return;
            }
            else
            {
                if(DRM_RESULT_OK > DRM_get_rights_issuer(handle, (kal_char*)url, (kal_uint32 *)&size))
                {
                    size = 0;
                    drmt_mem_free(url);
                    url = NULL;
                    mmi_popup_display((WCHAR*)(get_string(STR_GLOBAL_INVALID_URL)), MMI_EVENT_FAILURE, NULL);
                    return;
                }
    
                DRM_close_file(handle);
            }

            mmi_rmgr_clear_unlock_screen();
            mmi_rmgr_register_unlock_session(0, file_path, perm, MMI_TRUE, url, size, 0, NULL);
        }
#endif /* __DRM_V02__ */ 

    mmi_rmgr_request_rights_confirm();
}

/* API shared with the file manager and Java */
void mmi_rmgr_request_rights_confirm_ext(U16 *confirm_string, MMI_BOOL show_immediately)
{

	RMGR_UTIL_TRC("[RMGR] mmi_rmgr_request_rights_confirm",
				(TRACE_GROUP_UI, RMGR_UTIL_REQUEST_RIGHTS_CONFIRM));

	if (rmgr_req_ri_entry.file_path == NULL && rmgr_req_ri_entry.file_handle == 0)
    {
        ASSERT(0);
    }

    rmgr_req_ri_entry.confirm_string = confirm_string;

	mmi_rmgr_entry_request_rights_confirm();

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
#ifdef BROWSER_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif /*my added if 0 */

}





/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_send_rights_request
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_send_rights_request(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_send_rights_request",
            (TRACE_GROUP_UI, RMGR_UTIL_SEND_RIGHTS_REQUEST));

#ifdef __DRM_V02__
    if (rmgr_req_ri_entry.file_path)
    {
        mmi_rmgr_entry_activate();
        DRM_activate_file((kal_wchar*)rmgr_req_ri_entry.file_path, rmgr_req_ri_entry.permission, NULL, mmi_rmgr_activate_callback);
    }
    else if (rmgr_req_ri_entry.file_handle)
    {
        mmi_rmgr_entry_activate();
        DRM_activate_file_by_handle(rmgr_req_ri_entry.file_handle, NULL, mmi_rmgr_activate_callback);
    }
    else
#endif /* __DRM_V02__ */
    if (rmgr_req_ri_entry.url)
    {
#ifdef BROWSER_SUPPORT
#if defined(__MMI_RMGR_SEAMLESS_UNLOCK__) && defined(__MMI_BROWSER_2__)
        rmgr_req_ri_entry.is_activating = MMI_TRUE;
        mmi_rmgr_entry_activate();

        if (rmgr_req_ri_entry.file_path)
        {
            /* In some slow network, we cannot get the file immediately, therefore,
               we set the timeout time longer */
            rmgr_req_ri_entry.sd_callback_id = DRM_register_sd_callback(rmgr_req_ri_entry.file_path, DRM_DEFAULT_WAIT * 2, rmgr_req_ri_entry.file_path, mmi_rmgr_unlock_session_sd_cb);
        }
        else if(rmgr_req_ri_entry.file_handle)
        {
            rmgr_req_ri_entry.sd_callback_id = DRM_register_sd_callback_by_handle(rmgr_req_ri_entry.file_handle, DRM_DEFAULT_WAIT * 2, NULL, mmi_rmgr_unlock_session_sd_cb);
        }
        else
        {
            ASSERT(0);
        }

        wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8 *)rmgr_req_ri_entry.url);

        if (rmgr_req_ri_entry.result_callback)
        {
            rmgr_req_ri_entry.result_callback(MMI_TRUE);
        }
        /* we do not clean the unlock session if support seamless unlock  */
#else

        wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8 *)rmgr_req_ri_entry.url);

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
    #endif 

        if (rmgr_req_ri_entry.result_callback)
        {
            rmgr_req_ri_entry.result_callback(MMI_TRUE);
        }
        mmi_rmgr_wipe_unlock_session();

#endif
#endif
    }
    else
    {
        ASSERT(0);
    }

  //  mmi_frm_scrn_close(GRP_ID_RMGR_ACTIVATE, SCR_ID_RMGR_ACTIVATE_CONFIRM);
     //ClearDelScrnIDCallbackHandler(SCR_ID_RMGR_ACTIVATE_CONFIRM, NULL);
    //DeleteScreenIfPresent(SCR_ID_RMGR_ACTIVATE_CONFIRM);

}



/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_highlight_more_rits
 * DESCRIPTION
 *  Highlight handler of getting more rights 
 * PARAMETERS
 *  menu_idx        [IN]        Menu item index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_highlight_more_rits(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SetKeyHandler(mmi_rmgr_more_rits_entry_main, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
    SetLeftSoftkeyFunction(mmi_rmgr_more_rits_entry_main, KEY_EVENT_UP);
#ifdef __MMI_TOUCH_SCREEN__
    //wgui_register_list_item_selected_callback(mmi_rmgr_more_rits_entry_main);
#endif

}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_option_enabler_more_rits
 * DESCRIPTION
 *  Eandler of getting more rights 
 * PARAMETERS
 *  menu_idx        [IN]        Menu item index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_option_enabler_more_rits(mmi_menu_id menu_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(!DRM_rights_extendable((U16*)filepath) ||
       !srv_nw_usab_is_any_network_available() ||
       srv_mode_switch_is_network_service_available())
    {
        mmi_frm_hide_menu_item(menu_id);
    }
}





MMI_BOOL mmi_rmgr_populate_drm_info(U16 *path, U8 app_perm, U8 *data, S32 buf_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MTK_INTERNAL__ */   
   return mmi_rmgr_populate_drm_info_aux(path, app_perm, data, buf_size, -1);
}









void mmi_rmgr_populate_drm_constraint(
        drm_constraint_struct *constraint,
        U8 permission,
        U8 *data,
        S32 buf_size,
        MMI_BOOL simple_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 tmp[64]; /* For 10^10 <count> constraint */
    applib_time_struct t;
    S32 start = 0, end = 0;
	U8 *buff = data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (constraint->status != DRM_STATUS_RIGHTS_PRESENT &&
        constraint->status != DRM_STATUS_UNTRUSTED_TIME &&
        constraint->status != DRM_STATUS_RIGHTS_IN_FUTURE)
    {
        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_SUMMARY), buf_size);
        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_GLOBAL_INVALID), buf_size);
        //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        return;
    }

    if (constraint->type & DRM_CONSTRAINT_DATETIME)
    {
        /* two constraint
            |-------------------|
                      |----------------|
            A         B         C      D
            We should show B ~ C  */

        if ((constraint->type & DRM_CONSTRAINT_INTERVAL) && constraint->start_intv != 0)
        {
            if (constraint->start_time <= constraint->start_intv)
            {
                start = constraint->start_intv;
            }
            else
            {
                start = constraint->start_time;
            }

            /* there is a limitation time in end_time, or we just use the end_intv */
            if (constraint->end_time <= constraint->end_intv && constraint->end_time!=0)
            {
                end = constraint->end_time;
            }
            else
            {
                end = constraint->end_intv;
            }
        }
        else
        {
            start = constraint->start_time;
            end = constraint->end_time;
        }
    }
    else if (constraint->type & DRM_CONSTRAINT_INTERVAL)
    {
        if (constraint->interval <= 0)
        {
            start = 0;
            end = 0;
        }
        else
        {
            start = constraint->start_intv;
            end = constraint->end_intv;
        }
    }

#ifdef __MMI_RMGR_SIMPLE_DETAILS__
    if (simple_format)
    {
    	#if __DRM_V02__
        if (constraint->status == DRM_STATUS_UNTRUSTED_TIME)
        {
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8)GetString(STR_ID_DRM_TIME_UNTRUSTED), buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        }
        /* unlimited constraint or unlimited time anymore */
        else 
      #endif  
        if (constraint->type == DRM_CONSTRAINT_NONE ||
            (end == 0 && (constraint->type == DRM_CONSTRAINT_DATETIME)))
        {
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_LEFT_COUNT), buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNLIMITED), buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_LEFT_TIME), buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNLIMITED), buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        }
        else
        {
            if (constraint->type & DRM_CONSTRAINT_COUNT)
            {
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_LEFT_COUNT), buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);

                if (constraint->used_count > 0xFFFFFFFF)
                {
                    kal_wsprintf(
                        (WCHAR*) tmp,
                        "%u%09u\n",
                        (kal_uint32) (constraint->used_count / 1000000000),
                        (kal_uint32) (constraint->used_count % 1000000000));
                }
                else
                {
                     kal_wsprintf((WCHAR*)tmp, "%u\n", (kal_uint32)constraint->used_count);
                }

                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) tmp, buf_size);
            }

          if (constraint->type & (DRM_CONSTRAINT_INTERVAL | DRM_CONSTRAINT_ACCUMULATED | DRM_CONSTRAINT_DATETIME))
          {
            S32 left = 0;
			if(DRM_get_secure_time((applib_time_struct *)&t))
			{
            if (end > 0)
            {
                left = end - applib_dt_mytime_2_utc_sec(&t, KAL_FALSE);
            }

            if (constraint->type & DRM_CONSTRAINT_INTERVAL)
            {
                /* not start to use */
                if (constraint->start_intv == 0 && constraint->end_intv == 0)
                {
                    if (left <= 0 || left > constraint->interval)
                    {
                        left = constraint->interval;
                    }
                }
            }

            #ifdef __DRM_V02__
            if (constraint->type & DRM_CONSTRAINT_ACCUMULATED)
            {
                if (left <= 0 || left > constraint->accum_dur)
                {
                    left = constraint->accum_dur;
                }
            }
            #endif

            if (left > 0)
            {
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8)GetString(STR_ID_RMGR_DETAIL_LEFT_TIME), buf_size);

                if (left > DT_SEC_PER_DAY)
                {
                    /* >= 24 hours */
                    kal_wsprintf((WCHAR*)tmp, " %d ", left/DT_SEC_PER_DAY);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) tmp, buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_LEFT_DAYS), buf_size);
                }
                else if (left > DT_SEC_PER_HOUR)
                {
                    /* < 24 hours, >= 1 hours */
                    kal_wsprintf((WCHAR*)tmp, " %d ", left/DT_SEC_PER_HOUR);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) tmp, buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_LEFT_HOURS), buf_size);
                }
                else
                {
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);
                    /* < 1 hours */
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_LEFT_LAST), buf_size);
                }
                //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
            }
			else
			{
				memset(buff, 0, buf_size);
				mmi_rmgr_ucs2cat_secure((PS8) buff, (PS8) GetString(STR_ID_RMGR_REQ_RITS_EXPIRE_DETAIL), buf_size);
                //mmi_rmgr_ucs2cat_secure((PS8) buff, (PS8) L"\n", buf_size);
			}
          }
        }
    }
    }
    else
#endif /* __MMI_RMGR_SIMPLE_DETAILS__ */
    {
		 mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        switch(permission)
        {
            case DRM_PERMISSION_PLAY:
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_VAPP_DRM_PLAY), buf_size);
                //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                break;
            case DRM_PERMISSION_DISPLAY:
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_VAPP_DRM_DISPLAY), buf_size);
                //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                break;
            case DRM_PERMISSION_EXECUTE:
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_VAPP_DRM_EXECUTE), buf_size);
                //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                break;
            case DRM_PERMISSION_PRINT:
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_VAPP_DRM_PRINT), buf_size);
                //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                break;
#if __DRM_V02__
            case DRM_PERMISSION_EXPORT:
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_DRM_EXPORT), buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                break;
#endif
            default:
                break;
        }

#if __DRM_V02__
        if (constraint->status == DRM_STATUS_UNTRUSTED_TIME)
        {
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8)GetString(STR_ID_DRM_TIME_UNTRUSTED), buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        }
        else
#endif
        {

			
            if (constraint->type != DRM_CONSTRAINT_NONE)
            {
                if (constraint->type & DRM_CONSTRAINT_COUNT)
                {
		    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_COUNT_COSMOS), buf_size);
                    if (constraint->total_count > 0xFFFFFFFF)
                    {
                        if (constraint->used_count > 0xFFFFFFFF)
                        {
                            kal_wsprintf(
                                (WCHAR*) tmp,
                                "\n%u%09u/%u%09u",
                                (kal_uint32) (constraint->used_count / 1000000000),
                                (kal_uint32) (constraint->used_count % 1000000000),
                                (kal_uint32) (constraint->total_count / 1000000000),
                                (kal_uint32) (constraint->total_count % 1000000000));
                        }
                        else
                        {
                            kal_wsprintf(
                                (WCHAR*) tmp,
                                "\n%u/%u%09u",
                                (kal_uint32)constraint->used_count,
                                (kal_uint32) (constraint->total_count / 1000000000),
                                (kal_uint32) (constraint->total_count % 1000000000));
                        }

                    }
                    else
                    {
                        kal_wsprintf(
                            (WCHAR*) tmp,
                            "\n%u/%u",
                            (kal_uint32) constraint->used_count,
                            (kal_uint32) constraint->total_count);
                    }

                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) tmp, buf_size);
                }

            #ifdef __DRM_V02__
                if (constraint->type & DRM_CONSTRAINT_ACCUMULATED)
                {
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_ACCUMULATED), buf_size);
                    kal_wsprintf((WCHAR*)tmp, "\n%d\n", constraint->accum_dur);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) tmp, buf_size);
                }

                if (constraint->type & DRM_CONSTRAINT_TIMEDCOUNT)
                {
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_TIMEDCOUNT), buf_size);
                    kal_wsprintf((WCHAR*)tmp, "\n %d ", constraint->timed_count);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) tmp, buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_TIMEDCOUNT_TIME), buf_size);
                    kal_wsprintf((WCHAR*)tmp, " %d ", constraint->period);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) tmp, buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_SEC), buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                }
            #endif /* __DRM_V02__ */


                if (start > 0)
                {
		    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_START), buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                    mmi_dt_utc_sec_2_mytime(start, &t, MMI_FALSE);
                    date_string((MYTIME *)&t, (PU16) & data[mmi_ucs2strlen((PS8) data) << 1], DT_IDLE_SCREEN);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);
                    time_string((MYTIME *)&t, (PU16) & data[mmi_ucs2strlen((PS8) data) << 1], DT_IDLE_SCREEN);
                   // mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                }

                if (end > 0)
                {
		    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_END), buf_size);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                    mmi_dt_utc_sec_2_mytime(end, &t, MMI_FALSE);
                    date_string((MYTIME *)&t, (PU16) & data[mmi_ucs2strlen((PS8) data) << 1], DT_IDLE_SCREEN);
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);
                    time_string((MYTIME *)&t, (PU16) & data[mmi_ucs2strlen((PS8) data) << 1], DT_IDLE_SCREEN);
                  //  mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                }

            }
            else
            {
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNLIMITED), buf_size);
                //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
            }
        }
    }
}




/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_populate_drm_info_aux
 * DESCRIPTION
 *
 * PARAMETERS
 *  path                [?]         
 *  app_perm            [IN]        
 *  data                [?]         [?]
 *  buf_size            [IN]        
 *  ref                 [IN]        
 *  permission(?)       [IN]        
 *  rights          [?](?)
 * RETURNS
 *
 *****************************************************************************/
MMI_BOOL mmi_rmgr_populate_drm_info_aux(U16 *path, U8 app_perm, U8 *data, S32 buf_size, S32 ref)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE input = FS_ERROR_RESERVED;
    S32 cons_ret = DRM_RESULT_NON_DRM;
    MMI_BOOL result = MMI_FALSE, flag = MMI_TRUE;
    U8 permission;
    drm_method_enum method;
    MMI_BOOL is_installable;
    MMI_BOOL is_printable;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    DRM_MEM_START_EVAL

    if (ref < 0)
    {
        /* we use DRM_PERMISSION_PLAY first */
        input = DRM_open_file((kal_wchar*)path, FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_PLAY);

        if (input < DRM_RESULT_OK)
        {
            result = MMI_FALSE;
            goto final;
        }

        method = (drm_method_enum)DRM_get_object_method(input, NULL);
    }
    else
    {
        method =(drm_method_enum)DRM_get_object_method_by_ref(ref,DRM_DB_GET_ALL);
    }

    if (method != DRM_METHOD_NONE)  /* 1. DRM file */
    {
        if (ref < 0)
        {
    #ifdef __DRM_V02__
            U16 *sepa = kal_wstrrchr(path, (kal_int32) '\\');
    #endif
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_RIGHT), buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_PROTECTED), buf_size);

    #ifdef __DRM_V02__
            if (DRM_is_archive(input, NULL) && sepa &&
                app_ucs2_strnicmp((kal_int8*) (sepa - 4), (kal_int8*) L".odf\\", 5) != 0)
            {
                /* 1.1 Multi Part ODF */
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_MULTI_PART), buf_size);
                //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);

                result = MMI_FALSE;
                goto final;
            }
        #endif /* __DRM_V02__ */ 
            //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        }
    }
    else    /* 2. Not DRM file */
    {
        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_RIGHT), buf_size);
        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNPROTECTED), buf_size);
       // mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);

        result = MMI_FALSE;
        goto final;
    }

    if (method == DRM_METHOD_FORWARD_LOCK)
    {
        drm_constraint_struct cons;

        if (ref < 0)
        {
            DRM_get_constraint(input, NULL, DRM_PERMISSION_PLAY, &cons);
        }
        else
        {
            DRM_get_constraint_by_ref(ref, DRM_PERMISSION_PLAY, &cons);
        }

        if (cons.status == DRM_STATUS_RIGHTS_PRESENT)
        {
            /* 1.2 forward lock with right */
#ifdef __MMI_RMGR_SIMPLE_DETAILS__
            if (ref < 0)
            {
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8)GetString(STR_ID_RMGR_DETAIL_LEFT_COUNT), buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNLIMITED), buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8)GetString(STR_ID_RMGR_DETAIL_LEFT_TIME), buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L" ", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNLIMITED), buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                if (app_perm == DRM_PERMISSION_EXECUTE)
                {
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_INSTALLABLE), buf_size);
                }
                else
                {
                    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNINSTALLABLE), buf_size);
                }
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);

                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNFORWARDABLE), buf_size);

               // mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);

            }
            else
#endif /* __MMI_RMGR_SIMPLE_DETAILS__ */
            {
		mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_SUMMARY), buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNLIMITED), buf_size);
               // mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
            }
        }
        else
        {
            /* 1.3 forward lock without right */
	    mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_SUMMARY), buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_GLOBAL_INVALID), buf_size);
            //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        }

        result = MMI_FALSE;
        goto final;
    }


    permission = DRM_PERMISSION_PLAY;
    is_installable = is_printable = MMI_FALSE;

    do
    {
        if (app_perm != DRM_PERMISSION_ALL)
        {
            /* not in app_perm, we do not check this permission */
            if (app_perm & permission)
            {
                /* not first time in this loop, need to reopen file */
                if (ref < 0 && permission != DRM_PERMISSION_PLAY)
                {
                    DRM_close_file(input);
                    if (DRM_RESULT_OK > DRM_open_file(path, FS_READ_ONLY | FS_OPEN_SHARED, permission))
                    {
                        result = MMI_FALSE;
                        break;
                    }
                }
            }
            else
            {
                permission  = permission << 1;
                continue;
            }
        }

        if (permission &
            (DRM_PERMISSION_PLAY | DRM_PERMISSION_DISPLAY | DRM_PERMISSION_EXECUTE | DRM_PERMISSION_PRINT |
             DRM_PERMISSION_EXPORT))
        {
            drm_constraint_struct cons;
            memset(&cons, 0, sizeof(drm_constraint_struct));

            if (ref < 0)
            {
                cons_ret = DRM_get_constraint(input, NULL, permission, &cons);
            }
            else
            {
                cons_ret = DRM_get_constraint_by_ref(ref, permission, &cons);
            }

            if (cons_ret >= DRM_RESULT_OK &&
                (cons.status == DRM_STATUS_RIGHTS_PRESENT ||
                 cons.status == DRM_STATUS_UNTRUSTED_TIME || cons.status == DRM_STATUS_RIGHTS_IN_FUTURE))
            {
                /* 1.4 SD/CD/V2/PDCF with right */
                if (flag)
                {
#ifdef __MMI_RMGR_SIMPLE_DETAILS__
                    if (ref >=0)
#endif
                    {
	          	//ref value >=0 signifies that call is from licence list options.
			if(ref<0)
			{
			mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
			}
                        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_SUMMARY), buf_size);
                        //mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                    }
                }

                if (ref < 0)    /* list in file manager or AP*/
                {
                #ifndef __MMI_RMGR_SIMPLE_DETAILS__
                    mmi_rmgr_populate_drm_constraint(&cons, (U8)permission, (U8*)data, buf_size, MMI_TRUE);
                #else /* __MMI_RMGR_SIMPLE_DETAILS__ */ 
                    if (permission == DRM_PERMISSION_PLAY || permission == DRM_PERMISSION_DISPLAY ||
                        permission == DRM_PERMISSION_EXECUTE)
                    {
                        mmi_rmgr_populate_drm_constraint(&cons, (U8)permission, (U8*)data, buf_size, MMI_TRUE);

                        /* This is the first permission for the content
                           If one content has the play or display permission, we will skip execute permission */
                        if (permission == DRM_PERMISSION_EXECUTE && flag == MMI_TRUE)
                        {
                            is_installable = MMI_TRUE;
                        }
                    }
                    else if (permission == DRM_PERMISSION_PRINT)
                    {
                        is_printable = MMI_TRUE;
                    }
                    else
                    {
                        break;
                    }
                #endif /* __MMI_RMGR_SIMPLE_DETAILS__ */ 
                }
                else /* list in right manager */
                {
                    mmi_rmgr_populate_drm_constraint(&cons, (U8)permission, (U8*)data, buf_size, MMI_FALSE);
                }

                flag = KAL_FALSE;
            }
        }
        permission = permission << 1;
    }
    while(permission < DRM_PERMISSION_EXPORT && permission <= app_perm);


    if (flag)
    {
        /* 1.5 SD/CD/V2/PDCF without right */
	mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_SUMMARY), buf_size);
        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_GLOBAL_INVALID), buf_size);
      // mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
    }
#ifdef __MMI_RMGR_SIMPLE_DETAILS__
    else
    {
        if (ref < 0) /* list in file manager or AP*/
        {
            if (is_printable)
            {
				mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_PRINTABLE), buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
            }

            if (is_installable)
            {
				mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_INSTALLABLE), buf_size);
            }
            else
            {
				mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNINSTALLABLE), buf_size);
            }

            mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);

            if (DRM_interdev_movable(0, path))
            {
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_FORWARDABLE), buf_size);
            }
            else
            {
                mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) GetString(STR_ID_RMGR_DETAIL_UNFORWARDABLE), buf_size);
            }
          //  mmi_rmgr_ucs2cat_secure((PS8) data, (PS8) L"\n", buf_size);
        }
    }
#endif /* __MMI_RMGR_SIMPLE_DETAILS__ */ 

final:
    if (ref < 0)
    {
        if (input >= 0)
        {
            DRM_close_file(input);
        }
    }
    else
    {
        DRM_free_ro_detail();
    }
    DRM_MEM_END_EVAL
    return result;
}







S32 mmi_rmgr_check_rights_internal(FS_HANDLE handle, U8 permission, U16 icon, mmi_rmgr_ri_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = MMI_RMGR_STATUS_OK;
    U8 method;
    MMI_BOOL is_permitted;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_check_rights_internal %d %d %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_CHECK_RIGHTS_INTERNAL, handle, permission, icon, callback));

    ASSERT(handle>=DRM_RESULT_OK);

    method = DRM_get_object_method(handle, NULL);

    if (method == DRM_METHOD_NONE)
    {
        result = MMI_RMGR_STATUS_OK;
        goto final;
    }

    is_permitted = DRM_validate_permission(handle, NULL, permission);

    if (is_permitted)
    {
        result = MMI_RMGR_STATUS_OK;
        goto final;
    }

    /* No permission area */
    if (!srv_nw_usab_is_any_network_available())
    {
        result = MMI_RMGR_STATUS_NO_PERMISSION;
        goto final;
    }

    if (method & DRM_METHOD_SEPARATE_DELIVERY ||
        method & DRM_METHOD_V2 ||
        method & DRM_METHOD_PDCF)
    {
        U32 size = DRM_MAX_LINE_LENGTH;
        U8 *url = (U8 *)drmt_mem_alloc(size);

        memset(url, 0, size);
        if(DRM_RESULT_OK > DRM_get_rights_issuer(handle, (kal_char*)url, &size))
        {
            result = MMI_RMGR_STATUS_NO_PERMISSION;
        }
        else
        {
            result = MMI_RMGR_STATUS_REQUEST_RIGHTS;
            /* register url, size, icon and callback */
            mmi_rmgr_register_unlock_session(0, NULL, permission, MMI_FALSE, url, size, icon, callback);
        }
        drmt_mem_free(url);
    }
    else
    {
        result = MMI_RMGR_STATUS_NO_PERMISSION;
    }

final:
    if (result != MMI_RMGR_STATUS_REQUEST_RIGHTS)
    {
        mmi_rmgr_wipe_unlock_session();
    }

    return result;
}








S32 mmi_rmgr_check_rights_by_handle(FS_HANDLE handle, U8 permission, U16 icon, mmi_rmgr_ri_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_check_rights_by_handle %d %d %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_CHECK_RIGHTS_BY_HANDLE, handle, permission, icon, callback));

#ifdef __DRM_PDCF__
    if (handle < DRM_RESULT_OK)
    {
        return handle;
    }

    if (DRM_get_object_method(handle, NULL)!= DRM_METHOD_PDCF)
    {
        ASSERT(0);
        return MMI_RMGR_STATUS_NO_PERMISSION;
    }

    mmi_rmgr_clear_unlock_screen();

    /* register file handle only DRM_get_ro_list */
    mmi_rmgr_register_unlock_session(handle, NULL, 0, MMI_FALSE, NULL, 0, 0, NULL);

    return mmi_rmgr_check_rights_internal(handle, permission, icon, callback);
#else
    ASSERT(0);
    return MMI_RMGR_STATUS_NO_PERMISSION;
#endif
}





S32 mmi_rmgr_check_rights_by_path(U16* file_path, U8 permission, U16 icon, mmi_rmgr_ri_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
	S32 pop_index;
    S32 result = MMI_RMGR_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_check_rights_by_path %d %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_CHECK_RIGHTS_BY_PATH, permission, icon, callback));

	

	pop_index = vapp_rmgr_get_is_dl_popup();
	if(pop_index != 0)
	{
		mmi_rmgr_wipe_unlock_session();
		vcp_global_popup_cancel(pop_index);
		pop_index = 0;
	}

    handle = DRM_open_file(file_path, FS_READ_ONLY, permission);
    if (handle >= DRM_RESULT_OK)
    {
        mmi_rmgr_clear_unlock_screen();

        /* register file_path only */
        mmi_rmgr_register_unlock_session(0, (U16*)file_path, 0, MMI_FALSE, NULL, 0, 0, NULL);

        result = mmi_rmgr_check_rights_internal(handle, permission, icon, callback);

        DRM_close_file(handle);
    }
    else
    {
        result = handle;
    }
    return result;
}








/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_check_rights_full_procedure
 * DESCRIPTION
 * PARAMETERS
 *  file_path       [IN]     file path
 *  FS_HANDLE       [IN]     file handle, can be null when file_path is null
 *  callback        [IN]       callback of app to tell proceed or not
 * RETURNS
 *  MMI_RMGR_STATUS_REQUEST_RIGHTS: SD/V2 w/o valid rights
 *  MMI_RMGR_STATUS_NO_PERMISSION: FL/CD w/o valid rights or SD/V2 w/o RI URL
 *  negative value: Otherwise, error code
 *****************************************************************************/

MMI_BOOL mmi_rmgr_check_rights_full_procedure(U16* filepath, FS_HANDLE handle, U8 permission, U16 icon, mmi_rmgr_ri_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_check_rights_full_procedure %d %d %d %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_CHECK_RIGHTS_FULL_PROCEDURE, handle, permission, icon, callback));

    if (filepath)
    {
        result = mmi_rmgr_check_rights_by_path(filepath, permission, icon, callback);
    }
    else
    {
        result = mmi_rmgr_check_rights_by_handle(handle, permission, icon, callback);
    }

    switch(result)
    {
        case MMI_RMGR_STATUS_OK:
        case MMI_RMGR_STATUS_WITH_RIGHTS:
            return MMI_TRUE;
        case MMI_RMGR_STATUS_NO_PERMISSION:
        {
            //mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DRM_PROHIBITED), MMI_EVENT_FAILURE, NULL);
			vtst_request_rights_confirm_ext(2);
            break;
        }
        case MMI_RMGR_STATUS_REQUEST_RIGHTS:
        {
            mmi_rmgr_request_rights_confirm();
            break;
        }
        default:
        {
            //mmi_popup_display((WCHAR*)GetString(srv_fmgr_fs_error_get_string(result)), MMI_EVENT_FAILURE, NULL);
             vtst_request_rights_confirm_ext(3);
		}
    }
    return MMI_FALSE;
}






void mmi_rmgr_register_unlock_session(FS_HANDLE handle,  U16 *path,
                                      U8 permission, MMI_BOOL more,
                                      U8 *url, U32 url_size,
                                      U16 icon,
                                      mmi_rmgr_ri_callback callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_register_unlock_session %d %d %d %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_REGISTER_UNLOCK_SESSION, permission, more, url_size, icon, callback));


    if (handle > FS_NO_ERROR)
    {
        rmgr_req_ri_entry.file_handle = handle;
    }

    if (path)
    {
        ASSERT(rmgr_req_ri_entry.file_path == NULL);

        rmgr_req_ri_entry.file_path = (U16 *)drmt_mem_alloc((kal_wstrlen((kal_wchar*)path) + 1) * ENCODING_LENGTH);
        app_ucs2_strcpy((kal_int8 *)rmgr_req_ri_entry.file_path, (kal_int8 *)path);
    }

    rmgr_req_ri_entry.more = more;

    if (url)
    {
        ASSERT(rmgr_req_ri_entry.url == NULL);
        rmgr_req_ri_entry.url = (U16 *)drmt_mem_alloc(url_size * ENCODING_LENGTH);
        kal_wsprintf((kal_wchar*)rmgr_req_ri_entry.url, "%s", url);
    }

    if (icon)
    {
        rmgr_req_ri_entry.icon = icon;
    }
    else
    {
        rmgr_req_ri_entry.icon = mmi_rmgr_get_root_icon();
    }

    if (callback)
    {
        rmgr_req_ri_entry.result_callback = callback;
    }

    if (permission)
    {
        rmgr_req_ri_entry.permission = permission;
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_wipe_unlock_session
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_wipe_unlock_session(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_wipe_unlock_session",
            (TRACE_GROUP_UI, RMGR_UTIL_WIPE_UNLOCK_SESSION));

    if (rmgr_req_ri_entry.file_path)
    {
        drmt_mem_free(rmgr_req_ri_entry.file_path);
    }

    if (rmgr_req_ri_entry.url)
    {
        drmt_mem_free(rmgr_req_ri_entry.url);
    }

    /* also set is_set to KAL_FALSE */
    memset(&rmgr_req_ri_entry, 0, sizeof(rmgr_req_ri_entry));
}





void mmi_rmgr_query_icon(U16 *filepath, U8 perm, U16 *id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_RMGR_REPLACE_FILE_ICON__
    FS_HANDLE handle = DRM_open_file(filepath, FS_READ_ONLY | FS_OPEN_SHARED, perm);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(perm)
    {
    if (handle >= FS_NO_ERROR)
    {
        U8 method = DRM_get_object_method(handle, NULL);
        if (method != DRM_METHOD_NONE)
        {
            if (DRM_validate_permission(handle, NULL, perm))
            {
                *id = IMG_ID_RMGR_UNLOCK;
            }
            else
            {
                *id = IMG_ID_RMGR_LOCK;
            }
        }
    }
    }
    DRM_close_file(handle);
#endif /* __MMI_RMGR_REPLACE_FILE_ICON__ */
}



/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_hint_trans
 * DESCRIPTION
 *  Hint handler for trans. tracking ON/OFF
 * PARAMETERS
 *  hint_idx        [IN]        Hint index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_hint_scan_disk(U16 hint_idx)
{
#ifdef __DRM_SUPPORT_SCAN_DISK__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_rmgr_p->allow_scan_disk)
    {
        mmi_ucs2cpy((S8*) hintData[hint_idx], GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[hint_idx], GetString(STR_GLOBAL_OFF));
    }
#endif /* __DRM_SUPPORT_SCAN_DISK__ */ 
}

#ifdef __DRM_SUPPORT_SCAN_DISK__
static MMI_BOOL scan_cancelled_before = MMI_FALSE;
static MMI_BOOL scan_switch = MMI_FALSE;
/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_toggle_scan_disk
 * DESCRIPTION
 *  Toggle scan disk
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 void mmi_rmgr_toggle_scan_disk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_rmgr_p->allow_scan_disk == MMI_TRUE)
    {
        mmi_rmgr_p->allow_scan_disk = MMI_FALSE;
        mmi_rmgr_scan_disk_turnoff_1();
        StopTimer(RMGR_SCAN_DISK_TIMER);
    }
    else
    {
        mmi_rmgr_p->allow_scan_disk = MMI_TRUE;
        mmi_rmgr_scan_disk_turnon_1();
        mmi_rmgr_scan_disk();
    }

   // mmi_popup_display((WCHAR*) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_scan_disk_callback
 * DESCRIPTION
 *  scan all file system
 * PARAMETERS
 *  serial      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_scan_disk_callback(U8 serial, S32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_rmgr_p->scan_serial = 0;

    /* scan finished, we start to scan once again after 10 min */
    StartTimer(RMGR_SCAN_DISK_TIMER, 1000*60*10, mmi_rmgr_scan_disk);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_scan_disk_turnoff
 * DESCRIPTION
 *  cancel scan all file system
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_rmgr_scan_disk_turnoff(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return mmi_rmgr_scan_disk_turnoff_1();

}

mmi_ret mmi_rmgr_scan_disk_turnoff_1(void)
{
    if (mmi_rmgr_p->scan_serial != 0)
    {
        scan_cancelled_before = DRM_async_cancel_process(mmi_rmgr_p->scan_serial);
    }
	
    scan_switch = MMI_FALSE;
	
	return MMI_RET_OK;


}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_scan_disk_turnon
 * DESCRIPTION
 *  cancel scan all file system
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_rmgr_scan_disk_turnon(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Biggest switch : mmi_rmgr_p->allow_scan_disk  */
    /* smaller switch : scan_switch */
return mmi_rmgr_scan_disk_turnon_1();

}

mmi_ret mmi_rmgr_scan_disk_turnon_1(void)
{

    if (mmi_rmgr_p->allow_scan_disk)
    {
        scan_switch = MMI_TRUE;

        if (scan_cancelled_before)
        {
            scan_cancelled_before = MMI_FALSE;
            mmi_rmgr_scan_disk();
        }
    }

	return MMI_RET_OK;


}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_scan_disk_available
 * DESCRIPTION
 *  cancel scan all file system
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_rmgr_scan_disk_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* check every situation that if we can scan now */

    #ifdef __USB_IN_NORMAL_MODE__
    if (mmi_usb_is_in_mass_storage_mode())
    {
        return MMI_FALSE;
    }
#endif /* __USB_IN_NORMAL_MODE__ */ 

    return scan_switch;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_scan_disk
 * DESCRIPTION
 *  scan all file system
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_scan_disk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (mmi_rmgr_p->scan_serial)
    {
        /* scan disk is running now */
        return;
    }

    if (!mmi_rmgr_p->allow_scan_disk)
    {
        /* we cannot scan disk now */
        return;
    }

    StopTimer(RMGR_SCAN_DISK_TIMER);

    if (!mmi_rmgr_scan_disk_available())
    {
        /* cannot scan now, we try this 1 min later */
        StartTimer(RMGR_SCAN_DISK_TIMER, 1000*60, mmi_rmgr_scan_disk);
        return;
    }

    /* Continue to scan */
    if (FS_GetAttributes((WCHAR*)DRM_SCAN_QUEUE_FILEPATH) >= FS_NO_ERROR)
    {
        DRM_scan_disk(DRM_SCAN_DISK, NULL, &(mmi_rmgr_p->scan_serial), mmi_rmgr_scan_disk_callback);
    }
    else
    {
        DRM_scan_disk(DRM_SCAN_DISK, L"*", &(mmi_rmgr_p->scan_serial), mmi_rmgr_scan_disk_callback);
    }
}



#endif /*__DRM_SUPPORT_SCAN_DISK__*/

#define MMI_RMGR_EXTEND_WARNING_MAX_COUNT 2
#define MMI_RMGR_EXTEND_WARNING_MAX_DATETIME (DT_SEC_PER_DAY) /* 1 day */
#define MMI_RMGR_EXTEND_WARNING_MAX_ACCUM (DT_SEC_PER_HOUR)
#define MMI_RMGR_EXTEND_WARNING_MAX_TIMECOUNT 2

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_check_rights_internal
 * DESCRIPTION
 *  To validate rights with given path and permission
 * PARAMETERS
 *  file_path       [IN]       file path
 *  permission      [IN]       application specific permission
 *  callback        [IN]       callback of app to tell proceed or not
 * RETURNS
 *  MMI_RMGR_STATUS_REQUEST_RIGHTS: the rights is expired or expired soon.
 *  MMI_RMGR_STATUS_WITH_RIGHTS: this content with solid rights
 *  MMI_RMGR_STATUS_OK: this content is not a DRM file
 *  negative value: Otherwise, error code
 *****************************************************************************/
S32 mmi_rmgr_extend_rights_internal(FS_HANDLE handle, U8 permission, U16 icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = MMI_RMGR_STATUS_OK;
    U8 method;
    U32 size = DRM_MAX_LINE_LENGTH;
    U8 *url = NULL;
    drm_constraint_struct cons;
    applib_time_struct curr_time;
    S32 curr_in_sec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_extend_rights_internal %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_EXTREND_RIGHTS_INTERNAL, permission, icon));

    /* No permission area */
    if (!srv_nw_usab_is_any_network_available())
    {
        result = MMI_RMGR_STATUS_OK;
        goto final;
    }

    ASSERT(handle>=DRM_RESULT_OK);

    method = DRM_get_object_method(handle, NULL);

    /* not DRM file, need not to extend right */
    if (method == DRM_METHOD_NONE)
    {
        result = MMI_RMGR_STATUS_OK;
        goto final;
    }

    /* FL and CD cannot etend rights */
    if (method == DRM_METHOD_FORWARD_LOCK || method == DRM_METHOD_COMBINED_DELIVERY)
    {
        result = MMI_RMGR_STATUS_WITH_RIGHTS;
        goto final;
    }

    /* no right issuer , cannot get more rights */
    size = DRM_MAX_LINE_LENGTH;
    url = (U8 *)drmt_mem_alloc(DRM_MAX_LINE_LENGTH);
    if(DRM_RESULT_OK > DRM_get_rights_issuer(handle, (kal_char*)url, &size) || size == 0)
    {
        result = MMI_RMGR_STATUS_WITH_RIGHTS;
        goto final;
    }

    DRM_get_constraint(handle, NULL, permission, &cons);

    /* no permission, need to extend right */
    if (cons.status != DRM_STATUS_RIGHTS_PRESENT)
    {
        result = MMI_RMGR_STATUS_REQUEST_RIGHTS;
        goto final;
    }

    applib_dt_get_rtc_time(&curr_time);
    curr_in_sec = applib_dt_mytime_2_utc_sec(&curr_time, KAL_FALSE);

    /* too less count */
    if (cons.type & DRM_CONSTRAINT_COUNT)
    {
        if (cons.used_count <= MMI_RMGR_EXTEND_WARNING_MAX_COUNT)
        {
            result = MMI_RMGR_STATUS_REQUEST_RIGHTS;
            goto final;
        }
    }


    /* too less time */
    if (cons.type & DRM_CONSTRAINT_DATETIME && cons.end_time > 0)
    {
        if (cons.end_time - curr_in_sec <= MMI_RMGR_EXTEND_WARNING_MAX_DATETIME)
        {
            result = MMI_RMGR_STATUS_REQUEST_RIGHTS;
            goto final;
        }
    }

    /* too less time */
    if (cons.type & DRM_CONSTRAINT_INTERVAL && cons.end_intv > 0)
    {
        if (cons.end_intv - curr_in_sec <= MMI_RMGR_EXTEND_WARNING_MAX_DATETIME)
        {
            result = MMI_RMGR_STATUS_REQUEST_RIGHTS;
            goto final;
        }
    }

#ifdef __DRM_V02__
    /* too less accumulate time */
    if (cons.type & DRM_CONSTRAINT_ACCUMULATED)
    {
        if (cons.accum_dur <= MMI_RMGR_EXTEND_WARNING_MAX_ACCUM)
        {
            result = MMI_RMGR_STATUS_REQUEST_RIGHTS;
            goto final;
        }
    }

    /* too less timecount */
    if (cons.type & DRM_CONSTRAINT_TIMEDCOUNT)
    {
        if (cons.timed_count <= MMI_RMGR_EXTEND_WARNING_MAX_TIMECOUNT)
        {
            result = MMI_RMGR_STATUS_REQUEST_RIGHTS;
            goto final;
        }
    }
#endif

final:

    if (result != MMI_RMGR_STATUS_REQUEST_RIGHTS)
    {
        mmi_rmgr_wipe_unlock_session();
    }
    else
    {
        mmi_rmgr_register_unlock_session(0, NULL, permission, MMI_FALSE, url, size, icon, NULL);
    }

    if (url)
    {
        drmt_mem_free(url);
    }

    return result;
}






S32 mmi_rmgr_extend_rights_internal_mod(FS_HANDLE handle, U8 permission, U16 icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = MMI_RMGR_STATUS_OK;
    U8 method;
    U32 size = DRM_MAX_LINE_LENGTH;
    U8 *url = NULL;
    drm_constraint_struct cons;
    applib_time_struct curr_time;
    S32 curr_in_sec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_extend_rights_internal %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_EXTREND_RIGHTS_INTERNAL, permission, icon));

    /* No permission area */
   // if (!srv_nw_usab_is_any_network_available() ||
	//	srv_mode_switch_is_network_service_available())
	if (!srv_nw_usab_is_any_network_available())
    {
        result = MMI_RMGR_STATUS_OK;
        goto final;
    }

    ASSERT(handle>=DRM_RESULT_OK);

    method = DRM_get_object_method(handle, NULL);

    /* not DRM file, need not to extend right */
    if (method == DRM_METHOD_NONE)
    {
        result = MMI_RMGR_STATUS_OK;
        goto final;
    }

    /* FL and CD cannot etend rights */
    if (method == DRM_METHOD_FORWARD_LOCK || method == DRM_METHOD_COMBINED_DELIVERY)
    {
        result = MMI_RMGR_STATUS_WITH_RIGHTS;
        goto final;
    }

    /* no right issuer , cannot get more rights */
    size = DRM_MAX_LINE_LENGTH;
    url = (U8 *)drmt_mem_alloc(DRM_MAX_LINE_LENGTH);
    if(DRM_RESULT_OK > DRM_get_rights_issuer(handle, (kal_char*)url, &size) || size == 0)
    {
        result = MMI_RMGR_STATUS_WITH_RIGHTS;
        goto final;
    }

    DRM_get_constraint(handle, NULL, permission, &cons);

    /* no permission, need to extend right */
    if (cons.status != DRM_STATUS_RIGHTS_PRESENT)
    {
        result = MMI_RMGR_STATUS_REQUEST_RIGHTS;
        goto final;
    }

    applib_dt_get_rtc_time(&curr_time);
    curr_in_sec = applib_dt_mytime_2_utc_sec(&curr_time, KAL_FALSE);

    /* too less count */
    if (cons.type & DRM_CONSTRAINT_COUNT)
    {
        if (cons.used_count <= MMI_RMGR_EXTEND_WARNING_MAX_COUNT)
        {
            result = MMI_RMGR_STATUS_REQUEST_RIGHTS;
            goto final;
        }
    }


    /* too less time */
    if (cons.type & DRM_CONSTRAINT_DATETIME && cons.end_time > 0)
    {
        if (cons.end_time - curr_in_sec <= MMI_RMGR_EXTEND_WARNING_MAX_DATETIME)
        {
            result = MMI_RMGR_STATUS_REQUEST_RIGHTS;
            goto final;
        }
    }

    /* too less time */
    if (cons.type & DRM_CONSTRAINT_INTERVAL && cons.end_intv > 0)
    {
        if (cons.end_intv - curr_in_sec <= MMI_RMGR_EXTEND_WARNING_MAX_DATETIME)
        {
            result = MMI_RMGR_STATUS_REQUEST_RIGHTS;
            goto final;
        }
    }



final:

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_extend_rights_by_path
 * DESCRIPTION
 *  To check if it is necessary to extend right.
 * PARAMETERS
 *  file_path       [IN]    file path
 *  permission      [IN]    content permission
 *  icon            [IN]    icon
 * RETURNS
 *  MMI_RMGR_STATUS_REQUEST_RIGHTS: the rights is expired or expired soon.
 *  MMI_RMGR_STATUS_WITH_RIGHTS: this content with solid rights
 *  MMI_RMGR_STATUS_OK: this content is not a DRM file
 *  negative value: Otherwise, error code
 *****************************************************************************/
S32 mmi_rmgr_extend_rights_by_path(U16 *filepath, U8 permission, U16 icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;
    S32 result = MMI_RMGR_STATUS_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_extend_rights_by_path %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_EXTREND_RIGHTS_BY_PATH, permission, icon));

    handle = DRM_open_file((kal_wchar*)filepath, FS_READ_ONLY, permission);
    if (handle >= DRM_RESULT_OK)
    {
        mmi_rmgr_clear_unlock_screen();

        /* register file_path only */
        mmi_rmgr_register_unlock_session(0, (U16*)filepath, 0, MMI_FALSE, NULL, 0, 0, NULL);
        rmgr_req_ri_entry.show_detail = MMI_TRUE;

        result = mmi_rmgr_extend_rights_internal(handle, permission, icon);

        DRM_close_file(handle);
    }
    else
    {
        result = handle;
    }
    return result;

}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_extend_rights_full_procedure
 * DESCRIPTION
 *  To check if it is necessary to extend right. We will handle all the following
 *  sceen in this function
 * PARAMETERS
 *  file_path       [IN]    file path
 *  permission      [IN]    content permission
 *  icon            [IN]    icon
 * RETURNS
 *  MMI_TRUE: need to extend rights
 *  MMI_FALSE: no need
 *****************************************************************************/
MMI_BOOL mmi_rmgr_extend_rights_full_procedure(U16 *filepath, U8 permission, U16 icon)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    RMGR_UTIL_TRC("[RMGR] mmi_rmgr_extend_rights_full_procedure %d %d",
            (TRACE_GROUP_UI, RMGR_UTIL_EXTREND_RIGHTS_FULL_PROCEDURE, permission, icon));

    result = mmi_rmgr_extend_rights_by_path(filepath, permission, icon);

    if (result == MMI_RMGR_STATUS_REQUEST_RIGHTS)
    {
        mmi_rmgr_request_rights_confirm();
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_init
 * DESCRIPTION
 *  Init function of rights manager application, called in InitService()
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __DRM_V02__
    mmi_rmgr_p->trans_state = DRM_toggle_tracking(MMI_TRUE);
    mmi_rmgr_p->wl_count = 0;

    SetProtocolEventHandler(DRM_app_ro_expiry_hdlr, MSG_ID_DRMT_RO_EXPIRY_IND);
    SetProtocolEventHandler(DRM_app_activate_hdlr, MSG_ID_DRMT_ACTIVATE_CNF);
#endif /* __DRM_V02__ */

    SetProtocolEventHandler(DRM_app_parse_drm_message_hdlr, MSG_ID_DRMT_PARSE_DM_CNF);
    SetProtocolEventHandler(DRM_app_install_obj_hdlr, MSG_ID_DRMT_INSTALL_OBJECT_CNF);
    SetProtocolEventHandler(DRM_app_process_database_hdlr, MSG_ID_DRMT_PROCESS_DATABASE_CNF);
    SetProtocolEventHandler(DRM_app_get_ro_num_hdlr, MSG_ID_DRMT_GET_RO_NUM_CNF);
    SetProtocolEventHandler(DRM_app_encode_drm_message_hdlr, MSG_ID_DRMT_ENCODE_DRM_MESSAGE_CNF);
#ifdef __DRM_SUPPORT_SCAN_DISK__
    SetProtocolEventHandler(DRM_app_scan_disk_hdlr, MSG_ID_DRMT_SCAN_DISK_CNF);
#endif
#ifdef __DRM_SUPPORT_SD_CALLBACK__
        SetProtocolEventHandler(DRM_app_sd_expiry_hdlr, MSG_ID_DRMT_SD_EXPIRY_IND);
#endif

    /* special case for drm task busy */
#ifdef __DRM_V02__
    SetProtocolEventHandler((PsFuncPtr) DRM_slave_common_hdlr, MSG_ID_DRMT_ACTIVATE_REQ);
#endif
    SetProtocolEventHandler((PsFuncPtr) DRM_slave_common_hdlr, MSG_ID_DRMT_INSTALL_OBJECT_REQ);
    SetProtocolEventHandler((PsFuncPtr) DRM_slave_common_hdlr, MSG_ID_DRMT_PARSE_DM_REQ);
    SetProtocolEventHandler((PsFuncPtr) DRM_slave_common_hdlr, MSG_ID_DRMT_GET_RO_NUM_REQ);
    SetProtocolEventHandler((PsFuncPtr) DRM_slave_common_hdlr, MSG_ID_DRMT_PROCESS_DATABASE_REQ);
    SetProtocolEventHandler((PsFuncPtr) DRM_slave_common_hdlr, MSG_ID_DRMT_ENCODE_DRM_MESSAGE_REQ);
    ReadValue(NVRAM_RMGR_DB_CHECK, &rmgr_dbchk_nv, DS_BYTE, &error);
    vapp_set_rmgr_spc(rmgr_dbchk_nv);
#ifdef __DRM_V02__
    mmi_drm_ui_init();
#endif

#ifdef __DRM_SUPPORT_SCAN_DISK__
    /* StartTimer(RMGR_SCAN_DISK_TIMER, 1000*60, mmi_rmgr_scan_disk); */
#endif
}








#endif 
