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
 *   widget_view_ui.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements widget view UI presentation
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_GADGET_SUPPORT__

extern "C"
{
#include "stack_common.h"  
#include "stack_msgs.h"
#include "app_ltlcom.h"       	/* Task message communiction */
#include "task_config.h"      	/* Task creation */

#include "Conversions.h"
#include "ProfilesSrvGprot.h"
#include "med_utility.h"    // TODO: remove this after using VRT memory API
#include "mmi_rp_vapp_widget_delegator_def.h"
#include "widget_adp_struct.h"
#include "idlegprot.h"

#include "gadget_adp_audio_service.h"
#include "gadget_adp_avplugin.h"

#include "gdi_datatype.h"    
#include "gdi_const.h"    
#include "MMIDataType.h"    
#include "kal_public_defs.h"    
#include "GlobalConstants.h"    
#include "kal_general_types.h"    
#include "mmi_frm_input_gprot.h"    
#include "stack_config.h"    
#include "stack_msgs.h"    
#include "app_ltlcom.h"    
#include "stack_ltlcom.h"    
#include "kal_public_api.h"    
#include "mmi_frm_scenario_gprot.h"    
#include "mmi_frm_mem_gprot.h"    
#include "string.h"    
#include "gdi_include.h"    
#include "mmi_frm_history_gprot.h"    
#include "GlobalResDef.h"    
#include "CustDataRes.h"    
#include "mmi_frm_events_gprot.h"    
#include "AlertScreen.h"    
#include "wgui_categories.h"    
#include "gui.h"    
#include "med_smalloc.h"    
#include "wgui_categories_util.h"

#include "cache_sw.h"
#include "custom_gadget_config.h"

#include "WgtMgrSrvGprot.h"
#include "WgtMgrSrvIprot.h"

#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGprot.h"
#endif
}

#include "vapp_widget_adp.h"
     
#include "vfx_uc_include.h"
#include "vcp_include.h"

#include "vapp_widget_view.h"
#include "vapp_widget_delegator.h"
#include "vapp_widget_popup_controller.h"
#include "vapp_widget_editor.h"
#include "vapp_widget_defs.h"

#include "vadp_asm.h"
#include "mmi_rp_vapp_launcher_cosmos_def.h"
#include "vapp_widget_factory.h"
#include "vapp_widget_kit.h"
#include "vapp_launcher_app.h"

#include "mmi_rp_vapp_vol_dialog_def.h"  /* Add for volume event */
#include "vapp_vol_dialog_gprot.h"      /* Add for volume event */
 
#include "NativeAppFactorySrvGprot.h"   /* For OOM's dynamic resource */

#ifdef __MMI_USB_SUPPORT__
#include "vapp_usb_gprot.h"
#endif

#include "Vcp_global_popup.h"
#include "vapp_nmgr_gprot.h"

#include "gadget_adp_log.h"

/*****************************************************************************
 * Static Declaration
 *****************************************************************************/
/* Record in an application launching process or not */
static VfxBool g_widget_view_launch = VFX_FALSE;

/* View notify engine to free flag */
static VfxBool g_widget_view_notify_free = VFX_FALSE;

/* Main menu launch process completed flag */
static VfxBool g_widget_view_main_menu_wait_msg = VFX_FALSE;

/* Main menu widget id */
VfxS32 VappWidgetView::m_mainmenuId = 0;

/* Widget id */
VfxS32 VappWidgetView::m_widgetId = 0 ;

/* Widget view handle */
void *VappWidgetView::m_viewHandle = NULL;

/* Widget view type */
VfxS32 VappWidgetView::m_viewType = 0;

/* Image buffer mutext */
kal_mutexid VappWidgetViewPage::m_imageBufferMutex = 0;

/* A static state variable to record page status */
WidgetViewPageState VappWidgetViewPage::m_state = WIDGET_VIEW_PAGE_STATE_EXIT;

/*****************************************************************************
 * Function
 *****************************************************************************/
#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
#endif /*__MTK_INTERNAL__ */

extern "C" int gadget_adp_view_get_visible_area(kal_int32 *x, kal_int32 *y, kal_int32 *width, kal_int32 *height)
{
    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    if (!viewApp || !viewApp->getTopScreen() || !viewApp->getActivePage())
    {
        return -1;
    }

    *x = viewApp->getTopScreen()->getRect().getX();
    *y = viewApp->getTopScreen()->getRect().getY();
    *width = viewApp->getActivePage()->getRect().getWidth();
    *height = viewApp->getActivePage()->getRect().getHeight();

    return 0;
}

extern "C" int gadget_adp_view_get_screen_handle(gdi_handle * handle1, gdi_handle * handle2, gdi_handle *handle3)
{
    return 0;
}

extern "C" int gadget_adp_is_in_meeting_or_silent_mode(void)
{
    return (srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE) || srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE));
}

extern "C" int gadget_adp_view_get_screen_orientation(void)
{
    return 0;
}

extern "C" int gadget_adp_view_get_absolute_pos(int *x, int* y)
{

    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    if (!viewApp)
    {
        return -1;
    }

    *x = viewApp->getTopScreen()->getRect().getX();
    *y = viewApp->getTopScreen()->getRect().getY();

    return 0;
}

extern "C" unsigned int gadget_adp_view_get_transparent_color(void)
{
    return GDI_COLOR_TRANSPARENT;
}

extern "C" VfxFrame *gadget_adp_view_get_image_frame_ptr()
{
    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    if (!viewApp)
    {
        return NULL;
    }

    VappWidgetViewPage *page = (VappWidgetViewPage *)viewApp->getActivePage();

    VFX_ASSERT(page != NULL);

    return page->getImageFramePtr();
}

extern "C" VfxPage *gadget_adp_view_get_parent_object()
{
    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    if (!viewApp)
    {
        return NULL;
    }

    VfxPage *parentObj = (VfxPage *)viewApp->getActivePage();

    VFX_ASSERT(parentObj != NULL);

    return parentObj;
}

extern "C" void vapp_widget_view_send_message(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id, module_type dst_id)
{
    ilm_struct *ilm_ptr = NULL;

    /* allocate ilm */
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) local_para_ptr;
    ilm_ptr->msg_id = ilm_id;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;

    SEND_ILM(MOD_MMI, dst_id, MMI_GADGET_SAP, ilm_ptr);
}

void vapp_widget_launch_result_callback(VfxAppLauncherResultEnum result, void *userData)
{
    if (result == VFX_APP_LAUNCHER_RESULT_CANCEL)
    {
        g_widget_view_launch = VFX_FALSE;

        vapp_widget_close_view(VappWidgetView::m_widgetId, VappWidgetView::m_viewHandle, VappWidgetView::m_viewType, 0);
    }
}

void vapp_widget_launch_details_view_in_main_menu(void *param)
{
    g_widget_view_main_menu_wait_msg = VFX_FALSE;

    vapp_widget_set_ignore_load_rsp_flag(false);

    // Send a confirm message to gadget to avoid blocking 
    vapp_widget_view_send_message(NULL, NULL, MSG_ID_WIDGET_SHOW_VIEW_CNF, MOD_GADGET);

    /* Find widget delegator app and check it exist or not */
    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    if (viewApp)
    {
        widget_show_view_ind_struct *widgetShowViewInd = (widget_show_view_ind_struct *)param;
        viewApp->onInitView(widgetShowViewInd, VFX_TRUE);
    }

}

