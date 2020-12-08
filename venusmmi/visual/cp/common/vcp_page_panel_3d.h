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
 *  vcp_page_panel_3d.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  Provide a mechanism to transit from a frame to another frame with specific
 *  effect.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_PAGE_PANEL_3D_H__
#define __VCP_PAGE_PANEL_3D_H__

#if defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__)


/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vcp_page_panel.h"
#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_transform.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vfx_object.h"
#include "vfx_signal.h"
#include "vfx_control.h"
#include "vfx_class_info.h"
#include "vfx_weak_ptr.h"
#include "vfx_animation.h"

#include "vcp_frame_effect.h"


#include "vfx_world.h"
#include "vfx_camera.h"
#include "vfx_light.h"
#include "vfx_mesh.h"
#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_polygon_mode.h"
#include "vfx_compositing_mode.h"
#include "vfx_blender.h"
#include "vfx_stencil.h"
#include "vfx_shader.h"
#include "vfx_shader_uniforms.h"
#include "vfx_render_buffer.h"
#include "vfx_render_target.h"
#include "vfx_texture.h"
#include "vfx_asset_loader.h"


/*****************************************************************************
 * Class VcpPage3DCircle
 *
 *  support direction:
 *  default direction:
 *  default duration:
 *  affect property:
 *  parameter:
 *****************************************************************************/
class VcpPage3DCircleEffect : public VcpPageBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Constructor/Destructor>
    // Default constructor
    VcpPage3DCircleEffect(); 

// Override
protected:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onStart(
        VcpPagePanel *pagePanel, 
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
// Variable
private:
    VfxFrameHintsEnum m_backupHint[2];
    VfxMaterial *m_material;
	VfxFloatTimeline *m_fpeTimeline;
    VfxFloatTimeline *m_filterTimeline;
    VfxFrame *m_3dframe;
// Implementation
private:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
    void setupMaterial(VfxS32 index, VfxFrame *frame1, VfxFrame *frame2, VfxS32 width, VfxS32 height);
    void setupMaterialByImageSrc(VfxS32 index, VfxImageSrc& frame1ImgSrc, VfxImageSrc& frame2ImgSrc, VfxS32 width, VfxS32 height);
};


/*****************************************************************************
 * Class VcpPage3DCubeFlyOutEffect
 *
 *  support direction:
 *  default direction:
 *  default duration:
 *  affect property:
 *  parameter:
 *****************************************************************************/
class VcpPage3DCubeFlyOutEffect : public VcpPageBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Constructor/Destructor>
    // Default constructor
    VcpPage3DCubeFlyOutEffect(); 

// Override
protected:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onStart(
        VcpPagePanel *pagePanel, 
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
// Variable
private:
    VfxFloatTimeline *m_mainTimeline;
    VfxFrame *m_3dframe;
    VfxFrame *m_tempFrame;
    VfxWorld *m_world;
    VfxFrameHintsEnum m_backupHint[2];
// Implementation
private:
    void setupBox(const VfxString &name, VfxFrame *frameTexture, VfxS32 rIndex, VfxS32 cIndex);
    void setupBoxByImageSrc(const VfxString &name, VfxImageSrc &frameTexture, VfxS32 rIndex, VfxS32 cIndex);
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
};

/*****************************************************************************
 * Class VcpPage3DBlindsEffect
 *
 *  support direction:
 *  default direction:
 *  default duration:
 *  affect property:
 *  parameter:
 *****************************************************************************/
class VcpPage3DBlindsEffect : public VcpPageBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Constructor/Destructor>
    // Default constructor
    VcpPage3DBlindsEffect(); 

// Override
protected:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onStart(
        VcpPagePanel *pagePanel, 
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
// Variable
private:
    VfxFloatTimeline *m_mainTimeline;
    VfxFrame *m_3dframe;
    VfxWorld *m_world;
    VfxFrameHintsEnum m_backupHint[2];
// Implementation
private:
    void setupBox(const VfxString &name, VfxFrame *frameTexture1, VfxFrame *frameTexture2);
    void setupBoxByImageSrc(const VfxString &name, VfxImageSrc& frameTexture1, VfxImageSrc& frameTexture2);
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
};


/*****************************************************************************
 * Class VcpPage3DBrickFlipEffect
 *
 *  support direction:
 *  default direction:
 *  default duration:
 *  affect property:
 *  parameter:
 *****************************************************************************/
class VcpPage3DBrickFlipEffect : public VcpPageBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Constructor/Destructor>
    // Default constructor
    VcpPage3DBrickFlipEffect(); 

// Override
protected:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onStart(
        VcpPagePanel *pagePanel, 
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
// Variable
private:
    VfxFloatTimeline *m_mainTimeline;
    VfxFrame *m_3dframe;
    VfxWorld *m_world;
    VfxFrameHintsEnum m_backupHint[2];
    VfxShaderProgram *m_program1; 
    VfxShaderProgram *m_program2; 
    VfxBool m_isFirst;
// Implementation
private:
    void setupBox(const VfxString &name, VfxFrame *frameTexture1, VfxFrame *frameTexture2, VfxBool isRotate);
    void setupBoxByImageSrc(const VfxString &name, VfxImageSrc& frameTexture1, VfxImageSrc& frameTexture2, VfxBool isRotate);
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
};


