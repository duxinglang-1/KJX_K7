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
 *  vcp_page_panel_3d.cpp
 *
 * Project:
 * --------
 *  Venus
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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


#if defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__)

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vcp_page_panel_3d.h"
#include "vadp_mmi_frm.h"
extern "C" 
{
    #include "MMIDataType.h"
    //#include "pageflip.h"
}
#include "vfx_frame.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_signal.h"
#include "vrt_datatype.h"
#include "vfx_animation.h"
#include "vfx_transform.h"
#include "vfx_basic_type.h"

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
#include "mmi_rp_srv_venus_component_page_panel_def.h"

/*****************************************************************************
 * Class VcpPage3DCircleEffect
 *****************************************************************************/

VcpPage3DCircleEffect::VcpPage3DCircleEffect() :
    m_3dframe(NULL)
{
}


void VcpPage3DCircleEffect::onStart(
        VcpPagePanel *pagePanel,
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        )
{
    if (duration == -1)
    {
        duration = 250;
    }

    VfxBool useBuff = VFX_FALSE;

    if (data)
    {
        VFX_ASSERT(dataSize == sizeof(VcpPage3DImageBufferData));
        useBuff = VFX_TRUE;
    }

    if (useBuff)
    {
        if (currentFrame)
        {
            m_backupHint[0] = currentFrame->getHints();
            currentFrame->setHidden(VFX_TRUE);
        }

        VfxImageSrc frame1src;
        VfxImageSrc frame2src;
        VcpPage3DImageBufferData* bufferData = (VcpPage3DImageBufferData*) data;

        if (direction == VCP_PAGE_DIRECTION_BACKWARD)
        {
            frame1src = bufferData->newImageSrc;
            frame2src = bufferData->oldImageSrc;
        }
        else
        {
            frame1src = bufferData->oldImageSrc;
            frame2src = bufferData->newImageSrc;
        }

        VfxS32 passNumber = 3;
        
        // create another pure color frame to improve performance
        targetFrame->setHidden(VFX_TRUE);
        VFX_OBJ_CREATE(m_3dframe, VfxFrame, pagePanel);
        m_3dframe->setSize(targetFrame->getSize());
        m_3dframe->setHidden(VFX_FALSE);
		m_3dframe->setBgColor(VFX_COLOR_GREEN);
        m_3dframe->setImgContent(frame2src);

        VFX_OBJ_CREATE_EX(m_material, VfxMaterial, this, (passNumber));

        m_3dframe->setMaterial(m_material);

        VfxS32 i;
        for (i = 0; i < passNumber; i++)
        {
            setupMaterialByImageSrc(i, bufferData->oldImageSrc, bufferData->newImageSrc, m_3dframe->getSize().width, m_3dframe->getSize().height);
        }
    }
    else
    {
        if (currentFrame)
        {
            m_backupHint[0] = currentFrame->getHints();
            currentFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);
        }

        VfxFrame *frame1;
        VfxFrame *frame2;

        if (direction == VCP_PAGE_DIRECTION_BACKWARD)
        {
            frame1 = targetFrame;
            frame2 = currentFrame;
        }
        else
        {
            frame1 = currentFrame;
            frame2 = targetFrame;
        }

        VfxS32 passNumber = 3;

        
        // create another pure color frame to improve performance
        targetFrame->setHidden(VFX_TRUE);
        VFX_OBJ_CREATE(m_3dframe, VfxFrame, pagePanel);
        m_3dframe->setSize(targetFrame->getSize());
        m_3dframe->setHidden(VFX_FALSE);

        VFX_OBJ_CREATE_EX(m_material, VfxMaterial, this, (passNumber));

        m_3dframe->setMaterial(m_material);

        VfxS32 i;
        for (i = 0; i < passNumber; i++)
        {
            setupMaterial(i, frame1, frame2, m_3dframe->getSize().width, m_3dframe->getSize().height);
        }
    }
    
    VFX_OBJ_CREATE(m_filterTimeline, VfxFloatTimeline, this);
    m_filterTimeline->setTarget(m_3dframe);
    m_filterTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Z);
    m_filterTimeline->setDurationTime(duration);
    if (direction == VCP_PAGE_DIRECTION_BACKWARD)
    {
        m_filterTimeline->setFromValue(1.0f);
        m_filterTimeline->setToValue(0.0f);
    }
    else
    {
        m_filterTimeline->setFromValue(0.0f);
        m_filterTimeline->setToValue(1.0f);
    }
    m_filterTimeline->m_signalStopped.connect(this, &VcpPage3DCircleEffect::onEndOfEffect);
    m_filterTimeline->start();

    VFX_OBJ_CREATE(m_fpeTimeline, VfxFloatTimeline, this);
    m_fpeTimeline->setTarget(m_3dframe);
    m_fpeTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FPE_USER_0);
    m_fpeTimeline->setDurationTime(duration);
    if (direction == VCP_PAGE_DIRECTION_BACKWARD)
    {
        m_fpeTimeline->setFromValue(1.0f);
        m_fpeTimeline->setToValue(0.0f);
    }
    else
    {
        m_fpeTimeline->setFromValue(0.0f);
        m_fpeTimeline->setToValue(1.0f);
    }
    m_fpeTimeline->start();
    
}


void VcpPage3DCircleEffect::setupMaterial(VfxS32 index, VfxFrame *frame1, VfxFrame *frame2, VfxS32 width, VfxS32 height)
{
    VfxPass *pass;
    VfxShaderProgram *program;
    VfxShaderUniforms *uniforms;
    VFX_OBJ_CREATE(pass, VfxPass, m_material);

    // Shader Program
    VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VCP_VTX_PAGE_PANEL_3D_CIRCLE, VCP_FRG_PAGE_PANEL_3D_CIRCLE));
    //VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR("c:\\PagePanel\\3DCircle.vs"), VFX_WSTR("c:\\PagePanel\\3DCircle.fs")));
    
    pass->setShaderProgram(program);

    // Shader Uniforms
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    pass->addShaderUniforms(uniforms);

    uniforms->addUniformVariable(VFX_STR("uFlip"), VFX_TYPE_ID_BOOL, 1)->setValue(VFX_TRUE);
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
    
    //uniforms->addUniformVariable(VFX_STR("u_startTime"), VFX_TYPE_ID_FLOAT, 1)->setValue(VfxFloat(index)/9.0f);
    //uniforms->addUniformVariable(VFX_STR("u_endTime"), VFX_TYPE_ID_FLOAT, 1)->setValue(VfxFloat(index + 5)/9.0f);
    uniforms->addUniformVariable(VFX_STR("u_startTime"), VFX_TYPE_ID_FLOAT, 1)->setValue(VfxFloat(index)/7.0f);
    uniforms->addUniformVariable(VFX_STR("u_endTime"), VFX_TYPE_ID_FLOAT, 1)->setValue(VfxFloat(index + 5)/7.0f);

    VfxFloat minR;
    VfxFloat maxR;
    if (index == 0)
    {
        minR = 0.0f;
        //maxR = 0.165f * 0.165f;
        maxR = 0.25f * 0.25f;
    }
    else if (index == 1)
    {
        //minR = 0.165f * 0.165f;
        minR = 0.25f * 0.25f;
        //maxR = 0.3f * 0.3f;
        maxR = 0.5f * 0.5f;
    }
    else if (index == 2)
    {
        //minR = 0.3f * 0.3f;
        minR = 0.5f * 0.5f;
        //maxR = 0.5f * 0.5f;
        maxR = 2.0f;
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
    uniforms->addUniformVariable(VFX_STR("u_ratio"), VFX_TYPE_ID_FLOAT, 1)->setValue(VfxFloat(height)/width);

    VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("u_frame1"), VFX_TYPE_ID_SAMPLER, 1);
    pass->addShaderUniforms(uniforms);

    VfxTextureFrame *texture;
    VFX_OBJ_CREATE_EX(texture, VfxTextureFrame, var, (frame1));
    var->setValue(texture);

    var = uniforms->addUniformVariable(VFX_STR("u_frame2"), VFX_TYPE_ID_SAMPLER, 1);
    pass->addShaderUniforms(uniforms);

    VFX_OBJ_CREATE_EX(texture, VfxTextureFrame, var, (frame2));
    var->setValue(texture);
    

    VfxCompositingMode *cm;
    VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
    pass->setCompositingMode(cm);
    cm->setDepthTestEnable(VFX_TRUE);
    cm->setDepthWriteEnable(VFX_TRUE);
    
    m_material->setPass(index, pass);
}


