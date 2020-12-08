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
*  JavaAppFactorySrv.c
*
* Project:
* --------
*  Venus
*
* Description:
* ------------
*  
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
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifdef __J2ME__
/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMI_include.h"
#include "JavaAppFactorySrvProt.h"
#include "JavaAppFactorySrvGprot.h"
#include "JavaAgencyDef.h"
#include "Jam_interface.h"
#include "jam_internal.h"  /* 20110223,SUPPORT_JAVA_SHARE_MED */
#include "AppMgrSrvGprot.h"
#include "AppMgrSrvProt.h"
#include "j2me_custom.h"
#include "jvm_internal.h"
#include "App_str.h"
#include "JavaAgencyProt.h"
#include "Jam_mvm_manager.h"
#include "Conversions.h"
#ifdef __COSMOS_MMI_PACKAGE__
#include "vapp_java_srv.h"
#elif defined (__PLUTO_MMI_PACKAGE__)
#include "AlertScreen.h"
#endif

#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGprot.h"
#ifdef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_vapp_usbmmi_def.h"
#endif
#endif
#include "Jam_msg_handler.h"
#include "J2me_trace.h"
#if (defined (__OP02__) || defined(__OP01_3G__))&& defined __COSMOS_MMI_PACKAGE__
#include "vapp_op_mm_util.h"
#endif
#if defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__)
#include "vapp_op_launcher_key_mainmenu_util.h"
#endif
#if defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__MMI_VUI_LAUNCHER__)
#include "PhoneSetupGprots.h"
#endif

/***************************************************************************** 
* Define
*****************************************************************************/
#define JAVA_APP_FACTORY_NAME  "JavaAppFactory"
#define JAVA_SYS_PATH          "@java"
#define JAVA_ICON_SUFFIX       "icon"
typedef struct {
    int installed_mids;
    int preinstall_mids;
    int operator_mids;
} srv_java_app_jacatory_statistics_struct;
extern kal_char j2me_sys_dir_path[];
#define srv_java_appfactory_get_sys_path(wfilename)                               kal_wsprintf(wfilename, "%c:\\%s\\\0",j2me_sys_dir_path[0],JAVA_SYS_PATH)
#define srv_java_appfactory_get_file_path(wfilename,app_name)                     kal_wsprintf(wfilename, "%c:\\%s\\%s\\%s\0",j2me_sys_dir_path[0],JAVA_SYS_PATH,JAVA_APP_FACTORY_NAME,app_name)
#define srv_java_appfactory_get_file_path_by_storage_name(wfilename,storage_name) kal_wsprintf(wfilename, "%c:\\%s\\%s\\java.%s\0",j2me_sys_dir_path[0],JAVA_SYS_PATH,JAVA_APP_FACTORY_NAME,storage_name)
#define srv_java_appfactory_get_factory_path(wfilename)                           kal_wsprintf(wfilename, "%c:\\%s\\%s\\\0",j2me_sys_dir_path[0],JAVA_SYS_PATH,JAVA_APP_FACTORY_NAME)
#define srv_java_appfactory_get_appname_pattern(wfilename)                        kal_wsprintf(wfilename, "%c:\\%s\\%s\\java.*\0",j2me_sys_dir_path[0],JAVA_SYS_PATH,JAVA_APP_FACTORY_NAME)
#define srv_java_appfactory_get_app_icon_path(wfilename,storage_name)             kal_wsprintf(wfilename, "%c:\\%s\\%s.%s",j2me_sys_dir_path[0],JAVA_SYS_PATH,storage_name,JAVA_ICON_SUFFIX)
#define srv_java_appfactory_get_app_java_path(wfilename)                          kal_wsprintf(wfilename, "%c:\\%s\\java.\0",j2me_sys_dir_path[0],JAVA_SYS_PATH)
/***************************************************************************** 
* Typedef
*****************************************************************************/
typedef void(*unify_srv_callback)(void* user_data, U32 result);
/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern void mmi_java_dummy_entry(void);
extern MMI_BOOL needToSendGetListReq;
extern java_context_struct g_java;
extern kal_char g_mmi_java_current_selected_mids_root[128];
kal_char g_mmi_java_current_launching_app_name[MMI_APP_NAME_MAX_LEN+1] = {0};
extern kal_eventgrpid g_java_event_group_2;
java_info_struct java_app_info;
extern  kal_bool g_java_list_lock;
extern MMI_BOOL g_mmi_java_is_background_display;

kal_bool g_mmi_java_allow_show_icon=KAL_TRUE; 
/*use this app to keep the running name;g_java_running_list use it to maintain data*/
srv_appfactory_func_table_struct java_appfactory_func_table = {
    SRV_APP_FACTORY_JAVA_TYPE,
    srv_java_appfactory_get_reg_mid_num,
    srv_java_appfactory_get_reg_app_list,
    srv_java_appfactory_get_string,
    srv_java_appfactory_get_image,
    srv_java_appfactory_get_info,
    srv_java_appfactory_launch,
    srv_java_appfactory_delete,
    srv_java_appfactory_get_reg_id_list,
    srv_java_appfactory_get_app_name_by_id,
    srv_java_appfactory_get_id_by_app_name
};
extern void jam_mids_getlist_exit_free(void);  
extern void mmi_java_mids_install(U16 *jad_file_name,U16 *jar_file_name,U16 *download_url,MMI_BOOL delete);       

/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_get_running_app_num
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
kal_int32 srv_java_appfactory_get_running_app_num(void)
{
    return jam_mvm_get_running_count();
}
/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_is_storage_type_app_name
* DESCRIPTION
*  return true if app_name is java.<storage_name>
*  return false if app_name is java.<vendor name>.<midlet name>
* PARAMETERS
*  CHAR*
* RETURNS
*  kal_bool
*****************************************************************************/
static kal_bool srv_java_appfactory_is_storage_type_app_name(CHAR* app_name)
{
   // kal_int32 idx = 0;
    CHAR* str = 0;
    if(app_name == NULL)return KAL_FALSE;
    str = strchr(app_name,'.');
    if(!str)return KAL_FALSE;
    str = strchr(str+1,'.');
    if(str)return KAL_FALSE;
    return KAL_TRUE;
}

