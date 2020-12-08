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
 *  vapp_java_srv.cpp
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#include "vapp_java_adp.h"
#include "vapp_javaagencymidsinstall.h"
#include "vapp_java_srv.h"
#include "vapp_vol_dialog_gprot.h"
#include "vcp_global_popup.h"
#include "vapp_javaagencysrc.h"
#include "Vapp_nmgr_gprot.h"

extern "C"
{
#include "MMI_include.h"
#include "MMI_features.h" 
#include "jam_msg_handler.h"
#include "JavaAppFactorySrvProt.h"
#include "App_str.h"
#include "mmi_rp_vapp_java_def.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "mmi_rp_srv_prof_def.h"
#include "NotificationGprot.h"
#include "jma_interface.h"
#include "DmSrvGprot.h"
}
#ifdef __MMI_USB_SUPPORT__
#include "Vapp_usb_gprot.h"
#endif
#include "gpiosrvgprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define LEN 30

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
 extern VappJavaMIDDetailScreen *gdetailScr;
extern VappJavaMidsSettingPage* SettingPage;
extern VappJavaMIDDetailControllor* g_mmi_vjava_detail_controllor;
extern VfxMainScr* g_parent_screen;
U16* setting_select_string[5];
extern mids_delete_callback g_vjava_delete_callabck;
extern void * g_vjava_user_data;
VfxBool g_vjava_get_mids_file_info_flag = KAL_FALSE;
extern VappJavaMidInstallScreen * g_install_mainscr;
extern CHAR * g_mmi_vjava_select_app_name;
S32 g_vjava_global_popup = VCP_GLOBAL_POPUP_INVALID_HANDLE;
VfxId g_mmi_vjava_advanced_setting_page = 101;
    