void VcpPage3DCircleEffect::setupMaterialByImageSrc(VfxS32 index, VfxImageSrc& frame1ImgSrc, VfxImageSrc& frame2ImgSrc, VfxS32 width, VfxS32 height)
{
    VfxPass *pass;
    VfxShaderProgram *program;
    VfxShaderUniforms *uniforms;
    VFX_OBJ_CREATE(pass, VfxPass, m_material);

    // Shader Program
    VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VCP_VTX_PAGE_PANEL_3D_CIRCLE, VCP_FRG_PAGE_PANEL_3D_CIRCLE));
    //VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR("c:\\PagePanel\\3DCircle.vs"), VFX_WSTR("c:\\PagePanel\\3DCircle.fs")));
    //program->setVertexShader(VFX_WSTR("c:\\vcp_page_panel_3D_Circle.vs"));
    pass->setShaderProgram(program);

    // Shader Uniforms
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    pass->addShaderUniforms(uniforms);

    uniforms->addUniformVariable(VFX_STR("uFlip"), VFX_TYPE_ID_BOOL, 1)->setValue(VFX_FALSE);

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
    
    //uniforms->addUniformVariable(VFX_STR("u_startTime"), VFX_TYPE_ID_FLOAT, 1)->setValue(VfxFloat(index)/9.0f);
    //uniforms->addUniformVariable(VFX_STR("u_endTime"), VFX_TYPE_ID_FLOAT, 1)->setValue(VfxFloat(index + 5)/9.0f);
    uniforms->addUniformVariable(VFX_STR("u_startTime"), VFX_TYPE_ID_FLOAT, 1)->setValue(VfxFloat(index)/7.0f);
    uniforms->addUniformVariable(VFX_STR("u_endTime"), VFX_TYPE_ID_FLOAT, 1)->setValue(VfxFloat(index + 5)/7.0f);

    VfxFloat minR;
    VfxFloat maxR;
    if (index == 0)
    {
        minR = 0.0f;
        //maxR = 0.165f * 0.165f;
        maxR = 0.25f * 0.25f;
    }
    else if (index == 1)
    {
        //minR = 0.165f * 0.165f;
        minR = 0.25f * 0.25f;
        //maxR = 0.3f * 0.3f;
        maxR = 0.5f * 0.5f;
    }
    else if (index == 2)
    {
        //minR = 0.3f * 0.3f;
        minR = 0.5f * 0.5f;
        //maxR = 0.5f * 0.5f;
        maxR = 2.0f;
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
    uniforms->addUniformVariable(VFX_STR("u_ratio"), VFX_TYPE_ID_FLOAT, 1)->setValue(VfxFloat(height)/width);

    VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("u_frame1"), VFX_TYPE_ID_SAMPLER, 1);
    pass->addShaderUniforms(uniforms);

    VfxImage2D *img;
    VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (frame1ImgSrc));

    VfxTexture2D *texture;
    VFX_OBJ_CREATE_EX(texture, VfxTexture2D, var, (img));
    var->setValue(texture);

    //VfxTextureFrame *texture;
    //VFX_OBJ_CREATE_EX(texture, VfxTextureFrame, var, (frame1));
    //var->setValue(texture);

    var = uniforms->addUniformVariable(VFX_STR("u_frame2"), VFX_TYPE_ID_SAMPLER, 1);
    pass->addShaderUniforms(uniforms);


    VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (frame2ImgSrc));

    VFX_OBJ_CREATE_EX(texture, VfxTexture2D, var, (img));
    var->setValue(texture);

    //VFX_OBJ_CREATE_EX(texture, VfxTextureFrame, var, (frame2));
    //var->setValue(texture);
    

    VfxCompositingMode *cm;
    VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
    pass->setCompositingMode(cm);
    cm->setDepthTestEnable(VFX_TRUE);
    cm->setDepthWriteEnable(VFX_TRUE);
    
    m_material->setPass(index, pass);
}


void VcpPage3DCircleEffect::onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    if (lastFrame)
    {
        lastFrame->setHints(m_backupHint[0]);
    }
	if (currentFrame)
	{
		//currentFrame->setHints(m_backupHint[1]);
        currentFrame->setMaterial(NULL);
	}
   
	VFX_OBJ_CLOSE(m_filterTimeline);
    VFX_OBJ_CLOSE(m_fpeTimeline);
    VFX_OBJ_CLOSE(m_material);
    VFX_OBJ_CLOSE(m_3dframe);
}


void VcpPage3DCircleEffect::onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    if (lastFrame)
    {
        lastFrame->setHints(m_backupHint[0]);
    }
	if (currentFrame)
	{
		//currentFrame->setHints(m_backupHint[1]);
        currentFrame->setMaterial(NULL);
	}
    
    VFX_OBJ_CLOSE(m_filterTimeline);
	VFX_OBJ_CLOSE(m_fpeTimeline);
    VFX_OBJ_CLOSE(m_material);
    VFX_OBJ_CLOSE(m_3dframe);
}


void VcpPage3DCircleEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}

/*****************************************************************************
 * Class VcpPage3DCubeFlyOutEffect
 *****************************************************************************/

VcpPage3DCubeFlyOutEffect::VcpPage3DCubeFlyOutEffect() :
    m_3dframe(NULL),
    m_tempFrame(NULL),
    m_world(NULL)
{
}


void VcpPage3DCubeFlyOutEffect::onStart(
        VcpPagePanel *pagePanel,
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        )
{
    if (duration == -1)
    {
        duration = 250;
    }

    VfxBool useBuff = VFX_FALSE;

    if (data)
    {
        VFX_ASSERT(dataSize == sizeof(VcpPage3DImageBufferData));
        useBuff = VFX_TRUE;
    }
    
    if (currentFrame)
    {
        m_backupHint[0] = currentFrame->getHints();
        if (direction != VCP_PAGE_DIRECTION_BACKWARD)
        {
            if (useBuff)
            {
                currentFrame->setHidden(VFX_TRUE);
            }
            else
            {
                currentFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);
            }
        }
    }

    m_backupHint[1] = targetFrame->getHints();
    if (direction == VCP_PAGE_DIRECTION_BACKWARD)
    {
        if (useBuff)
        {
            targetFrame->setHidden(VFX_TRUE);
        }
        else
        {
            targetFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);
        }
    }
   
    VFX_OBJ_CREATE(m_3dframe, VfxFrame, pagePanel);
    m_3dframe->setSize(pagePanel->getSize());
    m_3dframe->setHidden(VFX_FALSE);

    /* World */
    VFX_OBJ_CREATE(m_world, VfxWorld, m_3dframe);
    m_3dframe->setWorld(m_world);

    if (useBuff)
    {
        VfxImageSrc frame1Src; 
        VfxImageSrc frame2Src; 
        VcpPage3DImageBufferData* bufferData = (VcpPage3DImageBufferData*) data;
        if (direction == VCP_PAGE_DIRECTION_BACKWARD)
        {
            frame1Src = bufferData->newImageSrc;
            frame2Src = bufferData->oldImageSrc;
        }
        else
        {
            frame1Src = bufferData->oldImageSrc;
            frame2Src = bufferData->newImageSrc;
        }

        VfxAssetLoader::loadSceneBegin(m_world, VCP_SCN_PAGE_PANEL_CUBE);
        setupBoxByImageSrc(VFX_STR("Box001-node"), frame1Src, 4, 0);
        VfxAssetLoader::loadSceneEnd();

        // improve performance use image2D

        targetFrame->setHidden(VFX_TRUE);
        VFX_OBJ_CREATE(m_tempFrame, VfxFrame, pagePanel);
        m_tempFrame->setHidden(VFX_FALSE);
        m_tempFrame->setSize(currentFrame->getSize());
      
        VfxMaterial *material;
        VFX_OBJ_CREATE_EX(material, VfxMaterial, this, (1));
        m_tempFrame->setMaterial(material);

        VfxPass *pass;
        VFX_OBJ_CREATE(pass, VfxPass, material);
        material->setPass(0, pass);

        VfxShaderProgram *program;
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_RES_ID_NULL, VCP_FRG_PAGE_PANEL_SIMPLE));
        pass->setShaderProgram(program);

        VfxShaderUniforms *uniforms;
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);

        VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
        pass->addShaderUniforms(uniforms);

        VfxImage2D *img;
        VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (frame2Src));

        VfxTexture2D *texture;
        VFX_OBJ_CREATE_EX(texture, VfxTexture2D, var, (img));
        var->setValue(texture);

        VfxCompositingMode *cm;
        VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
        cm->setDepthTestEnable(VFX_FALSE);
        pass->setCompositingMode(cm);

        VfxBlender *blender;
        VFX_OBJ_CREATE(blender, VfxBlender, cm);
        cm->setBlender(blender);

        m_3dframe->bringToFront();
    }
    else
    {
        VfxFrame *frame1; 
        if (direction == VCP_PAGE_DIRECTION_BACKWARD)
        {
            frame1 = targetFrame;
        }
        else
        {
            frame1 = currentFrame;
        }

        VfxAssetLoader::loadSceneBegin(m_world, VCP_SCN_PAGE_PANEL_CUBE);
        setupBox(VFX_STR("Box001-node"), frame1, 4, 0);
        VfxAssetLoader::loadSceneEnd();
    }

    VFX_OBJ_CREATE(m_mainTimeline, VfxFloatTimeline, this);
    m_mainTimeline->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_mainTimeline->setTarget(pagePanel);
    m_mainTimeline->setRepeatCount(1);
    
    if (direction == VCP_PAGE_DIRECTION_BACKWARD)
    {
        m_mainTimeline->setFromValue(1);
        m_mainTimeline->setToValue(0);
    }
    else
    {
        m_mainTimeline->setFromValue(0);
        m_mainTimeline->setToValue(1);
    }
    m_mainTimeline->setDuration(duration);
    m_mainTimeline->m_signalStopped.connect(this, &VcpPage3DCubeFlyOutEffect::onEndOfEffect); 
    

    VfxAnimation *anim;
    VFX_OBJ_CREATE(anim, VfxAnimation, m_world);

    VfxAssetLoader::loadAnimation(anim, m_world, VCP_ANI_PAGE_PANEL_CUBE);
    
    anim->setTimelineTime(m_mainTimeline);
    m_mainTimeline->start();

}


