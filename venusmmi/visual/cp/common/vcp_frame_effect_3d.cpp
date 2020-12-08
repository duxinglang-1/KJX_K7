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
 *  vcp_frame_effect_3d.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Venus frame effect Component
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
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __COSMOS_3D_V10__

/***************************************************************************** 
 * Include
 *****************************************************************************/
 
#include "vcp_frame_effect_3d.h"
#include "vfx_frame.h"
#include "vfx_datatype.h"
#include "vcp_frame_effect_type.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vrt_datatype.h"
#include "vfx_signal.h"
#include "vfx_animation.h"
#include "vfx_basic_type.h"
#include "vfx_transform.h"
#include "vfx_image_src.h"
#include <string.h>

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
#include "mmi_rp_srv_venus_component_title_bar_def.h" // for title bar effect shader
#include "mmi_rp_srv_venus_component_frame_effect_def.h"


/*****************************************************************************
 * Class Vcp3DCircleEffect
 *****************************************************************************/

Vcp3DCircleEffect::Vcp3DCircleEffect()
{
}


void Vcp3DCircleEffect::onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        )
{


    VFX_OBJ_CREATE(m_filterTimeline, VfxFloatTimeline, this);
    m_filterTimeline->setTarget(activeFrame);
    m_filterTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    m_filterTimeline->setDurationTime(duration);
    m_filterTimeline->setFromValue(0.0f);
    m_filterTimeline->setToValue(1.0f);
    m_filterTimeline->m_signalStopped.connect(this, &Vcp3DCircleEffect::onEndOfEffect);
    m_filterTimeline->start();

    VFX_OBJ_CREATE(m_fpeTimeline, VfxFloatTimeline, this);
    m_fpeTimeline->setTarget(activeFrame);
    m_fpeTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FPE_USER_0);
    m_fpeTimeline->setDurationTime(duration);
    m_fpeTimeline->setFromValue(0.0f);
    m_fpeTimeline->setToValue(1.0f);
    m_fpeTimeline->start();

    VfxS32 passNumber = 5;
    VFX_OBJ_CREATE_EX(m_material, VfxMaterial, activeFrame, (passNumber));
    activeFrame->setMaterial(m_material);

    VfxS32 i;
    for (i = 0; i < passNumber; i++)
    {
        setupMaterial(i, direction, isReverse, activeFrame->getSize().width, activeFrame->getSize().height);
    }
}

