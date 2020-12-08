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
 *  vfx_app.cpp
 *
 * Project:
 * --------
 *  Venus FW
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
// by RHR //#include "vfx_mmi.h"
#include "vfx_app.h"
#include "vfx_app_scr.h"
#include "vfx_app_launcher.h"
#include "trc\vadp_sys_trc.h"
#include "vfx_adp_sse.h"
#include "vfx_logger.h"
#include "vfx_mmi.h"

extern "C"
{
#include "string.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"

#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_res_range_def.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_cb_mgr_gprot.h"       // for mmi_frm_cb_reg_event
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "app_mem.h"
#include "fix_size_mem.h"
#include "mmi_frm_prot.h"           // for get_active_history_node_id
#include "wgui_categories.h"
extern kal_uint32 applib_mem_ap_get_single_usage(kal_uint32 app_id);
extern void mmi_frm_enable_anti_blink(MMI_BOOL enable);
}

#include "vfx_config.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_system.h"
#include "vfx_context.h"
#include "vrt_datatype.h"
#include "vfx_signal.h"
#include "vapp_platform_context.h"



/***************************************************************************** 
 * Define
 *****************************************************************************/

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

#if defined(VFX_CFG_SOFTWARE_LA)
#undef __MAUI_SOFTWARE_LA__
#define __MAUI_SOFTWARE_LA__
#endif

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif

#define VFX_APP_CLOSE_STATE_NONE        0x0

#define VFX_APP_CLOSE_STATE_ENDKEY      (VFX_APP_CLOSE_REASON_ENDKEY_FLAG << 16)
#define VFX_APP_CLOSE_STATE_OOM         (VFX_APP_CLOSE_REASON_OOM_FLAG    << 16)
#define VFX_APP_CLOSE_STATE_PLUTO       (VFX_APP_CLOSE_REASON_PLUTO_FLAG  << 16)

#define VFX_APP_CLOSE_STATE_REASON(x)   ((x) & 0xFFFF0000)
#define VFX_APP_CLOSE_REASON_FLAG(x)    ((x) >> 16)

#define VFX_APP_CLOSE_OPTION_ENDKEY     (VFX_APP_CLOSE_OPTION_YES_FLAG | VFX_APP_CLOSE_OPTION_NO_FLAG | VFX_APP_CLOSE_OPTION_BG_FLAG | VFX_APP_CLOSE_OPTION_LATER_FLAG)
#define VFX_APP_CLOSE_OPTION_OOM        (VFX_APP_CLOSE_OPTION_YES_FLAG | VFX_APP_CLOSE_OPTION_LATER_FLAG)
#define VFX_APP_CLOSE_OPTION_PLUTO      (VFX_APP_CLOSE_OPTION_YES_FLAG | VFX_APP_CLOSE_OPTION_NO_FLAG | VFX_APP_CLOSE_OPTION_LATER_FLAG)


/***************************************************************************** 
 * Debug Trace
 *****************************************************************************/

#define __VFX_APP_ENABLE_EVENT_PRINT__

typedef struct {
    VfxU16 evt;
    const VfxChar *name;
} evt_name_struct;

typedef struct {
    VfxU16 state;
    const VfxChar *name;
} state_name_struct;

typedef void (*mmi_frm_evt_print_fptr)(VfxU8 *str_prefix, mmi_event_struct *evt);

typedef struct {
    VfxU32 id_start;
    VfxU32 id_end;
    mmi_frm_evt_print_fptr print_func;
} mmi_frm_evt_print_struct;

#ifdef __AFX_RT_TEST__

const evt_name_struct evt_name[] = {
    {EVT_ID_POST_CB_RST,        "POST_CB_RST"},
    {EVT_ID_POST_DEREG_CB,      "POST_DEREG_CB"},
    {EVT_ID_SCENAIO_CHANGE,     "SCENAIO_CHANGE"},
    {EVT_ID_GROUP_FIRST_ENTRY,  "GROUP_FIRST_ENTRY"},
    {EVT_ID_GROUP_ACTIVE,       "GROUP_ACTIVE"},
    {EVT_ID_GROUP_INACTIVE,     "GROUP_INACTIVE"},
    {EVT_ID_GROUP_GOBACK,       "GROUP_GOBACK"},
    {EVT_ID_GROUP_DELETE_REQ,   "GROUP_DELETE_REQ"},
    {EVT_ID_GROUP_DEINIT,       "GROUP_DEINIT"},
    {EVT_ID_SCRN_ACTIVE,        "SCRN_ACTIVE"},
    {EVT_ID_SCRN_INACTIVE,      "SCRN_INACTIVE"},
    {EVT_ID_SCRN_GOBACK,        "SCRN_GOBACK"},
    {EVT_ID_SCRN_DELETE_REQ,    "SCRN_DELETE_REQ"},
    {EVT_ID_SCRN_DEINIT,        "SCRN_DEINIT"},
    {EVT_ID_MEM_FREE_ASM,       "MEM_FREE_ASM"},
    {EVT_ID_MEM_IS_ENOUGH,      "MEM_IS_ENOUGH"},
    {EVT_ID_MEM_CANCELED,       "MEM_CANCELED"},
};

const state_name_struct state_name[] = {
    {MMI_SCENARIO_STATE_NONE,               "NONE"},
    {MMI_SCENARIO_STATE_ACTIVE,             "ACTIVE"},
    {MMI_SCENARIO_STATE_INACTIVE,           "INACTIVE"},
    {MMI_SCENARIO_STATE_CREATE,             "CREATE"},
    {MMI_SCENARIO_STATE_FIRST_ENTRY,        "FIRST_ENTRY"},
    {MMI_SCENARIO_STATE_FORWARD,            "FORWARD"},
    {MMI_SCENARIO_STATE_FORWARD_ACTIVE,     "FORWARD_ACTIVE"},
    {MMI_SCENARIO_STATE_FORWARD_INACTIVE,   "FORWARD_INACTIVE"},
    {MMI_SCENARIO_STATE_BACKWARD,           "BACKWARD"},
    {MMI_SCENARIO_STATE_BACKWARD_ACTIVE,    "BACKWARD_ACTIVE"},
    {MMI_SCENARIO_STATE_BACKWARD_INACTIVE,  "BACKWARD_INACTIVE"},
    {MMI_SCENARIO_STATE_REDRAW,             "REDRAW"},
    {MMI_SCENARIO_STATE_CLOSE_IND,          "CLOSE_IND"},
    {MMI_SCENARIO_STATE_DELETE_REQ,         "DELETE_REQ"},
    {MMI_SCENARIO_STATE_DEINIT,             "DEINIT"},
};