void VcpPage3DCubeFlyOutEffect::setupBox(const VfxString &name, VfxFrame *frameTexture, VfxS32 rIndex, VfxS32 cIndex)
{
    VfxObject3D *obj = VfxAssetLoader::findObjByName(name);
    VfxMesh* box = VFX_OBJ_DYNAMIC_CAST(obj, VfxMesh);

    VfxMaterial *material;
    if (rIndex == -1)
    {
        material = box->getMaterial(0);
    }
    else
    {
        material = box->getMaterial(1);
    }
    
    VfxPass *pass;
    pass = material->getPass(0);
    
    VfxShaderUniforms *uniforms;
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    pass->addShaderUniforms(uniforms);

    VfxTextureFrame *texture;
    VFX_OBJ_CREATE_EX(texture, VfxTextureFrame, var, (frameTexture));
    var->setValue(texture);
}


void VcpPage3DCubeFlyOutEffect::setupBoxByImageSrc(const VfxString &name, VfxImageSrc& frameTexture, VfxS32 rIndex, VfxS32 cIndex)
{
    VfxObject3D *obj = VfxAssetLoader::findObjByName(name);
    VfxMesh* box = VFX_OBJ_DYNAMIC_CAST(obj, VfxMesh);

    VfxMaterial *material;
    if (rIndex == -1)
    {
        material = box->getMaterial(0);
    }
    else
    {
        material = box->getMaterial(1);
    }
    
    VfxPass *pass;
    pass = material->getPass(0);
    
    VfxShaderUniforms *uniforms;
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    uniforms->addUniformVariable(VFX_STR("uFlip"), VFX_TYPE_ID_BOOL, 1)->setValue(VFX_FALSE);
    VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    pass->addShaderUniforms(uniforms);

    VfxImage2D *img;
    VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (frameTexture));

    VfxTexture2D *texture;
    VFX_OBJ_CREATE_EX(texture, VfxTexture2D, var, (img));
    var->setValue(texture);
}


void VcpPage3DCubeFlyOutEffect::onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    if (lastFrame)
    {
        lastFrame->setHints(m_backupHint[0]);
    }
	if (currentFrame)
	{
		currentFrame->setHints(m_backupHint[1]);
	}
    VFX_OBJ_CLOSE(m_3dframe);
    VFX_OBJ_CLOSE(m_tempFrame);
	VFX_OBJ_CLOSE(m_mainTimeline);
}


void VcpPage3DCubeFlyOutEffect::onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    if (lastFrame)
    {
        lastFrame->setHints(m_backupHint[0]);
    }
	if (currentFrame)
	{
		currentFrame->setHints(m_backupHint[1]);
	}
    VFX_OBJ_CLOSE(m_3dframe);
    VFX_OBJ_CLOSE(m_tempFrame);
	VFX_OBJ_CLOSE(m_mainTimeline);
}


void VcpPage3DCubeFlyOutEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}

/*****************************************************************************
 * Class VcpPage3DBlindsEffect
 *****************************************************************************/

VcpPage3DBlindsEffect::VcpPage3DBlindsEffect()
{
}


void VcpPage3DBlindsEffect::onStart(
        VcpPagePanel *pagePanel,
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        )
{
    if (duration == -1)
    {
        duration = 250;
    }

    VfxBool useBuff = VFX_FALSE;

    if (data)
    {
        VFX_ASSERT(dataSize == sizeof(VcpPage3DImageBufferData));
        useBuff = VFX_TRUE;
    }

    
    if (currentFrame)
    {
        m_backupHint[0] = currentFrame->getHints();
        if (useBuff)
        {
            currentFrame->setHidden(VFX_TRUE);
        }
        else
        {
            currentFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);
        }
    }

    m_backupHint[1] = targetFrame->getHints();
    if (useBuff)
    {
        targetFrame->setHidden(VFX_TRUE);
    }
    else
    {
        targetFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);
    }
   
    VFX_OBJ_CREATE(m_3dframe, VfxFrame, pagePanel);
    m_3dframe->setSize(pagePanel->getSize());
    m_3dframe->setHidden(VFX_FALSE);

    /* World */
    VFX_OBJ_CREATE(m_world, VfxWorld, m_3dframe);
    m_3dframe->setWorld(m_world);

    if (useBuff)
    {
        VfxImageSrc frame1Src; 
    	VfxImageSrc frame2Src;

        VcpPage3DImageBufferData* bufferData = (VcpPage3DImageBufferData*) data;

        if (direction == VCP_PAGE_DIRECTION_BACKWARD)
        {
            frame1Src = bufferData->oldImageSrc;
            frame2Src = bufferData->newImageSrc;
        }
        else
        {
            frame1Src = bufferData->newImageSrc;
            frame2Src = bufferData->oldImageSrc;
        }

        VfxAssetLoader::loadSceneBegin(m_world, VCP_SCN_PAGE_PANEL_TRIANGLE);
        setupBoxByImageSrc(VFX_STR("Star011-node"), frame1Src, frame2Src);  
        VfxAssetLoader::loadSceneEnd();
    }
    else
    {
        VfxFrame *frame1; 
    	VfxFrame *frame2;

        if (direction == VCP_PAGE_DIRECTION_BACKWARD)
        {
            frame1 = currentFrame;
            frame2 = targetFrame;
        }
        else
        {
            frame1 = targetFrame;
            frame2 = currentFrame;
        }

        VfxAssetLoader::loadSceneBegin(m_world, VCP_SCN_PAGE_PANEL_TRIANGLE);
        setupBox(VFX_STR("Star011-node"), frame1, frame2);  
        VfxAssetLoader::loadSceneEnd();
    }

    VFX_OBJ_CREATE(m_mainTimeline, VfxFloatTimeline, this);
    m_mainTimeline->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_mainTimeline->setTarget(pagePanel);
    m_mainTimeline->setRepeatCount(1);
    
    if (direction == VCP_PAGE_DIRECTION_BACKWARD)
    {
        m_mainTimeline->setFromValue(1);
        m_mainTimeline->setToValue(0);
    }
    else
    {
        m_mainTimeline->setFromValue(0);
        m_mainTimeline->setToValue(1);
    }
    m_mainTimeline->setDuration(duration);
    m_mainTimeline->m_signalStopped.connect(this, &VcpPage3DBlindsEffect::onEndOfEffect); 
    

    VfxAnimation *anim;
    VFX_OBJ_CREATE(anim, VfxAnimation, m_world);

    VfxAssetLoader::loadAnimation(anim, m_world, VCP_ANI_PAGE_PANEL_TRIANGLE);
    //anim->start();
    anim->setTimelineTime(m_mainTimeline);
    m_mainTimeline->start();

}


void VcpPage3DBlindsEffect::setupBox(const VfxString &name, VfxFrame *frameTexture1, VfxFrame *frameTexture2)
{
    VfxObject3D *obj = VfxAssetLoader::findObjByName(name);
    VfxMesh* box = VFX_OBJ_DYNAMIC_CAST(obj, VfxMesh);

    VfxMaterial *material;
    material = box->getMaterial(0);
    
    VfxPass *pass;
    pass = material->getPass(0);
    
    VfxShaderUniforms *uniforms;
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    pass->addShaderUniforms(uniforms);

    VfxTextureFrame *texture;
    VFX_OBJ_CREATE_EX(texture, VfxTextureFrame, var, (frameTexture2));
    var->setValue(texture);

    material = box->getMaterial(1);                
    pass = material->getPass(0);
    
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    pass->addShaderUniforms(uniforms);

    VFX_OBJ_CREATE_EX(texture, VfxTextureFrame, var, (frameTexture1));
    var->setValue(texture);
}


void VcpPage3DBlindsEffect::setupBoxByImageSrc(const VfxString &name, VfxImageSrc& frameTexture1, VfxImageSrc& frameTexture2)
{
    VfxObject3D *obj = VfxAssetLoader::findObjByName(name);
    VfxMesh* box = VFX_OBJ_DYNAMIC_CAST(obj, VfxMesh);

    VfxMaterial *material;
    material = box->getMaterial(0);
    
    VfxPass *pass;
    pass = material->getPass(0);

    // TODO: temp solution
    //VfxShaderProgram *program = pass->getShaderProgram();
    //program->setVertexShader(VFX_WSTR("c:\\pnt2tcs.vs"));
    
    VfxShaderUniforms *uniforms;
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    uniforms->addUniformVariable(VFX_STR("uFlip"), VFX_TYPE_ID_BOOL, 1)->setValue(VFX_FALSE);
    VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    pass->addShaderUniforms(uniforms);

    VfxImage2D *img;
    VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (frameTexture2));

    VfxTexture2D *texture;
    VFX_OBJ_CREATE_EX(texture, VfxTexture2D, var, (img));
    var->setValue(texture);

    material = box->getMaterial(1);                
    pass = material->getPass(0);

    // TODO: temp solution
	//program = pass->getShaderProgram();
    //program->setVertexShader(VFX_WSTR("c:\\pnt2tcs.vs"));
    
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    uniforms->addUniformVariable(VFX_STR("uFlip"), VFX_TYPE_ID_BOOL, 1)->setValue(VFX_FALSE);
    var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    pass->addShaderUniforms(uniforms);

    VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (frameTexture1));
    VFX_OBJ_CREATE_EX(texture, VfxTexture2D, var, (img));
    var->setValue(texture);
}


