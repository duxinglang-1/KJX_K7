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
 *  vfx_screen.cpp
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Description
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
 *
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_screen.h"

#include "vfx_timer.h"
#include "vfx_frame.h"
#include "vfx_renderer.h"
#include "vfx_timer.h"
#include "vfx_control.h"
#include "vfx_top_level.h"
#include "vfx_pen.h"
#include "vfx_keypad.h"
#include "vfx_base_popup.h"

#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_context.h"
#include "vrt_datatype.h"
#include "vfx_system.h"
#include "vfx_object_list.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_basic_type.h"
#include "vfx_transform.h"
#include "vfx_mmi.h"
#include "vfx_sys_config.h"
#include "vfx_logger.h"

#include "vadp_sys_trc.h"
#include "vfx_adp_device.h"

extern "C"
{
#include "mmi_frm_history_gprot.h"
#include "gdi_include.h"
}


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



/***************************************************************************** 
 * Global function
 *****************************************************************************/

void vfxScreenRotateMorph(VfxScreen *screen, const VfxScreenRotateParam &param)
{
    VfxRect parentBounds = screen->getParentFrame()->getBounds();

    // Backup auto-animation
    VfxBool autoAnimate = screen->getAutoAnimate();

    // From
    screen->setAutoAnimate(VFX_FALSE);
    screen->setAnchor(0.5f, 0.5f);
    screen->setPos(parentBounds.size.width / 2, parentBounds.size.height / 2);
    screen->setQuality(VFX_RENDER_QUALITY_NORMAL);
    VfxTransform t;
    t.data.affine.rz = VFX_DEG_TO_RAD(90.0f) * 
        (((VfxU32)param.rotateTo - (VfxU32)param.rotateFrom + 4) % 4);
    if (t.data.affine.rz > VFX_DEG_TO_RAD(180.0f))
    {
        t.data.affine.rz -= VFX_DEG_TO_RAD(360.0f);
    }
    screen->setTransform(t);

    // To
    screen->setAutoAnimate(VFX_TRUE);
    t.setIdentity();
    screen->setTransform(t);
    screen->setSize(parentBounds.size);

    // Restore auto-animation
    screen->setAutoAnimate(autoAnimate);

    screen->setNoAnimRotate(VFX_FALSE);
}


void vfxScreenRotateRotateOnly(VfxScreen *screen, const VfxScreenRotateParam &param)
{
    VfxRect parentBounds = screen->getParentFrame()->getBounds();

    // Backup auto-animation
    VfxBool autoAnimate = screen->getAutoAnimate();

    // From
    screen->setAutoAnimate(VFX_FALSE);
    screen->setAnchor(0.5f, 0.5f);
    screen->setPos(parentBounds.size.width / 2, parentBounds.size.height / 2);
    screen->setQuality(VFX_RENDER_QUALITY_NORMAL);
    VfxTransform t;
    t.data.affine.rz = VFX_DEG_TO_RAD(90.0f) * 
        (((VfxU32)param.rotateTo - (VfxU32)param.rotateFrom + 4) % 4);
    if (t.data.affine.rz > VFX_DEG_TO_RAD(180.0f))
    {
        t.data.affine.rz -= VFX_DEG_TO_RAD(360.0f);
    }
    screen->setTransform(t);

    // To
    screen->setAutoAnimate(VFX_TRUE);
    t.setIdentity();
    screen->setTransform(t);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    screen->setSize(parentBounds.size);
    VfxAutoAnimate::commit();

    // Restore auto-animation
    screen->setAutoAnimate(autoAnimate);

    screen->setNoAnimRotate(VFX_TRUE);
}


/***************************************************************************** 
 * Class VfxScreenEntryCanvasParam
 *****************************************************************************/
 
VfxScreenEntryCanvasParam::VfxScreenEntryCanvasParam() :
    flags(0),
    attachVrtBufferFromAsmSize(0),
    attachVrtBufferForCacheLimit(0)
{
}

/***************************************************************************** 
 * Class VfxScreenLeaveCanvasParam
 *****************************************************************************/
 
VfxScreenLeaveCanvasParam::VfxScreenLeaveCanvasParam() :
    flags(0)
{
}


/***************************************************************************** 
 * Class VfxScreen
 *****************************************************************************/
 
VFX_IMPLEMENT_CLASS(VFX_SCREEN_CLASS_NAME, VfxScreen, VfxControl);


VfxScreen::VfxScreen() :
    m_pAccessKeyMgr(NULL),
    m_vrtCacheSize(0xFFFFFFFF),
    m_vrtCacheLimitSize(0),
    m_screenFlags(SCREEN_FLAGS_NONE),
    m_pContext(NULL),
    m_isStartIme(VFX_FALSE),
    m_frameImeTarget(NULL),
    m_screenDisable(VFX_FALSE),
    m_popupLeaving(NULL),
    m_transitType(VFX_SCR_TRANSIT_TYPE_DEFAULT),
    m_rotateType(VFX_SCR_ROTATE_TYPE_NORMAL)
{
}