void print_scenario_evt(PU8 str_prefix, mmi_scenario_evt_struct *evt)
{
#ifndef __MTK_TARGET__

    VfxU32 i;
    for (i=0; i<sizeof(evt_name)/sizeof(evt_name_struct); i++)
        if (evt_name[i].evt == evt->evt_id)
            VFX_TRACE(("===> [%s](%d, %d) %s\n", str_prefix, evt->targ_group, evt->targ_scrn, evt_name[i].name));

    for (i=0; i<sizeof(state_name)/sizeof(state_name_struct); i++)
        if (state_name[i].state == evt->state)
            VFX_TRACE(("===> [%s](%d, %d) %s\n", str_prefix, evt->targ_group, evt->targ_scrn, state_name[i].name));   
#else
    VFX_UNUSED(str_prefix);
    VFX_UNUSED(evt);
#endif
}


mmi_frm_evt_print_struct evt_print_table[] = {
    {EVT_ID_POST_CB_RST, EVT_ID_SCENARIO_MAX, (mmi_frm_evt_print_fptr)print_scenario_evt},
};

#endif // __AFX_RT_TEST__

void print_event(PU8 str_prefix, mmi_event_struct *evt)
{
#ifdef __AFX_RT_TEST__
#ifdef __VFX_APP_ENABLE_EVENT_PRINT__
    VfxU32 i, i_max = sizeof(evt_print_table)/sizeof(mmi_frm_evt_print_struct);
    for (i=0; i<i_max; i++)
        if ((evt_print_table[i].id_start <= evt->evt_id) && (evt->evt_id <= evt_print_table[i].id_end))
            evt_print_table[i].print_func(str_prefix, evt);
#endif /* #ifdef __VFX_APP_ENABLE_EVENT_PRINT__ */
#else
    VFX_UNUSED(str_prefix);
    VFX_UNUSED(evt);
#endif
}

typedef struct {
    void* user_cb;
    void* user_data;
    void* handle;
} vfx_app_enlarge_heap_data_struct;

mmi_id vfx_get_prev_app_group_id(mmi_id group_id)
{
    mmi_id prev_id = GRP_ID_INVALID;

#ifdef __MMI_FRM_HISTORY__
    /* Pluto has many tricks, put them in one place. */
    if(group_id == get_active_history_node_id())
    {
        prev_id = GetCurrScrnId();
    }
    else
    {
        GetPreviousScrnIdOf(group_id, &prev_id);
    }
#else
	prev_id = mmi_frm_scrn_get_neighbor_id(GRP_ID_ROOT, group_id, MMI_FRM_NODE_BEFORE_FLAG);
#endif
    
    return prev_id;
}

static mmi_ret vfx_app_check_group_empty(mmi_event_struct *param)
{
    VFX_LOG_STATIC_FUNC1("(%d)", param->evt_id);
    VfxApp *app = VfxApp::getObject(param->evt_id);
    if(app && app->getScreenCount() == 0)
    {
        app->exit();
    }
    return MMI_RET_OK;
}

static void vfx_app_entry_dummy_screen()
{
    if(mmi_frm_scrn_enter(GRP_ID_ROOT, SCR_ID_DUMMY, NULL, vfx_app_entry_dummy_screen, MMI_FRM_FULL_SCRN))
    {
        ShowCategoryDummyScreen();
        mmi_frm_scrn_clear_attribute(GRP_ID_ROOT, SCR_ID_DUMMY, MMI_SCRN_ATTRIB_ADD_HISTORY);
    }
}

AppHistoryNode::AppHistoryNode() :
    groupId(GRP_ID_INVALID), 
    flag(0), 
    classInfo(NULL),
    logContext(VFX_FALSE),
    serializeData(NULL),
    serializeDataSize(0)
{
}

AppHistoryNode::~AppHistoryNode()
{
    if (serializeData)
    {
        VFX_FREE_MEM(serializeData);
    }
}

/***************************************************************************** 
 * Class VfxApp
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("App", VfxApp, VfxObject);

VfxApp::VfxApp() :
    m_groupId(SCR_ID_INVALID),
    m_callerId(SCR_ID_INVALID),
    m_pTopScreen(NULL),
    m_appState(APP_STATE_INIT),
    m_launcher(NULL),
    m_needToFreeCtx(VFX_TRUE),
    m_logContext(VFX_FALSE),
    m_CABCMode(0xFF),
    m_DynHeapSetting(VFX_APP_NO_DYN_HEAP),
    m_closeState(VFX_APP_CLOSE_STATE_NONE),
    m_skipDeleteCheck(VFX_FALSE)
{
}

VfxApp::~VfxApp()
{
}


void VfxApp::onRun(void* args, VfxU32 argSize) 
{
    VFX_LOG(VFX_INFO, VFX_APP_ON_RUN, m_groupId, args, argSize);
    VFX_UNUSED(args);
    VFX_UNUSED(argSize);
}


VfxContext* VfxApp::getContext() const
{
    VFX_DEV_ASSERT(getParent()->isKindOf(VFX_OBJ_CLASS_INFO(VfxContext)));
    return (VfxContext*) getParent();
}

VfxApp * VfxApp::getObject(mmi_id gid)
{
    VfxObject *obj = (VfxObject *)VfxObject::handleToObject((VfxObjHandle)mmi_frm_group_get_user_data(gid));

    if (!obj)
        return NULL;

    if (obj->isKindOf(VFX_OBJ_CLASS_INFO(VfxAppLauncher)))
        return NULL;
    
    if (obj->isKindOf(VFX_OBJ_CLASS_INFO(VfxApp)))
    {
        if (((VfxApp *)obj)->getGroupId() == gid)
        {
            return (VfxApp *)obj;
        }
        else
        {
            /* Pluto screen group? */
            return NULL;
        }
    }

    return NULL;
}

