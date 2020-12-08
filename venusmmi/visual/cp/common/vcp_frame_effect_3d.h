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
 *  vcp_frame_effect_3d.h
 *
 * Project:
 * --------
 *  Venus UI Component
 *
 * Description:
 * ------------
 *  Venus frame effect Component
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef __VCP_FRAME_EFFECT_3D_H__
#define __VCP_FRAME_EFFECT_3D_H__

#ifdef __COSMOS_3D_V10__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_frame_effect_type.h"
#include "vcp_frame_effect.h"
#include "vfx_object.h"
#include "vfx_frame.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_signal.h"
#include "vfx_weak_ptr.h"
#include "vfx_animation.h"
#include "vfx_basic_type.h"
#include "vfx_frame_filter.h"
#include "vfx_image_src.h"

#include "vfx_material.h"

/*****************************************************************************
 * Class Vcp3DCircleEffect
 *
 *  support direction:  
 *  default direction:
 *  default duration:
 *  affect property:
 *  parameter:
 *****************************************************************************/
class Vcp3DCircleEffect : public VcpBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_FrameEffect_VcpTransformerEffect_Constructor/Destructor>
    // Default constructor
    Vcp3DCircleEffect(); 

// Override
public:
    // <group DOM_FrameEffect_VcpTransformerEffect_Override>
    virtual void onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        );
    // <group DOM_FrameEffect_VcpTransformerEffect_Override>
    virtual void restore(VfxFrame *activeFrame);
    
// Variable
private:
    VfxMaterial *m_material;
	VfxFloatTimeline *m_fpeTimeline;
    VfxFloatTimeline *m_filterTimeline;
    
// Implementation
private:
    // <group DOM_FrameEffect_VcpTransformerEffect_Implementation>
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
    void setupMaterial(VfxS32 index, VcpEffectTypeDirection direction, VfxBool isReverse, VfxS32 width, VfxS32 height);
};


/*****************************************************************************
 * Class VcpTitleBarLightEffect
 *
 *  support direction:  
 *  default direction:
 *  default duration:
 *  affect property:
 *  parameter:
 *****************************************************************************/
class VcpTitleBarLightEffect : public VcpBaseEffect
{
// Constructor / Destructor
public:
    // Default constructor
    VcpTitleBarLightEffect(); 

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

    virtual void onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        );

    virtual void restore(VfxFrame *activeFrame);

private:
    // Variable
    VfxWeakPtr<VfxFrame> m_activeFrame;
    VfxMaterial * m_material;
    VfxFloatTimeline *m_offsetTimeline;

private:
    // Implementation
    void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);
};

/*****************************************************************************
 * Class Vcp3DBlingEffect
 *
 *  support direction:  
 *  default direction:
 *  default duration:
 *  affect property:
 *  parameter:
 *****************************************************************************/
class Vcp3DBlingEffect : public VcpBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_FrameEffect_VcpPopupEffect_Constructor/Destructor>
    // Default constructor
    Vcp3DBlingEffect(); 



// Override
protected:
    // <group DOM_FrameEffect_VcpPopupEffect_Override>
    virtual void onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        );

     // <group DOM_FrameEffect_VcpTransformerEffect_Override>
    virtual void restore(VfxFrame *activeFrame);
 // Variable
 private:
	   VfxWeakPtr <VfxFrame> m_activeFrame;          
     VfxFloatTimeline *m_timeline;
     VfxMaterial *m_material;

     void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);

};


/******************************************************************************
 * Class Vcp3DBlurEffect
 *
 *  support direction:  
 *  default direction:
 *  default duration:
 *  affect property:
 *  parameter:
 *****************************************************************************/
class Vcp3DBlurEffect : public VcpBaseEffect
{
// Constructor / Destructor
public:
    // <group DOM_FrameEffect_VcpPopupEffect_Constructor/Destructor>
    // Default constructor
    Vcp3DBlurEffect(); 

   

// Override
protected:
    // <group DOM_FrameEffect_VcpPopupEffect_Override>
    virtual void onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        );

     // <group DOM_FrameEffect_VcpTransformerEffect_Override>
    virtual void restore(VfxFrame *activeFrame);
     // Variable
private:
     VfxMaterial *m_material;
     VfxFloatTimeline *m_timeline;

     VfxBool m_isFrameTexture;
     VfxWeakPtr <VfxFrame> m_background;
     void onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted);

     static  vrt_render_dirty_type_enum frameEffectCallBack(
         vrt_frame_visual_property_struct *target_frame,
         const vrt_frame_visual_property_struct *watch_frame,
         void *user_data,
         vrt_u32 user_data_size);
};

#endif /* __COSMOS_3D_V10__ */

#endif /* __VCP_FRAME_EFFECT_H__ */