static mmi_ret srv_java_appfactory_get_storage_name_from_file(CHAR* storage_name, CHAR* app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    WCHAR * filename;
    kal_int32 handle = -1;
    kal_uint32 err_code = J2ME_NO_ERROR; 
    kal_uint32 byte = 0;
    WCHAR *wapp_name = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    filename = GET_FILE_NAME_BUFF();
    wapp_name = (WCHAR*)get_ctrl_buffer(MMI_APP_NAME_MAX_LEN<<1);
    srv_java_appfactory_get_sys_path(filename);
    mmi_chset_convert(MMI_CHSET_UTF8,MMI_CHSET_UCS2, app_name, (char *)wapp_name, (MMI_APP_NAME_MAX_LEN -1)<<1);

    mmi_ucs2cat((CHAR *)filename, (const CHAR *)wapp_name);
    handle = FS_Open((U16*) filename, FS_READ_ONLY);
    if (handle < 0)
    {
        err_code = J2ME_FILE_NOT_FOUND;
    }
    else
    {
        if(FS_Read(handle, (void*)storage_name, STORAGE_LEN, &byte) < FS_NO_ERROR)
        {
            err_code = J2ME_ACTION_FAILE;
        } 
    }
    FS_Close(handle);
    free_ctrl_buffer(wapp_name);
    FREE_FILE_NAME_BUFF(filename);
    return ((err_code == J2ME_NO_ERROR) ? MMI_RET_OK: MMI_RET_ERR);
}
/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_get_storage_name_by_app_name
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret srv_java_appfactory_get_storage_name_by_app_name(CHAR* storage_name, CHAR* app_name)
{
    if(storage_name == NULL || app_name == NULL)return MMI_RET_ERR;
    if(srv_java_appfactory_is_storage_type_app_name(app_name) == KAL_FALSE)
    {
        srv_java_appfactory_get_storage_name_from_file(storage_name,app_name);
    }
    else
    {
        strcpy(storage_name, (const kal_char*)(app_name+strlen("java.")));
    }
    return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_get_record
* DESCRIPTION
*  Check whether is a java application default game.
* PARAMETERS
*  WCHAR name: Record file name.
* RETURNS
*  kal_bool true: is default game
*               false: not default game
*****************************************************************************/
static mmi_ret srv_java_appfactory_get_record(WCHAR * name,mmi_java_app_factory_record_struct *record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    WCHAR * filename = NULL;
    kal_int32 handle = -1;
    kal_uint32 err_code = J2ME_NO_ERROR; 
    kal_uint32 byte = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    filename = GET_FILE_NAME_BUFF();
    srv_java_appfactory_get_factory_path(filename);
    mmi_wcscat(filename, name);
    handle = FS_Open((U16*) filename, FS_READ_ONLY);
    if (handle < 0)
    {
        err_code = 1;
    }else{
        if(FS_Read(handle, (void*)record, sizeof(mmi_java_app_factory_record_struct), &byte) < FS_NO_ERROR)
        {
            err_code = 2;
        } 
    }
    FS_Close(handle);
    FREE_FILE_NAME_BUFF(filename);
    kal_trace(JAM_JAVAAGENCY_GROUP, SRV_JAVA_APPFACTORY_GET_RECORD,err_code);
    return ((err_code == J2ME_NO_ERROR) ? MMI_RET_OK: MMI_RET_ERR);
}

/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_get_record
* DESCRIPTION
*  Check whether is a java application default game.
* PARAMETERS
*  WCHAR name: Record file name.
* RETURNS
*  kal_bool true: is default game
*               false: not default game
*****************************************************************************/
static mmi_ret srv_java_appfactory_set_record(WCHAR * wapp_name,mmi_java_app_factory_record_struct *record)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    WCHAR * filename = NULL;
    kal_int32 handle = -1;
    kal_uint32 err_code = J2ME_NO_ERROR; 
    kal_uint32 byte = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    filename = GET_FILE_NAME_BUFF();
    srv_java_appfactory_get_factory_path(filename);
    mmi_wcscat(filename, wapp_name);
    handle = FS_Open((U16*) filename, FS_CREATE_ALWAYS | FS_COMMITTED);
    if (handle < 0)
    {
        err_code = 1;
    }
    else
    {
        if (FS_Write(handle, (void*)record, sizeof(mmi_java_app_factory_record_struct), &byte) < 0)
        {           
            err_code = 2;
        }
    }
    FS_Close(handle);
    FREE_FILE_NAME_BUFF(filename);
    kal_trace(JAM_JAVAAGENCY_GROUP, SRV_JAVA_APPFACTORY_SET_RECORD,err_code);
    return ((err_code == J2ME_NO_ERROR) ? MMI_RET_OK: MMI_RET_ERR);
}
/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_get_bg_enabled_apname
* DESCRIPTION
* input app name to get if the bg is enable
* PARAMETERS
*  void
* RETURNS
*  KAL_TRUE ==> OK
*****************************************************************************/
kal_bool srv_java_appfactory_get_bg_enabled_apname(kal_bool* is_on, CHAR *app_name)
{
    kal_bool kal_ret = KAL_TRUE;
    WCHAR * wapp_name = NULL;
    mmi_ret ret = MMI_OK;
    mmi_java_app_factory_record_struct *record = NULL;
    
    record=(mmi_java_app_factory_record_struct*)get_ctrl_buffer(sizeof(mmi_java_app_factory_record_struct));
    memset(record, 0, sizeof(mmi_java_app_factory_record_struct));
    wapp_name = GET_FILE_NAME_BUFF();
    kal_wsprintf(wapp_name,"%s\0",app_name);
    ret = srv_java_appfactory_get_record(wapp_name,record);
    if(ret == MMI_OK)
    {
	    *is_on = record->is_bg_enabled;

    	kal_ret = KAL_TRUE;
    }
    else
    {
    	kal_ret = KAL_FALSE;
    }
    free_ctrl_buffer(record);
    record=NULL;
    FREE_FILE_NAME_BUFF(wapp_name);
    kal_trace(JAM_JAVAAGENCY_GROUP, SRV_JAVA_APPFACTORY_GET_BG_ON, kal_ret, *is_on);
	return kal_ret;

}


/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_get_bg_enabled
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  KAL_TRUE ==> OK
*****************************************************************************/
kal_bool srv_java_appfactory_get_bg_enabled(kal_bool* is_on, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    kal_char* storage_name = jam_mvm_get_vm_storage_name(vm_id);
    CHAR app_name[STORAGE_LEN+10] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if(storage_name == NULL)
    {
        return KAL_FALSE;
    }
    srv_java_appfactory_get_app_name_by_storage_name(app_name,storage_name);
    return srv_java_appfactory_get_bg_enabled_apname(is_on, app_name);
}

/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_set_bg_enabled_apname
* DESCRIPTION
*  set VK flag in record file.
* PARAMETERS
*  
* RETURNS
*  KAL_TRUE ==> OK
*****************************************************************************/
kal_bool srv_java_appfactory_set_bg_enabled_apname(kal_bool is_on, CHAR *app_name)
{
    mmi_ret ret = MMI_OK;
    kal_bool kal_ret = KAL_FALSE;
    mmi_java_app_factory_record_struct *record = NULL;
    WCHAR * wapp_name = NULL;

    record=(mmi_java_app_factory_record_struct*)get_ctrl_buffer(sizeof(mmi_java_app_factory_record_struct));
    memset(record, 0, sizeof(mmi_java_app_factory_record_struct));
    wapp_name = GET_FILE_NAME_BUFF();
    kal_wsprintf(wapp_name,"%s\0",app_name);
    ret = srv_java_appfactory_get_record(wapp_name,record);
    if(ret == MMI_OK)
    {
        record->is_bg_enabled= is_on;
        ret = srv_java_appfactory_set_record(wapp_name,record);
        kal_ret = KAL_TRUE;

    }

    FREE_FILE_NAME_BUFF(wapp_name);  
    free_ctrl_buffer(record);
    record=NULL;
    kal_trace(JAM_JAVAAGENCY_GROUP, SRV_JAVA_APPFACTORY_SET_BG_ON, kal_ret, is_on);
	return kal_ret;
}

/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_set_vk_on
* DESCRIPTION
*  set VK flag in record file.
* PARAMETERS
*  
* RETURNS
*  KAL_TRUE ==> OK
*****************************************************************************/
kal_bool srv_java_appfactory_set_bg_enabled(kal_bool is_on, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    kal_char* storage_name = jam_mvm_get_vm_storage_name(vm_id);
    CHAR app_name[STORAGE_LEN+10] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if(storage_name == NULL)
    {
        return KAL_FALSE;
    }
    srv_java_appfactory_get_app_name_by_storage_name(app_name,storage_name);
    return srv_java_appfactory_set_bg_enabled_apname(is_on, app_name);
}


/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_vk_is_on_by_app_name
* DESCRIPTION
*  Check whether is a java application support VK.
* PARAMETERS
*  char* name: app name.
* RETURNS
*  kal_bool true: is on
*               false: is off
*****************************************************************************/
kal_bool srv_java_appfactory_vk_is_on_by_app_name(kal_char * app_name)
{
    mmi_java_app_factory_record_struct *record = NULL;
    WCHAR * wname = NULL;
    kal_bool is_vk_on=KAL_FALSE; 

    record=(mmi_java_app_factory_record_struct*)get_ctrl_buffer(sizeof(mmi_java_app_factory_record_struct));
    memset(record, 0, sizeof(mmi_java_app_factory_record_struct));
    if(NULL != app_name)
    {
        wname = GET_FILE_NAME_BUFF();
        kal_wsprintf(wname,"%s\0",app_name);        
        srv_java_appfactory_get_record(wname,record);
        FREE_FILE_NAME_BUFF(wname);
    }
    is_vk_on=record->is_vk_on;
    free_ctrl_buffer(record);
    record=NULL;
    return is_vk_on;
}

/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_vk_is_on
* DESCRIPTION
*  Check whether is a java application support VK.
* PARAMETERS
*  char* name: app name.
* RETURNS
*  kal_bool true: is on
*               false: is off
*****************************************************************************/
kal_bool srv_java_appfactory_vk_is_on(kal_char * storage_name)
{
    kal_bool ret = KAL_FALSE;
    CHAR app_name[STORAGE_LEN+10] = {0};
    if(NULL != storage_name)
    {
        srv_java_appfactory_get_app_name_by_storage_name(app_name,storage_name);
        ret = srv_java_appfactory_vk_is_on_by_app_name(app_name);
    }
    return ret;
}

/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_set_vk_on
* DESCRIPTION
*  set VK flag in record file.
* PARAMETERS
*  
* RETURNS
*  
*****************************************************************************/
mmi_ret srv_java_appfactory_set_vk_on(kal_bool is_on,kal_char* app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    WCHAR * wapp_name = NULL;
    mmi_java_app_factory_record_struct *record = NULL;
    mmi_ret ret = MMI_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    record=(mmi_java_app_factory_record_struct*)get_ctrl_buffer(sizeof(mmi_java_app_factory_record_struct));
    memset(record, 0, sizeof(mmi_java_app_factory_record_struct));
    wapp_name = GET_FILE_NAME_BUFF();
    kal_wsprintf(wapp_name,"%s\0",app_name);
    ret = srv_java_appfactory_get_record(wapp_name,record);
    if(ret == MMI_OK)
    {
        record->is_vk_on = is_on;
        ret = srv_java_appfactory_set_record(wapp_name,record);
    }    
    FREE_FILE_NAME_BUFF(wapp_name);
    free_ctrl_buffer(record);
    record=NULL;
    kal_trace(JAM_JAVAAGENCY_GROUP, SRV_JAVA_APPFACTORY_SET_VK_ON,ret,is_on);
    return ret;
}

/*****************************************************************************
* FUNCTION 
* srv_java_appfactory_allow_show_icon
* DESCRIPTION
* 
* PARAMETERS
* 
* RETURNS 
* kal_bool 
*modify/add date: 2012-9-19
*modify/add time: 19:43:48
*****************************************************************************/
kal_bool srv_java_appfactory_allow_show_icon()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_java_allow_show_icon;
    
}

