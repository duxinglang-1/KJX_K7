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
 *  vtst_rt_3d_owner_draw.cpp
 *
 * Project:
 * --------
 *  Venus UI
 *
 * Description:
 * ------------
 *  Venus Regression Test for 3d owner draw
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
 * removed!
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

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_main.h"
#include "vfx_frame.h"
#include "vfx_owner_draw.h"
#include "gles2\gl2.h"


typedef struct
{
   // Handle to a program object
   GLuint programObject;

} UserData;

///
// Create a shader object, load the shader source, and
// compile the shader.
//
GLuint loadShader ( GLenum type, const char *shaderSrc )
{
   GLuint shader;
   GLint compiled;
   
   // Create the shader object
   shader = glCreateShader ( type );

   if ( shader == 0 )
   	return 0;

   // Load the shader source
   glShaderSource ( shader, 1, &shaderSrc, NULL );
   
   // Compile the shader
   glCompileShader ( shader );

   // Check the compile status
   glGetShaderiv ( shader, GL_COMPILE_STATUS, &compiled );

   if ( !compiled ) 
   {
      glDeleteShader ( shader );
      return 0;
   }

   return shader;

}


class MyGLESOwenerDraw : public VfxOwnerDraw
{
public:
    MyGLESOwenerDraw()
    {
        m_data.programObject = 0;
    }

protected:
    virtual vrt_bool isUsingGLAPI() const { return VFX_TRUE; }
    
    virtual void onInitResource()
    {
        UserData *userData = &m_data;
        const char vShaderStr[] =  
        "attribute vec4 vPosition;    \n"
        "attribute vec4 aColor;       \n"
        "varying vec4 vColor;       \n"
        "void main()                  \n"
        "{                            \n"
        "   vColor = aColor;  \n"
        "   gl_Position = vPosition;  \n"
        "}                            \n";

        const char fShaderStr[] =  
        "precision mediump float;\n"\
        "varying vec4 vColor;       \n"
        "void main()                                  \n"
        "{                                            \n"
        "  gl_FragColor = vColor;                     \n"
        "}                                            \n";

        GLuint vertexShader;
        GLuint fragmentShader;
        GLuint programObject;
        GLint linked;

        // Load the vertex/fragment shaders
        vertexShader = loadShader ( GL_VERTEX_SHADER, vShaderStr );
        fragmentShader = loadShader ( GL_FRAGMENT_SHADER, fShaderStr );

        // Create the program object
        programObject = glCreateProgram ( );

        VFX_DEV_ASSERT(programObject);

        glAttachShader ( programObject, vertexShader );
        glAttachShader ( programObject, fragmentShader );

        // Bind vPosition to attribute 0   
        glBindAttribLocation ( programObject, 0, "vPosition" );

        glBindAttribLocation ( programObject, 1, "vColor" );

        // Link the program
        glLinkProgram ( programObject );

        // Check the link status
        glGetProgramiv ( programObject, GL_LINK_STATUS, &linked );

        if ( !linked ) 
        {
            glDeleteProgram ( programObject );
            VFX_DEV_ASSERT(0);
        }

        // Store the program object
        userData->programObject = programObject;

        glClearColor ( 0.0f, 0.0f, 0.0f, 0.0f );
    }

    virtual void onDeinitResource()
    {
        UserData *userData = &m_data;
        if (userData->programObject)
        {
            glDeleteProgram(userData->programObject);
            userData->programObject = 0;
        }
    }