void VfxApp::closeScreen(mmi_id screenId)
{
    VFX_LOG_FUNC1("%d", screenId);
    void* arg = mmi_frm_scrn_get_user_data(m_groupId, screenId);
    if (!arg)
        return;

    VfxAppScr::HistoryNode* node = (VfxAppScr::HistoryNode*) arg;
    node->flag |= VFX_SCR_HISTORY_NODE_SKIP_DEL_CHECK_FLAG;

    VfxWeakPtr<VfxApp> appPtr = this; // to check if the app object is still valid
    
    mmi_frm_scrn_close (m_groupId, screenId);
    
    if (!appPtr->isValid())
    {
        return;
    }

    if(getScreenCount() == 0)
    {
        // Notify application the screen count is 0. The VfxApp will be closed afterward.
        onScrEmpty();
    
        //vfxPostInvoke1(this, &VfxApp::postCheckEmpty, m_groupId);
    }

    mmi_event_struct evt;
    MMI_FRM_INIT_EVENT(&evt, m_groupId);
    mmi_frm_post_event(&evt, vfx_app_check_group_empty, NULL);
}

VfxAppScr* VfxApp::getScreen(mmi_id screenId) const
{
    if(screenId < VENUS_FW_BASE || screenId >= VENUS_FW_BASE_MAX)
        return NULL;
    
    void* arg = mmi_frm_scrn_get_user_data(m_groupId, screenId);

    if (arg)
    {
        VfxAppScr::HistoryNode* node = (VfxAppScr::HistoryNode*) arg;
        return node->screen.get();
    }
    return NULL;
}

mmi_id VfxApp::getCallerId() const
{
    mmi_group_node_struct info;

    info.caller = GRP_ID_INVALID;
    mmi_frm_group_get_info(m_groupId, &info);
    return info.caller;
}

VfxU32 VfxApp::getDynHeapSetting() const
{
#if !defined(__MMI_USE_MMV2__)
    VFX_ASSERT(0);
#endif
    return m_DynHeapSetting;
}

void VfxApp::setDynHeapSetting(VfxAppDynHeapSettingEnum flag)
{
#if !defined(__MMI_USE_MMV2__)
    VFX_ASSERT(0);
#endif
    m_DynHeapSetting = flag;
}
mmi_ret VfxApp::sendToCaller(mmi_group_event_struct *evt)
{
    VFX_LOG_FUNC1("%d", evt->evt_id);
    return mmi_frm_group_send_to_caller(m_groupId, evt);
}

void VfxApp::postToCaller(mmi_group_event_struct *evt, VfxAppPostToCallerCb cb /*= NULL*/)
{
    VFX_LOG_FUNC1("%d", evt->evt_id);
    mmi_group_node_struct info;

    if (mmi_frm_group_get_info(m_groupId, &info) == MMI_RET_OK)
    {
        VfxAppPostToCallerCb *cbPtr;
        VFX_SYS_NEW_EX(cbPtr, VfxAppPostToCallerCb, (cb));

        if(info.caller_proc)
        {
            MMI_FRM_POST_EVENT_EX(evt, info.caller_proc, info.caller_user_data, &VfxApp::static_postToCallerResultCb, cbPtr);
        }
        else
        {
            mmi_group_node_struct caller_info;

            if (mmi_frm_group_get_info(info.caller, &caller_info) == MMI_RET_OK)
            {
                MMI_FRM_POST_EVENT_EX(evt, caller_info.proc, caller_info.user_data, &VfxApp::static_postToCallerResultCb, cbPtr);
            }
        }
    } 
}

mmi_ret VfxApp::onProc(mmi_event_struct *evt)
{
    //VfxApp* app = (VfxApp*) evt->user_data;
    VFX_UNUSED(evt);

    return MMI_RET_OK;
}

VfxAppCloseAnswerEnum VfxApp::onProcessClose(VfxAppCloseOption options)
{
    VFX_UNUSED(options);
    
    return VFX_APP_CLOSE_ANSWER_YES;
}

VfxAppCloseAnswerEnum VfxApp::onProcessClose(VfxAppCloseOption options, VfxAppCloseReason reason)
{
    VFX_UNUSED(reason);
    
    return onProcessClose(options);
}

VfxBool VfxApp::onScrBack(VfxAppScr *scr)
{
    VFX_UNUSED(scr);
    
    return VFX_TRUE;
}

void VfxApp::onScrEmpty(void)
{
}

void VfxApp::continueClose(VfxAppCloseAnswerEnum answer /* = VFX_APP_CLOSE_ANSWER_YES*/)
{
    VFX_LOG(VFX_INFO, VFX_APP_CONTINUE_CLOSE, m_groupId, m_closeState, answer);
    
    if(m_closeState == VFX_APP_CLOSE_STATE_NONE)
        return;

    VfxU32 closeState = m_closeState;
    m_closeState = 0;

    if(closeState & VFX_APP_CLOSE_OPTION_LATER_FLAG)
    {
        mmi_frm_suspend_handle_key_process(MMI_FALSE);
        mmi_frm_enable_anti_blink(MMI_TRUE);
    }

    switch(VFX_APP_CLOSE_STATE_REASON(closeState))
    {
    case VFX_APP_CLOSE_STATE_ENDKEY:
        {
            mmi_id groupId;
            
            if (getParentGroupId() == GRP_ID_ROOT) /* App */
            { 
                if (answer == VFX_APP_CLOSE_ANSWER_BG)
                {
                    /* We have to close previous groups first to avoid temp enter/exit scenario */
                    groupId = vfx_get_prev_app_group_id(m_groupId);
                    
    				if (groupId != GRP_ID_INVALID)
    				{
    				    mmi_frm_close_to_idle_group_with_start_id(groupId);
    				}

                    setHidden(VFX_TRUE);
                }
                else
                {
                    /* Close to idle (start from current app) */
					setSkipDeleteCheck();
			        mmi_frm_close_to_idle_group_with_start_id(m_groupId);
                }
            }
            else /* CUI */
            {
                /* Close to idle (start from top parent app) */
                groupId = mmi_frm_group_get_top_parent_group_id(m_groupId);
                
				setSkipDeleteCheck();
			    mmi_frm_close_to_idle_group_with_start_id(groupId);
            }
        }
        break;

    case VFX_APP_CLOSE_STATE_OOM:
        vfx_app_post_evt_struct postFreeEvt;
        MMI_FRM_INIT_EVENT(&postFreeEvt, 0);
        postFreeEvt.groupId = getGroupId();
        MMI_FRM_POST_EVENT(&postFreeEvt, VfxApp::static_postFreeASM, NULL);

        exit();
        break;

    case VFX_APP_CLOSE_STATE_PLUTO:
        exit();
        break;

    default:
        VFX_ASSERT(0);
    }
}

void VfxApp::postInvoke(mmi_proc_func func, void *user_data)
{
    if (func)
    {
        mmi_event_struct evt;
        MMI_FRM_INIT_EVENT(&evt, 0);
        MMI_FRM_POST_EVENT(&evt, func, user_data);  
    }
}