extern "C" kal_bool vapp_widget_launch_in_main_menu(int id)
{
    //
    // 1.  Check if it is usb storage mode
    //
#ifdef __MMI_USB_SUPPORT__	
    if (srv_usb_is_in_mass_storage_mode())
    {
        vapp_usb_unavailable_popup(0);      
        return KAL_FALSE;
    }
#endif

    g_widget_view_launch = VFX_TRUE;

    g_widget_view_main_menu_wait_msg = VFX_TRUE;

    vapp_widget_set_ignore_load_rsp_flag(true);    

    //
    // 2. Find widget delegator app and check it exist or not 
    //

    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    if (viewApp)
    {
        VfxAppLauncher::terminate(viewApp->getGroupId());
    }

    VappWidgetView::m_mainmenuId = id;
    
    //
    // 3.  Launch widget delegator application 
    //
    vapp_widget_initialize();
    VfxAppLauncher::launch( 
                        VAPP_WIDGET_DELEGATOR,                  /*app id = VAPP_WIDGET_DELEGATOR*/
                        VFX_OBJ_CLASS_INFO(VappWidgetView),
                        GRP_ID_ROOT, 
                        NULL, 
                        0);
    return KAL_TRUE;
}

void vapp_widget_launch_details_view(void *param)
{
    // Send a confirm message to gadget to avoid blocking 
    vapp_widget_view_send_message(NULL, NULL, MSG_ID_WIDGET_SHOW_VIEW_CNF, MOD_GADGET);

    //
    // 1. Check if launch in main menu, if yes. return directly to avoid async. problem.
    //
    widget_show_view_ind_struct *p = (widget_show_view_ind_struct *)param;

    if (g_widget_view_main_menu_wait_msg == VFX_TRUE)
    {

        g_widget_view_main_menu_wait_msg = VFX_FALSE;

        vapp_widget_close_view(p->instance_id, p->view_handle, p->type, 0);

        vapp_widget_set_ignore_load_rsp_flag(true);

        return ;
    }

    //
    // 2. Check if the widget is vaild or not to avoid widget has been unloaded
    //
    VappWidgetDelegator *widget = 
        VappWidgetDelegator::findByInstancId(p->instance_id);

    if (!widget)
    {
        vapp_widget_close_view(p->instance_id, p->view_handle, p->type, 0);

        return;
    }


    /* Set launching flag */ 
    g_widget_view_launch = VFX_TRUE;

    //
    // 3. Check if the active screen is home screen
    //

    /* Get home app and its group id */
    VfxApp *homeApp = 
        (VfxApp *) VfxAppLauncher::findApp(VAPP_LAUNCHER, VFX_OBJ_CLASS_INFO(VappLauncherApp), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    /* Check if active group is home app or not */
    if (homeApp->getGroupId() != mmi_frm_group_get_active_id())
    {
        g_widget_view_launch = VFX_FALSE;

        vapp_widget_close_view(p->instance_id, p->view_handle, p->type, 0);

        return ;
    }

    //
    // 4. Find widget delegator app and check it exist or not 
    //
    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    if (viewApp)
    {
        VfxAppLauncher::terminate(viewApp->getGroupId());
    }

    //
    // 5.  Launch widget delegator application 
    //
    /*VfxAppLauncher::launch( 
                        VAPP_WIDGET_DELEGATOR,                  
                        VFX_OBJ_CLASS_INFO(VappWidgetView),
                        GRP_ID_ROOT, 
                        param, 
                        sizeof(widget_show_view_ind_struct));*/

    VfxAppLauncherParam launch_param(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), GRP_ID_ROOT);
    launch_param.setArgument(param, sizeof(widget_show_view_ind_struct));
    VappWidgetView::m_widgetId = p->instance_id;
    VappWidgetView::m_viewHandle = p->view_handle;
    VappWidgetView::m_viewType = p->type;
    launch_param.setLauncherResultCb(vapp_widget_launch_result_callback, NULL);
    VfxAppLauncher::launchEx(launch_param);
        
}

void vapp_widget_view_check_load_result(int result)
{
    /* Find widget delegator app and check it exist or not */
    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    if (viewApp)
    {
        viewApp->checkLoadResult(result);
    }
}

void vapp_widget_view_repaint(void * param)
{
    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    if (viewApp)
    {
        /* Call onUpdatePage to update widget content */
        viewApp->onUpatePage(param);
    }
}

void vapp_widget_view_handle_terminate_all_ind(void * param)
{
    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    if (viewApp)
    {
        /* Call terminate to close widget application */
        viewApp->terminateAll(param);
    } 

    vapp_widget_view_send_message(NULL, NULL, MSG_ID_WIDGET_TERMINATE_ALL_WGT_CNF, MOD_GADGET);
}

void vapp_widget_view_handle_terminate_ind(void * param)
{
    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    if (viewApp)
    {
        /* Call terminate to close widget application */
        viewApp->terminate(param);
    } 
}

void vapp_widget_view_terminate_callback(VfxId id, void *userData)
{
    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    if (viewApp)
    {
        viewApp->terminateCallback();
    }   
}

void vapp_widget_file_not_exist_callback(VfxId id, void *userData)
{
    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    if (viewApp)
    {
        viewApp->exit();
    }   

    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1 || id == VCP_CONFIRM_POPUP_BUTTON_OK)
    {
        srv_wgtmgr_delete_wgt(VappWidgetView::m_mainmenuId, NULL, NULL);
    }
}


void vapp_widget_close_view_handler(void * param)
{
    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    if (!viewApp)
    {
        return;        
    }

    viewApp->closeView(param);
}

VfxS32 vapp_widget_close_view_by_id(int instance_id)
{
    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    if (!viewApp)
    {
        return 0;
    }

    return viewApp->closeById(instance_id);
}

void vapp_widget_close_main_menu_view()
{
    //Check if any view launch by mainmenu, if yes, close it
    vapp_widget_close_editor_by_id(VappWidgetView::m_mainmenuId);
    vapp_widget_close_view_by_id(VappWidgetView::m_mainmenuId);       
}

VfxBool vapp_widget_is_view_notify_to_free_handler()
{
    if (g_widget_view_notify_free)
    {
        g_widget_view_notify_free = VFX_FALSE;

        VappWidgetView *viewApp = 
            (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);
        
        if (viewApp)
        {
            viewApp->continueClose(VFX_APP_CLOSE_ANSWER_YES);
        }

        return VFX_TRUE;
    }

    return VFX_FALSE;
}

/* Used for gadget engine to determine has launching/entering details view or not */
VfxBool vapp_widget_is_details_view_launched(void)
{
    return g_widget_view_launch;
}

extern "C" mmi_ret vapp_widget_delegator_proc (mmi_event_struct *param)
{
    VappWidgetView *viewApp = 
        (VappWidgetView *) VfxAppLauncher::findApp(VAPP_WIDGET_DELEGATOR, VFX_OBJ_CLASS_INFO(VappWidgetView), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);

    if (viewApp)
    {
        // Only process app name query event
        if (param->evt_id == EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_NAME)
        {
            srv_nativeappfactory_query_app_name_evt_struct *evt = (srv_nativeappfactory_query_app_name_evt_struct*)param;

            VfxWChar *nameStr = viewApp->getWidgetName();

            if (nameStr)
            {
                mmi_wcsncpy((*evt).app_string, (const WCHAR*)nameStr, WIDGET_MAX_NAME_LENGTH);

                VFX_FREE_MEM(nameStr);
                
                return MMI_RET_OK;                
            }
        }
    }
    return MMI_RET_DONT_CARE;
}