    virtual void onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect)
    {
        UserData *userData = &m_data;
        GLfloat vVertices[] = {  0.0f,  0.5f, 0.0f, 
                               -0.5f, -0.5f, 0.0f,
                                1.0f, 0.5f, 0.0f,
                                0.5f, -0.5f, 0.0f};

        GLubyte vColors[] = { 255, 255, 255, 255,
                               255, 0, 0, 255,
                               0, 0, 255, 255,
                               255, 255, 0, 255};

        // Set the viewport
        glViewport ( 0, 0, dstRect.size.width, dstRect.size.height );

        // Clear the color buffer
        glClear ( GL_COLOR_BUFFER_BIT );
        glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

        // Use the program object
        glUseProgram ( userData->programObject );

        // Load the vertex data
        glVertexAttribPointer ( 0, 3, GL_FLOAT, GL_FALSE, 0, vVertices );
        glEnableVertexAttribArray ( 0 );

        glVertexAttribPointer ( 1, 4, GL_UNSIGNED_BYTE, GL_TRUE, 0, vColors );
        glEnableVertexAttribArray ( 1 );

        glVertexAttrib4f ( 1, 0.0, 1.0, 0.0, 1.0 );
        glDrawArrays ( GL_TRIANGLE_STRIP, 0, 4 );

    }

    UserData m_data;
};

class VtstRt3DOwnerDraw : public VtstRtScr
{
// Variable
public:
    
// Constructor / Destructor
public:
    VtstRt3DOwnerDraw()
    {
    }

    // Override
protected:

    virtual void onInit()
    {
        VtstRtScr::onInit();
        MyGLESOwenerDraw *ownerDraw;
        VFX_OBJ_CREATE(ownerDraw, MyGLESOwenerDraw, this);
        setOwnerDraw(ownerDraw);

        setTitle(VFX_WSTR("3D Owner Draw test"));
    }

    virtual int start()
    {        
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        confirm(VFX_WSTR("3D Owner Draw OK?"));
        return -1;
    }
};


VtstTestResultEnum vtst_rt_3d_owner_draw(VfxU32 param)
{
    VTST_START_SCRN(VtstRt3DOwnerDraw);
    return VTST_TR_OK;
}



class VtstRt3DOwnerDrawLifeTime : public VtstRtScr
{
// Variable
public:
    
// Constructor / Destructor
public:
    VtstRt3DOwnerDrawLifeTime()
    : m_ownerDraw(NULL)
    {
    }

    MyGLESOwenerDraw *m_ownerDraw;
    // Override
protected:

    virtual void onInit()
    {
        VtstRtScr::onInit();
        setTitle(VFX_WSTR("Init / Deinit"));
    }

    virtual int start()
    {
        return 2;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        switch (idx)
        {
        case 0:
            VFX_OBJ_CREATE(m_ownerDraw, MyGLESOwenerDraw, this);
            setOwnerDraw(m_ownerDraw);

            confirm(VFX_WSTR("Init OK?"));
            break;
        case 1:
            setOwnerDraw(NULL);
            VFX_OBJ_CLOSE(m_ownerDraw);
            confirm(VFX_WSTR("Deinit OK?"));
            break;
        }

        return -1;
    }    
};


VtstTestResultEnum vtst_rt_3d_owner_draw_init_deinit(VfxU32 param)
{
    VTST_START_SCRN(VtstRt3DOwnerDrawLifeTime);
    return VTST_TR_OK;
}



class CheckBoardDraw : public VfxOwnerDraw
{
// Override
public:
    static vrt_render_dirty_type_enum onUpdate(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size)
    {
        return VRT_RENDER_DIRTY_TYPE_CONTENT_DIRTY;
    }