/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_is_in_op_filter
* DESCRIPTION
*  Check whther the app name should be filtrated for operater's customization.
* PARAMETERS
*  WCHAR * app_name
* RETURNS
*  TRUE or FALSE
*****************************************************************************/
kal_bool srv_java_appfactory_is_in_op_filter(WCHAR * app_name)
{
#if (defined (__OP02__) || defined(__OP01_3G__))&& defined __COSMOS_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_int32 index = 0;
    kal_int32 table_size = vapp_op_get_midlet_count();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(index = 0; index < table_size; index++)
    {
        if(!app_ucs2_strcmp((const kal_int8*)app_name, (const kal_int8*)vapp_op_midlet_info[index].midlet_name))
        {
            return KAL_TRUE;
        }
    }
#endif

#if defined(__OP01_3G__) && defined(__MMI_VUI_LAUNCHER_KEY__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_int32 midlet_index = 0;
    kal_int32 midlet_count = vapp_op_launcher_key_get_midlet_count();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(midlet_index = 0; midlet_index < midlet_count; midlet_index++)
    {
        if(!app_ucs2_strcmp((const kal_int8*)app_name, (const kal_int8*)vapp_op_launcher_key_midlet_info[midlet_index].midlet_name))
        {
            return KAL_TRUE;
        }
    }
#endif

    return KAL_FALSE;
}


/*****************************************************************************
* FUNCTION
 *  srv_java_appfactory_timer_callback
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_java_appfactory_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DOSDirEntry info;
    WCHAR * name_pattern;
    WCHAR * filename;
    kal_int32 handle; 
    kal_char app_name[MMI_APP_NAME_MAX_LEN] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filename = GET_FILE_NAME_BUFF();
    name_pattern = GET_FILE_NAME_BUFF();
    srv_java_appfactory_get_appname_pattern(name_pattern);
    if ((handle = FS_FindFirst(
         (UI_string_type) name_pattern,
         0,
         0,
         &info,
         (WCHAR*) filename,
         MAX_WCHAR_FILENAME_LEN)) >= 0)
    {
        mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char *)filename, (char *)app_name, MMI_APP_NAME_MAX_LEN -1);
        srv_appmgr_update_app_info(NULL, EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE);
        FS_FindClose(handle);
    }
    else if (handle == FS_DEVICE_BUSY)
    {
        StartTimer(J2ME_APP_FACTORY_TIMER, 3 * 1000, (FuncPtr) srv_java_appfactory_timer_callback);   
    }
    FREE_FILE_NAME_BUFF(name_pattern);
    FREE_FILE_NAME_BUFF(filename);
}


/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_get_reg_mid_num
* DESCRIPTION
*  get the total number of installed midlet suite.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
U32 srv_java_appfactory_get_reg_mid_num(srv_appmgr_flag_type flag)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
  //  kal_uint32 err_code = NW_OP_NO_ERR;
    FS_DOSDirEntry info;
    WCHAR * name_pattern;
    WCHAR * filename;
    kal_int32 handle;     
    kal_int32 count = 0;
    mmi_java_app_factory_record_struct *record = NULL;     


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return 0;
    }

    if(!srv_java_appfactory_allow_show_icon())
    {
        return 0;
    }
#endif

 #ifndef __MMI_JAVA_PREINSTALL_TCARD_PACKAGE__ 

    if( SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE ==flag )
    {     
        return 0;
    }
 #endif 
    record=(mmi_java_app_factory_record_struct*)get_ctrl_buffer(sizeof(mmi_java_app_factory_record_struct));
    memset(record, 0, sizeof(mmi_java_app_factory_record_struct));
    name_pattern = GET_FILE_NAME_BUFF();
    filename = GET_FILE_NAME_BUFF();
    srv_java_appfactory_get_appname_pattern(name_pattern);
    if ((handle = FS_FindFirst(
        (UI_string_type) name_pattern,
        0,
        0,
        &info,
        (WCHAR*) filename,
        MAX_WCHAR_FILENAME_LEN)) >= 0)
    {
    do
    {      
        srv_java_appfactory_get_record(filename,record);

         switch(flag)
        {
        #ifdef __MMI_JAVA_PREINSTALL_TCARD_PACKAGE__ 
            case SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE:
                {
                    if(!record->is_installed)
                    {
                        count++;
                    }
                    break;
                }
        #endif
            case SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE:
                {
                    if((!record->is_default)&&(!record->is_op_mids)&&(record->is_installed))
                    {
                        count++;
                    }
                    break;
                }
            case SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE:
            case SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE:
            case SRV_APPMGR_JAVA_APP_PACKAGE_TYPE:
                {
                    if(record->is_installed)
                    {
                        count++;
                    }
                    break;     
                }
            default:break;
        
        }

     } while (FS_FindNext(handle, &info, (WCHAR*) filename, MAX_WCHAR_FILENAME_LEN) >= 0);
     FS_FindClose(handle);  
     }
        
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    else if (handle == FS_DEVICE_BUSY)
    {
        StartTimer(J2ME_APP_FACTORY_TIMER, 3 * 1000, (FuncPtr) srv_java_appfactory_timer_callback);
    }
#endif
    free_ctrl_buffer(record);
    record=NULL;     
    FREE_FILE_NAME_BUFF(name_pattern);
    FREE_FILE_NAME_BUFF(filename);
    kal_trace(JAM_JAVAAGENCY_GROUP, SRV_JAVA_APPFACTORY_GET_REG_MID_NUM,count);
    return count;
}


/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_get_reg_app_list
* DESCRIPTION
*  get the name list of installed midlet suite.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret srv_java_appfactory_get_reg_app_list(srv_appmgr_flag_type flag, mmi_app_package_name_struct * item, U32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
   //  kal_uint32 err_code = NW_OP_NO_ERR;
    FS_DOSDirEntry info;
    WCHAR * name_pattern;
    WCHAR * filename;
    kal_int32 handle;     
    kal_int32 count = 0;
  //char storage_name[LEN] = {0};
  //kal_int32 mids_id = -1;
    mmi_java_app_factory_record_struct *record = NULL;      
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return MMI_RET_ERR;
    }
    if(!srv_java_appfactory_allow_show_icon())
    {
        return 0;
    }
#endif
#ifndef __MMI_JAVA_PREINSTALL_TCARD_PACKAGE__

        if(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE==flag)
        {      
            return MMI_RET_OK;
        }
 #endif 
        record=(mmi_java_app_factory_record_struct*)get_ctrl_buffer(sizeof(mmi_java_app_factory_record_struct));
        memset(record, 0, sizeof(mmi_java_app_factory_record_struct));
        filename = GET_FILE_NAME_BUFF();
        name_pattern = GET_FILE_NAME_BUFF();
        srv_java_appfactory_get_appname_pattern(name_pattern);
        if ((handle = FS_FindFirst(
            (UI_string_type) name_pattern,
            0,
            0,
            &info,
            (WCHAR*) filename,
            MAX_WCHAR_FILENAME_LEN)) >= 0)
        {
            do
            {
                srv_java_appfactory_get_record(filename,record);

                 switch(flag)
                 {
                #ifdef __MMI_JAVA_PREINSTALL_TCARD_PACKAGE__
                    case SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE:
                    {
                        if(!record->is_installed)
                        {
                            mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char *)filename, (char *)&item[count], MMI_APP_NAME_MAX_LEN -1);
                            count++;
                        }
                        break;
                    }
                #endif
                    case SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE:
                    {
                        if((!record->is_default)&&(!record->is_op_mids)&&(record->is_installed))
                        {
                            mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char *)filename, (char *)&item[count], MMI_APP_NAME_MAX_LEN -1);
                            count++;
                        }
                        break;
                    }
                    case SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE:
                    case SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE:
                    case SRV_APPMGR_JAVA_APP_PACKAGE_TYPE:
                    {
                        if(record->is_installed)
                        {
                            mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char *)filename, (char *)&item[count], MMI_APP_NAME_MAX_LEN -1);
                            count++;
                        }
                        break;     
                    }
                    default:break;
        
                 }
              
            } while (FS_FindNext(handle, &info, (WCHAR*) filename, MAX_WCHAR_FILENAME_LEN) >= 0 && count < num);
            FS_FindClose(handle);  
        }
        free_ctrl_buffer(record);
        record=NULL;         
        FREE_FILE_NAME_BUFF(filename);
        FREE_FILE_NAME_BUFF(name_pattern);
 
    kal_trace(JAM_JAVAAGENCY_GROUP, SRV_JAVA_APPFACTORY_GET_REG_APP_LIST,flag,num,0);
    return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_get_string
* DESCRIPTION
*  get the name list of a midlet suite by app name.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret srv_java_appfactory_get_string(CHAR * app_name, WCHAR * mids_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    WCHAR * wapp_name;
    mmi_java_app_factory_record_struct *record = NULL;
    kal_int32 mid_name_len = 0;    
    mmi_ret ret = MMI_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return MMI_RET_ERR;
    }
#endif
    record=(mmi_java_app_factory_record_struct*)get_ctrl_buffer(sizeof(mmi_java_app_factory_record_struct));
    memset(record, 0, sizeof(mmi_java_app_factory_record_struct));

    wapp_name = GET_FILE_NAME_BUFF();
    kal_wsprintf(wapp_name,"%s\0",app_name);
    ret = srv_java_appfactory_get_record(wapp_name,record);
    FREE_FILE_NAME_BUFF(wapp_name);
    if(ret == MMI_OK)
    {
        mid_name_len = mmi_ucs2strlen((CHAR*)record->mids_name);
        if(mid_name_len < MMI_APP_NAME_MAX_LEN-1)
        {
            memcpy(mids_name, record->mids_name,(mid_name_len)<<1);
            mids_name[mid_name_len] = '\0';
        }
        else
        {
            memcpy(mids_name, record->mids_name,(MMI_APP_NAME_MAX_LEN-1)<<1);
            mids_name[MMI_APP_NAME_MAX_LEN-1] = '\0';
        }        
    }
    free_ctrl_buffer(record);
    record=NULL;
    kal_trace(JAM_JAVAAGENCY_GROUP,SRV_JAVA_APPFACTORY_GET_STRING,ret);
    return ret;
}


void srv_java_appfactory_get_app_name_by_storage_name(CHAR * app_name, kal_char * storage_name)
{
    if(app_name==NULL || storage_name == NULL) return;
    sprintf(app_name, "java.%s\0", storage_name);
}


/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_get_image
* DESCRIPTION
*  get the name list of a midlet suite by app name.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret srv_java_appfactory_get_image(CHAR * app_name, mmi_image_src_struct* img)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    kal_char storage_name[STORAGE_LEN] = {0};
    kal_int32 handle = -1;
   // kal_int32 mids_id = -1;
    WCHAR * filename;
    kal_int32 idx = 0;
    kal_char driver_arr[4] = {0};
#if defined(__COSMOS_MMI_PACKAGE__)
    WCHAR * wapp_name;
    mmi_java_app_factory_record_struct *record = NULL;
    mmi_ret ret = MMI_OK;
    kal_bool is_show_tcard_icon = KAL_FALSE;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return MMI_RET_ERR;
    }
#endif
    driver_arr[0] = SRV_FMGR_SYSTEM_DRV;
    driver_arr[1] = SRV_FMGR_PUBLIC_DRV;
    driver_arr[2] = SRV_FMGR_CARD_DRV;
    driver_arr[3] = SRV_FMGR_CARD2_DRV;
    kal_trace(JAM_JAVAAGENCY_GROUP, SRV_JAVA_APPFACTORY_GET_IMAGE);
#if defined(__COSMOS_MMI_PACKAGE__)
    record=(mmi_java_app_factory_record_struct*)get_ctrl_buffer(sizeof(mmi_java_app_factory_record_struct));
    memset(record, 0, sizeof(mmi_java_app_factory_record_struct));

    wapp_name = GET_FILE_NAME_BUFF();
    kal_wsprintf(wapp_name,"%s\0",app_name);
    ret = srv_java_appfactory_get_record(wapp_name,record);
    FREE_FILE_NAME_BUFF(wapp_name);
    if(ret == MMI_OK)
    {
        if ((record->installed_drive == SRV_FMGR_CARD_DRV || record->installed_drive == SRV_FMGR_CARD2_DRV) &&
            FS_GetDevStatus((UINT)record->installed_drive, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
        {
            is_show_tcard_icon = KAL_TRUE;
        }
    }
#endif
    filename = GET_FILE_NAME_BUFF();
    srv_java_appfactory_get_storage_name_by_app_name(storage_name,app_name);
    srv_java_appfactory_get_app_icon_path(filename,storage_name);
    for(idx = 0; idx<sizeof(driver_arr); idx++)
    {
        filename[0] = driver_arr[idx];
        handle = FS_Open((U16*) filename, FS_READ_ONLY | FS_OPEN_SHARED);
        if(handle != FS_FILE_NOT_FOUND && handle != FS_PATH_NOT_FOUND)
        {
            break;
        }        
    }

    if(handle < 0)
    {
#if defined(__COSMOS_MMI_PACKAGE__)
        if (is_show_tcard_icon)
        {
            img->data.res_id = IMG_ID_VJAVA_MAINMENU_TCARD_ICON;
        }
        else
        {
            img->data.res_id = IMG_ID_VJAVA_MAINMENU_ICON;
        }
#elif defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__MMI_VUI_LAUNCHER__)
        if (mmi_phnset_launcher_get_launcher_type() == MMI_PHNSET_LAUNCHER_KEY)
        {
            img->data.res_id = IMG_ID_JAVA_KEY_LAUNCHER_ICON;
        }
        else
        {
            img->data.res_id = IMG_ID_JAVA_LAUNCHER_ICON;
        }
#elif !defined(__MMI_VUI_LAUNCHER_KEY__) && defined(__MMI_VUI_LAUNCHER__)
        img->data.res_id = IMG_ID_JAVA_LAUNCHER_ICON;
#elif defined(__MMI_VUI_LAUNCHER_KEY__) && !defined(__MMI_VUI_LAUNCHER__)
        img->data.res_id = IMG_ID_JAVA_KEY_LAUNCHER_ICON;
#elif defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
        img->data.res_id = IMG_ID_JAVA_LAUNCHER_ICON;
#else
        img->data.res_id = IMG_JAVA_STAR1;
#endif
        img->type = MMI_IMAGE_SRC_TYPE_RES_ID;
    }
    else
    {
        app_ucs2_strcpy((kal_int8*)img->data.path,(kal_int8*)filename);
        img->type = MMI_IMAGE_SRC_TYPE_PATH;
    }
    FS_Close(handle);
 #if defined(__COSMOS_MMI_PACKAGE__)   
    free_ctrl_buffer(record);
    record=NULL;     
#endif
    FREE_FILE_NAME_BUFF(filename);
    return MMI_RET_OK;    
}

/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_get_info
* DESCRIPTION
*  get the info of a midlet suite by app name.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret srv_java_appfactory_get_info(CHAR * app_name, srv_app_info_struct * info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/      
    mmi_ret ret = MMI_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    kal_trace(JAM_JAVAAGENCY_GROUP,SRV_JAVA_APPFACTORY_GET_MIDS_INFO);
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return MMI_RET_ERR;
    }
#endif
    ret = srv_java_appfactory_get_string(app_name, info->string);
    if (ret != MMI_OK)
    {
        return MMI_RET_ERR;
    }
    srv_java_appfactory_get_image(app_name, &(info->image));
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_get_vm_id
* DESCRIPTION
*  get vm id by app name.
* PARAMETERS
*  app_name
* RETURNS
*  S32
*****************************************************************************/
S32  srv_java_appfactory_get_vm_id(CHAR * app_name)
{
    kal_char storage_name[STORAGE_LEN] = {0};
    kal_int32 vm_id = INVALIDE_VM_ID;
    mmi_ret ret;
    ret = srv_java_appfactory_get_storage_name_by_app_name(storage_name,app_name);
    if(ret == MMI_RET_ERR)
    {
        return INVALIDE_VM_ID;
    }
    else
    {
        vm_id =jam_mvm_get_vm_id((kal_char *) storage_name,-1);
        return vm_id;
    }
}