void VcpPage3DBlindsEffect::onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    if (lastFrame)
    {
        lastFrame->setHints(m_backupHint[0]);
    }
	if (currentFrame)
	{
		currentFrame->setHints(m_backupHint[1]);
	}
    VFX_OBJ_CLOSE(m_3dframe);
	VFX_OBJ_CLOSE(m_mainTimeline);
}


void VcpPage3DBlindsEffect::onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    if (lastFrame)
    {
        lastFrame->setHints(m_backupHint[0]);
    }
	if (currentFrame)
	{
		currentFrame->setHints(m_backupHint[1]);
	}
    VFX_OBJ_CLOSE(m_3dframe);
	VFX_OBJ_CLOSE(m_mainTimeline);
}


void VcpPage3DBlindsEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}


/*****************************************************************************
 * Class VcpPage3DBrickFlipEffect
 *****************************************************************************/

VcpPage3DBrickFlipEffect::VcpPage3DBrickFlipEffect()
{
}


void VcpPage3DBrickFlipEffect::onStart(
        VcpPagePanel *pagePanel,
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        )
{
    if (duration == -1)
    {
        duration = 250;
    }

    VfxBool useBuff = VFX_FALSE;

    if (data)
    {
        VFX_ASSERT(dataSize == sizeof(VcpPage3DImageBufferData));
        useBuff = VFX_TRUE;
    }
    
    if (currentFrame)
    {
        m_backupHint[0] = currentFrame->getHints();
        if (useBuff)
        {
            currentFrame->setHidden(VFX_TRUE);
        }
        else
        {
            currentFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);
        }
    }

    m_backupHint[1] = targetFrame->getHints();
    if (useBuff)
    {
        targetFrame->setHidden(VFX_TRUE);
    }
    else
    {
        targetFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);
    }
   
    VFX_OBJ_CREATE(m_3dframe, VfxFrame, pagePanel);
    m_3dframe->setSize(pagePanel->getSize());
    m_3dframe->setHidden(VFX_FALSE);

    /* World */
    VFX_OBJ_CREATE(m_world, VfxWorld, m_3dframe);
    m_3dframe->setWorld(m_world);

    if (useBuff)
    {
        VfxImageSrc frame1Src; 
    	VfxImageSrc frame2Src;
        VfxBool isRotate = VFX_FALSE;

        VcpPage3DImageBufferData* bufferData = (VcpPage3DImageBufferData*) data;

        if (direction == VCP_PAGE_DIRECTION_FROM_RIGHT || direction == VCP_PAGE_DIRECTION_FROM_BOTTOM)
        {
            frame1Src = bufferData->oldImageSrc;
            frame2Src = bufferData->newImageSrc;
        }
        else
        {
            frame1Src = bufferData->newImageSrc;
            frame2Src = bufferData->oldImageSrc;
        }

        if (direction == VCP_PAGE_DIRECTION_FROM_UP || direction == VCP_PAGE_DIRECTION_FROM_BOTTOM)
        {
            isRotate = VFX_TRUE;
        }

        VfxAssetLoader::loadSceneBegin(m_world, VCP_SCN_PAGE_PANEL_BRICK);
        setupBoxByImageSrc(VFX_STR("Box001-node"), frame1Src, frame2Src, isRotate);
        VfxAssetLoader::loadSceneEnd();
    }
    else
    {

        VfxFrame *frame1; 
    	VfxFrame *frame2;
        VfxBool isRotate = VFX_FALSE;

        if (direction == VCP_PAGE_DIRECTION_FROM_RIGHT || direction == VCP_PAGE_DIRECTION_FROM_BOTTOM)
        {
            frame1 = currentFrame;
            frame2 = targetFrame;
        }
        else
        {
            frame1 = targetFrame;
            frame2 = currentFrame;
        }

        if (direction == VCP_PAGE_DIRECTION_FROM_UP || direction == VCP_PAGE_DIRECTION_FROM_BOTTOM)
        {
            isRotate = VFX_TRUE;
        }

        VfxAssetLoader::loadSceneBegin(m_world, VCP_SCN_PAGE_PANEL_BRICK);
        setupBox(VFX_STR("Box001-node"), frame1, frame2, isRotate);
        VfxAssetLoader::loadSceneEnd();
    }


    VFX_OBJ_CREATE(m_mainTimeline, VfxFloatTimeline, this);
    m_mainTimeline->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_mainTimeline->setTarget(pagePanel);
    m_mainTimeline->setRepeatCount(1);
    
    if (direction == VCP_PAGE_DIRECTION_FROM_RIGHT || direction == VCP_PAGE_DIRECTION_FROM_BOTTOM)
    {
        m_mainTimeline->setFromValue(1);
        m_mainTimeline->setToValue(0);
    }
    else
    {
        m_mainTimeline->setFromValue(0);
        m_mainTimeline->setToValue(1);
    }
    m_mainTimeline->setDuration(duration);
    m_mainTimeline->m_signalStopped.connect(this, &VcpPage3DBrickFlipEffect::onEndOfEffect); 
    
    if (direction == VCP_PAGE_DIRECTION_FROM_UP || direction == VCP_PAGE_DIRECTION_FROM_BOTTOM)
    {
    	VfxCamera *camera = m_world->getActiveCamera();

        VfxMatrix4f mat = camera->getProjectionMatrix();
        VfxMatrix4f invMat = camera->getInverseProjectionMatrix();

        VfxFloat temp;
        temp = mat[0][0];
        mat[0][0] = mat[1][1];
        mat[1][1] = temp;


        temp = invMat[0][0];
        invMat[0][0] = invMat[1][1];
        invMat[1][1] = temp;

        camera->setGeneric(mat, invMat);
            
        camera->setRotationZ(VRT_PI_2);
    }

    VfxAnimation *anim;
    VFX_OBJ_CREATE(anim, VfxAnimation, m_world);

    VfxAssetLoader::loadAnimation(anim, m_world, VCP_ANI_PAGE_PANEL_BRICK);
    
    anim->setTimelineTime(m_mainTimeline);
    m_mainTimeline->start();

}


void VcpPage3DBrickFlipEffect::setupBox(const VfxString &name, VfxFrame *frameTexture1, VfxFrame *frameTexture2, VfxBool isRotate)
{
    VfxObject3D *obj = VfxAssetLoader::findObjByName(name);
    VfxMesh* box = VFX_OBJ_DYNAMIC_CAST(obj, VfxMesh);

    VfxMaterial *material;
    material = box->getMaterial(0);
    
    VfxPass *pass;
    pass = material->getPass(0);

    VfxShaderProgram *program = pass->getShaderProgram();
    if (isRotate)
    {
        VfxAssetSrc vs = program->getVertexShader();
        VFX_OBJ_CLOSE(program);
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, material, (vs, VfxAssetSrc(VCP_FRG_PAGE_PANEL_B1_FRAMETEX_ROTATE)));
        pass->setShaderProgram(program);
    }
    
    VfxShaderUniforms *uniforms;
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    pass->addShaderUniforms(uniforms);

    VfxTextureFrame *texture;
    VFX_OBJ_CREATE_EX(texture, VfxTextureFrame, var, (frameTexture2));
    var->setValue(texture);

    material = box->getMaterial(1);                
    pass = material->getPass(0);

    program = pass->getShaderProgram();
    if (isRotate)
    {
        VfxAssetSrc vs = program->getVertexShader();
        VFX_OBJ_CLOSE(program);
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, material, (vs, VfxAssetSrc(VCP_FRG_PAGE_PANEL_B1_FRAMETEX_ROTATE)));
        pass->setShaderProgram(program);
    }
    
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    pass->addShaderUniforms(uniforms);

    VFX_OBJ_CREATE_EX(texture, VfxTextureFrame, var, (frameTexture1));
    var->setValue(texture);
}