void Vcp3DCircleEffect::setupMaterial(VfxS32 index, VcpEffectTypeDirection direction, VfxBool isReverse, VfxS32 width, VfxS32 height)
{
    VfxPass *pass;
    VfxShaderProgram *program;
    VfxShaderUniforms *uniforms;
    VFX_OBJ_CREATE(pass, VfxPass, m_material);

    // Shader Program
    VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VCP_VTX_FRAME_EFFECT_3D_CIRCLE, VCP_FRG_FRAME_EFFECT_3D_CIRCLE));
    //VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR("c:\\FrameEffect\\3DCircle.vs"), VFX_WSTR("c:\\FrameEffect\\3DCircle.fs")));
    
    pass->setShaderProgram(program);

    // Shader Uniforms
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    pass->addShaderUniforms(uniforms);

    // Texture    
    uniforms->addUniformVariable(VFX_STR("index"), VFX_TYPE_ID_S32, 1)->setValue(index);

    VfxFloat pi = 3.14159265359f;
    VfxFloat fovy = pi / 6.0f;
    VfxFloat n = 10.0f;
    VfxFloat f = 2000.0f;

    VfxFloat h = vfxSin(fovy / 2.0f)/vfxCos(fovy / 2.0f);
    VfxFloat w = h * width / height;
    VfxFloat d = f - n;

    VfxMatrix4f model;
    model.setIdentity();
    model[3][0] = -width / 2.0f;
    model[3][1] = -height / 2.0f;

    VfxMatrix4f inv;
    inv.setIdentity();
    if (isReverse == VFX_FALSE)
    {
        inv[0][0] = -1.0f;
        inv[2][2] = -1.0f;
    }
    model = inv * model;

    uniforms->addUniformVariable(VFX_STR("u_model"), VFX_TYPE_ID_MAT4, 1)->setValue(model);
   
    VfxMatrix4f view;
    view.setIdentity();
    view[1][1] = -1.0f;
    view[2][2] = -1.0f;
    view[3][2] = -height / 2.0f / h;

    uniforms->addUniformVariable(VFX_STR("u_view"), VFX_TYPE_ID_MAT4, 1)->setValue(view);
    
    VfxMatrix4f proj;
    proj.setIdentity();
    proj[0][0] = 1.0f / w;
    proj[1][1] = 1.0f / h;
    proj[2][2] = -(n + f) / d;
    proj[3][3] = 0.0f;
    proj[2][3] = -1.0f;
    proj[3][2] = -2.0f * n * f / d;

    proj = proj * view;
    
    uniforms->addUniformVariable(VFX_STR("u_projectView"), VFX_TYPE_ID_MAT4, 1)->setValue(proj);
    
    uniforms->addUniformVariable(VFX_STR("u_startTime"), VFX_TYPE_ID_FLOAT, 1)->setValue(VfxFloat(index)/9.0f);
    uniforms->addUniformVariable(VFX_STR("u_endTime"), VFX_TYPE_ID_FLOAT, 1)->setValue(VfxFloat(index + 5)/9.0f);

    VfxFloat minR;
    VfxFloat maxR;
    if (index == 0)
    {
        minR = 0.0f;
        maxR = 0.165f * 0.165f;
    }
    else if (index == 1)
    {
        minR = 0.165f * 0.165f;
        maxR = 0.3f * 0.3f;
    }
    else if (index == 2)
    {
        minR = 0.3f * 0.3f;
        maxR = 0.5f * 0.5f;
    }
    else if (index == 3)
    {
        minR = 0.5f * 0.5f;
        maxR = 0.8f * 0.8f;
    }
    else
    {
        minR = 0.8f * 0.8f;
        maxR = 2.0f;
    }

    uniforms->addUniformVariable(VFX_STR("u_minR"), VFX_TYPE_ID_FLOAT, 1)->setValue(minR);
    uniforms->addUniformVariable(VFX_STR("u_maxR"), VFX_TYPE_ID_FLOAT, 1)->setValue(maxR);
    

    VfxCompositingMode *cm;
    VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
    pass->setCompositingMode(cm);
    cm->setDepthTestEnable(VFX_TRUE);
    cm->setDepthWriteEnable(VFX_TRUE);

    VfxPolygonMode *pm;
    VFX_OBJ_CREATE(pm, VfxPolygonMode, pass);
    pass->setPolygonMode(pm);
    pm->setCulling(VFX_CULLING_BACK);
    pm->setWinding(VFX_WINDING_CW);
    
    m_material->setPass(index, pass);
}


void Vcp3DCircleEffect::restore(VfxFrame *activeFrame)
{
    activeFrame->setMaterial(NULL);
    VFX_OBJ_CLOSE(m_material);
    VFX_OBJ_CLOSE(m_fpeTimeline);
}
    
void Vcp3DCircleEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if (isCompleted)
    {
        m_complete.emit();
    }
}


/*****************************************************************************
 * Class VcpTitleBarLightEffect
 *****************************************************************************/

VcpTitleBarLightEffect::VcpTitleBarLightEffect():
    m_material(NULL)
{
}


void VcpTitleBarLightEffect::onInit()
{
    VcpBaseEffect::onInit();

    VfxPass *pass;
    VfxShaderProgram *program;
    VfxShaderUniforms *uniforms;

    VFX_OBJ_CREATE_EX(m_material, VfxMaterial, this, (1));

    // Pass
    VFX_OBJ_CREATE(pass, VfxPass, m_material);
    m_material->setPass(0, pass);

    // Shader Program
    VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VfxResId(0), VCP_BINARY_TITLEBAR_EFFECT_FS));

    pass->setShaderProgram(program);

     // Shader Uniforms
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    pass->addShaderUniforms(uniforms);

    VfxShaderVariable *var;
    {
        const int BLIING_COUNT_2 = 38;
        static const VfxU8 bling2[BLIING_COUNT_2] = {255, 254, 252, 250, 247, 243, 238, 233, 227, 220, 213, 206, 198, 190, 182, 173, 164, 155, 146, 136, 127, 118, 108, 99, 89, 80, 72, 63, 55, 47, 39, 32, 25, 19, 13, 8, 4, 0};
        VfxImageBuffer imageBuf;
        imageBuf.ptr = (VfxU8*)bling2;
        imageBuf.pitchBytes = 38;
        imageBuf.width = 38;
        imageBuf.height = 1;
        imageBuf.colorFormat = VRT_COLOR_TYPE_A8;

        VfxImageSrc blingImageSrc(imageBuf);
        
        VfxImage2D *image;
        VfxTexture *tex;
        VFX_OBJ_CREATE_EX(image, VfxImage2D, m_material, (blingImageSrc) );
        VFX_OBJ_CREATE_EX(tex, VfxTexture2D, pass, (image));
        uniforms->addUniformVariable(VFX_STR("u_blingPic"), VFX_TYPE_ID_SAMPLER, 1)->setValue(tex);
    }

    var = uniforms->addUniformVariable(VFX_STR("offset"), VFX_TYPE_ID_FLOAT, 1);
    VFX_OBJ_CREATE(m_offsetTimeline, VfxFloatTimeline, var);
    m_offsetTimeline->setTarget(var);
    m_offsetTimeline->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT);
    m_offsetTimeline->setFromValue(0.0f);
    m_offsetTimeline->setToValue(1.0f);
    m_offsetTimeline->m_signalStopped.connect(this, &VcpTitleBarLightEffect::onEndOfEffect);
}

