/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_ncenter.cpp
 *
 * Project:
 * --------
 *  COSMOS Notification Center
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
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
 *
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
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
 *
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
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
 *
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
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
 *
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
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
 *
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vapp_ncenter.h"

#if defined(__MMI_NCENTER_SUPPORT__) && !defined(__MMI_KEY_ONLY_NCENTER__)


#ifdef __MTK_TARGET__
#ifdef __VENUS_SWLA_DBG_ON__
#define __MAUI_SOFTWARE_LA__
#else
//#define __MAUI_SOFTWARE_LA__
#endif
#endif





#include "vadp_asm.h"
#include "notificationGprot.h"


#include "vfx_uc_include.h"
#include "vcp_status_icon_bar.h"
#include "vapp_ncenter_system_cell.h"
#include "vapp_ncenter_test_cell.h"
#include "vapp_ncenter_quick_setting_cell.h"

#include "vfx_primitive_frame.h"
#include "vapp_launcher_gprot.h"



#include "vcp_global_popup.h"
#include "vapp_platform_context.h"
#include "vapp_ncenter_gprot.h"



#if defined(__MMI_SAFE_MODE__)
#include "SafeModeSrvGprot.h"
#include "vapp_ncenter_safe_mode_cell.h"
#endif /* defined(__MMI_SAFE_MODE__) */



extern "C" 
{
    #include "idleGprot.h"
    #include "wgui_categories_util.h"
    #include "mmi_common_app_trc.h"
    #include "vfx_adp_device.h"
    #include "mmi_rp_app_ncenter_def.h"

    #ifdef  __MMI_NSS_SUPPORT__
    #include "NotificationSettingSrvGprot.h" //for NSS
    #endif

    #if defined(__MMI_VUI_COSMOS_CP__)
    #include "mmi_rp_app_cosmos_global_def.h"
    #endif

    #include "GlobalResDef.h" //for EVT_ID_SCRN_ENTER_SUCCESS_NOTIFY

#ifdef __MAUI_SOFTWARE_LA__
    #include "SST_sla.h"
#endif

}




extern "C" void mmi_pen_send_event_to_new_screen(void);
extern "C" void vapp_ncenter_entry_small_screen(void);


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define TRACE(a) VFX_TRACE (a)

#define VAPP_NCENTER_Z_ORDER                    (5500)
#define VAPP_NCENTER_Y_VELOCITY_THRESHOLD       (150)
#define VAPP_NCENTER_INVALID_ID 0xFFFFFFFF