// VappWidgetView Implementation
VFX_IMPLEMENT_CLASS("VappWidgetView", VappWidgetView, VfxApp);

VappWidgetView::VappWidgetView():
    m_screen(NULL),
    m_viewFlags(0),
    m_viewWidth(0),
    m_viewHeight(0),
    m_closedByEngine(VFX_FALSE),
    m_exceptionOccured(VFX_FALSE),
    m_viewResponse(0),
    m_pageState(WIDGET_VIEW_PAGE_STATE_NONE), 
	m_prepared(VFX_TRUE),
	m_mainmenu(VFX_FALSE)
{
    m_widgetId = 0; 
    m_viewHandle = NULL;
    m_viewType = 0;
}

void VappWidgetView::onRun(void * args, VfxU32 argSize)
{
    // Call VfxApp's onRun
    VfxApp::onRun(args, argSize);

    if (argSize == sizeof(widget_show_view_ind_struct))
    {
        widget_show_view_ind_struct *widgetShowViewInd = (widget_show_view_ind_struct *)args;
        onInitView(widgetShowViewInd, VFX_FALSE);
    }
    else if (argSize == sizeof(widget_enter_text_ind_struct))
    {
        widget_enter_text_ind_struct *widgetEnterTextInd = (widget_enter_text_ind_struct*)args;
        onInitEditorPage(widgetEnterTextInd);
    }
    else
    {
        m_mainmenu = VFX_TRUE;
        m_widgetId = m_mainmenuId;

        if (checkWidgetIsValid(m_mainmenuId))
        {
            // Create and display main screen
            if (!m_screen)
            {
                VFX_OBJ_CREATE(m_screen, VappWidgetViewMainScr, this);
                m_screen->setAutoClose(VFX_TRUE);
                m_screen->m_signalLeaved.connect(this, &VappWidgetView::onLeaveMainScr);
            }

            // Create page and connect the related signal
            VappWidgetViewPage *page = (VappWidgetViewPage *)m_screen->createWidgetViewPage();
            page->m_signalStateChanged.connect(this, &VappWidgetView::onPageStateChanged);
            page->m_singalKeyInput.connect(this, &VappWidgetView::onPageKeyInput);
            page->m_singalPenInput.connect(this, &VappWidgetView::onPagePenInput);
            m_screen->show();
        }
    }

    // Register EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE callback for avplugin
    mmi_frm_cb_reg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, &VfxApp::static_proc, this);

}

void VappWidgetView::onInitView(widget_show_view_ind_struct *widgetShowViewInd, VfxBool mainmenu)
{
	srv_wgtmgr_hold_bearer();

    VappWidgetDelegator *widget = 
        VappWidgetDelegator::findByInstancId(widgetShowViewInd->instance_id);

    if (widget)
    {
        // Set widget's view type
        widget->setViewType(WIDGET_DETAIL_VIEW);
    }

    m_mainmenuId = widgetShowViewInd->instance_id; 

    // Record the message's local parameter information 
    m_widgetId = widgetShowViewInd->instance_id;
    m_viewHandle = widgetShowViewInd->view_handle;
    m_viewWidth = widgetShowViewInd->width;
    m_viewHeight = widgetShowViewInd->height;
    m_viewType = widgetShowViewInd->type;
    m_viewFlags = widgetShowViewInd->flags;
    m_resizeRatio = VappWidgetDelegator::getResizeRatio(m_widgetId);

    // Set widget details view title
    if (widgetShowViewInd->caption[0])
    {
        mmi_chset_utf8_to_ucs2_string(
            (U8*) m_viewCaption,
            sizeof(m_viewCaption),
            (U8*) widgetShowViewInd->caption);
    }

    if (!mainmenu)
    {
        // Create and display main screen
        if (!m_screen)
        {
            VFX_OBJ_CREATE(m_screen, VappWidgetViewMainScr, this);
            m_screen->setAutoClose(VFX_TRUE);
            m_screen->m_signalLeaved.connect(this, &VappWidgetView::onLeaveMainScr);
        }

        // Create page and connect the related signal
        VappWidgetViewPage *page = (VappWidgetViewPage *)m_screen->createWidgetViewPage();
        page->m_signalStateChanged.connect(this, &VappWidgetView::onPageStateChanged);
        page->m_singalKeyInput.connect(this, &VappWidgetView::onPageKeyInput);
        page->m_singalPenInput.connect(this, &VappWidgetView::onPagePenInput);
        m_screen->show();
    }
    else if (m_pageState == WIDGET_VIEW_PAGE_STATE_ENTER)
    {
        showPage();
    }

}

void VappWidgetView::onInitEditorPage(widget_enter_text_ind_struct *param)
{
    // Create and display main screen
    if (!m_screen)
    {
        VFX_OBJ_CREATE(m_screen, VappWidgetViewMainScr, this);
        m_screen->setAutoClose(VFX_TRUE);
    }
    
    // Create page for editor
    VappWidgetEditorPage *page = (VappWidgetEditorPage *)m_screen->createWidgetEditorPage();
    page->createEditor(param);
    m_screen->show();
}

void VappWidgetView::closeEditorPage()
{
    if (m_screen)
    {
        m_screen->closeWidgetEditorPage();
    }
}

void VappWidgetView::onDeinit()
{
	srv_wgtmgr_release_bearer();

    setEventHandler(VFX_FALSE);
    onLeaveMainScr(VFX_TRUE);

    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_SHOW_VIEW_IND, (PsIntFuncPtr)vapp_widget_launch_details_view, KAL_FALSE);

    VappWidgetDelegator *widget = 
        VappWidgetDelegator::findByInstancId(m_widgetId);

    if (widget)
    {
        widget->setViewType(WIDGET_IDLE_VIEW);
    }

    // Deregister EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE callback for avplugin
    mmi_frm_cb_dereg_event(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, &VfxApp::static_proc, this);

    // Set widget details view launch flag to false
    g_widget_view_launch = VFX_FALSE;

    if (m_mainmenu /*&& !widget*/)
    {
        widget_unload_widget(m_mainmenuId);
    }

    vapp_widget_disable_view_cache(VFX_TRUE, VFX_FALSE);

    m_widgetId = 0; 
    m_viewHandle = NULL;
    m_viewType = 0;

    VfxApp::onDeinit();
}

VfxAppCloseAnswerEnum VappWidgetView::onProcessClose(VfxAppCloseOption options)
{
    if (options & VFX_APP_CLOSE_OPTION_NO_FLAG) /* press home key */
    {
        return VFX_APP_CLOSE_ANSWER_YES;
    }
    else
    {
        m_prepared = VFX_FALSE;

        if (custom_gadget_using_asm() == KAL_TRUE)
        {
            if (vapp_widget_is_wait_asm_rsp() == VFX_TRUE)
            {
                return VFX_APP_CLOSE_ANSWER_YES;
            }

            g_widget_view_notify_free = VFX_TRUE;

            vapp_widget_send_message(NULL, NULL, MSG_ID_WIDGET_FREE_ASM_REQ, MOD_GADGET);

            return VFX_APP_CLOSE_ANSWER_LATER;
        }
        else
        {
            return VFX_APP_CLOSE_ANSWER_YES;
        }
    }

    return VfxApp::onProcessClose(options);
}