void VfxScreen::entryCanvas(VfxContext *context, const VfxScreenEntryCanvasParam &param)    
{
    VFX_ASSERT(context != NULL);
    
    if (vfx_sys_get_canvas_state() == VFX_SYS_STATE_ENTRY)
    {
        return;
    }

    VFX_LOG_STATIC_FUNC;
    VFX_LOG(VFX_INFO, VFX_SCREEN_ENTRY_CANVAS, context, param.flags);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XCV", SA_start);
#endif

    if (!VFX_FLAG_HAS(param.flags, VFX_SCREEN_ENTRY_CANVAS_FLAG_WITHOUT_RESET))
    {
        VfxKeypad *keypad = VFX_OBJ_GET_INSTANCE(VfxKeypad);
        keypad->reset();
    }

    // Prepare memory config flags
    VfxFlag memConfigFlags = 0;
    if (VFX_FLAG_HAS(param.flags, VFX_SCREEN_ENTRY_CANVAS_FLAG_SHARE_APP_CONTEXT_FOR_VRT))
    {
        VFX_FLAG_SET(memConfigFlags, VFX_SYS_MEM_CONFIG_FLAG_SHARE_APP_CONTEXT_FOR_VRT);
    }
    if (VFX_FLAG_HAS(param.flags, VFX_SCREEN_ENTRY_CANVAS_FLAG_FORBID_GDI_LAYER))
    {
        VFX_FLAG_SET(memConfigFlags, VFX_SYS_MEM_CONFIG_FLAG_FORBID_GDI_LAYER);
    }

    // Prepare VRT flags
    VfxFlag vrtFlags = 0;
    if (vfx_adp_sleep_mode_get_state() != VFX_ADP_SLEEP_MODE_STATE_ENABLE)
    {
        VFX_FLAG_SET(vrtFlags, VRT_CANVAS_ENTRY_FLAG_POWER_OFF);
    }
    if (VFX_FLAG_HAS(param.flags, VFX_SCREEN_ENTRY_CANVAS_FLAG_FORBID_MAIN_BASE_LAYER))
    {
        VFX_FLAG_SET(vrtFlags, VRT_CANVAS_ENTRY_FLAG_FORBID_MAIN_BASE_LAYER);
    }

    vfx_sys_entry_canvas(
        context->getAllocator(), 
        memConfigFlags,
        vrtFlags,
        param.attachVrtBufferFromAsmSize,
        param.attachVrtBufferForCacheLimit);

    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->startup();

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->startup();
    
    VfxTimerManager *timerManager = VFX_OBJ_GET_INSTANCE(VfxTimerManager);
    timerManager->switchTimerType(VFX_TIMER_MANAGER_TYPE_VRT_TIMER);

    if (!VFX_FLAG_HAS(param.flags, VFX_SCREEN_ENTRY_CANVAS_FLAG_WITHOUT_RESET))
    {
        VfxPen *penSrv = VFX_OBJ_GET_INSTANCE(VfxPen);
        penSrv->startup();        
    }
}


void VfxScreen::entryCanvas(VfxContext *context)
{
    // Create a parametser object with default settings
    VfxScreenEntryCanvasParam param;
    entryCanvas(context, param);
}


void VfxScreen::leaveCanvas(const VfxScreenLeaveCanvasParam &param)
{
    if (vfx_sys_get_canvas_state() != VFX_SYS_STATE_ENTRY)
    {
        return;
    }    
    
    VFX_LOG_STATIC_FUNC;

    if (!VFX_FLAG_HAS(param.flags, VFX_SCREEN_LEAVE_CANVAS_FLAG_WITHOUT_RESET))
    {
        VfxPen *penSrv = VFX_OBJ_GET_INSTANCE(VfxPen);
        penSrv->shutdown();
    }        

    VfxTimerManager *timerManager = VFX_OBJ_GET_INSTANCE(VfxTimerManager);
    timerManager->switchTimerType(VFX_TIMER_MANAGER_TYPE_VFX_TIMER);
    
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->shutdown();
    
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->shutdown();

    // Prepare VRT flags
    VfxFlag vrtFlags = 0;
    if (VFX_FLAG_HAS(param.flags, VFX_SCREEN_LEAVE_CANVAS_FLAG_FORBID_FLATTEN))
    {
        VRT_FLAG_SET(vrtFlags, VRT_CANVAS_LEAVE_FLAG_FORBID_FLATTEN);
    }
    if (VFX_FLAG_HAS(param.flags, VFX_SCREEN_LEAVE_CANVAS_FLAG_NEXT_HAS_VRT))
    {
        VRT_FLAG_SET(vrtFlags, VRT_CANVAS_LEAVE_FLAG_NEXT_HAS_VRT);
    }

    vfx_sys_leave_canvas(vrtFlags);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("XCV", SA_stop);
#endif
    VFX_LOG(VFX_INFO, VFX_SCREEN_LEAVE_CANVAS, param.flags);
}