void VcpPage3DBrickFlipEffect::setupBoxByImageSrc(const VfxString &name, VfxImageSrc& frameTexture1, VfxImageSrc& frameTexture2, VfxBool isRotate)
{
    VfxObject3D *obj = VfxAssetLoader::findObjByName(name);
    VfxMesh* box = VFX_OBJ_DYNAMIC_CAST(obj, VfxMesh);

    VfxMaterial *material;
    material = box->getMaterial(0);
    
    VfxPass *pass;
    pass = material->getPass(0);

    VfxShaderProgram *program = pass->getShaderProgram();
    if (isRotate)
    {
        VfxAssetSrc vs = program->getVertexShader();
        VFX_OBJ_CLOSE(program);
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, material, (vs, VfxAssetSrc(VCP_FRG_PAGE_PANEL_B1_FRAMETEX_ROTATE)));
        pass->setShaderProgram(program);
    }
    
    VfxShaderUniforms *uniforms;
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    uniforms->addUniformVariable(VFX_STR("uFlip"), VFX_TYPE_ID_BOOL, 1)->setValue(VFX_FALSE);
    VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    pass->addShaderUniforms(uniforms);

    VfxImage2D *img;
    VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (frameTexture2));

    VfxTexture2D *texture;
    VFX_OBJ_CREATE_EX(texture, VfxTexture2D, var, (img));
    var->setValue(texture);

    material = box->getMaterial(1);                
    pass = material->getPass(0);

    program = pass->getShaderProgram();
    if (isRotate)
    {
        VfxAssetSrc vs = program->getVertexShader();
        VFX_OBJ_CLOSE(program);
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, material, (vs, VfxAssetSrc(VCP_FRG_PAGE_PANEL_B1_FRAMETEX_ROTATE)));
        pass->setShaderProgram(program);
    }
    
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    uniforms->addUniformVariable(VFX_STR("uFlip"), VFX_TYPE_ID_BOOL, 1)->setValue(VFX_FALSE);
    var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    pass->addShaderUniforms(uniforms);

    VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (frameTexture1));
    VFX_OBJ_CREATE_EX(texture, VfxTexture2D, var, (img));
    var->setValue(texture);
}


void VcpPage3DBrickFlipEffect::onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    if (lastFrame)
    {
        lastFrame->setHints(m_backupHint[0]);
    }
	if (currentFrame)
	{
		currentFrame->setHints(m_backupHint[1]);
	}
    VFX_OBJ_CLOSE(m_3dframe);
	VFX_OBJ_CLOSE(m_mainTimeline);
}


void VcpPage3DBrickFlipEffect::onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    if (lastFrame)
    {
        lastFrame->setHints(m_backupHint[0]);
    }
	if (currentFrame)
	{
		currentFrame->setHints(m_backupHint[1]);
	}
    VFX_OBJ_CLOSE(m_3dframe);
	VFX_OBJ_CLOSE(m_mainTimeline);
}


void VcpPage3DBrickFlipEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}

/*****************************************************************************
 * Class VcpPage3DTwistEffect
 *****************************************************************************/

VcpPage3DTwistEffect::VcpPage3DTwistEffect()
{
}


void VcpPage3DTwistEffect::onStart(
        VcpPagePanel *pagePanel,
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        )
{
    if (duration == -1)
    {
        duration = 250;
    }

    VfxBool useBuff = VFX_FALSE;

    if (data)
    {
        VFX_ASSERT(dataSize == sizeof(VcpPage3DImageBufferData));
        useBuff = VFX_TRUE;
    }
    
    if (currentFrame)
    {
        m_backupHint[0] = currentFrame->getHints();
        if (useBuff)
        {
            currentFrame->setHidden(VFX_TRUE);
        }
        else
        {
            currentFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);
        }
    }

    m_backupHint[1] = targetFrame->getHints();
    if (useBuff)
    {
        targetFrame->setHidden(VFX_TRUE);
    }
    else
    {
        targetFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);
    }
   
    VFX_OBJ_CREATE(m_3dframe, VfxFrame, pagePanel);
    m_3dframe->setSize(pagePanel->getSize());
    m_3dframe->setHidden(VFX_FALSE);

    /* World */
    VFX_OBJ_CREATE(m_world, VfxWorld, m_3dframe);
    m_3dframe->setWorld(m_world);

    if (useBuff)
    {
        VfxImageSrc frame1Src; 
    	VfxImageSrc frame2Src;
        VfxBool  isRotate = VFX_FALSE;

        VcpPage3DImageBufferData* bufferData = (VcpPage3DImageBufferData*) data;

        if (direction == VCP_PAGE_DIRECTION_FROM_RIGHT || direction == VCP_PAGE_DIRECTION_FROM_BOTTOM)
        {
            frame1Src = bufferData->newImageSrc;
            frame2Src = bufferData->oldImageSrc;
        }
        else
        {
            frame1Src = bufferData->oldImageSrc;
            frame2Src = bufferData->newImageSrc;
        }

        if (direction == VCP_PAGE_DIRECTION_FROM_UP || direction == VCP_PAGE_DIRECTION_FROM_BOTTOM)
        {
            isRotate = VFX_TRUE;
        }

        VfxAssetLoader::loadSceneBegin(m_world, VCP_SCN_PAGE_PANEL_TWIST);
        setupBoxByImageSrc(VFX_STR("Box001-node"), frame1Src, frame2Src, isRotate);
        VfxAssetLoader::loadSceneEnd();
    }
    else
    {
        VfxFrame *frame1; 
    	VfxFrame *frame2;
        VfxBool  isRotate = VFX_FALSE;

        if (direction == VCP_PAGE_DIRECTION_FROM_RIGHT || direction == VCP_PAGE_DIRECTION_FROM_BOTTOM)
        {
            frame1 = targetFrame;
            frame2 = currentFrame;
        }
        else
        {
            frame1 = currentFrame;
            frame2 = targetFrame;
        }

        if (direction == VCP_PAGE_DIRECTION_FROM_UP || direction == VCP_PAGE_DIRECTION_FROM_BOTTOM)
        {
            isRotate = VFX_TRUE;
        }

        VfxAssetLoader::loadSceneBegin(m_world, VCP_SCN_PAGE_PANEL_TWIST);
        setupBox(VFX_STR("Box001-node"), frame1, frame2, isRotate);
        VfxAssetLoader::loadSceneEnd();
    }


    VFX_OBJ_CREATE(m_mainTimeline, VfxFloatTimeline, this);
    m_mainTimeline->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_mainTimeline->setTarget(pagePanel);
    m_mainTimeline->setRepeatCount(1);
    
    if (direction == VCP_PAGE_DIRECTION_FROM_RIGHT || direction == VCP_PAGE_DIRECTION_FROM_BOTTOM)
    {
        m_mainTimeline->setFromValue(1);
        m_mainTimeline->setToValue(0);
    }
    else
    {
        m_mainTimeline->setFromValue(0);
        m_mainTimeline->setToValue(1);
    }
    m_mainTimeline->setDuration(duration);
    m_mainTimeline->m_signalStopped.connect(this, &VcpPage3DTwistEffect::onEndOfEffect); 

    if (direction == VCP_PAGE_DIRECTION_FROM_UP || direction == VCP_PAGE_DIRECTION_FROM_BOTTOM)
    {
    	VfxCamera *camera = m_world->getActiveCamera();

        VfxMatrix4f mat = camera->getProjectionMatrix();
        VfxMatrix4f invMat = camera->getInverseProjectionMatrix();

        VfxFloat temp;
        temp = mat[0][0];
        mat[0][0] = mat[1][1];
        mat[1][1] = temp;


        temp = invMat[0][0];
        invMat[0][0] = invMat[1][1];
        invMat[1][1] = temp;

        camera->setGeneric(mat, invMat);
            
        camera->setRotationZ(VRT_PI_2);
    }
    
    VfxAnimation *anim;
    VFX_OBJ_CREATE(anim, VfxAnimation, m_world);

    //VfxAssetLoader::loadAnimation(anim, m_world, VFX_WSTR("E:\\twist\\SSE-Twist.ani"));
    VfxAssetLoader::loadAnimation(anim, m_world, VCP_ANI_PAGE_PANEL_TWIST);
    
    anim->setTimelineTime(m_mainTimeline);
    m_mainTimeline->start();

}


void VcpPage3DTwistEffect::setupBox(const VfxString &name, VfxFrame *frameTexture1, VfxFrame *frameTexture2, VfxBool isRotate)
{
    VfxObject3D *obj = VfxAssetLoader::findObjByName(name);
    VfxMesh* box = VFX_OBJ_DYNAMIC_CAST(obj, VfxMesh);

    VfxMaterial *material;
    material = box->getMaterial(0);
    
    VfxPass *pass;
    pass = material->getPass(0);

    VfxShaderProgram *program = pass->getShaderProgram();
    if (isRotate)
    {
        VfxAssetSrc vs = program->getVertexShader();
        VFX_OBJ_CLOSE(program);
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, material, (vs, VfxAssetSrc(VCP_FRG_PAGE_PANEL_B1_FRAMETEX_ROTATE)));
        pass->setShaderProgram(program);
    }
    
    VfxShaderUniforms *uniforms;
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    pass->addShaderUniforms(uniforms);

    VfxTextureFrame *texture;
    VFX_OBJ_CREATE_EX(texture, VfxTextureFrame, var, (frameTexture1));
    var->setValue(texture);

    material = box->getMaterial(4);                
    pass = material->getPass(0);

    program = pass->getShaderProgram();
    if (isRotate)
    {
        VfxAssetSrc vs = program->getVertexShader();
        VFX_OBJ_CLOSE(program);
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, material, (vs, VfxAssetSrc(VCP_FRG_PAGE_PANEL_B1_FRAMETEX_ROTATE)));
        pass->setShaderProgram(program);
    }
    
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    pass->addShaderUniforms(uniforms);

    VFX_OBJ_CREATE_EX(texture, VfxTextureFrame, var, (frameTexture2));
    var->setValue(texture);
}