/*****************************************************************************
 * Class VcpPage3DBrickFlipEffect
 *
 *  support direction:
 *  default direction:
 *  default duration:
 *  affect property:
 *  parameter:
 *****************************************************************************/
class VcpPage3DTwistEffect : public VcpPageBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Constructor/Destructor>
    // Default constructor
    VcpPage3DTwistEffect(); 

// Override
protected:
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onStart(
        VcpPagePanel *pagePanel, 
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Override>
    virtual void onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
// Variable
private:
    VfxFloatTimeline *m_mainTimeline;
    VfxFrame *m_3dframe;
    VfxWorld *m_world;
    VfxFrameHintsEnum m_backupHint[2];
// Implementation
private:
    void setupBox(const VfxString &name, VfxFrame *frameTexture1, VfxFrame *frameTexture2, VfxBool isRotate);
    void setupBoxByImageSrc(const VfxString &name, VfxImageSrc& frameTexture1, VfxImageSrc& frameTexture2, VfxBool isRotate);
    // <group DOM_PagePanel_VcpPageFlipOutFlipInEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
};

/*****************************************************************************
 * Class VcpPage3DCurlEffect
 *  VcpPageFadeInEffect provide a Fade-in effect between frames.
 *
 *  support direction:
 *  default direction:
 *  default duration:
 *  affect property:
 *  parameter:
 *****************************************************************************/
class VcpPage3DCurlEffect : public VcpPageBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_PagePanel_VcpPageFadeInEffect_Constructor/Destructor>
    // Default constructor
    VcpPage3DCurlEffect(); 

// Override
public:
    // <group DOM_PagePanel_VcpPageFadeInEffect_Override>
    virtual void onStart(
        VcpPagePanel *pagePanel,
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_PagePanel_VcpPageFadeInEffect_Override>
    virtual void onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
    // <group DOM_PagePanel_VcpPageFadeInEffect_Override>
    virtual void onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
// Variable
private:
    // <group DOM_PagePanel_VcpPageFadeInEffect_Variable>
    VfxFloatTimeline *m_leftPageCurlThetaTl;
    VfxFloatTimeline *m_rightPageCurlThetaTl;
    VfxFloatTimeline *m_leftPageCurlRhoTl;
    VfxFloatTimeline *m_rightPageCurlRhoTl;

    VfxFrame *m_leftFrame;
    VfxFrame *m_rightFrame;
    VfxWeakPtr <VfxFrame> m_target;
    VfxFrameHintsEnum m_backupHint;
 
    
// Implementation
private:
    // <group DOM_PagePanel_VcpPageFadeInEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
};


/*****************************************************************************
 * Class VcpPage3DFusionEffect
 *  VcpPage3DFusionEffect provide one frame fusion into another frame 
 *  with an alpha mask
 *
 *  support direction:
 *      VCP_PAGE_DIRECTION_FROM_NONE
 *  default direction:
 *      VCP_PAGE_DIRECTION_FROM_NONE
 *  default duration:
 *      1000
 *  affect property:
 *      Opacity
 *  parameter:
 *      None  
 *****************************************************************************/
class VcpPage3DFusionEffect : public VcpPageBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_PagePanel_VcpPage3DFusionEffect_Constructor/Destructor>
    // Default constructor
    VcpPage3DFusionEffect(); 

// Override
protected:
    // <group DOM_PagePanel_VcpPage3DFusionEffect_Override>
    virtual void onStart(
        VcpPagePanel *pagePanel, 
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_PagePanel_VcpPage3DFusionEffect_Override>
    virtual void onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
    // <group DOM_PagePanel_VcpPage3DFusionEffect_Override>
    virtual void onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
// Variable
private:
    // <group DOM_PagePanel_VcpPage3DFusionEffect_Variable>
    VfxFloatTimeline *m_animTimeline;
    VfxFrame *m_effectFrame;
    VfxFrameHintsEnum m_backupHint[2];

// Implementation
private:
    // <group DOM_PagePanel_VcpPage3DFusionEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
};


class VfxMaterial;

/*****************************************************************************
 * Class VcpPage3DRippleEffect
 *  VcpPageFadeInEffect provide a Fade-in effect between frames.
 *
 *  support direction:
 *  default direction:
 *  default duration:
 *  affect property:
 *  parameter:
 *****************************************************************************/
class VcpPage3DRippleEffect : public VcpPageBaseEffect
{
// Constructor / Destructor
public:
    VcpPage3DRippleEffect(); 

// Override
protected:
    virtual void onStart(
        VcpPagePanel *pagePanel, 
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        );

    virtual void onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
    virtual void onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame);
private:
    const static VfxS32 RIPPLE_DURATION = 1500;
    VfxMaterial * m_material;
    VfxU32 m_imageBuffer[1];
    VfxFrameHintsEnum m_backupHint[2];

    VfxFloatTimeline * m_transTimeline;
    VfxFloatTimeline * m_rippleTimeline;
    VfxFloatTimeline * m_zTimeline;
    VfxMaterial * createRippleMaterial(VfxFrame * target, VfxFrame * frameTexture);
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
};

#endif /* defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__) */
#endif /* __VCP_PAGE_H__ */