void VfxScreen::leaveCanvas()
{
    // Create a parametser object with default settings
    VfxScreenLeaveCanvasParam param;
    leaveCanvas(param);
}


void VfxScreen::clearPopupStack()
{
    VFX_LOG_FUNC;
    // whatever clear or not clear popup, swith it to enable
    switchToEnable();

    if (m_popupStack.isEmpty()) 
    {
        return;
    }

    VfxObjListEntry *entry = m_popupStack.getTail();
    VFX_DEV_ASSERT(entry != NULL);

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VfxBasePopup *popup = (VfxBasePopup *)entry->get();
    if (popup == topLevel->getActivePopup())
    {
        popup->processLeaveStack(this);
        topLevel->leavePopup(popup, VFX_FALSE);
        entry = entry->getPrev();
    }

    // Clear all background popup
    for (;entry != NULL; entry = entry->getPrev())
    {
        VfxBasePopup *popup = (VfxBasePopup *)entry->get(); 
        if (popup != NULL)
        {
            popup->processLeaveStack(this);
            // popup already leave
            if (popup->m_destoryType == VfxBasePopup::DESTROY_TYPE_CLOSE)
            {
                vfxPostInvoke0(popup, &VfxBasePopup::closePopup);
            }
        }
    }

    m_popupStack.clear();
}


void VfxScreen::processBeforeEnter(VfxScreen *screen, VfxBool isBackward)
{
    VFX_LOG_STATIC_FUNC2("<%X>,%d", screen, isBackward);

    VFX_DEV_ASSERT(screen != NULL);
    VFX_DEV_ASSERT(screen->m_pContext != NULL);

    VfxBool isSnapshotDrawingMode = 
        mmi_is_redrawing_bk_screens() || 
            gdi_lcd_get_freeze();
    screen->setIsSnapshotDrawing(isSnapshotDrawingMode);

    // Prepare parameters
    VfxScreenEntryCanvasParam param;    
    if (VFX_FLAG_HAS(screen->m_screenFlags, SCREEN_FLAGS_SMALL_SCREEN))
    {
        VFX_FLAG_SET(param.flags, VFX_SCREEN_ENTRY_CANVAS_FLAG_FORBID_MAIN_BASE_LAYER);
    }
    if (VFX_FLAG_HAS(screen->m_screenFlags, SCREEN_FLAGS_APP_CONTEXT_SHARE_FOR_VRT))
    {
        VFX_FLAG_SET(param.flags, VFX_SCREEN_ENTRY_CANVAS_FLAG_SHARE_APP_CONTEXT_FOR_VRT);
    }
    if (screen->m_vrtCacheSize != 0xFFFFFFFF)
    {
        param.attachVrtBufferFromAsmSize = screen->m_vrtCacheSize;
    }
    param.attachVrtBufferForCacheLimit = screen->m_vrtCacheLimitSize;

    // Startup canvas engine (VRT) with context of the screen
    entryCanvas(screen->m_pContext, param);
}


void VfxScreen::processEnter(VfxBool isBackward)
{
    VFX_LOG_FUNC1("%d", isBackward);

    // Callback
    if (getIsSnapshotDrawing())
    {
        onSnapshotEnter();
    }
    else
    {
        onEnter(isBackward);
        broadcastEvent(VFX_FRAME_BROADCAST_EVENT_BEFOR_ENTER);

        // ScrTransit
        if (!isBackward)
        {
            vfx_adp_sse_setup_transit(getTransitType(), VFX_TRUE, VFX_SCR_TRANSIT_PRIORITY_USER);
        }
    }
}


void VfxScreen::processAfterEnter(VfxScreen *screen, VfxBool isBackward)
{
    VFX_LOG_STATIC_FUNC2("<%X>,%d", screen, isBackward);

    // All enter callback has been done, and than
    //  - finish all post event
    //  - commit scene graph to VRT (paused)
    //  - Ask VRT to draw one frame to LCD
    // VRT will be resumed after Pluto screen entered (vfx_mmi_screen_entered())
    
    VfxWeakPtr <VfxScreen> screenPtr(screen);

    // Finish all post event and commit scene graph to VRT
    //  The commit should be blocking, because SSE need use this buffer.
    vfx_mmi_update_scene_and_suspend();

    // TODO: review this check
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    if (screenPtr == NULL || screenPtr != topLevel->getActiveScr())
    {
        return;
    }
    
    vfx_adp_sse_commit();

    if (!screen->getIsSnapshotDrawing())
    {
        isBackward ? 
            VFX_FLAG_SET(screen->m_screenFlags, SCREEN_FLAGS_BACKWARD_ENTERED) :
            VFX_FLAG_CLEAR(screen->m_screenFlags, SCREEN_FLAGS_BACKWARD_ENTERED);            

        VFX_FLAG_SET(screen->m_screenFlags, SCREEN_FLAGS_ENTERING);

        // Send a primitive event to implement onEntered()
        //  This is a temp solution that VRT will send a new primitive after SSE.
        //  It should be the first primitive after SSE.
        vrt_invoke_mmi_rpc(onEnteredCallback, screen->getObjHandle());
    }
}