/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C" void vapp_java_recv_mids_get_setting_cnf(void *MsgStruct)
 {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_get_setting_cnf_struct *msg;
    VcpConfirmPopup * alertPopup = NULL;
    VappJavaMidsSettingPage* settingPage;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_MIDS_GET_SETTING_CNF);

    VFX_OBJ_CLOSE(VappJavaMIDDetailControllor::m_indacatorppPopup);

    msg = (mmi_java_mids_get_setting_cnf_struct*) MsgStruct;
    if (g_java.msg_ctrl & SEND_MID_GET_SETTING_CTRL )
    {
        g_java.msg_ctrl &= (~SEND_MID_GET_SETTING_CTRL);        
        if (msg->error_code == (kal_uint32) J2ME_NO_ERROR)
        {
            g_java.mids_trusted = (U8) msg->mids_trusted;
    
            kal_mem_cpy(&(g_java.mids_setting), &(msg->mids_setting), sizeof(mmi_setting_struct));
            kal_mem_cpy(&(g_java.mids_max_setting), &(msg->mids_max_setting), sizeof(mmi_setting_struct));
        }
    
        if (!get_setting_only)
        {
            get_domain_setting = MMI_FALSE;
            VFX_OBJ_CREATE(settingPage, VappJavaMidsSettingPage,g_parent_screen);
            settingPage->setSize(LCD_WIDTH,LCD_HEIGHT);
            g_parent_screen->pushPage(g_mmi_vjava_advanced_setting_page, settingPage);
        }
        else
        {
            vapp_java_refreash_setting_page();
        }
        get_setting_only = MMI_FALSE;
    }
}


 extern "C" void vapp_java_send_get_setting_req(void)
{
    g_java.domain = -1;  /* for specific midlet */
    SetProtocolEventHandler((PsFuncPtr) vapp_java_recv_mids_get_setting_cnf, MSG_ID_MMI_JAVA_MIDS_GET_SETTING_CNF);
    if(mmi_wcslen((const U16 *)g_java.mids_info[g_java.mids_index - g_java.mids_info_start].storage_name) < 127)
    {       
        app_ucs2_str_to_asc_str((kal_int8 *) g_mmi_java_current_selected_mids_root, (kal_int8 *)g_java.mids_info[g_java.mids_index - g_java.mids_info_start].storage_name);
    }
    else
    {                
        app_ucs2_str_n_to_asc_str((kal_int8 *) g_mmi_java_current_selected_mids_root, (kal_int8 *)g_java.mids_info[g_java.mids_index - g_java.mids_info_start].storage_name, 127);
    }  
    mmi_java_send_mids_get_setting_req(g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id, g_mmi_java_current_selected_mids_root);

}


 extern "C" U16* vapp_jave_get_permission(kal_uint8 idx)
{
   setting_select_string[0] = (U16*)GetString(STR_JAVA_PERM_USERDENY);
   setting_select_string[1] = (U16*)GetString(STR_JAVA_PERM_ONESHOT);
   setting_select_string[2] = (U16*)GetString(STR_JAVA_PERM_SESSION), 
   setting_select_string[3] =(U16*)GetString(STR_JAVA_PERM_BLANKET);
   setting_select_string[4] =(U16*)GetString(STR_JAVA_PERM_BLANKET_GRANTED);
   switch(idx)
   {
        case J2ME_SETTING_NETWORK_ACCESS:
            g_java.mids_choice_index[J2ME_SETTING_NETWORK_ACCESS] = mmi_java_get_choice_level(g_java.mids_setting.permission_network);
            return setting_select_string[mmi_java_get_choice_level(g_java.mids_setting.permission_network)];
        case J2ME_SETTING_AUTO_INVOCATION:
            g_java.mids_choice_index[J2ME_SETTING_AUTO_INVOCATION] = mmi_java_get_choice_level(g_java.mids_setting.permission_push);
            return setting_select_string[mmi_java_get_choice_level(g_java.mids_setting.permission_push)];
        case J2ME_SETTING_MESSAGING:
            g_java.mids_choice_index[J2ME_SETTING_MESSAGING] = mmi_java_get_choice_level(g_java.mids_setting.permission_message);
            return setting_select_string[mmi_java_get_choice_level(g_java.mids_setting.permission_message)];
        case J2ME_SETTING_MULTIMEDIA:
            g_java.mids_choice_index[J2ME_SETTING_MULTIMEDIA] = mmi_java_get_choice_level(g_java.mids_setting.permission_multimedia);
            return setting_select_string[mmi_java_get_choice_level(g_java.mids_setting.permission_multimedia)];
        case J2ME_SETTING_DATA_READ:
            g_java.mids_choice_index[J2ME_SETTING_DATA_READ] = mmi_java_get_choice_level(g_java.mids_setting.permission_data_read);
            return setting_select_string[mmi_java_get_choice_level(g_java.mids_setting.permission_data_read)];
        case J2ME_SETTING_DATA_WRITE:
            g_java.mids_choice_index[J2ME_SETTING_DATA_WRITE] = mmi_java_get_choice_level(g_java.mids_setting.permission_data_write);
            return setting_select_string[mmi_java_get_choice_level(g_java.mids_setting.permission_data_write)];
        case J2ME_SETTING_LOCAL_CONNECTIVITY:
            g_java.mids_choice_index[J2ME_SETTING_LOCAL_CONNECTIVITY] = mmi_java_get_choice_level(g_java.mids_setting.permission_local_connectivity);
            return setting_select_string[mmi_java_get_choice_level(g_java.mids_setting.permission_local_connectivity)];
#ifdef SUPPORT_JSR_179             
        case J2ME_SETTING_LOCATION_ACCESS:
            g_java.mids_choice_index[J2ME_SETTING_LOCATION_ACCESS] = mmi_java_get_choice_level(g_java.mids_setting.permission_location_access);
            return  setting_select_string[mmi_java_get_choice_level(g_java.mids_setting.permission_location_access)];
#endif
#ifdef SUPPORT_JSR_177
        case J2ME_SETTING_SATSA:
            g_java.mids_choice_index[J2ME_SETTING_SATSA] = mmi_java_get_choice_level(g_java.mids_setting.permission_satsa);
            return  setting_select_string[mmi_java_get_choice_level(g_java.mids_setting.permission_satsa)];
#endif
#ifdef SUPPORT_JSR_257
        case J2ME_SETTING_CONTACTLESS_COMMUNICATION:
            g_java.mids_choice_index[J2ME_SETTING_CONTACTLESS_COMMUNICATION] = mmi_java_get_choice_level(g_java.mids_setting.permission_contactless_communication);
            return  setting_select_string[mmi_java_get_choice_level(g_java.mids_setting.permission_contactless_communication)];
            default:
                break;
#endif                
   }
   return NULL;
}


 extern "C" S8 vapp_jave_get_permission_level_by_index(kal_uint8 idx)
{
   switch(idx)
   {
        case J2ME_SETTING_NETWORK_ACCESS:
            return mmi_java_get_choice_level(g_java.mids_setting.permission_network);
        case J2ME_SETTING_AUTO_INVOCATION:
            return mmi_java_get_choice_level(g_java.mids_setting.permission_push);
        case J2ME_SETTING_MESSAGING:
            return mmi_java_get_choice_level(g_java.mids_setting.permission_message);
        case J2ME_SETTING_MULTIMEDIA:
            return mmi_java_get_choice_level(g_java.mids_setting.permission_multimedia);
        case J2ME_SETTING_DATA_READ:
            return mmi_java_get_choice_level(g_java.mids_setting.permission_data_read);
        case J2ME_SETTING_DATA_WRITE:
            return mmi_java_get_choice_level(g_java.mids_setting.permission_data_write);
        case J2ME_SETTING_LOCAL_CONNECTIVITY:
            return mmi_java_get_choice_level(g_java.mids_setting.permission_local_connectivity);
    #ifdef SUPPORT_JSR_179            
        case J2ME_SETTING_LOCATION_ACCESS:
            return  mmi_java_get_choice_level(g_java.mids_setting.permission_location_access);
    #endif
    #ifdef SUPPORT_JSR_177
        case J2ME_SETTING_SATSA:
            return mmi_java_get_choice_level(g_java.mids_setting.permission_satsa);
    #endif
    #ifdef SUPPORT_JSR_257    
        case J2ME_SETTING_CONTACTLESS_COMMUNICATION:
            return mmi_java_get_choice_level(g_java.mids_setting.permission_contactless_communication);
    #endif
        default:
            break;
   }
   return 0;
}

