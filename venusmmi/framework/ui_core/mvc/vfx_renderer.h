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
 *  vfx_renderer.h
 *
 * Project:
 * --------
 *  Venus UI Core
 *
 * Description:
 * ------------
 *  Venus UI Engine Renderer
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef __VFX_RENDERER_H__
#define __VFX_RENDERER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

// For VfxObject
#include "vfx_object.h"

#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_weak_ptr.h"
#include "vfx_object_list.h"
#include "vfx_draw_context.h" 


/***************************************************************************** 
 * Define
 *****************************************************************************/
 
// The VfxRenderer registered name
#define VFX_RENDERER_CLASS_NAME        "Renderer"


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
// Pre-defined class
class VfxFrame;
class VfxDrawContext;

#ifdef __VENUS_3D_UI_ENGINE__
class VfxNode;
class VfxPass;
class VfxMesh;
class VfxMaterial;
#endif

/*
 * Internal used. It should only be changed by framework.
 */
enum VfxRendererStateEnum
{
    VFX_RENDERER_STATE_UNKNOWN = 0,
    VFX_RENDERER_STATE_STARTUP,     // Startup
    VFX_RENDERER_STATE_SHUTDOWN,    // Shutdown
    VFX_RENDERER_STATE_COMMIT,      // Commiting
    VFX_RENDERER_STATE_END_OF_ENUM
};


enum VfxRendererCommitActionEnum
{
    VFX_RENDERER_COMMIT_ACTION_KEEP = 0,
    VFX_RENDERER_COMMIT_ACTION_FORCE_SUSPEND,
    VFX_RENDERER_COMMIT_ACTION_FORCE_RESUME,
    VFX_RENDERER_COMMIT_ACTION_END_OF_ENUM
};


struct VfxRendererProfilingData : public VfxBase
{
    VfxRendererProfilingData() :
        commitTime(0),
        prepareHandleTime(0),
        prepareSceneGraphTime(0),
        isBlocking(VFX_FALSE),
        hasDebugPanelUpdate(VFX_FALSE),
        hasPlutoControl(VFX_FALSE)
    {
    }

    VfxMsec commitTime;
    VfxMsec prepareHandleTime;
    VfxMsec prepareSceneGraphTime;
    VfxBool isBlocking;
    VfxBool hasDebugPanelUpdate;
    VfxBool hasPlutoControl;
};


/***************************************************************************** 
 * Class VfxRendererProfiling
 *****************************************************************************/

class VfxRendererProfiling
{
public:
    static void setHasDebugPanelUpdate();
    static void setHasPlutoControl();
    
    static void reset();
    static void addData(const VfxRendererProfilingData &data);
    static VfxU32 getCount();
    static const VfxRendererProfilingData &getData(VfxU32 index);

private:
    enum
    {
        DATA_MAX_COUNT = 5
    };

    static VfxBool s_hasDebugPanelUpdate;
    static VfxBool s_hasPlutoControl;
    static VfxRendererProfilingData s_data[DATA_MAX_COUNT];
    static VfxU32 s_dataCount;
};


/***************************************************************************** 
 * Class VfxRenderer
 *****************************************************************************/

/*
 * Internal Used. VfxRenderer is a singleton class, maintains the frame tree.
 */
class VfxRenderer : public VfxObject
{
    VFX_DECLARE_CLASS(VfxRenderer);    
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VfxRenderer);

// Constructor / Destructor
public:
    // Default constructor
    VfxRenderer();

// Method
public:
    // Return the root frame of renderer.
    //
    // RETURNS: The root frame of renderer. Return NULL if the frame tree is empty.
    VfxFrame *getRootFrame() const
    {
        return m_rootFramePtr.get();
    }

    // Set the root frame of renderer.
    //
    // NOTE: The given frame can be NULL.
    void setRootFrame(
        VfxFrame *frame             // [IN] The frame to set as root frame.
    );

    void pushRootFrame(
        VfxFrame *frame             // [IN] The frame to set as root frame.
    );

    void popRootFrame();

// ***Experimental method
public:
    // Pause all animation image
    // 
    // SEE ALSO: resumeAllImgAnim
    void pauseAllImgAnim(VfxObject *requester);
    // Resume all animation image
    //
    // SEE ALSO: pauseAllImgAnim
    void resumeAllImgAnim(VfxObject *requester);

    // Mark the next frame must be displayed. For example, 
    //  the 100% state of a music play.
    //
    // NOTE: Only use the method on necessary case, 
    //  or it will descease the performance.
    void mustShowNextFrame();

    // Internal use.
    //  Mark the next frame must be blocked until VRT render finished
    void waitDrawFinishNextFrame();

    // MMI will blocking a given time until VRT rendering finished, 
    //  and callback.
    void blockAfterNextCommit(
        VfxMsec waitTime,                           // the time to blockAfterNextCommit
        VfxCallback0 callback = VFX_CALLBACK_NULL   // the callback after time up
    );

    // Cancel the callback set by blockAfterNextCommit()
    void removeBlockAfterNextCommitCallback(
        VfxCallback0 callback   // the callback after time up
    );

    // MMI will blocking on leaving screen
    void mustShowTime(
        VfxMsec relTime     // the relative important time
    );