/*****************************************************************************
* FUNCTION
 *  srv_java_appfactory_get_reg_id_list
 * DESCRIPTION
 *  get the app id list of installed midlet suite.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_java_appfactory_get_reg_id_list(srv_appmgr_flag_type flag, U32 *id, U32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    // kal_uint32 err_code = NW_OP_NO_ERR;
    FS_DOSDirEntry info;
    WCHAR * name_pattern;
    WCHAR * filename;
    kal_int32 handle;     
    kal_int32 count = 0;
    mmi_java_app_factory_record_struct *record=NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return 0;
    }
    if(!srv_java_appfactory_allow_show_icon())
    {
        return 0;
    }
#endif

#ifndef __MMI_JAVA_PREINSTALL_TCARD_PACKAGE__
    if(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE==flag)
    {      
        return MMI_RET_OK;
    }
 #endif 
        record=(mmi_java_app_factory_record_struct*)get_ctrl_buffer(sizeof(mmi_java_app_factory_record_struct));
        memset(record, 0, sizeof(mmi_java_app_factory_record_struct));
        filename = GET_FILE_NAME_BUFF();
        name_pattern = GET_FILE_NAME_BUFF();
        srv_java_appfactory_get_appname_pattern(name_pattern);
        if ((handle = FS_FindFirst(
            (UI_string_type) name_pattern,
            0,
            0,
            &info,
            (WCHAR*) filename,
            MAX_WCHAR_FILENAME_LEN)) >= 0)
        {
            do
            {
                srv_java_appfactory_get_record(filename,record);

                switch(flag)
                {
                #ifdef __MMI_JAVA_PREINSTALL_TCARD_PACKAGE__
                    case SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE:
                    {
                        if(!record->is_installed)
                        {
                            id[count] = (U32) atoi(&record->storage_name[1]);
                            count++;
                        }
                        break;
                    }
                #endif
                    case SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE:
                    {
                        if((!record->is_default)&&(!record->is_op_mids)&&(record->is_installed))
                        {
                           id[count] = (U32) atoi(&record->storage_name[1]);
                            count++;
                        }
                        break;
                    }
                    case SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE:
                    case SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE:
                    case SRV_APPMGR_JAVA_APP_PACKAGE_TYPE:
                    {
                        if(record->is_installed)
                        {
                            id[count] = (U32) atoi(&record->storage_name[1]);
                            count++;
                        }
                        break;     
                    }
                    default:break;
        
                 }

            } while (FS_FindNext(handle, &info, (WCHAR*) filename, MAX_WCHAR_FILENAME_LEN) >= 0 && count < num);
            FS_FindClose(handle);  
        }
        FREE_FILE_NAME_BUFF(filename);
        FREE_FILE_NAME_BUFF(name_pattern);
        free_ctrl_buffer(record);
        record=NULL;      

    kal_trace(JAM_JAVAAGENCY_GROUP, SRV_JAVA_APPFACTORY_GET_REG_ID_LIST,flag,num,0);
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
 *  srv_java_appfactory_get_app_name_by_id
 * DESCRIPTION
 *  get the app name by app id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_java_appfactory_get_app_name_by_id(U32 id, CHAR *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(app_name, "java.J%07d\0", id);
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
 *  srv_java_appfactory_get_id_by_app_name
 * DESCRIPTION
 *  get the app id by app name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_java_appfactory_get_id_by_app_name(const CHAR *app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    return (U32) atoi(app_name + 6);
}


/*****************************************************************************
* FUNCTION
 *  srv_java_appfactory_terminate_screen
 * DESCRIPTION
 *  Callback function to handle
 *  Ask user if they want to terminate VM first before launch MIDlet
 * PARAMETERS
 *  teminate    [IN]    user select yes/No
 * RETURNS
 *  void
 *****************************************************************************/