extern "C" S32 vapp_java_get_permission_item_count(kal_int32 index)
{
    switch(index)
        {
            case J2ME_SETTING_NETWORK_ACCESS:
                return mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_network);
            case J2ME_SETTING_AUTO_INVOCATION:
                return mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_push);
            case J2ME_SETTING_MESSAGING:
                return mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_message);
            case J2ME_SETTING_MULTIMEDIA:
                return mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_multimedia);
            case J2ME_SETTING_DATA_READ:
                return mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_data_read);
            case J2ME_SETTING_DATA_WRITE:
                return mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_data_write);
            case J2ME_SETTING_LOCAL_CONNECTIVITY:
                return mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_local_connectivity);
    #ifdef SUPPORT_JSR_179
            case J2ME_SETTING_LOCATION_ACCESS:
                return mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_location_access);
    #endif
    #ifdef SUPPORT_JSR_177
            case J2ME_SETTING_SATSA:
                return mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_satsa);
    #endif
    #ifdef SUPPORT_JSR_257
            case J2ME_SETTING_CONTACTLESS_COMMUNICATION:
                return mmi_java_get_perm_menu_item_count(g_java.mids_max_setting.permission_contactless_communication);
    #endif     
    default:
        return 0;
        }
}


extern "C" void vapp_java_mids_delete(kal_uint32 mids_id, kal_char* mids_storage_id)
{
        /*----------------------------------------------------------------*/
        /* Local Variables*/
        /*----------------------------------------------------------------*/
        kal_int32  len = 0;
        kal_char* ptr = NULL;
        mmi_java_mids_remove_req_struct *msg = NULL;
        VcpConfirmPopup* alertPopup = NULL;

        /*----------------------------------------------------------------*/
        /* Code Body      */
        /*----------------------------------------------------------------*/
        MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_MIDS_REMOVE_REQ);
        if(mids_id == -1 && mids_storage_id ==NULL)
        {
            mmi_java_report_status(g_mmi_java_current_running_cmd,J2ME_INVALID_REQUEST,NULL,NULL,NULL);
            return;
        }
    
