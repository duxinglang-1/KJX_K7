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
 *  vfx_trc.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __VADP_SYS_TRC_H__
#define __VADP_SYS_TRC_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GEN_FOR_PC
 #include "stack_config.h"
#else
 #include "kal_trace.h"
#endif /* GEN_FOR_PC */

#include "kal_trace.h"

/* For MOD_VFX_FW */
#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "vadp_sys_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_VFX)

    /* Comments for VFX System */
    TRC_MSG(VFX_SYS_ENTRY_CANVAS,           "[VFX] entry canvas : vrt_time=%u")
    TRC_MSG(VFX_SYS_LEAVE_CANVAS,           "[VFX] leave canvas : vrt_time=%u")

    /* Comments for VFX MMI */
    TRC_MSG(VFX_MMI_INIT,                   "[VFX] vfx_mmi_sys_init()")
    TRC_MSG(VFX_MMI_CHECK_UPDATE_BEGIN,     "[VFX] vfx_mmi_check_update() begin")
    TRC_MSG(VFX_MMI_CHECK_UPDATE_END,       "[VFX] vfx_mmi_check_update() end")
    TRC_MSG(VFX_MMI_UPDATE_SCENE,           "[VFX] vfx_mmi_update_scene()")
    TRC_MSG(VFX_MMI_UPDATE_SCENE_COMMIT,    "[VFX] vfx_mmi_update_scene() : vrt_time=%u")
    TRC_MSG(VFX_MMI_LCD_SLEEPOUT,           "[VFX] vfx_mmi_lcd_sleepout_handler() : vrt_time=%u")
    TRC_MSG(VFX_MMI_LCD_SLEEPIN,            "[VFX] vfx_mmi_lcd_sleepin_handler() : vrt_time=%u")
    TRC_MSG(VFX_MMI_SCREEN_ENTERED,         "[VFX] vfx_mmi_screen_entered() : vrt_time=%u")
    TRC_MSG(VFX_MMI_CANVAS_SUSPEND,         "[VFX] canvas suspend")
    TRC_MSG(VFX_MMI_CANVAS_RESUMED,         "[VFX] canvas resumed")

    /* Comments for VfxTimerManager */
    TRC_MSG(VFX_TIMER_INIT,                 "[VfxTimerManager] onInit()")
    TRC_MSG(VFX_TIMER_START_TIMER,          "[VfxTimerManager] startTimer(%08x %d %d)")
    TRC_MSG(VFX_TIMER_STOP_TIMER,           "[VfxTimerManager] stopTimer(%08x)")
    TRC_MSG(VFX_TIMER_SWITCH_TIMER_TYPE,    "[VfxTimerManager] switchTimerType(%d)")
    TRC_MSG(VFX_TIMER_START_SYS_TIME,       "[VfxTimerManager] startSystemTimer(%d %d)")
    TRC_MSG(VFX_TIMER_STOP_SYS_TIME,        "[VfxTimerManager] stopSystemTimer(%d)")
    TRC_MSG(VFX_TIMER_TIME_UP_UNKNOWN,      "[VfxTimerManager] timeUpCallback(): an unknown callback")
    TRC_MSG(VFX_TIMER_TIME_UP,              "[VfxTimerManager] timeUpCallback(%d %d)")
    TRC_MSG(VFX_TIMER_COMMIT_BEGIN,         "[VfxTimerManager] processCommit() begin")
    TRC_MSG(VFX_TIMER_COMMIT_END,           "[VfxTimerManager] processCommit() end #%d")
    TRC_MSG(VFX_TIMER_EMIT,                 "[VfxTimerManager] emitAllTimeUpTimer(%d %08x)")

    /* Comments for VfxPen */
    TRC_MSG(VFX_PEN_STARTUP,                "[VfxPen] startup()")
    TRC_MSG(VFX_PEN_STUTDOWN,               "[VfxPen] shutdown()")
    TRC_MSG(VFX_PEN_SET_CAPTURE,            "[VfxPen] setCapture(%08x) %d old=%08x")
    TRC_MSG(VFX_PEN_PROCESS,                "[VfxPen] processPenInput(%d (%d,%d) %d)")
    TRC_MSG(VFX_PEN_PROCESS_TARGET,         "[VfxPen] processPenInput(): target=%08x")
    TRC_MSG(VFX_PEN_PROCESS_HANDLED,        "[VfxPen] processPenInput(): handled=%08x")
    TRC_MSG(VFX_PEN_PROCESS_DOWN,           "[VfxPen] processPenInput(): down, handled=%08x")
    TRC_MSG(VFX_PEN_PROCESS_UP,             "[VfxPen] processPenInput(): up, captured=%08x")
    TRC_MSG(VFX_PEN_START_CAPTURE_STROKES,  "[VfxPen] startCaptureStrokes(%08x)")
    TRC_MSG(VFX_PEN_STOP_CAPTURE_STROKES,   "[VfxPen] stopCaptureStrokes(%08x)")
    TRC_MSG(VFX_PEN_PROCESS_STROKE,         "[VfxPen] processStrokeInput(%d (%d,%d) %d)")
    
    /* Comments for VfxKeypad */
    TRC_MSG(VFX_KEYPAD_PROCESS,             "[VfxKeypad] processKeyInput(%d %d %d")
    TRC_MSG(VFX_KEYPAD_REGISTER,            "[VfxKeypad] registerHandler(%d %08x")
    TRC_MSG(VFX_KEYPAD_UNREGISTER,          "[VfxKeypad] unregisterHandler(%d %08x")
    TRC_MSG(VFX_KEYPAD_UNREGISTER_ALL,      "[VfxKeypad] unregisterHandlerAll(%08x")
    
    /* Comments for VfxRenderer */
    TRC_MSG(VFX_RENDERER_STARTUP,                       "[VfxRenderer] startup()")
    TRC_MSG(VFX_RENDERER_STUTDOWN,                      "[VfxRenderer] shutdown()")
    TRC_MSG(VFX_RENDERER_SUSPEND_UNTIL_COMMIT,          "[VfxRenderer] suspendUntilCommit()")
    TRC_MSG(VFX_RENDERER_UPDATE_SCENE_BEGIN,            "[VfxRenderer] updateScene(): begin")
    TRC_MSG(VFX_RENDERER_UPDATE_SCENE_END,              "[VfxRenderer] updateScene(): end #%d")
    TRC_MSG(VFX_RENDERER_UPDATE_SCENE_DRAW_FRAME_BEGIN, "[VfxRenderer] updateScene(): draw frame begin")
    TRC_MSG(VFX_RENDERER_UPDATE_SCENE_DRAW_FRAME_END,   "[VfxRenderer] updateScene(): draw frame end")
    TRC_MSG(VFX_RENDERER_UPDATE_SCENE_COMMIT_BEGIN,     "[VfxRenderer] updateScene(): commit begin")
    TRC_MSG(VFX_RENDERER_UPDATE_SCENE_COMMIT_END,       "[VfxRenderer] updateScene(): commit end")
    
    /* Comments for VfxTopLevel */
    TRC_MSG(VFX_TOPLEVEL_STARTUP,           "[VfxTopLevel] startup()")
    TRC_MSG(VFX_TOPLEVEL_SHUTDOWN,          "[VfxTopLevel] shutdown()")
    TRC_MSG(VFX_TOPLEVEL_ENTER_TO_SCREEN,   "[VfxTopLevel] enterToScreen(%08x) old=%08x")
    TRC_MSG(VFX_TOPLEVEL_SHOW_POPUP,        "[VfxTopLevel] showPopup(%08x %d)")
    TRC_MSG(VFX_TOPLEVEL_LEAVE_POPUP,       "[VfxTopLevel] leavePopup(%08x %d)")
    TRC_MSG(VFX_TOPLEVEL_SHOW_SHELTER,      "[VfxTopLevel] showShelter: shelter %x, static %d, bg %x, anim %d, popup %x")

    /* Comments for VfxScreen */
    TRC_MSG(VFX_SCREEN_ENTRY_CANVAS,        "[VfxScreen] entryCanvas(%08x %d)")
    TRC_MSG(VFX_SCREEN_LEAVE_CANVAS,        "[VfxScreen] leaveCanvas(%d)")
    TRC_MSG(VFX_SCREEN_ON_INIT,             "[VfxScreen] onInit(%08x)")
    TRC_MSG(VFX_SCREEN_ON_DEINIT,           "[VfxScreen] onDeinit(%08x)")

    /* Comments for VfxAppCatScr */
    TRC_MSG(VFX_APPCATSCR_INITALIZE,            "[VfxAppCatScr] initializeInt(%08x %d)")
    TRC_MSG(VFX_APPCATSCR_DEINITALIZE,          "[VfxAppCatScr] deinitalize()")
    TRC_MSG(VFX_APPCATSCR_ENABLE_ASM_CACHE,     "[VfxAppCatScr] enableAsmCache()")
    TRC_MSG(VFX_APPCATSCR_ON_INIT,              "[VfxAppCatScr] onInit(%08x)")
    TRC_MSG(VFX_APPCATSCR_ON_AFTER_INIT,        "[VfxAppCatScr] onAfterInit(%08x)")
    TRC_MSG(VFX_APPCATSCR_ON_BEFORE_DEINIT,     "[VfxAppCatScr] onBeforeDeinit(%08x)")
    TRC_MSG(VFX_APPCATSCR_ON_DEINIT,            "[VfxAppCatScr] onDeinit(%08x)")
    TRC_MSG(VFX_APPCATSCR_FIRST_FRAME_FINISH,   "[VfxAppCatScr] onAfterInit() first frame finished")
    TRC_MSG(VFX_APPCATSCR_LAST_FRAME_FINISH,    "[VfxAppCatScr] onBeforeDeinit() last frame finished")
    TRC_MSG(VFX_APPCATSCR_CANVAS_RESUMED,       "[VfxAppCatScr] canvas resumed")
    TRC_MSG(VFX_APPCATSCR_CANVAS_SUSPEND,       "[VfxAppCatScr] canvas suspend")

    /* Comments for VfxAppLauncher */
    TRC_MSG(VFX_APPLAUNCHER_LAUNCH_BY_MEM,          "[AppLauncher] launchByMem (gid=%d, cInfo=0x%X, cid=%d, heap=0x%X, hSize=%d, cb=0x%X, userData=0x%X, arg=0x%X, aSize=%d")
    TRC_MSG(VFX_APPLAUNCHER_LAUNCH_BY_CTX,          "[AppLauncher] launchByCtx (gid=%d, cInfo=0x%X, cid=%d, ctx=0x%X, arg=0x%X, aSize=%d)")
    TRC_MSG(VFX_APPLAUNCHER_TERMINATE,              "[AppLauncher] terminate (gid=%d, obj=0x%X)")
    TRC_MSG(VFX_APPLAUNCHER_CTX_MEM_NOT_ENOUGH_1,   "[AppLauncher] createCtx : mem. not enough for %d (heapSize=%d, depSize=%d)")
    TRC_MSG(VFX_APPLAUNCHER_CTX_MEM_NOT_ENOUGH_2,   "[AppLauncher] createCtx : mem. not enough for %d (heapSize=%d)")
    TRC_MSG(VFX_APPLAUNCHER_CTX_READY,              "[AppLauncher] context ready for %d (ctx=0x%X, app=0x%X)")
    TRC_MSG(VFX_APPLAUNCHER_GROUP_DEINIT,           "[AppLauncher] GroupDeinit (%d)")
    TRC_MSG(VFX_APPLAUNCHER_ASM_READY,              "[AppLauncher] ctx from ASM is ready for %d")
    TRC_MSG(VFX_APPLAUNCHER_ASM_CANCEL,             "[AppLauncher] ctx alloc. fail for %d (reason=%d)")
    TRC_MSG(VFX_APPLAUNCHER_NON_HANDLED_EVT,        "[AppLauncher] non handled evt in launcher proc (gid=%d, eid=%d)")
    TRC_MSG(VFX_APPLAUNCHER_CUI_CREATE,             "[AppLauncher] CUI create (gid=%d, cInfo=0x%X, pid=%d, heap=0x%X, hSize=%d, arg=0x%X, aSize=%d")
    TRC_MSG(VFX_APPLAUNCHER_CUI_RUN,                "[AppLauncher] CUI run (gid=%d, launcher=0x%X)")

    /* Comments for VfxAppContext */
    TRC_MSG(VFX_APPCONTEXT_SET_CB,          "[AppContext] setFreeContextMemCallback (this=0x%X, cb=0x%X, userData=0x%X)")
    TRC_MSG(VFX_APPCONTEXT_ON_DEINIT,       "[AppContext] onDeinit (this=0x%X, ctx=0x%X, cb=0x%X, userData=0x%X)")

    /* Comments for vfx_sys_mem_pool */
    TRC_MSG(VFX_SYS_MEM_POOL_USED_IN_SHRINK,"[vfx_sys_mem_pool][shrink_slmm_heap] app:%MRESOURCE_BASE_ENUM shrink heap size to %d (used page size:%d, used size: %d)")
    TRC_MSG(VFX_SYS_MEM_POOL_PROFILE_OVERALL_NO_ID, "[vfx_sys_mem_pool][Profile_overall] Heap addr:0x%x, peak size:%d, heap size:%d")
    TRC_MSG(VFX_SYS_MEM_POOL_PROFILE_OVERALL_KNOW_ID,"[vfx_sys_mem_pool][Profile_overall] Heap of ap:%MRESOURCE_BASE_ENUM ,peak size:%d, heap size:%d")
    TRC_MSG(VFX_SYS_MEM_POOL_PROFILE_ENABLE,"[vfx_sys_mem_pool][Profile_detail][Enable] appid:%MRESOURCE_BASE_ENUM ,threshold size:%dKB")
    TRC_MSG(VFX_SYS_MEM_POOL_PROFILE_DISABLE,"[vfx_sys_mem_pool][Profile_detail][Disabled]")
    TRC_MSG(VFX_SYS_MEM_POOL_PROFILE_TRIGGERED,"[vfx_sys_mem_pool][Profile_detail] app id:%MRESOURCE_BASE_ENUM used size:%d ,snapshoted")
    TRC_MSG(VFX_SYS_MEM_POOL_PROFILE_APP_EXIST,"[vfx_sys_mem_pool][Profile_detail][Warning] app id:%MRESOURCE_BASE_ENUM already exists but enable snapshot must be done before app launched")
    TRC_MSG(VFX_SYS_MEM_POOL_PROFILE_OVER_COUNT,"[vfx_sys_mem_pool][Profile_detail][Warning] app id:%MRESOURCE_BASE_ENUM allocation count is larger than snapshot count, do partial snapshot")

    /* Comments for VfxApp */
    TRC_MSG(VFX_APP_ON_RUN,             "[VfxApp] onRun for %d (arg=0x%X, aSize=%d)")
    TRC_MSG(VFX_APP_GROUP_ACTIVE,       "[VfxApp] groupActive for %d")
    TRC_MSG(VFX_APP_GROUP_INACTIVE,     "[VfxApp] groupInactive for %d")
    TRC_MSG(VFX_APP_GROUP_DELETE_REQ,   "[VfxApp] groupDeleteReq for %d")
    TRC_MSG(VFX_APP_GROUP_DEINIT,       "[VfxApp] groupDeinit for %d (objClosed=%d)")
    TRC_MSG(VFX_APP_ASM_FORCE_FREE,     "[VfxApp] force to free ASM for %d")
    TRC_MSG(VFX_APP_NON_HANDLED_EVT,    "[VfxApp] non handled evt in VfxApp (gid=%d, eid=%d)")
    TRC_MSG(VFX_APP_POST_DEINIT,        "[VfxApp] postDeinit for %d (ctx=0x%X, freeCtx=%d)")
    TRC_MSG(VFX_APP_POST_FREE_ASM,      "[VfxApp] postFreeASM for %d : notify stop finished")
    TRC_MSG(VFX_APP_ON_DEINIT,          "[VfxApp] onDeinit for %d (this=0x%X)")
    TRC_MSG(VFX_APP_ON_PROCESS_CLOSE,   "[VfxApp] onProcessClose for %d (option=0x%X, reason=%d, ans=%d)")
    TRC_MSG(VFX_APP_CONTINUE_CLOSE,     "[VfxApp] continueClose for %d (state=%d, ans=%d)")

    /* Comments for VfxAppScr */
    TRC_MSG(VFX_APPSCR_NEW_HNODE,       "[AppScr] new hNode in show() (sid=%d, hNode=0x%X")
    TRC_MSG(VFX_APPSCR_FREE_HNODE,      "[AppScr] free hNode when scr deinit (sid=%d, hNode=0x%X)")
    TRC_MSG(VFX_APPSCR_NON_HANDLED_EVT, "[AppScr] non handled evt in VfxAppScr (sid=%d, eid=%d)")
    TRC_MSG(VFX_APPSCR_SCR_EXIT,        "[AppScr] exit %d (isBackward=%d)")
    TRC_MSG(VFX_APPSCR_SCR_ENTRY,       "[AppScr] entry %d (isBackward=%d)")

    /* Comments for VfxMainScr & VfxPage */
    TRC_MSG(TRC_VFX_9422CABFB965418F97324C8CB6B9180C, "[VfxMainScr](%d) pushPage(%d,%x) = %d")
    TRC_MSG(TRC_VFX_AB4AADC7A02C4E6E8DAFA05CBB2D4C9C, "[VfxMainScr](%d) popPage(stack size=%d)")
    TRC_MSG(TRC_VFX_F2F1289D7BC54778A81E930AA649BFF1, "[VfxMainScr](%d) onUpdatePage(%d)")
    TRC_MSG(TRC_VFX_0BD04636765F4CDD8F462132E5BF4C3F, "[VfxMainScr](%d) onCreatePage(%d)=%x")
    TRC_MSG(TRC_VFX_07F8E0E1DDFB4716B009DAAC1E2BB9C0, "[VfxMainScr](%d) onUpdateLayout(%d)")
    TRC_MSG(TRC_VFX_8AD69028F634407F97328C5549F84EE7, "[VfxPage](%x) reposistionBars()")
    TRC_MSG(TRC_VFX_6C4AE3A674B04A868B13B105B6AC5C0B, "[VfxPage](%x) startTransition(%d,%d,%d)")
    TRC_MSG(TRC_VFX_BBD8AFE125E24BFE8F171BCC9F90E7DD, "[VfxPage](%x) onUpdate(%d)")
    TRC_MSG(TRC_VFX_F5FD630A0FA44B6990DD4AC43AE75B29, "[VfxPage](%x) adjustClient(%d,%d,%dx%d)")
    TRC_MSG(TRC_VFX_78686DE3CAF94CF59B5CB41D1B8B212E, "[VfxPage](%x):bar(%d):visible=%d,enable=%d")

    /* Comments for VfxAssetLoader */
    /* Errors */
    TRC_MSG(VFX_ASSETLOADER_DATA_ASSERT_ERROR,  "[VfxAssetLoader] (%d) %s assert error")
    /* Warnings */
    TRC_MSG(VFX_ASSETLOADER_NOT_LOADING_SCENE,  "[VfxAssetLoader] Not within loadSceneBegin/End")
    TRC_MSG(VFX_ASSETLOADER_LOAD_SCENE_REENTRY, "[VfxAssetLoader] loadSceneBegin re-entry fail")
    TRC_MSG(VFX_ASSETLOADER_INVALID_PARAMETER,  "[VfxAssetLoader] Invalid parameter")
    TRC_MSG(VFX_ASSETLOADER_GET_RESOURCE_FAIL,  "[VfxAssetLoader] Get Resource %d fail")
    TRC_MSG(VFX_ASSETLOADER_OPEN_FILE_FAIL,     "[VfxAssetLoader] Open file fail")
    TRC_MSG(VFX_ASSETLOADER_OBJECT_NOT_FOUND,   "[VfxAssetLoader] Object %s not found")
    /* Infos */
    TRC_MSG(VFX_ASSETLOADER_LOAD_MESH,          "[VfxAssetLoader] loadMesh")
    TRC_MSG(VFX_ASSETLOADER_LOAD_MATERIAL,      "[VfxAssetLoader] loadMaterial")
    TRC_MSG(VFX_ASSETLOADER_LOAD_KEYFRAME,      "[VfxAssetLoader] loadKeyframe")
    TRC_MSG(VFX_ASSETLOADER_LOAD_ANIMATION,     "[VfxAssetLoader] loadAnimation")
    TRC_MSG(VFX_ASSETLOADER_LOAD_SCENE_BEGIN,   "[VfxAssetLoader] loadSceneBegin")
    TRC_MSG(VFX_ASSETLOADER_LOAD_SCENE_END,     "[VfxAssetLoader] loadSceneEnd")
    TRC_MSG(VFX_ASSETLOADER_FIND_OBJ_BY_NAME,   "[VfxAssetLoader] findObjByName")
    TRC_MSG(VFX_ASSETLOADER_TARGET_NOT_FOUND,   "[VfxAssetLoader] Timeline target %s not found")
    TRC_MSG(VFX_ASSETLOADER_BINDING_NOT_FOUND,  "[VfxAssetLoader] Binding of variable %s not found")

    /* 
     * Add VCP component trace here
     */

    /* scrollable */
    TRC_MSG(VCP_SCROLLABLE_INFO_SCROLL_START,           "[SCROLLABLE] SCRL %x : [SCROLL] start")
    TRC_MSG(VCP_SCROLLABLE_INFO_SCROLL_STOP,            "[SCROLLABLE] SCRL %x : [SCROLL] stop, isCompleted %d")
    TRC_MSG(VCP_SCROLLABLE_INFO_SCROLL_ING,             "[SCROLLABLE] SCRL %x : [SCROLL] ing")
    TRC_MSG(VCP_SCROLLABLE_INFO_SCROLL_BOUNDS_CHANGE,   "[SCROLLABLE] SCRL %x : onViewBoundsValueChange")
    TRC_MSG(VCP_SCROLLABLE_INFO_SCROLL_TO_VISIBLE,      "[SCROLLABLE] VIEW %x : scrollRectToVisible, rect %d %d %d %d isAnimated %d")
    TRC_MSG(VCP_SCROLLABLE_INFO_PEN_DOWN,               "[SCROLLABLE] VIEW %x : [PEN DOWN] pen %d %d bo %d %d")
    TRC_MSG(VCP_SCROLLABLE_INFO_PEN_MOVE,               "[SCROLLABLE] VIEW %x : [PEN MOVE] pen %d %d bo %d %d")
    TRC_MSG(VCP_SCROLLABLE_INFO_PEN_UP,                 "[SCROLLABLE] VIEW %x : [PEN UP] pen %d %d bo %d %d")
    TRC_MSG(VCP_SCROLLABLE_INFO_STATE,                  "[SCROLLABLE] VIEW %x : STATE, track %d drag %d decel %d")  
    TRC_MSG(VCP_SCROLLABLE_INFO_STOP_BOUNDS_ANIMATION,  "[SCROLLABLE] VIEW %x : stopBoundsAnimation, bounds %d recover %d free %d")
    TRC_MSG(VCP_SCROLLABLE_INFO_CONTENT_WARNING,        "[SCROLLABLE] VIEW %x : [EMIT] warning %d %d %d %d")
    TRC_MSG(VCP_SCROLLABLE_INFO_CONTENT_ERROR,          "[SCROLLABLE] VIEW %x : [EMIT] error %d %d %d %d")
    TRC_MSG(VCP_SCROLLABLE_INFO_CONTENT_WARNING_ERROR,  "[SCROLLABLE] VIEW %x : [EMIT] warning %d %d %d %d error %d %d %d %d")
    TRC_MSG(VCP_SCROLLABLE_INFO_MONITOR_WARNING,        "[SCROLLABLE] VIEW %x : [MONITOR] %d %d %d %d warning %d %d %d %d")  
    TRC_MSG(VCP_SCROLLABLE_INFO_MONITOR_ERROR,          "[SCROLLABLE] VIEW %x : [MONITOR] %d %d %d %d error %d %d %d %d")  
    TRC_MSG(VCP_SCROLLABLE_INFO_MONITOR_WARNING_ERROR,  "[SCROLLABLE] VIEW %x : [MONITOR] %d %d %d %d warning %d %d %d %d error %d %d %d %d")      
    TRC_MSG(VCP_SCROLLABLE_INFO_SET_WARNING_RECT,       "[SCROLLABLE] VIEW %x : [SET WARNING] %d %d %d %d")  
    TRC_MSG(VCP_SCROLLABLE_INFO_SET_VALID_RECT,         "[SCROLLABLE] VIEW %x : [SET VALID] %d %d %d %d")  
    TRC_MSG(VCP_SCROLLABLE_INFO_SET_BOUNDS_AUTO_ANIM,   "[SCROLLABLE] VIEW %x : [SET BOUNDS] %d %d %d %d auto animated")
    TRC_MSG(VCP_SCROLLABLE_INFO_SET_BOUNDS_DIRECT,      "[SCROLLABLE] VIEW %x : [SET BOUNDS] %d %d %d %d direct")    
    TRC_MSG(VCP_SCROLLABLE_INFO_PEN_UP_TIMELINE,        "[SCROLLABLE] VIEW %x : ANIM, isRecover %d isFreeRun %d freeRunTime %d")
    TRC_MSG(VCP_SCROLLABLE_INFO_PEN_ABORT,              "[SCROLLABLE] VIEW %x : [PEN ABORT]")
    TRC_MSG(VCP_SCROLLABLE_INFO_MIN_INIT_SPEED,         "[SCROLLABLE] VIEW %x : Initial v=%d")
    TRC_MSG(VCP_SCROLLABLE_INFO_FRPARA_VIEW,            "[SCROLLABLE] VIEW %d/%d : v=%d a=%d s=%d t=%d")
    TRC_MSG(VCP_SCROLLABLE_SCROLL_ANIM_STOP,            "[SCROLLABLE] VIEW %x : Scroll Anim finished, track %d drag %d decel %d")  
    TRC_MSG(VCP_SCROLLABLE_DOWN_TIMER_TICK,             "[SCROLLABLE] VIEW %x : PenDownTimer tick, track %d drag %d decel %d, isFreeRun %d")  
    TRC_MSG(VCP_SCROLLABLE_DOWN_TIMER_TICK_FREERUN,     "[SCROLLABLE] VIEW %x : PenDownTimer tick for FreeRun, track %d drag %d decel %d, isFreeRun %d")  
    TRC_MSG(VCP_SCROLLABLE_MOVE_TIMER_TICK,             "[SCROLLABLE] VIEW %x : PenMoveTimer tick, track %d drag %d decel %d, isFreeRun %d")  

    /* Comments for Vcp Base Menu */
    TRC_MSG(VCP_BASEMENU_UPDATE_MSG,                "[BaseMenuLayout] update")
    TRC_MSG(VCP_BASEMENU_CLEAR_FOCUS_ITEM_MSG,      "[BaseMenuLayout] clear focus Item")
    TRC_MSG(VCP_BASEMENU_SET_FOCUS_ITEM_MSG,        "[BaseMenuLayout] set focus item (%d, %d) %d")
    TRC_MSG(VCP_BASEMENU_MAKEVISIBLE_MSG,           "[BaseMenuLayout] make cell visible (%d, %d) %d")
    
    TRC_MSG(VCP_BASEMENU_UPDATE_LAYOUT_MSG,         "[BaseMenu] update layout")
    TRC_MSG(VCP_BASEMENU_MAKE_RECT_VISIBLE_MSG,     "[BaseMenu] make rect visible (%d, %d, %d, %d) %d")
    TRC_MSG(VCP_BASEMENU_SCROLL_CONTENT_MSG,        "[BaseMenu] scroll content (%d, %d) %d")
    TRC_MSG(VCP_BASEMENU_SET_CONTENT_OFFSET_MSG,    "[BaseMenu] set content offset (%d, %d) %d")
    TRC_MSG(VCP_BASEMENU_EMIT_SCROLL_START_MSG,     "[BaseMenu] emit view scroll start")
    TRC_MSG(VCP_BASEMENU_EMIT_SCROLL_END_MSG,       "[BaseMenu] emit view scroll end")
    TRC_MSG(VCP_BASEMENU_MAKE_POS_VISIBLE_MSG,      "[BaseMenu] make pos (%d, %d) visible %d")
    TRC_MSG(VCP_BASEMENU_NEWLAYOUT_MSG,             "[BaseMenu] new layout")
    TRC_MSG(VCP_BASEMENU_RESET_INTERNAL_MSG,        "[BaseMenu] reset internal")
    TRC_MSG(VCP_BASEMENU_CREATE_CELL_MSG,           "[BaseMenu] create cell (%d, %d)")
    TRC_MSG(VCP_BASEMENU_DEL_CELL_MSG,              "[BaseMenu] delete cell (%d, %d)")
    TRC_MSG(VCP_BASEMENU_UPDATE_CELL_MSG,           "[BaseMenu] update cell (%d, %d)")
    TRC_MSG(VCP_BASEMENU_ONUPDATE_MSG,              "[BaseMenu] onUpdate")
    TRC_MSG(VCP_BASEMENU_DO_RELAYOUT_MSG,           "[BaseMenu] do re-layout")
    TRC_MSG(VCP_BASEMENU_RESET_ALL_MSG,             "[BaseMenu] reset all cell for closing")
    TRC_MSG(VCP_BASEMENU_ON_FOCUS_CHANGE_MSG,       "[BaseMenu] emit focus change (%d, %d) old:(%d, %d)")
    TRC_MSG(VCP_BASEMENU_BEFORE_SCROLL_FIX_MSG,     "[BaseMenu] before scroll fix (%d, %d)")
    TRC_MSG(VCP_BASEMENU_AFTER_SCROLL_FIX_MSG,      "[BaseMenu] after scroll fix (%d, %d)")
    TRC_MSG(VCP_BASEMENU_ON_DRAG_START_MSG,         "[BaseMenu] emit drag start")
    TRC_MSG(VCP_BASEMENU_ON_DRAG_END_MSG,           "[BaseMenu] emit drag end")
    TRC_MSG(VCP_BASEMENU_ON_DRAG_MSG,               "[BaseMenu] emit drag (%d, %d)")
    TRC_MSG(VCP_BASEMENU_EMIT_TAP_MSG,              "[BaseMenu] emit tap (%d, %d)")
    TRC_MSG(VCP_BASEMENU_EMIT_TOUCH_DM_CELL_MSG,    "[BaseMenu] emit touch down cell (%d, %d) pt (%d, %d)")
    TRC_MSG(VCP_BASEMENU_EMIT_TOUCH_UP_CELL_MSG,    "[BaseMenu] emit touch up cell (%d, %d) pt (%d, %d)")
    TRC_MSG(VCP_BASEMENU_EMIT_TOUCH_TAP_CELL_MSG,   "[BaseMenu] emit touch tap cell (%d, %d) pt (%d, %d)")
    TRC_MSG(VCP_BASEMENU_SWAP_CELL_MSG,             "[BaseMenu] swap cell(%d, %d) <--> (%d, %d)")
    TRC_MSG(VCP_BASEMENU_ON_CONTENT_WARNING_MSG,    "[BaseMenu] on content warning")
    TRC_MSG(VCP_BASEMENU_SET_VALID_CONTENT_MSG,     "[BaseMenu] set valid content (%d, %d, %d, %d)")
    TRC_MSG(VCP_BASEMENU_SET_WARNING_CONTENT_MSG,   "[BaseMenu] set warning content (%d, %d, %d, %d)")

    /* Traces for Inline Menu */
    TRC_MSG(VCP_INLINEMENU_INITIALIZED_MSG, "[InlineMenu] Menu initialized ")
    TRC_MSG(VCP_INLINEMENU_ACT_COMP_MSG, "[InlineMenu] Pending switch activity completed (cellid = %d ,success = %d)")
    TRC_MSG(VCP_INLINEMENU_CREATECELL_MSG, "[InlineMenu] Create new cell (cellid = %d, g = %d,p = %d, celltype = %d")
    TRC_MSG(VCP_INLINEMENU_UPDATE_SWITCH_MSG, "[InlineMenu] Update switch status (cellid = %d ,newStatus = %d)")
    TRC_MSG(VCP_INLINEMENU_UPDATE_OPTION_LIST_MSG, "[InlineMenu] Option list updated (cellid = %d)")
    TRC_MSG(VCP_INLINEMENU_UPDATE_SELCTD_OPTION_MSG, "[InlineMenu] New option selected (cellid = %d ,selected = %d )")
    TRC_MSG(VCP_INLINEMENU_UPDATE_ADD_OPTION_MSG, "[InlineMenu]Add more options (cellid = %d ,optionsIncreased = %d")
    TRC_MSG(VCP_INLINEMENU_SET_TOTAL_OPTIONS_MSG, "[InlineMenu] Set total options (cellid = %d,options = %d)")
    TRC_MSG(VCP_INLINEMENU_UPDATE_VISIBILITY_MSG, "[InlineMenu] Set visibility (cellid = %d, visibility = %d)")
    TRC_MSG(VCP_INLINEMENU_UPDATE_ACTIVE_STATE_MSG, "[InlineMenu] Set active state (cellid = %d ,state = %d")
    TRC_MSG(VCP_INLINEMENU_ONCELLTAP_MSG, "[InlineMenu] Cell tapped (cellid = %d)")
    TRC_MSG(VCP_INLINEMENU_RADIOLIST_LAUNCH_MSG, "[InlineMenu] Launch radio list (cellid = %d)")
    TRC_MSG(VCP_INLINEMENU_SUSPEND_MSG, "[InlineMenu] Menu suspended") 
    TRC_MSG(VCP_INLINEMENU_RESUME_MSG, "[InlineMenu] Menu resumed")     
    TRC_MSG(VCP_INLINEMENU_ONCELLTAP_EMIT, "[InlineMenu] Emitting Cell-tapped signal for cellid: %d")
    TRC_MSG(VCP_INLINEMENU_CELLBASE_PEN_EVENT, "[InlineMenu] Base cell got pen event: %d")
    TRC_MSG(VCP_INLINEMENU_CELLBTN_PEN_EVENT, "[InlineMenu] Button cell got pen event: %d")
    TRC_MSG(VCP_INLINEMENU_CELLRADIO_PEN_EVENT, "[InlineMenu] Radio list cell got pen event: %d")

    /* Trace for VcpAsyncImageFrame */
    TRC_MSG(VCP_ASYNC_IMAGE_FRAME_CREATE_BUFF_BY_APP,    "[AsyncImageFrame] create buff by app = 0x%x")
    TRC_MSG(VCP_ASYNC_IMAGE_FRAME_CREATE_BUFF,           "[AsyncImageFrame] create buff = 0x%x")
    TRC_MSG(VCP_ASYNC_IMAGE_FRAME_LOAD_IMAGE,            "[AsyncImageFrame] load image handle = %d, layer = %x, buff = 0x%x")
    TRC_MSG(VCP_ASYNC_IMAGE_FRAME_DEINIT,                "[AsyncImageFrame] deinit handle = %d, layer = 0x%x, buff = 0x%x")
    TRC_MSG(VCP_ASYNC_IMAGE_FRAME_ERROR,                 "[AsyncImageFrame] decode result = %d, layer = 0x%x, buff = 0x%x")

    /* Trace for VcpGlobalPopup */
    TRC_MSG(VCP_GLOBAL_POPUP_SHOW_CONFIRM_ID_MSG,        "[VcpGlobalPopup] confirm 2 id = %d")
    TRC_MSG(VCP_GLOBAL_POPUP_SHOW_CONFIRM_STR_MSG,       "[VcpGlobalPopup] confirm 2 str = %d")
    TRC_MSG(VCP_GLOBAL_POPUP_CONFIRM_ENTRY_MSG,          "[VcpGlobalPopup] confirm entry = %d")
    TRC_MSG(VCP_GLOBAL_POPUP_CONFIRM_LEAVE_MSG,          "[VcpGlobalPopup] leave")
    TRC_MSG(VCP_GLOBAL_POPUP_CONFIRM_DEINIT_MSG,         "[VcpGlobalPopup] confirm Deinit")

    TRC_MSG(VCP_GLOBAL_POPUP_CREATE_COMMAND_ID_MSG,      "[VcpGlobalPopup] command create id = %d")
    TRC_MSG(VCP_GLOBAL_POPUP_ADD_COMMAND_ID_MSG,         "[VcpGlobalPopup] command add id = %d")
    TRC_MSG(VCP_GLOBAL_POPUP_SHOW_COMMAND_ID_MSG,        "[VcpGlobalPopup] command show id = %d")
    TRC_MSG(VCP_GLOBAL_POPUP_CREATE_COMMAND_STR_MSG,     "[VcpGlobalPopup] command create str = %d")
    TRC_MSG(VCP_GLOBAL_POPUP_ADD_COMMAND_STR_MSG,        "[VcpGlobalPopup] command add str = %d")
    TRC_MSG(VCP_GLOBAL_POPUP_SHOW_COMMAND_STR_MSG,       "[VcpGlobalPopup] command show str = %d")
    TRC_MSG(VCP_GLOBAL_POPUP_COMMAND_ENTRY_MSG,          "[VcpGlobalPopup] command entry = %d")
    TRC_MSG(VCP_GLOBAL_POPUP_COMMAND_DEINIT_MSG,         "[VcpGlobalPopup] command Deinit")

    TRC_MSG(VCP_GLOBAL_POPUP_ALLOCATE_MSG,               "[VcpGlobalPopup] allocate = %08x")
    TRC_MSG(VCP_GLOBAL_POPUP_FREE_MSG,                   "[VcpGlobalPopup] free = %08x")
    
    /* Trace for Slider */
    TRC_MSG(VCP_SLIDER_THUMB_PEN_INPUT, "[VcpSlider] Got pen input: %d at position %d")
    TRC_MSG(VCP_SLIDER_THUMB_EMITTING_PEN_DOWN, "[VcpSlider] Emitting pen down event")
    TRC_MSG(VCP_SLIDER_THUMB_PEN_VALUE_UPDATE, "[VcpSlider] Updated value from oldValue(%d) to newValue(%d)")
    TRC_MSG(VCP_SLIDER_THUMB_SIGNAL_SKIP_DISCRETE, "[VcpSlider] Discrete mode, difference not significant. ")
    TRC_MSG(VCP_SLIDER_THUMB_EMITTING_PEN_MOVE, "[VcpSlider] Emitting pen-move event with Value = %d")
    TRC_MSG(VCP_SLIDER_THUMB_EMITTING_PEN_UP, "[VcpSlider] Emitting pen-up with final value = %d")
    TRC_MSG(VCP_SLIDER_SET_VALUE_INPUT, "[VcpSlider] Setting new Value. Max = %d, Input value = %d, Min = %d")
    TRC_MSG(VCP_SLIDER_SET_VALUE_ROUNDED, "[VcpSlider] Setting new Value. Rounded to %d for discrete mode")
    TRC_MSG(VCP_SLIDER_SET_VALUE_FINALIZED, "[VcpSlider] Setting new Value. Value finalized to %d")
    TRC_MSG(VCP_SLIDER_SET_VALUE_POSITION_FINALIZED, "[VcpSlider] Setting new Value. Position finalized to %d")
    TRC_MSG(VCP_SLIDER_DISCRETE_MODE_SETTING, "[VcpSlider] Total discrete steps = %d, Unit step = %d")
    TRC_MSG(VCP_SLIDER_SET_LENGTH, "[VcpSlider] Set length = %d")

    /* Trace for Menu popup */
    TRC_MSG(VCP_MENUPOPUP_EMIT_CANCEL, "[VcpMenuPopup] Tapped outside..Emitting cancel ")
    TRC_MSG(VCP_MENUPOPUP_EMIT_CLOSE, "[VcpMenuPopup] Closing")
    TRC_MSG(VCP_MENUPOPUP_EXIT, "[VcpMenuPopup] onExit")
    TRC_MSG(VCP_MENUPOPUP_ENTER, "[VcpMenuPopup] onEnter ")
    TRC_MSG(VCP_MENUPOPUP_EMIT_CANCEL_FROM_BACKKEY,"[VcpMenuPopup] Back key pressed..Emitting cancel")
    TRC_MSG(VCP_MENUPOPUP_EMIT_ITEM_SELECTED, "[VcpMenuPopup] Selected item : %d")
    TRC_MSG(VCP_MENUPOPUP_NEW_TEM_INSERTED, "[VcpMenuPopup] Inserted new item %d")

    /* Trace for text editor/view */
    TRC_MSG(VCP_TEXT_STORAGE_INSERT_TEXT,          "[VcpTextEditor] insert text, affect range start = %d, end = %d ")
    TRC_MSG(VCP_TEXT_LAYOUT_UPDATE_ICON,           "[VcpTextEditor] updateFormatForIcon, start = %d, end = %d, time = %d")
    TRC_MSG(VCP_TEXT_LAYOUT_GET_TEXT_METRICS,      "[VcpTextEditor] layout getTextMetrics, time1 = %d, time2 = %d, time = %d")
    TRC_MSG(VCP_TEXT_LAYOUT_RANGE,                 "[VcpTextEditor] layout range, start = %d, end = %d, dirty start = %d, dirty end = %d")
    TRC_MSG(VCP_TEXT_LAYOUT_TIME,                  "[VcpTextEditor] layout time, time1 = %d, time2 = %d, time3 = %d, time4 = %d")    
    TRC_MSG(VCP_TEXT_LAYOUT_TIME_DETAIL,           "[VcpTextEditor] layout time detail, total time = %d, loop time = %d, notify time = %d")
    TRC_MSG(VCP_TEXT_CLIPBOARD_PASTE,              "[VcpTextEditor] clipboard paste len = %d, ret len = %d, time = %d")

    /* Trace for SSE */
    TRC_MSG(VCP_SSE_BUILD_OLD_SCREEN_MSG,        "[VcpSse] build old screen")
    TRC_MSG(VCP_SSE_BUILD_NEW_SCREEN_MSG,       "[VcpSse] build new screen")
    TRC_MSG(VCP_SSE_RUN_SSE_MSG,          "[VcpSse] run sse")
    TRC_MSG(VCP_SSE_FINISH_SSE_MSG,          "[VcpSse] finish sse")
    TRC_MSG(VCP_SSE_SETUP_SCENARIO_MSG,         "[VcpSse] setup scenario = %d")
    TRC_MSG(VCP_SSE_SETUP_SCENARIO_2_MSG,         "[VcpSse] setup 2 scenario = %d")
    TRC_MSG(VCP_SSE_OUT_OF_MEMORY_MSG,         "[VcpSse] out of memory for vrt")
    TRC_MSG(VCP_SSE_OUT_OF_MEMORY_3D_MSG,         "[VcpSse] out of memory for 3D")

	/* Trace for Form */
	TRC_MSG(VCP_FORM_CHANGE_VIEW_BOUNDS, 			"[VcpForm] [onBoundsChange] Width = %d, Height = %d")
	TRC_MSG(VCP_FORM_ADJUST_VIEW,				"[VcpForm] [adjustContentOffsetPosition] contentHeight = %d, viewOrigin = %d, viewHeight = %d")
	TRC_MSG(VCP_FORM_ADJUST_VIEW_TO,			"[VcpForm] [adjustContentOffsetPosition] Scrolling to new y origin %d")
	TRC_MSG(VCP_FORM_INSERT_ITEM_CALLED, 			"[VcpForm] [insertItem] itemId = %d, ReferenceId = %d, addBeforeRefId = %d")
	TRC_MSG(VCP_FORM_INSERT_ITEM_ENDS, 			"[VcpForm] [insertItem] itemId = %d, m_itemCount = %d, m_formHeight = %d")
	TRC_MSG(VCP_FORM_REMOVE_ITEM_CALLED, 			"[VcpForm] [removeItem] itemId = %d")                        
	TRC_MSG(VCP_FORM_REMOVE_ITEM_ENDS, 			"[VcpForm] [removeItem] itemId = %d, m_itemCount = %d, m_formHeight = %d")
	TRC_MSG(VCP_FORM_ON_ITEM_HEIGHT_CHNG, 		        "[VcpForm] [onItemHeightChange] id = %d, m_formHeight = %d")
	TRC_MSG(VCP_FORM_SCROLL_TO_VIEW_REQ, 			"[VcpForm] [scrollItemToView] id = %d, target pos = %d, current item_y = %d, item_height = %d, formHeight = %d ")
	TRC_MSG(VCP_FORM_SCROLL_TO_VIEW_ENDS, 			"[VcpForm] [scrollItemToView] id = %d, finalYOffset = %d")
	TRC_MSG(VCP_FORM_ITEM_SET_HEIGHT, 			"[VcpForm] [setHeight] id = %d, old height = %d , new height = %d")
	TRC_MSG(VCP_FORM_ITEM_DISABLED, 			"[VcpForm] [setIsDisabled] id = %d, isDisabled = %d")
	TRC_MSG(VCP_FORM_ITEM_HIDDEN, 				"[VcpForm] [setIsHidden] id = %d, m_isHidden = %d")
	TRC_MSG(VCP_FORM_ITEM_HAS_SEPARATOR, 			"[VcpForm] [setHasSeparator] id = %d, has separator = %d")
	
	/*VfxShelter*/
	TRC_MSG(VFX_SHELTER_INIT_RESOURCE_START,	    "[SHELTER] [RES INI] %x Start: HPO %d HFB %d HTB %d VPO %d")	 
	TRC_MSG(VFX_SHELTER_INIT_RESOURCE_END,		    "[SHELTER] [RES INI] %x   End: HPO %d HFB %d HTB %d VPO %d")	 
	TRC_MSG(VFX_SHELTER_DEINIT_RESOURCE_START,	    "[SHELTER] [RES DIN] %x Start: HPO %d HFB %d HTB %d VPO %d")	 
	TRC_MSG(VFX_SHELTER_DEINIT_RESOURCE_END,		"[SHELTER] [RES DIN] %x   End: HPO %d HFB %d HTB %d VPO %d")	 
	TRC_MSG(VFX_SHELTER_FIRST_COPY,    		        "[SHELTER] [COPY] %x First: HTI %d")	 
	TRC_MSG(VFX_SHELTER_FORCE_COPY,		            "[SHELTER] [COPY] %x Force: HTI %d")	 
	TRC_MSG(VFX_SHELTER_FRAME_EFFECT_SHOW,		    "[SHELTER] [FE] %x SHOW")	 
	TRC_MSG(VFX_SHELTER_FRAME_EFFECT_HIDE,		    "[SHELTER] [FE] %x HIDE")	 	
	TRC_MSG(VFX_SHELTER_OWNER_DRAW_SHOW_V,	        "[SHELTER] [OD] %x SHOW V: %x")	 
	TRC_MSG(VFX_SHELTER_OWNER_DRAW_SHOW_H,	        "[SHELTER] [OD] %x SHOW H: %x")	 
	TRC_MSG(VFX_SHELTER_OWNER_DRAW_SET_V,	        "[SHELTER] [OD] %x SET V: %x")	 
	TRC_MSG(VFX_SHELTER_OWNER_DRAW_SET_H,	        "[SHELTER] [OD] %x SET H: %x")	 

    /* 
     * Add VPI engine trace here
     */

    TRC_MSG(VPI_APP_LAUNCHER_LOAD,                  "[VpiAppLauncher] loadLibrary()")
    TRC_MSG(VPI_APP_LAUNCHER_LOADED,                "[VpiAppLauncher] loadLibrary(): handle = %x")
    TRC_MSG(VPI_APP_LAUNCHER_LAUNCH,                "[VpiAppLauncher] launch(): parent = %x")
    TRC_MSG(VPI_APP_LAUNCHER_LAUNCH_WITH_CTX,       "[VpiAppLauncher] launch(): context = %x, parent = %x")
    TRC_MSG(VPI_APP_LAUNCHER_LAUNCH_WITH_MEM,       "[VpiAppLauncher] launch(): buf = %x, size = %d, parent = %x")
    TRC_MSG(VPI_APP_LAUNCHER_LAUNCH_INTERNAL,       "[VpiAppLauncher] launchInternal(): handle = %x")
    TRC_MSG(VPI_APP_LAUNCHER_LAUNCH_MSG,            "[VpiAppLauncher] msgProcPtr(): VPI_MSG_LAUNCH, handle = %x, context = %x, objFactory = %x, parent = %x")
    TRC_MSG(VPI_APP_LAUNCHER_TERMINATE,             "[VpiAppLauncher] terminate(): handle = %x")
    TRC_MSG(VPI_APP_LAUNCHER_TERMINATE_MSG,         "[VpiAppLauncher] msgProcPtr(): VPI_MSG_TERMINATE, handle = %x")
    TRC_MSG(VPI_APP_LAUNCHER_RELEASE,               "[VpiAppLauncher] release(): handle = %x")
    TRC_MSG(VPI_OBJECT_FACTORY_CREATE,              "[VpiObjectFactory] createObject(): handle = %x, iid = %d, object = %x, vfxObject = %x, delegator = %x, context = %x, parent = %x")
    TRC_MSG(VPI_OBJECT_CLOSE,                       "[VpiObject] close(): handle = %x, vfxObject = %x")
    TRC_MSG(VPI_BASE_PROXY_CMD_REGISTER,            "[VpiBaseProxy] registerCmdHandler(): handle = %x, cmdId = %d")
    TRC_MSG(VPI_BASE_PROXY_CMD_UNREGISTER,          "[VpiBaseProxy] unregisterCmdHandler(): handle = %x, cmdId = %d")
    TRC_MSG(VPI_BASE_PROXY_CMD_UNREGISTER_ALL,      "[VpiBaseProxy] unregisterAllCmdHandler(): handle = %x")
    TRC_MSG(VPI_BASE_PROXY_CMD_PROCESS,             "[VpiBaseProxy] processCmd(): handle = %x, sender = %x, cmdId = %d, args = (%x %x %x %x)")

END_TRACE_MAP(MOD_VFX)

#ifdef __cplusplus
}
#endif

#endif /* __VADP_SYS_TRC_H__ */