void VcpPage3DTwistEffect::setupBoxByImageSrc(const VfxString &name, VfxImageSrc& frameTexture1, VfxImageSrc& frameTexture2, VfxBool isRotate)
{
    VfxObject3D *obj = VfxAssetLoader::findObjByName(name);
    VfxMesh* box = VFX_OBJ_DYNAMIC_CAST(obj, VfxMesh);

    VfxMaterial *material;
    material = box->getMaterial(0);
    
    VfxPass *pass;
    pass = material->getPass(0);

    VfxShaderProgram *program = pass->getShaderProgram();
    if (isRotate)
    {
        VfxAssetSrc vs = program->getVertexShader();
        VFX_OBJ_CLOSE(program);
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, material, (vs, VfxAssetSrc(VCP_FRG_PAGE_PANEL_B1_FRAMETEX_ROTATE)));
        pass->setShaderProgram(program);
    }
    
    VfxShaderUniforms *uniforms;
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    uniforms->addUniformVariable(VFX_STR("uFlip"), VFX_TYPE_ID_BOOL, 1)->setValue(VFX_FALSE);
    VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    pass->addShaderUniforms(uniforms);

    VfxImage2D *img;
    VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (frameTexture1));

    VfxTexture2D *texture;
    VFX_OBJ_CREATE_EX(texture, VfxTexture2D, var, (img));
    var->setValue(texture);

    material = box->getMaterial(4);                
    pass = material->getPass(0);

    program = pass->getShaderProgram();
    if (isRotate)
    {
        VfxAssetSrc vs = program->getVertexShader();
        VFX_OBJ_CLOSE(program);
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, material, (vs, VfxAssetSrc(VCP_FRG_PAGE_PANEL_B1_FRAMETEX_ROTATE)));
        pass->setShaderProgram(program);
    }
    
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    uniforms->addUniformVariable(VFX_STR("uFlip"), VFX_TYPE_ID_BOOL, 1)->setValue(VFX_FALSE);
    var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    pass->addShaderUniforms(uniforms);

    VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (frameTexture2));
    VFX_OBJ_CREATE_EX(texture, VfxTexture2D, var, (img));
    var->setValue(texture);
}



void VcpPage3DTwistEffect::onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    if (lastFrame)
    {
        lastFrame->setHints(m_backupHint[0]);
    }
	if (currentFrame)
	{
		currentFrame->setHints(m_backupHint[1]);
	}
    VFX_OBJ_CLOSE(m_3dframe);
	VFX_OBJ_CLOSE(m_mainTimeline);
}


void VcpPage3DTwistEffect::onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    if (lastFrame)
    {
        lastFrame->setHints(m_backupHint[0]);
    }
	if (currentFrame)
	{
		currentFrame->setHints(m_backupHint[1]);
	}
    VFX_OBJ_CLOSE(m_3dframe);
	VFX_OBJ_CLOSE(m_mainTimeline);
}


void VcpPage3DTwistEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}


/*****************************************************************************
 * Class VcpPage3DCurlEffect
 *****************************************************************************/
static VfxFloat timingFuncCallback(VfxFloat t, void *data, VfxU32 dataSize)
{

	vrt_float s;
    vrt_float c = 0.5;

           
	s = vrt_sqrt(4 * c * t);


    // to prevent error when the timeline is ended, t = 1.0f must be mapped to 1.0f
    if (s >= 1.0f)
    {
        s =  1.0f;
    }
	return s;

}
VcpPage3DCurlEffect::VcpPage3DCurlEffect():
    m_leftPageCurlThetaTl(NULL),
    m_rightPageCurlThetaTl(NULL),   
    m_leftPageCurlRhoTl(NULL),
    m_rightPageCurlRhoTl(NULL),   
    m_leftFrame(NULL),
    m_rightFrame(NULL),
    m_target(NULL)
{
}


void VcpPage3DCurlEffect::onStart(
        VcpPagePanel *pagePanel,
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        )
{
   
                

    VfxBool inverse = VFX_FALSE;
    VfxFloat ThetaFrom, ThetaTo;
    VfxFloat RhoFrom, RhoTo;

    if(data)
    {
        VFX_ASSERT(dataSize == sizeof(VcpPage3DCurlEffectData));
        VcpPage3DCurlEffectData *userdata = (VcpPage3DCurlEffectData*) data;
        inverse = userdata->inverse;        
    }


    if(inverse)
    {
        m_target = targetFrame;
        ThetaFrom = VFX_PI / 10.0f;
        ThetaTo = VFX_PI / 2.5f;
        RhoFrom = VFX_PI / 2.0f;
        RhoTo = 0.0;        
    }
    else
    {
        m_target = currentFrame;
        ThetaFrom = VFX_PI / 2.5f;
        ThetaTo = VFX_PI / 10.0f;
        RhoFrom = 0.0;
        RhoTo = VFX_PI / 2.0f;

    }

    if (m_target == NULL)
    {
        return;
    }

    
    m_backupHint = m_target->getHints();
    m_target->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);


    VfxS32 w = pagePanel->getSize().width;
    VfxS32 h = pagePanel->getSize().height;

    if (duration == -1)
    {
        duration = 250;
    }
    if (m_leftPageCurlThetaTl == NULL)
    {
        VFX_OBJ_CREATE(m_leftPageCurlThetaTl, VfxFloatTimeline, this);
    }    
    if (m_rightPageCurlThetaTl == NULL)
    {
        VFX_OBJ_CREATE(m_rightPageCurlThetaTl, VfxFloatTimeline, this);
    }
    if (m_leftPageCurlRhoTl == NULL)
    {
        VFX_OBJ_CREATE(m_leftPageCurlRhoTl, VfxFloatTimeline, this);
    }    
    if (m_rightPageCurlRhoTl == NULL)
    {
        VFX_OBJ_CREATE(m_rightPageCurlRhoTl, VfxFloatTimeline, this);
    }

    if (m_leftFrame == NULL)
    {        
        VFX_OBJ_CREATE(m_leftFrame, VfxFrame, pagePanel);
        if(direction == VCP_PAGE_DIRECTION_FROM_UP || direction == VCP_PAGE_DIRECTION_FROM_BOTTOM)            
        {
            m_leftFrame->setRect(0,0, w/2, h);    

        }
        else
        {
            m_leftFrame->setRect(0,0, w, h/2);            
        }      
        m_leftFrame->setHidden(VFX_FALSE);
//        m_leftFrame->setBgColor(VFX_COLOR_GREEN);            
    }
    
    if (m_rightFrame == NULL)
    {        
        VFX_OBJ_CREATE(m_rightFrame, VfxFrame, pagePanel);
        if(direction == VCP_PAGE_DIRECTION_FROM_UP || direction == VCP_PAGE_DIRECTION_FROM_BOTTOM)            
        {
            //m_rightFrame->setRect(-pagePanel->getPos().x +w/2,-pagePanel->getPos().y, w/2, h);
			m_rightFrame->setRect(w/2,0, w/2, h);
        }
        else
        {
            //m_rightFrame->setRect(-pagePanel->getPos().x,-pagePanel->getPos().y+h/2, w, h/2);
			m_rightFrame->setRect(0,h/2, w, h/2);
        }      
        m_rightFrame->setHidden(VFX_FALSE);
//        m_rightFrame->setBgColor(VFX_COLOR_PURPLE);

    }               
    
    VfxMaterial *material;
    VfxPass *pass;
    VfxShaderProgram *program;
    VfxCompositingMode *cm;
    VfxShaderUniforms *uniforms;
    VfxTextureFrame *texture;

    VfxShaderVariable *var; 
   

    // Material
    VFX_OBJ_CREATE(material, VfxMaterial, m_leftFrame);
    m_leftFrame->setMaterial(material);

    // Pass
    VFX_OBJ_CREATE(pass, VfxPass, material);
    material->setPass(0, pass);
    pass->setTessellationLevel(w/20, h/20);

    // Shader Program
    if(direction == VCP_PAGE_DIRECTION_FROM_UP || direction == VCP_PAGE_DIRECTION_FROM_BOTTOM)            
    {
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VCP_VTX_PAGE_PANEL_CURL_D, VCP_FRG_PAGE_PANEL_CURL_D));
 //       VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR("d:\\test\\shader\\vcp_page_panel_curl_d.vs"), VFX_WSTR("d:\\test\\shader\\vcp_page_panel_curl_d.fs")));

    }
    else
    {

        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VCP_VTX_PAGE_PANEL_CURL_L, VCP_FRG_PAGE_PANEL_CURL_L));
 //         VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR("d:\\test\\shader\\vcp_page_panel_curl_l.vs"), VFX_WSTR("d:\\test\\shader\\vcp_page_panel_curl_l.fs")));

    }  
    
    
    pass->setShaderProgram(program);

    
    VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
    pass->setCompositingMode(cm);
    cm->setDepthTestEnable(VFX_TRUE);
    cm->setDepthWriteEnable(VFX_TRUE);

    
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    pass->addShaderUniforms(uniforms);

    
    VFX_OBJ_CREATE_EX(texture, VfxTextureFrame, m_leftFrame, (m_target.get()));
    uniforms->addUniformVariable(VFX_STR("baseTex"), VFX_TYPE_ID_SAMPLER, 1)->setValue(texture);
           
    var = uniforms->addUniformVariable(VFX_STR("theta"), VFX_TYPE_ID_FLOAT, 1);

    m_leftPageCurlThetaTl->setTarget(var);
    m_leftPageCurlThetaTl->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT);
    if(!inverse)
		m_leftPageCurlThetaTl->setCustomTimingFunc(timingFuncCallback, NULL, 0);