/***************************************************************************** 
 * Class VappNCenter 
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappNCenter", VappNCenter, VfxControl);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappNCenter);

VappNCenter::VappNCenter()
{
    m_panel = NULL;
    m_enterTimer = NULL;
    m_leaveTimer = NULL;
    m_eventCount = 0;
    m_ongoingCount = 0;
    m_operatorCell = NULL;
    m_panelContent = NULL;
    m_topRegion = NULL;
    m_bottomRegion = NULL;
    m_bottomHeight = 0;
    m_topHeight = 0;
    m_tabBarPos = VAPP_NCENTER_TABBAR_TOP;
    m_currentViewId = 0;
    m_clearCell = NULL;
    m_disableLeave = VFX_FALSE;
    m_disableDrag = VFX_FALSE;
    m_entered = VFX_FALSE;
    m_isDrag = VFX_FALSE;
    m_callbackNoti = NULL;
    m_noTextFrame = NULL;
    m_quickSettingCell = NULL;
#if defined(__MMI_SAFE_MODE__)
    m_safeModeCell = NULL;
#endif    
    m_list = NULL;
    m_context = NULL;
    m_ncenterScrPtr = NULL;
    m_operatorCellIsFold = VFX_TRUE;
    m_statusBar = NULL;
    m_tabBar = NULL;
    m_uiContext = NULL;
    m_asmId = GRP_ID_INVALID;
    m_memPtr = NULL;
}


#define VAPP_NCENTER_MEM_POOL 2
static VfxU32 g_vappNCenterMemPool[VAPP_NCENTER_MEM_POOL * 1024 / sizeof(VfxU32)]; //for ncenter and leavetimer

#ifdef __COSMOS_MMI_PACKAGE__


static mmi_ret vapp_ncenter_event_handler(mmi_event_struct *evt)
{   
    if (vfx_sys_get_canvas_state() == VFX_SYS_STATE_LEAVE) //pluto screen
    {        
        VappNCenter *nc = VFX_OBJ_GET_INSTANCE(VappNCenter);
        if (nc->getNCenterEntered() && nc->getDisableLeaveOnScreeChange())
        {           
            // close previous one if re-entry
            mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_NCENTER);            
            vapp_ncenter_entry_small_screen();            
        }
    }
    return MMI_RET_OK;
}  



static mmi_ret vappNCenterEventHandler(mmi_event_struct *event)
{
    switch(event->evt_id)
    {
        case EVT_ID_SCRN_ENTER_SUCCESS_NOFITY:
            mmi_event_struct postInvoke;
            MMI_FRM_INIT_EVENT(&postInvoke, 0);
            MMI_FRM_POST_EVENT(&postInvoke, vapp_ncenter_event_handler, NULL);                
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}


mmi_ret vapp_ncenter_on_asm_event(mmi_event_struct *evt)
{
    mmi_ret ret = MMI_RET_OK;
    VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    

    switch(evt->evt_id)
    {
        case EVT_ID_DELETE_DANGLE_GROUP_REQ:
        {
            // Keep dangle group.
            ret = MMI_RET_ERR;
            break;
        }
        case EVT_ID_ASM_FREE_REQ:           // volunteer free
        case EVT_ID_ASM_FREE_REQ_NO_WAIT:   // volunteer free
        case EVT_ID_ASM_FORCE_FREE:         // force free
        {
            NCenter->deinitAsmMemory();
            ret = MMI_FRM_ASM_FREED;

            break;
        }
        default:
        {
            break;
        }
    }

    return ret;
}

mmi_ret vapp_ncenter_oom_handler(mmi_event_struct *evt)
{
    mmi_frm_nmgr_alert_struct alert_info;

    memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct)); 

    alert_info.app_id = APP_NCENTER; 
    alert_info.scen_id = MMI_SCENARIO_ID_DEFAULT;

    alert_info.event_type = MMI_EVENT_DEFAULT; 

    alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_BAR_MASK; 
    alert_info.behavior_mask = FORCE_STATUS_BAR; 
    alert_info.status_bar_para.status_bar_type =MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
    alert_info.status_bar_para.display_string = (WCHAR*)GetString(STR_ID_VAPP_NCENTER_OOM);
    //alert_info.app_proc_para.scrn_group_proc= &vapp_ncenter_text_preview_hdlr;
    alert_info.alert_option= MMI_FRM_NMGR_DISABLE_TONE | MMI_FRM_NMGR_DISABLE_VIB;

    mmi_frm_nmgr_alert(&alert_info); 
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_NCENTER);  

    return MMI_RET_OK;
}

#endif


void VappNCenter::onInit()
{
    VFX_OBJ_CREATE(m_context, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
    m_context->assignPool((VfxU8 *)g_vappNCenterMemPool, VAPP_NCENTER_MEM_POOL * 1024);
     
    VfxControl::onInit();    
    
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->addChildFrame(this);
    topLevel->m_signalActiveScreenBeforeEnter.connect(this, &VappNCenter::onActiveScreenEnter);
    topLevel->m_signalActiveScreenExit.connect(this, &VappNCenter::onActiveScreenExit);
    topLevel->m_signalActivePopupEnter.connect(this, &VappNCenter::onPopupChanged);
    topLevel->m_signalRotated.connect(this, &VappNCenter::onRotate);
       

    setSize(getParentFrame()->getSize());
    setHidden(VFX_TRUE);
    setPosZ(VAPP_NCENTER_Z_ORDER);


    VFX_OBJ_CREATE(m_leaveTimer, VfxTimer, this); //use ncenter static memory
    m_leaveTimer->m_signalTick.connect(this, &VappNCenter::leaveInternalEx);
    m_leaveTimer->setStartDelay(1);
    

    
    VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
    nm->m_signalNStatus.connect(this, &VappNCenter::onNotificationChanged);    

#ifdef __COSMOS_MMI_PACKAGE__
    mmi_frm_cb_reg_event(EVT_ID_SCRN_ENTER_SUCCESS_NOFITY, vappNCenterEventHandler, NULL);
#endif

}

void VappNCenter::emitEvent(VappNCenterEventEnum event)
{
    m_signalEvent.emit(event);

    mmi_group_event_struct evt;
	VfxU16 evtId;
    switch (event)
    {
        case VAPP_NCENTER_EVENT_ENTER:
        {
			evtId = EVT_ID_VAPP_NCENTER_ENTER;
            break;
        }
        case VAPP_NCENTER_EVENT_ENTERED:
        {
			evtId = EVT_ID_VAPP_NCENTER_ENTERED;
            break;
        }
        case VAPP_NCENTER_EVENT_EXIT:
        {
			evtId = EVT_ID_VAPP_NCENTER_EXIT;
            break;
        }
        case VAPP_NCENTER_EVENT_EXITED:
        {
			evtId = EVT_ID_VAPP_NCENTER_EXITED;
            break;           
        }
        default:
        {
            VFX_ASSERT(0);   
            return;
        }      
    }
	
	MMI_FRM_INIT_EVENT(&evt, evtId);
    MMI_FRM_CB_EMIT_EVENT(&evt); //brocast to receiver
    
}


VfxBool VappNCenter::onPenInput(VfxPenEvent &event)
{   

    //vfx_sys_mem_pool_status_struct output,old;
    //VFX_OBJ_GET_INSTANCE(VappPlatformContext)->statistics(old);

    
    if (m_panel)
    {
        switch (event.type)
        {
            case VFX_PEN_EVENT_TYPE_DOWN:
                {
#ifdef __MAUI_SOFTWARE_LA__
                    SLA_CustomLogging("NPD", SA_label);
#endif                      
                    
                    VfxPoint dowmpt = event.getRelDownPos(this);

                if (m_entered)
                {
                	if(dowmpt.y < getSize().height - m_bottom->getSize().height)
            		{
                    	return VFX_FALSE;
            		}
                    emitEvent(VAPP_NCENTER_EVENT_EXIT);

                    //freeze cache mode                  
                    VcpMenuRegionIter   itr(m_list->getLayout(), m_list->getRealContentRegion());
                    while(!itr.isEnd())
                    {
                        VcpMenuPos p = itr.next();
                        VfxFrame* c = m_list->getCellIfPresent(p.group, p.pos);       
                        if (c)
                        {
                            c->setCacheMode(VFX_CACHE_MODE_FREEZE);                       
                        }
                    }  
                    m_tabBar->setCacheMode(VFX_CACHE_MODE_FREEZE);
					m_originY = dowmpt.y;
                
                }
				else
				{
					m_originY = dowmpt.y + VAPP_NCENTER_BOTTOM_HEIGHT / 2;//m_panel->getPos().y + m_panel->getSize().height;                                        
				}
				
                m_isDrag = VFX_TRUE;                    
                
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->releaseFocus(m_list); //relase Focus to original holder when pen down

                updatePanelPos(event);
                return VFX_TRUE;
            }
            case VFX_PEN_EVENT_TYPE_ABORT:
            case VFX_PEN_EVENT_TYPE_UP:
            {
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("NPU", SA_label);
#endif                                          

                m_panel->setAutoAnimate(VFX_TRUE);
                m_bottom->setAutoAnimate(VFX_TRUE);
                // use velocity to determine leave or not
                VfxPoint dowmpt = event.getRelDownPos(this);
                VfxPoint pt     = event.getRelPredictPos(this);
                VfxS32   yv;
                
                if (event.timeStamp == event.downTimeStamp)
                {
                    // means only tap                    
				    return VFX_TRUE;
                }
                else
                {
                    yv = (1000 * (pt.y - dowmpt.y)) / (event.timeStamp - event.downTimeStamp);
                }

                if (yv > VAPP_NCENTER_Y_VELOCITY_THRESHOLD || pt.y > 0.5 * getSize().height)
                {
                    m_panel->setPos(0, 0);
                    m_panel->setSize(getSize());
                    setIsDisabled(VFX_TRUE);
                    m_list->setIsDisabled(VFX_TRUE);
                    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                    topLevel->captureFocus(m_list); //key support

                    VFX_OBJ_CREATE(m_enterTimer, VfxTimer, m_panel);
                    m_enterTimer->m_signalTick.connect(this, &VappNCenter::onEnterEnd);
                    m_enterTimer->setStartDelay(VfxAutoAnimate::getDuration());
                    m_enterTimer->start();
                }
                else
                {
                    leave();
                }
                break;
            }
            case VFX_PEN_EVENT_TYPE_MOVE:
            {
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("NPM", SA_label);
#endif             
                updatePanelPos(event);
                break;                
            }
            default:
                break;
        }
    }
    return VFX_TRUE;
}

void VappNCenter::updatePanelPos(VfxPenEvent &event)
{
    VfxPoint dowmpt = event.getRelDownPos(this);
    VfxPoint pt     = event.getRelPos(this);

    VfxS32 newY = m_originY + (pt.y - dowmpt.y);
    VfxS32 finalY;

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    if (!m_entered)
    {
		VfxS32 finalPanelHeight;
		VfxS32 originPanelHeight = m_panel->getSize().height;
		VfxS32 NCenterHeight = getSize().height;
	    VfxS32 marginHeight = m_topHeight + m_bottomHeight;
	    VcpBaseMenuLayout* layout = m_list->getLayout();
	    VfxS32 formHeight = VFX_MIN(layout->getTotalLength(), NCenterHeight - marginHeight);
		
        if(newY <= MMI_STATUS_BAR_HEIGHT)
        {
			finalPanelHeight = formHeight + m_bottomHeight;
            finalY = newY - (VAPP_NCENTER_BOTTOM_HEIGHT - MMI_STATUS_BAR_HEIGHT) - originPanelHeight;
        }
        else if (newY > MMI_STATUS_BAR_HEIGHT && newY < marginHeight + formHeight && newY < NCenterHeight)
        {
            finalPanelHeight = marginHeight + formHeight;
            finalY = newY - originPanelHeight;
        } 
        else if (newY >= marginHeight + formHeight && newY < NCenterHeight)
        {
            finalPanelHeight = newY;
			finalY = 0;
        }
        else
        {
            if (marginHeight + formHeight > NCenterHeight)
            {
				finalY = NCenterHeight - marginHeight - formHeight;
                finalPanelHeight = marginHeight + formHeight;
            }
            else
            {
                finalPanelHeight = NCenterHeight;
				finalY = 0;
            }                         
        }
        m_panel->setSize(m_panel->getSize().width, finalPanelHeight);
    }
    else
    {
        // only move position if already entered.
        finalY = newY - m_originY;
        if (finalY > 0)
        {
            finalY = 0;
        }
    }
	
	m_panel->setPos(0, finalY);

    VfxAutoAnimate::commit();

}

void VappNCenter::onPopupChanged(VfxWeakPtr<VfxBasePopup> popup)
{
#ifdef __COSMOS_MMI_PACKAGE__
    if(popup.get() && getHidden() == VFX_FALSE)
    {

        VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        VcpGlobalPopupScr *globalPopupScr = VFX_OBJ_DYNAMIC_CAST(topLevel->getActiveScr(), VcpGlobalPopupScr);

        // not a global popup
        if (globalPopupScr == NULL)
        {
            topLevel->releaseFocus(m_list);
            leaveInternal();
        }
    }
#endif
}

VfxBool VappNCenter::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
    	switch (event.keyCode)
		{
	        case VFX_KEY_CODE_BACK:
			case VFX_KEY_CODE_RSK:
	        {
	            leave();            
	            return VFX_TRUE;
	        }
			
	        case VFX_KEY_CODE_HOME:
	        {
#ifdef __COSMOS_MMI_PACKAGE__ 
	            if (vapp_launcher_is_active())
	            {
	                leave();
	            }
#endif
	            return VFX_FALSE;
	        }
			
	        case VFX_KEY_CODE_ARROW_LEFT:
	        case VFX_KEY_CODE_ARROW_RIGHT:
	        {
	            if(m_tabBar)
	            {
	                VfxId id;
					if(event.keyCode == VFX_KEY_CODE_ARROW_LEFT)
					{
						id = VAPP_NCENTER_TAB_NOTIFICATION;
					}
					else
					{
						id = VAPP_NCENTER_TAB_ONGOING;					
					}
	                m_tabBar->setHighlightedTab(id);
	                onTabSwitched(NULL, id);
	                return VFX_TRUE;
	            }
				break;
	        }

#ifndef __COSMOS_MMI_PACKAGE__ 
	        case VFX_KEY_CODE_VOL_UP:
	        case VFX_KEY_CODE_VOL_DOWN:
	        {
				VcpBaseMenuLayout::NavDirEnum dir;
				if(event.keyCode == VFX_KEY_CODE_VOL_UP)
				{
					dir = VcpBaseMenuLayout::NAV_DIR_UP;
				}
				else
				{
					dir = VcpBaseMenuLayout::NAV_DIR_DOWN;					
				}
				
	            if(m_list)
	            {
	                m_list->getLayout()->navDir(dir);
	            }
	            return VFX_TRUE;
	        }
#endif
			default:
				break;
		}
    }
 

    
    return VfxControl::onKeyInput(event);
}

void VappNCenter::enter()
{

#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("NER", SA_start);
#endif

    // hidden = true and no object is requesting leave
    if (getHidden() != VFX_FALSE && !m_callbackNoti)
    {
 

        MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_ENTER);
        
        VFX_ASSERT(m_asmId == GRP_ID_INVALID);

        VfxBool enterable = VFX_TRUE;

#ifdef __COSMOS_MMI_PACKAGE__
        if (!initAsmMemory())
        {                    
            enterable = VFX_FALSE;
            mmi_event_struct postInvoke;
            MMI_FRM_INIT_EVENT(&postInvoke, 0);
            MMI_FRM_POST_EVENT(&postInvoke, vapp_ncenter_oom_handler, NULL);                    
        }
#endif    

        if (enterable)
        {
            vfx_adp_srs_pause();   
            
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);
            
            emitEvent(VAPP_NCENTER_EVENT_ENTER); // Entering NCenter
            
            VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            topLevel->addChildFrame(this);
            setSize(getParentFrame()->getSize());        
            createSystemView();
            setHidden(VFX_FALSE);
            
            
            VfxS32 initHeight = getSize().height;        
            if(m_list)
            {
                VcpBaseMenuLayout* layout = m_list->getLayout();
                initHeight = VFX_MIN(initHeight, m_topHeight + layout->getTotalLength() + m_bottomHeight);
            }
            
            m_panel->setSize(m_panel->getSize().width, initHeight);
            m_panel->setPos(VfxPoint(0, m_bottom->getSize().height - m_panel->getSize().height));
            m_list->setIsUnhittable(VFX_TRUE);
            
            capture();
            VfxAutoAnimate::commit();    
        }
    }

#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("NER", SA_stop);
#endif
    
}

void VappNCenter::leave()
{

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("NLE", SA_start);
#endif
    
    if (getHidden() == VFX_FALSE && m_panel)
    {
        MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_LEAVE);

        setIsDisabled(VFX_TRUE);

        
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_FALSE);
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);        

        m_panel->setPos(0, 0 - m_panel->getSize().height);

        
        VfxAutoAnimate::commit();
        

        VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        topLevel->releaseFocus(m_list);

        //timer new feature
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->blockAfterNextCommit(250, VfxCallback0(this, &VappNCenter::leaveInternal));

    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("NLE", SA_stop);
#endif    
}



void VappNCenter::onEnterEnd(VfxTimer *source)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("NEE", SA_start);
#endif    

    
    VFX_OBJ_CLOSE(m_enterTimer);
    
    if (getHidden() == VFX_FALSE)
    {
        VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
        nm->sendIntent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_ENTERED, VSRV_NOTIFICATION_TYPE_CUSTOM);
        
        emitEvent(VAPP_NCENTER_EVENT_ENTERED);

        VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        topLevel->captureFocus(m_list); //key support
    
        m_list->setIsUnhittable(VFX_FALSE);
        m_list->setIsDisabled(VFX_FALSE);

        //restore cache mode                  
        VcpMenuRegionIter   itr(m_list->getLayout(), m_list->getRealContentRegion());
        while(!itr.isEnd())
        {
            VcpMenuPos p = itr.next();
            VfxFrame* c = m_list->getCellIfPresent(p.group, p.pos);       
            if (c)
            {
                c->setCacheMode(VFX_CACHE_MODE_AUTO);                       
            }
        }        

        m_tabBar->setCacheMode(VFX_CACHE_MODE_AUTO);       

        setIsDisabled(VFX_FALSE);
        m_entered = VFX_TRUE;
        m_isDrag = VFX_FALSE;            
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("NEE", SA_stop);
#endif    



}



void VappNCenter::onRequestUpdate(VfxId id, VfxS32 height)
{
    VFX_UNUSED(height);
    VFX_UNUSED(id);

    m_operatorCellIsFold = m_operatorCell->getIsFold();
    m_list->removeMarginItem(m_operatorCell);              
    m_list->addMarginItem(VCP_BASE_MENU_MARGIN_AREA_TOP, VCP_BASE_MENU_MARGIN_AREA_FRAME_PLACEMENT_FULL, m_operatorCell);        
    m_operatorCell->sendToBack();
}

void VappNCenter::onEventClearAll(VfxObject* sender, VfxId id)
{
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_ON_EVENT_CLEAR_ALL);
    VFX_UNUSED(sender);
    VFX_UNUSED(id);

    VfxList <VsrvNotification*> intentList;
    intentList.init(m_panel);

    VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
    VfxList <VsrvNGroup*>::It it;    
    for (it = nm->getNGroups(); !it.isNull(); ++it)  
    {                 
        VsrvNGroup* group = *it;        
        VfxList <VsrvNotification*>::It itt;        
        for (itt = group->getNotifications(); !itt.isNull(); ++itt)
        {
            VsrvNotification *noti = *itt;
            if (checkNotification(noti))
            {
                intentList.pushBack(noti);
            }                                                            
         }
     }                 
    
    VfxList <VsrvNotification*>::It itt;
    for (itt = intentList.begin(); !itt.isNull(); ++itt)
    {
        VsrvNotification* noti = *itt;
        VfxBool autoClose = noti->getAutoClose(VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_CLEAR);        
        VfxS32 serialNum = noti->getSerialNum();

        nm->sendIntent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_CLEAR, noti);
                
        if (autoClose && nm->checkNotification(noti) && noti->getSerialNum() == serialNum)
        {
            nm->sendIntent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_CLOSE, noti);
            VSRV_NOTIFICATION_CLOSE(noti);
        }        
    }    

    
}


vrt_allocator_handle VappNCenter::getAllocator()
{
    return m_context->getAllocator();
}

VfxBool VappNCenter::initAsmMemory()
{       

    VfxBool ret = VFX_TRUE;
 
    m_asmId = mmi_frm_group_create(
                GRP_ID_ROOT,
                SCR_ID_NCENTER,
                &vapp_ncenter_on_asm_event,
                NULL);           
    VFX_ASSERT(m_asmId != GRP_ID_INVALID);

    VadpAsmProperty ncenterProperty;
    VadpAsm::getProperty(m_asmId, ncenterProperty);
    ncenterProperty.f_prepare_w_reserve = 0;
    ncenterProperty.f_hide_in_oom       = 1;
    VadpAsm::setProperty(m_asmId, ncenterProperty);
    

    m_memPtr = (VfxU8*) vadpAsmAlloc(m_asmId, 60 * 1024);  

    if (m_memPtr)
    {
        VFX_OBJ_CREATE(m_uiContext, VfxContext, this);           
        m_uiContext->assignPool(m_memPtr, 60 * 1024);

    }
    else
    {
        mmi_frm_group_close(m_asmId);
        m_asmId = GRP_ID_INVALID;        
        
        ret = VFX_FALSE;        
    }   


    return ret;
    

}

void VappNCenter::deinitAsmMemory()
{
    leaveInternal();                  
}


void VappNCenter::createSystemView()
{

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("NCS", SA_start);
#endif 

    VfxS32 panelWidth = getSize().width;
    VfxS32 panelHeight = getSize().height;

#ifdef __COSMOS_MMI_PACKAGE__
    wgui_status_icon_bar_enter_ncenter();
#endif

    VFX_DEV_ASSERT(m_panel == NULL);

#ifdef __COSMOS_MMI_PACKAGE__
    VFX_OBJ_CREATE(m_panel, VfxFrame, m_uiContext);
#else
    VFX_OBJ_CREATE(m_panel, VfxFrame, m_ncenterScrPtr.get());
#endif
    addChildFrame(m_panel);

    
    m_panel->setBgColor(VAPP_NCENTER_CLR_BACKGROUND);
    m_panel->setSize(panelWidth, panelHeight);
    m_panel->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_panel->setAutoAnimate(VFX_TRUE);
   

    VFX_OBJ_CREATE(m_topRegion, VfxFrame, m_panel);
    m_topRegion->setSize(panelWidth, panelHeight);
    m_topHeight = 0;    

    VfxS32 h;
	m_topHeight = onCreateContentTop(m_topRegion);
    if (m_topHeight > 0)
    {
        m_topRegion->setBounds(0, 0, panelWidth, m_topHeight);
        m_topRegion->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);
    }
    else
    {
        VFX_OBJ_CLOSE(m_topRegion);
    }


    m_bottomHeight = 0;

    VFX_OBJ_CREATE(m_bottomRegion, VfxFrame, m_panel);
    m_bottomRegion->setSize(panelWidth, panelHeight);
    h = onCreateContentBottom(m_bottomRegion);
    if (h > 0)
    {
        m_bottomRegion->setAnchor(0, 1);        
        m_bottomRegion->setPos(0, panelHeight - VAPP_NCENTER_BOTTOM_HEIGHT);
        m_bottomRegion->setSize(panelWidth, h);
        m_bottomRegion->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_bottomHeight += h;
    }    
    else
    {
        VFX_OBJ_CLOSE(m_bottomRegion);
    }    


    // bottom 
    VFX_OBJ_CREATE(m_bottom, VfxFrame, m_panel);
    m_bottom->setPos(0, panelHeight - VAPP_NCENTER_BOTTOM_HEIGHT);
    m_bottom->setSize(panelWidth, VAPP_NCENTER_BOTTOM_HEIGHT);
    m_bottom->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bottom->setImgContent(VfxImageSrc(VAPP_IMG_NCENTER_DRAG_BAR_BG));
    m_bottom->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    VFX_OBJ_CREATE(m_bottomImage, VfxImageFrame, m_bottom);
    m_bottomImage->setAnchor(0.5f, 0.5f);
    m_bottomImage->setPos(panelWidth/2, VAPP_NCENTER_BOTTOM_HEIGHT/2);
    m_bottomImage->setSize(panelWidth, VAPP_NCENTER_BOTTOM_HEIGHT);
    m_bottomImage->setResId(VAPP_IMG_NCENTER_DRAG_BAR);
    m_bottomImage->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID, VFX_FRAME_ALIGNER_MODE_MID, VFX_FRAME_ALIGNER_MODE_MID, VFX_FRAME_ALIGNER_MODE_MID);

    m_bottomHeight += VAPP_NCENTER_BOTTOM_HEIGHT;



    VFX_OBJ_CREATE(m_panelContent, VfxFrame, m_panel);
    m_panelContent->setAutoAnimate(VFX_TRUE);   
    m_panelContent->setPos(0, m_topHeight);    
    m_panelContent->setSize(panelWidth, panelHeight - m_topHeight - m_bottomHeight);
    m_panelContent->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);    


    for(int i=0; i < VAPP_NCENTER_TAB_TOTAL; ++i)
    {
        m_formBounds[i] = VFX_RECT_ZERO;
    }

    onCreateContentView(m_currentViewId, m_panelContent);


#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("NCS", SA_stop);
#endif 


}

void VappNCenter::onTabSwitched(VfxObject* tabBar, VfxId tid)
{
    if (m_currentViewId != tid)
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);


        m_formBounds[m_currentViewId] = m_list->getViewBounds();
        onCloseContentView(m_currentViewId);
        m_currentViewId = tid;
        onCreateContentView( m_currentViewId, m_panelContent);
        if(m_formBounds[m_currentViewId].size.height != m_panelContent->getBounds().size.height)
        {
            m_list->scrollRectToVisible(m_panelContent->getBounds(), VFX_FALSE);
        }
        else
        {
            m_list->scrollRectToVisible(m_formBounds[m_currentViewId], VFX_FALSE);
        }

        VfxAutoAnimate::commit();
        
    }

    
}

VfxS32 VappNCenter::createTabBar(VfxFrame *parent)
{   

#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("NCT", SA_start);
#endif 
    
    VfxS32 topGap = 0;
#ifdef __VAPP_NCENTER_UNIT_TEST__
    VappNCenterGridCell* grid;
    VFX_OBJ_CREATE(grid, VappNCenterGridCell, parent);        
    grid->setPos(0, MMI_STATUS_BAR_HEIGHT);
    topGap += grid->getSize().height;
#endif
    VFX_OBJ_CREATE(m_tabBar, VcpTabBar, parent);
    m_tabBar->setPos(0, topGap + MMI_STATUS_BAR_HEIGHT);

    VfxId sid[VAPP_NCENTER_TAB_TOTAL] = {0}, iid[VAPP_NCENTER_TAB_TOTAL] = {0};
    sid[0] = STR_ID_VAPP_NCENTER_NOTIFICATION;
    sid[1] = STR_ID_VAPP_NCENTER_ONGOING;    
    iid[0] = VAPP_IMG_NCENTER_TAB_ICON_NOTIFICATION;
    iid[1] = VAPP_IMG_NCENTER_TAB_ICON_ONGOING;
    
    for(int i=0; i < VAPP_NCENTER_TAB_TOTAL; ++i)
    {                
          m_tabBar->addTab(i, VcpStateImage(iid[i]), VFX_WSTR_RES(sid[i]));        
    }
    
    m_tabBar->setHighlightedTab(m_currentViewId);                
    m_tabBar->m_signalTabSwitched.connect(this, &VappNCenter::onTabSwitched);
    m_tabBar->setCacheMode(VFX_CACHE_MODE_FREEZE);       


#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("NCT", SA_stop);
#endif    

    return topGap + m_tabBar->getSize().height;
}
    

VfxS32 VappNCenter::onCreateContentTop(VfxFrame* parent)
{
    VfxS32 ret = 0;
    
    VFX_OBJ_CREATE(m_statusBar, VcpStatusIconBar, parent);
    m_statusBar->setBgColor(VFX_COLOR_WHITE);
    m_statusBar->setSize(getSize().width, MMI_STATUS_BAR_HEIGHT); 
    ret = MMI_STATUS_BAR_HEIGHT;
    
    if(VAPP_NCENTER_TAB_TOTAL > 1 && m_tabBarPos == VAPP_NCENTER_TABBAR_TOP)
    {        
        ret += createTabBar(parent);        
    }
    return ret;
}


VfxS32 VappNCenter::onCreateContentBottom(VfxFrame* parent)
{
 
    if(VAPP_NCENTER_TAB_TOTAL > 1 && m_tabBarPos == VAPP_NCENTER_TABBAR_BOTTOM)
    {
        return createTabBar(parent);        
    }
    return -1;
 
    
}

void VappNCenter::onCreateContentView(VfxId vid, VfxFrame* parent)
{    

#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("NCC", SA_start);
#endif

    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CREATE_CONTENT, vid);



    VFX_ASSERT(m_list == NULL);      
        
    VFX_OBJ_CREATE(m_list, VappNCenterList, parent);
    m_list->setPos(0, 0);
    m_list->setSize(m_panelContent->getSize());
    m_list->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_list->getFirstChildFrame()->setCacheMode(VFX_CACHE_MODE_PREVENT_PARENTS);


    if(vid == VAPP_NCENTER_TAB_NOTIFICATION)
    {  

#if defined(__MMI_SAFE_MODE__)
        // Safe mode cell.
        if (srv_safe_mode_is_active())
        {
            VFX_OBJ_CLOSE(m_safeModeCell);
            VFX_OBJ_CREATE(m_safeModeCell, VappSafeModeNotificationCell, parent);
            m_safeModeCell->setSize(getSize().width, m_safeModeCell->getSize().height);
            m_list->addMarginItem(VCP_BASE_MENU_MARGIN_AREA_TOP, VCP_BASE_MENU_MARGIN_AREA_FRAME_PLACEMENT_FULL, m_safeModeCell);        
        }
#endif /* defined(__MMI_SAFE_MODE__) */

        VFX_OBJ_CLOSE(m_operatorCell);
        VFX_OBJ_CREATE(m_operatorCell, VappNCenterOperatorCell, parent);
        m_operatorCell->m_signalRequestUpdate.connect(this, &VappNCenter::onRequestUpdate);                              
        m_list->addMarginItem(VCP_BASE_MENU_MARGIN_AREA_TOP, VCP_BASE_MENU_MARGIN_AREA_FRAME_PLACEMENT_FULL, m_operatorCell); // add here so removeMargin pos 0 will remove operator cell instead of safemode cell
        m_operatorCell->setIsFold(m_operatorCellIsFold);
        m_operatorCell->setAutoAnimate(VFX_TRUE);
    }    
    else if(vid == VAPP_NCENTER_TAB_ONGOING)
    {                      
        VFX_OBJ_CLOSE(m_quickSettingCell);
        VFX_OBJ_CREATE(m_quickSettingCell, VappQuickSettingCell, parent);
        m_quickSettingCell->setSize(getSize().width, m_quickSettingCell->getSize().height);
        m_list->addMarginItem(VCP_BASE_MENU_MARGIN_AREA_TOP, VCP_BASE_MENU_MARGIN_AREA_FRAME_PLACEMENT_FULL, m_quickSettingCell);
    }
    
    VfxList <VappNCenterGroupStruct> grouplist;
    grouplist.init(parent);

    VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
    VfxList <VsrvNGroup*>::It it;    
                    
    for (it = nm->getNGroups(); !it.isNull(); ++it)  
    {
        VsrvNGroup* group = *it;
        VfxList <VsrvNotification*>::It itt;        
        for (itt = group->getNotifications(); !itt.isNull() ; ++itt)
        {
            VsrvNotification *noti = *itt;
            if (checkNotification(noti))
            {                    
                VfxList <VappNCenterGroupStruct>::It ittt;        
                for (ittt = grouplist.begin(); !ittt.isNull(); ++ittt)
                {
                    VappNCenterGroupStruct data = *ittt;                        
                    VfxDateTime::CompareEnum result = noti->getTimeStamp().compareWith(data.groupTimeStamp);
                    if (result != VfxDateTime::LESS)
                    {
                        break;             
                    }                         
                }

                VappNCenterGroupStruct data;
                data.group = group;
                data.groupTimeStamp = noti->getTimeStamp();

                if (ittt.isNull())
                {
                    grouplist.pushBack(data);
                }
                else
                {
                    grouplist.insert(ittt, data);        
                }
                break;
                
            }                
        }            
    }

    VfxId refId = VAPP_NCENTER_INVALID_ID;
    VfxList <VappNCenterGroupStruct>::It ittt;
    for (ittt = grouplist.begin(); !ittt.isNull(); ++ittt)
    {
        VappNCenterGroupStruct gdata = *ittt;                        
        VsrvNGroup* group = gdata.group;
        if (group->getType() == VSRV_NGROUP_TYPE_SINGLE_TITLE)
        {
            VappNCenterListCellStruct data;
            data.timeStamp = gdata.groupTimeStamp;
            data.type = VAPP_NCENTER_LIST_CELL_TYPE_HEADER;                        
            m_list->addItem((VfxId)group, VAPP_NCENTER_CAPTION_HEIGHT, &data, sizeof(data));
            refId = (VfxId)group;
            
            MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CREATE_HEADER, group, group->getId(), group->getType());
        }
        
        VfxList <VsrvNotification*>::It itt;
        for (itt = group->getNotifications(); !itt.isNull() ; ++itt)
        {
            VsrvNotification *noti = *itt;
            if (checkNotification(noti))
            {
                createCell(noti, refId);
                refId = (VfxId) noti;   
            }                            
        }                  
    }
 
    
    if(vid == VAPP_NCENTER_TAB_NOTIFICATION)
    { 
        if (m_eventCount > 0)
        {                    
            createClearCell();                                
        }
        else
        {
            createNoTextFrame();
        }         
    }

    if (m_entered)
    {        
        VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        topLevel->captureFocus(m_list); //key support
    }

