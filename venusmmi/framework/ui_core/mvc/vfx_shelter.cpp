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
 *  vfx_shelter.cpp
 *
 * Project:
 * --------
 *  Venus
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
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

#include "vfx_shelter.h"
#include "vcp_frame_effect.h"

#include "vadp_sys_trc.h"
//#include "fs_type.h"
//#include "fs_func.h"


#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

extern "C"
{
// For GetString(), GetBinary()
#include "CustDataRes.h"
#include "app_mem_med.h"
#ifdef __MAUI_SOFTWARE_LA__
    #include "SST_sla.h"
#endif
} // extern "C"


#define VFX_SHELTER_ANIM_DURATION 300
#define VFX_SHELTER_BLUR_DARKNESS 0.7f


#ifdef __COSMOS_3D_V10_SHELTER__

#define GL_CHECK_ERROR
    
#ifdef GL_CHECK_ERROR
    #define GL_CHECK(x) \
                x; \
                { \
                    GLenum glError = glGetError(); \
                    VRT_EXT_ASSERT(glError == GL_NO_ERROR, glError, glError, glError); \
                }
#else
    #define GL_CHECK(x)    x;
#endif


#ifdef GL_CHECK_ERROR
    #define GL_CHECK_MEM(x) \
                x; \
                { \
                    GLenum glError = glGetError(); \
                    if(glError == GL_OUT_OF_MEMORY) \
                    { \
                        vrt_oom_free_discardable_resource(); \
                        x; \
                        glError = glGetError(); \
                        VRT_EXT_ASSERT(glError == GL_NO_ERROR, glError, glError, glError); \
                    } \
                }
#else
    #define GL_CHECK_MEM(x)    x;
#endif

GLuint VfxShelterLoadShader(GLenum type, const U16 resId)
{
    GLuint shader;
    GLint compiled;
    U32 size = 0;
    char *shaderSrc = NULL;
    vrt_bool isBinary = VRT_FALSE;

    // Create the shader object
    shader = glCreateShader(type);

    if(shader == 0)
    {
        return 0;
    }

    // TODO: implement vrt_sys_res_shader_lock
    //shaderSrc = (vrt_char *)vrt_sys_res_shader_lock(vrtshader->getResourceId());

    const char *start = (const char*)GetBinary(resId);
    if(start == NULL)
    {
        return 0;
    }
    /* first byte is type, 2~5 is size */
    const unsigned char *header = (const unsigned char*)start;
    size = *((U32*)(header+1));
    //   size = header[1] | header[2] << 8 | header[3] << 16 | header[4] << 24;
    start += 8;

#ifndef __MTK_TARGET__
    char *source = (char *)applib_asm_alloc_anonymous_nc(sizeof(char) * (size + 1));
    memcpy(source, start, size);

    // WORKAROUND: add null-terminal after source from res
    source[size] = 0;
    shaderSrc = source;
#else
    shaderSrc = (vrt_char*)start;
    isBinary = VRT_TRUE;
#endif

    if (isBinary)
    {
        GLenum MALI_SHADER_BINARY_ARM = 0x8F60;
        GL_CHECK(glShaderBinary(1, &shader, MALI_SHADER_BINARY_ARM, (const void* )shaderSrc, size));
    }
    else
    {
        // Load the shader source
        GL_CHECK(glShaderSource(shader, 1, (const char **)&shaderSrc, NULL));

        // Compile the shader
        GL_CHECK(glCompileShader(shader ) );

        // Check the compile status
        GL_CHECK(glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled));

        if (!compiled)
        {
            GL_CHECK(glDeleteShader(shader));
            return 0;
        }
    }

    return shader;
}