void VfxApp::postInvoke(mmi_post_invoke_func_type func, void *arg1, void *arg2, void *arg3)
{
    if (func)
    {
        vfx_app_post_invoke_evt_struct evt;
        MMI_FRM_INIT_EVENT(&evt, 0);
        evt.arg1 = arg1;
        evt.arg2 = arg2;
        evt.arg3 = arg3;
        MMI_FRM_POST_EVENT(&evt, postInvokeHelper, (void *)func);
    }
}

void VfxApp::postInvokeHelper(vfx_app_post_invoke_evt_struct *evt)
{
    mmi_post_invoke_func_type func = (mmi_post_invoke_func_type)evt->user_data;
    func(evt->arg1, evt->arg2, evt->arg3);
}

mmi_ret VfxApp::static_proc(mmi_event_struct *evt)
{
    if (evt->user_data == NULL)
        return MMI_RET_OK;

    VfxApp* app = (VfxApp*) evt->user_data;
    VFX_OBJ_ASSERT_VALID(app);
    VFX_LOG(VFX_INFO2, VFX_APP_NON_HANDLED_EVT, app->m_groupId, evt->evt_id);
    return app->onProc(evt);
}

mmi_ret VfxApp::static_group_proc(mmi_event_struct *evt)
{
    VfxApp* app = (VfxApp*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
    if(!app)
        return MMI_RET_OK;
    VFX_ASSERT(app->isKindOf(VFX_OBJ_CLASS_INFO(VfxApp)));
    return app->processGroupProc(evt);
}

mmi_ret VfxApp::static_serialize_proc(mmi_event_struct *evt)
{
    mmi_ret ret = MMI_RET_OK;
    mmi_id groupId;
    AppHistoryNode* node = (AppHistoryNode*) evt->user_data;
    VFX_DEV_ASSERT(node);

    // setup serialize event
    vfx_app_serialize_evt_struct serialize_evt;
    
    MMI_FRM_INIT_EVENT(&serialize_evt, evt->evt_id);
    serialize_evt.serializeData = node->serializeData;
    serialize_evt.serializeDataSize = node->serializeDataSize;

    // notify clients with group events
    if (node->proxy_proc)
    {
        ret = node->proxy_proc((mmi_event_struct*)&serialize_evt);
    }

    if (ret != MMI_RET_OK)
    {
        // allow client to discard the event
        return ret;
    }
    
    switch (evt->evt_id)
    {
    case EVT_ID_GROUP_FOCUSED:
        static_restore(node);
        break;

    case EVT_ID_ASM_FORCE_FREE:
        groupId = node->groupId;

        mmi_frm_group_close(groupId);
        
        vfx_app_post_evt_struct postFreeEvt;
        MMI_FRM_INIT_EVENT(&postFreeEvt, 0);
        postFreeEvt.groupId = groupId;
        MMI_FRM_POST_EVENT(&postFreeEvt, VfxApp::static_postFreeASM, NULL);

        ret = MMI_FRM_ASM_WAITING_TO_FREE;
        break;
        
    case EVT_ID_GROUP_DEINIT:
        // free group ID
        VfxAppLauncher::static_freeId(node->groupId);

        // check if free all ASM
        mmi_group_node_struct info;
        if (mmi_frm_group_get_info(node->groupId, &info) == MMI_RET_OK)
        {
            if (info.parent == GRP_ID_ROOT)
            {
                // Assertion here means there is memory leak of your application.
                VFX_ASSERT(applib_mem_ap_get_single_usage(node->groupId) == 0);
            }
        }

        // Free history node
        VFX_SYS_DELETE(node);
        break;
        
    default:
        break;
    }

    return ret;
}

mmi_ret VfxApp::processGroupProc(mmi_event_struct *evt)
{
    mmi_ret ret = MMI_RET_OK;
    VfxAppCloseAnswerEnum ans;

    switch (evt->evt_id)
    {
    case EVT_ID_DELETE_DANGLE_GROUP_REQ:
        /* keep dangle group */
        return MMI_RET_ERR;
    
    case EVT_ID_NO_CHILD_NOTIFY:
        {
            // Notify application the screen count is 0. The VfxApp will be closed afterward.
            onScrEmpty();
            
            mmi_event_struct evt;
            MMI_FRM_INIT_EVENT(&evt, m_groupId);
            mmi_frm_post_event(&evt, vfx_app_check_group_empty, NULL);
        }
        break;
        
    case EVT_ID_GROUP_ACTIVE:
        VFX_LOG(VFX_INFO2, VFX_APP_GROUP_ACTIVE, ((mmi_scenario_evt_struct *)evt)->targ_group);
        onGroupActive();
        break;

    case EVT_ID_GROUP_INACTIVE:
        VFX_LOG(VFX_INFO2, VFX_APP_GROUP_INACTIVE, ((mmi_scenario_evt_struct *)evt)->targ_group);

        // commit sse while app (top level group) inactive     
        if(getParentGroupId() == GRP_ID_ROOT)
            vfx_adp_sse_commit();
        
        processGroupInactive();
        break;

    case EVT_ID_GROUP_REDRAW_START:
        onGroupSnapshotActive();
        break;

    case EVT_ID_GROUP_REDRAW_DONE:
        onGroupSnapshotInactive();
        break;

    case EVT_ID_GROUP_FOCUSED:
        onGroupTopActive();
        break;

    case EVT_ID_GROUP_DEFOCUSED:
        onGroupTopInactive();
        break;

    case EVT_ID_GROUP_HIDE:
        if(getParentGroupId() == GRP_ID_ROOT)
        {
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_APP, VFX_FALSE, VFX_SCR_TRANSIT_PRIORITY_APP);
            vfx_adp_sse_commit();
        }

        onGroupHidden();
		
    #if defined(__MMI_USE_MMV2__)
        if ( m_DynHeapSetting & VFX_APP_DYN_HEAP_IN_HIDDEN_SWITCH )
        {
            VfxContext *context = getContext();
            vfx_mmi_check_update(); /* complete the post free memory event if it exists*/
            context->shrinkHeapSize(m_groupId);
        }
    #endif
        break;

    case EVT_ID_GROUP_UNHIDE:
        onGroupUnhidden();
        break;
        
    case EVT_ID_GROUP_DELETE_REQ:
    case EVT_ID_GROUP_GOBACK:
        VFX_LOG(VFX_INFO2, VFX_APP_GROUP_DELETE_REQ, ((mmi_scenario_evt_struct *)evt)->targ_group);

        if(m_skipDeleteCheck)
            ret = MMI_RET_OK;
        else if(VFX_APP_CLOSE_ANSWER_YES != processClose(VFX_APP_CLOSE_OPTION_PLUTO, VFX_APP_CLOSE_STATE_PLUTO))
            ret = MMI_RET_ERR;

        if(ret == MMI_RET_OK && isActive())
        {
            // Setup SSE for closing app
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_APP, VFX_FALSE, VFX_SCR_TRANSIT_PRIORITY_APP);
        }
        break;

    case EVT_ID_GROUP_GOBACK_IN_END_KEY:        
    case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
        VFX_LOG(VFX_INFO2, VFX_APP_GROUP_DELETE_REQ, ((mmi_scenario_evt_struct *)evt)->targ_group);

        if(m_skipDeleteCheck)
        {
            ret = MMI_RET_OK;
        }
        else
        {
            ans = processClose(VFX_APP_CLOSE_OPTION_ENDKEY, VFX_APP_CLOSE_STATE_ENDKEY);
            if(VFX_APP_CLOSE_ANSWER_YES != ans)
            {
                ret = MMI_RET_STOP_END_KEY_FLOW;
                if(ans == VFX_APP_CLOSE_ANSWER_BG)
                {
                    /* The hidden request will be handled in post event while in end key process */
                    setHidden(VFX_TRUE);

                    /* Return MMI_RET_ERR to keep current group but continue deleting other groups */
    				ret = MMI_RET_ERR;
                }
            }
        }

        if(ret == MMI_RET_OK && isActive())
        {
            // Setup SSE for closing app           
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_APP, VFX_FALSE, VFX_SCR_TRANSIT_PRIORITY_HOME);
        }
        break;
        
    case EVT_ID_GROUP_DEINIT:
        {
            VFX_LOG(VFX_INFO, VFX_APP_GROUP_DEINIT, ((mmi_scenario_evt_struct *)evt)->targ_group, m_groupId == GRP_ID_INVALID);

            /* may come from obj close() */
            if (m_groupId != GRP_ID_INVALID)
            {
                VfxContext *context = getContext();
                mmi_id groupId = m_groupId;
                VfxBool needToFreeCtx = m_needToFreeCtx;

                // free launcher if exists
                if (m_launcher)
                    VFX_OBJ_CLOSE(m_launcher);

                m_appState = APP_STATE_DEINITING;

                VfxApp *app = this;
                VFX_OBJ_CLOSE(app);

                // free context    
                if (needToFreeCtx)
                    VFX_OBJ_CLOSE(context);            
                
                // free group ID
                VfxAppLauncher::static_freeId(groupId);

                // check if free all ASM
                mmi_group_node_struct info;
                if(mmi_frm_group_get_info(groupId, &info) == MMI_RET_OK)
                {
                    if(info.parent == GRP_ID_ROOT)
                    {
                        // Assertion here means there is memory leak of your application.
                        VFX_ASSERT(applib_mem_ap_get_single_usage(groupId) == 0);
                    }
                }
                
            }
        }
        break;

    case EVT_ID_ASM_FORCE_FREE:
        {
            mmi_id groupId = m_groupId;
            VFX_LOG(VFX_INFO, VFX_APP_ASM_FORCE_FREE, groupId);

            VfxAppCloseAnswerEnum ans = processClose(VFX_APP_CLOSE_OPTION_OOM, VFX_APP_CLOSE_STATE_OOM);

            switch(ans)
            {
            case VFX_APP_CLOSE_ANSWER_YES:
                exit();
                
                vfx_app_post_evt_struct postFreeEvt;
                MMI_FRM_INIT_EVENT(&postFreeEvt, 0);
                postFreeEvt.groupId = groupId;
                MMI_FRM_POST_EVENT(&postFreeEvt, VfxApp::static_postFreeASM, NULL);
                break;

            case VFX_APP_CLOSE_ANSWER_LATER:
                break;

            default:
                VFX_ASSERT(0);  // only accept above answer.
                break;
            }
           
            ret = MMI_FRM_ASM_WAITING_TO_FREE;
        }
        break;