#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("NCC", SA_stop);
#endif    

}

void VappNCenter::createClearCell()
{
    if (m_noTextFrame)
    {
        m_list->removeMarginItem(m_noTextFrame);
        VFX_OBJ_CLOSE(m_noTextFrame);
    }    

    VfxBool create = VFX_FALSE;
    for (VfxS32 i = 0; i < m_list->getCellCount(); ++i)
    {
        VappNCenterListCellStruct* data = (VappNCenterListCellStruct*)m_list->getItemData(i);
        if (data->type != VAPP_NCENTER_LIST_CELL_TYPE_HEADER && data->type != VAPP_NCENTER_LIST_CELL_TYPE_END)
        {
            VsrvNotification* noti = (VsrvNotification*) m_list->getItemId(i);                
            if (!(noti->getFlag() & VSRV_NOTIFICATION_FLAG_NO_CLEAR_BUTTON))
            {
                create = VFX_TRUE;                
                break;
            }
        }
    }    

    
    if (create && !m_clearCell)
    {        
        VFX_OBJ_CREATE(m_clearCell, VappNCenterClearCell, m_list);
        m_clearCell->setBounds(0, 0, getSize().width, VAPP_NCENTER_CLEAR_CELL_HEIGHT);
        m_clearCell->m_clearButton->m_signalClicked.connect(this, &VappNCenter::onEventClearAll);
        m_list->addMarginItem(VCP_BASE_MENU_MARGIN_AREA_BOTTOM, VCP_BASE_MENU_MARGIN_AREA_FRAME_PLACEMENT_FULL, m_clearCell);
    }
    else if (!create && m_clearCell)
    {
        m_list->removeMarginItem(m_clearCell);
        VFX_OBJ_CLOSE(m_clearCell);                
    }

}