void srv_java_appfactory_terminate_screen(MMI_BOOL terminate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(terminate)
    {
        jam_enter_terminate_mode(g_mmi_java_current_selected_vm_id);
        g_mmi_java_current_selected_vm_id = -1;
        mmi_java_entry_terminating(MMI_FALSE);
    }
}


/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_launch
* DESCRIPTION
*  Launch the  midlet suite by app name.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
MMI_ID srv_java_appfactory_launch(srv_appfactory_launch_type_enum type, CHAR *app_name, void* param, U32 parm_size)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    kal_char storage_name[STORAGE_LEN] ={0};
    kal_int32 mids_id;
   // kal_int32 count;
   // kal_int32 vm_id;
    MMI_ID ret = GRP_ID_INVALID;
#ifdef __COSMOS_MMI_PACKAGE__
    mmi_frm_asm_property_struct p;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    kal_trace(JAM_JAVAAGENCY_GROUP,SRV_JAVA_APPFACTORY_LAUNCH);   
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
#ifdef __COSMOS_MMI_PACKAGE__
        vapp_java_display_popup(STR_JAVA_ERROR_CODE_NO_CARD,VJAVA_POPUP_WARNING,VAPP_JAVA_ENTRY_NONE);
#else
        mmi_popup_display_simple_ext(STR_JAVA_ERROR_CODE_NO_CARD, MMI_EVENT_WARNING, GRP_ID_ROOT, NULL);
#endif
        goto finalizeStep;
    }
#endif
    if (jam_mvm_has_launching_midlet())
    {
        goto finalizeStep;
    }
    if(jam_is_busy())
    {
        mmi_java_display_is_busy();
        goto finalizeStep;
    }
#ifdef __COSMOS_MMI_PACKAGE__ 
    if(vapp_screen_lock_is_exist())
    {
        goto finalizeStep;
    }
#endif

#if (defined( __MMI_USB_SUPPORT__)&& defined(__COSMOS_MMI_PACKAGE__))
    if(srv_usb_is_in_mass_storage_mode())
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR *)((UI_string_type)get_string(vapp_usb_get_error_info(0, NULL))));  
        goto finalizeStep;
    }
#endif    

    if(app_name == NULL ||app_name[0] == '\0')
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,SRV_JAVA_APPFACTORY_LAUNCH_1);
        goto finalizeStep;
    }
    memcpy(g_mmi_java_current_launching_app_name,app_name,MMI_APP_NAME_MAX_LEN);
    srv_java_appfactory_get_storage_name_by_app_name(storage_name,app_name);

    if (jam_mvm_is_shutdowning() ||
    jam_mvm_has_terminating_midlet_in_mids((kal_char *) storage_name))
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,SRV_JAVA_APPFACTORY_LAUNCH_2);
        memset(g_mmi_java_current_launching_app_name,0,MMI_APP_NAME_MAX_LEN+1);
        mmi_java_display_is_busy();
        goto finalizeStep;
    }
    g_mmi_java_current_selected_vm_id = srv_java_appfactory_get_vm_id(app_name);
    if(g_mmi_java_current_selected_vm_id != INVALIDE_VM_ID) /* resume*/
    {   /* resume*/
        mmi_java_update_mids_runtime_setting(g_mmi_java_current_selected_vm_id);
        jam_resume_screen();
        ret = GRP_ID_JAVA_APP;
        goto finalizeStep;
    }
    
    if(jam_mvm_get_current_vm_id()!= INVALIDE_VM_ID&&g_mmi_java_current_selected_vm_id!=jam_mvm_get_current_vm_id())
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,SRV_JAVA_APPFACTORY_LAUNCH_5,g_mmi_java_current_selected_vm_id,jam_mvm_get_current_vm_id());
        goto finalizeStep;
    }
    /* Launch new app*/
    mids_id = jam_call_back_functions.jam_get_mids_id_from_storage_name(storage_name);
    if(mids_id < 0)
    {
        #ifdef __MMI_JAVA_PREINSTALL_TCARD_PACKAGE__     // modify by Zhiqing 2012-9-11;
        srv_java_appfactory_preinstall_mids_install(app_name);
        #else
            kal_trace(JAM_JAVAAGENCY_GROUP,SRV_JAVA_APPFACTORY_LAUNCH_3);
        #ifdef __PLUTO_MMI_PACKAGE__
            mmi_popup_display_simple_ext(STR_GLOBAL_FILE_NOT_FOUND, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
        #endif
    #endif
        goto finalizeStep;
    }
    needToSendGetListReq = MMI_TRUE;
    g_java.mids_info_end = g_java.mids_info_start = -1;
    g_java.mids_list_filter.filter_type = JAM_NONE_FILTER;
    g_java.total_java_app_mids = mids_id;
    
    g_java_list_lock = KAL_TRUE;
    if(!mmi_java_fetch_mids_list(mids_id - 1, (UI_string_type) NULL, (PU8*) NULL, 0))
    {
        goto finalizeStep; 
    }
    g_java.mids_index = mids_id - 1;
    g_java.mid_index = 0;
    app_ucs2_str_to_asc_str((kal_int8 *)(&g_mmi_java_current_selected_mids_root[0]),(kal_int8 *) (g_java.mids_info[g_java.mids_index - g_java.mids_info_start].storage_name));   
   // count = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mid_count;
    
#if(MAX_VM_INSTANCE_NUM == 1)
    if (jam_mvm_is_pause_mode(0) || jam_mvm_is_minimize_mode(0))  
    {
#ifdef __COSMOS_MMI_PACKAGE__       
        if(!mmi_frm_group_is_present(APP_JAVA))
        { 
            mmi_frm_group_create_ex(
                GRP_ID_ROOT,
                APP_JAVA,
                NULL,
                NULL,
                MMI_FRM_NODE_NONE_FLAG);

            mmi_java_dummy_entry();
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        }
        vapp_java_entry_terminate_dialog();
#elif defined (__PLUTO_MMI_PACKAGE__)
        g_mmi_java_current_selected_vm_id = 0;
        g_java.screen_after_terminate = TER_ENTRY_TASK_MANAGER;
        jam_mids_getlist_exit_free();
        mmi_java_entry_cb_terminate_dialog(srv_java_appfactory_terminate_screen, (U16*)GetString(STR_JAVA_TERMINATE_JAVA_GAME),0); 
#endif
        goto finalizeStep;
    }
    else
    {
#ifdef __COSMOS_MMI_PACKAGE__ 
        mmi_frm_scrn_set_leave_proc(APP_JAVA, SCR_JAVA_DUMMY, NULL);
        mmi_frm_group_close(APP_JAVA);
#endif
    }
#endif
    
    mmi_java_send_mid_getlist_req();
    mmi_java_load_setting();
    ret = GRP_ID_JAVA_APP;
finalizeStep:
    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_add_record
* DESCRIPTION
*  App a record into app factory mapping file.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret srv_java_appfactory_add_record(mmi_java_app_factory_record_struct* record)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    kal_int32 handle = -1;
    kal_uint32 err_code = J2ME_NO_ERROR; 
    kal_uint32 byte = 0;
   // kal_uint8 count = 0;
    WCHAR * filename;
    CHAR app_name[30] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    filename = GET_FILE_NAME_BUFF();
    srv_java_appfactory_get_app_java_path(filename);
    app_ucs2_strcat((kal_int8 *) filename,(const kal_int8 *) record->mids_vendor);
    app_ucs2_strcat((kal_int8 *) filename,(const kal_int8 *)L".");
    app_ucs2_strcat((kal_int8 *) filename,(const kal_int8 *) record->mids_name);
    if(srv_java_appfactory_is_in_op_filter(filename+3+strlen(JAVA_SYS_PATH)+1))
    {
        handle = FS_Open((U16*) filename, FS_CREATE_ALWAYS | FS_COMMITTED);
        if (handle > 0)
        {
            if (FS_Write(handle, (void*)record->storage_name, sizeof(record->storage_name), &byte) < 0)
            {           
                err_code = 1;  
                record->is_op_mids = KAL_FALSE;
            }
            else
            {
                record->is_op_mids = KAL_TRUE;                
            }
            FS_Close(handle);
        }
    }
    
    srv_java_appfactory_get_app_name_by_storage_name(app_name,record->storage_name);
    srv_java_appfactory_get_file_path(filename,app_name);

    handle = FS_Open((U16*) filename, FS_CREATE_ALWAYS | FS_COMMITTED);
    if (handle < 0)
    {
        if(handle == FS_PATH_NOT_FOUND )
        {
            srv_java_appfactory_get_factory_path(filename);
            FS_CreateDir(filename);
        }
        err_code = 2;
    }
    else
    {
        if (FS_Write(handle, (void*)record, sizeof(mmi_java_app_factory_record_struct), &byte) < 0)
        {           
            err_code = 3;  
        }
    }
    FS_Close(handle);
    FREE_FILE_NAME_BUFF(filename); 
    kal_trace(JAM_JAVAAGENCY_GROUP,SRV_JAVA_APPFACTORY_ADD_RECORD,err_code);
    return ((err_code == J2ME_NO_ERROR) ? MMI_RET_OK: MMI_RET_ERR);
}