//    m_leftPageCurlTimeLine->setStartDelay(300);
    m_leftPageCurlThetaTl->setDurationTime(duration);
//    m_leftPageCurlTimeLine->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
    m_leftPageCurlThetaTl->setRepeatCount(1);       
    m_leftPageCurlThetaTl->setFromValue(ThetaFrom);         
    m_leftPageCurlThetaTl->setToValue(ThetaTo);    
    m_leftPageCurlThetaTl->m_signalStopped.connect(this, &VcpPage3DCurlEffect::onEndOfEffect); 
    m_leftPageCurlThetaTl->start();
                   

   var = uniforms->addUniformVariable(VFX_STR("rho"), VFX_TYPE_ID_FLOAT, 1);

   m_leftPageCurlRhoTl->setTarget(var);
   m_leftPageCurlRhoTl->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT);
//    m_leftPageCurlTimeLine->setStartDelay(300);
   m_leftPageCurlRhoTl->setDurationTime(duration);
//    m_leftPageCurlTimeLine->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
   m_leftPageCurlRhoTl->setRepeatCount(1);       
   m_leftPageCurlRhoTl->setFromValue(RhoFrom);         
   m_leftPageCurlRhoTl->setToValue(RhoTo);    
   m_leftPageCurlRhoTl->start();




   // Material
    VFX_OBJ_CREATE(material, VfxMaterial, m_rightFrame);
    m_rightFrame->setMaterial(material);

    // Pass
    VFX_OBJ_CREATE(pass, VfxPass, material);
    material->setPass(0, pass);
    pass->setTessellationLevel(w/20, h/20);

      // Shader Program
    if(direction == VCP_PAGE_DIRECTION_FROM_UP || direction == VCP_PAGE_DIRECTION_FROM_BOTTOM)            
    {
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VCP_VTX_PAGE_PANEL_CURL_U, VCP_FRG_PAGE_PANEL_CURL_U));
 //       VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR("d:\\test\\shader\\vcp_page_panel_curl_u.vs"), VFX_WSTR("d:\\test\\shader\\vcp_page_panel_curl_u.fs")));

    }
    else
    {
        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VCP_VTX_PAGE_PANEL_CURL_R, VCP_FRG_PAGE_PANEL_CURL_R));
//        VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_WSTR("d:\\test\\shader\\vcp_page_panel_curl_r.vs"), VFX_WSTR("d:\\test\\shader\\vcp_page_panel_curl_r.fs")));
    }  

    pass->setShaderProgram(program);


    VFX_OBJ_CREATE(cm, VfxCompositingMode, pass);
    pass->setCompositingMode(cm);
    cm->setDepthTestEnable(VFX_TRUE);
    cm->setDepthWriteEnable(VFX_TRUE);


    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    pass->addShaderUniforms(uniforms);


    VFX_OBJ_CREATE_EX(texture, VfxTextureFrame, m_rightFrame, (m_target.get()));
    uniforms->addUniformVariable(VFX_STR("baseTex"), VFX_TYPE_ID_SAMPLER, 1)->setValue(texture);

    var = uniforms->addUniformVariable(VFX_STR("theta"), VFX_TYPE_ID_FLOAT, 1);

    m_rightPageCurlThetaTl->setTarget(var);
    m_rightPageCurlThetaTl->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT);
	if(!inverse)
		m_rightPageCurlThetaTl->setCustomTimingFunc(timingFuncCallback, NULL, 0);
    
//    m_rightPageCurlThetaTl->setStartDelay(800);
    m_rightPageCurlThetaTl->setDurationTime(duration);
//    m_rightPageCurlThetaTl->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
    m_rightPageCurlThetaTl->setRepeatCount(1);       
    m_rightPageCurlThetaTl->setFromValue(ThetaFrom);             
    m_rightPageCurlThetaTl->setToValue(ThetaTo);  

    m_rightPageCurlThetaTl->start();

    
   var = uniforms->addUniformVariable(VFX_STR("rho"), VFX_TYPE_ID_FLOAT, 1);

   m_rightPageCurlRhoTl->setTarget(var);
   m_rightPageCurlRhoTl->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT);
   
//    m_leftPageCurlTimeLine->setStartDelay(300);
   m_rightPageCurlRhoTl->setDurationTime(duration);
//    m_leftPageCurlTimeLine->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
   m_rightPageCurlRhoTl->setRepeatCount(1);       
   m_rightPageCurlRhoTl->setFromValue(RhoFrom);         
   m_rightPageCurlRhoTl->setToValue(RhoTo);    
   m_rightPageCurlRhoTl->start();


}


void VcpPage3DCurlEffect::onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    VFX_UNUSED(lastFrame);
    VFX_UNUSED(currentFrame);

    
	if (m_target.get())
	{
		m_target.get()->setHints(m_backupHint);
	}

    VFX_OBJ_CLOSE(m_leftPageCurlThetaTl);
    VFX_OBJ_CLOSE(m_rightPageCurlThetaTl);
    VFX_OBJ_CLOSE(m_leftPageCurlRhoTl);
    VFX_OBJ_CLOSE(m_rightPageCurlRhoTl);

    VFX_OBJ_CLOSE(m_leftFrame);
    VFX_OBJ_CLOSE(m_rightFrame);

}
void VcpPage3DCurlEffect::onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    VFX_UNUSED(pagePanel);
    VFX_UNUSED(lastFrame);
    VFX_UNUSED(currentFrame);
	if (m_target.get())
	{
		m_target.get()->setHints(m_backupHint);
	}

    VFX_OBJ_CLOSE(m_leftPageCurlThetaTl);
    VFX_OBJ_CLOSE(m_rightPageCurlThetaTl);
    VFX_OBJ_CLOSE(m_leftPageCurlRhoTl);
    VFX_OBJ_CLOSE(m_rightPageCurlRhoTl);

    VFX_OBJ_CLOSE(m_leftFrame);
    VFX_OBJ_CLOSE(m_rightFrame);
  
}


void VcpPage3DCurlEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}


/*****************************************************************************
 * Class VcpPage3DFusionEffect
 *****************************************************************************/
VcpPage3DFusionEffect::VcpPage3DFusionEffect():
    m_animTimeline(NULL),
    m_effectFrame(NULL)
{
}

void VcpPage3DFusionEffect::onStart(
    VcpPagePanel *pagePanel, 
    VfxFrame *currentFrame, 
    VfxFrame *targetFrame, 
    VfxMsec duration, 
    VcpPageEffectTypeDirection direction,
    void *data, 
    VfxS32 dataSize
    )
{

    if (duration == -1)
    {
        duration = 1000;
    }

    VFX_OBJ_CLOSE(m_effectFrame);
    VFX_OBJ_CREATE(m_effectFrame, VfxFrame, pagePanel);
    m_effectFrame->setPos(0, 0);
    m_effectFrame->setSize(pagePanel->getSize());
    m_effectFrame->setBgColor(VFX_COLOR_BLACK);
    m_effectFrame->setOpacity(1.0);
    m_effectFrame->setHidden(VFX_FALSE);

    // make sure all frames are visible & opaque.
    // they must be opaque for VfxTextureFrame to work.
    if(currentFrame)
    {
        m_backupHint[0] = currentFrame->getHints();
        currentFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);
    }
    if(targetFrame)
    {
        m_backupHint[1] = targetFrame->getHints();
        targetFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);
    }

    // set proper z-order
    m_effectFrame->bringToFront();

    VfxMaterial *material;
    VFX_OBJ_CREATE(material, VfxMaterial, m_effectFrame);
    m_effectFrame->setMaterial(material);
    
    // Pass
    VfxPass *pass;
    VFX_OBJ_CREATE_EX(pass, VfxPass, material, (VFX_PASS_GEOMETRY_DEFAULT));
    material->setPass(0, pass);
    
    // Shader Program
    VfxShaderProgram *program;
    VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VFX_RES_ID_NULL, VCP_FRG_PAGE_PANEL_FUSION));
    pass->setShaderProgram(program);

    VfxShaderUniforms *uniforms;
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    pass->addShaderUniforms(uniforms);

    VfxShaderVariable *var;
    var = uniforms->addUniformVariable(VFX_STR("u_effectTime"), VFX_TYPE_ID_FLOAT, 1);
    var->setValue(0.0f);

    if(NULL == m_animTimeline)
    {
        VFX_OBJ_CREATE(m_animTimeline, VfxFloatTimeline, this);
    }
    m_animTimeline->setTarget(var);
    m_animTimeline->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT);
    m_animTimeline->m_signalStopped.connect(this, &VcpPage3DFusionEffect::onEndOfEffect);
    m_animTimeline->setDurationTime(duration);
    m_animTimeline->setFromValue(0.0f);
    m_animTimeline->setToValue(1.0f);
    m_animTimeline->start();
    
    // Textures
    var = uniforms->addUniformVariable(VFX_STR("u_texFrom"), VFX_TYPE_ID_SAMPLER, 1);
    VfxTextureFrame *texFrom;
    VFX_OBJ_CREATE_EX(texFrom, VfxTextureFrame, var, (currentFrame));
    var->setValue(texFrom);
    
    var = uniforms->addUniformVariable(VFX_STR("u_texTo"), VFX_TYPE_ID_SAMPLER, 1);
    VfxTextureFrame *texTo;
    VFX_OBJ_CREATE_EX(texTo, VfxTextureFrame, var, (targetFrame));
    var->setValue(texTo);
    
    var = uniforms->addUniformVariable(VFX_STR("u_texMask"), VFX_TYPE_ID_SAMPLER, 1);
    VfxImage2D *img;
    VfxTexture2D *tex2D;
    VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (IMG_ID_VCP_PAGE_PANEL_FUSION));
    VFX_OBJ_CREATE_EX(tex2D, VfxTexture2D, var, (img));
    var->setValue(tex2D);
}  