GLuint VfxShelterCreateTexture2D(VfxS32 width, VfxS32 height)
{
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("ShC", SA_start);
#endif 


    // Texture object handle
    GLuint textureId;

    // Use tightly packed data
    GL_CHECK(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));

    // Generate a texture object
    GL_CHECK(glGenTextures(1, &textureId));


    // Bind the texture object
    GL_CHECK(glBindTexture(GL_TEXTURE_2D, textureId));

    // Set the filtering mode
    GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR));
    GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

    GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
    GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));


        GL_CHECK_MEM( glCopyTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 0, 0, width, height, 0) );

#ifdef __MAUI_SOFTWARE_LA__
           SLA_CustomLogging("ShC", SA_stop);
#endif 


   return textureId;

}


VfxShelterOwnerDraw::VfxShelterOwnerDraw(VfxSize size):	
    m_size(size),
    m_forceCopy(VFX_FALSE)
{    
    memset(&m_dataH, 0, sizeof(m_dataH));
    memset(&m_dataV, 0, sizeof(m_dataV));
}


    
void VfxShelterOwnerDraw::onInitResource()
{      
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("ShI", SA_start);
#endif 

    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint programObject;
    GLint linked;
    VFX_LOG(VFX_INFO, VFX_SHELTER_INIT_RESOURCE_START, this, m_dataH.programObject, m_dataH.frameBuffer, m_dataH.textureBuffer, m_dataV.programObject);

    m_forceCopy = VFX_FALSE;
    memset(&m_dataH, 0, sizeof(m_dataH));
    memset(&m_dataV, 0, sizeof(m_dataV));

    // Load the vertex/fragment shaders
    vertexShader = VfxShelterLoadShader(GL_VERTEX_SHADER, VFX_VTX_SHELTER_BLUR);
    fragmentShader = VfxShelterLoadShader(GL_FRAGMENT_SHADER, VFX_FRG_SHELTER_BLUR_H);

    // Create the program object
    programObject = GL_CHECK(glCreateProgram());

    VFX_DEV_ASSERT(programObject);

    GL_CHECK_ERROR(glAttachShader(programObject, vertexShader));
    GL_CHECK_ERROR(glAttachShader(programObject, fragmentShader));


    // Link the program
    GL_CHECK(glLinkProgram(programObject));

    // Check the link status
    GL_CHECK(glGetProgramiv(programObject, GL_LINK_STATUS, &linked));

    if ( !linked )
    {
        GL_CHECK_ERROR(glDeleteProgram(programObject));
        VFX_DEV_ASSERT(0);
    }

    GL_CHECK_ERROR(glDeleteShader(fragmentShader));


    m_dataH.uViewPortSizeLoc = GL_CHECK(glGetUniformLocation(programObject, "uViewportSize"));
    m_dataH.uFrameAnchorLoc = GL_CHECK(glGetUniformLocation(programObject, "uFrameAnchor"));
    m_dataH.aPositionLoc = GL_CHECK(glGetAttribLocation(programObject, "aPosition"));
    m_dataH.aTexCoordLoc = GL_CHECK(glGetAttribLocation(programObject, "aTexCoord"));

    m_dataH.uBaseTexLoc = GL_CHECK(glGetUniformLocation(programObject, "uBaseTex"));
    m_dataH.uBaseTexSizeLoc = GL_CHECK(glGetUniformLocation(programObject, "uBaseTexSize"));
    m_dataH.uLevelLoc = GL_CHECK(glGetUniformLocation(programObject, "uLevel"));


    GL_CHECK(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));
    GL_CHECK(glGenFramebuffers(1, &m_dataH.frameBuffer));

    m_dataH.programObject = programObject;

    fragmentShader = VfxShelterLoadShader(GL_FRAGMENT_SHADER, VFX_FRG_SHELTER_BLUR_V);

    // Create the program object
    programObject = GL_CHECK(glCreateProgram());

    VFX_DEV_ASSERT(programObject);

    GL_CHECK(glAttachShader(programObject, vertexShader));
    GL_CHECK(glAttachShader(programObject, fragmentShader));


    // Link the program
    GL_CHECK(glLinkProgram(programObject));

    // Check the link status
    GL_CHECK(glGetProgramiv(programObject, GL_LINK_STATUS, &linked));

    if ( !linked )
    {
        GL_CHECK_ERROR(glDeleteProgram(programObject));
        VFX_DEV_ASSERT(0);
    }

    GL_CHECK(glDeleteShader(vertexShader));
    GL_CHECK(glDeleteShader(fragmentShader));         

    m_dataV.uViewPortSizeLoc = GL_CHECK(glGetUniformLocation(programObject, "uViewportSize"));       
    m_dataV.uFrameAnchorLoc = GL_CHECK(glGetUniformLocation( programObject, "uFrameAnchor"));
    m_dataV.aPositionLoc = GL_CHECK(glGetAttribLocation(programObject, "aPosition"));
    m_dataV.aTexCoordLoc = GL_CHECK(glGetAttribLocation(programObject, "aTexCoord"));

    m_dataV.uBaseTexLoc = GL_CHECK(glGetUniformLocation(programObject, "uBaseTex"));
    m_dataV.uBaseTexSizeLoc = GL_CHECK(glGetUniformLocation(programObject, "uBaseTexSize"));
    m_dataV.uLevelLoc = GL_CHECK(glGetUniformLocation(programObject, "uLevel"));
    m_dataV.uDarknessLoc= GL_CHECK(glGetUniformLocation(programObject, "uDarkness"));
    m_dataV.uFrameTexLoc= GL_CHECK(glGetUniformLocation(programObject, "uFrameTex"));         
    m_dataV.programObject = programObject;

    VFX_LOG(VFX_INFO, VFX_SHELTER_INIT_RESOURCE_END, this, m_dataH.programObject, m_dataH.frameBuffer, m_dataH.textureBuffer, m_dataV.programObject);
    
    
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("ShI", SA_stop);
#endif   

}

