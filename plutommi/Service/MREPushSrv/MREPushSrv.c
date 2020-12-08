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
*  MREPushSrv.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  MRE Push Service implement file.
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
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
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
* Include
****************************************************************************/
#include "MMI_features.h"
#include "vmswitch.h" 
//remove  __MRE_SAL_PN__ to below for srv_mre_appmgr_bootup_hdlr() and srv_mre_push_event_hdlr() should always exists
#include "vmcert.h"
#include "vmgettag.h"
#include "PnSrvGprot.h"
#include "liblist.h"
#include "AMUtil.h"
#include "liblist.h"
#include <string.h>
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "vmresmng.h"
#include "MREAppMgrSrvGprot.h"
#include "Conversions.h"
#include "MMIDataType.h"
//#include "vmgettag.h"
//#include "vmcert.h"
#include "vm4res.h"
#include "vmpn.h"
#include "MRESrvGProt.h"
#include "NotificationSettingSrvGprot.h"
#include "NotificationGprot.h"

#include "FileMgrSrvGProt.h"
#include "mmi_rp_app_usbsrv_def.h"
#include "MREPushSrvProt.h"
#include "app_str.h"


MMI_BOOL mre_push_usb_ms_mode = MMI_FALSE;
MMI_BOOL mre_push_dev_plug_out = MMI_FALSE;
#ifdef  __MMI_MRE_PREINSTALL_TCARD_PACKAGE__
extern srv_mre_appmgr_t_card_install_strut g_mre_appmgr_restore_factory_mode;
extern MMI_BOOL mmi_mre_appmgr_parse_init(MMI_BOOL flag);
#endif


#ifdef __MRE_SAL_PN__

srv_mre_appmgr_push_payload_ram_struct  push_cache;    /*for the push payload*/
extern srv_mre_appmgr_map_table g_mre_appmgr_maptable[];
extern S32 vm_send_system_message(VM_P_HANDLE handle,S32 msg, S32 param);
#ifdef __MMI_NCENTER_SUPPORT__
extern S32 vm_ncenter_push_delete_message(U32 app_id, U32 index);
extern S32 vm_ncenter_push_new_message(U32 app_id, U32 unique_appid,U32 index) ;
#endif//__MMI_NCENTER_SUPPORT__
static void srv_mre_appmgr_push_defer_notification(MMI_BOOL flag);
#ifdef __LOW_COST_SUPPORT_COMMON__
extern U32  srv_mre_appmgr_get_avaible_unique_id(U16 *app_name,U16 app_type,U16 flag,U16 *appname0,U16 * appname1, U16 *rom_path,U16 badge,U32 app_id);
#else
extern U32  srv_mre_appmgr_get_avaible_unique_id(U16 *app_name,U16 app_type,U16 flag,U16 *appname0,U16 * appname1,U16 * appname2, U16 *rom_path,U16 badge,U32 app_id);
#endif
mmi_ret srv_mre_push_receiver_set_badge_number(U32 appId,U32 badge);
mmi_ret srv_mre_push_receiver_uninstall(WCHAR *app_name);
mmi_ret srv_mre_push_receiver_app_handler(srv_mre_mpr_app_handle_event event,U32 appId,char* senderId, mmi_proc_func cb, void* user_data);
mmi_ret srv_mre_push_receiver_pns_query(vm_srv_pns_query_event event,int AppID,void* userdata);
mmi_ret srv_mre_push_receiver_pns_callback(mmi_event_struct *param);
mmi_ret srv_mre_push_receiver_pns_register(U32 appId,char* senderId, mmi_proc_func cb, void* user_data);
mmi_ret srv_mre_push_receiver_pns_deregister(U32 appId);
mmi_ret srv_mre_push_receiver_broadcast_receiver(mmi_event_struct *param);
extern mmi_ret srv_mre_appmgr_get_push_app_list(srv_mre_appmgr_push_installed_info_struct *name_array, U32 num);
extern mmi_ret vm_pn_proc(mmi_event_struct *param, void * user_data);
extern U32 srv_mre_appmgr_get_push_app_num(void);
extern mmi_ret srv_mre_push_receiver_install_app(U16 *app_path,srv_mre_appmgr_app_type_enum app_type,mmi_app_package_char *app_name,U32 app_unique_id);
MMI_BOOL srv_mre_appmgr_get_push_installed_info(U16 *app_name, srv_mre_appmgr_push_installed_info_struct *info);
mmi_ret srv_mre_push_receiver_file_read(U32 AppId,srv_mre_appmgr_push_installed_info_struct* read_info,MMI_BOOL flag);
mmi_ret srv_mre_push_receiver_file_write(U32 AppId,srv_mre_appmgr_push_installed_info_struct* write_info,MMI_BOOL flag);
mmi_ret srv_mre_push_receiver_is_have_register_id(U32 AppID,char *RegID);
mmi_ret srv_mre_push_receiver_call_user_func(U32 AppID,mmi_event_struct *Param);
extern VM_PROCESS_STATUS srv_mre_check_app_status_by_name(U16 *name);
#endif //__MRE_SAL_PN__


mmi_ret srv_mre_appmgr_bootup_hdlr(mmi_event_struct *evt)
{
#ifdef __MRE_SAL_PN__
    srv_mre_appmgr_push_defer_notification(MMI_FALSE);
#endif
    return MMI_RET_OK;
}
/*****************************************************************************
* FUNCTION
*  srv_mre_push_event_hdlr
* DESCRIPTION
*  This function is to handle callback events from callback manager.
* PARAMETERS
*  event           : [IN]      Event
* RETURNS
*  mmi_ret
*****************************************************************************/
mmi_ret srv_mre_push_event_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                          usb_ms_mode;
    extern MMI_BOOL dev_plug_in;                            */
    /*----------------------------------------------------------------*/
    switch (event->evt_id)
    {
    case EVT_ID_USB_ENTER_MS_MODE:
        mre_push_usb_ms_mode = MMI_TRUE;
        break;
    case EVT_ID_USB_EXIT_MS_MODE:
        mre_push_usb_ms_mode = MMI_FALSE;
#ifdef __MRE_SAL_PN__
        srv_mre_appmgr_push_defer_notification(MMI_TRUE);
#endif
        break;
    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        mre_push_dev_plug_out = MMI_FALSE;
#ifdef __MRE_SAL_PN__
        srv_mre_appmgr_push_defer_notification(MMI_TRUE);
#endif
#ifdef __MMI_MRE_PREINSTALL_TCARD_PACKAGE__
        if(g_mre_appmgr_restore_factory_mode.t_card_has_install==0)
        {
            mmi_mre_appmgr_parse_init(MMI_FALSE);
        }
#endif
        break;
    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        mre_push_dev_plug_out = MMI_TRUE;
        break;
    default:
        break;
    }

    return ret;
}



#ifdef __MRE_SAL_PN__

#ifdef __MMI_NSS_SUPPORT__
void srv_mre_appmgr_listen_setting_change(U16 app_id, U32 changed_setting, U16* alias_id)
{
	#ifndef __MMI_MRE_DISABLE_FMGR__
    if(changed_setting & NSS_MASK_BADGE_ICON)
    {
        S16 index = app_id - SRV_MRE_APPMGR_ID_BASE;
        if(index>=0&&index<SRV_MRE_APPMGR_INSTALLED_APP_MAX&&g_mre_appmgr_maptable[index].unique_appid)
            srv_appmgr_update_app_info((mmi_app_package_char*)((g_mre_appmgr_maptable[index].app_install_name)),EVT_ID_SRV_APPMGR_UPDATE_BADGE);	
    }
  #endif
}
#endif