#ifdef __USB_IN_NORMAL_MODE__
        if (srv_usb_is_in_mass_storage_mode())
        {
            /* in mass storage mode */
            if(!g_mmi_java_is_background_display)
            {
                vapp_usb_unavailable_popup(0);   /* pass 0 will show default string */
            }
            mmi_java_report_status(g_mmi_java_current_running_cmd,J2ME_ACTION_FAILE,NULL,NULL,NULL);
            return;
            
        }
#endif /* __USB_IN_NORMAL_MODE__ */ 
        if (g_java.mids_delete_state == DELETE_VALID_STATE)
        {
            msg = (mmi_java_mids_remove_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mids_remove_req_struct));
            if(mids_id != -1)
            {
                msg->mids_id = mids_id;
                msg->mids_storage_id = NULL;
            }
            else
            {
                msg->mids_id = -1;
                len = strlen((const char *) mids_storage_id)+1;
                ptr = (kal_char*)get_ctrl_buffer(len);
                if(ptr==NULL){
                    ASSERT(0);
                }
                memset(ptr,0,len);
                memcpy(ptr, mids_storage_id, len);
                msg->mids_storage_id = ptr;
            }
            mmi_java_send_message_from_active_mod( MOD_JAM, MMI_J2ME_SAP,
                MSG_ID_MMI_JAVA_MIDS_REMOVE_REQ, msg); 
    
            g_java.mids_delete_state = DELETE_START_STATE;
        }
        else
        {
            if(!g_mmi_java_is_background_display)
            {
                mmi_java_display_is_busy();
            }
            mmi_java_report_status(g_mmi_java_current_running_cmd,J2ME_VM_IS_BUSY,NULL,NULL,NULL);
        }
    
}

extern "C" mmi_id  g_java_installer_cui_gid;
extern "C" void vapp_java_mids_del_notify(kal_int32 error_code)
{
    if(!g_mmi_java_is_background_display &&g_vjava_delete_callabck)
    {
        if(error_code == J2ME_NO_ERROR)
            g_vjava_delete_callabck(g_vjava_user_data,0);
        else
            g_vjava_delete_callabck(g_vjava_user_data,1);

    }
    g_vjava_delete_callabck = NULL;
}


void vapp_java_recv_mids_set_setting_cnf(void *MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_set_setting_cnf_struct *msg;
    VcpConfirmPopup* alertPopup = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_RECV_MIDS_SET_SETTING_CNF);

    msg = (mmi_java_mids_set_setting_cnf_struct*) MsgStruct;

    if (g_java.msg_ctrl & SEND_MID_SET_SETTING_CTRL )
    {
        get_setting_only = MMI_TRUE;
        vapp_java_send_get_setting_req();
        g_java.msg_ctrl &= (~SEND_MID_SET_SETTING_CTRL);
    }
}


extern "C" void vapp_java_send_mids_set_setting_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_mids_set_setting_req_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_TRACE_FUNC, MMI_JAVA_SEND_MIDS_SET_SETTING_REQ);

    if (g_java.msg_ctrl & SEND_MID_SET_SETTING_CTRL )
    {
        return;
    }
    else
    {
        g_java.msg_ctrl |= SEND_MID_SET_SETTING_CTRL;
        msg = (mmi_java_mids_set_setting_req_struct*) OslConstructDataPtr(sizeof(mmi_java_mids_set_setting_req_struct));
        msg->mids_id = g_java.mids_info[g_java.mids_index - g_java.mids_info_start].mids_id;

        kal_mem_cpy(&(msg->mids_setting), &(g_java.mids_setting), sizeof(mmi_setting_struct));
        SetProtocolEventHandler((PsFuncPtr) vapp_java_recv_mids_set_setting_cnf, MSG_ID_MMI_JAVA_MIDS_SET_SETTING_CNF);
        mmi_java_send_message_from_active_mod(MOD_JAM, MMI_J2ME_SAP,
            MSG_ID_MMI_JAVA_MIDS_SET_SETTING_REQ, msg);
    }
}