void VappWidgetView::continueClose(VfxAppCloseAnswerEnum answer)
{
    VfxApp::continueClose(answer);
}

VfxBool VappWidgetView::checkWidgetIsValid(VfxS32 id)
{
    m_mainmenuId = id;
    
    if (srv_wgtmgr_check_downloaded_wgt(id) != SRV_WGTMGR_RET_OK)
    {
        srv_wgtmgr_wgt_drive_enum drive = srv_wgtmgr_get_downloaded_wgt_installed_drive(id);

        if (drive != WIDGET_MGR_DRIVE_MEMORY_CARD)
        {
            // Show a popup to notify user exception occured due to file not exist
            vapp_nmgr_global_popup_show_confirm_one_button_id(
                MMI_SCENARIO_ID_DEFAULT, 
                VCP_POPUP_TYPE_FAILURE, 
                STR_ID_VAPP_LAUNCHER_COSMOS_FILE_NOT_EXISTS_AND_WILL_BE_REMOVED, 
                STR_GLOBAL_OK, 
                VCP_POPUP_BUTTON_TYPE_NORMAL, 
                vapp_widget_file_not_exist_callback, 
                &m_mainmenuId);

        }
        else
        {
            // Show a popup to notify user exception occured due to file not exist
            vapp_nmgr_global_popup_show_confirm_two_button_str(
                MMI_SCENARIO_ID_DEFAULT,
                VCP_POPUP_TYPE_QUESTION,
                VFX_WSTR_RES(STR_ID_VAPP_LAUNCHER_COSMOS_FILE_NOT_EXISTS),
                VFX_WSTR_RES(STR_GLOBAL_DELETE),
                VFX_WSTR_RES(STR_ID_VAPP_LAUNCHER_COSMOS_KEEP_IT),
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                VCP_POPUP_BUTTON_TYPE_NORMAL,
                vapp_widget_file_not_exist_callback,
                &m_mainmenuId);

        }
        return VFX_FALSE;
    }

    return VFX_TRUE;
}

void VappWidgetView::checkLoadResult(VfxS32 result)
{
    if (result == 0)
    {
        return ;
    }

    VappWidgetPopupController *controller;

	switch(result)
	{
    case WIDGET_WAIT_FOR_UNLOADING:
        vapp_widget_load_widget(m_widgetId, 1);
        return;

	case WIDGET_PERMISSION_NOT_GRANTED:
        // Show a popup to notify user exception occured due to permission not granted
        VFX_OBJ_CREATE(controller, VappWidgetPopupController, getTopScreen());
        controller->setCallback(vapp_widget_view_terminate_callback, NULL);        
        
        controller->showPopupWithOk(
            getTopScreen(), 
            VFX_WSTR_RES(STR_ID_VAPP_WIDGET_PERMISSION_NOT_GRANTED));
       
        return;
    case WIDGET_PATH_NOT_FOUND:
        // Show a popup to notify user exception occured due to widget path not found
        VFX_OBJ_CREATE(controller, VappWidgetPopupController, getTopScreen());
        controller->setCallback(vapp_widget_view_terminate_callback, NULL);        
        
        controller->showPopupWithOk(
            getTopScreen(), 
            VFX_WSTR_RES(STR_ID_VAPP_WIDGET_PATH_NOT_FOUND));
        return;
	case WIDGET_FAILED_LOAD_GADGET:
	case WIDGET_HOST_NOT_INITIALIZED:
        // Show a popup to notify user exception occured due to fail to load
        VFX_OBJ_CREATE(controller, VappWidgetPopupController, getTopScreen());
        controller->setCallback(vapp_widget_view_terminate_callback, NULL);        
        
        controller->showPopupWithOk(
            getTopScreen(), 
            VFX_WSTR_RES(STR_ID_VAPP_WIDGET_FAILED_LOAD_WIDGET));
	        return;
	case WIDGET_MEMORY_FULL:
        // Show a popup to notify user exception occured due to memory full
        VFX_OBJ_CREATE(controller, VappWidgetPopupController, getTopScreen());
        controller->setCallback(vapp_widget_view_terminate_callback, NULL);        
        
        controller->showPopupWithOk(
            getTopScreen(), 
            VFX_WSTR_RES(STR_ID_VAPP_WIDGET_MEMORY_FULL));
   
        return;
    default:
    	VFX_ASSERT(0);
    	return;
    }
}

mmi_ret VappWidgetView::onProc(mmi_event_struct * evt)
{
    switch(evt->evt_id)
    {
        // Side key event, have to check avplugin play or not 
        case EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE: 
        {
            vapp_vol_dialog_evt_struct *vol_evt = (vapp_vol_dialog_evt_struct *)evt;
            if (vol_evt->type == VAPP_VOL_DIALOG_IS_MEDIA)
            {
				// call avplugin api to check media is playing or not
                if (
                    gadget_adp_audio_service_audio_playing()
                )
                {
                    return !MMI_RET_OK;
                }
            }
            
            break;
        }
        // Volunteer to free asm
        case EVT_ID_ASM_FREE_REQ:
            //m_prepared = VFX_FALSE;
            break;
        // Memory is ok to use  
        case EVT_ID_ASM_PREPARED:
            m_prepared = VFX_TRUE;
            break;
        // OOM is canceled
        case EVT_ID_ASM_CANCELED:
            m_prepared = VFX_FALSE;

            closeEditorPage();
            
            if (m_screen && m_screen->getPage(1))
            {
                exit();
            }
            break;
    }

    return VfxApp::onProc(evt);
}

void VappWidgetView::sendUpdateResponse(int instance_id, void *view_handle)
{
    widget_notify_content_update_cnf_struct *p = (widget_notify_content_update_cnf_struct*) construct_local_para(
                                                sizeof(widget_notify_content_update_cnf_struct),
                                                TD_RESET);
    p->instance_id = instance_id;
    p->view_handle = view_handle;

    // Send widget notify content update confirm message to gadget
    vapp_widget_view_send_message(p, NULL, MSG_ID_WIDGET_NOTIFY_CONTENT_UPDATE_CNF, MOD_GADGET);
}

void VappWidgetView::onPageStateChanged(VappWidgetViewPage *page, WidgetViewPageState state)
{
    switch(state)
    {
        // Event of entering a page
        case WIDGET_VIEW_PAGE_STATE_ENTER:
            m_pageState = WIDGET_VIEW_PAGE_STATE_ENTER;
            onEnterPage(page);
            break;
        // Event of exiting a page
        case WIDGET_VIEW_PAGE_STATE_EXIT:
            m_pageState = WIDGET_VIEW_PAGE_STATE_EXIT;
            onExitPage(page);
            break;
    }
}

void VappWidgetView::onEnterPage(VappWidgetViewPage *page)
{
    // Check if memory ok or not
	if (!m_prepared)
	{
		return ;
	}

    vapp_widget_enable_view_cache();

    if (m_exceptionOccured) 
    {
        // Show a popup to notify user exception occured due to memory full
        VappWidgetPopupController *controller;
        VFX_OBJ_CREATE(controller, VappWidgetPopupController, getTopScreen());
        controller->setCallback(vapp_widget_view_terminate_callback, NULL);        

        controller->showPopupWithOk(
            getTopScreen(), 
            VFX_WSTR_RES(STR_ID_VAPP_WIDGET_MEMORY_FULL));
    }
    else
    {
        // Set event handler in details view
        setEventHandler(VFX_TRUE);

        showPage();
    }
}