//0: bootup; 1:defer
static void srv_mre_appmgr_push_defer_notification(MMI_BOOL flag)
{			
    U32 push_num = 0;
    U16 filename[SRV_MRE_APPMGR_PATH_SIZE];
    U16 app_name_w[MMI_APP_NAME_MAX_LEN];
    CHAR  app_name[MMI_APP_NAME_MAX_LEN];
    S32 	search_hdl = -1;
    S32 	search_ret	= FS_NO_ERROR;
    FS_DOSDirEntry de;
    U32 i = 0,j = 0;
    mmi_mpr_popup_message_struct *mpsPtr = NULL;
    MMI_BOOL show_ncenter = MMI_FALSE;
#ifdef __MMI_NSS_SUPPORT__
    U16 setting_value = 0;
#endif
    srv_mre_appmgr_push_installed_info_struct push_installed_info;

    push_num = srv_mre_appmgr_get_push_app_num();
    //mmi_wcscpy(filename, SRV_MRE_APPMGR_PUSH_FOLDER);
    //mmi_wcscat(filename, L"*");
    kal_wsprintf(filename,"z:\\@mre\\push\\*");
    search_hdl = FS_FindFirst(filename, 0, FS_ATTR_DIR, &de, app_name_w, MMI_APP_NAME_MAX_LEN*2);
    if (search_hdl >= 0)
    {
        for(;i<push_num;i++)
        {
            if((search_ret >= FS_NO_ERROR)&&srv_mre_appmgr_get_push_installed_info(app_name_w, &push_installed_info)&& (NULL !=push_installed_info.app_path))
            {
                //#ifdef __MMI_APP_MANAGER_SUPPORT__
                //mmi_chset_convert(MMI_CHSET_UCS2,MMI_CHSET_UTF8,(char*)(push_installed_info.app_install_name),(char*)app_name,sizeof(app_name));
                //srv_appmgr_update_app_info((mmi_app_package_char*)app_name,EVT_ID_SRV_APPMGR_UPDATE_BADGE);
                //#endif
                //for n-center
                U32 defer = 1;
                if(flag)
                    defer = push_installed_info.defer_notification;
                if(defer)
                {
#ifdef __MMI_NCENTER_SUPPORT__
#ifdef __MMI_NSS_SUPPORT__

                    mmi_srv_nss_get_setting(push_installed_info.app_unique_id,NSS_SETTING_NCENTER,&setting_value);
                    if(setting_value==SETTING_ON)
                    {
#endif//__MMI_NSS_SUPPORT__
                        srv_mre_push_receiver_file_read(push_installed_info.app_id,&push_installed_info,MMI_TRUE);
                        if((push_cache.app_id==push_installed_info.app_id)&&(push_cache.app_payload.payload_count>0))
                        {
                            mpsPtr = (mmi_mpr_popup_message_struct*)OslMalloc(sizeof(mmi_mpr_popup_message_struct));
                            for(j=0;j<push_cache.app_payload.payload_count;j++)
                            {
                                //show status icon bar
                                memset(mpsPtr,0,sizeof(mmi_mpr_popup_message_struct));
                                if(srv_pns_get_mps_info((char *)(push_cache.app_payload.multiple_payload[j].payload), &mpsPtr->pns_msg_mps) == SRV_PNS_NO_ERROR)
                                {
                                    if(mpsPtr->pns_msg_mps.mainLen != 0 || mpsPtr->pns_msg_mps.mainResId != 0)
                                    {
                                        vm_ncenter_push_new_message(push_cache.app_id,push_installed_info.app_unique_id, push_cache.app_payload.multiple_payload[j].query_index);
                                        show_ncenter = MMI_TRUE;
                                    }
                                }
                            }
                            //mpsPtr = (mmi_mpr_popup_message_struct*)OslMalloc(sizeof(mmi_mpr_popup_message_struct));
                            memset(mpsPtr,0,sizeof(mmi_mpr_popup_message_struct));
                            if (srv_pns_get_mps_info((char *)(push_cache.app_payload.multiple_payload[j-1].payload), &mpsPtr->pns_msg_mps) != SRV_PNS_NO_ERROR)
                            {
                                mpsPtr->pns_msg_mps.icon = 0;
                            }
                            if(show_ncenter)
                            {
                                srv_mre_push_receiver_show_status_icon_only(push_installed_info.app_unique_id, push_installed_info.app_path,push_installed_info.app_install_name,mpsPtr->pns_msg_mps.icon);
                            }
                            if (mpsPtr) OslMfree(mpsPtr);
                        }
#ifdef __MMI_NSS_SUPPORT__
                    }
#endif //__MMI_NSS_SUPPORT__
#endif // __MMI_NCENTER_SUPPORT__
                    //for n-center
                    if(flag)
                    {
                        mmi_chset_convert(MMI_CHSET_UCS2,MMI_CHSET_UTF8,(char*)(push_installed_info.app_install_name),(char*)app_name,sizeof(app_name));
                        srv_appmgr_update_app_info((mmi_app_package_char*)app_name,EVT_ID_SRV_APPMGR_UPDATE_BADGE);
                        push_installed_info.defer_notification=0;
                        srv_mre_push_receiver_file_write(push_installed_info.app_id,&push_installed_info,MMI_FALSE);
                    }
                }
                search_ret =  FS_FindNext(search_hdl, &de, app_name_w, MMI_APP_NAME_MAX_LEN * 2);
            }
        }
        FS_FindClose(search_hdl);
    }
}

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_installed_info
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info            [OUT]     
* RETURNS
*  
*****************************************************************************/
MMI_BOOL srv_mre_appmgr_get_push_installed_info(
    U16 *app_name,
    srv_mre_appmgr_push_installed_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    WCHAR push_info_path[SRV_MRE_APPMGR_PATH_SIZE];
    FS_HANDLE file_hdl;
    U32 read;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (info == NULL)
    {
        return MMI_FALSE;
    }

    //mmi_wcscpy(push_info_path, SRV_MRE_APPMGR_PUSH_FOLDER);
    // mmi_wcscat(push_info_path, (const WCHAR*)app_name);
    kal_wsprintf(push_info_path,"z:\\@mre\\push\\%w",app_name);
    file_hdl = FS_Open(push_info_path, FS_OPEN_NO_DIR | FS_READ_ONLY);
    if (file_hdl >= FS_NO_ERROR)
    {
        if ((FS_Read(file_hdl, info, sizeof(srv_mre_appmgr_push_installed_info_struct), &read) >= FS_NO_ERROR) &&
            (read == sizeof(srv_mre_appmgr_push_installed_info_struct)))
        {
            ret = MMI_TRUE;
        }
        FS_Close(file_hdl);
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
void srv_mre_push_receiver_file_itoa(U32 appId,CHAR* buffer)
{
    if(NULL != buffer)
    {
        app_ucs2_itoa(appId,(signed char *)buffer,10);
    }
}


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
mmi_ret srv_mre_push_receiver_file_is_exist(U32 AppID)
{
    CHAR buffer[MAX_PUSH_APP_ITOA_NAME_LENGTH*2];
    WCHAR 	push_path[SRV_MRE_APPMGR_PATH_SIZE];	

    S32 search_hdl = -1;

    srv_mre_push_receiver_file_itoa(AppID,buffer);

    //mmi_wcscpy(push_path, SRV_MRE_APPMGR_PUSH_FOLDER);
    //mmi_wcscat(push_path, (const WCHAR*)temp_file_name);
    kal_wsprintf(push_path,"z:\\@mre\\push\\%w",buffer);

    search_hdl = FS_Open(push_path, FS_READ_ONLY);
    if (search_hdl >= 0)
    { 
        FS_Close(search_hdl);
        return SRV_MRE_PUHS_TYPE_FILE_EXIT;
    }

    return SRV_MRE_PUHS_TYPE_FILE_NOT_EXIT;
}


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
mmi_ret srv_mre_push_receiver_file_read(U32 AppId,srv_mre_appmgr_push_installed_info_struct* read_info,MMI_BOOL flag)
{
    U32 		read	= 0;
    FS_HANDLE 	fd 		= -1;
    CHAR 		buffer[MAX_PUSH_APP_ITOA_NAME_LENGTH*2];

    WCHAR 		push_path[SRV_MRE_APPMGR_PATH_SIZE];
    int 		ret = SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;

    srv_mre_push_receiver_file_itoa(AppId,buffer);

    //mmi_wcscpy(push_path, SRV_MRE_APPMGR_PUSH_FOLDER);
    //mmi_wcscat(push_path, (const WCHAR*)buffer);
    kal_wsprintf(push_path,"z:\\@mre\\push\\%w",buffer);

    // read file.
    fd = FS_Open((U16*)push_path, FS_READ_ONLY);
    if (fd >= FS_NO_ERROR)
    {
        if(read_info)
        {
            memset(read_info,0,sizeof(srv_mre_appmgr_push_installed_info_struct));
            if ((FS_Read(fd, read_info, sizeof(srv_mre_appmgr_push_installed_info_struct), &read) >= FS_NO_ERROR)
                &&(read == sizeof(srv_mre_appmgr_push_installed_info_struct)))
            {
                ret = SRV_MRE_PUHS_TYPE_SUCCESS;
            }
        }
        if(flag == MMI_TRUE&&(push_cache.app_id!=AppId))
        {
            FS_Seek(fd,-4,FS_FILE_CURRENT);
            memset(&push_cache,0,sizeof(srv_mre_appmgr_push_payload_ram_struct));
            if ((FS_Read(fd, &push_cache, sizeof(srv_mre_appmgr_push_payload_ram_struct), &read) >= FS_NO_ERROR)
                &&(read == sizeof(srv_mre_appmgr_push_payload_ram_struct)))
            { 
                ret = SRV_MRE_PUHS_TYPE_SUCCESS;
            }
        }

        FS_Close(fd);
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
mmi_ret srv_mre_push_receiver_file_write(U32 AppId,srv_mre_appmgr_push_installed_info_struct* write_info,MMI_BOOL flag)
{
    U32 		push_size_written 	= 0;	
    int 		ret1 					= -1;	
    FS_HANDLE push_hdl				= -1;
    int 		del_ret 				= FS_NO_ERROR ;
    mmi_ret 	ret						= SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;	
    mmi_ret	FileExist 				= SRV_MRE_PUHS_TYPE_FILE_NOT_EXIT;
    CHAR 		buffer[MAX_PUSH_APP_ITOA_NAME_LENGTH*2];	
    WCHAR 		push_path[SRV_MRE_APPMGR_PATH_SIZE];

    // 
    srv_mre_push_receiver_file_itoa(AppId,buffer);

    //mmi_wcscpy(push_path, SRV_MRE_APPMGR_PUSH_FOLDER);
    //mmi_wcscat(push_path, (const WCHAR*)buffer);
    kal_wsprintf(push_path,"z:\\@mre\\push\\%w",buffer);

    FileExist = srv_mre_push_receiver_file_is_exist(AppId);

    if(SRV_MRE_PUHS_TYPE_FILE_NOT_EXIT == FileExist){
        del_ret = FS_Delete(push_path);//delete old file
        if(FS_NO_ERROR == del_ret)
            return MMI_FALSE;
    }		

    push_hdl = FS_Open(push_path, FS_CREATE_ALWAYS | FS_READ_WRITE);

    if (push_hdl >= FS_NO_ERROR)
    {
        ret1 = -1;			
        ret1 =	FS_Write(push_hdl, write_info, sizeof(srv_mre_appmgr_push_installed_info_struct),&push_size_written);
        if (ret1 >= FS_NO_ERROR)
        {
            ret = SRV_MRE_PUHS_TYPE_SUCCESS;
        }
        else
        {
            ret = SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;
        }
        if(flag==MMI_TRUE&&(push_cache.app_id==AppId)&&ret1>=FS_NO_ERROR)
        {
            ret1 = FS_Write(push_hdl,&(push_cache.app_payload),sizeof(srv_mre_appmgr_push_multiple_payload_struct),&push_size_written);
            if(ret1<FS_NO_ERROR)
                ret1 = SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;
        }
        FS_Close(push_hdl);
    }			

    return ret;
}

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
mmi_ret srv_mre_push_receiver_broadcast_receiver(mmi_event_struct *param)
{
    U32 		i 					= 0;
    int 		push_app_num 		= -1;	
    S32 		search_hdl 		= -1;
    S32 		search_ret 		= FS_NO_ERROR;
    //mmi_ret 	ret = SRV_MRE_PUHS_TYPE_SUCCESS;
    WCHAR 		filename[SRV_MRE_APPMGR_PATH_SIZE];
    WCHAR 		app_name_w[MMI_APP_NAME_MAX_LEN];

    FS_DOSDirEntry de;
    srv_mre_appmgr_push_installed_info_struct name_array;	

    memset(&name_array,0,sizeof(srv_mre_appmgr_push_installed_info_struct));
    //memset(&de,0,sizeof(FS_DOSDirEntry));

    if (EVT_ID_SRV_PNS_START_REGISTER == param->evt_id)
    {
        push_app_num = srv_mre_appmgr_get_push_app_num();

        /* Build pattern */
        //mmi_wcscpy(filename, SRV_MRE_APPMGR_PUSH_FOLDER);
        //mmi_wcscat(filename, L"*");
        kal_wsprintf(filename,"z:\\@mre\\push\\*");
        search_hdl = FS_FindFirst(filename, 0, FS_ATTR_DIR, &de, app_name_w, MMI_APP_NAME_MAX_LEN*2);
        if (search_hdl >= 0)
        {
            for (; i < push_app_num;i++)
            {
                if (search_ret==FS_NO_ERROR&&srv_mre_appmgr_get_push_installed_info(app_name_w, &name_array) && (NULL !=name_array.app_path))
                { 
                    char senderID[MAX_PUSH_SENDER_ID_LENGTH]= {0};
                    mmi_ret GetRegIdRet 	= SRV_PNS_ERR_TOTAL;
                    char RegID[MAX_PUSH_REGISTER_ID_LENGTH] = {L'0'};
                    GetRegIdRet = srv_mre_push_receiver_is_have_register_id(name_array.app_id,RegID);
                    if(SRV_PNS_NO_ERROR == GetRegIdRet) //when have reg id, can broadcast
                    {
                        mmi_chset_convert(MMI_CHSET_UCS2,MMI_CHSET_UTF8,(char*)name_array.SenderID,(char*)senderID,sizeof(senderID));
                        srv_mre_push_receiver_pns_register(name_array.app_id,senderID,NULL,NULL);
                    }
                }
                search_ret = FS_FindNext(search_hdl, &de, app_name_w, MMI_APP_NAME_MAX_LEN*2);
            }
        }
        FS_FindClose(search_hdl);
        return SRV_MRE_PUHS_TYPE_SUCCESS;
    }
    return SRV_MRE_PUHS_TYPE_SUCCESS;
}

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
mmi_ret srv_mre_push_receiver_install_app(U16 *app_path,srv_mre_appmgr_app_type_enum app_type,mmi_app_package_char *app_name,U32 app_unique_id)
{
    WCHAR push_path[SRV_MRE_APPMGR_PATH_SIZE];	
    srv_mre_appmgr_push_payload_info_struct* push_installed_info;
    U32 			appId = 0;
    VMUINT			is_support_push=0;
    VMINT			bufSize = 4;
    S32 			app_id_buf_size = 26;
    int 			*sender_id_buf = NULL;
    S32 			sender_id_buf_size = ((MAX_PUSH_REGISTER_ID_LENGTH)*sizeof(char));			
    FS_HANDLE 		push_hdl = -1;
    U32 			push_size_written;	
    mmi_ret 		ret = SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;
    //char			*p =NULL;
    CHAR 			temp_file_name[MAX_PUSH_APP_ITOA_NAME_LENGTH*2];
    U16 			temp_app_name[MMI_APP_NAME_MAX_LEN];
    FS_HANDLE    image_hdl = -1,image_crt_hdl = -1;


    push_installed_info = (srv_mre_appmgr_push_payload_info_struct*) vm_malloc(sizeof(srv_mre_appmgr_push_payload_info_struct));
    if (NULL == push_installed_info)
    {
        srv_mre_unload_core(SRV_MRE_CALLER_AM);
        return SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;
    }

    memset(push_installed_info,0,sizeof(srv_mre_appmgr_push_payload_info_struct));

    // 1.get app file path
    if (NULL == (sender_id_buf = vm_malloc((MAX_PUSH_REGISTER_ID_LENGTH) * sizeof(VMWCHAR)))){
        return SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;
    }

    // 2.read tag.
    if (vm_get_vm_tag((short *)app_path, VM_CE_INFO_PUSH, &is_support_push, &bufSize) == GET_TAG_TRUE && is_support_push == 1)
    {
        if(GET_TAG_TRUE == vm_get_vm_tag((short *)app_path, VM_CE_INFO_PUSH_APPID, &appId, &app_id_buf_size))
        {
            ret = SRV_MRE_PUHS_TYPE_SUCCESS;
        }
        if(GET_TAG_TRUE == vm_get_vm_tag((short *)app_path, VM_CE_INFO_PUSH_SENDERID, sender_id_buf, &sender_id_buf_size))
        {
            ret = SRV_MRE_PUHS_TYPE_SUCCESS;
        }

        srv_mre_push_receiver_file_itoa(appId,temp_file_name);

        //memset(temp_app_name,0,sizeof(temp_app_name));
        if (!srv_mre_appmgr_generate_identification(app_path, temp_app_name))
        {
            vm_free(sender_id_buf);	
            vm_free(push_installed_info);
            return SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;
        }

        // copy info
        push_installed_info->app_id = appId;
        push_installed_info->style  = VM_SRV_MRE_MPR_NOTIFY_STYLE_POPUP | VM_SRV_MRE_MPR_NOTIFY_ON;
        mmi_wcscpy(push_installed_info->SenderID, (const WCHAR*)sender_id_buf); 		
        mmi_wcscpy(push_installed_info->app_install_name, (const WCHAR*)temp_app_name);
        mmi_wcscpy(push_installed_info->app_path, app_path);
        push_installed_info->app_unique_id = app_unique_id;
        push_installed_info->defer_notification = 0;


        //mmi_wcscpy(push_path, SRV_MRE_APPMGR_PUSH_FOLDER);
        //mmi_wcscat(push_path, (const WCHAR*)temp_file_name);
        kal_wsprintf(push_path,"z:\\@mre\\push\\%w",(const WCHAR*)temp_file_name);
        push_hdl = FS_Open(push_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
        if (push_hdl >= FS_NO_ERROR)
        {
            int ret1 = -1;
            ret1 =	FS_Write(push_hdl, push_installed_info, sizeof(srv_mre_appmgr_push_payload_info_struct),&push_size_written);
            if (ret1 >= FS_NO_ERROR){
                ret = SRV_MRE_PUHS_TYPE_SUCCESS;
            }
            else{
                ret = SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;
            }
            FS_Close(push_hdl); 
        }
        else
        {
            // push_hdl log out
            ret= SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;
        }
    }
    // free
    vm_free(sender_id_buf);	
    vm_free(push_installed_info);
    kal_wsprintf(push_path, "%c%w", SRV_MRE_APPMGR_PRELOAD_DRV,SRV_MRE_APPMGR_IMG_FIRST_FOLDER);
    image_hdl = FS_Open(push_path, FS_OPEN_DIR | FS_READ_ONLY);
    if (image_hdl < FS_NO_ERROR)  /* folder not exist */
    {
        image_crt_hdl = FS_CreateDir(push_path); // create image folder
    }  
    FS_Close(image_hdl);
    kal_wsprintf(push_path, "%c%w", SRV_MRE_APPMGR_PRELOAD_DRV,SRV_MRE_APPMGR_IMG_FOLDER);
    image_hdl = FS_Open(push_path, FS_OPEN_DIR | FS_READ_ONLY);
    if (image_hdl < FS_NO_ERROR)  /* folder not exist */
    {
        image_crt_hdl = FS_CreateDir(push_path); // create image folder
    }
    FS_Close(image_hdl);
    if(image_hdl>=FS_NO_ERROR || image_crt_hdl>=FS_NO_ERROR)
    {
        vm_res_extract_images((short *)app_path,PUSH_IMAGE_ID_BEGIN,(short *)push_path);
        vm_res_extract_audios((short *)app_path,PUSH_AUDIO_ID_BEGIN,(short *)push_path);
    }
#ifdef __MMI_NSS_SUPPORT__
    if(ret == SRV_MRE_PUHS_TYPE_SUCCESS)
    {
        mmi_srv_nss_node nss_node;
        //U32 app_nss_id = 0;
        memset(&nss_node,0,sizeof(mmi_srv_nss_node));
        nss_node.app_type = DOWNLOAD_APP_TYPE;
        nss_node.app_id = app_unique_id;
        nss_node.notification_setting = NSS_SETTING_DEFAULT;
        nss_node.notification_mask = NSS_MASK_DEFAULT;
        mmi_srv_nss_register(&nss_node);/*appid用来打开push install file*/
    }
#endif

    return ret;
}


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
mmi_ret srv_mre_push_receiver_is_have_register_id(U32 AppID,char *RegID)
{
    srv_pns_result ret = SRV_PNS_ERR_TOTAL;

    if (NULL == RegID)
    {
        return SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;//
    }
    memset(RegID,0,MAX_PUSH_REGISTER_ID_LENGTH);

    ret = srv_pns_query_regid(AppID,RegID,MAX_PUSH_REGISTER_ID_LENGTH);
    if (ret != SRV_PNS_NO_ERROR)
        return SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;

    return SRV_MRE_PUHS_TYPE_SUCCESS;
}


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
mmi_ret srv_mre_push_receiver_set_notify_style(U32 appId,vm_srv_pns_notify_switch OnOff,vm_srv_pns_notify_style style)
{
    //U32 PushStyle = 0;
    srv_mre_appmgr_push_installed_info_struct* read_info = NULL;
    mmi_ret 	isFileExit			= SRV_MRE_PUHS_TYPE_FILE_NOT_EXIT;
    isFileExit = srv_mre_push_receiver_file_is_exist(appId);
    if(isFileExit == SRV_MRE_PUHS_TYPE_FILE_EXIT)
    {
        read_info = (srv_mre_appmgr_push_installed_info_struct*)mmi_malloc(sizeof(srv_mre_appmgr_push_installed_info_struct));
        srv_mre_push_receiver_file_read(appId,read_info,MMI_FALSE);
        // set switch ( Clean all => "|" On/Off).
        read_info->style = OnOff;				
        // set style ("|" style
        read_info->style |= style;
        // save file
        srv_mre_push_receiver_file_write(appId,read_info,MMI_FALSE);
        mmi_mfree(read_info);
        return SRV_MRE_PUHS_TYPE_SUCCESS;
    }
    else
    {
        return SRV_MRE_PUSH_TYPE_LIST_NOT_FIND;// not install app
    }
}

mmi_ret srv_mre_push_reveiver_get_click_rate(U32 push_id, srv_mre_appmgr_click_rate_struct *click)
{
    srv_mre_appmgr_push_installed_info_struct* read_info = NULL;
    if(click==NULL)
        return SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;
    read_info = (srv_mre_appmgr_push_installed_info_struct*)mmi_malloc(sizeof(srv_mre_appmgr_push_installed_info_struct));
    srv_mre_push_receiver_file_read(push_id,read_info,MMI_FALSE);
    //srv_mre_appmgr_click_rate_struct temp = read_info->click_rate;
    // click->normal_launch_count = temp.normal_launch_count;
    //click->ncenter_launch_count = temp.ncenter_launch_count;
    //click->ncenter_launch_has_custom_key_count = temp.ncenter_launch_has_custom_key_count;
    //click->popup_launch_count = temp.popup_launch_count;
    //click->popup_launch_has_custom_key_count = temp.popup_launch_has_custom_key_count;
    //click->textpreview_launch_count = temp.textpreview_launch_count;
    //click->textpreview_launch_has_custom_key_count = temp.textpreview_launch_has_custom_key_count;
    //click->badge_launch_count = temp.badge_launch_count;
    memcpy(click,&(read_info->click_rate),sizeof(srv_mre_appmgr_click_rate_struct));
    mmi_mfree(read_info);
    //}
    //else
    //{
    //return SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;
    //}

    return SRV_MRE_PUHS_TYPE_SUCCESS;
}


mmi_ret srv_mre_push_reveiver_set_click_rate(U32 push_id)
{
    srv_mre_appmgr_push_installed_info_struct* read_info = NULL;
    //char temp_name[MMI_APP_NAME_MAX_LEN*2] = {0};
    read_info = (srv_mre_appmgr_push_installed_info_struct*)mmi_malloc(sizeof(srv_mre_appmgr_push_installed_info_struct));
    //if(read_info)
    //{
    // store to file
    srv_mre_push_receiver_file_read(push_id,read_info,MMI_TRUE);
    //(read_info->click_rate).normal_launch_count = 0;
    //(read_info->click_rate).ncenter_launch_count = 0;
    //(read_info->click_rate).ncenter_launch_has_custom_key_count = 0;
    //(read_info->click_rate).popup_launch_count = 0;
    //(read_info->click_rate).popup_launch_has_custom_key_count = 0;
    // (read_info->click_rate).textpreview_launch_count = 0;
    // (read_info->click_rate).textpreview_launch_has_custom_key_count = 0;
    //(read_info->click_rate).badge_launch_count = 0;
    memset(&(read_info->click_rate),0,sizeof(srv_mre_appmgr_click_rate_struct));
    srv_mre_push_receiver_file_write(push_id,read_info,MMI_TRUE);
    mmi_mfree(read_info);
    //}
    //else
    //{
    //	return SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;
    //}

    return SRV_MRE_PUHS_TYPE_SUCCESS;

}

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
mmi_ret srv_mre_push_receiver_set_badge_number(U32 appId,U32 badge)
{
    srv_mre_appmgr_push_installed_info_struct* read_info = NULL;
    char temp_name[MMI_APP_NAME_MAX_LEN*2] = {0};
    mmi_ret 	isFileExit			= SRV_MRE_PUHS_TYPE_FILE_NOT_EXIT;
    isFileExit = srv_mre_push_receiver_file_is_exist(appId);
    if(isFileExit == SRV_MRE_PUHS_TYPE_FILE_EXIT)
    {
        read_info = (srv_mre_appmgr_push_installed_info_struct*)mmi_malloc(sizeof(srv_mre_appmgr_push_installed_info_struct));
        // store to file
        srv_mre_push_receiver_file_read(appId,read_info,MMI_FALSE);

        // set badge
        read_info->_badge = badge;

        // save file
        srv_mre_push_receiver_file_write(appId,read_info,MMI_FALSE);
#ifdef __LOW_COST_SUPPORT_COMMON__
        srv_mre_appmgr_get_avaible_unique_id(NULL,0,read_info->app_unique_id,NULL,NULL,NULL,badge,0);
#else
        srv_mre_appmgr_get_avaible_unique_id(NULL,0,read_info->app_unique_id,NULL,NULL,NULL,NULL,badge,0);
#endif

        // notify mainmenu update information
        mmi_chset_convert(MMI_CHSET_UCS2,MMI_CHSET_UTF8,(char*)read_info->app_install_name,(char*)temp_name,sizeof(temp_name));
        srv_appmgr_update_app_info((const mmi_app_package_char*)temp_name,EVT_ID_SRV_APPMGR_UPDATE_BADGE);
        mmi_mfree(read_info);
    }
    return SRV_MRE_PUHS_TYPE_SUCCESS;
}


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
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
#endif

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
//mmi_ret srv_mre_push_receiver_deinit(void)
//{
//	return 0;
//}


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
mmi_ret srv_mre_push_receiver_uninstall(WCHAR *app_name)
{
    U32 		i 					= 0;
    int 		push_app_num 		= -1;	
    S32 		search_hdl 		= -1;
    S32 		search_ret 		= FS_NO_ERROR;
    mmi_ret 	ret = SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;
    WCHAR 		filename[SRV_MRE_APPMGR_PATH_SIZE];
    WCHAR 		app_name_w[MMI_APP_NAME_MAX_LEN];
    FS_HANDLE    image_hdl = -1;
    WCHAR push_path[SRV_MRE_APPMGR_PATH_SIZE];	

    FS_DOSDirEntry de;
    srv_mre_appmgr_push_installed_info_struct name_array;	

    memset(&name_array,0,sizeof(srv_mre_appmgr_push_installed_info_struct));
    //memset(&de,0,sizeof(FS_DOSDirEntry));	


    push_app_num = srv_mre_appmgr_get_push_app_num();
    kal_wsprintf(push_path, "%c%w", SRV_MRE_APPMGR_PRELOAD_DRV,SRV_MRE_APPMGR_IMG_FOLDER);
    image_hdl = FS_Open(push_path, FS_OPEN_DIR | FS_READ_ONLY);
    FS_Close(image_hdl);

    /* Build pattern */
    //mmi_wcscpy(filename, SRV_MRE_APPMGR_PUSH_FOLDER);
    //mmi_wcscat(filename, L"*");
    kal_wsprintf(filename,"z:\\@mre\\push\\*");

    search_hdl = FS_FindFirst(filename, 0, FS_ATTR_DIR, &de, app_name_w, MMI_APP_NAME_MAX_LEN*2);
    if (search_hdl >= 0)
    {
        for (; i < push_app_num;i++)
        {
            if ((search_ret== FS_NO_ERROR)&&srv_mre_appmgr_get_push_installed_info(app_name_w, &name_array) && (NULL !=name_array.app_path))
            {
                if(0 == app_ucs2_wcsncmp(app_name,name_array.app_install_name,(sizeof(U16)*MMI_APP_NAME_MAX_LEN)))
                {
                    // if find get app id.
                    //srv_mre_push_type_enum DegID = SRV_MRE_PUHS_TYPE_SUCCESS;
                    srv_mre_push_receiver_pns_deregister(name_array.app_id);
#ifdef __MMI_NSS_SUPPORT__
                    mmi_srv_nss_unregister(name_array.app_unique_id);
#endif
                    // delete.
                    FS_FindClose(search_hdl);
                    {
                        //int x = FS_NO_ERROR;
                        // create app path.
                        WCHAR 		delfilename[SRV_MRE_APPMGR_PATH_SIZE];
                        //WCHAR 		delfileName[16]= {L'0'};
                        //mmi_chset_convert(MMI_CHSET_UTF8,MMI_CHSET_UCS2,(char*)de.FileName,(char*)delfileName,sizeof(WCHAR)*16);

                        //mmi_wcscpy(delfilename, SRV_MRE_APPMGR_PUSH_FOLDER);
                        //mmi_wcscat(delfilename, (const WCHAR*)app_name_w);
                        kal_wsprintf(delfilename,"%w%w",SRV_MRE_APPMGR_PUSH_FOLDER,app_name_w);
#ifdef __MMI_NCENTER_SUPPORT__
                        srv_mre_push_receiver_file_read(name_array.app_id,&name_array,MMI_TRUE);
                        if(push_cache.app_id == name_array.app_id&&push_cache.app_payload.payload_count>0)
                        {
                            int array_index = 0;
                            for(;array_index<push_cache.app_payload.payload_count;array_index++)
                            {
                                vm_ncenter_push_delete_message(name_array.app_id,push_cache.app_payload.multiple_payload[array_index].query_index);
                            }
                            srv_mre_push_receiver_hide_status_icon(name_array.app_unique_id);
                        }
#endif
                        FS_Delete(delfilename);
                        memset(&push_cache,0,sizeof(srv_mre_appmgr_push_payload_ram_struct));
                        if(image_hdl>=FS_NO_ERROR)
                        {
                            vm_res_delete_images((short *)(name_array.app_path),PUSH_IMAGE_ID_BEGIN,(short *)push_path);
                            vm_res_delete_audios((short *)(name_array.app_path),PUSH_AUDIO_ID_BEGIN,(short *)push_path);
                        }
                    }
                    return SRV_MRE_PUHS_TYPE_SUCCESS;
                }
                //i++;
                search_ret = FS_FindNext(search_hdl, &de, app_name_w, MMI_APP_NAME_MAX_LEN*2);
            }
        }
    }
    FS_FindClose(search_hdl);
    return ret;
}


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
mmi_ret srv_mre_push_receiver_pns_register(U32 AppID,char* SenderID, mmi_proc_func CB, void* UserData)
{
    //int 		queryRet			= -1;
    //mmi_ret 	regRet				= MMI_RET_OK;
   // mmi_ret 	reg_ret 			= MMI_RET_OK;	
    mmi_ret 	isFileExit			= SRV_MRE_PUHS_TYPE_FILE_NOT_EXIT;
    //int 		Ret 				= SRV_PNS_NO_ERROR;	
    mmi_ret GetRegIdRet 	= SRV_PNS_ERR_TOTAL;

    char RegID[MAX_PUSH_REGISTER_ID_LENGTH];
    isFileExit = srv_mre_push_receiver_file_is_exist(AppID);
    if(SRV_MRE_PUHS_TYPE_FILE_EXIT == isFileExit)	
    {

        GetRegIdRet = srv_mre_push_receiver_is_have_register_id(AppID,RegID);

        /* if an app have REG_ID,we have two things to do
        * first  : call user callback to notify app the REG_ID.
        * second : set the message receive callback.*/
        if(SRV_PNS_NO_ERROR == GetRegIdRet)
        {
            vm_srv_pns_identity_event_struct app_reg_evt;
            memset(&app_reg_evt,0,sizeof(vm_srv_pns_identity_event_struct));

            app_reg_evt.evt_id 		= EVT_ID_SRV_PNS_REGISTER_RSP;
            app_reg_evt.size			= 0;
            app_reg_evt.user_data 		= UserData;
            app_reg_evt.result 		= VM_SRV_PNS_NO_ERROR;
            app_reg_evt.appId 			= AppID;
            app_strlcpy(app_reg_evt.reg_id,RegID,SRV_PNS_REGID_LEN);

            // call user callback to notify RED ID
            srv_mre_push_receiver_call_user_func(AppID,(mmi_event_struct*)&app_reg_evt);

            // setup callback to receive message (MUST BE)
            srv_pns_setup_receive_cb(AppID,srv_mre_push_receiver_pns_callback,UserData);
            return SRV_MRE_PUSH_TYPE_REG_ID_ALREADY_REG;
        }
        else
        {		
            srv_mre_push_receiver_app_handler(SRV_MRE_MPR_APP_HANDLE_REG,AppID,SenderID,CB,UserData);
        }

    }
    //else if(SRV_MRE_PUHS_TYPE_FILE_NOT_EXIT)
    //{
    //	regRet = srv_mre_push_receiver_app_handler(SRV_MRE_MPR_APP_HANDLE_REG,AppID,SenderID,CB,UserData);		
    //}
    else
    {
        // normal logic should be not running to here
        // Assert(0);
        return SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;
    }

    return SRV_MRE_PUHS_TYPE_SUCCESS;
}


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
mmi_ret srv_mre_push_receiver_pns_deregister(U32 appId)
{
    mmi_ret regRet 	 = SRV_MRE_PUHS_TYPE_SUCCESS;
    mmi_ret fileExistCheck = SRV_MRE_PUHS_TYPE_FILE_NOT_EXIT;

    // parameter check 
    if(0 >= appId){
        return MMI_FALSE;
    }

    fileExistCheck = srv_mre_push_receiver_file_is_exist(appId);
    if(SRV_MRE_PUHS_TYPE_FILE_EXIT == fileExistCheck )
    {
        regRet = (mmi_ret)(srv_mre_push_receiver_app_handler(SRV_MRE_MPR_APP_HANDLE_DEREG,appId,NULL,NULL,NULL));
        // vm_log_debug();
        return regRet;	
    }

    return SRV_MRE_PUHS_TYPE_FILE_NOT_EXIT;
}


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
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
#endif

mmi_ret srv_mre_load_last_message(multiple_payload_internal_struct* payload, U32 app_id)
{
    srv_mre_appmgr_push_installed_info_struct read_info;
    if(payload==NULL)
    {
        return MMI_FALSE;
    }
    srv_mre_push_receiver_file_read(app_id,&read_info,MMI_TRUE);
    if(push_cache.app_id==app_id &&push_cache.app_payload.payload_count>0)
    {
        memcpy(payload, &(push_cache.app_payload.multiple_payload[push_cache.app_payload.payload_count-1]), sizeof(multiple_payload_internal_struct));
    }

    return MMI_TRUE;
}
/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
U32 srv_mre_appmgr_get_push_app_num(void)
{
    WCHAR filename[SRV_MRE_APPMGR_PATH_SIZE];
    S32 app_num = 0;

    /* Build file path, and check app number */
    mmi_wcscpy(filename, SRV_MRE_APPMGR_PUSH_FOLDER);
    app_num = FS_Count((WCHAR*) filename, FS_FILE_TYPE, NULL, 0);
    if (app_num <= FS_NO_ERROR)
    {
        return 0;
    }

    return app_num;
}
/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
mmi_ret srv_mre_push_receiver_call_user_func(U32 AppID,mmi_event_struct *Param)
{
    srv_pns_reg_rsp_event_struct * 	reg_evt = (srv_pns_reg_rsp_event_struct *)Param;
    //vm_pn_cb cb = NULL;
    vm_srv_pns_identity_event_struct app_reg_evt = {0};

    // data copy
    app_reg_evt.evt_id 	= reg_evt->evt_id;
    app_reg_evt.user_data 	= reg_evt->user_data;
    app_reg_evt.result 	= (vm_srv_pns_result)reg_evt->result;
    app_reg_evt.appId 		= reg_evt->appId;
    app_strlcpy(app_reg_evt.reg_id,reg_evt->reg_id,SRV_PNS_REGID_LEN);

    // call user callback
    vm_pn_proc((mmi_event_struct*)&app_reg_evt,(void*)Param->user_data);

    return SRV_MRE_PUHS_TYPE_SUCCESS;
}

mmi_ret srv_mre_clear_message_by_index(U32 app_id, U32 query_index)
{
    srv_mre_appmgr_push_installed_info_struct read_info;
    U32 i = 0;
    srv_mre_push_receiver_file_read(app_id,&read_info,MMI_TRUE);
    if(push_cache.app_id==app_id &&push_cache.app_payload.payload_count>0)
    {
        for(;i<MRE_PUSH_MAX_PAYLOAD;i++)
        {
            if(push_cache.app_payload.multiple_payload[i].query_index == query_index )
                break;
        }
        if(i>=MRE_PUSH_MAX_PAYLOAD)
            return MMI_FALSE;
        if(i == (push_cache.app_payload.payload_count -1))
        {
            memset(&(push_cache.app_payload.multiple_payload[i]),0,sizeof(multiple_payload_internal_struct));
            (push_cache.app_payload.payload_count) --;
        }
        else 
        {    U32 j = i;
        for(;j<push_cache.app_payload.payload_count-1;j++)
        {
            memcpy(&(push_cache.app_payload.multiple_payload[j]), &(push_cache.app_payload.multiple_payload[j+1]), sizeof(multiple_payload_internal_struct));
        }
        memset(&(push_cache.app_payload.multiple_payload[push_cache.app_payload.payload_count-1]),0,sizeof(multiple_payload_internal_struct));
        (push_cache.app_payload.payload_count)--;
        }
        if(push_cache.app_payload.payload_count == 0)
        {
            srv_mre_push_receiver_hide_status_icon(read_info.app_unique_id);
        }
        srv_mre_push_receiver_file_write(push_cache.app_id,&read_info,MMI_TRUE);
    }
    else
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


mmi_ret srv_mre_load_message_by_index(multiple_payload_internal_struct* payload, U32 app_id,U32 query_index)
{
    srv_mre_appmgr_push_installed_info_struct read_info;
    U32 i = 0;
    if(payload==NULL)
    {
        return MMI_FALSE;
    }
    srv_mre_push_receiver_file_read(app_id,&read_info,MMI_TRUE);
    if(push_cache.app_id==app_id &&push_cache.app_payload.payload_count>0)
    {
        for(;i<MRE_PUSH_MAX_PAYLOAD;i++)
        {
            if(push_cache.app_payload.multiple_payload[i].query_index == query_index )
                break;
        }
        if(i>=MRE_PUSH_MAX_PAYLOAD)
            return MMI_FALSE;
        memcpy(payload, &(push_cache.app_payload.multiple_payload[i]), sizeof(multiple_payload_internal_struct));
    }
    else
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}

U32 srv_mre_appmgr_get_push_avaible_payload_index(void)
{
    U32 i = 1,j = 0;// query_index range from 1 to MRE_PUSH_MAX_PAYLOAD
    for (;i<=MRE_PUSH_MAX_PAYLOAD;i++)
    {
        for(;j<MRE_PUSH_MAX_PAYLOAD;j++)
        {
            if(push_cache.app_payload.multiple_payload[j].query_index == i)
                break;
        }
        if(j==MRE_PUSH_MAX_PAYLOAD&&(i<=MRE_PUSH_MAX_PAYLOAD))
            break;
    }
    return i;
}

void srv_mre_appmgr_write_push_payload(char * msg_body)
{
    U32 payload_count = push_cache.app_payload.payload_count;
    if(payload_count == 0 )
    {
        strncpy((char *)(push_cache.app_payload.multiple_payload[0].payload),msg_body, MMI_PNS_MAX_MSGBODY_SIZE);
        push_cache.app_payload.multiple_payload[0].payload[MMI_PNS_MAX_MSGBODY_SIZE - 1] = '\0';
        push_cache.app_payload.multiple_payload[0].query_index = 1;
        applib_dt_get_rtc_time(&(push_cache.app_payload.multiple_payload[0].receive_time));
        push_cache.app_payload.payload_count = 1;
    }
    else if(payload_count == MRE_PUSH_MAX_PAYLOAD)
    {      
        U32 temp_query_index= push_cache.app_payload.multiple_payload[0].query_index;
        U32 i = 0;
#ifdef __MMI_NCENTER_SUPPORT__
        vm_ncenter_push_delete_message(push_cache.app_id,push_cache.app_payload.multiple_payload[0].query_index);
#endif
        for(;i<MRE_PUSH_MAX_PAYLOAD-1;i++)
        {
            memcpy(&(push_cache.app_payload.multiple_payload[i]), &(push_cache.app_payload.multiple_payload[i+1]), sizeof(multiple_payload_internal_struct));
        }
        strncpy((char *)(push_cache.app_payload.multiple_payload[MRE_PUSH_MAX_PAYLOAD-1].payload),msg_body, MMI_PNS_MAX_MSGBODY_SIZE);
        push_cache.app_payload.multiple_payload[MRE_PUSH_MAX_PAYLOAD-1].payload[MMI_PNS_MAX_MSGBODY_SIZE - 1] = '\0';
        push_cache.app_payload.multiple_payload[MRE_PUSH_MAX_PAYLOAD-1].query_index = temp_query_index;
        applib_dt_get_rtc_time(&(push_cache.app_payload.multiple_payload[MRE_PUSH_MAX_PAYLOAD-1].receive_time));
        push_cache.app_payload.payload_count = MRE_PUSH_MAX_PAYLOAD;
    }
    else
    {
        strncpy((char *)(push_cache.app_payload.multiple_payload[payload_count].payload),msg_body, MMI_PNS_MAX_MSGBODY_SIZE);
        push_cache.app_payload.multiple_payload[payload_count].payload[MMI_PNS_MAX_MSGBODY_SIZE - 1] = '\0';
        push_cache.app_payload.multiple_payload[payload_count].query_index = srv_mre_appmgr_get_push_avaible_payload_index();
        applib_dt_get_rtc_time(&(push_cache.app_payload.multiple_payload[payload_count].receive_time));
        push_cache.app_payload.payload_count = payload_count+1;
    }

}

void srv_mre_appmgr_delete_push_payload(srv_mre_mpr_query_event event,void *user_data,srv_mre_appmgr_push_installed_info_struct *installed_info)
{
    U32 i = 0;
    U32 temp_count = push_cache.app_payload.payload_count;
    switch(event)
    {
    case SRV_MRE_MPR_QUERY_PAYLOAD_BY_INDEX:
        {
            U32 query_index = ((one_payload_by_index *)user_data)->index;
            for(;i<MRE_PUSH_MAX_PAYLOAD;i++)
            {
                if(push_cache.app_payload.multiple_payload[i].query_index == query_index )
                    break;
            }
            if(i>=MRE_PUSH_MAX_PAYLOAD)
                return;
            strcpy((char *)(((one_payload_by_index*)user_data)->app_payload),(char*)push_cache.app_payload.multiple_payload[i].payload);
            if(i == (temp_count -1))
            {
#ifdef __MMI_NCENTER_SUPPORT__
                vm_ncenter_push_delete_message(push_cache.app_id,push_cache.app_payload.multiple_payload[i].query_index);
#endif
                memset(&(push_cache.app_payload.multiple_payload[i]),0,sizeof(multiple_payload_internal_struct));
                (push_cache.app_payload.payload_count) --;
            }
            else 
            {    U32 j = i;
#ifdef __MMI_NCENTER_SUPPORT__
            vm_ncenter_push_delete_message(push_cache.app_id,push_cache.app_payload.multiple_payload[i].query_index);
#endif
            for(;j<temp_count-1;j++)
            {
                memcpy(&(push_cache.app_payload.multiple_payload[j]), &(push_cache.app_payload.multiple_payload[j+1]), sizeof(multiple_payload_internal_struct));
            }
            memset(&(push_cache.app_payload.multiple_payload[temp_count-1]),0,sizeof(multiple_payload_internal_struct));
            (push_cache.app_payload.payload_count)--;
            }
        }
        break;
    case SRV_MRE_MPR_QUERY_MULTIPLE_PAYLOAD:
        {
            U32 payload_count =  0;
            U32 j = 0;
            if(((multiple_payload_by_count *)user_data)&&(((multiple_payload_by_count *)user_data)->payload_count))
            {
                payload_count = *(((multiple_payload_by_count *)user_data)->payload_count);
            }
            else return;
            if(payload_count>temp_count)
                return;
            i = temp_count - payload_count;
            for(j=0;j<payload_count;j++,i++)
            {
#ifdef __MMI_NCENTER_SUPPORT__
                vm_ncenter_push_delete_message(push_cache.app_id,push_cache.app_payload.multiple_payload[i].query_index);
#endif
                strcpy(((char *)((multiple_payload_by_count*)user_data)->app_payload[j]),(char*)push_cache.app_payload.multiple_payload[i].payload);
                memset(&(push_cache.app_payload.multiple_payload[i]),0,sizeof(multiple_payload_internal_struct));
            }
            push_cache.app_payload.payload_count = push_cache.app_payload.payload_count - payload_count;
        }
        break;
    default:break;
    }
    if(push_cache.app_payload.payload_count == 0)
    {
        srv_mre_push_receiver_hide_status_icon(installed_info->app_unique_id);
    }
    srv_mre_push_receiver_file_write(push_cache.app_id,installed_info,MMI_TRUE);
}

/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
mmi_ret srv_mre_push_receiver_pns_callback(mmi_event_struct *param)
{
    mmi_ret ret = SRV_PNS_ERR_TOTAL;
    //int paser_ret = SRV_PNS_NO_ERROR;

    //mmi_event_struct				*event = NULL;
    //srv_pns_msg_event_struct		*temp_event = NULL;
    //srv_pns_msg_mps_struct		*temp_msg;

    if (NULL == param)
    {
        return SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;
    }
    if (SRV_PNS_SETTING_OFF == srv_pns_get_global_setting())
    {
        return SRV_MRE_PUSH_TYPE_SETTING_OFF;
    }

    // 1.
    switch(param->evt_id)
    {
    case EVT_ID_SRV_PNS_REGISTER_RSP:
        {
            srv_pns_reg_rsp_event_struct* temp = (srv_pns_reg_rsp_event_struct*)param;
            if(SRV_PNS_NO_ERROR == temp->result)
            {
                srv_mre_push_receiver_call_user_func(temp->appId,param);
            }
        }
        break;

    case EVT_ID_SRV_PNS_REGISTRATION_ID_CHANGED:

        break;

    case EVT_ID_SRV_PNS_DEREGISTER_RSP:
        {
             ret = 1;// 1.directly return true.
        }
        break;

    case EVT_ID_SRV_PNS_MESSAGE:
        {
            int 	push_app_num = 0; 
            //int 	i = 0;
            //WCHAR 	push_path[SRV_MRE_APPMGR_PATH_SIZE];
            //U32 	push_size_written;	
            //FS_HANDLE 		push_hdl;
            srv_pns_msg_mps_struct p;

            //MMI_BOOL get_img_ret = MMI_FALSE; 			
            srv_pns_result 					paser_ret = SRV_PNS_NO_ERROR;
            mmi_mpr_popup_message_struct	mpsPtr;
            //mmi_pns_msg_event_struct* 		message = NULL; 	
            //mmi_ret 							FileFindRet = SRV_MRE_PUHS_TYPE_FILE_NOT_EXIT;
            srv_mre_appmgr_push_installed_info_struct* fileStoreInfo = NULL;
            srv_pns_msg_event_struct		*original_message = NULL;
            VM_PROCESS_STATUS app_status = VM_PMNG_UNLOAD;
            U32 payload_index = 0;
            MMI_BOOL is_only_badge = MMI_FALSE;



            memset(&mpsPtr,0,sizeof(mmi_mpr_popup_message_struct));
            //memset(&p,0,sizeof(srv_pns_msg_mps_struct));

            original_message = (srv_pns_msg_event_struct*)param;

            paser_ret = srv_pns_get_mps_info(original_message->msgBody,&mpsPtr.pns_msg_mps);
            // get app path.
            if(SRV_PNS_NO_ERROR == paser_ret)
            {
                // get push app num
                push_app_num = srv_mre_appmgr_get_push_app_num();
                if(0 != push_app_num)
                {		
                    // no need read file again.
                    fileStoreInfo =(srv_mre_appmgr_push_installed_info_struct*)mmi_malloc(sizeof(srv_mre_appmgr_push_installed_info_struct));
                    //if(NULL == fileStoreInfo)
                    //{
                    //return SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;
                    //}
                    //memset(fileStoreInfo,0,sizeof(srv_mre_appmgr_push_installed_info_struct));
                    srv_mre_push_receiver_file_read(original_message->appId,fileStoreInfo,MMI_TRUE);

                    {
                        mpsPtr.app_path = fileStoreInfo->app_path;
                        // store payload to file(we only store the last payload)
                        {
                            //strncpy(fileStoreInfo->app_payload,original_message->msgBody, sizeof(fileStoreInfo->app_payload));
                            //fileStoreInfo->app_payload[sizeof(fileStoreInfo->app_payload) - 1] = '\0';
                            //refresh push_cache
                            srv_mre_appmgr_write_push_payload(original_message->msgBody);
                            memset(&p,0,sizeof(srv_pns_msg_mps_struct)); 
                            ret = srv_pns_get_mps_info(original_message->msgBody,(srv_pns_msg_mps_struct*)&p);
                            {
                                if (SRV_PNS_NO_ERROR == ret)
                                {
                                    fileStoreInfo->_badge = p.badge;
                                }
                                if(p.mainLen==0&&p.mainResId==0)
                                {
                                    is_only_badge = MMI_TRUE;
                                }
                            }
                        }
                        if(mre_push_usb_ms_mode||mre_push_dev_plug_out)
                        {
                            fileStoreInfo->defer_notification = 1;
                        }
                        else
                        {
                            fileStoreInfo->defer_notification = 0;
                        }
                        // store to file
                        srv_mre_push_receiver_file_write(original_message->appId,fileStoreInfo,MMI_TRUE);
#ifdef __LOW_COST_SUPPORT_COMMON__
                        srv_mre_appmgr_get_avaible_unique_id(NULL,0,fileStoreInfo->app_unique_id,NULL,NULL, NULL,p.badge,0);
#else
                        srv_mre_appmgr_get_avaible_unique_id(NULL,0,fileStoreInfo->app_unique_id,NULL,NULL,NULL,NULL,p.badge,0);
#endif
                        if(fileStoreInfo->defer_notification==0)
                        {
                            payload_index = push_cache.app_payload.payload_count-1;

                            app_status = srv_mre_check_app_status_by_name(fileStoreInfo->app_path);
                            if((VM_PMNG_FOREGROUND!= app_status))
                            {
                                // check push notify style.
                                //{
                                //int x = (fileStoreInfo->style & VM_PNS_NOTIFY_SWITCH_MASK);
                                //if(0 != x)// notification set on.
                                //{
                                if(!is_only_badge)
                                {
                                    if (VM_SRV_MRE_MPR_NOTIFY_STYLE_POPUP == (fileStoreInfo->style & VM_SRV_MRE_MPR_NOTIFY_STYLE_POPUP))
                                    {
                                        //srv_mre_push_receiver_show_text_preview(fileStoreInfo->app_id);
                                        srv_mre_push_receiver_show_popup_wrapper(original_message->appId, fileStoreInfo->app_unique_id, (WCHAR*)fileStoreInfo->app_path,(WCHAR*)fileStoreInfo->app_install_name,original_message->msgBody, MMI_TRUE);
                                    }
                                    else
                                    {
                                        srv_mre_push_receiver_show_popup_wrapper(original_message->appId, fileStoreInfo->app_unique_id, (WCHAR*)fileStoreInfo->app_path, (WCHAR*)fileStoreInfo->app_install_name,original_message->msgBody,MMI_FALSE);
                                        //mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_MRE_PUSH,MMI_EVENT_MRE_PUSH,srv_mre_push_receiver_show_popup_wrapper,(void *)fileStoreInfo->app_id);
                                    }
                                    // N-Center 
#ifdef __MMI_NCENTER_SUPPORT__
                                    vm_ncenter_push_new_message(fileStoreInfo->app_id,fileStoreInfo->app_unique_id,push_cache.app_payload.multiple_payload[payload_index].query_index);
#endif
                                }

                                // Badge
                                {
                                    char temp_name[MMI_APP_NAME_MAX_LEN*2] = {0};
                                    mmi_chset_convert(MMI_CHSET_UCS2,MMI_CHSET_UTF8,(char*)fileStoreInfo->app_install_name,(char*)temp_name,sizeof(temp_name));
                                    srv_appmgr_update_app_info((mmi_app_package_char*)temp_name,EVT_ID_SRV_APPMGR_UPDATE_BADGE);
                                }
                                // set the status bar's icon.
                                //srv_mre_push_receiver_show_status_icon(fileStoreInfo->app_id,(WCHAR*)fileStoreInfo->app_path);
                                //	}

                                //}
                            }
                            else
                            {
                                //	VM_P_HANDLE  p_handle = 0;
                                VMINT handle = srv_mre_get_running_handle(fileStoreInfo->app_path);
                                //p_handle = vm_pmng_get_current_handle();/**/
                                vm_send_system_message( handle,VM_MSG_PUSH, push_cache.app_payload.multiple_payload[payload_index].query_index);
                            }
                        }
                    }
                    mmi_mfree(fileStoreInfo);
                }
            }
        }
        break;

    default: // do nothing.
        break;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
mmi_ret srv_mre_push_receiver_pns_query(vm_srv_pns_query_event event,int AppID,void* userdata)
{
    mmi_ret RetVal = 0;	// default return value.
    //mmi_ret readFileRet = SRV_MRE_PUHS_TYPE_SUCCESS;
    srv_mre_appmgr_push_installed_info_struct readInfo;
    //memset(&readInfo,0,sizeof(srv_mre_appmgr_push_installed_info_struct));

    // read file
    if(SRV_MRE_PUHS_TYPE_SUCCESS != srv_mre_push_receiver_file_read(AppID,&readInfo,MMI_TRUE))
    {
        return SRV_MRE_PUHS_TYPE_INTERNAL_ERROR;
    }

    // 
    switch(event)
    {
    case SRV_MRE_MPR_QUERY_APP_ID:
        {
            RetVal = readInfo.app_id;
        }
        break;
    case SRV_MRE_MPR_QUERY_SENDER_ID:
        {
            char  sender_id[MMI_PNS_SENDERID_LEN] = {L'0'};
            mmi_chset_convert(MMI_CHSET_UCS2,MMI_CHSET_UTF8,(char*)readInfo.SenderID,(char*)sender_id,(sizeof(sender_id)));	
            strcpy((char*)userdata,(const char*)sender_id);
        }
        break;
    case SRV_MRE_MPR_QUERY_REGISTER_ID:
        {
            mmi_ret GetRegIdRet 	= SRV_PNS_ERR_TOTAL;
            char RegID[MAX_PUSH_REGISTER_ID_LENGTH] = {L'0'};
            GetRegIdRet = srv_mre_push_receiver_is_have_register_id(AppID,RegID);
            if(SRV_PNS_NO_ERROR == GetRegIdRet)
            {
                strcpy((char*)userdata,RegID);
            }

        }
        break;				
    case SRV_MRE_MPR_QUERY_SETTING_STATUS:
        {
            srv_pns_global_setting_enum SettingStatus = SRV_PNS_SETTING_END;
            SettingStatus = srv_pns_get_global_setting();
            RetVal =  SettingStatus;
        }
        break;
    case SRV_MRE_MPR_QUERY_BADGE:
        {
            RetVal = readInfo._badge;
        }
        break;	
    case SRV_MRE_MPR_QUERY_PAYLOAD_COUNT:
        if(push_cache.app_id==AppID)
        {
            *(((multiple_payload_by_count *)userdata)->payload_count) = push_cache.app_payload.payload_count;
        }
        break;
    case SRV_MRE_MPR_QUERY_PAYLOAD://last payload
        {
            if(push_cache.app_id==AppID &&push_cache.app_payload.payload_count>0 &&userdata!=NULL)
            {
                U32 i=push_cache.app_payload.payload_count-1;
                strcpy((char*)userdata,(char*)(push_cache.app_payload.multiple_payload[i].payload));
#ifdef __MMI_NCENTER_SUPPORT__
                vm_ncenter_push_delete_message(push_cache.app_id,push_cache.app_payload.multiple_payload[i].query_index);
#endif
                memset(&(push_cache.app_payload.multiple_payload[i]),0,sizeof(multiple_payload_internal_struct));
                (push_cache.app_payload.payload_count) --;
                if(push_cache.app_payload.payload_count == 0)
                {
                    srv_mre_push_receiver_hide_status_icon(readInfo.app_unique_id);
                }
                srv_mre_push_receiver_file_write(push_cache.app_id,&readInfo,MMI_TRUE);
            }
        }
        break;
    case SRV_MRE_MPR_QUERY_PAYLOAD_BY_INDEX:
        if(userdata!=NULL)
        {
            srv_mre_appmgr_delete_push_payload(SRV_MRE_MPR_QUERY_PAYLOAD_BY_INDEX,(void *)userdata,&readInfo);
        }
        break;
    case SRV_MRE_MPR_QUERY_MULTIPLE_PAYLOAD:
        if(userdata!=NULL)
        {
            srv_mre_appmgr_delete_push_payload(SRV_MRE_MPR_QUERY_MULTIPLE_PAYLOAD,(void *)userdata,&readInfo);
        }
        break;
    case SRV_MRE_MPR_QUERY_END:
    default:
        RetVal =  SRV_MRE_PUHS_TYPE_BADPARA;
        break;
    }

    return RetVal;
}


/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
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
#endif
/*****************************************************************************
* FUNCTION
*  
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
*  info     : [OUT]     
* RETURNS
*  
*****************************************************************************/
mmi_ret srv_mre_push_receiver_app_handler(srv_mre_mpr_app_handle_event event,U32 appId,char* senderId, mmi_proc_func cb, void* user_data)
{
    // init 
    int RetVal = SRV_PNS_NO_ERROR;
    //	mmi_mpr_list_node_struct* p = NULL;	
    //int save_res_ret = VM_RES_OK;
    //VM_P_HANDLE pHandle = vm_pmng_get_app_handle();

    // 1.parameter check
    if(0 >= appId){
        return MMI_FALSE;
    }

    // 2.APP_ID has been register.
    switch(event)
    {
    case SRV_MRE_MPR_APP_HANDLE_REG:
        {
            //int ret = SRV_PNS_NO_ERROR;

            RetVal = srv_pns_register(appId,senderId,srv_mre_push_receiver_pns_callback,user_data);
            srv_pns_setup_receive_cb(appId,srv_mre_push_receiver_pns_callback,user_data);		
            //return RetVal;
        }
        break;
    case SRV_MRE_MPR_APP_HANDLE_DEREG:
        {

            RetVal = srv_pns_deregister(appId, srv_mre_push_receiver_pns_callback,NULL);
            //return RetVal;
        }
        break;
        //case SRV_MRE_MPR_APP_HANDLE_END:
    default:
        // return error code bad_parameter
        break;
    }

    return RetVal;
}

mmi_ret srv_mre_appmgr_get_app_badge(mmi_app_package_char *app_name, void *badge)
{
	#ifndef __MMI_MRE_DISABLE_FMGR__
    U32 unique_app_id = 0;
    S32 index = 0;
#ifdef __MMI_NSS_SUPPORT__
    U16 setting_value = 0;
#endif
    unique_app_id = srv_mre_appmgr_get_unique_app_id(app_name);
    index = unique_app_id - SRV_MRE_APPMGR_ID_BASE;
    if(unique_app_id!=0&&index>=0)
    {
#ifdef __MMI_NSS_SUPPORT__
        mmi_srv_nss_get_setting(unique_app_id,NSS_SETTING_BADGE_ICON,&setting_value);
        if(setting_value==SETTING_ON)
        {
#endif
            if(0 != g_mre_appmgr_maptable[index].badge)
            {
                if(g_mre_appmgr_maptable[index].badge > 999)
                {
                    mmi_wcscpy((WCHAR*)badge,(WCHAR*)L"...");
                }
                else if(g_mre_appmgr_maptable[index].badge<=0)
                {
                    // Do nothing.
                }
                else
                {
                    mmi_wsprintf_ex((WCHAR*)badge,(SRV_APPMGR_BADGE_MAX_LEN+1)*sizeof(WCHAR),(WCHAR*)L"%d",g_mre_appmgr_maptable[index].badge);
                }
            }
#ifdef __MMI_NSS_SUPPORT__
        }
#endif		
    }	
    return MMI_RET_OK;
#else
return 0;
#endif
}

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_list
* DESCRIPTION
*  Get the application identifications, including shortcut application.
*  The caller should call srv_mre_appmgr_get_app_num() firstly to prepare the array size.
* PARAMETERS
*  flag : [IN] application manager service flag.
*  name_array : [OUT] get the application name of all installed applications.
*  num : [IN]  the array size.
* RETURN VALUES
*  MMI_RET_OK: Get the application list successfully.
*  MMI_RET_ERR: Get the application list fail.
*****************************************************************************/
mmi_ret srv_mre_appmgr_get_push_app_list(srv_mre_appmgr_push_installed_info_struct *name_array, U32 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_ret ret = MMI_RET_OK;
    WCHAR filename[SRV_MRE_APPMGR_PATH_SIZE];
    WCHAR app_name_w[MMI_APP_NAME_MAX_LEN*2];
    S32 search_hdl = -1, search_ret = FS_NO_ERROR;
    FS_DOSDirEntry de;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Build pattern */
    //mmi_wcscpy(filename, SRV_MRE_APPMGR_PUSH_FOLDER);
    //mmi_wcscat(filename, L"*");
    kal_wsprintf(filename,"z:\\@mre\\push\\*");
    search_hdl = FS_FindFirst(filename, 0, FS_ATTR_DIR, &de, app_name_w, MMI_APP_NAME_MAX_LEN*2);
    if (search_hdl >= 0)
    {
        for (; i < num;)
        {
            if (search_ret==FS_NO_ERROR&&srv_mre_appmgr_get_push_installed_info(app_name_w, &name_array[i]) && (NULL !=name_array[i].app_path))
            {
                // register app
                i++;
            }

            search_ret = FS_FindNext(search_hdl, &de, app_name_w, MMI_APP_NAME_MAX_LEN*2);
        }
    }
    FS_FindClose(search_hdl);
    return MMI_RET_OK;
}

#else
mmi_ret srv_mre_push_reveiver_get_click_rate(U32 push_id, srv_mre_appmgr_click_rate_struct *click)
{
    return 0;
}

mmi_ret srv_mre_push_reveiver_set_click_rate(U32 push_id)
{
    return 0;

}
#endif /* __MRE_SAL_PN__ */