#if defined(__MMI_USE_MMV2__)
    case EVT_ID_ASM_BACKWARD_ENLARGE_HEAP:
        {
            if (m_DynHeapSetting & VFX_APP_DYN_HEAP_IN_ACTIVE_SWITCH)
            {
                VfxContext *context = getContext();
                //VFX_LOG(VFX_INFO, VFX_APP_ASM_FORCE_FREE, m_groupId);
                if (context->backwardEnlargeHeapSize(m_groupId) == 0 )
                    ret = MMI_FRM_ASM_WAITING_TO_FREE;
                else
                    ret = MMI_FRM_ASM_FREED;
            }
        }
        break;
    case EVT_ID_ASM_INACTIVE_SHRINK_HEAP:
        {
            if (m_DynHeapSetting & VFX_APP_DYN_HEAP_IN_ACTIVE_SWITCH)
            {
                VfxContext *context = getContext();
                //VFX_LOG(VFX_INFO, EVT_ID_ASM_INACTIVE_SHRINK_HEAP, m_groupId);
                context->shrinkHeapSize(m_groupId);
            }
        }
        break;
#endif //__MMI_USE_MMV2__
       
    default:
        VFX_LOG(VFX_INFO2, VFX_APP_NON_HANDLED_EVT, m_groupId, evt->evt_id);
        ret = onProc(evt);
        break;
    }
    return ret;
}


mmi_ret VfxApp::static_postDeinit(vfx_app_post_evt_struct *evt)
{
    VfxContext *context = (VfxContext *)evt->user_data;

    
    VFX_LOG(VFX_INFO, VFX_APP_POST_DEINIT, evt->groupId, context, context!=NULL);
    
    // free context    
    if (context)
    {
        VFX_OBJ_CLOSE(context);            
    }

    // free group ID
    VfxAppLauncher::static_freeId(evt->groupId);

    return MMI_RET_OK;
}

mmi_ret VfxApp::static_postFreeASM(vfx_app_post_evt_struct *evt)
{
    mmi_id appId = (mmi_id)evt->groupId;

    VFX_LOG(VFX_INFO, VFX_APP_POST_FREE_ASM, appId);
    applib_mem_ap_notify_stop_finished(appId, KAL_TRUE);
    
    return MMI_RET_OK;
}