void VcpPage3DFusionEffect::onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    if (lastFrame)
    {
        lastFrame->setHints(m_backupHint[0]);
    }
    if (currentFrame)
    {
        currentFrame->setHints(m_backupHint[1]);
    }

    if (m_animTimeline)
    {
        m_animTimeline->stop();
    }

    if(m_effectFrame)
    {
        m_effectFrame->setMaterial(NULL);
    }
    
    VFX_OBJ_CLOSE(m_effectFrame);
}

void VcpPage3DFusionEffect::onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    if (lastFrame)
    {
        lastFrame->setHints(m_backupHint[0]);
    }
    if (currentFrame)
    {
        currentFrame->setHints(m_backupHint[1]);
    }

    if (m_animTimeline)
    {
        m_animTimeline->stop();
    }

    if(m_effectFrame)
    {
        m_effectFrame->setMaterial(NULL);
    }

    VFX_OBJ_CLOSE(m_effectFrame);
}

void VcpPage3DFusionEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    
    if(isCompleted)
    {
        m_complete.emit();
    }
}


/*****************************************************************************
 * Class VcpPageRipple3DEffect
 *****************************************************************************/

#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_shader.h"
#include "vfx_shader_uniforms.h"
#include "vfx_render_buffer.h"
#include "vfx_texture.h"

VcpPage3DRippleEffect::VcpPage3DRippleEffect():
    m_material(NULL)
{
}

void VcpPage3DRippleEffect::onStart(
        VcpPagePanel *pagePanel,
        VfxFrame *currentFrame, 
        VfxFrame *targetFrame, 
        VfxMsec duration, 
        VcpPageEffectTypeDirection direction,
        void *data, 
        VfxS32 dataSize
        )
{
    VFX_ASSERT(m_material == NULL);
    m_material = createRippleMaterial(targetFrame, currentFrame);
    targetFrame->setMaterial(m_material);

    if (currentFrame)
    {
        m_backupHint[0] = currentFrame->getHints();
        currentFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);
    }

    m_backupHint[1] = targetFrame->getHints();
    targetFrame->setHints(VFX_FRAME_HINTS_TEXTURE);

    if (m_rippleTimeline)
    {
        m_rippleTimeline->m_signalStopped.connect(this, &VcpPage3DRippleEffect::onEndOfEffect); 
    }
}

void VcpPage3DRippleEffect::onStop(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    if (lastFrame)
    {
        lastFrame->setHints(m_backupHint[0]);
    }
    if (currentFrame)
    {
        currentFrame->setHints(m_backupHint[1]);
    }

    if (m_transTimeline)
    {
        m_transTimeline->stop();
        m_rippleTimeline->stop();
        m_zTimeline->stop();
        m_transTimeline->stop();
        m_rippleTimeline->stop();
        m_zTimeline->stop();
        VFX_OBJ_CLOSE(m_transTimeline);
        VFX_OBJ_CLOSE(m_rippleTimeline);
        VFX_OBJ_CLOSE(m_zTimeline);
    }
    if (currentFrame)
    {
        currentFrame->setMaterial(NULL);
    }
    VFX_OBJ_CLOSE(m_material);
}


void VcpPage3DRippleEffect::onCancel(VcpPagePanel *pagePanel, VfxFrame *lastFrame, VfxFrame *currentFrame)
{
    if (lastFrame)
    {
        lastFrame->setHints(m_backupHint[0]);
    }
    if (currentFrame)
    {
        currentFrame->setHints(m_backupHint[1]);
    }

    if (m_transTimeline)
    {
        m_transTimeline->stop();
        m_rippleTimeline->stop();
        m_zTimeline->stop();
        VFX_OBJ_CLOSE(m_transTimeline);
        VFX_OBJ_CLOSE(m_rippleTimeline);
        VFX_OBJ_CLOSE(m_zTimeline);
    }
    if (currentFrame)
    {
        currentFrame->setMaterial(NULL);
    }
    VFX_OBJ_CLOSE(m_material);
}

void VcpPage3DRippleEffect::onEndOfEffect(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_complete.emit();
    }
}

VfxMaterial * VcpPage3DRippleEffect::createRippleMaterial(VfxFrame * target, VfxFrame * frameTexture)
{
    VfxMaterial *material;
    // Material (1 pass rendering)
    VFX_OBJ_CREATE_EX(material, VfxMaterial, this, (1));

    // Pass 1
    VfxPass *pass;
    VFX_OBJ_CREATE(pass, VfxPass, material);
    material->setPass(0, pass);

    VfxShaderProgram *program;
    VFX_OBJ_CREATE_EX(program, VfxShaderProgram, pass, (VfxResId(0), VCP_FRG_PAGE_PANEL_RIPPLE));
    pass->setShaderProgram(program);

    VfxShaderUniforms *uniforms;
    VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
    pass->addShaderUniforms(uniforms);

    // set animated uniform
    VfxShaderVariable *var1;
    var1 = uniforms->addUniformVariable(VFX_STR("u_RippleTime"), VFX_TYPE_ID_FLOAT, 1);
    VFX_OBJ_CREATE(m_rippleTimeline, VfxFloatTimeline, var1);
    m_rippleTimeline->setTarget(var1);
    m_rippleTimeline->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT);
    m_rippleTimeline->setDurationTime(RIPPLE_DURATION);
    m_rippleTimeline->setFromValue(0.0f);
    m_rippleTimeline->setToValue(1.0f);
    m_rippleTimeline->start();

    VFX_OBJ_CREATE(m_zTimeline, VfxFloatTimeline, var1);
    m_zTimeline->setTarget(target);
    m_zTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_Z);
    m_zTimeline->setDurationTime(RIPPLE_DURATION);
    m_zTimeline->setFromValue(0.0f);
    m_zTimeline->setToValue(1.0f);
    m_zTimeline->start();

    VfxShaderVariable *var2;
    var2 = uniforms->addUniformVariable(VFX_STR("u_TransPic"), VFX_TYPE_ID_FLOAT, 1);
    VFX_OBJ_CREATE(m_transTimeline, VfxFloatTimeline, var2);
    m_transTimeline->setTarget(var2);
    m_transTimeline->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_FLOAT);
    m_transTimeline->setDurationTime(RIPPLE_DURATION);
    m_transTimeline->setFromValue(0.0f);
    m_transTimeline->setToValue(1.0f);
    m_transTimeline->start();

    if (frameTexture)
    {
        VfxTextureFrame *texture;
        VFX_OBJ_CREATE_EX(texture, VfxTextureFrame, pass, (frameTexture));
        uniforms->addUniformVariable(VFX_STR("u_StartPic"), VFX_TYPE_ID_SAMPLER, 1)->setValue(texture);
    }
    else
    {
        VfxImageBuffer imageBuf;
        m_imageBuffer[0] = 0;
        imageBuf.ptr = (VfxU8*)&m_imageBuffer[0];
        imageBuf.pitchBytes = 4;
        imageBuf.width = 1;
        imageBuf.height = 1;
        imageBuf.colorFormat = VRT_COLOR_TYPE_ARGB8888;

        VfxImageSrc startImageSrc(imageBuf);
        
        VfxImage2D *image;
        VfxTexture *tex;
        VFX_OBJ_CREATE_EX(image, VfxImage2D, material, (startImageSrc) );
        VFX_OBJ_CREATE_EX(tex, VfxTexture2D, pass, (image));
        uniforms->addUniformVariable(VFX_STR("u_StartPic"), VFX_TYPE_ID_SAMPLER, 1)->setValue(tex);
    }

    return material;
}


#endif /* defined(__COSMOS_3D_V10__) || defined(__PLUTO_3D_V10__) */