void VcpTitleBarLightEffect::onDeinit()
{
    VcpBaseEffect::onDeinit();
}

void VcpTitleBarLightEffect::onStart(
        VfxFrame *activeFrame,
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data,
        VfxS32 dataSize
        )
{
    VFX_UNUSED(dataSize);

    m_activeFrame = activeFrame;

    if (activeFrame)
    {
        activeFrame->setMaterial(m_material);
    }

    m_offsetTimeline->setDurationTime(duration / 5);
    m_offsetTimeline->start();
}

void VcpTitleBarLightEffect::restore(VfxFrame *activeFrame)
{
    if (activeFrame)
    {
        activeFrame->setMaterial(NULL);
    }
    m_offsetTimeline->stop();
}

void VcpTitleBarLightEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if (isCompleted)
    {
        if (m_activeFrame.isValid())
        {
            m_activeFrame->setMaterial(NULL);
            m_activeFrame = NULL;
        }
        m_complete.emit();
    }
}

/*****************************************************************************
 * Class Vcp3DBlingEffect
 *****************************************************************************/


Vcp3DBlingEffect::Vcp3DBlingEffect():
    m_timeline(NULL),
    m_activeFrame(NULL),
    m_material(NULL)    
{
}


void Vcp3DBlingEffect::onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        )
{
        VFX_UNUSED(dataSize);


        m_activeFrame = activeFrame;

         VfxPass *pass;
         VfxShaderProgram *program;
         VfxShaderUniforms *uniforms;
         VfxImage2D *image;         
         VfxTexture2D *tex;
      


         VFX_OBJ_CREATE_EX(m_material, VfxMaterial, this, (1));
         activeFrame->setMaterial(m_material);

         // Pass
         VFX_OBJ_CREATE(pass, VfxPass, m_material);
         m_material->setPass(0, pass);

         // Shader Program            
        // VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR_NULL, VFX_WSTR("d:\\test\\blur\\gaussian_blur_h.fs")));

         if(direction == VCP_EFFECT_DIRECTION_FROM_RIGHT || direction == VCP_EFFECT_DIRECTION_FROM_LEFT || direction == VCP_EFFECT_DIRECTION_FROM_NONE)
         {
               VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (NULL, VCP_FRG_FRAME_EFFECT_BLING_H));
//                 VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR_NULL, VFX_WSTR("d:\\test\\shader\\vcp_frame_effect_bling_h.fs")));
         }
         else
         {
               VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (NULL, VCP_FRG_FRAME_EFFECT_BLING_V));            
//                 VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR_NULL, VFX_WSTR("d:\\test\\shader\\vcp_frame_effect_bling_v.fs")));

         }

         pass->setShaderProgram(program);

          // Shader Uniforms
         VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
         pass->addShaderUniforms(uniforms);

         
         VFX_OBJ_CREATE_EX(image, VfxImage2D, m_material, (VCP_IMG_FRAME_EFFECT_BLING));               
         VFX_OBJ_CREATE_EX(tex, VfxTexture2D, uniforms, (image));
         uniforms->addUniformVariable(VFX_STR("blingTex"), VFX_TYPE_ID_SAMPLER, 1)->setValue(tex);

         VfxFloat shear = -image->getImageSrc().getSize().height * 2;
        VfxFloat blingwidth = image->getImageSrc().getSize().height;
        VfxS32 repeat = 1;
        VfxFloat bright = 0.7;


        if(data)
        {               
            Vcp3DEffectBlingData *userData = (Vcp3DEffectBlingData *)data;
            blingwidth = userData->width;
            shear = userData->sheer;    
            repeat = userData->repeat; 
            bright = userData->bright;
        }

         uniforms->addUniformVariable(VFX_STR("blingwidth"), VFX_TYPE_ID_FLOAT, 1)->setValue(blingwidth);
         uniforms->addUniformVariable(VFX_STR("shear"), VFX_TYPE_ID_FLOAT, 1)->setValue(shear);
         uniforms->addUniformVariable(VFX_STR("bright"), VFX_TYPE_ID_FLOAT, 1)->setValue(bright);         

         VfxShaderVariable *var;

         var = uniforms->addUniformVariable(VFX_STR("offset"), VFX_TYPE_ID_FLOAT, 1);


         VFX_OBJ_CREATE(m_timeline, VfxFloatTimeline, this);
         m_timeline->setTarget(var);
         m_timeline->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT);
         m_timeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
         m_timeline->setDurationTime(duration);
         m_timeline->setRepeatDuration(duration*2);
         m_timeline->setAutoReversed(isReverse);
         m_timeline->setRepeatCount(repeat);

         m_timeline->m_signalStopped.connect(this, &Vcp3DBlingEffect::onEndOfEffect);
        
         if(direction == VCP_EFFECT_DIRECTION_FROM_LEFT || direction == VCP_EFFECT_DIRECTION_FROM_BOTTOM || direction == VCP_EFFECT_DIRECTION_FROM_NONE)
         {
            m_timeline->setFromValue(0.0f);
            m_timeline->setToValue(1.0f);
            var->setValue(1.0f);
         }
         else
         {
            m_timeline->setFromValue(1.0f);
            m_timeline->setToValue(0.0f);
            var->setValue(0.0f);
         }
       
         m_timeline->start();
            
}