void VfxApp::static_postToCallerResultCb(mmi_post_result_event_struct *evt)
{
    VfxAppPostToCallerCb *cbPtr = (VfxAppPostToCallerCb *)evt->user_data;
    if (cbPtr)
    {
        cbPtr->invoke((mmi_group_event_struct *)evt->evt_p, evt->result);
        VFX_DELETE(cbPtr);
    }
}

mmi_ret VfxApp::static_changeHeapInUnhiddenProc(mmi_event_struct *evt)
{
#if defined(__MMI_USE_MMV2__)
    switch(evt->evt_id)
    {
    case EVT_ID_MEM_IS_ENOUGH:
        {
            vfx_app_enlarge_heap_data_struct my_data;
            VfxApp *app;
            VfxAppHeapCallback* cbPtr;
            mmi_event_struct evt2;
            memcpy(&my_data, evt->user_data, sizeof(my_data));
            mmi_frm_free(evt->user_data);
            app = (VfxApp *)VfxObject::handleToObject((VfxObjHandle)my_data.handle);
            cbPtr = (VfxAppHeapCallback*)my_data.user_cb; 
            if (cbPtr != NULL)
                cbPtr->invoke(VFX_TRUE);
            VFX_DELETE(cbPtr);
            /*request mmi_frm_asm_app_unhide to prepare asm in unhidden process*/
            MMI_FRM_INIT_EVENT(&evt2, EVT_ID_MEM_FREE_ASM);
            mmi_frm_post_event(&evt2, static_changeHeapInUnhiddenProc, (void *)app->getGroupId());
        }
        break;
        
    case EVT_ID_MEM_CANCELED:
        {
            vfx_app_enlarge_heap_data_struct my_data;
            VfxAppHeapCallback* cbPtr;
            memcpy(&my_data, evt->user_data, sizeof(my_data));
            mmi_frm_free(evt->user_data);
            cbPtr = (VfxAppHeapCallback*)my_data.user_cb; 

            if (cbPtr != NULL)
                cbPtr->invoke(VFX_FALSE);
            VFX_DELETE(cbPtr);
        }
        break;
    case EVT_ID_MEM_FREE_ASM:
        mmi_frm_asm_app_unhide((MMI_ID)((VfxU32)evt->user_data));
        break;
    default :  
        VFX_ASSERT(0);
    }
    return MMI_RET_OK;
#else
    VFX_ASSERT(0);
    return MMI_RET_OK;
#endif
}

void VfxApp::onInit()
{
    VfxObject::onInit();
}


void VfxApp::exit()
{
    VFX_LOG_FUNC;
    VFX_TRACE(("===> [VfxApp] (%d, 0x%x) exit\n", m_groupId, this));

    m_appState = APP_STATE_DEINITING;
    setSkipDeleteCheck();
    mmi_frm_group_close(m_groupId);
}

void VfxApp::onDeinit()
{
    VFX_LOG(VFX_INFO, VFX_APP_ON_DEINIT, m_groupId, this);

    // only can goes here through exit().
    // please call exit() to stop App instead of using VFX_OBJ_CLOSE() directly
    VFX_ASSERT(m_appState == APP_STATE_DEINITING);

    VfxObject::onDeinit();    
}


VfxU32 VfxApp::_getId() const
{
    return m_groupId;
}


mmi_ret VfxApp::onGroupDeleteReq(DelReason reason)
{
    return MMI_RET_OK;
}


void VfxApp::onGroupActive()
{
}

void VfxApp::onGroupInactive()
{
}

void VfxApp::onGroupTopActive()
{
}

void VfxApp::onGroupTopInactive()
{
}

void VfxApp::onGroupSnapshotActive()
{
}

void VfxApp::onGroupSnapshotInactive()
{
}

void VfxApp::onGroupHidden()
{
}

void VfxApp::onGroupUnhidden()
{
}

void VfxApp::processGroupInactive()
{
    onGroupInactive();
}

VfxBool VfxApp::isRunning() const
{
    return m_appState == APP_STATE_INIT ? VFX_FALSE : VFX_TRUE;
}

VfxBool VfxApp::isActive() const
{
    return m_groupId == mmi_frm_group_get_active_id();
}


VfxBool VfxApp::isActiveSerial() const
{
    return mmi_frm_group_get_top_parent_group_id(m_groupId) == 
        mmi_frm_group_get_top_parent_group_id(mmi_frm_group_get_active_id());
}

VfxBool VfxApp::isGroupActive() const
{
    return isActiveSerial();
}

VfxBool VfxApp::isGroupTopActive() const
{
    return isActive();
}

mmi_id VfxApp::insertScreen(VfxClassInfo *screenClassInfo, mmi_id inserted_sid)
{
    VFX_ASSERT(inserted_sid != SCR_ID_INVALID);

    VfxAppScr::HistoryNode* node = VfxAppScr::createHistoryNode(this, screenClassInfo);
    
    node->screen = (VfxAppScr*)node->classInfo->createObject(this);
    VFX_ASSERT(node->screen->isKindOf(VFX_OBJ_CLASS_INFO(VfxAppScr)));

    node->screenId = VfxAppScr::getUnusedScreenId(this);
    node->screen->m_screenId = node->screenId;
    node->screen->m_pHistoryNode = node;

    mmi_frm_node_struct new_node = {0};
    new_node.id = node->screenId;
    new_node.entry_proc = (mmi_proc_func)&VfxAppScr::static_entry;
    new_node.user_data = node;

    mmi_frm_scrn_insert(m_groupId, inserted_sid, &new_node, MMI_FRM_NODE_BEFORE_FLAG);

    return node->screenId;
}


VfxU32 VfxApp::getScreenCount() const
{
    return mmi_frm_scrn_get_count(m_groupId);
}

mmi_id VfxApp::getNextScreenId(mmi_id baseScreenId) const
{
    return mmi_frm_scrn_get_neighbor_id(
            m_groupId, 
            baseScreenId, 
            MMI_FRM_NODE_AFTER_FLAG
    );
}

mmi_id VfxApp::getPrevScreenId(mmi_id baseScreenId) const
{
    return mmi_frm_scrn_get_neighbor_id(
            m_groupId, 
            baseScreenId, 
            MMI_FRM_NODE_BEFORE_FLAG
    );
}


mmi_id VfxApp::getTopScreenId() const
{
    return mmi_frm_scrn_get_neighbor_id(
            m_groupId, 
            GRP_ID_INVALID, 
            MMI_FRM_NODE_AT_LATEST_FLAG
    );
}