extern "C" void vapp_java_update_mids_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    VcpConfirmPopup* alertPopup = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for( i = 0 ; i < J2ME_SETTING_MAX ;i ++)
    {
        switch (i)
        {
            case J2ME_SETTING_NETWORK_ACCESS:
                g_java.mids_setting.permission_network = mmi_java_get_new_permission_level((S8) g_java.mids_choice_index[i],
                                                                                (S8)g_java.mids_max_setting.permission_network,
                                                                                (S8)g_java.mids_setting.permission_network);
                break;
            case J2ME_SETTING_AUTO_INVOCATION:
                g_java.mids_setting.permission_push = mmi_java_get_new_permission_level((S8) g_java.mids_choice_index[i],
                                                                                (S8)g_java.mids_max_setting.permission_push,
                                                                                (S8)g_java.mids_setting.permission_push);
                break;
            case J2ME_SETTING_MESSAGING:
                g_java.mids_setting.permission_message = mmi_java_get_new_permission_level((S8) g_java.mids_choice_index[i],
                                                                                (S8)g_java.mids_max_setting.permission_message,
                                                                                (S8)g_java.mids_setting.permission_message);
                break;
            case J2ME_SETTING_MULTIMEDIA:
                g_java.mids_setting.permission_multimedia = mmi_java_get_new_permission_level((S8) g_java.mids_choice_index[i],
                                                                                (S8)g_java.mids_max_setting.permission_multimedia,
                                                                                (S8)g_java.mids_setting.permission_multimedia);
                break;
            case J2ME_SETTING_DATA_READ:
                g_java.mids_setting.permission_data_read = mmi_java_get_new_permission_level((S8) g_java.mids_choice_index[i],
                                                                                (S8)g_java.mids_max_setting.permission_data_read,
                                                                                (S8)g_java.mids_setting.permission_data_read);
                break;
            case J2ME_SETTING_DATA_WRITE:
                g_java.mids_setting.permission_data_write = mmi_java_get_new_permission_level((S8) g_java.mids_choice_index[i],
                                                                                (S8)g_java.mids_max_setting.permission_data_write,
                                                                                (S8)g_java.mids_setting.permission_data_write);
                break;
            case J2ME_SETTING_LOCAL_CONNECTIVITY:
                g_java.mids_setting.permission_local_connectivity = mmi_java_get_new_permission_level((S8) g_java.mids_choice_index[i],
                                                                                (S8)g_java.mids_max_setting.permission_local_connectivity,
                                                                                (S8)g_java.mids_setting.permission_local_connectivity);
                break;
#ifdef SUPPORT_JSR_179
            case J2ME_SETTING_LOCATION_ACCESS:
                g_java.mids_setting.permission_location_access = mmi_java_get_new_permission_level((S8) g_java.mids_choice_index[i],
                                                                                (S8)g_java.mids_max_setting.permission_location_access,
                                                                                (S8)g_java.mids_setting.permission_location_access);
                break;
#endif
#ifdef SUPPORT_JSR_177
            case J2ME_SETTING_SATSA:
              g_java.mids_setting.permission_satsa = mmi_java_get_new_permission_level((S8) g_java.mids_choice_index[i],
                                                                              (S8)g_java.mids_max_setting.permission_satsa,
                                                                              (S8)g_java.mids_setting.permission_satsa);
              break;
#endif
#ifdef SUPPORT_JSR_257
            case J2ME_SETTING_CONTACTLESS_COMMUNICATION:
                g_java.mids_setting.permission_contactless_communication = mmi_java_get_new_permission_level((S8) g_java.mids_choice_index[i],
                                                                                (S8)g_java.mids_max_setting.permission_contactless_communication,
                                                                                (S8)g_java.mids_setting.permission_contactless_communication);
                break;
#endif
          }
    }

    #ifdef OGDR_SECURITY_SETTING
    if (g_java.domain >= 0 )
    {
        //mmi_java_send_set_default_domain_req();
    }
    else
    #endif
    {
        vapp_java_send_mids_set_setting_req();
    }
}


extern "C" VappJavaMidsSettingPage* 
vapp_java_get_detail_page_instance(void)
{
    return SettingPage;
}