void VfxScreen::processEntered(VfxBool isBackward)
{
    VFX_LOG_FUNC;

    VFX_FLAG_CLEAR(m_screenFlags, SCREEN_FLAGS_ENTERING);

    // Callback
    onEntered(isBackward);
    broadcastEvent(VFX_FRAME_BROADCAST_EVENT_AFTER_ENTER);

    // Resume all popups
    resumePopupStack();
}


void VfxScreen::processBeforeExit(VfxBool isBackward)
{
    VFX_LOG_FUNC1("%d", isBackward);

    VFX_FLAG_CLEAR(m_screenFlags, SCREEN_FLAGS_ENTERING);
}


void VfxScreen::processExit(VfxBool isBackward)
{
    VFX_LOG_FUNC1("%d", isBackward);

    // Callback onExit() before screen displaying last shot
    if (!getIsSnapshotDrawing())
    {
        // Callback
        onExit(isBackward);
        broadcastEvent(VFX_FRAME_BROADCAST_EVENT_BEFORE_EXIT);

        if (isBackward)
        {
            // Clear all popup if backward
            clearPopupStack();
        }
        else
        {
            // Suspend all popup
            suspendPopupStack();
        }

        if (m_popupLeaving.isValid())
        {
            m_popupLeaving->setHidden(VFX_TRUE);
            m_popupLeaving = NULL;
        }

        // ScrTransit
        if (isBackward)
        {
            vfx_adp_sse_setup_transit(getTransitType(), VFX_FALSE, VFX_SCR_TRANSIT_PRIORITY_USER);
        }

        // Commit the latest state
        VfxWeakPtr <VfxScreen> self(this);
        setFocused(VFX_FALSE);

        // For small screen, clear the background color
        if (getIsSmallScreen())
        {
            setBgColor(VFX_COLOR_TRANSPARENT);
        }

        if (!getIsSnapshotDrawing() &&
            !(getIsSmallScreen() && isBackward))
        {
            vfx_mmi_update_scene_and_suspend();
        }
        else
        {
            vfx_mmi_check_update();
        }
        if (!self.isValid())
        {
            return;
        }
    }

    // Pause update screen, so that we can delete object safely.
    vrt_canvas_suspend();
}


void VfxScreen::processAfterExit(VfxBool isBackward)
{
    VFX_LOG_FUNC1("%d", isBackward);
    
    // Wait screen displaying last shot and than callback onExited()
    //
    // We CANNOT drawing the final screen in following cases:
    // 1. Now is in redrawing small screen
    // 2. Venus is inited when LCD freeze (caller don't wanna screen update)
    if (!getIsSnapshotDrawing())
    {
        onExited(isBackward);
        broadcastEvent(VFX_FRAME_BROADCAST_EVENT_AFTER_EXIT);
    }
    else
    {
        onSnapshotExit();
        suspendPopupStack();
    }

    // Prepare parameters to leaving canvas engine
    VfxScreenLeaveCanvasParam param;

    // We don't need to keep screen snapshot on main base layer,
    //  because Small Screen backward is always without SSE.
    if (getIsSmallScreen() && isBackward)
    {
        VFX_FLAG_SET(param.flags, VFX_SCREEN_LEAVE_CANVAS_FLAG_FORBID_FLATTEN);
    }

    if (VFX_FLAG_HAS(m_screenFlags, SCREEN_FLAGS_NEXT_IS_VENUS))
    {
        VFX_FLAG_SET(param.flags, VFX_SCREEN_LEAVE_CANVAS_FLAG_NEXT_HAS_VRT);
        VFX_FLAG_CLEAR(m_screenFlags, SCREEN_FLAGS_NEXT_IS_VENUS);
    }

    leaveCanvas(param);

    // Reset flags
    setIsSnapshotDrawing(VFX_FALSE);
}


void VfxScreen::queryRotate(VfxScreenRotateParam &param)
{
    onQueryRotateEx(param);
}


void VfxScreen::processRotate(const VfxScreenRotateParam &param)
{
    VFX_LOG_FUNC;

    m_rotateType = param.rotateTo;

    if (m_popupLeaving.isValid())
    {
        m_popupLeaving->setHidden(VFX_TRUE);
        m_popupLeaving = NULL;
    }

    onRotate(param);
}