void VappWidgetView::onExitPage(VappWidgetViewPage *page)
{
    gadget_adp_audio_service_suspend();
    gadget_adp_avplugin_notify_suspend();

    if (m_viewHandle)
    {
        sendUpdateResponse(m_widgetId, m_viewHandle);
    }

    // Defocus the details view when exiting page
    onDefocus();

    // Send a pen about event
    vapp_widget_handle_pen_event(m_widgetId, m_viewHandle, 0, 0, PEN_ABORT);
}

void VappWidgetView::onFocus()
{
    // Send widget foucs in message
    vapp_widget_focus_in(m_widgetId, m_viewHandle);
}

void VappWidgetView::onDefocus()
{
    // Send widget foucs out message
    vapp_widget_focus_out(m_widgetId, m_viewHandle);
}

VfxPage *VappWidgetView::getActivePage()
{
    VFX_ASSERT(m_screen != NULL);

    return (VfxPage *)m_screen->getPage();
}

VfxWChar *VappWidgetView::getWidgetName()
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    VFX_ALLOC_MEM(m_nameString, sizeof(VfxWChar) * (WIDGET_MAX_NAME_LENGTH + 1), this);
    memset(m_nameString, 0, sizeof(VfxWChar) * (WIDGET_MAX_NAME_LENGTH + 1));

    if (m_nameString)
    {
        //widget->getName(nameString, sizeof(VfxWChar) * (WIDGET_MAX_NAME_LENGTH + 1));
        srv_wgtmgr_get_downloaded_wgt_name(m_widgetId, m_nameString, sizeof(VfxWChar) * WIDGET_MAX_NAME_LENGTH);
    }
   
    return m_nameString;
}

void VappWidgetView::onUpatePage(void *param)
{
    widget_notify_content_update_ind_struct *p = (widget_notify_content_update_ind_struct *)param;

    // check if screen and view handle match or not
    if (m_viewHandle != p->view_handle || m_pageState != WIDGET_VIEW_PAGE_STATE_ENTER || !m_screen->getPage(1))
    {
        sendUpdateResponse(p->instance_id, p->view_handle);
        return;
    }

    // Set updated content to image frame
    VappWidgetViewPage *page = (VappWidgetViewPage *)m_screen->getPage(1);
    page->setResizeRatio(m_resizeRatio);
    page->setImageContent(m_viewWidth, m_viewHeight);

    sendUpdateResponse(p->instance_id, p->view_handle);

}

void VappWidgetView::onPageKeyInput(VfxU16 keyCode, VfxU16 keyType)
{
    if (!m_viewHandle)
    {
        return ;
    }

    // Send input key event
    vapp_widget_handle_key_event(m_widgetId, m_viewHandle, keyCode, keyType);
}

void VappWidgetView::onPagePenInput(VfxPoint point, VfxS32 eventType)
{
    if (!m_viewHandle)
    {
        return ;
    }

    vapp_widget_handle_pen_event(m_widgetId, m_viewHandle, point.x, point.y, eventType);
}

void VappWidgetView::onLeaveMainScr(VfxBool leave)
{
    gadget_adp_avplugin_notify_close();
    
    if (!m_closedByEngine)
    {
        vapp_widget_close_view(m_widgetId, m_viewHandle, m_viewType, m_viewResponse);
    }

}

void VappWidgetView::showPage()
{
    if (!m_viewHandle || m_viewWidth == 0 || m_viewHeight == 0)
    {
        return;
    }

    // Set fullscreen flag
    int is_fullscreen = ((m_viewType == VIEW_DETAILS) 
                        && (m_viewFlags & DETAILS_VIEW_FLAG_NO_FRAME));

    VappWidgetViewPage *page = (VappWidgetViewPage *)m_screen->createWidgetViewPage();

    // If widget has set MaxResolution, resize ratio will be enable and zoom it
    page->setResizeRatio(m_resizeRatio);

    // Show page
    if (!page->show(m_viewCaption, is_fullscreen, m_viewWidth, m_viewHeight))
    {
        return ; 
    }

    gadget_adp_audio_service_resume();
    gadget_adp_avplugin_notify_resume();

    // Send message to request gadget update content
    vapp_widget_update_content(m_widgetId, m_viewHandle);

    // Focus details view
    onFocus();

}

void VappWidgetView::closeView(void *param)
{
    widget_show_view_ind_struct *p = (widget_show_view_ind_struct *)param;

    // Check if the request is for the current view
    if (m_viewHandle != p->view_handle || !m_screen->getPage(1))
    {
        return;
    }

    // Set close by engine flag
    m_closedByEngine = VFX_TRUE;

    exit();
}

VfxS32 VappWidgetView::closeById(VfxS32 instance_id)
{
    // Check if widget id is match or not
    if (m_widgetId != instance_id || !m_screen || m_pageState == WIDGET_VIEW_PAGE_STATE_CLOSED)
    {
        return 0;
    }

	m_pageState = WIDGET_VIEW_PAGE_STATE_CLOSED;

    exit();
	
    return 1;
}

void VappWidgetView::terminateAll(void *param)
{
    widget_terminate_all_wgt_ind_struct *ind = (widget_terminate_all_wgt_ind_struct *)param;

    if (!m_viewHandle)
    {
        return ;
    }

    // Check entering details view or not
    if (m_pageState !=  WIDGET_VIEW_PAGE_STATE_ENTER)
    {
        if (ind->type == WIDGET_RESET_MEMORY_FULL)
        {
            m_exceptionOccured = VFX_TRUE;
            return ;
        }
        else if (ind->type == WIDGET_RESET_STOP_ASM)
        {
            // Ternimate widget details view application if asm has been freed 
            m_closedByEngine = VFX_TRUE;
            VfxAppLauncher::terminate(getGroupId());
        }
    }
    else
    {
        // If entering details view page, show memory popup
        if (ind->type == WIDGET_RESET_MEMORY_FULL)
        {
            VappWidgetPopupController *controller;
            VFX_OBJ_CREATE(controller, VappWidgetPopupController, getTopScreen());
            controller->setCallback(vapp_widget_view_terminate_callback, NULL);
            
            controller->showPopupWithOk(
                getTopScreen(), 
                VFX_WSTR_RES(STR_ID_VAPP_WIDGET_MEMORY_FULL));
        }
    }
}

void VappWidgetView::terminate(void *param)
{
    widget_terminate_wgt_ind_struct *ind = (widget_terminate_wgt_ind_struct *)param;

    if (ind->wgt_id != m_widgetId || !m_viewHandle)
    {
        return ;
    }

    // If entering details view page, show memory popup
    VappWidgetPopupController *controller;
    VFX_OBJ_CREATE(controller, VappWidgetPopupController, getTopScreen());
    controller->setCallback(vapp_widget_view_terminate_callback, NULL);
    
    controller->showPopupWithOk(
        getTopScreen(), 
        VFX_WSTR_RES(STR_ID_VAPP_WIDGET_MEMORY_FULL));
}


void VappWidgetView::terminateCallback()
{
    // Check if screen is valid or not
    if (!m_screen || m_pageState == WIDGET_VIEW_PAGE_STATE_CLOSED)
    {
        return;
    }
	
	m_pageState = WIDGET_VIEW_PAGE_STATE_CLOSED;

    m_closedByEngine = VFX_TRUE;

    exit();
}