extern "C" void vapp_java_nw_get_local_setting_rsp(void* MsgStruct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_java_nw_get_local_setting_rsp_struct *rsp_ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_NW_GET_LOCAL_SETTING_RSP);
    ASSERT (MsgStruct != NULL);
    
    vapp_java_send_get_setting_req();
    
    rsp_ptr = (mmi_java_nw_get_local_setting_rsp_struct *) MsgStruct;
    MMI_TRACE(MMI_TRACE_STATE, INFO_MMI_JAVA_NW_STATE_D, rsp_ptr->error_code);
    if (rsp_ptr->error_code != NW_OP_NO_ERR)
    {
        //mmi_popup_display_simple((WCHAR*)((UI_string_type)GetString(STR_GLOBAL_BUSY_TRY_LATER)), MMI_EVENT_PROGRESS, g_mmi_java_nw_cntx.sg_id_parent, NULL);
        return;
    }
}

extern "C" void vapp_java_event_init(void)
{
    SetProtocolEventHandler((PsFuncPtr) vapp_java_nw_get_local_setting_rsp, MSG_ID_MMI_JAVA_NW_GET_LOCAL_SETTING_RSP);
}
typedef struct vapp_java_popup_param_struct_t{
    vapp_java_entry_after_popup_enum entry;
    vapp_java_popup_type_enum type;
    VfxResId str_id;
    WCHAR* text;    
} vapp_java_popup_param_struct;

void vapp_java_display_popup_cb(VfxId id, void *userData)
{
    VappJavaHelper* ptrVappJavaHelper = (VappJavaHelper*)userData;
    if(ptrVappJavaHelper == NULL) return;
    if( id ==  VCP_POPUP_BUTTON_NO_PRESSED)
    {
        ptrVappJavaHelper->setHomekeyPressed(VFX_TRUE);
    }
    if(!vappjavaHelper.getSkip())
    {
        ptrVappJavaHelper->switchEntry();
    }
    else
    {
        vappjavaHelper.setSkip(VFX_FALSE);
    }
    g_vjava_global_popup = GRP_ID_INVALID;
}


extern "C" void vapp_java_display_popup(S32 str_id,S32 type,vapp_java_entry_after_popup_enum entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VcpPopupTypeEnum event_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(type)
    {
        case VJAVA_POPUP_FAILURE:
            event_type = VCP_POPUP_TYPE_FAILURE;
            break;
        case VJAVA_POPUP_INFO:
            event_type = VCP_POPUP_TYPE_INFO;
            break;
        case VJAVA_POPUP_WARNING:
            event_type = VCP_POPUP_TYPE_WARNING;
            break;
        case VJAVA_POPUP_SUCCESS:
            event_type = VCP_POPUP_TYPE_SUCCESS;
            break;
        case VJAVA_POPUP_QUESTION:
            event_type =VCP_POPUP_TYPE_QUESTION;
            break;
        default:
            event_type = VCP_POPUP_TYPE_INFO;
    }
    if(entry != VAPP_JAVA_ENTRY_SKIP)
    {
        vappjavaHelper.setEntry(entry);
    }
    else
    {
        vappjavaHelper.setSkip(VFX_TRUE);
    }
    vcp_global_popup_cancel(g_vjava_global_popup);
    g_vjava_global_popup = vapp_nmgr_global_popup_show_confirm_one_button_id(
        MMI_SCENARIO_ID_DEFAULT,
        event_type, 
        str_id,
        STR_GLOBAL_OK,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        &vapp_java_display_popup_cb,
        (void*)&vappjavaHelper);
}
extern "C" void vapp_java_display_popup_str(WCHAR* str,S32 type,vapp_java_entry_after_popup_enum entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VcpPopupTypeEnum event_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(type)
    {
        case VJAVA_POPUP_FAILURE:
            event_type = VCP_POPUP_TYPE_FAILURE;
            break;
        case VJAVA_POPUP_INFO:
            event_type = VCP_POPUP_TYPE_INFO;
            break;
        case VJAVA_POPUP_WARNING:
            event_type = VCP_POPUP_TYPE_WARNING;
            break;
        case VJAVA_POPUP_SUCCESS:
            event_type = VCP_POPUP_TYPE_SUCCESS;
            break;
        case VJAVA_POPUP_QUESTION:
            event_type =VCP_POPUP_TYPE_QUESTION;
            break;
        default:
            event_type = VCP_POPUP_TYPE_INFO;
    }        
    vappjavaHelper.setEntry(entry);
    vapp_nmgr_global_popup_show_confirm_one_button_str(
         MMI_SCENARIO_ID_DEFAULT,
         event_type, 
        VFX_WSTR_MEM(str), 
        VFX_WSTR_RES(STR_GLOBAL_OK), 
         VCP_POPUP_BUTTON_TYPE_NORMAL,
        &vapp_java_display_popup_cb,
        (void*)&vappjavaHelper);    
}