mmi_id VfxApp::getBottomScreenId() const
{
    return mmi_frm_scrn_get_neighbor_id(
            m_groupId, 
            GRP_ID_INVALID, 
            MMI_FRM_NODE_AT_BEGINNING_FLAG
    );
}


VfxAppScr* VfxApp::getTopScreen() const
{
    return getScreen(getTopScreenId());
}

void VfxApp::setHidden(VfxBool value)
{
    VFX_LOG_FUNC1("%d", value);
    if(value != getHidden())
    {
        if(value)
            mmi_frm_asm_app_hide(m_groupId);

        else
        {
        #if defined(__MMI_USE_MMV2__)
            if ( m_DynHeapSetting & VFX_APP_DYN_HEAP_IN_HIDDEN_SWITCH )
            {
                vfx_app_enlarge_heap_data_struct* my_data;
                VfxContext *context = getContext();
                //VfxAppHeapCallback* cbPtr;
                my_data = (vfx_app_enlarge_heap_data_struct*) mmi_frm_malloc(sizeof(*my_data));
                //VFX_SYS_NEW_EX(cbPtr, VfxAppHeapCallback, (user_cb));
                my_data->user_cb = (void*)NULL;
                my_data->user_data = NULL ;
                my_data->handle = getObjHandle();
                // enter a dummy screen to force FG release.
                vfx_app_entry_dummy_screen();
                if (0 == context->enlargeHeapSize(m_groupId, static_changeHeapInUnhiddenProc, (void*)my_data,
                                         VFX_SYS_MEM_POOL_SLMM_ENLARGE_FLAG_UNHIDDEN ))
                {
                    return ;/*async enlarge heap case*/
                }
            }
        #endif
            mmi_frm_asm_app_unhide(m_groupId);
        }
    }
}