void VappNCenter::createNoTextFrame()
{
    if (m_clearCell)
    {
        m_list->removeMarginItem(m_clearCell);
        VFX_OBJ_CLOSE(m_clearCell); 
    }
                        
    if (!m_noTextFrame)
    {
        VFX_OBJ_CREATE(m_noTextFrame, VfxTextFrame, m_list);
        m_noTextFrame->setString(VFX_WSTR_RES(STR_ID_VAPP_NCENTER_NO_NOTIFICATION));
        

    #if defined(__MMI_VUI_COSMOS_CP__)
        m_noTextFrame->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_EMPTY));
        m_noTextFrame->setFont(VFX_FONT_RES(FNT_COSMOS_TEXT_EMPTY));            
    #else /* defined(__MMI_VUI_COSMOS_CP__) */
        m_noTextFrame->setColor(VFX_COLOR_GREY);
    #endif /* defined(__MMI_VUI_COSMOS_CP__) */
        
        m_noTextFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);    
        m_noTextFrame->setSize(getSize().width, VAPP_NCENTER_EVENT_CELL_HEIGHT);
        m_noTextFrame->setVerticalToCenter(VFX_TRUE);
        m_noTextFrame->setAutoResized(VFX_FALSE);
        m_noTextFrame->setAutoAnimate(VFX_TRUE);
        m_list->addMarginItem(VCP_BASE_MENU_MARGIN_AREA_BOTTOM, VCP_BASE_MENU_MARGIN_AREA_FRAME_PLACEMENT_FULL, m_noTextFrame); 
    }    
}