void VfxShelterOwnerDraw::onDeinitResource()
{
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("ShD", SA_start);
#endif     

    VFX_LOG(VFX_INFO, VFX_SHELTER_DEINIT_RESOURCE_START, this, m_dataH.programObject, m_dataH.frameBuffer, m_dataH.textureBuffer, m_dataV.programObject);

    glDeleteFramebuffers(1, &m_dataH.frameBuffer);
    if (m_dataH.textureBuffer)
    {
        glDeleteTextures(1, &m_dataH.textureBuffer);
        m_dataH.textureBuffer = 0;
    }

    if (m_dataH.textureId)
    {
        glDeleteTextures(1, &m_dataH.textureId);
        m_dataH.textureId = 0;
    }

    if (m_dataH.programObject)
    {
        glDeleteProgram(m_dataH.programObject);
        m_dataH.programObject = 0;
    }
    if (m_dataV.programObject)
    {
        glDeleteProgram(m_dataV.programObject);
        m_dataV.programObject = 0;
    }           
    m_forceCopy = VFX_FALSE;
    memset(&m_dataH, 0, sizeof(m_dataH));
    memset(&m_dataV, 0, sizeof(m_dataV));
    
    
    VFX_LOG(VFX_INFO, VFX_SHELTER_DEINIT_RESOURCE_END, this, m_dataH.programObject, m_dataH.frameBuffer, m_dataH.textureBuffer, m_dataV.programObject);

#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("ShD", SA_stop);
#endif     
}

void VfxShelterOwnerDraw::bindStrokeFramebuffer(VfxSize texSize)
{
    if (m_dataH.textureBuffer && m_dataH.textureSize != texSize)
    {
        glDeleteTextures(1, &m_dataH.textureBuffer);
        m_dataH.textureBuffer = 0;
    }

    if (m_dataH.textureBuffer == 0)
    {
        GL_CHECK(glGenTextures(1,&m_dataH.textureBuffer));
        m_dataH.textureSize = texSize;
        
        GL_CHECK(glBindTexture(GL_TEXTURE_2D, m_dataH.textureBuffer));
        GL_CHECK_MEM(glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_dataH.textureSize.width , m_dataH.textureSize.height, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, NULL));
        
        GL_CHECK(glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST));
        GL_CHECK(glTexParameteri ( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST));
        
        GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE));
        GL_CHECK(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE));
    }

    GL_CHECK_MEM(glBindFramebuffer(GL_FRAMEBUFFER, m_dataH.frameBuffer));
    GL_CHECK_MEM(glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_dataH.textureBuffer, 0));
}