void VfxScreen::showPopup(VfxBasePopup *popup, VfxBool isAnim)
{
    VFX_LOG_FUNC;
    VFX_OBJ_ASSERT_VALID(popup);
    
    if (m_popupStack.contains(popup))
    {
        // already show
        return;
    }

    // stop m_blackScreenTimer if m_blackScreenTimer is leaving
    m_blackScreenTimer->stop();

    // If this screen is inactive, 
    //  do nothing if the popup does not push into history.
    //  Or push the popup into screen stack, and the popup will active 
    //  when the screen active next time.
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    if (topLevel->getActiveScr() != this)
    {
        if(popup->needPushHistory())
        {
            popup->processEnterStack(this);
            m_popupStack.append(popup);
        }
        return;
    }

    // The screen is active, but it is entering
    //  Queue this popup into the popup stack and it will display after screen entered.
    if (topLevel->getActiveScreenState() == VFX_TOP_LEVEL_ACTIVE_SCREEN_STATE_ENTERING)
    {
        popup->processEnterStack(this);
        m_popupStack.append(popup);
        return;
    }

    switchToDisable(popup, isAnim, popup->getIsStaticShelter());

    if (!m_popupStack.isEmpty())
    {
        // If the popup does not need to push to histroy, 
        //  remove it from the stack
        VfxBasePopup *origPopup = (VfxBasePopup *)m_popupStack.getLast();
        if (!origPopup->needPushHistory())
        {
            origPopup->processLeaveStack(this);
            m_popupStack.removePos(m_popupStack.getTail());
        }

        topLevel->leavePopup(origPopup, VFX_FALSE, popup->getCatchFocus());
    }

    // Push the new popup to the stack
    popup->processEnterStack(this);
    m_popupStack.append(popup);

    if (isCustomRotate())
    {
        isAnim = VFX_FALSE;
    }

    // Show popup
    topLevel->showPopup(popup, isAnim);

    m_popupLeaving = NULL;
}


void VfxScreen::leavePopup(VfxBasePopup *popup, VfxBool isAnim)
{
    VFX_LOG_FUNC;
    VFX_OBJ_ASSERT_VALID(popup);

    if (!m_popupStack.contains(popup))
    {
        // popup already leaved
        popup->processLeavedPopup();
        return;
    }

    // Remove from call stack
    popup->processLeaveStack(this);
    m_popupStack.removeOne(popup);

    m_popupLeaving = popup;
    
    if (isCustomRotate())
    {
        isAnim = VFX_FALSE;
    }

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->leavePopup(popup, isAnim);

    // If there is no more popup in the screen stack, hide the shelter.    
    if (topLevel->getActiveScr() == this && m_popupStack.isEmpty()) 
    {
        topLevel->hideShelter(isAnim);
        m_blackScreenTimer->setStartDelay(popup->getEffectDuration());
        m_blackScreenTimer->start();
        return;
    }

    // Show topmost popup in stack if the screen is active screen
    if (topLevel->getActiveScr() == this)
    {
        VfxBasePopup *nextPopup = (VfxBasePopup *)m_popupStack.getLast();

        // Update Shelter for new popup
        switchToDisable(nextPopup, isAnim, nextPopup->getIsStaticShelter()); 

        topLevel->showPopup(nextPopup, VFX_FALSE);
    }
}


void VfxScreen::onInit()
{
    VFX_LOG_FUNC;
    VFX_LOG(VFX_INFO, VFX_SCREEN_ON_INIT, this);

    m_pContext = findContext();
    // We need to make sure the root is a context object.
    VFX_ASSERT(m_pContext != NULL);
    
    VfxControl::onInit();
   
    // Set properties
    setCacheMode(VFX_CACHE_MODE_PREVENT);
    setIsOpaque(VFX_TRUE);
    setOpaqueMode(
        getIsSmallScreen() ?
            VFX_FRAME_OPAQUE_MODE_AUTO :
            VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    
    VFX_OBJ_CREATE(m_pAccessKeyMgr, VfxAccessKeyMgr, this);

    VFX_OBJ_CREATE(m_blackScreenTimer, VfxTimer, this);
    m_blackScreenTimer->m_signalTick.connect(this, &VfxScreen::onBlackScreenTimerStop);
}


void VfxScreen::onDeinit()
{
    VFX_LOG_FUNC;
    VFX_LOG(VFX_INFO, VFX_SCREEN_ON_DEINIT, this);

    // Clean stacked popup
    while (!m_popupStack.isEmpty())
    {
        VfxObjListEntry* entry = m_popupStack.getHead();
        VfxBasePopup *popup = (VfxBasePopup *)entry->get();
        VFX_OBJ_CLOSE(popup);
    }
    // Make sure the shleter closed
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    if (topLevel->getActiveScr() == NULL || topLevel->getActiveScr() == this)
    {
        topLevel->exitShelter();
    }

    VfxControl::onDeinit();
}


void VfxScreen::processRegisterAccessKeyHandler(VfxKeyCodeEnum keyCode, VfxControl *target)
{
    registerAccessKeyHandler(keyCode, target);
}


void VfxScreen::processUnregisterAccessKeyHandler(VfxKeyCodeEnum keyCode, VfxControl *target)
{
    unregisterAccessKeyHandler(keyCode, target);
}


void VfxScreen::processUnregisterAllAccessKeyHandler(VfxControl *target)
{   
    unregisterAllAccessKeyHandler(target);
}

    
VfxBool VfxScreen::processFocusKey(VfxKeyEvent &event)
{
    VFX_LOG_FUNC;
    VfxBool ret = VFX_FALSE;

    // If there is focused child, let it handle first
    if (getFocusChildFrame())
    {
        ret = getFocusChildFrame()->processFocusKey(event);
    }

    // If there is access key registered, process it
    if (!ret)
    {
        VFX_DEV_ASSERT(m_pAccessKeyMgr != NULL);
        ret = m_pAccessKeyMgr->processKeyInput(event);
    }

    // If there is no other one handle it, handle it by screen it self.
    if (!ret)
    {
        ret = onKeyInput(event);
    }
    return ret;
}


void VfxScreen::onFocusChanged(VfxBool value)
{
    VfxControl::onFocusChanged(value);

    if (value)
    {
        VfxKeypad* keypad = VFX_OBJ_GET_INSTANCE(VfxKeypad);
        keypad->registerTranslateKey();
    }        
}


void VfxScreen::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_FRAME_NOTIFY_ID_FOCUS_CHANGED:
        {
            onFocusChanged(*(VfxBool *)userData);
            return;
        }
        default:
        {
            VfxControl::onObjectNotify(id, userData);
            return;
        }
    }
}