void VappWidgetView::setEventHandler(VfxBool isView)
{
    // Set details view event handler
    if (isView)
    {
        mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_NOTIFY_CONTENT_UPDATE_IND, (PsIntFuncPtr)vapp_widget_view_repaint, KAL_FALSE);
        mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_CLOSE_VIEW_IND, (PsIntFuncPtr)vapp_widget_close_view_handler, KAL_FALSE);
        mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_TERMINATE_ALL_WGT_IND, (PsIntFuncPtr)vapp_widget_view_handle_terminate_all_ind, KAL_FALSE);
        mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_TERMINATE_WGT_IND, (PsIntFuncPtr)vapp_widget_view_handle_terminate_ind, KAL_FALSE);
    }
    else
    {
        mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_NOTIFY_CONTENT_UPDATE_IND, NULL, KAL_FALSE);
        mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_CLOSE_VIEW_IND, NULL, KAL_FALSE);
        mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_TERMINATE_ALL_WGT_IND, (PsIntFuncPtr)vapp_widget_handle_terminate_all_ind, KAL_FALSE);
        mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_TERMINATE_WGT_IND, (PsIntFuncPtr)vapp_widget_handle_terminate_ind, KAL_FALSE);
    }
}

void* VappWidgetView::lockCanvas(int instance_id, void *view_handle, void **ptr_buffer, int width, int height)
{
	/* Fix bug: check if m_screen has been created */
    if(g_widget_view_launch == VFX_FALSE || !m_screen)
    {
        return NULL;
    }

    if(m_widgetId != instance_id || m_viewHandle != view_handle || 
       m_viewWidth != width || m_viewHeight != height)
    {
        return NULL;
    }

    // Check page is valid or not
    VappWidgetViewPage *page = (VappWidgetViewPage *) m_screen->getPage(1);

    if (page == NULL)
    {
        return NULL;
    }
        
    return page->lockCanvas(m_viewType, ptr_buffer);

}

void VappWidgetView::setViewResponse(VfxS32 response)
{
    m_viewResponse = response;
}

// VappWidgetViewMainScr Implementation
VFX_IMPLEMENT_CLASS("VappWidgetViewMainScr", VappWidgetViewMainScr, VfxMainScr);

VappWidgetViewMainScr::VappWidgetViewMainScr() :
    m_viewPage(NULL), 
    m_editorPage(NULL)
{
    
}

void VappWidgetViewMainScr::on1stReady()
{
    VfxMainScr::on1stReady();
}

void VappWidgetViewMainScr::onDeinit()
{
    if (m_viewPage != NULL && m_viewPage.isValid())
    {
        VFX_OBJ_CLOSE(m_viewPage);
    }

    if (m_editorPage != NULL && m_editorPage.isValid())
    {
        VFX_OBJ_CLOSE(m_editorPage);
    }

    VfxMainScr::onDeinit();
}

VappWidgetViewPage* VappWidgetViewMainScr::createWidgetViewPage()
{
    if (m_viewPage != NULL)
    {
        return m_viewPage.get();
    }
    
    VFX_OBJ_CREATE(m_viewPage, VappWidgetViewPage, this);
    m_viewPage->setStatusBar(VFX_TRUE);
    pushPage(1, m_viewPage.get());
    return m_viewPage.get();
}

VappWidgetEditorPage* VappWidgetViewMainScr::createWidgetEditorPage()
{
    closeWidgetEditorPage();

    VFX_OBJ_CREATE(m_editorPage, VappWidgetEditorPage, this);
    m_editorPage->setStatusBar(VFX_TRUE);
    pushPage(2, m_editorPage.get());
    return m_editorPage.get();
}


void VappWidgetViewMainScr::closeWidgetEditorPage()
{
    if (m_editorPage != NULL && m_editorPage.isValid())
    {
        closePage(2);
    }

    m_editorPage = NULL;
}


// VappWidgetViewPage Implementation
VFX_IMPLEMENT_CLASS("VappWidgetViewPage", VappWidgetViewPage, VfxPage);

VappWidgetViewPage::VappWidgetViewPage() :
    m_imageFrame(NULL), 
    m_imageBuffer1(NULL), 
    m_imageBuffer2(NULL), 
    m_loadingIcon(NULL), 
    m_widgetIcon(NULL)
{
    // Entering widget details view page, create image buffer mutex first
    createMutex();
    weakPtr = this;
}

void VappWidgetViewPage::onEnter(VfxBool isBackward)
{
    VfxPage::onEnter(isBackward);

    // Set page parameters
    setBgColor(VFX_COLOR_WHITE);
    setFocused(VFX_TRUE);
    setAutoAnimate(VFX_FALSE);

    // Ensure main screen is valid
    VfxMainScr *scr = (VfxMainScr*) getMainScr();
    ASSERT(scr != NULL);

    // Do nothing when under small screen redraw scenario
    if (scr->getIsSnapshotDrawing())
    {
        // Create image frame if it not exists
        if (m_imageFrame == NULL)
        {
            VFX_OBJ_CREATE(m_imageFrame, VfxImageFrame, this);
        }

        // Hide image content to avoid showing mess
        m_imageFrame->setHidden(VFX_TRUE);

        return ;
    }


    // Create image frame to set image content
    if (m_imageFrame == NULL)
    {
        VFX_OBJ_CREATE(m_imageFrame, VfxImageFrame, this);
    }
    m_imageFrame->setHidden(VFX_TRUE); 

    // Set content placement for zooming
    m_imageFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    takeMutex();

    // Set global page status variable
    m_state = WIDGET_VIEW_PAGE_STATE_ENTER;

    giveMutex();

    // Showing load icon to notify loading now
    displayLoadingIcon();

    m_signalStateChanged.emit(this, m_state);
}

void VappWidgetViewPage::onExited2()
{
    VfxPage::onExited2();

    VfxMainScr *scr = (VfxMainScr*) getMainScr();
    ASSERT(scr != NULL);

    if (scr->getIsSnapshotDrawing())
    {
        return ;
    }

    takeMutex();
    
    // Set global page status variable
    m_state = WIDGET_VIEW_PAGE_STATE_EXIT;

    // When leaving page, release image buffer
    prepareImgBuffer(VFX_FALSE, 0);

    giveMutex();

    m_signalStateChanged.emit(this, m_state);

}


void VappWidgetViewPage::onDeinit()
{
    takeMutex();

    if (m_loadingIcon != NULL && m_loadingIcon.isValid())
    {
        VFX_OBJ_CLOSE(m_loadingIcon);
    }

    if (m_widgetIcon != NULL  && m_widgetIcon.isValid())
    {
        VFX_OBJ_CLOSE(m_widgetIcon);
    }

    if (m_imageFrame != NULL  && m_imageFrame.isValid())
    {
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit(); 

        m_imageFrame->setImgContent(VFX_IMAGE_SRC_NULL);

        VFX_OBJ_CLOSE(m_imageFrame);
    }    

    VfxPageBar *bar = getBar(VFX_PAGE_BAR_LOCATION_TOP);
    if (bar)
    {
        VFX_OBJ_CLOSE(bar);
    }

    bar = getBar(VFX_PAGE_BAR_LOCATION_BOTTOM);
    if (bar)
    {
        VFX_OBJ_CLOSE(bar);
    }

    prepareImgBuffer(VFX_FALSE, 0);

    giveMutex();

    VfxPage::onDeinit();
}