void VfxShelterOwnerDraw::onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect)
{   

#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("ShR", SA_start);
#endif 

    GLfloat vVertices[] = {0.0f, 0.0f, 0.0f, 
                         0.0f, m_size.height, 0.0f,
                         m_size.width, 0.0f, 0.0f,
                         m_size.width, m_size.height, 0.0f};

    GLfloat vVerticesHalf[] = { 0.0f, 0.0f, 0.0f, 
                              0.0f, m_size.height / SHRINK_RATIO, 0.0f,
                              m_size.width / SHRINK_RATIO, 0.0f, 0.0f,
                              m_size.width / SHRINK_RATIO, m_size.height / SHRINK_RATIO, 0.0f};


         
    GLfloat vTexcoord[] = { 0.0f, 0.0f,
                          0.0f, 1.0f,
                          1.0f, 0.0f,
                          1.0f, 1.0f};



    GLint viewportsize[4];  
    GLint scissorboxsize[4];
    GLint fbo;          


    GL_CHECK( glGetIntegerv(GL_VIEWPORT, viewportsize) );
    GL_CHECK( glGetIntegerv(GL_SCISSOR_BOX, scissorboxsize) );    
    GL_CHECK( glGetIntegerv(GL_FRAMEBUFFER_BINDING, &fbo) );

    vrt_sys_screen_rotate_enum screen_rotation = VRT_SYS_SCREEN_ROTATE_0;
    VfxSize texSize = m_size;
    VfxSize texSizeHalf;
    texSizeHalf.width = m_size.width / SHRINK_RATIO;
    texSizeHalf.height = m_size.height / SHRINK_RATIO;

    if (fbo == 0)
    {
        screen_rotation = vrt_sys_get_screen_rotation();
        if (screen_rotation == VRT_SYS_SCREEN_ROTATE_90 ||
            screen_rotation == VRT_SYS_SCREEN_ROTATE_270)
        {   // screen rotate by transform
            vVertices[4] = vVertices[10] = m_size.width;
            vVertices[6] = vVertices[9] = m_size.height;
            vVerticesHalf[4] = vVerticesHalf[10] = m_size.width / SHRINK_RATIO;
            vVerticesHalf[6] = vVerticesHalf[9] = m_size.height / SHRINK_RATIO;
            texSize.width = m_size.height;
            texSize.height = m_size.width;
            texSizeHalf.width = m_size.height / SHRINK_RATIO;
            texSizeHalf.height = m_size.width / SHRINK_RATIO;
        }
    }

	if(m_forceCopy)
	{
	    if (m_dataH.textureId)
	    {
	        glDeleteTextures(1, &m_dataH.textureId);
	        m_dataH.textureId = 0;
	    }
	    m_dataH.textureId = VfxShelterCreateTexture2D(texSize.width, texSize.height);
	    m_forceCopy = VFX_FALSE;
	    VFX_LOG(VFX_INFO, VFX_SHELTER_FORCE_COPY, this, m_dataH.textureId);            
	}else if(m_dataH.textureId ==0)
	{
	    m_dataH.textureId = VfxShelterCreateTexture2D(texSize.width, texSize.height);        
	    VFX_LOG(VFX_INFO, VFX_SHELTER_FIRST_COPY, this, m_dataH.textureId);            
	}


    GL_CHECK(glViewport ( 0, 0, texSizeHalf.width, texSizeHalf.height));
    GL_CHECK(glScissor(0, 0, texSizeHalf.width, texSizeHalf.height));


    // bind stroke frame buffer
    bindStrokeFramebuffer(texSizeHalf);
        
    // Use the program object
    GL_CHECK(glUseProgram(m_dataH.programObject));

    GL_CHECK(glUniform2i(m_dataH.uViewPortSizeLoc, texSizeHalf.width, texSizeHalf.height));
    GL_CHECK(glUniform2i(m_dataH.uFrameAnchorLoc, 0, 0) );
    GL_CHECK(glUniform2i(m_dataH.uBaseTexSizeLoc, texSize.width, texSize.height));


    // Bind the texture
    GL_CHECK(glActiveTexture(GL_TEXTURE0));   
    GL_CHECK(glBindTexture(GL_TEXTURE_2D, m_dataH.textureId));
    GL_CHECK(glUniform1i(m_dataH.uBaseTexLoc, 0));// Set the sampler texture unit to 0

    GL_CHECK(glUniform1f(m_dataH.uLevelLoc, m_level));          


    GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);          
    VRT_EXT_ASSERT(status == GL_FRAMEBUFFER_COMPLETE, status, status, status); 


    GL_CHECK(glVertexAttribPointer(m_dataH.aPositionLoc, VERTEX_POS_SIZE, GL_FLOAT, GL_FALSE, 0, vVerticesHalf));
    GL_CHECK(glEnableVertexAttribArray(m_dataH.aPositionLoc));
    GL_CHECK(glVertexAttribPointer(m_dataH.aTexCoordLoc, VERTEX_TEXCOOR_SIZE, GL_FLOAT, GL_FALSE, 0, vTexcoord));
    GL_CHECK(glEnableVertexAttribArray(m_dataH.aTexCoordLoc));
    GL_CHECK(glDrawArrays(GL_TRIANGLE_STRIP, 0, 4 ) );
    GL_CHECK(glDisableVertexAttribArray(m_dataH.aPositionLoc));
    GL_CHECK(glDisableVertexAttribArray(m_dataH.aTexCoordLoc));

    //
    // vertical
    //
    // bind origin frame buffer
    GL_CHECK_MEM(glBindFramebuffer(GL_FRAMEBUFFER, fbo));
    GL_CHECK(glScissor(scissorboxsize[0],scissorboxsize[1],scissorboxsize[2], scissorboxsize[3]));
        
    GL_CHECK(glUseProgram(m_dataV.programObject));

    switch(screen_rotation)
    {
        case VRT_SYS_SCREEN_ROTATE_0:
            GL_CHECK(glViewport (dstRect.origin.x, dstBuffer.height - (dstRect.origin.y + dstRect.size.height),
                        dstRect.size.width, dstRect.size.height));
            GL_CHECK(glUniform2i(m_dataV.uViewPortSizeLoc, dstRect.size.width, dstRect.size.height));
            GL_CHECK(glUniform2i(m_dataV.uFrameAnchorLoc, srcRect.origin.x  , m_size.height - (srcRect.origin.y + srcRect.size.height)));
            break;
        case VRT_SYS_SCREEN_ROTATE_90:
            GL_CHECK(glViewport (dstRect.origin.y, dstRect.origin.x,
                        dstRect.size.height, dstRect.size.width));
            GL_CHECK(glUniform2i(m_dataV.uViewPortSizeLoc, dstRect.size.height, dstRect.size.width));
            GL_CHECK(glUniform2i(m_dataV.uFrameAnchorLoc, srcRect.origin.y, srcRect.origin.x));
            break;
        case VRT_SYS_SCREEN_ROTATE_180:
            GL_CHECK(glViewport (dstBuffer.width - (dstRect.origin.x + dstRect.size.width), dstRect.origin.y,
                        dstRect.size.width, dstRect.size.height));
            GL_CHECK(glUniform2i(m_dataV.uViewPortSizeLoc, dstRect.size.width, dstRect.size.height) );
            GL_CHECK(glUniform2i(m_dataV.uFrameAnchorLoc, m_size.width - (srcRect.origin.x + srcRect.size.width), srcRect.origin.y));
            break;
        case VRT_SYS_SCREEN_ROTATE_270:
            GL_CHECK(glViewport (dstBuffer.height - (dstRect.origin.y + dstRect.size.height), dstBuffer.width - (dstRect.origin.x + dstRect.size.width),
                        dstRect.size.height, dstRect.size.width));
            GL_CHECK(glUniform2i(m_dataV.uViewPortSizeLoc, dstRect.size.height, dstRect.size.width));
            GL_CHECK(glUniform2i(m_dataV.uFrameAnchorLoc, m_size.height - (srcRect.origin.y + srcRect.size.height), m_size.width - (srcRect.origin.x + srcRect.size.width)));
            break;
    }

    // Bind the texture
    GL_CHECK(glActiveTexture(GL_TEXTURE0));
    GL_CHECK(glBindTexture(GL_TEXTURE_2D, m_dataH.textureId));
    GL_CHECK(glUniform1i(m_dataV.uFrameTexLoc, 0));// Set the sampler texture unit to 0


    // Bind the texture
    GL_CHECK(glActiveTexture(GL_TEXTURE1));
    GL_CHECK(glBindTexture(GL_TEXTURE_2D, m_dataH.textureBuffer));
    GL_CHECK(glUniform1i(m_dataV.uBaseTexLoc, 1));// Set the sampler texture unit to 1       

         

    GL_CHECK(glUniform2i(m_dataV.uBaseTexSizeLoc, texSize.width, texSize.height));
    GL_CHECK(glUniform1f(m_dataV.uLevelLoc, m_level));          
    GL_CHECK(glUniform1f(m_dataV.uDarknessLoc, VFX_SHELTER_BLUR_DARKNESS));                                 

    GL_CHECK(glVertexAttribPointer(m_dataV.aPositionLoc, VERTEX_POS_SIZE, GL_FLOAT, GL_FALSE, 0, vVertices));
    GL_CHECK(glEnableVertexAttribArray(m_dataV.aPositionLoc));
    GL_CHECK(glVertexAttribPointer(m_dataV.aTexCoordLoc, VERTEX_TEXCOOR_SIZE, GL_FLOAT, GL_FALSE, 0, vTexcoord));
    GL_CHECK(glEnableVertexAttribArray(m_dataV.aTexCoordLoc));
    GL_CHECK(glDrawArrays(GL_TRIANGLE_STRIP, 0, 4));
    GL_CHECK(glDisableVertexAttribArray (m_dataV.aPositionLoc));
    GL_CHECK(glDisableVertexAttribArray (m_dataV.aTexCoordLoc));    


    GL_CHECK(glViewport(viewportsize[0], viewportsize[1], viewportsize[2], viewportsize[3]));