/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_gen_file
* DESCRIPTION
*  Generate the app name storage name mapping file.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret srv_java_appfactory_gen_file(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;
    int idx;
   // int len = 0;
   // int remainder = 0;
    //int divider = 0;
    kal_uint32 count = 0;    
    kal_uint32 re_try_count = 0;
    char  storage_name[LEN] = {0};
    CHAR defaultl_app_name[MMI_APP_NAME_MAX_LEN] = {0};
    j2me_custom_file_info_struct *info_ptr = _jvm_get_builtin_file_info();
    mmi_java_app_factory_record_struct *record =NULL;
    kal_int32 handle = -1;
  //  kal_int32 error_code = J2ME_NO_ERROR;
    jam_getlist_filter_struct filter = {0};
    mids_list_info_struct *mids_info_ptr = NULL;
    WCHAR* filename;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return ret;
    }
#endif
    work_sys_dir_path = _jvm_get_dir_path();
    work_info_ptr = _jvm_get_builtin_file_info();
    record=(mmi_java_app_factory_record_struct*)get_ctrl_buffer(sizeof(mmi_java_app_factory_record_struct));
    memset(record, 0, sizeof(mmi_java_app_factory_record_struct));
    filename = GET_FILE_NAME_BUFF();
    count = info_ptr->default_mids_count;
    srv_java_appfactory_get_factory_path(filename);
    if((handle = FS_CreateDir(filename)) < FS_NO_ERROR)
    {
        if(handle == FS_FILE_EXISTS || handle == FS_PATH_NOT_FOUND)
        {
            FREE_FILE_NAME_BUFF(filename);
            free_ctrl_buffer(record);
            record=NULL;  
            return ret;
        }
        else
        {
            FREE_FILE_NAME_BUFF(filename);
            free_ctrl_buffer(record);
            record=NULL;  
            return MMI_RET_ERR;
        }
    }

    filter.filter_type = JAM_DEFAULT_GAME_FILTER;
#ifndef __COSMOS_MMI_PACKAGE__
     jam_call_back_functions.jam_get_list(
    0, JAVA_LIST_CACHE_COUNT, &saved_mids_listfile_ptr, &filter);
    if(saved_mids_listfile_ptr == NULL)
    {
        FREE_FILE_NAME_BUFF(filename);
        free_ctrl_buffer(record);
        record=NULL;  
        return MMI_RET_OK;
    }
    mids_info_ptr = saved_mids_listfile_ptr->mids_info_list;
#endif
    for(idx = 1;idx <= count; idx++)
    {
#ifdef __COSMOS_MMI_PACKAGE__
             jam_call_back_functions.jam_get_list(
            idx -1, JAVA_LIST_CACHE_COUNT, &saved_mids_listfile_ptr, &filter);
            if(saved_mids_listfile_ptr == NULL)
            {
                FREE_FILE_NAME_BUFF(filename);
                free_ctrl_buffer(record);
                record=NULL;  
                return MMI_RET_OK;
            }
            mids_info_ptr = saved_mids_listfile_ptr->mids_info_list;
#endif
            #if defined(__IJET_VM__)
        sprintf(storage_name, "%08d_\0", idx);
            #elif defined(__NEMO_VM__)
        sprintf(storage_name, "J%07d\0", idx);
            #endif
        memcpy(record->storage_name,storage_name,mmi_ucs2strlen(storage_name)<<1);
        srv_java_appfactory_get_app_name_by_storage_name(defaultl_app_name,storage_name);
       // memcpy(record->app_name,defaultl_app_name,MMI_APP_NAME_MAX_LEN-1);
        memcpy(record->mids_name,mids_info_ptr->mids_name,(MMI_APP_NAME_MAX_LEN-1)<<1);
        memcpy(record->mids_vendor,mids_info_ptr->mids_vendor,(MIDLET_VENDOR_LEN-1)<<1);
        record->is_default = KAL_TRUE;
        record->is_bg_enabled= KAL_TRUE;
        record->is_installed=KAL_TRUE;
#ifndef __COSMOS_MMI_PACKAGE__
        mids_info_ptr = mids_info_ptr->mids_list_info_next;
#endif
        while((ret = srv_java_appfactory_add_record(record)) != MMI_RET_OK)
        {
            re_try_count++;
            kal_sleep_task(10);
            if(re_try_count == 10)
            {
                FREE_FILE_NAME_BUFF(filename);
                free_ctrl_buffer(record);
                record=NULL;  
                return ret;
            }
        }
        if(ret!= MMI_RET_OK)
        {
            FREE_FILE_NAME_BUFF(filename);
            free_ctrl_buffer(record);
            record=NULL;  
            return ret;
        }
    }
    jam_call_back_functions.jam_free_list();
    FREE_FILE_NAME_BUFF(filename);
    free_ctrl_buffer(record);
    record=NULL;  
    //#ifndef __MMI_JAVA_PREINSTALL_TCARD_PACKAGE__
    //StartTimer(J2ME_APP_FACTORY_TIMER, 3 * 1000, (FuncPtr) srv_java_appfactory_timer_callback);     // modify by Zhiqing 2012-9-11;
    //#endif
    return MMI_RET_OK;
}


unify_srv_callback java_get_info_callback;
extern mmi_java_mids_getinfo_cnf_struct* mids_getinfo_cnf_msg;
void srv_java_appfactory_get_mids_info_cnf(void* para)
{
    if (mids_getinfo_cnf_msg->error_code != J2ME_NO_ERROR)
    {
        return;

    }
    java_app_info.mids_authorized = mids_getinfo_cnf_msg->mids_info.mids_authorized;
    if(mids_getinfo_cnf_msg->mids_info.mids_description!=NULL)
        java_app_info.mids_description = mids_getinfo_cnf_msg->mids_info.mids_description;
    else
         java_app_info.mids_description = NULL;
    if(mids_getinfo_cnf_msg->mids_info.mids_name!=NULL)
        java_app_info.mids_name = mids_getinfo_cnf_msg->mids_info.mids_name;
    else
       java_app_info.mids_name = NULL; 
    java_app_info.mids_size = mids_getinfo_cnf_msg->mids_info.mids_size;
    if(mids_getinfo_cnf_msg->mids_info.mids_vendor!=NULL)
        java_app_info.mids_vendor = mids_getinfo_cnf_msg->mids_info.mids_vendor;
    else
         java_app_info.mids_vendor = NULL;
    if(mids_getinfo_cnf_msg->mids_info.mids_version!=NULL)
        java_app_info.mids_version = mids_getinfo_cnf_msg->mids_info.mids_version;
    else
        java_app_info.mids_version = NULL;
    if(mids_getinfo_cnf_msg->mids_info.mids_webside!=NULL)
        java_app_info.mids_website = mids_getinfo_cnf_msg->mids_info.mids_webside;
    else
        java_app_info.mids_website = NULL;

}