void VfxScreen::setVrtCacheSize(VfxU32 size)
{
    m_vrtCacheSize = size;
}

VfxU32 VfxScreen::getVrtCacheSize() const 
{
    return m_vrtCacheSize;
}


void VfxScreen::setVrtCacheLimitSize(VfxU32 size)
{
    m_vrtCacheLimitSize = size;
}

VfxBool VfxScreen::getIsSmallScreen() const
{
    return VFX_FLAG_HAS(m_screenFlags, SCREEN_FLAGS_SMALL_SCREEN);
}


VfxBool VfxScreen::getIsSmallScreenDisable() const
{
    return VFX_FLAG_HAS(m_screenFlags, SCREEN_FLAGS_SMALL_SCREEN_DISABLE);
}


VfxBool VfxScreen::getIsSnapshotDrawing() const
{
    return VFX_FLAG_HAS(m_screenFlags, SCREEN_FLAGS_SNAPSHOT_DRAWING);
}


void VfxScreen::registerAccessKeyHandler(VfxKeyCodeEnum keyCode, VfxControl *control)
{
    VFX_DEV_ASSERT(m_pAccessKeyMgr != NULL);
    m_pAccessKeyMgr->registerHandler(keyCode, control);
}


void VfxScreen::unregisterAccessKeyHandler(VfxKeyCodeEnum keyCode, VfxControl *control)
{
    VFX_DEV_ASSERT(m_pAccessKeyMgr != NULL);
    m_pAccessKeyMgr->unregisterHandler(keyCode, control);
}


void VfxScreen::unregisterAllAccessKeyHandler(VfxControl *control)
{
    VFX_DEV_ASSERT(m_pAccessKeyMgr != NULL);
    m_pAccessKeyMgr->unregisterAllHandler(control);
}


void VfxScreen::setNextIsVenus()
{
    VFX_FLAG_SET(m_screenFlags, SCREEN_FLAGS_NEXT_IS_VENUS);
}


void VfxScreen::setAppContextShareForVrt(VfxBool isEnable)
{
    isEnable ? 
        VFX_FLAG_SET(m_screenFlags, SCREEN_FLAGS_APP_CONTEXT_SHARE_FOR_VRT) :
        VFX_FLAG_CLEAR(m_screenFlags, SCREEN_FLAGS_APP_CONTEXT_SHARE_FOR_VRT);
}


void VfxScreen::setIsCustomRotate(VfxBool value)
{
    if (value)
    {
        VFX_FLAG_SET(m_screenFlags, SCREEN_FLAGS_CUSTOM_ROTATE);
    }
    else
    {
        VFX_FLAG_CLEAR(m_screenFlags, SCREEN_FLAGS_CUSTOM_ROTATE);
    }
}


VfxBool VfxScreen::isCustomRotate() const
{
    return VFX_FLAG_HAS(m_screenFlags, SCREEN_FLAGS_CUSTOM_ROTATE);
}


void VfxScreen::setNoAnimRotate(VfxBool value)
{
    value ? 
        VFX_FLAG_SET(m_screenFlags, SCREEN_FLAGS_NO_ANIM_ROTATE) :
        VFX_FLAG_CLEAR(m_screenFlags, SCREEN_FLAGS_NO_ANIM_ROTATE);
}


VfxBool VfxScreen::isNoAnimRotate()
{
    return VFX_FLAG_HAS(m_screenFlags, SCREEN_FLAGS_NO_ANIM_ROTATE);
}


void VfxScreen::setTransitType(VfxScrTransitTypeEnum type)
{
    m_transitType = type;
}