void VappWidgetViewPage::displayLoadingIcon()
{
    // show loading icon
    if (m_loadingIcon == NULL)
    {
        VFX_OBJ_CREATE(m_loadingIcon, VcpActivityIndicator, this);
    }

    VfxU32 x, y;
    m_loadingIcon->setSize(
		(VfxS32)WIDGET_VIEW_LOADING_ICON_SIZE_WIDTH, 
		(VfxS32)WIDGET_VIEW_LOADING_ICON_SIZE_HEIGHT);
    x = getPageRect().getWidth()/2 - m_loadingIcon->getSize().width/2;
    y = getPageRect().getHeight()/2 - m_loadingIcon->getSize().height/2;
    m_loadingIcon->setPos(x, y);
    m_loadingIcon->start();

    if (m_widgetIcon == NULL)
    {
        VfxWString path;
        WCHAR icon_path[WIDGET_MAX_ICON_PATH_LENGTH] = {0};

        srv_wgtmgr_get_downloaded_wgt_icon_path(VappWidgetView::m_mainmenuId, icon_path);
        path.loadFromMem(icon_path);

        VFX_OBJ_CREATE(m_widgetIcon, VfxFrame, this);   
        m_widgetIcon->setImgContent(VfxImageSrc(VfxWString(path)));
    }

    m_widgetIcon->setSize(WIDGET_VIEW_WIDGET_ICON_SIZE_WIDTH, WIDGET_VIEW_WIDGET_ICON_SIZE_HEIGHT);
    x = getPageRect().getWidth()/2 - m_widgetIcon->getSize().width/2;
    y = getPageRect().getHeight()/2 - m_widgetIcon->getSize().height/2;
    m_widgetIcon->setPos(x, y);
    m_widgetIcon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	m_widgetIcon->setHidden(VFX_FALSE);

}

VfxBool VappWidgetViewPage::show(VfxWChar *caption, int is_fullscreen, VfxU32 width, VfxU32 height)
{
    m_bufferSize = width * height * 2;

#ifdef WIDGET_DETAILS_VIEW_ARGB8888_COLOR_FORMAT
    m_bufferSize = width * height * 4;
#endif

    if (!is_fullscreen)
    {
        drawBars(caption);
    }

    // Check if there is a status bar or not
    if (is_fullscreen && (height * m_resizeRatio > getPageHeight()))
    {
       setStatusBar(VFX_FALSE);
    }

    takeMutex();
    
    // Allocate image buffer
    VfxBool success = prepareImgBuffer(VFX_TRUE, m_bufferSize);

    giveMutex();

    if (!success)
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}