void VappNCenter::onCloseContentView(VfxId vid)
{ 
#ifdef __MAUI_SOFTWARE_LA__
     SLA_CustomLogging("NOC", SA_start);
#endif   

    
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CLOSE_CONTENT, vid);

   if(vid == VAPP_NCENTER_TAB_NOTIFICATION)
   {                 
#if defined(__MMI_SAFE_MODE__)
        VFX_OBJ_CLOSE(m_safeModeCell); 
#endif
       VFX_OBJ_CLOSE(m_operatorCell); 
       VFX_OBJ_CLOSE(m_clearCell);
       VFX_OBJ_CLOSE(m_noTextFrame);
       m_eventCount = 0;
   } 
   else if(vid == VAPP_NCENTER_TAB_ONGOING)
   {
       VFX_OBJ_CLOSE(m_quickSettingCell); 
       m_ongoingCount = 0;    
   }
   
   if (m_list)
   {
       VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
       topLevel->releaseFocus(m_list);
   }
   VFX_OBJ_CLOSE(m_list);   

#ifdef __MAUI_SOFTWARE_LA__
     SLA_CustomLogging("NOC", SA_stop);
#endif      
}

void VappNCenter::releaseSystemView()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("NRS", SA_start);
#endif  

    
    onCloseContentView(m_currentViewId);
    
    VFX_OBJ_CLOSE(m_statusBar);    
    VFX_OBJ_CLOSE(m_panelContent);    
    VFX_OBJ_CLOSE(m_panel);
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("NRS", SA_stop);
#endif  

    
}