extern "C" void vapp_java_get_mids_info_by_app_name(CHAR * app_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 mids_id = -1;
    kal_char storage_name[LEN] ={0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_java_appfactory_get_storage_name_by_app_name(storage_name, app_name);
    ASSERT(storage_name!= NULL);
    mids_id = jam_call_back_functions.jam_get_mids_id_from_storage_name(storage_name);
    
    needToSendGetListReq = MMI_TRUE;
    g_java.mids_info_end = g_java.mids_info_start = -1;
    g_java.mids_list_filter.filter_type = JAM_NONE_FILTER;
    g_java.total_java_app_mids = mids_id;
    mmi_java_fetch_mids_list(mids_id - 1, (UI_string_type) NULL, (PU8*) NULL, 0);
    g_java.mids_index = mids_id - 1;
    g_java.mid_index = 0;
}


 extern "C" void vapp_java_fmgr_info_hdlr(const WCHAR* filepath, java_get_file_info_callback fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT( filepath != NULL );
    mmi_java_local_install_content_routing((U16*)filepath);
}

extern "C" kal_bool vapp_java_display_is_busy(void)
{
    vapp_java_display_popup(STR_ID_VAPP_JAVA_VM_BUSY,VJAVA_POPUP_WARNING,VAPP_JAVA_ENTRY_CLOSE_JAVA_APP);
    return KAL_TRUE;
}


extern "C" kal_bool  vapp_java_check_and_display_is_busy(void)
{
    if (jam_is_busy())
    {
        vapp_java_display_popup(STR_ID_VAPP_JAVA_VM_BUSY,VJAVA_POPUP_WARNING,VAPP_JAVA_ENTRY_CLOSE_JAVA_APP);
        return KAL_TRUE;
    }
    return KAL_FALSE;
}

extern "C" mmi_ret vapp_java_volume_event_hdlr(mmi_event_struct *evt)
{
    srv_prof_evt_vol_change_struct * volChangeEvt = NULL;
    vapp_vol_dialog_evt_struct *volEvent = NULL;
    
    kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_VOLUME_EVENT_HDLR,evt->evt_id,0);
    switch(evt->evt_id)
    {
        case EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE:      
        {
            volEvent = (vapp_vol_dialog_evt_struct*) evt;
            if (volEvent->type == VAPP_VOL_DIALOG_IS_MEDIA && jma_audio_player_is_really_active())
            {
                kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_VOLUME_EVENT_HDLR,evt->evt_id,1);
                return !MMI_RET_OK;
            }
            else
            {
            kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_VOLUME_EVENT_HDLR,evt->evt_id,2);
                return MMI_RET_OK;
            }
            break;
        }
        case EVT_ID_SRV_PROF_VOL_CHANGED:
            volChangeEvt = (srv_prof_evt_vol_change_struct*)evt;
            if(SRV_PROF_VOL_MEDIA == volChangeEvt->vol_type)
            {
                g_mmi_java_aud_volume_level = MDI_AUD_VOL_GET_EX_LEVEL(srv_prof_get_media_vol());
                kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_VOLUME_EVENT_HDLR,evt->evt_id,3);
                return MMI_RET_OK;
            }
            break;
        default:
            kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_VOLUME_EVENT_HDLR,evt->evt_id,4);
            break;
    }

}


extern "C" mmi_ret vapp_java_gpio_event_hdlr(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN:
            return MMI_RET_ERR;
        default:
            break;
    }    
    return MMI_RET_OK;
}


extern "C" void vapp_java_disable_lock_screen(void)
{
    mmi_frm_cb_reg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, vapp_java_gpio_event_hdlr, NULL);    
}


extern "C" void vapp_java_enable_lock_screen(void)
{
    mmi_frm_cb_dereg_event(EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN, vapp_java_gpio_event_hdlr, NULL);    
}


#endif/*__J2ME__*/