void VappWidgetViewPage::drawBars(VfxWChar *caption)
{
    if (!getBar(VFX_PAGE_BAR_LOCATION_TOP))
    {
        VcpTitleBar *m_titleBar;
        VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
        m_titleBar->setTitleStyle(VCP_TITLE_BAR_STYLE_BASE);
        m_titleBar->setTitle(VFX_WSTR_MEM(caption));
        setTopBar(m_titleBar);
    }

    if (!getBar(VFX_PAGE_BAR_LOCATION_BOTTOM))
    {
        VcpToolBar *m_toolBar;
        VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
        m_toolBar->addItem('TB1', VFX_WSTR_RES(VCP_STR_TOOL_BAR_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
        m_toolBar->addItem('TB2', VFX_WSTR_RES(VCP_STR_TOOL_BAR_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
        m_toolBar->m_signalButtonTap.connect(this, &VappWidgetViewPage::onToolBarClick);
        setBottomBar(m_toolBar);
    }
}

VfxBool VappWidgetViewPage::prepareImgBuffer(VfxBool alloc_flag, VfxU32 size)
{
    // Calcuate requested size
    size = ((size + 31) >> 5) << 5;
    
    if (alloc_flag)
    {
        // Get applicatio group id
		m_gid = getApp()->getGroupId();

        if(!m_imageBuffer1)
        {
            m_imageBuffer1 = (VfxU8 *)med_alloc_asm_mem(m_gid, size);
        }
      
        if(!m_imageBuffer2)
        {
            m_imageBuffer2 = (VfxU8 *)med_alloc_asm_mem(m_gid, size);
        }

        // If fail to allocate, show memory full popup
        if (!m_imageBuffer1 || !m_imageBuffer2)
        {
            VfxObject *parentObj = VappWidgetPopupController::getParentObj();

            if (!parentObj)
            {
                vapp_widget_view_terminate_callback(VCP_POPUP_BUTTON_NO_PRESSED, NULL);    
                return VFX_FALSE;
            }
            
            VappWidgetPopupController *controller;
            VFX_OBJ_CREATE(controller, VappWidgetPopupController, parentObj);
            controller->setCallback(vapp_widget_view_terminate_callback, NULL);
        
            controller->showPopupWithOk(
                parentObj, 
                VFX_WSTR_RES(STR_ID_VAPP_WIDGET_MEMORY_FULL));
        
            return VFX_FALSE;
        }
            
        VFX_ASSERT(m_imageBuffer1 || m_imageBuffer2);

        // Set allocated buffer to 0xff
        memset(m_imageBuffer1, 0xff, size);
        memset(m_imageBuffer2, 0xff, size);

    }
    else
    {
        VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit(); 

        if (m_imageFrame != NULL && m_imageFrame.isValid())
        {
            m_imageFrame->setImgContent(VFX_IMAGE_SRC_NULL);
        }
       
        if (m_imageBuffer1)
        {
            med_free_asm_mem(m_gid, (void **) &m_imageBuffer1);
            m_imageBuffer1 = NULL;
        }
        
        if (m_imageBuffer2)
        {
            med_free_asm_mem(m_gid, (void **) &m_imageBuffer2);
            m_imageBuffer2 = NULL;
        }
    }

    return VFX_TRUE;
}


void VappWidgetViewPage::setImageContent(VfxU32 width, VfxU32 height)
{
    m_width = width;
    m_height = height;

    VfxImageBuffer imageBuf;

    // Stop loading icon if it existed
    if (m_loadingIcon != NULL && m_loadingIcon.isValid())
    {
        m_loadingIcon->stop();
        VFX_OBJ_CLOSE(m_loadingIcon);
    }

    if (m_widgetIcon != NULL && m_widgetIcon.isValid())
    {
        m_widgetIcon->setHidden(VFX_TRUE);
    }

    takeMutex();

    if (m_state == WIDGET_VIEW_PAGE_STATE_EXIT || 
        !m_imageBufferMutex || m_imageFrame == NULL || !m_imageFrame.isValid() || 
        !m_imageBuffer1 || !m_imageBuffer2)
    {
        giveMutex();
        return ;
    }    

    m_imageFrame->setHidden(VFX_FALSE);

    // Double buffering, exchange the idle buffer for gadget to draw
    if (m_imageFrame->isNull() == VFX_FALSE && 
        m_drawedBuffer == 2)
        //m_imageFrame->getImgContent().getImageBuffer().ptr == m_imageBuffer1)
    {
        imageBuf.ptr = (VfxU8 *)m_imageBuffer2;
    }
    else
    {
        imageBuf.ptr = (VfxU8 *)m_imageBuffer1;
    }
    
#ifdef WIDGET_DETAILS_VIEW_ARGB8888_COLOR_FORMAT
    imageBuf.pitchBytes = width * 4;
    imageBuf.colorFormat = VRT_COLOR_TYPE_ARGB8888;
#else
    imageBuf.pitchBytes = width * 2;
    imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
#endif

    imageBuf.width = width;
    imageBuf.height = height;
    //m_imageFrame->setImgContent(VfxImageSrc(imageBuf));
    m_imageFrame->forceImgContent(VfxImageSrc(imageBuf));
    m_imageFrame->setBgColor(VFX_COLOR_BLACK);
    m_imageFrame->setPos(0, 0);

#if defined(__MMI_MAINLCD_480X800__) 
    if (m_resizeRatio > 1)
    {
	    m_imageFrame->setSize(LCD_WIDTH + 1, getPageHeight() + 1);
    }
#endif

    giveMutex();
}

void VappWidgetViewPage::createMutex()
{
    if (!m_imageBufferMutex)
    {
        m_imageBufferMutex = kal_create_mutex("widget_view_lock");
    }
}

void VappWidgetViewPage::takeMutex()
{
    kal_take_mutex(m_imageBufferMutex);
}

void VappWidgetViewPage::giveMutex()
{
    kal_give_mutex(m_imageBufferMutex);
}

void* VappWidgetViewPage::lockCanvas(VfxS32 view_type, void **ptr_buffer)
{
    canvas_lock_struct *lock = NULL;
    VFX_ASSERT(ptr_buffer);

    takeMutex();

    // If the image buffer is not existed, return directly    
    if (m_state == WIDGET_VIEW_PAGE_STATE_EXIT || 
        !m_imageBufferMutex || m_imageFrame == NULL || !m_imageFrame.isValid() || 
        !m_imageBuffer1 || !m_imageBuffer2)
    {
        giveMutex();
        return NULL;
    }

    // Set lock property
    lock = (canvas_lock_struct *)OslMalloc(sizeof(canvas_lock_struct));
    memset(lock, 0, sizeof(canvas_lock_struct));
    lock->mutex = m_imageBufferMutex;
    lock->view_type = view_type;
    lock->unlock_canvas =  VappWidgetViewPage::unlockCanvas;

    VFX_ASSERT(m_imageFrame != NULL);

    gadget_adp_log_prompt_trace("[lockCanvas] [Before set ptr_buffer] m_imageFrame: %x", m_imageFrame.get());

    // Double buffering, choose 
    if (m_imageFrame->isNull() == VFX_FALSE && 
        m_imageFrame->getImgContent().getImageBuffer().ptr == m_imageBuffer1)    
    {
        gadget_adp_log_prompt_trace("[lockCanvas] [Set ptr_buffer] m_imageBuffer2: %x", m_imageBuffer2);
        
        memset(m_imageBuffer2, 0x00, m_bufferSize);
        *ptr_buffer = (VfxU8 *)m_imageBuffer2;
        m_drawedBuffer = 2;
    }
    else
    {
        gadget_adp_log_prompt_trace("[lockCanvas] [Set ptr_buffer] m_imageBuffer1: %x", m_imageBuffer1);

        memset(m_imageBuffer1, 0x00, m_bufferSize);
        *ptr_buffer = (VfxU8 *)m_imageBuffer1;
        m_drawedBuffer = 1;
    }

    return lock;
}


void VappWidgetViewPage::unlockCanvas(void *p)
{
    gadget_adp_log_prompt_trace("[unlockCanvas]");

    canvas_lock_struct *lock = (canvas_lock_struct *)p;
    VFX_ASSERT(lock);

    VFX_ASSERT(lock->mutex == m_imageBufferMutex);

    giveMutex();

    OslMfree(lock);
}


void VappWidgetViewPage::closePage()
{
    if (weakPtr.isValid())
    {
        exit();
    }
}

void VappWidgetViewPage::onToolBarClick(VfxObject *sender, VfxId id)
{
    VappWidgetView *viewApp = (VappWidgetView *)getApp();
    
    switch(id)
    {
        // click ok button
        case 'TB1':
            //g_widget_view_cntx->view_response = VIEW_RESPONSE_OK;
            viewApp->setViewResponse(VIEW_RESPONSE_OK);
            back();
            break;

        // click cancle button
        case 'TB2':
            //g_widget_view_cntx->view_response = VIEW_RESPONSE_CANCEL;
            viewApp->setViewResponse(VIEW_RESPONSE_CANCEL);
            back();
            break;

        default:
            break;
    }
}


VfxBool VappWidgetViewPage::onKeyInput(VfxKeyEvent &event)
{
    VfxU16 keyCode, keyType;
    
#ifdef __MTK_INTERNAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 

    if(event.type == VFX_KEY_EVENT_TYPE_DOWN &&
            event.keyCode == VFX_KEY_CODE_BACK)
    {
        keyType = KEY_EVENT_DOWN;
        keyCode = KEY_BACK;
        
        m_singalKeyInput.postEmit(keyCode, keyType);

        if (!g_widget_view_main_menu_wait_msg)
        {
            return VFX_TRUE;
        }
    }
#if 0   /* Use volume cui instead of processing side key by gadget */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

    if (event.keyCode != VFX_KEY_CODE_VOL_DOWN && event.keyCode != VFX_KEY_CODE_VOL_UP)
    {
        switch (event.type)
        {
            case VFX_KEY_EVENT_TYPE_DOWN:
            case VFX_KEY_EVENT_TYPE_UP:
            case VFX_KEY_EVENT_TYPE_REPEAT:
            case VFX_KEY_EVENT_TYPE_LONG_PRESS:
                m_singalKeyInput.postEmit(event.keyCode, event.type);   //mark to add 
            break;
        }
    }

    return VfxPage::onKeyInput(event);
}


VfxBool VappWidgetViewPage::onPenInput(VfxPenEvent &event)
{
    VfxPoint point;

    if (!m_imageBuffer1 || !m_imageBuffer2 || 
        m_imageFrame->getSize().width == 0 || m_imageFrame->getSize().height == 0)
    {
        return VFX_TRUE;
    }

    VFX_ASSERT(m_width != 0 && m_height != 0);

    VfxFloat widgetResizeRatio = (m_imageFrame->getSize().width / (VfxFloat)m_width);
    VfxFloat heightResizeRatio = (m_imageFrame->getSize().height / (VfxFloat)m_height);

    VFX_ASSERT(widgetResizeRatio != 0 && heightResizeRatio != 0);
    
    point.x = (VfxS32)(event.getRelPos(this).x / widgetResizeRatio);
    point.y = (VfxS32)(event.getRelPos(this).y / heightResizeRatio);

    int type = 0;

    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_DOWN:
        type = PEN_DOWN;
        break;
    case VFX_PEN_EVENT_TYPE_UP:
        type = PEN_UP;
        break;
    case VFX_PEN_EVENT_TYPE_MOVE:
        type = PEN_MOVE;
        break;
    case VFX_PEN_EVENT_TYPE_ABORT:
        type = PEN_ABORT;
        break;
    default:
        return MMI_FALSE;
        
    }

    m_singalPenInput.postEmit(point, type);
    
    return VFX_TRUE;

}

VfxU32 VappWidgetViewPage::getPageHeight()
{
    return getPageRect().getHeight();
}

VfxFrame *VappWidgetViewPage::getImageFramePtr()
{
    if (m_imageFrame.get())
    {
        return m_imageFrame.get();
    }
    else
    {
        return NULL;
    }
}



#endif /* __MMI_GADGET_SUPPORT__ */