    virtual void onDraw(VfxImageBuffer &dstBuffer, VfxRect &dstRect, VfxRect &srcRect)
    {
        VfxS32 ox, oy, sx, sy;
        VfxS32 x, y;

        if (m_isFullyOpaque)
        {
            ox = dstRect.origin.x;
            oy = dstRect.origin.y;
            sx = dstRect.origin.x + dstRect.size.width;
            sy = dstRect.origin.y + dstRect.size.height;
        }
        else
        {
            ox = ((dstRect.origin.x + dstRect.size.width / 4) >> 4) << 4;
            oy = ((dstRect.origin.y + dstRect.size.height / 4) >> 4) << 4;
            sx = ((dstRect.origin.x + dstRect.size.width * 3 / 4) >> 4) << 4;
            sy = ((dstRect.origin.y + dstRect.size.height * 3 / 4) >> 4) << 4;
        }

        if (dstBuffer.colorFormat == VRT_COLOR_TYPE_RGB565)
        {
            for (y = oy; y < sy; y++)
            {
                VfxU8 *dst_buf_ptr = dstBuffer.ptr + dstBuffer.pitchBytes * y + ox * 2;

                for (x = ox; x < sx; x++)
                {
                    VfxS32 square = ((x >> 4) - (y >> 4)) % 3;

                    if (square == 0)
                    {
                        *((VfxU16 *)dst_buf_ptr) = 0xFFFF;
                    }
                    else if (square == 1 || square == -2)
                    {
                        *((VfxU16 *)dst_buf_ptr) = 0x001F;  // Color Key
                    }
                    else
                    {
                        *((VfxU16 *)dst_buf_ptr) = 0x0000;
                    }
                    dst_buf_ptr += 2;
                }
            }
        }
        else
        {
            for (y = oy; y < sy; y++)
            {
                VfxU8 *dst_buf_ptr = dstBuffer.ptr + dstBuffer.pitchBytes * y + ox * 4;

                for (x = ox; x < sx; x++)
                {
                    VfxS32 square = ((x >> 4) - (y >> 4)) % 3;

                    if (square == 0)
                    {
                        *((VfxU32 *)dst_buf_ptr) = 0xFFFFFFFF;
                    }
                    else if (square == 1 || square == -2)
                    {
                        *((VfxU32 *)dst_buf_ptr) = 0x80808080;  // Bg Color
                    }
                    else
                    {
                        *((VfxU32 *)dst_buf_ptr) = 0x00000000;
                    }
                    dst_buf_ptr += 4;
                }
            }
        }
    }    

    CheckBoardDraw() : m_isFullyOpaque(VFX_TRUE)
    {
    }

    void setFullyOpaque(VfxBool fullyOpaque)
    {
        m_isFullyOpaque = fullyOpaque;
    }

private:
    VfxBool m_isFullyOpaque;
};

class VtstRt3DSWOwnerDraw : public VtstRtScr
{
// Variable
public:
    VfxFrame *m_frame;
    CheckBoardDraw *m_ownerDraw;

// Constructor / Destructor
public:
    VtstRt3DSWOwnerDraw()
    : m_frame(NULL)
    , m_ownerDraw(NULL)
    {
    }

    // Override
protected:

    virtual void onInit()
    {
        VtstRtScr::onInit();

        VFX_OBJ_CREATE(m_frame, VfxFrame, this);
        VFX_OBJ_CREATE(m_ownerDraw, CheckBoardDraw, this);
        m_frame->setBgColor(VFX_COLOR_GREY);
        m_frame->setSize(this->getSize());
        m_frame->setOwnerDraw(m_ownerDraw);
        m_frame->setPropertyEffectCallback(m_frame, m_ownerDraw->onUpdate, NULL, 0, VRT_FPE_TRIGGER_TYPE_EVERYTIME);

        setTitle(VFX_WSTR("SW Owner Draw test"));
    }

    virtual int start()
    {        
        return 3;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        switch (idx)
        {
        case 0:
            confirm(VFX_WSTR("Fully Opaque Owner Draw OK?"));
            break;
        case 1:
            confirm(VFX_WSTR("Color Key Owner Draw OK?"));
            m_frame->setBgColor(VFX_COLOR_TRANSPARENT);
            m_ownerDraw->setFullyOpaque(VFX_FALSE);
            break;
        case 2:
            confirm(VFX_WSTR("Translucent Owner Draw OK?"));
            m_frame->setBgColor(VfxColor(0x80808080));
            break;
        }
        return -1;
    }
};


VtstTestResultEnum vtst_rt_3d_sw_owner_draw(VfxU32 param)
{
    VTST_START_SCRN(VtstRt3DSWOwnerDraw);
    return VTST_TR_OK;
}


#endif // __AFX_RT_TEST__