void Vcp3DBlingEffect::restore(VfxFrame *activeFrame)
{
    if (activeFrame)
    {
        activeFrame->setMaterial(NULL);
    }
    VFX_OBJ_CLOSE(m_timeline);
    VFX_OBJ_CLOSE(m_material);
}


void Vcp3DBlingEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
	if(m_activeFrame.get())
	{
		m_activeFrame->setMaterial(NULL);
   		VFX_OBJ_CLOSE(m_material);   		  
   	}
    if (isCompleted)
    {
        m_complete.emit();
    }
}

/*****************************************************************************
 * Class Vcp3DBlurEffect
 *****************************************************************************/


Vcp3DBlurEffect::Vcp3DBlurEffect():
                m_material(NULL),
                m_timeline(NULL),
                m_background(NULL),
                m_isFrameTexture(VFX_TRUE)
{
}


void Vcp3DBlurEffect::onStart(
        VfxFrame *activeFrame, 
        VfxMsec duration,
        VcpEffectTypeDirection direction,
        VfxBool isReverse,
        void *data, 
        VfxS32 dataSize
        )
{
        VFX_UNUSED(dataSize);


        m_background = activeFrame;
        VfxFloat darkness = 0.7;   
        VfxFloat from, to;


        if(isReverse)
        {
            from = 1.0f;
            to = 0.0f;                       
        }
        else
        {
            from = 0.0f;
            to = 1.0f;  
        }

        if(data)
        {       
            Vcp3DEffectBlurData *userData = (Vcp3DEffectBlurData *)data;
            m_background = userData->background;     
            darkness = userData->darkness;
            from = userData->from;
            m_isFrameTexture= userData->isFrameTexture;     
        }

          
        VfxPass *pass = NULL;
        VfxShaderProgram *program = NULL;
        VfxShaderUniforms *uniforms = NULL;
        VfxImage2D *image = NULL, *frameImage = NULL;
        VfxRenderTarget *rt = NULL;
        VfxTexture2D *tex = NULL, *texture2D = NULL;
        VfxTextureFrame *textureFrame = NULL;


        if(m_isFrameTexture)
        {   
			m_background->setHintFlag(VFX_FRAME_HINTS_TEXTURE_HIDDEN);                       
        }
        else
        {
            m_background->setHintFlag(VFX_FRAME_HINTS_TEXTURE);   

            VfxMaterial *material;
            VFX_OBJ_CREATE_EX(material, VfxMaterial, this, (1));
            m_background->setMaterial(material);                    

            // Pass
            VfxPass *pass;
            VFX_OBJ_CREATE(pass, VfxPass, material);
            material->setPass(0, pass);
        
            // Render Buffer
            VFX_OBJ_CREATE_EX(frameImage, VfxImage2D, pass, (m_background->getSize().width, m_background->getSize().height, VRT_COLOR_TYPE_RGB565));
        
            // Render Target
            VfxRenderTarget *rt;
            VFX_OBJ_CREATE_EX(rt, VfxRenderTarget, pass, (frameImage));
            pass->setRenderTarget(rt);
            rt->setClearColor(VFX_COLOR_BLACK);
            rt->enableClearColor(VFX_TRUE);            
        }

        VfxColor color = m_background->getBgColor();
        vrt_canvas_set_layer_frame_clear_color((vrt_color_type)color);


        // Material (2 pass rendering)
        VFX_OBJ_CREATE_EX(m_material, VfxMaterial, this, (2));
        activeFrame->setMaterial(m_material);

        // Pass
        VFX_OBJ_CREATE_EX(pass, VfxPass, m_material, (VFX_PASS_GEOMETRY_VIEWPORT));
        m_material->setPass(0, pass);

        // Shader Program            
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (NULL, VCP_FRG_FRAME_EFFECT_BLUR_H));
        pass->setShaderProgram(program);

        // Render Buffer
        VFX_OBJ_CREATE_EX(image, VfxImage2D, pass, (activeFrame->getSize().width / 2.0, activeFrame->getSize().height / 2.0, VRT_COLOR_TYPE_RGB565));

        // Render Target
        VFX_OBJ_CREATE_EX(rt, VfxRenderTarget, pass, (image));
        pass->setRenderTarget(rt);


        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        if(m_isFrameTexture)
        {
            VFX_OBJ_CREATE_EX(textureFrame, VfxTextureFrame, uniforms, (m_background.get()));         
            uniforms->addUniformVariable(VFX_STR("baseTex"), VFX_TYPE_ID_SAMPLER, 1)->setValue(textureFrame);
        }
        else
        {
            VFX_OBJ_CREATE_EX(texture2D, VfxTexture2D, uniforms, (frameImage));        
            uniforms->addUniformVariable(VFX_STR("baseTex"), VFX_TYPE_ID_SAMPLER, 1)->setValue(texture2D);
        }
        
        
        
        // Pass2
        VFX_OBJ_CREATE(pass, VfxPass, m_material);

        // Shader Program
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (NULL, VCP_FRG_FRAME_EFFECT_BLUR_V));
        pass->setShaderProgram(program);
        
        // Shader Uniforms
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);

        // Texture    
        VFX_OBJ_CREATE_EX(tex, VfxTexture2D, uniforms, (image));
        uniforms->addUniformVariable(VFX_STR("baseTex"), VFX_TYPE_ID_SAMPLER, 1)->setValue(tex);
        uniforms->addUniformVariable(VFX_STR("darkness"), VFX_TYPE_ID_FLOAT, 1)->setValue(darkness);

        if(m_isFrameTexture)
        {
            uniforms->addUniformVariable(VFX_STR("frameTex"), VFX_TYPE_ID_SAMPLER, 1)->setValue(textureFrame);
        }
        else
        {
            uniforms->addUniformVariable(VFX_STR("frameTex"), VFX_TYPE_ID_SAMPLER, 1)->setValue(texture2D);
        }


        m_material->setPass(1, pass);

        

        VFX_OBJ_CREATE(m_timeline, VfxFloatTimeline, this);

        m_timeline->setTarget(activeFrame);
        m_timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FPE_USER_0);
        m_timeline->setDurationTime(duration);
        m_timeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
        m_timeline->m_signalStopped.connect(this, &Vcp3DBlurEffect::onEndOfEffect);        
        m_timeline->setFromValue(from);
        m_timeline->setToValue(to);
        m_timeline->start();

        activeFrame->setFpeUser0(to);
        activeFrame->setPropertyEffectCallback(
        m_background.get(),
        frameEffectCallBack,
        NULL,
        0,
        VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);        
}

vrt_render_dirty_type_enum Vcp3DBlurEffect::frameEffectCallBack(
               vrt_frame_visual_property_struct *target_frame,
               const vrt_frame_visual_property_struct *watch_frame,
               void *user_data,
               vrt_u32 user_data_size)
{    
    return VRT_RENDER_DIRTY_TYPE_CONTENT_DIRTY;
}


void Vcp3DBlurEffect::restore(VfxFrame *activeFrame)
{
    activeFrame->setMaterial(NULL);

    vrt_canvas_set_layer_frame_clear_color(VRT_COLOR_NULL);

    if(m_background.get() != NULL)
    {       
       if(m_isFrameTexture)
       {
           m_background->clearHintFlag(VFX_FRAME_HINTS_TEXTURE_HIDDEN);  
       }
       else
       {
           m_background->clearHintFlag(VFX_FRAME_HINTS_TEXTURE);
           m_background->setMaterial(NULL);       
       }       
    }
    
    VFX_OBJ_CLOSE(m_timeline);
    VFX_OBJ_CLOSE(m_material);    
}

void Vcp3DBlurEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{

    if (isCompleted)
    {
        m_complete.emit();		
    }
}
#endif /* __COSMOS_3D_V10__ */