void VappNCenter::requestLeave(VsrvNotification* noti)
{
    if (m_callbackNoti == NULL)
    {
        MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_REQUEST_LEAVE, noti, noti->getGroupId(), noti->getId(), noti->getType());        
        m_callbackNoti = noti;
        leave();
    }
}


void VappNCenter::onNotificationChanged(VsrvNotification* noti, VsrvNStatusType status)
{
    // won't update if hidden or there is a screen above NCenter (m_disableLeave is true)
    if (getHidden() == VFX_FALSE && (!m_disableLeave || status == VSRV_NSTATUS_CLOSE))
    {   
        VappNCenterListCellStruct* data = (VappNCenterListCellStruct*)m_list->getItemData((VfxId)noti);
        
        if (checkNotification(noti) || data)
        {

            MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_NOTI_CHANGED, noti, status);      

            VfxBool refresh = VFX_FALSE;
            VfxBool create = VFX_FALSE;
            VfxId refId = VAPP_NCENTER_INVALID_ID;
			VfxBool addBeforeRef;
            
            VsrvNGroup *group = noti->getGroup();

            VfxS32 count = 0;
            VfxList <VsrvNotification*>::It itt;
            for (itt = group->getNotifications(); !itt.isNull() ; ++itt)
            {
                VsrvNotification *n = (*itt);
                if (checkNotification(n))
                {
                    count++;
                }                                   
            }   

            switch (status)
            {
                case VSRV_NSTATUS_CREATE:
                {
                    if (count == 1)                
                    {                       
                        create = VFX_TRUE;                               
                    }                     
                    else
                    {               
                        refresh = VFX_TRUE;
                    }
                }
                    break;
                case VSRV_NSTATUS_UPDATE:
                {                    
                    if (data)
                    {
                        VfxDateTime::CompareEnum result = noti->getTimeStamp().compareWith(data->timeStamp);
                        if ((result == VfxDateTime::EQUAL || count == 1) && checkIsTheSameType(noti, data))
                        {
                            if (noti->getFlag() & VSRV_NOTIFICATION_FLAG_NO_NSS)
                            {
                                if (count == 0)
                                {                                
                                    m_list->removeItem((VfxId)group);                        
                                    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CLOSE_HEADER, group, group->getId(), group->getType());      
                                }
                                closeCell(noti);     
                            }                                                   
                            else
                            {
                                m_list->updateItem((VfxId)group);
                                m_list->updateItem((VfxId)noti);                                
                            }                        
                        }                              
                        else
                        {
                            if (checkNotification(noti))
                            {
                                if (count == 1)
                                {
                                    create = VFX_TRUE;
                                }
                                else
                                {
                                    closeCell(noti);    
                                    refresh = VFX_TRUE;                
                                }                            
                            }
                            else
                            {
                                closeCell(noti);
                            
                                if (count == 0)
                                {
                                    m_list->removeItem((VfxId)group);                        
                                    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CLOSE_HEADER, group, group->getId(), group->getType());                                                        
                                }                            
                            }
                        }
                    }
                    else
                    {
                        if (count == 1)                
                        {                       
                            create = VFX_TRUE;                               
                        }                     
                        else
                        {               
                            refresh = VFX_TRUE;
                        }
                    }
                }
                    break;
                case VSRV_NSTATUS_CLOSE:
                {
                    if (closeCell(noti))
                    {
                        if (count == 1) // this group will be closed
                        {
                            m_list->removeItem((VfxId)group);
                            MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CLOSE_HEADER, group, group->getId(), group->getType());
                        }
                        else
                        {
                            m_list->updateItem((VfxId)group);
                        }                      
                    }
                }
                    break;
                default:
                    break;
                
            }                     

            if (create)
            {
                MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_NOTI_CHANGED_CREATE);      
                
                if (group->getType() == VSRV_NGROUP_TYPE_SINGLE_TITLE)
                {
                    VappNCenterListCellStruct data;
                    data.type = VAPP_NCENTER_LIST_CELL_TYPE_HEADER;                    
                    data.timeStamp = noti->getTimeStamp();
                    m_list->insertItem((VfxId)group, VAPP_NCENTER_CAPTION_HEIGHT, 0, &data, sizeof(data));                        
                    refId = (VfxId)group;

                    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CREATE_HEADER, group, group->getId(), group->getType());
                }   
                if (refId == VAPP_NCENTER_INVALID_ID && m_list->getCellCount() != 0)
                {
                    refId = m_list->getItemId(0);
                    addBeforeRef = VFX_TRUE;
                }
                else
                {
                    addBeforeRef = VFX_FALSE;  // add to back         
                }				
                createCell(noti, refId, addBeforeRef);
            }            
            else if (refresh)
            {
                MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_NOTI_CHANGED_REFRESH);      

                m_list->updateItem((VfxId)group);
                VsrvNotification *target = noti->getPrevious();
                while(target)
                {
                    if (checkNotification(target))
                    {
                        break;                        
                    }
                    target = target->getPrevious();
                }
                if (target)
                {
                    createCell(noti, (VfxId)target, VFX_FALSE);                                        
                }
                else
                {
                    target = noti->getNext();
                    while(target)
                    {
                        if (checkNotification(target))
                        {
                            break;                        
                        }
                        target = target->getNext();
                    }
                    if (target)
                    {
                        createCell(noti, (VfxId)target, VFX_TRUE);                        
                    }
                }                
            }           
                      
                        
            if (m_currentViewId == VAPP_NCENTER_TAB_NOTIFICATION)
            { 
                if (m_eventCount > 0)
                {                    
                    createClearCell();                                
                }
                else
                {
                    createNoTextFrame();
                }         
            }

            m_list->makeVisible(m_list->getFocusItem(), VFX_TRUE);
        }   
    }  
}