#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("ShR", SA_stop);
#endif 
}


#endif /*__COSMOS_3D_V10_SHELTER__*/


/***************************************************************************** 
 * Class VfxShelter
 *****************************************************************************/

VfxShelter::VfxShelter() :
    m_isHiding(VFX_FALSE),
    m_rotateTimer(NULL),
    m_isRotating(VFX_FALSE)
{    
#ifdef __COSMOS_3D_V10_SHELTER__
    m_isStatic = VFX_FALSE;
    m_content = NULL;
    m_frameEffect = NULL;
    m_ownerDrawV = NULL;
    m_ownerDrawH = NULL;
#endif /*__COSMOS_3D_V10_SHELTER__*/
}


void VfxShelter::show(VfxFrame *target, VfxBool isAnim)
{
    VfxAutoAnimate::initAnimateBegin();
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);

    m_isRotating = VFX_FALSE; 
    m_isHiding = VFX_FALSE;    
    setBounds(getParentFrame()->getBounds());     
    setPosZ(target->getPosZ() + 1);
    bringToFront();    
 
    VfxAutoAnimate::commit();
    VfxAutoAnimate::initAnimateEnd();


#ifdef __COSMOS_3D_V10_SHELTER__   

    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);

    if(m_ownerDrawV)
    {
        m_ownerDrawV->m_forceCopy = VFX_TRUE;
        VFX_LOG(VFX_INFO, VFX_SHELTER_OWNER_DRAW_SHOW_V, this, m_ownerDrawV);           
    }

    if(m_ownerDrawH)
    {
        m_ownerDrawH->m_forceCopy = VFX_TRUE;
        VFX_LOG(VFX_INFO, VFX_SHELTER_OWNER_DRAW_SHOW_H, this, m_ownerDrawH);           
    }
      
    VfxAutoAnimate::initAnimateBegin();
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(!isAnim);
    VfxAutoAnimate::setDuration(VFX_SHELTER_ANIM_DURATION);
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);          
    setFilterTiming(1.0);
    VfxAutoAnimate::commit();
    VfxAutoAnimate::initAnimateEnd();

    VfxS32 duration = isAnim? VFX_SHELTER_ANIM_DURATION : 0;
    updateFrameEffect(duration); 
    
