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
 *  vfx_app_scr.cpp
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
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
#include "vfx_app.h"
#include "vfx_app_scr.h"
#include "trc\vadp_sys_trc.h"
#include "vfx_sys_config.h"

extern "C"
{
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
    
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_res_range_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "CustDataRes.h"
#include "gui_typedef.h"
}

#include "vrt_datatype.h"
#include "vrt_canvas.h"

#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_input_event.h"
#include "vfx_system.h"
#include "vfx_signal.h"
#include "vfx_archive.h"
#include "vfx_top_level.h"
#include "vfx_logger.h"

extern mmi_id vfx_get_prev_app_group_id(mmi_id group_id);
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

#ifdef __COSMOS_MMI__
#define VFX_APPSCR_KEY_BACK VFX_KEY_CODE_BACK
#else
#define VFX_APPSCR_KEY_BACK VFX_KEY_CODE_RSK
#endif

static mmi_ret vfx_app_scr_exit_func(mmi_event_struct *param)
{
    VfxApp *app = VfxApp::getObject(param->evt_id);
    if(app)
    {
        app->closeScreen((mmi_id)(U32)param->user_data);
    }
    return MMI_RET_OK;
}

/***************************************************************************** 
 * Class VfxAppScr
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("AppScr", VfxAppScr, VfxScreen);

VfxU16 VfxAppScr::m_nextScrIdToCheck = VENUS_FW_BASE;


VfxAppScr::HistoryNode::HistoryNode() :
    screenId(SCR_ID_INVALID), 
    flag(0), 
    app(NULL),
    classInfo(NULL),
    serializeData(NULL),
    serializeDataSize(0)
{
}


VfxAppScr::HistoryNode::~HistoryNode()
{
    if (serializeData)
    {
        VFX_DEV_ASSERT(app);
        VFX_FREE_MEM(serializeData);
    }
}

// Save data before show() (historyNode is created)
class VfxAppScrInitData : public VfxBase
{
public:
    VfxAppScrInitData() :
        flag(0)
    {}
    virtual ~VfxAppScrInitData() {}

public:    
    VfxU16          flag;
};


VfxAppScr::VfxAppScr() : 
    m_screenId(SCR_ID_INVALID), 
    m_CABCMode(0xFF),
    m_pHistoryNode(NULL),
    m_pInitData(NULL)
{
}

void VfxAppScr::onInit()
{
    VFX_LOG_FUNC;
    VfxScreen::onInit();

    VFX_ALLOC_NEW(m_pInitData, VfxAppScrInitData, this);
}

void VfxAppScr::onDeinit()
{
    VFX_LOG_FUNC;
    VFX_DELETE(m_pInitData);

    VfxScreen::onDeinit();
}

void VfxAppScr::onBeforeDeinit()
{
    VFX_LOG_FUNC;

    if (getApp()->m_pTopScreen.get() == this)
    {
        getApp()->m_pTopScreen = NULL;
    }

    if (m_pHistoryNode && !(m_pHistoryNode->flag & VFX_SCR_HISTORY_NODE_SERIALIZE_FLAG))
    {
        m_pHistoryNode->screen = NULL;
        m_pHistoryNode->flag |= VFX_SCR_HISTORY_NODE_CLOSING_FLAG;
        exit();
    }

    VfxScreen::onBeforeDeinit();
}

void VfxAppScr::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_OBJECT_NOTIFY_ID_BEFORE_DEINIT:
        {
            onBeforeDeinit();
            return;
        }
        default:
        {
            VfxScreen::onObjectNotify(id, userData);
            return;
        }
    }
}

VfxBool VfxAppScr::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_APPSCR_KEY_BACK &&
        event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        back();
        return VFX_TRUE;
    }
    
    return VfxScreen::onKeyInput(event);
}

VfxApp* VfxAppScr::getApp() const
{
    VfxObject *parent = getParent();
    VFX_DEV_ASSERT(parent != NULL && parent->isKindOf(VFX_OBJ_CLASS_INFO(VfxApp)));
    return (VfxApp *)parent;
}


VfxBool VfxAppScr::isShown()
{
    if (m_screenId == SCR_ID_INVALID)
    {
        return VFX_FALSE;
    }

    if (MMI_TRUE == mmi_frm_scrn_is_present(getApp()->getGroupId(), m_screenId, MMI_FRM_NODE_ALL_FLAG))
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}


mmi_id VfxAppScr::getGroupId() const
{
    return getApp()->getGroupId();
}


mmi_id VfxAppScr::getUnusedScreenId(VfxApp *app)
{
    mmi_id screenId = SCR_ID_INVALID;
    
    // find out a unused screen ID
    for (mmi_id i = m_nextScrIdToCheck; i < VENUS_FW_BASE_MAX; i++)
    {
        if (MMI_FALSE == mmi_frm_scrn_is_present(app->getGroupId(), i, MMI_FRM_NODE_ALL_FLAG))
        {
            screenId = i;
            m_nextScrIdToCheck = (i+1) < VENUS_FW_BASE_MAX ? (i+1) : VENUS_FW_BASE;
            break;
        }
    }
    VFX_ASSERT(screenId != SCR_ID_INVALID);

    return screenId;
}


VfxAppScr::HistoryNode *VfxAppScr::createHistoryNode(VfxApp *app, VfxClassInfo *classInfo)
{
    HistoryNode* node = NULL;

    VFX_SYS_NEW(node, HistoryNode);
    node->app = app;
    node->classInfo = classInfo;
    node->serializeData = NULL;
    node->serializeDataSize = 0;
    node->screenId = SCR_ID_INVALID;
    node->flag = 0;

    return node;
}


VfxBool VfxAppScr::getAllowDelete() const
{
    VfxU32 flag = m_pHistoryNode ? m_pHistoryNode->flag : m_pInitData->flag;

    return (flag & VFX_SCR_HISTORY_NODE_DELETE_FORBIDDEN_FLAG) ? VFX_FALSE : VFX_TRUE;
}


void VfxAppScr::setAllowDelete(VfxBool allowDelete)
{
    if(!m_pHistoryNode)
    {
        if (!allowDelete)
        {
            m_pInitData->flag |= VFX_SCR_HISTORY_NODE_DELETE_FORBIDDEN_FLAG;
        }
        else
        {
            m_pInitData->flag &= ~VFX_SCR_HISTORY_NODE_DELETE_FORBIDDEN_FLAG;
        }
    }
    else
    {
        if (!allowDelete)
        {
            m_pHistoryNode->flag |= VFX_SCR_HISTORY_NODE_DELETE_FORBIDDEN_FLAG;
        }
        else
        {
            m_pHistoryNode->flag &= ~VFX_SCR_HISTORY_NODE_DELETE_FORBIDDEN_FLAG;
        }
    }
}


void VfxAppScr::setCABCMode(mmi_frm_cabc_mode_enum mode)
{
    if(mode >= MMI_FRM_CABC_MODE_END_OF_ENUM)
        return;

    m_CABCMode = (VfxU8)mode;
    if(isActive())
        updateCABCMode();
}

void VfxAppScr::resetCABCMode()
{
    m_CABCMode = 0xFF;
    if(isActive())
        updateCABCMode();
}

mmi_frm_cabc_mode_enum VfxAppScr::getCABCMode() const
{
    if(m_CABCMode >= MMI_FRM_CABC_MODE_END_OF_ENUM)
        return MMI_FRM_CABC_MODE_UI;
        
    return (mmi_frm_cabc_mode_enum)m_CABCMode;
}

void VfxAppScr::updateCABCMode()
{
    mmi_frm_cabc_mode_enum cabcValue;
    cabcValue = (m_CABCMode >= MMI_FRM_CABC_MODE_END_OF_ENUM) ? getApp()->getCABCMode() : (mmi_frm_cabc_mode_enum)m_CABCMode;

    mmi_frm_set_cabc_mode(cabcValue);
}

mmi_id VfxAppScr::show()
{
    VFX_LOG_FUNC;
    if (isShown())
    {
        // The screen is in visible state
        if (isActive())
        {
            return m_screenId;
        }
        
        VFX_DEV_ASSERT(MMI_TRUE == mmi_frm_scrn_is_present(getApp()->getGroupId(), m_screenId, MMI_FRM_NODE_ALL_FLAG));
        
        // TODO: should support this
        VFX_ASSERT(0); // Current, we are now allow show a sreen in history
        
        return m_screenId;
    }
    else
    {
        VFX_DEV_ASSERT(m_pHistoryNode == NULL);

        mmi_id groupId = getGroupId();
        m_screenId = getUnusedScreenId(getApp());
        VfxBool isSmall = getIsSmallScreen();
        
        if (m_pHistoryNode == NULL)
        {
            m_pHistoryNode = createHistoryNode(getApp(), getClassInfo());
            m_pHistoryNode->screen = this;
            m_pHistoryNode->flag = m_pInitData->flag;
            VFX_DELETE(m_pInitData);
            
            VFX_LOG(VFX_INFO, VFX_APPSCR_NEW_HNODE, int(m_screenId), m_pHistoryNode);
        }
        m_pHistoryNode->screenId = m_screenId;
        
        //mmi_frm_create_new_screen((entry_func_ptr)VfxAppScr::entry, (void*)m_pHistoryNode);
        mmi_frm_scrn_first_enter(
            groupId, 
            m_screenId,
            (FuncPtr)VfxAppScr::static_entry,
            (void*)m_pHistoryNode
            );

        mmi_frm_scrn_set_leave_proc(
            groupId, 
            m_screenId,
            &VfxAppScr::static_proc);

        if (isSmall)
        {
            mmi_frm_scrn_set_attribute(
                groupId, 
                m_screenId, 
                MMI_SCRN_ATTRIB_SMALL_SCRN);
        }
        
        return m_screenId;
    }
}


void VfxAppScr::exit()
{
    VFX_LOG_FUNC;

	// post the close
	if(m_pHistoryNode)
	{
	    // vfxPostInvoke1(getApp(), &VfxApp::closeScreen, getScreenId());
	    mmi_event_struct evt;
		MMI_FRM_INIT_EVENT(&evt, getGroupId());
		mmi_frm_post_event(&evt, vfx_app_scr_exit_func, (void*)m_screenId);
    }
}

void VfxAppScr::back()
{
    VFX_LOG_FUNC;
    if(!getAllowDelete())
        return;

    onBack();
}


VfxBool VfxAppScr::isActive()
{
    return (getGroupId() == mmi_frm_group_get_active_id()) 
        && (getScreenId() == mmi_frm_scrn_get_active_id());
}


mmi_id VfxAppScr::getScreenId() const
{
    return m_screenId;
}


void VfxAppScr::onRestore(VfxArchive &ar)
{
    VFX_UNUSED(ar);
}


VfxBool VfxAppScr::onSerialize(VfxArchive &ar)
{
    VFX_UNUSED(ar);
    return VFX_FALSE;
}


void VfxAppScr::onBack()
{
    getApp()->processScrBack(this);
}

mmi_ret VfxAppScr::onProc(mmi_event_struct *evt)
{
    return proc(evt);
}

mmi_ret VfxAppScr::proc(mmi_event_struct *evt)
{
    VFX_UNUSED(evt);
    return MMI_RET_OK;
}


mmi_ret VfxAppScr::static_proc(mmi_event_struct *evt)
{
    VFX_LOG_STATIC_FUNC1("(event=%d)", evt->evt_id);
    HistoryNode* node = (HistoryNode*) evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            VFX_DEV_ASSERT(node);
            
            VfxAppScr *scr = node->screen.get();
            if (scr)
            {
                VFX_DEV_ASSERT(scr->m_pHistoryNode == node);
                scr->m_pHistoryNode = NULL;

                VFX_OBJ_CLOSE(scr);
            }

            VFX_LOG(VFX_INFO, VFX_APPSCR_FREE_HNODE, int(node->screenId), node);
            VFX_SYS_DELETE(node);
            return MMI_RET_OK;
        }
        
        case EVT_ID_SCRN_GOBACK:
        case EVT_ID_SCRN_DELETE_REQ:
            // If already in cleanup process
            if (node->flag & VFX_SCR_HISTORY_NODE_SKIP_DEL_CHECK_FLAG)
                return MMI_RET_OK;

            // If there is screen pointer, ask it. 
            if(node->screen.isValid())
                return node->screen->getAllowDelete() ? MMI_RET_OK : MMI_RET_ERR;

            // If the screen is serialized, check flag
            if (node->flag & VFX_SCR_HISTORY_NODE_DELETE_FORBIDDEN_FLAG)
                return MMI_RET_ERR;
            break;

        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            // end key cannot be stopped
            break;

        default:
            print_event((PU8)"VfxAppScr", evt);

            if (node)
            {
                VFX_LOG(VFX_INFO2, VFX_APPSCR_NON_HANDLED_EVT, node->screenId, evt->evt_id);
                if (node->screen.isValid())
                    return node->screen->processProc(evt);
            }
            break;
    }
    return MMI_RET_OK;
}
    
mmi_ret VfxAppScr::processProc(mmi_event_struct *evt)
{
    return onProc(evt);
}

VfxBool VfxAppScr::processSerialize(VfxArchive &ar)
{
    return onSerialize(ar);
}


void VfxAppScr::processRestore(VfxArchive &ar)
{
    onRestore(ar);
}

void VfxAppScr::processEnter(VfxBool isBackward)
{
    VFX_LOG_FUNC1("%d", isBackward);

    VfxWeakPtr<VfxScreen> self(this);
    VfxScreen::processEnter(isBackward);
    if(!self.isValid())
        return;

    // ScrTransit
    if(!isBackward)
    {
        if(getTransitType() == VFX_SCR_TRANSIT_TYPE_DEFAULT)
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_SCR, VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_SCR);
        else
            vfx_adp_sse_setup_transit(getTransitType(), VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);	
    }
}

void VfxAppScr::processExit(VfxBool isBackward)
{
    VFX_LOG_FUNC1("%d", isBackward);
    VfxWeakPtr<VfxScreen> self(this);
    VfxScreen::processExit(isBackward);
    if(!self.isValid())
        return;

    // ScrTransit
    if(isBackward)
    {
        if(getTransitType() == VFX_SCR_TRANSIT_TYPE_DEFAULT)
            vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_SCR, VFX_FALSE, VFX_SCR_TRANSIT_PRIORITY_SCR);
        else
            vfx_adp_sse_setup_transit(getTransitType(), VFX_FALSE, VFX_SCR_TRANSIT_PRIORITY_USER);		
    }
}

VfxBool VfxAppScr::serialize(VfxBool isAutoClose)
{
    VFX_LOG_FUNC;
    if (m_pHistoryNode->flag & VFX_SCR_HISTORY_NODE_DELETE_FORBIDDEN_FLAG)
    {
        return VFX_FALSE;
    }

    VfxArchive* pArchive;
    VFX_OBJ_CREATE(pArchive, VfxArchive, getApp());

    VfxMemArchiveSource* pSource;
    VFX_OBJ_CREATE(pSource, VfxMemArchiveSource, pArchive);
    
    pArchive->setSource(pSource);
    VfxBool ret = processSerialize(*pArchive);

    if (ret)
    {
        if (m_pHistoryNode->serializeData)
        {
              VFX_FREE_MEM(m_pHistoryNode->serializeData);
        }
        m_pHistoryNode->serializeData = NULL;
        m_pHistoryNode->serializeDataSize = 0;

        VfxU8* pBuffer = NULL;
        VfxU32 bufSize = 0;
        pSource->detachBuffer(&pBuffer, &bufSize);
        
        m_pHistoryNode->serializeData = pBuffer;
        m_pHistoryNode->serializeDataSize = bufSize;
    }
    VFX_OBJ_CLOSE(pArchive);

    if (ret && isAutoClose)
    {
        //m_screenId = 0; // do not close screen
        
        m_pHistoryNode->screen = NULL;  // reset screen pointer
        m_pHistoryNode->flag |= VFX_SCR_HISTORY_NODE_SERIALIZE_FLAG;

        VfxAppScr* _this = this;
        VFX_OBJ_CLOSE(_this);
    }

    return ret;
}


void VfxAppScr::restore()
{
    VFX_LOG_FUNC;

    // remove serialize flag
    m_pHistoryNode->flag &= ~VFX_SCR_HISTORY_NODE_SERIALIZE_FLAG;

    if (m_pHistoryNode->serializeData == NULL || m_pHistoryNode->serializeDataSize == 0)
    {
        return;
    }

    VfxArchive* pArchive;
    VFX_OBJ_CREATE(pArchive, VfxArchive, getApp());

    VfxMemArchiveSource* pSource;
    VFX_OBJ_CREATE(pSource, VfxMemArchiveSource, pArchive);

    pSource->attachBuffer(
        (VfxU8*)m_pHistoryNode->serializeData,
        m_pHistoryNode->serializeDataSize
    );

    m_pHistoryNode->serializeData = NULL;
    m_pHistoryNode->serializeDataSize = 0;
    
    pArchive->setSource(pSource);
    
    processRestore(*pArchive);

    VFX_OBJ_CLOSE(pArchive);

}


void VfxAppScr::static_exit(mmi_scrn_essential_struct* scrn_info)
{
    VFX_LOG_STATIC_FUNC2("(%d,%d)", scrn_info->group_id, scrn_info->scrn_id);
    HistoryNode* node = (HistoryNode*) scrn_info->user_data;

    VFX_ASSERT(node != NULL);
    VFX_ASSERT(node->screen.isValid() || node->flag & VFX_SCR_HISTORY_NODE_CLOSING_FLAG);
    VFX_ASSERT(node->screenId != 0);

    VfxBool isBackward = (mmi_frm_is_in_backward_scenario() != MMI_FALSE);
    VfxBool isSmallScr = node->screen.isValid() ? node->screen->getIsSmallScreen() : VFX_FALSE;
	VfxBool isSmallScrDisbale = node->screen.isValid() ? node->screen->getIsSmallScreenDisable() : VFX_FALSE;
    VfxBool isRedrawing = (mmi_is_redrawing_bk_screens() != MMI_FALSE);

    VFX_LOG(VFX_INFO, VFX_APPSCR_SCR_EXIT, int(node->screenId), isBackward);

    // Inactive the screen
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XSB", SA_start);
#endif
    VfxTopLevel* topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);

    // Set hint if previous screen group is a VfxApp
    if (isBackward)
    {
        MMI_ID prev_group_id = vfx_get_prev_app_group_id(scrn_info->group_id);
        VfxApp* app = VfxApp::getObject(prev_group_id);

        if (app)
        {
            topLevel->setNextScreenIsVenus();
        }
    }

    topLevel->enterToScreen(NULL, isBackward);  
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XSB", SA_stop);
#endif

    // reset small screen if necessary
    if (isSmallScr)
    {
        ExitCategoryFunction = reset_small_screen;
        vfx_adp_sse_setup_transit(VFX_SCR_TRANSIT_TYPE_NONE, VFX_FALSE, VFX_SCR_TRANSIT_PRIORITY_SMALL_SCR);	
    }
    if (isSmallScrDisbale)
    {
        mmi_frm_scrn_clear_attribute(
            scrn_info->group_id, 
            scrn_info->scrn_id, 
            MMI_SCRN_ATTRIB_SMALL_SCRN);
    }
    if (!isRedrawing)
        mmi_frm_reset_cabc_mode();
}


void VfxAppScr::static_entry(mmi_scrn_essential_struct* scrn_info)
{
    VFX_LOG_STATIC_FUNC2("(%d,%d)", scrn_info->group_id, scrn_info->scrn_id);
    HistoryNode* node = (HistoryNode*) scrn_info->user_data;

    VFX_ASSERT(node != NULL);
    VFX_ASSERT(node->screenId != 0);

    VfxBool isBackward = (mmi_frm_is_in_backward_scenario() != MMI_FALSE);
    VfxBool isRedrawing = (mmi_is_redrawing_bk_screens() != MMI_FALSE);

    VFX_LOG(VFX_INFO, VFX_APPSCR_SCR_ENTRY, int(node->screenId), isBackward);

    if (mmi_frm_scrn_enter(
        scrn_info->group_id,
        scrn_info->scrn_id,
        (FuncPtr)&VfxAppScr::static_exit, 
        (FuncPtr)&VfxAppScr::static_entry, 
        MMI_FRM_FULL_SCRN))
    {
        // Early set leave proc here, to make sure it will always be called.
        // Because screen may exit itself in onEnter.
        mmi_frm_scrn_set_leave_proc(
            scrn_info->group_id, 
            scrn_info->scrn_id,
            &VfxAppScr::static_proc);

        VfxApp* app = VfxApp::getObject(scrn_info->group_id);
        VFX_DEV_ASSERT(app);

        // Serialize
        if (app->m_pTopScreen.isValid())
        {
            // if the top screen is not as next screen, or not NULL, serialize it
            if (app->m_pTopScreen.get() != node->screen.get())
            {
                app->m_pTopScreen->serialize(VFX_TRUE);
            }
        }

        // Restore if necessary
        if (!node->screen.isValid() && (node->flag & VFX_SCR_HISTORY_NODE_SERIALIZE_FLAG))
        {
            node->screen = (VfxAppScr*)node->classInfo->createObject(app);
            VFX_ASSERT(node->screen->isKindOf(VFX_OBJ_CLASS_INFO(VfxAppScr)));

            node->screen->m_screenId = node->screenId;
            node->screen->m_pHistoryNode = node;
            
            node->screen->restore();
        }

        if (node->screen.isValid())
        {
            if (!isRedrawing)
                node->screen->updateCABCMode();

            if (node->screen->getIsSmallScreen())
            {
                set_small_screen();
            }
            
            app->m_pTopScreen = node->screen;

            // Active the screen
            if(app->m_pTopScreen->getVrtCacheSize() == 0xFFFFFFFF)
            {
                app->m_pTopScreen->setVrtCacheSize((VfxU32)(((mmi_res_get_app_vrt_mem_factor(app->getGroupId()))*VRT_MEM_UNIT_SIZE)+0.5));
            }

#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("XSA", SA_start);
#endif
            VfxTopLevel* topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
            topLevel->enterToScreen(node->screen.get(), isBackward);  
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("XSA", SA_stop);
#endif
        }
    }

}


mmi_ret VfxAppScr::static_callerProc(mmi_event_struct *evt)
{
    VfxU32 d = (VfxU32)evt->user_data;
    mmi_id groupId = (mmi_id)((d >> 16) & 0xFFFF);
    mmi_id scrId = (mmi_id)(d & 0xFFFF);

    VfxApp *app = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(groupId), VfxApp);
    if(!app)
        return MMI_RET_OK;

    VfxAppScr *scr = app->getScreen(scrId);
    if(!scr)
        return MMI_RET_OK;

    return scr->processProc(evt);
}

mmi_ret vfxSetCuiCallerScr(mmi_id cuiId, VfxAppScr* scr)
{
    mmi_ret result;
    mmi_group_node_struct cuiInfo;
    VfxU32 userdata;

    result = mmi_frm_group_get_info(cuiId, &cuiInfo);
    if(result != MMI_RET_OK)
        return result;
    
    // make sure cui / scr has the same parent
    if(scr->getGroupId() != cuiInfo.parent)
        return MMI_RET_ERR;

    userdata = ((scr->getGroupId() << 16) | scr->getScreenId());

    return mmi_frm_group_set_caller_proc(cuiId, &VfxAppScr::static_callerProc, (void*)userdata);
}