/*****************************************************************************
* FUNCTION
*  srv_java_get_mids_info
* DESCRIPTION
*  Generate the app name storage name mapping file.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret srv_java_appfactory_get_mids_info(CHAR * app_name, java_info_struct** info)
{
    kal_char storage_name[STORAGE_LEN] = {0};
    mmi_ret ret  = MMI_RET_ERR;
    FS_FileInfo fileinfo;
    kal_int32 handle = -1;
	mmi_java_get_appmgr_info_req_struct *new_msg;
    kal_uint32 event_group;
    kal_int32 mids_id = -1;
    WCHAR * filename;
    if (jam_is_busy())   
    {
        return ret;
    }
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MIDS_GETINFO_REQ);
    filename = GET_FILE_NAME_BUFF();
    srv_java_appfactory_get_file_path(filename,app_name);

    //1. get java_app_info.install_time     'from JavaAppfactory/J0000001'
    handle = FS_Open((WCHAR*) filename, FS_READ_ONLY);
    if (handle < 0)
    {
        FS_Close(handle);
    }
    else
    {
        FS_GetFileInfo(handle, &fileinfo);
    }
    
    java_app_info.install_time.nYear = fileinfo.DirEntry->DateTime.Year1980+1980;
    java_app_info.install_time.nMonth = fileinfo.DirEntry->DateTime.Month;
    java_app_info.install_time.nDay = fileinfo.DirEntry->DateTime.Day;
    
    FS_Close(handle);

	
	//Prepare storage_name from appname, to be uesd.
    handle = FS_Open((U16*) filename, FS_READ_WRITE);
    if(handle == FS_FILE_NOT_FOUND)
    {
        FS_Close(handle);
        FREE_FILE_NAME_BUFF(filename);
        return MMI_RET_ERR;
    }
    else
    {
        FS_Close(handle);
        ret =srv_java_appfactory_get_storage_name_by_app_name(storage_name,app_name);
        ASSERT(ret != MMI_RET_ERR);
    }	
    
	//2.get java_app_info. icon_path
    srv_java_appfactory_get_app_icon_path(java_app_info.icon_path,storage_name);
    handle = FS_Open((WCHAR*) java_app_info.icon_path, FS_READ_ONLY);
    if (handle < 0)
    {
        memset(java_app_info.icon_path,0,_MAX_FILE_NAME_LENGTH);
        FS_Close(handle);
    }
    FS_Close(handle);

	

    //MY TEST.

	
	mids_id = jam_call_back_functions.jam_get_mids_id_from_storage_name(storage_name);
	if(mids_id < 0)
	{
		   kal_trace(JAM_JAVAAGENCY_GROUP, SRV_JAVA_APPFACTORY_GET_MIDS_INFO);
		   FREE_FILE_NAME_BUFF(filename);
		   return MMI_RET_ERR;
	}
    new_msg = (mmi_java_get_appmgr_info_req_struct*) OslConstructDataPtr(sizeof(mmi_java_get_appmgr_info_req_struct));
    new_msg->mids_id=mids_id;
	new_msg->mids_name=NULL;   //[Name]  java app package name
    new_msg->mids_size=0;   //[Size] java app size
    new_msg->mids_version=NULL; //[Version] java app version
    new_msg->mids_vendor=NULL; //[Vendor] java app vendor
    new_msg->mids_description=NULL; //[Description] java app description
    new_msg->mids_website=NULL; //[Website] java app download website
    new_msg->mids_authorized=KAL_FALSE; //[Connections] connections URL
    new_msg->can_be_uninstall=KAL_FALSE; //can be uninstall or not
    new_msg->can_be_update=KAL_FALSE; // can be update or not
    new_msg->storage_type=0; // can be update or not
    mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP,
    MSG_ID_MMI_JAVA_GET_APPMGR_INFO_REQ, new_msg);

    kal_retrieve_eg_events(g_java_event_group_2, JAVA_EG_GETLIST_3, KAL_OR_CONSUME, (kal_uint32*)&event_group, KAL_SUSPEND);

	//retrieve value
    java_app_info.mids_name=new_msg->mids_name;   //[Name]  java app package name
    java_app_info.mids_size=new_msg->mids_size;   //[Size] java app size
    java_app_info.mids_version=new_msg->mids_version; //[Version] java app version
    java_app_info.mids_vendor=new_msg->mids_vendor; //[Vendor] java app vendor
    java_app_info.mids_description=new_msg->mids_description; //[Description] java app description
    java_app_info.mids_website=new_msg->mids_website; //[Website] java app download website
    java_app_info.mids_authorized=new_msg->mids_authorized; //[Connections] connections URL
    java_app_info.can_be_uninstall=new_msg->can_be_uninstall;
	java_app_info.can_be_update=new_msg->can_be_update;
	java_app_info.storage_type=(kal_bool)new_msg->storage_type;
	*info = &java_app_info;

	if(filename){
		FREE_FILE_NAME_BUFF(filename);
	    filename=NULL;}
    return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  srv_java_get_mids_info
* DESCRIPTION
*  check can be update or not update
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_java_appfactory_check_update_app(CHAR * app_name, unify_srv_callback callback)
{
    callback(NULL, 0);
}


/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_is_app_exit
* DESCRIPTION
*  check the exixtence of the java app
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL srv_java_appfactory_is_app_exit(mmi_app_package_char * app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    kal_int32 handle = -1;
    WCHAR * filename = NULL;
    MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    filename = GET_FILE_NAME_BUFF();
    srv_java_appfactory_get_file_path(filename,app_name);
    handle = FS_Open((U16*) filename, FS_READ_ONLY);
    if(handle >= FS_NO_ERROR)
    {
        ret = MMI_TRUE;
    }
    FREE_FILE_NAME_BUFF(filename);
    FS_Close(handle);
    return ret;
}

/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_is_app_running
* DESCRIPTION
*  check whther the mids is running
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL srv_java_appfactory_is_app_running(mmi_app_package_char * app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    kal_char storage_name[STORAGE_LEN] = {0};
    kal_int32 vm_id = INVALIDE_VM_ID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    srv_java_appfactory_get_storage_name_by_app_name(storage_name,app_name);
    vm_id = jam_mvm_get_vm_id(storage_name,-1);
    if(jam_mvm_get_vm_state(vm_id)!= JVM_TERMINATE_STATE&&
        jam_mvm_get_vm_state(vm_id)!= JVM_TERMINATING_STATE)
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
*  srv_java_appfactory_remove_proc
* DESCRIPTION
*  Remove the record in appFactory by app_name
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret srv_java_appfactory_remove_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    kal_char appname[50] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->user_data)
    {
        sprintf(appname,"java.%s\0",(kal_char*) evt->user_data);
        free_ctrl_buffer(evt->user_data);
        srv_appmgr_update_app_info(appname, EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE);
    }
}

/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_remove_record
* DESCRIPTION
*  Remove the record in appFactory by app_name
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret srv_java_appfactory_remove_record(kal_char* storage_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    WCHAR * filename = NULL;
    kal_int32 handle = -1;
    kal_uint32 err_code = J2ME_NO_ERROR; 
    mmi_java_app_factory_record_struct *record = NULL;
    kal_uint32 byte = 0;
    kal_char app_name[50] = {0};
   // mmi_event_struct evt;
   // kal_char *mids_storage_name = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    record=(mmi_java_app_factory_record_struct*)get_ctrl_buffer(sizeof(mmi_java_app_factory_record_struct));
    memset(record, 0, sizeof(mmi_java_app_factory_record_struct));
    filename = GET_FILE_NAME_BUFF();
    srv_java_appfactory_get_file_path_by_storage_name(filename,storage_name);
    handle = FS_Open((U16*) filename, FS_READ_ONLY);
    if (handle < 0)
    {
        err_code = J2ME_FILE_NOT_FOUND;
    }
    else
    {
        if(FS_Read(handle, (void*)record, sizeof(mmi_java_app_factory_record_struct), &byte) < FS_NO_ERROR)
        {
            err_code = J2ME_ACTION_FAILE;
        }
    }
    FS_Close(handle);
    FS_Delete(filename);
    if(err_code == J2ME_NO_ERROR)
    {
        srv_java_appfactory_get_app_java_path(filename);
        app_ucs2_strcat((kal_int8 *) filename,(const kal_int8 *) record->mids_vendor);
        app_ucs2_strcat((kal_int8 *) filename,(const kal_int8 *)L".");
        app_ucs2_strcat((kal_int8 *) filename,(const kal_int8 *) record->mids_name);
        FS_Delete(filename);
    }
    FREE_FILE_NAME_BUFF(filename);
    free_ctrl_buffer(record);
    record=NULL;
    
    sprintf(app_name,"java.%s\0",storage_name);
    srv_appmgr_update_app_info(app_name, EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE);

    return MMI_RET_OK;
}

mmi_ret srv_java_appfactory_remove_all_records(void)
{ 
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/   
    WCHAR * folder;
    kal_int32 handle = -1;
    mmi_ret ret = MMI_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    folder = GET_FILE_NAME_BUFF();
    srv_java_appfactory_get_factory_path(folder);
    FS_XDelete(folder, FS_FILE_TYPE | FS_DIR_TYPE | FS_RECURSIVE_TYPE, NULL, 0);
    if((handle = FS_RemoveDir(folder)) < FS_NO_ERROR)
    {
        kal_trace(JAM_JAVAAGENCY_GROUP, SRV_JAVA_APPFACTORY_REMOVE_ALL_RECORDS,handle);
        if( handle == FS_PATH_NOT_FOUND)
            ret = MMI_RET_OK;
        else
            ret = MMI_RET_ERR;
    }
    FREE_FILE_NAME_BUFF(folder);
    return ret;
}


kal_bool srv_java_appfactory_is_busy(void)
{
    return (kal_bool)(jam_is_busy()||jam_mvm_is_shutdowning());
}

extern mmi_java_cmd_enum g_mmi_java_current_running_cmd;

srv_appmgr_uninstall_cb srv_java_app_factory_delete_callabck = NULL;
void * srv_java_app_factory_delete_callabck_user_data = NULL;
void srv_java_app_factory_mids_del_notify(kal_int32 error_code,kal_char* storage_name)
{
    if (error_code == J2ME_NO_ERROR)
    { 
        kal_char appname[50] = {0};
        sprintf(appname,"java.%s\0",storage_name);
        if(srv_java_app_factory_delete_callabck)
        {
            srv_java_app_factory_delete_callabck(SRV_APPMGR_CB_EVENT_DONE, srv_java_app_factory_delete_callabck_user_data);            
        }
        //srv_appmgr_update_app_info(appname, EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE);
    }
    else
    {
        if(srv_java_app_factory_delete_callabck)
        {
            srv_java_app_factory_delete_callabck(SRV_APPMGR_CB_EVENT_ERROR, srv_java_app_factory_delete_callabck_user_data);           
        }           
    }
    srv_java_app_factory_delete_callabck = NULL;
}

mmi_ret srv_java_appfactory_delete(CHAR* app_name, srv_appmgr_uninstall_cb callback, void * user_data)
{
    kal_int32 ret = J2ME_NO_ERROR;
    kal_char storage_name[STORAGE_LEN] = {0};
    srv_java_appfactory_get_storage_name_by_app_name(storage_name,app_name);

    srv_java_app_factory_delete_callabck = callback;
    srv_java_app_factory_delete_callabck_user_data = user_data;
    g_mmi_java_is_background_display = MMI_FALSE;
    g_mmi_java_current_running_cmd = MMI_JAVA_CMD_REMOVE_BY_USER;
#ifdef __OP01__
    ret = mmi_java_mids_delete(-1,storage_name,KAL_TRUE);
#else
    ret= mmi_java_mids_delete(-1,storage_name,KAL_FALSE);
#endif
    if(ret!=J2ME_NO_ERROR)
    {
        callback(SRV_APPMGR_CB_EVENT_ERROR, user_data);
    }
    return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION 
* srv_java_appfactory_get_preinstall_mids_path
* DESCRIPTION
* 
* PARAMETERS
* kal_char * app_name
* WCHAR* mids_jar_path 
* WCHAR* mids_jad_path 
* RETURNS 
* kal_bool 
*modify/add date: 2012-9-05
*modify/add time: 11:20:20
*****************************************************************************/
kal_bool srv_java_appfactory_get_preinstall_mids_path(WCHAR*mids_jad_path,WCHAR* mids_jar_path,kal_bool * is_installed,kal_char * app_name)
{
         // modify by Zhiqing 2012-9-05;
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR * wapp_name;
    mmi_java_app_factory_record_struct *record = NULL;     
    kal_int8 jar_path_len=0;
    mmi_ret ret = MMI_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(J2ME_SLIM_MEMORY_SUPPORT)
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR)
    {
        return KAL_FALSE;
    }