#else     
    setBgColor(VFX_COLOR_BLACK);
    setIsOpaque(VFX_TRUE);
    setOpacity(0.0f);

    VfxAutoAnimate::initAnimateBegin();
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(!isAnim);
    VfxAutoAnimate::setDuration(VFX_SHELTER_ANIM_DURATION);
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
    setOpacity(0.5f);
    VfxAutoAnimate::commit();
    VfxAutoAnimate::initAnimateEnd();
#endif
}


void VfxShelter::hide(VfxBool isAnim)
{
    m_isHiding = VFX_TRUE;
#ifdef __COSMOS_3D_V10_SHELTER__
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(!isAnim);
    VfxAutoAnimate::setDuration(VFX_SHELTER_ANIM_DURATION);     
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
    setFilterTiming(0.0f);
    VfxAutoAnimate::commit();

    VfxS32 duration = isAnim? VFX_SHELTER_ANIM_DURATION : 0;
    updateFrameEffect(duration);

#else        
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(!isAnim);
    VfxAutoAnimate::setDuration(VFX_SHELTER_ANIM_DURATION); 
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
    setOpacity(0.0f);
    VfxAutoAnimate::commit();
#endif
}


void VfxShelter::exit()
{ 
    m_isHiding = VFX_FALSE;


#ifdef __COSMOS_3D_V10_SHELTER__
    if(m_isStatic == VFX_TRUE)//ownerdraw
    {            
        vrt_canvas_set_layer_frame_clear_color(NULL);
	}
#endif
}


