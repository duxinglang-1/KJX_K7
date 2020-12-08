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
#include "vapp_javaagencysrc.h"
#include "Vapp_JavaAgencyMidsInstall.h"
#include "Vapp_java_srv.h"

extern "C"
{
#include "MMI_include.h"
#include "MMI_features.h" 
#include "jam_msg_handler.h"
#include "Drm_gprot.h"
#include "Jvm_interface.h"
#include "AppMgrSrvGprot.h"
#include "FileMgrSrvGprot.h"
#include "RightsMgrGProt.h"
#include "mmi_rp_vapp_java_def.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/       
extern "C" void vapp_java_entry_delete_mids_menu_confirm(void)
{
}
extern "C" void vapp_java_entry_terminate_vm_confirm(void)
{
    kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_ENTRY_TERMINATE_VM_CONFIRM,0);
    
#if defined(J2ME_SLIM_MEMORY_SUPPORT) 
		vapp_java_catscr_entry(VJAVA_MID_STOP_RUNNING);  
#else
    vapp_java_entry(VJAVA_MID_STOP_RUNNING);  
#endif
      

/*    if(!mmi_java_is_allow_to_popup_screen()||
       VappJavaAgency::getInstance()==NULL||
       VappJavaAgency::getInstance()->install_is_active() == VFX_FALSE)
    {                                     
        mmi_java_mids_install_ask_terminate_cb(MMI_FALSE);
        vapp_java_close_venus_screen();
        return;
    }                                   
    if (jam_mvm_is_vm_running(g_mmi_java_install_terminate_vm_id) || jam_mvm_is_vm_terminating(g_mmi_java_install_terminate_vm_id))
    {                                 
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_ENTRY_TERMINATE_VM_CONFIRM,1);
        g_java.screen_after_terminate = TER_ENTRY_INSTALL_JAVA; 
        VappJavaAgency::getInstance()->get_install_screen()->terminateRunningDialog();                              
    }                                     
    else                                  
    {                                                                              
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_ENTRY_TERMINATE_VM_CONFIRM,2);
        g_mmi_java_install_terminate_vm_id = -1;
        g_java.screen_after_terminate = TER_ENTRY_NONE; 
        vfxPostInvoke0(&vappjavaHelper,&VappJavaHelper::reEntryInstall);
    }                                     
 */
}
extern "C" void vapp_java_entry_select_install_drv(void)
{
    kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_ENTRY_SELECT_DRV,0);
    if(VappJavaAgency::getInstance() == NULL)
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_ENTRY_SELECT_DRV,1);
        return;
    }
    VappJavaAgency::getInstance()->get_install_screen()->selectInstallDrv();
}                             
extern "C" void vapp_java_update_install_progress_bar(S32 value)                                  
{     
    kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_UPDATE_PROGRESS_BAR,0);
    if(VappJavaAgency::getInstance() == NULL)
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_UPDATE_PROGRESS_BAR,1);
        return;
    }
    if(VappJavaAgency::getInstance()->get_install_screen()== NULL)
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_UPDATE_PROGRESS_BAR,2);
        return;
    }
    VappJavaAgency::getInstance()->get_install_screen()->updateProgress((VfxFloat)(value/100.0));                            
}                                     
extern "C" void vapp_java_entry_mids_install_confirm(U16* str)                                            
{                                         
    kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_ENTRY_INSTALL_CONFIRM,0);
    if(VappJavaAgency::getInstance() == NULL)
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_ENTRY_INSTALL_CONFIRM,1);
        return;
    }
    VappJavaAgency::getInstance()->get_install_screen()->showConfirmDialog(str);
}      

extern "C" void  vapp_java_entry_mids_install_start(void)
{
    kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_ENTRY_INSTALL_START);
    vapp_java_entry(VJAVA_INSTALL);
}

extern "C" void vapp_java_entry_reset_rms_res(void)
{                                         
    kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_ENTRY_RMS_CONFIRM,0);
    if(VappJavaAgency::getInstance() == NULL)
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_ENTRY_RMS_CONFIRM,1);
        return;
    }
    VappJavaAgency::getInstance()->get_install_screen()->rmsConfirmDialog();
}


extern "C" void vapp_java_entry_auth(void)
{
    kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_ENTRY_INSTALL_AUTH,0);
    if(VappJavaAgency::getInstance() == NULL)
    {
        kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_ENTRY_INSTALL_AUTH,1);
        return;
    }
    VappJavaAgency::getInstance()->get_install_screen()->showAuthDialog();
}
extern "C" void vapp_java_entry_push_install_confirm(void)
{   
    kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_ENTRY_PUSH_INSTALL,0);
    vapp_java_entry(VJAVA_PUSH_INSTALL);
}                                     
                                          
extern "C" void vapp_java_entry_dm_install_confirm(void)
{
    kal_trace(JAM_JAVAAGENCY_GROUP,VAPP_JAVA_ENTRY_DM_INSTALL,0);
    vapp_java_entry(VJAVA_DM_INSTALL);
}                                         
                                          
void vapp_java_fmgr_install_hdlr(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 app_id = 0, icon_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT( filepath != NULL );
#ifdef __DRM_SUPPORT__
    if(!mmi_java_fmgr_check_drm_rights((U16 *)filepath, DRM_PERMISSION_EXECUTE, icon_id))
    {
        return;
    }
#endif 
    mmi_java_local_install_content_routing((kal_uint16*) filepath);
}
 
#endif                                        