VfxScrTransitTypeEnum VfxScreen::getTransitType() const
{
    return m_transitType;
}

void VfxScreen::setScreenRotateType(VfxScrRotateTypeEnum newRotateType)
{
    VFX_LOG_FUNC;
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->setScreenRotateType(newRotateType);
}


VfxRect VfxScreen::onGetClientRect() const
{
    return getBounds();
}


void VfxScreen::onEnter(VfxBool isBackward)
{    
    VFX_UNUSED(isBackward);
    // do nothing
}


void VfxScreen::onEntered(VfxBool isBackward)
{
    VFX_UNUSED(isBackward);
    // do nothing
}


void VfxScreen::onExit(VfxBool isBackward)
{
    VFX_UNUSED(isBackward);
    // do nothing
}


void VfxScreen::onExited(VfxBool isBackward)
{
    VFX_UNUSED(isBackward);
    // do nothing
}


void VfxScreen::onSnapshotEnter()
{    
    // do nothing
}


void VfxScreen::onSnapshotExit()
{
    // do nothing
}


void VfxScreen::onQueryRotateEx(VfxScreenRotateParam &param)
{
    param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
}


void VfxScreen::onRotate(const VfxScreenRotateParam &param)
{
    VFX_CFG_SCREEN_ROTATE_DEFAULT_EFFECT(this, param);
}


void VfxScreen::onEnteredCallback(void *screenHandle)
{
    VfxScreen *screen = (VfxScreen *)VfxObject::handleToObject(screenHandle);
    if (screen == NULL)
    {
        return;
    }
    
    if (!VFX_FLAG_HAS(screen->m_screenFlags, SCREEN_FLAGS_ENTERING))
    {
        return;
    }
    
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->processScreenAfterEnter(screen, VFX_FLAG_HAS(screen->m_screenFlags, SCREEN_FLAGS_BACKWARD_ENTERED));
}


void VfxScreen::setIMElayout(VfxRect &imeRect, VfxFrame *imeOwner)
{
    VFX_LOG_FUNC;

    // decide IME re-layout path
    // only init path for each IME launch
    if (!m_isStartIme)
    {
        m_resizePath.clear();

        for (VfxFrame *f = imeOwner ; f != NULL ; f = f->getParentFrame())
        {
            m_resizePath.append(f);

            if (f->processGetImeMode() != VFX_FRAME_IME_MODE_NONE)
            {
                m_frameImeTarget = f;
                m_rectImeTarget.origin = f->getPos();
                m_rectImeTarget.size = f->getBounds().size;
                break;
            }
        }
    }

    // adjust frame for IME
    if (m_frameImeTarget != NULL)
    {
        VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
        VfxRect ownerBounds = imeOwner->getBounds();
        VfxPoint ownerMaxPos(ownerBounds.getMaxX(), ownerBounds.getMaxY());
        VfxPoint pos = imeOwner->convertPointTo(ownerMaxPos, topLevel);

        VfxFrameImeModeEnum mode = m_frameImeTarget->processGetImeMode();

        // adjust frame for shift case
        if (mode == VFX_FRAME_IME_MODE_SHIFT)
        {
            VfxPoint p = m_frameImeTarget->getPos();
            VfxS32 diff = imeRect.origin.y - pos.y;

            // calculate suggested pos
            p.y += diff;
            p.y = (p.y > m_rectImeTarget.origin.y) ? (m_rectImeTarget.origin.y) : (p.y);

            m_frameImeTarget->processAdjustImeShift(p, imeOwner);
        }
        // adjust frame for resize case
        else if (mode == VFX_FRAME_IME_MODE_RESIZE)
        {
            VfxPoint imePos = topLevel->convertPointTo(imeRect.origin, (VfxFrame*)(m_frameImeTarget.get()));
            VfxRect b = m_frameImeTarget->getBounds();
            VfxSize s = b.size;

            // calculate suggested size
            s.height = imePos.y - b.origin.y;
            s.height = (s.height > m_rectImeTarget.size.height) ? (m_rectImeTarget.size.height) : (s.height);

            m_frameImeTarget->processAdjustImeResize(s, imeOwner);

            // adjust view port
            VfxObjListEntry *iter;
            for (iter = m_resizePath.getValidTail() ; iter != NULL ; iter = iter->getValidPrev())
            {
                VfxFrame *f = (VfxFrame*)iter->get();
                if (f && f->processUpdateViewForIme(imeOwner))
                {
                    break;
                }
            }
        }
    }

    m_isStartIme = VFX_TRUE;
}


void VfxScreen::resetIMElayout()
{
    VFX_LOG_FUNC;

    if (m_isStartIme && (m_frameImeTarget != NULL))
    {
        VfxFrameImeModeEnum mode = m_frameImeTarget->processGetImeMode();

        if (mode == VFX_FRAME_IME_MODE_SHIFT)
        {
            m_frameImeTarget->processAdjustImeShift(m_rectImeTarget.origin, NULL);
        }
        else if (mode == VFX_FRAME_IME_MODE_RESIZE)
        {
            m_frameImeTarget->processAdjustImeResize(m_rectImeTarget.size, NULL);
        }
    }

    m_isStartIme = VFX_FALSE;
    m_frameImeTarget = NULL;
    m_resizePath.clear();
}