void VfxShelter::onInit()
{
    VfxControl::onInit();
    setAutoAnimate(VFX_TRUE);           
}



void VfxShelter::processRotate(VfxScreenRotateParam param)
{
    m_isRotating = VFX_TRUE;
    VFX_OBJ_CREATE(m_rotateTimer, VfxTimer, this);
    m_rotateTimer->setStartDelay(param.durTime);
    m_rotateTimer->m_signalTick.connect(this, &VfxShelter::onRotateTimerTick);       
    m_rotateTimer->start();     
}
	

void VfxShelter::onRotateTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);
    VFX_OBJ_CLOSE(m_rotateTimer);   
    m_isRotating = VFX_FALSE;
   
#ifdef __COSMOS_3D_V10_SHELTER__
    updateFrameEffect(0);
#endif
}

void VfxShelter::setBounds(const VfxRect &value)
{
    VfxControl::setBounds(value);

#ifdef __COSMOS_3D_V10_SHELTER__
    if(m_isStatic == VFX_TRUE)//ownerdraw
    {            
        VfxSize v = getParentFrame()->getSize();
        VfxSize h;
        h.height = v.width;
        h.width = v.height;

        if(m_ownerDrawV == NULL)
        {
            VFX_OBJ_CREATE_EX(m_ownerDrawV, VfxShelterOwnerDraw, this, (v));
        }
        if(m_ownerDrawH == NULL)
        {
            VFX_OBJ_CREATE_EX(m_ownerDrawH, VfxShelterOwnerDraw, this, (h));            
        } 
       
        VfxShelterOwnerDraw* ownerdraw = NULL;

        if(value.size == m_ownerDrawV->m_size)
        {
            ownerdraw = m_ownerDrawV;
            VFX_LOG(VFX_INFO, VFX_SHELTER_OWNER_DRAW_SET_V, this, ownerdraw);   
        }
        else if(value.size == m_ownerDrawH->m_size)
        {
            ownerdraw = m_ownerDrawH;
            VFX_LOG(VFX_INFO, VFX_SHELTER_OWNER_DRAW_SET_H, this, ownerdraw);   
        }

        VFX_ASSERT(ownerdraw != NULL);                
                    
        setOwnerDraw(ownerdraw);
            
        Shelter_data sdata;
        sdata.ownerdraw = ownerdraw;
    
        setPropertyEffectCallback(
        this,
        shelterFrameEffectCallBack,
        &sdata,
        sizeof(Shelter_data),
        VRT_FPE_TRIGGER_TYPE_CONTENT_DIRTY);

        if (m_content.get())
        {
            VfxColor color = m_content->getBgColor();
            vrt_canvas_set_layer_frame_clear_color((vrt_color_type)color);
        }
    }
    else
    {    
        updateFrameEffect(0);
    }          
#endif /*__COSMOS_3D_V10_SHELTER__*/

}