VfxBool VappNCenter::checkIsTheSameType(VsrvNotification *noti, VappNCenterListCellStruct* data)
{
    if ((data->type == VAPP_NCENTER_LIST_CELL_TYPE_EVENT && noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT) ||
        (data->type == VAPP_NCENTER_LIST_CELL_TYPE_ONGOING && noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING))
    {
        return VFX_TRUE;
    }
        
    if(noti->getType() == VSRV_NOTIFICATION_TYPE_CUSTOM)
    {
        VsrvNotificationCustom* cust = (VsrvNotificationCustom*)noti;       
        if ((data->type == VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_EVENT && cust->getCategory() == VSRV_NOTIFICAITON_CUSTOM_CATEGORY_EVENT) ||
            (data->type == VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_ONGOING && cust->getCategory() == VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING))        
        {
            return VFX_TRUE;
        }            
    }    

    return VFX_FALSE;
}



VfxBool VappNCenter::checkNotification(VsrvNotification *noti)
{
    U16 settingValue = 1;

#ifdef  __MMI_NSS_SUPPORT__
    //check APP's NSS setting
    mmi_srv_nss_get_setting(noti->getGroupId(), NSS_SETTING_NCENTER, &settingValue);
#endif

    VfxBool ret = VFX_FALSE;
          
    if ((settingValue || (noti->getFlag() & VSRV_NOTIFICATION_FLAG_NO_NSS)) && noti->getIsStable())
    {
        if (m_currentViewId == VAPP_NCENTER_TAB_NOTIFICATION && noti->getType() == VSRV_NOTIFICATION_TYPE_EVENT ||
            m_currentViewId == VAPP_NCENTER_TAB_ONGOING && noti->getType() == VSRV_NOTIFICATION_TYPE_ONGOING)
        {
            ret = VFX_TRUE;
        }

        if(noti->getType() == VSRV_NOTIFICATION_TYPE_CUSTOM)
        {
            VsrvNotificationCustom* cust = (VsrvNotificationCustom*)noti;
            if (m_currentViewId == VAPP_NCENTER_TAB_NOTIFICATION && cust->getCategory() == VSRV_NOTIFICAITON_CUSTOM_CATEGORY_EVENT ||
                m_currentViewId == VAPP_NCENTER_TAB_ONGOING && cust->getCategory() == VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING)
            {
                ret = VFX_TRUE;
            }            
        }
    }

    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CHECK_NOTIFICATION, noti, noti->getGroupId(), noti->getId(), noti->getType(), noti->getIsStable(), ret);
    
    return ret;
}


VfxBool VappNCenter::closeCell(VsrvNotification *noti)
{
    VfxBool ret = VFX_FALSE;
    
    VappNCenterListCellStruct* data = (VappNCenterListCellStruct*)m_list->getItemData((VfxId)noti);
    if (data)
    {
        VappNCenterListCellType type = data->type;
        VfxBool removed = m_list->removeItem((VfxId)noti);
        if (removed)
        {
            if (type == VAPP_NCENTER_LIST_CELL_TYPE_EVENT || type == VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_EVENT)
            {
               m_eventCount--;            
            }
            else if (type == VAPP_NCENTER_LIST_CELL_TYPE_ONGOING || type == VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_ONGOING)
            {
                m_ongoingCount--;
            }            
            ret = VFX_TRUE;
        }    
        
    }    


    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CLOSE_CELL, noti, noti->getGroupId(), noti->getId(), noti->getType());
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CELL_COUNT, m_eventCount, m_ongoingCount);

    return ret;    
}



VfxBool VappNCenter::createCell(VsrvNotification *noti, VfxId refId, VfxBool addBeforeRef)
{      
    VappNCenterListCellStruct data;
	VfxS32 h;
	switch(noti->getType())
	{
	
	    case VSRV_NOTIFICATION_TYPE_EVENT:
	    {
	        m_eventCount++;                
	        data.type = VAPP_NCENTER_LIST_CELL_TYPE_EVENT; 
			h = VAPP_NCENTER_ONGOING_CELL_HEIGHT;
			break;	        
	    }
	    case VSRV_NOTIFICATION_TYPE_ONGOING:
	    {
	        m_ongoingCount++;           
	        data.type = VAPP_NCENTER_LIST_CELL_TYPE_ONGOING;      
			h = VAPP_NCENTER_ONGOING_CELL_HEIGHT;
			break;
	    }
	    case VSRV_NOTIFICATION_TYPE_CUSTOM:
	    {            
	        VsrvNotificationCustom *n = (VsrvNotificationCustom*) noti;
	        if (n->getCategory() == VSRV_NOTIFICAITON_CUSTOM_CATEGORY_EVENT)
	        {
	            data.type = VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_EVENT;
	            m_eventCount++;                           
	        }
	        else if (n->getCategory() == VSRV_NOTIFICAITON_CUSTOM_CATEGORY_ONGOING)
	        {
	            data.type = VAPP_NCENTER_LIST_CELL_TYPE_CUSTOM_ONGOING;
	            m_ongoingCount++;
	        } 
	        
	        h = n->getHeight();
			break;
	    }
		default:
			return VFX_FALSE;   
	}
	
	data.timeStamp = noti->getTimeStamp(); 
	if (refId == VAPP_NCENTER_INVALID_ID)
	{
		m_list->addItem((VfxId) noti, h, &data, sizeof(data));
	}
	else
	{
		m_list->insertItem((VfxId) noti, h, refId, addBeforeRef, &data, sizeof(data));
	} 
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CREATE_CELL, noti, noti->getGroupId(), noti->getId(), noti->getType(), refId, addBeforeRef);
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_CELL_COUNT, m_eventCount, m_ongoingCount);
    return VFX_TRUE;
}