VfxBool VfxApp::getHidden() const
{
    VfxU32 state = (VfxU32)mmi_frm_group_get_state(m_groupId);
    if((state & MMI_SCENARIO_STATE_HIDE) ||
        (state & MMI_SCENARIO_STATE_HIDING))
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxBool VfxApp::setActive(void)
{
    // CUI is not allowed to be active
    if (getParentGroupId() == GRP_ID_ROOT)
    {
        return (VfxBool)mmi_frm_set_active_group(m_groupId);
    }

    return VFX_FALSE;
}

void VfxApp::registerCBEvent(mmi_event_id event_id, VfxBool on)
{
    if(on)
    {
        mmi_frm_cb_reg_event(event_id, (mmi_proc_func)&VfxApp::static_group_proc, getObjHandle());
    }
    else
    {
        mmi_frm_cb_dereg_event(event_id, (mmi_proc_func)&VfxApp::static_group_proc, getObjHandle());
    }
}

void VfxApp::setCABCMode(mmi_frm_cabc_mode_enum mode)
{
    if(mode >= MMI_FRM_CABC_MODE_END_OF_ENUM)
        return;
    m_CABCMode = (VfxU8)mode;
    
    if(isActive())
    {
        VfxAppScr *scr = getTopScreen();
        if(scr)
            scr->updateCABCMode();
    }
}

void VfxApp::resetCABCMode()
{
    m_CABCMode = 0xFF;
    if(isActive())
    {
        VfxAppScr *scr = getTopScreen();
        if(scr)
            scr->updateCABCMode();
    }
}

mmi_frm_cabc_mode_enum VfxApp::getCABCMode() const
{
    if(m_CABCMode >= MMI_FRM_CABC_MODE_END_OF_ENUM)
        return MMI_FRM_CABC_MODE_UI;
        
    return (mmi_frm_cabc_mode_enum)m_CABCMode;
}

mmi_id VfxApp::getParentGroupId(void) const
{
    mmi_group_node_struct node;

    if (mmi_frm_group_get_info(m_groupId, &node) != MMI_RET_OK)
        return GRP_ID_INVALID;

    return node.parent;
}

void VfxApp::postCheckEmpty(mmi_id groupId)
{
    VFX_LOG_FUNC;

    VfxApp* app = VfxApp::getObject(groupId);

    if (app && (app->getScreenCount() == 0))
    {
        exit();
    }
}

VfxAppCloseAnswerEnum VfxApp::processClose(VfxAppCloseOption options, VfxU32 reason)
{
    VFX_LOG_FUNC2("<%X>, %d", options, reason);
    // In previous close flow ??
    VFX_DEV_ASSERT(m_closeState == VFX_APP_CLOSE_STATE_NONE);

    VfxAppCloseAnswerEnum ans = onProcessClose(options, VFX_APP_CLOSE_REASON_FLAG(reason));
    
    VFX_LOG(VFX_INFO, VFX_APP_ON_PROCESS_CLOSE, m_groupId, options, VFX_APP_CLOSE_REASON_FLAG(reason), ans);

    switch(ans)
    {
    case VFX_APP_CLOSE_ANSWER_YES:
        VFX_ASSERT(options & VFX_APP_CLOSE_OPTION_YES_FLAG);
        setSkipDeleteCheck();
        break;

    case VFX_APP_CLOSE_ANSWER_NO:
        VFX_ASSERT(options & VFX_APP_CLOSE_OPTION_NO_FLAG);
        break;

    case VFX_APP_CLOSE_ANSWER_BG:
        VFX_ASSERT(options & VFX_APP_CLOSE_OPTION_BG_FLAG);
        break;

    case VFX_APP_CLOSE_ANSWER_LATER:
        VFX_ASSERT(options & VFX_APP_CLOSE_OPTION_LATER_FLAG);
        // Suspend key
        mmi_frm_suspend_handle_key_process(MMI_TRUE);
        mmi_frm_enable_anti_blink(MMI_FALSE);
        m_closeState = (reason | options);
        break;
    }

    return ans;
}

void VfxApp::setSkipDeleteCheck()
{
    // Turn on skip delete check before actually do mmi_frm_group_close()
    m_skipDeleteCheck = VFX_TRUE;

    mmi_id scrn = getTopScreenId();
    while(scrn != SCR_ID_INVALID)
    {
        VfxAppScr::HistoryNode* node = (VfxAppScr::HistoryNode*)mmi_frm_scrn_get_user_data(m_groupId, scrn);
        if(node)
            node->flag |= VFX_SCR_HISTORY_NODE_SKIP_DEL_CHECK_FLAG;

        scrn = getPrevScreenId(scrn);
    }
}

void VfxApp::processScrBack(VfxAppScr *scr)
{
    VFX_LOG_FUNC1("<%X>", scr);
    if(onScrBack(scr))
    {
        scr->exit();
    }
}

void VfxApp::processRun(void* args, VfxU32 argSize)
{
    m_appState = APP_STATE_NORMAL;

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XRN", SA_start);
#endif

    onRun(args, argSize);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XRN", SA_stop);
#endif
}

void VfxApp::onSerialize(void *hint, VfxArchive &ar)
{
    VFX_UNUSED(hint);
    VFX_UNUSED(ar);
}

void VfxApp::onRestore(VfxArchive &ar)
{
    VFX_UNUSED(ar);
}

void VfxApp::processSerialize(void *hint, VfxArchive &ar)
{
    onSerialize(hint, ar);
}

void VfxApp::processRestore(VfxArchive &ar)
{
    onRestore(ar);
}

AppHistoryNode* VfxApp::createAppHistoryNode(void)
{
    AppHistoryNode* node = NULL;

    VFX_SYS_NEW(node, AppHistoryNode);
    node->groupId = m_groupId;
    node->flag = 0;
    node->classInfo = getClassInfo();
    node->serializeData = NULL;
    node->serializeDataSize = 0;
    node->proxy_proc = NULL;

    return node;
}

void VfxApp::serialize(void* serializeHint, VfxBool reserveASM, serializeCbFunc cbFunc,	void* cbArg, VfxU32 cbArgSize, mmi_proc_func proxy_proc)
{
    if (m_appState == APP_STATE_DEINITING)
    {
        // directly return if the app is going to exit
        return;
    }
    
    AppHistoryNode* node = createAppHistoryNode();

    // Serialize app
    VfxArchive* pArchive;
    VFX_OBJ_CREATE(pArchive, VfxArchive, VFX_SYS_GLOBAL_CONTEXT);

    VfxMemArchiveSource* pSource;
    VFX_OBJ_CREATE(pSource, VfxMemArchiveSource, pArchive);
    
    pArchive->setSource(pSource);

    processSerialize(serializeHint, *pArchive);

    node->logContext = m_logContext;
    node->serializeData = NULL;
    node->serializeDataSize = 0;
    node->proxy_proc = proxy_proc;

    VfxU8* pBuffer = NULL;
    VfxU32 bufSize = 0;
    pSource->detachBuffer(&pBuffer, &bufSize);

    if (pBuffer && bufSize != 0)
    {
        VFX_DEV_ASSERT(bufSize <= 2048);
        
        node->serializeData = (void*)pBuffer;
        node->serializeDataSize = bufSize;
    }
    else
    {
        pSource->attachBuffer(pBuffer, bufSize);
    }

    VFX_OBJ_CLOSE(pArchive);

    node->flag |= VFX_APP_HISTORY_NODE_SERIALIZE_FLAG;

    // Update group proc/userdata
    mmi_frm_group_set_proc_data(m_groupId, (mmi_proc_func)VfxApp::static_serialize_proc, (void*)node);

    // Close screen/app/context
    VfxContext *context = getContext();

    mmi_id screenId = getTopScreenId();

    while (screenId != SCR_ID_INVALID)
    {
        closeScreen(screenId);

        screenId = getNextScreenId(screenId);
    }

    m_appState = APP_STATE_DEINITING;
    setSkipDeleteCheck();
    
    VfxApp* app = this;
    VFX_OBJ_CLOSE(app);

    if (context->isKindOf(VFX_OBJ_CLASS_INFO(VappPlatformContext)))
    {
        node->flag |= VFX_APP_HISTORY_NODE_PLATFORM_CTX_FLAG;
    }
    else
    {
        VFX_OBJ_CLOSE(context);
    }

    // Shrink base size
    if (! reserveASM)
    {
        mmi_frm_asm_base_shrink_size(node->groupId, 0);
    }
    
    // Callback to caller
    if (cbFunc)
    {
        cbFunc(cbArg, cbArgSize);
    }
    
}

void VfxApp::static_restore(AppHistoryNode* node)
{
    if (node->flag & VFX_APP_HISTORY_NODE_SERIALIZE_FLAG)
    {
        // Create context
        VfxContext *context = NULL;
        
        if (node->flag & VFX_APP_HISTORY_NODE_PLATFORM_CTX_FLAG)
        {
            context = VFX_OBJ_GET_INSTANCE(VappPlatformContext);
        }
        else
        {
            VfxAppContext *AppContext;
            VfxU32 heapSize = VfxAppLauncher::getHeapSize(node->groupId);
            void* heap = mmi_frm_asm_alloc_r(node->groupId, heapSize);
            VFX_DEV_ASSERT(heap);
            
            VFX_OBJ_CREATE(AppContext, VfxAppContext, VFX_SYS_GLOBAL_CONTEXT);

            AppContext->setFreeContextMemCallback(VfxAppLauncher::static_freeContextMemCb, (void*)node->groupId);
            AppContext->assignPool((VfxU8 *)heap, heapSize, node->logContext);

            context = (VfxContext*)AppContext;
        }
    
        // Create app
        VfxApp *app = (VfxApp *)node->classInfo->createObject(context);
        VFX_DEV_ASSERT(app->isKindOf(VFX_OBJ_CLASS_INFO(VfxApp)));

        app->m_groupId = node->groupId;

        if (node->flag & VFX_APP_HISTORY_NODE_PLATFORM_CTX_FLAG)
        {
            app->m_needToFreeCtx = VFX_FALSE;
        }

        mmi_frm_group_set_proc_data(app->m_groupId, (mmi_proc_func)VfxApp::static_group_proc, app->getObjHandle());

        // Restore
        node->flag &= ~VFX_APP_HISTORY_NODE_SERIALIZE_FLAG;

        VfxArchive* pArchive = NULL;
        
        if (node->serializeData != NULL && node->serializeDataSize != 0)
        {
            VFX_OBJ_CREATE(pArchive, VfxArchive, VFX_SYS_GLOBAL_CONTEXT);

            VfxMemArchiveSource* pSource;
            VFX_OBJ_CREATE(pSource, VfxMemArchiveSource, pArchive);

            pSource->attachBuffer(
                (VfxU8*)node->serializeData,
                node->serializeDataSize
            );

            node->serializeData = NULL;
            node->serializeDataSize = 0;
            
            pArchive->setSource(pSource);

        }
        
        app->processRestore(*pArchive);

        VFX_OBJ_CLOSE(pArchive);

        // Free history node
        VFX_SYS_DELETE(node);

    }
}