#ifdef __COSMOS_3D_V10_SHELTER__

void VfxShelter::setShelterContent(VfxFrame *content)    
{
    m_content = content; 
    VFX_OBJ_CLOSE(m_frameEffect);        
    setOwnerDraw(NULL);   
}

void VfxShelter::setIsStatic(VfxBool isStatic)    
{
    m_isStatic = isStatic;
    VFX_OBJ_CLOSE(m_frameEffect);        
    setOwnerDraw(NULL);   
}

void VfxShelter::updateFrameEffect(VfxMsec duration)
{
    if(m_isStatic == VFX_FALSE && m_content.get())
    {       
        VFX_LOG(VFX_INFO, VFX_SHELTER_FRAME_EFFECT_SHOW, this);            

        Vcp3DEffectBlurData data;

        data.darkness = VFX_SHELTER_BLUR_DARKNESS;
        data.background = m_content.get();                            
        data.from = forceGetFilterTiming();
        data.isFrameTexture = !m_isRotating;

        VFX_OBJ_CLOSE(m_frameEffect);

        if(duration != 0 || !m_isHiding)
        {
            VFX_OBJ_CREATE(m_frameEffect, VcpFrameEffect, this);                
            m_frameEffect->applyEffect(this, VCP_EFFECT_3D_BLUR, duration, VCP_EFFECT_DIRECTION_FROM_NONE, m_isHiding, &data, sizeof(data));
        }
    }
}


vrt_render_dirty_type_enum VfxShelter::shelterFrameEffectCallBack(
               vrt_frame_visual_property_struct *target_frame,
               const vrt_frame_visual_property_struct *watch_frame,
               void *user_data,
               vrt_u32 user_data_size)
{
    Shelter_data* userdata = (Shelter_data*)user_data;
    VfxShelterOwnerDraw* ownerDraw =  userdata->ownerdraw;

    ownerDraw->m_level = watch_frame->filter_timing;
    return VRT_RENDER_DIRTY_TYPE_CONTENT_DIRTY;

}


#endif /*__COSMOS_3D_V10_SHELTER__*/