void VappNCenter::setBounds(const VfxRect &value)
{
    VfxRect old = getBounds();    
    VfxControl::setBounds(value);

    if (value != old)
    {
    	VfxS32 w = getSize().width;
        if (m_statusBar)
        {
            m_statusBar->setSize(w, m_statusBar->getSize().height);
        }    

        if (m_quickSettingCell)
        {
            m_quickSettingCell->setWidth(w);
        }
    }
}



void VappNCenter::onActiveScreenEnter(VfxWeakPtr<VfxScreen> scr)
{
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_ON_SCREEN_CHANGED, getHidden());    

    if (getHidden() == VFX_FALSE)
    {
        if (m_disableLeave == VFX_FALSE)
        {            
            if (m_list)
            {
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->releaseFocus(m_list);
            }
            leaveInternal();
        }
        else
        {        
            if(m_callbackNoti == NULL)
            {
                VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
                topLevel->captureFocus(m_list);
                VfxAutoAnimate::begin();
                VfxAutoAnimate::setDisable(VFX_TRUE);
                setBounds(topLevel->getBounds());                
                VfxAutoAnimate::commit();
            }
        }
    }
    m_disableLeave = VFX_FALSE;
}
 

void VappNCenter::onActiveScreenExit(VfxWeakPtr<VfxScreen> scr)
{
#ifdef __COSMOS_MMI_PACKAGE__
    // when drag it should leave immediately.
    if (m_isDrag)
    {
        VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        topLevel->releaseFocus(m_list);

        leaveInternal();
    }
#else     
    if (m_ncenterScrPtr.get())
    {
        leaveInternal();
    }     
#endif        
}



void VappNCenter::onRotate(VfxScreenRotateParam param)
{   
    if (getHidden() == VFX_FALSE)
    {
        VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        setBounds(topLevel->getBounds());                
        VfxAutoAnimate::commit();
    }    
}


void VappNCenter::leaveInternal()
{
    if (getHidden() == VFX_FALSE && m_list)
    {
        MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_LEAVE_INTERNAL);

        vfx_adp_srs_resume();        

#ifdef __COSMOS_MMI_PACKAGE__
        wgui_status_icon_bar_leave_ncenter();
#endif

        setHidden(VFX_TRUE);    
        releaseSystemView();        
        removeFromParentFrame();

        setIsDisabled(VFX_FALSE);

        m_entered = VFX_FALSE;
        m_isDrag = VFX_FALSE;
        m_operatorCellIsFold = VFX_TRUE;

        m_leaveTimer->start(); // 2 statges leaving to let VRT render 1 more frame first


#ifdef __COSMOS_MMI_PACKAGE__


        VFX_OBJ_CLOSE(m_uiContext);

        if (m_memPtr)
        {            
            vadpAsmFree(m_asmId, m_memPtr);            
            m_memPtr = NULL;
        }        

        mmi_frm_group_close(m_asmId);
        m_asmId = GRP_ID_INVALID;

#endif

    }
}

void VappNCenter::leaveInternalEx(VfxTimer *source)
{    
    MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_LEAVE_INTERNAL_EX);
        
    emitEvent(VAPP_NCENTER_EVENT_EXITED);   
    
    VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
    if (m_callbackNoti)
    {
        MMI_TRACE(TRACE_GROUP_10, TRC_VAPP_NCENTER_AFTER_REQUEST_LEAVE, m_callbackNoti, m_callbackNoti->getAutoLaunch(), m_callbackNoti->getAutoClose(VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_LAUNCH), m_callbackNoti->getAutoClose(VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_REQUEST_LEAVE));

        VsrvNotification* tmp = m_callbackNoti;
        m_callbackNoti = NULL;
		VfxBool autoClose;
		VfxU32 flg;
        VfxS32 serialNum = tmp->getSerialNum();
		VsrvNIntentType intentType;
        if (tmp->getAutoLaunch())
        {
        	flg = VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_LAUNCH;
			intentType = VSRV_NINTENT_TYPE_LAUNCH;                    
        }
        else
        {
        	flg = VSRV_NOTIFICATION_FLAG_AUTO_CLOSE_AFTER_REQUEST_LEAVE;
			intentType = VSRV_NINTENT_TYPE_AFTER_REQUEST_LEAVE;
        }
        autoClose = tmp->getAutoClose(flg);
        nm->sendIntent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, intentType, tmp);
		if (autoClose && nm->checkNotification(tmp) && tmp->getSerialNum() == serialNum)
        {
            nm->sendIntent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_CLOSE, tmp);
            VSRV_NOTIFICATION_CLOSE(tmp);
        }
    }   
     
    nm->sendIntent(VSRV_NVIEWER_TYPE_VAPP_NCENTER, VSRV_NINTENT_TYPE_EXITED, VSRV_NOTIFICATION_TYPE_CUSTOM);
    
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_NCENTER);  

    
}



/***************************************************************************** 
 * Class VappNCenterScr 
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappNCenterScr", VappNCenterScr, VfxAppCatScr);
void VappNCenterScr::onInit()
{
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    m_dir = renderer->getPreScreenRotateType();
    renderer->setScreenRotateType(m_dir);
    
    VfxAppCatScr::onInit();

    VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    NCenter->setNCenterScr(this);
}

static mmi_ret vapp_ncenter_close_scr(mmi_event_struct *evt)
{
    VFX_UNUSED(evt);
    mmi_frm_scrn_close(GRP_ID_ROOT, SCR_ID_NCENTER);  
    return MMI_RET_OK;
}     
void VappNCenterScr::onEnter(VfxBool isBackward)
{
    VfxAppCatScr::onEnter(isBackward);

    VappNCenter *NCenter = VFX_OBJ_GET_INSTANCE(VappNCenter);
    if (isBackward)
    {
        // close scr only when disableLeave = false
        if (NCenter->getDisableLeaveOnScreeChange() == FALSE)
        {            
            // use MMI_FRM_POST_EVENT instead vfxPostInvoke0 to ensure post event after pluto entering flow
            mmi_event_struct postInvoke;
            MMI_FRM_INIT_EVENT(&postInvoke, 0);
            MMI_FRM_POST_EVENT(&postInvoke, vapp_ncenter_close_scr, NULL);           
        }
    }
    else
    {
        NCenter->disableLeaveOnScreenChange();
        NCenter->enter();
    }
}

void VappNCenterScr::onQueryRotateEx(VfxScreenRotateParam &param)
{
    param.rotateTo = m_dir;
}


    
#endif /* defined(__MMI_NCENTER_SUPPORT__) && !defined(__MMI_KEY_ONLY_NCENTER__) */