VfxContext *VfxScreen::getContext() const
{
    return m_pContext;
}


void VfxScreen::setIsSmallScreen()
{
    // Note: Can only switch once
    VFX_ASSERT(!VFX_FLAG_HAS(m_screenFlags, SCREEN_FLAGS_SMALL_SCREEN));
    // Note: Can not switch to small after disabled
    VFX_ASSERT(!VFX_FLAG_HAS(m_screenFlags, SCREEN_FLAGS_SMALL_SCREEN_DISABLE));
    
    VFX_FLAG_SET(m_screenFlags, SCREEN_FLAGS_SMALL_SCREEN);
}


void VfxScreen::disableSmallScreen()
{
    if (!VFX_FLAG_HAS(m_screenFlags, SCREEN_FLAGS_SMALL_SCREEN))
    {
        return;
    }

    // Note: Can only switch once
    VFX_DEV_ASSERT(!VFX_FLAG_HAS(m_screenFlags, SCREEN_FLAGS_SMALL_SCREEN_DISABLE));

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->exitBackground();

    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);

    VFX_FLAG_SET(m_screenFlags, SCREEN_FLAGS_SMALL_SCREEN_DISABLE);
    VFX_FLAG_CLEAR(m_screenFlags, SCREEN_FLAGS_SMALL_SCREEN);    
}


void VfxScreen::setIsSnapshotDrawing(VfxBool value)
{
    value ? 
        VFX_FLAG_SET(m_screenFlags, SCREEN_FLAGS_SNAPSHOT_DRAWING) :
        VFX_FLAG_CLEAR(m_screenFlags, SCREEN_FLAGS_SNAPSHOT_DRAWING);
}


VfxContext *VfxScreen::findContext()
{
    // Find the root object
    VfxObject *root = this;
    VfxContext *context = NULL;
    while (root->getParent() != NULL)
    {
        root = root->getParent();        

        context = VFX_OBJ_DYNAMIC_CAST(root, VfxContext);
        if (context)
        {
            return context;
        }
    }
    return NULL;
}


void VfxScreen::onBlackScreenTimerStop(VfxTimer *source)
{
    VFX_UNUSED(source);
    
    switchToEnable();
}


void VfxScreen::onEnteredTimerTick(VfxTimer *source)
{
    VFX_OBJ_CLOSE(source);

    if (!VFX_FLAG_HAS(m_screenFlags, SCREEN_FLAGS_ENTERING))
    {
        return;
    }

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->processScreenAfterEnter(this, VFX_FLAG_HAS(m_screenFlags, SCREEN_FLAGS_BACKWARD_ENTERED));
}


void VfxScreen::switchToEnable()
{
    if (m_screenDisable)
    {
        m_screenDisable = VFX_FALSE;
    
        setIsDisabled(VFX_FALSE);
        setCacheMode(VFX_CACHE_MODE_PREVENT);
    }

    onScreenDisabled(VFX_FALSE);

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    if (topLevel->getActiveScr() == this)
    {
        topLevel->exitShelter();
    }
}


void VfxScreen::switchToDisable(VfxFrame *frame, VfxBool isAnim, VfxBool isStatic)
{
    if (!m_screenDisable)
    {
        m_screenDisable = VFX_TRUE;
        
        setIsDisabled(VFX_TRUE);
        setIsCached(VFX_TRUE);
        setCacheMode(VFX_CACHE_MODE_AUTO);
    }

    onScreenDisabled(VFX_TRUE);

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->showShelter(frame, isAnim, isStatic);
}


void VfxScreen::suspendPopupStack()
{
    VFX_LOG_FUNC;
    
    // whatever clear or not clear popup, swith it to enable
    m_blackScreenTimer->stop();
    switchToEnable();

    if (m_popupStack.isEmpty()) 
    {
        return;
    }

    // We only need to leave the active popup
    VfxBasePopup *origPopup = (VfxBasePopup *)m_popupStack.getLast();
    if (!origPopup->needPushHistory())
    {
        origPopup->processLeaveStack(this);
        m_popupStack.removePos(m_popupStack.getTail());
    }

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->leavePopup(origPopup, VFX_FALSE);
}


void VfxScreen::resumePopupStack()
{
    VFX_LOG_FUNC;
    if (m_popupStack.isEmpty()) 
    {
        // no pending popup
        return;
    }

    VfxBasePopup *topPopup = (VfxBasePopup *)m_popupStack.getLast();

    switchToDisable(topPopup, VFX_TRUE, topPopup->getIsStaticShelter());

    // Show popup
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->showPopup(topPopup, VFX_TRUE);
}