#endif
    if(NULL==app_name)
    {
        return KAL_FALSE;
    }
    record=(mmi_java_app_factory_record_struct*)get_ctrl_buffer(sizeof(mmi_java_app_factory_record_struct));
    memset(record, 0, sizeof(mmi_java_app_factory_record_struct));
    wapp_name = GET_FILE_NAME_BUFF();
    kal_wsprintf(wapp_name,"%s\0",app_name);
    ret = srv_java_appfactory_get_record(wapp_name,record);
    FREE_FILE_NAME_BUFF(wapp_name);
    if(MMI_OK == ret)
    {
        (*is_installed)=record->is_installed;

        mmi_ucs2cpy((S8*)mids_jar_path, (S8*)record->install_path);
        jar_path_len=mmi_wcslen(mids_jar_path);
    
        if(jar_path_len>0)
        {
        /*get jad file */
           
            mmi_ucs2cpy((S8*)mids_jad_path, (S8*)mids_jar_path);
        
            if(mids_jad_path[jar_path_len - 2]=='a')
            {   
                mids_jad_path[jar_path_len - 1] = 'd';      
            }
            else
            {                        
                mids_jad_path[jar_path_len - 1] = 'D';  
            } 
        
            if(FS_GetAttributes((WCHAR*) mids_jad_path) < FS_NO_ERROR) 
            {
                 memset(mids_jad_path,0,sizeof(WCHAR) * MIDLET_INSTALL_PATH_LEN);
            }
        }
        else
        {
            memset(mids_jar_path,0,sizeof(WCHAR) * MIDLET_INSTALL_PATH_LEN);
            free_ctrl_buffer(record);
            record=NULL;
            return KAL_FALSE;
        }
        free_ctrl_buffer(record);
        record=NULL;     
        return KAL_TRUE;
    }
}


/*****************************************************************************
* FUNCTION 
* srv_java_appfactory_preinstall_mids_install
* DESCRIPTION
* 
* PARAMETERS
* kal_char * app_name
* RETURNS 
* kal_bool 
*modify/add date: 2012-9-06
*modify/add time: 11:40:2
*****************************************************************************/
void srv_java_appfactory_preinstall_mids_install(kal_char * app_name)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR* mids_jad_path=NULL;
    WCHAR* mids_jar_path=NULL;
    kal_bool is_installed=KAL_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    mids_jar_path=(WCHAR*)get_ctrl_buffer(sizeof(WCHAR) * MIDLET_INSTALL_PATH_LEN);
    mids_jad_path=(WCHAR*)get_ctrl_buffer(sizeof(WCHAR) * MIDLET_INSTALL_PATH_LEN);
    memset(mids_jar_path, 0, sizeof(WCHAR) * MIDLET_INSTALL_PATH_LEN);
    memset(mids_jad_path, 0, sizeof(WCHAR) * MIDLET_INSTALL_PATH_LEN);

    srv_java_appfactory_get_preinstall_mids_path(mids_jad_path,mids_jar_path,&is_installed,app_name);
    
    if(!is_installed)
    {
        if(0<mmi_wcslen(mids_jad_path))     
	    {
	        g_mmi_java_is_background_display=KAL_FALSE;
		    mmi_java_mids_install(mids_jad_path,NULL,L"file://", KAL_FALSE);
	    }else
	    {
	         g_mmi_java_is_background_display=KAL_FALSE;
		     mmi_java_mids_install(NULL,mids_jar_path,L"file://", KAL_FALSE);
	    }     
    }
    else
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,SRV_JAVA_APPFACTORY_LAUNCH_3);
    #ifdef __PLUTO_MMI_PACKAGE__
        mmi_popup_display_simple_ext(STR_GLOBAL_FILE_NOT_FOUND, MMI_EVENT_FAILURE, GRP_ID_ROOT, NULL);
    #endif
    }
    if(mids_jar_path)
    {
        free_ctrl_buffer(mids_jar_path);
        mids_jar_path=NULL;
    }
    if(mids_jad_path)
    {
        free_ctrl_buffer(mids_jad_path); 
        mids_jad_path=NULL;
    }
}

/*****************************************************************************
* FUNCTION 
* srv_java_appfactory_mids_is_default
* DESCRIPTION
* 
* PARAMETERS
* kal_char * app_name
* RETURNS 
* kal_bool 
*modify/add date: 2012-9-07
*modify/add time: 20:49:17
*****************************************************************************/
kal_bool srv_java_appfactory_mids_is_default(kal_char * storage_name)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR * wapp_name;
    mmi_java_app_factory_record_struct *record = NULL; 
    kal_bool is_default=KAL_FALSE;
    mmi_ret ret = MMI_OK;
    CHAR app_name[STORAGE_LEN+10] = {0}; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_java_appfactory_get_app_name_by_storage_name(app_name,storage_name);
    record=(mmi_java_app_factory_record_struct*)get_ctrl_buffer(sizeof(mmi_java_app_factory_record_struct));
    memset(record, 0, sizeof(mmi_java_app_factory_record_struct));
    wapp_name = GET_FILE_NAME_BUFF();
    kal_wsprintf(wapp_name,"%s\0",app_name);
    ret = srv_java_appfactory_get_record(wapp_name,record);
    FREE_FILE_NAME_BUFF(wapp_name);
    if(MMI_OK == ret)
    {
       is_default=record->is_default;
    }
    else
    {
        is_default=KAL_FALSE;
    }
    free_ctrl_buffer(record);
    return is_default;
}
#endif