// Framework method
public:
    // Internal used.
    void startup();
    
    // Internal used.
    void shutdown();

    // Internal used.
    void beforeSleepIn();
    
    // Internal used.
    void afterSleepIn();

    // Internal used.
    void beforeSleepOut();
    
    // Internal used.
    void afterSleepOut();
    
    // Internal used.
    void suspendUntilCommit();

    // Internal used.
    void waitForRenderingComplete();

    // Internal used.
    VfxBool needCommitSoon() const;

    // Internal used.
    // RETURNS: the time commit scene graph
    VfxMsec updateScene(VfxBool commitToVrt, VfxRendererCommitActionEnum commiotAction);

    // Internal used.
    void processBlockNextCommit(VfxMsec currentTime);

    // Internal used.
    void processMustShowTime();

    // Return the current LCD screen rotate type
    //
    // RETURNS: The current LCD screen rotate type
    VfxScrRotateTypeEnum getScreenRotateType() const;

    // Return the previous LCD screen rotate type
    //
    // RETURNS: The previous LCD screen rotate type
    VfxScrRotateTypeEnum getPreScreenRotateType() const;

    // Set the LCD screen rotate type
    void setScreenRotateType(
        VfxScrRotateTypeEnum type // The rotate type to set
    );

    VfxBool snapshot(VfxImageBuffer &snapshotBuffer);

    // For debugging. Dump full frame tree information on MoDIS terminal.
    void debugDump() const;

// Singal
public:
    // This signal will be invoked whenever backlight is on or off.
    // Argument is VFX_TRUE if the backlight is on.
    VfxSignal1 <VfxBool> m_signalBacklightSwitch;
    // TODO: this signal will be merge to m_signalBacklightSwitch
    // This signal will be invoked whenever backlight is on or off.
    // Argument is VFX_TRUE if the backlight is on.
    // It will emit before backlight on and after backlight off.
    VfxSignal1 <VfxBool> m_signalBacklightSwitch2;

// Override
protected:
    virtual vrt_allocator_handle getAllocator();

// Implementation
private:
    friend class VfxFrame;

    VfxRendererStateEnum m_state;
    VfxBool m_isSuspendUntilCommit;
    VfxBool m_isSuspendByRenderer;

    // Pointer to the root frame
    VfxWeakPtr <VfxFrame> m_rootFramePtr;
    VfxWeakPtr <VfxFrame> m_stackFramePtr;
    
    // The next frame must be displayed
    VfxBool m_mustShowNextFrame;
    VfxBool m_waitDrawFinishNextFrame;

    VfxObjList m_nullParentFrameList;

    VfxObjList m_pauseAllImgAnimRequesters;

    // The time to blocking after next commit
    VfxMsec m_blockAfterNextCommitTime;
    VfxSlotList m_blockAfterNextCommitCallbackList;

    // Must show time to apply after next commit
    VfxMsec m_mustShowTime;
    // Must show time will be blocking on leaving canvas
    VfxBool m_mustShowTimeEnabled;
    VfxMsec m_mustShowAbsTime;
    
    VfxMsec m_preCommitTime;

    void addToNullParentFrameList(VfxFrame *frame);
    void removeFromNullParentFrameList(VfxFrame *frame);
    
    // Check whether we need to invoke event at this moments
    void setBacklightState(
        VfxBool on  // [IN] VFX_TRUE if the backlight is on
    );

    void drawRootFrame(VfxDrawContext &dc);
    static void drawFrame(VfxDrawContext &dc, VfxFrame *frame);    
    
    static void debugDumpFrame(const VfxFrame *frame, VfxU32 level);
    static void debugDumpFrameDummy(void);
#ifdef __VENUS_3D_UI_ENGINE__
    static void debugDumpNode(const VfxNode *node, VfxU32 level);
    static void debugDumpMesh(const VfxMesh *mesh, VfxU32 level);
    static void debugDumpMaterial(const VfxMaterial *mat, VfxU32 idx, VfxU32 level);
    static void debugDumpPass(const VfxPass *pass, VfxU32 idx, VfxU32 level);
#endif
};

#endif /* __VFX_FRAME_H__ */

